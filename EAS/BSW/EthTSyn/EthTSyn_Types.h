/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
*   File Name       : EthTSyn_Types.h
********************************************************************************
*   Project/Product : AUTOSAR 4.2
*   Title           : EthTSyn module type definitions Header File
*   Author          : Hirain
********************************************************************************
*   Description     : The header file EthTSyn_Types.h contains the  common type
*                     definitions of EthTSyn module
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

#ifndef ETHTSYN_TYPE_H
#define ETHTSYN_TYPE_H

/*PRQA S 778,779,3432,4641 EOF*/
/*******************************************************************************
*   Includes
*******************************************************************************/
#include "ComStack_Types.h"
#include "Eth_GeneralTypes.h"
#include "EthTSyn_Cfg.h"
#include "StbM_Types.h"
#include "EthTrcv_Types.h" //modified by Yibo: ret is added to adapt mcal version
/*******************************************************************************
*   Macro define
*******************************************************************************/

#define ETHTSYN_PTP_HEADER_SRCPORTIDENTITY_SIZE                           ((uint8)10)
#define ETHTSYN_COEERCTIONFIELD_FRACTION_SIZE                             ((uint8)2)

/*******************************************************************************
*   Typedef AutoSar standard EthTSyn_Type
*******************************************************************************/

/*SWS_EthTSyn_00034*/
typedef enum
{
    ETHTSYN_SYNC,             /* Ethernet time synchronous */
    ETHTSYN_UNSYNC,           /* Ethernet not time synchronous */
    ETHTSYN_UNCERTAIN,        /* Ethernet Sync state uncertain */
    ETHTSYN_NEVERSYNC         /* No Sync message received between EthTSyn_Init() and current requested state */
}EthTSyn_SyncStateType;

/*SWS_EthTSyn_00033*/
typedef enum
{
    ETHTSYN_TX_OFF,      /*Transmission Disabled*/
    ETHTSYN_TX_ON        /*Transmission Enabled*/
}EthTSyn_TransmissionModeType;

typedef enum
{
	ETHTSYN_STATE_INIT,
	ETHTSYN_STATE_UNINIT
}EthTSyn_InitStateType;

typedef enum
{
    ETHTSYN_SYNC_STATE_INIT,
    ETHTSYN_SYNC_STATE_MASTER_SENDING_SYNC,
    ETHTSYN_SYNC_STATE_MASTER_SENDING_FOLLOW_UP,
    ETHTSYN_SYNC_STATE_SLAVE_WAITING_SYNC,
    ETHTSYN_SYNC_STATE_SLAVE_WAITING_FOLLOW_UP,
    ETHTSYN_SYNC_STATE_SLAVE_UPDATING,
    ETHTSYN_SYNC_STATE_MASTER_RETRANSMISSION_SYNC,
    ETHTSYN_SYNC_STATE_MASTER_CURRENT_CYCLE_SENDINF_SUCCESSFULLY
}EthTSyn_CtrlSyncStateType;

/*  Pdelay Tx state type */
typedef enum
{
    ETHTSYN_PDELAY_STATE_INIT,
    ETHTSYN_PDELAY_STATE_MASTER_SENDING_PDELAYRESP,
    ETHTSYN_PDELAY_STATE_MASTER_SENDING_PDELAYRESPFUP,
    ETHTSYN_PDELAY_STATE_MASTER_WAITING_PDELAYREQ,
    ETHTSYN_PDELAY_STATE_SLAVE_SENDING_PDELAYREQ,    
    ETHTSYN_PDELAY_STATE_SLAVE_WAITING_PDELAYRESP,
    ETHTSYN_PDELAY_STATE_SLAVE_WAITING_PDELAYRESPFUP,
    ETHTSYN_PDELAY_STATE_SLAVE_MEASUREING_DELAY,
    ETHTSYN_PDELAY_STATE_SLAVE_RETRANSMISSION_PDELAYREQ
}EthTSyn_CtrlPdelayStateType;

typedef struct
{
    uint16 MsgLength;
    uint16 Flags;
    uint16 SequID;
    uint8 MsgType;
    uint8 Control;
    uint8 LogMsgInterval;
}EthTSyn_PTPHeaderType;

