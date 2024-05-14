/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
* File Name:       Os_InternalCode.h
********************************************************************************
* Project/Product: AUTOSAR OS PROJECT
* Title:           Os_InternalCode.h
* Author:          Hirain
********************************************************************************
* Description:     Declare the internal functions used in different OS modules
*                  this file Can not seen by user
*                  OS API is not in this file
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
#ifndef OS_INTERNALCODE_H
#define OS_INTERNALCODE_H
#include "Os_Types.h"

/*****************************************************************************
* General QAC Suppression
******************************************************************************/
/*PRQA S 3432 EOF*/
/*
P2VAR and other macros in the Compiler conforms to AUTOSAR standard.There's no
need to revise.
OR
Parameters in macros or functions are useless for some hardware platforms, 
but they can not be deleted according to the requirements of 
AUTOSAR specification or compatibility.
*/

/*PRQA S 3429, 3410, 3453 EOF*/
/*
Function-like macro is OK.
*/

#define OS_START_SEC_CODE
#include "Os_MemMap.h"

/*****************************************************************************
* Os internal functions declare
******************************************************************************/

/*****************************************************************************
* Kernel
******************************************************************************/
#if(OS_CPULOAD_API == OS_ON)
extern FUNC(void, OS_CODE)  OsKernel_CheckCpuLoad
(
    CoreIdType CoreID,
    Os_boolean isIdleStart
);
#endif /*(OS_CPULOAD_API == OS_ON)*/

extern FUNC(Os_boolean, OS_CODE) OsKernel_NeedSchedule
(
    CoreIdType CoreID,
    Os_boolean isEnforce
);
extern FUNC(void, OS_CODE) OsKernel_InsertTask
(
    CoreIdType CoreID,
    TaskType TaskID
);
extern FUNC(void, OS_CODE) OsKernel_RemoveTask
(
    CoreIdType CoreID,
    TaskType TaskID
);
extern FUNC(void, OS_CODE) OsKernel_KillTask
(
    CoreIdType CoreID,
    TaskType TaskID
);

extern FUNC(void, OS_CODE) OsKernel_InternalShutdown
(
    CoreIdType CoreID,
    StatusType Error,
    ShutdownConceptType ShutdownType
); 

extern FUNC(void, OS_CODE) OsKernel_InternalSetMode
(
    CoreIdType CoreID
);

extern FUNC(void, OS_CODE)  OsKernel_ExitTask
(
    CoreIdType CoreID,
    Os_boolean isPreempt,
    TaskStateType nextState
);

extern FUNC(void, OS_CODE)  OsKernel_EnterTask
(
    CoreIdType CoreID,
    Os_boolean isRestore
);
extern FUNC(void, OS_CODE) OsKernel_CheckTaskSwitch
(
    CoreIdType CoreID
);

#if(OS_RESOURCE_NUMBER > 0)
extern FUNC(void, OS_CODE) OsKernel_InsertResCellingTask
(
    CoreIdType CoreID,
    TaskType TaskID,
    Os_PrioType taskPriority 
);

extern FUNC(void, OS_CODE) OsKernel_RemoveResCellingTask
(
    CoreIdType CoreID,
    TaskType TaskID,
    Os_PrioType taskPriority 
);
#endif /*(OS_RESOURCE_NUMBER > 0)*/

/*****************************************************************************
* Task
******************************************************************************/
extern FUNC(StatusType, OS_CODE) OsTask_InternalActivateTask
(
    CoreIdType CoreID,
    TaskType TaskID,
    Os_boolean needSchedule,
    OSServiceIdType ServiceId
);


extern FUNC(void, OS_CODE) OsTask_InternalTerminateTask
(
    CoreIdType CoreID
);

extern FUNC(void, OS_CODE) OsTask_Init
(
    CoreIdType CoreID
);

extern FUNC(void, OS_CODE) OsTask_AutoStart
(
    CoreIdType CoreID
);


extern FUNC(void, OS_CODE) OsTask_KillRunningTask
(
    CoreIdType CoreID,
    Os_boolean isKillAll
);

extern FUNC(void, OS_CODE) OsTask_KillTask
(
    CoreIdType CoreID,
    TaskType TaskID
);

/*****************************************************************************
* Event
******************************************************************************/
#if((OS_CC == OS_ECC1) || (OS_CC == OS_ECC2))
extern FUNC(StatusType, OS_CODE) OsEvent_InternalSetEvent
(
    CoreIdType CoreID,
    TaskType TaskID,
    EventMaskType Mask
);
#endif /*((OS_CC == OS_ECC1) || (OS_CC == OS_ECC2))*/

/*****************************************************************************
* Alarm
******************************************************************************/
extern FUNC(Os_boolean, OS_CODE) OsAlarm_Check
(
    CoreIdType CoreID,
    CounterType CounterID,
    AlarmType AlarmID
);
extern FUNC(void, OS_CODE) OsAlarm_Init
(
    CoreIdType CoreID
);

