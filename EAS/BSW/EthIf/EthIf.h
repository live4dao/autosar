/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE                              
*   This software is the property of HiRain Technologies. Any information 
*   contained in this doc should not be reproduced, or used, or disclosed 
*   without the written authorization from HiRain Technologies.
********************************************************************************
*   File Name       : EthIf.h
********************************************************************************
*   Project/Product : AUTOSAR 4.2.2
*   Title           : Ethernet Interface module head File
*   Author          : Hirain
********************************************************************************
*   Description     : Ethernet Interface module head File
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
#ifndef _ETHIF_H_
#define _ETHIF_H_

/*******************************************************************************
*   Includes
*******************************************************************************/ 
#include "EthIf_Cbk.h"
#include "EthIf_Version.h"
#include "EthIf_Types.h"
#include "EthIf_Cfg.h"
#include "EthIf_Lcfg.h"
#include "EthIf_PBcfg.h"

/*[SWS_EthIf_00017]*/
#define ETHIF_E_INV_CTRL_IDX                     ((uint8)0x01)
#define ETHIF_E_INV_TRCV_IDX                     ((uint8)0x02)
#define ETHIF_E_NOT_INITIALIZED                  ((uint8)0x03)
#define ETHIF_E_PARAM_POINTER                    ((uint8)0x04)
#define ETHIF_E_INV_PARAM                        ((uint8)0x05)
#define ETHIF_E_INIT_FAILED                      ((uint8)0x06)

#define ETHIF_API_ID_INIT                        ((uint8)0x01)
#define ETHIF_API_ID_CONTROLLERINIT              ((uint8)0x02)
#define ETHIF_API_ID_SETCONTROLLERMODE           ((uint8)0x03)
#define ETHIF_API_ID_GETCONTROLLERMODE           ((uint8)0x04)
#define ETHIF_API_ID_TRANSCEIVERINIT             ((uint8)0x05)
#define ETHIF_API_ID_SETTRANSCEIVERMODE          ((uint8)0x06)
#define ETHIF_API_ID_GETTRANSCEIVERMODE          ((uint8)0x07)
#define ETHIF_API_ID_GETPHYSADDR                 ((uint8)0x08)
#define ETHIF_API_ID_PROVIDETXBUFFER             ((uint8)0x09)
#define ETHIF_API_ID_TRANSMIT                    ((uint8)0x0A)
#define ETHIF_API_ID_GETVERSIONINFO              ((uint8)0x0B)
#define ETHIF_API_ID_UPDATEPHYSADDRFILTER        ((uint8)0x0C)
#define ETHIF_API_ID_SETPHYSADDR                 ((uint8)0x0D)
#define ETHIF_API_ID_CTRLMODEINDICATION          ((uint8)0x0E)
#define ETHIF_API_ID_TRCVMODEINDICATION          ((uint8)0x0F)
#define ETHIF_API_ID_RXINDICATION                ((uint8)0x10)
#define ETHIF_API_ID_TXCONFIRMATION              ((uint8)0x11)
#define ETHIF_API_ID_MAINFUNCTIONRX              ((uint8)0x20)
#define ETHIF_API_ID_MAINFUNCTIONTX              ((uint8)0x21)
#define ETHIF_API_ID_SETTRANSCEIVERWAKEUPMODE    ((uint8)0x2E)
#define ETHIF_API_ID_GETTRANSCEIVERWAKEUPMODE    ((uint8)0x2F)
#define ETHIF_API_ID_CHECKWAKEUP                 ((uint8)0x30)
#define ETHIF_API_ID_GETPORTMACADDR                 ((uint8)0x31)
#define ETHIF_API_ID_GETBUFFERLEVEL                 ((uint8)0x32)
#define ETHIF_API_ID_STORECONFIGURATION             ((uint8)0x33)
#define ETHIF_API_ID_RESETCONFIGURATION             ((uint8)0x34)

/*******************************************************************************
* Functions
*******************************************************************************/
#define ETHIF_START_SEC_CODE
#include "MemMap.h"
/*[SWS_EthIf_00024]*/
extern FUNC(void, ETHIF_CODE) EthIf_Init
(
    P2CONST(EthIf_ConfigType, AUTOMATIC, ETHIF_APPL_DATA) CfgPtr
);

/*[SWS_EthIf_00034]*/
extern FUNC(Std_ReturnType, ETHIF_CODE) EthIf_SetControllerMode
(
    uint8 CtrlIdx,
    Eth_ModeType CtrlMode
);

/*[SWS_EthIf_00039]*/
extern FUNC(Std_ReturnType, ETHIF_CODE) EthIf_GetControllerMode
(
    uint8 CtrlIdx,
    P2VAR(Eth_ModeType, AUTOMATIC, ETHIF_APPL_DATA) CtrlModePtr
);

/*[SWS_EthIf_00050]*/
extern FUNC(Std_ReturnType, ETHIF_CODE) EthIf_SetTransceiverMode
(
    uint8 CtrlIdx,
    EthTrcv_ModeType TrcvMode
);

/*[SWS_EthIf_00055]*/
extern FUNC(Std_ReturnType, ETHIF_CODE) EthIf_GetTransceiverMode
(
    uint8 CtrlIdx,
    P2VAR(EthTrcv_ModeType, AUTOMATIC, ETHIF_APPL_DATA) TrcvModePtr
);


