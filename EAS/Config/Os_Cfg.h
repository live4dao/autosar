/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : Os_Cfg.h
********************************************************************************
*   Project/Product : AUTOSAR BSW PROJECT
*   Title           : OS module configuration File
*   Author          : Hirain
********************************************************************************
*   Description     : OS module configuration File
*
********************************************************************************
*   Limitations     : None
*
********************************************************************************
*
********************************************************************************
*   Revision History:
*
*   Version     Date          Initials      CR#          Descriptions
*   ---------   ----------    ------------  ----------   ---------------
*   V1.0.2_3.5.5_AZ240046       10/05/2024    Eas           N/A          N/A
*
********************************************************************************
* END_FILE_HDR*/

#ifndef OS_CFG_H
#define OS_CFG_H

/*****************************************************************************


* General QAC Suppression
******************************************************************************/
/*PRQA S 3453,3429,0792 EOF*/
/*
This part has been verified and has no problem.
The form of macros were defined by detail design of OS.
*/

/*PRQA S 3332 EOF*/
/*
"OS_ON" was defined in Os_BasicTypes.h.
*/

/*****************************************************************************
* Generate tool's version
******************************************************************************/
#define OS_VERSION_CHECK                                    OS_ON
#define OS_SW_MAJOR_VERSION_CFG                             1
#define OS_SW_TEC_VERSION_CFG                               6
#define OS_SW_TKPC_VERSION_CFG                              4
#define OS_SW_PATCH_VERSION_CFG                             0
#define OS_AR_RELEASE_MAJOR_VERSION_CFG                     4
#define OS_AR_RELEASE_MINOR_VERSION_CFG                     2
#define OS_AR_RELEASE_REVISION_VERSION_CFG                  2

/*****************************************************************************
* feathers enable disable
******************************************************************************/
/*Kernel*/
#define OS_SC                                               OS_SC1

#define OS_CC                                               OS_ECC2
#define OS_STATUS_LEVEL                                     OS_EXTENDED
#define OS_CRC_SUPPORT                                      OS_OFF
/* not support yet, always off */
#define OS_SHUTDOWN_RESTART_SUPPORT                         OS_OFF
/*Stack related*/
#define OS_CHK_STACK                                        OS_ON
#define OS_STACK_USEAGE_API                                 OS_ON

/* Cpuload */
#define OS_CPULOAD_API                                      OS_OFF


/*ISR*/
#define OS_ISR_NEST_SUPPORT                                 OS_OFF

/*Timing Protection*/
#define OS_TIMING_PROTECTION_SUPPORT                        OS_OFF

#define OS_TP_TSK_TIMEFRAME_SUPPORT                         OS_OFF
#define OS_TP_TSK_ANYBUDGET_SUPPORT                         OS_OFF
#define OS_TP_TSK_EXBUDGET_SUPPORT                          OS_OFF
#define OS_TP_TSK_RESOURCE_LOCKTIME_SUPPORT                 OS_OFF
#define OS_TP_TSK_INTLOCKBUDGET_SUPPORT                     OS_OFF

#define OS_TP_ISR_TIMEFRAME_SUPPORT                         OS_OFF
#define OS_TP_ISR_ANYBUDGET_SUPPORT                         OS_OFF
#define OS_TP_ISR_EXBUDGET_SUPPORT                          OS_OFF
#define OS_TP_ISR_RESOURCE_LOCKTIME_SUPPORT                 OS_OFF
#define OS_TP_ISR_INTLOCKBUDGET_SUPPORT                     OS_OFF



#define OS_TP_TIMER_NEED                                    OS_OFF
#define OS_TP_FCTIMER_NEED                                    OS_OFF

/*Memory Protection*/
#define OS_MEM_PROTECTION_SUPPORT                           OS_OFF



#define OS_MEM_PROTECTION_CODE_APPLICATION_SUPPORT          OS_OFF


