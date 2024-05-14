/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
*   File Name       : WdgM.c
********************************************************************************
*   Project/Product : AUTOSAR 4.2
*   Title           : Watchdog Manager module Source File
*   Author          : Hirain
********************************************************************************
*   Description     : Watchdog Manager module Source File
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
*   01.00.00    22/07/2015    Ning.Chen      N/A          Beta
*   01.01.00    22/05/2018    Ning.Chen      N/A          Original
*   01.02.00    10/09/2018    Ning.Chen      N/A          EAS422_WDGM_20180910_01
*   01.02.01    01/11/2018    Ning.Chen      N/A          EAS422_WDGM_20181101_01
*   01.02.02    15/07/2019    Ning.Chen      N/A          EAS422_WDGM_20190715_01
*   01.02.03    16/04/2021    Heyan.Li       N/A          EAS422_WDGM_20210416_01
*   01.02.04    11/06/2021    Boxue.Li       N/A          EAS422_WDGM_20210611_01
********************************************************************************
* END_FILE_HDR*/

/*******************************************************************************
*   Includes
*******************************************************************************/
#include "WdgM.h"

#include "SchM_WdgM.h"
#if(STD_ON == WDGM_DEV_ERROR_DETECT)
#include "Det.h"
#endif

/*******************************************************************************
*   Version Check
*******************************************************************************/
#if(STD_ON == WDGM_PRIVATE_VERSION_CHECK)
/* check Version with other import module */

/* check Version with cfg file */
#if ((WDGM_AR_RELEASE_MAJOR_VERSION != WDGM_AR_RELEASE_MAJOR_VERSION_CFG) || \
   (WDGM_AR_RELEASE_MINOR_VERSION != WDGM_AR_RELEASE_MINOR_VERSION_CFG))
#error "AutoSar Version Numbers of WDGM and its cfg file are different"
#endif

#if ((WDGM_SW_MAJOR_VERSION != WDGM_SW_MAJOR_VERSION_CFG) || \
   (WDGM_SW_MINOR_VERSION != WDGM_SW_MINOR_VERSION_CFG))
#error "SW Version Numbers of WDGM and its cfg file are different"
#endif


#endif/*#if(STD_ON == WDGM_PRIVATE_VERSION_CHECK)*/


/*******************************************************************************
*   Macro
*******************************************************************************/
#if(STD_ON == WDGM_DEV_ERROR_DETECT)

#define  WDGM_DET_REPORT_ERROR(ApiId, errcode)  \
    DET_REPORT_ERROR(WDGM_MODULE_ID_VALUE, WDGM_INSTANCE_ID_VALUE_0, (ApiId), (errcode))

#else

#define  WDGM_DET_REPORT_ERROR(ApiId, errcode)

#endif

#if(STD_OFF == WDGM_BSWM_USED)
#define WDGM_BSWM_REPORT(app)
#else
#define WDGM_BSWM_REPORT(app)  BswM_WdgM_RequestPartitionReset(app)
#endif

#if(STD_OFF == WDGM_DEM_USED)
#define WDGM_DEM_REPORT(eventId,status)
#else
#define WDGM_DEM_REPORT(eventId,status)  Dem_ReportErrorStatus(eventId,status)
#endif



/*******************************************************************************
*   Local Data Define
*******************************************************************************/
#define WDGM_START_SEC_VAR_INIT_8
#include "MemMap.h"

STATIC VAR(Std_InitStateType, WDGM_VAR)  WdgM_InitStatus = STD_UNINITIALIZED;

#define WDGM_STOP_SEC_VAR_INIT_8
#include "MemMap.h"


#define WDGM_START_SEC_VAR_NOINIT_8
#include "MemMap.h"

STATIC VAR(WdgM_ModeType, WDGM_VAR)  WdgM_runTimeModeIndex;
STATIC VAR(WdgM_GlobalStatusType, WDGM_VAR)  WdgM_GlobalMonitoringStatus;


#define WDGM_STOP_SEC_VAR_NOINIT_8
#include "MemMap.h"


#define WDGM_START_SEC_VAR_NOINIT_16
#include "MemMap.h"

STATIC VAR(uint16, WDGM_VAR)  WdgM_GStatusExpired_Cnt;
STATIC VAR(WdgM_SupervisedEntityIdType, WDGM_VAR)  WdgM_FirstExpSeId;
STATIC VAR(WdgM_SupervisedEntityIdType, WDGM_VAR)  WdgM_FirstExpSeIdInv;

#define WDGM_STOP_SEC_VAR_NOINIT_16
#include "MemMap.h"



#define WDGM_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"

STATIC P2CONST(WdgM_ConfigType, WDGM_VAR_NOINIT, WDGM_CONST) WdgM_runTimeConfig;

STATIC P2CONST(WdgM_ModeCfgType, WDGM_VAR_NOINIT, WDGM_CONST) WdgM_runTimeMode;


#define WDGM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"


/*******************************************************************************
*   Private Function Define
*******************************************************************************/
#define WDGM_START_SEC_CODE
#include "MemMap.h"
#if(STD_OFF == WDGM_OFF_MODE_ENABLED)
STATIC FUNC(boolean, WDGM_CODE)  WdgM_HasWdgOffMode(void);
#endif
STATIC FUNC(void, WDGM_CODE) WdgM_setWdgMode(void);
STATIC FUNC(void, WDGM_CODE) WdgM_setTriggerValue(void);
#if(WDGM_TOTAL_FLOW_NUM > 0)
STATIC FUNC(void, WDGM_CODE) WdgM_ResetFlow(void);
#endif

#if(WDGM_TOTAL_ALIVE_NUM > 0)
STATIC FUNC(void, WDGM_CODE) WdgM_ResetAliveMonitor(void);
#endif

#if(WDGM_TOTAL_DEADLINE_NUM > 0)
STATIC FUNC(void, WDGM_CODE) WdgM_ResetDeadlineMonitor(void);
#endif

#if(WDGM_TOTAL_FLOW_NUM > 0)
STATIC FUNC(void, WDGM_CODE)  WdgM_TransitionCheck
(
    WdgM_SupervisedEntityIdType SEID,
    WdgM_CheckpointIdType CheckpointID
);
#endif

#if(WDGM_TOTAL_ALIVE_NUM > 0)
STATIC FUNC(void, WDGM_CODE)  WdgM_AliveMonitorMainFunction(void);
#endif

