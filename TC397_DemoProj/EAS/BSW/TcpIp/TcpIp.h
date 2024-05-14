/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE                             
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
*   File Name       : TcpIp.h
********************************************************************************
*   Project/Product : AUTOSAR 4.2
*   Title           : The TcpIp Stack
*   Author          : mingqing.tang
********************************************************************************
*   Description     : The header file TcpIp.h contains the declaration of the
*                     TcpIp module API, 'extern' declarations of constants,
*                     global data,type definitions and services that are
*                     specified in the TcpIp module SWS.
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
*   02.00.00    21/05/2018    mingqing.tang   N/A          AUTOSAR V4.2.2
*   02.01.00    25/06/2018    mingqing.tang   N/A          Enable DHCP, AutoIP
********************************************************************************
* END_FILE_HDR*/
#ifndef _TCPIP_H_
#define _TCPIP_H_

/*******************************************************************************
*   Includes
*******************************************************************************/
#include "TcpIp_Types.h"
#include "TcpIp_Version.h"

/*******************************************************************************
*   Macro
*******************************************************************************/

#define TCPIP_E_NOTINIT                         (1)
#define TCPIP_E_PARAM_POINTER                   (2)
#define TCPIP_E_INV_ARG                         (3)
#define TCPIP_E_NOBUFS                          (4)
#define TCPIP_E_INV_SOCKADDR                    (5)
#define TCPIP_E_DESTADDRREQ                     (6)
#define TCPIP_E_MSGSIZE                         (7)
#define TCPIP_E_PROTOTYPE                       (8)
#define TCPIP_E_ADDRINUSE                       (9)
#define TCPIP_E_ADDRNOTAVAIL                    (10)
#define TCPIP_E_ISCONN                          (11)
#define TCPIP_E_NOTCONN                         (12)
#define TCPIP_E_NOPROTOOPT                      (13)
#define TCPIP_E_AFNOSUPPORT                     (14)
#define TCPIP_E_INV_CONFIG                      (15)

#define TCPIP_API_INIT                          (0x01)
#define TCPIP_API_GETVERSIONINFO                (0x02)
#define TCPIP_API_GETSOCKET                     (0x03)
#define TCPIP_API_CLOSE                         (0x04)
#define TCPIP_API_BIND                          (0x05)
#define TCPIP_API_TCPCONNECT                    (0x06)
#define TCPIP_API_TCPLISTEN                     (0x07)
#define TCPIP_API_TCPRECEIVED                   (0x08)
#define TCPIP_API_REQUESTCOMMODE                (0x09)
#define TCPIP_API_REQUESTIPADDRASSIGNMENT       (0x0A)
#define TCPIP_API_RELEASEIPADDRASSIGNMENT       (0x0B)
#define TCPIP_API_ICMPTRANSMIT                  (0x0C)
#define TCPIP_API_DHCPREADOPTION                (0x0D)
#define TCPIP_API_DHCPWRITEOPTION               (0x0E)
#define TCPIP_API_CHANGEPARAMETER               (0x0F)
#define TCPIP_API_GETIPADDR                     (0x10)
#define TCPIP_API_GETPHYSADDR                   (0x11)
#define TCPIP_API_UDPTRANSMIT                   (0x12)
#define TCPIP_API_TCPTRANSMIT                   (0x13)
#define TCPIP_API_RXINDICATION                  (0x14)
#define TCPIP_API_MAINFUNCTION                  (0x15)
#define TCPIP_API_GETREMOTEPHYSADDR             (0x16)
#define TCPIP_API_GETCTRLIDX                    (0x17)
#define TCPIP_API_ICMPV6TRANSMIT                (0x18)
#define TCPIP_API_DHCPV6READOPTION              (0x19)
#define TCPIP_API_DHCPV6WRITEOPTION             (0x1A)
#define TCPIP_API_RESETIPASSIGNMENT             (0x1B)

/*******************************************************************************
*   Global Function Declaration
*******************************************************************************/
#define TCPIP_START_SEC_CODE
#include "MemMap.h"

extern FUNC(void, TCPIP_CODE) TcpIp_Init
(
    P2CONST(TcpIp_ConfigType, AUTOMATIC, AUTOMATIC) CfgPtr
);

extern FUNC(void, TCPIP_CODE) TcpIp_MainFunction
(
    void
);

/*SWS_TCPIP_00037*/
extern FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_RequestIpAddrAssignment
(
    TcpIp_LocalAddrIdType LocalAddrId,
    TcpIp_IpAddrAssignmentType Type,
    P2CONST(TcpIp_SockAddrType, AUTOMATIC, AUTOMATIC) LocalIpAddrPtr,
    uint8 Netmask,
    P2CONST(TcpIp_SockAddrType, AUTOMATIC, AUTOMATIC) DefaultRouterPtr
);
/*SWS_TCPIP_00078*/
extern FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_ReleaseIpAddrAssignment
(
    TcpIp_LocalAddrIdType LocalAddrId
);
/*SWS_TCPIP_00070*/
extern FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_RequestComMode
(
    uint8 CtrlIdx,
    TcpIp_StateType State
);

