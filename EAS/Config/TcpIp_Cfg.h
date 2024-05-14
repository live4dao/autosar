/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : TcpIp_Cfg.h
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
#ifndef _TCPIP_CFG_H_
#define _TCPIP_CFG_H_
/*******************************************************************************
*   Include  
*******************************************************************************/
#include "TcpIp_Types.h"
#include "SoAd_Cbk.h"
/*******************************************************************************
*   General  
*******************************************************************************/
#define TCPIP_ETHSM_ENABLED                                 STD_ON
#define TCPIP_CONFIG_VARIANTS                               STD_CONFIG_VARIANTS_PRECOMPILE
#define TCPIP_VERSION_INFO_API                              STD_OFF
#define TCPIP_VERSION_CHECK                                 STD_ON
#define TCPIP_TX_BUFFER_SIZE                                16000
#define TCPIP_RX_BUFFER_SIZE                                576
#define TCPIP_RX_BUFFER_NUM                                 10
#define TCPIP_DEV_ERROR_DETECT                              STD_ON
#define TCPIP_MAIN_FUNCTION_PERIOD                          5
#define TCPIP_PROVIDE_SYSTEM_TIME                           STD_ON
#define TCPIP_RESET_IPASSIGNMENT_API                        STD_OFF
#define TCPIP_SCALABILITY_CLASS                             TCPIP_SCALABILITY_CLASS_1
#define TCPIP_DHCP_SERVER_ENABLED                           STD_OFF
#define TCPIP_TCP_ENABLED                                   STD_ON
#define TCPIP_TCP_SOCKET_LISTEN_MAX                         5
#define TCPIP_TCP_SOCKET_CLIENT_MAX                         10
#define TCPIP_TCP_SOCKET_MAX                                (TCPIP_TCP_SOCKET_CLIENT_MAX + TCPIP_TCP_SOCKET_LISTEN_MAX)

#define TCPIP_TCP_NAGLE_ENABLED                             STD_ON
#define TCPIP_TCP_SLOW_START_ENABLED                        STD_ON
#define TCPIP_TCP_CONGESTION_AVOIDANCE_ENABLED              STD_ON
#define TCPIP_TCP_FAST_RETRANSMIT_ENABLED                   STD_ON
#define TCPIP_TCP_FAST_RECOVERY_ENABLED                     STD_ON
#define TCPIP_TCP_FINWAIT2_TIMEOUT                          20
#define TCPIP_TCP_MSL                                       120000
#define TCPIP_TCP_MSS                                       1460
#define TCPIP_TCP_RECEIVE_WINDOW_MAX                        4096
#define TCPIP_TCP_KEEP_ALIVE_ENABLED                        STD_OFF
#define TCPIP_TCP_KEEP_ALIVE_INTERVAL                       75
#define TCPIP_TCP_KEEP_ALIVE_PROBES_MAX                     0
#define TCPIP_TCP_KEEP_ALIVE_TIME                           7200
#define TCPIP_TCP_RETRANSMISSION_TIMEOUT                    500
#define TCPIP_TCP_RETRANSMISSION_MAX                        3
#define TCPIP_TCP_SYN_RETRANSMISSION_MAX                    3
#define TCPIP_TCP_SYN_RECEIVED_TIMEOUT                      20
#define TCPIP_TCP_TTL                                       255
#define TCPIP_UDP_ENABLED                                   STD_ON
#define TCPIP_UDP_SOCKET_MAX                                5
#define TCPIP_UDP_TTL                                       255
#define TCPIP_UDP_RX_DATAGRAM_LENGTH_MAX                    0
#define TCPIP_IPV4_ENABLED                                  STD_ON
#define TCPIP_IPFRAGMENTATION_RX_ENABLED                    STD_OFF
#define TCPIP_ARP_ENABLED                                   STD_ON
#define TCPIP_ARP_CONFIG_MAX                                1
#define TCPIP_ARP_GRATUITOUS_ARP_MAX                        1
#define TCPIP_ARP_PACKET_QUEUE_ENABLED                      STD_ON
#define TCPIP_ARP_TABLE_ENTRY_TIMEOUT                       120000
#define TCPIP_ARP_TABLE_SIZE_MAX                            10
#define TCPIP_DHCP_CLIENT_ENABLED                           STD_OFF
#define TCPIP_DHCP_CONFIG_MAX                               0
#define TCPIP_DHCP_CLIENT_MAX                               0
#define TCPIP_AUTOIP_ENABLED                                STD_OFF
#define TCPIP_AUTOIP_CLIENT_MAX                             0
#define TCPIP_ICMP_ENABLED                                  STD_ON
#define TCPIP_ICMP_TTL                                      255
#define TCPIP_IGMP_ENABLED                                  STD_OFF
#define TCPIP_IGMP_GROUP_MAX                                0
#define TCPIP_PATH_MTU_DISCOVERY_ENABLED                    STD_OFF
#define TCPIP_LOCALADDR_IPV4_TABLE_SIZE                     1
#define TCPIP_IPV6_ENABLED                                  STD_OFF
#define TCPIP_DHCPV6_CLIENT_ENABLED                         STD_OFF
#define TCPIP_IPV6_PATH_MTU_DISCOVERY_ENABLED               STD_OFF
#define TCPIP_IPV6_NDP_ARUD_ENABLED                         STD_OFF
#define TCPIP_IPV6_NDP_PARD_ENABLED                         STD_OFF
#define TCPIP_LOCALADDR_IPV6_TABLE_SIZE                     0
#define TCPIP_LOCALADDR_TABLE_MAX                           TCPIP_LOCALADDR_IPV4_TABLE_SIZE
#define TCPIP_STATIC_IPADDR_MAX                             1
#define TCPIP_NETIF_CTRL_MAX                                1
#define TCPIP_IPV4_CTRL_MAX                                 1