STATIC FUNC(void, WDGM_CODE)  WdgM_UpdateGlobalStatus(void);
STATIC FUNC(void, WDGM_CODE)  WdgM_UpdateLocalStatus(void);
STATIC FUNC(boolean, WDGM_CODE)   WdgM_IsSEActiveInCurrentMode
(
    WdgM_SupervisedEntityIdType se
);

STATIC FUNC(void, WDGM_CODE)  WdgM_ChangeLocalMode
(
    WdgM_SupervisedEntityIdType  seid,
    WdgM_LocalStatusType status
);
STATIC FUNC(void, WDGM_CODE)  WdgM_ChangeGlobalMode
(
    WdgM_GlobalStatusType status
);

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: WdgM_ChangeLocalMode
*
* Description:   update local se's status,and indication to rte
*
* Inputs:        seid ,status
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, WDGM_CODE)  WdgM_ChangeLocalMode
(
    WdgM_SupervisedEntityIdType  seid,
    WdgM_LocalStatusType status
)
{
    if(status != WdgM_LocalMonitoringStatus[seid])
    {
        WdgM_LocalMonitoringStatus[seid] = status;
        if(NULL_PTR != WdgMSupervisedEntity[seid].seModeInd)
        {
            (void)WdgMSupervisedEntity[seid].seModeInd(status); /*SWS_WdgM_00197*/
        }
    }
}


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: WdgM_ChangeGlobalMode
*
* Description:   update global  status,and indication to rte
*
* Inputs:        None
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, WDGM_CODE)  WdgM_ChangeGlobalMode
(
    WdgM_GlobalStatusType status
)
{
#if(STD_ON == WDGM_IMMEDIATE_RESET)
    if(WDGM_GLOBAL_STATUS_STOPPED == status) 
    {
        /* perform immediate reset SWS_WdgM_00133 134 dont notification if immReset */
        Mcu_PerformReset();
    }
#endif


    if(status != WdgM_GlobalMonitoringStatus)
    {
        WdgM_GlobalMonitoringStatus = status;
        if(NULL_PTR != WdgM_GlobalStatusInd)
        {
            (void)WdgM_GlobalStatusInd(status); /*SWS_WdgM_00198 199*/
        }
    }

}


#if(STD_OFF == WDGM_OFF_MODE_ENABLED)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: WdgM_HasWdgOffMode
*
* Description:   check if current  wdgM mode has wdg off mode
*
* Inputs:        None
*
* Outputs:       boolean
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(boolean, WDGM_CODE)  WdgM_HasWdgOffMode(void)
{
    boolean retValue = FALSE;
    uint8 index;

    for(index = ((uint8)0); index < WdgM_runTimeMode->numOfTrigger; index++)
    {
        if(WDGIF_OFF_MODE == WdgM_runTimeMode->WdgMTrigger[index].WdgMWatchdogMode)
        {
            retValue = TRUE;
            break;
        }
    }


    return  retValue;
}
#endif

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: WdgM_setWdgMode
*
* Description:   Called in Init and SetMode,
*                when new WdgM Mode is entered, new wdg Mode need to be set
* Inputs:        None
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, WDGM_CODE) WdgM_setWdgMode(void)
{
    uint8 dogIndex;
    Std_ReturnType ret = E_NOT_OK;
    P2CONST(WdgM_TriggerType, AUTOMATIC, WDGM_CONST) dog = NULL_PTR;

    /* switch dog mode */
    for(dogIndex = ((uint8)0); dogIndex < WdgM_runTimeMode->numOfTrigger; dogIndex++)
    {
        dog = &(WdgM_runTimeMode->WdgMTrigger[dogIndex]);
        ret = WdgIf_SetMode(dog->WdgMWatchdogDeviceRef, dog->WdgMWatchdogMode);

        if(E_NOT_OK == ret)
        {
            /*SWS_WdgM_00186 if mode switch failed, set global status stop and reset */
            WdgM_ChangeGlobalMode(WDGM_GLOBAL_STATUS_STOPPED);

            WDGM_DEM_REPORT(WdgM_runTimeConfig->setModeEventId, DEM_EVENT_STATUS_FAILED);



            break;
        }
    }

}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: WdgM_setTriggerValue
*
* Description:   Called in Mainfunction,
*
* Inputs:        None
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, WDGM_CODE) WdgM_setTriggerValue(void)
{
    uint8 dogIndex;
#if(WDGM_WDG_DEVICE_NUM > 1)
    uint8 dogDevice;
#endif
    uint16 value;

    /*  SWS_WdgM_00223
        DEACTIVATED dont call  WdgIf_SetTriggerCondition
        SWS_WdgM_00122 stop trigger 0
        SWS_WdgM_00120 121 other trigger normal

        SWS_WdgM_00119 not triiger off mode dog
    */
    if(WDGM_GLOBAL_STATUS_DEACTIVATED != WdgM_GlobalMonitoringStatus)
    {
        for(dogIndex = ((uint8)0); dogIndex < WdgM_runTimeMode->numOfTrigger; dogIndex++)
        {
            if(WDGIF_OFF_MODE != WdgM_runTimeMode->WdgMTrigger[dogIndex].WdgMWatchdogMode)
            {
#if(WDGM_WDG_DEVICE_NUM > 1)
                dogDevice =  WdgM_runTimeMode->WdgMTrigger[dogIndex].WdgMWatchdogDeviceRef;
#endif
                value =  WdgM_runTimeMode->WdgMTrigger[dogIndex].WdgMTriggerConditionValue;

                if(WDGM_GLOBAL_STATUS_STOPPED == WdgM_GlobalMonitoringStatus)
                {
                    value = ((uint16)0);
                }

                WdgIf_SetTriggerCondition(dogDevice, value);
            }
        }
    }
}


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: WdgM_ResetFlow
*
* Description:   Init flow related sw vars
*
* Inputs:        None
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
#if(WDGM_TOTAL_FLOW_NUM > 0)
STATIC FUNC(void, WDGM_CODE) WdgM_ResetFlow(void)
{
    uint16 i;

    for(i = ((uint16)0); i < WDGM_USED_FLOW_NUM; i++)
    {
        WdgM_FlowActiveFlag[i] = FALSE;
        WdgM_LastCP[i] = WDGM_INVALID_CP;
    }

}
#endif

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: WdgM_ResetAliveMonitor
*
* Description:   Init alive related sw vars
*
* Inputs:        None
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
#if(WDGM_TOTAL_ALIVE_NUM > 0)
STATIC FUNC(void, WDGM_CODE) WdgM_ResetAliveMonitor(void)
{
    uint16 i;

    for(i = ((uint16)0); i < WDGM_USED_ALIVE_NUM; i++)
    {
        WdgM_AliveCycle[i] = ((uint16)0);
        WdgM_AliveCnt[i] = ((uint16)0);
    }
    for(i = ((uint16)0); i < WDGM_TOTAL_SE_NUM; i++)
    {
        WdgM_LocalFailedCnt[i] = ((uint8)0);
    }

}
#endif


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: WdgM_ResetDeadlineMonitor
*
* Description:   Init deadline related sw vars
*
* Inputs:        None
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
#if(WDGM_TOTAL_DEADLINE_NUM > 0)
STATIC FUNC(void, WDGM_CODE) WdgM_ResetDeadlineMonitor(void)
{
    uint16 i;

    for(i = ((uint16)0); i < WDGM_USED_DEADLINE_NUM; i++)
    {
        WdgM_DeadlineState[i] = WDGM_DEADLINE_INACTIVE;
        WdgM_DeadlineSavedTick[i] = ((TickType)0);
    }
}
#endif



