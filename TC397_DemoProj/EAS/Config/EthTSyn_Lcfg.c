/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : EthTSyn_Lcfg.c
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
/*******************************************************************************
*   Includes
*******************************************************************************/
/*PRQA S 862,2213,3211,3214,3120,3121,3132 EOF*/
/*PRQA S 0790 EOF*/
/*PRQA S 4640 ++*/
/*<errno.h> will not be used*/
#include "EthTSyn_Lcfg.h"
#define ETHTSYN_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "EthTSyn_MemMap.h"
/*  SWS_EthTSyn_00002 */
VAR(uint8, ETHTSYN_APPL_CONST) EthTSyn_DestMacAddr_P2P[6] = {(uint8)0x01, (uint8)0x1b, (uint8)0x19, (uint8)0x00, (uint8)0x00, (uint8)0x00};
VAR(uint8, ETHTSYN_APPL_CONST) EthTSyn_DestMacAddr_PTP[6] = {(uint8)0x01, (uint8)0x80, (uint8)0xC2, (uint8)0x00, (uint8)0x00, (uint8)0x0E};

STATIC VAR(EthTSyn_MasterControllerConfigType, ETHTSYN_CONST) EthTSyn_MasterControllerConfig =
{
    (float32)1.0,/*SyncTxInterval*/
    (StbM_SynchronizedTimeBaseType)0,/*TimeBaseId*/
    (uint16)1,/*PortNumber*/
    (uint8)0/*SyncTxMsgLogInterval*/
};

CONST(EthTSyn_ConfigType, ETHTSYN_CONST) EthTSyn_Config =
{
    (uint8)6,/*EthTSyn_MessagePriority*/
    {
    /*EthTSynCtrlIdx  EthIfCtrlIdx*/
        {(uint8)0, (uint8)0},
        {(uint8)1, (uint8)0}
    },
    &EthTSyn_MasterControllerConfig/*EthTSyn_MasterCtrlConfigPtr*/
};
#define ETHTSYN_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "EthTSyn_MemMap.h"
