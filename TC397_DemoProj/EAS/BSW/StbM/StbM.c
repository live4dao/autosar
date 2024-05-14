/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
*   File Name       : StbM.c
********************************************************************************
*   Project/Product : AUTOSAR 4.2
*   Title           : StbM.c
*   Author          : HiRain
********************************************************************************
*   Description     : Source of AUTOSAR Basic Software module StbM.
********************************************************************************
*   Limitations     : None
*
********************************************************************************
*
********************************************************************************
*   Revision History:
*
*   Version     Date          Initials        CR#        Descriptions
*   ---------   ----------    --------------  --------   ---------------
*   01.00.00    18/11/2020    Feixiang.Dong   N/A        Beta
*   01.00.01    18/06/2021    Feixiang.Dong   N/A        EAS422_StbM_20210618_01
*   01.00.02    17/12/2021    Feixiang.Dong   N/A        EAS422_StbM_20211217_01
*   01.00.03    11/04/2022    Ziyi.Zhao       N/A        EAS422_StbM_20220411_01
*   01.00.04    15/04/2022    Ziyi.Zhao       N/A        EAS422_StbM_20220415_01
*   01.00.05    07/05/2022    Ziyi.Zhao       N/A        EAS422_StbM_20220507_01
*   01.00.06    20/06/2022    Ziyi.Zhao       N/A        EAS422_StbM_20220620_01
*   01.00.07    30/06/2022    Ziyi.Zhao       N/A        EAS422_StbM_20220630_01
*   01.01.00    15/08/2023    Yaping.Jin      N/A        EAS422_StbM_20230815_01
********************************************************************************
* END_FILE_HDR*/


/*******************************************************************************
*   Includes
*******************************************************************************/
#include "StbM.h"
#if(STBM_ETH_GLOBALTIME_USED == STD_ON)
#include "EthTSyn.h"
#endif
#if(STD_ON == STBM_DEV_ERROR_DETECT)
#include "Det.h"
#endif
#include "Rte_StbM.h"
#include "SchM_StbM.h"
#include "StbM_Lcfg.h"
#if(StbM_OS_ENABLED == STD_ON)
#include "Os.h"
#endif
#if((STBM_USERDEFCNT_USED == STD_ON)||(STBM_RAW_USER_COUNTER_SUPPORT == STD_ON))
#include "StbM_Callout.h"
#endif


/*******************************************************************************
*   Version Check
*******************************************************************************/
#if(STD_ON == STBM_VERSION_CHECK)
/* check Version with other import module */
/* check Version with cfg file */
#if(STBM_CONFIG_VARIANTS != STD_CONFIG_VARIANTS_PRECOMPILE)
#error "The StbM module only supports Pre-Compile configuration."
#endif

/* check Version with cfg file */
#if((STBM_AR_RELEASE_MAJOR_VERSION != STBM_AR_RELEASE_MAJOR_VERSION_CFG) || \
    (STBM_AR_RELEASE_MINOR_VERSION != STBM_AR_RELEASE_MINOR_VERSION_CFG))
#error "AutoSar Version Numbers of StbM and its cfg file are different"
#endif

#if((STBM_SW_MAJOR_VERSION != STBM_SW_MAJOR_VERSION_CFG) || \
    (STBM_SW_MINOR_VERSION != STBM_SW_MINOR_VERSION_CFG))
#error "SW Version Numbers of StbM and its cfg file are different"
#endif

#endif/*#if(STD_ON == STBM_VERSION_CHECK)*/


/*******************************************************************************
*   Macros
*******************************************************************************/
#if(STD_ON == STBM_DEV_ERROR_DETECT)
#define  STBM_DET_REPORT_ERROR(ApiId, errcode)  \
    DET_REPORT_ERROR(STBM_MODULE_ID, STBM_INSTANCE_ID, ((uint8)ApiId), ((uint8)errcode))
#else
#define  STBM_DET_REPORT_ERROR(ApiId, errcode)
#endif

#define STBM_TIME_NANOSECONDS_MAX                ((uint32)1000000000)/*uint:ns, hex value 0x3B9A CA00*/
#define STBM_TIME_SECONDS_MAX                    (0xFFFFFFFF)/*uint:s*/
#define STBM_TIME_SECONDS_SHIFT                  ((uint64)32)

#define STBM_BIT_SET                             ((unsigned int)1)
#define STBM_BIT_CLR                             ((unsigned int)0)

#define STBM_USERDATA_MAX_LENGTH                 ((uint8)3)
#define STBM_OFFSET_TIMEBASE_START_ID            ((StbM_SynchronizedTimeBaseType)16)
#define STBM_TIME_BASE_MAX_ID                    ((StbM_SynchronizedTimeBaseType)31)

#define STBM_IS_INITIALIZED()                    (StbM_InitState == STD_INITIALIZED)
#define STBM_IS_TIMEBASE_ID(id)                  (id < STBM_OFFSET_TIMEBASE_START_ID)
#define STBM_IS_OFFSETTIME_ID(id)                \
    ((id <= STBM_TIME_BASE_MAX_ID) && (id >= STBM_OFFSET_TIMEBASE_START_ID))
#define STBM_IS_ID_VALID(id)                     ((STBM_ID_TO_INDEX(id) < STBM_NUM_OF_TIMEBASE) \
    && (STBM_CFG_TB_ID((STBM_ID_TO_INDEX(id))) == id))

/*Time Base Context*/
#define STBM_TIME_STAMP(idx)                     (StbM_GlobalTimeStamp[idx])
#define STBM_TIME_SECONDSHI(idx)                 (StbM_GlobalTimeStamp[idx].secondsHi)
#define STBM_TIME_SECONDS(idx)                   (StbM_GlobalTimeStamp[idx].seconds)
#define STBM_TIME_NANOSECONDS(idx)               (StbM_GlobalTimeStamp[idx].nanoseconds)
#define STBM_STATUS(idx)                         (StbM_GlobalTimeStamp[idx].timeBaseStatus)
#define STBM_STATUS_TIMEOUT(idx)                 (StbM_GlobalTimeStamp[idx].timeBaseStatus.TIMEOUT)
#define STBM_STATUS_TIMELEAP(idx)                (StbM_GlobalTimeStamp[idx].timeBaseStatus.TIMELEAP)
#define STBM_STATUS_SYNC_TO_GATEWAY(idx)         (StbM_GlobalTimeStamp[idx].timeBaseStatus.SYNC_TO_GATEWAY)
#define STBM_STATUS_GLOBAL_TIME_BASE(idx)        (StbM_GlobalTimeStamp[idx].timeBaseStatus.GLOBAL_TIME_BASE)

#define STBM_LAST_BUSSET_STAMP(idx)              (StbM_LastBusSetTimeStamp[idx])

#define STBM_TIME_PRE_COUNTER(idx)               (StbM_PreviousOsCounter[idx])

#define STBM_USERDATA(idx)                       (StbM_UserData[idx])


#if(STBM_NUM_OF_TRIGGEREDCUSTOMER > 0)
#define STBM_TRIGGERED_TIME(i)                   (StbM_TriggeredTime[i])
#endif



/*Time Base Identifier translate to Index*/
#define STBM_ID_TO_INDEX(id)                     (StbM_TimeBaseIdMap[id])

/*Time Base Info*/
#define STBM_CFG_TB_ID(idx)                      (StbM_SynchronizedTimeBaseInfo[idx].StbMSynchronizedTimeBaseIdentifier)
#define STBM_CFG_TB_IS_MASTER(idx)               (StbM_SynchronizedTimeBaseInfo[idx].StbMIsSystemWideGlobalTimeMaster)
#if(STBM_NONVOLATILE_SUPPORT == STD_ON)
#define STBM_CFG_TB_NV(idx)                      (StbM_SynchronizedTimeBaseInfo[idx].StbMStoreTimebaseNonVolatile)
#endif
#define STBM_CFG_TB_LOSS_SECONDS_THRESHOLD(idx)          (StbM_SynchronizedTimeBaseInfo[idx].StbMSyncLossThreshold->Seconds)
#define STBM_CFG_TB_LOSS_NASECONDS_THRESHOLD(idx)          (StbM_SynchronizedTimeBaseInfo[idx].StbMSyncLossThreshold->Nanoseconds)
#define STBM_CFG_TB_LOSS_SECONDS_TIMEOUT(idx)            (StbM_SynchronizedTimeBaseInfo[idx].StbMSyncLossTimeout->Seconds)
#define STBM_CFG_TB_LOSS_NASECONDS_TIMEOUT(idx)            (StbM_SynchronizedTimeBaseInfo[idx].StbMSyncLossTimeout->Nanoseconds)




#if(STBM_ETH_GLOBALTIME_USED == STD_ON)
#define STBM_CFG_TB_ETH_DOMAIN_REF(idx)          (StbM_SynchronizedTimeBaseInfo[idx].StbMEthGlobalTimeDomainRef)
#endif
#define STBM_CFG_TB_LOCAL_TIME_REF(idx)          (StbM_SynchronizedTimeBaseInfo[idx].StbMLocalTimeRef)
#define STBM_CFG_TB_COUNTER_ID(idx)              (StbM_SynchronizedTimeBaseInfo[idx].StbMLocalTimeRef->CounterId)
#define STBM_CFG_TB_COUNTER_MAX_VALUE(idx)       \
    (StbM_SynchronizedTimeBaseInfo[idx].StbMLocalTimeRef->CounterMaxAllowedValue)
#define STBM_CFG_TB_COUNTER_FACTOR(idx)          \
    (StbM_SynchronizedTimeBaseInfo[idx].StbMLocalTimeRef->NanosecondsPerTick)
#define STBM_CFG_LOCALTIME_HARDWARE(idx)          \
    (StbM_SynchronizedTimeBaseInfo[idx].StbMLocalTimeRef->StbMLocalTimeHardware)
