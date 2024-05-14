/* BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
*   File Name       : Dem_Types.h
********************************************************************************
*   Project/Product : AUTOSAR 4.2
*   Title           : Dem module head File
*   Author          : Hirain
********************************************************************************
*   Description: Type header file of the AUTOSAR Diagnositc Event Manager,
*              according to AUTOSAR_SWS_DiagnosticEventManager.pdf (Release 4.2)
********************************************************************************
*   Limitations: None
*
********************************************************************************
*
********************************************************************************
*   Revision History:
*   Reference to Core C File
********************************************************************************
* END_FILE_HDR*/

#ifndef DEM_TYPES_H
#define DEM_TYPES_H

/*******************************************************************************
* Include files
*******************************************************************************/
#include "Dem_Cfg.h"
#include "Std_Types.h"
#include "Rte_Dem_Type.h"
#if(DEM_NVM_SUPPORT == STD_ON)
#include "NvM_Types.h"
#endif


/*******************************************************************************
* Macros and Typedef
*******************************************************************************/

/*SWS_Dem_01114*/
typedef uint16 Dem_ComponentIdType;/*1..65535, 0 is not a valid value*/

/*SWS_Dem_00924*/
typedef struct
{
    uint16     CfgId;
} Dem_ConfigType;


/*SWS_Dem_00935*/
typedef uint8 Dem_DTCRequestType;
/*first failed DTC requested*/
#define DEM_FIRST_FAILED_DTC                        ((uint8)0x01)
/*most recent failed DTC requested*/
#define DEM_MOST_RECENT_FAILED_DTC                  ((uint8)0x02)
/*first detected confirmed DTC requested*/
#define DEM_FIRST_DET_CONFIRMED_DTC                 ((uint8)0x03)
/*most recently detected confirmed DTC requeste*/
#define DEM_MOST_REC_DET_CONFIRMED_DTC              ((uint8)0x04)

/*SWS_Dem_00936*/
typedef uint8 Dem_DTCTranslationFormatType;
/*ISO15031-6 DTC format/SAE J2012-DA_DTCFormat_00 DTC format*/
#define DEM_DTC_TRANSLATION_ISO15031_6              ((uint8)0x00)
/*ISO14229-1 DTC format*/
#define DEM_DTC_TRANSLATION_ISO14229_1              ((uint8)0x01)
/*SAEJ1939-73 DTC format*/
#define DEM_DTC_TRANSLATION_SAEJ1939_73             ((uint8)0x02)
/*ISO11992-4 DTC format*/
#define DEM_DTC_TRANSLATION_ISO11992_4              ((uint8)0x03)
/*SAE_J2012-DA_DTCFormat_04 DTC format*/
#define DEM_DTC_TRANSLATION_J2012_DA_FORMAT_04      ((uint8)0x04)

/*SWS_Dem_00937*/
typedef uint8 Dem_DTCSeverityType;
#define DEM_SEVERITY_NO_SEVERITY                    ((uint8)0x00)/*No severity information available*/
#define DEM_SEVERITY_MAINTENANCE_ONLY               ((uint8)0x20)/*maintenance required*/
#define DEM_SEVERITY_CHECK_AT_NEXT_HALT             ((uint8)0x40)/*check at next halt*/
#define DEM_SEVERITY_CHECK_IMMEDIATELY              ((uint8)0x80)/*Check immediately*/

#define DEM_SEVERITY_WWHOBD_CLASS_NO_CLASS          ((uint8)0x01)/*No class information*/
#define DEM_SEVERITY_WWHOBD_CLASS_A                 ((uint8)0x02)/*WWH-OBD Class A*/
#define DEM_SEVERITY_WWHOBD_CLASS_B1                ((uint8)0x04)/*WWH-OBD Class B1*/
#define DEM_SEVERITY_WWHOBD_CLASS_B2                ((uint8)0x08)/*WWH-OBD Class B2*/
#define DEM_SEVERITY_WWHOBD_CLASS_C                 ((uint8)0x10)/*WWH-OBD Class C*/
#define DTC_CLASS                                   ((uint8)0x1F)/*Selects one of the defined DTC classes (or "NO_CLASS")*/


/*SWS_Dem_00940*/
/*OBD specific ratio Id.Configurable, size depends on system complexity (refer to range of configuration parameter DemRatioId)*/
typedef uint16 Dem_RatioIdType;/*uint8, uint16*/

/*SWS_Dem_00941*/
typedef uint8 Dem_DTRControlType;
/*Values are reported and regarded as valid test result*/
#define DEM_DTR_CTL_NORMAL                          ((uint8)0x00)
/*Values are reported,but maximum limit is not available (not valid); upper limit value is ignored.*/
#define DEM_DTR_CTL_NO_MAX                          ((uint8)0x01)
/*Values are reported,but minimum limit is not available (not valid); lower limit value is ignored.*/
#define DEM_DTR_CTL_NO_MIN                          ((uint8)0x02)
/*Values are all ignored.External representation will be all zeros as initialized (e.g. after fault clear)*/
#define DEM_DTR_CTL_RESET                           ((uint8)0x03)
/*Values are all ignored.This DTR is treated for the external view (tester) as if not integrated.*/
#define DEM_DTR_CTL_INVISIBLE                       ((uint8)0x04)

/*SWS_Dem_00943*/
/*This type contains all possible additional IUMPR denominator conditions to
be broadcasted among OBD-relevant ECUs.*/
typedef enum
{
    /*IUMPR denominator condition "General Denominator"*/
    DEM_IUMPR_GENERAL_DENOMINATOR  = 0x00,
    /*Additional IUMPR denominator condition "Cold Start"*/
    DEM_IUMPR_DEN_COND_COLDSTART   = 0x01,
    /*Additional IUMPR denominator condition "EVAP"*/
    DEM_IUMPR_DEN_COND_EVAP        = 0x02,
    /*Additional IUMPR denominator condition "500 miles"*/
    DEM_IUMPR_DEN_COND_500MI       = 0x03
} Dem_IumprDenomCondIdType;

/*SWS_Dem_00945*/
typedef uint8 Dem_J1939DcmDTCStatusFilterType;
#define DEM_J1939DTC_ACTIVE                         ((uint8)0x00)/*active DTCs*/
#define DEM_J1939DTC_PREVIOUSLY_ACTIVE              ((uint8)0x01)/*previously active DTCs*/
#define DEM_J1939DTC_PENDING                        ((uint8)0x02)/*pending DTCs*/
#define DEM_J1939DTC_PERMANENT                      ((uint8)0x03)/*permanent DTCs*/
#define DEM_J1939DTC_CURRENTLY_ACTIVE               ((uint8)0x04)/*currently active DTC*/

/*SWS_Dem_00946*/
typedef uint8 Dem_J1939DcmSetClearFilterType;
#define DEM_J1939DTC_CLEAR_ALL                      ((uint8)0x00)/*active DTCs*/
#define DEM_J1939DTC_CLEAR_PREVIOUSLY_ACTIVE        ((uint8)0x01)/*previously active DTCs*/

/*SWS_Dem_00947*/
typedef uint8 Dem_J1939DcmSetFreezeFrameFilterType;
#define DEM_J1939DCM_FREEZEFRAME                    ((uint8)0x00)/*FreezeFrame (DM04)*/
#define DEM_J1939DCM_EXPANDED_FREEZEFRAME           ((uint8)0x01)/*ExpandedFreezeFrame(DM25)*/
#define DEM_J1939DCM_SPNS_IN_EXPANDED_FREEZEFRAME   ((uint8)0x02)/*SPNs in ExpandedFreezeFrame (DM24)*/



/*SWS_Dem_00948*/
typedef uint16 Dem_J1939DcmLampStatusType;
#define DEM_J1939_LAMP_UNAVAILABLE                  ((uint16)0xFFFF)
/*Malfunction Indicator Lamp Status:Off*/
#define DEM_J1939_MIL_OFF                           ((uint16)0x0000)
/*Malfunction Indicator Lamp Status:On*/
#define DEM_J1939_MIL_ON                            ((uint16)0x4000)
/*Malfunction Indicator Lamp Status:Short MI*/
#define DEM_J1939_MIL_SHORT                         ((uint16)0x8000)
/*Malfunction Indicator Lamp Status:Unavailable*/
#define DEM_J1939_MIL_UNAVAILABLE                   ((uint16)0xC000)

/*Red Stop Lamp Status:Off*/
#define DEM_J1939_RSL_OFF                           ((uint16)0x0000)
/*Red Stop Lamp Status:On*/
#define DEM_J1939_RSL_ON                            ((uint16)0x1000)
/*Reserved for SAE Assignment*/
#define DEM_J1939_RSL_RESERVED                      ((uint16)0x2000)
/*Red Stop Lamp Status:Unavailable*/
#define DEM_J1939_RSL_UNAVAILABLE                   ((uint16)0x3000)

