/*  BEGIN_FILE_HDR

********************************************************************************
*   NOTICE                             
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
*   File Name       : TcpIp.c
********************************************************************************
*   Project/Product : AUTOSAR 4.2
*   Title           : The TcpIp Stack
*   Author          : mingqing.tang
********************************************************************************
*   Description     : The core file of the TcpIp module.
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
*   02.01.10    03/09/2019    beibei.xing     N/A          ETH422_TcpIp_20190903_01
*   02.01.11    21/10/2019    beibei.xing     N/A          ETH422_TcpIp_20191021_01
*   02.01.12    03/09/2019    qiang.yang      N/A          ETH422_TcpIp_20191122_01
*   02.01.13    06/12/2019    mingqing.tang   N/A          ETH422_TcpIp_20191206_01
*   02.01.14    27/05/2020    mingqing.tang   N/A          ETH422_TcpIp_20200527_01
*   02.01.15    04/09/2020    mingqing.tang   N/A          ETH422_TcpIp_20200904_01
*   02.01.16    04/09/2020    hao.liu         N/A          ETH422_TcpIp_20200929_01
*   02.01.17    25/04/2021    hao.liu         N/A          ETH422_TcpIp_20210425_01
*   02.01.18    26/10/2021    Zeyu.Ren        N/A          ETH422_TcpIp_20211026_01
*   02.01.19    26/10/2021    Zeyu.Ren        N/A          ETH422_TcpIp_20220711_01
*   02.01.21    30/01/2023    Zeyu.Ren        N/A          ETH422_TcpIp_20230130_01
*   02.01.22    06/03/2023    Zeyu.Ren        N/A          ETH422_TcpIp_20230306_01
*   02.01.23    21/01/2023    yanheng.he      N/A          TCP/IP QAC
*   02.01.24    13/07/2023    yanheng.he      N/A          Fix: Call tcp_free() multiple times causes a list loop.
*   02.01.25    31/10/2023    yanheng.he      N/A          ETH422_TcpIp_20231031_01
*   02.02.00    31/10/2023    yanheng.he      N/A          ETH422_TcpIp_20231213_01
********************************************************************************
* END_FILE_HDR*/

/******************************************************************************
*   General QAC Suppression
******************************************************************************/
/*PRQA S 3120 EOF*/
/* An integer constant has been used. */

/*PRQA S 3141 EOF*/
/* SchM_Exit_TcpIp_TCPIP_EXCLUSIVE_AREA will be used or not, a marco maybe has a NULL statement. */

/*PRQA S 3214 EOF*/
/* A marco is defined and not used ,but reserve for the future. */

/*PRQA S 3416 EOF*/
/* Logical operation performed. */

/*PRQA S 3432 EOF*/
/* Using eg.P2CONST,P2VAR. */

/*PRQA S 315,316,317,326 EOF*/
/* Cast between void* and type*. */

/*PRQA S 1338 EOF*/
/* Modify the parameter of function. */

/*PRQA S 1881 EOF*/
/* Using equality operator between enum and signed. */

/*PRQA S 3383 EOF*/
/* Data use is under control. */

/*******************************************************************************
*   Includes
*******************************************************************************/
/* PRQA S 857 ++ */
/* Number of macro definitions exceeds 1024 */
#include "TcpIp.h"
#include "TcpIp_Cfg.h"
#include "EthIf.h"
#include "SchM_TcpIp.h"

#if (TCPIP_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"
#endif

#if (TCPIP_ETHSM_ENABLED == STD_ON)
#include "EthSM_Cbk.h"
#endif

#if (TCPIP_IGMP_ENABLED == STD_ON)
#include "lwip/igmp.h"
#endif

#if (TCPIP_DHCP_CLIENT_ENABLED == STD_ON)
#include "lwip/dhcp.h"
#endif

#if (TCPIP_AUTOIP_ENABLED == STD_ON)
#include "lwip/autoip.h"
#endif

#include "lwip/netif.h"
#include "lwip/etharp.h"
#include "lwip/tcp.h"
#include "lwip/udp.h"
#include "lwip/def.h"
#include "lwip/mem.h"
#include "lwip/err.h"
#include "lwip/init.h"
#include "lwip/ip_addr.h"
#include "lwip/timeouts.h"

#include "netif/ethernet.h"
/* PRQA S 857 -- */
/*******************************************************************************
*   Check
*******************************************************************************/

#if((TCPIP_AR_RELEASE_MAJOR_VERSION != TCPIP_AR_RELEASE_MAJOR_VERSION_CFG)\
    || (TCPIP_AR_RELEASE_MINOR_VERSION != TCPIP_AR_RELEASE_MINOR_VERSION_CFG))
#error "The AUTOSAR version of TcpIp module and its configuration file are different."
#endif

#if((TCPIP_SW_MAJOR_VERSION != TCPIP_SW_MAJOR_VERSION_CFG)\
    || (TCPIP_SW_MINOR_VERSION != TCPIP_SW_MINOR_VERSION_CFG))
#error "The Software version of TcpIp module and its configuration file are different."
#endif

#if (TCPIP_SCALABILITY_CLASS != TCPIP_SCALABILITY_CLASS_1)
#error "Only IPv4 is supported."
#endif

#if ((TCPIP_SCALABILITY_CLASS == TCPIP_SCALABILITY_CLASS_1) && (TCPIP_IPV6_ENABLED == STD_ON))
#error "Only IPv4 is supported."
#endif

#if ((TCPIP_SCALABILITY_CLASS == TCPIP_SCALABILITY_CLASS_1) && (TCPIP_IPV4_ENABLED == STD_OFF))
#error "The TcpIp module needs IPV4 when TCPIP_SCALABILITY_CLASS is TCPIP_SCALABILITY_CLASS_1."
#endif

#if ((TCPIP_SCALABILITY_CLASS == TCPIP_SCALABILITY_CLASS_2) && (TCPIP_IPV4_ENABLED == STD_ON))
#error "Only IPv6 is supported."
#endif

#if ((TCPIP_SCALABILITY_CLASS == TCPIP_SCALABILITY_CLASS_2) && (TCPIP_IPV6_ENABLED == STD_OFF))
#error "The TcpIp module needs IPV6 when TCPIP_SCALABILITY_CLASS is TCPIP_SCALABILITY_CLASS_2."
#endif

#if ((TCPIP_SCALABILITY_CLASS == TCPIP_SCALABILITY_CLASS_3) && ((TCPIP_IPV6_ENABLED == STD_OFF) || (TCPIP_IPV4_ENABLED == STD_OFF)))
#error "The TcpIp module needs IPV6 and IPV4 when TCPIP_SCALABILITY_CLASS is TCPIP_SCALABILITY_CLASS_3."
#endif

#if ((TCPIP_AUTOIP_ENABLED == STD_ON) && (TCPIP_ARP_ENABLED == STD_OFF))
#error "the Auto-IP use the ARP to probe linklocal IP address."
#endif

#if ((TCPIP_DHCP_CLIENT_ENABLED == STD_ON) && (TCPIP_UDP_ENABLED == STD_OFF))
#error "the DHCP use the UDP to request dynamic IP address."
#endif

#if ((TCPIP_IGMP_ENABLED == STD_ON) && (TCPIP_UDP_ENABLED == STD_OFF))
#error "Only UDP can receive multicast ethernet frame."
#endif

#if ((TCPIP_UDP_ENABLED == STD_OFF) && (TCPIP_TCP_ENABLED == STD_OFF))
#error "Are you sure?"
#endif

#if (TCPIP_LOCALADDR_ASSIGNMENT_PRIORITY_MAX > 8)
#error "The assignment priority must be less than eight."
#endif

#if (TCPIP_UPLAYER_MAX <= 0)
#error "The TcpIp module needs a UpLayer."
#endif

#if (TCPIP_NETIF_CTRL_MAX <= 0)
#error "The TcpIp module needs a EthIf controller."
#endif
/*PRQA S 4588 ++*/
/* Using signed with "&" */
#if (((TCPIP_RX_FIFO_SIZE - 1) & TCPIP_RX_FIFO_SIZE) != 0)
#error "The size of RX fifo must be the power of 2."
#endif
/*PRQA S 4588 --*/
#if (TCPIP_RX_FIFO_SIZE < 16)
#error "The size of RX fifo must be greater than 16."
#endif

#if (TCPIP_RX_FIFO_SIZE >= 65536)
#error "The size of RX fifo must be less than 65536."
#endif


/*******************************************************************************
*   Macro
*******************************************************************************/
/*PRQA S 3429,3453 ++*/
/* A function-like macro is being defined. */
#define TCPIP_UNUSED(dummy)                             ((void)(dummy))
/*PRQA S 3435,3436,3456 ++*/
/* Parameter occurs more than once in marco. */
#define TCPIP_MIN(a, b)                                 (((a) < (b)) ? (a): (b))

#define TCPIP_VOIDPTR_TO_UINT(ptr)                      ((uint32)(ptr))

#define TCPIP_IS_UNINITIALIZED()                        (TcpIp_Initialized != STD_INITIALIZED)

#define TCPIP_RXINDICATION_MAX                          16

#define TCPIP_MAKE_TIMEOUT(timeout)                     ((timeout)/TCPIP_MAIN_FUNCTION_PERIOD)

#if (TCPIP_PROVIDE_SYSTEM_TIME == STD_ON)
#define TCPIP_RESET_SYSTEM_TIME()                       (TcpIp_SystemTime = (uint32)0)
#define TCPIP_ADD_SYSTEM_TIME()                         (TcpIp_SystemTime += (uint32)TCPIP_MAIN_FUNCTION_PERIOD)
#else
#define TCPIP_RESET_SYSTEM_TIME()
#define TCPIP_ADD_SYSTEM_TIME()
#endif

#if (TCPIP_DEV_ERROR_DETECT == STD_ON)

#define TCPIP_DET_REPORT_ERROR(api, err)                DET_REPORT_ERROR(\
                                                            (uint16)TCPIP_MODULE_ID,\
                                                            (uint8)TCPIP_INSTANCE_ID,\
                                                           (uint8)(api),\
                                                           (uint8)(err))

#else
#define TCPIP_DET_REPORT_ERROR(api, err)
#endif /*TCPIP_DEV_ERROR_DETECT == STD_ON*/

/*UpLayer*/
#if ((TCPIP_UPLAYER_MAX == 1) && (TCPIP_CONFIG_VARIANTS == STD_CONFIG_VARIANTS_PRECOMPILE))
#define TCPIP_UPLAYER_CALL_RXINDICATION(up, so, addr, buf, len) TCPIP_UPLAYER_RXINDICATION(so, addr, buf, len)
#define TCPIP_UPLAYER_CALL_TCPIPEVENT(up, so, event)            TCPIP_UPLAYER_TCPIPEVENT(so, event)
#define TCPIP_UPLAYER_CALL_TXCONFIRMATION(up, so, len)          TCPIP_UPLAYER_TXCONFIRMATION(so, len)
#define TCPIP_UPLAYER_CALL_TCPACCEPTED(up, so, newso, addr)     TCPIP_UPLAYER_TCPACCEPTED(so, newso, addr)
#define TCPIP_UPLAYER_CALL_TCPCONNECTED(up, so)                 TCPIP_UPLAYER_TCPCONNECTED(so)
#define TCPIP_UPLAYER_CALL_COPYTXDATA(up, so, buf, len)         TCPIP_UPLAYER_COPYTXDATA(so, buf, len)
#define TCPIP_UPLAYER_CALL_IPADDRASSIGNMENTCHG(up, id, sta)     TCPIP_UPLAYER_IPADDRASSIGNMENTCHG(id, sta)

#define TCPIP_LOCALADDR_NOTIFY_STATE(id, sta)                   TCPIP_UPLAYER_IPADDRASSIGNMENTCHG(id, sta)
#else /*TCPIP_UPLAYER_MAX > 1*/
#define TCPIP_UPLAYER_GET_INTERFACE(up)                         (&TcpIp_UpLayerInterfaces[up])

#define TCPIP_UPLAYER_CALL_RXINDICATION(up, so, addr, buf, len) TCPIP_UPLAYER_GET_INTERFACE(up)->RxIndication(so, addr, buf, len)
#define TCPIP_UPLAYER_CALL_TCPIPEVENT(up, so, event)            TCPIP_UPLAYER_GET_INTERFACE(up)->TcpIpEvent(so, event)
#define TCPIP_UPLAYER_CALL_TXCONFIRMATION(up, so, len)          TCPIP_UPLAYER_GET_INTERFACE(up)->TxConfirmation(so, len)
#define TCPIP_UPLAYER_CALL_TCPACCEPTED(up, so, newso, addr)     TCPIP_UPLAYER_GET_INTERFACE(up)->TcpAccepted(so, newso, addr)
#define TCPIP_UPLAYER_CALL_TCPCONNECTED(up, so)                 TCPIP_UPLAYER_GET_INTERFACE(up)->TcpConnected(so)
#define TCPIP_UPLAYER_CALL_COPYTXDATA(up, so, buf, len)         TCPIP_UPLAYER_GET_INTERFACE(up)->CopyTxData(so, buf, len)
#define TCPIP_UPLAYER_CALL_IPADDRASSIGNMENTCHG(up, id, sta)     TCPIP_UPLAYER_GET_INTERFACE(up)->LocalIpAddrAssignmentChg(id, sta)

#define TCPIP_LOCALADDR_NOTIFY_STATE(id, sta)                   TcpIp__LocalIpAddrAssignmentChg(id, sta)
#endif /*(TCPIP_UPLAYER_MAX == 1) && (TCPIP_CONFIG_VARIANTS == STD_CONFIG_VARIANTS_PRECOMPILE)*/


/*Socket Manager*/
#define TCPIP_SOCKET_STATE_IDLE                 ((TcpIp_SocketStatetype)0)
#define TCPIP_SOCKET_STATE_CONNECT              ((TcpIp_SocketStatetype)1)
#define TCPIP_SOCKET_STATE_CONNECTING           ((TcpIp_SocketStatetype)2)
#define TCPIP_SOCKET_STATE_CONNECTED            ((TcpIp_SocketStatetype)3)
#define TCPIP_SOCKET_STATE_LISTEN               ((TcpIp_SocketStatetype)4)
#define TCPIP_SOCKET_STATE_LISTENING            ((TcpIp_SocketStatetype)5)
#define TCPIP_SOCKET_STATE_WAITCLOSE            ((TcpIp_SocketStatetype)6)
#define TCPIP_SOCKET_STATE_CLOSE                ((TcpIp_SocketStatetype)7)
#define TCPIP_SOCKET_STATE_CLOSING              ((TcpIp_SocketStatetype)8)
#define TCPIP_SOCKET_STATE_CLOSED               ((TcpIp_SocketStatetype)9)
#define TCPIP_SOCKET_STATE_CLOSE_LISTEN         ((TcpIp_SocketStatetype)10)

#define TCPIP_SOCKET_GET_STATE(socket)          ((socket)->State)
#define TCPIP_SOCKET_SET_STATE(socket, sta)     (TCPIP_SOCKET_GET_STATE(socket) = (sta))

#define TCPIP_SOCKET_SET_IDLE(socket)           TCPIP_SOCKET_SET_STATE(socket, TCPIP_SOCKET_STATE_IDLE)
#define TCPIP_SOCKET_SET_CONNECT(socket)        TCPIP_SOCKET_SET_STATE(socket, TCPIP_SOCKET_STATE_CONNECT)
#define TCPIP_SOCKET_SET_CONNECTING(socket)     TCPIP_SOCKET_SET_STATE(socket, TCPIP_SOCKET_STATE_CONNECTING)
#define TCPIP_SOCKET_SET_CONNECTED(socket)      TCPIP_SOCKET_SET_STATE(socket, TCPIP_SOCKET_STATE_CONNECTED)
#define TCPIP_SOCKET_SET_LISTEN(socket)         TCPIP_SOCKET_SET_STATE(socket, TCPIP_SOCKET_STATE_LISTEN)
#define TCPIP_SOCKET_SET_LISTENING(socket)      TCPIP_SOCKET_SET_STATE(socket, TCPIP_SOCKET_STATE_LISTENING)
#define TCPIP_SOCKET_SET_WAITCLOSE(socket)      TCPIP_SOCKET_SET_STATE(socket, TCPIP_SOCKET_STATE_WAITCLOSE)
#define TCPIP_SOCKET_SET_CLOSE(socket)          TCPIP_SOCKET_SET_STATE(socket, TCPIP_SOCKET_STATE_CLOSE)
#define TCPIP_SOCKET_SET_CLOSING(socket)        TCPIP_SOCKET_SET_STATE(socket, TCPIP_SOCKET_STATE_CLOSING)
#define TCPIP_SOCKET_SET_CLOSED(socket)         TCPIP_SOCKET_SET_STATE(socket, TCPIP_SOCKET_STATE_CLOSED)
#define TCPIP_SOCKET_SET_CLOSE_LISTEN(socket)   TCPIP_SOCKET_SET_STATE(socket, TCPIP_SOCKET_STATE_CLOSE_LISTEN)

#define TCPIP_SOCKET_IS_STATE(socket, sta)      (TCPIP_SOCKET_GET_STATE(socket) == (sta))
#define TCPIP_SOCKET_IS_IDLE(socket)            TCPIP_SOCKET_IS_STATE(socket, TCPIP_SOCKET_STATE_IDLE)
#define TCPIP_SOCKET_IS_CONNECT(socket)         TCPIP_SOCKET_IS_STATE(socket, TCPIP_SOCKET_STATE_CONNECT)
#define TCPIP_SOCKET_IS_CONNECTING(socket)      TCPIP_SOCKET_IS_STATE(socket, TCPIP_SOCKET_STATE_CONNECTING)
#define TCPIP_SOCKET_IS_CONNECTED(socket)       TCPIP_SOCKET_IS_STATE(socket, TCPIP_SOCKET_STATE_CONNECTED)
#define TCPIP_SOCKET_IS_LISTEN(socket)          TCPIP_SOCKET_IS_STATE(socket, TCPIP_SOCKET_STATE_LISTEN)
#define TCPIP_SOCKET_IS_LISTENING(socket)       TCPIP_SOCKET_IS_STATE(socket, TCPIP_SOCKET_STATE_LISTENING)
#define TCPIP_SOCKET_IS_WAITCLOSE(socket)       TCPIP_SOCKET_IS_STATE(socket, TCPIP_SOCKET_STATE_WAITCLOSE)
#define TCPIP_SOCKET_IS_CLOSE(socket)           TCPIP_SOCKET_IS_STATE(socket, TCPIP_SOCKET_STATE_CLOSE)
#define TCPIP_SOCKET_IS_CLOSING(socket)         TCPIP_SOCKET_IS_STATE(socket, TCPIP_SOCKET_STATE_CLOSING)
#define TCPIP_SOCKET_IS_CLOSED(socket)          TCPIP_SOCKET_IS_STATE(socket, TCPIP_SOCKET_STATE_CLOSED)
#define TCPIP_SOCKET_IS_CLOSE_LISTEN(socket)    TCPIP_SOCKET_IS_STATE(socket, TCPIP_SOCKET_STATE_CLOSE_LISTEN)

#define TCPIP_TXBUFFER_HEAD_SIZE                (sizeof(TcpIp_TcpTxBufferHeadType))


#define TCPIP_SOCKET_GET_TCPCONTEXT(id)         (&TcpIp_TcpSockets[id])
#define TCPIP_SOCKET_SET_TCPARG(pcb, arg)       tcp_arg(pcb, (void*)((uint32)(arg)))
#define TCPIP_SOCKET_SET_TCPPARAM(sid, id, val) E_NOT_OK

#define TCPIP_SOCKET_GET_UDPCONTEXT(id)         (&TcpIp_UdpSockets[id])
#define TCPIP_SOCKET_SET_UDPRECV(pcb, arg)      udp_recv(pcb, &TcpIp__UdpReceiveHandler, (void*)((uint32)(arg)))
#define TCPIP_SOCKET_SET_UDPPARAM(sid, id, val) E_NOT_OK

#if (TCPIP_SCALABILITY_CLASS == TCPIP_SCALABILITY_CLASS_1)
#define TCPIP_SOCKET_NEW_TCPSOCKET(domain)      tcp_new_ip_type(IPADDR_TYPE_V4)
#define TCPIP_SOCKET_NEW_UDPSOCKET(domain)      udp_new_ip_type(IPADDR_TYPE_V4)

#define TCPIP_SOCKET_SET_ADDR(d, domain, s)     ((d)->Addr[0] = (s)->Addr[0])

#endif /*TCPIP_SCALABILITY_CLASS == TCPIP_SCALABILITY_CLASS_1*/

#if (TCPIP_SCALABILITY_CLASS == TCPIP_SCALABILITY_CLASS_2)
#define TCPIP_SOCKET_NEW_TCPSOCKET(domain)      tcp_new_ip_type(IPADDR_TYPE_V6)
#define TCPIP_SOCKET_NEW_UDPSOCKET(domain)      udp_new_ip_type(IPADDR_TYPE_V6)

#define TCPIP_SOCKET_SET_ADDR(d, domain, s)     do{\
                                                    (d)->Addr[0] = (s)->Addr[0];\
                                                    (d)->Addr[1] = (s)->Addr[1];\
                                                    (d)->Addr[2] = (s)->Addr[2];\
                                                    (d)->Addr[3] = (s)->Addr[3];\
                                                } while(0)
#endif /*TCPIP_SCALABILITY_CLASS == TCPIP_SCALABILITY_CLASS_2*/
#if (TCPIP_SCALABILITY_CLASS == TCPIP_SCALABILITY_CLASS_3) /*TCPIP_SCALABILITY_CLASS == TCPIP_SCALABILITY_CLASS_3*/
#define TCPIP_SOCKET_NEW_TCPSOCKET(domain)      (((domain) == TCPIP_AF_INET)\
                                                    ? tcp_new_ip_type(IPADDR_TYPE_V4)\
                                                    : tcp_new_ip_type(IPADDR_TYPE_V6))

#define TCPIP_SOCKET_NEW_UDPSOCKET(domain)      (((domain) == TCPIP_AF_INET)\
                                                    ? udp_new_ip_type(IPADDR_TYPE_V4)\
                                                    : udp_new_ip_type(IPADDR_TYPE_V6))

#define TCPIP_SOCKET_SET_ADDR(d, domain, s)     do{\
                                                    (d)->Addr[0] = (s)->Addr[0];\
                                                    if ((domain) == TCPIP_AF_INET6) {\
                                                        (d)->Addr[1] = (s)->Addr[1];\
                                                        (d)->Addr[2] = (s)->Addr[2];\
                                                        (d)->Addr[3] = (s)->Addr[3];\
                                                    }\
                                                } while(0)
#endif /*TCPIP_SCALABILITY_CLASS == TCPIP_SCALABILITY_CLASS_3*/
/*PRQA S 3459 ++*/
/* Using "do-while-zero" */
#define TCPIP_SOCKET_COPY_REMOTEADDR(d, s)      do{\
                                                    (d)->Domain = (s)->Domain;\
                                                    (d)->Port = (s)->Port;\
                                                    TCPIP_SOCKET_SET_ADDR(d, (s)->Domain, s);\
                                                } while(0)
/*PRQA S 3608 ++*/
/* Using "#elif" */
#if ((TCPIP_UDP_ENABLED == STD_ON) && (TCPIP_TCP_ENABLED == STD_ON))
#define TCPIP_SOCKET_MAX                                    (TCPIP_TCP_SOCKET_MAX + TCPIP_UDP_SOCKET_MAX)
#elif (TCPIP_UDP_ENABLED == STD_ON)
#define TCPIP_SOCKET_MAX                                    (TCPIP_UDP_SOCKET_MAX)
#elif (TCPIP_TCP_ENABLED == STD_ON)
#define TCPIP_SOCKET_MAX                                    (TCPIP_TCP_SOCKET_MAX)
#else
#define TCPIP_SOCKET_MAX                                    0
#endif

/*local address assignment*/
#define TCPIP_LOCALADDR_IS_VALID_ID(id)                     ((id) < (TcpIp_LocalAddrIdType)TCPIP_LOCALADDR_TABLE_MAX)
#define TCPIP_LOCALADDR_GET_ASSIGNMENT_TRIGGER(cfg, id)     ((cfg)->Assignments[id]\
                                                                & (TcpIp_LocalAddrAssignmentConfigType)TCPIP_LOCALADDR_ASSIGNMENT_TRIGGER_MASK)
/*PRQA S 791,792 EOF*/
/*TCPIP_LOCALADDR_ is same and exceed marco namelength */
#define TCPIP_LOCALADDR_GET_ASSIGNMENT_METHOD(cfg, id)      ((cfg)->Assignments[id]\
                                                                & (TcpIp_LocalAddrAssignmentConfigType)TCPIP_LOCALADDR_ASSIGNMENT_METHOD_MASK)


#define TCPIP_LOCALADDR_IS_VALID_ASSIGNMENT(cfg, id)        (TCPIP_LOCALADDR_GET_ASSIGNMENT_METHOD(cfg, id)\
                                                                < (TcpIp_LocalAddrAssignmentConfigType)TCPIP_LOCALADDR_ASSIGNMENT_PRIORITY_MAX)
#define TCPIP_LOCALADDR_IS_MANUAL_ASSIGNMENT(cfg, id)       (TCPIP_LOCALADDR_GET_ASSIGNMENT_TRIGGER(cfg, id) == (uint8)TCPIP_MANUAL)
#define TCPIP_LOCALADDR_IS_AUTOMATIC_ASSIGNMENT(cfg, id)    (TCPIP_LOCALADDR_GET_ASSIGNMENT_TRIGGER(cfg, id) ==(uint8) TCPIP_AUTOMATIC)

#define TCPIP_LOCALADDR_GET_CONTEXT(id)                     (&TcpIp_LocalAddrContexts[id])

#define TCPIP_LOCALADDR_HAS_STATIC_IPADDR(cfg)              ((cfg)->StaticAddrId < (TcpIp_StaticAddrIdType)TCPIP_STATIC_IPADDR_MAX)
#define TCPIP_LOCALADDR_IS_UNICAST_IPADDR(cfg)              ((cfg)->Address == (TcpIp_AddressType)TCPIP_UNICAST)
#define TCPIP_LOCALADDR_IS_MULTICAST_IPADDR(cfg)            ((cfg)->Address == (TcpIp_AddressType)TCPIP_MULTICAST)

#define TCPIP_LOCALADDR_GET_ASSIGNMENT_ID(ctx, type)        TcpIp__GetAssignmentIdByMethod(ctx, type)
#define TCPIP_LOCALADDR_GET_ASSIGNMENT_REQUEST(ctx)         ((ctx)->RequestAddr)
#define TCPIP_LOCALADDR_SET_ASSIGNMENT_REQUEST(ctx, id)     ((ctx)->RequestAddr\
                                                                |= (TcpIp_LocalAddrAssignmentStatusType)(((uint32)0x01) << (id)))
#define TCPIP_LOCALADDR_CLEAR_ASSIGNMENT_REQUEST(ctx, id)   ((ctx)->RequestAddr\
                                                                &= (TcpIp_LocalAddrAssignmentStatusType)(~((uint32)0x01 << (id))))


#define TCPIP_LOCALADDR_GET_NEW_ASSIGNMENT_RELEASE(ctx)     (TcpIp_LocalAddrAssignmentStatusType)((((ctx)->RequestAddr ^ (ctx)->StartedAddr)\
                                                                & (ctx)->StartedAddr))
#define TCPIP_LOCALADDR_GET_NEW_ASSIGNMENT_REQUEST(ctx)     (TcpIp_LocalAddrAssignmentStatusType)((((ctx)->RequestAddr ^ (ctx)->StartedAddr)\
                                                                & (ctx)->RequestAddr))


#define TCPIP_LOCALADDR_GET_HANDLER(ctx, id)                (&TcpIp_LocalAddrAssignmentHandlers[TCPIP_LOCALADDR_GET_ASSIGNMENT_METHOD((ctx)->ConfigPtr, id)])
#define TCPIP_LOCALADDR_START_ASSIGNMENT(ctx, id)           TCPIP_LOCALADDR_GET_HANDLER(ctx, id)->StartAssignment(ctx, id)
#define TCPIP_LOCALADDR_RELEASE_ASSIGNMENT(ctx, id)         TCPIP_LOCALADDR_GET_HANDLER(ctx, id)->ReleaseAssignment(ctx, id)
#define TCPIP_LOCALADDR_GET_ASSIGNMENT_STATE(ctx, id, ip)   TCPIP_LOCALADDR_GET_HANDLER(ctx, id)->GetState(ctx, id, ip)

#define TCPIP_LOCALADDR_SET_STARTED_ASSIGNMENT(ctx, id)     ((ctx)->StartedAddr\
                                                                |= (TcpIp_LocalAddrAssignmentStatusType)((uint32)(0x01) << (uint32)(id)))
#define TCPIP_LOCALADDR_CLEAR_STARTED_ASSIGNMENT(ctx, id)   ((ctx)->StartedAddr\
                                                                &= (TcpIp_LocalAddrAssignmentStatusType)(~((uint32)(0x01) << (uint32)(id))))
#define TCPIP_LOCALADDR_IS_STARTED_ASSIGNMENT(ctx, id)      (((ctx)->StartedAddr\
                                                                & ((uint32)(0x01) << (uint32)(id))) > (uint32)0)

#define TCPIP_LOCALADDR_CLEAR_ASSIGNED_ID(ctx)              ((ctx)->AssignedId = (TcpIp_LocalAddrAssignmentIdType)TCPIP_LOCALADDR_ASSIGNMENT_PRIORITY_MAX)
#define TCPIP_LOCALADDR_IS_VALID_ASSIGNED_ID(id)            ((TcpIp_LocalAddrAssignmentIdType)(id) < (TcpIp_LocalAddrAssignmentIdType)TCPIP_LOCALADDR_ASSIGNMENT_PRIORITY_MAX)
#define TCPIP_LOCALADDR_SET_ASSIGNED_ID(ctx, id)            ((ctx)->AssignedId = (TcpIp_LocalAddrAssignmentIdType)(id))


#if (TCPIP_SCALABILITY_CLASS == TCPIP_SCALABILITY_CLASS_1)

#define TCPIP_START_STATICIP_ASSIGNMENT                 (&TcpIp__StartStaticIpV4Assignment)
#define TCPIP_RELEASE_STATICIP_ASSIGNMENT               (&TcpIp__ReleaseStaticIpV4Assignment)
#define TCPIP_GET_STATICIP_ASSIGNMENT_STATE             (&TcpIp__GetStaticIpV4AssignmentState)

#if (TCPIP_DHCP_CLIENT_ENABLED == STD_ON)
#define TCPIP_START_DHCP_ASSIGNMENT                     &TcpIp__StartDhcpV4Assignment
#define TCPIP_RELEASE_DHCP_ASSIGNMENT                   &TcpIp__ReleaseDhcpV4Assignment
#define TCPIP_GET_DHCP_ASSIGNMENT_STATE                 &TcpIp__GetDhcpV4AssignmentState
#else
#define TCPIP_START_DHCP_ASSIGNMENT                     (&TcpIp__StartDummyAssignment)
#define TCPIP_RELEASE_DHCP_ASSIGNMENT                   (&TcpIp__ReleaseDummyAssignment)
#define TCPIP_GET_DHCP_ASSIGNMENT_STATE                 (&TcpIp__GetDummyAssignmentState)
#endif

#if (TCPIP_AUTOIP_ENABLED == STD_ON)
#define TCPIP_START_AUTOIP_ASSIGNMENT                   &TcpIp__StartAutoIpAssignment
#define TCPIP_RELEASE_AUTOIP_ASSIGNMENT                 &TcpIp__ReleaseAutoIpAssignment
#define TCPIP_GET_AUTOIP_ASSIGNMENT_STATE               &TcpIp__GetAutoIpAssignmentState
#else
#define TCPIP_START_AUTOIP_ASSIGNMENT                   (&TcpIp__StartDummyAssignment)
#define TCPIP_RELEASE_AUTOIP_ASSIGNMENT                 (&TcpIp__ReleaseDummyAssignment)
#define TCPIP_GET_AUTOIP_ASSIGNMENT_STATE               (&TcpIp__GetDummyAssignmentState)
#endif

#define TCPIP_START_IPV6ROUTER_ASSIGNMENT               (&TcpIp__StartDummyAssignment)
#define TCPIP_RELEASE_IPV6ROUTER_ASSIGNMENT             (&TcpIp__ReleaseDummyAssignment)
#define TCPIP_GET_IPV6ROUTER_ASSIGNMENT_STATE           (&TcpIp__GetDummyAssignmentState)

#define TCPIP_IS_VALID_NETMASK(domain, netmask)         (((uint16)(domain) == (uint16)TCPIP_AF_INET) && ((uint16)(netmask) <= (uint16)32))
#define TCPIP_IS_SAME_DOMAIN(d1, d2)                    ((d1) == (d2))
#define TCPIP_IS_VALID_DOMAIN(domain)                   ((domain) == TCPIP_AF_INET)
#define TCPIP_IS_VALID_MULTICAST_IPADDR(domain, ip)     (((ip)->Addr[0] & 0xFF000000U) == 0xE0000000U)

#define TCPIP_SET_STATICIPADDR(d, ip, mask, gw)         do{\
                                                            (d)->Domain = (ip)->Domain;\
                                                            (d)->IpAddr.Addr[0] = (ip)->Addr[0];\
                                                            (d)->Netmask = (mask);\
                                                            (d)->DefaultRouter.Addr[0] = (gw)->Addr[0];\
                                                        } while(0)
#define TCPIP_COPY_STATICIPADDR(d, s)                   do{\
                                                            (d)->Domain = (s)->Domain;\
                                                            (d)->IpAddr.Addr[0] = (s)->IpAddr.Addr[0];\
                                                            (d)->Netmask = (s)->Netmask;\
                                                            (d)->DefaultRouter.Addr[0] = (s)->DefaultRouter.Addr[0];\
                                                        } while(0)
#define TCPIP_SET_BROADCAST_STATICIPADDR(d, s)          do{\
                                                            (d)->Netmask = (s)->Netmask;\
                                                            (d)->Domain = (s)->Domain;\
                                                            (d)->IpAddr.Addr[0] = (s)->IpAddr.Addr[0] | (0xFFFFFFFFU >> (s)->Netmask);\
                                                        } while(0)
#define TCPIP_CLEAR_STATICIPADDR(d)                     do{\
                                                            (d)->Netmask = 0;\
                                                            (d)->Domain = 0;\
                                                            TCPIP_SET_ANY_IPADDR(&(d)->IpAddr);\
                                                            TCPIP_SET_ANY_IPADDR(&(d)->DefaultRouter);\
                                                        } while(0)

#define TCPIP_LWIP_COPY_IPADDR(d, domain, s)            ((d)->addr = lwip_htonl((s)->Addr[0]))
#define TCPIP_LWIP_GET_ANY_IPADDR(domain)               IP4_ADDR_ANY
#define TCPIP_LWIP_GET_IPADDR(netif, idx)               netif_ip_addr4(netif)

#define TCPIP_COPY_REMOTE_IPADDR_FROM_PCB(d, s)         do{\
                                                            (d)->Domain = TCPIP_AF_INET;\
                                                            (d)->Addr[0] = (uint32)lwip_ntohl((s)->remote_ip.addr);\
                                                            (d)->Port = (uint16)(s)->remote_port;\
                                                        } while(0)

