/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
* File Name:       Os_Err.h
********************************************************************************
* Project/Product: AUTOSAR OS PROJECT
* Title:           Os_Err.h
* Author:          Hirain
********************************************************************************
* Description:     Define the Macro for error handling.
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

#ifndef OS_ERR_H
#define OS_ERR_H

/*****************************************************************************
* General QAC Suppression
******************************************************************************/
/*PRQA S 0792 EOF*/
/*
The form of macros were defined by detail design of OS.
*/


/*****************************************************************************
* Macro definition for Error Message
******************************************************************************/

/*****************************************************************************
* Standard Error Code Id
******************************************************************************/
#define E_OS_OK                    ((StatusType)0x00)
/* OSEK standard Error ID */
#define E_OS_ACCESS                ((StatusType)0x01)        /* Access to the service/object denied  */
#define E_OS_CALLEVEL              ((StatusType)0x02)        /* Access to the service from the ISR is not permitted  */
#define E_OS_ID                    ((StatusType)0x03)        /* Object ID is invalid */
#define E_OS_LIMIT                 ((StatusType)0x04)        /* Limit of services/objects exceeded   */
#define E_OS_NOFUNC                ((StatusType)0x05)        /* The object is not used, service rejected */
#define E_OS_RESOURCE              ((StatusType)0x06)        /* Task still occupies resource */
#define E_OS_STATE                 ((StatusType)0x07)        /* The state of the object is not correct for the required service */
#define E_OS_VALUE                 ((StatusType)0x08)        /* Value outside of the admissible limit    */


/* AUTOSAR added standard ID */
#define E_OS_STACKFAULT            ((StatusType)0x09)        /* A stack fault detected via stack monitoring by the OS */
#define E_OS_PARAM_POINTER         ((StatusType)0x0A)        /* A pointer argument OS an API is null */
#define E_OS_DISABLEDINT           ((StatusType)0x0B)        /* A service of the OS is called inside an interrupt disable/enable pair */
#define E_OS_SERVICEID             ((StatusType)0x0C)        /* Service can not be called */
#define E_OS_ILLEGAL_ADDRESS       ((StatusType)0x0D)        /* An invalid address is given as a parameter to a service */
#define E_OS_MISSINGEND            ((StatusType)0x0E)        /* Tasks terminates without a TerminateTask() or ChainTask() call */
#define E_OS_PROTECTION_MEMORY     ((StatusType)0x10)        /* A memory access violation occurred */
#define E_OS_PROTECTION_TIME       ((StatusType)0x11)        /* A Task/Category 2 ISR exceeds its execution time budget */
#define E_OS_PROTECTION_ARRIVAL    ((StatusType)0x12)        /* A Task/Category 2 ISR arrives before its timeframe has expired */
#define E_OS_PROTECTION_LOCKED     ((StatusType)0x13)        /* A Task/Category 2 ISR blocks for too long */
#define E_OS_PROTECTION_EXCEPTION  ((StatusType)0x14)        /* A trap occurred */
#define E_OS_CORE                  ((StatusType)0x15)        /* API called in idle or non-autosar core*/
#define E_OS_SPINLOCK              ((StatusType)0x16)
#define E_OS_INTERFERENCE_DEADLOCK ((StatusType)0x17)
#define E_OS_NESTING_DEADLOCK      ((StatusType)0x18)


/*****************************************************************************
* non fatal OS self define error code, start from 0x50
******************************************************************************/
#define E_OS_SYS_SPINLOCKMETHOD                      ((StatusType)0x50)
#define E_OS_SYS_SERVICE_NOTSUPPORT_CROSSCORE        ((StatusType)0x51)
#define E_OS_SYS_CROSSCORE_WAITING                   ((StatusType)0x52)
#define E_OS_SYS_CROSSCORE_ERR                       ((StatusType)0x53)
#define E_OS_SYS_IDLETIME_OVERFLOW                   ((StatusType)0x54)
#define E_OS_SYS_NO_ACCESS_RIGHT                     ((StatusType)0x55)
#define E_OS_SYS_SHUTDOWN_BY_UNTRUST_APP             ((StatusType)0x56)
#define E_OS_SYS_SPINLOCK_NEST_LIMIT_ERROR           ((StatusType)0x57)
#define E_OS_SYS_SHUTDOWN_BY_TERMINATE_APP           ((StatusType)0x58)
/*****************************************************************************
* fatal OS self define error code,  start from 0x80
******************************************************************************/
#define E_OS_SYSFATA_UNREACHABLE                  ((StatusType)0x80)
#define E_OS_SYSFATA_CNTTREE                      ((StatusType)0x81)
#define E_OS_SYSFATA_READYQUEUE                   ((StatusType)0x82)
#define E_OS_SYSFATA_CONTEXTCRC_ERR               ((StatusType)0x83)
#define E_OS_SYSFATA_ISRAPI_NEST_LIMIT_ERROR      ((StatusType)0x84)
#define E_OS_SYSFATA_ISR_NEST_LIMIT_ERROR         ((StatusType)0x85)
#define E_OS_SYSFATA_ISR_NEST_ID_ERROR            ((StatusType)0x86)

