/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
* File Name:       Os_AsrTypes.h
********************************************************************************
* Project/Product: AUTOSAR EAS
* Title:           Os_AsrTypes.h
* Author:          Hirain
********************************************************************************
* Description:     Definition of OS AUTOSAR standard types
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

#ifndef OS_ASRTYPES_H
#define OS_ASRTYPES_H

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


/*****************************************************************************
* OsApplication types define
******************************************************************************/
/* Define the data type of Application ID, according to the amount of Applications. */
/*SWS_Os_00772*/
typedef Os_uint8 ApplicationType;
#define OS_INVALID_OSAPPLICATION   ((ApplicationType)0xFF)

/*SWS_Os_00773*/
typedef enum
{
    APPLICATION_ACCESSIBLE = 0,
    APPLICATION_RESTARTING = 1,
    APPLICATION_TERMINATED = 2
} ApplicationStateType;

/*SWS_Os_00774*/
typedef ApplicationStateType *ApplicationStateRefType;


typedef void* TrustedFunctionParameterRefType;

#if(OS_TRUSTED_FUNCTION_NUMBER < 256)
typedef Os_uint8 TrustedFunctionIndexType;
#define OS_INVALID_TRUSTEDFUN ((TrustedFunctionIndexType)0xFF)
#elif((OS_TRUSTED_FUNCTION_NUMBER >= 256) && (OS_TRUSTED_FUNCTION_NUMBER < 65535))
typedef Os_uint16 TrustedFunctionIndexType;
#define OS_INVALID_TRUSTEDFUN ((TrustedFunctionIndexType)0xFFFF)
#else
typedef Os_uint32 TrustedFunctionIndexType;
#define OS_INVALID_TRUSTEDFUN ((TrustedFunctionIndexType)0xFFFFFFFF)
#endif /*(OS_TRUSTED_FUNCTION_NUMBER < 256)*/



/*SWS_Os_00778*/
typedef enum
{
    ACCESS,
    NO_ACCESS
} ObjectAccessType;

/*SWS_Os_00779*/
typedef enum
{
    OBJECT_TASK,
    OBJECT_ISR,
    OBJECT_ALARM,
    OBJECT_RESOURCE,
    OBJECT_COUNTER,
    OBJECT_SCHEDULETABLE
} ObjectTypeType;

typedef Os_uint8 *MemoryStartAddressType;
/*SWS_Os_00781*/
typedef Os_uint32 MemorySizeType;



/*****************************************************************************
* ISR types
******************************************************************************/
/*SWS_Os_00782*/
#if(OS_ISR_NUMBER < 256)
typedef Os_uint8 ISRType;
#define OS_INVALID_ISR ((ISRType)0xFF)
#elif((OS_ISR_NUMBER >= 256) && (OS_ISR_NUMBER < 65535))
typedef Os_uint16 ISRType;
#define OS_INVALID_ISR ((ISRType)0xFFFF)
#else
typedef Os_uint32 ISRType;
#define OS_INVALID_ISR ((ISRType)0xFFFFFFFF)
#endif /*(OS_ISR_NUMBER < 256)*/

typedef ISRType *ISRRefType;

/*****************************************************************************
* Schedule Table types
******************************************************************************/
/*SWS_Os_00783*/
#if(OS_SCHTBL_NUMBER <= 255)
typedef Os_uint8 ScheduleTableType;
#define OS_INVALID_SCHTBL   ((ScheduleTableType)0xFF)
#elif((OS_SCHTBL_NUMBER>255)&&(OS_SCHTBL_NUMBER<=65535))
typedef Os_uint16 ScheduleTableType;
#define OS_INVALID_SCHTBL   ((ScheduleTableType)0xFFFF)
#else
typedef Os_uint32 ScheduleTableType;
#define OS_INVALID_SCHTBL   ((ScheduleTableType)0xFFFFFFFF)
#endif /*(OS_SCHTBL_NUMBER <= 255)*/

/*SWS_Os_00784*/
typedef enum
{
    SCHEDULETABLE_STOPPED = 0,
    SCHEDULETABLE_NEXT = 1,
    SCHEDULETABLE_WAITING = 2,
    SCHEDULETABLE_RUNNING = 3,
    SCHEDULETABLE_RUNNING_AND_SYNCHRONOUS = 4
} ScheduleTableStatusType;

/*SWS_Os_00785*/
typedef ScheduleTableStatusType *ScheduleTableStatusRefType;

/*****************************************************************************
* Counter types
******************************************************************************/
/*SWS_Os_00786*/
typedef Os_uint8  CounterType; /* support max 256 counter*/
#define OS_INVALID_COUNTER_ID   ((CounterType)0xFF)

/*****************************************************************************
* Other types
******************************************************************************/
/*SWS_Os_00787*/
typedef enum
{
    PRO_IGNORE = 0,
    PRO_TERMINATETASKISR = 1,
    PRO_TERMINATEAPPL = 2,
    PRO_TERMINATEAPPL_RESTART = 3,
    PRO_SHUTDOWN = 4
} ProtectionReturnType;

/*SWS_Os_00788*/
typedef enum
{
    RESTART = 0,
    NO_RESTART = 1
} RestartType;

/*SWS_Os_00789*/
typedef Os_uint32 PhysicalTimeType;

/*SWS_Os_00790*/
typedef Os_uint8 CoreIdType;
#define OS_INVALID_COREID   ((CoreIdType)0xFF)


/*SWS_Os_00791*/
#if(OS_SPINLOCK_NUMBER <= 255)
typedef Os_uint8 SpinlockIdType;
#define OS_INVALID_SPINLOCK   ((SpinlockIdType)0xFF)
#elif((OS_SPINLOCK_NUMBER > 255) && (OS_SPINLOCK_NUMBER <= 65535))
typedef Os_uint16 SpinlockIdType;
#define OS_INVALID_SPINLOCK   ((SpinlockIdType)0xFFFF)
#else
typedef Os_uint32 SpinlockIdType;
#define OS_INVALID_SPINLOCK   ((SpinlockIdType)0xFFFFFFFF)
#endif /*(OS_SPINLOCK_NUMBER <= 255)*/
#if(OS_USED_CORE_NUMBER > 1)
typedef Os_Pl_SpinlockType SpinlockType;
#endif /*(OS_USED_CORE_NUMBER > 1)*/
/*SWS_Os_00792*/
typedef enum
{
    TRYTOGETSPINLOCK_SUCCESS = 0,
    TRYTOGETSPINLOCK_NOSUCCESS = 1,
    TRYTOGETSPINLOCK_UNDEFINE = 2
} TryToGetSpinlockType;

/*SWS_Os_00793 not use now*/
typedef enum
{
    IDLE_NO_HALT = 0
} IdleModeType;

/* 422 7.9.7 */
typedef enum
{
    INDIVIDUAL_SHUTDOWN = 0,
    SYNCHRONIZED_SHUTDOWN = 1
} ShutdownConceptType;

#endif /*OS_ASRTYPES_H*/
