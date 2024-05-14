/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
*   File Name       : SoAd_Types.h
********************************************************************************
*   Project/Product : AUTOSAR 4.2
*   Title           : The Socket Adaptor
*   Author          : mingqing.tang
********************************************************************************
*   Description     : The header file SoAd_Types.h contains the declaration of
*                     the SoAd module API, 'extern' declarations of constants,
*                     global data,type definitions and services that are
*                     specified in the SoAd module SWS.
*
********************************************************************************
*   Limitations     : only used for AUTOSAR 4.2 version
*
********************************************************************************
*
********************************************************************************
*   Revision History:
*
*   Version     Date          Initials        CR#          Descriptions
*   ---------   ----------    -------------   ----------   ---------------
*   01.00.00    21/09/2016    mingqing.tang   N/A          Original
*   02.00.00    01/09/2017    mingqing.tang   N/A          Update to R4.2.2
********************************************************************************
* END_FILE_HDR*/

#ifndef _SOAD_TYPES_H_
#define _SOAD_TYPES_H_

/*******************************************************************************
*   Includes
*******************************************************************************/
#include "SoAd_GeneratedTypes.h"
#include "TcpIp_Types.h"

/*******************************************************************************
*   Macro
*******************************************************************************/
#define SOAD_UL_TYPE_IF                             (0)
#define SOAD_UL_TYPE_TP                             (1)

#define SOAD_PDUHEADER_LENGTH                       (8)

#define SOAD_ROUTING_GROUP_ENABLED                  (1)
#define SOAD_ROUTING_GROUP_DISABLED                 (0)

#define SOAD_IFTRIGGER_REQUEST                      (1)

/* The request for socket connection*/
#define SOAD_SOCON_REQUEST_OPEN                     (1)
#define SOAD_SOCON_REQUEST_CLOSE                    (2)
#define SOAD_SOCON_REQUEST_CLOSE_EVENT              (4)   /*Used for events*/
#define SOAD_SOCON_REQUEST_CLOSE_ALL                (SOAD_SOCON_REQUEST_CLOSE | SOAD_SOCON_REQUEST_CLOSE_EVENT)

/* The state of session*/
#define SOAD_SESSION_STATE_IDLE                     (0)
#define SOAD_SESSION_STATE_IF                       (1)
#define SOAD_SESSION_STATE_TRIGGER                  (2)
#define SOAD_SESSION_STATE_TP                       (3)
#define SOAD_SESSION_STATE_TP_CANCELLED             (4)

/* Valid values used for CtrlFlag in the SoAd_SocketConnectionGroupType*/
#define SOAD_SOCONGRP_AUTOSETUP                     (0x01)
#define SOAD_SOCONGRP_PDUHEADER_ENABLED             (0x02)
#define SOAD_SOCONGRP_MAF_ENABLED                   (0x04)
#define SOAD_SOCONGRP_ADDR_ASSIGNMENT_CHG           (0x08)
#define SOAD_SOCONGRP_MODE_CHG                      (0x10)
#define SOAD_SOCONGRP_UDP                           (0x20)

/* Valid values used for CtrlFlag in the SoAd_TcpProtocolType*/
#define SOAD_SOCONGRP_TCP_IMMEDIATE_TPTXCONFIRM     (0x01)
#define SOAD_SOCONGRP_TCP_INITIATE                  (0x02)
#define SOAD_SOCONGRP_TCP_NO_DELAY                  (0x04)
#define SOAD_SOCONGRP_TCP_KEEP_ALIVE                (0x08)

/* Valid values used for CtrlFlag in the SoAd_UdpProtocolType*/
#define SOAD_SOCONGRP_UDP_LISTEN_ONLY               (0x01)
#define SOAD_SOCONGRP_UDP_CHECK_PDUHEADER_LEN       (0x02)

/* Valid values used for CtrlFlag in the SoAd_RoutingGroupType*/
#define SOAD_ROUTING_GROUP_TRIGGERABLE              (0x01)
#define SOAD_ROUTING_GROUP_INIT_ENABLED             (0x02)