/*Counter*/
#define OS_CNT_TIMEPERBASE_GREAT1                           OS_ON

/*Os-Applications*/
#define OsApplication0_Core0                                0
#define OsApplication0_Core1                                1
#define OsApplication0_Core2                                2
#define OsApplication0_Core3                                3
#define OsApplication0_Core4                                4
#define OsApplication0_Core5                                5
#define OS_OSAPP_RESTARTTASK_SUPPORT                        OS_OFF


/*Hooks*/
#define OS_STARTUPHOOK_SUPPORT                              OS_OFF
#define OS_ERRORHOOK_SUPPORT                                OS_ON
#define OS_SHUTDOWNHOOK_SUPPORT                             OS_OFF
#define OS_PRETASKHOOK_SUPPORT                              OS_OFF
#define OS_POSTTASKHOOK_SUPPORT                             OS_OFF
#define OS_PREISRHOOK_SUPPORT                               OS_OFF
#define OS_POSTISRHOOK_SUPPORT                              OS_OFF
#define OS_PROTECTIONHOOK_SUPPORT                           OS_OFF
#define OS_OSAPP_ERRORHOOK_SUPPORT                          OS_OFF
#define OS_OSAPP_STARTUPHOOK_SUPPORT                        OS_OFF
#define OS_OSAPP_SHUTDOWNHOOK_SUPPORT                       OS_OFF


/*Spinlock*/
#define OS_SPINKLOCK_LOCKSCH_SUPPORT                        OS_OFF

/* Multicore*/
#define OS_MULTICORE_ACTION_TMEOUT                          ((Os_uint32)10000)
#define OS_MULTICORE_SHORT_TMEOUT                           ((Os_uint32)1000)

/*****************************************************************************
* cross core feathers enable disable
These switches make user to consider system crosscore careful
also reduce the code size
******************************************************************************/


/*****************************************************************************
* numbers of object
******************************************************************************/
#define OS_USED_CORE_NUMBER                                 6

#define OS_TASK_NUMBER                                      37
#define OS_EXTENDED_TASK_NUMBER                             5
#define OS_AUTO_TASK_NUMBER                                 6

#define OS_ISR_NUMBER                                       22
#define OS_COUNTER_NUMBER                                   6
#define OS_USER_COUNTER_NUMBER                              0

#define OS_ALARM_NUMBER                                     19
#define OS_AUTO_ALARM_NUMBER                                0
#define OS_ALARM_ACTIVETASK_NUMBER                          14
#define OS_ALARM_SETEVENT_NUMBER                            5
#define OS_ALARM_CALLBACK_NUMBER                            0
#define OS_ALARM_INCREMENTCOUNTER_NUMBER                    0

#define OS_RESOURCE_NUMBER                                  0
#define OS_TASK_RESOURCE_NUMBER                             0
#define OS_ISR_RESOURCE_NUMBER                              0
#define OS_SHARE_RESOURCE_NUMBER                            0



#define OS_SCHTBL_NUMBER                                    0
#define OS_AUTO_SCHTBL_NUMBER                               0
#define OS_SCHTBL_SETEVENT_NUMBER                           0


#define OS_SPINLOCK_NUMBER                                  0
#define OS_SPINLOCK_LINK_NUMBER                             0


#define OS_APPLICATION_NUMBER                               6
#define OS_IOC_NUMBER                                       63
#define OS_IOC_SPINLOCK_NUMBER                              63
#define OS_IOC_QUEUE_NUMBER                                 0


#define OS_APPMODE_NUMBER                                   1
#define OS_TRUSTED_FUNCTION_NUMBER                          0
/*****************************************************************************
* Object Handles
******************************************************************************/

