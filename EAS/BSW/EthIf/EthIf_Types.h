/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE                              
*   This software is the property of HiRain Technologies. Any information 
*   contained in this doc should not be reproduced, or used, or disclosed 
*   without the written authorization from HiRain Technologies.
********************************************************************************
*   File Name       : EthIf_Types.h
********************************************************************************
*   Project/Product : AUTOSAR 4.2.2
*   Title           : Ethernet Interface module type definitions head File
*   Author          : Hirain
********************************************************************************
*   Description     : Ethernet Interface module type definitions head File
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
*   01.00.03    19/09/2022      zeyu.ren       N/A          change BufferId type
********************************************************************************
* END_FILE_HDR*/
#ifndef _ETHIF_TYPES_H_
#define _ETHIF_TYPES_H_

/*******************************************************************************
*   Includes
*******************************************************************************/
/*[SWS_EthIf_00152]*/
#include "Eth_GeneralTypes.h"
#include "EthTrcv_Types.h"
#include "EthIf_Cfg.h"

#if(ETHIF_WAKEUP_SUPPORT == STD_ON)
#include "EcuM_Generated_Types.h"
#endif

/*[SWS_EthIf_00150]*/
typedef enum {
    ETHCTRL_STATE_UNINIT = 0,
    ETHCTRL_STATE_INIT = 1
} EthIf_StateType;

typedef uint8 EthIf_TxBufOwnerType;

typedef struct{
    uint8 FreqCnt;
    uint8 CtrlIdx;
}EthIf_TrcvLinkCheckType;

typedef struct{
    Eth_ModeType CtrlMode;
    EthTrcv_ModeType TrcvMode;
    EthTrcv_LinkStateType LinkState;
}EthIf_CtrlType;    /*runtime status of a virtual controller*/

typedef P2FUNC(void, AUTOMATIC, EthIf_RxIndicationFctPtr)(
                                    uint8 CtrlIdx,
                                    Eth_FrameType FrameType,
                                    boolean IsBroadcast,
                                    const uint8* PhysAddrPtr,
                                    uint8* DataPtr,
                                    uint16 LenByte);

typedef P2FUNC(void, AUTOMATIC, EthIf_TxConfirmationFctPtr)(
                                    uint8 CtrlIdx,
                                    uint8 BufIdx);

typedef P2FUNC(void, AUTOMATIC, EthIf_TrcvLinkStateChgFctPtr)(
                                    uint8 CtrlIdx,
                                    EthTrcv_LinkStateType TrcvLinkState);
typedef P2FUNC(Std_ReturnType, TYPEDEF, EthIf_EthSetControllerModeType)(uint8 CtrlIdx, Eth_ModeType CtrlMode);

typedef P2FUNC(Std_ReturnType, TYPEDEF, EthIf_EthGetControllerModeType)(uint8 CtrlIdx, P2VAR(Eth_ModeType, AUTOMATIC, ETHIF_APPL_DATA) CtrlModePtr);

typedef P2FUNC(void, TYPEDEF, EthIf_EthGetPhysAddrType)(uint8 CtrlIdx, P2VAR(uint8, AUTOMATIC, ETHIF_APPL_DATA) PhysAddrPtr);

typedef P2FUNC(void, TYPEDEF, EthIf_EthSetPhysAddrType)(uint8 CtrlIdx, P2CONST(uint8, AUTOMATIC, ETHIF_APPL_DATA) PhysAddrPtr);

typedef P2FUNC(Std_ReturnType, TYPEDEF, EthIf_EthUpdatePhysAddrFilterType)(uint8 CtrlIdx,
    P2VAR(uint8, AUTOMATIC, ETHIF_APPL_DATA) PhysAddrPtr, Eth_FilterActionType Action );

//Modified by Yibo: Priority is added to adapt mcal version
typedef P2FUNC(BufReq_ReturnType, TYPEDEF, EthIf_EthProvideTxBufferType)(uint8 CtrlIdx, uint8 Priority,
    P2VAR(Eth_BufIdxType, AUTOMATIC, ETHIF_APPL_DATA) BufIdxPtr, uint8** BufPtr, P2VAR(uint16, AUTOMATIC, ETHIF_APPL_DATA) LenBytePtr);

typedef P2FUNC(Std_ReturnType, TYPEDEF, EthIf_EthTransmitType)(uint8 CtrlIdx, uint8 BufIdx, Eth_FrameType FramType, boolean TxConfirmation,
    uint16 LenByte, P2CONST(uint8, AUTOMATIC, ETHIF_APPL_DATA) PhysAddrPtr);

typedef P2FUNC(void, TYPEDEF, EthIf_EthReceiveType)(uint8 CtrlIdx, P2VAR(Eth_RxStatusType, AUTOMATIC, ETHIF_APPL_DATA) RxStatusPtr);