#if(OS_AUTO_ALARM_NUMBER > 0)
extern FUNC(void, OS_CODE) OsAlarm_AutoStart
(
    CoreIdType CoreID
);
#endif /*(OS_AUTO_ALARM_NUMBER > 0)*/

#if(OS_APPLICATION_NUMBER > 0)
extern FUNC(void, OS_CODE) OsAlarm_KillAlarm
(
    CoreIdType CoreID,
    AlarmType AlarmID
);
#endif /*(OS_APPLICATION_NUMBER > 0)*/

extern FUNC(StatusType, OS_CODE) OsAlarm_InternalSetRelAlarm
(
    CoreIdType CoreID,
    AlarmType AlarmID,
    TickType increment,
    TickType cycle
);
extern FUNC(StatusType, OS_CODE) OsAlarm_InternalSetAbsAlarm
(
    CoreIdType CoreID,
    AlarmType AlarmID,
    TickType start,
    TickType cycle
);
extern FUNC(StatusType, OS_CODE) OsAlarm_InternalCancelAlarm
(
    CoreIdType CoreID,
    AlarmType AlarmID
);

/*****************************************************************************
* Resource
******************************************************************************/
#if(OS_RESOURCE_NUMBER > 0)
extern FUNC(void, OS_CODE) OsRes_Init
(
    CoreIdType CoreID
);

extern FUNC(Os_boolean, OS_CODE) OsRes_AutoReleaseTaskResource
(
    CoreIdType CoreID,
    TaskType TaskID
);

extern FUNC(Os_boolean, OS_CODE) OsRes_AutoReleaseISRResource
(
    CoreIdType CoreID,
    ISRType ISRID
);
#endif /*(OS_RESOURCE_NUMBER > 0)*/

/*****************************************************************************
* ISR
******************************************************************************/
extern FUNC(void, OS_CODE) OsIsr_Init
(
    CoreIdType CoreID
);

extern FUNC(Os_boolean, OS_CODE) OsIsr_AutoResumeInterrupt
(
    CoreIdType CoreID
);

extern FUNC(void, OS_CODE)  OsIsr_InISR1
(
    CoreIdType CoreID
);

extern FUNC(void, OS_CODE)  OsIsr_OutISR1
(
    CoreIdType CoreID
);

extern FUNC(void, OS_CODE)  OsIsr_InISR2
(
    CoreIdType CoreID,
    ISRType ISRID,
    Os_AddrType ctxAddr
);
extern FUNC(Os_boolean, OS_CODE)  OsIsr_OutISR2
(
    CoreIdType CoreID
);

extern FUNC(void, OS_CODE) OsIsr_InternalSuspendAllInterrupts
(
    CoreIdType CoreID
);

extern FUNC(void, OS_CODE) OsIsr_InternalResumeAllInterrupts
(
    CoreIdType CoreID
);

extern FUNC(void, OS_CODE) OsIsr_InternalSuspendOsInterrupts
(
    CoreIdType CoreID
);

extern FUNC(void, OS_CODE) OsIsr_InternalResumeOsInterrupts
(
    CoreIdType CoreID
);

extern FUNC(void, OS_CODE) OsIsr_RemoveAndSortISRQueue
(
    CoreIdType CoreID,
    ApplicationType ApplID
);

#if(OS_APPLICATION_NUMBER > 0)
extern FUNC(void, OS_CODE) OsIsr_KillISR
(
    CoreIdType CoreID,
    ISRType ISRID
);
#endif /*(OS_APPLICATION_NUMBER > 0)*/

#if((OS_TIMING_PROTECTION_SUPPORT == OS_ON)||(OS_MEM_PROTECTION_SUPPORT == OS_ON)||(OS_APPLICATION_NUMBER > 0))
extern FUNC(void, OS_CODE) OsIsr_KillRunningISR
(
    CoreIdType CoreID,
    ISRType ISRID,
    Os_boolean isKillAll
);
#endif /*((OS_TIMING_PROTECTION_SUPPORT == OS_ON)||(OS_MEM_PROTECTION_SUPPORT == OS_ON)||(OS_APPLICATION_NUMBER > 0))*/

/*****************************************************************************
* Schedule Table
******************************************************************************/
#if(OS_SCHTBL_NUMBER > 0)
extern FUNC(void, OS_CODE) OsSchTbl_Init
(
    CoreIdType CoreID
);

extern FUNC(Os_boolean, OS_CODE) OsSchTbl_Trigger
(
    CoreIdType CoreID,
    CounterType CounterID,
    ScheduleTableType SchId
);

extern FUNC(StatusType, OS_CODE) OsSchTbl_InternalStartAbs
(
    CoreIdType CoreID,
    ScheduleTableType ScheduleTableID,
    TickType start
);

extern FUNC(StatusType, OS_CODE) OsSchTbl_InternalStartRel
(
    CoreIdType CoreID,
    ScheduleTableType ScheduleTableID,
    TickType offset,
    Os_boolean internalStart
);

extern FUNC(StatusType, OS_CODE) OsSchTbl_InternalStop
(
    CoreIdType CoreID,
    ScheduleTableType ScheduleTableID
);