#define E_OS_SYSFATA_TP_TIMER_ERROR               ((StatusType)0x87)
#define E_OS_SYSFATA_TP_INDEX_ERROR               ((StatusType)0x88)

#define E_OS_SYSFATA_RES_NEST_LIMIT_ERROR         ((StatusType)0x89)

#define E_OS_SYSFATA_RES_CROSSCORE_TIMEOUT        ((StatusType)0x8A)
#define E_OS_SYSFATA_RESTART_TASK_INVALID         ((StatusType)0x8B)
#define E_OS_SYSFATA_IGNORE_NOT_ALLOWD            ((StatusType)0x8C)
#define E_OS_SYSFATA_RESTART_TASK_FAIL            ((StatusType)0x8D)

#define OS_INVALID_ERROR                          ((StatusType)0xFF)

/*****************************************************************************
* OS Detail error infos
* High Byte is standard err code
* Low byte is self define sub err code
******************************************************************************/
#define OS_IE_E_OK                          ((Os_uint16)0)
#define OS_IE_NOMORE_INFO                   ((Os_uint16)1)
#define OS_IE_NO_ERRPAR                     ((Os_uint32)2)


/*E_OS_ACCESS  = 01*/
#define OS_IE_SHUTDOWN_BY_UNTRUST_APP       ((Os_uint16)0x0100)
#define OS_IE_INVALID_OSAPPICATION          ((Os_uint16)0x0101)
#define OS_IE_NO_ACCESS_RIGHT               ((Os_uint16)0x0102)
#define OS_IE_EVENT_WORK_WITH_BT            ((Os_uint16)0x0103)
#define OS_IE_EVENT_ERRTASK                 ((Os_uint16)0x0104)
#define OS_IE_CHAINTASK_ERRTASK             ((Os_uint16)0x0105)

#define OS_IE_TASKRES_ACCBY_ISR             ((Os_uint16)0x0106)
#define OS_IE_ISRRES_ACCBY_TASK             ((Os_uint16)0x0107)
#define OS_IE_RES_ACCBY_HPRIISR             ((Os_uint16)0x0108)
#define OS_IE_RES_ACCBY_HPRITASK            ((Os_uint16)0x0109)
#define OS_IE_RES_LIFO_ERROR                ((Os_uint16)0x010A)
#define OS_IE_SPINLOCK_LIFO_ERROR           ((Os_uint16)0x010B)

#define OS_IE_TERMINATEAPP_BY_UNTRUST_APP   ((Os_uint16)0x010C)
#define OS_IE_TERMINATETASK_ERRTASK         ((Os_uint16)0x010D)
#define OS_IE_OBJECT_KILLED                 ((Os_uint16)0x010E)
#define OS_IE_EVENT_ERRTASK_STATE           ((Os_uint16)0x010F)
#define OS_IE_ALARM_ALREADY_ALIVE           ((Os_uint16)0x0110)
#define OS_IE_SCHTBL_ALREADY_ALIVE          ((Os_uint16)0x0111)

/*E_OS_CALLEVEL*/