/* Valid values used for CtrlFlag in the SoAd_PduRouteType*/
#define SOAD_PDUROUTE_PDUHEADER_ENABLED             (0x01)
#define SOAD_PDUROUTE_FANOUT                        (0x02)

/* The Remote Address*/
#define SOAD_REMOTE_ADDRESS_UNSET                   (0x04)
#define SOAD_REMOTE_ADDRESS_ALL_ANY                 (0x00)
#define SOAD_REMOTE_ADDRESS_PORT_SET                (0x01)
#define SOAD_REMOTE_ADDRESS_IP_SET                  (0x02)
#define SOAD_REMOTE_ADDRESS_SET                     (0x03)

/* The UDP Trigger Mode*/
#define SOAD_UDP_TRIGGER_ALWAYS                     (0x01)
#define SOAD_UDP_TRIGGER_NEVER                      (0x02)

#define SOAD_IFTX_UDPTXTIMER_DEFAULT_VALUE          (0xFFFF)


/*******************************************************************************
*   Global Data Declaration
*******************************************************************************/

typedef TcpIp_SockAddrInetType SoAd_RemoteAddressType;

typedef enum
{
    SOAD_SOCON_UNINIT = 0,
    SOAD_SOCON_OFFLINE,
    SOAD_SOCON_RECONN,
    SOAD_SOCON_ONLINE
} SoAd_SoConModeType;   /*SWS_SoAd_00512*/

typedef struct
{
    uint32 PduHeaderId;
    uint32 PduLength;
} SoAd_PduHeaderType;

typedef struct
{
    /*UDP Tx buffer(nPduUdpBuffer or TP) or TCP Rx Buffer(IF)*/  /*SWS_SoAd_00565*/
    uint16 IfBufferLength;
    uint16 IfBufferOffset;
    /*TCP Rx Buffer(TP)*/
    uint16 TpBufferLength;
    uint16 TpBufferOffset;
    uint8 PduRouteNum;
    uint8 SocketRouteNum;
    uint8 PduRouteDestNum;
    uint8 RemoteAddrState;
    SoAd_RemoteAddressType RemoteAddr; 
    P2CONST(SoAd_PduRouteDestIdType, AUTOMATIC, AUTOMATIC) PduRouteDestList;
    P2CONST(SoAd_PduRouteIdType, AUTOMATIC, AUTOMATIC) PduRouteList;
    P2CONST(SoAd_SocketRouteIdType, AUTOMATIC, AUTOMATIC) SocketRouteList;
    P2CONST(SoAd_ULIndexType, AUTOMATIC, AUTOMATIC) SoConModeChgList;
} SoAd_SocketConnectionType;

typedef struct
{
    uint8 CtrlFlag;
    uint16 KeepAliveProbesMax;
    uint32 KeepAliveInterval;
    uint32 KeepAliveTime;
    uint32 TxQuota;
} SoAd_TcpProtocolType;

typedef struct
{
    uint8 CtrlFlag;
    uint16 nPduTxBufferMin;
    SoAd_IfTxTimerType TriggerTimeout; /*real value is TriggerTimeout - 1*/
    uint32 AliveSupervisionTimeout;
} SoAd_UdpProtocolType;

typedef struct
{
    SoAd_SoConGroupIdType GroupId;
    uint8 CtrlFlag;
    uint8 FramePriority;
    SoAd_SoConIdType SoConNum;
    SoAd_SoConIdType SoConId;
    TcpIp_LocalAddrIdType IpAddrAssignChgNum;
    TcpIp_LocalAddrIdType LocalAddrId;
    uint16 LocalPort;
    P2CONST(SoAd_ULIndexType, AUTOMATIC, AUTOMATIC) IpAddrAssignChgList;
    P2CONST(SoAd_TcpProtocolType, AUTOMATIC, AUTOMATIC) TcpProtocolPtr;
    P2CONST(SoAd_UdpProtocolType, AUTOMATIC, AUTOMATIC) UdpProtocolPtr;
} SoAd_SocketConnectionGroupType;