#if(STBM_OFFSETTIMEBASE_USED == STD_ON)
#define STBM_CFG_TB_OFFSET_TB_REF(idx)           (StbM_SynchronizedTimeBaseInfo[idx].StbMOffsetTimeBase)
#endif

/*Triggered Customer*/
#if(STBM_NUM_OF_TRIGGEREDCUSTOMER > 0)
#define STBM_CFG_TRIGGER_PERIOD(i)               \
    (((StbM_TriggeredCustomer[i].StbMTriggeredCustomerPeriod)/1000U)/STBM_MAIN_FUNCTION_PERIOD)
#define STBM_CFG_TRIGGER_TABLE(i)                (StbM_TriggeredCustomer[i].StbMOSScheduleTableRef)
#define STBM_CFG_TRIGGER_TABLE_DURATION(i)       (StbM_TriggeredCustomer[i].StbMOSScheduleTableDuration)
#define STBM_CFG_TRIGGER_FACTOR(i)               (StbM_TriggeredCustomer[i].StbMOSScheduleTableNanosecondsPerTick)
#define STBM_CFG_TRIGGER_TB_REF(i)               (StbM_TriggeredCustomer[i].StbMSynchronizedTimeBaseRef)
#endif

/*******************************************************************************
*   Gloable Data definitions
*******************************************************************************/
#define STBM_START_SEC_VAR_INIT_8
#include "MemMap.h"

/*SWS_StbM_00100*/
STATIC VAR(Std_InitStateType, STBM_VAR) StbM_InitState = STD_UNINITIALIZED;

#define STBM_STOP_SEC_VAR_INIT_8
#include "MemMap.h"

#define STBM_START_SEC_VAR_NOINIT_32
#include "MemMap.h"
#if(STBM_NUM_OF_TRIGGEREDCUSTOMER > 0)
STATIC VAR(uint32, STBM_VAR) StbM_TriggeredTime[STBM_NUM_OF_TRIGGEREDCUSTOMER];
#endif
#define STBM_STOP_SEC_VAR_NOINIT_32
#include "MemMap.h"

#define STBM_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"

#if(STBM_CONFIG_VARIANTS == STD_CONFIG_VARIANTS_POSTBUILD)
STATIC P2CONST(StbM_ConfigType, STBM_VAR_NOINIT, STBM_CONST) StbM_ConfigSet;
#endif

/*For Base Time Id 0~15: means global base time;
  For Base Time Id 16~31: means offset time;*/
STATIC VAR(StbM_TimeStampType, STBM_VAR) StbM_GlobalTimeStamp[STBM_NUM_OF_TIMEBASE];
/*StbM_LossTimeStamp is used to record the time of last invocation of StbM_BusSetGlobalTime().*/
STATIC VAR(StbM_TimeStampType, STBM_VAR) StbM_LastBusSetTimeStamp[STBM_NUM_OF_TIMEBASE];

STATIC VAR(TickType, STBM_VAR) StbM_PreviousOsCounter[STBM_NUM_OF_TIMEBASE];

STATIC VAR(StbM_UserDataType, STBM_VAR) StbM_UserData[STBM_NUM_OF_TIMEBASE];


#define STBM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"

#define STBM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

STATIC CONST(StbM_TimeStampType, STBM_CONST) StbMTimeStampInitValue =
{
    {0U, 0U, 0U, 0U, 0U},
    0U,
    0U,
    0U
};

STATIC CONST(StbM_UserDataType, STBM_CONST) StbMUserDataInitValue =
{
    0U, 0U, 0U, 0U
};

#define STBM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

/*******************************************************************************
*   Local Functions define
*******************************************************************************/
#define STBM_START_SEC_CODE
#include "MemMap.h"

STATIC FUNC(Std_ReturnType, STBM_CODE) StbM_S_UpdatePreTicks
(
    StbM_SynchronizedTimeBaseType TbIdx
);

STATIC FUNC(Std_ReturnType, STBM_CODE) StbM_S_GetBaseTime
(
    StbM_SynchronizedTimeBaseType timeBaseId,
    P2VAR(StbM_TimeStampType, AUTOMATIC, STBM_APPL_DATA) timeStampPtr
);

#if(STBM_OFFSETTIMEBASE_USED == STD_ON)
STATIC FUNC(void, STBM_CODE) StbM_S_AddOffsetTime
(
    StbM_SynchronizedTimeBaseType timeBaseId,
    P2VAR(StbM_TimeStampType, AUTOMATIC, STBM_APPL_DATA) timeStampPtr
);
#endif

STATIC FUNC(Std_ReturnType, STBM_CODE) StbM_S_SetBaseTime
(
    StbM_SynchronizedTimeBaseType timeBaseId,
    P2CONST(StbM_TimeStampType, STBM_APPL_CONST, AUTOMATIC) timeStampPtr
);

STATIC FUNC(void, STBM_CODE) StbM_S_CopyTimeStamp
(
    P2VAR(StbM_TimeStampType, AUTOMATIC, STBM_APPL_DATA) DestPtr,
    P2CONST(StbM_TimeStampType, STBM_APPL_CONST, AUTOMATIC) SrcPtr
);

STATIC FUNC(void, STBM_CODE) StbM_S_CopyUserData
(
    P2VAR(StbM_UserDataType, AUTOMATIC, STBM_APPL_DATA) DestPtr,
    P2CONST(StbM_UserDataType, STBM_APPL_CONST, AUTOMATIC) SrcPtr
);

STATIC FUNC(Std_ReturnType, STBM_CODE) StbM_S_CalculateTimeStampDiff
(
    P2CONST(StbM_TimeStampType, STBM_APPL_CONST, AUTOMATIC) MinuendtimeStampPtr,
    P2VAR(StbM_TimeStampType, AUTOMATIC, STBM_APPL_DATA) SubtrahendtimeStampPtr
);

STATIC FUNC(boolean, STBM_CODE) StbM_S_CheckLossThreshold
(
    StbM_SynchronizedTimeBaseType timeBaseId,
    P2CONST(StbM_TimeStampType, STBM_APPL_CONST, AUTOMATIC) PretimeStampPtr,
    P2CONST(StbM_TimeStampType, STBM_APPL_CONST, AUTOMATIC) CurtimeStampPtr
);

STATIC FUNC(boolean, STBM_CODE) StbM_S_CheckLossTimeout
(
    StbM_SynchronizedTimeBaseType timeBaseId,
    P2CONST(StbM_TimeStampType, STBM_APPL_CONST, AUTOMATIC) PretimeStampPtr,
    P2CONST(StbM_TimeStampType, STBM_APPL_CONST, AUTOMATIC) CurtimeStampPtr
);
#if(STBM_NUM_OF_TRIGGEREDCUSTOMER > 0)
STATIC FUNC(void, STBM_CODE) StbM_S_TriggeredCustomer
(
    StbM_CustomerIdType CustomerId
);
#endif
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: StbM_S_UpdatePreTicks
*
* Description  : Update the time value of OSCounter saved locally.
*
* Inputs       : TbIdx
*
* Outputs      : None.
*
* Return       : E_OK, E_NOT_OK
*
* Limitations  : None.
********************************************************************************
 END_FUNCTION_HDR*/
