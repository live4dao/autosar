/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
* File Name:       Os.h
********************************************************************************
* Project/Product: AUTOSAR OS PROJECT
* Title:           Os.h
* Author:          Hirain
********************************************************************************
* Description:     Declare OS API
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
#ifndef OS_H
#define OS_H
#include "Os_Internal.h"

/*****************************************************************************
* APIs that dont affected by memory protection
******************************************************************************/
/* these API can work even when OS is not running, so they dont affect by mp*/
#define StartOS        Os_StartOS
#if(OS_USED_CORE_NUMBER > 1)
#define StartCore Os_StartCore
#define StartNonAutosarCore Os_StartNonAutosarCore
#endif/*#if(OS_USED_CORE_NUMBER > 1)*/

#define GetCoreID      Os_GetCoreID
#define GetActiveApplicationMode      Os_GetActiveApplicationMode

/* APIs only read data from OS*/
#if(OS_MEM_PROTECTION_SUPPORT == OS_OFF)

/* trust function will switch MPU by its self*/
#if(OS_TRUSTED_FUNCTION_NUMBER > 0)
#define CallTrustedFunction Os_CallTrustedFunction
#endif

#if(OS_USED_CORE_NUMBER > 1)
#define ControlIdle    Os_ControlIdle
#endif/*#if(OS_USED_CORE_NUMBER > 1)*/
/* kernel*/
#define ShutdownOS  Os_ShutdownOS
#if(OS_STACK_USEAGE_API == OS_ON)
#define GetSysStackUsage  Os_GetSysStackUsage
#define GetTaskStackUsage  Os_GetTaskStackUsage
#define GetISRStackUsage  Os_GetISRStackUsage
#endif
#if(OS_CPULOAD_API == OS_ON)
#define GetCpuLoadValue  Os_GetCpuLoadValue
#endif

/*Task*/
#define ActivateTask  Os_ActivateTask
#define TerminateTask  Os_TerminateTask
#define ChainTask  Os_ChainTask
#define Schedule Os_Schedule
#define GetTaskID Os_GetTaskID
#define GetTaskState Os_GetTaskState


/*Event*/
#if((OS_CC == OS_ECC1) || (OS_CC == OS_ECC2))
#define SetEvent Os_SetEvent
#define ClearEvent Os_ClearEvent
#define GetEvent Os_GetEvent
#define WaitEvent Os_WaitEvent
#endif

/*Alarm*/
#define GetAlarmBase Os_GetAlarmBase
#define GetAlarm Os_GetAlarm
#define SetRelAlarm Os_SetRelAlarm
#define SetAbsAlarm Os_SetAbsAlarm
#define CancelAlarm Os_CancelAlarm

/*Counter*/
#if(OS_USER_COUNTER_NUMBER > 0)
#define IncrementCounter Os_IncrementCounter
#endif
#define GetCounterValue Os_GetCounterValue
#define GetElapsedValue Os_GetElapsedValue

/*Resource*/
#if(OS_RESOURCE_NUMBER > 0)
#define GetResource Os_GetResource
#define ReleaseResource Os_ReleaseResource
#endif

/*Schtbl*/
#if(OS_SCHTBL_NUMBER > 0)
#define StartScheduleTableRel Os_StartScheduleTableRel
#define StartScheduleTableAbs Os_StartScheduleTableAbs
#define NextScheduleTable Os_NextScheduleTable
#define StopScheduleTable Os_StopScheduleTable
#define GetScheduleTableStatus Os_GetScheduleTableStatus
#endif

/*ISR*/
#define DisableAllInterrupts    Os_DisableAllInterrupts
#define EnableAllInterrupts Os_EnableAllInterrupts
#define SuspendAllInterrupts    Os_SuspendAllInterrupts
#define ResumeAllInterrupts Os_ResumeAllInterrupts
#define SuspendOSInterrupts Os_SuspendOSInterrupts
#define ResumeOSInterrupts  Os_ResumeOSInterrupts
#define GetISRID    Os_GetISRID
#define EnableInterruptSource    Os_EnableInterruptSource
#define DisableInterruptSource   Os_DisableInterruptSource
#define ClearPendingInterrupt    Os_ClearPendingInterrupt


/*SpinLock*/
#if (OS_SPINLOCK_NUMBER > 0)
#define GetSpinlock Os_GetSpinlock
#define ReleaseSpinlock Os_ReleaseSpinlock
#define TryToGetSpinlock Os_TryToGetSpinlock
#endif

/*Application*/
#if(OS_APPLICATION_NUMBER > 0)
#define GetApplicationID Os_GetApplicationID
#define GetCurrentApplicationID Os_GetCurrentApplicationID
#if(OS_ON == OS_OSAPP_RESTARTTASK_SUPPORT)
#define AllowAccess Os_AllowAccess
#endif
#define GetApplicationState Os_GetApplicationState
#define TerminateApplication Os_TerminateApplication
#define CheckObjectAccess Os_CheckObjectAccess
#define CheckObjectOwnership Os_CheckObjectOwnership
#endif



