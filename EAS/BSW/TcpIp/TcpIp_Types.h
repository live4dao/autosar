/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
*   File Name       : TcpIp_Types.h
********************************************************************************
*   Project/Product : AUTOSAR 4.2
*   Title           : The TCP/IP Stack
*   Author          : mingqing.tang
********************************************************************************
*   Description     : The header file TcpIp_Types.h contains the type definitions
*                     of the TcpIp module.
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
#ifndef _TCPIP_TYPES_H_
#define _TCPIP_TYPES_H_

/*******************************************************************************
*   Includes
*******************************************************************************/
#include "TcpIp_GeneratedTypes.h"

/*******************************************************************************
*   Macro
*******************************************************************************/
#define TCPIP_SCALABILITY_CLASS_1                   (1) /*only IPv4*/
#define TCPIP_SCALABILITY_CLASS_2                   (2) /*only IPv6*/
#define TCPIP_SCALABILITY_CLASS_3                   (3) /*IPv4 and IPv6*/

#define TCPIP_UNICAST                               ((TcpIp_AddressType)0)
#define TCPIP_MULTICAST                             ((TcpIp_AddressType)1)
/*only used for IPv4*/
#define TCPIP_BROADCAST                             ((TcpIp_AddressType)2)
/*only used for IPv6*/
#define TCPIP_ANYCAST                               ((TcpIp_AddressType)2)

#define TCPIP_IPPROTO_TCP                           ((TcpIp_ProtocolType)0x06)
#define TCPIP_IPPROTO_UDP                           ((TcpIp_ProtocolType)0x11)

#define TCPIP_TCP_RESET                             ((TcpIp_EventType)0)
#define TCPIP_TCP_CLOSED                            ((TcpIp_EventType)1)
#define TCPIP_TCP_FIN_RECEIVED                      ((TcpIp_EventType)2)
#define TCPIP_UDP_CLOSED                            ((TcpIp_EventType)3)

#define TCPIP_OK                                    ((TcpIp_ReturnType)0)
#define TCPIP_E_NOT_OK                              ((TcpIp_ReturnType)1)
#define TCPIP_E_PHYS_ADDR_MISS                      ((TcpIp_ReturnType)2)

#define TCPIP_PARAMID_TCP_RXWND_MAX                 ((TcpIp_ParamIdType)0)
#define TCPIP_PARAMID_FRAMEPRIO                     ((TcpIp_ParamIdType)1)
#define TCPIP_PARAMID_TCP_NAGLE                     ((TcpIp_ParamIdType)2)
#define TCPIP_PARAMID_TCP_KEEPALIVE                 ((TcpIp_ParamIdType)3)
#define TCPIP_PARAMID_TTL                           ((TcpIp_ParamIdType)4)
#define TCPIP_PARAMID_TCP_KEEPALIVE_TIME            ((TcpIp_ParamIdType)5)
#define TCPIP_PARAMID_TCP_KEEPALIVE_PROBES_MAX      ((TcpIp_ParamIdType)6)
#define TCPIP_PARAMID_TCP_KEEPALIVE_INTERVAL        ((TcpIp_ParamIdType)7)
#define TCPIP_PARAMID_VENDOR_SPECIFIC               ((TcpIp_ParamIdType)128)

#define TCPIP_IPADDR_STATE_UNASSIGNED               ((TcpIp_IpAddrStateType)0x01)
#define TCPIP_IPADDR_STATE_ONHOLD                   ((TcpIp_IpAddrStateType)0x02)
#define TCPIP_IPADDR_STATE_ASSIGNED                 ((TcpIp_IpAddrStateType)0x03)

#define TCPIP_LOCALADDR_ASSIGNMENT_METHOD_MASK      (0x0F)
#define TCPIP_LOCALADDR_ASSIGNMENT_TRIGGER_MASK     (0x10)
#define TCPIP_LOCALADDR_ASSIGNMENT_LIFETIME_MASK    (0x20)

#define TCPIP_LOCALADDR_ASSIGNMENT_CONFIG_INVALID   (0x0F)

#define TCPIP_AUTOMATIC                             (0)
#define TCPIP_MANUAL                                (0x10)

#define TCPIP_PORT_ANY                              ((TcpIp_PortWildcardType)0)

#define TCPIP_LOCALADDRID_ANY                       ((TcpIp_LocalAddrIdWildcardType)255)
#define TCPIP_LOCALADDRID_INVALID                   ((TcpIp_LocalAddrIdType)254)

#define TCPIP_STATE_OFFLINE                         ((TcpIp_StateType)0x00)
#define TCPIP_STATE_ONLINE                          ((TcpIp_StateType)0x01)
#define TCPIP_STATE_ONHOLD                          ((TcpIp_StateType)0x02)
#define TCPIP_STATE_STARTUP                         ((TcpIp_StateType)0x03)
#define TCPIP_STATE_SHUTDOWN                        ((TcpIp_StateType)0x04)
#define TCPIP_STATE_VISIBLE                         TCPIP_STATE_STARTUP
#define TCPIP_STATE_VALID                           ((TcpIp_StateType)0x05)

