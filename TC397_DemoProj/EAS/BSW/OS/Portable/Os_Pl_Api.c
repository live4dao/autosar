/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
* File Name:       Os_Pl_Api.c
********************************************************************************
* Project/Product: AUTOSAR OS PROJECT
* Title:           Os_Pl_Api.c
* Author:          Hirain
********************************************************************************
* Description:     Pl Apis Module of OS
*
********************************************************************************
* Limitations     : None
*
********************************************************************************
*
********************************************************************************
*   Revision History:
*   Reference to Core Os_Cpu.c File
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
/*PRQA S 3200 EOF*/
/*
Return value of "OsCpu_PreAPI" can not be removed for compatibility.
*/
/*PRQA S 3408 EOF*/
/*
For TC3xx, trap functions are called by hardware, so no need to declaration.
*/
/*PRQA S 3432 EOF*/
/*
P2VAR and other macros in the Compiler conforms to AUTOSAR standard.There's no
need to revise.
*/
#define OS_START_SEC_CODE
#include "Os_MemMap.h"

#if(OS_MEM_PROTECTION_SUPPORT == OS_ON)
#if(OS_USED_CORE_NUMBER > 1)
FUNC(StatusType, OS_CODE)Os_Pl_ControlIdle
(
    CoreIdType CoreID,
    IdleModeType IdleMode
)
{
    StatusType ret;
    OsCpu_PreAPI();
    ret = Os_ControlIdle(CoreID, IdleMode);
    return ret;
}
#endif
FUNC(StatusType, OS_CODE)Os_Pl_ActivateTask
(
    TaskType TaskID
)
{
    StatusType ret;
    OsCpu_PreAPI();
    ret = Os_ActivateTask(TaskID);
    return ret;
}

FUNC(void, OS_CODE)Os_Pl_ShutdownOS
(
    StatusType Error
)
{
    OsCpu_PreAPI();
    Os_ShutdownOS(Error);
}
#if(OS_USED_CORE_NUMBER > 1)
FUNC(void, OS_CODE)Os_Pl_ShutdownAllCores
(
    StatusType Error
)
{
    OsCpu_PreAPI();
    Os_ShutdownAllCores(Error);
}
#endif
FUNC(StatusType, OS_CODE)Os_Pl_TerminateTask
(
    void
)
{
    StatusType ret;
    OsCpu_PreAPI();
    ret = Os_TerminateTask();
    return ret;
}

FUNC(StatusType, OS_CODE)Os_Pl_ChainTask
(
    TaskType TaskID
)
{
    StatusType ret;
    OsCpu_PreAPI();
    ret = Os_ChainTask(TaskID);
    return ret;
}

FUNC(StatusType, OS_CODE)Os_Pl_Schedule
(
    void
)
{
    StatusType ret;
    OsCpu_PreAPI();
    ret = Os_Schedule();
    return ret;
}

FUNC(StatusType, OS_CODE)Os_Pl_GetTaskID
(
    TaskRefType TaskID
)
{
    StatusType ret;
    OsCpu_PreAPI();
    ret = Os_GetTaskID(TaskID);
    return ret;
}

FUNC(StatusType, OS_CODE)Os_Pl_GetTaskState
(
    TaskType TaskID,
    TaskStateRefType State
)
{
    StatusType ret;
    OsCpu_PreAPI();
    ret = Os_GetTaskState(TaskID,State);
    return ret;
}

/*Event*/
#if((OS_CC == OS_ECC1) || (OS_CC == OS_ECC2))

FUNC(StatusType, OS_CODE)Os_Pl_SetEvent
(
    TaskType TaskID,
    EventMaskType Mask
)
{
    StatusType ret;
    OsCpu_PreAPI();
    ret = Os_SetEvent(TaskID,Mask);
    return ret;
}

FUNC(StatusType, OS_CODE)Os_Pl_ClearEvent
(
    EventMaskType Mask
)
{
    StatusType ret;
    OsCpu_PreAPI();
    ret = Os_ClearEvent(Mask);
    return ret;
}

FUNC(StatusType, OS_CODE)Os_Pl_GetEvent
(
    TaskType TaskID,
    EventMaskRefType Event
)
{
    StatusType ret;
    OsCpu_PreAPI();
    ret = Os_GetEvent(TaskID,Event);
    return ret;
}

FUNC(StatusType, OS_CODE)Os_Pl_WaitEvent
(
    EventMaskType Mask
)
{
    StatusType ret;
    OsCpu_PreAPI();
    ret = Os_WaitEvent(Mask);
    return ret;
}
#endif

#if(OS_ALARM_NUMBER > 0)
/*Alarm*/
FUNC(StatusType, OS_CODE)Os_Pl_GetAlarmBase
(
    AlarmType AlarmID,
    AlarmBaseRefType Info
)
{
    StatusType ret;
    OsCpu_PreAPI();
    ret = Os_GetAlarmBase(AlarmID, Info);
    return ret;
}

