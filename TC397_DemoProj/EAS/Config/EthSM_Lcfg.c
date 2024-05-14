/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : EthSM_Lcfg.c
********************************************************************************
*   Project/Product : AUTOSAR BSW PROJECT
*   Title           : EthSM module configuration File
*   Author          : Hirain
********************************************************************************
*   Description     : EthSM module configuration File
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
#include "EthSM.h"


#include "ComM_Cfg.h"


#define ETHSM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"
CONST(EthSM_NetworkConfigType, ETHSM_CONST)  EthSM_NetworkConfig[ETHSM_MAX_NETWORK_NUM] =
{
    {
        ComM_ComM_EthCtrl,
        EthIf_EthIfController0
    }/*EthSM_EthCtrl_0*/
};
#define ETHSM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"