typedef P2FUNC(void, TYPEDEF, EthIf_EthTxConfirmationType)(uint8 CtrlIdx);

typedef P2FUNC(Std_ReturnType, TYPEDEF, EthIf_EthTrcvSetTransceiverModeType)(uint8 TrcvIdx, EthTrcv_ModeType CtrlMode);

typedef P2FUNC(Std_ReturnType, TYPEDEF, EthIf_EthTrcvGetTransceiverModeType)(uint8 TrcvIdx,
    P2VAR(EthTrcv_ModeType, AUTOMATIC, ETHIF_APPL_DATA) TrcvModePtr);

typedef P2FUNC(Std_ReturnType, TYPEDEF, EthIf_EthTrcvSetTrcvWakeupModeType)(uint8 TrcvIdx, EthTrcv_WakeupModeType TrcvWakeupMode);

typedef P2FUNC(Std_ReturnType, TYPEDEF, EthIf_EthTrcvGetTrcvWakeupModeType)(uint8 TrcvIdx,
    P2VAR(EthTrcv_WakeupModeType, AUTOMATIC, ETHIF_APPL_DATA) TrcvWakeupModePtr);

typedef P2FUNC(Std_ReturnType, TYPEDEF, EthIf_EthTrcvCheckWakeupType)(uint8 TrcvIdx);

typedef P2FUNC(Std_ReturnType, TYPEDEF, EthIf_EthTrcvGetLinkStateType)(uint8 TrcvIdx,
    P2VAR(EthTrcv_LinkStateType, AUTOMATIC, ETHIF_APPL_DATA)LinkStatePtr);

typedef P2FUNC(Std_ReturnType, TYPEDEF, EthIf_SetSwtPortModeType)(uint8 SwitchIdx, uint8 SwitchPortIdx, EthTrcv_ModeType PortMode);

typedef P2FUNC(Std_ReturnType, TYPEDEF, EthIf_GetSwtPortModeType)(uint8 SwitchIdx, uint8 SwitchPortIdx,
    P2VAR(EthTrcv_ModeType, AUTOMATIC, ETHIF_APPL_DATA) SwitchModePtr);

typedef P2FUNC(Std_ReturnType, TYPEDEF, EthIf_GetSwtLinkStateType)(uint8 SwitchIdx, uint8 SwitchPortIdx,
    P2VAR(EthTrcv_LinkStateType, AUTOMATIC, ETHIF_APPL_DATA) LinkStatePtr);

typedef P2FUNC(Std_ReturnType, TYPEDEF, EthIf_GetPortMacAddrType)(P2CONST(uint8, AUTOMATIC, ETHIF_APPL_DATA) MacAddrPtr,
    P2VAR(uint8, AUTOMATIC, ETHIF_APPL_DATA) SwitchIdxPtr, P2VAR(uint8, AUTOMATIC, ETHIF_APPL_DATA) PortIdxPtr);

typedef P2FUNC(Std_ReturnType, TYPEDEF, EthIf_GetBufferLevelType)(uint8 SwitchIdx,
    P2VAR(uint32, AUTOMATIC, ETHIF_APPL_DATA) SwitchBufferLevelPtr);

typedef P2FUNC(Std_ReturnType, TYPEDEF, EthIf_StoreConfigurationType)(uint8 SwitchIdx);

typedef P2FUNC(Std_ReturnType, TYPEDEF, EthIf_ResetConfigurationType)(uint8 SwitchIdx);

typedef struct{
    EthIf_EthSetControllerModeType SetCtrlMode;
    EthIf_EthGetControllerModeType GetCtrlMode;
    EthIf_EthGetPhysAddrType GetPhyAddr;
    EthIf_EthSetPhysAddrType SetPhyAddr;
    EthIf_EthUpdatePhysAddrFilterType UpdatePhyAddrFilter;
    EthIf_EthProvideTxBufferType ProvideTxBuffer;
    EthIf_EthTransmitType Transmit;
    EthIf_EthReceiveType Receive;
    EthIf_EthTxConfirmationType TxConfirmation;
}EthIf_CtrlApisType;

typedef struct{
    EthIf_EthTrcvSetTransceiverModeType SetTrcvMode;
    EthIf_EthTrcvGetTransceiverModeType GetTrcvMode;
    EthIf_EthTrcvGetLinkStateType GetLinkState;
#if(ETHIF_WAKEUP_SUPPORT == STD_ON)
    EthIf_EthTrcvSetTrcvWakeupModeType SetTrcvWakeupMode;
    EthIf_EthTrcvCheckWakeupType CheckWakeup;
#if(ETHIF_GET_TRANSCEIVER_WAKEUP_MODE_API == STD_ON)
    EthIf_EthTrcvGetTrcvWakeupModeType GetTrcvWakeupMode;
#endif
#endif
}EthIf_TrcvApisType;

