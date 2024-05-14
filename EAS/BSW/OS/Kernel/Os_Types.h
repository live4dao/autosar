/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
* File Name:       Os_Types.h
********************************************************************************
* Project/Product: AUTOSAR OS PROJECT
* Title:           Os_Types.h
* Author:          Hirain
********************************************************************************
* Description:     Definition of OS general types and structures for system usage.
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

#ifndef OS_TYPES_H
#define OS_TYPES_H

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

/*****************************************************************************
* files include
******************************************************************************/

#include "Os_Pl_Err.h"
#include "Os_Pl_Cfg.h"
#include "Os_Pl_Types.h"
#include "Os_AsrTypes.h"
#include "Os_OsekTypes.h"
#include "Os_Err.h"
#include "Os_Pl_HwDef.h"
#include "Os_Pl_Instruction.h"

/*****************************************************************************
* Macros
******************************************************************************/
/* context define */
#define OS_CONTEXT_TASK                        ((Os_uint16)0x0001)
#define OS_CONTEXT_C1ISR                       ((Os_uint16)0x0002)
#define OS_CONTEXT_C2ISR                       ((Os_uint16)0x0004)
#define OS_CONTEXT_ERRHOOK                     ((Os_uint16)0x0008)
#define OS_CONTEXT_PRETASKHOOK                 ((Os_uint16)0x0010)
#define OS_CONTEXT_POSTTASKHOOK                ((Os_uint16)0x0020)

#define OS_CONTEXT_STARTUPHOOK                 ((Os_uint16)0x0040)
#define OS_CONTEXT_SHUTDOWNHOOK                ((Os_uint16)0x0080)
#define OS_CONTEXT_PROTECTIONHOOK              ((Os_uint16)0x0100)
#define OS_CONTEXT_ALARMCALLBACK               ((Os_uint16)0x0200)
#define OS_CONTEXT_PREISRHOOK                  ((Os_uint16)0x0400)
#define OS_CONTEXT_POSTISRHOOK                 ((Os_uint16)0x0800)
#define OS_CONTEXT_KERNEL                      ((Os_uint16)0x0000) /* no API is allowed in kernal state */
#define OS_CONTEXT_All                         ((Os_uint16)0x03FF)

#define Os_ActivateTaskMask               ((Os_uint16)(OS_CONTEXT_TASK|OS_CONTEXT_C2ISR))
#define Os_TerminateTaskMask              (OS_CONTEXT_TASK)
#define Os_ChainTaskMask                  (OS_CONTEXT_TASK)
#define Os_ScheduleMask                   (OS_CONTEXT_TASK)
#define Os_GetTaskIDMask                  ((Os_uint16)(OS_CONTEXT_TASK|OS_CONTEXT_C2ISR|OS_CONTEXT_ERRHOOK|OS_CONTEXT_PRETASKHOOK|OS_CONTEXT_PREISRHOOK|OS_CONTEXT_POSTTASKHOOK|OS_CONTEXT_POSTISRHOOK|OS_CONTEXT_PROTECTIONHOOK))
#define Os_GetTaskStateMask               ((Os_uint16)(OS_CONTEXT_TASK|OS_CONTEXT_C2ISR|OS_CONTEXT_ERRHOOK|OS_CONTEXT_PRETASKHOOK|OS_CONTEXT_PREISRHOOK|OS_CONTEXT_POSTTASKHOOK|OS_CONTEXT_POSTISRHOOK))
/* no context for Os_DisableAllInterrupts.. as they can be called in all context */
/* SWS_Os_00808 */
#define Os_EnableInterruptSourceMask      ((Os_uint16)(OS_CONTEXT_TASK|OS_CONTEXT_C2ISR))
#define Os_DisableInterruptSourceMask     ((Os_uint16)(OS_CONTEXT_TASK|OS_CONTEXT_C2ISR))
#define Os_ClearPendingInterruptMask      ((Os_uint16)(OS_CONTEXT_TASK|OS_CONTEXT_C2ISR))

#define Os_GetResouceMask                 ((Os_uint16)(OS_CONTEXT_TASK|OS_CONTEXT_C2ISR))
#define Os_ReleaseResouceMask             ((Os_uint16)(OS_CONTEXT_TASK|OS_CONTEXT_C2ISR))
#define Os_SetEventMask                   ((Os_uint16)(OS_CONTEXT_TASK|OS_CONTEXT_C2ISR))
#define Os_ClearEventMask                 (OS_CONTEXT_TASK)
#define Os_GetEventMask                   ((Os_uint16)(OS_CONTEXT_TASK|OS_CONTEXT_C2ISR|OS_CONTEXT_ERRHOOK|OS_CONTEXT_PRETASKHOOK|OS_CONTEXT_PREISRHOOK|OS_CONTEXT_POSTTASKHOOK))
#define Os_WaitEventMask                  (OS_CONTEXT_TASK)
#define Os_GetAlarmBaseMask               ((Os_uint16)(OS_CONTEXT_TASK|OS_CONTEXT_C2ISR|OS_CONTEXT_ERRHOOK|OS_CONTEXT_PRETASKHOOK|OS_CONTEXT_PREISRHOOK|OS_CONTEXT_POSTTASKHOOK))
#define Os_GetAlarmMask                   ((Os_uint16)(OS_CONTEXT_TASK|OS_CONTEXT_C2ISR|OS_CONTEXT_ERRHOOK|OS_CONTEXT_PRETASKHOOK|OS_CONTEXT_PREISRHOOK|OS_CONTEXT_POSTTASKHOOK))
#define Os_SetRelAlarmMask                ((Os_uint16)(OS_CONTEXT_TASK|OS_CONTEXT_C2ISR))
#define Os_SetAbsAlarmMask                ((Os_uint16)(OS_CONTEXT_TASK|OS_CONTEXT_C2ISR))
#define Os_CancelAlarmMask                ((Os_uint16)(OS_CONTEXT_TASK|OS_CONTEXT_C2ISR))
#define Os_GetActiveApplicationModeMask   ((Os_uint16)(OS_CONTEXT_TASK|OS_CONTEXT_C2ISR|OS_CONTEXT_ERRHOOK|OS_CONTEXT_PRETASKHOOK|OS_CONTEXT_PREISRHOOK|OS_CONTEXT_POSTTASKHOOK|OS_CONTEXT_POSTISRHOOK|OS_CONTEXT_STARTUPHOOK|OS_CONTEXT_SHUTDOWNHOOK))
#define Os_StartOSMask                    (OS_CONTEXT_KERNEL)
#define Os_ShutdownOSMask                 ((Os_uint16)(OS_CONTEXT_TASK|OS_CONTEXT_C2ISR|OS_CONTEXT_ERRHOOK|OS_CONTEXT_STARTUPHOOK))
#define Os_GetSysStackUsageMask           ((Os_uint16)(OS_CONTEXT_TASK|OS_CONTEXT_C2ISR))
#define Os_GetTaskStackUsageMask          ((Os_uint16)(OS_CONTEXT_TASK|OS_CONTEXT_C2ISR))
#define Os_GetISRStackUsageMask           ((Os_uint16)(OS_CONTEXT_TASK|OS_CONTEXT_C2ISR))

