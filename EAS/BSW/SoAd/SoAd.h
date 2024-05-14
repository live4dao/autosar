/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE                             
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
*   File Name       : SoAd.h
********************************************************************************
*   Project/Product : AUTOSAR 4.2
*   Title           : The Socket Adaptor
*   Author          : mingqing.tang
********************************************************************************
*   Description     : The header file SoAd.h contains the declaration of the
*                     SoAd module API, 'extern' declarations of constants,
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

#ifndef _SOAD_H_
#define _SOAD_H_

/*******************************************************************************
*   Includes
*******************************************************************************/
#include "SoAd_Cfg.h"
#include "SoAd_Types.h"
#include "SoAd_Version.h"


/*******************************************************************************
*   Macro
*******************************************************************************/
/*SWS_SoAd_00101 Development Errors*/
#define SOAD_E_NOTINIT                          (0x01)
#define SOAD_E_PARAM_POINTER                    (0x02)
#define SOAD_E_INV_ARG                          (0x03)
#define SOAD_E_NOBUFS                           (0x04)
#define SOAD_E_INV_PDUHEADER_ID                 (0x05)
#define SOAD_E_INV_PDUID                        (0x06)
#define SOAD_E_INV_SOCKETID                     (0x07)
#define SOAD_E_INIT_FAILED                      (0x08)
#define SOAD_E_INV_CONFIG_DATA                  (0x09)

#define SOAD_API_INIT                           (0x01)
#define SOAD_API_IF_TRANSMIT                    (0x03)
#define SOAD_API_TP_TRANSMIT                    (0x04)
#define SOAD_API_TP_CANCEL_TRANSMIT             (0x05)
#define SOAD_API_TP_CANCEL_RECEIVE              (0x06)
#define SOAD_API_GET_SOCONID                    (0x07)
#define SOAD_API_OPEN_SOCON                     (0x08)
#define SOAD_API_CLOSE_SOCON                    (0x09)
#define SOAD_API_REQUEST_IPADDR_ASSIGNMENT      (0x0A)
#define SOAD_API_RELEASE_IPADDR_ASSIGNMENT      (0x0B)
#define SOAD_API_GET_LOCAL_ADDR                 (0x0C)
#define SOAD_API_GET_PHYS_ADDR                  (0x0D)
#define SOAD_API_ENABLE_ROUTING                 (0x0E)
#define SOAD_API_DISABLE_ROUTING                (0x0F)
#define SOAD_API_SET_REMOTE_ADDR                (0x10)
#define SOAD_API_TP_CHANGE_PARAMETER            (0x11)
#define SOAD_API_RX_INDICATION                  (0x12)
#define SOAD_API_COPY_TX_DATA                   (0x13)
#define SOAD_API_TX_CONFIRMATION                (0x14)
#define SOAD_API_TCP_ACCEPTED                   (0x15)
#define SOAD_API_TCP_CONNECTED                  (0x16)
#define SOAD_API_TCPIP_EVENT                    (0x17)
#define SOAD_API_LOCAL_IPADDR_ASSIGNMENT_CHG    (0x18)
#define SOAD_API_MAIN_FUNCTION                  (0x19)
#define SOAD_API_READ_DHCP_HOST_NAME_OPTION     (0x1A)
#define SOAD_API_WRITE_DHCP_HOST_NAME_OPTION    (0x1B)
#define SOAD_API_GET_REMOTE_ADDR                (0x1C)
#define SOAD_API_IF_ROUTING_GROUP_TRANSMIT      (0x1D)
#define SOAD_API_SET_UNIQUE_REMOTE_ADDR         (0x1E)
#define SOAD_API_IF_SPECROUTING_GROUP_TRANSMIT  (0x1F)
#define SOAD_API_ENABLE_SPECIFIC_ROUTING        (0x20)
#define SOAD_API_DISABLE_SPECIFIC_ROUTING       (0x21)
#define SOAD_API_INTERNAL                       (0xFF)

/*******************************************************************************
*   Global Data Declaration
*******************************************************************************/

/*******************************************************************************
*   Global Function Declaration
*******************************************************************************/
#define SOAD_START_SEC_CODE
#include "MemMap.h"
FUNC(void, SOAD_CODE) SoAd_Init
(
    P2CONST(SoAd_ConfigType, SOAD_CONFIG_DATA, AUTOMATIC) ConfigPtr
);
/*SWS_SoAd_00091*/
FUNC(Std_ReturnType, SOAD_CODE) SoAd_IfTransmit
(
    PduIdType TxPduId,
    P2CONST(PduInfoType, AUTOMATIC, SOAD_APPL_DATA) PduInfoPtr
);

FUNC(Std_ReturnType, SOAD_CODE) SoAd_IfRoutingGroupTransmit
(
    SoAd_RoutingGroupIdType GroupId
);

/*SWS_SoAd_00711*/
FUNC(Std_ReturnType, SOAD_CODE) SoAd_IfSpecificRoutingGroupTransmit
(
    SoAd_RoutingGroupIdType GroupId,
    SoAd_SoConIdType SoConId
);

FUNC(Std_ReturnType, SOAD_CODE) SoAd_TpTransmit
(
    PduIdType TxPduId,
    P2CONST(PduInfoType, AUTOMATIC, SOAD_APPL_DATA) PduInfoPtr
);

