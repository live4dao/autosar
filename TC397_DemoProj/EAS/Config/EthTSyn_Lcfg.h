/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : EthTSyn_Lcfg.h
********************************************************************************
*   Project/Product : AUTOSAR BSW PROJECT
*   Title           : EthTSyn module configuration File
*   Author          : Hirain
********************************************************************************
*   Description     : EthTSyn module configuration File
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
#ifndef ETHTSYN_LCFG_H
#define ETHTSYN_LCFG_H
/*******************************************************************************
*   Includes
*******************************************************************************/
#include "EthTSyn_Types.h"
/*******************************************************************************
*  Global Data Declaration
*******************************************************************************/
#define ETHTSYN_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "EthTSyn_MemMap.h"
extern CONST(EthTSyn_ConfigType, ETHTSYN_CONST) EthTSyn_Config;
extern VAR(uint8, ETHTSYN_APPL_CONST) EthTSyn_DestMacAddr_PTP[6];
extern VAR(uint8, ETHTSYN_APPL_CONST) EthTSyn_DestMacAddr_P2P[6];
#define ETHTSYN_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "EthTSyn_MemMap.h"
#endif
 /* ETHTSYN_LCFG_H */
