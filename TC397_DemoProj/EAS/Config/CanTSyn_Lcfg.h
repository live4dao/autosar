/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : CanTSyn_Lcfg.h
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
*   V1.0.0_3.5.5_AZ240046       27/03/2024    Eas           N/A          N/A
*
********************************************************************************
* END_FILE_HDR*/
#ifndef CANSTYN_LCFG_H
#define CANSTYN_LCFG_H
/*******************************************************************************
*   Include files
*******************************************************************************/
#include "CanIf.h"
#include "CanTSyn_Types.h"

#define CANSTYN_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"

extern CONST(CanTSyn_ConfigType, CANTSYN_CONST) CanTSyn_Config;

#define CANSTYN_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"
#define CANTSYN_START_SEC_CONFIG_DATA_8
#include "MemMap.h"
extern CONST(uint8, CANTSYN_CONST) CanTSyn_SYNCDataList[16];
extern CONST(uint8, CANTSYN_CONST) CanTSyn_FUPDataList[16];
extern CONST(uint8, CANTSYN_CONST) CanTSyn_OFSDataList[16];
extern CONST(uint8, CANTSYN_CONST) CanTSyn_OFNSDataList[16];
extern CONST(uint8, CANTSYN_CONST)CanTSyn_SlaveDomainIdMap[32];
#define CANTSYN_STOP_SEC_CONFIG_DATA_8
#include "MemMap.h"

#endif/*CANSTYN_LCFG_H*/