/*SWS_TCPIP_00018*/
extern FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_GetSocket
(
    TcpIp_DomainType Domain,
    TcpIp_ProtocolType Protocol,
    TcpIp_UpLayerIndexType UpLayer,
    P2VAR(TcpIp_SocketIdType, AUTOMATIC, AUTOMATIC) SocketIdPtr
);

/*SWS_TCPIP_00017*/
extern FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Close
(
    TcpIp_SocketIdType SocketId,
    boolean Abort
);
/*SWS_TCPIP_00015*/
extern FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Bind
(
    TcpIp_SocketIdType SocketId,
    TcpIp_LocalAddrIdType LocalAddrId,
    P2VAR(uint16, AUTOMATIC, AUTOMATIC) PortPtr
);
/*SWS_TCPIP_00022*/
extern FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TcpConnect
(
    TcpIp_SocketIdType SocketId,
    P2CONST(TcpIp_SockAddrType, AUTOMATIC, AUTOMATIC) RemoteAddrPtr
);
/*SWS_TCPIP_00023*/
extern FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TcpListen
(
    TcpIp_SocketIdType SocketId,
    uint16 MaxChannels
);
/*SWS_TCPIP_00024*/
extern FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TcpReceived
(
    TcpIp_SocketIdType SocketId,
    uint32 Length
);

/*SWS_TCPIP_00050*/
extern FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TcpTransmit
(
    TcpIp_SocketIdType SocketId,
    P2CONST(uint8, AUTOMATIC, AUTOMATIC) DataPtr,
    uint32 AvailableLength,
    boolean ForceRetrieve
);
/*SWS_TCPIP_00025*/
extern FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_UdpTransmit
(
    TcpIp_SocketIdType SocketId,
    P2CONST(uint8, AUTOMATIC, AUTOMATIC) DataPtr,
    P2CONST(TcpIp_SockAddrType, AUTOMATIC, AUTOMATIC) RemoteAddrPtr,
    uint16 TotalLength
);
/*SWS_TCPIP_00140*/
extern FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_GetCtrlIdx
(
    TcpIp_LocalAddrIdType LocalAddrId,
    P2VAR(uint8, AUTOMATIC, AUTOMATIC) CtrlIdxPtr
);
/*SWS_TCPIP_00032*/
extern FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_GetIpAddr
(
    TcpIp_LocalAddrIdType LocalAddrId,
    P2VAR(TcpIp_SockAddrType, AUTOMATIC, AUTOMATIC) IpAddrPtr,
    P2VAR(uint8, AUTOMATIC, AUTOMATIC) NetmaskPtr,
    P2VAR(TcpIp_SockAddrType, AUTOMATIC, AUTOMATIC) DefaultRouterPtr
);
/*SWS_TCPIP_00033*/
extern FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_GetPhysAddr
(
    TcpIp_LocalAddrIdType LocalAddrId,
    P2VAR(uint8, AUTOMATIC, AUTOMATIC) PhysAddrPtr
);
/*SWS_TCPIP_00137*/
extern FUNC(TcpIp_ReturnType, TCPIP_CODE) TcpIp_GetRemotePhysAddr
(
    uint8 CtrlIdx,
    P2VAR(TcpIp_SockAddrType, AUTOMATIC, AUTOMATIC) IpAddrPtr,
    P2VAR(uint8, AUTOMATIC, AUTOMATIC) PhysAddrPtr,
    boolean initRes
);
/*SWS_TCPIP_00016*/
extern FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_ChangeParameter
(
    TcpIp_SocketIdType SocketId,
    TcpIp_ParamIdType ParameterId,
    P2CONST(uint8, AUTOMATIC, AUTOMATIC) ParameterValue
);
/*SWS_TCPIP_00040*/
extern FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_DhcpReadOption
(
    TcpIp_LocalAddrIdType LocalAddrId,
    uint8 Option,
    P2VAR(uint8, AUTOMATIC, AUTOMATIC) DataLengthPtr,
    P2VAR(uint8, AUTOMATIC, AUTOMATIC) DataPtr
);
/*SWS_TCPIP_00020*/
extern FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_DhcpWriteOption
(
    TcpIp_LocalAddrIdType LocalAddrId,
    uint8 Option,
    uint8 DataLength,
    P2CONST(uint8, AUTOMATIC, AUTOMATIC) DataPtr
);
/*SWS_TCPIP_00189*/
extern FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_DhcpV6ReadOption
(
    TcpIp_LocalAddrIdType LocalAddrId,
    uint16 Option,
    P2VAR(uint16, AUTOMATIC, AUTOMATIC) DataLengthPtr,
    P2VAR(uint8, AUTOMATIC, AUTOMATIC) DataPtr
);
/*SWS_TCPIP_00190*/
extern FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_DhcpV6WriteOption
(
    TcpIp_LocalAddrIdType LocalAddrId,
    uint16 Option,
    uint16 DataLength,
    P2CONST(uint8, AUTOMATIC, AUTOMATIC) DataPtr
);

/*SWS_TCPIP_00004*/
extern FUNC(void, TCPIP_CODE) TcpIp_GetVersionInfo
(
    P2VAR(Std_VersionInfoType, AUTOMATIC, AUTOMATIC) VersionInfoPtr
);

#define TCPIP_STOP_SEC_CODE
#include "MemMap.h"

#endif /* _TCPIP_H_ */
