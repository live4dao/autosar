/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : Rte_Type.h
********************************************************************************
*   Project/Product : AUTOSAR BSW PROJECT
*   Title           : Rte module configuration File
*   Author          : Hirain
********************************************************************************
*   Description     : Rte module configuration File
*
********************************************************************************
*   Limitations     : None
*
********************************************************************************
*
********************************************************************************
*   Revision History:
*
*   Version     Date          Initials      CR#          Descriptions
*   ---------   ----------    ------------  ----------   ---------------
*   V1.0.2_3.5.5_AZ240046       10/05/2024    Eas           N/A          N/A
*
********************************************************************************
* END_FILE_HDR*/
#ifndef RTE_TYPE_H
#define RTE_TYPE_H
/*******************************************************************************
*   Includes.
*******************************************************************************/
#include "Std_Types.h"

#define RTE_TRUE                                     1
#define RTE_FALSE                                    0
#define RTE_SERVER_RESPONSE_READY                    0
#define RTE_SERVER_RESPONSE_SUCCESS                  1
#define RTE_CLIENT_REQUESET_CLEAR                    0
#define RTE_CLIENT_REQUESET_SET                      1


/*******************************************************************************
* Macros and Typedef
*******************************************************************************/
/*SWS_Dcm_00977*/
/*SWS_Dcm_01003*/
typedef uint8 Dcm_SecLevelType;


/*SWS_Dcm_00978*/
/*SWS_Dcm_01004*/
typedef uint8 Dcm_SesCtrlType;

/*SWS_Dcm_00979*/
/*SWS_Dcm_01005*/
typedef uint8 Dcm_ProtocolType;

#define DCM_OBD_ON_CAN               (uint8)0x00
#define DCM_OBD_ON_FLEXRAY           (uint8)0x01
#define DCM_OBD_ON_IP                (uint8)0x02

#define DCM_UDS_ON_CAN               (uint8)0x03
#define DCM_UDS_ON_FLEXRAY           (uint8)0x04
#define DCM_UDS_ON_IP                (uint8)0x05

#define DCM_ROE_ON_CAN               (uint8)0x06
#define DCM_ROE_ON_FLEXRAY           (uint8)0x07
#define DCM_ROE_ON_IP                (uint8)0x08

#define DCM_PERIODICTRANS_ON_CAN     (uint8)0x09
#define DCM_PERIODICTRANS_ON_FLEXRAY (uint8)0x0A
#define DCM_PERIODICTRANS_ON_IP      (uint8)0x0B
#define DCM_UDS_ON_LIN               (uint8)0x0D

#define DCM_NO_ACTIVE_PROTOCOL       (uint8)0x0C
/*0x0D..0xEF Reserved for further AUTOSAR implementation*/



/*SWS_Dcm_00980*/
/*SWS_Dcm_01010*/
typedef uint8 Dcm_NegativeResponseCodeType;
/*SWS_Dcm_01307*/
#define DCM_POSITIVE_RESPONSE                           (uint8)0x00
/*range of values 0x01..0x0F reserved by ISO 14229*/
#define DCM_E_GENERALREJECT                             (uint8)0x10
#define DCM_E_SERVICENOTSUPPORTED                       (uint8)0x11
#define DCM_E_SUBFUNCTIONNOTSUPPORTED                   (uint8)0x12
#define DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT     (uint8)0x13
#define DCM_E_RESPONSETOOLONG                           (uint8)0x14
/*range of values 0x15..0x20 reserved by ISO 14229*/
#define DCM_E_BUSYREPEATREQUEST                         (uint8)0x21
#define DCM_E_CONDITIONSNOTCORRECT                      (uint8)0x22
/*value 0x23 reserved by ISO 14229*/
#define DCM_E_REQUESTSEQUENCEERROR                      (uint8)0x24
#define DCM_E_NORESPONSEFROMSUBNETCOMPONENT             (uint8)0x25
#define DCM_E_FAILUREPREVENTSEXECUTIONOFREQUESTEDACTION (uint8)0x26
/*range of values 0x27..0x30 reserved by ISO 14229*/
#define DCM_E_REQUESTOUTOFRANGE                         (uint8)0x31
/*value 0x32 reserved by ISO 14229*/
#define DCM_E_SECURITYACCESSDENIED                      (uint8)0x33
/*value 0x34 reserved by ISO 14229*/
#define DCM_E_INVALIDKEY                                (uint8)0x35
#define DCM_E_EXCEEDNUMBEROFATTEMPTS                    (uint8)0x36
#define DCM_E_REQUIREDTIMEDELAYNOTEXPIRED               (uint8)0x37
/*range of values 0x38..0x4F reserved by ISO 15764*/
/*range of values 0x50..0x6F reserved by ISO 14229*/
#define DCM_E_UPLOADDOWNLOADNOTACCEPTED                 (uint8)0x70
#define DCM_E_TRANSFERDATASUSPENDED                     (uint8)0x71
#define DCM_E_GENERALPROGRAMMINGFAILURE                 (uint8)0x72
#define DCM_E_WRONGBLOCKSEQUENCECOUNTER                 (uint8)0x73
/*range of values 0x74..0x77 reserved by ISO 14229*/
#define DCM_E_RESPONSEPENDING                           (uint8)0x78
/*range of values 0x79..0x7D reserved by ISO 14229*/
#define DCM_E_SUBFUNCTIONNOTSUPPORTEDINACTIVESESSION    (uint8)0x7E
#define DCM_E_SERVICENOTSUPPORTEDINACTIVESESSION        (uint8)0x7F
/*value 0x80 reserved by ISO 14229*/
#define DCM_E_RPMTOOHIGH                                (uint8)0x81
#define DCM_E_RPMTOOLOW                                 (uint8)0x82
#define DCM_E_ENGINEISRUNNING                           (uint8)0x83
#define DCM_E_ENGINEISNOTRUNNING                        (uint8)0x84
#define DCM_E_ENGINERUNTIMETOOLOW                       (uint8)0x85
#define DCM_E_TEMPERATURETOOHIGH                        (uint8)0x86
#define DCM_E_TEMPERATURETOOLOW                         (uint8)0x87
#define DCM_E_VEHICLESPEEDTOOHIGH                       (uint8)0x88
#define DCM_E_VEHICLESPEEDTOOLOW                        (uint8)0x89
#define DCM_E_THROTTLE_PEDALTOOHIGH                     (uint8)0x8A
#define DCM_E_THROTTLE_PEDALTOOLOW                      (uint8)0x8B
#define DCM_E_TRANSMISSIONRANGENOTINNEUTRAL             (uint8)0x8C
#define DCM_E_TRANSMISSIONRANGENOTINGEAR                (uint8)0x8D
/*value 0x8E reserved by ISO 14229*/
#define DCM_E_BRAKESWITCH_NOTCLOSED                     (uint8)0x8F
#define DCM_E_SHIFTERLEVERNOTINPARK                     (uint8)0x90
#define DCM_E_TORQUECONVERTERCLUTCHLOCKED               (uint8)0x91
#define DCM_E_VOLTAGETOOHIGH                            (uint8)0x92
#define DCM_E_VOLTAGETOOLOW                             (uint8)0x93
/*range of values 0x94..0xEF reserved by ISO 14229*/
/*value 0xFF reserved by ISO 14229*/


/*SWS_Dcm_00983*/
/*SWS_Dcm_01002*/
typedef uint8 Dcm_ConfirmationStatusType;

#define DCM_RES_POS_OK         (uint8)0x00
#define DCM_RES_POS_NOT_OK     (uint8)0x01
#define DCM_RES_NEG_OK         (uint8)0x02
#define DCM_RES_NEG_NOT_OK     (uint8)0x03


/*SWS_Dcm_00984*/
/*SWS_Dcm_01001*/
typedef uint8 Dcm_OpStatusType;

#define DCM_INITIAL            (uint8)0x00
#define DCM_PENDING            (uint8)0x01
#define DCM_CANCEL             (uint8)0x02
#define DCM_FORCE_RCRRP_OK     (uint8)0x03


/*SWS_Dcm_01305*/
typedef uint8 Dcm_InputOutputControlParameterType;

#define DCM_RETURN_CONTROL_TO_ECU    (uint8)0x00
#define DCM_RESET_TO_DEFAULT         (uint8)0x01
#define DCM_FREEZE_CURRENT_STATE     (uint8)0x02
#define DCM_SHORT_TERM_ADJUSTMENT    (uint8)0x03
/*SWS_Dem_00933*/
typedef uint8 Dem_DTCFormatType;
/*selects the 2-byte OBD DTC format (refer to configuration parameter DemObdDTC)*/
#define DEM_DTC_FORMAT_OBD                          ((Dem_DTCFormatType)0)
/*selects the 3-byte UDS DTC format (refer to configuration parameter DemUdsDTC)*/
#define DEM_DTC_FORMAT_UDS                          ((Dem_DTCFormatType)1)
/*selects the merged SPN + FMI to 3-byte J1939 DTC format (refer to DemJ1939DTC)*/
#define DEM_DTC_FORMAT_J1939                        ((Dem_DTCFormatType)2)
/*SWS_Dem_00925*/
typedef uint16 Dem_EventIdType;
#define DEM_EVENT_ID_INVALID                        ((Dem_EventIdType)0xFFFF)
/*SWS_Dem_00926*/
typedef uint8 Dem_EventStatusType;
#define DEM_EVENT_STATUS_PASSED                     ((Dem_EventStatusType)0x00)
#define DEM_EVENT_STATUS_FAILED                     ((Dem_EventStatusType)0x01)
#define DEM_EVENT_STATUS_PREPASSED                  ((Dem_EventStatusType)0x02)
#define DEM_EVENT_STATUS_PREFAILED                  ((Dem_EventStatusType)0x03)
#define DEM_EVENT_STATUS_FDC_THRESHOLD_REACHED      ((Dem_EventStatusType)0x04)
/*SWS_Dem_01000*/
typedef uint8 Dem_DebouncingStateType;
/*Bit 0: Temporarily Defective(corresponds to 0 <FDC < 127)*/
#define DEM_TEMPORARILY_DEFECTIVE                   ((Dem_DebouncingStateType)0x01)
/*Bit 1: finally Defective(corresponds to FDC =127)*/
#define DEM_FINALLY_DEFECTIVE                       ((Dem_DebouncingStateType)0x02)
/*Bit 2: temporarily healed(corresponds to -128 <FDC < 0)*/
#define DEM_TEMPORARILY_HEALED                      ((Dem_DebouncingStateType)0x04)
/*Bit 3: Test complete (corresponds to FDC = -128 or FDC = 127)*/
#define DEM_TEST_COMPLETE                           ((Dem_DebouncingStateType)0x08)
/*Bit 4: DTR Update (= Test complete && Debouncing complete && enable
conditions/storage conditions fulfilled)*/
#define DEM_DTR_UPDATE                              ((Dem_DebouncingStateType)0x10)
/*SWS_Dem_00927*/
typedef uint8 Dem_DebounceResetStatusType;
#define DEM_DEBOUNCE_STATUS_FREEZE                  ((Dem_DebounceResetStatusType)0x00)
#define DEM_DEBOUNCE_STATUS_RESET                   ((Dem_DebounceResetStatusType)0x01)
/*SWS_Dem_00928*/
typedef uint8 Dem_UdsStatusByteType;
#define DEM_UDS_STATUS_TF                           ((Dem_UdsStatusByteType)0x01)/*bit 0: TestFailed*/
#define DEM_UDS_STATUS_TFTOC                        ((Dem_UdsStatusByteType)0x02)/*bit 1: TestFailedThisOperationCycle*/
#define DEM_UDS_STATUS_PDTC                         ((Dem_UdsStatusByteType)0x04)/*bit 2: PendingDTC*/
#define DEM_UDS_STATUS_CDTC                         ((Dem_UdsStatusByteType)0x08)/*bit 3: ConfirmedDTC*/
#define DEM_UDS_STATUS_TNCSLC                       ((Dem_UdsStatusByteType)0x10)/*bit 4: TestNotCompletedSinceLastClear*/
#define DEM_UDS_STATUS_TFSLC                        ((Dem_UdsStatusByteType)0x20)/*bit 5: TestFailedSinceLastClear*/
#define DEM_UDS_STATUS_TNCTOC                       ((Dem_UdsStatusByteType)0x40)/*bit 6: TestNotCompletedThisOperationCycle*/
#define DEM_UDS_STATUS_WIR                          ((Dem_UdsStatusByteType)0x80)/*bit 7: WarningIndicatorRequested*/
/*SWS_Dem_00929*/
typedef uint8 Dem_OperationCycleStateType;
#define DEM_CYCLE_STATE_START                       ((Dem_OperationCycleStateType)0x01)
#define DEM_CYCLE_STATE_END                         ((Dem_OperationCycleStateType)0x02)
/*SWS_Dem_00930*/
typedef uint8 Dem_IndicatorStatusType;
#define DEM_INDICATOR_OFF                           ((Dem_IndicatorStatusType)0x00)
#define DEM_INDICATOR_CONTINUOUS                    ((Dem_IndicatorStatusType)0x01)
#define DEM_INDICATOR_BLINKING                      ((Dem_IndicatorStatusType)0x02)
#define DEM_INDICATOR_BLINK_CONT                    ((Dem_IndicatorStatusType)0x03)
#define DEM_INDICATOR_SLOW_FLASH                    ((Dem_IndicatorStatusType)0x04)
#define DEM_INDICATOR_FAST_FLASH                    ((Dem_IndicatorStatusType)0x05)
#define DEM_INDICATOR_ON_DEMAND                     ((Dem_IndicatorStatusType)0x06)
#define DEM_INDICATOR_SHORT                         ((Dem_IndicatorStatusType)0x07)
/*SWS_Dem_00932*/
typedef uint8 Dem_DTCKindType;
#define DEM_DTC_KIND_ALL_DTCS                       ((Dem_DTCKindType)0x01)/*Select all DTCs*/
#define DEM_DTC_KIND_EMISSION_REL_DTCS              ((Dem_DTCKindType)0x02)/*Select OBD-relevant DTCs*/
/*SWS_Dem_00934*/
typedef uint8 Dem_DTCOriginType;
/*Event information located in the primary memory*/
#define DEM_DTC_ORIGIN_PRIMARY_MEMORY               ((Dem_DTCOriginType)0x01)
/*Event information located in the mirror memory*/
#define DEM_DTC_ORIGIN_MIRROR_MEMORY                ((Dem_DTCOriginType)0x02)
/*The Event information is located in the permanent memory*/
#define DEM_DTC_ORIGIN_PERMANENT_MEMORY             ((Dem_DTCOriginType)0x03)
/*Event information located in the user defined memory, where XX is the configured
DemUserDefinedMemoryIdentifier in hexadecimal*/
#define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_XX        ((Dem_DTCOriginType)0x04)
/*SWS_Dem_00942*/
typedef uint8 Dem_InitMonitorReasonType;
/*Event was cleared and all internal values and states are reset.*/
#define DEM_INIT_MONITOR_CLEAR                      ((Dem_InitMonitorReasonType)0x01)
/*Operation cycle of the event was (re-)started.*/
#define DEM_INIT_MONITOR_RESTART                    ((Dem_InitMonitorReasonType)0x02)
/*Enable conditions or DTC settings re-enabled.*/
#define DEM_INIT_MONITOR_REENABLED                  ((Dem_InitMonitorReasonType)0x03)
/*Storage condition reenabled.*/
#define DEM_INIT_MONITOR_STORAGE_REENABLED          ((Dem_InitMonitorReasonType)0x04)
/*SWS_Dem_00944*/
/*This type contains all possible states of an additional IUMPR denominator
condition to be broadcasted among OBD-relevant ECUs.*/
typedef enum
{
    /*Condition of IUMPRDenominator given by IUMPRDenCondId is not met (yet).*/
    DEM_IUMPR_DEN_STATUS_NOT_REACHED = 0x00,
    /*Condition of IUMPRDenominator given by IUMPRDenCondId is met*/
    DEM_IUMPR_DEN_STATUS_REACHED     = 0x01,
    /*Condition of IUMPRDenominator given by IUMPRDenCondId is inhibited and cannot be reached.*/
    DEM_IUMPR_DEN_STATUS_INHIBITED   = 0x02
} Dem_IumprDenomCondStatusType;


/*SWS_KeyM_00038*/
typedef enum
{
    KEYM_START_OEM_PRODUCTIONMODE = 0x01,
    KEYM_START_WORKSHOPMODE       = 0x02,

}KeyM_StartType;

/*SWS_KeyM_00300*/
typedef uint16 KeyM_CertElementIdType;

/*SWS_KeyM_00301*/
typedef uint16 KeyM_CertificateIdType;

/*SWS_KeyM_00039*/
typedef enum
{
    KEYM_SERVICE_CERT_REQUEST_CSR         = 0x01,
    KEYM_SERVICE_CERT_UPDATE_SIGNED_CSR   = 0x02,
    KEYM_SERVICE_CERT_SET_ROOT            = 0x03,
    KEYM_SERVICE_CERT_UPDATE_ROOT         = 0x04,
    KEYM_SERVICE_CERT_SET_INTERMEDIATE    = 0x05,
    KEYM_SERVICE_CERT_UPDATE_INTERMEDIATE = 0x06,
    KEYM_SERVICE_CERT_UPDATE_CRL          = 0x07,

}KeyM_ServiceCertificateType;


/*SWS_KeyM_91003*/
typedef enum
{
    KEYM_CERTIFICATE_VALID                    = 0x00,
    KEYM_CERTIFICATE_INVALID                  = 0x01,
    KEYM_CERTIFICATE_NOT_PARSED               = 0x02,
    KEYM_CERTIFICATE_PARSED_NOT_VALIDATED     = 0x03,
    KEYM_CERTIFICATE_NOT_AVAILABLE            = 0x04,
    KEYM_E_CERTIFICATE_VALIDITY_PERIOD_FAIL   = 0x05,
    KEYM_E_CERTIFICATE_SIGNATURE_FAIL         = 0x06,
    KEYM_E_CERTIFICATE_INVALID_CHAIN_OF_TRUST = 0x07,
    KEYM_E_CERTIFICATE_INVALID_TYPE           = 0x08,
    KEYM_E_CERTIFICATE_INVALID_FORMAT         = 0x09,
    KEYM_E_CERTIFICATE_INVALID_CONTENT        = 0x0A,
    KEYM_E_CERTIFICATE_REVOKED                = 0x0B,
}KeyM_CertificateStatusType;

/*SWS_KeyM_91012*/
typedef uint8 KeyM_CryptoKeyDataType;

/*SWS_KeyM_91008*/
typedef enum
{
    KEYM_RT_OK                          = 0x00,
    KEYM_RT_NOT_OK                      = 0x01,
    KEYM_RT_KEY_CERT_INVALID            = 0x02,
    KEYM_RT_KEY_CERT_WRITE_FAIL         = 0x03,
    KEYM_RT_KEY_CERT_UPDATE_FAIL        = 0x04,
    KEYM_RT_CERT_INVALID_CHAIN_OF_TRUST = 0x05,

}KeyM_ResultType;

#ifndef CxFFF_Invalid
#define CxFFF_Invalid 4095U
#endif /* CxFFF_Invalid */

#ifndef CxFF_Invalid
#define CxFF_Invalid 255U
#endif /* CxFF_Invalid */

#ifndef Value0
#define Value0 0U
#endif /* Value0 */

#ifndef NVM_REQ_OK
#define NVM_REQ_OK 0x00U
#endif /* NVM_REQ_OK */

#ifndef NVM_REQ_NOT_OK
#define NVM_REQ_NOT_OK 0x01U
#endif /* NVM_REQ_NOT_OK */

#ifndef NVM_REQ_PENDING
#define NVM_REQ_PENDING 0x02U
#endif /* NVM_REQ_PENDING */

#ifndef NVM_REQ_INTEGRITY_FAILED
#define NVM_REQ_INTEGRITY_FAILED 0x03U
#endif /* NVM_REQ_INTEGRITY_FAILED */

#ifndef NVM_REQ_BLOCK_SKIPPED
#define NVM_REQ_BLOCK_SKIPPED 0x04U
#endif /* NVM_REQ_BLOCK_SKIPPED */

#ifndef NVM_REQ_NV_INVALIDATED
#define NVM_REQ_NV_INVALIDATED 0x05U
#endif /* NVM_REQ_NV_INVALIDATED */

#ifndef NVM_REQ_CANCELED
#define NVM_REQ_CANCELED 0x06U
#endif /* NVM_REQ_CANCELED */

#ifndef NVM_REQ_REDUNDANCY_FAILED
#define NVM_REQ_REDUNDANCY_FAILED 0x07U
#endif /* NVM_REQ_REDUNDANCY_FAILED */

#ifndef NVM_REQ_RESTORED_FROM_ROM
#define NVM_REQ_RESTORED_FROM_ROM 0x08U
#endif /* NVM_REQ_RESTORED_FROM_ROM */

// #ifndef TIMEOUT
// #define TIMEOUT 0x01U
// #endif /* TIMEOUT */

// #ifndef TIMELEAP
// #define TIMELEAP 0x02U
// #endif /* TIMELEAP */

// #ifndef SYNC_TO_GATEWAY
// #define SYNC_TO_GATEWAY 0x04U
// #endif /* SYNC_TO_GATEWAY */

// #ifndef GLOBAL_TIME_BASE
// #define GLOBAL_TIME_BASE 0x08U
// #endif /* GLOBAL_TIME_BASE */

#ifndef false
#define false 0U
#endif /* false */

#ifndef true
#define true 1U
#endif /* true */

#ifndef FALSE
#define FALSE 0U
#endif /* FALSE */

#ifndef TRUE
#define TRUE 1U
#endif /* TRUE */

/*******************************************************************************
*   Implementing Data Type Definition.
*******************************************************************************/
typedef uint8 ABSActive_IDT;
typedef uint8 ABSFailed_IDT;
typedef uint8 ABS_EBDFailed_IDT;
typedef uint8 ABS_FLWheelDirection_IDT;
typedef uint8 ABS_FLWheelSpeedInvalid_IDT;
typedef uint16 ABS_FLWheelSpeedKPH_IDT;
typedef uint8 ABS_FLWheelSpeedRCSts_IDT;
typedef uint16 ABS_FLWheelSpeedRC_IDT;
typedef uint8 ABS_FRWheelDirection_IDT;
typedef uint8 ABS_FRWheelSpeedInvalid_IDT;
typedef uint16 ABS_FRWheelSpeedKPH_IDT;
typedef uint8 ABS_FRWheelSpeedRCSts_IDT;
typedef uint16 ABS_FRWheelSpeedRC_IDT;
typedef uint8 ABS_FWSpeMCUKPH_AliveCounter_IDT;
typedef uint8 ABS_FWSpeMCUKPH_CheckSum_IDT;
typedef uint8 ABS_HAZActive_IDT;
typedef uint8 ABS_LowBrakeFluid_IDT;
typedef uint8 ABS_RLWheelDirection_IDT;
typedef uint8 ABS_RLWheelSpeedInvalid_IDT;
typedef uint16 ABS_RLWheelSpeedKPH_IDT;
typedef uint8 ABS_RLWheelSpeedRCSts_IDT;
typedef uint16 ABS_RLWheelSpeedRC_IDT;
typedef uint8 ABS_RRWheelDirection_IDT;
typedef uint8 ABS_RRWheelSpeedInvalid_IDT;
typedef uint16 ABS_RRWheelSpeedKPH_IDT;
typedef uint8 ABS_RRWheelSpeedRCSts_IDT;
typedef uint16 ABS_RRWheelSpeedRC_IDT;
typedef uint8 ABS_RWSpeMCUKPH_AliveCounter_IDT;
typedef uint8 ABS_RWSpeMCUKPH_CheckSum_IDT;
typedef uint8 ABS_Status_AliveCounter_IDT;
typedef uint8 ABS_Status_CheckSum_IDT;
typedef uint8 ABS_VehicleSpeedInvalid_IDT;
typedef uint16 ABS_VehicleSpeed_IDT;
typedef uint8 ABS_WheelSpeMCURC_AliveCounter_IDT;
typedef uint8 ABS_WheelSpeMCURC_CheckSum_IDT;
typedef uint8 AB_BrkPedalPctV_IDT;
typedef uint8 AB_BrkPedalPct_IDT;
typedef uint8 AB_BrkPedalSwStsV_IDT;
typedef uint8 AB_BrkPedalSwSts_IDT;
typedef uint8 AB_BrkPedalTravelV_IDT;
typedef uint16 AB_BrkPedalTravel_IDT;
typedef uint8 AB_Fault_Status_IDT;
typedef uint8 AB_IBS_Sys_Fault_Sts_IDT;
typedef uint8 ACC_AdtLowerJerkLimit_IDT;
typedef uint8 ACC_AdtUpperJerkLimit_IDT;
typedef uint8 ACC_DriveoffReq_IDT;
typedef uint8 ACC_ObjDispSts_IDT;
typedef struct
{
    uint8 ADAS_ACC_SpdUnit;
    uint8 ADAS_ACC_TargetSpeed;
    uint8 ADAS_ACC_OperatingSts;
    uint8 ADAS_ACC_TimeGapLevel;
    uint8 ADAS_ACC_DistanceLevel;
    uint8 ADAS_ACC_ObjDispSts;
    uint8 ADAS_ACC_TakeOverReq;
    float32 ADAS_AccelerationReq;
    float32 ADAS_MaxSoftAcceleration;
    float32 ADAS_MinSoftAcceleration;
    uint8 ADAS_IBS_StopReq;
    uint8 ADAS_IBS_CarStarting;
    uint8 ADAS_ACC_BrakePreferred;
    uint8 ADAS_IBS_MinBreakReq;
    uint8 ADAS_VLCShutDownReq;
    uint8 ADAS_VLCModeReq;
    float32 ACC_AdtUpperJerkLimit;
    float32 ACC_AdtLowerJerkLimit;
    uint8 ACC_TxtInfoForDriver;
    uint8 ACC_DriveoffReq;
} ACC_Output;

typedef uint8 ACC_TakeOverReq_IDT;
typedef uint8 ACC_TxtInfoForDriver_IDT;
typedef uint8 ACU_AirbagWarningStatus_IDT;
typedef uint8 ACU_AliveCounter_IDT;
typedef uint8 ACU_CheckSum_IDT;
typedef uint8 ACU_CoDAirbagStatus_IDT;
typedef uint8 ACU_CoDSeatOccupSensorStat_IDT;
typedef uint8 ACU_CoDSeatbeltBucklestatus_IDT;
typedef uint8 ACU_CoDSeatbletPTighten_IDT;
typedef uint8 ACU_CrashFrontOutputSts_IDT;
typedef uint8 ACU_CrashLeftOutputSts_IDT;
typedef uint8 ACU_CrashRearOutputSts_IDT;
typedef uint8 ACU_CrashRightOutputSts_IDT;
typedef uint8 ACU_CrashSts_IDT;
typedef uint8 ACU_DAirbagStatus_IDT;
typedef uint8 ACU_DSeatOccupSensorStat_IDT;
typedef uint8 ACU_DSeatbeltBucklestatus_IDT;
typedef uint8 ACU_DSeatbletPTighten_IDT;
typedef uint8 ACU_LCABsts_IDT;
typedef uint8 ACU_LPSeatOccupSensorStat_IDT;
typedef uint8 ACU_LPSeatbeltBucklestatus_IDT;
typedef uint8 ACU_LSABsts_IDT;
typedef uint8 ACU_MPSeatOccupSensorStat_IDT;
typedef uint8 ACU_MPSeatbeltBucklestatus_IDT;
typedef uint8 ACU_RCABsts_IDT;
typedef uint8 ACU_RPSeatOccupSensorStat_IDT;
typedef uint8 ACU_RPSeatbeltBucklestatus_IDT;
typedef uint8 ACU_RSABsts_IDT;
typedef uint8 ADAS_01_Checksum_IDT;
typedef uint8 ADAS_01_RollingCounter_IDT;
typedef uint8 ADAS_02_Checksum_IDT;
typedef uint8 ADAS_02_RollingCounter_IDT;
typedef uint8 ADAS_03_Checksum_IDT;
typedef uint8 ADAS_03_RollingCounter_IDT;
typedef uint8 ADAS_ACC_BrakePreferred_IDT;
typedef uint8 ADAS_ACC_DistanceLevel_IDT;
typedef uint8 ADAS_ACC_ObjDispSts_IDT;
typedef uint8 ADAS_ACC_OperatingSts_IDT;
typedef uint8 ADAS_ACC_SpdUnit_IDT;
typedef uint8 ADAS_ACC_TakeOverReq_IDT;
typedef uint8 ADAS_ACC_TargetSpeed_IDT;
typedef uint8 ADAS_ACC_TimeGapLevel_IDT;
typedef uint8 ADAS_AEB_AbaLevel_IDT;
typedef uint8 ADAS_AEB_AbpReq_IDT;
typedef uint8 ADAS_AEB_FuncSWResp_IDT;
typedef uint16 ADAS_AEB_TgtDecel_ReqValue_IDT;
typedef uint8 ADAS_APA_AbortWarning_IDT;
typedef uint8 ADAS_APA_BrakeModeSts_IDT;
typedef uint8 ADAS_APA_LightReq_IDT;
typedef uint8 ADAS_APA_ModeSelect_IDT;
typedef uint8 ADAS_APA_OperationSts_IDT;
typedef uint8 ADAS_APA_OtherWarning_IDT;
typedef uint8 ADAS_APA_OverspeedAlarm_IDT;
typedef uint8 ADAS_APA_ParkingDirection_IDT;
typedef uint8 ADAS_APA_ParkingModeReq_IDT;
typedef uint8 ADAS_APA_ParkingType_IDT;
typedef uint8 ADAS_APA_PauseWarning_IDT;
typedef uint8 ADAS_APA_RemindTxt1_IDT;
typedef uint8 ADAS_APA_RemindTxt2_IDT;
typedef uint8 ADAS_APA_RenewParkingReq_IDT;
typedef uint8 ADAS_APA_SearchingWarning_IDT;
typedef uint8 ADAS_APA_Soundremind_IDT;
typedef uint8 ADAS_APA_StartParkingReq_IDT;
typedef uint8 ADAS_APA_SuggestedID_IDT;
typedef uint8 ADAS_APA_SystemSts_IDT;
typedef uint16 ADAS_AccelerationReq_IDT;
typedef struct
{
    float32 ADAS_AEB_TgtDecel_ReqValue;
    uint8 ADAS_AEB_AbpReq;
    uint8 ADAS_IBS_EBAReq;
    uint8 AEB_AWB_Level;
    uint8 AEB_ABA_Req;
    uint8 AEB_VehHldReq;
    uint8 AEB_TgtDecel_Req;
    uint8 AEB_AWB_Req;
    uint8 ADAS_AEB_AbaLevel;
    uint8 ADAS_AEB_FuncSWResp;
    uint8 AEB_FuncSts;
    uint8 AEB_VehActive;
    uint8 AEB_VRUActive;
    uint8 AEB_ErrorSts;
    uint8 AEB_FCW_SnvtyResp;
    uint8 AEB_FCW_Warning;
} AEB_OutPut;

typedef struct
{
    uint8 ADAS_LSS_AssidFormResp;
    float32 ADAS_LSS_AngCmdReqPortnValue;
    float32 ADAS_EPS_TargetSteeringAngle;
    uint8 ADAS_EPS_Vibration_Req;
    uint8 ADAS_LSS_VoiceWarn;
    uint8 ADAS_LSS_HandsoffWarn;
    uint8 ADAS_LSS_FuncResp;
    uint8 ADAS_EPS_AngReqSts;
    uint8 ADAS_LSS_LeLineTrackingSts;
    uint8 ADAS_LSS_RiLineTrackingSts;
    uint8 ADAS_LSS_Available;
    uint8 ADAS_LSS_FunSts;
    uint8 ADAS_LSS_ErrSts;
    uint8 ADAS_LSS_WarnFromResp;
    uint8 FC_CalibrationSts;
    uint8 FC_BlockageSts;
} LSS_Output;

typedef struct
{
    uint8 ADAS_TSR_SWSts;
    uint8 TSR_SLWSwtResp;
    uint8 ADAS_TSR_OperationSts;
    uint8 ADAS_TSR_SpeedLimit;
    uint8 TSR_TrafSign;
    uint8 TSR_SpdAssistInfoDisp;
    uint8 TSR_Warning_offset;
    uint8 TSR_SLWVisualWarn;
    uint8 TSR_SLWVoiceWarn;
} TSR_Output;

typedef struct
{
    AEB_OutPut aeb_output;
    ACC_Output acc_output;
    LSS_Output lss_output;
    TSR_Output tsr_output;
} ADAS_CAN_Output;

typedef uint8 ADAS_ECU_Fault_IDT;
typedef uint16 ADAS_EPSAngleReq;
typedef uint8 ADAS_EPS_AngReqSts_IDT;
typedef uint16 ADAS_EPS_TargetSteeringAngle_IDT;
typedef uint8 ADAS_EPS_Vibration_Req_IDT;
typedef uint8 ADAS_FrontCamera_Fault_IDT;
typedef uint8 ADAS_IBS_BreakOverrideSystem_IDT;
typedef uint8 ADAS_IBS_BreakWarningLevel_IDT;
typedef uint8 ADAS_IBS_CarStarting_IDT;
typedef uint8 ADAS_IBS_EBAReq_IDT;
typedef uint8 ADAS_IBS_MinBreakReq_IDT;
typedef uint8 ADAS_IBS_PrefillActive_IDT;
typedef uint8 ADAS_IBS_StopReq_IDT;
typedef uint16 ADAS_IDB_TargetDecel;
typedef uint16 ADAS_LSS_AngCmdReqPortnValue_IDT;
typedef uint8 ADAS_LSS_AssidFormResp_IDT;
typedef uint8 ADAS_LSS_Available_IDT;
typedef uint8 ADAS_LSS_ErrSts_IDT;
typedef uint8 ADAS_LSS_FunSts_IDT;
typedef uint8 ADAS_LSS_FuncResp_IDT;
typedef uint8 ADAS_LSS_HandsoffWarn_IDT;
typedef uint8 ADAS_LSS_LeLineTrackingSts_IDT;
typedef uint8 ADAS_LSS_RiLineTrackingSts_IDT;
typedef uint8 ADAS_LSS_VoiceWarn_IDT;
typedef uint8 ADAS_LSS_WarnFromResp_IDT;
typedef uint8 ADAS_LeftCamera_Fault_IDT;
typedef uint16 ADAS_MaxSoftAcceleration_IDT;
typedef uint16 ADAS_MinSoftAcceleration_IDT;
typedef uint8 ADAS_RAEB_Target_Deceleration;
typedef uint8 ADAS_RearCamera_Fault_IDT;
typedef uint8 ADAS_RightCamera_Fault_IDT;
typedef uint8 ADAS_TSR_OperationSts_IDT;
typedef uint8 ADAS_TSR_SWSts_IDT;
typedef uint8 ADAS_TSR_SpeedLimit_IDT;
typedef uint8 ADAS_USS_FaultFLI_IDT;
typedef uint8 ADAS_USS_FaultFLO_IDT;
typedef uint8 ADAS_USS_FaultFLS_IDT;
typedef uint8 ADAS_USS_FaultFRI_IDT;
typedef uint8 ADAS_USS_FaultFRO_IDT;
typedef uint8 ADAS_USS_FaultFRS_IDT;
typedef uint8 ADAS_USS_FaultRLI_IDT;
typedef uint8 ADAS_USS_FaultRLO_IDT;
typedef uint8 ADAS_USS_FaultRLS_IDT;
typedef uint8 ADAS_USS_FaultRRI_IDT;
typedef uint8 ADAS_USS_FaultRRO_IDT;
typedef uint8 ADAS_USS_FaultRRS_IDT;
typedef uint16 ADAS_VCU_Wheeltorque;
typedef uint8 ADAS_VLCModeReq_IDT;
typedef uint8 ADAS_VLCShutDownReq_IDT;
typedef uint8 AEB_ABA_Req_IDT;
typedef uint8 AEB_AWB_Level_IDT;
typedef uint8 AEB_AWB_Req_IDT;
typedef uint8 AEB_Emergency_Braking_Level_IDT;
typedef uint8 AEB_ErrorSts_IDT;
typedef uint8 AEB_FCW_SnvtyRWCBS_IDT;
typedef uint8 AEB_FCW_SnvtyReq_IDT;
typedef uint8 AEB_FCW_SnvtyResp_IDT;
typedef uint8 AEB_FCW_Warning_IDT;
typedef uint8 AEB_FuncSts_IDT;
typedef uint8 AEB_FuncSwtReq_IDT;
typedef uint8 AEB_PressureHold_IDT;
typedef uint8 AEB_TgtDecel_Req_IDT;
typedef uint8 AEB_VRUActive_IDT;
typedef uint8 AEB_VehActive_IDT;
typedef uint8 AEB_VehHldReq_IDT;
typedef struct
{
    uint64 time_stamp;
    uint64 time_stamp_can;
    uint8 m_iuss_state_obs;
    uint8 need_replan_stop;
    uint8 plan_trigger;
    uint8 control_enable;
    uint8 control_status;
    uint8 apa_run_state;
} APAControlState;

typedef uint8 serial_number_16[16];
typedef struct
{
    uint64 time_stamp;
    uint32 frame_index;
    float32 p0_x;
    float32 p0_y;
    float32 p1_x;
    float32 p1_y;
    float32 p2_x;
    float32 p2_y;
    float32 p3_x;
    float32 p3_y;
    float32 width;
    float32 depth;
    uint8 direction;
    uint8 slot_type;
    uint8 slot_status;
    uint8 slot_detection_type;
    uint8 slot_occupied;
    uint8 quality;
    float32 angle;
    float32 lane_width;
    uint8 tracking_id;
    serial_number_16 serial_number;
} ParkingSlot;

typedef struct
{
    uint8 replan_counter;
    ParkingSlot planning_slot;
} PlanningSlotLocked;

typedef struct
{
    float32 x;
    float32 y;
    float32 heading;
    float32 arc_length_to_end;
    float32 curve;
    float32 steering_angle;
    float32 maxvel;
    float32 acc;
    float32 speed;
    float32 time_to_end;
} TrajectoryPoint;

typedef struct
{
    uint8 replan_counter;
    uint8 trajectory_id;
    uint32 trajectory_point_id;
    float32 cur_vehicle_brake;
    float32 exp_vehicle_brake;
    float32 cur_vehicle_throttle;
    float32 exp_vehicle_throttle;
    float32 cur_vehicle_lon_acc;
    float32 exp_vehicle_lon_acc;
    uint8 cur_vehicle_gear;
    uint8 exp_vehicle_gear;
    TrajectoryPoint exp_point;
    TrajectoryPoint cur_point;
} TrackingPointsDebug;

typedef struct
{
    uint8 tracking_error_status;
    uint8 cur_trajectory_finish;
    uint8 points_to_end;
} TrackingState;

typedef ParkingSlot slot_set_12[12];
typedef struct
{
    uint64 time_stamp;
    uint64 time_stamp_slot;
    uint32 frame_index;
    uint8 slot_cnt;
    slot_set_12 slot_set;
} ParkingSlotSet;

typedef struct
{
    uint64 time_stamp;
    uint64 time_stamp_fusion;
    PlanningSlotLocked planning_slot_locked;
    TrackingPointsDebug tracking_points_debug;
    TrackingState tracking_state;
    ParkingSlotSet planning_fusion_slot_set;
    ParkingSlotSet tracking_slot_set_debug;
} APAPlanningControlDebug;

typedef uint8 APA_ChimeRequest_IDT;
typedef uint8 APA_EPS_AngReqSts_IDT;
typedef uint16 APA_EPS_TargetSteeringAngle_IDT;
typedef uint8 APA_FRegion1ObjectSts_IDT;
typedef uint8 APA_FRegion2ObjectSts_IDT;
typedef uint8 APA_FRegion3ObjectSts_IDT;
typedef uint8 APA_FRegion4ObjectSts_IDT;
typedef uint8 APA_FrontExtenedDistance_IDT;
typedef uint8 APA_FrontSystemSts_IDT;
typedef uint8 APA_ParkAssistRExtenedDistance_IDT;
typedef uint8 APA_ParkAssistRRegion1ObjectSts_IDT;
typedef uint8 APA_ParkAssistRRegion2ObjectSts_IDT;
typedef uint8 APA_ParkAssistRRegion3ObjectSts_IDT;
typedef uint8 APA_ParkAssistRRegion4ObjectSts_IDT;
typedef uint8 APA_RearSystemSts_IDT;
typedef uint8 APA_WCBS_BrakeFunctionMode_IDT;
typedef uint8 APA_WCBS_BrakeMode_IDT;
typedef uint8 APA_WCBS_ExpectedGearPosition_IDT;
typedef uint8 APA_WCBS_SpeedLimitation_IDT;
typedef uint16 APA_WCBS_TargetStopDistance_IDT;
typedef uint8 APA_WCB_BrakeControlReq_IDT;
typedef uint8 APA_slot_10_IDT;
typedef uint8 APA_slot_11_IDT;
typedef uint8 APA_slot_12_IDT;
typedef uint8 APA_slot_1_IDT;
typedef uint8 APA_slot_2_IDT;
typedef uint8 APA_slot_3_IDT;
typedef uint8 APA_slot_4_IDT;
typedef uint8 APA_slot_5_IDT;
typedef uint8 APA_slot_6_IDT;
typedef uint8 APA_slot_7_IDT;
typedef uint8 APA_slot_8_IDT;
typedef uint8 APA_slot_9_IDT;
typedef uint16 APA_slot_ID_10_P0_X_IDT;
typedef uint16 APA_slot_ID_10_P0_Y_IDT;
typedef uint16 APA_slot_ID_10_P1_X_IDT;
typedef uint16 APA_slot_ID_10_P1_Y_IDT;
typedef uint16 APA_slot_ID_10_P2_X_IDT;
typedef uint16 APA_slot_ID_10_P2_Y_IDT;
typedef uint16 APA_slot_ID_10_P3_X_IDT;
typedef uint16 APA_slot_ID_10_P3_Y_IDT;
typedef uint8 APA_slot_ID_10_Type_IDT;
typedef uint16 APA_slot_ID_11_P0_X_IDT;
typedef uint16 APA_slot_ID_11_P0_Y_IDT;
typedef uint16 APA_slot_ID_11_P1_X_IDT;
typedef uint16 APA_slot_ID_11_P1_Y_IDT;
typedef uint16 APA_slot_ID_11_P2_X_IDT;
typedef uint16 APA_slot_ID_11_P2_Y_IDT;
typedef uint16 APA_slot_ID_11_P3_X_IDT;
typedef uint16 APA_slot_ID_11_P3_Y_IDT;
typedef uint8 APA_slot_ID_11_Type_IDT;
typedef uint16 APA_slot_ID_12_P0_X_IDT;
typedef uint16 APA_slot_ID_12_P0_Y_IDT;
typedef uint16 APA_slot_ID_12_P1_X_IDT;
typedef uint16 APA_slot_ID_12_P1_Y_IDT;
typedef uint16 APA_slot_ID_12_P2_X_IDT;
typedef uint16 APA_slot_ID_12_P2_Y_IDT;
typedef uint16 APA_slot_ID_12_P3_X_IDT;
typedef uint16 APA_slot_ID_12_P3_Y_IDT;
typedef uint8 APA_slot_ID_12_Type_IDT;
typedef uint16 APA_slot_ID_1_P0_X_IDT;
typedef uint16 APA_slot_ID_1_P0_Y_IDT;
typedef uint16 APA_slot_ID_1_P1_X_IDT;
typedef uint16 APA_slot_ID_1_P1_Y_IDT;
typedef uint16 APA_slot_ID_1_P2_X_IDT;
typedef uint16 APA_slot_ID_1_P2_Y_IDT;
typedef uint16 APA_slot_ID_1_P3_X_IDT;
typedef uint16 APA_slot_ID_1_P3_Y_IDT;
typedef uint8 APA_slot_ID_1_Type_IDT;
typedef uint16 APA_slot_ID_2_P0_X_IDT;
typedef uint16 APA_slot_ID_2_P0_Y_IDT;
typedef uint16 APA_slot_ID_2_P1_X_IDT;
typedef uint16 APA_slot_ID_2_P1_Y_IDT;
typedef uint16 APA_slot_ID_2_P2_X_IDT;
typedef uint16 APA_slot_ID_2_P2_Y_IDT;
typedef uint16 APA_slot_ID_2_P3_X_IDT;
typedef uint16 APA_slot_ID_2_P3_Y_IDT;
typedef uint8 APA_slot_ID_2_Type_IDT;
typedef uint16 APA_slot_ID_3_P0_X_IDT;
typedef uint16 APA_slot_ID_3_P0_Y_IDT;
typedef uint16 APA_slot_ID_3_P1_X_IDT;
typedef uint16 APA_slot_ID_3_P1_Y_IDT;
typedef uint16 APA_slot_ID_3_P2_X_IDT;
typedef uint16 APA_slot_ID_3_P2_Y_IDT;
typedef uint16 APA_slot_ID_3_P3_X_IDT;
typedef uint16 APA_slot_ID_3_P3_Y_IDT;
typedef uint8 APA_slot_ID_3_Type_IDT;
typedef uint16 APA_slot_ID_4_P0_X_IDT;
typedef uint16 APA_slot_ID_4_P0_Y_IDT;
typedef uint16 APA_slot_ID_4_P1_X_IDT;
typedef uint16 APA_slot_ID_4_P1_Y_IDT;
typedef uint16 APA_slot_ID_4_P2_X_IDT;
typedef uint16 APA_slot_ID_4_P2_Y_IDT;
typedef uint16 APA_slot_ID_4_P3_X_IDT;
typedef uint16 APA_slot_ID_4_P3_Y_IDT;
typedef uint8 APA_slot_ID_4_Type_IDT;
typedef uint16 APA_slot_ID_5_P0_X_IDT;
typedef uint16 APA_slot_ID_5_P0_Y_IDT;
typedef uint16 APA_slot_ID_5_P1_X_IDT;
typedef uint16 APA_slot_ID_5_P1_Y_IDT;
typedef uint16 APA_slot_ID_5_P2_X_IDT;
typedef uint16 APA_slot_ID_5_P2_Y_IDT;
typedef uint16 APA_slot_ID_5_P3_X_IDT;
typedef uint16 APA_slot_ID_5_P3_Y_IDT;
typedef uint8 APA_slot_ID_5_Type_IDT;
typedef uint16 APA_slot_ID_6_P0_X_IDT;
typedef uint16 APA_slot_ID_6_P0_Y_IDT;
typedef uint16 APA_slot_ID_6_P1_X_IDT;
typedef uint16 APA_slot_ID_6_P1_Y_IDT;
typedef uint16 APA_slot_ID_6_P2_X_IDT;
typedef uint16 APA_slot_ID_6_P2_Y_IDT;
typedef uint16 APA_slot_ID_6_P3_X_IDT;
typedef uint16 APA_slot_ID_6_P3_Y_IDT;
typedef uint8 APA_slot_ID_6_Type_IDT;
typedef uint16 APA_slot_ID_7_P0_X_IDT;
typedef uint16 APA_slot_ID_7_P0_Y_IDT;
typedef uint16 APA_slot_ID_7_P1_X_IDT;
typedef uint16 APA_slot_ID_7_P1_Y_IDT;
typedef uint16 APA_slot_ID_7_P2_X_IDT;
typedef uint16 APA_slot_ID_7_P2_Y_IDT;
typedef uint16 APA_slot_ID_7_P3_X_IDT;
typedef uint16 APA_slot_ID_7_P3_Y_IDT;
typedef uint8 APA_slot_ID_7_Type_IDT;
typedef uint16 APA_slot_ID_8_P0_X_IDT;
typedef uint16 APA_slot_ID_8_P0_Y_IDT;
typedef uint16 APA_slot_ID_8_P1_X_IDT;
typedef uint16 APA_slot_ID_8_P1_Y_IDT;
typedef uint16 APA_slot_ID_8_P2_X_IDT;
typedef uint16 APA_slot_ID_8_P2_Y_IDT;
typedef uint16 APA_slot_ID_8_P3_X_IDT;
typedef uint16 APA_slot_ID_8_P3_Y_IDT;
typedef uint8 APA_slot_ID_8_Type_IDT;
typedef uint16 APA_slot_ID_9_P0_X_IDT;
typedef uint16 APA_slot_ID_9_P0_Y_IDT;
typedef uint16 APA_slot_ID_9_P1_X_IDT;
typedef uint16 APA_slot_ID_9_P1_Y_IDT;
typedef uint16 APA_slot_ID_9_P2_X_IDT;
typedef uint16 APA_slot_ID_9_P2_Y_IDT;
typedef uint16 APA_slot_ID_9_P3_X_IDT;
typedef uint16 APA_slot_ID_9_P3_Y_IDT;
typedef uint8 APA_slot_ID_9_Type_IDT;
typedef uint16 ARS_CFGSTATE_CRC16_Checksum_IDT;
typedef uint8 ARS_CFGSTATE_Mode_IDT;
typedef uint8 ARS_CFGSTATE_MsgCounter_IDT;
typedef uint8 ARS_CFGSTATE_SensorID_CFGflag_IDT;
typedef uint8 ARS_CFGSTATE_SensorID_IDT;
typedef uint16 ARS_CFGSTATE_VehParCoverDamping_IDT;
typedef uint16 ARS_CFGSTATE_VehParLatPos_IDT;
typedef uint16 ARS_CFGSTATE_VehParLongPos_IDT;
typedef uint16 ARS_CFGSTATE_VehParSteeringRatio_IDT;
typedef uint16 ARS_CFGSTATE_VehParVertPos_IDT;
typedef uint16 ARS_CFGSTATE_VehParWheelBase_IDT;
typedef uint16 ARS_CFGSTATE_VehParYawAngle_IDT;
typedef uint8 ARS_CFGST_TmeSynEnFl_IDT;
typedef uint8 ARS_CFGST_VehParStrRatio_CFGfl_IDT;
typedef uint16 ARS_CFGST_VehPrAxLdDistr0_IDT;
typedef uint8 ARS_CFGST_VehPrAxLdDstr_CFGfl_IDT;
typedef uint8 ARS_CFGST_VehPrCntrGrvHght_CFGfl_IDT;
typedef uint16 ARS_CFGST_VehPrCntrOfGrvHght_IDT;
typedef uint8 ARS_CFGST_VehPrCvrDmp_CFGfl_IDT;
typedef uint8 ARS_CFGST_VehPrLatPos_CFGfl_IDT;
typedef uint8 ARS_CFGST_VehPrLngPosCoG_CFGfl_IDT;
typedef uint16 ARS_CFGST_VehPrLngPosCoG_IDT;
typedef uint8 ARS_CFGST_VehPrLngPos_CFGfl_IDT;
typedef uint8 ARS_CFGST_VehPrSnsrOri_CFGfl_IDT;
typedef uint8 ARS_CFGST_VehPrSnsrOri_IDT;
typedef uint8 ARS_CFGST_VehPrTrWdFrnt_CFGfl_IDT;
typedef uint8 ARS_CFGST_VehPrTrWdRear_CFGfl_IDT;
typedef uint16 ARS_CFGST_VehPrTrkWdthFrnt_IDT;
typedef uint16 ARS_CFGST_VehPrTrkWdthRear_IDT;
typedef uint8 ARS_CFGST_VehPrVehWght_CFGfl_IDT;
typedef uint16 ARS_CFGST_VehPrVehWght_IDT;
typedef uint8 ARS_CFGST_VehPrVrtPos_CFGfl_IDT;
typedef uint8 ARS_CFGST_VehPrWhlBs_CFGfl_IDT;
typedef uint8 ARS_CFGST_VehPrYwAng_CFGfl_IDT;
typedef uint8 ARS_CFG_ProtoclFlag_P_IDT;
typedef uint8 ARS_CFG_VParPitchAngle_CFGflag_IDT;
typedef uint16 ARS_CFG_VParPitchAngle_IDT;
typedef uint8 ARS_OD_AabsXStd_Obj_00_IDT;
typedef uint8 ARS_OD_AabsXStd_Obj_01_IDT;
typedef uint8 ARS_OD_AabsXStd_Obj_02_IDT;
typedef uint8 ARS_OD_AabsXStd_Obj_03_IDT;
typedef uint8 ARS_OD_AabsXStd_Obj_04_IDT;
typedef uint8 ARS_OD_AabsXStd_Obj_05_IDT;
typedef uint8 ARS_OD_AabsXStd_Obj_06_IDT;
typedef uint8 ARS_OD_AabsXStd_Obj_07_IDT;
typedef uint8 ARS_OD_AabsXStd_Obj_08_IDT;
typedef uint8 ARS_OD_AabsXStd_Obj_09_IDT;
typedef uint8 ARS_OD_AabsXStd_Obj_10_IDT;
typedef uint8 ARS_OD_AabsXStd_Obj_11_IDT;
typedef uint8 ARS_OD_AabsXStd_Obj_12_IDT;
typedef uint8 ARS_OD_AabsXStd_Obj_13_IDT;
typedef uint8 ARS_OD_AabsXStd_Obj_14_IDT;
typedef uint8 ARS_OD_AabsXStd_Obj_15_IDT;
typedef uint8 ARS_OD_AabsXStd_Obj_16_IDT;
typedef uint8 ARS_OD_AabsXStd_Obj_17_IDT;
typedef uint8 ARS_OD_AabsXStd_Obj_18_IDT;
typedef uint8 ARS_OD_AabsXStd_Obj_19_IDT;
typedef uint8 ARS_OD_AabsXStd_Obj_20_IDT;
typedef uint8 ARS_OD_AabsXStd_Obj_21_IDT;
typedef uint8 ARS_OD_AabsXStd_Obj_22_IDT;
typedef uint8 ARS_OD_AabsXStd_Obj_23_IDT;
typedef uint8 ARS_OD_AabsXStd_Obj_24_IDT;
typedef uint8 ARS_OD_AabsXStd_Obj_25_IDT;
typedef uint8 ARS_OD_AabsXStd_Obj_26_IDT;
typedef uint8 ARS_OD_AabsXStd_Obj_27_IDT;
typedef uint8 ARS_OD_AabsXStd_Obj_28_IDT;
typedef uint8 ARS_OD_AabsXStd_Obj_29_IDT;
typedef uint8 ARS_OD_AabsXStd_Obj_30_IDT;
typedef uint8 ARS_OD_AabsXStd_Obj_31_IDT;
typedef uint8 ARS_OD_AabsXStd_Obj_32_IDT;
typedef uint8 ARS_OD_AabsXStd_Obj_33_IDT;
typedef uint8 ARS_OD_AabsXStd_Obj_34_IDT;
typedef uint8 ARS_OD_AabsXStd_Obj_35_IDT;
typedef uint8 ARS_OD_AabsXStd_Obj_36_IDT;
typedef uint8 ARS_OD_AabsXStd_Obj_37_IDT;
typedef uint8 ARS_OD_AabsXStd_Obj_38_IDT;
typedef uint8 ARS_OD_AabsXStd_Obj_39_IDT;
typedef uint8 ARS_OD_AabsXStd_Obj_40_IDT;
typedef uint8 ARS_OD_AabsXStd_Obj_41_IDT;
typedef uint8 ARS_OD_AabsXStd_Obj_42_IDT;
typedef uint8 ARS_OD_AabsXStd_Obj_43_IDT;
typedef uint8 ARS_OD_AabsXStd_Obj_44_IDT;
typedef uint8 ARS_OD_AabsXStd_Obj_45_IDT;
typedef uint8 ARS_OD_AabsXStd_Obj_46_IDT;
typedef uint8 ARS_OD_AabsXStd_Obj_47_IDT;
typedef uint8 ARS_OD_AabsXStd_Obj_48_IDT;
typedef uint8 ARS_OD_AabsXStd_Obj_49_IDT;
typedef uint8 ARS_OD_AabsXStd_Obj_50_IDT;
typedef uint8 ARS_OD_AabsXStd_Obj_51_IDT;
typedef uint8 ARS_OD_AabsXStd_Obj_52_IDT;
typedef uint8 ARS_OD_AabsXStd_Obj_53_IDT;
typedef uint8 ARS_OD_AabsXStd_Obj_54_IDT;
typedef uint8 ARS_OD_AabsXStd_Obj_55_IDT;
typedef uint8 ARS_OD_AabsXStd_Obj_56_IDT;
typedef uint8 ARS_OD_AabsXStd_Obj_57_IDT;
typedef uint8 ARS_OD_AabsXStd_Obj_58_IDT;
typedef uint8 ARS_OD_AabsXStd_Obj_59_IDT;
typedef uint16 ARS_OD_AabsX_Obj_00_IDT;
typedef uint16 ARS_OD_AabsX_Obj_01_IDT;
typedef uint16 ARS_OD_AabsX_Obj_02_IDT;
typedef uint16 ARS_OD_AabsX_Obj_03_IDT;
typedef uint16 ARS_OD_AabsX_Obj_04_IDT;
typedef uint16 ARS_OD_AabsX_Obj_05_IDT;
typedef uint16 ARS_OD_AabsX_Obj_06_IDT;
typedef uint16 ARS_OD_AabsX_Obj_07_IDT;
typedef uint16 ARS_OD_AabsX_Obj_08_IDT;
typedef uint16 ARS_OD_AabsX_Obj_09_IDT;
typedef uint16 ARS_OD_AabsX_Obj_10_IDT;
typedef uint16 ARS_OD_AabsX_Obj_11_IDT;
typedef uint16 ARS_OD_AabsX_Obj_12_IDT;
typedef uint16 ARS_OD_AabsX_Obj_13_IDT;
typedef uint16 ARS_OD_AabsX_Obj_14_IDT;
typedef uint16 ARS_OD_AabsX_Obj_15_IDT;
typedef uint16 ARS_OD_AabsX_Obj_16_IDT;
typedef uint16 ARS_OD_AabsX_Obj_17_IDT;
typedef uint16 ARS_OD_AabsX_Obj_18_IDT;
typedef uint16 ARS_OD_AabsX_Obj_19_IDT;
typedef uint16 ARS_OD_AabsX_Obj_20_IDT;
typedef uint16 ARS_OD_AabsX_Obj_21_IDT;
typedef uint16 ARS_OD_AabsX_Obj_22_IDT;
typedef uint16 ARS_OD_AabsX_Obj_23_IDT;
typedef uint16 ARS_OD_AabsX_Obj_24_IDT;
typedef uint16 ARS_OD_AabsX_Obj_25_IDT;
typedef uint16 ARS_OD_AabsX_Obj_26_IDT;
typedef uint16 ARS_OD_AabsX_Obj_27_IDT;
typedef uint16 ARS_OD_AabsX_Obj_28_IDT;
typedef uint16 ARS_OD_AabsX_Obj_29_IDT;
typedef uint16 ARS_OD_AabsX_Obj_30_IDT;
typedef uint16 ARS_OD_AabsX_Obj_31_IDT;
typedef uint16 ARS_OD_AabsX_Obj_32_IDT;
typedef uint16 ARS_OD_AabsX_Obj_33_IDT;
typedef uint16 ARS_OD_AabsX_Obj_34_IDT;
typedef uint16 ARS_OD_AabsX_Obj_35_IDT;
typedef uint16 ARS_OD_AabsX_Obj_36_IDT;
typedef uint16 ARS_OD_AabsX_Obj_37_IDT;
typedef uint16 ARS_OD_AabsX_Obj_38_IDT;
typedef uint16 ARS_OD_AabsX_Obj_39_IDT;
typedef uint16 ARS_OD_AabsX_Obj_40_IDT;
typedef uint16 ARS_OD_AabsX_Obj_41_IDT;
typedef uint16 ARS_OD_AabsX_Obj_42_IDT;
typedef uint16 ARS_OD_AabsX_Obj_43_IDT;
typedef uint16 ARS_OD_AabsX_Obj_44_IDT;
typedef uint16 ARS_OD_AabsX_Obj_45_IDT;
typedef uint16 ARS_OD_AabsX_Obj_46_IDT;
typedef uint16 ARS_OD_AabsX_Obj_47_IDT;
typedef uint16 ARS_OD_AabsX_Obj_48_IDT;
typedef uint16 ARS_OD_AabsX_Obj_49_IDT;
typedef uint16 ARS_OD_AabsX_Obj_50_IDT;
typedef uint16 ARS_OD_AabsX_Obj_51_IDT;
typedef uint16 ARS_OD_AabsX_Obj_52_IDT;
typedef uint16 ARS_OD_AabsX_Obj_53_IDT;
typedef uint16 ARS_OD_AabsX_Obj_54_IDT;
typedef uint16 ARS_OD_AabsX_Obj_55_IDT;
typedef uint16 ARS_OD_AabsX_Obj_56_IDT;
typedef uint16 ARS_OD_AabsX_Obj_57_IDT;
typedef uint16 ARS_OD_AabsX_Obj_58_IDT;
typedef uint16 ARS_OD_AabsX_Obj_59_IDT;
typedef uint8 ARS_OD_AabsYStd_Obj_00_IDT;
typedef uint8 ARS_OD_AabsYStd_Obj_01_IDT;
typedef uint8 ARS_OD_AabsYStd_Obj_02_IDT;
typedef uint8 ARS_OD_AabsYStd_Obj_03_IDT;
typedef uint8 ARS_OD_AabsYStd_Obj_04_IDT;
typedef uint8 ARS_OD_AabsYStd_Obj_05_IDT;
typedef uint8 ARS_OD_AabsYStd_Obj_06_IDT;
typedef uint8 ARS_OD_AabsYStd_Obj_07_IDT;
typedef uint8 ARS_OD_AabsYStd_Obj_08_IDT;
typedef uint8 ARS_OD_AabsYStd_Obj_09_IDT;
typedef uint8 ARS_OD_AabsYStd_Obj_10_IDT;
typedef uint8 ARS_OD_AabsYStd_Obj_11_IDT;
typedef uint8 ARS_OD_AabsYStd_Obj_12_IDT;
typedef uint8 ARS_OD_AabsYStd_Obj_13_IDT;
typedef uint8 ARS_OD_AabsYStd_Obj_14_IDT;
typedef uint8 ARS_OD_AabsYStd_Obj_15_IDT;
typedef uint8 ARS_OD_AabsYStd_Obj_16_IDT;
typedef uint8 ARS_OD_AabsYStd_Obj_17_IDT;
typedef uint8 ARS_OD_AabsYStd_Obj_18_IDT;
typedef uint8 ARS_OD_AabsYStd_Obj_19_IDT;
typedef uint8 ARS_OD_AabsYStd_Obj_20_IDT;
typedef uint8 ARS_OD_AabsYStd_Obj_21_IDT;
typedef uint8 ARS_OD_AabsYStd_Obj_22_IDT;
typedef uint8 ARS_OD_AabsYStd_Obj_23_IDT;
typedef uint8 ARS_OD_AabsYStd_Obj_24_IDT;
typedef uint8 ARS_OD_AabsYStd_Obj_25_IDT;
typedef uint8 ARS_OD_AabsYStd_Obj_26_IDT;
typedef uint8 ARS_OD_AabsYStd_Obj_27_IDT;
typedef uint8 ARS_OD_AabsYStd_Obj_28_IDT;
typedef uint8 ARS_OD_AabsYStd_Obj_29_IDT;
typedef uint8 ARS_OD_AabsYStd_Obj_30_IDT;
typedef uint8 ARS_OD_AabsYStd_Obj_31_IDT;
typedef uint8 ARS_OD_AabsYStd_Obj_32_IDT;
typedef uint8 ARS_OD_AabsYStd_Obj_33_IDT;
typedef uint8 ARS_OD_AabsYStd_Obj_34_IDT;
typedef uint8 ARS_OD_AabsYStd_Obj_35_IDT;
typedef uint8 ARS_OD_AabsYStd_Obj_36_IDT;
typedef uint8 ARS_OD_AabsYStd_Obj_37_IDT;
typedef uint8 ARS_OD_AabsYStd_Obj_38_IDT;
typedef uint8 ARS_OD_AabsYStd_Obj_39_IDT;
typedef uint8 ARS_OD_AabsYStd_Obj_40_IDT;
typedef uint8 ARS_OD_AabsYStd_Obj_41_IDT;
typedef uint8 ARS_OD_AabsYStd_Obj_42_IDT;
typedef uint8 ARS_OD_AabsYStd_Obj_43_IDT;
typedef uint8 ARS_OD_AabsYStd_Obj_44_IDT;
typedef uint8 ARS_OD_AabsYStd_Obj_45_IDT;
typedef uint8 ARS_OD_AabsYStd_Obj_46_IDT;
typedef uint8 ARS_OD_AabsYStd_Obj_47_IDT;
typedef uint8 ARS_OD_AabsYStd_Obj_48_IDT;
typedef uint8 ARS_OD_AabsYStd_Obj_49_IDT;
typedef uint8 ARS_OD_AabsYStd_Obj_50_IDT;
typedef uint8 ARS_OD_AabsYStd_Obj_51_IDT;
typedef uint8 ARS_OD_AabsYStd_Obj_52_IDT;
typedef uint8 ARS_OD_AabsYStd_Obj_53_IDT;
typedef uint8 ARS_OD_AabsYStd_Obj_54_IDT;
typedef uint8 ARS_OD_AabsYStd_Obj_55_IDT;
typedef uint8 ARS_OD_AabsYStd_Obj_56_IDT;
typedef uint8 ARS_OD_AabsYStd_Obj_57_IDT;
typedef uint8 ARS_OD_AabsYStd_Obj_58_IDT;
typedef uint8 ARS_OD_AabsYStd_Obj_59_IDT;
typedef uint16 ARS_OD_AabsY_Obj_00_IDT;
typedef uint16 ARS_OD_AabsY_Obj_01_IDT;
typedef uint16 ARS_OD_AabsY_Obj_02_IDT;
typedef uint16 ARS_OD_AabsY_Obj_03_IDT;
typedef uint16 ARS_OD_AabsY_Obj_04_IDT;
typedef uint16 ARS_OD_AabsY_Obj_05_IDT;
typedef uint16 ARS_OD_AabsY_Obj_06_IDT;
typedef uint16 ARS_OD_AabsY_Obj_07_IDT;
typedef uint16 ARS_OD_AabsY_Obj_08_IDT;
typedef uint16 ARS_OD_AabsY_Obj_09_IDT;
typedef uint16 ARS_OD_AabsY_Obj_10_IDT;
typedef uint16 ARS_OD_AabsY_Obj_11_IDT;
typedef uint16 ARS_OD_AabsY_Obj_12_IDT;
typedef uint16 ARS_OD_AabsY_Obj_13_IDT;
typedef uint16 ARS_OD_AabsY_Obj_14_IDT;
typedef uint16 ARS_OD_AabsY_Obj_15_IDT;
typedef uint16 ARS_OD_AabsY_Obj_16_IDT;
typedef uint16 ARS_OD_AabsY_Obj_17_IDT;
typedef uint16 ARS_OD_AabsY_Obj_18_IDT;
typedef uint16 ARS_OD_AabsY_Obj_19_IDT;
typedef uint16 ARS_OD_AabsY_Obj_20_IDT;
typedef uint16 ARS_OD_AabsY_Obj_21_IDT;
typedef uint16 ARS_OD_AabsY_Obj_22_IDT;
typedef uint16 ARS_OD_AabsY_Obj_23_IDT;
typedef uint16 ARS_OD_AabsY_Obj_24_IDT;
typedef uint16 ARS_OD_AabsY_Obj_25_IDT;
typedef uint16 ARS_OD_AabsY_Obj_26_IDT;
typedef uint16 ARS_OD_AabsY_Obj_27_IDT;
typedef uint16 ARS_OD_AabsY_Obj_28_IDT;
typedef uint16 ARS_OD_AabsY_Obj_29_IDT;
typedef uint16 ARS_OD_AabsY_Obj_30_IDT;
typedef uint16 ARS_OD_AabsY_Obj_31_IDT;
typedef uint16 ARS_OD_AabsY_Obj_32_IDT;
typedef uint16 ARS_OD_AabsY_Obj_33_IDT;
typedef uint16 ARS_OD_AabsY_Obj_34_IDT;
typedef uint16 ARS_OD_AabsY_Obj_35_IDT;
typedef uint16 ARS_OD_AabsY_Obj_36_IDT;
typedef uint16 ARS_OD_AabsY_Obj_37_IDT;
typedef uint16 ARS_OD_AabsY_Obj_38_IDT;
typedef uint16 ARS_OD_AabsY_Obj_39_IDT;
typedef uint16 ARS_OD_AabsY_Obj_40_IDT;
typedef uint16 ARS_OD_AabsY_Obj_41_IDT;
typedef uint16 ARS_OD_AabsY_Obj_42_IDT;
typedef uint16 ARS_OD_AabsY_Obj_43_IDT;
typedef uint16 ARS_OD_AabsY_Obj_44_IDT;
typedef uint16 ARS_OD_AabsY_Obj_45_IDT;
typedef uint16 ARS_OD_AabsY_Obj_46_IDT;
typedef uint16 ARS_OD_AabsY_Obj_47_IDT;
typedef uint16 ARS_OD_AabsY_Obj_48_IDT;
typedef uint16 ARS_OD_AabsY_Obj_49_IDT;
typedef uint16 ARS_OD_AabsY_Obj_50_IDT;
typedef uint16 ARS_OD_AabsY_Obj_51_IDT;
typedef uint16 ARS_OD_AabsY_Obj_52_IDT;
typedef uint16 ARS_OD_AabsY_Obj_53_IDT;
typedef uint16 ARS_OD_AabsY_Obj_54_IDT;
typedef uint16 ARS_OD_AabsY_Obj_55_IDT;
typedef uint16 ARS_OD_AabsY_Obj_56_IDT;
typedef uint16 ARS_OD_AabsY_Obj_57_IDT;
typedef uint16 ARS_OD_AabsY_Obj_58_IDT;
typedef uint16 ARS_OD_AabsY_Obj_59_IDT;
typedef uint16 ARS_OD_CRC16_Checksum_Header_IDT;
typedef uint16 ARS_OD_CRC16_Checksum_Obj_00_01_IDT;
typedef uint16 ARS_OD_CRC16_Checksum_Obj_02_03_IDT;
typedef uint16 ARS_OD_CRC16_Checksum_Obj_04_05_IDT;
typedef uint16 ARS_OD_CRC16_Checksum_Obj_06_07_IDT;
typedef uint16 ARS_OD_CRC16_Checksum_Obj_08_09_IDT;
typedef uint16 ARS_OD_CRC16_Checksum_Obj_10_11_IDT;
typedef uint16 ARS_OD_CRC16_Checksum_Obj_12_13_IDT;
typedef uint16 ARS_OD_CRC16_Checksum_Obj_14_15_IDT;
typedef uint16 ARS_OD_CRC16_Checksum_Obj_16_17_IDT;
typedef uint16 ARS_OD_CRC16_Checksum_Obj_18_19_IDT;
typedef uint16 ARS_OD_CRC16_Checksum_Obj_20_21_IDT;
typedef uint16 ARS_OD_CRC16_Checksum_Obj_22_23_IDT;
typedef uint16 ARS_OD_CRC16_Checksum_Obj_24_25_IDT;
typedef uint16 ARS_OD_CRC16_Checksum_Obj_26_27_IDT;
typedef uint16 ARS_OD_CRC16_Checksum_Obj_28_29_IDT;
typedef uint16 ARS_OD_CRC16_Checksum_Obj_30_31_IDT;
typedef uint16 ARS_OD_CRC16_Checksum_Obj_32_33_IDT;
typedef uint16 ARS_OD_CRC16_Checksum_Obj_34_35_IDT;
typedef uint16 ARS_OD_CRC16_Checksum_Obj_36_37_IDT;
typedef uint16 ARS_OD_CRC16_Checksum_Obj_38_39_IDT;
typedef uint16 ARS_OD_CRC16_Checksum_Obj_40_41_IDT;
typedef uint16 ARS_OD_CRC16_Checksum_Obj_42_43_IDT;
typedef uint16 ARS_OD_CRC16_Checksum_Obj_44_45_IDT;
typedef uint16 ARS_OD_CRC16_Checksum_Obj_46_47_IDT;
typedef uint16 ARS_OD_CRC16_Checksum_Obj_48_49_IDT;
typedef uint16 ARS_OD_CRC16_Checksum_Obj_50_51_IDT;
typedef uint16 ARS_OD_CRC16_Checksum_Obj_52_53_IDT;
typedef uint16 ARS_OD_CRC16_Checksum_Obj_54_55_IDT;
typedef uint16 ARS_OD_CRC16_Checksum_Obj_56_57_IDT;
typedef uint16 ARS_OD_CRC16_Checksum_Obj_58_59_IDT;
typedef uint8 ARS_OD_ClassConf_Obj_00_IDT;
typedef uint8 ARS_OD_ClassConf_Obj_01_IDT;
typedef uint8 ARS_OD_ClassConf_Obj_02_IDT;
typedef uint8 ARS_OD_ClassConf_Obj_03_IDT;
typedef uint8 ARS_OD_ClassConf_Obj_04_IDT;
typedef uint8 ARS_OD_ClassConf_Obj_05_IDT;
typedef uint8 ARS_OD_ClassConf_Obj_06_IDT;
typedef uint8 ARS_OD_ClassConf_Obj_07_IDT;
typedef uint8 ARS_OD_ClassConf_Obj_08_IDT;
typedef uint8 ARS_OD_ClassConf_Obj_09_IDT;
typedef uint8 ARS_OD_ClassConf_Obj_10_IDT;
typedef uint8 ARS_OD_ClassConf_Obj_11_IDT;
typedef uint8 ARS_OD_ClassConf_Obj_12_IDT;
typedef uint8 ARS_OD_ClassConf_Obj_13_IDT;
typedef uint8 ARS_OD_ClassConf_Obj_14_IDT;
typedef uint8 ARS_OD_ClassConf_Obj_15_IDT;
typedef uint8 ARS_OD_ClassConf_Obj_16_IDT;
typedef uint8 ARS_OD_ClassConf_Obj_17_IDT;
typedef uint8 ARS_OD_ClassConf_Obj_18_IDT;
typedef uint8 ARS_OD_ClassConf_Obj_19_IDT;
typedef uint8 ARS_OD_ClassConf_Obj_20_IDT;
typedef uint8 ARS_OD_ClassConf_Obj_21_IDT;
typedef uint8 ARS_OD_ClassConf_Obj_22_IDT;
typedef uint8 ARS_OD_ClassConf_Obj_23_IDT;
typedef uint8 ARS_OD_ClassConf_Obj_24_IDT;
typedef uint8 ARS_OD_ClassConf_Obj_25_IDT;
typedef uint8 ARS_OD_ClassConf_Obj_26_IDT;
typedef uint8 ARS_OD_ClassConf_Obj_27_IDT;
typedef uint8 ARS_OD_ClassConf_Obj_28_IDT;
typedef uint8 ARS_OD_ClassConf_Obj_29_IDT;
typedef uint8 ARS_OD_ClassConf_Obj_30_IDT;
typedef uint8 ARS_OD_ClassConf_Obj_31_IDT;
typedef uint8 ARS_OD_ClassConf_Obj_32_IDT;
typedef uint8 ARS_OD_ClassConf_Obj_33_IDT;
typedef uint8 ARS_OD_ClassConf_Obj_34_IDT;
typedef uint8 ARS_OD_ClassConf_Obj_35_IDT;
typedef uint8 ARS_OD_ClassConf_Obj_36_IDT;
typedef uint8 ARS_OD_ClassConf_Obj_37_IDT;
typedef uint8 ARS_OD_ClassConf_Obj_38_IDT;
typedef uint8 ARS_OD_ClassConf_Obj_39_IDT;
typedef uint8 ARS_OD_ClassConf_Obj_40_IDT;
typedef uint8 ARS_OD_ClassConf_Obj_41_IDT;
typedef uint8 ARS_OD_ClassConf_Obj_42_IDT;
typedef uint8 ARS_OD_ClassConf_Obj_43_IDT;
typedef uint8 ARS_OD_ClassConf_Obj_44_IDT;
typedef uint8 ARS_OD_ClassConf_Obj_45_IDT;
typedef uint8 ARS_OD_ClassConf_Obj_46_IDT;
typedef uint8 ARS_OD_ClassConf_Obj_47_IDT;
typedef uint8 ARS_OD_ClassConf_Obj_48_IDT;
typedef uint8 ARS_OD_ClassConf_Obj_49_IDT;
typedef uint8 ARS_OD_ClassConf_Obj_50_IDT;
typedef uint8 ARS_OD_ClassConf_Obj_51_IDT;
typedef uint8 ARS_OD_ClassConf_Obj_52_IDT;
typedef uint8 ARS_OD_ClassConf_Obj_53_IDT;
typedef uint8 ARS_OD_ClassConf_Obj_54_IDT;
typedef uint8 ARS_OD_ClassConf_Obj_55_IDT;
typedef uint8 ARS_OD_ClassConf_Obj_56_IDT;
typedef uint8 ARS_OD_ClassConf_Obj_57_IDT;
typedef uint8 ARS_OD_ClassConf_Obj_58_IDT;
typedef uint8 ARS_OD_ClassConf_Obj_59_IDT;
typedef uint8 ARS_OD_Classification_Obj_00_IDT;
typedef uint8 ARS_OD_Classification_Obj_01_IDT;
typedef uint8 ARS_OD_Classification_Obj_02_IDT;
typedef uint8 ARS_OD_Classification_Obj_03_IDT;
typedef uint8 ARS_OD_Classification_Obj_04_IDT;
typedef uint8 ARS_OD_Classification_Obj_05_IDT;
typedef uint8 ARS_OD_Classification_Obj_06_IDT;
typedef uint8 ARS_OD_Classification_Obj_07_IDT;
typedef uint8 ARS_OD_Classification_Obj_08_IDT;
typedef uint8 ARS_OD_Classification_Obj_09_IDT;
typedef uint8 ARS_OD_Classification_Obj_10_IDT;
typedef uint8 ARS_OD_Classification_Obj_11_IDT;
typedef uint8 ARS_OD_Classification_Obj_12_IDT;
typedef uint8 ARS_OD_Classification_Obj_13_IDT;
typedef uint8 ARS_OD_Classification_Obj_14_IDT;
typedef uint8 ARS_OD_Classification_Obj_15_IDT;
typedef uint8 ARS_OD_Classification_Obj_16_IDT;
typedef uint8 ARS_OD_Classification_Obj_17_IDT;
typedef uint8 ARS_OD_Classification_Obj_18_IDT;
typedef uint8 ARS_OD_Classification_Obj_19_IDT;
typedef uint8 ARS_OD_Classification_Obj_20_IDT;
typedef uint8 ARS_OD_Classification_Obj_21_IDT;
typedef uint8 ARS_OD_Classification_Obj_22_IDT;
typedef uint8 ARS_OD_Classification_Obj_23_IDT;
typedef uint8 ARS_OD_Classification_Obj_24_IDT;
typedef uint8 ARS_OD_Classification_Obj_25_IDT;
typedef uint8 ARS_OD_Classification_Obj_26_IDT;
typedef uint8 ARS_OD_Classification_Obj_27_IDT;
typedef uint8 ARS_OD_Classification_Obj_28_IDT;
typedef uint8 ARS_OD_Classification_Obj_29_IDT;
typedef uint8 ARS_OD_Classification_Obj_30_IDT;
typedef uint8 ARS_OD_Classification_Obj_31_IDT;
typedef uint8 ARS_OD_Classification_Obj_32_IDT;
typedef uint8 ARS_OD_Classification_Obj_33_IDT;
typedef uint8 ARS_OD_Classification_Obj_34_IDT;
typedef uint8 ARS_OD_Classification_Obj_35_IDT;
typedef uint8 ARS_OD_Classification_Obj_36_IDT;
typedef uint8 ARS_OD_Classification_Obj_37_IDT;
typedef uint8 ARS_OD_Classification_Obj_38_IDT;
typedef uint8 ARS_OD_Classification_Obj_39_IDT;
typedef uint8 ARS_OD_Classification_Obj_40_IDT;
typedef uint8 ARS_OD_Classification_Obj_41_IDT;
typedef uint8 ARS_OD_Classification_Obj_42_IDT;
typedef uint8 ARS_OD_Classification_Obj_43_IDT;
typedef uint8 ARS_OD_Classification_Obj_44_IDT;
typedef uint8 ARS_OD_Classification_Obj_45_IDT;
typedef uint8 ARS_OD_Classification_Obj_46_IDT;
typedef uint8 ARS_OD_Classification_Obj_47_IDT;
typedef uint8 ARS_OD_Classification_Obj_48_IDT;
typedef uint8 ARS_OD_Classification_Obj_49_IDT;
typedef uint8 ARS_OD_Classification_Obj_50_IDT;
typedef uint8 ARS_OD_Classification_Obj_51_IDT;
typedef uint8 ARS_OD_Classification_Obj_52_IDT;
typedef uint8 ARS_OD_Classification_Obj_53_IDT;
typedef uint8 ARS_OD_Classification_Obj_54_IDT;
typedef uint8 ARS_OD_Classification_Obj_55_IDT;
typedef uint8 ARS_OD_Classification_Obj_56_IDT;
typedef uint8 ARS_OD_Classification_Obj_57_IDT;
typedef uint8 ARS_OD_Classification_Obj_58_IDT;
typedef uint8 ARS_OD_Classification_Obj_59_IDT;
typedef uint16 ARS_OD_CycleCounter_IDT;
typedef uint8 ARS_OD_DistXStd_Obj_00_IDT;
typedef uint8 ARS_OD_DistXStd_Obj_01_IDT;
typedef uint8 ARS_OD_DistXStd_Obj_02_IDT;
typedef uint8 ARS_OD_DistXStd_Obj_03_IDT;
typedef uint8 ARS_OD_DistXStd_Obj_04_IDT;
typedef uint8 ARS_OD_DistXStd_Obj_05_IDT;
typedef uint8 ARS_OD_DistXStd_Obj_06_IDT;
typedef uint8 ARS_OD_DistXStd_Obj_07_IDT;
typedef uint8 ARS_OD_DistXStd_Obj_08_IDT;
typedef uint8 ARS_OD_DistXStd_Obj_09_IDT;
typedef uint8 ARS_OD_DistXStd_Obj_10_IDT;
typedef uint8 ARS_OD_DistXStd_Obj_11_IDT;
typedef uint8 ARS_OD_DistXStd_Obj_12_IDT;
typedef uint8 ARS_OD_DistXStd_Obj_13_IDT;
typedef uint8 ARS_OD_DistXStd_Obj_14_IDT;
typedef uint8 ARS_OD_DistXStd_Obj_15_IDT;
typedef uint8 ARS_OD_DistXStd_Obj_16_IDT;
typedef uint8 ARS_OD_DistXStd_Obj_17_IDT;
typedef uint8 ARS_OD_DistXStd_Obj_18_IDT;
typedef uint8 ARS_OD_DistXStd_Obj_19_IDT;
typedef uint8 ARS_OD_DistXStd_Obj_20_IDT;
typedef uint8 ARS_OD_DistXStd_Obj_21_IDT;
typedef uint8 ARS_OD_DistXStd_Obj_22_IDT;
typedef uint8 ARS_OD_DistXStd_Obj_23_IDT;
typedef uint8 ARS_OD_DistXStd_Obj_24_IDT;
typedef uint8 ARS_OD_DistXStd_Obj_25_IDT;
typedef uint8 ARS_OD_DistXStd_Obj_26_IDT;
typedef uint8 ARS_OD_DistXStd_Obj_27_IDT;
typedef uint8 ARS_OD_DistXStd_Obj_28_IDT;
typedef uint8 ARS_OD_DistXStd_Obj_29_IDT;
typedef uint8 ARS_OD_DistXStd_Obj_30_IDT;
typedef uint8 ARS_OD_DistXStd_Obj_31_IDT;
typedef uint8 ARS_OD_DistXStd_Obj_32_IDT;
typedef uint8 ARS_OD_DistXStd_Obj_33_IDT;
typedef uint8 ARS_OD_DistXStd_Obj_34_IDT;
typedef uint8 ARS_OD_DistXStd_Obj_35_IDT;
typedef uint8 ARS_OD_DistXStd_Obj_36_IDT;
typedef uint8 ARS_OD_DistXStd_Obj_37_IDT;
typedef uint8 ARS_OD_DistXStd_Obj_38_IDT;
typedef uint8 ARS_OD_DistXStd_Obj_39_IDT;
typedef uint8 ARS_OD_DistXStd_Obj_40_IDT;
typedef uint8 ARS_OD_DistXStd_Obj_41_IDT;
typedef uint8 ARS_OD_DistXStd_Obj_42_IDT;
typedef uint8 ARS_OD_DistXStd_Obj_43_IDT;
typedef uint8 ARS_OD_DistXStd_Obj_44_IDT;
typedef uint8 ARS_OD_DistXStd_Obj_45_IDT;
typedef uint8 ARS_OD_DistXStd_Obj_46_IDT;
typedef uint8 ARS_OD_DistXStd_Obj_47_IDT;
typedef uint8 ARS_OD_DistXStd_Obj_48_IDT;
typedef uint8 ARS_OD_DistXStd_Obj_49_IDT;
typedef uint8 ARS_OD_DistXStd_Obj_50_IDT;
typedef uint8 ARS_OD_DistXStd_Obj_51_IDT;
typedef uint8 ARS_OD_DistXStd_Obj_52_IDT;
typedef uint8 ARS_OD_DistXStd_Obj_53_IDT;
typedef uint8 ARS_OD_DistXStd_Obj_54_IDT;
typedef uint8 ARS_OD_DistXStd_Obj_55_IDT;
typedef uint8 ARS_OD_DistXStd_Obj_56_IDT;
typedef uint8 ARS_OD_DistXStd_Obj_57_IDT;
typedef uint8 ARS_OD_DistXStd_Obj_58_IDT;
typedef uint8 ARS_OD_DistXStd_Obj_59_IDT;
typedef uint16 ARS_OD_DistX_Obj_00_IDT;
typedef uint16 ARS_OD_DistX_Obj_01_IDT;
typedef uint16 ARS_OD_DistX_Obj_02_IDT;
typedef uint16 ARS_OD_DistX_Obj_03_IDT;
typedef uint16 ARS_OD_DistX_Obj_04_IDT;
typedef uint16 ARS_OD_DistX_Obj_05_IDT;
typedef uint16 ARS_OD_DistX_Obj_06_IDT;
typedef uint16 ARS_OD_DistX_Obj_07_IDT;
typedef uint16 ARS_OD_DistX_Obj_08_IDT;
typedef uint16 ARS_OD_DistX_Obj_09_IDT;
typedef uint16 ARS_OD_DistX_Obj_10_IDT;
typedef uint16 ARS_OD_DistX_Obj_11_IDT;
typedef uint16 ARS_OD_DistX_Obj_12_IDT;
typedef uint16 ARS_OD_DistX_Obj_13_IDT;
typedef uint16 ARS_OD_DistX_Obj_14_IDT;
typedef uint16 ARS_OD_DistX_Obj_15_IDT;
typedef uint16 ARS_OD_DistX_Obj_16_IDT;
typedef uint16 ARS_OD_DistX_Obj_17_IDT;
typedef uint16 ARS_OD_DistX_Obj_18_IDT;
typedef uint16 ARS_OD_DistX_Obj_19_IDT;
typedef uint16 ARS_OD_DistX_Obj_20_IDT;
typedef uint16 ARS_OD_DistX_Obj_21_IDT;
typedef uint16 ARS_OD_DistX_Obj_22_IDT;
typedef uint16 ARS_OD_DistX_Obj_23_IDT;
typedef uint16 ARS_OD_DistX_Obj_24_IDT;
typedef uint16 ARS_OD_DistX_Obj_25_IDT;
typedef uint16 ARS_OD_DistX_Obj_26_IDT;
typedef uint16 ARS_OD_DistX_Obj_27_IDT;
typedef uint16 ARS_OD_DistX_Obj_28_IDT;
typedef uint16 ARS_OD_DistX_Obj_29_IDT;
typedef uint16 ARS_OD_DistX_Obj_30_IDT;
typedef uint16 ARS_OD_DistX_Obj_31_IDT;
typedef uint16 ARS_OD_DistX_Obj_32_IDT;
typedef uint16 ARS_OD_DistX_Obj_33_IDT;
typedef uint16 ARS_OD_DistX_Obj_34_IDT;
typedef uint16 ARS_OD_DistX_Obj_35_IDT;
typedef uint16 ARS_OD_DistX_Obj_36_IDT;
typedef uint16 ARS_OD_DistX_Obj_37_IDT;
typedef uint16 ARS_OD_DistX_Obj_38_IDT;
typedef uint16 ARS_OD_DistX_Obj_39_IDT;
typedef uint16 ARS_OD_DistX_Obj_40_IDT;
typedef uint16 ARS_OD_DistX_Obj_41_IDT;
typedef uint16 ARS_OD_DistX_Obj_42_IDT;
typedef uint16 ARS_OD_DistX_Obj_43_IDT;
typedef uint16 ARS_OD_DistX_Obj_44_IDT;
typedef uint16 ARS_OD_DistX_Obj_45_IDT;
typedef uint16 ARS_OD_DistX_Obj_46_IDT;
typedef uint16 ARS_OD_DistX_Obj_47_IDT;
typedef uint16 ARS_OD_DistX_Obj_48_IDT;
typedef uint16 ARS_OD_DistX_Obj_49_IDT;
typedef uint16 ARS_OD_DistX_Obj_50_IDT;
typedef uint16 ARS_OD_DistX_Obj_51_IDT;
typedef uint16 ARS_OD_DistX_Obj_52_IDT;
typedef uint16 ARS_OD_DistX_Obj_53_IDT;
typedef uint16 ARS_OD_DistX_Obj_54_IDT;
typedef uint16 ARS_OD_DistX_Obj_55_IDT;
typedef uint16 ARS_OD_DistX_Obj_56_IDT;
typedef uint16 ARS_OD_DistX_Obj_57_IDT;
typedef uint16 ARS_OD_DistX_Obj_58_IDT;
typedef uint16 ARS_OD_DistX_Obj_59_IDT;
typedef uint8 ARS_OD_DistYStd_Obj_00_IDT;
typedef uint8 ARS_OD_DistYStd_Obj_01_IDT;
typedef uint8 ARS_OD_DistYStd_Obj_02_IDT;
typedef uint8 ARS_OD_DistYStd_Obj_03_IDT;
typedef uint8 ARS_OD_DistYStd_Obj_04_IDT;
typedef uint8 ARS_OD_DistYStd_Obj_05_IDT;
typedef uint8 ARS_OD_DistYStd_Obj_06_IDT;
typedef uint8 ARS_OD_DistYStd_Obj_07_IDT;
typedef uint8 ARS_OD_DistYStd_Obj_08_IDT;
typedef uint8 ARS_OD_DistYStd_Obj_09_IDT;
typedef uint8 ARS_OD_DistYStd_Obj_10_IDT;
typedef uint8 ARS_OD_DistYStd_Obj_11_IDT;
typedef uint8 ARS_OD_DistYStd_Obj_12_IDT;
typedef uint8 ARS_OD_DistYStd_Obj_13_IDT;
typedef uint8 ARS_OD_DistYStd_Obj_14_IDT;
typedef uint8 ARS_OD_DistYStd_Obj_15_IDT;
typedef uint8 ARS_OD_DistYStd_Obj_16_IDT;
typedef uint8 ARS_OD_DistYStd_Obj_17_IDT;
typedef uint8 ARS_OD_DistYStd_Obj_18_IDT;
typedef uint8 ARS_OD_DistYStd_Obj_19_IDT;
typedef uint8 ARS_OD_DistYStd_Obj_20_IDT;
typedef uint8 ARS_OD_DistYStd_Obj_21_IDT;
typedef uint8 ARS_OD_DistYStd_Obj_22_IDT;
typedef uint8 ARS_OD_DistYStd_Obj_23_IDT;
typedef uint8 ARS_OD_DistYStd_Obj_24_IDT;
typedef uint8 ARS_OD_DistYStd_Obj_25_IDT;
typedef uint8 ARS_OD_DistYStd_Obj_26_IDT;
typedef uint8 ARS_OD_DistYStd_Obj_27_IDT;
typedef uint8 ARS_OD_DistYStd_Obj_28_IDT;
typedef uint8 ARS_OD_DistYStd_Obj_29_IDT;
typedef uint8 ARS_OD_DistYStd_Obj_30_IDT;
typedef uint8 ARS_OD_DistYStd_Obj_31_IDT;
typedef uint8 ARS_OD_DistYStd_Obj_32_IDT;
typedef uint8 ARS_OD_DistYStd_Obj_33_IDT;
typedef uint8 ARS_OD_DistYStd_Obj_34_IDT;
typedef uint8 ARS_OD_DistYStd_Obj_35_IDT;
typedef uint8 ARS_OD_DistYStd_Obj_36_IDT;
typedef uint8 ARS_OD_DistYStd_Obj_37_IDT;
typedef uint8 ARS_OD_DistYStd_Obj_38_IDT;
typedef uint8 ARS_OD_DistYStd_Obj_39_IDT;
typedef uint8 ARS_OD_DistYStd_Obj_40_IDT;
typedef uint8 ARS_OD_DistYStd_Obj_41_IDT;
typedef uint8 ARS_OD_DistYStd_Obj_42_IDT;
typedef uint8 ARS_OD_DistYStd_Obj_43_IDT;
typedef uint8 ARS_OD_DistYStd_Obj_44_IDT;
typedef uint8 ARS_OD_DistYStd_Obj_45_IDT;
typedef uint8 ARS_OD_DistYStd_Obj_46_IDT;
typedef uint8 ARS_OD_DistYStd_Obj_47_IDT;
typedef uint8 ARS_OD_DistYStd_Obj_48_IDT;
typedef uint8 ARS_OD_DistYStd_Obj_49_IDT;
typedef uint8 ARS_OD_DistYStd_Obj_50_IDT;
typedef uint8 ARS_OD_DistYStd_Obj_51_IDT;
typedef uint8 ARS_OD_DistYStd_Obj_52_IDT;
typedef uint8 ARS_OD_DistYStd_Obj_53_IDT;
typedef uint8 ARS_OD_DistYStd_Obj_54_IDT;
typedef uint8 ARS_OD_DistYStd_Obj_55_IDT;
typedef uint8 ARS_OD_DistYStd_Obj_56_IDT;
typedef uint8 ARS_OD_DistYStd_Obj_57_IDT;
typedef uint8 ARS_OD_DistYStd_Obj_58_IDT;
typedef uint8 ARS_OD_DistYStd_Obj_59_IDT;
typedef uint16 ARS_OD_DistY_Obj_00_IDT;
typedef uint16 ARS_OD_DistY_Obj_01_IDT;
typedef uint16 ARS_OD_DistY_Obj_02_IDT;
typedef uint16 ARS_OD_DistY_Obj_03_IDT;
typedef uint16 ARS_OD_DistY_Obj_04_IDT;
typedef uint16 ARS_OD_DistY_Obj_05_IDT;
typedef uint16 ARS_OD_DistY_Obj_06_IDT;
typedef uint16 ARS_OD_DistY_Obj_07_IDT;
typedef uint16 ARS_OD_DistY_Obj_08_IDT;
typedef uint16 ARS_OD_DistY_Obj_09_IDT;
typedef uint16 ARS_OD_DistY_Obj_10_IDT;
typedef uint16 ARS_OD_DistY_Obj_11_IDT;
typedef uint16 ARS_OD_DistY_Obj_12_IDT;
typedef uint16 ARS_OD_DistY_Obj_13_IDT;
typedef uint16 ARS_OD_DistY_Obj_14_IDT;
typedef uint16 ARS_OD_DistY_Obj_15_IDT;
typedef uint16 ARS_OD_DistY_Obj_16_IDT;
typedef uint16 ARS_OD_DistY_Obj_17_IDT;
typedef uint16 ARS_OD_DistY_Obj_18_IDT;
typedef uint16 ARS_OD_DistY_Obj_19_IDT;
typedef uint16 ARS_OD_DistY_Obj_20_IDT;
typedef uint16 ARS_OD_DistY_Obj_21_IDT;
typedef uint16 ARS_OD_DistY_Obj_22_IDT;
typedef uint16 ARS_OD_DistY_Obj_23_IDT;
typedef uint16 ARS_OD_DistY_Obj_24_IDT;
typedef uint16 ARS_OD_DistY_Obj_25_IDT;
typedef uint16 ARS_OD_DistY_Obj_26_IDT;
typedef uint16 ARS_OD_DistY_Obj_27_IDT;
typedef uint16 ARS_OD_DistY_Obj_28_IDT;
typedef uint16 ARS_OD_DistY_Obj_29_IDT;
typedef uint16 ARS_OD_DistY_Obj_30_IDT;
typedef uint16 ARS_OD_DistY_Obj_31_IDT;
typedef uint16 ARS_OD_DistY_Obj_32_IDT;
typedef uint16 ARS_OD_DistY_Obj_33_IDT;
typedef uint16 ARS_OD_DistY_Obj_34_IDT;
typedef uint16 ARS_OD_DistY_Obj_35_IDT;
typedef uint16 ARS_OD_DistY_Obj_36_IDT;
typedef uint16 ARS_OD_DistY_Obj_37_IDT;
typedef uint16 ARS_OD_DistY_Obj_38_IDT;
typedef uint16 ARS_OD_DistY_Obj_39_IDT;
typedef uint16 ARS_OD_DistY_Obj_40_IDT;
typedef uint16 ARS_OD_DistY_Obj_41_IDT;
typedef uint16 ARS_OD_DistY_Obj_42_IDT;
typedef uint16 ARS_OD_DistY_Obj_43_IDT;
typedef uint16 ARS_OD_DistY_Obj_44_IDT;
typedef uint16 ARS_OD_DistY_Obj_45_IDT;
typedef uint16 ARS_OD_DistY_Obj_46_IDT;
typedef uint16 ARS_OD_DistY_Obj_47_IDT;
typedef uint16 ARS_OD_DistY_Obj_48_IDT;
typedef uint16 ARS_OD_DistY_Obj_49_IDT;
typedef uint16 ARS_OD_DistY_Obj_50_IDT;
typedef uint16 ARS_OD_DistY_Obj_51_IDT;
typedef uint16 ARS_OD_DistY_Obj_52_IDT;
typedef uint16 ARS_OD_DistY_Obj_53_IDT;
typedef uint16 ARS_OD_DistY_Obj_54_IDT;
typedef uint16 ARS_OD_DistY_Obj_55_IDT;
typedef uint16 ARS_OD_DistY_Obj_56_IDT;
typedef uint16 ARS_OD_DistY_Obj_57_IDT;
typedef uint16 ARS_OD_DistY_Obj_58_IDT;
typedef uint16 ARS_OD_DistY_Obj_59_IDT;
typedef uint8 ARS_OD_DynConf_Obj_00_IDT;
typedef uint8 ARS_OD_DynConf_Obj_01_IDT;
typedef uint8 ARS_OD_DynConf_Obj_02_IDT;
typedef uint8 ARS_OD_DynConf_Obj_03_IDT;
typedef uint8 ARS_OD_DynConf_Obj_04_IDT;
typedef uint8 ARS_OD_DynConf_Obj_05_IDT;
typedef uint8 ARS_OD_DynConf_Obj_06_IDT;
typedef uint8 ARS_OD_DynConf_Obj_07_IDT;
typedef uint8 ARS_OD_DynConf_Obj_08_IDT;
typedef uint8 ARS_OD_DynConf_Obj_09_IDT;
typedef uint8 ARS_OD_DynConf_Obj_10_IDT;
typedef uint8 ARS_OD_DynConf_Obj_11_IDT;
typedef uint8 ARS_OD_DynConf_Obj_12_IDT;
typedef uint8 ARS_OD_DynConf_Obj_13_IDT;
typedef uint8 ARS_OD_DynConf_Obj_14_IDT;
typedef uint8 ARS_OD_DynConf_Obj_15_IDT;
typedef uint8 ARS_OD_DynConf_Obj_16_IDT;
typedef uint8 ARS_OD_DynConf_Obj_17_IDT;
typedef uint8 ARS_OD_DynConf_Obj_18_IDT;
typedef uint8 ARS_OD_DynConf_Obj_19_IDT;
typedef uint8 ARS_OD_DynConf_Obj_20_IDT;
typedef uint8 ARS_OD_DynConf_Obj_21_IDT;
typedef uint8 ARS_OD_DynConf_Obj_22_IDT;
typedef uint8 ARS_OD_DynConf_Obj_23_IDT;
typedef uint8 ARS_OD_DynConf_Obj_24_IDT;
typedef uint8 ARS_OD_DynConf_Obj_25_IDT;
typedef uint8 ARS_OD_DynConf_Obj_26_IDT;
typedef uint8 ARS_OD_DynConf_Obj_27_IDT;
typedef uint8 ARS_OD_DynConf_Obj_28_IDT;
typedef uint8 ARS_OD_DynConf_Obj_29_IDT;
typedef uint8 ARS_OD_DynConf_Obj_30_IDT;
typedef uint8 ARS_OD_DynConf_Obj_31_IDT;
typedef uint8 ARS_OD_DynConf_Obj_32_IDT;
typedef uint8 ARS_OD_DynConf_Obj_33_IDT;
typedef uint8 ARS_OD_DynConf_Obj_34_IDT;
typedef uint8 ARS_OD_DynConf_Obj_35_IDT;
typedef uint8 ARS_OD_DynConf_Obj_36_IDT;
typedef uint8 ARS_OD_DynConf_Obj_37_IDT;
typedef uint8 ARS_OD_DynConf_Obj_38_IDT;
typedef uint8 ARS_OD_DynConf_Obj_39_IDT;
typedef uint8 ARS_OD_DynConf_Obj_40_IDT;
typedef uint8 ARS_OD_DynConf_Obj_41_IDT;
typedef uint8 ARS_OD_DynConf_Obj_42_IDT;
typedef uint8 ARS_OD_DynConf_Obj_43_IDT;
typedef uint8 ARS_OD_DynConf_Obj_44_IDT;
typedef uint8 ARS_OD_DynConf_Obj_45_IDT;
typedef uint8 ARS_OD_DynConf_Obj_46_IDT;
typedef uint8 ARS_OD_DynConf_Obj_47_IDT;
typedef uint8 ARS_OD_DynConf_Obj_48_IDT;
typedef uint8 ARS_OD_DynConf_Obj_49_IDT;
typedef uint8 ARS_OD_DynConf_Obj_50_IDT;
typedef uint8 ARS_OD_DynConf_Obj_51_IDT;
typedef uint8 ARS_OD_DynConf_Obj_52_IDT;
typedef uint8 ARS_OD_DynConf_Obj_53_IDT;
typedef uint8 ARS_OD_DynConf_Obj_54_IDT;
typedef uint8 ARS_OD_DynConf_Obj_55_IDT;
typedef uint8 ARS_OD_DynConf_Obj_56_IDT;
typedef uint8 ARS_OD_DynConf_Obj_57_IDT;
typedef uint8 ARS_OD_DynConf_Obj_58_IDT;
typedef uint8 ARS_OD_DynConf_Obj_59_IDT;
typedef uint8 ARS_OD_DynProp_Obj_00_IDT;
typedef uint8 ARS_OD_DynProp_Obj_01_IDT;
typedef uint8 ARS_OD_DynProp_Obj_02_IDT;
typedef uint8 ARS_OD_DynProp_Obj_03_IDT;
typedef uint8 ARS_OD_DynProp_Obj_04_IDT;
typedef uint8 ARS_OD_DynProp_Obj_05_IDT;
typedef uint8 ARS_OD_DynProp_Obj_06_IDT;
typedef uint8 ARS_OD_DynProp_Obj_07_IDT;
typedef uint8 ARS_OD_DynProp_Obj_08_IDT;
typedef uint8 ARS_OD_DynProp_Obj_09_IDT;
typedef uint8 ARS_OD_DynProp_Obj_10_IDT;
typedef uint8 ARS_OD_DynProp_Obj_11_IDT;
typedef uint8 ARS_OD_DynProp_Obj_12_IDT;
typedef uint8 ARS_OD_DynProp_Obj_13_IDT;
typedef uint8 ARS_OD_DynProp_Obj_14_IDT;
typedef uint8 ARS_OD_DynProp_Obj_15_IDT;
typedef uint8 ARS_OD_DynProp_Obj_16_IDT;
typedef uint8 ARS_OD_DynProp_Obj_17_IDT;
typedef uint8 ARS_OD_DynProp_Obj_18_IDT;
typedef uint8 ARS_OD_DynProp_Obj_19_IDT;
typedef uint8 ARS_OD_DynProp_Obj_20_IDT;
typedef uint8 ARS_OD_DynProp_Obj_21_IDT;
typedef uint8 ARS_OD_DynProp_Obj_22_IDT;
typedef uint8 ARS_OD_DynProp_Obj_23_IDT;
typedef uint8 ARS_OD_DynProp_Obj_24_IDT;
typedef uint8 ARS_OD_DynProp_Obj_25_IDT;
typedef uint8 ARS_OD_DynProp_Obj_26_IDT;
typedef uint8 ARS_OD_DynProp_Obj_27_IDT;
typedef uint8 ARS_OD_DynProp_Obj_28_IDT;
typedef uint8 ARS_OD_DynProp_Obj_29_IDT;
typedef uint8 ARS_OD_DynProp_Obj_30_IDT;
typedef uint8 ARS_OD_DynProp_Obj_31_IDT;
typedef uint8 ARS_OD_DynProp_Obj_32_IDT;
typedef uint8 ARS_OD_DynProp_Obj_33_IDT;
typedef uint8 ARS_OD_DynProp_Obj_34_IDT;
typedef uint8 ARS_OD_DynProp_Obj_35_IDT;
typedef uint8 ARS_OD_DynProp_Obj_36_IDT;
typedef uint8 ARS_OD_DynProp_Obj_37_IDT;
typedef uint8 ARS_OD_DynProp_Obj_38_IDT;
typedef uint8 ARS_OD_DynProp_Obj_39_IDT;
typedef uint8 ARS_OD_DynProp_Obj_40_IDT;
typedef uint8 ARS_OD_DynProp_Obj_41_IDT;
typedef uint8 ARS_OD_DynProp_Obj_42_IDT;
typedef uint8 ARS_OD_DynProp_Obj_43_IDT;
typedef uint8 ARS_OD_DynProp_Obj_44_IDT;
typedef uint8 ARS_OD_DynProp_Obj_45_IDT;
typedef uint8 ARS_OD_DynProp_Obj_46_IDT;
typedef uint8 ARS_OD_DynProp_Obj_47_IDT;
typedef uint8 ARS_OD_DynProp_Obj_48_IDT;
typedef uint8 ARS_OD_DynProp_Obj_49_IDT;
typedef uint8 ARS_OD_DynProp_Obj_50_IDT;
typedef uint8 ARS_OD_DynProp_Obj_51_IDT;
typedef uint8 ARS_OD_DynProp_Obj_52_IDT;
typedef uint8 ARS_OD_DynProp_Obj_53_IDT;
typedef uint8 ARS_OD_DynProp_Obj_54_IDT;
typedef uint8 ARS_OD_DynProp_Obj_55_IDT;
typedef uint8 ARS_OD_DynProp_Obj_56_IDT;
typedef uint8 ARS_OD_DynProp_Obj_57_IDT;
typedef uint8 ARS_OD_DynProp_Obj_58_IDT;
typedef uint8 ARS_OD_DynProp_Obj_59_IDT;
typedef uint16 ARS_OD_EgoAcceleration_IDT;
typedef uint8 ARS_OD_EgoCurvature_IDT;
typedef uint8 ARS_OD_EgoVelocityStd_IDT;
typedef uint16 ARS_OD_EgoVelocity_IDT;
typedef uint16 ARS_OD_EgoYawRate_IDT;
typedef uint8 ARS_OD_ExtendedCycleFlag_IDT;
typedef uint8 ARS_OD_ID_00_IDT;
typedef uint8 ARS_OD_ID_01_IDT;
typedef uint8 ARS_OD_ID_02_IDT;
typedef uint8 ARS_OD_ID_03_IDT;
typedef uint8 ARS_OD_ID_04_IDT;
typedef uint8 ARS_OD_ID_05_IDT;
typedef uint8 ARS_OD_ID_06_IDT;
typedef uint8 ARS_OD_ID_07_IDT;
typedef uint8 ARS_OD_ID_08_IDT;
typedef uint8 ARS_OD_ID_09_IDT;
typedef uint8 ARS_OD_ID_10_IDT;
typedef uint8 ARS_OD_ID_11_IDT;
typedef uint8 ARS_OD_ID_12_IDT;
typedef uint8 ARS_OD_ID_13_IDT;
typedef uint8 ARS_OD_ID_14_IDT;
typedef uint8 ARS_OD_ID_15_IDT;
typedef uint8 ARS_OD_ID_16_IDT;
typedef uint8 ARS_OD_ID_17_IDT;
typedef uint8 ARS_OD_ID_18_IDT;
typedef uint8 ARS_OD_ID_19_IDT;
typedef uint8 ARS_OD_ID_20_IDT;
typedef uint8 ARS_OD_ID_21_IDT;
typedef uint8 ARS_OD_ID_22_IDT;
typedef uint8 ARS_OD_ID_23_IDT;
typedef uint8 ARS_OD_ID_24_IDT;
typedef uint8 ARS_OD_ID_25_IDT;
typedef uint8 ARS_OD_ID_26_IDT;
typedef uint8 ARS_OD_ID_27_IDT;
typedef uint8 ARS_OD_ID_28_IDT;
typedef uint8 ARS_OD_ID_29_IDT;
typedef uint8 ARS_OD_ID_30_IDT;
typedef uint8 ARS_OD_ID_31_IDT;
typedef uint8 ARS_OD_ID_32_IDT;
typedef uint8 ARS_OD_ID_33_IDT;
typedef uint8 ARS_OD_ID_34_IDT;
typedef uint8 ARS_OD_ID_35_IDT;
typedef uint8 ARS_OD_ID_36_IDT;
typedef uint8 ARS_OD_ID_37_IDT;
typedef uint8 ARS_OD_ID_38_IDT;
typedef uint8 ARS_OD_ID_39_IDT;
typedef uint8 ARS_OD_ID_40_IDT;
typedef uint8 ARS_OD_ID_41_IDT;
typedef uint8 ARS_OD_ID_42_IDT;
typedef uint8 ARS_OD_ID_43_IDT;
typedef uint8 ARS_OD_ID_44_IDT;
typedef uint8 ARS_OD_ID_45_IDT;
typedef uint8 ARS_OD_ID_46_IDT;
typedef uint8 ARS_OD_ID_47_IDT;
typedef uint8 ARS_OD_ID_48_IDT;
typedef uint8 ARS_OD_ID_49_IDT;
typedef uint8 ARS_OD_ID_50_IDT;
typedef uint8 ARS_OD_ID_51_IDT;
typedef uint8 ARS_OD_ID_52_IDT;
typedef uint8 ARS_OD_ID_53_IDT;
typedef uint8 ARS_OD_ID_54_IDT;
typedef uint8 ARS_OD_ID_55_IDT;
typedef uint8 ARS_OD_ID_56_IDT;
typedef uint8 ARS_OD_ID_57_IDT;
typedef uint8 ARS_OD_ID_58_IDT;
typedef uint8 ARS_OD_ID_59_IDT;
typedef uint16 ARS_OD_Latency_IDT;
typedef uint8 ARS_OD_Length_Obj_00_IDT;
typedef uint8 ARS_OD_Length_Obj_01_IDT;
typedef uint8 ARS_OD_Length_Obj_02_IDT;
typedef uint8 ARS_OD_Length_Obj_03_IDT;
typedef uint8 ARS_OD_Length_Obj_04_IDT;
typedef uint8 ARS_OD_Length_Obj_05_IDT;
typedef uint8 ARS_OD_Length_Obj_06_IDT;
typedef uint8 ARS_OD_Length_Obj_07_IDT;
typedef uint8 ARS_OD_Length_Obj_08_IDT;
typedef uint8 ARS_OD_Length_Obj_09_IDT;
typedef uint8 ARS_OD_Length_Obj_10_IDT;
typedef uint8 ARS_OD_Length_Obj_11_IDT;
typedef uint8 ARS_OD_Length_Obj_12_IDT;
typedef uint8 ARS_OD_Length_Obj_13_IDT;
typedef uint8 ARS_OD_Length_Obj_14_IDT;
typedef uint8 ARS_OD_Length_Obj_15_IDT;
typedef uint8 ARS_OD_Length_Obj_16_IDT;
typedef uint8 ARS_OD_Length_Obj_17_IDT;
typedef uint8 ARS_OD_Length_Obj_18_IDT;
typedef uint8 ARS_OD_Length_Obj_19_IDT;
typedef uint8 ARS_OD_Length_Obj_20_IDT;
typedef uint8 ARS_OD_Length_Obj_21_IDT;
typedef uint8 ARS_OD_Length_Obj_22_IDT;
typedef uint8 ARS_OD_Length_Obj_23_IDT;
typedef uint8 ARS_OD_Length_Obj_24_IDT;
typedef uint8 ARS_OD_Length_Obj_25_IDT;
typedef uint8 ARS_OD_Length_Obj_26_IDT;
typedef uint8 ARS_OD_Length_Obj_27_IDT;
typedef uint8 ARS_OD_Length_Obj_28_IDT;
typedef uint8 ARS_OD_Length_Obj_29_IDT;
typedef uint8 ARS_OD_Length_Obj_30_IDT;
typedef uint8 ARS_OD_Length_Obj_31_IDT;
typedef uint8 ARS_OD_Length_Obj_32_IDT;
typedef uint8 ARS_OD_Length_Obj_33_IDT;
typedef uint8 ARS_OD_Length_Obj_34_IDT;
typedef uint8 ARS_OD_Length_Obj_35_IDT;
typedef uint8 ARS_OD_Length_Obj_36_IDT;
typedef uint8 ARS_OD_Length_Obj_37_IDT;
typedef uint8 ARS_OD_Length_Obj_38_IDT;
typedef uint8 ARS_OD_Length_Obj_39_IDT;
typedef uint8 ARS_OD_Length_Obj_40_IDT;
typedef uint8 ARS_OD_Length_Obj_41_IDT;
typedef uint8 ARS_OD_Length_Obj_42_IDT;
typedef uint8 ARS_OD_Length_Obj_43_IDT;
typedef uint8 ARS_OD_Length_Obj_44_IDT;
typedef uint8 ARS_OD_Length_Obj_45_IDT;
typedef uint8 ARS_OD_Length_Obj_46_IDT;
typedef uint8 ARS_OD_Length_Obj_47_IDT;
typedef uint8 ARS_OD_Length_Obj_48_IDT;
typedef uint8 ARS_OD_Length_Obj_49_IDT;
typedef uint8 ARS_OD_Length_Obj_50_IDT;
typedef uint8 ARS_OD_Length_Obj_51_IDT;
typedef uint8 ARS_OD_Length_Obj_52_IDT;
typedef uint8 ARS_OD_Length_Obj_53_IDT;
typedef uint8 ARS_OD_Length_Obj_54_IDT;
typedef uint8 ARS_OD_Length_Obj_55_IDT;
typedef uint8 ARS_OD_Length_Obj_56_IDT;
typedef uint8 ARS_OD_Length_Obj_57_IDT;
typedef uint8 ARS_OD_Length_Obj_58_IDT;
typedef uint8 ARS_OD_Length_Obj_59_IDT;
typedef uint16 ARS_OD_LifeCycle_Obj_00_IDT;
typedef uint16 ARS_OD_LifeCycle_Obj_01_IDT;
typedef uint16 ARS_OD_LifeCycle_Obj_02_IDT;
typedef uint16 ARS_OD_LifeCycle_Obj_03_IDT;
typedef uint16 ARS_OD_LifeCycle_Obj_04_IDT;
typedef uint16 ARS_OD_LifeCycle_Obj_05_IDT;
typedef uint16 ARS_OD_LifeCycle_Obj_06_IDT;
typedef uint16 ARS_OD_LifeCycle_Obj_07_IDT;
typedef uint16 ARS_OD_LifeCycle_Obj_08_IDT;
typedef uint16 ARS_OD_LifeCycle_Obj_09_IDT;
typedef uint16 ARS_OD_LifeCycle_Obj_10_IDT;
typedef uint16 ARS_OD_LifeCycle_Obj_11_IDT;
typedef uint16 ARS_OD_LifeCycle_Obj_12_IDT;
typedef uint16 ARS_OD_LifeCycle_Obj_13_IDT;
typedef uint16 ARS_OD_LifeCycle_Obj_14_IDT;
typedef uint16 ARS_OD_LifeCycle_Obj_15_IDT;
typedef uint16 ARS_OD_LifeCycle_Obj_16_IDT;
typedef uint16 ARS_OD_LifeCycle_Obj_17_IDT;
typedef uint16 ARS_OD_LifeCycle_Obj_18_IDT;
typedef uint16 ARS_OD_LifeCycle_Obj_19_IDT;
typedef uint16 ARS_OD_LifeCycle_Obj_20_IDT;
typedef uint16 ARS_OD_LifeCycle_Obj_21_IDT;
typedef uint16 ARS_OD_LifeCycle_Obj_22_IDT;
typedef uint16 ARS_OD_LifeCycle_Obj_23_IDT;
typedef uint16 ARS_OD_LifeCycle_Obj_24_IDT;
typedef uint16 ARS_OD_LifeCycle_Obj_25_IDT;
typedef uint16 ARS_OD_LifeCycle_Obj_26_IDT;
typedef uint16 ARS_OD_LifeCycle_Obj_27_IDT;
typedef uint16 ARS_OD_LifeCycle_Obj_28_IDT;
typedef uint16 ARS_OD_LifeCycle_Obj_29_IDT;
typedef uint16 ARS_OD_LifeCycle_Obj_30_IDT;
typedef uint16 ARS_OD_LifeCycle_Obj_31_IDT;
typedef uint16 ARS_OD_LifeCycle_Obj_32_IDT;
typedef uint16 ARS_OD_LifeCycle_Obj_33_IDT;
typedef uint16 ARS_OD_LifeCycle_Obj_34_IDT;
typedef uint16 ARS_OD_LifeCycle_Obj_35_IDT;
typedef uint16 ARS_OD_LifeCycle_Obj_36_IDT;
typedef uint16 ARS_OD_LifeCycle_Obj_37_IDT;
typedef uint16 ARS_OD_LifeCycle_Obj_38_IDT;
typedef uint16 ARS_OD_LifeCycle_Obj_39_IDT;
typedef uint16 ARS_OD_LifeCycle_Obj_40_IDT;
typedef uint16 ARS_OD_LifeCycle_Obj_41_IDT;
typedef uint16 ARS_OD_LifeCycle_Obj_42_IDT;
typedef uint16 ARS_OD_LifeCycle_Obj_43_IDT;
typedef uint16 ARS_OD_LifeCycle_Obj_44_IDT;
typedef uint16 ARS_OD_LifeCycle_Obj_45_IDT;
typedef uint16 ARS_OD_LifeCycle_Obj_46_IDT;
typedef uint16 ARS_OD_LifeCycle_Obj_47_IDT;
typedef uint16 ARS_OD_LifeCycle_Obj_48_IDT;
typedef uint16 ARS_OD_LifeCycle_Obj_49_IDT;
typedef uint16 ARS_OD_LifeCycle_Obj_50_IDT;
typedef uint16 ARS_OD_LifeCycle_Obj_51_IDT;
typedef uint16 ARS_OD_LifeCycle_Obj_52_IDT;
typedef uint16 ARS_OD_LifeCycle_Obj_53_IDT;
typedef uint16 ARS_OD_LifeCycle_Obj_54_IDT;
typedef uint16 ARS_OD_LifeCycle_Obj_55_IDT;
typedef uint16 ARS_OD_LifeCycle_Obj_56_IDT;
typedef uint16 ARS_OD_LifeCycle_Obj_57_IDT;
typedef uint16 ARS_OD_LifeCycle_Obj_58_IDT;
typedef uint16 ARS_OD_LifeCycle_Obj_59_IDT;
typedef uint8 ARS_OD_MaintenanceState_Obj_00_IDT;
typedef uint8 ARS_OD_MaintenanceState_Obj_01_IDT;
typedef uint8 ARS_OD_MaintenanceState_Obj_02_IDT;
typedef uint8 ARS_OD_MaintenanceState_Obj_03_IDT;
typedef uint8 ARS_OD_MaintenanceState_Obj_04_IDT;
typedef uint8 ARS_OD_MaintenanceState_Obj_05_IDT;
typedef uint8 ARS_OD_MaintenanceState_Obj_06_IDT;
typedef uint8 ARS_OD_MaintenanceState_Obj_07_IDT;
typedef uint8 ARS_OD_MaintenanceState_Obj_08_IDT;
typedef uint8 ARS_OD_MaintenanceState_Obj_09_IDT;
typedef uint8 ARS_OD_MaintenanceState_Obj_10_IDT;
typedef uint8 ARS_OD_MaintenanceState_Obj_11_IDT;
typedef uint8 ARS_OD_MaintenanceState_Obj_12_IDT;
typedef uint8 ARS_OD_MaintenanceState_Obj_13_IDT;
typedef uint8 ARS_OD_MaintenanceState_Obj_14_IDT;
typedef uint8 ARS_OD_MaintenanceState_Obj_15_IDT;
typedef uint8 ARS_OD_MaintenanceState_Obj_16_IDT;
typedef uint8 ARS_OD_MaintenanceState_Obj_17_IDT;
typedef uint8 ARS_OD_MaintenanceState_Obj_18_IDT;
typedef uint8 ARS_OD_MaintenanceState_Obj_19_IDT;
typedef uint8 ARS_OD_MaintenanceState_Obj_20_IDT;
typedef uint8 ARS_OD_MaintenanceState_Obj_21_IDT;
typedef uint8 ARS_OD_MaintenanceState_Obj_22_IDT;
typedef uint8 ARS_OD_MaintenanceState_Obj_23_IDT;
typedef uint8 ARS_OD_MaintenanceState_Obj_24_IDT;
typedef uint8 ARS_OD_MaintenanceState_Obj_25_IDT;
typedef uint8 ARS_OD_MaintenanceState_Obj_26_IDT;
typedef uint8 ARS_OD_MaintenanceState_Obj_27_IDT;
typedef uint8 ARS_OD_MaintenanceState_Obj_28_IDT;
typedef uint8 ARS_OD_MaintenanceState_Obj_29_IDT;
typedef uint8 ARS_OD_MaintenanceState_Obj_30_IDT;
typedef uint8 ARS_OD_MaintenanceState_Obj_31_IDT;
typedef uint8 ARS_OD_MaintenanceState_Obj_32_IDT;
typedef uint8 ARS_OD_MaintenanceState_Obj_33_IDT;
typedef uint8 ARS_OD_MaintenanceState_Obj_34_IDT;
typedef uint8 ARS_OD_MaintenanceState_Obj_35_IDT;
typedef uint8 ARS_OD_MaintenanceState_Obj_36_IDT;
typedef uint8 ARS_OD_MaintenanceState_Obj_37_IDT;
typedef uint8 ARS_OD_MaintenanceState_Obj_38_IDT;
typedef uint8 ARS_OD_MaintenanceState_Obj_39_IDT;
typedef uint8 ARS_OD_MaintenanceState_Obj_40_IDT;
typedef uint8 ARS_OD_MaintenanceState_Obj_41_IDT;
typedef uint8 ARS_OD_MaintenanceState_Obj_42_IDT;
typedef uint8 ARS_OD_MaintenanceState_Obj_43_IDT;
typedef uint8 ARS_OD_MaintenanceState_Obj_44_IDT;
typedef uint8 ARS_OD_MaintenanceState_Obj_45_IDT;
typedef uint8 ARS_OD_MaintenanceState_Obj_46_IDT;
typedef uint8 ARS_OD_MaintenanceState_Obj_47_IDT;
typedef uint8 ARS_OD_MaintenanceState_Obj_48_IDT;
typedef uint8 ARS_OD_MaintenanceState_Obj_49_IDT;
typedef uint8 ARS_OD_MaintenanceState_Obj_50_IDT;
typedef uint8 ARS_OD_MaintenanceState_Obj_51_IDT;
typedef uint8 ARS_OD_MaintenanceState_Obj_52_IDT;
typedef uint8 ARS_OD_MaintenanceState_Obj_53_IDT;
typedef uint8 ARS_OD_MaintenanceState_Obj_54_IDT;
typedef uint8 ARS_OD_MaintenanceState_Obj_55_IDT;
typedef uint8 ARS_OD_MaintenanceState_Obj_56_IDT;
typedef uint8 ARS_OD_MaintenanceState_Obj_57_IDT;
typedef uint8 ARS_OD_MaintenanceState_Obj_58_IDT;
typedef uint8 ARS_OD_MaintenanceState_Obj_59_IDT;
typedef uint16 ARS_OD_MeasCounter_IDT;
typedef uint8 ARS_OD_MicroDopplerFlag_00_IDT;
typedef uint8 ARS_OD_MicroDopplerFlag_01_IDT;
typedef uint8 ARS_OD_MicroDopplerFlag_02_IDT;
typedef uint8 ARS_OD_MicroDopplerFlag_03_IDT;
typedef uint8 ARS_OD_MicroDopplerFlag_04_IDT;
typedef uint8 ARS_OD_MicroDopplerFlag_05_IDT;
typedef uint8 ARS_OD_MicroDopplerFlag_06_IDT;
typedef uint8 ARS_OD_MicroDopplerFlag_07_IDT;
typedef uint8 ARS_OD_MicroDopplerFlag_08_IDT;
typedef uint8 ARS_OD_MicroDopplerFlag_09_IDT;
typedef uint8 ARS_OD_MicroDopplerFlag_10_IDT;
typedef uint8 ARS_OD_MicroDopplerFlag_11_IDT;
typedef uint8 ARS_OD_MicroDopplerFlag_12_IDT;
typedef uint8 ARS_OD_MicroDopplerFlag_13_IDT;
typedef uint8 ARS_OD_MicroDopplerFlag_14_IDT;
typedef uint8 ARS_OD_MicroDopplerFlag_15_IDT;
typedef uint8 ARS_OD_MicroDopplerFlag_16_IDT;
typedef uint8 ARS_OD_MicroDopplerFlag_17_IDT;
typedef uint8 ARS_OD_MicroDopplerFlag_18_IDT;
typedef uint8 ARS_OD_MicroDopplerFlag_19_IDT;
typedef uint8 ARS_OD_MicroDopplerFlag_20_IDT;
typedef uint8 ARS_OD_MicroDopplerFlag_21_IDT;
typedef uint8 ARS_OD_MicroDopplerFlag_22_IDT;
typedef uint8 ARS_OD_MicroDopplerFlag_23_IDT;
typedef uint8 ARS_OD_MicroDopplerFlag_24_IDT;
typedef uint8 ARS_OD_MicroDopplerFlag_25_IDT;
typedef uint8 ARS_OD_MicroDopplerFlag_26_IDT;
typedef uint8 ARS_OD_MicroDopplerFlag_27_IDT;
typedef uint8 ARS_OD_MicroDopplerFlag_28_IDT;
typedef uint8 ARS_OD_MicroDopplerFlag_29_IDT;
typedef uint8 ARS_OD_MicroDopplerFlag_30_IDT;
typedef uint8 ARS_OD_MicroDopplerFlag_31_IDT;
typedef uint8 ARS_OD_MicroDopplerFlag_32_IDT;
typedef uint8 ARS_OD_MicroDopplerFlag_33_IDT;
typedef uint8 ARS_OD_MicroDopplerFlag_34_IDT;
typedef uint8 ARS_OD_MicroDopplerFlag_35_IDT;
typedef uint8 ARS_OD_MicroDopplerFlag_36_IDT;
typedef uint8 ARS_OD_MicroDopplerFlag_37_IDT;
typedef uint8 ARS_OD_MicroDopplerFlag_38_IDT;
typedef uint8 ARS_OD_MicroDopplerFlag_39_IDT;
typedef uint8 ARS_OD_MicroDopplerFlag_40_IDT;
typedef uint8 ARS_OD_MicroDopplerFlag_41_IDT;
typedef uint8 ARS_OD_MicroDopplerFlag_42_IDT;
typedef uint8 ARS_OD_MicroDopplerFlag_43_IDT;
typedef uint8 ARS_OD_MicroDopplerFlag_44_IDT;
typedef uint8 ARS_OD_MicroDopplerFlag_45_IDT;
typedef uint8 ARS_OD_MicroDopplerFlag_46_IDT;
typedef uint8 ARS_OD_MicroDopplerFlag_47_IDT;
typedef uint8 ARS_OD_MicroDopplerFlag_48_IDT;
typedef uint8 ARS_OD_MicroDopplerFlag_49_IDT;
typedef uint8 ARS_OD_MicroDopplerFlag_50_IDT;
typedef uint8 ARS_OD_MicroDopplerFlag_51_IDT;
typedef uint8 ARS_OD_MicroDopplerFlag_52_IDT;
typedef uint8 ARS_OD_MicroDopplerFlag_53_IDT;
typedef uint8 ARS_OD_MicroDopplerFlag_54_IDT;
typedef uint8 ARS_OD_MicroDopplerFlag_55_IDT;
typedef uint8 ARS_OD_MicroDopplerFlag_56_IDT;
typedef uint8 ARS_OD_MicroDopplerFlag_57_IDT;
typedef uint8 ARS_OD_MicroDopplerFlag_58_IDT;
typedef uint8 ARS_OD_MicroDopplerFlag_59_IDT;
typedef uint8 ARS_OD_MirrorProb_Obj_00_IDT;
typedef uint8 ARS_OD_MirrorProb_Obj_01_IDT;
typedef uint8 ARS_OD_MirrorProb_Obj_02_IDT;
typedef uint8 ARS_OD_MirrorProb_Obj_03_IDT;
typedef uint8 ARS_OD_MirrorProb_Obj_04_IDT;
typedef uint8 ARS_OD_MirrorProb_Obj_05_IDT;
typedef uint8 ARS_OD_MirrorProb_Obj_06_IDT;
typedef uint8 ARS_OD_MirrorProb_Obj_07_IDT;
typedef uint8 ARS_OD_MirrorProb_Obj_08_IDT;
typedef uint8 ARS_OD_MirrorProb_Obj_09_IDT;
typedef uint8 ARS_OD_MirrorProb_Obj_10_IDT;
typedef uint8 ARS_OD_MirrorProb_Obj_11_IDT;
typedef uint8 ARS_OD_MirrorProb_Obj_12_IDT;
typedef uint8 ARS_OD_MirrorProb_Obj_13_IDT;
typedef uint8 ARS_OD_MirrorProb_Obj_14_IDT;
typedef uint8 ARS_OD_MirrorProb_Obj_15_IDT;
typedef uint8 ARS_OD_MirrorProb_Obj_16_IDT;
typedef uint8 ARS_OD_MirrorProb_Obj_17_IDT;
typedef uint8 ARS_OD_MirrorProb_Obj_18_IDT;
typedef uint8 ARS_OD_MirrorProb_Obj_19_IDT;
typedef uint8 ARS_OD_MirrorProb_Obj_20_IDT;
typedef uint8 ARS_OD_MirrorProb_Obj_21_IDT;
typedef uint8 ARS_OD_MirrorProb_Obj_22_IDT;
typedef uint8 ARS_OD_MirrorProb_Obj_23_IDT;
typedef uint8 ARS_OD_MirrorProb_Obj_24_IDT;
typedef uint8 ARS_OD_MirrorProb_Obj_25_IDT;
typedef uint8 ARS_OD_MirrorProb_Obj_26_IDT;
typedef uint8 ARS_OD_MirrorProb_Obj_27_IDT;
typedef uint8 ARS_OD_MirrorProb_Obj_28_IDT;
typedef uint8 ARS_OD_MirrorProb_Obj_29_IDT;
typedef uint8 ARS_OD_MirrorProb_Obj_30_IDT;
typedef uint8 ARS_OD_MirrorProb_Obj_31_IDT;
typedef uint8 ARS_OD_MirrorProb_Obj_32_IDT;
typedef uint8 ARS_OD_MirrorProb_Obj_33_IDT;
typedef uint8 ARS_OD_MirrorProb_Obj_34_IDT;
typedef uint8 ARS_OD_MirrorProb_Obj_35_IDT;
typedef uint8 ARS_OD_MirrorProb_Obj_36_IDT;
typedef uint8 ARS_OD_MirrorProb_Obj_37_IDT;
typedef uint8 ARS_OD_MirrorProb_Obj_38_IDT;
typedef uint8 ARS_OD_MirrorProb_Obj_39_IDT;
typedef uint8 ARS_OD_MirrorProb_Obj_40_IDT;
typedef uint8 ARS_OD_MirrorProb_Obj_41_IDT;
typedef uint8 ARS_OD_MirrorProb_Obj_42_IDT;
typedef uint8 ARS_OD_MirrorProb_Obj_43_IDT;
typedef uint8 ARS_OD_MirrorProb_Obj_44_IDT;
typedef uint8 ARS_OD_MirrorProb_Obj_45_IDT;
typedef uint8 ARS_OD_MirrorProb_Obj_46_IDT;
typedef uint8 ARS_OD_MirrorProb_Obj_47_IDT;
typedef uint8 ARS_OD_MirrorProb_Obj_48_IDT;
typedef uint8 ARS_OD_MirrorProb_Obj_49_IDT;
typedef uint8 ARS_OD_MirrorProb_Obj_50_IDT;
typedef uint8 ARS_OD_MirrorProb_Obj_51_IDT;
typedef uint8 ARS_OD_MirrorProb_Obj_52_IDT;
typedef uint8 ARS_OD_MirrorProb_Obj_53_IDT;
typedef uint8 ARS_OD_MirrorProb_Obj_54_IDT;
typedef uint8 ARS_OD_MirrorProb_Obj_55_IDT;
typedef uint8 ARS_OD_MirrorProb_Obj_56_IDT;
typedef uint8 ARS_OD_MirrorProb_Obj_57_IDT;
typedef uint8 ARS_OD_MirrorProb_Obj_58_IDT;
typedef uint8 ARS_OD_MirrorProb_Obj_59_IDT;
typedef uint8 ARS_OD_MsgCounter_Header_IDT;
typedef uint8 ARS_OD_MsgCounter_Obj_00_01_IDT;
typedef uint8 ARS_OD_MsgCounter_Obj_02_03_IDT;
typedef uint8 ARS_OD_MsgCounter_Obj_04_05_IDT;
typedef uint8 ARS_OD_MsgCounter_Obj_06_07_IDT;
typedef uint8 ARS_OD_MsgCounter_Obj_08_09_IDT;
typedef uint8 ARS_OD_MsgCounter_Obj_10_11_IDT;
typedef uint8 ARS_OD_MsgCounter_Obj_12_13_IDT;
typedef uint8 ARS_OD_MsgCounter_Obj_14_15_IDT;
typedef uint8 ARS_OD_MsgCounter_Obj_16_17_IDT;
typedef uint8 ARS_OD_MsgCounter_Obj_18_19_IDT;
typedef uint8 ARS_OD_MsgCounter_Obj_20_21_IDT;
typedef uint8 ARS_OD_MsgCounter_Obj_22_23_IDT;
typedef uint8 ARS_OD_MsgCounter_Obj_24_25_IDT;
typedef uint8 ARS_OD_MsgCounter_Obj_26_27_IDT;
typedef uint8 ARS_OD_MsgCounter_Obj_28_29_IDT;
typedef uint8 ARS_OD_MsgCounter_Obj_30_31_IDT;
typedef uint8 ARS_OD_MsgCounter_Obj_32_33_IDT;
typedef uint8 ARS_OD_MsgCounter_Obj_34_35_IDT;
typedef uint8 ARS_OD_MsgCounter_Obj_36_37_IDT;
typedef uint8 ARS_OD_MsgCounter_Obj_38_39_IDT;
typedef uint8 ARS_OD_MsgCounter_Obj_40_41_IDT;
typedef uint8 ARS_OD_MsgCounter_Obj_42_43_IDT;
typedef uint8 ARS_OD_MsgCounter_Obj_44_45_IDT;
typedef uint8 ARS_OD_MsgCounter_Obj_46_47_IDT;
typedef uint8 ARS_OD_MsgCounter_Obj_48_49_IDT;
typedef uint8 ARS_OD_MsgCounter_Obj_50_51_IDT;
typedef uint8 ARS_OD_MsgCounter_Obj_52_53_IDT;
typedef uint8 ARS_OD_MsgCounter_Obj_54_55_IDT;
typedef uint8 ARS_OD_MsgCounter_Obj_56_57_IDT;
typedef uint8 ARS_OD_MsgCounter_Obj_58_59_IDT;
typedef uint8 ARS_OD_NumOfObjects_IDT;
typedef uint8 ARS_OD_ObstacleProb_Obj_00_IDT;
typedef uint8 ARS_OD_ObstacleProb_Obj_01_IDT;
typedef uint8 ARS_OD_ObstacleProb_Obj_02_IDT;
typedef uint8 ARS_OD_ObstacleProb_Obj_03_IDT;
typedef uint8 ARS_OD_ObstacleProb_Obj_04_IDT;
typedef uint8 ARS_OD_ObstacleProb_Obj_05_IDT;
typedef uint8 ARS_OD_ObstacleProb_Obj_06_IDT;
typedef uint8 ARS_OD_ObstacleProb_Obj_07_IDT;
typedef uint8 ARS_OD_ObstacleProb_Obj_08_IDT;
typedef uint8 ARS_OD_ObstacleProb_Obj_09_IDT;
typedef uint8 ARS_OD_ObstacleProb_Obj_10_IDT;
typedef uint8 ARS_OD_ObstacleProb_Obj_11_IDT;
typedef uint8 ARS_OD_ObstacleProb_Obj_12_IDT;
typedef uint8 ARS_OD_ObstacleProb_Obj_13_IDT;
typedef uint8 ARS_OD_ObstacleProb_Obj_14_IDT;
typedef uint8 ARS_OD_ObstacleProb_Obj_15_IDT;
typedef uint8 ARS_OD_ObstacleProb_Obj_16_IDT;
typedef uint8 ARS_OD_ObstacleProb_Obj_17_IDT;
typedef uint8 ARS_OD_ObstacleProb_Obj_18_IDT;
typedef uint8 ARS_OD_ObstacleProb_Obj_19_IDT;
typedef uint8 ARS_OD_ObstacleProb_Obj_20_IDT;
typedef uint8 ARS_OD_ObstacleProb_Obj_21_IDT;
typedef uint8 ARS_OD_ObstacleProb_Obj_22_IDT;
typedef uint8 ARS_OD_ObstacleProb_Obj_23_IDT;
typedef uint8 ARS_OD_ObstacleProb_Obj_24_IDT;
typedef uint8 ARS_OD_ObstacleProb_Obj_25_IDT;
typedef uint8 ARS_OD_ObstacleProb_Obj_26_IDT;
typedef uint8 ARS_OD_ObstacleProb_Obj_27_IDT;
typedef uint8 ARS_OD_ObstacleProb_Obj_28_IDT;
typedef uint8 ARS_OD_ObstacleProb_Obj_29_IDT;
typedef uint8 ARS_OD_ObstacleProb_Obj_30_IDT;
typedef uint8 ARS_OD_ObstacleProb_Obj_31_IDT;
typedef uint8 ARS_OD_ObstacleProb_Obj_32_IDT;
typedef uint8 ARS_OD_ObstacleProb_Obj_33_IDT;
typedef uint8 ARS_OD_ObstacleProb_Obj_34_IDT;
typedef uint8 ARS_OD_ObstacleProb_Obj_35_IDT;
typedef uint8 ARS_OD_ObstacleProb_Obj_36_IDT;
typedef uint8 ARS_OD_ObstacleProb_Obj_37_IDT;
typedef uint8 ARS_OD_ObstacleProb_Obj_38_IDT;
typedef uint8 ARS_OD_ObstacleProb_Obj_39_IDT;
typedef uint8 ARS_OD_ObstacleProb_Obj_40_IDT;
typedef uint8 ARS_OD_ObstacleProb_Obj_41_IDT;
typedef uint8 ARS_OD_ObstacleProb_Obj_42_IDT;
typedef uint8 ARS_OD_ObstacleProb_Obj_43_IDT;
typedef uint8 ARS_OD_ObstacleProb_Obj_44_IDT;
typedef uint8 ARS_OD_ObstacleProb_Obj_45_IDT;
typedef uint8 ARS_OD_ObstacleProb_Obj_46_IDT;
typedef uint8 ARS_OD_ObstacleProb_Obj_47_IDT;
typedef uint8 ARS_OD_ObstacleProb_Obj_48_IDT;
typedef uint8 ARS_OD_ObstacleProb_Obj_49_IDT;
typedef uint8 ARS_OD_ObstacleProb_Obj_50_IDT;
typedef uint8 ARS_OD_ObstacleProb_Obj_51_IDT;
typedef uint8 ARS_OD_ObstacleProb_Obj_52_IDT;
typedef uint8 ARS_OD_ObstacleProb_Obj_53_IDT;
typedef uint8 ARS_OD_ObstacleProb_Obj_54_IDT;
typedef uint8 ARS_OD_ObstacleProb_Obj_55_IDT;
typedef uint8 ARS_OD_ObstacleProb_Obj_56_IDT;
typedef uint8 ARS_OD_ObstacleProb_Obj_57_IDT;
typedef uint8 ARS_OD_ObstacleProb_Obj_58_IDT;
typedef uint8 ARS_OD_ObstacleProb_Obj_59_IDT;
typedef uint8 ARS_OD_OrientationStd_Obj_00_IDT;
typedef uint8 ARS_OD_OrientationStd_Obj_01_IDT;
typedef uint8 ARS_OD_OrientationStd_Obj_02_IDT;
typedef uint8 ARS_OD_OrientationStd_Obj_03_IDT;
typedef uint8 ARS_OD_OrientationStd_Obj_04_IDT;
typedef uint8 ARS_OD_OrientationStd_Obj_05_IDT;
typedef uint8 ARS_OD_OrientationStd_Obj_06_IDT;
typedef uint8 ARS_OD_OrientationStd_Obj_07_IDT;
typedef uint8 ARS_OD_OrientationStd_Obj_08_IDT;
typedef uint8 ARS_OD_OrientationStd_Obj_09_IDT;
typedef uint8 ARS_OD_OrientationStd_Obj_10_IDT;
typedef uint8 ARS_OD_OrientationStd_Obj_11_IDT;
typedef uint8 ARS_OD_OrientationStd_Obj_12_IDT;
typedef uint8 ARS_OD_OrientationStd_Obj_13_IDT;
typedef uint8 ARS_OD_OrientationStd_Obj_14_IDT;
typedef uint8 ARS_OD_OrientationStd_Obj_15_IDT;
typedef uint8 ARS_OD_OrientationStd_Obj_16_IDT;
typedef uint8 ARS_OD_OrientationStd_Obj_17_IDT;
typedef uint8 ARS_OD_OrientationStd_Obj_18_IDT;
typedef uint8 ARS_OD_OrientationStd_Obj_19_IDT;
typedef uint8 ARS_OD_OrientationStd_Obj_20_IDT;
typedef uint8 ARS_OD_OrientationStd_Obj_21_IDT;
typedef uint8 ARS_OD_OrientationStd_Obj_22_IDT;
typedef uint8 ARS_OD_OrientationStd_Obj_23_IDT;
typedef uint8 ARS_OD_OrientationStd_Obj_24_IDT;
typedef uint8 ARS_OD_OrientationStd_Obj_25_IDT;
typedef uint8 ARS_OD_OrientationStd_Obj_26_IDT;
typedef uint8 ARS_OD_OrientationStd_Obj_27_IDT;
typedef uint8 ARS_OD_OrientationStd_Obj_28_IDT;
typedef uint8 ARS_OD_OrientationStd_Obj_29_IDT;
typedef uint8 ARS_OD_OrientationStd_Obj_30_IDT;
typedef uint8 ARS_OD_OrientationStd_Obj_31_IDT;
typedef uint8 ARS_OD_OrientationStd_Obj_32_IDT;
typedef uint8 ARS_OD_OrientationStd_Obj_33_IDT;
typedef uint8 ARS_OD_OrientationStd_Obj_34_IDT;
typedef uint8 ARS_OD_OrientationStd_Obj_35_IDT;
typedef uint8 ARS_OD_OrientationStd_Obj_36_IDT;
typedef uint8 ARS_OD_OrientationStd_Obj_37_IDT;
typedef uint8 ARS_OD_OrientationStd_Obj_38_IDT;
typedef uint8 ARS_OD_OrientationStd_Obj_39_IDT;
typedef uint8 ARS_OD_OrientationStd_Obj_40_IDT;
typedef uint8 ARS_OD_OrientationStd_Obj_41_IDT;
typedef uint8 ARS_OD_OrientationStd_Obj_42_IDT;
typedef uint8 ARS_OD_OrientationStd_Obj_43_IDT;
typedef uint8 ARS_OD_OrientationStd_Obj_44_IDT;
typedef uint8 ARS_OD_OrientationStd_Obj_45_IDT;
typedef uint8 ARS_OD_OrientationStd_Obj_46_IDT;
typedef uint8 ARS_OD_OrientationStd_Obj_47_IDT;
typedef uint8 ARS_OD_OrientationStd_Obj_48_IDT;
typedef uint8 ARS_OD_OrientationStd_Obj_49_IDT;
typedef uint8 ARS_OD_OrientationStd_Obj_50_IDT;
typedef uint8 ARS_OD_OrientationStd_Obj_51_IDT;
typedef uint8 ARS_OD_OrientationStd_Obj_52_IDT;
typedef uint8 ARS_OD_OrientationStd_Obj_53_IDT;
typedef uint8 ARS_OD_OrientationStd_Obj_54_IDT;
typedef uint8 ARS_OD_OrientationStd_Obj_55_IDT;
typedef uint8 ARS_OD_OrientationStd_Obj_56_IDT;
typedef uint8 ARS_OD_OrientationStd_Obj_57_IDT;
typedef uint8 ARS_OD_OrientationStd_Obj_58_IDT;
typedef uint8 ARS_OD_OrientationStd_Obj_59_IDT;
typedef uint16 ARS_OD_Orientation_Obj_00_IDT;
typedef uint16 ARS_OD_Orientation_Obj_01_IDT;
typedef uint16 ARS_OD_Orientation_Obj_02_IDT;
typedef uint16 ARS_OD_Orientation_Obj_03_IDT;
typedef uint16 ARS_OD_Orientation_Obj_04_IDT;
typedef uint16 ARS_OD_Orientation_Obj_05_IDT;
typedef uint16 ARS_OD_Orientation_Obj_06_IDT;
typedef uint16 ARS_OD_Orientation_Obj_07_IDT;
typedef uint16 ARS_OD_Orientation_Obj_08_IDT;
typedef uint16 ARS_OD_Orientation_Obj_09_IDT;
typedef uint16 ARS_OD_Orientation_Obj_10_IDT;
typedef uint16 ARS_OD_Orientation_Obj_11_IDT;
typedef uint16 ARS_OD_Orientation_Obj_12_IDT;
typedef uint16 ARS_OD_Orientation_Obj_13_IDT;
typedef uint16 ARS_OD_Orientation_Obj_14_IDT;
typedef uint16 ARS_OD_Orientation_Obj_15_IDT;
typedef uint16 ARS_OD_Orientation_Obj_16_IDT;
typedef uint16 ARS_OD_Orientation_Obj_17_IDT;
typedef uint16 ARS_OD_Orientation_Obj_18_IDT;
typedef uint16 ARS_OD_Orientation_Obj_19_IDT;
typedef uint16 ARS_OD_Orientation_Obj_20_IDT;
typedef uint16 ARS_OD_Orientation_Obj_21_IDT;
typedef uint16 ARS_OD_Orientation_Obj_22_IDT;
typedef uint16 ARS_OD_Orientation_Obj_23_IDT;
typedef uint16 ARS_OD_Orientation_Obj_24_IDT;
typedef uint16 ARS_OD_Orientation_Obj_25_IDT;
typedef uint16 ARS_OD_Orientation_Obj_26_IDT;
typedef uint16 ARS_OD_Orientation_Obj_27_IDT;
typedef uint16 ARS_OD_Orientation_Obj_28_IDT;
typedef uint16 ARS_OD_Orientation_Obj_29_IDT;
typedef uint16 ARS_OD_Orientation_Obj_30_IDT;
typedef uint16 ARS_OD_Orientation_Obj_31_IDT;
typedef uint16 ARS_OD_Orientation_Obj_32_IDT;
typedef uint16 ARS_OD_Orientation_Obj_33_IDT;
typedef uint16 ARS_OD_Orientation_Obj_34_IDT;
typedef uint16 ARS_OD_Orientation_Obj_35_IDT;
typedef uint16 ARS_OD_Orientation_Obj_36_IDT;
typedef uint16 ARS_OD_Orientation_Obj_37_IDT;
typedef uint16 ARS_OD_Orientation_Obj_38_IDT;
typedef uint16 ARS_OD_Orientation_Obj_39_IDT;
typedef uint16 ARS_OD_Orientation_Obj_40_IDT;
typedef uint16 ARS_OD_Orientation_Obj_41_IDT;
typedef uint16 ARS_OD_Orientation_Obj_42_IDT;
typedef uint16 ARS_OD_Orientation_Obj_43_IDT;
typedef uint16 ARS_OD_Orientation_Obj_44_IDT;
typedef uint16 ARS_OD_Orientation_Obj_45_IDT;
typedef uint16 ARS_OD_Orientation_Obj_46_IDT;
typedef uint16 ARS_OD_Orientation_Obj_47_IDT;
typedef uint16 ARS_OD_Orientation_Obj_48_IDT;
typedef uint16 ARS_OD_Orientation_Obj_49_IDT;
typedef uint16 ARS_OD_Orientation_Obj_50_IDT;
typedef uint16 ARS_OD_Orientation_Obj_51_IDT;
typedef uint16 ARS_OD_Orientation_Obj_52_IDT;
typedef uint16 ARS_OD_Orientation_Obj_53_IDT;
typedef uint16 ARS_OD_Orientation_Obj_54_IDT;
typedef uint16 ARS_OD_Orientation_Obj_55_IDT;
typedef uint16 ARS_OD_Orientation_Obj_56_IDT;
typedef uint16 ARS_OD_Orientation_Obj_57_IDT;
typedef uint16 ARS_OD_Orientation_Obj_58_IDT;
typedef uint16 ARS_OD_Orientation_Obj_59_IDT;
typedef uint8 ARS_OD_ProbOfExist_Obj_00_IDT;
typedef uint8 ARS_OD_ProbOfExist_Obj_01_IDT;
typedef uint8 ARS_OD_ProbOfExist_Obj_02_IDT;
typedef uint8 ARS_OD_ProbOfExist_Obj_03_IDT;
typedef uint8 ARS_OD_ProbOfExist_Obj_04_IDT;
typedef uint8 ARS_OD_ProbOfExist_Obj_05_IDT;
typedef uint8 ARS_OD_ProbOfExist_Obj_06_IDT;
typedef uint8 ARS_OD_ProbOfExist_Obj_07_IDT;
typedef uint8 ARS_OD_ProbOfExist_Obj_08_IDT;
typedef uint8 ARS_OD_ProbOfExist_Obj_09_IDT;
typedef uint8 ARS_OD_ProbOfExist_Obj_10_IDT;
typedef uint8 ARS_OD_ProbOfExist_Obj_11_IDT;
typedef uint8 ARS_OD_ProbOfExist_Obj_12_IDT;
typedef uint8 ARS_OD_ProbOfExist_Obj_13_IDT;
typedef uint8 ARS_OD_ProbOfExist_Obj_14_IDT;
typedef uint8 ARS_OD_ProbOfExist_Obj_15_IDT;
typedef uint8 ARS_OD_ProbOfExist_Obj_16_IDT;
typedef uint8 ARS_OD_ProbOfExist_Obj_17_IDT;
typedef uint8 ARS_OD_ProbOfExist_Obj_18_IDT;
typedef uint8 ARS_OD_ProbOfExist_Obj_19_IDT;
typedef uint8 ARS_OD_ProbOfExist_Obj_20_IDT;
typedef uint8 ARS_OD_ProbOfExist_Obj_21_IDT;
typedef uint8 ARS_OD_ProbOfExist_Obj_22_IDT;
typedef uint8 ARS_OD_ProbOfExist_Obj_23_IDT;
typedef uint8 ARS_OD_ProbOfExist_Obj_24_IDT;
typedef uint8 ARS_OD_ProbOfExist_Obj_25_IDT;
typedef uint8 ARS_OD_ProbOfExist_Obj_26_IDT;
typedef uint8 ARS_OD_ProbOfExist_Obj_27_IDT;
typedef uint8 ARS_OD_ProbOfExist_Obj_28_IDT;
typedef uint8 ARS_OD_ProbOfExist_Obj_29_IDT;
typedef uint8 ARS_OD_ProbOfExist_Obj_30_IDT;
typedef uint8 ARS_OD_ProbOfExist_Obj_31_IDT;
typedef uint8 ARS_OD_ProbOfExist_Obj_32_IDT;
typedef uint8 ARS_OD_ProbOfExist_Obj_33_IDT;
typedef uint8 ARS_OD_ProbOfExist_Obj_34_IDT;
typedef uint8 ARS_OD_ProbOfExist_Obj_35_IDT;
typedef uint8 ARS_OD_ProbOfExist_Obj_36_IDT;
typedef uint8 ARS_OD_ProbOfExist_Obj_37_IDT;
typedef uint8 ARS_OD_ProbOfExist_Obj_38_IDT;
typedef uint8 ARS_OD_ProbOfExist_Obj_39_IDT;
typedef uint8 ARS_OD_ProbOfExist_Obj_40_IDT;
typedef uint8 ARS_OD_ProbOfExist_Obj_41_IDT;
typedef uint8 ARS_OD_ProbOfExist_Obj_42_IDT;
typedef uint8 ARS_OD_ProbOfExist_Obj_43_IDT;
typedef uint8 ARS_OD_ProbOfExist_Obj_44_IDT;
typedef uint8 ARS_OD_ProbOfExist_Obj_45_IDT;
typedef uint8 ARS_OD_ProbOfExist_Obj_46_IDT;
typedef uint8 ARS_OD_ProbOfExist_Obj_47_IDT;
typedef uint8 ARS_OD_ProbOfExist_Obj_48_IDT;
typedef uint8 ARS_OD_ProbOfExist_Obj_49_IDT;
typedef uint8 ARS_OD_ProbOfExist_Obj_50_IDT;
typedef uint8 ARS_OD_ProbOfExist_Obj_51_IDT;
typedef uint8 ARS_OD_ProbOfExist_Obj_52_IDT;
typedef uint8 ARS_OD_ProbOfExist_Obj_53_IDT;
typedef uint8 ARS_OD_ProbOfExist_Obj_54_IDT;
typedef uint8 ARS_OD_ProbOfExist_Obj_55_IDT;
typedef uint8 ARS_OD_ProbOfExist_Obj_56_IDT;
typedef uint8 ARS_OD_ProbOfExist_Obj_57_IDT;
typedef uint8 ARS_OD_ProbOfExist_Obj_58_IDT;
typedef uint8 ARS_OD_ProbOfExist_Obj_59_IDT;
typedef uint16 ARS_OD_RCS_Obj_00_IDT;
typedef uint16 ARS_OD_RCS_Obj_01_IDT;
typedef uint16 ARS_OD_RCS_Obj_02_IDT;
typedef uint16 ARS_OD_RCS_Obj_03_IDT;
typedef uint16 ARS_OD_RCS_Obj_04_IDT;
typedef uint16 ARS_OD_RCS_Obj_05_IDT;
typedef uint16 ARS_OD_RCS_Obj_06_IDT;
typedef uint16 ARS_OD_RCS_Obj_07_IDT;
typedef uint16 ARS_OD_RCS_Obj_08_IDT;
typedef uint16 ARS_OD_RCS_Obj_09_IDT;
typedef uint16 ARS_OD_RCS_Obj_10_IDT;
typedef uint16 ARS_OD_RCS_Obj_11_IDT;
typedef uint16 ARS_OD_RCS_Obj_12_IDT;
typedef uint16 ARS_OD_RCS_Obj_13_IDT;
typedef uint16 ARS_OD_RCS_Obj_14_IDT;
typedef uint16 ARS_OD_RCS_Obj_15_IDT;
typedef uint16 ARS_OD_RCS_Obj_16_IDT;
typedef uint16 ARS_OD_RCS_Obj_17_IDT;
typedef uint16 ARS_OD_RCS_Obj_18_IDT;
typedef uint16 ARS_OD_RCS_Obj_19_IDT;
typedef uint16 ARS_OD_RCS_Obj_20_IDT;
typedef uint16 ARS_OD_RCS_Obj_21_IDT;
typedef uint16 ARS_OD_RCS_Obj_22_IDT;
typedef uint16 ARS_OD_RCS_Obj_23_IDT;
typedef uint16 ARS_OD_RCS_Obj_24_IDT;
typedef uint16 ARS_OD_RCS_Obj_25_IDT;
typedef uint16 ARS_OD_RCS_Obj_26_IDT;
typedef uint16 ARS_OD_RCS_Obj_27_IDT;
typedef uint16 ARS_OD_RCS_Obj_28_IDT;
typedef uint16 ARS_OD_RCS_Obj_29_IDT;
typedef uint16 ARS_OD_RCS_Obj_30_IDT;
typedef uint16 ARS_OD_RCS_Obj_31_IDT;
typedef uint16 ARS_OD_RCS_Obj_32_IDT;
typedef uint16 ARS_OD_RCS_Obj_33_IDT;
typedef uint16 ARS_OD_RCS_Obj_34_IDT;
typedef uint16 ARS_OD_RCS_Obj_35_IDT;
typedef uint16 ARS_OD_RCS_Obj_36_IDT;
typedef uint16 ARS_OD_RCS_Obj_37_IDT;
typedef uint16 ARS_OD_RCS_Obj_38_IDT;
typedef uint16 ARS_OD_RCS_Obj_39_IDT;
typedef uint16 ARS_OD_RCS_Obj_40_IDT;
typedef uint16 ARS_OD_RCS_Obj_41_IDT;
typedef uint16 ARS_OD_RCS_Obj_42_IDT;
typedef uint16 ARS_OD_RCS_Obj_43_IDT;
typedef uint16 ARS_OD_RCS_Obj_44_IDT;
typedef uint16 ARS_OD_RCS_Obj_45_IDT;
typedef uint16 ARS_OD_RCS_Obj_46_IDT;
typedef uint16 ARS_OD_RCS_Obj_47_IDT;
typedef uint16 ARS_OD_RCS_Obj_48_IDT;
typedef uint16 ARS_OD_RCS_Obj_49_IDT;
typedef uint16 ARS_OD_RCS_Obj_50_IDT;
typedef uint16 ARS_OD_RCS_Obj_51_IDT;
typedef uint16 ARS_OD_RCS_Obj_52_IDT;
typedef uint16 ARS_OD_RCS_Obj_53_IDT;
typedef uint16 ARS_OD_RCS_Obj_54_IDT;
typedef uint16 ARS_OD_RCS_Obj_55_IDT;
typedef uint16 ARS_OD_RCS_Obj_56_IDT;
typedef uint16 ARS_OD_RCS_Obj_57_IDT;
typedef uint16 ARS_OD_RCS_Obj_58_IDT;
typedef uint16 ARS_OD_RCS_Obj_59_IDT;
typedef uint8 ARS_OD_RefPoint_Obj_00_IDT;
typedef uint8 ARS_OD_RefPoint_Obj_01_IDT;
typedef uint8 ARS_OD_RefPoint_Obj_02_IDT;
typedef uint8 ARS_OD_RefPoint_Obj_03_IDT;
typedef uint8 ARS_OD_RefPoint_Obj_04_IDT;
typedef uint8 ARS_OD_RefPoint_Obj_05_IDT;
typedef uint8 ARS_OD_RefPoint_Obj_06_IDT;
typedef uint8 ARS_OD_RefPoint_Obj_07_IDT;
typedef uint8 ARS_OD_RefPoint_Obj_08_IDT;
typedef uint8 ARS_OD_RefPoint_Obj_09_IDT;
typedef uint8 ARS_OD_RefPoint_Obj_10_IDT;
typedef uint8 ARS_OD_RefPoint_Obj_11_IDT;
typedef uint8 ARS_OD_RefPoint_Obj_12_IDT;
typedef uint8 ARS_OD_RefPoint_Obj_13_IDT;
typedef uint8 ARS_OD_RefPoint_Obj_14_IDT;
typedef uint8 ARS_OD_RefPoint_Obj_15_IDT;
typedef uint8 ARS_OD_RefPoint_Obj_16_IDT;
typedef uint8 ARS_OD_RefPoint_Obj_17_IDT;
typedef uint8 ARS_OD_RefPoint_Obj_18_IDT;
typedef uint8 ARS_OD_RefPoint_Obj_19_IDT;
typedef uint8 ARS_OD_RefPoint_Obj_20_IDT;
typedef uint8 ARS_OD_RefPoint_Obj_21_IDT;
typedef uint8 ARS_OD_RefPoint_Obj_22_IDT;
typedef uint8 ARS_OD_RefPoint_Obj_23_IDT;
typedef uint8 ARS_OD_RefPoint_Obj_24_IDT;
typedef uint8 ARS_OD_RefPoint_Obj_25_IDT;
typedef uint8 ARS_OD_RefPoint_Obj_26_IDT;
typedef uint8 ARS_OD_RefPoint_Obj_27_IDT;
typedef uint8 ARS_OD_RefPoint_Obj_28_IDT;
typedef uint8 ARS_OD_RefPoint_Obj_29_IDT;
typedef uint8 ARS_OD_RefPoint_Obj_30_IDT;
typedef uint8 ARS_OD_RefPoint_Obj_31_IDT;
typedef uint8 ARS_OD_RefPoint_Obj_32_IDT;
typedef uint8 ARS_OD_RefPoint_Obj_33_IDT;
typedef uint8 ARS_OD_RefPoint_Obj_34_IDT;
typedef uint8 ARS_OD_RefPoint_Obj_35_IDT;
typedef uint8 ARS_OD_RefPoint_Obj_36_IDT;
typedef uint8 ARS_OD_RefPoint_Obj_37_IDT;
typedef uint8 ARS_OD_RefPoint_Obj_38_IDT;
typedef uint8 ARS_OD_RefPoint_Obj_39_IDT;
typedef uint8 ARS_OD_RefPoint_Obj_40_IDT;
typedef uint8 ARS_OD_RefPoint_Obj_41_IDT;
typedef uint8 ARS_OD_RefPoint_Obj_42_IDT;
typedef uint8 ARS_OD_RefPoint_Obj_43_IDT;
typedef uint8 ARS_OD_RefPoint_Obj_44_IDT;
typedef uint8 ARS_OD_RefPoint_Obj_45_IDT;
typedef uint8 ARS_OD_RefPoint_Obj_46_IDT;
typedef uint8 ARS_OD_RefPoint_Obj_47_IDT;
typedef uint8 ARS_OD_RefPoint_Obj_48_IDT;
typedef uint8 ARS_OD_RefPoint_Obj_49_IDT;
typedef uint8 ARS_OD_RefPoint_Obj_50_IDT;
typedef uint8 ARS_OD_RefPoint_Obj_51_IDT;
typedef uint8 ARS_OD_RefPoint_Obj_52_IDT;
typedef uint8 ARS_OD_RefPoint_Obj_53_IDT;
typedef uint8 ARS_OD_RefPoint_Obj_54_IDT;
typedef uint8 ARS_OD_RefPoint_Obj_55_IDT;
typedef uint8 ARS_OD_RefPoint_Obj_56_IDT;
typedef uint8 ARS_OD_RefPoint_Obj_57_IDT;
typedef uint8 ARS_OD_RefPoint_Obj_58_IDT;
typedef uint8 ARS_OD_RefPoint_Obj_59_IDT;
typedef uint8 ARS_OD_TaskValidFlag_IDT;
typedef uint32 ARS_OD_TimeStampGlobNanoSec_IDT;
typedef uint32 ARS_OD_TimeStampGlobSec_IDT;
typedef uint32 ARS_OD_TimeStampLocal_IDT;
typedef uint8 ARS_OD_VabsXStd_Obj_00_IDT;
typedef uint8 ARS_OD_VabsXStd_Obj_01_IDT;
typedef uint8 ARS_OD_VabsXStd_Obj_02_IDT;
typedef uint8 ARS_OD_VabsXStd_Obj_03_IDT;
typedef uint8 ARS_OD_VabsXStd_Obj_04_IDT;
typedef uint8 ARS_OD_VabsXStd_Obj_05_IDT;
typedef uint8 ARS_OD_VabsXStd_Obj_06_IDT;
typedef uint8 ARS_OD_VabsXStd_Obj_07_IDT;
typedef uint8 ARS_OD_VabsXStd_Obj_08_IDT;
typedef uint8 ARS_OD_VabsXStd_Obj_09_IDT;
typedef uint8 ARS_OD_VabsXStd_Obj_10_IDT;
typedef uint8 ARS_OD_VabsXStd_Obj_11_IDT;
typedef uint8 ARS_OD_VabsXStd_Obj_12_IDT;
typedef uint8 ARS_OD_VabsXStd_Obj_13_IDT;
typedef uint8 ARS_OD_VabsXStd_Obj_14_IDT;
typedef uint8 ARS_OD_VabsXStd_Obj_15_IDT;
typedef uint8 ARS_OD_VabsXStd_Obj_16_IDT;
typedef uint8 ARS_OD_VabsXStd_Obj_17_IDT;
typedef uint8 ARS_OD_VabsXStd_Obj_18_IDT;
typedef uint8 ARS_OD_VabsXStd_Obj_19_IDT;
typedef uint8 ARS_OD_VabsXStd_Obj_20_IDT;
typedef uint8 ARS_OD_VabsXStd_Obj_21_IDT;
typedef uint8 ARS_OD_VabsXStd_Obj_22_IDT;
typedef uint8 ARS_OD_VabsXStd_Obj_23_IDT;
typedef uint8 ARS_OD_VabsXStd_Obj_24_IDT;
typedef uint8 ARS_OD_VabsXStd_Obj_25_IDT;
typedef uint8 ARS_OD_VabsXStd_Obj_26_IDT;
typedef uint8 ARS_OD_VabsXStd_Obj_27_IDT;
typedef uint8 ARS_OD_VabsXStd_Obj_28_IDT;
typedef uint8 ARS_OD_VabsXStd_Obj_29_IDT;
typedef uint8 ARS_OD_VabsXStd_Obj_30_IDT;
typedef uint8 ARS_OD_VabsXStd_Obj_31_IDT;
typedef uint8 ARS_OD_VabsXStd_Obj_32_IDT;
typedef uint8 ARS_OD_VabsXStd_Obj_33_IDT;
typedef uint8 ARS_OD_VabsXStd_Obj_34_IDT;
typedef uint8 ARS_OD_VabsXStd_Obj_35_IDT;
typedef uint8 ARS_OD_VabsXStd_Obj_36_IDT;
typedef uint8 ARS_OD_VabsXStd_Obj_37_IDT;
typedef uint8 ARS_OD_VabsXStd_Obj_38_IDT;
typedef uint8 ARS_OD_VabsXStd_Obj_39_IDT;
typedef uint8 ARS_OD_VabsXStd_Obj_40_IDT;
typedef uint8 ARS_OD_VabsXStd_Obj_41_IDT;
typedef uint8 ARS_OD_VabsXStd_Obj_42_IDT;
typedef uint8 ARS_OD_VabsXStd_Obj_43_IDT;
typedef uint8 ARS_OD_VabsXStd_Obj_44_IDT;
typedef uint8 ARS_OD_VabsXStd_Obj_45_IDT;
typedef uint8 ARS_OD_VabsXStd_Obj_46_IDT;
typedef uint8 ARS_OD_VabsXStd_Obj_47_IDT;
typedef uint8 ARS_OD_VabsXStd_Obj_48_IDT;
typedef uint8 ARS_OD_VabsXStd_Obj_49_IDT;
typedef uint8 ARS_OD_VabsXStd_Obj_50_IDT;
typedef uint8 ARS_OD_VabsXStd_Obj_51_IDT;
typedef uint8 ARS_OD_VabsXStd_Obj_52_IDT;
typedef uint8 ARS_OD_VabsXStd_Obj_53_IDT;
typedef uint8 ARS_OD_VabsXStd_Obj_54_IDT;
typedef uint8 ARS_OD_VabsXStd_Obj_55_IDT;
typedef uint8 ARS_OD_VabsXStd_Obj_56_IDT;
typedef uint8 ARS_OD_VabsXStd_Obj_57_IDT;
typedef uint8 ARS_OD_VabsXStd_Obj_58_IDT;
typedef uint8 ARS_OD_VabsXStd_Obj_59_IDT;
typedef uint16 ARS_OD_VabsX_Obj_00_IDT;
typedef uint16 ARS_OD_VabsX_Obj_01_IDT;
typedef uint16 ARS_OD_VabsX_Obj_02_IDT;
typedef uint16 ARS_OD_VabsX_Obj_03_IDT;
typedef uint16 ARS_OD_VabsX_Obj_04_IDT;
typedef uint16 ARS_OD_VabsX_Obj_05_IDT;
typedef uint16 ARS_OD_VabsX_Obj_06_IDT;
typedef uint16 ARS_OD_VabsX_Obj_07_IDT;
typedef uint16 ARS_OD_VabsX_Obj_08_IDT;
typedef uint16 ARS_OD_VabsX_Obj_09_IDT;
typedef uint16 ARS_OD_VabsX_Obj_10_IDT;
typedef uint16 ARS_OD_VabsX_Obj_11_IDT;
typedef uint16 ARS_OD_VabsX_Obj_12_IDT;
typedef uint16 ARS_OD_VabsX_Obj_13_IDT;
typedef uint16 ARS_OD_VabsX_Obj_14_IDT;
typedef uint16 ARS_OD_VabsX_Obj_15_IDT;
typedef uint16 ARS_OD_VabsX_Obj_16_IDT;
typedef uint16 ARS_OD_VabsX_Obj_17_IDT;
typedef uint16 ARS_OD_VabsX_Obj_18_IDT;
typedef uint16 ARS_OD_VabsX_Obj_19_IDT;
typedef uint16 ARS_OD_VabsX_Obj_20_IDT;
typedef uint16 ARS_OD_VabsX_Obj_21_IDT;
typedef uint16 ARS_OD_VabsX_Obj_22_IDT;
typedef uint16 ARS_OD_VabsX_Obj_23_IDT;
typedef uint16 ARS_OD_VabsX_Obj_24_IDT;
typedef uint16 ARS_OD_VabsX_Obj_25_IDT;
typedef uint16 ARS_OD_VabsX_Obj_26_IDT;
typedef uint16 ARS_OD_VabsX_Obj_27_IDT;
typedef uint16 ARS_OD_VabsX_Obj_28_IDT;
typedef uint16 ARS_OD_VabsX_Obj_29_IDT;
typedef uint16 ARS_OD_VabsX_Obj_30_IDT;
typedef uint16 ARS_OD_VabsX_Obj_31_IDT;
typedef uint16 ARS_OD_VabsX_Obj_32_IDT;
typedef uint16 ARS_OD_VabsX_Obj_33_IDT;
typedef uint16 ARS_OD_VabsX_Obj_34_IDT;
typedef uint16 ARS_OD_VabsX_Obj_35_IDT;
typedef uint16 ARS_OD_VabsX_Obj_36_IDT;
typedef uint16 ARS_OD_VabsX_Obj_37_IDT;
typedef uint16 ARS_OD_VabsX_Obj_38_IDT;
typedef uint16 ARS_OD_VabsX_Obj_39_IDT;
typedef uint16 ARS_OD_VabsX_Obj_40_IDT;
typedef uint16 ARS_OD_VabsX_Obj_41_IDT;
typedef uint16 ARS_OD_VabsX_Obj_42_IDT;
typedef uint16 ARS_OD_VabsX_Obj_43_IDT;
typedef uint16 ARS_OD_VabsX_Obj_44_IDT;
typedef uint16 ARS_OD_VabsX_Obj_45_IDT;
typedef uint16 ARS_OD_VabsX_Obj_46_IDT;
typedef uint16 ARS_OD_VabsX_Obj_47_IDT;
typedef uint16 ARS_OD_VabsX_Obj_48_IDT;
typedef uint16 ARS_OD_VabsX_Obj_49_IDT;
typedef uint16 ARS_OD_VabsX_Obj_50_IDT;
typedef uint16 ARS_OD_VabsX_Obj_51_IDT;
typedef uint16 ARS_OD_VabsX_Obj_52_IDT;
typedef uint16 ARS_OD_VabsX_Obj_53_IDT;
typedef uint16 ARS_OD_VabsX_Obj_54_IDT;
typedef uint16 ARS_OD_VabsX_Obj_55_IDT;
typedef uint16 ARS_OD_VabsX_Obj_56_IDT;
typedef uint16 ARS_OD_VabsX_Obj_57_IDT;
typedef uint16 ARS_OD_VabsX_Obj_58_IDT;
typedef uint16 ARS_OD_VabsX_Obj_59_IDT;
typedef uint8 ARS_OD_VabsYStd_Obj_00_IDT;
typedef uint8 ARS_OD_VabsYStd_Obj_01_IDT;
typedef uint8 ARS_OD_VabsYStd_Obj_02_IDT;
typedef uint8 ARS_OD_VabsYStd_Obj_03_IDT;
typedef uint8 ARS_OD_VabsYStd_Obj_04_IDT;
typedef uint8 ARS_OD_VabsYStd_Obj_05_IDT;
typedef uint8 ARS_OD_VabsYStd_Obj_06_IDT;
typedef uint8 ARS_OD_VabsYStd_Obj_07_IDT;
typedef uint8 ARS_OD_VabsYStd_Obj_08_IDT;
typedef uint8 ARS_OD_VabsYStd_Obj_09_IDT;
typedef uint8 ARS_OD_VabsYStd_Obj_10_IDT;
typedef uint8 ARS_OD_VabsYStd_Obj_11_IDT;
typedef uint8 ARS_OD_VabsYStd_Obj_12_IDT;
typedef uint8 ARS_OD_VabsYStd_Obj_13_IDT;
typedef uint8 ARS_OD_VabsYStd_Obj_14_IDT;
typedef uint8 ARS_OD_VabsYStd_Obj_15_IDT;
typedef uint8 ARS_OD_VabsYStd_Obj_16_IDT;
typedef uint8 ARS_OD_VabsYStd_Obj_17_IDT;
typedef uint8 ARS_OD_VabsYStd_Obj_18_IDT;
typedef uint8 ARS_OD_VabsYStd_Obj_19_IDT;
typedef uint8 ARS_OD_VabsYStd_Obj_20_IDT;
typedef uint8 ARS_OD_VabsYStd_Obj_21_IDT;
typedef uint8 ARS_OD_VabsYStd_Obj_22_IDT;
typedef uint8 ARS_OD_VabsYStd_Obj_23_IDT;
typedef uint8 ARS_OD_VabsYStd_Obj_24_IDT;
typedef uint8 ARS_OD_VabsYStd_Obj_25_IDT;
typedef uint8 ARS_OD_VabsYStd_Obj_26_IDT;
typedef uint8 ARS_OD_VabsYStd_Obj_27_IDT;
typedef uint8 ARS_OD_VabsYStd_Obj_28_IDT;
typedef uint8 ARS_OD_VabsYStd_Obj_29_IDT;
typedef uint8 ARS_OD_VabsYStd_Obj_30_IDT;
typedef uint8 ARS_OD_VabsYStd_Obj_31_IDT;
typedef uint8 ARS_OD_VabsYStd_Obj_32_IDT;
typedef uint8 ARS_OD_VabsYStd_Obj_33_IDT;
typedef uint8 ARS_OD_VabsYStd_Obj_34_IDT;
typedef uint8 ARS_OD_VabsYStd_Obj_35_IDT;
typedef uint8 ARS_OD_VabsYStd_Obj_36_IDT;
typedef uint8 ARS_OD_VabsYStd_Obj_37_IDT;
typedef uint8 ARS_OD_VabsYStd_Obj_38_IDT;
typedef uint8 ARS_OD_VabsYStd_Obj_39_IDT;
typedef uint8 ARS_OD_VabsYStd_Obj_40_IDT;
typedef uint8 ARS_OD_VabsYStd_Obj_41_IDT;
typedef uint8 ARS_OD_VabsYStd_Obj_42_IDT;
typedef uint8 ARS_OD_VabsYStd_Obj_43_IDT;
typedef uint8 ARS_OD_VabsYStd_Obj_44_IDT;
typedef uint8 ARS_OD_VabsYStd_Obj_45_IDT;
typedef uint8 ARS_OD_VabsYStd_Obj_46_IDT;
typedef uint8 ARS_OD_VabsYStd_Obj_47_IDT;
typedef uint8 ARS_OD_VabsYStd_Obj_48_IDT;
typedef uint8 ARS_OD_VabsYStd_Obj_49_IDT;
typedef uint8 ARS_OD_VabsYStd_Obj_50_IDT;
typedef uint8 ARS_OD_VabsYStd_Obj_51_IDT;
typedef uint8 ARS_OD_VabsYStd_Obj_52_IDT;
typedef uint8 ARS_OD_VabsYStd_Obj_53_IDT;
typedef uint8 ARS_OD_VabsYStd_Obj_54_IDT;
typedef uint8 ARS_OD_VabsYStd_Obj_55_IDT;
typedef uint8 ARS_OD_VabsYStd_Obj_56_IDT;
typedef uint8 ARS_OD_VabsYStd_Obj_57_IDT;
typedef uint8 ARS_OD_VabsYStd_Obj_58_IDT;
typedef uint8 ARS_OD_VabsYStd_Obj_59_IDT;
typedef uint16 ARS_OD_VabsY_Obj_00_IDT;
typedef uint16 ARS_OD_VabsY_Obj_01_IDT;
typedef uint16 ARS_OD_VabsY_Obj_02_IDT;
typedef uint16 ARS_OD_VabsY_Obj_03_IDT;
typedef uint16 ARS_OD_VabsY_Obj_04_IDT;
typedef uint16 ARS_OD_VabsY_Obj_05_IDT;
typedef uint16 ARS_OD_VabsY_Obj_06_IDT;
typedef uint16 ARS_OD_VabsY_Obj_07_IDT;
typedef uint16 ARS_OD_VabsY_Obj_08_IDT;
typedef uint16 ARS_OD_VabsY_Obj_09_IDT;
typedef uint16 ARS_OD_VabsY_Obj_10_IDT;
typedef uint16 ARS_OD_VabsY_Obj_11_IDT;
typedef uint16 ARS_OD_VabsY_Obj_12_IDT;
typedef uint16 ARS_OD_VabsY_Obj_13_IDT;
typedef uint16 ARS_OD_VabsY_Obj_14_IDT;
typedef uint16 ARS_OD_VabsY_Obj_15_IDT;
typedef uint16 ARS_OD_VabsY_Obj_16_IDT;
typedef uint16 ARS_OD_VabsY_Obj_17_IDT;
typedef uint16 ARS_OD_VabsY_Obj_18_IDT;
typedef uint16 ARS_OD_VabsY_Obj_19_IDT;
typedef uint16 ARS_OD_VabsY_Obj_20_IDT;
typedef uint16 ARS_OD_VabsY_Obj_21_IDT;
typedef uint16 ARS_OD_VabsY_Obj_22_IDT;
typedef uint16 ARS_OD_VabsY_Obj_23_IDT;
typedef uint16 ARS_OD_VabsY_Obj_24_IDT;
typedef uint16 ARS_OD_VabsY_Obj_25_IDT;
typedef uint16 ARS_OD_VabsY_Obj_26_IDT;
typedef uint16 ARS_OD_VabsY_Obj_27_IDT;
typedef uint16 ARS_OD_VabsY_Obj_28_IDT;
typedef uint16 ARS_OD_VabsY_Obj_29_IDT;
typedef uint16 ARS_OD_VabsY_Obj_30_IDT;
typedef uint16 ARS_OD_VabsY_Obj_31_IDT;
typedef uint16 ARS_OD_VabsY_Obj_32_IDT;
typedef uint16 ARS_OD_VabsY_Obj_33_IDT;
typedef uint16 ARS_OD_VabsY_Obj_34_IDT;
typedef uint16 ARS_OD_VabsY_Obj_35_IDT;
typedef uint16 ARS_OD_VabsY_Obj_36_IDT;
typedef uint16 ARS_OD_VabsY_Obj_37_IDT;
typedef uint16 ARS_OD_VabsY_Obj_38_IDT;
typedef uint16 ARS_OD_VabsY_Obj_39_IDT;
typedef uint16 ARS_OD_VabsY_Obj_40_IDT;
typedef uint16 ARS_OD_VabsY_Obj_41_IDT;
typedef uint16 ARS_OD_VabsY_Obj_42_IDT;
typedef uint16 ARS_OD_VabsY_Obj_43_IDT;
typedef uint16 ARS_OD_VabsY_Obj_44_IDT;
typedef uint16 ARS_OD_VabsY_Obj_45_IDT;
typedef uint16 ARS_OD_VabsY_Obj_46_IDT;
typedef uint16 ARS_OD_VabsY_Obj_47_IDT;
typedef uint16 ARS_OD_VabsY_Obj_48_IDT;
typedef uint16 ARS_OD_VabsY_Obj_49_IDT;
typedef uint16 ARS_OD_VabsY_Obj_50_IDT;
typedef uint16 ARS_OD_VabsY_Obj_51_IDT;
typedef uint16 ARS_OD_VabsY_Obj_52_IDT;
typedef uint16 ARS_OD_VabsY_Obj_53_IDT;
typedef uint16 ARS_OD_VabsY_Obj_54_IDT;
typedef uint16 ARS_OD_VabsY_Obj_55_IDT;
typedef uint16 ARS_OD_VabsY_Obj_56_IDT;
typedef uint16 ARS_OD_VabsY_Obj_57_IDT;
typedef uint16 ARS_OD_VabsY_Obj_58_IDT;
typedef uint16 ARS_OD_VabsY_Obj_59_IDT;
typedef uint8 ARS_OD_Width_Obj_00_IDT;
typedef uint8 ARS_OD_Width_Obj_01_IDT;
typedef uint8 ARS_OD_Width_Obj_02_IDT;
typedef uint8 ARS_OD_Width_Obj_03_IDT;
typedef uint8 ARS_OD_Width_Obj_04_IDT;
typedef uint8 ARS_OD_Width_Obj_05_IDT;
typedef uint8 ARS_OD_Width_Obj_06_IDT;
typedef uint8 ARS_OD_Width_Obj_07_IDT;
typedef uint8 ARS_OD_Width_Obj_08_IDT;
typedef uint8 ARS_OD_Width_Obj_09_IDT;
typedef uint8 ARS_OD_Width_Obj_10_IDT;
typedef uint8 ARS_OD_Width_Obj_11_IDT;
typedef uint8 ARS_OD_Width_Obj_12_IDT;
typedef uint8 ARS_OD_Width_Obj_13_IDT;
typedef uint8 ARS_OD_Width_Obj_14_IDT;
typedef uint8 ARS_OD_Width_Obj_15_IDT;
typedef uint8 ARS_OD_Width_Obj_16_IDT;
typedef uint8 ARS_OD_Width_Obj_17_IDT;
typedef uint8 ARS_OD_Width_Obj_18_IDT;
typedef uint8 ARS_OD_Width_Obj_19_IDT;
typedef uint8 ARS_OD_Width_Obj_20_IDT;
typedef uint8 ARS_OD_Width_Obj_21_IDT;
typedef uint8 ARS_OD_Width_Obj_22_IDT;
typedef uint8 ARS_OD_Width_Obj_23_IDT;
typedef uint8 ARS_OD_Width_Obj_24_IDT;
typedef uint8 ARS_OD_Width_Obj_25_IDT;
typedef uint8 ARS_OD_Width_Obj_26_IDT;
typedef uint8 ARS_OD_Width_Obj_27_IDT;
typedef uint8 ARS_OD_Width_Obj_28_IDT;
typedef uint8 ARS_OD_Width_Obj_29_IDT;
typedef uint8 ARS_OD_Width_Obj_30_IDT;
typedef uint8 ARS_OD_Width_Obj_31_IDT;
typedef uint8 ARS_OD_Width_Obj_32_IDT;
typedef uint8 ARS_OD_Width_Obj_33_IDT;
typedef uint8 ARS_OD_Width_Obj_34_IDT;
typedef uint8 ARS_OD_Width_Obj_35_IDT;
typedef uint8 ARS_OD_Width_Obj_36_IDT;
typedef uint8 ARS_OD_Width_Obj_37_IDT;
typedef uint8 ARS_OD_Width_Obj_38_IDT;
typedef uint8 ARS_OD_Width_Obj_39_IDT;
typedef uint8 ARS_OD_Width_Obj_40_IDT;
typedef uint8 ARS_OD_Width_Obj_41_IDT;
typedef uint8 ARS_OD_Width_Obj_42_IDT;
typedef uint8 ARS_OD_Width_Obj_43_IDT;
typedef uint8 ARS_OD_Width_Obj_44_IDT;
typedef uint8 ARS_OD_Width_Obj_45_IDT;
typedef uint8 ARS_OD_Width_Obj_46_IDT;
typedef uint8 ARS_OD_Width_Obj_47_IDT;
typedef uint8 ARS_OD_Width_Obj_48_IDT;
typedef uint8 ARS_OD_Width_Obj_49_IDT;
typedef uint8 ARS_OD_Width_Obj_50_IDT;
typedef uint8 ARS_OD_Width_Obj_51_IDT;
typedef uint8 ARS_OD_Width_Obj_52_IDT;
typedef uint8 ARS_OD_Width_Obj_53_IDT;
typedef uint8 ARS_OD_Width_Obj_54_IDT;
typedef uint8 ARS_OD_Width_Obj_55_IDT;
typedef uint8 ARS_OD_Width_Obj_56_IDT;
typedef uint8 ARS_OD_Width_Obj_57_IDT;
typedef uint8 ARS_OD_Width_Obj_58_IDT;
typedef uint8 ARS_OD_Width_Obj_59_IDT;
typedef uint16 ARS_OD_YawRateAbsStd_Obj_00_IDT;
typedef uint16 ARS_OD_YawRateAbsStd_Obj_01_IDT;
typedef uint16 ARS_OD_YawRateAbsStd_Obj_02_IDT;
typedef uint16 ARS_OD_YawRateAbsStd_Obj_03_IDT;
typedef uint16 ARS_OD_YawRateAbsStd_Obj_04_IDT;
typedef uint16 ARS_OD_YawRateAbsStd_Obj_05_IDT;
typedef uint16 ARS_OD_YawRateAbsStd_Obj_06_IDT;
typedef uint16 ARS_OD_YawRateAbsStd_Obj_07_IDT;
typedef uint16 ARS_OD_YawRateAbsStd_Obj_08_IDT;
typedef uint16 ARS_OD_YawRateAbsStd_Obj_09_IDT;
typedef uint16 ARS_OD_YawRateAbsStd_Obj_10_IDT;
typedef uint16 ARS_OD_YawRateAbsStd_Obj_11_IDT;
typedef uint16 ARS_OD_YawRateAbsStd_Obj_12_IDT;
typedef uint16 ARS_OD_YawRateAbsStd_Obj_13_IDT;
typedef uint16 ARS_OD_YawRateAbsStd_Obj_14_IDT;
typedef uint16 ARS_OD_YawRateAbsStd_Obj_15_IDT;
typedef uint16 ARS_OD_YawRateAbsStd_Obj_16_IDT;
typedef uint16 ARS_OD_YawRateAbsStd_Obj_17_IDT;
typedef uint16 ARS_OD_YawRateAbsStd_Obj_18_IDT;
typedef uint16 ARS_OD_YawRateAbsStd_Obj_19_IDT;
typedef uint16 ARS_OD_YawRateAbsStd_Obj_20_IDT;
typedef uint16 ARS_OD_YawRateAbsStd_Obj_21_IDT;
typedef uint16 ARS_OD_YawRateAbsStd_Obj_22_IDT;
typedef uint16 ARS_OD_YawRateAbsStd_Obj_23_IDT;
typedef uint16 ARS_OD_YawRateAbsStd_Obj_24_IDT;
typedef uint16 ARS_OD_YawRateAbsStd_Obj_25_IDT;
typedef uint16 ARS_OD_YawRateAbsStd_Obj_26_IDT;
typedef uint16 ARS_OD_YawRateAbsStd_Obj_27_IDT;
typedef uint16 ARS_OD_YawRateAbsStd_Obj_28_IDT;
typedef uint16 ARS_OD_YawRateAbsStd_Obj_29_IDT;
typedef uint16 ARS_OD_YawRateAbsStd_Obj_30_IDT;
typedef uint16 ARS_OD_YawRateAbsStd_Obj_31_IDT;
typedef uint16 ARS_OD_YawRateAbsStd_Obj_32_IDT;
typedef uint16 ARS_OD_YawRateAbsStd_Obj_33_IDT;
typedef uint16 ARS_OD_YawRateAbsStd_Obj_34_IDT;
typedef uint16 ARS_OD_YawRateAbsStd_Obj_35_IDT;
typedef uint16 ARS_OD_YawRateAbsStd_Obj_36_IDT;
typedef uint16 ARS_OD_YawRateAbsStd_Obj_37_IDT;
typedef uint16 ARS_OD_YawRateAbsStd_Obj_38_IDT;
typedef uint16 ARS_OD_YawRateAbsStd_Obj_39_IDT;
typedef uint16 ARS_OD_YawRateAbsStd_Obj_40_IDT;
typedef uint16 ARS_OD_YawRateAbsStd_Obj_41_IDT;
typedef uint16 ARS_OD_YawRateAbsStd_Obj_42_IDT;
typedef uint16 ARS_OD_YawRateAbsStd_Obj_43_IDT;
typedef uint16 ARS_OD_YawRateAbsStd_Obj_44_IDT;
typedef uint16 ARS_OD_YawRateAbsStd_Obj_45_IDT;
typedef uint16 ARS_OD_YawRateAbsStd_Obj_46_IDT;
typedef uint16 ARS_OD_YawRateAbsStd_Obj_47_IDT;
typedef uint16 ARS_OD_YawRateAbsStd_Obj_48_IDT;
typedef uint16 ARS_OD_YawRateAbsStd_Obj_49_IDT;
typedef uint16 ARS_OD_YawRateAbsStd_Obj_50_IDT;
typedef uint16 ARS_OD_YawRateAbsStd_Obj_51_IDT;
typedef uint16 ARS_OD_YawRateAbsStd_Obj_52_IDT;
typedef uint16 ARS_OD_YawRateAbsStd_Obj_53_IDT;
typedef uint16 ARS_OD_YawRateAbsStd_Obj_54_IDT;
typedef uint16 ARS_OD_YawRateAbsStd_Obj_55_IDT;
typedef uint16 ARS_OD_YawRateAbsStd_Obj_56_IDT;
typedef uint16 ARS_OD_YawRateAbsStd_Obj_57_IDT;
typedef uint16 ARS_OD_YawRateAbsStd_Obj_58_IDT;
typedef uint16 ARS_OD_YawRateAbsStd_Obj_59_IDT;
typedef uint16 ARS_OD_YawRateAbs_Obj_00_IDT;
typedef uint16 ARS_OD_YawRateAbs_Obj_01_IDT;
typedef uint16 ARS_OD_YawRateAbs_Obj_02_IDT;
typedef uint16 ARS_OD_YawRateAbs_Obj_03_IDT;
typedef uint16 ARS_OD_YawRateAbs_Obj_04_IDT;
typedef uint16 ARS_OD_YawRateAbs_Obj_05_IDT;
typedef uint16 ARS_OD_YawRateAbs_Obj_06_IDT;
typedef uint16 ARS_OD_YawRateAbs_Obj_07_IDT;
typedef uint16 ARS_OD_YawRateAbs_Obj_08_IDT;
typedef uint16 ARS_OD_YawRateAbs_Obj_09_IDT;
typedef uint16 ARS_OD_YawRateAbs_Obj_10_IDT;
typedef uint16 ARS_OD_YawRateAbs_Obj_11_IDT;
typedef uint16 ARS_OD_YawRateAbs_Obj_12_IDT;
typedef uint16 ARS_OD_YawRateAbs_Obj_13_IDT;
typedef uint16 ARS_OD_YawRateAbs_Obj_14_IDT;
typedef uint16 ARS_OD_YawRateAbs_Obj_15_IDT;
typedef uint16 ARS_OD_YawRateAbs_Obj_16_IDT;
typedef uint16 ARS_OD_YawRateAbs_Obj_17_IDT;
typedef uint16 ARS_OD_YawRateAbs_Obj_18_IDT;
typedef uint16 ARS_OD_YawRateAbs_Obj_19_IDT;
typedef uint16 ARS_OD_YawRateAbs_Obj_20_IDT;
typedef uint16 ARS_OD_YawRateAbs_Obj_21_IDT;
typedef uint16 ARS_OD_YawRateAbs_Obj_22_IDT;
typedef uint16 ARS_OD_YawRateAbs_Obj_23_IDT;
typedef uint16 ARS_OD_YawRateAbs_Obj_24_IDT;
typedef uint16 ARS_OD_YawRateAbs_Obj_25_IDT;
typedef uint16 ARS_OD_YawRateAbs_Obj_26_IDT;
typedef uint16 ARS_OD_YawRateAbs_Obj_27_IDT;
typedef uint16 ARS_OD_YawRateAbs_Obj_28_IDT;
typedef uint16 ARS_OD_YawRateAbs_Obj_29_IDT;
typedef uint16 ARS_OD_YawRateAbs_Obj_30_IDT;
typedef uint16 ARS_OD_YawRateAbs_Obj_31_IDT;
typedef uint16 ARS_OD_YawRateAbs_Obj_32_IDT;
typedef uint16 ARS_OD_YawRateAbs_Obj_33_IDT;
typedef uint16 ARS_OD_YawRateAbs_Obj_34_IDT;
typedef uint16 ARS_OD_YawRateAbs_Obj_35_IDT;
typedef uint16 ARS_OD_YawRateAbs_Obj_36_IDT;
typedef uint16 ARS_OD_YawRateAbs_Obj_37_IDT;
typedef uint16 ARS_OD_YawRateAbs_Obj_38_IDT;
typedef uint16 ARS_OD_YawRateAbs_Obj_39_IDT;
typedef uint16 ARS_OD_YawRateAbs_Obj_40_IDT;
typedef uint16 ARS_OD_YawRateAbs_Obj_41_IDT;
typedef uint16 ARS_OD_YawRateAbs_Obj_42_IDT;
typedef uint16 ARS_OD_YawRateAbs_Obj_43_IDT;
typedef uint16 ARS_OD_YawRateAbs_Obj_44_IDT;
typedef uint16 ARS_OD_YawRateAbs_Obj_45_IDT;
typedef uint16 ARS_OD_YawRateAbs_Obj_46_IDT;
typedef uint16 ARS_OD_YawRateAbs_Obj_47_IDT;
typedef uint16 ARS_OD_YawRateAbs_Obj_48_IDT;
typedef uint16 ARS_OD_YawRateAbs_Obj_49_IDT;
typedef uint16 ARS_OD_YawRateAbs_Obj_50_IDT;
typedef uint16 ARS_OD_YawRateAbs_Obj_51_IDT;
typedef uint16 ARS_OD_YawRateAbs_Obj_52_IDT;
typedef uint16 ARS_OD_YawRateAbs_Obj_53_IDT;
typedef uint16 ARS_OD_YawRateAbs_Obj_54_IDT;
typedef uint16 ARS_OD_YawRateAbs_Obj_55_IDT;
typedef uint16 ARS_OD_YawRateAbs_Obj_56_IDT;
typedef uint16 ARS_OD_YawRateAbs_Obj_57_IDT;
typedef uint16 ARS_OD_YawRateAbs_Obj_58_IDT;
typedef uint16 ARS_OD_YawRateAbs_Obj_59_IDT;
typedef uint8 ARS_SP_AzimuthCorrection_IDT;
typedef uint16 ARS_SP_CRC16_Checksum_IDT;
typedef uint8 ARS_SP_CalibrationState_IDT;
typedef uint8 ARS_SP_ElevationCorrection_IDT;
typedef uint8 ARS_SP_ErrStateGroup_1_IDT;
typedef uint8 ARS_SP_ErrStateGroup_2_IDT;
typedef uint8 ARS_SP_ErrStateGroup_3_IDT;
typedef uint8 ARS_SP_ErrStateGroup_4_IDT;
typedef uint8 ARS_SP_MsgCounter_IDT;
typedef uint8 ARS_SP_OperationMode_IDT;
typedef uint8 ARS_SP_TunnelFlag_IDT;
typedef uint16 ARS_SP_VisibilityRange_IDT;
typedef uint8 ARS_SP_VisibilityState_IDT;
typedef uint16 ARS_TSYNC_CRC16_Checksum_IDT;
typedef uint16 ARS_TSYNC_LastTimeLeap_IDT;
typedef uint16 ARS_TSYNC_MaxTimeLeap_IDT;
typedef uint8 ARS_TSYNC_MsgCounter_IDT;
typedef uint32 ARS_TSYNC_TimeStampGlobNSec_IDT;
typedef uint32 ARS_TSYNC_TimeStampGlobSec_IDT;
typedef struct
{
    uint16 distance;
    uint8 type;
    uint16 width;
    uint8 peak;
    uint8 counter;
    uint64 time_stamp;
    uint8 reserve;
} ApaDistT;

typedef struct
{
    uint8 ARS_OD_ID;
    float32 ARS_OD_DistX_Obj;
    float32 ARS_OD_DistY_Obj;
    float32 ARS_OD_VabsX_Obj;
    float32 ARS_OD_VabsY_Obj;
    float32 ARS_OD_AabsX_Obj;
    float32 ARS_OD_AabsY_Obj;
    uint8 ARS_OD_DistXStd_Obj;
    uint8 ARS_OD_DistYStd_Obj;
    uint8 ARS_OD_VabsXStd_Obj;
    uint8 ARS_OD_VabsYStd_Obj;
    uint8 ARS_OD_AabsXStd_Obj;
    uint8 ARS_OD_AabsYStd_Obj;
    float32 ARS_OD_RCS_Obj;
    float32 ARS_OD_Length_Obj;
    float32 ARS_OD_Width_Obj;
    float32 ARS_OD_Orientation_Obj;
    float32 ARS_OD_OrientationStd_Obj;
    float32 ARS_OD_YawRateAbs_Obj;
    float32 ARS_OD_YawRateAbsStd_Obj;
    uint8 ARS_OD_RefPoint;
    uint8 ARS_OD_Classification_Obj;
    uint8 ARS_OD_ClassConf_Obj;
    uint8 ARS_OD_DynProp_Obj;
    uint8 ARS_OD_DynConf_Obj;
    uint8 ARS_OD_ProbOfExist_Obj;
    uint8 ARS_OD_MirrorProb_Obj;
    uint8 ARS_OD_ObstacleProb_Obj;
    uint8 ARS_OD_MaintenanceState_Obj;
    uint16 ARS_OD_LifeCycle_Obj;
    uint8 ARS_OD_MicroDopplerFlag;
    float32 DistHeight_Obj;
} ArsObjectInfo;

typedef ArsObjectInfo ArsObjectInfo_60[60];
typedef struct
{
    uint8 gear_status;
    uint8 gear_enable;
    uint8 driver_override;
    uint64 can_time;
    uint64 system_time;
} AutoGearInfo;

typedef uint8 BAS_CtrlActv_IDT;
typedef uint8 BAS_FlgFlt_IDT;
typedef uint8 BCM_ATWS_St_IDT;
typedef uint8 BCM_AmbeLightZone1Sts_IDT;
typedef uint8 BCM_AmbeLightZone2Sts_IDT;
typedef uint8 BCM_AutoWipeSts_IDT;
typedef uint8 BCM_BrakeLightSts_IDT;
typedef uint8 BCM_CodriversSideDoorAjarSts_IDT;
typedef uint8 BCM_CoverAjarStatus_IDT;
typedef uint8 BCM_DayRunningLampSts_IDT;
typedef uint8 BCM_DoorLockStatusCodrivres_IDT;
typedef uint8 BCM_DoorLockStatusDrv_IDT;
typedef uint8 BCM_DoorLockStatusRL_IDT;
typedef uint8 BCM_DoorLockStatusRR_IDT;
typedef uint8 BCM_DriverSideDoorAjarSts_IDT;
typedef uint8 BCM_FFogLampSWSts_IDT;
typedef uint8 BCM_FLWinAntipinchSts_IDT;
typedef uint8 BCM_FLWin_Postion_IDT;
typedef uint8 BCM_FRWinAntipinchSts_IDT;
typedef uint8 BCM_FRWin_Postion_IDT;
typedef uint8 BCM_Fr_domelampSts_IDT;
typedef uint8 BCM_FrontFogLampLightSts_IDT;
typedef uint8 BCM_FrontWinWashSWSts_IDT;
typedef uint8 BCM_FrontWipeReturn_IDT;
typedef uint8 BCM_FrontWipeSWSts_IDT;
typedef uint8 BCM_FrontWipeSts_IDT;
typedef uint8 BCM_HeadLight_adjustSts_IDT;
typedef uint8 BCM_HighBeamSWSts_IDT;
typedef uint8 BCM_HighBeamSts_IDT;
typedef uint8 BCM_LicensePlateLightSts_IDT;
typedef uint8 BCM_LowBeamSWSts_IDT;
typedef uint8 BCM_LowBeamSts_IDT;
typedef uint8 BCM_PosLmpSts_IDT;
typedef uint8 BCM_RFogLampSWSts_IDT;
typedef uint8 BCM_RLWinAntipinchSts_IDT;
typedef uint8 BCM_RLWinIN_Postion_IDT;
typedef uint8 BCM_RMarkerLightSts_IDT;
typedef uint8 BCM_RRWinAntipinchSts_IDT;
typedef uint8 BCM_RRWin_Postion_IDT;
typedef uint8 BCM_RearFogLampLightSts_IDT;
typedef uint8 BCM_RearLeftDoorAjarStatus_IDT;
typedef uint8 BCM_RearRightDoorAjarStatus_IDT;
typedef uint8 BCM_RearWinWashSWSts_IDT;
typedef uint8 BCM_RearWipeReturn_IDT;
typedef uint8 BCM_RearWipeSWSts_IDT;
typedef uint8 BCM_RearWipeSts_IDT;
typedef uint8 BCM_ReverseLightSts_IDT;
typedef uint8 BCM_Rr_domelampSts_IDT;
typedef uint8 BCM_STAT_HazardWarn_IDT;
typedef uint8 BCM_STAT_Horn_IDT;
typedef uint8 BCM_STAT_InteriorLight_IDT;
typedef uint8 BCM_STAT_SwLightBrightness_IDT;
typedef uint8 BCM_TailGateSts_IDT;
typedef uint8 BCM_Tail_MicroSW_IDT;
typedef uint8 BCM_TrunckAjarStatus_IDT;
typedef uint8 BCM_TurnIndicatorSts_IDT;
typedef uint8 BCM_TurnLightSWSts_IDT;
typedef uint8 BCM_TurnLight_FaultSts_IDT;
typedef uint8 BCM_WPC_Off_Req_IDT;
typedef uint8 BCM_WinLockSts_IDT;
typedef uint8 BSD_LCA_FuncSWReq_IDT;
typedef uint8 BSD_LCA_FuncSts_IDT;
typedef uint8 BSD_LCA_FuncSwtResp_IDT;
typedef uint8 BSD_LCA_WarningReqLeft_IDT;
typedef uint8 BSD_LCA_WarningReqRight_IDT;
typedef struct
{
    uint8 turn_light_status;
    uint8 brake_light_status;
    uint8 high_beam;
    uint8 low_beam;
    uint8 wiper;
    uint8 door_driver;
    uint8 door_passenger;
    uint8 door_left_rear;
    uint8 door_right_rear;
    uint8 hood;
    uint8 trunk;
    uint8 passenger_detect;
    uint8 driver_seat_belt;
    uint8 passenger_seat_belt;
    float32 temperature;
    uint64 can_time;
    uint64 system_time;
} BodyInfo;

typedef struct
{
    float32 x;
    float32 y;
    float32 width;
    float32 height;
} BoxRect;

typedef struct
{
    uint8 brake_enable;
    uint8 brake_prefill;
    uint8 brake_system_mode;
    float32 brake_command;
    uint8 dec_to_stop_flag;
    uint8 brake_control_mode;
} BrakeCommand;

typedef struct
{
    uint8 braking_status;
    float32 brake_pedal_output;
    float32 master_cylinder_pressure;
    uint8 brake_control_available;
    uint8 brake_error;
    uint8 brake_enable;
    uint8 driver_override;
    uint8 abs_enable;
    uint8 abs_active;
    uint64 can_time;
    uint64 system_time;
} BrakeInfo;

typedef uint8 CCU_AC_Req_IDT;
typedef uint8 CCU_AC_Sts_IDT;
typedef uint8 CCU_AUTO_Status_IDT;
typedef uint8 CCU_Anion_Generator_Sts_IDT;
typedef uint8 CCU_Circulation_Sts_IDT;
typedef uint16 CCU_CompSpdMEAS_Comp_IDT;
typedef uint8 CCU_ExternalTemperatureFailSts_IDT;
typedef uint8 CCU_ExternalTemperature_IDT;
typedef uint8 CCU_FrontDefrostSts_IDT;
typedef uint8 CCU_InteriorTemp;
typedef uint8 CCU_Onoff_Sts_IDT;
typedef uint8 CCU_PTCPwr_Req_IDT;
typedef uint8 CCU_PTC_Req_IDT;
typedef uint8 CCU_PTCgear_Req_Reserve_IDT;
typedef uint8 CCU_Temp_Sync_Sts_IDT;
typedef uint8 CCU_evaporator_Temperature_IDT;
typedef struct
{
    uint8 calib_status;
    float32 yaw;
    float32 pitch;
    float32 roll;
    float32 camera_x;
    float32 camera_y;
    float32 camera_z;
} Camera_Calib_Results;

typedef struct
{
    uint32 sensor_ID;
} Camera_Intrinsic_Params;

typedef struct
{
    uint8 steer_enable;
    uint8 steer_system_mode;
    uint8 steer_clear;
    float32 steering_command;
    float32 steering_speed_command;
} SteerCommand;

typedef struct
{
    uint8 throttle_enable;
    uint8 throttle_ignore;
    uint8 throttle_system_mode;
    float32 throttle_command;
    float32 target_acce;
} ThrottleCommand;

typedef struct
{
    uint8 gear_enable;
    uint8 gear_ignore;
    uint8 gear_clear;
    uint8 gear_command;
} GearCommand;

typedef struct
{
    uint8 epb_enable;
    uint8 epb_command;
} EPBCommand;

typedef struct
{
    uint64 time_stamp;
    uint64 time_stamp_can;
    SteerCommand steering_command;
    BrakeCommand braking_command;
    ThrottleCommand throttle_command;
    GearCommand gear_command;
    EPBCommand epb_command;
} CarControlCommandH;

typedef struct
{
    uint64 time_stamp;
    uint64 time_stamp_can;
    uint8 bcm_enable;
    uint8 turn_light_command;
    uint8 high_beam_command;
    uint8 dipped_beam_command;
    uint8 emergency_light_command;
    uint8 front_fog_lamp_command;
    uint8 rear_fog_lamp_command;
    uint8 brake_light_command;
    uint8 horn_command;
    uint8 front_wind_shield_wiper;
    uint8 rear_wind_shield_wiper;
} CarControlCommandL;

typedef struct
{
    float32 steering_angle;
    uint8 steering_enable;
    float32 steering_column_torque;
    uint8 driver_override;
    uint8 steering_control_available;
    float32 steering_angle_speed;
    uint64 can_time;
    uint64 system_time;
} SteeringInfo;

typedef struct
{
    float32 wheel_speed_rear_right;
    float32 wheel_speed_rear_left;
    float32 wheel_speed_front_right;
    float32 wheel_speed_front_left;
    uint8 wheel_speed_rear_right_dir;
    uint8 wheel_speed_rear_left_dir;
    uint8 wheel_speed_front_right_dir;
    uint8 wheel_speed_front_left_dir;
    sint16 wheel_position_rear_right;
    sint16 wheel_position_rear_left;
    sint16 wheel_position_front_right;
    sint16 wheel_position_front_left;
    float32 vehicle_speed;
    uint8 vehicle_stand_still;
    float32 longitude_acce;
    uint8 longitude_acce_valid;
    float32 lateral_acce;
    uint8 lateral_acce_valid;
    float32 roll_rate;
    float32 yaw_rate;
    uint64 can_time;
    uint64 system_time;
} VehicleSpeedInfo;

typedef struct
{
    float32 throttle_pedal_output;
    float32 torque_output_fr;
    float32 torque_output_rr;
    uint8 throttle_enable;
    uint8 driver_override;
    uint8 throttle_error;
    uint8 throttle_control_available;
    uint64 can_time;
    uint64 system_time;
} ThrottleInfo;

typedef struct
{
    uint8 epb_status;
    uint8 driver_override;
    uint8 epb_enable;
    uint64 can_time;
    uint64 system_time;
} EPBInfo;

typedef struct
{
    uint64 time_stamp;
    uint64 time_stamp_can;
    SteeringInfo steering;
    BrakeInfo brake;
    VehicleSpeedInfo vehicle_speed;
    ThrottleInfo throttle;
    AutoGearInfo gear;
    EPBInfo epb;
} CarInfoH;

typedef struct
{
    uint16 front_left_pressure;
    uint16 front_right_pressure;
    uint16 rear_left_pressure;
    uint16 rear_right_pressure;
    uint8 front_left_pressure_alarm;
    uint8 front_right_pressure_alarm;
    uint8 rear_left_pressure_alarm;
    uint8 rear_right_pressure_alarm;
} TirePressureInfo;

typedef struct
{
    uint64 time_stamp;
    uint64 time_stamp_can;
    BodyInfo body_info;
    TirePressureInfo tire_pressure;
} CarInfoL;

typedef struct
{
    float32 x;
    float32 y;
    uint8 class_type;
    uint8 edge;
    uint16 id;
    float32 vehicle_x;
    float32 vehicle_y;
    float32 vehicle_heading;
} Cc_Point2f;

typedef uint8 CheckSum_0x106_IDT;
typedef uint8 CheckSum_0x109_IDT;
typedef uint8 CheckSum_0x17F_IDT;
typedef uint8 CheckSum_0x3F1_IDT;
typedef uint8 CheckSum_0x3F5_IDT;
typedef uint8 CheckSum_0x3F7_IDT;
typedef uint8 CheckSum_1F8_IDT;
typedef uint8 Checksum_0x132_IDT;
typedef uint8 Checksum_0x17E_IDT;
typedef uint8 Checksum_0x3E2_IDT;
typedef uint8 Checksum_230_IDT;
typedef struct
{
    uint64 time_stamp;
    uint8 system_command;
    uint8 emergency_brake;
    uint8 reset_system;
} Command;

typedef const void* ConstVoidPtr;
typedef uint8 DOW_FuncSWReq_IDT;
typedef uint8 DOW_FuncSts_IDT;
typedef uint8 DOW_FuncSwtResp_IDT;
typedef uint8 DOW_WarningReqLeft_IDT;
typedef uint8 DOW_WarningReqRight_IDT;
// typedef uint8 Dcm_DidSupportedType;
typedef uint8 Dem_MaxDataValueType[32];
typedef uint8 Dem_MonitorStatusType;
typedef uint8 Dem_PID21valueType[2];
typedef uint8 Dem_PID31valueType;
typedef struct
{
    uint64 time_stamp;
    float32 x;
    float32 y;
    float32 heading;
} LocationPoint;

typedef float32 rt_Array_float32_200[200];
typedef struct
{
    rt_Array_float32_200 x;
    rt_Array_float32_200 y;
    rt_Array_float32_200 heading;
    rt_Array_float32_200 curve;
    rt_Array_float32_200 acc;
    rt_Array_float32_200 speed;
    uint8 gear;
    uint8 points_cnt;
} Trajectory;

typedef struct
{
    uint64 time_stamp;
    uint64 time_stamp_fusion;
    uint8 replan_counter;
    uint8 trajectories_cnt;
    float32 step_length;
    LocationPoint freeze_coordinate;
    Trajectory trajectories;
    uint8 plan_ok;
} DesiredTrajectoryGeneral;

typedef uint8 DistHeight_Obj_00_IDT;
typedef uint8 DistHeight_Obj_01_IDT;
typedef uint8 DistHeight_Obj_02_IDT;
typedef uint8 DistHeight_Obj_03_IDT;
typedef uint8 DistHeight_Obj_04_IDT;
typedef uint8 DistHeight_Obj_05_IDT;
typedef uint8 DistHeight_Obj_06_IDT;
typedef uint8 DistHeight_Obj_07_IDT;
typedef uint8 DistHeight_Obj_08_IDT;
typedef uint8 DistHeight_Obj_09_IDT;
typedef uint8 DistHeight_Obj_10_IDT;
typedef uint8 DistHeight_Obj_11_IDT;
typedef uint8 DistHeight_Obj_12_IDT;
typedef uint8 DistHeight_Obj_13_IDT;
typedef uint8 DistHeight_Obj_14_IDT;
typedef uint8 DistHeight_Obj_15_IDT;
typedef uint8 DistHeight_Obj_16_IDT;
typedef uint8 DistHeight_Obj_17_IDT;
typedef uint8 DistHeight_Obj_18_IDT;
typedef uint8 DistHeight_Obj_19_IDT;
typedef uint8 DistHeight_Obj_20_IDT;
typedef uint8 DistHeight_Obj_21_IDT;
typedef uint8 DistHeight_Obj_22_IDT;
typedef uint8 DistHeight_Obj_23_IDT;
typedef uint8 DistHeight_Obj_24_IDT;
typedef uint8 DistHeight_Obj_25_IDT;
typedef uint8 DistHeight_Obj_26_IDT;
typedef uint8 DistHeight_Obj_27_IDT;
typedef uint8 DistHeight_Obj_28_IDT;
typedef uint8 DistHeight_Obj_29_IDT;
typedef uint8 DistHeight_Obj_30_IDT;
typedef uint8 DistHeight_Obj_31_IDT;
typedef uint8 DistHeight_Obj_32_IDT;
typedef uint8 DistHeight_Obj_33_IDT;
typedef uint8 DistHeight_Obj_34_IDT;
typedef uint8 DistHeight_Obj_35_IDT;
typedef uint8 DistHeight_Obj_36_IDT;
typedef uint8 DistHeight_Obj_37_IDT;
typedef uint8 DistHeight_Obj_38_IDT;
typedef uint8 DistHeight_Obj_39_IDT;
typedef uint8 DistHeight_Obj_40_IDT;
typedef uint8 DistHeight_Obj_41_IDT;
typedef uint16 EDS_Spd_FR;
typedef uint16 EDS_Spd_RR;
typedef uint16 EDS_output_trq_FR;
typedef uint16 EDS_output_trq_RR;
typedef uint8 EPB_AVHFeedbackSts_IDT;
typedef uint8 EPB_AVHStatIndReqV_IDT;
typedef uint8 EPB_AVHStatIndReq_IDT;
typedef uint8 EPB_AVHWrnIndReqV_IDT;
typedef uint8 EPB_AVHWrnIndReq_IDT;
typedef uint8 EPB_Sts_IDT;
typedef uint8 EPB_SysBrkLtsReq_IDT;
typedef uint8 EPB_SysDspMsgReqV_IDT;
typedef uint8 EPB_SysDspMsgReq_IDT;
typedef uint8 EPB_SysStatIndReqV_IDT;
typedef uint8 EPB_SysStatIndReq_IDT;
typedef uint8 EPB_SysWrnIndReqV_IDT;
typedef uint8 EPB_SysWrnIndReq_IDT;
typedef uint8 EPS_ADAS_CtrlAbortFeedback_IDT;
typedef uint8 EPS_ADAS_ModActv_IDT;
typedef uint8 EPS_ADAS_ModAvail_IDT;
typedef uint8 EPS_APA_CtrlAbortFeedback_IDT;
typedef uint8 EPS_APA_ModActv_IDT;
typedef uint8 EPS_APA_ModAvail_IDT;
typedef uint8 EPS_DrStrTorqV_IDT;
typedef uint8 EPS_DrStrTorqVal_IDT;
typedef uint16 EPS_LKARespTorq_IDT;
typedef uint16 EPS_SteeringEMTorque;
typedef uint16 EPS_SteeringTorque;
typedef uint8 EPS_SterFltMod_IDT;
typedef uint8 EPS_SterModV_IDT;
typedef uint8 EPS_SterMod_IDT;
typedef uint8 ESC_EscCtrlActv_IDT;
typedef uint8 ESC_EscDisableSts_IDT;
typedef uint8 ESC_EscFlgFlt_IDT;
typedef uint8 ESC_HBAFlgFlt_IDT;
typedef uint8 ESC_HSA_Control_Status_IDT;
typedef uint8 ESC_HSA_Status_Fault_IDT;
typedef uint8 ESC_HbaCtrlActv_IDT;
typedef uint16 ESC_LateralACC_IDT;
typedef uint8 ESC_LateralACC_Valid_IDT;
typedef uint16 ESC_LongitudeACC_IDT;
typedef uint8 ESC_LongitudeACC_Valid_IDT;
typedef uint8 ESC_MasterCylinderPressureV_IDT;
typedef uint16 ESC_MasterCylinderPressure_IDT;
typedef uint8 ESC_SlopeGradeAngle_IDT;
typedef uint8 ESC_TcsCtrlActv_IDT;
typedef uint8 ESC_TcsDisableSts_IDT;
typedef uint8 ESC_TcsFlgFlt_IDT;
typedef uint16 ESC_VehDynYawRate_IDT;
typedef uint8 ESC_VehDynYawRate_Valid_IDT;
typedef uint8 FC_BlockageSts_IDT;
typedef uint8 FC_CalibrationSts_IDT;
typedef uint8 FLC_ExtenedDistance_IDT;
typedef uint8 FLM_ExtenedDistance_IDT;
typedef uint16 FLS_ExtenedDistance_IDT;
typedef uint8 FRC_ExtenedDistance_IDT;
typedef uint8 FRM_ExtenedDistance_IDT;
typedef uint16 FRS_ExtenedDistance_IDT;
typedef float32 Float;
typedef Cc_Point2f vehicle_points_400[400];
typedef struct
{
    uint16 point_num;
    uint8 closed_contour;
    vehicle_points_400 vehicle_points;
    uint8 color_type;
    uint8 class_type;
} FreespaceInfo;

typedef struct
{
    uint64 time_stamp;
    uint64 time_stamp_camera;
    uint32 frame_index;
    uint8 info_cnt;
    FreespaceInfo freespace_set;
} FreespaceSet;

typedef struct
{
    uint64 ARS_OD_TimeStampGlobSec;
    uint64 ARS_OD_TimeStampGlobNanoSec;
    uint64 ARS_OD_TimeStampLocal;
    uint16 ARS_OD_Latency;
    uint16 ARS_OD_MeasCounter;
    uint8 ARS_OD_CycleCounter;
    uint8 ARS_OD_NumOfObjects;
    uint8 ARS_OD_TaskValidFlag;
    uint8 ARS_OD_ExtendedCycleFlag;
    uint8 ARS_OD_MsgCounter_Header;
    uint16 ARS_OD_CRC16_Checksum_Header;
} RadarHeader;

typedef struct
{
    RadarHeader header;
    uint64 timestamp;
    ArsObjectInfo_60 objects;
} FrontRadarInfo;

typedef struct
{
    uint64 time_stamp;
    uint8 NumObstacles_ub;
    uint8 cipv_id_ub;
    uint8 cipv_lost_ub;
    uint8 allow_acc_ub;
    uint8 vd_niv_left_ub;
    uint8 vd_niv_right_ub;
} Fusion_Header_ST;

typedef struct
{
    uint64 time_stamp;
    uint8 ObstacleID_ub;
    uint8 ObstacleValid_ub;
    uint8 ObstacleSource_ub;
    uint8 ObstacleConfidence_ub;
    uint8 ObstacleMotionCategory_ub;
    uint8 ObstacleMotionStatus_ub;
    uint8 ObstacleMeasuringStatus_ub;
    uint8 ObstacleClass_ub;
    uint8 ObstacleLaneAssignment_ub;
    uint8 CIPVFlag_ub;
    uint8 MCPFlag_ub;
    uint8 ObstacleBlinkerInfo_ub;
    uint8 ObstacleBrakeLights_ub;
    uint8 ObstacleTrackingConfidence_ub;
    uint8 CutInFlag_ub;
    float32 ObstacleLength_f;
    float32 ObstacleWidth_f;
    float32 ObstacleHeight_f;
    float32 ObstacleAge_f;
    float32 Obstacle_TTC_f;
    float32 ObstaclePosX_f;
    float32 ObstaclePosY_f;
    float32 ObstacleVelXRel_f;
    float32 ObstacleVelYRel_f;
    float32 ObstacleAccX_f;
    float32 ObstaclePosXSTD_f;
    float32 ObstaclePosYSTD_f;
    float32 ObstacleVelXSTD_f;
    float32 ObstacleVelYSTD_f;
    float32 ObstacleAccY_f;
    float32 ObstacleAngle_f;
    float32 ObstacleAngleStd_f;
    float32 ObstacleVelXAbs_f;
    float32 ObstacleVelYAbs_f;
    float32 CutInDistance_f;
    float32 ObjCornerPointPoxX_f;
    float32 ObjCornerPointPoxY_f;
} Fusion_Object_ST;

typedef struct
{
    uint64 time_stamp;
    uint8 Fus_ObjMainStatus_ub;
    uint8 Fus_TsrMainStatus_ub;
    uint8 Reversed;
} Fusion_Status;

typedef uint8 GPSSystAtv_IDT;
typedef uint16 GW_ACU_CRC16_Checksum_IDT;
typedef uint16 GW_ACU_LateralAcceleration_IDT;
typedef uint8 GW_ACU_LateralAcceleration_Valid_IDT;
typedef uint8 GW_ACU_LongiAccel_ValidFl_IDT;
typedef uint16 GW_ACU_LongitudinalAcceleration_IDT;
typedef uint8 GW_ACU_MsgCounter_IDT;
typedef uint16 GW_ACU_YawRate_IDT;
typedef uint8 GW_ACU_YawRate_ValidFlag_IDT;
typedef uint8 GW_ESC_ABS_ActiveFlag_IDT;
typedef uint8 GW_ESC_ABS_ValidFlag_IDT;
typedef uint16 GW_ESC_CRC16_Checksum_IDT;
typedef uint8 GW_ESC_EPB_ActiveFlag_IDT;
typedef uint8 GW_ESC_EPB_ValidFlag_IDT;
typedef uint8 GW_ESC_MsgCounter_IDT;
typedef uint8 GW_ESC_TCS_ActiveFlag_IDT;
typedef uint8 GW_ESC_TCS_ValidFlag_IDT;
typedef uint16 GW_ESC_VehicleSpeed_IDT;
typedef uint8 GW_ESC_VehicleSpeed_ValidFlag_IDT;
typedef uint8 GW_ESC_WheelDirection_FL_IDT;
typedef uint8 GW_ESC_WheelDirection_FL_ValidFl_IDT;
typedef uint8 GW_ESC_WheelDirection_FR_IDT;
typedef uint8 GW_ESC_WheelDirection_FR_ValidFl_IDT;
typedef uint8 GW_ESC_WheelDirection_RL_IDT;
typedef uint8 GW_ESC_WheelDirection_RL_ValidFl_IDT;
typedef uint8 GW_ESC_WheelDirection_RR_IDT;
typedef uint8 GW_ESC_WheelDirection_RR_ValidFl_IDT;
typedef uint16 GW_ESC_WheelSpeed_FL_IDT;
typedef uint8 GW_ESC_WheelSpeed_FL_ValidFlag_IDT;
typedef uint16 GW_ESC_WheelSpeed_FR_IDT;
typedef uint8 GW_ESC_WheelSpeed_FR_ValidFlag_IDT;
typedef uint16 GW_ESC_WheelSpeed_RL_IDT;
typedef uint8 GW_ESC_WheelSpeed_RL_ValidFlag_IDT;
typedef uint16 GW_ESC_WheelSpeed_RR_IDT;
typedef uint8 GW_ESC_WheelSpeed_RR_ValidFlag_IDT;
typedef uint32 GW_IDCM_VehicleTotalMileage_IDT;
typedef uint16 GW_SAS_CRC16_Checksum_IDT;
typedef uint8 GW_SAS_MsgCounter_IDT;
typedef uint16 GW_SAS_SteeringWheelAngle_IDT;
typedef uint8 GW_SAS_SteeringWheelAngle_ValidF_IDT;
typedef uint16 GW_SENCFG_CRC16_Checksum_IDT;
typedef uint8 GW_SENCFG_ID_IDT;
typedef uint8 GW_SENCFG_MsgCounter_IDT;
typedef uint8 GW_TBOX_AbsoluteTime_Day_IDT;
typedef uint8 GW_TBOX_AbsoluteTime_Hour_IDT;
typedef uint8 GW_TBOX_AbsoluteTime_Minute_IDT;
typedef uint8 GW_TBOX_AbsoluteTime_Month_IDT;
typedef uint8 GW_TBOX_AbsoluteTime_Second_IDT;
typedef uint8 GW_TBOX_AbsoluteTime_Year_IDT;
typedef uint16 GW_TM_CRC16_Checksum_IDT;
typedef uint8 GW_TM_GearPosition_IDT;
typedef uint8 GW_TM_GearPosition_ValidFlag_IDT;
typedef uint8 GW_TM_MsgCounter_IDT;
typedef struct
{
    uint64 time_stamp;
    uint64 time_stamp_can;
    float32 x;
    float32 y;
    float32 z;
    float32 heading;
    float32 pitch;
    float32 roll;
} GlobalPoseEstimation;

typedef GlobalPoseEstimation global_pose_10[12];
typedef struct
{
    uint8 counter;
    global_pose_10 global_pose;
} GlobalPoseBuffer;

typedef struct
{
    uint64 time_stamp;
    uint64 time_stamp_guideline;
    Float a;
    Float b;
    Float c;
    Float d;
    Float min;
    Float max;
    Float residue_dis;
} GuideLine;

typedef uint8 IBS_ESCOFF_StsFB_IDT;
typedef uint16 IDB_Brake_Pedal_position;
typedef struct
{
    uint64 time_stamp;
    uint64 time_stamp_ins;
    float32 acce_x;
    float32 acce_y;
    float32 acce_z;
    float32 gyro_x;
    float32 gyro_y;
    float32 gyro_z;
    float32 heading;
    float32 pitch;
    float32 roll;
    float32 imu_temperature;
} IMUInfo;

typedef uint8 IPC_IPCTotalOdometerV_IDT;
typedef uint32 IPC_IPCTotalOdometer_IDT;
typedef uint16 IPC_Remain_Maintenance_IDT;
typedef uint8 MCPressure;
typedef uint8 MFS_ACC_CruiseCancel_IDT;
typedef uint8 MFS_ACC_CruiseGapSet_IDT;
typedef uint8 MFS_ACC_CruiseOn_Off_IDT;
typedef uint8 MFS_ACC_CruiseSpdDecrease_IDT;
typedef uint8 MFS_ACC_CruiseSpdIncrease_IDT;
typedef uint8 MFS_L1_Central_Control_IDT;
typedef uint8 MFS_L1_DownControl_IDT;
typedef uint8 MFS_L1_Failure_IDT;
typedef uint8 MFS_L1_LeftControl_IDT;
typedef uint8 MFS_L1_RightControl_IDT;
typedef uint8 MFS_L1_UpControl_IDT;
typedef uint8 MFS_L2_Failure_IDT;
typedef uint8 MHU_APA_ParkIn_Req_IDT;
typedef uint8 MHU_APA_ParkOut_Direction_IDT;
typedef uint8 MHU_APA_ParkOut_Mode_IDT;
typedef uint8 MHU_APA_ParkOut_Req_IDT;
typedef uint8 MHU_APA_ParkingReCover_Req_IDT;
typedef uint8 MHU_APA_ParkingSpace_ID_IDT;
typedef uint8 MHU_APA_ParkingStart_Req_IDT;
typedef uint8 MHU_APA_Req_IDT;
typedef uint8 MHU_AVH_Req_IDT;
typedef uint8 MHU_DM_SwitchModeSts_IDT;
typedef uint8 MHU_ESCOFF_SW_Sts_IDT;
typedef uint8 MHU_LSS_Mode_IDT;
typedef uint8 MHU_LSS_Req_IDT;
typedef uint8 MHU_LSS_WarningMethod_IDT;
typedef uint8 MHU_RegencyLevRequest_IDT;
typedef uint8 MHU_STAT_AmbientTemp;
typedef uint8 MHU_TSR_Req_IDT;
typedef uint8 MHU_Trailermode_Req_IDT;
typedef uint8 MHU_UPAMuteSwitch_IDT;
typedef uint8 MHU_VCU_CreepDisable_stt_IDT;
typedef uint16 MainCylinderPres;
typedef uint8 Nav_CtryType_IDT;
typedef uint8 Nav_RoadType_IDT;
typedef uint8 Nav_SpdLimType_IDT;
typedef uint8 Nav_SpdLimUnit_IDT;
typedef uint8 Nav_SpdLimValue_IDT;
typedef uint8 Nav_TSRTrafSign_IDT;
typedef uint8 Nav_TimeIndcn_IDT;
typedef uint8 Nav_TimeMod_IDT;
typedef uint16 Nav_VehToTrafEyeDist_IDT;
typedef uint8 Nav_errorSts_IDT;
typedef struct
{
    float32 distance_x;
    float32 distance_y;
    uint16 tracking_id;
    uint8 class_id;
    uint8 angle_view;
    uint8 confidence;
    float32 width;
    float32 height;
    float32 length;
    float32 yaw;
    float32 relative_velocity_x;
    float32 relative_velocity_y;
    float32 relative_acceleration_x;
    float32 relative_acceleration_y;
    uint8 motion_status;
    uint16 valid_status;
    uint8 target_source;
} ObjectInfo;

typedef ObjectInfo object_set_64[64];
typedef struct
{
    uint64 time_stamp;
    uint64 time_stamp_raw;
    uint32 frame_index;
    uint8 object_cnt;
    object_set_64 object_set;
} ObjectSet;

typedef uint8 PEPS_IGN1RelaySts_IDT;
typedef uint8 PEPS_IGN1RelayValidity_IDT;
typedef uint8 PEPS_Learning_Status_IDT;
typedef uint8 PEPS_Message_Sts_AliveCounter_IDT;
typedef uint8 PEPS_Message_Sts_CheckSum_IDT;
typedef uint8 PEPS_PowerModeValidity_IDT;
typedef uint8 PEPS_PowerMode_IDT;
typedef uint8 PEPS_RemoteControlSt_IDT;
typedef struct
{
    float32 x;
    float32 y;
    float32 heading;
} ParkingSlotError;

typedef struct
{
    uint8 flc_info;
    uint8 flm_info;
    uint8 frm_info;
    uint8 frc_info;
    uint8 rlc_info;
    uint8 rlm_info;
    uint8 rrm_info;
    uint8 rrc_info;
    uint8 fls_info;
    uint8 frs_info;
    uint8 rls_info;
    uint8 rrs_info;
} PdcAlertInfo;

typedef struct
{
    uint16 flc_distance;
    uint16 flm_distance;
    uint16 frm_distance;
    uint16 frc_distance;
    uint16 rlc_distance;
    uint16 rlm_distance;
    uint16 rrm_distance;
    uint16 rrc_distance;
    uint16 fls_distance;
    uint16 frs_distance;
    uint16 rls_distance;
    uint16 rrs_distance;
} PdcDistInfo;

typedef struct
{
    uint16 flc_distance_left;
    uint16 flc_distance_right;
    uint16 flm_distance_left;
    uint16 flm_distance_right;
    uint16 frm_distance_left;
    uint16 frm_distance_right;
    uint16 frc_distance_left;
    uint16 frc_distance_right;
    uint16 rlc_distance_left;
    uint16 rlc_distance_right;
    uint16 rlm_distance_left;
    uint16 rlm_distance_right;
    uint16 rrm_distance_left;
    uint16 rrm_distance_right;
    uint16 rrc_distance_left;
    uint16 rrc_distance_right;
    uint16 fls_distance;
    uint16 frs_distance;
    uint16 rls_distance;
    uint16 rrs_distance;
} PdcDistInfoAvm;

typedef struct
{
    uint8 ls_info;
    uint8 rs_info;
    uint8 ls_distance;
    uint8 rs_distance;
} PdcSideInfo;

typedef PdcSideInfo PdcSideInfo_3[3];
typedef struct
{
    uint64 time_stamp;
    uint8 enable_parking_slot_detection;
    uint8 enable_object_detection;
    uint8 enable_freespace_detection;
    uint8 enable_uss;
    uint8 enable_radar;
    uint8 enable_lidar;
    uint8 system_command;
    uint8 system_reset;
} PerceptionCommand;

typedef struct
{
    sint32 camera_position;
    sint64 timestamp;
    sint8 blockage_status;
    sint8 weather_status;
    sint8 illumination_status;
    sint8 image_limited_status;
    boolean out_of_focus;
    sint32 impacted_technologies;
} PerceptionFailsafe;

typedef PerceptionFailsafe PerceptionFailsafe_12[12];
typedef struct
{
    sint32 track_id;
    sint32 age;
    float32 exist_probability;
    uint8 quality;
    sint64 prediction_type;
    sint64 prediction_source;
    uint8 color;
    float32 color_confidence;
    uint8 lanemark_type;
    float32 lanemark_type_confidence;
    uint8 dlm_type;
    uint8 role;
    float32 marker_width;
    float32 marker_width_std;
    float32 line_c3;
    float32 line_c2;
    float32 line_c1;
    float32 line_c0;
    float32 view_range_start;
    float32 view_range_end;
    float32 measured_view_range_end;
    uint8 camera_position;
    boolean is_valid;
} PerceptionLaneAdjacent;

typedef PerceptionLaneAdjacent PerceptionLaneAdjacent_4[4];
typedef struct
{
    sint64 timestamp;
    sint32 track_id;
    sint32 age;
    float32 exist_probability;
    uint8 quality;
    sint64 prediction_source;
    sint64 prediction_type;
    uint8 color;
    float32 color_confidence;
    uint8 lanemark_type;
    float32 lanemark_type_confidence;
    uint8 dlm_type;
    uint8 decel_type;
    uint8 side;
    boolean crossing;
    float32 marker_width;
    float32 marker_width_std;
    float32 dash_average_length;
    float32 dash_average_gap;
    boolean is_multi_clothoid;
    float32 first_line_c0;
    float32 first_line_c1;
    float32 first_line_c2;
    float32 first_line_c3;
    float32 first_view_range_start;
    float32 first_view_range_end;
    float32 first_measured_view_range_end;
    float32 second_line_c0;
    float32 second_line_c1;
    float32 second_line_c2;
    float32 second_line_c3;
    float32 second_view_range_start;
    float32 second_view_range_end;
    float32 second_measured_view_range_end;
    uint8 camera_position;
    boolean is_valid;
} PerceptionLaneHost;

typedef PerceptionLaneHost PerceptionLaneHost_2[2];
typedef struct
{
    uint64 timestamp;
    uint64 frame_index;
    sint8 camera_position;
    uint8 id;
    sint8 class;
    sint8 subclass;
    float32 confidence;
    BoxRect bbox;
    float32 length;
    float32 length_std;
    float32 width;
    float32 width_std;
    float32 height;
    float32 height_std;
    sint8 age_count;
    float32 age_seconds;
    sint8 visibility_side;
    float32 heading;
    float32 heading_std;
    float32 inverse_ttc;
    float32 inverse_ttc_std;
    float32 angle_left;
    float32 angle_right;
    float32 angle_side;
    float32 angle_rate;
    sint8 top_out_of_image;
    sint8 bottom_out_of_image;
    sint8 left_out_of_image;
    sint8 right_out_of_image;
    sint8 brake_light;
    sint8 turn_indicator_left;
    sint8 turn_indicator_right;
    sint8 measuring_status_0;
    sint8 measuring_status_1;
    sint8 measuring_status_2;
    sint8 motion_orientation;
    sint8 motion_category;
    sint8 motion_status;
    sint8 cutin_cutout;
    float32 lat_distance;
    float32 lat_distance_std;
    float32 long_distance;
    float32 long_distance_std;
    float32 relative_lat_velocity;
    float32 relative_lat_velocity_std;
    float32 relative_long_velocity;
    float32 relative_long_velocity_std;
    float32 abs_lat_velocity;
    float32 abs_lat_velocity_std;
    float32 abs_long_velocity;
    float32 abs_long_velocity_std;
    float32 relative_lat_acc;
    float32 relative_lat_acc_std;
    float32 relative_long_acc;
    float32 relative_long_acc_std;
    float32 abs_lat_acc;
    float32 abs_lat_acc_std;
    float32 abs_long_acc;
    float32 abs_long_acc_std;
    float32 abs_speed;
    float32 abs_speed_std;
    float32 abs_acceleration;
    float32 abs_acceleration_std;
} PerceptionOutObject;

typedef PerceptionOutObject PerceptionOutObject_32[32];
typedef struct
{
    float32 exist_probability;
    float32 height;
    float32 height_std;
    float32 line_c3;
    float32 line_c2;
    float32 line_c1;
    float32 line_c0;
    float32 view_range_start;
    float32 view_range_end;
    float32 measured_view_range_end;
    uint8 camera_position;
} PerceptionRoadEdge;

typedef PerceptionRoadEdge PerceptionRoadEdge_2[2];
typedef struct
{
    BoxRect bbox;
    float32 height;
    float32 width;
    float32 lat_distance;
    float32 lat_distance_std;
    float32 long_distance;
    float32 long_distance_std;
    uint8 relevance;
} PerceptionTrafficSign;

typedef struct
{
    sint32 sign;
    uint8 type;
} TrafficSignType;

typedef TrafficSignType TrafficSignType_24[24];
typedef struct
{
    TrafficSignType sign;
    TrafficSignType_24 derived_signs;
    BoxRect bbox;
    float32 lat_distance;
    float32 long_distance;
    float32 panel_width;
    float32 panel_height;
    float32 height;
    float32 speed_limit;
    float32 height_limit;
    float32 weight_limit;
} PerceptionTrafficSignStatus;

typedef PerceptionTrafficSignStatus PerceptionTrafficSignStatus_16[16];
typedef PerceptionTrafficSign PerceptionTrafficSign_16[16];
typedef uint8 RCR_BlockagedSts_IDT;
typedef uint8 RCR_SysErrorSts_IDT;
typedef uint8 RCR_VoiceWarningReq_IDT;
typedef uint8 RCTA_FuncSWReq_IDT;
typedef uint8 RCTA_FuncSts_IDT;
typedef uint8 RCTA_FuncSwtResp_IDT;
typedef uint8 RCTA_WarningReqLeft_IDT;
typedef uint8 RCTA_WarningReqRight_IDT;
typedef uint8 RCW_FuncSWReq_IDT;
typedef uint8 RCW_FuncSts_IDT;
typedef uint8 RCW_FuncSwtResp_IDT;
typedef uint8 RCW_Hazard_lightReq_IDT;
typedef uint8 RCW_WarningReq_IDT;
typedef uint8 RLC_ExtenedDistance_IDT;
typedef uint8 RLM_ExtenedDistance_IDT;
typedef uint16 RLS_ExtenedDistance_IDT;
typedef uint8 RLS_LightRequest_IDT;
typedef uint8 RLS_LightSensorError_IDT;
typedef uint8 RLS_RainSensorError_IDT;
typedef uint8 RLS_Rainfall_magnitude_IDT;
typedef uint8 RLS_Solar_Left_Driveside_IDT;
typedef uint8 RLS_Solar_Right_PassgSide_IDT;
typedef uint8 RRC_ExtenedDistance_IDT;
typedef uint8 RRM_ExtenedDistance_IDT;
typedef uint16 RRS_ExtenedDistance_IDT;
typedef uint8 RollingCounter_0x106_IDT;
typedef uint8 RollingCounter_0x109_IDT;
typedef uint8 RollingCounter_0x132_IDT;
typedef uint8 RollingCounter_0x17F_IDT;
typedef uint8 RollingCounter_0x3E2_IDT;
typedef uint8 RollingCounter_0x3F1_IDT;
typedef uint8 RollingCounter_0x3F5_IDT;
typedef uint8 RollingCounter_0x3F7_IDT;
typedef uint8 RollingCounter_1F8_IDT;
typedef uint8 RollingCounter_230_IDT;
typedef uint8 Rolling_counter_0x17E_IDT;
typedef uint8 SAS_Calibrated_IDT;
typedef uint8 SAS_SASFailure_IDT;
typedef uint8 SAS_SASStsSnsr_IDT;
typedef uint16 SAS_SteerWheelAngle;
typedef uint16 SAS_SteerWheelAngle_IDT;
typedef uint16 SAS_SteerWhlRotSpd;
typedef uint8 SAS_SteerWhlRotSpdStatus_IDT;
typedef uint16 SAS_SteerWhlRotSpd_IDT;
typedef uint8 SAS_SteeringAngleValid_IDT;
typedef uint8 STAT_Central_LockSts_IDT;
typedef struct
{
    ABS_FLWheelSpeedKPH_IDT ABS_FLWheelSpeedKPH;
    ABS_FLWheelSpeedInvalid_IDT ABS_FLWheelSpeedInvalid;
    ABS_FRWheelSpeedKPH_IDT ABS_FRWheelSpeedKPH;
    ABS_FRWheelSpeedInvalid_IDT ABS_FRWheelSpeedInvalid;
    ABS_FLWheelDirection_IDT ABS_FLWheelDirection;
    ABS_FRWheelDirection_IDT ABS_FRWheelDirection;
    ABS_FWSpeMCUKPH_AliveCounter_IDT ABS_FWSpeMCUKPH_AliveCounter;
    ABS_FWSpeMCUKPH_CheckSum_IDT ABS_FWSpeMCUKPH_CheckSum;
} SigGroup_ABS_FrontWheelSpeMCUKPH_IDT;

typedef struct
{
    ABS_RLWheelSpeedKPH_IDT ABS_RLWheelSpeedKPH;
    ABS_RLWheelSpeedInvalid_IDT ABS_RLWheelSpeedInvalid;
    ABS_RRWheelSpeedKPH_IDT ABS_RRWheelSpeedKPH;
    ABS_RRWheelSpeedInvalid_IDT ABS_RRWheelSpeedInvalid;
    ABS_RLWheelDirection_IDT ABS_RLWheelDirection;
    ABS_RRWheelDirection_IDT ABS_RRWheelDirection;
    ABS_RWSpeMCUKPH_AliveCounter_IDT ABS_RWSpeMCUKPH_AliveCounter;
    ABS_RWSpeMCUKPH_CheckSum_IDT ABS_RWSpeMCUKPH_CheckSum;
} SigGroup_ABS_RearWheelSpeMCUKPH_IDT;

typedef struct
{
    ABSActive_IDT ABSActive;
    ABS_EBDFailed_IDT ABS_EBDFailed;
    ABSFailed_IDT ABSFailed;
    ABS_LowBrakeFluid_IDT ABS_LowBrakeFluid;
    ABS_VehicleSpeedInvalid_IDT ABS_VehicleSpeedInvalid;
    ABS_VehicleSpeed_IDT ABS_VehicleSpeed;
    ABS_Status_AliveCounter_IDT ABS_Status_AliveCounter;
    ABS_HAZActive_IDT ABS_HAZActive;
    ABS_Status_CheckSum_IDT ABS_Status_CheckSum;
} SigGroup_ABS_Status_IDT;

typedef struct
{
    ABS_FLWheelSpeedRC_IDT ABS_FLWheelSpeedRC;
    ABS_FRWheelSpeedRC_IDT ABS_FRWheelSpeedRC;
    ABS_RLWheelSpeedRC_IDT ABS_RLWheelSpeedRC;
    ABS_RRWheelSpeedRC_IDT ABS_RRWheelSpeedRC;
    ABS_FLWheelSpeedRCSts_IDT ABS_FLWheelSpeedRCSts;
    ABS_FRWheelSpeedRCSts_IDT ABS_FRWheelSpeedRCSts;
    ABS_RLWheelSpeedRCSts_IDT ABS_RLWheelSpeedRCSts;
    ABS_RRWheelSpeedRCSts_IDT ABS_RRWheelSpeedRCSts;
    ABS_WheelSpeMCURC_AliveCounter_IDT ABS_WheelSpeMCURC_AliveCounter;
    ABS_WheelSpeMCURC_CheckSum_IDT ABS_WheelSpeMCURC_CheckSum;
} SigGroup_ABS_WheelSpeedRC_IDT;

typedef struct
{
    ACU_CoDSeatOccupSensorStat_IDT ACU_CoDSeatOccupSensorStat;
    ACU_DSeatOccupSensorStat_IDT ACU_DSeatOccupSensorStat;
    ACU_CoDSeatbeltBucklestatus_IDT ACU_CoDSeatbeltBucklestatus;
    ACU_DSeatbeltBucklestatus_IDT ACU_DSeatbeltBucklestatus;
    ACU_CoDAirbagStatus_IDT ACU_CoDAirbagStatus;
    ACU_DAirbagStatus_IDT ACU_DAirbagStatus;
    ACU_RPSeatOccupSensorStat_IDT ACU_RPSeatOccupSensorStat;
    ACU_MPSeatOccupSensorStat_IDT ACU_MPSeatOccupSensorStat;
    ACU_LPSeatOccupSensorStat_IDT ACU_LPSeatOccupSensorStat;
    ACU_RCABsts_IDT ACU_RCABsts;
    ACU_LCABsts_IDT ACU_LCABsts;
    ACU_RSABsts_IDT ACU_RSABsts;
    ACU_LSABsts_IDT ACU_LSABsts;
    ACU_RPSeatbeltBucklestatus_IDT ACU_RPSeatbeltBucklestatus;
    ACU_MPSeatbeltBucklestatus_IDT ACU_MPSeatbeltBucklestatus;
    ACU_LPSeatbeltBucklestatus_IDT ACU_LPSeatbeltBucklestatus;
    ACU_CrashSts_IDT ACU_CrashSts;
    ACU_CrashRearOutputSts_IDT ACU_CrashRearOutputSts;
    ACU_CrashRightOutputSts_IDT ACU_CrashRightOutputSts;
    ACU_CrashLeftOutputSts_IDT ACU_CrashLeftOutputSts;
    ACU_CrashFrontOutputSts_IDT ACU_CrashFrontOutputSts;
    ACU_AirbagWarningStatus_IDT ACU_AirbagWarningStatus;
    ACU_CoDSeatbletPTighten_IDT ACU_CoDSeatbletPTighten;
    ACU_DSeatbletPTighten_IDT ACU_DSeatbletPTighten;
    ACU_AliveCounter_IDT ACU_AliveCounter;
    ACU_CheckSum_IDT ACU_CheckSum;
} SigGroup_ACU_ChimeTelltaleReq_IDT;

typedef struct
{
    ADAS_01_Checksum_IDT ADAS_01_Checksum;
    ADAS_01_RollingCounter_IDT ADAS_01_RollingCounter;
    ADAS_ACC_SpdUnit_IDT ADAS_ACC_SpdUnit;
    ADAS_ACC_TargetSpeed_IDT ADAS_ACC_TargetSpeed;
    ADAS_ACC_OperatingSts_IDT ADAS_ACC_OperatingSts;
    ADAS_ACC_TimeGapLevel_IDT ADAS_ACC_TimeGapLevel;
    ADAS_ACC_DistanceLevel_IDT ADAS_ACC_DistanceLevel;
    ACC_ObjDispSts_IDT ACC_ObjDispSts;
    ACC_TakeOverReq_IDT ACC_TakeOverReq;
} SigGroup_ADAS_01_IDT;

typedef struct
{
    ADAS_02_Checksum_IDT ADAS_02_Checksum;
    ADAS_02_RollingCounter_IDT ADAS_02_RollingCounter;
    ADAS_LSS_AssidFormResp_IDT ADAS_LSS_AssidFormResp;
    ADAS_LSS_AngCmdReqPortnValue_IDT ADAS_LSS_AngCmdReqPortnValue;
    ADAS_EPS_TargetSteeringAngle_IDT ADAS_EPS_TargetSteeringAngle;
    ADAS_EPS_Vibration_Req_IDT ADAS_EPS_Vibration_Req;
    ADAS_LSS_VoiceWarn_IDT ADAS_LSS_VoiceWarn;
    ADAS_LSS_HandsoffWarn_IDT ADAS_LSS_HandsoffWarn;
    ADAS_LSS_FuncResp_IDT ADAS_LSS_FuncResp;
    ADAS_EPS_AngReqSts_IDT ADAS_EPS_AngReqSts;
    ADAS_LSS_LeLineTrackingSts_IDT ADAS_LSS_LeLineTrackingSts;
    ADAS_LSS_RiLineTrackingSts_IDT ADAS_LSS_RiLineTrackingSts;
} SigGroup_ADAS_02_IDT;

typedef struct
{
    ADAS_03_Checksum_IDT ADAS_03_Checksum;
    ADAS_03_RollingCounter_IDT ADAS_03_RollingCounter;
    ADAS_AEB_TgtDecel_ReqValue_IDT ADAS_AEB_TgtDecel_ReqValue;
    ADAS_AccelerationReq_IDT ADAS_AccelerationReq;
    ADAS_MaxSoftAcceleration_IDT ADAS_MaxSoftAcceleration;
    ADAS_MinSoftAcceleration_IDT ADAS_MinSoftAcceleration;
} SigGroup_ADAS_03_IDT;

typedef struct
{
    CheckSum_1F8_IDT CheckSum_1F8;
    RollingCounter_1F8_IDT RollingCounter_1F8;
    APA_EPS_TargetSteeringAngle_IDT APA_EPS_TargetSteeringAngle;
    APA_WCB_BrakeControlReq_IDT APA_WCB_BrakeControlReq;
} SigGroup_ADAS_Info23_IDT;

typedef struct
{
    CheckSum_0x106_IDT CheckSum_0x106;
    RollingCounter_0x106_IDT RollingCounter_0x106;
    BCM_TurnIndicatorSts_IDT BCM_TurnIndicatorSts;
    BCM_PosLmpSts_IDT BCM_PosLmpSts;
    BCM_LowBeamSts_IDT BCM_LowBeamSts;
    BCM_HighBeamSts_IDT BCM_HighBeamSts;
    BCM_RearFogLampLightSts_IDT BCM_RearFogLampLightSts;
    BCM_BrakeLightSts_IDT BCM_BrakeLightSts;
    BCM_ReverseLightSts_IDT BCM_ReverseLightSts;
    BCM_DayRunningLampSts_IDT BCM_DayRunningLampSts;
    BCM_RMarkerLightSts_IDT BCM_RMarkerLightSts;
    BCM_Rr_domelampSts_IDT BCM_Rr_domelampSts;
    BCM_Fr_domelampSts_IDT BCM_Fr_domelampSts;
    BCM_LicensePlateLightSts_IDT BCM_LicensePlateLightSts;
    BCM_HeadLight_adjustSts_IDT BCM_HeadLight_adjustSts;
    BCM_FrontFogLampLightSts_IDT BCM_FrontFogLampLightSts;
    BCM_STAT_InteriorLight_IDT BCM_STAT_InteriorLight;
    BCM_STAT_SwLightBrightness_IDT BCM_STAT_SwLightBrightness;
    BCM_TurnLight_FaultSts_IDT BCM_TurnLight_FaultSts;
    BCM_AmbeLightZone2Sts_IDT BCM_AmbeLightZone2Sts;
    BCM_AmbeLightZone1Sts_IDT BCM_AmbeLightZone1Sts;
} SigGroup_BCM_LIGHT_0x106_IDT;

typedef struct
{
    PEPS_PowerModeValidity_IDT PEPS_PowerModeValidity;
    PEPS_PowerMode_IDT PEPS_PowerMode;
    PEPS_RemoteControlSt_IDT PEPS_RemoteControlSt;
    PEPS_IGN1RelayValidity_IDT PEPS_IGN1RelayValidity;
    PEPS_IGN1RelaySts_IDT PEPS_IGN1RelaySts;
    PEPS_Learning_Status_IDT PEPS_Learning_Status;
    BCM_WPC_Off_Req_IDT BCM_WPC_Off_Req;
    PEPS_Message_Sts_AliveCounter_IDT PEPS_Message_Sts_AliveCounter;
    PEPS_Message_Sts_CheckSum_IDT PEPS_Message_Sts_CheckSum;
} SigGroup_BCM_PEPS_Sts_IDT;

typedef struct
{
    CheckSum_0x109_IDT CheckSum_0x109;
    RollingCounter_0x109_IDT RollingCounter_0x109;
    BCM_STAT_Horn_IDT BCM_STAT_Horn;
    BCM_STAT_HazardWarn_IDT BCM_STAT_HazardWarn;
    BCM_LowBeamSWSts_IDT BCM_LowBeamSWSts;
    BCM_TurnLightSWSts_IDT BCM_TurnLightSWSts;
    BCM_Tail_MicroSW_IDT BCM_Tail_MicroSW;
    STAT_Central_LockSts_IDT STAT_Central_LockSts;
    BCM_RFogLampSWSts_IDT BCM_RFogLampSWSts;
    BCM_FFogLampSWSts_IDT BCM_FFogLampSWSts;
    BCM_HighBeamSWSts_IDT BCM_HighBeamSWSts;
} SigGroup_BCM_SwitchSts_0x109_IDT;

typedef struct
{
    CheckSum_0x17F_IDT CheckSum_0x17F;
    EPS_ADAS_CtrlAbortFeedback_IDT EPS_ADAS_CtrlAbortFeedback;
    RollingCounter_0x17F_IDT RollingCounter_0x17F;
    EPS_SterMod_IDT EPS_SterMod;
    EPS_SterModV_IDT EPS_SterModV;
    EPS_LKARespTorq_IDT EPS_LKARespTorq;
    EPS_SterFltMod_IDT EPS_SterFltMod;
    EPS_DrStrTorqV_IDT EPS_DrStrTorqV;
    EPS_ADAS_ModActv_IDT EPS_ADAS_ModActv;
    EPS_ADAS_ModAvail_IDT EPS_ADAS_ModAvail;
    EPS_DrStrTorqVal_IDT EPS_DrStrTorqVal;
} SigGroup_EPS_LKA_Sts_IDT;

typedef uint8 WCBS_Trailermode_Feedback_IDT;
typedef struct
{
    Checksum_230_IDT Checksum_230;
    RollingCounter_230_IDT RollingCounter_230;
    EPB_SysBrkLtsReq_IDT EPB_SysBrkLtsReq;
    EPB_SysDspMsgReqV_IDT EPB_SysDspMsgReqV;
    EPB_SysStatIndReqV_IDT EPB_SysStatIndReqV;
    EPB_SysWrnIndReqV_IDT EPB_SysWrnIndReqV;
    EPB_SysWrnIndReq_IDT EPB_SysWrnIndReq;
    EPB_SysStatIndReq_IDT EPB_SysStatIndReq;
    EPB_SysDspMsgReq_IDT EPB_SysDspMsgReq;
    EPB_AVHWrnIndReq_IDT EPB_AVHWrnIndReq;
    EPB_AVHWrnIndReqV_IDT EPB_AVHWrnIndReqV;
    EPB_AVHStatIndReq_IDT EPB_AVHStatIndReq;
    EPB_AVHStatIndReqV_IDT EPB_AVHStatIndReqV;
    EPB_AVHFeedbackSts_IDT EPB_AVHFeedbackSts;
    EPB_Sts_IDT EPB_Sts;
    WCBS_Trailermode_Feedback_IDT WCBS_Trailermode_Feedback;
} SigGroup_ESC_EPB_0x230_IDT;

typedef struct
{
    Checksum_0x132_IDT Checksum_0x132;
    RollingCounter_0x132_IDT RollingCounter_0x132;
    ESC_SlopeGradeAngle_IDT ESC_SlopeGradeAngle;
    ESC_MasterCylinderPressureV_IDT ESC_MasterCylinderPressureV;
    ESC_MasterCylinderPressure_IDT ESC_MasterCylinderPressure;
    ESC_HSA_Control_Status_IDT ESC_HSA_Control_Status;
    ESC_HSA_Status_Fault_IDT ESC_HSA_Status_Fault;
    ESC_TcsDisableSts_IDT ESC_TcsDisableSts;
    ESC_EscCtrlActv_IDT ESC_EscCtrlActv;
    ESC_TcsCtrlActv_IDT ESC_TcsCtrlActv;
    ESC_EscFlgFlt_IDT ESC_EscFlgFlt;
    ESC_TcsFlgFlt_IDT ESC_TcsFlgFlt;
    ESC_EscDisableSts_IDT ESC_EscDisableSts;
    ESC_HBAFlgFlt_IDT ESC_HBAFlgFlt;
    ESC_HbaCtrlActv_IDT ESC_HbaCtrlActv;
    BAS_FlgFlt_IDT BAS_FlgFlt;
    BAS_CtrlActv_IDT BAS_CtrlActv;
    IBS_ESCOFF_StsFB_IDT IBS_ESCOFF_StsFB;
} SigGroup_ESC_Status_0x132_IDT;

typedef struct
{
    IPC_IPCTotalOdometer_IDT IPC_IPCTotalOdometer;
    IPC_IPCTotalOdometerV_IDT IPC_IPCTotalOdometerV;
    IPC_Remain_Maintenance_IDT IPC_Remain_Maintenance;
    RollingCounter_0x3F1_IDT RollingCounter_0x3F1;
    CheckSum_0x3F1_IDT CheckSum_0x3F1;
} SigGroup_IPC_TotalOdometer_IDT;

typedef struct
{
    CheckSum_0x3F5_IDT CheckSum_0x3F5;
    RollingCounter_0x3F5_IDT RollingCounter_0x3F5;
    MFS_L1_UpControl_IDT MFS_L1_UpControl;
    MFS_L1_Central_Control_IDT MFS_L1_Central_Control;
    MFS_L1_Failure_IDT MFS_L1_Failure;
    MFS_L1_LeftControl_IDT MFS_L1_LeftControl;
    MFS_L1_DownControl_IDT MFS_L1_DownControl;
    MFS_L1_RightControl_IDT MFS_L1_RightControl;
} SigGroup_MFS_L_Control_Button1_0_IDT;

typedef struct
{
    CheckSum_0x3F7_IDT CheckSum_0x3F7;
    RollingCounter_0x3F7_IDT RollingCounter_0x3F7;
    MFS_ACC_CruiseSpdIncrease_IDT MFS_ACC_CruiseSpdIncrease;
    MFS_ACC_CruiseOn_Off_IDT MFS_ACC_CruiseOn_Off;
    MFS_L2_Failure_IDT MFS_L2_Failure;
    MFS_ACC_CruiseGapSet_IDT MFS_ACC_CruiseGapSet;
    MFS_ACC_CruiseSpdDecrease_IDT MFS_ACC_CruiseSpdDecrease;
    MFS_ACC_CruiseCancel_IDT MFS_ACC_CruiseCancel;
} SigGroup_MFS_L_Control_Button2_0_IDT;

typedef struct
{
    Checksum_0x17E_IDT Checksum_0x17E;
    Rolling_counter_0x17E_IDT Rolling_counter_0x17E;
    SAS_SASStsSnsr_IDT SAS_SASStsSnsr;
    SAS_SteeringAngleValid_IDT SAS_SteeringAngleValid;
    SAS_SteerWhlRotSpd_IDT SAS_SteerWhlRotSpd;
    SAS_SASFailure_IDT SAS_SASFailure;
    SAS_Calibrated_IDT SAS_Calibrated;
    SAS_SteerWhlRotSpdStatus_IDT SAS_SteerWhlRotSpdStatus;
    SAS_SteerWheelAngle_IDT SAS_SteerWheelAngle;
} SigGroup_SAS_Sensor_0x17E_IDT;

typedef uint8 VCU_ModeGearSts_IDT;
typedef uint8 VCU_Warning_IMMO_Fail_IDT;
typedef uint8 VCU_Ready_IDT;
typedef uint8 VCU_RegencyLevInd_IDT;
typedef uint8 VCU_Ctrl_AliveCounter_IDT;
typedef uint8 VCU_LimpHomeSts_IDT;
typedef uint8 VCU_Ctrl_CheckSum_IDT;
typedef struct
{
    VCU_ModeGearSts_IDT VCU_ModeGearSts;
    VCU_Warning_IMMO_Fail_IDT VCU_Warning_IMMO_Fail;
    VCU_Ready_IDT VCU_Ready;
    VCU_RegencyLevInd_IDT VCU_RegencyLevInd;
    VCU_Ctrl_AliveCounter_IDT VCU_Ctrl_AliveCounter;
    VCU_LimpHomeSts_IDT VCU_LimpHomeSts;
    VCU_Ctrl_CheckSum_IDT VCU_Ctrl_CheckSum;
} SigGroup_VCU_Ctrl_IDT;

typedef uint8 VCU_StsAccPedalFault_IDT;
typedef uint8 VCU_StsSysFault_IDT;
typedef uint8 VCU_AccPedalPosition_IDT;
typedef uint8 VCU_AccPedal_Active_IDT;
typedef uint8 VCU_StsEpt_AliveCounter_IDT;
typedef uint8 VCU_StsEpt_CheckSum_IDT;
typedef struct
{
    VCU_StsAccPedalFault_IDT VCU_StsAccPedalFault;
    VCU_StsSysFault_IDT VCU_StsSysFault;
    VCU_AccPedalPosition_IDT VCU_AccPedalPosition;
    VCU_AccPedal_Active_IDT VCU_AccPedal_Active;
    VCU_StsEpt_AliveCounter_IDT VCU_StsEpt_AliveCounter;
    VCU_StsEpt_CheckSum_IDT VCU_StsEpt_CheckSum;
} SigGroup_VCU_StsEpt_IDT;

typedef struct
{
    ARS_CFG_VParPitchAngle_IDT ARS_CFG_VParPitchAngle;
    ARS_CFG_VParPitchAngle_CFGflag_IDT ARS_CFG_VParPitchAngle_CFGflag;
    ARS_CFG_ProtoclFlag_P_IDT ARS_CFG_ProtoclFlag_P;
    ARS_CFGSTATE_Mode_IDT ARS_CFGSTATE_Mode;
    ARS_CFGST_VehPrAxLdDstr_CFGfl_IDT ARS_CFGST_VehPrAxLdDstr_CFGfl;
    ARS_CFGST_VehPrCntrGrvHght_CFGfl_IDT ARS_CFGST_VehPrCntrGrvHght_CFGfl;
    ARS_CFGST_VehPrCntrOfGrvHght_IDT ARS_CFGST_VehPrCntrOfGrvHght;
    ARS_CFGST_VehPrVehWght_CFGfl_IDT ARS_CFGST_VehPrVehWght_CFGfl;
    ARS_CFGST_VehPrTrWdRear_CFGfl_IDT ARS_CFGST_VehPrTrWdRear_CFGfl;
    ARS_CFGST_VehPrAxLdDistr0_IDT ARS_CFGST_VehPrAxLdDistr0;
    ARS_CFGST_VehPrTrWdFrnt_CFGfl_IDT ARS_CFGST_VehPrTrWdFrnt_CFGfl;
    ARS_CFGSTATE_VehParLatPos_IDT ARS_CFGSTATE_VehParLatPos;
    ARS_CFGST_VehPrWhlBs_CFGfl_IDT ARS_CFGST_VehPrWhlBs_CFGfl;
    ARS_CFGST_VehParStrRatio_CFGfl_IDT ARS_CFGST_VehParStrRatio_CFGfl;
    ARS_CFGSTATE_VehParLongPos_IDT ARS_CFGSTATE_VehParLongPos;
    ARS_CFGST_TmeSynEnFl_IDT ARS_CFGST_TmeSynEnFl;
    ARS_CFGSTATE_VehParVertPos_IDT ARS_CFGSTATE_VehParVertPos;
    ARS_CFGSTATE_VehParSteeringRatio_IDT ARS_CFGSTATE_VehParSteeringRatio;
    ARS_CFGST_VehPrLatPos_CFGfl_IDT ARS_CFGST_VehPrLatPos_CFGfl;
    ARS_CFGSTATE_SensorID_IDT ARS_CFGSTATE_SensorID;
    ARS_CFGSTATE_SensorID_CFGflag_IDT ARS_CFGSTATE_SensorID_CFGflag;
    ARS_CFGST_VehPrLngPosCoG_IDT ARS_CFGST_VehPrLngPosCoG;
    ARS_CFGSTATE_VehParYawAngle_IDT ARS_CFGSTATE_VehParYawAngle;
    ARS_CFGST_VehPrLngPos_CFGfl_IDT ARS_CFGST_VehPrLngPos_CFGfl;
    ARS_CFGST_VehPrVrtPos_CFGfl_IDT ARS_CFGST_VehPrVrtPos_CFGfl;
    ARS_CFGST_VehPrLngPosCoG_CFGfl_IDT ARS_CFGST_VehPrLngPosCoG_CFGfl;
    ARS_CFGST_VehPrSnsrOri_IDT ARS_CFGST_VehPrSnsrOri;
    ARS_CFGST_VehPrSnsrOri_CFGfl_IDT ARS_CFGST_VehPrSnsrOri_CFGfl;
    ARS_CFGST_VehPrYwAng_CFGfl_IDT ARS_CFGST_VehPrYwAng_CFGfl;
    ARS_CFGST_VehPrCvrDmp_CFGfl_IDT ARS_CFGST_VehPrCvrDmp_CFGfl;
    ARS_CFGSTATE_VehParCoverDamping_IDT ARS_CFGSTATE_VehParCoverDamping;
    ARS_CFGSTATE_MsgCounter_IDT ARS_CFGSTATE_MsgCounter;
    ARS_CFGSTATE_CRC16_Checksum_IDT ARS_CFGSTATE_CRC16_Checksum;
    ARS_CFGSTATE_VehParWheelBase_IDT ARS_CFGSTATE_VehParWheelBase;
    ARS_CFGST_VehPrTrkWdthFrnt_IDT ARS_CFGST_VehPrTrkWdthFrnt;
    ARS_CFGST_VehPrTrkWdthRear_IDT ARS_CFGST_VehPrTrkWdthRear;
    ARS_CFGST_VehPrVehWght_IDT ARS_CFGST_VehPrVehWght;
} Signal_Group_ARS_CONFIG_STATE_IDT;

typedef struct
{
    DistHeight_Obj_01_IDT DistHeight_Obj_01;
    DistHeight_Obj_00_IDT DistHeight_Obj_00;
    ARS_OD_DistX_Obj_00_IDT ARS_OD_DistX_Obj_00;
    ARS_OD_Classification_Obj_00_IDT ARS_OD_Classification_Obj_00;
    ARS_OD_AabsYStd_Obj_00_IDT ARS_OD_AabsYStd_Obj_00;
    ARS_OD_ClassConf_Obj_00_IDT ARS_OD_ClassConf_Obj_00;
    ARS_OD_ProbOfExist_Obj_00_IDT ARS_OD_ProbOfExist_Obj_00;
    ARS_OD_DynConf_Obj_00_IDT ARS_OD_DynConf_Obj_00;
    ARS_OD_VabsX_Obj_00_IDT ARS_OD_VabsX_Obj_00;
    ARS_OD_DynProp_Obj_00_IDT ARS_OD_DynProp_Obj_00;
    ARS_OD_MirrorProb_Obj_00_IDT ARS_OD_MirrorProb_Obj_00;
    ARS_OD_Length_Obj_00_IDT ARS_OD_Length_Obj_00;
    ARS_OD_MaintenanceState_Obj_00_IDT ARS_OD_MaintenanceState_Obj_00;
    ARS_OD_Width_Obj_00_IDT ARS_OD_Width_Obj_00;
    ARS_OD_RCS_Obj_00_IDT ARS_OD_RCS_Obj_00;
    ARS_OD_Orientation_Obj_00_IDT ARS_OD_Orientation_Obj_00;
    ARS_OD_YawRateAbs_Obj_00_IDT ARS_OD_YawRateAbs_Obj_00;
    ARS_OD_YawRateAbsStd_Obj_00_IDT ARS_OD_YawRateAbsStd_Obj_00;
    ARS_OD_RefPoint_Obj_00_IDT ARS_OD_RefPoint_Obj_00;
    ARS_OD_LifeCycle_Obj_00_IDT ARS_OD_LifeCycle_Obj_00;
    ARS_OD_DistX_Obj_01_IDT ARS_OD_DistX_Obj_01;
    ARS_OD_VabsX_Obj_01_IDT ARS_OD_VabsX_Obj_01;
    ARS_OD_AabsX_Obj_01_IDT ARS_OD_AabsX_Obj_01;
    ARS_OD_AabsX_Obj_00_IDT ARS_OD_AabsX_Obj_00;
    ARS_OD_DistY_Obj_01_IDT ARS_OD_DistY_Obj_01;
    ARS_OD_VabsY_Obj_01_IDT ARS_OD_VabsY_Obj_01;
    ARS_OD_AabsY_Obj_01_IDT ARS_OD_AabsY_Obj_01;
    ARS_OD_DistXStd_Obj_01_IDT ARS_OD_DistXStd_Obj_01;
    ARS_OD_DistYStd_Obj_01_IDT ARS_OD_DistYStd_Obj_01;
    ARS_OD_VabsXStd_Obj_01_IDT ARS_OD_VabsXStd_Obj_01;
    ARS_OD_VabsYStd_Obj_01_IDT ARS_OD_VabsYStd_Obj_01;
    ARS_OD_AabsXStd_Obj_01_IDT ARS_OD_AabsXStd_Obj_01;
    ARS_OD_Classification_Obj_01_IDT ARS_OD_Classification_Obj_01;
    ARS_OD_AabsYStd_Obj_01_IDT ARS_OD_AabsYStd_Obj_01;
    ARS_OD_ClassConf_Obj_01_IDT ARS_OD_ClassConf_Obj_01;
    ARS_OD_DistY_Obj_00_IDT ARS_OD_DistY_Obj_00;
    ARS_OD_ProbOfExist_Obj_01_IDT ARS_OD_ProbOfExist_Obj_01;
    ARS_OD_DynConf_Obj_01_IDT ARS_OD_DynConf_Obj_01;
    ARS_OD_DynProp_Obj_01_IDT ARS_OD_DynProp_Obj_01;
    ARS_OD_MirrorProb_Obj_01_IDT ARS_OD_MirrorProb_Obj_01;
    ARS_OD_Length_Obj_01_IDT ARS_OD_Length_Obj_01;
    ARS_OD_MaintenanceState_Obj_01_IDT ARS_OD_MaintenanceState_Obj_01;
    ARS_OD_Width_Obj_01_IDT ARS_OD_Width_Obj_01;
    ARS_OD_RCS_Obj_01_IDT ARS_OD_RCS_Obj_01;
    ARS_OD_Orientation_Obj_01_IDT ARS_OD_Orientation_Obj_01;
    ARS_OD_YawRateAbs_Obj_01_IDT ARS_OD_YawRateAbs_Obj_01;
    ARS_OD_YawRateAbsStd_Obj_01_IDT ARS_OD_YawRateAbsStd_Obj_01;
    ARS_OD_RefPoint_Obj_01_IDT ARS_OD_RefPoint_Obj_01;
    ARS_OD_LifeCycle_Obj_01_IDT ARS_OD_LifeCycle_Obj_01;
    ARS_OD_OrientationStd_Obj_00_IDT ARS_OD_OrientationStd_Obj_00;
    ARS_OD_OrientationStd_Obj_01_IDT ARS_OD_OrientationStd_Obj_01;
    ARS_OD_ObstacleProb_Obj_00_IDT ARS_OD_ObstacleProb_Obj_00;
    ARS_OD_MicroDopplerFlag_00_IDT ARS_OD_MicroDopplerFlag_00;
    ARS_OD_ObstacleProb_Obj_01_IDT ARS_OD_ObstacleProb_Obj_01;
    ARS_OD_VabsY_Obj_00_IDT ARS_OD_VabsY_Obj_00;
    ARS_OD_MicroDopplerFlag_01_IDT ARS_OD_MicroDopplerFlag_01;
    ARS_OD_ID_00_IDT ARS_OD_ID_00;
    ARS_OD_ID_01_IDT ARS_OD_ID_01;
    ARS_OD_MsgCounter_Obj_00_01_IDT ARS_OD_MsgCounter_Obj_00_01;
    ARS_OD_CRC16_Checksum_Obj_00_01_IDT ARS_OD_CRC16_Checksum_Obj_00_01;
    ARS_OD_AabsY_Obj_00_IDT ARS_OD_AabsY_Obj_00;
    ARS_OD_DistXStd_Obj_00_IDT ARS_OD_DistXStd_Obj_00;
    ARS_OD_DistYStd_Obj_00_IDT ARS_OD_DistYStd_Obj_00;
    ARS_OD_VabsXStd_Obj_00_IDT ARS_OD_VabsXStd_Obj_00;
    ARS_OD_VabsYStd_Obj_00_IDT ARS_OD_VabsYStd_Obj_00;
    ARS_OD_AabsXStd_Obj_00_IDT ARS_OD_AabsXStd_Obj_00;
} Signal_Group_ARS_OD_00_01_IDT;

typedef struct
{
    DistHeight_Obj_02_IDT DistHeight_Obj_02;
    DistHeight_Obj_03_IDT DistHeight_Obj_03;
    ARS_OD_DistX_Obj_02_IDT ARS_OD_DistX_Obj_02;
    ARS_OD_Classification_Obj_02_IDT ARS_OD_Classification_Obj_02;
    ARS_OD_AabsYStd_Obj_02_IDT ARS_OD_AabsYStd_Obj_02;
    ARS_OD_ClassConf_Obj_02_IDT ARS_OD_ClassConf_Obj_02;
    ARS_OD_ProbOfExist_Obj_02_IDT ARS_OD_ProbOfExist_Obj_02;
    ARS_OD_DynConf_Obj_02_IDT ARS_OD_DynConf_Obj_02;
    ARS_OD_VabsX_Obj_02_IDT ARS_OD_VabsX_Obj_02;
    ARS_OD_DynProp_Obj_02_IDT ARS_OD_DynProp_Obj_02;
    ARS_OD_MirrorProb_Obj_02_IDT ARS_OD_MirrorProb_Obj_02;
    ARS_OD_Length_Obj_02_IDT ARS_OD_Length_Obj_02;
    ARS_OD_MaintenanceState_Obj_02_IDT ARS_OD_MaintenanceState_Obj_02;
    ARS_OD_Width_Obj_02_IDT ARS_OD_Width_Obj_02;
    ARS_OD_RCS_Obj_02_IDT ARS_OD_RCS_Obj_02;
    ARS_OD_Orientation_Obj_02_IDT ARS_OD_Orientation_Obj_02;
    ARS_OD_YawRateAbs_Obj_02_IDT ARS_OD_YawRateAbs_Obj_02;
    ARS_OD_YawRateAbsStd_Obj_02_IDT ARS_OD_YawRateAbsStd_Obj_02;
    ARS_OD_RefPoint_Obj_02_IDT ARS_OD_RefPoint_Obj_02;
    ARS_OD_LifeCycle_Obj_02_IDT ARS_OD_LifeCycle_Obj_02;
    ARS_OD_DistX_Obj_03_IDT ARS_OD_DistX_Obj_03;
    ARS_OD_VabsX_Obj_03_IDT ARS_OD_VabsX_Obj_03;
    ARS_OD_AabsX_Obj_03_IDT ARS_OD_AabsX_Obj_03;
    ARS_OD_AabsX_Obj_02_IDT ARS_OD_AabsX_Obj_02;
    ARS_OD_DistY_Obj_03_IDT ARS_OD_DistY_Obj_03;
    ARS_OD_VabsY_Obj_03_IDT ARS_OD_VabsY_Obj_03;
    ARS_OD_AabsY_Obj_03_IDT ARS_OD_AabsY_Obj_03;
    ARS_OD_DistXStd_Obj_03_IDT ARS_OD_DistXStd_Obj_03;
    ARS_OD_DistYStd_Obj_03_IDT ARS_OD_DistYStd_Obj_03;
    ARS_OD_VabsXStd_Obj_03_IDT ARS_OD_VabsXStd_Obj_03;
    ARS_OD_VabsYStd_Obj_03_IDT ARS_OD_VabsYStd_Obj_03;
    ARS_OD_AabsXStd_Obj_03_IDT ARS_OD_AabsXStd_Obj_03;
    ARS_OD_Classification_Obj_03_IDT ARS_OD_Classification_Obj_03;
    ARS_OD_AabsYStd_Obj_03_IDT ARS_OD_AabsYStd_Obj_03;
    ARS_OD_ClassConf_Obj_03_IDT ARS_OD_ClassConf_Obj_03;
    ARS_OD_DistY_Obj_02_IDT ARS_OD_DistY_Obj_02;
    ARS_OD_ProbOfExist_Obj_03_IDT ARS_OD_ProbOfExist_Obj_03;
    ARS_OD_DynConf_Obj_03_IDT ARS_OD_DynConf_Obj_03;
    ARS_OD_DynProp_Obj_03_IDT ARS_OD_DynProp_Obj_03;
    ARS_OD_MirrorProb_Obj_03_IDT ARS_OD_MirrorProb_Obj_03;
    ARS_OD_Length_Obj_03_IDT ARS_OD_Length_Obj_03;
    ARS_OD_MaintenanceState_Obj_03_IDT ARS_OD_MaintenanceState_Obj_03;
    ARS_OD_Width_Obj_03_IDT ARS_OD_Width_Obj_03;
    ARS_OD_RCS_Obj_03_IDT ARS_OD_RCS_Obj_03;
    ARS_OD_Orientation_Obj_03_IDT ARS_OD_Orientation_Obj_03;
    ARS_OD_YawRateAbs_Obj_03_IDT ARS_OD_YawRateAbs_Obj_03;
    ARS_OD_YawRateAbsStd_Obj_03_IDT ARS_OD_YawRateAbsStd_Obj_03;
    ARS_OD_RefPoint_Obj_03_IDT ARS_OD_RefPoint_Obj_03;
    ARS_OD_LifeCycle_Obj_03_IDT ARS_OD_LifeCycle_Obj_03;
    ARS_OD_OrientationStd_Obj_02_IDT ARS_OD_OrientationStd_Obj_02;
    ARS_OD_OrientationStd_Obj_03_IDT ARS_OD_OrientationStd_Obj_03;
    ARS_OD_ObstacleProb_Obj_02_IDT ARS_OD_ObstacleProb_Obj_02;
    ARS_OD_MicroDopplerFlag_02_IDT ARS_OD_MicroDopplerFlag_02;
    ARS_OD_ObstacleProb_Obj_03_IDT ARS_OD_ObstacleProb_Obj_03;
    ARS_OD_VabsY_Obj_02_IDT ARS_OD_VabsY_Obj_02;
    ARS_OD_MicroDopplerFlag_03_IDT ARS_OD_MicroDopplerFlag_03;
    ARS_OD_ID_02_IDT ARS_OD_ID_02;
    ARS_OD_ID_03_IDT ARS_OD_ID_03;
    ARS_OD_MsgCounter_Obj_02_03_IDT ARS_OD_MsgCounter_Obj_02_03;
    ARS_OD_CRC16_Checksum_Obj_02_03_IDT ARS_OD_CRC16_Checksum_Obj_02_03;
    ARS_OD_AabsY_Obj_02_IDT ARS_OD_AabsY_Obj_02;
    ARS_OD_DistXStd_Obj_02_IDT ARS_OD_DistXStd_Obj_02;
    ARS_OD_DistYStd_Obj_02_IDT ARS_OD_DistYStd_Obj_02;
    ARS_OD_VabsXStd_Obj_02_IDT ARS_OD_VabsXStd_Obj_02;
    ARS_OD_VabsYStd_Obj_02_IDT ARS_OD_VabsYStd_Obj_02;
    ARS_OD_AabsXStd_Obj_02_IDT ARS_OD_AabsXStd_Obj_02;
} Signal_Group_ARS_OD_02_03_IDT;

typedef struct
{
    DistHeight_Obj_04_IDT DistHeight_Obj_04;
    DistHeight_Obj_05_IDT DistHeight_Obj_05;
    ARS_OD_DistX_Obj_04_IDT ARS_OD_DistX_Obj_04;
    ARS_OD_Classification_Obj_04_IDT ARS_OD_Classification_Obj_04;
    ARS_OD_AabsYStd_Obj_04_IDT ARS_OD_AabsYStd_Obj_04;
    ARS_OD_ClassConf_Obj_04_IDT ARS_OD_ClassConf_Obj_04;
    ARS_OD_ProbOfExist_Obj_04_IDT ARS_OD_ProbOfExist_Obj_04;
    ARS_OD_DynConf_Obj_04_IDT ARS_OD_DynConf_Obj_04;
    ARS_OD_VabsX_Obj_04_IDT ARS_OD_VabsX_Obj_04;
    ARS_OD_DynProp_Obj_04_IDT ARS_OD_DynProp_Obj_04;
    ARS_OD_MirrorProb_Obj_04_IDT ARS_OD_MirrorProb_Obj_04;
    ARS_OD_Length_Obj_04_IDT ARS_OD_Length_Obj_04;
    ARS_OD_MaintenanceState_Obj_04_IDT ARS_OD_MaintenanceState_Obj_04;
    ARS_OD_Width_Obj_04_IDT ARS_OD_Width_Obj_04;
    ARS_OD_RCS_Obj_04_IDT ARS_OD_RCS_Obj_04;
    ARS_OD_Orientation_Obj_04_IDT ARS_OD_Orientation_Obj_04;
    ARS_OD_YawRateAbs_Obj_04_IDT ARS_OD_YawRateAbs_Obj_04;
    ARS_OD_YawRateAbsStd_Obj_04_IDT ARS_OD_YawRateAbsStd_Obj_04;
    ARS_OD_RefPoint_Obj_04_IDT ARS_OD_RefPoint_Obj_04;
    ARS_OD_LifeCycle_Obj_04_IDT ARS_OD_LifeCycle_Obj_04;
    ARS_OD_DistX_Obj_05_IDT ARS_OD_DistX_Obj_05;
    ARS_OD_VabsX_Obj_05_IDT ARS_OD_VabsX_Obj_05;
    ARS_OD_AabsX_Obj_05_IDT ARS_OD_AabsX_Obj_05;
    ARS_OD_AabsX_Obj_04_IDT ARS_OD_AabsX_Obj_04;
    ARS_OD_DistY_Obj_05_IDT ARS_OD_DistY_Obj_05;
    ARS_OD_VabsY_Obj_05_IDT ARS_OD_VabsY_Obj_05;
    ARS_OD_AabsY_Obj_05_IDT ARS_OD_AabsY_Obj_05;
    ARS_OD_DistXStd_Obj_05_IDT ARS_OD_DistXStd_Obj_05;
    ARS_OD_DistYStd_Obj_05_IDT ARS_OD_DistYStd_Obj_05;
    ARS_OD_VabsXStd_Obj_05_IDT ARS_OD_VabsXStd_Obj_05;
    ARS_OD_VabsYStd_Obj_05_IDT ARS_OD_VabsYStd_Obj_05;
    ARS_OD_AabsXStd_Obj_05_IDT ARS_OD_AabsXStd_Obj_05;
    ARS_OD_Classification_Obj_05_IDT ARS_OD_Classification_Obj_05;
    ARS_OD_AabsYStd_Obj_05_IDT ARS_OD_AabsYStd_Obj_05;
    ARS_OD_ClassConf_Obj_05_IDT ARS_OD_ClassConf_Obj_05;
    ARS_OD_DistY_Obj_04_IDT ARS_OD_DistY_Obj_04;
    ARS_OD_ProbOfExist_Obj_05_IDT ARS_OD_ProbOfExist_Obj_05;
    ARS_OD_DynConf_Obj_05_IDT ARS_OD_DynConf_Obj_05;
    ARS_OD_DynProp_Obj_05_IDT ARS_OD_DynProp_Obj_05;
    ARS_OD_MirrorProb_Obj_05_IDT ARS_OD_MirrorProb_Obj_05;
    ARS_OD_Length_Obj_05_IDT ARS_OD_Length_Obj_05;
    ARS_OD_MaintenanceState_Obj_05_IDT ARS_OD_MaintenanceState_Obj_05;
    ARS_OD_Width_Obj_05_IDT ARS_OD_Width_Obj_05;
    ARS_OD_RCS_Obj_05_IDT ARS_OD_RCS_Obj_05;
    ARS_OD_Orientation_Obj_05_IDT ARS_OD_Orientation_Obj_05;
    ARS_OD_YawRateAbs_Obj_05_IDT ARS_OD_YawRateAbs_Obj_05;
    ARS_OD_YawRateAbsStd_Obj_05_IDT ARS_OD_YawRateAbsStd_Obj_05;
    ARS_OD_RefPoint_Obj_05_IDT ARS_OD_RefPoint_Obj_05;
    ARS_OD_LifeCycle_Obj_05_IDT ARS_OD_LifeCycle_Obj_05;
    ARS_OD_OrientationStd_Obj_04_IDT ARS_OD_OrientationStd_Obj_04;
    ARS_OD_OrientationStd_Obj_05_IDT ARS_OD_OrientationStd_Obj_05;
    ARS_OD_ObstacleProb_Obj_04_IDT ARS_OD_ObstacleProb_Obj_04;
    ARS_OD_MicroDopplerFlag_04_IDT ARS_OD_MicroDopplerFlag_04;
    ARS_OD_ObstacleProb_Obj_05_IDT ARS_OD_ObstacleProb_Obj_05;
    ARS_OD_VabsY_Obj_04_IDT ARS_OD_VabsY_Obj_04;
    ARS_OD_MicroDopplerFlag_05_IDT ARS_OD_MicroDopplerFlag_05;
    ARS_OD_ID_04_IDT ARS_OD_ID_04;
    ARS_OD_ID_05_IDT ARS_OD_ID_05;
    ARS_OD_MsgCounter_Obj_04_05_IDT ARS_OD_MsgCounter_Obj_04_05;
    ARS_OD_CRC16_Checksum_Obj_04_05_IDT ARS_OD_CRC16_Checksum_Obj_04_05;
    ARS_OD_AabsY_Obj_04_IDT ARS_OD_AabsY_Obj_04;
    ARS_OD_DistXStd_Obj_04_IDT ARS_OD_DistXStd_Obj_04;
    ARS_OD_DistYStd_Obj_04_IDT ARS_OD_DistYStd_Obj_04;
    ARS_OD_VabsXStd_Obj_04_IDT ARS_OD_VabsXStd_Obj_04;
    ARS_OD_VabsYStd_Obj_04_IDT ARS_OD_VabsYStd_Obj_04;
    ARS_OD_AabsXStd_Obj_04_IDT ARS_OD_AabsXStd_Obj_04;
} Signal_Group_ARS_OD_04_05_IDT;

typedef struct
{
    DistHeight_Obj_07_IDT DistHeight_Obj_07;
    DistHeight_Obj_06_IDT DistHeight_Obj_06;
    ARS_OD_DistX_Obj_06_IDT ARS_OD_DistX_Obj_06;
    ARS_OD_Classification_Obj_06_IDT ARS_OD_Classification_Obj_06;
    ARS_OD_AabsYStd_Obj_06_IDT ARS_OD_AabsYStd_Obj_06;
    ARS_OD_ClassConf_Obj_06_IDT ARS_OD_ClassConf_Obj_06;
    ARS_OD_ProbOfExist_Obj_06_IDT ARS_OD_ProbOfExist_Obj_06;
    ARS_OD_DynConf_Obj_06_IDT ARS_OD_DynConf_Obj_06;
    ARS_OD_VabsX_Obj_06_IDT ARS_OD_VabsX_Obj_06;
    ARS_OD_DynProp_Obj_06_IDT ARS_OD_DynProp_Obj_06;
    ARS_OD_MirrorProb_Obj_06_IDT ARS_OD_MirrorProb_Obj_06;
    ARS_OD_Length_Obj_06_IDT ARS_OD_Length_Obj_06;
    ARS_OD_MaintenanceState_Obj_06_IDT ARS_OD_MaintenanceState_Obj_06;
    ARS_OD_Width_Obj_06_IDT ARS_OD_Width_Obj_06;
    ARS_OD_RCS_Obj_06_IDT ARS_OD_RCS_Obj_06;
    ARS_OD_Orientation_Obj_06_IDT ARS_OD_Orientation_Obj_06;
    ARS_OD_YawRateAbs_Obj_06_IDT ARS_OD_YawRateAbs_Obj_06;
    ARS_OD_YawRateAbsStd_Obj_06_IDT ARS_OD_YawRateAbsStd_Obj_06;
    ARS_OD_RefPoint_Obj_06_IDT ARS_OD_RefPoint_Obj_06;
    ARS_OD_LifeCycle_Obj_06_IDT ARS_OD_LifeCycle_Obj_06;
    ARS_OD_DistX_Obj_07_IDT ARS_OD_DistX_Obj_07;
    ARS_OD_VabsX_Obj_07_IDT ARS_OD_VabsX_Obj_07;
    ARS_OD_AabsX_Obj_07_IDT ARS_OD_AabsX_Obj_07;
    ARS_OD_AabsX_Obj_06_IDT ARS_OD_AabsX_Obj_06;
    ARS_OD_DistY_Obj_07_IDT ARS_OD_DistY_Obj_07;
    ARS_OD_VabsY_Obj_07_IDT ARS_OD_VabsY_Obj_07;
    ARS_OD_AabsY_Obj_07_IDT ARS_OD_AabsY_Obj_07;
    ARS_OD_DistXStd_Obj_07_IDT ARS_OD_DistXStd_Obj_07;
    ARS_OD_DistYStd_Obj_07_IDT ARS_OD_DistYStd_Obj_07;
    ARS_OD_VabsXStd_Obj_07_IDT ARS_OD_VabsXStd_Obj_07;
    ARS_OD_VabsYStd_Obj_07_IDT ARS_OD_VabsYStd_Obj_07;
    ARS_OD_AabsXStd_Obj_07_IDT ARS_OD_AabsXStd_Obj_07;
    ARS_OD_Classification_Obj_07_IDT ARS_OD_Classification_Obj_07;
    ARS_OD_AabsYStd_Obj_07_IDT ARS_OD_AabsYStd_Obj_07;
    ARS_OD_ClassConf_Obj_07_IDT ARS_OD_ClassConf_Obj_07;
    ARS_OD_DistY_Obj_06_IDT ARS_OD_DistY_Obj_06;
    ARS_OD_ProbOfExist_Obj_07_IDT ARS_OD_ProbOfExist_Obj_07;
    ARS_OD_DynConf_Obj_07_IDT ARS_OD_DynConf_Obj_07;
    ARS_OD_DynProp_Obj_07_IDT ARS_OD_DynProp_Obj_07;
    ARS_OD_MirrorProb_Obj_07_IDT ARS_OD_MirrorProb_Obj_07;
    ARS_OD_Length_Obj_07_IDT ARS_OD_Length_Obj_07;
    ARS_OD_MaintenanceState_Obj_07_IDT ARS_OD_MaintenanceState_Obj_07;
    ARS_OD_Width_Obj_07_IDT ARS_OD_Width_Obj_07;
    ARS_OD_RCS_Obj_07_IDT ARS_OD_RCS_Obj_07;
    ARS_OD_Orientation_Obj_07_IDT ARS_OD_Orientation_Obj_07;
    ARS_OD_YawRateAbs_Obj_07_IDT ARS_OD_YawRateAbs_Obj_07;
    ARS_OD_YawRateAbsStd_Obj_07_IDT ARS_OD_YawRateAbsStd_Obj_07;
    ARS_OD_RefPoint_Obj_07_IDT ARS_OD_RefPoint_Obj_07;
    ARS_OD_LifeCycle_Obj_07_IDT ARS_OD_LifeCycle_Obj_07;
    ARS_OD_OrientationStd_Obj_06_IDT ARS_OD_OrientationStd_Obj_06;
    ARS_OD_OrientationStd_Obj_07_IDT ARS_OD_OrientationStd_Obj_07;
    ARS_OD_ObstacleProb_Obj_06_IDT ARS_OD_ObstacleProb_Obj_06;
    ARS_OD_MicroDopplerFlag_06_IDT ARS_OD_MicroDopplerFlag_06;
    ARS_OD_ObstacleProb_Obj_07_IDT ARS_OD_ObstacleProb_Obj_07;
    ARS_OD_VabsY_Obj_06_IDT ARS_OD_VabsY_Obj_06;
    ARS_OD_MicroDopplerFlag_07_IDT ARS_OD_MicroDopplerFlag_07;
    ARS_OD_ID_06_IDT ARS_OD_ID_06;
    ARS_OD_ID_07_IDT ARS_OD_ID_07;
    ARS_OD_MsgCounter_Obj_06_07_IDT ARS_OD_MsgCounter_Obj_06_07;
    ARS_OD_CRC16_Checksum_Obj_06_07_IDT ARS_OD_CRC16_Checksum_Obj_06_07;
    ARS_OD_AabsY_Obj_06_IDT ARS_OD_AabsY_Obj_06;
    ARS_OD_DistXStd_Obj_06_IDT ARS_OD_DistXStd_Obj_06;
    ARS_OD_DistYStd_Obj_06_IDT ARS_OD_DistYStd_Obj_06;
    ARS_OD_VabsXStd_Obj_06_IDT ARS_OD_VabsXStd_Obj_06;
    ARS_OD_VabsYStd_Obj_06_IDT ARS_OD_VabsYStd_Obj_06;
    ARS_OD_AabsXStd_Obj_06_IDT ARS_OD_AabsXStd_Obj_06;
} Signal_Group_ARS_OD_06_07_IDT;

typedef struct
{
    DistHeight_Obj_09_IDT DistHeight_Obj_09;
    DistHeight_Obj_08_IDT DistHeight_Obj_08;
    ARS_OD_DistX_Obj_08_IDT ARS_OD_DistX_Obj_08;
    ARS_OD_Classification_Obj_08_IDT ARS_OD_Classification_Obj_08;
    ARS_OD_AabsYStd_Obj_08_IDT ARS_OD_AabsYStd_Obj_08;
    ARS_OD_ClassConf_Obj_08_IDT ARS_OD_ClassConf_Obj_08;
    ARS_OD_ProbOfExist_Obj_08_IDT ARS_OD_ProbOfExist_Obj_08;
    ARS_OD_DynConf_Obj_08_IDT ARS_OD_DynConf_Obj_08;
    ARS_OD_VabsX_Obj_08_IDT ARS_OD_VabsX_Obj_08;
    ARS_OD_DynProp_Obj_08_IDT ARS_OD_DynProp_Obj_08;
    ARS_OD_MirrorProb_Obj_08_IDT ARS_OD_MirrorProb_Obj_08;
    ARS_OD_Length_Obj_08_IDT ARS_OD_Length_Obj_08;
    ARS_OD_MaintenanceState_Obj_08_IDT ARS_OD_MaintenanceState_Obj_08;
    ARS_OD_Width_Obj_08_IDT ARS_OD_Width_Obj_08;
    ARS_OD_RCS_Obj_08_IDT ARS_OD_RCS_Obj_08;
    ARS_OD_Orientation_Obj_08_IDT ARS_OD_Orientation_Obj_08;
    ARS_OD_YawRateAbs_Obj_08_IDT ARS_OD_YawRateAbs_Obj_08;
    ARS_OD_YawRateAbsStd_Obj_08_IDT ARS_OD_YawRateAbsStd_Obj_08;
    ARS_OD_RefPoint_Obj_08_IDT ARS_OD_RefPoint_Obj_08;
    ARS_OD_LifeCycle_Obj_08_IDT ARS_OD_LifeCycle_Obj_08;
    ARS_OD_DistX_Obj_09_IDT ARS_OD_DistX_Obj_09;
    ARS_OD_VabsX_Obj_09_IDT ARS_OD_VabsX_Obj_09;
    ARS_OD_AabsX_Obj_09_IDT ARS_OD_AabsX_Obj_09;
    ARS_OD_AabsX_Obj_08_IDT ARS_OD_AabsX_Obj_08;
    ARS_OD_DistY_Obj_09_IDT ARS_OD_DistY_Obj_09;
    ARS_OD_VabsY_Obj_09_IDT ARS_OD_VabsY_Obj_09;
    ARS_OD_AabsY_Obj_09_IDT ARS_OD_AabsY_Obj_09;
    ARS_OD_DistXStd_Obj_09_IDT ARS_OD_DistXStd_Obj_09;
    ARS_OD_DistYStd_Obj_09_IDT ARS_OD_DistYStd_Obj_09;
    ARS_OD_VabsXStd_Obj_09_IDT ARS_OD_VabsXStd_Obj_09;
    ARS_OD_VabsYStd_Obj_09_IDT ARS_OD_VabsYStd_Obj_09;
    ARS_OD_AabsXStd_Obj_09_IDT ARS_OD_AabsXStd_Obj_09;
    ARS_OD_Classification_Obj_09_IDT ARS_OD_Classification_Obj_09;
    ARS_OD_AabsYStd_Obj_09_IDT ARS_OD_AabsYStd_Obj_09;
    ARS_OD_ClassConf_Obj_09_IDT ARS_OD_ClassConf_Obj_09;
    ARS_OD_DistY_Obj_08_IDT ARS_OD_DistY_Obj_08;
    ARS_OD_ProbOfExist_Obj_09_IDT ARS_OD_ProbOfExist_Obj_09;
    ARS_OD_DynConf_Obj_09_IDT ARS_OD_DynConf_Obj_09;
    ARS_OD_DynProp_Obj_09_IDT ARS_OD_DynProp_Obj_09;
    ARS_OD_MirrorProb_Obj_09_IDT ARS_OD_MirrorProb_Obj_09;
    ARS_OD_Length_Obj_09_IDT ARS_OD_Length_Obj_09;
    ARS_OD_MaintenanceState_Obj_09_IDT ARS_OD_MaintenanceState_Obj_09;
    ARS_OD_Width_Obj_09_IDT ARS_OD_Width_Obj_09;
    ARS_OD_RCS_Obj_09_IDT ARS_OD_RCS_Obj_09;
    ARS_OD_Orientation_Obj_09_IDT ARS_OD_Orientation_Obj_09;
    ARS_OD_YawRateAbs_Obj_09_IDT ARS_OD_YawRateAbs_Obj_09;
    ARS_OD_YawRateAbsStd_Obj_09_IDT ARS_OD_YawRateAbsStd_Obj_09;
    ARS_OD_RefPoint_Obj_09_IDT ARS_OD_RefPoint_Obj_09;
    ARS_OD_LifeCycle_Obj_09_IDT ARS_OD_LifeCycle_Obj_09;
    ARS_OD_OrientationStd_Obj_08_IDT ARS_OD_OrientationStd_Obj_08;
    ARS_OD_OrientationStd_Obj_09_IDT ARS_OD_OrientationStd_Obj_09;
    ARS_OD_ObstacleProb_Obj_08_IDT ARS_OD_ObstacleProb_Obj_08;
    ARS_OD_MicroDopplerFlag_08_IDT ARS_OD_MicroDopplerFlag_08;
    ARS_OD_ObstacleProb_Obj_09_IDT ARS_OD_ObstacleProb_Obj_09;
    ARS_OD_VabsY_Obj_08_IDT ARS_OD_VabsY_Obj_08;
    ARS_OD_MicroDopplerFlag_09_IDT ARS_OD_MicroDopplerFlag_09;
    ARS_OD_ID_08_IDT ARS_OD_ID_08;
    ARS_OD_ID_09_IDT ARS_OD_ID_09;
    ARS_OD_MsgCounter_Obj_08_09_IDT ARS_OD_MsgCounter_Obj_08_09;
    ARS_OD_CRC16_Checksum_Obj_08_09_IDT ARS_OD_CRC16_Checksum_Obj_08_09;
    ARS_OD_AabsY_Obj_08_IDT ARS_OD_AabsY_Obj_08;
    ARS_OD_DistXStd_Obj_08_IDT ARS_OD_DistXStd_Obj_08;
    ARS_OD_DistYStd_Obj_08_IDT ARS_OD_DistYStd_Obj_08;
    ARS_OD_VabsXStd_Obj_08_IDT ARS_OD_VabsXStd_Obj_08;
    ARS_OD_VabsYStd_Obj_08_IDT ARS_OD_VabsYStd_Obj_08;
    ARS_OD_AabsXStd_Obj_08_IDT ARS_OD_AabsXStd_Obj_08;
} Signal_Group_ARS_OD_08_09_IDT;

typedef struct
{
    DistHeight_Obj_11_IDT DistHeight_Obj_11;
    DistHeight_Obj_10_IDT DistHeight_Obj_10;
    ARS_OD_DistX_Obj_10_IDT ARS_OD_DistX_Obj_10;
    ARS_OD_Classification_Obj_10_IDT ARS_OD_Classification_Obj_10;
    ARS_OD_AabsYStd_Obj_10_IDT ARS_OD_AabsYStd_Obj_10;
    ARS_OD_ClassConf_Obj_10_IDT ARS_OD_ClassConf_Obj_10;
    ARS_OD_ProbOfExist_Obj_10_IDT ARS_OD_ProbOfExist_Obj_10;
    ARS_OD_DynConf_Obj_10_IDT ARS_OD_DynConf_Obj_10;
    ARS_OD_VabsX_Obj_10_IDT ARS_OD_VabsX_Obj_10;
    ARS_OD_DynProp_Obj_10_IDT ARS_OD_DynProp_Obj_10;
    ARS_OD_MirrorProb_Obj_10_IDT ARS_OD_MirrorProb_Obj_10;
    ARS_OD_Length_Obj_10_IDT ARS_OD_Length_Obj_10;
    ARS_OD_MaintenanceState_Obj_10_IDT ARS_OD_MaintenanceState_Obj_10;
    ARS_OD_Width_Obj_10_IDT ARS_OD_Width_Obj_10;
    ARS_OD_RCS_Obj_10_IDT ARS_OD_RCS_Obj_10;
    ARS_OD_Orientation_Obj_10_IDT ARS_OD_Orientation_Obj_10;
    ARS_OD_YawRateAbs_Obj_10_IDT ARS_OD_YawRateAbs_Obj_10;
    ARS_OD_YawRateAbsStd_Obj_10_IDT ARS_OD_YawRateAbsStd_Obj_10;
    ARS_OD_RefPoint_Obj_10_IDT ARS_OD_RefPoint_Obj_10;
    ARS_OD_LifeCycle_Obj_10_IDT ARS_OD_LifeCycle_Obj_10;
    ARS_OD_DistX_Obj_11_IDT ARS_OD_DistX_Obj_11;
    ARS_OD_VabsX_Obj_11_IDT ARS_OD_VabsX_Obj_11;
    ARS_OD_AabsX_Obj_11_IDT ARS_OD_AabsX_Obj_11;
    ARS_OD_AabsX_Obj_10_IDT ARS_OD_AabsX_Obj_10;
    ARS_OD_DistY_Obj_11_IDT ARS_OD_DistY_Obj_11;
    ARS_OD_VabsY_Obj_11_IDT ARS_OD_VabsY_Obj_11;
    ARS_OD_AabsY_Obj_11_IDT ARS_OD_AabsY_Obj_11;
    ARS_OD_DistXStd_Obj_11_IDT ARS_OD_DistXStd_Obj_11;
    ARS_OD_DistYStd_Obj_11_IDT ARS_OD_DistYStd_Obj_11;
    ARS_OD_VabsXStd_Obj_11_IDT ARS_OD_VabsXStd_Obj_11;
    ARS_OD_VabsYStd_Obj_11_IDT ARS_OD_VabsYStd_Obj_11;
    ARS_OD_AabsXStd_Obj_11_IDT ARS_OD_AabsXStd_Obj_11;
    ARS_OD_Classification_Obj_11_IDT ARS_OD_Classification_Obj_11;
    ARS_OD_AabsYStd_Obj_11_IDT ARS_OD_AabsYStd_Obj_11;
    ARS_OD_ClassConf_Obj_11_IDT ARS_OD_ClassConf_Obj_11;
    ARS_OD_DistY_Obj_10_IDT ARS_OD_DistY_Obj_10;
    ARS_OD_ProbOfExist_Obj_11_IDT ARS_OD_ProbOfExist_Obj_11;
    ARS_OD_DynConf_Obj_11_IDT ARS_OD_DynConf_Obj_11;
    ARS_OD_DynProp_Obj_11_IDT ARS_OD_DynProp_Obj_11;
    ARS_OD_MirrorProb_Obj_11_IDT ARS_OD_MirrorProb_Obj_11;
    ARS_OD_Length_Obj_11_IDT ARS_OD_Length_Obj_11;
    ARS_OD_MaintenanceState_Obj_11_IDT ARS_OD_MaintenanceState_Obj_11;
    ARS_OD_Width_Obj_11_IDT ARS_OD_Width_Obj_11;
    ARS_OD_RCS_Obj_11_IDT ARS_OD_RCS_Obj_11;
    ARS_OD_Orientation_Obj_11_IDT ARS_OD_Orientation_Obj_11;
    ARS_OD_YawRateAbs_Obj_11_IDT ARS_OD_YawRateAbs_Obj_11;
    ARS_OD_YawRateAbsStd_Obj_11_IDT ARS_OD_YawRateAbsStd_Obj_11;
    ARS_OD_RefPoint_Obj_11_IDT ARS_OD_RefPoint_Obj_11;
    ARS_OD_LifeCycle_Obj_11_IDT ARS_OD_LifeCycle_Obj_11;
    ARS_OD_OrientationStd_Obj_10_IDT ARS_OD_OrientationStd_Obj_10;
    ARS_OD_OrientationStd_Obj_11_IDT ARS_OD_OrientationStd_Obj_11;
    ARS_OD_ObstacleProb_Obj_10_IDT ARS_OD_ObstacleProb_Obj_10;
    ARS_OD_MicroDopplerFlag_10_IDT ARS_OD_MicroDopplerFlag_10;
    ARS_OD_ObstacleProb_Obj_11_IDT ARS_OD_ObstacleProb_Obj_11;
    ARS_OD_VabsY_Obj_10_IDT ARS_OD_VabsY_Obj_10;
    ARS_OD_MicroDopplerFlag_11_IDT ARS_OD_MicroDopplerFlag_11;
    ARS_OD_ID_10_IDT ARS_OD_ID_10;
    ARS_OD_ID_11_IDT ARS_OD_ID_11;
    ARS_OD_MsgCounter_Obj_10_11_IDT ARS_OD_MsgCounter_Obj_10_11;
    ARS_OD_CRC16_Checksum_Obj_10_11_IDT ARS_OD_CRC16_Checksum_Obj_10_11;
    ARS_OD_AabsY_Obj_10_IDT ARS_OD_AabsY_Obj_10;
    ARS_OD_DistXStd_Obj_10_IDT ARS_OD_DistXStd_Obj_10;
    ARS_OD_DistYStd_Obj_10_IDT ARS_OD_DistYStd_Obj_10;
    ARS_OD_VabsXStd_Obj_10_IDT ARS_OD_VabsXStd_Obj_10;
    ARS_OD_VabsYStd_Obj_10_IDT ARS_OD_VabsYStd_Obj_10;
    ARS_OD_AabsXStd_Obj_10_IDT ARS_OD_AabsXStd_Obj_10;
} Signal_Group_ARS_OD_10_11_IDT;

typedef struct
{
    DistHeight_Obj_13_IDT DistHeight_Obj_13;
    DistHeight_Obj_12_IDT DistHeight_Obj_12;
    ARS_OD_DistX_Obj_12_IDT ARS_OD_DistX_Obj_12;
    ARS_OD_Classification_Obj_12_IDT ARS_OD_Classification_Obj_12;
    ARS_OD_AabsYStd_Obj_12_IDT ARS_OD_AabsYStd_Obj_12;
    ARS_OD_ClassConf_Obj_12_IDT ARS_OD_ClassConf_Obj_12;
    ARS_OD_ProbOfExist_Obj_12_IDT ARS_OD_ProbOfExist_Obj_12;
    ARS_OD_DynConf_Obj_12_IDT ARS_OD_DynConf_Obj_12;
    ARS_OD_VabsX_Obj_12_IDT ARS_OD_VabsX_Obj_12;
    ARS_OD_DynProp_Obj_12_IDT ARS_OD_DynProp_Obj_12;
    ARS_OD_MirrorProb_Obj_12_IDT ARS_OD_MirrorProb_Obj_12;
    ARS_OD_Length_Obj_12_IDT ARS_OD_Length_Obj_12;
    ARS_OD_MaintenanceState_Obj_12_IDT ARS_OD_MaintenanceState_Obj_12;
    ARS_OD_Width_Obj_12_IDT ARS_OD_Width_Obj_12;
    ARS_OD_RCS_Obj_12_IDT ARS_OD_RCS_Obj_12;
    ARS_OD_Orientation_Obj_12_IDT ARS_OD_Orientation_Obj_12;
    ARS_OD_YawRateAbs_Obj_12_IDT ARS_OD_YawRateAbs_Obj_12;
    ARS_OD_YawRateAbsStd_Obj_12_IDT ARS_OD_YawRateAbsStd_Obj_12;
    ARS_OD_RefPoint_Obj_12_IDT ARS_OD_RefPoint_Obj_12;
    ARS_OD_LifeCycle_Obj_12_IDT ARS_OD_LifeCycle_Obj_12;
    ARS_OD_DistX_Obj_13_IDT ARS_OD_DistX_Obj_13;
    ARS_OD_VabsX_Obj_13_IDT ARS_OD_VabsX_Obj_13;
    ARS_OD_AabsX_Obj_13_IDT ARS_OD_AabsX_Obj_13;
    ARS_OD_AabsX_Obj_12_IDT ARS_OD_AabsX_Obj_12;
    ARS_OD_DistY_Obj_13_IDT ARS_OD_DistY_Obj_13;
    ARS_OD_VabsY_Obj_13_IDT ARS_OD_VabsY_Obj_13;
    ARS_OD_AabsY_Obj_13_IDT ARS_OD_AabsY_Obj_13;
    ARS_OD_DistXStd_Obj_13_IDT ARS_OD_DistXStd_Obj_13;
    ARS_OD_DistYStd_Obj_13_IDT ARS_OD_DistYStd_Obj_13;
    ARS_OD_VabsXStd_Obj_13_IDT ARS_OD_VabsXStd_Obj_13;
    ARS_OD_VabsYStd_Obj_13_IDT ARS_OD_VabsYStd_Obj_13;
    ARS_OD_AabsXStd_Obj_13_IDT ARS_OD_AabsXStd_Obj_13;
    ARS_OD_Classification_Obj_13_IDT ARS_OD_Classification_Obj_13;
    ARS_OD_AabsYStd_Obj_13_IDT ARS_OD_AabsYStd_Obj_13;
    ARS_OD_ClassConf_Obj_13_IDT ARS_OD_ClassConf_Obj_13;
    ARS_OD_DistY_Obj_12_IDT ARS_OD_DistY_Obj_12;
    ARS_OD_ProbOfExist_Obj_13_IDT ARS_OD_ProbOfExist_Obj_13;
    ARS_OD_DynConf_Obj_13_IDT ARS_OD_DynConf_Obj_13;
    ARS_OD_DynProp_Obj_13_IDT ARS_OD_DynProp_Obj_13;
    ARS_OD_MirrorProb_Obj_13_IDT ARS_OD_MirrorProb_Obj_13;
    ARS_OD_Length_Obj_13_IDT ARS_OD_Length_Obj_13;
    ARS_OD_MaintenanceState_Obj_13_IDT ARS_OD_MaintenanceState_Obj_13;
    ARS_OD_Width_Obj_13_IDT ARS_OD_Width_Obj_13;
    ARS_OD_RCS_Obj_13_IDT ARS_OD_RCS_Obj_13;
    ARS_OD_Orientation_Obj_13_IDT ARS_OD_Orientation_Obj_13;
    ARS_OD_YawRateAbs_Obj_13_IDT ARS_OD_YawRateAbs_Obj_13;
    ARS_OD_YawRateAbsStd_Obj_13_IDT ARS_OD_YawRateAbsStd_Obj_13;
    ARS_OD_RefPoint_Obj_13_IDT ARS_OD_RefPoint_Obj_13;
    ARS_OD_LifeCycle_Obj_13_IDT ARS_OD_LifeCycle_Obj_13;
    ARS_OD_OrientationStd_Obj_12_IDT ARS_OD_OrientationStd_Obj_12;
    ARS_OD_OrientationStd_Obj_13_IDT ARS_OD_OrientationStd_Obj_13;
    ARS_OD_ObstacleProb_Obj_12_IDT ARS_OD_ObstacleProb_Obj_12;
    ARS_OD_MicroDopplerFlag_12_IDT ARS_OD_MicroDopplerFlag_12;
    ARS_OD_ObstacleProb_Obj_13_IDT ARS_OD_ObstacleProb_Obj_13;
    ARS_OD_VabsY_Obj_12_IDT ARS_OD_VabsY_Obj_12;
    ARS_OD_MicroDopplerFlag_13_IDT ARS_OD_MicroDopplerFlag_13;
    ARS_OD_ID_12_IDT ARS_OD_ID_12;
    ARS_OD_ID_13_IDT ARS_OD_ID_13;
    ARS_OD_MsgCounter_Obj_12_13_IDT ARS_OD_MsgCounter_Obj_12_13;
    ARS_OD_CRC16_Checksum_Obj_12_13_IDT ARS_OD_CRC16_Checksum_Obj_12_13;
    ARS_OD_AabsY_Obj_12_IDT ARS_OD_AabsY_Obj_12;
    ARS_OD_DistXStd_Obj_12_IDT ARS_OD_DistXStd_Obj_12;
    ARS_OD_DistYStd_Obj_12_IDT ARS_OD_DistYStd_Obj_12;
    ARS_OD_VabsXStd_Obj_12_IDT ARS_OD_VabsXStd_Obj_12;
    ARS_OD_VabsYStd_Obj_12_IDT ARS_OD_VabsYStd_Obj_12;
    ARS_OD_AabsXStd_Obj_12_IDT ARS_OD_AabsXStd_Obj_12;
} Signal_Group_ARS_OD_12_13_IDT;

typedef struct
{
    DistHeight_Obj_15_IDT DistHeight_Obj_15;
    DistHeight_Obj_14_IDT DistHeight_Obj_14;
    ARS_OD_DistX_Obj_14_IDT ARS_OD_DistX_Obj_14;
    ARS_OD_Classification_Obj_14_IDT ARS_OD_Classification_Obj_14;
    ARS_OD_AabsYStd_Obj_14_IDT ARS_OD_AabsYStd_Obj_14;
    ARS_OD_ClassConf_Obj_14_IDT ARS_OD_ClassConf_Obj_14;
    ARS_OD_ProbOfExist_Obj_14_IDT ARS_OD_ProbOfExist_Obj_14;
    ARS_OD_DynConf_Obj_14_IDT ARS_OD_DynConf_Obj_14;
    ARS_OD_VabsX_Obj_14_IDT ARS_OD_VabsX_Obj_14;
    ARS_OD_DynProp_Obj_14_IDT ARS_OD_DynProp_Obj_14;
    ARS_OD_MirrorProb_Obj_14_IDT ARS_OD_MirrorProb_Obj_14;
    ARS_OD_Length_Obj_14_IDT ARS_OD_Length_Obj_14;
    ARS_OD_MaintenanceState_Obj_14_IDT ARS_OD_MaintenanceState_Obj_14;
    ARS_OD_Width_Obj_14_IDT ARS_OD_Width_Obj_14;
    ARS_OD_RCS_Obj_14_IDT ARS_OD_RCS_Obj_14;
    ARS_OD_Orientation_Obj_14_IDT ARS_OD_Orientation_Obj_14;
    ARS_OD_YawRateAbs_Obj_14_IDT ARS_OD_YawRateAbs_Obj_14;
    ARS_OD_YawRateAbsStd_Obj_14_IDT ARS_OD_YawRateAbsStd_Obj_14;
    ARS_OD_RefPoint_Obj_14_IDT ARS_OD_RefPoint_Obj_14;
    ARS_OD_LifeCycle_Obj_14_IDT ARS_OD_LifeCycle_Obj_14;
    ARS_OD_DistX_Obj_15_IDT ARS_OD_DistX_Obj_15;
    ARS_OD_VabsX_Obj_15_IDT ARS_OD_VabsX_Obj_15;
    ARS_OD_AabsX_Obj_15_IDT ARS_OD_AabsX_Obj_15;
    ARS_OD_AabsX_Obj_14_IDT ARS_OD_AabsX_Obj_14;
    ARS_OD_DistY_Obj_15_IDT ARS_OD_DistY_Obj_15;
    ARS_OD_VabsY_Obj_15_IDT ARS_OD_VabsY_Obj_15;
    ARS_OD_AabsY_Obj_15_IDT ARS_OD_AabsY_Obj_15;
    ARS_OD_DistXStd_Obj_15_IDT ARS_OD_DistXStd_Obj_15;
    ARS_OD_DistYStd_Obj_15_IDT ARS_OD_DistYStd_Obj_15;
    ARS_OD_VabsXStd_Obj_15_IDT ARS_OD_VabsXStd_Obj_15;
    ARS_OD_VabsYStd_Obj_15_IDT ARS_OD_VabsYStd_Obj_15;
    ARS_OD_AabsXStd_Obj_15_IDT ARS_OD_AabsXStd_Obj_15;
    ARS_OD_Classification_Obj_15_IDT ARS_OD_Classification_Obj_15;
    ARS_OD_AabsYStd_Obj_15_IDT ARS_OD_AabsYStd_Obj_15;
    ARS_OD_ClassConf_Obj_15_IDT ARS_OD_ClassConf_Obj_15;
    ARS_OD_DistY_Obj_14_IDT ARS_OD_DistY_Obj_14;
    ARS_OD_ProbOfExist_Obj_15_IDT ARS_OD_ProbOfExist_Obj_15;
    ARS_OD_DynConf_Obj_15_IDT ARS_OD_DynConf_Obj_15;
    ARS_OD_DynProp_Obj_15_IDT ARS_OD_DynProp_Obj_15;
    ARS_OD_MirrorProb_Obj_15_IDT ARS_OD_MirrorProb_Obj_15;
    ARS_OD_Length_Obj_15_IDT ARS_OD_Length_Obj_15;
    ARS_OD_MaintenanceState_Obj_15_IDT ARS_OD_MaintenanceState_Obj_15;
    ARS_OD_Width_Obj_15_IDT ARS_OD_Width_Obj_15;
    ARS_OD_RCS_Obj_15_IDT ARS_OD_RCS_Obj_15;
    ARS_OD_Orientation_Obj_15_IDT ARS_OD_Orientation_Obj_15;
    ARS_OD_YawRateAbs_Obj_15_IDT ARS_OD_YawRateAbs_Obj_15;
    ARS_OD_YawRateAbsStd_Obj_15_IDT ARS_OD_YawRateAbsStd_Obj_15;
    ARS_OD_RefPoint_Obj_15_IDT ARS_OD_RefPoint_Obj_15;
    ARS_OD_LifeCycle_Obj_15_IDT ARS_OD_LifeCycle_Obj_15;
    ARS_OD_OrientationStd_Obj_14_IDT ARS_OD_OrientationStd_Obj_14;
    ARS_OD_OrientationStd_Obj_15_IDT ARS_OD_OrientationStd_Obj_15;
    ARS_OD_ObstacleProb_Obj_14_IDT ARS_OD_ObstacleProb_Obj_14;
    ARS_OD_MicroDopplerFlag_14_IDT ARS_OD_MicroDopplerFlag_14;
    ARS_OD_ObstacleProb_Obj_15_IDT ARS_OD_ObstacleProb_Obj_15;
    ARS_OD_VabsY_Obj_14_IDT ARS_OD_VabsY_Obj_14;
    ARS_OD_MicroDopplerFlag_15_IDT ARS_OD_MicroDopplerFlag_15;
    ARS_OD_ID_14_IDT ARS_OD_ID_14;
    ARS_OD_ID_15_IDT ARS_OD_ID_15;
    ARS_OD_MsgCounter_Obj_14_15_IDT ARS_OD_MsgCounter_Obj_14_15;
    ARS_OD_CRC16_Checksum_Obj_14_15_IDT ARS_OD_CRC16_Checksum_Obj_14_15;
    ARS_OD_AabsY_Obj_14_IDT ARS_OD_AabsY_Obj_14;
    ARS_OD_DistXStd_Obj_14_IDT ARS_OD_DistXStd_Obj_14;
    ARS_OD_DistYStd_Obj_14_IDT ARS_OD_DistYStd_Obj_14;
    ARS_OD_VabsXStd_Obj_14_IDT ARS_OD_VabsXStd_Obj_14;
    ARS_OD_VabsYStd_Obj_14_IDT ARS_OD_VabsYStd_Obj_14;
    ARS_OD_AabsXStd_Obj_14_IDT ARS_OD_AabsXStd_Obj_14;
} Signal_Group_ARS_OD_14_15_IDT;

typedef struct
{
    DistHeight_Obj_17_IDT DistHeight_Obj_17;
    DistHeight_Obj_16_IDT DistHeight_Obj_16;
    ARS_OD_DistX_Obj_16_IDT ARS_OD_DistX_Obj_16;
    ARS_OD_Classification_Obj_16_IDT ARS_OD_Classification_Obj_16;
    ARS_OD_AabsYStd_Obj_16_IDT ARS_OD_AabsYStd_Obj_16;
    ARS_OD_ClassConf_Obj_16_IDT ARS_OD_ClassConf_Obj_16;
    ARS_OD_ProbOfExist_Obj_16_IDT ARS_OD_ProbOfExist_Obj_16;
    ARS_OD_DynConf_Obj_16_IDT ARS_OD_DynConf_Obj_16;
    ARS_OD_VabsX_Obj_16_IDT ARS_OD_VabsX_Obj_16;
    ARS_OD_DynProp_Obj_16_IDT ARS_OD_DynProp_Obj_16;
    ARS_OD_MirrorProb_Obj_16_IDT ARS_OD_MirrorProb_Obj_16;
    ARS_OD_Length_Obj_16_IDT ARS_OD_Length_Obj_16;
    ARS_OD_MaintenanceState_Obj_16_IDT ARS_OD_MaintenanceState_Obj_16;
    ARS_OD_Width_Obj_16_IDT ARS_OD_Width_Obj_16;
    ARS_OD_RCS_Obj_16_IDT ARS_OD_RCS_Obj_16;
    ARS_OD_Orientation_Obj_16_IDT ARS_OD_Orientation_Obj_16;
    ARS_OD_YawRateAbs_Obj_16_IDT ARS_OD_YawRateAbs_Obj_16;
    ARS_OD_YawRateAbsStd_Obj_16_IDT ARS_OD_YawRateAbsStd_Obj_16;
    ARS_OD_RefPoint_Obj_16_IDT ARS_OD_RefPoint_Obj_16;
    ARS_OD_LifeCycle_Obj_16_IDT ARS_OD_LifeCycle_Obj_16;
    ARS_OD_DistX_Obj_17_IDT ARS_OD_DistX_Obj_17;
    ARS_OD_VabsX_Obj_17_IDT ARS_OD_VabsX_Obj_17;
    ARS_OD_AabsX_Obj_17_IDT ARS_OD_AabsX_Obj_17;
    ARS_OD_AabsX_Obj_16_IDT ARS_OD_AabsX_Obj_16;
    ARS_OD_DistY_Obj_17_IDT ARS_OD_DistY_Obj_17;
    ARS_OD_VabsY_Obj_17_IDT ARS_OD_VabsY_Obj_17;
    ARS_OD_AabsY_Obj_17_IDT ARS_OD_AabsY_Obj_17;
    ARS_OD_DistXStd_Obj_17_IDT ARS_OD_DistXStd_Obj_17;
    ARS_OD_DistYStd_Obj_17_IDT ARS_OD_DistYStd_Obj_17;
    ARS_OD_VabsXStd_Obj_17_IDT ARS_OD_VabsXStd_Obj_17;
    ARS_OD_VabsYStd_Obj_17_IDT ARS_OD_VabsYStd_Obj_17;
    ARS_OD_AabsXStd_Obj_17_IDT ARS_OD_AabsXStd_Obj_17;
    ARS_OD_Classification_Obj_17_IDT ARS_OD_Classification_Obj_17;
    ARS_OD_AabsYStd_Obj_17_IDT ARS_OD_AabsYStd_Obj_17;
    ARS_OD_ClassConf_Obj_17_IDT ARS_OD_ClassConf_Obj_17;
    ARS_OD_DistY_Obj_16_IDT ARS_OD_DistY_Obj_16;
    ARS_OD_ProbOfExist_Obj_17_IDT ARS_OD_ProbOfExist_Obj_17;
    ARS_OD_DynConf_Obj_17_IDT ARS_OD_DynConf_Obj_17;
    ARS_OD_DynProp_Obj_17_IDT ARS_OD_DynProp_Obj_17;
    ARS_OD_MirrorProb_Obj_17_IDT ARS_OD_MirrorProb_Obj_17;
    ARS_OD_Length_Obj_17_IDT ARS_OD_Length_Obj_17;
    ARS_OD_MaintenanceState_Obj_17_IDT ARS_OD_MaintenanceState_Obj_17;
    ARS_OD_Width_Obj_17_IDT ARS_OD_Width_Obj_17;
    ARS_OD_RCS_Obj_17_IDT ARS_OD_RCS_Obj_17;
    ARS_OD_Orientation_Obj_17_IDT ARS_OD_Orientation_Obj_17;
    ARS_OD_YawRateAbs_Obj_17_IDT ARS_OD_YawRateAbs_Obj_17;
    ARS_OD_YawRateAbsStd_Obj_17_IDT ARS_OD_YawRateAbsStd_Obj_17;
    ARS_OD_RefPoint_Obj_17_IDT ARS_OD_RefPoint_Obj_17;
    ARS_OD_LifeCycle_Obj_17_IDT ARS_OD_LifeCycle_Obj_17;
    ARS_OD_OrientationStd_Obj_16_IDT ARS_OD_OrientationStd_Obj_16;
    ARS_OD_OrientationStd_Obj_17_IDT ARS_OD_OrientationStd_Obj_17;
    ARS_OD_ObstacleProb_Obj_16_IDT ARS_OD_ObstacleProb_Obj_16;
    ARS_OD_MicroDopplerFlag_16_IDT ARS_OD_MicroDopplerFlag_16;
    ARS_OD_ObstacleProb_Obj_17_IDT ARS_OD_ObstacleProb_Obj_17;
    ARS_OD_VabsY_Obj_16_IDT ARS_OD_VabsY_Obj_16;
    ARS_OD_MicroDopplerFlag_17_IDT ARS_OD_MicroDopplerFlag_17;
    ARS_OD_ID_16_IDT ARS_OD_ID_16;
    ARS_OD_ID_17_IDT ARS_OD_ID_17;
    ARS_OD_MsgCounter_Obj_16_17_IDT ARS_OD_MsgCounter_Obj_16_17;
    ARS_OD_CRC16_Checksum_Obj_16_17_IDT ARS_OD_CRC16_Checksum_Obj_16_17;
    ARS_OD_AabsY_Obj_16_IDT ARS_OD_AabsY_Obj_16;
    ARS_OD_DistXStd_Obj_16_IDT ARS_OD_DistXStd_Obj_16;
    ARS_OD_DistYStd_Obj_16_IDT ARS_OD_DistYStd_Obj_16;
    ARS_OD_VabsXStd_Obj_16_IDT ARS_OD_VabsXStd_Obj_16;
    ARS_OD_VabsYStd_Obj_16_IDT ARS_OD_VabsYStd_Obj_16;
    ARS_OD_AabsXStd_Obj_16_IDT ARS_OD_AabsXStd_Obj_16;
} Signal_Group_ARS_OD_16_17_IDT;

typedef struct
{
    DistHeight_Obj_19_IDT DistHeight_Obj_19;
    DistHeight_Obj_18_IDT DistHeight_Obj_18;
    ARS_OD_DistX_Obj_18_IDT ARS_OD_DistX_Obj_18;
    ARS_OD_Classification_Obj_18_IDT ARS_OD_Classification_Obj_18;
    ARS_OD_AabsYStd_Obj_18_IDT ARS_OD_AabsYStd_Obj_18;
    ARS_OD_ClassConf_Obj_18_IDT ARS_OD_ClassConf_Obj_18;
    ARS_OD_ProbOfExist_Obj_18_IDT ARS_OD_ProbOfExist_Obj_18;
    ARS_OD_DynConf_Obj_18_IDT ARS_OD_DynConf_Obj_18;
    ARS_OD_VabsX_Obj_18_IDT ARS_OD_VabsX_Obj_18;
    ARS_OD_DynProp_Obj_18_IDT ARS_OD_DynProp_Obj_18;
    ARS_OD_MirrorProb_Obj_18_IDT ARS_OD_MirrorProb_Obj_18;
    ARS_OD_Length_Obj_18_IDT ARS_OD_Length_Obj_18;
    ARS_OD_MaintenanceState_Obj_18_IDT ARS_OD_MaintenanceState_Obj_18;
    ARS_OD_Width_Obj_18_IDT ARS_OD_Width_Obj_18;
    ARS_OD_RCS_Obj_18_IDT ARS_OD_RCS_Obj_18;
    ARS_OD_Orientation_Obj_18_IDT ARS_OD_Orientation_Obj_18;
    ARS_OD_YawRateAbs_Obj_18_IDT ARS_OD_YawRateAbs_Obj_18;
    ARS_OD_YawRateAbsStd_Obj_18_IDT ARS_OD_YawRateAbsStd_Obj_18;
    ARS_OD_RefPoint_Obj_18_IDT ARS_OD_RefPoint_Obj_18;
    ARS_OD_LifeCycle_Obj_18_IDT ARS_OD_LifeCycle_Obj_18;
    ARS_OD_DistX_Obj_19_IDT ARS_OD_DistX_Obj_19;
    ARS_OD_VabsX_Obj_19_IDT ARS_OD_VabsX_Obj_19;
    ARS_OD_AabsX_Obj_19_IDT ARS_OD_AabsX_Obj_19;
    ARS_OD_AabsX_Obj_18_IDT ARS_OD_AabsX_Obj_18;
    ARS_OD_DistY_Obj_19_IDT ARS_OD_DistY_Obj_19;
    ARS_OD_VabsY_Obj_19_IDT ARS_OD_VabsY_Obj_19;
    ARS_OD_AabsY_Obj_19_IDT ARS_OD_AabsY_Obj_19;
    ARS_OD_DistXStd_Obj_19_IDT ARS_OD_DistXStd_Obj_19;
    ARS_OD_DistYStd_Obj_19_IDT ARS_OD_DistYStd_Obj_19;
    ARS_OD_VabsXStd_Obj_19_IDT ARS_OD_VabsXStd_Obj_19;
    ARS_OD_VabsYStd_Obj_19_IDT ARS_OD_VabsYStd_Obj_19;
    ARS_OD_AabsXStd_Obj_19_IDT ARS_OD_AabsXStd_Obj_19;
    ARS_OD_Classification_Obj_19_IDT ARS_OD_Classification_Obj_19;
    ARS_OD_AabsYStd_Obj_19_IDT ARS_OD_AabsYStd_Obj_19;
    ARS_OD_ClassConf_Obj_19_IDT ARS_OD_ClassConf_Obj_19;
    ARS_OD_DistY_Obj_18_IDT ARS_OD_DistY_Obj_18;
    ARS_OD_ProbOfExist_Obj_19_IDT ARS_OD_ProbOfExist_Obj_19;
    ARS_OD_DynConf_Obj_19_IDT ARS_OD_DynConf_Obj_19;
    ARS_OD_DynProp_Obj_19_IDT ARS_OD_DynProp_Obj_19;
    ARS_OD_MirrorProb_Obj_19_IDT ARS_OD_MirrorProb_Obj_19;
    ARS_OD_Length_Obj_19_IDT ARS_OD_Length_Obj_19;
    ARS_OD_MaintenanceState_Obj_19_IDT ARS_OD_MaintenanceState_Obj_19;
    ARS_OD_Width_Obj_19_IDT ARS_OD_Width_Obj_19;
    ARS_OD_RCS_Obj_19_IDT ARS_OD_RCS_Obj_19;
    ARS_OD_Orientation_Obj_19_IDT ARS_OD_Orientation_Obj_19;
    ARS_OD_YawRateAbs_Obj_19_IDT ARS_OD_YawRateAbs_Obj_19;
    ARS_OD_YawRateAbsStd_Obj_19_IDT ARS_OD_YawRateAbsStd_Obj_19;
    ARS_OD_RefPoint_Obj_19_IDT ARS_OD_RefPoint_Obj_19;
    ARS_OD_LifeCycle_Obj_19_IDT ARS_OD_LifeCycle_Obj_19;
    ARS_OD_OrientationStd_Obj_18_IDT ARS_OD_OrientationStd_Obj_18;
    ARS_OD_OrientationStd_Obj_19_IDT ARS_OD_OrientationStd_Obj_19;
    ARS_OD_ObstacleProb_Obj_18_IDT ARS_OD_ObstacleProb_Obj_18;
    ARS_OD_MicroDopplerFlag_18_IDT ARS_OD_MicroDopplerFlag_18;
    ARS_OD_ObstacleProb_Obj_19_IDT ARS_OD_ObstacleProb_Obj_19;
    ARS_OD_VabsY_Obj_18_IDT ARS_OD_VabsY_Obj_18;
    ARS_OD_MicroDopplerFlag_19_IDT ARS_OD_MicroDopplerFlag_19;
    ARS_OD_ID_18_IDT ARS_OD_ID_18;
    ARS_OD_ID_19_IDT ARS_OD_ID_19;
    ARS_OD_MsgCounter_Obj_18_19_IDT ARS_OD_MsgCounter_Obj_18_19;
    ARS_OD_CRC16_Checksum_Obj_18_19_IDT ARS_OD_CRC16_Checksum_Obj_18_19;
    ARS_OD_AabsY_Obj_18_IDT ARS_OD_AabsY_Obj_18;
    ARS_OD_DistXStd_Obj_18_IDT ARS_OD_DistXStd_Obj_18;
    ARS_OD_DistYStd_Obj_18_IDT ARS_OD_DistYStd_Obj_18;
    ARS_OD_VabsXStd_Obj_18_IDT ARS_OD_VabsXStd_Obj_18;
    ARS_OD_VabsYStd_Obj_18_IDT ARS_OD_VabsYStd_Obj_18;
    ARS_OD_AabsXStd_Obj_18_IDT ARS_OD_AabsXStd_Obj_18;
} Signal_Group_ARS_OD_18_19_IDT;

typedef struct
{
    DistHeight_Obj_21_IDT DistHeight_Obj_21;
    DistHeight_Obj_20_IDT DistHeight_Obj_20;
    ARS_OD_DistX_Obj_20_IDT ARS_OD_DistX_Obj_20;
    ARS_OD_Classification_Obj_20_IDT ARS_OD_Classification_Obj_20;
    ARS_OD_AabsYStd_Obj_20_IDT ARS_OD_AabsYStd_Obj_20;
    ARS_OD_ClassConf_Obj_20_IDT ARS_OD_ClassConf_Obj_20;
    ARS_OD_ProbOfExist_Obj_20_IDT ARS_OD_ProbOfExist_Obj_20;
    ARS_OD_DynConf_Obj_20_IDT ARS_OD_DynConf_Obj_20;
    ARS_OD_VabsX_Obj_20_IDT ARS_OD_VabsX_Obj_20;
    ARS_OD_DynProp_Obj_20_IDT ARS_OD_DynProp_Obj_20;
    ARS_OD_MirrorProb_Obj_20_IDT ARS_OD_MirrorProb_Obj_20;
    ARS_OD_Length_Obj_20_IDT ARS_OD_Length_Obj_20;
    ARS_OD_MaintenanceState_Obj_20_IDT ARS_OD_MaintenanceState_Obj_20;
    ARS_OD_Width_Obj_20_IDT ARS_OD_Width_Obj_20;
    ARS_OD_RCS_Obj_20_IDT ARS_OD_RCS_Obj_20;
    ARS_OD_Orientation_Obj_20_IDT ARS_OD_Orientation_Obj_20;
    ARS_OD_YawRateAbs_Obj_20_IDT ARS_OD_YawRateAbs_Obj_20;
    ARS_OD_YawRateAbsStd_Obj_20_IDT ARS_OD_YawRateAbsStd_Obj_20;
    ARS_OD_RefPoint_Obj_20_IDT ARS_OD_RefPoint_Obj_20;
    ARS_OD_LifeCycle_Obj_20_IDT ARS_OD_LifeCycle_Obj_20;
    ARS_OD_DistX_Obj_21_IDT ARS_OD_DistX_Obj_21;
    ARS_OD_VabsX_Obj_21_IDT ARS_OD_VabsX_Obj_21;
    ARS_OD_AabsX_Obj_21_IDT ARS_OD_AabsX_Obj_21;
    ARS_OD_AabsX_Obj_20_IDT ARS_OD_AabsX_Obj_20;
    ARS_OD_DistY_Obj_21_IDT ARS_OD_DistY_Obj_21;
    ARS_OD_VabsY_Obj_21_IDT ARS_OD_VabsY_Obj_21;
    ARS_OD_AabsY_Obj_21_IDT ARS_OD_AabsY_Obj_21;
    ARS_OD_DistXStd_Obj_21_IDT ARS_OD_DistXStd_Obj_21;
    ARS_OD_DistYStd_Obj_21_IDT ARS_OD_DistYStd_Obj_21;
    ARS_OD_VabsXStd_Obj_21_IDT ARS_OD_VabsXStd_Obj_21;
    ARS_OD_VabsYStd_Obj_21_IDT ARS_OD_VabsYStd_Obj_21;
    ARS_OD_AabsXStd_Obj_21_IDT ARS_OD_AabsXStd_Obj_21;
    ARS_OD_Classification_Obj_21_IDT ARS_OD_Classification_Obj_21;
    ARS_OD_AabsYStd_Obj_21_IDT ARS_OD_AabsYStd_Obj_21;
    ARS_OD_ClassConf_Obj_21_IDT ARS_OD_ClassConf_Obj_21;
    ARS_OD_DistY_Obj_20_IDT ARS_OD_DistY_Obj_20;
    ARS_OD_ProbOfExist_Obj_21_IDT ARS_OD_ProbOfExist_Obj_21;
    ARS_OD_DynConf_Obj_21_IDT ARS_OD_DynConf_Obj_21;
    ARS_OD_DynProp_Obj_21_IDT ARS_OD_DynProp_Obj_21;
    ARS_OD_MirrorProb_Obj_21_IDT ARS_OD_MirrorProb_Obj_21;
    ARS_OD_Length_Obj_21_IDT ARS_OD_Length_Obj_21;
    ARS_OD_MaintenanceState_Obj_21_IDT ARS_OD_MaintenanceState_Obj_21;
    ARS_OD_Width_Obj_21_IDT ARS_OD_Width_Obj_21;
    ARS_OD_RCS_Obj_21_IDT ARS_OD_RCS_Obj_21;
    ARS_OD_Orientation_Obj_21_IDT ARS_OD_Orientation_Obj_21;
    ARS_OD_YawRateAbs_Obj_21_IDT ARS_OD_YawRateAbs_Obj_21;
    ARS_OD_YawRateAbsStd_Obj_21_IDT ARS_OD_YawRateAbsStd_Obj_21;
    ARS_OD_RefPoint_Obj_21_IDT ARS_OD_RefPoint_Obj_21;
    ARS_OD_LifeCycle_Obj_21_IDT ARS_OD_LifeCycle_Obj_21;
    ARS_OD_OrientationStd_Obj_20_IDT ARS_OD_OrientationStd_Obj_20;
    ARS_OD_OrientationStd_Obj_21_IDT ARS_OD_OrientationStd_Obj_21;
    ARS_OD_ObstacleProb_Obj_20_IDT ARS_OD_ObstacleProb_Obj_20;
    ARS_OD_MicroDopplerFlag_20_IDT ARS_OD_MicroDopplerFlag_20;
    ARS_OD_ObstacleProb_Obj_21_IDT ARS_OD_ObstacleProb_Obj_21;
    ARS_OD_VabsY_Obj_20_IDT ARS_OD_VabsY_Obj_20;
    ARS_OD_MicroDopplerFlag_21_IDT ARS_OD_MicroDopplerFlag_21;
    ARS_OD_ID_20_IDT ARS_OD_ID_20;
    ARS_OD_ID_21_IDT ARS_OD_ID_21;
    ARS_OD_MsgCounter_Obj_20_21_IDT ARS_OD_MsgCounter_Obj_20_21;
    ARS_OD_CRC16_Checksum_Obj_20_21_IDT ARS_OD_CRC16_Checksum_Obj_20_21;
    ARS_OD_AabsY_Obj_20_IDT ARS_OD_AabsY_Obj_20;
    ARS_OD_DistXStd_Obj_20_IDT ARS_OD_DistXStd_Obj_20;
    ARS_OD_DistYStd_Obj_20_IDT ARS_OD_DistYStd_Obj_20;
    ARS_OD_VabsXStd_Obj_20_IDT ARS_OD_VabsXStd_Obj_20;
    ARS_OD_VabsYStd_Obj_20_IDT ARS_OD_VabsYStd_Obj_20;
    ARS_OD_AabsXStd_Obj_20_IDT ARS_OD_AabsXStd_Obj_20;
} Signal_Group_ARS_OD_20_21_IDT;

typedef struct
{
    DistHeight_Obj_23_IDT DistHeight_Obj_23;
    DistHeight_Obj_22_IDT DistHeight_Obj_22;
    ARS_OD_DistX_Obj_22_IDT ARS_OD_DistX_Obj_22;
    ARS_OD_Classification_Obj_22_IDT ARS_OD_Classification_Obj_22;
    ARS_OD_AabsYStd_Obj_22_IDT ARS_OD_AabsYStd_Obj_22;
    ARS_OD_ClassConf_Obj_22_IDT ARS_OD_ClassConf_Obj_22;
    ARS_OD_ProbOfExist_Obj_22_IDT ARS_OD_ProbOfExist_Obj_22;
    ARS_OD_DynConf_Obj_22_IDT ARS_OD_DynConf_Obj_22;
    ARS_OD_VabsX_Obj_22_IDT ARS_OD_VabsX_Obj_22;
    ARS_OD_DynProp_Obj_22_IDT ARS_OD_DynProp_Obj_22;
    ARS_OD_MirrorProb_Obj_22_IDT ARS_OD_MirrorProb_Obj_22;
    ARS_OD_Length_Obj_22_IDT ARS_OD_Length_Obj_22;
    ARS_OD_MaintenanceState_Obj_22_IDT ARS_OD_MaintenanceState_Obj_22;
    ARS_OD_Width_Obj_22_IDT ARS_OD_Width_Obj_22;
    ARS_OD_RCS_Obj_22_IDT ARS_OD_RCS_Obj_22;
    ARS_OD_Orientation_Obj_22_IDT ARS_OD_Orientation_Obj_22;
    ARS_OD_YawRateAbs_Obj_22_IDT ARS_OD_YawRateAbs_Obj_22;
    ARS_OD_YawRateAbsStd_Obj_22_IDT ARS_OD_YawRateAbsStd_Obj_22;
    ARS_OD_RefPoint_Obj_22_IDT ARS_OD_RefPoint_Obj_22;
    ARS_OD_LifeCycle_Obj_22_IDT ARS_OD_LifeCycle_Obj_22;
    ARS_OD_DistX_Obj_23_IDT ARS_OD_DistX_Obj_23;
    ARS_OD_VabsX_Obj_23_IDT ARS_OD_VabsX_Obj_23;
    ARS_OD_AabsX_Obj_23_IDT ARS_OD_AabsX_Obj_23;
    ARS_OD_AabsX_Obj_22_IDT ARS_OD_AabsX_Obj_22;
    ARS_OD_DistY_Obj_23_IDT ARS_OD_DistY_Obj_23;
    ARS_OD_VabsY_Obj_23_IDT ARS_OD_VabsY_Obj_23;
    ARS_OD_AabsY_Obj_23_IDT ARS_OD_AabsY_Obj_23;
    ARS_OD_DistXStd_Obj_23_IDT ARS_OD_DistXStd_Obj_23;
    ARS_OD_DistYStd_Obj_23_IDT ARS_OD_DistYStd_Obj_23;
    ARS_OD_VabsXStd_Obj_23_IDT ARS_OD_VabsXStd_Obj_23;
    ARS_OD_VabsYStd_Obj_23_IDT ARS_OD_VabsYStd_Obj_23;
    ARS_OD_AabsXStd_Obj_23_IDT ARS_OD_AabsXStd_Obj_23;
    ARS_OD_Classification_Obj_23_IDT ARS_OD_Classification_Obj_23;
    ARS_OD_AabsYStd_Obj_23_IDT ARS_OD_AabsYStd_Obj_23;
    ARS_OD_ClassConf_Obj_23_IDT ARS_OD_ClassConf_Obj_23;
    ARS_OD_DistY_Obj_22_IDT ARS_OD_DistY_Obj_22;
    ARS_OD_ProbOfExist_Obj_23_IDT ARS_OD_ProbOfExist_Obj_23;
    ARS_OD_DynConf_Obj_23_IDT ARS_OD_DynConf_Obj_23;
    ARS_OD_DynProp_Obj_23_IDT ARS_OD_DynProp_Obj_23;
    ARS_OD_MirrorProb_Obj_23_IDT ARS_OD_MirrorProb_Obj_23;
    ARS_OD_Length_Obj_23_IDT ARS_OD_Length_Obj_23;
    ARS_OD_MaintenanceState_Obj_23_IDT ARS_OD_MaintenanceState_Obj_23;
    ARS_OD_Width_Obj_23_IDT ARS_OD_Width_Obj_23;
    ARS_OD_RCS_Obj_23_IDT ARS_OD_RCS_Obj_23;
    ARS_OD_Orientation_Obj_23_IDT ARS_OD_Orientation_Obj_23;
    ARS_OD_YawRateAbs_Obj_23_IDT ARS_OD_YawRateAbs_Obj_23;
    ARS_OD_YawRateAbsStd_Obj_23_IDT ARS_OD_YawRateAbsStd_Obj_23;
    ARS_OD_RefPoint_Obj_23_IDT ARS_OD_RefPoint_Obj_23;
    ARS_OD_LifeCycle_Obj_23_IDT ARS_OD_LifeCycle_Obj_23;
    ARS_OD_OrientationStd_Obj_22_IDT ARS_OD_OrientationStd_Obj_22;
    ARS_OD_OrientationStd_Obj_23_IDT ARS_OD_OrientationStd_Obj_23;
    ARS_OD_ObstacleProb_Obj_22_IDT ARS_OD_ObstacleProb_Obj_22;
    ARS_OD_MicroDopplerFlag_22_IDT ARS_OD_MicroDopplerFlag_22;
    ARS_OD_ObstacleProb_Obj_23_IDT ARS_OD_ObstacleProb_Obj_23;
    ARS_OD_VabsY_Obj_22_IDT ARS_OD_VabsY_Obj_22;
    ARS_OD_MicroDopplerFlag_23_IDT ARS_OD_MicroDopplerFlag_23;
    ARS_OD_ID_22_IDT ARS_OD_ID_22;
    ARS_OD_ID_23_IDT ARS_OD_ID_23;
    ARS_OD_MsgCounter_Obj_22_23_IDT ARS_OD_MsgCounter_Obj_22_23;
    ARS_OD_CRC16_Checksum_Obj_22_23_IDT ARS_OD_CRC16_Checksum_Obj_22_23;
    ARS_OD_AabsY_Obj_22_IDT ARS_OD_AabsY_Obj_22;
    ARS_OD_DistXStd_Obj_22_IDT ARS_OD_DistXStd_Obj_22;
    ARS_OD_DistYStd_Obj_22_IDT ARS_OD_DistYStd_Obj_22;
    ARS_OD_VabsXStd_Obj_22_IDT ARS_OD_VabsXStd_Obj_22;
    ARS_OD_VabsYStd_Obj_22_IDT ARS_OD_VabsYStd_Obj_22;
    ARS_OD_AabsXStd_Obj_22_IDT ARS_OD_AabsXStd_Obj_22;
} Signal_Group_ARS_OD_22_23_IDT;

typedef struct
{
    DistHeight_Obj_25_IDT DistHeight_Obj_25;
    DistHeight_Obj_24_IDT DistHeight_Obj_24;
    ARS_OD_DistX_Obj_24_IDT ARS_OD_DistX_Obj_24;
    ARS_OD_Classification_Obj_24_IDT ARS_OD_Classification_Obj_24;
    ARS_OD_AabsYStd_Obj_24_IDT ARS_OD_AabsYStd_Obj_24;
    ARS_OD_ClassConf_Obj_24_IDT ARS_OD_ClassConf_Obj_24;
    ARS_OD_ProbOfExist_Obj_24_IDT ARS_OD_ProbOfExist_Obj_24;
    ARS_OD_DynConf_Obj_24_IDT ARS_OD_DynConf_Obj_24;
    ARS_OD_VabsX_Obj_24_IDT ARS_OD_VabsX_Obj_24;
    ARS_OD_DynProp_Obj_24_IDT ARS_OD_DynProp_Obj_24;
    ARS_OD_MirrorProb_Obj_24_IDT ARS_OD_MirrorProb_Obj_24;
    ARS_OD_Length_Obj_24_IDT ARS_OD_Length_Obj_24;
    ARS_OD_MaintenanceState_Obj_24_IDT ARS_OD_MaintenanceState_Obj_24;
    ARS_OD_Width_Obj_24_IDT ARS_OD_Width_Obj_24;
    ARS_OD_RCS_Obj_24_IDT ARS_OD_RCS_Obj_24;
    ARS_OD_Orientation_Obj_24_IDT ARS_OD_Orientation_Obj_24;
    ARS_OD_YawRateAbs_Obj_24_IDT ARS_OD_YawRateAbs_Obj_24;
    ARS_OD_YawRateAbsStd_Obj_24_IDT ARS_OD_YawRateAbsStd_Obj_24;
    ARS_OD_RefPoint_Obj_24_IDT ARS_OD_RefPoint_Obj_24;
    ARS_OD_LifeCycle_Obj_24_IDT ARS_OD_LifeCycle_Obj_24;
    ARS_OD_DistX_Obj_25_IDT ARS_OD_DistX_Obj_25;
    ARS_OD_VabsX_Obj_25_IDT ARS_OD_VabsX_Obj_25;
    ARS_OD_AabsX_Obj_25_IDT ARS_OD_AabsX_Obj_25;
    ARS_OD_AabsX_Obj_24_IDT ARS_OD_AabsX_Obj_24;
    ARS_OD_DistY_Obj_25_IDT ARS_OD_DistY_Obj_25;
    ARS_OD_VabsY_Obj_25_IDT ARS_OD_VabsY_Obj_25;
    ARS_OD_AabsY_Obj_25_IDT ARS_OD_AabsY_Obj_25;
    ARS_OD_DistXStd_Obj_25_IDT ARS_OD_DistXStd_Obj_25;
    ARS_OD_DistYStd_Obj_25_IDT ARS_OD_DistYStd_Obj_25;
    ARS_OD_VabsXStd_Obj_25_IDT ARS_OD_VabsXStd_Obj_25;
    ARS_OD_VabsYStd_Obj_25_IDT ARS_OD_VabsYStd_Obj_25;
    ARS_OD_AabsXStd_Obj_25_IDT ARS_OD_AabsXStd_Obj_25;
    ARS_OD_Classification_Obj_25_IDT ARS_OD_Classification_Obj_25;
    ARS_OD_AabsYStd_Obj_25_IDT ARS_OD_AabsYStd_Obj_25;
    ARS_OD_ClassConf_Obj_25_IDT ARS_OD_ClassConf_Obj_25;
    ARS_OD_DistY_Obj_24_IDT ARS_OD_DistY_Obj_24;
    ARS_OD_ProbOfExist_Obj_25_IDT ARS_OD_ProbOfExist_Obj_25;
    ARS_OD_DynConf_Obj_25_IDT ARS_OD_DynConf_Obj_25;
    ARS_OD_DynProp_Obj_25_IDT ARS_OD_DynProp_Obj_25;
    ARS_OD_MirrorProb_Obj_25_IDT ARS_OD_MirrorProb_Obj_25;
    ARS_OD_Length_Obj_25_IDT ARS_OD_Length_Obj_25;
    ARS_OD_MaintenanceState_Obj_25_IDT ARS_OD_MaintenanceState_Obj_25;
    ARS_OD_Width_Obj_25_IDT ARS_OD_Width_Obj_25;
    ARS_OD_RCS_Obj_25_IDT ARS_OD_RCS_Obj_25;
    ARS_OD_Orientation_Obj_25_IDT ARS_OD_Orientation_Obj_25;
    ARS_OD_YawRateAbs_Obj_25_IDT ARS_OD_YawRateAbs_Obj_25;
    ARS_OD_YawRateAbsStd_Obj_25_IDT ARS_OD_YawRateAbsStd_Obj_25;
    ARS_OD_RefPoint_Obj_25_IDT ARS_OD_RefPoint_Obj_25;
    ARS_OD_LifeCycle_Obj_25_IDT ARS_OD_LifeCycle_Obj_25;
    ARS_OD_OrientationStd_Obj_24_IDT ARS_OD_OrientationStd_Obj_24;
    ARS_OD_OrientationStd_Obj_25_IDT ARS_OD_OrientationStd_Obj_25;
    ARS_OD_ObstacleProb_Obj_24_IDT ARS_OD_ObstacleProb_Obj_24;
    ARS_OD_MicroDopplerFlag_24_IDT ARS_OD_MicroDopplerFlag_24;
    ARS_OD_ObstacleProb_Obj_25_IDT ARS_OD_ObstacleProb_Obj_25;
    ARS_OD_VabsY_Obj_24_IDT ARS_OD_VabsY_Obj_24;
    ARS_OD_MicroDopplerFlag_25_IDT ARS_OD_MicroDopplerFlag_25;
    ARS_OD_ID_24_IDT ARS_OD_ID_24;
    ARS_OD_ID_25_IDT ARS_OD_ID_25;
    ARS_OD_MsgCounter_Obj_24_25_IDT ARS_OD_MsgCounter_Obj_24_25;
    ARS_OD_CRC16_Checksum_Obj_24_25_IDT ARS_OD_CRC16_Checksum_Obj_24_25;
    ARS_OD_AabsY_Obj_24_IDT ARS_OD_AabsY_Obj_24;
    ARS_OD_DistXStd_Obj_24_IDT ARS_OD_DistXStd_Obj_24;
    ARS_OD_DistYStd_Obj_24_IDT ARS_OD_DistYStd_Obj_24;
    ARS_OD_VabsXStd_Obj_24_IDT ARS_OD_VabsXStd_Obj_24;
    ARS_OD_VabsYStd_Obj_24_IDT ARS_OD_VabsYStd_Obj_24;
    ARS_OD_AabsXStd_Obj_24_IDT ARS_OD_AabsXStd_Obj_24;
} Signal_Group_ARS_OD_24_25_IDT;

typedef struct
{
    DistHeight_Obj_27_IDT DistHeight_Obj_27;
    DistHeight_Obj_26_IDT DistHeight_Obj_26;
    ARS_OD_DistX_Obj_26_IDT ARS_OD_DistX_Obj_26;
    ARS_OD_Classification_Obj_26_IDT ARS_OD_Classification_Obj_26;
    ARS_OD_AabsYStd_Obj_26_IDT ARS_OD_AabsYStd_Obj_26;
    ARS_OD_ClassConf_Obj_26_IDT ARS_OD_ClassConf_Obj_26;
    ARS_OD_ProbOfExist_Obj_26_IDT ARS_OD_ProbOfExist_Obj_26;
    ARS_OD_DynConf_Obj_26_IDT ARS_OD_DynConf_Obj_26;
    ARS_OD_VabsX_Obj_26_IDT ARS_OD_VabsX_Obj_26;
    ARS_OD_DynProp_Obj_26_IDT ARS_OD_DynProp_Obj_26;
    ARS_OD_MirrorProb_Obj_26_IDT ARS_OD_MirrorProb_Obj_26;
    ARS_OD_Length_Obj_26_IDT ARS_OD_Length_Obj_26;
    ARS_OD_MaintenanceState_Obj_26_IDT ARS_OD_MaintenanceState_Obj_26;
    ARS_OD_Width_Obj_26_IDT ARS_OD_Width_Obj_26;
    ARS_OD_RCS_Obj_26_IDT ARS_OD_RCS_Obj_26;
    ARS_OD_Orientation_Obj_26_IDT ARS_OD_Orientation_Obj_26;
    ARS_OD_YawRateAbs_Obj_26_IDT ARS_OD_YawRateAbs_Obj_26;
    ARS_OD_YawRateAbsStd_Obj_26_IDT ARS_OD_YawRateAbsStd_Obj_26;
    ARS_OD_RefPoint_Obj_26_IDT ARS_OD_RefPoint_Obj_26;
    ARS_OD_LifeCycle_Obj_26_IDT ARS_OD_LifeCycle_Obj_26;
    ARS_OD_DistX_Obj_27_IDT ARS_OD_DistX_Obj_27;
    ARS_OD_VabsX_Obj_27_IDT ARS_OD_VabsX_Obj_27;
    ARS_OD_AabsX_Obj_27_IDT ARS_OD_AabsX_Obj_27;
    ARS_OD_AabsX_Obj_26_IDT ARS_OD_AabsX_Obj_26;
    ARS_OD_DistY_Obj_27_IDT ARS_OD_DistY_Obj_27;
    ARS_OD_VabsY_Obj_27_IDT ARS_OD_VabsY_Obj_27;
    ARS_OD_AabsY_Obj_27_IDT ARS_OD_AabsY_Obj_27;
    ARS_OD_DistXStd_Obj_27_IDT ARS_OD_DistXStd_Obj_27;
    ARS_OD_DistYStd_Obj_27_IDT ARS_OD_DistYStd_Obj_27;
    ARS_OD_VabsXStd_Obj_27_IDT ARS_OD_VabsXStd_Obj_27;
    ARS_OD_VabsYStd_Obj_27_IDT ARS_OD_VabsYStd_Obj_27;
    ARS_OD_AabsXStd_Obj_27_IDT ARS_OD_AabsXStd_Obj_27;
    ARS_OD_Classification_Obj_27_IDT ARS_OD_Classification_Obj_27;
    ARS_OD_AabsYStd_Obj_27_IDT ARS_OD_AabsYStd_Obj_27;
    ARS_OD_ClassConf_Obj_27_IDT ARS_OD_ClassConf_Obj_27;
    ARS_OD_DistY_Obj_26_IDT ARS_OD_DistY_Obj_26;
    ARS_OD_ProbOfExist_Obj_27_IDT ARS_OD_ProbOfExist_Obj_27;
    ARS_OD_DynConf_Obj_27_IDT ARS_OD_DynConf_Obj_27;
    ARS_OD_DynProp_Obj_27_IDT ARS_OD_DynProp_Obj_27;
    ARS_OD_MirrorProb_Obj_27_IDT ARS_OD_MirrorProb_Obj_27;
    ARS_OD_Length_Obj_27_IDT ARS_OD_Length_Obj_27;
    ARS_OD_MaintenanceState_Obj_27_IDT ARS_OD_MaintenanceState_Obj_27;
    ARS_OD_Width_Obj_27_IDT ARS_OD_Width_Obj_27;
    ARS_OD_RCS_Obj_27_IDT ARS_OD_RCS_Obj_27;
    ARS_OD_Orientation_Obj_27_IDT ARS_OD_Orientation_Obj_27;
    ARS_OD_YawRateAbs_Obj_27_IDT ARS_OD_YawRateAbs_Obj_27;
    ARS_OD_YawRateAbsStd_Obj_27_IDT ARS_OD_YawRateAbsStd_Obj_27;
    ARS_OD_RefPoint_Obj_27_IDT ARS_OD_RefPoint_Obj_27;
    ARS_OD_LifeCycle_Obj_27_IDT ARS_OD_LifeCycle_Obj_27;
    ARS_OD_OrientationStd_Obj_26_IDT ARS_OD_OrientationStd_Obj_26;
    ARS_OD_OrientationStd_Obj_27_IDT ARS_OD_OrientationStd_Obj_27;
    ARS_OD_ObstacleProb_Obj_26_IDT ARS_OD_ObstacleProb_Obj_26;
    ARS_OD_MicroDopplerFlag_26_IDT ARS_OD_MicroDopplerFlag_26;
    ARS_OD_ObstacleProb_Obj_27_IDT ARS_OD_ObstacleProb_Obj_27;
    ARS_OD_VabsY_Obj_26_IDT ARS_OD_VabsY_Obj_26;
    ARS_OD_MicroDopplerFlag_27_IDT ARS_OD_MicroDopplerFlag_27;
    ARS_OD_ID_26_IDT ARS_OD_ID_26;
    ARS_OD_ID_27_IDT ARS_OD_ID_27;
    ARS_OD_MsgCounter_Obj_26_27_IDT ARS_OD_MsgCounter_Obj_26_27;
    ARS_OD_CRC16_Checksum_Obj_26_27_IDT ARS_OD_CRC16_Checksum_Obj_26_27;
    ARS_OD_AabsY_Obj_26_IDT ARS_OD_AabsY_Obj_26;
    ARS_OD_DistXStd_Obj_26_IDT ARS_OD_DistXStd_Obj_26;
    ARS_OD_DistYStd_Obj_26_IDT ARS_OD_DistYStd_Obj_26;
    ARS_OD_VabsXStd_Obj_26_IDT ARS_OD_VabsXStd_Obj_26;
    ARS_OD_VabsYStd_Obj_26_IDT ARS_OD_VabsYStd_Obj_26;
    ARS_OD_AabsXStd_Obj_26_IDT ARS_OD_AabsXStd_Obj_26;
} Signal_Group_ARS_OD_26_27_IDT;

typedef struct
{
    DistHeight_Obj_29_IDT DistHeight_Obj_29;
    DistHeight_Obj_28_IDT DistHeight_Obj_28;
    ARS_OD_DistX_Obj_28_IDT ARS_OD_DistX_Obj_28;
    ARS_OD_Classification_Obj_28_IDT ARS_OD_Classification_Obj_28;
    ARS_OD_AabsYStd_Obj_28_IDT ARS_OD_AabsYStd_Obj_28;
    ARS_OD_ClassConf_Obj_28_IDT ARS_OD_ClassConf_Obj_28;
    ARS_OD_ProbOfExist_Obj_28_IDT ARS_OD_ProbOfExist_Obj_28;
    ARS_OD_DynConf_Obj_28_IDT ARS_OD_DynConf_Obj_28;
    ARS_OD_VabsX_Obj_28_IDT ARS_OD_VabsX_Obj_28;
    ARS_OD_DynProp_Obj_28_IDT ARS_OD_DynProp_Obj_28;
    ARS_OD_MirrorProb_Obj_28_IDT ARS_OD_MirrorProb_Obj_28;
    ARS_OD_Length_Obj_28_IDT ARS_OD_Length_Obj_28;
    ARS_OD_MaintenanceState_Obj_28_IDT ARS_OD_MaintenanceState_Obj_28;
    ARS_OD_Width_Obj_28_IDT ARS_OD_Width_Obj_28;
    ARS_OD_RCS_Obj_28_IDT ARS_OD_RCS_Obj_28;
    ARS_OD_Orientation_Obj_28_IDT ARS_OD_Orientation_Obj_28;
    ARS_OD_YawRateAbs_Obj_28_IDT ARS_OD_YawRateAbs_Obj_28;
    ARS_OD_YawRateAbsStd_Obj_28_IDT ARS_OD_YawRateAbsStd_Obj_28;
    ARS_OD_RefPoint_Obj_28_IDT ARS_OD_RefPoint_Obj_28;
    ARS_OD_LifeCycle_Obj_28_IDT ARS_OD_LifeCycle_Obj_28;
    ARS_OD_DistX_Obj_29_IDT ARS_OD_DistX_Obj_29;
    ARS_OD_VabsX_Obj_29_IDT ARS_OD_VabsX_Obj_29;
    ARS_OD_AabsX_Obj_29_IDT ARS_OD_AabsX_Obj_29;
    ARS_OD_AabsX_Obj_28_IDT ARS_OD_AabsX_Obj_28;
    ARS_OD_DistY_Obj_29_IDT ARS_OD_DistY_Obj_29;
    ARS_OD_VabsY_Obj_29_IDT ARS_OD_VabsY_Obj_29;
    ARS_OD_AabsY_Obj_29_IDT ARS_OD_AabsY_Obj_29;
    ARS_OD_DistXStd_Obj_29_IDT ARS_OD_DistXStd_Obj_29;
    ARS_OD_DistYStd_Obj_29_IDT ARS_OD_DistYStd_Obj_29;
    ARS_OD_VabsXStd_Obj_29_IDT ARS_OD_VabsXStd_Obj_29;
    ARS_OD_VabsYStd_Obj_29_IDT ARS_OD_VabsYStd_Obj_29;
    ARS_OD_AabsXStd_Obj_29_IDT ARS_OD_AabsXStd_Obj_29;
    ARS_OD_Classification_Obj_29_IDT ARS_OD_Classification_Obj_29;
    ARS_OD_AabsYStd_Obj_29_IDT ARS_OD_AabsYStd_Obj_29;
    ARS_OD_ClassConf_Obj_29_IDT ARS_OD_ClassConf_Obj_29;
    ARS_OD_DistY_Obj_28_IDT ARS_OD_DistY_Obj_28;
    ARS_OD_ProbOfExist_Obj_29_IDT ARS_OD_ProbOfExist_Obj_29;
    ARS_OD_DynConf_Obj_29_IDT ARS_OD_DynConf_Obj_29;
    ARS_OD_DynProp_Obj_29_IDT ARS_OD_DynProp_Obj_29;
    ARS_OD_MirrorProb_Obj_29_IDT ARS_OD_MirrorProb_Obj_29;
    ARS_OD_Length_Obj_29_IDT ARS_OD_Length_Obj_29;
    ARS_OD_MaintenanceState_Obj_29_IDT ARS_OD_MaintenanceState_Obj_29;
    ARS_OD_Width_Obj_29_IDT ARS_OD_Width_Obj_29;
    ARS_OD_RCS_Obj_29_IDT ARS_OD_RCS_Obj_29;
    ARS_OD_Orientation_Obj_29_IDT ARS_OD_Orientation_Obj_29;
    ARS_OD_YawRateAbs_Obj_29_IDT ARS_OD_YawRateAbs_Obj_29;
    ARS_OD_YawRateAbsStd_Obj_29_IDT ARS_OD_YawRateAbsStd_Obj_29;
    ARS_OD_RefPoint_Obj_29_IDT ARS_OD_RefPoint_Obj_29;
    ARS_OD_LifeCycle_Obj_29_IDT ARS_OD_LifeCycle_Obj_29;
    ARS_OD_OrientationStd_Obj_28_IDT ARS_OD_OrientationStd_Obj_28;
    ARS_OD_OrientationStd_Obj_29_IDT ARS_OD_OrientationStd_Obj_29;
    ARS_OD_ObstacleProb_Obj_28_IDT ARS_OD_ObstacleProb_Obj_28;
    ARS_OD_MicroDopplerFlag_28_IDT ARS_OD_MicroDopplerFlag_28;
    ARS_OD_ObstacleProb_Obj_29_IDT ARS_OD_ObstacleProb_Obj_29;
    ARS_OD_VabsY_Obj_28_IDT ARS_OD_VabsY_Obj_28;
    ARS_OD_MicroDopplerFlag_29_IDT ARS_OD_MicroDopplerFlag_29;
    ARS_OD_ID_28_IDT ARS_OD_ID_28;
    ARS_OD_ID_29_IDT ARS_OD_ID_29;
    ARS_OD_MsgCounter_Obj_28_29_IDT ARS_OD_MsgCounter_Obj_28_29;
    ARS_OD_CRC16_Checksum_Obj_28_29_IDT ARS_OD_CRC16_Checksum_Obj_28_29;
    ARS_OD_AabsY_Obj_28_IDT ARS_OD_AabsY_Obj_28;
    ARS_OD_DistXStd_Obj_28_IDT ARS_OD_DistXStd_Obj_28;
    ARS_OD_DistYStd_Obj_28_IDT ARS_OD_DistYStd_Obj_28;
    ARS_OD_VabsXStd_Obj_28_IDT ARS_OD_VabsXStd_Obj_28;
    ARS_OD_VabsYStd_Obj_28_IDT ARS_OD_VabsYStd_Obj_28;
    ARS_OD_AabsXStd_Obj_28_IDT ARS_OD_AabsXStd_Obj_28;
} Signal_Group_ARS_OD_28_29_IDT;

typedef struct
{
    DistHeight_Obj_31_IDT DistHeight_Obj_31;
    DistHeight_Obj_30_IDT DistHeight_Obj_30;
    ARS_OD_DistX_Obj_30_IDT ARS_OD_DistX_Obj_30;
    ARS_OD_Classification_Obj_30_IDT ARS_OD_Classification_Obj_30;
    ARS_OD_AabsYStd_Obj_30_IDT ARS_OD_AabsYStd_Obj_30;
    ARS_OD_ClassConf_Obj_30_IDT ARS_OD_ClassConf_Obj_30;
    ARS_OD_ProbOfExist_Obj_30_IDT ARS_OD_ProbOfExist_Obj_30;
    ARS_OD_DynConf_Obj_30_IDT ARS_OD_DynConf_Obj_30;
    ARS_OD_VabsX_Obj_30_IDT ARS_OD_VabsX_Obj_30;
    ARS_OD_DynProp_Obj_30_IDT ARS_OD_DynProp_Obj_30;
    ARS_OD_MirrorProb_Obj_30_IDT ARS_OD_MirrorProb_Obj_30;
    ARS_OD_Length_Obj_30_IDT ARS_OD_Length_Obj_30;
    ARS_OD_MaintenanceState_Obj_30_IDT ARS_OD_MaintenanceState_Obj_30;
    ARS_OD_Width_Obj_30_IDT ARS_OD_Width_Obj_30;
    ARS_OD_RCS_Obj_30_IDT ARS_OD_RCS_Obj_30;
    ARS_OD_Orientation_Obj_30_IDT ARS_OD_Orientation_Obj_30;
    ARS_OD_YawRateAbs_Obj_30_IDT ARS_OD_YawRateAbs_Obj_30;
    ARS_OD_YawRateAbsStd_Obj_30_IDT ARS_OD_YawRateAbsStd_Obj_30;
    ARS_OD_RefPoint_Obj_30_IDT ARS_OD_RefPoint_Obj_30;
    ARS_OD_LifeCycle_Obj_30_IDT ARS_OD_LifeCycle_Obj_30;
    ARS_OD_DistX_Obj_31_IDT ARS_OD_DistX_Obj_31;
    ARS_OD_VabsX_Obj_31_IDT ARS_OD_VabsX_Obj_31;
    ARS_OD_AabsX_Obj_31_IDT ARS_OD_AabsX_Obj_31;
    ARS_OD_AabsX_Obj_30_IDT ARS_OD_AabsX_Obj_30;
    ARS_OD_DistY_Obj_31_IDT ARS_OD_DistY_Obj_31;
    ARS_OD_VabsY_Obj_31_IDT ARS_OD_VabsY_Obj_31;
    ARS_OD_AabsY_Obj_31_IDT ARS_OD_AabsY_Obj_31;
    ARS_OD_DistXStd_Obj_31_IDT ARS_OD_DistXStd_Obj_31;
    ARS_OD_DistYStd_Obj_31_IDT ARS_OD_DistYStd_Obj_31;
    ARS_OD_VabsXStd_Obj_31_IDT ARS_OD_VabsXStd_Obj_31;
    ARS_OD_VabsYStd_Obj_31_IDT ARS_OD_VabsYStd_Obj_31;
    ARS_OD_AabsXStd_Obj_31_IDT ARS_OD_AabsXStd_Obj_31;
    ARS_OD_Classification_Obj_31_IDT ARS_OD_Classification_Obj_31;
    ARS_OD_AabsYStd_Obj_31_IDT ARS_OD_AabsYStd_Obj_31;
    ARS_OD_ClassConf_Obj_31_IDT ARS_OD_ClassConf_Obj_31;
    ARS_OD_DistY_Obj_30_IDT ARS_OD_DistY_Obj_30;
    ARS_OD_ProbOfExist_Obj_31_IDT ARS_OD_ProbOfExist_Obj_31;
    ARS_OD_DynConf_Obj_31_IDT ARS_OD_DynConf_Obj_31;
    ARS_OD_DynProp_Obj_31_IDT ARS_OD_DynProp_Obj_31;
    ARS_OD_MirrorProb_Obj_31_IDT ARS_OD_MirrorProb_Obj_31;
    ARS_OD_Length_Obj_31_IDT ARS_OD_Length_Obj_31;
    ARS_OD_MaintenanceState_Obj_31_IDT ARS_OD_MaintenanceState_Obj_31;
    ARS_OD_Width_Obj_31_IDT ARS_OD_Width_Obj_31;
    ARS_OD_RCS_Obj_31_IDT ARS_OD_RCS_Obj_31;
    ARS_OD_Orientation_Obj_31_IDT ARS_OD_Orientation_Obj_31;
    ARS_OD_YawRateAbs_Obj_31_IDT ARS_OD_YawRateAbs_Obj_31;
    ARS_OD_YawRateAbsStd_Obj_31_IDT ARS_OD_YawRateAbsStd_Obj_31;
    ARS_OD_RefPoint_Obj_31_IDT ARS_OD_RefPoint_Obj_31;
    ARS_OD_LifeCycle_Obj_31_IDT ARS_OD_LifeCycle_Obj_31;
    ARS_OD_OrientationStd_Obj_30_IDT ARS_OD_OrientationStd_Obj_30;
    ARS_OD_OrientationStd_Obj_31_IDT ARS_OD_OrientationStd_Obj_31;
    ARS_OD_ObstacleProb_Obj_30_IDT ARS_OD_ObstacleProb_Obj_30;
    ARS_OD_MicroDopplerFlag_30_IDT ARS_OD_MicroDopplerFlag_30;
    ARS_OD_ObstacleProb_Obj_31_IDT ARS_OD_ObstacleProb_Obj_31;
    ARS_OD_VabsY_Obj_30_IDT ARS_OD_VabsY_Obj_30;
    ARS_OD_MicroDopplerFlag_31_IDT ARS_OD_MicroDopplerFlag_31;
    ARS_OD_ID_30_IDT ARS_OD_ID_30;
    ARS_OD_ID_31_IDT ARS_OD_ID_31;
    ARS_OD_MsgCounter_Obj_30_31_IDT ARS_OD_MsgCounter_Obj_30_31;
    ARS_OD_CRC16_Checksum_Obj_30_31_IDT ARS_OD_CRC16_Checksum_Obj_30_31;
    ARS_OD_AabsY_Obj_30_IDT ARS_OD_AabsY_Obj_30;
    ARS_OD_DistXStd_Obj_30_IDT ARS_OD_DistXStd_Obj_30;
    ARS_OD_DistYStd_Obj_30_IDT ARS_OD_DistYStd_Obj_30;
    ARS_OD_VabsXStd_Obj_30_IDT ARS_OD_VabsXStd_Obj_30;
    ARS_OD_VabsYStd_Obj_30_IDT ARS_OD_VabsYStd_Obj_30;
    ARS_OD_AabsXStd_Obj_30_IDT ARS_OD_AabsXStd_Obj_30;
} Signal_Group_ARS_OD_30_31_IDT;

typedef struct
{
    DistHeight_Obj_33_IDT DistHeight_Obj_33;
    DistHeight_Obj_32_IDT DistHeight_Obj_32;
    ARS_OD_DistX_Obj_32_IDT ARS_OD_DistX_Obj_32;
    ARS_OD_Classification_Obj_32_IDT ARS_OD_Classification_Obj_32;
    ARS_OD_AabsYStd_Obj_32_IDT ARS_OD_AabsYStd_Obj_32;
    ARS_OD_ClassConf_Obj_32_IDT ARS_OD_ClassConf_Obj_32;
    ARS_OD_ProbOfExist_Obj_32_IDT ARS_OD_ProbOfExist_Obj_32;
    ARS_OD_DynConf_Obj_32_IDT ARS_OD_DynConf_Obj_32;
    ARS_OD_VabsX_Obj_32_IDT ARS_OD_VabsX_Obj_32;
    ARS_OD_DynProp_Obj_32_IDT ARS_OD_DynProp_Obj_32;
    ARS_OD_MirrorProb_Obj_32_IDT ARS_OD_MirrorProb_Obj_32;
    ARS_OD_Length_Obj_32_IDT ARS_OD_Length_Obj_32;
    ARS_OD_MaintenanceState_Obj_32_IDT ARS_OD_MaintenanceState_Obj_32;
    ARS_OD_Width_Obj_32_IDT ARS_OD_Width_Obj_32;
    ARS_OD_RCS_Obj_32_IDT ARS_OD_RCS_Obj_32;
    ARS_OD_Orientation_Obj_32_IDT ARS_OD_Orientation_Obj_32;
    ARS_OD_YawRateAbs_Obj_32_IDT ARS_OD_YawRateAbs_Obj_32;
    ARS_OD_YawRateAbsStd_Obj_32_IDT ARS_OD_YawRateAbsStd_Obj_32;
    ARS_OD_RefPoint_Obj_32_IDT ARS_OD_RefPoint_Obj_32;
    ARS_OD_LifeCycle_Obj_32_IDT ARS_OD_LifeCycle_Obj_32;
    ARS_OD_DistX_Obj_33_IDT ARS_OD_DistX_Obj_33;
    ARS_OD_VabsX_Obj_33_IDT ARS_OD_VabsX_Obj_33;
    ARS_OD_AabsX_Obj_33_IDT ARS_OD_AabsX_Obj_33;
    ARS_OD_AabsX_Obj_32_IDT ARS_OD_AabsX_Obj_32;
    ARS_OD_DistY_Obj_33_IDT ARS_OD_DistY_Obj_33;
    ARS_OD_VabsY_Obj_33_IDT ARS_OD_VabsY_Obj_33;
    ARS_OD_AabsY_Obj_33_IDT ARS_OD_AabsY_Obj_33;
    ARS_OD_DistXStd_Obj_33_IDT ARS_OD_DistXStd_Obj_33;
    ARS_OD_DistYStd_Obj_33_IDT ARS_OD_DistYStd_Obj_33;
    ARS_OD_VabsXStd_Obj_33_IDT ARS_OD_VabsXStd_Obj_33;
    ARS_OD_VabsYStd_Obj_33_IDT ARS_OD_VabsYStd_Obj_33;
    ARS_OD_AabsXStd_Obj_33_IDT ARS_OD_AabsXStd_Obj_33;
    ARS_OD_Classification_Obj_33_IDT ARS_OD_Classification_Obj_33;
    ARS_OD_AabsYStd_Obj_33_IDT ARS_OD_AabsYStd_Obj_33;
    ARS_OD_ClassConf_Obj_33_IDT ARS_OD_ClassConf_Obj_33;
    ARS_OD_DistY_Obj_32_IDT ARS_OD_DistY_Obj_32;
    ARS_OD_ProbOfExist_Obj_33_IDT ARS_OD_ProbOfExist_Obj_33;
    ARS_OD_DynConf_Obj_33_IDT ARS_OD_DynConf_Obj_33;
    ARS_OD_DynProp_Obj_33_IDT ARS_OD_DynProp_Obj_33;
    ARS_OD_MirrorProb_Obj_33_IDT ARS_OD_MirrorProb_Obj_33;
    ARS_OD_Length_Obj_33_IDT ARS_OD_Length_Obj_33;
    ARS_OD_MaintenanceState_Obj_33_IDT ARS_OD_MaintenanceState_Obj_33;
    ARS_OD_Width_Obj_33_IDT ARS_OD_Width_Obj_33;
    ARS_OD_RCS_Obj_33_IDT ARS_OD_RCS_Obj_33;
    ARS_OD_Orientation_Obj_33_IDT ARS_OD_Orientation_Obj_33;
    ARS_OD_YawRateAbs_Obj_33_IDT ARS_OD_YawRateAbs_Obj_33;
    ARS_OD_YawRateAbsStd_Obj_33_IDT ARS_OD_YawRateAbsStd_Obj_33;
    ARS_OD_RefPoint_Obj_33_IDT ARS_OD_RefPoint_Obj_33;
    ARS_OD_LifeCycle_Obj_33_IDT ARS_OD_LifeCycle_Obj_33;
    ARS_OD_OrientationStd_Obj_32_IDT ARS_OD_OrientationStd_Obj_32;
    ARS_OD_OrientationStd_Obj_33_IDT ARS_OD_OrientationStd_Obj_33;
    ARS_OD_ObstacleProb_Obj_32_IDT ARS_OD_ObstacleProb_Obj_32;
    ARS_OD_MicroDopplerFlag_32_IDT ARS_OD_MicroDopplerFlag_32;
    ARS_OD_ObstacleProb_Obj_33_IDT ARS_OD_ObstacleProb_Obj_33;
    ARS_OD_VabsY_Obj_32_IDT ARS_OD_VabsY_Obj_32;
    ARS_OD_MicroDopplerFlag_33_IDT ARS_OD_MicroDopplerFlag_33;
    ARS_OD_ID_32_IDT ARS_OD_ID_32;
    ARS_OD_ID_33_IDT ARS_OD_ID_33;
    ARS_OD_MsgCounter_Obj_32_33_IDT ARS_OD_MsgCounter_Obj_32_33;
    ARS_OD_CRC16_Checksum_Obj_32_33_IDT ARS_OD_CRC16_Checksum_Obj_32_33;
    ARS_OD_AabsY_Obj_32_IDT ARS_OD_AabsY_Obj_32;
    ARS_OD_DistXStd_Obj_32_IDT ARS_OD_DistXStd_Obj_32;
    ARS_OD_DistYStd_Obj_32_IDT ARS_OD_DistYStd_Obj_32;
    ARS_OD_VabsXStd_Obj_32_IDT ARS_OD_VabsXStd_Obj_32;
    ARS_OD_VabsYStd_Obj_32_IDT ARS_OD_VabsYStd_Obj_32;
    ARS_OD_AabsXStd_Obj_32_IDT ARS_OD_AabsXStd_Obj_32;
} Signal_Group_ARS_OD_32_33_IDT;

typedef struct
{
    DistHeight_Obj_35_IDT DistHeight_Obj_35;
    DistHeight_Obj_34_IDT DistHeight_Obj_34;
    ARS_OD_DistX_Obj_34_IDT ARS_OD_DistX_Obj_34;
    ARS_OD_Classification_Obj_34_IDT ARS_OD_Classification_Obj_34;
    ARS_OD_AabsYStd_Obj_34_IDT ARS_OD_AabsYStd_Obj_34;
    ARS_OD_ClassConf_Obj_34_IDT ARS_OD_ClassConf_Obj_34;
    ARS_OD_ProbOfExist_Obj_34_IDT ARS_OD_ProbOfExist_Obj_34;
    ARS_OD_DynConf_Obj_34_IDT ARS_OD_DynConf_Obj_34;
    ARS_OD_VabsX_Obj_34_IDT ARS_OD_VabsX_Obj_34;
    ARS_OD_DynProp_Obj_34_IDT ARS_OD_DynProp_Obj_34;
    ARS_OD_MirrorProb_Obj_34_IDT ARS_OD_MirrorProb_Obj_34;
    ARS_OD_Length_Obj_34_IDT ARS_OD_Length_Obj_34;
    ARS_OD_MaintenanceState_Obj_34_IDT ARS_OD_MaintenanceState_Obj_34;
    ARS_OD_Width_Obj_34_IDT ARS_OD_Width_Obj_34;
    ARS_OD_RCS_Obj_34_IDT ARS_OD_RCS_Obj_34;
    ARS_OD_Orientation_Obj_34_IDT ARS_OD_Orientation_Obj_34;
    ARS_OD_YawRateAbs_Obj_34_IDT ARS_OD_YawRateAbs_Obj_34;
    ARS_OD_YawRateAbsStd_Obj_34_IDT ARS_OD_YawRateAbsStd_Obj_34;
    ARS_OD_RefPoint_Obj_34_IDT ARS_OD_RefPoint_Obj_34;
    ARS_OD_LifeCycle_Obj_34_IDT ARS_OD_LifeCycle_Obj_34;
    ARS_OD_DistX_Obj_35_IDT ARS_OD_DistX_Obj_35;
    ARS_OD_VabsX_Obj_35_IDT ARS_OD_VabsX_Obj_35;
    ARS_OD_AabsX_Obj_35_IDT ARS_OD_AabsX_Obj_35;
    ARS_OD_AabsX_Obj_34_IDT ARS_OD_AabsX_Obj_34;
    ARS_OD_DistY_Obj_35_IDT ARS_OD_DistY_Obj_35;
    ARS_OD_VabsY_Obj_35_IDT ARS_OD_VabsY_Obj_35;
    ARS_OD_AabsY_Obj_35_IDT ARS_OD_AabsY_Obj_35;
    ARS_OD_DistXStd_Obj_35_IDT ARS_OD_DistXStd_Obj_35;
    ARS_OD_DistYStd_Obj_35_IDT ARS_OD_DistYStd_Obj_35;
    ARS_OD_VabsXStd_Obj_35_IDT ARS_OD_VabsXStd_Obj_35;
    ARS_OD_VabsYStd_Obj_35_IDT ARS_OD_VabsYStd_Obj_35;
    ARS_OD_AabsXStd_Obj_35_IDT ARS_OD_AabsXStd_Obj_35;
    ARS_OD_Classification_Obj_35_IDT ARS_OD_Classification_Obj_35;
    ARS_OD_AabsYStd_Obj_35_IDT ARS_OD_AabsYStd_Obj_35;
    ARS_OD_ClassConf_Obj_35_IDT ARS_OD_ClassConf_Obj_35;
    ARS_OD_DistY_Obj_34_IDT ARS_OD_DistY_Obj_34;
    ARS_OD_ProbOfExist_Obj_35_IDT ARS_OD_ProbOfExist_Obj_35;
    ARS_OD_DynConf_Obj_35_IDT ARS_OD_DynConf_Obj_35;
    ARS_OD_DynProp_Obj_35_IDT ARS_OD_DynProp_Obj_35;
    ARS_OD_MirrorProb_Obj_35_IDT ARS_OD_MirrorProb_Obj_35;
    ARS_OD_Length_Obj_35_IDT ARS_OD_Length_Obj_35;
    ARS_OD_MaintenanceState_Obj_35_IDT ARS_OD_MaintenanceState_Obj_35;
    ARS_OD_Width_Obj_35_IDT ARS_OD_Width_Obj_35;
    ARS_OD_RCS_Obj_35_IDT ARS_OD_RCS_Obj_35;
    ARS_OD_Orientation_Obj_35_IDT ARS_OD_Orientation_Obj_35;
    ARS_OD_YawRateAbs_Obj_35_IDT ARS_OD_YawRateAbs_Obj_35;
    ARS_OD_YawRateAbsStd_Obj_35_IDT ARS_OD_YawRateAbsStd_Obj_35;
    ARS_OD_RefPoint_Obj_35_IDT ARS_OD_RefPoint_Obj_35;
    ARS_OD_LifeCycle_Obj_35_IDT ARS_OD_LifeCycle_Obj_35;
    ARS_OD_OrientationStd_Obj_34_IDT ARS_OD_OrientationStd_Obj_34;
    ARS_OD_OrientationStd_Obj_35_IDT ARS_OD_OrientationStd_Obj_35;
    ARS_OD_ObstacleProb_Obj_34_IDT ARS_OD_ObstacleProb_Obj_34;
    ARS_OD_MicroDopplerFlag_34_IDT ARS_OD_MicroDopplerFlag_34;
    ARS_OD_ObstacleProb_Obj_35_IDT ARS_OD_ObstacleProb_Obj_35;
    ARS_OD_VabsY_Obj_34_IDT ARS_OD_VabsY_Obj_34;
    ARS_OD_MicroDopplerFlag_35_IDT ARS_OD_MicroDopplerFlag_35;
    ARS_OD_ID_34_IDT ARS_OD_ID_34;
    ARS_OD_ID_35_IDT ARS_OD_ID_35;
    ARS_OD_MsgCounter_Obj_34_35_IDT ARS_OD_MsgCounter_Obj_34_35;
    ARS_OD_CRC16_Checksum_Obj_34_35_IDT ARS_OD_CRC16_Checksum_Obj_34_35;
    ARS_OD_AabsY_Obj_34_IDT ARS_OD_AabsY_Obj_34;
    ARS_OD_DistXStd_Obj_34_IDT ARS_OD_DistXStd_Obj_34;
    ARS_OD_DistYStd_Obj_34_IDT ARS_OD_DistYStd_Obj_34;
    ARS_OD_VabsXStd_Obj_34_IDT ARS_OD_VabsXStd_Obj_34;
    ARS_OD_VabsYStd_Obj_34_IDT ARS_OD_VabsYStd_Obj_34;
    ARS_OD_AabsXStd_Obj_34_IDT ARS_OD_AabsXStd_Obj_34;
} Signal_Group_ARS_OD_34_35_IDT;

typedef struct
{
    DistHeight_Obj_37_IDT DistHeight_Obj_37;
    DistHeight_Obj_36_IDT DistHeight_Obj_36;
    ARS_OD_DistX_Obj_36_IDT ARS_OD_DistX_Obj_36;
    ARS_OD_Classification_Obj_36_IDT ARS_OD_Classification_Obj_36;
    ARS_OD_AabsYStd_Obj_36_IDT ARS_OD_AabsYStd_Obj_36;
    ARS_OD_ClassConf_Obj_36_IDT ARS_OD_ClassConf_Obj_36;
    ARS_OD_ProbOfExist_Obj_36_IDT ARS_OD_ProbOfExist_Obj_36;
    ARS_OD_DynConf_Obj_36_IDT ARS_OD_DynConf_Obj_36;
    ARS_OD_VabsX_Obj_36_IDT ARS_OD_VabsX_Obj_36;
    ARS_OD_DynProp_Obj_36_IDT ARS_OD_DynProp_Obj_36;
    ARS_OD_MirrorProb_Obj_36_IDT ARS_OD_MirrorProb_Obj_36;
    ARS_OD_Length_Obj_36_IDT ARS_OD_Length_Obj_36;
    ARS_OD_MaintenanceState_Obj_36_IDT ARS_OD_MaintenanceState_Obj_36;
    ARS_OD_Width_Obj_36_IDT ARS_OD_Width_Obj_36;
    ARS_OD_RCS_Obj_36_IDT ARS_OD_RCS_Obj_36;
    ARS_OD_Orientation_Obj_36_IDT ARS_OD_Orientation_Obj_36;
    ARS_OD_YawRateAbs_Obj_36_IDT ARS_OD_YawRateAbs_Obj_36;
    ARS_OD_YawRateAbsStd_Obj_36_IDT ARS_OD_YawRateAbsStd_Obj_36;
    ARS_OD_RefPoint_Obj_36_IDT ARS_OD_RefPoint_Obj_36;
    ARS_OD_LifeCycle_Obj_36_IDT ARS_OD_LifeCycle_Obj_36;
    ARS_OD_DistX_Obj_37_IDT ARS_OD_DistX_Obj_37;
    ARS_OD_VabsX_Obj_37_IDT ARS_OD_VabsX_Obj_37;
    ARS_OD_AabsX_Obj_37_IDT ARS_OD_AabsX_Obj_37;
    ARS_OD_AabsX_Obj_36_IDT ARS_OD_AabsX_Obj_36;
    ARS_OD_DistY_Obj_37_IDT ARS_OD_DistY_Obj_37;
    ARS_OD_VabsY_Obj_37_IDT ARS_OD_VabsY_Obj_37;
    ARS_OD_AabsY_Obj_37_IDT ARS_OD_AabsY_Obj_37;
    ARS_OD_DistXStd_Obj_37_IDT ARS_OD_DistXStd_Obj_37;
    ARS_OD_DistYStd_Obj_37_IDT ARS_OD_DistYStd_Obj_37;
    ARS_OD_VabsXStd_Obj_37_IDT ARS_OD_VabsXStd_Obj_37;
    ARS_OD_VabsYStd_Obj_37_IDT ARS_OD_VabsYStd_Obj_37;
    ARS_OD_AabsXStd_Obj_37_IDT ARS_OD_AabsXStd_Obj_37;
    ARS_OD_Classification_Obj_37_IDT ARS_OD_Classification_Obj_37;
    ARS_OD_AabsYStd_Obj_37_IDT ARS_OD_AabsYStd_Obj_37;
    ARS_OD_ClassConf_Obj_37_IDT ARS_OD_ClassConf_Obj_37;
    ARS_OD_DistY_Obj_36_IDT ARS_OD_DistY_Obj_36;
    ARS_OD_ProbOfExist_Obj_37_IDT ARS_OD_ProbOfExist_Obj_37;
    ARS_OD_DynConf_Obj_37_IDT ARS_OD_DynConf_Obj_37;
    ARS_OD_DynProp_Obj_37_IDT ARS_OD_DynProp_Obj_37;
    ARS_OD_MirrorProb_Obj_37_IDT ARS_OD_MirrorProb_Obj_37;
    ARS_OD_Length_Obj_37_IDT ARS_OD_Length_Obj_37;
    ARS_OD_MaintenanceState_Obj_37_IDT ARS_OD_MaintenanceState_Obj_37;
    ARS_OD_Width_Obj_37_IDT ARS_OD_Width_Obj_37;
    ARS_OD_RCS_Obj_37_IDT ARS_OD_RCS_Obj_37;
    ARS_OD_Orientation_Obj_37_IDT ARS_OD_Orientation_Obj_37;
    ARS_OD_YawRateAbs_Obj_37_IDT ARS_OD_YawRateAbs_Obj_37;
    ARS_OD_YawRateAbsStd_Obj_37_IDT ARS_OD_YawRateAbsStd_Obj_37;
    ARS_OD_RefPoint_Obj_37_IDT ARS_OD_RefPoint_Obj_37;
    ARS_OD_LifeCycle_Obj_37_IDT ARS_OD_LifeCycle_Obj_37;
    ARS_OD_OrientationStd_Obj_36_IDT ARS_OD_OrientationStd_Obj_36;
    ARS_OD_OrientationStd_Obj_37_IDT ARS_OD_OrientationStd_Obj_37;
    ARS_OD_ObstacleProb_Obj_36_IDT ARS_OD_ObstacleProb_Obj_36;
    ARS_OD_MicroDopplerFlag_36_IDT ARS_OD_MicroDopplerFlag_36;
    ARS_OD_ObstacleProb_Obj_37_IDT ARS_OD_ObstacleProb_Obj_37;
    ARS_OD_VabsY_Obj_36_IDT ARS_OD_VabsY_Obj_36;
    ARS_OD_MicroDopplerFlag_37_IDT ARS_OD_MicroDopplerFlag_37;
    ARS_OD_ID_36_IDT ARS_OD_ID_36;
    ARS_OD_ID_37_IDT ARS_OD_ID_37;
    ARS_OD_MsgCounter_Obj_36_37_IDT ARS_OD_MsgCounter_Obj_36_37;
    ARS_OD_CRC16_Checksum_Obj_36_37_IDT ARS_OD_CRC16_Checksum_Obj_36_37;
    ARS_OD_AabsY_Obj_36_IDT ARS_OD_AabsY_Obj_36;
    ARS_OD_DistXStd_Obj_36_IDT ARS_OD_DistXStd_Obj_36;
    ARS_OD_DistYStd_Obj_36_IDT ARS_OD_DistYStd_Obj_36;
    ARS_OD_VabsXStd_Obj_36_IDT ARS_OD_VabsXStd_Obj_36;
    ARS_OD_VabsYStd_Obj_36_IDT ARS_OD_VabsYStd_Obj_36;
    ARS_OD_AabsXStd_Obj_36_IDT ARS_OD_AabsXStd_Obj_36;
} Signal_Group_ARS_OD_36_37_IDT;

typedef struct
{
    DistHeight_Obj_39_IDT DistHeight_Obj_39;
    DistHeight_Obj_38_IDT DistHeight_Obj_38;
    ARS_OD_DistX_Obj_38_IDT ARS_OD_DistX_Obj_38;
    ARS_OD_Classification_Obj_38_IDT ARS_OD_Classification_Obj_38;
    ARS_OD_AabsYStd_Obj_38_IDT ARS_OD_AabsYStd_Obj_38;
    ARS_OD_ClassConf_Obj_38_IDT ARS_OD_ClassConf_Obj_38;
    ARS_OD_ProbOfExist_Obj_38_IDT ARS_OD_ProbOfExist_Obj_38;
    ARS_OD_DynConf_Obj_38_IDT ARS_OD_DynConf_Obj_38;
    ARS_OD_VabsX_Obj_38_IDT ARS_OD_VabsX_Obj_38;
    ARS_OD_DynProp_Obj_38_IDT ARS_OD_DynProp_Obj_38;
    ARS_OD_MirrorProb_Obj_38_IDT ARS_OD_MirrorProb_Obj_38;
    ARS_OD_Length_Obj_38_IDT ARS_OD_Length_Obj_38;
    ARS_OD_MaintenanceState_Obj_38_IDT ARS_OD_MaintenanceState_Obj_38;
    ARS_OD_Width_Obj_38_IDT ARS_OD_Width_Obj_38;
    ARS_OD_RCS_Obj_38_IDT ARS_OD_RCS_Obj_38;
    ARS_OD_Orientation_Obj_38_IDT ARS_OD_Orientation_Obj_38;
    ARS_OD_YawRateAbs_Obj_38_IDT ARS_OD_YawRateAbs_Obj_38;
    ARS_OD_YawRateAbsStd_Obj_38_IDT ARS_OD_YawRateAbsStd_Obj_38;
    ARS_OD_RefPoint_Obj_38_IDT ARS_OD_RefPoint_Obj_38;
    ARS_OD_LifeCycle_Obj_38_IDT ARS_OD_LifeCycle_Obj_38;
    ARS_OD_DistX_Obj_39_IDT ARS_OD_DistX_Obj_39;
    ARS_OD_VabsX_Obj_39_IDT ARS_OD_VabsX_Obj_39;
    ARS_OD_AabsX_Obj_39_IDT ARS_OD_AabsX_Obj_39;
    ARS_OD_AabsX_Obj_38_IDT ARS_OD_AabsX_Obj_38;
    ARS_OD_DistY_Obj_39_IDT ARS_OD_DistY_Obj_39;
    ARS_OD_VabsY_Obj_39_IDT ARS_OD_VabsY_Obj_39;
    ARS_OD_AabsY_Obj_39_IDT ARS_OD_AabsY_Obj_39;
    ARS_OD_DistXStd_Obj_39_IDT ARS_OD_DistXStd_Obj_39;
    ARS_OD_DistYStd_Obj_39_IDT ARS_OD_DistYStd_Obj_39;
    ARS_OD_VabsXStd_Obj_39_IDT ARS_OD_VabsXStd_Obj_39;
    ARS_OD_VabsYStd_Obj_39_IDT ARS_OD_VabsYStd_Obj_39;
    ARS_OD_AabsXStd_Obj_39_IDT ARS_OD_AabsXStd_Obj_39;
    ARS_OD_Classification_Obj_39_IDT ARS_OD_Classification_Obj_39;
    ARS_OD_AabsYStd_Obj_39_IDT ARS_OD_AabsYStd_Obj_39;
    ARS_OD_ClassConf_Obj_39_IDT ARS_OD_ClassConf_Obj_39;
    ARS_OD_DistY_Obj_38_IDT ARS_OD_DistY_Obj_38;
    ARS_OD_ProbOfExist_Obj_39_IDT ARS_OD_ProbOfExist_Obj_39;
    ARS_OD_DynConf_Obj_39_IDT ARS_OD_DynConf_Obj_39;
    ARS_OD_DynProp_Obj_39_IDT ARS_OD_DynProp_Obj_39;
    ARS_OD_MirrorProb_Obj_39_IDT ARS_OD_MirrorProb_Obj_39;
    ARS_OD_Length_Obj_39_IDT ARS_OD_Length_Obj_39;
    ARS_OD_MaintenanceState_Obj_39_IDT ARS_OD_MaintenanceState_Obj_39;
    ARS_OD_Width_Obj_39_IDT ARS_OD_Width_Obj_39;
    ARS_OD_RCS_Obj_39_IDT ARS_OD_RCS_Obj_39;
    ARS_OD_Orientation_Obj_39_IDT ARS_OD_Orientation_Obj_39;
    ARS_OD_YawRateAbs_Obj_39_IDT ARS_OD_YawRateAbs_Obj_39;
    ARS_OD_YawRateAbsStd_Obj_39_IDT ARS_OD_YawRateAbsStd_Obj_39;
    ARS_OD_RefPoint_Obj_39_IDT ARS_OD_RefPoint_Obj_39;
    ARS_OD_LifeCycle_Obj_39_IDT ARS_OD_LifeCycle_Obj_39;
    ARS_OD_OrientationStd_Obj_38_IDT ARS_OD_OrientationStd_Obj_38;
    ARS_OD_OrientationStd_Obj_39_IDT ARS_OD_OrientationStd_Obj_39;
    ARS_OD_ObstacleProb_Obj_38_IDT ARS_OD_ObstacleProb_Obj_38;
    ARS_OD_MicroDopplerFlag_38_IDT ARS_OD_MicroDopplerFlag_38;
    ARS_OD_ObstacleProb_Obj_39_IDT ARS_OD_ObstacleProb_Obj_39;
    ARS_OD_VabsY_Obj_38_IDT ARS_OD_VabsY_Obj_38;
    ARS_OD_MicroDopplerFlag_39_IDT ARS_OD_MicroDopplerFlag_39;
    ARS_OD_ID_38_IDT ARS_OD_ID_38;
    ARS_OD_ID_39_IDT ARS_OD_ID_39;
    ARS_OD_MsgCounter_Obj_38_39_IDT ARS_OD_MsgCounter_Obj_38_39;
    ARS_OD_CRC16_Checksum_Obj_38_39_IDT ARS_OD_CRC16_Checksum_Obj_38_39;
    ARS_OD_AabsY_Obj_38_IDT ARS_OD_AabsY_Obj_38;
    ARS_OD_DistXStd_Obj_38_IDT ARS_OD_DistXStd_Obj_38;
    ARS_OD_DistYStd_Obj_38_IDT ARS_OD_DistYStd_Obj_38;
    ARS_OD_VabsXStd_Obj_38_IDT ARS_OD_VabsXStd_Obj_38;
    ARS_OD_VabsYStd_Obj_38_IDT ARS_OD_VabsYStd_Obj_38;
    ARS_OD_AabsXStd_Obj_38_IDT ARS_OD_AabsXStd_Obj_38;
} Signal_Group_ARS_OD_38_39_IDT;

typedef struct
{
    DistHeight_Obj_41_IDT DistHeight_Obj_41;
    DistHeight_Obj_40_IDT DistHeight_Obj_40;
    ARS_OD_DistX_Obj_40_IDT ARS_OD_DistX_Obj_40;
    ARS_OD_Classification_Obj_40_IDT ARS_OD_Classification_Obj_40;
    ARS_OD_AabsYStd_Obj_40_IDT ARS_OD_AabsYStd_Obj_40;
    ARS_OD_ClassConf_Obj_40_IDT ARS_OD_ClassConf_Obj_40;
    ARS_OD_ProbOfExist_Obj_40_IDT ARS_OD_ProbOfExist_Obj_40;
    ARS_OD_DynConf_Obj_40_IDT ARS_OD_DynConf_Obj_40;
    ARS_OD_VabsX_Obj_40_IDT ARS_OD_VabsX_Obj_40;
    ARS_OD_DynProp_Obj_40_IDT ARS_OD_DynProp_Obj_40;
    ARS_OD_MirrorProb_Obj_40_IDT ARS_OD_MirrorProb_Obj_40;
    ARS_OD_Length_Obj_40_IDT ARS_OD_Length_Obj_40;
    ARS_OD_MaintenanceState_Obj_40_IDT ARS_OD_MaintenanceState_Obj_40;
    ARS_OD_Width_Obj_40_IDT ARS_OD_Width_Obj_40;
    ARS_OD_RCS_Obj_40_IDT ARS_OD_RCS_Obj_40;
    ARS_OD_Orientation_Obj_40_IDT ARS_OD_Orientation_Obj_40;
    ARS_OD_YawRateAbs_Obj_40_IDT ARS_OD_YawRateAbs_Obj_40;
    ARS_OD_YawRateAbsStd_Obj_40_IDT ARS_OD_YawRateAbsStd_Obj_40;
    ARS_OD_RefPoint_Obj_40_IDT ARS_OD_RefPoint_Obj_40;
    ARS_OD_LifeCycle_Obj_40_IDT ARS_OD_LifeCycle_Obj_40;
    ARS_OD_DistX_Obj_41_IDT ARS_OD_DistX_Obj_41;
    ARS_OD_VabsX_Obj_41_IDT ARS_OD_VabsX_Obj_41;
    ARS_OD_AabsX_Obj_41_IDT ARS_OD_AabsX_Obj_41;
    ARS_OD_AabsX_Obj_40_IDT ARS_OD_AabsX_Obj_40;
    ARS_OD_DistY_Obj_41_IDT ARS_OD_DistY_Obj_41;
    ARS_OD_VabsY_Obj_41_IDT ARS_OD_VabsY_Obj_41;
    ARS_OD_AabsY_Obj_41_IDT ARS_OD_AabsY_Obj_41;
    ARS_OD_DistXStd_Obj_41_IDT ARS_OD_DistXStd_Obj_41;
    ARS_OD_DistYStd_Obj_41_IDT ARS_OD_DistYStd_Obj_41;
    ARS_OD_VabsXStd_Obj_41_IDT ARS_OD_VabsXStd_Obj_41;
    ARS_OD_VabsYStd_Obj_41_IDT ARS_OD_VabsYStd_Obj_41;
    ARS_OD_AabsXStd_Obj_41_IDT ARS_OD_AabsXStd_Obj_41;
    ARS_OD_Classification_Obj_41_IDT ARS_OD_Classification_Obj_41;
    ARS_OD_AabsYStd_Obj_41_IDT ARS_OD_AabsYStd_Obj_41;
    ARS_OD_ClassConf_Obj_41_IDT ARS_OD_ClassConf_Obj_41;
    ARS_OD_DistY_Obj_40_IDT ARS_OD_DistY_Obj_40;
    ARS_OD_ProbOfExist_Obj_41_IDT ARS_OD_ProbOfExist_Obj_41;
    ARS_OD_DynConf_Obj_41_IDT ARS_OD_DynConf_Obj_41;
    ARS_OD_DynProp_Obj_41_IDT ARS_OD_DynProp_Obj_41;
    ARS_OD_MirrorProb_Obj_41_IDT ARS_OD_MirrorProb_Obj_41;
    ARS_OD_Length_Obj_41_IDT ARS_OD_Length_Obj_41;
    ARS_OD_MaintenanceState_Obj_41_IDT ARS_OD_MaintenanceState_Obj_41;
    ARS_OD_Width_Obj_41_IDT ARS_OD_Width_Obj_41;
    ARS_OD_RCS_Obj_41_IDT ARS_OD_RCS_Obj_41;
    ARS_OD_Orientation_Obj_41_IDT ARS_OD_Orientation_Obj_41;
    ARS_OD_YawRateAbs_Obj_41_IDT ARS_OD_YawRateAbs_Obj_41;
    ARS_OD_YawRateAbsStd_Obj_41_IDT ARS_OD_YawRateAbsStd_Obj_41;
    ARS_OD_RefPoint_Obj_41_IDT ARS_OD_RefPoint_Obj_41;
    ARS_OD_LifeCycle_Obj_41_IDT ARS_OD_LifeCycle_Obj_41;
    ARS_OD_OrientationStd_Obj_40_IDT ARS_OD_OrientationStd_Obj_40;
    ARS_OD_OrientationStd_Obj_41_IDT ARS_OD_OrientationStd_Obj_41;
    ARS_OD_ObstacleProb_Obj_40_IDT ARS_OD_ObstacleProb_Obj_40;
    ARS_OD_MicroDopplerFlag_40_IDT ARS_OD_MicroDopplerFlag_40;
    ARS_OD_ObstacleProb_Obj_41_IDT ARS_OD_ObstacleProb_Obj_41;
    ARS_OD_VabsY_Obj_40_IDT ARS_OD_VabsY_Obj_40;
    ARS_OD_MicroDopplerFlag_41_IDT ARS_OD_MicroDopplerFlag_41;
    ARS_OD_ID_40_IDT ARS_OD_ID_40;
    ARS_OD_ID_41_IDT ARS_OD_ID_41;
    ARS_OD_MsgCounter_Obj_40_41_IDT ARS_OD_MsgCounter_Obj_40_41;
    ARS_OD_CRC16_Checksum_Obj_40_41_IDT ARS_OD_CRC16_Checksum_Obj_40_41;
    ARS_OD_AabsY_Obj_40_IDT ARS_OD_AabsY_Obj_40;
    ARS_OD_DistXStd_Obj_40_IDT ARS_OD_DistXStd_Obj_40;
    ARS_OD_DistYStd_Obj_40_IDT ARS_OD_DistYStd_Obj_40;
    ARS_OD_VabsXStd_Obj_40_IDT ARS_OD_VabsXStd_Obj_40;
    ARS_OD_VabsYStd_Obj_40_IDT ARS_OD_VabsYStd_Obj_40;
    ARS_OD_AabsXStd_Obj_40_IDT ARS_OD_AabsXStd_Obj_40;
} Signal_Group_ARS_OD_40_41_IDT;

typedef struct
{
    ARS_OD_DistX_Obj_42_IDT ARS_OD_DistX_Obj_42;
    ARS_OD_Classification_Obj_42_IDT ARS_OD_Classification_Obj_42;
    ARS_OD_AabsYStd_Obj_42_IDT ARS_OD_AabsYStd_Obj_42;
    ARS_OD_ClassConf_Obj_42_IDT ARS_OD_ClassConf_Obj_42;
    ARS_OD_ProbOfExist_Obj_42_IDT ARS_OD_ProbOfExist_Obj_42;
    ARS_OD_DynConf_Obj_42_IDT ARS_OD_DynConf_Obj_42;
    ARS_OD_VabsX_Obj_42_IDT ARS_OD_VabsX_Obj_42;
    ARS_OD_DynProp_Obj_42_IDT ARS_OD_DynProp_Obj_42;
    ARS_OD_MirrorProb_Obj_42_IDT ARS_OD_MirrorProb_Obj_42;
    ARS_OD_Length_Obj_42_IDT ARS_OD_Length_Obj_42;
    ARS_OD_MaintenanceState_Obj_42_IDT ARS_OD_MaintenanceState_Obj_42;
    ARS_OD_Width_Obj_42_IDT ARS_OD_Width_Obj_42;
    ARS_OD_RCS_Obj_42_IDT ARS_OD_RCS_Obj_42;
    ARS_OD_Orientation_Obj_42_IDT ARS_OD_Orientation_Obj_42;
    ARS_OD_YawRateAbs_Obj_42_IDT ARS_OD_YawRateAbs_Obj_42;
    ARS_OD_YawRateAbsStd_Obj_42_IDT ARS_OD_YawRateAbsStd_Obj_42;
    ARS_OD_RefPoint_Obj_42_IDT ARS_OD_RefPoint_Obj_42;
    ARS_OD_LifeCycle_Obj_42_IDT ARS_OD_LifeCycle_Obj_42;
    ARS_OD_DistX_Obj_43_IDT ARS_OD_DistX_Obj_43;
    ARS_OD_VabsX_Obj_43_IDT ARS_OD_VabsX_Obj_43;
    ARS_OD_AabsX_Obj_43_IDT ARS_OD_AabsX_Obj_43;
    ARS_OD_AabsX_Obj_42_IDT ARS_OD_AabsX_Obj_42;
    ARS_OD_DistY_Obj_43_IDT ARS_OD_DistY_Obj_43;
    ARS_OD_VabsY_Obj_43_IDT ARS_OD_VabsY_Obj_43;
    ARS_OD_AabsY_Obj_43_IDT ARS_OD_AabsY_Obj_43;
    ARS_OD_DistXStd_Obj_43_IDT ARS_OD_DistXStd_Obj_43;
    ARS_OD_DistYStd_Obj_43_IDT ARS_OD_DistYStd_Obj_43;
    ARS_OD_VabsXStd_Obj_43_IDT ARS_OD_VabsXStd_Obj_43;
    ARS_OD_VabsYStd_Obj_43_IDT ARS_OD_VabsYStd_Obj_43;
    ARS_OD_AabsXStd_Obj_43_IDT ARS_OD_AabsXStd_Obj_43;
    ARS_OD_Classification_Obj_43_IDT ARS_OD_Classification_Obj_43;
    ARS_OD_AabsYStd_Obj_43_IDT ARS_OD_AabsYStd_Obj_43;
    ARS_OD_ClassConf_Obj_43_IDT ARS_OD_ClassConf_Obj_43;
    ARS_OD_DistY_Obj_42_IDT ARS_OD_DistY_Obj_42;
    ARS_OD_ProbOfExist_Obj_43_IDT ARS_OD_ProbOfExist_Obj_43;
    ARS_OD_DynConf_Obj_43_IDT ARS_OD_DynConf_Obj_43;
    ARS_OD_DynProp_Obj_43_IDT ARS_OD_DynProp_Obj_43;
    ARS_OD_MirrorProb_Obj_43_IDT ARS_OD_MirrorProb_Obj_43;
    ARS_OD_Length_Obj_43_IDT ARS_OD_Length_Obj_43;
    ARS_OD_MaintenanceState_Obj_43_IDT ARS_OD_MaintenanceState_Obj_43;
    ARS_OD_Width_Obj_43_IDT ARS_OD_Width_Obj_43;
    ARS_OD_RCS_Obj_43_IDT ARS_OD_RCS_Obj_43;
    ARS_OD_Orientation_Obj_43_IDT ARS_OD_Orientation_Obj_43;
    ARS_OD_YawRateAbs_Obj_43_IDT ARS_OD_YawRateAbs_Obj_43;
    ARS_OD_YawRateAbsStd_Obj_43_IDT ARS_OD_YawRateAbsStd_Obj_43;
    ARS_OD_RefPoint_Obj_43_IDT ARS_OD_RefPoint_Obj_43;
    ARS_OD_LifeCycle_Obj_43_IDT ARS_OD_LifeCycle_Obj_43;
    ARS_OD_OrientationStd_Obj_42_IDT ARS_OD_OrientationStd_Obj_42;
    ARS_OD_OrientationStd_Obj_43_IDT ARS_OD_OrientationStd_Obj_43;
    ARS_OD_ObstacleProb_Obj_42_IDT ARS_OD_ObstacleProb_Obj_42;
    ARS_OD_MicroDopplerFlag_42_IDT ARS_OD_MicroDopplerFlag_42;
    ARS_OD_ObstacleProb_Obj_43_IDT ARS_OD_ObstacleProb_Obj_43;
    ARS_OD_VabsY_Obj_42_IDT ARS_OD_VabsY_Obj_42;
    ARS_OD_MicroDopplerFlag_43_IDT ARS_OD_MicroDopplerFlag_43;
    ARS_OD_ID_42_IDT ARS_OD_ID_42;
    ARS_OD_ID_43_IDT ARS_OD_ID_43;
    ARS_OD_MsgCounter_Obj_42_43_IDT ARS_OD_MsgCounter_Obj_42_43;
    ARS_OD_CRC16_Checksum_Obj_42_43_IDT ARS_OD_CRC16_Checksum_Obj_42_43;
    ARS_OD_AabsY_Obj_42_IDT ARS_OD_AabsY_Obj_42;
    ARS_OD_DistXStd_Obj_42_IDT ARS_OD_DistXStd_Obj_42;
    ARS_OD_DistYStd_Obj_42_IDT ARS_OD_DistYStd_Obj_42;
    ARS_OD_VabsXStd_Obj_42_IDT ARS_OD_VabsXStd_Obj_42;
    ARS_OD_VabsYStd_Obj_42_IDT ARS_OD_VabsYStd_Obj_42;
    ARS_OD_AabsXStd_Obj_42_IDT ARS_OD_AabsXStd_Obj_42;
} Signal_Group_ARS_OD_42_43_IDT;

typedef struct
{
    ARS_OD_DistX_Obj_44_IDT ARS_OD_DistX_Obj_44;
    ARS_OD_Classification_Obj_44_IDT ARS_OD_Classification_Obj_44;
    ARS_OD_AabsYStd_Obj_44_IDT ARS_OD_AabsYStd_Obj_44;
    ARS_OD_ClassConf_Obj_44_IDT ARS_OD_ClassConf_Obj_44;
    ARS_OD_ProbOfExist_Obj_44_IDT ARS_OD_ProbOfExist_Obj_44;
    ARS_OD_DynConf_Obj_44_IDT ARS_OD_DynConf_Obj_44;
    ARS_OD_VabsX_Obj_44_IDT ARS_OD_VabsX_Obj_44;
    ARS_OD_DynProp_Obj_44_IDT ARS_OD_DynProp_Obj_44;
    ARS_OD_MirrorProb_Obj_44_IDT ARS_OD_MirrorProb_Obj_44;
    ARS_OD_Length_Obj_44_IDT ARS_OD_Length_Obj_44;
    ARS_OD_MaintenanceState_Obj_44_IDT ARS_OD_MaintenanceState_Obj_44;
    ARS_OD_Width_Obj_44_IDT ARS_OD_Width_Obj_44;
    ARS_OD_RCS_Obj_44_IDT ARS_OD_RCS_Obj_44;
    ARS_OD_Orientation_Obj_44_IDT ARS_OD_Orientation_Obj_44;
    ARS_OD_YawRateAbs_Obj_44_IDT ARS_OD_YawRateAbs_Obj_44;
    ARS_OD_YawRateAbsStd_Obj_44_IDT ARS_OD_YawRateAbsStd_Obj_44;
    ARS_OD_RefPoint_Obj_44_IDT ARS_OD_RefPoint_Obj_44;
    ARS_OD_LifeCycle_Obj_44_IDT ARS_OD_LifeCycle_Obj_44;
    ARS_OD_DistX_Obj_45_IDT ARS_OD_DistX_Obj_45;
    ARS_OD_VabsX_Obj_45_IDT ARS_OD_VabsX_Obj_45;
    ARS_OD_AabsX_Obj_45_IDT ARS_OD_AabsX_Obj_45;
    ARS_OD_AabsX_Obj_44_IDT ARS_OD_AabsX_Obj_44;
    ARS_OD_DistY_Obj_45_IDT ARS_OD_DistY_Obj_45;
    ARS_OD_VabsY_Obj_45_IDT ARS_OD_VabsY_Obj_45;
    ARS_OD_AabsY_Obj_45_IDT ARS_OD_AabsY_Obj_45;
    ARS_OD_DistXStd_Obj_45_IDT ARS_OD_DistXStd_Obj_45;
    ARS_OD_DistYStd_Obj_45_IDT ARS_OD_DistYStd_Obj_45;
    ARS_OD_VabsXStd_Obj_45_IDT ARS_OD_VabsXStd_Obj_45;
    ARS_OD_VabsYStd_Obj_45_IDT ARS_OD_VabsYStd_Obj_45;
    ARS_OD_AabsXStd_Obj_45_IDT ARS_OD_AabsXStd_Obj_45;
    ARS_OD_Classification_Obj_45_IDT ARS_OD_Classification_Obj_45;
    ARS_OD_AabsYStd_Obj_45_IDT ARS_OD_AabsYStd_Obj_45;
    ARS_OD_ClassConf_Obj_45_IDT ARS_OD_ClassConf_Obj_45;
    ARS_OD_DistY_Obj_44_IDT ARS_OD_DistY_Obj_44;
    ARS_OD_ProbOfExist_Obj_45_IDT ARS_OD_ProbOfExist_Obj_45;
    ARS_OD_DynConf_Obj_45_IDT ARS_OD_DynConf_Obj_45;
    ARS_OD_DynProp_Obj_45_IDT ARS_OD_DynProp_Obj_45;
    ARS_OD_MirrorProb_Obj_45_IDT ARS_OD_MirrorProb_Obj_45;
    ARS_OD_Length_Obj_45_IDT ARS_OD_Length_Obj_45;
    ARS_OD_MaintenanceState_Obj_45_IDT ARS_OD_MaintenanceState_Obj_45;
    ARS_OD_Width_Obj_45_IDT ARS_OD_Width_Obj_45;
    ARS_OD_RCS_Obj_45_IDT ARS_OD_RCS_Obj_45;
    ARS_OD_Orientation_Obj_45_IDT ARS_OD_Orientation_Obj_45;
    ARS_OD_YawRateAbs_Obj_45_IDT ARS_OD_YawRateAbs_Obj_45;
    ARS_OD_YawRateAbsStd_Obj_45_IDT ARS_OD_YawRateAbsStd_Obj_45;
    ARS_OD_RefPoint_Obj_45_IDT ARS_OD_RefPoint_Obj_45;
    ARS_OD_LifeCycle_Obj_45_IDT ARS_OD_LifeCycle_Obj_45;
    ARS_OD_OrientationStd_Obj_44_IDT ARS_OD_OrientationStd_Obj_44;
    ARS_OD_OrientationStd_Obj_45_IDT ARS_OD_OrientationStd_Obj_45;
    ARS_OD_ObstacleProb_Obj_44_IDT ARS_OD_ObstacleProb_Obj_44;
    ARS_OD_MicroDopplerFlag_44_IDT ARS_OD_MicroDopplerFlag_44;
    ARS_OD_ObstacleProb_Obj_45_IDT ARS_OD_ObstacleProb_Obj_45;
    ARS_OD_VabsY_Obj_44_IDT ARS_OD_VabsY_Obj_44;
    ARS_OD_MicroDopplerFlag_45_IDT ARS_OD_MicroDopplerFlag_45;
    ARS_OD_ID_44_IDT ARS_OD_ID_44;
    ARS_OD_ID_45_IDT ARS_OD_ID_45;
    ARS_OD_MsgCounter_Obj_44_45_IDT ARS_OD_MsgCounter_Obj_44_45;
    ARS_OD_CRC16_Checksum_Obj_44_45_IDT ARS_OD_CRC16_Checksum_Obj_44_45;
    ARS_OD_AabsY_Obj_44_IDT ARS_OD_AabsY_Obj_44;
    ARS_OD_DistXStd_Obj_44_IDT ARS_OD_DistXStd_Obj_44;
    ARS_OD_DistYStd_Obj_44_IDT ARS_OD_DistYStd_Obj_44;
    ARS_OD_VabsXStd_Obj_44_IDT ARS_OD_VabsXStd_Obj_44;
    ARS_OD_VabsYStd_Obj_44_IDT ARS_OD_VabsYStd_Obj_44;
    ARS_OD_AabsXStd_Obj_44_IDT ARS_OD_AabsXStd_Obj_44;
} Signal_Group_ARS_OD_44_45_IDT;

typedef struct
{
    ARS_OD_DistX_Obj_46_IDT ARS_OD_DistX_Obj_46;
    ARS_OD_Classification_Obj_46_IDT ARS_OD_Classification_Obj_46;
    ARS_OD_AabsYStd_Obj_46_IDT ARS_OD_AabsYStd_Obj_46;
    ARS_OD_ClassConf_Obj_46_IDT ARS_OD_ClassConf_Obj_46;
    ARS_OD_ProbOfExist_Obj_46_IDT ARS_OD_ProbOfExist_Obj_46;
    ARS_OD_DynConf_Obj_46_IDT ARS_OD_DynConf_Obj_46;
    ARS_OD_VabsX_Obj_46_IDT ARS_OD_VabsX_Obj_46;
    ARS_OD_DynProp_Obj_46_IDT ARS_OD_DynProp_Obj_46;
    ARS_OD_MirrorProb_Obj_46_IDT ARS_OD_MirrorProb_Obj_46;
    ARS_OD_Length_Obj_46_IDT ARS_OD_Length_Obj_46;
    ARS_OD_MaintenanceState_Obj_46_IDT ARS_OD_MaintenanceState_Obj_46;
    ARS_OD_Width_Obj_46_IDT ARS_OD_Width_Obj_46;
    ARS_OD_RCS_Obj_46_IDT ARS_OD_RCS_Obj_46;
    ARS_OD_Orientation_Obj_46_IDT ARS_OD_Orientation_Obj_46;
    ARS_OD_YawRateAbs_Obj_46_IDT ARS_OD_YawRateAbs_Obj_46;
    ARS_OD_YawRateAbsStd_Obj_46_IDT ARS_OD_YawRateAbsStd_Obj_46;
    ARS_OD_RefPoint_Obj_46_IDT ARS_OD_RefPoint_Obj_46;
    ARS_OD_LifeCycle_Obj_46_IDT ARS_OD_LifeCycle_Obj_46;
    ARS_OD_DistX_Obj_47_IDT ARS_OD_DistX_Obj_47;
    ARS_OD_VabsX_Obj_47_IDT ARS_OD_VabsX_Obj_47;
    ARS_OD_AabsX_Obj_47_IDT ARS_OD_AabsX_Obj_47;
    ARS_OD_AabsX_Obj_46_IDT ARS_OD_AabsX_Obj_46;
    ARS_OD_DistY_Obj_47_IDT ARS_OD_DistY_Obj_47;
    ARS_OD_VabsY_Obj_47_IDT ARS_OD_VabsY_Obj_47;
    ARS_OD_AabsY_Obj_47_IDT ARS_OD_AabsY_Obj_47;
    ARS_OD_DistXStd_Obj_47_IDT ARS_OD_DistXStd_Obj_47;
    ARS_OD_DistYStd_Obj_47_IDT ARS_OD_DistYStd_Obj_47;
    ARS_OD_VabsXStd_Obj_47_IDT ARS_OD_VabsXStd_Obj_47;
    ARS_OD_VabsYStd_Obj_47_IDT ARS_OD_VabsYStd_Obj_47;
    ARS_OD_AabsXStd_Obj_47_IDT ARS_OD_AabsXStd_Obj_47;
    ARS_OD_Classification_Obj_47_IDT ARS_OD_Classification_Obj_47;
    ARS_OD_AabsYStd_Obj_47_IDT ARS_OD_AabsYStd_Obj_47;
    ARS_OD_ClassConf_Obj_47_IDT ARS_OD_ClassConf_Obj_47;
    ARS_OD_DistY_Obj_46_IDT ARS_OD_DistY_Obj_46;
    ARS_OD_ProbOfExist_Obj_47_IDT ARS_OD_ProbOfExist_Obj_47;
    ARS_OD_DynConf_Obj_47_IDT ARS_OD_DynConf_Obj_47;
    ARS_OD_DynProp_Obj_47_IDT ARS_OD_DynProp_Obj_47;
    ARS_OD_MirrorProb_Obj_47_IDT ARS_OD_MirrorProb_Obj_47;
    ARS_OD_Length_Obj_47_IDT ARS_OD_Length_Obj_47;
    ARS_OD_MaintenanceState_Obj_47_IDT ARS_OD_MaintenanceState_Obj_47;
    ARS_OD_Width_Obj_47_IDT ARS_OD_Width_Obj_47;
    ARS_OD_RCS_Obj_47_IDT ARS_OD_RCS_Obj_47;
    ARS_OD_Orientation_Obj_47_IDT ARS_OD_Orientation_Obj_47;
    ARS_OD_YawRateAbs_Obj_47_IDT ARS_OD_YawRateAbs_Obj_47;
    ARS_OD_YawRateAbsStd_Obj_47_IDT ARS_OD_YawRateAbsStd_Obj_47;
    ARS_OD_RefPoint_Obj_47_IDT ARS_OD_RefPoint_Obj_47;
    ARS_OD_LifeCycle_Obj_47_IDT ARS_OD_LifeCycle_Obj_47;
    ARS_OD_OrientationStd_Obj_46_IDT ARS_OD_OrientationStd_Obj_46;
    ARS_OD_OrientationStd_Obj_47_IDT ARS_OD_OrientationStd_Obj_47;
    ARS_OD_ObstacleProb_Obj_46_IDT ARS_OD_ObstacleProb_Obj_46;
    ARS_OD_MicroDopplerFlag_46_IDT ARS_OD_MicroDopplerFlag_46;
    ARS_OD_ObstacleProb_Obj_47_IDT ARS_OD_ObstacleProb_Obj_47;
    ARS_OD_VabsY_Obj_46_IDT ARS_OD_VabsY_Obj_46;
    ARS_OD_MicroDopplerFlag_47_IDT ARS_OD_MicroDopplerFlag_47;
    ARS_OD_ID_46_IDT ARS_OD_ID_46;
    ARS_OD_ID_47_IDT ARS_OD_ID_47;
    ARS_OD_MsgCounter_Obj_46_47_IDT ARS_OD_MsgCounter_Obj_46_47;
    ARS_OD_CRC16_Checksum_Obj_46_47_IDT ARS_OD_CRC16_Checksum_Obj_46_47;
    ARS_OD_AabsY_Obj_46_IDT ARS_OD_AabsY_Obj_46;
    ARS_OD_DistXStd_Obj_46_IDT ARS_OD_DistXStd_Obj_46;
    ARS_OD_DistYStd_Obj_46_IDT ARS_OD_DistYStd_Obj_46;
    ARS_OD_VabsXStd_Obj_46_IDT ARS_OD_VabsXStd_Obj_46;
    ARS_OD_VabsYStd_Obj_46_IDT ARS_OD_VabsYStd_Obj_46;
    ARS_OD_AabsXStd_Obj_46_IDT ARS_OD_AabsXStd_Obj_46;
} Signal_Group_ARS_OD_46_47_IDT;

typedef struct
{
    ARS_OD_DistX_Obj_48_IDT ARS_OD_DistX_Obj_48;
    ARS_OD_Classification_Obj_48_IDT ARS_OD_Classification_Obj_48;
    ARS_OD_AabsYStd_Obj_48_IDT ARS_OD_AabsYStd_Obj_48;
    ARS_OD_ClassConf_Obj_48_IDT ARS_OD_ClassConf_Obj_48;
    ARS_OD_ProbOfExist_Obj_48_IDT ARS_OD_ProbOfExist_Obj_48;
    ARS_OD_DynConf_Obj_48_IDT ARS_OD_DynConf_Obj_48;
    ARS_OD_VabsX_Obj_48_IDT ARS_OD_VabsX_Obj_48;
    ARS_OD_DynProp_Obj_48_IDT ARS_OD_DynProp_Obj_48;
    ARS_OD_MirrorProb_Obj_48_IDT ARS_OD_MirrorProb_Obj_48;
    ARS_OD_Length_Obj_48_IDT ARS_OD_Length_Obj_48;
    ARS_OD_MaintenanceState_Obj_48_IDT ARS_OD_MaintenanceState_Obj_48;
    ARS_OD_Width_Obj_48_IDT ARS_OD_Width_Obj_48;
    ARS_OD_RCS_Obj_48_IDT ARS_OD_RCS_Obj_48;
    ARS_OD_Orientation_Obj_48_IDT ARS_OD_Orientation_Obj_48;
    ARS_OD_YawRateAbs_Obj_48_IDT ARS_OD_YawRateAbs_Obj_48;
    ARS_OD_YawRateAbsStd_Obj_48_IDT ARS_OD_YawRateAbsStd_Obj_48;
    ARS_OD_RefPoint_Obj_48_IDT ARS_OD_RefPoint_Obj_48;
    ARS_OD_LifeCycle_Obj_48_IDT ARS_OD_LifeCycle_Obj_48;
    ARS_OD_DistX_Obj_49_IDT ARS_OD_DistX_Obj_49;
    ARS_OD_VabsX_Obj_49_IDT ARS_OD_VabsX_Obj_49;
    ARS_OD_AabsX_Obj_49_IDT ARS_OD_AabsX_Obj_49;
    ARS_OD_AabsX_Obj_48_IDT ARS_OD_AabsX_Obj_48;
    ARS_OD_DistY_Obj_49_IDT ARS_OD_DistY_Obj_49;
    ARS_OD_VabsY_Obj_49_IDT ARS_OD_VabsY_Obj_49;
    ARS_OD_AabsY_Obj_49_IDT ARS_OD_AabsY_Obj_49;
    ARS_OD_DistXStd_Obj_49_IDT ARS_OD_DistXStd_Obj_49;
    ARS_OD_DistYStd_Obj_49_IDT ARS_OD_DistYStd_Obj_49;
    ARS_OD_VabsXStd_Obj_49_IDT ARS_OD_VabsXStd_Obj_49;
    ARS_OD_VabsYStd_Obj_49_IDT ARS_OD_VabsYStd_Obj_49;
    ARS_OD_AabsXStd_Obj_49_IDT ARS_OD_AabsXStd_Obj_49;
    ARS_OD_Classification_Obj_49_IDT ARS_OD_Classification_Obj_49;
    ARS_OD_AabsYStd_Obj_49_IDT ARS_OD_AabsYStd_Obj_49;
    ARS_OD_ClassConf_Obj_49_IDT ARS_OD_ClassConf_Obj_49;
    ARS_OD_DistY_Obj_48_IDT ARS_OD_DistY_Obj_48;
    ARS_OD_ProbOfExist_Obj_49_IDT ARS_OD_ProbOfExist_Obj_49;
    ARS_OD_DynConf_Obj_49_IDT ARS_OD_DynConf_Obj_49;
    ARS_OD_DynProp_Obj_49_IDT ARS_OD_DynProp_Obj_49;
    ARS_OD_MirrorProb_Obj_49_IDT ARS_OD_MirrorProb_Obj_49;
    ARS_OD_Length_Obj_49_IDT ARS_OD_Length_Obj_49;
    ARS_OD_MaintenanceState_Obj_49_IDT ARS_OD_MaintenanceState_Obj_49;
    ARS_OD_Width_Obj_49_IDT ARS_OD_Width_Obj_49;
    ARS_OD_RCS_Obj_49_IDT ARS_OD_RCS_Obj_49;
    ARS_OD_Orientation_Obj_49_IDT ARS_OD_Orientation_Obj_49;
    ARS_OD_YawRateAbs_Obj_49_IDT ARS_OD_YawRateAbs_Obj_49;
    ARS_OD_YawRateAbsStd_Obj_49_IDT ARS_OD_YawRateAbsStd_Obj_49;
    ARS_OD_RefPoint_Obj_49_IDT ARS_OD_RefPoint_Obj_49;
    ARS_OD_LifeCycle_Obj_49_IDT ARS_OD_LifeCycle_Obj_49;
    ARS_OD_OrientationStd_Obj_48_IDT ARS_OD_OrientationStd_Obj_48;
    ARS_OD_OrientationStd_Obj_49_IDT ARS_OD_OrientationStd_Obj_49;
    ARS_OD_ObstacleProb_Obj_48_IDT ARS_OD_ObstacleProb_Obj_48;
    ARS_OD_MicroDopplerFlag_48_IDT ARS_OD_MicroDopplerFlag_48;
    ARS_OD_ObstacleProb_Obj_49_IDT ARS_OD_ObstacleProb_Obj_49;
    ARS_OD_VabsY_Obj_48_IDT ARS_OD_VabsY_Obj_48;
    ARS_OD_MicroDopplerFlag_49_IDT ARS_OD_MicroDopplerFlag_49;
    ARS_OD_ID_48_IDT ARS_OD_ID_48;
    ARS_OD_ID_49_IDT ARS_OD_ID_49;
    ARS_OD_MsgCounter_Obj_48_49_IDT ARS_OD_MsgCounter_Obj_48_49;
    ARS_OD_CRC16_Checksum_Obj_48_49_IDT ARS_OD_CRC16_Checksum_Obj_48_49;
    ARS_OD_AabsY_Obj_48_IDT ARS_OD_AabsY_Obj_48;
    ARS_OD_DistXStd_Obj_48_IDT ARS_OD_DistXStd_Obj_48;
    ARS_OD_DistYStd_Obj_48_IDT ARS_OD_DistYStd_Obj_48;
    ARS_OD_VabsXStd_Obj_48_IDT ARS_OD_VabsXStd_Obj_48;
    ARS_OD_VabsYStd_Obj_48_IDT ARS_OD_VabsYStd_Obj_48;
    ARS_OD_AabsXStd_Obj_48_IDT ARS_OD_AabsXStd_Obj_48;
} Signal_Group_ARS_OD_48_49_IDT;

typedef struct
{
    ARS_OD_DistX_Obj_50_IDT ARS_OD_DistX_Obj_50;
    ARS_OD_Classification_Obj_50_IDT ARS_OD_Classification_Obj_50;
    ARS_OD_AabsYStd_Obj_50_IDT ARS_OD_AabsYStd_Obj_50;
    ARS_OD_ClassConf_Obj_50_IDT ARS_OD_ClassConf_Obj_50;
    ARS_OD_ProbOfExist_Obj_50_IDT ARS_OD_ProbOfExist_Obj_50;
    ARS_OD_DynConf_Obj_50_IDT ARS_OD_DynConf_Obj_50;
    ARS_OD_VabsX_Obj_50_IDT ARS_OD_VabsX_Obj_50;
    ARS_OD_DynProp_Obj_50_IDT ARS_OD_DynProp_Obj_50;
    ARS_OD_MirrorProb_Obj_50_IDT ARS_OD_MirrorProb_Obj_50;
    ARS_OD_Length_Obj_50_IDT ARS_OD_Length_Obj_50;
    ARS_OD_MaintenanceState_Obj_50_IDT ARS_OD_MaintenanceState_Obj_50;
    ARS_OD_Width_Obj_50_IDT ARS_OD_Width_Obj_50;
    ARS_OD_RCS_Obj_50_IDT ARS_OD_RCS_Obj_50;
    ARS_OD_Orientation_Obj_50_IDT ARS_OD_Orientation_Obj_50;
    ARS_OD_YawRateAbs_Obj_50_IDT ARS_OD_YawRateAbs_Obj_50;
    ARS_OD_YawRateAbsStd_Obj_50_IDT ARS_OD_YawRateAbsStd_Obj_50;
    ARS_OD_RefPoint_Obj_50_IDT ARS_OD_RefPoint_Obj_50;
    ARS_OD_LifeCycle_Obj_50_IDT ARS_OD_LifeCycle_Obj_50;
    ARS_OD_DistX_Obj_51_IDT ARS_OD_DistX_Obj_51;
    ARS_OD_VabsX_Obj_51_IDT ARS_OD_VabsX_Obj_51;
    ARS_OD_AabsX_Obj_51_IDT ARS_OD_AabsX_Obj_51;
    ARS_OD_AabsX_Obj_50_IDT ARS_OD_AabsX_Obj_50;
    ARS_OD_DistY_Obj_51_IDT ARS_OD_DistY_Obj_51;
    ARS_OD_VabsY_Obj_51_IDT ARS_OD_VabsY_Obj_51;
    ARS_OD_AabsY_Obj_51_IDT ARS_OD_AabsY_Obj_51;
    ARS_OD_DistXStd_Obj_51_IDT ARS_OD_DistXStd_Obj_51;
    ARS_OD_DistYStd_Obj_51_IDT ARS_OD_DistYStd_Obj_51;
    ARS_OD_VabsXStd_Obj_51_IDT ARS_OD_VabsXStd_Obj_51;
    ARS_OD_VabsYStd_Obj_51_IDT ARS_OD_VabsYStd_Obj_51;
    ARS_OD_AabsXStd_Obj_51_IDT ARS_OD_AabsXStd_Obj_51;
    ARS_OD_Classification_Obj_51_IDT ARS_OD_Classification_Obj_51;
    ARS_OD_AabsYStd_Obj_51_IDT ARS_OD_AabsYStd_Obj_51;
    ARS_OD_ClassConf_Obj_51_IDT ARS_OD_ClassConf_Obj_51;
    ARS_OD_DistY_Obj_50_IDT ARS_OD_DistY_Obj_50;
    ARS_OD_ProbOfExist_Obj_51_IDT ARS_OD_ProbOfExist_Obj_51;
    ARS_OD_DynConf_Obj_51_IDT ARS_OD_DynConf_Obj_51;
    ARS_OD_DynProp_Obj_51_IDT ARS_OD_DynProp_Obj_51;
    ARS_OD_MirrorProb_Obj_51_IDT ARS_OD_MirrorProb_Obj_51;
    ARS_OD_Length_Obj_51_IDT ARS_OD_Length_Obj_51;
    ARS_OD_MaintenanceState_Obj_51_IDT ARS_OD_MaintenanceState_Obj_51;
    ARS_OD_Width_Obj_51_IDT ARS_OD_Width_Obj_51;
    ARS_OD_RCS_Obj_51_IDT ARS_OD_RCS_Obj_51;
    ARS_OD_Orientation_Obj_51_IDT ARS_OD_Orientation_Obj_51;
    ARS_OD_YawRateAbs_Obj_51_IDT ARS_OD_YawRateAbs_Obj_51;
    ARS_OD_YawRateAbsStd_Obj_51_IDT ARS_OD_YawRateAbsStd_Obj_51;
    ARS_OD_RefPoint_Obj_51_IDT ARS_OD_RefPoint_Obj_51;
    ARS_OD_LifeCycle_Obj_51_IDT ARS_OD_LifeCycle_Obj_51;
    ARS_OD_OrientationStd_Obj_50_IDT ARS_OD_OrientationStd_Obj_50;
    ARS_OD_OrientationStd_Obj_51_IDT ARS_OD_OrientationStd_Obj_51;
    ARS_OD_ObstacleProb_Obj_50_IDT ARS_OD_ObstacleProb_Obj_50;
    ARS_OD_MicroDopplerFlag_50_IDT ARS_OD_MicroDopplerFlag_50;
    ARS_OD_ObstacleProb_Obj_51_IDT ARS_OD_ObstacleProb_Obj_51;
    ARS_OD_VabsY_Obj_50_IDT ARS_OD_VabsY_Obj_50;
    ARS_OD_MicroDopplerFlag_51_IDT ARS_OD_MicroDopplerFlag_51;
    ARS_OD_ID_50_IDT ARS_OD_ID_50;
    ARS_OD_ID_51_IDT ARS_OD_ID_51;
    ARS_OD_MsgCounter_Obj_50_51_IDT ARS_OD_MsgCounter_Obj_50_51;
    ARS_OD_CRC16_Checksum_Obj_50_51_IDT ARS_OD_CRC16_Checksum_Obj_50_51;
    ARS_OD_AabsY_Obj_50_IDT ARS_OD_AabsY_Obj_50;
    ARS_OD_DistXStd_Obj_50_IDT ARS_OD_DistXStd_Obj_50;
    ARS_OD_DistYStd_Obj_50_IDT ARS_OD_DistYStd_Obj_50;
    ARS_OD_VabsXStd_Obj_50_IDT ARS_OD_VabsXStd_Obj_50;
    ARS_OD_VabsYStd_Obj_50_IDT ARS_OD_VabsYStd_Obj_50;
    ARS_OD_AabsXStd_Obj_50_IDT ARS_OD_AabsXStd_Obj_50;
} Signal_Group_ARS_OD_50_51_IDT;

typedef struct
{
    ARS_OD_DistX_Obj_52_IDT ARS_OD_DistX_Obj_52;
    ARS_OD_Classification_Obj_52_IDT ARS_OD_Classification_Obj_52;
    ARS_OD_AabsYStd_Obj_52_IDT ARS_OD_AabsYStd_Obj_52;
    ARS_OD_ClassConf_Obj_52_IDT ARS_OD_ClassConf_Obj_52;
    ARS_OD_ProbOfExist_Obj_52_IDT ARS_OD_ProbOfExist_Obj_52;
    ARS_OD_DynConf_Obj_52_IDT ARS_OD_DynConf_Obj_52;
    ARS_OD_VabsX_Obj_52_IDT ARS_OD_VabsX_Obj_52;
    ARS_OD_DynProp_Obj_52_IDT ARS_OD_DynProp_Obj_52;
    ARS_OD_MirrorProb_Obj_52_IDT ARS_OD_MirrorProb_Obj_52;
    ARS_OD_Length_Obj_52_IDT ARS_OD_Length_Obj_52;
    ARS_OD_MaintenanceState_Obj_52_IDT ARS_OD_MaintenanceState_Obj_52;
    ARS_OD_Width_Obj_52_IDT ARS_OD_Width_Obj_52;
    ARS_OD_RCS_Obj_52_IDT ARS_OD_RCS_Obj_52;
    ARS_OD_Orientation_Obj_52_IDT ARS_OD_Orientation_Obj_52;
    ARS_OD_YawRateAbs_Obj_52_IDT ARS_OD_YawRateAbs_Obj_52;
    ARS_OD_YawRateAbsStd_Obj_52_IDT ARS_OD_YawRateAbsStd_Obj_52;
    ARS_OD_RefPoint_Obj_52_IDT ARS_OD_RefPoint_Obj_52;
    ARS_OD_LifeCycle_Obj_52_IDT ARS_OD_LifeCycle_Obj_52;
    ARS_OD_DistX_Obj_53_IDT ARS_OD_DistX_Obj_53;
    ARS_OD_VabsX_Obj_53_IDT ARS_OD_VabsX_Obj_53;
    ARS_OD_AabsX_Obj_53_IDT ARS_OD_AabsX_Obj_53;
    ARS_OD_AabsX_Obj_52_IDT ARS_OD_AabsX_Obj_52;
    ARS_OD_DistY_Obj_53_IDT ARS_OD_DistY_Obj_53;
    ARS_OD_VabsY_Obj_53_IDT ARS_OD_VabsY_Obj_53;
    ARS_OD_AabsY_Obj_53_IDT ARS_OD_AabsY_Obj_53;
    ARS_OD_DistXStd_Obj_53_IDT ARS_OD_DistXStd_Obj_53;
    ARS_OD_DistYStd_Obj_53_IDT ARS_OD_DistYStd_Obj_53;
    ARS_OD_VabsXStd_Obj_53_IDT ARS_OD_VabsXStd_Obj_53;
    ARS_OD_VabsYStd_Obj_53_IDT ARS_OD_VabsYStd_Obj_53;
    ARS_OD_AabsXStd_Obj_53_IDT ARS_OD_AabsXStd_Obj_53;
    ARS_OD_Classification_Obj_53_IDT ARS_OD_Classification_Obj_53;
    ARS_OD_AabsYStd_Obj_53_IDT ARS_OD_AabsYStd_Obj_53;
    ARS_OD_ClassConf_Obj_53_IDT ARS_OD_ClassConf_Obj_53;
    ARS_OD_DistY_Obj_52_IDT ARS_OD_DistY_Obj_52;
    ARS_OD_ProbOfExist_Obj_53_IDT ARS_OD_ProbOfExist_Obj_53;
    ARS_OD_DynConf_Obj_53_IDT ARS_OD_DynConf_Obj_53;
    ARS_OD_DynProp_Obj_53_IDT ARS_OD_DynProp_Obj_53;
    ARS_OD_MirrorProb_Obj_53_IDT ARS_OD_MirrorProb_Obj_53;
    ARS_OD_Length_Obj_53_IDT ARS_OD_Length_Obj_53;
    ARS_OD_MaintenanceState_Obj_53_IDT ARS_OD_MaintenanceState_Obj_53;
    ARS_OD_Width_Obj_53_IDT ARS_OD_Width_Obj_53;
    ARS_OD_RCS_Obj_53_IDT ARS_OD_RCS_Obj_53;
    ARS_OD_Orientation_Obj_53_IDT ARS_OD_Orientation_Obj_53;
    ARS_OD_YawRateAbs_Obj_53_IDT ARS_OD_YawRateAbs_Obj_53;
    ARS_OD_YawRateAbsStd_Obj_53_IDT ARS_OD_YawRateAbsStd_Obj_53;
    ARS_OD_RefPoint_Obj_53_IDT ARS_OD_RefPoint_Obj_53;
    ARS_OD_LifeCycle_Obj_53_IDT ARS_OD_LifeCycle_Obj_53;
    ARS_OD_OrientationStd_Obj_52_IDT ARS_OD_OrientationStd_Obj_52;
    ARS_OD_OrientationStd_Obj_53_IDT ARS_OD_OrientationStd_Obj_53;
    ARS_OD_ObstacleProb_Obj_52_IDT ARS_OD_ObstacleProb_Obj_52;
    ARS_OD_MicroDopplerFlag_52_IDT ARS_OD_MicroDopplerFlag_52;
    ARS_OD_ObstacleProb_Obj_53_IDT ARS_OD_ObstacleProb_Obj_53;
    ARS_OD_VabsY_Obj_52_IDT ARS_OD_VabsY_Obj_52;
    ARS_OD_MicroDopplerFlag_53_IDT ARS_OD_MicroDopplerFlag_53;
    ARS_OD_ID_52_IDT ARS_OD_ID_52;
    ARS_OD_ID_53_IDT ARS_OD_ID_53;
    ARS_OD_MsgCounter_Obj_52_53_IDT ARS_OD_MsgCounter_Obj_52_53;
    ARS_OD_CRC16_Checksum_Obj_52_53_IDT ARS_OD_CRC16_Checksum_Obj_52_53;
    ARS_OD_AabsY_Obj_52_IDT ARS_OD_AabsY_Obj_52;
    ARS_OD_DistXStd_Obj_52_IDT ARS_OD_DistXStd_Obj_52;
    ARS_OD_DistYStd_Obj_52_IDT ARS_OD_DistYStd_Obj_52;
    ARS_OD_VabsXStd_Obj_52_IDT ARS_OD_VabsXStd_Obj_52;
    ARS_OD_VabsYStd_Obj_52_IDT ARS_OD_VabsYStd_Obj_52;
    ARS_OD_AabsXStd_Obj_52_IDT ARS_OD_AabsXStd_Obj_52;
} Signal_Group_ARS_OD_52_53_IDT;

typedef struct
{
    ARS_OD_DistX_Obj_54_IDT ARS_OD_DistX_Obj_54;
    ARS_OD_Classification_Obj_54_IDT ARS_OD_Classification_Obj_54;
    ARS_OD_AabsYStd_Obj_54_IDT ARS_OD_AabsYStd_Obj_54;
    ARS_OD_ClassConf_Obj_54_IDT ARS_OD_ClassConf_Obj_54;
    ARS_OD_ProbOfExist_Obj_54_IDT ARS_OD_ProbOfExist_Obj_54;
    ARS_OD_DynConf_Obj_54_IDT ARS_OD_DynConf_Obj_54;
    ARS_OD_VabsX_Obj_54_IDT ARS_OD_VabsX_Obj_54;
    ARS_OD_DynProp_Obj_54_IDT ARS_OD_DynProp_Obj_54;
    ARS_OD_MirrorProb_Obj_54_IDT ARS_OD_MirrorProb_Obj_54;
    ARS_OD_Length_Obj_54_IDT ARS_OD_Length_Obj_54;
    ARS_OD_MaintenanceState_Obj_54_IDT ARS_OD_MaintenanceState_Obj_54;
    ARS_OD_Width_Obj_54_IDT ARS_OD_Width_Obj_54;
    ARS_OD_RCS_Obj_54_IDT ARS_OD_RCS_Obj_54;
    ARS_OD_Orientation_Obj_54_IDT ARS_OD_Orientation_Obj_54;
    ARS_OD_YawRateAbs_Obj_54_IDT ARS_OD_YawRateAbs_Obj_54;
    ARS_OD_YawRateAbsStd_Obj_54_IDT ARS_OD_YawRateAbsStd_Obj_54;
    ARS_OD_RefPoint_Obj_54_IDT ARS_OD_RefPoint_Obj_54;
    ARS_OD_LifeCycle_Obj_54_IDT ARS_OD_LifeCycle_Obj_54;
    ARS_OD_DistX_Obj_55_IDT ARS_OD_DistX_Obj_55;
    ARS_OD_VabsX_Obj_55_IDT ARS_OD_VabsX_Obj_55;
    ARS_OD_AabsX_Obj_55_IDT ARS_OD_AabsX_Obj_55;
    ARS_OD_AabsX_Obj_54_IDT ARS_OD_AabsX_Obj_54;
    ARS_OD_DistY_Obj_55_IDT ARS_OD_DistY_Obj_55;
    ARS_OD_VabsY_Obj_55_IDT ARS_OD_VabsY_Obj_55;
    ARS_OD_AabsY_Obj_55_IDT ARS_OD_AabsY_Obj_55;
    ARS_OD_DistXStd_Obj_55_IDT ARS_OD_DistXStd_Obj_55;
    ARS_OD_DistYStd_Obj_55_IDT ARS_OD_DistYStd_Obj_55;
    ARS_OD_VabsXStd_Obj_55_IDT ARS_OD_VabsXStd_Obj_55;
    ARS_OD_VabsYStd_Obj_55_IDT ARS_OD_VabsYStd_Obj_55;
    ARS_OD_AabsXStd_Obj_55_IDT ARS_OD_AabsXStd_Obj_55;
    ARS_OD_Classification_Obj_55_IDT ARS_OD_Classification_Obj_55;
    ARS_OD_AabsYStd_Obj_55_IDT ARS_OD_AabsYStd_Obj_55;
    ARS_OD_ClassConf_Obj_55_IDT ARS_OD_ClassConf_Obj_55;
    ARS_OD_DistY_Obj_54_IDT ARS_OD_DistY_Obj_54;
    ARS_OD_ProbOfExist_Obj_55_IDT ARS_OD_ProbOfExist_Obj_55;
    ARS_OD_DynConf_Obj_55_IDT ARS_OD_DynConf_Obj_55;
    ARS_OD_DynProp_Obj_55_IDT ARS_OD_DynProp_Obj_55;
    ARS_OD_MirrorProb_Obj_55_IDT ARS_OD_MirrorProb_Obj_55;
    ARS_OD_Length_Obj_55_IDT ARS_OD_Length_Obj_55;
    ARS_OD_MaintenanceState_Obj_55_IDT ARS_OD_MaintenanceState_Obj_55;
    ARS_OD_Width_Obj_55_IDT ARS_OD_Width_Obj_55;
    ARS_OD_RCS_Obj_55_IDT ARS_OD_RCS_Obj_55;
    ARS_OD_Orientation_Obj_55_IDT ARS_OD_Orientation_Obj_55;
    ARS_OD_YawRateAbs_Obj_55_IDT ARS_OD_YawRateAbs_Obj_55;
    ARS_OD_YawRateAbsStd_Obj_55_IDT ARS_OD_YawRateAbsStd_Obj_55;
    ARS_OD_RefPoint_Obj_55_IDT ARS_OD_RefPoint_Obj_55;
    ARS_OD_LifeCycle_Obj_55_IDT ARS_OD_LifeCycle_Obj_55;
    ARS_OD_OrientationStd_Obj_54_IDT ARS_OD_OrientationStd_Obj_54;
    ARS_OD_OrientationStd_Obj_55_IDT ARS_OD_OrientationStd_Obj_55;
    ARS_OD_ObstacleProb_Obj_54_IDT ARS_OD_ObstacleProb_Obj_54;
    ARS_OD_MicroDopplerFlag_54_IDT ARS_OD_MicroDopplerFlag_54;
    ARS_OD_ObstacleProb_Obj_55_IDT ARS_OD_ObstacleProb_Obj_55;
    ARS_OD_VabsY_Obj_54_IDT ARS_OD_VabsY_Obj_54;
    ARS_OD_MicroDopplerFlag_55_IDT ARS_OD_MicroDopplerFlag_55;
    ARS_OD_ID_54_IDT ARS_OD_ID_54;
    ARS_OD_ID_55_IDT ARS_OD_ID_55;
    ARS_OD_MsgCounter_Obj_54_55_IDT ARS_OD_MsgCounter_Obj_54_55;
    ARS_OD_CRC16_Checksum_Obj_54_55_IDT ARS_OD_CRC16_Checksum_Obj_54_55;
    ARS_OD_AabsY_Obj_54_IDT ARS_OD_AabsY_Obj_54;
    ARS_OD_DistXStd_Obj_54_IDT ARS_OD_DistXStd_Obj_54;
    ARS_OD_DistYStd_Obj_54_IDT ARS_OD_DistYStd_Obj_54;
    ARS_OD_VabsXStd_Obj_54_IDT ARS_OD_VabsXStd_Obj_54;
    ARS_OD_VabsYStd_Obj_54_IDT ARS_OD_VabsYStd_Obj_54;
    ARS_OD_AabsXStd_Obj_54_IDT ARS_OD_AabsXStd_Obj_54;
} Signal_Group_ARS_OD_54_55_IDT;

typedef struct
{
    ARS_OD_DistX_Obj_56_IDT ARS_OD_DistX_Obj_56;
    ARS_OD_Classification_Obj_56_IDT ARS_OD_Classification_Obj_56;
    ARS_OD_AabsYStd_Obj_56_IDT ARS_OD_AabsYStd_Obj_56;
    ARS_OD_ClassConf_Obj_56_IDT ARS_OD_ClassConf_Obj_56;
    ARS_OD_ProbOfExist_Obj_56_IDT ARS_OD_ProbOfExist_Obj_56;
    ARS_OD_DynConf_Obj_56_IDT ARS_OD_DynConf_Obj_56;
    ARS_OD_VabsX_Obj_56_IDT ARS_OD_VabsX_Obj_56;
    ARS_OD_DynProp_Obj_56_IDT ARS_OD_DynProp_Obj_56;
    ARS_OD_MirrorProb_Obj_56_IDT ARS_OD_MirrorProb_Obj_56;
    ARS_OD_Length_Obj_56_IDT ARS_OD_Length_Obj_56;
    ARS_OD_MaintenanceState_Obj_56_IDT ARS_OD_MaintenanceState_Obj_56;
    ARS_OD_Width_Obj_56_IDT ARS_OD_Width_Obj_56;
    ARS_OD_RCS_Obj_56_IDT ARS_OD_RCS_Obj_56;
    ARS_OD_Orientation_Obj_56_IDT ARS_OD_Orientation_Obj_56;
    ARS_OD_YawRateAbs_Obj_56_IDT ARS_OD_YawRateAbs_Obj_56;
    ARS_OD_YawRateAbsStd_Obj_56_IDT ARS_OD_YawRateAbsStd_Obj_56;
    ARS_OD_RefPoint_Obj_56_IDT ARS_OD_RefPoint_Obj_56;
    ARS_OD_LifeCycle_Obj_56_IDT ARS_OD_LifeCycle_Obj_56;
    ARS_OD_DistX_Obj_57_IDT ARS_OD_DistX_Obj_57;
    ARS_OD_VabsX_Obj_57_IDT ARS_OD_VabsX_Obj_57;
    ARS_OD_AabsX_Obj_57_IDT ARS_OD_AabsX_Obj_57;
    ARS_OD_AabsX_Obj_56_IDT ARS_OD_AabsX_Obj_56;
    ARS_OD_DistY_Obj_57_IDT ARS_OD_DistY_Obj_57;
    ARS_OD_VabsY_Obj_57_IDT ARS_OD_VabsY_Obj_57;
    ARS_OD_AabsY_Obj_57_IDT ARS_OD_AabsY_Obj_57;
    ARS_OD_DistXStd_Obj_57_IDT ARS_OD_DistXStd_Obj_57;
    ARS_OD_DistYStd_Obj_57_IDT ARS_OD_DistYStd_Obj_57;
    ARS_OD_VabsXStd_Obj_57_IDT ARS_OD_VabsXStd_Obj_57;
    ARS_OD_VabsYStd_Obj_57_IDT ARS_OD_VabsYStd_Obj_57;
    ARS_OD_AabsXStd_Obj_57_IDT ARS_OD_AabsXStd_Obj_57;
    ARS_OD_Classification_Obj_57_IDT ARS_OD_Classification_Obj_57;
    ARS_OD_AabsYStd_Obj_57_IDT ARS_OD_AabsYStd_Obj_57;
    ARS_OD_ClassConf_Obj_57_IDT ARS_OD_ClassConf_Obj_57;
    ARS_OD_DistY_Obj_56_IDT ARS_OD_DistY_Obj_56;
    ARS_OD_ProbOfExist_Obj_57_IDT ARS_OD_ProbOfExist_Obj_57;
    ARS_OD_DynConf_Obj_57_IDT ARS_OD_DynConf_Obj_57;
    ARS_OD_DynProp_Obj_57_IDT ARS_OD_DynProp_Obj_57;
    ARS_OD_MirrorProb_Obj_57_IDT ARS_OD_MirrorProb_Obj_57;
    ARS_OD_Length_Obj_57_IDT ARS_OD_Length_Obj_57;
    ARS_OD_MaintenanceState_Obj_57_IDT ARS_OD_MaintenanceState_Obj_57;
    ARS_OD_Width_Obj_57_IDT ARS_OD_Width_Obj_57;
    ARS_OD_RCS_Obj_57_IDT ARS_OD_RCS_Obj_57;
    ARS_OD_Orientation_Obj_57_IDT ARS_OD_Orientation_Obj_57;
    ARS_OD_YawRateAbs_Obj_57_IDT ARS_OD_YawRateAbs_Obj_57;
    ARS_OD_YawRateAbsStd_Obj_57_IDT ARS_OD_YawRateAbsStd_Obj_57;
    ARS_OD_RefPoint_Obj_57_IDT ARS_OD_RefPoint_Obj_57;
    ARS_OD_LifeCycle_Obj_57_IDT ARS_OD_LifeCycle_Obj_57;
    ARS_OD_OrientationStd_Obj_56_IDT ARS_OD_OrientationStd_Obj_56;
    ARS_OD_OrientationStd_Obj_57_IDT ARS_OD_OrientationStd_Obj_57;
    ARS_OD_ObstacleProb_Obj_56_IDT ARS_OD_ObstacleProb_Obj_56;
    ARS_OD_MicroDopplerFlag_56_IDT ARS_OD_MicroDopplerFlag_56;
    ARS_OD_ObstacleProb_Obj_57_IDT ARS_OD_ObstacleProb_Obj_57;
    ARS_OD_VabsY_Obj_56_IDT ARS_OD_VabsY_Obj_56;
    ARS_OD_MicroDopplerFlag_57_IDT ARS_OD_MicroDopplerFlag_57;
    ARS_OD_ID_56_IDT ARS_OD_ID_56;
    ARS_OD_ID_57_IDT ARS_OD_ID_57;
    ARS_OD_MsgCounter_Obj_56_57_IDT ARS_OD_MsgCounter_Obj_56_57;
    ARS_OD_CRC16_Checksum_Obj_56_57_IDT ARS_OD_CRC16_Checksum_Obj_56_57;
    ARS_OD_AabsY_Obj_56_IDT ARS_OD_AabsY_Obj_56;
    ARS_OD_DistXStd_Obj_56_IDT ARS_OD_DistXStd_Obj_56;
    ARS_OD_DistYStd_Obj_56_IDT ARS_OD_DistYStd_Obj_56;
    ARS_OD_VabsXStd_Obj_56_IDT ARS_OD_VabsXStd_Obj_56;
    ARS_OD_VabsYStd_Obj_56_IDT ARS_OD_VabsYStd_Obj_56;
    ARS_OD_AabsXStd_Obj_56_IDT ARS_OD_AabsXStd_Obj_56;
} Signal_Group_ARS_OD_56_57_IDT;

typedef struct
{
    ARS_OD_DistX_Obj_58_IDT ARS_OD_DistX_Obj_58;
    ARS_OD_Classification_Obj_58_IDT ARS_OD_Classification_Obj_58;
    ARS_OD_AabsYStd_Obj_58_IDT ARS_OD_AabsYStd_Obj_58;
    ARS_OD_ClassConf_Obj_58_IDT ARS_OD_ClassConf_Obj_58;
    ARS_OD_ProbOfExist_Obj_58_IDT ARS_OD_ProbOfExist_Obj_58;
    ARS_OD_DynConf_Obj_58_IDT ARS_OD_DynConf_Obj_58;
    ARS_OD_VabsX_Obj_58_IDT ARS_OD_VabsX_Obj_58;
    ARS_OD_DynProp_Obj_58_IDT ARS_OD_DynProp_Obj_58;
    ARS_OD_MirrorProb_Obj_58_IDT ARS_OD_MirrorProb_Obj_58;
    ARS_OD_Length_Obj_58_IDT ARS_OD_Length_Obj_58;
    ARS_OD_MaintenanceState_Obj_58_IDT ARS_OD_MaintenanceState_Obj_58;
    ARS_OD_Width_Obj_58_IDT ARS_OD_Width_Obj_58;
    ARS_OD_RCS_Obj_58_IDT ARS_OD_RCS_Obj_58;
    ARS_OD_Orientation_Obj_58_IDT ARS_OD_Orientation_Obj_58;
    ARS_OD_YawRateAbs_Obj_58_IDT ARS_OD_YawRateAbs_Obj_58;
    ARS_OD_YawRateAbsStd_Obj_58_IDT ARS_OD_YawRateAbsStd_Obj_58;
    ARS_OD_RefPoint_Obj_58_IDT ARS_OD_RefPoint_Obj_58;
    ARS_OD_LifeCycle_Obj_58_IDT ARS_OD_LifeCycle_Obj_58;
    ARS_OD_DistX_Obj_59_IDT ARS_OD_DistX_Obj_59;
    ARS_OD_VabsX_Obj_59_IDT ARS_OD_VabsX_Obj_59;
    ARS_OD_AabsX_Obj_59_IDT ARS_OD_AabsX_Obj_59;
    ARS_OD_AabsX_Obj_58_IDT ARS_OD_AabsX_Obj_58;
    ARS_OD_DistY_Obj_59_IDT ARS_OD_DistY_Obj_59;
    ARS_OD_VabsY_Obj_59_IDT ARS_OD_VabsY_Obj_59;
    ARS_OD_AabsY_Obj_59_IDT ARS_OD_AabsY_Obj_59;
    ARS_OD_DistXStd_Obj_59_IDT ARS_OD_DistXStd_Obj_59;
    ARS_OD_DistYStd_Obj_59_IDT ARS_OD_DistYStd_Obj_59;
    ARS_OD_VabsXStd_Obj_59_IDT ARS_OD_VabsXStd_Obj_59;
    ARS_OD_VabsYStd_Obj_59_IDT ARS_OD_VabsYStd_Obj_59;
    ARS_OD_AabsXStd_Obj_59_IDT ARS_OD_AabsXStd_Obj_59;
    ARS_OD_Classification_Obj_59_IDT ARS_OD_Classification_Obj_59;
    ARS_OD_AabsYStd_Obj_59_IDT ARS_OD_AabsYStd_Obj_59;
    ARS_OD_ClassConf_Obj_59_IDT ARS_OD_ClassConf_Obj_59;
    ARS_OD_DistY_Obj_58_IDT ARS_OD_DistY_Obj_58;
    ARS_OD_ProbOfExist_Obj_59_IDT ARS_OD_ProbOfExist_Obj_59;
    ARS_OD_DynConf_Obj_59_IDT ARS_OD_DynConf_Obj_59;
    ARS_OD_DynProp_Obj_59_IDT ARS_OD_DynProp_Obj_59;
    ARS_OD_MirrorProb_Obj_59_IDT ARS_OD_MirrorProb_Obj_59;
    ARS_OD_Length_Obj_59_IDT ARS_OD_Length_Obj_59;
    ARS_OD_MaintenanceState_Obj_59_IDT ARS_OD_MaintenanceState_Obj_59;
    ARS_OD_Width_Obj_59_IDT ARS_OD_Width_Obj_59;
    ARS_OD_RCS_Obj_59_IDT ARS_OD_RCS_Obj_59;
    ARS_OD_Orientation_Obj_59_IDT ARS_OD_Orientation_Obj_59;
    ARS_OD_YawRateAbs_Obj_59_IDT ARS_OD_YawRateAbs_Obj_59;
    ARS_OD_YawRateAbsStd_Obj_59_IDT ARS_OD_YawRateAbsStd_Obj_59;
    ARS_OD_RefPoint_Obj_59_IDT ARS_OD_RefPoint_Obj_59;
    ARS_OD_LifeCycle_Obj_59_IDT ARS_OD_LifeCycle_Obj_59;
    ARS_OD_OrientationStd_Obj_58_IDT ARS_OD_OrientationStd_Obj_58;
    ARS_OD_OrientationStd_Obj_59_IDT ARS_OD_OrientationStd_Obj_59;
    ARS_OD_ObstacleProb_Obj_58_IDT ARS_OD_ObstacleProb_Obj_58;
    ARS_OD_MicroDopplerFlag_58_IDT ARS_OD_MicroDopplerFlag_58;
    ARS_OD_ObstacleProb_Obj_59_IDT ARS_OD_ObstacleProb_Obj_59;
    ARS_OD_VabsY_Obj_58_IDT ARS_OD_VabsY_Obj_58;
    ARS_OD_MicroDopplerFlag_59_IDT ARS_OD_MicroDopplerFlag_59;
    ARS_OD_ID_58_IDT ARS_OD_ID_58;
    ARS_OD_ID_59_IDT ARS_OD_ID_59;
    ARS_OD_MsgCounter_Obj_58_59_IDT ARS_OD_MsgCounter_Obj_58_59;
    ARS_OD_CRC16_Checksum_Obj_58_59_IDT ARS_OD_CRC16_Checksum_Obj_58_59;
    ARS_OD_AabsY_Obj_58_IDT ARS_OD_AabsY_Obj_58;
    ARS_OD_DistXStd_Obj_58_IDT ARS_OD_DistXStd_Obj_58;
    ARS_OD_DistYStd_Obj_58_IDT ARS_OD_DistYStd_Obj_58;
    ARS_OD_VabsXStd_Obj_58_IDT ARS_OD_VabsXStd_Obj_58;
    ARS_OD_VabsYStd_Obj_58_IDT ARS_OD_VabsYStd_Obj_58;
    ARS_OD_AabsXStd_Obj_58_IDT ARS_OD_AabsXStd_Obj_58;
} Signal_Group_ARS_OD_58_59_IDT;

typedef struct
{
    ARS_OD_TimeStampGlobSec_IDT ARS_OD_TimeStampGlobSec;
    ARS_OD_CycleCounter_IDT ARS_OD_CycleCounter;
    ARS_OD_NumOfObjects_IDT ARS_OD_NumOfObjects;
    ARS_OD_TaskValidFlag_IDT ARS_OD_TaskValidFlag;
    ARS_OD_ExtendedCycleFlag_IDT ARS_OD_ExtendedCycleFlag;
    ARS_OD_Latency_IDT ARS_OD_Latency;
    ARS_OD_EgoVelocity_IDT ARS_OD_EgoVelocity;
    ARS_OD_EgoYawRate_IDT ARS_OD_EgoYawRate;
    ARS_OD_EgoVelocityStd_IDT ARS_OD_EgoVelocityStd;
    ARS_OD_EgoAcceleration_IDT ARS_OD_EgoAcceleration;
    ARS_OD_EgoCurvature_IDT ARS_OD_EgoCurvature;
    ARS_OD_MsgCounter_Header_IDT ARS_OD_MsgCounter_Header;
    ARS_OD_CRC16_Checksum_Header_IDT ARS_OD_CRC16_Checksum_Header;
    ARS_OD_TimeStampGlobNanoSec_IDT ARS_OD_TimeStampGlobNanoSec;
    ARS_OD_TimeStampLocal_IDT ARS_OD_TimeStampLocal;
    ARS_OD_MeasCounter_IDT ARS_OD_MeasCounter;
} Signal_Group_ARS_OD_Header_IDT;

typedef struct
{
    ARS_SP_MsgCounter_IDT ARS_SP_MsgCounter;
    ARS_SP_CRC16_Checksum_IDT ARS_SP_CRC16_Checksum;
    ARS_SP_ErrStateGroup_1_IDT ARS_SP_ErrStateGroup_1;
    ARS_SP_ErrStateGroup_2_IDT ARS_SP_ErrStateGroup_2;
    ARS_SP_ErrStateGroup_3_IDT ARS_SP_ErrStateGroup_3;
} Signal_Group_ARS_SYS_PERFORM_IDT;

typedef struct
{
    ARS_TSYNC_TimeStampGlobSec_IDT ARS_TSYNC_TimeStampGlobSec;
    ARS_TSYNC_CRC16_Checksum_IDT ARS_TSYNC_CRC16_Checksum;
    ARS_TSYNC_TimeStampGlobNSec_IDT ARS_TSYNC_TimeStampGlobNSec;
    ARS_TSYNC_MaxTimeLeap_IDT ARS_TSYNC_MaxTimeLeap;
    ARS_TSYNC_LastTimeLeap_IDT ARS_TSYNC_LastTimeLeap;
    ARS_TSYNC_MsgCounter_IDT ARS_TSYNC_MsgCounter;
} Signal_Group_ARS_TIME_SYNC_IDT;

// typedef uint8 StbM_TimeBaseStatusType;
// typedef struct
// {
//     uint32 nanoseconds;
//     uint64 seconds;
// } StbM_TimeStampExtendedType;

// typedef struct
// {
//     uint32 nanoseconds;
//     uint32 seconds;
//     uint16 secondsHi;
// } StbM_TimeStampType;

// typedef struct
// {
//     uint8 userDataLength;
//     uint8 userByte0;
//     uint8 userByte1;
//     uint8 userByte2;
// } StbM_UserDataType;

typedef uint8 TPMS_FLTirePress;
typedef uint8 TPMS_FRTirePress;
typedef uint8 TPMS_LFpressureSts_IDT;
typedef uint8 TPMS_LFpressureV_IDT;
typedef uint8 TPMS_LFpressure_IDT;
typedef uint8 TPMS_LRpressureSts_IDT;
typedef uint8 TPMS_LRpressureV_IDT;
typedef uint8 TPMS_LRpressure_IDT;
typedef uint8 TPMS_RFpressureSts_IDT;
typedef uint8 TPMS_RFpressureV_IDT;
typedef uint8 TPMS_RFpressure_IDT;
typedef uint8 TPMS_RLTirePress;
typedef uint8 TPMS_RRTirePress;
typedef uint8 TPMS_RRpressureSts_IDT;
typedef uint8 TPMS_RRpressureV_IDT;
typedef uint8 TPMS_RRpressure_IDT;
typedef uint8 TPMS_SysSts_IDT;
typedef uint8 TSR_SLWFuncSwtReq_IDT;
typedef uint8 TSR_SLWSwtResp_IDT;
typedef uint8 TSR_SLWVisualWarn_IDT;
typedef uint8 TSR_SLWVoiceWarn_IDT;
typedef uint8 TSR_SpdAssistInfoDisp_IDT;
typedef uint8 TSR_SpdWarningOffs_S_IDT;
typedef uint8 TSR_TrafSign_IDT;
typedef uint8 TSR_WarningOffset_IDT;
typedef uint8 TSR_Warning_offset_IDT;
typedef uint8 Tcp_ReceiveSignal_1601_IDT[1017];
typedef uint8 Tcp_ReceiveSignal_1602_IDT[10643];
typedef uint8 Tcp_ReceiveSignal_1603_IDT[4857];
typedef uint8 Tcp_ReceiveSignal_1604_IDT[84];
typedef uint8 Tcp_ReceiveSignal_1605_IDT[6788];
typedef uint8 Tcp_ReceiveSignal_1606_IDT[713];
typedef uint8 Tcp_ReceiveSignal_1607_IDT[4248];
typedef uint8 Tcp_ReceiveSignal_1608_IDT[406];
typedef uint8 Tcp_ReceiveSignal_IDT[9];
typedef uint8 Tcp_SendSignal_IDT[9];
typedef uint8 Time_Day_IDT;
typedef uint8 Time_Hour_IDT;
typedef uint8 Time_Minute_IDT;
typedef uint8 Time_Month_IDT;
typedef uint8 Time_Year_IDT;
typedef uint8 Time_second_IDT;
typedef uint8 Udp_ReceiveSignal_IDT[9];
typedef uint8 Udp_SendSignal_1501_IDT[594];
typedef uint8 Udp_SendSignal_1502_IDT[1294];
typedef uint8 Udp_SendSignal_1503_IDT[23];
typedef uint8 Udp_SendSignal_1504_IDT[423];
typedef uint8 Udp_SendSignal_1505_IDT[942];
typedef uint8 Udp_SendSignal_1506_IDT[13];
typedef uint8 Udp_SendSignal_1507_IDT[208];
typedef uint8 Udp_SendSignal_IDT[9];
typedef uint16 distance_12[12];
typedef struct
{
    distance_12 distance;
    uint64 time_stamp;
} UpaDistT;

typedef sint32 x_6[6];
typedef sint32 y_6[6];
typedef uint8 type_6[6];
typedef struct
{
    x_6 x;
    y_6 y;
    type_6 type;
    uint64 time_stamp;
} UpaObjectInfo;

typedef UpaObjectInfo upa_object_3[3];
typedef struct
{
    upa_object_3 upa_object;
} UpaObjsT;

typedef struct
{
    uint8 polling_mode;
    uint8 dispatching_cycle;
} UssDataFeedBack;

typedef ApaDistT apa_dist_info_4[4];
typedef UpaObjsT upa_objs_2[2];
typedef UpaDistT upa_dist_2[2];
typedef uint16 min_distance_12[12];
typedef struct
{
    uint64 time_stamp;
    apa_dist_info_4 apa_dist_info;
    upa_objs_2 upa_objs;
    upa_dist_2 upa_dist;
    min_distance_12 min_distance;
} UssInfo;

typedef uint16 ring_time_uint16_array_12[12];
typedef uint8 reserved_data_uint8_array_56[56];
typedef struct
{
    ring_time_uint16_array_12 ring_time;
    reserved_data_uint8_array_56 reserved_data;
} UssNvmData;

typedef struct
{
    uint64 time_stamp;
    uint8 fpa_audible_alarm;
    uint8 rpa_audible_alarm;
    float32 fpa_min_dist;
    float32 rpa_min_dist;
    float32 pa_obstacles_mindist;
    uint8 fpa_obstacles_area;
    uint8 rpa_obstacles_area;
    uint8 pa_obstacles_area;
    PdcAlertInfo pdc_alert_info;
    PdcSideInfo_3 pdc_side_info;
    PdcDistInfo pdc_dist_info;
    PdcDistInfoAvm pdc_dist_info_avm;
    float32 reserved_a;
    float32 reserved_b;
    float32 reserved_c;
} UssPdcInfo;

typedef uint16 distance_10[10];
typedef uint16 width_10[10];
typedef uint8 peak_10[10];
typedef struct
{
    uint8 echo_num;
    distance_10 distance;
    width_10 width;
    peak_10 peak;
    uint16 ring_time;
    uint8 valid_fram;
    uint8 confidence;
    uint8 status_work;
    uint8 counter;
    uint64 system_time;
} UssRawData;

typedef UssRawData sensor_info_12[12];
typedef struct
{
    uint64 time_stamp;
    uint8 counter;
    sensor_info_12 sensor_info;
} UssRawDataSet;

typedef struct
{
    uint16 diagnosis_info;
    uint8 remind_info;
    uint8 counter;
    uint64 system_time;
} UssStatus;

typedef UssStatus sensor_status_12[12];
typedef struct
{
    uint64 time_stamp;
    uint8 counter;
    sensor_status_12 sensor_status;
} UssStatusSet;

typedef uint16 VCU_ACPD_Percent;
typedef uint8 VCU_AccPedal_Valid_IDT;
typedef uint8 VCU_P_Sts_IDT;
typedef struct
{
    uint64 time_stamp;
    uint64 time_stamp_can;
    float32 SAS_SteerWheelAngle;
    uint8 SAS_SteeringAngleValid;
    float32 SAS_SteerWhlRotSpd;
    uint8 SAS_SteerWhlRotSpdStatus;
    uint8 SAS_SASFailure;
    uint8 SAS_Calibrated;
    float32 EPS_LKARespTorq;
    uint8 EPS_SterFltMod;
    float32 EPS_DrStrTorqVal;
    uint8 EPS_ADAS_CtrlAbortFeedback;
    uint8 EPS_ADAS_ModActv;
    uint8 EPS_ADAS_ModAvail;
    uint8 ACU_DSeatbeltBucklestatus;
    uint8 ACU_CoDSeatbeltBucklestatus;
    float32 IPC_IPCTotalOdometer;
    uint8 IPC_IPCTotalOdometerV;
    float32 CCU_ExternalTemperature;
    uint8 VCU_ModeGearSts;
    uint8 VCU_Ready;
    uint8 VCU_LimpHomeSts;
    uint8 VCU_StsSysFault;
    float32 VCU_AccPedalPosition;
    uint8 VCU_AccPedal_Valid;
    uint8 VCU_StsAccPedalFault;
    uint8 MHU_LSS_Req;
    uint8 MHU_LSS_Mode;
    uint8 MHU_LSS_Warning_method;
    uint8 MHU_TSR_Req;
    uint8 TSR_SpdWarningOffs_S;
    uint8 TSR_SLWFuncSwtReq;
    uint8 AEB_FuncSwtReq;
    uint8 AEB_FCW_SnvtyReq;
    uint8 BSD_LCA_FuncSWReq;
    uint8 RCTA_FuncSWReq;
    uint8 DOW_FuncSWReq;
    uint8 RCW_FuncSWReq;
    uint8 MHU_DM_SwitchModeSts;
    uint8 MHU_Trailermode_Req;
    uint8 MFS_ACC_CruiseOn_Off;
    uint8 MFS_ACC_CruiseGapSet;
    uint8 MFS_ACC_CruiseCancel;
    uint8 MFS_ACC_CruiseSpdDecrease;
    uint8 MFS_ACC_CruiseSpdIncrease;
    uint32 Nav_RoadType;
    uint8 Nav_errorSts;
    float32 Nav_VehToTrafEyeDist;
    uint8 Nav_SpdLimValue;
    uint8 Nav_SpdLimType;
    uint8 Nav_SpdLimUnit;
    uint8 Nav_TSRTrafSign;
    uint8 Nav_CtryType;
    uint8 Time_second;
    uint8 GPSSystAtv;
    uint8 Time_Minute;
    uint8 Time_Hour;
    uint8 Time_Day;
    uint8 Time_Month;
    uint8 Time_Year;
    uint8 BCM_FrontWipeSWSts;
    uint8 BCM_AutoWipeSts;
    uint8 BCM_FrontWipeSts;
    uint8 BCM_TurnIndicatorSts;
    uint8 BCM_TurnLight_FaultSts;
    uint8 BCM_FrontFogLampLightSts;
    uint8 BCM_CoverAjarStatus;
    uint8 BCM_TrunckAjarStatus;
    uint8 BCM_DriverSideDoorAjarSts;
    uint8 BCM_CodriversSideDoorAjarSts;
    uint8 BCM_RearLeftDoorAjarStatus;
    uint8 BCM_RearRightDoorAjarStatus;
    uint8 BCM_DoorLockStatusRL;
    uint8 BCM_DoorLockStatusRR;
    uint8 BCM_DoorLockStatusCodrivres;
    uint8 BCM_DoorLockStatusDrv;
    uint8 PEPS_PowerMode;
    uint8 PEPS_PowerModeValidity;
    uint8 RLS_Rainfall_magnitude;
    uint8 BCM_TurnLightSWSts;
    uint8 ABSActive;
    float32 ABS_VehicleSpeed;
    uint8 ABS_VehicleSpeedInvalid;
    uint8 AB_BrkPedalSwSts;
    uint8 AB_BrkPedalSwStsV;
    uint8 AB_Fault_Status;
    float32 AB_BrkPedalPct;
    float32 AB_BrkPedalTravel;
    float32 ESC_MasterCylinderPressure;
    uint8 ESC_MasterCylinderPressureV;
    uint8 EPB_AVHStatIndReqV;
    uint8 EPB_AVHFeedbackSts;
    uint8 EPB_Sts;
    uint8 ESC_HSA_Control_Status;
    uint8 ESC_TcsDisableSts;
    uint8 ESC_EscCtrlActv;
    uint8 ESC_TcsCtrlActv;
    uint8 ESC_EscDisableSts;
    uint8 IBS_ESCOFF_StsFB;
    uint8 WCBS_ACC_VLC_Active;
    uint8 WCBS_ACC_CDD_Active;
    uint8 WCBS_ACC_VLC_Avl;
    uint8 WCBS_ACC_CDD_Avl;
    uint8 WCBS_ABAAtv;
    uint8 WCBS_ABAAva;
    uint8 WCBS_ABPAtv;
    uint8 WCBS_ABPAva;
    uint8 WCBS_AWBAtv;
    uint8 WCBS_AWBAvl;
    uint8 WCBS_AEBAtv;
    uint8 WCBS_AEBAva;
    uint8 WCBS_VStandstillSta;
    uint8 WCBS_BrkFrcSta;
    uint8 WCBS_ESCDeteACCErroSta;
    uint8 ESC_LateralACC_Valid;
    uint8 ESC_LongitudeACC_Valid;
    uint8 ESC_VehDynYawRate_Valid;
    float32 ESC_LateralACC;
    float32 ESC_VehDynYawRate;
    float32 ESC_LongitudeACC;
    float32 ABS_FLWheelSpeedKPH;
    uint8 ABS_FLWheelSpeedInvalid;
    float32 ABS_FRWheelSpeedKPH;
    uint8 ABS_FRWheelSpeedInvalid;
    uint8 ABS_FLWheelDirection;
    uint8 ABS_FRWheelDirection;
    float32 ABS_RLWheelSpeedKPH;
    uint8 ABS_RLWheelSpeedInvalid;
    float32 ABS_RRWheelSpeedKPH;
    uint8 ABS_RRWheelSpeedInvalid;
    uint8 ABS_RLWheelDirection;
    uint8 ABS_RRWheelDirection;
    uint8 ADAS_APA_OperationSts;
} VehicleInfo;

typedef uint16 VehicleSpd;
typedef struct
{
    uint64 time_stamp;
    Camera_Intrinsic_Params Camera_Intrinsic_Params;
    Camera_Calib_Results Camera_Calib_Results;
} VisionCal;

typedef struct
{
    sint32 failsafe_size;
    PerceptionFailsafe_12 failsafe;
} VisionFailSafe;

typedef struct
{
    sint64 sync_id;
    uint8 estimated_width;
    sint32 lane_host_count;
    PerceptionLaneHost_2 lane_host;
    sint32 lane_adjacent_count;
    PerceptionLaneAdjacent_4 lane_adjacent;
    sint32 road_edge_count;
    PerceptionRoadEdge_2 road_edge;
} VisionLaneSet;

typedef struct
{
    sint32 object_length;
    PerceptionOutObject_32 objects;
} VisionObjectSet;

typedef struct
{
    uint64 time_stamp;
    uint8 enable_object_set;
    uint8 enable_lane_set;
    uint8 enable_traffic_set;
    uint8 enable_failsafe_set;
    uint8 system_reset;
} VisionPerceptionControl;

typedef struct
{
    sint32 traffic_sign_size;
    PerceptionTrafficSign_16 traffic_sign;
    sint32 traffic_sign_status_size;
    PerceptionTrafficSignStatus_16 traffic_sign_status;
} VisionTrafficSignSet;

typedef struct
{
    uint64 time_stamp;
    uint8 processing_status;
} Vision_WorkingStus;

typedef const void* VoidPtr;
typedef uint8 WCBS_ABAAtv_IDT;
typedef uint8 WCBS_ABAAva_IDT;
typedef uint8 WCBS_ABPAtv_IDT;
typedef uint8 WCBS_ABPAva_IDT;
typedef uint8 WCBS_ACCAtv_IDT;
typedef uint8 WCBS_ACCAva_IDT;
typedef uint8 WCBS_ACC_CDD_Active_IDT;
typedef uint8 WCBS_ACC_CDD_Avl_IDT;
typedef uint16 WCBS_ACC_VLC_AccInTar_IDT;
typedef uint8 WCBS_ACC_VLC_Active_IDT;
typedef uint8 WCBS_ACC_VLC_Avl_IDT;
typedef uint8 WCBS_AEBAtv_IDT;
typedef uint8 WCBS_AEBAva_IDT;
typedef uint8 WCBS_AEBJerkAtv_IDT;
typedef uint8 WCBS_AEBJerkAva_IDT;
typedef uint8 WCBS_AEB_PressureHold_IDT;
typedef uint8 WCBS_APA_CDD_Active_IDT;
typedef uint8 WCBS_APA_EmgyBrkAvlb_IDT;
typedef uint8 WCBS_APA_VLC_Active_IDT;
typedef uint8 WCBS_APA_VLC_Available_IDT;
typedef uint8 WCBS_APA_VLC_FailureStatus_IDT;
typedef uint8 WCBS_APA_VLC_Status_IDT;
typedef uint8 WCBS_AWBAtv_IDT;
typedef uint8 WCBS_AWBAvl_IDT;
typedef uint8 WCBS_BrkFrcStaV_IDT;
typedef uint8 WCBS_BrkFrcSta_IDT;
typedef uint8 WCBS_BrkTempSta_IDT;
typedef uint8 WCBS_EBA_Active_Sts_IDT;
typedef uint8 WCBS_ESCDeteACCErroSta_IDT;
typedef uint8 WCBS_HBA_Level_IDT;
typedef uint8 WCBS_VDDAtv_IDT;
typedef uint8 WCBS_VDDAva_IDT;
typedef uint8 WCBS_VStandstillSta_IDT;
typedef uint8 WCB_APA_BrakeControlRes_IDT;
typedef uint8 WCB_APA_VLC_Available_IDT;
typedef uint8 WCB_APA_VLC_FailureStatus_IDT;
typedef uint8 WCB_APA_VLC_Status_IDT;
typedef uint16 WheelSpeedFL;
typedef float32 WheelSpeedFL_adt1_IDT;
typedef uint16 WheelSpeedFR;
typedef uint16 WheelSpeedRL;
typedef uint16 WheelSpeedRR;
typedef struct
{
    uint64 time_stamp;
    uint8 counter;
    uint8 processing_status;
} WorkingStatus;

typedef float32 YSS_LAT_ACC;
typedef uint16 YSS_LAT_ACC_UNFILTERED;
typedef uint16 YSS_LONG_ACC;
typedef uint16 YSS_LONG_ACC_UNFILTERED;
typedef uint16 YSS_YAW_RATE;
typedef uint16 YSS_YAW_RATE_UNFILTERED;
typedef uint8 DataTypeUint8_N_4[4];
typedef uint8 DataTypeUint8_N_1[1];
typedef uint8 DataTypeUint8_N_3[3];
typedef uint8 DataTypeUint8_N_6[6];
typedef uint8 DataTypeUint8_N_2[2];
typedef uint8 DataTypeUint8_N_12[12];
typedef uint8 DataTypeUint8_N_9[9];
typedef uint8 DataTypeUint8_N_8[8];
typedef uint8 DataTypeUint8_N_5[5];
typedef uint8 DataTypeUint8_N_25[25];
typedef uint8 DataTypeUint8_N_36[36];
typedef uint8 DataTypeUint8_N_30[30];
typedef uint8 DataTypeUint8_N_16[16];
typedef uint8 DataTypeUint8_N_13[13];
typedef uint8 DataTypeUint8_N_26[26];
typedef uint8 DataTypeUint8_N_17[17];
typedef uint8 DataTypeUint8_N_7[7];
/*****************************************************************************
* Swc structure
******************************************************************************/
typedef struct {
    uint8 Rte_Dummy;
} Rte_CDS_CtApSignal_Transmission;
typedef struct {
    uint8 Rte_Dummy;
} Rte_CDS_CC_TCP_Handler;
typedef struct {
    uint8 Rte_Dummy;
} Rte_CDS_Driving_Control;
typedef struct {
    uint8 Rte_Dummy;
} Rte_CDS_CC_DiagMsg_SWC;
typedef struct {
    uint8 Rte_Dummy;
} Rte_CDS_CC_TDA4_DiagMsg_SWC;
typedef struct {
    uint8 Rte_Dummy;
} Rte_CDS_Driving_Fusion;
typedef struct {
    uint8 Rte_Dummy;
} Rte_CDS_CC_ADAS_TIME_SYNC_SWC;
typedef struct {
    uint8 Rte_Dummy;
} Rte_CDS_CtApUss_Data_Processing;
typedef struct {
    uint8 Rte_Dummy;
} Rte_CDS_CtApUss_Raw_Data_task;
typedef struct {
    uint8 Rte_Dummy;
} Rte_CDS_CtApState_Machine;
typedef struct {
    uint8 Rte_Dummy;
} Rte_CDS_CtApUss_Pdc;
typedef struct {
    uint8 Rte_Dummy;
} Rte_CDS_CtApAPA_Control;
typedef struct {
    uint8 Rte_Dummy;
} Rte_CDS_CtApDriving_Signal_Transmission;
typedef struct {
    uint8 Rte_Dummy;
} Rte_CDS_TopComposition;
/*******************************************************************************
*   Type definitions for implicit access to S/R port elements 
*******************************************************************************/



/*******************************************************************************
*   type define of Server
*******************************************************************************/
typedef struct {
    uint16 clientId;
    uint16 sequenceCounter;
} Rte_Cs_TransactionHandleType;

/*******************************************************************************
*   OS TrustedFunction
*******************************************************************************/

#endif


