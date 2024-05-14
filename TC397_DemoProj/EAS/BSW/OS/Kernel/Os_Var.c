/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
* File Name:       Os_Var.c
********************************************************************************
* Project/Product: AUTOSAR OS PROJECT
* Title:           Os_Var.c
* Author:          Hirain
********************************************************************************
* Description:     Define the variables used in different OS modules
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

/*PRQA S 3211 EOF*/
/*
There are global variables which were defined here to be used in other files.
*/

#define OS_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap.h"

VAR(TaskType, OS_VAR)  Os_CurrentTaskId[OS_USED_CORE_NUMBER];/* used to store the task id of core, not global id*/
VAR(Os_uint16, OS_VAR) Os_CurrentContext[OS_USED_CORE_NUMBER];
VAR(Os_TaskCBType, OS_VAR) Os_TaskCBTable[OS_TASK_NUMBER];
VAR(Os_ISRCBType, OS_VAR) Os_ISRCBTable[OS_ISR_NUMBER];

#if(OS_ALARM_NUMBER > 0)
VAR(Os_AlarmCBType, OS_VAR) Os_AlarmCBTable[OS_ALARM_NUMBER];
#endif /*(OS_ALARM_NUMBER > 0)*/

VAR(TickType, OS_VAR) Os_CounterTick[OS_COUNTER_NUMBER];

#if(OS_RESOURCE_NUMBER > 0)
VAR(Os_ResCBType, OS_VAR) Os_ResCBTable[OS_RESOURCE_NUMBER];

#if(OS_SHARE_RESOURCE_NUMBER > 0)
VAR(Os_uint8, OS_VAR) Os_IntResLockDepth[OS_USED_CORE_NUMBER];
#endif /*(OS_SHARE_RESOURCE_NUMBER > 0)*/

#endif /*(OS_RESOURCE_NUMBER > 0)*/

#if(OS_APPLICATION_NUMBER > 0)
VAR(Os_AppCBType, OS_VAR) Os_AppCBTable[OS_APPLICATION_NUMBER];
VAR(ApplicationType, OS_VAR) Os_CurrentApplicationId[OS_USED_CORE_NUMBER];
#endif /*(OS_APPLICATION_NUMBER > 0)*/

VAR(Os_IntAPIUsedType, OS_VAR) Os_IntAPIUsedFlag[OS_USED_CORE_NUMBER];
/*Nest counter of API*/
VAR(Os_uint8, OS_VAR) OsISR_IntAPINesting[OS_USED_CORE_NUMBER];

VAR(ISRType, OS_VAR) Os_IntNestDepth[OS_USED_CORE_NUMBER];
VAR(ISRType, OS_VAR) Os_C1IntNestDepth[OS_USED_CORE_NUMBER];

#if(OS_SCHTBL_NUMBER > 0)
VAR(Os_SchTblCBType, OS_VAR) Os_SchTblCBTable[OS_SCHTBL_NUMBER];
#endif /*(OS_SCHTBL_NUMBER > 0)*/

#if(OS_SPINKLOCK_LOCKSCH_SUPPORT == OS_ON)
VAR(Os_uint8, OS_VAR) Os_SpinlockDepth[OS_USED_CORE_NUMBER];
#endif /*(OS_SPINKLOCK_LOCKSCH_SUPPORT == OS_ON)*/

#if((OS_STATUS_LEVEL == OS_EXTENDED) || (OS_ERRORHOOK_SUPPORT == OS_ON))
VAR(Os_boolean, OS_VAR) Os_ErrNestFlag[OS_USED_CORE_NUMBER];
#endif /*((OS_STATUS_LEVEL == OS_EXTENDED) || (OS_ERRORHOOK_SUPPORT == OS_ON))*/
VAR(Os_ErrRecordType, OS_VAR) Os_ErrRecord[OS_USED_CORE_NUMBER];

#define OS_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap.h"

#if (OS_USED_CORE_NUMBER == 1)
#define OS_START_SEC_VAR_NOINIT_UNSPECIFIED
#else
#define OS_START_SEC_VAR_NOINIT_MULTICORE
#endif /*(OS_USED_CORE_NUMBER == 1)*/
#include "Os_MemMap.h"

VAR(Os_CoreStateType, OS_VAR) Os_CoreState[OS_USED_CORE_NUMBER];
#if(OS_USED_CORE_NUMBER > 1)
VAR(Os_CoreStateType, OS_VAR) Os_CoreSyn[OS_USED_CORE_NUMBER];
VAR(SpinlockType, OS_VAR) OsMultiCore_OpLock[OS_USED_CORE_NUMBER];
#endif /*(OS_USED_CORE_NUMBER > 1)*/
#if(OS_APPMODE_NUMBER > 1)
VAR(Os_AppModeMaskType, OS_VAR) Os_ActiveAppMode[OS_USED_CORE_NUMBER];
#endif /*(OS_APPMODE_NUMBER > 1)*/
#if(OS_SPINLOCK_NUMBER > 0)
VAR(SpinlockType, OS_VAR) Os_SpinlockState[OS_SPINLOCK_NUMBER];
#endif/*#if(OS_SPINLOCK_NUMBER > 0)*/

#if (OS_USED_CORE_NUMBER == 1)
#define OS_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#else
#define OS_STOP_SEC_VAR_NOINIT_MULTICORE
#endif /*(OS_USED_CORE_NUMBER == 1)*/
#include "Os_MemMap.h"