#define Os_GetCpuLoadValueMask            (OS_CONTEXT_TASK) /* this service can only be called in task */
#define Os_GetApplicationIDMask           ((Os_uint16)(OS_CONTEXT_TASK|OS_CONTEXT_C2ISR|OS_CONTEXT_ERRHOOK|OS_CONTEXT_PRETASKHOOK|OS_CONTEXT_PREISRHOOK|OS_CONTEXT_POSTTASKHOOK|OS_CONTEXT_POSTISRHOOK|OS_CONTEXT_STARTUPHOOK|OS_CONTEXT_SHUTDOWNHOOK|OS_CONTEXT_PROTECTIONHOOK))
#define Os_GetISRIDMask                   ((Os_uint16)(OS_CONTEXT_TASK|OS_CONTEXT_C2ISR|OS_CONTEXT_ERRHOOK|OS_CONTEXT_PROTECTIONHOOK))
#define Os_CallTrustedFuntionMask         ((Os_uint16)(OS_CONTEXT_TASK|OS_CONTEXT_C2ISR))
#define Os_CheckISRMemoryAccessMask       ((Os_uint16)(OS_CONTEXT_TASK|OS_CONTEXT_C2ISR|OS_CONTEXT_ERRHOOK|OS_CONTEXT_PROTECTIONHOOK))
#define Os_CheckTaskMemoryAccessMask      ((Os_uint16)(OS_CONTEXT_TASK|OS_CONTEXT_C2ISR|OS_CONTEXT_ERRHOOK|OS_CONTEXT_PROTECTIONHOOK))
#define Os_CheckObjectAccessMask          ((Os_uint16)(OS_CONTEXT_TASK|OS_CONTEXT_C2ISR|OS_CONTEXT_ERRHOOK|OS_CONTEXT_PROTECTIONHOOK))
#define Os_CheckObjectOwnershipMask       ((Os_uint16)(OS_CONTEXT_TASK|OS_CONTEXT_C2ISR|OS_CONTEXT_ERRHOOK|OS_CONTEXT_PROTECTIONHOOK))
#define Os_StartScheduleTableRelMask      ((Os_uint16)(OS_CONTEXT_TASK|OS_CONTEXT_C2ISR))
#define Os_StartScheduleTableAbsMask      ((Os_uint16)(OS_CONTEXT_TASK|OS_CONTEXT_C2ISR))
#define Os_StopScheduleTableMask          ((Os_uint16)(OS_CONTEXT_TASK|OS_CONTEXT_C2ISR))
#define Os_NextScheduleTableMask          ((Os_uint16)(OS_CONTEXT_TASK|OS_CONTEXT_C2ISR))
#define Os_StartScheduleTableSynchronMask ((Os_uint16)(OS_CONTEXT_TASK|OS_CONTEXT_C2ISR))
#define Os_SyncScheduleTableMask          ((Os_uint16)(OS_CONTEXT_TASK|OS_CONTEXT_C2ISR))
#define Os_GetScheduleTableStatusMask     ((Os_uint16)(OS_CONTEXT_TASK|OS_CONTEXT_C2ISR))
#define Os_SetScheduleTableAsyncMask      ((Os_uint16)(OS_CONTEXT_TASK|OS_CONTEXT_C2ISR))
#define Os_IncrementCounterMask           ((Os_uint16)(OS_CONTEXT_TASK|OS_CONTEXT_C2ISR))
#define Os_GetCounterValueMask            ((Os_uint16)(OS_CONTEXT_TASK|OS_CONTEXT_C2ISR))
#define Os_GetElapsedValueMask            ((Os_uint16)(OS_CONTEXT_TASK|OS_CONTEXT_C2ISR))
#define Os_TerminateApplicationMask       ((Os_uint16)(OS_CONTEXT_TASK|OS_CONTEXT_C2ISR|OS_CONTEXT_ERRHOOK))
#define Os_AllowAccessMask                ((Os_uint16)(OS_CONTEXT_TASK))  /* this is different from AUTOSAR, as allowaccess can only be called in restart task*/
#define Os_GetApplicationStateMask        ((Os_uint16)(OS_CONTEXT_TASK|OS_CONTEXT_C2ISR|OS_CONTEXT_ERRHOOK|OS_CONTEXT_PRETASKHOOK|OS_CONTEXT_PREISRHOOK|OS_CONTEXT_POSTTASKHOOK|OS_CONTEXT_POSTISRHOOK|OS_CONTEXT_STARTUPHOOK|OS_CONTEXT_SHUTDOWNHOOK|OS_CONTEXT_PROTECTIONHOOK))
#define Os_ControlIdleMask                ((Os_uint16)(OS_CONTEXT_TASK|OS_CONTEXT_C2ISR))
#define Os_GetCurrentApplicationIDMask    ((Os_uint16)(OS_CONTEXT_TASK|OS_CONTEXT_C2ISR|OS_CONTEXT_ERRHOOK|OS_CONTEXT_PRETASKHOOK|OS_CONTEXT_PREISRHOOK|OS_CONTEXT_POSTTASKHOOK|OS_CONTEXT_POSTISRHOOK|OS_CONTEXT_STARTUPHOOK|OS_CONTEXT_SHUTDOWNHOOK|OS_CONTEXT_PROTECTIONHOOK))

