/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
* File Name:       Os_Pl_InternalCode.h
********************************************************************************
* Project/Product: AUTOSAR EAS
* Title:           Os_Pl_InternalCode.h
* Author:          Hirain
********************************************************************************
* Description:     Declare of portable layer functions
*
********************************************************************************
* Limitations     : None
*
********************************************************************************
*
********************************************************************************
*   Revision History:
*   Reference to Os_Cpu.c File
********************************************************************************
* END_FILE_HDR*/

#ifndef OS_PL_INTERNALCODE_H
#define OS_PL_INTERNALCODE_H
#include "Os_Types.h"

/*****************************************************************************
* General QAC Suppression
******************************************************************************/
/*PRQA S 3432 EOF*/
/*
P2VAR and other macros in the Compiler conforms to AUTOSAR standard.There's no
need to revise.
*/

/*PRQA S 3453,3429 EOF*/
/*
Macro functions are allowed to use to access parameters and do some 
simple operations.
These function-like macros are AUTOSAR standard API, they will be used as
prefixion when define functions, variable and so on. So the parameters or the
body of the macros cannot be enclosed in ().
This part of code is verified manually and has no impact.
*/

/*PRQA S 3209 EOF*/
/*
Can not remove return values for compatibility.
*/

#define OS_START_SEC_CODE
#include "Os_MemMap.h"

/*****************************************************************************
* Os Api Functions Declare
******************************************************************************/
#if(OS_APPLICATION_NUMBER > 0)
#if(OS_USED_CORE_NUMBER > 1)
/*****************************************************************************
* Multicore
******************************************************************************/
extern FUNC(void, OS_CODE) Os_Pl_ShutdownAllCores(StatusType Error);
extern FUNC(StatusType, OS_CODE) Os_Pl_ControlIdle(CoreIdType CoreID, IdleModeType IdleMode);
extern FUNC(Os_uint32, OS_CODE)Os_Pl_GetNumberOfActivatedCores(void);
#endif

/*****************************************************************************
* Kernel
******************************************************************************/
extern FUNC(void, OS_CODE) Os_Pl_ShutdownOS(StatusType Error);

/*****************************************************************************
* Task
******************************************************************************/
extern FUNC(StatusType, OS_CODE) Os_Pl_ActivateTask(TaskType TaskID);
extern FUNC(StatusType, OS_CODE) Os_Pl_TerminateTask(void);
extern FUNC(StatusType, OS_CODE) Os_Pl_ChainTask(TaskType TaskID);
extern FUNC(StatusType, OS_CODE) Os_Pl_Schedule(void);
extern FUNC(StatusType, OS_CODE) Os_Pl_GetTaskID(TaskRefType TaskID);
extern FUNC(StatusType, OS_CODE) Os_Pl_GetTaskState(TaskType TaskID, TaskStateRefType State);

/*****************************************************************************
* Event
******************************************************************************/
#if((OS_CC == OS_ECC1) || (OS_CC == OS_ECC2))
extern FUNC(StatusType, OS_CODE) Os_Pl_SetEvent(TaskType TaskID, EventMaskType Mask);
extern FUNC(StatusType, OS_CODE) Os_Pl_ClearEvent(EventMaskType Mask);
extern FUNC(StatusType, OS_CODE) Os_Pl_GetEvent(TaskType TaskID, EventMaskRefType Event);
extern FUNC(StatusType, OS_CODE) Os_Pl_WaitEvent(EventMaskType Mask);
#endif

/*****************************************************************************
* Alarm
******************************************************************************/
extern FUNC(StatusType, OS_CODE) Os_Pl_GetAlarmBase(AlarmType AlarmID, AlarmBaseRefType Info);
extern FUNC(StatusType, OS_CODE) Os_Pl_GetAlarm(AlarmType AlarmID, TickRefType Tick);
extern FUNC(StatusType, OS_CODE) Os_Pl_SetRelAlarm(AlarmType AlarmID, TickType increment, TickType cycle);
extern FUNC(StatusType, OS_CODE) Os_Pl_SetAbsAlarm(AlarmType AlarmID, TickType start, TickType cycle);
extern FUNC(StatusType, OS_CODE) Os_Pl_CancelAlarm(AlarmType AlarmID);