#if(OS_AUTO_SCHTBL_NUMBER > 0)
extern FUNC(void, OS_CODE) OsSchTbl_AutoStart
(
    CoreIdType CoreID
);
#endif /*(OS_AUTO_SCHTBL_NUMBER > 0)*/

#if(OS_APPLICATION_NUMBER > 0)
extern FUNC(void, OS_CODE) OsSchTbl_Kill
(
    CoreIdType CoreID,
    ScheduleTableType SchId
);
#endif /*(OS_APPLICATION_NUMBER > 0)*/

#endif /*(OS_SCHTBL_NUMBER > 0)*/

/*****************************************************************************
* Counter
******************************************************************************/
#if(OS_SYSTICK_MODE == OS_HRT_MODE)
extern FUNC (Os_uint32, OS_CODE) OsCnt_CheckCounter
(
    CoreIdType CoreID,
    CounterType CounterID
);
#endif/*(OS_SYSTICK_MODE == OS_HRT_MODE)*/

extern FUNC(void, OS_CODE) OsCnt_InternalIncreaseCounter
(
    CoreIdType CoreID,
    CounterType CounterID
);

extern FUNC(void, OS_CODE) OsCnt_Init
(
    CoreIdType CoreID
);

#if((OS_ALARM_NUMBER > 0) || (OS_SCHTBL_NUMBER > 0))
extern FUNC(void, OS_CODE) OsCnt_TreeRemove
(
    CoreIdType CoreID,
    CounterType CounterID
);

extern FUNC(void, OS_CODE) OsCnt_DelTreeElement
(
    CoreIdType CoreID,
    CounterType CounterID,
    Os_uint32  ObjID,
    Os_boolean isAlarm
);

extern FUNC(void, OS_CODE) OsCnt_TreeInsert
(
    CoreIdType CoreID,
    CounterType CounterID,
    Os_uint32 ObjID,
    Os_boolean isAlarm
);
#endif /*((OS_ALARM_NUMBER > 0) || (OS_SCHTBL_NUMBER > 0))*/


/*****************************************************************************
* Spinlock
******************************************************************************/
#if(OS_SPINLOCK_NUMBER > 0)
extern FUNC(void, OS_CODE) OsSpinlock_Init(void);

extern FUNC(Os_boolean, OS_CODE) OsSpinLock_AutoReleaseISR
(
    CoreIdType CoreID,
    ISRType ISRID
);

extern FUNC(Os_boolean, OS_CODE) OsSpinLock_AutoReleaseTask
(
    CoreIdType CoreID,
    TaskType TaskID
);
#endif /*(OS_SPINLOCK_NUMBER > 0)*/

/*****************************************************************************
* Os-Application
******************************************************************************/
#if(OS_APPLICATION_NUMBER > 0)
extern FUNC(void, OS_CODE) OsApp_Init
(
    CoreIdType CoreID
);

extern FUNC(void, OS_CODE) OsApp_InternalTerminateApplication
(
    CoreIdType CoreID,
    ApplicationType Application,
    RestartType RestartOption
);

#endif /*(OS_APPLICATION_NUMBER > 0)*/

/*****************************************************************************
* IOC
******************************************************************************/
#if(OS_IOC_NUMBER > 0)
extern FUNC(void, OS_CODE) OsIoc_Init
(
    CoreIdType CoreID
);

#if(OS_STATUS_LEVEL == OS_EXTENDED)
extern FUNC(Std_ReturnType, OS_CODE) OsIoc_Check
(
    CoreIdType CoreID,
    Os_uint16 IocId,
    ApplicationType cfgAppId, /* this is sender or receiver's app id*/
    OSServiceIdType ApiId
);
#endif /*(OS_STATUS_LEVEL == OS_EXTENDED)*/
#endif /*(OS_IOC_NUMBER > 0)*/

/*****************************************************************************
* Memory Protection
******************************************************************************/


/*****************************************************************************
* Timing Protection
******************************************************************************/
#if(OS_ON == OS_TIMING_PROTECTION_SUPPORT)
extern FUNC(void, OS_CODE) OsTp_Init
(
    CoreIdType CoreID
);

extern FUNC(void, OS_CODE) OsTp_ProtectionProcess(void);
#endif /*(OS_ON == OS_TIMING_PROTECTION_SUPPORT)*/

#if(OS_TP_TSK_EXBUDGET_SUPPORT == OS_ON)
extern FUNC(void, OS_CODE) OsTp_TskExecutionBudgetStart
(
    CoreIdType CoreID,
    TaskType TaskID
);

extern FUNC(void, OS_CODE) OsTp_TskExecutionBudgetStop
(
    CoreIdType CoreID,
    TaskType TaskID
);

#else
#define OsTp_TskExecutionBudgetStart(CoreID, TaskID)
#define OsTp_TskExecutionBudgetStop(CoreID, TaskID)
#endif /*(OS_TP_TSK_EXBUDGET_SUPPORT == OS_ON)*/