#define Os_GetNumberOfActivatedCoresMask  ((Os_uint16)(OS_CONTEXT_TASK|OS_CONTEXT_C2ISR))
/*GetCoreId can be called be all context*/
#define Os_StartCoreMask                  (OS_CONTEXT_KERNEL)
#define Os_StartNonAutosarCoreMask        (OS_CONTEXT_KERNEL)
#define Os_GetSpinlockMask                ((Os_uint16)(OS_CONTEXT_TASK|OS_CONTEXT_C2ISR))
#define Os_ReleaseSpinlockMask            ((Os_uint16)(OS_CONTEXT_TASK|OS_CONTEXT_C2ISR))
#define Os_TryToGetSpinlockMask           ((Os_uint16)(OS_CONTEXT_TASK|OS_CONTEXT_C2ISR))
#define Os_ShutdownAllCoresMask           ((Os_uint16)(OS_CONTEXT_TASK|OS_CONTEXT_C2ISR|OS_CONTEXT_ERRHOOK|OS_CONTEXT_STARTUPHOOK))

#define Os_IocComMask                     ((Os_uint16)(OS_CONTEXT_TASK|OS_CONTEXT_C2ISR))

/*Task Queue index */
#define OS_TASK_QUEUE_INVALID_INDEX   ((Os_uint16)0xFFFF)

/*Stack check related*/
#define OS_STACKINIT_VALUE            (0xAAAAAAAA)

/*Alarm*/

/* Core Hw State */
#define OS_HW_CORE_START   ((Os_uint8)0xC0)  
#define OS_HW_CORE_STOP    ((Os_uint8)0x0C)  

/*ISR*/
#define OS_INTAPI_MAX_NEST_VALUE   ((Os_uint8)250)

/*RES*/
#define OS_INTRES_MAX_NEST_VALUE   ((Os_uint8)250)

/*TP*/
#define OS_TP_INVALID_NEST_LEVEL   ((Os_uint16)0xFFFF)

/*Spinlock*/
#define OS_SPINLOCK_INVALD_NEST_LEVEL   ((Os_uint8)250)

/* Application*/
#define OS_APP_ALL_MASK            (0xFFFFFFFF)

/*****************************************************************************
* Type define
******************************************************************************/
typedef enum
{
    OS_CORE_IDLE = 0, 
    OS_CORE_START = 1
} Os_CoreStateType;

typedef Os_uint16 Os_PrioType;
#define OS_INVALID_PRIO   ((Os_PrioType)0xFFFF)

/*Support 32 AppMode at most*/
typedef Os_uint32 Os_AppModeMaskType;

typedef struct 
{
    Os_boolean   OsResSemaphore;
    ResourceType LastResId;
    Os_PrioType  SavedTaskPri; /* when more than 1 res locked by task, this record the highest celling pri of all linked res before */
    Os_PrioType  SavedISRPri;  /* when more than 1 res locked by ISR, this record the highest celling pri of all linked res before */
} Os_ResCBType;

/* Variables definition of task control block */
typedef struct
{
#if((OS_CC == OS_BCC2) || (OS_CC == OS_ECC2))
    Os_uint8 OsTaskActivationTimes; /* Task activation times */
#endif /*((OS_CC == OS_BCC2) || (OS_CC == OS_ECC2))*/
#if((OS_CC == OS_ECC1) || (OS_CC == OS_ECC2))
    EventMaskType OsSetEventMask;
    EventMaskType OsWaitEventMask;
#endif /*((OS_CC == OS_ECC1) || (OS_CC == OS_ECC2))*/

#if(OS_SPINLOCK_NUMBER > 0)
    SpinlockIdType LastSpinLock;
#endif /*(OS_SPINLOCK_NUMBER > 0)*/

    Os_AddrType OsTaskCtxPtr; /* Task context is stored in this address */

#if(OS_RESOURCE_NUMBER > 0)
    ResourceType LastResId;
    Os_PrioType OsCellingTaskPri; /* Task celling  priority */
#endif /*(OS_RESOURCE_NUMBER > 0)*/

    TaskStateType OsTaskState; /* Task state */

#if(OS_APPLICATION_NUMBER > 0)
    Os_boolean isKilled;
#endif /*(OS_APPLICATION_NUMBER > 0)*/

#if(OS_CRC_SUPPORT == OS_ON)
    Os_uint8 crcResult;
#endif /*(OS_CRC_SUPPORT == OS_ON)*/

#if(OS_ON == OS_TP_TSK_ANYBUDGET_SUPPORT)
    Os_uint16 tpNestIndex;
    Os_TpTickType tpStartTs;
#endif /*(OS_ON == OS_TP_TSK_ANYBUDGET_SUPPORT)*/

#if(OS_TP_TSK_TIMEFRAME_SUPPORT == OS_ON)
    Os_boolean      timeFrameFirstFlag;
    Os_TpTickType   frameLastTs;      /* time of last successful transition to 'ready' state */
#endif /*(OS_TP_TSK_TIMEFRAME_SUPPORT == OS_ON)*/
} Os_TaskCBType; /*  TCB structure */

