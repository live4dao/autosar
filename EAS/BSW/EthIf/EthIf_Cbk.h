/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE                              
*   This software is the property of HiRain Technologies. Any information 
*   contained in this doc should not be reproduced, or used, or disclosed 
*   without the written authorization from HiRain Technologies.
********************************************************************************
*   File Name       : EthIf_Cbk.h
********************************************************************************
*   Project/Product : AUTOSAR 4.2.2
*   Title           : Ethernet Interface module call back head File
*   Author          : Hirain
********************************************************************************
*   Description     : Ethernet Interface module call back head File
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
*   01.00.00    10/10/2017    junfei.chen    N/A          Original
*   01.00.01    19/04/2018    xueyu.zhao     N/A          add VLAN and switch
*   01.00.02    17/07/2018    xueyu.zhao     N/A          after test and QAC
********************************************************************************
* END_FILE_HDR*/
#ifndef _ETHIF_CBK_H_
#define _ETHIF_CBK_H_

/*******************************************************************************
*   Includes
*******************************************************************************/
#include "EthIf_Types.h"


/*******************************************************************************
* Functions
*******************************************************************************/
#define ETHIF_START_SEC_CODE
#include "MemMap.h"

/*[SWS_EthIf_00085]*/
extern FUNC(void, ETHIF_CODE) EthIf_RxIndication
(
    uint8 CtrlIdx,
    Eth_FrameType FrameType,
    boolean IsBroadcast,
    P2CONST(uint8, AUTOMATIC, ETHIF_APPL_DATA) PhysAddrPtr,
    P2VAR(Eth_DataType, AUTOMATIC, ETHIF_APPL_DATA) DataPtr,
    uint16 LenByte
);

/*[SWS_EthIf_00091]*/
extern FUNC(void, ETHIF_CODE) EthIf_TxConfirmation
(
    uint8 CtrlIdx,
    uint8 BufIdx,
	Std_ReturnType ret //modified by Yibo: ret is added to adapt mcal version
);

/*[SWS_EthIf_00231]*/
extern FUNC(void, ETHIF_CODE) EthIf_CtrlModeIndication
(
    uint8  CtrlIdx,
    Eth_ModeType CtrlMode
);

/*[SWS_EthIf_00232]*/
extern FUNC(void, ETHIF_CODE) EthIf_TrcvModeIndication
(
    uint8  CtrlIdx,
    EthTrcv_ModeType TrcvMode
);

#define ETHIF_STOP_SEC_CODE
#include "MemMap.h"

#endif/*_ETHIF_CBK_H_*/