/*Amber Warning Lamp Status:Off*/
#define DEM_J1939_AWL_OFF                           ((uint16)0x0000)
/*Amber Warning Lamp Status:On*/
#define DEM_J1939_AWL_ON                            ((uint16)0x0400)
/*Reserved for SAE Assignment*/
#define DEM_J1939_AWL_RESERVED                      ((uint16)0x0800)
/*Amber Warning Lamp Status:Unavailable*/
#define DEM_J1939_AWL_UNAVAILABLE                   ((uint16)0x0C00)

/*Protect Lamp Status:Off*/
#define DEM_J1939_PL_OFF                            ((uint16)0x0000)
/*Protect Lamp Status:On*/
#define DEM_J1939_PL_ON                             ((uint16)0x0100)
/*Reserved for SAE Assignment*/
#define DEM_J1939_PL_RESERVED                       ((uint16)0x0200)
/*Protect Lamp Status:Unavailable*/
#define DEM_J1939_PL_UNAVAILABLE                    ((uint16)0x0300)

/*Flash Malfunction Indicator Lamp Status:Slow Flash*/
#define DEM_J1939_FMIL_SF                           ((uint16)0x0000)
/*Flash Malfunction Indicator Lamp Status:Fast Flash*/
#define DEM_J1939_FMIL_FF                           ((uint16)0x0040)
/*Flash Malfunction Indicator Lamp Status:Class C DTC*/
#define DEM_J1939_FMIL_CCDTC                        ((uint16)0x0080)
/*Flash Malfunction Indicator Lamp Status:Unavailable/Do Not Flash*/
#define DEM_J1939_FMIL_UNAVAILABLE                  ((uint16)0x00C0)

/*Flash Red Stop Lamp Status:Slow Flash*/
#define DEM_J1939_FRSL_SF                           ((uint16)0x0000)
/*Flash Red Stop Lamp Status:Fast Flash*/
#define DEM_J1939_FRSL_FF                           ((uint16)0x0010)
/*Reserved for SAE Assignment*/
#define DEM_J1939_FRSL_RESERVED                     ((uint16)0x0020)
/*Flash Red Stop Lamp Status:Unavailable/Do Not Flash*/
#define DEM_J1939_FRSL_UNAVAILABLE                  ((uint16)0x0030)

/*Flash Amber Warning Lamp Status:Slow Flash*/
#define DEM_J1939_FAWL_SF                           ((uint16)0x0000)
/*Flash Amber Warning Lamp Status:Fast Flash*/
#define DEM_J1939_FAWL_FF                           ((uint16)0x0004)
/*Reserved for SAE Assignment*/
#define DEM_J1939_FAWL_RESERVED                     ((uint16)0x0008)
/*Flash Amber Warning Lamp Status:Unavailable/Do Not Flash*/
#define DEM_J1939_FAWL_UNAVAILABLE                  ((uint16)0x000C)

/*Flash Protect Lamp Status:Slow Flash*/
#define DEM_J1939_FPL_SF                            ((uint16)0x0000)
/*Flash Protect Lamp Status:Fast Flash*/
#define DEM_J1939_FPL_FF                            ((uint16)0x0001)
/*Reserved for SAE Assignment*/
#define DEM_J1939_FPL_RESERVED                      ((uint16)0x0002)
/*Flash Protect Lamp Status:Unavailable/Do Not Flash*/
#define DEM_J1939_FPL_UNAVAILABLE                   ((uint16)0x0003)



/*SWS_Dem_00949*/
typedef struct
{
    /*Number of active DTCs*/
    uint8  ActiveTroubleCodes;
    /*Number of previously active DTCs*/
    uint8  PreviouslyActiveDiagnosticTroubleCodes;
    /*OBD Compliance*/
    uint8  OBDCompliance;
    /*Identifies the continuously monitored system support and status*/
    uint8  ContinuouslyMonitoredSystemsSupport_Status;
    /*Identifies the noncontinuously monitored systems support*/
    uint16 NonContinuouslyMonitoredSystemsSupport;
    /*Identifies the noncontinuously monitored systems status*/
    uint16 NonContinuouslyMonitoredSystemsStatus;
} Dem_J1939DcmDiagnosticReadiness1Type;

/*SWS_Dem_00950*/
typedef struct
{
    /*The kilometers accumulated while the MIL is activated*/
    uint16 DistanceTraveledWhileMILisActivated;
    /*Distance accumulated since emission related DTCs were cleared*/
    uint16 DistanceSinceDTCsCleared;
    /*Accumulated count (in minutes) while the MIL is activated (on)*/
    uint16 MinutesRunbyEngineWhileMILisActivated;
    /*Engine running time accumulated since emission related DTCs were cleared*/
    uint16 TimeSinceDiagnosticTroubleCodesCleared;
} Dem_J1939DcmDiagnosticReadiness2Type;

/*SWS_Dem_00951*/
typedef struct
{
    /*Time since key-on that the engine has been running.*/
    uint16 TimeSinceEngineStart;
    /*Number of OBD warmup cycles since all DTCs were cleared*/
    uint8  NumberofWarmupsSinceDTCsCleared;
    /*Identifies the continuously monitored system enable/completed support and status.*/
    uint8  ContinuouslyMonitoredSystemsEnableCompletedStatus;
    /*Enable status of noncontinuous monitors this monitoring cycle*/
    uint16 NonContinuouslyMonitoredSystemsEnableStatus;
    /*Completion status of noncontinuous monitors this monitoring cycle*/
    uint16 NonContinuouslyMonitoredSystems;
} Dem_J1939DcmDiagnosticReadiness3Type;




/*SWS_Dem_00952*/
typedef uint8 Dem_ReturnGetStatusOfDTCType;
#define DEM_STATUS_OK                               ((uint8)0x00)
#define DEM_STATUS_WRONG_DTC                        ((uint8)0x01)
#define DEM_STATUS_WRONG_DTCORIGIN                  ((uint8)0x02)
#define DEM_STATUS_FAILED                           ((uint8)0x03)
#define DEM_STATUS_PENDING                          ((uint8)0x04)

/*SWS_Dem_00953*/
typedef uint8 Dem_ReturnGetSeverityOfDTCType;
#define DEM_GET_SEVERITYOFDTC_OK                    ((uint8)0x00)
#define DEM_GET_SEVERITYOFDTC_WRONG_DTC             ((uint8)0x01)
#define DEM_GET_SEVERITYOFDTC_NOSEVERITY            ((uint8)0x02)
#define DEM_GET_SEVERITYOFDTC_PENDING               ((uint8)0x03)

/*SWS_Dem_00954*/
typedef uint8 Dem_ReturnGetFunctionalUnitOfDTCType;
#define DEM_GET_FUNCTIONALUNITOFDTC_OK              ((uint8)0x00)
#define DEM_GET_FUNCTIONALUNITOFDTC_WRONG_DTC       ((uint8)0x01)

/*SWS_Dem_00955*/
typedef uint8 Dem_ReturnSetFilterType;
#define DEM_FILTER_ACCEPTED                         ((uint8)0x00)
#define DEM_WRONG_FILTER                            ((uint8)0x01)

/*SWS_Dem_00956*/
typedef uint8 Dem_ReturnGetNumberOfFilteredDTCType;
#define DEM_NUMBER_OK                               ((uint8)0x00)
#define DEM_NUMBER_FAILED                           ((uint8)0x01)
#define DEM_NUMBER_PENDING                          ((uint8)0x02)

/*SWS_Dem_00957*/
typedef uint8 Dem_ReturnGetNextFilteredElementType;
#define DEM_FILTERED_OK                             ((uint8)0x00)
#define DEM_FILTERED_NO_MATCHING_ELEMENT            ((uint8)0x01)
#define DEM_FILTERED_PENDING                        ((uint8)0x02)
#define DEM_FILTERED_BUFFER_TOO_SMALL               ((uint8)0x03)

/*SWS_Dem_00958*/
typedef uint8 Dem_ReturnGetDTCByOccurrenceTimeType;
#define DEM_OCCURR_OK                               ((uint8)0x00)
#define DEM_OCCURR_NOT_AVAILABLE                    ((uint8)0x01)

/*SWS_Dem_00959*/
typedef uint8 Dem_ReturnDisableDTCRecordUpdateType;
#define DEM_DISABLE_DTCRECUP_OK                     ((uint8)0x00)
#define DEM_DISABLE_DTCRECUP_WRONG_DTC              ((uint8)0x01)
#define DEM_DISABLE_DTCRECUP_WRONG_DTCORIGIN        ((uint8)0x02)
#define DEM_DISABLE_DTCRECUP_PENDING                ((uint8)0x03)

