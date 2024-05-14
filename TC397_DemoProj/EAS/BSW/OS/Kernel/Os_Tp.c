/*BEGIN_FILE_HDR
********************************************************************************
* NOTICE
* This software is the property of HiRain Technologies. Any information
* contained in this doc should not be reproduced, or used, or disclosed
* without the written authorization from HiRain Technologies.
********************************************************************************
* File Name       : Os_Tp.c
********************************************************************************
* Project/Product : AUTOSAR OS PROJECT
* Title           : Os_Tp.c
* Author          : Hirain
********************************************************************************
* Description     : Timing protection for Os
*
********************************************************************************
* Limitations     : None
*
********************************************************************************
*
********************************************************************************
* Revision History:
* Reference to Core Os_Kernel.c File
********************************************************************************
* END_FILE_HDR*/

/*****************************************************************************
* Files include
******************************************************************************/
/*PRQA S 0857 EOF*/
/*
Number of macro definitions exceeds 1024
*/
#include "Os_Internal.h"

/*****************************************************************************
* General QAC Suppression
******************************************************************************/
/*PRQA S 0862 EOF*/
/*
The code segment like:

#define XXX
#include "Os_MemMap.h"

is a part of AUTOSAR specification, but will be an error in PRQA.
*/

/*PRQA S 3432 EOF*/
/*
P2VAR and other macros in the Compiler conforms to AUTOSAR standard.There's no
need to revise.
OR
Parameters in macros or functions are useless for some hardware platforms, 
but they can not be deleted according to the requirements of 
AUTOSAR specification or compatibility.
*/

/*PRQA S 3119 EOF*/
/*
Some parameters will not be used in different configurations and hardware 
platforms, but they can not be deleted according to the requirements of 
AUTOSAR specification or compatibility. So we retain these parameters for 
compatibility and convert them with (void) to clean the warnings in compiler.
PRQA notices such statements as warning 3119, it has been suppressed here.
*/
/*PRQA S 3112 EOF*/
/*
Many macros encapsulate assembly instructions which be used to operate 
specific registers or function as C code(inline assembly). 
But PRQA can not parse assembly instructions and notice them as errors. 
So we use: 
#if defined(OS_QAC)
    #define macro (number)
#else
    #define macros asm
#endif
in source code and a macro "OS_QAC" in PRQA config to demotion errors.
PRQA notices these fake macros as warning 3112, it has been suppressed here.
*/

/*PRQA S 0553 EOF*/
/*
Some files are empty because user do not enable this function.
*/

#if(OS_TIMING_PROTECTION_SUPPORT == OS_ON)
/*****************************************************************************
* Variable Declaration
******************************************************************************/