#define TCPIP_COPY_REMOTE_IPADDR_FROM_LWIP(d, ip, port) do{\
                                                            (d)->Domain = TCPIP_AF_INET;\
                                                            (d)->Addr[0] = (uint32)lwip_ntohl((ip)->addr);\
                                                            (d)->Port = (uint16)(port);\
                                                        } while(0)

#define TCPIP_COPY_PHYS_ADDR(phys, ctx)                 TCPIP_COPY_DATA(phys, (ctx)->NetIf.hwaddr, TCPIP_HWADDR_LENGTH)

#elif (TCPIP_SCALABILITY_CLASS == TCPIP_SCALABILITY_CLASS_2)

#define TCPIP_START_STATICIP_ASSIGNMENT                 &TcpIp__StartStaticIpV6Assignment

#define TCPIP_IS_VALID_NETMASK(domain, netmask)         (((domain) == TCPIP_AF_INET6) && ((netmask) <= 128))
#define TCPIP_IS_SAME_DOMAIN(d1, d2)                    (1)
#define TCPIP_IS_VALID_DOMAIN(domain)                   ((domain) == TCPIP_AF_INET6)

#define TCPIP_LWIP_COPY_IPADDR(d, domain, s)            do{\
                                                            (d)->addr[0] = lwip_htonl((s)->Addr[0]);\
                                                            (d)->addr[1] = lwip_htonl((s)->Addr[1]);\
                                                            (d)->addr[2] = lwip_htonl((s)->Addr[2]);\
                                                            (d)->addr[3] = lwip_htonl((s)->Addr[3]);\
                                                        } while(0)

#define TCPIP_LWIP_GET_ANY_IPADDR(domain)               IP6_ADDR_ANY
#define TCPIP_LWIP_GET_IPADDR(netif, idx)               netif_ip_addr6(netif, idx)

#define TCPIP_COPY_REMOTE_IPADDR_FROM_PCB(d, s)         do{\
                                                            (d)->Domain = TCPIP_AF_INET6;\
                                                            (d)->Addr[0] = lwip_ntohl((s)->remote_ip.addr[0]);\
                                                            (d)->Addr[1] = lwip_ntohl((s)->remote_ip.addr[1]);\
                                                            (d)->Addr[2] = lwip_ntohl((s)->remote_ip.addr[2]);\
                                                            (d)->Addr[3] = lwip_ntohl((s)->remote_ip.addr[3]);\
                                                            (d)->Port = (s)->remote_port;\
                                                        } while(0)

#define TCPIP_COPY_REMOTE_IPADDR_FROM_LWIP(d, ip, port) do{\
                                                            (d)->Domain = TCPIP_AF_INET6;\
                                                            (d)->Addr[0] = lwip_ntohl((ip)->addr[0]);\
                                                            (d)->Addr[1] = lwip_ntohl((ip)->addr[1]);\
                                                            (d)->Addr[2] = lwip_ntohl((ip)->addr[2]);\
                                                            (d)->Addr[3] = lwip_ntohl((ip)->addr[3]);\
                                                            (d)->Port = (port);\
                                                        } while(0)
#else

#define TCPIP_START_STATICIP_ASSIGNMENT                 &TcpIp__StartStaticIpAssignment

#define TCPIP_IS_VALID_NETMASK(domain, netmask)         ((((domain) == TCPIP_AF_INET) && ((netmask) <= 32))\
                                                            || (((domain) == TCPIP_AF_INET6) && ((netmask) <= 128)))

#define TCPIP_IS_SAME_DOMAIN(d1, d2)                    ((d1) == (d2))
#define TCPIP_IS_VALID_DOMAIN(domain)                   (((domain) == TCPIP_AF_INET)\
                                                            || ((domain) == TCPIP_AF_INET6))


#define TCPIP_LWIP_COPY_IPADDR(d, domain, s)            do{\
                                                            IP_SET_TYPE_VAL(*d, (domain == TCPIP_AF_INET)? IPADDR_TYPE_V4: IPADDR_TYPE_V6);
                                                            (d)->addr[0] = lwip_htonl((s)->Addr[0]);\
                                                            if (domain != TCPIP_AF_INET) {\
                                                                (d)->addr[1] = lwip_htonl((s)->Addr[1]);\
                                                                (d)->addr[2] = lwip_htonl((s)->Addr[2]);\
                                                                (d)->addr[3] = lwip_htonl((s)->Addr[3]);\
                                                            }\
                                                        } while(0)

#define TCPIP_LWIP_GET_ANY_IPADDR(domain)               (((domain) == TCPIP_AF_INET)? IP4_ADDR_ANY: IP6_ADDR_ANY)
#define TCPIP_LWIP_GET_IPADDR(netif, idx)               (((id) == 0)? netif_ip_addr4(netif): netif_ip_addr6(netif, idx))

#define TCPIP_COPY_REMOTE_IPADDR_FROM_PCB(d, s)         do{\
                                                            (d)->Domain = IP_IS_V4_VAL((s)->remote_ip)? TCPIP_AF_INET: TCPIP_AF_INET6;\
                                                            (d)->Addr[0] = lwip_ntohl((s)->remote_ip.addr[0]);\
                                                            (d)->Addr[1] = lwip_ntohl((s)->remote_ip.addr[1]);\
                                                            (d)->Addr[2] = lwip_ntohl((s)->remote_ip.addr[2]);\
                                                            (d)->Addr[3] = lwip_ntohl((s)->remote_ip.addr[3]);\
                                                            (d)->Port = (s)->remote_port;\
                                                        } while(0)

#define TCPIP_COPY_REMOTE_IPADDR_FROM_LWIP(d, ip, port) do{\
                                                            (d)->Domain = IP_IS_V4_VAL(ip)? TCPIP_AF_INET: TCPIP_AF_INET6;\
                                                            (d)->Addr[0] = lwip_ntohl((ip)->addr[0]);\
                                                            (d)->Addr[1] = lwip_ntohl((ip)->addr[1]);\
                                                            (d)->Addr[2] = lwip_ntohl((ip)->addr[2]);\
                                                            (d)->Addr[3] = lwip_ntohl((ip)->addr[3]);\
                                                            (d)->Port = (port);\
                                                        } while(0)
#endif


#define TCPIP_IPADDR_GET_PORT(addr)                     ((addr)->Port)
#define TCPIP_CIDR_TO_NETMASK(cidr)                     (((uint32)0xFFFFFFFF) << ((uint32)32 - (uint32)(cidr)))
#define TCPIP_LWIP_SET_NETMASK(netmask, n)              ((netmask)->addr = lwip_htonl(n))
#define TCPIP_LWIP_GET_NETMASK(netif)                   (lwip_ntohl(netif_ip4_netmask(netif)->addr))
#define TCPIP_LWIP_GET_IPV4ADDR(netif)                  (lwip_ntohl(netif_ip4_addr(netif)->addr))
#define TCPIP_LWIP_GET_GW(netif)                        (lwip_ntohl(netif_ip4_gw(netif)->addr))
/*PRQA S 3410 EOF*/
#define TCPIP_LWIP_SET_IPV4_MULTICAST_MAC(mac, ip)      do{\
                                                            mac[0] = (uint8)0x01u;\
                                                            mac[1] = (uint8)0x00u;\
                                                            mac[2] = (uint8)0x5eu;\
                                                            mac[3] = ((uint8*)(&(ip)->addr))[1] & 0x7Fu;\
                                                            mac[4] = ((uint8*)(&(ip)->addr))[2];\
                                                            mac[5] = ((uint8*)(&(ip)->addr))[3];\
                                                        } while(0)
/*PRQA S 3410 EOF*/
#define TCPIP_LWIP_SET_IPV6_MULTICAST_MAC(mac, ip)      do{\
                                                            mac[0] = (uint8)0x33u;\
                                                            mac[1] = (uint8)0x33u;\
                                                            mac[2] = ((uint8*)(&(ip)->addr[3]))[0];\
                                                            mac[3] = ((uint8*)(&(ip)->addr[3]))[1];\
                                                            mac[4] = ((uint8*)(&(ip)->addr[3]))[2];\
                                                            mac[5] = ((uint8*)(&(ip)->addr[3]))[3];\
                                                        } while(0)

/*PRQA S 3459 --*/
#define TCPIP_COMSTATE_HANDLER_AGAIN                    ((uint8)(1))
#define TCPIP_COMSTATE_HANDLER_DONE                     ((uint8)(0))


#if ((TCPIP_CONFIG_VARIANTS == STD_CONFIG_VARIANTS_PRECOMPILE) || (TCPIP_CONFIG_VARIANTS == STD_CONFIG_VARIANTS_LINKTIME))
/*PRQA S 3412 EOF*/
#define TCPIP_IF_CONFIG_PTR(cfg)                            TCPIP_UNUSED(cfg);
#define TCPIP_NETCTRL_GET_CONFIG(id)                        (&TcpIp_NetIfCtrlConfigs[id])
#define TCPIP_IPV4_GET_CONFIG(id)                           (&TcpIp_IpV4CtrlConfigs[id])
#define TCPIP_STATICIP_GET_CONFIG(id)                       (&TcpIp_StaticIpAddrConfigs[id])
#define TCPIP_LOCALADDR_GET_CONFIG(id)                      (&TcpIp_LocalAddrConfigs[id])
#else
#define TCPIP_IF_CONFIG_PTR(cfg)                            if ((TcpIp_ConfigPtr = (cfg)) != NULL_PTR)
#define TCPIP_NETCTRL_GET_CONFIG(id)                        (&TcpIp_ConfigPtr->NetIfCtrlPtr[id])
#define TCPIP_IPV4_GET_CONFIG(id)                           (&TcpIp_ConfigPtr->IpV4CtrlPtr[id])
#define TCPIP_STATICIP_GET_CONFIG(id)                       (&TcpIp_ConfigPtr->StaticIpAddrPtr[id])
#define TCPIP_LOCALADDR_GET_CONFIG(id)                      (&TcpIp_ConfigPtr->LocalAddrConfigs[id])
#endif /*(TCPIP_CONFIG_VARIANTS == STD_CONFIG_VARIANTS_PRECOMPILE) || (TCPIP_CONFIG_VARIANTS == STD_CONFIG_VARIANTS_LINKTIME)*/



/*netif ctrl*/
#if (TCPIP_SCALABILITY_CLASS == TCPIP_SCALABILITY_CLASS_1)
#define TCPIP_NETCTRL_ADD_NETIF(ctx, id)                    netif_add(&(ctx)->NetIf,\
                                                                        IP4_ADDR_ANY,\
                                                                        IP4_ADDR_ANY,\
                                                                        IP4_ADDR_ANY,\
                                                                        (void*)(uint32)(id),\
                                                                        &TcpIp__InitNetIfHandler,\
                                                                        &ethernet_input)

#if (TCPIP_ARP_ENABLED == STD_ON)
#define TCPIP_NETCTRL_FIND_ETHADDR(ctx, ip, eth, ret, idx)  ((idx) = etharp_find_addr(&(ctx)->NetIf, ip, eth, ret))
#define TCPIP_NETCTRL_REQUEST_ETHADDR(ctx, ip)              etharp_request(&(ctx)->NetIf, ip)
#else
#define TCPIP_NETCTRL_FIND_ETHADDR(ctx, ip, eth, ret, idx)  ((idx) = -1)
#define TCPIP_NETCTRL_REQUEST_ETHADDR(ctx, ip)
#endif

#define TCPIP_NETCTRL_READ_DHCP_OPTION(ctx, op, l, d)       E_NOT_OK
#define TCPIP_NETCTRL_WRITE_DHCP_OPTION(ctx, op, l, d)      E_NOT_OK
#elif (TCPIP_SCALABILITY_CLASS == TCPIP_SCALABILITY_CLASS_2)
#define TCPIP_NETCTRL_ADD_NETIF(ctx, id)                    netif_add(&(ctx)->NetIf,\
                                                                        (void*)(uint32)id,\
                                                                        &TcpIp__InitNetIfHandler,\
                                                                        &ethernet_input)

#define TCPIP_NETCTRL_READ_DHCPV6_OPTION(ctx, op, l, d)     E_NOT_OK
#define TCPIP_NETCTRL_WRITE_DHCPV6_OPTION(ctx, op, l, d)    E_NOT_OK
#else /*TCPIP_SCALABILITY_CLASS == TCPIP_SCALABILITY_CLASS_3*/
#define TCPIP_NETCTRL_ADD_NETIF(ctx, id)                    netif_add(&(ctx)->NetIf,\
                                                                        IP4_ADDR_ANY,\
                                                                        IP4_ADDR_ANY,\
                                                                        IP4_ADDR_ANY,\
                                                                        (void*)(uint32)id,\
                                                                        &TcpIp__InitNetIfHandler,\
                                                                        &ethernet_input)

#define TCPIP_NETCTRL_READ_DHCP_OPTION(ctx, op, l, d)       E_NOT_OK
#define TCPIP_NETCTRL_WRITE_DHCP_OPTION(ctx, op, l, d)      E_NOT_OK

#define TCPIP_NETCTRL_READ_DHCPV6_OPTION(ctx, op, l, d)     E_NOT_OK
#define TCPIP_NETCTRL_WRITE_DHCPV6_OPTION(ctx, op, l, d)    E_NOT_OK
#endif /*TCPIP_SCALABILITY_CLASS == TCPIP_SCALABILITY_CLASS_1*/



#define TCPIP_NETCTRL_SET_DEFAULT_NETIF(ctx)            netif_set_default(&(ctx)->NetIf)
#define TCPIP_NETCTRL_GET_DEFAULT_NETIF()               (netif_default)

#define TCPIP_NETCTRL_SET_LINK_UP(ctx)                  netif_set_link_up(&(ctx)->NetIf)
#define TCPIP_NETCTRL_SET_LINK_DOWN(ctx)                netif_set_link_down(&(ctx)->NetIf)

#define TCPIP_NETCTRL_RX_HANDLER(ctx, buf)              ((ctx)->NetIf.input(buf, &(ctx)->NetIf))
#define TCPIP_NETCTRL_IS_VALID_ID(id)                   ((id) < (uint8)TCPIP_NETIF_CTRL_MAX)
#define TCPIP_NETCTRL_IS_LINK_UP(ctrl)                  ((uint8)1 == netif_is_link_up(&(ctrl)->NetIf))


#define TCPIP_NETCTRL_GET_CONTEXT(id)                   (&TcpIp_NetIfCtrls[id])
#define TCPIP_NETCTRL_GET_CONTEXT_BYLOCALADDR(addr)     TCPIP_NETCTRL_GET_CONTEXT(TCPIP_LOCALADDR_GET_CONTEXT(addr)->CtrlId)
#define TCPIP_NETCTRL_GET_ETHIFCTRL(id)                 (TCPIP_NETCTRL_GET_CONTEXT(id)->CtrlIdx)
#define TCPIP_NETCTRL_GET_HWADDR_PTR(id)                (uint8*)(TCPIP_NETCTRL_GET_CONTEXT(id)->NetIf.hwaddr)


#define TCPIP_NETCTRL_GET_LOCALADDR_ID(ctx)             ((ctx)->UnicastAddrId)
#define TCPIP_NETCTRL_GET_UNICASTADDR_ID(ctx)           ((ctx)->UnicastAddrId)
#define TCPIP_NETCTRL_GET_UNICASTADDR_LIMIT(ctx)        ((ctx)->UnicastAddrLimit)
#define TCPIP_NETCTRL_GET_MULTICASTADDR_ID(ctx)         ((ctx)->MulticastAddrId)
#define TCPIP_NETCTRL_GET_MULTICASTADDR_LIMIT(ctx)      ((ctx)->LocalAddrLimit)
/*PRQA S 791,792 EOF*/
#define TCPIP_NETCTRL_GET_LOCALADDR_LIMIT(ctx)          ((ctx)->LocalAddrLimit)
#define TCPIP_NETCTRL_GET_BROADCASTADDR_ID(ctx)         ((ctx)->UnicastAddrLimit)

#define TCPIP_NETCTRL_SET_STATE(ctx, sta)               ((ctx)->CurrentState = (sta))
#define TCPIP_NETCTRL_GOTO_OFFLINE(ctx)                 TCPIP_NETCTRL_SET_STATE(ctx, TCPIP_STATE_OFFLINE)
#define TCPIP_NETCTRL_GOTO_STARTUP(ctx)                 TCPIP_NETCTRL_SET_STATE(ctx, TCPIP_STATE_STARTUP)
#define TCPIP_NETCTRL_GOTO_ONLINE(ctx)                  TCPIP_NETCTRL_SET_STATE(ctx, TCPIP_STATE_ONLINE)
#define TCPIP_NETCTRL_GOTO_ONHOLD(ctx)                  TCPIP_NETCTRL_SET_STATE(ctx, TCPIP_STATE_ONHOLD)
#define TCPIP_NETCTRL_GOTO_SHUTDOWN(ctx)                TCPIP_NETCTRL_SET_STATE(ctx, TCPIP_STATE_SHUTDOWN)

#define TCPIP_NETCTRL_IS_ONLINE(ctx)                    ((ctx)->CurrentState == TCPIP_STATE_ONLINE)
#define TCPIP_NETCTRL_IS_OFFINE(ctx)                    ((ctx)->CurrentState == TCPIP_STATE_OFFLINE)
#define TCPIP_NETCTRL_IS_SHUTDOWN(ctx)                  ((ctx)->CurrentState == TCPIP_STATE_SHUTDOWN)

#define TCPIP_NETCTRL_SET_REQUEST_STATE(ctx, sta)       ((ctx)->RequestState = (sta))

#define TCPIP_NETCTRL_IS_DOWN(idx)                      (TCPIP_NETCTRL_IS_OFFINE(TCPIP_NETCTRL_GET_CONTEXT(idx))\
                                                            || TCPIP_NETCTRL_IS_SHUTDOWN(TCPIP_NETCTRL_GET_CONTEXT(idx)))
#if (TCPIP_NETIF_CTRL_MAX == 1)
#define TCPIP_NETCTRL_IS_ALL_DOWN()                     TCPIP_NETCTRL_IS_DOWN(0)
#else
#define TCPIP_NETCTRL_IS_ALL_DOWN()                     (TcpIp__IsAllNetCtrlDown() == E_OK)
#endif

#if (TCPIP_ETHSM_ENABLED == STD_ON)
#define TCPIP_NETCTRL_NOTIFY_STATE(ctx)                 EthSM_TcpIpModeIndication((ctx)->CtrlIdx, (ctx)->CurrentState)
#else
#define TCPIP_NETCTRL_NOTIFY_STATE(ctx)
#endif
/*PRQA S 3435,3436 --*/
#define TCPIP_COPY_DATA(d, s, l)                        TcpIp__CopyData(d, s, l)

#define TCPIP_HWADDR_LENGTH                             (uint32)(6)
#define TCPIP_ETHERNET_FRAME_HEADER_LENGTH              (14)

#define TCPIP_IS_VALID_FRAME_TYPE(type)                 (1)
/*PRQA S 3429,3453 --*/
/*******************************************************************************
*   Types Declaration
*******************************************************************************/
typedef struct
{
    TcpIp_LocalAddrAssignmentStatusType StartedAddr;
    TcpIp_LocalAddrAssignmentStatusType RequestAddr;
    TcpIp_LocalAddrAssignmentIdType AssignedId;
    TcpIp_CtrlIdType CtrlId;
    TcpIp_StaticIpAddrType StaticIpAddr;
    P2CONST(TcpIp_LocalAddrConfigType, TCPIP_CONFIG_DATA, AUTOMATIC) ConfigPtr;
} TcpIp_LocalAddrType;

typedef struct
{
    P2FUNC(void, AUTOMATIC, StartAssignment)
    (
        P2VAR(TcpIp_LocalAddrType, AUTOMATIC, AUTOMATIC) LocalAddrCtxPtr,
        TcpIp_LocalAddrAssignmentIdType AssignmentId
    );
    P2FUNC(void, AUTOMATIC, ReleaseAssignment)
    (
        P2VAR(TcpIp_LocalAddrType, AUTOMATIC, AUTOMATIC) LocalAddrCtxPtr,
        TcpIp_LocalAddrAssignmentIdType AssignmentId
    );
    P2FUNC(Std_ReturnType, AUTOMATIC, GetState)
    (
        P2VAR(TcpIp_LocalAddrType, AUTOMATIC, AUTOMATIC) LocalAddrCtxPtr,
        TcpIp_LocalAddrAssignmentIdType AssignmentId,
        P2VAR(TcpIp_StaticIpAddrType, AUTOMATIC, AUTOMATIC) IpAddrPtr
    );
} TcpIp_LocalAddrAssignmentHandlerType;


/*SWS_TCPIP_00083*/
typedef struct
{
    uint8 CtrlIdx; /*EthIf Ctrl Index*/
#if (TCPIP_AUTOIP_ENABLED == STD_ON)
    uint16 AutoIpTimeout;
#endif
    /*Unicast - Multicast - limit*/
    TcpIp_LocalAddrIdType UnicastAddrId;    /*must be the first local address Id*/
    TcpIp_LocalAddrIdType UnicastAddrLimit; /*IPv6 may have multiple unicast address*/
    TcpIp_LocalAddrIdType MulticastAddrId;  /*equal to LocalAddrLimit if this NetCtrl do not have multicast address*/
    TcpIp_LocalAddrIdType LocalAddrLimit;
    /*SWS_TCPIP_00083*/
    TcpIp_StateType RequestState; /*request state by uplayer*/
    TcpIp_StateType CurrentState; /*current state of this TcpIpCtrl*/
    struct netif NetIf;
#if (TCPIP_DHCP_CLIENT_ENABLED == STD_ON)
    P2VAR(struct dhcp, AUTOMATIC, AUTOMATIC) DHCPCtxPtr;
#endif
#if (TCPIP_AUTOIP_ENABLED == STD_ON)
    P2VAR(struct autoip, AUTOMATIC, AUTOMATIC) AutoIpCtxPtr;
#endif
} TcpIp_NetIfCtrlType;


typedef P2FUNC(uint8, AUTOMATIC, TcpIp_ComStateProcessorType)(P2VAR(TcpIp_NetIfCtrlType, AUTOMATIC, AUTOMATIC) CtrlPtr);

typedef struct
{
    TcpIp_ComStateProcessorType Processor[TCPIP_STATE_VISIBLE];
} TcpIp_ComStateManagerType;


typedef uint8 TcpIp_SocketStatetype;


typedef struct TcpIp_TcpTxBufferHead
{
    struct TcpIp_TcpTxBufferHead *NextPtr;
    uint16 Length;
} TcpIp_TcpTxBufferHeadType;

typedef struct
{
    P2VAR(TcpIp_TcpTxBufferHeadType, AUTOMATIC, AUTOMATIC) HeadPtr;
    P2VAR(TcpIp_TcpTxBufferHeadType, AUTOMATIC, AUTOMATIC) TailPtr;
} TcpIp_TcpTxBufferListType;

typedef struct
{
    TcpIp_SocketStatetype State;
    TcpIp_UpLayerIndexType UpLayer;
    TcpIp_DomainType Domain;
    TcpIp_LocalAddrIdType LocalAddrId;
    TcpIp_CtrlIdType NetIfCtrlId;
    uint8 Abort;
    uint16 MaxChannels;
    uint16 ReceivedDataSize;
    TcpIp_SockAddrRealType RemoteAddr;  /* used for connect */
     /*PRQA S 3430 EOF*/
    P2VAR(struct tcp_pcb, AUTOMATIC, AUTOMATIC) PcbPtr;
    TcpIp_TcpTxBufferListType TxBufferList;
    TcpIp_TcpTxBufferListType WaitConfirmList;
} TcpIp_TcpSocketType;

typedef struct
{
    TcpIp_SocketStatetype State;
    TcpIp_UpLayerIndexType UpLayer;
    TcpIp_DomainType Domain;
    TcpIp_LocalAddrIdType LocalAddrId;
    TcpIp_CtrlIdType NetIfCtrlId;
    P2VAR(struct udp_pcb, AUTOMATIC, AUTOMATIC) PcbPtr;
} TcpIp_UdpSocketType;


typedef struct
{
    uint16 In;
    uint16 Out;
    uint8 Fifo[TCPIP_RX_FIFO_SIZE];
} TcpIp_RxFifoType;


/******************************************************************************
*   Local Function Declaration
******************************************************************************/

STATIC FUNC(uint8, TCPIP_CODE) TcpIp__ComStateIdle
(
    P2VAR(TcpIp_NetIfCtrlType, AUTOMATIC, AUTOMATIC) CtrlPtr
);

STATIC FUNC(uint8, TCPIP_CODE) TcpIp__ComStateOfflineToOnline
(
    P2VAR(TcpIp_NetIfCtrlType, AUTOMATIC, AUTOMATIC) CtrlPtr
);

STATIC FUNC(uint8, TCPIP_CODE) TcpIp__ComStateOnlineToOffline
(
    P2VAR(TcpIp_NetIfCtrlType, AUTOMATIC, AUTOMATIC) CtrlPtr
);

STATIC FUNC(uint8, TCPIP_CODE) TcpIp__ComStateOnline
(
    P2VAR(TcpIp_NetIfCtrlType, AUTOMATIC, AUTOMATIC) CtrlPtr
);

STATIC FUNC(uint8, TCPIP_CODE) TcpIp__ComStateOnlineToOnhold
(
    P2VAR(TcpIp_NetIfCtrlType, AUTOMATIC, AUTOMATIC) CtrlPtr
);

STATIC FUNC(uint8, TCPIP_CODE) TcpIp__ComStateOnholdToOnline
(
    P2VAR(TcpIp_NetIfCtrlType, AUTOMATIC, AUTOMATIC) CtrlPtr
);

STATIC FUNC(uint8, TCPIP_CODE) TcpIp__ComStateStartupToOnline
(
    P2VAR(TcpIp_NetIfCtrlType, AUTOMATIC, AUTOMATIC) CtrlPtr
);

STATIC FUNC(uint8, TCPIP_CODE) TcpIp__ComStateStartupToOffline
(
    P2VAR(TcpIp_NetIfCtrlType, AUTOMATIC, AUTOMATIC) CtrlPtr
);

STATIC FUNC(uint8, TCPIP_CODE) TcpIp__ComStateShutdownToOffline
(
    P2VAR(TcpIp_NetIfCtrlType, AUTOMATIC, AUTOMATIC) CtrlPtr
);


STATIC FUNC(void, TCPIP_CODE) TcpIp__StartStaticIpV4Assignment
(
    P2VAR(TcpIp_LocalAddrType, AUTOMATIC, AUTOMATIC) LocalAddrCtxPtr,
    TcpIp_LocalAddrAssignmentIdType AssignmentId
);

STATIC FUNC(void, TCPIP_CODE) TcpIp__ReleaseStaticIpV4Assignment
(
    P2VAR(TcpIp_LocalAddrType, AUTOMATIC, AUTOMATIC) LocalAddrCtxPtr,
    TcpIp_LocalAddrAssignmentIdType AssignmentId
);

STATIC FUNC(Std_ReturnType, TCPIP_CODE) TcpIp__GetStaticIpV4AssignmentState
(
    P2VAR(TcpIp_LocalAddrType, AUTOMATIC, AUTOMATIC) LocalAddrCtxPtr,
    TcpIp_LocalAddrAssignmentIdType AssignmentId,
    P2VAR(TcpIp_StaticIpAddrType, AUTOMATIC, AUTOMATIC) IpAddrPtr
);
STATIC FUNC(void, TCPIP_CODE) TcpIp__CopyData
(
    P2VAR(uint8, AUTOMATIC, AUTOMATIC) DestPtr,
    P2CONST(uint8, AUTOMATIC, AUTOMATIC) SrcPtr,
    uint32 TotalLength
);
#if (TCPIP_DHCP_CLIENT_ENABLED == STD_ON)
STATIC FUNC(void, TCPIP_CODE) TcpIp__StartDhcpV4Assignment
(
    P2VAR(TcpIp_LocalAddrType, AUTOMATIC, AUTOMATIC) LocalAddrCtxPtr,
    TcpIp_LocalAddrAssignmentIdType AssignmentId
);

STATIC FUNC(void, TCPIP_CODE) TcpIp__ReleaseDhcpV4Assignment
(
    P2VAR(TcpIp_LocalAddrType, AUTOMATIC, AUTOMATIC) LocalAddrCtxPtr,
    TcpIp_LocalAddrAssignmentIdType AssignmentId
);

STATIC FUNC(Std_ReturnType, TCPIP_CODE) TcpIp__GetDhcpV4AssignmentState
(
    P2VAR(TcpIp_LocalAddrType, AUTOMATIC, AUTOMATIC) LocalAddrCtxPtr,
    TcpIp_LocalAddrAssignmentIdType AssignmentId,
    P2VAR(TcpIp_StaticIpAddrType, AUTOMATIC, AUTOMATIC) IpAddrPtr
);
#endif

#if (TCPIP_AUTOIP_ENABLED == STD_ON)
STATIC FUNC(void, TCPIP_CODE) TcpIp__StartAutoIpAssignment
(
    P2VAR(TcpIp_LocalAddrType, AUTOMATIC, AUTOMATIC) LocalAddrCtxPtr,
    TcpIp_LocalAddrAssignmentIdType AssignmentId
);

STATIC FUNC(void, TCPIP_CODE) TcpIp__ReleaseAutoIpAssignment
(
    P2VAR(TcpIp_LocalAddrType, AUTOMATIC, AUTOMATIC) LocalAddrCtxPtr,
    TcpIp_LocalAddrAssignmentIdType AssignmentId
);

STATIC FUNC(Std_ReturnType, TCPIP_CODE) TcpIp__GetAutoIpAssignmentState
(
    P2VAR(TcpIp_LocalAddrType, AUTOMATIC, AUTOMATIC) LocalAddrCtxPtr,
    TcpIp_LocalAddrAssignmentIdType AssignmentId,
    P2VAR(TcpIp_StaticIpAddrType, AUTOMATIC, AUTOMATIC) IpAddrPtr
);
#endif

STATIC FUNC(void, TCPIP_CODE) TcpIp__StartDummyAssignment
(
    P2VAR(TcpIp_LocalAddrType, AUTOMATIC, AUTOMATIC) LocalAddrCtxPtr,
    TcpIp_LocalAddrAssignmentIdType AssignmentId
);

STATIC FUNC(void, TCPIP_CODE) TcpIp__ReleaseDummyAssignment
(
    P2VAR(TcpIp_LocalAddrType, AUTOMATIC, AUTOMATIC) LocalAddrCtxPtr,
    TcpIp_LocalAddrAssignmentIdType AssignmentId
);

STATIC FUNC(Std_ReturnType, TCPIP_CODE) TcpIp__GetDummyAssignmentState
(
    P2VAR(TcpIp_LocalAddrType, AUTOMATIC, AUTOMATIC) LocalAddrCtxPtr,
    TcpIp_LocalAddrAssignmentIdType AssignmentId,
    P2VAR(TcpIp_StaticIpAddrType, AUTOMATIC, AUTOMATIC) IpAddrPtr
);
/******************************************************************************
*   Local Data Define
******************************************************************************/
#define TCPIP_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
/*PRQA S 0778,779 EOF*/
/* Identifier matches other identifier in first 31 characters - program does not conform strictly to ISO:C90. */
STATIC CONST(TcpIp_LocalAddrAssignmentHandlerType, AUTOMATIC) TcpIp_LocalAddrAssignmentHandlers[TCPIP_IPADDR_ASSIGNMENT_MAX] =
{
    /*TCPIP_IPADDR_ASSIGNMENT_STATIC*/
    {
        TCPIP_START_STATICIP_ASSIGNMENT,
        TCPIP_RELEASE_STATICIP_ASSIGNMENT,
        TCPIP_GET_STATICIP_ASSIGNMENT_STATE
    },
    /*TCPIP_IPADDR_ASSIGNMENT_DHCP*/
    {
        TCPIP_START_DHCP_ASSIGNMENT,
        TCPIP_RELEASE_DHCP_ASSIGNMENT,
        TCPIP_GET_DHCP_ASSIGNMENT_STATE
    },
    /*TCPIP_IPADDR_ASSIGNMENT_LINKLOCAL*/
    /*TCPIP_IPADDR_ASSIGNMENT_LINKLOCAL_DOIP*/
    {
        TCPIP_START_AUTOIP_ASSIGNMENT,
        TCPIP_RELEASE_AUTOIP_ASSIGNMENT,
        TCPIP_GET_AUTOIP_ASSIGNMENT_STATE
    },
    /*TCPIP_IPADDR_ASSIGNMENT_IPV6_ROUTER*/
    {
        TCPIP_START_IPV6ROUTER_ASSIGNMENT,
        TCPIP_RELEASE_IPV6ROUTER_ASSIGNMENT,
        TCPIP_GET_IPV6ROUTER_ASSIGNMENT_STATE
    }
};
STATIC CONST(TcpIp_ComStateManagerType, AUTOMATIC) TcpIp_ComStateProcessors[TCPIP_STATE_VALID] = 
{
    /*TCPIP_STATE_OFFLINE*/
    {
        {
            &TcpIp__ComStateIdle, &TcpIp__ComStateOfflineToOnline, &TcpIp__ComStateIdle
        }
    },
    /*TCPIP_STATE_ONLINE*/
    {
        {
            &TcpIp__ComStateOnlineToOffline, &TcpIp__ComStateOnline, &TcpIp__ComStateOnlineToOnhold
        }
    },
    /*TCPIP_STATE_ONHOLD*/
    {
        {
            &TcpIp__ComStateOnlineToOffline, &TcpIp__ComStateOnholdToOnline, &TcpIp__ComStateOnline
        }
    },
    /*TCPIP_STATE_STARTUP*/
    {
        {
            &TcpIp__ComStateStartupToOffline, &TcpIp__ComStateStartupToOnline, &TcpIp__ComStateStartupToOnline
        }
    },
    /*TCPIP_STATE_SHUTDOWN*/
    {
        {
            &TcpIp__ComStateShutdownToOffline, &TcpIp__ComStateShutdownToOffline, &TcpIp__ComStateShutdownToOffline
        }
    }
    
};

#define TCPIP_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"

#define TCPIP_START_SEC_VAR_INIT_8
#include "MemMap.h"
STATIC VAR(Std_InitStateType, AUTOMATIC) TcpIp_Initialized = STD_UNINITIALIZED;
#define TCPIP_STOP_SEC_VAR_INIT_8
#include "MemMap.h"

#if (TCPIP_UDP_RX_DATAGRAM_LENGTH_MAX > 0)
#define TCPIP_START_SEC_VAR_NOINIT_8
#include "MemMap.h"
/*PRQA S 3218 EOF*/
STATIC VAR(uint8, AUTOMATIC) TcpIp_UdpRxBuffer[TCPIP_UDP_RX_DATAGRAM_LENGTH_MAX];

#define TCPIP_STOP_SEC_VAR_NOINIT_8
#include "MemMap.h"
#endif

#define TCPIP_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"
#if (TCPIP_DHCP_CLIENT_ENABLED == STD_ON)
/*PRQA S 3218 EOF*/
STATIC VAR(struct dhcp, AUTOMATIC) TcpIp_DHCPContexts[TCPIP_DHCP_CLIENT_MAX];
#endif

#if (TCPIP_AUTOIP_ENABLED == STD_ON)
/*PRQA S 3218 EOF*/
STATIC VAR(struct autoip, AUTOMATIC) TcpIp_AutoIpContexts[TCPIP_AUTOIP_CLIENT_MAX];
#endif