typedef struct{
    EthIf_SetSwtPortModeType SetSwtPortMode;
    EthIf_GetSwtPortModeType GetSwtPortMode;
    EthIf_GetSwtLinkStateType GetSwtLinkState;
    EthIf_GetPortMacAddrType GetPortMacAddr;
    EthIf_GetBufferLevelType GetBufferLevel;
    EthIf_StoreConfigurationType StoreConfiguration;
    EthIf_ResetConfigurationType ResetConfiguration;
}EthIf_SwtApisType;

typedef struct{
    uint8 TrcvIdx; /*index in transceiver driver*/
    P2VAR(Eth_ModeType, AUTOMATIC, AUTOMATIC) HwStatePtr;/*active counter of HW*/
    P2CONST(EthIf_TrcvApisType, AUTOMATIC, AUTOMATIC) TrcvApis;
}EthIf_TrcvType;

typedef struct{
    EthTrcv_ModeType Mode;/*SwtPortMode*/
    EthTrcv_LinkStateType LinkState;/*SwtPortLinkState*/
}EthIf_PortStateType;

typedef struct{
    uint8 SwtIdx;
    uint8 PortIdx;
    P2VAR(uint8, AUTOMATIC, AUTOMATIC) HwStatePtr;/*active counter of HW*/
    P2VAR(EthTrcv_LinkStateType, AUTOMATIC, AUTOMATIC) StatePtr;/*Mode and LinkState in IF*/
}EthIf_SwtPortType;


typedef struct{
    uint8 PortNum;
    uint8 PortIdx;    /*index in EthIf_SwtPortType array*/
}EthIf_SwtPortGroupType;

typedef enum{
    ETHIF_NONE,
    ETHIF_TRCV,
    ETHIF_SWTPORT_GROUP
}EthIf_PhyType;

typedef struct {
    uint8 CtrlIdx;                 /*ECUC_EthIf_00027*/ /*CtrlIdx: index in EthDriver*/
    EthIf_PhyType PhyType;         /*ECUC_EthIf_00028*/
    uint8 PhyIdx;
    uint8 TxBufNum;              /*ECUC_EthIf_00002*/
    uint16 VlanId;                 /*ECUC_EthIf_00029*/
    uint16 CtrlMtu;                                             /*ECUC_EthIf_00032*/
    P2VAR(uint8, AUTOMATIC, AUTOMATIC) HwStatePtr;           /*active counter of HW*/
    P2VAR(EthIf_CtrlType, AUTOMATIC, AUTOMATIC) StatePtr;    /*CtrlMode,TrcvmMode,LinkState*/
    P2CONST(EthIf_CtrlApisType, AUTOMATIC, AUTOMATIC) EthApis;
}EthIf_ControllerType;

typedef struct{
    uint8 SwitchIdx;
    P2CONST(EthIf_SwtApisType, AUTOMATIC, AUTOMATIC) SwtApis;
}EthIf_SwitchType;

typedef struct {
    uint16 FrameType;                /*[ECUC_EthIf_00012]*/
    EthIf_TxBufOwnerType Owner;        /*[ECUC_EthIf_00013]*/
} EthIf_FrameOwnerType;

/*[SWS_EthIf_00149]*/
typedef struct {
    uint8 CtrlNum;
    uint8 SwtNum;
    uint8 TrcvNum;
    uint8 SwtPortNum;
    uint8 SwtPortGroupNum;
    uint8 FrameOwnerNum;
    uint8 RxTxCbkNum;
    uint8 TrcvLinkChgNum;
    P2CONST(EthIf_ControllerType, AUTOMATIC, AUTOMATIC) CtrlCfg;
    P2CONST(EthIf_SwitchType, AUTOMATIC, AUTOMATIC) SwtCfg;
    P2CONST(EthIf_TrcvType, AUTOMATIC, AUTOMATIC) TrcvCfg;
    P2CONST(EthIf_SwtPortType, AUTOMATIC, AUTOMATIC) SwtPortCfg;
    P2CONST(EthIf_SwtPortGroupType, AUTOMATIC, AUTOMATIC) SwtPortGroupCfg;
    P2CONST(EthIf_FrameOwnerType, AUTOMATIC, AUTOMATIC) FrameOwnerCfg;
    P2CONST(EthIf_RxIndicationFctPtr, AUTOMATIC, AUTOMATIC) RxIndCfg;
    P2CONST(EthIf_TxConfirmationFctPtr, AUTOMATIC, AUTOMATIC) TxConfCfg;
    P2CONST(EthIf_TrcvLinkStateChgFctPtr, AUTOMATIC, AUTOMATIC) TrcvLinkStateChgs;
}EthIf_ConfigType;

#if(ETHIF_WAKEUP_SUPPORT == STD_ON)
typedef struct
{
    EcuM_WakeupSourceType WakeupSource;
    uint8 EthTrcvId;
}EthIf_WakeupCfgType;
#endif

#endif/*_ETHIF_TYPES_H_*/

