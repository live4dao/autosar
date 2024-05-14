/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : TcpIp_GeneratedTypes.h
********************************************************************************
*   Project/Product : AUTOSAR BSW PROJECT
*   Title           : TcpIp module configuration File
*   Author          : Hirain
********************************************************************************
*   Description     : TcpIp module configuration File
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
*   V1.0.0_3.5.5_AZ240046       27/03/2024    Eas           N/A          N/A
*
********************************************************************************
* END_FILE_HDR*/
#ifndef _TCPIP_GENERATED_TYPES_H_
#define _TCPIP_GENERATED_TYPES_H_
/*******************************************************************************
*   Include  
*******************************************************************************/
#include "ComStack_Types.h"
/*******************************************************************************
*   Macro  
*******************************************************************************/
#define TCPIP_IPADDR_ANY                (0)
#define TCPIP_IP6ADDR_ANY               (0)
#define TCPIP_SOCKETID_INVALID          ((TcpIp_SocketIdType)0xFF)
#define TCPIP_SET_ANY_IPADDR(ip)        ((ip)->Addr[0] = TCPIP_IPADDR_ANY)

#define TCPIP_COPY_SOCKADDR(dest, src)  do{\
                                            (dest)->Domain = (src)->Domain;\
                                            (dest)->Port = (src)->Port;\
                                            (dest)->Addr[0] = (src)->Addr[0];\
                                        } while(0)
#define TCPIP_UPLAYER_SoAd          ((TcpIp_UpLayerIndexType)0)
#define TcpIp_SoAdGetSocket(d,p,s)     TcpIp_GetSocket(d, p, TCPIP_UPLAYER_SoAd, s)
#define TCPIP_UPLAYER_MAX         (1)
/*******************************************************************************
*   Types Declaration  
*******************************************************************************/
typedef uint8  TcpIp_SocketIdType;
typedef uint8  TcpIp_UpLayerIndexType;
typedef struct
{
    uint32 Addr[1];
} TcpIp_IpAddressType;

typedef uint32 TcpIp_IpAddrWildcardType;

typedef uint32 TcpIp_Ip6AddrWildcardType;

typedef uint16 TcpIp_DomainType;

typedef struct
{
    TcpIp_DomainType Domain;
} TcpIp_SockAddrType;

typedef struct
{
    TcpIp_DomainType Domain;
    uint16 Port;
    uint32 Addr[1];
} TcpIp_SockAddrInetType;

typedef struct
{
    TcpIp_DomainType Domain;
    uint16 Port;
    uint32 Addr[4];
} TcpIp_SockAddrInet6Type;

typedef TcpIp_SockAddrInetType TcpIp_SockAddrRealType;


#endif /* _TCPIP_GENERATED_TYPES_H_ */ 