/*SWS_Dem_00960*/
typedef uint8 Dem_ReturnGetFreezeFrameDataByDTCType;
#define DEM_GET_FFDATABYDTC_OK                      ((uint8)0x00)
#define DEM_GET_FFDATABYDTC_WRONG_DTC               ((uint8)0x01)
#define DEM_GET_FFDATABYDTC_WRONG_DTCORIGIN         ((uint8)0x02)
#define DEM_GET_FFDATABYDTC_WRONG_RECORDNUMBER      ((uint8)0x03)
#define DEM_GET_FFDATABYDTC_WRONG_BUFFERSIZE        ((uint8)0x04)
#define DEM_GET_FFDATABYDTC_PENDING                 ((uint8)0x05)

/*SWS_Dem_00961*/
typedef uint8 Dem_ReturnGetExtendedDataRecordByDTCType;
#define DEM_RECORD_OK                               ((uint8)0x00)
#define DEM_RECORD_WRONG_DTC                        ((uint8)0x01)
#define DEM_RECORD_WRONG_DTCORIGIN                  ((uint8)0x02)
#define DEM_RECORD_WRONG_NUMBER                     ((uint8)0x03)
#define DEM_RECORD_WRONG_BUFFERSIZE                 ((uint8)0x04)
#define DEM_RECORD_PENDING                          ((uint8)0x05)

/*SWS_Dem_00962*/
typedef uint8 Dem_ReturnGetSizeOfDataByDTCType;
#define DEM_GETSIZEBYDTC_OK                         ((uint8)0x00)
#define DEM_GETSIZEBYDTC_WRONG_DTC                  ((uint8)0x01)
#define DEM_GETSIZEBYDTC_WRONG_DTCORIGIN            ((uint8)0x02)
#define DEM_GETSIZEBYDTC_WRONG_RECNUM               ((uint8)0x03)
#define DEM_GETSIZEBYDTC_PENDING                    ((uint8)0x04)

/*SWS_Dem_00963*/
typedef uint8 Dem_ReturnClearDTCType;
#define DEM_CLEAR_OK                                ((uint8)0x00)
#define DEM_CLEAR_WRONG_DTC                         ((uint8)0x01)
#define DEM_CLEAR_WRONG_DTCORIGIN                   ((uint8)0x02)
#define DEM_CLEAR_FAILED                            ((uint8)0x03)
#define DEM_CLEAR_PENDING                           ((uint8)0x04)
#define DEM_CLEAR_BUSY                              ((uint8)0x05)
#define DEM_CLEAR_MEMORY_ERROR                      ((uint8)0x06)

/*SWS_Dem_00964*/
typedef uint8 Dem_ReturnControlDTCSettingType;
#define DEM_CONTROL_DTC_SETTING_OK                  ((uint8)0x00)
#define DEM_CONTROL_DTC_SETTING_N_OK                ((uint8)0x01)
#define DEM_CONTROL_DTC_WRONG_DTCGROUP              ((uint8)0x02)


/*******************************************************************************
*   DemGeneral Types ECUC_Dem_00677
*******************************************************************************/
/*ECUC_Dem_00603*/
/*DemAgingCycleCounterProcessing*/
#define DEM_PROCESS_AGINGCTR_EXTERN                 (0)
#define DEM_PROCESS_AGINGCTR_INTERN                 (1)

/*ECUC_Dem_00878*/
/*DemAvailabilitySupport*/
#define DEM_EVENT_AVAILABILITY                      (0)
#define DEM_NO_AVAILABILITY                         (1)

/*ECUC_Dem_00766*/
/*DemClearDTCBehavior*/
#define DEM_CLRRESP_NONVOLATILE_FINISH              (0)
#define DEM_CLRRESP_NONVOLATILE_TRIGGER             (1)
#define DEM_CLRRESP_VOLATILE                        (2)

/*ECUC_Dem_00790*/
/*DemClearDTCLimitation*/
#define DEM_ALL_SUPPORTED_DTCS                      (0)
#define DEM_ONLY_CLEAR_ALL_DTCS                     (1)

/*ECUC_Dem_00858*/
/*DemDataElementDefaultEndianness*/
#define DEM_BIG_ENDIAN                              (0)
#define DEM_LITTLE_ENDIAN                           (1)
#define DEM_OPAQUE                                  (2)

/*ECUC_Dem_00895*/
/*DemEnvironmentDataCapture*/
#define DEM_CAPTURE_ASYNCHRONOUS_TO_REPORTING       (0)
#define DEM_CAPTURE_SYNCHRONOUS_TO_REPORTING        (1)

/*ECUC_Dem_00740*/
/*DemEventCombinationSupport*/
#define DEM_EVCOMB_DISABLED                         (0)
#define DEM_EVCOMB_ONRETRIEVAL                      (1)
#define DEM_EVCOMB_ONSTORAGE                        (2)

/*ECUC_Dem_00742*/
/*DemEventDisplacementStrategy*/
#define DEM_DISPLACEMENT_FULL                       (0)
#define DEM_DISPLACEMENT_NONE                       (1)
#define DEM_DISPLACEMENT_PRIO_OCC                   (2)


/*DemEventMemoryEntryStorageTrigger*/
typedef uint8 Dem_EventMemoryEntryStorageTriggerType;
/*ECUC_Dem_00804*/
#define DEM_TRIGGER_ON_MIRROR                       ((uint8)0x01)
#define DEM_TRIGGER_ON_PASSED                       ((uint8)0x02)
/*ECUC_Dem_00797*/
#define DEM_TRIGGER_ON_FDC_THRESHOLD                ((uint8)0x04)
#define DEM_TRIGGER_ON_TEST_FAILED                  ((uint8)0x08)
#define DEM_TRIGGER_ON_PENDING                      ((uint8)0x10)
#define DEM_TRIGGER_ON_CONFIRMED                    ((uint8)0x20)


/*ECUC_Dem_00698*/
/*DemOBDSupport*/
#define DEM_OBD_DEP_SEC_ECU                         (0)
#define DEM_OBD_MASTER_ECU                          (1)
#define DEM_OBD_NO_OBD_SUPPORT                      (2)
#define DEM_OBD_PRIMARY_ECU                         (4)

#if((DEM_CFG_OBD_SUPPORT == DEM_OBD_MASTER_ECU)||(DEM_CFG_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU))
/*ECUC_Dem_00900*/
/*DemOBDEngineType*/
#define DEM_IGNITION_SPARK                          (0)
#define DEM_IGNITION_COMPRESSION                    (1)
#endif

/*ECUC_Dem_00767*/
/*DemOccurrenceCounterProcessing*/
#define DEM_PROCESS_OCCCTR_CDTC                     (0)
#define DEM_PROCESS_OCCCTR_TF                       (1)

/*ECUC_Dem_00784*/
/*DemStatusBitHandlingTestFailedSinceLastClear*/
#define DEM_STATUS_BIT_AGING_AND_DISPLACEMENT       (0)
#define DEM_STATUS_BIT_NORMAL                       (1)

/*ECUC_Dem_00793*/
/*DemSuppressionSupport*/
#define DEM_DTC_SUPPRESSION                         (0)
#define DEM_NO_SUPPRESSION                          (1)

/*ECUC_Dem_00778*/
/*DemTypeOfFreezeFrameRecordNumeration*/
/*freeze frame records will be numbered consecutive starting by 1 in their chronological order*/
#define DEM_FF_RECNUM_CALCULATED                    (0)
/*freeze frame records will be numbered based on the given configuration in their chronological order*/
#define DEM_FF_RECNUM_CONFIGURED                    (1)

/*ECUC_Dem_00703*/
/*DemOperationCycleType*/
typedef uint8 Dem_OperationCycleType;
#define DEM_OPCYC_IGNITION                          ((uint8)0x00)/*Ignition ON / OFF cycle*/
#define DEM_OPCYC_OBD_DCY                           ((uint8)0x01)/*OBD Driving cycle*/
#define DEM_OPCYC_OTHER                             ((uint8)0x02)/*further operation cycle*/
#define DEM_OPCYC_POWER                             ((uint8)0x03)/*Power ON / OFF cycle*/
#define DEM_OPCYC_TIME                              ((uint8)0x04)/*Time based operation cycle*/
#define DEM_OPCYC_WARMUP                            ((uint8)0x05)/*OBD Warm up cycle*/

/*ECUC_Dem_00701*/
/*DemOperationCycle:1...256*/
typedef struct
{
    /*ECUC_Dem_00837*/
    /*If DemOperationCycleAutomaticEnd is configured to TRUE, Dem shall
      automatically end the driving cycle at either Dem_Shutdown() or Dem_Init().*/
    /*SWS_Dem_00697*/
    boolean DemOperationCycleAutomaticEnd;
    /*ECUC_Dem_00805*/
    /*The autostart property defines if the operation cycles is automatically (re-)started during Dem_PreInit.*/
    boolean DemOperationCycleAutostart;
    /*ECUC_Dem_00898*/
    uint8 DemOperationCycleId;
    /*ECUC_Dem_00703*/
    Dem_OperationCycleType DemOperationCycleType;
} Dem_OperationCycleInfoType;