#define OS_START_SEC_CODE
#include "Os_MemMap.h"
/*****************************************************************************
* Private functions of Tp 
******************************************************************************/
STATIC FUNC(void, OS_CODE) OsTp_DelTpInfo
(
    CoreIdType CoreID,
    P2VAR(Os_TpInfoType, AUTOMATIC, OS_VAR) tpInfo,
    P2VAR(Os_uint16, AUTOMATIC, OS_VAR) tpNestIndex,
    P2VAR(Os_TpTickType, AUTOMATIC, OS_VAR) startTs
);
STATIC FUNC(void, OS_CODE) OsTp_AddNewTpInfo
(
    CoreIdType CoreID,
    P2VAR(Os_TpInfoType, AUTOMATIC, OS_VAR) tpInfo,
    P2VAR(Os_uint16, AUTOMATIC, OS_VAR) tpNestIndex,
    Os_TpTickType timeVal,
    P2VAR(Os_TpTickType, AUTOMATIC, OS_VAR) startTs,
    Os_TpMonitorType mType
);
STATIC FUNC(void, OS_CODE) OsTp_PauseInternal
(
    CoreIdType CoreID,
    P2VAR(Os_TpInfoType, AUTOMATIC, OS_VAR) tpInfo,
    Os_uint16 tpNestIndex,
    Os_TpTickType startTs
);

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: OsTp_DelTpInfo
*
* Description: Called when task end, res releases, Int Enabled, remove the last
*              tp info from list
*
* Inputs: CoreID, tpInfo, tpNestIndex, startTs
*
* Outputs: 
*
* Return: None
*
* Limitations:  None
*********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, OS_CODE) OsTp_DelTpInfo
(
    CoreIdType CoreID,
    P2VAR(Os_TpInfoType, AUTOMATIC, OS_VAR) tpInfo,
    P2VAR(Os_uint16, AUTOMATIC, OS_VAR) tpNestIndex,
    P2VAR(Os_TpTickType, AUTOMATIC, OS_VAR) startTs
)
{
    Os_uint16 index = *tpNestIndex;
    Os_TpTickType tempStartTs = *startTs;
    Os_uint16 tempIdx;
    Os_TpTickType elapsedTime;

    if(index == (Os_uint16)0)/* last element*/
    {
        *tpNestIndex = OS_TP_INVALID_NEST_LEVEL;
        OsTpTimer_Stop(CoreID);/* stop tp timer */
        *startTs = (Os_TpTickType)0;
    }
    else
    {
        index--;
        elapsedTime = OsTpTimer_GetElapsedTime(CoreID, tempStartTs);

        for(tempIdx = (Os_uint16)0; tempIdx <= index; tempIdx++)
        {
            if(tpInfo[tempIdx].minTime >= elapsedTime)
            {
                tpInfo[tempIdx].minTime  = tpInfo[tempIdx].minTime - elapsedTime;
            }
            else
            {
                /*feta err*/
                OsHook_FataErrReport(CoreID, E_OS_SYSFATA_TP_TIMER_ERROR, OSServiceId_OsTp_DelTpInfo, OS_IE_NOMORE_INFO, tpInfo[tempIdx].minTime, elapsedTime, OS_IE_NO_ERRPAR);
            }
        }

        /* set timer to last shortest */
        tempStartTs = OsTpTimer_Set(CoreID, tpInfo[index].minTime);

        *tpNestIndex = index;
        *startTs = tempStartTs;
    }
}


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: OsTp_AddNewTpInfo
*
* Description: Add new budget time monitor info to tp list
*
* Inputs: CoreID, tpInfo, tpNestIndex, timeVal, startTs, mType
*
* Outputs: tpInfo, tpNestIndex, startTs
*
* Return: None
*
* Limitations:  
*********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, OS_CODE) OsTp_AddNewTpInfo
(
    CoreIdType CoreID,
    P2VAR(Os_TpInfoType, AUTOMATIC, OS_VAR) tpInfo,
    P2VAR(Os_uint16, AUTOMATIC, OS_VAR) tpNestIndex,
    Os_TpTickType timeVal,
    P2VAR(Os_TpTickType, AUTOMATIC, OS_VAR) startTs,
    Os_TpMonitorType mType
)
{
    Os_uint16 index = *tpNestIndex;
    Os_TpTickType tempStartTs = *startTs;
    Os_uint16 tempIdx = (Os_uint16)0;
    Os_TpTickType elapsedTime;
    Os_TpTickType tempMinTime;
    Os_TpMonitorType tempType;

    if(index == OS_TP_INVALID_NEST_LEVEL)
    {
        tempStartTs = OsTpTimer_Set(CoreID, timeVal);
        index = (Os_uint16)0;  
        tpInfo[index].minTime = timeVal;
        tpInfo[index].mintype = mType;
        tpInfo[index].type = mType;
    }
    else
    {
        tempMinTime = tpInfo[index].minTime;

        elapsedTime = OsTpTimer_GetElapsedTime(CoreID, tempStartTs);
        if(tempMinTime >= elapsedTime)
        {
            tempMinTime = tempMinTime - elapsedTime;
        }
        else
        {
            /*feta err*/
            OsHook_FataErrReport(CoreID, E_OS_SYSFATA_TP_TIMER_ERROR, OSServiceId_OsTp_AddNewTpInfo, OS_IE_NOMORE_INFO, tpInfo[tempIdx].minTime, elapsedTime, OS_IE_NO_ERRPAR);

        }

        if(timeVal < tempMinTime) /* new time is small, re set tp timer*/
        {
            tempMinTime = timeVal;
            tempStartTs = OsTpTimer_Set(CoreID, tempMinTime);
            /*PRQA S 3383 ++*/
            /* The "tpNestIndex"(input) confirms that overflow will not happen. */
            index++;
            /*PRQA S 3383 --*/
            tpInfo[index].minTime = tempMinTime;
            tpInfo[index].mintype = mType;
            tpInfo[index].type = mType;
        }
        else/* new time is long, keep all level and start ts unchange */
        {
            /* creat new info*/
            tempStartTs = OsTpTimer_Get(CoreID);
            tempType = tpInfo[index].mintype;
            /*PRQA S 3383 ++*/
            /* The "tpNestIndex"(input) confirms that overflow will not happen. */
            index++;
            /*PRQA S 3383 --*/
            tpInfo[index].minTime = (Os_TpTickType)tempMinTime;
            tpInfo[index].mintype = tempType;
            tpInfo[index].type = mType;
        }

        /* update all nested tp info */
        do
        {
            if(tpInfo[tempIdx].minTime >= (Os_TpTickType)elapsedTime)
            {
                tpInfo[tempIdx].minTime  = tpInfo[tempIdx].minTime - (Os_TpTickType)elapsedTime;
            }
            else
            {
                /*feta err*/
                OsHook_FataErrReport(CoreID, E_OS_SYSFATA_TP_TIMER_ERROR, OSServiceId_OsTp_AddNewTpInfo, OS_IE_NOMORE_INFO, tpInfo[tempIdx].minTime, elapsedTime, OS_IE_NO_ERRPAR);
            }
            /*PRQA S 3383 ++*/
            /* The "index" below confirms that overflow will not happen. */
            tempIdx++;
            /*PRQA S 3383 --*/
        } while(tempIdx < index);/* last index has been updated*/

    }

    *startTs = tempStartTs;
    *tpNestIndex = index;
}


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: OsTp_PauseInternal
*
* Description: Pause timing monitor
*
* Inputs: CoreID, tpInfo, tpNestIndex, startTs
*
* Outputs: None
*
* Return: None
*
* Limitations: None
*********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, OS_CODE) OsTp_PauseInternal
(
    CoreIdType CoreID,
    P2VAR(Os_TpInfoType, AUTOMATIC, OS_VAR) tpInfo,
    Os_uint16 tpNestIndex,
    Os_TpTickType startTs
)
{
    Os_TpTickType elapsedTime;
    Os_uint16 tempIdx;

    /* update the min time */
    elapsedTime = OsTpTimer_GetElapsedTime(CoreID, startTs);

    for(tempIdx = (Os_uint16)0; tempIdx <= tpNestIndex; tempIdx++)
    {
        if(tpInfo[tempIdx].minTime >= elapsedTime)
        {
            tpInfo[tempIdx].minTime = tpInfo[tempIdx].minTime- elapsedTime;
        }
        else
        {
            /*feta err*/
            OsHook_FataErrReport(CoreID, E_OS_SYSFATA_TP_TIMER_ERROR, OSServiceId_OsTp_PauseInternal, OS_IE_NOMORE_INFO, tpInfo[tempIdx].minTime, elapsedTime, OS_IE_NO_ERRPAR);
        }
    }

    OsTpTimer_Stop(CoreID);/* stop tp timer */
}