#if((OS_TP_TSK_EXBUDGET_SUPPORT == OS_ON) || (OS_TP_TSK_RESOURCE_LOCKTIME_SUPPORT == OS_ON))
extern FUNC(void, OS_CODE) OsTp_TskPause
(
    CoreIdType CoreID,
    TaskType TaskID
);

extern FUNC(void, OS_CODE) OsTp_TskRestore
(
    CoreIdType CoreID,
    TaskType TaskID
);

#else
#define OsTp_TskPause(CoreID, TaskID)
#define OsTp_TskRestore(CoreID, TaskID)
#endif /*((OS_TP_TSK_EXBUDGET_SUPPORT == OS_ON) || (OS_TP_TSK_RESOURCE_LOCKTIME_SUPPORT == OS_ON))*/

#if(OS_TP_ISR_EXBUDGET_SUPPORT == OS_ON)
extern FUNC(void, OS_CODE) OsTp_IsrExecutionBudgetStart
(
    CoreIdType CoreID,
    ISRType ISRID
);
extern FUNC(void, OS_CODE) OsTp_IsrExecutionBudgetStop
(
    CoreIdType CoreID,
    ISRType ISRID
);

#else
#define OsTp_IsrExecutionBudgetStart(CoreID, TaskID)
#define OsTp_IsrExecutionBudgetStop(CoreID, TaskID)
#endif /*(OS_TP_ISR_EXBUDGET_SUPPORT == OS_ON)*/

#if((OS_TP_ISR_EXBUDGET_SUPPORT == OS_ON) || (OS_TP_ISR_RESOURCE_LOCKTIME_SUPPORT == OS_ON))
extern FUNC(void, OS_CODE) OsTp_IsrPause
(
    CoreIdType CoreID,
    ISRType ISRID
);

extern FUNC(void, OS_CODE) OsTp_IsrRestore
(
    CoreIdType CoreID,
    ISRType ISRID
);

#else
#define OsTp_IsrPause(CoreID, TaskID)
#define OsTp_IsrRestore(CoreID, TaskID)
#endif /*((OS_TP_ISR_EXBUDGET_SUPPORT == OS_ON) || (OS_TP_ISR_RESOURCE_LOCKTIME_SUPPORT == OS_ON))*/

#if((OS_TP_ISR_INTLOCKBUDGET_SUPPORT == OS_ON) || (OS_TP_TSK_INTLOCKBUDGET_SUPPORT == OS_ON))
extern FUNC(void, OS_CODE) OsTp_IsrLockTimeStart
(
    CoreIdType CoreID,
    Os_boolean isAllIntType
);

extern FUNC(void, OS_CODE) OsTp_IsrLockTimeStop
(
    CoreIdType CoreID,
    Os_boolean isAllIntType
);
#else
#define OsTp_IsrLockTimeStart(CoreID, isAllIntType)
#define OsTp_IsrLockTimeStop(CoreID, isAllIntType)
#endif /*((OS_TP_ISR_INTLOCKBUDGET_SUPPORT == OS_ON) || (OS_TP_TSK_INTLOCKBUDGET_SUPPORT == OS_ON))*/


#if(OS_TP_TSK_RESOURCE_LOCKTIME_SUPPORT == OS_ON)
extern FUNC(void, OS_CODE) OsTp_TskResourceLocktimeStart
(
    CoreIdType CoreID,
    TaskType TaskID,
    ResourceType offsetResId
);

extern FUNC(void, OS_CODE) OsTp_TskResourceLocktimeStop
(
    CoreIdType CoreID,
    TaskType TaskID,
    TaskType offsetResId
);
#else
#define OsTp_TskResourceLocktimeStart(CoreID, TaskID, offsetResId)  ((void)offsetResId)
#define OsTp_TskResourceLocktimeStop(CoreID, TaskID, offsetResId)  ((void)offsetResId)
#endif /*(OS_TP_TSK_RESOURCE_LOCKTIME_SUPPORT == OS_ON)*/


#if(OS_TP_ISR_RESOURCE_LOCKTIME_SUPPORT == OS_ON)
extern FUNC(void, OS_CODE) OsTp_IsrResourceLocktimeStart
(
    CoreIdType CoreID,
    ISRType ISRID,
    ResourceType offsetResId
);

extern FUNC(void, OS_CODE) OsTp_IsrResourceLocktimeStop
(
    CoreIdType CoreID,
    ISRType ISRID,
    TaskType offsetResId
);
#else
#define OsTp_IsrResourceLocktimeStart(CoreID, ISRID, offsetResId)  ((void)offsetResId)
#define OsTp_IsrResourceLocktimeStop(CoreID, ISRID, offsetResId)  ((void)offsetResId)
#endif /*(OS_TP_ISR_RESOURCE_LOCKTIME_SUPPORT == OS_ON)*/