/*****************************************************************************
* Counter
******************************************************************************/
#if(OS_USER_COUNTER_NUMBER > 0)
extern FUNC(StatusType, OS_CODE) Os_Pl_IncrementCounter(CounterType CounterID);
#endif
extern FUNC(StatusType, OS_CODE) Os_Pl_GetCounterValue(CounterType CounterID, TickRefType Value);
extern FUNC(StatusType, OS_CODE) Os_Pl_GetElapsedValue(CounterType CounterID, TickRefType Value, TickRefType ElapsedValue);

/*****************************************************************************
* Resource
******************************************************************************/
#if(OS_RESOURCE_NUMBER > 0)
extern FUNC(StatusType, OS_CODE) Os_Pl_GetResource(ResourceType ResID);
extern FUNC(StatusType, OS_CODE) Os_Pl_ReleaseResource(ResourceType ResID);
#endif

/*****************************************************************************
* Schtbl
******************************************************************************/
#if(OS_SCHTBL_NUMBER > 0)
extern FUNC(StatusType, OS_CODE) Os_Pl_StartScheduleTableRel(ScheduleTableType ScheduleTableID, TickType Offset);
extern FUNC(StatusType, OS_CODE) Os_Pl_StartScheduleTableAbs(ScheduleTableType ScheduleTableID, TickType Start);
extern FUNC(StatusType, OS_CODE) Os_Pl_NextScheduleTable(ScheduleTableType ScheduleTableID_From, ScheduleTableType ScheduleTableID_To);
extern FUNC(StatusType, OS_CODE) Os_Pl_StopScheduleTable(ScheduleTableType ScheduleTableID);
extern FUNC(StatusType, OS_CODE) Os_Pl_GetScheduleTableStatus(ScheduleTableType ScheduleTableID, ScheduleTableStatusRefType ScheduleStatus);
#endif

/*****************************************************************************
* ISR
******************************************************************************/
extern FUNC(void, OS_CODE) Os_Pl_DisableAllInterrupts(void);
extern FUNC(void, OS_CODE) Os_Pl_EnableAllInterrupts(void);
extern FUNC(void, OS_CODE) Os_Pl_SuspendAllInterrupts(void);
extern FUNC(void, OS_CODE) Os_Pl_ResumeAllInterrupts(void);
extern FUNC(void, OS_CODE) Os_Pl_SuspendOSInterrupts(void);
extern FUNC(void, OS_CODE) Os_Pl_ResumeOSInterrupts(void);
extern FUNC(ISRType, OS_CODE) Os_Pl_GetISRID(void);

/*****************************************************************************
* Spinlock
******************************************************************************/
#if(OS_SPINLOCK_NUMBER > 0)
extern FUNC(StatusType, OS_CODE) Os_Pl_GetSpinlock(SpinlockIdType SpinlockID);
extern FUNC(StatusType, OS_CODE) Os_Pl_ReleaseSpinlock(SpinlockIdType SpinlockID);
extern FUNC(StatusType, OS_CODE) Os_Pl_TryToGetSpinlock(SpinlockIdType SpinlockID, P2VAR(TryToGetSpinlockType, AUTOMATIC, OS_APPL_DATA) Success);
#endif