/* Variables definition of OsApp control block */
typedef struct
{
    ApplicationStateType appState; /* OS-Application state */
} Os_AppCBType;

typedef enum
{
    OS_ISR_SUSPENDED = 0,
    OS_ISR_READY = 1,
    OS_ISR_RUNNING = 2
} ISRStateType;

/* Variables definition of Isr control block */
typedef struct
{
#if(OS_ON == OS_ISR_NEST_SUPPORT)
    Os_AddrType OsIsrCtxPtr; /* ISR context is stored in this address */
#endif /*(OS_ON == OS_ISR_NEST_SUPPORT)*/
#if(OS_RESOURCE_NUMBER > 0)
    ResourceType LastResId;
#endif /*(OS_RESOURCE_NUMBER > 0)*/

#if(OS_SPINLOCK_NUMBER > 0)
    SpinlockIdType LastSpinLock;
#endif /*(OS_SPINLOCK_NUMBER > 0)*/

#if(OS_ON == OS_TP_ISR_ANYBUDGET_SUPPORT)
    Os_uint16 tpNestIndex;
    Os_TpTickType tpStartTs;
#endif /*(OS_ON == OS_TP_ISR_ANYBUDGET_SUPPORT)*/

#if(OS_TP_ISR_TIMEFRAME_SUPPORT == OS_ON)
    Os_boolean      timeFrameFirstFlag;
    Os_TpTickType   frameLastTs;      /* time of last successful transition to 'ready' state */
#endif /*(OS_TP_ISR_TIMEFRAME_SUPPORT == OS_ON)*/

#if(OS_APPLICATION_NUMBER > 0)
    Os_boolean isKilled;
#endif /*(OS_APPLICATION_NUMBER > 0)*/

#if(OS_CRC_SUPPORT == OS_ON)
    Os_uint8 crcResult;
#endif /*(OS_CRC_SUPPORT == OS_ON)*/

    ISRStateType isrState;

} Os_ISRCBType; /*  TCB structure */

typedef enum
{
    OS_NO_API_USED = 0,
    OS_DIS_ALL_API_USED = 1,
    OS_SUS_ALL_API_USED = 2,
    OS_SUS_OS_API_USED = 3
} Os_IntAPIUsedType;

#if((OS_CC == OS_BCC2) || (OS_CC == OS_ECC2))
/* Declare the structure type of priority ready queues */
typedef struct
{
    Os_uint16 Os_Q_front; /* add new task to front*/
    Os_uint16 Os_Q_rear; /* read out task from rear*/
} Os_TaskQueueCtlType;
#endif /*((OS_CC == OS_BCC2) || (OS_CC == OS_ECC2))*/

/*****************************************************************************
* Alarm types
******************************************************************************/
typedef struct
{
    Os_boolean isAlive;   /* alarm id*/
    TickType timeVal;    /* time value */
    TickType alarmcycle; /**/
#if(OS_APPLICATION_NUMBER > 0)
    Os_boolean isKilled;
#endif /*(OS_APPLICATION_NUMBER > 0)*/
} Os_AlarmCBType;

/*****************************************************************************
* Alarm types
******************************************************************************/
#if(OS_SCHTBL_NUMBER > 0)
typedef struct
{
    ScheduleTableStatusType OsSchTblState;
    ScheduleTableType toTable;
    ScheduleTableType fromTable;
    Os_uint8 OsSchTblNextEP;
    TickType timeVal; /* time value that next ep will expire*/
#if(OS_APPLICATION_NUMBER > 0)
    Os_boolean isKilled;
#endif /*(OS_APPLICATION_NUMBER > 0)*/

} Os_SchTblCBType;
#endif /*(OS_SCHTBL_NUMBER > 0)*/

/*****************************************************************************
* Application type
******************************************************************************/
/*Support 32 Applications at most*/
typedef Os_uint32 Os_ApplicationMaskType;

/* Only used in application module*/
typedef Os_uint32 Os_ObjectIdType;

/*****************************************************************************
* Spinlock type
******************************************************************************/

/*****************************************************************************
* IOC type
******************************************************************************/

/*****************************************************************************
* Error record type
******************************************************************************/
#define OS_MAX_ERR_RECORD_NUM  3
typedef struct
{
    CoreIdType errCore;
    OSServiceIdType serviceId;
    StatusType error;
    Os_uint16 errDescription;
    Os_uint32 errPar[OS_MAX_ERR_RECORD_NUM];/* used to record err parameters like TaskID eventid and so on*/
} Os_ErrRecordType;

/**********************************************************************************************************************************************
* Cfg structure type define
****************************************************************************************************************************************************************************/
typedef struct
{
    ResourceType ResId; 
#if((OS_TP_TSK_RESOURCE_LOCKTIME_SUPPORT == OS_ON)||(OS_TP_ISR_RESOURCE_LOCKTIME_SUPPORT == OS_ON))
    Os_TpTickType OsResLockTimeBudget;
#endif /*((OS_TP_TSK_RESOURCE_LOCKTIME_SUPPORT == OS_ON)||(OS_TP_ISR_RESOURCE_LOCKTIME_SUPPORT == OS_ON))*/
} Os_TaskIsrResCfgType;