/*****************************************************************************
* Os Internal functions of Tp 
******************************************************************************/

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: OsTp_Init
*
* Description: Service for basic initialization of AUTOSAR OS time protection module.
*
* Inputs: CoreID
*
* Outputs: None
*
* Return: None
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, OS_CODE) OsTp_Init
(
    CoreIdType CoreID
)
{
    /* nothing to do at this version*/
    /* task and ISR related tp vars will be init at Task and ISR module. */
    (void)CoreID;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: OsTp_TskExecutionBudgetStart
*
* Description: Service for time protection of the tasks's execution. Start time
*              protection for tasks's execution
*
* Inputs: CoreID, TaskID: The current running task ID.
*
* Outputs: None
*
* Return: None
*
* Limitations: None
*********************************************************************************
END_FUNCTION_HDR*/
#if(OS_TP_TSK_EXBUDGET_SUPPORT == OS_ON)
FUNC(void, OS_CODE) OsTp_TskExecutionBudgetStart
(
    CoreIdType CoreID,
    TaskType TaskID
)
{
    P2CONST(Os_TaskCfgType, AUTOMATIC, OS_CONST) task_cp;
    P2VAR(Os_TaskCBType, AUTOMATIC, OS_VAR) task_vp;

    task_cp = &Os_TaskCfg[TaskID];
    task_vp = &Os_TaskCBTable[TaskID];

    if(task_cp->OsTaskExecBudget != (Os_TpTickType)0)
    {
        if(task_vp->tpNestIndex == OS_TP_INVALID_NEST_LEVEL)
        {
            OsTp_AddNewTpInfo(CoreID, task_cp->tpInfo, &(task_vp->tpNestIndex), task_cp->OsTaskExecBudget, &(task_vp->tpStartTs), OS_TP_EXECBUDGET);
        }
        else
        {
           /* feta err*/
            OsHook_FataErrReport(CoreID, E_OS_SYSFATA_TP_INDEX_ERROR, OSServiceId_OsTp_TskExeBudgetStart, OS_IE_NOMORE_INFO, (Os_uint32)TaskID, \
                (Os_uint32)(task_vp->tpNestIndex), OS_IE_NO_ERRPAR);

        }

    }

}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: OsTp_TskExecutionBudgetStop
*
* Description: Service for time protection of the tasks's execution. Stop time
*              protection for tasks's execution
*
* Inputs: CoreID, TaskID: The current running task ID.
*
* Outputs: None
*
* Return: None
*
* Limitations: None
*********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, OS_CODE) OsTp_TskExecutionBudgetStop
(
    CoreIdType CoreID,
    TaskType TaskID
)
{
    P2CONST(Os_TaskCfgType, AUTOMATIC, OS_CONST) task_cp;
    P2VAR(Os_TaskCBType, AUTOMATIC, OS_VAR) task_vp;

    task_cp = &Os_TaskCfg[TaskID];
    task_vp = &Os_TaskCBTable[TaskID];

    if(task_cp->OsTaskExecBudget != (Os_TpTickType)0)
    {
        if(task_vp->tpNestIndex == (Os_uint16)0)
        {
            OsTp_DelTpInfo(CoreID, task_cp->tpInfo, &(task_vp->tpNestIndex), &(task_vp->tpStartTs));
        }
        else
        {
            OsHook_FataErrReport(CoreID, E_OS_SYSFATA_TP_INDEX_ERROR, OSServiceId_OsTp_TskExeBudgetStop, OS_IE_NOMORE_INFO, (Os_uint32)TaskID, \
                (Os_uint32)(task_vp->tpNestIndex), OS_IE_NO_ERRPAR);
        }
    }
}

#endif /*(OS_TP_TSK_EXBUDGET_SUPPORT == OS_ON)*/

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: OsTp_TskPause
*
* Description: When Task is premmpted, need to pause the ExecutionBudget time and resource
*
* Inputs: CoreID, TaskID: The current running task ID.
*
* Outputs: None
*
* Return: None
*
* Limitations: No need to consider int lock, because not poosible leave task when int is lock
*********************************************************************************
END_FUNCTION_HDR*/
#if((OS_TP_TSK_EXBUDGET_SUPPORT == OS_ON) || (OS_TP_TSK_RESOURCE_LOCKTIME_SUPPORT == OS_ON))
FUNC(void, OS_CODE) OsTp_TskPause
(
    CoreIdType CoreID,
    TaskType TaskID
)
{
    /* Task preempt by ISR or other task*/
    P2VAR(Os_TaskCBType, AUTOMATIC, OS_VAR) task_vp;
    P2CONST(Os_TaskCfgType, AUTOMATIC, OS_CONST) task_cp;

    task_cp = &Os_TaskCfg[TaskID];
    task_vp = &Os_TaskCBTable[TaskID];
    if(task_vp->tpNestIndex != OS_TP_INVALID_NEST_LEVEL)
    {
        OsTp_PauseInternal(CoreID, task_cp->tpInfo, task_vp->tpNestIndex, task_vp->tpStartTs);
    }
}


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: OsTp_TskRestore
*
* Description: When Task is restore only reload the start time stamp of tp timer
*
* Inputs: CoreID, TaskID: The restore task ID.
*
* Outputs: None
*
* Return: None
*
* Limitations: No need to consider int lock, because not poosible leave task when int is lock
*********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, OS_CODE) OsTp_TskRestore
(
    CoreIdType CoreID,
    TaskType TaskID
)
{
    P2CONST(Os_TaskCfgType, AUTOMATIC, OS_CONST) task_cp;
    P2VAR(Os_TaskCBType, AUTOMATIC, OS_VAR) task_vp;
    Os_TpTickType timeVal;
    Os_TpTickType tempStartTs;

    task_cp = &Os_TaskCfg[TaskID];
    task_vp = &Os_TaskCBTable[TaskID];

    if(task_vp->tpNestIndex != OS_TP_INVALID_NEST_LEVEL)
    {
        timeVal = task_cp->tpInfo[task_vp->tpNestIndex].minTime;
        tempStartTs = OsTpTimer_Set(CoreID, timeVal);
        task_vp->tpStartTs = tempStartTs;
    }
}