/*ECUC_Dem_00653*/
/*DemEnableCondition 0..255*/
typedef struct
{
    /*ECUC_Dem_00654*/
    uint8 DemEnableConditionId;/*0..255*/
    /*ECUC_Dem_00656*/
    boolean DemEnableConditionStatus;
} Dem_EnableConditionType;

/*ECUC_Dem_00745*/
/*DemEnableConditionGroup 0..255*/
typedef struct
{
    uint8 Number;/*1..255*/
    /*ECUC_Dem_00655*/
    const uint8 *DemEnableConditionRef;
} Dem_EnableConditionGroupType;

/*ECUC_Dem_00728*/
/*DemStorageCondition 0..255*/
typedef struct
{
    /*ECUC_Dem_00730*/
    uint8 DemStorageConditionId;/*0..255*/
    /*ECUC_Dem_00893*//*SWS_Dem_01085*/
    uint16 DemStorageConditionReplacementEventRef;
    /*ECUC_Dem_00731*/
    boolean DemStorageConditionStatus;
} Dem_StorageConditionType;

/*ECUC_Dem_00773*/
/*DemStorageConditionGroup 0..255*/
typedef struct
{
    uint8 Number;/*1..255*/
    /*ECUC_Dem_00768*/
    const uint8 *DemStorageConditionRef;
} Dem_StorageConditionGroupType;


/*ECUC_Dem_00696*/
/*DemNvRamBlockId:0..n*/
typedef struct
{
    /*ECUC_Dem_00697*/
    /*This reference contains the link to a non-volatile memory block. For
          post build time configurations worst case scenario shall be used.*/
    uint16 DemNvRamBlockIdRef;
} Dem_NvRamBlockIdType;

/*ECUC_Dem_00679*//*ECUC_Dem_00678*/
typedef uint32 Dem_DTCGroupType;
#define DEM_DTC_GROUP_EMISSION              ((uint32)0xFFFF33)/*Emissions-system group*/
#define DEM_DTC_GROUP_SAFETY                ((uint32)0xFFFFD0)/*Safety-system group*/
#define DEM_DTC_GROUP_VOBD                  ((uint32)0xFFFFFE)/*VOBD system*/

#define DEM_DTC_GROUP_CHASSIS               ((uint32)0x400000)/*Chassis Group*/
#define DEM_DTC_CHASSIS_RANGE_LOW           ((uint32)0x400000)
#define DEM_DTC_CHASSIS_RANGE_HIGH          ((uint32)0x7FFFFF)


#define DEM_DTC_GROUP_BODY                  ((uint32)0x800000)/*Body Group*/
#define DEM_DTC_BODY_RANGE_LOW              ((uint32)0x800000)
#define DEM_DTC_BODY_RANGE_HIGH             ((uint32)0xBFFFFF)

/*Powertrain Group: engine and transmission*/
#define DEM_DTC_GROUP_POWERTRAIN            ((uint32)0x100000)
#define DEM_DTC_POWER_RANGE_LOW             ((uint32)0x000100)
#define DEM_DTC_POWER_RANGE_HIGH            ((uint32)0x3FFFFF)

/*Network Communication Group*/
#define DEM_DTC_GROUP_NETWORK_COM           ((uint32)0xC00000)
#define DEM_DTC_COM_RANGE_LOW               ((uint32)0xC00000)
#define DEM_DTC_COM_RANGE_HIGH              ((uint32)0xFFFF00)

/*All functional system groups*/
#define DEM_DTC_GROUP_ALL                   ((uint32)0xFFFFFF)




/*ECUC_Dem_00910*/
/*DemUserDefinedMemory:0..30*/
typedef struct
{
    /*ECUC_Dem_00691*/
    /*Maximum number of events which can be stored in the user defined memory.*/
    uint8 DemMaxNumberEventEntryUserDefined;/*0 .. 255*/
    /*ECUC_Dem_00903*/
    /*Identifier used by external tester to identify the User defined event memory.*/
    uint8 DemUserDefinedMemoryIdentifier;/*16 .. 255*/
} Dem_UserDefinedMemoryEntryMaxNumberType;

typedef uint32 Dem_UdsDTCType;

/*ECUC_Dem_00626*//*DemCallbackDTCStatusChanged*/
/*ECUC_Dem_00627*//*DemCallbackDTCStatusChangedFnc*/
/*SWS_Dem_00617*/
typedef P2FUNC(Std_ReturnType, DEM_APPL_CODE, Dem_DTCStatusChangedNotificationType)
(
    Dem_UdsDTCType DTC,
    Dem_UdsStatusByteType DTCStatusOld,
    Dem_UdsStatusByteType DTCStatusNew
);

#ifndef DEM_E_NO_FDC_AVAILABLE
#define DEM_E_NO_FDC_AVAILABLE   ((uint8)2)
#endif



#if((DEM_CFG_OBD_SUPPORT == DEM_OBD_MASTER_ECU)||(DEM_CFG_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU))
/*ECUC_Dem_00838*/
#define DEM_IUMPR_DEN_GENERAL  ((uint8)0)
typedef enum
{
    DEM_IUMPR_DEN_NONE       = 0,
    DEM_IUMPR_DEN_COLDSTART  = 1,
    DEM_IUMPR_DEN_EVAP       = 2,
    DEM_IUMPR_DEN_500MILL    = 3,
    DEM_IUMPR_DEN_PHYS_API   = 4
} Dem_IUMPRDenGroupType;

/*ECUC_Dem_00737*/
typedef enum
{
#if(DEM_CFG_OBD_ENGINE_TYPE == DEM_IGNITION_SPARK)
    DEM_IUMPR_CAT1        = 1,/*Sequence reference SAE J1979-DA*/
    DEM_IUMPR_CAT2        = 2,
    DEM_IUMPR_OXS1        = 3,
    DEM_IUMPR_OXS2        = 4,
    DEM_IUMPR_EGR         = 5,
    DEM_IUMPR_SAIR        = 6,
    DEM_IUMPR_EVAP        = 7,
    DEM_IUMPR_SECOXS1     = 8,
    DEM_IUMPR_SECOXS2     = 9,
#else
    DEM_IUMPR_NMHCCAT     = 1,
    DEM_IUMPR_NOXCAT      = 2,
    DEM_IUMPR_NOXADSORB   = 3,
    DEM_IUMPR_PMFILTER    = 4,
    DEM_IUMPR_EGSENSOR    = 5,
    DEM_IUMPR_EGR         = 6,
    DEM_IUMPR_BOOSTPRS    = 7,
    DEM_IUMPR_FLSYS       = 8,
#endif
    /*DEM_IUMPR_PRIVATE     = 10*//*Not used*/
} Dem_IUMPRGroupType;

/*ECUC_Dem_00741*/
typedef enum
{
    DEM_RATIO_API       = 0,
    DEM_RATIO_OBSERVER  = 1
} Dem_RatioKindType;

/*ECUC_Dem_00734*/
typedef struct
{
    /*ECUC_Dem_0078*/
    //Dem_RatioIdType DemRatioId;
    /*ECUC_Dem_00735*/
    Dem_EventIdType DemDiagnosticEventRef;
    /*ECUC_Dem_00736*/
    //uint16 DemFunctionIdRef;
    /*ECUC_Dem_00782*/
    //uint16 DemSecondaryFunctionIdRef;
    /*ECUC_Dem_00737*/
    Dem_IUMPRGroupType DemIUMPRGroup;
    /*ECUC_Dem_00838*//*SWS_Dem_00715*/
    Dem_IUMPRDenGroupType DemIUMPRDenGroup;
    /*ECUC_Dem_00741*//*SWS_Dem_00361*/
    Dem_RatioKindType DemRatioKind;
} Dem_RatioType;

#endif/*#if((DEM_CFG_OBD_SUPPORT == DEM_OBD_MASTER_ECU)||(DEM_CFG_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU))*/




/*******************************************************************************
*   DemConfigSet Types ECUC_Dem_00634
*******************************************************************************/