/*E_OS_ID */
#define OS_IE_TASK_ID                     ((Os_uint16)0x0300)
#define OS_IE_RES_ID                      ((Os_uint16)0x0301)
#define OS_IE_APPMODE_ID                  ((Os_uint16)0x0302)
#define OS_IE_ISR_ID                      ((Os_uint16)0x0303)
#define OS_IE_COUNTER_ID                  ((Os_uint16)0x0304)
#define OS_IE_ALARM_ID                    ((Os_uint16)0x0305)
#define OS_IE_SCHTBL_ID                   ((Os_uint16)0x0306)
#define OS_IE_SCHTBL_NEXT_CNT_NOTSAME     ((Os_uint16)0x0307)
#define OS_IE_COREID                      ((Os_uint16)0x0308)
#define OS_IE_SPINLOCK_ID                 ((Os_uint16)0x0309)
#define OS_IE_OSAPP_ID                    ((Os_uint16)0x030A)
#define OS_IE_OBJECT_ID                   ((Os_uint16)0x030B)
#define OS_IE_TRUSTFUN_ID                 ((Os_uint16)0x030C)
#define OS_IE_IOC_ID                      ((Os_uint16)0x030D)


/*E_OS_VALUE*/
#define OS_IE_ALARM_INCREAMENT            ((Os_uint16)0x0800)
#define OS_IE_ALARM_CYCLE                 ((Os_uint16)0x0801)
#define OS_IE_ALARM_START                 ((Os_uint16)0x0802)

#define OS_IE_SCHTBL_START                ((Os_uint16)0x0803)
#define OS_IE_SCHTBL_OFFSET               ((Os_uint16)0x0804)

/*E_OS_SYS_UNREACHABLE*/

/*E_OS_SYS_READYQUEUE*/
#define OS_IE_READYQUEUE_FULL             ((Os_uint16)0x5100)
#define OS_IE_READYQUEUE_EMPTY            ((Os_uint16)0x5101)
#define OS_IE_READYQUEUE_DATAERR          ((Os_uint16)0x5102)

/*E_OS_LIMIT*/
#define OS_IE_TASK_ACTIVE_TIMES_ERROR        ((Os_uint16)0x0400)

#define OS_IE_IOC_QUEUE_FULL                 ((Os_uint16)0x0401)
#define OS_IE_IOC_QUEUE_EMPTY                ((Os_uint16)0x0402)


/*E_OS_STATE*/
#define OS_IE_APP_ALREADY_TERMINATE          ((Os_uint16)0x0700)
#define OS_IE_APP_RESTART_TERMINATE          ((Os_uint16)0x0701)
#define OS_IE_APP_ALREADY_RESTART            ((Os_uint16)0x0702)
#define OS_IE_APP_NO_RESTART_TASK            ((Os_uint16)0x0703)
#define OS_IE_APP_RESTART_STATE_ERR          ((Os_uint16)0x0704)
#define OS_IE_APP_RESTART_TASK_ERR           ((Os_uint16)0x0705)

/*****************************************************************************
* IOC special Error code
******************************************************************************/
#define IOC_E_OK                   ((Std_ReturnType)0)
#define IOC_E_NOK                  ((Std_ReturnType)1)
#define IOC_E_LIMIT                ((Std_ReturnType)130)
#define IOC_E_LOST_DATA            ((Std_ReturnType)64)
#define IOC_E_NO_DATA              ((Std_ReturnType)131)

/*****************************************************************************
* OS Function Id:
*
* Highbyte = module id:
* kernel layer 0x0~0x7F, portable layer 0x80 ~ 0xFF
*
* 0x0--Kernel, 0x1--Task, 0x2--ISR, 0x3--Event, 0x4--Alarm
* 0x5--SchTbl, 0x6--Resource, 0x7--Counter, 0x8--Application, 0x9--MemoryProtection
* 0xA--Spinlock, 0xB--TimingProtectioon, 0xC--IOC, 0xD--CRC, 0xE--Hook, 0xF-MultiCore
*
* 0x80--Cpu, 0x81--Timer, 0x82--Intc, 0x83--Mpu
*
* LowByte =  function id:
*
* API:                     0x1~0x4F
* Internal function:       0x50~0x7F
* module private function  0x80~0xFF
*
******************************************************************************/
/*****************************************************************************
* OS service API
******************************************************************************/
/*kernel*/
#define OSServiceId_StartOS                       ((OSServiceIdType)0x001)
#define OSServiceId_ShutdownOS                    ((OSServiceIdType)0x002)
#define OSServiceId_GetSysStackUsage              ((OSServiceIdType)0x003)
#define OSServiceId_GetTaskStackUsage             ((OSServiceIdType)0x004)
#define OSServiceId_GetISRStackUsage              ((OSServiceIdType)0x005)
#define OSServiceId_GetCpuLoadValue               ((OSServiceIdType)0x006)
#define OSServiceId_GetActiveApplicationMode      ((OSServiceIdType)0x007)