#if(OS_TP_ISR_TIMEFRAME_SUPPORT == OS_ON)
extern FUNC(void, OS_CODE) OsTp_IsrTimeFrameCheck
(
    CoreIdType CoreID,
    ISRType ISRID
);
#else
#define OsTp_IsrTimeFrameCheck(CoreID, ISRID)
#endif /*(OS_TP_ISR_TIMEFRAME_SUPPORT == OS_ON)*/

#if(OS_TP_TSK_TIMEFRAME_SUPPORT == OS_ON)
extern FUNC(void, OS_CODE) OsTp_TskTimeFrameCheck
(
    CoreIdType CoreID,
    TaskType TaskID
);
#else
#define OsTp_TskTimeFrameCheck(CoreID, TaskID)
#endif /*(OS_TP_TSK_TIMEFRAME_SUPPORT == OS_ON)*/

/*****************************************************************************
* Multicore
******************************************************************************/
#if(OS_USED_CORE_NUMBER > 1)
extern FUNC(void, OS_CODE) OsMultiCore_Init
(
    CoreIdType CoreID
);

extern FUNC(StatusType, OS_CODE) OsMultiCore_TriggerActivateTask
(
    CoreIdType CoreID,
    TaskType TaskID
);

extern FUNC(StatusType, OS_CODE) OsMultiCore_TriggerTerminateApplication
(
    CoreIdType CoreID,
    ApplicationType Application,
    RestartType RestartOption
);

#if(OS_ALARM_NUMBER != 0)
extern FUNC(StatusType, OS_CODE) OsMultiCore_TriggerSetAbsAlarm
(
    CoreIdType CoreID,
    AlarmType AlarmID,
    TickType start,
    TickType cycle
);

extern FUNC(StatusType, OS_CODE) OsMultiCore_TriggerSetRelAlarm
(
    CoreIdType CoreID,
    AlarmType AlarmID,
    TickType increment,
    TickType cycle
);

extern FUNC(StatusType, OS_CODE) OsMultiCore_TriggerCancelAlarm
(
    CoreIdType CoreID,
    AlarmType AlarmID
);
#endif /*(OS_ALARM_NUMBER != 0)*/
#if((OS_CC == OS_ECC1) || (OS_CC == OS_ECC2))
extern FUNC(StatusType, OS_CODE) OsMultiCore_TriggerSetEvent
(
    CoreIdType CoreID,
    TaskType TaskID,
    EventMaskType Mask
);
#endif /*((OS_CC == OS_ECC1) || (OS_CC == OS_ECC2))*/
extern FUNC(void, OS_CODE) OsMultiCore_InternalShutdownAllCores
(
    CoreIdType CurrentCoreId,
    StatusType Error
);

extern FUNC(void, OS_CODE) OsMultiCore_CrossCoreProcess
(
    CoreIdType CurrentCoreId
);
#endif /*(OS_USED_CORE_NUMBER > 1)*/

/*****************************************************************************
* CRC
******************************************************************************/
#if(OS_CRC_SUPPORT == OS_ON)
extern FUNC(Os_uint8, OS_CODE) OsCrc_Calculate
(
    Os_AddrType startAddr
);
#endif

/*****************************************************************************
* Hook
******************************************************************************/
extern FUNC(void, OS_CODE) OsHook_Init
(
    CoreIdType CoreID
);

extern FUNC(void, OS_CODE) OsHook_FataErrReport
(
    CoreIdType CoreID,
    StatusType ErrorID,
    OSServiceIdType ServiceId,
    Os_uint16 ErrInfo,
    Os_uint32 par,
    Os_uint32 par1,
    Os_uint32 par2
);


#if((OS_STATUS_LEVEL == OS_EXTENDED) || (OS_ERRORHOOK_SUPPORT == OS_ON))
extern FUNC(void, OS_CODE) OsHook_ReportError
(
    CoreIdType CoreID,
    StatusType ErrorID,
    OSServiceIdType ServiceId,
    Os_uint16 ErrInfo,
    Os_uint32 par,
    Os_uint32 par1,
    Os_uint32 par2
);

extern FUNC(void, OS_CODE) OsHook_ReportErrorDisInt
(
    CoreIdType CoreID,
    StatusType ErrorID,
    OSServiceIdType ServiceId,
    Os_uint16 ErrInfo,
    Os_uint32 par,
    Os_uint32 par1,
    Os_uint32 par2
);
#else
#define OsHook_ReportError(CoreID, ErrorID, ServiceId, ErrInfo, par, par1, par2)
#define OsHook_ReportErrorDisInt(CoreID, ErrorID, ServiceId, ErrInfo, par, par1, par2)
#endif /*((OS_STATUS_LEVEL == OS_EXTENDED) || (OS_ERRORHOOK_SUPPORT == OS_ON))*/

#if(OS_STARTUPHOOK_SUPPORT == OS_ON)
extern FUNC(void, OS_CODE) OsHook_StartupHook
(
    CoreIdType CoreID
);
#else
#define OsHook_StartupHook(CoreID)
#endif /*(OS_STARTUPHOOK_SUPPORT == OS_ON)*/

