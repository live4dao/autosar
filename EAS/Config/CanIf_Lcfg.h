/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : CanIf_Lcfg.h
********************************************************************************
*   Project/Product : AUTOSAR BSW PROJECT
*   Title           : CanIf module configuration File
*   Author          : Hirain
********************************************************************************
*   Description     : CanIf module configuration File
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
#ifndef CANIF_LCFG_H
#define CANIF_LCFG_H
/*******************************************************************************
*   Includes
*******************************************************************************/
#include "CanIf_Types.h"
#include "PduR_CanIf.h"
#include "CanTp_Cbk.h"
#include "CanNm_Cbk.h"
#include "CanSM_Cbk.h"

/*******************************************************************************
*   Global Vars
*******************************************************************************/
#define CANIF_START_SEC_VAR_NOINIT_8
#include "MemMap.h"
extern VAR(CanIf_ControllerModeType, CANIF_VAR_NOINIT) CanIf_ControllerMode[2];
extern VAR(CanIf_PduModeType, CANIF_VAR_NOINIT) CanIf_PduMode[2];
extern VAR(boolean, CANIF_VAR_NOINIT) CanIf_TxBufActiveFlag[14];
extern VAR(uint8, CANIF_VAR_NOINIT) CanIf_TxDataBuf[14][8];
#define CANIF_STOP_SEC_VAR_NOINIT_8
#include "MemMap.h"

#define CANIF_START_SEC_VAR_NOINIT_8
#include "MemMap.h"
extern VAR(PduIdType, CANIF_VAR_NOINIT) CanIf_TxBufferFillCount[33];
#define CANIF_STOP_SEC_VAR_NOINIT_8
#include "MemMap.h"

#define CANIF_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"
extern VAR(Can_PduType, CANIF_VAR_NOINIT) CanIf_TxBufPdu[14];
#define CANIF_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"


/*******************************************************************************
*   Config Parameters
*******************************************************************************/
#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"
extern CONST(CanIf_CanWriteType, CANIF_CONST)                CanIf_Can_Write[1];
extern CONST(CanIf_CanSetControllerModeType, CANIF_CONST)    CanIf_Can_SetControllerMode[1];
extern CONST(CanIf_User_TxConfirmationType, CANIF_CONST)           CanIf_TxConfirmationName[4];
extern CONST(CanIf_User_RxIndicationType, CANIF_CONST)             CanIf_RxIndicationName[3];
extern CONST(CanIf_CtrlCfgType, CANIF_CONST)           CanIf_CtrlCfg[2];
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"
extern CONST(CanIf_HthCfgType, CANIF_CONST) CanIf_HthCfg[33];
extern CONST(CanIf_TxPduCfgType, CANIF_CONST) CanIf_TxPduCfg[40];
extern CONST(CanIf_HrhCfgType, CANIF_CONST) CanIf_HrhCfg[51];
extern CONST(CanIf_RxPduCfgType, CANIF_CONST) CanIf_RxPduCfg[51];
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"

/*******************************************************************************
*   Access macro
*******************************************************************************/

#define CANIF_TXPDU_CFG_INFO                                CanIf_TxPduCfg
#define CANIF_RXPDU_CFG_INFO                                CanIf_RxPduCfg
#define CANIF_HTH_CFG_INFO                                  CanIf_HthCfg
#define CANIF_HRH_CFG_INFO                                  CanIf_HrhCfg
#endif
