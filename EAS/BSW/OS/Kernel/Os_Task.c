/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
*   File Name       : Os_Task.c
********************************************************************************
*   Project/Product : AUTOSAR OS PROJECT
*   Title           : Os_Task.c
*   Author          : Hirain
********************************************************************************
*   Description     : Define the API about Task for user
*
********************************************************************************
*   Limitations     : None
*
********************************************************************************
*
********************************************************************************
*   Revision History:
*   Reference to Core Os_Kernel.c File
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

/*PRQA S 3138 EOF*/
/*
Some statements are "NULL" beacause of the configuration of OS.
User may not enable such functions.
*/

/*PRQA S 3141 EOF*/
/*
Some statements are "NULL" beacause of the configuration of OS.
User may not enable such functions.
*/

/*PRQA S 1006 EOF*/
/*
Inline assembler statement is essential.
*/

/*****************************************************************************
* static variables define
******************************************************************************/


#define OS_START_SEC_CODE
#include "Os_MemMap.h"
/*****************************************************************************
* OS Private code
******************************************************************************/
STATIC FUNC(void, OS_CODE) OsTask_InitTaskCBT
(
    TaskType TaskID,
    Os_boolean isKillAll
);

/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: OsTask_InitTaskCBT
*
* Description:   init CBT of task
*
* Inputs:        TaskID, isKill
*
* Outputs:       None
*
* Limitations:   None
***********************************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, OS_CODE) OsTask_InitTaskCBT
(
    TaskType TaskID,
    Os_boolean isKillAll
)
{
    P2VAR(Os_TaskCBType, AUTOMATIC, OS_VAR) Os_Tcb_vp_temp;
    Os_Tcb_vp_temp = &(Os_TaskCBTable[TaskID]);

#if((OS_CC == OS_BCC2) || (OS_CC == OS_ECC2))
    Os_Tcb_vp_temp->OsTaskActivationTimes = (Os_uint8)0; /* The time of task activation is initialized. */
#endif /*((OS_CC == OS_BCC2) || (OS_CC == OS_ECC2))*/

#if((OS_CC == OS_ECC1) || (OS_CC == OS_ECC2))
    Os_Tcb_vp_temp->OsSetEventMask = (EventMaskType)0; /* no event set at init */
    Os_Tcb_vp_temp->OsWaitEventMask = (EventMaskType)0; /* no wait event at init */
#endif /*((OS_CC == OS_ECC1) || (OS_CC == OS_ECC2))*/

#if(OS_SPINLOCK_NUMBER > 0)
    Os_Tcb_vp_temp->LastSpinLock = OS_INVALID_SPINLOCK; /* no spinlock locked init */
#endif /*(OS_SPINLOCK_NUMBER > 0)*/

    Os_Tcb_vp_temp->OsTaskCtxPtr = (Os_AddrType)0; /* set to 0, invalid addr */

#if(OS_RESOURCE_NUMBER > 0)
    /* If isKillAll = OS_TRUE, it means from OsApp_InternalTerminateApplication -> OsTask_KillTask, if get a resource then TerminateApplication
    will can not release resource auto because Os_Tcb_vp_temp->LastResId = OS_INVALID_RES_ID.
    Or OsTask_InitTaskCBT(TaskID, OS_TRUE); Add Running check
    */
    if(isKillAll == OS_FALSE)
    {
        Os_Tcb_vp_temp->LastResId = OS_INVALID_RES_ID;  
    }
    Os_Tcb_vp_temp->OsCellingTaskPri = Os_TaskCfg[TaskID].OsTaskCfgPrio;
#endif /*(OS_RESOURCE_NUMBER > 0)*/

    Os_Tcb_vp_temp->OsTaskState = OS_TASK_SUSPENDED;

#if(OS_APPLICATION_NUMBER > 0)
    Os_Tcb_vp_temp->isKilled = isKillAll;
#else
    /*PRQA S 3119 ++*/
    /*Using useless statement to avoid QAC warns unused variable.*/
    (void)isKillAll;
    /*PRQA S 3119 --*/
#endif /*(OS_APPLICATION_NUMBER > 0)*/
#if(OS_CRC_SUPPORT == OS_ON)
    Os_Tcb_vp_temp->crcResult = (Os_uint8)0;
#endif /*(OS_CRC_SUPPORT == OS_ON)*/
    /* init tp related vars */
#if(OS_ON == OS_TP_TSK_ANYBUDGET_SUPPORT)
    Os_Tcb_vp_temp->tpNestIndex = OS_TP_INVALID_NEST_LEVEL;
    Os_Tcb_vp_temp->tpStartTs = (Os_TpTickType)0;
#endif /*(OS_ON == OS_TP_TSK_ANYBUDGET_SUPPORT)*/

#if(OS_TP_TSK_TIMEFRAME_SUPPORT == OS_ON)
    Os_Tcb_vp_temp->timeFrameFirstFlag = OS_TRUE;
    Os_Tcb_vp_temp->frameLastTs = (Os_TpTickType)0;
#endif /*(OS_TP_TSK_TIMEFRAME_SUPPORT == OS_ON)*/
}

/*****************************************************************************
* OS Internal code
******************************************************************************/