#if(OS_SHUTDOWNHOOK_SUPPORT == OS_ON)
extern FUNC(void, OS_CODE) OsHook_ShutdownHook
(
    CoreIdType CoreID,
    StatusType Error
);
#else
#define OsHook_ShutdownHook(CoreID, Error)    (void)Error
#endif /*(OS_SHUTDOWNHOOK_SUPPORT == OS_ON)*/

#if(OS_PRETASKHOOK_SUPPORT == OS_ON)
extern FUNC(void, OS_CODE) OsHook_PreTaskHook
(
    CoreIdType CoreID
);
#else
#define OsHook_PreTaskHook(CoreID)
#endif /*(OS_PRETASKHOOK_SUPPORT == OS_ON)*/

#if(OS_POSTTASKHOOK_SUPPORT == OS_ON)
extern FUNC(void, OS_CODE) OsHook_PostTaskHook
(
    CoreIdType CoreID
);
#else
#define OsHook_PostTaskHook(CoreID)
#endif /*(OS_POSTTASKHOOK_SUPPORT == OS_ON)*/

#if(OS_PREISRHOOK_SUPPORT == OS_ON)
extern FUNC(void, OS_CODE) OsHook_PreISRHook
(
    CoreIdType CoreID
);
#else
#define OsHook_PreISRHook(CoreID)
#endif /*(OS_PREISRHOOK_SUPPORT == OS_ON)*/

#if(OS_POSTISRHOOK_SUPPORT == OS_ON)
extern FUNC(void, OS_CODE) OsHook_PostISRHook
(
    CoreIdType CoreID
);
#else
#define OsHook_PostISRHook(CoreID)
#endif /*(OS_POSTISRHOOK_SUPPORT == OS_ON)*/

extern FUNC(void, OS_CODE) OsHook_ProtectionHook
(
    CoreIdType CoreID,
    StatusType FatalError
);

#if(OS_OSAPP_STARTUPHOOK_SUPPORT == OS_ON)
extern FUNC(void, OS_CODE) OsHook_AppStartupHook
(
    CoreIdType CoreID,
    ApplicationType ApplID
);
#endif /*(OS_OSAPP_STARTUPHOOK_SUPPORT == OS_ON)*/

#if(OS_OSAPP_SHUTDOWNHOOK_SUPPORT == OS_ON)
extern FUNC(void, OS_CODE) OsHook_AppShutdownHook
(
    CoreIdType CoreID,
    StatusType ErrorID,
    ApplicationType ApplID
);
#endif /*(OS_OSAPP_SHUTDOWNHOOK_SUPPORT == OS_ON)*/

#if(OS_OSAPP_ERRORHOOK_SUPPORT == OS_ON)
extern FUNC(void, OS_CODE) OsHook_AppErrorHook
(
    CoreIdType CoreID,
    StatusType ErrorID,
    ApplicationType ApplID
);
#endif /*(OS_OSAPP_ERRORHOOK_SUPPORT == OS_ON)*/

/*****************************************************************************
* Os Api Functions Declare
******************************************************************************/
/*****************************************************************************
* Kernel
******************************************************************************/
extern FUNC(void, OS_CODE) OS_Init(void);
extern FUNC(void, OS_CODE) Os_StartOS(AppModeType OsAppMode);
extern FUNC(void, OS_CODE) Os_ShutdownOS(StatusType Error);
#if(OS_STACK_USEAGE_API == OS_ON)
extern FUNC(StatusType, OS_CODE) Os_GetTaskStackUsage(TaskType TaskID, CONSTP2VAR(Os_uint16, AUTOMATIC, OS_APPL_DATA) Value);
extern FUNC(StatusType, OS_CODE) Os_GetISRStackUsage(ISRType ISRId, CONSTP2VAR(Os_uint16, AUTOMATIC, OS_APPL_DATA) Value);
#endif /*(OS_STACK_USEAGE_API == OS_ON)*/
#if(OS_CPULOAD_API == OS_ON)
extern FUNC(StatusType, OS_CODE) Os_GetCpuLoadValue(CONSTP2VAR(Os_uint8, AUTOMATIC, OS_APPL_DATA) Value);
#endif /*(OS_CPULOAD_API == OS_ON)*/
extern FUNC(AppModeType, OS_CODE) Os_GetActiveApplicationMode(void);

/*****************************************************************************
* Task
******************************************************************************/
extern FUNC(StatusType, OS_CODE) Os_ActivateTask(TaskType TaskID);
extern FUNC(StatusType, OS_CODE) Os_TerminateTask(void);
extern FUNC(StatusType, OS_CODE) Os_ChainTask(TaskType TaskID);
extern FUNC(StatusType, OS_CODE) Os_Schedule(void);
extern FUNC(StatusType, OS_CODE) Os_GetTaskID(TaskRefType TaskID);
extern FUNC(StatusType, OS_CODE) Os_GetTaskState(TaskType TaskID, TaskStateRefType State);