#if(DEM_CFG_OBD_SUPPORT == DEM_OBD_MASTER_ECU)
typedef enum
{
    /*The order is same as monitors in PID01/41. See SAE J1979*/
    DEM_OBD_RDY_MISF     = 0,  /*Byte 2, bit 0*//*Misfire - spark, compr.*/
    DEM_OBD_RDY_FLSYS    = 1,  /*Byte 2, bit 1*//*Fuel system - spark, compr.*/
    //DEM_OBD_RDY_FLSYS_NONCONT  = 1,/*Byte 2, bit 1*//*Non Contious Fuel system - spark, compr*/
    DEM_OBD_RDY_CMPRCMPT = 2,  /*Byte 2, bit 2*//*Comprehensive component - spark, compr.*/
                               /*Byte 2, bit 3*//*Engine type*/
#if(DEM_CFG_OBD_ENGINE_TYPE == DEM_IGNITION_SPARK)
    DEM_OBD_RDY_CAT      = 8,  /*Byte 3, bit 0*//*Catalyst - spark*/
    DEM_OBD_RDY_HTCAT    = 9,  /*Byte 3, bit 1*//*Heated catalyst - spark*/
    DEM_OBD_RDY_EVAP     = 10, /*Byte 3, bit 2*//*Evaporative system - spark*/
    DEM_OBD_RDY_SECAIR   = 11, /*Byte 3, bit 3*//*Secondary air system - spark*/
    //DEM_OBD_RDY_AC       = 12, /*Byte 3, bit 4*//*Secondary air system - spark*/
    DEM_OBD_RDY_O2SENS   = 13, /*Byte 3, bit 5*//*Oxygen sensor - spark*/
    DEM_OBD_RDY_O2SENSHT = 14, /*Byte 3, bit 6*//*Oxygen sensor heater - spark*/
#endif

#if(DEM_CFG_OBD_ENGINE_TYPE == DEM_IGNITION_COMPRESSION)
    DEM_OBD_RDY_HCCAT    = 8,  /*Byte 3, bit 0*//*Non-Methan HC Catalyst - compr.*/
    DEM_OBD_RDY_NOXCAT   = 9,  /*Byte 3, bit 1*//*NOx Catalyst - compr.*/
    DEM_OBD_RDY_BOOSTPR  = 11, /*Byte 3, bit 3*//*Boost Pressure System - compr.*/
    DEM_OBD_RDY_EGSENS   = 13, /*Byte 3, bit 5*//*Exhaust Gas Sensor - compr.*/
    DEM_OBD_RDY_PMFLT    = 14, /*Byte 3, bit 6*//*Particle Matters Filter - compr.*/
#endif
    DEM_OBD_RDY_ERG      = 15, /*Byte 3, bit 7*//*EGR system - spark, compr.*/
    DEM_OBD_RDY_NONE     = 16
} Dem_EventOBDReadinessGroupType;
#endif

#if((DEM_CFG_OBD_SUPPORT == DEM_OBD_MASTER_ECU)||(DEM_CFG_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU)||(DEM_J1939_SUPPORT == STD_ON))
/*ECUC_Dem_00884*/
typedef struct
{
#if(DEM_CFG_PTO_SUPPORT == STD_ON)
    /*ECUC_Dem_00602*/
    boolean DemConsiderPtoStatus;
#endif
#if((DEM_CFG_OBD_SUPPORT == DEM_OBD_MASTER_ECU)||(DEM_CFG_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU))
    /*ECUC_Dem_00885*/
    uint16 DemDtcValue;/*Range:1 .. 65535*/
#endif
#if(DEM_CFG_OBD_SUPPORT == DEM_OBD_MASTER_ECU)
    /*ECUC_Dem_00755*/
    Dem_EventOBDReadinessGroupType DemEventOBDReadinessGroup;
#endif
#if(DEM_J1939_SUPPORT == STD_ON)
    /*ECUC_Dem_00892*/
    uint32 DemJ1939DTCValue;
#endif
} Dem_ObdDTCInfoType;
#endif

#if((DEM_CFG_OBD_SUPPORT == DEM_OBD_MASTER_ECU)||(DEM_CFG_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU))
typedef uint16 Dem_DtrIdType;
typedef uint8 Dem_DtrMidType;
typedef uint8 Dem_DtrTidType;
typedef uint8 Dem_DtrUasidType;
/*ECUC_Dem_00812*/
typedef enum
{
    DEM_DTR_UPDATE_ALWAYS  = 0,
    DEM_DTR_UPDATE_STEADY  = 1
} Dem_DtrUpdateKindType;

/*ECUC_Dem_00806*/
typedef struct
{
    /*ECUC_Dem_00815*/
    uint16 DemDtrCompuDenominator0;
    /*ECUC_Dem_00813*/
    uint16 DemDtrCompuNumerator0;
    /*ECUC_Dem_00814*/
    uint16 DemDtrCompuNumerator1;
    /*ECUC_Dem_00808*/
    Dem_EventIdType DemDtrEventRef;
    /*ECUC_Dem_00807*/
    Dem_DtrIdType DemDtrId;
    /*ECUC_Dem_00809*/
    Dem_DtrMidType DemDtrMid;
    /*ECUC_Dem_00810*/
    Dem_DtrTidType DemDtrTid;
    /*ECUC_Dem_00811*/
    Dem_DtrUasidType DemDtrUasid;
    /*ECUC_Dem_00812*/
    Dem_DtrUpdateKindType DemDtrUpdateKind;
} Dem_DtrType;

/*ECUC_Dem_00729*/
typedef struct
{
    /*ECUC_Dem_00705*/
    uint8 DemPidIdentifier;
    /*ECUC_Dem_00896*//*ECUC_Dem_00733*/
    uint8 NumOfData;
    const uint8 *DemPidDataElementClassRef;
} Dem_PidClassType;

#endif/*#if((DEM_CFG_OBD_SUPPORT == DEM_OBD_MASTER_ECU)||(DEM_CFG_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU))*/


/*ECUC_Dem_00886*/
/*DemDTC:This container contains the configuration (parameters) for DemUdsDTC.*/
/*0..65535*/
typedef struct
{
    /*ECUC_Dem_00642*/
    uint16 DemDTCAttributesRef;
    /*ECUC_Dem_00643*/
    uint8 DemDTCFunctionalUnit;/*0 .. 255*/
    /*ECUC_Dem_00645*/
    Dem_DTCSeverityType DemDTCSeverity;
    /*ECUC_Dem_00887*/
    Dem_UdsDTCType DemDtcValue;
#if((DEM_CFG_OBD_SUPPORT == DEM_OBD_MASTER_ECU)||(DEM_CFG_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU)||(DEM_J1939_SUPPORT == STD_ON))
    /*ECUC_Dem_00889*/
    const Dem_ObdDTCInfoType *DemObdDTCRef;
#endif
#if((DEM_CFG_OBD_SUPPORT == DEM_OBD_MASTER_ECU)||(DEM_CFG_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU))
    /*ECUC_Dem_00912*/
    Dem_DTCSeverityType DemWWHOBDDTCClass;
#endif
} Dem_DTCInfoType;

typedef enum
{
    DEM_EVENT_SIGNIFICANCE_OCCURRENCE = 0,
    DEM_EVENT_SIGNIFICANCE_FAULT
} Dem_DTCSignificanceType;

/*ECUC_Dem_00616*/
typedef enum
{
    DEM_AGINGCTR_DOWNCNT = 0,
    DEM_AGINGCTR_UPCNT = 1,
    DEM_CURRENT_FDC = 2,
    DEM_CYCLES_SINCE_FIRST_FAILED = 3,
    DEM_CYCLES_SINCE_LAST_FAILED = 4,
    DEM_FAILED_CYCLES = 5,
    DEM_MAX_FDC_DURING_CURRENT_CYCLE = 6,
    DEM_MAX_FDC_SINCE_LAST_CLEAR = 7,
    DEM_OCCCTR = 8,
    DEM_OVFLIND = 9,
    DEM_SIGNIFICANCE = 10,
#if(STD_ON == DEM_CMA_PLATFORM_ENABLED)
    DEM_PASSED_CYCLES_SINCE_LAST_FAILED = 11,
    DEM_CMA_SI30 = 12,
    DEM_CMA_CONSECUTIVE_FAILED_CYCLES = 13,
#endif
    DEM_OBD_PASSED_CYCLES_SINCE_LAST_FAILED = 14,
    DEM_AGED_COUNTER = 15
} Dem_InternalDataElementType;

/*ECUC_Dem_00619*/
typedef P2FUNC(Std_ReturnType, DEM_APPL_CODE, Dem_DataElementReadFncType)
(
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) Data
);

/*ECUC_Dem_00684*/
typedef struct
{
    /*ECUC_Dem_00614*/
    uint8 DemDataElementDataSize;/*1 .. 255*/
    /*ECUC_Dem_00616*//*SWS_Dem_00469*/
    Dem_InternalDataElementType DemInternalDataElement;
} Dem_InternalDataElementClassType;

/*ECUC_Dem_00668*/
typedef struct
{
    /*ECUC_Dem_00646*/
    uint8 DemDataElementDataSize;/*1 .. 255*/
    /*ECUC_Dem_00619*//*SWS_Dem_00261*/
    Dem_DataElementReadFncType DemDataElementReadFnc;
    /*ECUC_Dem_00647*/
    boolean DemDataElementUsePort;
} Dem_ExternalCSDataElementClassType;