/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: WdgM_TransitionCheck
*
* Description:   Called only in WdgM_CheckpointReached, check tr
*
* Inputs:        None
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
#if(WDGM_TOTAL_FLOW_NUM > 0)
STATIC FUNC(void, WDGM_CODE)  WdgM_TransitionCheck
(
    WdgM_SupervisedEntityIdType SEID,
    WdgM_CheckpointIdType CheckpointID
)
{
    WdgM_CheckpointIdType srcCP;
    uint16 start;
    uint16 end ;
    uint16 i;
    boolean hasValidTr = FALSE;

    uint16 flowIndex;
    P2CONST(WdgM_CheckpointIdType, AUTOMATIC, WDGM_CONST) flowPtr = NULL_PTR;


    uint8 flowCpType;

    /* decide the flow this cp belongs to
       if ext flow , use ext flow first,
       if no ext flow , use internal flow ,
    */

    /*SWS_WdgM_00295*/
    if(NULL_PTR != WdgM_runTimeMode->WdgCpInMode[CheckpointID].FlowPtr)
    {
        flowPtr = WdgM_runTimeMode->WdgCpInMode[CheckpointID].FlowPtr;
        flowCpType = WdgM_runTimeMode->WdgCpInMode[CheckpointID].flowCpType;
        start = WdgM_runTimeMode->WdgCpInMode[CheckpointID].trOffset;
        end = start + WdgM_runTimeMode->WdgCpInMode[CheckpointID].trNum;
        flowIndex = WdgM_runTimeMode->WdgCpInMode[CheckpointID].flowIndex;
    }
    else if(NULL_PTR != WdgMCheckPoint[CheckpointID].FlowPtr)
    {
        flowPtr = WdgMCheckPoint[CheckpointID].FlowPtr;
        flowCpType = WdgMCheckPoint[CheckpointID].flowCpType;
        start = WdgMCheckPoint[CheckpointID].trOffset;
        end = start + WdgMCheckPoint[CheckpointID].trNum;
        flowIndex = WdgMCheckPoint[CheckpointID].flowIndex;

    }
    else
    {
        /* no flow check for this cp */
    }

    /*SWS_WdgM_00274 252*/
    if(NULL_PTR != flowPtr)
    {

        if(FALSE == WdgM_FlowActiveFlag[flowIndex])
        {
            if(WDGM_CP_FLOW_INIT == flowCpType)
            {
                WdgM_FlowActiveFlag[flowIndex] = TRUE;/*SWS_WdgM_00332 273*/
            }
            else
            {
                WdgM_ErrFlag[SEID] |= WDGM_FLOW_ERROR;
            }

        }
        else
        {
            srcCP = WdgM_LastCP[flowIndex];
            for(i = start; i < end; i++)
            {
                if(srcCP == flowPtr[i])
                {
                    hasValidTr = TRUE;
                    break;
                }
            }

            if(FALSE == hasValidTr)
            {
                WdgM_ErrFlag[SEID] |= WDGM_FLOW_ERROR;
            }

            if(WDGM_CP_FLOW_END == flowCpType)
            {
                WdgM_FlowActiveFlag[flowIndex] = FALSE;/*SWS_WdgM_00331 329*/
            }
        }
        /*SWS_WdgM_00246*/
        WdgM_LastCP[flowIndex] = CheckpointID;
    }


}
#endif



/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: WdgM_AliveMonitorMainFunction
*
* Description:   Called only in mainfuntion, do the alive check alg
*
* Inputs:        None
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/

#if(WDGM_TOTAL_ALIVE_NUM > 0)
STATIC FUNC(void, WDGM_CODE)  WdgM_AliveMonitorMainFunction(void)
{

    WdgM_CheckpointIdType cpId;
    WdgM_SupervisedEntityIdType seId;


    uint16 aliveIndex;
    uint16 maxAliveInMode = WdgM_runTimeMode->numOfAlive;
    P2CONST(WdgM_AliveSupervisionType, AUTOMATIC, WDGM_CONST) alive = NULL_PTR;


    for(aliveIndex = ((uint16)0); aliveIndex < maxAliveInMode; aliveIndex++)
    {

        alive = &WdgM_runTimeMode->WdgMAliveSupervision[aliveIndex];

        cpId = alive->WdgMAliveSupervisionCheckpointRef;
        seId = WdgMCheckPoint[cpId].seRef;

        /*SWS_WdgM_00074 115*/
        if((WDGM_LOCAL_STATUS_DEACTIVATED != WdgM_LocalMonitoringStatus[seId])
                && (WDGM_LOCAL_STATUS_EXPIRED != WdgM_LocalMonitoringStatus[seId]))
        {
            if(WdgM_AliveCycle[aliveIndex] < alive->WdgMSupervisionReferenceCycle)
            {
                WdgM_AliveCycle[aliveIndex]++;
            }

            if(WdgM_AliveCycle[aliveIndex] >= alive->WdgMSupervisionReferenceCycle) /*SWS_WdgM_00098*/
            {
                WdgM_ErrFlag[seId] |= WDGM_ALIVE_ERROR_TEMP;
                if((WdgM_AliveCnt[aliveIndex] < alive->WdgMMinMargin)
                        || (WdgM_AliveCnt[aliveIndex] > alive->WdgMMaxMargin))
                {
                    WdgM_ErrFlag[seId] |= WDGM_ALIVE_ERROR;
                }
                WdgM_AliveCycle[aliveIndex] = ((uint16)0);
                WdgM_AliveCnt[aliveIndex] = ((uint16)0);
            }

        }

    }

}
#endif