/*****************************************************************************
* Application
******************************************************************************/
extern FUNC(ApplicationType, OS_CODE) Os_Pl_GetApplicationID(void);
extern FUNC(ApplicationType, OS_CODE) Os_Pl_GetCurrentApplicationID(void);
extern FUNC(ObjectAccessType, OS_CODE) Os_Pl_CheckObjectAccess(ApplicationType ApplID, ObjectTypeType ObjectType, Os_ObjectIdType ObjectId);
extern FUNC(ApplicationType, OS_CODE) Os_Pl_CheckObjectOwnership(ObjectTypeType ObjectType, Os_ObjectIdType ObjectId);
extern FUNC(StatusType, OS_CODE) Os_Pl_TerminateApplication(ApplicationType Application, RestartType RestartOption);
extern FUNC(StatusType, OS_CODE) Os_Pl_AllowAccess(void);
extern FUNC(StatusType, OS_CODE) Os_Pl_GetApplicationState(ApplicationType Application, ApplicationStateRefType Value);

#endif
#if(OS_TRUSTED_FUNCTION_NUMBER > 0)
extern FUNC(StatusType, OS_CODE) Os_Pl_CallTrustedFunction
(
    TrustedFunctionIndexType FunctionIndex,
    TrustedFunctionParameterRefType FunctionParams
)
#endif/* (OS_TRUSTED_FUNCTION_NUMBER > 0) */
/*****************************************************************************
* CPU
******************************************************************************/
extern FUNC(void, OS_CODE) OsCpu_Init(CoreIdType CoreID);
extern FUNC(void , OS_CODE)  OsCpu_FirstSchedule
(
    CoreIdType CoreID
);
extern FUNC(void , OS_CODE)OsCpu_TaskTerminateSchedule
(
    CoreIdType CoreID,
    TaskType TaskID
);

#define OsCpu_TaskPreemptSchedule(CoreID, taskId)   OS_PL_SYSCALL(OS_SYSCALL_TIN)

extern FUNC(void, OS_CODE)  OsCpu_InternalTaskPreempt(void);

extern FUNC(void, OS_CODE)  OsCpu_TaskSwitch(void);

extern FUNC(void, OS_CODE) OsCpu_EnterCritical
(
    CoreIdType CoreID,
    P2VAR(Os_boolean, AUTOMATIC, AUTOMATIC) gIntState
);

#define OsCpu_ExitCritical(CoreID, gIntState)  OsIntc_SetGlobalIntState(CoreID, gIntState)


extern FUNC(CoreIdType, OS_CODE) OsCpu_GetCoreID(void);


#define OsCpu_GetPhyCoreId()  (CoreIdType)(OS_PL_MFCR(OS_PL_CPU_COREID_REG))


extern FUNC(void, OS_CODE) OsCpu_SetMode(CoreIdType CoreID, Os_uint8 mode);







extern FUNC(void, OS_CODE) OsIntc_FreeISRCSA
(
    CoreIdType CoreID,
    ISRType ISRID
);

extern FUNC(void, OS_CODE) OsCpu_FreeTaskCSA
(
    CoreIdType CoreID,
    TaskType TaskID
);

extern FUNC(Os_AddrType, OS_CODE) OsCpu_ConvertAddr
(
    Os_AddrType pcxAddr
);

extern FUNC(Os_uint16, OS_CODE) OsCpu_GetCpuWatchdogPassword
(
    CoreIdType phyCoreID
);
extern FUNC(void, OS_CODE) OsCpu_ClearCpuEndinit
(
    CoreIdType phyCoreID,
    Os_uint16 password
);
extern FUNC(void, OS_CODE) OsCpu_SetCpuEndinit
(
    CoreIdType phyCoreID,
    Os_uint16 password
);

/*****************************************************************************
* Timer
******************************************************************************/
extern FUNC(void, OS_CODE) OsSysTimer_Init(CoreIdType CoreID);
extern FUNC(void, OS_CODE) OsSysTimer_Run(CoreIdType CoreID);

extern FUNC(void, OS_CODE) OsSysTimer_ISR(void);
#define OsSysTimer_Stop(CoreID)      (OS_PL_STM_SR(CoreID, 0) &= OS_PL_STM_SR_SRE_CLEAR_MASK)
#define OsSysTimer_GetTimer(CoreID)  OS_PL_STM_TIM0(CoreID)