/*ECUC_Dem_00610*/
/*DemDataElementClass 0..65535*/
typedef struct
{
    /*ECUC_Dem_00684*/
    const Dem_InternalDataElementClassType *DemInternalDataElementClass;
    /*ECUC_Dem_00668*/
    const Dem_ExternalCSDataElementClassType *DemExternalCSDataElementClass;
} Dem_DataElementClassType;

/*******************************************************************************
* Dem_J1939Dcm Types
*******************************************************************************/
/*ECUC_Dem_00828*/
/*DemJ1939FreezeFrameClass 0..255*/
typedef struct
{
    uint8 Number;/*1..255*/
    /*ECUC_Dem_00829*/
    const uint32 *DemSPNClassRef;
} Dem_J1939FreezeFrameClassType;


/*ECUC_Dem_00830*/
/*DemSPNClass 0..524287(0x7FFFF)*/
typedef struct
{
    /*ECUC_Dem_00832*/
    const Dem_DataElementClassType *DemSPNDataElementClassRef;/*Multiplicity: 1*/
    /*ECUC_Dem_00831*/
    uint32 DemSPNId;/*0..524287(0x7FFFF)*/
} Dem_SPNClassType;

/*ECUC_Dem_00817*/
/*DemJ1939Node 0..255*/
typedef struct
{
    uint8 Number;/*1..255*/
    /*ECUC_Dem_00818*/
    const uint8 *DemJ1939NmNodeRef;
} Dem_J1939NodeType;


typedef uint16 Dem_PriorityType;
#define DEM_DTC_LOWEST_PRIORITY  (Dem_PriorityType)256

/*ECUC_Dem_00641*/
/*DemDTCAttributes:This container contains the configuration (parameters) for DemDTCAttributes.*/
/*0..65535*/
typedef struct
{
    /*ECUC_Dem_00622*/
    boolean DemAgingAllowed;
    /*ECUC_Dem_00623*//*SWS_Dem_00493*/
    uint16 DemAgingCycleCounterThreshold;/*1 .. 256*/
#if(DEM_CFG_STATUSBITHANDLING_TFSLC == DEM_STATUS_BIT_AGING_AND_DISPLACEMENT)
    /*ECUC_Dem_00897*/
    uint16 DemAgingCycleCounterThresholdForTFSLC;/*1 .. 256*/
#endif
    /*ECUC_Dem_00624*//*SWS_Dem_00494*/
    uint8 DemAgingCycleRef;
    /*ECUC_Dem_00662*/
    Dem_PriorityType DemDTCPriority;/*1 .. 256*/
    /*ECUC_Dem_00779*/
    Dem_DTCSignificanceType DemDTCSignificance;
    /*ECUC_Dem_00798*/
    uint8 DemEventMemoryEntryFdcThresholdStorageValue;/*1...126*/
    /*ECUC_Dem_00667*/
    const uint8 *DemExtendedDataClassRef;
    /*ECUC_Dem_00776*/
    const uint8 *DemFreezeFrameRecNumClassRef;
    /*ECUC_Dem_00739*/
    boolean DemImmediateNvStorage;
    /*ECUC_Dem_00819*/
    const Dem_J1939NodeType *DemJ1939DTC_J1939NodeRef;
#if(STD_ON == DEM_CFG_J1939EX_FF_SUPPORT)
    /*ECUC_Dem_00834*/
    const Dem_J1939FreezeFrameClassType *DemJ1939ExpandedFreezeFrameClassRef;/*0..1*/
#endif
#if(STD_ON == DEM_CFG_J1939_FF_SUPPORT)
    /*ECUC_Dem_00835*/
    const Dem_J1939FreezeFrameClassType *DemJ1939FreezeFrameClassRef;/*0..1*/
#endif
#if(DEM_CFG_TYPE_OF_FF_RECORD_NUMERATION == DEM_FF_RECNUM_CALCULATED)
    /*ECUC_Dem_00605*//*SWS_Dem_00337*/
    uint8 DemMaxNumberFreezeFrameRecords;/*0 .. 255*/
#endif
    /*ECUC_Dem_00890*/
    uint8 DemMemoryDestinationRef;
#if((DEM_CFG_OBD_SUPPORT == DEM_OBD_MASTER_ECU)||(DEM_CFG_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU))
    /*ECUC_Dem_00911*/
    uint16 DemWWHOBDFreezeFrameClassRef;
#endif
} Dem_DTCAttributesType;


typedef enum
{
    DEM_EVENT_KIND_BSW,
    DEM_EVENT_KIND_SWC
} Dem_EventKindType;

typedef enum
{
    DEM_REPORT_AFTER_INIT = 1,
    DEM_REPORT_BEFORE_INIT = 2
} Dem_ReportBehaviorType;

typedef enum
{
    DEM_DEBOUNCE_FREEZE,
    DEM_DEBOUNCE_RESET
} Dem_DebounceBehaviorType;

#if(DEM_CFG_DEBOUNCECOUNTERBASEDSUPPORT == STD_ON)
/*ECUC_Dem_00881*/
/*DemDebounceCounterBasedClass  0..65535*/
typedef struct
{
    /*ECUC_Dem_00786*/
    Dem_DebounceBehaviorType DemDebounceBehavior;
    /*ECUC_Dem_00635*//*SWS_Dem_00419*/
    uint16 DemDebounceCounterDecrementStepSize;/*PREPASSED 1 .. 32768*/
    /*ECUC_Dem_00637*//*SWS_Dem_00418*/
    uint16 DemDebounceCounterIncrementStepSize;/*PREFAILED 1 .. 32767*/
    /*ECUC_Dem_00636*//*SWS_Dem_00417*/
    sint16 DemDebounceCounterPassedThreshold;/*-32768 .. -1*/
    /*ECUC_Dem_00618*//*SWS_Dem_00416*/
    sint16 DemDebounceCounterFailedThreshold;/*1 .. 32767*/
    /*ECUC_Dem_00685*//*SWS_Dem_00422*/
    boolean DemDebounceCounterJumpDown;
    /*ECUC_Dem_00686*//*SWS_Dem_00424*/
    boolean DemDebounceCounterJumpUp;
    /*ECUC_Dem_00638*//*SWS_Dem_00423*/
    sint16 DemDebounceCounterJumpDownValue;/*-32768 .. 32767*/
    /*ECUC_Dem_00639*//*SWS_Dem_00425*/
    sint16 DemDebounceCounterJumpUpValue;/*-32768 .. 32767*/
    /*ECUC_Dem_00791*/
    boolean DemDebounceCounterStorage;
} Dem_DebounceCounterBasedClassType;
#endif

#if(DEM_CFG_DEBOUNCETIMEBASEDSUPPORT == STD_ON)
/*ECUC_Dem_00882*/
/*DemDebounceTimeBaseClass  0..65535*/
typedef struct
{
    /*ECUC_Dem_00789*/
    Dem_DebounceBehaviorType DemDebounceBehavior;
    /*ECUC_Dem_00717*/
    uint32 DemDebounceTimePassedThreshold;
    /*ECUC_Dem_00716*//*SWS_Dem_00434*/
    uint32 DemDebounceTimeFailedThreshold;
} Dem_DebounceTimeBaseClassType;
#endif
/*SWS_Dem_00622*/
typedef P2FUNC(Std_ReturnType, DEM_APPL_CODE, Dem_CallbackGetFDCFncType)
(
    P2VAR(sint8, AUTOMATIC, DEM_APPL_DATA) FaultDetectionCounter
);

/*ECUC_Dem_00604*/
/*DemDebounceAlgorithmClass*/
typedef struct
{
#if(DEM_CFG_DEBOUNCECOUNTERBASEDSUPPORT == STD_ON)
    /*ECUC_Dem_00711*//*ECUC_Dem_00883*/
    const Dem_DebounceCounterBasedClassType *DemDebounceCounterBasedClassRef;
#endif

#if(DEM_CFG_DEBOUNCETIMEBASEDSUPPORT == STD_ON)
    /*ECUC_Dem_00713*//*ECUC_Dem_00891*/
    const Dem_DebounceTimeBaseClassType *DemDebounceTimeBaseRef;
#endif
    /*ECUC_Dem_00712*//*ECUC_Dem_00630*//*ECUC_Dem_00631*/
    const Dem_CallbackGetFDCFncType DemCallbackGetFDCFnc;
} Dem_DebounceAlgorithmClassType;

