/* BEGIN_FILE_HDR
********************************************************************************
* NOTICE
* This software is the property of HiRain Technologies. Any information
* contained in this doc should not be reproduced, or used, or disclosed
* without the written authorization from HiRain Technologies.
********************************************************************************
* File Name:       Os_Event.c
********************************************************************************
* Project/Product: AUTOSAR OS PROJECT
* Title:           Os_Event.c
* Author:          Hirain
********************************************************************************
* Description:     Event implement of OS
*
********************************************************************************
* Limitations     : None
*
********************************************************************************
*
********************************************************************************
*   Revision History:
*   Reference to Core Os_Kernel.c File
********************************************************************************
* END_FILE_HDR*/
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

#if((OS_CC == OS_ECC1) || (OS_CC == OS_ECC2))
/*****************************************************************************
* static variables define
******************************************************************************/

#define OS_START_SEC_CODE
#include "Os_MemMap.h"
/*****************************************************************************
* OS private code
******************************************************************************/

/*****************************************************************************
* OS internal code
******************************************************************************/
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: OsEvent_InternalSetEvent
*
* Description:   Internal set Event, called by event and crosscore setEvent
*
* Inputs:        CoreID,TaskID,Mask
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(StatusType, OS_CODE) OsEvent_InternalSetEvent
(
    CoreIdType CoreID,
    TaskType TaskID,
    EventMaskType Mask
)
{

    StatusType ret = E_OS_OK;

    /* following checks not include by OS_STATUS_LEVEL
     * as these errors are runtime errors
     * */
    /*
     * check if TASK is killed, TASK can be killed only when teminateApplication called
     * */
#if(OS_APPLICATION_NUMBER > 0)
    if(Os_TaskCBTable[TaskID].isKilled == OS_TRUE)/* SWS_OS_00509*/
    {
        OsHook_ReportErrorDisInt (CoreID, E_OS_ACCESS, OSServiceId_OsEvent_InternalSetEvent, OS_IE_OBJECT_KILLED, (Os_uint32)TaskID, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        ret = E_OS_ACCESS;    /* the TASK has been killed */
    }
    else
#endif /*(OS_APPLICATION_NUMBER > 0)*/

    /* OSEK 13.5.3.1 Events can not be set as the referenced task is in the suspended state, E_OS_STATE */
    if(Os_TaskCBTable[TaskID].OsTaskState == OS_TASK_SUSPENDED)
    {
        OsHook_ReportErrorDisInt (CoreID, E_OS_STATE, OSServiceId_OsEvent_InternalSetEvent, OS_IE_EVENT_ERRTASK_STATE, (Os_uint32)TaskID, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        ret = E_OS_STATE;
    }
    else
    {
        Os_TaskCBTable[TaskID].OsSetEventMask |= Mask;

        /* if task waiting, trigger schedule*/
        if(Os_TaskCBTable[TaskID].OsTaskState == OS_TASK_WAITING)
        {
            if((Os_TaskCBTable[TaskID].OsSetEventMask & Os_TaskCBTable[TaskID].OsWaitEventMask) != (EventMaskType)0)
            {
                /* dont need to clear any bit in waitEventMask here, as when extended tast starts, 
                user call waitEvent again and waitEventMask will be updated there   */
                OsKernel_InsertTask(CoreID, TaskID);

                /*Extend task, ready state set, not new state, extend task will resume*/
                Os_TaskCBTable[TaskID].OsTaskState = OS_TASK_WAITING_TO_READY;

                /*PRQA S 3416 ++*/
                /* The side effect of "OsKernel_NeedSchedule" is expected. */
                if(OS_TRUE == OsKernel_NeedSchedule(CoreID, OS_FALSE))
                /*PRQA S 3416 --*/
                {
                    OsKernel_ExitTask(CoreID, OS_TRUE, OS_TASK_READY);
                    /* Task scheduling */
                    OsCpu_TaskPreemptSchedule(CoreID, Os_CurrentTaskId[CoreID]);
                    /* here is the task restore point*/

                }
            }
        }
    }

    return ret;

}


/*****************************************************************************
* API code
******************************************************************************/

/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: Os_SetEvent
*
* Description:   API function called by Application.This call serves to set event for extend task.
*
* Inputs:        <TaskID> Reference to task.
*                <Mask> Mask of the events to be set.
*
* Outputs:       None
*
* Limitations:   None
***********************************************************************************************
END_FUNCTION_HDR*/
FUNC(StatusType, OS_CODE) Os_SetEvent
(
    TaskType TaskID,
    EventMaskType Mask
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
    
    else if((Os_uint16)(Os_CurrentContext[CoreID] & Os_SetEventMask) == (Os_uint16)0)
    {
        OsHook_ReportError(CoreID, E_OS_CALLEVEL, OSServiceId_SetEvent, OS_IE_NOMORE_INFO, (Os_uint32)TaskID, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        ret = E_OS_CALLEVEL;
    }

    /* Check whether this API is called between interrupt processing APIs*/
    else if(OS_NO_API_USED != Os_IntAPIUsedFlag[CoreID])
    {
        /* System error -- this API is called between interrupt processing function pairs */
        OsHook_ReportError(CoreID, E_OS_DISABLEDINT, OSServiceId_SetEvent, OS_IE_NOMORE_INFO, (Os_uint32)TaskID, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        ret = E_OS_DISABLEDINT;
    }

    /* Check TaskID valid or not*/
    else if(TaskID >= (TaskType)OS_TASK_NUMBER)
    {
        OsHook_ReportError(CoreID, E_OS_ID, OSServiceId_SetEvent, OS_IE_TASK_ID, (Os_uint32)TaskID, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        ret = E_OS_ID;
    }

    /* Check Task extend*/
    else if(Os_TaskCfg[TaskID].isExtendTask == OS_FALSE)
    {
        OsHook_ReportError(CoreID, E_OS_ACCESS, OSServiceId_SetEvent, OS_IE_EVENT_WORK_WITH_BT, (Os_uint32)TaskID, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        ret = E_OS_ACCESS;
    }


#if(OS_APPLICATION_NUMBER > 0)
    /*Current application invalid, should not has this case*/
    else if(Os_CurrentApplicationId[CoreID] == OS_INVALID_OSAPPLICATION)
    {
        OsHook_ReportError(CoreID, E_OS_ACCESS, OSServiceId_SetEvent, OS_IE_INVALID_OSAPPICATION, (Os_uint32)Os_CurrentApplicationId[CoreID], OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        ret = E_OS_ACCESS;
    }

    else if((Os_ApplicationMaskType)0 == ( (((Os_ApplicationMaskType)1) << Os_CurrentApplicationId[CoreID]) & Os_TaskCfg[TaskID].AppMask))
    {
        OsHook_ReportError(CoreID, E_OS_ACCESS, OSServiceId_SetEvent, OS_IE_NO_ACCESS_RIGHT, (Os_uint32)TaskID, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
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
        if (CoreID != Os_TaskCfg[TaskID].objCoreId)
        {
            ret = OsMultiCore_TriggerSetEvent(CoreID,TaskID,Mask);
        }
        else
#endif /*(OS_USED_CORE_NUMBER > 1)*/
        {
            ret = OsEvent_InternalSetEvent(CoreID,TaskID,Mask);
        }

        /*Exit critical section */
        OsCpu_ExitCritical(CoreID, tempPri);
    }
    return ret;
}



/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: Os_ClearEvent
*
* Description:   API function called by Application.Used to clear the event according to the
*                event mask <Mask>.
*
* Inputs:        <Mask> Mask of the events to be cleared.
*
* Outputs:       None
*
* Limitations:   Can only be called in task which this event belongs
***********************************************************************************************
END_FUNCTION_HDR*/
FUNC(StatusType, OS_CODE) Os_ClearEvent
(
    EventMaskType Mask
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

    else if((Os_uint16)(Os_CurrentContext[CoreID] & Os_ClearEventMask) == (Os_uint16)0)
    {
        OsHook_ReportError(CoreID, E_OS_CALLEVEL, OSServiceId_ClearEvent, OS_IE_NOMORE_INFO, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        ret = E_OS_CALLEVEL;
    }

    /* Check whether this API is called between interrupt processing APIs*/
    else if(OS_NO_API_USED != Os_IntAPIUsedFlag[CoreID])
    {
        /* System error -- this API is called between interrupt processing function pairs */
        OsHook_ReportError(CoreID, E_OS_DISABLEDINT, OSServiceId_ClearEvent, OS_IE_NOMORE_INFO, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        ret = E_OS_DISABLEDINT;
    }
#if(OS_USED_CORE_NUMBER > 1)
    else if((Os_CurrentTaskId[CoreID] >= (TaskType)OS_TASK_NUMBER) || (Os_TaskCfg[Os_CurrentTaskId[CoreID]].objCoreId != CoreID))
#else
    else if(Os_CurrentTaskId[CoreID] >= (TaskType)OS_TASK_NUMBER)
#endif /*(OS_USED_CORE_NUMBER > 1)*/
    {
        /* check if this API called in valid task*/
        OsHook_ReportError(CoreID, E_OS_ACCESS, OSServiceId_ClearEvent, OS_IE_EVENT_ERRTASK, (Os_uint32)Os_CurrentTaskId[CoreID], OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        ret = E_OS_ACCESS;
    }

    /* can only call this API in extend task */
    else if(Os_TaskCfg[Os_CurrentTaskId[CoreID]].isExtendTask == OS_FALSE)
    {
        OsHook_ReportError(CoreID, E_OS_ACCESS, OSServiceId_ClearEvent, OS_IE_EVENT_WORK_WITH_BT, (Os_uint32)Os_CurrentTaskId[CoreID], OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        ret = E_OS_ACCESS;
    }
    else
#endif /*(OS_STATUS_LEVEL == OS_EXTENDED)*/
    {

        /* Enter critical section */
        OsCpu_EnterCritical(CoreID, &tempPri);

        Os_TaskCBTable[Os_CurrentTaskId[CoreID]].OsSetEventMask &= ((EventMaskType)(~Mask));

        /*Exit critical section */
        OsCpu_ExitCritical(CoreID, tempPri);
    }

    return ret;
}

/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: Os_GetEvent
*
* Description:   API function called by Application.Returns the current state of all event
*                bits of the task <TaskID>.
*
* Inputs:        <TaskID> Task whose event mask is to be returned.
*
* Outputs:       <Event> Reference to the memory of the return data.
*
* Limitations:   None
***********************************************************************************************
END_FUNCTION_HDR*/
FUNC(StatusType, OS_CODE) Os_GetEvent
(
    TaskType TaskID,
    EventMaskRefType Event
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
    
    else if((Os_uint16)(Os_CurrentContext[CoreID] & Os_GetEventMask) == (Os_uint16)0)
    {
        OsHook_ReportError(CoreID, E_OS_CALLEVEL, OSServiceId_GetEvent, OS_IE_NOMORE_INFO, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        ret = E_OS_CALLEVEL;
    }

    /* Check whether this API is called between interrupt processing APIs*/
    else if(OS_NO_API_USED != Os_IntAPIUsedFlag[CoreID])
    {
        /* System error -- this API is called between interrupt processing function pairs */
        OsHook_ReportError(CoreID, E_OS_DISABLEDINT, OSServiceId_GetEvent, OS_IE_NOMORE_INFO, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        ret = E_OS_DISABLEDINT;
    }

    else if(TaskID >= (TaskType)OS_TASK_NUMBER)
    {
        OsHook_ReportError(CoreID, E_OS_ID, OSServiceId_GetEvent, OS_IE_TASK_ID, (Os_uint32)TaskID, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        ret = E_OS_ID;
    }

    else if(Event == OS_NULL)
    {
        OsHook_ReportError(CoreID, E_OS_PARAM_POINTER, OSServiceId_GetEvent, OS_IE_NOMORE_INFO, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        ret = E_OS_PARAM_POINTER;
    }

    /* can only call this API in extend task */
    else if(Os_TaskCfg[TaskID].isExtendTask == OS_FALSE)
    {
        OsHook_ReportError(CoreID, E_OS_ACCESS, OSServiceId_GetEvent, OS_IE_EVENT_WORK_WITH_BT, (Os_uint32)TaskID, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        ret = E_OS_ACCESS;
    }
#if(OS_USED_CORE_NUMBER > 1)
    /* not support crosscore */
    else if(Os_TaskCfg[TaskID].objCoreId != CoreID)
    {
        OsHook_ReportError(CoreID, E_OS_SYS_SERVICE_NOTSUPPORT_CROSSCORE, OSServiceId_GetEvent, OS_IE_TASK_ID, (Os_uint32)TaskID, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        ret = E_OS_SYS_SERVICE_NOTSUPPORT_CROSSCORE;
    }
#endif /*(OS_USED_CORE_NUMBER > 1)*/
    /* check if TASK is SUSPEND, only alive TASK can be get event */
    else if(Os_TaskCBTable[TaskID].OsTaskState == OS_TASK_SUSPENDED)
    {
        OsHook_ReportError(CoreID, E_OS_STATE, OSServiceId_GetEvent, OS_IE_TASK_ID, (Os_uint32)TaskID, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        ret = E_OS_STATE;
    }


#if(OS_APPLICATION_NUMBER > 0)
    /*  current application invalid, should not has this case*/
    else if(Os_CurrentApplicationId[CoreID] == OS_INVALID_OSAPPLICATION)
    {
        OsHook_ReportError(CoreID, E_OS_ACCESS, OSServiceId_GetEvent, OS_IE_INVALID_OSAPPICATION, (Os_uint32)Os_CurrentApplicationId[CoreID], OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        ret = E_OS_ACCESS;
    }

    /* has no access right from current application*/
    else if((Os_ApplicationMaskType)0 == ((((Os_ApplicationMaskType)1) << Os_CurrentApplicationId[CoreID]) & ((Os_TaskCfg[TaskID].AppMask))))
    {
        OsHook_ReportError(CoreID, E_OS_ACCESS, OSServiceId_GetEvent, OS_IE_NO_ACCESS_RIGHT, (Os_uint32)TaskID, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        ret = E_OS_ACCESS;
    }
#endif /*(OS_APPLICATION_NUMBER > 0)*/
    else
#endif /*(OS_STATUS_LEVEL == OS_EXTENDED)*/
    {
        /* Enter critical section */
        OsCpu_EnterCritical(CoreID, &tempPri);

        *Event = Os_TaskCBTable[TaskID].OsSetEventMask;

        /*Exit critical section */
        OsCpu_ExitCritical(CoreID, tempPri);
    }
    return ret;
}

/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: Os_WaitEvent
*
* Description:   API function called by Application.This call serves to wait a event.
*
* Inputs:        <Mask> Mask of the events waited for.
*
* Outputs:       None
*
* Limitations:   None
***********************************************************************************************
END_FUNCTION_HDR*/
FUNC(StatusType, OS_CODE) Os_WaitEvent
(
    EventMaskType Mask
)
{
    CoreIdType CoreID;
    Os_boolean tempPri;
    P2VAR(Os_TaskCBType, AUTOMATIC, OS_VAR) temp_Tcb_vp;
    StatusType ret = E_OS_OK;

    CoreID = OsCpu_GetCoreID();


#if(OS_STATUS_LEVEL == OS_EXTENDED)
    if((CoreID >= (CoreIdType)OS_USED_CORE_NUMBER) || (Os_CoreState[CoreID] != OS_CORE_START))
    {
        /* can not record err in this state, as OS services can not be called*/
        ret = E_OS_CORE;
    }
    
    else if((Os_uint16)(Os_CurrentContext[CoreID] & Os_WaitEventMask) == (Os_uint16)0)
    {
        OsHook_ReportError(CoreID, E_OS_CALLEVEL, OSServiceId_WaitEvent, OS_IE_NOMORE_INFO, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        ret = E_OS_CALLEVEL;
    }

    /* Check whether this API is called between interrupt processing APIs*/
    else if(OS_NO_API_USED != Os_IntAPIUsedFlag[CoreID])
    {
        /* System error -- this API is called between interrupt processing function pairs */
        OsHook_ReportError(CoreID, E_OS_DISABLEDINT, OSServiceId_WaitEvent, OS_IE_NOMORE_INFO, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        ret = E_OS_DISABLEDINT;
    }

#if(OS_USED_CORE_NUMBER > 1)
    else if((Os_CurrentTaskId[CoreID] >= (TaskType)OS_TASK_NUMBER) || (Os_TaskCfg[Os_CurrentTaskId[CoreID]].objCoreId != CoreID))
#else
    else if(Os_CurrentTaskId[CoreID] >= (TaskType)OS_TASK_NUMBER)
#endif /*(OS_USED_CORE_NUMBER > 1)*/
    {
        /* check if this API called in valid task*/
        OsHook_ReportError(CoreID, E_OS_ACCESS, OSServiceId_WaitEvent, OS_IE_EVENT_ERRTASK, (Os_uint32)Os_CurrentTaskId[CoreID], OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        ret = E_OS_ACCESS;
    }

    /* can only call this API in extend task */
    else if(Os_TaskCfg[Os_CurrentTaskId[CoreID]].isExtendTask == OS_FALSE)
    {
        OsHook_ReportError(CoreID, E_OS_ACCESS, OSServiceId_WaitEvent, OS_IE_EVENT_WORK_WITH_BT, (Os_uint32)Os_CurrentTaskId[CoreID], OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        ret = E_OS_ACCESS;
    }
    else
#endif /*(OS_STATUS_LEVEL == OS_EXTENDED)*/
    {
        OsCpu_EnterCritical(CoreID, &tempPri);

        /* auto release */
        /*PRQA S 3416 ++*/
        /* The side effect of "OsIsr_AutoResumeInterrupt" is expected. */
        if(OS_TRUE == OsIsr_AutoResumeInterrupt(CoreID))
        /*PRQA S 3416 --*/
        {
            OsHook_ReportError(CoreID, E_OS_DISABLEDINT, OSServiceId_WaitEvent, OS_IE_NOMORE_INFO, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        }
#if(OS_RESOURCE_NUMBER > 0)
        /*PRQA S 3416 ++*/
        /* The side effect of "OsRes_AutoReleaseTaskResource" is expected. */
        if(OS_TRUE == OsRes_AutoReleaseTaskResource(CoreID,Os_CurrentTaskId[CoreID]))
        /*PRQA S 3416 --*/
        {
            OsHook_ReportError(CoreID, E_OS_RESOURCE, OSServiceId_WaitEvent, OS_IE_NOMORE_INFO, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        }
#endif /*(OS_RESOURCE_NUMBER > 0)*/

#if(OS_SPINLOCK_NUMBER > 0)
        /*PRQA S 3416 ++*/
        /* The side effect of "OsSpinLock_AutoReleaseTask" is expected. */
        if(OS_TRUE == OsSpinLock_AutoReleaseTask(CoreID,Os_CurrentTaskId[CoreID]))
        /*PRQA S 3416 --*/
        {
            OsHook_ReportError(CoreID, E_OS_SPINLOCK, OSServiceId_WaitEvent, OS_IE_NOMORE_INFO, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR, OS_IE_NO_ERRPAR);
        }
#endif /*(OS_SPINLOCK_NUMBER > 0)*/

        temp_Tcb_vp = &Os_TaskCBTable[Os_CurrentTaskId[CoreID]];

        temp_Tcb_vp->OsWaitEventMask = Mask;

        /*The event to be waited has not taken place.*/
        if((EventMaskType)0 == (temp_Tcb_vp->OsSetEventMask & Mask))
        {
            OsKernel_RemoveTask(CoreID, Os_CurrentTaskId[CoreID]);

            OsKernel_ExitTask(CoreID, OS_TRUE, OS_TASK_WAITING);
            /* Task scheduling */
            OsCpu_TaskPreemptSchedule(CoreID, Os_CurrentTaskId[CoreID]);
            /* here is the task restore point*/
        }
        else
        {
            /* event has been set, do nothing , return and continue to execute the task */
        }
        OsCpu_ExitCritical(CoreID, tempPri);
    }

    return ret;

}


#define OS_STOP_SEC_CODE
#include "Os_MemMap.h"


#endif /*((OS_CC == OS_ECC1) || (OS_CC == OS_ECC2))*/