/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: OsTask_Init
*
* Description:   Task initialization.
*
* Inputs:        CoreID
*
* Outputs:       None
*
* Limitations:   None
***********************************************************************************************
END_FUNCTION_HDR*/
FUNC(void, OS_CODE) OsTask_Init
(
    CoreIdType CoreID
)
{
    TaskType TaskID;
    TaskType TaskEnd;
    Os_uint8 tableindex;
    Os_PrioType priIndex;

#ifndef OS_HW_CHK_STACK_SUPPORT
#if(OS_CHK_STACK == OS_ON)
    Os_uint16 stackIndex;
#endif /*(OS_CHK_STACK == OS_ON)*/
#endif

    /*The TaskID and priority of the current running task.*/
    Os_CurrentTaskId[CoreID] = OS_INVALID_TASK_ID;

    TaskEnd = Os_CoreCfg[CoreID].startTaskId + Os_CoreCfg[CoreID].taskNum;

    for (TaskID = Os_CoreCfg[CoreID].startTaskId; TaskID < TaskEnd; TaskID++)
    {
        OsTask_InitTaskCBT(TaskID, OS_FALSE);

#ifndef OS_HW_CHK_STACK_SUPPORT       
#if(OS_CHK_STACK == OS_ON)
        /* Initialization the task stack of current core. */
        for(stackIndex = (Os_uint16)0; stackIndex < Os_TaskCfg[TaskID].OsTaskStkSize; stackIndex++)
        {
#if(OS_PL_STACK_GROW_DIR == OS_PL_STACK_GROW_DOWN)
            Os_TaskCfg[TaskID].OsTaskStkTop[stackIndex] = OS_STACKINIT_VALUE;
#else
            Os_TaskCfg[TaskID].OsTaskStkBottom[stackIndex] = OS_STACKINIT_VALUE;
#endif /*(OS_PL_STACK_GROW_DIR == OS_PL_STACK_GROW_DOWN)*/
        }
#endif /*(OS_CHK_STACK == OS_ON)*/
#endif
    }

    /* Initialization of Priority Ready Table. */
    *(Os_CoreCfg[CoreID].taskPriReadyTableCfg.p_table_line) = (Os_uint32)0;

    for(tableindex = (Os_uint8)0; tableindex < Os_CoreCfg[CoreID].taskPriReadyTableCfg.p_table_size; tableindex++)
    {
        Os_CoreCfg[CoreID].taskPriReadyTableCfg.p_table[tableindex] = (Os_uint32)0;
    }

    for(priIndex = (Os_PrioType)0; priIndex < Os_CoreCfg[CoreID].TaskPriNumOfCore; priIndex++)
    {
        /*Q_Buf is only need initialize the first member*/
        Os_CoreCfg[CoreID].taskQueCfg[priIndex].Q_Buf[0] = OS_INVALID_TASK_ID;
#if(OS_RESOURCE_NUMBER > 0)
        Os_CoreCfg[CoreID].taskQueCfg[priIndex].cellingTaskPtr[0] = OS_INVALID_TASK_ID;
#endif /*(OS_RESOURCE_NUMBER > 0)*/
#if((OS_CC == OS_BCC2) || (OS_CC == OS_ECC2))
        if(Os_CoreCfg[CoreID].taskQueCfg[priIndex].Q_Ctl_Ptr != OS_NULL)
        {
            Os_CoreCfg[CoreID].taskQueCfg[priIndex].Q_Ctl_Ptr->Os_Q_front = (Os_uint16)0;
            Os_CoreCfg[CoreID].taskQueCfg[priIndex].Q_Ctl_Ptr->Os_Q_rear = OS_TASK_QUEUE_INVALID_INDEX;
        }
#endif /*((OS_CC == OS_BCC2) || (OS_CC == OS_ECC2))*/
    }
}

/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: OsTask_AutoStart
*
* Description:   Activation of the autostart task
*
* Inputs:        CoreID
*
* Outputs:       None
*
* Limitations:   None
***********************************************************************************************
END_FUNCTION_HDR*/
FUNC(void, OS_CODE) OsTask_AutoStart
(
    CoreIdType CoreID
)
{
    TaskType TaskID;
    TaskType TaskEnd;

    TaskEnd = Os_CoreCfg[CoreID].startTaskId + Os_CoreCfg[CoreID].taskNum;

    for(TaskID = Os_CoreCfg[CoreID].startTaskId; TaskID < TaskEnd; TaskID++)
    {
        if(OS_TRUE == Os_TaskCfg[TaskID].isAutoStart)
        {
#if(OS_APPMODE_NUMBER > 1)
            if((Os_AppModeMaskType)0 != (Os_ActiveAppMode[CoreID] & Os_TaskCfg[TaskID].appModeMask))
#endif /*(OS_APPMODE_NUMBER > 1)*/
            {
                (void)OsTask_InternalActivateTask(CoreID, TaskID, OS_FALSE, OSServiceId_ActivateTask);
            }
        }
    }
}