typedef struct
{
    uint8 CtrlFlag;
    uint8 PduRouteDestNum;
    uint8 SocketRouteDestNum;
    P2CONST(uint8, AUTOMATIC, AUTOMATIC) PduRouteDestList;
    P2CONST(uint8, AUTOMATIC, AUTOMATIC) SocketRouteDestList;
} SoAd_RoutingGroupType;

typedef struct
{
    uint8 ULType;   /*IF or TP*/
    /*
     *  The Index of UpLayer module is used to find callback in SoAd_UpLayerInterfaces[].
     */
    SoAd_ULIndexType ULIndex;
    uint8 CtrlFlag;
    uint8 RouteDestNum;
    uint8 RouteDestId;
    /*
     *  The Pdu Id allocated by UpLayer modules of SoAd.
     *  It's used to call Up_TxConfirmation and(or) Up_IfTriggerTransmit.
     */
    PduIdType TxPduId;
} SoAd_PduRouteType;

typedef struct
{
    uint32 TxPduHeaderId;
    SoAd_SoConIdType SoConNum;
    SoAd_SoConIdType SoConId;
    SoAd_PduRouteIdType PduRouteId; /*PduRouteDest to PduRoute*/
    uint8 UdpTriggerMode;
    SoAd_IfTxTimerType UdpTriggerTimeout;
    /*The runtime context of PduRouteDest*/
    P2VAR(SoAd_RoutingGroupCtrlType, SOAD_CONFIG_DATA, AUTOMATIC) RoutingCtrlList;
    P2VAR(uint8, SOAD_CONFIG_DATA, AUTOMATIC) IfTriggerList;
} SoAd_PduRouteDestType;

typedef struct
{
    uint32 RxPduHeaderId;
    uint8 ULType;   /*IF or TP*/
    /*
     *  The Index of UpLayer module is used to find callback in SoAd_UpLayerInterfaces[].
     */
    SoAd_ULIndexType ULIndex;
    SoAd_SoConIdType SoConNum;
    SoAd_SoConIdType SoConId;
    /*
     *  The Pdu Id allocated by UpLayer modules of SoAd.
     *  It's used to call Up_RxIndication.
     */
    PduIdType RxPduId;
    /*The runtime context of SocketRouteDest*/
    P2VAR(SoAd_RoutingGroupCtrlType, SOAD_CONFIG_DATA, AUTOMATIC) RoutingCtrlList;
} SoAd_SocketRouteType;