/*Task*/
#define OSServiceId_ActivateTask                  ((OSServiceIdType)0x101)
#define OSServiceId_TerminateTask                 ((OSServiceIdType)0x102)
#define OSServiceId_ChainTask                     ((OSServiceIdType)0x103)
#define OSServiceId_Schedule                      ((OSServiceIdType)0x104)
#define OSServiceId_GetTaskID                     ((OSServiceIdType)0x105)
#define OSServiceId_GetTaskState                  ((OSServiceIdType)0x106)

/*ISR*/
#define OSServiceId_EnableAllInterrupts           ((OSServiceIdType)0x201)
#define OSServiceId_DisableAllInterrupts          ((OSServiceIdType)0x202)
#define OSServiceId_ResumeOSInterrupts            ((OSServiceIdType)0x203)
#define OSServiceId_SuspendOSInterrupts           ((OSServiceIdType)0x204)
#define OSServiceId_ResumeAllInterrupts           ((OSServiceIdType)0x205)
#define OSServiceId_SuspendAllInterrupts          ((OSServiceIdType)0x206)
#define OSServiceId_GetISRID                      ((OSServiceIdType)0x207)
/* SWS_Os_00808 */
#define OSServiceId_EnableInterruptSource         ((OSServiceIdType)0x208)
#define OSServiceId_DisableInterruptSource        ((OSServiceIdType)0x209)
#define OSServiceId_ClearPendingInterrupt         ((OSServiceIdType)0x20A)

/*Event*/
#define OSServiceId_SetEvent                      ((OSServiceIdType)0x301)
#define OSServiceId_ClearEvent                    ((OSServiceIdType)0x302)
#define OSServiceId_GetEvent                      ((OSServiceIdType)0x303)
#define OSServiceId_WaitEvent                     ((OSServiceIdType)0x304)

/*Alarm*/
#define OSServiceId_GetAlarmBase                  ((OSServiceIdType)0x401)
#define OSServiceId_GetAlarm                      ((OSServiceIdType)0x402)
#define OSServiceId_SetRelAlarm                   ((OSServiceIdType)0x403)
#define OSServiceId_SetAbsAlarm                   ((OSServiceIdType)0x404)
#define OSServiceId_CancelAlarm                   ((OSServiceIdType)0x405)

/*schtbl*/
#define OSServiceId_StartScheduleTableRel         ((OSServiceIdType)0x501)
#define OSServiceId_StartScheduleTableAbs         ((OSServiceIdType)0x502)
#define OSServiceId_NextScheduleTable             ((OSServiceIdType)0x503)
#define OSServiceId_StopScheduleTable             ((OSServiceIdType)0x504)
#define OSServiceId_GetScheduleTableStatus        ((OSServiceIdType)0x505)

/*Resource*/
#define OSServiceId_GetResource                   ((OSServiceIdType)0x601)
#define OSServiceId_ReleaseResource               ((OSServiceIdType)0x602)

/*Counter*/
#define OSServiceId_IncrementCounter              ((OSServiceIdType)0x701)
#define OSServiceId_GetCounterValue               ((OSServiceIdType)0x702)
#define OSServiceId_GetElapsedValue               ((OSServiceIdType)0x703)

/*Application*/
#define OSServiceId_GetApplicationID              ((OSServiceIdType)0x801)
#define OSServiceId_GetCurrentApplicationID       ((OSServiceIdType)0x802)
#define OSServiceId_CheckObjectAccess             ((OSServiceIdType)0x803)
#define OSServiceId_CheckObjectOwnership          ((OSServiceIdType)0x804)
#define OSServiceId_TerminateApplication          ((OSServiceIdType)0x805)
#define OSServiceId_AllowAccess                   ((OSServiceIdType)0x806)
#define OSServiceId_GetApplicationState           ((OSServiceIdType)0x807)
#define OSServiceId_CallTrustedFunction           ((OSServiceIdType)0x808)

/*Mem protection, no API in current version*/