typedef enum
{
    OS_TP_NONE,
    OS_TP_EXECBUDGET,
    OS_TP_RESOURCELOCK,
    OS_TP_ISRLOCK,
    OS_TP_FRAMECHECK
} Os_TpMonitorType;

typedef struct
{
    Os_TpMonitorType type;
    Os_TpMonitorType mintype;
    Os_TpTickType minTime; /* shortest time at this level*/
} Os_TpInfoType;

/*****************************************************************************
* Task Cfg structure type define
******************************************************************************/
typedef void (*Os_TaskFuncType) (void);

/* Constants definition of task control block */
typedef struct
{
    Os_uint32 *OsTaskStkTop; /* The pointer to the top of the task stack */
    Os_uint32 *OsTaskStkBottom; /* The pointer to the buttom of the task stack */
    Os_uint16 OsTaskStkSize; /* The size of task stack */

    /* this parameter can not be optimized as IDLE task must be preemptable*/
    Os_boolean isPreemptable;
#if((OS_CC == OS_ECC1) || (OS_CC == OS_ECC2))
    Os_boolean isExtendTask;              /* Task type: BT or ET */
#endif /*((OS_CC == OS_ECC1) || (OS_CC == OS_ECC2))*/
    TaskType OsTaskID;                /* Global Task ID */
    Os_uint8 OsMaxActivationTimes;    /* The maximum activation time for a task*/
    Os_PrioType OsTaskCfgPrio;        /* Task static priority */

    Os_boolean isAutoStart;
#if(OS_APPMODE_NUMBER > 1)
    Os_AppModeMaskType appModeMask;
#endif /*(OS_APPMODE_NUMBER > 1)*/

#if((OS_TASK_RESOURCE_NUMBER > 0) || (OS_SHARE_RESOURCE_NUMBER > 0))
    CONSTP2CONST(Os_TaskIsrResCfgType, AUTOMATIC, OS_CONST) resPtr;
    ResourceType resNum;
#endif /*((OS_TASK_RESOURCE_NUMBER > 0) || (OS_SHARE_RESOURCE_NUMBER > 0))*/

#if(OS_ON == OS_MEM_PROTECTION_SUPPORT)
    Os_AddrType lowAddr;
    Os_AddrType highAddr;
#endif /*(OS_ON == OS_MEM_PROTECTION_SUPPORT)*/

#if(OS_APPLICATION_NUMBER > 0)
    ApplicationType ApplID;
    Os_ApplicationMaskType AppMask;
#endif /*(OS_APPLICATION_NUMBER > 0)*/

#if(OS_ON == OS_TP_TSK_ANYBUDGET_SUPPORT)
    CONSTP2VAR(Os_TpInfoType, AUTOMATIC, OS_VAR) tpInfo;
    Os_uint16 tpNestSize;/*task+res+ISR*/
#endif /*(OS_ON == OS_TP_TSK_ANYBUDGET_SUPPORT)*/
    /* TP data for AUTOSAR spec. V3/4 */
#if(OS_TP_TSK_EXBUDGET_SUPPORT == OS_ON)
    Os_TpTickType OsTaskExecBudget;  /* the execution budget */
#endif /*(OS_TP_TSK_EXBUDGET_SUPPORT == OS_ON)*/

#if(OS_TP_TSK_TIMEFRAME_SUPPORT == OS_ON)
    Os_TpTickType OsTaskTimeFrame;   /* time frame */
#endif /*(OS_TP_TSK_TIMEFRAME_SUPPORT == OS_ON)*/

#if(OS_TP_TSK_INTLOCKBUDGET_SUPPORT==OS_ON)
    Os_TpTickType OsTaskAllIntLockBudget;
    Os_TpTickType OsTaskOsIntLockBudget;
#endif /*(OS_TP_TSK_INTLOCKBUDGET_SUPPORT==OS_ON)*/

#if(OS_USED_CORE_NUMBER > 1)
    CoreIdType objCoreId;
    TaskType   TaskIdInCore;
#endif /*(OS_USED_CORE_NUMBER > 1)*/
    Os_TaskFuncType OsTaskAddr;       /* Entry address for a task */
} Os_TaskCfgType;

/* Constants config of task queue */
typedef struct
{
#if((OS_CC == OS_BCC2) || (OS_CC == OS_ECC2))
    CONSTP2VAR(Os_TaskQueueCtlType, AUTOMATIC, OS_VAR) Q_Ctl_Ptr;
    Os_uint16 Q_Size;
#endif /*((OS_CC == OS_BCC2) || (OS_CC == OS_ECC2))*/
#if(OS_RESOURCE_NUMBER > 0)
    CONSTP2VAR(TaskType, AUTOMATIC, OS_VAR) cellingTaskPtr;
#endif /*(OS_RESOURCE_NUMBER > 0)*/
    CONSTP2VAR(TaskType, AUTOMATIC, OS_VAR) Q_Buf;
} Os_TaskQueCfgType;

/* Constants config of task pri ready table */
#define OS_PRI_SHIFT_VALUE     ((Os_PrioType)5)
#define OS_PRI_MASK_VALUE      ((Os_PrioType)0x1F)

typedef struct
{
    CONSTP2VAR(Os_uint32, AUTOMATIC, OS_VAR) p_table_line;
    CONSTP2VAR(Os_uint32, AUTOMATIC, OS_VAR) p_table;
    Os_uint8 p_table_size; /* max size = 32*/
} Os_TaskPriReadyTblCfgType;