FUNC(StatusType, OS_CODE)Os_Pl_GetAlarm
(
    AlarmType AlarmID,
    TickRefType Tick
)
{
    StatusType ret;
    OsCpu_PreAPI();
    ret = Os_GetAlarm(AlarmID, Tick);
    return ret;
}

FUNC(StatusType, OS_CODE)Os_Pl_SetRelAlarm
(
    AlarmType AlarmID,
    TickType increment,
    TickType cycle
)
{
    StatusType ret;
    OsCpu_PreAPI();
    ret = Os_SetRelAlarm(AlarmID, increment, cycle);
    return ret;
}

FUNC(StatusType, OS_CODE)Os_Pl_SetAbsAlarm
(
    AlarmType AlarmID,
    TickType start,
    TickType cycle
)
{
    StatusType ret;
    OsCpu_PreAPI();
    ret = Os_SetAbsAlarm(AlarmID, start, cycle);
    return ret;
}

FUNC(StatusType, OS_CODE)Os_Pl_CancelAlarm
(
    AlarmType AlarmID
)
{
    StatusType ret;
    OsCpu_PreAPI();
    ret = Os_CancelAlarm(AlarmID);
    return ret;
}
#endif

/*Counter*/
#if(OS_USER_COUNTER_NUMBER > 0)
FUNC(StatusType, OS_CODE)Os_Pl_IncrementCounter
(
    CounterType CounterID
)
{
    StatusType ret;
    OsCpu_PreAPI();
    ret = Os_IncrementCounter(CounterID);
    return ret;
}
#endif

FUNC(StatusType, OS_CODE)Os_Pl_GetCounterValue
(
    CounterType CounterID,
    TickRefType Value
)
{
    StatusType ret;
    OsCpu_PreAPI();
    ret = Os_GetCounterValue(CounterID, Value);
    return ret;
}

FUNC(StatusType, OS_CODE)Os_Pl_GetElapsedValue
(
    CounterType CounterID,
    TickRefType Value,
    TickRefType ElapsedValue
)
{
    StatusType ret;
    OsCpu_PreAPI();
    ret = Os_GetElapsedValue(CounterID, Value, ElapsedValue);
    return ret;
}

/*Resource*/
#if(OS_RESOURCE_NUMBER > 0)
FUNC(StatusType, OS_CODE)Os_Pl_GetResource
(
    ResourceType ResID
)
{
    StatusType ret;
    OsCpu_PreAPI();
    ret = Os_GetResource(ResID);
    return ret;
}

FUNC(StatusType, OS_CODE)Os_Pl_ReleaseResource
(
    ResourceType ResID
)
{
    StatusType ret;
    OsCpu_PreAPI();
    ret = Os_ReleaseResource(ResID);
    return ret;
}
#endif

/*Schtbl*/
#if(OS_SCHTBL_NUMBER > 0)

FUNC(StatusType, OS_CODE)Os_Pl_StartScheduleTableRel
(
    ScheduleTableType ScheduleTableID,
    TickType Offset
)
{
    StatusType ret;
    OsCpu_PreAPI();
    ret = Os_StartScheduleTableRel(ScheduleTableID, Offset);
    return ret;
}

FUNC(StatusType, OS_CODE)Os_Pl_StartScheduleTableAbs
(
    ScheduleTableType ScheduleTableID,
    TickType Start
)
{
    StatusType ret;
    OsCpu_PreAPI();
    ret = Os_StartScheduleTableAbs(ScheduleTableID, Start);
    return ret;
}

FUNC(StatusType, OS_CODE)Os_Pl_NextScheduleTable
(
    ScheduleTableType ScheduleTableID_From,
    ScheduleTableType ScheduleTableID_To
)
{
    StatusType ret;
    OsCpu_PreAPI();
    ret = Os_NextScheduleTable(ScheduleTableID_From, ScheduleTableID_To);
    return ret;
}

FUNC(StatusType, OS_CODE)Os_Pl_StopScheduleTable
(
    ScheduleTableType ScheduleTableID
)
{
    StatusType ret;
    OsCpu_PreAPI();
    ret = Os_StopScheduleTable(ScheduleTableID);
    return ret;
}

FUNC(StatusType, OS_CODE)Os_Pl_GetScheduleTableStatus
(
    ScheduleTableType ScheduleTableID,
    ScheduleTableStatusRefType ScheduleStatus
)
{
    StatusType ret;
    OsCpu_PreAPI();
    ret = Os_GetScheduleTableStatus(ScheduleTableID, ScheduleStatus);
    return ret;
}
#endif

/*ISR*/
FUNC(void, OS_CODE) Os_Pl_DisableAllInterrupts
(
    void
)
{
    OsCpu_PreAPI();
    Os_DisableAllInterrupts();
}

FUNC(void, OS_CODE) Os_Pl_EnableAllInterrupts
(
    void
)
{
    OsCpu_PreAPI();
    Os_EnableAllInterrupts();
}

FUNC(void, OS_CODE) Os_Pl_SuspendAllInterrupts
(
    void
)
{
    OsCpu_PreAPI();
    Os_SuspendAllInterrupts();
}