#endif /*((OS_TP_TSK_EXBUDGET_SUPPORT == OS_ON) || (OS_TP_TSK_RESOURCE_LOCKTIME_SUPPORT == OS_ON))*/

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: OsTp_IsrExecutionBudgetStart
*
* Description: Service for time protection of the ISR's execution. Start time
*              protection for ISR execution
*
* Inputs: CoreID, ISRID: The current running ISR ID.
*
* Outputs: None
*
* Return: None
*
* Limitations: None
*********************************************************************************
END_FUNCTION_HDR*/
#if(OS_TP_ISR_EXBUDGET_SUPPORT == OS_ON)
FUNC(void, OS_CODE) OsTp_IsrExecutionBudgetStart
(
    CoreIdType CoreID,
    ISRType ISRID
)
{
    /*PRQA S 4643 ++*/
    /* Do not include <ctype.h> */
    P2CONST(Os_ISRCfgType, AUTOMATIC, OS_CONST) isr_cp;
    P2VAR(Os_ISRCBType, AUTOMATIC, OS_VAR) isr_vp;
    /*PRQA S 4643 --*/

    isr_cp = &Os_ISRCfg[ISRID];
    isr_vp = &Os_ISRCBTable[ISRID];

    if(isr_cp->OsIsrExecBudget != (Os_TpTickType)0)
    {
        if(isr_vp->tpNestIndex == OS_TP_INVALID_NEST_LEVEL)
        {
            OsTp_AddNewTpInfo(CoreID, isr_cp->tpInfo, &(isr_vp->tpNestIndex), isr_cp->OsIsrExecBudget, &(isr_vp->tpStartTs), OS_TP_EXECBUDGET);
        }
        else
        {
           /* feta err*/
            OsHook_FataErrReport(CoreID, E_OS_SYSFATA_TP_INDEX_ERROR, OSServiceId_OsTp_IsrExeBudgetStart, OS_IE_NOMORE_INFO, (Os_uint32)ISRID, \
                (Os_uint32)(isr_vp->tpNestIndex), OS_IE_NO_ERRPAR);

        }

    }

}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: OsTp_IsrExecutionBudgetStop
*
* Description: Service for time protection of the ISR execution. Stop time
*              protection for ISR execution
*
* Inputs: CoreID, ISRID: The current running ISRID.
*
* Outputs: None
*
* Return: None
*
* Limitations: None
*********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, OS_CODE) OsTp_IsrExecutionBudgetStop
(
    CoreIdType CoreID,
    ISRType ISRID
)
{
    /*PRQA S 4643 ++*/
    /* Do not include <ctype.h> */
    P2CONST(Os_ISRCfgType, AUTOMATIC, OS_CONST) isr_cp;
    P2VAR(Os_ISRCBType, AUTOMATIC, OS_VAR) isr_vp;
    /*PRQA S 4643 --*/

    isr_cp = &Os_ISRCfg[ISRID];
    isr_vp = &Os_ISRCBTable[ISRID];

    if(isr_cp->OsIsrExecBudget != (Os_TpTickType)0)
    {
        if(isr_vp->tpNestIndex == (Os_uint16)0)
        {
            OsTp_DelTpInfo(CoreID, isr_cp->tpInfo, &(isr_vp->tpNestIndex), &(isr_vp->tpStartTs));
        }
        else
        {
            OsHook_FataErrReport(CoreID, E_OS_SYSFATA_TP_INDEX_ERROR, OSServiceId_OsTp_IsrExeBudgetStop, OS_IE_NOMORE_INFO, (Os_uint32)ISRID, \
                (Os_uint32)(isr_vp->tpNestIndex), OS_IE_NO_ERRPAR);
        }
    }
}
#endif /*(OS_TP_ISR_EXBUDGET_SUPPORT == OS_ON)*/

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: OsTp_IsrPause
*
* Description: When ISR is premmpted, need to pause the ExecutionBudget time and resource
*
* Inputs: CoreID, ISRID: The current running ISR ID.
*
* Outputs: None
*
* Return: None
*
* Limitations: None
*********************************************************************************
END_FUNCTION_HDR*/
#if((OS_TP_ISR_EXBUDGET_SUPPORT == OS_ON) || (OS_TP_ISR_RESOURCE_LOCKTIME_SUPPORT == OS_ON))
FUNC(void, OS_CODE) OsTp_IsrPause
(
    CoreIdType CoreID,
    ISRType ISRID
)
{
    /*PRQA S 4643 ++*/
    /* Do not include <ctype.h> */
    P2CONST(Os_ISRCfgType, AUTOMATIC, OS_CONST) isr_cp;
    P2VAR(Os_ISRCBType, AUTOMATIC, OS_VAR) isr_vp;
    /*PRQA S 4643 --*/

    isr_cp = &Os_ISRCfg[ISRID];
    isr_vp = &Os_ISRCBTable[ISRID];
    if(isr_vp->tpNestIndex != OS_TP_INVALID_NEST_LEVEL)
    {
        OsTp_PauseInternal(CoreID, isr_cp->tpInfo, isr_vp->tpNestIndex, isr_vp->tpStartTs);
    }
}


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: OsTp_IsrRestore
*
* Description: When ISR is restore only reload the start time of tp timer
*
* Inputs: CoreID, ISRID: The restore ISR ID.
*
* Outputs: None
*
* Return: None
*
* Limitations: None
*********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, OS_CODE) OsTp_IsrRestore
(
    CoreIdType CoreID,
    ISRType ISRID
)
{
    /*PRQA S 4643 ++*/
    /* Do not include <ctype.h> */
    P2CONST(Os_ISRCfgType, AUTOMATIC, OS_CONST) isr_cp;
    P2VAR(Os_ISRCBType, AUTOMATIC, OS_VAR) isr_vp;
    /*PRQA S 4643 --*/
    Os_TpTickType timeVal;
    Os_TpTickType tempStartTs;

    isr_cp = &Os_ISRCfg[ISRID];
    isr_vp = &Os_ISRCBTable[ISRID];

    if(isr_vp->tpNestIndex != OS_TP_INVALID_NEST_LEVEL)
    {
        timeVal = isr_cp->tpInfo[isr_vp->tpNestIndex].minTime;
        tempStartTs = OsTpTimer_Set(CoreID, timeVal);
        isr_vp->tpStartTs = tempStartTs;
    }
}
#endif /*((OS_TP_ISR_EXBUDGET_SUPPORT == OS_ON) || (OS_TP_ISR_RESOURCE_LOCKTIME_SUPPORT == OS_ON))*/

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: OsTp_IsrLockTimeStart
*
* Description: Service starts time protection of the OS interrupts suspended by Tasks/
*              Category 2 ISRs or all interrupts suspended/disabled by Tasks/Category 2 ISRs.
*
* Inputs: isAllIntType: The current type of interrupts suspended/disabled by Tasks/Category 2
*                       ISRs is OS_TP_ALLINTLOCKTYPE or OS_TP_OSINTLOCKTYPE.
*
* Outputs: None
*
* Return: None
*
* Limitations: None
*********************************************************************************
END_FUNCTION_HDR*/
#if((OS_TP_ISR_INTLOCKBUDGET_SUPPORT == OS_ON) || (OS_TP_TSK_INTLOCKBUDGET_SUPPORT == OS_ON))
FUNC(void, OS_CODE) OsTp_IsrLockTimeStart
(
    CoreIdType CoreID,
    Os_boolean isAllIntType
)
{
#if(OS_TP_ISR_INTLOCKBUDGET_SUPPORT == OS_ON)
    ISRType ISRID;
#endif /*(OS_TP_ISR_INTLOCKBUDGET_SUPPORT == OS_ON)*/
#if(OS_TP_TSK_INTLOCKBUDGET_SUPPORT == OS_ON)
    TaskType TaskID;
#endif /*(OS_TP_TSK_INTLOCKBUDGET_SUPPORT == OS_ON)*/

    Os_TpTickType maxlockTime;

    /* C1 ISR can call DisableInt API, but can not has tp */

#if(OS_TP_ISR_INTLOCKBUDGET_SUPPORT == OS_ON)
    if(Os_CurrentContext[CoreID] == OS_CONTEXT_C2ISR)
    {
        ISRID = Os_CoreCfg[CoreID].nestIsrIdPtr[Os_IntNestDepth[CoreID]];

        if(OS_TRUE == isAllIntType)/* all interrupt type*/
        {
            maxlockTime = Os_ISRCfg[ISRID].OsIsrAllIntLockBudget;
        }
        else
        {
            maxlockTime = Os_ISRCfg[ISRID].OsIsrOsIntLockBudget;
        }

        if((Os_TpTickType)0 != maxlockTime )
        {
            if((OS_TP_INVALID_NEST_LEVEL == Os_ISRCBTable[ISRID].tpNestIndex) \
                || (Os_ISRCBTable[ISRID].tpNestIndex < (Os_ISRCfg[ISRID].tpNestSize - (Os_uint16)1)))
            {
                OsTp_AddNewTpInfo(CoreID, Os_ISRCfg[ISRID].tpInfo, &(Os_ISRCBTable[ISRID].tpNestIndex), maxlockTime, &(Os_ISRCBTable[ISRID].tpStartTs), OS_TP_ISRLOCK);
            }
            else
            {
                OsHook_FataErrReport(CoreID, E_OS_SYSFATA_TP_INDEX_ERROR, OSServiceId_OsTp_IsrLockTimeStart, OS_IE_NOMORE_INFO, (Os_uint32)ISRID, \
                    (Os_uint32)(Os_ISRCBTable[ISRID].tpNestIndex), OS_IE_NO_ERRPAR);
            }
        }
    }
#endif /*(OS_TP_ISR_INTLOCKBUDGET_SUPPORT == OS_ON)*/

#if(OS_TP_TSK_INTLOCKBUDGET_SUPPORT == OS_ON)
    if(Os_CurrentContext[CoreID] == OS_CONTEXT_TASK)
    {
        TaskID = Os_CurrentTaskId[CoreID];
        if(OS_TRUE == isAllIntType)/* all interrupt type*/
        {
            maxlockTime = Os_TaskCfg[TaskID].OsTaskAllIntLockBudget;
        }
        else
        {
            maxlockTime = Os_TaskCfg[TaskID].OsTaskOsIntLockBudget;
        }

        if((Os_TpTickType)0 != maxlockTime )
        {
            if((OS_TP_INVALID_NEST_LEVEL == Os_TaskCBTable[TaskID].tpNestIndex) \
                || (Os_TaskCBTable[TaskID].tpNestIndex < (Os_TaskCfg[TaskID].tpNestSize - (Os_uint16)1)))
            {
                OsTp_AddNewTpInfo(CoreID, Os_TaskCfg[TaskID].tpInfo, &(Os_TaskCBTable[TaskID].tpNestIndex), maxlockTime, &(Os_TaskCBTable[TaskID].tpStartTs), OS_TP_ISRLOCK);
            }
            else
            {
                OsHook_FataErrReport(CoreID, E_OS_SYSFATA_TP_INDEX_ERROR, OSServiceId_OsTp_IsrLockTimeStart, OS_IE_NOMORE_INFO, (Os_uint32)TaskID, \
                    (Os_uint32)(Os_TaskCBTable[TaskID].tpNestIndex), OS_IE_NO_ERRPAR);
            }
        }
    }  
#endif /*(OS_TP_TSK_INTLOCKBUDGET_SUPPORT == OS_ON)*/
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: OsTp_IsrLockTimeStop
*
* Description: Service stop time protection of the OS interrupts suspended by Tasks/
*              Category 2 ISRs or all interrupts suspended/disabled by Tasks/Category 2 ISRs.
*
* Inputs: isAllIntType: The current type of interrupts suspended/disabled by Tasks/Category 2
*                       ISRs is OS_TP_ALLINTLOCKTYPE or OS_TP_OSINTLOCKTYPE.
*
* Outputs: None
*
* Return: None
*
* Limitations: None
*********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, OS_CODE) OsTp_IsrLockTimeStop
(
    CoreIdType CoreID,
    Os_boolean isAllIntType
)
{
#if(OS_TP_ISR_INTLOCKBUDGET_SUPPORT == OS_ON)
    ISRType ISRID;
#endif /*(OS_TP_ISR_INTLOCKBUDGET_SUPPORT == OS_ON)*/
#if(OS_TP_TSK_INTLOCKBUDGET_SUPPORT == OS_ON)
    TaskType TaskID;
#endif /*(OS_TP_TSK_INTLOCKBUDGET_SUPPORT == OS_ON)*/

    Os_TpTickType maxlockTime;
    Os_uint16 tempIdx;

    /* C1 ISR can call DisableInt API, but can not has tp */

#if(OS_TP_ISR_INTLOCKBUDGET_SUPPORT == OS_ON)
    if(Os_CurrentContext[CoreID] == OS_CONTEXT_C2ISR)
    {
        ISRID = Os_CoreCfg[CoreID].nestIsrIdPtr[Os_IntNestDepth[CoreID]];

        if(OS_TRUE == isAllIntType)/* all interrupt type*/
        {
            maxlockTime = Os_ISRCfg[ISRID].OsIsrAllIntLockBudget;
        }
        else
        {
            maxlockTime = Os_ISRCfg[ISRID].OsIsrOsIntLockBudget;
        }

        if((Os_TpTickType)0 != maxlockTime )
        {
            tempIdx = Os_ISRCBTable[ISRID].tpNestIndex;
            if((OS_TP_INVALID_NEST_LEVEL == tempIdx) \
                || (Os_ISRCfg[ISRID].tpInfo[tempIdx].type != OS_TP_ISRLOCK))
            {
                OsHook_FataErrReport(CoreID, E_OS_SYSFATA_TP_INDEX_ERROR, OSServiceId_OsTp_IsrLockTimeStop, OS_IE_NOMORE_INFO, (Os_uint32)ISRID, (Os_uint32)tempIdx, OS_IE_NO_ERRPAR);
            }
            else
            {
                OsTp_DelTpInfo(CoreID, Os_ISRCfg[ISRID].tpInfo, &(Os_ISRCBTable[ISRID].tpNestIndex), &(Os_ISRCBTable[ISRID].tpStartTs));
            }
        }
    }
#endif /*(OS_TP_ISR_INTLOCKBUDGET_SUPPORT == OS_ON)*/

#if(OS_TP_TSK_INTLOCKBUDGET_SUPPORT == OS_ON)
    if(Os_CurrentContext[CoreID] == OS_CONTEXT_TASK)
    {
        TaskID = Os_CurrentTaskId[CoreID];
        if(OS_TRUE == isAllIntType)/* all interrupt type*/
        {
            maxlockTime = Os_TaskCfg[TaskID].OsTaskAllIntLockBudget;
        }
        else
        {
            maxlockTime = Os_TaskCfg[TaskID].OsTaskOsIntLockBudget;
        }

        if((Os_TpTickType)0 != maxlockTime )
        {
            tempIdx = Os_TaskCBTable[TaskID].tpNestIndex;
            if((OS_TP_INVALID_NEST_LEVEL == tempIdx) \
                || (Os_TaskCfg[TaskID].tpInfo[tempIdx].type != OS_TP_ISRLOCK))
            {
                OsHook_FataErrReport(CoreID, E_OS_SYSFATA_TP_INDEX_ERROR, OSServiceId_OsTp_IsrLockTimeStop, OS_IE_NOMORE_INFO, (Os_uint32)TaskID, (Os_uint32)tempIdx, OS_IE_NO_ERRPAR);
            }
            else
            {
                OsTp_DelTpInfo(CoreID, Os_TaskCfg[TaskID].tpInfo, &(Os_TaskCBTable[TaskID].tpNestIndex), &(Os_TaskCBTable[TaskID].tpStartTs));
            }
        }
    }
#endif /*(OS_TP_TSK_INTLOCKBUDGET_SUPPORT == OS_ON)*/
}
#endif /*((OS_TP_ISR_INTLOCKBUDGET_SUPPORT == OS_ON) || (OS_TP_TSK_INTLOCKBUDGET_SUPPORT == OS_ON))*/