/*****************************************************************************
* ISR Cfg structure type define
******************************************************************************/
typedef struct
{
    Os_uint32 *OsIsrStkTop; /* The pointer to the top of the ISR stack */
    Os_uint32 *OsIsrStkBottom; /* The pointer to the buttom of the ISR stack */
    Os_uint16 OsIsrStkSize; /* The size of ISR stack */

    Os_boolean isC1Int;         /* type of the ISR */
#if(OS_ON == OS_ISR_NEST_SUPPORT)
    Os_boolean enNest;          /* enable Interrupt nesting */
#endif /*(OS_ON == OS_ISR_NEST_SUPPORT)*/

#if((OS_ISR_RESOURCE_NUMBER > 0) || (OS_SHARE_RESOURCE_NUMBER > 0))
    CONSTP2CONST(Os_TaskIsrResCfgType, AUTOMATIC, OS_CONST) resPtr;
    ResourceType resNum;
#endif /*((OS_ISR_RESOURCE_NUMBER > 0) || (OS_SHARE_RESOURCE_NUMBER > 0))*/

#if(OS_ON == OS_TP_ISR_ANYBUDGET_SUPPORT)
    CONSTP2VAR(Os_TpInfoType, AUTOMATIC, OS_VAR) tpInfo;
    Os_uint16 tpNestSize;/*ISR +res+ INT*/
#endif /*(OS_ON == OS_TP_ISR_ANYBUDGET_SUPPORT)*/

#if(OS_TP_ISR_EXBUDGET_SUPPORT == OS_ON)
    Os_TpTickType OsIsrExecBudget;  /* the execution budget */
#endif /*(OS_TP_ISR_EXBUDGET_SUPPORT == OS_ON)*/

#if(OS_TP_ISR_TIMEFRAME_SUPPORT==OS_ON)
    Os_TpTickType OsIsrTimeFrame;   /* time frame */
#endif /*(OS_TP_ISR_TIMEFRAME_SUPPORT==OS_ON)*/

#if(OS_TP_ISR_INTLOCKBUDGET_SUPPORT==OS_ON)
    Os_TpTickType OsIsrAllIntLockBudget;
    Os_TpTickType OsIsrOsIntLockBudget;
#endif /*(OS_TP_ISR_INTLOCKBUDGET_SUPPORT==OS_ON)*/

#if(OS_ON == OS_MEM_PROTECTION_SUPPORT)
    Os_AddrType lowAddr;
    Os_AddrType highAddr;
#endif /*(OS_ON == OS_MEM_PROTECTION_SUPPORT)*/

#if(OS_APPLICATION_NUMBER > 0)
    ApplicationType ApplID;
#endif /*(OS_APPLICATION_NUMBER > 0)*/

#if(OS_USED_CORE_NUMBER > 1)
    CoreIdType objCoreId;
#endif /*(OS_USED_CORE_NUMBER > 1)*/
    Os_PrioType Prio;             /* Interrupt priority */
    Os_uint16 vectorIndex;
} Os_ISRCfgType;

/*****************************************************************************
* OS-Application cfg types
******************************************************************************/
typedef void (*Os_AppStartupHookFuncType)   (void);
typedef void (*Os_AppErrorHookFuncType)     (StatusType Error);
typedef void (*Os_AppShutdownHookFuncType)  (StatusType Fatalerror);

typedef struct
{
    Os_boolean isTrusted;
    Os_boolean isTrustedWithProtec;
#if(OS_ON == OS_OSAPP_ERRORHOOK_SUPPORT)
    Os_AppErrorHookFuncType ErrorHookFunc;
#endif /*(OS_ON == OS_OSAPP_ERRORHOOK_SUPPORT)*/
#if(OS_ON == OS_OSAPP_STARTUPHOOK_SUPPORT)
    Os_AppStartupHookFuncType StartupHookFunc;
#endif /*(OS_ON == OS_OSAPP_STARTUPHOOK_SUPPORT)*/
#if(OS_ON == OS_OSAPP_SHUTDOWNHOOK_SUPPORT)
    Os_AppShutdownHookFuncType ShutdownHookFunc;
#endif /*(OS_ON == OS_OSAPP_SHUTDOWNHOOK_SUPPORT)*/

#if(OS_ON == OS_OSAPP_RESTARTTASK_SUPPORT)
    TaskType restartTask;
#endif /*(OS_ON == OS_OSAPP_RESTARTTASK_SUPPORT)*/

#if(OS_ON == OS_MEM_PROTECTION_SUPPORT)
    Os_AddrType *lowAddr;   
    Os_AddrType *highAddr;   
    Os_uint8 mpuDataNum;         
#if(OS_ON == OS_MEM_PROTECTION_CODE_APPLICATION_SUPPORT) 
    Os_AddrType osCodeLowAddr;      
    Os_AddrType osCodeHighAddr;     
    Os_AddrType *appCodeLowAddr;      
    Os_AddrType *appCodeHighAddr;    
    Os_uint8 mpuCodeNum;             
#endif /*(OS_ON == OS_MEM_PROTECTION_CODE_APPLICATION_SUPPORT)*/
#endif /*(OS_ON == OS_MEM_PROTECTION_SUPPORT)*/

#if(OS_USED_CORE_NUMBER > 1)
    CoreIdType    objCoreId;
    ApplicationType   AppIdInCore;
#endif /*(OS_USED_CORE_NUMBER > 1)*/
    
    CONSTP2CONST(TaskType, AUTOMATIC, OS_CONST) taskOfApp;
    TaskType taskNum;

    CONSTP2CONST(ISRType, AUTOMATIC, OS_CONST) isrOfApp;
    ISRType isrNum;

    CONSTP2CONST(AlarmType, AUTOMATIC, OS_CONST) alarmOfApp;
    AlarmType alarmNum;

#if(OS_SCHTBL_NUMBER > 0)
    CONSTP2CONST(ScheduleTableType, AUTOMATIC, OS_CONST) schTblOfApp;
    ScheduleTableType schTblNum;
#endif /*(OS_SCHTBL_NUMBER > 0)*/

    CONSTP2CONST(CounterType, AUTOMATIC, OS_CONST) cntOfApp;
    CounterType cntNum;
    
} Os_AppCfgType;

