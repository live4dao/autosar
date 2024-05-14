/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : EcuM_Cfg.c
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


/*******************************************************************************
*   Includes
*******************************************************************************/
#include "EcuM.h"
#include "ComM_EcuMBswM.h"

/*******************************************************************************
*   Local Data Declaration
*******************************************************************************/
/* EcuM User */
#define ECUM_START_SEC_CONFIG_DATA_8
#include "MemMap.h"

CONST(EcuMAlarmIdType, ECUM_CONST) EcuM_UserAlarm[ECUM_USER_NUMBER] =
{
    ECUM_INVALID_ALARMID
};


#define ECUM_STOP_SEC_CONFIG_DATA_8
#include "MemMap.h"

/* EcuM CoreWakeupMask */
#define ECUM_START_SEC_CONFIG_DATA_32
#include "MemMap.h"

CONST(EcuM_WakeupSourceType, ECUM_CONST) EcuM_CoreWakeupSourceMask[ECUM_CORE_NUMBER] =
{
    (EcuM_WakeupSourceType)0,
    (EcuM_WakeupSourceType)0,
    (EcuM_WakeupSourceType)0,
    (EcuM_WakeupSourceType)0,
    (EcuM_WakeupSourceType)0,
    (EcuM_WakeupSourceType)0
};

#define ECUM_STOP_SEC_CONFIG_DATA_32
#include "MemMap.h"

#define ECUM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"

/* EcuM CoreShutdown */
CONST(EcuM_CoreShutdownInfoType, ECUM_CONST) EcuM_CoreShutdownInfo[ECUM_CORE_NUMBER] =
{
    {
        0,
        0,
        0
    },
    {
        0,
        0,
        0
    },
    {
        0,
        0,
        0
    },
    {
        0,
        0,
        0
    },
    {
        0,
        0,
        0
    },
    {
        0,
        0,
        0
    }
};
/* EcuM WkSrcConfigTable */
CONST(EcuM_WakeupSourceConfigType, ECUM_CONST) EcuM_WkSrcConfigTable[ECUM_WKSOURCE_NUMBER] =
{
    /*WkSource_Power*/
    {
        FALSE,
    },
    /*WkSource_Reset*/
    {
        FALSE,
    },
    /*WkSource_Internal_Reset*/
    {
        FALSE,
    },
    /*WkSource_Internal_Wdg*/
    {
        FALSE,
    },
    /*WkSource_External_Wdg*/
    {
        FALSE,
    }
};

/* EcuM SleepModeTable */
/* EcuM AlarmClockTable */

#define ECUM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"




