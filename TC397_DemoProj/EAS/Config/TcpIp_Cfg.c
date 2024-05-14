/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : TcpIp_Cfg.c
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
*   V1.0.0_3.5.5_AZ240046       16/04/2024    Eas           N/A          N/A
*
********************************************************************************
* END_FILE_HDR*/
/*******************************************************************************
*   Include  
*******************************************************************************/
#include "TcpIp_Types.h"
#include "TcpIp_Cfg.h"
#include "EthIf_Cfg.h"


#define TCPIP_MAKE_IPV4(a, b, c, d)                         ((((a) << 24) & 0xFF000000)\
                                                | (((b) << 16) & 0x00FF0000)\
                                                | (((c) <<  8) & 0x0000FF00)\
                                                | (((d) <<  0) & 0x000000FF))


#define TCPIP_MAKE_ASSIGNMENT_CONFIG(m, t)                  (((m) & TCPIP_LOCALADDR_ASSIGNMENT_METHOD_MASK)\
                                                | ((t) & TCPIP_LOCALADDR_ASSIGNMENT_TRIGGER_MASK))


#define TCPIP_START_SEC_VAR_32
#include "MemMap.h"

VAR(uint32, TCPIP_VAR) TcpIp_SystemTime = 0;

#define TCPIP_STOP_SEC_VAR_32
#include "MemMap.h"

#define TCPIP_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"

CONST(TcpIp_NetIfCtrlConfigType, TCPIP_CONST) TcpIp_NetIfCtrlConfigs[TCPIP_NETIF_CTRL_MAX] = 
{
    {EthIf_EthIfController0, 0,0, 1, 1, 1, 0, 0},
};

CONST(TcpIp_IpV4CtrlConfigType, TCPIP_CONST) TcpIp_IpV4CtrlConfigs[TCPIP_IPV4_CTRL_MAX] = 
{
    {0, 0xFF, 65535},
};
CONST(TcpIp_LocalAddrConfigType, TCPIP_CONST) TcpIp_LocalAddrConfigs[TCPIP_LOCALADDR_TABLE_MAX] = 
{
    {
        0, TCPIP_UNICAST, TCPIP_AF_INET, 0, 
        {
            TCPIP_MAKE_ASSIGNMENT_CONFIG(TCPIP_IPADDR_ASSIGNMENT_STATIC  , TCPIP_AUTOMATIC),
            TCPIP_LOCALADDR_ASSIGNMENT_CONFIG_INVALID,
            TCPIP_LOCALADDR_ASSIGNMENT_CONFIG_INVALID,
        }
    },
};
CONST(TcpIp_StaticIpAddrType, TCPIP_CONST) TcpIp_StaticIpAddrConfigs[TCPIP_STATIC_IPADDR_MAX] = 
{
    {0, 24, TCPIP_AF_INET, {{TCPIP_MAKE_IPV4(0xC0, 0xA8, 0x06, 0x64)}}, {{TCPIP_MAKE_IPV4(0xC0, 0xA8, 0x06, 0x5A)}}    },
};


#define TCPIP_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"