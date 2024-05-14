/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : EcuM_PBcfg.c
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

/*******************************************************************************
*   Local Data Declaration
*******************************************************************************/
#define ECUM_START_SEC_CONFIG_DATA_8
#include "MemMap.h"

STATIC CONST(uint8, ECUM_CONST) EcuM_ConsistencyHash[ECUM_CONFIG_HASH_LEN] =
{
    (uint8)0x00
};

#define ECUM_STOP_SEC_CONFIG_DATA_8
#include "MemMap.h"


#define ECUM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"

STATIC CONST(EcuM_FlexModuleConfigType, ECUM_CONST) EcuM_ModuleConfig =
{
    NULL_PTR
};

CONST(EcuM_ConfigType, ECUM_CONST) EcuM_PostBuildConfig =
{
    0,
    ECUM_CONFIG_HASH_LEN,
    EcuM_ConsistencyHash,
    &EcuM_ModuleConfig,
    ECUM_SHUTDOWN_TARGET_OFF,
    0
};

#define ECUM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"