/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: WdgM_UpdateGlobalStatus
*
* Description:   Called in mainfuntion and setMode, update global status
*
* Inputs:        None
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, WDGM_CODE)  WdgM_UpdateGlobalStatus(void)
{
    WdgM_SupervisedEntityIdType seCnt;
    boolean expiredFlag = FALSE;
    boolean failFlag = FALSE;

    /*SWS_WdgM_00078 76 215 217 218 77 117 219*/

    /* update globa status based on all se's status*/
    /* there may be expire se in other mode's se*/
    for(seCnt = ((WdgM_SupervisedEntityIdType)0); seCnt < WDGM_TOTAL_SE_NUM; seCnt++)
    {
        if(WdgM_LocalMonitoringStatus[seCnt] == WDGM_LOCAL_STATUS_EXPIRED)
        {
            expiredFlag = TRUE;
            break;
        }

        if(WdgM_LocalMonitoringStatus[seCnt] == WDGM_LOCAL_STATUS_FAILED)
        {
            failFlag = TRUE;
        }

    }


    /* change global status based on all se's status*/
    if(TRUE == expiredFlag)
    {
        if(((uint16)0) == WdgM_runTimeMode->WdgMExpiredSupervisionCycleTol)
        {
            WdgM_ChangeGlobalMode(WDGM_GLOBAL_STATUS_STOPPED);
        }
        else
        {
            /* expired will be switch to stop after time out*/
            WdgM_ChangeGlobalMode(WDGM_GLOBAL_STATUS_EXPIRED);
        }
    }
    else
    {
        if(TRUE == failFlag)
        {
            WdgM_ChangeGlobalMode(WDGM_GLOBAL_STATUS_FAILED);
        }
        else
        {
            WdgM_ChangeGlobalMode(WDGM_GLOBAL_STATUS_OK);
        }
    }


}