#define TCPIP_PHYSADDR_CHGHANDLER
#define TCPIP_RX_FIFO_SIZE                                  128
#define TCPIP_HARDWARE_MAC_0                                (0)
#define TCPIP_HARDWARE_MAC_1                                (0x11)
#define TCPIP_HARDWARE_MAC_2                                (0x22)
#define TCPIP_HARDWARE_MAC_3                                (0x33)
#define TCPIP_HARDWARE_MAC_4                                (0x44)
#define TCPIP_HARDWARE_MAC_5_BASE                           (0x0)

#define TCPIP_SW_MAJOR_VERSION_CFG                          2
#define TCPIP_SW_MINOR_VERSION_CFG                          2
#define TCPIP_SW_PATCH_VERSION_CFG                          0
#define TCPIP_AR_RELEASE_MAJOR_VERSION_CFG                  4
#define TCPIP_AR_RELEASE_MINOR_VERSION_CFG                  2
#define TCPIP_AR_RELEASE_REVISION_VERSION_CFG               2

#define TCPIP_UPLAYER_RXINDICATION(s, r, d, l)              SoAd_RxIndication(s, r, d, l)
#define TCPIP_UPLAYER_TCPIPEVENT(s, e)                      SoAd_TcpIpEvent(s, e)
#define TCPIP_UPLAYER_TXCONFIRMATION(s, l)                  SoAd_TxConfirmation(s, l)
#define TCPIP_UPLAYER_TCPACCEPTED(s, n, r)                  SoAd_TcpAccepted(s, n, r)
#define TCPIP_UPLAYER_TCPCONNECTED(s)                       SoAd_TcpConnected(s)
#define TCPIP_UPLAYER_COPYTXDATA(s, b, l)                   SoAd_CopyTxData(s, b, l)
#define TCPIP_UPLAYER_IPADDRASSIGNMENTCHG(i, s)             SoAd_LocalIpAddrAssignmentChg(i, s)


#define TCPIP_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"
extern CONST(TcpIp_NetIfCtrlConfigType, TCPIP_CONST) TcpIp_NetIfCtrlConfigs[];
extern CONST(TcpIp_IpV4CtrlConfigType, TCPIP_CONST) TcpIp_IpV4CtrlConfigs[];
extern CONST(TcpIp_LocalAddrConfigType, TCPIP_CONST) TcpIp_LocalAddrConfigs[];
extern CONST(TcpIp_StaticIpAddrType, TCPIP_CONST) TcpIp_StaticIpAddrConfigs[];
#define TCPIP_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"


#define TCPIP_START_SEC_VAR_32
#include "MemMap.h"
extern VAR(uint32, TCPIP_VAR) TcpIp_SystemTime;
#define TCPIP_STOP_SEC_VAR_32
#include "MemMap.h"


#endif /* _TCPIP_CFG_H_ */ 