STATIC FUNC(Std_ReturnType, STBM_CODE) StbM_S_UpdatePreTicks
(
    StbM_SynchronizedTimeBaseType TbIdx
)
{
    TickType CurrentCounter;
    StatusType Os_ret;
    Std_ReturnType ret = E_NOT_OK;

    Os_ret = GetCounterValue(STBM_CFG_TB_COUNTER_ID(TbIdx), &CurrentCounter);
    if(Os_ret == E_OS_OK)
    {
        STBM_TIME_PRE_COUNTER(TbIdx) = CurrentCounter;
        ret = E_OK;
    }

    return ret;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: StbM_S_GetBaseTime
*
* Description  : Get the global time of Timebase.
*
* Inputs       : timeBaseId
*
* Outputs      : timeStampPtr
*
* Return       : E_OK, E_NOT_OK
*
* Limitations  : None.
********************************************************************************
 END_FUNCTION_HDR*/
STATIC FUNC(Std_ReturnType, STBM_CODE) StbM_S_GetBaseTime
(
    StbM_SynchronizedTimeBaseType timeBaseId,
    P2VAR(StbM_TimeStampType, AUTOMATIC, STBM_APPL_DATA) timeStampPtr
)
{
    StbM_SynchronizedTimeBaseType TbIdx;
    StbM_SynchronizedTimeBaseType RefTbId;
    TickType CurrentCounter = 0U;
    TickType ElapseCounter;
    uint32 Nanoseconds;
    uint32 Seconds;
#if(STBM_ETH_GLOBALTIME_USED == STD_ON)
    EthTSyn_SyncStateType SyncState;
#endif
    StatusType Status_ret = E_OS_ACCESS;
    Std_ReturnType ret = E_NOT_OK;

    TbIdx = STBM_ID_TO_INDEX(timeBaseId);

#if(STBM_OFFSETTIMEBASE_USED == STD_ON)
    if(timeBaseId >= STBM_OFFSET_TIMEBASE_START_ID)
    {
        RefTbId = STBM_CFG_TB_OFFSET_TB_REF(TbIdx);
        TbIdx = STBM_ID_TO_INDEX(RefTbId);
    }
#endif

    SchM_Enter_StbM_STBM_EXCLUSIVE_AREA_0();

    /*SWS_StbM_00173*/
    if(STBM_CFG_TB_LOCAL_TIME_REF(TbIdx) != NULL_PTR)
    {
        switch(STBM_CFG_LOCALTIME_HARDWARE(TbIdx))
        {
#if(STBM_OS_GLOBALTIME_USED == STD_ON)
            case STBM_OS:
            /*SWS_StbM_00178*/
            Status_ret = GetCounterValue(STBM_CFG_TB_COUNTER_ID(TbIdx), &CurrentCounter);
            break;
#endif

#if(STBM_USERDEFCNT_USED == STD_ON)
            case STBM_USERDEF:
            Status_ret = StbM_GetUserCounterValue_Callout(STBM_CFG_TB_COUNTER_ID(TbIdx), &CurrentCounter);
            break;
#endif
            default:
                ret = E_NOT_OK;
            break;
        }
        if(Status_ret == E_OS_OK)
        {
            if(CurrentCounter >= STBM_TIME_PRE_COUNTER(TbIdx))
            {
                ElapseCounter = CurrentCounter - STBM_TIME_PRE_COUNTER(TbIdx);
            }
            else
            {
                ElapseCounter = STBM_CFG_TB_COUNTER_MAX_VALUE(TbIdx) - STBM_TIME_PRE_COUNTER(TbIdx) + CurrentCounter + (TickType)1;
            }
            /*Convert the value of ElapseCounter to the time value*/
            Nanoseconds = (uint32)ElapseCounter * STBM_CFG_TB_COUNTER_FACTOR(TbIdx);
            Seconds = (Nanoseconds / STBM_TIME_NANOSECONDS_MAX);
            Nanoseconds = (Nanoseconds % STBM_TIME_NANOSECONDS_MAX);
            /*Assign the value of CurrentCounter to PreviousOsCounter*/
            STBM_TIME_PRE_COUNTER(TbIdx) = CurrentCounter;
            /*Caculate the current global time:nanoseconds*/
            STBM_TIME_NANOSECONDS(TbIdx) += Nanoseconds;
            if(STBM_TIME_NANOSECONDS_MAX <= STBM_TIME_NANOSECONDS(TbIdx))
            {
                STBM_TIME_NANOSECONDS(TbIdx) -= STBM_TIME_NANOSECONDS_MAX;
                Seconds++;
            }
            /*Caculate the current global time:seconds*/
            if((STBM_TIME_SECONDS_MAX - STBM_TIME_SECONDS(TbIdx)) < Seconds)
            {
                STBM_TIME_SECONDS(TbIdx) = Seconds - (STBM_TIME_SECONDS_MAX - STBM_TIME_SECONDS(TbIdx)) - (uint32)1;
                Seconds = (uint32)1;
            }
            else
            {
                STBM_TIME_SECONDS(TbIdx) += Seconds;
                Seconds = 0U;
            }
            /*Caculate the current global time:secondsHi*/
            STBM_TIME_SECONDSHI(TbIdx) += (uint16)Seconds;
            /*return the global time*/
            StbM_S_CopyTimeStamp(timeStampPtr, &(STBM_TIME_STAMP(TbIdx)));
            ret = E_OK;
        }
        else
        {
            ret = E_NOT_OK;
        }        
    }
#if(STBM_ETH_GLOBALTIME_USED == STD_ON)
    else if(STBM_CFG_TB_ETH_DOMAIN_REF(TbIdx) != STBM_ETH_TIMEDOMIN_INVALID)
    {
        ret = EthTSyn_GetCurrentTime(STBM_CFG_TB_ETH_DOMAIN_REF(TbIdx), timeStampPtr, &SyncState);
        if(ret == E_OK)
        {
            /*SWS_StbM_00176*/
            switch(SyncState)
            {
                case ETHTSYN_SYNC:
                    STBM_STATUS_GLOBAL_TIME_BASE(TbIdx) = STBM_BIT_SET;
                break;

                case ETHTSYN_UNSYNC:
                    if(STBM_STATUS_GLOBAL_TIME_BASE(TbIdx) == STBM_BIT_SET)
                    {
                        STBM_STATUS_TIMEOUT(TbIdx) = STBM_BIT_SET;
                    }
                break;

                case ETHTSYN_NEVERSYNC:
                    STBM_STATUS_TIMEOUT(TbIdx) = STBM_BIT_CLR;
                    STBM_STATUS_TIMELEAP(TbIdx) = STBM_BIT_CLR;
                    STBM_STATUS_SYNC_TO_GATEWAY(TbIdx) = STBM_BIT_CLR;
                    STBM_STATUS_GLOBAL_TIME_BASE(TbIdx) = STBM_BIT_CLR;
                break;

                case ETHTSYN_UNCERTAIN:
                default:
                    ret = E_NOT_OK;
                break;
            }

            if(ret == E_OK)
            {
                timeStampPtr->timeBaseStatus.TIMEOUT = STBM_STATUS_TIMEOUT(TbIdx);
                timeStampPtr->timeBaseStatus.TIMELEAP = STBM_STATUS_TIMELEAP(TbIdx);
                timeStampPtr->timeBaseStatus.SYNC_TO_GATEWAY = STBM_STATUS_SYNC_TO_GATEWAY(TbIdx);
                timeStampPtr->timeBaseStatus.GLOBAL_TIME_BASE = STBM_STATUS_GLOBAL_TIME_BASE(TbIdx);
            }
        }
    }
#endif
    else
    {
        /*ret = E_NOT_OK;*/
    }

#if(STBM_OFFSETTIMEBASE_USED == STD_ON)
    if(ret == E_OK)
    {
        /*SWS_StbM_00177*/
        if(timeBaseId >= STBM_OFFSET_TIMEBASE_START_ID)
        {
            StbM_S_AddOffsetTime(timeBaseId, timeStampPtr);
        }
    }
#endif
    SchM_Exit_StbM_STBM_EXCLUSIVE_AREA_0();
    return ret;
}

#if(STBM_OFFSETTIMEBASE_USED == STD_ON)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: StbM_S_AddOffsetTime
*
* Description  : Add the offset time of Timebase 16~31.
*
* Inputs       : timeBaseId, timeStampPtr
*
* Outputs      : timeStampPtr
*
* Return       : None.
*
* Limitations  : None.
********************************************************************************
 END_FUNCTION_HDR*/
STATIC FUNC(void, STBM_CODE) StbM_S_AddOffsetTime
(
    StbM_SynchronizedTimeBaseType timeBaseId,
    P2VAR(StbM_TimeStampType, AUTOMATIC, STBM_APPL_DATA) timeStampPtr
)
{
    const StbM_SynchronizedTimeBaseType TbIdx = STBM_ID_TO_INDEX(timeBaseId);
    uint32 Increase = (uint32)0;

    timeStampPtr->nanoseconds += STBM_TIME_NANOSECONDS(TbIdx);

    if((timeStampPtr->nanoseconds) >= STBM_TIME_NANOSECONDS_MAX)
    {
        timeStampPtr->nanoseconds -= STBM_TIME_NANOSECONDS_MAX;
        Increase = (uint32)1;
    }

    if((STBM_TIME_SECONDS_MAX - (timeStampPtr->seconds) - Increase) < STBM_TIME_SECONDS(TbIdx))
    {
        timeStampPtr->seconds = (STBM_TIME_SECONDS_MAX - (timeStampPtr->seconds) - Increase);
        timeStampPtr->seconds = (STBM_TIME_SECONDS(TbIdx) - timeStampPtr->seconds - (uint32)1);
        Increase = (uint32)1;
    }
    else
    {
        timeStampPtr->seconds += (Increase + STBM_TIME_SECONDS(TbIdx));
        Increase = (uint32)0;
    }

    timeStampPtr->secondsHi += ((uint16)Increase + STBM_TIME_SECONDSHI(TbIdx));
}
#endif
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: StbM_S_SetBaseTime
*
* Description  : Set the global time or offset time of Timebase
*
* Inputs       : timeBaseId, timeStampPtr
*
* Outputs      : None.
*
* Return       : E_OK: Set successfully
*                E_NOT_OK: Set failed
*
* Limitations  : None.
********************************************************************************
 END_FUNCTION_HDR*/
STATIC FUNC(Std_ReturnType, STBM_CODE) StbM_S_SetBaseTime
(
    StbM_SynchronizedTimeBaseType timeBaseId,
    P2CONST(StbM_TimeStampType, STBM_APPL_CONST, AUTOMATIC) timeStampPtr
)
{
    StbM_SynchronizedTimeBaseType TbIdx;
#if(STBM_OFFSETTIMEBASE_USED == STD_ON)
    StbM_SynchronizedTimeBaseType OffsetTbId;
    StbM_SynchronizedTimeBaseType OffsetTbIdx;
#endif
    StbM_TimeStampType CurrentTimeStamp;
    Std_ReturnType ret = E_NOT_OK;

    TbIdx = STBM_ID_TO_INDEX(timeBaseId);

    if(STBM_IS_TIMEBASE_ID(timeBaseId))
    {
        if(STBM_CFG_TB_LOCAL_TIME_REF(TbIdx) != NULL_PTR)
        {
            ret = StbM_S_UpdatePreTicks(TbIdx);
            if(ret == E_OK)
            {
                /*Set the global time*/
                STBM_TIME_SECONDSHI(TbIdx) = timeStampPtr->secondsHi;
                STBM_TIME_SECONDS(TbIdx) = timeStampPtr->seconds;
                STBM_TIME_NANOSECONDS(TbIdx) = timeStampPtr->nanoseconds;
            }
        }
#if(STBM_ETH_GLOBALTIME_USED == STD_ON)
        else if(STBM_CFG_TB_ETH_DOMAIN_REF(TbIdx) != STBM_ETH_TIMEDOMIN_INVALID)
        {
            ret = EthTSyn_SetGlobalTime(STBM_CFG_TB_ETH_DOMAIN_REF(TbIdx), timeStampPtr);
        }
#endif
        else
        {
            /*do nothing*/
        }
    }
#if(STBM_OFFSETTIMEBASE_USED == STD_ON)
    else
    {
        /*Offset time base*/
        OffsetTbId = STBM_CFG_TB_OFFSET_TB_REF(TbIdx);
        OffsetTbIdx = STBM_ID_TO_INDEX(OffsetTbId);

        if(STBM_STATUS_GLOBAL_TIME_BASE(OffsetTbIdx) == STBM_BIT_SET)
        {
            /*Get the current global time of the referenced base time*/
            ret = StbM_S_GetBaseTime(OffsetTbId, &CurrentTimeStamp);

            if(ret == E_OK)
            {
                /*Calculate the diff between timeStampPtr(minuend) and CurrentTimeStamp(subtrahend)*/
                ret = StbM_S_CalculateTimeStampDiff(timeStampPtr, &CurrentTimeStamp);

                if(ret == E_OK)
                {
                    /*Set the offset time*/
                    STBM_TIME_SECONDSHI(TbIdx) = CurrentTimeStamp.secondsHi;
                    STBM_TIME_SECONDS(TbIdx) = CurrentTimeStamp.seconds;
                    STBM_TIME_NANOSECONDS(TbIdx) = CurrentTimeStamp.nanoseconds;
                }
            }
        }
    }
#endif

    return ret;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: StbM_S_CopyTimeStamp
*
* Description  : Copy time stamp data of SrcPtr to DestPtr.
*
* Inputs       : DestPtr, SrcPtr
*
* Outputs      : DestPtr
*
* Return       : None
*
* Limitations  : None.
********************************************************************************
 END_FUNCTION_HDR*/
STATIC FUNC(void, STBM_CODE) StbM_S_CopyTimeStamp
(
    P2VAR(StbM_TimeStampType, AUTOMATIC, STBM_APPL_DATA) DestPtr,
    P2CONST(StbM_TimeStampType, STBM_APPL_CONST, AUTOMATIC) SrcPtr
)
{
    DestPtr->secondsHi = SrcPtr->secondsHi;
    DestPtr->seconds = SrcPtr->seconds;
    DestPtr->nanoseconds = SrcPtr->nanoseconds;
    DestPtr->timeBaseStatus.GLOBAL_TIME_BASE = SrcPtr->timeBaseStatus.GLOBAL_TIME_BASE;
    DestPtr->timeBaseStatus.SYNC_TO_GATEWAY = SrcPtr->timeBaseStatus.SYNC_TO_GATEWAY;
    DestPtr->timeBaseStatus.TIMELEAP = SrcPtr->timeBaseStatus.TIMELEAP;
    DestPtr->timeBaseStatus.TIMEOUT = SrcPtr->timeBaseStatus.TIMEOUT;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: StbM_S_CopyUserData
*
* Description  : Copy the user data of SrcPtr to DestPtr.
*
* Inputs       : DestPtr, SrcPtr
*
* Outputs      : DestPtr
*
* Return       : None
*
* Limitations  : None.
********************************************************************************
 END_FUNCTION_HDR*/
STATIC FUNC(void, STBM_CODE) StbM_S_CopyUserData
(
    P2VAR(StbM_UserDataType, AUTOMATIC, STBM_APPL_DATA) DestPtr,
    P2CONST(StbM_UserDataType, STBM_APPL_CONST, AUTOMATIC) SrcPtr
)
{
    if(SrcPtr->userDataLength >= 3)
    {
        DestPtr->userByte2 = SrcPtr->userByte2;
    }
    if(SrcPtr->userDataLength >= 2)
    {
        DestPtr->userByte1 = SrcPtr->userByte1;
    }
    if(SrcPtr->userDataLength >= 1)
    {
        DestPtr->userByte0 = SrcPtr->userByte0;
    }
    DestPtr->userDataLength = SrcPtr->userDataLength;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: StbM_S_CalculateTimeStampDiff
*
* Description  : Calculate the time difference between the MinuendtimeStamp and
*                SubtrahendtimeStamp.
*
* Inputs       : MinuendtimeStampPtr, SubtrahendtimeStampPtr
*
* Outputs      : SubtrahendtimeStampPtr
*
* Return       : E_OK: Successfully calculated the difference
*                E_NOT_OK: MinuendtimeStamp is less than SubtrahendtimeStamp.
*
* Limitations  : None.
********************************************************************************
 END_FUNCTION_HDR*/
STATIC FUNC(Std_ReturnType, STBM_CODE) StbM_S_CalculateTimeStampDiff
(
    P2CONST(StbM_TimeStampType, STBM_APPL_CONST, AUTOMATIC) MinuendtimeStampPtr,
    P2VAR(StbM_TimeStampType, AUTOMATIC, STBM_APPL_DATA) SubtrahendtimeStampPtr
)
{
    uint64 MinuendSeconds;
    uint64 SubtrahendSeconds;
    Std_ReturnType ret = E_NOT_OK;

    MinuendSeconds = (uint64)(MinuendtimeStampPtr->secondsHi) << STBM_TIME_SECONDS_SHIFT;
    MinuendSeconds |= (uint64)(MinuendtimeStampPtr->seconds);
    SubtrahendSeconds = (uint64)(SubtrahendtimeStampPtr->secondsHi) << STBM_TIME_SECONDS_SHIFT;
    SubtrahendSeconds |= (uint64)(SubtrahendtimeStampPtr->seconds);

    if(MinuendSeconds > SubtrahendSeconds)
    {
        if((MinuendtimeStampPtr->nanoseconds) >= (SubtrahendtimeStampPtr->nanoseconds))
        {
            SubtrahendtimeStampPtr->nanoseconds = (MinuendtimeStampPtr->nanoseconds - SubtrahendtimeStampPtr->nanoseconds);
            SubtrahendSeconds = (MinuendSeconds - SubtrahendSeconds);
        }
        else
        {
            SubtrahendtimeStampPtr->nanoseconds = (STBM_TIME_NANOSECONDS_MAX - SubtrahendtimeStampPtr->nanoseconds);
            SubtrahendtimeStampPtr->nanoseconds += MinuendtimeStampPtr->nanoseconds;
            SubtrahendSeconds = (MinuendSeconds - SubtrahendSeconds - (uint64)1);
        }
        ret = E_OK;
    }
    else if(MinuendSeconds == SubtrahendSeconds)
    {
        if((MinuendtimeStampPtr->nanoseconds) >= (SubtrahendtimeStampPtr->nanoseconds))
        {
            SubtrahendtimeStampPtr->nanoseconds = (MinuendtimeStampPtr->nanoseconds - SubtrahendtimeStampPtr->nanoseconds);
            SubtrahendSeconds = 0U;
            ret = E_OK;
        }
    }
    else
    {
        /*ret = E_NOT_OK;*/
    }

    if(ret == E_OK)
    {
        SubtrahendtimeStampPtr->seconds = (uint32)SubtrahendSeconds;
        SubtrahendtimeStampPtr->secondsHi = (uint16)(SubtrahendSeconds >> STBM_TIME_SECONDS_SHIFT);
    }

    return ret;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: StbM_S_CheckLossThreshold
*
* Description  : Check if the time difference between the current and the update
*                timestamp exceeds the configured threshold.
*
* Inputs       : timeBaseId, PretimeStampPtr, CurtimeStampPtr
*
* Outputs      : None.
*
* Return       : TRUE: exceeds the configured threshold; FALSE:does not exceed
*
* Limitations  : None.
********************************************************************************
 END_FUNCTION_HDR*/
STATIC FUNC(boolean, STBM_CODE) StbM_S_CheckLossThreshold
(
    StbM_SynchronizedTimeBaseType timeBaseId,
    P2CONST(StbM_TimeStampType, STBM_APPL_CONST, AUTOMATIC) PretimeStampPtr,
    P2CONST(StbM_TimeStampType, STBM_APPL_CONST, AUTOMATIC) CurtimeStampPtr
)
{
    uint64 PreSeconds;
    uint64 CurSeconds;
    boolean Overrun = FALSE;
    const StbM_SynchronizedTimeBaseType TbIdx = STBM_ID_TO_INDEX(timeBaseId);
    if((STBM_CFG_TB_LOSS_SECONDS_THRESHOLD(TbIdx) > (uint32)0) || STBM_CFG_TB_LOSS_NASECONDS_THRESHOLD(TbIdx) > (uint32)0)
    {
        PreSeconds = (uint64)(PretimeStampPtr->secondsHi) << STBM_TIME_SECONDS_SHIFT;
        PreSeconds |= (uint64)(PretimeStampPtr->seconds);
        CurSeconds = (uint64)(CurtimeStampPtr->secondsHi) << STBM_TIME_SECONDS_SHIFT;
        CurSeconds |= (uint64)(CurtimeStampPtr->seconds);
        if(CurSeconds > (PreSeconds + (uint64)STBM_CFG_TB_LOSS_SECONDS_THRESHOLD(TbIdx) + (uint64)1))
        {
             Overrun = TRUE;
        }
        else if(CurSeconds == (PreSeconds + (uint64)STBM_CFG_TB_LOSS_SECONDS_THRESHOLD(TbIdx) + (uint64)1))
        {
            if((STBM_TIME_NANOSECONDS_MAX + CurtimeStampPtr->nanoseconds) > (PretimeStampPtr->nanoseconds + STBM_CFG_TB_LOSS_NASECONDS_THRESHOLD(TbIdx)))
            {
                Overrun = TRUE;
            }
            else
            {
                Overrun = FALSE;
            }
        }
        else if(CurSeconds == (PreSeconds + (uint64)STBM_CFG_TB_LOSS_SECONDS_THRESHOLD(TbIdx)))
        {
            if(CurtimeStampPtr->nanoseconds > (PretimeStampPtr->nanoseconds + STBM_CFG_TB_LOSS_NASECONDS_THRESHOLD(TbIdx)))
            {
                Overrun = TRUE;
            }
            else
            {
                Overrun = FALSE;
            }
        }
        else
        {
            /*Overrun = FALSE;*/
        }
    }   
   return Overrun;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: StbM_S_CheckLossTimeout
*
* Description  : Check if a timeout occurs from last invocation StbM_BusSetGlobalTime()
*                to the current invocation StbM_BusSetGlobalTime().
*
* Inputs       : timeBaseId, PretimeStampPtr, CurtimeStampPtr
*
* Outputs      : None.
*
* Return       : TRUE: timeout happen; FALSE: no timeout
*
* Limitations  : None.
********************************************************************************
 END_FUNCTION_HDR*/
STATIC FUNC(boolean, STBM_CODE) StbM_S_CheckLossTimeout
(
    StbM_SynchronizedTimeBaseType timeBaseId,
    P2CONST(StbM_TimeStampType, STBM_APPL_CONST, AUTOMATIC) PretimeStampPtr,
    P2CONST(StbM_TimeStampType, STBM_APPL_CONST, AUTOMATIC) CurtimeStampPtr
)
{
    uint64 PreSeconds;
    uint64 CurSeconds;
    boolean Overrun = FALSE;
    const StbM_SynchronizedTimeBaseType TbIdx = STBM_ID_TO_INDEX(timeBaseId);
    if((STBM_CFG_TB_LOSS_SECONDS_TIMEOUT(TbIdx) > (uint32)0) || (STBM_CFG_TB_LOSS_NASECONDS_TIMEOUT(TbIdx) > (uint32)0))
    {
        PreSeconds = (uint64)(PretimeStampPtr->secondsHi) << STBM_TIME_SECONDS_SHIFT;
        PreSeconds |= (uint64)(PretimeStampPtr->seconds);
        CurSeconds = (uint64)(CurtimeStampPtr->secondsHi) << STBM_TIME_SECONDS_SHIFT;
        CurSeconds |= (uint64)(CurtimeStampPtr->seconds);
        if(CurSeconds > (PreSeconds + STBM_CFG_TB_LOSS_SECONDS_TIMEOUT(TbIdx) + (uint64)1))
        {
            Overrun = TRUE;
        }
        else if(CurSeconds == (PreSeconds + STBM_CFG_TB_LOSS_SECONDS_TIMEOUT(TbIdx) + (uint64)1))
        {
            if((STBM_TIME_NANOSECONDS_MAX + CurtimeStampPtr->nanoseconds) > (PretimeStampPtr->nanoseconds + STBM_CFG_TB_LOSS_NASECONDS_TIMEOUT(TbIdx)))
            {
                Overrun = TRUE;
            }
            else
            {
                Overrun = FALSE;
            }
        }
        else if(CurSeconds == (STBM_CFG_TB_LOSS_SECONDS_TIMEOUT(TbIdx) + PreSeconds))
        {
            if(CurtimeStampPtr->nanoseconds > (PretimeStampPtr->nanoseconds + STBM_CFG_TB_LOSS_NASECONDS_TIMEOUT(TbIdx)))
            {
                Overrun = TRUE;
            }
            else
            {
                Overrun = FALSE;
            }
        }
        else
        {
            /*Overrun = FALSE;*/
        }
    }
    return Overrun;
}

#if(STBM_NUM_OF_TRIGGEREDCUSTOMER > 0)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: StbM_S_TriggeredCustomer
*
* Description  : Request synchronization schedule table of one customer 
*
* Inputs       : CustomerId
*
* Outputs      : None.
*
* Return       : None
*
* Limitations  : Only available when triggered customer function used.
********************************************************************************
 END_FUNCTION_HDR*/
FUNC(void, STBM_CODE) StbM_S_TriggeredCustomer
(
    StbM_CustomerIdType CustomerId
)
{
    StbM_SynchronizedTimeBaseType TbId;
    StbM_TimeStampType TimeStamp;
    TickType TickValue;
    ScheduleTableStatusType ScheduleStatus;
    StatusType OsStatus = E_OK;

    /*SWS_StbM_00092*/
    OsStatus = GetScheduleTableStatus(STBM_CFG_TRIGGER_TABLE(CustomerId), &ScheduleStatus);
    if((OsStatus == E_OK) && ((ScheduleStatus == SCHEDULETABLE_WAITING) \
        || (ScheduleStatus == SCHEDULETABLE_RUNNING) || (ScheduleStatus == SCHEDULETABLE_RUNNING_AND_SYNCHRONOUS)))
    {
        TbId = STBM_CFG_TRIGGER_TB_REF(CustomerId);
        if(E_OK == StbM_S_GetBaseTime(TbId, &TimeStamp))
        {
            TickValue = (TimeStamp.nanoseconds / STBM_CFG_TRIGGER_FACTOR(CustomerId));
            TickValue = (TickValue % STBM_CFG_TRIGGER_TABLE_DURATION(CustomerId));

            (void)SyncScheduleTable(STBM_CFG_TRIGGER_TABLE(CustomerId), TickValue);
        }
    }
}
#endif

/*******************************************************************************
*  PUBLIC Functions define
*******************************************************************************/

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: StbM_Init  SWS_StbM_00052
*
* Description  : Initializes the Synchronized Time-base Manager.
*
* Inputs       : ConfigPtr: Pointer to the selected configuration set.
*
* Outputs      : None.
*
* Return       : None
*
* Limitations  : None.
********************************************************************************
 END_FUNCTION_HDR*/
FUNC(void, STBM_CODE) StbM_Init
(
    P2CONST(StbM_ConfigType, STBM_APPL_CONST, AUTOMATIC) ConfigPtr
)
{
    /*Time Base Index value*/
    StbM_SynchronizedTimeBaseType TbIdx;
#if(STBM_NONVOLATILE_SUPPORT == STD_ON)
    StbM_SynchronizedTimeBaseType TbId;
#endif
#if(STBM_NUM_OF_TRIGGEREDCUSTOMER > 0)
    StbM_CustomerIdType CustomerId;
#endif

#if(STBM_CONFIG_VARIANTS == STD_CONFIG_VARIANTS_POSTBUILD)
    if(NULL_PTR == ConfigPtr)
    {
        STBM_DET_REPORT_ERROR(STBM_SID_INIT, STBM_E_PARAM_POINTER);
    }
    else
#else
    /* MISRA RULE 14.2 violated:
    this statement is used to reduce the compiler warnning on the unused parameters.*/
    (void)ConfigPtr;
#endif
    {
#if(STBM_CONFIG_VARIANTS == STD_CONFIG_VARIANTS_POSTBUILD)
        StbM_ConfigSet = ConfigPtr;
#endif
        for(TbIdx = (StbM_SynchronizedTimeBaseType)0; TbIdx < (StbM_SynchronizedTimeBaseType)STBM_NUM_OF_TIMEBASE; TbIdx++)
        {
            /*SWS_StbM_00170*/
            /*Reset status and time value*/
            StbM_S_CopyTimeStamp(&(STBM_TIME_STAMP(TbIdx)), &StbMTimeStampInitValue);
            StbM_S_CopyTimeStamp(&(STBM_LAST_BUSSET_STAMP(TbIdx)), &StbMTimeStampInitValue);
            /*Reset user data*/
            StbM_UserData[TbIdx].userDataLength = (uint8)0;
            StbM_UserData[TbIdx].userByte0 = (uint8)0;
            StbM_UserData[TbIdx].userByte1 = (uint8)0;
            StbM_UserData[TbIdx].userByte2 = (uint8)0;
            STBM_TIME_PRE_COUNTER(TbIdx) = 0U;

#if(STBM_NONVOLATILE_SUPPORT == STD_ON)
            if(STBM_CFG_TB_NV(TbIdx) == STBM_STORAGE_AT_SHUTDOWN)
            {
                TbId = STBM_CFG_TB_ID(TbIdx);
                (void)StbM_Rte_GlobalTime_RestoreFromNonVolatile(TbId, &(STBM_TIME_STAMP(TbIdx)), &(STBM_USERDATA(TbIdx)));

                if((STBM_IS_TIMEBASE_ID(TbId)) && (STBM_CFG_TB_LOCAL_TIME_REF(TbIdx) != NULL_PTR))
                {
                    if(E_OK != StbM_S_UpdatePreTicks(TbIdx))
                    {
                        /*SWS_StbM_00099*/
                        STBM_DET_REPORT_ERROR(STBM_SID_INIT, STBM_E_INIT_FAILED);
                    }
                }
                else
                {
                    /*do nothing*/
                }
            }
#endif
        }

#if(STBM_NUM_OF_TRIGGEREDCUSTOMER > 0)
        for(CustomerId = 0U; CustomerId < STBM_NUM_OF_TRIGGEREDCUSTOMER; CustomerId++)
        {
            STBM_TRIGGERED_TIME(CustomerId) = STBM_CFG_TRIGGER_PERIOD(CustomerId);
        }
#endif
        /*SWS_StbM_00121*/
        StbM_InitState = STD_INITIALIZED;
    }
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: StbM_GetCurrentTime   SWS_StbM_00195
*
* Description  : Returns a time value (Local Time Base derived from Global Time
*                Base) in standard format.
*
* Inputs       : timeBaseId: time base reference
*
* Outputs      : timeStampPtr: Current time stamp that is valid at this time.
*                userDataPtr: User data of the Time Base.
*
* Return       : E_OK: successful 
*                E_NOT_OK: failed
*
* Limitations  : None.
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, STBM_CODE) StbM_GetCurrentTime
(
    StbM_SynchronizedTimeBaseType timeBaseId,
    P2VAR(StbM_TimeStampType, AUTOMATIC, STBM_APPL_DATA) timeStampPtr,
    P2VAR(StbM_UserDataType, AUTOMATIC, STBM_APPL_DATA) userDataPtr
)
{
    StbM_SynchronizedTimeBaseType TbIdx;
    Std_ReturnType ret = E_NOT_OK;

    if(!STBM_IS_INITIALIZED())
    {
        /*SWS_StbM_00198*/
        STBM_DET_REPORT_ERROR(STBM_SID_GETCURRENTTIME, STBM_E_NOT_INITIALIZED);
    }
    else if((timeBaseId > STBM_TIME_BASE_MAX_ID) || (!STBM_IS_ID_VALID(timeBaseId)))
    {
        /*SWS_StbM_00196*/
        STBM_DET_REPORT_ERROR(STBM_SID_GETCURRENTTIME, STBM_E_PARAM);
    }
    else if((timeStampPtr == NULL_PTR) || (userDataPtr == NULL_PTR))
    {
        /*SWS_StbM_00197*/
        STBM_DET_REPORT_ERROR(STBM_SID_GETCURRENTTIME, STBM_E_PARAM_POINTER);
    }
    else
    {
        ret = StbM_S_GetBaseTime(timeBaseId, timeStampPtr);
    }

    if(ret == E_OK)
    {
        TbIdx = STBM_ID_TO_INDEX(timeBaseId);
        StbM_S_CopyUserData(userDataPtr, &(STBM_USERDATA(TbIdx)));
    }

    return ret;
}

#if(STBM_NONVOLATILE_SUPPORT == STD_ON)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: StbM_GetCurrentTimeToBeStored
*
* Description  : This function is used to read the standard format time value of
*                the time base stored in the non-volatile memory when the power
*                is off.
*
* Inputs       : timeBaseId: time base reference
*
* Outputs      : timeStampPtr: Current time stamp that is valid at this time.
*                userDataPtr: User data of the Time Base.
*
* Return       : E_OK: successful 
*                E_NOT_OK: failed
*
* Limitations  : None.
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, STBM_CODE) StbM_GetCurrentTimeToBeStored
(
    StbM_SynchronizedTimeBaseType timeBaseId,
    P2VAR(StbM_TimeStampType, AUTOMATIC, STBM_APPL_DATA) timeStampPtr,
    P2VAR(StbM_UserDataType, AUTOMATIC, STBM_APPL_DATA) userDataPtr
)
{
    StbM_SynchronizedTimeBaseType TbIdx;
    Std_ReturnType ret = E_NOT_OK;

    if(!STBM_IS_INITIALIZED())
    {
        STBM_DET_REPORT_ERROR(STBM_SID_GETCURRENTTIMETOBESTORED, STBM_E_NOT_INITIALIZED);
    }
    else if((timeBaseId > STBM_TIME_BASE_MAX_ID) || (!STBM_IS_ID_VALID(timeBaseId)))
    {
        STBM_DET_REPORT_ERROR(STBM_SID_GETCURRENTTIMETOBESTORED, STBM_E_PARAM);
    }
    else if((timeStampPtr == NULL_PTR) || (userDataPtr == NULL_PTR))
    {
        STBM_DET_REPORT_ERROR(STBM_SID_GETCURRENTTIMETOBESTORED, STBM_E_PARAM_POINTER);
    }
    else if(STBM_CFG_TB_NV(STBM_ID_TO_INDEX(timeBaseId)) != STBM_STORAGE_AT_SHUTDOWN)
    {
        /*return E_NOT_OK*/
    }
    else
    {
        ret = StbM_S_GetBaseTime(timeBaseId, timeStampPtr);
    }

    if(ret == E_OK)
    {
        TbIdx = STBM_ID_TO_INDEX(timeBaseId);
        StbM_S_CopyUserData(userDataPtr, &(STBM_USERDATA(TbIdx)));
    }

    return ret;
}
#endif

#if(STBM_GETCURRENTTIMEEXTENDED_AVAILABLE == STD_ON)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: StbM_GetCurrentTimeExtended  SWS_StbM_00200
*
* Description  : Returns a time value (Local Time Base derived from Global Time
*                Base) in extended format.
*
* Inputs       : timeBaseId: time base reference
*
* Outputs      : timeStampPtr: Current time stamp that is valid at this time.
*                userDataPtr: User data of the Time Base.
*
* Return       : E_OK: successful 
*                E_NOT_OK: failed
*
* Limitations  : None.
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, STBM_CODE) StbM_GetCurrentTimeExtended
(
    StbM_SynchronizedTimeBaseType timeBaseId,
    P2VAR(StbM_TimeStampExtendedType, AUTOMATIC, STBM_APPL_DATA) timeStampPtr,
    P2VAR(StbM_UserDataType, AUTOMATIC, STBM_APPL_DATA) userDataPtr
)
{
    StbM_TimeStampType TimeStamp;
    StbM_SynchronizedTimeBaseType TbIdx;
    Std_ReturnType ret = E_NOT_OK;

    if(!STBM_IS_INITIALIZED())
    {
        /*SWS_StbM_00198*/
        STBM_DET_REPORT_ERROR(STBM_SID_GETCURRENTTIMEEXTENDED, STBM_E_NOT_INITIALIZED);
    }
    else if((timeBaseId > STBM_TIME_BASE_MAX_ID) || (!STBM_IS_ID_VALID(timeBaseId)))
    {
        /*SWS_StbM_00201*/
        STBM_DET_REPORT_ERROR(STBM_SID_GETCURRENTTIMEEXTENDED, STBM_E_PARAM);
    }
    else if((timeStampPtr == NULL_PTR) || (userDataPtr == NULL_PTR))
    {
        /*SWS_StbM_00202*/
        STBM_DET_REPORT_ERROR(STBM_SID_GETCURRENTTIMEEXTENDED, STBM_E_PARAM_POINTER);
    }
    else
    {
        ret = StbM_S_GetBaseTime(timeBaseId, &TimeStamp);
    }

    if(ret == E_OK)
    {
        TbIdx = STBM_ID_TO_INDEX(timeBaseId);
        StbM_S_CopyUserData(userDataPtr, &(STBM_USERDATA(TbIdx)));
        timeStampPtr->seconds = (uint64)(TimeStamp.secondsHi) << STBM_TIME_SECONDS_SHIFT;
        timeStampPtr->seconds |= (uint64)(TimeStamp.seconds);
        timeStampPtr->nanoseconds = TimeStamp.nanoseconds;
        timeStampPtr->timeBaseStatus.GLOBAL_TIME_BASE = TimeStamp.timeBaseStatus.GLOBAL_TIME_BASE;
        timeStampPtr->timeBaseStatus.SYNC_TO_GATEWAY = TimeStamp.timeBaseStatus.SYNC_TO_GATEWAY;
        timeStampPtr->timeBaseStatus.TIMELEAP = TimeStamp.timeBaseStatus.TIMELEAP;
        timeStampPtr->timeBaseStatus.TIMEOUT = TimeStamp.timeBaseStatus.TIMEOUT;
    }

    return ret;
}
#endif

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: StbM_GetCurrentTimeRaw  SWS_StbM_00205
*
* Description  : Returns a time value in raw format from the most accurate time
*                source.
*
* Inputs       : None.
*
* Outputs      : timeStampRawPtr: Current time stamp that is valid at this time
*
* Return       : E_OK: successful 
*                E_NOT_OK: failed
*
* Limitations  : None.
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, STBM_CODE) StbM_GetCurrentTimeRaw
(
    P2VAR(StbM_TimeStampRawType, AUTOMATIC, STBM_APPL_DATA) timeStampRawPtr
)
{
    TickType Counter;
    StatusType Status_ret = E_OS_ACCESS;
    Std_ReturnType ret = E_NOT_OK;

    if(!STBM_IS_INITIALIZED())
    {
        /*SWS_StbM_00198*/
        STBM_DET_REPORT_ERROR(STBM_SID_GETCURRENTTIMERAW, STBM_E_NOT_INITIALIZED);
    }
    else if(timeStampRawPtr == NULL_PTR)
    {
        /*SWS_StbM_00206*/
        STBM_DET_REPORT_ERROR(STBM_SID_GETCURRENTTIMERAW, STBM_E_PARAM_POINTER);
    }
    else
    {
        /*SWS_StbM_00174*/
#if(STBM_RAW_OS_COUNTER_SUPPORT == STD_ON)
        Status_ret = GetCounterValue((CounterType)STBM_RAW_COUNTER_REF, &Counter);
#endif 
#if(STBM_RAW_USER_COUNTER_SUPPORT == STD_ON)
        Status_ret = StbM_GetUserCounterValue_Callout((CounterType)STBM_RAW_COUNTER_REF, &Counter);
#endif 
        if(Status_ret == E_OS_OK)
        {
            /*Calculate the nanoseconds of OsCounter*/
            *timeStampRawPtr = Counter * (StbM_TimeStampRawType)STBM_RAW_TICK_TO_NS_FACTOR;
            ret = E_OK;
        }
    }
    return ret;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: StbM_GetCurrentTimeDiff  SWS_StbM_00209
*
* Description  : Returns the time difference of current time raw that is valid
*                at this time minus given time raw by using a most accurate time
*                source.
*
* Inputs       : givenTimeStamp: Given time stamp as difference calculation basis
*
* Outputs      : timeStampDiffPtr: Time difference of current time stamp that is
*                valid at this time minus given time stamp
*
* Return       : E_OK: successful 
*                E_NOT_OK: failed
*
* Limitations  : None.
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, STBM_CODE) StbM_GetCurrentTimeDiff
(
    StbM_TimeStampRawType givenTimeStamp,
    P2VAR(StbM_TimeStampRawType, AUTOMATIC, STBM_APPL_DATA) timeStampDiffPtr
)
{
    TickType Counter;
    StbM_TimeStampRawType TimeDiff;
    StbM_TimeStampRawType TimeMax;
    StatusType Status_ret = E_OS_ACCESS;
    Std_ReturnType ret = E_NOT_OK;

    if(!STBM_IS_INITIALIZED())
    {
        /*SWS_StbM_00198*/
        STBM_DET_REPORT_ERROR(STBM_SID_GETCURRENTTIMEDIFF, STBM_E_NOT_INITIALIZED);
    }
    else if(timeStampDiffPtr == NULL_PTR)
    {
        /*SWS_StbM_00210*/
        STBM_DET_REPORT_ERROR(STBM_SID_GETCURRENTTIMEDIFF, STBM_E_PARAM_POINTER);
    }
    else
    {
        /*SWS_StbM_00175*/

#if(STBM_RAW_OS_COUNTER_SUPPORT  == STD_ON)
        Status_ret= GetCounterValue((CounterType)STBM_RAW_COUNTER_REF, &Counter);
#endif 

#if(STBM_RAW_USER_COUNTER_SUPPORT == STD_ON)
        Status_ret = StbM_GetUserCounterValue_Callout((CounterType)STBM_RAW_COUNTER_REF, &Counter);
#endif        
        if(Status_ret == E_OS_OK)
        {
            /*Calculate the nanoseconds of OsCounter*/
            TimeDiff = Counter * (StbM_TimeStampRawType)STBM_RAW_TICK_TO_NS_FACTOR;
            if(TimeDiff >= givenTimeStamp)
            {
                TimeDiff -= givenTimeStamp;
            }
            else
            {
                TimeMax = (StbM_TimeStampRawType)(STBM_RAW_TICK_MAX_VALUE * STBM_RAW_TICK_TO_NS_FACTOR);
                TimeDiff += (TimeMax - givenTimeStamp + (StbM_TimeStampRawType)1);
            }
            *timeStampDiffPtr = TimeDiff;
            ret = E_OK;
        }
    }

    return ret;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: StbM_SetGlobalTime  SWS_StbM_00213
*
* Description  : Allows the Customers to set the new global time that has to be
*                valid for the system, which will be sent to the busses and modify
*                HW registers behind the providers, if supported. This function
*                will be used if a Time Master is present in this ECU.
*
* Inputs       : timeBaseId: time base reference
*                timeStampPtr: New time stamp
*                userDataPtr: New user data (if not NULL)
*
* Outputs      : None.
*
* Return       : E_OK: successful 
*                E_NOT_OK: failed
*
* Limitations  : None.
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, STBM_CODE) StbM_SetGlobalTime
(
    StbM_SynchronizedTimeBaseType timeBaseId,
    P2CONST(StbM_TimeStampType, STBM_APPL_CONST, AUTOMATIC) timeStampPtr,
    P2CONST(StbM_UserDataType, STBM_APPL_CONST, AUTOMATIC) userDataPtr
)
{
    StbM_SynchronizedTimeBaseType TbIdx;
    Std_ReturnType ret = E_NOT_OK;

    if(!STBM_IS_INITIALIZED())
    {
        /*SWS_StbM_00198*/
        STBM_DET_REPORT_ERROR(STBM_SID_SETGLOBALTIME, STBM_E_NOT_INITIALIZED);
    }
    else if((timeBaseId > STBM_TIME_BASE_MAX_ID) || (!STBM_IS_ID_VALID(timeBaseId)))
    {
        /*SWS_StbM_00214*/
        STBM_DET_REPORT_ERROR(STBM_SID_SETGLOBALTIME, STBM_E_PARAM);
    }
    else if(STBM_CFG_TB_IS_MASTER(STBM_ID_TO_INDEX(timeBaseId)) != TRUE)
    {
        STBM_DET_REPORT_ERROR(STBM_SID_SETGLOBALTIME, STBM_E_PARAM);
    }
    else if(timeStampPtr == NULL_PTR)
    {
        /*SWS_StbM_00215*/
        STBM_DET_REPORT_ERROR(STBM_SID_SETGLOBALTIME, STBM_E_PARAM_POINTER);
    }
    else if((userDataPtr != NULL_PTR) && (userDataPtr->userDataLength > STBM_USERDATA_MAX_LENGTH))
    {
        STBM_DET_REPORT_ERROR(STBM_SID_SETGLOBALTIME, STBM_E_PARAM);
    }
    else
    {
        ret = StbM_S_SetBaseTime(timeBaseId, timeStampPtr);

        if(ret == E_OK)
        {
            TbIdx = STBM_ID_TO_INDEX(timeBaseId);
            /*Set status SWS_StbM_00181*/
            STBM_STATUS_TIMEOUT(TbIdx) = STBM_BIT_CLR;
            STBM_STATUS_TIMELEAP(TbIdx) = STBM_BIT_CLR;
            STBM_STATUS_SYNC_TO_GATEWAY(TbIdx) = STBM_BIT_CLR;
            STBM_STATUS_GLOBAL_TIME_BASE(TbIdx) = STBM_BIT_SET;
            /*Set user data*/
            if(userDataPtr != NULL_PTR)
            {
                StbM_S_CopyUserData(&(STBM_USERDATA(TbIdx)), userDataPtr);
            }
        }
    }

    return ret;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: StbM_SetUserData  SWS_StbM_00218
*
* Description  : Allows the Customers to set the new user data that has to be
*                valid for the system, which will be sent to the busses.
*
* Inputs       : timeBaseId: time base reference
*                userDataPtr: New user data (if not NULL)
*
* Outputs      : None.
*
* Return       : E_OK: successful 
*                E_NOT_OK: failed
*
* Limitations  : None.
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, STBM_CODE) StbM_SetUserData
(
    StbM_SynchronizedTimeBaseType timeBaseId,
    P2CONST(StbM_UserDataType, STBM_APPL_CONST, AUTOMATIC) userDataPtr
)
{
    StbM_SynchronizedTimeBaseType TbIdx;
    Std_ReturnType ret = E_NOT_OK;

    if(!STBM_IS_INITIALIZED())
    {
        /*SWS_StbM_00198*/
        STBM_DET_REPORT_ERROR(STBM_SID_SETUSERDATA, STBM_E_NOT_INITIALIZED);
    }
    else if((timeBaseId > STBM_TIME_BASE_MAX_ID) || (!STBM_IS_ID_VALID(timeBaseId)))
    {
        /*SWS_StbM_00219*/
        STBM_DET_REPORT_ERROR(STBM_SID_SETUSERDATA, STBM_E_PARAM);
    }
    else if(STBM_CFG_TB_IS_MASTER(STBM_ID_TO_INDEX(timeBaseId)) != TRUE)
    {
        STBM_DET_REPORT_ERROR(STBM_SID_SETUSERDATA, STBM_E_PARAM);
    }
    else if(userDataPtr == NULL_PTR)
    {
        /*SWS_StbM_00220*/
        STBM_DET_REPORT_ERROR(STBM_SID_SETUSERDATA, STBM_E_PARAM_POINTER);
    }
    else if(userDataPtr->userDataLength > STBM_USERDATA_MAX_LENGTH)
    {
        STBM_DET_REPORT_ERROR(STBM_SID_SETUSERDATA, STBM_E_PARAM);
    }
    else
    {
        TbIdx = STBM_ID_TO_INDEX(timeBaseId);
        StbM_S_CopyUserData(&(STBM_USERDATA(TbIdx)), userDataPtr);

        ret = E_OK;
    }

    return ret;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: StbM_SetOffset  SWS_StbM_00223
*
* Description  : Allows the Customers and the Timebase Provider Modules to set
*                the offset time that has to be valid for the system.
*
* Inputs       : timeBaseId: time base reference
*                timeStampPtr: New time stamp
*
* Outputs      : None.
*
* Return       : E_OK: successful 
*                E_NOT_OK: failed
*
* Limitations  : None.
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, STBM_CODE) StbM_SetOffset
(
    StbM_SynchronizedTimeBaseType timeBaseId,
    P2CONST(StbM_TimeStampType, STBM_APPL_CONST, AUTOMATIC) timeStampPtr
)
{
    StbM_SynchronizedTimeBaseType TbIdx;
    Std_ReturnType ret = E_NOT_OK;

    if(!STBM_IS_INITIALIZED())
    {
        /*SWS_StbM_00198*/
        STBM_DET_REPORT_ERROR(STBM_SID_SETOFFSET, STBM_E_NOT_INITIALIZED);
    }
    else if((!STBM_IS_OFFSETTIME_ID(timeBaseId)) || (!STBM_IS_ID_VALID(timeBaseId)))
    {
        /*SWS_StbM_00224*//*SWS_StbM_00191*/
        STBM_DET_REPORT_ERROR(STBM_SID_SETOFFSET, STBM_E_PARAM);
    }
    else if(timeStampPtr == NULL_PTR)
    {
        /*SWS_StbM_00225*/
        STBM_DET_REPORT_ERROR(STBM_SID_SETOFFSET, STBM_E_PARAM_POINTER);
    }
    else
    {
        TbIdx = STBM_ID_TO_INDEX(timeBaseId);
        /*SWS_StbM_00190*/
        STBM_TIME_SECONDSHI(TbIdx) = timeStampPtr->secondsHi;
        STBM_TIME_SECONDS(TbIdx) = timeStampPtr->seconds;
        STBM_TIME_NANOSECONDS(TbIdx) = timeStampPtr->nanoseconds;

        ret = E_OK;
    }

    return ret;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: StbM_GetOffset  SWS_StbM_00228
*
* Description  : Allows the Timebase Provider Modules to get the currentoffset
*                time.
*
* Inputs       : timeBaseId: time base reference
*
* Outputs      : timeStampPtr: Current offset time stamp
*
* Return       : E_OK: successful 
*                E_NOT_OK: failed
*
* Limitations  : None.
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, STBM_CODE) StbM_GetOffset
(
    StbM_SynchronizedTimeBaseType timeBaseId,
    P2VAR(StbM_TimeStampType, AUTOMATIC, STBM_APPL_DATA) timeStampPtr
)
{
    StbM_SynchronizedTimeBaseType TbIdx;
    Std_ReturnType ret = E_NOT_OK;

    if(!STBM_IS_INITIALIZED())
    {
        /*SWS_StbM_00198*/
        STBM_DET_REPORT_ERROR(STBM_SID_GETOFFSET, STBM_E_NOT_INITIALIZED);
    }
    else if((!STBM_IS_OFFSETTIME_ID(timeBaseId)) || (!STBM_IS_ID_VALID(timeBaseId)))
    {
        /*SWS_StbM_00229*//*SWS_StbM_00191*/
        STBM_DET_REPORT_ERROR(STBM_SID_GETOFFSET, STBM_E_PARAM);
    }
    else if(timeStampPtr == NULL_PTR)
    {
        /*SWS_StbM_00230*/
        STBM_DET_REPORT_ERROR(STBM_SID_GETOFFSET, STBM_E_PARAM_POINTER);
    }
    else
    {
        TbIdx = STBM_ID_TO_INDEX(timeBaseId);
        /*SWS_StbM_00192*/
        timeStampPtr->secondsHi = STBM_TIME_SECONDSHI(TbIdx);
        timeStampPtr->seconds = STBM_TIME_SECONDS(TbIdx);
        timeStampPtr->nanoseconds = STBM_TIME_NANOSECONDS(TbIdx);

        ret = E_OK;
    }

    return ret;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: StbM_BusSetGlobalTime  SWS_StbM_00233
*
* Description  : Allows the Timebase Provider Modules to forward a new Global
*                Time to the StbM, which has been received from different busses.
*
* Inputs       : timeBaseId: time base reference
*                timeStampPtr: New time stamp
*                userDataPtr: New user data (if not NULL)
*                syncToTimeBase: SYNC to GTM (0) clear the SYNC_TO_GATEWAY bit
*                within the status SYNC to sub-domain (1) set the SYNC_TO_GATEWAY
*                bit within the status
*
* Outputs      : None.
*
* Return       : E_OK: successful 
*                E_NOT_OK: failed
*
* Limitations  : None.
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, STBM_CODE) StbM_BusSetGlobalTime
(
    StbM_SynchronizedTimeBaseType timeBaseId,
    P2CONST(StbM_TimeStampType, STBM_APPL_CONST, AUTOMATIC) timeStampPtr,
    P2CONST(StbM_UserDataType, STBM_APPL_CONST, AUTOMATIC) userDataPtr,
    boolean syncToTimeBase
)
{
    StbM_SynchronizedTimeBaseType TbIdx;
    StbM_TimeStampType SlaveTimeStamp;
    Std_ReturnType ret = E_NOT_OK;

    if(!STBM_IS_INITIALIZED())
    {
        /*SWS_StbM_00198*/
        STBM_DET_REPORT_ERROR(STBM_SID_BUSSETGLOBALTIME, STBM_E_NOT_INITIALIZED);
    }
    else if((timeBaseId > STBM_TIME_BASE_MAX_ID) || (!STBM_IS_ID_VALID(timeBaseId)))
    {
        /*SWS_StbM_00234*/
        STBM_DET_REPORT_ERROR(STBM_SID_BUSSETGLOBALTIME, STBM_E_PARAM);
    }
    else if(STBM_CFG_TB_IS_MASTER(STBM_ID_TO_INDEX(timeBaseId)) == TRUE)
    {
        STBM_DET_REPORT_ERROR(STBM_SID_BUSSETGLOBALTIME, STBM_E_PARAM);
    }
    else if(timeStampPtr == NULL_PTR)
    {
        /*SWS_StbM_00235*/
        STBM_DET_REPORT_ERROR(STBM_SID_BUSSETGLOBALTIME, STBM_E_PARAM_POINTER);
    }
    else if((userDataPtr != NULL_PTR) && (userDataPtr->userDataLength > STBM_USERDATA_MAX_LENGTH))
    {
        STBM_DET_REPORT_ERROR(STBM_SID_BUSSETGLOBALTIME, STBM_E_PARAM);
    }
    else
    {
        TbIdx = STBM_ID_TO_INDEX(timeBaseId);

        ret = StbM_S_GetBaseTime(timeBaseId, &SlaveTimeStamp);

        if(ret == E_OK)
        {
            /*SWS_StbM_00179*/
            ret = StbM_S_SetBaseTime(timeBaseId, timeStampPtr);
        }
        
        if(ret == E_OK)
        {
            if(STBM_STATUS_GLOBAL_TIME_BASE(TbIdx) == STBM_BIT_SET)
            {
                /*SWS_StbM_00182*//*SWS_StbM_00186*/
                if(TRUE == StbM_S_CheckLossThreshold(timeBaseId, &SlaveTimeStamp, timeStampPtr))
                {
                    STBM_STATUS_TIMELEAP(TbIdx) = STBM_BIT_SET;
                }
                else
                {
                    STBM_STATUS_TIMELEAP(TbIdx) = STBM_BIT_CLR;
                }
            }
            /*SWS_StbM_00183*//*SWS_StbM_00187*/
            STBM_STATUS_TIMEOUT(TbIdx) = STBM_BIT_CLR;

            StbM_S_CopyTimeStamp(&(STBM_LAST_BUSSET_STAMP(TbIdx)), timeStampPtr);
            /*SWS_StbM_00184*//*SWS_StbM_00188*/
            if(syncToTimeBase == TRUE)
            {
                STBM_STATUS_SYNC_TO_GATEWAY(TbIdx) = STBM_BIT_SET;
            }
            else
            {
                STBM_STATUS_SYNC_TO_GATEWAY(TbIdx) = STBM_BIT_CLR;
            }
            /*SWS_StbM_00185*//*SWS_StbM_00189*/
            STBM_STATUS_GLOBAL_TIME_BASE(TbIdx) = STBM_BIT_SET;

            if(userDataPtr != NULL_PTR)
            {
                StbM_S_CopyUserData(&(STBM_USERDATA(TbIdx)), userDataPtr);
            }
        }
    }

    return ret;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: StbM_MainFunction  SWS_StbM_00057
*
* Description  : This function will be called cyclically by a task body provided
*                by the BSW Schedule.
*
* Inputs       : None.
*
* Outputs      : None.
*
* Return       : None.
*
* Limitations  : None.
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, STBM_CODE) StbM_MainFunction
(
    void
)
{
#if(STBM_NUM_OF_TRIGGEREDCUSTOMER > 0)
    StbM_CustomerIdType CustomerId;
#endif
    StbM_SynchronizedTimeBaseType TbId;
    StbM_SynchronizedTimeBaseType TbIdx;
    StbM_TimeStampType CurTimeStamp;
    Std_ReturnType ret = E_OK;

    if(!STBM_IS_INITIALIZED())
    {
        /*SWC_StbM_00198*/
        STBM_DET_REPORT_ERROR(STBM_SID_MAINFUNCTION, STBM_E_NOT_INITIALIZED);
    }
    else
    {
#if(STBM_NUM_OF_TRIGGEREDCUSTOMER > 0)
        /*SWS_StbM_00020 Triggered Customer*//*SWS_StbM_00084*/
        for(CustomerId = 0U; CustomerId < STBM_NUM_OF_TRIGGEREDCUSTOMER; CustomerId++)
        {
            if(STBM_TRIGGERED_TIME(CustomerId) != 0U)
            {
                STBM_TRIGGERED_TIME(CustomerId)--;

                if(STBM_TRIGGERED_TIME(CustomerId) == 0U)
                {
                    STBM_TRIGGERED_TIME(CustomerId) = STBM_CFG_TRIGGER_PERIOD(CustomerId);

                    TbId = STBM_CFG_TRIGGER_TB_REF(CustomerId);
                    TbIdx = STBM_ID_TO_INDEX(TbId);
                    /*SWS_StbM_00077*/
                    if(STBM_STATUS_GLOBAL_TIME_BASE(TbIdx) == STBM_BIT_SET)
                    {
                        StbM_S_TriggeredCustomer(CustomerId);
                    }
                }
            }
        }
#endif

        /*SWS_StbM_00183*//*SWS_StbM_00187*/
        for(TbIdx = 0U; TbIdx < STBM_NUM_OF_TIMEBASE; TbIdx++)
        {
            TbId = STBM_CFG_TB_ID(TbIdx);
            ret = StbM_S_GetBaseTime(TbId, &CurTimeStamp);
            if(ret == E_OK)
            {
                if(STBM_STATUS_TIMEOUT(TbIdx) == STBM_BIT_CLR)
                {
                    if(TRUE == StbM_S_CheckLossTimeout(TbId, &STBM_LAST_BUSSET_STAMP(TbIdx), &CurTimeStamp))
                    {
                        STBM_STATUS_TIMEOUT(TbIdx) = STBM_BIT_SET;
                    }
                }
            }
        }/*for(TbIdx = 0U; TbIdx < STBM_NUM_OF_TIMEBASE; TbIdx++)*/
    }
}

#if(STBM_VERSION_INFO_API == STD_ON)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: StbM_GetVersionInfo   SWS_StbM_00066
*
* Description  : Returns the version information of this module.
*
* Inputs       : None.
*
* Outputs      : versionInfo: Pointer to the memory location holding the version
*                information of the module.
*
* Return       : None.
*
* Limitations  : None.
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, STBM_CODE) StbM_GetVersionInfo
(
    P2VAR(Std_VersionInfoType, AUTOMATIC, STBM_APPL_DATA) versioninfo
)
{
    if(NULL_PTR == versioninfo)
    {
        /*SWS_StbM_00094*/
        STBM_DET_REPORT_ERROR(STBM_SID_GETVERSIONINFO, STBM_E_PARAM_POINTER);
    }
    else
    {
        versioninfo->vendorID = STBM_VENDOR_ID;
        versioninfo->moduleID = STBM_MODULE_ID;

        versioninfo->sw_major_version = STBM_SW_MAJOR_VERSION;
        versioninfo->sw_minor_version = STBM_SW_MINOR_VERSION;
        versioninfo->sw_patch_version = STBM_SW_PATCH_VERSION;
    }
}
#endif/*#if(STBM_VERSION_INFO_API == STD_ON)*/

#define STBM_STOP_SEC_CODE
#include "MemMap.h"

