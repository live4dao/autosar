/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
*   File Name       : EcuM.h
********************************************************************************
*   Project/Product : AUTOSAR 4.2
*   Title           : The ECU state manager
*   Author          : mingqing.tang
********************************************************************************
*   Description     : The header file EcuM.h contains the declaration of the
*                     EcuM module API, 'extern' declarations of constants,
*                     global data,type definitions and services that are
*                     specified in the EcuM module SWS.
*
********************************************************************************
*   Limitations     : only used for AUTOSAR 4.2 version
*
********************************************************************************
*
********************************************************************************
*   Revision History:
*   Reference to Core C File
********************************************************************************
* END_FILE_HDR*/
#ifndef ECUM_H
#define ECUM_H

/*******************************************************************************
*   Includes
*******************************************************************************/
#include "EcuM_Cbk.h"


/*******************************************************************************
*   Macro
*******************************************************************************/
/*SWS_EcuM_03019*/
#define ECUM_E_EARLIER_ACTIVE                   ((Std_ReturnType)3)
#define ECUM_E_PAST                             ((Std_ReturnType)4)
#define ECUM_E_NOT_ACTIVE                       ((Std_ReturnType)5)
#define ECUM_E_RAM_CHECK_FAILED                 ((Std_ReturnType)6)
#define ECUM_E_CONFIGURATION_DATA_INCONSISTENT  ((Std_ReturnType)7)
#define ECUM_E_IMPROPER_CALLER                  ((Std_ReturnType)8)

#define ECUM_E_UNINIT                           ((Std_ReturnType)0x10)
#define ECUM_E_SERVICE_DISABLED                 ((Std_ReturnType)0x11)
#define ECUM_E_NULL_POINTER                     ((Std_ReturnType)0x12)
#define ECUM_E_INVALID_PAR                      ((Std_ReturnType)0x13)
#define ECUM_E_STATE_PAR_OUT_OF_RANGE           ((Std_ReturnType)0x16)
#define ECUM_E_UNKNOWN_WAKEUP_SOURCE            ((Std_ReturnType)0x17)
#define ECUM_E_INIT_FAILED                      ((Std_ReturnType)0x18)
#define ECUM_E_MULTIPLE_RUN_REQUESTS            ((Std_ReturnType)0x19)
#define ECUM_E_MISMATCHED_RUN_RELEASE           ((Std_ReturnType)0x20)

#define ECUM_API_GETVERSIONINFO                 (0x00)
#define ECUM_API_INIT                           (0x01)
#define ECUM_API_SHUTDOWN                       (0x02)
#define ECUM_API_STARTUPTWO                     (0x1A)
#define ECUM_API_GODOWN                         (0x1F)
#define ECUM_API_GOHALT                         (0x20)
#define ECUM_API_GOPOLL                         (0x21)
#define ECUM_API_GODOWNHALTPOLL                 (0x2C)
#define ECUM_API_SETSTATE                       (0x2B)
#define ECUM_API_REQUESTRUN                     (0x03)
#define ECUM_API_RELEASERUN                     (0x04)
#define ECUM_API_REQUESTPOSTRUN                 (0x0A)
#define ECUM_API_RELEASEPOSTRUN                 (0x0B)
#define ECUM_API_SELECTSHUTDOWNTARGET           (0x06)
#define ECUM_API_GETLASTSHUTDOWNTARGET          (0x08)
#define ECUM_API_GETSHUTDOWNTARGET              (0x09)
#define ECUM_API_SELECTSHUTDOWNCAUSE            (0x1B)
#define ECUM_API_GETSHUTDOWNCAUSE               (0x1C)
#define ECUM_API_GETPENDINGWAKEUPEVENTS         (0x0D)
#define ECUM_API_GETVALIDATEDWAKEUPEVENTS       (0x15)
#define ECUM_API_CLEARWAKEUPEVENTS              (0x16)
#define ECUM_API_GETEXPIREDWAKEUPEVENTS         (0x19)
#define ECUM_API_SELECTBOOTTARGET               (0x12)
#define ECUM_API_GETBOOTTARGET                  (0x13)
#define ECUM_API_MAINFUNCTION                   (0x18)
#define ECUM_API_SETWAKEUPEVENT                 (0x0C)
#define ECUM_API_VALIDATEWAKEUPEVENT            (0x14)
#if (ECUM_ALARM_CLOCK_PRESENT == STD_ON)
#define ECUM_API_SETRELWAKEUPALARM              (0x22)
#define ECUM_API_SETABSWAKEUPALARM              (0x23)
#define ECUM_API_ABORTWAKEUPALARM               (0x24)
#define ECUM_API_GETCURRENTTIME                 (0x25)
#define ECUM_API_GETWAKEUPTIME                  (0x26)
#define ECUM_API_SETCLOCK                       (0x27)
#endif