/*****************************************************************************
* Event
******************************************************************************/
#if((OS_CC == OS_ECC1) || (OS_CC == OS_ECC2))
extern FUNC(StatusType, OS_CODE) Os_SetEvent(TaskType TaskID, EventMaskType Mask);
extern FUNC(StatusType, OS_CODE) Os_ClearEvent(EventMaskType Mask);
extern FUNC(StatusType, OS_CODE) Os_GetEvent(TaskType TaskID, EventMaskRefType Event);
extern FUNC(StatusType, OS_CODE) Os_WaitEvent(EventMaskType Mask);
#endif /*((OS_CC == OS_ECC1) || (OS_CC == OS_ECC2))*/

/*****************************************************************************
* Alarm
******************************************************************************/
extern FUNC(StatusType, OS_CODE) Os_GetAlarmBase(AlarmType AlarmID, AlarmBaseRefType Info);
extern FUNC(StatusType, OS_CODE) Os_GetAlarm(AlarmType AlarmID, TickRefType Tick);
extern FUNC(StatusType, OS_CODE) Os_SetRelAlarm(AlarmType AlarmID, TickType increment, TickType cycle);
extern FUNC(StatusType, OS_CODE) Os_SetAbsAlarm(AlarmType AlarmID, TickType start, TickType cycle);
extern FUNC(StatusType, OS_CODE) Os_CancelAlarm(AlarmType AlarmID);

/*****************************************************************************
* Counter
******************************************************************************/
#if(OS_USER_COUNTER_NUMBER > 0)
extern FUNC(StatusType, OS_CODE) Os_IncrementCounter(CounterType CounterID);
#endif /*(OS_USER_COUNTER_NUMBER > 0)*/
extern FUNC(StatusType, OS_CODE) Os_GetCounterValue(CounterType CounterID, TickRefType Value);
extern FUNC(StatusType, OS_CODE) Os_GetElapsedValue(CounterType CounterID, TickRefType Value, TickRefType ElapsedValue);

/*****************************************************************************
* Resource
******************************************************************************/
#if(OS_RESOURCE_NUMBER > 0)
extern FUNC(StatusType, OS_CODE) Os_GetResource(ResourceType ResID);
extern FUNC(StatusType, OS_CODE) Os_ReleaseResource(ResourceType ResID);
#endif /*(OS_RESOURCE_NUMBER > 0)*/

/*****************************************************************************
* ISR
***************************************************************************************************/
extern FUNC(void, OS_CODE) Os_DisableAllInterrupts
(
    void
);

extern FUNC(void, OS_CODE) Os_EnableAllInterrupts
(
    void
);

extern FUNC(void, OS_CODE) Os_SuspendAllInterrupts
(
    void
);

extern FUNC(void, OS_CODE) Os_ResumeAllInterrupts
(
    void
);

extern FUNC(void, OS_CODE) Os_SuspendOSInterrupts
(
    void
);

extern FUNC(void, OS_CODE) Os_ResumeOSInterrupts
(
    void
);

extern FUNC(ISRType, OS_CODE) Os_GetISRID
(
    void
);

/* SWS_Os_00808 */
extern FUNC(StatusType, OS_CODE) Os_EnableInterruptSource
(
    ISRType ISRID,
    boolean ClearPending
);

extern FUNC(StatusType, OS_CODE) Os_DisableInterruptSource
(
    ISRType ISRID
);

extern FUNC(StatusType, OS_CODE) Os_ClearPendingInterrupt
(
    ISRType ISRID
);

/***************************************************************************************************
* Schtbl
******************************************************************************/
#if(OS_SCHTBL_NUMBER > 0)
extern FUNC(StatusType, OS_CODE) Os_StartScheduleTableRel(ScheduleTableType ScheduleTableID, TickType Offset);
extern FUNC(StatusType, OS_CODE) Os_StartScheduleTableAbs(ScheduleTableType ScheduleTableID, TickType Start);
extern FUNC(StatusType, OS_CODE) Os_NextScheduleTable(ScheduleTableType ScheduleTableID_From, ScheduleTableType ScheduleTableID_To);
extern FUNC(StatusType, OS_CODE) Os_StopScheduleTable(ScheduleTableType ScheduleTableID);
extern FUNC(StatusType, OS_CODE) Os_GetScheduleTableStatus(ScheduleTableType ScheduleTableID, ScheduleTableStatusRefType ScheduleStatus);
#endif /*(OS_SCHTBL_NUMBER > 0)*/

/*****************************************************************************
* Spinlock
******************************************************************************/
#if(OS_SPINLOCK_NUMBER > 0)
extern FUNC(StatusType, OS_CODE) Os_GetSpinlock(SpinlockIdType SpinlockID);
extern FUNC(StatusType, OS_CODE) Os_ReleaseSpinlock(SpinlockIdType SpinlockID);
extern FUNC(StatusType, OS_CODE) Os_TryToGetSpinlock(SpinlockIdType SpinlockID, P2VAR(TryToGetSpinlockType, AUTOMATIC, OS_APPL_DATA) Success);
#endif /*(OS_SPINLOCK_NUMBER > 0)*/