#if(OS_TP_TSK_RESOURCE_LOCKTIME_SUPPORT == OS_ON)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: OsTp_TskResourceLocktimeStart
*
* Description: Service start resource lock time monitor
*
* Inputs: CoreID, TaskID, offsetResId
*
* Outputs: None
*
* Return: None
*
* Limitations: None
*********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, OS_CODE) OsTp_TskResourceLocktimeStart
(
    CoreIdType CoreID,
    TaskType TaskID,
    ResourceType offsetResId
)
{
    P2CONST(Os_TaskCfgType, AUTOMATIC, OS_CONST) task_cp;
    P2VAR(Os_TaskCBType, AUTOMATIC, OS_VAR) task_vp;
    Os_TpTickType tempTime;

    task_cp = &Os_TaskCfg[TaskID];
    task_vp = &Os_TaskCBTable[TaskID];

    /* offsetResId has been caculate in GetResource */
    tempTime = task_cp->resPtr[offsetResId].OsResLockTimeBudget;

    if(tempTime != (Os_TpTickType)0)
    {
        if((OS_TP_INVALID_NEST_LEVEL == task_vp->tpNestIndex) \
            || (task_vp->tpNestIndex < (task_cp->tpNestSize - (Os_uint16)1)))
        {
            OsTp_AddNewTpInfo(CoreID, task_cp->tpInfo, &(task_vp->tpNestIndex), tempTime, &(task_vp->tpStartTs), OS_TP_RESOURCELOCK);
        }
        else
        {
            OsHook_FataErrReport(CoreID, E_OS_SYSFATA_TP_INDEX_ERROR, OSServiceId_OsTp_TskResourceLocktimeStart, OS_IE_NOMORE_INFO, \
                (Os_uint32)TaskID, (Os_uint32)(task_vp->tpNestIndex), OS_IE_NO_ERRPAR);
        }
    }
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: OsTp_TskResourceLocktimeStop
*
* Description: Service stop resource lock time monitor
*
* Inputs: CoreID, TaskID, offsetResId
*
* Outputs: None
*
* Return: None
*
* Limitations: None
*********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, OS_CODE) OsTp_TskResourceLocktimeStop
(
    CoreIdType CoreID,
    TaskType TaskID,
    TaskType offsetResId
)
{
    P2CONST(Os_TaskCfgType, AUTOMATIC, OS_CONST) task_cp;
    P2VAR(Os_TaskCBType, AUTOMATIC, OS_VAR) task_vp;
    Os_TpTickType tempTime;

    task_cp = &Os_TaskCfg[TaskID];
    task_vp = &Os_TaskCBTable[TaskID];

    /* offsetResId has been caculate in GetResource */
    tempTime = task_cp->resPtr[offsetResId].OsResLockTimeBudget;

    if(tempTime != (Os_TpTickType)0)
    {
        if((OS_TP_INVALID_NEST_LEVEL == task_vp->tpNestIndex) \
            || (task_cp->tpInfo[task_vp->tpNestIndex].type != OS_TP_RESOURCELOCK))
        {
            OsHook_FataErrReport(CoreID, E_OS_SYSFATA_TP_INDEX_ERROR, OSServiceId_OsTp_TskResourceLocktimeStop, OS_IE_NOMORE_INFO, \
                (Os_uint32)TaskID, (Os_uint32)(task_vp->tpNestIndex), OS_IE_NO_ERRPAR);
        }
        else
        {
            OsTp_DelTpInfo(CoreID, task_cp->tpInfo, &(task_vp->tpNestIndex), &(task_vp->tpStartTs));
        }
    }
}
#endif /*(OS_TP_TSK_RESOURCE_LOCKTIME_SUPPORT == OS_ON)*/

