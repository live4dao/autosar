/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
*   File Name       : EcuM_Types.h
********************************************************************************
*   Project/Product : AUTOSAR 4.2
*   Title           : The ECU state manager
*   Author          : mingqing.tang
********************************************************************************
*   Description     : This file contains the types of the EcuM module.
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

#ifndef ECUM_TYPES_H
#define ECUM_TYPES_H

/*******************************************************************************
*   Includes
*******************************************************************************/
#include "EcuM_Generated_Types.h"

/*******************************************************************************
*   Macro
*******************************************************************************/
#define ECUM_TYPE_FLEX                  (0)
#define ECUM_TYPE_FIXED                 (1)


/*******************************************************************************
*   Global Data Declaration
*******************************************************************************/
typedef uint8  EcuM_StateType;          /*SWS_EcuM_04039*/
/*SWS_EcuM_02664*//*SWS_EcuM_0507*/
#define ECUM_STATE_MASK                 ((EcuM_StateType)0xF0)
#define ECUM_SUBSTATE_MASK              ((EcuM_StateType)0x0F)
#define ECUM_STATE_STARTUP              ((EcuM_StateType)0x10)
#define ECUM_STATE_STARTUP_ONE          ((EcuM_StateType)0x11)
#define ECUM_STATE_STARTUP_TWO          ((EcuM_StateType)0x12)
#define ECUM_STATE_WAKEUP               ((EcuM_StateType)0x20)
#define ECUM_STATE_WAKEUP_ONE           ((EcuM_StateType)0x21)
#define ECUM_STATE_WAKEUP_VALIDATION    ((EcuM_StateType)0x22)
#define ECUM_STATE_WAKEUP_REACTION      ((EcuM_StateType)0x23)
#define ECUM_STATE_WAKEUP_TWO           ((EcuM_StateType)0x24)
#define ECUM_STATE_WAKEUP_WAKESLEEP     ((EcuM_StateType)0x25)
#define ECUM_STATE_WAKEUP_TTII          ((EcuM_StateType)0x26)
#define ECUM_STATE_RUN                  ((EcuM_StateType)0x30)
#define ECUM_STATE_APP_RUN              ((EcuM_StateType)0x32)
#define ECUM_STATE_APP_POST_RUN         ((EcuM_StateType)0x33)
#define ECUM_STATE_SHUTDOWN             ((EcuM_StateType)0x40)
#define ECUM_STATE_PREP_SHUTDOWN        ((EcuM_StateType)0x44)
#define ECUM_STATE_GO_SLEEP             ((EcuM_StateType)0x49)
#define ECUM_STATE_GO_OFF_ONE           ((EcuM_StateType)0x4d)
#define ECUM_STATE_GO_OFF_TWO           ((EcuM_StateType)0x4e)
#define ECUM_STATE_SLEEP                ((EcuM_StateType)0x50)
#define ECUM_STATE_OFF                  ((EcuM_StateType)0x80)
#define ECUM_STATE_RESET                ((EcuM_StateType)0x90)

/*SWS_EcuM_04120*/
typedef uint8 EcuM_RunStatusType;
#define ECUM_RUNSTATUS_UNKNOWN          ((EcuM_RunStatusType)0) /*Unknown status. Init Value.*/
#define ECUM_RUNSTATUS_REQUESTED        ((EcuM_RunStatusType)1) /*Status requested from EcuM*/
#define ECUM_RUNSTATUS_RELEASED         ((EcuM_RunStatusType)2) /*Status released from EcuM*/

typedef uint8 EcuM_WakeupStatusType;    /*SWS_EcuM_04041*/
#define ECUM_WKSTATUS_MAX               (6)
#define ECUM_WKSTATUS_NONE              ((EcuM_WakeupStatusType)0)
#define ECUM_WKSTATUS_PENDING           ((EcuM_WakeupStatusType)1)
#define ECUM_WKSTATUS_VALIDATED         ((EcuM_WakeupStatusType)2)
#define ECUM_WKSTATUS_EXPIRED           ((EcuM_WakeupStatusType)3)
#define ECUM_WKSTATUS_DISABLED          ((EcuM_WakeupStatusType)4)
#define ECUM_WKSTATUS_ENABLED           ((EcuM_WakeupStatusType)5)

typedef uint8 EcuM_BootTargetType;      /*SWS_EcuM_04042*/
#define ECUM_BOOT_TARGET_APP            ((EcuM_BootTargetType)0)
#define ECUM_BOOT_TARGET_OEM_BOOTLOADER ((EcuM_BootTargetType)1)
#define ECUM_BOOT_TARGET_SYS_BOOTLOADER ((EcuM_BootTargetType)2)
#define ECUM_BOOT_TARGET_MAX_NUMBER     ((EcuM_BootTargetType)3)

typedef uint8 EcuMAlarmIdType;
#define ECUM_INVALID_ALARMID            (EcuMAlarmIdType)ECUM_ALARM_CLOCK_NUMBER

typedef struct
{
    boolean ModeSuspend;
    Mcu_ModeType McuMode;    /*refence to McuModeSettingConf*/
    EcuM_WakeupSourceType WkSourceMask;
} EcuM_SleepModeType;

/*SWS_EcuM_04038*/
typedef struct
{
    AppModeType AppMode;
    uint8 HashLength;
    P2CONST(uint8, AUTOMATIC, ECUM_VAR) ConfigHashPtr;
    P2CONST(EcuM_FlexModuleConfigType, AUTOMATIC, ECUM_VAR) ModuleConfigPtr;
    EcuM_ShutdownTargetType DefaultTarget;
    EcuM_ShutdownModeType DefaultMode;
} EcuM_ConfigType;
/*******************************************************************************
*   Global Function Declaration
*******************************************************************************/

#endif /* ECUM_TYPES_H */