/*Spinlock*/
#define OSServiceId_GetSpinlock                   ((OSServiceIdType)0xA01)
#define OSServiceId_ReleaseSpinlock               ((OSServiceIdType)0xA02)
#define OSServiceId_TryToGetSpinlock              ((OSServiceIdType)0xA03)

/*Timeing protection, no API in current version*/

/*IOC*/
#define OSServiceId_IocWrite                      ((OSServiceIdType)0xC01)
#define OSServiceId_IocRead                       ((OSServiceIdType)0xC02)
#define OSServiceId_IocWriteGroup                 ((OSServiceIdType)0xC03)
#define OSServiceId_IocReadGroup                  ((OSServiceIdType)0xC04)
#define OSServiceId_IocSend                       ((OSServiceIdType)0xC05)
#define OSServiceId_IocReceive                    ((OSServiceIdType)0xC06)
#define OSServiceId_IocSendGroup                  ((OSServiceIdType)0xC07)
#define OSServiceId_IocReceiveGroup               ((OSServiceIdType)0xC08)

/*Hook,CRC no API in current version*/

/*Multicore*/
#define OSServiceId_GetCoreID                     ((OSServiceIdType)0xF01)
#define OSServiceId_GetNumberOfActivatedCores     ((OSServiceIdType)0xF02)
#define OSServiceId_StartCore                     ((OSServiceIdType)0xF03)
#define OSServiceId_StartNonAutosarCore           ((OSServiceIdType)0xF04)
#define OSServiceId_ShutdownAllCores              ((OSServiceIdType)0xF05)
#define OSServiceId_ControlIdle                   ((OSServiceIdType)0xF06)


/*Cpu, no API in current version*/
/*Timer, no API in current version*/
/*Intc, no API in current version*/
/*Mpu, no API in current version*/

/*****************************************************************************
* internal and private function Id
******************************************************************************/
/* kernel */
#define OSServiceId_OsKernel_CheckCpuLoad        ((OSServiceIdType)0x0050)
#define OSServiceId_OsKernel_CheckTaskSwitch     ((OSServiceIdType)0x0051)
#define OSServiceId_OsKernel_EnterTask           ((OSServiceIdType)0x0052)
#define OSServiceId_OsKernel_ExitTask            ((OSServiceIdType)0x0053)
#define OSServiceId_OsKernel_InsertTask          ((OSServiceIdType)0x0054)
#define OSServiceId_OsKernel_RemoveTask          ((OSServiceIdType)0x0055)
#define OSServiceId_OsKernel_InternalShutdown    ((OSServiceIdType)0x0056)
#define OSServiceId_OsKernel_KillTask            ((OSServiceIdType)0x0057)
#define OSServiceId_OsKernel_NeedSchedule        ((OSServiceIdType)0x0058)

#define OSServiceId_OsKernel_ClearTaskPriReadyTable    ((OSServiceIdType)0x0080)
#define OSServiceId_OsKernel_GetHighestPriLine         ((OSServiceIdType)0x0081)
#define OSServiceId_OsKernel_UpdateTaskHighestPri      ((OSServiceIdType)0x0082)
#define OSServiceId_OsKernel_SetTaskPriReadyTable      ((OSServiceIdType)0x0083)
#define OSServiceId_OsKernel_OsKernel_SynStartUp       ((OSServiceIdType)0x0084)

/*Task*/
#define OSServiceId_OsTask_Init                  ((OSServiceIdType)0x0150)
#define OSServiceId_OsTask_AutoStart             ((OSServiceIdType)0x0151)
#define OSServiceId_OsTask_InternalActivateTask  ((OSServiceIdType)0x0152)
#define OSServiceId_OsTask_InternalTerminateTask ((OSServiceIdType)0x0153)
#define OSServiceId_OsTask_KillRunningTask       ((OSServiceIdType)0x0154)
#define OSServiceId_OsTask_KillTask              ((OSServiceIdType)0x0155)

#define OSServiceId_OsTask_InitTaskCBT           ((OSServiceIdType)0x0180)


