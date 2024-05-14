/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
*   File Name       : SoAd_Cbk.h
********************************************************************************
*   Project/Product : AUTOSAR 4.2
*   Title           : The Socket Adaptor
*   Author          : mingqing.tang
********************************************************************************
*   Description     : The header file SoAd_Cbk.h contains the declaration of
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
*   01.00.00    18/06/2014    mingqing.tang   N/A          Original
*   02.00.00    01/09/2017    mingqing.tang   N/A          Update to R4.2.2
********************************************************************************
* END_FILE_HDR*/

#ifndef _SOAD_CBK_H_
#define _SOAD_CBK_H_

/*******************************************************************************
*   Includes
*******************************************************************************/
#include "ComStack_Types.h"
#include "TcpIp_Types.h"
#include "SoAd_Types.h"
#include "SoAd_Cfg.h"

/*******************************************************************************
*   Macro
*******************************************************************************/

/*******************************************************************************
*   Global Data Declaration
*******************************************************************************/

/*******************************************************************************
*   Global Function Declaration
*******************************************************************************/
#define SOAD_START_SEC_CODE
#include "MemMap.h"
FUNC(void, SOAD_CODE) SoAd_RxIndication
(
    TcpIp_SocketIdType SocketId,
    P2CONST(TcpIp_SockAddrType, AUTOMATIC, SOAD_APPL_DATA) RemoteAddrPtr,
    P2VAR(uint8, AUTOMATIC, SOAD_APPL_DATA) DataPtr,
    uint16 DataLength
);

FUNC(BufReq_ReturnType, SOAD_CODE) SoAd_CopyTxData
(
    TcpIp_SocketIdType SocketId,
    P2VAR(uint8, AUTOMATIC, SOAD_APPL_DATA) BufferPtr,
    uint16 BufferLength
);

FUNC(void, SOAD_CODE) SoAd_TxConfirmation
(
    TcpIp_SocketIdType SocketId,
    uint16 Length
);

FUNC(Std_ReturnType, SOAD_CODE) SoAd_TcpAccepted
(
    TcpIp_SocketIdType SocketId,
    TcpIp_SocketIdType SocketIdConnected,
    P2CONST(TcpIp_SockAddrType, AUTOMATIC, SOAD_APPL_DATA) RemoteAddrPtr
);

FUNC(void, SOAD_CODE) SoAd_TcpConnected
(
    TcpIp_SocketIdType SocketId
);

FUNC(void, SOAD_CODE) SoAd_TcpIpEvent
(
    TcpIp_SocketIdType SocketId,
    TcpIp_EventType Event
);

FUNC(void, SOAD_CODE) SoAd_LocalIpAddrAssignmentChg
(
    TcpIp_LocalAddrIdType IpAddrId,
    TcpIp_IpAddrStateType State
);

/*Callouts*/
FUNC(void, SOAD_CALLOUT_CODE) SoAd_SetRoutingGroup
(
    P2VAR(SoAd_RoutingGroupCtrlType, SOAD_CONFIG_DATA, AUTOMATIC) RoutingCtrlPtr,
    SoAd_RoutingGroupIdType GroupId,
    uint8 State
);

FUNC(void, SOAD_CALLOUT_CODE) SoAd_SetSpecificRoutingGroup
(
    P2VAR(SoAd_RoutingGroupCtrlType, SOAD_CONFIG_DATA, AUTOMATIC) RoutingCtrlPtr,
    SoAd_RoutingGroupIdType GroupId,
    SoAd_SoConIdType SoConId,
    uint8 State
);

FUNC(Std_ReturnType, SOAD_CALLOUT_CODE) SoAd_IsEnabledRouting
(
    P2CONST(SoAd_RoutingGroupCtrlType, SOAD_CONFIG_DATA, AUTOMATIC) RoutingCtrlPtr
);

#define SOAD_STOP_SEC_CODE
#include "MemMap.h"

#endif /*_SOAD_CBK_H_*/