/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: WdgM_UpdateLocalStatus
*
* Description:   Called only in mainfuntion, update se's local status of active mode
*
* Inputs:        None
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, WDGM_CODE)  WdgM_UpdateLocalStatus(void)
{
    WdgM_SupervisedEntityIdType seCnt = ((WdgM_SupervisedEntityIdType)0);
    WdgM_SupervisedEntityIdType seindex = ((WdgM_SupervisedEntityIdType)0);


    for(seCnt = ((WdgM_SupervisedEntityIdType)0); seCnt < WdgM_runTimeMode->numOfLocalStatus; seCnt++)
    {
        seindex = WdgM_runTimeMode->WdgMLocalStatusParams[seCnt].WdgMLocalStatusSupervisionEntityRef;

        /*SWS_WdgM_00202 203 204 205 300 206*/
        if(((uint8)0) != ((uint8)(WdgM_ErrFlag[seindex] & WDGM_FLOW_DEAFLINE_MASK)))
        {
            /*flow or deadline err, */
            WdgM_ChangeLocalMode(seindex, WDGM_LOCAL_STATUS_EXPIRED);
#if(WDGM_TOTAL_ALIVE_NUM > 0)
            WdgM_LocalFailedCnt[seindex] = ((uint8)0);
#endif
        }
#if(WDGM_TOTAL_ALIVE_NUM > 0)
        else
        {

            /* alive err */
            if(((uint8)0) != ((uint8)(WdgM_ErrFlag[seindex] & WDGM_ALIVE_ERROR_TEMP)))
            {
                if(((uint8)0) != ((uint8)(WdgM_ErrFlag[seindex] & WDGM_ALIVE_ERROR)))
                {
                    if(WdgM_LocalFailedCnt[seindex] < WdgM_runTimeMode->WdgMLocalStatusParams[seCnt].WdgMFailedAliveSupervisionRefCycleTol)
                    {
                        WdgM_LocalFailedCnt[seindex]++;
                    }
                    
                    if(WdgM_LocalFailedCnt[seindex] >= WdgM_runTimeMode->WdgMLocalStatusParams[seCnt].WdgMFailedAliveSupervisionRefCycleTol)
                    {
                        WdgM_LocalFailedCnt[seindex] = ((uint8)0);
                        WdgM_ChangeLocalMode(seindex, WDGM_LOCAL_STATUS_EXPIRED);

                    }
                    else
                    {
                        WdgM_ChangeLocalMode(seindex, WDGM_LOCAL_STATUS_FAILED);
                        WDGM_BSWM_REPORT(WdgMSupervisedEntity[seindex].WdgMOsApplicationRef);
                    }
                }
                else
                {
                    /* no alive err for this cycle */
                    if(WDGM_LOCAL_STATUS_FAILED == WdgM_LocalMonitoringStatus[seindex])
                    {
                        if(WdgM_LocalFailedCnt[seindex] > ((uint8)0))
                        {
                            WdgM_LocalFailedCnt[seindex]--;
                        }
                        if(((uint8)0) == WdgM_LocalFailedCnt[seindex])
                        {
                            WdgM_ChangeLocalMode(seindex, WDGM_LOCAL_STATUS_OK);

                        }
                    }
                }
            }
        }
#endif
        WdgM_ErrFlag[seindex] = WDGM_NO_ERROR;



        if(WDGM_LOCAL_STATUS_EXPIRED == WdgM_LocalMonitoringStatus[seindex])
        {
            /* SWS_WdgM_00351 check if this is the first expired se, and save it*/
            if(WdgM_FirstExpSeId != (WdgM_SupervisedEntityIdType)(~WdgM_FirstExpSeIdInv))
            {
                WdgM_FirstExpSeId = seindex;
                WdgM_FirstExpSeIdInv = (WdgM_SupervisedEntityIdType)(~seindex);
            }
        }
    }

}


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: WdgM_IsSEActiveInCurrentMode
*
* Description:   Called only in mainfuntion, update se's local status of active mode
*
* Inputs:        None
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(boolean, WDGM_CODE)   WdgM_IsSEActiveInCurrentMode
(
    WdgM_SupervisedEntityIdType se
)
{
    boolean ret = FALSE;
    WdgM_SupervisedEntityIdType i;

    for(i = ((WdgM_SupervisedEntityIdType)0); i < WdgM_runTimeMode->numOfLocalStatus; i++)
    {
        if(se == WdgM_runTimeMode->WdgMLocalStatusParams[i].WdgMLocalStatusSupervisionEntityRef)
        {
            ret = TRUE;
            break;
        }
    }
    return ret;
}


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: WdgM_Init  SWS_WdgM_00151
*
* Description:   Wdg Manager Init
*
* Inputs:        ConfigPtr
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, WDGM_CODE)  WdgM_Init
(
    P2CONST(WdgM_ConfigType, AUTOMATIC, WDGM_CONST)  ConfigPtr
)
{
    WdgM_SupervisedEntityIdType i = ((WdgM_SupervisedEntityIdType)0);

    if(STD_UNINITIALIZED != WdgM_InitStatus)
    {
        WDGM_DET_REPORT_ERROR(WDGM_INIT_APIID, WDGM_E_NO_INIT);
    }
#if(WDGM_CONFIG_VARIANTS == STD_CONFIG_VARIANTS_POSTBUILD)
    else if(NULL_PTR == ConfigPtr)
    {
        WDGM_DET_REPORT_ERROR(WDGM_INIT_APIID, WDGM_E_NULL_POINTER);
    }
#endif
    else
    {

        /*SWS_WdgM_00018*/
#if(WDGM_CONFIG_VARIANTS != STD_CONFIG_VARIANTS_POSTBUILD)
        (void) ConfigPtr;
        WdgM_runTimeConfig = &WdgM_Config[0];
#else
        WdgM_runTimeConfig = ConfigPtr;
#endif


        /*SWS_WdgM_00010*/
        if(WdgM_runTimeConfig->WdgMInitialMode >= WdgM_runTimeConfig->WdgMNumOfMode)
        {
            WDGM_DET_REPORT_ERROR(WDGM_INIT_APIID, WDGM_E_PARAM_CONFIG);
        }
        else
        {
            WdgM_runTimeModeIndex = WdgM_runTimeConfig->WdgMInitialMode;
            WdgM_runTimeMode = &WdgM_runTimeConfig->WdgMMode[WdgM_runTimeModeIndex];


#if(STD_OFF == WDGM_OFF_MODE_ENABLED)
            if(TRUE == WdgM_HasWdgOffMode())/*SWS_WdgM_00030*/
            {
                WDGM_DET_REPORT_ERROR(WDGM_INIT_APIID, WDGM_E_DISABLE_NOT_ALLOWED);
            }
            else
#endif
            {

                /* first set all state to deactive, then set ok, this will cause mode indication to rte*/
                for(i = ((WdgM_SupervisedEntityIdType)0); i < WDGM_TOTAL_SE_NUM; i++)
                {
                    WdgM_LocalMonitoringStatus[i] = WDGM_LOCAL_STATUS_DEACTIVATED;
                }
                WdgM_GlobalMonitoringStatus = WDGM_GLOBAL_STATUS_DEACTIVATED;


                /* SWS_WdgM_00269 reset all se's local status  */
                for(i = ((WdgM_SupervisedEntityIdType)0); i < WDGM_TOTAL_SE_NUM; i++)
                {
                    if(TRUE == WdgM_IsSEActiveInCurrentMode(i))
                    {
                        /* SWS_WdgM_00268 active se of init mode */
                        WdgM_ChangeLocalMode(i, WDGM_LOCAL_STATUS_OK);
                    }

                    WdgM_ErrFlag[i] = ((uint8)0);
                }


                /* global variable */
                WdgM_GStatusExpired_Cnt = ((uint16)0);
                WdgM_ChangeGlobalMode(WDGM_GLOBAL_STATUS_OK);/*SWS_WdgM_00285*/

#if(WDGM_TOTAL_FLOW_NUM > 0)/*SWS_WdgM_00296*/
                WdgM_ResetFlow();
#endif

                /* alive */
#if(WDGM_TOTAL_ALIVE_NUM > 0)
                WdgM_ResetAliveMonitor();
#endif

                /* deadline SWS_WdgM_00298*/
#if(WDGM_TOTAL_DEADLINE_NUM > 0)
                WdgM_ResetDeadlineMonitor();
#endif
                /*SWS_WdgM_00370*/
                WdgM_FirstExpSeId = ((WdgM_SupervisedEntityIdType)0);
                WdgM_FirstExpSeIdInv = ((WdgM_SupervisedEntityIdType)0);


                /* switch dog mode */
                WdgM_setWdgMode();


                WdgM_InitStatus = STD_INITIALIZED;/*SWS_WdgM_00135*/
            }
        }

    }

}


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: WdgM_DeInit  SWS_WdgM_00261
*
* Description:   Wdg Manager DeInit
*
* Inputs:        None
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, WDGM_CODE) WdgM_DeInit(void)
{
    WdgM_SupervisedEntityIdType i;

    if(STD_INITIALIZED != WdgM_InitStatus)
    {
        WDGM_DET_REPORT_ERROR(WDGM_DEINIT_APIID, WDGM_E_NO_INIT);
    }
    else
    {

        SchM_Enter_WdgM_WDGM_EXCLUSIVE_AREA_0();
        /*set all dog's trigger condition to configvalue,
        application may need time to do some jobs before dog reset
        see Asr Spec before SWS_WdgM_00288
        */
        WdgM_setTriggerValue();

        WdgM_runTimeConfig = NULL_PTR;
        WdgM_runTimeModeIndex = WDGM_UNUSED_MODE;
        WdgM_runTimeMode = NULL_PTR;

        /* local se variable */
        for(i = ((WdgM_SupervisedEntityIdType)0); i < WDGM_TOTAL_SE_NUM; i++)
        {
            WdgM_ChangeLocalMode(i, WDGM_LOCAL_STATUS_DEACTIVATED);
            WdgM_ErrFlag[0] = WDGM_NO_ERROR;
        }

        /* global variable */
        WdgM_GStatusExpired_Cnt = ((uint16)0);
        WdgM_ChangeGlobalMode(WDGM_GLOBAL_STATUS_DEACTIVATED);/*SWS_WdgM_00286*/


#if(WDGM_TOTAL_FLOW_NUM > 0)
        WdgM_ResetFlow();
#endif

        /* alive */
#if(WDGM_TOTAL_ALIVE_NUM > 0)
        WdgM_ResetAliveMonitor();
#endif

        /* deadline */
#if(WDGM_TOTAL_DEADLINE_NUM > 0)
        WdgM_ResetDeadlineMonitor();
#endif

        WdgM_FirstExpSeId = ((WdgM_SupervisedEntityIdType)0);
        WdgM_FirstExpSeIdInv = ((WdgM_SupervisedEntityIdType)0);

        WdgM_InitStatus = STD_UNINITIALIZED;
        SchM_Exit_WdgM_WDGM_EXCLUSIVE_AREA_0();
    }
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: WdgM_SetMode  SWS_WdgM_00154
*
* Description:   Sets the current mode of Watchdog Manager.
*
* Inputs:        Mode, CallerID
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, WDGM_CODE)  WdgM_SetMode
(
    WdgM_ModeType Mode,
    uint16 CallerID
)
{
    Std_ReturnType ret = E_NOT_OK;
    WdgM_SupervisedEntityIdType i;

    /*SWS_WdgM_00020 21*/
    if(STD_INITIALIZED != WdgM_InitStatus)
    {
        WDGM_DET_REPORT_ERROR(WDGM_SETMODE_APIID, WDGM_E_NO_INIT);
    }
    else if(Mode >= WdgM_runTimeConfig->WdgMNumOfMode)
    {
        WDGM_DET_REPORT_ERROR(WDGM_SETMODE_APIID, WDGM_E_PARAM_MODE);
    }
#if(STD_OFF == WDGM_OFF_MODE_ENABLED)
    else if(TRUE == WdgM_HasWdgOffMode())/*SWS_WdgM_00031*/
    {
        WDGM_DET_REPORT_ERROR(WDGM_SETMODE_APIID, WDGM_E_DISABLE_NOT_ALLOWED);
    }
#endif
    else
    {
        (void)CallerID;/* obsolete SWS_WdgM_00245*/

        SchM_Enter_WdgM_WDGM_EXCLUSIVE_AREA_0();

        if((WdgM_GlobalMonitoringStatus == WDGM_GLOBAL_STATUS_OK)
                || (WdgM_GlobalMonitoringStatus == WDGM_GLOBAL_STATUS_FAILED)) /*SWS_WdgM_00145 316*/
        {

            WdgM_runTimeModeIndex = Mode;
            WdgM_runTimeMode = &WdgM_runTimeConfig->WdgMMode[Mode];

            /*SWS_WdgM_00182:if SE is both actived in old and new mode, this SE's status cannot be changed
              only start a new monitor cycle
            */

            for(i = ((WdgM_SupervisedEntityIdType)0); i < WDGM_TOTAL_SE_NUM; i++)
            {
                /*SWS_WdgM_00207 SWS_WdgM_00291, only ok or failed se canbe change to deactive
                  expired will keep unchange
                */
                if(FALSE == WdgM_IsSEActiveInCurrentMode(i))
                {
                    if(WdgM_LocalMonitoringStatus[i] < WDGM_LOCAL_STATUS_EXPIRED)
                    {
                        WdgM_ChangeLocalMode(i, WDGM_LOCAL_STATUS_DEACTIVATED);

                    }
                }
                else
                {
                    /*SWS_WdgM_00209 , if new mode has the se, se will be set ok,
                    but if old state is expired, this will not change*/
                    if(WdgM_LocalMonitoringStatus[i] == WDGM_LOCAL_STATUS_DEACTIVATED)
                    {
                        WdgM_ChangeLocalMode(i, WDGM_LOCAL_STATUS_OK);
                    }
                }

                WdgM_ErrFlag[i] = WDGM_NO_ERROR;
            }

            /* updata global status, may have fail SE */
            WdgM_UpdateGlobalStatus();

#if(WDGM_TOTAL_FLOW_NUM > 0)
            WdgM_ResetFlow();
#endif

            /* alive */
#if(WDGM_TOTAL_ALIVE_NUM > 0)
            WdgM_ResetAliveMonitor();
#endif

            /* deadline */
#if(WDGM_TOTAL_DEADLINE_NUM > 0)
            WdgM_ResetDeadlineMonitor();
#endif

            WdgM_setWdgMode();

            ret = E_OK;


        }
        SchM_Exit_WdgM_WDGM_EXCLUSIVE_AREA_0();

    }

    return ret;

}


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: WdgM_GetMode SWS_WdgM_00168
*
* Description:   Returns the current mode of the Watchdog Manager.
*
* Inputs:        Mode
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, WDGM_CODE)  WdgM_GetMode
(
    P2VAR(WdgM_ModeType, AUTOMATIC, WDGM_APPL_DATA) Mode
)
{
    Std_ReturnType ret = E_NOT_OK;

    /*SWS_WdgM_00253 SWS_WdgM_00254*/
    if(STD_INITIALIZED != WdgM_InitStatus)
    {
        WDGM_DET_REPORT_ERROR(WDGM_GETMODE_APIID, WDGM_E_NO_INIT);
    }
    else if(NULL_PTR == Mode)
    {
        WDGM_DET_REPORT_ERROR(WDGM_GETMODE_APIID, WDGM_E_NULL_POINTER);
    }
    else
    {
        *Mode = WdgM_runTimeModeIndex ; /*SWS_WdgM_00170*/
        ret = E_OK;
    }

    return ret;

}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: WdgM_CheckpointReached
*
* Description:   Indicates to the Watchdog Manager that a Checkpoint within a
*                Supervised Entity has been reached.
*
* Inputs:        SEID  CheckpointID
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, WDGM_CODE)  WdgM_CheckpointReached
(
    WdgM_SupervisedEntityIdType SEID,
    WdgM_CheckpointIdType CheckpointID
)
{
    Std_ReturnType ret = E_NOT_OK;

#if(WDGM_TOTAL_ALIVE_NUM > 0)
    uint16 aliveIndex;
#endif

#if(WDGM_TOTAL_DEADLINE_NUM > 0)
    uint16 deadlineIndex ;
    CounterType cntIndex;
    TickType eTick;
    uint16 deadlineCnt;
    P2CONST(WdgM_DeadlineSupervisionType, AUTOMATIC, WDGM_CONST) deadlinePtr = NULL_PTR;
#endif

    P2CONST(WdgM_CheckPointInModeCfgType, AUTOMATIC, WDGM_CONST) cpModeCfg = NULL_PTR;


    if(STD_INITIALIZED != WdgM_InitStatus)
    {
        WDGM_DET_REPORT_ERROR(WDGM_CPREACH_APIID, WDGM_E_NO_INIT);
    }
    else if(SEID >= WDGM_TOTAL_SE_NUM)
    {
        WDGM_DET_REPORT_ERROR(WDGM_CPREACH_APIID, WDGM_E_PARAM_SEID);
    }
    else if(CheckpointID >= WDGM_TOTAL_CP_NUM)
    {
        WDGM_DET_REPORT_ERROR(WDGM_CPREACH_APIID, WDGM_E_CPID);
    }
    else if(WdgM_LocalMonitoringStatus[SEID] == WDGM_LOCAL_STATUS_DEACTIVATED)/*SWS_WdgM_00319*/
    {
        WDGM_DET_REPORT_ERROR(WDGM_CPREACH_APIID, WDGM_E_SEDEACTIVATED);
    }
    else
    {
        SchM_Enter_WdgM_WDGM_EXCLUSIVE_AREA_0();
        ret = E_OK;

        if((WdgM_GlobalMonitoringStatus <= WDGM_GLOBAL_STATUS_FAILED)
                && (WdgM_LocalMonitoringStatus[SEID] <= WDGM_LOCAL_STATUS_FAILED)) /*SWS_WdgM_00208*/
        {
            cpModeCfg = &WdgM_runTimeMode->WdgCpInMode[CheckpointID];


#if(WDGM_TOTAL_FLOW_NUM > 0)
            /* Transition check */
            WdgM_TransitionCheck(SEID, CheckpointID);
#endif

#if(WDGM_TOTAL_ALIVE_NUM > 0)
            /* Alive counter add */
            aliveIndex = cpModeCfg->AliveIndex;
            /* check if this alive point is enabled in this mode */
            if(WDGM_INVALID_ALIVE_INDEX != aliveIndex)
            {
                if(WdgM_AliveCnt[aliveIndex] < WDGM_INVALID_ALIVE_INDEX)
                {
                    WdgM_AliveCnt[aliveIndex]++;
                }                
            }
#endif

#if(WDGM_TOTAL_DEADLINE_NUM > 0)
            cntIndex = WdgMSupervisedEntity[SEID].osCounterRef;

            /*Transition has no error, cnt deadline */
            if(NULL_PTR != cpModeCfg->DeadlinePtr)
            {
                /* SWS_WdgM_00374 374 228 229 294
                check if this deadline point is enabled in this mode */
                for(deadlineCnt = ((uint16)0); deadlineCnt < cpModeCfg->DeadlineNum; deadlineCnt++)
                {
                    deadlineIndex = cpModeCfg->DeadlinePtr[deadlineCnt];
                    deadlinePtr = &WdgM_runTimeMode->WdgMDeadlineSupervision[deadlineIndex];


                    if(CheckpointID == deadlinePtr->WdgMDeadlineStartRef)
                    {
                        /* dont break , 1 CP may belong to different deadline */
                        if(E_OK == WdgM_GetElapsedValue(cntIndex, &WdgM_DeadlineSavedTick[deadlineIndex], &eTick))
                        {
                            WdgM_DeadlineState[deadlineIndex] = WDGM_DEADLINE_BUSY;
                        }
                    }

                    if(CheckpointID == deadlinePtr->WdgMDeadlineStopRef)
                    {
                        /* dont break , 1 CP may belong to different deadline */
                        if(WDGM_DEADLINE_BUSY == WdgM_DeadlineState[deadlineIndex])
                        {
                            if(E_OK == WdgM_GetElapsedValue(cntIndex, &WdgM_DeadlineSavedTick[deadlineIndex], &eTick))
                            {
                                if((eTick < deadlinePtr->WdgMDeadlineMin)
                                        || (eTick > deadlinePtr->WdgMDeadlineMax))
                                {
                                    WdgM_ErrFlag[SEID] |= WDGM_DEADLINE_ERROR;
                                }
                            }

                            WdgM_DeadlineState[deadlineIndex] = WDGM_DEADLINE_INACTIVE;
                        }
                    }
                }
            }
#endif

        }
        SchM_Exit_WdgM_WDGM_EXCLUSIVE_AREA_0();

    }

    return ret;

}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: WdgM_UpdateAliveCounter
*
* Description:   BEWARE, this API is deprecated. Gives alive indications to
*                the Watchdog Manager
*
* Inputs:        SEID
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, WDGM_CODE)  WdgM_UpdateAliveCounter
(
    WdgM_SupervisedEntityIdType SEID
)
{
    (void)SEID;
    return E_NOT_OK;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: WdgM_GetLocalStatus SWS_WdgM_00169
*
* Description:   Returns the monitoring status of an individual Supervised Entity.
*
* Inputs:        SEID  Status
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, WDGM_CODE) WdgM_GetLocalStatus
(
    WdgM_SupervisedEntityIdType SEID,
    P2VAR(WdgM_LocalStatusType, AUTOMATIC, WDGM_APPL_DATA) Status
)
{
    Std_ReturnType ret = E_NOT_OK;

    /* SWS_WdgM_00172 173 257 */
    if(STD_UNINITIALIZED == WdgM_InitStatus)
    {
        WDGM_DET_REPORT_ERROR(WDGM_GETLOCALSTATUS_APIID, WDGM_E_NO_INIT);
    }
    else if(NULL_PTR == Status)
    {
        WDGM_DET_REPORT_ERROR(WDGM_GETLOCALSTATUS_APIID, WDGM_E_NULL_POINTER);
    }
    else if(SEID >= WDGM_TOTAL_SE_NUM)
    {
        WDGM_DET_REPORT_ERROR(WDGM_GETLOCALSTATUS_APIID, WDGM_E_PARAM_SEID);
    }
    else
    {
        *Status = WdgM_LocalMonitoringStatus[SEID] ; /*SWS_WdgM_00171*/
        ret = E_OK;
    }

    return ret;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: WdgM_GetGlobalStatus SWS_WdgM_00175
*
* Description:   Returns the global monitoring status of the Watchdog Manager
*
* Inputs:        Status
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, WDGM_CODE) WdgM_GetGlobalStatus
(
    P2VAR(WdgM_GlobalStatusType, AUTOMATIC, WDGM_APPL_DATA) Status
)
{
    Std_ReturnType ret = E_NOT_OK;

    /* SWS_WdgM_00344 258 176 */
    if(STD_INITIALIZED != WdgM_InitStatus)
    {
        WDGM_DET_REPORT_ERROR(WDGM_GETGLOBALSTATUS_APIID, WDGM_E_NO_INIT);
    }
    else if(NULL_PTR == Status)
    {
        WDGM_DET_REPORT_ERROR(WDGM_GETGLOBALSTATUS_APIID, WDGM_E_NULL_POINTER);
    }
    else
    {
        *Status = WdgM_GlobalMonitoringStatus;
        ret = E_OK;
    }

    return ret;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: WdgM_PerformReset SWS_WdgM_00264
*
* Description:   Instructs the Watchdog Manager to cause a watchdog reset.
*
* Inputs:        None
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, WDGM_CODE) WdgM_PerformReset(void)
{
    uint8 i;


    if(STD_INITIALIZED != WdgM_InitStatus)/*SWS_WdgM_00270*/
    {
        WDGM_DET_REPORT_ERROR(WDGM_PERFORMRESET_APIID, WDGM_E_NO_INIT);
    }
    else
    {
        /*SWS_WdgM_00232 set all dog's trigger condition to 0*/
        for(i = ((uint8)0); i < (uint8)WDGM_WDG_DEVICE_NUM; i++)
        {
            WdgIf_SetTriggerCondition(WdgMWatchdog[i], ((uint16)0));
        }

        /* SWS_WdgM_00233 reset global status, so that the condition value will not be updated anymore */
        WdgM_ChangeGlobalMode(WDGM_GLOBAL_STATUS_DEACTIVATED);

    }

}


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: WdgM_MainFunction SWS_WdgM_00159
*
* Description:   Performs the processing of the cyclic Watchdog Manager jobs.
*
* Inputs:        None
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, WDGM_CODE) WdgM_MainFunction(void)
{
#if(STD_ON == WDGM_DEM_ALIVE_SUPERVISION_REPORT)
    boolean stopFlag = FALSE;
#endif


    if(STD_INITIALIZED !=  WdgM_InitStatus) /*SWS_WdgM_00039*/
    {
        WDGM_DET_REPORT_ERROR(WDGM_MAINFUNCTION_APIID, WDGM_E_NO_INIT);
    }
    else
    {
        SchM_Enter_WdgM_WDGM_EXCLUSIVE_AREA_0();
        /*SWS_WdgM_00063 221*/
        if((WDGM_GLOBAL_STATUS_DEACTIVATED != WdgM_GlobalMonitoringStatus)
                && (WDGM_GLOBAL_STATUS_STOPPED != WdgM_GlobalMonitoringStatus))
        {


            /* if expired ,only wait and cnt until stop */
            if(WDGM_GLOBAL_STATUS_EXPIRED != WdgM_GlobalMonitoringStatus)
            {
#if(WDGM_TOTAL_ALIVE_NUM > 0)
                WdgM_AliveMonitorMainFunction();/*SWS_WdgM_00324*/
#endif
                /*SWS_WdgM_00325 326 214*/
                WdgM_UpdateLocalStatus();
                WdgM_UpdateGlobalStatus();

            }


            /*SWS_WdgM_00216 220*/
            if(WDGM_GLOBAL_STATUS_EXPIRED == WdgM_GlobalMonitoringStatus)
            {
                if(WdgM_GStatusExpired_Cnt < WdgM_runTimeMode->WdgMExpiredSupervisionCycleTol)
                {
                    WdgM_GStatusExpired_Cnt++;
                }
                
                if(WdgM_GStatusExpired_Cnt >= WdgM_runTimeMode->WdgMExpiredSupervisionCycleTol)
                {
                    WdgM_ChangeGlobalMode(WDGM_GLOBAL_STATUS_STOPPED);
                    WdgM_GStatusExpired_Cnt = ((uint16)0);

#if(STD_ON == WDGM_DEM_ALIVE_SUPERVISION_REPORT)
                    stopFlag = TRUE;
#endif

                }
            }
#if(STD_ON == WDGM_DEM_ALIVE_SUPERVISION_REPORT)/*SWS_WdgM_00129*/
            if(TRUE == stopFlag)
            {
                WDGM_DEM_REPORT(WdgM_runTimeConfig->stopEventId, DEM_EVENT_STATUS_FAILED);

            }
            else
            {
                WDGM_DEM_REPORT(WdgM_runTimeConfig->stopEventId, DEM_EVENT_STATUS_PASSED);
            }
#endif


        }

        /* trigger every task cycle */
        WdgM_setTriggerValue();
        SchM_Exit_WdgM_WDGM_EXCLUSIVE_AREA_0();
    }

}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: WdgM_GetVersionInfo SWS_WdgM_00153
*
* Description:   get
*
* Inputs:        VersionInfo
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
#if (STD_ON == WDGM_VERSION_INFO_API)
FUNC(void, WDGM_CODE) WdgM_GetVersionInfo
(
    P2VAR(Std_VersionInfoType, AUTOMATIC, WDGM_APPL_DATA) VersionInfo
)
{
    /*SWS_WdgM_00256*/
    if(NULL_PTR == VersionInfo)
    {
        WDGM_DET_REPORT_ERROR(WDGM_GETVERSION_APIID, WDGM_E_NULL_POINTER);
    }
    else
    {
        /* Copy the vendor Id */
        VersionInfo->vendorID = WDGM_VENDOR_ID_VALUE;
        /* Copy the module Id */
        VersionInfo->moduleID = WDGM_MODULE_ID_VALUE;
        /* Copy Software Major Version */
        VersionInfo->sw_major_version = ((uint8)WDGM_SW_MAJOR_VERSION);
        /* Copy Software Minor Version */
        VersionInfo->sw_minor_version = ((uint8)WDGM_SW_MINOR_VERSION);
        /* Copy Software Patch Version */
        VersionInfo->sw_patch_version = ((uint8)WDGM_SW_PATCH_VERSION);
    }

}
#endif

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: WdgM_GetFirstExpiredSEID SWS_WdgM_00346
*
* Description:   get first FirstExpired se id
*
* Inputs:        SEID
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, WDGM_CODE) WdgM_GetFirstExpiredSEID
(
    P2VAR(WdgM_SupervisedEntityIdType, AUTOMATIC, WDGM_APPL_DATA) SEID
)
{
    Std_ReturnType ret = E_NOT_OK;

    /*SWS_WdgM_00256*/
    /*SWS_WdgM_00348 this api is available when uninit*/
    if(NULL_PTR == SEID)
    {
        WDGM_DET_REPORT_ERROR(WDGM_GET1STEXPSEID_APIID, WDGM_E_NULL_POINTER);
    }
    else
    {
        /*SWS_WdgM_00349*/
        SchM_Enter_WdgM_WDGM_EXCLUSIVE_AREA_0();
        if(WdgM_FirstExpSeId == (WdgM_SupervisedEntityIdType)(~WdgM_FirstExpSeIdInv))
        {
            *SEID = WdgM_FirstExpSeId;
            ret = E_OK;
        }
        else
        {
            *SEID = ((WdgM_SupervisedEntityIdType)0);
        }
        SchM_Exit_WdgM_WDGM_EXCLUSIVE_AREA_0();

    }
    return ret;
}


#define WDGM_STOP_SEC_CODE
#include "MemMap.h"