/*SWS_SoAd_00210*/
typedef struct
{
    SoAd_SoConIdType SoConNum;
    SoAd_SoConGroupIdType SoConGroupNum;
    SoAd_PduRouteIdType PduRouteNum;
    SoAd_SocketRouteIdType SocketRouteNum;
    SoAd_RoutingGroupIdType RoutingGroupNum;
    uint8 LocalIpStateNum;
    uint16 PduRouteDestNum;
    uint16 BufferLength;
    uint16 IfTriggerBufferLength;
    /*
     * This buffer is a set including IfTriggerBuffer, PduUdpTxBuffer, UdpTpTxBuffer,
     * IfRxBuffer and TpRxBuffer.
     *
     * Note that the IfTriggerBuffer always located at first.
     *
     */
    P2VAR(uint8, SOAD_CONFIG_DATA, AUTOMATIC) Buffer;
    /*
     * SharedSocketIdList is used to keep the socketId used for SoConGroup.
     * Its size equal to SoConGroupNum.
     *
     */
    P2VAR(TcpIp_SocketIdType, SOAD_CONFIG_DATA, AUTOMATIC) SharedSocketIdList;
    /*
     * LocalIpStateList is used to keep the latest state of the local IP address used by SoConGroup.
     * THe LocalIpStateNum equal to the maximum value of LocalAddrId in all SoConGroups.
     */
    P2VAR(TcpIp_IpAddrStateType, SOAD_CONFIG_DATA, AUTOMATIC) LocalIpStateList;
    /*
     * IfTxUnconfirmList is used to keep the unconfirmated IF transmission request.
     * Its size equal to PduRouteNum.
     */
    P2VAR(SoAd_IfTxUnconfirmedType, SOAD_CONFIG_DATA, AUTOMATIC) IfTxUnconfirmList;
    P2CONST(SoAd_SocketConnectionType, SOAD_CONFIG_DATA, AUTOMATIC) SoConList;
    P2CONST(SoAd_SocketConnectionGroupType, SOAD_CONFIG_DATA, AUTOMATIC) SoConGroupList;
    P2CONST(SoAd_PduRouteType, SOAD_CONFIG_DATA, AUTOMATIC) PduRouteList;
    P2CONST(SoAd_PduRouteDestType, SOAD_CONFIG_DATA, AUTOMATIC) PduRouteDestList;
    P2CONST(SoAd_SocketRouteType, SOAD_CONFIG_DATA, AUTOMATIC) SocketRouteList;
    P2CONST(SoAd_RoutingGroupType, SOAD_CONFIG_DATA, AUTOMATIC) RoutingGroupList;
} SoAd_ConfigType;


typedef struct
{
    uint8 State;
    SoAd_IfTxTimerType Timer; /*SWS_SoAd_00696*/
    uint16 BufferLength;
    uint16 BufferOffset;
    /*
     * If the State is SOAD_SESSION_STATE_IF, the buffer is nPduUdpTxBuffer.
     * If the State is SOAD_SESSION_STATE_TP, the buffer is used to cache data of UDP protocol.
     *
     * Note that a SoCon supports only one type, IF or TP.
     */
    P2VAR(uint8, AUTOMATIC, AUTOMATIC) UdpTxBuffer;

    uint16 TotalTxLength;
    uint16 UsedTxLength;
    /*
     * It's used to keep the PduInfoPtr->SduDataPtr when SoAd_IfTransmit is called
     * and the PduHeader is enabled.
     */
    P2CONST(uint8, AUTOMATIC, AUTOMATIC) IfTxDataBuffer;
    P2CONST(SoAd_PduRouteDestType, SOAD_CONFIG_DATA, AUTOMATIC) PduRouteDestPtr;
} SoAd_TxSessionType;


typedef struct
{
    uint16 PduLength;
    uint16 RemainLength;
    P2CONST(SoAd_SocketRouteType, SOAD_CONFIG_DATA, AUTOMATIC) SocketRoutePtr;
} SoAd_RxPduInfoType;

typedef struct
{
    uint16 TotalLength;
    uint16 In;
    uint16 Out;
    P2VAR(uint8, AUTOMATIC, AUTOMATIC) BufferPtr;
} SoAd_RxFifoType;

typedef struct
{
    uint16 TotalLength;
    uint16 UsedLength;
    P2VAR(uint8, AUTOMATIC, AUTOMATIC) BufferPtr;
} SoAd_RxBufferType;

typedef struct
{
    uint8 State;
    uint8 ValidHeaderLen;
    uint8 PduHeader[SOAD_PDUHEADER_LENGTH];

    /* RxIndication: cache the pdu divided into 2+ TcpIp messages */
    SoAd_RxPduInfoType RxPduInfo;

    /*MainFunction: cache the TP pdu can't be one-time received by the upper layer*/

    SoAd_RxPduInfoType ProcessPduInfo;
    SoAd_RxBufferType IfBuffer;
    SoAd_RxFifoType TpBuffer;
} SoAd_RxSessionType;

