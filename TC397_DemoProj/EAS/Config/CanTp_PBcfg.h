/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : CanTp_PBcfg.h
********************************************************************************
*   Project/Product : AUTOSAR BSW PROJECT
*   Title           : CanTp module configuration File
*   Author          : Hirain
********************************************************************************
*   Description     : CanTp module configuration File
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
#ifndef CANTP_PBCFG_H
#define CANTP_PBCFG_H

/*******************************************************************************
*   Includes
*******************************************************************************/
#include "CanTp_Types.h"

#define CANTP_START_SEC_CONFIG_DATA_8
#include "MemMap.h"
extern CONST(CanTp_ChannelModeType, CANTP_CONST) CanTp_ChannelModeInfo[CANTP_MAX_CHANNEL_NUM];
#define CANTP_STOP_SEC_CONFIG_DATA_8
#include "MemMap.h"
#define CANTP_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"
extern CONST(CanTp_RxNsduCfgType, CANTP_CONST) CanTp_RxNsduCfgInfo[CANTP_MAX_NUM_RX_SDUS];
extern CONST(CanTp_TxNsduCfgType, CANTP_CONST) CanTp_TxNsduCfgInfo[CANTP_MAX_NUM_TX_SDUS];
#define CANTP_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"


#endif /* CANTP_PBCFG_H */