FUNC(void, OS_CODE) Os_Pl_ResumeAllInterrupts
(
    void
)
{
    OsCpu_PreAPI();
    Os_ResumeAllInterrupts();
}

FUNC(void, OS_CODE) Os_Pl_SuspendOSInterrupts
(
    void
)
{
    OsCpu_PreAPI();
    Os_SuspendOSInterrupts();
}

FUNC(void, OS_CODE) Os_Pl_ResumeOSInterrupts
(
    void
)
{
    OsCpu_PreAPI();
    Os_ResumeOSInterrupts();
}

FUNC(ISRType, OS_CODE) Os_Pl_GetISRID
(
    void
)
{
    ISRType tempId;
    OsCpu_PreAPI();
    tempId = Os_GetISRID();
    return tempId;
}

/*SpinLock*/
#if(OS_SPINLOCK_NUMBER > 0)
FUNC(StatusType, OS_CODE)Os_Pl_GetSpinlock
(
    SpinlockIdType SpinlockID 
)
{
    StatusType ret;
    OsCpu_PreAPI();
    ret = Os_GetSpinlock(SpinlockID);
    return ret;
}

FUNC(StatusType, OS_CODE)Os_Pl_ReleaseSpinlock
(
    SpinlockIdType SpinlockID 
)
{
    StatusType ret;
    OsCpu_PreAPI();
    ret = Os_ReleaseSpinlock(SpinlockID);
    return ret;
}

FUNC(StatusType, OS_CODE)Os_Pl_TryToGetSpinlock
(
    SpinlockIdType SpinlockID, 
    P2VAR(TryToGetSpinlockType, AUTOMATIC, OS_APPL_DATA)Success
)
{
    StatusType ret;
    OsCpu_PreAPI();
    ret = Os_TryToGetSpinlock(SpinlockID, Success);
    return ret;
}
#endif

/*Application*/
#if(OS_APPLICATION_NUMBER > 0)
FUNC(ApplicationType, OS_CODE)Os_Pl_GetApplicationID
(
    void
)
{
    ApplicationType ret;
    OsCpu_PreAPI();
    ret = Os_GetApplicationID();
    return ret;
}

FUNC(ApplicationType, OS_CODE)Os_Pl_GetCurrentApplicationID
(
    void
)
{
    ApplicationType ret;
    OsCpu_PreAPI();
    ret = Os_GetCurrentApplicationID();
    return ret;
}

#if(OS_ON == OS_OSAPP_RESTARTTASK_SUPPORT)
FUNC(StatusType, OS_CODE)Os_Pl_AllowAccess
(
    void
)
{
    StatusType ret;
    OsCpu_PreAPI();
    ret = Os_AllowAccess();
    return ret;
}
#endif/*#if(OS_ON == OS_OSAPP_RESTARTTASK_SUPPORT)*/

FUNC(StatusType, OS_CODE)Os_Pl_GetApplicationState
(
    ApplicationType Application,
    ApplicationStateRefType Value
)
{
    StatusType ret;
    OsCpu_PreAPI();
    ret = Os_GetApplicationState(Application,Value);
    return ret;
}

FUNC(StatusType, OS_CODE)Os_Pl_TerminateApplication
(
    ApplicationType Application,
    RestartType RestartOption
)
{
    StatusType ret;
    OsCpu_PreAPI();
    ret = Os_TerminateApplication(Application,RestartOption);
    return ret;
}

FUNC(ObjectAccessType, OS_CODE)Os_Pl_CheckObjectAccess
(
    ApplicationType ApplID,
    ObjectTypeType ObjectType,
    Os_ObjectIdType ObjectId
)
{
    ObjectAccessType ret;
    OsCpu_PreAPI();
    ret = Os_CheckObjectAccess(ApplID, ObjectType, ObjectId);
    return ret;
}

FUNC(ApplicationType, OS_CODE) Os_Pl_CheckObjectOwnership
(
    ObjectTypeType ObjectType,
    Os_ObjectIdType ObjectId
)
{
    ApplicationType ret;
    OsCpu_PreAPI();
    ret = Os_CheckObjectOwnership(ObjectType, ObjectId);
    return ret;
}

#endif

#if(OS_TRUSTED_FUNCTION_NUMBER > 0)
FUNC(StatusType, OS_CODE) Os_Pl_CallTrustedFunction
(
    TrustedFunctionIndexType FunctionIndex,
    TrustedFunctionParameterRefType FunctionParams
)
{
    StatusType ret;
    OsCpu_PreAPI();
    ret = Os_CallTrustedFunction (FunctionIndex, FunctionParams);
    return ret;
}
#endif
#if(OS_USED_CORE_NUMBER > 1)
FUNC(Os_uint32, OS_CODE)Os_Pl_GetNumberOfActivatedCores(void)
{
    Os_uint32 ret;
    OsCpu_PreAPI();
    ret = Os_GetNumberOfActivatedCores();
    return ret;
}
#endif
#endif
#define OS_STOP_SEC_CODE
#include "Os_MemMap.h"