/*Task*/
#define OsTask_Core0_InitTask                               0
#define OsTask_Core0_Bsw_5ms                                1
#define OsTask_Core0_App_10ms                               2
#define OsTask_Core0_BswWdgM_1ms                            3
#define OsTask_Core0_App_InitTask                           4
#define OsTask_Core1_Bsw_10ms                               6
#define OsTask_Core1_InitTask                               7
#define OsTask_Core1_App_10ms                               8
#define OsTask_Core1_App_InitTask                           9
#define OsTask_Core2_Bsw_10ms                               11
#define OsTask_Core2_InitTask                               12
#define OsTask_Core2_App_10ms                               13
#define OsTask_Core2_App_40ms                               14
#define OsTask_Core2_App_1ms                                15
#define OsTask_Core2_App_5ms                                16
#define OsTask_Core2_App_1s                                 17
#define OsTask_Core2_App_InitTask                           18
#define OsTask_Core3_Bsw_10ms                               20
#define OsTask_Core3_InitTask                               21
#define OsTask_Core3_App_10ms                               22
#define OsTask_Core3_App_20ms                               23
#define OsTask_Core3_App_40ms                               24
#define OsTask_Core3_App_InitTask                           25
#define OsTask_Core4_Bsw_10ms                               27
#define OsTask_Core4_InitTask                               28
#define OsTask_Core4_App_10ms                               29
#define OsTask_Core4_App_InitTask                           30
#define OsTask_Core5_Bsw_10ms                               32
#define OsTask_Core5_InitTask                               33
#define OsTask_Core5_App_10ms                               34
#define OsTask_Core5_App_InitTask                           35
#define TaskIdleCore0                                       5
#define TaskIdleCore1                                       10
#define TaskIdleCore2                                       19
#define TaskIdleCore3                                       26
#define TaskIdleCore4                                       31
#define TaskIdleCore5                                       36



/*ISR*/
#define STM0_ISROsCore0                                     0
#define CROSS_OsCore0                                       1
#define Os_IrqCAN2SR0                                       2
#define Os_IrqCAN2SR1                                       3
#define Os_IrqCAN2SR2                                       4
#define Os_IrqCAN2SR3                                       5
#define Os_IrqCAN2SR4                                       6
#define Os_IrqCAN2SR5                                       7
#define Os_IrqCAN2SR6                                       8
#define Os_IrqCAN2SR7                                       9
#define Os_IrqETHSR2                                        10
#define Os_IrqETHSR6                                        11
#define STM0_ISROsCore1                                     12
#define CROSS_OsCore1                                       13
#define STM0_ISROsCore2                                     14
#define CROSS_OsCore2                                       15
#define STM0_ISROsCore3                                     16
#define CROSS_OsCore3                                       17
#define STM0_ISROsCore4                                     18
#define CROSS_OsCore4                                       19
#define STM0_ISROsCore5                                     20
#define CROSS_OsCore5                                       21


/*Event*/
#define OsTask_Core1_Bsw_10ms_OsEvent_Core1_Bsw_10ms        ((EventMaskType)(0x00000001))
#define OsTask_Core2_Bsw_10ms_OsEvent_Core2_Bsw_10ms        ((EventMaskType)(0x00000001))
#define OsTask_Core3_Bsw_10ms_OsEvent_Core3_Bsw_10ms        ((EventMaskType)(0x00000001))
#define OsTask_Core4_Bsw_10ms_OsEvent_Core4_Bsw_10ms        ((EventMaskType)(0x00000001))
#define OsTask_Core5_Bsw_10ms_OsEvent_Core5_Bsw_10ms        ((EventMaskType)(0x00000001))