FUNC(Std_ReturnType, SOAD_CODE) SoAd_TpCancelTransmit
(
    PduIdType PduId
);

FUNC(Std_ReturnType, SOAD_CODE) SoAd_TpCancelReceive
(
    PduIdType PduId
);
/*SWS_SoAd_00509*/
FUNC(Std_ReturnType, SOAD_CODE) SoAd_GetSoConId
(
    PduIdType TxPduId,
    P2VAR(SoAd_SoConIdType, AUTOMATIC, SOAD_APPL_DATA) SoConIdPtr
);
/*SWS_SoAd_00510*/
FUNC(Std_ReturnType, SOAD_CODE) SoAd_OpenSoCon
(
    SoAd_SoConIdType SoConId
);
/*SWS_SoAd_00511*/
FUNC(Std_ReturnType, SOAD_CODE) SoAd_CloseSoCon
(
    SoAd_SoConIdType SoConId,
    boolean Abort
);

FUNC(Std_ReturnType, SOAD_CODE) SoAd_RequestIpAddrAssignment
(
    SoAd_SoConIdType SoConId,
    TcpIp_IpAddrAssignmentType Type,
    P2CONST(TcpIp_SockAddrType, AUTOMATIC, SOAD_APPL_DATA) LocalIpAddrPtr,
    uint8 Netmask,
    P2CONST(TcpIp_SockAddrType, AUTOMATIC, SOAD_APPL_DATA) DefaultRouterPtr
);

FUNC(Std_ReturnType, SOAD_CODE) SoAd_ReleaseIpAddrAssignment
(
    SoAd_SoConIdType SoConId
);

FUNC(Std_ReturnType, SOAD_CODE) SoAd_GetLocalAddr
(
    SoAd_SoConIdType SoConId,
    P2VAR(TcpIp_SockAddrType, AUTOMATIC, SOAD_APPL_DATA) LocalAddrPtr,
    P2VAR(uint8, AUTOMATIC, SOAD_APPL_DATA) NetmaskPtr,
    P2VAR(TcpIp_SockAddrType, AUTOMATIC, SOAD_APPL_DATA) DefaultRouterPtr
);

FUNC(Std_ReturnType, SOAD_CODE) SoAd_GetPhysAddr
(
    SoAd_SoConIdType SoConId,
    P2VAR(uint8, AUTOMATIC, SOAD_APPL_DATA) PhysAddrPtr
);

FUNC(Std_ReturnType, SOAD_CODE) SoAd_GetRemoteAddr
(
    SoAd_SoConIdType SoConId,
    P2VAR(TcpIp_SockAddrType, AUTOMATIC, SOAD_APPL_DATA) IpAddrPtr
);

FUNC(Std_ReturnType, SOAD_CODE) SoAd_SetRemoteAddr
(
    SoAd_SoConIdType SoConId,
    P2CONST(TcpIp_SockAddrType, AUTOMATIC, SOAD_APPL_DATA) IpAddrPtr
);

FUNC(Std_ReturnType, SOAD_CODE) SoAd_SetUniqueRemoteAddr
(
    SoAd_SoConIdType SoConId,
    P2CONST(TcpIp_SockAddrType, AUTOMATIC, SOAD_APPL_DATA) IpAddrPtr,
    P2VAR(SoAd_SoConIdType, AUTOMATIC, SOAD_APPL_DATA) AssignedSoConIdPtr
);

FUNC(Std_ReturnType, SOAD_CODE) SoAd_EnableRouting
(
    SoAd_RoutingGroupIdType id
);

FUNC(Std_ReturnType, SOAD_CODE) SoAd_EnableSpecificRouting
(
    SoAd_RoutingGroupIdType GroupId,
    SoAd_SoConIdType SoConId
);

FUNC(Std_ReturnType, SOAD_CODE) SoAd_DisableRouting
(
    SoAd_RoutingGroupIdType GroupId
);

FUNC(Std_ReturnType, SOAD_CODE) SoAd_DisableSpecificRouting
(
    SoAd_RoutingGroupIdType GroupId,
    SoAd_SoConIdType SoConId
);

FUNC(Std_ReturnType, SOAD_CODE) SoAd_TpChangeParameter
(
    PduIdType PduId,
    uint8 Parameter,
    uint16 Value
);

FUNC(Std_ReturnType, SOAD_CODE) SoAd_ReadDhcpHostNameOption
(
    SoAd_SoConIdType SoConId,
    P2VAR(uint8, AUTOMATIC, SOAD_APPL_DATA) Length,
    P2VAR(uint8, AUTOMATIC, SOAD_APPL_DATA) Data
);

FUNC(Std_ReturnType, SOAD_CODE) SoAd_WriteDhcpHostNameOption
(
    SoAd_SoConIdType SoConId,
    uint8 Length,
    P2CONST(uint8, AUTOMATIC, SOAD_APPL_DATA) Data
);

FUNC(void, SOAD_CODE) SoAd_MainFunction
(
    void
);

#if (SOAD_VERSION_INFO_API == STD_ON)
FUNC(void, SOAD_CODE) SoAd_GetVersionInfo
(
    P2VAR(Std_VersionInfoType, AUTOMATIC, SOAD_APPL_DATA) VersionInfoPtr
);
#endif

#define SOAD_STOP_SEC_CODE
#include "MemMap.h"

#endif /*_SOAD_H_*/
