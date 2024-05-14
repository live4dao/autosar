/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : CanTSyn_Lcfg.c
********************************************************************************
*   Project/Product : AUTOSAR BSW PROJECT
*   Title           : CanTSyn module configuration File
*   Author          : Hirain
********************************************************************************
*   Description     : CanTSyn module configuration File
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
*   V1.0.2_3.5.5_AZ240046       09/05/2024    Eas           N/A          N/A
*
********************************************************************************
* END_FILE_HDR*/


/*******************************************************************************
*   Includes
*******************************************************************************/
#include "CanTSyn_Lcfg.h"
#define CANTSYN_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"

STATIC CONST(CanTSyn_MasterTimerDomainType, CANTSYN_CONST) CanTSyn_SYNCMasterCfg[1] =
{
    {
        0,/*PduRef*/
        (StbM_SynchronizedTimeBaseType)0,/*timeBaseId*/
        0,/*DomainId*/
        CanIf_CanConfigSet_Tx_Radar_ADCU_SYNC_FUP,/*PduId*/
        4,/*TxTimeOut*/
        4,/*DebounceTime*/
        4,/*TxOffset*/
        200,/*TxPeriod*/
        CRC_NOT_SUPPORTED,/*CrcMode*/
        1,/*ControllerId*/
    }
};
CONST(CanTSyn_ConfigType, CANTSYN_CONST) CanTSyn_Config =
{
    CanTSyn_SYNCMasterCfg,//SYNCMaster_Cfg
};
#define CANTSYN_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"


#define CANTSYN_START_SEC_CONFIG_DATA_8
#include "MemMap.h"

CONST(uint8, CANTSYN_CONST) CanTSyn_SYNCDataList[16] =
{
    (uint8)10,
    (uint8)10,
    (uint8)10,
    (uint8)10,
    (uint8)10,
    (uint8)10,
    (uint8)10,
    (uint8)10,
    (uint8)10,
    (uint8)10,
    (uint8)10,
    (uint8)10,
    (uint8)10,
    (uint8)10,
    (uint8)10,
    (uint8)10
};
CONST(uint8, CANTSYN_CONST) CanTSyn_FUPDataList[16] =
{
    (uint8)10,
    (uint8)10,
    (uint8)10,
    (uint8)10,
    (uint8)10,
    (uint8)10,
    (uint8)10,
    (uint8)10,
    (uint8)10,
    (uint8)10,
    (uint8)10,
    (uint8)10,
    (uint8)10,
    (uint8)10,
    (uint8)10,
    (uint8)10
};
CONST(uint8, CANTSYN_CONST) CanTSyn_OFNSDataList[16] =
{
    (uint8)10,
    (uint8)10,
    (uint8)10,
    (uint8)10,
    (uint8)10,
    (uint8)10,
    (uint8)10,
    (uint8)10,
    (uint8)10,
    (uint8)10,
    (uint8)10,
    (uint8)10,
    (uint8)10,
    (uint8)10,
    (uint8)10,
    (uint8)10
};
CONST(uint8, CANTSYN_CONST) CanTSyn_OFSDataList[16] =
{
    (uint8)10,
    (uint8)10,
    (uint8)10,
    (uint8)10,
    (uint8)10,
    (uint8)10,
    (uint8)10,
    (uint8)10,
    (uint8)10,
    (uint8)10,
    (uint8)10,
    (uint8)10,
    (uint8)10,
    (uint8)10,
    (uint8)10,
    (uint8)10
};
#define CANTSYN_STOP_SEC_CONFIG_DATA_8
#include "MemMap.h"