/*Alarm*/
#define OsAlarm_Core0_Bsw_5ms                               (AlarmType)0
#define OsAlarm_Core0_App_10ms                              (AlarmType)1
#define OsAlarm_Core0_BswWdgM_1ms                           (AlarmType)2
#define OsAlarm_Core1_App_10ms                              (AlarmType)3
#define OsAlarm_Core1_Bsw_10ms_Event                        (AlarmType)4
#define OsAlarm_Core2_App_10ms                              (AlarmType)5
#define OsAlarm_Core2_Bsw_10ms_Event                        (AlarmType)6
#define OsAlarm_Core2_App_40ms                              (AlarmType)7
#define OsAlarm_Core2_App_5ms                               (AlarmType)8
#define OsAlarm_Core2_App_1ms                               (AlarmType)9
#define OsAlarm_Core2_App_1s                                (AlarmType)10
#define OsAlarm_Core3_App_10ms                              (AlarmType)11
#define OsAlarm_Core3_Bsw_10ms_Event                        (AlarmType)12
#define OsAlarm_Core3_App_20ms                              (AlarmType)13
#define OsAlarm_Core3_App_40ms                              (AlarmType)14
#define OsAlarm_Core4_App_10ms                              (AlarmType)15
#define OsAlarm_Core4_Bsw_10ms_Event                        (AlarmType)16
#define OsAlarm_Core5_App_10ms                              (AlarmType)17
#define OsAlarm_Core5_Bsw_10ms_Event                        (AlarmType)18



/*Resource*/


/*App Mode*/
typedef enum
{
    OS_SYSTEM_APPMODE = 0x0,
    OS_INVALID_APPMODE = 0xFF
} AppModeType;
/* ScheduleTable */



/*Expiry Point*/

/*Counter*/
#define SystemCounterOsCore0                                ((CounterType)0)
#define OS_TICKS2NS_SystemCounterOsCore0(x)                 (1000000* (x))
#define OS_TICKS2US_SystemCounterOsCore0(x)                 (1000.000* (x))
#define OS_TICKS2MS_SystemCounterOsCore0(x)                 (1.000000* (x))
#define OS_TICKS2S_SystemCounterOsCore0(x)                  (0.001* (x))

#define SystemCounterOsCore1                                ((CounterType)1)
#define OS_TICKS2NS_SystemCounterOsCore1(x)                 (1000000* (x))
#define OS_TICKS2US_SystemCounterOsCore1(x)                 (1000.000* (x))
#define OS_TICKS2MS_SystemCounterOsCore1(x)                 (1.000000* (x))
#define OS_TICKS2S_SystemCounterOsCore1(x)                  (0.001* (x))

#define SystemCounterOsCore2                                ((CounterType)2)
#define OS_TICKS2NS_SystemCounterOsCore2(x)                 (1000000* (x))
#define OS_TICKS2US_SystemCounterOsCore2(x)                 (1000.000* (x))
#define OS_TICKS2MS_SystemCounterOsCore2(x)                 (1.000000* (x))
#define OS_TICKS2S_SystemCounterOsCore2(x)                  (0.001* (x))

#define SystemCounterOsCore3                                ((CounterType)3)
#define OS_TICKS2NS_SystemCounterOsCore3(x)                 (1000000* (x))
#define OS_TICKS2US_SystemCounterOsCore3(x)                 (1000.000* (x))
#define OS_TICKS2MS_SystemCounterOsCore3(x)                 (1.000000* (x))
#define OS_TICKS2S_SystemCounterOsCore3(x)                  (0.001* (x))

#define SystemCounterOsCore4                                ((CounterType)4)
#define OS_TICKS2NS_SystemCounterOsCore4(x)                 (1000000* (x))
#define OS_TICKS2US_SystemCounterOsCore4(x)                 (1000.000* (x))
#define OS_TICKS2MS_SystemCounterOsCore4(x)                 (1.000000* (x))
#define OS_TICKS2S_SystemCounterOsCore4(x)                  (0.001* (x))

#define SystemCounterOsCore5                                ((CounterType)5)
#define OS_TICKS2NS_SystemCounterOsCore5(x)                 (1000000* (x))
#define OS_TICKS2US_SystemCounterOsCore5(x)                 (1000.000* (x))
#define OS_TICKS2MS_SystemCounterOsCore5(x)                 (1.000000* (x))
#define OS_TICKS2S_SystemCounterOsCore5(x)                  (0.001* (x))


/*SpinLock*/
#endif