#if (ECUM_SHUTDOWN_TARGET_SLEEP_SUPPORT == STD_OFF)
#define EcuM_GoHalt()                           ECUM_E_SERVICE_DISABLED
#define EcuM_GoPoll()                           ECUM_E_SERVICE_DISABLED


#if (ECUM_WAKEUPSOURCE_VALIDATION == STD_OFF)
#define EcuM_GetExpiredWakeupEvents()           ECUM_WKSTATUS_NONE
#define EcuM_GetPendingWakeupEvents()           ECUM_WKSTATUS_NONE
#endif

#if (ECUM_ALARM_CLOCK_PRESENT == STD_OFF)
#define EcuM_SetRelWakeupAlarm(user,time)       E_NOT_OK
#define EcuM_SetAbsWakeupAlarm(user,time)       E_NOT_OK
#define EcuM_AbortWakeupAlarm(user)             E_NOT_OK
#define EcuM_GetCurrentTime(time)               E_NOT_OK
#define EcuM_GetWakeupTime(time)                E_NOT_OK
#define EcuM_SetClock(user,time)                E_NOT_OK
#elif (ECUM_SETCLOCK_USER_NUMBER == 0)
#define EcuM_SetClock(user,time)                E_NOT_OK
#endif /*ECUM_ALARM_CLOCK_PRESENT == STD_OFF*/
#endif /*ECUM_SHUTDOWN_TARGET_SLEEP_SUPPORT == STD_OFF*/


/*******************************************************************************
*   Global Data Declaration
*******************************************************************************/

/*******************************************************************************
*   Global Function Declaration
*******************************************************************************/
#define ECUM_START_SEC_CODE
#include "MemMap.h"
/*SWS_EcuM_02811*/
extern FUNC(void, ECUM_CODE) EcuM_Init
(
    void
);

/*SWS_EcuM_02838*/
extern FUNC(void, ECUM_CODE) EcuM_StartupTwo
(
    void
);

/*SWS_EcuM_02812*/
extern FUNC(void, ECUM_CODE) EcuM_Shutdown
(
    void
);

/*SWS_EcuM_04046*/
extern FUNC(Std_ReturnType, ECUM_CODE) EcuM_GoDown
(
    uint16 caller
);

#if (ECUM_SHUTDOWN_TARGET_SLEEP_SUPPORT == STD_ON)
/*SWS_EcuM_04048*/
extern FUNC(Std_ReturnType, ECUM_CODE) EcuM_GoHalt
(
    void
);

/*SWS_EcuM_04049*/
extern FUNC(Std_ReturnType, ECUM_CODE) EcuM_GoPoll
(
    void
);
#endif

/*SWS_EcuM_91002*/
extern FUNC(Std_ReturnType, ECUM_CODE) EcuM_GoDownHaltPoll
(
    uint16 caller
);

/*SWS_EcuM_04122*/
extern FUNC(void, ECUM_CODE) EcuM_SetState
(
    EcuM_StateType state
);

/*SWS_EcuM_04124*/
extern FUNC(Std_ReturnType, ECUM_CODE) EcuM_RequestRUN
(
    EcuM_UserType user
);

/*SWS_EcuM_04127*/
extern FUNC(Std_ReturnType, ECUM_CODE) EcuM_ReleaseRUN
(
    EcuM_UserType user
);


/*SWS_EcuM_04128*/
extern FUNC(Std_ReturnType, ECUM_CODE) EcuM_RequestPOST_RUN
(
    EcuM_UserType user
);

/*SWS_EcuM_04129*/
extern FUNC(Std_ReturnType, ECUM_CODE) EcuM_ReleasePOST_RUN
(
    EcuM_UserType user
);

/*SWS_EcuM_02822*/
extern FUNC(Std_ReturnType, ECUM_CODE) EcuM_SelectShutdownTarget
(
    EcuM_ShutdownTargetType shutdownTarget,
    EcuM_ShutdownModeType shutdownMode
);

/*SWS_EcuM_02824*/
extern FUNC(Std_ReturnType, ECUM_CODE) EcuM_GetShutdownTarget
(
    P2VAR(EcuM_ShutdownTargetType, AUTOMATIC, ECUM_APPL_DATA) shutdownTarget,
    P2VAR(EcuM_ShutdownModeType, AUTOMATIC, ECUM_APPL_DATA) shutdownMode
);