/*ISR*/
#define OSServiceId_OsIsr_Init                   ((OSServiceIdType)0x0250)
#define OSServiceId_OsIsr_AutoResumeInterrupt    ((OSServiceIdType)0x0251)
#define OSServiceId_OsIsr_InISR1                 ((OSServiceIdType)0x0252)
#define OSServiceId_OsIsr_OutISR1                ((OSServiceIdType)0x0253)
#define OSServiceId_OsIsr_InISR2                 ((OSServiceIdType)0x0254)
#define OSServiceId_OsIsr_OutISR2                ((OSServiceIdType)0x0255)
#define OSServiceId_OsIsr_InternalSuspendAllInterrupts                ((OSServiceIdType)0x0256)
#define OSServiceId_OsIsr_InternalResumeAllInterrupts                 ((OSServiceIdType)0x0257)
#define OSServiceId_OsIsr_InternalSuspendOsInterrupts                 ((OSServiceIdType)0x0258)
#define OSServiceId_OsIsr_InternalResumeOsInterrupts                  ((OSServiceIdType)0x0259)
#define OSServiceId_OsIsr_RemoveAndSortISRQueue                       ((OSServiceIdType)0x025A)
#define OSServiceId_OsIsr_KillISR                                     ((OSServiceIdType)0x025B)
#define OSServiceId_OsIsr_KillRunningISR                              ((OSServiceIdType)0x025C)

#define OSServiceId_OsIsr_EnterISR               ((OSServiceIdType)0x0280)
#define OSServiceId_OsIsr_ExitISR                ((OSServiceIdType)0x0281)
#define OSServiceId_OsIsr_InitISRCBT             ((OSServiceIdType)0x0282)


/*Event*/
#define OSServiceId_OsEvent_InternalSetEvent      ((OSServiceIdType)0x0350)

/*Alarm*/
#define OSServiceId_OsAlarm_Init                  ((OSServiceIdType)0x0450)
#define OSServiceId_OsAlarm_Check                 ((OSServiceIdType)0x0451)
#define OSServiceId_OsAlarm_AutoStart             ((OSServiceIdType)0x0452)
#define OSServiceId_OsAlarm_KillAlarm             ((OSServiceIdType)0x0453)
#define OSServiceId_OsAlarm_InternalSetRelAlarm   ((OSServiceIdType)0x0454)
#define OSServiceId_OsAlarm_InternalSetAbsAlarm   ((OSServiceIdType)0x0455)
#define OSServiceId_OsAlarm_InternalCancelAlarm   ((OSServiceIdType)0x0456)

/*SchTbl*/
#define OSServiceId_OsSchTbl_Init                 ((OSServiceIdType)0x0550)
#define OSServiceId_OsSchTbl_AutoStart            ((OSServiceIdType)0x0551)
#define OSServiceId_OsSchTbl_Kill                 ((OSServiceIdType)0x0552)
#define OSServiceId_OsSchTbl_Trigger              ((OSServiceIdType)0x0553)
#define OSServiceId_OsSchTbl_InternalStartAbs     ((OSServiceIdType)0x0554)
#define OSServiceId_OsSchTbl_InternalStartRel     ((OSServiceIdType)0x0555)
#define OSServiceId_OsSchTbl_InternalStop         ((OSServiceIdType)0x0556)
#define OSServiceId_OsSchTbl_InternalNext         ((OSServiceIdType)0x0556)


/*Resource*/
#define OSServiceId_OsRes_Init                    ((OSServiceIdType)0x0650)
#define OSServiceId_OsRes_AutoReleaseTaskResource ((OSServiceIdType)0x0651)
#define OSServiceId_OsRes_AutoReleaseISRResource  ((OSServiceIdType)0x0652)

#define OSServiceId_OsRes_CheckBelongs            ((OSServiceIdType)0x0680)


/*Counter*/
#define OSServiceId_OsCnt_Init                    ((OSServiceIdType)0x0750)
#define OSServiceId_OsCnt_TreeInsert              ((OSServiceIdType)0x0751)
#define OSServiceId_OsCnt_TreeRemove              ((OSServiceIdType)0x0752)
#define OSServiceId_OsCnt_TreeDel                 ((OSServiceIdType)0x0753)
#define OSServiceId_OsCnt_InternalIncreamCounter  ((OSServiceIdType)0x0754)

#define OSServiceId_OsCnt_Compare                 ((OSServiceIdType)0x0780)

/*Application*/
#define OSServiceId_OsApp_Init                           ((OSServiceIdType)0x850)
#define OSServiceId_OsApp_InternalTerminateApplication   ((OSServiceIdType)0x851)

/*mem protection no function in this version*/