/*[SWS_EthIf_00233]*/
#if(ETHIF_WAKEUP_SUPPORT == STD_ON)
extern FUNC(Std_ReturnType, ETHIF_CODE) EthIf_SetTransceiverWakeupMode
(
    uint8  TrcvIdx,
    EthTrcv_WakeupModeType  TrcvWakeupMode
);

#if(ETHIF_GET_TRANSCEIVER_WAKEUP_MODE_API == STD_ON)
/*[SWS_EthIf_00238]*/
extern FUNC(Std_ReturnType, ETHIF_CODE) EthIf_GetTransceiverWakeupMode
(
    uint8  TrcvIdx,
    P2VAR(EthTrcv_WakeupModeType, AUTOMATIC, ETHIF_APPL_DATA) TrcvWakeupModePtr
);
#endif

/*[SWS_EthIf_00244]*/
extern FUNC(Std_ReturnType, ETHIF_CODE) EthIf_CheckWakeup
(
    EcuM_WakeupSourceType  WakeupSource
);
#endif

/*[SWS_EthIf_00061]*/
extern FUNC(void, ETHIF_CODE) EthIf_GetPhysAddr
(
    uint8 CtrlIdx,
    P2VAR(uint8, AUTOMATIC, ETHIF_APPL_DATA) PhysAddrPtr
);

/*[SWS_EthIf_00132]*/
extern FUNC(void, ETHIF_CODE) EthIf_SetPhysAddr
(
    uint8 CtrlIdx,
    P2CONST(uint8, AUTOMATIC, ETHIF_APPL_DATA) PhysAddrPtr
);

/*[SWS_EthIf_00139]*/
extern FUNC(Std_ReturnType, ETHIF_CODE) EthIf_UpdatePhysAddrFilter
(
    uint8 CtrlIdx,
    P2VAR(uint8, AUTOMATIC, ETHIF_APPL_DATA) PhysAddrPtr,
    Eth_FilterActionType Action
);

#if(ETHIF_SWITCH_SUPPORT == STD_ON)
/*[SWS_EthIf_00190]*/
extern FUNC(Std_ReturnType, ETHIF_CODE) EthIf_GetPortMacAddr
(
    P2CONST(uint8, AUTOMATIC, ETHIF_APPL_DATA) MacAddrPtr,
    P2VAR(uint8, AUTOMATIC, ETHIF_APPL_DATA) SwitchIdxPtr,
    P2VAR(uint8, AUTOMATIC, ETHIF_APPL_DATA) PortIdxPtr
);

/*[SWS_EthIf_00202]*/
extern FUNC(Std_ReturnType, ETHIF_CODE) EthIf_GetBufferLevel
(
    uint8 SwitchIdx,
    P2VAR(uint32, AUTOMATIC, ETHIF_APPL_DATA) SwitchBufferLevelPtr
);

/*[SWS_EthIf_00214]*/
extern FUNC(Std_ReturnType, ETHIF_CODE) EthIf_StoreConfiguration
(
    uint8 SwitchIdx
);

/*[SWS_EthIf_00219]*/
extern FUNC(Std_ReturnType, ETHIF_CODE) EthIf_ResetConfiguration
(
    uint8 SwitchIdx
);
#endif

/*[SWS_EthIf_00067]*/
extern FUNC(BufReq_ReturnType, ETHIF_CODE) EthIf_ProvideTxBuffer
(
    uint8 CtrlIdx,
    Eth_FrameType FrameType,
    uint8 Priority,
    P2VAR(Eth_BufIdxType, AUTOMATIC, ETHIF_APPL_DATA) BufIdxPtr,
    P2VAR(P2VAR(uint8, AUTOMATIC, AUTOMATIC), AUTOMATIC, ETHIF_APPL_DATA) BufPtr,
    P2VAR(uint16, AUTOMATIC, ETHIF_APPL_DATA) LenBytePtr
);

/*[SWS_EthIf_00075]*/
extern FUNC(Std_ReturnType, ETHIF_CODE) EthIf_Transmit
(
    uint8 CtrlIdx,
    uint8 BufIdx,
    Eth_FrameType FrameType,
    boolean TxConfirmation,
    uint16 LenByte,
    P2CONST(uint8, AUTOMATIC, ETHIF_APPL_DATA) PhysAddrPtr
);

#if ((ETHIF_VERSIONINFO_API_MACRO == STD_ON) && (ETHIF_VERSION_INFO_API == STD_ON))
/*[SWS_EthIf_00082]*/
extern FUNC(void, ETHIF_CODE) EthIf_GetVersionInfo
(
    P2VAR(Std_VersionInfoType, AUTOMATIC, ETHIF_APPL_DATA) VersionInfoPtr
);
#endif

/*[SWS_EthIf_00097]*/
extern FUNC(void, ETHIF_CODE) EthIf_MainFunctionRx
(
    void
);

/*[SWS_EthIf_00113]*/
extern FUNC(void, ETHIF_CODE) EthIf_MainFunctionTx
(
    void
);
#define ETHIF_STOP_SEC_CODE
#include "MemMap.h"

#endif/*_ETHIF_H_*/