extern FUNC(Os_SysTickType, OS_CODE) OsSysTimer_GetElapsedTime
(
    CoreIdType CoreID,
    Os_SysTickType startTime
);


#if(OS_ON == OS_TP_TIMER_NEED)
extern FUNC(void, OS_CODE) OsTpTimer_Init
(
    CoreIdType CoreID
);

extern FUNC(Os_TpTickType, OS_CODE) OsTpTimer_Set
(
    CoreIdType CoreID,
    Os_TpTickType value
);

#define OsTpTimer_Stop(CoreID)    OS_PL_MTCR(OS_PL_TPS_TIMER(OS_TPTIMER_CHANNEL), 0)

extern FUNC(Os_TpTickType, OS_CODE) OsTpTimer_GetElapsedTime
(
    CoreIdType CoreID,
    Os_TpTickType startTime

);

#define OsTpTimer_Get(CoreID)  OS_PL_MFCR(OS_PL_TPS_TIMER(OS_TPTIMER_CHANNEL))


extern FUNC(void, OS_CODE) OsTpTimer_ISR(void);
#endif

#if(OS_ON == OS_TP_FCTIMER_NEED)
extern FUNC(void, OS_CODE) OsTpFcTimer_Init
(
    CoreIdType CoreID
);

#define OsTpFcTimer_Stop(CoreID)  OS_PL_MTCR(OS_PL_TPS_TIMER(OS_TPFCTIMER_CHANNEL), 0)



extern FUNC(Os_TpTickType, OS_CODE) OsTpFcTimer_GetElapsedTime
(
    CoreIdType CoreID,
    Os_TpTickType startTime

);

#define OsTpFcTimer_Get(CoreID)  OS_PL_MFCR(OS_PL_TPS_TIMER(OS_TPFCTIMER_CHANNEL))

#endif

#if(OS_ON == OS_CPULOAD_API)
#define OsCpuLoadTimer_Init(CoreID)  (void)(CoreID)

#define OsCpuLoadTimer_GetTimer(CoreID)  OsSysTimer_GetTimer(CoreID)

#define OsCpuLoadTimer_GetElapsedTime(CoreID, startTime) \
    OsSysTimer_GetElapsedTime(CoreID, startTime)

#define OsCpuLoadTimer_Stop(CoreID)  (void)(CoreID)

#endif


/*****************************************************************************
* Intc
******************************************************************************/
/*****************************************************************************
* Intc inline code and function declare
******************************************************************************/
#define OsIntc_EnableGlobalInterrupt(CoreID)  OS_PL_EnableInterrupts()
#define OsIntc_DisableGlobalInterrupt(CoreID)  OS_PL_DisableInterrupts()


extern FUNC(void, OS_CODE) OsIntc_Init
(
    CoreIdType CoreID
);

#if(OS_USED_CORE_NUMBER > 1)
extern FUNC(void, OS_CODE) OsIntc_CrossCoreIntTrigger
(
    CoreIdType CoreID
);

extern FUNC(void, OS_CODE) OsIntc_CrossCoreISR
(
    void
);
#endif

/* BEGIN_FUNCTION_HDR
***********************************************************************************************
* Function Name: OsIntc_GetIntPriority
*
* Description:   Get interrupt priority of current core
*
* Inputs:        CoreID
*
* Outputs:       OS_INLINE_FUNC(Os_PrioType) OsIntc_GetIntPriority

*
* Limitations:   input CoreID is logical id, If needed , CoreID need to change to phy core id
***********************************************************************************************
END_FUNCTION_HDR*/
#define OsIntc_GetIntPriority(CoreID)  ((Os_PrioType)(OS_PL_MFCR(OS_PL_CPU_ICR_REG) & OS_PL_ICR_CCPN_MASK))

extern FUNC(void, OS_CODE)  OsIntc_ReplaceIntPriority
(
    CoreIdType CoreID,
    Os_PrioType priority
);