/*Spinlock */
#define OSServiceId_OsSpinlock_Init                      ((OSServiceIdType)0xA50)
#define OSServiceId_OsSpinLock_AutoReleaseISR            ((OSServiceIdType)0xA51)
#define OSServiceId_OsSpinLock_AutoReleaseTask           ((OSServiceIdType)0xA52)


#define OSServiceId_OsSpinlock_GetEnvCheck               ((OSServiceIdType)0xA80)
#define OSServiceId_OsSpinlock_OsSpinlock_CheckLinkOrder ((OSServiceIdType)0xA81)

/* timing protection*/
#define OSServiceId_OsTp_Init                            ((OSServiceIdType)0xB50)
#define OSServiceId_OsTp_TskExeBudgetStart               ((OSServiceIdType)0xB51)
#define OSServiceId_OsTp_TskExeBudgetStop                ((OSServiceIdType)0xB52)
#define OSServiceId_OsTp_TskPause                        ((OSServiceIdType)0xB53)
#define OSServiceId_OsTp_TskRestore                      ((OSServiceIdType)0xB54)
#define OSServiceId_OsTp_IsrExeBudgetStart               ((OSServiceIdType)0xB55)
#define OSServiceId_OsTp_IsrExeBudgetStop                ((OSServiceIdType)0xB56)
#define OSServiceId_OsTp_IsrPause                        ((OSServiceIdType)0xB57)
#define OSServiceId_OsTp_IsrRestore                      ((OSServiceIdType)0xB58)
#define OSServiceId_OsTp_IsrLockTimeStart                ((OSServiceIdType)0xB59)
#define OSServiceId_OsTp_IsrLockTimeStop                 ((OSServiceIdType)0xB5A)
#define OSServiceId_OsTp_TskResourceLocktimeStart        ((OSServiceIdType)0xB5B)
#define OSServiceId_OsTp_TskResourceLocktimeStop         ((OSServiceIdType)0xB5C)
#define OSServiceId_OsTp_IsrResourceLocktimeStart        ((OSServiceIdType)0xB5D)
#define OSServiceId_OsTp_IsrResourceLocktimeStop         ((OSServiceIdType)0xB5E)
#define OSServiceId_OsTp_TskTimeFrameCheck               ((OSServiceIdType)0xB5F)
#define OSServiceId_OsTp_IsrTimeFrameCheck               ((OSServiceIdType)0xB60)
#define OSServiceId_OsTp_ProtectionProcess               ((OSServiceIdType)0xB61)

#define OSServiceId_OsTp_DelTpInfo                       ((OSServiceIdType)0xB80)
#define OSServiceId_OsTp_AddNewTpInfo                    ((OSServiceIdType)0xB81)
#define OSServiceId_OsTp_PauseInternal                   ((OSServiceIdType)0xB82)


/*IOC*/
#define OSServiceId_OsIoc_Check                  ((OSServiceIdType)0x0C80)

/*Crc*/
#define OSServiceId_OsCrc_Caculate               ((OSServiceIdType)0x0D50)

/* Hook no need to define the API of hook*/

/* Multicore*/
#define OSServiceId_OsMultiCore_Init                       ((OSServiceIdType)0xF50)
#define OSServiceId_OsMultiCore_CrossCoreProcess           ((OSServiceIdType)0xF51)
#define OSServiceId_OsMultiCore_InternalShutdownAllCores   ((OSServiceIdType)0xF52)
#define OSServiceId_OsMultiCore_TriggerActivateTask        ((OSServiceIdType)0xF53)
#define OSServiceId_OsMultiCore_TriggerSetEvent            ((OSServiceIdType)0xF54)
#define OSServiceId_OsMultiCore_TriggerSetAbsAlarm         ((OSServiceIdType)0xF55)
#define OSServiceId_OsMultiCore_TriggerSetRelAlarm         ((OSServiceIdType)0xF55)
#define OSServiceId_OsMultiCore_TriggerCancelAlarm         ((OSServiceIdType)0xF56)
#define OSServiceId_OsMultiCore_TriggerShutdown            ((OSServiceIdType)0xF57)
#define OSServiceId_OsMultiCore_TriggerControlIdle         ((OSServiceIdType)0xF58)

#define OSServiceId_NO_SERVICE                             ((OSServiceIdType)0xFFFF)


#endif /*OS_ERR_H*/

