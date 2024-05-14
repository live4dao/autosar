/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : EthSM_Lcfg.h
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

#ifndef ETHSM_LCFG_H
#define ETHSM_LCFG_H
/*******************************************************************************
*   Includes
*******************************************************************************/
#include "EthSM_Types.h"


#define ETHSM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"

extern CONST(EthSM_NetworkConfigType, ETHSM_CONST)  EthSM_NetworkConfig[ETHSM_MAX_NETWORK_NUM];

#define ETHSM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"

#endif /* EthSM_LCFG_H */