extern FUNC(Os_boolean, OS_CODE) OsIntc_GetGlobalIntState
(
    CoreIdType CoreID
);

extern FUNC(void, OS_CODE) OsIntc_SetGlobalIntState
(
    CoreIdType CoreID,
    Os_boolean gIntState
);

extern FUNC(void, OS_CODE)  OsIntc_DisableAllInterrupts
(
    CoreIdType CoreID
);
extern FUNC(void, OS_CODE)  OsIntc_ResumeAllInterrupts
(
    CoreIdType CoreID
);
extern FUNC(void, OS_CODE)  OsIntc_SuspendOsInterrupts
(
    CoreIdType CoreID
);
extern FUNC(void, OS_CODE)  OsIntc_ResumeOsInterrupts
(
    CoreIdType CoreID
);

extern FUNC(void, OS_CODE) OsIntc_OutISR2(void);
extern FUNC(void, OS_CODE) OsIntc_InISR1
(
    CoreIdType CoreID,
    ISRType ISRID
);
extern FUNC(void, OS_CODE) OsIntc_OutISR1(void);

#if((OS_TIMING_PROTECTION_SUPPORT == OS_ON)||(OS_MEM_PROTECTION_SUPPORT == OS_ON)||(OS_APPLICATION_NUMBER > 0))
extern FUNC(void, OS_CODE) OsIntc_EnableISR
(
    CoreIdType CoreID, 
    ISRType ISRID
);
extern FUNC(void, OS_CODE) OsIntc_DisableISR
(
    CoreIdType CoreID, 
    ISRType ISRID
);
extern FUNC(void, OS_CODE) OsIntc_ClearPendingISR
(
    CoreIdType CoreID, 
    ISRType ISRID
);
#else
#define OsIntc_EnableISR(CoreID,ISRID)
#define OsIntc_DisableISR(CoreID,ISRID)
#define OsIntc_ClearPendingISR(CoreID, ISRID)
#endif
extern FUNC(Os_boolean, OS_CODE) OsIntc_CheckISREnabled
(
    CoreIdType CoreID, 
    ISRType ISRID
);
extern FUNC(void, OS_CODE) OsIntc_KillISRSchedule
(
    CoreIdType CoreID,
    ISRType ISRID,
    Os_boolean needSchedule
);


/*****************************************************************************
* MPU
******************************************************************************/
#if(OS_ON == OS_MEM_PROTECTION_SUPPORT)
extern FUNC(void, OS_CODE) OsMpu_Init(CoreIdType CoreID);
extern FUNC(void, OS_CODE) OsMpu_SetTask(CoreIdType CoreID, TaskType TaskID);
extern FUNC(void, OS_CODE) OsMpu_SetISR(CoreIdType CoreID, ISRType ISRID);
extern FUNC(void, OS_CODE) OsMpu_Enable(CoreIdType CoreID);
extern FUNC(void, OS_CODE) OsMpu_Disable(CoreIdType CoreID);
extern FUNC(void, OS_CODE) OsMpu_ProtectionISR(void);

#else
#define OsMpu_Init(CoreID)
#define OsMpu_SetTask(CoreID, TaskID)
#define OsMpu_SetISR(CoreID, ISRID)
#define OsMpu_Enable(CoreID)
#define OsMpu_Disable(CoreID)
#define OsMpu_SetApplication(CoreID, appId)
#define OsMpu_RestoreTaskISR(CoreID)

#endif

/*****************************************************************************
* Spinlock
******************************************************************************/
extern FUNC(Os_boolean, OS_CODE) OsCpu_TryToGetSpinlock (Os_uint32 *address, CoreIdType value);
extern FUNC(void, OS_CODE) OsCpu_GetSpinlock(Os_uint32 *address, CoreIdType value);








#define OS_STOP_SEC_CODE
#include "Os_MemMap.h"


#endif /* OS_PL_INTERNALCODE_H */