/*Multicore*/
#if(OS_USED_CORE_NUMBER > 1)
#define ShutdownAllCores Os_ShutdownAllCores
#endif/*(OS_USED_CORE_NUMBER > 1)*/
#define GetNumberOfActivatedCores Os_GetNumberOfActivatedCores

#else

/* kernel*/
#if(OS_USED_CORE_NUMBER > 1)
#define ControlIdle			Os_Pl_ControlIdle
#endif
#define ShutdownOS			Os_Pl_ShutdownOS
#if(OS_STACK_USEAGE_API == OS_ON)
#define GetTaskStackUsage	Os_GetTaskStackUsage
#define GetISRStackUsage	Os_GetISRStackUsage
#endif
#if(OS_CPULOAD_API == OS_ON)
#define GetCpuLoadValue  Os_GetCpuLoadValue
#endif

/*Task*/
#define ActivateTask  Os_Pl_ActivateTask

#define TerminateTask  Os_Pl_TerminateTask
#define ChainTask  Os_Pl_ChainTask
#define Schedule Os_Pl_Schedule
#define GetTaskID Os_Pl_GetTaskID
#define GetTaskState Os_Pl_GetTaskState


/*Event*/
#if((OS_CC == OS_ECC1) || (OS_CC == OS_ECC2))
#define SetEvent Os_Pl_SetEvent
#define ClearEvent Os_Pl_ClearEvent
#define GetEvent Os_Pl_GetEvent
#define WaitEvent Os_Pl_WaitEvent
#endif

/*Alarm*/
#define GetAlarmBase Os_Pl_GetAlarmBase
#define GetAlarm Os_Pl_GetAlarm
#define SetRelAlarm Os_Pl_SetRelAlarm
#define SetAbsAlarm Os_Pl_SetAbsAlarm
#define CancelAlarm Os_Pl_CancelAlarm

/*Counter*/
#if(OS_USER_COUNTER_NUMBER > 0)
#define IncrementCounter Os_Pl_IncrementCounter
#endif
#define GetCounterValue Os_Pl_GetCounterValue
#define GetElapsedValue Os_Pl_GetElapsedValue

/*Resource*/
#if(OS_RESOURCE_NUMBER > 0)
#define GetResource Os_Pl_GetResource
#define ReleaseResource Os_Pl_ReleaseResource
#endif

/*Schtbl*/
#if(OS_SCHTBL_NUMBER > 0)
#define StartScheduleTableRel Os_Pl_StartScheduleTableRel
#define StartScheduleTableAbs Os_Pl_StartScheduleTableAbs
#define NextScheduleTable Os_Pl_NextScheduleTable
#define StopScheduleTable Os_Pl_StopScheduleTable
#define GetScheduleTableStatus Os_Pl_GetScheduleTableStatus
#endif

/*ISR*/
#define DisableAllInterrupts    Os_Pl_DisableAllInterrupts
#define EnableAllInterrupts Os_Pl_EnableAllInterrupts
#define SuspendAllInterrupts    Os_Pl_SuspendAllInterrupts
#define ResumeAllInterrupts Os_Pl_ResumeAllInterrupts
#define SuspendOSInterrupts Os_Pl_SuspendOSInterrupts
#define ResumeOSInterrupts  Os_Pl_ResumeOSInterrupts
#define GetISRID    Os_Pl_GetISRID
#define EnableInterruptSource    Os_Pl_EnableInterruptSource
#define DisableInterruptSource   Os_Pl_DisableInterruptSource
#define ClearPendingInterrupt    Os_Pl_ClearPendingInterrupt

/*SpinLock*/
#if(OS_SPINLOCK_NUMBER > 0)
#define GetSpinlock Os_Pl_GetSpinlock
#define ReleaseSpinlock Os_Pl_ReleaseSpinlock
#define TryToGetSpinlock Os_Pl_TryToGetSpinlock
#endif

/*Application*/
#if(OS_APPLICATION_NUMBER > 0)
#define GetApplicationID Os_Pl_GetApplicationID
#define GetCurrentApplicationID Os_Pl_GetCurrentApplicationID
#if(OS_ON == OS_OSAPP_RESTARTTASK_SUPPORT)
#define AllowAccess Os_Pl_AllowAccess
#endif
#define GetApplicationState Os_Pl_GetApplicationState
#define TerminateApplication Os_Pl_TerminateApplication
#define CheckObjectAccess Os_Pl_CheckObjectAccess
#define CheckObjectOwnership Os_Pl_CheckObjectOwnership
#endif

/* trust function will switch MPU by its self*/
#if(OS_TRUSTED_FUNCTION_NUMBER > 0)
#define CallTrustedFunction Os_Pl_CallTrustedFunction
#endif

/*Multicore*/
#if(OS_USED_CORE_NUMBER > 1)
#define ShutdownAllCores Os_Pl_ShutdownAllCores
#endif/*(OS_USED_CORE_NUMBER > 1)*/
#define GetNumberOfActivatedCores Os_Pl_GetNumberOfActivatedCores

#endif/*#if(OS_MEM_PROTECTION_SUPPORT == OS_OFF)*/


#endif/*OS_H*/