#define TCPIP_IPV4CTRL_AUTOIP_DISABLED(config)      ((config)->AutoIpInitTimeout == 65535)
#define TCPIP_IPV4CTRL_DHCP_DISABLED(config)        ((config)->DHCPConfigId >= TCPIP_DHCP_CONFIG_MAX)
#define TCPIP_IPV4CTRL_ARP_DISABLED(config)         ((config)->ArpConfigId >= TCPIP_ARP_CONFIG_MAX)

#define TCPIP_NETCTRL_IPV4_CTRL_DISABLED(config)    ((config)->IpV4CtrlId >= TCPIP_IPV4_CTRL_MAX)

#define TCPIP_LOCALADDR_ASSIGNMENT_PRIORITY_1       (0u)
#define TCPIP_LOCALADDR_ASSIGNMENT_PRIORITY_2       (0x01u)
#define TCPIP_LOCALADDR_ASSIGNMENT_PRIORITY_3       (0x02u)
#define TCPIP_LOCALADDR_ASSIGNMENT_PRIORITY_MAX     (0x03u)

#define TCPIP_IPADDR_ASSIGNMENT_STATIC              ((TcpIp_IpAddrAssignmentType)0x00)
#define TCPIP_IPADDR_ASSIGNMENT_DHCP                ((TcpIp_IpAddrAssignmentType)0x01)
#define TCPIP_IPADDR_ASSIGNMENT_LINKLOCAL           ((TcpIp_IpAddrAssignmentType)0x02)
#define TCPIP_IPADDR_ASSIGNMENT_LINKLOCAL_DOIP      TCPIP_IPADDR_ASSIGNMENT_LINKLOCAL
#define TCPIP_IPADDR_ASSIGNMENT_IPV6_ROUTER         ((TcpIp_IpAddrAssignmentType)0x03)
#define TCPIP_IPADDR_ASSIGNMENT_MAX                 ((TcpIp_IpAddrAssignmentType)0x04)

#define TCPIP_AF_INET                               ((TcpIp_DomainType)0x02)
#define TCPIP_AF_INET6                              ((TcpIp_DomainType)0x1C)
/*******************************************************************************
*   Types Declaration
*******************************************************************************/
/*SWS_TCPIP_00065*/
typedef uint8 TcpIp_IpAddrAssignmentType;

typedef uint8 TcpIp_AddressType;

/*SWS_TCPIP_00010*/
typedef uint8 TcpIp_ProtocolType;

/*SWS_TCPIP_00031*/
typedef uint8 TcpIp_EventType;

/*SWS_TCPIP_00066*/
typedef uint8 TcpIp_ReturnType;

/*SWS_TCPIP_00126*/
typedef uint8 TcpIp_ParamIdType;

typedef uint8 TcpIp_CtrlIdType;
/*WS_TCPIP_00082*/
typedef uint8 TcpIp_IpAddrStateType;

typedef uint8 TcpIp_LocalAddrAssignmentIdType;
typedef uint8 TcpIp_LocalAddrAssignmentStatusType; /*for bitfield*/
/*ECUC_TcpIp_00186*/ /*ECUC_TcpIp_00035*/ /*ECUC_TcpIp_00036*/
typedef uint8 TcpIp_LocalAddrAssignmentConfigType;

typedef uint8 TcpIp_StaticAddrIdType;
typedef struct
{
    uint8 State;
    /*ECUC_TcpIp_00039*/
    uint8 Netmask; /* 0-128 */
    TcpIp_DomainType Domain;
    /*ECUC_TcpIp_00038*/
    TcpIp_IpAddressType IpAddr;
    /*ECUC_TcpIp_00040*/
    TcpIp_IpAddressType DefaultRouter;
} TcpIp_StaticIpAddrType;
/*
#define TCPIP_STATICIP_STATE_INVALID            (0)
#define TCPIP_STATICIP_STATE_VALID              (1)
#define TCPIP_STATICIP_STATE_VALID_ANY          (2)
*/

/*SWS_TCPIP_00134*/
typedef uint16 TcpIp_PortWildcardType;

/*SWS_TCPIP_00030*/
typedef uint8 TcpIp_LocalAddrIdType;
/*SWS_TCPIP_00135*/
typedef TcpIp_LocalAddrIdType TcpIp_LocalAddrIdWildcardType;

/*SWS_TCPIP_00073*/ /*SWS_TCPIP_00083*/
typedef uint8 TcpIp_StateType;

