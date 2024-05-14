/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : EthIf_Lcfg.h
********************************************************************************
*   Project/Product : AUTOSAR BSW PROJECT
*   Title           : EthIf module configuration File
*   Author          : Hirain
********************************************************************************
*   Description     : EthIf module configuration File
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
#ifndef EthIF_LCFG_H
#define EthIF_LCFG_H
/*******************************************************************************
*   Includes
*******************************************************************************/
#include "EthIf_Types.h"
#include "EthIf_Cfg.h"


#define ETHIF_START_SEC_VAR_NOINIT_8
#include "MemMap.h"
extern VAR(EthIf_TxBufOwnerType, ETHIF_VAR_NOINIT) EthIf_TxBufOwner[1][4];
#define ETHIF_STOP_SEC_VAR_NOINIT_8
#include "MemMap.h"

#define ETHIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"

extern CONST(EthIf_ConfigType, ETHIF_CONST) EthIf_ConfigSet;
#define ETHIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"
#endif