STATIC VAR(TcpIp_RxFifoType, AUTOMATIC) TcpIp_RxFifo;
STATIC VAR(TcpIp_LocalAddrType, AUTOMATIC) TcpIp_LocalAddrContexts[TCPIP_LOCALADDR_TABLE_MAX];
STATIC VAR(TcpIp_NetIfCtrlType, AUTOMATIC) TcpIp_NetIfCtrls[TCPIP_NETIF_CTRL_MAX];

#if (TCPIP_TCP_ENABLED == STD_ON)
STATIC VAR(TcpIp_TcpSocketType, AUTOMATIC) TcpIp_TcpSockets[TCPIP_TCP_SOCKET_MAX];
#endif

#if (TCPIP_UDP_ENABLED == STD_ON)
STATIC VAR(TcpIp_UdpSocketType, AUTOMATIC) TcpIp_UdpSockets[TCPIP_UDP_SOCKET_MAX];
#endif

#define TCPIP_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"

/******************************************************************************
*   Local Function Define
******************************************************************************/
#define TCPIP_START_SEC_CODE
#include "MemMap.h"

#if (TCPIP_UPLAYER_MAX > 1)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: TcpIp__LocalIpAddrAssignmentChg
*
* Description:   notify that the state of local address was changed.
*
* Inputs:        IpAddrId   - the local address id
*                State      - the state of local address
*
* Outputs:       None
*
* Returns:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, TCPIP_CODE) TcpIp__LocalIpAddrAssignmentChg
(
    TcpIp_LocalAddrIdType IpAddrId,
    TcpIp_IpAddrStateType State
)
{
    TcpIp_UpLayerIndexType i;

    for (i = 0; i < (TcpIp_UpLayerIndexType)TCPIP_UPLAYER_MAX; i++)
    {
        TCPIP_UPLAYER_CALL_IPADDRASSIGNMENTCHG(i, IpAddrId, State);
    }
}
#endif

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: TcpIp__NetmaskToCIDR
*
* Description:   netmask to CIDR notation.
*
* Inputs:        netmask    - the netmask
*
* Outputs:       None
*
* Returns:       CIDR value
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
/*PRQA S 3450 EOF*/
/*PRQA S 3384,3219 EOF*/
STATIC FUNC(uint8, TCPIP_CODE) TcpIp__NetmaskToCIDR
(
    uint32 netmask
)
{
    netmask -= ((netmask >> (uint32)1) & 0x55555555u);
    netmask = (netmask & 0x33333333u) + ((netmask >> (uint32)2) & 0x33333333u);
    netmask = (netmask + (netmask >> (uint32)4)) & 0x0f0f0f0fu;
    netmask += (netmask >> (uint32)8);
    netmask += (netmask >> (uint32)16); 
    return (uint8)(netmask & 0x3fu);
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: TcpIp__CopyData
*
* Description:   Copy the data.
*
* Inputs:        DestPtr       - the dest address
*                SrcPtr        - the source address
*                TotalLength    - the length of data
*
* Outputs:       None
*
* Returns:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, TCPIP_CODE) TcpIp__CopyData
(
    P2VAR(uint8, AUTOMATIC, AUTOMATIC) DestPtr,
    P2CONST(uint8, AUTOMATIC, AUTOMATIC) SrcPtr,
    uint32 TotalLength
)
{
    uint32 i;

    for (i = (uint32)0; i < TotalLength; i++)
    {
        DestPtr[i] = SrcPtr[i];
    }
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: TcpIp__StartDummyAssignment
*
* Description:   This a placeholder.
*
* Inputs:        LocalAddrCtxPtr    - the local address context 
*                AssignmentId       - the assignment id
*
* Outputs:       None
*
* Returns:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, TCPIP_CODE) TcpIp__StartDummyAssignment
(
    /*PRQA S 3673 EOF*/
    P2VAR(TcpIp_LocalAddrType, AUTOMATIC, AUTOMATIC) LocalAddrCtxPtr,
    TcpIp_LocalAddrAssignmentIdType AssignmentId
)
{
    /*PRQA S 3112 EOF*/
    TCPIP_UNUSED(LocalAddrCtxPtr);
    TCPIP_UNUSED(AssignmentId);
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: TcpIp__ReleaseDummyAssignment
*
* Description:   This a placeholder.
*
* Inputs:        LocalAddrCtxPtr    - the local address context 
*                AssignmentId       - the assignment id
*
* Outputs:       None
*
* Returns:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, TCPIP_CODE) TcpIp__ReleaseDummyAssignment
(
    P2VAR(TcpIp_LocalAddrType, AUTOMATIC, AUTOMATIC) LocalAddrCtxPtr,
    TcpIp_LocalAddrAssignmentIdType AssignmentId
)
{
    TCPIP_UNUSED(LocalAddrCtxPtr);
    TCPIP_UNUSED(AssignmentId);
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: TcpIp__GetDummyAssignmentState
*
* Description:   This a placeholder.
*
* Inputs:        LocalAddrCtxPtr    - the local address context 
*                AssignmentId       - the assignment id
*
* Outputs:       None
*
* Returns:       E_NOT_OK
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(Std_ReturnType, TCPIP_CODE) TcpIp__GetDummyAssignmentState
(
    P2VAR(TcpIp_LocalAddrType, AUTOMATIC, AUTOMATIC) LocalAddrCtxPtr,
    TcpIp_LocalAddrAssignmentIdType AssignmentId,
    P2VAR(TcpIp_StaticIpAddrType, AUTOMATIC, AUTOMATIC) IpAddrPtr
)
{
    TCPIP_UNUSED(LocalAddrCtxPtr);
    TCPIP_UNUSED(AssignmentId);
    TCPIP_UNUSED(IpAddrPtr);

    return E_NOT_OK;
}

#if (TCPIP_AUTOIP_ENABLED == STD_ON)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: TcpIp__StartAutoIpAssignment
*
* Description:   Starts the assignment of a AutoIP IP address
*
* Inputs:        LocalAddrCtxPtr    - the local address context 
*                AssignmentId       - the assignment id
*
* Outputs:       None
*
* Returns:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, TCPIP_CODE) TcpIp__StartAutoIpAssignment
(
    P2VAR(TcpIp_LocalAddrType, AUTOMATIC, AUTOMATIC) LocalAddrCtxPtr,
    TcpIp_LocalAddrAssignmentIdType AssignmentId
)
{
    P2VAR(TcpIp_NetIfCtrlType, AUTOMATIC, AUTOMATIC) netCtrl;

    TCPIP_UNUSED(AssignmentId);

    netCtrl = TCPIP_NETCTRL_GET_CONTEXT(LocalAddrCtxPtr->CtrlId);
    if (0 == netCtrl->AutoIpTimeout)
    {
        (void)autoip_start(&netCtrl->NetIf);
    }
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: TcpIp__ReleaseAutoIpAssignment
*
* Description:   Release a assigned AutoIp IP address
*
* Inputs:        LocalAddrCtxPtr    - the local address context 
*                AssignmentId       - the assignment id
*
* Outputs:       None
*
* Returns:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, TCPIP_CODE) TcpIp__ReleaseAutoIpAssignment
(
    P2VAR(TcpIp_LocalAddrType, AUTOMATIC, AUTOMATIC) LocalAddrCtxPtr,
    TcpIp_LocalAddrAssignmentIdType AssignmentId
)
{
    P2VAR(TcpIp_NetIfCtrlType, AUTOMATIC, AUTOMATIC) netCtrl;
    P2CONST(TcpIp_NetIfCtrlConfigType, TCPIP_CONFIG_DATA, AUTOMATIC) ctrlConfig;

    TCPIP_UNUSED(AssignmentId);

    netCtrl = TCPIP_NETCTRL_GET_CONTEXT(LocalAddrCtxPtr->CtrlId);
    if (0 == netCtrl->AutoIpTimeout)
    {
        (void)autoip_stop(&netCtrl->NetIf);
    }

    ctrlConfig = TCPIP_NETCTRL_GET_CONFIG(LocalAddrCtxPtr->CtrlId);
    if ((!TCPIP_NETCTRL_IPV4_CTRL_DISABLED(ctrlConfig))
        && (!TCPIP_IPV4CTRL_AUTOIP_DISABLED(TCPIP_IPV4_GET_CONFIG(ctrlConfig->IpV4CtrlId))))
    {
        netCtrl->AutoIpTimeout = TCPIP_MAKE_TIMEOUT(TCPIP_IPV4_GET_CONFIG(ctrlConfig->IpV4CtrlId)->AutoIpInitTimeout);
    }
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: TcpIp__GetAutoIpAssignmentState
*
* Description:   Get the assignment state of a AutoIp IP address and its value.
*
* Inputs:        LocalAddrCtxPtr    - the local address context 
*                AssignmentId       - the assignment id
*
* Outputs:       IpAddrPtr          - the AutoIp IP address
*
* Returns:       E_OK       - the AutoIp IP address was assigned.
*                E_NOT_OK   - the AutoIp IP address was NOT assigned.
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(Std_ReturnType, TCPIP_CODE) TcpIp__GetAutoIpAssignmentState
(
    P2VAR(TcpIp_LocalAddrType, AUTOMATIC, AUTOMATIC) LocalAddrCtxPtr,
    TcpIp_LocalAddrAssignmentIdType AssignmentId,
    P2VAR(TcpIp_StaticIpAddrType, AUTOMATIC, AUTOMATIC) IpAddrPtr
)
{
    P2VAR(TcpIp_NetIfCtrlType, AUTOMATIC, AUTOMATIC) netCtrl;
    Std_ReturnType ret = E_NOT_OK;
    /*PRQA S 0781 EOF*/
    uint32 netmask;

    TCPIP_UNUSED(AssignmentId);

    netCtrl = TCPIP_NETCTRL_GET_CONTEXT(LocalAddrCtxPtr->CtrlId);
    if (netCtrl->AutoIpTimeout > 0)
    {
        netCtrl->AutoIpTimeout--;
        if (0 == netCtrl->AutoIpTimeout)
        {
            (void)autoip_start(&netCtrl->NetIf);
        }
    }
    /*PRQA S 3344 EOF*/
    else if (autoip_supplied_address(&netCtrl->NetIf))
    {
        if (IpAddrPtr != NULL_PTR)
        {
            netmask = TCPIP_LWIP_GET_NETMASK(&netCtrl->NetIf);
            IpAddrPtr->Domain = TCPIP_AF_INET;
            IpAddrPtr->IpAddr.Addr[0] = TCPIP_LWIP_GET_IPV4ADDR(&netCtrl->NetIf);
            IpAddrPtr->DefaultRouter.Addr[0] = TCPIP_LWIP_GET_GW(&netCtrl->NetIf);
            IpAddrPtr->Netmask = TcpIp__NetmaskToCIDR(netmask);
        }

        ret = E_OK;
    }
    else
    {
        /*do nothing*/
    }

    return ret;
}
#endif /*TCPIP_AUTOIP_ENABLED == STD_ON*/

#if (TCPIP_DHCP_CLIENT_ENABLED == STD_ON)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: TcpIp__StartDhcpV4Assignment
*
* Description:   Starts the assignment of a DHCP IP address
*
* Inputs:        LocalAddrCtxPtr    - the local address context 
*                AssignmentId       - the assignment id
*
* Outputs:       None
*
* Returns:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, TCPIP_CODE) TcpIp__StartDhcpV4Assignment
(
    P2VAR(TcpIp_LocalAddrType, AUTOMATIC, AUTOMATIC) LocalAddrCtxPtr,
    TcpIp_LocalAddrAssignmentIdType AssignmentId
)
{
    P2VAR(TcpIp_NetIfCtrlType, AUTOMATIC, AUTOMATIC) netCtrl;

    TCPIP_UNUSED(AssignmentId);

    netCtrl = TCPIP_NETCTRL_GET_CONTEXT(LocalAddrCtxPtr->CtrlId);
    (void)dhcp_start(&netCtrl->NetIf);
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: TcpIp__ReleaseDhcpV4Assignment
*
* Description:   Release a assigned DHCP IP address
*
* Inputs:        LocalAddrCtxPtr    - the local address context 
*                AssignmentId       - the assignment id
*
* Outputs:       None
*
* Returns:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, TCPIP_CODE) TcpIp__ReleaseDhcpV4Assignment
(
    P2VAR(TcpIp_LocalAddrType, AUTOMATIC, AUTOMATIC) LocalAddrCtxPtr,
    TcpIp_LocalAddrAssignmentIdType AssignmentId
)
{
    P2VAR(TcpIp_NetIfCtrlType, AUTOMATIC, AUTOMATIC) netCtrl;

    TCPIP_UNUSED(AssignmentId);

    netCtrl = TCPIP_NETCTRL_GET_CONTEXT(LocalAddrCtxPtr->CtrlId);
    (void)dhcp_release(&netCtrl->NetIf);
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: TcpIp__GetDhcpV4AssignmentState
*
* Description:   Get the assignment state of a DHCP IP address and its value.
*
* Inputs:        LocalAddrCtxPtr    - the local address context 
*                AssignmentId       - the assignment id
*
* Outputs:       IpAddrPtr          - the DHCP IP address
*
* Returns:       E_OK       - the DHCP IP address was assigned.
*                E_NOT_OK   - the DHCP IP address was NOT assigned.
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(Std_ReturnType, TCPIP_CODE) TcpIp__GetDhcpV4AssignmentState
(
    P2VAR(TcpIp_LocalAddrType, AUTOMATIC, AUTOMATIC) LocalAddrCtxPtr,
    TcpIp_LocalAddrAssignmentIdType AssignmentId,
    P2VAR(TcpIp_StaticIpAddrType, AUTOMATIC, AUTOMATIC) IpAddrPtr
)
{
    P2VAR(TcpIp_NetIfCtrlType, AUTOMATIC, AUTOMATIC) netCtrl;
    Std_ReturnType ret = E_NOT_OK;
    uint32 netmask;

    TCPIP_UNUSED(AssignmentId);
    
    netCtrl = TCPIP_NETCTRL_GET_CONTEXT(LocalAddrCtxPtr->CtrlId);
    /*PRQA S 3344 EOF*/
    if (dhcp_supplied_address(&netCtrl->NetIf))
    {
        if (IpAddrPtr != NULL_PTR)
        {
            netmask = TCPIP_LWIP_GET_NETMASK(&netCtrl->NetIf);
            IpAddrPtr->Domain = TCPIP_AF_INET;
            IpAddrPtr->IpAddr.Addr[0] = TCPIP_LWIP_GET_IPV4ADDR(&netCtrl->NetIf);
            IpAddrPtr->DefaultRouter.Addr[0] = TCPIP_LWIP_GET_GW(&netCtrl->NetIf);
            IpAddrPtr->Netmask = TcpIp__NetmaskToCIDR(netmask);
        }

        ret = E_OK;
    }

    return ret;
}
#endif /*TCPIP_DHCP_CLIENT_ENABLED == STD_ON*/

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: TcpIp__StartStaticIpV4Assignment
*
* Description:   Starts the assignment of a static IP address
*
* Inputs:        LocalAddrCtxPtr    - the local address context 
*                AssignmentId       - the assignment id
*
* Outputs:       None
*
* Returns:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, TCPIP_CODE) TcpIp__StartStaticIpV4Assignment
(
    P2VAR(TcpIp_LocalAddrType, AUTOMATIC, AUTOMATIC) LocalAddrCtxPtr,
    TcpIp_LocalAddrAssignmentIdType AssignmentId
)
{
    P2VAR(TcpIp_NetIfCtrlType, AUTOMATIC, AUTOMATIC) netCtrl;
    ip_addr_t ipaddr;
    ip_addr_t netmask;
    ip_addr_t gw;
    uint32 tmp;

    TCPIP_UNUSED(AssignmentId);

    TCPIP_LWIP_COPY_IPADDR((ip4_addr_t*)&ipaddr, LocalAddrCtxPtr->ConfigPtr->Domain, &LocalAddrCtxPtr->StaticIpAddr.IpAddr);
    netCtrl = TCPIP_NETCTRL_GET_CONTEXT(LocalAddrCtxPtr->CtrlId);
    if (TCPIP_LOCALADDR_IS_UNICAST_IPADDR(LocalAddrCtxPtr->ConfigPtr))
    {
        TCPIP_LWIP_COPY_IPADDR((ip4_addr_t*)&gw, LocalAddrCtxPtr->ConfigPtr->Domain, &LocalAddrCtxPtr->StaticIpAddr.DefaultRouter);
        tmp = TCPIP_CIDR_TO_NETMASK(LocalAddrCtxPtr->StaticIpAddr.Netmask);
        TCPIP_LWIP_SET_NETMASK((ip4_addr_t*)&netmask, tmp);
        netif_set_addr(&netCtrl->NetIf, (ip4_addr_t*)&ipaddr, (ip4_addr_t*)&netmask, (ip4_addr_t*)&gw);
    }
#if (TCPIP_IGMP_ENABLED == STD_ON)
    else if (TCPIP_LOCALADDR_IS_MULTICAST_IPADDR(LocalAddrCtxPtr->ConfigPtr))
    {
        /*SWS_TCPIP_00080*/
        (void)igmp_joingroup_netif(&netCtrl->NetIf, &ipaddr);
    }
#endif
    else
    {
        /*broadcast for IPv4*/
        /*do nothing*/
    }
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: TcpIp__ReleaseStaticIpV4Assignment
*
* Description:   Release a assigned static IP address
*
* Inputs:        LocalAddrCtxPtr    - the local address context 
*                AssignmentId       - the assignment id
*
* Outputs:       None
*
* Returns:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, TCPIP_CODE) TcpIp__ReleaseStaticIpV4Assignment
(
    P2VAR(TcpIp_LocalAddrType, AUTOMATIC, AUTOMATIC) LocalAddrCtxPtr,
    TcpIp_LocalAddrAssignmentIdType AssignmentId
)
{
    P2VAR(TcpIp_NetIfCtrlType, AUTOMATIC, AUTOMATIC) netCtrl;
    /*PRQA S 3196 EOF*/
    ip_addr_t ipaddr;

    TCPIP_UNUSED(AssignmentId);

    netCtrl = TCPIP_NETCTRL_GET_CONTEXT(LocalAddrCtxPtr->CtrlId);
    if (TCPIP_LOCALADDR_IS_UNICAST_IPADDR(LocalAddrCtxPtr->ConfigPtr))
    {
        if (AssignmentId == LocalAddrCtxPtr->AssignedId)
        {
            /*PRQA S 3321 EOF*/
            TCPIP_UNUSED(ipaddr);
            netif_set_addr(&netCtrl->NetIf, IP4_ADDR_ANY, IP4_ADDR_ANY, IP4_ADDR_ANY);
        }
    }
#if (TCPIP_IGMP_ENABLED == STD_ON)
    else if (TCPIP_LOCALADDR_IS_MULTICAST_IPADDR(LocalAddrCtxPtr->ConfigPtr))
    {
        TCPIP_LWIP_COPY_IPADDR((ip4_addr_t*)&ipaddr, LocalAddrCtxPtr->ConfigPtr->Domain, &LocalAddrCtxPtr->StaticIpAddr.IpAddr);
        (void)igmp_leavegroup_netif(&netCtrl->NetIf, &ipaddr);
    }
#endif
    else
    {
        /*do nothing*/
    }
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: TcpIp__GetStaticIpV4AssignmentState
*
* Description:   Get the assignment state of a static IP address and its value.
*
* Inputs:        LocalAddrCtxPtr    - the local address context 
*                AssignmentId       - the assignment id
*
* Outputs:       IpAddrPtr          - the static IP address
*
* Returns:       E_OK       - the static IP address was assigned.
*                E_NOT_OK   - the static IP address was NOT assigned.
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(Std_ReturnType, TCPIP_CODE) TcpIp__GetStaticIpV4AssignmentState
(
    P2VAR(TcpIp_LocalAddrType, AUTOMATIC, AUTOMATIC) LocalAddrCtxPtr,
    TcpIp_LocalAddrAssignmentIdType AssignmentId,
    P2VAR(TcpIp_StaticIpAddrType, AUTOMATIC, AUTOMATIC) IpAddrPtr
)
{
    P2VAR(TcpIp_NetIfCtrlType, AUTOMATIC, AUTOMATIC) netCtrl;
    ip4_addr_t ipaddr;
    Std_ReturnType ret = E_NOT_OK;

    TCPIP_UNUSED(AssignmentId);

    TCPIP_LWIP_COPY_IPADDR((ip4_addr_t*)&ipaddr, LocalAddrCtxPtr->ConfigPtr->Domain, &LocalAddrCtxPtr->StaticIpAddr.IpAddr);
    netCtrl = TCPIP_NETCTRL_GET_CONTEXT(LocalAddrCtxPtr->CtrlId);
    if (TCPIP_LOCALADDR_IS_UNICAST_IPADDR(LocalAddrCtxPtr->ConfigPtr))
    {
        if (ip4_addr_cmp(netif_ip4_addr(&netCtrl->NetIf), (ip4_addr_t*)&ipaddr))
        {
            ret = E_OK;
        }
    }
#if (TCPIP_IGMP_ENABLED == STD_ON)
    else if (TCPIP_LOCALADDR_IS_MULTICAST_IPADDR(LocalAddrCtxPtr->ConfigPtr))
    {
        if (igmp_lookfor_group(&netCtrl->NetIf, &ipaddr) != NULL_PTR)
        {
            ret = E_OK;
        }
    }
#endif
    else
    {
        /*broadcast for IPv4*/
        if ((!ip4_addr_isany_val(ipaddr)) && (ip4_addr_netcmp(netif_ip4_addr(&netCtrl->NetIf), (ip4_addr_t*)&ipaddr, &(netCtrl)->NetIf.netmask)))
        {
            ret = E_OK;
            
        }
    }

    if ((E_OK == ret) && (IpAddrPtr != NULL_PTR))
    {
        /*PRQA S 3138 EOF*/
        SchM_Enter_TcpIp_TCPIP_EXCLUSIVE_AREA_2();
        TCPIP_COPY_STATICIPADDR(IpAddrPtr, &LocalAddrCtxPtr->StaticIpAddr);
        SchM_Exit_TcpIp_TCPIP_EXCLUSIVE_AREA_2();
    }

    return ret;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: TcpIp__CheckStaticIpAddr
*
* Description:   Check if a static IP address is valid.
*
* Inputs:        LocalAddrConfigPtr - the configurations of a local address 
*                LocalIpAddrPtr     - the local IP address
*                Netmask            - the netmask
*                DefaultRouterPtr   - the IP address of default router
*
* Outputs:       None
*
* Returns:       E_OK       - the static IP address is valid.
*                E_NOT_OK   - error
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(Std_ReturnType, TCPIP_CODE) TcpIp__CheckStaticIpAddr
(
    P2CONST(TcpIp_LocalAddrConfigType, TCPIP_CONFIG_DATA, AUTOMATIC) LocalAddrConfigPtr,
    P2CONST(TcpIp_SockAddrType, AUTOMATIC, AUTOMATIC) LocalIpAddrPtr,
    uint8 Netmask,
    P2CONST(TcpIp_SockAddrType, AUTOMATIC, AUTOMATIC) DefaultRouterPtr
)
{
    /*PRQA S 3205 EOF*/
    P2CONST(TcpIp_SockAddrRealType, AUTOMATIC, AUTOMATIC) multicastAddr;
    Std_ReturnType ret = E_NOT_OK;

    if ((LocalIpAddrPtr->Domain == DefaultRouterPtr->Domain)
        && (LocalAddrConfigPtr->Domain == LocalIpAddrPtr->Domain)
        && TCPIP_IS_VALID_NETMASK(LocalAddrConfigPtr->Domain, Netmask))
    {
#if (TCPIP_IGMP_ENABLED == STD_ON)
        if (TCPIP_LOCALADDR_IS_MULTICAST_IPADDR(LocalAddrConfigPtr))
        {
            /*PRQA S 3305,0310 EOF*/
            multicastAddr = (P2CONST(TcpIp_SockAddrRealType, AUTOMATIC, AUTOMATIC))LocalIpAddrPtr;
            if (TCPIP_IS_VALID_MULTICAST_IPADDR(LocalAddrConfigPtr->Domain, multicastAddr))
            {
                ret = E_OK;
            }
        }
        else
#endif
        {
            ret = E_OK;
        }
    }

    return ret;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: TcpIp__GetAssignmentIdByMethod
*
* Description:   Get a assignment id by assignment method.
*
* Inputs:        LocalAddrPtr   - the local address context
*                Method         - the assignment method
*
* Outputs:       None
*
* Returns:       a assignment id.
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(TcpIp_LocalAddrAssignmentIdType, TCPIP_CODE) TcpIp__GetAssignmentIdByMethod
(
    P2VAR(TcpIp_LocalAddrType, AUTOMATIC, AUTOMATIC) LocalAddrPtr,
    TcpIp_IpAddrAssignmentType Method
)
{
    TcpIp_LocalAddrAssignmentIdType id;

    for (id = (uint8)0 ; id < (uint8)TCPIP_LOCALADDR_ASSIGNMENT_PRIORITY_MAX; id++)
    {
        if (TCPIP_LOCALADDR_GET_ASSIGNMENT_METHOD(LocalAddrPtr->ConfigPtr, id) == Method)
        {
            break;
        }
    }

    return id;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: TcpIp__ReleaseLocalAddrByRequest
*
* Description:   Release a assignment by user request.
*
* Inputs:        LocalAddrId    - the local address id
*
* Outputs:       None
*
* Returns:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, TCPIP_CODE) TcpIp__ReleaseLocalAddrByRequest
(
    P2VAR(TcpIp_LocalAddrType, AUTOMATIC, AUTOMATIC) LocalAddrCtxPtr
)
{
    TcpIp_LocalAddrAssignmentIdType id;
    TcpIp_LocalAddrAssignmentStatusType releaseStatus;

    releaseStatus = TCPIP_LOCALADDR_GET_NEW_ASSIGNMENT_RELEASE(LocalAddrCtxPtr);
    for (id = (uint8)0 ; id < (uint8)TCPIP_LOCALADDR_ASSIGNMENT_PRIORITY_MAX; id++)
    {
        /*PRQA S 3344,4130,4397,4571 EOF*/
        if (releaseStatus & ((uint8)0x01<< id))
        {
            /*PRQA S 4130,0290,4570,4571 EOF*/
            TCPIP_LOCALADDR_CLEAR_STARTED_ASSIGNMENT(LocalAddrCtxPtr, id);
            TCPIP_LOCALADDR_RELEASE_ASSIGNMENT(LocalAddrCtxPtr, id);
        }
    }
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: TcpIp__AssignLocalAddrByRequest
*
* Description:   Start a assignment by user request.
*
* Inputs:        LocalAddrCtxPtr    - the local address context
*
* Outputs:       None
*
* Returns:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, TCPIP_CODE) TcpIp__AssignLocalAddrByRequest
(
    P2VAR(TcpIp_LocalAddrType, AUTOMATIC, AUTOMATIC) LocalAddrCtxPtr
)
{
    TcpIp_LocalAddrAssignmentIdType id;
    TcpIp_LocalAddrAssignmentIdType i;
    TcpIp_LocalAddrAssignmentStatusType requestStatus;

    requestStatus = TCPIP_LOCALADDR_GET_NEW_ASSIGNMENT_REQUEST(LocalAddrCtxPtr);
    /*PRQA S 3418,2463 EOF*/
    for (i = (uint8)0, id = (uint8)TCPIP_LOCALADDR_ASSIGNMENT_PRIORITY_3 ; i < (uint8)TCPIP_LOCALADDR_ASSIGNMENT_PRIORITY_MAX;i++, id--)
    {
        /*low to high priority*/
        if  ( (((uint32)requestStatus & ((uint32)0x01 << (uint32)id)) > (uint32)0) && ((uint32)id < (uint32)(LocalAddrCtxPtr->AssignedId)) )
        {
            TCPIP_LOCALADDR_SET_STARTED_ASSIGNMENT(LocalAddrCtxPtr, id);
            TCPIP_LOCALADDR_START_ASSIGNMENT(LocalAddrCtxPtr, id);
        }
    }
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: TcpIp__GetNewAssignedLocalAddrId
*
* Description:   Get a New assigned id of assignment method.
*
* Inputs:        LocalAddrCtxPtr    - the local address context
*                IpAddrPtr          - the local address
*
* Outputs:       None
*
* Returns:       id of assignment method and IP address.
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(TcpIp_LocalAddrAssignmentIdType, TCPIP_CODE) TcpIp__GetNewAssignedLocalAddrId
(
    P2VAR(TcpIp_LocalAddrType, AUTOMATIC, AUTOMATIC) LocalAddrCtxPtr,
    P2VAR(TcpIp_StaticIpAddrType, AUTOMATIC, AUTOMATIC) IpAddrPtr
)
{
    TcpIp_LocalAddrAssignmentIdType id;
    TcpIp_LocalAddrAssignmentIdType ret = (uint8)TCPIP_LOCALADDR_ASSIGNMENT_PRIORITY_MAX;

    for (id = (uint8)0 ; id < LocalAddrCtxPtr->AssignedId; id++)
    {
        /*PRQA S 3415 EOF*/
        if (TCPIP_LOCALADDR_IS_STARTED_ASSIGNMENT(LocalAddrCtxPtr, id)
            && (TCPIP_LOCALADDR_GET_ASSIGNMENT_STATE(LocalAddrCtxPtr, id, IpAddrPtr) == E_OK))
        {
            ret = id;
            break;
        }
    }

    return ret;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: TcpIp__ReleaseLocalAddrByPriority
*
* Description:   Release all assigned local address by priority.
*
* Inputs:        LocalAddrId    - the local address id
*                Priority       - the priority
*
* Outputs:       None
*
* Returns:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, TCPIP_CODE) TcpIp__ReleaseLocalAddrByPriority
(
    TcpIp_LocalAddrIdType LocalAddrId,
    TcpIp_LocalAddrAssignmentIdType Priority
)
{
    P2VAR(TcpIp_LocalAddrType, AUTOMATIC, AUTOMATIC) localAddrCtx = TCPIP_LOCALADDR_GET_CONTEXT(LocalAddrId);
    TcpIp_LocalAddrAssignmentIdType id;

    for (id = Priority; id < (uint8)TCPIP_LOCALADDR_ASSIGNMENT_PRIORITY_MAX; id++)
    {
        if (TCPIP_LOCALADDR_IS_STARTED_ASSIGNMENT(localAddrCtx, id))
        {
            TCPIP_LOCALADDR_RELEASE_ASSIGNMENT(localAddrCtx, id);
            TCPIP_LOCALADDR_CLEAR_STARTED_ASSIGNMENT(localAddrCtx, id);
        }
    }
}

#if (TCPIP_IGMP_ENABLED == STD_ON)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: TcpIp__AssignMultiAddrByRequest
*
* Description:   Start a multicast local address assignment by user request.
*
* Inputs:        LocalAddrId    - the local address ID
*
* Outputs:       None
*
* Returns:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, TCPIP_CODE) TcpIp__AssignMulticastAddrByRequest
(
    TcpIp_LocalAddrIdType LocalAddrId
)
{
    P2VAR(TcpIp_LocalAddrType, AUTOMATIC, AUTOMATIC) localAddrCtx;
    TcpIp_LocalAddrAssignmentStatusType requestStatus;

    localAddrCtx = TCPIP_LOCALADDR_GET_CONTEXT(LocalAddrId);
    requestStatus = TCPIP_LOCALADDR_GET_NEW_ASSIGNMENT_REQUEST(localAddrCtx);
    if ((requestStatus & (0x01 << TCPIP_LOCALADDR_ASSIGNMENT_PRIORITY_1)) > 0)
    {
        TCPIP_LOCALADDR_SET_STARTED_ASSIGNMENT(localAddrCtx, TCPIP_LOCALADDR_ASSIGNMENT_PRIORITY_1);
        TCPIP_LOCALADDR_START_ASSIGNMENT(localAddrCtx, TCPIP_LOCALADDR_ASSIGNMENT_PRIORITY_1);
        localAddrCtx->AssignedId = TCPIP_LOCALADDR_ASSIGNMENT_PRIORITY_1;
        /*notify EthSM*/    /*PRQA S 3200 EOF*/
        TCPIP_LOCALADDR_NOTIFY_STATE(LocalAddrId, TCPIP_IPADDR_STATE_ASSIGNED);
    }
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: TcpIp__ReleaseMulticastAddrAssignment
*
* Description:   Release a multicast assigned local address.
*
* Inputs:        LocalAddrId    - the multicast address id
*
* Outputs:       None
*
* Returns:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, TCPIP_CODE) TcpIp__ReleaseMulticastAddrAssignment
(
    TcpIp_LocalAddrIdType LocalAddrId
)
{
    P2VAR(TcpIp_LocalAddrType, AUTOMATIC, AUTOMATIC) localAddrCtx;

    localAddrCtx = TCPIP_LOCALADDR_GET_CONTEXT(LocalAddrId);
    if (TCPIP_LOCALADDR_IS_STARTED_ASSIGNMENT(localAddrCtx, TCPIP_LOCALADDR_ASSIGNMENT_PRIORITY_1))
    {
        /*PRQA S 0277 EOF*/
        TCPIP_LOCALADDR_CLEAR_STARTED_ASSIGNMENT(localAddrCtx, TCPIP_LOCALADDR_ASSIGNMENT_PRIORITY_1);
        TCPIP_LOCALADDR_RELEASE_ASSIGNMENT(localAddrCtx, TCPIP_LOCALADDR_ASSIGNMENT_PRIORITY_1);
        TCPIP_LOCALADDR_CLEAR_ASSIGNED_ID(localAddrCtx);
        /*notify EthSM*/
        TCPIP_LOCALADDR_NOTIFY_STATE(LocalAddrId, TCPIP_IPADDR_STATE_UNASSIGNED);
    }
}
#endif

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: TcpIp__CheckAssignedIpAddr
*
* Description:   Check if a local address was assigned.
*
* Inputs:        LocalAddrPtr   - the local address context
*
* Outputs:       None
*
* Returns:       TCPIP_IPADDR_STATE_ASSIGNED or TCPIP_IPADDR_STATE_UNASSIGNED.
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(TcpIp_IpAddrStateType, TCPIP_CODE) TcpIp__CheckAssignedIpAddr
(
    P2VAR(TcpIp_LocalAddrType, AUTOMATIC, AUTOMATIC) LocalAddrPtr
)
{
    TcpIp_IpAddrStateType state;
    if (TCPIP_LOCALADDR_IS_VALID_ASSIGNED_ID(LocalAddrPtr->AssignedId))
    {
        state = TCPIP_IPADDR_STATE_ASSIGNED;
    }
    else
    {
        state = TCPIP_IPADDR_STATE_UNASSIGNED;
    }

    return state;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: TcpIp__CheckAssignedUnicastAddr
*
* Description:   Check if a unicast local address was assigned.
*
* Inputs:        CtrlPtr   - the netCtrl context
*
* Outputs:       None
*
* Returns:       TCPIP_IPADDR_STATE_ASSIGNED or TCPIP_IPADDR_STATE_UNASSIGNED.
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(TcpIp_IpAddrStateType, TCPIP_CODE) TcpIp__CheckAssignedUnicastAddr
(
    P2VAR(TcpIp_NetIfCtrlType, AUTOMATIC, AUTOMATIC) CtrlPtr
)
{
    P2VAR(TcpIp_LocalAddrType, AUTOMATIC, AUTOMATIC) localAddr;
    TcpIp_LocalAddrIdType id = TCPIP_NETCTRL_GET_UNICASTADDR_ID(CtrlPtr);
    TcpIp_LocalAddrIdType limit = TCPIP_NETCTRL_GET_UNICASTADDR_LIMIT(CtrlPtr);
    TcpIp_IpAddrStateType state = TCPIP_IPADDR_STATE_UNASSIGNED;

    for (; id < limit; id++)
    {
        localAddr = TCPIP_LOCALADDR_GET_CONTEXT(id);
        if (TCPIP_LOCALADDR_IS_VALID_ASSIGNED_ID(localAddr->AssignedId))
        {
            state = TCPIP_IPADDR_STATE_ASSIGNED;
            break;
        }
    }

    return state;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: TcpIp__LocalAddrAssignmentHandler
*
* Description:   process the request of local address assignment.
*
* Inputs:        LocalAddrId    - the local address id
*
* Outputs:       None
*
* Returns:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, TCPIP_CODE) TcpIp__LocalAddrAssignmentHandler
(
    P2VAR(TcpIp_LocalAddrType, AUTOMATIC, AUTOMATIC) LocalAddrCtxPtr
)
{
    /*  */
    if (TCPIP_LOCALADDR_GET_NEW_ASSIGNMENT_RELEASE(LocalAddrCtxPtr) > (TcpIp_LocalAddrAssignmentStatusType)0)
    {
        /*SWS_TCPIP_00117*/
        TcpIp__ReleaseLocalAddrByRequest(LocalAddrCtxPtr);
    }

    if (TCPIP_LOCALADDR_GET_NEW_ASSIGNMENT_REQUEST(LocalAddrCtxPtr) > (TcpIp_LocalAddrAssignmentStatusType)0)
    {
        /*SWS_TCPIP_00116*/
        TcpIp__AssignLocalAddrByRequest(LocalAddrCtxPtr);
    }

    (void)TcpIp__GetNewAssignedLocalAddrId(LocalAddrCtxPtr, NULL_PTR);
}

#if (TCPIP_TCP_ENABLED == STD_ON)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: TcpIp__ReleaseTcpTxBuffer
*
* Description:   Release the TX buffer list and free all buffer.
*
* Inputs:        ListPtr    - the list
*
* Outputs:       None
*
* Returns:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
/* PRQA S 4599 EOF*/
STATIC FUNC(void, TCPIP_CODE) TcpIp__ReleaseTcpTxBuffer
(
    P2VAR(TcpIp_TcpTxBufferListType, AUTOMATIC, AUTOMATIC) ListPtr
)
{
    P2VAR(TcpIp_TcpTxBufferHeadType, AUTOMATIC, AUTOMATIC) head;

    while (ListPtr->HeadPtr != NULL_PTR)
    {
        head = ListPtr->HeadPtr;
        ListPtr->HeadPtr = ListPtr->HeadPtr->NextPtr;
        mem_free(head);
    }

    ListPtr->TailPtr = NULL_PTR;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: TcpIp__RemoveTcpTxBufferHead
*
* Description:   Remotes the head buffer in a list.
*
* Inputs:        ListPtr    - the list
*
* Outputs:       None
*
* Returns:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, TCPIP_CODE) TcpIp__RemoveTcpTxBufferHead
(
    P2VAR(TcpIp_TcpTxBufferListType, AUTOMATIC, AUTOMATIC) ListPtr
)
{
    if (ListPtr->HeadPtr != NULL_PTR)
    {
        ListPtr->HeadPtr = ListPtr->HeadPtr->NextPtr;
        if (ListPtr->HeadPtr == NULL_PTR)
        {
            ListPtr->TailPtr = NULL_PTR;
        }
    }
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: TcpIp__InsertTcpTxBufferHead
*
* Description:   Inserts a TX buffer to List.
*
* Inputs:        ListPtr    - the list
*                DataPtr    - the TX buffer
*
* Outputs:       None
*
* Returns:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, TCPIP_CODE) TcpIp__InsertTcpTxBufferHead
(
    P2VAR(TcpIp_TcpTxBufferListType, AUTOMATIC, AUTOMATIC) ListPtr,
    P2VAR(TcpIp_TcpTxBufferHeadType, AUTOMATIC, AUTOMATIC) DataPtr
)
{
    /* PRQA S 4599 EOF*/
    P2VAR(TcpIp_TcpTxBufferHeadType,AUTOMATIC,AUTOMATIC) AvailablePtr;
    if (NULL_PTR == ListPtr->HeadPtr)
    {
        ListPtr->HeadPtr = DataPtr;
        ListPtr->HeadPtr->NextPtr = NULL_PTR;
    }
    else
    {
        for(AvailablePtr = ListPtr->HeadPtr; AvailablePtr->NextPtr != NULL_PTR; AvailablePtr = AvailablePtr->NextPtr);
        AvailablePtr->NextPtr = DataPtr;
        AvailablePtr->NextPtr->NextPtr = NULL_PTR;

    }

    ListPtr->TailPtr = DataPtr;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: TcpIp__ReleaseTcpSocket
*
* Description:   Release a TCP socket.
*
* Inputs:        SocketPtr  - the TCP socket
*
* Outputs:       None
*
* Returns:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, TCPIP_CODE) TcpIp__ReleaseTcpSocket
(
    P2VAR(TcpIp_TcpSocketType, AUTOMATIC, AUTOMATIC) SocketPtr
)
{
    if (SocketPtr->TxBufferList.HeadPtr != NULL_PTR)
    {
        TcpIp__ReleaseTcpTxBuffer(&SocketPtr->TxBufferList);
    }

    if (SocketPtr->WaitConfirmList.HeadPtr != NULL_PTR)
    {
        TcpIp__ReleaseTcpTxBuffer(&SocketPtr->WaitConfirmList);
    }

    SocketPtr->ReceivedDataSize = (uint16)0;
    SocketPtr->LocalAddrId = (uint8)TCPIP_LOCALADDR_TABLE_MAX;
    SocketPtr->NetIfCtrlId = (uint8)TCPIP_NETIF_CTRL_MAX;
    SocketPtr->UpLayer = (TcpIp_UpLayerIndexType)TCPIP_UPLAYER_MAX;
    SocketPtr->Domain = (uint16)0;
    SocketPtr->Abort = (uint8)0;
    SocketPtr->MaxChannels = (uint16)0;
    SocketPtr->PcbPtr = NULL_PTR;
    TCPIP_SOCKET_SET_IDLE(SocketPtr);
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: TcpIp__TcpClosed
*
* Description:   Release the TCP socket and notify the Upper Layer of TcpIp module.
*
* Inputs:        SocketId   - the TCP socket id
*                Event      - the Event
*
* Outputs:       None
*
* Returns:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, TCPIP_CODE) TcpIp__TcpClosed
(
    TcpIp_SocketIdType SocketId,
    TcpIp_EventType Event
)
{
    P2VAR(TcpIp_TcpSocketType, AUTOMATIC, AUTOMATIC) socket = TCPIP_SOCKET_GET_TCPCONTEXT(SocketId);
    /*PRQA S 3203 EOF*/
    TcpIp_UpLayerIndexType index;

    SchM_Enter_TcpIp_TCPIP_EXCLUSIVE_AREA_1();
    /*PRQA S 3199 EOF*/
    index = socket->UpLayer;
    TcpIp__ReleaseTcpSocket(socket);
    SchM_Exit_TcpIp_TCPIP_EXCLUSIVE_AREA_1();
    TCPIP_UPLAYER_CALL_TCPIPEVENT(index, SocketId, Event);
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: TcpIp__CloseTcpSocket
*
* Description:   Close a TCP socket.
*
* Inputs:        SocketId   - the TCP socket id
*
* Outputs:       None
*
* Returns:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, TCPIP_CODE) TcpIp__CloseTcpSocket
(
    TcpIp_SocketIdType SocketId
)
{
    P2VAR(TcpIp_TcpSocketType, AUTOMATIC, AUTOMATIC) tcp = TCPIP_SOCKET_GET_TCPCONTEXT(SocketId);

    if (tcp->PcbPtr != NULL_PTR)
    {
        if (TCPIP_SOCKET_IS_LISTENING(tcp)
            || TCPIP_SOCKET_IS_CLOSE_LISTEN(tcp))
        {
            TCPIP_SOCKET_SET_CLOSE(tcp);
            (void)tcp_close(tcp->PcbPtr);
            TcpIp__TcpClosed(SocketId, TCPIP_TCP_CLOSED);
        }
        else
        {
            TCPIP_SOCKET_SET_CLOSE(tcp);
            tcp_abort(tcp->PcbPtr);
        }
    }
}
#endif

#if (TCPIP_UDP_ENABLED == STD_ON)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: TcpIp__ReleaseUdpSocket
*
* Description:   Release a UDP socket.
*
* Inputs:        SocketPtr  - the UDP socket
*
* Outputs:       None
*
* Returns:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, TCPIP_CODE) TcpIp__ReleaseUdpSocket
(
    P2VAR(TcpIp_UdpSocketType, AUTOMATIC, AUTOMATIC) SocketPtr
)
{
    SocketPtr->LocalAddrId = (uint8)TCPIP_LOCALADDR_TABLE_MAX;
    SocketPtr->NetIfCtrlId = (uint8)TCPIP_NETIF_CTRL_MAX;
    SocketPtr->UpLayer = (TcpIp_UpLayerIndexType)TCPIP_UPLAYER_MAX;
    SocketPtr->Domain = (uint16)0;
    SocketPtr->PcbPtr = NULL_PTR;
    TCPIP_SOCKET_SET_IDLE(SocketPtr);
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: TcpIp__CloseUdpSocket
*
* Description:   Close a UDP socket.
*
* Inputs:        SocketId   - the UDP socket id
*
* Outputs:       None
*
* Returns:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, TCPIP_CODE) TcpIp__CloseUdpSocket
(
    TcpIp_SocketIdType SocketId
)
{
    P2VAR(TcpIp_UdpSocketType, AUTOMATIC, AUTOMATIC) socket = TCPIP_SOCKET_GET_UDPCONTEXT(SocketId);
    /*PRQA S 3203 EOF*/
    TcpIp_UpLayerIndexType index;

    udp_remove(socket->PcbPtr);
    SchM_Enter_TcpIp_TCPIP_EXCLUSIVE_AREA_1();
    /*PRQA S 3199 EOF*/
    index = socket->UpLayer;
    TcpIp__ReleaseUdpSocket(socket);
    SchM_Exit_TcpIp_TCPIP_EXCLUSIVE_AREA_1();
#if (TCPIP_TCP_ENABLED == STD_ON)
    SocketId += (TcpIp_SocketIdType)TCPIP_TCP_SOCKET_MAX;
#endif
    TCPIP_UPLAYER_CALL_TCPIPEVENT(index, SocketId, TCPIP_UDP_CLOSED);
}
#endif

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: TcpIp__CloseAllSocket
*
* Description:   Close all socket.
*
* Inputs:        None
*
* Outputs:       None
*
* Returns:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, TCPIP_CODE) TcpIp__CloseAllSocket
(
    void
)
{
    TcpIp_SocketIdType socketId;
    P2VAR(TcpIp_UdpSocketType, AUTOMATIC, AUTOMATIC) udp;
#if (TCPIP_TCP_ENABLED == STD_ON)
    for (socketId = (uint8)0; socketId < (TcpIp_SocketIdType)TCPIP_TCP_SOCKET_MAX; socketId++)
    {
        TcpIp__CloseTcpSocket(socketId);
    }
#endif

#if (TCPIP_UDP_ENABLED == STD_ON)
    for (socketId = (uint8)0; socketId < (TcpIp_SocketIdType)TCPIP_UDP_SOCKET_MAX; socketId++)
    {
		udp = TCPIP_SOCKET_GET_UDPCONTEXT(socketId);
        if (udp->PcbPtr != NULL_PTR)
        {
            TCPIP_SOCKET_SET_CLOSE(udp);
            TcpIp__CloseUdpSocket(socketId);
        }
    }
#endif
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: TcpIp__CloseSocketByNetCtrl
*
* Description:   Close all socket of a NetIfCtrl.
*
* Inputs:        CtrlPtr    - the NetIfCtrl
*
* Outputs:       None
*
* Returns:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, TCPIP_CODE) TcpIp__CloseSocketByNetCtrl
(
    P2VAR(TcpIp_NetIfCtrlType, AUTOMATIC, AUTOMATIC) CtrlPtr
)
{
    TcpIp_SocketIdType socketId;
    P2VAR(TcpIp_TcpSocketType, AUTOMATIC, AUTOMATIC) tcp;
    P2VAR(TcpIp_UdpSocketType, AUTOMATIC, AUTOMATIC) udp;
#if (TCPIP_TCP_ENABLED == STD_ON)
    for (socketId = (uint8)0; socketId < (TcpIp_SocketIdType)TCPIP_TCP_SOCKET_MAX; socketId++)
    {
    	tcp = TCPIP_SOCKET_GET_TCPCONTEXT(socketId);
        if (TCPIP_NETCTRL_IS_VALID_ID(tcp->NetIfCtrlId)
            && (TCPIP_NETCTRL_GET_CONTEXT(tcp->NetIfCtrlId) == CtrlPtr))
        {
            TcpIp__CloseTcpSocket(socketId);
        }
    }
#endif

#if (TCPIP_UDP_ENABLED == STD_ON)
    for (socketId = (uint8)0; socketId < (TcpIp_SocketIdType)TCPIP_UDP_SOCKET_MAX; socketId++)
    {

    	udp = TCPIP_SOCKET_GET_UDPCONTEXT(socketId);
        if (TCPIP_NETCTRL_IS_VALID_ID(udp->NetIfCtrlId)
            && (TCPIP_NETCTRL_GET_CONTEXT(udp->NetIfCtrlId) == CtrlPtr)
            && (udp->PcbPtr != NULL_PTR))
        {
            TCPIP_SOCKET_SET_CLOSE(udp);
            TcpIp__CloseUdpSocket(socketId);
        }
    }
#endif
}

#if (TCPIP_NETIF_CTRL_MAX > 1)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: TcpIp__IsAllNetCtrlDown
*
* Description:   Check if all NetIfCtrl are down.
*
* Inputs:        None
*
* Outputs:       None
*
* Returns:       If all NetIfCtrl are down returns E_OK, otherwise returns E_NOT_OK
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(Std_ReturnType, TCPIP_CODE) TcpIp__IsAllNetCtrlDown
(
    void
)
{
    Std_ReturnType ret = E_OK;
    TcpIp_CtrlIdType i;

    for (i = 0; i < TCPIP_NETIF_CTRL_MAX; i++)
    {
        if (!TCPIP_NETCTRL_IS_DOWN(i))
        {
            ret = E_NOT_OK;
            break;
        }
    }

    return ret;
}
#endif

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: TcpIp__ComStateIdle
*
* Description:   The handler that process idle
*
* Inputs:        CtrlPtr    - the NetIfCtrl
*
* Outputs:       None
*
* Returns:       TCPIP_COMSTATE_HANDLER_DONE
*
* Limitations:   Only called by TcpIp_MainFunction.
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(uint8, TCPIP_CODE) TcpIp__ComStateIdle
(
    P2VAR(TcpIp_NetIfCtrlType, AUTOMATIC, AUTOMATIC) CtrlPtr
)
{
    TCPIP_UNUSED(CtrlPtr);
    return (uint8)TCPIP_COMSTATE_HANDLER_DONE;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: TcpIp__ComStateOfflineToOnline
*
* Description:   The handler that process offline to online
*
* Inputs:        CtrlPtr    - the NetIfCtrl
*
* Outputs:       None
*
* Returns:       TCPIP_COMSTATE_HANDLER_AGAIN
*
* Limitations:   Only called by TcpIp_MainFunction.
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(uint8, TCPIP_CODE) TcpIp__ComStateOfflineToOnline
(
    P2VAR(TcpIp_NetIfCtrlType, AUTOMATIC, AUTOMATIC) CtrlPtr
)
{
    TcpIp_LocalAddrIdType id = TCPIP_NETCTRL_GET_UNICASTADDR_ID(CtrlPtr);
    TcpIp_LocalAddrIdType limit = TCPIP_NETCTRL_GET_UNICASTADDR_LIMIT(CtrlPtr);

    TCPIP_NETCTRL_SET_LINK_UP(CtrlPtr);
    /*SWS_TCPIP_00075.a*/
    for (; id < limit; id++)
    {
        /*SWS_TCPIP_00071*/
        TcpIp__AssignLocalAddrByRequest(TCPIP_LOCALADDR_GET_CONTEXT(id));
    }

#if (TCPIP_IGMP_ENABLED == STD_ON)
    id = TCPIP_NETCTRL_GET_MULTICASTADDR_ID(CtrlPtr);
    limit = TCPIP_NETCTRL_GET_LOCALADDR_LIMIT(CtrlPtr);
    for (; id < limit; id++)
    {
        /*SWS_TCPIP_00071*/
        TcpIp__AssignMulticastAddrByRequest(id);
    }
#endif

    /*SWS_TCPIP_00075.b*/
    TCPIP_NETCTRL_GOTO_STARTUP(CtrlPtr);
    /*Do NOT notify EthSM*/

    return (uint8)TCPIP_COMSTATE_HANDLER_AGAIN;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: TcpIp__ComStateOnlineToOffline
*
* Description:   The handler that process online to offline
*
* Inputs:        CtrlPtr    - the NetIfCtrl
*
* Outputs:       None
*
* Returns:       TCPIP_COMSTATE_HANDLER_AGAIN
*
* Limitations:   Only called by TcpIp_MainFunction.
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(uint8, TCPIP_CODE) TcpIp__ComStateOnlineToOffline
(
    P2VAR(TcpIp_NetIfCtrlType, AUTOMATIC, AUTOMATIC) CtrlPtr
)
{
    TcpIp_LocalAddrIdType id = TCPIP_NETCTRL_GET_UNICASTADDR_ID(CtrlPtr);
    TcpIp_LocalAddrIdType limit = TCPIP_NETCTRL_GET_UNICASTADDR_LIMIT(CtrlPtr);

    /*SWS_TCPIP_00072*//*SWS_TCPIP_00077.b*/
    TCPIP_NETCTRL_SET_LINK_DOWN(CtrlPtr);
    
    /*SWS_TCPIP_00077.c*/
    TcpIp__CloseSocketByNetCtrl(CtrlPtr);
    /*SWS_TCPIP_00077.a*/
    for (; id < limit; id++)
    {
        /*SWS_TCPIP_00072*/
        TcpIp__ReleaseLocalAddrByPriority(id, (uint8)TCPIP_LOCALADDR_ASSIGNMENT_PRIORITY_1);
    }

#if (TCPIP_IGMP_ENABLED == STD_ON)
    id = TCPIP_NETCTRL_GET_MULTICASTADDR_ID(CtrlPtr);
    limit = TCPIP_NETCTRL_GET_LOCALADDR_LIMIT(CtrlPtr);
    for (; id < limit; id++)
    {
        TcpIp__ReleaseMulticastAddrAssignment(id);
    }
#endif

    /*SWS_TCPIP_00075.e*/
    TCPIP_NETCTRL_GOTO_SHUTDOWN(CtrlPtr);
    /*Do NOT notify the uplayer*/

    /*SWS_TCPIP_00075.d*/
    if (TCPIP_NETCTRL_IS_ALL_DOWN())
    {
        TcpIp__CloseAllSocket();
    }

    return (uint8)TCPIP_COMSTATE_HANDLER_AGAIN;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: TcpIp__ComStateOnline
*
* Description:   The handler that process online
*
* Inputs:        CtrlPtr    - the NetIfCtrl
*
* Outputs:       None
*
* Returns:       TCPIP_COMSTATE_HANDLER_DONE
*
* Limitations:   Only called by TcpIp_MainFunction.
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(uint8, TCPIP_CODE) TcpIp__ComStateOnline
(
    P2VAR(TcpIp_NetIfCtrlType, AUTOMATIC, AUTOMATIC) CtrlPtr
)
{
    P2VAR(TcpIp_LocalAddrType, AUTOMATIC, AUTOMATIC) localAddrCtx;
    TcpIp_LocalAddrIdType id = TCPIP_NETCTRL_GET_UNICASTADDR_ID(CtrlPtr);
    TcpIp_LocalAddrIdType limit = TCPIP_NETCTRL_GET_UNICASTADDR_LIMIT(CtrlPtr);
    TcpIp_LocalAddrAssignmentStatusType isRequested = (uint8)0;
    uint8 ret = (uint8)TCPIP_COMSTATE_HANDLER_DONE;

    /*SWS_TCPIP_00079*/
    for (; id < limit; id++)
    {
        localAddrCtx = TCPIP_LOCALADDR_GET_CONTEXT(id);
        TcpIp__LocalAddrAssignmentHandler(localAddrCtx);
        isRequested |= TCPIP_LOCALADDR_GET_ASSIGNMENT_REQUEST(localAddrCtx);
    }

    if (isRequested == (uint8)0)
    {
        /*SWS_TCPIP_00077*//*all assigned IP address have been released for an EthIf controller.*/
        TCPIP_NETCTRL_SET_REQUEST_STATE(CtrlPtr, TCPIP_STATE_OFFLINE);
        /*Do NOT notify EthSM*/
        ret = (uint8)TCPIP_COMSTATE_HANDLER_AGAIN;
    }
    else
    {
#if (TCPIP_IGMP_ENABLED == STD_ON)
        id = TCPIP_NETCTRL_GET_MULTICASTADDR_ID(CtrlPtr);
        limit = TCPIP_NETCTRL_GET_LOCALADDR_LIMIT(CtrlPtr);
        for (; id < limit; id++)
        {
            localAddrCtx = TCPIP_LOCALADDR_GET_CONTEXT(id);
            if (TCPIP_LOCALADDR_GET_NEW_ASSIGNMENT_RELEASE(localAddrCtx) > 0)
            {
                /*SWS_TCPIP_00117*/
                TcpIp__ReleaseMulticastAddrAssignment(id);
            }

            if (TCPIP_LOCALADDR_GET_NEW_ASSIGNMENT_REQUEST(localAddrCtx) > 0)
            {
                /*SWS_TCPIP_00116*/
                TcpIp__AssignMulticastAddrByRequest(id);
            }
        }
#endif
    }

    return ret;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: TcpIp__ComStateOnlineToOnhold
*
* Description:   The handler that process online to onhold
*
* Inputs:        CtrlPtr    - the NetIfCtrl
*
* Outputs:       None
*
* Returns:       TCPIP_COMSTATE_HANDLER_DONE
*
* Limitations:   Only called by TcpIp_MainFunction.
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(uint8, TCPIP_CODE) TcpIp__ComStateOnlineToOnhold
(
    P2VAR(TcpIp_NetIfCtrlType, AUTOMATIC, AUTOMATIC) CtrlPtr
)
{
    TcpIp_LocalAddrIdType id = TCPIP_NETCTRL_GET_LOCALADDR_ID(CtrlPtr);
    TcpIp_LocalAddrIdType limit = TCPIP_NETCTRL_GET_LOCALADDR_LIMIT(CtrlPtr);

    /*SWS_TCPIP_00076.b*/
    TCPIP_NETCTRL_SET_LINK_DOWN(CtrlPtr);
    /*SWS_TCPIP_00076.a*/
    for (; id < limit; id++)
    {
        /*SWS_TCPIP_00074*/
        if (TcpIp__CheckAssignedIpAddr(TCPIP_LOCALADDR_GET_CONTEXT(id)) == TCPIP_IPADDR_STATE_ASSIGNED)
        {
            TCPIP_LOCALADDR_NOTIFY_STATE(id, TCPIP_IPADDR_STATE_ONHOLD);
        }
    }

    /*SWS_TCPIP_00076.c*/
    TCPIP_NETCTRL_GOTO_ONHOLD(CtrlPtr);
    /*notify uplayer*/    /*PRQA S 3138 EOF*/
    TCPIP_NETCTRL_NOTIFY_STATE(CtrlPtr);

    return (uint8)TCPIP_COMSTATE_HANDLER_DONE;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: TcpIp__ComStateOnholdToOnline
*
* Description:   The handler that process onhold to online
*
* Inputs:        CtrlPtr    - the NetIfCtrl
*
* Outputs:       None
*
* Returns:       TCPIP_COMSTATE_HANDLER_DONE
*
* Limitations:   Only called by TcpIp_MainFunction.
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(uint8, TCPIP_CODE) TcpIp__ComStateOnholdToOnline
(
    P2VAR(TcpIp_NetIfCtrlType, AUTOMATIC, AUTOMATIC) CtrlPtr
)
{
    TcpIp_LocalAddrIdType id = TCPIP_NETCTRL_GET_LOCALADDR_ID(CtrlPtr);
    TcpIp_LocalAddrIdType limit = TCPIP_NETCTRL_GET_LOCALADDR_LIMIT(CtrlPtr);

    /*SWS_TCPIP_00086.a*/
    TCPIP_NETCTRL_SET_LINK_UP(CtrlPtr);
    /*SWS_TCPIP_00086.b*/
    for (; id < limit; id++)
    {
        if (TcpIp__CheckAssignedIpAddr(TCPIP_LOCALADDR_GET_CONTEXT(id)) == TCPIP_IPADDR_STATE_ASSIGNED)
        {
            TCPIP_LOCALADDR_NOTIFY_STATE(id, TCPIP_IPADDR_STATE_ASSIGNED);
        }
    }

    /*SWS_TCPIP_00086.c*/
    TCPIP_NETCTRL_GOTO_ONLINE(CtrlPtr);
    /*notify uplayer*/
    TCPIP_NETCTRL_NOTIFY_STATE(CtrlPtr);

    return (uint8)TCPIP_COMSTATE_HANDLER_DONE;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: TcpIp__ComStateStartupToOffline
*
* Description:   The handler that process startup to offline
*
* Inputs:        CtrlPtr    - the NetIfCtrl
*
* Outputs:       None
*
* Returns:       TCPIP_COMSTATE_HANDLER_DONE
*
* Limitations:   Only called by TcpIp_MainFunction.
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(uint8, TCPIP_CODE) TcpIp__ComStateStartupToOffline
(
    P2VAR(TcpIp_NetIfCtrlType, AUTOMATIC, AUTOMATIC) CtrlPtr
)
{
    TcpIp_LocalAddrIdType id = TCPIP_NETCTRL_GET_UNICASTADDR_ID(CtrlPtr);
    TcpIp_LocalAddrIdType limit = TCPIP_NETCTRL_GET_UNICASTADDR_LIMIT(CtrlPtr);

    /*SWS_TCPIP_00088.a*/
    for (; id < limit; id++)
    {
        TcpIp__ReleaseLocalAddrByPriority(id, (uint8)TCPIP_LOCALADDR_ASSIGNMENT_PRIORITY_1);
    }

#if (TCPIP_IGMP_ENABLED == STD_ON)
    id = TCPIP_NETCTRL_GET_MULTICASTADDR_ID(CtrlPtr);
    limit = TCPIP_NETCTRL_GET_LOCALADDR_LIMIT(CtrlPtr);
    for (; id < limit; id++)
    {
        TcpIp__ReleaseMulticastAddrAssignment(id);
    }
#endif

    /*SWS_TCPIP_00088.b*/
    TCPIP_NETCTRL_GOTO_OFFLINE(CtrlPtr);
    /*notify EthSM*/
    TCPIP_NETCTRL_NOTIFY_STATE(CtrlPtr);

    return (uint8)TCPIP_COMSTATE_HANDLER_DONE;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: TcpIp__ComStateStartupToOnline
*
* Description:   The handler that process online
*
* Inputs:        CtrlPtr    - the NetIfCtrl
*
* Outputs:       None
*
* Returns:       TCPIP_COMSTATE_HANDLER_DONE
*
* Limitations:   Only called by TcpIp_MainFunction.
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(uint8, TCPIP_CODE) TcpIp__ComStateStartupToOnline
(
    P2VAR(TcpIp_NetIfCtrlType, AUTOMATIC, AUTOMATIC) CtrlPtr
)
{
    P2VAR(TcpIp_LocalAddrType, AUTOMATIC, AUTOMATIC) localAddrCtx;
    TcpIp_LocalAddrIdType id = TCPIP_NETCTRL_GET_UNICASTADDR_ID(CtrlPtr);
    TcpIp_LocalAddrIdType limit = TCPIP_NETCTRL_GET_UNICASTADDR_LIMIT(CtrlPtr);
    uint8 ret = (uint8)TCPIP_COMSTATE_HANDLER_DONE;

    if (TcpIp__CheckAssignedUnicastAddr(CtrlPtr) == TCPIP_IPADDR_STATE_ASSIGNED)
    {
        /*SWS_TCPIP_00085*/
        TCPIP_NETCTRL_GOTO_ONLINE(CtrlPtr);
        /*notify EthSM*/
        TCPIP_NETCTRL_NOTIFY_STATE(CtrlPtr);

        /*try to start all higher priority assignments in ONLINE state.*/
        ret = (uint8)TCPIP_COMSTATE_HANDLER_AGAIN;
    }
    else
    {
        for (; id < limit; id++)
        {
            TcpIp__LocalAddrAssignmentHandler(TCPIP_LOCALADDR_GET_CONTEXT(id));
        }

#if (TCPIP_IGMP_ENABLED == STD_ON)
        id = TCPIP_NETCTRL_GET_MULTICASTADDR_ID(CtrlPtr);
        limit = TCPIP_NETCTRL_GET_LOCALADDR_LIMIT(CtrlPtr);
        for (; id < limit; id++)
        {
            localAddrCtx = TCPIP_LOCALADDR_GET_CONTEXT(id);
            if (TCPIP_LOCALADDR_GET_NEW_ASSIGNMENT_RELEASE(localAddrCtx) > 0)
            {
                /*SWS_TCPIP_00117*/
                TcpIp__ReleaseMulticastAddrAssignment(id);
            }

            if (TCPIP_LOCALADDR_GET_NEW_ASSIGNMENT_REQUEST(localAddrCtx) > 0)
            {
                /*SWS_TCPIP_00116*/
                TcpIp__AssignMulticastAddrByRequest(id);
            }
        }
#endif
    }

    return ret;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: TcpIp__ComStateShutdownToOffline
*
* Description:   The handler that process shutdown to offline
*
* Inputs:        CtrlPtr    - the NetIfCtrl
*
* Outputs:       None
*
* Returns:       TCPIP_COMSTATE_HANDLER_DONE
*
* Limitations:   Only called by TcpIp_MainFunction.
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(uint8, TCPIP_CODE) TcpIp__ComStateShutdownToOffline
(
    P2VAR(TcpIp_NetIfCtrlType, AUTOMATIC, AUTOMATIC) CtrlPtr
)
{
    TcpIp_LocalAddrIdType id = TCPIP_NETCTRL_GET_LOCALADDR_ID(CtrlPtr);
    TcpIp_LocalAddrIdType limit = TCPIP_NETCTRL_GET_LOCALADDR_LIMIT(CtrlPtr);
    TcpIp_IpAddrStateType assigned = TCPIP_IPADDR_STATE_UNASSIGNED;
    TcpIp_IpAddrStateType tmp;

    /*SWS_TCPIP_00087*/
    for (; id < limit; id++)
    {
        tmp = TcpIp__CheckAssignedIpAddr(TCPIP_LOCALADDR_GET_CONTEXT(id));
        if ((TCPIP_IPADDR_STATE_ASSIGNED == tmp) && (assigned != TCPIP_IPADDR_STATE_ASSIGNED))
        {
            assigned = TCPIP_IPADDR_STATE_ASSIGNED;
        }
    }

    if (TCPIP_IPADDR_STATE_UNASSIGNED == assigned)
    {
        /*SWS_TCPIP_00087*/
        TCPIP_NETCTRL_GOTO_OFFLINE(CtrlPtr);
        /*notify EthSM*/
        TCPIP_NETCTRL_NOTIFY_STATE(CtrlPtr);
    }

    return (uint8)TCPIP_COMSTATE_HANDLER_DONE;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: TcpIp__ComStateHandler
*
* Description:   The handler that process the state of NetIfCtrl.
*
* Inputs:        CtrlPtr    - the NetIfCtrl
*
* Outputs:       None
*
* Returns:       None
*
* Limitations:   Only called by TcpIp_MainFunction.
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, TCPIP_CODE) TcpIp__ComStateHandler
(
    P2VAR(TcpIp_NetIfCtrlType, AUTOMATIC, AUTOMATIC) CtrlPtr
)
{
    uint8 ret = (uint8)TCPIP_COMSTATE_HANDLER_DONE;
    TcpIp_StateType request;
    TcpIp_StateType current;

    do
    {
        request = CtrlPtr->RequestState;
        current = CtrlPtr->CurrentState;
        if ((current < TCPIP_STATE_VALID) && (request < TCPIP_STATE_VISIBLE))
        {
            ret = TcpIp_ComStateProcessors[current].Processor[request](CtrlPtr);
        }
        else
        {
            /*PRQA S 3138 EOF*/
            TCPIP_DET_REPORT_ERROR(TCPIP_API_MAINFUNCTION, TCPIP_E_INV_ARG);
        }
    } while (TCPIP_COMSTATE_HANDLER_AGAIN == ret);
}

#if (TCPIP_UDP_ENABLED == STD_ON)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: TcpIp__UdpReceiveHandler
*
* Description:   the Handler used to notify that a UDP datagram was received.
*
* Inputs:        Arg            - the UDP socket id
*                PcbPtr         - the socket PCB
*                DataPtr        - the datagram
*                RemoteAddrPtr  - the IP address of remote host
*                RemotePort     - the port of remote host
*
* Outputs:       None
*
* Returns:       None
*
* Limitations:   called by TcpIp core
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, TCPIP_CODE) TcpIp__UdpReceiveHandler
(
    P2VAR(void, AUTOMATIC, AUTOMATIC) Arg,
    P2VAR(struct udp_pcb, AUTOMATIC, AUTOMATIC) PcbPtr,
    P2VAR(struct pbuf, AUTOMATIC, AUTOMATIC) DataPtr,
    P2CONST(ip_addr_t, AUTOMATIC, AUTOMATIC) RemoteAddrPtr,
    uint16 RemotePort
)
{
    /*PRQA S 0306 EOF*/
    TcpIp_SocketIdType socketId = (TcpIp_SocketIdType)TCPIP_VOIDPTR_TO_UINT(Arg);
    /*PRQA S 3203,1065 EOF*/
    P2VAR(TcpIp_UdpSocketType, AUTOMATIC, AUTOMATIC) socket;
    P2VAR(struct pbuf, AUTOMATIC, AUTOMATIC) p = DataPtr;
    P2VAR(uint8, AUTOMATIC, AUTOMATIC) buffer = NULL_PTR;
    uint16 length = (uint16)0;
    TcpIp_SockAddrRealType remoteAddr;

    if ((socketId < (TcpIp_SocketIdType)TCPIP_UDP_SOCKET_MAX) && (TCPIP_SOCKET_GET_UDPCONTEXT(socketId)->PcbPtr == PcbPtr))
    {
        /*PRQA S 3199 EOF*/
        socket = TCPIP_SOCKET_GET_UDPCONTEXT(socketId);
#if (TCPIP_TCP_ENABLED == STD_ON)
        socketId += (TcpIp_SocketIdType)TCPIP_TCP_SOCKET_MAX;
#endif
        /*PRQA S 3198,3215,3892 EOF*/
        TCPIP_COPY_REMOTE_IPADDR_FROM_LWIP(&remoteAddr, RemoteAddrPtr, RemotePort);
#if (TCPIP_UDP_RX_DATAGRAM_LENGTH_MAX > 0)
        if (pbuf_clen(p) > 1)
        {
            if (p->tot_len <= TCPIP_UDP_RX_DATAGRAM_LENGTH_MAX)
            {
                /*PRQA S 3418 EOF*/
                for (length = 0, p = DataPtr; p != NULL_PTR; p = p->next)
                {
                    TCPIP_COPY_DATA(&TcpIp_UdpRxBuffer[length], p->payload, p->len);
                    length += p->len;
                }


                buffer = TcpIp_UdpRxBuffer;
            }
        }
        else
#endif
        if (pbuf_clen(p) == (uint16)1)
        {
            buffer = p->payload;
            length = p->len;
        }
        else
        {
            /*buffer is NULL_PTR*/
        }

        if (buffer != NULL_PTR)
        {
            TCPIP_UPLAYER_CALL_RXINDICATION(socket->UpLayer,
                                            socketId,
                                            (P2CONST(TcpIp_SockAddrType, AUTOMATIC, AUTOMATIC))&remoteAddr,
                                            buffer,
                                            length);
        }
    }
    /*PRQA S 3200 EOF*/
    pbuf_free(DataPtr);
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: TcpIp__GetUdpSocket
*
* Description:   allocates a UDP socket and Initializes it.
*
* Inputs:        Domain     - the IP address family
*                UpLayer    - the Upper layer index of TcpIp module
*                PcbPtr     - the socket PCB
*
* Outputs:       None
*
* Returns:       the allocated socket id or TCPIP_SOCKETID_INVALID.
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(TcpIp_SocketIdType, TCPIP_CODE) TcpIp__GetUdpSocket
(
    TcpIp_DomainType Domain,
    TcpIp_UpLayerIndexType UpLayer,
    P2VAR(struct udp_pcb, AUTOMATIC, AUTOMATIC) PcbPtr
)
{
    TcpIp_SocketIdType socketId = TCPIP_SOCKETID_INVALID;
    TcpIp_SocketIdType i;

    SchM_Enter_TcpIp_TCPIP_EXCLUSIVE_AREA_1();
    for (i = (uint8)0; i < (TcpIp_SocketIdType)TCPIP_UDP_SOCKET_MAX; i++)
    {
        if (NULL_PTR == TcpIp_UdpSockets[i].PcbPtr)
        {
            /*PRQA S 1334,0306 EOF*/
            TCPIP_SOCKET_SET_UDPRECV(PcbPtr, (uint32)i);
            TcpIp_UdpSockets[i].PcbPtr = PcbPtr;
            TcpIp_UdpSockets[i].UpLayer = UpLayer;
            TcpIp_UdpSockets[i].Domain = Domain;
            socketId = i;
            break;
        }
    }
    SchM_Exit_TcpIp_TCPIP_EXCLUSIVE_AREA_1();

    return socketId;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: TcpIp__UdpBind
*
* Description:   Binds a local IP address to a UDP socket
*
* Inputs:        SocketId       - the socket id
*                LocalAddrId    - the local address id
*                PortPtr        - the local port
*
* Outputs:       None
*
* Returns:       E_OK       - the local IP address was bound to the socket.
*                E_NOT_OK   - error
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(Std_ReturnType, TCPIP_CODE) TcpIp__UdpBind
(
    TcpIp_SocketIdType SocketId,
    TcpIp_LocalAddrIdType LocalAddrId,
    P2VAR(uint16, AUTOMATIC, AUTOMATIC) PortPtr
)
{
    P2VAR(TcpIp_LocalAddrType, AUTOMATIC, AUTOMATIC) localAddrCtx = NULL_PTR;
    P2VAR(TcpIp_UdpSocketType, AUTOMATIC, AUTOMATIC) socket;
    TcpIp_StaticIpAddrType localAddr;
    ip_addr_t tmpAddr;
    err_t err;
    Std_ReturnType ret = E_NOT_OK;

#if (TCPIP_TCP_ENABLED == STD_ON)
    SocketId -= (TcpIp_SocketIdType)TCPIP_TCP_SOCKET_MAX;
#endif
    socket = TCPIP_SOCKET_GET_UDPCONTEXT(SocketId);

    SchM_Enter_TcpIp_TCPIP_EXCLUSIVE_AREA_1();
    if ((socket->State != TCPIP_SOCKET_STATE_IDLE)
        || (NULL_PTR == socket->PcbPtr)
        /*SWS_TCPIP_00147*/
        || (TCPIP_LOCALADDRID_ANY == socket->LocalAddrId)
        || TCPIP_LOCALADDR_IS_VALID_ID(socket->LocalAddrId))
    {
        TCPIP_DET_REPORT_ERROR(TCPIP_API_BIND, TCPIP_E_ADDRNOTAVAIL);
    }
    else if (LocalAddrId != TCPIP_LOCALADDRID_ANY)
    {
        localAddrCtx = TCPIP_LOCALADDR_GET_CONTEXT(LocalAddrId);
        if (TCPIP_IS_SAME_DOMAIN(socket->Domain, localAddrCtx->ConfigPtr->Domain))
        {
            ret = TCPIP_LOCALADDR_GET_ASSIGNMENT_STATE(localAddrCtx, localAddrCtx->AssignedId, &localAddr);
        }
    }
    else
    {
        /*PRQA S 1290 ++*/
        TCPIP_SET_ANY_IPADDR(&(localAddr.IpAddr));
        ret = E_OK;
        /*PRQA S 1290 --*/
    }

    if (E_OK == ret)
    {
        /*PRQA S 3353,2144 EOF*//*Related to Lwip's cc.h and err.h*/
        TCPIP_LWIP_COPY_IPADDR(&tmpAddr, socket->Domain, &(localAddr.IpAddr));
        if(localAddrCtx != NULL_PTR)
        {
            socket->PcbPtr->netif_idx = localAddrCtx->CtrlId;
        }
        err = udp_bind(socket->PcbPtr, &tmpAddr, *PortPtr);
        if (ERR_OK == err)
        {
            socket->LocalAddrId = LocalAddrId;
            if (localAddrCtx != NULL_PTR)
            {
                socket->NetIfCtrlId = localAddrCtx->CtrlId;
            }

            if (*PortPtr == TCPIP_PORT_ANY)
            {
                *PortPtr = socket->PcbPtr->local_port;
            }
        }
        else
        {
            /*SWS_TCPIP_00146*/
            if (ERR_USE == err)
            {
                TCPIP_DET_REPORT_ERROR(TCPIP_API_BIND, TCPIP_E_ADDRINUSE);
            }
            ret = E_NOT_OK;
        }
    }
    SchM_Exit_TcpIp_TCPIP_EXCLUSIVE_AREA_1();

    return ret;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: TcpIp__UdpTransmit
*
* Description:   transmit a UDP datagram.
*
* Inputs:        SocketPtr      - the socket
*                RemoteAddrPtr  - the IP address of remote host
*                BufPtr         - the udp datagram
*
* Outputs:       None
*
* Returns:       E_OK       - the UDP datagram was sent by TcpIp module.
*                E_NOT_OK   - error.
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(Std_ReturnType, TCPIP_CODE) TcpIp__UdpTransmit
(
    P2VAR(TcpIp_UdpSocketType, AUTOMATIC, AUTOMATIC) SocketPtr,
    P2CONST(TcpIp_SockAddrRealType, AUTOMATIC, AUTOMATIC) RemoteAddrPtr,
    P2VAR(struct pbuf, AUTOMATIC, AUTOMATIC) BufPtr
)
{
    ip_addr_t tmpAddr;
    err_t err;
    uint16 port;
    Std_ReturnType ret = E_NOT_OK;

    SchM_Enter_TcpIp_TCPIP_EXCLUSIVE_AREA_1();
    if (SocketPtr->PcbPtr != NULL_PTR)
    {
       /*PRQA S 4423,4424 EOF*/
        err = ERR_OK;
        if ((TCPIP_LOCALADDRID_ANY != SocketPtr->LocalAddrId)
            && (!TCPIP_LOCALADDR_IS_VALID_ID(SocketPtr->LocalAddrId)))
        {
            /*bind a new address*//*SWS_TCPIP_00122*/
            err = udp_bind(SocketPtr->PcbPtr, TCPIP_LWIP_GET_ANY_IPADDR(SocketPtr->Domain), TCPIP_PORT_ANY);
            if (ERR_OK == err)
            {
                SocketPtr->LocalAddrId = TCPIP_LOCALADDRID_ANY;
            }
        }

        if (ERR_OK == err)
        {
            TCPIP_LWIP_COPY_IPADDR(&tmpAddr, SocketPtr->Domain, RemoteAddrPtr);
            port = TCPIP_IPADDR_GET_PORT(RemoteAddrPtr);
            /*SWS_TCPIP_00120*/
            err = udp_sendto(SocketPtr->PcbPtr, BufPtr, &tmpAddr, port);
            if (ERR_OK == err)
            {
                ret = E_OK;
            }
        }
    }
    SchM_Exit_TcpIp_TCPIP_EXCLUSIVE_AREA_1();

    return ret;
}
#endif

#if (TCPIP_TCP_ENABLED == STD_ON)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: TcpIp__TcpBind
*
* Description:   Binds a local IP address to a TCP socket
*
* Inputs:        SocketId       - the socket id
*                LocalAddrId    - the local address id
*                PortPtr        - the local port
*
* Outputs:       None
*
* Returns:       E_OK       - the local IP address was bound to the socket.
*                E_NOT_OK   - error
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(Std_ReturnType, TCPIP_CODE) TcpIp__TcpBind
(
    TcpIp_SocketIdType SocketId,
    TcpIp_LocalAddrIdType LocalAddrId,
    P2VAR(uint16, AUTOMATIC, AUTOMATIC) PortPtr
)
{
    P2VAR(TcpIp_LocalAddrType, AUTOMATIC, AUTOMATIC) localAddrCtx = NULL_PTR;
    P2VAR(TcpIp_TcpSocketType, AUTOMATIC, AUTOMATIC) socket;
    TcpIp_StaticIpAddrType localAddr;
    ip_addr_t tmpAddr;
    err_t err;
    Std_ReturnType ret = E_NOT_OK;

    socket = TCPIP_SOCKET_GET_TCPCONTEXT(SocketId);

    SchM_Enter_TcpIp_TCPIP_EXCLUSIVE_AREA_1();
    if ((socket->State != TCPIP_SOCKET_STATE_IDLE)
        || (NULL_PTR == socket->PcbPtr) /*no alloc?*/
        /*SWS_TCPIP_00147*/
        || (TCPIP_LOCALADDRID_ANY == socket->LocalAddrId)
        || TCPIP_LOCALADDR_IS_VALID_ID(socket->LocalAddrId)) /*bound?*/
    {
        TCPIP_DET_REPORT_ERROR(TCPIP_API_BIND, TCPIP_E_ADDRNOTAVAIL);
    }
    else if (LocalAddrId != TCPIP_LOCALADDRID_ANY)
    {
        localAddrCtx = TCPIP_LOCALADDR_GET_CONTEXT(LocalAddrId);
        if (TCPIP_IS_SAME_DOMAIN(socket->Domain, localAddrCtx->ConfigPtr->Domain)
            && TCPIP_LOCALADDR_IS_UNICAST_IPADDR(localAddrCtx->ConfigPtr))
        {
            ret = TCPIP_LOCALADDR_GET_ASSIGNMENT_STATE(localAddrCtx, localAddrCtx->AssignedId, &localAddr);
        }
    }
    else
    {
        /*PRQA S 1290 ++*/
        TCPIP_SET_ANY_IPADDR(&(localAddr.IpAddr));
        ret = E_OK;
        /*PRQA S 1290 --*/
    }

    if (E_OK == ret)
    {
        /*PRQA S 3353 EOF*/
        TCPIP_LWIP_COPY_IPADDR(&tmpAddr, socket->Domain, &(localAddr.IpAddr));
        err = tcp_bind(socket->PcbPtr, &tmpAddr, *PortPtr);
        if (ERR_OK == err)
        {
            socket->LocalAddrId = LocalAddrId;
            if (localAddrCtx != NULL_PTR)
            {
                socket->NetIfCtrlId = localAddrCtx->CtrlId;
            }

            if (*PortPtr == TCPIP_PORT_ANY)
            {
                *PortPtr = socket->PcbPtr->local_port;
            }
        }
        else
        {
            /*SWS_TCPIP_00146*/
            if (ERR_USE == err)
            {
                TCPIP_DET_REPORT_ERROR(TCPIP_API_BIND, TCPIP_E_ADDRINUSE);
            }
            ret = E_NOT_OK;
        }
    }
    SchM_Exit_TcpIp_TCPIP_EXCLUSIVE_AREA_1();

    return ret;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: TcpIp__TcpTransmit
*
* Description:   Get a TCP segment and sent it by EthIf module.
*
* Inputs:        TcpSocketId   - the socket id
*
* Outputs:       None
*
* Returns:       None
*
* Limitations:   only called by TcpIp_MainFunction
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, TCPIP_CODE) TcpIp__TcpTransmit
(
    TcpIp_SocketIdType TcpSocketId
)
{
    P2VAR(TcpIp_TcpSocketType, AUTOMATIC, AUTOMATIC) socket = TCPIP_SOCKET_GET_TCPCONTEXT(TcpSocketId);
    P2VAR(TcpIp_TcpTxBufferListType, AUTOMATIC, AUTOMATIC) list = &socket->TxBufferList;
    P2VAR(TcpIp_TcpTxBufferHeadType, AUTOMATIC, AUTOMATIC) head;
    P2VAR(uint8, AUTOMATIC, AUTOMATIC) data;
    uint16 length;
    uint8 transmitted = (uint8)0;
    err_t err;

    while (list->HeadPtr != NULL_PTR)
    {
        head = list->HeadPtr;
        /*PRQA S 0310,0488,0702,0751 EOF*/
        data = ((P2VAR(uint8, AUTOMATIC, AUTOMATIC))head) + TCPIP_TXBUFFER_HEAD_SIZE;
        length = head->Length;

        err = tcp_write(socket->PcbPtr, data, length, (u8_t)0);
        if (ERR_OK == err)
        {
            transmitted = (uint8)1;
            SchM_Enter_TcpIp_TCPIP_EXCLUSIVE_AREA_1();
            TcpIp__RemoveTcpTxBufferHead(list);
            TcpIp__InsertTcpTxBufferHead(&socket->WaitConfirmList, head);
            SchM_Exit_TcpIp_TCPIP_EXCLUSIVE_AREA_1();
        }
        else
        {
            break;
        }
    }

    if ((uint8)1 == transmitted)
    {
        (void)tcp_output(socket->PcbPtr);
    }
}
#endif

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: TcpIp__CopyUpLayerData
*
* Description:   Copy the data of Upper layer.
*
* Inputs:        SocketId       - the socket id
*                UpLayer        - the Upper layer of TcpIp module
*                DataPtr        - the data of Upper layer or NULL_PTR
*                TotalLength    - the length of data
*
* Outputs:       BufferPtr      - the buffer allocated by TcpIp module
*
* Returns:       E_OK       - The data were copied to buffer.
*                E_NOT_OK   - error.
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(Std_ReturnType, TCPIP_CODE) TcpIp__CopyUpLayerData
(
    TcpIp_SocketIdType SocketId,
    /*PRQA S 3206 EOF*/
    TcpIp_UpLayerIndexType UpLayer,
    P2CONST(uint8, AUTOMATIC, AUTOMATIC) DataPtr,
    uint32 TotalLength,
    P2VAR(uint8, AUTOMATIC, AUTOMATIC) BufferPtr
)
{
    Std_ReturnType ret = E_NOT_OK;
    BufReq_ReturnType result;

    if (DataPtr != NULL_PTR)
    {
        TcpIp__CopyData(BufferPtr, DataPtr, TotalLength);
        ret = E_OK;
    }
    else
    {
        /*PRQA S 1442 EOF*/
        result = TCPIP_UPLAYER_CALL_COPYTXDATA(UpLayer, SocketId, BufferPtr, (uint16)TotalLength);
        if (BUFREQ_OK == result)
        {
            ret = E_OK;
        }
    }

    return ret;
}

#if (TCPIP_IGMP_ENABLED == STD_ON)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: TcpIp__UpdateIgmpMacAddrHandler
*
* Description:   when a mulitcast address is added to a netif, this handler will
*                be called by LWIP.
*
* Inputs:        NetIfPtr   - the NetIf in NetIfCtrl
*                GroupPtr   - the mulitcast IP address
*                Action     - ADD or REMOVE group address
*
* Outputs:       None
*
* Returns:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(err_t, TCPIP_CODE) TcpIp__UpdateIgmpMacAddrHandler
(
    P2VAR(struct netif, AUTOMATIC, AUTOMATIC) NetIfPtr,
    P2CONST(ip4_addr_t, AUTOMATIC, AUTOMATIC) GroupPtr,
    enum netif_mac_filter_action Action
)
{
    uint8 mulitcastMac[TCPIP_HWADDR_LENGTH];
    TcpIp_CtrlIdType ctrlId = (TcpIp_CtrlIdType)TCPIP_VOIDPTR_TO_UINT(NetIfPtr->state);
    P2VAR(TcpIp_NetIfCtrlType, AUTOMATIC, AUTOMATIC) netCtrl = TCPIP_NETCTRL_GET_CONTEXT(ctrlId);
	
    /*PRQA S 0310,0311 EOF*/
    TCPIP_LWIP_SET_IPV4_MULTICAST_MAC(mulitcastMac, GroupPtr);
    if (NETIF_ADD_MAC_FILTER == Action)
    {
	    /*PRQA S 1441 EOF*/
        (void)EthIf_UpdatePhysAddrFilter(netCtrl->CtrlIdx, mulitcastMac, ETH_ADD_TO_FILTER);
    }
    else
    {
        (void)EthIf_UpdatePhysAddrFilter(netCtrl->CtrlIdx, mulitcastMac, ETH_REMOVE_FROM_FILTER);
    }

    return ERR_OK;
}
#endif

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: TcpIp__ReleaseBroadcastAddrAssignment
*
* Description:   Release the broadcast address of a NetIfCtrl when the unicast
*                address of it was release.
*
* Inputs:        NetCtrlPtr - the NetIfCtrl
*
* Outputs:       None
*
* Returns:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, TCPIP_CODE) TcpIp__ReleaseBroadcastAddrAssignment
(
    P2VAR(TcpIp_NetIfCtrlType, AUTOMATIC, AUTOMATIC) NetCtrlPtr
)
{
    TcpIp_LocalAddrIdType broadcastId = TCPIP_NETCTRL_GET_BROADCASTADDR_ID(NetCtrlPtr);
    TcpIp_LocalAddrIdType multicastId = TCPIP_NETCTRL_GET_MULTICASTADDR_ID(NetCtrlPtr);
    P2VAR(TcpIp_LocalAddrType, AUTOMATIC, AUTOMATIC) localAddr;

    if (broadcastId < multicastId)
    {
        /*this netctrl has a broadcast address*/
        localAddr = TCPIP_LOCALADDR_GET_CONTEXT(broadcastId);
        TCPIP_LOCALADDR_CLEAR_ASSIGNED_ID(localAddr);
        /*PRQA S 1290 ++*/
        TCPIP_CLEAR_STATICIPADDR(&localAddr->StaticIpAddr);
        /*PRQA S 1290 --*/
        TCPIP_LOCALADDR_NOTIFY_STATE(broadcastId, TCPIP_IPADDR_STATE_UNASSIGNED);
    }
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: TcpIp__AssignBroadcastAddrAssignment
*
* Description:   Assign the broadcast address of a NetIfCtrl when the unicast
*                address of it was assigned.
*
* Inputs:        NetCtrlPtr     - the NetIfCtrl
*                NewIpAddrPtr   - the new IP address
*
* Outputs:       None
*
* Returns:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, TCPIP_CODE) TcpIp__AssignBroadcastAddrAssignment
(
    P2VAR(TcpIp_NetIfCtrlType, AUTOMATIC, AUTOMATIC) NetCtrlPtr,
    P2VAR(TcpIp_StaticIpAddrType, AUTOMATIC, AUTOMATIC) NewIpAddrPtr
)
{
    TcpIp_LocalAddrIdType broadcastId = TCPIP_NETCTRL_GET_BROADCASTADDR_ID(NetCtrlPtr);
    TcpIp_LocalAddrIdType multicastId = TCPIP_NETCTRL_GET_MULTICASTADDR_ID(NetCtrlPtr);
    P2VAR(TcpIp_LocalAddrType, AUTOMATIC, AUTOMATIC) localAddr;

    if (broadcastId < multicastId)
    {
        /*this netctrl has a broadcast address*/
        localAddr = TCPIP_LOCALADDR_GET_CONTEXT(broadcastId);
        TCPIP_LOCALADDR_SET_ASSIGNED_ID(localAddr, TCPIP_LOCALADDR_ASSIGNMENT_PRIORITY_1);
        TCPIP_SET_BROADCAST_STATICIPADDR(&localAddr->StaticIpAddr, NewIpAddrPtr);
        TCPIP_LOCALADDR_NOTIFY_STATE(broadcastId, TCPIP_IPADDR_STATE_ASSIGNED);
    }
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: TcpIp__UnicastAddrAssignmentChangedHandler
*
* Description:   when a unicast address of netif was changed, this handler will
*                be called by LWIP.
*
* Inputs:        NetIfPtr   - the NetIf in NetIfCtrl
*
* Outputs:       None
*
* Returns:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, TCPIP_CODE) TcpIp__UnicastAddrAssignmentChangedHandler
(
    P2VAR(struct netif, AUTOMATIC, AUTOMATIC) NetIfPtr
)
{
    TcpIp_CtrlIdType ctrlId = (TcpIp_CtrlIdType)TCPIP_VOIDPTR_TO_UINT(NetIfPtr->state);
    P2VAR(TcpIp_NetIfCtrlType, AUTOMATIC, AUTOMATIC) netCtrl = TCPIP_NETCTRL_GET_CONTEXT(ctrlId);
    P2VAR(TcpIp_LocalAddrType, AUTOMATIC, AUTOMATIC) localAddr;
    TcpIp_LocalAddrAssignmentIdType assignedId;
    TcpIp_LocalAddrAssignmentIdType newId;
    TcpIp_LocalAddrIdType id;
    TcpIp_LocalAddrIdType limit = TCPIP_NETCTRL_GET_UNICASTADDR_LIMIT(netCtrl);
    TcpIp_LocalAddrIdType i = (TcpIp_LocalAddrIdType)0;
    P2CONST(ip_addr_t, AUTOMATIC, AUTOMATIC) ip;
    TcpIp_StaticIpAddrType staticIpAddr;
    /*PRQA S 3418 EOF*/
    for (id = TCPIP_NETCTRL_GET_UNICASTADDR_ID(netCtrl); id < limit; id++)
    {
        i++;
        localAddr = TCPIP_LOCALADDR_GET_CONTEXT(id);
        assignedId = localAddr->AssignedId;
        ip = TCPIP_LWIP_GET_IPADDR(NetIfPtr, i);
        if (ip_addr_isany_val(*ip))
        {
            if (TCPIP_LOCALADDR_IS_VALID_ASSIGNED_ID(assignedId))
            {
                TCPIP_LOCALADDR_CLEAR_ASSIGNED_ID(localAddr);
                TcpIp__ReleaseBroadcastAddrAssignment(netCtrl);
                TCPIP_LOCALADDR_NOTIFY_STATE(id, TCPIP_IPADDR_STATE_UNASSIGNED);
            }
            TcpIp__AssignLocalAddrByRequest(localAddr);
        }
        else
        {
            newId = TcpIp__GetNewAssignedLocalAddrId(localAddr, &staticIpAddr);
            if (TCPIP_LOCALADDR_IS_VALID_ASSIGNED_ID(newId))
            {
                TCPIP_LOCALADDR_SET_ASSIGNED_ID(localAddr, newId);
                /*SWS_TCPIP_00127*/
                TcpIp__ReleaseLocalAddrByPriority(id, newId + (TcpIp_LocalAddrAssignmentIdType)1);
                if (TCPIP_LOCALADDR_IS_VALID_ASSIGNED_ID(assignedId))
                {
                    TcpIp__ReleaseBroadcastAddrAssignment(netCtrl);
                    TCPIP_LOCALADDR_NOTIFY_STATE(id, TCPIP_IPADDR_STATE_UNASSIGNED);
                }
                TcpIp__AssignBroadcastAddrAssignment(netCtrl, &staticIpAddr);
                TCPIP_LOCALADDR_NOTIFY_STATE(id, TCPIP_IPADDR_STATE_ASSIGNED);
            }
        }
    }
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: TcpIp__LinkOutput
*
* Description:   transmit a ehternet frame by EthIf module.
*
* Inputs:        NetIfPtr   - the NetIf in NetIfCtrl
*                BufPtr     - the ethernet frame
*
* Outputs:       None
*
* Returns:       ERR_OK     - the ehternet frame was sent by EthIf module.
*                ERR_MEM    - need more memory.
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(err_t, TCPIP_CODE) TcpIp__LinkOutput
(
    P2VAR(struct netif, AUTOMATIC, AUTOMATIC) NetIfPtr,
    P2VAR(struct pbuf, AUTOMATIC, AUTOMATIC) BufPtr
)
{
    TcpIp_CtrlIdType ctrlId = (TcpIp_CtrlIdType)TCPIP_VOIDPTR_TO_UINT(NetIfPtr->state);
    P2VAR(TcpIp_NetIfCtrlType, AUTOMATIC, AUTOMATIC) netctrl;
    P2VAR(struct pbuf, AUTOMATIC, AUTOMATIC) q;
    P2VAR(uint8, AUTOMATIC, AUTOMATIC) buffer;
    uint16 i;
    uint16 len;
    uint16 maxlen;
    Eth_BufIdxType id;
    uint16 type;
    Std_ReturnType ret;
    err_t err = ERR_MEM;

    if (TCPIP_NETCTRL_IS_VALID_ID(ctrlId))
    {
        netctrl = TCPIP_NETCTRL_GET_CONTEXT(ctrlId);

        len = BufPtr->tot_len - (uint16)TCPIP_ETHERNET_FRAME_HEADER_LENGTH - (uint16)ETH_PAD_SIZE;
        maxlen = len;
     /*Related to Lwip*/ /*PRQA S 0894 EOF*/
#if ETH_PAD_SIZE
        (void)pbuf_header(BufPtr, -ETH_PAD_SIZE); /* drop the padding word */
#endif        
        type = lwip_ntohs(*((uint16 *)((uint8 *)BufPtr->payload + 12)));
        if (EthIf_ProvideTxBuffer(netctrl->CtrlIdx, type, TCPIP_NETCTRL_GET_CONFIG(ctrlId)->FramePrio, &id, &buffer, &maxlen) == BUFREQ_OK)
        {
            if(buffer != NULL_PTR)
            {
                i = BufPtr->len - (uint16)TCPIP_ETHERNET_FRAME_HEADER_LENGTH;
                /*PRQA S 0314 ++*/
                /* cast to a pointer to void */
                /*PRQA S 4471 ++*/
                /* Cast uint16 to uint32 */
                TCPIP_COPY_DATA(buffer, (const void *)((uint8 *)BufPtr->payload + TCPIP_ETHERNET_FRAME_HEADER_LENGTH), i);
                /*PRQA S 0314 --*/
                for(q = BufPtr->next; q != NULL; q = q->next)
                {
                    TCPIP_COPY_DATA(&buffer[i],q->payload, q->len);
                    i += q->len;
                }
                /*PRQA S 3305,0488,4423 EOF*/            
                ret = EthIf_Transmit(netctrl->CtrlIdx, id, type, FALSE, len, (uint8*)BufPtr->payload);
                if (ret == E_OK)
                {
                    err = ERR_OK;
                }
            }
        }
    }

    return err;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: TcpIp__MemCmp
*
* Description:   compares memory.
*
* Inputs:        Mem1Ptr    - the memory address one
*                Mem2Ptr    - the memory address two
*                Length     - the length of memory
*
* Outputs:       None
*
* Returns:       1  - NOT equal
*                0  - Equal
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(uint8, TCPIP_CODE) TcpIp__MemCmp
(
    P2CONST(uint8, AUTOMATIC, AUTOMATIC) Mem1Ptr,
    P2CONST(uint8, AUTOMATIC, AUTOMATIC) Mem2Ptr,
    uint16 Length
)
{
    uint16 i;
    uint8 ret = (uint8)0;

    for (i = (uint16)0; i < Length; i++)
    {
        if (Mem1Ptr[i] != Mem2Ptr[i])
        {
            ret = (uint8)1;
            break;
        }
    }

    return ret;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: TcpIp__InitNetIfHandler
*
* Description:   Initializes the NetIf in the NetIfCtrl.
*
* Inputs:        NetIfPtr  - the NetIf
*
* Outputs:       None
*
* Returns:       If NetIfCtrl id is valid return ERR_OK, otherwise return ERR_ARG. 
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(err_t, TCPIP_CODE) TcpIp__InitNetIfHandler
(
    P2VAR(struct netif, AUTOMATIC, AUTOMATIC) NetIfPtr
)
{
    uint8 hwAddr[ETH_HWADDR_LEN];
    /*PRQA S 2213,3604 ++*/
    /* Matching braces appear on the same line. */
    uint8 hwAddrZero[ETH_HWADDR_LEN] = {0};
    uint8 hwAddrAllOne[ETH_HWADDR_LEN] = {(uint8)0xff,(uint8)0xff,(uint8)0xff,(uint8)0xff,(uint8)0xff,(uint8)0xff};
    /*PRQA S 2213,3604 --*/
    err_t err = ERR_ARG;
    TcpIp_CtrlIdType ctrlId = (TcpIp_CtrlIdType)TCPIP_VOIDPTR_TO_UINT(NetIfPtr->state);
    P2VAR(TcpIp_NetIfCtrlType, AUTOMATIC, AUTOMATIC) netCtrl;
    P2CONST(TcpIp_NetIfCtrlConfigType, TCPIP_CONFIG_DATA, AUTOMATIC) ctrlConfig;
    P2CONST(TcpIp_IpV4CtrlConfigType, TCPIP_CONFIG_DATA, AUTOMATIC) ipv4Ctrl;

    if (TCPIP_NETCTRL_IS_VALID_ID(ctrlId))
    {
        netCtrl = TCPIP_NETCTRL_GET_CONTEXT(ctrlId);
        ctrlConfig = TCPIP_NETCTRL_GET_CONFIG(ctrlId);
        /*PRQA S 3123,3631 ++*/
        /* A character constant has been used. Cast to char */
        NetIfPtr->name[0] = 'e';
        NetIfPtr->name[1] = (char)('0' + netCtrl->CtrlIdx);
        /*PRQA S 3123,3613 --*/
        /* set MAC hardware address length */
        NetIfPtr->hwaddr_len = (u8_t)ETH_HWADDR_LEN;
        /* set MAC hardware address */
        EthIf_GetPhysAddr(netCtrl->CtrlIdx, hwAddr);
        /*PRQA S 3415 EOF*/
        /*PRQA S 2201 ++*/
        if ((TcpIp__MemCmp(hwAddr, hwAddrZero, (uint16)ETH_HWADDR_LEN) == (uint8)0)
	        || (TcpIp__MemCmp(hwAddr, hwAddrAllOne, (uint16)ETH_HWADDR_LEN) == (uint8)0))
        {
            NetIfPtr->hwaddr[0] = (u8_t)TCPIP_HARDWARE_MAC_0;
            NetIfPtr->hwaddr[1] = (u8_t)TCPIP_HARDWARE_MAC_1;
            NetIfPtr->hwaddr[2] = (u8_t)TCPIP_HARDWARE_MAC_2;
            NetIfPtr->hwaddr[3] = (u8_t)TCPIP_HARDWARE_MAC_3;
            NetIfPtr->hwaddr[4] = (u8_t)TCPIP_HARDWARE_MAC_4;
            NetIfPtr->hwaddr[5] = (u8_t)TCPIP_HARDWARE_MAC_5_BASE + netCtrl->CtrlIdx;
	        EthIf_SetPhysAddr(netCtrl->CtrlIdx, NetIfPtr->hwaddr);
            /*PRQA S 2201 --*/
        }
        else
        {
            NetIfPtr->hwaddr[0] = hwAddr[0];
            NetIfPtr->hwaddr[1] = hwAddr[1];
            NetIfPtr->hwaddr[2] = hwAddr[2];
            NetIfPtr->hwaddr[3] = hwAddr[3];
            NetIfPtr->hwaddr[4] = hwAddr[4];
            NetIfPtr->hwaddr[5] = hwAddr[5];
        }
        /* maximum transfer unit */
        NetIfPtr->mtu = (u16_t)1500;
        /* don't set NETIF_FLAG_ETHARP if this device is not an ethernet one */
        NetIfPtr->flags = NETIF_FLAG_BROADCAST | NETIF_FLAG_UP;
        /*PRQA S 0313 ++*/
        NetIfPtr->linkoutput = (netif_linkoutput_fn)&TcpIp__LinkOutput;
        /*PRQA S 0313 --*/
        /*Only used for checking the Local Address assignment*/    /*PRQA S 0435,557 EOF*/
        /*Because of Lwip*//*PRQA S 0428 EOF*/
        NetIfPtr->status_callback = &TcpIp__UnicastAddrAssignmentChangedHandler;

#if (TCPIP_IGMP_ENABLED == STD_ON)
        if (TCPIP_LOCALADDR_IS_VALID_ID(netCtrl->MulticastAddrId))
        {
            NetIfPtr->flags |= NETIF_FLAG_IGMP;
            NetIfPtr->igmp_mac_filter = &TcpIp__UpdateIgmpMacAddrHandler;
        }
#endif

#if (TCPIP_ARP_ENABLED == STD_ON)
        if (!TCPIP_NETCTRL_IPV4_CTRL_DISABLED(ctrlConfig))
        {
            ipv4Ctrl = TCPIP_IPV4_GET_CONFIG(ctrlConfig->IpV4CtrlId);
            if (!TCPIP_IPV4CTRL_ARP_DISABLED(ipv4Ctrl))
            {
                NetIfPtr->flags |= (u8_t)NETIF_FLAG_ETHARP;
                 /*PRQA S 0563 ++*/
                NetIfPtr->output = &etharp_output;
                 /*PRQA S 0313 --*/
            }
        }
#else
        TCPIP_UNUSED(ctrlConfig);
        TCPIP_UNUSED(ipv4Ctrl);
#endif

#if (TCPIP_DHCP_CLIENT_ENABLED == STD_ON)
        if (netCtrl->DHCPCtxPtr != NULL_PTR)
        {
            dhcp_set_struct(NetIfPtr, netCtrl->DHCPCtxPtr);
        }
#endif

#if (TCPIP_AUTOIP_ENABLED == STD_ON)
        if (netCtrl->AutoIpCtxPtr != NULL_PTR)
        {
            autoip_set_struct(NetIfPtr, netCtrl->AutoIpCtxPtr);
        }
#endif
        err = ERR_OK;
    }

    return err;
}

#if (TCPIP_TCP_ENABLED == STD_ON)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: TcpIp__TcpTxConfirmation
*
* Description:   Confirms the Tx data of TCP socket.
*
* Inputs:        SocketPtr  - the TCP socket
*                Length     - the length of data were sent do remote host
*
* Outputs:       None
*
* Returns:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(uint16, TCPIP_CODE) TcpIp__TcpTxConfirmation
(
    P2VAR(TcpIp_TcpSocketType, AUTOMATIC, AUTOMATIC) SocketPtr,
    uint16 Length
)
{
    P2VAR(TcpIp_TcpTxBufferHeadType, AUTOMATIC, AUTOMATIC) head;
    P2VAR(TcpIp_TcpTxBufferListType, AUTOMATIC, AUTOMATIC) wait = &SocketPtr->WaitConfirmList;
    uint16 confirmed = (uint16)0;

    while ((wait->HeadPtr != NULL_PTR) && (Length > (uint16)0))
    {
        if (wait->HeadPtr->Length <= Length)
        {
            confirmed += wait->HeadPtr->Length;
            Length -= wait->HeadPtr->Length;
            head = wait->HeadPtr;
            TcpIp__RemoveTcpTxBufferHead(wait);
            mem_free(head);
        }
        else
        {
            confirmed += Length;
            wait->HeadPtr->Length -= Length;
            Length = (uint16)0;
        }
    }

    return confirmed;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: TcpIp__TcpSentHandler
*
* Description:   The Handler used to notify that a TCP segment was sent to remote
*                host.
*
* Inputs:        Arg    - the TCP socket id
*                PcbPtr - the TCP socket PCB
*                Length - the length of data were sent do remote host
*
* Outputs:       None
*
* Returns:       None
*
* Limitations:   called by TcpIp core
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(err_t, TCPIP_CODE) TcpIp__TcpSentHandler
(
    P2VAR(void, AUTOMATIC, AUTOMATIC) Arg,
    P2VAR(struct tcp_pcb, AUTOMATIC, AUTOMATIC) PcbPtr,
    uint16 Length
)
{
    TcpIp_SocketIdType socketId = (TcpIp_SocketIdType)TCPIP_VOIDPTR_TO_UINT(Arg);
    P2VAR(TcpIp_TcpSocketType, AUTOMATIC, AUTOMATIC) socket;
    err_t err = ERR_MEM;

    if ((socketId < (TcpIp_SocketIdType)TCPIP_TCP_SOCKET_MAX) && (TCPIP_SOCKET_GET_TCPCONTEXT(socketId)->PcbPtr == PcbPtr))
    {
        socket = TCPIP_SOCKET_GET_TCPCONTEXT(socketId);
        Length = TcpIp__TcpTxConfirmation(socket, Length);
        if (Length > (uint16)0)
        {
            TCPIP_UPLAYER_CALL_TXCONFIRMATION(socket->UpLayer, socketId, Length);
            err = ERR_OK;
        }
    }

    return err;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: TcpIp__TcpErrorHandler
*
* Description:   the Handler used to notify that a TCP error was issued.
*
* Inputs:        Arg        - the TCP socket id
*                ErrCode    - the error code
*
* Outputs:       None
*
* Returns:       None
*
* Limitations:   called by TcpIp core
********************************************************************************
END_FUNCTION_HDR*/
 /*iit has been analyzed*//*PRQA S 2016,0570 EOF*/
STATIC FUNC(void, TCPIP_CODE) TcpIp__TcpErrorHandler
(
    P2VAR(void, AUTOMATIC, AUTOMATIC) Arg,
    err_t ErrCode
)
{
    TcpIp_SocketIdType socketId = (TcpIp_SocketIdType)TCPIP_VOIDPTR_TO_UINT(Arg);

    if (socketId < (TcpIp_SocketIdType)TCPIP_TCP_SOCKET_MAX)
    {
        switch (ErrCode)
        {
        case ERR_ABRT :
            TcpIp__TcpClosed(socketId, TCPIP_TCP_CLOSED);
            break;
        case ERR_RST :
            TcpIp__TcpClosed(socketId, TCPIP_TCP_RESET);
            break;
        case ERR_CLSD :
            TcpIp__TcpClosed(socketId, TCPIP_TCP_CLOSED);
            break;
        default :
            break;
        }
    }
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: TcpIp__GetTcpSocket
*
* Description:   allocates a TCP socket and Initializes it.
*
* Inputs:        Domain     - the IP address family
*                UpLayer    - the Upper layer index of TcpIp module
*                PcbPtr     - the socket PCB
*
* Outputs:       None
*
* Returns:       the allocated socket id or TCPIP_SOCKETID_INVALID.
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(TcpIp_SocketIdType, TCPIP_CODE) TcpIp__GetTcpSocket
(
    TcpIp_DomainType Domain,
    TcpIp_UpLayerIndexType UpLayer,
    P2VAR(struct tcp_pcb, AUTOMATIC, AUTOMATIC) PcbPtr
)
{
    TcpIp_SocketIdType socketId = TCPIP_SOCKETID_INVALID;
    TcpIp_SocketIdType i;

    SchM_Enter_TcpIp_TCPIP_EXCLUSIVE_AREA_1();
    for (i = (TcpIp_SocketIdType)0; i < (TcpIp_SocketIdType)TCPIP_TCP_SOCKET_MAX; i++)
    {
        if (NULL_PTR == TcpIp_TcpSockets[i].PcbPtr)
        {
            /*PRQA S 0306 EOF*/
            TCPIP_SOCKET_SET_TCPARG(PcbPtr, i);
            tcp_err(PcbPtr, &TcpIp__TcpErrorHandler);
            TcpIp_TcpSockets[i].PcbPtr = PcbPtr;
            TcpIp_TcpSockets[i].UpLayer = UpLayer;
            TcpIp_TcpSockets[i].Domain = Domain;
            socketId = i;
            break;
        }
    }
    SchM_Exit_TcpIp_TCPIP_EXCLUSIVE_AREA_1();

    return socketId;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: TcpIp__TcpReceiveHandler
*
* Description:   the Handler used to notify that a TCP segment was received.
*
* Inputs:        Arg        - the TCP socket id
*                PcbPtr     - the connected socket PCB
*                DataPtr    - the data or FIN (DataPtr == NULL_PTR)
*                ErrCode    - E_OK
*
* Outputs:       None
*
* Returns:       None
*
* Limitations:   called by TcpIp core
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(err_t, TCPIP_CODE) TcpIp__TcpReceiveHandler
(
    P2VAR(void, AUTOMATIC, AUTOMATIC) Arg,
    P2VAR(struct tcp_pcb, AUTOMATIC, AUTOMATIC) PcbPtr,
    P2VAR(struct pbuf, AUTOMATIC, AUTOMATIC) DataPtr,
    err_t ErrCode
)
{
    TcpIp_SocketIdType socketId = (TcpIp_SocketIdType)TCPIP_VOIDPTR_TO_UINT(Arg);
    P2VAR(TcpIp_TcpSocketType, AUTOMATIC, AUTOMATIC) socket;
    P2VAR(struct pbuf, AUTOMATIC, AUTOMATIC) p;
    TcpIp_SockAddrRealType remoteAddr;
    err_t err = ERR_MEM;

    TCPIP_UNUSED(ErrCode);

    if ((socketId < (TcpIp_SocketIdType)TCPIP_TCP_SOCKET_MAX) && (TCPIP_SOCKET_GET_TCPCONTEXT(socketId)->PcbPtr == PcbPtr))
    {
        socket = TCPIP_SOCKET_GET_TCPCONTEXT(socketId);
        if (DataPtr != NULL_PTR)
        {
            if (TCPIP_SOCKET_IS_CONNECTED(socket)
                /*we send a FIN frame but remote host do not close this connections.*/
                || TCPIP_SOCKET_IS_CLOSING(socket))
            {
                /*PRQA S 3198 EOF*/
                TCPIP_COPY_REMOTE_IPADDR_FROM_PCB(&remoteAddr, PcbPtr);
                for (p = DataPtr; p != NULL_PTR; p = p->next)
                {
                    TCPIP_UPLAYER_CALL_RXINDICATION(socket->UpLayer,
                                                    socketId,
                                                    (P2CONST(TcpIp_SockAddrType, AUTOMATIC, AUTOMATIC))&remoteAddr,
                                                    p->payload,
                                                    p->len);
                }
            }

            pbuf_free(DataPtr);
        }
        else
        {
            SchM_Enter_TcpIp_TCPIP_EXCLUSIVE_AREA_1();
            /*we receive a FIN frame. again?*/
            if (TCPIP_SOCKET_IS_CONNECTED(socket))
            {
                TCPIP_SOCKET_SET_WAITCLOSE(socket);
                SchM_Exit_TcpIp_TCPIP_EXCLUSIVE_AREA_1();

                TCPIP_UPLAYER_CALL_TCPIPEVENT(socket->UpLayer, socketId, TCPIP_TCP_FIN_RECEIVED);
                SchM_Enter_TcpIp_TCPIP_EXCLUSIVE_AREA_1();
            }
            else if (TCPIP_SOCKET_IS_CLOSE(socket))
            {
                /*The up layer has requested to close this socket?*/
                TCPIP_SOCKET_SET_CLOSED(socket);
            }
            else if (TCPIP_SOCKET_IS_CLOSING(socket))
            {
                SchM_Exit_TcpIp_TCPIP_EXCLUSIVE_AREA_1();
                TcpIp__TcpClosed(socketId, TCPIP_TCP_CLOSED);
                SchM_Enter_TcpIp_TCPIP_EXCLUSIVE_AREA_1();
            }
            else
            {
                /*do nothing*/
            }
            SchM_Exit_TcpIp_TCPIP_EXCLUSIVE_AREA_1();
        }

        err = ERR_OK;
    }

    return err;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: TcpIp__TcpConnectedHandler
*
* Description:   the Handler used to notify that a socket is connected.
*
* Inputs:        Arg        - the TCP socket id
*                PcbPtr     - the connected socket PCB
*                ErrCode    - E_OK
*
* Outputs:       None
*
* Returns:       None
*
* Limitations:   called by TcpIp core
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(err_t, TCPIP_CODE) TcpIp__TcpConnectedHandler
(
    P2VAR(void, AUTOMATIC, AUTOMATIC) Arg,
    P2VAR(struct tcp_pcb, AUTOMATIC, AUTOMATIC) PcbPtr,
    err_t ErrCode
)
{
    TcpIp_SocketIdType socketId = (TcpIp_SocketIdType)TCPIP_VOIDPTR_TO_UINT(Arg);
    P2VAR(TcpIp_TcpSocketType, AUTOMATIC, AUTOMATIC) socket;
    err_t err = ERR_MEM;

    TCPIP_UNUSED(ErrCode);

    if ((socketId < (TcpIp_SocketIdType)TCPIP_TCP_SOCKET_MAX) && (TCPIP_SOCKET_GET_TCPCONTEXT(socketId)->PcbPtr == PcbPtr))
    {
        socket = TCPIP_SOCKET_GET_TCPCONTEXT(socketId);

        tcp_recv(PcbPtr, &TcpIp__TcpReceiveHandler);
        tcp_sent(PcbPtr, &TcpIp__TcpSentHandler);
        tcp_nagle_disable(PcbPtr);

        SchM_Enter_TcpIp_TCPIP_EXCLUSIVE_AREA_1();
        TCPIP_SOCKET_SET_CONNECTED(socket);
        SchM_Exit_TcpIp_TCPIP_EXCLUSIVE_AREA_1();
        TCPIP_UPLAYER_CALL_TCPCONNECTED(socket->UpLayer, socketId);

        err = ERR_OK;
    }

    return err;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: TcpIp__TcpAcceptHandler
*
* Description:   the Handler used to accept a new socket.
*
* Inputs:        Arg        - the TCP socket id
*                NewPcbPtr  - the new socket PCB
*                ErrCode    - E_OK
*
* Outputs:       None
*
* Returns:       None
*
* Limitations:   called by TcpIp core
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(err_t, TCPIP_CODE) TcpIp__TcpAcceptHandler
(
    P2VAR(void, AUTOMATIC, AUTOMATIC) Arg,
    P2VAR(struct tcp_pcb, AUTOMATIC, AUTOMATIC) NewPcbPtr,
    err_t ErrCode
)
{
    TcpIp_SocketIdType socketId = (TcpIp_SocketIdType)TCPIP_VOIDPTR_TO_UINT(Arg);
    TcpIp_SocketIdType newSocketId;
    P2VAR(TcpIp_TcpSocketType, AUTOMATIC, AUTOMATIC) socket;
    P2VAR(TcpIp_TcpSocketType, AUTOMATIC, AUTOMATIC) newSocket;
    err_t err = ERR_MEM;
    TcpIp_SockAddrRealType remoteAddr;
    Std_ReturnType ret;

    TCPIP_UNUSED(ErrCode);

    if ((socketId < (TcpIp_SocketIdType)TCPIP_TCP_SOCKET_MAX) && (NewPcbPtr != NULL_PTR))
    {
        socket = TCPIP_SOCKET_GET_TCPCONTEXT(socketId);
        newSocketId = TcpIp__GetTcpSocket(socket->Domain, socket->UpLayer, NewPcbPtr);
        if (newSocketId != TCPIP_SOCKETID_INVALID)
        {
            tcp_recv(NewPcbPtr, &TcpIp__TcpReceiveHandler);
            tcp_sent(NewPcbPtr, &TcpIp__TcpSentHandler);
            tcp_nagle_disable(NewPcbPtr);

            newSocket = TCPIP_SOCKET_GET_TCPCONTEXT(newSocketId);
            newSocket->LocalAddrId = socket->LocalAddrId;
            newSocket->NetIfCtrlId = socket->NetIfCtrlId;
            TCPIP_SOCKET_SET_CONNECTED(newSocket);
            /*PRQA S 3198 EOF*/
            TCPIP_COPY_REMOTE_IPADDR_FROM_PCB(&remoteAddr, NewPcbPtr);
            /*PRQA S 3757 EOF*/
            ret = TCPIP_UPLAYER_CALL_TCPACCEPTED(socket->UpLayer,
                                                    socketId,
                                                    newSocketId,
                                                    (P2CONST(TcpIp_SockAddrType, AUTOMATIC, AUTOMATIC))&remoteAddr);
            if (E_OK == ret)
            {
                err = ERR_OK;
            }
            else
            {
                /*avoid notifying the up layer. LWIP will abort this socket.*/
                TCPIP_SOCKET_SET_TCPARG(NewPcbPtr, TCPIP_SOCKETID_INVALID);
                TcpIp__ReleaseTcpSocket(newSocket);
            }
        }
    }

    return err;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: TcpIp__TcpSocketStateHandler
*
* Description:   Process the TCP socket's state.
*
* Inputs:        SocketId   - the TCP socket id.
*
* Outputs:       None
*
* Returns:       None
*
* Limitations:   Only called by TcpIp_MainFunction
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, TCPIP_CODE) TcpIp__TcpSocketStateHandler
(
    TcpIp_SocketIdType SocketId
)
{
    P2VAR(TcpIp_TcpSocketType, AUTOMATIC, AUTOMATIC) socket = TCPIP_SOCKET_GET_TCPCONTEXT(SocketId);
    P2VAR(struct tcp_pcb, AUTOMATIC, AUTOMATIC) pcb;
    ip_addr_t addr;
    err_t err;
    uint16 rxLen;

    switch (socket->State)
    {
    case TCPIP_SOCKET_STATE_CONNECT :
        SchM_Enter_TcpIp_TCPIP_EXCLUSIVE_AREA_1();
        TCPIP_SOCKET_SET_CONNECTING(socket);
        SchM_Exit_TcpIp_TCPIP_EXCLUSIVE_AREA_1();
        TCPIP_LWIP_COPY_IPADDR((ip4_addr_t*)&addr, socket->Domain, &socket->RemoteAddr);
        err = tcp_connect(socket->PcbPtr, &addr, socket->RemoteAddr.Port, &TcpIp__TcpConnectedHandler);
        if (err != ERR_OK)
        {
            tcp_abort(socket->PcbPtr);
        }
        break;
    case TCPIP_SOCKET_STATE_CONNECTED :
        if (socket->ReceivedDataSize > (uint16)0)
        {
            SchM_Enter_TcpIp_TCPIP_EXCLUSIVE_AREA_1();
            rxLen = socket->ReceivedDataSize;
            socket->ReceivedDataSize = (uint16)0;
            SchM_Exit_TcpIp_TCPIP_EXCLUSIVE_AREA_1();
            /*SWS_TCPIP_00115*/
            tcp_recved(socket->PcbPtr, rxLen);
        }
        break;
    case TCPIP_SOCKET_STATE_LISTEN :
        /*PRQA S 3746,4461 EOF*/
        pcb = tcp_listen_with_backlog(socket->PcbPtr, socket->MaxChannels);
        SchM_Enter_TcpIp_TCPIP_EXCLUSIVE_AREA_1();
        if (pcb != NULL_PTR)
        {
            tcp_accept(pcb, &TcpIp__TcpAcceptHandler);
            socket->PcbPtr = pcb;
            socket->MaxChannels = (uint16)0;
            TCPIP_SOCKET_SET_LISTENING(socket);
        }
        SchM_Exit_TcpIp_TCPIP_EXCLUSIVE_AREA_1();
        break;
    case TCPIP_SOCKET_STATE_CLOSE :
        /*active close*//*SWS_TCPIP_00109*/
        if (socket->Abort == FALSE)
        {
            err = tcp_close(socket->PcbPtr);
            if (err != ERR_OK)
            {
                tcp_abort(socket->PcbPtr);
                /*Notify up layer by LWIP callback, so we don't notify it again.*/
            }
            else
            {
                /*wait for FIN.*/
                TCPIP_SOCKET_SET_CLOSING(socket);
            }
        }
        else
        {
            tcp_abort(socket->PcbPtr);
        }
        break;
    case TCPIP_SOCKET_STATE_CLOSE_LISTEN :
        (void)tcp_close(socket->PcbPtr);
        TcpIp__TcpClosed(SocketId, TCPIP_TCP_CLOSED);
        break;
    case TCPIP_SOCKET_STATE_CLOSED :
        /*passtive close*/
        if (socket->Abort == FALSE)
        {
            err = tcp_close(socket->PcbPtr);
            if (err != ERR_OK)
            {
                tcp_abort(socket->PcbPtr);
                /*Notify up layer by LWIP, so we don't notify it again.*/
            }
        }
        else
        {
            tcp_abort(socket->PcbPtr);
        }
        TcpIp__TcpClosed(SocketId, TCPIP_TCP_CLOSED);
        break;
    default :
        break;
    }
}
#endif

#if (TCPIP_UDP_ENABLED == STD_ON)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: TcpIp__UdpSocketStateHandler
*
* Description:   Process the UDP socket's state.
*
* Inputs:        SocketId   - the UDP socket id.
*
* Outputs:       None
*
* Returns:       None
*
* Limitations:   Only called by TcpIp_MainFunction
********************************************************************************
END_FUNCTION_HDR*/
 /*PRQA S 3352 EOF*//*} displays an error in QAC*/
STATIC FUNC(void, TCPIP_CODE) TcpIp__UdpSocketStateHandler
(
    TcpIp_SocketIdType SocketId
)
{
    P2VAR(TcpIp_UdpSocketType, AUTOMATIC, AUTOMATIC) socket = TCPIP_SOCKET_GET_UDPCONTEXT(SocketId);

    switch (socket->State)
    {
    case TCPIP_SOCKET_STATE_CLOSE :
        TcpIp__CloseUdpSocket(SocketId);
        break;
    default :
        break;
    }
}
#endif

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: TcpIp__RxIndication
*
* Description:   Process the ethernet frame by TcpIp module.
*
* Inputs:        RxBufferPtr    - The Rx Buffer allocated by TcpIp_RxIndication.
*
* Outputs:       None
*
* Returns:       None
*
* Limitations:   Only called by TcpIp_MainFunction
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, TCPIP_CODE) TcpIp__RxIndication
(
    P2VAR(struct pbuf, AUTOMATIC, AUTOMATIC) RxBufferPtr
)
{
    uint8 ctrlId;
    P2VAR(TcpIp_NetIfCtrlType, AUTOMATIC, AUTOMATIC) ctrlCtx;
    Std_ReturnType ret = E_NOT_OK;

    /*Get ctrlId and restore the type of buffer to PBUF_POOL.*/
    ctrlId = RxBufferPtr->type_internal;
    /*PRQA S 2900 EOF*/
    RxBufferPtr->type_internal = PBUF_POOL;
    /*PRQA S 3344, 3491, 4559, 4115 EOF*/
    if (TCPIP_NETCTRL_IS_VALID_ID(ctrlId)
        && TCPIP_NETCTRL_IS_LINK_UP(TCPIP_NETCTRL_GET_CONTEXT(ctrlId)))
    {
        ctrlCtx = TCPIP_NETCTRL_GET_CONTEXT(ctrlId);
        /*PRQA S 0432 ++*/
        if (TCPIP_NETCTRL_RX_HANDLER(ctrlCtx, RxBufferPtr) == ERR_OK)
        {
            ret = E_OK;
        }
    }

    if (ret != E_OK)
    {
        pbuf_free(RxBufferPtr);
    }
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: TcpIp__FindNetCtrlByEthIfCtrlIdx
*
* Description:   Finds the NetIfCtrl Id by EthIf controller index.
*
* Inputs:        EthIfCtrlIdx   - the EthIf controller index 
*
* Outputs:       None
*
* Returns:       NetIfCtrl's Id or TCPIP_NETIF_CTRL_MAX.
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(TcpIp_CtrlIdType, TCPIP_CODE) TcpIp__FindNetCtrlByEthIfCtrlIdx
(
    uint8 EthIfCtrlIdx
)
{
    TcpIp_CtrlIdType i;
    TcpIp_CtrlIdType ret = (uint8)TCPIP_NETIF_CTRL_MAX;

    for (i = (uint8)0; TCPIP_NETCTRL_IS_VALID_ID(i); i++)
    {
        if (TCPIP_NETCTRL_GET_ETHIFCTRL(i) == EthIfCtrlIdx)
        {
            ret = i;
            break;
        }
    }

    return ret;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: TcpIp__GetRxData
*
* Description:   Get the RX data's pointer allocated by TcpIp_RxIndication From
*                the RxFIFO.
*
* Inputs:        Length     - the length of data pointer 
*
* Outputs:       BufferPtr  - the pointer of rx data pointer
*
* Returns:       If the FIFO is empty returns E_NOT_OK, otherwise return E_OK.
*
* Limitations:   Only called by TcpIp_MainFunction
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(Std_ReturnType, TCPIP_CODE) TcpIp__GetRxData
(
    P2VAR(void, AUTOMATIC, AUTOMATIC) BufferPtr,
    uint16 Length
)
{
    Std_ReturnType ret = E_NOT_OK;
    volatile uint16 size;
    uint16 usedLen;
    uint16 offset;

    usedLen = TcpIp_RxFifo.In - TcpIp_RxFifo.Out;
    /*PRQA S 3396, 3442,3441 EOF*/
    size = TCPIP_MIN(Length, usedLen);
    if(size == Length)
    {
        /*
         * The TCPIP_RX_FIFO_SIZE must be divisible by the length of data,
         * so we only copy the data once.
         */
        offset = TcpIp_RxFifo.Out & (uint16)(TCPIP_RX_FIFO_SIZE - 1);
        TCPIP_COPY_DATA((uint8*)BufferPtr, &TcpIp_RxFifo.Fifo[offset], size);
        /**/
        TcpIp_RxFifo.Out += size;
        ret = E_OK;
    }

    return ret;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: TcpIp__PutRxData
*
* Description:   Puts the RX data's pointer allocated by TcpIp_RxIndication into
*                the RxFIFO.
*
* Inputs:        BufferPtr  - the pointer of rx data pointer
*                Length     - the length of data pointer 
*
* Outputs:       None
*
* Returns:       If the FIFO is full returns E_NOT_OK, otherwise return E_OK.
*
* Limitations:   Only called by TcpIp_RxIndication
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(Std_ReturnType, TCPIP_CODE) TcpIp__PutRxData
(
    P2VAR(void, AUTOMATIC, AUTOMATIC) BufferPtr,
    uint16 Length
)
{
    Std_ReturnType ret = E_NOT_OK;
    volatile uint16 size;
    uint16 offset;
    uint16 emptyLen;

    emptyLen = ((uint16)TCPIP_RX_FIFO_SIZE - TcpIp_RxFifo.In) + TcpIp_RxFifo.Out;
    /*PRQA S 3396 EOF*/
    size = TCPIP_MIN(Length, emptyLen);
    if (size == Length)
    {
        /*
         * The TCPIP_RX_FIFO_SIZE must be divisible by the length of data,
         * so we only copy the data once.
         */
        offset = TcpIp_RxFifo.In & (uint16)(TCPIP_RX_FIFO_SIZE - 1);
        TCPIP_COPY_DATA(&TcpIp_RxFifo.Fifo[offset], (uint8*)BufferPtr, size);
        /**/
        TcpIp_RxFifo.In += size;
        ret = E_OK;
    }

    return ret;
}


/******************************************************************************
*   Global Function Define
******************************************************************************/
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: TcpIp_Init
*
* Description:   Initializes the TcpIp module.
*
* Inputs:        CfgPtr - the configuration data of the TcpIp module.
*
* Outputs:       None
*
* Returns:       None
*
* Limitations:   The call of this service is mandatory before using the TcpIp
*                module for further processing.
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, TCPIP_CODE) TcpIp_Init
(
    P2CONST(TcpIp_ConfigType, AUTOMATIC, AUTOMATIC) CfgPtr
)
{
    P2VAR(TcpIp_NetIfCtrlType, AUTOMATIC, AUTOMATIC) netctrl;
    P2CONST(TcpIp_NetIfCtrlConfigType, TCPIP_CONFIG_DATA, AUTOMATIC) ctrlConfig;
    P2CONST(TcpIp_IpV4CtrlConfigType, TCPIP_CONFIG_DATA, AUTOMATIC) ipv4Ctrl;
    P2VAR(TcpIp_LocalAddrType, AUTOMATIC, AUTOMATIC) localAddrCtx;
    P2CONST(TcpIp_LocalAddrConfigType, AUTOMATIC, AUTOMATIC) localAddrConfig;
    TcpIp_LocalAddrAssignmentIdType assignmentId;
    TcpIp_LocalAddrIdType localAddrId;
    TcpIp_CtrlIdType ctrlId;
    TcpIp_SocketIdType socketId;
    uint8 dhcpIdx = (uint8)0;
    uint8 autoipIdx = (uint8)0;
	
    /*PRQA S 3112 EOF*/
    TCPIP_IF_CONFIG_PTR(CfgPtr)
    {
        /*init LWIP module*/
        lwip_init();
        /*init netif*/  
        for (ctrlId = (uint8)0; TCPIP_NETCTRL_IS_VALID_ID(ctrlId); ctrlId++)
        {
            netctrl = TCPIP_NETCTRL_GET_CONTEXT(ctrlId);
            ctrlConfig = TCPIP_NETCTRL_GET_CONFIG(ctrlId);

            netctrl->CtrlIdx = ctrlConfig->CtrlIdx;
            netctrl->UnicastAddrId = ctrlConfig->UnicastAddrId;
            netctrl->UnicastAddrLimit = ctrlConfig->UnicastAddrLimit;
            netctrl->MulticastAddrId = ctrlConfig->MulticastAddrId;
            netctrl->LocalAddrLimit = ctrlConfig->LocalAddrLimit;
            netctrl->CurrentState = TCPIP_STATE_OFFLINE;
            netctrl->RequestState = TCPIP_STATE_OFFLINE;

#if (TCPIP_DHCP_CLIENT_ENABLED == STD_ON)
            if (!TCPIP_NETCTRL_IPV4_CTRL_DISABLED(ctrlConfig))
            {
                ipv4Ctrl = TCPIP_IPV4_GET_CONFIG(ctrlConfig->IpV4CtrlId);
                if(!TCPIP_IPV4CTRL_DHCP_DISABLED(ipv4Ctrl))
                {
                    netctrl->DHCPCtxPtr = &TcpIp_DHCPContexts[dhcpIdx];
                    dhcpIdx++;
                    if(dhcpIdx > TCPIP_DHCP_CLIENT_MAX)
                    {
                        TCPIP_DET_REPORT_ERROR(TCPIP_API_INIT, TCPIP_E_INV_CONFIG);
                    } 
                }
            }
#else
            TCPIP_UNUSED(dhcpIdx);
             /*PRQA S 3324,1853,3109 EOF*/
            if (!TCPIP_NETCTRL_IPV4_CTRL_DISABLED(ctrlConfig))
            {
                ipv4Ctrl = TCPIP_IPV4_GET_CONFIG(ctrlConfig->IpV4CtrlId);
                if(!TCPIP_IPV4CTRL_DHCP_DISABLED(ipv4Ctrl))
                {
                    TCPIP_DET_REPORT_ERROR(TCPIP_API_INIT, TCPIP_E_INV_CONFIG);
                }
            }
#endif

#if (TCPIP_AUTOIP_ENABLED == STD_ON)
            if (!TCPIP_NETCTRL_IPV4_CTRL_DISABLED(ctrlConfig))
            {
                ipv4Ctrl = TCPIP_IPV4_GET_CONFIG(ctrlConfig->IpV4CtrlId);
                if(!TCPIP_IPV4CTRL_AUTOIP_DISABLED(ipv4Ctrl))
                {
                    netctrl->AutoIpTimeout = TCPIP_MAKE_TIMEOUT(ipv4Ctrl->AutoIpInitTimeout);
                    netctrl->AutoIpCtxPtr = &TcpIp_AutoIpContexts[autoipIdx];
                    autoipIdx++;
                    if(autoipIdx > TCPIP_AUTOIP_CLIENT_MAX)
                    {
                        TCPIP_DET_REPORT_ERROR(TCPIP_API_INIT, TCPIP_E_INV_CONFIG);
                    }
                }
            }
#else
            TCPIP_UNUSED(autoipIdx);
            if (!TCPIP_NETCTRL_IPV4_CTRL_DISABLED(ctrlConfig))
            {
                ipv4Ctrl = TCPIP_IPV4_GET_CONFIG(ctrlConfig->IpV4CtrlId);
                if(!TCPIP_IPV4CTRL_AUTOIP_DISABLED(ipv4Ctrl))
                {
                    TCPIP_DET_REPORT_ERROR(TCPIP_API_INIT, TCPIP_E_INV_CONFIG);
                }
            }
#endif
            /*PRQA S 0306 EOF*/
            if (TCPIP_NETCTRL_ADD_NETIF(netctrl, ctrlId) == NULL_PTR)
            {
                TCPIP_DET_REPORT_ERROR(TCPIP_API_INIT, TCPIP_E_INV_CONFIG);
            }

            if (netctrl->CtrlIdx == (uint8)0)
            {
                TCPIP_NETCTRL_SET_DEFAULT_NETIF(netctrl);
            }
        }

        if (TCPIP_NETCTRL_GET_DEFAULT_NETIF() == NULL_PTR)
        {
            TCPIP_NETCTRL_SET_DEFAULT_NETIF(TCPIP_NETCTRL_GET_CONTEXT(0));
        }

        /*init local addr table*/
        for (localAddrId = (uint8)0; TCPIP_LOCALADDR_IS_VALID_ID(localAddrId); localAddrId++)
        {
            localAddrCtx = TCPIP_LOCALADDR_GET_CONTEXT(localAddrId);
            localAddrConfig = TCPIP_LOCALADDR_GET_CONFIG(localAddrId);

            localAddrCtx->CtrlId = localAddrConfig->CtrlId;
            localAddrCtx->AssignedId = (uint8)TCPIP_LOCALADDR_ASSIGNMENT_PRIORITY_MAX;
            localAddrCtx->StartedAddr = (uint8)0;
            localAddrCtx->RequestAddr = (uint8)0;

#if (TCPIP_STATIC_IPADDR_MAX > 0)
            if (TCPIP_LOCALADDR_HAS_STATIC_IPADDR(localAddrConfig))
            {
                TCPIP_COPY_STATICIPADDR(&localAddrCtx->StaticIpAddr, TCPIP_STATICIP_GET_CONFIG(localAddrConfig->StaticAddrId));
            }
#endif

            for (assignmentId = (uint8)0; assignmentId < (uint8)TCPIP_LOCALADDR_ASSIGNMENT_PRIORITY_MAX; assignmentId++)
            {
                if (TCPIP_LOCALADDR_IS_VALID_ASSIGNMENT(localAddrConfig, assignmentId)
                    && TCPIP_LOCALADDR_IS_AUTOMATIC_ASSIGNMENT(localAddrConfig, assignmentId))
                {
                    /*SWS_TCPIP_00197*/
                    TCPIP_LOCALADDR_SET_ASSIGNMENT_REQUEST(localAddrCtx, assignmentId);
                }
            }
            localAddrCtx->ConfigPtr = localAddrConfig;
        }

        /*init all socket*/
#if (TCPIP_TCP_ENABLED == STD_ON)
        for (socketId = (uint8)0; socketId < (TcpIp_SocketIdType)TCPIP_TCP_SOCKET_MAX; socketId++)
        {
            TcpIp__ReleaseTcpSocket(TCPIP_SOCKET_GET_TCPCONTEXT(socketId));
        }
#endif

#if (TCPIP_UDP_ENABLED == STD_ON)
        for (socketId = (uint8)0; socketId < (TcpIp_SocketIdType)TCPIP_UDP_SOCKET_MAX; socketId++)
        {
            TcpIp__ReleaseUdpSocket(TCPIP_SOCKET_GET_UDPCONTEXT(socketId));
        }
#endif

        TCPIP_RESET_SYSTEM_TIME();
        TcpIp_Initialized = STD_INITIALIZED;
    }
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: TcpIp_MainFunction
*
* Description:   Schedules the TcpIp module.
*
* Inputs:        None
*
* Outputs:       None
*
* Returns:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, TCPIP_CODE) TcpIp_MainFunction
(
    void
)
{
    uint16 rxMax = (uint16)TCPIP_RXINDICATION_MAX;
    TcpIp_SocketIdType socketId;
    TcpIp_CtrlIdType ctrlId;
    P2VAR(struct pbuf, AUTOMATIC, AUTOMATIC) rxBuffer;
    P2VAR(TcpIp_NetIfCtrlType, AUTOMATIC, AUTOMATIC) ctrl;
    P2VAR(TcpIp_TcpSocketType, AUTOMATIC, AUTOMATIC) socket;

    for (ctrlId = (uint8)0; ctrlId < (uint8)TCPIP_NETIF_CTRL_MAX; ctrlId++)
    {
        ctrl = TCPIP_NETCTRL_GET_CONTEXT(ctrlId);

        TcpIp__ComStateHandler(ctrl);
    }

    /*timeouts process*/
    TCPIP_ADD_SYSTEM_TIME();
    sys_check_timeouts();

    /*rx*/
    while ((TcpIp__GetRxData(&rxBuffer, (uint16)sizeof(rxBuffer)) == E_OK) && (rxMax > (uint16)0))
    {
        rxMax--;
        TcpIp__RxIndication(rxBuffer);
    }

#if (TCPIP_TCP_ENABLED == STD_ON)
    for (socketId = (uint8)0; socketId < (TcpIp_SocketIdType)TCPIP_TCP_SOCKET_MAX; socketId++)
    {
        socket = TCPIP_SOCKET_GET_TCPCONTEXT(socketId);
        TcpIp__TcpSocketStateHandler(socketId);
        /*Tcp Transmission*/
        if ((socket->PcbPtr != NULL_PTR)
            && (socket->TxBufferList.HeadPtr != NULL_PTR))
        {
            TcpIp__TcpTransmit(socketId);
        }
    }
#endif

#if (TCPIP_UDP_ENABLED == STD_ON)
    for (socketId = (uint8)0; socketId < (TcpIp_SocketIdType)TCPIP_UDP_SOCKET_MAX; socketId++)
    {
        TcpIp__UdpSocketStateHandler(socketId);
    }
#endif

}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: TcpIp_RxIndication
*
* Description:   Notify that the TcpIp module receives a ethernet frame.
*
* Inputs:        CtrlIdx        - the EthIf Controller Index
*                FrameType      - the type of ethernet frame
*                IsBroadcast    - A broadcase frame or not
*                PhysAddrPtr    - the source addr(network order) of ethernet frame
*                DataPtr        - the payload of the ethernet frame
*                LenByte        - the length of the payload
*
* Outputs:       None
*
* Returns:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
/*PRQA S 3408 EOF*/
FUNC(void, TCPIP_CODE) TcpIp_RxIndication
(
    uint8 CtrlIdx,
    Eth_FrameType FrameType,
    boolean IsBroadcast,
    P2CONST(uint8, AUTOMATIC, AUTOMATIC) PhysAddrPtr,
    P2VAR(uint8, AUTOMATIC, AUTOMATIC) DataPtr,
    uint16 LenByte
)
{
    P2VAR(struct pbuf, AUTOMATIC, AUTOMATIC) buffer;
    uint16 length;
    TcpIp_CtrlIdType id = TcpIp__FindNetCtrlByEthIfCtrlIdx(CtrlIdx);
    uint8 tmp[TCPIP_ETHERNET_FRAME_HEADER_LENGTH];


    TCPIP_UNUSED(IsBroadcast);
    if (TCPIP_IS_UNINITIALIZED())
    {
        TCPIP_DET_REPORT_ERROR(TCPIP_API_RXINDICATION, TCPIP_E_NOTINIT);
    }
    else if ((NULL_PTR == PhysAddrPtr) || (NULL_PTR == DataPtr))
    {
        TCPIP_DET_REPORT_ERROR(TCPIP_API_RXINDICATION, TCPIP_E_PARAM_POINTER);
    }
    else if (!TCPIP_NETCTRL_IS_VALID_ID(id))
    {
        TCPIP_DET_REPORT_ERROR(TCPIP_API_RXINDICATION, TCPIP_E_INV_ARG);
    }
    /*PRQA S 4559 ++*/
    else if (TCPIP_NETCTRL_IS_LINK_UP(TCPIP_NETCTRL_GET_CONTEXT(id)))
    /*PRQA S 4559 --*/
    {
        /*payload without ethernet header*/
        length = LenByte + (uint16)TCPIP_ETHERNET_FRAME_HEADER_LENGTH;
        buffer = pbuf_alloc(PBUF_RAW, length + (uint16)ETH_PAD_SIZE, PBUF_POOL);
        if ((buffer != NULL_PTR) && (length > LenByte))
        {
            (void)pbuf_header(buffer, -ETH_PAD_SIZE);
            /*DA + SA + Type + payload*/    /*PRQA S 0488 EOF*/
            if (DataPtr == (PhysAddrPtr + 8))
            {
                /*linear address for ethernet frame?*/    /*PRQA S 3200,0488 EOF*/
                pbuf_take(buffer, DataPtr - TCPIP_ETHERNET_FRAME_HEADER_LENGTH, length);
            }
            else
            {
                /*separated address or VLAN?*/
                TCPIP_COPY_DATA(tmp, TCPIP_NETCTRL_GET_HWADDR_PTR(id), TCPIP_HWADDR_LENGTH);
                TCPIP_COPY_DATA(&tmp[TCPIP_HWADDR_LENGTH], PhysAddrPtr, TCPIP_HWADDR_LENGTH);
                tmp[12] = (uint8)(FrameType >> (uint16)8);
                tmp[13] = (uint8)(FrameType >> (uint16)0);
                pbuf_take(buffer, tmp, (u16_t)TCPIP_ETHERNET_FRAME_HEADER_LENGTH);
                (void)pbuf_header(buffer, -TCPIP_ETHERNET_FRAME_HEADER_LENGTH);
                pbuf_take(buffer, DataPtr, LenByte);
                (void)pbuf_header(buffer, TCPIP_ETHERNET_FRAME_HEADER_LENGTH);
            }

            (void)pbuf_header(buffer, ETH_PAD_SIZE);
            /*
             * The type field is temporarily borrowed because its value is always PBUF_POOL,
             * we will restore its value before passing it to LWIP.
             */
            buffer->type_internal = id;
            if (TcpIp__PutRxData(&buffer, (uint16)sizeof(buffer)) != E_OK)
            {
                (void)pbuf_free(buffer);
            }
        }
    }
    else
    {
        /*do nothing*/
    }
}

#if (TCPIP_TCP_ENABLED == STD_ON)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: TcpIp_TcpTransmit
*
* Description:   Requests transmission of data via TCP to a remote host.
*
* Inputs:        SocketId           - the socket id
*                DataPtr            - A linear buffer or NULL_PTR
*                AvailableLength    - the length of the data
*                ForceRetrieve      - TRUE: the whole data indicated by availableLength
*                                     shall be retrieved when DataPtr is NULL_PTR
*
* Outputs:       None
*
* Returns:       If the request has been accepted returns E_OK, otherwise returns
*                E_NOT_OK.
*
* Limitations:   Non reentrant for the same SocketId.
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TcpTransmit
(
    TcpIp_SocketIdType SocketId,
    P2CONST(uint8, AUTOMATIC, AUTOMATIC) DataPtr,
    uint32 AvailableLength,
    boolean ForceRetrieve
)
{
    Std_ReturnType ret = E_NOT_OK;
    /*PRQA S 3197 EOF*/
    P2VAR(TcpIp_TcpTxBufferHeadType, AUTOMATIC, AUTOMATIC) head = NULL_PTR;
    P2VAR(TcpIp_TcpSocketType, AUTOMATIC, AUTOMATIC) socket;
    TcpIp_TcpTxBufferListType list;
    TcpIp_UpLayerIndexType uplayer;
    uint16 copyLen;

    if (TCPIP_IS_UNINITIALIZED())
    {
        TCPIP_DET_REPORT_ERROR(TCPIP_API_TCPTRANSMIT, TCPIP_E_NOTINIT);
    }
    else if (SocketId >= (TcpIp_SocketIdType)TCPIP_TCP_SOCKET_MAX)
    {
        TCPIP_DET_REPORT_ERROR(TCPIP_API_TCPTRANSMIT, TCPIP_E_INV_ARG);
    }
    else if ((uint32)0 == AvailableLength)
    {
        TCPIP_DET_REPORT_ERROR(TCPIP_API_TCPTRANSMIT, TCPIP_E_INV_ARG);
    }
    else
    {
        list.HeadPtr = NULL_PTR;
        list.TailPtr = NULL_PTR;
        socket = TCPIP_SOCKET_GET_TCPCONTEXT(SocketId);
        if ((socket->PcbPtr != NULL_PTR)
            && ((TCPIP_SOCKET_STATE_CONNECTED == socket->State)
            || (TCPIP_SOCKET_STATE_WAITCLOSE == socket->State))
            && TCPIP_LOCALADDR_IS_VALID_ID(socket->LocalAddrId)
            && TCPIP_NETCTRL_IS_ONLINE(TCPIP_NETCTRL_GET_CONTEXT_BYLOCALADDR(socket->LocalAddrId)))
        {
            uplayer = socket->UpLayer;

            do
            {
                /*PRQA S 3792,3396 EOF*/
                copyLen = (uint16)TCPIP_MIN(AvailableLength, (uint32)TCPIP_TCP_MSS);
                /*SWS_TCPIP_00123*/
                head = mem_malloc(copyLen + TCPIP_TXBUFFER_HEAD_SIZE);
                if (NULL_PTR == head)
                {
                    ret = E_NOT_OK;
                    break;
                }

                head->NextPtr = NULL_PTR;
                head->Length = copyLen;
                /*SWS_TCPIP_00124*/    /*PRQA S 0488 EOF*/
                ret = TcpIp__CopyUpLayerData(SocketId,
                                                uplayer,
                                                DataPtr,
                                                (uint16)copyLen,
                                                ((P2VAR(uint8, AUTOMATIC, AUTOMATIC))head) + (uint8)TCPIP_TXBUFFER_HEAD_SIZE);
                if (E_OK == ret)
                {
                    /*PRQA S 3382 EOF*/
                    AvailableLength -= copyLen;
                    if (DataPtr != NULL_PTR)
                    {
                        DataPtr = &DataPtr[copyLen];
                    }
                    TcpIp__InsertTcpTxBufferHead(&list, head);
                }
            } while ((AvailableLength > (uint32)0) && (E_OK == ret));

            /*SWS_TCPIP_00125*/
            if ((ret != E_OK) && (FALSE == ForceRetrieve) && (list.HeadPtr != NULL_PTR))
            {
                ret = E_OK;
            }
        }

        if (E_OK == ret)
        {
            SchM_Enter_TcpIp_TCPIP_EXCLUSIVE_AREA_1();
            if ((socket->PcbPtr != NULL_PTR)
                && ((TCPIP_SOCKET_STATE_CONNECTED == socket->State)
                || (TCPIP_SOCKET_STATE_WAITCLOSE == socket->State))
                && TCPIP_LOCALADDR_IS_VALID_ID(socket->LocalAddrId)
                && TCPIP_NETCTRL_IS_ONLINE(TCPIP_NETCTRL_GET_CONTEXT_BYLOCALADDR(socket->LocalAddrId)))
            {
                /*SWS_TCPIP_00123*/    /*PRQA S 3353 EOF*/
                head = NULL_PTR;
                for(head = &socket->TxBufferList.HeadPtr; head->NextPtr != NULL_PTR ; head = head->NextPtr);
                head->NextPtr = list.HeadPtr;
            }
            else
            {
                ret = E_NOT_OK;
            }
            SchM_Exit_TcpIp_TCPIP_EXCLUSIVE_AREA_1();

            if (ret != E_OK)
            {
                TcpIp__ReleaseTcpTxBuffer(&list);
            }
        }
        else if (list.HeadPtr != NULL_PTR)
        {
            TcpIp__ReleaseTcpTxBuffer(&list);
        }
        else
        {
            /*nothing*/
        }
    }

    return ret;
}
#endif

#if (TCPIP_UDP_ENABLED == STD_ON)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: TcpIp_UdpTransmit
*
* Description:   Requests transmission of data via UDP to a remote host.
*
* Inputs:        SocketId       - the socket id
*                DataPtr        - A linear buffer or NULL_PTR
*                RemoteAddrPtr  - the IP address of remote host
*                TotalLength    - the length of the data
*
* Outputs:       None
*
* Returns:       If the request has been accepted returns E_OK, otherwise returns
*                E_NOT_OK.
*
* Limitations:   Non reentrant for the same SocketId.
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_UdpTransmit
(
    TcpIp_SocketIdType SocketId,
    P2CONST(uint8, AUTOMATIC, AUTOMATIC) DataPtr,
    P2CONST(TcpIp_SockAddrType, AUTOMATIC, AUTOMATIC) RemoteAddrPtr,
    uint16 TotalLength
)
{
    P2VAR(TcpIp_UdpSocketType, AUTOMATIC, AUTOMATIC) socket;
    P2CONST(TcpIp_SockAddrRealType, AUTOMATIC, AUTOMATIC) realRemoteAddr;
    P2VAR(struct pbuf, AUTOMATIC, AUTOMATIC) buf = NULL_PTR;
    Std_ReturnType ret = E_NOT_OK;
	
    /*PRQA S 3305 EOF*/
    realRemoteAddr = (P2CONST(TcpIp_SockAddrRealType, AUTOMATIC, AUTOMATIC))RemoteAddrPtr;
    if (TCPIP_IS_UNINITIALIZED())
    {
        TCPIP_DET_REPORT_ERROR(TCPIP_API_UDPTRANSMIT, TCPIP_E_NOTINIT);
    }
#if (TCPIP_TCP_ENABLED == STD_ON)
    else if ((SocketId >= (TcpIp_SocketIdType)TCPIP_SOCKET_MAX) || (SocketId < (TcpIp_SocketIdType)TCPIP_TCP_SOCKET_MAX))
#else
    else if (SocketId >= TCPIP_SOCKET_MAX)
#endif
    {
        TCPIP_DET_REPORT_ERROR(TCPIP_API_UDPTRANSMIT, TCPIP_E_INV_ARG);
    }
    else if (NULL_PTR == realRemoteAddr)
    {
        TCPIP_DET_REPORT_ERROR(TCPIP_API_UDPTRANSMIT, TCPIP_E_PARAM_POINTER);
    }
    else
    {
#if (TCPIP_TCP_ENABLED == STD_ON)
        socket = TCPIP_SOCKET_GET_UDPCONTEXT(SocketId - (TcpIp_SocketIdType)TCPIP_TCP_SOCKET_MAX);
#else
        socket = TCPIP_SOCKET_GET_UDPCONTEXT(SocketId);
#endif
        /*
         * The state of netif will be checked by lwip, so we do not check it now.
         */
        if ((socket->PcbPtr != NULL_PTR)
            && TCPIP_IS_VALID_DOMAIN(realRemoteAddr->Domain)
            && TCPIP_IS_SAME_DOMAIN(realRemoteAddr->Domain, socket->Domain))
        {
            buf = pbuf_alloc(PBUF_TRANSPORT, TotalLength, PBUF_RAM);
            if (buf != NULL_PTR)
            {
                if (TotalLength > (uint16)0)
                {
                    /*SWS_TCPIP_00121*/
                    ret = TcpIp__CopyUpLayerData(SocketId, socket->UpLayer, DataPtr, (uint32)TotalLength, buf->payload);
                }
                else
                {
                    ret = E_OK;
                }
            }
        }

        if (E_OK == ret)
        {
            ret = TcpIp__UdpTransmit(socket, realRemoteAddr, buf);
        }

        if (buf != NULL_PTR)
        {
            pbuf_free(buf);
        }
    }

    return ret;
}
#endif

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: TcpIp_Bind
*
* Description:   Bind a UDP or TCP socket to a local address and port.
*
* Inputs:        SocketId       - the socket id
*                LocalAddrId    - the local IP address id
*                PortPtr        - the local port
*
* Outputs:       PortPtr        - the bound port
*
* Returns:       If the request has been accepted returns E_OK, otherwise returns
*                E_NOT_OK.
*
* Limitations:   The TcpIp module can't understand the difference between IP_ANY
*                and TCPIP_LOCALADDR_ANY.
*                Non reentrant for the same SocketId.
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Bind
(
    TcpIp_SocketIdType SocketId,
    TcpIp_LocalAddrIdType LocalAddrId,
    P2VAR(uint16, AUTOMATIC, AUTOMATIC) PortPtr
)
{
    P2VAR(TcpIp_LocalAddrType, AUTOMATIC, AUTOMATIC) localAddrCtx;
    TcpIp_IpAddrStateType assigned = TCPIP_IPADDR_STATE_UNASSIGNED;
    Std_ReturnType ret = E_NOT_OK;

    if (TCPIP_IS_UNINITIALIZED())
    {
        TCPIP_DET_REPORT_ERROR(TCPIP_API_BIND, TCPIP_E_NOTINIT);
    }
    else if (NULL_PTR == PortPtr)
    {
        TCPIP_DET_REPORT_ERROR(TCPIP_API_BIND, TCPIP_E_PARAM_POINTER);
    }
    else if (SocketId >= (TcpIp_SocketIdType)TCPIP_SOCKET_MAX)
    {
        TCPIP_DET_REPORT_ERROR(TCPIP_API_BIND, TCPIP_E_INV_ARG);
    }
    else if ((LocalAddrId != TCPIP_LOCALADDRID_ANY) && (!TCPIP_LOCALADDR_IS_VALID_ID(LocalAddrId)))
    {
        TCPIP_DET_REPORT_ERROR(TCPIP_API_BIND, TCPIP_E_INV_ARG);
    }
    else
    {
        if (LocalAddrId == TCPIP_LOCALADDRID_ANY)
        {
            assigned = TCPIP_IPADDR_STATE_ASSIGNED;
        }
        else
        {
            localAddrCtx = TCPIP_LOCALADDR_GET_CONTEXT(LocalAddrId);
            if (TCPIP_LOCALADDR_IS_VALID_ASSIGNED_ID(localAddrCtx->AssignedId))
            {
                assigned = TCPIP_IPADDR_STATE_ASSIGNED;
            }
        }

        if (TCPIP_IPADDR_STATE_ASSIGNED == assigned)
        {
#if (TCPIP_TCP_ENABLED == STD_ON)
            /*SWS_TCPIP_00111*/
            if (SocketId < (TcpIp_SocketIdType)TCPIP_TCP_SOCKET_MAX)
            {
                ret = TcpIp__TcpBind(SocketId, LocalAddrId, PortPtr);
            }
            else
#endif
            {
#if (TCPIP_UDP_ENABLED == STD_ON)
                ret = TcpIp__UdpBind(SocketId, LocalAddrId, PortPtr);
#endif
            }
        }
    }

    return ret;
}

#if (TCPIP_TCP_ENABLED == STD_ON)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: TcpIp_TcpConnect
*
* Description:   Establish a TCP connection to the remote host.
*
* Inputs:        SocketId       - the socket id
*                RemoteAddrPtr  - the IP address of remote host
*
* Outputs:       None
*
* Returns:       If the request has been accepted returns E_OK, otherwise returns
*                E_NOT_OK.
*
* Limitations:   Non reentrant for the same SocketId.
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TcpConnect
(
    TcpIp_SocketIdType SocketId,
    P2CONST(TcpIp_SockAddrType, AUTOMATIC, AUTOMATIC) RemoteAddrPtr
)
{
    Std_ReturnType ret = E_NOT_OK;
    P2VAR(TcpIp_TcpSocketType, AUTOMATIC, AUTOMATIC) socket;
    P2CONST(TcpIp_SockAddrRealType, AUTOMATIC, AUTOMATIC) remote;

    if (TCPIP_IS_UNINITIALIZED())
    {
        TCPIP_DET_REPORT_ERROR(TCPIP_API_TCPCONNECT, TCPIP_E_NOTINIT);
    }
    else if (SocketId >= (TcpIp_SocketIdType)TCPIP_TCP_SOCKET_MAX)
    {
        TCPIP_DET_REPORT_ERROR(TCPIP_API_TCPCONNECT, TCPIP_E_INV_ARG);
    }
    /*SWS_TCPIP_00129*/
    else if (NULL_PTR == RemoteAddrPtr)
    {
        TCPIP_DET_REPORT_ERROR(TCPIP_API_TCPCONNECT, TCPIP_E_PARAM_POINTER);
    }
    else if ((!TCPIP_IS_VALID_DOMAIN(RemoteAddrPtr->Domain))
            || (!TCPIP_IS_SAME_DOMAIN(RemoteAddrPtr->Domain, TCPIP_SOCKET_GET_TCPCONTEXT(SocketId)->Domain)))
    {
        TCPIP_DET_REPORT_ERROR(TCPIP_API_TCPCONNECT, TCPIP_E_INV_ARG);
    }
    else
    {
        socket = TCPIP_SOCKET_GET_TCPCONTEXT(SocketId);
        SchM_Enter_TcpIp_TCPIP_EXCLUSIVE_AREA_1();
        if ((TCPIP_SOCKET_STATE_IDLE == socket->State)
            && (socket->PcbPtr != NULL_PTR)
            && TCPIP_LOCALADDR_IS_VALID_ID(socket->LocalAddrId))
        {
            /*PRQA S 3305 EOF*/
            remote = (P2CONST(TcpIp_SockAddrRealType, AUTOMATIC, AUTOMATIC))RemoteAddrPtr;
            /*SWS_TCPIP_00112*/
            TCPIP_SOCKET_COPY_REMOTEADDR(&socket->RemoteAddr, remote);
            TCPIP_SOCKET_SET_CONNECT(socket);
            ret = E_OK;
        }
        SchM_Exit_TcpIp_TCPIP_EXCLUSIVE_AREA_1();
    }

    return ret;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: TcpIp_TcpListen
*
* Description:   Listen on the TCP socket specified by the socket identifier.
*
* Inputs:        SocketId       - the socket id
*                MaxChannels    - Maximum number of new parallel connections
*                                 established on this listen connection.
*
* Outputs:       None
*
* Returns:       If the request has been accepted returns E_OK, otherwise returns
*                E_NOT_OK.
*
* Limitations:   Non reentrant for the same SocketId.
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TcpListen
(
    TcpIp_SocketIdType SocketId,
    uint16 MaxChannels
)
{
    Std_ReturnType ret = E_NOT_OK;
    P2VAR(TcpIp_TcpSocketType, AUTOMATIC, AUTOMATIC) socket;

    if (TCPIP_IS_UNINITIALIZED())
    {
        TCPIP_DET_REPORT_ERROR(TCPIP_API_TCPLISTEN, TCPIP_E_NOTINIT);
    }
    else if (SocketId >= (TcpIp_SocketIdType)TCPIP_TCP_SOCKET_MAX)
    {
        TCPIP_DET_REPORT_ERROR(TCPIP_API_TCPLISTEN, TCPIP_E_INV_ARG);
    }
    else
    {
        socket = TCPIP_SOCKET_GET_TCPCONTEXT(SocketId);
        SchM_Enter_TcpIp_TCPIP_EXCLUSIVE_AREA_1();
        if ((TCPIP_SOCKET_STATE_IDLE == socket->State)
            && (socket->PcbPtr != NULL_PTR)
            && ((TCPIP_LOCALADDRID_ANY == socket->LocalAddrId)
            || TCPIP_LOCALADDR_IS_VALID_ID(socket->LocalAddrId)))
        {
            /*SWS_TCPIP_00114*/
            socket->MaxChannels = MaxChannels;
            /*SWS_TCPIP_00113*/
            TCPIP_SOCKET_SET_LISTEN(socket);
            ret = E_OK;
        }
        SchM_Exit_TcpIp_TCPIP_EXCLUSIVE_AREA_1();
    }

    return ret;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: TcpIp_TcpReceived
*
* Description:   the reception of socket data is confirmed to the TcpIp module.
*
* Inputs:        SocketId   - the socket id
*                Length     - Number of bytes finally consumed by the upper layer 
*
* Outputs:       None
*
* Returns:       If the request has been accepted returns E_OK, otherwise returns
*                E_NOT_OK.
*
* Limitations:   Non reentrant for the same SocketId.
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TcpReceived
(
    TcpIp_SocketIdType SocketId,
    uint32 Length
)
{
    Std_ReturnType ret = E_NOT_OK;
    P2VAR(TcpIp_TcpSocketType, AUTOMATIC, AUTOMATIC) socket;

    if (TCPIP_IS_UNINITIALIZED())
    {
        TCPIP_DET_REPORT_ERROR(TCPIP_API_TCPRECEIVED, TCPIP_E_NOTINIT);
    }
    else if (SocketId >= (TcpIp_SocketIdType)TCPIP_TCP_SOCKET_MAX)
    {
        TCPIP_DET_REPORT_ERROR(TCPIP_API_TCPRECEIVED, TCPIP_E_INV_ARG);
    }
    else if ((uint32)0 == Length)
    {
        TCPIP_DET_REPORT_ERROR(TCPIP_API_TCPRECEIVED, TCPIP_E_INV_ARG);
        ret = E_OK;
    }
    else
    {
        socket = TCPIP_SOCKET_GET_TCPCONTEXT(SocketId);
        SchM_Enter_TcpIp_TCPIP_EXCLUSIVE_AREA_1();
        if ((socket->PcbPtr != NULL_PTR)
            &&(TCPIP_SOCKET_STATE_CONNECTED == socket->State))
        {
            /*PRAQ S 3792 EOF*/
            socket->ReceivedDataSize += (uint16)Length;
            ret = E_OK;
        }
        SchM_Exit_TcpIp_TCPIP_EXCLUSIVE_AREA_1();
    }

    return ret;
}
#endif

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: TcpIp_GetSocket
*
* Description:   Allocates a new TCP or UDP socket
*
* Inputs:        Domain         - IP address family
*                Protocol       - Socket protocol, TCP or UDP
*                UpLayer        - the up layer of TcpIp Module
*
* Outputs:       SocketIdPtr    - the allocated socket id
*
* Returns:       If the request has been accepted returns E_OK, otherwise returns
*                E_NOT_OK.
*
* Limitations:   Non reentrant for the same SocketId.
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_GetSocket
(
    TcpIp_DomainType Domain,
    TcpIp_ProtocolType Protocol,
    TcpIp_UpLayerIndexType UpLayer,
    P2VAR(TcpIp_SocketIdType, AUTOMATIC, AUTOMATIC) SocketIdPtr
)
{
    Std_ReturnType ret = E_NOT_OK;
    TcpIp_SocketIdType socketId = TCPIP_SOCKETID_INVALID;
    P2VAR(struct tcp_pcb, AUTOMATIC, AUTOMATIC) tcp;
    P2VAR(struct udp_pcb, AUTOMATIC, AUTOMATIC) udp;

    if (TCPIP_IS_UNINITIALIZED())
    {
        TCPIP_DET_REPORT_ERROR(TCPIP_API_GETSOCKET, TCPIP_E_NOTINIT);
    }
    else if (!TCPIP_IS_VALID_DOMAIN(Domain))
    {
        /*SWS_TCPIP_00128*/
        TCPIP_DET_REPORT_ERROR(TCPIP_API_GETSOCKET, TCPIP_E_AFNOSUPPORT);
    }
    else if (UpLayer >= (TcpIp_UpLayerIndexType)TCPIP_UPLAYER_MAX)
    {
        TCPIP_DET_REPORT_ERROR(TCPIP_API_GETSOCKET, TCPIP_E_INV_ARG);
    }
    else if (NULL_PTR == SocketIdPtr)
    {
        TCPIP_DET_REPORT_ERROR(TCPIP_API_GETSOCKET, TCPIP_E_PARAM_POINTER);
    }
    else
    {
        switch (Protocol)
        {
#if (TCPIP_TCP_ENABLED == STD_ON)
        case TCPIP_IPPROTO_TCP :
            tcp = TCPIP_SOCKET_NEW_TCPSOCKET(Domain);
            if (tcp != NULL_PTR)
            {
                socketId = TcpIp__GetTcpSocket(Domain, UpLayer, tcp);
                tcp->so_options |= SOF_REUSEADDR; /* zeyu CP_937 */

                if (TCPIP_SOCKETID_INVALID == socketId)
                {
                    (void)tcp_close(tcp);
                }
#if (TCPIP_TCP_KEEP_ALIVE_ENABLED == STD_ON)
                else
                {
                    tcp->so_options |= SOF_KEEPALIVE;
                }
#endif          
            }
            break;
#endif
#if (TCPIP_UDP_ENABLED == STD_ON)
        case TCPIP_IPPROTO_UDP :
            udp = TCPIP_SOCKET_NEW_UDPSOCKET(Domain);
            if (udp != NULL_PTR)
            {
                socketId = TcpIp__GetUdpSocket(Domain, UpLayer, udp);
                if (TCPIP_SOCKETID_INVALID == socketId)
                {
                    udp_remove(udp);
                }
#if (TCPIP_TCP_ENABLED == STD_ON)
                else
                {
                    /*PRQA S 3382 EOF*/
                    socketId += (TcpIp_SocketIdType)TCPIP_TCP_SOCKET_MAX;
                }
#endif
            }
            break;
#endif
        default :
            /*SWS_TCPIP_00128*/
            TCPIP_DET_REPORT_ERROR(TCPIP_API_GETSOCKET, TCPIP_E_PROTOTYPE);
            break;
        }

        if (socketId != TCPIP_SOCKETID_INVALID)
        {
            *SocketIdPtr = socketId;
            ret = E_OK;
        }
    }

    return ret;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: TcpIp_Close
*
* Description:   Close the socket and release all related resources.
*
* Inputs:        SocketId   - the socket id
*                Abort      - connection will immediately be terminated or not
*
* Outputs:       None
*
* Returns:       If the request has been accepted returns E_OK, otherwise returns
*                E_NOT_OK.
*
* Limitations:   Non reentrant for the same SocketId.
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Close
(
    TcpIp_SocketIdType SocketId,
    boolean Abort
)
{
    Std_ReturnType ret = E_NOT_OK;
    P2VAR(TcpIp_TcpSocketType, AUTOMATIC, AUTOMATIC) socket;
    P2VAR(TcpIp_UdpSocketType, AUTOMATIC, AUTOMATIC) udp;

    if (TCPIP_IS_UNINITIALIZED())
    {
        TCPIP_DET_REPORT_ERROR(TCPIP_API_CLOSE, TCPIP_E_NOTINIT);
    }
    else if (SocketId >= (TcpIp_SocketIdType)TCPIP_SOCKET_MAX)
    {
        TCPIP_DET_REPORT_ERROR(TCPIP_API_CLOSE, TCPIP_E_INV_ARG);
    }
#if (TCPIP_TCP_ENABLED == STD_ON)
    else if (SocketId < (TcpIp_SocketIdType)TCPIP_TCP_SOCKET_MAX)
    {
        /*TCP socket*/
        socket = TCPIP_SOCKET_GET_TCPCONTEXT(SocketId);
        SchM_Enter_TcpIp_TCPIP_EXCLUSIVE_AREA_1();
        if ((socket->PcbPtr != NULL_PTR)
            && (socket->State < TCPIP_SOCKET_STATE_CLOSE))
        {
            socket->Abort = (uint8)Abort;
            /*PRQA S 2201 ++*/
            /*PRQA S 2209 ++*/
            if (TCPIP_SOCKET_IS_IDLE(socket))
	        {
	            /*passtive close*/
                socket->Abort = TRUE;
	        }
            /*PRQA S 2201 --*/
            /*PRQA S 2209 --*/
            else if(TCPIP_SOCKET_IS_WAITCLOSE(socket))
            {
                /*passtive close*/
                TCPIP_SOCKET_SET_CLOSED(socket);
            }
            else if (TCPIP_SOCKET_IS_LISTEN(socket)
                    || TCPIP_SOCKET_IS_LISTENING(socket))
            {
                /*close listen*/
                TCPIP_SOCKET_SET_CLOSE_LISTEN(socket);
            }
            else
            {
                /*active close*/
                TCPIP_SOCKET_SET_CLOSE(socket);
            }
            
            ret = E_OK;
        }
        SchM_Exit_TcpIp_TCPIP_EXCLUSIVE_AREA_1();
    }
#endif
    else
    {
#if (TCPIP_UDP_ENABLED == STD_ON)
        /*UDP socket*/
#if (TCPIP_TCP_ENABLED == STD_ON)
        SocketId -= (TcpIp_SocketIdType)TCPIP_TCP_SOCKET_MAX;
#endif
        udp = TCPIP_SOCKET_GET_UDPCONTEXT(SocketId);
        SchM_Enter_TcpIp_TCPIP_EXCLUSIVE_AREA_1();
        if ((udp->PcbPtr != NULL_PTR)
            && (!TCPIP_SOCKET_IS_CLOSE(udp)))
        {
            /*SWS_TCPIP_00110*/
            TCPIP_SOCKET_SET_CLOSE(udp);
            ret = E_OK;
        }
        SchM_Exit_TcpIp_TCPIP_EXCLUSIVE_AREA_1();
#endif
    }

    return ret;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: TcpIp_RequestComMode
*
* Description:   Changes the TcpIp state of the communication network identified
*                by EthIf controller index.
*
* Inputs:        CtrlIdx    - the EthIf controller index
*                State      - Requested TcpIp NetIfCtrl state
*
* Outputs:       None
*
* Returns:       If the request has been accepted returns E_OK, otherwise returns
*                E_NOT_OK.
*
* Limitations:   Non Reentrant.
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_RequestComMode
(
    uint8 CtrlIdx,
    TcpIp_StateType State
)
{
    Std_ReturnType ret = E_NOT_OK;
    TcpIp_CtrlIdType id;

    if (TCPIP_IS_UNINITIALIZED())
    {
        TCPIP_DET_REPORT_ERROR(TCPIP_API_REQUESTCOMMODE, TCPIP_E_NOTINIT);
    }
    /*SWS_TCPIP_00089*/
    else if (!(State < TCPIP_STATE_VISIBLE))
    {
        TCPIP_DET_REPORT_ERROR(TCPIP_API_REQUESTCOMMODE, TCPIP_E_INV_ARG);
    }
    else
    {
        id = TcpIp__FindNetCtrlByEthIfCtrlIdx(CtrlIdx);
        if (TCPIP_NETCTRL_IS_VALID_ID(id))
        {
            TCPIP_NETCTRL_SET_REQUEST_STATE(TCPIP_NETCTRL_GET_CONTEXT(id), State);
            ret = E_OK;
        }
        else
        {
            TCPIP_DET_REPORT_ERROR(TCPIP_API_REQUESTCOMMODE, TCPIP_E_INV_ARG);
        }
    }

    return ret;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: TcpIp_RequestIpAddrAssignment
*
* Description:   Initializes the local IP address assignment for the IP address.
*
* Inputs:        LocalAddrId        - the local address id
*                Type               - the assignment type of local address
*                LocalIpAddrPtr     - the static IP address
*                Netmask            - the static netmask in CIDR Notation
*                DefaultRouterPtr   - the static default router
*
* Outputs:       None
*
* Returns:       If the request has been accepted returns E_OK, otherwise returns
*                E_NOT_OK.
*
* Limitations:   Non Reentrant.
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_RequestIpAddrAssignment
(
    TcpIp_LocalAddrIdType LocalAddrId,
    TcpIp_IpAddrAssignmentType Type,
    P2CONST(TcpIp_SockAddrType, AUTOMATIC, AUTOMATIC) LocalIpAddrPtr,
    uint8 Netmask,
    P2CONST(TcpIp_SockAddrType, AUTOMATIC, AUTOMATIC) DefaultRouterPtr
)
{
    P2VAR(TcpIp_LocalAddrType, AUTOMATIC, AUTOMATIC) ctx = NULL_PTR;
    TcpIp_LocalAddrAssignmentIdType assignmentId = (uint8)TCPIP_LOCALADDR_ASSIGNMENT_PRIORITY_MAX;
    P2CONST(TcpIp_SockAddrRealType, AUTOMATIC, AUTOMATIC) ipAddr;
    P2CONST(TcpIp_SockAddrRealType, AUTOMATIC, AUTOMATIC) router;
    Std_ReturnType ret = E_NOT_OK;

    if (TCPIP_IS_UNINITIALIZED())
    {
        TCPIP_DET_REPORT_ERROR(TCPIP_API_REQUESTIPADDRASSIGNMENT, TCPIP_E_NOTINIT);
    }
    else if (!TCPIP_LOCALADDR_IS_VALID_ID(LocalAddrId))
    {
        TCPIP_DET_REPORT_ERROR(TCPIP_API_REQUESTIPADDRASSIGNMENT, TCPIP_E_INV_ARG);
    }
    else
    {
        ctx = TCPIP_LOCALADDR_GET_CONTEXT(LocalAddrId);
        assignmentId = TCPIP_LOCALADDR_GET_ASSIGNMENT_ID(ctx, Type);
    }

    if ((NULL_PTR == ctx) || (assignmentId >= (uint8)TCPIP_LOCALADDR_ASSIGNMENT_PRIORITY_MAX))
    {
        TCPIP_DET_REPORT_ERROR(TCPIP_API_REQUESTIPADDRASSIGNMENT, TCPIP_E_INV_ARG);
    }
    /*SWS_TCPIP_00198*/
    else if (!TCPIP_LOCALADDR_IS_MANUAL_ASSIGNMENT(ctx->ConfigPtr, assignmentId))
    {
        TCPIP_DET_REPORT_ERROR(TCPIP_API_REQUESTIPADDRASSIGNMENT, TCPIP_E_INV_CONFIG);
    }
    else if (TCPIP_IPADDR_ASSIGNMENT_STATIC == Type)
    {
#if (TCPIP_STATIC_IPADDR_MAX > 0)
        /*SWS_TCPIP_00079*/
        if (TCPIP_LOCALADDR_HAS_STATIC_IPADDR(ctx->ConfigPtr))
        {
            /*The TcpIp do NOT know which Static IP address should be used if the LocalIpAddrPtr is NOT NULL_PTR.*/
            if ((NULL_PTR == LocalIpAddrPtr) && (NULL_PTR == DefaultRouterPtr))
            {
                ret = E_OK;
            }
        }
        else
#endif
        /*PRQA S 3415 EOF*/
        if ((LocalIpAddrPtr != NULL_PTR)
            && (DefaultRouterPtr != NULL_PTR)
            && (TcpIp__CheckStaticIpAddr(ctx->ConfigPtr, LocalIpAddrPtr, Netmask, DefaultRouterPtr) == E_OK))
        {
            /**
             * The parameter Type set to TCPIP_IPADDR_ASSIGNMENT_STATIC and no TcpIpStaticIpAddressConfig container
             * is configured for the LocalAddr specified by parameter LocalAddrId.
             */
            /*PRQA S 3305 EOF*/
            ipAddr = (P2CONST(TcpIp_SockAddrRealType, AUTOMATIC, AUTOMATIC))LocalIpAddrPtr;
            router = (P2CONST(TcpIp_SockAddrRealType, AUTOMATIC, AUTOMATIC))DefaultRouterPtr;
            SchM_Enter_TcpIp_TCPIP_EXCLUSIVE_AREA_2();
            TCPIP_SET_STATICIPADDR(&ctx->StaticIpAddr, ipAddr, Netmask, router);
            SchM_Exit_TcpIp_TCPIP_EXCLUSIVE_AREA_2();
            ret = E_OK;
        }
        else
        {
            /*do nothing*/
        }

        if (E_OK == ret)
        {
            /*SWS_TCPIP_00116*//*SWS_TCPIP_00195*/
            TCPIP_LOCALADDR_SET_ASSIGNMENT_REQUEST(ctx, assignmentId);
        }
        else
        {
            TCPIP_DET_REPORT_ERROR(TCPIP_API_REQUESTIPADDRASSIGNMENT, TCPIP_E_INV_ARG);
        }
    }
    else
    {
        /*SWS_TCPIP_00116*//*SWS_TCPIP_00195*/
        TCPIP_LOCALADDR_SET_ASSIGNMENT_REQUEST(ctx, assignmentId);
        ret = E_OK;
    }

    return ret;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: TcpIp_ReleaseIpAddrAssignment
*
* Description:   Releases the local IP address assignment for the IP address.
*
* Inputs:        LocalAddrId        - the local address id
*
* Outputs:       None
*
* Returns:       If the request has been accepted returns E_OK, otherwise returns
*                E_NOT_OK.
*
* Limitations:   Non Reentrant.
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_ReleaseIpAddrAssignment
(
    TcpIp_LocalAddrIdType LocalAddrId
)
{
    P2VAR(TcpIp_LocalAddrType, AUTOMATIC, AUTOMATIC) ctx;
    TcpIp_LocalAddrAssignmentIdType i;
    Std_ReturnType ret = E_NOT_OK;

    if (TCPIP_IS_UNINITIALIZED())
    {
        TCPIP_DET_REPORT_ERROR(TCPIP_API_RELEASEIPADDRASSIGNMENT, TCPIP_E_NOTINIT);
    }
    else if (!TCPIP_LOCALADDR_IS_VALID_ID(LocalAddrId))
    {
        TCPIP_DET_REPORT_ERROR(TCPIP_API_RELEASEIPADDRASSIGNMENT, TCPIP_E_INV_ARG);
    }
    else
    {
        ctx = TCPIP_LOCALADDR_GET_CONTEXT(LocalAddrId);

        for (i = (uint8)0; i < (uint8)TCPIP_LOCALADDR_ASSIGNMENT_PRIORITY_MAX; i++)
        {
            /*SWS_TCPIP_00199 If all assignment are AUTOMATIC return E_NOT_OK.*/
            if (TCPIP_LOCALADDR_IS_MANUAL_ASSIGNMENT(ctx->ConfigPtr, i))
            {
                /*SWS_TCPIP_00196*/
                TCPIP_LOCALADDR_CLEAR_ASSIGNMENT_REQUEST(ctx, i);
                /*do NOT clear Static IP.*/
                ret = E_OK;
            }
        }
    }

    return ret;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: TcpIp_GetCtrlIdx
*
* Description:   Gets the EthIf controller index related to LocalAddrId.
*
* Inputs:        LocalAddrId        - the local address id
*
* Outputs:       CtrlIdx            - the EthIf controller index
*
* Returns:       If the request has been accepted returns E_OK, otherwise returns
*                E_NOT_OK.
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_GetCtrlIdx
(
    TcpIp_LocalAddrIdType LocalAddrId,
    P2VAR(uint8, AUTOMATIC, AUTOMATIC) CtrlIdxPtr
)
{
    P2VAR(TcpIp_LocalAddrType, AUTOMATIC, AUTOMATIC) ctx;
    Std_ReturnType ret = E_NOT_OK;

    if (TCPIP_IS_UNINITIALIZED())
    {
        TCPIP_DET_REPORT_ERROR(TCPIP_API_GETCTRLIDX, TCPIP_E_NOTINIT);
    }
    else if (NULL_PTR == CtrlIdxPtr)
    {
        TCPIP_DET_REPORT_ERROR(TCPIP_API_GETCTRLIDX, TCPIP_E_PARAM_POINTER);
    }
    else if (!TCPIP_LOCALADDR_IS_VALID_ID(LocalAddrId))
    {
        TCPIP_DET_REPORT_ERROR(TCPIP_API_GETCTRLIDX, TCPIP_E_INV_ARG);
    }
    else
    {
        ctx = TCPIP_LOCALADDR_GET_CONTEXT(LocalAddrId);
        /*SWS_TCPIP_00141*/
        *CtrlIdxPtr = TCPIP_NETCTRL_GET_CONTEXT(ctx->CtrlId)->CtrlIdx;
        ret = E_OK;
    }

    return ret;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: TcpIp_GetIpAddr
*
* Description:   Obtains the local IP address actually used by LocalAddrId, the
*                netmask and default router.
*
* Inputs:        LocalAddrId        - the local address id
*
* Outputs:       IpAddrPtr          - the IP address
*                NetmaskPtr         - the netmask in CIDR notation
*                DefaultRouterPtr   - the gateway
*
* Returns:       If the request has been accepted returns E_OK, otherwise returns
*                E_NOT_OK.
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_GetIpAddr
(
    TcpIp_LocalAddrIdType LocalAddrId,
    P2VAR(TcpIp_SockAddrType, AUTOMATIC, AUTOMATIC) IpAddrPtr,
    P2VAR(uint8, AUTOMATIC, AUTOMATIC) NetmaskPtr,
    P2VAR(TcpIp_SockAddrType, AUTOMATIC, AUTOMATIC) DefaultRouterPtr
)
{
    P2VAR(TcpIp_LocalAddrType, AUTOMATIC, AUTOMATIC) ctx;
    P2VAR(TcpIp_SockAddrRealType, AUTOMATIC, AUTOMATIC) addr;
    TcpIp_StaticIpAddrType ip;
    Std_ReturnType ret = E_NOT_OK;

    if (TCPIP_IS_UNINITIALIZED())
    {
        TCPIP_DET_REPORT_ERROR(TCPIP_API_GETIPADDR, TCPIP_E_NOTINIT);
    }
    else if (!TCPIP_LOCALADDR_IS_VALID_ID(LocalAddrId))
    {
        TCPIP_DET_REPORT_ERROR(TCPIP_API_GETIPADDR, TCPIP_E_INV_ARG);
    }
    else if ((NULL_PTR == IpAddrPtr)
            || (NULL_PTR == NetmaskPtr)
            || (NULL_PTR == DefaultRouterPtr))
    {
        TCPIP_DET_REPORT_ERROR(TCPIP_API_GETIPADDR, TCPIP_E_PARAM_POINTER);
    }
    /*SWS_TCPIP_00206*/
    else if ((!TCPIP_IS_VALID_DOMAIN(IpAddrPtr->Domain))
            || (!TCPIP_IS_VALID_DOMAIN(DefaultRouterPtr->Domain))
            || (!TCPIP_IS_SAME_DOMAIN(IpAddrPtr->Domain, DefaultRouterPtr->Domain)))
    {
        TCPIP_DET_REPORT_ERROR(TCPIP_API_GETIPADDR, TCPIP_E_INV_ARG);
    }
    else
    {
        ctx = TCPIP_LOCALADDR_GET_CONTEXT(LocalAddrId);
        if (TCPIP_LOCALADDR_IS_VALID_ASSIGNED_ID(ctx->AssignedId))
        {
            SchM_Enter_TcpIp_TCPIP_EXCLUSIVE_AREA_2();
            ret = TCPIP_LOCALADDR_GET_ASSIGNMENT_STATE(ctx, ctx->AssignedId, &ip);
            SchM_Exit_TcpIp_TCPIP_EXCLUSIVE_AREA_2();
            /*SWS_TCPIP_00205*/ 
            if ((E_OK == ret) && TCPIP_IS_SAME_DOMAIN(IpAddrPtr->Domain, ip.Domain))
            {
                /*PRQA S 3305 EOF*/
                addr = (P2VAR(TcpIp_SockAddrRealType, AUTOMATIC, AUTOMATIC))IpAddrPtr;
                TCPIP_SOCKET_SET_ADDR(addr, ip.Domain, &ip.IpAddr);
                /*PRQA S 3305 EOF*/
                addr = (P2VAR(TcpIp_SockAddrRealType, AUTOMATIC, AUTOMATIC))DefaultRouterPtr;
                TCPIP_SOCKET_SET_ADDR(addr, ip.Domain, &ip.DefaultRouter);
                *NetmaskPtr = ip.Netmask;
            }
        }
    }

    return ret;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: TcpIp_GetPhysAddr
*
* Description:   Obtains the physical source address used by the EthIf controller.
*
* Inputs:        LocalAddrId    - the local address id
*
* Outputs:       PhysAddrPtr    - the MAC address
*
* Returns:       If the request has been accepted returns E_OK, otherwise returns
*                E_NOT_OK.
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_GetPhysAddr
(
    TcpIp_LocalAddrIdType LocalAddrId,
    P2VAR(uint8, AUTOMATIC, AUTOMATIC) PhysAddrPtr
)
{
    P2VAR(TcpIp_LocalAddrType, AUTOMATIC, AUTOMATIC) ctx;
    Std_ReturnType ret = E_NOT_OK;

    if (TCPIP_IS_UNINITIALIZED())
    {
        TCPIP_DET_REPORT_ERROR(TCPIP_API_GETCTRLIDX, TCPIP_E_NOTINIT);
    }
    else if (NULL_PTR == PhysAddrPtr)
    {
        TCPIP_DET_REPORT_ERROR(TCPIP_API_GETCTRLIDX, TCPIP_E_PARAM_POINTER);
    }
    else if (!TCPIP_LOCALADDR_IS_VALID_ID(LocalAddrId))
    {
        TCPIP_DET_REPORT_ERROR(TCPIP_API_GETCTRLIDX, TCPIP_E_INV_ARG);
    }
    else
    {
        ctx = TCPIP_LOCALADDR_GET_CONTEXT(LocalAddrId);
        TCPIP_COPY_PHYS_ADDR(PhysAddrPtr, TCPIP_NETCTRL_GET_CONTEXT(ctx->CtrlId));
        ret = E_OK;
    }

    return ret;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: TcpIp_GetRemotePhysAddr
*
* Description:   Queries the IP/physical address translation table specified by
*                CtrlIdx and returns the physical address related to the IP
*                address specified by IpAddrPtr.
*
* Inputs:        CtrlIdx        - the EthIf controller index
*                IpAddrPtr      - the IP address
*                initRes        - the ARP request shall be initiated or not
*
* Outputs:       PhysAddrPtr    - the MAC address of remote host.
*
* Returns:       If the request has been accepted returns TCPIP_OK, otherwise
*                returns TCPIP_E_PHYS_ADDR_MISS.
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(TcpIp_ReturnType, TCPIP_CODE) TcpIp_GetRemotePhysAddr
(
    uint8 CtrlIdx,
    P2VAR(TcpIp_SockAddrType, AUTOMATIC, AUTOMATIC) IpAddrPtr,
    P2VAR(uint8, AUTOMATIC, AUTOMATIC) PhysAddrPtr,
    boolean initRes
)
{
    P2VAR(TcpIp_NetIfCtrlType, AUTOMATIC, AUTOMATIC) netCtrl;
    P2VAR(TcpIp_SockAddrRealType, AUTOMATIC, AUTOMATIC) addr;
    P2CONST(ip_addr_t, AUTOMATIC, AUTOMATIC) retIp;
    P2VAR(struct eth_addr, AUTOMATIC, AUTOMATIC) ethAddr;
    ip_addr_t ip;

    TcpIp_CtrlIdType netCtrlId = TcpIp__FindNetCtrlByEthIfCtrlIdx(CtrlIdx);
    TcpIp_ReturnType ret = TCPIP_E_PHYS_ADDR_MISS;
    sint8 id;

    if (TCPIP_IS_UNINITIALIZED())
    {
        TCPIP_DET_REPORT_ERROR(TCPIP_API_GETREMOTEPHYSADDR, TCPIP_E_NOTINIT);
    }
    else if (!TCPIP_NETCTRL_IS_VALID_ID(netCtrlId))
    {
        TCPIP_DET_REPORT_ERROR(TCPIP_API_GETREMOTEPHYSADDR, TCPIP_E_INV_ARG);
    }
    else if ((NULL_PTR == PhysAddrPtr) || (NULL_PTR == IpAddrPtr))
    {
        TCPIP_DET_REPORT_ERROR(TCPIP_API_GETREMOTEPHYSADDR, TCPIP_E_PARAM_POINTER);
    }
    else if (!TCPIP_IS_VALID_DOMAIN(IpAddrPtr->Domain))
    {
        TCPIP_DET_REPORT_ERROR(TCPIP_API_GETREMOTEPHYSADDR, TCPIP_E_INV_ARG);
    }
    else
    {
        netCtrl = TCPIP_NETCTRL_GET_CONTEXT(netCtrlId);
        /*PRQA S 3305 EOF*/
        addr = (P2VAR(TcpIp_SockAddrRealType, AUTOMATIC, AUTOMATIC))IpAddrPtr;

        TCPIP_LWIP_COPY_IPADDR((ip4_addr_t*)&ip, addr->Domain, addr);
        SchM_Enter_TcpIp_TCPIP_EXCLUSIVE_AREA_2();
        TCPIP_NETCTRL_FIND_ETHADDR(netCtrl,(ip4_addr_t*)&ip, &ethAddr, (ip_addr_t*)&retIp, id);
        SchM_Exit_TcpIp_TCPIP_EXCLUSIVE_AREA_2();
        if (id >= (sint8)0)
        {
            /*SWS_TCPIP_00138.a*/
            /*PRQA S 2754,1569,435 ++*/
            TCPIP_COPY_DATA(PhysAddrPtr, ethAddr->addr, TCPIP_HWADDR_LENGTH);
            /*PRQA S 2754,1569 --*/
            /*PRQA S 0432 --*/
            ret = TCPIP_OK;
        }
        else if (TRUE == initRes)
        {
            /*SWS_TCPIP_00138.b*/
            SchM_Enter_TcpIp_TCPIP_EXCLUSIVE_AREA_2();
            /*PRQA S 3200 EOF*/
            TCPIP_NETCTRL_REQUEST_ETHADDR(netCtrl, &ip);
            SchM_Exit_TcpIp_TCPIP_EXCLUSIVE_AREA_2();
        }
        else
        {
            /*do nothing*/
        }
    }

    return ret;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: TcpIp_ChangeParameter
*
* Description:   Change a parameter of a socket.
*
* Inputs:        SocketId       - the socket id
*                ParameterId    - the parameter id
*                ParameterValue - the value of parameter
*
* Outputs:       None
*
* Returns:       If the request has been accepted returns E_OK, otherwise returns
*                E_NOT_OK.
*
* Limitations:   Non reentrant for the same SocketId.
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_ChangeParameter
(
    TcpIp_SocketIdType SocketId,
    /*PRQA S 3206 EOF*/
    TcpIp_ParamIdType ParameterId,
    P2CONST(uint8, AUTOMATIC, AUTOMATIC) ParameterValue
)
{
    Std_ReturnType ret = E_NOT_OK;

    if (TCPIP_IS_UNINITIALIZED())
    {
        TCPIP_DET_REPORT_ERROR(TCPIP_API_CHANGEPARAMETER, TCPIP_E_NOTINIT);
    }
    else if (SocketId >= (TcpIp_SocketIdType)TCPIP_SOCKET_MAX)
    {
        TCPIP_DET_REPORT_ERROR(TCPIP_API_CHANGEPARAMETER, TCPIP_E_INV_ARG);
    }
    else if (NULL_PTR == ParameterValue)
    {
        TCPIP_DET_REPORT_ERROR(TCPIP_API_CHANGEPARAMETER, TCPIP_E_PARAM_POINTER);
    }
    /*SWS_TCPIP_00119*/
#if (TCPIP_TCP_ENABLED == STD_ON)
    else if (SocketId < (TcpIp_SocketIdType)TCPIP_TCP_SOCKET_MAX)
    {
        /*TCP socket*/
        ret = TCPIP_SOCKET_SET_TCPPARAM(SocketId, ParameterId, ParameterValue);
    }
#endif
    else
    {
#if (TCPIP_UDP_ENABLED == STD_ON)
        /*UDP socket*/
        ret = TCPIP_SOCKET_SET_UDPPARAM(SocketId, ParameterId, ParameterValue);
#endif
    }

    return ret;
}

#if (TCPIP_IPV4_ENABLED == STD_ON) 
#if (TCPIP_DHCP_CLIENT_ENABLED == STD_ON)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: TcpIp_DhcpReadOption
*
* Description:   Retrieves DHCP option data identified by parameter option for
*                already received DHCP options.
*
* Inputs:        LocalAddrId    - the local address id
*                Option         - the option id
*                DataLengthPtr  - the max length of the buffer
*
* Outputs:       DataLengthPtr  - the length of the DHCP option data
*                DataPtr        - the buffer of the DHCP option data
*
* Returns:       If the request has been accepted returns E_OK, otherwise returns
*                E_NOT_OK.
*
* Limitations:   Non Reentrant.
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_DhcpReadOption
(
    TcpIp_LocalAddrIdType LocalAddrId,
    /*PRQA S 3206 EOF*/
    uint8 Option,
    P2VAR(uint8, AUTOMATIC, AUTOMATIC) DataLengthPtr,
    P2VAR(uint8, AUTOMATIC, AUTOMATIC) DataPtr
)
{
    P2VAR(TcpIp_LocalAddrType, AUTOMATIC, AUTOMATIC) ctx;
    P2VAR(TcpIp_NetIfCtrlType, AUTOMATIC, AUTOMATIC) netCtrl;
    Std_ReturnType ret = E_NOT_OK;

    if (TCPIP_IS_UNINITIALIZED())
    {
        TCPIP_DET_REPORT_ERROR(TCPIP_API_DHCPREADOPTION, TCPIP_E_NOTINIT);
    }
    /*SWS_TCPIP_00233*/
    else if (!TCPIP_LOCALADDR_IS_VALID_ID(LocalAddrId))
    {
        TCPIP_DET_REPORT_ERROR(TCPIP_API_DHCPREADOPTION, TCPIP_E_INV_ARG);
    }
    else if ((NULL_PTR == DataPtr) || (NULL_PTR == DataLengthPtr))
    {
        TCPIP_DET_REPORT_ERROR(TCPIP_API_DHCPREADOPTION, TCPIP_E_PARAM_POINTER);
    }
    else
    {
        ctx = TCPIP_LOCALADDR_GET_CONTEXT(LocalAddrId);
        netCtrl = TCPIP_NETCTRL_GET_CONTEXT(ctx->CtrlId);
        if (netCtrl->DHCPCtxPtr != NULL_PTR)
        {
            /*SWS_TCPIP_00234*//*SWS_TCPIP_00235*/
            ret = TCPIP_NETCTRL_READ_DHCP_OPTION(netCtrl, Option, DataLengthPtr, DataPtr);
        }
    }

    return ret;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: TcpIp_DhcpWriteOption
*
* Description:   Writes DHCP option data identified by parameter option.
*
* Inputs:        LocalAddrId    - the local address id
*                Option         - the option id
*                DataLength     - the length of DHCP option data
*                DataPtr        - the DHCP option data
*
* Outputs:       None
*
* Returns:       If the request has been accepted returns E_OK, otherwise returns
*                E_NOT_OK.
*
* Limitations:   Non Reentrant.
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_DhcpWriteOption
(
    TcpIp_LocalAddrIdType LocalAddrId,
    /*PRQA S 3206 EOF*/
    uint8 Option,
    uint8 DataLength,
    P2CONST(uint8, AUTOMATIC, AUTOMATIC) DataPtr
)
{
    P2VAR(TcpIp_LocalAddrType, AUTOMATIC, AUTOMATIC) ctx;
    P2VAR(TcpIp_NetIfCtrlType, AUTOMATIC, AUTOMATIC) netCtrl;
    Std_ReturnType ret = E_NOT_OK;

    if (TCPIP_IS_UNINITIALIZED())
    {
        TCPIP_DET_REPORT_ERROR(TCPIP_API_DHCPWRITEOPTION, TCPIP_E_NOTINIT);
    }
    /*SWS_TCPIP_00243*/
    else if (!TCPIP_LOCALADDR_IS_VALID_ID(LocalAddrId))
    {
        TCPIP_DET_REPORT_ERROR(TCPIP_API_DHCPWRITEOPTION, TCPIP_E_INV_ARG);
    }
    else if (NULL_PTR == DataPtr)
    {
        TCPIP_DET_REPORT_ERROR(TCPIP_API_DHCPWRITEOPTION, TCPIP_E_PARAM_POINTER);
    }
    /*SWS_TCPIP_00247*/
    else if (0 == DataLength)
    {
        ret = E_OK;
    }
    else
    {
        ctx = TCPIP_LOCALADDR_GET_CONTEXT(LocalAddrId);
        netCtrl = TCPIP_NETCTRL_GET_CONTEXT(ctx->CtrlId);
        if (netCtrl->DHCPCtxPtr != NULL_PTR)
        {
            /*SWS_TCPIP_00244*//*SWS_TCPIP_00245*/
            ret = TCPIP_NETCTRL_WRITE_DHCP_OPTION(netCtrl, Option, DataLength, DataPtr);
        }
    }

    return ret;
}
#else
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: TcpIp_DhcpReadOption
*
* Description:   Retrieves DHCP option data identified by parameter option for
*                already received DHCP options.
*
* Inputs:        LocalAddrId    - the local address id
*                Option         - the option id
*                DataLengthPtr  - the max length of the buffer
*
* Outputs:       DataLengthPtr  - the length of the DHCP option data
*                DataPtr        - the buffer of the DHCP option data
*
* Returns:       If the request has been accepted returns E_OK, otherwise returns
*                E_NOT_OK.
*
* Limitations:   Non Reentrant.
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_DhcpReadOption
(
    TcpIp_LocalAddrIdType LocalAddrId,
    /*PRQA S 3206 EOF*/
    uint8 Option,
    P2VAR(uint8, AUTOMATIC, AUTOMATIC) DataLengthPtr,
    P2VAR(uint8, AUTOMATIC, AUTOMATIC) DataPtr
)
{
    Std_ReturnType ret = E_NOT_OK;

    if (TCPIP_IS_UNINITIALIZED())
    {
        TCPIP_DET_REPORT_ERROR(TCPIP_API_DHCPREADOPTION, TCPIP_E_NOTINIT);
    }
    /*SWS_TCPIP_00233*/
    else if (!TCPIP_LOCALADDR_IS_VALID_ID(LocalAddrId))
    {
        TCPIP_DET_REPORT_ERROR(TCPIP_API_DHCPREADOPTION, TCPIP_E_INV_ARG);
    }
    else if ((NULL_PTR == DataPtr) || (NULL_PTR == DataLengthPtr))
    {
        TCPIP_DET_REPORT_ERROR(TCPIP_API_DHCPREADOPTION, TCPIP_E_PARAM_POINTER);
    }
    else
    {
        /*do nothing*/
    }

    return ret;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: TcpIp_DhcpWriteOption
*
* Description:   Writes DHCP option data identified by parameter option.
*
* Inputs:        LocalAddrId    - the local address id
*                Option         - the option id
*                DataLength     - the length of DHCP option data
*                DataPtr        - the DHCP option data
*
* Outputs:       None
*
* Returns:       If the request has been accepted returns E_OK, otherwise returns
*                E_NOT_OK.
*
* Limitations:   Non Reentrant.
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_DhcpWriteOption
(
    TcpIp_LocalAddrIdType LocalAddrId,
    /*PRQA S 3206 EOF*/
    uint8 Option,
    uint8 DataLength,
    P2CONST(uint8, AUTOMATIC, AUTOMATIC) DataPtr
)
{
    Std_ReturnType ret = E_NOT_OK;

    if (TCPIP_IS_UNINITIALIZED())
    {
        TCPIP_DET_REPORT_ERROR(TCPIP_API_DHCPWRITEOPTION, TCPIP_E_NOTINIT);
    }
    /*SWS_TCPIP_00243*/
    else if (!TCPIP_LOCALADDR_IS_VALID_ID(LocalAddrId))
    {
        TCPIP_DET_REPORT_ERROR(TCPIP_API_DHCPWRITEOPTION, TCPIP_E_INV_ARG);
    }
    else if (NULL_PTR == DataPtr)
    {
        TCPIP_DET_REPORT_ERROR(TCPIP_API_DHCPWRITEOPTION, TCPIP_E_PARAM_POINTER);
    }
    else 
    {
        /*do nothing*/
    }

    return ret;
}
#endif
#endif

#if (TCPIP_IPV6_ENABLED == STD_ON)

#if (TCPIP_DHCPV6_CLIENT_ENABLED == STD_ON)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: TcpIp_DhcpV6ReadOption
*
* Description:   Retrieves DHCP option data identified by parameter option for
*                already received DHCP options.
*
* Inputs:        LocalAddrId    - the local address id
*                Option         - the option id
*                DataLengthPtr  - the max length of the buffer
*
* Outputs:       DataLengthPtr  - the length of the DHCP option data
*                DataPtr        - the buffer of the DHCP option data
*
* Returns:       If the request has been accepted returns E_OK, otherwise returns
*                E_NOT_OK.
*
* Limitations:   Non Reentrant.
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_DhcpV6ReadOption
(
    TcpIp_LocalAddrIdType LocalAddrId,
    uint16 Option,
    P2VAR(uint16, AUTOMATIC, AUTOMATIC) DataLengthPtr,
    P2VAR(uint8, AUTOMATIC, AUTOMATIC) DataPtr
)
{
    P2VAR(TcpIp_LocalAddrType, AUTOMATIC, AUTOMATIC) ctx;
    P2VAR(TcpIp_NetIfCtrlType, AUTOMATIC, AUTOMATIC) netCtrl;
    Std_ReturnType ret = E_NOT_OK;

    if (TCPIP_IS_UNINITIALIZED())
    {
        TCPIP_DET_REPORT_ERROR(TCPIP_API_DHCPV6READOPTION, TCPIP_E_NOTINIT);
    }
    /*SWS_TCPIP_00238*/
    else if (!TCPIP_LOCALADDR_IS_VALID_ID(LocalAddrId))
    {
        TCPIP_DET_REPORT_ERROR(TCPIP_API_DHCPV6READOPTION, TCPIP_E_INV_ARG);
    }
    else if ((NULL_PTR == DataPtr) || (NULL_PTR == DataLengthPtr))
    {
        TCPIP_DET_REPORT_ERROR(TCPIP_API_DHCPV6READOPTION, TCPIP_E_PARAM_POINTER);
    }
    else
    {
        ctx = TCPIP_LOCALADDR_GET_CONTEXT(LocalAddrId);
        netCtrl = TCPIP_NETCTRL_GET_CONTEXT(ctx->CtrlId);
        if (netCtrl->DHCPV6CtxPtr != NULL_PTR)
        {
            /*SWS_TCPIP_00239*//*SWS_TCPIP_00240*/
            ret = TCPIP_NETCTRL_READ_DHCPV6_OPTION(netCtrl, Option, DataLengthPtr, DataPtr);
        }
    }

    return ret;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: TcpIp_DhcpV6WriteOption
*
* Description:   Writes DHCP option data identified by parameter option.
*
* Inputs:        LocalAddrId    - the local address id
*                Option         - the option id
*                DataLength     - the length of DHCP option data
*                DataPtr        - the DHCP option data
*
* Outputs:       None
*
* Returns:       If the request has been accepted returns E_OK, otherwise returns
*                E_NOT_OK.
*
* Limitations:   Non Reentrant.
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_DhcpV6WriteOption
(
    TcpIp_LocalAddrIdType LocalAddrId,
    uint16 Option,
    uint16 DataLength,
    P2CONST(uint8, AUTOMATIC, AUTOMATIC) DataPtr
)
{
    P2VAR(TcpIp_LocalAddrType, AUTOMATIC, AUTOMATIC) ctx;
    P2VAR(TcpIp_NetIfCtrlType, AUTOMATIC, AUTOMATIC) netCtrl;
    Std_ReturnType ret = E_NOT_OK;

    if (TCPIP_IS_UNINITIALIZED())
    {
        TCPIP_DET_REPORT_ERROR(TCPIP_API_DHCPV6WRITEOPTION, TCPIP_E_NOTINIT);
    }
    /*SWS_TCPIP_00248*/
    else if (!TCPIP_LOCALADDR_IS_VALID_ID(LocalAddrId))
    {
        TCPIP_DET_REPORT_ERROR(TCPIP_API_DHCPV6WRITEOPTION, TCPIP_E_INV_ARG);
    }
    else if (NULL_PTR == DataPtr)
    {
        TCPIP_DET_REPORT_ERROR(TCPIP_API_DHCPV6WRITEOPTION, TCPIP_E_PARAM_POINTER);
    }
    /*SWS_TCPIP_00252*/
    else if (0 == DataLength)
    {
        ret = E_OK;
    }
    else
    {
        ctx = TCPIP_LOCALADDR_GET_CONTEXT(LocalAddrId);
        netCtrl = TCPIP_NETCTRL_GET_CONTEXT(ctx->CtrlId);
        if (netCtrl->DHCPV6CtxPtr != NULL_PTR)
        {
            /*SWS_TCPIP_00249*//*SWS_TCPIP_00250*/
            ret = TCPIP_NETCTRL_WRITE_DHCPV6_OPTION(netCtrl, Option, DataLength, DataPtr);
        }
    }

    return ret;
}
#else
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: TcpIp_DhcpV6ReadOption
*
* Description:   Retrieves DHCP option data identified by parameter option for
*                already received DHCP options.
*
* Inputs:        LocalAddrId    - the local address id
*                Option         - the option id
*                DataLengthPtr  - the max length of the buffer
*
* Outputs:       DataLengthPtr  - the length of the DHCP option data
*                DataPtr        - the buffer of the DHCP option data
*
* Returns:       If the request has been accepted returns E_OK, otherwise returns
*                E_NOT_OK.
*
* Limitations:   Non Reentrant.
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_DhcpV6ReadOption
(
    TcpIp_LocalAddrIdType LocalAddrId,
    uint16 Option,
    P2VAR(uint16, AUTOMATIC, AUTOMATIC) DataLengthPtr,
    P2VAR(uint8, AUTOMATIC, AUTOMATIC) DataPtr
)
{
    Std_ReturnType ret = E_NOT_OK;

    if (TCPIP_IS_UNINITIALIZED())
    {
        TCPIP_DET_REPORT_ERROR(TCPIP_API_DHCPV6READOPTION, TCPIP_E_NOTINIT);
    }
    /*SWS_TCPIP_00238*/
    else if (!TCPIP_LOCALADDR_IS_VALID_ID(LocalAddrId))
    {
        TCPIP_DET_REPORT_ERROR(TCPIP_API_DHCPV6READOPTION, TCPIP_E_INV_ARG);
    }
    else if ((NULL_PTR == DataPtr) || (NULL_PTR == DataLengthPtr))
    {
        TCPIP_DET_REPORT_ERROR(TCPIP_API_DHCPV6READOPTION, TCPIP_E_PARAM_POINTER);
    }
    else
    {
        /*do nothing*/
    }

    return ret;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: TcpIp_DhcpV6WriteOption
*
* Description:   Writes DHCP option data identified by parameter option.
*
* Inputs:        LocalAddrId    - the local address id
*                Option         - the option id
*                DataLength     - the length of DHCP option data
*                DataPtr        - the DHCP option data
*
* Outputs:       None
*
* Returns:       If the request has been accepted returns E_OK, otherwise returns
*                E_NOT_OK.
*
* Limitations:   Non Reentrant.
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_DhcpV6WriteOption
(
    TcpIp_LocalAddrIdType LocalAddrId,
    uint16 Option,
    uint16 DataLength,
    P2CONST(uint8, AUTOMATIC, AUTOMATIC) DataPtr
)
{
    Std_ReturnType ret = E_NOT_OK;

    if (TCPIP_IS_UNINITIALIZED())
    {
        TCPIP_DET_REPORT_ERROR(TCPIP_API_DHCPV6WRITEOPTION, TCPIP_E_NOTINIT);
    }
    /*SWS_TCPIP_00248*/
    else if (!TCPIP_LOCALADDR_IS_VALID_ID(LocalAddrId))
    {
        TCPIP_DET_REPORT_ERROR(TCPIP_API_DHCPV6WRITEOPTION, TCPIP_E_INV_ARG);
    }
    else if (NULL_PTR == DataPtr)
    {
        TCPIP_DET_REPORT_ERROR(TCPIP_API_DHCPV6WRITEOPTION, TCPIP_E_PARAM_POINTER);
    }    
    else 
    {
        /*do nothing*/
    }

    return ret;
}
#endif
#endif

/*SWS_TCPIP_00006*/
#if (TCPIP_VERSION_INFO_API == STD_ON)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: TcpIp_GetVersionInfo
*
* Description:   Gets the version inforation.
*
* Inputs:        None
*
* Outputs:       VersionInfoPtr - the version info
*
* Returns:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, TCPIP_CODE) TcpIp_GetVersionInfo
(
    P2VAR(Std_VersionInfoType, AUTOMATIC, AUTOMATIC) VersionInfoPtr
)
{
    if (VersionInfoPtr != NULL_PTR)
    {
        /*SWS_TCPIP_00005*/
        VersionInfoPtr->vendorID = TCPIP_VENDOR_ID;
        VersionInfoPtr->moduleID = TCPIP_MODULE_ID;
        VersionInfoPtr->sw_major_version = TCPIP_SW_MAJOR_VERSION;
        VersionInfoPtr->sw_minor_version = TCPIP_SW_MINOR_VERSION;
        VersionInfoPtr->sw_patch_version = TCPIP_SW_PATCH_VERSION;
    }
    else
    {
        TCPIP_DET_REPORT_ERROR(TCPIP_API_GETVERSIONINFO, TCPIP_E_PARAM_POINTER);
    }
}


#endif
#define TCPIP_STOP_SEC_CODE
/*PRQA S 862 ++*/
/*#include "MemMap.h" more than once*/
#include "MemMap.h"
/*PRQA S 862 --*/