/*ECUC_TcpIp_00172*/
typedef struct
{
    /*SWS_TCPIP_00223*/ /*Up_RxIndication*/
    P2FUNC(void, AUTOMATIC, RxIndication)
    (
        TcpIp_SocketIdType SocketId,
        P2CONST(TcpIp_SockAddrType, AUTOMATIC, AUTOMATIC) RemoteAddrPtr,
        P2VAR(uint8, AUTOMATIC, AUTOMATIC) BufPtr,
        uint16 Length
    );
    /*SWS_TCPIP_00224*/ /*Up_TcpIpEvent*/
    P2FUNC(void, AUTOMATIC, TcpIpEvent)
    (
        TcpIp_SocketIdType SocketId,
        TcpIp_EventType Event
    );
    /*SWS_TCPIP_00225*/ /*Up_TxConfirmation*/
    P2FUNC(void, AUTOMATIC, TxConfirmation)
    (
        TcpIp_SocketIdType SocketId,
        uint16 Length
    );
    /*SWS_TCPIP_00226*/ /*Up_TcpAccepted*/
    P2FUNC(Std_ReturnType, AUTOMATIC, TcpAccepted)
    (
        TcpIp_SocketIdType SocketId,
        TcpIp_SocketIdType SocketIdConnected,
        P2CONST(TcpIp_SockAddrType, AUTOMATIC, AUTOMATIC) RemoteAddrPtr
    );
    /*SWS_TCPIP_00227*/ /*Up_TcpConnected*/
    P2FUNC(void, AUTOMATIC, TcpConnected)
    (
        TcpIp_SocketIdType SocketId
    );
    /*SWS_TCPIP_00228*/ /*Up_CopyTxData*/
    P2FUNC(BufReq_ReturnType, AUTOMATIC, CopyTxData)
    (
        TcpIp_SocketIdType SocketId,
        P2VAR(uint8, AUTOMATIC, AUTOMATIC) BufPtr,
        uint16 BufLength
    );
    /*SWS_TCPIP_00229*/ /*Up_LocalIpAddrAssignmentChg*/
    P2FUNC(void, AUTOMATIC, LocalIpAddrAssignmentChg)
    (
        TcpIp_LocalAddrIdType IpAddrId,
        TcpIp_IpAddrStateType State
    );
} TcpIp_UpLayerInterfaceType;

/*ECUC_TcpIp_00020*/
typedef struct
{
    /*ECUC_TcpIp_00032*/
    TcpIp_CtrlIdType CtrlId;    /*NetIfCtrl's ID*/
    /*ECUC_TcpIp_00031*/
    TcpIp_AddressType Address;
    /*ECUC_TcpIp_00030*/
    TcpIp_DomainType Domain;
    /*ECUC_TcpIp_00034*/
    TcpIp_StaticAddrIdType StaticAddrId;
    /*ECUC_TcpIp_00033*/ /*ECUC_TcpIp_00037*/
    TcpIp_LocalAddrAssignmentConfigType Assignments[TCPIP_LOCALADDR_ASSIGNMENT_PRIORITY_MAX];
} TcpIp_LocalAddrConfigType;

typedef struct
{
    /*ECUC_TcpIp_00097*/
    uint8 ArpConfigId;
    /*ECUC_TcpIp_00100*/
    uint8 DHCPConfigId;
    /*ECUC_TcpIp_00098*/ /*ECUC_TcpIp_00074*/
    /*
     *  65535   - NO AutoIp
     *  0       - immediately start AutoIp
     *  other   - wait timeout
     */
    uint16 AutoIpInitTimeout;
} TcpIp_IpV4CtrlConfigType;

/*ECUC_TcpIp_00021*/
typedef struct
{
    /*ECUC_TcpIp_00041*/
    uint8 CtrlIdx; /*EthIf Ctrl Index*/
    /*ECUC_TcpIp_00081*/
    uint8 FramePrio;
    TcpIp_LocalAddrIdType UnicastAddrId;    /*must be the first local address Id*/
    TcpIp_LocalAddrIdType UnicastAddrLimit; /*IPv6 may have multiple unicast address*/
    TcpIp_LocalAddrIdType MulticastAddrId;  /*equal to LocalAddrLimit if this NetCtrl do not have multicast address*/
    TcpIp_LocalAddrIdType LocalAddrLimit;
    /*ECUC_TcpIp_00094*/
    /*ECUC_TcpIp_00166*/
    uint8 IpV4CtrlId;
    /*ECUC_TcpIp_00096*/
    uint8 IpV6CtrlId;
} TcpIp_NetIfCtrlConfigType;

typedef struct
{
    P2CONST(TcpIp_NetIfCtrlConfigType, TCPIP_CONFIG_DATA, AUTOMATIC) NetIfCtrlPtr;
    P2CONST(TcpIp_IpV4CtrlConfigType, TCPIP_CONFIG_DATA, AUTOMATIC) IpV4CtrlPtr;
    P2CONST(TcpIp_LocalAddrConfigType, TCPIP_CONFIG_DATA, AUTOMATIC) LocalAddrPtr;
    P2CONST(TcpIp_StaticIpAddrType, TCPIP_CONFIG_DATA, AUTOMATIC) StaticIpAddrPtr;
} TcpIp_ConfigType;

#endif /* _TCPIP_TYPES_H_ */
