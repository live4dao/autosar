/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : CanSM_Lcfg.c
********************************************************************************
*   Project/Product : AUTOSAR BSW PROJECT
*   Title           : CanSM module configuration File
*   Author          : Hirain
********************************************************************************
*   Description     : CanSM module configuration File
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

#include "CanSM.h"

#include "Dem.h"


#define CANSM_START_SEC_VAR_NOINIT_8
#include "MemMap.h"
VAR(uint8, CANSM_VAR)  CanSM_TriggerInfo[CANSM_MAX_NETWORK_NUM];
#define CANSM_STOP_SEC_VAR_NOINIT_8
#include "MemMap.h"


#define CANSM_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"
VAR(CanSM_NeworkInfoType, CANSM_VAR)  CanSM_NetworkInfo[CANSM_MAX_NETWORK_NUM];
#define CANSM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"
#define CANSM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"
CONST(CanSM_NetworkCfgType, CANSM_CONST)  CanSM_NetworkCfg[CANSM_MAX_NETWORK_NUM] =
{
    {
        ComM_ComM_CanCtrl_0,0,100,200,20,Dem_Event_0xD20288,
    },/*CanSM_CanCtrl_0*/
    {
        ComM_ComM_CanCtrl_1,0,100,200,20,Dem_Event_0xD20388,
    }/*CanSM_CanCtrl_1*/
};
#define CANSM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"