/*
 * The context of Socket Connection.
 */
 typedef struct
 {
    SoAd_SoConIdType SoConId;
    SoAd_SoConModeType Mode;
    uint8 ModeRequest;
    boolean Abort;
    TcpIp_SocketIdType SocketId;
    uint8 RemoteAddrState;
    SoAd_RemoteAddressType RemoteAddr; 
    SoAd_TxSessionType TxSession;
    SoAd_RxSessionType RxSession;
    P2CONST(SoAd_SocketConnectionType, AUTOMATIC, AUTOMATIC) ConfigPtr;
    P2CONST(SoAd_SocketConnectionGroupType, AUTOMATIC, AUTOMATIC) GroupConfigPtr;
 } SoAd_ConnectionType;

typedef struct
{
    /*Notification Interfaces*/
    /*SWS_SoAd_00514 <Up>_SoConModeChg*/
    P2FUNC(void, AUTOMATIC, SoConModeChg)
    (SoAd_SoConIdType SoConId, SoAd_SoConModeType SoConMode);
    /*SWS_SoAd_00513 <Up>_LocalIpAddrAssignmentChg*/
    P2FUNC(void, AUTOMATIC, LocalIpAddrAssignmentChg)
    (SoAd_SoConIdType SoConId, TcpIp_IpAddrStateType State);

    /*IF Interfaces*/
    /*SWS_SoAd_00106 <Up>_IfRxIndication*/
    P2FUNC(void, AUTOMATIC, IfRxIndication)
    (PduIdType RxPduId, P2CONST(PduInfoType, AUTOMATIC, AUTOMATIC) PduInfoPtr);
    /*SWS_SoAd_00663 <Up>IfTriggerTransmit*/
    P2FUNC(Std_ReturnType, AUTOMATIC, IfTriggerTransmit)
    (PduIdType RxPduId, P2VAR(PduInfoType, AUTOMATIC, AUTOMATIC) PduInfoPtr);
    /*SWS_SoAd_00107 <Up>_IfTxConfirmation*/
    P2FUNC(void, AUTOMATIC, IfTxConfirmation)(PduIdType RxPduId);

    /*TP Interfaces*/
    /*SWS_SoAd_00137 <Up>_CopyTxData*/
    P2FUNC(BufReq_ReturnType, AUTOMATIC, CopyTxData)
    (PduIdType TxPduId,P2CONST(PduInfoType, AUTOMATIC, AUTOMATIC) PduInfoPtr,
    P2VAR(RetryInfoType, AUTOMATIC, AUTOMATIC) RetryPtr, P2VAR(PduLengthType, AUTOMATIC, AUTOMATIC) AvailableDataPtr);
    /*SWS_SoAd_00181 <Up>_TpTxConfirmation*/
    P2FUNC(void, AUTOMATIC, TpTxConfirmation)(PduIdType TxPduId, Std_ReturnType Result);
    /*SWS_SoAd_00138 <Up>_StartOfReception*/
    P2FUNC(BufReq_ReturnType, AUTOMATIC, StartOfReception)
    (PduIdType RxPduId,P2CONST(PduInfoType, AUTOMATIC, AUTOMATIC) PduInfoPtr,
    PduLengthType TpSduLength, P2VAR(PduLengthType, AUTOMATIC, AUTOMATIC) bufferSizePtr);
    /*SWS_SoAd_00139 <Up>_CopyRxData*/
    P2FUNC(BufReq_ReturnType, AUTOMATIC, CopyRxData)
    (PduIdType RxPduId,P2CONST(PduInfoType, AUTOMATIC, AUTOMATIC) PduInfoPtr,
    P2VAR(PduLengthType, AUTOMATIC, AUTOMATIC) bufferSizePtr);
    /*SWS_SoAd_00180 <Up>_TpRxIndication*/
    P2FUNC(void, AUTOMATIC, TpRxIndication)(PduIdType RxPduId, Std_ReturnType Result);
} SoAd_UpLayerInterfaceType;

/*******************************************************************************
*   Global Function Declaration
*******************************************************************************/

#endif /*_SOAD_TYPES_H_*/
