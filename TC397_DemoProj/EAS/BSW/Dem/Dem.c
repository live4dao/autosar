/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
*   File Name       : Dem.c
********************************************************************************
*   Project/Product : AUTOSAR 4.2
*   Title           : Dem.c
*   Author          : Hirain
********************************************************************************
*   Description: Main source file of the AUTOSAR Diagnositc Event Manager,
*                    AUTOSAR_SWS_DiagnosticEventManager.pdf (Release 4.2)
*                    and ISO14229-1(2013).pdf.
********************************************************************************
*   Limitations: None
*
********************************************************************************
*
********************************************************************************
*   Revision History:
*
*   Version      Date         Initials          CR#       Descriptions
*   ---------   ----------    ------------  ----------   ---------------
*   01.00.00    15/11/2017    Feixiang.Dong     N/A       Beta
*   01.01.00    26/06/2018    Feixiang.Dong     N/A       Original
*   01.01.03    11/09/2018    Feixiang.Dong     N/A       EAS422_DEM_20180911_01
*   01.01.04    10/01/2019    Feixiang.Dong     N/A       EAS422_DEM_20190110_01
*   01.01.05    27/02/2019    Feixiang.Dong     N/A       EAS422_DEM_20190227_01
*   01.01.06    20/03/2019    Feixiang.Dong     N/A       EAS422_DEM_20190320_01
*   01.01.07    24/03/2019    Feixiang.Dong     N/A       EAS422_DEM_20190324_01
*   01.01.08    03/04/2019    Feixiang.Dong     N/A       EAS422_DEM_20190403_01
*   01.01.09    08/04/2019    Feixiang.Dong     N/A       EAS422_DEM_20190408_01
*   01.01.10    22/04/2019    Feixiang.Dong     N/A       EAS422_DEM_20190422_01
*   01.01.11    05/08/2019    Feixiang.Dong     N/A       EAS422_DEM_20190805_01
*   01.01.12    25/10/2019    Feixiang.Dong     N/A       EAS422_DEM_20191025_01
*   01.01.13    17/01/2020    Feixiang.Dong     N/A       EAS422_DEM_20200117_01
*   01.01.14    13/03/2020    Feixiang.Dong     N/A       EAS422_DEM_20200313_01
*   01.01.15    30/03/2020    Feixiang.Dong     N/A       EAS422_DEM_20200330_01
*   01.01.16    13/11/2020    Feixiang.Dong     N/A       EAS422_DEM_20201113_01
*   01.01.17    22/01/2021    Feixiang.Dong     N/A       EAS422_DEM_20210122_01
*   01.01.18    11/03/2021    Feixiang.Dong     N/A       EAS422_DEM_20210311_01
*   01.01.19    10/05/2021    Feixiang.Dong     N/A       EAS422_DEM_20210510_01
*   01.01.20    26/05/2021    Feixiang.Dong     N/A       EAS422_DEM_20210526_01
*   01.01.21    18/06/2021    Feixiang.Dong     N/A       EAS422_DEM_20210618_01
*   01.01.22    03/08/2021    Feixiang.Dong     N/A       EAS422_DEM_20210803_01
*   01.01.23    15/11/2021    Feixiang.Dong     N/A       EAS422_DEM_20211115_01
*   01.01.24    25/05/2022    Feixiang.Dong     N/A       EAS422_DEM_20220525_01
*   01.01.25    17/10/2022    Zhenxing.Wu       N/A       EAS422_DEM_20221017_01
*   01.01.26    09/01/2023    Feixiang.Dong     N/A       EAS422_DEM_20230109_01
*   01.01.27    03/04/2023    Feixiang.Dong     N/A       EAS422_DEM_20230403_01
*   01.01.28    27/06/2023    chaolimen.Han     N/A       EAS422_DEM_20230627_01
*   01.02.00    01/08/2023    chaolimen.Han     N/A       EAS422_DEM_20230801_01
*   01.02.00    04/08/2023    chaolimen.Han     N/A       EAS422_DEM_20230804_01
*   01.02.01    10/08/2023    chaolimen.Han     N/A       EAS422_DEM_20230810_01
*   01.02.01    22/08/2023    chaolimen.Han     N/A       EAS422_DEM_20230822_01
*   01.02.02    06/09/2023    chaolimen.Han     N/A       EAS422_DEM_20230906_01
*   01.02.03    08/10/2023    chaolimen.Han     N/A       EAS422_DEM_20231008_01
*   01.02.04    01/11/2023    chaolimen.Han     N/A       EAS422_DEM_20231101_01
*   01.02.05    30/11/2023    chaolimen.Han     N/A       EAS422_DEM_20231130_01
********************************************************************************
* END_FILE_HDR*/

/*******************************************************************************
*   Includes
*******************************************************************************/
#include "Dem.h"
#include "Dem_Dcm.h"
#include "Dem_NvM.h"
#include "Dem_Lcfg.h"
#include "SchM_Dem.h"
#if(DEM_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"
#endif
#if(DEM_NVM_SUPPORT == STD_ON)
#include "NvM.h"
#endif
#if(DEM_CFG_TRIGGER_FIM_REPORTS == STD_ON)
#include "FiM.h"
#endif
#include "Bsw_Common.h"

/*******************************************************************************
*   Version Check
*******************************************************************************/
#if(DEM_PRIVATE_VERSION_CHECK == STD_ON)
/* check Version with cfg file */
#if ((DEM_AR_RELEASE_MAJOR_VERSION != DEM_AR_RELEASE_MAJOR_VERSION_CFG) || \
   (DEM_AR_RELEASE_MINOR_VERSION != DEM_AR_RELEASE_MINOR_VERSION_CFG))
#error "AutoSar Version Numbers of Dem and its cfg file are different"
#endif

#if ((DEM_SW_MAJOR_VERSION != DEM_SW_MAJOR_VERSION_CFG) || \
   (DEM_SW_MINOR_VERSION != DEM_SW_MINOR_VERSION_CFG))
#error "SW Version Numbers of Dem and its cfg file are different"
#endif

#endif/*(DEM_PRIVATE_VERSION_CHECK == STD_ON)*/

/*******************************************************************************
*   Cfg data Check
*******************************************************************************/
#if((DEM_CFG_OBD_SUPPORT == DEM_OBD_MASTER_ECU)||(DEM_CFG_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU))
#if(0 == DEM_CFG_OBD_NUM_OF_PID)
#error "The number of Pid should not be 0 while OBD is supported."
#endif
#if(0 == DEM_NUM_OF_INDICATOR)
#error "The number of indicator should not be 0 while OBD is supported."
#endif
#if(0xFF == DEM_CFG_MILINDICATORREF)
#error "The DemMILIndicatorRef parameter should reference to a valid indicator while OBD is supported."
#endif
#if(0 == DEM_CFG_MAXNUMBEREVENTENTRY_PERMANENT)
#error "The number of permanent memory entry should not be 0 while OBD is supported."
#endif
#else/*#if((DEM_CFG_OBD_SUPPORT == DEM_OBD_MASTER_ECU)||(DEM_CFG_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU))*/
#if(0 != DEM_CFG_MAXNUMBEREVENTENTRY_PERMANENT)
#error "The number of permanent memory entry should be 0 if OBD is not supported."
#endif
#endif/*#if((DEM_CFG_OBD_SUPPORT == DEM_OBD_MASTER_ECU)||(DEM_CFG_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU))*/

/*******************************************************************************
*   Macro
*******************************************************************************/
#if(DEM_DEV_ERROR_DETECT == STD_ON)
#define DEM_DET_ERROR_DETECT(cond, ApiId, errcode)  \
    DET_ERROR_DETECT(cond, DEM_MODULE_ID, DEM_INSTANCE_ID, ApiId, errcode)

#define DEM_DET_ERROR_DETECT_RET(cond, ApiId, errcode, ret) \
    DET_ERROR_DETECT_RET(cond, DEM_MODULE_ID, DEM_INSTANCE_ID, ApiId, errcode, ret)

#define DEM_DET_REPORT_ERROR(ApiId, errcode)  \
    DET_REPORT_ERROR(DEM_MODULE_ID, DEM_INSTANCE_ID, ApiId, errcode)
#else
#define DEM_DET_ERROR_DETECT(cond, ApiId, errcode)
#define DEM_DET_ERROR_DETECT_RET(cond, ApiId, errcode, ret)
#define DEM_DET_REPORT_ERROR(ApiId, errcode)
#endif

typedef uint8 Dem_StateType;
#define DEM_UNINIT                  ((Dem_StateType)0x00)
#define DEM_PREINIT                 ((Dem_StateType)0x01)
#define DEM_NORMAL                  ((Dem_StateType)0x02)

typedef uint8 Dem_MemIdType;

/*Clear DTC State*/
#define DEM_IN_CLEAR_DTC_IDLE       ((uint8)0x00)
#define DEM_IN_CLEAR_DTC_BUSY       ((uint8)0x01)
#define DEM_IN_CLEAR_DTC_OK         ((uint8)0x02)
#define DEM_IN_CLEAR_DTC_ERR        ((uint8)0x03)
#define DEM_IN_CLEAR_EVENT_MEM      ((uint8)0x04)
#define DEM_IN_CLEAR_DTC_GROUP      ((uint8)0x05)
#define DEM_CLEAR_NUM_PER_CYCLE     ((uint16)20)

#define DEM_DATA_INVALID_U8         ((uint8)0xFF)
#define DEM_DATA_INVALID_U16        ((uint16)0xFFFF)
#define DEM_DATA_CLEAR              (0u)
#define DEM_DATA_MAX_FDC            ((sint8)127)
#define DEM_DATA_U8_FF              ((uint8)0xFF)
#define DEM_OBD_PCSLF_MAXVALUE      ((uint8)3)

#define DEM_STATUS_RESET            ((Dem_UdsStatusByteType)0x50)

#define DEM_F_FDC_FACTOR            ((uint8)127)
#define DEM_P_FDC_FACTOR            ((uint8)128)

#if((DEM_CFG_OBD_SUPPORT == DEM_OBD_MASTER_ECU)||(DEM_CFG_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU))
#define DEM_OBD_PID1C_DATA_LENGTH   (1)/*byte*/
#define DEM_OBD_PID21_DATA_LENGTH   (2)/*byte*/
#define DEM_OBD_PID30_DATA_LENGTH   (1)/*byte*/
#define DEM_OBD_PID4D_DATA_LENGTH   (2)/*byte*/
#define DEM_OBD_PID4E_DATA_LENGTH   (2)/*byte*/
#define DEM_OBD_PID91_DATA_LENGTH   (5)/*byte*/
#define DEM_OBD_INFO08_DATA_LENGTH  (40)/*byte: 32/40/56*/
#define DEM_OBD_INFO0B_DATA_LENGTH  (36)/*byte: 32/36*/

#if(DEM_NUM_OF_RATIO > 0)
#define DEM_OBD_NUM_INCREASED_MASK  ((uint8)0x01)
#define DEM_OBD_DEN_INCREASED_MASK  ((uint8)0x02)
#define DEM_OBD_DEN_LOCK_MASK       ((uint8)0x04)
/*Numerator/Denominator max value*/
#define DEM_OBD_NUMDEN_MAX_VALUE    ((uint16)65535)
#endif

#endif

#if(DEM_NUM_OF_INDICATOR > 0)
typedef enum
{
    DEM_TF_CLEAR = 0,/*TestFailed bit of DTC status is reset to 0.*/
    DEM_CYCLE_END = 1/*Operation cycle end.*/
} Dem_IndicatorOffType;
#endif


#define DEM_SET_STATE(state)        (Dem_State = state)

/*Event*/
#define DEM_EVENT_FIRST_FAILED                 (Dem_StorageMem.EventHead.FirstFailedEvent)
#define DEM_EVENT_RECENT_FAILED                (Dem_StorageMem.EventHead.MostRecentFailedEvent)
#define DEM_EVENT_FIRST_CONFIRMED              (Dem_StorageMem.EventHead.FirstConfirmedEvent)
#define DEM_EVENT_RECENT_CONFIRMED             (Dem_StorageMem.EventHead.MostRecentConfirmedEvent)

/*Event Counter*/
#define DEM_EVENT_FCC(i)                       (Dem_StorageMem.EventEntry[i].EventFaultConfCnt)
#if(DEM_NUM_OF_INDICATOR > 0)
#define DEM_EVENT_IFCC(i)                      (Dem_StorageMem.EventEntry[i].IndicatorFailureCycleCounter)
#define DEM_EVENT_IHCC(i)                      (Dem_StorageMem.EventEntry[i].IndicatorHealingCycleCounter)
#endif
#define DEM_EVENT_OCCCTR(i)                    (Dem_StorageMem.EventEntry[i].EventOccurrence)
#if(DEM_CFG_DEBOUNCECOUNTERBASEDSUPPORT == STD_ON)
#define DEM_EVENT_DBC(i)                       (Dem_StorageMem.EventEntry[i].EventDebounceCnt)
#endif
#if(DEM_CFG_DEBOUNCETIMEBASEDSUPPORT == STD_ON)
#define DEM_EVENT_DBT(i)                       (Dem_StorageMem.EventEntry[i].EventDebounceTimer)
#define DEM_EVENT_TIMERDIRECTION(i)            (Dem_StorageMem.EventEntry[i].TimerDirection)
#endif
#define DEM_EVENT_MAXFDCDCC(i)                 (Dem_StorageMem.EventEntry[i].EventMaxFdcDuringCurrentCycle)
#define DEM_EVENT_MAXFDCSLC(i)                 (Dem_StorageMem.EventEntry[i].EventMaxFdcSinceLastClear)
#define DEM_EVENT_CSLF(i)                      (Dem_StorageMem.EventEntry[i].EventCyclesSinceLastFailed)
#define DEM_EVENT_CSFF(i)                      (Dem_StorageMem.EventEntry[i].EventCyclesSinceFirstFailed)
#define DEM_EVENT_FCSLC(i)                     (Dem_StorageMem.EventEntry[i].EventFailedCyclesSinceLastCleared)
#if((DEM_CFG_OBD_SUPPORT == DEM_OBD_MASTER_ECU)||(DEM_CFG_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU))
#define DEM_EVENT_OBD_PCSLF(i)                 (Dem_StorageMem.EventEntry[i].EventOBDPassedCyclesSinceLastFailed)
#endif
#if(DEM_CFG_MAXNUMBEREVENTENTRY_PERMANENT > 0)
#define DEM_EVENT_OBD_CLEAR_FLAG(i)            (Dem_StorageMem.EventEntry[i].EventClearFlagForPermanent)
#endif
#if(STD_ON == DEM_CMA_PLATFORM_ENABLED)
#define DEM_EVENT_CMA_STATUS(i)                (Dem_StorageMem.EventEntry[i].EventCMAStatus)
#define DEM_EVENT_CMA_PCSLF(i)                 (Dem_StorageMem.EventEntry[i].EventPassedCyclesSinceLastFailed)
#endif
/*Indicator*/
#if(DEM_NUM_OF_INDICATOR > 0)
#define DEM_INDICATOR_STATUS(i)                (Dem_StorageMem.IndicatorStatus[i])
#endif
/*DTC*/
#define DEM_DTC_STATUS(i)                      (Dem_StorageMem.DtcEntry[i].DtcStatus)
#define DEM_DTC_LASTSTATUS(i)                  (Dem_StorageMem.DtcEntry[i].DtcLastStatus)
#define DEM_DTC_AGINGCNT(i)                    (Dem_StorageMem.DtcEntry[i].DtcAgingCounter)
#define DEM_DTC_AGEDCNT(i)                     (Dem_StorageMem.DtcEntry[i].DtcAgedCounter)
#define DEM_DTC_DATAENTRYREF(i)                (Dem_StorageMem.DtcEntry[i].DataEntryRef)

#define DEM_PRIMARY_DATAENTRY_USEDNUM          (Dem_StorageMem.PrimaryDataEntryUsedNum)
#define DEM_PRIMARY_DATAENTRY_USED(i)          (Dem_StorageMem.PrimaryDataEntry[i].Used)
#if(DEM_MAX_FFSIZE_OF_DTC > 0)
#define DEM_PRIMARY_FFDATA_PTR(i)              (Dem_StorageMem.PrimaryDataEntry[i].FreezeFrameData)
#endif
#if(DEM_MAX_EXTSIZE_OF_DTC > 0)
#define DEM_PRIMARY_EXTDATA_PTR(i)             (Dem_StorageMem.PrimaryDataEntry[i].ExtendedData)
#endif

#if(DEM_MAX_J1939FFSIZE_OF_DTC > 0)
#define DEM_PRIMARY_J1939DTC_FFDATA_PTR(i)            (Dem_StorageMem.PrimaryDataEntry[i].J1939FreezeFrameData)
#endif
#if(DEM_MAX_J1939EXPFFSIZE_OF_DTC > 0)
#define DEM_PRIMARY_J1939DTC_EXPFFDATA_PTR(i)            (Dem_StorageMem.PrimaryDataEntry[i].J1939ExpFreezeFrameData)
#endif


#if((DEM_CFG_OBD_SUPPORT == DEM_OBD_MASTER_ECU)||(DEM_CFG_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU))
#define DEM_OBD_DATA_INFO                      (Dem_StorageMem.OBDDataInfo)
/*Used for PID01/41*/
#define DEM_OBD_READINESSGROUP_STATUS          (DEM_OBD_DATA_INFO.ReadinessGroupStatus)
/*Used for PID31.Unit:m, Range:0-65535000*/
#define DEM_OBD_DISTANCE_SINCEDTCCLEARED       (DEM_OBD_DATA_INFO.DistanceSinceDtcCleared)
/*Data for Service 02*/
#define DEM_OBD_FF_EVENT                       (DEM_OBD_DATA_INFO.ObdEventId)
#define DEM_OBD_FF_DATA_BUF                    (DEM_OBD_DATA_INFO.ObdFreezeFrameData)
/*Data for Service 09*/
#if(DEM_NUM_OF_RATIO > 0)
#define DEM_OBD_RATIO_IGN_CNT                  (DEM_OBD_DATA_INFO.RatioIGNCycleCounter)
#define DEM_OBD_RATIO_GENDEN_CNT               (DEM_OBD_DATA_INFO.RatioGeneralDenominatorCounter)
#define DEM_OBD_RATIO_GENDEN_STATE             (DEM_OBD_DATA_INFO.RatioGeneralDenominatorState)
#define DEM_OBD_RATIO_DENOMCOND_STATUS(i)      (DEM_OBD_DATA_INFO.RatioDenomCondStatus[i])
#define DEM_OBD_RATIO_NUMERATOR(i)             (DEM_OBD_DATA_INFO.RatioNumerator[i])
#define DEM_OBD_RATIO_DENOMINATOR(i)           (DEM_OBD_DATA_INFO.RatioDenominator[i])
/*bit 0: Numerator increased flag;
  bit 1: Denominator increased flag;
  bit 2: Denominator lock flag.*/
#define DEM_OBD_RATIO_STATE(i)                 (DEM_OBD_DATA_INFO.RatioState[i])
#endif
#if(DEM_CFG_MAXNUMBEREVENTENTRY_PERMANENT > 0)
#define DEM_OBD_PFC_CYCLE_STATUS               (DEM_OBD_DATA_INFO.PfcCycleStatus)
#endif
#endif/*#if((DEM_CFG_OBD_SUPPORT == DEM_OBD_MASTER_ECU)||(DEM_CFG_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU))*/

#if(DEM_CFG_MAXNUMBEREVENTENTRY_PERMANENT > 0)
#define DEM_PERMANENT_DATAENTRY_USEDNUM        (Dem_StorageMem.PermanentEntryUsedNum)
#define DEM_PERMANENT_DATAENTRY_EVENTID(i)     (Dem_StorageMem.PermanentDataEntry[i])
#endif/*#if(DEM_CFG_MAXNUMBEREVENTENTRY_PERMANENT > 0)*/


/*SWS_Dem_00415*/
#if(DEM_CFG_DEBOUNCECOUNTERBASEDSUPPORT == STD_ON)
#define DEM_EVENT_DBC_F_FDC(i)                 (sint8)(((sint32)DEM_EVENT_DBC(i)*DEM_F_FDC_FACTOR)/(DEM_CFG_EVENT_DBC_FAILTHRESHOLD(i)))
#define DEM_EVENT_DBC_P_FDC(i)                 (sint8)(((sint32)DEM_EVENT_DBC(i)*DEM_P_FDC_FACTOR)/(0-DEM_CFG_EVENT_DBC_PASSTHRESHOLD(i)))
#endif
#if(DEM_CFG_DEBOUNCETIMEBASEDSUPPORT == STD_ON)
#define DEM_EVENT_DBT_F_FDC(i)                 (sint8)(((sint32)DEM_EVENT_DBT(i)*DEM_F_FDC_FACTOR)/(DEM_CFG_EVENT_DBT_FAILED(i)))
#define DEM_EVENT_DBT_P_FDC(i)                 (sint8)(((sint32)DEM_EVENT_DBT(i)*DEM_P_FDC_FACTOR)/(sint32)(0-DEM_CFG_EVENT_DBT_PASSED(i)))
#endif


/*Operation Cycle*/
#define DEM_CFG_OPCYC_AUTOSTART(i)             (Dem_OperationCycleTable[i].DemOperationCycleAutostart)
#define DEM_CFG_OPCYC_AUTOEND(i)               (Dem_OperationCycleTable[i].DemOperationCycleAutomaticEnd)
#define DEM_CFG_OPCYC_TYPE(i)                  (Dem_OperationCycleTable[i].DemOperationCycleType)

/*NvM BlockId*/
#define DEM_CFG_NVM_BLOCKID                    (Dem_NvRamBlockIdTable[0].DemNvRamBlockIdRef)

/*Event*/
#define DEM_CFG_EVENT_DTCREF(i)                (Dem_EventTable[i].DemDTCRef)
#define DEM_CFG_EVENT_AVAILABLE(i)             (Dem_EventTable[i].DemEventAvailable)
#define DEM_CFG_EVENT_OPCYCREF(i)              (Dem_EventTable[i].DemOperationCycleRef)
#define DEM_CFG_EVENT_KIND(i)                  (Dem_EventTable[i].DemEventKind)
#define DEM_CFG_EVENT_REPBEHAVIOR(i)           (Dem_EventTable[i].DemReportBehavior)
#if(DEM_NUM_OF_EN_GROUP > 0)
#define DEM_CFG_EVENT_EN(i)                    (Dem_EventTable[i].DemEnableConditionGroupRef)
#define DEM_CFG_EVENT_EN_NUM(i)                (Dem_EventTable[i].DemEnableConditionGroupRef->Number)
#define DEM_CFG_EVENT_EN_REF(i)                (Dem_EventTable[i].DemEnableConditionGroupRef->DemEnableConditionRef)
#endif
#if(DEM_NUM_OF_STOR_GROUP > 0)
#define DEM_CFG_EVENT_STOR(i)                  (Dem_EventTable[i].DemStorageConditionGroupRef)
#define DEM_CFG_EVENT_STOR_NUM(i)              (Dem_EventTable[i].DemStorageConditionGroupRef->Number)
#define DEM_CFG_EVENT_STOR_REF(i)              (Dem_EventTable[i].DemStorageConditionGroupRef->DemStorageConditionRef)
#endif
#if(DEM_NUM_OF_INDICATOR > 0)
#define DEM_CFG_EVENT_INDICATOR_NUM(i)         (Dem_EventTable[i].NumOfIndicator)
#define DEM_CFG_EVENT_INDICATOR(i)             (Dem_EventTable[i].DemIndicatorAttribute)
#define DEM_CFG_EVENT_INDICATOR_BEHAVIOUR(i,j) (Dem_EventTable[i].DemIndicatorAttribute[j].DemIndicatorBehaviour)
#define DEM_CFG_EVENT_INDICATOR_F_THRESHOLD(i,j) \
    (Dem_EventTable[i].DemIndicatorAttribute[j].DemIndicatorFailureCycleCounterThreshold)
#define DEM_CFG_EVENT_INDICATOR_H_THRESHOLD(i,j) \
    (Dem_EventTable[i].DemIndicatorAttribute[j].DemIndicatorHealingCycleCounterThreshold)
#define DEM_CFG_EVENT_INDICATOR_ID(i,j)        (Dem_EventTable[i].DemIndicatorAttribute[j].DemIndicatorID)
#define DEM_CFG_EVENT_INDICATOR_OFFSET(i,j)    (Dem_EventTable[i].DemIndicatorAttribute[j].DemIndicatorStatusPosOffset)
#endif/*#if(DEM_NUM_OF_INDICATOR > 0)*/

#define DEM_CFG_EVENT_FAULTCNTTHRESHOLD(i)     (Dem_EventTable[i].DemEventFailureCycleCounterThreshold)
#define DEM_CFG_EVENT_CLEARALLOWED_BEHAVIOR(i) (Dem_EventTable[i].DemCallbackClearEventAllowed.DemClearEventAllowedBehavior)
#define DEM_CFG_EVENT_CLEARALLOWED_CALLFNC(i)  (Dem_EventTable[i].DemCallbackClearEventAllowed.DemCallbackClearEventAllowedFnc)
#define DEM_CFG_EVENT_STATUSCHANGED_CALLFNC(i) (Dem_EventTable[i].DemCallbackEventStatusChangedFnc)
#define DEM_CFG_EVENT_DATACHANGED_CALLFNC(i)   (Dem_EventTable[i].DemCallbackEventDataChangedFnc)
#define DEM_CFG_EVENT_INITM_CALLFNC(i)         (Dem_EventTable[i].DemCallbackInitMForEFnc)

#if(DEM_CFG_DEBOUNCECOUNTERBASEDSUPPORT == STD_ON)
#define DEM_CFG_EVENT_DBC(i)                   \
    (Dem_EventTable[i].DemDebounceAlgorithmClass.DemDebounceCounterBasedClassRef)
#define DEM_CFG_EVENT_DBC_BEHAVIOR(i)          \
    (DEM_CFG_EVENT_DBC(i)->DemDebounceBehavior)
#define DEM_CFG_EVENT_DBC_FAILTHRESHOLD(i)     \
    (DEM_CFG_EVENT_DBC(i)->DemDebounceCounterFailedThreshold)
#define DEM_CFG_EVENT_DBC_JUMPUP(i)            \
    (DEM_CFG_EVENT_DBC(i)->DemDebounceCounterJumpUp)
#define DEM_CFG_EVENT_DBC_JUMPUP_VALUE(i)      \
    (DEM_CFG_EVENT_DBC(i)->DemDebounceCounterJumpUpValue)
#define DEM_CFG_EVENT_DBC_INCREMENT_SIZE(i)    \
    (DEM_CFG_EVENT_DBC(i)->DemDebounceCounterIncrementStepSize)
#define DEM_CFG_EVENT_DBC_PASSTHRESHOLD(i)     \
    (DEM_CFG_EVENT_DBC(i)->DemDebounceCounterPassedThreshold)
#define DEM_CFG_EVENT_DBC_JUMPDOWN(i)          \
    (DEM_CFG_EVENT_DBC(i)->DemDebounceCounterJumpDown)
#define DEM_CFG_EVENT_DBC_JUMPDOWN_VALUE(i)    \
    (DEM_CFG_EVENT_DBC(i)->DemDebounceCounterJumpDownValue)
#define DEM_CFG_EVENT_DBC_DECREMENT_SIZE(i)    \
    (DEM_CFG_EVENT_DBC(i)->DemDebounceCounterDecrementStepSize)
#define DEM_CFG_EVENT_DBC_STORAGE(i)           \
    (DEM_CFG_EVENT_DBC(i)->DemDebounceCounterStorage)
#endif

#if(DEM_CFG_DEBOUNCETIMEBASEDSUPPORT == STD_ON)
#define DEM_CFG_EVENT_DBT(i)                   \
    (Dem_EventTable[i].DemDebounceAlgorithmClass.DemDebounceTimeBaseRef)
#define DEM_CFG_EVENT_DBT_FAILED(i)            \
    ((DEM_CFG_EVENT_DBT(i)->DemDebounceTimeFailedThreshold)/DEM_TASK_TIME)
#define DEM_CFG_EVENT_DBT_PASSED(i)            \
    ((DEM_CFG_EVENT_DBT(i)->DemDebounceTimePassedThreshold)/DEM_TASK_TIME)
#define DEM_CFG_EVENT_DBT_BAHAVIOR(i)          \
    (DEM_CFG_EVENT_DBT(i)->DemDebounceBehavior)
#endif

#define DEM_CFG_EVENT_GET_FDC_FNC(i)           \
    (Dem_EventTable[i].DemDebounceAlgorithmClass.DemCallbackGetFDCFnc)

/*DTC StatusChangedNotification*/
#define DEM_CFG_DTC_STATUSCHANGED_CALLFNC      (Dem_DtcStatusChangedNotificationArray[0])
/*DTC groups*/
#define DEM_CFG_DTC_GROUPVALUE(i)              (Dem_GroupOfDTCTable[i])
/*DTCs*/
#define DEM_CFG_DTC_VALUE(i)                   (Dem_DTCTable[i].DemDtcValue)
#define DEM_CFG_DTC_SEVERITY(i)                (Dem_DTCTable[i].DemDTCSeverity)
#define DEM_CFG_DTC_FNCUNIT(i)                 (Dem_DTCTable[i].DemDTCFunctionalUnit)
#if((DEM_CFG_OBD_SUPPORT == DEM_OBD_MASTER_ECU)||(DEM_CFG_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU)||(DEM_J1939_SUPPORT == STD_ON))
#define DEM_CFG_DTC_OBDDTCREF(i)               (Dem_DTCTable[i].DemObdDTCRef)

#if(DEM_CFG_PTO_SUPPORT == STD_ON)
#define DEM_CFG_DTC_OBD_CON_PTO(i)             (DEM_CFG_DTC_OBDDTCREF(i)->DemConsiderPtoStatus)
#endif

#if((DEM_CFG_OBD_SUPPORT == DEM_OBD_MASTER_ECU)||(DEM_CFG_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU))
#define DEM_CFG_DTC_OBD_VALUE(i)               (DEM_CFG_DTC_OBDDTCREF(i)->DemDtcValue)
#define DEM_CFG_DTC_OBDDTCCLASS(i)             (Dem_DTCTable[i].DemWWHOBDDTCClass)

#define DEM_DTC_IS_OBD(i)                      \
    ((DEM_CFG_DTC_OBDDTCREF(i) != NULL_PTR) && (DEM_CFG_DTC_OBD_VALUE(i) != 0))
#endif

#if(DEM_CFG_OBD_SUPPORT == DEM_OBD_MASTER_ECU)
#define DEM_CFG_DTC_OBD_READINESSGROUP(i)      (DEM_CFG_DTC_OBDDTCREF(i)->DemEventOBDReadinessGroup)
#endif

#if(DEM_J1939_SUPPORT == STD_ON)
#define DEM_CFG_DTC_J1939_VALUE(i)             (DEM_CFG_DTC_OBDDTCREF(i)->DemJ1939DTCValue)
#endif
#endif/*#if((DEM_CFG_OBD_SUPPORT == DEM_OBD_MASTER_ECU)||(DEM_CFG_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU)||(DEM_J1939_SUPPORT == STD_ON))*/

#define DEM_CFG_DTC_AGING_ALLOWED(i)           \
    (Dem_DTCAttributesTable[Dem_DTCTable[i].DemDTCAttributesRef].DemAgingAllowed)
#define DEM_CFG_DTC_AGINGCYCREF(i)             \
    (Dem_DTCAttributesTable[Dem_DTCTable[i].DemDTCAttributesRef].DemAgingCycleRef)
#define DEM_CFG_AGINGCYCLECOUNTERTHRESHOLD(i)  \
    (Dem_DTCAttributesTable[Dem_DTCTable[i].DemDTCAttributesRef].DemAgingCycleCounterThreshold)
#define DEM_CFG_DTC_SIGNIFICANCE(i)            \
    (Dem_DTCAttributesTable[Dem_DTCTable[i].DemDTCAttributesRef].DemDTCSignificance)
#define DEM_CFG_DTC_PRIORITY(i)                \
    (Dem_DTCAttributesTable[Dem_DTCTable[i].DemDTCAttributesRef].DemDTCPriority)
#define DEM_CFG_DTC_FDC_THRESHLD(i)            \
    (Dem_DTCAttributesTable[Dem_DTCTable[i].DemDTCAttributesRef].DemEventMemoryEntryFdcThresholdStorageValue)
#define DEM_CFG_DTC_J1939NODE_REF(i)           \
    (Dem_DTCAttributesTable[Dem_DTCTable[i].DemDTCAttributesRef].DemJ1939DTC_J1939NodeRef)
#define DEM_CFG_DTC_J1939NODE_NUM(i)           \
    (Dem_DTCAttributesTable[Dem_DTCTable[i].DemDTCAttributesRef].DemJ1939DTC_J1939NodeRef->Number)
#define DEM_CFG_DTC_J1939NODE_ARRAY(i)         \
    (Dem_DTCAttributesTable[Dem_DTCTable[i].DemDTCAttributesRef].DemJ1939DTC_J1939NodeRef->DemJ1939NmNodeRef)



#if(DEM_NUM_OF_EXTDATACLASS > 0)
/*ExtendedData*/
#define DEM_CFG_DTC_EXTDATACLASSREF(i)         \
    (Dem_DTCAttributesTable[Dem_DTCTable[i].DemDTCAttributesRef].DemExtendedDataClassRef)
#define DEM_CFG_DTC_NUM_OF_EXTREC(i)           \
    (Dem_ExtDataClassTable[*DEM_CFG_DTC_EXTDATACLASSREF(i)].Number)
#define DEM_CFG_DTC_EXTREC_ARRAY(i)            \
    (Dem_ExtDataClassTable[*DEM_CFG_DTC_EXTDATACLASSREF(i)].DemExtendedDataRecordClassRef)
#define DEM_CFG_DTC_EXTRECNUM(i)               \
    (Dem_ExtDataRecClassTable[i].DemExtendedDataRecordNumber)
#define DEM_CFG_DTC_EXTREC_UPDATA(i)           \
    (Dem_ExtDataRecClassTable[i].DemExtendedDataRecordUpdate)
#define DEM_CFG_DTC_EXTREC_TRIGGER(i)          \
    (Dem_ExtDataRecClassTable[i].DemExtendedDataRecordTrigger)
#define DEM_CFG_NUMDATA_OF_EXTRECNUM(i)        \
    (Dem_ExtDataRecClassTable[i].Number)
#define DEM_CFG_DATAARRAY_OF_EXTRECNUM(i)      \
    (Dem_ExtDataRecClassTable[i].DemDataElementClassRef)
#endif

#if(DEM_NUM_OF_FFRECCLASS > 0)
/*FreezeFrameData*/
#define DEM_CFG_DTC_FFRECNUMCLASSREF(i)        \
    (Dem_DTCAttributesTable[Dem_DTCTable[i].DemDTCAttributesRef].DemFreezeFrameRecNumClassRef)
#define DEM_CFG_DTC_NUM_OF_FFREC(i)            \
    (Dem_FFRecNumClassTable[*DEM_CFG_DTC_FFRECNUMCLASSREF(i)].Number)
#define DEM_CFG_DTC_FFREC_ARRAY(i)             \
    (Dem_FFRecNumClassTable[*DEM_CFG_DTC_FFRECNUMCLASSREF(i)].DemFreezeFrameRecordClassRef)
#define DEM_CFG_DTC_FFRECNUM(i)                \
    (Dem_FFRecClassTable[i].DemFreezeFrameRecordNumber)
#define DEM_CFG_DTC_FFREC_UPDATA(i)            \
    (Dem_FFRecClassTable[i].DemFreezeFrameRecordUpdate)
#define DEM_CFG_DTC_FFREC_TRIGGER(i)           \
    (Dem_FFRecClassTable[i].DemFreezeFrameRecordTrigger)
#define DEM_CFG_NUMDID_OF_FFRECNUM(i)          \
    (Dem_FFRecClassTable[i].Number)
#define DEM_CFG_DIDARRAY_OF_FFRECNUM(i)        \
    (Dem_FFRecClassTable[i].DemDidClassRef)
#define DEM_CFG_DID(i)                         \
    (Dem_DidClassTable[i].DemDidIdentifier)
#define DEM_CFG_NUMDATA_OF_DID(i)              \
    (Dem_DidClassTable[i].Number)
#define DEM_CFG_DATAARRAY_OF_DID(i)            \
    (Dem_DidClassTable[i].DemDidDataElementClassRef)
#endif

#if(STD_ON == DEM_CFG_J1939_FF_SUPPORT)
#define DEM_CFG_J1939DTC_FFRECNUMCLASSREF(i)        \
    (Dem_DTCAttributesTable[Dem_DTCTable[i].DemDTCAttributesRef].DemJ1939FreezeFrameClassRef)
#define DEM_CFG_J1939DTC_NUM_OF_FFSPNC(i)            \
    (DEM_CFG_J1939DTC_FFRECNUMCLASSREF(i)->Number)
#define DEM_CFG_J1939DTC_FFSPNC_ARRAY(i)             \
    (DEM_CFG_J1939DTC_FFRECNUMCLASSREF(i)->DemSPNClassRef) 
#endif

#if((STD_ON == DEM_CFG_J1939_FF_SUPPORT)||(STD_ON == DEM_CFG_J1939EX_FF_SUPPORT))
#define DEM_CFG_DATAARRAY_OF_FFSPN(i)            \
    (Dem_SPNClassTable[i].DemSPNDataElementClassRef)
#define DEM_CFG_SPNID_OF_FFSPNC(i)\
    (Dem_SPNClassTable[i].DemSPNId)
#endif

#if(STD_ON == DEM_CFG_J1939EX_FF_SUPPORT)
#define DEM_CFG_1939DTC_EXPFFRECNUMCLASSREF(i)        \
    (Dem_DTCAttributesTable[Dem_DTCTable[i].DemDTCAttributesRef].DemJ1939ExpandedFreezeFrameClassRef)
#define DEM_CFG_J1939DTC_NUM_OF_EXPFFSPNC(i)            \
    (DEM_CFG_1939DTC_EXPFFRECNUMCLASSREF(i)->Number)
#define DEM_CFG_J1939DTC_EXPFFSPNC_ARRAY(i)             \
    (DEM_CFG_1939DTC_EXPFFRECNUMCLASSREF(i)->DemSPNClassRef) 
#endif

#if(DEM_NUM_OF_DATA > 0)
/*DataElement*/
#define DEM_CFG_DATA_IN_DATA(i)                \
    (Dem_DataElementClassTable[i].DemInternalDataElementClass)
#define DEM_CFG_DATA_IN_DATA_SIZE(i)           \
    (DEM_CFG_DATA_IN_DATA(i)->DemDataElementDataSize)
#define DEM_CFG_DATA_IN_DATA_TYPE(i)           \
    (DEM_CFG_DATA_IN_DATA(i)->DemInternalDataElement)
#define DEM_CFG_DATA_CS_DATA(i)                \
    (Dem_DataElementClassTable[i].DemExternalCSDataElementClass)
#define DEM_CFG_DATA_CS_DATA_SIZE(i)           \
    (DEM_CFG_DATA_CS_DATA(i)->DemDataElementDataSize)
#define DEM_CFG_DATA_CS_DATA_READ_FNC(i)       \
    (DEM_CFG_DATA_CS_DATA(i)->DemDataElementReadFnc)
#endif

/*Enable condition*/
#if(DEM_NUM_OF_EN_CONDITION > 0)
#define DEM_CFG_EN_CONDITION_STATUS(i)         \
    (Dem_EnConditionTable[i].DemEnableConditionStatus)
#endif
/*Enable condition*/
#if(DEM_NUM_OF_STOR_CONDITION > 0)
#define DEM_CFG_STOR_CONDITION_STATUS(i)       \
    (Dem_StorageConditionTable[i].DemStorageConditionStatus)
#endif

/*Indicator*/
#if(DEM_NUM_OF_INDICATOR > 0)
#define DEM_CFG_INDICATOR_STATUS_FNC(i)        \
    (Dem_IndicatorStatusIndex[i].DemCallbackIndicatorStatusNotifyFnc)
#define DEM_CFG_INDICATOR_STATUS_START(i)      \
    (Dem_IndicatorStatusIndex[i].IndicatorStatusStartOffset)
#define DEM_CFG_INDICATOR_STATUS_NUM(i)        \
    (Dem_IndicatorStatusIndex[i].NumOfReferencedEvent)
#endif/*#if(DEM_NUM_OF_INDICATOR > 0)*/


#if((DEM_CFG_OBD_SUPPORT == DEM_OBD_MASTER_ECU)||(DEM_CFG_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU))
/*DemRatio*/
#if(DEM_NUM_OF_RATIO > 0)
#define DEM_CFG_RATIO_EVENTREF(i)              (Dem_RatioTable[i].DemDiagnosticEventRef)
#define DEM_CFG_RATIO_IUMPR(i)                 (Dem_RatioTable[i].DemIUMPRGroup)
#define DEM_CFG_RATIO_IUMPR_DEN(i)             (Dem_RatioTable[i].DemIUMPRDenGroup)
#define DEM_CFG_RATIO_KIND(i)                  (Dem_RatioTable[i].DemRatioKind)
#endif/*#if(DEM_NUM_OF_RATIO > 0)*/
#if(DEM_CFG_OBD_NUM_OF_PID > 0)
/*DemPidClass*/
#define DEM_CFG_PID_ID(i)                      (Dem_PidTable[i].DemPidIdentifier)
#define DEM_CFG_PID_NUM_OF_DATA(i)             (Dem_PidTable[i].NumOfData)
#define DEM_CFG_PID_DATA_CLASS(i)              (Dem_PidTable[i].DemPidDataElementClassRef)
#endif
#endif/*#if((DEM_CFG_OBD_SUPPORT == DEM_OBD_MASTER_ECU)||(DEM_CFG_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU))*/


/* Status bit0 testFailed  */
#define DEM_TEST_UDS_STATUS_TF(Status)              ((Status & DEM_UDS_STATUS_TF) != 0)
#define DEM_SET_UDS_STATUS_TF(Status)               (Status | DEM_UDS_STATUS_TF)
#define DEM_CLEAR_UDS_STATUS_TF(Status)             (Status & (~DEM_UDS_STATUS_TF))

/* Status bit1 testFailedThisOperationCycle */
#define DEM_TEST_UDS_STATUS_TFTOC(Status)           ((Status & DEM_UDS_STATUS_TFTOC) != 0)
#define DEM_SET_UDS_STATUS_TFTOC(Status)            (Status | DEM_UDS_STATUS_TFTOC)
#define DEM_CLEAR_UDS_STATUS_TFTOC(Status)          (Status & (~DEM_UDS_STATUS_TFTOC))

/* Status bit2 pendingDTC */
#define DEM_TEST_UDS_STATUS_PDTC(Status)            ((Status & DEM_UDS_STATUS_PDTC) != 0)
#define DEM_SET_UDS_STATUS_PDTC(Status)             (Status | DEM_UDS_STATUS_PDTC)
#define DEM_CLEAR_UDS_STATUS_PDTC(Status)           (Status & (~DEM_UDS_STATUS_PDTC))

/* Status bit3 confirmedDTC */
#define DEM_TEST_UDS_STATUS_CDTC(Status)            ((Status & DEM_UDS_STATUS_CDTC) != 0)
#define DEM_SET_UDS_STATUS_CDTC(Status)             (Status | DEM_UDS_STATUS_CDTC)
#define DEM_CLEAR_UDS_STATUS_CDTC(Status)           (Status & (~DEM_UDS_STATUS_CDTC))

/* Status bit4 testNotCompletedSinceLastClear*/
#define DEM_TEST_UDS_STATUS_TNCSLC(Status)          ((Status & DEM_UDS_STATUS_TNCSLC) != 0)
#define DEM_SET_UDS_STATUS_TNCSLC(Status)           (Status | DEM_UDS_STATUS_TNCSLC)
#define DEM_CLEAR_UDS_STATUS_TNCSLC(Status)         (Status & (~DEM_UDS_STATUS_TNCSLC))

/* Status bit5 testFailedSinceLastClear */
#define DEM_TEST_UDS_STATUS_TFSLC(Status)           ((Status & DEM_UDS_STATUS_TFSLC) != 0)
#define DEM_SET_UDS_STATUS_TFSLC(Status)            (Status | DEM_UDS_STATUS_TFSLC)
#define DEM_CLEAR_UDS_STATUS_TFSLC(Status)          (Status & (~DEM_UDS_STATUS_TFSLC))

/* Status bit6 testNotCompletedThisOperationCycle*/
#define DEM_TEST_UDS_STATUS_TNCTOC(Status)          ((Status & DEM_UDS_STATUS_TNCTOC) != 0)
#define DEM_SET_UDS_STATUS_TNCTOC(Status)           (Status | DEM_UDS_STATUS_TNCTOC)
#define DEM_CLEAR_UDS_STATUS_TNCTOC(Status)         (Status & (~DEM_UDS_STATUS_TNCTOC))

/* Status bit7 warningIndicatorRequested */
#define DEM_TEST_UDS_STATUS_WIR(Status)             ((Status & DEM_UDS_STATUS_WIR) != 0)
#define DEM_SET_UDS_STATUS_WIR(Status)              (Status | DEM_UDS_STATUS_WIR)
#define DEM_CLEAR_UDS_STATUS_WIR(Status)            (Status & (~DEM_UDS_STATUS_WIR))

#if(STD_ON == DEM_CMA_PLATFORM_ENABLED)
/*Status bit0 UnconfirmedDTC*/
#define DEM_TEST_CMA_STATUS_UDTC(Status)            ((Status & DEM_UDS_STATUS_TF) != 0)
#define DEM_SET_CMA_STATUS_UDTC(Status)             (Status | DEM_UDS_STATUS_TF)
#define DEM_CLEAR_CMA_STATUS_UDTC(Status)           (Status & (~DEM_UDS_STATUS_TF))
/*Status bit1 UnconfirmedDTCThisOperationonCycle*/
#define DEM_TEST_CMA_STATUS_UDTCTOC(Status)         ((Status & DEM_UDS_STATUS_TFTOC) != 0)
#define DEM_SET_CMA_STATUS_UDTCTOC(Status)          (Status | DEM_UDS_STATUS_TFTOC)
#define DEM_CLEAR_CMA_STATUS_UDTCTOC(Status)        (Status & (~DEM_UDS_STATUS_TFTOC))
/*Status bit2 UnconfirmedDTCSinceLastClear*/
#define DEM_TEST_CMA_STATUS_UDTCSLC(Status)         ((Status & DEM_UDS_STATUS_PDTC) != 0)
#define DEM_SET_CMA_STATUS_UDTCSLC(Status)          (Status | DEM_UDS_STATUS_PDTC)
#define DEM_CLEAR_CMA_STATUS_UDTCSLC(Status)        (Status & (~DEM_UDS_STATUS_PDTC))
/*Status bit3 AgedDTC*/
#define DEM_TEST_CMA_STATUS_ADTC(Status)            ((Status & DEM_UDS_STATUS_CDTC) != 0)
#define DEM_SET_CMA_STATUS_ADTC(Status)             (Status | DEM_UDS_STATUS_CDTC)
#define DEM_CLEAR_CMA_STATUS_ADTC(Status)           (Status & (~DEM_UDS_STATUS_CDTC))
/*Status bit4 SymptomSinceLastClear*/
#define DEM_TEST_CMA_STATUS_SSLC(Status)            ((Status & DEM_UDS_STATUS_TNCSLC) != 0)
#define DEM_SET_CMA_STATUS_SSLC(Status)             (Status | DEM_UDS_STATUS_TNCSLC)
#define DEM_CLEAR_CMA_STATUS_SSLC(Status)           (Status & (~DEM_UDS_STATUS_TNCSLC))
/*Status bit5 WarningIndicatorRequestedSinceLastClear*/
#define DEM_TEST_CMA_STATUS_WIRSLC(Status)          ((Status & DEM_UDS_STATUS_TFSLC) != 0)
#define DEM_SET_CMA_STATUS_WIRSLC(Status)           (Status | DEM_UDS_STATUS_TFSLC)
#define DEM_CLEAR_CMA_STATUS_WIRSLC(Status)         (Status & (~DEM_UDS_STATUS_TFSLC))
/*Status bit6 EmissionRelatedDTC*/
#define DEM_TEST_CMA_STATUS_ERDTC(Status)           ((Status & DEM_UDS_STATUS_TNCTOC) != 0)
#define DEM_SET_CMA_STATUS_ERDTC(Status)            (Status | DEM_UDS_STATUS_TNCTOC)
#define DEM_CLEAR_CMA_STATUS_ERDTC(Status)          (Status & (~DEM_UDS_STATUS_TNCTOC))
/*Status bit7 TestFailedSinceLastClear/Aged*/
#define DEM_TEST_CMA_STATUS_TFSLCA(Status)          ((Status & DEM_UDS_STATUS_WIR) != 0)
#define DEM_SET_CMA_STATUS_TFSLCA(Status)           (Status | DEM_UDS_STATUS_WIR)
#define DEM_CLEAR_CMA_STATUS_TFSLCA(Status)         (Status & (~DEM_UDS_STATUS_WIR))
#endif
/*******************************************************************************
*   typedef
*******************************************************************************/
typedef struct
{
    boolean FilteredValidFlag;
    Dem_UdsStatusByteType DTCStatusMask;
    Dem_DTCKindType DTCKind;
    Dem_DTCFormatType DTCFormat;
    Dem_DTCOriginType DTCOrigin;
    boolean FilterWithSeverity;
    boolean FilterForFDC;
    Dem_DTCSeverityType DTCSeverityMask;
    uint16 FilteredDTCIndexTable[DEM_NUM_OF_DTC];
    uint16 NumberOfFilteredDTC;
    uint16 NextFilteredDTCIndex;
} Dem_DcmFilterInfoType;

#if(STD_ON == DEM_CFG_J1939READING_DTC_SUPPORT)
typedef struct
{
    boolean FilteredValidFlag;
    Dem_J1939DcmDTCStatusFilterType DTCStatusFilter;
    Dem_DTCKindType DTCKind;
    uint8 node;
    Dem_J1939DcmSetFreezeFrameFilterType FreezeFrameKind;
    uint16 FilteredDTCIndexTable[DEM_NUM_OF_DTC];
    uint16 NumberOfFilteredDTC;
    uint16 NextFilteredDTCIndex;
} Dem_J1939DcmFilterInfoType;
#endif/*#if(STD_ON == DEM_CFG_J1939READING_DTC_SUPPORT)*/


/*******************************************************************************
*   Vars
*******************************************************************************/
#define DEM_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"

VAR(Dem_StorageMemType, DEM_VAR_NOINIT) Dem_StorageMem;

#define DEM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"

#define DEM_START_SEC_VAR_INIT_8
#include "MemMap.h"

STATIC VAR(Dem_StateType, DEM_VAR_INIT) Dem_State = DEM_UNINIT;
STATIC VAR(uint8, DEM_VAR_INIT) Dem_ClearDTCState = DEM_IN_CLEAR_DTC_IDLE;

#define DEM_STOP_SEC_VAR_INIT_8
#include "MemMap.h"

#define DEM_START_SEC_VAR_NOINIT_8
#include "MemMap.h"

STATIC VAR(Dem_OperationCycleStateType, DEM_VAR_NOINIT) Dem_OpCycReq[DEM_NUM_OF_OPCYCLE];
STATIC VAR(Dem_OperationCycleStateType, DEM_VAR_NOINIT) Dem_OpCycState[DEM_NUM_OF_OPCYCLE];


#if(DEM_NUM_OF_EN_CONDITION > 0)
STATIC VAR(boolean, DEM_VAR_NOINIT) Dem_EventEnCondition[DEM_NUM_OF_EN_CONDITION];
#endif
#if(DEM_NUM_OF_STOR_CONDITION > 0)
STATIC VAR(boolean, DEM_VAR_NOINIT) Dem_EventStorCondition[DEM_NUM_OF_STOR_CONDITION];
#endif

#if((DEM_CONFIG_VARIANTS != STD_CONFIG_VARIANTS_POSTBUILD) \
    && (DEM_CFG_AVAILABILITYSUPPORT == DEM_EVENT_AVAILABILITY))
STATIC VAR(uint8, DEM_VAR_NOINIT) Dem_EventAvailable[DEM_NUM_OF_EVENT];
#endif

STATIC VAR(boolean, DEM_VAR_NOINIT) Dem_EnableDtcSetting[DEM_NUM_OF_DTC];
STATIC VAR(boolean, DEM_VAR_NOINIT) Dem_DtcUpDateState[DEM_NUM_OF_DTC];

STATIC VAR(boolean, DEM_VAR_NOINIT) Dem_DataCaptureFlag[DEM_NUM_OF_EVENT];
STATIC VAR(Dem_EventMemoryEntryStorageTriggerType, DEM_VAR_NOINIT) Dem_DataCaptureTrigger[DEM_NUM_OF_EVENT];

#if(DEM_CFG_DEBOUNCETIMEBASEDSUPPORT == STD_ON)
STATIC VAR(boolean, DEM_VAR_NOINIT) Dem_EventDBTFreezeFlag[DEM_NUM_OF_EVENT];
#endif


STATIC VAR(boolean, DEM_VAR_NOINIT) Dem_DTC_FirstFdcThreshold[DEM_NUM_OF_DTC];



#define DEM_STOP_SEC_VAR_NOINIT_8
#include "MemMap.h"

#define DEM_START_SEC_VAR_NOINIT_16
#include "MemMap.h"

STATIC VAR(uint16, DEM_VAR_NOINIT) Dem_CapturePosition;

#if((DEM_CFG_OBD_SUPPORT == DEM_OBD_MASTER_ECU) && (DEM_CFG_OBD_CENTRALIZED_PID31_HANDLING == STD_ON))
STATIC VAR(uint16, DEM_VAR_NOINIT) Dem_ObdTimeSinceEngineStartLast;
STATIC VAR(uint16, DEM_VAR_NOINIT) Dem_ObdTimesOneSecond;
#endif

#define DEM_STOP_SEC_VAR_NOINIT_16
#include "MemMap.h"

#define DEM_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"

STATIC VAR(Dem_DcmFilterInfoType, DEM_VAR_NOINIT) Dem_DcmFilterInfo;
#if(STD_ON == DEM_CFG_J1939READING_DTC_SUPPORT)
STATIC VAR(Dem_J1939DcmFilterInfoType, DEM_VAR_NOINIT) Dem_J1939DcmFilterInfo;
#endif

#define DEM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"

#define DEM_START_SEC_VAR_NOINIT_8
#include "MemMap.h"

/*used for UDS: Dem_DcmSetFreezeFrameRecordFilter & Dem_DcmGetNextFilteredRecord*/
#if(DEM_NUM_OF_FFRECCLASS > 0)
STATIC VAR(uint8, DEM_VAR_NOINIT) Dem_NumFFRecOfDTC;
#endif

#define DEM_STOP_SEC_VAR_NOINIT_8
#include "MemMap.h"

#if(DEM_CFG_BSWERRORBUFFERSIZE > 0)
#define DEM_START_SEC_VAR_NOINIT_16
#include "MemMap.h"
STATIC VAR(Dem_EventIdType, DEM_VAR_NOINIT) Dem_BswErrorQueue[DEM_CFG_BSWERRORBUFFERSIZE];
#define DEM_STOP_SEC_VAR_NOINIT_16
#include "MemMap.h"
#define DEM_START_SEC_VAR_NOINIT_8
#include "MemMap.h"
STATIC VAR(Dem_EventStatusType, DEM_VAR_NOINIT) Dem_BswErrorStatus[DEM_CFG_BSWERRORBUFFERSIZE];
#define DEM_STOP_SEC_VAR_NOINIT_8
#include "MemMap.h"
#endif


#define DEM_START_SEC_VAR_NOINIT_32
#include "MemMap.h"
STATIC VAR(uint32, DEM_VAR_NOINIT) Dem_ClearDTC_DTC;
#define DEM_STOP_SEC_VAR_NOINIT_32
#include "MemMap.h"

#define DEM_START_SEC_VAR_NOINIT_32
#include "MemMap.h"
STATIC VAR(uint16, DEM_VAR_NOINIT) Dem_ClearDTC_Index;
#define DEM_STOP_SEC_VAR_NOINIT_32
#include "MemMap.h"

#define DEM_START_SEC_VAR_NOINIT_8
#include "MemMap.h"
STATIC VAR(Dem_DTCFormatType, DEM_VAR_NOINIT) Dem_ClearDTC_DTCFormat;
STATIC VAR(Dem_DTCOriginType, DEM_VAR_NOINIT) Dem_ClearDTC_DTCOrigin;
#define DEM_STOP_SEC_VAR_NOINIT_8
#include "MemMap.h"



#define DEM_START_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
*   Dem static Api declaration
*******************************************************************************/
STATIC FUNC(void, DEM_CODE) DemInternal_CheckStorageMem
(
    void
);

STATIC FUNC(void, DEM_CODE) DemInternal_SetCaptureQueue
(
    uint16 EventId,
    Dem_EventMemoryEntryStorageTriggerType Trigger
);

STATIC FUNC(void, DEM_CODE) DemInternal_ClrCaptureQueue
(
    uint16 EventId
);

STATIC FUNC(boolean, DEM_CODE) DemInternal_GetCaptureQueue
(
    uint16 EventId,
    Dem_EventMemoryEntryStorageTriggerType *Trigger
);

STATIC FUNC(Dem_UdsStatusByteType, DEM_CODE) DemInternal_SetEventPass
(
    Dem_EventIdType EventId
);

STATIC FUNC(Dem_UdsStatusByteType, DEM_CODE) DemInternal_SetEventFail
(
    Dem_EventIdType EventId
);

STATIC FUNC(void, DEM_CODE) DemInternal_SetEventStatus
(
    Dem_EventIdType EventId,
    Dem_EventStatusType EventStatus
);

STATIC FUNC(Std_ReturnType, DEM_CODE) DemInternal_GetUsableMemoryEntry
(
    uint16 DtcId,
    P2VAR(Dem_MemIdType, AUTOMATIC, DEM_APPL_DATA) MemoryEntryId
);

STATIC FUNC(Std_ReturnType, DEM_CODE) DemInternal_SearchFreeEntry
(
    P2VAR(Dem_MemIdType, AUTOMATIC, DEM_APPL_DATA) MemoryEntryId
);

STATIC FUNC(void, DEM_CODE) DemInternal_ClearOneMemoryEntry
(
    Dem_MemIdType MemoryEntryId
);

STATIC FUNC(Std_ReturnType, DEM_CODE) DemInternal_SearchEntryForDisplacement
(
    uint16 DtcId,
    P2VAR(Dem_MemIdType, AUTOMATIC, DEM_APPL_DATA) MemoryEntryId
);

#if((DEM_CFG_OBD_SUPPORT == DEM_OBD_MASTER_ECU)||(DEM_CFG_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU))
#if(DEM_CFG_OBD_EVENT_DISPLACEMENT == STD_ON)
STATIC FUNC(boolean, DEM_CODE) DemInternal_IgnoreFoundEntry
(
    uint16 EventId
);
#endif
#endif

#if(DEM_CFG_EVENTDISPLACEMENTSTRATEGY == DEM_DISPLACEMENT_FULL)
STATIC FUNC(boolean, DEM_CODE) DemInternal_IsDtcActive
(
    uint16 DtcId
);
#endif

#if(DEM_CFG_EVENTDISPLACEMENTSTRATEGY != DEM_DISPLACEMENT_NONE)
STATIC FUNC(boolean, DEM_CODE) DemInternal_IsDtcOlder
(
    uint16 Event1,
    uint16 Event2
);
#endif

STATIC FUNC(uint8, DEM_CODE) DemInternal_GetEventInternalData
(
    uint16 EventId,
    Dem_InternalDataElementType DataType
);

#if(((DEM_MAX_FFSIZE_OF_DTC > 0)&&(DEM_NUM_OF_FFRECCLASS > 0))||((DEM_MAX_EXTSIZE_OF_DTC > 0)&&(DEM_NUM_OF_EXTDATACLASS > 0))\
    || (DEM_MAX_J1939FFSIZE_OF_DTC > 0) || (DEM_MAX_J1939EXPFFSIZE_OF_DTC > 0))
STATIC FUNC(void, DEM_CODE) DemInternal_StorageDataElement
(
    uint16 EventId,
    uint16 DataIdx,
    P2P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DataBufferPtr
);
#endif

STATIC FUNC(uint8, DEM_CODE) DemInternal_GetDtcInternalData
(
    uint16 DtcId,
    uint16 DataIdx
);

STATIC FUNC(void, DEM_CODE) DemInternal_CaptureData
(
    uint16 EventId
);

#if((DEM_MAX_FFSIZE_OF_DTC > 0) && (DEM_NUM_OF_FFRECCLASS > 0) \
    || ((DEM_MAX_J1939FFSIZE_OF_DTC > 0) || (DEM_MAX_J1939EXPFFSIZE_OF_DTC > 0)))
STATIC FUNC(boolean, DEM_CODE) DemInternal_UpdateFFData
(
    uint16 EventId,
    Dem_EventMemoryEntryStorageTriggerType Trigger
);
#endif

#if((DEM_MAX_EXTSIZE_OF_DTC > 0) && (DEM_NUM_OF_EXTDATACLASS > 0))
STATIC FUNC(boolean, DEM_CODE) DemInternal_UpdateExtData
(
    uint16 EventId,
    Dem_EventMemoryEntryStorageTriggerType Trigger
);
#endif

STATIC FUNC(void, DEM_CODE) DemInternal_CycleStartProcess
(
    uint8 OperationCycleId
);

STATIC FUNC(void, DEM_CODE) DemInternal_CycleEndProcess
(
    uint8 OperationCycleId
);

STATIC FUNC(void, DEM_CODE) DemInternal_MainFnc_OperationCycle
(
    void
);

STATIC FUNC(void, DEM_CODE) DemInternal_MainFnc_BswErrorHandle
(
    void
);

#if(DEM_CFG_DEBOUNCETIMEBASEDSUPPORT == STD_ON)
STATIC FUNC(void, DEM_CODE) DemInternal_MainFnc_DebounceTimer
(
    void
);
#endif

STATIC FUNC(void, DEM_CODE) DemInternal_MainFnc_CaptureData
(
    void
);

STATIC FUNC(void, DEM_CODE) DemInternal_MainFnc_ClearDTC
(
    void
);

STATIC FUNC(void, DEM_CODE) DemInternal_ClearOneDTC
(
    uint16 DtcId
);

STATIC FUNC(void, DEM_CODE) DemInternal_ClearOneEvent
(
    Dem_EventIdType EventId,
    boolean Aging
);

STATIC FUNC(void, DEM_CODE) DemInternal_ClearOneDTCGroup
(
    void
);

STATIC FUNC(Std_ReturnType, DEM_CODE) DemInternal_GetEventFreezeFrameDataEx
(
    Dem_EventIdType EventId,
    uint8 RecordNumber,
    uint16 DataId,
    uint8 *DestBuffer,
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) BufSize
);

STATIC FUNC(Std_ReturnType, DEM_CODE) DemInternal_GetEventExtendedDataRecordEx
(
    Dem_EventIdType EventId,
    uint8 RecordNumber,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DestBuffer,
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) BufSize
);

#if(DEM_NUM_OF_INDICATOR > 0)
STATIC FUNC(void, DEM_CODE) DemInternal_IndicatorOnCriteriaFulfilled
(
    Dem_EventIdType EventId,
    Dem_UdsStatusByteType EventOldStatus, 
    P2VAR(Dem_UdsStatusByteType, AUTOMATIC, DEM_APPL_DATA) EventNewStatus
);

STATIC FUNC(void, DEM_CODE) DemInternal_IndicatorOffCriteriaFulfilled
(
    Dem_EventIdType EventId,
    Dem_IndicatorOffType OffReason,
    Dem_UdsStatusByteType EventOldStatus, 
    P2VAR(Dem_UdsStatusByteType, AUTOMATIC, DEM_APPL_DATA) EventNewStatus
);

STATIC FUNC(void, DEM_CODE) DemInternal_GetIndicatorStatus
(
    uint8 IndicatorId,
    P2VAR(Dem_IndicatorStatusType, AUTOMATIC, DEM_APPL_DATA) IndicatorStatus
);
#endif/*#if(DEM_NUM_OF_INDICATOR > 0)*/

#if((DEM_CFG_OBD_SUPPORT == DEM_OBD_MASTER_ECU)||(DEM_CFG_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU))
STATIC FUNC(void, DEM_CODE) DemInternal_InitOBDData
(
    void
);

STATIC FUNC(void, DEM_CODE) DemInternal_StoreOBDFreezeFrame
(
    Dem_EventIdType EventId,
    Dem_UdsStatusByteType EventOldStatus,
    Dem_UdsStatusByteType EventNewStatus
);

STATIC FUNC(void, DEM_CODE) DemInternal_ClearOBDFreezeFrame
(
    Dem_EventIdType EventId
);

STATIC FUNC(void, DEM_CODE) DemInternal_MainFnc_OBD
(
    void
);

#if((DEM_CFG_OBD_SUPPORT == DEM_OBD_MASTER_ECU) && (DEM_CFG_OBD_CENTRALIZED_PID31_HANDLING == STD_ON))
STATIC FUNC(void, DEM_CODE) DemInternal_CalPID31Data
(
    void
);
#endif/*#if((DEM_CFG_OBD_SUPPORT == DEM_OBD_MASTER_ECU) && (DEM_CFG_OBD_CENTRALIZED_PID31_HANDLING == STD_ON))*/

#if(DEM_NUM_OF_RATIO > 0)
STATIC FUNC(void, DEM_CODE) DemInternal_UpdateRatioNumerator
(
    Dem_EventIdType EventId
);

STATIC FUNC(void, DEM_CODE) DemInternal_UpdateRatioDenominator
(
    void
);
#endif/*#if(DEM_NUM_OF_RATIO > 0)*/
#endif/*#if((DEM_CFG_OBD_SUPPORT == DEM_OBD_MASTER_ECU)||(DEM_CFG_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU))*/

#if(DEM_CFG_MAXNUMBEREVENTENTRY_PERMANENT > 0)
STATIC FUNC(void, DEM_CODE) DemInternal_AddEventPermanentEntry
(
    Dem_EventIdType EventId
);

STATIC FUNC(void, DEM_CODE) DemInternal_RemoveEventPermanentEntry
(
    Dem_EventIdType EventId
);
#endif/*#if(DEM_CFG_MAXNUMBEREVENTENTRY_PERMANENT > 0)*/

STATIC FUNC(Std_ReturnType, DEM_CODE) DemInternal_J1939GetSizeOfFreezeFrame
(
    uint16 DtcId,
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) SizeOfFreezeFrame,
    Dem_J1939DcmSetFreezeFrameFilterType FreezeFrameKind
);

STATIC FUNC(void, DEM_CODE) DemInternal_J1939GetOccurrenceCounter
(
    uint16 DtcId,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) OccurenceCounter
);
STATIC FUNC(void, DEM_CODE) DemInternal_J1939GetDataOfFreezeFrame
(
    uint16 DtcId,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DestBuffer,
    Dem_J1939DcmSetFreezeFrameFilterType FreezeFrameKind
);
/*******************************************************************************
*   Dem static Api definition
*******************************************************************************/

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DemInternal_CheckStorageMem
*
* Description:
*
* Inputs:
*
* Outputs:
*
* Return:
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, DEM_CODE) DemInternal_CheckStorageMem
(
    void
)
{
    uint16 i;
#if((DEM_MAX_FFSIZE_OF_DTC > 0)||(DEM_MAX_EXTSIZE_OF_DTC > 0))
    uint16 j;
#endif
    Std_ReturnType ret = E_OK;

    if(((DEM_EVENT_FIRST_FAILED != DEM_DATA_INVALID_U16) && (DEM_EVENT_FIRST_FAILED >= DEM_NUM_OF_EVENT)) \
        || ((DEM_EVENT_RECENT_FAILED != DEM_DATA_INVALID_U16) && (DEM_EVENT_RECENT_FAILED >= DEM_NUM_OF_EVENT)) \
        || ((DEM_EVENT_FIRST_CONFIRMED != DEM_DATA_INVALID_U16) && (DEM_EVENT_FIRST_CONFIRMED >= DEM_NUM_OF_EVENT)) \
        || ((DEM_EVENT_RECENT_CONFIRMED != DEM_DATA_INVALID_U16) && (DEM_EVENT_RECENT_CONFIRMED >= DEM_NUM_OF_EVENT)))
    {
        ret = E_NOT_OK;
    }

    if((ret == E_OK) && (DEM_PRIMARY_DATAENTRY_USEDNUM > DEM_CFG_MAXNUMBEREVENTENTRY_PRIMARY))
    {
        ret = E_NOT_OK;
    }

    if((ret == E_OK) && (DEM_PRIMARY_DATAENTRY_USEDNUM == DEM_DATA_CLEAR))
    {
        for(i = 0; i < DEM_CFG_MAXNUMBEREVENTENTRY_PRIMARY; i++)
        {
#if(DEM_MAX_FFSIZE_OF_DTC > 0)
            for(j = 0; j < DEM_MAX_FFSIZE_OF_DTC; j++)
            {
                if((DEM_PRIMARY_FFDATA_PTR(i))[j] != DEM_DATA_INVALID_U8)
                {
                    ret = E_NOT_OK;
                    break;
                }
            }
#endif/*#if(DEM_MAX_FFSIZE_OF_DTC > 0)*/

#if(DEM_MAX_EXTSIZE_OF_DTC > 0)
            if(ret == E_OK)
            {
                for(j = 0; j < DEM_MAX_EXTSIZE_OF_DTC; j++)
                {
                    if((DEM_PRIMARY_EXTDATA_PTR(i))[j] != DEM_DATA_INVALID_U8)
                    {
                        ret = E_NOT_OK;
                        break;
                    }
                }
            }
#endif/*#if(DEM_MAX_EXTSIZE_OF_DTC > 0)*/
            if(ret == E_NOT_OK)
            {
                break;
            }
        }
    }

#if(DEM_CFG_MAXNUMBEREVENTENTRY_PERMANENT > 0)
    if((ret == E_OK) && (DEM_PERMANENT_DATAENTRY_USEDNUM > DEM_CFG_MAXNUMBEREVENTENTRY_PERMANENT))
    {
        ret = E_NOT_OK;
    }

    if((ret == E_OK) && (DEM_PERMANENT_DATAENTRY_USEDNUM == DEM_DATA_CLEAR))
    {
        for(i = 0; i < DEM_CFG_MAXNUMBEREVENTENTRY_PERMANENT; i++)
        {
            if(DEM_PERMANENT_DATAENTRY_EVENTID(i) != DEM_EVENT_ID_INVALID)
            {
                ret = E_NOT_OK;
                break;
            }
        }
    }
#endif/*#if(DEM_CFG_MAXNUMBEREVENTENTRY_PERMANENT > 0)*/

    if(ret == E_OK)
    {
        for(i = (uint16)0; i < DEM_NUM_OF_EVENT; i++)
        {
            if((DEM_EVENT_MAXFDCDCC(i) > DEM_EVENT_MAXFDCSLC(i)) \
                || (DEM_EVENT_CSLF(i) > DEM_EVENT_CSFF(i)))
            {
                ret = E_NOT_OK;
                break;
            }
            else if((DEM_DTC_DATAENTRYREF(DEM_CFG_EVENT_DTCREF(i)) != DEM_DATA_INVALID_U16) \
                && (DEM_DTC_DATAENTRYREF(DEM_CFG_EVENT_DTCREF(i)) >= DEM_CFG_MAXNUMBEREVENTENTRY_PRIMARY))
            {
                ret = E_NOT_OK;
                break;
            }
            else
            {
                /*Continue check*/
            }
        }
    }

    if(ret == E_NOT_OK)
    {
        DEM_DET_REPORT_ERROR(DEM_INIT_APIID, DEM_E_INIT_FAILED);
        (void)Dem_NvM_InitStorageMem();
    }
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DemInternal_SetCaptureQueue
*
* Description:
*
* Inputs:
*
* Outputs:
*
* Return:
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, DEM_CODE) DemInternal_SetCaptureQueue
(
    uint16 EventId,
    Dem_EventMemoryEntryStorageTriggerType Trigger
)
{
    Dem_DataCaptureFlag[EventId] = TRUE;
    Dem_DataCaptureTrigger[EventId] |= Trigger;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name:
*
* Description:
*
* Inputs:
*
* Outputs:
*
* Return:
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, DEM_CODE) DemInternal_ClrCaptureQueue
(
    uint16 EventId
)
{
    Dem_DataCaptureFlag[EventId] = FALSE;
    Dem_DataCaptureTrigger[EventId] = DEM_DATA_CLEAR;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name:
*
* Description:
*
* Inputs:
*
* Outputs:
*
* Return:
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(boolean, DEM_CODE) DemInternal_GetCaptureQueue
(
    uint16 EventId,
    Dem_EventMemoryEntryStorageTriggerType *Trigger
)
{
    boolean ret = FALSE;

    if(Dem_DataCaptureFlag[EventId] == TRUE)
    {
        ret = TRUE;
    }

    if(Trigger != NULL_PTR)
    {
        *Trigger = Dem_DataCaptureTrigger[EventId];
    }

    return ret;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name:
*
* Description:
*
* Inputs:
*
* Outputs:
*
* Return:
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(Dem_UdsStatusByteType, DEM_CODE) DemInternal_SetEventPass
(
    Dem_EventIdType EventId
)
{
    Dem_UdsStatusByteType EventNewStatus;
    Dem_UdsStatusByteType EventOldStatus;
#if(STD_ON == DEM_CMA_PLATFORM_ENABLED)
    uint8 EventCmaStatus;
#endif

    EventNewStatus = DEM_DTC_STATUS(DEM_CFG_EVENT_DTCREF(EventId));
    EventOldStatus = DEM_DTC_STATUS(DEM_CFG_EVENT_DTCREF(EventId));

    /*SWS_Dem_00036*//*SWS_Dem_00386*/
    EventNewStatus = DEM_CLEAR_UDS_STATUS_TF(EventNewStatus);
    /*SWS_Dem_00392*/
    EventNewStatus = DEM_CLEAR_UDS_STATUS_TNCSLC(EventNewStatus);
    /*SWS_Dem_00394*/
    EventNewStatus = DEM_CLEAR_UDS_STATUS_TNCTOC(EventNewStatus);

#if(STD_ON == DEM_CMA_PLATFORM_ENABLED)
    EventCmaStatus = DEM_EVENT_CMA_STATUS(EventId);
    EventCmaStatus = DEM_CLEAR_CMA_STATUS_UDTC(EventCmaStatus);
    DEM_EVENT_CMA_STATUS(EventId) = EventCmaStatus;

    if((DEM_TEST_UDS_STATUS_TFSLC(EventNewStatus)) \
        && (!DEM_TEST_UDS_STATUS_TFTOC(EventNewStatus)) \
		&& (DEM_TEST_UDS_STATUS_TNCTOC(EventOldStatus)) \
        && (DEM_EVENT_CMA_PCSLF(EventId) < DEM_DATA_U8_FF))
    {
        DEM_EVENT_CMA_PCSLF(EventId)++;
    }
#endif

    /*SWS_Dem_00421*/
#if(DEM_CFG_DEBOUNCECOUNTERBASEDSUPPORT == STD_ON)
    if(DEM_CFG_EVENT_DBC(EventId) != NULL_PTR)
    {
        DEM_EVENT_DBC(EventId) = DEM_CFG_EVENT_DBC_PASSTHRESHOLD(EventId);
    }
#endif
    /*SWS_Dem_00435*/
#if(DEM_CFG_DEBOUNCETIMEBASEDSUPPORT == STD_ON)
    if(DEM_CFG_EVENT_DBT(EventId) != NULL_PTR)
    {
        DEM_EVENT_DBT(EventId) = DEM_CFG_EVENT_DBT_PASSED(EventId);
        DEM_EVENT_TIMERDIRECTION(EventId) = DEM_EVENT_STATUS_PASSED;
        Dem_EventDBTFreezeFlag[EventId] = FALSE;
    }
#endif

#if(STD_ON != DEM_CMA_PLATFORM_ENABLED)
    if((DEM_TEST_UDS_STATUS_TF(EventOldStatus)) && (!DEM_TEST_UDS_STATUS_TF(EventNewStatus)))
#endif
    {
        /*SWS_Dem_01070*/
        DemInternal_SetCaptureQueue(EventId, DEM_TRIGGER_ON_PASSED);
    }

#if(DEM_NUM_OF_INDICATOR > 0)
    DemInternal_IndicatorOffCriteriaFulfilled(EventId, DEM_TF_CLEAR, EventOldStatus, &EventNewStatus);
#endif

    return EventNewStatus;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name:
*
* Description:
*
* Inputs:
*
* Outputs:
*
* Return:
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(Dem_UdsStatusByteType, DEM_CODE) DemInternal_SetEventFail
(
    Dem_EventIdType EventId
)
{
    Dem_UdsStatusByteType EventOldStatus;
    Dem_UdsStatusByteType EventNewStatus;
#if(DEM_NUM_OF_STOR_GROUP > 0)
    boolean EventStorageCondFullFilled = TRUE;
#endif
#if(STD_ON == DEM_CMA_PLATFORM_ENABLED)
    uint8 EventCmaStatus;
#endif
#if(DEM_NUM_OF_STOR_CONDITION > 0)
    uint8 i;
#endif

    if(DEM_EVENT_FIRST_FAILED == DEM_DATA_INVALID_U16)
    {
        DEM_EVENT_FIRST_FAILED = EventId;
    }

    EventOldStatus = DEM_DTC_STATUS(DEM_CFG_EVENT_DTCREF(EventId));
    EventNewStatus = DEM_DTC_STATUS(DEM_CFG_EVENT_DTCREF(EventId));

    /*SWS_Dem_00036*//*SWS_Dem_00386*/
    EventNewStatus = DEM_SET_UDS_STATUS_TF(EventNewStatus);
    /*SWS_Dem_00389*/
    EventNewStatus = DEM_SET_UDS_STATUS_TFTOC(EventNewStatus);
    /*SWS_Dem_00390*/
    EventNewStatus = DEM_SET_UDS_STATUS_PDTC(EventNewStatus);
    /*SWS_Dem_00392*/
    EventNewStatus = DEM_CLEAR_UDS_STATUS_TNCSLC(EventNewStatus);
    /*SWS_Dem_00393*/
    EventNewStatus = DEM_SET_UDS_STATUS_TFSLC(EventNewStatus);
    /*SWS_Dem_00394*/
    EventNewStatus = DEM_CLEAR_UDS_STATUS_TNCTOC(EventNewStatus);

#if(STD_ON == DEM_CMA_PLATFORM_ENABLED)
    EventCmaStatus = DEM_EVENT_CMA_STATUS(EventId);
    EventCmaStatus = DEM_SET_CMA_STATUS_UDTC(EventCmaStatus);
    EventCmaStatus = DEM_SET_CMA_STATUS_UDTCTOC(EventCmaStatus);
    EventCmaStatus = DEM_SET_CMA_STATUS_UDTCSLC(EventCmaStatus);
    EventCmaStatus = DEM_CLEAR_CMA_STATUS_ADTC(EventCmaStatus);
    EventCmaStatus = DEM_SET_CMA_STATUS_SSLC(EventCmaStatus);
    EventCmaStatus = DEM_SET_CMA_STATUS_ERDTC(EventCmaStatus);
    EventCmaStatus = DEM_SET_CMA_STATUS_TFSLCA(EventCmaStatus);
    DEM_EVENT_CMA_STATUS(EventId) = EventCmaStatus;
#endif

    /*SWS_Dem_00420*/
#if(DEM_CFG_DEBOUNCECOUNTERBASEDSUPPORT == STD_ON)
    if(DEM_CFG_EVENT_DBC(EventId) != NULL_PTR)
    {
        DEM_EVENT_DBC(EventId) = DEM_CFG_EVENT_DBC_FAILTHRESHOLD(EventId);
    }
#endif
    /*SWS_Dem_00431*/
#if(DEM_CFG_DEBOUNCETIMEBASEDSUPPORT == STD_ON)
    if(DEM_CFG_EVENT_DBT(EventId) != NULL_PTR)
    {
        DEM_EVENT_DBT(EventId) = DEM_CFG_EVENT_DBT_FAILED(EventId);
        DEM_EVENT_TIMERDIRECTION(EventId) = DEM_EVENT_STATUS_FAILED;
        Dem_EventDBTFreezeFlag[EventId] = FALSE;
    }
#endif
    /*SWS_Dem_00791*/
    DEM_EVENT_MAXFDCDCC(EventId) = DEM_DATA_MAX_FDC;
    /*SWS_Dem_00795*/
    DEM_EVENT_MAXFDCSLC(EventId) = DEM_DATA_MAX_FDC;
    /*Reset DTC aging counter*/
    DEM_DTC_AGINGCNT(DEM_CFG_EVENT_DTCREF(EventId)) = DEM_DATA_CLEAR;

    if(!DEM_TEST_UDS_STATUS_TFTOC(EventOldStatus))
    {
        if(DEM_EVENT_FCC(EventId) < DEM_CFG_EVENT_FAULTCNTTHRESHOLD(EventId))
        {
            DEM_EVENT_FCC(EventId)++;
            if(DEM_EVENT_FCC(EventId) >= DEM_CFG_EVENT_FAULTCNTTHRESHOLD(EventId))
            {
#if(STD_ON == DEM_CMA_PLATFORM_ENABLED)
                DEM_EVENT_FCC(EventId) = DEM_DATA_CLEAR;
#endif
                /*SWS_Dem_00391*/
                EventNewStatus = DEM_SET_UDS_STATUS_CDTC(EventNewStatus);
                if(DEM_EVENT_FIRST_CONFIRMED == DEM_DATA_INVALID_U16)
                {
                    DEM_EVENT_FIRST_CONFIRMED = EventId;
                }

                if(!DEM_TEST_UDS_STATUS_CDTC(EventOldStatus))
                {
                    DEM_EVENT_RECENT_CONFIRMED = EventId;
                }
            }
        }
    }

    /*SWS_Dem_00771*//*SWS_Dem_00772*/
    DEM_EVENT_CSLF(EventId) = DEM_DATA_CLEAR;

    if(!DEM_TEST_UDS_STATUS_TF(EventOldStatus))
    {
        /*SWS_Dem_00787*/
        DEM_EVENT_RECENT_FAILED = EventId;
#if((DEM_CFG_OBD_SUPPORT == DEM_OBD_MASTER_ECU)||(DEM_CFG_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU))
        DEM_EVENT_OBD_PCSLF(EventId) = DEM_DATA_CLEAR;
#endif
#if(STD_ON == DEM_CMA_PLATFORM_ENABLED)
        DEM_EVENT_CMA_PCSLF(EventId) = DEM_DATA_CLEAR;
#endif

#if(DEM_PROCESS_OCCCTR_TF == DEM_CFG_OCCURRENCECOUNTERPROCESSING)
        /*SWS_Dem_00524*/
        if(DEM_DTC_DATAENTRYREF(DEM_CFG_EVENT_DTCREF(EventId)) != DEM_DATA_INVALID_U16)
#else
        /*SWS_Dem_00580*/
        if((DEM_DTC_DATAENTRYREF(DEM_CFG_EVENT_DTCREF(EventId)) != DEM_DATA_INVALID_U16) \
                && (DEM_TEST_UDS_STATUS_CDTC(EventNewStatus)))
#endif
        {
            /*SWS_Dem_00625*/
            if(DEM_EVENT_OCCCTR(EventId) < DEM_DATA_U8_FF)
            {
                DEM_EVENT_OCCCTR(EventId)++;
            }
        }
    }

    if(!DEM_TEST_UDS_STATUS_TFSLC(EventOldStatus))
    {
        /*SWS_Dem_00776*/
        DEM_EVENT_CSFF(EventId) = DEM_DATA_CLEAR;
        /*SWS_Dem_00780*/
        DEM_EVENT_FCSLC(EventId) = DEM_DATA_CLEAR;
    }

#if(STD_ON == DEM_CMA_PLATFORM_ENABLED)
    /*SWS_Dem_00782*/
    if((!DEM_TEST_UDS_STATUS_TFTOC(EventOldStatus)) \
            && (DEM_EVENT_FCSLC(EventId) < DEM_DATA_U8_FF))
    {
        DEM_EVENT_FCSLC(EventId)++;
    }
#endif

#if(DEM_NUM_OF_STOR_GROUP > 0)
    /*SWS_Dem_00455*//*SWS_Dem_00458*/
    /*SWS_Dem_00591*//*SWS_Dem_00459*/
    if(DEM_CFG_EVENT_STOR(EventId) != NULL_PTR)
    {
        for(i = 0; i < DEM_CFG_EVENT_STOR_NUM(EventId); i++)
        {
            if(Dem_EventStorCondition[(DEM_CFG_EVENT_STOR_REF(EventId)[i])] != TRUE)
            {
                EventStorageCondFullFilled = FALSE;
                break;
            }
        }
    }
    if(EventStorageCondFullFilled != FALSE)
    {
#endif
        if(!DEM_TEST_UDS_STATUS_TF(EventOldStatus))
        {
            /*SWS_Dem_00783*/
            DemInternal_SetCaptureQueue(EventId, DEM_TRIGGER_ON_TEST_FAILED);
            /*SWS_Dem_00784*//*SWS_Dem_00922*/
            DemInternal_SetCaptureQueue(EventId, DEM_TRIGGER_ON_PENDING);
            /*SWS_Dem_00923*/
            if(DEM_TEST_UDS_STATUS_CDTC(EventNewStatus))
            {
                DemInternal_SetCaptureQueue(EventId, DEM_TRIGGER_ON_CONFIRMED);
            }
        }

        if((DEM_TEST_UDS_STATUS_CDTC(EventNewStatus)) && (!DEM_TEST_UDS_STATUS_CDTC(EventOldStatus)))
        {
            /*SWS_Dem_00785*/
            DemInternal_SetCaptureQueue(EventId, DEM_TRIGGER_ON_CONFIRMED);
        }

#if((DEM_CFG_OBD_SUPPORT == DEM_OBD_MASTER_ECU)||(DEM_CFG_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU))
        DemInternal_StoreOBDFreezeFrame(EventId, EventOldStatus, EventNewStatus);
#endif/*#if((DEM_CFG_OBD_SUPPORT == DEM_OBD_MASTER_ECU)||(DEM_CFG_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU))*/

#if(DEM_NUM_OF_STOR_GROUP > 0)
    }
#endif

#if(DEM_NUM_OF_INDICATOR > 0)
    DemInternal_IndicatorOnCriteriaFulfilled(EventId, EventOldStatus, &EventNewStatus);
#endif
#if(DEM_CFG_MAXNUMBEREVENTENTRY_PERMANENT > 0)
    DemInternal_AddEventPermanentEntry(EventId);
    DEM_EVENT_OBD_CLEAR_FLAG(EventId) = FALSE;
#endif
    return EventNewStatus;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name:
*
* Description:
*
* Inputs:
*
* Outputs:
*
* Return:
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, DEM_CODE) DemInternal_SetEventStatus
(
    Dem_EventIdType EventId,
    Dem_EventStatusType EventStatus
)
{
    Dem_UdsStatusByteType EventOldStatus;
    Dem_UdsStatusByteType EventNewStatus;
#if(STD_ON == DEM_CMA_PLATFORM_ENABLED)
    uint8 EventCmaStatus;
#endif
#if(DEM_CFG_DEBOUNCECOUNTERBASEDSUPPORT == STD_ON)
    sint8 EventOldFdc;
    sint8 EventNewFdc;
    sint8 EventCurrentFDC;
#endif

    /*SWS_Dem_00626*//*SWS_Dem_00529*//*SWS_Dem_00481*//*SWS_Dem_00482*/
    if((Dem_OpCycState[DEM_CFG_EVENT_OPCYCREF(EventId)] == DEM_CYCLE_STATE_START) \
        && (Dem_EnableDtcSetting[EventId] == TRUE))
    {
        EventOldStatus = DEM_DTC_STATUS(DEM_CFG_EVENT_DTCREF(EventId));
        EventNewStatus = DEM_DTC_STATUS(DEM_CFG_EVENT_DTCREF(EventId));

        if(EventStatus == DEM_EVENT_STATUS_FAILED)
        {
            EventNewStatus = DemInternal_SetEventFail(EventId);
        }
        else if(EventStatus == DEM_EVENT_STATUS_PREFAILED)
        {
#if(DEM_CFG_DEBOUNCECOUNTERBASEDSUPPORT == STD_ON)
            if(DEM_CFG_EVENT_DBC(EventId) != NULL_PTR)
            {
                EventOldFdc = DEM_EVENT_DBC_F_FDC(EventId);

                if((DEM_EVENT_DBC(EventId) < DEM_CFG_EVENT_DBC_JUMPUP_VALUE(EventId)) \
                        && (DEM_CFG_EVENT_DBC_JUMPUP(EventId) == TRUE))
                {
                    /*SWS_Dem_00425*/
                    DEM_EVENT_DBC(EventId) = DEM_CFG_EVENT_DBC_JUMPUP_VALUE(EventId);
                }

                if((DEM_CFG_EVENT_DBC_FAILTHRESHOLD(EventId) - DEM_EVENT_DBC(EventId)) \
                    > DEM_CFG_EVENT_DBC_INCREMENT_SIZE(EventId))
                {
                    /*SWS_Dem_00418*/
                    DEM_EVENT_DBC(EventId) += DEM_CFG_EVENT_DBC_INCREMENT_SIZE(EventId);
                }
                else
                {
                    EventNewStatus = DemInternal_SetEventFail(EventId);
                }

                EventNewFdc = DEM_EVENT_DBC_F_FDC(EventId);

                if((EventOldFdc < (sint8)DEM_CFG_DTC_FDC_THRESHLD(DEM_CFG_EVENT_DTCREF(EventId))) \
                        && (EventNewFdc >= (sint8)DEM_CFG_DTC_FDC_THRESHLD(DEM_CFG_EVENT_DTCREF(EventId))))
                {
#if(STD_ON == DEM_CMA_PLATFORM_ENABLED)
                    EventCmaStatus = DEM_EVENT_CMA_STATUS(EventId);
                    EventCmaStatus = DEM_SET_CMA_STATUS_UDTC(EventCmaStatus);
                    EventCmaStatus = DEM_SET_CMA_STATUS_UDTCTOC(EventCmaStatus);
                    EventCmaStatus = DEM_SET_CMA_STATUS_UDTCSLC(EventCmaStatus);
                    EventCmaStatus = DEM_CLEAR_CMA_STATUS_ADTC(EventCmaStatus);
                    EventCmaStatus = DEM_SET_CMA_STATUS_SSLC(EventCmaStatus);
                    DEM_EVENT_CMA_STATUS(EventId) = EventCmaStatus;
#endif
                    if(FALSE == Dem_DTC_FirstFdcThreshold[DEM_CFG_EVENT_DTCREF(EventId)])
                    {
                        Dem_DTC_FirstFdcThreshold[DEM_CFG_EVENT_DTCREF(EventId)] = TRUE;
                        /*SWS_Dem_00786*//*SWS_Dem_00799*//*SWS_Dem_00811*/
                        DemInternal_SetCaptureQueue(EventId, DEM_TRIGGER_ON_FDC_THRESHOLD);
                    }
                }

                EventCurrentFDC = DEM_EVENT_DBC_F_FDC(EventId);
                /*SWS_Dem_00791*/
                if(EventCurrentFDC > DEM_EVENT_MAXFDCDCC(EventId))
                {
                    DEM_EVENT_MAXFDCDCC(EventId) = EventCurrentFDC;
                }
                /*SWS_Dem_00795*/
                if(EventCurrentFDC > DEM_EVENT_MAXFDCSLC(EventId))
                {
                    DEM_EVENT_MAXFDCSLC(EventId) = EventCurrentFDC;
                }
            }
#endif

#if(DEM_CFG_DEBOUNCETIMEBASEDSUPPORT == STD_ON)
            if(DEM_CFG_EVENT_DBT(EventId) != NULL_PTR)
            {
                /*SWS_Dem_00429*//*SWS_Dem_00430*/
                if((DEM_EVENT_TIMERDIRECTION(EventId) != DEM_EVENT_STATUS_PREFAILED) \
                        && (DEM_EVENT_TIMERDIRECTION(EventId) != DEM_EVENT_STATUS_FAILED))
                {
                    DEM_EVENT_TIMERDIRECTION(EventId) = DEM_EVENT_STATUS_PREFAILED;
                    DEM_EVENT_DBT(EventId) = 0;
                }
                /*SWS_Dem_00656*/
                Dem_EventDBTFreezeFlag[EventId] = FALSE;
            }
#endif
        }
        else if(EventStatus == DEM_EVENT_STATUS_PASSED)
        {
            EventNewStatus = DemInternal_SetEventPass(EventId);
        }
        else if(EventStatus == DEM_EVENT_STATUS_PREPASSED)
        {
#if(DEM_CFG_DEBOUNCECOUNTERBASEDSUPPORT == STD_ON)
            if(DEM_CFG_EVENT_DBC(EventId) != NULL_PTR)
            {
                if((DEM_EVENT_DBC(EventId) > DEM_CFG_EVENT_DBC_JUMPDOWN_VALUE(EventId)) \
                        && (DEM_CFG_EVENT_DBC_JUMPDOWN(EventId) == TRUE))
                {
                    /*SWS_Dem_00423*/
                    DEM_EVENT_DBC(EventId) = DEM_CFG_EVENT_DBC_JUMPDOWN_VALUE(EventId);
                }

                if((DEM_EVENT_DBC(EventId) - DEM_CFG_EVENT_DBC_PASSTHRESHOLD(EventId)) \
                        > DEM_CFG_EVENT_DBC_DECREMENT_SIZE(EventId))
                {
                    /*SWS_Dem_00419*/
                    DEM_EVENT_DBC(EventId) -= DEM_CFG_EVENT_DBC_DECREMENT_SIZE(EventId);
                }
                else
                {
                    EventNewStatus = DemInternal_SetEventPass(EventId);
                }
            }
#endif

#if(DEM_CFG_DEBOUNCETIMEBASEDSUPPORT == STD_ON)
            if(DEM_CFG_EVENT_DBT(EventId) != NULL_PTR)
            {
                /*SWS_Dem_00432*//*SWS_Dem_00433*/
                if((DEM_EVENT_TIMERDIRECTION(EventId) != DEM_EVENT_STATUS_PREPASSED) \
                        && (DEM_EVENT_TIMERDIRECTION(EventId) != DEM_EVENT_STATUS_PASSED))
                {
                    DEM_EVENT_TIMERDIRECTION(EventId) = DEM_EVENT_STATUS_PREPASSED;
                    DEM_EVENT_DBT(EventId) = 0;
                }
                /*SWS_Dem_00656*/
                Dem_EventDBTFreezeFlag[EventId] = FALSE;
            }
#endif
        }
        else if(EventStatus == DEM_EVENT_STATUS_FDC_THRESHOLD_REACHED)
        {
            if(FALSE == Dem_DTC_FirstFdcThreshold[DEM_CFG_EVENT_DTCREF(EventId)])
            {
                Dem_DTC_FirstFdcThreshold[DEM_CFG_EVENT_DTCREF(EventId)] = TRUE;
                /*SWS_Dem_01068*//*SWS_Dem_01069*/
                DemInternal_SetCaptureQueue(EventId, DEM_TRIGGER_ON_FDC_THRESHOLD);
            }
        }
        else
        {
            /*do nothing*/
        }

        DEM_DTC_STATUS(DEM_CFG_EVENT_DTCREF(EventId)) = EventNewStatus;
#if((DEM_CFG_OBD_SUPPORT == DEM_OBD_MASTER_ECU)||(DEM_CFG_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU))
#if(DEM_NUM_OF_RATIO > 0)
        DemInternal_UpdateRatioNumerator(EventId);
#endif
#endif
        if(EventNewStatus != EventOldStatus)
        {
            /*SWS_Dem_00284*/
            (void)DEM_CFG_DTC_STATUSCHANGED_CALLFNC(DEM_CFG_DTC_VALUE(DEM_CFG_EVENT_DTCREF(EventId)), EventOldStatus, EventNewStatus);

            if(NULL_PTR != DEM_CFG_EVENT_STATUSCHANGED_CALLFNC(EventId))
            {
                /*SWS_Dem_00016*/
                (void)DEM_CFG_EVENT_STATUSCHANGED_CALLFNC(EventId)(EventOldStatus, EventNewStatus);
            }
#if(DEM_CFG_TRIGGER_FIM_REPORTS == STD_ON)
            FiM_DemTriggerOnEventStatus(EventId, EventOldStatus, EventNewStatus);
#endif
        }
    }/*if((Dem_OpCycState[DEM_CFG_EVENT_OPCYCREF(EventId)] == DEM_CYCLE_STATE_START) \
          && (Dem_EnableDtcSetting[EventId] == TRUE))*/
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DemInternal_GetUsableMemoryEntry
*
* Description:
*
* Inputs:
*
* Outputs:
*
* Return:
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(Std_ReturnType, DEM_CODE) DemInternal_GetUsableMemoryEntry
(
    uint16 DtcId,
    P2VAR(Dem_MemIdType, AUTOMATIC, DEM_APPL_DATA) MemoryEntryId
)
{
    /*SWS_Dem_00810*/
    Std_ReturnType Result = E_NOT_OK;

    /*Search a free entry for the reported event.*/
    Result = DemInternal_SearchFreeEntry(MemoryEntryId);

    if(Result != E_OK)
    {
        /*SWS_Dem_00400*//*Event displacement*/
        Result = DemInternal_SearchEntryForDisplacement(DtcId, MemoryEntryId);
    }

    return Result;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DemInternal_SearchFreeEntry
*
* Description: Search a free entry for reported event.
*
* Inputs:
*
* Outputs: MemoryEntryId
*
* Return:
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(Std_ReturnType, DEM_CODE) DemInternal_SearchFreeEntry
(
    P2VAR(Dem_MemIdType, AUTOMATIC, DEM_APPL_DATA) MemoryEntryId
)
{
    Std_ReturnType Result = E_NOT_OK;
    Dem_MemIdType MemIndex;

    if(DEM_PRIMARY_DATAENTRY_USEDNUM < DEM_CFG_MAXNUMBEREVENTENTRY_PRIMARY)
    {
        for(MemIndex = 0; MemIndex < DEM_CFG_MAXNUMBEREVENTENTRY_PRIMARY; MemIndex++)
        {
            if(DEM_PRIMARY_DATAENTRY_USED(MemIndex) == FALSE)
            {
                DEM_PRIMARY_DATAENTRY_USED(MemIndex) = TRUE;
                *MemoryEntryId = MemIndex;
                DEM_PRIMARY_DATAENTRY_USEDNUM++;
                Result = E_OK;
                break;
            }
        }
    }/*if(DEM_PRIMARY_DATAENTRY_USEDNUM < DEM_CFG_MAXNUMBEREVENTENTRY_PRIMARY)*/

    return Result;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DemInternal_ClearOneMemoryEntry
*
* Description: Clear one memory entry.
*
* Inputs: MemoryEntryId
*
* Outputs: None
*
* Return: None
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, DEM_CODE) DemInternal_ClearOneMemoryEntry
(
    Dem_MemIdType MemoryEntryId
)
{
#if((DEM_MAX_FFSIZE_OF_DTC > 0) || (DEM_MAX_EXTSIZE_OF_DTC > 0) || (DEM_MAX_J1939FFSIZE_OF_DTC > 0) || (DEM_MAX_J1939EXPFFSIZE_OF_DTC > 0))
    uint16 DataIndex = 0;
#endif/*#if((DEM_MAX_FFSIZE_OF_DTC > 0) || (DEM_MAX_EXTSIZE_OF_DTC > 0))*/

#if(DEM_MAX_FFSIZE_OF_DTC > 0)
    for(DataIndex = 0; DataIndex < DEM_MAX_FFSIZE_OF_DTC; DataIndex++)
    {
        DEM_PRIMARY_FFDATA_PTR(MemoryEntryId)[DataIndex] = DEM_DATA_INVALID_U8;
    }
#endif

#if(DEM_MAX_J1939FFSIZE_OF_DTC > 0)
    for(DataIndex = 0; DataIndex < DEM_MAX_J1939FFSIZE_OF_DTC; DataIndex++)
    {
        DEM_PRIMARY_J1939DTC_FFDATA_PTR(MemoryEntryId)[DataIndex] = DEM_DATA_INVALID_U8;
    }
#endif

#if(DEM_MAX_J1939EXPFFSIZE_OF_DTC > 0)
    for(DataIndex = 0; DataIndex < DEM_MAX_J1939EXPFFSIZE_OF_DTC; DataIndex++)
    {
        DEM_PRIMARY_J1939DTC_EXPFFDATA_PTR(MemoryEntryId)[DataIndex] = DEM_DATA_INVALID_U8;
    }
#endif

#if(DEM_MAX_EXTSIZE_OF_DTC > 0)
    for(DataIndex = 0; DataIndex < DEM_MAX_EXTSIZE_OF_DTC; DataIndex++)
    {
        DEM_PRIMARY_EXTDATA_PTR(MemoryEntryId)[DataIndex] = DEM_DATA_INVALID_U8;
    }
#endif
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DemInternal_SearchEntryForDisplacement
*
* Description: Event displacement
*
* Inputs: DtcId
*
* Outputs: MemoryEntryId
*
* Return:
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(Std_ReturnType, DEM_CODE) DemInternal_SearchEntryForDisplacement
(
    uint16 DtcId,
    P2VAR(Dem_MemIdType, AUTOMATIC, DEM_APPL_DATA) MemoryEntryId
)
{
    /*SWS_Dem_00810*/
    Std_ReturnType Result = E_NOT_OK;
#if(DEM_CFG_RESETCONFIRMEDBITONOVERFLOW == STD_ON)
    Dem_UdsStatusByteType DtcStatus;
#endif
#if(DEM_CFG_EVENTDISPLACEMENTSTRATEGY != DEM_DISPLACEMENT_NONE)
    uint16 EventId1 = 0;
    uint16 EventId2 = 0;
    uint16 DtcIndex1 = 0;
    uint16 DtcIndex2 = 0;
    boolean DtcActive1 = TRUE;
    boolean DtcActive2 = TRUE;
    Dem_PriorityType LowestPri = DEM_CFG_DTC_PRIORITY(DtcId);
#endif/*#if(DEM_CFG_EVENTDISPLACEMENTSTRATEGY != DEM_DISPLACEMENT_NONE)*/

    /*SWS_Dem_00401*//*SWS_Dem_00402*/
#if(DEM_CFG_EVENTDISPLACEMENTSTRATEGY != DEM_DISPLACEMENT_NONE)
    for(EventId1 = 0; EventId1 < DEM_NUM_OF_EVENT; EventId1++)
    {
        DtcIndex1 = DEM_CFG_EVENT_DTCREF(EventId1);

#if((DEM_CFG_OBD_SUPPORT == DEM_OBD_MASTER_ECU)||(DEM_CFG_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU))
#if(DEM_CFG_OBD_EVENT_DISPLACEMENT == STD_ON)
        if((DEM_DTC_DATAENTRYREF(DtcIndex1) != DEM_DATA_INVALID_U16)
            && (FALSE == DemInternal_IgnoreFoundEntry(EventId1)))
#else/*#if(DEM_CFG_OBD_EVENT_DISPLACEMENT == STD_ON)*/
        if(DEM_DTC_DATAENTRYREF(DtcIndex1) != DEM_DATA_INVALID_U16)
#endif/*#if(DEM_CFG_OBD_EVENT_DISPLACEMENT == STD_ON)*/
#else/*#if((DEM_CFG_OBD_SUPPORT == DEM_OBD_MASTER_ECU)||(DEM_CFG_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU))*/
        if(DEM_DTC_DATAENTRYREF(DtcIndex1) != DEM_DATA_INVALID_U16)
#endif/*#if((DEM_CFG_OBD_SUPPORT == DEM_OBD_MASTER_ECU)||(DEM_CFG_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU))*/
        {
            /*SWS_Dem_00406*//*SWS_Dem_00403*/
            if(LowestPri < DEM_CFG_DTC_PRIORITY(DtcIndex1))
            {
                LowestPri = DEM_CFG_DTC_PRIORITY(DtcIndex1);
                DtcIndex2 = DtcIndex1;
                EventId2 = EventId1;
                *MemoryEntryId = DEM_DTC_DATAENTRYREF(DtcIndex1);
                Result = E_OK;
            }
            else if(LowestPri == DEM_CFG_DTC_PRIORITY(DtcIndex1))
            {
#if(DEM_CFG_EVENTDISPLACEMENTSTRATEGY == DEM_DISPLACEMENT_FULL)
                DtcActive1 = DemInternal_IsDtcActive(DtcIndex1);
                /*SWS_Dem_00404*/
                if(Result == E_NOT_OK)/*None event entry has been searched for displacement.*/
                {
                    if(DtcActive1 == FALSE)
                    {
                        LowestPri = DEM_CFG_DTC_PRIORITY(DtcIndex1);
                        DtcIndex2 = DtcIndex1;
                        EventId2 = EventId1;
                        *MemoryEntryId = DEM_DTC_DATAENTRYREF(DtcIndex1);
                        Result = E_OK;
                    }
                }
                else/*Has found at least one memory entry used by lower priority DTC.*/
                {
                    DtcActive2 = DemInternal_IsDtcActive(DtcIndex2);

                    if(((DtcActive1 == FALSE) && (DtcActive2 == TRUE)) \
                        || (DemInternal_IsDtcOlder(EventId1, EventId2)))
                    {
                        /*SWS_Dem_00405*/
                        LowestPri = DEM_CFG_DTC_PRIORITY(DtcIndex1);
                        DtcIndex2 = DtcIndex1;
                        EventId2 = EventId1;
                        *MemoryEntryId = DEM_DTC_DATAENTRYREF(DtcIndex1);
                        Result = E_OK;
                    }
                }
#else/*DEM_CFG_EVENTDISPLACEMENTSTRATEGY == DEM_DISPLACEMENT_PRIO_OCC*/
                if((DEM_CFG_DTC_PRIORITY(DtcId) < DEM_CFG_DTC_PRIORITY(DtcIndex1)) \
                    && (DemInternal_IsDtcOlder(EventId1, EventId2)))
                {
                    /*SWS_Dem_00405*/
                    LowestPri = DEM_CFG_DTC_PRIORITY(DtcIndex1);
                    DtcIndex2 = DtcIndex1;
                    EventId2 = EventId1;
                    *MemoryEntryId = DEM_DTC_DATAENTRYREF(DtcIndex1);
                    Result = E_OK;
                }
#endif/*#if(DEM_CFG_EVENTDISPLACEMENTSTRATEGY == DEM_DISPLACEMENT_FULL)*/
            }
            else
            {
                /*do nothing*/
            }
        }
    }

    /*Clear the displacement memory entry.*/
    if(Result == E_OK)
    {
        DEM_DTC_DATAENTRYREF(DtcIndex2) = DEM_DATA_INVALID_U16;
        /*SWS_Dem_00408*//*Clear the stored data*/
        DemInternal_ClearOneMemoryEntry(*MemoryEntryId);

#if(DEM_CFG_RESETCONFIRMEDBITONOVERFLOW == STD_ON)
        DtcStatus = DEM_DTC_STATUS(DtcIndex2);
        /*SWS_Dem_00409*/
        DtcStatus = DEM_CLEAR_UDS_STATUS_PDTC(DtcStatus);
        DtcStatus = DEM_CLEAR_UDS_STATUS_CDTC(DtcStatus);

        /*SWS_Dem_01186*/
#if(DEM_CFG_STATUSBITHANDLING_TFSLC == DEM_STATUS_BIT_AGING_AND_DISPLACEMENT)
        DtcStatus = DEM_CLEAR_UDS_STATUS_TFSLC(DtcStatus);
#endif
        DEM_DTC_STATUS(DtcIndex2) = DtcStatus;
#endif
    }
#endif/*#if(DEM_CFG_EVENTDISPLACEMENTSTRATEGY != DEM_DISPLACEMENT_NONE)*/

#if(DEM_CFG_RESETCONFIRMEDBITONOVERFLOW == STD_ON)
    if(Result == E_NOT_OK)
    {
        DtcStatus = DEM_DTC_STATUS(DtcId);
        DtcStatus = DEM_CLEAR_UDS_STATUS_PDTC(DtcStatus);
        DtcStatus = DEM_CLEAR_UDS_STATUS_CDTC(DtcStatus);
        DEM_DTC_STATUS(DtcId) = DtcStatus;
    }
#endif

    return Result;
}

#if((DEM_CFG_OBD_SUPPORT == DEM_OBD_MASTER_ECU)||(DEM_CFG_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU))
#if(DEM_CFG_OBD_EVENT_DISPLACEMENT == STD_ON)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DemInternal_IgnoreFoundEntry
*
* Description: Check whether the found entry should be ignored.
*
* Inputs: DtcId
*
* Outputs:
*
* Return: TRUE: active, FALSE: passive
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(boolean, DEM_CODE) DemInternal_IgnoreFoundEntry
(
    uint16 EventId
)
{
    uint8 Index;
    uint8 IndicatorId;
    uint16 StatusPos;
    boolean Ignore = FALSE;
    uint16 DtcId = DEM_CFG_EVENT_DTCREF(EventId);
    Dem_UdsStatusByteType DtcStatus = DEM_DTC_STATUS(DtcId);

    if(DEM_CFG_DTC_OBDDTCREF(DtcId) == NULL_PTR)
    {
        Ignore = TRUE;
    }
    else if(DEM_OBD_FF_EVENT == EventId)
    {
        Ignore = TRUE;
    }
    else if(DEM_TEST_UDS_STATUS_PDTC(DtcStatus))
    {
        Ignore = TRUE;
    }
    else if((DEM_CFG_EVENT_INDICATOR_NUM(EventId) > (uint8)0) \
        && (DEM_CFG_EVENT_INDICATOR(EventId) != NULL_PTR))
    {
        for(Index = 0; Index < DEM_CFG_EVENT_INDICATOR_NUM(EventId); Index++)
        {
            IndicatorId = DEM_CFG_EVENT_INDICATOR_ID(EventId,Index);
            StatusPos = DEM_CFG_EVENT_INDICATOR_OFFSET(EventId,Index) \
                            + DEM_CFG_INDICATOR_STATUS_START(IndicatorId);

            if((IndicatorId == DEM_CFG_MILINDICATORREF) \
                && (DEM_INDICATOR_STATUS(StatusPos) != DEM_INDICATOR_OFF))
            {
                Ignore = TRUE;
                break;
            }
        }
    }
    else
    {
        /*do nothing*/
    }
    return Ignore;
}
#endif
#endif

#if(DEM_CFG_EVENTDISPLACEMENTSTRATEGY == DEM_DISPLACEMENT_FULL)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DemInternal_IsDtcActive
*
* Description: Get DTC Active/Passive status.
*
* Inputs: DtcId
*
* Outputs:
*
* Return: TRUE: active, FALSE: passive
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(boolean, DEM_CODE) DemInternal_IsDtcActive
(
    uint16 DtcId
)
{
    boolean DtcActive = TRUE;
    Dem_UdsStatusByteType DtcStatus = DEM_DTC_STATUS(DtcId);

    /*SWS_Dem_00692*//*SWS_Dem_00693*/
    if(DEM_TEST_UDS_STATUS_TF(DtcStatus))
    {
        DtcActive = TRUE;
    }
    else
    {
        DtcActive = FALSE;
    }
    return DtcActive;
}
#endif/*#if(DEM_CFG_EVENTDISPLACEMENTSTRATEGY == DEM_DISPLACEMENT_FULL)*/

#if(DEM_CFG_EVENTDISPLACEMENTSTRATEGY != DEM_DISPLACEMENT_NONE)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DemInternal_IsDtcOlder
*
* Description: Check whether the fault Event1 is older than Event2.
*
* Inputs: Event1, Event2
*
* Outputs:
*
* Return:
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(boolean, DEM_CODE) DemInternal_IsDtcOlder
(
    uint16 Event1,
    uint16 Event2
)
{
    boolean E1OlderThanE2 = FALSE;

    if(DEM_EVENT_OCCCTR(Event1) > DEM_EVENT_OCCCTR(Event2))
    {
        E1OlderThanE2 = TRUE;
    }
    return E1OlderThanE2;
}
#endif

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DemInternal_GetEventInternalData
*
* Description:
*
* Inputs:
*
* Outputs:
*
* Return:
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(uint8, DEM_CODE) DemInternal_GetEventInternalData
(
    uint16 EventId,
    Dem_InternalDataElementType DataType
)
{
    uint8 Data;
    uint16 DtcId = DEM_CFG_EVENT_DTCREF(EventId);
    Std_ReturnType ret = E_OK;

    if(DataType == DEM_AGINGCTR_DOWNCNT)
    {
        /*SWS_Dem_00472*//*SWS_Dem_00673*/
        if(DEM_CFG_DTC_AGING_ALLOWED(DtcId) == TRUE)
        {
            Data = DEM_CFG_AGINGCYCLECOUNTERTHRESHOLD(DtcId) - DEM_DTC_AGINGCNT(DtcId);/*1 byte*/
        }
        else
        {
            /*SWS_Dem_01043*/
            Data = DEM_DATA_U8_FF;
        }
    }
    else if(DataType == DEM_AGINGCTR_UPCNT)
    {
        /*SWS_Dem_00472*//*SWS_Dem_00643*/
        if(DEM_CFG_DTC_AGING_ALLOWED(DtcId) == TRUE)
        {
            Data = DEM_DTC_AGINGCNT(DtcId);/*1 byte*/
        }
        else
        {
            /*SWS_Dem_01044*/
            Data = 0;
        }
    }
    else if(DataType == DEM_AGED_COUNTER)
    {
        /*User requirement*/
        Data = DEM_DTC_AGEDCNT(DtcId);/*1 byte*/
    }
    else if(DataType == DEM_CURRENT_FDC)
    {
        /*SWS_Dem_01084*//*SWS_Dem_01045*/
        /*1 byte*/
        ret = Dem_GetFaultDetectionCounter(EventId, (sint8*)&Data);
        if(ret != E_OK)
        {
            Data = DEM_DATA_INVALID_U8;
        }
    }
    else if(DataType == DEM_CYCLES_SINCE_FIRST_FAILED)
    {
        /*SWS_Dem_00821*/
        Data = DEM_EVENT_CSFF(EventId);/*1 byte*/
    }
    else if(DataType == DEM_CYCLES_SINCE_LAST_FAILED)
    {
        /*SWS_Dem_00820*/
        Data = DEM_EVENT_CSLF(EventId);/*1 byte*/
    }
    else if(DataType == DEM_FAILED_CYCLES)
    {
        /*SWS_Dem_00822*/
        Data = DEM_EVENT_FCSLC(EventId);/*1 byte*/
    }
    else if(DataType == DEM_MAX_FDC_DURING_CURRENT_CYCLE)
    {
        /*SWS_Dem_00788*//*SWS_Dem_00819*//*SWS_Dem_00792*/
        Data = DEM_EVENT_MAXFDCDCC(EventId);/*1 byte*/
    }
    else if(DataType == DEM_MAX_FDC_SINCE_LAST_CLEAR)
    {
        /*SWS_Dem_00818*/
        Data = DEM_EVENT_MAXFDCSLC(EventId);/*1 byte*/
    }
    else if(DataType == DEM_OCCCTR)
    {
        /*SWS_Dem_00471*/
        Data = DEM_EVENT_OCCCTR(EventId);/*1 byte*/
    }
#if((DEM_CFG_OBD_SUPPORT == DEM_OBD_MASTER_ECU)||(DEM_CFG_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU))
    else if(DataType == DEM_OBD_PASSED_CYCLES_SINCE_LAST_FAILED)
    {
        Data = DEM_EVENT_OBD_PCSLF(EventId);
    }
#endif
#if(STD_ON == DEM_CMA_PLATFORM_ENABLED)
    else if(DataType == DEM_PASSED_CYCLES_SINCE_LAST_FAILED)
    {
        Data = DEM_EVENT_CMA_PCSLF(EventId);/*1 byte*/
    }
    else if(DataType == DEM_CMA_SI30)
    {
        Data = DEM_EVENT_CMA_STATUS(EventId);/*1 byte*/
    }
    else if(DataType == DEM_CMA_CONSECUTIVE_FAILED_CYCLES)
    {
        Data = DEM_EVENT_FCC(EventId);/*1 byte*/
    }
#endif
    else if(DataType == DEM_OVFLIND)
    {
        /*SWS_Dem_00473*/
        if(DEM_PRIMARY_DATAENTRY_USEDNUM < DEM_CFG_MAXNUMBEREVENTENTRY_PRIMARY)
        {
            Data = FALSE;/*1 byte*/
        }
        else
        {
            Data = TRUE;/*1 byte*/
        }
    }
    else/*(DataType == DEM_SIGNIFICANCE)*/
    {
        /*SWS_Dem_00592*/
        Data = DEM_CFG_DTC_SIGNIFICANCE(DtcId);/*1 byte*/
    }

    return Data;
}

#if(((DEM_MAX_FFSIZE_OF_DTC > 0)&&(DEM_NUM_OF_FFRECCLASS > 0))||((DEM_MAX_EXTSIZE_OF_DTC > 0)&&(DEM_NUM_OF_EXTDATACLASS > 0))\
    || (DEM_MAX_J1939FFSIZE_OF_DTC > 0) || (DEM_MAX_J1939EXPFFSIZE_OF_DTC > 0))
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name:
*
* Description:
*
* Inputs:
*
* Outputs:
*
* Return:
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, DEM_CODE) DemInternal_StorageDataElement
(
    uint16 EventId,
    uint16 DataIdx,
    P2P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DataBufferPtr
)
{
#if(DEM_NUM_OF_DATA > 0)
    uint8 DataSize;
    uint8 i;
    Std_ReturnType ret = E_OK;

    if(DEM_CFG_DATA_IN_DATA(DataIdx) != NULL_PTR)
    {
        DataSize = DEM_CFG_DATA_IN_DATA_SIZE(DataIdx);

        **DataBufferPtr = DemInternal_GetEventInternalData(EventId, DEM_CFG_DATA_IN_DATA_TYPE(DataIdx));

        (*DataBufferPtr) += DataSize;
    }

    if(DEM_CFG_DATA_CS_DATA(DataIdx) != NULL_PTR)
    {
        DataSize = DEM_CFG_DATA_CS_DATA_SIZE(DataIdx);
        /*SWS_Dem_00282*//*SWS_Dem_00918*//*SWS_Dem_00919*//*SWS_Dem_00920*/
        ret = (*DEM_CFG_DATA_CS_DATA_READ_FNC(DataIdx))(*DataBufferPtr);
        /*SWS_Dem_00463*/
        if(ret != E_OK)
        {
            for(i = 0; i < DataSize; i++)
            {
                *((*DataBufferPtr) + i) = DEM_DATA_INVALID_U8;
            }
            /*SWS_Dem_00370*/
            DEM_DET_REPORT_ERROR(DEM_MAINFUNCTION_APIID, DEM_E_NODATAAVAILABLE);
        }
        (*DataBufferPtr) += DataSize;
    }
#endif
}
#endif

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DemInternal_GetDtcInternalData
*
* Description:
*
* Inputs:
*
* Outputs:
*
* Return:
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(uint8, DEM_CODE) DemInternal_GetDtcInternalData
(
    uint16 DtcId,
    uint16 DataIdx
)
{
    uint8 Data = DEM_DATA_U8_FF;
#if(DEM_NUM_OF_DATA > 0)
    uint16 EventId;

    for(EventId = (uint16)0; EventId < DEM_NUM_OF_EVENT; EventId++)
    {
        if(DtcId == DEM_CFG_EVENT_DTCREF(EventId))
        {
            Data = DemInternal_GetEventInternalData(EventId, DEM_CFG_DATA_IN_DATA_TYPE(DataIdx));
            break;
        }
    }
#endif
    return Data;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name:
*
* Description:
*
* Inputs:
*
* Outputs:
*
* Return:
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, DEM_CODE) DemInternal_CaptureData
(
    uint16 EventId
)
{
    Dem_MemIdType MemEntryId;
    uint16 DtcId;

    Dem_EventMemoryEntryStorageTriggerType Trigger;
    boolean ExtDataChangedFlag = FALSE;
	boolean FFDataChangedFlag = FALSE;

    DemInternal_GetCaptureQueue(EventId, &Trigger);
    DemInternal_ClrCaptureQueue(EventId);
    DtcId = DEM_CFG_EVENT_DTCREF(EventId);

    /*DemEventMemoryEntryStorageTrigger: used to allocate an event memory entry.*/
    /*SWS_Dem_00783*//*SWS_Dem_00784*/
    /*SWS_Dem_00922*//*SWS_Dem_00785*/
    /*SWS_Dem_00786*//*SWS_Dem_00810*/
    if((DEM_DTC_DATAENTRYREF(DtcId) == DEM_DATA_INVALID_U16) \
        && (Trigger >= DEM_CFG_EVENTMEMORYENTRYSTORAGETRIGGER))
    {
        if(E_OK == DemInternal_GetUsableMemoryEntry(DtcId, &MemEntryId))
        {
            /*SWS_Dem_00523*/
            DEM_EVENT_OCCCTR(EventId) = 1;

            DEM_DTC_DATAENTRYREF(DtcId) = MemEntryId;
        }
        else
        {
            DEM_EVENT_FCC(EventId) = DEM_DATA_CLEAR;
            DEM_EVENT_OCCCTR(EventId) = DEM_DATA_CLEAR;
            DEM_EVENT_MAXFDCDCC(EventId) = 0;
            DEM_EVENT_MAXFDCSLC(EventId) = 0;
            DEM_EVENT_CSLF(EventId) = DEM_DATA_CLEAR;
            DEM_EVENT_CSFF(EventId) = DEM_DATA_CLEAR;
            DEM_EVENT_FCSLC(EventId) = DEM_DATA_CLEAR;
#if((DEM_CFG_OBD_SUPPORT == DEM_OBD_MASTER_ECU)||(DEM_CFG_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU))
            DEM_EVENT_OBD_PCSLF(EventId) = DEM_DATA_CLEAR;
#endif
#if(STD_ON == DEM_CMA_PLATFORM_ENABLED)
            DEM_EVENT_CMA_PCSLF(EventId) = DEM_DATA_CLEAR;
#endif
        }
    }

    /*Store data for the first time or Update Record*/
    if(DEM_DTC_DATAENTRYREF(DtcId) != DEM_DATA_INVALID_U16)
    {
        /*SWS_Dem_00270: The function Dem_DcmDisableDTCRecordUpdate
        shall protect the event related data of the specified DTC
        within the specified origin from updating or deleting.*/
        if(Dem_DtcUpDateState[DtcId] == TRUE)
        {
#if((DEM_MAX_FFSIZE_OF_DTC > 0) && (DEM_NUM_OF_FFRECCLASS > 0) \
    || ((DEM_MAX_J1939FFSIZE_OF_DTC > 0) || (DEM_MAX_J1939EXPFFSIZE_OF_DTC > 0))) 
            /*Update FreezeFrameData*/
            FFDataChangedFlag = DemInternal_UpdateFFData(EventId, Trigger);
#endif

#if((DEM_MAX_EXTSIZE_OF_DTC > 0) && (DEM_NUM_OF_EXTDATACLASS > 0))
            /*Update Extended Data*/
            ExtDataChangedFlag = DemInternal_UpdateExtData(EventId, Trigger);
#endif
        }
    }
    else
    {
        /*SWS_Dem_00407*/
    }

    if((FFDataChangedFlag == TRUE) || (ExtDataChangedFlag == TRUE))
    {
        /*SWS_Dem_00475*/
        if(DEM_CFG_EVENT_DATACHANGED_CALLFNC(DtcId) != NULL_PTR)
        {
            (void)(*DEM_CFG_EVENT_DATACHANGED_CALLFNC(DtcId))();
        }
    }
}

#if((DEM_MAX_FFSIZE_OF_DTC > 0) && (DEM_NUM_OF_FFRECCLASS > 0) \
    || ((DEM_MAX_J1939FFSIZE_OF_DTC > 0) || (DEM_MAX_J1939EXPFFSIZE_OF_DTC > 0)))
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DemInternal_UpdateFFData
*
* Description: Update the Freeze Frame Data of one Event/DTC.
*
* Inputs: EventId, Trigger
*
* Outputs:
*
* Return: TRUE: Data has been changed. FALSE:No data changed.
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(boolean, DEM_CODE) DemInternal_UpdateFFData
(
    uint16 EventId,
    Dem_EventMemoryEntryStorageTriggerType Trigger
)
{
    boolean DataChangedFlag = FALSE;
    uint8 RecIdx;
    uint8 i;
    uint8 j;
    uint8 DataIdx;
    uint8 *DataBufferPtr;
    uint8 RecNum;
    uint8 DidIdx;
    uint16 DID;
    uint8 k;
    uint16 SPNIndex;
    uint16 DtcId = DEM_CFG_EVENT_DTCREF(EventId);
    Dem_MemIdType MemEntryId = DEM_DTC_DATAENTRYREF(DtcId);
#if(DEM_NUM_OF_FFRECCLASS > 0)
    if(DEM_CFG_DTC_FFRECNUMCLASSREF(DtcId) != NULL_PTR)
    {
        DataBufferPtr = DEM_PRIMARY_FFDATA_PTR(MemEntryId);
        RecNum = 0;

        for(i = 0; i < DEM_CFG_DTC_NUM_OF_FFREC(DtcId); i++)
        {
            RecIdx = (DEM_CFG_DTC_FFREC_ARRAY(DtcId)[i]);
#if(DEM_CFG_TYPE_OF_FF_RECORD_NUMERATION == DEM_FF_RECNUM_CONFIGURED)
            /*SWS_Dem_00582*/
            RecNum = DEM_CFG_DTC_FFRECNUM(RecIdx);
#else
            /*SWS_Dem_00337*//*SWS_Dem_00581*/
            RecNum++;
#endif
            /*DemFreezeFrameRecordTrigger: Defines the trigger to store the FreezeFrameRecord*/
            if(((DEM_CFG_DTC_FFREC_UPDATA(RecIdx) == DEM_UPDATE_RECORD_YES) \
                || ((DEM_CFG_DTC_FFREC_UPDATA(RecIdx) == DEM_UPDATE_RECORD_NO) \
                    && (*DataBufferPtr == DEM_DATA_INVALID_U8))) \
                && (((DEM_CFG_DTC_FFREC_TRIGGER(RecIdx))&Trigger) != 0))
            {
                DataChangedFlag = TRUE;
                /*+ RecNum length(one byte) + RecordNumberOfIdentifiers length(one byte)*/
                *DataBufferPtr = RecNum;
                *(DataBufferPtr + 1) = DEM_CFG_NUMDID_OF_FFRECNUM(RecIdx);
                DataBufferPtr += 2;

                for(j = 0; j < DEM_CFG_NUMDID_OF_FFRECNUM(RecIdx); j++)
                {
                    DidIdx = (DEM_CFG_DIDARRAY_OF_FFRECNUM(RecIdx)[j]);
                    DID = DEM_CFG_DID(DidIdx);
                    /*Did length(two bytes)*/
                    *DataBufferPtr = ((uint8)(DID >> 8));
                    *(DataBufferPtr + 1) = ((uint8)DID);
                    DataBufferPtr += 2;

                    for(k = 0; k < DEM_CFG_NUMDATA_OF_DID(DidIdx); k++)
                    {
                        DataIdx = (DEM_CFG_DATAARRAY_OF_DID(DidIdx)[k]);
                        /*SWS_Dem_00261*/
                        DemInternal_StorageDataElement(EventId, DataIdx, &DataBufferPtr);
                    }
                }
            }
            else
            {
                /*+ RecNum length(one byte) + RecordNumberOfIdentifiers length(one byte)*/
                DataBufferPtr += 2;

                for(j = 0; j < DEM_CFG_NUMDID_OF_FFRECNUM(RecIdx); j++)
                {
                    DidIdx = (DEM_CFG_DIDARRAY_OF_FFRECNUM(RecIdx)[j]);
                    /*Did length(two bytes)*/
                    DataBufferPtr += 2;

                    for(k = 0; k < DEM_CFG_NUMDATA_OF_DID(DidIdx); k++)
                    {
                        DataIdx = (DEM_CFG_DATAARRAY_OF_DID(DidIdx)[k]);

                        if(DEM_CFG_DATA_IN_DATA(DataIdx) != NULL_PTR)
                        {
                            DataBufferPtr += DEM_CFG_DATA_IN_DATA_SIZE(DataIdx);
                        }

                        if(DEM_CFG_DATA_CS_DATA(DataIdx) != NULL_PTR)
                        {
                            DataBufferPtr += DEM_CFG_DATA_CS_DATA_SIZE(DataIdx);
                        }
                    }
                }
            }
        }/*for(i = 0; i < DEM_CFG_DTC_NUM_OF_FFREC(DtcId); i++)*/
    }/*if(DEM_CFG_DTC_FFRECNUMCLASSREF(DtcId) != NULL_PTR)*/
#endif
#if(DEM_MAX_J1939FFSIZE_OF_DTC > 0)
    if(DEM_CFG_J1939DTC_FFRECNUMCLASSREF(DtcId) != NULL_PTR)
    {
        DataBufferPtr = DEM_PRIMARY_J1939DTC_FFDATA_PTR(MemEntryId);
        DataChangedFlag = TRUE;
        for(i = 0U; i < DEM_CFG_J1939DTC_NUM_OF_FFSPNC(DtcId); i++)
        {
            SPNIndex = DEM_CFG_J1939DTC_FFSPNC_ARRAY(DtcId)[i];
            DataIdx = DEM_CFG_DATAARRAY_OF_FFSPN(SPNIndex);
            DemInternal_StorageDataElement(EventId, DataIdx, &DataBufferPtr);
        }
    }
#endif
#if(DEM_MAX_J1939EXPFFSIZE_OF_DTC > 0)
    if( DEM_CFG_1939DTC_EXPFFRECNUMCLASSREF(DtcId) != NULL_PTR)
    {
        DataBufferPtr = DEM_PRIMARY_J1939DTC_EXPFFDATA_PTR(MemEntryId);

        DataChangedFlag = TRUE;
        for(i = 0U; i < DEM_CFG_J1939DTC_NUM_OF_EXPFFSPNC(DtcId); i++)
        {
            SPNIndex = DEM_CFG_J1939DTC_EXPFFSPNC_ARRAY(DtcId)[i];
            DataIdx = DEM_CFG_DATAARRAY_OF_FFSPN(SPNIndex);
            DemInternal_StorageDataElement(EventId, DataIdx, &DataBufferPtr);
        }
    }
#endif
    return DataChangedFlag;
}
#endif

#if((DEM_MAX_EXTSIZE_OF_DTC > 0) && (DEM_NUM_OF_EXTDATACLASS > 0))
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DemInternal_UpdateExtData
*
* Description: Update the Extended Data of one Event/DTC.
*
* Inputs: EventId, Trigger
*
* Outputs:
*
* Return: TRUE: Data has been changed. FALSE:No data changed.
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(boolean, DEM_CODE) DemInternal_UpdateExtData
(
    uint16 EventId,
    Dem_EventMemoryEntryStorageTriggerType Trigger
)
{
    boolean DataChangedFlag = FALSE;
    uint8 RecIdx;
    uint8 i;
    uint8 j;
    uint8 DataIdx;
    uint8 *DataBufferPtr;
    uint16 DtcId = DEM_CFG_EVENT_DTCREF(EventId);
    Dem_MemIdType MemEntryId = DEM_DTC_DATAENTRYREF(DtcId);

    if(DEM_CFG_DTC_EXTDATACLASSREF(DtcId) != NULL_PTR)
    {
        DataBufferPtr = DEM_PRIMARY_EXTDATA_PTR(MemEntryId);

        for(i = 0; i < DEM_CFG_DTC_NUM_OF_EXTREC(DtcId); i++)
        {
            RecIdx = (DEM_CFG_DTC_EXTREC_ARRAY(DtcId)[i]);
            /*SWS_Dem_00809*//*SWS_Dem_00811*/
            /*SWS_Dem_01069*//*SWS_Dem_00812*/
            /*SWS_Dem_00813*//*SWS_Dem_00814*/
            /*SWS_Dem_00815*//*SWS_Dem_00816*/
            if(((DEM_CFG_DTC_EXTREC_UPDATA(RecIdx) == DEM_UPDATE_RECORD_YES) \
                || ((DEM_CFG_DTC_EXTREC_UPDATA(RecIdx) == DEM_UPDATE_RECORD_NO) \
                    && (*DataBufferPtr == DEM_DATA_INVALID_U8))) \
                && (((DEM_CFG_DTC_EXTREC_TRIGGER(RecIdx))&Trigger) != 0))
            {
                DataChangedFlag = TRUE;
                /*+ DataRecNum length(one byte)*/
                *DataBufferPtr = DEM_CFG_DTC_EXTRECNUM(RecIdx);
                DataBufferPtr += 1;

                for(j = 0; j < DEM_CFG_NUMDATA_OF_EXTRECNUM(RecIdx); j++)
                {
                    DataIdx = (DEM_CFG_DATAARRAY_OF_EXTRECNUM(RecIdx)[j]);
                    /*SWS_Dem_00468*/
                    DemInternal_StorageDataElement(EventId, DataIdx, &DataBufferPtr);
                }
            }
            else
            {
                /*+ DataRecNum length(one byte)*/
                DataBufferPtr += 1;

                for(j = 0; j < DEM_CFG_NUMDATA_OF_EXTRECNUM(RecIdx); j++)
                {
                    DataIdx = (DEM_CFG_DATAARRAY_OF_EXTRECNUM(RecIdx)[j]);

                    if(DEM_CFG_DATA_IN_DATA(DataIdx) != NULL_PTR)
                    {
                        DataBufferPtr += DEM_CFG_DATA_IN_DATA_SIZE(DataIdx);
                    }

                    if(DEM_CFG_DATA_CS_DATA(DataIdx) != NULL_PTR)
                    {
                        DataBufferPtr += DEM_CFG_DATA_CS_DATA_SIZE(DataIdx);
                    }
                }
            }
        }
    }
	
	return DataChangedFlag;
}
#endif

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name:
*
* Description:
*
* Inputs:
*
* Outputs:
*
* Return:
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, DEM_CODE) DemInternal_CycleStartProcess
(
    uint8 OperationCycleId
)
{
    uint16 EventId;
    uint16 DtcId;
    Dem_UdsStatusByteType EventOldStatus;
    Dem_UdsStatusByteType EventNewStatus;
#if((DEM_CFG_OBD_SUPPORT == DEM_OBD_MASTER_ECU)||(DEM_CFG_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU))
#if(DEM_NUM_OF_RATIO > 0)
    Dem_RatioIdType RatioID;
#endif
#endif
#if(STD_ON == DEM_CMA_PLATFORM_ENABLED)
    uint8 EventCmaStatus;
#endif


    for(EventId = 0; EventId < DEM_NUM_OF_EVENT; EventId++)
    {
        if(OperationCycleId == DEM_CFG_EVENT_OPCYCREF(EventId))
        {
            DtcId = DEM_CFG_EVENT_DTCREF(EventId);
            EventOldStatus = DEM_DTC_STATUS(DtcId);
            EventNewStatus = DEM_DTC_STATUS(DtcId);
            Dem_DTC_FirstFdcThreshold[DEM_CFG_EVENT_DTCREF(EventId)] = FALSE;
#if(DEM_CFG_DEBOUNCECOUNTERBASEDSUPPORT == STD_ON)
            /*SWS_Dem_00674*//*SWS_Dem_00675*/
            if((DEM_CFG_EVENT_DBC(EventId) != NULL_PTR) && (DEM_CFG_EVENT_DBC_STORAGE(EventId) != TRUE))
            {
                /*SWS_Dem_00344*/
                DEM_EVENT_DBC(EventId) = 0;
            }
#endif
#if(DEM_CFG_DEBOUNCETIMEBASEDSUPPORT == STD_ON)
            DEM_EVENT_DBT(EventId) = 0;
            DEM_EVENT_TIMERDIRECTION(EventId) = DEM_DATA_INVALID_U8;
            Dem_EventDBTFreezeFlag[EventId] = FALSE;
#endif

#if(STD_ON == DEM_CMA_PLATFORM_ENABLED)
            if((!DEM_TEST_UDS_STATUS_TFTOC(EventNewStatus)) \
                    && (!DEM_TEST_UDS_STATUS_TNCTOC(EventNewStatus)))
            {
                DEM_EVENT_FCC(EventId) = DEM_DATA_CLEAR;
            }

            EventCmaStatus = DEM_EVENT_CMA_STATUS(EventId);
            EventCmaStatus = DEM_CLEAR_CMA_STATUS_UDTCTOC(EventCmaStatus);
            DEM_EVENT_CMA_STATUS(EventId) = EventCmaStatus;
#endif

            /*SWS_Dem_00790 The maximum FDC during current operation cycle
            shall be reset to zero with each (re-)start operation cycle.*/
            DEM_EVENT_MAXFDCDCC(EventId) = DEM_DATA_CLEAR;

            /*clear bit1 TestFailedThisOperationCycle*//*SWS_Dem_00389*/
            EventNewStatus = DEM_CLEAR_UDS_STATUS_TFTOC(EventNewStatus);
#if(DEM_CFG_STATUSBITSTORAGE_TF != STD_ON)
            /*clear bit0 TestFailed*//*SWS_Dem_00525*/
            EventNewStatus = DEM_CLEAR_UDS_STATUS_TF(EventNewStatus);
#endif
            /*set bit6 testNotCompletedThisOperationCycle*//*SWS_Dem_00394*/
            EventNewStatus = DEM_SET_UDS_STATUS_TNCTOC(EventNewStatus);

            /*save the current and last operation cycle status*/
            DEM_DTC_LASTSTATUS(DtcId) = EventNewStatus;
            DEM_DTC_STATUS(DtcId) = EventNewStatus;

            if(EventNewStatus != EventOldStatus)
            {
                /*SWS_Dem_00284*/
                (void)DEM_CFG_DTC_STATUSCHANGED_CALLFNC(DEM_CFG_DTC_VALUE(DtcId), EventOldStatus, EventNewStatus);
                if(NULL_PTR != DEM_CFG_EVENT_STATUSCHANGED_CALLFNC(EventId))
                {
                    /*SWS_Dem_00016*/
                    (void)DEM_CFG_EVENT_STATUSCHANGED_CALLFNC(EventId)(EventOldStatus, EventNewStatus);
                }
#if(DEM_CFG_TRIGGER_FIM_REPORTS == STD_ON)
                FiM_DemTriggerOnEventStatus(EventId, EventOldStatus, EventNewStatus);
#endif
            }
            /*SWS_Dem_00679*/
            if(DEM_CFG_EVENT_INITM_CALLFNC(EventId) != NULL_PTR)
            {
                DEM_CFG_EVENT_INITM_CALLFNC(EventId)(DEM_INIT_MONITOR_RESTART);
            }
        }
    }/*for(EventId = 0; EventId < DEM_NUM_OF_EVENT; EventId++)*/

#if((DEM_CFG_OBD_SUPPORT == DEM_OBD_MASTER_ECU)||(DEM_CFG_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU))
#if(DEM_NUM_OF_RATIO > 0)
    if(DEM_CFG_OPCYC_TYPE(OperationCycleId) == DEM_OPCYC_IGNITION)
    {
        if(DEM_OBD_RATIO_IGN_CNT >= DEM_OBD_NUMDEN_MAX_VALUE)
        {
            DEM_OBD_RATIO_IGN_CNT = DEM_DATA_CLEAR;
        }

        /*Clear the General Denominator increased flag*/
        DEM_OBD_RATIO_GENDEN_STATE &= (~DEM_OBD_DEN_INCREASED_MASK);
        /*Reset the General Denominator condition state.*/
        DEM_OBD_RATIO_DENOMCOND_STATUS(DEM_IUMPR_GENERAL_DENOMINATOR) = DEM_IUMPR_DEN_STATUS_NOT_REACHED;
        /*Ignition Cycle counter increase 1*/
        DEM_OBD_RATIO_IGN_CNT++;

        if(DEM_OBD_RATIO_GENDEN_CNT >= DEM_OBD_NUMDEN_MAX_VALUE)
        {
            DEM_OBD_RATIO_GENDEN_CNT = DEM_DATA_CLEAR;
        }
    }

    if(DEM_CFG_OPCYC_TYPE(OperationCycleId) == DEM_OPCYC_OBD_DCY)
    {
        /*Reset status enabled all readiness group*/
        DEM_OBD_READINESSGROUP_STATUS[0] = (uint8)0x03;
        DEM_OBD_READINESSGROUP_STATUS[0] = (uint8)0xFF;

        for(RatioID = 0; RatioID < DEM_NUM_OF_RATIO; RatioID++)
        {
            /*Clear the Denominator increased flag*/
            DEM_OBD_RATIO_STATE(RatioID) &= (~DEM_OBD_DEN_INCREASED_MASK);
            /*Clear the Numerator increased flag*/
            DEM_OBD_RATIO_STATE(RatioID) &= (~DEM_OBD_NUM_INCREASED_MASK);
        }
        /*Reset additional IUMPR denominator condition state.*/
        DEM_OBD_RATIO_DENOMCOND_STATUS(DEM_IUMPR_DEN_COND_COLDSTART) = DEM_IUMPR_DEN_STATUS_NOT_REACHED;
        DEM_OBD_RATIO_DENOMCOND_STATUS(DEM_IUMPR_DEN_COND_EVAP) = DEM_IUMPR_DEN_STATUS_NOT_REACHED;
        DEM_OBD_RATIO_DENOMCOND_STATUS(DEM_IUMPR_DEN_COND_500MI) = DEM_IUMPR_DEN_STATUS_NOT_REACHED;
    }
#endif/*#if(DEM_NUM_OF_RATIO > 0)*/
#endif/*#if((DEM_CFG_OBD_SUPPORT == DEM_OBD_MASTER_ECU)||(DEM_CFG_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU))*/
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name:
*
* Description:
*
* Inputs:
*
* Outputs:
*
* Return:
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, DEM_CODE) DemInternal_CycleEndProcess
(
    uint8 OperationCycleId
)
{
    uint16 EventId;
    uint16 DtcId;
    Dem_UdsStatusByteType DtcOldStatus;
    Dem_UdsStatusByteType DtcNewStatus;
    Dem_UdsStatusByteType EventCurStatus;

    for(EventId = 0; EventId < DEM_NUM_OF_EVENT; EventId++)
    {
        if(OperationCycleId == DEM_CFG_EVENT_OPCYCREF(EventId))
        {
            EventCurStatus = DEM_DTC_STATUS(DEM_CFG_EVENT_DTCREF(EventId));
            /*The counter shall be started*/
            if((DEM_DTC_DATAENTRYREF(DEM_CFG_EVENT_DTCREF(EventId)) != DEM_DATA_INVALID_U16) \
                    && (DEM_TEST_UDS_STATUS_TFSLC(EventCurStatus)))
            {
                /*SWS_Dem_00773*//*SWS_Dem_00774*/
                if(DEM_EVENT_CSLF(EventId) < DEM_DATA_U8_FF)
                {
                    DEM_EVENT_CSLF(EventId)++;
                }
                /*SWS_Dem_00777*//*SWS_Dem_00778*/
                if(DEM_EVENT_CSFF(EventId) < DEM_DATA_U8_FF)
                {
                    DEM_EVENT_CSFF(EventId)++;
                }
#if(STD_OFF == DEM_CMA_PLATFORM_ENABLED)
                /*SWS_Dem_00781*//*SWS_Dem_00782*/
                if((DEM_TEST_UDS_STATUS_TFTOC(EventCurStatus)) \
                    && (DEM_EVENT_FCSLC(EventId) < DEM_DATA_U8_FF))
                {
                    DEM_EVENT_FCSLC(EventId)++;
                }
#endif
            }

#if((DEM_CFG_OBD_SUPPORT == DEM_OBD_MASTER_ECU)||(DEM_CFG_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU))
            if((DEM_TEST_UDS_STATUS_TFSLC(EventCurStatus)) \
                && (!DEM_TEST_UDS_STATUS_TFTOC(EventCurStatus)) \
                && (!DEM_TEST_UDS_STATUS_TNCTOC(EventCurStatus)) \
                && (DEM_EVENT_OBD_PCSLF(EventId) < DEM_OBD_PCSLF_MAXVALUE))
            {
                DEM_EVENT_OBD_PCSLF(EventId)++;
            }
#endif
            /*Capture data before operation cycle end*/
            if(TRUE == DemInternal_GetCaptureQueue(EventId, NULL_PTR))
            {
                DemInternal_CaptureData(EventId);
            }
        }

        /*Aging process*/
        /*SWS_Dem_00985*/
        /*SWS_Dem_00489: The Dem module shall only allow processing
        (counting further)the value of the aging counter, if the related
        event is stored in the event memory and is qualified as passed.
        Note: Aging is independent of the UDS status bit 3 (ConfirmedDTC)
        and therefore independent of the fault confirmation.*/
        DtcId = DEM_CFG_EVENT_DTCREF(EventId);
        DtcOldStatus = DEM_DTC_STATUS(DtcId);
        DtcNewStatus = DEM_DTC_STATUS(DtcId);

        /*if(OperationCycleId == DEM_CFG_DTC_AGINGCYCREF(DtcId))*/
        if(OperationCycleId == DEM_CFG_EVENT_OPCYCREF(EventId))
        {
#if(DEM_NUM_OF_INDICATOR > 0)
            DemInternal_IndicatorOffCriteriaFulfilled(EventId, DEM_CYCLE_END, DtcOldStatus, &DtcNewStatus);
#endif
#if(DEM_CFG_MAXNUMBEREVENTENTRY_PERMANENT > 0)
            if((!DEM_TEST_UDS_STATUS_TFTOC(DtcOldStatus)) \
                && (!DEM_TEST_UDS_STATUS_TNCTOC(DtcOldStatus)))
            {
                DemInternal_RemoveEventPermanentEntry(EventId);
            }
#endif

#if(DEM_CFG_AGINGREQUIRESTESTEDCYCLE == STD_ON)
            if((!DEM_TEST_UDS_STATUS_TFTOC(DtcOldStatus)) \
                && (!DEM_TEST_UDS_STATUS_TNCTOC(DtcOldStatus)))
#else
            if(!DEM_TEST_UDS_STATUS_TFTOC(DtcOldStatus))
#endif
            {
                /*BIT2_Pending_DTC*//*SWS_Dem_00390*//*SWS_Dem_01183*/
                if(DEM_TEST_UDS_STATUS_PDTC(DtcOldStatus))
                {
                    DtcNewStatus = DEM_CLEAR_UDS_STATUS_PDTC(DtcOldStatus);
#if(STD_OFF == DEM_CMA_PLATFORM_ENABLED)
                    DEM_EVENT_FCC(EventId) = DEM_DATA_CLEAR;
#endif
                }
#if((DEM_CFG_OBD_SUPPORT == DEM_OBD_MASTER_ECU)||(DEM_CFG_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU))
                if(!DEM_TEST_UDS_STATUS_CDTC(DtcOldStatus))
                {
                    DemInternal_ClearOBDFreezeFrame(EventId);
                }
#endif
            }
        }

        if((DEM_DTC_DATAENTRYREF(DtcId) != DEM_DATA_INVALID_U16) \
            && (OperationCycleId == DEM_CFG_DTC_AGINGCYCREF(DtcId)) \
            && (DEM_CFG_DTC_AGING_ALLOWED(DtcId) == TRUE))
        {
            /*SWS_Dem_00490*//*SWS_Dem_00826*/
#if(DEM_CFG_AGINGREQUIRESTESTEDCYCLE == STD_ON)
            if((!DEM_TEST_UDS_STATUS_TFTOC(DtcOldStatus)) \
                && (!DEM_TEST_UDS_STATUS_TNCTOC(DtcOldStatus)))
#else
            if(!DEM_TEST_UDS_STATUS_TFTOC(DtcOldStatus))
#endif
            {
                /*SWS_Dem_01184*/
                DEM_DTC_AGINGCNT(DtcId)++;
            }
            /*else
            {
                DEM_DTC_AGINGCNT(DtcId) = 0;
            }*/

            if(DEM_DTC_AGINGCNT(DtcId) >= DEM_CFG_AGINGCYCLECOUNTERTHRESHOLD(DtcId))
            {
                /*Clear event info*/
                DemInternal_ClearOneEvent(EventId, TRUE);
                /*Clear DTC info*/
                /*SWS_Dem_00391*//*SWS_Dem_00498*/
                DtcNewStatus = DEM_CLEAR_UDS_STATUS_CDTC(DtcNewStatus);
#if(DEM_CFG_STATUSBITHANDLING_TFSLC == DEM_STATUS_BIT_AGING_AND_DISPLACEMENT)
                /*SWS_Dem_00393*//*SWS_Dem_01054*/
                DtcNewStatus = DEM_CLEAR_UDS_STATUS_TFSLC(DtcNewStatus);
#endif
                DEM_DTC_AGINGCNT(DtcId) = DEM_DATA_CLEAR;
                if(DEM_DTC_AGEDCNT(DtcId) < DEM_DATA_U8_FF)
                {
                    DEM_DTC_AGEDCNT(DtcId)++;
                }
                /*SWS_Dem_01075*/
                DEM_PRIMARY_DATAENTRY_USEDNUM--;
                DemInternal_ClearOneMemoryEntry((DEM_DTC_DATAENTRYREF(DtcId)));
                DEM_PRIMARY_DATAENTRY_USED(DEM_DTC_DATAENTRYREF(DtcId)) = FALSE;
                DEM_DTC_DATAENTRYREF(DtcId) = DEM_DATA_INVALID_U16;

#if((DEM_CFG_OBD_SUPPORT == DEM_OBD_MASTER_ECU)||(DEM_CFG_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU))
                /*SWS_Dem_01174*/
                DemInternal_ClearOBDFreezeFrame(EventId);
#endif
            }

            if(DtcNewStatus != DtcOldStatus)
            {
                /*SWS_Dem_00284*/
                (void)DEM_CFG_DTC_STATUSCHANGED_CALLFNC(DEM_CFG_DTC_VALUE(DtcId), DtcOldStatus, DtcNewStatus);
                if(NULL_PTR != DEM_CFG_EVENT_STATUSCHANGED_CALLFNC(EventId))
                {
                    /*SWS_Dem_00016*/
                    (void)DEM_CFG_EVENT_STATUSCHANGED_CALLFNC(EventId)(DtcOldStatus, DtcNewStatus);
                }
#if(DEM_CFG_TRIGGER_FIM_REPORTS == STD_ON)
                FiM_DemTriggerOnEventStatus(EventId, DtcOldStatus, DtcNewStatus);
#endif
            }
        }
        else
        {
            /*do nothing*/
        }
        /*save the current and last operation cycle DTC status*/
        DEM_DTC_LASTSTATUS(DtcId) = DtcOldStatus;
        DEM_DTC_STATUS(DtcId) = DtcNewStatus;
    }
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name:
*
* Description:
*
* Inputs:
*
* Outputs:
*
* Return:
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, DEM_CODE) DemInternal_MainFnc_OperationCycle
(
    void
)
{
    uint8 i;

    for(i = 0; i < DEM_NUM_OF_OPCYCLE; i++)
    {
        if((Dem_OpCycReq[i] == DEM_CYCLE_STATE_START) \
                && (Dem_OpCycState[i] == DEM_CYCLE_STATE_END))
        {
            Dem_OpCycReq[i] = DEM_DATA_CLEAR;
            Dem_OpCycState[i] = DEM_CYCLE_STATE_START;
            DemInternal_CycleStartProcess(i);
        }
        else if((Dem_OpCycReq[i] == DEM_CYCLE_STATE_END) \
                && (Dem_OpCycState[i] == DEM_CYCLE_STATE_START))
        {
            Dem_OpCycReq[i] = DEM_DATA_CLEAR;
            Dem_OpCycState[i] = DEM_CYCLE_STATE_END;
            DemInternal_CycleEndProcess(i);
        }
        else if((Dem_OpCycReq[i] == DEM_CYCLE_STATE_START) \
                && (Dem_OpCycState[i] == DEM_CYCLE_STATE_START))
        {
            /*SWS_Dem_00483*/
            Dem_OpCycReq[i] = DEM_DATA_CLEAR;
            Dem_OpCycState[i] = DEM_CYCLE_STATE_START;
            DemInternal_CycleEndProcess(i);
            DemInternal_CycleStartProcess(i);
        }
        else
        {
            /*SWS_Dem_00484*/
        }
    }
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name:
*
* Description:
*
* Inputs:
*
* Outputs:
*
* Return:
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, DEM_CODE) DemInternal_MainFnc_BswErrorHandle
(
    void
)
{
    uint8 i;
#if(DEM_CFG_BSWERRORBUFFERSIZE > 0)
    for(i = 0; i < DEM_CFG_BSWERRORBUFFERSIZE; i++)
    {
        if(Dem_BswErrorQueue[i] != DEM_DATA_INVALID_U16)
        {
            DemInternal_SetEventStatus(Dem_BswErrorQueue[i], Dem_BswErrorStatus[i]);
            Dem_BswErrorQueue[i] = DEM_DATA_INVALID_U16;
        }
    }
#endif
}

#if(DEM_CFG_DEBOUNCETIMEBASEDSUPPORT == STD_ON)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name:
*
* Description:
*
* Inputs:
*
* Outputs:
*
* Return:
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, DEM_CODE) DemInternal_MainFnc_DebounceTimer
(
    void
)
{
    Dem_EventIdType EventId;
    uint8 i;
#if(DEM_NUM_OF_EN_GROUP > 0)
    boolean DbtStopFlag;
#endif

    for(EventId = 0; EventId < DEM_NUM_OF_EVENT; EventId++)
    {
#if(DEM_NUM_OF_EN_GROUP > 0)
        DbtStopFlag = FALSE;

        if(DEM_CFG_EVENT_EN(EventId) != NULL_PTR)
        {
            for(i = 0; i < DEM_CFG_EVENT_EN_NUM(EventId); i++)
            {
                if(Dem_EventEnCondition[(DEM_CFG_EVENT_EN_REF(EventId)[i])] != TRUE)
                {
                    DbtStopFlag = TRUE;
                    break;
                }
            }
        }
        /*SWS_Dem_00655*//*SWS_Dem_00678*/
        if((DEM_CFG_EVENT_DBT(EventId) != NULL_PTR) \
            && ((DEM_EVENT_TIMERDIRECTION(EventId) == DEM_EVENT_STATUS_PREFAILED) \
                || (DEM_EVENT_TIMERDIRECTION(EventId) == DEM_EVENT_STATUS_PREPASSED)) \
            && (Dem_EventDBTFreezeFlag[EventId] == FALSE) \
            && (Dem_EnableDtcSetting[EventId] == TRUE) \
            && (DbtStopFlag == FALSE))
#else
        if((DEM_CFG_EVENT_DBT(EventId) != NULL_PTR) \
            && ((DEM_EVENT_TIMERDIRECTION(EventId) == DEM_EVENT_STATUS_PREFAILED) \
                || (DEM_EVENT_TIMERDIRECTION(EventId) == DEM_EVENT_STATUS_PREPASSED)) \
            && (Dem_EventDBTFreezeFlag[EventId] == FALSE) \
            && (Dem_EnableDtcSetting[EventId] == TRUE))
#endif
        {
            (DEM_EVENT_DBT(EventId))++;

            if((DEM_EVENT_TIMERDIRECTION(EventId) == DEM_EVENT_STATUS_PREFAILED) \
                && (DEM_EVENT_DBT(EventId) >= DEM_CFG_EVENT_DBT_FAILED(EventId)))
            {
                DemInternal_SetEventStatus(EventId, DEM_EVENT_STATUS_FAILED);
            }
            else if((DEM_EVENT_TIMERDIRECTION(EventId) == DEM_EVENT_STATUS_PREPASSED) \
                && (DEM_EVENT_DBT(EventId) >= DEM_CFG_EVENT_DBT_PASSED(EventId)))
            {
                DemInternal_SetEventStatus(EventId, DEM_EVENT_STATUS_PASSED);
            }
            else
            {
                /*do nothing*/
            }
        }
    }
}
#endif/*#if(DEM_CFG_DEBOUNCETIMEBASEDSUPPORT == STD_ON)*/

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name:
*
* Description:
*
* Inputs:
*
* Outputs:
*
* Return:
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, DEM_CODE) DemInternal_MainFnc_CaptureData
(
    void
)
{
    uint16 EventId;
    uint16 i = 0;

    for(EventId = Dem_CapturePosition; EventId < DEM_NUM_OF_DTC; EventId++)
    {
        if(DemInternal_GetCaptureQueue(EventId, NULL_PTR) == TRUE)
        {
            i++;

            SchM_Enter_Dem_DEM_EXCLUSIVE_AREA_0();
            DemInternal_CaptureData(EventId);
            SchM_Exit_Dem_DEM_EXCLUSIVE_AREA_0();
        }

        if(EventId >= (DEM_NUM_OF_EVENT - 1))
        {
            /*the last DTC*/
            Dem_CapturePosition = 0;
            break;
        }
        else if(i >= DEM_MAXNUM_CAPTURE_DATA_PER_MAINCYCLE)
        {
            /*MaxNumOfCaptureDataForDtcPerMainCycle is reached*/
            Dem_CapturePosition += DEM_MAXNUM_CAPTURE_DATA_PER_MAINCYCLE;
            break;
        }
        else
        {
            /*continue capture data*/
        }
    }
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DemInternal_MainFnc_ClearDTC
*
* Description: Clear the group DTC or Write the RAM info which has been cleared
*              in nonvalatile memory.
*
* Inputs: None
*
* Outputs: None
*
* Return: None
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, DEM_CODE) DemInternal_MainFnc_ClearDTC
(
    void
)
{

#if(DEM_CFG_CLEARDTCBEHAIOR != DEM_CLRRESP_VOLATILE)    
    NvM_RequestResultType ret = NVM_REQ_OK;
#endif

    if(Dem_ClearDTCState == DEM_IN_CLEAR_DTC_GROUP)
    {
        DemInternal_ClearOneDTCGroup();
    }
#if(DEM_CFG_CLEARDTCBEHAIOR != DEM_CLRRESP_VOLATILE)
    else if(Dem_ClearDTCState == DEM_IN_CLEAR_EVENT_MEM)
    {
        if(E_OK == Dem_WriteBlock(DEM_CFG_NVM_BLOCKID, &Dem_StorageMem))
        {
            Dem_ClearDTCState = DEM_IN_CLEAR_DTC_BUSY;
            Dem_SetRamBlockStatus(DEM_CFG_NVM_BLOCKID, TRUE);
        }
        else
        {
            Dem_ClearDTCState = DEM_IN_CLEAR_DTC_ERR;
        }
    }
    else if(Dem_ClearDTCState == DEM_IN_CLEAR_DTC_BUSY)
    {
        if(E_OK == Dem_GetErrorStatus(DEM_CFG_NVM_BLOCKID, &ret))
        {
            if(ret == NVM_REQ_OK)
            {
                Dem_ClearDTCState = DEM_IN_CLEAR_DTC_OK;

            }
            else if(ret == NVM_REQ_PENDING)
            {
                /*do nothing*/
            }
            else
            {
                Dem_ClearDTCState = DEM_IN_CLEAR_DTC_ERR;
            }
        }
        else
        {
            Dem_ClearDTCState = DEM_IN_CLEAR_DTC_ERR;
        }
    }
#endif
    else
    {
        /*do nothing*/
    }
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DemInternal_ClearOneDTC
*
* Description: Clear the RAM info of one DTC
*
* Inputs: DtcId
*
* Outputs: None
*
* Return: None
*
* Limitations: Used for UDS and J1939
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, DEM_CODE) DemInternal_ClearOneDTC
(
    uint16 DtcId
)
{
    Std_ReturnType ret = E_OK;
    Dem_UdsStatusByteType OldStatus;
    Dem_UdsStatusByteType NewStatus;
    uint16 EventId;
    boolean ClearAllowed = TRUE;

    for(EventId = 0U; EventId < DEM_NUM_OF_EVENT; EventId++)
    {
#if((DEM_CONFIG_VARIANTS != STD_CONFIG_VARIANTS_POSTBUILD) && (DEM_CFG_AVAILABILITYSUPPORT == DEM_EVENT_AVAILABILITY))
        /*SWS_Dem_01108*/
        if((Dem_EventAvailable[EventId] == TRUE) && (DEM_CFG_EVENT_DTCREF(EventId) == DtcId))
#else
        if(DEM_CFG_EVENT_DTCREF(EventId) == DtcId)
#endif
        {
            break;
        }
    }/*for(EventId = 0U; EventId < DEM_NUM_OF_EVENT; EventId++)*/

    if(DEM_CFG_EVENT_CLEARALLOWED_CALLFNC(EventId) != NULL_PTR)
    {
        /*SWS_Dem_00514*//*SWS_Dem_00515*/
        ret = DEM_CFG_EVENT_CLEARALLOWED_CALLFNC(EventId)(&ClearAllowed);
    }

    OldStatus = DEM_DTC_STATUS(DtcId);
    NewStatus = DEM_DTC_STATUS(DtcId);
    /*SWS_Dem_00667*//*SWS_Dem_00516*/
    if((ClearAllowed == TRUE) || (ret == E_NOT_OK))
    {
        Dem_DTC_FirstFdcThreshold[DtcId] = FALSE;
        /*SWS_Dem_00660*/
        /*Clear event info*/
        DemInternal_ClearOneEvent(EventId, FALSE);

        /*Clear DTC info*/
        /*SWS_Dem_00385*//*SWS_Dem_00386*/
        /*SWS_Dem_00389*//*SWS_Dem_00390*/
        /*SWS_Dem_00391*//*SWS_Dem_00392*/
        /*SWS_Dem_00393*//*SWS_Dem_00395*/
        DEM_DTC_STATUS(DtcId) = DEM_STATUS_RESET;
        DEM_DTC_LASTSTATUS(DtcId) = DEM_STATUS_RESET;
        DEM_DTC_AGINGCNT(DtcId) = DEM_DATA_CLEAR;
        DEM_DTC_AGEDCNT(DtcId) = DEM_DATA_CLEAR;

        /*Clear Record data*/
        if(DEM_DTC_DATAENTRYREF(DtcId) != DEM_DATA_INVALID_U16)
        {
            /*SWS_Dem_00399*/
            DEM_PRIMARY_DATAENTRY_USEDNUM--;
            DemInternal_ClearOneMemoryEntry((DEM_DTC_DATAENTRYREF(DtcId)));
            DEM_PRIMARY_DATAENTRY_USED(DEM_DTC_DATAENTRYREF(DtcId)) = FALSE;
            DEM_DTC_DATAENTRYREF(DtcId) = DEM_DATA_INVALID_U16;
        }
    }
    else
    {
        /*SWS_Dem_00668*//*SWS_Dem_00669*/
        if(DEM_CFG_EVENT_CLEARALLOWED_BEHAVIOR(EventId) == DEM_ONLY_THIS_CYCLE_AND_READINESS)
        {
            Dem_DTC_FirstFdcThreshold[DtcId] = FALSE;
            /*bit1*/
            NewStatus = DEM_CLEAR_UDS_STATUS_TFTOC(OldStatus);
            /*bit4*/
            NewStatus = DEM_SET_UDS_STATUS_TNCSLC(OldStatus);
            /*bit5*/
            NewStatus = DEM_CLEAR_UDS_STATUS_TFSLC(OldStatus);
            /*bit6*/
            NewStatus = DEM_SET_UDS_STATUS_TNCTOC(OldStatus);
            DEM_DTC_STATUS(DtcId) = NewStatus;
            
        }
    }

    NewStatus = DEM_DTC_STATUS(DtcId);
    /*SWS_Dem_00284*/
    if(OldStatus != NewStatus)
    {
        (void)DEM_CFG_DTC_STATUSCHANGED_CALLFNC(DEM_CFG_DTC_VALUE(DtcId), OldStatus, NewStatus);
        if(NULL_PTR != DEM_CFG_EVENT_STATUSCHANGED_CALLFNC(EventId))
        {
            /*SWS_Dem_00016*/
            (void)DEM_CFG_EVENT_STATUSCHANGED_CALLFNC(EventId)(OldStatus, NewStatus);
        }
#if(DEM_CFG_TRIGGER_FIM_REPORTS == STD_ON)
        FiM_DemTriggerOnEventStatus(EventId, OldStatus, NewStatus);
#endif
    }
    /*SWS_Dem_00659*//*SWS_Dem_00680*/
    if(DEM_CFG_EVENT_INITM_CALLFNC(EventId) != NULL_PTR)
    {
        DEM_CFG_EVENT_INITM_CALLFNC(EventId)(DEM_INIT_MONITOR_CLEAR);
    }

}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DemInternal_ClearOneEvent
*
* Description: Clear data information of one event
*
* Inputs: EventId
*         Aging: TRUE-clear because of aging;
*                FALSE-Clear because of Clear Command
*
* Outputs:
*
* Return:
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, DEM_CODE) DemInternal_ClearOneEvent
(
    Dem_EventIdType EventId,
    boolean Aging
)
{
#if(DEM_NUM_OF_INDICATOR > 0)
    uint8 Index;
    uint8 IndicatorId;
    uint16 StatusPos;
#endif

    DEM_EVENT_FCC(EventId) = DEM_DATA_CLEAR;
    DEM_EVENT_OCCCTR(EventId) = DEM_DATA_CLEAR;
#if(DEM_CFG_DEBOUNCECOUNTERBASEDSUPPORT == STD_ON)
    /*SWS_Dem_00343*/
    DEM_EVENT_DBC(EventId) = 0;
#endif

#if(DEM_CFG_DEBOUNCETIMEBASEDSUPPORT == STD_ON)
    DEM_EVENT_DBT(EventId) = 0;
    DEM_EVENT_TIMERDIRECTION(EventId) = DEM_DATA_INVALID_U8;
    Dem_EventDBTFreezeFlag[EventId] = FALSE;
#endif
    DEM_EVENT_MAXFDCDCC(EventId) = 0;
    /*SWS_Dem_00794*/
    DEM_EVENT_MAXFDCSLC(EventId) = 0;
    DEM_EVENT_CSLF(EventId) = DEM_DATA_CLEAR;
    DEM_EVENT_CSFF(EventId) = DEM_DATA_CLEAR;
    DEM_EVENT_FCSLC(EventId) = DEM_DATA_CLEAR;
#if((DEM_CFG_OBD_SUPPORT == DEM_OBD_MASTER_ECU)||(DEM_CFG_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU))
    DEM_EVENT_OBD_PCSLF(EventId) = DEM_DATA_CLEAR;
#endif
#if(STD_ON == DEM_CMA_PLATFORM_ENABLED)
    DEM_EVENT_CMA_PCSLF(EventId) = DEM_DATA_CLEAR;
    DEM_EVENT_CMA_STATUS(EventId) = DEM_DATA_CLEAR;
#endif

    if(Aging == FALSE)
    {
#if(DEM_NUM_OF_INDICATOR > 0)
        if((DEM_CFG_EVENT_INDICATOR_NUM(EventId) > (uint8)0) \
            && (DEM_CFG_EVENT_INDICATOR(EventId) != NULL_PTR))
        {

            DEM_EVENT_IFCC(EventId) = DEM_DATA_CLEAR;
            DEM_EVENT_IHCC(EventId) = DEM_DATA_CLEAR;

            for(Index = 0; Index < DEM_CFG_EVENT_INDICATOR_NUM(EventId); Index++)
            {
                IndicatorId = DEM_CFG_EVENT_INDICATOR_ID(EventId,Index);
                StatusPos = DEM_CFG_EVENT_INDICATOR_OFFSET(EventId,Index) \
                                + DEM_CFG_INDICATOR_STATUS_START(IndicatorId);

                if(DEM_INDICATOR_STATUS(StatusPos) != DEM_INDICATOR_OFF)
                {
                    DEM_INDICATOR_STATUS(StatusPos) = DEM_INDICATOR_OFF;

                    if(DEM_CFG_INDICATOR_STATUS_FNC(IndicatorId) != NULL_PTR)
                    {
                        (void)DEM_CFG_INDICATOR_STATUS_FNC(IndicatorId)(EventId, DEM_INDICATOR_OFF);
                    }
                }
            }
        }/*if((DEM_CFG_EVENT_INDICATOR_NUM(EventId) > (uint8)0) \
              && (DEM_CFG_EVENT_INDICATOR(EventId) != NULL_PTR))*/
#endif/*#if(DEM_NUM_OF_INDICATOR > 0)*/

#if((DEM_CFG_OBD_SUPPORT == DEM_OBD_MASTER_ECU)||(DEM_CFG_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU))
        DemInternal_ClearOBDFreezeFrame(EventId);
#endif

#if(DEM_CFG_MAXNUMBEREVENTENTRY_PERMANENT > 0)
        DEM_EVENT_OBD_CLEAR_FLAG(EventId) = TRUE;
#endif
    }/*if(Aging == FALSE)*/
    else
    {
#if(STD_ON == DEM_CMA_PLATFORM_ENABLED)
        DEM_EVENT_CMA_STATUS(EventId) = DEM_SET_CMA_STATUS_ADTC(DEM_EVENT_CMA_STATUS(EventId));
#endif
    }
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name:
*
* Description:
*
* Inputs:
*
* Outputs:
*
* Return:
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, DEM_CODE) DemInternal_ClearOneDTCGroup
(
    void
)
{
    uint16 DtcIndex;
    uint16 MaxIndexCurrentCycle;

    if(DEM_NUM_OF_DTC <= DEM_CLEAR_NUM_PER_CYCLE)
    {
        MaxIndexCurrentCycle = DEM_NUM_OF_DTC;
    }
    else
    {
        if((DEM_NUM_OF_DTC - DEM_CLEAR_NUM_PER_CYCLE) > Dem_ClearDTC_Index)
        {
            MaxIndexCurrentCycle = (Dem_ClearDTC_Index + DEM_CLEAR_NUM_PER_CYCLE);
        }
        else
        {
            MaxIndexCurrentCycle = DEM_NUM_OF_DTC;
        }
    }

    switch(Dem_ClearDTC_DTC)
    {
        case DEM_DTC_GROUP_ALL:
        case DEM_DTC_GROUP_CHASSIS:
        case DEM_DTC_GROUP_BODY:
        case DEM_DTC_GROUP_POWERTRAIN:
        case DEM_DTC_GROUP_NETWORK_COM:
            for(DtcIndex = Dem_ClearDTC_Index; DtcIndex < MaxIndexCurrentCycle; DtcIndex++)
            {
                if(DEM_DTC_GROUP_ALL == Dem_ClearDTC_DTC)
                {
                    DemInternal_ClearOneDTC(DtcIndex);
                }
                else if((DEM_DTC_GROUP_CHASSIS == Dem_ClearDTC_DTC) && (DEM_DTC_CHASSIS_RANGE_LOW <= DEM_CFG_DTC_VALUE(DtcIndex)) \
                    && (DEM_DTC_CHASSIS_RANGE_HIGH >= DEM_CFG_DTC_VALUE(DtcIndex)))
                {
                    DemInternal_ClearOneDTC(DtcIndex);
                }
                else if((DEM_DTC_GROUP_BODY == Dem_ClearDTC_DTC) && (DEM_DTC_BODY_RANGE_LOW <= DEM_CFG_DTC_VALUE(DtcIndex)) \
                    && (DEM_DTC_BODY_RANGE_HIGH >= DEM_CFG_DTC_VALUE(DtcIndex)))
                {
                    DemInternal_ClearOneDTC(DtcIndex);
                }
                else if((DEM_DTC_GROUP_POWERTRAIN == Dem_ClearDTC_DTC) && (DEM_DTC_POWER_RANGE_LOW <= DEM_CFG_DTC_VALUE(DtcIndex)) \
                    && (DEM_DTC_POWER_RANGE_HIGH >= DEM_CFG_DTC_VALUE(DtcIndex)))
                {
                    DemInternal_ClearOneDTC(DtcIndex);
                }
                else if((DEM_DTC_GROUP_NETWORK_COM == Dem_ClearDTC_DTC) && (DEM_DTC_COM_RANGE_LOW <= DEM_CFG_DTC_VALUE(DtcIndex)) \
                    && (DEM_DTC_COM_RANGE_HIGH >= DEM_CFG_DTC_VALUE(DtcIndex)))
                {
                    DemInternal_ClearOneDTC(DtcIndex);
                }
                else
                {
                    /*Continue*/
                }
            }

            if(MaxIndexCurrentCycle == DEM_NUM_OF_DTC)
            {
#if(DEM_CFG_CLEARDTCBEHAIOR == DEM_CLRRESP_VOLATILE)
                Dem_ClearDTCState = DEM_IN_CLEAR_DTC_OK;
#else
                Dem_ClearDTCState = DEM_IN_CLEAR_EVENT_MEM;
#endif
            }
            /*Update the start index value for the next cycle to clear DTC.*/
            Dem_ClearDTC_Index = MaxIndexCurrentCycle; 
        break;

        case DEM_DTC_GROUP_EMISSION:
        case DEM_DTC_GROUP_SAFETY:
        case DEM_DTC_GROUP_VOBD:

        default:
            Dem_ClearDTCState = DEM_IN_CLEAR_DTC_ERR;
        break;
    }
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name:
*
* Description:
*
* Inputs:
*
* Outputs:
*
* Return:
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(Std_ReturnType, DEM_CODE) DemInternal_GetEventFreezeFrameDataEx
(
    Dem_EventIdType EventId,
    uint8 RecordNumber,
    uint16 DataId,
    uint8 *DestBuffer,
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) BufSize
)
{
    Std_ReturnType Result = E_OK;
#if(DEM_MAX_FFSIZE_OF_DTC > 0)
    uint16 DtcId;
    uint16 MemEntryId;
    uint8 *SrcDataPtr;
    uint8 i;
    uint8 j;
    uint8 k;
    uint8 RecIdx;
    uint8 DidIdx;
    uint8 DataIdx;
#endif
    uint16 DataSize = 0;

#if(DEM_MAX_FFSIZE_OF_DTC > 0)
#if(DEM_NUM_OF_FFRECCLASS > 0)

    DtcId = DEM_CFG_EVENT_DTCREF(EventId);

    if(DEM_CFG_DTC_FFRECNUMCLASSREF(DtcId) != NULL_PTR)
    {
        MemEntryId = DEM_DTC_DATAENTRYREF(DtcId);
        SrcDataPtr = DEM_PRIMARY_FFDATA_PTR(MemEntryId);

        for(i = 0; i < DEM_CFG_DTC_NUM_OF_FFREC(DtcId); i++)
        {
            RecIdx = (DEM_CFG_DTC_FFREC_ARRAY(DtcId)[i]);

            if(SrcDataPtr[0] == RecordNumber)
            {
                /*+ RecNum length(one byte) + RecordNumberOfIdentifiers length(one byte)*/
                SrcDataPtr += 2;

                for(j = 0; j < DEM_CFG_NUMDID_OF_FFRECNUM(RecIdx); j++)
                {
                    /*Did length(two bytes)*/
                    SrcDataPtr += 2;

                    DidIdx = (DEM_CFG_DIDARRAY_OF_FFRECNUM(RecIdx)[j]);
                    if(DataId == DEM_CFG_DID(DidIdx))
                    {
                        for(k = 0; k < DEM_CFG_NUMDATA_OF_DID(DidIdx); k++)
                        {
                            DataIdx = (DEM_CFG_DATAARRAY_OF_DID(DidIdx)[k]);
                            if(DEM_CFG_DATA_IN_DATA(DataIdx) != NULL_PTR)
                            {
                                /*SWS_Dem_00817*/
                                *SrcDataPtr = DemInternal_GetDtcInternalData(DtcId, DataIdx);
                                DataSize += DEM_CFG_DATA_IN_DATA_SIZE(DataIdx);
                            }

                            if(DEM_CFG_DATA_CS_DATA(DataIdx) != NULL_PTR)
                            {
                                DataSize += DEM_CFG_DATA_CS_DATA_SIZE(DataIdx);
                            }
                        }
                        /*SWS_Dem_00991*/
                        if(*BufSize >= DataSize)
                        {
                            Bsw_MemCpy(DestBuffer, SrcDataPtr, DataSize);
                            *BufSize = DataSize;
                        }
                        else
                        {
                            Result = E_NOT_OK;
                        }
                        break;
                    }
                    else
                    {
                        for(k = 0; k < DEM_CFG_NUMDATA_OF_DID(DidIdx); k++)
                        {
                            DataIdx = (DEM_CFG_DATAARRAY_OF_DID(DidIdx)[k]);
                            if(DEM_CFG_DATA_IN_DATA(DataIdx) != NULL_PTR)
                            {
                                /*SWS_Dem_00817*/
                                *SrcDataPtr = DemInternal_GetDtcInternalData(DtcId, DataIdx);
                                SrcDataPtr += DEM_CFG_DATA_IN_DATA_SIZE(DataIdx);
                            }

                            if(DEM_CFG_DATA_CS_DATA(DataIdx) != NULL_PTR)
                            {
                                SrcDataPtr += DEM_CFG_DATA_CS_DATA_SIZE(DataIdx);
                            }
                        }
                    }
                }
                break;
            }
            else
            {
                /*+ RecNum length(one byte) + RecordNumberOfIdentifiers length(one byte)*/
                SrcDataPtr += 2;

                for(j = 0; j < DEM_CFG_NUMDID_OF_FFRECNUM(RecIdx); j++)
                {
                    /*Did length(two bytes)*/
                    SrcDataPtr += 2;

                    DidIdx = (DEM_CFG_DIDARRAY_OF_FFRECNUM(RecIdx)[j]);
                    for(k = 0; k < DEM_CFG_NUMDATA_OF_DID(DidIdx); k++)
                    {
                        DataIdx = (DEM_CFG_DATAARRAY_OF_DID(DidIdx)[k]);
                        if(DEM_CFG_DATA_IN_DATA(DataIdx) != NULL_PTR)
                        {
                            /*SWS_Dem_00817*/
                            *SrcDataPtr = DemInternal_GetDtcInternalData(DtcId, DataIdx);
                            SrcDataPtr += DEM_CFG_DATA_IN_DATA_SIZE(DataIdx);
                        }

                        if(DEM_CFG_DATA_CS_DATA(DataIdx) != NULL_PTR)
                        {
                            SrcDataPtr += DEM_CFG_DATA_CS_DATA_SIZE(DataIdx);
                        }
                    }
                }
            }
        }
    }
#endif
#endif
    if(DataSize == 0)
    {
        Result = E_NOT_OK;
    }
    return Result;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name:
*
* Description:
*
* Inputs:
*
* Outputs:
*
* Return:
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(Std_ReturnType, DEM_CODE) DemInternal_GetEventExtendedDataRecordEx
(
    Dem_EventIdType EventId,
    uint8 RecordNumber,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DestBuffer,
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) BufSize
)
{
    Std_ReturnType Result = E_OK;
#if(DEM_MAX_EXTSIZE_OF_DTC > 0)
    uint16 DtcId;
    uint16 MemEntryId;
    uint8 *SrcDataPtr;
    uint8 i;
    uint8 j;
    uint8 RecIdx;
    uint8 DataIdx;
#endif
    uint16 DataSize = 0;

#if(DEM_MAX_EXTSIZE_OF_DTC > 0)
#if(DEM_NUM_OF_EXTDATACLASS > 0)

    DtcId = DEM_CFG_EVENT_DTCREF(EventId);

    if(DEM_CFG_DTC_EXTDATACLASSREF(DtcId) != NULL_PTR)
    {
        MemEntryId = DEM_DTC_DATAENTRYREF(DtcId);
        SrcDataPtr = DEM_PRIMARY_EXTDATA_PTR(MemEntryId);

        for(i = 0; i < DEM_CFG_DTC_NUM_OF_EXTREC(DtcId); i++)
        {
            RecIdx = (DEM_CFG_DTC_EXTREC_ARRAY(DtcId)[i]);

            if(SrcDataPtr[0] == RecordNumber)
            {
                /*+ DataRecNum length(one byte)*/
                SrcDataPtr += 1;

                for(j = 0; j < DEM_CFG_NUMDATA_OF_EXTRECNUM(RecIdx); j++)
                {
                    DataIdx = (DEM_CFG_DATAARRAY_OF_EXTRECNUM(RecIdx)[j]);
                    if(DEM_CFG_DATA_IN_DATA(DataIdx) != NULL_PTR)
                    {
                        /*SWS_Dem_00817*/
                        *SrcDataPtr = DemInternal_GetDtcInternalData(DtcId, DataIdx);
                        DataSize += DEM_CFG_DATA_IN_DATA_SIZE(DataIdx);
                    }

                    if(DEM_CFG_DATA_CS_DATA(DataIdx) != NULL_PTR)
                    {
                        DataSize += DEM_CFG_DATA_CS_DATA_SIZE(DataIdx);
                    }
                }
                /*SWS_Dem_00989*/
                if(*BufSize >= DataSize)
                {
                    Bsw_MemCpy(DestBuffer, SrcDataPtr, DataSize);
                    *BufSize = DataSize;
                }
                else
                {
                    Result = E_NOT_OK;
                }
                break;
            }
            else
            {
                /*+ DataRecNum length(one byte)*/
                SrcDataPtr += 1;

                for(j = 0; j < DEM_CFG_NUMDATA_OF_EXTRECNUM(RecIdx); j++)
                {
                    DataIdx = (DEM_CFG_DATAARRAY_OF_EXTRECNUM(RecIdx)[j]);
                    if(DEM_CFG_DATA_IN_DATA(DataIdx) != NULL_PTR)
                    {
                        /*SWS_Dem_00817*/
                        *SrcDataPtr = DemInternal_GetDtcInternalData(DtcId, DataIdx);
                        SrcDataPtr += DEM_CFG_DATA_IN_DATA_SIZE(DataIdx);
                    }

                    if(DEM_CFG_DATA_CS_DATA(DataIdx) != NULL_PTR)
                    {
                        SrcDataPtr += DEM_CFG_DATA_CS_DATA_SIZE(DataIdx);
                    }
                }
            }
        }
    }
#endif
#endif
    if(DataSize == 0)
    {
        Result = E_NOT_OK;
    }
    return Result;
}

#if(DEM_NUM_OF_INDICATOR > 0)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DemInternal_IndicatorOnCriteriaFulfilled
*
* Description:
*
* Inputs:
*
* Outputs:
*
* Return:
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, DEM_CODE) DemInternal_IndicatorOnCriteriaFulfilled
(
    Dem_EventIdType EventId,
    Dem_UdsStatusByteType EventOldStatus, 
    P2VAR(Dem_UdsStatusByteType, AUTOMATIC, DEM_APPL_DATA) EventNewStatus
)
{
    uint8 Index;
    uint8 IndicatorId;
    uint16 StatusPos;
#if(STD_ON == DEM_CMA_PLATFORM_ENABLED)
    uint8 EventCmaStatus;
#endif
    boolean SetWIRBit = FALSE;
    Dem_UdsStatusByteType NewStatus = *EventNewStatus;

    if((DEM_CFG_EVENT_INDICATOR_NUM(EventId) > (uint8)0) \
        && (DEM_CFG_EVENT_INDICATOR(EventId) != NULL_PTR) \
        && (DEM_TEST_UDS_STATUS_TFTOC(NewStatus)) \
        && (!DEM_TEST_UDS_STATUS_TFTOC(EventOldStatus)))
    {
        /*SWS_Dem_00506*/
        DEM_EVENT_IHCC(EventId) = DEM_DATA_CLEAR;

        if(DEM_EVENT_IFCC(EventId) < DEM_DATA_U8_FF)
        {
            DEM_EVENT_IFCC(EventId)++;
        }

        if(DEM_TEST_UDS_STATUS_CDTC(NewStatus))
        {
            DEM_EVENT_IFCC(EventId) = DEM_DATA_U8_FF;
        }

        for(Index = 0; Index < DEM_CFG_EVENT_INDICATOR_NUM(EventId); Index++)
        {
            IndicatorId = DEM_CFG_EVENT_INDICATOR_ID(EventId,Index);
            StatusPos = DEM_CFG_EVENT_INDICATOR_OFFSET(EventId,Index) \
                            + DEM_CFG_INDICATOR_STATUS_START(IndicatorId);

            if((DEM_INDICATOR_STATUS(StatusPos) == DEM_INDICATOR_OFF) \
                && (DEM_EVENT_IFCC(EventId) >= DEM_CFG_EVENT_INDICATOR_F_THRESHOLD(EventId,Index)))
            {
                /*SWS_Dem_00501*/
                DEM_INDICATOR_STATUS(StatusPos) = DEM_CFG_EVENT_INDICATOR_BEHAVIOUR(EventId,Index);
                SetWIRBit = TRUE;

                if(DEM_CFG_INDICATOR_STATUS_FNC(IndicatorId) != NULL_PTR)
                {
                    (void)DEM_CFG_INDICATOR_STATUS_FNC(IndicatorId)(EventId, (DEM_INDICATOR_STATUS(StatusPos)));
                }
            }
        }

        if(SetWIRBit == TRUE)
        {
#if(STD_ON == DEM_CMA_PLATFORM_ENABLED)
            EventCmaStatus = DEM_EVENT_CMA_STATUS(EventId);
            EventCmaStatus = DEM_SET_CMA_STATUS_WIRSLC(EventCmaStatus);
            DEM_EVENT_CMA_STATUS(EventId) = EventCmaStatus;
#endif
            /*SWS_Dem_00566*/
            NewStatus = DEM_SET_UDS_STATUS_WIR(NewStatus);
            *EventNewStatus = NewStatus;
        }
    }
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DemInternal_IndicatorOffCriteriaFulfilled
*
* Description:
*
* Inputs:
*
* Outputs:
*
* Return:
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, DEM_CODE) DemInternal_IndicatorOffCriteriaFulfilled
(
    Dem_EventIdType EventId,
    Dem_IndicatorOffType OffReason,
    Dem_UdsStatusByteType EventOldStatus,
    P2VAR(Dem_UdsStatusByteType, AUTOMATIC, DEM_APPL_DATA) EventNewStatus
)
{
    uint8 Index;
    uint8 IndicatorId;
    uint16 StatusPos;
    boolean ClearWIRBit = TRUE;
    Dem_UdsStatusByteType NewStatus = *EventNewStatus;

    if((DEM_CFG_EVENT_INDICATOR_NUM(EventId) > (uint8)0) \
        && (DEM_CFG_EVENT_INDICATOR(EventId) != NULL_PTR))
    {
        if((OffReason == DEM_CYCLE_END) \
            && (!DEM_TEST_UDS_STATUS_TNCTOC(EventOldStatus)) \
            && (!DEM_TEST_UDS_STATUS_TFTOC(EventOldStatus)))
        {
            /*SWS_Dem_00506*/
            DEM_EVENT_IFCC(EventId) = DEM_DATA_CLEAR;

            if((DEM_TEST_UDS_STATUS_WIR(EventOldStatus)) \
                && (DEM_EVENT_IHCC(EventId) < DEM_DATA_U8_FF))
            {
                DEM_EVENT_IHCC(EventId)++;
            }
        }

        for(Index = 0; Index < DEM_CFG_EVENT_INDICATOR_NUM(EventId); Index++)
        {
            IndicatorId = DEM_CFG_EVENT_INDICATOR_ID(EventId,Index);
            StatusPos = DEM_CFG_EVENT_INDICATOR_OFFSET(EventId,Index) \
                            + DEM_CFG_INDICATOR_STATUS_START(IndicatorId);

            if((DEM_INDICATOR_STATUS(StatusPos) != DEM_INDICATOR_OFF) \
                && (DEM_EVENT_IHCC(EventId) >= DEM_CFG_EVENT_INDICATOR_H_THRESHOLD(EventId,Index)))
            {
                /*SWS_Dem_00503*/
                DEM_INDICATOR_STATUS(StatusPos) = DEM_INDICATOR_OFF;

                if(DEM_CFG_INDICATOR_STATUS_FNC(IndicatorId) != NULL_PTR)
                {
                    (void)DEM_CFG_INDICATOR_STATUS_FNC(IndicatorId)(EventId, (DEM_INDICATOR_STATUS(StatusPos)));
                }
            }

            if(DEM_INDICATOR_STATUS(StatusPos) != DEM_INDICATOR_OFF)
            {
                ClearWIRBit = FALSE;
            }
        }

        if(ClearWIRBit == TRUE)
        {
            /*SWS_Dem_00533*//*SWS_Dem_00835*/
            NewStatus = DEM_CLEAR_UDS_STATUS_WIR(NewStatus);
            *EventNewStatus = NewStatus;
        }
    }
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DemInternal_GetIndicatorStatus
*
* Description: Get the indicator status internally.
*
* Inputs: IndicatorId
*
* Outputs: IndicatorStatus
*
* Return: None
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, DEM_CODE) DemInternal_GetIndicatorStatus
(
    uint8 IndicatorId,
    P2VAR(Dem_IndicatorStatusType, AUTOMATIC, DEM_APPL_DATA) IndicatorStatus
)
{
    uint16 Index;
    uint16 StartIndex;
    uint16 EndIndex;

    *IndicatorStatus = DEM_INDICATOR_OFF;

    StartIndex = DEM_CFG_INDICATOR_STATUS_START(IndicatorId);
    EndIndex = DEM_CFG_INDICATOR_STATUS_START(IndicatorId) + DEM_CFG_INDICATOR_STATUS_NUM(IndicatorId);

    for(Index = StartIndex; Index < EndIndex; Index++)
    {
        if(*IndicatorStatus == DEM_INDICATOR_OFF)
        {
            *IndicatorStatus = DEM_INDICATOR_STATUS(Index);
        }
        else if((DEM_INDICATOR_STATUS(Index) != DEM_INDICATOR_OFF) \
            && (*IndicatorStatus != DEM_INDICATOR_STATUS(Index)))
        {
            *IndicatorStatus = DEM_INDICATOR_BLINK_CONT;
            break;
        }
        else
        {
            /*do nothing*/
        }
    }
}
#endif/*#if(DEM_NUM_OF_INDICATOR > 0)*/

#if((DEM_CFG_OBD_SUPPORT == DEM_OBD_MASTER_ECU)||(DEM_CFG_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU))
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DemInternal_InitOBDData
*
* Description: Init data value of OBD function
*
* Inputs:
*
* Outputs:
*
* Return:
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, DEM_CODE) DemInternal_InitOBDData
(
    void
)
{
    uint16 i;

    /*Used for PID01/41*/
    DEM_OBD_READINESSGROUP_STATUS[0] = (uint8)0x03;
    DEM_OBD_READINESSGROUP_STATUS[0] = (uint8)0xFF;
    /*Used for PID31.Unit:m, Range:0-65535000*/
    DEM_OBD_DISTANCE_SINCEDTCCLEARED = DEM_DATA_CLEAR;
    /*Data for Service 02*/
    DEM_OBD_FF_EVENT = DEM_EVENT_ID_INVALID;
    for(i = 0; i < DEM_CFG_OBD_FF_LENGTH; i++)
    {
        DEM_OBD_FF_DATA_BUF[i] = DEM_DATA_INVALID_U8;
    }
    /*Data for Service 09*/
#if(DEM_NUM_OF_RATIO > 0)
    DEM_OBD_RATIO_IGN_CNT = DEM_DATA_CLEAR;
    DEM_OBD_RATIO_GENDEN_CNT = DEM_DATA_CLEAR;
    DEM_OBD_RATIO_GENDEN_STATE = DEM_DATA_CLEAR;
    DEM_OBD_RATIO_DENOMCOND_STATUS(DEM_IUMPR_DEN_GENERAL) = DEM_IUMPR_DEN_STATUS_NOT_REACHED;
    DEM_OBD_RATIO_DENOMCOND_STATUS(DEM_IUMPR_DEN_COLDSTART) = DEM_IUMPR_DEN_STATUS_NOT_REACHED;
    DEM_OBD_RATIO_DENOMCOND_STATUS(DEM_IUMPR_DEN_EVAP) = DEM_IUMPR_DEN_STATUS_NOT_REACHED;
    DEM_OBD_RATIO_DENOMCOND_STATUS(DEM_IUMPR_DEN_500MILL) = DEM_IUMPR_DEN_STATUS_NOT_REACHED;
    for(i = 0; i < DEM_NUM_OF_RATIO; i++)
    {
        DEM_OBD_RATIO_NUMERATOR(i) = DEM_DATA_CLEAR;
        DEM_OBD_RATIO_DENOMINATOR(i) = DEM_DATA_CLEAR;
        DEM_OBD_RATIO_STATE(i) = DEM_DATA_CLEAR;
    }
#endif

#if(DEM_CFG_MAXNUMBEREVENTENTRY_PERMANENT > 0)
    DEM_OBD_PFC_CYCLE_STATUS = FALSE;
#endif
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DemInternal_StoreOBDFreezeFrame
*
* Description: EventId, EventOldStatus, EventNewStatus
*
* Inputs:
*
* Outputs:
*
* Return:
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, DEM_CODE) DemInternal_StoreOBDFreezeFrame
(
    Dem_EventIdType EventId,
    Dem_UdsStatusByteType EventOldStatus,
    Dem_UdsStatusByteType EventNewStatus
)
{
    uint8 PidIndex;
    uint8 DataIndex;/*Data index in PID*/
    uint8 i;
    uint16 DataEleIndex;/*Data index in DemDataElementClass*/
    Dem_PriorityType StoredEventPriority;
    Dem_PriorityType StoringEventPriority;
    uint8 *DataPtr;
    boolean UpdateFlag = FALSE;
    Std_ReturnType Result = E_OK;

    if(DEM_CFG_DTC_OBDDTCREF(DEM_CFG_EVENT_DTCREF(EventId)) != NULL_PTR)
    {
        if(DEM_OBD_FF_EVENT == DEM_EVENT_ID_INVALID)
        {
            /*The OBD freeze frame buffer is empty.*/
            UpdateFlag = TRUE;
        }
        else if(DEM_OBD_FF_EVENT == EventId)
        {
            if((DEM_TEST_UDS_STATUS_CDTC(EventNewStatus)) && (!DEM_TEST_UDS_STATUS_CDTC(EventOldStatus)))
            {
                /*The OBD freeze frame buffer needs update.*/
                UpdateFlag = TRUE;
            }
        }
        else
        {
            /*The OBD freeze frame buffer is full.*/
            StoredEventPriority = DEM_CFG_DTC_PRIORITY(DEM_CFG_EVENT_DTCREF(DEM_OBD_FF_EVENT));
            StoringEventPriority = DEM_CFG_DTC_PRIORITY(DEM_CFG_EVENT_DTCREF(EventId));

            if(StoringEventPriority < StoredEventPriority)
            {
                /*The priority of new event is higher than stored event.*/
                UpdateFlag = TRUE;
            }
        }
    }

    if(UpdateFlag == TRUE)
    {
        /*Update the OBD freeze frame buffer.*/
        DEM_OBD_FF_EVENT = EventId;
        DataPtr = DEM_OBD_FF_DATA_BUF;
#if(DEM_CFG_OBD_NUM_OF_PID > 0)
        for(PidIndex = 0; PidIndex < DEM_CFG_OBD_NUM_OF_PID; PidIndex++)
        {
            *DataPtr = DEM_CFG_PID_ID(PidIndex);
            DataPtr++;

            for(DataIndex = 0; DataIndex < DEM_CFG_PID_NUM_OF_DATA(PidIndex); DataIndex++)
            {
                DataEleIndex = DEM_CFG_PID_DATA_CLASS(PidIndex)[DataIndex];

                Result = DEM_CFG_DATA_CS_DATA_READ_FNC(DataEleIndex)(DataPtr);

                if(Result != E_OK)
                {
                    for(i = 0; i < DEM_CFG_DATA_CS_DATA_SIZE(DataEleIndex); i++)
                    {
                        DataPtr[i] = DEM_DATA_INVALID_U8;
                    }
                }

                DataPtr += DEM_CFG_DATA_CS_DATA_SIZE(DataEleIndex);

            }/*for(DataIndex = 0; DataIndex < DEM_CFG_PID_NUM_OF_DATA(PidIndex); DataIndex++)*/
        }/*for(PidIndex = 0; PidIndex < DEM_CFG_OBD_NUM_OF_PID; PidIndex++)*/
#endif
    }/*if(UpdateFlag == TRUE)*/
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DemInternal_ClearOBDFreezeFrame
*
* Description: Clear the OBD Freeze Frame 0x00 when Event aged.
*
* Inputs: EventId
*
* Outputs:
*
* Return:
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, DEM_CODE) DemInternal_ClearOBDFreezeFrame
(
    Dem_EventIdType EventId
)
{
    uint16 i;

    if(DEM_OBD_FF_EVENT == EventId)
    {
        DEM_OBD_FF_EVENT = DEM_EVENT_ID_INVALID;

        for(i = 0; i < DEM_CFG_OBD_FF_LENGTH; i++)
        {
            DEM_OBD_FF_DATA_BUF[i] = DEM_DATA_INVALID_U8;
        }
    }
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DemInternal_MainFnc_OBD
*
* Description: Main function to process task relevant OBD.
*
* Inputs:
*
* Outputs:
*
* Return:
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, DEM_CODE) DemInternal_MainFnc_OBD
(
    void
)
{
    /*SWS_Dem_00703*/
#if((DEM_CFG_OBD_SUPPORT == DEM_OBD_MASTER_ECU) && (DEM_CFG_OBD_CENTRALIZED_PID31_HANDLING == STD_ON))
    Dem_ObdTimesOneSecond++;
    /*1 second = 1000 millisecond*/
    if(Dem_ObdTimesOneSecond >= (uint16)(1000/DEM_TASK_TIME))
    {
        Dem_ObdTimesOneSecond = DEM_DATA_CLEAR;
        DemInternal_CalPID31Data();
    }
#endif
}

#if((DEM_CFG_OBD_SUPPORT == DEM_OBD_MASTER_ECU) && (DEM_CFG_OBD_CENTRALIZED_PID31_HANDLING == STD_ON))
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DemInternal_CalPID31Data
*
* Description: Calculate data value of PID31.
*
* Inputs:
*
* Outputs:
*
* Return:
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, DEM_CODE) DemInternal_CalPID31Data
(
    void
)
{
    uint8 TimeBuf[2];
    uint16 TimeSinceEngineStart;/*Unit:s*/
    uint8 VehicleSpeed;/*Unit: km/h*/
    uint16 TimeDelta = 0;/*Unit:s*/
    Dem_DataElementReadFncType GetTimeFnc = NULL_PTR;
    Dem_DataElementReadFncType GetSpeedFnc = NULL_PTR;

    if((DEM_CFG_OBD_TIME_SINCE_ENGINE_START != NULL_PTR) \
        && (DEM_CFG_OBD_IN_VEHICLE_SPEED != NULL_PTR))
    {
        GetTimeFnc = ((Dem_DataElementClassType *)DEM_CFG_OBD_TIME_SINCE_ENGINE_START-> \
                                                  DemExternalCSDataElementClass-> \
                                                  DemDataElementReadFnc);
        GetSpeedFnc = ((Dem_DataElementClassType *)DEM_CFG_OBD_IN_VEHICLE_SPEED-> \
                                                   DemExternalCSDataElementClass-> \
                                                   DemDataElementReadFnc);
        if((E_OK == GetTimeFnc(TimeBuf)) && (E_OK == GetSpeedFnc(&VehicleSpeed)))
        {
            TimeSinceEngineStart = (((uint16)TimeBuf[0]<<8) | ((uint16)TimeBuf[1]));

            if(TimeSinceEngineStart < Dem_ObdTimeSinceEngineStartLast)
            {
                Dem_ObdTimeSinceEngineStartLast = TimeSinceEngineStart;
                TimeDelta = TimeSinceEngineStart;
            }
            else
            {
                TimeDelta = TimeSinceEngineStart - Dem_ObdTimeSinceEngineStartLast;
                Dem_ObdTimeSinceEngineStartLast = TimeSinceEngineStart;
            }
            /*y km/h = y*1000/3600 m/s*/
            DEM_OBD_DISTANCE_SINCEDTCCLEARED += ((((uint32)VehicleSpeed)*1000/3600)*(uint32)TimeDelta);

            if(DEM_OBD_DISTANCE_SINCEDTCCLEARED > (uint32)65535000)
            {
                DEM_OBD_DISTANCE_SINCEDTCCLEARED = (uint32)65535000;
            }
        }
    }
}
#endif/*#if((DEM_CFG_OBD_SUPPORT == DEM_OBD_MASTER_ECU) && (DEM_CFG_OBD_CENTRALIZED_PID31_HANDLING == STD_ON))*/

#if(DEM_NUM_OF_RATIO > 0)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DemInternal_UpdateRatioNumerator
*
* Description: Only for monitors being configured with the option "observer",the
*              Dem module shall increment the numerator of the corresponding
*              monitor, if the assigned event gets tested/qualified (as passed
*              or failed).
*
* Inputs:
*
* Outputs:
*
* Return:
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, DEM_CODE) DemInternal_UpdateRatioNumerator
(
    Dem_EventIdType EventId
)
{
    Dem_RatioIdType RatioID;
    Dem_UdsStatusByteType DtcStatus;

    for(RatioID = 0; RatioID < DEM_NUM_OF_RATIO; RatioID++)
    {
        if(DEM_CFG_RATIO_EVENTREF(RatioID) == EventId)
        {
            DtcStatus = DEM_DTC_STATUS(DEM_CFG_EVENT_DTCREF(EventId));
            /*SWS_Dem_00359*//*SWS_Dem_00299*/
            if((DEM_CFG_RATIO_KIND(RatioID) == DEM_RATIO_OBSERVER) \
                && (!DEM_TEST_UDS_STATUS_TNCTOC(DtcStatus)) \
                && (!DEM_TEST_UDS_STATUS_PDTC(DtcStatus)))
            {
                /*SWS_Dem_01188*/
                if((DEM_OBD_RATIO_STATE(RatioID) & DEM_OBD_NUM_INCREASED_MASK) == 0)
                {
                    /*increase 1 to the numerator*/
                    DEM_OBD_RATIO_NUMERATOR(RatioID)++;
                    DEM_OBD_RATIO_STATE(RatioID) |= DEM_OBD_NUM_INCREASED_MASK;
                }

                if(DEM_OBD_RATIO_NUMERATOR(RatioID) >= DEM_OBD_NUMDEN_MAX_VALUE)
                {
                    DEM_OBD_RATIO_NUMERATOR(RatioID) = (DEM_OBD_RATIO_NUMERATOR(RatioID) >> 1);
                    DEM_OBD_RATIO_DENOMINATOR(RatioID) = (DEM_OBD_RATIO_DENOMINATOR(RatioID) >> 1);
                }
            }
            break;/*for(RatioID = 0; RatioID < DEM_NUM_OF_RATIO; RatioID++)*/
        }
    }
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DemInternal_UpdateRatioDenominator
*
* Description: Update the denominator of all ratio.
*
* Inputs:
*
* Outputs:
*
* Return:
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, DEM_CODE) DemInternal_UpdateRatioDenominator
(
    void
)
{
    Dem_RatioIdType RatioID;
    Dem_EventIdType EventId;
    Dem_UdsStatusByteType DtcStatus;
    Dem_IUMPRDenGroupType DenGroup = DEM_IUMPR_DEN_NONE;

    /*SWS_Dem_00712*/
    if(DEM_OBD_RATIO_DENOMCOND_STATUS(DEM_IUMPR_DEN_GENERAL) == DEM_IUMPR_DEN_STATUS_REACHED)
    {
        for(RatioID = 0; RatioID < DEM_NUM_OF_RATIO; RatioID++)
        {
            DenGroup = DEM_CFG_RATIO_IUMPR_DEN(RatioID);

            if(((DEM_OBD_RATIO_STATE(RatioID) & DEM_OBD_DEN_INCREASED_MASK) == 0) \
                && (((DenGroup != DEM_IUMPR_DEN_PHYS_API) \
                && (DEM_OBD_RATIO_DENOMCOND_STATUS(DenGroup) == DEM_IUMPR_DEN_STATUS_REACHED)) \
                || ((DenGroup == DEM_IUMPR_DEN_PHYS_API) \
                && ((DEM_OBD_RATIO_STATE(RatioID) & DEM_OBD_DEN_LOCK_MASK) == 0))))
            {
                EventId = DEM_CFG_RATIO_EVENTREF(RatioID);
                DtcStatus = DEM_DTC_STATUS(DEM_CFG_EVENT_DTCREF(EventId));
                /*SWS_Dem_00299*//*SWS_Dem_00709*/
#if((DEM_CONFIG_VARIANTS != STD_CONFIG_VARIANTS_POSTBUILD) \
    && (DEM_CFG_AVAILABILITYSUPPORT == DEM_EVENT_AVAILABILITY))
                if((Dem_EventAvailable[EventId] == TRUE) && (!DEM_TEST_UDS_STATUS_PDTC(DtcStatus)))
#else
                if(!DEM_TEST_UDS_STATUS_PDTC(DtcStatus))
#endif
                {
                    DEM_OBD_RATIO_DENOMINATOR(RatioID)++;
                    DEM_OBD_RATIO_STATE(RatioID) |= DEM_OBD_DEN_INCREASED_MASK;
                }

                if(DEM_OBD_RATIO_DENOMINATOR(RatioID) >= DEM_OBD_NUMDEN_MAX_VALUE)
                {
                    DEM_OBD_RATIO_NUMERATOR(RatioID) = (DEM_OBD_RATIO_NUMERATOR(RatioID) >> 1);
                    DEM_OBD_RATIO_DENOMINATOR(RatioID) = (DEM_OBD_RATIO_DENOMINATOR(RatioID) >> 1);
                }
            }
        }/* for(RatioID = 0; RatioID < DEM_NUM_OF_RATIO; RatioID++)*/
    }/*if(DEM_OBD_RATIO_DENOMCOND_STATUS(DEM_IUMPR_DEN_GENERAL) == DEM_IUMPR_DEN_STATUS_REACHED)*/
}
#endif/*#if(DEM_NUM_OF_RATIO > 0)*/
#endif/*#if((DEM_CFG_OBD_SUPPORT == DEM_OBD_MASTER_ECU)||(DEM_CFG_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU))*/

#if(DEM_CFG_MAXNUMBEREVENTENTRY_PERMANENT > 0)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DemInternal_AddEventPermanentEntry
*
* Description: Add one event to the permanent memory entry.
*
* Inputs:
*
* Outputs:
*
* Return:
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, DEM_CODE) DemInternal_AddEventPermanentEntry
(
    Dem_EventIdType EventId
)
{
    uint8 Index;
    uint8 IndicatorId;
    uint16 StatusPos;
    uint8 FreeEntry = DEM_CFG_MAXNUMBEREVENTENTRY_PERMANENT;
    boolean MilOn = FALSE;
    boolean IgnOn = FALSE;

    /*Check if IGN operation cycle is start.*/
    for(Index = 0; Index < DEM_NUM_OF_OPCYCLE; Index++)
    {
        if((DEM_CFG_OPCYC_TYPE(Index) == DEM_OPCYC_IGNITION) \
            && (Dem_OpCycState[Index] == DEM_CYCLE_STATE_START))
        {
            IgnOn = TRUE;
        }
    }

    if((DEM_CFG_EVENT_INDICATOR_NUM(EventId) > (uint8)0) \
        && (DEM_CFG_EVENT_INDICATOR(EventId) != NULL_PTR) \
        && (IgnOn == TRUE))
    {
        for(Index = 0; Index < DEM_CFG_EVENT_INDICATOR_NUM(EventId); Index++)
        {
            IndicatorId = DEM_CFG_EVENT_INDICATOR_ID(EventId,Index);
            StatusPos = DEM_CFG_EVENT_INDICATOR_OFFSET(EventId,Index) \
                            + DEM_CFG_INDICATOR_STATUS_START(IndicatorId);

            if((DEM_INDICATOR_STATUS(StatusPos) != DEM_INDICATOR_OFF) \
                && (IndicatorId == DEM_CFG_MILINDICATORREF))
            {
                MilOn = TRUE;
                break;
            }
        }
    }

    if(MilOn == TRUE)
    {
        for(Index = 0; Index < DEM_CFG_MAXNUMBEREVENTENTRY_PERMANENT; Index++)
        {
            if(DEM_PERMANENT_DATAENTRY_EVENTID(Index) == EventId)
            {
                break;
            }
            else if((DEM_PERMANENT_DATAENTRY_EVENTID(Index) == DEM_EVENT_ID_INVALID) \
                && (FreeEntry == DEM_CFG_MAXNUMBEREVENTENTRY_PERMANENT))
            {
                FreeEntry = Index;
            }
            else
            {
                /*do nothing*/
            }
        }

        if((Index == DEM_CFG_MAXNUMBEREVENTENTRY_PERMANENT) \
            && (FreeEntry < DEM_CFG_MAXNUMBEREVENTENTRY_PERMANENT))
        {
            DEM_PERMANENT_DATAENTRY_EVENTID(FreeEntry) = EventId;
            DEM_PERMANENT_DATAENTRY_USEDNUM++;
        }
    }
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DemInternal_RemoveEventPermanentEntry
*
* Description: Remove one event from the permanent memory entry.
*
* Inputs:
*
* Outputs:
*
* Return:
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, DEM_CODE) DemInternal_RemoveEventPermanentEntry
(
    Dem_EventIdType EventId
)
{
    uint8 Index;
    uint8 IndicatorId;
    uint16 StatusPos;
    Dem_EventIdType EventIdx;
    uint8 MemIdx = DEM_CFG_MAXNUMBEREVENTENTRY_PERMANENT;
    boolean MilOff = FALSE;
    boolean ClearConditionSatisfied = FALSE;

    if(DEM_EVENT_OBD_CLEAR_FLAG(EventId) == FALSE)
    {
        ClearConditionSatisfied = TRUE;
    }
    else
    {
        /*Check if WarmUp operation cycle is start.*/
        for(Index = 0; Index < DEM_NUM_OF_OPCYCLE; Index++)
        {
            if((DEM_CFG_OPCYC_TYPE(Index) == DEM_OPCYC_WARMUP) \
                && (Dem_OpCycState[Index] == DEM_CYCLE_STATE_START))
            {
                ClearConditionSatisfied = TRUE;
            }
        }
    }

    if(ClearConditionSatisfied == TRUE)
    {
        for(Index = 0; Index < DEM_CFG_MAXNUMBEREVENTENTRY_PERMANENT; Index++)
        {
            if(DEM_PERMANENT_DATAENTRY_EVENTID(Index) == EventId)
            {
                MemIdx = Index;
                break;
            }
        }

        if(MemIdx < DEM_CFG_MAXNUMBEREVENTENTRY_PERMANENT)
        {
            for(Index = 0; Index < DEM_CFG_EVENT_INDICATOR_NUM(EventId); Index++)
            {
                IndicatorId = DEM_CFG_EVENT_INDICATOR_ID(EventId,Index);
                StatusPos = DEM_CFG_EVENT_INDICATOR_OFFSET(EventId,Index) \
                                + DEM_CFG_INDICATOR_STATUS_START(IndicatorId);

                if((DEM_INDICATOR_STATUS(StatusPos) == DEM_INDICATOR_OFF) \
                    && (IndicatorId == DEM_CFG_MILINDICATORREF))
                {
                    MilOff = TRUE;
                    break;
                }
            }
        }

        if(MilOff == TRUE)
        {
            DEM_PERMANENT_DATAENTRY_EVENTID(MemIdx) = DEM_EVENT_ID_INVALID;
            DEM_PERMANENT_DATAENTRY_USEDNUM--;

            /*If one event with MIL ON is not stored in permanent entry, now it can be stored.*/
            for(EventIdx = 0; EventIdx < DEM_NUM_OF_EVENT; EventIdx++)
            {
                DemInternal_AddEventPermanentEntry(EventIdx);
            }
        }
    }
}
#endif/*#if(DEM_CFG_MAXNUMBEREVENTENTRY_PERMANENT > 0)*/

/*******************************************************************************
*   AUTOSAR Stabdard Api
*******************************************************************************/
#if(STD_ON == DEM_VERSION_INFO_API)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_GetVersionInfo
*
* Description: Returns the version information of this module.
*
* Inputs: None
*
* Outputs: versioninfo:Pointer to where to store the version information of
*                      this module.
*
* Return: None
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, DEM_CODE) Dem_GetVersionInfo
(
    P2VAR(Std_VersionInfoType, AUTOMATIC, DEM_APPL_DATA) versionInfo
)
{
    if(NULL_PTR == versionInfo)
    {
        DEM_DET_REPORT_ERROR(DEM_GETVERSIONINFO_APIID, DEM_E_PARAM_POINTER);
    }
    else
    {
        versionInfo->vendorID = DEM_VENDOR_ID;
        versionInfo->moduleID = DEM_MODULE_ID;

        versionInfo->sw_major_version = DEM_SW_MAJOR_VERSION;
        versionInfo->sw_minor_version = DEM_SW_MINOR_VERSION;
        versionInfo->sw_patch_version = DEM_SW_PATCH_VERSION;
    }
}
#endif

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_PreInit
*
* Description: Initializes the internal states necessary to process events
*              reported by BSW-modules.
*
* Inputs: None
*
* Outputs: None
*
* Return: None
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, DEM_CODE) Dem_PreInit
(
    void
)
{
    uint16 i;

#if(DEM_CFG_BSWERRORBUFFERSIZE > 0)
    for(i = 0; i < DEM_CFG_BSWERRORBUFFERSIZE; i++)
    {
        Dem_BswErrorQueue[i] = DEM_DATA_INVALID_U16;
        Dem_BswErrorStatus[i] = DEM_DATA_INVALID_U8;
    }
#endif

#if((DEM_CONFIG_VARIANTS != STD_CONFIG_VARIANTS_POSTBUILD) \
    && (DEM_CFG_AVAILABILITYSUPPORT == DEM_EVENT_AVAILABILITY))
    /*SWS_Dem_01107 init the availability of an event*/
    for(i = 0; i < DEM_NUM_OF_EVENT; i++)
    {
        if(DEM_CFG_EVENT_AVAILABLE(i) == TRUE)
        {
            Dem_EventAvailable[i] = TRUE;
        }
        else
        {
            Dem_EventAvailable[i] = FALSE;
        }
    }
#endif
    /*SWS_Dem_00438*/
    for(i = 0; i < DEM_NUM_OF_EVENT; i++)
    {
        /*reset the Dem-internal debounce algorithm*/
#if(DEM_CFG_DEBOUNCECOUNTERBASEDSUPPORT == STD_ON)
        DEM_EVENT_DBC(i) = 0;
#endif
#if(DEM_CFG_DEBOUNCETIMEBASEDSUPPORT == STD_ON)
        DEM_EVENT_DBT(i) = 0;
        DEM_EVENT_TIMERDIRECTION(i) = DEM_DATA_INVALID_U8;
        Dem_EventDBTFreezeFlag[i] = FALSE;
#endif
    }
    /*init the status of enable conditions*/
#if(DEM_NUM_OF_EN_CONDITION > 0)
    for(i = 0; i < DEM_NUM_OF_EN_CONDITION; i++)
    {
        if(DEM_CFG_EN_CONDITION_STATUS(i) == TRUE)
        {
            Dem_EventEnCondition[i] = TRUE;
        }
        else
        {
            Dem_EventEnCondition[i] = FALSE;
        }
    }
#endif
    /*init the status of storage conditions*/
#if(DEM_NUM_OF_STOR_CONDITION > 0)
    for(i = 0; i < DEM_NUM_OF_STOR_CONDITION; i++)
    {
        if(DEM_CFG_STOR_CONDITION_STATUS(i) == TRUE)
        {
            Dem_EventStorCondition[i] = TRUE;
        }
        else
        {
            Dem_EventStorCondition[i] = FALSE;
        }
    }
#endif
    /*SWS_Dem_00169*/
    DEM_SET_STATE(DEM_PREINIT);
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_Init
*
* Description: Initializes or reinitializes this module.
*
* Inputs: ConfigPtr:Pointer to the configuration set in VARIANT-POSTBUILD.
*
* Outputs: None
*
* Return: None
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, DEM_CODE) Dem_Init
(
    P2CONST(Dem_ConfigType, AUTOMATIC, DEM_APPL_DATA) ConfigPtr
)
{
    uint16 i;

#if(DEM_CONFIG_VARIANTS == STD_CONFIG_VARIANTS_POSTBUILD)
    if(NULL_PTR == ConfigPtr)
    {
        DEM_DET_REPORT_ERROR(DEM_INIT_APIID, DEM_E_PARAM_POINTER);
    }
    else
    {
        Dem_ConfigPtr = ConfigPtr;
#else
    (void)ConfigPtr;
#endif
        /*Check if the value in Dem_StorageMem is valid*/
        DemInternal_CheckStorageMem();

        for(i = 0; i < DEM_NUM_OF_DTC; i++)
        {
            /*Enable DTC setting*/
            Dem_EnableDtcSetting[i] = TRUE;
            /*Enable DTC Update*/
            Dem_DtcUpDateState[i] = TRUE;
        }
        for(i = 0; i < DEM_NUM_OF_EVENT; i++)
        {
            /*Clear EventCaptureFlag*/
            DemInternal_ClrCaptureQueue(i);
        }
        Dem_CapturePosition = 0;

        Dem_DcmFilterInfo.FilteredValidFlag = FALSE;
#if(STD_ON == DEM_CFG_J1939READING_DTC_SUPPORT)
        Dem_J1939DcmFilterInfo.FilteredValidFlag = FALSE;
#endif
        /*init operation cycle state*//*SWS_Dem_00853*/
        for(i = 0; i < DEM_NUM_OF_OPCYCLE; i++)
        {
            Dem_OpCycState[i] = DEM_CYCLE_STATE_END;
            if(DEM_CFG_OPCYC_AUTOSTART(i) == TRUE)
            {
                Dem_OpCycReq[i] = DEM_CYCLE_STATE_START;
            }
            else
            {
                Dem_OpCycReq[i] = DEM_DATA_CLEAR;
            }
        }
#if((DEM_CFG_OBD_SUPPORT == DEM_OBD_MASTER_ECU) && (DEM_CFG_OBD_CENTRALIZED_PID31_HANDLING == STD_ON))
        Dem_ObdTimeSinceEngineStartLast = DEM_DATA_CLEAR;
        Dem_ObdTimesOneSecond = DEM_DATA_CLEAR;
#endif
        /*SWS_Dem_01189*/
#if(DEM_CFG_TRIGGER_FIM_REPORTS == STD_ON)
        FiM_DemInit();
#endif
        /*SWS_Dem_00340*/
        DEM_SET_STATE(DEM_NORMAL);
#if(DEM_CONFIG_VARIANTS == STD_CONFIG_VARIANTS_POSTBUILD)
    }
#endif
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_Shutdown
*
* Description: Shuts down this module.
*
* Inputs: None
*
* Outputs: None
*
* Return: None
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, DEM_CODE) Dem_Shutdown
(
    void
)
{
    uint8 i;

    SchM_Enter_Dem_DEM_EXCLUSIVE_AREA_0();

    if(Dem_State != DEM_UNINIT)
    {
        for(i = 0; i < DEM_NUM_OF_OPCYCLE; i++)
        {
            /*SWS_Dem_01078*/
            Dem_OpCycReq[i] = DEM_DATA_CLEAR;
            if(Dem_OpCycState[i] == DEM_CYCLE_STATE_START)
            {
                Dem_OpCycState[i] = DEM_CYCLE_STATE_END;
                DemInternal_CycleEndProcess(i);
            }
        }
        /*SWS_Dem_00368*/
        DEM_SET_STATE(DEM_PREINIT);
    }
    SchM_Exit_Dem_DEM_EXCLUSIVE_AREA_0();
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_ReportErrorStatus
*
* Description: Queues the reported events from the BSW modules (API is only used
*              by BSW modules).The interface has an asynchronous behavior, because
*              the processing of the event is done within the Dem main function.
*              OBD Events Suppression shall be ignored for this computation.
*
* Inputs: EventId: Identification of an event by assigned Event ID.
*         EventStatus: Monitor test result
*
* Outputs: None
*
* Return: None
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, DEM_CODE) Dem_ReportErrorStatus
(
    Dem_EventIdType EventId,
    Dem_EventStatusType EventStatus
)
{
    /*SWS_Dem_00107*/
#if(DEM_NUM_OF_EN_GROUP > 0)
    Std_ReturnType ret = E_OK;
#endif
    uint8 i;

    if(Dem_State == DEM_UNINIT)
    {
        /*SWS_Dem_00364*/
        DEM_DET_REPORT_ERROR(DEM_REPORTERRORSTATUS_APIID, DEM_E_UNINIT);
    }
    else if(EventId >= DEM_NUM_OF_EVENT)
    {
        DEM_DET_REPORT_ERROR(DEM_REPORTERRORSTATUS_APIID, DEM_E_PARAM_DATA);
    }
    else if(DEM_CFG_EVENT_KIND(EventId) != DEM_EVENT_KIND_BSW)
    {
        DEM_DET_REPORT_ERROR(DEM_REPORTERRORSTATUS_APIID, DEM_E_WRONG_CONFIGURATION);
    }
    else if((Dem_State == DEM_PREINIT) \
            && (DEM_CFG_EVENT_REPBEHAVIOR(EventId) != DEM_REPORT_BEFORE_INIT))
    {
        DEM_DET_REPORT_ERROR(DEM_REPORTERRORSTATUS_APIID, DEM_E_WRONG_CONFIGURATION);
    }
#if(DEM_CFG_DEBOUNCECOUNTERBASEDSUPPORT == STD_ON)
    else if((Dem_State == DEM_PREINIT) \
            && (DEM_CFG_EVENT_DBC(EventId) != NULL_PTR)
            && (DEM_CFG_EVENT_DBC_STORAGE(EventId) == TRUE))
    {
        /*SWS_Dem_00676*//*SWS_Dem_00518*/
        DEM_DET_REPORT_ERROR(DEM_REPORTERRORSTATUS_APIID, DEM_E_WRONG_CONDITION);
    }
#endif
#if((DEM_CONFIG_VARIANTS != STD_CONFIG_VARIANTS_POSTBUILD) \
    && (DEM_CFG_AVAILABILITYSUPPORT == DEM_EVENT_AVAILABILITY))
    else if(Dem_EventAvailable[EventId] == FALSE)
    {
        /*SWS_Dem_01108*/
    }
#endif
    else if(((EventStatus == DEM_EVENT_STATUS_PREPASSED) \
             || (EventStatus == DEM_EVENT_STATUS_PREFAILED)) \
            && (DEM_CFG_EVENT_GET_FDC_FNC(EventId) != NULL_PTR))
    {
        /*SWS_Dem_00437*/
    }
    else
    {
#if(DEM_NUM_OF_EN_GROUP > 0)
        /*SWS_Dem_00447*//*SWS_Dem_00449*//*SWS_Dem_00450*/
        if(DEM_CFG_EVENT_EN(EventId) != NULL_PTR)
        {
            for(i = 0; i < DEM_CFG_EVENT_EN_NUM(EventId); i++)
            {
                if(Dem_EventEnCondition[(DEM_CFG_EVENT_EN_REF(EventId)[i])] != TRUE)
                {
                    ret = E_NOT_OK;
                    break;
                }
            }
        }
        if(ret == E_OK)
#endif
        {
#if(DEM_CFG_BSWERRORBUFFERSIZE > 0)
            for(i = 0; i < DEM_CFG_BSWERRORBUFFERSIZE; i++)
            {
                if(Dem_BswErrorQueue[i] == DEM_DATA_INVALID_U16)
                {
                    Dem_BswErrorQueue[i] = EventId;
                    Dem_BswErrorStatus[i] = EventStatus;
                    break;
                }
            }
#endif
        }
    }
}

#if((DEM_CONFIG_VARIANTS != STD_CONFIG_VARIANTS_POSTBUILD) \
    && (DEM_CFG_AVAILABILITYSUPPORT == DEM_EVENT_AVAILABILITY))
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_SetEventAvailable
*
* Description: Set the available status of a specific Event.
*
* Inputs: EventId: Identification of an event by assigned EventId.
*         AvailableStatus: This parameter specifies whether the respective
*                          Event shall be available (TRUE) or not (FALSE).
*
* Outputs: None
*
* Return: E_OK: Operation was successful.
*         E_NOT_OK: change of available status not accepted
*
* Limitations: Non Reentrant
********************************************************************************
END_FUNCTION_HDR*/
/*SWS_Dem_00177*//*SWS_Dem_00687*/
FUNC(Std_ReturnType, DEM_CODE) Dem_SetEventAvailable
(
    Dem_EventIdType EventId,
    boolean AvailableStatus
)
{
    Std_ReturnType Result = E_OK;
    Dem_UdsStatusByteType EventOldStatus = DEM_DTC_STATUS(DEM_CFG_EVENT_DTCREF(EventId));

    if(Dem_State == DEM_UNINIT)
    {
        DEM_DET_REPORT_ERROR(DEM_SETEVENTAVAILABLE_APIID, DEM_E_UNINIT);
        Result = E_NOT_OK;
    }
    else if((DEM_TEST_UDS_STATUS_TF(EventOldStatus))\
        || (DEM_DTC_DATAENTRYREF(DEM_CFG_EVENT_DTCREF(EventId)) != DEM_DATA_INVALID_U16))
    {
        /*SWS_Dem_01109*/
        Result = E_NOT_OK;
    }
    else
    {
        if(Dem_EventAvailable[EventId] == AvailableStatus)
        {
            /*state not changed*/
            Result = E_NOT_OK;
        }
        else if(AvailableStatus == TRUE)
        {
            Dem_EventAvailable[EventId] = TRUE;
            /*SWS_Dem_01111*/
            DEM_DTC_STATUS(DEM_CFG_EVENT_DTCREF(EventId)) = DEM_STATUS_RESET;
            (void)DEM_CFG_DTC_STATUSCHANGED_CALLFNC(DEM_CFG_DTC_VALUE(DEM_CFG_EVENT_DTCREF(EventId)), DEM_DATA_CLEAR, DEM_STATUS_RESET);
            if(DEM_CFG_EVENT_STATUSCHANGED_CALLFNC(EventId) != NULL_PTR)
            {
                /*SWS_Dem_00016*/
                (void)DEM_CFG_EVENT_STATUSCHANGED_CALLFNC(EventId)(DEM_DATA_CLEAR, DEM_STATUS_RESET);
            }
#if(DEM_CFG_TRIGGER_FIM_REPORTS == STD_ON)
            FiM_DemTriggerOnEventStatus(EventId, DEM_DATA_CLEAR, DEM_STATUS_RESET);
#endif
        }
        else
        {
            /*SWS_Dem_01108*/
            Dem_EventAvailable[EventId] = FALSE;
            /*SWS_Dem_01110*/
            DEM_DTC_STATUS(DEM_CFG_EVENT_DTCREF(EventId)) = DEM_DATA_CLEAR;
            (void)DEM_CFG_DTC_STATUSCHANGED_CALLFNC(DEM_CFG_DTC_VALUE(DEM_CFG_EVENT_DTCREF(EventId)), EventOldStatus, DEM_DATA_CLEAR);
            if(DEM_CFG_EVENT_STATUSCHANGED_CALLFNC(EventId) != NULL_PTR)
            {
                /*SWS_Dem_00016*/
                (void)DEM_CFG_EVENT_STATUSCHANGED_CALLFNC(EventId)(EventOldStatus, DEM_DATA_CLEAR);
            }
#if(DEM_CFG_TRIGGER_FIM_REPORTS == STD_ON)
            FiM_DemTriggerOnEventStatus(EventId, EventOldStatus, DEM_DATA_CLEAR);
#endif
        }
    }

    return Result;
}
#endif/*#if((DEM_CONFIG_VARIANTS != STD_CONFIG_VARIANTS_POSTBUILD) \
    && (DEM_CFG_AVAILABILITYSUPPORT == DEM_EVENT_AVAILABILITY))*/

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_SetEventStatus
*
* Description: Processes the events reported by SW-Cs via RTE. This API can only
*              be used through the RTE, and therefore no declaration is exported
*              via Dem.h. Some bits of the UDS DTC status byte changes
*              synchronously or asynchronously (refer to SWS_Dem_00036 and
*              SWS_Dem_00379).OBD Events Suppression shall be ignored for this
*              computation.
*
* Inputs: EventId: Identification of an event by assigned EventId.
*         EventStatus: Monitor test result
*
* Outputs: None
*
* Return: E_OK: set of event status was successful.
*         E_NOT_OK: set of event status failed or could not be accepted.
*                   (e.g.: the operation cycle configured for this event has not
*                   been started,an according enable condition has been disabled)
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, DEM_CODE) Dem_SetEventStatus
(
    Dem_EventIdType EventId,
    Dem_EventStatusType EventStatus
)
{
    Std_ReturnType Result = E_NOT_OK;
#if(DEM_NUM_OF_EN_CONDITION > 0)
    uint8 i;
#endif

    if(Dem_State != DEM_NORMAL)
    {
        /*SWS_Dem_01112*//*SWS_Dem_00124*/
        DEM_DET_REPORT_ERROR(DEM_SETEVENTSTATUS_APIID, DEM_E_UNINIT);
    }
    else if(EventId >= DEM_NUM_OF_EVENT)
    {
        DEM_DET_REPORT_ERROR(DEM_SETEVENTSTATUS_APIID, DEM_E_PARAM_DATA);
    }
    else if(DEM_CFG_EVENT_KIND(EventId) != DEM_EVENT_KIND_SWC)
    {
        DEM_DET_REPORT_ERROR(DEM_SETEVENTSTATUS_APIID, DEM_E_WRONG_CONFIGURATION);
    }
#if((DEM_CONFIG_VARIANTS != STD_CONFIG_VARIANTS_POSTBUILD) \
    && (DEM_CFG_AVAILABILITYSUPPORT == DEM_EVENT_AVAILABILITY))
    else if(Dem_EventAvailable[EventId] == FALSE)
    {
        /*SWS_Dem_01108*/
    }
#endif
    else if(((EventStatus == DEM_EVENT_STATUS_PREPASSED) \
             || (EventStatus == DEM_EVENT_STATUS_PREFAILED)) \
            && (DEM_CFG_EVENT_GET_FDC_FNC(EventId) != NULL_PTR))
    {
        /*SWS_Dem_00437*/
    }
    else
    {
        Result = E_OK;

#if(DEM_NUM_OF_EN_GROUP > 0)
        /*SWS_Dem_00447*//*SWS_Dem_00449*//*SWS_Dem_00450*/
        if(DEM_CFG_EVENT_EN(EventId) != NULL_PTR)
        {
            for(i = 0; i < DEM_CFG_EVENT_EN_NUM(EventId); i++)
            {
                if(Dem_EventEnCondition[(DEM_CFG_EVENT_EN_REF(EventId)[i])] != TRUE)
                {
                    Result = E_NOT_OK;
                    break;
                }
            }
        }
        if(Result == E_OK)
#endif
        {
            DemInternal_SetEventStatus(EventId, EventStatus);
        }
    }
    return Result;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_ResetEventDebounceStatus
*
* Description: Control the internal debounce counter/timer by BSW modules and SWCs.
*              The event qualification will not be affected by these debounce state
*              changes. This API is available for BSW modules as soon as Dem_PreInit
*              has been completed
*
* Inputs: EventId: Identification of an event by assigned EventId.
*         DebounceResetStatus: Freeze or reset the internal debounce counter/timer
*                              of the specified event.
*
* Outputs: None
*
* Return: E_OK: Operation was successful
*         E_NOT_OK: Only on development error
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, DEM_CODE) Dem_ResetEventDebounceStatus
(
    Dem_EventIdType EventId,
    Dem_DebounceResetStatusType DebounceResetStatus
)
{
    Std_ReturnType Result = E_OK;

    if(Dem_State == DEM_UNINIT)
    {
        /*SWS_Dem_00364*/
        DEM_DET_REPORT_ERROR(DEM_RESETEVENTDEBOUNCESTATUS_APIID, DEM_E_UNINIT);
        Result = E_NOT_OK;
    }
#if(DEM_CFG_DEBOUNCECOUNTERBASEDSUPPORT == STD_ON)
    else if((Dem_State != DEM_NORMAL) && (DEM_CFG_EVENT_DBC_STORAGE(EventId) == TRUE))
    {
        /*SWS_Dem_00676*//*SWS_Dem_00518*/
        DEM_DET_REPORT_ERROR(DEM_RESETEVENTDEBOUNCESTATUS_APIID, DEM_E_WRONG_CONDITION);
        Result = E_NOT_OK;
    }
#endif
#if((DEM_CONFIG_VARIANTS != STD_CONFIG_VARIANTS_POSTBUILD) \
    && (DEM_CFG_AVAILABILITYSUPPORT == DEM_EVENT_AVAILABILITY))
    else if(Dem_EventAvailable[EventId] == FALSE)
    {
        /*SWS_Dem_01108*/
        Result = E_NOT_OK;
    }
#endif
    else
    {
        if(DebounceResetStatus == DEM_DEBOUNCE_STATUS_FREEZE)
        {
            /*SWS_Dem_00685*/
#if(DEM_CFG_DEBOUNCETIMEBASEDSUPPORT == STD_ON)
            Dem_EventDBTFreezeFlag[EventId] = TRUE;
#endif
        }
        else if(DebounceResetStatus == DEM_DEBOUNCE_STATUS_RESET)
        {
            /*SWS_Dem_00684*/
#if(DEM_CFG_DEBOUNCECOUNTERBASEDSUPPORT == STD_ON)
            DEM_EVENT_DBC(EventId) = 0;
#endif
#if(DEM_CFG_DEBOUNCETIMEBASEDSUPPORT == STD_ON)
            DEM_EVENT_DBT(EventId) = 0;
            DEM_EVENT_TIMERDIRECTION(EventId) = DEM_DATA_INVALID_U8;
            Dem_EventDBTFreezeFlag[EventId] = FALSE;
#endif
        }
        else
        {
            Result = E_NOT_OK;
        }
    }
    return Result;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_ResetEventStatus
*
* Description: Resets the event failed status. This API can only be used through
*              the RTE and therefore no declaration is exported via Dem.h.
*
* Inputs: EventId: Identification of an event by assigned EventId.
*
* Outputs: None
*
* Return: E_OK: reset of event status was successful
*         E_NOT_OK: reset of event status failed or is not allowed,because the
*                   event is already tested in this operation cycle
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, DEM_CODE) Dem_ResetEventStatus
(
    Dem_EventIdType EventId
)
{
    Std_ReturnType Result = E_OK;
    uint8 EventOldStatus;
    uint8 EventNewStatus;

    if(Dem_State == DEM_UNINIT)
    {
        /*SWS_Dem_01112*/
        DEM_DET_REPORT_ERROR(DEM_SETEVENTSTATUS_APIID, DEM_E_UNINIT);
        Result = E_NOT_OK;
    }
    else if(EventId >= DEM_NUM_OF_EVENT)
    {
        DEM_DET_REPORT_ERROR(DEM_SETEVENTSTATUS_APIID, DEM_E_PARAM_DATA);
        Result = E_NOT_OK;
    }
#if((DEM_CONFIG_VARIANTS != STD_CONFIG_VARIANTS_POSTBUILD) \
    && (DEM_CFG_AVAILABILITYSUPPORT == DEM_EVENT_AVAILABILITY))
    else if(Dem_EventAvailable[EventId] == FALSE)
    {
        /*SWS_Dem_01108*/
        Result = E_NOT_OK;
    }
#endif
    else if(Dem_EnableDtcSetting[EventId] == FALSE)
    {
        /*SWS_Dem_00518*/
        DEM_DET_REPORT_ERROR(DEM_SETEVENTSTATUS_APIID, DEM_E_WRONG_CONDITION);
        Result = E_NOT_OK;
    }
    else
    {
        EventOldStatus = DEM_DTC_STATUS(DEM_CFG_EVENT_DTCREF(EventId));
        /*SWS_Dem_00638*//*SWS_Dem_00187*/
        if(DEM_TEST_UDS_STATUS_TNCTOC(EventOldStatus))
        {
            /*SWS_Dem_00386*/
            EventNewStatus = DEM_CLEAR_UDS_STATUS_TF(EventOldStatus);

            DEM_DTC_STATUS(DEM_CFG_EVENT_DTCREF(EventId)) = EventNewStatus;

            if(EventNewStatus != EventOldStatus)
            {
                (void)DEM_CFG_DTC_STATUSCHANGED_CALLFNC(DEM_CFG_DTC_VALUE(DEM_CFG_EVENT_DTCREF(EventId)), EventOldStatus, EventNewStatus);
                if(NULL_PTR != DEM_CFG_EVENT_STATUSCHANGED_CALLFNC(EventId))
                {
                    /*SWS_Dem_00016*/
                    (void)DEM_CFG_EVENT_STATUSCHANGED_CALLFNC(EventId)(EventOldStatus, EventNewStatus);
                }
#if(DEM_CFG_TRIGGER_FIM_REPORTS == STD_ON)
                FiM_DemTriggerOnEventStatus(EventId, EventOldStatus, EventNewStatus);
#endif
            }
#if(DEM_CFG_DEBOUNCECOUNTERBASEDSUPPORT == STD_ON)
            /* Reset debounce counter. */
            DEM_EVENT_DBC(EventId) = 0;
#endif
#if(DEM_CFG_DEBOUNCETIMEBASEDSUPPORT == STD_ON)
            DEM_EVENT_DBT(EventId) = 0;
            DEM_EVENT_TIMERDIRECTION(EventId) = DEM_DATA_INVALID_U8;
            Dem_EventDBTFreezeFlag[EventId] = FALSE;
#endif
        }
        else
        {
            Result = E_NOT_OK;
        }
    }
    return Result;
}

#if(DEM_CFG_MAXNUMBER_PRESTOREDFF > 0)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_PrestoreFreezeFrame
*
* Description: Captures the freeze frame data for a specific event. This API can
*              only be used through the RTE and therefore no declaration is
*              exported via Dem.h.
*
* Inputs: EventId: Identification of an event by assigned EventId.
*
* Outputs: None
*
* Return: E_OK: Freeze frame prestorage was successful
*         E_NOT_OK: Freeze frame prestorage failed
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, DEM_CODE) Dem_PrestoreFreezeFrame
(
    Dem_EventIdType EventId
)
{
    /*SWS_Dem_00334*//*SWS_Dem_00189*/
    Std_ReturnType Result = E_NOT_OK;


    return Result;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_ClearPrestoredFreezeFrame
*
* Description: Clears a prestored freeze frame of a specific event. This API can
*              only be used through the RTE and therefore no declaration is
*              exported via Dem.h.
*
* Inputs: EventId: Identification of an event by assigned EventId.
*
* Outputs: None
*
* Return: E_OK: Clear prestored freeze frame was successful
*         E_NOT_OK: Clear prestored freeze frame failed
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, DEM_CODE) Dem_ClearPrestoredFreezeFrame
(
    Dem_EventIdType EventId
)
{
    /*SWS_Dem_00334*//*SWS_Dem_00050*/
    Std_ReturnType Result = E_NOT_OK;


    return Result;
}
#endif

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_SetOperationCycleState
*
* Description: Sets an operation cycle state. This API can only be used through
*              the RTE and therefore no declaration is exported via Dem.h. The
*              interface has an asynchronous behavior to avoid exceeding of typical
*              timing requirements on APIs if a large number of events has to be
*              processed and during the re-initializations of the related monitors.
*              The asynchronous acknowledgements are the related InitMonitorForEvent
*              callbacks.
*
* Inputs: OperationCycleId: Identification of operation cycle, like power cycle,
*                           driving cycle.
*         CycleState: New operation cycle state: (re-)start or end
*
* Outputs: None
*
* Return: E_OK: set of operation cycle was accepted and will be handled
*               asynchronously
*         E_NOT_OK: set of operation cycle was rejected
*
* Limitations: Asynchronous,Reentrant
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, DEM_CODE) Dem_SetOperationCycleState
(
    uint8 OperationCycleId,
    Dem_OperationCycleStateType CycleState
)
{
    /*SWS_Dem_00338*/
    Std_ReturnType Result = E_NOT_OK;

    if(Dem_State != DEM_NORMAL)
    {
        /*SWS_Dem_01112*//*SWS_Dem_00124*/
        DEM_DET_REPORT_ERROR(DEM_SETOPERATIONCYCLESTATE_APIID, DEM_E_UNINIT);
    }
    else if(OperationCycleId >= DEM_NUM_OF_OPCYCLE)
    {
        DEM_DET_REPORT_ERROR(DEM_SETOPERATIONCYCLESTATE_APIID, DEM_E_PARAM_DATA);
    }
    else if((CycleState != DEM_CYCLE_STATE_START) && (CycleState != DEM_CYCLE_STATE_END))
    {
        DEM_DET_REPORT_ERROR(DEM_SETOPERATIONCYCLESTATE_APIID, DEM_E_PARAM_DATA);
    }
    else
    {
        Dem_OpCycReq[OperationCycleId] = CycleState;
        Result = E_OK;
    }
    return Result;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_GetOperationCycleState
*
* Description: Gets information about the status of a specific operation cycle.
*              This API can only be used through the RTE and therefore no
*              declaration is exported via Dem.h.
*
* Inputs: OperationCycleId: Identification of operation cycle, like power cycle,
*                           driving cycle.
*
* Outputs: CycleState: Cycle status information
*
* Return: E_OK: read out of operation cycle was successful
*         E_NOT_OK: read out of operation cycle failed
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, DEM_CODE) Dem_GetOperationCycleState
(
    uint8 OperationCycleId,
    P2VAR(Dem_OperationCycleStateType, AUTOMATIC, DEM_APPL_DATA) CycleState
)
{
    Std_ReturnType Result = E_NOT_OK;

    if(Dem_State != DEM_NORMAL)
    {
        /*SWS_Dem_01112*//*SWS_Dem_00124*/
        DEM_DET_REPORT_ERROR(DEM_GETOPERATIONCYCLESTATE_APIID, DEM_E_UNINIT);
    }
    else if(OperationCycleId >= DEM_NUM_OF_OPCYCLE)
    {
        DEM_DET_REPORT_ERROR(DEM_GETOPERATIONCYCLESTATE_APIID, DEM_E_PARAM_DATA);
    }
    else if(CycleState == NULL_PTR)
    {
        DEM_DET_REPORT_ERROR(DEM_GETOPERATIONCYCLESTATE_APIID, DEM_E_PARAM_POINTER);
    }
    else
    {
        *CycleState = Dem_OpCycState[OperationCycleId];
        Result = E_OK;
    }
    return Result;
}


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_SetAgingCycleState
*
* Description: Triggers the next aging cycle state. This API can only be used
*              through the RTE,and therefore no declaration is exported via Dem.h.
*
* Inputs: OperationCycleId: Identification of aging cycle.
*
* Outputs: None
*
* Return: E_OK: set of aging cycle was successful
*         E_NOT_OK: set of aging cycle failed
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, DEM_CODE) Dem_SetAgingCycleState
(
    uint8 OperationCycleId
)
{
    Std_ReturnType Result = E_NOT_OK;

    Result = Dem_SetOperationCycleState(OperationCycleId, DEM_CYCLE_STATE_START);

    return Result;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_SetWIRStatus
*
* Description: Sets the WIR status bit via failsafe SW-Cs.This API can only be
*              used through the RTE and therefore no declaration is exported via
*              Dem.h.
*
* Inputs: EventId: Identification of an event by assigned EventId.
*         WIRStatus: Requested status of event related WIR-bit (regarding to the
*                    current status of function inhibition)
*                    WIRStatus = TRUE -> WIR-bit shall be set to "1"
*                    WIRStatus = FALSE -> WIR-bit shall be set to "0"
*
* Outputs: None
*
* Return: E_OK: The request is accepted
*         E_NOT_OK: not be accepted (e.g. disabled controlDTCSetting) and should
*                   be repeated.
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
/*SWS_Dem_00831*//*SWS_Dem_00832*//*SWS_Dem_00839*/
FUNC(Std_ReturnType, DEM_CODE) Dem_SetWIRStatus
(
    Dem_EventIdType EventId,
    boolean WIRStatus
)
{
    Std_ReturnType Result = E_NOT_OK;
#if(DEM_NUM_OF_INDICATOR > 0)
    Dem_UdsStatusByteType EventStatus;
    uint8 Index;
    uint8 IndicatorId;
    uint16 StatusPos;
    boolean ClearWIRBit = TRUE;
#endif
#if(STD_ON == DEM_CMA_PLATFORM_ENABLED)
    uint8 EventCmaStatus;
#endif

    if(Dem_State != DEM_NORMAL)
    {
        /*SWS_Dem_01112*//*SWS_Dem_00124*/
        DEM_DET_REPORT_ERROR(DEM_SETWIRSTATUS_APIID, DEM_E_UNINIT);
    }
    else if(EventId >= DEM_NUM_OF_EVENT)
    {
        DEM_DET_REPORT_ERROR(DEM_SETWIRSTATUS_APIID, DEM_E_PARAM_DATA);
    }
    else if(Dem_EnableDtcSetting[DEM_CFG_EVENT_DTCREF(EventId)] == FALSE)
    {
        /*SWS_Dem_00836*/
    }
#if((DEM_CONFIG_VARIANTS != STD_CONFIG_VARIANTS_POSTBUILD) \
    && (DEM_CFG_AVAILABILITYSUPPORT == DEM_EVENT_AVAILABILITY))
    else if(Dem_EventAvailable[EventId] == FALSE)
    {
        /*SWS_Dem_01108*/
    }
#endif
#if(DEM_NUM_OF_INDICATOR > 0)
    else if((DEM_CFG_EVENT_INDICATOR_NUM(EventId) == 0) \
            || (DEM_CFG_EVENT_INDICATOR(EventId) == NULL_PTR))
    {
        /*Result = E_NOT_OK;*/
    }
    else
    {
        EventStatus = DEM_DTC_STATUS(DEM_CFG_EVENT_DTCREF(EventId));

        if(WIRStatus == TRUE)
        {
#if(STD_ON == DEM_CMA_PLATFORM_ENABLED)
            EventCmaStatus = DEM_EVENT_CMA_STATUS(EventId);
            EventCmaStatus = DEM_SET_CMA_STATUS_WIRSLC(EventCmaStatus);
            DEM_EVENT_CMA_STATUS(EventId) = EventCmaStatus;
#endif
            /*SWS_Dem_00833*/
            EventStatus = DEM_SET_UDS_STATUS_WIR(EventStatus);
            DEM_DTC_STATUS(DEM_CFG_EVENT_DTCREF(EventId)) = EventStatus;
        }
        else if(DEM_TEST_UDS_STATUS_WIR(EventStatus))
        {
            for(Index = 0; Index < DEM_CFG_EVENT_INDICATOR_NUM(EventId); Index++)
            {
                IndicatorId = DEM_CFG_EVENT_INDICATOR_ID(EventId,Index);
                StatusPos = DEM_CFG_EVENT_INDICATOR_OFFSET(EventId,Index) \
                                + DEM_CFG_INDICATOR_STATUS_START(IndicatorId);
                if(DEM_INDICATOR_STATUS(StatusPos) != DEM_INDICATOR_OFF)
                {
                    ClearWIRBit = FALSE;
                    break;
                }
            }

            if(ClearWIRBit == TRUE)
            {
                /*SWS_Dem_00834*/
                EventStatus = DEM_CLEAR_UDS_STATUS_WIR(EventStatus);
                DEM_DTC_STATUS(DEM_CFG_EVENT_DTCREF(EventId)) = EventStatus;
            }
        }
        else
        {
            /*WIR bit value is 0 now in EventStatus.*/
        }

        Result = E_OK;
    }
#else
    else
    {
        /*Result = E_NOT_OK;*/
    }
#endif/*#if(DEM_NUM_OF_INDICATOR > 0)*/

    return Result;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_GetComponentFailed
*
* Description: Gets the failed status of a DemComponent.
*
* Inputs: ComponentId: Identification of a DemComponent
*
* Outputs: ComponentFailed: TRUE: failed
*                           FALSE: not failed
*
* Return: E_OK: getting "ComponentFailed" was successful
*         E_NOT_OK: getting "ComponentFailed" was not successful
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, DEM_CODE) Dem_GetComponentFailed
(
    Dem_ComponentIdType ComponentId,
    P2VAR(boolean, AUTOMATIC, DEM_APPL_DATA) ComponentFailed
)
{
    Std_ReturnType Result = E_NOT_OK;


    return Result;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_GetEventStatus
*
* Description: Gets the current extended event status of an event.
*
* Inputs: EventId: Identification of an event by assigned EventId.
*
* Outputs: EventStatusByte: UDS DTC status byte of the requested event (refer to
*                           chapter "Status bit support").If the return value of
*                           the function call is E_NOT_OK,this parameter does not
*                           contain valid data.
*
* Return: E_OK: get of event status was successful
*         E_NOT_OK: get of event status failed
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, DEM_CODE) Dem_GetEventStatus
(
    Dem_EventIdType EventId,
    P2VAR(Dem_UdsStatusByteType, AUTOMATIC, DEM_APPL_DATA) EventStatusByte
)
{
    Std_ReturnType Result = E_NOT_OK;

    if(Dem_State != DEM_NORMAL)
    {
        /*SWS_Dem_01112*//*SWS_Dem_00124*/
        DEM_DET_REPORT_ERROR(DEM_GETEVENTSTATUS_APIID, DEM_E_UNINIT);
    }
    else if(EventStatusByte == NULL_PTR)
    {
        DEM_DET_REPORT_ERROR(DEM_GETEVENTSTATUS_APIID, DEM_E_PARAM_POINTER);
    }
    else if(EventId >= DEM_NUM_OF_EVENT)
    {
        DEM_DET_REPORT_ERROR(DEM_GETEVENTSTATUS_APIID, DEM_E_PARAM_DATA);
    }
#if((DEM_CONFIG_VARIANTS != STD_CONFIG_VARIANTS_POSTBUILD) \
    && (DEM_CFG_AVAILABILITYSUPPORT == DEM_EVENT_AVAILABILITY))
    else if(Dem_EventAvailable[EventId] == FALSE)
    {
        /*SWS_Dem_01108*/
    }
#endif
    else
    {
        /*SWS_Dem_00051*/
        *EventStatusByte = DEM_DTC_STATUS(DEM_CFG_EVENT_DTCREF(EventId));
        *EventStatusByte &= DEM_CFG_DTCSTATUSAVAILABILITYMASK;
        Result = E_OK;
    }
    return Result;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_GetEventFailed
*
* Description: Gets the event failed status of an event.
*
* Inputs: EventId: Identification of an event by assigned EventId.
*
* Outputs: EventFailed: TRUE - Last Failed
*                       FALSE - not Last Failed
*
* Return: E_OK: get of "EventFailed" was successful
*         E_NOT_OK: get of "EventFailed" was not successful
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, DEM_CODE) Dem_GetEventFailed
(
    Dem_EventIdType EventId,
    P2VAR(boolean, AUTOMATIC, DEM_APPL_DATA) EventFailed
)
{
    /*SWS_Dem_00333*/
    Std_ReturnType Result = E_NOT_OK;
    Dem_UdsStatusByteType Status;

    if(Dem_State != DEM_NORMAL)
    {
        /*SWS_Dem_01112*//*SWS_Dem_00124*/
        DEM_DET_REPORT_ERROR(DEM_GETEVENTFAILED_APIID, DEM_E_UNINIT);
    }
    else if(EventFailed == NULL_PTR)
    {
        DEM_DET_REPORT_ERROR(DEM_GETEVENTFAILED_APIID, DEM_E_PARAM_POINTER);
    }
    else if(EventId >= DEM_NUM_OF_EVENT)
    {
        DEM_DET_REPORT_ERROR(DEM_GETEVENTFAILED_APIID, DEM_E_PARAM_DATA);
    }
#if((DEM_CONFIG_VARIANTS != STD_CONFIG_VARIANTS_POSTBUILD) \
    && (DEM_CFG_AVAILABILITYSUPPORT == DEM_EVENT_AVAILABILITY))
    else if(Dem_EventAvailable[EventId] == FALSE)
    {
        /*SWS_Dem_01108*/
    }
#endif
    else
    {
        Status = DEM_DTC_STATUS(DEM_CFG_EVENT_DTCREF(EventId));
        /*SWS_Dem_00052*/
        if((DEM_TEST_UDS_STATUS_TF(Status)) && (!DEM_TEST_UDS_STATUS_TNCTOC(Status)))
        {
            *EventFailed = TRUE;
        }
        else
        {
            *EventFailed = FALSE;
        }
        Result = E_OK;
    }
    return Result;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_GetEventTested
*
* Description: Gets the event tested status of an event.
*
* Inputs: EventId: Identification of an event by assigned EventId.
*
* Outputs: EventTested: TRUE - event tested this cycle
*                       FALSE - event not tested this cycle
*
* Return: E_OK: get of event state "tested" successful
*         E_NOT_OK: get of event state "tested" failed
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, DEM_CODE) Dem_GetEventTested
(
    Dem_EventIdType EventId,
    P2VAR(boolean, AUTOMATIC, DEM_APPL_DATA) EventTested
)
{
    /*SWS_Dem_00333*/
    Std_ReturnType Result = E_NOT_OK;
    Dem_UdsStatusByteType Status;

    if(Dem_State != DEM_NORMAL)
    {
        /*SWS_Dem_01112*//*SWS_Dem_00124*/
        DEM_DET_REPORT_ERROR(DEM_GETEVENTTESTED_APIID, DEM_E_UNINIT);
    }
    else if (EventTested == NULL_PTR)
    {
        DEM_DET_REPORT_ERROR(DEM_GETEVENTTESTED_APIID, DEM_E_PARAM_POINTER);
    }
    else if(EventId >= DEM_NUM_OF_EVENT)
    {
        DEM_DET_REPORT_ERROR(DEM_GETEVENTTESTED_APIID, DEM_E_PARAM_DATA);
    }
#if((DEM_CONFIG_VARIANTS != STD_CONFIG_VARIANTS_POSTBUILD) \
    && (DEM_CFG_AVAILABILITYSUPPORT == DEM_EVENT_AVAILABILITY))
    else if(Dem_EventAvailable[EventId] == FALSE)
    {
        /*SWS_Dem_01108*/
    }
#endif
    else
    {
        Status = DEM_DTC_STATUS(DEM_CFG_EVENT_DTCREF(EventId));
        /*SWS_Dem_00053*/
        if(DEM_TEST_UDS_STATUS_TNCTOC(Status))
        {
            *EventTested = FALSE;
        }
        else
        {
            *EventTested = TRUE;
        }
        Result = E_OK;
    }
    return Result;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_GetDebouncingOfEvent
*
* Description: Gets the debouncing status of an event. This function shall not
*              be used for EventId with native debouncing within their functions.
*              It is rather for EventIds using debouncing within the Dem.
*
* Inputs: EventId: Identification of an event by assigned EventId.
*
* Outputs: DebouncingState
*
* Return: E_OK: get of debouncing status per event state successful
*         E_NOT_OK: get of debouncing per event state failed
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, DEM_CODE) Dem_GetDebouncingOfEvent
(
    Dem_EventIdType EventId,
    P2VAR(Dem_DebouncingStateType, AUTOMATIC, DEM_APPL_DATA) DebouncingState
)
{
    Std_ReturnType Result = E_OK;

    if(Dem_State != DEM_NORMAL)
    {
        /*SWS_Dem_01112*//*SWS_Dem_00124*/
        DEM_DET_REPORT_ERROR(DEM_GETDEBOUNCINGOFEVENT_APIID, DEM_E_UNINIT);
        Result = E_NOT_OK;
    }
    else if (DebouncingState == NULL_PTR)
    {
        DEM_DET_REPORT_ERROR(DEM_GETDEBOUNCINGOFEVENT_APIID, DEM_E_PARAM_POINTER);
        Result = E_NOT_OK;
    }
    else if(EventId >= DEM_NUM_OF_EVENT)
    {
        DEM_DET_REPORT_ERROR(DEM_GETDEBOUNCINGOFEVENT_APIID, DEM_E_PARAM_DATA);
        Result = E_NOT_OK;
    }
#if((DEM_CONFIG_VARIANTS != STD_CONFIG_VARIANTS_POSTBUILD) \
    && (DEM_CFG_AVAILABILITYSUPPORT == DEM_EVENT_AVAILABILITY))
    else if(Dem_EventAvailable[EventId] == FALSE)
    {
        /*SWS_Dem_01108*/
        Result = E_NOT_OK;
    }
#endif
    else
    {
        /*SWS_Dem_00844*/
#if(DEM_CFG_DEBOUNCECOUNTERBASEDSUPPORT == STD_ON)
        if(DEM_CFG_EVENT_DBC(EventId) != NULL_PTR)
        {
            if((DEM_EVENT_DBC(EventId) > 0) \
                    && (DEM_EVENT_DBC(EventId) < DEM_CFG_EVENT_DBC_FAILTHRESHOLD(EventId)))
            {
                *DebouncingState = DEM_TEMPORARILY_DEFECTIVE;
            }
            else if((DEM_EVENT_DBC(EventId) < 0) \
                    && (DEM_EVENT_DBC(EventId) > DEM_CFG_EVENT_DBC_PASSTHRESHOLD(EventId)))
            {
                *DebouncingState = DEM_TEMPORARILY_HEALED;
            }
            else if(DEM_EVENT_DBC(EventId) <= DEM_CFG_EVENT_DBC_PASSTHRESHOLD(EventId))
            {
                *DebouncingState = DEM_TEST_COMPLETE;
            }
            else if(DEM_EVENT_DBC(EventId) >= DEM_CFG_EVENT_DBC_FAILTHRESHOLD(EventId))
            {
                if(DEM_DTC_DATAENTRYREF(DEM_CFG_EVENT_DTCREF(EventId)) == DEM_DATA_INVALID_U16)
                {
                    *DebouncingState = DEM_FINALLY_DEFECTIVE;
                }
                else
                {
                    *DebouncingState = DEM_DTR_UPDATE;
                }
            }
            else
            {
                Result = E_NOT_OK;
            }
        }
#endif

#if(DEM_CFG_DEBOUNCETIMEBASEDSUPPORT == STD_ON)
        if(DEM_CFG_EVENT_DBT(EventId) != NULL_PTR)
        {
            if(DEM_EVENT_TIMERDIRECTION(EventId) == DEM_EVENT_STATUS_PREFAILED)
            {
                *DebouncingState = DEM_TEMPORARILY_DEFECTIVE;
            }
            else if(DEM_EVENT_TIMERDIRECTION(EventId) == DEM_EVENT_STATUS_PREPASSED)
            {
                *DebouncingState = DEM_TEMPORARILY_HEALED;
            }
            else if(DEM_EVENT_TIMERDIRECTION(EventId) == DEM_EVENT_STATUS_PASSED)
            {
                *DebouncingState = DEM_TEST_COMPLETE;
            }
            else if(DEM_EVENT_TIMERDIRECTION(EventId) == DEM_EVENT_STATUS_FAILED)
            {
                if(DEM_DTC_DATAENTRYREF(DEM_CFG_EVENT_DTCREF(EventId)) == DEM_DATA_INVALID_U16)
                {
                    *DebouncingState = DEM_FINALLY_DEFECTIVE;
                }
                else
                {
                    *DebouncingState = DEM_DTR_UPDATE;
                }
            }
            else
            {
                Result = E_NOT_OK;
            }
        }
#endif
    }
    return Result;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_GetDTCOfEvent
*
* Description: Gets the DTC of an event.
*
* Inputs: EventId: Identification of an event by assigned EventId.
*         DTCFormat: Defines the output-format of the requested DTC value.
*
* Outputs: DTCOfEvent: Receives the DTC value in respective format returned by
*                      this function. If the return value of the function is
*                      other than E_OK this parameter does not contain valid data.
*
* Return: E_OK: get of DTC was successful
*         E_NOT_OK: the call was not successful
*         DEM_E_NO_DTC_AVAILABLE: there is no DTC configured in the requested
*                                 format
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, DEM_CODE) Dem_GetDTCOfEvent
(
    Dem_EventIdType EventId,
    Dem_DTCFormatType DTCFormat,
    P2VAR(uint32, AUTOMATIC, DEM_APPL_DATA) DTCOfEvent
)
{
    Std_ReturnType Result = E_OK;

    if(EventId >= DEM_NUM_OF_EVENT)
    {
        DEM_DET_REPORT_ERROR(DEM_GETDTCOFEVENT_APIID, DEM_E_PARAM_DATA);
        Result = E_NOT_OK;
    }
#if((DEM_CONFIG_VARIANTS != STD_CONFIG_VARIANTS_POSTBUILD) \
    && (DEM_CFG_AVAILABILITYSUPPORT == DEM_EVENT_AVAILABILITY))
    else if(Dem_EventAvailable[EventId] == FALSE)
    {
        /*SWS_Dem_01108*/
        Result = E_NOT_OK;
    }
#endif
    else
    {
        if(DTCFormat == DEM_DTC_FORMAT_UDS)
        {
            if(DEM_CFG_DTC_VALUE(DEM_CFG_EVENT_DTCREF(EventId)) != (uint32)0)
            {
                *DTCOfEvent = DEM_CFG_DTC_VALUE(DEM_CFG_EVENT_DTCREF(EventId));
            }
        }
#if((DEM_CFG_OBD_SUPPORT == DEM_OBD_MASTER_ECU)||(DEM_CFG_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU))
        else if(DTCFormat == DEM_DTC_FORMAT_OBD)
        {
            if((DEM_CFG_DTC_OBDDTCREF(DEM_CFG_EVENT_DTCREF(EventId)) != NULL_PTR) \
                && (DEM_CFG_DTC_OBD_VALUE(DEM_CFG_EVENT_DTCREF(EventId)) != (uint16)0))
            {
                *DTCOfEvent = (uint32)DEM_CFG_DTC_OBD_VALUE(DEM_CFG_EVENT_DTCREF(EventId));
            }
        }
#endif
#if(DEM_J1939_SUPPORT == STD_ON)
        else if(DTCFormat == DEM_DTC_FORMAT_J1939)
        {
            if((DEM_CFG_DTC_OBDDTCREF(DEM_CFG_EVENT_DTCREF(EventId)) != NULL_PTR) \
                && (DEM_CFG_DTC_J1939_VALUE(DEM_CFG_EVENT_DTCREF(EventId)) != (uint32)0))
            {
                *DTCOfEvent = DEM_CFG_DTC_J1939_VALUE(DEM_CFG_EVENT_DTCREF(EventId));
            }
        }
#endif
        else
        {
            Result = E_NOT_OK;
        }
    }
    return Result;
}

#if(DEM_NUM_OF_EN_CONDITION > 0)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_SetEnableCondition
*
* Description: Sets an enable condition.
*
* Inputs: EnableConditionID: This parameter identifies the enable condition.
*         ConditionFulfilled: This parameter specifies whether the enable
*                             condition assigned to the EnableConditionID is
*                             fulfilled (TRUE) or not fulfilled (FALSE).
*
* Outputs: None
*
* Return: E_OK: the enable condition could be set successfully
*         E_NOT_OK: the setting of the enable condition failed
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, DEM_CODE) Dem_SetEnableCondition
(
    uint8 EnableConditionID,
    boolean ConditionFulfilled
)
{
    /*SWS_Dem_00202*/
    Std_ReturnType Result = E_OK;
    Dem_EventIdType EventId;
    uint8 i;

    if(Dem_State != DEM_NORMAL)
    {
        /*SWS_Dem_01112*//*SWS_Dem_00124*/
        DEM_DET_REPORT_ERROR(DEM_SETENABLECONDITION_APIID, DEM_E_UNINIT);
        Result = E_NOT_OK;
    }
    else if(EnableConditionID >= DEM_NUM_OF_EN_CONDITION)
    {
        DEM_DET_REPORT_ERROR(DEM_SETENABLECONDITION_APIID, DEM_E_PARAM_DATA);
        Result = E_NOT_OK;
    }
    else
    {
        if(ConditionFulfilled == TRUE)
        {
            Dem_EventEnCondition[EnableConditionID] = TRUE;
        }
        else
        {
            Dem_EventEnCondition[EnableConditionID] = FALSE;
#if(DEM_NUM_OF_EN_GROUP > 0)
            for(EventId = 0; EventId < DEM_NUM_OF_EVENT; EventId++)
            {
                if(DEM_CFG_EVENT_EN(EventId) != NULL_PTR)
                {
                    for(i = 0; i < DEM_CFG_EVENT_EN_NUM(EventId); i++)
                    {
                        if((DEM_CFG_EVENT_EN_REF(EventId)[i]) == EnableConditionID)
                        {
                            /*SWS_Dem_00654*/
#if(DEM_CFG_DEBOUNCECOUNTERBASEDSUPPORT == STD_ON)
                            if((DEM_CFG_EVENT_DBC(EventId) != NULL_PTR) \
                                && (DEM_CFG_EVENT_DBC_BEHAVIOR(EventId) == DEM_DEBOUNCE_RESET))
                            {
                                DEM_EVENT_DBC(EventId) = 0;
                            }
#endif
#if(DEM_CFG_DEBOUNCETIMEBASEDSUPPORT == STD_ON)
                            if((DEM_CFG_EVENT_DBT(EventId) != NULL_PTR) \
                                && (DEM_CFG_EVENT_DBT_BAHAVIOR(EventId) == DEM_DEBOUNCE_RESET))
                            {
                                DEM_EVENT_DBT(EventId) = 0;
                                DEM_EVENT_TIMERDIRECTION(EventId) = DEM_DATA_INVALID_U8;
                            }
#endif
                            break;
                        }
                    }
                }/*if(DEM_CFG_EVENT_EN(EventId) != NULL_PTR)*/
            }
#endif
        }
    }
    return Result;
}
#endif/*#if(DEM_NUM_OF_EN_CONDITION > 0)*/

#if(DEM_NUM_OF_STOR_CONDITION > 0)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_SetStorageCondition
*
* Description: Sets a storage condition.
*
* Inputs: StorageConditionID: This parameter identifies the storage condition.
*         ConditionFulfilled: This parameter specifies whether the storage
*                             condition assigned to the StorageConditionID is
*                             fulfilled (TRUE) or not fulfilled (FALSE).
*
* Outputs: None
*
* Return: E_OK: the storage condition could be set successfully
*         E_NOT_OK: the setting of the storage condition failed
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, DEM_CODE) Dem_SetStorageCondition
(
    uint8 StorageConditionID,
    boolean ConditionFulfilled
)
{
    /*SWS_Dem_00543*/
    Std_ReturnType Result = E_NOT_OK;

    if(Dem_State != DEM_NORMAL)
    {
        /*SWS_Dem_01112*//*SWS_Dem_00124*/
        DEM_DET_REPORT_ERROR(DEM_SETSTORAGECONDITION_APIID, DEM_E_UNINIT);
        Result = E_NOT_OK;
    }
    else if(StorageConditionID >= DEM_NUM_OF_STOR_CONDITION)
    {
        DEM_DET_REPORT_ERROR(DEM_SETSTORAGECONDITION_APIID, DEM_E_PARAM_DATA);
        Result = E_NOT_OK;
    }
    else
    {
        if(ConditionFulfilled == TRUE)
        {
            Dem_EventStorCondition[StorageConditionID] = TRUE;
        }
        else
        {
            Dem_EventStorCondition[StorageConditionID] = FALSE;
        }
    }
    return Result;
}
#endif
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_GetFaultDetectionCounter
*
* Description: Gets the fault detection counter of an event. This API can only
*              be used through the RTE, and therefore no declaration is exported
*              via Dem.h.
*
* Inputs: EventId: Identification of an event by assigned EventId.
*
* Outputs: FaultDetectionCounter: This parameter receives the Fault Detection
*                                 Counter information of the requested EventId. 
*                                 If the return value of the function call is
*                                 other than E_OK this parameter does not
*                                 contain valid data.
*
* Return: E_OK: request was successful
*         E_NOT_OK: request failed
*         DEM_E_NO_FDC_AVAILABLE: there is no fault detection counter available
*                                 for the requested event.
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, DEM_CODE) Dem_GetFaultDetectionCounter
(
    Dem_EventIdType EventId,
    P2VAR(sint8, AUTOMATIC, DEM_APPL_DATA) FaultDetectionCounter
)
{
    Std_ReturnType Result = E_OK;

    if(Dem_State != DEM_NORMAL)
    {
        /*SWS_Dem_01112*//*SWS_Dem_00124*/
        DEM_DET_REPORT_ERROR(DEM_GETFAULTDETECTIONCOUNTER_APIID, DEM_E_UNINIT);
        Result = E_NOT_OK;
    }
    else if(EventId >= DEM_NUM_OF_EVENT)
    {
        DEM_DET_REPORT_ERROR(DEM_GETFAULTDETECTIONCOUNTER_APIID, DEM_E_PARAM_DATA);
        Result = E_NOT_OK;
    }
    else if(FaultDetectionCounter == NULL_PTR)
    {
        DEM_DET_REPORT_ERROR(DEM_GETFAULTDETECTIONCOUNTER_APIID, DEM_E_PARAM_POINTER);
        Result = E_NOT_OK;
    }
#if((DEM_CONFIG_VARIANTS != STD_CONFIG_VARIANTS_POSTBUILD) \
    && (DEM_CFG_AVAILABILITYSUPPORT == DEM_EVENT_AVAILABILITY))
    else if(Dem_EventAvailable[EventId] == FALSE)
    {
        /*SWS_Dem_01108*/
        Result = E_NOT_OK;
    }
#endif
    else
    {
        /*SWS_Dem_00204*/
#if(DEM_CFG_DEBOUNCECOUNTERBASEDSUPPORT == STD_ON)
        if(DEM_CFG_EVENT_DBC(EventId) != NULL_PTR)
        {
            if(DEM_EVENT_DBC(EventId) >= 0)
            {
                *FaultDetectionCounter = DEM_EVENT_DBC_F_FDC(EventId);
            }
            else
            {
                *FaultDetectionCounter = DEM_EVENT_DBC_P_FDC(EventId);
            }
        }
        else
#endif
#if(DEM_CFG_DEBOUNCETIMEBASEDSUPPORT == STD_ON)
        if(DEM_CFG_EVENT_DBT(EventId) != NULL_PTR)
        {
            if((DEM_EVENT_TIMERDIRECTION(EventId) == DEM_EVENT_STATUS_FAILED) \
                    || (DEM_EVENT_TIMERDIRECTION(EventId) == DEM_EVENT_STATUS_PREFAILED))
            {
                *FaultDetectionCounter = DEM_EVENT_DBT_F_FDC(EventId);
            }
            else if((DEM_EVENT_TIMERDIRECTION(EventId) == DEM_EVENT_STATUS_PASSED) \
                    || (DEM_EVENT_TIMERDIRECTION(EventId) == DEM_EVENT_STATUS_PREPASSED))
            {
                *FaultDetectionCounter = DEM_EVENT_DBT_P_FDC(EventId);
            }
            else
            {
                *FaultDetectionCounter = 0;
            }
        }
        else
#endif
        if(DEM_CFG_EVENT_GET_FDC_FNC(EventId) != NULL_PTR)
        {
            /*SWS_Dem_00264*//*SWS_Dem_00439*/
            Result = DEM_CFG_EVENT_GET_FDC_FNC(EventId)(FaultDetectionCounter);
        }
        else
        {
            /*SWS_Dem_00671*/
            Result = DEM_E_NO_FDC_AVAILABLE;
        }
    }
    return Result;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_GetIndicatorStatus
*
* Description: Gets the indicator status derived from the event status.
*
* Inputs: IndicatorId: Number of indicator
*
* Outputs: IndicatorStatus: Status of the indicator, like off, on, or blinking.
*
* Return: E_OK: Operation was successful
*         E_NOT_OK: Operation failed
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, DEM_CODE) Dem_GetIndicatorStatus
(
    uint8 IndicatorId,
    P2VAR(Dem_IndicatorStatusType, AUTOMATIC, DEM_APPL_DATA) IndicatorStatus
)
{
    /*SWS_Dem_00046*/
    Std_ReturnType Result = E_NOT_OK;

    if(Dem_State != DEM_NORMAL)
    {
        /*SWS_Dem_01112*//*SWS_Dem_00124*/
        DEM_DET_REPORT_ERROR(DEM_GETINDICATORSTATUS_APIID, DEM_E_UNINIT);
    }
    else if(IndicatorId >= DEM_NUM_OF_INDICATOR)
    {
        DEM_DET_REPORT_ERROR(DEM_GETINDICATORSTATUS_APIID, DEM_E_PARAM_DATA);
    }
    else if(IndicatorStatus == NULL_PTR)
    {
        DEM_DET_REPORT_ERROR(DEM_GETINDICATORSTATUS_APIID, DEM_E_PARAM_POINTER);
    }
    else
    {
#if(DEM_NUM_OF_INDICATOR > 0)
        DemInternal_GetIndicatorStatus(IndicatorId, IndicatorStatus);
        Result = E_OK;
#endif
    }    
    return Result;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_GetEventFreezeFrameData
*
* Description: Gets the data of a freeze frame by event.
*
* Inputs: EventId: Identification of an event by assigned EventId.
*         RecordNumber: This parameter is a unique identifier for a freeze frame
*                       record as defined in ISO14229-1. 0xFF means most recent
*                       freeze frame record is returned.
*                       0x00 is only supported if the Dem module supports WWH-OBD
*                       (refer to DemOBDSupport)
*         ReportTotalRecord: This parameter is obsolete and shall be set to FALSE.
*                            This function requests a single PID/DID.
*         DataId: This parameter specifies the DID (ISO14229-1) that shall be
*                 copied to the destination buffer.
*
* Outputs: DestBuffer: This parameter contains a byte pointer that points to the
*                      buffer, to which the freeze frame data record shall be written
*                      to. The format is raw hexadecimal values and contains no
*                      header-information.
*
* Return: E_OK: Operation was successful
*         E_NOT_OK: Operation could not be performed
*         DEM_E_NODATAAVAILABLE: The requested event data is not currently stored
*                                (but the request was valid)
*         DEM_E_WRONG_RECORDNUMBER: The requested record number is not supported by
*                                   the event
*         DEM_E_WRONG_DIDNUMBER: The requested DID is not supported by the freeze frame
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, DEM_CODE) Dem_GetEventFreezeFrameData
(
    Dem_EventIdType EventId,
    uint8 RecordNumber,
    boolean ReportTotalRecord,
    uint16 DataId,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DestBuffer
)
{
    Std_ReturnType Result = E_NOT_OK;
    uint16 DataSize = DEM_MAX_FFSIZE_OF_DTC;

    if(Dem_State != DEM_NORMAL)
    {
        /*SWS_Dem_01112*//*SWS_Dem_00124*/
        DEM_DET_REPORT_ERROR(DEM_GETEVENTFREEZEFRAMEDATA_APIID, DEM_E_UNINIT);
    }
    else if(EventId >= DEM_NUM_OF_EVENT)
    {
        DEM_DET_REPORT_ERROR(DEM_GETEVENTFREEZEFRAMEDATA_APIID, DEM_E_PARAM_DATA);
    }
    else if(DestBuffer == NULL_PTR)
    {
        DEM_DET_REPORT_ERROR(DEM_GETEVENTFREEZEFRAMEDATA_APIID, DEM_E_PARAM_POINTER);
    }
#if((DEM_CONFIG_VARIANTS != STD_CONFIG_VARIANTS_POSTBUILD) \
    && (DEM_CFG_AVAILABILITYSUPPORT == DEM_EVENT_AVAILABILITY))
    else if(Dem_EventAvailable[EventId] == FALSE)
    {
        /*Result = E_NOT_OK;*/
    }
#endif
    else if(DEM_DTC_DATAENTRYREF(DEM_CFG_EVENT_DTCREF(EventId)) == DEM_DATA_INVALID_U16)
    {
        /*Result = E_NOT_OK;*/
    }
    else
    {
        Result = DemInternal_GetEventFreezeFrameDataEx(EventId, RecordNumber, DataId, DestBuffer, &DataSize);
    }
    return Result;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_GetEventFreezeFrameDataEx
*
* Description: Gets the data of a freeze frame by event.
*
* Inputs: EventId: Identification of an event by assigned EventId.
*         RecordNumber: This parameter is a unique identifier for a freeze frame
*                       record as defined in ISO14229-1. 0xFF means most recent
*                       freeze frame record is returned. 0x00 is only supported
*                       if the Dem module supports WWH-OBD (refer to DemOBDSupport)
*         DataId: This parameter specifies the DID (ISO14229-1) that shall be
*                 copied to the destination buffer.
*         BufSize: When the function is called this parameter contains the maximum
*                  number of data bytes that can be written to the buffer.
*
* Outputs: BufSize: The function returns the actual number of written data bytes
*                   in this parameter.
*          DestBuffer: This parameter contains a byte pointer that points to the
*                      buffer, to which the freeze frame data record shall be
*                      written to. The format is raw hexadecimal values and
*                      contains no header-information.
*
* Return: E_OK: Operation was successful
*         E_NOT_OK: Operation could not be performed
*         DEM_E_NODATAAVAILABLE: The requested event data is not currently stored
*                                (but the request was valid)
*         DEM_E_WRONG_RECORDNUMBER: The requested record number is not supported
*                                   by the event
*         DEM_E_WRONG_DIDNUMBER: The requested DID is not supported by the freeze
*                                frame
*         DEM_E_WRONG_BUFFERSIZE: The provided buffer size is too small
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, DEM_CODE) Dem_GetEventFreezeFrameDataEx
(
    Dem_EventIdType EventId,
    uint8 RecordNumber,
    uint16 DataId,
    uint8 *DestBuffer,
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) BufSize
)
{
    /*SWS_Dem_01062*//*SWS_Dem_00479*//*SWS_Dem_00995*/
    Std_ReturnType Result = E_NOT_OK;

    if(Dem_State != DEM_NORMAL)
    {
        /*SWS_Dem_01112*//*SWS_Dem_00124*/
        DEM_DET_REPORT_ERROR(DEM_GETEVENTFREEZEFRAMEDATAEX_APIID, DEM_E_UNINIT);
    }
    else if(EventId >= DEM_NUM_OF_EVENT)
    {
        DEM_DET_REPORT_ERROR(DEM_GETEVENTFREEZEFRAMEDATAEX_APIID, DEM_E_PARAM_DATA);
    }
    else if((DestBuffer == NULL_PTR) || (BufSize == NULL_PTR) || (*BufSize == 0))
    {
        DEM_DET_REPORT_ERROR(DEM_GETEVENTFREEZEFRAMEDATAEX_APIID, DEM_E_PARAM_POINTER);
    }
#if((DEM_CONFIG_VARIANTS != STD_CONFIG_VARIANTS_POSTBUILD) \
    && (DEM_CFG_AVAILABILITYSUPPORT == DEM_EVENT_AVAILABILITY))
    else if(Dem_EventAvailable[EventId] == FALSE)
    {
        /*SWS_Dem_00996*//*SWS_Dem_01108*/
    }
#endif
    else if(DEM_DTC_DATAENTRYREF(DEM_CFG_EVENT_DTCREF(EventId)) == DEM_DATA_INVALID_U16)
    {
        /*Result = E_NOT_OK;*/
    }
    else
    {
        Result = DemInternal_GetEventFreezeFrameDataEx(EventId, RecordNumber, DataId, DestBuffer, BufSize);
    }
    return Result;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_GetEventExtendedDataRecord
*
* Description: Gets the data of an extended data record by event.
*
* Inputs: EventId: Identification of an event by assigned EventId.
*         RecordNumber: Identification of requested Extended data record.Valid
*                       values are between 0x01 and 0xEF as defined in ISO14229-1.
*
* Outputs: DestBuffer: This parameter contains a byte pointer that points to the
*                      buffer, to which the freeze frame data record shall be
*                      written to. The format is raw hexadecimal values and
*                      contains no header-information.
*
* Return: E_OK: Operation was successful
*         E_NOT_OK: Operation could not be performed
*         DEM_E_NODATAAVAILABLE: The requested event data is not currently stored
*                                (but the request was valid)
*         DEM_E_WRONG_RECORDNUMBER: The requested record number is not supported
*                                   by the event
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, DEM_CODE) Dem_GetEventExtendedDataRecord
(
    Dem_EventIdType EventId,
    uint8 RecordNumber,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DestBuffer
)
{
    Std_ReturnType Result = E_NOT_OK;
    uint16 DataSize = DEM_MAX_EXTSIZE_OF_DTC;

    if(Dem_State != DEM_NORMAL)
    {
        /*SWS_Dem_01112*//*SWS_Dem_00124*/
        DEM_DET_REPORT_ERROR(DEM_GETEVENTEXTENDEDDATARECORD_APIID, DEM_E_UNINIT);
    }
    else if(EventId >= DEM_NUM_OF_EVENT)
    {
        DEM_DET_REPORT_ERROR(DEM_GETEVENTEXTENDEDDATARECORD_APIID, DEM_E_PARAM_DATA);
    }
    else if(DestBuffer == NULL_PTR)
    {
        DEM_DET_REPORT_ERROR(DEM_GETEVENTEXTENDEDDATARECORD_APIID, DEM_E_PARAM_POINTER);
    }
#if((DEM_CONFIG_VARIANTS != STD_CONFIG_VARIANTS_POSTBUILD) \
    && (DEM_CFG_AVAILABILITYSUPPORT == DEM_EVENT_AVAILABILITY))
    else if(Dem_EventAvailable[EventId] == FALSE)
    {
        /*Result = E_NOT_OK;*/
    }
#endif
    else if(DEM_DTC_DATAENTRYREF(DEM_CFG_EVENT_DTCREF(EventId)) == DEM_DATA_INVALID_U16)
    {
        /*Result = E_NOT_OK;*/
    }
    else
    {
        Result = DemInternal_GetEventExtendedDataRecordEx(EventId, RecordNumber, DestBuffer, &DataSize);
    }
    return Result;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_GetEventExtendedDataRecordEx
*
* Description: Gets the data of an extended data record by event.
*
* Inputs: EventId: Identification of an event by assigned EventId.
*         RecordNumber: Identification of requested Extended data record.Valid
*                       values are between 0x01 and 0xEF as defined in ISO14229-1.
*         BufSize: When the function is called this parameter contains the maximum
*                  number of data bytes that can be written to the buffer.
*
* Outputs: BufSize: The function returns the actual number of written data bytes in
*                   this parameter.
*          DestBuffer: This parameter contains a byte pointer that points to the
*                      buffer, to which the freeze frame data record shall be written
*                      to. The format is raw hexadecimal values and contains no
*                      header-information.
*
* Return: E_OK: Operation was successful
*         E_NOT_OK: Operation could not be performed
*         DEM_E_NODATAAVAILABLE: The requested event data is not currently stored
*                                (but the request was valid)
*         DEM_E_WRONG_RECORDNUMBER: The requested record number is not supported
*                                   by the event
*         DEM_E_WRONG_BUFFERSIZE: The provided buffer size is too small
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, DEM_CODE) Dem_GetEventExtendedDataRecordEx
(
    Dem_EventIdType EventId,
    uint8 RecordNumber,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DestBuffer,
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) BufSize
)
{
    /*SWS_Dem_01062*//*SWS_Dem_00477*//*SWS_Dem_00995*/
    Std_ReturnType Result = E_NOT_OK;

    if(Dem_State != DEM_NORMAL)
    {
        /*SWS_Dem_01112*//*SWS_Dem_00124*/
        DEM_DET_REPORT_ERROR(DEM_GETEVENTEXTENDEDDATARECORDEX_APIID, DEM_E_UNINIT);
    }
    else if(EventId >= DEM_NUM_OF_EVENT)
    {
        DEM_DET_REPORT_ERROR(DEM_GETEVENTEXTENDEDDATARECORDEX_APIID, DEM_E_PARAM_DATA);
    }
    else if((DestBuffer == NULL_PTR) || (BufSize == NULL_PTR) || (*BufSize == 0))
    {
        DEM_DET_REPORT_ERROR(DEM_GETEVENTEXTENDEDDATARECORDEX_APIID, DEM_E_PARAM_POINTER);
    }
#if((DEM_CONFIG_VARIANTS != STD_CONFIG_VARIANTS_POSTBUILD) \
    && (DEM_CFG_AVAILABILITYSUPPORT == DEM_EVENT_AVAILABILITY))
    else if(Dem_EventAvailable[EventId] == FALSE)
    {
        /*SWS_Dem_00997*//*SWS_Dem_01108*/
    }
#endif
    else if(DEM_DTC_DATAENTRYREF(DEM_CFG_EVENT_DTCREF(EventId)) == DEM_DATA_INVALID_U16)
    {
        /*Result = E_NOT_OK;*/
    }
    else
    {
        Result = DemInternal_GetEventExtendedDataRecordEx(EventId, RecordNumber, DestBuffer, BufSize);
    }
    return Result;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_GetEventMemoryOverflow
*
* Description: Control the internal debounce counter/timer by BSW modules and SWCs.
*              The event qualification will not be affected by these debounce state
*              changes. This API is available for BSW modules as soon as Dem_PreInit
*              has been completed
*
* Inputs: DTCOrigin: If the Dem supports more than one event memory this parameter
*                    is used to select the source memory the overflow indication
*                    shall be read from.
*
* Outputs: OverflowIndication: This parameter returns TRUE if the according event
*                              memory was overflowed, otherwise it returns FALSE.
*
* Return: E_OK: Operation was successful
*         E_NOT_OK: Operation failed or is not supported
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, DEM_CODE) Dem_GetEventMemoryOverflow
(
    Dem_DTCOriginType DTCOrigin,
    P2VAR(boolean, AUTOMATIC, DEM_APPL_DATA) OverflowIndication
)
{
    /*SWS_Dem_00397*//*SWS_Dem_00398*/
    Std_ReturnType Result = E_OK;

    if(Dem_State != DEM_NORMAL)
    {
        /*SWS_Dem_01112*//*SWS_Dem_00124*/
        DEM_DET_REPORT_ERROR(DEM_GETEVENTMEMORYOVERFLOW_APIID, DEM_E_UNINIT);
        Result = E_NOT_OK;
    }
    else if(OverflowIndication == NULL_PTR)
    {
        DEM_DET_REPORT_ERROR(DEM_GETEVENTMEMORYOVERFLOW_APIID, DEM_E_PARAM_POINTER);
        Result = E_NOT_OK;
    }
    else
    {
        if(DTCOrigin == DEM_DTC_ORIGIN_PRIMARY_MEMORY)
        {
            if(DEM_PRIMARY_DATAENTRY_USEDNUM < DEM_CFG_MAXNUMBEREVENTENTRY_PRIMARY)
            {
                *OverflowIndication = FALSE;
            }
            else
            {
                *OverflowIndication = TRUE;
            }
        }
#if(DEM_CFG_MAXNUMBEREVENTENTRY_PERMANENT > 0)
        else if(DTCOrigin == DEM_DTC_ORIGIN_PERMANENT_MEMORY)
        {
            if(DEM_PERMANENT_DATAENTRY_USEDNUM < DEM_CFG_MAXNUMBEREVENTENTRY_PERMANENT)
            {
                *OverflowIndication = FALSE;
            }
            else
            {
                *OverflowIndication = TRUE;
            }
        }
#endif
        else
        {
            Result = E_NOT_OK;
        }
    }
    return Result;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_GetNumberOfEventMemoryEntries
*
* Description: Returns the number of entries currently stored in the requested
*              event memory.
*
* Inputs: DTCOrigin: If the Dem supports more than one event memory this parameter
*                    is used to select the source memory the number of entries
*                    shall be read from.
*
* Outputs: NumberOfEventMemoryEntries: Number of entries currently stored in the
*                                      requested event memory.
*
* Return: E_OK: Operation was successful
*         E_NOT_OK: Operation failed
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, DEM_CODE) Dem_GetNumberOfEventMemoryEntries
(
    Dem_DTCOriginType DTCOrigin,
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) NumberOfEventMemoryEntries
)
{
    /*SWS_Dem_00651*/
    Std_ReturnType Result = E_OK;

    if(Dem_State != DEM_NORMAL)
    {
        /*SWS_Dem_01112*//*SWS_Dem_00124*/
        DEM_DET_REPORT_ERROR(DEM_GETNUMBEROFEVENTMEMORYENTRIES_APIID, DEM_E_UNINIT);
        Result = E_NOT_OK;
    }
    else if(NumberOfEventMemoryEntries == NULL_PTR)
    {
        DEM_DET_REPORT_ERROR(DEM_GETNUMBEROFEVENTMEMORYENTRIES_APIID, DEM_E_PARAM_POINTER);
        Result = E_NOT_OK;
    }
    else
    {
        if(DTCOrigin == DEM_DTC_ORIGIN_PRIMARY_MEMORY)
        {
            *NumberOfEventMemoryEntries = DEM_PRIMARY_DATAENTRY_USEDNUM;
        }
#if(DEM_CFG_MAXNUMBEREVENTENTRY_PERMANENT > 0)
        else if(DTCOrigin == DEM_DTC_ORIGIN_PERMANENT_MEMORY)
        {
            *NumberOfEventMemoryEntries = DEM_PERMANENT_DATAENTRY_USEDNUM;
        }
#endif
        else
        {
            Result = E_NOT_OK;
        }
    }
    return Result;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_SetComponentAvailable
*
* Description: Set the availability of a specific DemComponent.
*
* Inputs: ComponentId: Identification of a DemComponent.
*         AvailableStatus: This parameter specifies whether the respective
*                          Component shall be available (TRUE) or not (FALSE).
*
* Outputs: None
*
* Return: E_OK: Operation was successful
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, DEM_CODE) Dem_SetComponentAvailable
(
    Dem_ComponentIdType ComponentId,
    boolean AvailableStatus
)
{
    Std_ReturnType Result = E_NOT_OK;
    (void)ComponentId;
    (void)AvailableStatus;


    return Result;
}

#if(DEM_CFG_SUPPRESSIONSUPPORT == DEM_DTC_SUPPRESSION)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_SetDTCSuppression
*
* Description: Set the suppression status of a specific DTC.
*
* Inputs: DTC: Diagnostic Trouble Code
*         DTCFormat: Defines the input-format of the provided DTC value.
*         SuppressionStatus: This parameter specifies whether the respective DTC
*                            shall be disabled (TRUE) or enabled (FALSE).
*
* Outputs: None
*
* Return: E_OK: Operation was successful
*         E_NOT_OK: operation failed or event entry for this DTC still exists
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, DEM_CODE) Dem_SetDTCSuppression
(
    uint32 DTC,
    Dem_DTCFormatType DTCFormat,
    boolean SuppressionStatus
)
{
    Std_ReturnType Result = E_NOT_OK;


    return Result;
}
#endif

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_ClearDTC
*
* Description: Clears single DTCs, as well as groups of DTCs. This API is intended
*              for complex device driver. It can only be used through the RTE (due
*              to work-around described below SWS_Dem_00659), and therefore no
*              declaration is exported via Dem.h.
*
* Inputs: DTC: Defines the DTC in respective format, that shall be cleared from
*              the event memory.If the DTC fits to a DTC group number, all DTCs
*              of the group shall be cleared.
*         DTCFormat: Defines the input-format of the provided DTC value.
*         DTCOrigin: If the Dem supports more than one event memory this parameter
*                    is used to select the source memory the DTCs shall be read from.
*
* Outputs: None
*
* Return: Dem_ReturnClearDTCType
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Dem_ReturnClearDTCType, DEM_CODE) Dem_ClearDTC
(
    uint32 DTC,
    Dem_DTCFormatType DTCFormat,
    Dem_DTCOriginType DTCOrigin
)
{
    /*SWS_Dem_00659*/
    Dem_ReturnClearDTCType Result = DEM_CLEAR_OK;
#if(DEM_CFG_CLEARDTCLIMITATION != DEM_ONLY_CLEAR_ALL_DTCS)
    uint16 DtcIndex;
#endif

    if(Dem_State != DEM_NORMAL)
    {
        DEM_DET_REPORT_ERROR(DEM_CLEARDTC_APIID, DEM_E_UNINIT);
        Result = DEM_CLEAR_FAILED;
    }
    /*SWS_Dem_01042*/
    else if(Dem_ClearDTCState == DEM_IN_CLEAR_DTC_IDLE)
    {
        if((DTC == (uint32)0) || (DTC > DEM_DTC_GROUP_ALL))
        {
            DEM_DET_REPORT_ERROR(DEM_CLEARDTC_APIID, DEM_E_PARAM_DATA);
            Result = DEM_CLEAR_WRONG_DTC;
        }
        else if((DTCFormat != DEM_DTC_FORMAT_OBD) \
            && (DTCFormat != DEM_DTC_FORMAT_UDS) \
            && (DTCFormat != DEM_DTC_FORMAT_J1939))
        {
            DEM_DET_REPORT_ERROR(DEM_CLEARDTC_APIID, DEM_E_PARAM_DATA);
            Result = DEM_CLEAR_FAILED;
        }
        else if(DTCOrigin != DEM_DTC_ORIGIN_PRIMARY_MEMORY)
        {
            DEM_DET_REPORT_ERROR(DEM_CLEARDTC_APIID, DEM_E_PARAM_DATA);
            Result = DEM_CLEAR_WRONG_DTCORIGIN;
        }
#if(DEM_CFG_CLEARDTCLIMITATION == DEM_ONLY_CLEAR_ALL_DTCS)
        else if(DTC != DEM_DTC_GROUP_ALL)
        {
            /*SWS_Dem_00670*/
            Result = DEM_CLEAR_WRONG_DTC;
        }
#endif
        else
        {
            /*SWS_Dem_00661*//*SWS_Dem_00569*/
            Dem_ClearDTC_DTC = DTC;
            Dem_ClearDTC_DTCFormat = DTCFormat;
            Dem_ClearDTC_DTCOrigin = DTCOrigin;
            Dem_ClearDTC_Index = DEM_DATA_CLEAR;

#if(DEM_CFG_CLEARDTCLIMITATION != DEM_ONLY_CLEAR_ALL_DTCS)
            /*Check if the request DTC is a group DTC.*/
            for(DtcIndex = 0; DtcIndex < DEM_NUM_OF_DTCGROUP; DtcIndex++)
            {
                if(DTC == DEM_CFG_DTC_GROUPVALUE(DtcIndex))
                {
                    /*Clear RAM info of one DTC group in main function*/
                    Dem_ClearDTCState = DEM_IN_CLEAR_DTC_GROUP;
                    Result = DEM_CLEAR_PENDING;
                    break;
                }
            }

            /*if the request DTC not a group DTC, it should be a single DTC.*/
            if(Result != DEM_CLEAR_PENDING)
            {
                /*SWS_Dem_00172*/
                Result = DEM_CLEAR_WRONG_DTC;
                for(DtcIndex = 0; DtcIndex < DEM_NUM_OF_DTC; DtcIndex++)
                {
                    if(((DTCFormat == DEM_DTC_FORMAT_UDS) && (DTC == DEM_CFG_DTC_VALUE(DtcIndex)))
#if((DEM_CFG_OBD_SUPPORT == DEM_OBD_MASTER_ECU)||(DEM_CFG_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU))
                        || ((DTCFormat == DEM_DTC_FORMAT_OBD) && (DEM_CFG_DTC_OBDDTCREF(DtcIndex) != NULL_PTR) \
                            && (DTC == DEM_CFG_DTC_OBD_VALUE(DtcIndex)))
#endif
#if(DEM_J1939_SUPPORT == STD_ON)
                        || ((DTCFormat == DEM_DTC_FORMAT_J1939) && (DEM_CFG_DTC_OBDDTCREF(DtcIndex) != NULL_PTR) \
                            && (DTC == DEM_CFG_DTC_J1939_VALUE(DtcIndex)))
#endif
							)
                    {
                        /*Clear RAM info of one DTC*/
                        DemInternal_ClearOneDTC(DtcIndex);
#if(DEM_CFG_CLEARDTCBEHAIOR == DEM_CLRRESP_VOLATILE)
                        /*SWS_Dem_00570*/
                        Result = DEM_CLEAR_OK;
#else
                        Dem_ClearDTCState = DEM_IN_CLEAR_EVENT_MEM;
                        Result = DEM_CLEAR_PENDING;
#endif/*(DEM_CFG_CLEARDTCBEHAIOR == DEM_CLRRESP_VOLATILE)*/

                        break;
                    }
                }
            }
#else/*(DEM_CFG_CLEARDTCLIMITATION != DEM_ONLY_CLEAR_ALL_DTCS)*/
            Dem_ClearDTCState = DEM_IN_CLEAR_DTC_GROUP;
            Result = DEM_CLEAR_PENDING;
#endif/*(DEM_CFG_CLEARDTCLIMITATION != DEM_ONLY_CLEAR_ALL_DTCS)*/
        }
    }
    else
    {
        if((Dem_ClearDTC_DTC != DTC) || (Dem_ClearDTC_DTCFormat != DTCFormat) || (Dem_ClearDTC_DTCOrigin != DTCOrigin))
        {
            /*SWS_Dem_00662*//*SWS_Dem_00664*/
            Result = DEM_CLEAR_BUSY;
        }
        else
        {
            if(Dem_ClearDTCState == DEM_IN_CLEAR_DTC_OK)
            {
                Dem_ClearDTCState = DEM_IN_CLEAR_DTC_IDLE;
                /*SWS_Dem_00572*/
                Result = DEM_CLEAR_OK;
            }
            else if(Dem_ClearDTCState == DEM_IN_CLEAR_DTC_ERR)
            {
                Dem_ClearDTCState = DEM_IN_CLEAR_DTC_IDLE;
                /*SWS_Dem_01057*/
                Result = DEM_CLEAR_MEMORY_ERROR;
            }
            else
            {
                /*SWS_Dem_00663*/
                Result = DEM_CLEAR_PENDING;
            }
        }
    }

    return Result;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_MainFunction
*
* Description: Processes all not event based Dem internal functions.
*
* Inputs: None
*
* Outputs: None
*
* Return: None
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, DEM_CODE) Dem_MainFunction
(
    void
)
{
    /*SWS_Dem_00125*/
    if(Dem_State == DEM_NORMAL)
    {
        DemInternal_MainFnc_OperationCycle();
        DemInternal_MainFnc_BswErrorHandle();
#if(DEM_CFG_DEBOUNCETIMEBASEDSUPPORT == STD_ON)
        DemInternal_MainFnc_DebounceTimer();
#endif
        /*SWS_Dem_00806*/
        DemInternal_MainFnc_CaptureData();
        /*Clear the group DTC or Write the RAM info which has been cleared in nonvalatile memory.*/
        DemInternal_MainFnc_ClearDTC();

#if((DEM_CFG_OBD_SUPPORT == DEM_OBD_MASTER_ECU)||(DEM_CFG_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU))
        DemInternal_MainFnc_OBD();
#endif
    }
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_GetEventInternalData
*
* Description: Get the internal data of one event.
*              It's not AUTOSAR standard interface.
*
* Inputs: EventId,DataType
*
* Outputs: DataValue
*
* Return: None
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, DEM_CODE) Dem_GetEventInternalData
(
    Dem_EventIdType EventId,
    Dem_InternalDataElementType DataType,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DataValue
)
{
    Std_ReturnType Result = E_NOT_OK;

    if(Dem_State != DEM_NORMAL)
    {
        /*SWS_Dem_01112*//*SWS_Dem_00124*/
    }
    else if(EventId >= DEM_NUM_OF_EVENT)
    {
        /*Result = E_NOT_OK;*/
    }
#if((DEM_CONFIG_VARIANTS != STD_CONFIG_VARIANTS_POSTBUILD) \
    && (DEM_CFG_AVAILABILITYSUPPORT == DEM_EVENT_AVAILABILITY))
    else if(Dem_EventAvailable[EventId] == FALSE)
    {
        /*SWS_Dem_01108*/
    }
#endif
    else
    {
        *DataValue = DemInternal_GetEventInternalData(EventId, DataType);
        Result = E_OK;
    }

    return Result;
}

#if((DEM_CFG_OBD_SUPPORT == DEM_OBD_MASTER_ECU)||(DEM_CFG_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU))
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_SetEventDisabled
*
* Description: Service for reporting the event as disabled to the Dem for the
*              PID $41 computation.
*
* Inputs: EventId: Identification of an event by assigned EventId.
*
* Outputs: None
*
* Return: E_OK: set of event to disabled was successfull.
*         E_NOT_OK: set of event disabled failed.
*
* Limitations: This API will be available only if ({ecuc(Dem/DemGeneral.DemOBD-
*              Support)} != DEM_OBD_NO_OBD_SUPPORT)
********************************************************************************
END_FUNCTION_HDR*/
/*SWS_Dem_00312*//*SWS_Dem_00294*/
FUNC(Std_ReturnType, DEM_CODE) Dem_SetEventDisabled
(
    Dem_EventIdType EventId
)
{
    Std_ReturnType Result = E_NOT_OK;
#if(DEM_CFG_OBD_SUPPORT == DEM_OBD_MASTER_ECU)
    Dem_EventOBDReadinessGroupType ReadinessGroup = DEM_OBD_RDY_NONE;
    uint8 BytePos;
    uint8 BitPos;
#endif

    if(Dem_State != DEM_NORMAL)
    {
        /*SWS_Dem_01112*//*SWS_Dem_00124*/
        DEM_DET_REPORT_ERROR(DEM_SETEVENTDISABLED_APIID, DEM_E_UNINIT);
    }
    else if(EventId >= DEM_NUM_OF_EVENT)
    {
        DEM_DET_REPORT_ERROR(DEM_SETEVENTDISABLED_APIID, DEM_E_PARAM_DATA);
    }
#if((DEM_CONFIG_VARIANTS != STD_CONFIG_VARIANTS_POSTBUILD) \
    && (DEM_CFG_AVAILABILITYSUPPORT == DEM_EVENT_AVAILABILITY))
    else if(Dem_EventAvailable[EventId] == FALSE)
    {
        /*SWS_Dem_01108*/
    }
#endif
    else
    {
#if(DEM_CFG_OBD_SUPPORT == DEM_OBD_MASTER_ECU)
        /*SWS_Dem_00348*/
        ReadinessGroup = DEM_CFG_DTC_OBD_READINESSGROUP(DEM_CFG_EVENT_DTCREF(EventId));

        if(ReadinessGroup != DEM_OBD_RDY_NONE)
        {
            BytePos = (ReadinessGroup/8);
            BitPos = (ReadinessGroup%8);

            DEM_OBD_READINESSGROUP_STATUS[BytePos] &= (~((uint8)0x01 << BitPos));

            Result = E_OK;
        }
#endif
    }

    return Result;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_RepIUMPRFaultDetect
*
* Description: Service for reporting that faults are possibly found because all
*              conditions are fullfilled.
*
* Inputs: RatioID: Ratio Identifier reporting that a respective monitor could
*                  have found a fault- only used when interface option "API"
*                  is selected.
*
* Outputs: None
*
* Return: E_OK: report of IUMPR result was successfully reported.
*         E_NOT_OK: report of IUMPR result failed.
*
* Limitations: This API will be available only if ({ecuc(Dem/DemGeneral.DemOBD-
*              Support)} != DEM_OBD_NO_OBD_SUPPORT)
********************************************************************************
END_FUNCTION_HDR*/
/*SWS_Dem_00313*//*SWS_Dem_00360*//*SWS_Dem_00296*/
FUNC(Std_ReturnType, DEM_CODE) Dem_RepIUMPRFaultDetect
(
    Dem_RatioIdType RatioID
)
{
    Std_ReturnType Result = E_NOT_OK;
    Dem_EventIdType EventId;
    Dem_UdsStatusByteType DtcStatus;

#if(DEM_NUM_OF_RATIO > 0)
    if(Dem_State != DEM_NORMAL)
    {
        /*SWS_Dem_01112*//*SWS_Dem_00124*/
        DEM_DET_REPORT_ERROR(DEM_REPIUMPRFAULTDETECT_APIID, DEM_E_UNINIT);
    }
    else if(RatioID >= DEM_NUM_OF_RATIO)
    {
        DEM_DET_REPORT_ERROR(DEM_REPIUMPRFAULTDETECT_APIID, DEM_E_PARAM_DATA);
    }
    else if(DEM_CFG_RATIO_KIND(RatioID) != DEM_RATIO_API)
    {
        DEM_DET_REPORT_ERROR(DEM_REPIUMPRFAULTDETECT_APIID, DEM_E_WRONG_CONFIGURATION);
    }
#if((DEM_CONFIG_VARIANTS != STD_CONFIG_VARIANTS_POSTBUILD) \
    && (DEM_CFG_AVAILABILITYSUPPORT == DEM_EVENT_AVAILABILITY))
    else if(Dem_EventAvailable[DEM_CFG_RATIO_EVENTREF(RatioID)] == FALSE)
    {
        /*SWS_Dem_01108*//*SWS_Dem_00709*/
    }
#endif
    else
    {
        EventId = DEM_CFG_RATIO_EVENTREF(RatioID);
        DtcStatus = DEM_DTC_STATUS(DEM_CFG_EVENT_DTCREF(EventId));

        /*SWS_Dem_00299*//*Check event status*/
        if(!DEM_TEST_UDS_STATUS_PDTC(DtcStatus))
        {
            /*SWS_Dem_01188*/
            if((DEM_OBD_RATIO_STATE(RatioID) & DEM_OBD_NUM_INCREASED_MASK) == 0)
            {
                /*increase 1 to the numerator*/
                DEM_OBD_RATIO_NUMERATOR(RatioID)++;
                DEM_OBD_RATIO_STATE(RatioID) |= DEM_OBD_NUM_INCREASED_MASK;
            }

            if(DEM_OBD_RATIO_NUMERATOR(RatioID) >= DEM_OBD_NUMDEN_MAX_VALUE)
            {
                DEM_OBD_RATIO_NUMERATOR(RatioID) = (DEM_OBD_RATIO_NUMERATOR(RatioID) >> 1);
                DEM_OBD_RATIO_DENOMINATOR(RatioID) = (DEM_OBD_RATIO_DENOMINATOR(RatioID) >> 1);
            }
        }

        Result = E_OK;
    }
#endif/*#if(DEM_NUM_OF_RATIO > 0)*/
    return Result;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_SetIUMPRDenCondition
*
* Description: In order to communicate the status of the (additional) denominator
*              conditions among the OBD relevant ECUs, the API is used to forward
*              the condition status to a Dem of a particular ECU.
*
* Inputs: ConditionId: Identification of a IUMPR denominator condition ID
*                      (General Denominator, Cold start, EVAP, 500mi).
*         ConditionStatus: Status of the IUMPR denominator condition (Notreached,
*                          reached, not reachable / inhibited)
*
* Outputs: None
*
* Return: E_OK: set of IUMPR denominator condition was successful.
*         E_NOT_OK: set of IUMPR denominator condition failed or could not be
*                   accepted.
*
* Limitations: This API will be available only if ({ecuc(Dem/DemGeneral.DemOBD-
*              Support)} != DEM_OBD_NO_OBD_SUPPORT)
********************************************************************************
END_FUNCTION_HDR*/
/*SWS_Dem_00733*//*SWS_Dem_00714*/
FUNC(Std_ReturnType, DEM_CODE) Dem_SetIUMPRDenCondition
(
    Dem_IumprDenomCondIdType ConditionId,
    Dem_IumprDenomCondStatusType ConditionStatus
)
{
    Std_ReturnType Result = E_NOT_OK;
#if(DEM_NUM_OF_RATIO > 0)
    Dem_IumprDenomCondStatusType OldConditionStatus = DEM_IUMPR_DEN_STATUS_REACHED;
#endif
    if(Dem_State != DEM_NORMAL)
    {
        /*SWS_Dem_01112*//*SWS_Dem_00124*/
        DEM_DET_REPORT_ERROR(DEM_SETIUMPRDENCONDITION_APIID, DEM_E_UNINIT);
    }
    else
    {
#if(DEM_NUM_OF_RATIO > 0)
        OldConditionStatus = DEM_OBD_RATIO_DENOMCOND_STATUS(ConditionId);
        /*SWS_Dem_00717*//*Set and record the status*/
        DEM_OBD_RATIO_DENOMCOND_STATUS(ConditionId) = ConditionStatus;

        if(ConditionId == DEM_IUMPR_GENERAL_DENOMINATOR)
        {
            if((ConditionStatus == DEM_IUMPR_DEN_STATUS_REACHED) \
                && ((DEM_OBD_RATIO_GENDEN_STATE & DEM_OBD_DEN_INCREASED_MASK) == 0))
            {
                DEM_OBD_RATIO_GENDEN_CNT++;
                DEM_OBD_RATIO_GENDEN_STATE |= DEM_OBD_DEN_INCREASED_MASK;
            }
            else if(ConditionStatus == DEM_IUMPR_DEN_STATUS_INHIBITED)
            {
                DEM_OBD_RATIO_GENDEN_STATE |= DEM_OBD_DEN_INCREASED_MASK;
            }
            else
            {
                /*do nothing*/
            }
        }

        if((OldConditionStatus != ConditionStatus) \
            && (ConditionStatus == DEM_IUMPR_DEN_STATUS_REACHED))
        {
            DemInternal_UpdateRatioDenominator();
        }

        Result = E_OK;
#endif/*#if(DEM_NUM_OF_RATIO > 0)*/
    }

    return Result;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_GetIUMPRDenCondition
*
* Description: In order to communicate the status of the (additional) denominator
*              conditions among the OBD relevant ECUs, the API is used to retrieve
*              the condition status from the Dem of the ECU where the conditions
*              are computed.
*
* Inputs: ConditionId: Identification of a IUMPR denominator condition ID
*                      (General Denominator, Cold start, EVAP, 500mi).
*
* Outputs: ConditionStatus: Status of the IUMPR denominator condition (Notreached,
*                           reached, not reachable / inhibited)
*
* Return: E_OK: get of IUMPR denominator condition was successful.
*         E_NOT_OK: get of condition status failed.
*
* Limitations: This API will be available only if ({ecuc(Dem/DemGeneral.DemOBD-
*              Support)} != DEM_OBD_NO_OBD_SUPPORT)
********************************************************************************
END_FUNCTION_HDR*/
/*SWS_Dem_00734*//*SWS_Dem_00966*/
FUNC(Std_ReturnType, DEM_CODE) Dem_GetIUMPRDenCondition
(
    Dem_IumprDenomCondIdType ConditionId,
    P2VAR(Dem_IumprDenomCondStatusType, AUTOMATIC, DEM_APPL_DATA) ConditionStatus
)
{
    Std_ReturnType Result = E_NOT_OK;

    if(Dem_State != DEM_NORMAL)
    {
        /*SWS_Dem_01112*//*SWS_Dem_00124*/
        DEM_DET_REPORT_ERROR(DEM_GETIUMPRDENCONDITION_APIID, DEM_E_UNINIT);
    }
    else if (ConditionStatus == NULL_PTR)
    {
        DEM_DET_REPORT_ERROR(DEM_GETIUMPRDENCONDITION_APIID, DEM_E_PARAM_POINTER);
    }
    else
    {
#if(DEM_NUM_OF_RATIO > 0)
        /*SWS_Dem_00716*//*Read the status*/
        *ConditionStatus = DEM_OBD_RATIO_DENOMCOND_STATUS(ConditionId);
        
        Result = E_OK;
#endif
    }

    return Result;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_RepIUMPRDenLock
*
* Description: Service is used to lock a denominator of a specific monitor.
*
* Inputs: RatioID: Ratio Identifier reporting that specific denominator is locked
*                  (for physical reasons - e.g. temperature conditions or minimum
*                  activity).
*
* Outputs: None.
*
* Return: E_OK: report of IUMPR denominator status was successfully reported.
*         E_NOT_OK: report of IUMPR denominator status was not successfully
*                   reported.
*
* Limitations: This API will be available only if ({ecuc(Dem/DemGeneral.DemOBD-
*              Support)} != DEM_OBD_NO_OBD_SUPPORT)
********************************************************************************
END_FUNCTION_HDR*/
/*SWS_Dem_00314*//*SWS_Dem_00362*//*SWS_Dem_00297*/
FUNC(Std_ReturnType, DEM_CODE) Dem_RepIUMPRDenLock
(
    Dem_RatioIdType RatioID
)
{
    Std_ReturnType Result = E_NOT_OK;

#if(DEM_NUM_OF_RATIO > 0)
    if(Dem_State != DEM_NORMAL)
    {
        /*SWS_Dem_01112*//*SWS_Dem_00124*/
        DEM_DET_REPORT_ERROR(DEM_REPIUMPRDENLOCK_APIID, DEM_E_UNINIT);
    }
    else if(RatioID >= DEM_NUM_OF_RATIO)
    {
        DEM_DET_REPORT_ERROR(DEM_REPIUMPRDENLOCK_APIID, DEM_E_PARAM_DATA);
    }
    else if(DEM_CFG_RATIO_IUMPR_DEN(RatioID) != DEM_IUMPR_DEN_PHYS_API)
    {
        DEM_DET_REPORT_ERROR(DEM_REPIUMPRDENLOCK_APIID, DEM_E_WRONG_CONFIGURATION);
    }
#if((DEM_CONFIG_VARIANTS != STD_CONFIG_VARIANTS_POSTBUILD) \
    && (DEM_CFG_AVAILABILITYSUPPORT == DEM_EVENT_AVAILABILITY))
    else if(Dem_EventAvailable[DEM_CFG_RATIO_EVENTREF(RatioID)] == FALSE)
    {
        /*SWS_Dem_01108*/
    }
#endif
    else
    {
        /*Recod the lock status*/
        DEM_OBD_RATIO_STATE(RatioID) |= DEM_OBD_DEN_LOCK_MASK;

        Result = E_OK;
    }
#endif/*#if(DEM_NUM_OF_RATIO > 0)*/
    return Result;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_RepIUMPRDenRelease
*
* Description: Service is used to release a denominator of a specific monitor.
*
* Inputs: RatioID: Ratio Identifier reporting that specific denominator is released
*                  (for physical reasons - e.g. temperature conditions or minimum
*                  activity).
*
* Outputs: None.
*
* Return: E_OK: report of IUMPR denominator status was successfully reported.
*         E_NOT_OK: report of IUMPR denominator status was not successfully
*                   reported.
*
* Limitations: This API will be available only if ({ecuc(Dem/DemGeneral.DemOBD-
*              Support)} != DEM_OBD_NO_OBD_SUPPORT)
********************************************************************************
END_FUNCTION_HDR*/
/*SWS_Dem_00315*//*SWS_Dem_00362*//*SWS_Dem_00308*/
FUNC(Std_ReturnType, DEM_CODE) Dem_RepIUMPRDenRelease
(
    Dem_RatioIdType RatioID
)
{
    Std_ReturnType Result = E_NOT_OK;
    Dem_EventIdType EventId;
    Dem_UdsStatusByteType DtcStatus;

#if(DEM_NUM_OF_RATIO > 0)
    if(Dem_State != DEM_NORMAL)
    {
        /*SWS_Dem_01112*//*SWS_Dem_00124*/
        DEM_DET_REPORT_ERROR(DEM_REPIUMPRDENRELEASE_APIID, DEM_E_UNINIT);
    }
    else if(RatioID >= DEM_NUM_OF_RATIO)
    {
        DEM_DET_REPORT_ERROR(DEM_REPIUMPRDENRELEASE_APIID, DEM_E_PARAM_DATA);
    }
    else if(DEM_CFG_RATIO_IUMPR_DEN(RatioID) != DEM_IUMPR_DEN_PHYS_API)
    {
        DEM_DET_REPORT_ERROR(DEM_REPIUMPRDENRELEASE_APIID, DEM_E_WRONG_CONFIGURATION);
    }
#if((DEM_CONFIG_VARIANTS != STD_CONFIG_VARIANTS_POSTBUILD) \
    && (DEM_CFG_AVAILABILITYSUPPORT == DEM_EVENT_AVAILABILITY))
    else if(Dem_EventAvailable[DEM_CFG_RATIO_EVENTREF(RatioID)] == FALSE)
    {
        /*SWS_Dem_01108*/
    }
#endif
    else
    {
        /*Reset the lock status*/
        DEM_OBD_RATIO_STATE(RatioID) &= (~DEM_OBD_DEN_LOCK_MASK);
        /*SWS_Dem_00712*/
        if((DEM_OBD_RATIO_DENOMCOND_STATUS(DEM_IUMPR_DEN_GENERAL) == DEM_IUMPR_DEN_STATUS_REACHED) \
            && ((DEM_OBD_RATIO_STATE(RatioID) & DEM_OBD_DEN_INCREASED_MASK) == 0))
        {
            EventId = DEM_CFG_RATIO_EVENTREF(RatioID);
            DtcStatus = DEM_DTC_STATUS(DEM_CFG_EVENT_DTCREF(EventId));
            /*SWS_Dem_00299*/
            if(!DEM_TEST_UDS_STATUS_PDTC(DtcStatus))
            {
                DEM_OBD_RATIO_DENOMINATOR(RatioID)++;
                DEM_OBD_RATIO_STATE(RatioID) |= DEM_OBD_DEN_INCREASED_MASK;
            }

            if(DEM_OBD_RATIO_DENOMINATOR(RatioID) >= DEM_OBD_NUMDEN_MAX_VALUE)
            {
                DEM_OBD_RATIO_NUMERATOR(RatioID) = (DEM_OBD_RATIO_NUMERATOR(RatioID) >> 1);
                DEM_OBD_RATIO_DENOMINATOR(RatioID) = (DEM_OBD_RATIO_DENOMINATOR(RatioID) >> 1);
            }
        }

        Result = E_OK;
    }
#endif/*#if(DEM_NUM_OF_RATIO > 0)*/
    return Result;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_GetGeneralNumeratorAndDenominator
*
* Description: This interface is provided to user to get the General Numerator
*              and Denominator of one Ratio or Event.
*
* Inputs: None
*
* Outputs: Numerator, Denominator
*
* Return: E_OK, E_NOT_OK
*
* Limitations: This API will be available only if ({ecuc(Dem/DemGeneral.DemOBD-
*              Support)} != DEM_OBD_NO_OBD_SUPPORT)
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, DEM_CODE) Dem_GetGeneralNumeratorAndDenominator
(
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) Numerator,
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) Denominator
)
{
    Std_ReturnType Result = E_OK;

    if(Dem_State != DEM_NORMAL)
    {
        Result = E_NOT_OK;
    }
    else if((Numerator == NULL_PTR) || (Denominator == NULL_PTR))
    {
        Result = E_NOT_OK;
    }
    else
    {
#if(DEM_NUM_OF_RATIO > 0)
        *Numerator = DEM_OBD_RATIO_IGN_CNT;
        *Denominator = DEM_OBD_RATIO_GENDEN_CNT;
#else
        Result = E_NOT_OK;
#endif
    }
    return Result;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_GetNumeratorAndDenominator
*
* Description: This interface is provided to user to get the Numerator and
*              Denominator of one Ratio or Event.
*
* Inputs: RatioID
*
* Outputs: EventId, Numerator, Denominator
*
* Return: E_OK, E_NOT_OK
*
* Limitations: This API will be available only if ({ecuc(Dem/DemGeneral.DemOBD-
*              Support)} != DEM_OBD_NO_OBD_SUPPORT)
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, DEM_CODE) Dem_GetNumeratorAndDenominator
(
    Dem_RatioIdType RatioID,
    P2VAR(Dem_EventIdType, AUTOMATIC, DEM_APPL_DATA) EventId,
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) Numerator,
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) Denominator
)
{
    Std_ReturnType Result = E_NOT_OK;

#if(DEM_NUM_OF_RATIO > 0)
    if(Dem_State != DEM_NORMAL)
    {
        /*Result = E_NOT_OK;*/
    }
    else if(RatioID >= DEM_NUM_OF_RATIO)
    {
        /*Result = E_NOT_OK;*/
    }
    else if((EventId == NULL_PTR) || (Numerator == NULL_PTR) \
        || (Denominator == NULL_PTR))
    {
        /*Result = E_NOT_OK;*/
    }
    else
    {
        *EventId = DEM_CFG_RATIO_EVENTREF(RatioID);
        *Numerator = DEM_OBD_RATIO_NUMERATOR(RatioID);
        *Denominator = DEM_OBD_RATIO_DENOMINATOR(RatioID);

        Result = E_OK;
    }
#endif/*#if(DEM_NUM_OF_RATIO > 0)*/
    return Result;
}


#if(DEM_CFG_PTO_SUPPORT == STD_ON)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_SetPtoStatus
*
* Description: Set the status of the PTO(PID 0x1E).
*
* Inputs: PtoStatus: sets the status of the PTO (TRUE==active; FALSE==inactive).
*
* Outputs: None.
*
* Return: Returns E_OK when the new PTO-status has been adopted by the Dem;
*         returns E_NOT_OK in all other cases.
*
* Limitations: This API will be available only if ({ecuc(Dem/DemGeneral.DemOBD-
*              Support)} != DEM_OBD_NO_OBD_SUPPORT)
********************************************************************************
END_FUNCTION_HDR*/
/*SWS_Dem_00627*/
FUNC(Std_ReturnType, DEM_CODE) Dem_SetPtoStatus
(
    boolean PtoStatus
)
{
    Std_ReturnType Result = E_NOT_OK;

    if(Dem_State != DEM_NORMAL)
    {
        /*SWS_Dem_01112*//*SWS_Dem_00124*/
        DEM_DET_REPORT_ERROR(DEM_SETPTOSTATUS_APIID, DEM_E_UNINIT);
    }
    else if((PtoStatus != TRUE) && (PtoStatus != FALSE))
    {
        DEM_DET_REPORT_ERROR(DEM_SETPTOSTATUS_APIID, DEM_E_PARAM_DATA);
    }
    else
    {
        /*Not implemented.*/
        Result = E_OK;
    }
}
#endif

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_ReadDataOfPID01
*
* Description: Service to report the value of PID $01 computed by the Dem.
*
* Inputs: None.
*
* Outputs: PID01value: Buffer containing the contents of PID $01 computed by
*                      the Dem.
*
* Return: Always E_OK is returned, as E_NOT_OK will never appear.
*
* Limitations: This API will be available only if ({ecuc(Dem/DemGeneral.DemOBD-
*              Support)} != DEM_OBD_NO_OBD_SUPPORT)
********************************************************************************
END_FUNCTION_HDR*/
/*SWS_Dem_01167*/
FUNC(Std_ReturnType, DEM_CODE) Dem_ReadDataOfPID01
(
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) PID01value
)
{
    Std_ReturnType Result = E_NOT_OK;
#if(DEM_CFG_OBD_SUPPORT == DEM_OBD_MASTER_ECU)
    Dem_EventIdType EventId;
    uint16 DtcId;
    Dem_UdsStatusByteType DtcStatus;
    uint8 BytePos;
    uint8 BitPos;
    Dem_IndicatorStatusType IndicatorStatus;
#endif

    if(Dem_State != DEM_NORMAL)
    {
        /*SWS_Dem_01112*//*SWS_Dem_00124*/
        DEM_DET_REPORT_ERROR(DEM_READDATAOFPID01_APIID, DEM_E_UNINIT);
    }
    else if(PID01value == NULL_PTR)
    {
        DEM_DET_REPORT_ERROR(DEM_READDATAOFPID01_APIID, DEM_E_PARAM_POINTER);
    }
    else
    {
#if(DEM_CFG_OBD_SUPPORT == DEM_OBD_MASTER_ECU)
        PID01value[0U] = DEM_DATA_CLEAR;
        /*Set the value of engine type bit*/
        PID01value[1U] = (uint8)(DEM_CFG_OBD_ENGINE_TYPE << 3);
        PID01value[2U] = DEM_DATA_CLEAR;
        PID01value[3U] = DEM_DATA_CLEAR;

        for(EventId = 0; EventId < DEM_NUM_OF_EVENT; EventId++)
        {
            DtcId = DEM_CFG_EVENT_DTCREF(EventId);
            /*SWS_Dem_00354*/
#if((DEM_CONFIG_VARIANTS != STD_CONFIG_VARIANTS_POSTBUILD) \
    && (DEM_CFG_AVAILABILITYSUPPORT == DEM_EVENT_AVAILABILITY))
            if((Dem_EventAvailable[EventId] == TRUE) \
                && (DEM_CFG_DTC_OBDDTCREF(DtcId) != NULL_PTR) \
                && (DEM_CFG_DTC_OBD_READINESSGROUP(DtcId) != DEM_OBD_RDY_NONE))
#else
            if((DEM_CFG_DTC_OBDDTCREF(DtcId) != NULL_PTR) \
                && (DEM_CFG_DTC_OBD_READINESSGROUP(DtcId) != DEM_OBD_RDY_NONE))
#endif
            {
                BytePos = (DEM_CFG_DTC_OBD_READINESSGROUP(DtcId)/8);
                BitPos = (DEM_CFG_DTC_OBD_READINESSGROUP(DtcId)%8);
                /*Set value of monitors supported bit*/
                PID01value[BytePos + 1] |= ((uint8)0x01 << BitPos);

                DtcStatus = DEM_DTC_STATUS(DtcId);
                /*Status of monitors since DTC cleared*/
                if(DEM_TEST_UDS_STATUS_TNCSLC(DtcStatus))
                {
                    switch(BytePos)
                    {
                        /*Set value of monitors compleate bit.
                        0 = monitor complete (YES)
                        0 = monitor not applicable (N/A)
                        1 =  monitor not complete (NO)*/
                        case 0:
                            PID01value[1] |= ((uint8)0x40 << BitPos);
                        break;

                        default:
                            PID01value[3] |= ((uint8)0x01 << BitPos);
                        break;
                    }
                }/*if(DEM_TEST_UDS_STATUS_TNCSLC(DtcStatus))*/

                if((DEM_TEST_UDS_STATUS_CDTC(DtcStatus)) && (PID01value[0] < (uint8)0x7F))
                {
                    PID01value[0]++;
                }
            }
        }/*for(EventId = 0; EventId < DEM_NUM_OF_EVENT; EventId++)*/

        DemInternal_GetIndicatorStatus(DEM_CFG_MILINDICATORREF, &IndicatorStatus);

        if(IndicatorStatus != DEM_INDICATOR_OFF)
        {
            PID01value[0] |= (uint8)0x80;
        }

        Result = E_OK;
#endif/*#if(DEM_CFG_OBD_SUPPORT == DEM_OBD_MASTER_ECU)*/
    }
    return Result;
}

#if((DEM_CFG_OBD_SUPPORT == DEM_OBD_MASTER_ECU) \
    && (DEM_CFG_OBD_CENTRALIZED_PID21_HANDLING == STD_ON))
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_GetDataOfPID21
*
* Description: Service to get the value of PID $21 from the Dem by a software
*              component.
*
* Inputs: None.
*
* Outputs: PID21value: Content of PID $21 as raw hex value.
*
* Return: Always E_OK is returned, as E_NOT_OK will never appear.
*
* Limitations: This API will be available only if ({ecuc(Dem/DemGeneral/
*              DemGeneralOBD.DemOBDCentralizedPID21Handling)}== true)
*              && ({ecuc(Dem/DemGeneral.DemOBDSupport)} == DEM_OBD_MASTER_ECU).
********************************************************************************
END_FUNCTION_HDR*/
/*SWS_Dem_01093*/
FUNC(Std_ReturnType, DEM_CODE) Dem_GetDataOfPID21
(
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) PID21value
)
{
    Std_ReturnType Result = E_NOT_OK;

    if(Dem_State != DEM_NORMAL)
    {
        /*SWS_Dem_01112*//*SWS_Dem_00124*/
        DEM_DET_REPORT_ERROR(DEM_GETDATAOFPID21_APIID, DEM_E_UNINIT);
    }
    else if(PID21value == NULL_PTR)
    {
        DEM_DET_REPORT_ERROR(DEM_GETDATAOFPID21_APIID, DEM_E_PARAM_POINTER);
    }
    else
    {
        /*Not implemented.*/
        Result = E_OK;
    }
    return Result;
}
#endif/*#if((DEM_CFG_OBD_SUPPORT == DEM_OBD_MASTER_ECU) \
            && (DEM_CFG_OBD_CENTRALIZED_PID21_HANDLING == STD_ON))*/

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_SetDataOfPID21
*
* Description: Service to set the value of PID $21 in the Dem by a software
*              component.
*
* Inputs: PID21value: Buffer containing the contents of PID $21.
*
* Outputs: None.
*
* Return: Always E_OK is returned, as E_NOT_OK will never appear.
*
* Limitations: This API will be available only if ({ecuc(Dem/DemGeneral.DemOBD-
*              Support)} != DEM_OBD_NO_OBD_SUPPORT)
********************************************************************************
END_FUNCTION_HDR*/
/*SWS_Dem_00735*/
FUNC(Std_ReturnType, DEM_CODE) Dem_SetDataOfPID21
(
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) PID21value
)
{
    Std_ReturnType Result = E_NOT_OK;

    if(Dem_State != DEM_NORMAL)
    {
        /*SWS_Dem_01112*//*SWS_Dem_00124*/
        DEM_DET_REPORT_ERROR(DEM_SETDATAOFPID21_APIID, DEM_E_UNINIT);
    }
    else if(PID21value == NULL_PTR)
    {
        DEM_DET_REPORT_ERROR(DEM_SETDATAOFPID21_APIID, DEM_E_PARAM_POINTER);
    }
    else
    {
        /*Not implemented.*/
        Result = E_OK;
    }
    return Result;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_SetDataOfPID31
*
* Description: Service to set the value of PID $31 in the Dem by a software
*              component.
*
* Inputs: PID31value: Buffer containing the contents of PID $31.
*
* Outputs: None.
*
* Return: Always E_OK is returned, as E_NOT_OK will never appear.
*
* Limitations: This API will be available only if ({ecuc(Dem/DemGeneral.DemOBD-
*              Support)} != DEM_OBD_NO_OBD_SUPPORT)
********************************************************************************
END_FUNCTION_HDR*/
/*SWS_Dem_00736*/
FUNC(Std_ReturnType, DEM_CODE) Dem_SetDataOfPID31
(
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) PID31value
)
{
    Std_ReturnType Result = E_NOT_OK;
    uint32 Distance;

    if(Dem_State != DEM_NORMAL)
    {
        /*SWS_Dem_01112*//*SWS_Dem_00124*/
        DEM_DET_REPORT_ERROR(DEM_SETDATAOFPID31_APIID, DEM_E_UNINIT);
    }
    else if(PID31value == NULL_PTR)
    {
        DEM_DET_REPORT_ERROR(DEM_SETDATAOFPID31_APIID, DEM_E_PARAM_POINTER);
    }
    else
    {
        Distance = (((uint32)PID31value[0] << 8) | ((uint32)PID31value[1]));
        DEM_OBD_DISTANCE_SINCEDTCCLEARED = (uint32)(Distance*1000);

        Result = E_OK;
    }
    return Result;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_SetDataOfPID4D
*
* Description: Service to set the value of PID $4D in the Dem by a software
*              component.
*
* Inputs: PID4Dvalue: Buffer containing the contents of PID $4D.
*
* Outputs: None.
*
* Return: Always E_OK is returned, as E_NOT_OK will never appear.
*
* Limitations: This API will be available only if ({ecuc(Dem/DemGeneral.DemOBD-
*              Support)} != DEM_OBD_NO_OBD_SUPPORT)
********************************************************************************
END_FUNCTION_HDR*/
/*SWS_Dem_00737*/
FUNC(Std_ReturnType, DEM_CODE) Dem_SetDataOfPID4D
(
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) PID4Dvalue
)
{
    Std_ReturnType Result = E_NOT_OK;

    if(Dem_State != DEM_NORMAL)
    {
        /*SWS_Dem_01112*//*SWS_Dem_00124*/
        DEM_DET_REPORT_ERROR(DEM_SETDATAOFPID4D_APIID, DEM_E_UNINIT);
    }
    else if(PID4Dvalue == NULL_PTR)
    {
        DEM_DET_REPORT_ERROR(DEM_SETDATAOFPID4D_APIID, DEM_E_PARAM_POINTER);
    }
    else
    {
        /*Not implemented.*/
        Result = E_OK;
    }
    return Result;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_SetDataOfPID4E
*
* Description: Service to set the value of PID $4E in the Dem by a software
*              component.
*
* Inputs: PID4Evalue: Buffer containing the contents of PID $4E.
*
* Outputs: None.
*
* Return: Always E_OK is returned, as E_NOT_OK will never appear.
*
* Limitations: This API will be available only if ({ecuc(Dem/DemGeneral.DemOBD-
*              Support)} != DEM_OBD_NO_OBD_SUPPORT)
********************************************************************************
END_FUNCTION_HDR*/
/*SWS_Dem_00738*/
FUNC(Std_ReturnType, DEM_CODE) Dem_SetDataOfPID4E
(
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) PID4Evalue
)
{
    Std_ReturnType Result = E_NOT_OK;

    if(Dem_State != DEM_NORMAL)
    {
        /*SWS_Dem_01112*//*SWS_Dem_00124*/
        DEM_DET_REPORT_ERROR(DEM_SETDATAOFPID4E_APIID, DEM_E_UNINIT);
    }
    else if(PID4Evalue == NULL_PTR)
    {
        DEM_DET_REPORT_ERROR(DEM_SETDATAOFPID4E_APIID, DEM_E_PARAM_POINTER);
    }
    else
    {
        /*Not implemented.*/
        Result = E_OK;
    }
    return Result;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_SetPfcCycleQualified
*
* Description: Marks the current OBD driving cycle as having met the criteria
*              for the PFC cycle.
*
* Inputs: None
*
* Outputs: None.
*
* Return: Always E_OK is returned, as E_NOT_OK will never appear.
*
* Limitations: This API will be available only if ({ecuc(Dem/DemGeneral.DemOBD-
*              Support)} != DEM_OBD_NO_OBD_SUPPORT)
********************************************************************************
END_FUNCTION_HDR*/
/*SWS_Dem_00739*/
FUNC(Std_ReturnType, DEM_CODE) Dem_SetPfcCycleQualified
(
    void
)
{
    Std_ReturnType Result = E_NOT_OK;

    if(Dem_State != DEM_NORMAL)
    {
        /*SWS_Dem_01112*//*SWS_Dem_00124*/
        DEM_DET_REPORT_ERROR(DEM_SETPFCCYCLEQUALIFIED_APIID, DEM_E_UNINIT);
    }
    else
    {
#if(DEM_CFG_MAXNUMBEREVENTENTRY_PERMANENT > 0)
        /*Not implemented.*/
        DEM_OBD_PFC_CYCLE_STATUS = TRUE;
        Result = E_OK;
#endif
    }
    return Result;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_GetPfcCycleQualified
*
* Description: Returns TRUE if the criteria for the PFC cycle have been met
*              during the current OBD driving cycle.
*
* Inputs: None
*
* Outputs: isqualified: TRUE: During the current OBD driving cycle the criteria
*                             for the PFC cycle have been met.
*                       FALSE: During the current OBD driving cycle the criteria
*                              for the PFC cycle have not been met.
*
* Return: Always E_OK is returned, as E_NOT_OK will never appear.
*
* Limitations: This API will be available only if ({ecuc(Dem/DemGeneral.DemOBD-
*              Support)} != DEM_OBD_NO_OBD_SUPPORT)
********************************************************************************
END_FUNCTION_HDR*/
/*SWS_Dem_00740*/
FUNC(Std_ReturnType, DEM_CODE) Dem_GetPfcCycleQualified
(
    P2VAR(boolean, AUTOMATIC, DEM_APPL_DATA) isqualified
)
{
    Std_ReturnType Result = E_NOT_OK;

    if(Dem_State != DEM_NORMAL)
    {
        /*SWS_Dem_01112*//*SWS_Dem_00124*/
        DEM_DET_REPORT_ERROR(DEM_GETPFCCYCLEQUALIFIED_APIID, DEM_E_UNINIT);
    }
    else if(isqualified == NULL_PTR)
    {
        DEM_DET_REPORT_ERROR(DEM_GETPFCCYCLEQUALIFIED_APIID, DEM_E_PARAM_POINTER);
    }
    else
    {
#if(DEM_CFG_MAXNUMBEREVENTENTRY_PERMANENT > 0)
        *isqualified = DEM_OBD_PFC_CYCLE_STATUS;
        Result = E_OK;
#endif
    }
    return Result;
}

#if(DEM_CFG_OBD_SUPPORT == DEM_OBD_DEP_SEC_ECU)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_SetClearDTC
*
* Description: API to inform the Dem (of a Dependend / Secondary ECU) about the
*              reception of service $04 execution by a software component.
*              API is needed in OBD Dependend / Secondary ECUs only.
*
* Inputs: DTC: Defines the DTC in respective format, that has been cleared from
*              the event memory.
*         DTCFormat: Format of the provided DTC value.
*         DTCOrigin: Event memory (e.g. MIRROR).
*
* Outputs: None.
*
* Return: Always E_OK is returned, as E_NOT_OK will never appear.
*
* Limitations: This API will be available only if ({ecuc(Dem/DemGeneral.DemOBD-
*              Support)} == DEM_OBD_DEP_SEC_ECU)
********************************************************************************
END_FUNCTION_HDR*/
/*SWS_Dem_00741*/
FUNC(Std_ReturnType, DEM_CODE) Dem_SetClearDTC
(
    uint32 DTC,
    Dem_DTCFormatType DTCFormat,
    Dem_DTCOriginType DTCOrigin
)
{
    Std_ReturnType Result = E_NOT_OK;

    /*Not implemented.*/

    return Result;
}
#endif/*#if(DEM_CFG_OBD_SUPPORT == DEM_OBD_DEP_SEC_ECU)*/


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_GetB1Counter
*
* Description: Service to report the value of the B1 counter computed by the Dem.
*              API is needed in WWH-OBD relevant ECUs only.
*
* Inputs: None.
*
* Outputs: B1Counter: Buffer containing the B1 counter.
*                     The buffer is provided by the application with the size
*                     of 2 bytes.
*
* Return: Always E_OK is returned, as E_NOT_OK will never appear.
*
* Limitations: This API will be available only if ({ecuc(Dem/DemGeneral.DemOBD-
*              Support)} != DEM_OBD_NO_OBD_SUPPORT)
********************************************************************************
END_FUNCTION_HDR*/
/*SWS_Dem_01169*/
FUNC(Std_ReturnType, DEM_CODE) Dem_GetB1Counter
(
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) B1Counter
)
{
    Std_ReturnType Result = E_NOT_OK;

    /*Not implemented.*/

    return Result;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_SetDTR
*
* Description: Reports a DTR result with lower and upper limit. The internal
*              eventstatus serves as master whether the DTR values are forwarded
*              or ignored, also taking the DTRUpdateKind into account.
*
* Inputs: DTRId: Identification of a DTR element by assigned DTRId.
*         TestResult: Test result of DTR
*         LowerLimit: Lower limit of DTR
*         UpperLimit: Upper limit of DTR
*         Ctrlval: Control value of the DTR to support its interpretation
*                  Dem-internally.
*
* Outputs: None.
*
* Return: E_OK: Report of DTR result successful
*         E_NOT_OK: Report of DTR result failed
*
* Limitations: This API will be available only if ({ecuc(Dem/DemGeneral.DemOBD-
*              Support)} != DEM_OBD_NO_OBD_SUPPORT)
********************************************************************************
END_FUNCTION_HDR*/
/*SWS_Dem_00765*/
FUNC(Std_ReturnType, DEM_CODE) Dem_SetDTR
(
    uint16 DTRId,
    sint32 TestResult,
    sint32 LowerLimit,
    sint32 UpperLimit,
    Dem_DTRControlType Ctrlval
)
{
    Std_ReturnType Result = E_NOT_OK;

    /*Not implemented.*/

    return Result;
}
#endif/*#if((DEM_CFG_OBD_SUPPORT == DEM_OBD_MASTER_ECU)||(DEM_CFG_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU))*/

#define DEM_STOP_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
*   Dem_Dcm
*******************************************************************************/
#define DEM_START_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
*   Dem_Dcm  static Api declaration
*******************************************************************************/
STATIC FUNC(Std_ReturnType, DEM_CODE) DemInternal_CheckDtcValid
(
    Dem_UdsDTCType DTC,
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) DtcId
);

STATIC FUNC(Dem_ReturnGetSizeOfDataByDTCType, DEM_CODE) DemInternal_GetSizeOfExtendedData
(
    uint32 DTC,
    Dem_DTCOriginType DTCOrigin,
    uint8 ExtendedDataNumber,
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) SizeOfExtendedDataRecord,
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) ExtendedDataOffset
);

#if(DEM_MAX_EXTSIZE_OF_DTC > 0U)
STATIC FUNC(void, DEM_CODE) DemInternal_GetAllExtendedData
(
    uint32 DtcId,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DestBuffer
);
#endif

STATIC FUNC(Dem_ReturnGetSizeOfDataByDTCType, DEM_CODE) DemInternal_GetSizeOfFFData
(
    uint32 DTC,
    Dem_DTCOriginType DTCOrigin,
    uint8 RecordNumber,
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) SizeOfFreezeFrame,
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) FFDataOffset
);

#if(DEM_MAX_FFSIZE_OF_DTC > 0U)
STATIC FUNC(void, DEM_CODE) DemInternal_GetAllFFData
(
    uint32 DtcId,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DestBuffer
);
#endif

/*******************************************************************************
*   Dem_Dcm  static Api definition
*******************************************************************************/

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name:
*
* Description:
*
* Inputs:
*
* Outputs:
*
* Return:
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(Std_ReturnType, DEM_CODE) DemInternal_CheckDtcValid
(
    Dem_UdsDTCType DTC,
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) DtcId
)
{
    Std_ReturnType Result = E_NOT_OK;
    uint16 i;

    for(i = 0; i < DEM_NUM_OF_DTC; i++)
    {
        if(DTC == DEM_CFG_DTC_VALUE(i))
        {
            *DtcId = i;
            Result = E_OK;
            break;
        }
    }
    return Result;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name:
*
* Description:
*
* Inputs:
*
* Outputs:
*
* Return:
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(Dem_ReturnGetSizeOfDataByDTCType, DEM_CODE) DemInternal_GetSizeOfExtendedData
(
    uint32 DTC,
    Dem_DTCOriginType DTCOrigin,
    uint8 ExtendedDataNumber,
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) SizeOfExtendedDataRecord,
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) ExtendedDataOffset
)
{
    Dem_ReturnGetSizeOfDataByDTCType Result = DEM_GETSIZEBYDTC_OK;
    uint16 DtcId;
#if(DEM_NUM_OF_EXTDATACLASS > 0U)
    uint8 i;
    uint8 j;
    uint8 RecIdx;
    uint8 DataIdx;
    uint8 RecNum;
    uint8 DataSize;
    uint8 *DataBufferPtr;
    uint16 RecDataSize;
    uint16 InvalidDataLength;
#endif
    if(SizeOfExtendedDataRecord == NULL_PTR)
    {
        Result = DEM_GETSIZEBYDTC_WRONG_RECNUM;
    }
    else if(DTCOrigin != DEM_DTC_ORIGIN_PRIMARY_MEMORY)
    {
        /*SWS_Dem_00171*/
        Result = DEM_GETSIZEBYDTC_WRONG_DTCORIGIN;
    }
    else if((ExtendedDataNumber == 0U) || ((ExtendedDataNumber > 0xEFU) && (ExtendedDataNumber < 0xFFU)))
    {
        Result = DEM_GETSIZEBYDTC_WRONG_RECNUM;
    }
    else if(E_OK != DemInternal_CheckDtcValid(DTC, &DtcId))
    {
        /*SWS_Dem_00172*/
        Result = DEM_GETSIZEBYDTC_WRONG_DTC;
    }
#if(DEM_NUM_OF_EXTDATACLASS > 0)
    else if(DEM_CFG_DTC_EXTDATACLASSREF(DtcId) == NULL_PTR)
    {
        Result = DEM_GETSIZEBYDTC_WRONG_RECNUM;
    }
#endif
    else if(DEM_DTC_DATAENTRYREF(DtcId) == DEM_DATA_INVALID_U16)
    {
        *SizeOfExtendedDataRecord = 0U;
        Result = DEM_GETSIZEBYDTC_WRONG_RECNUM;
#if(DEM_NUM_OF_EXTDATACLASS > 0U)
        for(i = 0U; i < DEM_CFG_DTC_NUM_OF_EXTREC(DtcId); i++)
        {
            RecIdx = (DEM_CFG_DTC_EXTREC_ARRAY(DtcId)[i]);
            RecNum = DEM_CFG_DTC_EXTRECNUM(RecIdx);
            if(RecNum == ExtendedDataNumber)
            {
                Result = DEM_GETSIZEBYDTC_OK;
                break;
            }
        }

        if(ExtendedDataNumber == (uint8)0xFF)
        {
            Result = DEM_GETSIZEBYDTC_OK;
        }
#endif/*#if(DEM_NUM_OF_EXTDATACLASS > 0U)*/
    }
    else
    {
#if(DEM_NUM_OF_EXTDATACLASS > 0U)

        *SizeOfExtendedDataRecord = 0U;
        *ExtendedDataOffset = 0U;
        InvalidDataLength = 0U;
        DataBufferPtr = DEM_PRIMARY_EXTDATA_PTR(DEM_DTC_DATAENTRYREF(DtcId));

        for(i = 0U; i < DEM_CFG_DTC_NUM_OF_EXTREC(DtcId); i++)
        {
            RecIdx = (DEM_CFG_DTC_EXTREC_ARRAY(DtcId)[i]);
            RecNum = DEM_CFG_DTC_EXTRECNUM(RecIdx);
            if(RecNum == ExtendedDataNumber)
            {
                if(*(DataBufferPtr + (*ExtendedDataOffset)) != DEM_DATA_INVALID_U8)
                {
                    /*+ RecNum length(one byte)*/
                    (*SizeOfExtendedDataRecord)++;

                    for(j = 0U; j < DEM_CFG_NUMDATA_OF_EXTRECNUM(RecIdx); j++)
                    {
                        DataIdx = (DEM_CFG_DATAARRAY_OF_EXTRECNUM(RecIdx)[j]);
                        if(DEM_CFG_DATA_IN_DATA(DataIdx) != NULL_PTR)
                        {
                            DataSize = DEM_CFG_DATA_IN_DATA_SIZE(DataIdx);
                            /*SWS_Dem_00817*/
                            *(DataBufferPtr + (*ExtendedDataOffset) + (*SizeOfExtendedDataRecord)) = \
                                    DemInternal_GetDtcInternalData(DtcId, DataIdx);
                            *SizeOfExtendedDataRecord += (uint16)DataSize;
                        }

                        if(DEM_CFG_DATA_CS_DATA(DataIdx) != NULL_PTR)
                        {
                            DataSize = DEM_CFG_DATA_CS_DATA_SIZE(DataIdx);
                            *SizeOfExtendedDataRecord += (uint16)DataSize;
                        }
                    }
                }
                break;
            }
            else
            {
                /*+ RecNum length(one byte)*/
                RecDataSize = 1U;

                for(j = 0U; j < DEM_CFG_NUMDATA_OF_EXTRECNUM(RecIdx); j++)
                {
                    DataIdx = (DEM_CFG_DATAARRAY_OF_EXTRECNUM(RecIdx)[j]);
                    if(DEM_CFG_DATA_IN_DATA(DataIdx) != NULL_PTR)
                    {
                        DataSize = DEM_CFG_DATA_IN_DATA_SIZE(DataIdx);
                        /*SWS_Dem_00817*/
                        *(DataBufferPtr + (*ExtendedDataOffset) + RecDataSize) = \
                                DemInternal_GetDtcInternalData(DtcId, DataIdx);
                        RecDataSize += (uint16)DataSize;
                    }

                    if(DEM_CFG_DATA_CS_DATA(DataIdx) != NULL_PTR)
                    {
                        DataSize = DEM_CFG_DATA_CS_DATA_SIZE(DataIdx);
                        RecDataSize += (uint16)DataSize;
                    }
                }

                if(*(DataBufferPtr + (*ExtendedDataOffset)) == DEM_DATA_INVALID_U8)
                {
                    InvalidDataLength += RecDataSize;
                }
                (*ExtendedDataOffset) += RecDataSize;
            }
        }
        if(ExtendedDataNumber == 0xFFU)
        {
            *SizeOfExtendedDataRecord = (*ExtendedDataOffset - InvalidDataLength);
        }
        else if(i == DEM_CFG_DTC_NUM_OF_EXTREC(DtcId))
        {
            Result = DEM_GETSIZEBYDTC_WRONG_RECNUM;
        }
        else
        {
            /*do nothing*/
        }
#else
        Result = DEM_GETSIZEBYDTC_WRONG_DTC;
#endif
    }
    return Result;
}

#if(DEM_MAX_EXTSIZE_OF_DTC > 0U)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name:
*
* Description:
*
* Inputs:
*
* Outputs:
*
* Return:
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, DEM_CODE) DemInternal_GetAllExtendedData
(
    uint32 DtcId,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DestBuffer
)
{
    uint8 i;
    uint8 j;
    uint8 RecIdx;
    uint8 DataIdx;
    uint8 DataSize;
    uint8 *SrcBufferPtr = DEM_PRIMARY_EXTDATA_PTR(DEM_DTC_DATAENTRYREF(DtcId));

    for(i = 0U; i < DEM_CFG_DTC_NUM_OF_EXTREC(DtcId); i++)
    {
        RecIdx = (DEM_CFG_DTC_EXTREC_ARRAY(DtcId)[i]);

        if(*SrcBufferPtr != DEM_DATA_INVALID_U8)
        {
            /*RecNum(one byte)*/
            Bsw_MemCpy(DestBuffer, SrcBufferPtr, 1U);
            DestBuffer++;
            SrcBufferPtr++;

            for(j = 0U; j < DEM_CFG_NUMDATA_OF_EXTRECNUM(RecIdx); j++)
            {
                DataIdx = (DEM_CFG_DATAARRAY_OF_EXTRECNUM(RecIdx)[j]);
                if(DEM_CFG_DATA_IN_DATA(DataIdx) != NULL_PTR)
                {
                    DataSize = DEM_CFG_DATA_IN_DATA_SIZE(DataIdx);
                    Bsw_MemCpy(DestBuffer, SrcBufferPtr, DataSize);
                    DestBuffer += DataSize;
                    SrcBufferPtr += DataSize;
                }

                if(DEM_CFG_DATA_CS_DATA(DataIdx) != NULL_PTR)
                {
                    DataSize = DEM_CFG_DATA_CS_DATA_SIZE(DataIdx);
                    Bsw_MemCpy(DestBuffer, SrcBufferPtr, DataSize);
                    DestBuffer += DataSize;
                    SrcBufferPtr += DataSize;
                }
            }
        }
        else
        {
            /*RecNum(one byte)*/
            SrcBufferPtr++;

            for(j = 0U; j < DEM_CFG_NUMDATA_OF_EXTRECNUM(RecIdx); j++)
            {
                DataIdx = (DEM_CFG_DATAARRAY_OF_EXTRECNUM(RecIdx)[j]);
                if(DEM_CFG_DATA_IN_DATA(DataIdx) != NULL_PTR)
                {
                    DataSize = DEM_CFG_DATA_IN_DATA_SIZE(DataIdx);
                    SrcBufferPtr += DataSize;
                }

                if(DEM_CFG_DATA_CS_DATA(DataIdx) != NULL_PTR)
                {
                    DataSize = DEM_CFG_DATA_CS_DATA_SIZE(DataIdx);
                    SrcBufferPtr += DataSize;
                }
            }
        }
    }
}
#endif

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name:
*
* Description:
*
* Inputs:
*
* Outputs:
*
* Return:
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(Dem_ReturnGetSizeOfDataByDTCType, DEM_CODE) DemInternal_GetSizeOfFFData
(
    uint32 DTC,
    Dem_DTCOriginType DTCOrigin,
    uint8 RecordNumber,
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) SizeOfFreezeFrame,
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) FFDataOffset
)
{
    Dem_ReturnGetSizeOfDataByDTCType Result = DEM_GETSIZEBYDTC_OK;
    uint16 DtcId;
#if(DEM_NUM_OF_FFRECCLASS > 0U)
    uint8 i;
    uint8 j;
    uint8 k;
    uint8 RecIdx;
    uint8 DidIdx;
    uint8 DataIdx;
    uint8 RecNum = 0U;
    uint8 DataSize;
    uint8 *DataBufferPtr;
    uint16 RecDataSize;
    uint16 InvalidDataLength;
#endif
    if(SizeOfFreezeFrame == NULL_PTR)
    {
        Result = DEM_GETSIZEBYDTC_WRONG_RECNUM;
    }
    else if(DTCOrigin != DEM_DTC_ORIGIN_PRIMARY_MEMORY)
    {
        /*SWS_Dem_00171*/
        Result = DEM_GETSIZEBYDTC_WRONG_DTCORIGIN;
    }
    else if(RecordNumber == 0U)
    {
        Result = DEM_GETSIZEBYDTC_WRONG_RECNUM;
    }
    else if(E_OK != DemInternal_CheckDtcValid(DTC, &DtcId))
    {
        /*SWS_Dem_00172*/
        Result = DEM_GETSIZEBYDTC_WRONG_DTC;
    }
#if(DEM_NUM_OF_FFRECCLASS > 0U)
    else if(DEM_CFG_DTC_FFRECNUMCLASSREF(DtcId) == NULL_PTR)
    {
        Result = DEM_GETSIZEBYDTC_WRONG_RECNUM;
    }
#endif
    else if(DEM_DTC_DATAENTRYREF(DtcId) == DEM_DATA_INVALID_U16)
    {
        *SizeOfFreezeFrame = 0U;
        Result = DEM_GETSIZEBYDTC_WRONG_RECNUM;
#if(DEM_NUM_OF_FFRECCLASS > 0U)
        for(i = 0U; i < DEM_CFG_DTC_NUM_OF_FFREC(DtcId); i++)
        {
            RecIdx = (DEM_CFG_DTC_FFREC_ARRAY(DtcId)[i]);
#if(DEM_CFG_TYPE_OF_FF_RECORD_NUMERATION == DEM_FF_RECNUM_CONFIGURED)
            RecNum = DEM_CFG_DTC_FFRECNUM(RecIdx);
#else
            RecNum++;
#endif
            if(RecNum == RecordNumber)
            {
                Result = DEM_GETSIZEBYDTC_OK;
                break;
            }
        }

        if(RecordNumber == (uint8)0xFF)
        {
            Result = DEM_GETSIZEBYDTC_OK;
        }
#endif/*#if(DEM_NUM_OF_FFRECCLASS > 0U)*/
    }
    else
    {
#if(DEM_NUM_OF_FFRECCLASS > 0U)

        *SizeOfFreezeFrame = 0U;
        *FFDataOffset = 0U;
        InvalidDataLength = 0U;
        DataBufferPtr = DEM_PRIMARY_FFDATA_PTR(DEM_DTC_DATAENTRYREF(DtcId));

        for(i = 0U; i < DEM_CFG_DTC_NUM_OF_FFREC(DtcId); i++)
        {
            RecIdx = (DEM_CFG_DTC_FFREC_ARRAY(DtcId)[i]);
#if(DEM_CFG_TYPE_OF_FF_RECORD_NUMERATION == DEM_FF_RECNUM_CONFIGURED)
            /*SWS_Dem_00582*/
            RecNum = DEM_CFG_DTC_FFRECNUM(RecIdx);
#else
            /*SWS_Dem_00337*//*SWS_Dem_00581*/
            RecNum++;
#endif
            if(RecNum == RecordNumber)
            {
                if(*(DataBufferPtr + (*FFDataOffset)) != DEM_DATA_INVALID_U8)
                {
                    /*+ RecNum length(one byte) + RecordNumberOfIdentifiers length(one byte)*/
                    *SizeOfFreezeFrame += 2U;

                    for(j = 0U; j < DEM_CFG_NUMDID_OF_FFRECNUM(RecIdx); j++)
                    {
                        /*Did length(two bytes)*/
                        *SizeOfFreezeFrame += 2U;

                        DidIdx = (DEM_CFG_DIDARRAY_OF_FFRECNUM(RecIdx)[j]);
                        for(k = 0U; k < DEM_CFG_NUMDATA_OF_DID(DidIdx); k++)
                        {
                            DataIdx = (DEM_CFG_DATAARRAY_OF_DID(DidIdx)[k]);
                            if(DEM_CFG_DATA_IN_DATA(DataIdx) != NULL_PTR)
                            {
                                DataSize = DEM_CFG_DATA_IN_DATA_SIZE(DataIdx);
                                /*SWS_Dem_00817*/
                                *(DataBufferPtr + (*FFDataOffset) + (*SizeOfFreezeFrame)) = \
                                        DemInternal_GetDtcInternalData(DtcId, DataIdx);
                                *SizeOfFreezeFrame += (uint16)DataSize;
                            }

                            if(DEM_CFG_DATA_CS_DATA(DataIdx) != NULL_PTR)
                            {
                                DataSize = DEM_CFG_DATA_CS_DATA_SIZE(DataIdx);
                                *SizeOfFreezeFrame += (uint16)DataSize;
                            }
                        }
                    }
                }
                break;
            }
            else
            {
                /*+ RecNum length(one byte) + RecordNumberOfIdentifiers length(one byte)*/
                RecDataSize = 2U;

                for(j = 0U; j < DEM_CFG_NUMDID_OF_FFRECNUM(RecIdx); j++)
                {
                    /*Did length(two bytes)*/
                    RecDataSize += 2U;

                    DidIdx = (DEM_CFG_DIDARRAY_OF_FFRECNUM(RecIdx)[j]);
                    for(k = 0U; k < DEM_CFG_NUMDATA_OF_DID(DidIdx); k++)
                    {
                        DataIdx = (DEM_CFG_DATAARRAY_OF_DID(DidIdx)[k]);
                        if(DEM_CFG_DATA_IN_DATA(DataIdx) != NULL_PTR)
                        {
                            DataSize = DEM_CFG_DATA_IN_DATA_SIZE(DataIdx);
                            /*SWS_Dem_00817*/
                            *(DataBufferPtr + (*FFDataOffset) + RecDataSize) = \
                                    DemInternal_GetDtcInternalData(DtcId, DataIdx);
                            RecDataSize += (uint16)DataSize;
                        }

                        if(DEM_CFG_DATA_CS_DATA(DataIdx) != NULL_PTR)
                        {
                            DataSize = DEM_CFG_DATA_CS_DATA_SIZE(DataIdx);
                            RecDataSize += (uint16)DataSize;
                        }
                    }
                }

                if(*(DataBufferPtr + (*FFDataOffset)) == DEM_DATA_INVALID_U8)
                {
                    InvalidDataLength += RecDataSize;
                }
                (*FFDataOffset) += RecDataSize;
            }
        }

        if(RecordNumber == 0xFFU)
        {
            *SizeOfFreezeFrame = (*FFDataOffset - InvalidDataLength);
        }
        else if(i == DEM_CFG_DTC_NUM_OF_FFREC(DtcId))
        {
            Result = DEM_GETSIZEBYDTC_WRONG_RECNUM;
        }
        else
        {
            /*do nothing*/
        }
#else
        Result = DEM_GETSIZEBYDTC_WRONG_RECNUM;
#endif
    }
    return Result;
}

#if(DEM_MAX_FFSIZE_OF_DTC > 0U)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name:
*
* Description:
*
* Inputs:
*
* Outputs:
*
* Return:
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, DEM_CODE) DemInternal_GetAllFFData
(
    uint32 DtcId,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DestBuffer
)
{
    uint8 i;
    uint8 j;
    uint8 k;
    uint8 RecIdx;
    uint8 DidIdx;
    uint8 DataIdx;
    uint8 DataSize;
    uint8 *SrcBufferPtr = DEM_PRIMARY_FFDATA_PTR(DEM_DTC_DATAENTRYREF(DtcId));

    for(i = 0U; i < DEM_CFG_DTC_NUM_OF_FFREC(DtcId); i++)
    {
        RecIdx = (DEM_CFG_DTC_FFREC_ARRAY(DtcId)[i]);

        if(*SrcBufferPtr != DEM_DATA_INVALID_U8)
        {
            /*+ RecNum(one byte) + RecordNumberOfIdentifiers(one byte)*/
            Bsw_MemCpy(DestBuffer, SrcBufferPtr, 2U);
            DestBuffer += 2U;
            SrcBufferPtr += 2U;

            for(j = 0U; j < DEM_CFG_NUMDID_OF_FFRECNUM(RecIdx); j++)
            {
                /*Did(two bytes)*/
                Bsw_MemCpy(DestBuffer, SrcBufferPtr, 2U);
                DestBuffer += 2U;
                SrcBufferPtr += 2U;

                DidIdx = (DEM_CFG_DIDARRAY_OF_FFRECNUM(RecIdx)[j]);
                for(k = 0U; k < DEM_CFG_NUMDATA_OF_DID(DidIdx); k++)
                {
                    DataIdx = (DEM_CFG_DATAARRAY_OF_DID(DidIdx)[k]);
                    if(DEM_CFG_DATA_IN_DATA(DataIdx) != NULL_PTR)
                    {
                        DataSize = DEM_CFG_DATA_IN_DATA_SIZE(DataIdx);
                        Bsw_MemCpy(DestBuffer, SrcBufferPtr, DataSize);
                        DestBuffer += DataSize;
                        SrcBufferPtr += DataSize;
                    }

                    if(DEM_CFG_DATA_CS_DATA(DataIdx) != NULL_PTR)
                    {
                        DataSize = DEM_CFG_DATA_CS_DATA_SIZE(DataIdx);
                        Bsw_MemCpy(DestBuffer, SrcBufferPtr, DataSize);
                        DestBuffer += DataSize;
                        SrcBufferPtr += DataSize;
                    }
                }
            }
        }
        else
        {
            /*+ RecNum(one byte) + RecordNumberOfIdentifiers(one byte)*/
            SrcBufferPtr += 2U;

            for(j = 0U; j < DEM_CFG_NUMDID_OF_FFRECNUM(RecIdx); j++)
            {
                /*Did(two bytes)*/
                SrcBufferPtr += 2U;

                DidIdx = (DEM_CFG_DIDARRAY_OF_FFRECNUM(RecIdx)[j]);
                for(k = 0U; k < DEM_CFG_NUMDATA_OF_DID(DidIdx); k++)
                {
                    DataIdx = (DEM_CFG_DATAARRAY_OF_DID(DidIdx)[k]);
                    if(DEM_CFG_DATA_IN_DATA(DataIdx) != NULL_PTR)
                    {
                        DataSize = DEM_CFG_DATA_IN_DATA_SIZE(DataIdx);
                        SrcBufferPtr += DataSize;
                    }

                    if(DEM_CFG_DATA_CS_DATA(DataIdx) != NULL_PTR)
                    {
                        DataSize = DEM_CFG_DATA_CS_DATA_SIZE(DataIdx);
                        SrcBufferPtr += DataSize;
                    }
                }
            }
        }
    }
}
#endif

/*******************************************************************************
*   Dem_Dcm Api definition
*******************************************************************************/

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_DcmGetTranslationType
*
* Description: Gets the supported DTC formats of the ECU. The supported formats are
*                  configured via DemTypeOfDTCSupported.
*
* Inputs: None
*
* Outputs: None
*
* Return: Dem_DTCTranslationFormatType: Returns the configured DTC translation format.
*                         A combination of different DTC formats is not possible.
*
* Limitations: Synchronous
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Dem_DTCTranslationFormatType, DEM_CODE) Dem_DcmGetTranslationType
(
    void
)
{
    /*SWS_Dem_00231*/
    return DEM_CFG_TYPE_OF_DTC_SUPPORTED;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_DcmGetDTCStatusAvailabilityMask
*
* Description: Gets the DTC Status availability mask.
*
* Inputs: None
*
* Outputs: DTCStatusMask: The value DTCStatusMask indicates the supported DTC status bits
*                                     from the Dem. All supported information is indicated by setting the
*                                     corresponding status bit to 1. See ISO14229-1.
*
* Return: Std_ReturnType: E_OK: get of DTC status mask was successful
*                                    E_NOT_OK: get of DTC status mask failed
*
* Limitations: Synchronous
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, DEM_CODE) Dem_DcmGetDTCStatusAvailabilityMask
(
    P2VAR(Dem_UdsStatusByteType, AUTOMATIC, DEM_APPL_DATA) DTCStatusMask
)
{
    Std_ReturnType Result = E_OK;

    if(DTCStatusMask == NULL_PTR)
    {
        DEM_DET_REPORT_ERROR(DEM_DCMGETDTCSTATUSAVAILABILITYMASK_APIID, DEM_E_PARAM_POINTER);
        Result = E_NOT_OK;
    }
    else
    {
        /*SWS_Dem_00060*/
        *DTCStatusMask = DEM_CFG_DTCSTATUSAVAILABILITYMASK;
    }
    return Result;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_DcmGetStatusOfDTC
*
* Description: Gets the status of a DTC. The DTCs of OBD Events Suppression shall be
*                  reported as DEM_STATUS_WRONG_DTC.
*
* Inputs: DTC: Diagnostic Trouble Code in UDS format.
*            DTCOrigin: If the Dem supports more than one event memory this parameter is used
*                           to select the source memory the DTCs shall be read from.
*
* Outputs: DTCStatus: This parameter receives the status information of the requested DTC.
*                              If the return value of the function call is other than DEM_STATUS_OK
*                              this parameter does not contain valid data. 0x00...0xFF match
*                              DTCStatusMask as defined in ISO14229-1
*
* Return: Dem_ReturnGetStatusOfDTCType: Status of the operation
*
* Limitations: Synchronous
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Dem_ReturnGetStatusOfDTCType, DEM_CODE) Dem_DcmGetStatusOfDTC
(
    uint32 DTC,
    Dem_DTCOriginType DTCOrigin,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DTCStatus
)
{
    Dem_ReturnGetStatusOfDTCType Result = DEM_STATUS_OK;
    uint16 DtcId;
#if(DEM_CFG_MAXNUMBEREVENTENTRY_PERMANENT > 0)
    uint8 Index;
    Dem_EventIdType EventId;
#endif

    if(Dem_State != DEM_NORMAL)
    {
        /*SWS_Dem_01112*//*SWS_Dem_00124*/
        DEM_DET_REPORT_ERROR(DEM_DCMGETSTATUSOFDTC_APIID, DEM_E_UNINIT);
        Result = DEM_STATUS_FAILED;
    }
    else if((DTC == (Dem_UdsDTCType)0) || (DTC > DEM_DTC_GROUP_ALL))
    {
        DEM_DET_REPORT_ERROR(DEM_DCMGETSTATUSOFDTC_APIID, DEM_E_PARAM_DATA);
        Result = DEM_STATUS_WRONG_DTC;
    }
    else if((DTCOrigin != DEM_DTC_ORIGIN_PRIMARY_MEMORY) \
        && (DTCOrigin != DEM_DTC_ORIGIN_PERMANENT_MEMORY))
    {
        DEM_DET_REPORT_ERROR(DEM_DCMGETSTATUSOFDTC_APIID, DEM_E_PARAM_DATA);
        /*SWS_Dem_00171*/
        Result = DEM_STATUS_WRONG_DTCORIGIN;
    }
    else if(E_OK != DemInternal_CheckDtcValid(DTC, &DtcId))
    {
        /*SWS_Dem_00172*/
        Result = DEM_STATUS_WRONG_DTC;
    }
    else
    {
        /*SWS_Dem_00059*/
        if(DTCOrigin == DEM_DTC_ORIGIN_PRIMARY_MEMORY)
        {
            *DTCStatus = ((DEM_DTC_STATUS(DtcId)) & (DEM_CFG_DTCSTATUSAVAILABILITYMASK));
        }
#if(DEM_CFG_MAXNUMBEREVENTENTRY_PERMANENT > 0)
        else if(DTCOrigin == DEM_DTC_ORIGIN_PERMANENT_MEMORY)
        {
            for(Index = 0; Index < DEM_CFG_MAXNUMBEREVENTENTRY_PERMANENT; Index++)
            {
                EventId = DEM_PERMANENT_DATAENTRY_EVENTID(Index);

                if((EventId != DEM_EVENT_ID_INVALID) \
                    && (DtcId == DEM_CFG_EVENT_DTCREF(EventId)))
                {
                    *DTCStatus = ((DEM_DTC_STATUS(DtcId)) & (DEM_CFG_DTCSTATUSAVAILABILITYMASK));
                    break;
                }
            }

            if(Index == DEM_CFG_MAXNUMBEREVENTENTRY_PERMANENT)
            {
                Result = DEM_STATUS_FAILED;
            }
        }
#endif
        else
        {
            Result = DEM_STATUS_WRONG_DTCORIGIN;
        }
    }
    return Result;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_DcmGetSeverityOfDTC
*
* Description: Gets the severity of the requested DTC.
*
* Inputs: DTC: Diagnostic Trouble Code in UDS format.
*
* Outputs: DTCSeverity: This parameter contains the DTCSeverity according to ISO 14229-1.
*
* Return: Dem_ReturnGetSeverityOfDTCType: Status of the operation
*
* Limitations: Synchronous
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Dem_ReturnGetSeverityOfDTCType, DEM_CODE) Dem_DcmGetSeverityOfDTC
(
    uint32 DTC,
    P2VAR(Dem_DTCSeverityType, AUTOMATIC, DEM_APPL_DATA) DTCSeverity
)
{
    Dem_ReturnGetSeverityOfDTCType Result = DEM_GET_SEVERITYOFDTC_OK;
    uint16 DtcId;

    if(DTCSeverity == NULL_PTR)
    {
        DEM_DET_REPORT_ERROR(DEM_DCMGETSEVERITYOFDTC_APIID, DEM_E_PARAM_POINTER);
        Result = DEM_GET_SEVERITYOFDTC_NOSEVERITY;
    }
    else if(E_OK != DemInternal_CheckDtcValid(DTC, &DtcId))
    {
        /*SWS_Dem_00172*/
        Result = DEM_GET_SEVERITYOFDTC_WRONG_DTC;
    }
    else
    {
        *DTCSeverity = DEM_CFG_DTC_SEVERITY(DtcId);
    }
    return Result;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_DcmGetFunctionalUnitOfDTC
*
* Description: Gets the functional unit of the requested DTC.
*
* Inputs: DTC: Diagnostic Trouble Code in UDS format.
*
* Outputs: DTCFunctionalUnit: Functional unit value of this DTC
*
* Return: Dem_ReturnGetFunctionalUnitOfDTCType: Status of the operation
*
* Limitations: Synchronous
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Dem_ReturnGetFunctionalUnitOfDTCType, DEM_CODE) Dem_DcmGetFunctionalUnitOfDTC
(
    uint32 DTC,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DTCFunctionalUnit
)
{
    Dem_ReturnGetFunctionalUnitOfDTCType Result = DEM_GET_FUNCTIONALUNITOFDTC_OK;
    uint16 DtcId;

    if(DTCFunctionalUnit == NULL_PTR)
    {
        DEM_DET_REPORT_ERROR(DEM_DCMGETFUNCTIONALUNITOFDTC_APIID, DEM_E_PARAM_POINTER);
        /*SWS_Dem_00172*/
        Result = DEM_GET_FUNCTIONALUNITOFDTC_WRONG_DTC;
    }
    else if(E_OK != DemInternal_CheckDtcValid(DTC, &DtcId))
    {
        /*SWS_Dem_00172*/
        Result = DEM_GET_FUNCTIONALUNITOFDTC_WRONG_DTC;
    }
    else
    {
        *DTCFunctionalUnit = DEM_CFG_DTC_FNCUNIT(DtcId);
    }
    return Result;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_DcmSetDTCFilter
*
* Description: Sets the DTC Filter.
*
* Inputs: DTCStatusMask: Status-byte mask for DTC status-byte filtering
*         DTCKind: Defines the functional group of DTCs to be reported
*         DTCFormat: Defines the output-format of the requested DTC values for the sub-sequent API calls.
*         DTCOrigin: If the Dem supports more than one event memory this parameter is used
*                    to select the source memory the DTCs shall be read from.
*         FilterWithSeverity: This flag defines whether severity information shall be used for filtering.
*         DTCSeverityMask: This parameter contains the DTCSeverityMask according to ISO14229-1
*         FilterForFaultDetectionCounter: This flag defines whether the fault detection counter
*                                         information shall be used for filtering.
*
* Outputs: None
*
* Return: Dem_ReturnSetFilterType: Status of the operation to (re-)set a DTC filter.
*
* Limitations: Synchronous & Non Reentrant
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Dem_ReturnSetFilterType, DEM_CODE) Dem_DcmSetDTCFilter
(
    Dem_UdsStatusByteType DTCStatusMask,
    Dem_DTCKindType DTCKind,
    Dem_DTCFormatType DTCFormat,
    Dem_DTCOriginType DTCOrigin,
    boolean FilterWithSeverity,
    Dem_DTCSeverityType DTCSeverityMask,
    boolean FilterForFaultDetectionCounter
)
{
    Dem_ReturnSetFilterType Result = DEM_WRONG_FILTER;
    uint16 DtcId;
    uint8 StatusFilterMask;
#if(DEM_CFG_MAXNUMBEREVENTENTRY_PERMANENT > 0)
    uint8 Index;
#endif

    if(Dem_State != DEM_NORMAL)
    {
        /*SWS_Dem_01112*//*SWS_Dem_00124*/
        DEM_DET_REPORT_ERROR(DEM_DCMSETDTCFILTER_APIID, DEM_E_UNINIT);
    }
    else if((DTCKind != DEM_DTC_KIND_ALL_DTCS) \
        && (DTCKind != DEM_DTC_KIND_EMISSION_REL_DTCS))
    {
        /*SWS_Dem_01065*/
        DEM_DET_REPORT_ERROR(DEM_DCMSETDTCFILTER_APIID, DEM_E_WRONG_CONFIGURATION);
    }
    else if((DTCFormat != DEM_DTC_FORMAT_UDS) \
        && (DTCFormat != DEM_DTC_FORMAT_OBD) \
        && (DTCFormat != DEM_DTC_FORMAT_J1939))
    {
        /*SWS_Dem_01066*/
        DEM_DET_REPORT_ERROR(DEM_DCMSETDTCFILTER_APIID, DEM_E_WRONG_CONFIGURATION);
    }

    else if((DTCOrigin != DEM_DTC_ORIGIN_PRIMARY_MEMORY) \
        && (DTCOrigin != DEM_DTC_ORIGIN_PERMANENT_MEMORY))
    {
        /*SWS_Dem_01067*/
        DEM_DET_REPORT_ERROR(DEM_DCMSETDTCFILTER_APIID, DEM_E_WRONG_CONFIGURATION);
    }
    else
    {
        /*SWS_Dem_00057*//*SWS_Dem_00649*/
        Dem_DcmFilterInfo.DTCStatusMask = DTCStatusMask;
        Dem_DcmFilterInfo.DTCKind = DTCKind;
        Dem_DcmFilterInfo.DTCFormat = DTCFormat;
        Dem_DcmFilterInfo.DTCOrigin = DTCOrigin;
        Dem_DcmFilterInfo.FilterWithSeverity = FilterWithSeverity;
        Dem_DcmFilterInfo.DTCSeverityMask = DTCSeverityMask;
        /*If fault detection counter information is filter criteria, only those DTCs with a
        fault detection counter value between 1 and 0x7E shall be reported.*/
        /*But for geely, FDC value between -128 and 127 shall be reported.*/
        Dem_DcmFilterInfo.FilterForFDC = FilterForFaultDetectionCounter;
        Dem_DcmFilterInfo.NumberOfFilteredDTC = 0;
        Dem_DcmFilterInfo.NextFilteredDTCIndex = 0;
        /*SWS_Dem_00657*//*SWS_Dem_01058*/
        StatusFilterMask = (DTCStatusMask & DEM_CFG_DTCSTATUSAVAILABILITYMASK);

        if(DTCOrigin == DEM_DTC_ORIGIN_PRIMARY_MEMORY)
        {
            for(DtcId = 0; DtcId < DEM_NUM_OF_DTC; DtcId++)
            {
                if(((FilterWithSeverity == FALSE) || ((DEM_CFG_DTC_SEVERITY(DtcId) & DTCSeverityMask) != 0)) \
                    && ((DTCStatusMask == 0) || ((DEM_DTC_STATUS(DtcId) & StatusFilterMask) != 0)))
                {
#if((DEM_CFG_OBD_SUPPORT == DEM_OBD_MASTER_ECU)||(DEM_CFG_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU))
                    if(((DTCKind == DEM_DTC_KIND_ALL_DTCS) && (DEM_CFG_DTC_VALUE(DtcId) != 0)) \
                        || ((DTCKind == DEM_DTC_KIND_EMISSION_REL_DTCS) && DEM_DTC_IS_OBD(DtcId)))
#else
                    if((DTCKind == DEM_DTC_KIND_ALL_DTCS) && (DEM_CFG_DTC_VALUE(DtcId) != 0))
#endif
                    {
                        /*DTCStatusMask 0x00: Autosar-specific value to deactivate the status-byte filtering
                        (different meaning than in ISO 14229-1) to report all supported DTCs (used for
                        service 0x19 subfunctions 0x0A/0x15)*/
                        Dem_DcmFilterInfo.FilteredDTCIndexTable[Dem_DcmFilterInfo.NumberOfFilteredDTC] = DtcId;
                        Dem_DcmFilterInfo.NumberOfFilteredDTC++;
                    }
                }
            }/*for(DtcId = 0; DtcId < DEM_NUM_OF_DTC; DtcId++)*/
        }
#if(DEM_CFG_MAXNUMBEREVENTENTRY_PERMANENT > 0)
        else
        {
            /*Permanent memory entry, only has emission related DTCs*/
            for(Index = 0; Index < DEM_CFG_MAXNUMBEREVENTENTRY_PERMANENT; Index++)
            {
                if(DEM_PERMANENT_DATAENTRY_EVENTID(Index) != DEM_EVENT_ID_INVALID)
                {
                    DtcId = DEM_CFG_EVENT_DTCREF(DEM_PERMANENT_DATAENTRY_EVENTID(Index));

                    if(((FilterWithSeverity == FALSE) || ((DEM_CFG_DTC_SEVERITY(DtcId) & DTCSeverityMask) != 0)) \
                        && ((DTCStatusMask == 0) || ((DEM_DTC_STATUS(DtcId) & StatusFilterMask) != 0)))
                    {
                        Dem_DcmFilterInfo.FilteredDTCIndexTable[Dem_DcmFilterInfo.NumberOfFilteredDTC] = DtcId;
                        Dem_DcmFilterInfo.NumberOfFilteredDTC++;
                    }
                }
            }/*for(Index = 0; Index < DEM_CFG_MAXNUMBEREVENTENTRY_PERMANENT; Index++)*/
        }
#endif
        Dem_DcmFilterInfo.FilteredValidFlag = TRUE;

        Result = DEM_FILTER_ACCEPTED;
    }
    return Result;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_DcmGetNumberOfFilteredDTC
*
* Description: Gets the number of a filtered DTC.
*
* Inputs: None
*
* Outputs: NumberOfFilteredDTC: The number of DTCs matching the defined status mask.
*
* Return: Dem_ReturnGetNumberOfFilteredDTCType: Status of the operation to retrieve a
*                                                                       number of DTC from the Dem
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Dem_ReturnGetNumberOfFilteredDTCType, DEM_CODE) Dem_DcmGetNumberOfFilteredDTC
(
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) NumberOfFilteredDTC
)
{
    Dem_ReturnGetNumberOfFilteredDTCType Result = DEM_NUMBER_OK;

    if(Dem_State != DEM_NORMAL)
    {
        /*SWS_Dem_01112*//*SWS_Dem_00124*/
        DEM_DET_REPORT_ERROR(DEM_DCMGETNUMBEROFFILTEREDDTC_APIID, DEM_E_UNINIT);
        Result = DEM_NUMBER_FAILED;
    }
    else if(NumberOfFilteredDTC == NULL_PTR)
    {
        DEM_DET_REPORT_ERROR(DEM_DCMGETNUMBEROFFILTEREDDTC_APIID, DEM_E_PARAM_POINTER);
        Result = DEM_NUMBER_FAILED;
    }
    else if(Dem_DcmFilterInfo.FilteredValidFlag != TRUE)
    {
        Result = DEM_NUMBER_FAILED;
    }
    else
    {
        /*SWS_Dem_00061*/
        *NumberOfFilteredDTC = Dem_DcmFilterInfo.NumberOfFilteredDTC;
    }
    return Result;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_DcmGetNextFilteredDTC
*
* Description: Gets the next filtered DTC matching the filter criteria. For UDS services, the
*                  interface has an asynchronous behavior, because a large number of DTCs has to
*                  be processed.
*
* Inputs: None
*
* Outputs: DTC: Receives the DTC value in respective format of the filter returned by this function.
*              DTCStatus: This parameter receives the status information of the requested DTC.
*
* Return: Dem_ReturnGetNextFilteredElementType: Status of the operation to retrieve a
*                                                                       DTC from the Dem
*
* Limitations: Synchronous
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Dem_ReturnGetNextFilteredElementType, DEM_CODE) Dem_DcmGetNextFilteredDTC
(
    P2VAR(uint32, AUTOMATIC, DEM_APPL_DATA) DTC,
    P2VAR(Dem_UdsStatusByteType, AUTOMATIC, DEM_APPL_DATA) DTCStatus
)
{
    /*SWS_Dem_00653*/
    Dem_ReturnGetNextFilteredElementType Result = DEM_FILTERED_OK;
    uint16 DtcId;

    if((DTC == NULL_PTR) || (DTCStatus == NULL_PTR))
    {
        DEM_DET_REPORT_ERROR(DEM_DCMGETNEXTFILTEREDDTC_APIID, DEM_E_PARAM_POINTER);
        Result = DEM_FILTERED_BUFFER_TOO_SMALL;
    }
    else if(Dem_DcmFilterInfo.FilteredValidFlag != TRUE)
    {
        Result = DEM_FILTERED_NO_MATCHING_ELEMENT;
    }
    else if(Dem_DcmFilterInfo.NextFilteredDTCIndex >= Dem_DcmFilterInfo.NumberOfFilteredDTC)
    {
        Dem_DcmFilterInfo.FilteredValidFlag = FALSE;
        Dem_DcmFilterInfo.NextFilteredDTCIndex = 0;
        Dem_DcmFilterInfo.NumberOfFilteredDTC = 0;

        Result = DEM_FILTERED_NO_MATCHING_ELEMENT;
    }
    else
    {
        /*SWS_Dem_00216*/
        DtcId = Dem_DcmFilterInfo.FilteredDTCIndexTable[Dem_DcmFilterInfo.NextFilteredDTCIndex];
        *DTC = DEM_CFG_DTC_VALUE(DtcId);

#if((DEM_CFG_OBD_SUPPORT == DEM_OBD_MASTER_ECU)||(DEM_CFG_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU))
        if((Dem_DcmFilterInfo.DTCFormat == DEM_DTC_FORMAT_OBD) \
            && (DEM_CFG_DTC_OBDDTCREF(DtcId) != NULL_PTR))
        {
            *DTC = DEM_CFG_DTC_OBD_VALUE(DtcId);
        }
#endif
#if(DEM_J1939_SUPPORT == STD_ON)
        if((Dem_DcmFilterInfo.DTCFormat == DEM_DTC_FORMAT_J1939) \
            && (DEM_CFG_DTC_OBDDTCREF(DtcId) != NULL_PTR))
        {
            *DTC = DEM_CFG_DTC_J1939_VALUE(DtcId);
        }
#endif

        *DTCStatus = ((DEM_DTC_STATUS(DtcId)) & (DEM_CFG_DTCSTATUSAVAILABILITYMASK));
        Dem_DcmFilterInfo.NextFilteredDTCIndex++;
    }
    return Result;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_DcmGetNextFilteredDTCAndFDC
*
* Description: Gets the next filtered DTC and its associated Fault Detection Counter (FDC)
*                  matching the filter criteria.
*
* Inputs: None
*
* Outputs: DTC: Receives the DTC value in respective format of the filter returned by this function.
*              DTCFaultDetectionCounter: This parameter receives the Fault Detection Counter
*                                                    information of the requested DTC
*
* Return: Dem_ReturnGetNextFilteredElementType: Status of the operation to retrieve a
*                                                                       DTC from the Dem
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Dem_ReturnGetNextFilteredElementType, DEM_CODE) Dem_DcmGetNextFilteredDTCAndFDC
(
    P2VAR(uint32, AUTOMATIC, DEM_APPL_DATA) DTC,
    P2VAR(sint8, AUTOMATIC, DEM_APPL_DATA) DTCFaultDetectionCounter
)
{
    Dem_ReturnGetNextFilteredElementType Result = DEM_FILTERED_OK;
    uint16 DtcId;
    Std_ReturnType ret = E_OK;

    if((DTC == NULL_PTR) || (DTCFaultDetectionCounter == NULL_PTR))
    {
        DEM_DET_REPORT_ERROR(DEM_DCMGETNEXTFILTEREDDTCANDFDC_APIID, DEM_E_PARAM_POINTER);
        Result = DEM_FILTERED_NO_MATCHING_ELEMENT;
    }
    else if((Dem_DcmFilterInfo.FilteredValidFlag != TRUE) || (Dem_DcmFilterInfo.FilterForFDC != TRUE))
    {
        /*SWS_Dem_00518*/
        DEM_DET_REPORT_ERROR(DEM_DCMGETNEXTFILTEREDDTCANDFDC_APIID, DEM_E_WRONG_CONDITION);
        Result = DEM_FILTERED_NO_MATCHING_ELEMENT;
    }
    else if(Dem_DcmFilterInfo.NextFilteredDTCIndex >= Dem_DcmFilterInfo.NumberOfFilteredDTC)
    {
        Dem_DcmFilterInfo.FilteredValidFlag = FALSE;
        Dem_DcmFilterInfo.FilterForFDC = FALSE;
        Dem_DcmFilterInfo.NextFilteredDTCIndex = 0;
        Dem_DcmFilterInfo.NumberOfFilteredDTC = 0;

        Result = DEM_FILTERED_NO_MATCHING_ELEMENT;
    }
    else
    {
        /*SWS_Dem_00228*/
        DtcId = Dem_DcmFilterInfo.FilteredDTCIndexTable[Dem_DcmFilterInfo.NextFilteredDTCIndex];
        *DTC = DEM_CFG_DTC_VALUE(DtcId);

#if((DEM_CFG_OBD_SUPPORT == DEM_OBD_MASTER_ECU)||(DEM_CFG_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU))
        if((Dem_DcmFilterInfo.DTCFormat == DEM_DTC_FORMAT_OBD) \
            && (DEM_CFG_DTC_OBDDTCREF(DtcId) != NULL_PTR))
        {
            *DTC = DEM_CFG_DTC_OBD_VALUE(DtcId);
        }
#endif
#if(DEM_J1939_SUPPORT == STD_ON)
        if((Dem_DcmFilterInfo.DTCFormat == DEM_DTC_FORMAT_J1939) \
            && (DEM_CFG_DTC_OBDDTCREF(DtcId) != NULL_PTR))
        {
            *DTC = DEM_CFG_DTC_J1939_VALUE(DtcId);
        }
#endif

        if(DEM_CFG_EVENT_GET_FDC_FNC(DtcId) != NULL_PTR)
        {
            /*SWS_Dem_00513*/
            ret = (DEM_CFG_EVENT_GET_FDC_FNC(DtcId))(DTCFaultDetectionCounter);
            if(ret != E_OK)
            {
                Result = DEM_FILTERED_NO_MATCHING_ELEMENT;
            }
        }
#if(DEM_CFG_DEBOUNCECOUNTERBASEDSUPPORT == STD_ON)
        else if(DEM_CFG_EVENT_DBC(DtcId) != NULL_PTR)
        {
            /*SWS_Dem_00415*/
            if(DEM_EVENT_DBC(DtcId) >= 0)
            {
                *DTCFaultDetectionCounter = DEM_EVENT_DBC_F_FDC(DtcId);
            }
            else
            {
                *DTCFaultDetectionCounter = DEM_EVENT_DBC_P_FDC(DtcId);
            }
        }
#endif
#if(DEM_CFG_DEBOUNCETIMEBASEDSUPPORT == STD_ON)
        else if(DEM_CFG_EVENT_DBT(DtcId) != NULL_PTR)
        {
            if((DEM_EVENT_TIMERDIRECTION(DtcId) == DEM_EVENT_STATUS_FAILED) \
                    || (DEM_EVENT_TIMERDIRECTION(DtcId) == DEM_EVENT_STATUS_PREFAILED))
            {
                *DTCFaultDetectionCounter = DEM_EVENT_DBT_F_FDC(DtcId);
            }
            else if((DEM_EVENT_TIMERDIRECTION(DtcId) == DEM_EVENT_STATUS_PASSED) \
                    || (DEM_EVENT_TIMERDIRECTION(DtcId) == DEM_EVENT_STATUS_PREPASSED))
            {
                *DTCFaultDetectionCounter = DEM_EVENT_DBT_P_FDC(DtcId);
            }
            else
            {
                *DTCFaultDetectionCounter = 0;
            }
        }
#endif
        else
        {
            Result = DEM_FILTERED_NO_MATCHING_ELEMENT;
        }

        Dem_DcmFilterInfo.NextFilteredDTCIndex++;
    }
    return Result;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_DcmGetNextFilteredDTCAndSeverity
*
* Description: Gets the next filtered DTC and its associated Severity matching the filter criteria.
*
* Inputs: None
*
* Outputs: DTC: Receives the DTC value in respective format of the filter returned by this function.
*              DTCStatus: This parameter receives the status information of the requested DTC.
*              DTCSeverity: Receives the severity value returned by the function.
*              DTCFunctionalUnit: Receives the functional unit value returned by the function.
*
* Return: Dem_ReturnGetNextFilteredElementType: Status of the operation to retrieve a
*                                                                       DTC from the Dem
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Dem_ReturnGetNextFilteredElementType, DEM_CODE) Dem_DcmGetNextFilteredDTCAndSeverity
(
    P2VAR(uint32, AUTOMATIC, DEM_APPL_DATA) DTC,
    P2VAR(Dem_UdsStatusByteType, AUTOMATIC, DEM_APPL_DATA) DTCStatus,
    P2VAR(Dem_DTCSeverityType, AUTOMATIC, DEM_APPL_DATA) DTCSeverity,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DTCFunctionalUnit
)
{
    Dem_ReturnGetNextFilteredElementType Result = DEM_FILTERED_OK;
    uint16 DtcId;

    if((DTC == NULL_PTR) || (DTCStatus == NULL_PTR) \
            || (DTCSeverity == NULL_PTR) || (DTCFunctionalUnit == NULL_PTR))
    {
        DEM_DET_REPORT_ERROR(DEM_DCMGETNEXTFILTEREDDTCANDSEVERITY_APIID, DEM_E_PARAM_POINTER);
        Result = DEM_FILTERED_NO_MATCHING_ELEMENT;
    }
    else if(Dem_DcmFilterInfo.FilteredValidFlag != TRUE)
    {
        Result = DEM_FILTERED_NO_MATCHING_ELEMENT;
    }
    else if(Dem_DcmFilterInfo.NextFilteredDTCIndex >= Dem_DcmFilterInfo.NumberOfFilteredDTC)
    {
        Dem_DcmFilterInfo.FilteredValidFlag = FALSE;
        Dem_DcmFilterInfo.NextFilteredDTCIndex = 0;
        Dem_DcmFilterInfo.NumberOfFilteredDTC = 0;

        Result = DEM_FILTERED_NO_MATCHING_ELEMENT;
    }
    else
    {
        /*SWS_Dem_00287*/
        DtcId = Dem_DcmFilterInfo.FilteredDTCIndexTable[Dem_DcmFilterInfo.NextFilteredDTCIndex];
        *DTC = DEM_CFG_DTC_VALUE(DtcId);

#if((DEM_CFG_OBD_SUPPORT == DEM_OBD_MASTER_ECU)||(DEM_CFG_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU))
        if((Dem_DcmFilterInfo.DTCFormat == DEM_DTC_FORMAT_OBD) \
            && (DEM_CFG_DTC_OBDDTCREF(DtcId) != NULL_PTR))
        {
            *DTC = DEM_CFG_DTC_OBD_VALUE(DtcId);
        }
#endif
#if(DEM_J1939_SUPPORT == STD_ON)
        if((Dem_DcmFilterInfo.DTCFormat == DEM_DTC_FORMAT_J1939) \
            && (DEM_CFG_DTC_OBDDTCREF(DtcId) != NULL_PTR))
        {
            *DTC = DEM_CFG_DTC_J1939_VALUE(DtcId);
        }
#endif
        *DTCStatus = ((DEM_DTC_STATUS(DtcId)) & (DEM_CFG_DTCSTATUSAVAILABILITYMASK));
        *DTCSeverity = DEM_CFG_DTC_SEVERITY(DtcId);
        *DTCFunctionalUnit = DEM_CFG_DTC_FNCUNIT(DtcId);
        Dem_DcmFilterInfo.NextFilteredDTCIndex++;
    }
    return Result;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_DcmSetFreezeFrameRecordFilter
*
* Description: Sets a freeze frame record filter.
*
* Inputs: DTCFormat: Defines the output-format of the requested DTC values for the sub-sequent API calls.
*
* Outputs: NumberOfFilteredRecords: Number of freeze frame records currently stored in the event memory.
*
* Return: Dem_ReturnSetFilterType: Status of the operation to (re-)set a freeze frame record filter.
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Dem_ReturnSetFilterType, DEM_CODE) Dem_DcmSetFreezeFrameRecordFilter
(
    Dem_DTCFormatType DTCFormat,
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) NumberOfFilteredRecords
)
{
    /*SWS_Dem_00595*//*SWS_Dem_00650*/
    Dem_ReturnSetFilterType Result = DEM_FILTER_ACCEPTED;
#if(DEM_NUM_OF_FFRECCLASS > 0)
    uint16 i;
    uint8 j;
    uint32 DTC;
    uint8 RecordNumber;
    uint16 SizeOfFreezeFrame = 0;
    uint16 FFDataOffset = 0;
#endif

    if(Dem_State != DEM_NORMAL)
    {
        /*SWS_Dem_01112*//*SWS_Dem_00124*/
        DEM_DET_REPORT_ERROR(DEM_DCMSETFREEZEFRAMERECORDFILTER_APIID, DEM_E_UNINIT);
        Result = DEM_WRONG_FILTER;
    }
    else if((DTCFormat != DEM_DTC_FORMAT_UDS) \
        && (DTCFormat != DEM_DTC_FORMAT_OBD))
    {
        DEM_DET_REPORT_ERROR(DEM_DCMSETFREEZEFRAMERECORDFILTER_APIID, DEM_E_WRONG_CONFIGURATION);
        Result = DEM_WRONG_FILTER;
    }
    else if(NumberOfFilteredRecords == NULL_PTR)
    {
        DEM_DET_REPORT_ERROR(DEM_DCMSETFREEZEFRAMERECORDFILTER_APIID, DEM_E_PARAM_POINTER);
        Result = DEM_WRONG_FILTER;
    }
    else
    {
#if(DEM_NUM_OF_FFRECCLASS > 0)
        *NumberOfFilteredRecords = 0;
        Dem_NumFFRecOfDTC = 0;
        Dem_DcmFilterInfo.DTCFormat = DTCFormat;
        Dem_DcmFilterInfo.NumberOfFilteredDTC = 0;
        Dem_DcmFilterInfo.NextFilteredDTCIndex = 0;
        /*SWS_Dem_00210*/
        for(i = 0; i < DEM_NUM_OF_DTC; i++)
        {
            if((DEM_CFG_DTC_VALUE(i) != 0) && (DEM_DTC_DATAENTRYREF(i) != DEM_DATA_INVALID_U16) \
                && (DEM_CFG_DTC_FFRECNUMCLASSREF(i) != NULL_PTR))
            {
                Dem_DcmFilterInfo.FilteredDTCIndexTable[Dem_DcmFilterInfo.NumberOfFilteredDTC] = i;
                Dem_DcmFilterInfo.NumberOfFilteredDTC++;
                for(j = 0; j < DEM_CFG_DTC_NUM_OF_FFREC(i); j++)
                {
                    DTC = DEM_CFG_DTC_VALUE(i);
                    RecordNumber = DEM_CFG_DTC_FFRECNUM((DEM_CFG_DTC_FFREC_ARRAY(i)[j]));
                    (void)DemInternal_GetSizeOfFFData(DTC, DEM_DTC_ORIGIN_PRIMARY_MEMORY, \
                                                      RecordNumber, &SizeOfFreezeFrame, &FFDataOffset);
                    if(SizeOfFreezeFrame != 0)
                    {
                        (*NumberOfFilteredRecords)++;
                    }
                }
            }
        }
        Dem_DcmFilterInfo.FilteredValidFlag = TRUE;
#else
        Result = DEM_WRONG_FILTER;
#endif
    }
    return Result;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_DcmGetNextFilteredRecord
*
* Description: Gets the next freeze frame record number and its associated DTC stored in the event memory.
*
* Inputs: None
*
* Outputs: DTC: Receives the DTC value in respective format of the filter returned by this function.
*              RecordNumber: Freeze frame record number of the reported DTC(relative addressing).
*
* Return: Dem_ReturnGetNextFilteredElementType: Status of the operation to retrieve a DTC and
*                           its associated snapshot record number from the Dem.
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Dem_ReturnGetNextFilteredElementType, DEM_CODE) Dem_DcmGetNextFilteredRecord
(
    P2VAR(uint32, AUTOMATIC, DEM_APPL_DATA) DTC,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) RecordNumber
)
{
    /*SWS_Dem_00225*/
    Dem_ReturnGetNextFilteredElementType Result = DEM_FILTERED_OK;
#if(DEM_NUM_OF_FFRECCLASS > 0)
    uint16 DtcId;
    uint16 SizeOfFreezeFrame = 0;
    uint16 FFDataOffset = 0;
#endif
    if((DTC == NULL_PTR) || (RecordNumber == NULL_PTR))
    {
        DEM_DET_REPORT_ERROR(DEM_DCMGETNEXTFILTEREDRECORD_APIID, DEM_E_PARAM_POINTER);
        Result = DEM_FILTERED_NO_MATCHING_ELEMENT;
    }
    else if(Dem_DcmFilterInfo.FilteredValidFlag != TRUE)
    {
        Result = DEM_FILTERED_NO_MATCHING_ELEMENT;
    }
    else if(Dem_DcmFilterInfo.NextFilteredDTCIndex >= Dem_DcmFilterInfo.NumberOfFilteredDTC)
    {
        Dem_DcmFilterInfo.FilteredValidFlag = FALSE;
        Dem_DcmFilterInfo.NextFilteredDTCIndex = 0;
        Dem_DcmFilterInfo.NumberOfFilteredDTC = 0;

        Result = DEM_FILTERED_NO_MATCHING_ELEMENT;
    }
    else
    {
#if(DEM_NUM_OF_FFRECCLASS > 0)
        for(; (Dem_DcmFilterInfo.NextFilteredDTCIndex < Dem_DcmFilterInfo.NumberOfFilteredDTC);)
        {
            DtcId = Dem_DcmFilterInfo.FilteredDTCIndexTable[Dem_DcmFilterInfo.NextFilteredDTCIndex];
            if(Dem_NumFFRecOfDTC >= DEM_CFG_DTC_NUM_OF_FFREC(DtcId))
            {
                Dem_DcmFilterInfo.NextFilteredDTCIndex++;
                Dem_NumFFRecOfDTC = 0;
            }

            if(Dem_DcmFilterInfo.NextFilteredDTCIndex < Dem_DcmFilterInfo.NumberOfFilteredDTC)
            {
                DtcId = Dem_DcmFilterInfo.FilteredDTCIndexTable[Dem_DcmFilterInfo.NextFilteredDTCIndex];
                *DTC = DEM_CFG_DTC_VALUE(DtcId);

#if((DEM_CFG_OBD_SUPPORT == DEM_OBD_MASTER_ECU)||(DEM_CFG_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU))
                if((Dem_DcmFilterInfo.DTCFormat == DEM_DTC_FORMAT_OBD) \
                    && (DEM_CFG_DTC_OBDDTCREF(DtcId) != NULL_PTR))
                {
                    *DTC = DEM_CFG_DTC_OBD_VALUE(DtcId);
                }
#endif
#if(DEM_J1939_SUPPORT == STD_ON)
                if((Dem_DcmFilterInfo.DTCFormat == DEM_DTC_FORMAT_J1939) \
                    && (DEM_CFG_DTC_OBDDTCREF(DtcId) != NULL_PTR))
                {
                    *DTC = DEM_CFG_DTC_J1939_VALUE(DtcId);
                }
#endif
                *RecordNumber = DEM_CFG_DTC_FFRECNUM(DEM_CFG_DTC_FFREC_ARRAY(DtcId)[Dem_NumFFRecOfDTC]);
                (void)DemInternal_GetSizeOfFFData(*DTC, DEM_DTC_ORIGIN_PRIMARY_MEMORY, \
                                                  *RecordNumber, &SizeOfFreezeFrame, &FFDataOffset);
                Dem_NumFFRecOfDTC++;

                if(SizeOfFreezeFrame != 0)
                {
                    break;
                }
            }
            else
            {
                Dem_DcmFilterInfo.FilteredValidFlag = FALSE;
                Dem_DcmFilterInfo.NextFilteredDTCIndex = 0;
                Dem_DcmFilterInfo.NumberOfFilteredDTC = 0;

                Result = DEM_FILTERED_NO_MATCHING_ELEMENT;
            }
        }
#else
        Result = DEM_FILTERED_NO_MATCHING_ELEMENT;
#endif
    }
    return Result;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_DcmGetDTCByOccurrenceTime
*
* Description: Gets the DTC by occurrence time. There is no explicit parameter for the DTC-origin
*                  as the origin always is DEM_DTC_ORIGIN_PRIMARY_MEMORY.
*
* Inputs: DTCRequest: This parameter defines the request type of the DTC.
*
* Outputs: DTC: Receives the DTC value in respective format of the filter returned by this function.
*
* Return: Dem_ReturnGetDTCByOccurrenceTimeType: Status of the operation.
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Dem_ReturnGetDTCByOccurrenceTimeType, DEM_CODE) Dem_DcmGetDTCByOccurrenceTime
(
    Dem_DTCRequestType DTCRequest,
    P2VAR(uint32, AUTOMATIC, DEM_APPL_DATA) DTC
)
{
    Dem_ReturnGetDTCByOccurrenceTimeType Result = DEM_OCCURR_OK;
    uint16 EventId = DEM_DATA_INVALID_U16;

    if(Dem_State != DEM_NORMAL)
    {
        /*SWS_Dem_01112*//*SWS_Dem_00124*/
        DEM_DET_REPORT_ERROR(DEM_DCMGETDTCBYOCCURRENCETIME_APIID, DEM_E_UNINIT);
        Result = DEM_OCCURR_NOT_AVAILABLE;
    }
    else if(DTC == NULL_PTR)
    {
        DEM_DET_REPORT_ERROR(DEM_DCMGETDTCBYOCCURRENCETIME_APIID, DEM_E_PARAM_POINTER);
        Result = DEM_OCCURR_NOT_AVAILABLE;
    }
    else
    {
        /*SWS_Dem_00219*/
        switch(DTCRequest)
        {
            case DEM_FIRST_FAILED_DTC:
                EventId = DEM_EVENT_FIRST_FAILED;
                break;

            case DEM_MOST_RECENT_FAILED_DTC:
                EventId = DEM_EVENT_RECENT_FAILED;
                break;

            case DEM_FIRST_DET_CONFIRMED_DTC:
                EventId = DEM_EVENT_FIRST_CONFIRMED;
                break;

            case DEM_MOST_REC_DET_CONFIRMED_DTC:
                EventId = DEM_EVENT_RECENT_CONFIRMED;
                break;

            default:
                break;
        }

        if(EventId < DEM_NUM_OF_EVENT)
        {
            *DTC = DEM_CFG_DTC_VALUE(DEM_CFG_EVENT_DTCREF(EventId));
        }
        else
        {
            /*SWS_Dem_00221*/
            Result = DEM_OCCURR_NOT_AVAILABLE;
        }
    }
    return Result;
}

#if(DEM_CFG_TRIGGER_DCM_REPORTS == STD_OFF)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_DcmControlDTCStatusChangedNotification
*
* Description: Controls the triggering of Dcm_DemTriggerOnDTCStatus.
*
* Inputs: TriggerNotification: This parameter specifies whether the triggering of the notification
*                                       shall be enabled (TRUE) or disabled (FALSE).
*
* Outputs: None
*
* Return: None
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, DEM_CODE) Dem_DcmControlDTCStatusChangedNotification
(
    boolean TriggerNotification
)
{
    /*SWS_Dem_00827*/

}
#endif

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_DcmDisableDTCRecordUpdate
*
* Description: Disables the event memory update of a specific DTC (only one at one time).
*
* Inputs: DTC: Selects the DTC in UDS format, for which DTC record update shall be disabled.
*            DTCOrigin: If the Dem supports more than one event memory, this parameter is used
*                           to select the source memory for which DTC record update shall be disabled.
*
* Outputs: None
*
* Return: Dem_ReturnDisableDTCRecordUpdateType: Status of the operation to disable the
*                            event memory update of a specific DTC.
*
* Limitations: Synchronous
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Dem_ReturnDisableDTCRecordUpdateType, DEM_CODE) Dem_DcmDisableDTCRecordUpdate
(
    uint32 DTC,
    Dem_DTCOriginType DTCOrigin
)
{
    Dem_ReturnDisableDTCRecordUpdateType Result = DEM_DISABLE_DTCRECUP_OK;
    uint16 DtcId;

    if(Dem_State != DEM_NORMAL)
    {
        /*SWS_Dem_01112*//*SWS_Dem_00124*/
        DEM_DET_REPORT_ERROR(DEM_DCMDISABLEDTCRECORDUPDATE_APIID, DEM_E_UNINIT);
    }
    else if(DEM_DTC_ORIGIN_PRIMARY_MEMORY != DTCOrigin)
    {
        /*SWS_Dem_00171*/
        Result = DEM_DISABLE_DTCRECUP_WRONG_DTCORIGIN;
    }
    else if(E_OK != DemInternal_CheckDtcValid(DTC, &DtcId))
    {
        /*SWS_Dem_00172*/
        Result = DEM_DISABLE_DTCRECUP_WRONG_DTC;
    }
    else
    {
        SchM_Enter_Dem_DEM_EXCLUSIVE_AREA_0();
        /*SWS_Dem_00270*/
        Dem_DtcUpDateState[DtcId] = FALSE;
        SchM_Exit_Dem_DEM_EXCLUSIVE_AREA_0();
    }
    return Result;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_DcmEnableDTCRecordUpdate
*
* Description: Enables the event memory update of the DTC disabled by
*                  Dem_DcmDisableDTCRecordUpdate() before.
*
* Inputs: None
*
* Outputs: None
*
* Return: Std_ReturnType: Always E_OK is returned.
*
* Limitations: Synchronous
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, DEM_CODE) Dem_DcmEnableDTCRecordUpdate
(
    void
)
{
    uint16 i;
    if(Dem_State != DEM_NORMAL)
    {
        /*SWS_Dem_01112*//*SWS_Dem_00124*/
        DEM_DET_REPORT_ERROR(DEM_DCMENABLEDTCRECORDUPDATE_APIID, DEM_E_UNINIT);
    }
    else
    {
        SchM_Enter_Dem_DEM_EXCLUSIVE_AREA_0();

        for(i = 0; i < DEM_NUM_OF_DTC; i++)
        {
            /*SWS_Dem_00271*/
            Dem_DtcUpDateState[i] = TRUE;
        }

        SchM_Exit_Dem_DEM_EXCLUSIVE_AREA_0();
    }

    return E_OK;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_DcmGetFreezeFrameDataByDTC
*
* Description: Gets freeze frame data by DTC. The function stores the data in the provided DestBuffer.
*
* Inputs: DTC: Diagnostic Trouble Code in UDS format.
*            DTCOrigin: If the Dem supports more than one event memory,this parameter is used
*                           to select the source memory the DTCs shall be read from.
*            RecordNumber: This parameter is a unique identifier for a freeze frame record as defined
*                                 in ISO 15031-5 and ISO 14229-1. This record number is unique per DTC
*                                 (relative addressing). The value 0xFF is not allowed. The value 0x00 indicates
*                                 the DTC-specific OBD freeze frame.
*            BufSize: When the function is called this parameter contains the maximum number of
*                        data bytes that can be written to the buffer.
*
* Outputs: BufSize: The function returns the actual number of written data bytes in this parameter.
*              DestBuffer: This parameter contains a byte pointer that points to the buffer, to which
*                              the freeze frame data record shall be written to. The format is: {RecordNumber,
*                              NumOfDIDs, DID[1], data[1], ..., DID[N], data[N]}
*
* Return: Dem_ReturnGetFreezeFrameDataByDTCType:Status of the operation to retrieve
*                                                                          freeze frame data by DTC.
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Dem_ReturnGetFreezeFrameDataByDTCType, DEM_CODE) Dem_DcmGetFreezeFrameDataByDTC
(
    uint32 DTC,
    Dem_DTCOriginType DTCOrigin,
    uint8 RecordNumber,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DestBuffer,
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) BufSize
)
{
    Dem_ReturnGetFreezeFrameDataByDTCType Result = DEM_GET_FFDATABYDTC_OK;
    Dem_ReturnGetSizeOfDataByDTCType ret = DEM_GETSIZEBYDTC_OK;
    uint16 FFDataOffset;
    uint16 DtcId;
    uint32 Size;
#if(DEM_MAX_FFSIZE_OF_DTC > 0U)
    uint8 *DestBufferPtr;
#endif
    if(DestBuffer == NULL_PTR)
    {
        Result = DEM_GET_FFDATABYDTC_WRONG_BUFFERSIZE;
    }
    else if(E_OK != DemInternal_CheckDtcValid(DTC, &DtcId))
    {
        /*SWS_Dem_00172*/
        Result = DEM_GET_FFDATABYDTC_WRONG_DTC;
    }
    else
    {
        Size = (uint32)(*BufSize);
        ret = DemInternal_GetSizeOfFFData(DTC, DTCOrigin, RecordNumber, BufSize, &FFDataOffset);
        if(ret == DEM_GETSIZEBYDTC_WRONG_DTC)
        {
            /*SWS_Dem_00172*/
            Result = DEM_GET_FFDATABYDTC_WRONG_DTC;
        }
        else if(ret == DEM_GETSIZEBYDTC_WRONG_DTCORIGIN)
        {
            /*SWS_Dem_00171*/
            Result = DEM_GET_FFDATABYDTC_WRONG_DTCORIGIN;
        }
        else if(ret == DEM_GETSIZEBYDTC_WRONG_RECNUM)
        {
            Result = DEM_GET_FFDATABYDTC_WRONG_RECORDNUMBER;
        }
        else if(ret == DEM_GETSIZEBYDTC_PENDING)
        {
            Result = DEM_GET_FFDATABYDTC_PENDING;
        }
        else/*(ret == DEM_GETSIZEBYDTC_OK)*/
        {
            /*Result = DEM_GET_FFDATABYDTC_OK;*/
        }
    }

    if(Result == DEM_GET_FFDATABYDTC_OK)
    {
        if(Size >= (uint32)(*BufSize))
        {
            Size = (uint32)(*BufSize);
#if(DEM_MAX_FFSIZE_OF_DTC > 0U)
            /*SWS_Dem_00071*/
            if(RecordNumber == 0xFFU)
            {
                DestBufferPtr = DestBuffer;
                DemInternal_GetAllFFData(DtcId, DestBufferPtr);
            }
            else
            {
                Bsw_MemCpy(DestBuffer, (DEM_PRIMARY_FFDATA_PTR((DEM_DTC_DATAENTRYREF(DtcId))) + FFDataOffset), Size);
            }
#endif
        }
        else
        {
            Result = DEM_GET_FFDATABYDTC_WRONG_BUFFERSIZE;
        }
    }
    else
    {
        /*Result != DEM_RECORD_OK*/
    }
    return Result;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_DcmGetSizeOfFreezeFrameByDTC
*
* Description: Gets the size of freeze frame data by DTC.
*
* Inputs: DTC: Diagnostic Trouble Code in UDS format.
*            DTCOrigin: If the Dem supports more than one event memory,this parameter is used
*                           to select the source memory the DTCs shall be read from.
*            RecordNumber: This parameter is a unique identifier for a freeze frame record as defined
*                                 in ISO 15031-5 and ISO 14229-1. This record number is unique per DTC
*                                 (relative addressing). The value 0xFF is explicitly allowed to request the
*                                 overall size.
*
* Outputs: SizeOfFreezeFrame: Number of bytes in the requested freeze frame record.
*
* Return: Dem_ReturnGetSizeOfDataByDTCType:Status of the operation to retrieve the size of
*                                                                 freeze frame data.
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Dem_ReturnGetSizeOfDataByDTCType, DEM_CODE) Dem_DcmGetSizeOfFreezeFrameByDTC
(
    uint32 DTC,
    Dem_DTCOriginType DTCOrigin,
    uint8 RecordNumber,
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) SizeOfFreezeFrame
)
{
    Dem_ReturnGetSizeOfDataByDTCType Result = DEM_GETSIZEBYDTC_OK;
    uint16 FFDataOffset;
    /*SWS_Dem_00074*/
    Result = DemInternal_GetSizeOfFFData(DTC, DTCOrigin, RecordNumber, SizeOfFreezeFrame, &FFDataOffset);

    return Result;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_DcmGetExtendedDataRecordByDTC
*
* Description: Gets extended data by DTC. The function stores the data in the
*              provided DestBuffer.
*
* Inputs: DTC: Diagnostic Trouble Code in UDS format.
*         DTCOrigin: If the Dem supports more than one event memory,this parameter is used
*                    to select the source memory the DTCs shall be read from.
*         ExtendedDataNumber: Identification/Number of requested extended data record.
*                             The values 0xFE and 0xFF are not allowed.
*         BufSize: When the function is called this parameter contains the maximum number of
*                  data bytes that can be written to the buffer.
*
* Outputs: BufSize: The function returns the actual number of written data bytes in this parameter.
*          DestBuffer: This parameter contains a byte pointer that points to the buffer, to which
*                      the extended data record shall be written to. The format is raw
*                      hexadecimal values and contains no header-information.
*
* Return: Dem_ReturnGetExtendedDataRecordByDTCType:Status of the operation to retrieve
*         extended data by DTC.
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Dem_ReturnGetExtendedDataRecordByDTCType, DEM_CODE) Dem_DcmGetExtendedDataRecordByDTC
(
    uint32 DTC,
    Dem_DTCOriginType DTCOrigin,
    uint8 ExtendedDataNumber,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DestBuffer,
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) BufSize
)
{
    Dem_ReturnGetExtendedDataRecordByDTCType Result = DEM_RECORD_OK;
    Dem_ReturnGetSizeOfDataByDTCType ret = DEM_GETSIZEBYDTC_OK;
    uint16 ExtDataOffset;
    uint16 DtcId;
    uint32 Size;
#if(DEM_MAX_EXTSIZE_OF_DTC > 0U)
    uint8 *DestBufferPtr;
#endif
    if(DestBuffer == NULL_PTR)
    {
        Result = DEM_RECORD_WRONG_BUFFERSIZE;
    }
    else if(E_OK != DemInternal_CheckDtcValid(DTC, &DtcId))
    {
        /*SWS_Dem_00172*/
        Result = DEM_RECORD_WRONG_DTC;
    }
    else
    {
        Size = (uint32)(*BufSize);

        ret = DemInternal_GetSizeOfExtendedData(DTC, DTCOrigin, ExtendedDataNumber, BufSize, &ExtDataOffset);
        if(ret == DEM_GETSIZEBYDTC_WRONG_DTC)
        {
            /*SWS_Dem_00172*/
            Result = DEM_RECORD_WRONG_DTC;
        }
        else if(ret == DEM_GETSIZEBYDTC_WRONG_DTCORIGIN)
        {
            /*SWS_Dem_00171*/
            Result = DEM_RECORD_WRONG_DTCORIGIN;
        }
        else if(ret == DEM_GETSIZEBYDTC_WRONG_RECNUM)
        {
            Result = DEM_RECORD_WRONG_NUMBER;
        }
        else if(ret == DEM_GETSIZEBYDTC_PENDING)
        {
            Result = DEM_RECORD_PENDING;
        }
        else/*(ret == DEM_GETSIZEBYDTC_OK)*/
        {
            /*Result = DEM_RECORD_OK;*/
        }
    }

    if(Result == DEM_RECORD_OK)
    {
        if(Size >= (uint32)(*BufSize))
        {
            Size = (uint32)(*BufSize);
#if(DEM_MAX_EXTSIZE_OF_DTC > 0U)
            /*SWS_Dem_00075*/
            if(ExtendedDataNumber == 0xFFU)
            {
                DestBufferPtr = DestBuffer;
                DemInternal_GetAllExtendedData(DtcId, DestBufferPtr);
            }
            else
            {
                Bsw_MemCpy(DestBuffer, (DEM_PRIMARY_EXTDATA_PTR(DEM_DTC_DATAENTRYREF(DtcId)) + ExtDataOffset), Size);
            }
#endif
        }
        else
        {
            Result = DEM_RECORD_WRONG_BUFFERSIZE;
        }
    }
    else
    {
        /*Result != DEM_RECORD_OK*/
    }
    return Result;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_DcmGetSizeOfExtendedDataRecordByDTC
*
* Description: Gets the size of extended data by DTC.
*
* Inputs: DTC: Diagnostic Trouble Code in UDS format.
*         DTCOrigin: If the Dem supports more than one event memory,this parameter
*                    is used to select the source memory the DTCs shall be read from.
*         ExtendedDataNumber: Identification/Number of requested extended data record.
*                             Additionally the values 0xFE and 0xFF are explicitly
*                             allowed to request the overall size of all OBD records
*                             / all records.
*
* Outputs: SizeOfExtendedDataRecord: Size of the requested extended data record(s)
*                                    including record number size
*
* Return: Dem_ReturnGetSizeOfDataByDTCType: Status of the operation to retrieve
*                                           the size of extended data.
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Dem_ReturnGetSizeOfDataByDTCType, DEM_CODE) Dem_DcmGetSizeOfExtendedDataRecordByDTC
(
    uint32 DTC,
    Dem_DTCOriginType DTCOrigin,
    uint8 ExtendedDataNumber,
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) SizeOfExtendedDataRecord
)
{
    Dem_ReturnGetSizeOfDataByDTCType Result = DEM_GETSIZEBYDTC_OK;
    uint16 ExtDataOffset;
    /*SWS_Dem_00076*/
    Result = DemInternal_GetSizeOfExtendedData(DTC, DTCOrigin, ExtendedDataNumber, \
                                               SizeOfExtendedDataRecord, &ExtDataOffset);

    return Result;
}


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_DcmCheckClearParameter
*
* Description: Performs a parameter check and gives the result which would also
*              be returned by calling clear with same parameters.
*
* Inputs: DTC: Defines the DTC in respective format, that shall be cleared from
*              the event memory. Either a single DTC or a DTC group may be passed.
*         DTCFormat: Defines the input-format of the provided DTC value.
*         DTCOrigin: This parameter is used to select the source memory the DTCs
*                    shall be cleared from.
*
* Outputs: None
*
* Return: Dem_ReturnClearDTCType
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Dem_ReturnClearDTCType, DEM_CODE) Dem_DcmCheckClearParameter
(
    uint32 DTC,
    Dem_DTCFormatType DTCFormat,
    Dem_DTCOriginType DTCOrigin
)
{
    Dem_ReturnClearDTCType Result = DEM_CLEAR_OK;
    uint16 DtcIndex;

    if((DTC == (uint32)0) || (DTC > DEM_DTC_GROUP_ALL))
    {
        Result = DEM_CLEAR_WRONG_DTC;
    }
    else if((DTCFormat != DEM_DTC_FORMAT_OBD) \
        && (DTCFormat != DEM_DTC_FORMAT_UDS) \
        && (DTCFormat != DEM_DTC_FORMAT_J1939))
    {
        Result = DEM_CLEAR_FAILED;
    }
    else if(DTCOrigin != DEM_DTC_ORIGIN_PRIMARY_MEMORY)
    {
        Result = DEM_CLEAR_WRONG_DTCORIGIN;
    }
#if(DEM_CFG_CLEARDTCLIMITATION == DEM_ONLY_CLEAR_ALL_DTCS)
    else if(DTC != DEM_DTC_GROUP_ALL)
    {
        Result = DEM_CLEAR_WRONG_DTC;
    }
#endif
    else
    {
        Result = DEM_CLEAR_WRONG_DTC;

        for(DtcIndex = 0; DtcIndex < DEM_NUM_OF_DTC; DtcIndex++)
        {
            if(((DTCFormat == DEM_DTC_FORMAT_UDS) && (DTC == DEM_CFG_DTC_VALUE(DtcIndex)))
#if((DEM_CFG_OBD_SUPPORT == DEM_OBD_MASTER_ECU)||(DEM_CFG_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU))
                || ((DTCFormat == DEM_DTC_FORMAT_OBD) && (DEM_CFG_DTC_OBDDTCREF(DtcIndex) != NULL_PTR) \
                    && (DTC == DEM_CFG_DTC_OBD_VALUE(DtcIndex)))
#endif
#if(DEM_J1939_SUPPORT == STD_ON)
                || ((DTCFormat == DEM_DTC_FORMAT_J1939) && (DEM_CFG_DTC_OBDDTCREF(DtcIndex) != NULL_PTR) \
                    && (DTC == DEM_CFG_DTC_J1939_VALUE(DtcIndex)))
#endif
					)
            {
                Result = DEM_CLEAR_OK;
                break;
            }
        }
#if(DEM_NUM_OF_DTCGROUP > 0)
        for(DtcIndex = 0; DtcIndex < DEM_NUM_OF_DTCGROUP; DtcIndex++)
        {
            if(DTC == DEM_CFG_DTC_GROUPVALUE(DtcIndex))
            {
                Result = DEM_CLEAR_OK;
                break;
            }
        }
#endif
    }
    return Result;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_DcmClearDTC
*
* Description: Clears single DTCs, as well as groups of DTCs. This API is intended for the Dcm.
*                  It can only be used through the RTE (due to work-around described below
*                  SWS_Dem_00009), and therefore no declaration is exported via Dem_Dcm.h.
*
* Inputs: DTC: Defines the DTC in respective format, that shall be cleared from the event memory.
*                   If the DTC fits to a DTC group number, all DTCs of the group shall be cleared.
*            DTCFormat: Defines the input-format of the provided DTC value.
*            DTCOrigin: If the Dem supports more than one event memory this parameter is used to
*                            select the source memory the DTCs shall be read from.
*
* Outputs: None
*
* Return: Dem_ReturnClearDTCType
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Dem_ReturnClearDTCType, DEM_CODE) Dem_DcmClearDTC
(
    uint32 DTC,
    Dem_DTCFormatType DTCFormat,
    Dem_DTCOriginType DTCOrigin
)
{
    /*SWS_Dem_00009*/
    Dem_ReturnClearDTCType Result = DEM_CLEAR_OK;
    /*SWS_Dem_00077*/
    Result = Dem_ClearDTC(DTC, DTCFormat, DTCOrigin);

    return Result;
}



/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_DcmDisableDTCSetting
*
* Description: Disables the DTC setting for a DTC group.
*
* Inputs: DTCGroup: Defines the group of DTC that shall be disabled to store in event memory.
*            DTCKind: This parameter defines the requested DTC kind, either only OBD-relevant
*                          DTCs or all DTCs
*
* Outputs: None
*
* Return: Dem_ReturnControlDTCSettingType
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Dem_ReturnControlDTCSettingType, DEM_CODE) Dem_DcmDisableDTCSetting
(
    uint32 DTCGroup,
    Dem_DTCKindType DTCKind
)
{
    /*SWS_Dem_00035*/
    Dem_ReturnControlDTCSettingType Result = DEM_CONTROL_DTC_SETTING_OK;
    uint16 i;

    if((DTCGroup == DEM_DTC_GROUP_ALL) && (DTCKind == DEM_DTC_KIND_ALL_DTCS))
    {
        for(i = 0; i < DEM_NUM_OF_DTC; i++)
        {
            /*SWS_Dem_00079*/
            Dem_EnableDtcSetting[i] = FALSE;
#if(DEM_CFG_DEBOUNCECOUNTERBASEDSUPPORT == STD_ON)
            if((DEM_CFG_EVENT_DBC(i) != NULL_PTR) \
                    && (DEM_CFG_EVENT_DBC_BEHAVIOR(i) == DEM_DEBOUNCE_RESET))
            {
                /*SWS_Dem_00677*/
                DEM_EVENT_DBC(i) = 0;
            }
            else
#endif
#if(DEM_CFG_DEBOUNCETIMEBASEDSUPPORT == STD_ON)
                if((DEM_CFG_EVENT_DBT(i) != NULL_PTR) \
                        && (DEM_CFG_EVENT_DBT_BAHAVIOR(i) == DEM_DEBOUNCE_RESET))
                {
                    /*SWS_Dem_00677*/
                    DEM_EVENT_DBT(i) = 0;
                    DEM_EVENT_TIMERDIRECTION(i) = DEM_DATA_INVALID_U8;
                }
                else
#endif
                {
                    /*do nothing*/
                }
        }
    }
    else
    {
        Result = DEM_CONTROL_DTC_WRONG_DTCGROUP;

        for(i = 0; i < DEM_NUM_OF_DTC; i++)
        {
            if(DEM_CFG_DTC_VALUE(i) == DTCGroup)
            {
                /*SWS_Dem_00079*/
                Dem_EnableDtcSetting[i] = FALSE;
#if(DEM_CFG_DEBOUNCECOUNTERBASEDSUPPORT == STD_ON)
                if((DEM_CFG_EVENT_DBC(i) != NULL_PTR) \
                        && (DEM_CFG_EVENT_DBC_BEHAVIOR(i) == DEM_DEBOUNCE_RESET))
                {
                    /*SWS_Dem_00677*/
                    DEM_EVENT_DBC(i) = 0;
                }
                else
#endif
#if(DEM_CFG_DEBOUNCETIMEBASEDSUPPORT == STD_ON)
                    if((DEM_CFG_EVENT_DBT(i) != NULL_PTR) \
                            && (DEM_CFG_EVENT_DBT_BAHAVIOR(i) == DEM_DEBOUNCE_RESET))
                    {
                        /*SWS_Dem_00677*/
                        DEM_EVENT_DBT(i) = 0;
                        DEM_EVENT_TIMERDIRECTION(i) = DEM_DATA_INVALID_U8;
                    }
                    else
#endif
                    {
                        /*do nothing*/
                    }
                Result = DEM_CONTROL_DTC_SETTING_OK;
                break;
            }
        }
    }
    return Result;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_DcmEnableDTCSetting
*
* Description: Enables the DTC setting for a DTC group.This API is intended for
*              the Dcm. It can only be used through the RTE(due to work-around
*              described below SWS_Dem_00035), and therefore no declaration is
*              exported via Dem_Dcm.h.
*
* Inputs: DTCGroup: Defines the group of DTC that shall be enabled to store in
*                   event memory.
*         DTCKind: This parameter defines the requested DTC kind, either only
*                  OBD-relevant DTCs or all DTCs
*
* Outputs: None
*
* Return: Dem_ReturnControlDTCSettingType
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Dem_ReturnControlDTCSettingType, DEM_CODE) Dem_DcmEnableDTCSetting
(
    uint32 DTCGroup,
    Dem_DTCKindType DTCKind
)
{
    /*SWS_Dem_00035*/
    Dem_ReturnControlDTCSettingType Result = DEM_CONTROL_DTC_SETTING_OK;
    uint16 i;

    if((DTCGroup == DEM_DTC_GROUP_ALL) && (DTCKind == DEM_DTC_KIND_ALL_DTCS))
    {
        for(i = 0; i < DEM_NUM_OF_DTC; i++)
        {
            /*SWS_Dem_00080*/
            Dem_EnableDtcSetting[i] = TRUE;
        }
    }
    else
    {
        Result = DEM_CONTROL_DTC_WRONG_DTCGROUP;
    }
    return Result;
}


#if((DEM_CFG_OBD_SUPPORT == DEM_OBD_MASTER_ECU)||(DEM_CFG_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU))
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_DcmGetInfoTypeValue08
*
* Description: Service is used for requesting IUMPR data according to Info-Type $08.
*
* Inputs: OpStatus: Only DCM_INITIAL will appear, because this API behaves synchronous.
*         Iumprdata08BufferSize: The maximum number of data bytes that can be
*                                written to the Iumprdata08 Buffer.
*
* Outputs: Iumprdata08BufferSize
*          Iumprdata08: Buffer containing the number of data elements (as defined
*                       in ISO-15031-5) and contents of InfoType $08. The buffer
*                       is provided by the Dcm.
*
* Return: Always E_OK is returned.
*
* Limitations: This API will be available only if ({ecuc(Dem/DemGeneral.DemOBD-
*              Support)} != DEM_OBD_NO_OBD_SUPPORT)
********************************************************************************
END_FUNCTION_HDR*/
/*SWS_Dem_00316*//*SWS_Dem_00298*/
FUNC(Std_ReturnType, DEM_CODE) Dem_DcmGetInfoTypeValue08
(
    Dcm_OpStatusType OpStatus,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) Iumprdata08,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) Iumprdata08BufferSize
)
{
    Std_ReturnType Result = E_NOT_OK;
#if(DEM_CFG_OBD_ENGINE_TYPE == DEM_IGNITION_SPARK)
    Dem_RatioIdType RatioID;
    uint8 i;
    uint16 TempBuff[DEM_OBD_INFO08_DATA_LENGTH/2];
    uint32 CurrentRatio;
    uint32 ExistRatio;
#endif

    if(Dem_State != DEM_NORMAL)
    {
        /*SWS_Dem_01112*//*SWS_Dem_00124*/
        DEM_DET_REPORT_ERROR(DEM_DCMGETINFOTYPEVALUE08_APIID, DEM_E_UNINIT);
    }
    else if((Iumprdata08 == NULL_PTR) || (Iumprdata08BufferSize == NULL_PTR))
    {
        DEM_DET_REPORT_ERROR(DEM_DCMGETINFOTYPEVALUE08_APIID, DEM_E_PARAM_POINTER);
    }
    else if(*Iumprdata08BufferSize < DEM_OBD_INFO08_DATA_LENGTH)
    {
        DEM_DET_REPORT_ERROR(DEM_DCMGETINFOTYPEVALUE08_APIID, DEM_E_PARAM_LENGTH);
    }
    else
    {
        /*SWS_Dem_00357*/
#if(DEM_NUM_OF_RATIO > 0)
#if(DEM_CFG_OBD_ENGINE_TYPE == DEM_IGNITION_SPARK)
        for(i = 0; i < (DEM_OBD_INFO08_DATA_LENGTH/2); i++)
        {
            TempBuff[i] = DEM_DATA_INVALID_U16;
        }
        /*Numerator:OBD Monitoring Conditions Encountered Counts*/
        TempBuff[0] = DEM_OBD_RATIO_GENDEN_CNT;
        /*Denominator:Ignition Cycle Counter*/
        TempBuff[1] = DEM_OBD_RATIO_IGN_CNT;

        for(RatioID = 0; RatioID < DEM_NUM_OF_RATIO; RatioID++)
        {
            i = DEM_CFG_RATIO_IUMPR(RatioID);

            if(TempBuff[i*2] == DEM_DATA_INVALID_U16)
            {
                /*Numerator*/
                TempBuff[i*2] = DEM_OBD_RATIO_NUMERATOR(RatioID);
                /*Denominator*/
                TempBuff[i*2 + 1] = DEM_OBD_RATIO_DENOMINATOR(RatioID);
            }
            else
            {
                /*If one IUMPR group has been referenced by several Ratios,
                the IUMPR group value should same to the minimum value of the Ratios.*/
                CurrentRatio = (DEM_OBD_RATIO_NUMERATOR(RatioID)*(TempBuff[i*2 + 1]));
                ExistRatio = ((TempBuff[i*2])*DEM_OBD_RATIO_DENOMINATOR(RatioID));

                if((CurrentRatio < ExistRatio) \
                    || ((CurrentRatio == ExistRatio) \
                    && (DEM_OBD_RATIO_DENOMINATOR(RatioID) > (TempBuff[i*2 + 1]))))
                {
                    /*Numerator*/
                    TempBuff[i*2] = DEM_OBD_RATIO_NUMERATOR(RatioID);
                    /*Denominator*/
                    TempBuff[i*2 + 1] = DEM_OBD_RATIO_DENOMINATOR(RatioID);
                }
            }
        }

        for(i = 0; i < (DEM_OBD_INFO08_DATA_LENGTH/2); i++)
        {
            Iumprdata08[i*2] = (uint8)(TempBuff[i] >> 8);
            Iumprdata08[i*2 + 1] = (uint8)(TempBuff[i]);
        }
        *Iumprdata08BufferSize = DEM_OBD_INFO08_DATA_LENGTH;

        Result = E_OK;
#endif/*#if(DEM_CFG_OBD_ENGINE_TYPE == DEM_IGNITION_SPARK)*/
#endif/*#if(DEM_NUM_OF_RATIO > 0)*/
    }
    return Result;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_DcmGetInfoTypeValue0B
*
* Description: Service is used for requesting IUMPR data according to Info-Type $0B.
*
* Inputs: OpStatus: Only DCM_INITIAL will appear, because this API behaves synchronous.
*         Iumprdata0BBufferSize: The maximum number of data bytes that can be
*                                written to the Iumprdata0B Buffer.
*
* Outputs: Iumprdata0BBufferSize
*          Iumprdata0B: Buffer containing the number of data elements (as defined
*                       in ISO-15031-5) and contents of InfoType $0B. The buffer
*                       is provided by the Dcm.
*
* Return: Always E_OK is returned.
*
* Limitations: This API will be available only if ({ecuc(Dem/DemGeneral.DemOBD-
*              Support)} != DEM_OBD_NO_OBD_SUPPORT)
********************************************************************************
END_FUNCTION_HDR*/
/*SWS_Dem_00317*//*SWS_Dem_00298*/
FUNC(Std_ReturnType, DEM_CODE) Dem_DcmGetInfoTypeValue0B
(
    Dcm_OpStatusType OpStatus,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) Iumprdata0B,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) Iumprdata0BBufferSize
)
{
    Std_ReturnType Result = E_NOT_OK;
#if(DEM_CFG_OBD_ENGINE_TYPE == DEM_IGNITION_COMPRESSION)
    Dem_RatioIdType RatioID;
    uint8 i;
    uint16 TempBuff[DEM_OBD_INFO0B_DATA_LENGTH/2];
    uint32 CurrentRatio;
    uint32 ExistRatio;
#endif

    if(Dem_State != DEM_NORMAL)
    {
        /*SWS_Dem_01112*//*SWS_Dem_00124*/
        DEM_DET_REPORT_ERROR(DEM_DCMGETINFOTYPEVALUE0B_APIID, DEM_E_UNINIT);
    }
    else if((Iumprdata0B == NULL_PTR) || (Iumprdata0BBufferSize == NULL_PTR))
    {
        DEM_DET_REPORT_ERROR(DEM_DCMGETINFOTYPEVALUE0B_APIID, DEM_E_PARAM_POINTER);
    }
    else if(*Iumprdata0BBufferSize < DEM_OBD_INFO0B_DATA_LENGTH)
    {
        DEM_DET_REPORT_ERROR(DEM_DCMGETINFOTYPEVALUE0B_APIID, DEM_E_PARAM_LENGTH);
    }
    else
    {
        /*SWS_Dem_00358*/
#if(DEM_NUM_OF_RATIO > 0)
#if(DEM_CFG_OBD_ENGINE_TYPE == DEM_IGNITION_COMPRESSION)
        for(i = 0; i < (DEM_OBD_INFO0B_DATA_LENGTH/2); i++)
        {
            TempBuff[i] = DEM_DATA_INVALID_U16;
        }
        /*Numerator:OBD Monitoring Conditions Encountered Counts*/
        TempBuff[0] = DEM_OBD_RATIO_GENDEN_CNT;
        /*Denominator:Ignition Cycle Counter*/
        TempBuff[1] = DEM_OBD_RATIO_IGN_CNT;

        for(RatioID = 0; RatioID < DEM_NUM_OF_RATIO; RatioID++)
        {
            i = DEM_CFG_RATIO_IUMPR(RatioID);

            if(TempBuff[i*2] == DEM_DATA_INVALID_U16)
            {
                /*Numerator*/
                TempBuff[i*2] = DEM_OBD_RATIO_NUMERATOR(RatioID);
                /*Denominator*/
                TempBuff[i*2 + 1] = DEM_OBD_RATIO_DENOMINATOR(RatioID);
            }
            else
            {
                /*If one IUMPR group has been referenced by several Ratios,
                the IUMPR group value should same to the minimum value of the Ratios.*/
                CurrentRatio = (DEM_OBD_RATIO_NUMERATOR(RatioID)*(TempBuff[i*2 + 1]));
                ExistRatio = ((TempBuff[i*2])*DEM_OBD_RATIO_DENOMINATOR(RatioID));

                if((CurrentRatio < ExistRatio) \
                    || ((CurrentRatio == ExistRatio) \
                    && (DEM_OBD_RATIO_DENOMINATOR(RatioID) > (TempBuff[i*2 + 1]))))
                {
                    /*Numerator*/
                    TempBuff[i*2] = DEM_OBD_RATIO_NUMERATOR(RatioID);
                    /*Denominator*/
                    TempBuff[i*2 + 1] = DEM_OBD_RATIO_DENOMINATOR(RatioID);
                }
            }
        }

        for(i = 0; i < (DEM_OBD_INFO0B_DATA_LENGTH/2); i++)
        {
            Iumprdata0B[i*2] = (uint8)(TempBuff[i] >> 8);
            Iumprdata0B[i*2 + 1] = (uint8)(TempBuff[i]);
        }
        *Iumprdata0BBufferSize = DEM_OBD_INFO0B_DATA_LENGTH;

        Result = E_OK;
#endif/*#if(DEM_CFG_OBD_ENGINE_TYPE == DEM_IGNITION_COMPRESSION)*/
#endif/*#if(DEM_NUM_OF_RATIO > 0)*/
    }
    return Result;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_DcmReadDataOfPID01
*
* Description: Service to report the value of PID $01 computed by the Dem.
*
* Inputs: None.
*
* Outputs: PID01value: Buffer containing the contents of PID $01 computed by the
*                      Dem.
*
* Return: Always E_OK is returned, as E_NOT_OK will never appear.
*
* Limitations: This API will be available only if ({ecuc(Dem/DemGeneral.DemOBD-
*              Support)} != DEM_OBD_NO_OBD_SUPPORT)
********************************************************************************
END_FUNCTION_HDR*/
/*SWS_Dem_00318*/
FUNC(Std_ReturnType, DEM_CODE) Dem_DcmReadDataOfPID01
(
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) PID01value
)
{
    Std_ReturnType Result = E_NOT_OK;

    Result = Dem_ReadDataOfPID01(PID01value);

    return Result;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_DcmReadDataOfPID1C
*
* Description: Service to report the value of PID $1C computed by the Dem.
*
* Inputs: None.
*
* Outputs: PID1Cvalue: Buffer containing the contents of PID $1C computed by the
*                      Dem.
*
* Return: Always E_OK is returned, as E_NOT_OK will never appear.
*
* Limitations: This API will be available only if ({ecuc(Dem/DemGeneral.DemOBD-
*              Support)} != DEM_OBD_NO_OBD_SUPPORT)
********************************************************************************
END_FUNCTION_HDR*/
/*SWS_Dem_00325*/
FUNC(Std_ReturnType, DEM_CODE) Dem_DcmReadDataOfPID1C
(
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) PID1Cvalue
)
{
    Std_ReturnType Result = E_NOT_OK;

    if(Dem_State != DEM_NORMAL)
    {
        /*SWS_Dem_01112*//*SWS_Dem_00124*/
        DEM_DET_REPORT_ERROR(DEM_DCMREADDATAOFPID1C_APIID, DEM_E_UNINIT);
    }
    else if(PID1Cvalue == NULL_PTR)
    {
        DEM_DET_REPORT_ERROR(DEM_DCMREADDATAOFPID1C_APIID, DEM_E_PARAM_POINTER);
    }
    else
    {
        /*Not implemented.*/
        Result = E_OK;
    }
    return Result;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_DcmReadDataOfPID21
*
* Description: Service to report the value of PID $21 computed by the Dem.
*
* Inputs: None.
*
* Outputs: PID21value: Buffer containing the contents of PID $21 computed by the
*                      Dem.
*
* Return: Always E_OK is returned, as E_NOT_OK will never appear.
*
* Limitations: This API will be available only if ({ecuc(Dem/DemGeneral.DemOBD-
*              Support)} != DEM_OBD_NO_OBD_SUPPORT)
********************************************************************************
END_FUNCTION_HDR*/
/*SWS_Dem_00319*/
FUNC(Std_ReturnType, DEM_CODE) Dem_DcmReadDataOfPID21
(
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) PID21value
)
{
    Std_ReturnType Result = E_NOT_OK;

    if(Dem_State != DEM_NORMAL)
    {
        /*SWS_Dem_01112*//*SWS_Dem_00124*/
        DEM_DET_REPORT_ERROR(DEM_DCMREADDATAOFPID21_APIID, DEM_E_UNINIT);
    }
    else if(PID21value == NULL_PTR)
    {
        DEM_DET_REPORT_ERROR(DEM_DCMREADDATAOFPID21_APIID, DEM_E_PARAM_POINTER);
    }
    else
    {
        /*Not implemented.*/
        Result = E_OK;
    }
    return Result;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_DcmReadDataOfPID30
*
* Description: Service to report the value of PID $30 computed by the Dem.
*
* Inputs: None.
*
* Outputs: PID30value: Buffer containing the contents of PID $30 computed by the
*                      Dem.
*
* Return: Always E_OK is returned, as E_NOT_OK will never appear.
*
* Limitations: This API will be available only if ({ecuc(Dem/DemGeneral.DemOBD-
*              Support)} != DEM_OBD_NO_OBD_SUPPORT)
********************************************************************************
END_FUNCTION_HDR*/
/*SWS_Dem_00320*/
FUNC(Std_ReturnType, DEM_CODE) Dem_DcmReadDataOfPID30
(
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) PID30value
)
{
    Std_ReturnType Result = E_NOT_OK;

    if(Dem_State != DEM_NORMAL)
    {
        /*SWS_Dem_01112*//*SWS_Dem_00124*/
        DEM_DET_REPORT_ERROR(DEM_DCMREADDATAOFPID30_APIID, DEM_E_UNINIT);
    }
    else if(PID30value == NULL_PTR)
    {
        DEM_DET_REPORT_ERROR(DEM_DCMREADDATAOFPID30_APIID, DEM_E_PARAM_POINTER);
    }
    else
    {
        /*Not implemented.*/
        Result = E_OK;
    }
    return Result;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_DcmReadDataOfPID31
*
* Description: Service to report the value of PID $31 computed by the Dem.
*
* Inputs: None.
*
* Outputs: PID31value: Buffer containing the contents of PID $31 computed by the
*                      Dem.
*
* Return: Always E_OK is returned, as E_NOT_OK will never appear.
*
* Limitations: This API will be available only if ({ecuc(Dem/DemGeneral.DemOBD-
*              Support)} != DEM_OBD_NO_OBD_SUPPORT)
********************************************************************************
END_FUNCTION_HDR*/
/*SWS_Dem_00321*/
FUNC(Std_ReturnType, DEM_CODE) Dem_DcmReadDataOfPID31
(
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) PID31value
)
{
    Std_ReturnType Result = E_NOT_OK;
    uint32 Distance;

    if(Dem_State != DEM_NORMAL)
    {
        /*SWS_Dem_01112*//*SWS_Dem_00124*/
        DEM_DET_REPORT_ERROR(DEM_DCMREADDATAOFPID31_APIID, DEM_E_UNINIT);
    }
    else if(PID31value == NULL_PTR)
    {
        DEM_DET_REPORT_ERROR(DEM_DCMREADDATAOFPID31_APIID, DEM_E_PARAM_POINTER);
    }
    else
    {
        Distance = (uint32)(DEM_OBD_DISTANCE_SINCEDTCCLEARED/1000);
        PID31value[0] = (uint8)(Distance >> 8);
        PID31value[1] = (uint8)Distance;

        Result = E_OK;
    }
    return Result;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_DcmReadDataOfPID41
*
* Description: Service to report the value of PID $41 computed by the Dem.
*
* Inputs: None.
*
* Outputs: PID41value: Buffer containing the contents of PID $41 computed by the
*                      Dem.
*
* Return: Always E_OK is returned, as E_NOT_OK will never appear.
*
* Limitations: This API will be available only if ({ecuc(Dem/DemGeneral.DemOBD-
*              Support)} != DEM_OBD_NO_OBD_SUPPORT)
********************************************************************************
END_FUNCTION_HDR*/
/*SWS_Dem_00322*/
FUNC(Std_ReturnType, DEM_CODE) Dem_DcmReadDataOfPID41
(
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) PID41value
)
{
    Std_ReturnType Result = E_NOT_OK;
#if(DEM_CFG_OBD_SUPPORT == DEM_OBD_MASTER_ECU)
    Dem_EventIdType EventId;
    uint16 DtcId;
    Dem_UdsStatusByteType DtcStatus;
    uint8 BytePos;
    uint8 BitPos;
#endif

    if(Dem_State != DEM_NORMAL)
    {
        /*SWS_Dem_01112*//*SWS_Dem_00124*/
        DEM_DET_REPORT_ERROR(DEM_DCMREADDATAOFPID41_APIID, DEM_E_UNINIT);
    }
    else if(PID41value == NULL_PTR)
    {
        DEM_DET_REPORT_ERROR(DEM_DCMREADDATAOFPID41_APIID, DEM_E_PARAM_POINTER);
    }
    else
    {
#if(DEM_CFG_OBD_SUPPORT == DEM_OBD_MASTER_ECU)
        PID41value[0] = DEM_DATA_CLEAR;
        PID41value[1] = DEM_DATA_CLEAR;
        PID41value[2] = DEM_DATA_CLEAR;
        PID41value[3] = DEM_DATA_CLEAR;

        for(EventId = 0; EventId < DEM_NUM_OF_EVENT; EventId++)
        {
            DtcId = DEM_CFG_EVENT_DTCREF(EventId);
            /*SWS_Dem_00355*/
#if((DEM_CONFIG_VARIANTS != STD_CONFIG_VARIANTS_POSTBUILD) \
    && (DEM_CFG_AVAILABILITYSUPPORT == DEM_EVENT_AVAILABILITY))
            if((Dem_EventAvailable[EventId] == TRUE) \
                && (DEM_CFG_DTC_OBDDTCREF(DtcId) != NULL_PTR) \
                && (DEM_CFG_DTC_OBD_READINESSGROUP(DtcId) != DEM_OBD_RDY_NONE))
#else
            if((DEM_CFG_DTC_OBDDTCREF(DtcId) != NULL_PTR) \
                && (DEM_CFG_DTC_OBD_READINESSGROUP(DtcId) != DEM_OBD_RDY_NONE))
#endif
            {
                BytePos = (DEM_CFG_DTC_OBD_READINESSGROUP(DtcId)/8);
                BitPos = (DEM_CFG_DTC_OBD_READINESSGROUP(DtcId)%8);
                /*SWS_Dem_00356*/
                if((DEM_OBD_READINESSGROUP_STATUS[BytePos] & ((uint8)0x01 << BitPos)) != (uint8)0)
                {
                    /*Set value of monitors enable bit*/
                    PID41value[BytePos + 1] |= ((uint8)0x01 << BitPos);

                    DtcStatus = DEM_DTC_STATUS(DtcId);
                    /*Monitor status this driving cycle*/
                    if(DEM_TEST_UDS_STATUS_TNCTOC(DtcStatus))
                    {
                        switch(BytePos)
                        {
                            /*Set value of monitors compleate bit
                            0 = monitor complete this monitoring cycle (YES)
                            0 = monitor not supported (N/A)
                            1 = monitor not complete this monitoring cycle (NO)*/
                            case 0:
                                PID41value[1] |= ((uint8)0x40 << BitPos);
                            break;

                            default:
                                PID41value[3] |= ((uint8)0x01 << BitPos);
                            break;
                        }
                    }
                }/*if((DEM_OBD_READINESSGROUP_STATUS[BytePos] & ((uint8)0x01 << BitPos)) != (uint8)0)*/
            }
        }/*for(EventId = 0; EventId < DEM_NUM_OF_EVENT; EventId++)*/

        Result = E_OK;
#endif/*#if(DEM_CFG_OBD_SUPPORT == DEM_OBD_MASTER_ECU)*/
    }
    return Result;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_DcmReadDataOfPID4D
*
* Description: Service to report the value of PID $4D computed by the Dem.
*
* Inputs: None.
*
* Outputs: PID4Dvalue: Buffer containing the contents of PID $4D computed by the
*                      Dem.
*
* Return: Always E_OK is returned, as E_NOT_OK will never appear.
*
* Limitations: This API will be available only if ({ecuc(Dem/DemGeneral.DemOBD-
*              Support)} != DEM_OBD_NO_OBD_SUPPORT)
********************************************************************************
END_FUNCTION_HDR*/
/*SWS_Dem_00323*/
FUNC(Std_ReturnType, DEM_CODE) Dem_DcmReadDataOfPID4D
(
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) PID4Dvalue
)
{
    Std_ReturnType Result = E_NOT_OK;

    if(Dem_State != DEM_NORMAL)
    {
        /*SWS_Dem_01112*//*SWS_Dem_00124*/
        DEM_DET_REPORT_ERROR(DEM_DCMREADDATAOFPID4D_APIID, DEM_E_UNINIT);
    }
    else if(PID4Dvalue == NULL_PTR)
    {
        DEM_DET_REPORT_ERROR(DEM_DCMREADDATAOFPID4D_APIID, DEM_E_PARAM_POINTER);
    }
    else
    {
        /*Not implemented.*/
        Result = E_OK;
    }
    return Result;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_DcmReadDataOfPID4E
*
* Description: Service to report the value of PID $4E computed by the Dem.
*
* Inputs: None.
*
* Outputs: PID4Evalue: Buffer containing the contents of PID $4E computed by the
*                      Dem.
*
* Return: Always E_OK is returned, as E_NOT_OK will never appear.
*
* Limitations: This API will be available only if ({ecuc(Dem/DemGeneral.DemOBD-
*              Support)} != DEM_OBD_NO_OBD_SUPPORT)
********************************************************************************
END_FUNCTION_HDR*/
/*SWS_Dem_00324*/
FUNC(Std_ReturnType, DEM_CODE) Dem_DcmReadDataOfPID4E
(
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) PID4Evalue
)
{
    Std_ReturnType Result = E_NOT_OK;

    if(Dem_State != DEM_NORMAL)
    {
        /*SWS_Dem_01112*//*SWS_Dem_00124*/
        DEM_DET_REPORT_ERROR(DEM_DCMREADDATAOFPID4E_APIID, DEM_E_UNINIT);
    }
    else if(PID4Evalue == NULL_PTR)
    {
        DEM_DET_REPORT_ERROR(DEM_DCMREADDATAOFPID4E_APIID, DEM_E_PARAM_POINTER);
    }
    else
    {
        /*Not implemented.*/
        Result = E_OK;
    }
    return Result;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_DcmReadDataOfPID91
*
* Description: Service to report the value of PID $91 computed by the Dem.
*
* Inputs: None.
*
* Outputs: PID91value: Buffer containing the contents of PID $91 computed by the
*                      Dem.
*
* Return: Always E_OK is returned, as E_NOT_OK will never appear.
*
* Limitations: This API will be available only if ({ecuc(Dem/DemGeneral.DemOBD-
*              Support)} != DEM_OBD_NO_OBD_SUPPORT)
********************************************************************************
END_FUNCTION_HDR*/
/*SWS_Dem_01187*/
FUNC(Std_ReturnType, DEM_CODE) Dem_DcmReadDataOfPID91
(
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) PID91value
)
{
    Std_ReturnType Result = E_NOT_OK;

    if(Dem_State != DEM_NORMAL)
    {
        /*SWS_Dem_01112*//*SWS_Dem_00124*/
        DEM_DET_REPORT_ERROR(DEM_DCMREADDATAOFPID91_APIID, DEM_E_UNINIT);
    }
    else if(PID91value == NULL_PTR)
    {
        DEM_DET_REPORT_ERROR(DEM_DCMREADDATAOFPID91_APIID, DEM_E_PARAM_POINTER);
    }
    else
    {
        /*Not implemented.*/
        Result = E_OK;
    }
    return Result;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_DcmReadDataOfOBDFreezeFrame
*
* Description: Gets data element per PID and index of the most important freeze
*              frame being selected for the output of service $02.
*
* Inputs: PID: This parameter is an identifier for a PID as defined in ISO15031-5.
*         DataElementIndexOfPID: Data element index of this PID according to the
*                                Dcm configuration of service $02. It is zero-based
*                                and consecutive, and ordered by the data element
*                                positions.
*         DestBuffer: This parameter contains a byte pointer that points to the
*                     buffer, to which the data element of the PID shall be
*                     written to.
*         BufSize: When the function is called this parameter contains the maximum
*                  number of data bytes that can be written to the buffer.
*
* Outputs: DestBuffer
*          BufSize: The function returns the actual number of written data bytes
*                   in this parameter.
*
* Return: E_OK: Freeze frame data was successfully reported.
*         E_NOT_OK: Freeze frame data was not successfully reported.
*
* Limitations: This API will be available only if ({ecuc(Dem/DemGeneral.DemOBD-
*              Support)} != DEM_OBD_NO_OBD_SUPPORT)
********************************************************************************
END_FUNCTION_HDR*/
/*SWS_Dem_00327*/
FUNC(Std_ReturnType, DEM_CODE) Dem_DcmReadDataOfOBDFreezeFrame
(
    uint8 PID,
    uint8 DataElementIndexOfPID,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DestBuffer,
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) BufSize
)
{
    Std_ReturnType Result = E_NOT_OK;
    uint8 PidIndex;
    uint8 DataIndex;/*Data index of Pid*/
    uint8 DataIndexOfDataClass;/*Data index of DataElementClass*/
    uint8 *SrcDataPtr;

    if(Dem_State != DEM_NORMAL)
    {
        /*SWS_Dem_01112*//*SWS_Dem_00124*/
        DEM_DET_REPORT_ERROR(DEM_DCMREADDATAOFOBDFREEZEFRAME_APIID, DEM_E_UNINIT);
    }
    else if((DestBuffer == NULL_PTR) || (BufSize == NULL_PTR))
    {
        DEM_DET_REPORT_ERROR(DEM_DCMREADDATAOFOBDFREEZEFRAME_APIID, DEM_E_PARAM_POINTER);
    }
    else if(DEM_OBD_FF_EVENT == DEM_EVENT_ID_INVALID)
    {
        DEM_DET_REPORT_ERROR(DEM_DCMREADDATAOFOBDFREEZEFRAME_APIID, DEM_E_NODATAAVAILABLE);
    }
    else
    {
        SrcDataPtr = DEM_OBD_FF_DATA_BUF;
#if(DEM_CFG_OBD_NUM_OF_PID > 0)
        /*SWS_Dem_00596*//*SWS_Dem_00597*/
        for(PidIndex = 0; PidIndex < DEM_CFG_OBD_NUM_OF_PID; PidIndex++)
        {
            SrcDataPtr++;/*PID length: one byte*/

            if((DEM_CFG_PID_ID(PidIndex) == PID) \
                && (DataElementIndexOfPID < DEM_CFG_PID_NUM_OF_DATA(PidIndex)))
            {
                DataIndexOfDataClass = DEM_CFG_PID_DATA_CLASS(PidIndex)[DataElementIndexOfPID];

                if(*BufSize < DEM_CFG_DATA_CS_DATA_SIZE(DataIndexOfDataClass))
                {
                    DEM_DET_REPORT_ERROR(DEM_DCMREADDATAOFOBDFREEZEFRAME_APIID, DEM_E_PARAM_LENGTH);
                }
                else
                {
                    for(DataIndex = 0; DataIndex < DEM_CFG_PID_NUM_OF_DATA(PidIndex); DataIndex++)
                    {
                        DataIndexOfDataClass = DEM_CFG_PID_DATA_CLASS(PidIndex)[DataIndex];

                        if(DataIndex == DataElementIndexOfPID)
                        {
                            *BufSize = DEM_CFG_DATA_CS_DATA_SIZE(DataIndexOfDataClass);
                            Bsw_MemCpy(DestBuffer, SrcDataPtr, (*BufSize));
                        }
                        else
                        {
                            SrcDataPtr += DEM_CFG_DATA_CS_DATA_SIZE(DataIndexOfDataClass);
                        }
                    }
                    Result = E_OK;
                }
                break;
            }
            else
            {
                for(DataIndex = 0; DataIndex < DEM_CFG_PID_NUM_OF_DATA(PidIndex); DataIndex++)
                {
                    DataIndexOfDataClass = DEM_CFG_PID_DATA_CLASS(PidIndex)[DataIndex];
                    SrcDataPtr += DEM_CFG_DATA_CS_DATA_SIZE(DataIndexOfDataClass);
                }
            }
        }

        if(PidIndex == DEM_CFG_OBD_NUM_OF_PID)
        {
            DEM_DET_REPORT_ERROR(DEM_DCMREADDATAOFOBDFREEZEFRAME_APIID, DEM_E_PARAM_DATA);
        }
#endif
    }
    return Result;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_DcmGetDTCOfOBDFreezeFrame
*
* Description: Gets DTC by freeze frame record number.
*
* Inputs: FrameNumber: Unique identifier for a freeze frame record as defined in
*                      ISO 15031-5. The value 0x00 indicates the complete OBD
*                      freeze frame. Other values are reserved for future
*                      functionality.
*         DTCFormat: Output format of the DTC value.
*
* Outputs: DTC: Diagnostic Trouble Code in ODB format.
*
* Return: E_OK: operation was successful
*         E_NOT_OK: no DTC available
*
* Limitations: This API will be available only if ({ecuc(Dem/DemGeneral.DemOBD-
*              Support)} != DEM_OBD_NO_OBD_SUPPORT)
********************************************************************************
END_FUNCTION_HDR*/
/*SWS_Dem_00624*/
FUNC(Std_ReturnType, DEM_CODE) Dem_DcmGetDTCOfOBDFreezeFrame
(
    uint8 FrameNumber,
    P2VAR(uint32, AUTOMATIC, DEM_APPL_DATA) DTC,
    Dem_DTCFormatType DTCFormat
)
{
    Std_ReturnType Result = E_NOT_OK;

    if(Dem_State != DEM_NORMAL)
    {
        /*SWS_Dem_01112*//*SWS_Dem_00124*/
        DEM_DET_REPORT_ERROR(DEM_DCMGETDTCOFOBDFREEZEFRAME_APIID, DEM_E_UNINIT);
    }
    else if(DTC == NULL_PTR)
    {
        DEM_DET_REPORT_ERROR(DEM_DCMGETDTCOFOBDFREEZEFRAME_APIID, DEM_E_PARAM_POINTER);
    }
    else if(DTCFormat != DEM_DTC_FORMAT_OBD)
    {
        DEM_DET_REPORT_ERROR(DEM_DCMGETDTCOFOBDFREEZEFRAME_APIID, DEM_E_PARAM_DATA);
    }
    else
    {
        /*SWS_Dem_00291*/
        if(FrameNumber == 0)
        {
            if(DEM_OBD_FF_EVENT != DEM_EVENT_ID_INVALID)
            {
                /*SWS_Dem_00623*/
                *DTC = (uint32)DEM_CFG_DTC_OBD_VALUE(DEM_CFG_EVENT_DTCREF(DEM_OBD_FF_EVENT));
                Result = E_OK;
            }
        }
    }
    return Result;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_DcmGetAvailableOBDMIDs
*
* Description: Reports the value of a requested "availability-OBDMID" to the DCM
*              upon a Service $06 request.
*
* Inputs: Obdmid: Availablity OBDMID ($00,$20, $40...)
*
* Outputs: Obdmidvalue: Bit coded information on the support of OBDMIDs.
*
* Return: E_OK: Report of DTR result successful
*         E_NOT_OK: Report of DTR result failed
*
* Limitations: This API will be available only if ({ecuc(Dem/DemGeneral.DemOBD-
*              Support)} != DEM_OBD_NO_OBD_SUPPORT)
********************************************************************************
END_FUNCTION_HDR*/
/*SWS_Dem_00766*/
FUNC(Std_ReturnType, DEM_CODE) Dem_DcmGetAvailableOBDMIDs
(
    uint8 Obdmid,
    P2VAR(uint32, AUTOMATIC, DEM_APPL_DATA) Obdmidvalue
)
{
    Std_ReturnType Result = E_NOT_OK;

    /*Not implemented.*/

    return Result;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_DcmGetNumTIDsOfOBDMID
*
* Description: Gets the number of TIDs per (functional) OBDMID.
*
* Inputs: Obdmid: OBDMID subject of the request to identify the number of
*                 assigned TIDs.
*
* Outputs: numberOfTIDs: Number of assigned TIDs for the requested OBDMID.
*
* Return: E_OK: get number of TIDs successful
*         E_NOT_OK: get number of TIDs failed
*
* Limitations: This API will be available only if ({ecuc(Dem/DemGeneral.DemOBD-
*              Support)} != DEM_OBD_NO_OBD_SUPPORT)
********************************************************************************
END_FUNCTION_HDR*/
/*SWS_Dem_00767*/
FUNC(Std_ReturnType, DEM_CODE) Dem_DcmGetNumTIDsOfOBDMID
(
    uint8 Obdmid,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) numberOfTIDs
)
{
    Std_ReturnType Result = E_NOT_OK;

    /*Not implemented.*/

    return Result;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_DcmGetNumTIDsOfOBDMID
*
* Description: Reports a DTR data along with TID-value, UaSID, test result with
*              lower and upper limit.
*
* Inputs: Obdmid: Identification of a DTR element by assigned DTRId.
*         TIDindex: Index of the TID within the DEM. Runs from 0 to "numberOfTIDs"
*                   obtained in the call to Dem_DcmGetNumTIDsOfOBDMID().
*
* Outputs: TIDvalue: TID to be put on the tester reponse.
*          UaSID: UaSID to be put on the tester reponse.
*          Testvalue: Latest test result.
*          Lowlimvalue: Lower limit value associated to the latest test result.
*          Upplimvalue: Upper limit value associated to the latest test result.
*
* Return: E_OK: get number of TIDs successful
*         E_NOT_OK: get number of TIDs failed
*
* Limitations: This API will be available only if ({ecuc(Dem/DemGeneral.DemOBD-
*              Support)} != DEM_OBD_NO_OBD_SUPPORT)
********************************************************************************
END_FUNCTION_HDR*/
/*SWS_Dem_00768*/
FUNC(Std_ReturnType, DEM_CODE) Dem_DcmGetDTRData
(
    uint8 Obdmid,
    uint8 TIDindex,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) TIDvalue,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) UaSID,
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) Testvalue,
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) Lowlimvalue,
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) Upplimvalue
)
{
    Std_ReturnType Result = E_NOT_OK;

    /*Not implemented.*/

    return Result;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_DcmGetDTCSeverityAvailabilityMask
*
* Description: Gets the DTC Severity availability mask.
*
* Inputs: None.
*
* Outputs: DTCSeverityMask: The value DTCSeverityMask indicates the supported
*                           DTC severity bits from the Dem.
*
* Return: E_OK: get of DTC severity mask was successful
*         E_NOT_OK: get of DTC severity mask failed
*
* Limitations: This API will be available only if ({ecuc(Dem/DemGeneral.DemOBD-
*              Support)} != DEM_OBD_NO_OBD_SUPPORT)
********************************************************************************
END_FUNCTION_HDR*/
/*SWS_Dem_01168*/
FUNC(Std_ReturnType, DEM_CODE) Dem_DcmGetDTCSeverityAvailabilityMask
(
    P2VAR(Dem_DTCSeverityType, AUTOMATIC, DEM_APPL_DATA) DTCSeverityMask
)
{
    Std_ReturnType Result = E_OK;
    uint16 i;

    if(DTCSeverityMask == NULL_PTR)
    {
        DEM_DET_REPORT_ERROR(DEM_DCMGETDTCSEVERITYAVAILABILITYMASK_APIID, DEM_E_PARAM_POINTER);
        Result = E_NOT_OK;
    }
    else
    {
        *DTCSeverityMask = DEM_SEVERITY_NO_SEVERITY;
        /*SWS_Dem_01181*//*SWS_Dem_01182*/
        for(i = 0; i < DEM_NUM_OF_DTC; i++)
        {
            *DTCSeverityMask |= DEM_CFG_DTC_SEVERITY(i);
#if((DEM_CFG_OBD_SUPPORT == DEM_OBD_MASTER_ECU)||(DEM_CFG_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU))
            *DTCSeverityMask |= DEM_CFG_DTC_OBDDTCCLASS(i);
#endif
        }
    }
    return Result;
}
#endif/*#if((DEM_CFG_OBD_SUPPORT == DEM_OBD_MASTER_ECU)||(DEM_CFG_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU))*/

#define DEM_STOP_SEC_CODE
#include "MemMap.h"



/*******************************************************************************
*   Dem_NvM
*******************************************************************************/
#define DEM_START_SEC_CODE
#include "MemMap.h"

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name:
*
* Description:
*
* Inputs:
*
* Outputs:
*
* Return:
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, DEM_CODE) Dem_NvM_InitStorageMem
(
    void
)
{
    uint16 i;

    DEM_EVENT_FIRST_FAILED = DEM_DATA_INVALID_U16;
    DEM_EVENT_RECENT_FAILED = DEM_DATA_INVALID_U16;
    DEM_EVENT_FIRST_CONFIRMED = DEM_DATA_INVALID_U16;
    DEM_EVENT_RECENT_CONFIRMED = DEM_DATA_INVALID_U16;

    for(i = 0; i < DEM_NUM_OF_EVENT; i++)
    {
        DEM_EVENT_FCC(i) = DEM_DATA_CLEAR;
#if(DEM_NUM_OF_INDICATOR > 0)
        DEM_EVENT_IFCC(i) = DEM_DATA_CLEAR;
        DEM_EVENT_IHCC(i) = DEM_DATA_CLEAR;
#endif
        DEM_EVENT_OCCCTR(i) = DEM_DATA_CLEAR;
#if(DEM_CFG_DEBOUNCECOUNTERBASEDSUPPORT == STD_ON)
        DEM_EVENT_DBC(i) = 0;
#endif
#if(DEM_CFG_DEBOUNCETIMEBASEDSUPPORT == STD_ON)
        DEM_EVENT_DBT(i) = 0;
        DEM_EVENT_TIMERDIRECTION(i) = DEM_DATA_INVALID_U8;
#endif
        DEM_EVENT_MAXFDCDCC(i) = 0;
        DEM_EVENT_MAXFDCSLC(i) = 0;
        DEM_EVENT_CSLF(i) = DEM_DATA_CLEAR;
        DEM_EVENT_CSFF(i) = DEM_DATA_CLEAR;
        DEM_EVENT_FCSLC(i) = DEM_DATA_CLEAR;
#if((DEM_CFG_OBD_SUPPORT == DEM_OBD_MASTER_ECU)||(DEM_CFG_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU))
        DEM_EVENT_OBD_PCSLF(i) = DEM_DATA_CLEAR;
#endif
#if(DEM_CFG_MAXNUMBEREVENTENTRY_PERMANENT > 0)
        DEM_EVENT_OBD_CLEAR_FLAG(i) = FALSE;
#endif
#if(STD_ON == DEM_CMA_PLATFORM_ENABLED)
        DEM_EVENT_CMA_PCSLF(i) = DEM_DATA_CLEAR;
        DEM_EVENT_CMA_STATUS(i) = DEM_DATA_CLEAR;
#endif
    }

    for(i = 0; i < DEM_NUM_OF_DTC; i++)
    {
        DEM_DTC_STATUS(i) = DEM_STATUS_RESET;
        DEM_DTC_LASTSTATUS(i) = DEM_STATUS_RESET;
        DEM_DTC_AGINGCNT(i) = DEM_DATA_CLEAR;
        DEM_DTC_AGEDCNT(i) = DEM_DATA_CLEAR;
        DEM_DTC_DATAENTRYREF(i) = DEM_DATA_INVALID_U16;
    }

    DEM_PRIMARY_DATAENTRY_USEDNUM = DEM_DATA_CLEAR;

    for(i = 0; i < DEM_CFG_MAXNUMBEREVENTENTRY_PRIMARY; i++)
    {
        DEM_PRIMARY_DATAENTRY_USED(i) = FALSE;
        DemInternal_ClearOneMemoryEntry(i);
    }

#if(DEM_CFG_MAXNUMBEREVENTENTRY_PERMANENT > 0)
    DEM_PERMANENT_DATAENTRY_USEDNUM = DEM_DATA_CLEAR;

    for(i = 0; i < DEM_CFG_MAXNUMBEREVENTENTRY_PERMANENT; i++)
    {
        DEM_PERMANENT_DATAENTRY_EVENTID(i) = DEM_EVENT_ID_INVALID;
    }
#endif/*#if(DEM_CFG_MAXNUMBEREVENTENTRY_PERMANENT > 0)*/

#if(DEM_NUM_OF_INDICATOR > 0)
    for(i = 0; i < DEM_NUM_OF_BYTE_RECORD_INDICATOR_STATE; i++)
    {
        DEM_INDICATOR_STATUS(i) = DEM_INDICATOR_OFF;
    }
#endif

#if((DEM_CFG_OBD_SUPPORT == DEM_OBD_MASTER_ECU)||(DEM_CFG_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU))
    DemInternal_InitOBDData();
#endif

    return E_OK;
}

#if(STD_ON == DEM_NVM_SUPPORT)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name:
*
* Description:
*
* Inputs:
*
* Outputs:
*
* Return:
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, DEM_CODE) Dem_NvM_JobResultInd
(
    uint8 ServiceId,
    NvM_RequestResultType JobResult
)
{
    Std_ReturnType Result = E_NOT_OK;

    if(((ServiceId == NVM_JOB_READ) || (ServiceId == NVM_JOB_READALL)) \
            && (JobResult != NVM_REQ_OK))
    {
        Result = Dem_NvM_InitStorageMem();
    }
    return Result;
}
#endif

#define DEM_STOP_SEC_CODE
#include "MemMap.h"



/*******************************************************************************
*   Dem_J1939Dcm
*******************************************************************************/
#define DEM_START_SEC_CODE
#include "MemMap.h"
/*******************************************************************************
* Access DTCs and Status Information
*******************************************************************************/

#if(STD_ON == DEM_CFG_J1939READING_DTC_SUPPORT)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_J1939DcmSetDTCFilter
*
* Description: The function sets the DTC filter for a specific node and returns
*              the composite lamp status of the filtered DTCs.
*
* Inputs: DTCStatusFilter,DTCKind,node
*
* Outputs: LampStatus
*
* Return: Dem_ReturnSetFilterType
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
/*SWS_Dem_00970*/
FUNC(Dem_ReturnSetFilterType, DEM_CODE) Dem_J1939DcmSetDTCFilter
(
    Dem_J1939DcmDTCStatusFilterType DTCStatusFilter,
    Dem_DTCKindType DTCKind,
    uint8 node,
    P2VAR(Dem_J1939DcmLampStatusType, AUTOMATIC, DEM_APPL_DATA) LampStatus
)
{
    Dem_ReturnSetFilterType Result = DEM_FILTER_ACCEPTED;
    uint16 i;
    uint8 j;
    Dem_UdsStatusByteType DTCStatus;
#if(DEM_NUM_OF_INDICATOR > 0)
    Dem_IndicatorStatusType IndicatorStatus;
#endif

    if(Dem_State != DEM_NORMAL)
    {
        /*SWS_Dem_01112*//*SWS_Dem_00124*/
        DEM_DET_REPORT_ERROR(DEM_J1939DCMSETDTCFILTER_APIID, DEM_E_UNINIT);
        Result = DEM_WRONG_FILTER;
    }
    else if(DTCStatusFilter > DEM_J1939DTC_CURRENTLY_ACTIVE)
    {
        DEM_DET_REPORT_ERROR(DEM_J1939DCMSETDTCFILTER_APIID, DEM_E_PARAM_DATA);
        Result = DEM_WRONG_FILTER;
    }
    else if(DTCKind != DEM_DTC_KIND_ALL_DTCS)
    {
        /*Only support DM01 and DM02*/
        DEM_DET_REPORT_ERROR(DEM_J1939DCMSETDTCFILTER_APIID, DEM_E_PARAM_DATA);
        Result = DEM_WRONG_FILTER;
    }
    else
    {
        /*SWS_Dem_00855*//*SWS_Dem_00856*/
        Dem_J1939DcmFilterInfo.DTCStatusFilter = DTCStatusFilter;
        Dem_J1939DcmFilterInfo.DTCKind = DTCKind;
        Dem_J1939DcmFilterInfo.node = node;
        Dem_J1939DcmFilterInfo.NumberOfFilteredDTC = DEM_DATA_CLEAR;
        Dem_J1939DcmFilterInfo.NextFilteredDTCIndex = DEM_DATA_CLEAR;
        Dem_J1939DcmFilterInfo.FreezeFrameKind = DEM_DATA_INVALID_U8;
#if(((DEM_CFG_OBD_SUPPORT == DEM_OBD_MASTER_ECU)||(DEM_CFG_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU))||(DEM_J1939_SUPPORT == STD_ON))
        /*Only support DM01 and DM02*/
        for(i = 0; i < DEM_NUM_OF_DTC; i++)
        {
            if((DEM_CFG_DTC_J1939NODE_REF(i) != NULL_PTR) && \
                (DEM_CFG_DTC_OBDDTCREF(i) != NULL_PTR) && (DEM_CFG_DTC_J1939_VALUE(i) != (uint32)0))
            {
                for(j = 0; j < DEM_CFG_DTC_J1939NODE_NUM(i); j++)
                {
                    if((DEM_CFG_DTC_J1939NODE_ARRAY(i)[j]) == node)
                    {
                        DTCStatus = DEM_DTC_STATUS(i);
                        if((DTCStatusFilter == DEM_J1939DTC_ACTIVE) \
                                && (DEM_TEST_UDS_STATUS_TF(DTCStatus)) \
                                && (DEM_TEST_UDS_STATUS_CDTC(DTCStatus)))
                        {
                            /*Request by DM01*/
                            Dem_J1939DcmFilterInfo.FilteredDTCIndexTable[Dem_J1939DcmFilterInfo.NumberOfFilteredDTC] = i;
                            Dem_J1939DcmFilterInfo.NumberOfFilteredDTC++;
                        }
                        else if((DTCStatusFilter == DEM_J1939DTC_PREVIOUSLY_ACTIVE) \
                                && (!DEM_TEST_UDS_STATUS_TF(DTCStatus)) \
                                && (DEM_TEST_UDS_STATUS_CDTC(DTCStatus)))
                        {
                            /*Request by DM02*/
                            Dem_J1939DcmFilterInfo.FilteredDTCIndexTable[Dem_J1939DcmFilterInfo.NumberOfFilteredDTC] = i;
                            Dem_J1939DcmFilterInfo.NumberOfFilteredDTC++;
                        }
                        else
                        {
                            /*do nothing*/
                        }
                        break;
                    }
                }
            }
        }
#endif
        /*SWS_Dem_00857*/
#if(DEM_NUM_OF_INDICATOR > 0)
        *LampStatus = DEM_J1939_MIL_OFF;
        /*Returns a composite lamp status of MIL.*/
        if(DEM_CFG_MILINDICATORREF < DEM_NUM_OF_INDICATOR)
        {
            DemInternal_GetIndicatorStatus(DEM_CFG_MILINDICATORREF, &IndicatorStatus);

            if(IndicatorStatus != DEM_INDICATOR_OFF)
            {
                /*SWS_Dem_00858 MIL status should be ON*/
                *LampStatus |= DEM_J1939_MIL_ON;
            }

            if(IndicatorStatus == DEM_INDICATOR_SLOW_FLASH)
            {
                /*SWS_Dem_00860 Flash MIL status should be SlowFlash, no need change*/
            }
            else if(IndicatorStatus == DEM_INDICATOR_FAST_FLASH)
            {
                /*SWS_Dem_00861 Flash MIL status should be FastFlash.*/
                *LampStatus |= DEM_J1939_FMIL_FF;
            }
            else
            {
                /*SWS_Dem_00859 Flash MIL status should be Unavailable/DoNotFlash.*/
                *LampStatus |= DEM_J1939_FMIL_UNAVAILABLE;
            }
        }
        else
        {
            /*MIL is unavailable*/
            *LampStatus |= DEM_J1939_MIL_UNAVAILABLE;
            *LampStatus |= DEM_J1939_FMIL_UNAVAILABLE;
        }

        /*Returns a composite lamp status of Red Stop lamp.*/
        if(DEM_CFG_RED_LAMP_REF < DEM_NUM_OF_INDICATOR)
        {
            DemInternal_GetIndicatorStatus(DEM_CFG_RED_LAMP_REF, &IndicatorStatus);

            if(IndicatorStatus != DEM_INDICATOR_OFF)
            {
                /*SWS_Dem_00862 Red Stop lamp status should be ON*/
                *LampStatus |= DEM_J1939_RSL_ON;
            }

            if(IndicatorStatus == DEM_INDICATOR_SLOW_FLASH)
            {
                /*SWS_Dem_00864 Flash Red Stop lamp status should be SlowFlash, no need change*/
            }
            else if(IndicatorStatus == DEM_INDICATOR_FAST_FLASH)
            {
                /*SWS_Dem_00865 Flash Red Stop lamp status should be FastFlash.*/
                *LampStatus |= DEM_J1939_FRSL_FF;
            }
            else
            {
                /*SWS_Dem_00863 Flash Red Stop lamp status should be Unavailable/DoNotFlash.*/
                *LampStatus |= DEM_J1939_FRSL_UNAVAILABLE;
            }
        }
        else
        {
            /*Red Stop lamp is unavailable*/
            *LampStatus |= DEM_J1939_RSL_UNAVAILABLE;
            *LampStatus |= DEM_J1939_FRSL_UNAVAILABLE;
        }

        /*Returns a composite lamp status of Amber Warning lamp.*/
        if(DEM_CFG_AMBER_LAMP_REF < DEM_NUM_OF_INDICATOR)
        {
            DemInternal_GetIndicatorStatus(DEM_CFG_AMBER_LAMP_REF, &IndicatorStatus);

            if(IndicatorStatus != DEM_INDICATOR_OFF)
            {
                /*SWS_Dem_00866 Amber Warning lamp status should be ON*/
                *LampStatus |= DEM_J1939_AWL_ON;
            }

            if(IndicatorStatus == DEM_INDICATOR_SLOW_FLASH)
            {
                /*SWS_Dem_00868 Flash Amber Warning lamp status should be SlowFlash, no need change*/
            }
            else if(IndicatorStatus == DEM_INDICATOR_FAST_FLASH)
            {
                /*SWS_Dem_00869 Flash Amber Warning lamp status should be FastFlash.*/
                *LampStatus |= DEM_J1939_FAWL_FF;
            }
            else
            {
                /*SWS_Dem_00867 Flash Amber Warning lamp status should be Unavailable/DoNotFlash.*/
                *LampStatus |= DEM_J1939_FAWL_UNAVAILABLE;
            }
        }
        else
        {
            /*Amber Warning lamp is unavailable*/
            *LampStatus |= DEM_J1939_AWL_UNAVAILABLE;
            *LampStatus |= DEM_J1939_FAWL_UNAVAILABLE;
        }

        /*Returns a composite lamp status of Protect lamp.*/
        if(DEM_CFG_PROTECT_LAMP_REF < DEM_NUM_OF_INDICATOR)
        {
            DemInternal_GetIndicatorStatus(DEM_CFG_PROTECT_LAMP_REF, &IndicatorStatus);

            if(IndicatorStatus != DEM_INDICATOR_OFF)
            {
                /*SWS_Dem_00870 Protect lamp status should be ON*/
                *LampStatus |= DEM_J1939_PL_ON;
            }

            if(IndicatorStatus == DEM_INDICATOR_SLOW_FLASH)
            {
                /*SWS_Dem_00872 Flash Protect lamp status should be SlowFlash, no need change*/
            }
            else if(IndicatorStatus == DEM_INDICATOR_FAST_FLASH)
            {
                /*SWS_Dem_00873 Flash Protect lamp status should be FastFlash.*/
                *LampStatus |= DEM_J1939_FPL_FF;
            }
            else
            {
                /*SWS_Dem_00871 Flash Protect lamp status should be Unavailable/DoNotFlash.*/
                *LampStatus |= DEM_J1939_FPL_UNAVAILABLE;
            }
        }
        else
        {
            /*Protect lamp is unavailable*/
            *LampStatus |= DEM_J1939_PL_UNAVAILABLE;
            *LampStatus |= DEM_J1939_FPL_UNAVAILABLE;
        }
#else
        *LampStatus = DEM_J1939_LAMP_UNAVAILABLE;
#endif

        Dem_J1939DcmFilterInfo.FilteredValidFlag = TRUE;
    }
    return Result;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_J1939DcmGetNumberOfFilteredDTC
*
* Description: Gets the number of currently filtered DTCs set by the function
*              Dem_J1939DcmSetDTCFilter.
*
* Inputs: None
*
* Outputs: NumberOfFilteredDTC
*
* Return: Dem_ReturnGetNumberOfFilteredDTCType
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
/*SWS_Dem_00972*/
FUNC(Dem_ReturnGetNumberOfFilteredDTCType, DEM_CODE) Dem_J1939DcmGetNumberOfFilteredDTC
(
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) NumberOfFilteredDTC
)
{
    Dem_ReturnGetNumberOfFilteredDTCType Result = DEM_NUMBER_OK;

    if(Dem_State != DEM_NORMAL)
    {
        /*SWS_Dem_01112*//*SWS_Dem_00124*/
        DEM_DET_REPORT_ERROR(DEM_J1939DCMGETNUMBEROFFILTEREDDTC_APIID, DEM_E_UNINIT);
        Result = DEM_NUMBER_FAILED;
    }
    else if(NumberOfFilteredDTC == NULL_PTR)
    {
        DEM_DET_REPORT_ERROR(DEM_J1939DCMGETNUMBEROFFILTEREDDTC_APIID, DEM_E_PARAM_POINTER);
        Result = DEM_NUMBER_FAILED;
    }
    else if(Dem_J1939DcmFilterInfo.FilteredValidFlag != TRUE)
    {
        Result = DEM_NUMBER_FAILED;
    }
    else
    {
        /*SWS_Dem_00874*/
        *NumberOfFilteredDTC = Dem_J1939DcmFilterInfo.NumberOfFilteredDTC;
    }
    return Result;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_J1939DcmGetNextFilteredDTC
*
* Description: Gets the next filtered J1939 DTC.
*
* Inputs: None
*
* Outputs: J1939DTC,OccurenceCounter
*
* Return: Dem_ReturnGetNextFilteredElementType
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
/*SWS_Dem_00973*/
FUNC(Dem_ReturnGetNextFilteredElementType, DEM_CODE) Dem_J1939DcmGetNextFilteredDTC
(
    P2VAR(uint32, AUTOMATIC, DEM_APPL_DATA) J1939DTC,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) OccurenceCounter
)
{
    Dem_ReturnGetNextFilteredElementType Result = DEM_FILTERED_OK;
    uint16 DtcId;
    uint16 EventId;

    if((J1939DTC == NULL_PTR) || (OccurenceCounter == NULL_PTR))
    {
        DEM_DET_REPORT_ERROR(DEM_J1939DCMGETNEXTFILTEREDDTC_APIID, DEM_E_PARAM_POINTER);
        Result = DEM_FILTERED_BUFFER_TOO_SMALL;
    }
    else if(Dem_J1939DcmFilterInfo.FilteredValidFlag != TRUE)
    {
        Result = DEM_FILTERED_NO_MATCHING_ELEMENT;
    }
    else if(Dem_J1939DcmFilterInfo.NextFilteredDTCIndex >= Dem_J1939DcmFilterInfo.NumberOfFilteredDTC)
    {
        /*SWS_Dem_00875*/
        Dem_J1939DcmFilterInfo.FilteredValidFlag = FALSE;
        Dem_J1939DcmFilterInfo.NextFilteredDTCIndex = 0;
        Dem_J1939DcmFilterInfo.NumberOfFilteredDTC = 0;

        Result = DEM_FILTERED_NO_MATCHING_ELEMENT;
    }
    else
    {
#if(DEM_J1939_SUPPORT == STD_ON)
        /*SWS_Dem_00875*//*SWS_Dem_00877*/
        DtcId = Dem_J1939DcmFilterInfo.FilteredDTCIndexTable[Dem_J1939DcmFilterInfo.NextFilteredDTCIndex];
        *J1939DTC = DEM_CFG_DTC_J1939_VALUE(DtcId);
        for(EventId = 0; EventId < DEM_NUM_OF_EVENT; EventId++)
        {
            if(DEM_CFG_EVENT_DTCREF(EventId) == DtcId)
            {
                *OccurenceCounter = DEM_EVENT_OCCCTR(EventId);
                break;
            }
        }

        if(*OccurenceCounter > (uint8)0x7F)
        {
            *OccurenceCounter = (uint8)0x7F;
        }
        Dem_J1939DcmFilterInfo.NextFilteredDTCIndex++;
#else
        Result = DEM_FILTERED_NO_MATCHING_ELEMENT;
#endif
    }
    return Result;
}

#endif


#if(STD_OFF == DEM_CFG_J1939DM31_SUPPORT)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_J1939DcmFirstDTCwithLampStatus
*
* Description: The function sets the filter to the first applicable DTC for the
*              DM31 response for a specific node.
*
* Inputs: node
*
* Outputs: None
*
* Return: None
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
/*SWS_Dem_00974*/
FUNC(void, DEM_CODE) Dem_J1939DcmFirstDTCwithLampStatus
(
    uint8 node
)
{
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_J1939DcmGetNextDTCwithLampStatus
*
* Description: Gets the next filtered J1939 DTC for DM31 including current
*              LampStatus.
*
* Inputs: None
*
* Outputs: LampStatus,J1939DTC,OccurenceCounter
*
* Return: Dem_ReturnGetNextFilteredElementType
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
/*SWS_Dem_00975*/
FUNC(Dem_ReturnGetNextFilteredElementType, DEM_CODE) Dem_J1939DcmGetNextDTCwithLampStatus
(
    P2VAR(Dem_J1939DcmLampStatusType, AUTOMATIC, DEM_APPL_DATA) LampStatus,
    P2VAR(uint32, AUTOMATIC, DEM_APPL_DATA) J1939DTC,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) OccurenceCounter
)
{
    Dem_ReturnGetNextFilteredElementType Result = DEM_FILTERED_OK;

    return Result;
}
#endif
/*******************************************************************************
* DTC storage
*******************************************************************************/
#if(STD_ON == DEM_CFG_J1939CLEAR_DTC_SUPPORT)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_J1939DcmClearDTC
*
* Description: Clears active DTCs as well as previously active DTCs.
*
* Inputs: DTCTypeFilter,node
*
* Outputs: None
*
* Return: Dem_ReturnClearDTCType
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
/*SWS_Dem_00976*/
FUNC(Dem_ReturnClearDTCType, DEM_CODE) Dem_J1939DcmClearDTC
(
    Dem_J1939DcmSetClearFilterType DTCTypeFilter,
    uint8 node
)
{
    Dem_ReturnClearDTCType Result = DEM_CLEAR_OK;
    uint16 i;
    uint8 j;
    Dem_UdsStatusByteType DTCStatus;

    if(Dem_State != DEM_NORMAL)
    {
        DEM_DET_REPORT_ERROR(DEM_J1939DCMCLEARDTC_APIID, DEM_E_UNINIT);
        Result = DEM_CLEAR_FAILED;
    }
    else if(DTCTypeFilter > DEM_J1939DTC_CLEAR_PREVIOUSLY_ACTIVE)
    {
        DEM_DET_REPORT_ERROR(DEM_J1939DCMCLEARDTC_APIID, DEM_E_PARAM_DATA);
        Result = DEM_CLEAR_FAILED;
    }
    /*SWS_Dem_01042*/
    else if(Dem_ClearDTCState == DEM_IN_CLEAR_DTC_IDLE)
    {
#if(DEM_CFG_CLEARDTCBEHAIOR != DEM_CLRRESP_VOLATILE)
        Dem_ClearDTC_DTC = 0;
        Dem_ClearDTC_DTCFormat = DEM_DTC_FORMAT_J1939;
        Dem_ClearDTC_DTCOrigin = DEM_DTC_ORIGIN_PRIMARY_MEMORY;
#endif
        /*SWS_Dem_00878*/
        for(i = 0; i < DEM_NUM_OF_DTC; i++)
        {
            if(DEM_CFG_DTC_J1939NODE_REF(i) != NULL_PTR)
            {
                for(j = 0; j < DEM_CFG_DTC_J1939NODE_NUM(i); j++)
                {
                    if((DEM_CFG_DTC_J1939NODE_ARRAY(i)[j]) == node)
                    {
                        DTCStatus = DEM_DTC_STATUS(i);
                        if(DTCTypeFilter == DEM_J1939DTC_CLEAR_ALL)
                        {
                            /*SWS_Dem_00879*/
                            /*Clear RAM info of one DTC*/
                            DemInternal_ClearOneDTC(i);
                        }
                        else if((!DEM_TEST_UDS_STATUS_TF(DTCStatus)) && (DEM_TEST_UDS_STATUS_CDTC(DTCStatus)))
                        {
                            /*SWS_Dem_00879*/
                            /*Clear RAM info of one DTC*/
                            DemInternal_ClearOneDTC(i);
                        }
                        else
                        {
                            /*do nothing*/
                        }
                        break;
                    }
                }
            }
        }

#if(DEM_CFG_CLEARDTCBEHAIOR == DEM_CLRRESP_VOLATILE)
        /*SWS_Dem_00570*/
        Result = DEM_CLEAR_OK;
#else
        Dem_ClearDTCState = DEM_IN_CLEAR_EVENT_MEM;
        Result = DEM_CLEAR_PENDING;
#endif/*(DEM_CFG_CLEARDTCBEHAIOR == DEM_CLRRESP_VOLATILE)*/

    }
#if(DEM_CFG_CLEARDTCBEHAIOR != DEM_CLRRESP_VOLATILE)
    else if((Dem_ClearDTC_DTC != 0) || (Dem_ClearDTC_DTCFormat != DEM_DTC_FORMAT_J1939) \
        || (Dem_ClearDTC_DTCOrigin != DEM_DTC_ORIGIN_PRIMARY_MEMORY))
    {
        Result = DEM_CLEAR_BUSY;
    }
#endif/*(DEM_CFG_CLEARDTCBEHAIOR == DEM_CLRRESP_VOLATILE)*/
    else
    {
        if(Dem_ClearDTCState == DEM_IN_CLEAR_DTC_OK)
        {
            Dem_ClearDTCState = DEM_IN_CLEAR_DTC_IDLE;
            Result = DEM_CLEAR_OK;
        }
        else if(Dem_ClearDTCState == DEM_IN_CLEAR_DTC_ERR)
        {
            Dem_ClearDTCState = DEM_IN_CLEAR_DTC_IDLE;
            Result = DEM_CLEAR_MEMORY_ERROR;
        }
        else
        {
            Result = DEM_CLEAR_PENDING;
        }
    }
    return Result;
}
#endif

#if((STD_ON == DEM_CFG_J1939EX_FF_SUPPORT)||(STD_ON == DEM_CFG_J1939_FF_SUPPORT))
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_J1939DcmSetFreezeFrameFilter
*
* Description: The function sets the FreezeFrame filter for a specific node.
*
* Inputs: FreezeFrameKind,node
*
* Outputs: None
*
* Return: Dem_ReturnSetFilterType
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
/*SWS_Dem_00977*/
FUNC(Dem_ReturnSetFilterType, DEM_CODE) Dem_J1939DcmSetFreezeFrameFilter
(
    Dem_J1939DcmSetFreezeFrameFilterType FreezeFrameKind,
    uint8 node
)
{
    Dem_ReturnSetFilterType Result = DEM_WRONG_FILTER;
    if(Dem_State != DEM_NORMAL)
    {
        /*SWS_Dem_01112*//*SWS_Dem_00124*/
        DEM_DET_REPORT_ERROR(DEM_J1939DCMSETFREEZEFRAMEFILTER_APIID, DEM_E_UNINIT);
        
    }
    else if((FreezeFrameKind != DEM_J1939DCM_FREEZEFRAME)\
        && (FreezeFrameKind != DEM_J1939DCM_EXPANDED_FREEZEFRAME))
    {
        DEM_DET_REPORT_ERROR(DEM_J1939DCMSETFREEZEFRAMEFILTER_APIID, DEM_E_PARAM_DATA);
        
    }
    else
    {
        /*SWS_Dem_00899*/       
        Dem_J1939DcmFilterInfo.node = node;
        Dem_J1939DcmFilterInfo.NumberOfFilteredDTC = DEM_DATA_CLEAR;
        Dem_J1939DcmFilterInfo.NextFilteredDTCIndex = DEM_DATA_CLEAR;
        Dem_J1939DcmFilterInfo.FreezeFrameKind = FreezeFrameKind;
        Dem_J1939DcmFilterInfo.FilteredValidFlag = TRUE;
        Result = DEM_FILTER_ACCEPTED;

    }
    return Result;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_J1939DcmGetNextFreezeFrame
*
* Description: Gets next freeze frame data. The function stores the data in
*              the provided DestBuffer.
*
* Inputs: DestBuffer,BufSize
*
* Outputs: J1939DTC,OccurenceCounter,DestBuffer,BufSize
*
* Return: Dem_ReturnGetNextFilteredElementType
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
/*SWS_Dem_00978*/
FUNC(Dem_ReturnGetNextFilteredElementType, DEM_CODE) Dem_J1939DcmGetNextFreezeFrame
(
    P2VAR(uint32, AUTOMATIC, DEM_APPL_DATA) J1939DTC,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) OccurenceCounter,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DestBuffer,
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) BufSize
)
{
    uint16 i;
    uint8 j;
    uint16 FFDataSize = 0;
    Dem_ReturnGetNextFilteredElementType Result = DEM_FILTERED_NO_MATCHING_ELEMENT;
    Std_ReturnType ret = E_NOT_OK;
    if(Dem_State != DEM_NORMAL)
    {
        /*SWS_Dem_01112*//*SWS_Dem_00124*/
        DEM_DET_REPORT_ERROR(DEM_J1939DCMGETNEXTFREEZEFRAME_APIID, DEM_E_UNINIT);
    }
    else if((J1939DTC == NULL_PTR)\
        || (OccurenceCounter == NULL_PTR)\
        || (DestBuffer == NULL_PTR)\
        || (BufSize == NULL_PTR))
    {
        DEM_DET_REPORT_ERROR(DEM_J1939DCMGETNEXTFREEZEFRAME_APIID, DEM_E_PARAM_DATA);
    }
    else if(Dem_J1939DcmFilterInfo.FilteredValidFlag == FALSE)
    {
        DEM_DET_REPORT_ERROR(DEM_J1939DCMGETNEXTFREEZEFRAME_APIID, DEM_E_PARAM_DATA);
    }
    else
    {
        for(i = Dem_J1939DcmFilterInfo.NextFilteredDTCIndex; i < DEM_NUM_OF_DTC; i++)
        {

            if((DEM_CFG_DTC_OBDDTCREF(i) != NULL_PTR) && (DEM_CFG_DTC_J1939_VALUE(i) != (uint32)0) && (DEM_CFG_DTC_J1939NODE_REF(i) != NULL_PTR))
            {
                for(j = 0; j < DEM_CFG_DTC_J1939NODE_NUM(i); j++)
                {
                    if((DEM_CFG_DTC_J1939NODE_ARRAY(i)[j]) == Dem_J1939DcmFilterInfo.node)
                    {
                        if((Dem_J1939DcmFilterInfo.FreezeFrameKind ==  DEM_J1939DCM_FREEZEFRAME) \
                                && (DEM_CFG_J1939DTC_FFRECNUMCLASSREF(i) != NULL_PTR)
                                && (DEM_DTC_DATAENTRYREF(i) != DEM_DATA_INVALID_U16))
                        {
                            ret = DemInternal_J1939GetSizeOfFreezeFrame(i, &FFDataSize, DEM_J1939DCM_FREEZEFRAME);
                            if((*BufSize >= FFDataSize) && (ret == E_OK))
                            {
                                *BufSize = FFDataSize;
                                DemInternal_J1939GetDataOfFreezeFrame(i, DestBuffer, DEM_J1939DCM_FREEZEFRAME);
                                *J1939DTC = DEM_CFG_DTC_J1939_VALUE(i);  
                                DemInternal_J1939GetOccurrenceCounter(i, OccurenceCounter);
                                Dem_J1939DcmFilterInfo.NextFilteredDTCIndex = (i+1);
                                Result = E_OK;
                                break;     
                            }
                            else if((*BufSize < FFDataSize) && (ret == E_OK))
                            {
                                Result = DEM_FILTERED_BUFFER_TOO_SMALL;
                                break;
                            }
                            else
                            {
                                Result = DEM_FILTERED_NO_MATCHING_ELEMENT;
                                break;
                            } 
                        }
                        else if((Dem_J1939DcmFilterInfo.FreezeFrameKind == DEM_J1939DCM_EXPANDED_FREEZEFRAME) \
                                && (DEM_CFG_1939DTC_EXPFFRECNUMCLASSREF(i) != NULL_PTR) \
                                && (DEM_DTC_DATAENTRYREF(i) != DEM_DATA_INVALID_U16))
                        {
                            ret = DemInternal_J1939GetSizeOfFreezeFrame(i, &FFDataSize, DEM_J1939DCM_EXPANDED_FREEZEFRAME);
                            if((*BufSize >= FFDataSize) && (ret == E_OK))
                            {
                                *BufSize = FFDataSize;
                                DemInternal_J1939GetDataOfFreezeFrame(i,DestBuffer, DEM_J1939DCM_EXPANDED_FREEZEFRAME);
                                *J1939DTC = DEM_CFG_DTC_J1939_VALUE(i);  
                                DemInternal_J1939GetOccurrenceCounter(i, OccurenceCounter);
                                Dem_J1939DcmFilterInfo.NextFilteredDTCIndex = (i+1);
                                Result = E_OK;
                                break;     
                            }
                            else if((*BufSize < FFDataSize) && (ret == E_OK))
                            {
                                Result = DEM_FILTERED_BUFFER_TOO_SMALL;
                                break;
                            }
                            else
                            {
                                Result = DEM_FILTERED_NO_MATCHING_ELEMENT;
                                break;
                            } 
                        }
                        else
                        {
                            /*do nothing*/
                        }
                    }
                }
                  
            }
            
            if(Result == E_OK)
            {
                break;
            }
            else if(Result == DEM_FILTERED_BUFFER_TOO_SMALL) 
            {
                break;
            }
            else
            {

            }
        }
        if(i >= DEM_NUM_OF_DTC)
        {
            Dem_J1939DcmFilterInfo.NextFilteredDTCIndex = DEM_DATA_CLEAR;
            Result = DEM_FILTERED_NO_MATCHING_ELEMENT;
        }
    }
    return Result;
    
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DemInternal_J1939GetSizeOfFreezeFrame
*
* Description:
*
* Inputs:
*
* Outputs:
*
* Return:
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(Std_ReturnType, DEM_CODE) DemInternal_J1939GetSizeOfFreezeFrame
(
    uint16 DtcId,
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) SizeOfFreezeFrame,
    Dem_J1939DcmSetFreezeFrameFilterType FreezeFrameKind
)
{
    Std_ReturnType Result = E_OK;
#if((DEM_MAX_J1939FFSIZE_OF_DTC > 0) || (DEM_MAX_J1939EXPFFSIZE_OF_DTC > 0))
    uint8 i;
    uint16 SPNIndex;
    uint16 DataIdx;
    uint8 DataSize;
    uint8 *DataBufferPtr;
    uint16 FFDataOffset = 0;

    *SizeOfFreezeFrame = 0U;
#if(DEM_MAX_J1939FFSIZE_OF_DTC > 0)
    if(FreezeFrameKind == DEM_J1939DCM_FREEZEFRAME)
    {
        DataBufferPtr = DEM_PRIMARY_J1939DTC_FFDATA_PTR(DEM_DTC_DATAENTRYREF(DtcId));
    }
#endif
#if(DEM_MAX_J1939EXPFFSIZE_OF_DTC > 0)
    if(FreezeFrameKind == DEM_J1939DCM_EXPANDED_FREEZEFRAME)
    {
        DataBufferPtr = DEM_PRIMARY_J1939DTC_EXPFFDATA_PTR(DEM_DTC_DATAENTRYREF(DtcId));
    }
#endif
    
    for(i = 0U; i < DEM_CFG_J1939DTC_NUM_OF_FFSPNC(DtcId); i++)
    {   
        SPNIndex = DEM_CFG_J1939DTC_FFSPNC_ARRAY(DtcId)[i];
        DataIdx = DEM_CFG_DATAARRAY_OF_FFSPN(SPNIndex);
        if(DEM_CFG_DATA_IN_DATA(DataIdx) != NULL_PTR)
        {
            DataSize = DEM_CFG_DATA_IN_DATA_SIZE(DataIdx);
            /*SWS_Dem_00817*/
            *SizeOfFreezeFrame += (uint16)DataSize;
        }

        if(DEM_CFG_DATA_CS_DATA(DataIdx) != NULL_PTR)
        {
            DataSize = DEM_CFG_DATA_CS_DATA_SIZE(DataIdx);
            *SizeOfFreezeFrame += (uint16)DataSize;
        }
        FFDataOffset += (*SizeOfFreezeFrame);     
    }

#else
    Result = E_NOT_OK;
#endif

    return Result;
}


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name:DemInternal_J1939GetOccurrenceCounter
*
* Description:
*
* Inputs:
*
* Outputs:
*
* Return:
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, DEM_CODE) DemInternal_J1939GetOccurrenceCounter
(
    uint16 DtcId,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) OccurenceCounter
)
{
    Dem_EventIdType EventId;
    for(EventId = 0; EventId < DEM_NUM_OF_EVENT; EventId++)
    {
        if(DEM_CFG_EVENT_DTCREF(EventId) == DtcId)
        {
            *OccurenceCounter = DEM_EVENT_OCCCTR(EventId);
            break;
        }
    }
    if(*OccurenceCounter >= (uint8)0x7F)
    {
        *OccurenceCounter = (uint8)0x7E;
    }
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name:DemInternal_J1939GetDataOfFreezeFrame
*
* Description:
*
* Inputs:
*
* Outputs:
*
* Return:
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, DEM_CODE) DemInternal_J1939GetDataOfFreezeFrame
(
    uint16 DtcId,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DestBuffer,
    Dem_J1939DcmSetFreezeFrameFilterType FreezeFrameKind
)
{
#if((DEM_MAX_J1939FFSIZE_OF_DTC > 0) || (DEM_MAX_J1939EXPFFSIZE_OF_DTC > 0))
    uint8 i;
    uint8 DataIdx;
    uint8 DataSize;
    uint8 *SrcBufferPtr;
    uint16 SPNIndex;
#if(DEM_MAX_J1939FFSIZE_OF_DTC > 0)
    if(FreezeFrameKind == DEM_J1939DCM_FREEZEFRAME)
    {
        SrcBufferPtr = DEM_PRIMARY_J1939DTC_FFDATA_PTR(DEM_DTC_DATAENTRYREF(DtcId));
    }
#endif
#if(DEM_MAX_J1939EXPFFSIZE_OF_DTC > 0)
    if(FreezeFrameKind == DEM_J1939DCM_EXPANDED_FREEZEFRAME)
    {
        SrcBufferPtr = DEM_PRIMARY_J1939DTC_EXPFFDATA_PTR(DEM_DTC_DATAENTRYREF(DtcId));
    }
#endif
    for(i = 0U; i < DEM_CFG_J1939DTC_NUM_OF_FFSPNC(DtcId); i++)
    {
        SPNIndex = DEM_CFG_J1939DTC_FFSPNC_ARRAY(DtcId)[i];
        DataIdx = DEM_CFG_DATAARRAY_OF_FFSPN(SPNIndex);
        if(DEM_CFG_DATA_IN_DATA(DataIdx) != NULL_PTR)
        {
            DataSize = DEM_CFG_DATA_IN_DATA_SIZE(DataIdx);
            Bsw_MemCpy(DestBuffer, SrcBufferPtr, DataSize);
            DestBuffer += DataSize;
            SrcBufferPtr += DataSize;
        }
        if(DEM_CFG_DATA_CS_DATA(DataIdx) != NULL_PTR)
        {
            DataSize = DEM_CFG_DATA_CS_DATA_SIZE(DataIdx);
            Bsw_MemCpy(DestBuffer, SrcBufferPtr, DataSize);
            DestBuffer += DataSize;
            SrcBufferPtr += DataSize;
        }    
    }
#endif
}

#endif

#if(STD_ON == DEM_CFG_J1939EX_FF_SUPPORT)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_J1939DcmGetNextSPNInFreezeFrame
*
* Description: Gets next SPN.
*
* Inputs: None
*
* Outputs: SPNSupported,SPNDataLength
*
* Return: Dem_ReturnGetNextFilteredElementType
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
/*SWS_Dem_00979*/
FUNC(Dem_ReturnGetNextFilteredElementType, DEM_CODE) Dem_J1939DcmGetNextSPNInFreezeFrame
(
    P2VAR(uint32, AUTOMATIC, DEM_APPL_DATA) SPNSupported,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) SPNDataLength
)
{
}
#endif
/*******************************************************************************
* Reporting
*******************************************************************************/
#if(STD_ON == DEM_CFG_J1939_RATIO_SUPPORT)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_J1939DcmSetRatioFilter
*
* Description: The function sets the Ratio filter for a specific node and
*              returns the corresponding Ignition Cycle Counter and General
*              Denominator.
*
* Inputs: node
*
* Outputs: IgnitionCycleCounter,OBDMonitoringConditionsEncountered
*
* Return: Dem_ReturnSetFilterType
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
/*SWS_Dem_00980*/
FUNC(Dem_ReturnSetFilterType, DEM_CODE) Dem_J1939DcmSetRatioFilter
(
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) IgnitionCycleCounter,
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) OBDMonitoringConditionsEncountered,
    uint8 node
)
{
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_J1939DcmGetNextFilteredRatio
*
* Description: Gets the next filtered Ratio.
*
* Inputs: None
*
* Outputs: SPN,Numerator,Denominator
*
* Return: Dem_ReturnGetNextFilteredElementType
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
/*SWS_Dem_00981*/
FUNC(Dem_ReturnGetNextFilteredElementType, DEM_CODE) Dem_J1939DcmGetNextFilteredRatio
(
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) SPN,
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) Numerator,
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) Denominator
)
{
}
#endif

#if(STD_ON == DEM_CFG_J1939READINESS_1_SUPPORT)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_J1939DcmReadDiagnosticReadiness1
*
* Description: Service to report the value of Diagnostic Readiness 1
*              (DM05) computed by the Dem.
*
* Inputs: node
*
* Outputs: DataValue
*
* Return: Std_ReturnType
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
/*SWS_Dem_00982*/
FUNC(Std_ReturnType, DEM_CODE) Dem_J1939DcmReadDiagnosticReadiness1
(
    P2VAR(Dem_J1939DcmDiagnosticReadiness1Type, AUTOMATIC, DEM_APPL_DATA) DataValue,
    uint8 node
)
{
}
#endif

#if(STD_ON == DEM_CFG_J1939READINESS_2_SUPPORT)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_J1939DcmReadDiagnosticReadiness2
*
* Description: Service to report the value of Diagnostic Readiness 2
*              (DM21) computed by the Dem.
*
* Inputs: node
*
* Outputs: DataValue
*
* Return: Std_ReturnType
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
/*SWS_Dem_00983*/
FUNC(Std_ReturnType, DEM_CODE) Dem_J1939DcmReadDiagnosticReadiness2
(
    P2VAR(Dem_J1939DcmDiagnosticReadiness2Type, AUTOMATIC, DEM_APPL_DATA) DataValue,
    uint8 node
)
{
}
#endif

#if(STD_ON == DEM_CFG_J1939READINESS_3_SUPPORT)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_J1939DcmReadDiagnosticReadiness3
*
* Description: Service to report the value of Diagnostic Readiness 3
*              (DM26) computed by the Dem.
*
* Inputs: node
*
* Outputs: DataValue
*
* Return: Std_ReturnType
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
/*SWS_Dem_00770*/
FUNC(Std_ReturnType, DEM_CODE) Dem_J1939DcmReadDiagnosticReadiness3
(
    P2VAR(Dem_J1939DcmDiagnosticReadiness3Type, AUTOMATIC, DEM_APPL_DATA) DataValue,
    uint8 node
)
{
}
#endif

#define DEM_STOP_SEC_CODE
#include "MemMap.h"