/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: OsTask_InternalActivateTask
*
* Description:   API function called by ActiveTask.This call serves to activate a internel task.
*
* Inputs:        <CoreID> Reference to core,
*                <TaskID> Reference to task.
*                needSchedule = FALSE: call in chainTask, TermiateWithRestart, Alarm activeTask, multicore ISR active task
*
* Outputs:       None
*
* Limitations:   None
***********************************************************************************************
END_FUNCTION_HDR*/
FUNC(StatusType, OS_CODE) OsTask_InternalActivateTask
(
    CoreIdType CoreID,
    TaskType TaskID,
    Os_boolean needSchedule,
    OSServiceIdType ServiceId
)
{
    P2VAR (Os_TaskCBType, AUTOMATIC, OS_VAR) Os_Tcb_vp_temp;

    
    Os_Tcb_vp_temp = &Os_TaskCBTable[TaskID]; /* Initialization of the pointer to the TCB variable structure */

#if(OS_APPLICATION_NUMBER > 0)
    if(Os_Tcb_vp_temp->isKilled == OS_TRUE)
    {
        OsHook_ReportErrorDisInt (CoreID, E_OS_ACCESS, OSServiceId_OsTask_InternalActivateTask, OS_IE_OBJECT_KILLED, (Os_uint32)TaskID, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        return E_OS_ACCESS;    /* the alarm has been killed */
    }
#endif /*(OS_APPLICATION_NUMBER > 0)*/

#if((OS_CC == OS_ECC2) || (OS_CC == OS_BCC2))
    /* If extend task, OsMaxActivationTimes must be 1, which can not be edit by user in tool
     * so that extend task not allow active more than 1 time
     * */
    if (Os_Tcb_vp_temp->OsTaskActivationTimes >= Os_TaskCfg[TaskID].OsMaxActivationTimes)
    {
        /* Report the error that the task activation is beyond the maximum time of multiple activation */
        OsHook_ReportErrorDisInt (CoreID, E_OS_LIMIT, ServiceId, OS_IE_TASK_ACTIVE_TIMES_ERROR, (Os_uint32)TaskID, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);

        return E_OS_LIMIT;
    }
        /* Check whether the task of OS_BCC2 or OS_ECC2 will be activated for the first time. */
    if ((Os_uint8)0 == Os_Tcb_vp_temp->OsTaskActivationTimes)
    {
        Os_Tcb_vp_temp->OsTaskState = OS_TASK_NEW;
    }
    /*PRQA S 3383,3384 ++*/
    /*
    Can not overflow because of check 
    "if (Os_Tcb_vp_temp->OsTaskActivationTimes >= Os_TaskCfg[TaskID].OsMaxActivationTimes)" 
    above.
    */
    Os_Tcb_vp_temp->OsTaskActivationTimes++;
    /*PRQA S 3383,3384 --*/
#else
    /* Check whether the task is on the suspended state */
    if (Os_Tcb_vp_temp->OsTaskState != OS_TASK_SUSPENDED)
    {
        /* Task activation is beyond the maximum time. */
        OsHook_ReportErrorDisInt (CoreID, E_OS_LIMIT, ServiceId, OS_IE_TASK_ACTIVE_TIMES_ERROR, (Os_uint32)TaskID, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        return E_OS_LIMIT;
    }
    Os_Tcb_vp_temp->OsTaskState = OS_TASK_NEW;
#endif /*((OS_CC == OS_ECC2) || (OS_CC == OS_BCC2))*/

#if(OS_EXTENDED_TASK_NUMBER > 0)
    /* reset event */
    Os_Tcb_vp_temp->OsSetEventMask = (EventMaskType)0;
    Os_Tcb_vp_temp->OsWaitEventMask = (EventMaskType)0;
#endif /*(OS_EXTENDED_TASK_NUMBER > 0)*/
    /*Add a task to ready queue*/
    OsKernel_InsertTask(CoreID, TaskID);/*When there are multiple tasks with the same priority, or the task supports multiple activations, */
                                                        /*this function needs to operate the task queue, to support FIFO*/
    if(OS_TRUE == needSchedule)
    {
        /* Check whether the priority level of the current task is the highest in the system. */
        /*PRQA S 3416 ++*/
        /* The side effect of "OsKernel_NeedSchedule" is expected. */
        if((OsKernel_NeedSchedule(CoreID, OS_FALSE) == OS_TRUE))
        /*PRQA S 3416 --*/
        {
            OsKernel_ExitTask(CoreID, OS_TRUE, OS_TASK_READY);
            /* Task scheduling, save ctx and start schedule
            */
            OsCpu_TaskPreemptSchedule(CoreID, Os_CurrentTaskId[CoreID]);
            /* here is the task restore point*/
        }
    }
    return E_OS_OK;
}

/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: OsTask_InternalTerminateTask
*
* Description:   Terminate current running Task, called in TerminateTask ChainTask and 
*                auto terminate task within OS kernel(user not terminate task)
*
* Inputs:        <CoreID> Reference to core,
*
*
* Outputs:       None
*
* Limitations:   Not used in terminateTask and ProtectionHook, use kill task in these cases
***********************************************************************************************
END_FUNCTION_HDR*/
FUNC(void, OS_CODE) OsTask_InternalTerminateTask
(
    CoreIdType CoreID
)
{
    TaskType tempTaskId = Os_CurrentTaskId[CoreID];
#if((OS_CC == OS_BCC2) || (OS_CC == OS_ECC2) || (OS_ON == OS_TP_TSK_ANYBUDGET_SUPPORT))
    P2VAR(Os_TaskCBType, AUTOMATIC, OS_VAR) temp_Tcb_vp;
    temp_Tcb_vp = &Os_TaskCBTable[tempTaskId];
#endif /*((OS_CC == OS_BCC2) || (OS_CC == OS_ECC2) || (OS_ON == OS_TP_TSK_ANYBUDGET_SUPPORT))*/
    /* auto release */
    /*PRQA S 3416 ++*/
    /* The side effect of "OsIsr_AutoResumeInterrupt" is expected. */
    if(OS_TRUE == OsIsr_AutoResumeInterrupt(CoreID))
    /*PRQA S 3416 --*/
    {
        OsHook_ReportErrorDisInt(CoreID, E_OS_DISABLEDINT, OSServiceId_TerminateTask, OS_IE_NOMORE_INFO, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
    }
#if(OS_RESOURCE_NUMBER > 0)
    /*PRQA S 3416 ++*/
    /* The side effect of "OsRes_AutoReleaseTaskResource" is expected. */
    if(OS_TRUE == OsRes_AutoReleaseTaskResource(CoreID,tempTaskId))
    /*PRQA S 3416 --*/
    {
        OsHook_ReportErrorDisInt(CoreID, E_OS_RESOURCE, OSServiceId_TerminateTask, OS_IE_NOMORE_INFO, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
    }
#endif /*(OS_RESOURCE_NUMBER > 0)*/

#if(OS_SPINLOCK_NUMBER > 0)
    /*PRQA S 3416 ++*/
    /* The side effect of "OsSpinLock_AutoReleaseTask" is expected. */
    if(OS_TRUE == OsSpinLock_AutoReleaseTask(CoreID,tempTaskId))
    /*PRQA S 3416 --*/
    {
        OsHook_ReportErrorDisInt(CoreID, E_OS_SPINLOCK, OSServiceId_TerminateTask, OS_IE_NOMORE_INFO, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
    }
#endif /*(OS_SPINLOCK_NUMBER > 0)*/
#if(OS_ON == OS_TP_TSK_ANYBUDGET_SUPPORT)
    temp_Tcb_vp->tpNestIndex = (Os_uint16)0;
#endif /*(OS_ON == OS_TP_TSK_ANYBUDGET_SUPPORT)*/
    OsKernel_RemoveTask(CoreID, tempTaskId);

#if((OS_CC == OS_BCC2) || (OS_CC == OS_ECC2))
    /* If extend task, OsMaxActivationTimes must be 1, which can not be edit by user in tool
     * so that extend task not allow active more than 1 time
     * */
    if (temp_Tcb_vp->OsTaskActivationTimes <= (Os_uint8)0)
    {
        /* Report the error that the task activation is beyond the maximum time of multiple activation */
        OsHook_ReportErrorDisInt (CoreID, E_OS_LIMIT, OSServiceId_TerminateTask, OS_IE_TASK_ACTIVE_TIMES_ERROR, (Os_uint32)tempTaskId, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
    }
    temp_Tcb_vp->OsTaskActivationTimes--; /* The time of task activation is initialized. */

    if (temp_Tcb_vp->OsTaskActivationTimes == (Os_uint8)0)
    {
        OsKernel_ExitTask(CoreID, OS_FALSE,  OS_TASK_SUSPENDED);
    }
    else
    {
        OsKernel_ExitTask(CoreID, OS_FALSE,  OS_TASK_NEW);
    }
#else
    OsKernel_ExitTask(CoreID, OS_FALSE,  OS_TASK_SUSPENDED);
#endif /*((OS_CC == OS_BCC2) || (OS_CC == OS_ECC2))*/

#if(OS_ON == OS_TP_TSK_ANYBUDGET_SUPPORT)
    temp_Tcb_vp->tpNestIndex = OS_TP_INVALID_NEST_LEVEL;
#endif /*(OS_ON == OS_TP_TSK_ANYBUDGET_SUPPORT)*/

    /* set current task invlaid */
    Os_CurrentTaskId[CoreID] = OS_INVALID_TASK_ID;
}

/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: OsTask_KillRunningTask
*
* Description:   Self Kill running task ,  called in TerminateApplication and protectionHook
*
* Inputs:        CoreID, isKillAll
*
* Outputs:       None
*
* Limitations:   None
***********************************************************************************************
END_FUNCTION_HDR*/
FUNC(void, OS_CODE) OsTask_KillRunningTask
(
    CoreIdType CoreID,
    Os_boolean isKillAll
)
{
    P2VAR(Os_TaskCBType, AUTOMATIC, OS_VAR) Os_Tcb_vp_temp;

    TaskType TaskID = Os_CurrentTaskId[CoreID];
    Os_Tcb_vp_temp = &(Os_TaskCBTable[TaskID]);
    /* remove task from queue*/
    if(isKillAll == OS_TRUE)
    {
        if(Os_Tcb_vp_temp->OsTaskState == OS_TASK_RUNNING)
        {
            OsKernel_KillTask(CoreID, TaskID);
        }
    }
    else
    {
        OsKernel_RemoveTask(CoreID, TaskID);
    }

    /* auto release, as this kill process , no need to report error*/
    (void)OsIsr_AutoResumeInterrupt(CoreID);
#if(OS_RESOURCE_NUMBER > 0)
    (void)OsRes_AutoReleaseTaskResource(CoreID,TaskID);
#endif /*(OS_RESOURCE_NUMBER > 0)*/
#if(OS_SPINLOCK_NUMBER > 0)
    (void)OsSpinLock_AutoReleaseTask(CoreID,TaskID);
#endif /*(OS_SPINLOCK_NUMBER > 0)*/
#if(OS_ON == OS_TP_TSK_ANYBUDGET_SUPPORT)
    Os_Tcb_vp_temp->tpNestIndex = OS_TP_INVALID_NEST_LEVEL;
    Os_Tcb_vp_temp->tpStartTs = (Os_TpTickType)0;
    OsTpTimer_Stop(CoreID);/* stop tp timer */
#endif /*(OS_ON == OS_TP_TSK_ANYBUDGET_SUPPORT)*/

    /* no need to check stack here*/

    OsHook_PostTaskHook(CoreID);

    /* If only kill once, no need to set kill flag, task can be activate again*/
    /* this init will not affect the ctx related vars, which saved in portable layer, and CSA can be free in following code*/
    
#if((OS_CC == OS_BCC2) || (OS_CC == OS_ECC2))
    if(isKillAll == OS_FALSE)
    {
        /*PRQA S 3383,3384 ++*/
        /*
        Can not underflow because running task's "OsTaskActivationTimes" is larger than 1.
        */
        Os_Tcb_vp_temp->OsTaskActivationTimes --; /* The time of task activation is initialized. */
        /*PRQA S 3383,3384 --*/
        if(Os_Tcb_vp_temp->OsTaskActivationTimes > (Os_uint8)0)
        {
            Os_Tcb_vp_temp->OsTaskState = OS_TASK_NEW;
        }
        else
        {
            Os_Tcb_vp_temp->OsTaskState = OS_TASK_SUSPENDED;
#if(OS_APPLICATION_NUMBER > 0)
            Os_Tcb_vp_temp->isKilled = isKillAll;
#endif /*(OS_APPLICATION_NUMBER > 0)*/
        }
    }
    else
    {
        if(Os_Tcb_vp_temp->OsTaskState == OS_TASK_RUNNING)
        {
            Os_Tcb_vp_temp->OsTaskActivationTimes = (Os_uint8)0;
            Os_Tcb_vp_temp->OsTaskState = OS_TASK_SUSPENDED;
#if(OS_APPLICATION_NUMBER > 0)
            Os_Tcb_vp_temp->isKilled = isKillAll;
#endif /*(OS_APPLICATION_NUMBER > 0)*/
        }
    }
#else
    Os_Tcb_vp_temp->OsTaskState = OS_TASK_SUSPENDED;
#if(OS_APPLICATION_NUMBER > 0)
    Os_Tcb_vp_temp->isKilled = OS_TRUE;
#endif /*(OS_APPLICATION_NUMBER > 0)*/
#endif /*((OS_CC == OS_BCC2) || (OS_CC == OS_ECC2))*/
#if(OS_APPLICATION_NUMBER > 0)
    Os_CurrentApplicationId[CoreID] = OS_INVALID_OSAPPLICATION;
#endif /*(OS_APPLICATION_NUMBER > 0)*/
    Os_CurrentContext[CoreID] = OS_CONTEXT_KERNEL;
    Os_CurrentTaskId[CoreID] = OS_INVALID_TASK_ID;

    OsCpu_TaskTerminateSchedule(CoreID, TaskID);
}


/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: OsTask_KillTask
*
* Description:   kills non running task.
*
* Inputs:        CoreID, TaskID
*
* Outputs:       None
*
* Limitations:   If Task state is running , this function will consider it as interrupted by ISR, not really running
*              the caller must make sure, running task not use this API.
***********************************************************************************************
END_FUNCTION_HDR*/
FUNC(void, OS_CODE) OsTask_KillTask
(
    CoreIdType CoreID,
    TaskType TaskID
)
{
    TaskStateType taskState = Os_TaskCBTable[TaskID].OsTaskState;

    if(taskState == OS_TASK_NEW)
    {
        /* just remove task from queue*/
        OsKernel_KillTask(CoreID, TaskID);/* remove all for this task in task queue */
        OsTask_InitTaskCBT(TaskID, OS_TRUE);
    }
    else if((taskState == OS_TASK_READY)||(taskState == OS_TASK_WAITING_TO_READY))
    {
        /* current task is kill(this task may be interrupt by ISR), set Os_CurrentTaskId invalid*/
        if(Os_CurrentTaskId[CoreID] == TaskID)
        {
            Os_CurrentTaskId[CoreID] = OS_INVALID_TASK_ID;
        }

        /* Note even if task is  preempted by C2ISR, its state will also be ready*/
        /* this branch means the task is preempted by high pri task or ISR, so we need
           1. remove from queue 2. autorelease  3. stop the paused timing protection
           4. Free CSA of this Task
        */
        OsKernel_KillTask(CoreID, TaskID);/* remove all for this task in task queue */

        /* auto release, as this kill process , no need to report error*/
        /* No need to call OsIsr_AutoResumeInterrupt, as if Task is not running thread, its not possible that interrupt is locked by it*/
#if(OS_RESOURCE_NUMBER > 0)
        (void)OsRes_AutoReleaseTaskResource(CoreID,TaskID);
#endif /*(OS_RESOURCE_NUMBER > 0)*/
#if(OS_SPINLOCK_NUMBER > 0)
        (void)OsSpinLock_AutoReleaseTask(CoreID,TaskID);
#endif /*(OS_SPINLOCK_NUMBER > 0)*/
        OsTp_TskExecutionBudgetStop(CoreID, TaskID);
        /* do not call post task hook here, as it has been called in inISR2, when task is preempted by ISR
           this running is not really running .
        */
        OsCpu_FreeTaskCSA(CoreID, TaskID);
        OsTask_InitTaskCBT(TaskID, OS_TRUE);
    }
    else if(taskState == OS_TASK_WAITING)
    {
        /* task is waiting , only free CSA*/
        OsCpu_FreeTaskCSA(CoreID, TaskID);
        OsTask_InitTaskCBT(TaskID, OS_TRUE);
    }
    else if ( taskState == OS_TASK_SUSPENDED )
    {
        /* OS_TASK_SUSPENDED do nothing */
        /* if task is not active when terminate app, just set its kill flag to true
        to avoid actived by later code*/
        OsTask_InitTaskCBT(TaskID, OS_TRUE);
    }
    else
    {
        /* OS_TASK_RUNNING do nothing */
    }
}

/*****************************************************************************
* OS API code
******************************************************************************/
/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: Os_ActivateTask
*
* Description:   API function called by Application.This call serves to activate a task.
*
* Inputs:        <TaskID> Reference to task.
*
* Outputs:       None
*
* Limitations:   None
***********************************************************************************************
END_FUNCTION_HDR*/
FUNC(StatusType, OS_CODE) Os_ActivateTask
(
    TaskType TaskID
)
{

    Os_boolean tempPri;
    CoreIdType CoreID;
    StatusType ret = E_OS_OK;

    CoreID = OsCpu_GetCoreID();

#if(OS_STATUS_LEVEL == OS_EXTENDED)
    /* Check TaskID valid or not, Check Idle Task */
    if((TaskID >= (TaskType)(OS_TASK_NUMBER - 1))
#if(OS_USED_CORE_NUMBER > 1)
            || (TaskID >= (TaskType)((Os_CoreCfg[Os_TaskCfg[TaskID].objCoreId].startTaskId + Os_CoreCfg[Os_TaskCfg[TaskID].objCoreId].taskNum) - (TaskType)1))
#endif /*(OS_USED_CORE_NUMBER > 1)*/
    )
    {
        OsHook_ReportError(CoreID, E_OS_ID, OSServiceId_ActivateTask, OS_IE_TASK_ID, (Os_uint32)TaskID, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        ret = E_OS_ID;
    }

    else if((CoreID >= (CoreIdType)OS_USED_CORE_NUMBER) || (Os_CoreState[CoreID] != OS_CORE_START)
#if(OS_USED_CORE_NUMBER > 1)
             || (Os_CoreState[Os_TaskCfg[TaskID].objCoreId] != OS_CORE_START) 
#endif /*(OS_USED_CORE_NUMBER > 1)*/
            )
    {
        /* can not record err in this state, as OS services can not be called*/
        ret = E_OS_CORE;
    }
    
    else if((Os_uint16)(Os_CurrentContext[CoreID] & Os_ActivateTaskMask) == (Os_uint16)0)
    {
        OsHook_ReportError(CoreID, E_OS_CALLEVEL, OSServiceId_ActivateTask, OS_IE_NOMORE_INFO, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        ret = E_OS_CALLEVEL;
    }

    /* Check whether this API is called between interrupt processing APIs*/
    else if(OS_NO_API_USED != Os_IntAPIUsedFlag[CoreID])
    {
        OsHook_ReportError(CoreID, E_OS_DISABLEDINT, OSServiceId_ActivateTask, OS_IE_NOMORE_INFO, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        ret = E_OS_DISABLEDINT;
    }

#if(OS_APPLICATION_NUMBER > 0)
    /*  current application invalid, should not has this case*/
    else if(Os_CurrentApplicationId[CoreID] == OS_INVALID_OSAPPLICATION)
    {
        OsHook_ReportError (CoreID, E_OS_ACCESS, OSServiceId_ActivateTask, OS_IE_INVALID_OSAPPICATION, (Os_uint32)Os_CurrentApplicationId[CoreID], OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        ret = E_OS_ACCESS;
    }

    else if((Os_ApplicationMaskType)0 == ( (((Os_ApplicationMaskType)1) << Os_CurrentApplicationId[CoreID]) & (Os_TaskCfg[TaskID].AppMask) ) )
    {
        OsHook_ReportError (CoreID, E_OS_ACCESS, OSServiceId_ActivateTask, OS_IE_NO_ACCESS_RIGHT, (Os_uint32)Os_CurrentApplicationId[CoreID], (Os_uint32)TaskID, OS_IE_NO_ERRPAR);
        ret = E_OS_ACCESS;
    }

#endif /*(OS_APPLICATION_NUMBER > 0)*/
    else
#endif /*(OS_STATUS_LEVEL == OS_EXTENDED)*/
    {
        /* Enter critical section */
        OsCpu_EnterCritical(CoreID, &tempPri);

#if(OS_USED_CORE_NUMBER > 1)
        /* Check whether this API is called from diifferent core*/
        if(CoreID != Os_TaskCfg[TaskID].objCoreId)
        {
            ret = OsMultiCore_TriggerActivateTask(CoreID,TaskID);
        }
        else
#endif /*(OS_USED_CORE_NUMBER > 1)*/
        {
            ret = OsTask_InternalActivateTask(CoreID, TaskID, OS_TRUE, OSServiceId_ActivateTask);
        }

        /*Exit critical section */
        OsCpu_ExitCritical(CoreID, tempPri);
    }
    return ret;
}

/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: Os_TerminateTask
*
* Description:   API function called by Application. This service causes the termination of
*                the calling task.
*
* Inputs:        None
*
* Outputs:       None
*
* Limitations:   None
***********************************************************************************************
END_FUNCTION_HDR*/
FUNC(StatusType, OS_CODE)Os_TerminateTask
(
    void
)
{
    CoreIdType CoreID;
    TaskType tempTaskID;
    StatusType ret = E_OS_OK;

    CoreID = OsCpu_GetCoreID();

#if(OS_STATUS_LEVEL == OS_EXTENDED)
    if((CoreID >= (CoreIdType)OS_USED_CORE_NUMBER) || (Os_CoreState[CoreID] != OS_CORE_START))
    {
        /* can not record err in this state, as OS services can not be called*/
        ret = E_OS_CORE;
    }
    
    else if((Os_uint16)(Os_CurrentContext[CoreID] & Os_TerminateTaskMask) == (Os_uint16)0)
    {
        OsHook_ReportError(CoreID, E_OS_CALLEVEL, OSServiceId_TerminateTask, OS_IE_NOMORE_INFO, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        ret = E_OS_CALLEVEL;
    }

    else if((Os_CurrentTaskId[CoreID] >= (TaskType)OS_TASK_NUMBER)
#if(OS_USED_CORE_NUMBER > 1)
            || (Os_TaskCfg[Os_CurrentTaskId[CoreID]].objCoreId != CoreID)
#endif /*(OS_USED_CORE_NUMBER > 1)*/
    )
    {
        OsHook_ReportError(CoreID, E_OS_ACCESS, OSServiceId_TerminateTask, OS_IE_TERMINATETASK_ERRTASK, (Os_uint32)Os_CurrentTaskId[CoreID], OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        ret = E_OS_ACCESS;
    }

#if((OS_CC == OS_ECC2) || (OS_CC == OS_BCC2))
    /* Error--The task comes to the suspended state but never activated. */
    else if(Os_TaskCBTable[Os_CurrentTaskId[CoreID]].OsTaskActivationTimes <= (Os_uint8)0)
    {
        OsHook_ReportError(CoreID, E_OS_LIMIT, OSServiceId_TerminateTask, OS_IE_TASK_ACTIVE_TIMES_ERROR, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        ret = E_OS_LIMIT;
    }

#endif /*((OS_CC == OS_ECC2) || (OS_CC == OS_BCC2))*/
    /* dont need check Os_IntAPIUsedFlag here, as there is auto release in service protection*/
    else
#endif /*(OS_STATUS_LEVEL == OS_EXTENDED)*/
    {
        /* as task will end , so the intterupt will be disabled until next task start*/
        OsIntc_DisableGlobalInterrupt(CoreID);

        tempTaskID = Os_CurrentTaskId[CoreID];

        OsTask_InternalTerminateTask(CoreID);

        /* as current task id has been cleared in OsTask_InternalTerminateTask, tempTaskID is needed*/
        OsCpu_TaskTerminateSchedule(CoreID, tempTaskID);

        /* never reach here*/
        OsHook_FataErrReport(CoreID, E_OS_SYSFATA_UNREACHABLE, OSServiceId_TerminateTask, OS_IE_NOMORE_INFO, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        ret = E_OS_SYSFATA_UNREACHABLE;
    }
    return ret;
}

/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: Os_ChainTask
*
* Description:   API function called by Application. This service causes the termination of
*                the calling task. After termination of the calling task a succeeding task
*                <TaskID> is activated.
*
* Inputs:        <TaskID> Reference to task to be activated.
*
* Outputs:       None
*
* Limitations:   None
***********************************************************************************************
END_FUNCTION_HDR*/
FUNC(StatusType, OS_CODE) Os_ChainTask
(
    TaskType TaskID
)
{
    CoreIdType CoreID;
    TaskType tempTaskID;
    StatusType ret = E_OS_OK;

    CoreID = OsCpu_GetCoreID();

#if(OS_STATUS_LEVEL == OS_EXTENDED)
    if((CoreID >= (CoreIdType)OS_USED_CORE_NUMBER) || (Os_CoreState[CoreID] != OS_CORE_START))
    {
        /* can not record err in this state, as OS services can not be called*/
        ret = E_OS_CORE;
    }
    
    else if((Os_uint16)(Os_CurrentContext[CoreID] & Os_ChainTaskMask) == (Os_uint16)0)
    {
        OsHook_ReportError(CoreID, E_OS_CALLEVEL, OSServiceId_ChainTask, OS_IE_NOMORE_INFO, (Os_uint32)TaskID, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        ret = E_OS_CALLEVEL;
    }

    else if((Os_CurrentTaskId[CoreID] >= (TaskType)OS_TASK_NUMBER)
#if(OS_USED_CORE_NUMBER > 1)
            || (Os_TaskCfg[Os_CurrentTaskId[CoreID]].objCoreId != CoreID)
#endif /*(OS_USED_CORE_NUMBER > 1)*/
    )
    {
        OsHook_ReportError(CoreID, E_OS_ACCESS, OSServiceId_ChainTask, OS_IE_CHAINTASK_ERRTASK, (Os_uint32)Os_CurrentTaskId[CoreID], OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        ret = E_OS_ACCESS;
    }

    /* Check TaskID valid or not, Check Idle Task */
    else if((TaskID >= (TaskType)(OS_TASK_NUMBER - 1))
#if(OS_USED_CORE_NUMBER > 1)
            || (TaskID >= (TaskType)((Os_CoreCfg[Os_TaskCfg[TaskID].objCoreId].startTaskId + Os_CoreCfg[Os_TaskCfg[TaskID].objCoreId].taskNum) - (TaskType)1))
#endif /*(OS_USED_CORE_NUMBER > 1)*/
    )
    {
        OsHook_ReportError(CoreID, E_OS_ID, OSServiceId_ChainTask, OS_IE_TASK_ID, (Os_uint32)TaskID, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        ret = E_OS_ID;
    }

#if(OS_USED_CORE_NUMBER > 1)
    /* Check whether this API is called from different core*/
    else if(CoreID != Os_TaskCfg[TaskID].objCoreId)
    {
        OsHook_ReportError(CoreID, E_OS_SYS_SERVICE_NOTSUPPORT_CROSSCORE, OSServiceId_ChainTask, OS_IE_NOMORE_INFO, (Os_uint32)TaskID, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        ret = E_OS_SYS_SERVICE_NOTSUPPORT_CROSSCORE;
    }
#endif /*(OS_USED_CORE_NUMBER > 1)*/

#if((OS_CC == OS_ECC2) || (OS_CC == OS_BCC2))
    /* Error--The task comes to the suspended state but never activated. */
    else if(Os_TaskCBTable[Os_CurrentTaskId[CoreID]].OsTaskActivationTimes <= (Os_uint8)0)
    {
        OsHook_ReportError (CoreID, E_OS_LIMIT, OSServiceId_ChainTask, OS_IE_TASK_ACTIVE_TIMES_ERROR, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        ret = E_OS_LIMIT;
    }
#endif /*((OS_CC == OS_ECC2) || (OS_CC == OS_BCC2))*/

#if(OS_APPLICATION_NUMBER > 0)
    /*  current application invalid, should not has this case*/
    else if(Os_CurrentApplicationId[CoreID] == OS_INVALID_OSAPPLICATION)
    {
        OsHook_ReportError (CoreID, E_OS_ACCESS, OSServiceId_ChainTask, OS_IE_INVALID_OSAPPICATION, (Os_uint32)Os_CurrentApplicationId[CoreID], OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        ret = E_OS_ACCESS;
    }

    /* has no access right from current application*/
    else if((Os_ApplicationMaskType)0 == ((((Os_ApplicationMaskType)1) << Os_CurrentApplicationId[CoreID]) & ((Os_TaskCfg[TaskID].AppMask))))
    {
        OsHook_ReportError (CoreID, E_OS_ACCESS, OSServiceId_ChainTask, OS_IE_NO_ACCESS_RIGHT, (Os_uint32)Os_CurrentApplicationId[CoreID], (Os_uint32)TaskID, OS_IE_NO_ERRPAR);
        ret = E_OS_ACCESS;
    }
#endif /*(OS_APPLICATION_NUMBER > 0)*/

    else
#endif /*(OS_STATUS_LEVEL == OS_EXTENDED)*/
    {
        /* Don't need check Os_IntAPIUsedFlag here, as there is auto release in service protection*/


        /* as task will end , so the interrupt will be disabled until next task start*/
        OsIntc_DisableGlobalInterrupt(CoreID);

        tempTaskID = Os_CurrentTaskId[CoreID];
        if(TaskID == Os_CurrentTaskId[CoreID])
        {
            OsTask_InternalTerminateTask(CoreID);   
        }
        
        ret = OsTask_InternalActivateTask(CoreID, TaskID, OS_FALSE, OSServiceId_ChainTask);

        if(ret != E_OS_OK)
        {
            Os_CurrentTaskId[CoreID] = tempTaskID;
            OsIntc_EnableGlobalInterrupt(CoreID);
        }
        else
        {
            if(TaskID != tempTaskID)
            {
                OsTask_InternalTerminateTask(CoreID); 
            }

            /* as current task id has been cleared in OsTask_InternalTerminateTask, tempTaskID is needed*/
            OsCpu_TaskTerminateSchedule(CoreID, tempTaskID);

            /* never reach here*/
            OsHook_FataErrReport(CoreID, E_OS_SYSFATA_UNREACHABLE, OSServiceId_ChainTask, OS_IE_NOMORE_INFO, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
            ret = E_OS_SYSFATA_UNREACHABLE;
        }
    }
    return ret;
}

/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: Os_Schedule
*
* Description:   A function for scheduling of the task,it  restores old task context and  starts a new task
*
* Inputs:        None
*
* Outputs:       None
*
* Limitations:   None
***********************************************************************************************
END_FUNCTION_HDR*/
FUNC(StatusType, OS_CODE) Os_Schedule
(
    void
)
{
    CoreIdType CoreID;
    Os_boolean tempPri;
    StatusType ret = E_OS_OK;

    CoreID = OsCpu_GetCoreID();

#if(OS_STATUS_LEVEL == OS_EXTENDED)
    if((CoreID >= (CoreIdType)OS_USED_CORE_NUMBER) || (Os_CoreState[CoreID] != OS_CORE_START))
    {
        /* can not record err in this state, as OS services can not be called*/
        ret = E_OS_CORE;
    }
    
    else if((Os_uint16)(Os_CurrentContext[CoreID] & Os_ScheduleMask) == (Os_uint16)0)
    {
        OsHook_ReportError(CoreID, E_OS_CALLEVEL, OSServiceId_Schedule, OS_IE_NOMORE_INFO, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        ret = E_OS_CALLEVEL;
    }

    /* Check whether this API is called between interrupt processing APIs*/
    else if(OS_NO_API_USED != Os_IntAPIUsedFlag[CoreID])
    {
        /* System error -- this API is called between interrupt processing function pairs */
        OsHook_ReportError(CoreID, E_OS_DISABLEDINT, OSServiceId_Schedule, OS_IE_NOMORE_INFO, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        ret = E_OS_DISABLEDINT;
    }
#if(OS_RESOURCE_NUMBER > 0)
    else if(Os_TaskCBTable[Os_CurrentTaskId[CoreID]].LastResId != OS_INVALID_RES_ID)
    {
        OsHook_ReportError(CoreID, E_OS_RESOURCE, OSServiceId_Schedule, OS_IE_NOMORE_INFO, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        ret = E_OS_RESOURCE;
    }
#endif /*(OS_RESOURCE_NUMBER > 0)*/
    else
#endif /*(OS_STATUS_LEVEL == OS_EXTENDED)*/
    {

        /* Enter critical section. */
        OsCpu_EnterCritical(CoreID, &tempPri);

        /* Check whether the priority level of the current task is the highest in the system. */
        /*PRQA S 3416 ++*/
        /* The side effect of "OsKernel_NeedSchedule" is expected. */
        if((OsKernel_NeedSchedule(CoreID, OS_TRUE) == OS_TRUE))
        /*PRQA S 3416 --*/
        {
            OsKernel_ExitTask(CoreID, OS_TRUE, OS_TASK_READY);
            /* Task scheduling*/
            OsCpu_TaskPreemptSchedule(CoreID, Os_CurrentTaskId[CoreID]);
            /* here is the task restore point*/
        }

        OsCpu_ExitCritical(CoreID, tempPri);
    }

    return ret;
}

/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: Os_GetTaskID
*
* Description:   API function called by Application. The TaskID of the current running task
*                will be saved in the address which is referenced by the output parameter.
*
* Inputs:        None
*
* Outputs:       <TaskID> indicates the ID of the task which is currently running.
*
* Limitations:   None
***********************************************************************************************
END_FUNCTION_HDR*/
FUNC(StatusType, OS_CODE) Os_GetTaskID
(
    TaskRefType TaskID
)
{
    CoreIdType CoreID;
    Os_boolean tempPri;
    StatusType ret = E_OS_OK;

    CoreID = OsCpu_GetCoreID();

#if(OS_STATUS_LEVEL == OS_EXTENDED)
    if((CoreID >= (CoreIdType)OS_USED_CORE_NUMBER) || (Os_CoreState[CoreID] != OS_CORE_START))
    {
        /* can not record err in this state, as OS services can not be called*/
        ret = E_OS_CORE;
    }
    
    else if((Os_uint16)(Os_CurrentContext[CoreID] & Os_GetTaskIDMask) == (Os_uint16)0)
    {
        OsHook_ReportError(CoreID, E_OS_CALLEVEL, OSServiceId_GetTaskID, OS_IE_NOMORE_INFO, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        ret = E_OS_CALLEVEL;
    }
     
    /* Check whether this API is called between interrupt processing APIs*/
    else if(OS_NO_API_USED != Os_IntAPIUsedFlag[CoreID])
    {
        /* System error -- this API is called between interrupt processing function pairs */
        OsHook_ReportError(CoreID, E_OS_DISABLEDINT, OSServiceId_GetTaskID, OS_IE_NOMORE_INFO, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        ret = E_OS_DISABLEDINT;
    }

    else if(TaskID == OS_NULL)
    {
        OsHook_ReportError(CoreID, E_OS_PARAM_POINTER, OSServiceId_GetTaskID, OS_IE_NOMORE_INFO, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        ret = E_OS_PARAM_POINTER;
    }
    else
#endif /*(OS_STATUS_LEVEL == OS_EXTENDED)*/
    {
        /*only support read the Task of current core*/
        OsCpu_EnterCritical(CoreID, &tempPri);
        if((Os_CurrentTaskId[CoreID] != (TaskType)(OS_TASK_NUMBER - 1))
#if(OS_USED_CORE_NUMBER > 1)
            /*PRQA S 1860 ++*/
            /* ".startTaskId" + ".taskNum" will larger than 0.  */
            && (Os_CurrentTaskId[CoreID] != ((Os_CoreCfg[Os_TaskCfg[Os_CurrentTaskId[CoreID]].objCoreId].startTaskId + Os_CoreCfg[Os_TaskCfg[Os_CurrentTaskId[CoreID]].objCoreId].taskNum) - 1))
            /*PRQA S 1860 --*/
#endif /*(OS_USED_CORE_NUMBER > 1)*/
        )
        {
            *TaskID = Os_CurrentTaskId[CoreID];
        }
        else
        {
            /*Add for Osek Test*/
            *TaskID = OS_INVALID_TASK_ID;
        }
        OsCpu_ExitCritical(CoreID, tempPri);
    }
    return ret;
}

/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: Os_GetTaskState
*
* Description:   API function called by Application. Returns the state of a task at the time
*                of calling GetTaskState.
*
* Inputs:        <TaskID> Task reference
*
* Outputs:       <State> Reference to the state of the task
*
* Limitations:   None
***********************************************************************************************
END_FUNCTION_HDR*/
FUNC(StatusType, OS_CODE) Os_GetTaskState
(
    TaskType TaskID,
    TaskStateRefType State
)
{
    CoreIdType CoreID;
    Os_boolean tempPri;
    TaskStateType tempState;
    StatusType ret = E_OS_OK;

    CoreID = OsCpu_GetCoreID();

#if(OS_STATUS_LEVEL == OS_EXTENDED)
    if((CoreID >= (CoreIdType)OS_USED_CORE_NUMBER) || (Os_CoreState[CoreID] != OS_CORE_START))
    {
        /* can not record err in this state, as OS services can not be called*/
        ret = E_OS_CORE;
    }

    else if((Os_uint16)(Os_CurrentContext[CoreID] & Os_GetTaskStateMask) == (Os_uint16)0)
    {
        OsHook_ReportError(CoreID, E_OS_CALLEVEL, OSServiceId_GetTaskState, OS_IE_NOMORE_INFO, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        ret = E_OS_CALLEVEL;
    }

    /* Check whether this API is called between interrupt processing APIs*/
    else if(OS_NO_API_USED != Os_IntAPIUsedFlag[CoreID])
    {
        /* System error -- this API is called between interrupt processing function pairs */
        OsHook_ReportError(CoreID, E_OS_DISABLEDINT, OSServiceId_GetTaskState, OS_IE_NOMORE_INFO, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        ret = E_OS_DISABLEDINT;
    }

    else if(TaskID >= (TaskType)OS_TASK_NUMBER)
    {
        OsHook_ReportError(CoreID, E_OS_ID, OSServiceId_GetTaskState, OS_IE_TASK_ID, (Os_uint32)TaskID, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        ret = E_OS_ID;
    }

    else if(State == OS_NULL)
    {
        OsHook_ReportError(CoreID, E_OS_PARAM_POINTER, OSServiceId_GetTaskState, OS_IE_NOMORE_INFO, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        ret = E_OS_PARAM_POINTER;
    }
#if(OS_USED_CORE_NUMBER > 1)
    /* not support crosscore 
        when reading the state and other core is changing the state, it may cause read out a invalid value
        so we dont suppot cross core in this version
    */
    else if(Os_TaskCfg[TaskID].objCoreId != CoreID)
    {
        OsHook_ReportError(CoreID, E_OS_SYS_SERVICE_NOTSUPPORT_CROSSCORE, OSServiceId_GetTaskState, OS_IE_NOMORE_INFO, (Os_uint32)TaskID, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        ret = E_OS_SYS_SERVICE_NOTSUPPORT_CROSSCORE;
    }
#endif /*(OS_USED_CORE_NUMBER > 1)*/

#if(OS_APPLICATION_NUMBER > 0)
    /*  current application invalid, should not has this case*/
    else if(Os_CurrentApplicationId[CoreID] == OS_INVALID_OSAPPLICATION)
    {
        OsHook_ReportError (CoreID, E_OS_ACCESS, OSServiceId_GetTaskState, OS_IE_INVALID_OSAPPICATION, (Os_uint32)Os_CurrentApplicationId[CoreID], OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        ret = E_OS_ACCESS;
    }

    /* has no access right from current application*/
    else if((Os_ApplicationMaskType)0 == ((((Os_ApplicationMaskType)1) << Os_CurrentApplicationId[CoreID]) & ((Os_TaskCfg[TaskID].AppMask))))
    {
        OsHook_ReportError (CoreID, E_OS_ACCESS, OSServiceId_GetTaskState, OS_IE_NO_ACCESS_RIGHT, (Os_uint32)Os_CurrentApplicationId[CoreID], (Os_uint32)TaskID, OS_IE_NO_ERRPAR);
        ret = E_OS_ACCESS;
    }
#endif /*(OS_APPLICATION_NUMBER > 0)*/
    else
#endif /*(OS_STATUS_LEVEL == OS_EXTENDED)*/
    {
        /*Get the task state*/
        OsCpu_EnterCritical(CoreID, &tempPri);

        tempState = Os_TaskCBTable[TaskID].OsTaskState;

        if(OS_TASK_NEW == tempState)
        {
            tempState = OS_TASK_READY;
        }
        *State = tempState;

        OsCpu_ExitCritical(CoreID, tempPri);
    }

    return ret;
}

#define OS_STOP_SEC_CODE
#include "Os_MemMap.h"