typedef void (*Os_TrustedFunctionPtrType)(TrustedFunctionParameterRefType  par);

typedef struct
{
    ApplicationType ApplID; 
    Os_TrustedFunctionPtrType FunPtr;
}Os_TrustFunCfgType;

/*****************************************************************************
* Counter cfg types
******************************************************************************/
typedef struct
{
#if(OS_SCHTBL_NUMBER > 0)
    Os_boolean isAlarm;
#endif /*(OS_SCHTBL_NUMBER > 0)*/
    Os_uint32 ObjId;/* Alarm or SchTbl Id*/

} Os_CounterTreeQueEleType;

typedef struct
{
#if(OS_APPLICATION_NUMBER > 0)
    ApplicationType ApplID;       /* Object belongs to this application */
    Os_ApplicationMaskType AppMask;     /* object can be accessed by these apps*/
#endif /*(OS_APPLICATION_NUMBER > 0)*/

#if(OS_USED_CORE_NUMBER > 1)
    CoreIdType    objCoreId;
    CounterType   CntIdInCore;
#endif /*(OS_USED_CORE_NUMBER > 1)*/

    AlarmBaseType alarmBase;

    Os_uint32 treeSize; /* number of Alarm and Schtbls using this counter */
    P2VAR(Os_CounterTreeQueEleType, AUTOMATIC, OS_VAR) treeQue;

} Os_CounterCfgType;

/*****************************************************************************
* Alarm cfg types
******************************************************************************/
typedef enum
{
    OS_ALARM_TASK = 0,
    OS_ALARM_EVENT = 1,
    OS_ALARM_CALLBACK = 2,
    OS_ALARM_INCREMENTCOUNTER = 3
} Os_AlarmActionType;

typedef void (*OS_AlarmCallBackType) (void); /* AlarmCallBackType : function pointer */

typedef struct
{
#if((OS_ALARM_ACTIVETASK_NUMBER > 0) || (OS_ALARM_SETEVENT_NUMBER > 0))
    TaskType TaskID;
#if(OS_ALARM_SETEVENT_NUMBER > 0)
    EventMaskType Event;
#endif /*(OS_ALARM_SETEVENT_NUMBER > 0)*/
#endif /*((OS_ALARM_ACTIVETASK_NUMBER > 0) || (OS_ALARM_SETEVENT_NUMBER > 0))*/

#if(OS_ALARM_CALLBACK_NUMBER > 0)
    OS_AlarmCallBackType callback;
#endif /*(OS_ALARM_CALLBACK_NUMBER > 0)*/
#if(OS_ALARM_INCREMENTCOUNTER_NUMBER > 0)
    CounterType CounterID;
#endif /*(OS_ALARM_INCREMENTCOUNTER_NUMBER > 0)*/

#if(OS_AUTO_ALARM_NUMBER > 0)
    TickType OsAlarmTime;          /* Initial time of Alarm */
    TickType OsAlarmCycle;         /* Initial cycle of Alarm */
    Os_boolean isAbsAlarm;
    Os_boolean isAutoStart;
#if(OS_APPMODE_NUMBER > 1)
    Os_AppModeMaskType appModeMask;
#endif /*(OS_APPMODE_NUMBER > 1)*/
#endif /*(OS_AUTO_ALARM_NUMBER > 0)*/

#if(OS_APPLICATION_NUMBER > 0)
    ApplicationType ApplID;       /* Object belongs to this application */
    Os_ApplicationMaskType AppMask;     /* object can be accessed by these apps*/
#endif /*(OS_APPLICATION_NUMBER > 0)*/

#if(OS_USED_CORE_NUMBER > 1)
    CoreIdType    objCoreId;
    AlarmType     AlarmIdInCore;
#endif /*(OS_USED_CORE_NUMBER > 1)*/

    AlarmType   AlarmID;          /* global id*/
    CounterType OsAlarmCounter;    /* Software counter for Alarm */
    Os_AlarmActionType OsAlarmAction; /* Desired action when the Alarm is triggered */

} Os_AlarmCfgType;

/*****************************************************************************
* SchTbl cfg types
******************************************************************************/
#if(OS_SCHTBL_NUMBER > 0)
typedef enum
{
    OS_EP_TASK = 0,
    OS_EP_EVENT = 1
} Os_SchTblEpActionType;

typedef struct
{
    Os_SchTblEpActionType EpAction;
    TaskType TaskID;
#if(OS_EXTENDED_TASK_NUMBER > 0)
    EventMaskType Event;
#endif
} Os_SchTblEpActionCfgType;

typedef struct
{
    TickType OsEpOffset;
    Os_uint8 EpActionNum; /* max 255 ep action support*/
    CONSTP2CONST(Os_SchTblEpActionCfgType,AUTOMATIC, OS_CONST) epActionList;
} Os_SchTblEpCfgType;