#if(STD_ON == ETHTSYN_PORT_MASTER_SUPPORT)
typedef struct
{
	uint8 EthTSynCtrlIdx;
    EthTSyn_CtrlSyncStateType ControllerSyncState;
    EthTSyn_CtrlPdelayStateType ControllerPdelayState;
    StbM_SynchronizedTimeBaseType TimeBaseId;
#if(ETHTSYN_HW_TIMESTAMP_SUPPORT == STD_ON)
    Eth_TimeStampType Sync_EgressTimeStamp_TS;
    Eth_TimeStampType IngressTimeStampPdelay_t2;
    Eth_TimeStampType EgressTimeStampPdelay_t3;
#else
    StbM_TimeStampType Sync_EgressTimeStamp_TS;
    StbM_TimeStampType IngressTimeStampPdelay_t2;
    StbM_TimeStampType EgressTimeStampPdelay_t3;
#endif
    Eth_BufIdxType TxSyncBufIdx;
    Eth_BufIdxType TxFollowUpBufIdx;
    uint16 PortNumber;
    uint16 TxSyncSequId;
    uint16 TxFollowUpOffsetCounter;
#if(STD_ON == ETHTSYN_PORT_SLAVE_SUPPORT)
    uint64 CorrectionField_Integer;
#endif
    EthTSyn_TransmissionModeType TxMode; 
    EthTrcv_LinkStateType LinkState;
    Eth_BufIdxType TxPdelayRespBufIdx;
    Eth_BufIdxType TxPdelayRespFUpBufIdx;
    uint16 TxPdelayRespFUpOffsetCounter;
    uint8 PdelayReqRxSrcPortId[ETHTSYN_PTP_HEADER_SRCPORTIDENTITY_SIZE];
    uint16 Ingress_PdelayReqSequId;
}EthTSyn_MasterControllerType;

typedef struct
{
    float32 SyncTxInterval;
    StbM_SynchronizedTimeBaseType TimeBaseId;
    uint16 PortNumber;
    uint8 SyncTxMsgLogInterval;
} EthTSyn_MasterControllerConfigType;
#endif

#if(STD_ON == ETHTSYN_PORT_SLAVE_SUPPORT)
typedef struct
{
	uint8 EthTSynCtrlIdx;
    EthTSyn_CtrlSyncStateType ControllerSyncState;
    EthTSyn_CtrlPdelayStateType ControllerPdelayState;
    StbM_SynchronizedTimeBaseType TimeBaseId;
#if(ETHTSYN_HW_TIMESTAMP_SUPPORT == STD_ON)
    Eth_TimeStampType Sync_IngressTimeStamp_TR;
    Eth_TimeStampType Sync_OriginTimeStamp;
    Eth_TimeStampType TimeStampInFirstSync;
    Eth_TimeStampType Diff_TimeStamp_t4_t1;
    Eth_TimeStampType Pdelay_IngressTimeStamp_t4;
    Eth_TimeStampType Pdelay_EgressTimeStamp_t1;
    Eth_TimeStampType Pdelay_IngressTimeStamp_t2;
    Eth_TimeStampType Pdelay_EgressTimeStamp_t3;
#else
    StbM_TimeStampType Sync_IngressTimeStamp_TR;
    StbM_TimeStampType Sync_OriginTimeStamp;
    StbM_TimeStampType TimeStampInFirstSync;
    StbM_TimeStampType Diff_TimeStamp_t4_t1;
    StbM_TimeStampType Pdelay_IngressTimeStamp_t4;
    StbM_TimeStampType Pdelay_EgressTimeStamp_t1;
    StbM_TimeStampType Pdelay_IngressTimeStamp_t2;
    StbM_TimeStampType Pdelay_EgressTimeStamp_t3;
#endif
    EthTSyn_SyncStateType EcuSyncState;
    uint64 CorrectionField_Integer;
    boolean CurrentSyncReceived;
    uint8 CorrectionField_Fraction[ETHTSYN_COEERCTIONFIELD_FRACTION_SIZE];
    uint8 RxSyncSourcePortId[ETHTSYN_PTP_HEADER_SRCPORTIDENTITY_SIZE];
    uint8 RxPdelayRespSourcePortId[ETHTSYN_PTP_HEADER_SRCPORTIDENTITY_SIZE];
    uint16 PortNumber;
    uint16 Ingress_SyncSequId;
    EthTSyn_TransmissionModeType TxMode; 
    EthTrcv_LinkStateType LinkState;
    boolean AccomplishMeasuringDelay;
    Eth_BufIdxType TxPdelayReqBufIdx;
    uint16 TxPdelayReqSequId;
    uint32 NeighborMeanPropDelay;
    uint32 DefaultLinkDelay;
}EthTSyn_SlaveControllerType;

typedef struct
{
    float32 PdelayReqTxInterval;
    uint32 DefaultLinkDelay;
    StbM_SynchronizedTimeBaseType TimeBaseId;
    uint16 PortNumber;
    uint8 PdelayReqTxMsgLogInterval;
} EthTSyn_SlaveControllerConfigType;
#endif

typedef struct
{
    CONST(uint8, ETHTSYN_APPL_CONST) EthTSyn_MessagePriority;
    CONST(uint8, ETHTSYN_CONST) EthTSynMappedToEthIfIdxArray[2][2];
#if(STD_ON == ETHTSYN_PORT_SLAVE_SUPPORT)
    P2VAR(EthTSyn_SlaveControllerConfigType, AUTOMATIC, ETHTSYN_APPL_CONST) EthTSyn_SlaveCtrlConfigPtr;
#endif
#if(STD_ON == ETHTSYN_PORT_MASTER_SUPPORT)
    P2VAR(EthTSyn_MasterControllerConfigType, AUTOMATIC, ETHTSYN_APPL_CONST) EthTSyn_MasterCtrlConfigPtr;
#endif
} EthTSyn_ConfigType;
#endif /*ETHTSYN_TYPE_H*/
