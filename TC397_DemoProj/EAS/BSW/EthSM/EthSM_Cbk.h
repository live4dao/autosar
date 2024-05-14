/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE                              
*   This software is the property of HiRain Technologies. Any information 
*   contained in this doc should not be reproduced, or used, or disclosed 
*   without the written authorization from HiRain Technologies.
********************************************************************************
*   File Name       : EthSM_Cbk.h
********************************************************************************
*   Project/Product : AUTOSAR 4.2.2
*   Title           : Ethernet State Manager  
*   Author          : Hirain
********************************************************************************
*   Description     : EthSM module callback File                    
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
#ifndef _ETHSM_CBK_H_
#define _ETHSM_CBK_H_
/*******************************************************************************
*   Includes
*******************************************************************************/
#include "EthSM_Types.h"
/*******************************************************************************
*   Local Functions declare
*******************************************************************************/
#define ETHSM_START_SEC_CODE
#include "MemMap.h"

/*SWS_EthSM_00190*/
extern FUNC(void, ETHSM_CODE) EthSM_CtrlModeIndication
(
	uint8 CtrlIdx, 
	Eth_ModeType CtrlMode
);
/*SWS_EthSM_00193*/
extern FUNC(void, ETHSM_CODE) EthSM_TrcvModeIndication
(
	uint8 CtrlIdx, 
	EthTrcv_ModeType TrcvMode
);
/*SWS_EthSM_00109*/
extern FUNC(void, ETHSM_CODE) EthSM_TrcvLinkStateChg
(
	uint8 CtrlIdx, 
	EthTrcv_LinkStateType TransceiverLinkState
);

/*SWS_EthSM_00110*/
extern FUNC(Std_ReturnType, ETHSM_CODE) EthSM_TcpIpModeIndication
(
	uint8 CtrlIdx,
	TcpIp_StateType TcpIpState
);

#define ETHSM_STOP_SEC_CODE
#include "MemMap.h"

#endif