#if(OS_TP_ISR_RESOURCE_LOCKTIME_SUPPORT == OS_ON)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: OsTp_IsrResourceLocktimeStart
*
* Description: Service start resource lock time monitor
*
* Inputs: CoreID, ISRID, offsetResId
*
* Outputs: None
*
* Return: None
*
* Limitations: None
*********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, OS_CODE) OsTp_IsrResourceLocktimeStart
(
    CoreIdType CoreID,
    ISRType ISRID,
    ResourceType offsetResId
)
{
    /*PRQA S 4643 ++*/
    /* Do not include <ctype.h> */
    P2CONST(Os_ISRCfgType, AUTOMATIC, OS_CONST) isr_cp;
    P2VAR(Os_ISRCBType, AUTOMATIC, OS_VAR) isr_vp;
    /*PRQA S 4643 --*/
    Os_TpTickType tempTime;

    isr_cp = &Os_ISRCfg[ISRID];
    isr_vp = &Os_ISRCBTable[ISRID];


    /* offsetResId has been caculate in GetResource */
    tempTime = isr_cp->resPtr[offsetResId].OsResLockTimeBudget;

    if(tempTime != (Os_TpTickType)0)
    {
        if((OS_TP_INVALID_NEST_LEVEL == isr_vp->tpNestIndex) \
            || (isr_vp->tpNestIndex < (isr_cp->tpNestSize - (Os_uint16)1)))
        {
            OsTp_AddNewTpInfo(CoreID, isr_cp->tpInfo, &(isr_vp->tpNestIndex), tempTime, &(isr_vp->tpStartTs), OS_TP_RESOURCELOCK);
        }
        else
        {
            OsHook_FataErrReport(CoreID, E_OS_SYSFATA_TP_INDEX_ERROR, OSServiceId_OsTp_IsrResourceLocktimeStart, OS_IE_NOMORE_INFO, \
                (Os_uint32)ISRID, (Os_uint32)(isr_vp->tpNestIndex), OS_IE_NO_ERRPAR);
        }

    }
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: OsTp_IsrResourceLocktimeStop
*
* Description: Service stop resource lock time monitor
*
* Inputs: CoreID, TaskID, offsetResId
*
* Outputs: None
*
* Return: None
*
* Limitations: None
*********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, OS_CODE) OsTp_IsrResourceLocktimeStop
(
    CoreIdType CoreID,
    ISRType ISRID,
    TaskType offsetResId
)
{
    /*PRQA S 4643 ++*/
    /* Do not include <ctype.h> */
    P2CONST(Os_ISRCfgType, AUTOMATIC, OS_CONST) isr_cp;
    P2VAR(Os_ISRCBType, AUTOMATIC, OS_VAR) isr_vp;
    /*PRQA S 4643 --*/
    Os_TpTickType tempTime;

    isr_cp = &Os_ISRCfg[ISRID];
    isr_vp = &Os_ISRCBTable[ISRID];

    /* offsetResId has been caculate in GetResource */
    tempTime = isr_cp->resPtr[offsetResId].OsResLockTimeBudget;

    if(tempTime != (Os_TpTickType)0)
    {
        if((OS_TP_INVALID_NEST_LEVEL == isr_vp->tpNestIndex) \
            || (isr_cp->tpInfo[isr_vp->tpNestIndex].type != OS_TP_RESOURCELOCK))
        {
            OsHook_FataErrReport(CoreID, E_OS_SYSFATA_TP_INDEX_ERROR, OSServiceId_OsTp_IsrResourceLocktimeStop, OS_IE_NOMORE_INFO, \
                (Os_uint32)ISRID, (Os_uint32)(isr_vp->tpNestIndex), OS_IE_NO_ERRPAR);
        }
        else
        {
            OsTp_DelTpInfo(CoreID, isr_cp->tpInfo, &(isr_vp->tpNestIndex), &(isr_vp->tpStartTs));
        }

    }
}
#endif /*(OS_TP_ISR_RESOURCE_LOCKTIME_SUPPORT == OS_ON)*/

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: OsTp_TskTimeFrameCheck
*
* Description: Service for check the inter-arrival time of task.
*
* Inputs: CoreID, TaskID: The current running task ID.
*
* Outputs: None
*
* Return: None
*
* Limitations: None
*********************************************************************************
END_FUNCTION_HDR*/
#if(OS_TP_TSK_TIMEFRAME_SUPPORT == OS_ON)
FUNC(void, OS_CODE) OsTp_TskTimeFrameCheck
(
    CoreIdType CoreID,
    TaskType TaskID
)
{
    P2CONST(Os_TaskCfgType, AUTOMATIC, OS_CONST) task_cp;
    P2VAR(Os_TaskCBType, AUTOMATIC, OS_VAR) task_vp;
    Os_TpTickType tempTime;

    task_cp = &Os_TaskCfg[TaskID];
    task_vp = &Os_TaskCBTable[TaskID];


    if(task_cp->OsTaskTimeFrame != (Os_TpTickType)0)
    {
        if(task_vp->timeFrameFirstFlag == OS_TRUE)
        {
            task_vp->timeFrameFirstFlag = OS_FALSE;
            task_vp->frameLastTs = OsTpFcTimer_Get(CoreID);
        }
        else
        {
            tempTime = OsTpFcTimer_GetElapsedTime(CoreID, task_vp->frameLastTs);
            if(tempTime < task_cp->OsTaskTimeFrame)
            {
                OsHook_ProtectionHook(CoreID, E_OS_PROTECTION_ARRIVAL);
            }

            task_vp->frameLastTs = OsTpFcTimer_Get(CoreID);
        }
    }
}
#endif /*(OS_TP_TSK_TIMEFRAME_SUPPORT == OS_ON)*/

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: OsTp_IsrTimeFrameCheck
*
* Description: Service for Check the inter-arrival time of Category 2 ISRs.
*
* Inputs: ISRID: The current running ISR ID.
*
* Outputs: None
*
* Return: None
*
* Limitations: None
*********************************************************************************
END_FUNCTION_HDR*/
#if(OS_TP_ISR_TIMEFRAME_SUPPORT == OS_ON)
FUNC(void, OS_CODE) OsTp_IsrTimeFrameCheck
(
    CoreIdType CoreID,
    ISRType ISRID
)
{
    /*PRQA S 4643 ++*/
    /* Do not include <ctype.h> */
    P2CONST(Os_ISRCfgType, AUTOMATIC, OS_CONST) isr_cp;
    P2VAR(Os_ISRCBType, AUTOMATIC, OS_VAR) isr_vp;
    /*PRQA S 4643 --*/

    Os_TpTickType tempTime;

    isr_cp = &Os_ISRCfg[ISRID];
    isr_vp = &Os_ISRCBTable[ISRID];

    if(isr_cp->OsIsrTimeFrame != (Os_TpTickType)0)
    {
        if(isr_vp->timeFrameFirstFlag == OS_TRUE)
        {
            isr_vp->timeFrameFirstFlag = OS_FALSE;
            isr_vp->frameLastTs = OsTpFcTimer_Get(CoreID);
        }
        else
        {
            tempTime = OsTpFcTimer_GetElapsedTime(CoreID, isr_vp->frameLastTs);
            if(tempTime < isr_cp->OsIsrTimeFrame)
            {
                OsHook_ProtectionHook(CoreID, E_OS_PROTECTION_ARRIVAL);
            }

            isr_vp->frameLastTs = OsTpFcTimer_Get(CoreID);
        }
    }
}
#endif /*(OS_TP_ISR_TIMEFRAME_SUPPORT == OS_ON)*/

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: OsTp_ProtectionProcess
*
* Description: Called in timer overflow trap or ISR
*
* Inputs: None
*
* Outputs: None
*
* Return: None
*
* Limitations: None
*********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, OS_CODE) OsTp_ProtectionProcess
(
    void
)
{
    CoreIdType CoreID;
#if(OS_ON == OS_TP_ISR_ANYBUDGET_SUPPORT)
    ISRType ISRID;
#endif /*(OS_ON == OS_TP_ISR_ANYBUDGET_SUPPORT)*/
#if(OS_ON == OS_TP_TSK_ANYBUDGET_SUPPORT)
    TaskType TaskID;
#endif /*(OS_ON == OS_TP_TSK_ANYBUDGET_SUPPORT)*/
    Os_TpMonitorType type = OS_TP_NONE;

    CoreID = OsCpu_GetCoreID();

#if(OS_ON == OS_TP_ISR_ANYBUDGET_SUPPORT)
    if((Os_CurrentContext[CoreID] == OS_CONTEXT_C2ISR) || 
        ((Os_CurrentContext[CoreID] == OS_CONTEXT_C1ISR) && (Os_IntNestDepth[CoreID] != OS_INVALID_ISR)))
    {
        ISRID = Os_CoreCfg[CoreID].nestIsrIdPtr[Os_IntNestDepth[CoreID]];
        type = Os_ISRCfg[ISRID].tpInfo[Os_ISRCBTable[ISRID].tpNestIndex].mintype;
    }
#endif /*(OS_ON == OS_TP_ISR_ANYBUDGET_SUPPORT)*/

#if(OS_ON == OS_TP_TSK_ANYBUDGET_SUPPORT)
    if((Os_CurrentContext[CoreID] == OS_CONTEXT_TASK) || 
        ((Os_CurrentContext[CoreID] == OS_CONTEXT_C1ISR) && (Os_IntNestDepth[CoreID] == OS_INVALID_ISR)))
    {
        TaskID = Os_CurrentTaskId[CoreID];
        type = Os_TaskCfg[TaskID].tpInfo[Os_TaskCBTable[TaskID].tpNestIndex].mintype;
    }
#endif /*(OS_ON == OS_TP_TSK_ANYBUDGET_SUPPORT)*/

    switch(type)
    {
    case OS_TP_EXECBUDGET:
        OsHook_ProtectionHook(CoreID, E_OS_PROTECTION_TIME);
        break;

    case OS_TP_RESOURCELOCK:
        OsHook_ProtectionHook(CoreID, E_OS_PROTECTION_LOCKED);
        break;

    case OS_TP_ISRLOCK:
        OsHook_ProtectionHook(CoreID, E_OS_PROTECTION_LOCKED);
        break;
    /*PRQA S 2016 ++*/
    /* "type" is enum and do not need "default" to handle anything. */
    default:
        break;
    /*PRQA S 2016 --*/
    }
}

#define OS_STOP_SEC_CODE
#include "Os_MemMap.h"

#endif /*(OS_TIMING_PROTECTION_SUPPORT == OS_ON)*/