/*ECUC_Dem_00609*//*SWS_Dem_00620*/
typedef P2FUNC(Std_ReturnType, DEM_APPL_CODE, Dem_CallbackClearEventAllowedFncType)
(
    P2VAR(boolean, AUTOMATIC, DEM_APPL_DATA) Allowed
);
/*ECUC_Dem_00788*/
typedef enum
{
    DEM_NO_STATUS_BYTE_CHANGE = 0u,
    DEM_ONLY_THIS_CYCLE_AND_READINESS
} Dem_ClearEventAllowedBehaviorType;
/*ECUC_Dem_00607*/
typedef struct
{
    /*ECUC_Dem_00609*/
    Dem_CallbackClearEventAllowedFncType DemCallbackClearEventAllowedFnc;
    /*ECUC_Dem_00788*/
    Dem_ClearEventAllowedBehaviorType DemClearEventAllowedBehavior;
} Dem_CallbackClearEventAllowedType;

/*ECUC_Dem_00606*//*ECUC_Dem_00608*//*SWS_Dem_00618*/
typedef P2FUNC(Std_ReturnType, DEM_APPL_CODE, Dem_CallbackEventDataChangedFncType)
(
    void
);

/*ECUC_Dem_00628*//*ECUC_Dem_00629*//*SWS_Dem_00615*/
typedef P2FUNC(Std_ReturnType, DEM_APPL_CODE, Dem_CallbackEventStatusChangedFncType)
(
    Dem_UdsStatusByteType EventStatusByteOld,
    Dem_UdsStatusByteType EventStatusByteNew
);

/*ECUC_Dem_00632*//*ECUC_Dem_00601*/
typedef P2FUNC(Std_ReturnType, DEM_APPL_CODE, Dem_DemCallbackInitMForEFncType)
(
    Dem_InitMonitorReasonType InitMonitorReason
);

/*ECUC_Dem_00681*/
/*DemIndicatorAttribute:0..255*/
typedef struct
{
    /*ECUC_Dem_00682*//*SWS_Dem_00511*/
    Dem_IndicatorStatusType DemIndicatorBehaviour;
    /*ECUC_Dem_00750*//*SWS_Dem_00500*/
    /*If the failure counter is set to 0 or 1, it means Indicator
    should immediately ON when TestFaild bit is set to 1.*/
    uint8 DemIndicatorFailureCycleCounterThreshold;
    /*ECUC_Dem_00748*//*SWS_Dem_00502*/
    /*If the healing counter is set to 0, it means Indicator
    should immediately OFF when TestFaild bit is reset to 0
    event if TestFaildThisOperationCycle is 1.*/
    uint8 DemIndicatorHealingCycleCounterThreshold;
    /*ECUC_Dem_00687 DemIndicatorRef->ECUC_Dem_00680 DemIndicator->
    ECUC_Dem_00683 DemIndicatorID*//*SWS_Dem_00509*/
    uint8 DemIndicatorID;/*0..255*/
    uint8 DemIndicatorStatusPosOffset;/*position offset*/
} Dem_IndicatorAttributeType;

#if(DEM_NUM_OF_INDICATOR > 0)
/*Developer define*/
typedef P2FUNC(Std_ReturnType, DEM_APPL_CODE, Dem_DemCallbackIndicatorStatusNotify)
(
    Dem_EventIdType EventId,
    Dem_IndicatorStatusType IndicatorStatus
);

typedef struct
{
    Dem_DemCallbackIndicatorStatusNotify DemCallbackIndicatorStatusNotifyFnc;
    uint16 IndicatorStatusStartOffset;
    uint16 NumOfReferencedEvent;
} Dem_IndicatorStatusIndexType;
#endif

/*ECUC_Dem_00661*/
/*DemEventParameter:1..65535*/
typedef struct
{
    /*ECUC_Dem_00908*/
    uint16 DemComponentClassRef;
    /*ECUC_Dem_00909*/
    uint8 DemComponentPriority;/*0 .. 255*/
    /*ECUC_Dem_00888*/
    uint16 DemDTCRef;
    /*ECUC_Dem_00746*//*SWS_Dem_00446*/
#if(DEM_NUM_OF_EN_GROUP > 0)
    const Dem_EnableConditionGroupType *DemEnableConditionGroupRef;
#endif
#if(DEM_CONFIG_VARIANTS != STD_CONFIG_VARIANTS_POSTBUILD)
#if(DEM_CFG_AVAILABILITYSUPPORT == DEM_EVENT_AVAILABILITY)
    /*ECUC_Dem_00792*/
    boolean DemEventAvailable;
#endif
    /*ECUC_Dem_00753*//*SWS_Dem_00528*/
    uint8 DemEventFailureCycleCounterThreshold;/*0 .. 255*/
#endif
    /*ECUC_Dem_00659*/
    Dem_EventIdType DemEventId;/*1 .. 65535*/
    /*ECUC_Dem_00660*/
    Dem_EventKindType DemEventKind;
    /*ECUC_Dem_00671*//*SWS_Dem_00002*/
    boolean DemFFPrestorageSupported;
#if((DEM_CFG_OBD_SUPPORT == DEM_OBD_MASTER_ECU)||(DEM_CFG_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU))
    /*ECUC_Dem_00839*/
    /*uint16 DemOBDGroupingAssociativeEventsRef;*/
#endif
    /*ECUC_Dem_00702*//*SWS_Dem_00529*/
    uint8 DemOperationCycleRef;
    /*ECUC_Dem_00894*/
    Dem_ReportBehaviorType DemReportBehavior;/*DemEventKind == DEM_EVENT_KIND_BSW*/
    /*ECUC_Dem_00769*//*SWS_Dem_00453*/
#if(DEM_NUM_OF_STOR_GROUP > 0)
    const Dem_StorageConditionGroupType *DemStorageConditionGroupRef;
#endif
#if(DEM_NUM_OF_INDICATOR > 0)
    /*ECUC_Dem_00681*//*SWS_Dem_00510*/
    uint8 NumOfIndicator;
    const Dem_IndicatorAttributeType *DemIndicatorAttribute;
#endif
    /*ECUC_Dem_00604*//*SWS_Dem_00413*/
    Dem_DebounceAlgorithmClassType DemDebounceAlgorithmClass;
    /*ECUC_Dem_00607*/
    Dem_CallbackClearEventAllowedType DemCallbackClearEventAllowed;
    /*ECUC_Dem_00606*//*ECUC_Dem_00608*/
    Dem_CallbackEventDataChangedFncType DemCallbackEventDataChangedFnc;
    /*ECUC_Dem_00628*//*ECUC_Dem_00629*/
    Dem_CallbackEventStatusChangedFncType DemCallbackEventStatusChangedFnc;
    /*ECUC_Dem_00632*//*ECUC_Dem_00601*/
    Dem_DemCallbackInitMForEFncType DemCallbackInitMForEFnc;
} Dem_EventParameterType;


/*ECUC_Dem_00706*/
/*DemDidClass 0..65535*/
typedef struct
{
    uint8 Number;
    /*ECUC_Dem_00617*/
    const uint8 *DemDidDataElementClassRef;
    /*ECUC_Dem_00650*/
    uint16 DemDidIdentifier;
} Dem_DidClassType;

typedef enum
{
    DEM_UPDATE_RECORD_NO = 0,
    DEM_UPDATE_RECORD_YES
} Dem_RecordUpdateType;

/*ECUC_Dem_00801*/
/*DemFreezeFrameRecordClass 0...255*/
typedef struct
{
#if(DEM_CFG_TYPE_OF_FF_RECORD_NUMERATION == DEM_FF_RECNUM_CONFIGURED)
    /*ECUC_Dem_00777*/
    uint8 DemFreezeFrameRecordNumber;/*0...254*/
#endif
    /*ECUC_Dem_00803*/
    Dem_EventMemoryEntryStorageTriggerType DemFreezeFrameRecordTrigger;
    /*ECUC_Dem_00802*/
    Dem_RecordUpdateType DemFreezeFrameRecordUpdate;
    /*ECUC_Dem_00674/ECUC_Dem_00673  Dem_FreezeFrameClassType*/
    /*SWS_Dem_00040*/
    uint8 Number;
    /*ECUC_Dem_00707*/
    const uint8 *DemDidClassRef;
} Dem_FreezeFrameRecordClassType;

/*ECUC_Dem_00775*/
/*DemFreezeFrameRecNumClass 0..255*/
typedef struct
{
    uint8 Number;
    /*ECUC_Dem_00800*/
    const uint8 *DemFreezeFrameRecordClassRef;
} Dem_FreezeFrameRecNumClassType;

/*ECUC_Dem_00664*/
/*DemExtendedDataClass*/
typedef struct
{
    uint8 Number;
    /*ECUC_Dem_00774*/
    const uint8 *DemExtendedDataRecordClassRef;/*0...253*/
} Dem_ExtendedDataClassType;