/*****************************************************************************
* Application
******************************************************************************/
#if(OS_APPLICATION_NUMBER > 0)
extern FUNC(ApplicationType, OS_CODE) Os_GetApplicationID(void);
extern FUNC(ApplicationType, OS_CODE) Os_GetCurrentApplicationID(void);
extern FUNC(ObjectAccessType, OS_CODE) Os_CheckObjectAccess(ApplicationType ApplID, ObjectTypeType ObjectType, Os_ObjectIdType ObjectId);
extern FUNC(ApplicationType, OS_CODE) Os_CheckObjectOwnership(ObjectTypeType ObjectType, Os_ObjectIdType ObjectId);
extern FUNC(StatusType, OS_CODE) Os_TerminateApplication(ApplicationType Application, RestartType RestartOption);
extern FUNC(StatusType, OS_CODE) Os_AllowAccess(void);
extern FUNC(StatusType, OS_CODE) Os_GetApplicationState(ApplicationType Application, ApplicationStateRefType Value);

#if(OS_TRUSTED_FUNCTION_NUMBER > 0)
extern FUNC(StatusType, OS_CODE) Os_CallTrustedFunction(TrustedFunctionIndexType FunctionIndex, TrustedFunctionParameterRefType FunctionParams);
#endif /*(OS_TRUSTED_FUNCTION_NUMBER > 0)*/

#endif /*(OS_APPLICATION_NUMBER > 0)*/

/*****************************************************************************
* Multicore
******************************************************************************/
#if(OS_USED_CORE_NUMBER > 1)
extern FUNC(void, OS_CODE) Os_ShutdownAllCores(StatusType Error);
extern FUNC(void, OS_CODE) Os_StartCore(CoreIdType CoreID, P2VAR(StatusType, AUTOMATIC, OS_APPL_DATA) Status);
extern FUNC(CoreIdType, OS_CODE) Os_GetCoreID(void);
extern FUNC(Os_uint32, OS_CODE) Os_GetNumberOfActivatedCores(void);
extern FUNC(StatusType, OS_CODE) Os_ControlIdle(CoreIdType CoreID, IdleModeType IdleMode);
#endif /*(OS_USED_CORE_NUMBER > 1)*/

#if(OS_PL_MAX_CORE_NUMBER > 1)
extern FUNC(void, OS_CODE) Os_StartNonAutosarCore(CoreIdType CoreID, P2VAR(StatusType, AUTOMATIC, OS_APPL_DATA) Status);
#endif /*(OS_PL_MAX_CORE_NUMBER > 1)*/

#define OS_STOP_SEC_CODE
#include "Os_MemMap.h"

#define OS_START_SEC_CALLOUT_CODE
#include "Os_MemMap.h"

/*****************************************************************************
* Callout
******************************************************************************/
#if(OS_ON == OS_ERRORHOOK_SUPPORT)
extern FUNC(void, OS_CALLOUT_CODE) ErrorHook(StatusType Error);
#endif /*(OS_ON == OS_ERRORHOOK_SUPPORT)*/

#if(OS_SHUTDOWNHOOK_SUPPORT == OS_ON)
extern FUNC(void, OS_CALLOUT_CODE) ShutdownHook(StatusType Error);
#endif /*(OS_SHUTDOWNHOOK_SUPPORT == OS_ON)*/

#if(OS_ON == OS_STARTUPHOOK_SUPPORT)
extern FUNC(void, OS_CALLOUT_CODE) StartupHook(void);
#endif /*(OS_ON == OS_STARTUPHOOK_SUPPORT)*/

#if(OS_ON == OS_PRETASKHOOK_SUPPORT)
extern FUNC(void, OS_CALLOUT_CODE) PreTaskHook(void);
#endif /*(OS_ON == OS_PRETASKHOOK_SUPPORT)*/

#if(OS_ON == OS_POSTTASKHOOK_SUPPORT)
extern FUNC(void, OS_CALLOUT_CODE) PostTaskHook(void);
#endif /*(OS_ON == OS_POSTTASKHOOK_SUPPORT)*/

#if(OS_ON == OS_PREISRHOOK_SUPPORT)
extern FUNC(void, OS_CALLOUT_CODE) PreISRHook(void);
#endif /*(OS_ON == OS_PREISRHOOK_SUPPORT)*/

#if(OS_ON == OS_POSTISRHOOK_SUPPORT)
extern FUNC(void, OS_CALLOUT_CODE) PostISRHook(void);
#endif /*(OS_ON == OS_POSTISRHOOK_SUPPORT)*/

#if(OS_ON == OS_PROTECTIONHOOK_SUPPORT)
extern FUNC(ProtectionReturnType, OS_CALLOUT_CODE) ProtectionHook(StatusType FatalError);
#endif /*(OS_ON == OS_PROTECTIONHOOK_SUPPORT)*/

#define OS_STOP_SEC_CALLOUT_CODE
#include "Os_MemMap.h"

#endif /*OS_INTERNALCODE_H*/