/* Caution!!!!!  when generate EP for schedule table, must add 1 end EP for table
   endEp is a internal EP used by OS
*/
typedef struct
{
#if(OS_AUTO_SCHTBL_NUMBER > 0)
    TickType startTimeValue;          /* Start time of schtbl */
    Os_boolean isAbsSchTbl;
    Os_boolean isAutoStart;
#if(OS_APPMODE_NUMBER > 1)
    Os_AppModeMaskType appModeMask;
#endif /*(OS_APPMODE_NUMBER > 1)*/
#endif /*(OS_AUTO_SCHTBL_NUMBER > 0)*/

#if(OS_APPLICATION_NUMBER > 0)
    ApplicationType ApplID;       /* Object belongs to this application */
    Os_ApplicationMaskType AppMask;     /* object can be accessed by these apps*/
#endif /*(OS_APPLICATION_NUMBER > 0)*/

#if(OS_USED_CORE_NUMBER > 1)
    CoreIdType    objCoreId;
    ScheduleTableType   SchTblIdInCore;
#endif /*(OS_USED_CORE_NUMBER > 1)*/

    ScheduleTableType   SchTblId;          /* global id*/
    CounterType         refCounter;    /* Software counter for SchTbl */

    Os_boolean         isRepeat;
    TickType            FinalDelay;   /* OsScheduleTableDuration - offset of last e, not used by now*/
    Os_uint8 EpNum; /* max 255 ep support*/
    CONSTP2CONST(Os_SchTblEpCfgType,AUTOMATIC, OS_CONST) epList;
} Os_SchTblCfgType;
#endif /*(OS_SCHTBL_NUMBER > 0)*/

/*****************************************************************************
* Resource cfg types
******************************************************************************/
typedef enum
{
    OS_RES_TASK_ONLY = 0,
    OS_RES_ISR_ONLY = 1,
    OS_RES_SHARE = 2
} Os_ResAccessype;

/* Constants definition of resource control block */
typedef struct
{
    Os_ResAccessype    resAccessType; /* Indicate whether tasks or ISRs ask for the resource: ISR,TASK or SHARE */
    Os_PrioType ResCeilingPri_Task; /* The ceiling priority of resource for tasks */
    Os_PrioType ResCeilingPri_ISR;  /* The ceiling level of resources for ISR */

#if(OS_APPLICATION_NUMBER > 0)
    /*Resource dont belong to any app, but user should define which app can access it */
    Os_ApplicationMaskType AppMask;     /* object can be accessed by these apps*/
#endif /*(OS_APPLICATION_NUMBER > 0)*/

#if(OS_USED_CORE_NUMBER > 1)
    CoreIdType    objCoreId;
    ResourceType  resIdInCore;
#endif /*(OS_USED_CORE_NUMBER > 1)*/
} Os_ResourceCfgType;

/*****************************************************************************
* Spinlock cfg types
******************************************************************************/
typedef enum
{
    OS_LOCK_NOTHING = 0,
    OS_LOCK_ALL_INTERRUPTS = 1,
    OS_LOCK_CAT2_INTERRUPTS = 2,
    OS_LOCK_WITH_RES_SCHEDULER = 3
} Os_SpinlockMethodType;

typedef struct
{
#if(OS_APPLICATION_NUMBER > 0)
    /*SpinLock dont belong to any app, but user should define which app can access it */
    Os_ApplicationMaskType AppMask;     /* object can be accessed by these apps*/
#endif /*(OS_APPLICATION_NUMBER > 0)*/

#if(OS_SPINLOCK_LINK_NUMBER > 0)
    SpinlockIdType        LinkIndex; /* position in  link  group */
    SpinlockIdType        LinkGrp; /* this spinlock belong to which link group*/
#endif /*(OS_SPINLOCK_LINK_NUMBER > 0)*/
    Os_SpinlockMethodType SpinlockMethod;    /* Indicate the spinlock lock method */
} Os_SpinlockCfgType;

/*****************************************************************************
* IOC cfg types max supprt uint16 IOC number at this version
******************************************************************************/

/*****************************************************************************
* Core cfg types
******************************************************************************/
/*stack always used from Bottom to top*/
typedef struct
{
    TaskType startTaskId;
    TaskType taskNum;
    TaskType autotaskNum;
    TaskType extendtaskNum;
    TaskType idleTaskId;
    Os_PrioType TaskPriNumOfCore;
    CONSTP2CONST(Os_TaskQueCfgType, AUTOMATIC, OS_CONST) taskQueCfg;
    Os_TaskPriReadyTblCfgType taskPriReadyTableCfg;

    ISRType startIsrId; /*must C2 ISR first, then C1 */
    ISRType c2IsrNum;
    ISRType c1IsrNum;
    ISRType sysCntIsrId;
#if(OS_USED_CORE_NUMBER > 1)
    ISRType crossCoreIsrId;
#endif /*(OS_USED_CORE_NUMBER > 1)*/
    Os_PrioType topC2IsrPri;
#if(OS_TIMING_PROTECTION_SUPPORT  == OS_ON)
    ISRType tpIsrId;
#endif /*(OS_TIMING_PROTECTION_SUPPORT  == OS_ON)*/

    /* nest ISR size = Num of C2ISR of  this core whose int nest is enabled */
    P2VAR(ISRType, AUTOMATIC, OS_VAR) nestIsrIdPtr;
    ISRType maxNestSize;
#if(OS_ALARM_NUMBER > 0)
    AlarmType startAlarmId;
    AlarmType alarmNum;
    AlarmType autoAlarmNum;
#endif /*(OS_ALARM_NUMBER > 0)*/
#if(OS_SCHTBL_NUMBER > 0)
    ScheduleTableType startSchId;
    ScheduleTableType schNum;
    ScheduleTableType autoSchNum;
#endif /*(OS_SCHTBL_NUMBER > 0)*/

#if(OS_RESOURCE_NUMBER > 0)
    ResourceType startResId;
    ResourceType resNum;
#endif /*(OS_RESOURCE_NUMBER > 0)*/

#if(OS_APPLICATION_NUMBER > 0)
    ApplicationType startAppId;
    ApplicationType appNum;
#endif /*(OS_APPLICATION_NUMBER > 0)*/

    CounterType startCntId; /*also the system counter id of each core*/
    CounterType cntNum;

} Os_CoreCfgType;

#endif /*OS_TYPES_H*/
