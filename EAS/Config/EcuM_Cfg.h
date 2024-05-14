/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : EcuM_Cfg.h
********************************************************************************
*   Project/Product : AUTOSAR BSW PROJECT
*   Title           : EcuM module configuration File
*   Author          : Hirain
********************************************************************************
*   Description     : EcuM module configuration File
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
*   V1.0.0_3.5.5_AZ240046       27/03/2024    Eas           N/A          N/A
*
********************************************************************************
* END_FILE_HDR*/
#ifndef ECUM_CFG_H
#define ECUM_CFG_H

/*******************************************************************************
*   Includes
*******************************************************************************/


/*******************************************************************************
*   General
*******************************************************************************/

#define ECUM_CONFIG_VARIANTS                                STD_CONFIG_VARIANTS_POSTBUILD

/* generate tool's version*/
#define ECUM_SW_MAJOR_VERSION_CFG                           1
#define ECUM_SW_MINOR_VERSION_CFG                           1
#define ECUM_SW_PATCH_VERSION_CFG                           15
#define ECUM_AR_RELEASE_MAJOR_VERSION_CFG                   4
#define ECUM_AR_RELEASE_MINOR_VERSION_CFG                   2
#define ECUM_AR_RELEASE_REVISION_VERSION_CFG                2

#define ECUM_INSTANCE_TYPE                                  ECUM_TYPE_FLEX
#define ECUM_CORE_NUMBER                                    (6)
#define ECUM_CORE_MASTER_ID                                 ((uint8)0)
#define ECUM_SHUTDOWN_EVENT_MASK                            (0)
#define ECUM_SLEEP_EVENT_MASK                               (0)

#define ECUM_BOOT_TARGET_DEFAULT                            ECUM_BOOT_TARGET_APP
#define ECUM_CONFIG_HASH_LEN                                ((uint8)1)

#define ECUM_SHUTDOWN_TARGET_SLEEP_SUPPORT                  STD_OFF
#define ECUM_WAKEUPSOURCE_VALIDATION                        STD_OFF
#define ECUM_SLEEP_POLLING_MODE                             STD_OFF
#define ECUM_WAKEUPSOURCE_RESETREASON                       STD_OFF

#define ECUM_SLEEP_MODE_NUMBER                              (0)
#define ECUM_SLEEP_MODE_MAX_WKSRC_NUMBER                    (0)

#define EcuM_DisableAllInterrupts()
#define EcuM_EnableAllInterrupts()

/*ECUC_EcuM_00108*/
#define ECUM_DEV_ERROR_DETECT                               STD_ON
/*ECUC_EcuM_00118*/
#define ECUM_INCLUDE_DET                                    STD_ON
/*ECUC_EcuM_00149*/
#define ECUM_VERSION_INFO_API                               STD_ON
/*ECUC_EcuM_00121*/
#define ECUM_MAIN_FUNCTION_PERIOD                           (5)/*ms*/
#define ECUM_VERSION_CHECK                                  STD_ON
/*EcuM_CommonConfiguration(ECUC_EcuM_00181) START*/
#define ECUM_OS_RESOURCE_USED                               STD_OFF
#define ECUM_OS_RESOURCE_ID                                 0
/*EcuM_CommonConfiguration(ECUC_EcuM_00181) END*/

#define ECUM_COMM_WAKEUP_NOTIFICATION                       STD_OFF
/*EcuM_FlexGeneral(ECUC_EcuM_00168) START*/

#define ECUM_GODOWN_USER_NUMBER                             (0)
/*ECUC_EcuM_00221*/
#define ECUM_MODEHANDLING_SUPPORT                           STD_ON
/*ECUC_EcuM_00171*/
#define ECUM_RESET_LOOP_DETECTION                           STD_OFF
/*ECUC_EcuM_00210*/
#define EcuM_SETPROGRAMMABLEINTERRUPTS_SUPPORT              STD_ON
/*ECUC_EcuM_00199*/
#define ECUM_ALARM_CLOCK_PRESENT                            STD_OFF
/*ECUC_EcuM_00200*/
#define ECUM_ALARM_WAKEUP_SOURCE                            32
#define ECUM_ALARM_WAKEUP_SOURCE_MASK                       0

#define ECUM_ALARM_CLOCK_GPTCHANNEL                         0

/*EcuM_FlexConfiguration(ECUC_EcuM_00167) START*/
#define ECUM_SETCLOCK_USER_NUMBER                           (0)

#define ECUM_ALARM_CLOCK_NUMBER                             (0)

#define ECUM_NORMAL_MCU_MODE                                McuConf_McuModeSettingConf_McuModeSettingConf_0


/*******************************************************************************
*   Global Data Declaration
*******************************************************************************/

#define ECUM_START_SEC_CONFIG_DATA_8
#include "MemMap.h"

extern CONST(uint8, ECUM_CONST) EcuM_ConfigConsistencyHash[ECUM_CONFIG_HASH_LEN];

extern CONST(EcuMAlarmIdType, ECUM_CONST) EcuM_UserAlarm[ECUM_USER_NUMBER];
#define ECUM_STOP_SEC_CONFIG_DATA_8
#include "MemMap.h"

#define ECUM_START_SEC_CONFIG_DATA_32
#include "MemMap.h"

extern CONST(EcuM_WakeupSourceType, ECUM_CONST) EcuM_CoreWakeupSourceMask[ECUM_CORE_NUMBER];
#define ECUM_STOP_SEC_CONFIG_DATA_32
#include "MemMap.h"

#define ECUM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"

extern CONST(EcuM_CoreShutdownInfoType, ECUM_CONST) EcuM_CoreShutdownInfo[ECUM_CORE_NUMBER];
extern CONST(EcuM_ConfigType, ECUM_CONST) EcuM_PostBuildConfig;

extern CONST(EcuM_WakeupSourceConfigType, ECUM_CONST) EcuM_WkSrcConfigTable[ECUM_WKSOURCE_NUMBER];

#define ECUM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"



/*******************************************************************************
*    Access macro
*******************************************************************************/


/*User Handle*/
#define EcuM_USERID_User0                                   0

#endif /* ECUM_CFG_H */

