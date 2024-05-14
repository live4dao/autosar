/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
* File Name:       Os_Var.h
********************************************************************************
* Project/Product: AUTOSAR OS PROJECT
* Title:           Os_Var.h
* Author:          Hirain
********************************************************************************
* Description:     Declare the variables used in different OS modules
*                  this file Can not seen by user
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
#ifndef OS_VAR_H
#define OS_VAR_H
#include "Os_Types.h"

#define OS_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap.h"

extern VAR(TaskType, OS_VAR)  Os_CurrentTaskId[OS_USED_CORE_NUMBER];/* used to store the task id of core, not global id*/
extern VAR(Os_uint16, OS_VAR) Os_CurrentContext[OS_USED_CORE_NUMBER];
extern VAR(Os_TaskCBType, OS_VAR) Os_TaskCBTable[OS_TASK_NUMBER];
extern VAR(Os_ISRCBType, OS_VAR) Os_ISRCBTable[OS_ISR_NUMBER];

#if(OS_ALARM_NUMBER > 0)
extern VAR(Os_AlarmCBType, OS_VAR) Os_AlarmCBTable[OS_ALARM_NUMBER];
#endif /*(OS_ALARM_NUMBER > 0)*/

extern VAR(TickType, OS_VAR) Os_CounterTick[OS_COUNTER_NUMBER];

#if(OS_RESOURCE_NUMBER > 0)
extern VAR(Os_ResCBType, OS_VAR) Os_ResCBTable[OS_RESOURCE_NUMBER];

#if(OS_SHARE_RESOURCE_NUMBER > 0)
extern VAR(Os_uint8, OS_VAR) Os_IntResLockDepth[OS_USED_CORE_NUMBER];
#endif /*(OS_SHARE_RESOURCE_NUMBER > 0)*/

#endif /*(OS_RESOURCE_NUMBER > 0)*/

#if(OS_APPLICATION_NUMBER > 0)
extern VAR(Os_AppCBType, OS_VAR) Os_AppCBTable[OS_APPLICATION_NUMBER];
extern VAR(ApplicationType, OS_VAR) Os_CurrentApplicationId[OS_USED_CORE_NUMBER];
#endif /*(OS_APPLICATION_NUMBER > 0)*/

extern VAR(Os_IntAPIUsedType, OS_VAR) Os_IntAPIUsedFlag[OS_USED_CORE_NUMBER];
/*Nest counter of API*/
extern VAR(Os_uint8, OS_VAR) OsISR_IntAPINesting[OS_USED_CORE_NUMBER];

extern VAR(ISRType, OS_VAR) Os_IntNestDepth[OS_USED_CORE_NUMBER];
extern VAR(ISRType, OS_VAR) Os_C1IntNestDepth[OS_USED_CORE_NUMBER];

#if(OS_SCHTBL_NUMBER > 0)
extern VAR(Os_SchTblCBType, OS_VAR) Os_SchTblCBTable[OS_SCHTBL_NUMBER];
#endif /*(OS_SCHTBL_NUMBER > 0)*/

#if(OS_SPINKLOCK_LOCKSCH_SUPPORT == OS_ON)
extern VAR(Os_uint8, OS_VAR) Os_SpinlockDepth[OS_USED_CORE_NUMBER];
#endif /*(OS_SPINKLOCK_LOCKSCH_SUPPORT == OS_ON)*/

#if((OS_STATUS_LEVEL == OS_EXTENDED) || (OS_ERRORHOOK_SUPPORT == OS_ON))
extern VAR(Os_boolean, OS_VAR) Os_ErrNestFlag[OS_USED_CORE_NUMBER];
#endif /*((OS_STATUS_LEVEL == OS_EXTENDED) || (OS_ERRORHOOK_SUPPORT == OS_ON))*/
extern VAR(Os_ErrRecordType, OS_VAR) Os_ErrRecord[OS_USED_CORE_NUMBER];

#define OS_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap.h"

#if (OS_USED_CORE_NUMBER == 1)
#define OS_START_SEC_VAR_NOINIT_UNSPECIFIED
#else
#define OS_START_SEC_VAR_NOINIT_MULTICORE
#endif /*(OS_USED_CORE_NUMBER == 1)*/
#include "Os_MemMap.h"

extern VAR(Os_CoreStateType, OS_VAR) Os_CoreState[OS_USED_CORE_NUMBER];
#if(OS_USED_CORE_NUMBER > 1)
extern VAR(Os_CoreStateType, OS_VAR) Os_CoreSyn[OS_USED_CORE_NUMBER];
extern VAR(SpinlockType, OS_VAR) OsMultiCore_OpLock[OS_USED_CORE_NUMBER];
#endif /*(OS_USED_CORE_NUMBER > 1)*/
#if(OS_APPMODE_NUMBER > 1)
extern VAR(Os_AppModeMaskType, OS_VAR) Os_ActiveAppMode[OS_USED_CORE_NUMBER];
#endif /*(OS_APPMODE_NUMBER > 1)*/
#if(OS_SPINLOCK_NUMBER > 0)
extern VAR(SpinlockType, OS_VAR) Os_SpinlockState[OS_SPINLOCK_NUMBER];
#endif/*#if(OS_SPINLOCK_NUMBER > 0)*/

#if (OS_USED_CORE_NUMBER == 1)
#define OS_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#else
#define OS_STOP_SEC_VAR_NOINIT_MULTICORE
#endif /*(OS_USED_CORE_NUMBER == 1)*/
#include "Os_MemMap.h"

#endif /*OS_VAR_H*/
