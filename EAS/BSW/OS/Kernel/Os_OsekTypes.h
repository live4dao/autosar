/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
* File Name:       Os_OsekTypes.h
********************************************************************************
* Project/Product: AUTOSAR OS PROJECT
* Title:           Os_OsekTypes.h
* Author:          Hirain
********************************************************************************
* Description:     Definition of OS OSEK standard types
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

#ifndef OS_OSEKTYPES_H
#define OS_OSEKTYPES_H

/*****************************************************************************
* files include
******************************************************************************/
#include "Os_BasicTypes.h"
#include "Os_Cfg.h"
/*****************************************************************************
* General QAC Suppression
******************************************************************************/
/*PRQA S 3608 EOF*/
/*
Current compilers support "#elif".
*/

/*PRQA S 3453,3429 EOF*/
/*
OSEK standard Types.
*/

/*****************************************************************************
* Task related Types
******************************************************************************/
/* Define the data type of task ID, according to the amount of tasks. */
#if(OS_TASK_NUMBER < 256)
#define OS_TASK_TYPE_MASK    ((TaskType)0x00) /* Macro used for type conversion in assembler */
#define OS_INVALID_TASK_ID   ((TaskType)0xFF) /* Indication used when there is no task ready in the system */
typedef Os_uint8 TaskType;
#elif((OS_TASK_NUMBER >= 256) && (OS_TASK_NUMBER < 65536))
#define OS_TASK_TYPE_MASK    ((TaskType)0xFF)
#define OS_INVALID_TASK_ID   ((TaskType)0xFFFF)
typedef Os_uint16 TaskType;
#else
#define OS_TASK_TYPE_MASK    ((TaskType)0xFF)
#define OS_INVALID_TASK_ID   ((TaskType)0xFFFFFFFF)
typedef Os_uint32 TaskType;
#endif /*(OS_TASK_NUMBER < 256)*/

#ifndef INVALID_TASK
#define INVALID_TASK OS_INVALID_TASK_ID
#endif /*INVALID_TASK*/

typedef TaskType *TaskRefType;

typedef enum
{
    OS_TASK_SUSPENDED = 0,
    OS_TASK_NEW = 1,
    OS_TASK_READY = 2,
    OS_TASK_RUNNING = 3,
    OS_TASK_WAITING = 4,
    OS_TASK_WAITING_TO_READY = 5
} TaskStateType;

typedef TaskStateType *TaskStateRefType;

/*****************************************************************************
* Alarm related Types
******************************************************************************/
typedef Os_uint32 TickType;

typedef struct
{
    TickType maxallowedvalue; /* The maximum allowed value of alarms */
    TickType ticksperbase; /* Tick value per base */
    TickType mincycle; /* Minimum of the alarm period */
} AlarmBaseType;

#if(OS_ALARM_NUMBER <= 0xFF)
typedef Os_uint8 AlarmType;
#elif(OS_ALARM_NUMBER <= 0xFFFF)
typedef Os_uint16 AlarmType;
#else
typedef Os_uint32 AlarmType;
#endif /*(OS_ALARM_NUMBER <= 0xFF)*/

/* Declare the pointers to the alarm structure */
typedef TickType *TickRefType;
typedef AlarmBaseType *AlarmBaseRefType;  /* Pointer to the alarm structure type. */

/*****************************************************************************
* Event Types
******************************************************************************/
#if(OS_EXTENDED_TASK_NUMBER > 0)
typedef Os_uint32 EventMaskType; /*Mask off code for Events*/
typedef EventMaskType *EventMaskRefType;
#define OS_INVALID_EVENT_MASK    0
#endif /*(OS_EXTENDED_TASK_NUMBER > 0)*/

/*****************************************************************************
* Service Id Types
******************************************************************************/
typedef Os_uint16 OSServiceIdType;

/*****************************************************************************
* Resource Types
******************************************************************************/
#if(OS_RESOURCE_NUMBER <= 256)
typedef Os_uint8 ResourceType;
#define OS_INVALID_RES_ID   ((ResourceType)0xFF)
#elif((OS_RESOURCE_NUMBER > 256) && (OS_RESOURCE_NUMBER <= 65536))
typedef Os_uint16 ResourceType;
#define OS_INVALID_RES_ID   ((ResourceType)0xFFFF)
#else
typedef Os_uint32 ResourceType;
#define OS_INVALID_RES_ID   ((ResourceType)0xFFFFFFFF)
#endif /*(OS_RESOURCE_NUMBER <= 256)*/

/*****************************************************************************
* Status Types
******************************************************************************/
#ifndef STATUSTYPEDEFINED
#define STATUSTYPEDEFINED
#define E_OK 0x00U
typedef Os_uint8 StatusType;
#endif /*STATUSTYPEDEFINED*/

/*****************************************************************************
* OSEK standard Types
******************************************************************************/
/* Scalability classes definition */
#define OS_SC1              1
#define OS_SC2              2
#define OS_SC3              3
#define OS_SC4              4

/* Conformance classes definition */
#define OS_BCC1             1
#define OS_BCC2             2
#define OS_ECC1             4
#define OS_ECC2             8

/* OS check level definition */
#define OS_STANDARD         0x33
#define OS_EXTENDED         0xCC    /* More return values are available for debugging when the system is on OS_EXTENDED level. */

#define OS_PIT_MODE         0x00    /* Periodical interrupt timer mode */
#define OS_HRT_MODE         0x01    /* High resolution timer mode */

/*Task ISR name */
#define TASK(TaskName)  void TaskName##Func(void)
#define ISR(IsrName) void IsrName(void)
#define ALARMCALLBACK(CallBackName) void CallBackName(void)     /*the define for alarm-callback*/

#define OSDEFAULTAPPMODE    OS_SYSTEM_APPMODE                    

#endif /*OS_OSEKTYPES_H*/

