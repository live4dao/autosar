/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
*   File Name       : EthTSyn_Cbk.h
********************************************************************************
*   Project/Product : AutoSar
*   Title           : EthTSyn module call back head File
*   Author          : Hirain
********************************************************************************
*   Description     : The header file EthTSyn_Cbk.h contains the declaration of
*                     callback functions which is called by the EthTSyn module
*
********************************************************************************
*   Limitations     : None
*
********************************************************************************
*
********************************************************************************
*   Revision History:
*   Reference to Core C File
********************************************************************************
* END_FILE_HDR*/
/*PRQA S 3432,4640,3614 EOF*/
#ifndef ETHTSYN_CBK_H
#define ETHTSYN_CBK_H

/*******************************************************************************
*   Includes
*******************************************************************************/
#include "EthTSyn_Types.h"

#define ETHTSYN_START_SEC_CODE
#include "EthTSyn_MemMap.h"

/*******************************************************************************
*  Global Function Declaration
*******************************************************************************/

extern FUNC(void, ETHTSYN_CODE) EthTSyn_RxIndication
(
    uint8 CtrlIdx,
    Eth_FrameType FrameType, 
    boolean IsBroadcast,
    P2CONST(uint8, AUTOMATIC, ETHTSYN_APPL_DATA) PhysAddrPtr, 
    P2VAR(uint8, AUTOMATIC, ETHTSYN_APPL_DATA) RxDataPtr, 
    uint16 PTPMsgLength
);

extern FUNC(void, ETHTSYN_CODE) EthTSyn_TxConfirmation
(
    uint8 CtrlIdx,
	Eth_BufIdxType BufIdx
);

extern FUNC(void, ETHTSYN_CODE) EthTSyn_TrcvLinkStateChg
(
    uint8 CtrlIdx,
    EthTrcv_LinkStateType LinkState
);
#define ETHTSYN_STOP_SEC_CODE
#include "EthTSyn_MemMap.h"
#endif /* ETHTSYN_CBK_H */
