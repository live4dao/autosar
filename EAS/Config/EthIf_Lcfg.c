/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : EthIf_Lcfg.c
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

/*******************************************************************************
*   Includes
*******************************************************************************/
#include "EthIf_Lcfg.h"
#include "Eth.h"
#include "EthTrcv.h"
#include "TcpIp_Cbk.h"
#include "EthSM_Cbk.h"
#include "EthTSyn_Cbk.h"

#define ETHIF_START_SEC_VAR_NOINIT_8
#include "MemMap.h"

VAR(Eth_ModeType, ETHIF_VAR_NOINIT) EthIf_HardwareTrcvState[1];
VAR(uint8, ETHIF_VAR_NOINIT) EthIf_HardwareCtrlState[1];
VAR(EthIf_TxBufOwnerType, ETHIF_VAR_NOINIT) EthIf_TxBufOwner[1][4];

#define ETHIF_STOP_SEC_VAR_NOINIT_8
#include "MemMap.h"

#define ETHIF_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"

VAR(EthIf_CtrlType, ETHIF_VAR_NOINIT) EthIf_CtrlState[1];

#define ETHIF_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"

#define ETHIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"

CONST(EthIf_TrcvApisType, ETHIF_CONST)   EthIf_TrcvApis[1]=
{
    {
        &EthTrcv_SetTransceiverMode,
        &EthTrcv_GetTransceiverMode,
        &EthTrcv_GetLinkState,
    },
};
CONST(EthIf_TrcvType, ETHIF_CONST)   EthIf_Trcvs[1]=
{
    {
        0,//NULL_PTR, //modified by Yibo
        &EthIf_HardwareTrcvState[0],
        &EthIf_TrcvApis[0],
    },
};
CONST(EthIf_CtrlApisType, ETHIF_CONST) EthIf_CtrlApis[1] =
{
    {
        &Eth_SetControllerMode,
        &Eth_GetControllerMode,
        &Eth_GetPhysAddr,
        &Eth_SetPhysAddr,
        &Eth_UpdatePhysAddrFilter,
        &Eth_ProvideTxBuffer,
        &Eth_Transmit,
        &Eth_Receive,
        &Eth_TxConfirmation
    },
};
STATIC CONST(EthIf_ControllerType, ETHIF_CONST) EthIf_Controllers[1] =
{
    {
        0,
        ETHIF_NONE,
        0,
        4,
        0,
        1500,
        &EthIf_HardwareCtrlState[0],
        &EthIf_CtrlState[0],
        &EthIf_CtrlApis[0]
     },
};
STATIC CONST(EthIf_FrameOwnerType, ETHIF_CONST) EthIf_FrameOwnerConfig[3] =
{
    {
        0x800,0
    },
    {
        0x806,0
    },
    {
        0x88F7,1
    },
};
STATIC CONST(EthIf_RxIndicationFctPtr, ETHIF_CONST) EthIf_RxIndicationConfig[2] =
{
    TcpIp_RxIndication,
    EthTSyn_RxIndication,
};
STATIC CONST(EthIf_TxConfirmationFctPtr,ETHIF_CONST) EthIf_TxConfmationConfig[2] =
{
    NULL_PTR,
    EthTSyn_TxConfirmation,
};
STATIC CONST(EthIf_TrcvLinkStateChgFctPtr, ETHIF_CONST) EthIf_TrcvLinkStateChgConfig[2] =
{
    &EthSM_TrcvLinkStateChg,
    &EthTSyn_TrcvLinkStateChg,
};
CONST(EthIf_ConfigType, ETHIF_CONST) EthIf_ConfigSet=
{
    1,
    0,
    1,
    0,
    0,
    3,
    2,
    2,
    &EthIf_Controllers[0],
    NULL_PTR,
    &EthIf_Trcvs[0],
    NULL_PTR,
    NULL_PTR,
    &EthIf_FrameOwnerConfig[0],
    &EthIf_RxIndicationConfig[0],
    &EthIf_TxConfmationConfig[0],
    &EthIf_TrcvLinkStateChgConfig[0],
};
#define ETHIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"