/*ECUC_Dem_00665*/
/*DemExtendedDataRecordClass*/
typedef struct
{
    uint8 Number;
    /*ECUC_Dem_00771*/
    const uint8 *DemDataElementClassRef;
    /*ECUC_Dem_00666*/
    uint8 DemExtendedDataRecordNumber;/*1 .. 239*/
    /*ECUC_Dem_00804*/
    Dem_EventMemoryEntryStorageTriggerType DemExtendedDataRecordTrigger;
    /*ECUC_Dem_00621*/
    Dem_RecordUpdateType DemExtendedDataRecordUpdate;
} Dem_ExtendedDataRecordClassType;


/*******************************************************************************
* Event Memory Type
*******************************************************************************/
typedef struct
{
    /*0xFFFF is invalid value*/
    Dem_EventIdType FirstFailedEvent;
    /*0xFFFF is invalid value*/
    Dem_EventIdType FirstConfirmedEvent;
    /*0xFFFF is invalid value, only bit0 changed from 0 to 1 can affect the parameter's value*/
    Dem_EventIdType MostRecentFailedEvent;
    /*0xFFFF is invalid value, only bit3 changed from 0 to 1 can affect the parameter's value*/
    Dem_EventIdType MostRecentConfirmedEvent;
} Dem_EventHeadType;

typedef struct
{
    uint8 EventFaultConfCnt;
#if(DEM_NUM_OF_INDICATOR > 0)
    /*SWS_Dem_00499*/
    uint8 IndicatorFailureCycleCounter;
    uint8 IndicatorHealingCycleCounter;
#endif
    /*SWS_Dem_00011*/
    uint8 EventOccurrence;/*Event occurrence*/
#if(DEM_CFG_DEBOUNCECOUNTERBASEDSUPPORT == STD_ON)
    /*SWS_Dem_00414*/
    sint16 EventDebounceCnt;/*Debounce Counter*/
#endif
#if(DEM_CFG_DEBOUNCETIMEBASEDSUPPORT == STD_ON)
    /*SWS_Dem_00426*/
    uint32 EventDebounceTimer;/*Debounce Timer*/
    Dem_EventStatusType TimerDirection;
#endif
    /*SWS_Dem_00788*/
    sint8 EventMaxFdcDuringCurrentCycle;
    /*SWS_Dem_00792*/
    sint8 EventMaxFdcSinceLastClear;
    /*SWS_Dem_00984*/
    uint8 EventCyclesSinceLastFailed;
    /*SWS_Dem_00775*/
    uint8 EventCyclesSinceFirstFailed;
    /*SWS_Dem_00779*/
    uint8 EventFailedCyclesSinceLastCleared;
#if((DEM_CFG_OBD_SUPPORT == DEM_OBD_MASTER_ECU)||(DEM_CFG_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU))
    /*number of continuous no fault operation cycle*/
    uint8 EventOBDPassedCyclesSinceLastFailed;
#endif
#if(DEM_CFG_MAXNUMBEREVENTENTRY_PERMANENT > 0)
    /*Used for clear permanent DTC,
    Reset condition: Event fail again/Data failed to recover from NVRAM;
    Set TRUE condition: When an external diagnostic device requests to clear the DTC.*/
    boolean EventClearFlagForPermanent;
#endif
#if(STD_ON == DEM_CMA_PLATFORM_ENABLED)
    /*SI30:
    **bit0:UDTC  bit1:UDTCTOC  bit2:UDTCSLC
    **bit3:ADTC  The four bits are not used, shall be set to 0.
    **bit4:SSLC  bit5:WIRSLC
    **bit6:ERDTC bit7:TFSLCA*/
    uint8 EventCMAStatus;
    uint8 EventPassedCyclesSinceLastFailed;
#endif
} Dem_EventEntryType;

typedef struct
{
    /*SWS_Dem_01183*/
    Dem_UdsStatusByteType DtcStatus;
    Dem_UdsStatusByteType DtcLastStatus;
    /*SWS_Dem_00019*//*SWS_Dem_00492*/
    uint8 DtcAgingCounter;
    /*User requirement*/
    uint8 DtcAgedCounter;
    /*0xFFFF is invalid value*/
    uint16 DataEntryRef;
#if(DEM_CFG_MAXNUMBEREVENTENTRY_MIRROR > 0)
    uint16 MirrorEntryRef;/*0xFFFF is invalid value*/
#endif
} Dem_DTCEntryType;

typedef struct
{
    boolean Used;
    /*SWS_Dem_00796*//*SWS_Dem_00039*/
#if(DEM_MAX_FFSIZE_OF_DTC > 0)
    uint8 FreezeFrameData[DEM_MAX_FFSIZE_OF_DTC];
#endif
#if(DEM_MAX_EXTSIZE_OF_DTC > 0)
    uint8 ExtendedData[DEM_MAX_EXTSIZE_OF_DTC];
#endif
#if(DEM_MAX_J1939FFSIZE_OF_DTC > 0)
    uint8 J1939FreezeFrameData[DEM_MAX_J1939FFSIZE_OF_DTC];
#endif
#if(DEM_MAX_J1939EXPFFSIZE_OF_DTC > 0)
    uint8 J1939ExpFreezeFrameData[DEM_MAX_J1939EXPFFSIZE_OF_DTC];
#endif
} Dem_DTCDataEntryType;


#if((DEM_CFG_OBD_SUPPORT == DEM_OBD_MASTER_ECU)||(DEM_CFG_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU))

#define DEM_NUM_OF_DEN_CONDITION   (uint8)4

typedef struct
{
    /*Used for PID01/41*/
    uint8 ReadinessGroupStatus[2];
    /*Used for PID31.Unit:m, Range:0-65535000*/
    uint32 DistanceSinceDtcCleared;
    /*Data for Service 02*/
    Dem_EventIdType ObdEventId;
    uint8 ObdFreezeFrameData[DEM_CFG_OBD_FF_LENGTH];
#if(DEM_NUM_OF_RATIO > 0)
    /*Data for Infotype 08/0B of Service 09*/
    uint16 RatioIGNCycleCounter;
    uint16 RatioGeneralDenominatorCounter;
    uint8 RatioGeneralDenominatorState;/*Same to RatioState*/
    Dem_IumprDenomCondStatusType RatioDenomCondStatus[DEM_NUM_OF_DEN_CONDITION];/*only 4 elements*/
    uint16 RatioNumerator[DEM_NUM_OF_RATIO];
    uint16 RatioDenominator[DEM_NUM_OF_RATIO];
    /*bit 0: Numerator increased flag;
      bit 1: Denominator increased flag;
      bit 2: Denominator lock flag.*/
    uint8 RatioState[DEM_NUM_OF_RATIO];
#endif
#if(DEM_CFG_MAXNUMBEREVENTENTRY_PERMANENT > 0)
    uint8 PfcCycleStatus;/*Permanent fault code - driving cycle Status*/
#endif
} Dem_OBDDataInfoType;

#endif/*#if((DEM_CFG_OBD_SUPPORT == DEM_OBD_MASTER_ECU)||(DEM_CFG_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU))*/

typedef struct
{
    Dem_EventHeadType EventHead;
    Dem_EventEntryType EventEntry[DEM_NUM_OF_EVENT];
    Dem_DTCEntryType DtcEntry[DEM_NUM_OF_DTC];
    uint16 PrimaryDataEntryUsedNum;
    Dem_DTCDataEntryType PrimaryDataEntry[DEM_CFG_MAXNUMBEREVENTENTRY_PRIMARY];
#if(DEM_NUM_OF_INDICATOR > 0)
    /*data struct is as below:
    --Indicator0--------|--Indicator1-----------...-----------|--IndicatorN...
    State00,...,State0X,|State10,..,State1Y,..................|StateN0,...StateNZ...*/
    Dem_IndicatorStatusType IndicatorStatus[DEM_NUM_OF_BYTE_RECORD_INDICATOR_STATE];
#endif/*#if(DEM_NUM_OF_INDICATOR > 0)*/
#if((DEM_CFG_OBD_SUPPORT == DEM_OBD_MASTER_ECU)||(DEM_CFG_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU))
    Dem_OBDDataInfoType OBDDataInfo;
#endif
#if(DEM_CFG_MAXNUMBEREVENTENTRY_PERMANENT > 0)
    uint16 PermanentEntryUsedNum;
    Dem_EventIdType PermanentDataEntry[DEM_CFG_MAXNUMBEREVENTENTRY_PERMANENT];
#endif/*#if(DEM_CFG_MAXNUMBEREVENTENTRY_PERMANENT > 0)*/

#if(DEM_CFG_MAXNUMBEREVENTENTRY_MIRROR > 0)
    uint16 MirrorEntryUsedNum;
    Dem_DTCDataEntryType MirrorDataEntry[DEM_CFG_MAXNUMBEREVENTENTRY_MIRROR];
#endif/*#if(DEM_CFG_MAXNUMBEREVENTENTRY_MIRROR > 0)*/
    uint32 DemCrcValue;
} Dem_StorageMemType;



#endif /* DEM_TYPES_H */