/*SWS_EcuM_02825*/
extern FUNC(Std_ReturnType, ECUM_CODE) EcuM_GetLastShutdownTarget
(
    P2VAR(EcuM_ShutdownTargetType, AUTOMATIC, ECUM_APPL_DATA) shutdownTarget,
    P2VAR(EcuM_ShutdownModeType, AUTOMATIC, ECUM_APPL_DATA) shutdownMode
);

/*SWS_EcuM_04050*/
extern FUNC(Std_ReturnType, ECUM_CODE) EcuM_SelectShutdownCause
(
    EcuM_ShutdownCauseType target
);

/*SWS_EcuM_04051*/
extern FUNC(Std_ReturnType, ECUM_CODE) EcuM_GetShutdownCause
(
    P2VAR(EcuM_ShutdownCauseType, AUTOMATIC, ECUM_APPL_DATA) shutdownCause
);


/*SWS_EcuM_02835*/
extern FUNC(Std_ReturnType, ECUM_CODE) EcuM_SelectBootTarget
(
    EcuM_BootTargetType target
);

/*SWS_EcuM_02836*/
extern FUNC(Std_ReturnType, ECUM_CODE) EcuM_GetBootTarget
(
    P2VAR(EcuM_BootTargetType, AUTOMATIC, ECUM_APPL_DATA) target
);

/*SWS_EcuM_02837*/
extern FUNC(void, ECUM_CODE) EcuM_MainFunction
(
    void
);

#if (ECUM_SHUTDOWN_TARGET_SLEEP_SUPPORT == STD_ON)
/*SWS_EcuM_02828*/
extern FUNC(void, ECUM_CODE) EcuM_ClearWakeupEvent
(
    EcuM_WakeupSourceType sources
);

/*SWS_EcuM_02830*/
extern FUNC(EcuM_WakeupSourceType, ECUM_CODE) EcuM_GetValidatedWakeupEvents
(
    void
);

#if (ECUM_WAKEUPSOURCE_VALIDATION == STD_ON)
/*SWS_EcuM_02831*/
extern FUNC(EcuM_WakeupSourceType, ECUM_CODE) EcuM_GetExpiredWakeupEvents
(
    void
);

/*SWS_EcuM_02827*/
extern FUNC(EcuM_WakeupSourceType, ECUM_CODE) EcuM_GetPendingWakeupEvents
(
    void
);

#endif /*ECUM_WAKEUPSOURCE_VALIDATION == STD_ON*/

#if (ECUM_ALARM_CLOCK_PRESENT == STD_ON)
/*SWS_EcuM_04054*/
extern FUNC(Std_ReturnType, ECUM_CODE) EcuM_SetRelWakeupAlarm
(
    EcuM_UserType user,
    EcuM_TimeType time
);

/*SWS_EcuM_04057*/
extern FUNC(Std_ReturnType, ECUM_CODE) EcuM_SetAbsWakeupAlarm
(
    EcuM_UserType user,
    EcuM_TimeType time
);

/*SWS_EcuM_04061*/
extern FUNC(Std_ReturnType, ECUM_CODE) EcuM_AbortWakeupAlarm
(
    EcuM_UserType user
);

/*SWS_EcuM_04062*/
extern FUNC(Std_ReturnType, ECUM_CODE) EcuM_GetCurrentTime
(
    P2VAR(EcuM_TimeType, AUTOMATIC, ECUM_APPL_DATA) time
);

/*SWS_EcuM_04063*/
extern FUNC(Std_ReturnType, ECUM_CODE) EcuM_GetWakeupTime
(
    P2VAR(EcuM_TimeType, AUTOMATIC, ECUM_APPL_DATA) time
);

#if (ECUM_SETCLOCK_USER_NUMBER > 0)
/*SWS_EcuM_04064*/
extern FUNC(Std_ReturnType, ECUM_CODE) EcuM_SetClock
(
    EcuM_UserType user,
    EcuM_TimeType time
);
#endif
#endif /*ECUM_ALARM_CLOCK_PRESENT == STD_ON*/
#endif /*ECUM_SHUTDOWN_TARGET_SLEEP_SUPPORT == STD_ON*/

#if (ECUM_VERSION_INFO_API == STD_ON)
/*SWS_EcuM_02813*/
extern FUNC(void, ECUM_CODE) EcuM_GetVersionInfo
(
    P2VAR(Std_VersionInfoType, AUTOMATIC, ECUM_APPL_DATA) versioninfo
);
#endif

#define ECUM_STOP_SEC_CODE
#include "MemMap.h"

#endif /* ECUM_H */

