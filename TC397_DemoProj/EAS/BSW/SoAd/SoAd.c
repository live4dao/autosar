/*  BEGIN_FILE_HDR
*******************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
*******************************************************************************
*   File Name       : SoAd.c
*******************************************************************************
*   Project/Product : AUTOSAR 4.2
*   Title           : The Socket Adaptor
*   Author          : mingqing.tang
*******************************************************************************
*   Description     : The source file of the SoAd module.
*
*******************************************************************************
*   Limitations     : only used for AUTOSAR 4.2 version
*
*******************************************************************************
*
*******************************************************************************
*   Revision History:
*
*   Version     Date          Initials        CR#          Descriptions
*   ---------   ----------    ------------    ----------   ---------------
*   01.00.00    18/06/2014    mingqing.tang   N/A          Original
*   02.00.00    01/09/2017    mingqing.tang   N/A          Update to R4.2.2
*   02.00.01    25/12/2018    xueyu.zhao      N/A          ETH422_SoAd_20181225_01
*   02.00.02    03/09/2019    beibei.xing     N/A          ETH422_SoAd_20190903_01
*   02.00.03    21/10/2019    beibei.xing     N/A          ETH422_SoAd_20191021_01
*   02.00.04    01/11/2019    beibei.xing     N/A          ETH422_SoAd_20191101_01
*   02.00.05    06/12/2019    hao.liu3        N/A          ETH422_SoAd_20191206_01
*   02.00.06    04/09/2020    beibei.xing     N/A          ETH422_SoAd_20200904_01
*   02.00.07    04/09/2020    zeyu.ren        N/A          ETH422_SoAd_20211211_01
*   02.00.08    12/07/2022    wenbo.cui1      N/A          ETH422_SoAd_20210712_01
*   02.00.09    09/10/2022    zeyu.ren        N/A          Bug fix: tcp send SYN to 0.0.0.0
*   02.00.10    18/01/2023    zeyu.ren        N/A          ETH422_SoAd_20230118_01
*   02.00.11    26/01/2023    zeyu.ren        N/A          ETH422_SoAd_20230126_01
*   02.00.12    26/01/2023    zeyu.ren        N/A          ETH422_SoAd_20230206_01
*   02.00.13    03/04/2023    zeyu.ren        N/A          ETH422_SoAd_20230403_01
*   02.00.15    03/04/2023    zeyu.ren        N/A          ETH422_SoAd_20230420_01
*   02.00.16    08/05/2023    zeyu.ren        N/A          DET bug resolved
*   02.00.17    16/05/2023    zeyu.ren        N/A          ETH422_SoAd_20230516_01
*   02.00.18    03/08/2023    zeyu.ren        N/A          ETH422_SoAd_20230803_01
*   02.00.19    15/08/2023    zeyu.ren        N/A          ETH422_SoAd_20230815
*   02.00.20    01/09/2023    zeyu.ren        N/A          ETH422_SoAd_20230815
*   02.00.21    10/10/2023    yanheng.he      N/A          Bug fix: Receive error in TP mode.
*   02.00.22    02/11/2023    zeyu.ren        N/A          ETH422_SoAd_20231102
*   02.00.23    13/11/2023    zeyu.ren        N/A          ETH422_SoAd_20231113
*   02.00.24    22/11/2023    zeyu.ren        N/A          Bug fix: trigger transmit error
*   02.00.25    11/12/2023    zeyu.ren        N/A          Buffer length no longer need to be the power of 2
*   02.00.26    13/12/2023    zeyu.ren        N/A          Bug fix: ansmit return value error
*******************************************************************************
*   END_FILE_HDR*/


/******************************************************************************
*   Includes
******************************************************************************/
#include "SoAd.h"
#include "SoAd_Cbk.h"
#include "TcpIp.h"
#include "SchM_SoAd.h"
#if (STD_ON == SOAD_DEV_ERROR_DETECT)
#include "Det.h"
#endif

#if (STD_ON == SOAD_PRIVATE_VERSION_CHECK)
/* check Version with other import module */
/* check Version with cfg file */
#if ((SOAD_AR_RELEASE_MAJOR_VERSION != SOAD_AR_RELEASE_MAJOR_VERSION_CFG) || \
   (SOAD_AR_RELEASE_MINOR_VERSION != SOAD_AR_RELEASE_MINOR_VERSION_CFG))
#error "AUTOSAR Version Numbers of SoAd and its cfg file are different"
#endif

#if ((SOAD_SW_MAJOR_VERSION != SOAD_SW_MAJOR_VERSION_CFG) || \
   (SOAD_SW_MINOR_VERSION != SOAD_SW_MINOR_VERSION_CFG))
#error "SW Version Numbers of SoAd and its cfg file are different"
#endif
#endif

/*******************************************************************************
*   Macro
*******************************************************************************/
#define SOAD_USED(arg)                                                  ((void)(arg))

#define SOAD_ENTER_CRITICAL_SECTION_SOCON_MODE_IDX()                    SchM_Enter_SoAd_SOAD_EXCLUSIVE_AREA_0()
#define SOAD_LEAVE_CRITICAL_SECTION_SOCON_MODE_IDX()                    SchM_Exit_SoAd_SOAD_EXCLUSIVE_AREA_0()

#define SOAD_ENTER_CRITICAL_SECTION_SHARED_SOCKET_IDX()                 SchM_Enter_SoAd_SOAD_EXCLUSIVE_AREA_1()
#define SOAD_LEAVE_CRITICAL_SECTION_SHARED_SOCKET_IDX()                 SchM_Exit_SoAd_SOAD_EXCLUSIVE_AREA_1()

#define SOAD_ENTER_CRITICAL_SECTION_TX_UNCONFIRM_IDX()                  SchM_Enter_SoAd_SOAD_EXCLUSIVE_AREA_2()
#define SOAD_LEAVE_CRITICAL_SECTION_TX_UNCONFIRM_IDX()                  SchM_Exit_SoAd_SOAD_EXCLUSIVE_AREA_2()

#define SOAD_ENTER_CRITICAL_SECTION_TX_SESSION_IDX()                    SchM_Enter_SoAd_SOAD_EXCLUSIVE_AREA_3()
#define SOAD_LEAVE_CRITICAL_SECTION_TX_SESSION_IDX()                    SchM_Exit_SoAd_SOAD_EXCLUSIVE_AREA_3()

#define SOAD_ENTER_CRITICAL_SECTION_RX_SESSION_IDX()                    SchM_Enter_SoAd_SOAD_EXCLUSIVE_AREA_4()
#define SOAD_LEAVE_CRITICAL_SECTION_RX_SESSION_IDX()                    SchM_Exit_SoAd_SOAD_EXCLUSIVE_AREA_4()

#define SOAD_ENTER_CRITICAL_SECTION_IFRG_TRANSMIT_IDX()                 SchM_Enter_SoAd_SOAD_EXCLUSIVE_AREA_5()
#define SOAD_LEAVE_CRITICAL_SECTION_IFRG_TRANSMIT_IDX()                 SchM_Exit_SoAd_SOAD_EXCLUSIVE_AREA_5()

#define SOAD_ENTER_CRITICAL_SECTION_ROUTING_GROUP_IDX()                 SchM_Enter_SoAd_SOAD_EXCLUSIVE_AREA_6()
#define SOAD_LEAVE_CRITICAL_SECTION_ROUTING_GROUP_IDX()                 SchM_Exit_SoAd_SOAD_EXCLUSIVE_AREA_6()

#define SOAD_DEBUG(api, msg)  /* Integrate user code */
#if (SOAD_DEV_ERROR_DETECT == STD_ON)
/*SWS_SoAd_00692*/
#define SOAD_DET_REPORT_ERROR(api, err)             {\
                                                        SOAD_DEBUG(api, 'DET Error Reported');\
                                                        DET_REPORT_ERROR(\
                                                        SOAD_MODULE_ID,\
                                                        SOAD_INSTANCE_ID,\
                                                        (api),\
                                                        (err));\
                                                    }

#define SOAD_DET_REPORT_ERROR_RET(api, err, ret)    {\
                                                        SOAD_DEBUG(api, 'DET Error Reported');\
                                                        SOAD_DET_REPORT_ERROR((api), (err));\
                                                        return (ret);\
                                                    }

#else
#define SOAD_DET_REPORT_ERROR(api, err)             SOAD_DEBUG(api, 'DET Error Reported')
#define SOAD_DET_REPORT_ERROR_RET(api, err, ret)    {\
                                                        SOAD_DEBUG(api, 'DET Error Reported');\
                                                        return ret;\
                                                    }
#endif /*SOAD_DEV_ERROR_DETECT == STD_ON*/


#define SOAD_ATOUL(array)                           (((uint32)(((uint8*)(array))[0]) << 24) \
                                                    | ((uint32)(((uint8*)(array))[1]) << 16) \
                                                    | ((uint32)(((uint8*)(array))[2]) <<  8) \
                                                    | ((uint32)(((uint8*)(array))[3]) <<  0))

#define SOAD_ULTOA(ul,array)                        ((((uint8*)(array))[0]) = (uint8)((ul) >> 24)); \
                                                    ((((uint8*)(array))[1]) = (uint8)((ul) >> 16)); \
                                                    ((((uint8*)(array))[2]) = (uint8)((ul) >>  8)); \
                                                    ((((uint8*)(array))[3]) = (uint8)((ul) >>  0))

#define SOAD_MIN_LEN(a, b)                          (((a) < (b))? (a): (b))


#define SOAD_CHECK_UDP_PDUHEADER_LEN(c, b, l)       (!SOAD_SOCON_IS_UDP_CHECK_PDUHEADER_LEN(c)\
                                                    || (SoAd__CheckStrictPduHeaderLen(b, l) == E_OK))

/* The Configurations Operations*/
#define SOAD_GET_SOCONCTX_PTR(idx)                  (&SoAd_Connections[idx])
#define SOAD_GET_UL_INTERFACE(idx)                  (&SoAd_UpLayerInterfaces[idx])

#if (SOAD_CONFIG_VARIANTS != STD_CONFIG_VARIANTS_PRECOMPILE)
#define SOAD_GET_SOCON_GROUP_NUM()                  (SoAd_ConfigPtr->SoConGroupNum)
#define SOAD_GET_SOCON_GROUP_PTR(idx)               (&SoAd_ConfigPtr->SoConGroupList[idx])
#define SOAD_GET_SOCON_NUM()                        (SoAd_ConfigPtr->SoConNum)
#define SOAD_GET_SOCON_PTR(idx)                     (&SoAd_ConfigPtr->SoConList[idx])
#define SOAD_GET_PDUROUTE_NUM()                     (SoAd_ConfigPtr->PduRouteNum)
#define SOAD_GET_PDUROUTE_PTR(idx)                  (&SoAd_ConfigPtr->PduRouteList[idx])
#define SOAD_GET_PDUROUTE_DEST_NUM()                (SoAd_ConfigPtr->PduRouteDestNum)
#define SOAD_GET_PDUROUTE_DEST_PTR(idx)             (&SoAd_ConfigPtr->PduRouteDestList[idx])
#define SOAD_GET_SOCKETROUTE_NUM()                  (SoAd_ConfigPtr->SocketRouteNum)
#define SOAD_GET_SOCKETROUTE_PTR(idx)               (&SoAd_ConfigPtr->SocketRouteList[idx])
#define SOAD_GET_IFTXUNCONFIRMED_PTR(idx)           (&SoAd_ConfigPtr->IfTxUnconfirmList[idx])
#define SOAD_GET_ROUTINGGRP_NUM()                   (SoAd_ConfigPtr->RoutingGroupNum)
#define SOAD_GET_ROUTINGGRP_PTR(idx)                (&SoAd_ConfigPtr->RoutingGroupList[idx])
#define SOAD_GET_IFTRIGGER_BUFFER_LENGTH()          (SoAd_ConfigPtr->IfTriggerBufferLength)
#define SOAD_GET_IFTRIGGER_BUFFER_PTR()             (SoAd_ConfigPtr->Buffer)
#define SOAD_GET_BUFFER_LENGTH()                    (SoAd_ConfigPtr->BufferLength)
#define SOAD_GET_BUFFER_PTR(off)                    (&SoAd_ConfigPtr->Buffer[off])

#define SOAD_GET_LOCAL_IPADDR_STATE(idx)            (SoAd_ConfigPtr->LocalIpStateList[idx])
#define SOAD_SET_LOCAL_IPADDR_STATE(idx, sta)       (SoAd_ConfigPtr->LocalIpStateList[idx] = (sta))
#define SOAD_CLEAR_LOCAL_IPADDR_STATE(idx)          (SoAd_ConfigPtr->LocalIpStateList[idx] = TCPIP_IPADDR_STATE_UNASSIGNED)

#define SOAD_GET_SHARED_SOCKETID(grpId)             (SoAd_ConfigPtr->SharedSocketIdList[grpId])
#define SOAD_SET_SHARED_SOCKETID(grpId, socket)     (SoAd_ConfigPtr->SharedSocketIdList[grpId] = (socket))
#define SOAD_CLEAR_SHARED_SOCKETID(grpId)           (SOAD_SET_SHARED_SOCKETID(grpId, TCPIP_SOCKETID_INVALID))
#else
#define SOAD_GET_SOCON_GROUP_NUM()                  (SOAD_SOCONGROUP_NUM)
#define SOAD_GET_SOCON_GROUP_PTR(idx)               (&SoAd_SoConGroupList[idx])
#define SOAD_GET_SOCON_NUM()                        (SOAD_SOCON_MAX)
#define SOAD_GET_SOCON_PTR(idx)                     (&SoAd_SoConList[idx])
#define SOAD_GET_PDUROUTE_NUM()                     (SOAD_PDU_ROUTE_NUM)
#define SOAD_GET_PDUROUTE_PTR(idx)                  (&SoAd_PduRouteList[idx])
#define SOAD_GET_PDUROUTE_DEST_NUM()                (SOAD_PDU_ROUTE_DEST_NUM)
#define SOAD_GET_PDUROUTE_DEST_PTR(idx)             (&SoAd_PduRouteDestList[idx])
#define SOAD_GET_SOCKETROUTE_NUM()                  (SOAD_SOCKET_ROUTE_NUM)
#define SOAD_GET_SOCKETROUTE_PTR(idx)               (&SoAd_SocketRouteList[idx])
#define SOAD_GET_IFTXUNCONFIRMED_PTR(idx)           (&SoAd_IfTxUnconfirmList[idx])
#define SOAD_GET_ROUTINGGRP_NUM()                   (SOAD_ROUTING_GROUP_NUM)
#define SOAD_GET_ROUTINGGRP_PTR(idx)                (&SoAd_RoutingGroupList[idx])
#define SOAD_GET_IFTRIGGER_BUFFER_LENGTH()          (SOAD_IFTRIGGER_BUFFER_LEN)
#define SOAD_GET_IFTRIGGER_BUFFER_PTR()             (SoAd_Buffer)
#define SOAD_GET_BUFFER_LENGTH()                    (SOAD_BUFFER_LEN)
#define SOAD_GET_BUFFER_PTR(off)                    (&SoAd_Buffer[off])

#define SOAD_GET_SHARED_SOCKETID(grpId)             (SoAd_SharedSocketIdList[grpId])
#define SOAD_SET_SHARED_SOCKETID(grpId, socket)     (SoAd_SharedSocketIdList[grpId] = (socket))
#define SOAD_CLEAR_SHARED_SOCKETID(grpId)           (SOAD_SET_SHARED_SOCKETID(grpId, TCPIP_SOCKETID_INVALID))
#endif

#define SOAD_IS_VALID_SOCKETROUTE(id)               ((id) < SOAD_GET_SOCKETROUTE_NUM())
#define SOAD_IS_VALID_SOCON(id)                     ((id) < SOAD_GET_SOCON_NUM())


/* The Remote Address STATE Operations*/
#define SOAD_RADDR_IS_VALID_STATE(sta)              ((sta) <= SOAD_REMOTE_ADDRESS_UNSET)
#define SOAD_RADDR_IS_VALID_ADDR(sta)               ((sta) < SOAD_REMOTE_ADDRESS_UNSET)
#define SOAD_RADDR_IS_ALL_ANY(sta)                  ((sta) == SOAD_REMOTE_ADDRESS_ALL_ANY)
#define SOAD_RADDR_IS_IP_ANY(sta)                   (((sta) & SOAD_REMOTE_ADDRESS_IP_SET) == 0)
#define SOAD_RADDR_IS_IP_SET(sta)                   (((sta) & SOAD_REMOTE_ADDRESS_IP_SET) > 0)
#define SOAD_RADDR_IS_PORT_ANY(sta)                 (((sta) & SOAD_REMOTE_ADDRESS_PORT_SET) == 0)
#define SOAD_RADDR_IS_PORT_SET(sta)                 (((sta) & SOAD_REMOTE_ADDRESS_PORT_SET) > 0)
#define SOAD_RADDR_IS_IP_AND_PORT(sta)              ((sta) == SOAD_REMOTE_ADDRESS_SET)

#define SOAD_RADDR_UNSET(sta)                       ((sta) = SOAD_REMOTE_ADDRESS_UNSET)
#define SOAD_RADDR_SET_IP(sta)                      ((sta) |= SOAD_REMOTE_ADDRESS_IP_SET)
#define SOAD_RADDR_SET_PORT(sta)                    ((sta) |= SOAD_REMOTE_ADDRESS_PORT_SET)
#define SOAD_RADDR_SET_ALL(sta)                     ((sta) = SOAD_REMOTE_ADDRESS_SET)
#define SOAD_RADDR_ANY_ALL(sta)                     ((sta) = SOAD_REMOTE_ADDRESS_ALL_ANY)

#define SOAD_RADDR_IS_MATCHED_PORT(src, remote)     ((src)->Port == (remote)->Port)

#define SOAD_RADDR_SET_DEFAULT_ADDRESS(conn)        SoAd__SetRemoteAddress(conn,\
                                                    &((conn)->ConfigPtr->RemoteAddr),\
                                                    (conn)->ConfigPtr->RemoteAddrState)

#define SOAD_BMA_MATCH_LEVEL_MIN                    (0)
#define SOAD_BMA_MATCH_LEVEL_1                      (1)
#define SOAD_BMA_MATCH_LEVEL_2                      (2)
#define SOAD_BMA_MATCH_LEVEL_3                      (4)
#define SOAD_BMA_MATCH_LEVEL_MAX                    (6)


#define SOAD_IFTX_RESULT_OK                         (1)
#define SOAD_IFTX_RESULT_DISABLED_ROUTING           (2)
#define SOAD_IFTX_RESULT_NOT_OK                     (4)

#define SOAD_IFTX_GET_UNCONFIRMED(p)                ((uint16)*(p))
#define SOAD_IFTX_CLEAR_UNCONFIRMED(p)              (*(p) = 0)
#define SOAD_IFTX_INCREASE_UNCONFIRMED(p, l)        (*(p) += (l))
#define SOAD_IFTX_DECREASE_UNCONFIRMED(p, l)        (*(p) -= (l))
#define SOAD_IFTX_IS_VALID_UNCONFIRMED(p, l)        (*(p) <= (l))

#define SOAD_IFTX_IS_VALID_UDPTIMER(val)            ((val) < SOAD_IFTX_UDPTXTIMER_DEFAULT_VALUE)

#define SOAD_IFTX_STOP_UDPTIMER(session)            ((session)->Timer = SOAD_IFTX_UDPTXTIMER_DEFAULT_VALUE)
#define SOAD_IFTX_START_UDPTIMER(session,val)       ((session)->Timer = (SoAd_IfTxTimerType)(val))
#define SOAD_IFTX_DECREASE_UDPTIMER(session)        ((session)->Timer -= SOAD_MAIN_FUNCTION_PERIOD)
#define SOAD_IFTX_IS_STARTED_UDPTIMER(session)      SOAD_IFTX_IS_VALID_UDPTIMER((session)->Timer)
#define SOAD_IFTX_IS_STOPED_UDPTIMER(session)       !SOAD_IFTX_IS_VALID_UDPTIMER((session)->Timer)
#define SOAD_IFTX_IS_UDPTIMEDOUT(session)           ((session)->Timer == 0) /* cp_692(2) */


#define SOAD_IFRX_GET_BUFFER(conn)                  (&(conn)->RxSession.IfBuffer)
#define SOAD_IFRX_GET_BUFFER_PTR(buf)               ((buf)->BufferPtr)
#define SOAD_IFRX_CLEAR_BUFFER(buf)                 ((buf)->UsedLength = 0)
#define SOAD_IFRX_IS_VALID_LENGTH(buf, len)         (((buf)->UsedLength + (len)) < (buf)->TotalLength)

#define SOAD_TPRX_GET_BUFFER(conn)                  (&(conn)->RxSession.TpBuffer)
#define SOAD_TPRX_GET_USED_LENGTH(buf)              ((uint16)((buf)->In - (buf)->Out))
#define SOAD_TPRX_GET_UNUSED_LENGTH(buf)            ((uint16)((buf)->TotalLength - SOAD_TPRX_GET_USED_LENGTH(buf)))



/* The CtrlFlag Operations*/
#define SOAD_IS_VALID_MASK(val, mask)                       (((val) & (mask)) > 0)

/* The RoutingGroup Operations*/
#define SOAD_ROUTINGGRP_IS_TRIGGERABLE(grp)                 SOAD_IS_VALID_MASK((grp)->CtrlFlag, SOAD_ROUTING_GROUP_TRIGGERABLE)
#define SOAD_ROUTINGGRP_IS_INIT_ENABLED(grp)                SOAD_IS_VALID_MASK((grp)->CtrlFlag, SOAD_ROUTING_GROUP_INIT_ENABLED)

/* The SocketRoute Operations*/
#define SOAD_SOCKETROUTE_IS_IF(route)                       ((route)->ULType == SOAD_UL_TYPE_IF)
#define SOAD_SOCKETROUTE_IS_TP(route)                       ((route)->ULType == SOAD_UL_TYPE_TP)

#define SOAD_SOCKETROUTE_IS_VALID_SOCONID(route, id)        (((route)->SoConId <= (id)) \
                                                                && ((id) < ((route)->SoConId + (route)->SoConNum)))
#define SOAD_SOCKETROUTE_GET_ROUTING_IDX(route, id)         ((id) - (route)->SoConId)
#define SOAD_SOCKETROUTE_GET_ROUTING_PTR(route, idx)        (&((route)->RoutingCtrlList[idx]))

/* The PduRoute Operations*/
#define SOAD_PDUROUTE_IS_IF(route)                          ((route)->ULType == SOAD_UL_TYPE_IF)
#define SOAD_PDUROUTE_IS_TP(route)                          ((route)->ULType == SOAD_UL_TYPE_TP)

#define SOAD_PDUROUTE_IS_PDUHEADER_ENABLED(route)           SOAD_IS_VALID_MASK((route)->CtrlFlag, SOAD_PDUROUTE_PDUHEADER_ENABLED)
#define SOAD_PDUROUTE_IS_FANOUT(route)                      SOAD_IS_VALID_MASK((route)->CtrlFlag, SOAD_PDUROUTE_FANOUT)

#define SOAD_PDUROUTE_IS_VALID_SOCONID(dest, id)            (((dest)->SoConId <= (id)) \
                                                                && ((id) < ((dest)->SoConId + (dest)->SoConNum)))
#define SOAD_PDUROUTE_GET_ROUTING_IDX(dest, id)             ((id) - (dest)->SoConId)
#define SOAD_PDUROUTE_GET_ROUTING_PTR(dest, idx)            (&((dest)->RoutingCtrlList[idx]))

#define SOAD_PDUROUTE_IS_IFTRIGGER_REQUEST(dest, idx)       (((dest)->IfTriggerList[idx]) == SOAD_IFTRIGGER_REQUEST)
#define SOAD_PDUROUTE_SET_IFTRIGGER_REQUEST(dest, idx)      (((dest)->IfTriggerList[idx]) = SOAD_IFTRIGGER_REQUEST)
#define SOAD_PDUROUTE_CLEAR_IFTRIGGER_REQUEST(dest,idx)     (((dest)->IfTriggerList[idx]) = 0)

/* The Socket Connection Group Operations*/
#define SOAD_SOCONGRP_IS_AUTOSETUP(grp)                     SOAD_IS_VALID_MASK((grp)->CtrlFlag, SOAD_SOCONGRP_AUTOSETUP)
#define SOAD_SOCONGRP_IS_PDUHEADER_ENABLED(grp)             SOAD_IS_VALID_MASK((grp)->CtrlFlag, SOAD_SOCONGRP_PDUHEADER_ENABLED)
#define SOAD_SOCONGRP_IS_MAF_ENABLED(grp)                   SOAD_IS_VALID_MASK((grp)->CtrlFlag, SOAD_SOCONGRP_MAF_ENABLED)
#define SOAD_SOCONGRP_IS_ADDR_ASSIGNMENT_CHG(grp)           SOAD_IS_VALID_MASK((grp)->CtrlFlag, SOAD_SOCONGRP_ADDR_ASSIGNMENT_CHG)
#define SOAD_SOCONGRP_IS_SOCON_MODE_CHG(grp)                SOAD_IS_VALID_MASK((grp)->CtrlFlag, SOAD_SOCONGRP_MODE_CHG)
#define SOAD_SOCONGRP_IS_UDP(grp)                           SOAD_IS_VALID_MASK((grp)->CtrlFlag, SOAD_SOCONGRP_UDP)
#define SOAD_SOCONGRP_IS_TCP(grp)                           !SOAD_IS_VALID_MASK((grp)->CtrlFlag, SOAD_SOCONGRP_UDP)
#define SOAD_SOCONGRP_IS_TCP_IMMEDIATE_TPTXCONFIRM(grp)     SOAD_IS_VALID_MASK((grp)->TcpProtocolPtr->CtrlFlag, SOAD_SOCONGRP_TCP_IMMEDIATE_TPTXCONFIRM)
#define SOAD_SOCONGRP_IS_TCP_CLIENT(grp)                    SOAD_IS_VALID_MASK((grp)->TcpProtocolPtr->CtrlFlag, SOAD_SOCONGRP_TCP_INITIATE)
#define SOAD_SOCONGRP_IS_TCP_SERVER(grp)                    !SOAD_IS_VALID_MASK((grp)->TcpProtocolPtr->CtrlFlag, SOAD_SOCONGRP_TCP_INITIATE)
#define SOAD_SOCONGRP_IS_TCP_NO_DELAY(grp)                  SOAD_IS_VALID_MASK((grp)->TcpProtocolPtr->CtrlFlag, SOAD_SOCONGRP_TCP_NO_DELAY)
#define SOAD_SOCONGRP_IS_TCP_KEEY_ALIVE(grp)                SOAD_IS_VALID_MASK((grp)->TcpProtocolPtr->CtrlFlag, SOAD_SOCONGRP_TCP_KEEP_ALIVE)
#define SOAD_SOCONGRP_IS_UDP_LISTEN_ONLY(grp)               SOAD_IS_VALID_MASK((grp)->UdpProtocolPtr->CtrlFlag, SOAD_SOCONGRP_UDP_LISTEN_ONLY)
#define SOAD_SOCONGRP_IS_UDP_CHECK_PDUHEADER_LEN(grp)       SOAD_IS_VALID_MASK((grp)->UdpProtocolPtr->CtrlFlag, SOAD_SOCONGRP_UDP_CHECK_PDUHEADER_LEN)

#define SOAD_SOCONGRP_SET_SOCKETID(grp, socket)             SOAD_SET_SHARED_SOCKETID((grp)->GroupId, socket)
#define SOAD_SOCONGRP_GET_SOCKETID(grp)                     SOAD_GET_SHARED_SOCKETID((grp)->GroupId)
#define SOAD_SOCONGRP_CLEAR_SOCKETID(grp)                   SOAD_CLEAR_SHARED_SOCKETID((grp)->GroupId)

#define SOAD_SOCONGRP_GET_IPADDRASSIGNMENTCHG_PTR(grp)      ((grp)->IpAddrAssignChgList)
/* The Socket Connection Operations*/
#define SOAD_SOCON_IS_AUTOSETUP(conn)               SOAD_SOCONGRP_IS_AUTOSETUP((conn)->GroupConfigPtr)
#define SOAD_SOCON_IS_PDUHEADER_ENABLED(conn)       SOAD_SOCONGRP_IS_PDUHEADER_ENABLED((conn)->GroupConfigPtr)
#define SOAD_SOCON_IS_MAF_ENABLED(conn)             SOAD_SOCONGRP_IS_MAF_ENABLED((conn)->GroupConfigPtr)

#define SOAD_SOCON_IS_TCP(conn)                     SOAD_SOCONGRP_IS_TCP((conn)->GroupConfigPtr)
#define SOAD_SOCON_IS_TCP_SERVER(conn)              SOAD_SOCONGRP_IS_TCP_SERVER((conn)->GroupConfigPtr)
#define SOAD_SOCON_IS_TCP_IMMTPTXCONFIRM(conn)      SOAD_SOCONGRP_IS_TCP_IMMEDIATE_TPTXCONFIRM((conn)->GroupConfigPtr)
#define SOAD_SOCON_IS_UDP(conn)                     SOAD_SOCONGRP_IS_UDP((conn)->GroupConfigPtr)
#define SOAD_SOCON_IS_UDP_LISTEN_ONLY(conn)         SOAD_SOCONGRP_IS_UDP_LISTEN_ONLY((conn)->GroupConfigPtr)
#define SOAD_SOCON_IS_SOCON_MODE_CHG(conn)          SOAD_SOCONGRP_IS_SOCON_MODE_CHG((conn)->GroupConfigPtr)
#define SOAD_SOCON_IS_UDP_CHECK_PDUHEADER_LEN(conn) SOAD_SOCONGRP_IS_UDP_CHECK_PDUHEADER_LEN((conn)->GroupConfigPtr)

#define SOAD_SOCON_SET_OPEN_REQUEST(conn)           ((conn)->ModeRequest |= SOAD_SOCON_REQUEST_OPEN)
#define SOAD_SOCON_SET_CLOSE_REQUEST(conn)          ((conn)->ModeRequest = SOAD_SOCON_REQUEST_CLOSE)
#define SOAD_SOCON_SET_CLOSE_EVENT(conn)            ((conn)->ModeRequest |= SOAD_SOCON_REQUEST_CLOSE_EVENT)
#define SOAD_SOCON_CLEAR_REQUEST(conn)              ((conn)->ModeRequest = 0)
#define SOAD_SOCON_CLEAR_CLOSE(conn)                ((conn)->ModeRequest &= ~SOAD_SOCON_REQUEST_CLOSE_ALL)
#define SOAD_SOCON_CLEAR_OPEN(conn)                 ((conn)->ModeRequest &= ~SOAD_SOCON_REQUEST_OPEN)

#define SOAD_SOCON_IS_OPEN_REQUEST(conn)            (((conn)->ModeRequest & SOAD_SOCON_REQUEST_OPEN) > 0)
#define SOAD_SOCON_IS_CLOSE(conn)                   (((conn)->ModeRequest & SOAD_SOCON_REQUEST_CLOSE_ALL) > 0)
#define SOAD_SOCON_IS_CLOSE_REQUEST(conn)           (((conn)->ModeRequest & SOAD_SOCON_REQUEST_CLOSE) > 0)
#define SOAD_SOCON_IS_CLOSE_EVENT(conn)             (((conn)->ModeRequest & SOAD_SOCON_REQUEST_CLOSE_EVENT) > 0)

#define SOAD_SOCON_SET_CLOSE_ABORT(conn, abort)     ((conn)->Abort = (abort))

#define SOAD_SOCON_SET_MODE(conn, mode)             ((conn)->Mode = (mode))
#define SOAD_SOCON_SET_OFFLINE(conn)                SOAD_SOCON_SET_MODE(conn, SOAD_SOCON_OFFLINE)
#define SOAD_SOCON_SET_RECONN(conn)                 SOAD_SOCON_SET_MODE(conn, SOAD_SOCON_RECONN)
#define SOAD_SOCON_SET_ONLINE(conn)                 SOAD_SOCON_SET_MODE(conn, SOAD_SOCON_ONLINE)

#define SOAD_SOCON_IS_MODE(conn, mode)              ((conn)->Mode == (mode))
#define SOAD_SOCON_IS_OFFLINE(conn)                 SOAD_SOCON_IS_MODE(conn, SOAD_SOCON_OFFLINE)
#define SOAD_SOCON_IS_RECONN(conn)                  SOAD_SOCON_IS_MODE(conn, SOAD_SOCON_RECONN)
#define SOAD_SOCON_IS_ONLINE(conn)                  SOAD_SOCON_IS_MODE(conn, SOAD_SOCON_ONLINE)

#define SOAD_SOCON_SET_RADDR_STATE(conn, val)       ((conn)->RemoteAddrState = (val))
#define SOAD_SOCON_SET_SOCKETID(conn, socket)       ((conn)->SocketId = (socket))
#define SOAD_SOCON_CLEAR_SOCKETID(conn)             ((conn)->SocketId = TCPIP_SOCKETID_INVALID)
#define SOAD_SOCON_IS_VALID_SOCKETID(conn)          ((conn)->SocketId < TCPIP_SOCKETID_INVALID)

#define SOAD_SOCON_IS_SHARED_SOCKET(conn)           ((conn)->GroupConfigPtr->SoConNum > 1)

#define SOAD_SOCON_IS_ASSIGNED_IPADDR(conn)         (SOAD_GET_LOCAL_IPADDR_STATE((conn)->GroupConfigPtr->LocalAddrId)\
                                                                                    == TCPIP_IPADDR_STATE_ASSIGNED)
#define SOAD_SOCON_GET_SOCONMODECHG_PTR(conn)       ((conn)->ConfigPtr->SoConModeChgList)

/* The operations for configuriations of socket conneciton.*/
#define SOAD_SOCON_GET_PDUROUTE_NUM(conn)           ((conn)->ConfigPtr->PduRouteNum)
#define SOAD_SOCON_GET_PDUROUTEDEST_NUM(conn)       ((conn)->ConfigPtr->PduRouteDestNum)
#define SOAD_SOCON_GET_SOCKETROUTE_NUM(conn)        ((conn)->ConfigPtr->SocketRouteNum)
#define SOAD_SOCON_GET_PDUROUTE_ID(conn,idx)        ((conn)->ConfigPtr->PduRouteList[idx])
#define SOAD_SOCON_GET_PDUROUTEDEST_ID(conn,idx)    ((conn)->ConfigPtr->PduRouteDestList[idx])
#define SOAD_SOCON_GET_SOCKETROUTE_ID(conn,idx)     ((conn)->ConfigPtr->SocketRouteList[idx])


#define SOAD_SESSION_SET_STATE(sess, sta)           ((sess)->State = (sta))
#define SOAD_SESSION_IS_STATE(sess, sta)            ((sess)->State == (sta))

#define SOAD_SESSION_SET_IDLE(sess)                 SOAD_SESSION_SET_STATE(sess, SOAD_SESSION_STATE_IDLE)
#define SOAD_SESSION_SET_IF(sess)                   SOAD_SESSION_SET_STATE(sess, SOAD_SESSION_STATE_IF)
#define SOAD_SESSION_SET_TRIGGER(sess)              SOAD_SESSION_SET_STATE(sess, SOAD_SESSION_STATE_TRIGGER)
#define SOAD_SESSION_SET_TP(sess)                   SOAD_SESSION_SET_STATE(sess, SOAD_SESSION_STATE_TP)
#define SOAD_SESSION_SET_TP_CANCELLED(sess)         SOAD_SESSION_SET_STATE(sess, SOAD_SESSION_STATE_TP_CANCELLED)

#define SOAD_SESSION_IS_IDLE(sess)                  SOAD_SESSION_IS_STATE(sess, SOAD_SESSION_STATE_IDLE)
#define SOAD_SESSION_IS_IF(sess)                    SOAD_SESSION_IS_STATE(sess, SOAD_SESSION_STATE_IF)
#define SOAD_SESSION_IS_TRIGGER(sess)               SOAD_SESSION_IS_STATE(sess, SOAD_SESSION_STATE_TRIGGER)
#define SOAD_SESSION_IS_TP(sess)                    SOAD_SESSION_IS_STATE(sess, SOAD_SESSION_STATE_TP)
#define SOAD_SESSION_IS_TP_CANCELLED(sess)          SOAD_SESSION_IS_STATE(sess, SOAD_SESSION_STATE_TP_CANCELLED)

#define SOAD_SESSION_GET_SOCKET_ROUTE(sess)         ((sess)->SocketRoutePtr)
#define SOAD_SESSION_GET_PDU_ROUTE(sess)            ((sess)->PduRoutePtr)


/******************************************************************************
*   Local Function Declaration
******************************************************************************/
STATIC FUNC(void, SOAD_CODE) SoAd__InitConnection
(
    SoAd_SoConIdType SoConId,
    P2CONST(SoAd_SocketConnectionGroupType, AUTOMATIC, AUTOMATIC) GroupPtr,
    P2CONST(SoAd_SocketConnectionType, AUTOMATIC, AUTOMATIC) SoConPtr
);

/* The function used for remote address*/
STATIC FUNC(void, SOAD_CODE) SoAd__SetRemoteAddress
(
    P2VAR(SoAd_ConnectionType, AUTOMATIC, AUTOMATIC) ConnPtr,
    P2CONST(SoAd_RemoteAddressType, AUTOMATIC, AUTOMATIC) SrcAddrPtr,
    uint8 SrcAddrState
);

STATIC FUNC(void, SOAD_CODE) SoAd__UpdateConnRemoteAddress
(
    P2VAR(SoAd_ConnectionType, AUTOMATIC, AUTOMATIC) ConnPtr,
    P2CONST(SoAd_RemoteAddressType, AUTOMATIC, AUTOMATIC) RemoteAddrPtr,
    uint8 AddrState
);

STATIC FUNC(void, SOAD_CODE) SoAd__CopyRemoteAddress
(
    P2VAR(SoAd_RemoteAddressType, AUTOMATIC, AUTOMATIC) DestAddrPtr,
    P2CONST(SoAd_RemoteAddressType, AUTOMATIC, AUTOMATIC) SrcAddrPtr
);

STATIC FUNC(uint8, SOAD_CODE) SoAd__CheckRemoteAddressState
(
    P2CONST(SoAd_RemoteAddressType, AUTOMATIC, AUTOMATIC) RemoteAddrPtr
);

STATIC FUNC(Std_ReturnType, SOAD_CODE) SoAd__IsSpecificIpAddress
(
    P2CONST(SoAd_RemoteAddressType, AUTOMATIC, AUTOMATIC) RemoteAddrPtr
);

STATIC FUNC(Std_ReturnType, SOAD_CODE) SoAd__IsMatchedIpAddress
(
    P2CONST(SoAd_RemoteAddressType, AUTOMATIC, AUTOMATIC) SrcAddrPtr,
    P2CONST(SoAd_RemoteAddressType, AUTOMATIC, AUTOMATIC) RemoteAddrPtr
);

/* The function used for socket connection*/
STATIC FUNC(void, SOAD_CODE) SoAd__OpenSoCon
(
    P2VAR(SoAd_ConnectionType, AUTOMATIC, AUTOMATIC) ConnPtr
);

STATIC FUNC(void, SOAD_CODE) SoAd__CloseSoCon
(
    P2VAR(SoAd_ConnectionType, AUTOMATIC, AUTOMATIC) ConnPtr,
    boolean Offline
);

STATIC FUNC(void, SOAD_CODE) SoAd__SoConModeChg
(
    P2VAR(SoAd_ConnectionType, AUTOMATIC, AUTOMATIC) ConnPtr,
    SoAd_SoConModeType Mode
);

STATIC FUNC(void, SOAD_CODE) SoAd__LocalIpAddrAssignmentChg
(
    P2CONST(SoAd_SocketConnectionGroupType, AUTOMATIC, AUTOMATIC) GroupPtr,
    TcpIp_IpAddrStateType State
);

STATIC FUNC(Std_ReturnType, SOAD_CODE) SoAd__IsAllSoConOffline
(
    P2CONST(SoAd_SocketConnectionGroupType, SOAD_CONFIG_DATA, AUTOMATIC) SoConGroupPtr
);

STATIC FUNC(void, SOAD_CODE) SoAd__CloseSoConGroupSocketId
(
    P2CONST(SoAd_SocketConnectionGroupType, SOAD_CONFIG_DATA, AUTOMATIC) SoConGroupPtr
);

STATIC FUNC(void, SOAD_CODE) SoAd__CloseUdpSoConGroup
(
    P2CONST(SoAd_SocketConnectionGroupType, SOAD_CONFIG_DATA, AUTOMATIC) SoConGroupPtr
);

STATIC FUNC(TcpIp_SocketIdType, SOAD_CODE) SoAd__GetSocket
(
    P2VAR(SoAd_ConnectionType, AUTOMATIC, AUTOMATIC) ConnPtr
);

STATIC FUNC(Std_ReturnType, SOAD_CODE) SoAd__StartTpReceptionWithoutPduHeader
(
    P2VAR(SoAd_ConnectionType, AUTOMATIC, AUTOMATIC) ConnPtr
);

STATIC FUNC(Std_ReturnType, SOAD_CODE) SoAd__FindSoConGroupBySocketId
(
    TcpIp_SocketIdType SocketId,
    P2VAR(SoAd_SoConGroupIdType, AUTOMATIC, AUTOMATIC) SoConGroupIdPtr
);

STATIC FUNC(Std_ReturnType, SOAD_CODE) SoAd__FindConnBySocketId
(
    TcpIp_SocketIdType SocketId,
    P2VAR(SoAd_SoConIdType, AUTOMATIC, AUTOMATIC) SoConIdPtr
);

STATIC FUNC(Std_ReturnType, SOAD_CODE) SoAd__FindConnByRemoteAddr
(
    P2CONST(SoAd_SocketConnectionGroupType, SOAD_CONFIG_DATA, AUTOMATIC) SoConGroupPtr,
    P2CONST(SoAd_RemoteAddressType, AUTOMATIC, AUTOMATIC) RemoteAddrPtr,
    P2VAR(SoAd_SoConIdType, AUTOMATIC, AUTOMATIC) SoConIdPtr
);

STATIC FUNC(uint8, SOAD_CODE) SoAd__BestMatchAlgorithm
(
    P2VAR(SoAd_ConnectionType, SOAD_CONFIG_DATA, AUTOMATIC) ConnPtr,
    P2CONST(SoAd_RemoteAddressType, AUTOMATIC, AUTOMATIC) RemoteAddrPtr
);

STATIC FUNC(void, SOAD_CODE) SoAd__SetRoutingGroup
(
    SoAd_RoutingGroupIdType GroupId,
    uint8 state
);

STATIC FUNC(void, SOAD_CODE) SoAd__SetSpecificRoutingGroup
(
    SoAd_RoutingGroupIdType GroupId,
    SoAd_SoConIdType SoConId,
    uint8 state
);

STATIC FUNC(void, SOAD_CODE) SoAd__TpTxProcess
(
    P2VAR(SoAd_ConnectionType, AUTOMATIC, AUTOMATIC) ConnPtr
);

STATIC FUNC(void, SOAD_CODE) SoAd__IfTriggerTransmitProcess
(
    P2CONST(SoAd_PduRouteType, SOAD_CONFIG_DATA, AUTOMATIC) RoutePtr
);

STATIC FUNC(uint16, SOAD_CODE) SoAd__IfTransmit
(
    P2VAR(SoAd_ConnectionType, AUTOMATIC, AUTOMATIC) ConnPtr,
    P2CONST(SoAd_PduRouteType, SOAD_CONFIG_DATA, AUTOMATIC) RoutePtr,
    P2CONST(SoAd_PduRouteDestType, SOAD_CONFIG_DATA, AUTOMATIC) DestPtr,
    P2CONST(PduInfoType, AUTOMATIC, AUTOMATIC) PduInfoPtr
);

STATIC FUNC(void, SOAD_CODE) SoAd__StartIfUdpTxTimer
(
    P2VAR(SoAd_ConnectionType, AUTOMATIC, AUTOMATIC) ConnPtr,
    SoAd_IfTxTimerType Timeout
);

STATIC FUNC(void, SOAD_CODE) SoAd__InitTxSession
(
    P2VAR(SoAd_ConnectionType, AUTOMATIC, AUTOMATIC) ConnPtr
);

STATIC FUNC(void, SOAD_CODE) SoAd__ClearTxSession
(
    P2VAR(SoAd_TxSessionType, AUTOMATIC, AUTOMATIC) SessionPtr
);

STATIC FUNC(Std_ReturnType, SOAD_CODE) SoAd__StartTxSession
(
    P2VAR(SoAd_ConnectionType, AUTOMATIC, AUTOMATIC) ConnPtr,
    uint8 State
);

STATIC FUNC(Std_ReturnType, SOAD_CODE) SoAd__StopTxSession
(
    P2VAR(SoAd_ConnectionType, AUTOMATIC, AUTOMATIC) ConnPtr
);

STATIC FUNC(Std_ReturnType, SOAD_CODE) SoAd__CancelTxSession
(
    P2VAR(SoAd_ConnectionType, AUTOMATIC, AUTOMATIC) ConnPtr
);

STATIC FUNC(void, SOAD_CODE) SoAd__DisactiveTxSession
(
    P2VAR(SoAd_ConnectionType, AUTOMATIC, AUTOMATIC) ConnPtr
);

STATIC FUNC(Std_ReturnType, SOAD_CODE) SoAd__IsTxSession
(
    P2VAR(SoAd_ConnectionType, AUTOMATIC, AUTOMATIC) ConnPtr,
    uint8 State
);

STATIC FUNC(void, SOAD_CODE) SoAd__CopyData
(
    P2VAR(uint8, AUTOMATIC, AUTOMATIC) DestPtr,
    P2CONST(uint8, AUTOMATIC, AUTOMATIC) SrcPtr,
    uint16 Length
);

STATIC FUNC(void, SOAD_CODE) SoAd__CopyIfTxData
(
    P2VAR(SoAd_TxSessionType, AUTOMATIC, AUTOMATIC) TxSessionPtr,
    uint16 Length,
    P2VAR(uint8, AUTOMATIC, AUTOMATIC) BufferPtr,
    boolean WithHeader
);

STATIC FUNC(Std_ReturnType, SOAD_CODE) SoAd__CopyUdpTpTxData
(
    P2VAR(SoAd_TxSessionType, AUTOMATIC, AUTOMATIC) TxSessionPtr,
    P2CONST(SoAd_PduRouteType, SOAD_CONFIG_DATA, AUTOMATIC) PduRoutePtr,
    uint16 Length
);

STATIC FUNC(Std_ReturnType, SOAD_CODE) SoAd__StartTpReception
(
    P2VAR(SoAd_ConnectionType, AUTOMATIC, AUTOMATIC) ConnPtr,
    P2CONST(SoAd_SocketRouteType, SOAD_CONFIG_DATA, AUTOMATIC) SocketRoutePtr,
    PduLengthType SduLength,
    P2VAR(PduLengthType, AUTOMATIC, AUTOMATIC) BufferSizePtr
);

STATIC FUNC(void, SOAD_CODE) SoAd__TpRxProcess
(
    P2VAR(SoAd_ConnectionType, AUTOMATIC, AUTOMATIC) ConnPtr
);

STATIC FUNC(Std_ReturnType, SOAD_CODE) SoAd__UdpRxIndication
(
    P2VAR(SoAd_ConnectionType, AUTOMATIC, AUTOMATIC) ConnPtr,
    P2VAR(uint8, AUTOMATIC, SOAD_APPL_DATA) DataPtr,
    uint16 DataLength
);

STATIC FUNC(uint16, SOAD_CODE) SoAd__TcpRxIndication
(
    P2VAR(SoAd_ConnectionType, AUTOMATIC, AUTOMATIC) ConnPtr,
    P2VAR(uint8, AUTOMATIC, SOAD_APPL_DATA) DataPtr,
    uint16 DataLength
);

STATIC FUNC(Std_ReturnType, SOAD_CODE) SoAd__TpWithHeaderRxIndication
(
    P2VAR(SoAd_ConnectionType, AUTOMATIC, AUTOMATIC) ConnPtr,
    P2CONST(SoAd_SocketRouteType, SOAD_CONFIG_DATA, AUTOMATIC) SocketRoutePtr,
    P2CONST(PduInfoType, AUTOMATIC, AUTOMATIC) PduInfoPtr,
    P2CONST(SoAd_PduHeaderType, AUTOMATIC, AUTOMATIC) PduHeaderPtr,
    P2VAR(uint16, AUTOMATIC, AUTOMATIC) CachedLength
);

STATIC FUNC(Std_ReturnType, SOAD_CODE) SoAd__TpRxIndication
(
    P2VAR(SoAd_ConnectionType, AUTOMATIC, AUTOMATIC) ConnPtr,
    P2CONST(SoAd_SocketRouteType, SOAD_CONFIG_DATA, AUTOMATIC) SocketRoutePtr,
    P2CONST(PduInfoType, AUTOMATIC, AUTOMATIC) PduInfoPtr,
    P2VAR(uint16, AUTOMATIC, AUTOMATIC) CachedLength
);

STATIC FUNC(Std_ReturnType, SOAD_CODE) SoAd__CheckStrictPduHeaderLen
(
    P2CONST(uint8, AUTOMATIC, AUTOMATIC) DataPtr,
    uint16 DataLength
);

STATIC FUNC(void, SOAD_CODE) SoAd__SerializePduHeader
(
    uint32 PduHeaderId,
    uint32 PduHeaderLength,
    P2VAR(uint8, AUTOMATIC, AUTOMATIC) DataPtr
);

STATIC FUNC(void, SOAD_CODE) SoAd__MakePduHeader
(
    P2CONST(uint8, AUTOMATIC, AUTOMATIC) DataPtr,
    P2VAR(SoAd_PduHeaderType, AUTOMATIC, AUTOMATIC) PduHeaderPtr
);

STATIC FUNC(uint8, SOAD_CODE) SoAd__TcpMakePduHeader
(
    P2VAR(SoAd_ConnectionType, AUTOMATIC, AUTOMATIC) ConnPtr,
    P2CONST(uint8, AUTOMATIC, AUTOMATIC) DataPtr,
    PduLengthType DataLength,
    P2VAR(SoAd_PduHeaderType, AUTOMATIC, AUTOMATIC) PduHeaderPtr
);

STATIC FUNC(void, SOAD_CODE) SoAd__InitRxSession
(
    P2VAR(SoAd_ConnectionType, AUTOMATIC, AUTOMATIC) ConnPtr
);

STATIC FUNC(void, SOAD_CODE) SoAd__ClearRxSession
(
    P2VAR(SoAd_RxSessionType, AUTOMATIC, AUTOMATIC) SessionPtr
);

STATIC FUNC(Std_ReturnType, SOAD_CODE) SoAd__StartRxSession
(
    P2VAR(SoAd_ConnectionType, AUTOMATIC, AUTOMATIC) ConnPtr,
    P2CONST(SoAd_SocketRouteType, SOAD_CONFIG_DATA, AUTOMATIC) SocketRoutePtr,
    PduLengthType PduLength
);

STATIC FUNC(Std_ReturnType, SOAD_CODE) SoAd__CancelRxSession
(
    P2VAR(SoAd_ConnectionType, AUTOMATIC, AUTOMATIC) ConnPtr
);

STATIC FUNC(Std_ReturnType, SOAD_CODE) SoAd__IsCancelledRxSession
(
    P2VAR(SoAd_ConnectionType, AUTOMATIC, AUTOMATIC) ConnPtr
);

STATIC FUNC(void, SOAD_CODE) SoAd__DisactiveRxSession
(
    P2VAR(SoAd_ConnectionType, AUTOMATIC, AUTOMATIC) ConnPtr
);

STATIC FUNC(void, SOAD_CODE) SoAd__StopRxSession
(
    P2VAR(SoAd_ConnectionType, AUTOMATIC, AUTOMATIC) ConnPtr
);

STATIC FUNC(uint16, SOAD_CODE) SoAd__UpdateRxRemainLength
(
    P2VAR(SoAd_ConnectionType, AUTOMATIC, AUTOMATIC) ConnPtr,
    uint16 ReceivedLen
);

STATIC FUNC(void, SOAD_CODE) SoAd__SaveIfRxData
(
    P2VAR(SoAd_RxBufferType, AUTOMATIC, AUTOMATIC) RxBufferPtr,
    P2CONST(uint8, AUTOMATIC, AUTOMATIC) DataPtr,
    uint16 DataLength
);

STATIC FUNC(void, SOAD_CODE) SoAd__SaveTpRxData
(
    P2VAR(SoAd_ConnectionType, AUTOMATIC, AUTOMATIC) ConnPtr,
    P2CONST(uint8, AUTOMATIC, AUTOMATIC) DataPtr,
    uint16 DataLength
);

STATIC FUNC(Std_ReturnType, SOAD_CODE) SoAd__IsTpRxBufferEmpty
(
    P2VAR(SoAd_ConnectionType, AUTOMATIC, AUTOMATIC) ConnPtr
);

STATIC FUNC(Std_ReturnType, SOAD_CODE) SoAd__CheckTpBufferLength
(
    P2VAR(SoAd_ConnectionType, AUTOMATIC, AUTOMATIC) ConnPtr,
    uint16 DataLength
);

STATIC FUNC(Std_ReturnType, SOAD_CODE) SoAd__MakePduHeaderFromTpBuffer
(
    P2VAR(SoAd_ConnectionType, AUTOMATIC, AUTOMATIC) ConnPtr,
    P2VAR(SoAd_PduHeaderType, SOAD_CONFIG_DATA, AUTOMATIC) PduHeaderPtr
);

STATIC FUNC(uint16, SOAD_CODE) SoAd__DiscardTpRxData
(
    P2VAR(SoAd_ConnectionType, AUTOMATIC, AUTOMATIC) ConnPtr,
    uint16 DataLength
);

STATIC FUNC(Std_ReturnType, SOAD_CODE) SoAd__DispatchTpRxData
(
    P2VAR(SoAd_ConnectionType, AUTOMATIC, AUTOMATIC) ConnPtr,
    P2CONST(SoAd_SocketRouteType, SOAD_CONFIG_DATA, AUTOMATIC) SocketRoutePtr,
    P2VAR(uint16, AUTOMATIC, AUTOMATIC) DataLength
);

STATIC FUNC(Std_ReturnType, SOAD_CODE) SoAd__IsEnabledRxRouting
(
    P2VAR(SoAd_ConnectionType, AUTOMATIC, AUTOMATIC) ConnPtr,
    P2CONST(SoAd_SocketRouteType, SOAD_CONFIG_DATA, AUTOMATIC) SocketRoutePtr
);


STATIC FUNC(void, SOAD_CODE) SoAd__CallUpSoConModeChg
(
    SoAd_ULIndexType Index,
    SoAd_SoConIdType SoConId,
    SoAd_SoConModeType SoConMode
);

STATIC FUNC(void, SOAD_CODE) SoAd__CallUpLocalIpAddrAssignmentChg
(
    SoAd_ULIndexType Index,
    SoAd_SoConIdType SoConId,
    TcpIp_IpAddrStateType State
);

STATIC FUNC(void, SOAD_CODE) SoAd__CallUpIfRxIndication
(
    P2CONST(SoAd_SocketRouteType, SOAD_CONFIG_DATA, AUTOMATIC) SocketRoutePtr,
    P2CONST(PduInfoType, AUTOMATIC, AUTOMATIC) PduInfoPtr
);

STATIC FUNC(Std_ReturnType, SOAD_CODE) SoAd__CallUpIfTriggerTransmit
(
    P2CONST(SoAd_PduRouteType, SOAD_CONFIG_DATA, AUTOMATIC) PduRoutePtr,
    P2VAR(PduInfoType, AUTOMATIC, AUTOMATIC) PduInfoPtr
);

STATIC FUNC(void, SOAD_CODE) SoAd__CallUpIfTxConfirmation
(
    P2CONST(SoAd_PduRouteType, SOAD_CONFIG_DATA, AUTOMATIC) PduRoutePtr
);

STATIC FUNC(BufReq_ReturnType, SOAD_CODE) SoAd__CallUpCopyTxData
(
    P2CONST(SoAd_PduRouteType, SOAD_CONFIG_DATA, AUTOMATIC) PduRoutePtr,
    P2CONST(PduInfoType, AUTOMATIC, AUTOMATIC) PduInfoPtr,
    P2VAR(RetryInfoType, AUTOMATIC, AUTOMATIC) RetryPtr,
    P2VAR(PduLengthType, AUTOMATIC, AUTOMATIC) AvailableDataPtr
);

STATIC FUNC(void, SOAD_CODE) SoAd__CallUpTpTxConfirmation
(
    P2CONST(SoAd_PduRouteType, SOAD_CONFIG_DATA, AUTOMATIC) PduRoutePtr,
    Std_ReturnType Result
);

STATIC FUNC(BufReq_ReturnType, SOAD_CODE) SoAd__CallUpStartOfReception
(
    P2CONST(SoAd_SocketRouteType, SOAD_CONFIG_DATA, AUTOMATIC) SocketRoutePtr,
    P2CONST(PduInfoType, AUTOMATIC, AUTOMATIC) PduInfoPtr,
    PduLengthType TpSduLength,
    P2VAR(PduLengthType, AUTOMATIC, AUTOMATIC) bufferSizePtr
);

STATIC FUNC(BufReq_ReturnType, SOAD_CODE) SoAd__CallUpCopyRxData
(
    P2CONST(SoAd_SocketRouteType, SOAD_CONFIG_DATA, AUTOMATIC) SocketRoutePtr,
    P2CONST(PduInfoType, AUTOMATIC, AUTOMATIC) PduInfoPtr,
    P2VAR(PduLengthType, AUTOMATIC, AUTOMATIC) bufferSizePtr
);

STATIC FUNC(void, SOAD_CODE) SoAd__CallUpTpRxIndication
(
    P2CONST(SoAd_SocketRouteType, SOAD_CONFIG_DATA, AUTOMATIC) SocketRoutePtr,
    Std_ReturnType Result
);

/******************************************************************************
*   Local Data Define
******************************************************************************/
/*The UpLayer Modules Callback Table*/
extern CONST(SoAd_UpLayerInterfaceType, SOAD_CONFIG_DATA) SoAd_UpLayerInterfaces[SOAD_UL_MAX];
extern VAR(SoAd_ConnectionType, SOAD_CONFIG_DATA) SoAd_Connections[SOAD_SOCON_MAX];
#if (SOAD_CONFIG_VARIANTS == STD_CONFIG_VARIANTS_LINKTIME)
extern CONST(SoAd_ConfigType, SOAD_CONFIG_DATA) SoAd_Config;
#endif

#define SOAD_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"
#if (SOAD_CONFIG_VARIANTS != STD_CONFIG_VARIANTS_PRECOMPILE)
STATIC P2CONST(SoAd_ConfigType, SOAD_CONFIG_DATA, AUTOMATIC) SoAd_ConfigPtr;
#endif
#define SOAD_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"

#define SOAD_START_SEC_VAR_INIT_8
#include "MemMap.h"
STATIC Std_InitStateType SoAd_Initialized = STD_UNINITIALIZED;
#define SOAD_STOP_SEC_VAR_INIT_8
#include "MemMap.h"

#define SOAD_START_SEC_CODE
#include "MemMap.h"
/******************************************************************************
*   Global Function Define
******************************************************************************/
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: SoAd_Init
*
* Description:   Initializes the SoAd modules
*
* Inputs:        None
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, SOAD_CODE) SoAd_Init
(
    P2CONST(SoAd_ConfigType, SOAD_CONFIG_DATA, AUTOMATIC) ConfigPtr
)
{
    P2CONST(SoAd_SocketConnectionGroupType, SOAD_CONFIG_DATA, AUTOMATIC) groupPtr;
    SoAd_SoConGroupIdType groupId;
    SoAd_SoConIdType soConId;
    SoAd_SoConIdType soConIdMax;
    SoAd_RoutingGroupIdType routingId;

#if (SOAD_CONFIG_VARIANTS == STD_CONFIG_VARIANTS_POSTBUILD)
    if(NULL_PTR == ConfigPtr)
    {
        /*SWS_SoAd_00216*/
        SOAD_DET_REPORT_ERROR(SOAD_API_INIT, SOAD_E_INIT_FAILED);
    }
    else
#endif
    {
        /*SWS_SoAd_00211*/
#if (SOAD_CONFIG_VARIANTS == STD_CONFIG_VARIANTS_LINKTIME)
        SOAD_USED(ConfigPtr);
        SoAd_ConfigPtr = &SoAd_Config;
#elif(SOAD_CONFIG_VARIANTS == STD_CONFIG_VARIANTS_POSTBUILD)
        SoAd_ConfigPtr = ConfigPtr;
#else
        SOAD_USED(ConfigPtr);
#endif

        /*Initializes runtime context of socket connection*/
        for(groupId = 0; groupId < SOAD_GET_SOCON_GROUP_NUM(); groupId++)
        {
            groupPtr = SOAD_GET_SOCON_GROUP_PTR(groupId);
            soConId = groupPtr->SoConId;
            soConIdMax = groupPtr->SoConNum + soConId;

            /*Check if the configurations are valid in the SoConGroup*/
            if(soConId >= soConIdMax)
            {
                SOAD_DET_REPORT_ERROR(SOAD_API_INIT, SOAD_E_INV_CONFIG_DATA);
            }
            else
            {
                /*Initializes all socket connection in this SoConGroup*/
                do
                {
                    SoAd__InitConnection(soConId, groupPtr, SOAD_GET_SOCON_PTR(soConId));
                    soConId++;
                } while(soConId < soConIdMax);

                /*Initializes the shared socket Id*/
                SOAD_SET_SHARED_SOCKETID(groupId, TCPIP_SOCKETID_INVALID);
            }
        }

        for(routingId = 0; routingId < SOAD_GET_ROUTINGGRP_NUM(); routingId++)
        {
            if(SOAD_ROUTINGGRP_IS_INIT_ENABLED(SOAD_GET_ROUTINGGRP_PTR(routingId)))
            {
                SoAd__SetRoutingGroup(routingId, SOAD_ROUTING_GROUP_ENABLED);
            }
            else
            {
                SoAd__SetRoutingGroup(routingId, SOAD_ROUTING_GROUP_DISABLED);
            }
        }
        SoAd_Initialized = STD_INITIALIZED;
    }
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: SoAd_GetSoConId
*
* Description:   Finds the socket connection was refreferenced by TxPduId and
*                return the SoConId
*
* Inputs:        TxPduId    - the Index of PduRoute
*                SoConIdPtr - the buffer used for holding the SoConId
*
* Outputs:       If the socket connection is found returns E_OK, otherwise
*                returns NOT_OK.
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, SOAD_CODE) SoAd_GetSoConId
(
    PduIdType TxPduId,
    P2VAR(SoAd_SoConIdType, AUTOMATIC, SOAD_APPL_DATA) SoConIdPtr
)
{
    Std_ReturnType ret = E_NOT_OK;

    if(SoAd_Initialized != STD_INITIALIZED)
    {
        /*SWS_SoAd_00609*/
        SOAD_DET_REPORT_ERROR(SOAD_API_GET_SOCONID, SOAD_E_NOTINIT);
    }
    else if(TxPduId >= SOAD_GET_PDUROUTE_NUM())
    {
        /*SWS_SoAd_00610*/
        SOAD_DET_REPORT_ERROR(SOAD_API_GET_SOCONID, SOAD_E_INV_PDUID);
    }
    else if(NULL_PTR == SoConIdPtr)
    {
        SOAD_DET_REPORT_ERROR(SOAD_API_GET_SOCONID, SOAD_E_PARAM_POINTER);
    }
    else
    {
        P2CONST(SoAd_PduRouteType, SOAD_CONFIG_DATA, AUTOMATIC) routePtr;
        P2CONST(SoAd_PduRouteDestType, SOAD_CONFIG_DATA, AUTOMATIC) destPtr;

        routePtr = SOAD_GET_PDUROUTE_PTR(TxPduId);
        destPtr = SOAD_GET_PDUROUTE_DEST_PTR(routePtr->RouteDestId);
        /*SWS_SoAd_00724*/
        if((1 == routePtr->RouteDestNum) && (1 == destPtr->SoConNum))
        {
            ret = E_OK;
            *SoConIdPtr = destPtr->SoConId;
        }
    }

    return ret;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: SoAd_OpenSoCon
*
* Description:   Requests to open a socket connection.
*
* Inputs:        SoConId    - the socket connection will be opened.
*
* Outputs:       If the request is accepted returns OK, otherwise returns NOT_OK.
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, SOAD_CODE) SoAd_OpenSoCon
(
    SoAd_SoConIdType SoConId
)
{
    Std_ReturnType ret = E_NOT_OK;

    if(SoAd_Initialized != STD_INITIALIZED)
    {
        /*SWS_SoAd_00615*/
        SOAD_DET_REPORT_ERROR(SOAD_API_OPEN_SOCON, SOAD_E_NOTINIT);
    }
    else if(SoConId >= SOAD_GET_SOCON_NUM())
    {
        /*SWS_SoAd_00611*/
        SOAD_DET_REPORT_ERROR(SOAD_API_OPEN_SOCON, SOAD_E_INV_ARG);
    }
    else if(SOAD_SOCON_IS_AUTOSETUP(SOAD_GET_SOCONCTX_PTR(SoConId)))
    {
        /*SWS_SoAd_00528*/
        SOAD_DET_REPORT_ERROR(SOAD_API_OPEN_SOCON, SOAD_E_INV_ARG);
    }
    else
    {
        /*SWS_SoAd_00588*/
        SOAD_SOCON_SET_OPEN_REQUEST(SOAD_GET_SOCONCTX_PTR(SoConId));
        ret = E_OK;
    }

    return ret;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: SoAd_CloseSoCon
*
* Description:   Requests to close a socket connection.
*
* Inputs:        SoConId    - the socket connection will be closed.
* 				 abort      - TRUE: socket connection will immediately be terminated;
* 				            - FALSE: socket connection will be terminated if no other
* 				                     upper layer is using this socket connection.
*
* Outputs:       If the request is accepted returns OK, otherwise returns NOT_OK.
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, SOAD_CODE) SoAd_CloseSoCon
(
    SoAd_SoConIdType SoConId,
    boolean Abort
)
{
    Std_ReturnType ret = E_NOT_OK;

    if(SoAd_Initialized != STD_INITIALIZED)
    {
        /*SWS_SoAd_00616*/
        SOAD_DET_REPORT_ERROR(SOAD_API_CLOSE_SOCON, SOAD_E_NOTINIT);
    }
    else if(SoConId >= SOAD_GET_SOCON_NUM())
    {
        /*SWS_SoAd_00612*/
        SOAD_DET_REPORT_ERROR(SOAD_API_CLOSE_SOCON, SOAD_E_INV_ARG);
    }
    else if(SOAD_SOCON_IS_AUTOSETUP(SOAD_GET_SOCONCTX_PTR(SoConId)))
    {
        /*SWS_SoAd_00529*/
        SOAD_DET_REPORT_ERROR(SOAD_API_CLOSE_SOCON, SOAD_E_INV_ARG);
    }
    else
    {
        /*SWS_SoAd_00588*/
        SOAD_SOCON_SET_CLOSE_REQUEST(SOAD_GET_SOCONCTX_PTR(SoConId));
        SOAD_SOCON_SET_CLOSE_ABORT(SOAD_GET_SOCONCTX_PTR(SoConId), Abort);
        ret = E_OK;
    }

    return ret;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: SoAd_IfTransmit
*
* Description:   Requests transmission of an I-PDU.
*
* Inputs:        TxPduId    - the I-PDU's id.
*                PduInfoPtr - the informations of I-PDU.
*
* Outputs:       If the request is accepted returns OK, otherwise returns NOT_OK.
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, SOAD_CODE) SoAd_IfTransmit
(
    PduIdType TxPduId,
    P2CONST(PduInfoType, AUTOMATIC, SOAD_APPL_DATA) PduInfoPtr
)
{
    Std_ReturnType ret = E_NOT_OK;

    if(SoAd_Initialized != STD_INITIALIZED)
    {
        /*SWS_SoAd_00213*/
        SOAD_DET_REPORT_ERROR(SOAD_API_IF_TRANSMIT, SOAD_E_NOTINIT);
    }
    else if(NULL_PTR == PduInfoPtr)
    {
        SOAD_DET_REPORT_ERROR(SOAD_API_IF_TRANSMIT, SOAD_E_PARAM_POINTER);
    }
    else if(TxPduId >= SOAD_GET_PDUROUTE_NUM())
    {
        /*SWS_SoAd_00214*/
        SOAD_DET_REPORT_ERROR(SOAD_API_IF_TRANSMIT, SOAD_E_INV_PDUID);
    }
    /*SWS_SoAd_00539(2)*/
    else if((PduInfoPtr->SduLength > 0) || SOAD_PDUROUTE_IS_PDUHEADER_ENABLED(SOAD_GET_PDUROUTE_PTR(TxPduId)))
    {
        /*SWS_SoAd_00560*/
        P2CONST(SoAd_PduRouteType, SOAD_CONFIG_DATA, AUTOMATIC) routePtr;
        P2CONST(SoAd_PduRouteDestType, SOAD_CONFIG_DATA, AUTOMATIC) destPtr;
        P2VAR(SoAd_ConnectionType, AUTOMATIC, AUTOMATIC) connPtr;
        P2CONST(SoAd_UpLayerInterfaceType, SOAD_CONFIG_DATA, AUTOMATIC) interface;
        SoAd_SoConIdType connIdx = 0;
        uint8 result = SOAD_IFTX_RESULT_NOT_OK;
        uint16 unconfirmedLen = 0;
        uint16 txLen;
        SoAd_PduRouteDestIdType destId;
        SoAd_PduRouteDestIdType destMax;
        PduInfoType TxPduInfo;

        routePtr = SOAD_GET_PDUROUTE_PTR(TxPduId);
        destId = routePtr->RouteDestId;
        destMax = destId + routePtr->RouteDestNum;

        if(!SOAD_PDUROUTE_IS_IF(routePtr))
        {
            SOAD_DET_REPORT_ERROR_RET(SOAD_API_IF_TRANSMIT, SOAD_E_INV_PDUID, E_NOT_OK);
        }

        /*SWS_SoAd_00602*/
        while(destId < destMax)
        {
            destPtr = SOAD_GET_PDUROUTE_DEST_PTR(destId);
            /*SWS_SoAd_00722*/
            for(connIdx = 0; connIdx < destPtr->SoConNum; connIdx++)
            {
                connPtr = SOAD_GET_SOCONCTX_PTR(destPtr->SoConId + connIdx);
                if(SOAD_SOCON_IS_ONLINE(connPtr))
                {
                    if(SoAd_IsEnabledRouting(&destPtr->RoutingCtrlList[connIdx]) == E_OK)
                    {
                        TxPduInfo.SduLength = PduInfoPtr->SduLength;
                        if(PduInfoPtr->SduDataPtr == NULL_PTR) /* SomeIpTp Compatible */
                        {
                            if(SOAD_GET_IFTRIGGER_BUFFER_LENGTH() >= TxPduInfo.SduLength)
                            {
                                TxPduInfo.SduDataPtr = SOAD_GET_IFTRIGGER_BUFFER_PTR();
                                interface = SOAD_GET_UL_INTERFACE(SOAD_GET_PDUROUTE_PTR(TxPduId)->ULIndex);

                                if((interface->IfTriggerTransmit != NULL_PTR) && 
                                    (E_OK == interface->IfTriggerTransmit(routePtr->TxPduId, &TxPduInfo)))
                                {
                                    result = SOAD_IFTX_RESULT_OK;
                                }
                            }
                        }
                        else
                        {
                            TxPduInfo.SduDataPtr = PduInfoPtr->SduDataPtr;
                            result = SOAD_IFTX_RESULT_OK;
                        }
                        
                        if(result == SOAD_IFTX_RESULT_OK)
                        {
                            txLen = SoAd__IfTransmit(connPtr, routePtr, destPtr, &TxPduInfo);
                            if(0 == txLen)
                            {
                                /*SWS_SoAd_00648*/
                                result = SOAD_IFTX_RESULT_NOT_OK;
                                SOAD_DEBUG(SOAD_API_IF_TRANSMIT, 'Transmission Failed: Transport Layer Error!');
                                break;
                            }
                            unconfirmedLen += txLen;
                        }
                    }
                    else
                    {
                        SOAD_DEBUG(SOAD_API_IF_TRANSMIT, 'Transmission Failed: RoutingGroup not enabled!');
                    }
                }
                else
                {
                    SOAD_DEBUG(SOAD_API_IF_TRANSMIT, 'Transmission Failed: SoCon not online!');
                    result = SOAD_IFTX_RESULT_DISABLED_ROUTING;
                }
            }

            destId++;
        } /*while*/

        if(unconfirmedLen != (uint16)0)
        {
            /*SWS_SoAd_00647*/
            destPtr = SOAD_GET_PDUROUTE_DEST_PTR(routePtr->RouteDestId);
            SOAD_ENTER_CRITICAL_SECTION_TX_UNCONFIRM_IDX();
            SOAD_IFTX_INCREASE_UNCONFIRMED(SOAD_GET_IFTXUNCONFIRMED_PTR(destPtr->PduRouteId), unconfirmedLen);
            SOAD_LEAVE_CRITICAL_SECTION_TX_UNCONFIRM_IDX();
            ret = E_OK;
        }
    }
    else
    {

    }

    return ret;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: SoAd_IfRoutingGroupTransmit
*
* Description:   Triggers the transmission of all If-TxPDUs identified by the
*                parameter GroupId after requesting the data from the related\
*                upper layer.
*
* Inputs:        GroupId    - the routing group id
*
* Outputs:       If the request is accepted returns OK, otherwise returns NOT_OK.
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, SOAD_CODE) SoAd_IfRoutingGroupTransmit
(
    SoAd_RoutingGroupIdType GroupId
)
{
    Std_ReturnType ret = E_NOT_OK;

    if(SoAd_Initialized != STD_INITIALIZED)
    {
        /*SWS_SoAd_00661*/
        SOAD_DET_REPORT_ERROR(SOAD_API_IF_ROUTING_GROUP_TRANSMIT, SOAD_E_NOTINIT);
    }
    else if((GroupId >= SOAD_GET_ROUTINGGRP_NUM())
            || !SOAD_ROUTINGGRP_IS_TRIGGERABLE(SOAD_GET_ROUTINGGRP_PTR(GroupId)))
    {
        /*SWS_SoAd_00658*/
        SOAD_DET_REPORT_ERROR(SOAD_API_IF_ROUTING_GROUP_TRANSMIT, SOAD_E_INV_ARG);
    }
    else
    {
        P2CONST(SoAd_RoutingGroupType, SOAD_CONFIG_DATA, AUTOMATIC) groupPtr;
        P2CONST(SoAd_PduRouteDestType, SOAD_CONFIG_DATA, AUTOMATIC) routeDestPtr;
        SoAd_PduRouteDestIdType pduDestId;
        SoAd_SoConIdType idx;

        groupPtr = SOAD_GET_ROUTINGGRP_PTR(GroupId);
        SOAD_ENTER_CRITICAL_SECTION_IFRG_TRANSMIT_IDX();
        for(pduDestId = 0; pduDestId < groupPtr->PduRouteDestNum; pduDestId++)
        {
            routeDestPtr = SOAD_GET_PDUROUTE_DEST_PTR(groupPtr->PduRouteDestList[pduDestId]);
            if(!SOAD_PDUROUTE_IS_IF(SOAD_GET_PDUROUTE_PTR(routeDestPtr->PduRouteId)))
            {
                continue;
            }

            for(idx = 0; idx < routeDestPtr->SoConNum; idx++)
            {
                /*SWS_SoAd_00662*/
                SOAD_PDUROUTE_SET_IFTRIGGER_REQUEST(routeDestPtr, idx);
            }
        }
        SOAD_LEAVE_CRITICAL_SECTION_IFRG_TRANSMIT_IDX();
        ret = E_OK;
    }

    return ret;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: SoAd_IfSpecificRoutingGroupTransmit
*
* Description:   Triggers the transmission of all If-TxPDUs identified by the
*                parameter GroupId on the socket connection specified by SoConId
*                after requesting the data from the related upper layer.
*
* Inputs:        GroupId    - the routing group id
*                SoConId    - the socket connection id
*
* Outputs:       If the request is accepted returns OK, otherwise returns NOT_OK.
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, SOAD_CODE) SoAd_IfSpecificRoutingGroupTransmit
(
    SoAd_RoutingGroupIdType GroupId,
    SoAd_SoConIdType SoConId
)
{
    Std_ReturnType ret = E_NOT_OK;

    if(SoAd_Initialized != STD_INITIALIZED)
    {
        /*SWS_SoAd_00712*/
        SOAD_DET_REPORT_ERROR(SOAD_API_IF_SPECROUTING_GROUP_TRANSMIT, SOAD_E_NOTINIT);
    }
    else if((GroupId >= SOAD_GET_ROUTINGGRP_NUM())
            || !SOAD_ROUTINGGRP_IS_TRIGGERABLE(SOAD_GET_ROUTINGGRP_PTR(GroupId)))
    {
        /*SWS_SoAd_00713*/
        SOAD_DET_REPORT_ERROR(SOAD_API_IF_SPECROUTING_GROUP_TRANSMIT, SOAD_E_INV_ARG);
    }
    else
    {
        P2CONST(SoAd_RoutingGroupType, SOAD_CONFIG_DATA, AUTOMATIC) groupPtr;
        P2CONST(SoAd_PduRouteDestType, SOAD_CONFIG_DATA, AUTOMATIC) routeDestPtr;
        SoAd_PduRouteDestIdType pduDestId;
        SoAd_SoConIdType idx;

        groupPtr = SOAD_GET_ROUTINGGRP_PTR(GroupId);
        for(pduDestId = 0; pduDestId < groupPtr->PduRouteDestNum; pduDestId++)
        {
            routeDestPtr = SOAD_GET_PDUROUTE_DEST_PTR(groupPtr->PduRouteDestList[pduDestId]);
            if(SOAD_PDUROUTE_IS_IF(SOAD_GET_PDUROUTE_PTR(routeDestPtr->PduRouteId))
                && SOAD_PDUROUTE_IS_VALID_SOCONID(routeDestPtr, SoConId))
            {
                idx = SOAD_PDUROUTE_GET_ROUTING_IDX(routeDestPtr, SoConId);
                /*SWS_SoAd_00720*/
                SOAD_PDUROUTE_SET_IFTRIGGER_REQUEST(routeDestPtr, idx);
            }
        }
        ret = E_OK;
    }

    return ret;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: SoAd_TpTransmit
*
* Description:   Requests transmission of an I-PDU.
*
* Inputs:        TxPduId    - the I-PDU's id.
*                PduInfoPtr - the informations of I-PDU.
*                			  Note:Only the length is valid.
*
* Outputs:       If the request is accepted returns OK, otherwise returns NOT_OK.
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, SOAD_CODE) SoAd_TpTransmit
(
    PduIdType TxPduId,
    P2CONST(PduInfoType, AUTOMATIC, SOAD_APPL_DATA) PduInfoPtr
)
{
    Std_ReturnType ret = E_NOT_OK;
    P2CONST(SoAd_PduRouteType, SOAD_CONFIG_DATA, AUTOMATIC) routePtr;

    if(SoAd_Initialized != STD_INITIALIZED)
    {
        /*SWS_SoAd_00224*/
        SOAD_DET_REPORT_ERROR(SOAD_API_TP_TRANSMIT, SOAD_E_NOTINIT);
    }
    else if(NULL_PTR == PduInfoPtr)
    {
        SOAD_DET_REPORT_ERROR(SOAD_API_TP_TRANSMIT, SOAD_E_PARAM_POINTER);
    }
    else if(TxPduId >= SOAD_GET_PDUROUTE_NUM())
    {
        /*SWS_SoAd_00237*/
        SOAD_DET_REPORT_ERROR(SOAD_API_TP_TRANSMIT, SOAD_E_INV_PDUID);
    }
    else if(0 == PduInfoPtr->SduLength)
    {
        /*SWS_SoAd_00551(1)*/
    }
    else
    {
        P2CONST(SoAd_PduRouteDestType, SOAD_CONFIG_DATA, AUTOMATIC) destPtr;
        P2VAR(SoAd_ConnectionType, AUTOMATIC, AUTOMATIC) connPtr;
        P2VAR(SoAd_TxSessionType,  AUTOMATIC, AUTOMATIC) txSessionPtr;
        SoAd_SoConIdType connIdx = 0;

        routePtr = SOAD_GET_PDUROUTE_PTR(TxPduId);
        destPtr = SOAD_GET_PDUROUTE_DEST_PTR(routePtr->RouteDestId);
        /*SWS_SoAd_00551(2)*/
        connPtr = SOAD_GET_SOCONCTX_PTR(destPtr->SoConId); 
        txSessionPtr = &connPtr->TxSession;

        for(connIdx = 0; connIdx < destPtr->SoConNum; connIdx++)
        {
            /*SWS_SoAd_00650*/
            if((!SOAD_SOCON_IS_ONLINE(connPtr)))  
            {
                /*SWS_SoAd_00587*/
            }
            else if(SoAd_IsEnabledRouting(&destPtr->RoutingCtrlList[connIdx]) == E_NOT_OK)
            {
                /*SWS_SoAd_00561*/
            }
            else if(SoAd__StartTxSession(connPtr, SOAD_SESSION_STATE_TP) != E_OK)
            {
                /*nothing*/
            }
            /*SWS_SoAd_00551(3)*/
            else if(SOAD_SOCON_IS_UDP(connPtr))
            {
                SOAD_ENTER_CRITICAL_SECTION_TX_SESSION_IDX();

                txSessionPtr->PduRouteDestPtr = destPtr;
                if(SOAD_SOCON_IS_PDUHEADER_ENABLED(connPtr))
                {
                    SoAd__SerializePduHeader(destPtr->TxPduHeaderId, PduInfoPtr->SduLength, txSessionPtr->UdpTxBuffer);
                    txSessionPtr->BufferOffset = SOAD_PDUHEADER_LENGTH;
                }
                else
                {
                    txSessionPtr->BufferOffset = 0;
                }

                txSessionPtr->TotalTxLength = PduInfoPtr->SduLength;
                txSessionPtr->UsedTxLength = 0;

                SOAD_LEAVE_CRITICAL_SECTION_TX_SESSION_IDX();

                ret = E_OK;
            }
            else
            {
                /* SOAD_SOCON_IS_TCP */
                SOAD_ENTER_CRITICAL_SECTION_TX_SESSION_IDX();

                txSessionPtr->PduRouteDestPtr = destPtr;
                if(SOAD_SOCON_IS_PDUHEADER_ENABLED(connPtr))
                {
                    txSessionPtr->TotalTxLength = PduInfoPtr->SduLength + SOAD_PDUHEADER_LENGTH;
                }
                else
                {
                    txSessionPtr->TotalTxLength = PduInfoPtr->SduLength;
                }
                txSessionPtr->UsedTxLength = 0;

                SOAD_LEAVE_CRITICAL_SECTION_TX_SESSION_IDX();

                ret = E_OK;
            }
        }
    }

    return ret;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: SoAd_TpCancelTransmit
*
* Description:   Requests cancellation of the transmission via TP for a specific
*                I-PDU.
*
* Inputs:        PduId  - the I-PDU's id.
*
* Outputs:       If the request is accepted returns OK, otherwise returns NOT_OK.
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, SOAD_CODE) SoAd_TpCancelTransmit
(
    PduIdType PduId
)
{
    Std_ReturnType ret = E_NOT_OK;

    if(SoAd_Initialized != STD_INITIALIZED)
    {
        /*SWS_SoAd_00605*/
        SOAD_DET_REPORT_ERROR(SOAD_API_TP_CANCEL_TRANSMIT, SOAD_E_NOTINIT);
    }
    else if(PduId >= SOAD_GET_PDUROUTE_NUM())
    {
        /*SWS_SoAd_00606*/
        SOAD_DET_REPORT_ERROR(SOAD_API_TP_CANCEL_TRANSMIT, SOAD_E_INV_PDUID);
    }
    else if(!SOAD_PDUROUTE_IS_TP(SOAD_GET_PDUROUTE_PTR(PduId)))
    {
        /*nothing*/
    }
    else
    {
        P2CONST(SoAd_PduRouteType, SOAD_CONFIG_DATA, AUTOMATIC) routePtr;
        P2CONST(SoAd_PduRouteDestType, SOAD_CONFIG_DATA, AUTOMATIC) destPtr;
        P2VAR(SoAd_ConnectionType, AUTOMATIC, AUTOMATIC) connPtr;

        routePtr = SOAD_GET_PDUROUTE_PTR(PduId);
        destPtr = SOAD_GET_PDUROUTE_DEST_PTR(routePtr->RouteDestId);
        connPtr = SOAD_GET_SOCONCTX_PTR(destPtr->SoConId);
        /*SWS_SoAd_00575*/
        ret = SoAd__CancelTxSession(connPtr);
        if(E_OK == ret)
        {
            /*SWS_SoAd_00577*/
            SOAD_SOCON_SET_CLOSE_EVENT(connPtr);
        }
        else
        {
            /*SWS_SoAd_00576*/
        }
    }

    return ret;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: SoAd_TpCancelReceive
*
* Description:   Requests cancellation of the reception via TP for a specific
*                I-PDU.
*
* Inputs:        PduId  - the I-PDU's id.
*
* Outputs:       If the request is accepted returns OK, otherwise returns NOT_OK.
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, SOAD_CODE) SoAd_TpCancelReceive
(
    PduIdType PduId
)
{
    Std_ReturnType ret = E_NOT_OK;

    if(SoAd_Initialized != STD_INITIALIZED)
    {
        /*SWS_SoAd_00607*/
        SOAD_DET_REPORT_ERROR(SOAD_API_TP_CANCEL_RECEIVE, SOAD_E_NOTINIT);
    }
    else if(PduId >= SOAD_GET_SOCKETROUTE_NUM())
    {
        /*SWS_SoAd_00608*/
        SOAD_DET_REPORT_ERROR(SOAD_API_TP_CANCEL_RECEIVE, SOAD_E_INV_PDUID);
    }
    else
    {
        P2CONST(SoAd_SocketRouteType, SOAD_CONFIG_DATA, AUTOMATIC) routePtr;
        P2VAR(SoAd_ConnectionType, AUTOMATIC, AUTOMATIC) connPtr;
    
        routePtr = SOAD_GET_SOCKETROUTE_PTR(PduId);
        connPtr = SOAD_GET_SOCONCTX_PTR(routePtr->SoConId);
        /*SWS_SoAd_00575*/
        ret = SoAd__CancelRxSession(connPtr);
        if(E_OK == ret)
        {
            /*SWS_SoAd_00581*/
            SOAD_SOCON_SET_CLOSE_EVENT(connPtr);
        }
        else
        {
            /*SWS_SoAd_00576*/
        }
    }

    return ret;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: SoAd_RequestIpAddrAssignment
*
* Description:   By this API service the local IP address assignment which shall
*                be used for the socket connection specified by SoConId is initiated.
*
* Inputs:        SoConId            - the SoCon's id.
*                Type               - the assignment type
*                LocalIpAddrPtr     - the pointer of local IP address
*                Netmask            - the netmask of IP address
*                DefaultRouterPtr   - the pointer of default router
*
* Outputs:       If the request is accepted returns OK, otherwise returns NOT_OK.
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, SOAD_CODE) SoAd_RequestIpAddrAssignment
(
    SoAd_SoConIdType SoConId,
    TcpIp_IpAddrAssignmentType Type,
    P2CONST(TcpIp_SockAddrType, AUTOMATIC, SOAD_APPL_DATA) LocalIpAddrPtr,
    uint8 Netmask,
    P2CONST(TcpIp_SockAddrType, AUTOMATIC, SOAD_APPL_DATA) DefaultRouterPtr
)
{
    Std_ReturnType ret = E_NOT_OK;

    if(SoAd_Initialized != STD_INITIALIZED)
    {
        /*SWS_SoAd_00613*/
        SOAD_DET_REPORT_ERROR(SOAD_API_REQUEST_IPADDR_ASSIGNMENT, SOAD_E_NOTINIT);
    }
    else if(SoConId >= SOAD_GET_SOCON_NUM())
    {
        /*SWS_SoAd_00617*/
        SOAD_DET_REPORT_ERROR(SOAD_API_REQUEST_IPADDR_ASSIGNMENT, SOAD_E_INV_ARG);
    }
    else
    {
        P2VAR(SoAd_ConnectionType, AUTOMATIC, AUTOMATIC) connPtr;

        connPtr = SOAD_GET_SOCONCTX_PTR(SoConId);
        ret = TcpIp_RequestIpAddrAssignment(connPtr->GroupConfigPtr->LocalAddrId,
                                                Type,
                                                LocalIpAddrPtr,
                                                Netmask,
                                                DefaultRouterPtr);
    }

    return ret;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: SoAd_ReleaseIpAddrAssignment
*
* Description:   By this API service the local IP address assignment used for
*                the socket connection specified by SoConId is released.
*
* Inputs:        SoConId    - the SoCon's id.
*
* Outputs:       If the request is accepted returns OK, otherwise returns NOT_OK.
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, SOAD_CODE) SoAd_ReleaseIpAddrAssignment
(
    SoAd_SoConIdType SoConId
)
{
    Std_ReturnType ret = E_NOT_OK;

    if(SoAd_Initialized != STD_INITIALIZED)
    {
        /*SWS_SoAd_00618*/
        SOAD_DET_REPORT_ERROR(SOAD_API_RELEASE_IPADDR_ASSIGNMENT, SOAD_E_NOTINIT);
    }
    else if(SoConId >= SOAD_GET_SOCON_NUM())
    {
        /*SWS_SoAd_00619*/
        SOAD_DET_REPORT_ERROR(SOAD_API_RELEASE_IPADDR_ASSIGNMENT, SOAD_E_INV_ARG);
    }
    else
    {
        P2VAR(SoAd_ConnectionType, AUTOMATIC, AUTOMATIC) connPtr;
        connPtr = SOAD_GET_SOCONCTX_PTR(SoConId);
        ret = TcpIp_ReleaseIpAddrAssignment(connPtr->GroupConfigPtr->LocalAddrId);
    }

    return ret;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: SoAd_GetLocalAddr
*
* Description:   Retrieves the local address (IP address and port) actually used
*                for the SoAd socket connection specified by SoConId, the netmask
*                and default router
*
* Inputs:        SoConId            - the SoCon's id.
*                LocalIpAddrPtr     - the pointer of local IP address
*                NetmaskPtr         - the pointer of netmask of IP address
*                DefaultRouterPtr   - the pointer of default router
*
* Outputs:       If the request is accepted returns OK, otherwise returns NOT_OK.
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, SOAD_CODE) SoAd_GetLocalAddr
(
    SoAd_SoConIdType SoConId,
    P2VAR(TcpIp_SockAddrType, AUTOMATIC, SOAD_APPL_DATA) LocalAddrPtr,
    P2VAR(uint8, AUTOMATIC, SOAD_APPL_DATA) NetmaskPtr,
    P2VAR(TcpIp_SockAddrType, AUTOMATIC, SOAD_APPL_DATA) DefaultRouterPtr
)
{
    Std_ReturnType ret = E_NOT_OK;

    if(SoAd_Initialized != STD_INITIALIZED)
    {
        /*SWS_SoAd_00621*/
        SOAD_DET_REPORT_ERROR(SOAD_API_GET_LOCAL_ADDR, SOAD_E_NOTINIT);
    }
    else if(SoConId >= SOAD_GET_SOCON_NUM())
    {
        /*SWS_SoAd_00620*/
        SOAD_DET_REPORT_ERROR(SOAD_API_GET_LOCAL_ADDR, SOAD_E_INV_ARG);
    }
    else
    {
        P2VAR(SoAd_ConnectionType, AUTOMATIC, AUTOMATIC) connPtr;

        connPtr = SOAD_GET_SOCONCTX_PTR(SoConId);
        ret = TcpIp_GetIpAddr(connPtr->GroupConfigPtr->LocalAddrId,
                                LocalAddrPtr,
                                NetmaskPtr,
                                DefaultRouterPtr);
        if(E_OK == ret)
        {
            ((TcpIp_SockAddrInetType*)LocalAddrPtr)->Port = connPtr->GroupConfigPtr->LocalPort;
        }
    }

    return ret;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: SoAd_GetPhysAddr
*
* Description:   Retrieves the physical source address of the EthIf controller
*                used by the SoAd socket connection specified by SoConId.
*
* Inputs:        SoConId        - the SoCon's id.
*                PhysAddrPtr    - the pointer of MAC address
*
* Outputs:       If the request is accepted returns OK, otherwise returns NOT_OK.
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, SOAD_CODE) SoAd_GetPhysAddr
(
    SoAd_SoConIdType SoConId,
    P2VAR(uint8, AUTOMATIC, SOAD_APPL_DATA) PhysAddrPtr
)
{
    Std_ReturnType ret = E_NOT_OK;

    if(SoAd_Initialized != STD_INITIALIZED)
    {
        /*SWS_SoAd_00623*/
        SOAD_DET_REPORT_ERROR(SOAD_API_GET_PHYS_ADDR, SOAD_E_NOTINIT);
    }
    else if(SoConId >= SOAD_GET_SOCON_NUM())
    {
        /*SWS_SoAd_00622*/
        SOAD_DET_REPORT_ERROR(SOAD_API_GET_PHYS_ADDR, SOAD_E_INV_ARG);
    }
    else
    {
        P2VAR(SoAd_ConnectionType, AUTOMATIC, AUTOMATIC) connPtr;

        connPtr = SOAD_GET_SOCONCTX_PTR(SoConId);
        ret = TcpIp_GetPhysAddr(connPtr->GroupConfigPtr->LocalAddrId, PhysAddrPtr);
    }

    return ret;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: SoAd_GetRemoteAddr
*
* Description:   Retrieves the remote address (IP address and port) actually
*                used for the SoAd socket connection specified by SoConId
*
* Inputs:        SoConId    - the SoCon's id.
*                IpAddrPtr  - the pointer of remote IP address
*
* Outputs:       If the request is accepted returns OK, otherwise returns NOT_OK.
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, SOAD_CODE) SoAd_GetRemoteAddr
(
    SoAd_SoConIdType SoConId,
    P2VAR(TcpIp_SockAddrType, AUTOMATIC, SOAD_APPL_DATA) IpAddrPtr
)
{
    Std_ReturnType ret = E_NOT_OK;

    if(SoAd_Initialized != STD_INITIALIZED)
    {
        /*SWS_SoAd_00659*/
        SOAD_DET_REPORT_ERROR(SOAD_API_GET_REMOTE_ADDR, SOAD_E_NOTINIT);
    }
    else if(SoConId >= SOAD_GET_SOCON_NUM())
    {
        /*SWS_SoAd_00660*/
        SOAD_DET_REPORT_ERROR(SOAD_API_GET_REMOTE_ADDR, SOAD_E_INV_ARG);
    }
    else
    {
        P2VAR(SoAd_ConnectionType, AUTOMATIC, AUTOMATIC) connPtr;

        connPtr = SOAD_GET_SOCONCTX_PTR(SoConId);
        if(!SOAD_RADDR_IS_VALID_ADDR(connPtr->RemoteAddrState))
        {
            /*SWS_SoAd_00666*/
        }
        else if(connPtr->RemoteAddr.Domain != IpAddrPtr->Domain)
        {
            /*SWS_SoAd_00698*/
            SOAD_DET_REPORT_ERROR(SOAD_API_RELEASE_IPADDR_ASSIGNMENT, SOAD_E_INV_ARG);
        }
        else
        {
            SoAd__CopyRemoteAddress((P2VAR(SoAd_RemoteAddressType, AUTOMATIC, AUTOMATIC))IpAddrPtr,
                                    &connPtr->RemoteAddr);
            ret = E_OK;
        }
    }

    return ret;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: SoAd_SetRemoteAddr
*
* Description:   By this API service the remote address (IP address and port) of
*                the specified socket connection shall be set.
*
* Inputs:        SoConId    - the SoCon's id.
*                IpAddrPtr  - the pointer of remote IP address
*
* Outputs:       If the request is accepted returns OK, otherwise returns NOT_OK.
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, SOAD_CODE) SoAd_SetRemoteAddr
(
    SoAd_SoConIdType SoConId,
    P2CONST(TcpIp_SockAddrType, AUTOMATIC, SOAD_APPL_DATA) IpAddrPtr
)
{
    Std_ReturnType ret = E_NOT_OK;

    if(SoAd_Initialized != STD_INITIALIZED)
    {
        /*SWS_SoAd_00628*/
        SOAD_DET_REPORT_ERROR(SOAD_API_SET_REMOTE_ADDR, SOAD_E_NOTINIT);
    }
    else if(SoConId >= SOAD_GET_SOCON_NUM())
    {
        SOAD_DET_REPORT_ERROR(SOAD_API_SET_REMOTE_ADDR, SOAD_E_INV_ARG);
    }
    else if(SOAD_SOCON_IS_AUTOSETUP(SOAD_GET_SOCONCTX_PTR(SoConId)))
    {
        /*SWS_SoAd_00531*/
        SOAD_DET_REPORT_ERROR(SOAD_API_SET_REMOTE_ADDR, SOAD_E_INV_ARG);
    }
    else
    {
        P2VAR(SoAd_ConnectionType, AUTOMATIC, AUTOMATIC) connPtr;
        P2CONST(SoAd_RemoteAddressType, AUTOMATIC, SOAD_APPL_DATA) remoteAddrPtr;

        connPtr = SOAD_GET_SOCONCTX_PTR(SoConId);
        remoteAddrPtr = (P2CONST(SoAd_RemoteAddressType, AUTOMATIC, SOAD_APPL_DATA))IpAddrPtr;
        SOAD_ENTER_CRITICAL_SECTION_SOCON_MODE_IDX();
        if(connPtr->RemoteAddr.Domain != IpAddrPtr->Domain)
        {
            /*SWS_SoAd_00699*/
            SOAD_DET_REPORT_ERROR(SOAD_API_SET_REMOTE_ADDR, SOAD_E_INV_ARG);
        }
        /*SWS_SoAd_00532*/
        else if(SOAD_SOCON_IS_OFFLINE(connPtr)
                || (SOAD_SOCON_IS_UDP(connPtr)
                && SOAD_SESSION_IS_IDLE(&connPtr->TxSession)))
        {
            uint8 state = SoAd__CheckRemoteAddressState(remoteAddrPtr);
            /*SWS_SoAd_00533*/
            SoAd__UpdateConnRemoteAddress(connPtr, remoteAddrPtr, state);
            ret = E_OK;
        }
        else
        {
            /*nothing*/
        }
        SOAD_LEAVE_CRITICAL_SECTION_SOCON_MODE_IDX();
    }

    return ret;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: SoAd_SetUniqueRemoteAddr
*
* Description:   This API service shall either return the socket connection index
*                of the SoAdSocketConnectionGroup where the specified remote address
*                (IP address and port) is set or assign the remote address to an
*                unused socket connection from the same SoAdSocketConnectionGroup.
*
* Inputs:        SoConId            - the SoCon's id.
*                IpAddrPtr          - the pointer of remote IP address.
*                AssignedSoConIdPtr - the SoCon with remote IP address.
*
* Outputs:       If the request is accepted returns OK, otherwise returns NOT_OK.
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, SOAD_CODE) SoAd_SetUniqueRemoteAddr
(
    SoAd_SoConIdType SoConId,
    P2CONST(TcpIp_SockAddrType, AUTOMATIC, SOAD_APPL_DATA) IpAddrPtr,
    P2VAR(SoAd_SoConIdType, AUTOMATIC, SOAD_APPL_DATA) AssignedSoConIdPtr
)
{
    Std_ReturnType ret = E_NOT_OK;

    if(SoAd_Initialized != STD_INITIALIZED)
    {
        /*SWS_SoAd_00672*/
        SOAD_DET_REPORT_ERROR(SOAD_API_SET_UNIQUE_REMOTE_ADDR, SOAD_E_NOTINIT);
    }
    else if(SoConId >= SOAD_GET_SOCON_NUM())
    {
        /*SWS_SoAd_00673*/
        SOAD_DET_REPORT_ERROR(SOAD_API_SET_UNIQUE_REMOTE_ADDR, SOAD_E_INV_ARG);
    }
    else if(SOAD_SOCON_IS_AUTOSETUP(SOAD_GET_SOCONCTX_PTR(SoConId)))
    {
        /*SWS_SoAd_00531*/
        SOAD_DET_REPORT_ERROR(SOAD_API_SET_UNIQUE_REMOTE_ADDR, SOAD_E_INV_ARG);
    }
    else
    {
        P2VAR(SoAd_ConnectionType, AUTOMATIC, AUTOMATIC) connPtr;
        P2CONST(SoAd_RemoteAddressType, AUTOMATIC, SOAD_APPL_DATA) remoteAddrPtr;

        connPtr = SOAD_GET_SOCONCTX_PTR(SoConId);
        remoteAddrPtr = (P2CONST(SoAd_RemoteAddressType, AUTOMATIC, SOAD_APPL_DATA))IpAddrPtr;

        SOAD_ENTER_CRITICAL_SECTION_SOCON_MODE_IDX();
        if(connPtr->RemoteAddr.Domain != IpAddrPtr->Domain)
        {
            /*SWS_SoAd_00700*/
            SOAD_DET_REPORT_ERROR(SOAD_API_SET_UNIQUE_REMOTE_ADDR, SOAD_E_INV_ARG);
        }
        else
        {
            uint8 state = SoAd__CheckRemoteAddressState(remoteAddrPtr);
            uint8 level = SOAD_BMA_MATCH_LEVEL_MIN;
            SoAd_SoConIdType soConId = connPtr->GroupConfigPtr->SoConId;
            SoAd_SoConIdType soConIdMax = connPtr->GroupConfigPtr->SoConNum + soConId;
            SoAd_SoConIdType foundSoConId;

            for(;soConId < soConIdMax; soConId++)
            {
                connPtr = SOAD_GET_SOCONCTX_PTR(soConId);
                if(SOAD_RADDR_IS_VALID_ADDR(connPtr->RemoteAddrState))
                {
                    uint8 tmp = SoAd__BestMatchAlgorithm(connPtr, remoteAddrPtr);
                    if(SOAD_BMA_MATCH_LEVEL_MAX == tmp)
                    {
                        /*SWS_SoAd_00675*/
                        level = SOAD_BMA_MATCH_LEVEL_MIN;
                        *AssignedSoConIdPtr = soConId;
                        ret = E_OK;
                        break;
                    }
                    else if(tmp > level)
                    {
                        level = tmp;
                        foundSoConId = soConId;
                    }
                    else
                    {
                        /* SWS_SoAd_00678 */
                    }
                }
            }

            if(level > SOAD_BMA_MATCH_LEVEL_MIN)
            {
                /*SWS_SoAd_00676*/
                connPtr = SOAD_GET_SOCONCTX_PTR(foundSoConId);
                SoAd__UpdateConnRemoteAddress(connPtr, remoteAddrPtr, state);
                *AssignedSoConIdPtr = foundSoConId;
                ret = E_OK;
            }
        }
    	SOAD_LEAVE_CRITICAL_SECTION_SOCON_MODE_IDX();
    }

    return ret;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: SoAd_EnableRouting
*
* Description:   Enables routing of a group of PDUs in the SoAd related to the
*                RoutingGroup specified by parameter id.
*                Routing of PDUs can be either forwarding of PDUs from the upper
*                layer to a TCP or UDP socket of the TCP/IP stack specified by a
*                PduRoute or the other way around specified by a SocketRoute.
*
* Inputs:        GroupId    - the Routing Group's id.
*
* Outputs:       If the request is accepted returns OK, otherwise returns NOT_OK.
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, SOAD_CODE) SoAd_EnableRouting
(
    SoAd_RoutingGroupIdType GroupId
)
{
    Std_ReturnType ret = E_NOT_OK;

    if(SoAd_Initialized != STD_INITIALIZED)
    {
        /*SWS_SoAd_00624*/
        SOAD_DET_REPORT_ERROR(SOAD_API_ENABLE_ROUTING, SOAD_E_NOTINIT);
    }
    else if(GroupId >= SOAD_GET_ROUTINGGRP_NUM())
    {
        /*SWS_SoAd_00625*/
        SOAD_DET_REPORT_ERROR(SOAD_API_ENABLE_ROUTING, SOAD_E_INV_ARG);
    }
    else
    {
    	SOAD_ENTER_CRITICAL_SECTION_ROUTING_GROUP_IDX();
        SoAd__SetRoutingGroup(GroupId, SOAD_ROUTING_GROUP_ENABLED);
        SOAD_LEAVE_CRITICAL_SECTION_ROUTING_GROUP_IDX();
        ret = E_OK;
    }

    return ret;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: SoAd_EnableSpecificRouting
*
* Description:   Enables routing of a group of PDUs in the SoAd related to the
*                RoutingGroup specified by parameter id only on the socket
*                connection identified by SoConId.
*
* Inputs:        GroupId    - the Routing Group's id.
*                SoConhId   - the SoCon's Id
*
* Outputs:       If the request is accepted returns OK, otherwise returns NOT_OK.
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, SOAD_CODE) SoAd_EnableSpecificRouting
(
    SoAd_RoutingGroupIdType GroupId,
    SoAd_SoConIdType SoConId
)
{
    Std_ReturnType ret = E_NOT_OK;

    if(SoAd_Initialized != STD_INITIALIZED)
    {
        /*SWS_SoAd_00715*/
        SOAD_DET_REPORT_ERROR(SOAD_API_ENABLE_SPECIFIC_ROUTING, SOAD_E_NOTINIT);
    }
    else if(GroupId >= SOAD_GET_ROUTINGGRP_NUM())
    {
        /*SWS_SoAd_00716*/
        SOAD_DET_REPORT_ERROR(SOAD_API_ENABLE_SPECIFIC_ROUTING, SOAD_E_INV_ARG);
    }
    else
    {
    	SOAD_ENTER_CRITICAL_SECTION_ROUTING_GROUP_IDX();
        SoAd__SetSpecificRoutingGroup(GroupId, SoConId, SOAD_ROUTING_GROUP_ENABLED);
        SOAD_LEAVE_CRITICAL_SECTION_ROUTING_GROUP_IDX();
        ret = E_OK;
    }

    return ret;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: SoAd_DisableRouting
*
* Description:   Disables routing of a group of PDUs in the SoAd related to the
*                RoutingGroup specified by parameter id.
*                Routing of PDUs can be either forwarding of PDUs from the upper
*                layer to a TCP or UDP socket of the TCP/IP stack specified by a
*                PduRoute or the other way around specified by a SocketRoute.
*
* Inputs:        GroupId    - the Routing Group's id.
*
* Outputs:       If the request is accepted returns OK, otherwise returns NOT_OK.
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, SOAD_CODE) SoAd_DisableRouting
(
    SoAd_RoutingGroupIdType GroupId
)
{
    Std_ReturnType ret = E_NOT_OK;

    if(SoAd_Initialized != STD_INITIALIZED)
    {
        /*SWS_SoAd_00627*/
        SOAD_DET_REPORT_ERROR(SOAD_API_DISABLE_ROUTING, SOAD_E_NOTINIT);
    }
    else if(GroupId >= SOAD_GET_ROUTINGGRP_NUM())
    {
        /*SWS_SoAd_00626*/
        SOAD_DET_REPORT_ERROR(SOAD_API_DISABLE_ROUTING, SOAD_E_INV_ARG);
    }
    else
    {
    	SOAD_ENTER_CRITICAL_SECTION_ROUTING_GROUP_IDX();
        SoAd__SetRoutingGroup(GroupId, SOAD_ROUTING_GROUP_DISABLED);
        SOAD_LEAVE_CRITICAL_SECTION_ROUTING_GROUP_IDX();
        ret = E_OK;
    }

    return ret;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: SoAd_DisableSpecificRouting
*
* Description:   Disables routing of a group of PDUs in the SoAd related to the
*                RoutingGroup specified by parameter id only on the socket
*                connection identified by SoConId.
*
* Inputs:        GroupId    - the Routing Group's id.
*                SoConhId   - the SoCon's Id
*
* Outputs:       If the request is accepted returns OK, otherwise returns NOT_OK.
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, SOAD_CODE) SoAd_DisableSpecificRouting
(
    SoAd_RoutingGroupIdType GroupId,
    SoAd_SoConIdType SoConId
)
{
    Std_ReturnType ret = E_NOT_OK;

    if(SoAd_Initialized != STD_INITIALIZED)
    {
        /*SWS_SoAd_00718*/
        SOAD_DET_REPORT_ERROR(SOAD_API_ENABLE_SPECIFIC_ROUTING, SOAD_E_NOTINIT);
    }
    else if(GroupId >= SOAD_GET_ROUTINGGRP_NUM())
    {
        /*SWS_SoAd_00719*/
        SOAD_DET_REPORT_ERROR(SOAD_API_ENABLE_SPECIFIC_ROUTING, SOAD_E_INV_ARG);
    }
    else
    {
    	SOAD_ENTER_CRITICAL_SECTION_ROUTING_GROUP_IDX();
        SoAd__SetSpecificRoutingGroup(GroupId, SoConId, SOAD_ROUTING_GROUP_DISABLED);
        SOAD_LEAVE_CRITICAL_SECTION_ROUTING_GROUP_IDX();
        ret = E_OK;
    }

    return ret;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: SoAd_TpChangeParameter
*
* Description:   By this API service the SoAd or TCP/IP stack is requested to
*                change a connection parameter.
*
* Inputs:        PduId      - the PDU's Id
*                Parameter  - the parameter Id
*                Value      - the parameter's value
*
* Outputs:       If the request is accepted returns OK, otherwise returns NOT_OK.
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, SOAD_CODE) SoAd_TpChangeParameter
(
    PduIdType PduId,
    uint8 Parameter, 
    uint16 Value
)
{
    /* TODO */

    return E_NOT_OK;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: SoAd_ReadDhcpHostNameOption
*
* Description:   By this API service an upper layer of the SoAd can read the
*                currently configured hostname, i.e. FQDN option in the DHCP
*                submodule of the TCP/IP stack.
*
* Inputs:        SoConId    - the SoCon's id.
*                Length     - the buffer length.
*                Data       - the host name's buffer.
*
* Outputs:       If the request is accepted returns OK, otherwise returns NOT_OK.
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, SOAD_CODE) SoAd_ReadDhcpHostNameOption
(
    SoAd_SoConIdType SoConId,
    P2VAR(uint8, AUTOMATIC, SOAD_APPL_DATA) Length,
    P2VAR(uint8, AUTOMATIC, SOAD_APPL_DATA) Data
)
{
    Std_ReturnType ret = E_NOT_OK;

    if(SoAd_Initialized != STD_INITIALIZED)
    {
        /*SWS_SoAd_00701*/
        SOAD_DET_REPORT_ERROR(SOAD_API_READ_DHCP_HOST_NAME_OPTION, SOAD_E_NOTINIT);
    }
    else if(SoConId >= SOAD_GET_SOCON_NUM())
    {
        /*SWS_SoAd_00702*/
        SOAD_DET_REPORT_ERROR(SOAD_API_READ_DHCP_HOST_NAME_OPTION, SOAD_E_INV_ARG);
    }
    else
    {
        P2VAR(SoAd_ConnectionType, AUTOMATIC, AUTOMATIC) connPtr;

        connPtr = SOAD_GET_SOCONCTX_PTR(SoConId);
        if(SOAD_RADDR_IS_VALID_ADDR(connPtr->RemoteAddrState))
        {
            if(TCPIP_AF_INET == connPtr->RemoteAddr.Domain)
            {
                /*SWS_SoAd_00703*/
                ret = TcpIp_DhcpReadOption(connPtr->GroupConfigPtr->LocalAddrId, 81, Length, Data);
            }
#if (SOAD_IPV6_ADDRESS_ENABLED == STD_ON)
            else if(TCPIP_AF_INET6 == connPtr->RemoteAddr.Domain)
            {
                /*SWS_SoAd_00704*/
                ret = TcpIp_DhcpV6ReadOption(connPtr->GroupConfigPtr->LocalAddrId, 39, Length, Data);
            }
            else
            {
                /*nothing*/
            }
#endif
        }
    }

    return ret;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: SoAd_WriteDhcpHostNameOption
*
* Description:   By this API service an upper layer of the SoAd can set the
*                hostname, i.e. FQDN option in the DHCP submodule of the TCP/IP
*                stack.
*
* Inputs:        SoConId    - the SoCon's id.
*                Length     - the buffer length.
*                Data       - the host name's buffer.
*
* Outputs:       If the request is accepted returns OK, otherwise returns NOT_OK.
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, SOAD_CODE) SoAd_WriteDhcpHostNameOption
(
    SoAd_SoConIdType SoConId,
    uint8 Length,
    P2CONST(uint8, AUTOMATIC, SOAD_APPL_DATA) Data
)
{
    Std_ReturnType ret = E_NOT_OK;

    if(SoAd_Initialized != STD_INITIALIZED)
    {
        /*SWS_SoAd_00705*/
        SOAD_DET_REPORT_ERROR(SOAD_API_WRITE_DHCP_HOST_NAME_OPTION, SOAD_E_NOTINIT);
    }
    else if(SoConId >= SOAD_GET_SOCON_NUM())
    {
        /*SWS_SoAd_00706*/
        SOAD_DET_REPORT_ERROR(SOAD_API_WRITE_DHCP_HOST_NAME_OPTION, SOAD_E_INV_ARG);
    }
    else
    {
        P2VAR(SoAd_ConnectionType, AUTOMATIC, AUTOMATIC) connPtr;

        connPtr = SOAD_GET_SOCONCTX_PTR(SoConId);
        if(SOAD_RADDR_IS_VALID_ADDR(connPtr->RemoteAddrState))
        {
            if(TCPIP_AF_INET == connPtr->RemoteAddr.Domain)
            {
                /*SWS_SoAd_00707*/
                ret = TcpIp_DhcpWriteOption(connPtr->GroupConfigPtr->LocalAddrId, 81, Length, Data);
            }
#if (SOAD_IPV6_ADDRESS_ENABLED == STD_ON)
            else if(TCPIP_AF_INET6 == connPtr->RemoteAddr.Domain)
            {
                /*SWS_SoAd_00708*/
                ret = TcpIp_DhcpV6WriteOption(connPtr->GroupConfigPtr->LocalAddrId, 39, Length, Data);
            }
            else
            {
                /*nothing*/
            }
#endif
        }
    }

    return ret;
}

#if (SOAD_VERSION_INFO_API == STD_ON)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: SoAd_GetVersionInfo
*
* Description:   Returns version informations.
*
* Inputs:        VersionInfoPtr    - the buffer of version informations.
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, SOAD_CODE) SoAd_GetVersionInfo
(
    P2VAR(Std_VersionInfoType, AUTOMATIC, SOAD_APPL_DATA) VersionInfoPtr
)
{
    VersionInfoPtr->vendorID = SOAD_VENDOR_ID;
    VersionInfoPtr->moduleID = SOAD_MODULE_ID;
    VersionInfoPtr->sw_major_version = SOAD_SW_MAJOR_VERSION;
    VersionInfoPtr->sw_minor_version = SOAD_SW_MINOR_VERSION;
    VersionInfoPtr->sw_patch_version = SOAD_SW_PATCH_VERSION;
}
#endif

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: SoAd_MainFunction
*
* Description:   The main function for SoAd module.
*
* Inputs:        None
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, SOAD_CODE) SoAd_MainFunction
(
    void
)
{
    SoAd_SoConIdType i;
    SoAd_SoConIdType soConNum = SOAD_GET_SOCON_NUM();
    SoAd_PduRouteIdType pduRouteId;
    SoAd_PduRouteIdType pduRouteNum = SOAD_GET_PDUROUTE_NUM();
    boolean offline;
    P2CONST(SoAd_PduRouteDestType, AUTOMATIC, AUTOMATIC) pduRouteDestPtr;


    if(SoAd_Initialized != STD_INITIALIZED)
    {
        /*SWS_SoAd_00283*/
        SOAD_DET_REPORT_ERROR(SOAD_API_MAIN_FUNCTION, SOAD_E_NOTINIT);
    }
    else
    {
        /*Close or open the socket connections*/
        for(i = 0; i < soConNum; i++)
        {
            P2VAR(SoAd_ConnectionType, AUTOMATIC, AUTOMATIC) connPtr = SOAD_GET_SOCONCTX_PTR(i);

            if(SOAD_SOCON_IS_CLOSE(connPtr))
            {
                if(SOAD_SOCON_IS_CLOSE_REQUEST(connPtr))
                {
                    offline = TRUE;
                }
                else
                {
                    offline = FALSE;
                }

                /* Clear the Close request and Close event*/
                SOAD_SOCON_CLEAR_CLOSE(connPtr);

                /*SWS_SoAd_00604*/
                if(!SOAD_SOCON_IS_OFFLINE(connPtr))
                {
                    /*SWS_SoAd_00637*/
                    SoAd__CloseSoCon(connPtr, offline);
                }
            }
            else if(SOAD_SOCON_IS_OPEN_REQUEST(connPtr))
            {
                /*SWS_SoAd_00589*/
                if(!SOAD_SOCON_IS_ONLINE(connPtr)
                    && !SOAD_SOCON_IS_VALID_SOCKETID(connPtr)
                    && SOAD_RADDR_IS_VALID_ADDR(connPtr->RemoteAddrState)
                    && SOAD_SOCON_IS_ASSIGNED_IPADDR(connPtr))
                {
                    SOAD_SOCON_CLEAR_OPEN(connPtr);
                    SoAd__OpenSoCon(connPtr);
                }
            }
            else
            {
                /*Do nothing*/
            }

            /*Check if the timer used for nPduUdpTxBuffer is timedout.*/
            if(SOAD_IFTX_IS_STARTED_UDPTIMER(&connPtr->TxSession))
            {
                P2VAR(SoAd_TxSessionType, AUTOMATIC, AUTOMATIC) sessionPtr = &connPtr->TxSession;

                if(SoAd__StartTxSession(connPtr, SOAD_SESSION_STATE_TRIGGER) == E_OK) /* cp692(1) */
                {
                	SOAD_ENTER_CRITICAL_SECTION_TX_SESSION_IDX();
                    SOAD_IFTX_DECREASE_UDPTIMER(sessionPtr);
                    /*SWS_SoAd_00550*/
                    if(SOAD_IFTX_IS_UDPTIMEDOUT(sessionPtr) && (sessionPtr->BufferOffset > 0))
                    {
                        P2VAR(TcpIp_SockAddrType, AUTOMATIC, AUTOMATIC) remoteAddrPtr;

                        remoteAddrPtr = (P2VAR(TcpIp_SockAddrType, AUTOMATIC, AUTOMATIC))&connPtr->RemoteAddr;
                        (void)TcpIp_UdpTransmit(connPtr->SocketId, sessionPtr->UdpTxBuffer, remoteAddrPtr, sessionPtr->BufferOffset);
                        sessionPtr->BufferOffset = 0;
                    }
                    SOAD_LEAVE_CRITICAL_SECTION_TX_SESSION_IDX();

                    SoAd__StopTxSession(connPtr);
                }
            }

            if(SoAd__IsTxSession(connPtr, SOAD_SESSION_STATE_TP) == E_OK)
            {
                SoAd__TpTxProcess(connPtr);
            }

            /*SWS_SoAd_00574*/
            if(SoAd__IsTpRxBufferEmpty(connPtr) != E_OK)
            {
                SoAd__TpRxProcess(connPtr);
            }
        }

        for(pduRouteId = 0; pduRouteId < pduRouteNum; pduRouteId++)
        {
        	P2CONST(SoAd_PduRouteType, AUTOMATIC, AUTOMATIC) pduRoutePtr = SOAD_GET_PDUROUTE_PTR(pduRouteId);
            if(SOAD_PDUROUTE_IS_IF(pduRoutePtr))
            {
                
            	SOAD_ENTER_CRITICAL_SECTION_TX_UNCONFIRM_IDX();

            	/*all the socons of a pduroute must be same transmit protocol: TCP or UDP*/
            	pduRouteDestPtr = SOAD_GET_PDUROUTE_DEST_PTR(pduRoutePtr->RouteDestId);

				/*PduRoute IF TxConfirm*/ /*SWS_SoAd_00544*/
				if((SOAD_IFTX_GET_UNCONFIRMED(SOAD_GET_IFTXUNCONFIRMED_PTR(pduRouteId)) > 0)
					&& (SOAD_SOCON_IS_UDP(SOAD_GET_SOCONCTX_PTR(pduRouteDestPtr->SoConId))))
				{
					SOAD_IFTX_CLEAR_UNCONFIRMED(SOAD_GET_IFTXUNCONFIRMED_PTR(pduRouteId));
					
					SOAD_LEAVE_CRITICAL_SECTION_TX_UNCONFIRM_IDX();
					SoAd__CallUpIfTxConfirmation(SOAD_GET_PDUROUTE_PTR(pduRouteId));
				}
				else
				{
					SOAD_LEAVE_CRITICAL_SECTION_TX_UNCONFIRM_IDX();
				}
                SoAd__IfTriggerTransmitProcess(SOAD_GET_PDUROUTE_PTR(pduRouteId));
            }
        }
    }
}

/******************************************************************************
*   Callback Function Define
******************************************************************************/
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: SoAd_RxIndication
*
* Description:   The TCP/IP stack calls this primitive after the reception of
*                data on a socket.
*
* Inputs:        SocketId       - the socket id for reception.
*                RemoteAddrPtr  - the remote address of the peer.
*                DataPtr        - the buffer of received data.
*                DataLength     - the length of received data.
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, SOAD_CODE) SoAd_RxIndication
(
    TcpIp_SocketIdType SocketId,
    P2CONST(TcpIp_SockAddrType, AUTOMATIC, SOAD_APPL_DATA) RemoteAddrPtr,
    P2VAR(uint8, AUTOMATIC, SOAD_APPL_DATA) DataPtr,
    uint16 DataLength
)
{
    P2VAR(SoAd_ConnectionType, AUTOMATIC, AUTOMATIC) connPtr;
    SoAd_SoConIdType soConId;

    if(SoAd_Initialized != STD_INITIALIZED)
    {
        /*SWS_SoAd_00264*/
        SOAD_DET_REPORT_ERROR(SOAD_API_RX_INDICATION, SOAD_E_NOTINIT);
    }
    else if(0 == DataLength)
    {
        /*SWS_SoAd_00562(3)*/
    }
    else if((NULL_PTR == RemoteAddrPtr) || (NULL_PTR == DataPtr))
    {
        /*discard data*/ /*SWS_SoAd_00268*/
        SOAD_DET_REPORT_ERROR(SOAD_API_RX_INDICATION, SOAD_E_INV_ARG);
    }
    /*SWS_SoAd_00562(1)*/
    else if(SoAd__FindConnBySocketId(SocketId, &soConId) != E_OK)
    {
        /*discard data.*/   /*SWS_SoAd_00267*/
        SOAD_DET_REPORT_ERROR(SOAD_API_RX_INDICATION, SOAD_E_INV_SOCKETID);
    }
    else if(SOAD_SOCON_IS_UDP(SOAD_GET_SOCONCTX_PTR(soConId)))
    {
        P2CONST(SoAd_RemoteAddressType, AUTOMATIC, AUTOMATIC) remoteAddrPtr;

        remoteAddrPtr = (P2CONST(SoAd_RemoteAddressType, AUTOMATIC, AUTOMATIC))RemoteAddrPtr;

        if(SoAd__CheckRemoteAddressState(remoteAddrPtr) != SOAD_REMOTE_ADDRESS_SET)
        {
            SOAD_DET_REPORT_ERROR(SOAD_API_RX_INDICATION, SOAD_E_INV_ARG);
        }
        else
        {
            connPtr = SOAD_GET_SOCONCTX_PTR(soConId);
            if(SOAD_SOCON_IS_SHARED_SOCKET(connPtr))
            {
                /*SWS_SoAd_00657*/
                if(SoAd__FindConnByRemoteAddr(connPtr->GroupConfigPtr, remoteAddrPtr, &soConId) == E_OK)
                {
                    /**/
                    connPtr = SOAD_GET_SOCONCTX_PTR(soConId);

                    SOAD_ENTER_CRITICAL_SECTION_SOCON_MODE_IDX();
                    if(!SOAD_SOCON_IS_ONLINE(connPtr))
                    {
                        /*SWS_SoAd_00592*/
                        SoAd__SetRemoteAddress(connPtr, remoteAddrPtr, SOAD_REMOTE_ADDRESS_SET);
                        SoAd__SoConModeChg(connPtr, SOAD_SOCON_ONLINE);

                        /* SWS_SoAd_00595 */
                        if(SoAd__StartTpReceptionWithoutPduHeader(connPtr) != E_OK)
                        { 
                            SOAD_ENTER_CRITICAL_SECTION_SOCON_MODE_IDX();
                            /*SWS_SoAd_00570*/
                            SOAD_SOCON_CLEAR_SOCKETID(connPtr);
                            SOAD_SOCON_SET_CLOSE_EVENT(connPtr);
                            SOAD_LEAVE_CRITICAL_SECTION_SOCON_MODE_IDX();

                            connPtr = NULL_PTR;
                        }
                    }
                    SOAD_LEAVE_CRITICAL_SECTION_SOCON_MODE_IDX();
                }
                else
                {
                    connPtr = NULL_PTR;
                }
            }
            /*SWS_SoAd_00562(2)*/
            else if(SOAD_SOCON_IS_MAF_ENABLED(connPtr))
            {
                /*SWS_SoAd_00524*/ /*SWS_SoAd_00525*/
                SOAD_ENTER_CRITICAL_SECTION_SOCON_MODE_IDX();
                if(!SOAD_RADDR_IS_IP_ANY(connPtr->RemoteAddrState)
                    && (SoAd__IsMatchedIpAddress(&connPtr->RemoteAddr, remoteAddrPtr) != E_OK))
                {
                    connPtr = NULL_PTR;
                }
                else if(!SOAD_RADDR_IS_PORT_ANY(connPtr->RemoteAddrState)
                        && !SOAD_RADDR_IS_MATCHED_PORT(&connPtr->RemoteAddr, remoteAddrPtr))
                {
                    connPtr = NULL_PTR;
                }
                /*matched IP address*/
                else if(!SOAD_SOCON_IS_ONLINE(connPtr))
                {
                    /*SWS_SoAd_00592*/
                    SoAd__SetRemoteAddress(connPtr, remoteAddrPtr, SOAD_REMOTE_ADDRESS_SET);
                    SoAd__SoConModeChg(connPtr, SOAD_SOCON_ONLINE);
                    /* SWS_SoAd_00595 */
                    if(SoAd__StartTpReceptionWithoutPduHeader(connPtr) != E_OK)
                    {
                        
                        SOAD_ENTER_CRITICAL_SECTION_SOCON_MODE_IDX();
                        /*SWS_SoAd_00570*/
                        SOAD_SOCON_CLEAR_SOCKETID(connPtr);
                        SOAD_SOCON_SET_CLOSE_EVENT(connPtr);
                        SOAD_LEAVE_CRITICAL_SECTION_SOCON_MODE_IDX();

                        connPtr = NULL_PTR;
                    }
                }
                else
                {
                    /*nothing*/
                }
                SOAD_LEAVE_CRITICAL_SECTION_SOCON_MODE_IDX();
            }
            else
            {
                /*SWS_SoAd_00635*/
                /*we do not update the remote address of socket connection found by SocketId.*/
            }

            if(connPtr != NULL_PTR)
            {
                if((SoAd__UdpRxIndication(connPtr, DataPtr, DataLength) != E_OK))
                {
                    /*SWS_SoAd_00710*/
                    SOAD_ENTER_CRITICAL_SECTION_SOCON_MODE_IDX();
                    SOAD_RADDR_SET_DEFAULT_ADDRESS(connPtr);
                    SoAd__SoConModeChg(connPtr, SOAD_SOCON_RECONN);
                    SOAD_LEAVE_CRITICAL_SECTION_SOCON_MODE_IDX();
                }
            }
        }
    }
    else /*SOAD_SOCON_IS_TCP(connPtr)*/
    {
        uint16 receivedLength;

        connPtr = SOAD_GET_SOCONCTX_PTR(soConId);
        receivedLength = SoAd__TcpRxIndication(connPtr, DataPtr, DataLength);
        if(receivedLength > 0)
        {
            /*SWS_SoAd_00564*/
            (void)TcpIp_TcpReceived(SocketId, receivedLength);
        }
    }
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: SoAd_CopyTxData
*
* Description:   This service requests to copy data for transmission to the buffer
*                indicated. This call is triggered by TcpIp_Transmit().
*                Note: The call to <Up>_CopyTxData() may happen in the context of
*                TcpIp_Transmit().
*
* Inputs:        SocketId       - the socket id for reception.
*                BufferPtr      - the buffer of tx data.
*                BufferLength   - the length of tx data.
*
* Outputs:       If the tx data were copied to buffer returns BUFREQ_E_OK, otherwise
*                returns BUFREQ_E_NOT_OK.
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(BufReq_ReturnType, SOAD_CODE) SoAd_CopyTxData
(
    TcpIp_SocketIdType SocketId,
    P2VAR(uint8, AUTOMATIC, SOAD_APPL_DATA) BufferPtr,
    uint16 BufferLength
)
{
    BufReq_ReturnType ret = BUFREQ_E_NOT_OK;
    P2VAR(SoAd_ConnectionType, AUTOMATIC, AUTOMATIC) connPtr = NULL_PTR;
    P2VAR(uint8, AUTOMATIC, AUTOMATIC) TempBuffPtr = NULL_PTR;
    P2VAR(SoAd_TxSessionType, AUTOMATIC, AUTOMATIC) sessionPtr = NULL_PTR;
    SoAd_SoConIdType soConId;
    boolean WithHeader = FALSE;

    if(SoAd_Initialized != STD_INITIALIZED)
    {
        /*SWS_SoAd_00632*/
        SOAD_DET_REPORT_ERROR(SOAD_API_COPY_TX_DATA, SOAD_E_NOTINIT);
    }
    else if(SoAd__FindConnBySocketId(SocketId, &soConId) != E_OK)
    {
        /*SWS_SoAd_00633*/
        SOAD_DET_REPORT_ERROR(SOAD_API_COPY_TX_DATA, SOAD_E_INV_SOCKETID);
    }
    else if((SoAd__IsTxSession(SOAD_GET_SOCONCTX_PTR(soConId), SOAD_SESSION_STATE_IF) == E_OK)
            || (SoAd__IsTxSession(SOAD_GET_SOCONCTX_PTR(soConId), SOAD_SESSION_STATE_TP) == E_OK))
    {
        connPtr = SOAD_GET_SOCONCTX_PTR(soConId);
        sessionPtr = &connPtr->TxSession;
        TempBuffPtr = BufferPtr;
    }
    else
    {
        /*nothing*/
    }

    if((connPtr != NULL_PTR) && (sessionPtr->TotalTxLength > sessionPtr->UsedTxLength))
    {
        uint16 length;
        SoAd_PduRouteIdType pduRouteId;
        PduInfoType pdu;
        if(sessionPtr->PduRouteDestPtr == NULL_PTR)
        {
            SOAD_DET_REPORT_ERROR_RET(SOAD_API_COPY_TX_DATA, SOAD_E_INV_ARG, BUFREQ_E_NOT_OK)
        }

        length = SOAD_MIN_LEN(sessionPtr->TotalTxLength - sessionPtr->UsedTxLength, BufferLength);
        pduRouteId = sessionPtr->PduRouteDestPtr->PduRouteId;

        if(SOAD_SOCON_IS_PDUHEADER_ENABLED(connPtr) && (0 == sessionPtr->UsedTxLength))
        {
            if(length >= SOAD_PDUHEADER_LENGTH)
            {
                SoAd__SerializePduHeader(sessionPtr->PduRouteDestPtr->TxPduHeaderId,
                                            sessionPtr->TotalTxLength - SOAD_PDUHEADER_LENGTH,
                                            TempBuffPtr);
                
                length -= SOAD_PDUHEADER_LENGTH;
                TempBuffPtr = &BufferPtr[SOAD_PDUHEADER_LENGTH];
                WithHeader = TRUE;

                SOAD_ENTER_CRITICAL_SECTION_TX_SESSION_IDX();
                sessionPtr->UsedTxLength += SOAD_PDUHEADER_LENGTH;
                SOAD_LEAVE_CRITICAL_SECTION_TX_SESSION_IDX();

                ret = BUFREQ_OK;
            }
            else
            {
                length = 0;
            }
        }

        if(0 == length)
        {
            /*only copy a PduHeader or length < SOAD_PDUHEADER_LENGTH*/
        }
        else if(SOAD_PDUROUTE_IS_TP(SOAD_GET_PDUROUTE_PTR(pduRouteId)))
        {
            RetryInfoType retry = {TP_DATACONF, 0};
            PduLengthType dummy;
            pdu.SduDataPtr = BufferPtr;
            pdu.SduLength = length;
            /*SWS_SoAd_00556*/ /*SWS_SoAd_00543*/
            ret = SoAd__CallUpCopyTxData(SOAD_GET_PDUROUTE_PTR(pduRouteId), &pdu, &retry, &dummy);

            if(BUFREQ_OK == ret)
            {
                SOAD_ENTER_CRITICAL_SECTION_TX_SESSION_IDX();
                sessionPtr->UsedTxLength += length;
                SOAD_LEAVE_CRITICAL_SECTION_TX_SESSION_IDX();
            }
            else if(SOAD_SOCON_IS_TCP(connPtr))
            {
                /*SWS_SoAd_00651*/
                SoAd__CancelTxSession(connPtr);
                SOAD_SOCON_SET_CLOSE_EVENT(connPtr);
            }
            else
            {
                /*nothing*/
            }
        }
        else if(sessionPtr->IfTxDataBuffer != NULL_PTR)
        {
            /*SWS_SoAd_00543*/
            SOAD_ENTER_CRITICAL_SECTION_TX_SESSION_IDX();
            SoAd__CopyIfTxData(sessionPtr, length, TempBuffPtr, WithHeader);
            SOAD_LEAVE_CRITICAL_SECTION_TX_SESSION_IDX();

            ret = E_OK;
        }
        else
        {
            /*nothing*/
        }
    }

    return ret;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: SoAd_TxConfirmation
*
* Description:   The TCP/IP stack calls this function after the data has been
*                acknowledged by the peer for TCP.
*
* Inputs:        SocketId   - the socket id for listen.
*                uint16     - number of transmitted data bytes.
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, SOAD_CODE) SoAd_TxConfirmation
(
    TcpIp_SocketIdType SocketId,
    uint16 Length
)
{
    P2VAR(SoAd_ConnectionType, AUTOMATIC, AUTOMATIC) connPtr = NULL_PTR;
    P2VAR(SoAd_TxSessionType, AUTOMATIC, AUTOMATIC) sessionPtr = NULL_PTR;
    SoAd_SoConIdType soConId;

    if(SoAd_Initialized != STD_INITIALIZED)
    {
        /*SWS_SoAd_00269*/
        SOAD_DET_REPORT_ERROR(SOAD_API_TX_CONFIRMATION, SOAD_E_NOTINIT);
    }
    else if(0 == Length)
    {
        /*SWS_SoAd_00271*/
        SOAD_DET_REPORT_ERROR(SOAD_API_TX_CONFIRMATION, SOAD_E_INV_ARG);
    }
    else if(SoAd__FindConnBySocketId(SocketId, &soConId) != E_OK)
    {
        /*SWS_SoAd_00270*/
        SOAD_DET_REPORT_ERROR(SOAD_API_TX_CONFIRMATION, SOAD_E_INV_SOCKETID);
    }
    else if(SOAD_SOCON_IS_UDP(SOAD_GET_SOCONCTX_PTR(soConId)))
    {
        SOAD_DET_REPORT_ERROR(SOAD_API_TX_CONFIRMATION, SOAD_E_INV_ARG);
    }
    else if(SOAD_SOCON_IS_TCP_IMMTPTXCONFIRM(SOAD_GET_SOCONCTX_PTR(soConId)))
    {
        /*SWS_SoAd_00558*/
    }
    else
    {
        connPtr = SOAD_GET_SOCONCTX_PTR(soConId);
        sessionPtr = &connPtr->TxSession;
        
        if(sessionPtr->PduRouteDestPtr != NULL_PTR)
        {
            /*SOAD_PDUROUTE_IS_TP*/
            SoAd_PduRouteIdType pduRouteId;
            P2CONST(SoAd_PduRouteType, SOAD_CONFIG_DATA, AUTOMATIC) pduRoutePtr;
            P2VAR(SoAd_IfTxUnconfirmedType, SOAD_CONFIG_DATA, AUTOMATIC) unconfirmedPtr;

            pduRouteId = sessionPtr->PduRouteDestPtr->PduRouteId;
            pduRoutePtr = SOAD_GET_PDUROUTE_PTR(pduRouteId);
            unconfirmedPtr = SOAD_GET_IFTXUNCONFIRMED_PTR(pduRouteId);

            if(!SOAD_PDUROUTE_IS_TP(pduRoutePtr))
            {
                SOAD_DET_REPORT_ERROR(SOAD_API_TX_CONFIRMATION, SOAD_E_INV_CONFIG_DATA);
            }
            else
            {
                if(SoAd__IsTxSession(connPtr, SOAD_SESSION_STATE_TP) != E_OK)
                {
                    /*IF*/
                }
                /*TP*/
                else if(SOAD_IFTX_GET_UNCONFIRMED(unconfirmedPtr) >= Length)
                {
                    SOAD_ENTER_CRITICAL_SECTION_TX_UNCONFIRM_IDX();
                    SOAD_IFTX_DECREASE_UNCONFIRMED(unconfirmedPtr, Length);
                    SOAD_LEAVE_CRITICAL_SECTION_TX_UNCONFIRM_IDX();
                    if((SOAD_IFTX_GET_UNCONFIRMED(unconfirmedPtr) == 0)
                        && (sessionPtr->TotalTxLength == sessionPtr->UsedTxLength))
                    {
                        SoAd__StopTxSession(connPtr);
                        SoAd__CallUpTpTxConfirmation(pduRoutePtr, E_OK);  
                    }
                }
                else
                {
                    /*SWS_SoAd_00271*/
                    SOAD_DET_REPORT_ERROR(SOAD_API_TX_CONFIRMATION, SOAD_E_INV_ARG);
                }
            }
        }
        else
        {
            /*SOAD_PDUROUTE_IS_IF*/
            SoAd_PduRouteIdType pduRouteId;
            SoAd_PduRouteIdType i;
            P2VAR(SoAd_IfTxUnconfirmedType, SOAD_CONFIG_DATA, AUTOMATIC) unconfirmedPtr;
            uint16 unconfirmedLen;
            uint16 tmp;
            
            SOAD_ENTER_CRITICAL_SECTION_TX_UNCONFIRM_IDX();
            for(i = 0; i < connPtr->ConfigPtr->PduRouteNum; i++)
            {
                pduRouteId = connPtr->ConfigPtr->PduRouteList[i];

                unconfirmedPtr = SOAD_GET_IFTXUNCONFIRMED_PTR(pduRouteId);

                unconfirmedLen = SOAD_IFTX_GET_UNCONFIRMED(unconfirmedPtr);
                tmp = SOAD_MIN_LEN(unconfirmedLen, Length);
                SOAD_IFTX_DECREASE_UNCONFIRMED(unconfirmedPtr, tmp);

                if((unconfirmedLen - tmp) == 0)
                {
                	SOAD_LEAVE_CRITICAL_SECTION_TX_UNCONFIRM_IDX();
                    /*SWS_SoAd_00545*/
                    SoAd__CallUpIfTxConfirmation(SOAD_GET_PDUROUTE_PTR(pduRouteId));
                    
                    SOAD_ENTER_CRITICAL_SECTION_TX_UNCONFIRM_IDX();
                }

                Length -= tmp;
                if(Length == 0)
                {
                    break;
                }
            }
            SOAD_LEAVE_CRITICAL_SECTION_TX_UNCONFIRM_IDX();
        }
    }
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: SoAd_TcpAccepted
*
* Description:   The TCP/IP stack calls this function after a socket was set into
*                the listen state with TcpIp_TcpListen() and a TCP connection is
*                requested by the peer.
*
* Inputs:        SocketId           - the socket id for listen.
*                SocketIdConnected  - the socket id of the peer
*                RemoteAddrPtr      - the remote address of the peer
*
* Outputs:       If SocketIdConnected is accepted returns E_OK, otherwise returns
*                E_NOT_OK.
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, SOAD_CODE) SoAd_TcpAccepted
(
    TcpIp_SocketIdType SocketId,
    TcpIp_SocketIdType SocketIdConnected,
    P2CONST(TcpIp_SockAddrType, AUTOMATIC, SOAD_APPL_DATA) RemoteAddrPtr
)
{
    P2CONST(SoAd_RemoteAddressType, AUTOMATIC, AUTOMATIC) remoteAddrPtr;
    P2VAR(SoAd_ConnectionType, AUTOMATIC, AUTOMATIC) connPtr;
    SoAd_SoConIdType soConId;
    SoAd_SoConGroupIdType groupId;
    Std_ReturnType ret = E_NOT_OK;

    remoteAddrPtr = (P2CONST(SoAd_RemoteAddressType, AUTOMATIC, AUTOMATIC))RemoteAddrPtr;
    if(SoAd_Initialized != STD_INITIALIZED)
    {
        /*SWS_SoAd_00272*/
        SOAD_DET_REPORT_ERROR(SOAD_API_TCP_ACCEPTED, SOAD_E_NOTINIT);
    }
    else if(SoAd__FindSoConGroupBySocketId(SocketId, &groupId) != E_OK)
    {
        /*SWS_SoAd_00273*/
        SOAD_DET_REPORT_ERROR(SOAD_API_TCP_ACCEPTED, SOAD_E_INV_SOCKETID);
    }
    /*SWS_SoAd_00594(1)*/
    else if(SoAd__FindConnByRemoteAddr(SOAD_GET_SOCON_GROUP_PTR(groupId), remoteAddrPtr, &soConId) != E_OK)
    {
        /*nothing*/
    }
    else
    {    
        if(SoAd__CheckRemoteAddressState(remoteAddrPtr) != SOAD_REMOTE_ADDRESS_SET)
        {
            SOAD_DET_REPORT_ERROR_RET(SOAD_API_TCP_ACCEPTED, SOAD_E_INV_ARG, E_NOT_OK);
        }

        connPtr = SOAD_GET_SOCONCTX_PTR(soConId);
        
        SOAD_ENTER_CRITICAL_SECTION_SOCON_MODE_IDX();
        /*SWS_SoAd_00594(2)*/
        SoAd__SetRemoteAddress(connPtr, remoteAddrPtr, SOAD_REMOTE_ADDRESS_SET);
        /*SWS_SoAd_00594(3)*/
        SOAD_SOCON_SET_SOCKETID(connPtr, SocketIdConnected);
        /*SWS_SoAd_00594(4)*/
        SoAd__SoConModeChg(connPtr, SOAD_SOCON_ONLINE);
        
        SOAD_LEAVE_CRITICAL_SECTION_SOCON_MODE_IDX();
        /*SWS_SoAd_00595*/
        ret = SoAd__StartTpReceptionWithoutPduHeader(connPtr);
        if(ret != E_OK)
        {
            
        	SOAD_ENTER_CRITICAL_SECTION_SOCON_MODE_IDX();
            /*SWS_SoAd_00570*/
            SOAD_SOCON_CLEAR_SOCKETID(connPtr);
            SOAD_SOCON_SET_CLOSE_EVENT(connPtr);
            
            SOAD_LEAVE_CRITICAL_SECTION_SOCON_MODE_IDX();
        }
    }

    return ret;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: SoAd_TcpConnected
*
* Description:   The TCP/IP stack calls this function after a socket was
*                requested to connect with TcpIp_TcpConnect() and a TCP
*                connection is confirmed by the peer.
*
* Inputs:        SocketId   - the socket id of the peer.
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, SOAD_CODE) SoAd_TcpConnected
(
    TcpIp_SocketIdType SocketId
)
{
    SoAd_SoConIdType soConId;
    P2VAR(SoAd_ConnectionType, AUTOMATIC, AUTOMATIC) connPtr;

    if(SoAd_Initialized != STD_INITIALIZED)
    {
        /*SWS_SoAd_00274*/
        SOAD_DET_REPORT_ERROR(SOAD_API_TCP_CONNECTED, SOAD_E_NOTINIT);
    }
    else if(SoAd__FindConnBySocketId(SocketId, &soConId) != E_OK)
    {
        /*SWS_SoAd_00275*/
        SOAD_DET_REPORT_ERROR(SOAD_API_TCP_CONNECTED, SOAD_E_INV_SOCKETID);
    }
    /*SWS_SoAd_00593*/
    else if(SOAD_SOCON_IS_TCP_SERVER(SOAD_GET_SOCONCTX_PTR(soConId)))
    {
        /*nothing*/
    }
    else
    {
        connPtr = SOAD_GET_SOCONCTX_PTR(soConId);
        /*(void)SoAd__SetSoConOnline(ConnPtr);*/
        SOAD_ENTER_CRITICAL_SECTION_SOCON_MODE_IDX();
        SoAd__SoConModeChg(connPtr, SOAD_SOCON_ONLINE);
        /*SWS_SoAd_00595*/
        if(SoAd__StartTpReceptionWithoutPduHeader(connPtr) != E_OK)
        {
            /*SWS_SoAd_00570*/
            SOAD_SOCON_CLEAR_SOCKETID(connPtr);
            SOAD_SOCON_SET_CLOSE_EVENT(connPtr);
        }
        SOAD_LEAVE_CRITICAL_SECTION_SOCON_MODE_IDX();
    }

}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: SoAd_TcpIpEvent
*
* Description:   This service gets called if the stack encounters a condition
*                described by the values in Event.
*
* Inputs:        SocketId   - the socket id of the peer.
*                Event      - the TcpIp event
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, SOAD_CODE) SoAd_TcpIpEvent
(
    TcpIp_SocketIdType SocketId,
    TcpIp_EventType Event
)
{
    SoAd_SoConIdType soConId;

    if(SoAd_Initialized != STD_INITIALIZED)
    {
        /*SWS_SoAd_00276*/
        SOAD_DET_REPORT_ERROR(SOAD_API_TCPIP_EVENT, SOAD_E_NOTINIT);
    }
    else if(SoAd__FindConnBySocketId(SocketId, &soConId) != E_OK)
    {
        SoAd_SoConGroupIdType groupId;

        if(SoAd__FindSoConGroupBySocketId(SocketId, &groupId) != E_OK)
        {
            /*SWS_SoAd_00277*/
            SOAD_DET_REPORT_ERROR(SOAD_API_TCPIP_EVENT, SOAD_E_INV_SOCKETID);
        }
        else if(Event != TCPIP_TCP_CLOSED)
        {
            /*SWS_SoAd_00278*/
            SOAD_DET_REPORT_ERROR(SOAD_API_TCPIP_EVENT, SOAD_E_INV_ARG);
        }
        else
        {
            /*SWS_SoAd_00645*/
            
        	SOAD_ENTER_CRITICAL_SECTION_SHARED_SOCKET_IDX();
            SOAD_CLEAR_SHARED_SOCKETID(groupId);
            SOAD_LEAVE_CRITICAL_SECTION_SHARED_SOCKET_IDX();
        }
    }
    else
    {
        P2VAR(SoAd_ConnectionType, AUTOMATIC, AUTOMATIC) connPtr;
        P2CONST(SoAd_SocketConnectionGroupType, SOAD_CONFIG_DATA, AUTOMATIC) groupPtr;

        connPtr = SOAD_GET_SOCONCTX_PTR(soConId);
        groupPtr = connPtr->GroupConfigPtr;
        switch (Event)
        {
            /*SWS_SoAd_00646*/
            case TCPIP_TCP_RESET :
            case TCPIP_TCP_CLOSED :
            	SOAD_ENTER_CRITICAL_SECTION_SOCON_MODE_IDX();
                if(SOAD_SOCON_IS_TCP(connPtr)) /* cp_725 */
                {
                    SOAD_SOCON_CLEAR_SOCKETID(connPtr);
                    SOAD_SOCON_SET_CLOSE_EVENT(connPtr);
                }
                else
                {
                    SOAD_DET_REPORT_ERROR(SOAD_API_TCPIP_EVENT, SOAD_E_INV_SOCKETID);
                }
                SOAD_LEAVE_CRITICAL_SECTION_SOCON_MODE_IDX();
                break;
            /*SWS_SoAd_00688*/
            case TCPIP_TCP_FIN_RECEIVED :
             if(SOAD_SOCON_IS_TCP(connPtr)) /* cp_725 */
                {
                    (void)TcpIp_Close(connPtr->SocketId, FALSE);
                }
                 else
                {
                    SOAD_DET_REPORT_ERROR(SOAD_API_TCPIP_EVENT, SOAD_E_INV_SOCKETID);
                }
                break;
            case TCPIP_UDP_CLOSED :
            if(SOAD_SOCON_IS_UDP(connPtr)) /* cp_725 */
                {
                    /*SWS_SoAd_00643*/
                    SoAd__CloseUdpSoConGroup(groupPtr);
                }
                else
                {
                    SOAD_DET_REPORT_ERROR(SOAD_API_TCPIP_EVENT, SOAD_E_INV_SOCKETID);
                }
                break;
            default :
                /*SWS_SoAd_00278*/
                SOAD_DET_REPORT_ERROR(SOAD_API_TCPIP_EVENT, SOAD_E_INV_ARG);
                break;
        }
    }
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: SoAd_LocalIpAddrAssignmentChg
*
* Description:   This service gets called by the TCP/IP stack if an IP address
*                assignment changes.
*
* Inputs:        IpAddrId   - the Id of Local IP address.
*                State      - the State of Local IP address.
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, SOAD_CODE) SoAd_LocalIpAddrAssignmentChg
(
    TcpIp_LocalAddrIdType IpAddrId,
    TcpIp_IpAddrStateType State
)
{
    SoAd_SoConGroupIdType groupId;
    P2CONST(SoAd_SocketConnectionGroupType, SOAD_CONFIG_DATA, AUTOMATIC) groupPtr;

    if(SoAd_Initialized != STD_INITIALIZED)
    {
        /*SWS_SoAd_00279*/
        SOAD_DET_REPORT_ERROR(SOAD_API_LOCAL_IPADDR_ASSIGNMENT_CHG, SOAD_E_NOTINIT);
    }
    else if(State == SOAD_GET_LOCAL_IPADDR_STATE(IpAddrId))
    {
        /*nothing*/
    }
    else
    {
        uint8 result = 0;
        SOAD_SET_LOCAL_IPADDR_STATE(IpAddrId, State);
        
        for(groupId = 0; groupId < SOAD_GET_SOCON_GROUP_NUM(); groupId++)
        {
            groupPtr = SOAD_GET_SOCON_GROUP_PTR(groupId);
            if(groupPtr->LocalAddrId == IpAddrId)
            {
                result = 1;
                /*SWS_SoAd_00598*/
                SoAd__LocalIpAddrAssignmentChg(groupPtr, State);
            }
        }

        if(result != 1)
        {
            /*SWS_SoAd_00280*/
            SOAD_DET_REPORT_ERROR(SOAD_API_LOCAL_IPADDR_ASSIGNMENT_CHG, SOAD_E_INV_ARG);
        }
    }
}

/******************************************************************************
*   Local Function Define
******************************************************************************/
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: SoAd__InitConnection
*
* Description:   Initializes the runtime context of socket connection.
*
* Inputs:        SoConId    - the socket connection id.
*                GroupPtr   - the pointer of socket connection group.
*                SoConPtr   - the socket connection will be initialized.
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, SOAD_CODE) SoAd__InitConnection
(
    SoAd_SoConIdType SoConId,
    P2CONST(SoAd_SocketConnectionGroupType, AUTOMATIC, AUTOMATIC) GroupPtr,
    P2CONST(SoAd_SocketConnectionType, AUTOMATIC, AUTOMATIC) SoConPtr
)
{
    P2VAR(SoAd_ConnectionType, AUTOMATIC, AUTOMATIC) ConnPtr;

    if(GroupPtr == NULL_PTR)
    {
        SOAD_DET_REPORT_ERROR(SOAD_API_INTERNAL, SOAD_E_PARAM_POINTER);
    }
    else if(SoConPtr == NULL_PTR)
    {
        SOAD_DET_REPORT_ERROR(SOAD_API_INTERNAL, SOAD_E_PARAM_POINTER);
    }
    else if(GroupPtr->SoConId > SoConId)
    {
        SOAD_DET_REPORT_ERROR(SOAD_API_INTERNAL, SOAD_E_INV_ARG);
    }
    else if(SoConId >= (GroupPtr->SoConNum + GroupPtr->SoConId))
    {
        SOAD_DET_REPORT_ERROR(SOAD_API_INTERNAL, SOAD_E_INV_ARG);
    }
    else if(!SOAD_RADDR_IS_VALID_STATE(SoConPtr->RemoteAddrState))
    {
        SOAD_DET_REPORT_ERROR(SOAD_API_INTERNAL, SOAD_E_INV_ARG);
    }
    else
    {
        ConnPtr = SOAD_GET_SOCONCTX_PTR(SoConId);
        ConnPtr->SoConId = SoConId;
        ConnPtr->SocketId = TCPIP_SOCKETID_INVALID;
        SOAD_SOCON_CLEAR_REQUEST(ConnPtr);
        ConnPtr->Abort = FALSE;
        ConnPtr->ConfigPtr = SoConPtr;
        ConnPtr->GroupConfigPtr = GroupPtr;

        ConnPtr->RemoteAddr.Domain = SoConPtr->RemoteAddr.Domain;
        SOAD_RADDR_SET_DEFAULT_ADDRESS(ConnPtr);
        SoAd__InitTxSession(ConnPtr);
        SoAd__InitRxSession(ConnPtr);

        if(SOAD_SOCONGRP_IS_AUTOSETUP(GroupPtr))
        {
            SOAD_SOCON_SET_OPEN_REQUEST(ConnPtr);
        }
        else
        {
            SOAD_SOCON_CLEAR_REQUEST(ConnPtr);
        }

        /*SWS_SoAd_00723*/
        SOAD_SOCON_SET_OFFLINE(ConnPtr);
    }
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: SoAd__SetRemoteAddress
*
* Description:   Copy the remote address from source to destination.
*
* Inputs:        ConnPtr        - the runtime context of a socket conneciton.
*                SrcAddrPtr     - the source address
*                SrcAddrState   - the state of source address
*
* Outputs:       None
*
* Limitations:   The domain of destination must be same as the source's.
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, SOAD_CODE) SoAd__SetRemoteAddress
(
    P2VAR(SoAd_ConnectionType, AUTOMATIC, AUTOMATIC) ConnPtr,
    P2CONST(SoAd_RemoteAddressType, AUTOMATIC, AUTOMATIC) SrcAddrPtr,
    uint8 SrcAddrState
)
{
    SoAd__CopyRemoteAddress(&ConnPtr->RemoteAddr, SrcAddrPtr);
    SOAD_SOCON_SET_RADDR_STATE(ConnPtr, SrcAddrState);
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: SoAd__UpdateConnRemoteAddress
*
* Description:   Set the remote address of SoCon and change its Mode.
*
* Inputs:        ConnPtr        - the runtime context of a socket conneciton.
*                RemoteAddrPtr  - the remote address
*                AddrState      - the state of remote address
*
* Outputs:       None
*
* Limitations:   The domain of destination must be same as the source's.
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, SOAD_CODE) SoAd__UpdateConnRemoteAddress
(
    P2VAR(SoAd_ConnectionType, AUTOMATIC, AUTOMATIC) ConnPtr,
    P2CONST(SoAd_RemoteAddressType, AUTOMATIC, AUTOMATIC) RemoteAddrPtr,
    uint8 AddrState
)
{
    SoAd__SetRemoteAddress(ConnPtr, RemoteAddrPtr, AddrState);
    if(SOAD_RADDR_IS_IP_AND_PORT(AddrState))
    {
        if(SOAD_SOCON_IS_RECONN(ConnPtr))
        {
            SoAd__SoConModeChg(ConnPtr, SOAD_SOCON_ONLINE);
        }
    }
    else if(SOAD_SOCON_IS_ONLINE(ConnPtr))
    {
        /*SWS_SoAd_00687*/
        SoAd__SoConModeChg(ConnPtr, SOAD_SOCON_RECONN);
    }
    else
    {
    }
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: SoAd__CopyRemoteAddress
*
* Description:   Copy the remote address from source to destination.
*
* Inputs:        DestAddrPtr    - the destination address
*                SrcAddrPtr     - the source address
*
* Outputs:       None
*
* Limitations:   The domain of destination must be same as the source's.
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, SOAD_CODE) SoAd__CopyRemoteAddress
(
    P2VAR(SoAd_RemoteAddressType, AUTOMATIC, AUTOMATIC) DestAddrPtr,
    P2CONST(SoAd_RemoteAddressType, AUTOMATIC, AUTOMATIC) SrcAddrPtr
)
{
    if(DestAddrPtr == NULL_PTR)
    {
        SOAD_DET_REPORT_ERROR(SOAD_API_INTERNAL, SOAD_E_PARAM_POINTER);
    }
    else if(SrcAddrPtr == NULL_PTR)
    {
        SOAD_DET_REPORT_ERROR(SOAD_API_INTERNAL, SOAD_E_PARAM_POINTER);
    }
    else if(DestAddrPtr->Domain != SrcAddrPtr->Domain)
    {
        SOAD_DET_REPORT_ERROR(SOAD_API_INTERNAL, SOAD_E_INV_ARG);
    }
    else
    {
        DestAddrPtr->Port = SrcAddrPtr->Port;
        DestAddrPtr->Addr[0] = SrcAddrPtr->Addr[0];

#if (SOAD_IPV6_ADDRESS_ENABLED == STD_ON)
        if(TCPIP_AF_INET6 == SrcAddrPtr->Domain)
        {
            uint8 i;

            for(i = 1; i < 4; i++)
            {
                DestAddrPtr->Addr[i] = SrcAddrPtr->Addr[i];
            }
        }
#endif
    }
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: SoAd__CheckRemoteAddressState
*
* Description:   Checks the state of a specified remote address and return it.
*
* Inputs:        RemoteAddrPtr  - the remote address
*
* Outputs:       the state of a remote address.
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(uint8, SOAD_CODE) SoAd__CheckRemoteAddressState
(
    P2CONST(SoAd_RemoteAddressType, AUTOMATIC, AUTOMATIC) RemoteAddrPtr
)
{
    uint8 state = SOAD_REMOTE_ADDRESS_UNSET;

    if(RemoteAddrPtr != NULL_PTR)
    {
        state = SOAD_REMOTE_ADDRESS_ALL_ANY;

        if(RemoteAddrPtr->Port != TCPIP_PORT_ANY)
        {
            SOAD_RADDR_SET_PORT(state);
        }

        if(SoAd__IsSpecificIpAddress(RemoteAddrPtr) == E_OK)
        {
            SOAD_RADDR_SET_IP(state);
        }
    }

    return state;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: SoAd__IsSpecificIpAddress
*
* Description:   Checks if the retmote address is a specific IP address.
*
* Inputs:        RemoteAddrPtr  - the remote address
*
* Outputs:       If the IP is a specific address returns E_OK.
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(Std_ReturnType, SOAD_CODE) SoAd__IsSpecificIpAddress
(
    P2CONST(SoAd_RemoteAddressType, AUTOMATIC, AUTOMATIC) RemoteAddrPtr
)
{
    Std_ReturnType ret = E_NOT_OK;

    if(RemoteAddrPtr == NULL_PTR)
    {
        SOAD_DET_REPORT_ERROR_RET(SOAD_API_INTERNAL, SOAD_E_PARAM_POINTER, ret);
    }

    if(RemoteAddrPtr->Addr[0] != TCPIP_IPADDR_ANY)
    {
        ret = E_OK;
    }
#if (SOAD_IPV6_ADDRESS_ENABLED == STD_ON)
    else if(TCPIP_AF_INET6 == RemoteAddrPtr->Domain)
    {
        uint8 i;

        /* If all values in an IP are TCPIP_IPADDR_ANY, this IP address is a wildcard.*/
        for(i = 1;i < 4; i++)
        {
            if(RemoteAddrPtr->Addr[i] != TCPIP_IPADDR_ANY)
            {
                ret = E_OK;
                break;
            }
        }

    }
    else
    {
        /*Do nothing*/
    }
#endif

    return ret;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: SoAd__IsMatchedIpAddress
*
* Description:   Checks if the retmote address is matched.
*
* Inputs:        SrcAddrPtr     - the source address
*                RemoteAddrPtr  - the remote address
*
* Outputs:       If the IP is matched returns E_OK.
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(Std_ReturnType, SOAD_CODE) SoAd__IsMatchedIpAddress
(
    P2CONST(SoAd_RemoteAddressType, AUTOMATIC, AUTOMATIC) SrcAddrPtr,
    P2CONST(SoAd_RemoteAddressType, AUTOMATIC, AUTOMATIC) RemoteAddrPtr
)
{
    Std_ReturnType ret = E_NOT_OK;

    if((SrcAddrPtr == NULL_PTR) || (RemoteAddrPtr == NULL_PTR))
    {
        SOAD_DET_REPORT_ERROR_RET(SOAD_API_INTERNAL, SOAD_E_PARAM_POINTER, ret);
    }
#if (SOAD_IPV6_ADDRESS_ENABLED == STD_OFF)
    if((SrcAddrPtr->Domain != TCPIP_AF_INET) || (RemoteAddrPtr->Domain != TCPIP_AF_INET))
    {
        SOAD_DET_REPORT_ERROR_RET(SOAD_API_INTERNAL, SOAD_E_INV_ARG, ret);
    }

    if(SrcAddrPtr->Addr[0] == RemoteAddrPtr->Addr[0])
    {
        ret = E_OK;
    }
#else /*SOAD_IPV6_ADDRESS_ENABLED == STD_ON*/
    if((SrcAddrPtr->Domain != RemoteAddrPtr->Domain)
        || (SrcAddrPtr->Addr[0] != RemoteAddrPtr->Addr[0]))
    {
        /*the address is not matched*/
    }
    else if(TCPIP_AF_INET6 != SrcAddrPtr->Domain)
    {
        /*IPv4 and address are matched.*/
        ret = E_OK;
    }
    else
    {
        uint8 i;

        ret = E_OK;
        for(i = 1;i < 8; i++)
        {
            if(SrcAddrPtr->Addr[i] != RemoteAddrPtr->Addr[i])
            {
                ret = E_NOT_OK;
                break;
            }
        }
    }
#endif

    return ret;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: SoAd__CloseSoCon
*
* Description:   Close the socket connection.
*
* Inputs:        ConnPtr    - the runtime context of a socket conneciton.
                 Offline    - TRUE: SoAd_CloseSoCon been called; 
                              FALSE: Close Event happened
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, SOAD_CODE) SoAd__CloseSoCon
(
    P2VAR(SoAd_ConnectionType, AUTOMATIC, AUTOMATIC) ConnPtr,
    boolean Offline
)
{
    TcpIp_SocketIdType socketId;
    boolean abortFlag;

    if(ConnPtr == NULL_PTR)
    {
        SOAD_DET_REPORT_ERROR(SOAD_API_INTERNAL, SOAD_E_PARAM_POINTER);
    }
    else
    {
        /* Disable further transmission or reception for this socket connection.*/
        /*protect*/
        SOAD_ENTER_CRITICAL_SECTION_SOCON_MODE_IDX();
        socketId = ConnPtr->SocketId;
        SOAD_SOCON_CLEAR_SOCKETID(ConnPtr);
        /*unprotect*/
        SOAD_LEAVE_CRITICAL_SECTION_SOCON_MODE_IDX();

        /* Check if the TP sessions are actived.*/
        if(!SOAD_SESSION_IS_IDLE(&ConnPtr->TxSession))
        {
            /*Disactive the Tx session of TP*/
            SoAd__DisactiveTxSession(ConnPtr);
        }
        if(!SOAD_SESSION_IS_IDLE(&ConnPtr->RxSession))
        {
            /*Disactive the Rx session of TP*/
            SoAd__DisactiveRxSession(ConnPtr);
        }

        /* Clear the Remote Address*/ /*SWS_SoAd_00527*/
        SOAD_ENTER_CRITICAL_SECTION_SOCON_MODE_IDX();
        if(Offline == TRUE)
        {        
            /*This SoCon is closed by SoAd_CloseSoCon*/
            SoAd__SoConModeChg(ConnPtr, SOAD_SOCON_OFFLINE);
            SOAD_RADDR_SET_DEFAULT_ADDRESS(ConnPtr);
            abortFlag = ConnPtr->Abort;
        }
        else    /*SoAd_TcpIpEvent*/
        {
            SoAd__SoConModeChg(ConnPtr, SOAD_SOCON_RECONN);

            if(SOAD_SOCON_IS_TCP_SERVER(ConnPtr))
            {
                SOAD_RADDR_SET_DEFAULT_ADDRESS(ConnPtr);
            }
            abortFlag = FALSE;
            /*we need open this socket connection again.*/ /*SWS_SoAd_00586*/
            SOAD_SOCON_SET_OPEN_REQUEST(ConnPtr);
        }
        SOAD_LEAVE_CRITICAL_SECTION_SOCON_MODE_IDX();

        /*Close the (shared) socket*/ /*SWS_SoAd_00642*/
        if(SOAD_SOCON_IS_UDP(ConnPtr))
        {
            /*The UDP protocol*/
            if(SoAd__IsAllSoConOffline(ConnPtr->GroupConfigPtr) == E_OK)
            {
                SoAd__CloseSoConGroupSocketId(ConnPtr->GroupConfigPtr);
            }
        }
        else
        {
            /*The TCP protocol*/
            if(socketId != TCPIP_SOCKETID_INVALID)
            {
                /*SWS_SoAd_00642(1a)*/
                (void)TcpIp_Close(socketId, abortFlag);
            }

            if(SOAD_SOCON_IS_TCP_SERVER(ConnPtr)
                && (SoAd__IsAllSoConOffline(ConnPtr->GroupConfigPtr) == E_OK))
            {
                SoAd__CloseSoConGroupSocketId(ConnPtr->GroupConfigPtr);
            }
        }
    }
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: SoAd__SoConModeChg
*
* Description:   Change the mode of a socket connection to new mode and Call the
*                Up_SoConModeChg calback of UpLayer Modules of socket connection
*
* Inputs:        ConnPtr    - the runtime context of a socket conneciton.
*                Mode       - new Mode.
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, SOAD_CODE) SoAd__SoConModeChg
(
    P2VAR(SoAd_ConnectionType, AUTOMATIC, AUTOMATIC) ConnPtr,
    SoAd_SoConModeType Mode
)
{
    if(ConnPtr == NULL_PTR)
    {
        SOAD_DET_REPORT_ERROR(SOAD_API_INTERNAL, SOAD_E_PARAM_POINTER);
    }
    else
    {
        ConnPtr->Mode = Mode;
        if(SOAD_SOCON_IS_SOCON_MODE_CHG(ConnPtr))
        {
            P2CONST(SoAd_ULIndexType, AUTOMATIC, AUTOMATIC) upLayerIndexPtr;

            /*iterates all UpLayer Modules to call the Up_SoConModeChg callback*/
            upLayerIndexPtr = SOAD_SOCON_GET_SOCONMODECHG_PTR(ConnPtr);
            while(*upLayerIndexPtr < SOAD_UL_MAX)
            {
                SoAd__CallUpSoConModeChg(*upLayerIndexPtr, ConnPtr->SoConId, Mode);
                upLayerIndexPtr++;
            }
        }
    }
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: SoAd__LocalIpAddrAssignmentChg
*
* Description:   Call the Up_LocalIpAddrAssignmentChg calback of UpLayer Modules
*                of socket connection Group.
*
* Inputs:        GroupPtr    - the group of SoCon.
*                State       - the state of IP address.
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, SOAD_CODE) SoAd__LocalIpAddrAssignmentChg
(
    P2CONST(SoAd_SocketConnectionGroupType, AUTOMATIC, AUTOMATIC) GroupPtr,
    TcpIp_IpAddrStateType State
)
{
    P2CONST(SoAd_ULIndexType, AUTOMATIC, AUTOMATIC) upLayerIndexPtr;

    if(SOAD_SOCONGRP_IS_ADDR_ASSIGNMENT_CHG(GroupPtr))
    {
        /*iterates all UpLayer Modules to call the Up_LocalIpAddrAssignmentChg callback*/
        upLayerIndexPtr = SOAD_SOCONGRP_GET_IPADDRASSIGNMENTCHG_PTR(GroupPtr);
        while(*upLayerIndexPtr < SOAD_UL_MAX)
        {
            SoAd__CallUpLocalIpAddrAssignmentChg(*upLayerIndexPtr, GroupPtr->SoConId, State);
            upLayerIndexPtr++;
        }
    }
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: SoAd__IsAllSoConOffline
*
* Description:   Check if all of socket conneciton in a SoConGroup are OFFLINE.
*
* Inputs:        SoConGroupPtr  - the socket connection group.
*
* Outputs:       If all of socket connection in this SoConGroup are OFFLINE
*                return E_OK, otherwise returns E_NOT_OK.
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(Std_ReturnType, SOAD_CODE) SoAd__IsAllSoConOffline
(
    P2CONST(SoAd_SocketConnectionGroupType, SOAD_CONFIG_DATA, AUTOMATIC) SoConGroupPtr
)
{
    Std_ReturnType ret = E_OK;
    SoAd_SoConIdType soConId;
    SoAd_SoConIdType soConIdMax;

    if(SoConGroupPtr == NULL_PTR)
    {
        SOAD_DET_REPORT_ERROR(SOAD_API_INTERNAL, SOAD_E_PARAM_POINTER);
    }
    else
    {
        soConId = SoConGroupPtr->SoConId;
        soConIdMax = SoConGroupPtr->SoConNum + soConId;
        for(; soConId < soConIdMax; soConId++)
        {
            if(!SOAD_SOCON_IS_OFFLINE(SOAD_GET_SOCONCTX_PTR(soConId)))
            {
                ret = E_NOT_OK;
                break;
            }
        }
    }
    return ret;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: SoAd__CloseSoConGroupSocketId
*
* Description:   Close the shared socketId in a SoConGroup.
*
* Inputs:        SoConGroupPtr  - the socket connection group.
*
* Outputs:       None
*
* Limitations:   only used for TCP server SoConGroup or UDP SoConGroup with
*                multiple SoCon.
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, SOAD_CODE) SoAd__CloseSoConGroupSocketId
(
    P2CONST(SoAd_SocketConnectionGroupType, SOAD_CONFIG_DATA, AUTOMATIC) SoConGroupPtr
)
{
    TcpIp_SocketIdType socketId;

    if(SoConGroupPtr == NULL_PTR)
    {
        SOAD_DET_REPORT_ERROR(SOAD_API_INTERNAL, SOAD_E_PARAM_POINTER);
    }
    else
    {
        SOAD_ENTER_CRITICAL_SECTION_SHARED_SOCKET_IDX();
        socketId = SOAD_SOCONGRP_GET_SOCKETID(SoConGroupPtr);
        SOAD_SOCONGRP_CLEAR_SOCKETID(SoConGroupPtr);
        SOAD_LEAVE_CRITICAL_SECTION_SHARED_SOCKET_IDX();

        /*SWS_SoAd_00642(1b)  SWS_SoAd_00642(2b)*/
        if(socketId != TCPIP_SOCKETID_INVALID) 
        {
            (void)TcpIp_Close(socketId, FALSE);
        }
    }
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: SoAd__CloseUdpSoConGroup
*
* Description:   Close the socketId in a UDP SoConGroup and remove all socketId
*                in SoCons.
*
* Inputs:        SoConGroupPtr  - the socket connection group.
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, SOAD_CODE) SoAd__CloseUdpSoConGroup
(
    P2CONST(SoAd_SocketConnectionGroupType, SOAD_CONFIG_DATA, AUTOMATIC) SoConGroupPtr
)
{
    TcpIp_SocketIdType socketId;
    SoAd_SoConIdType soConId;
    SoAd_SoConIdType soConIdMax;
    P2VAR(SoAd_ConnectionType, AUTOMATIC, AUTOMATIC) connPtr;

    if(SoConGroupPtr == NULL_PTR)
    {
        SOAD_DET_REPORT_ERROR(SOAD_API_INTERNAL, SOAD_E_PARAM_POINTER);
    }
    else
    {
        SOAD_ENTER_CRITICAL_SECTION_SHARED_SOCKET_IDX();
        socketId = SOAD_SOCONGRP_GET_SOCKETID(SoConGroupPtr);
        SOAD_SOCONGRP_CLEAR_SOCKETID(SoConGroupPtr);
        SOAD_LEAVE_CRITICAL_SECTION_SHARED_SOCKET_IDX();

        soConId = SoConGroupPtr->SoConId;
        soConIdMax = SoConGroupPtr->SoConNum + soConId;
        for(; soConId < soConIdMax; soConId++)
        {
            connPtr = SOAD_GET_SOCONCTX_PTR(soConId);
            if(SOAD_SOCON_IS_VALID_SOCKETID(connPtr))
            {
                SOAD_ENTER_CRITICAL_SECTION_SOCON_MODE_IDX();
                SOAD_SOCON_CLEAR_SOCKETID(connPtr);
                if(SOAD_SOCON_IS_ONLINE(connPtr))
                {
                    SOAD_SOCON_SET_CLOSE_EVENT(connPtr);
                }
                SOAD_LEAVE_CRITICAL_SECTION_SOCON_MODE_IDX();
            }
        }

        if(socketId != TCPIP_SOCKETID_INVALID)
        {
            (void)TcpIp_Close(socketId, FALSE);
        }
    }
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: SoAd__OpenSoCon
*
* Description:   Open the socket connection.
*
* Inputs:        ConnPtr    - the runtime context of a socket conneciton.
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, SOAD_CODE) SoAd__OpenSoCon
(
    P2VAR(SoAd_ConnectionType, AUTOMATIC, AUTOMATIC) ConnPtr
)
{
    TcpIp_SocketIdType socketId;

    socketId = TCPIP_SOCKETID_INVALID;

    if(TCPIP_SOCKETID_INVALID == SOAD_SOCONGRP_GET_SOCKETID(ConnPtr->GroupConfigPtr))
    {
        if(!SOAD_RADDR_IS_IP_AND_PORT(ConnPtr->RemoteAddrState) && SOAD_SOCON_IS_TCP(ConnPtr) &&\
            !SOAD_SOCON_IS_TCP_SERVER(ConnPtr))
        {
            /* TCP Client with unspecified remote address */
            socketId = TCPIP_SOCKETID_INVALID;
        }
        else
        {
            /*SWS_SoAd_00638(1a,1b,1c)*/ /*SWS_SoAd_00639(1a,1b,1c)*/ /*SWS_SoAd_00590(1,2,3)*/
            socketId = SoAd__GetSocket(ConnPtr);
            if(SOAD_SOCON_IS_UDP(ConnPtr))
            {
                /*SWS_SoAd_00639(1d)*/
                
                SOAD_ENTER_CRITICAL_SECTION_SHARED_SOCKET_IDX();
                SOAD_SOCONGRP_SET_SOCKETID(ConnPtr->GroupConfigPtr, socketId);
                
                SOAD_LEAVE_CRITICAL_SECTION_SHARED_SOCKET_IDX();
            }
        }
    }
    else if(SOAD_SOCON_IS_UDP(ConnPtr))
    {
        /*Shared UDP socket*/
        socketId = SOAD_SOCONGRP_GET_SOCKETID(ConnPtr->GroupConfigPtr);
    }
    else if(SOAD_SOCONGRP_IS_TCP_SERVER(ConnPtr->GroupConfigPtr))
    {
        /*TCP Server*/ /*SWS_SoAd_00638(2)*/
    	SOAD_ENTER_CRITICAL_SECTION_SOCON_MODE_IDX();
        SoAd__SoConModeChg(ConnPtr, SOAD_SOCON_RECONN);
        SOAD_LEAVE_CRITICAL_SECTION_SOCON_MODE_IDX();
        socketId = TCPIP_SOCKETID_INVALID;
    }
    else
    {
        /* Shared TCP Client */
    }

    if(socketId == TCPIP_SOCKETID_INVALID)
    {
        /*nothing*/
    }
    /*If we get a socket, sets it to SoCon*/
    else if(SOAD_SOCON_IS_TCP(ConnPtr))
    {
        Std_ReturnType ret;

        if(SOAD_SOCON_IS_TCP_SERVER(ConnPtr))
        {
            /*SWS_SoAd_00638(1f)*/
            ret = TcpIp_TcpListen(socketId, ConnPtr->GroupConfigPtr->SoConNum);
            if(E_OK == ret)
            {
                /*SWS_SoAd_00638(1d)*/
                
            	SOAD_ENTER_CRITICAL_SECTION_SHARED_SOCKET_IDX();
                SOAD_SOCONGRP_SET_SOCKETID(ConnPtr->GroupConfigPtr, socketId);
                
                SOAD_LEAVE_CRITICAL_SECTION_SHARED_SOCKET_IDX();
                /*SWS_SoAd_00686(1)*/ /*SWS_SoAd_00638(1e)*/
                SOAD_ENTER_CRITICAL_SECTION_SOCON_MODE_IDX();
                SoAd__SoConModeChg(ConnPtr, SOAD_SOCON_RECONN);
                SOAD_LEAVE_CRITICAL_SECTION_SOCON_MODE_IDX();
            }
        }
        else
        {
            /*SWS_SoAd_00590(4)*/
            ret = TcpIp_TcpConnect(socketId,
                                    (P2VAR(TcpIp_SockAddrType, AUTOMATIC, AUTOMATIC))&ConnPtr->RemoteAddr);
            if(E_OK == ret)
            {
            	SOAD_ENTER_CRITICAL_SECTION_SOCON_MODE_IDX();
                SOAD_SOCON_SET_SOCKETID(ConnPtr, socketId);
                /*SWS_SoAd_00686(1)*/
                SoAd__SoConModeChg(ConnPtr, SOAD_SOCON_RECONN);
                SOAD_LEAVE_CRITICAL_SECTION_SOCON_MODE_IDX();
            }
        }

        if(ret == E_NOT_OK)
        {
            (void)TcpIp_Close(socketId, FALSE);
        }
    }
    else
    {
        /*The UDP protocol*/
    	SOAD_ENTER_CRITICAL_SECTION_SOCON_MODE_IDX();
        /*SWS_SoAd_00639(1e,2)*/
        SOAD_SOCON_SET_SOCKETID(ConnPtr, socketId);
        
        if(SOAD_SOCON_IS_UDP_LISTEN_ONLY(ConnPtr)
            || SOAD_RADDR_IS_IP_AND_PORT(ConnPtr->RemoteAddrState))
        {
            /*SWS_SoAd_00591*/
            SoAd__SoConModeChg(ConnPtr, SOAD_SOCON_ONLINE);
            /*SWS_SoAd_00595*/
            SOAD_LEAVE_CRITICAL_SECTION_SOCON_MODE_IDX();
            if(SoAd__StartTpReceptionWithoutPduHeader(ConnPtr) != E_OK)
            {
            	SOAD_ENTER_CRITICAL_SECTION_SOCON_MODE_IDX();
                /*SWS_SoAd_00570*/
                SOAD_SOCON_CLEAR_SOCKETID(ConnPtr);
                SOAD_SOCON_SET_CLOSE_EVENT(ConnPtr);
                SOAD_LEAVE_CRITICAL_SECTION_SOCON_MODE_IDX();
            }
            SOAD_ENTER_CRITICAL_SECTION_SOCON_MODE_IDX();
        }
        else
        {
            /*SWS_SoAd_00686(2)*/
            SoAd__SoConModeChg(ConnPtr, SOAD_SOCON_RECONN);
        }
        SOAD_LEAVE_CRITICAL_SECTION_SOCON_MODE_IDX();
    }
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: SoAd__GetSocket
*
* Description:   Get a new socket from TcpIp module.
*
* Inputs:        ConnPtr    - the runtime context of a socket conneciton.
*
* Outputs:       returns the id of new socket.
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(TcpIp_SocketIdType, SOAD_CODE) SoAd__GetSocket
(
    P2VAR(SoAd_ConnectionType, AUTOMATIC, AUTOMATIC) ConnPtr
)
{
    TcpIp_SocketIdType socketId = TCPIP_SOCKETID_INVALID;
    TcpIp_ProtocolType protocol = TCPIP_IPPROTO_UDP;
    uint16 port = ConnPtr->GroupConfigPtr->LocalPort;

    if(SOAD_SOCON_IS_TCP(ConnPtr))
    {
        protocol = TCPIP_IPPROTO_TCP;
    }

    if(TcpIp_SoAdGetSocket(ConnPtr->RemoteAddr.Domain, protocol, &socketId) == E_OK)
    {
        if(TcpIp_Bind(socketId, ConnPtr->GroupConfigPtr->LocalAddrId, &port) != E_OK)
        {
            (void)TcpIp_Close(socketId, FALSE);
            socketId = TCPIP_SOCKETID_INVALID;
        }
    }
    else
    {
        socketId = TCPIP_SOCKETID_INVALID;
    }

    if(socketId == TCPIP_SOCKETID_INVALID)
    {
        SOAD_DEBUG(SOAD_API_INTERNAL, 'Socket Open Failed!');
    }

    return socketId;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: SoAd__StartTpReceptionWithoutPduHeader
*
* Description:   Start TP reception of a SoCon without PduHeader
*
* Inputs:        ConnPtr    - the runtime context of a socket conneciton.
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(Std_ReturnType, SOAD_CODE) SoAd__StartTpReceptionWithoutPduHeader
(
    P2VAR(SoAd_ConnectionType, AUTOMATIC, AUTOMATIC) ConnPtr
)
{
    P2CONST(SoAd_SocketRouteType, SOAD_CONFIG_DATA, AUTOMATIC) socketRoutePtr;
    PduLengthType dummy;
    Std_ReturnType ret = E_OK;

    if(!SOAD_SOCON_IS_PDUHEADER_ENABLED(ConnPtr) && (SOAD_SOCON_GET_SOCKETROUTE_NUM(ConnPtr) > 0))
    {
        socketRoutePtr = SOAD_GET_SOCKETROUTE_PTR(SOAD_SOCON_GET_SOCKETROUTE_ID(ConnPtr, 0));
        if(SOAD_SOCKETROUTE_IS_TP(socketRoutePtr))
        {
            /*SWS_SoAd_00595*/
            ret = SoAd__StartTpReception(ConnPtr, socketRoutePtr, 0, &dummy);
        }
    }

    return ret;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: SoAd__FindSoConGroupBySocket
*
* Description:   Find a socket connection group's Id by socket Id.
*
* Inputs:        SocketId           - the socket id from the TcpIp module.
*                SoConGroupIdPtr    - the buffer used to save SoConId.
*
* Outputs:       If the SoConGroupId is found returns E_OK, otherwise returns
*                E_NOT_OK.
*
* Limitations:   SoConGroupId must be a valid pointer.
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(Std_ReturnType, SOAD_CODE) SoAd__FindSoConGroupBySocketId
(
    TcpIp_SocketIdType SocketId,
    P2VAR(SoAd_SoConGroupIdType, AUTOMATIC, AUTOMATIC) SoConGroupIdPtr
)
{
    SoAd_SoConGroupIdType groupId;
    SoAd_SoConGroupIdType groupNum = SOAD_GET_SOCON_GROUP_NUM();
    Std_ReturnType ret = E_NOT_OK;

    for(groupId = 0; groupId < groupNum; groupId++)
    {
        if(SOAD_GET_SHARED_SOCKETID(groupId) == SocketId)
        {
            *SoConGroupIdPtr = groupId;
            ret = E_OK;
            break;
        }
    }

    return ret;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: SoAd__FindConnBySocket
*
* Description:   Find a socket connection's Id by socket Id.
*
* Inputs:        SocketId   - the socket id from the TcpIp module.
*                SoConIdPtr - the buffer used to save SoConId.
*
* Outputs:       If the SoConId is found returns E_OK, otherwise returns E_NOT_OK.
*
* Limitations:   SoConIdPtr must be a valid pointer.
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(Std_ReturnType, SOAD_CODE) SoAd__FindConnBySocketId
(
    TcpIp_SocketIdType SocketId,
    P2VAR(SoAd_SoConIdType, AUTOMATIC, AUTOMATIC) SoConIdPtr
)
{
    Std_ReturnType ret = E_NOT_OK;
    SoAd_SoConIdType i;
    SoAd_SoConIdType soConNum = SOAD_GET_SOCON_NUM();

    for(i = 0; i < soConNum; i++)
    {
        if(SocketId == SOAD_GET_SOCONCTX_PTR(i)->SocketId)
        {
            ret = E_OK;
            *SoConIdPtr = i;
            break;
        }
    }

    return ret;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: SoAd__FindConnBySocket
*
* Description:   Find a socket connection's Id by remote address in a SoConGroup.
*
* Inputs:        SoConGroupPtr  - the socket id from the TcpIp module.
*                RemoteAddrPtr  - the remote address
*                SoConIdPtr     - the buffer used to save SoConId.
*
* Outputs:       If the SoConId is found returns E_OK, otherwise returns E_NOT_OK.
*
* Limitations:   All pointers must be a valid pointer.
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(Std_ReturnType, SOAD_CODE) SoAd__FindConnByRemoteAddr
(
    P2CONST(SoAd_SocketConnectionGroupType, SOAD_CONFIG_DATA, AUTOMATIC) SoConGroupPtr,
    P2CONST(SoAd_RemoteAddressType, AUTOMATIC, AUTOMATIC) RemoteAddrPtr,
    P2VAR(SoAd_SoConIdType, AUTOMATIC, AUTOMATIC) SoConIdPtr
)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 level = SOAD_BMA_MATCH_LEVEL_MIN;
    SoAd_SoConIdType soConId = SoConGroupPtr->SoConId;
    SoAd_SoConIdType soConIdMax = SoConGroupPtr->SoConNum + soConId;
    SoAd_SoConIdType foundSoConId;
    P2VAR(SoAd_ConnectionType, AUTOMATIC, AUTOMATIC) connPtr;

    for(;soConId < soConIdMax; soConId++)
    {
        connPtr = SOAD_GET_SOCONCTX_PTR(soConId);
        if(!SOAD_SOCON_IS_OFFLINE(connPtr))
        {
            uint8 tmp = SoAd__BestMatchAlgorithm(connPtr, RemoteAddrPtr);
            if(tmp > level)
            {
                level = tmp;
                foundSoConId = soConId;
            }
        }
    }

    if(level > SOAD_BMA_MATCH_LEVEL_MIN)
    {
        *SoConIdPtr = foundSoConId;
        ret = E_OK;
    }

    return ret;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: SoAd__FindSocketRoutebyPduHeader
*
* Description:   Find the SocketRouteId by PduHeader.
*
* Inputs:        ConnPtr            - the pointer of the socket conncetion.
*                PduHeaderId        - the PduHeaderId.
*                SocketRouteIdPtr   - the buffer used to save SocketRouteId.
*
* Outputs:       If the SocketRouteId is found returns E_OK, otherwise returns
*                E_NOT_OK.
*
* Limitations:   SocketRouteIdPtr must be valid pointer.
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(Std_ReturnType, SOAD_CODE) SoAd__FindSocketRoutebyPduHeader
(
    P2VAR(SoAd_ConnectionType, AUTOMATIC, AUTOMATIC) ConnPtr,
    uint32 PduHeaderId,
    P2VAR(SoAd_SocketRouteIdType, AUTOMATIC, AUTOMATIC) SocketRouteIdPtr
)
{
    Std_ReturnType ret = E_NOT_OK;
    SoAd_SocketRouteIdType i,j;
    P2CONST(SoAd_SocketRouteType, SOAD_CONFIG_DATA, AUTOMATIC) socketRoutePtr;
    uint8 SoConId;
    P2VAR(SoAd_ConnectionType, AUTOMATIC, AUTOMATIC) tempConnPtr;

    if(SOAD_SOCON_IS_SHARED_SOCKET(ConnPtr)) /* shared socket */
    {
        SoConId = ConnPtr->GroupConfigPtr->SoConId;
        for(i = 0; i < (ConnPtr->GroupConfigPtr->SoConNum); i++)
        {
            tempConnPtr = SOAD_GET_SOCONCTX_PTR(SoConId);
            SoConId ++;

            for(j = 0; j < SOAD_SOCON_GET_SOCKETROUTE_NUM(tempConnPtr); j++)
            {
                socketRoutePtr = SOAD_GET_SOCKETROUTE_PTR(SOAD_SOCON_GET_SOCKETROUTE_ID(tempConnPtr, j));

                if(socketRoutePtr->RxPduHeaderId == PduHeaderId)
                {
                    *SocketRouteIdPtr = SOAD_SOCON_GET_SOCKETROUTE_ID(tempConnPtr, j);
                    ret = E_OK;
                    break;
                }
            }

            if(ret == E_OK)
            {
                break;
            }
        }
    }
    else
    {
        for(i = 0; i < SOAD_SOCON_GET_SOCKETROUTE_NUM(ConnPtr); i++)
        {
            socketRoutePtr = SOAD_GET_SOCKETROUTE_PTR(SOAD_SOCON_GET_SOCKETROUTE_ID(ConnPtr, i));

            if(socketRoutePtr->RxPduHeaderId == PduHeaderId)
            {
                *SocketRouteIdPtr = SOAD_SOCON_GET_SOCKETROUTE_ID(ConnPtr, i);
                ret = E_OK;
                break;
            }
        }
    }

    return ret;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: SoAd__BestMatchAlgorithm
*
* Description:   Find the matched level by specific remote address.
*
* Inputs:        ConnPtr        - the pointer of the socket conncetion.
*                RemoteAddrPtr  - the pointer of the PDU information.
*
* Outputs:       the matched level of this Remote address.
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(uint8, SOAD_CODE) SoAd__BestMatchAlgorithm
(
    P2VAR(SoAd_ConnectionType, SOAD_CONFIG_DATA, AUTOMATIC) ConnPtr,
    P2CONST(SoAd_RemoteAddressType, AUTOMATIC, AUTOMATIC) RemoteAddrPtr
)
{
    uint8 level = SOAD_BMA_MATCH_LEVEL_MIN;

    if(SOAD_RADDR_IS_ALL_ANY(ConnPtr->RemoteAddrState))
    {
        /*SWS_SoAd_00680(d)*/
        level = SOAD_BMA_MATCH_LEVEL_1;
    }
    else
    {
        /*SWS_SoAd_00680(b)*/
        if(SOAD_RADDR_IS_IP_SET(ConnPtr->RemoteAddrState)
            && (SoAd__IsMatchedIpAddress(&ConnPtr->RemoteAddr, RemoteAddrPtr) == E_OK))
        {
            level += SOAD_BMA_MATCH_LEVEL_3;
        }

        /*SWS_SoAd_00680(c)*/
        if(SOAD_RADDR_IS_PORT_SET(ConnPtr->RemoteAddrState)
            && SOAD_RADDR_IS_MATCHED_PORT(&ConnPtr->RemoteAddr, RemoteAddrPtr))
        {
            level += SOAD_BMA_MATCH_LEVEL_2;
        }

        if((level != SOAD_BMA_MATCH_LEVEL_MAX)
            && SOAD_RADDR_IS_IP_AND_PORT(ConnPtr->RemoteAddrState))
        {
            /*SWS_SoAd_00680(e)*/
            level = SOAD_BMA_MATCH_LEVEL_MIN;
        }
        else
        {
            /*SWS_SoAd_00680(a)*/
        }
    }

    return level;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: SoAd__SetRoutingGroup
*
* Description:   Set the state of the PduRoute and SocketRoute in a routing group.
*
* Inputs:        GroupId    - the id of the routing group
*                State      - the state of the routing group
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, SOAD_CODE) SoAd__SetRoutingGroup
(
    SoAd_RoutingGroupIdType GroupId,
    uint8 state
)
{
    P2CONST(SoAd_RoutingGroupType, SOAD_CONFIG_DATA, AUTOMATIC) groupPtr;
    P2CONST(SoAd_PduRouteDestType, SOAD_CONFIG_DATA, AUTOMATIC) pduRouteDestPtr;
    P2CONST(SoAd_SocketRouteType, SOAD_CONFIG_DATA, AUTOMATIC) socketRoutePtr;
    SoAd_PduRouteDestIdType pduDestId;
    SoAd_SocketRouteIdType socketId;
    SoAd_SoConIdType idx;

    groupPtr = SOAD_GET_ROUTINGGRP_PTR(GroupId);
    for(pduDestId = 0; pduDestId < groupPtr->PduRouteDestNum; pduDestId++)
    {
        pduRouteDestPtr = SOAD_GET_PDUROUTE_DEST_PTR(groupPtr->PduRouteDestList[pduDestId]);
        /*SWS_SoAd_00721*/
        for(idx = 0; idx < pduRouteDestPtr->SoConNum; idx++)
        {
            SoAd_SetRoutingGroup(SOAD_PDUROUTE_GET_ROUTING_PTR(pduRouteDestPtr, idx), GroupId, state);
        }
    }

    for(socketId = 0; socketId < groupPtr->SocketRouteDestNum; socketId++)
    {
        socketRoutePtr = SOAD_GET_SOCKETROUTE_PTR(groupPtr->SocketRouteDestList[socketId]);
        for(idx = 0; idx < socketRoutePtr->SoConNum; idx++)
        {
            SoAd_SetRoutingGroup(SOAD_SOCKETROUTE_GET_ROUTING_PTR(socketRoutePtr, idx), GroupId, state);
        }
    }
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: SoAd__SetSpecificRoutingGroup
*
* Description:   Set the state of a RoutingGroup specified by parameter GroupId
*                only on the socket connection identified by SoConId.
*
* Inputs:        GroupId    - the id of the routing group
*                SoConId    - the id of socket connection
*                State      - the state of the routing group
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, SOAD_CODE) SoAd__SetSpecificRoutingGroup
(
    SoAd_RoutingGroupIdType GroupId,
    SoAd_SoConIdType SoConId,
    uint8 state
)
{
    P2CONST(SoAd_RoutingGroupType, SOAD_CONFIG_DATA, AUTOMATIC) groupPtr;
    P2CONST(SoAd_PduRouteDestType, SOAD_CONFIG_DATA, AUTOMATIC) pduRouteDestPtr;
    P2CONST(SoAd_SocketRouteType, SOAD_CONFIG_DATA, AUTOMATIC) socketRoutePtr;
    SoAd_PduRouteDestIdType pduDestId;
    SoAd_SocketRouteIdType socketId;
    SoAd_SoConIdType idx;

    groupPtr = SOAD_GET_ROUTINGGRP_PTR(GroupId);

    for(pduDestId = 0; pduDestId < groupPtr->PduRouteDestNum; pduDestId++)
    {
        pduRouteDestPtr = SOAD_GET_PDUROUTE_DEST_PTR(groupPtr->PduRouteDestList[pduDestId]);
        if(SOAD_PDUROUTE_IS_VALID_SOCONID(pduRouteDestPtr, SoConId))
        {
            idx = SOAD_PDUROUTE_GET_ROUTING_IDX(pduRouteDestPtr, SoConId);
            SoAd_SetRoutingGroup(SOAD_PDUROUTE_GET_ROUTING_PTR(pduRouteDestPtr, idx), GroupId, state);
        }
    }

    for(socketId = 0; socketId < groupPtr->SocketRouteDestNum; socketId++)
    {
        socketRoutePtr = SOAD_GET_SOCKETROUTE_PTR(groupPtr->SocketRouteDestList[socketId]);
        if(SOAD_SOCKETROUTE_IS_VALID_SOCONID(socketRoutePtr, SoConId))
        {
            idx = SOAD_SOCKETROUTE_GET_ROUTING_IDX(socketRoutePtr, SoConId);
            SoAd_SetRoutingGroup(SOAD_SOCKETROUTE_GET_ROUTING_PTR(socketRoutePtr, idx), GroupId, state);
        }
    }
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: SoAd__TpTxProcess
*
* Description:   Transmit a PDU of TP type.
*
* Inputs:        ConnPtr    - socket connection's runtime data.
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, SOAD_CODE) SoAd__TpTxProcess
(
    P2VAR(SoAd_ConnectionType, AUTOMATIC, AUTOMATIC) ConnPtr
)
{
    P2VAR(SoAd_TxSessionType, AUTOMATIC, AUTOMATIC) txSessionPtr;
    P2CONST(SoAd_PduRouteType, SOAD_CONFIG_DATA, AUTOMATIC) pduRoutePtr;
    P2CONST(SoAd_PduRouteDestType, SOAD_CONFIG_DATA, AUTOMATIC) pduRouteDestPtr;
    PduLengthType dataLen = 0;
    uint16 txLen = 0;
    PduInfoType pdu = {NULL_PTR, 0};
    RetryInfoType retry = {TP_DATACONF, 0};

    txSessionPtr = &ConnPtr->TxSession;
    pduRouteDestPtr = txSessionPtr->PduRouteDestPtr;
    pduRoutePtr = SOAD_GET_PDUROUTE_PTR(pduRouteDestPtr->PduRouteId);
    txLen = txSessionPtr->TotalTxLength - txSessionPtr->UsedTxLength;

    /*if all datas have been transmitted, don't call SoAd__CallUpCopyTxData*/  
    if(0 != txLen) 
    {
        /*SWS_SoAd_00552(1)*/
        (void)SoAd__CallUpCopyTxData(pduRoutePtr, &pdu, &retry, &dataLen);
        txLen = SOAD_MIN_LEN(txLen, dataLen);
    }
    
    /*SWS_SoAd_00552(2)*/
    if(0 == txLen)
    {
        /*wait for tx confirmations*/     
    }
    else if(SOAD_SOCON_IS_UDP(ConnPtr))
    {
        /*SWS_SoAd_00553(1)*/
        if(SoAd__CopyUdpTpTxData(txSessionPtr, pduRoutePtr, txLen) != E_OK)
        {
            SoAd__StopTxSession(ConnPtr);

            /*SWS_SoAd_00652*/
            SoAd__CallUpTpTxConfirmation(pduRoutePtr, E_NOT_OK);
        }
        else if(txSessionPtr->TotalTxLength == txSessionPtr->UsedTxLength)/*SWS_SoAd_00552(2)*/
        {
            Std_ReturnType ret;

            /*SWS_SoAd_00553(2)*/
            ret = TcpIp_UdpTransmit(ConnPtr->SocketId,
                                        txSessionPtr->UdpTxBuffer,
                                        (P2VAR(TcpIp_SockAddrType, AUTOMATIC, AUTOMATIC))&ConnPtr->RemoteAddr,
                                        txSessionPtr->BufferOffset);
            if(ret == E_OK )
            {
                /*SWS_SoAd_00557*/
                SoAd__CallUpTpTxConfirmation(pduRoutePtr, E_OK); /* cp_724 */
            }
            SoAd__StopTxSession(ConnPtr);
        }
    }
    else
    {
        /*SOAD_SOCON_IS_TCP*/
        /*SWS_SoAd_00554*/
        if(TcpIp_TcpTransmit(ConnPtr->SocketId, NULL_PTR, txLen, FALSE) != E_OK)
        {
            SoAd__StopTxSession(ConnPtr);

            /*SWS_SoAd_00670*/
            SoAd__CallUpTpTxConfirmation(pduRoutePtr, E_NOT_OK);
        }
        else if((txSessionPtr->TotalTxLength == txSessionPtr->UsedTxLength)/*SWS_SoAd_00552(2)*/
                && (SOAD_SOCON_IS_TCP_IMMTPTXCONFIRM(ConnPtr)))
        {
            SoAd__StopTxSession(ConnPtr);

            /*SWS_SoAd_00667*/
            SoAd__CallUpTpTxConfirmation(pduRoutePtr, E_OK);
        }
        else
        {
        	SOAD_ENTER_CRITICAL_SECTION_TX_UNCONFIRM_IDX();
            SOAD_IFTX_INCREASE_UNCONFIRMED(SOAD_GET_IFTXUNCONFIRMED_PTR(pduRouteDestPtr->PduRouteId), txLen);
            SOAD_LEAVE_CRITICAL_SECTION_TX_UNCONFIRM_IDX();
        }
    }
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: SoAd__IfTriggerTransmitProcess
*
* Description:   Transmit a PDU of IF type by trigger mode.
*
* Inputs:        RoutePtr   - the pointer of the PduRoute configuration.
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, SOAD_CODE) SoAd__IfTriggerTransmitProcess
(
    P2CONST(SoAd_PduRouteType, SOAD_CONFIG_DATA, AUTOMATIC) RoutePtr
)
{
    SoAd_PduRouteDestIdType destId;
    SoAd_PduRouteDestIdType destMax;
    P2CONST(SoAd_PduRouteDestType, SOAD_CONFIG_DATA, AUTOMATIC) destPtr;
    P2VAR(SoAd_ConnectionType, AUTOMATIC, AUTOMATIC) connPtr;
    PduInfoType pdu;
    SoAd_SoConIdType connIdx;
    PduLengthType bufferLen;

    destId = RoutePtr->RouteDestId;
    destMax = destId + RoutePtr->RouteDestNum;
    /*SWS_SoAd_00728*/
    bufferLen = SOAD_GET_IFTRIGGER_BUFFER_LENGTH();
    pdu.SduDataPtr = SOAD_GET_IFTRIGGER_BUFFER_PTR();

    while(destId < destMax)
    {
        destPtr = SOAD_GET_PDUROUTE_DEST_PTR(destId);

        destId++;
        if(NULL_PTR == destPtr->IfTriggerList)
        {
            continue;
        }

        for(connIdx = 0; connIdx < destPtr->SoConNum; connIdx++)
        {
            connPtr = SOAD_GET_SOCONCTX_PTR(destPtr->SoConId + connIdx);
            pdu.SduLength = bufferLen;
            /*SWS_SoAd_00665*/
            SOAD_ENTER_CRITICAL_SECTION_IFRG_TRANSMIT_IDX();
            if(SOAD_PDUROUTE_IS_IFTRIGGER_REQUEST(destPtr, connIdx))
            {
                SOAD_PDUROUTE_CLEAR_IFTRIGGER_REQUEST(destPtr, connIdx);
                SOAD_LEAVE_CRITICAL_SECTION_IFRG_TRANSMIT_IDX();

                if(SOAD_SOCON_IS_ONLINE(connPtr)
                    && (SoAd_IsEnabledRouting(&destPtr->RoutingCtrlList[connIdx]) == E_OK)
                    && (SoAd__CallUpIfTriggerTransmit(RoutePtr, &pdu) == E_OK))
                {
                    (void)SoAd__IfTransmit(connPtr, RoutePtr, destPtr, &pdu);
                }
            }
            SOAD_LEAVE_CRITICAL_SECTION_IFRG_TRANSMIT_IDX();
        }
    } /*while*/
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: SoAd__IfTransmit
*
* Description:   Transmit a PDU of IF type.
*
* Inputs:        ConnPtr    - socket connection's runtime data.
*                RoutePtr   - the pointer of the PduRoute configuration.
*                DestPtr    - the pointer of a PduRouteDest in this PduRoute.
*                PduInfoPtr - the pointer of the PDU information.
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(uint16, SOAD_CODE) SoAd__IfTransmit
(
    P2VAR(SoAd_ConnectionType, AUTOMATIC, AUTOMATIC) ConnPtr,
    P2CONST(SoAd_PduRouteType, SOAD_CONFIG_DATA, AUTOMATIC) RoutePtr,
    P2CONST(SoAd_PduRouteDestType, SOAD_CONFIG_DATA, AUTOMATIC) DestPtr,
    P2CONST(PduInfoType, AUTOMATIC, AUTOMATIC) PduInfoPtr
)
{
    uint16 length;
    P2VAR(uint8, AUTOMATIC, AUTOMATIC) bufferPtr;
    P2VAR(SoAd_TxSessionType, AUTOMATIC, AUTOMATIC) sessionPtr;
    P2VAR(TcpIp_SockAddrType, AUTOMATIC, AUTOMATIC) remoteAddrPtr;
    Std_ReturnType ret = E_NOT_OK;

    sessionPtr = &ConnPtr->TxSession;
    remoteAddrPtr = (P2VAR(TcpIp_SockAddrType, AUTOMATIC, AUTOMATIC))&ConnPtr->RemoteAddr;

    if(SoAd__StartTxSession(ConnPtr, SOAD_SESSION_STATE_IF) != E_OK)
    {
        /*SWS_SoAd_00653*/
    }
    else if(NULL_PTR == sessionPtr->UdpTxBuffer)
    {
        /*nPduUdpTxBuffer is NOT valid.*/
        if((SOAD_SOCON_IS_TCP(ConnPtr)) || (SOAD_UDP_TRIGGER_ALWAYS == DestPtr->UdpTriggerMode))
        {
            if(SOAD_SOCON_IS_PDUHEADER_ENABLED(ConnPtr))
            {
                /*SWS_SoAd_00197*/
                bufferPtr = NULL_PTR;
                length = PduInfoPtr->SduLength + SOAD_PDUHEADER_LENGTH;
                sessionPtr->TotalTxLength = length;
                sessionPtr->UsedTxLength = 0;
                sessionPtr->IfTxDataBuffer = PduInfoPtr->SduDataPtr;
                sessionPtr->PduRouteDestPtr = DestPtr;
            }
            else
            {
                bufferPtr = PduInfoPtr->SduDataPtr;
                length = PduInfoPtr->SduLength;
            }

            if(SOAD_SOCON_IS_TCP(ConnPtr))
            {
                /*SWS_SoAd_00542*/
                ret = TcpIp_TcpTransmit(ConnPtr->SocketId, bufferPtr, length, TRUE);
            }
            else
            {
                /*SWS_SoAd_00540*/
                ret = TcpIp_UdpTransmit(ConnPtr->SocketId, bufferPtr, remoteAddrPtr, length);
            }
        }
		/*SWS_SoAd_00546*/
        SoAd__StopTxSession(ConnPtr);
    }
    else /*nPduUdpTxBuffer is valid*/
    {
        /*If a connection is TCP, the nPduUdpTxBuffer must be NULL_PTR*/
        if(!SOAD_SOCON_IS_UDP(ConnPtr))
        {
            SOAD_DET_REPORT_ERROR_RET(SOAD_API_IF_TRANSMIT, SOAD_E_INV_CONFIG_DATA, E_NOT_OK);
        }

        /*SWS_SoAd_00546*/ 
        if(SOAD_SOCON_IS_PDUHEADER_ENABLED(ConnPtr))
        {
            length = PduInfoPtr->SduLength + SOAD_PDUHEADER_LENGTH; 
        }
        else
        {
            length = PduInfoPtr->SduLength;                         
        }

        if(length > ConnPtr->ConfigPtr->IfBufferLength)
        {
            /* Buffer length exceeded */
            SOAD_DET_REPORT_ERROR_RET(SOAD_API_IF_TRANSMIT, SOAD_E_NOBUFS, E_NOT_OK);
        }

        SOAD_ENTER_CRITICAL_SECTION_TX_SESSION_IDX();
        if((sessionPtr->BufferOffset + length) > ConnPtr->ConfigPtr->IfBufferLength) 
        {
            /* SWS_SoAd_00685 */ /*SWS_SoAd_00549*/
            /* If the buffer will be exceeded, transmit all the PDUs that already in the buffer */
            if(E_OK == TcpIp_UdpTransmit(ConnPtr->SocketId, sessionPtr->UdpTxBuffer, remoteAddrPtr, sessionPtr->BufferOffset))
            {
                sessionPtr->BufferOffset = 0;  
                bufferPtr = sessionPtr->UdpTxBuffer;
                ret = E_OK;
            }
            SOAD_IFTX_STOP_UDPTIMER(sessionPtr);
        }
        else
        {
            /*SWS_SoAd_00547,SWS_SoAd_00548*/
            bufferPtr = &sessionPtr->UdpTxBuffer[sessionPtr->BufferOffset];
            ret = E_OK;
        }
        
        if(E_OK == ret)
        {
            /*SWS_SoAd_00547*/
            if(SOAD_SOCON_IS_PDUHEADER_ENABLED(ConnPtr))
            {
                SoAd__SerializePduHeader(DestPtr->TxPduHeaderId, PduInfoPtr->SduLength, bufferPtr);
                bufferPtr = &bufferPtr[SOAD_PDUHEADER_LENGTH];
                sessionPtr->BufferOffset += SOAD_PDUHEADER_LENGTH;
            }

            SoAd__CopyData(bufferPtr, PduInfoPtr->SduDataPtr, PduInfoPtr->SduLength);
            sessionPtr->BufferOffset += PduInfoPtr->SduLength;

            /*SWS_SoAd_00548*/ /*SWS_SoAd_00685*/
            if(DestPtr->UdpTriggerMode == SOAD_UDP_TRIGGER_ALWAYS)
            {
                ret = TcpIp_UdpTransmit(ConnPtr->SocketId, sessionPtr->UdpTxBuffer, remoteAddrPtr, sessionPtr->BufferOffset);
                sessionPtr->BufferOffset = 0;
                /*SWS_SoAd_00684*/
                SOAD_IFTX_STOP_UDPTIMER(sessionPtr);
            }
            else
            {
                SoAd__StartIfUdpTxTimer(ConnPtr, DestPtr->UdpTriggerTimeout);
            }
        }
        else
        {
            ret = E_NOT_OK;
        }
        SOAD_LEAVE_CRITICAL_SECTION_TX_SESSION_IDX();

        SoAd__StopTxSession(ConnPtr);
    }
	
    if(ret != E_OK)
    {
        length = 0;
    }

    return length;
}


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: SoAd__InitTxSession
*
* Description:   Initialize the TP session of transmission.
*
* Inputs:        ConnPtr        - the socket connection's runtime data.
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, SOAD_CODE) SoAd__InitTxSession
(
    P2VAR(SoAd_ConnectionType, AUTOMATIC, AUTOMATIC) ConnPtr
)
{
    P2VAR(SoAd_TxSessionType, AUTOMATIC, AUTOMATIC) sessionPtr;

    sessionPtr = &ConnPtr->TxSession;
    SoAd__ClearTxSession(sessionPtr);
    sessionPtr->UdpTxBuffer = NULL_PTR;

    if(SOAD_SOCON_IS_UDP(ConnPtr) && (ConnPtr->ConfigPtr->IfBufferLength > 0))
    {
        /*initialize the udp Tx buffer*/
        sessionPtr->BufferLength = ConnPtr->ConfigPtr->IfBufferLength;
        sessionPtr->UdpTxBuffer = SOAD_GET_BUFFER_PTR(ConnPtr->ConfigPtr->IfBufferOffset);
        sessionPtr->BufferOffset = 0;
    }
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: SoAd__ClearTxSession
*
* Description:   Clear the TP session of transmission.
*
* Inputs:        SessionPtr     - the TX session
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, SOAD_CODE) SoAd__ClearTxSession
(
    P2VAR(SoAd_TxSessionType, AUTOMATIC, AUTOMATIC) SessionPtr
)
{
     P2VAR(SoAd_IfTxUnconfirmedType, SOAD_CONFIG_DATA, AUTOMATIC) unconfirmedPtr;
     SoAd_PduRouteIdType pduRouteId;

     if(NULL_PTR != SessionPtr->PduRouteDestPtr)
     {
        pduRouteId = SessionPtr->PduRouteDestPtr->PduRouteId;
        unconfirmedPtr = SOAD_GET_IFTXUNCONFIRMED_PTR(pduRouteId);
        SOAD_IFTX_CLEAR_UNCONFIRMED(unconfirmedPtr);
     }    

    SessionPtr->BufferOffset = 0;
    SessionPtr->IfTxDataBuffer = NULL_PTR;
    SessionPtr->PduRouteDestPtr = NULL_PTR;
    SessionPtr->TotalTxLength = 0;
    SessionPtr->UsedTxLength = 0;
    SOAD_IFTX_STOP_UDPTIMER(SessionPtr);
    SOAD_SESSION_SET_IDLE(SessionPtr);
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: SoAd__StartTxSession
*
* Description:   Start the TP session of transmission.
*
* Inputs:        ConnPtr        - the socket connection's runtime data.
*                State          - the State of TP session
*
* Outputs:       If the Session is IDLE returns OK, otherwise returns NOT_OK.
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(Std_ReturnType, SOAD_CODE) SoAd__StartTxSession
(
    P2VAR(SoAd_ConnectionType, AUTOMATIC, AUTOMATIC) ConnPtr,
    uint8 State
)
{
    Std_ReturnType ret = E_NOT_OK;
    
    SOAD_ENTER_CRITICAL_SECTION_TX_SESSION_IDX();

    if(SOAD_SESSION_IS_IDLE(&ConnPtr->TxSession))
    {
        SOAD_SESSION_SET_STATE(&ConnPtr->TxSession, State);
        ret = E_OK;
    }
    
    SOAD_LEAVE_CRITICAL_SECTION_TX_SESSION_IDX();

    return ret;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: SoAd__StopTxSession
*
* Description:   Stop the TP session of transmission.
*
* Inputs:        ConnPtr        - the socket connection's runtime data.
*
* Outputs:       If the Session is NOT IDLE returns OK, otherwise returns NOT_OK.
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(Std_ReturnType, SOAD_CODE) SoAd__StopTxSession
(
    P2VAR(SoAd_ConnectionType, AUTOMATIC, AUTOMATIC) ConnPtr
)
{
    Std_ReturnType ret = E_NOT_OK;
    
    SOAD_ENTER_CRITICAL_SECTION_TX_SESSION_IDX();
    if(!SOAD_SESSION_IS_IDLE(&ConnPtr->TxSession))
    {
    	ConnPtr->TxSession.TotalTxLength = 0;
    	ConnPtr->TxSession.UsedTxLength = 0;
        SOAD_SESSION_SET_IDLE(&ConnPtr->TxSession);
        ret = E_OK;
    }
    
    SOAD_LEAVE_CRITICAL_SECTION_TX_SESSION_IDX();

    return ret;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: SoAd__CancelTxSession
*
* Description:   Cancels the TP session of reception.
*
* Inputs:        ConnPtr        - the socket connection's runtime data.
*
* Outputs:       If the Session is TP returns OK, otherwise returns NOT_OK.
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(Std_ReturnType, SOAD_CODE) SoAd__CancelTxSession
(
    P2VAR(SoAd_ConnectionType, AUTOMATIC, AUTOMATIC) ConnPtr
)
{
    Std_ReturnType ret = E_NOT_OK;
    
    SOAD_ENTER_CRITICAL_SECTION_TX_SESSION_IDX();
    if(SOAD_SESSION_IS_TP(&ConnPtr->TxSession))
    {
        SOAD_SESSION_SET_TP_CANCELLED(&ConnPtr->TxSession);
        ret = E_OK;
    }
    
    SOAD_LEAVE_CRITICAL_SECTION_TX_SESSION_IDX();

    return ret;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: SoAd__DisactiveTxSession
*
* Description:   Disactive the Tx session.
*
* Inputs:        ConnPtr    - the socket connection's runtime data.
*
* Outputs:       none
*
* Limitations:   The () must be locked before this function is called.
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, SOAD_CODE) SoAd__DisactiveTxSession
(
    P2VAR(SoAd_ConnectionType, AUTOMATIC, AUTOMATIC) ConnPtr
)
{
    P2VAR(SoAd_TxSessionType, AUTOMATIC, AUTOMATIC) txSessionPtr;
    P2CONST(SoAd_PduRouteDestType, SOAD_CONFIG_DATA, AUTOMATIC) destPtr;

    SOAD_ENTER_CRITICAL_SECTION_TX_SESSION_IDX();
    txSessionPtr = &ConnPtr->TxSession;
    if(txSessionPtr->PduRouteDestPtr != NULL_PTR)
    {
        destPtr = txSessionPtr->PduRouteDestPtr;
        SoAd__ClearTxSession(txSessionPtr);
        SOAD_LEAVE_CRITICAL_SECTION_TX_SESSION_IDX();
        /*SWS_SoAd_00640*/
        SoAd__CallUpTpTxConfirmation(SOAD_GET_PDUROUTE_PTR(destPtr->PduRouteId), E_NOT_OK);
    }
    else
    {
    	SOAD_LEAVE_CRITICAL_SECTION_TX_SESSION_IDX();
    }
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: SoAd__IsTxSession
*
* Description:   Check if the state of Tx session.
*
* Inputs:        ConnPtr    - the socket connection's runtime data.
*                State      - the state
*
* Outputs:       If the state is equal to the value of the State parameter return
*                E_OK, otherwise return E_NOT_OK.
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(Std_ReturnType, SOAD_CODE) SoAd__IsTxSession
(
    P2VAR(SoAd_ConnectionType, AUTOMATIC, AUTOMATIC) ConnPtr,
    uint8 State
)
{
    Std_ReturnType ret = E_NOT_OK;
    
    if(SOAD_SESSION_IS_STATE(&ConnPtr->TxSession, State))
    {
        ret = E_OK;
    }
    
    return ret;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: SoAd__StartIfUdpTxTimer
*
* Description:   Start the timer of UdpTxBuffer.
*
* Inputs:        ConnPtr        - the socket connection's runtime data.
*                Timeout        - the timeout value.
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, SOAD_CODE) SoAd__StartIfUdpTxTimer
(
    P2VAR(SoAd_ConnectionType, AUTOMATIC, AUTOMATIC) ConnPtr,
    SoAd_IfTxTimerType Timeout
)
{
    if((SOAD_IFTX_IS_VALID_UDPTIMER(Timeout)) && (Timeout != 0))
    {
        if(Timeout < ConnPtr->TxSession.Timer)
        {
            /*SWS_SoAd_00697*/
            SOAD_IFTX_START_UDPTIMER(&ConnPtr->TxSession, Timeout);
        }
    }
    else if(ConnPtr->GroupConfigPtr->UdpProtocolPtr->TriggerTimeout < ConnPtr->TxSession.Timer)
    {
        /*SWS_SoAd_00683*/
        SOAD_IFTX_START_UDPTIMER(&ConnPtr->TxSession, 
            ConnPtr->GroupConfigPtr->UdpProtocolPtr->TriggerTimeout);
    }
    else
    {
        /*nothing*/
    }
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: SoAd__CopyData
*
* Description:   Copy the data from SrcPtr to DestPtr
*
* Inputs:        DestPtr    - the dest buffer.
*                SrcPtr     - the src buffer.
*                Length     - the length of data.
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, SOAD_CODE) SoAd__CopyData
(
    P2VAR(uint8, AUTOMATIC, AUTOMATIC) DestPtr,
    P2CONST(uint8, AUTOMATIC, AUTOMATIC) SrcPtr,
    uint16 Length
)
{
    uint16 i;

    for(i = 0; i < Length; i++)
    {
        DestPtr[i] = SrcPtr[i];
    }
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: SoAd__CopyIfTxData
*
* Description:   Copy the data from the Tx buffer.
*
* Inputs:        TxSessionPtr   - the Tx session.
*                Length         - the length of data.
*                BufferPtr      - the buffer.
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, SOAD_CODE) SoAd__CopyIfTxData
(
    P2VAR(SoAd_TxSessionType, AUTOMATIC, AUTOMATIC) TxSessionPtr,
    uint16 Length,
    P2VAR(uint8, AUTOMATIC, AUTOMATIC) BufferPtr,
    boolean WithHeader
)
{
    P2CONST(uint8, AUTOMATIC, AUTOMATIC) srcPtr;

    srcPtr = TxSessionPtr->IfTxDataBuffer + TxSessionPtr->UsedTxLength;

    if(WithHeader == TRUE)
    {
        srcPtr -= SOAD_PDUHEADER_LENGTH;
    }

    SoAd__CopyData(BufferPtr, srcPtr, Length);

    TxSessionPtr->UsedTxLength += Length;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: SoAd__CopyUdpTpTxData
*
* Description:   Copy the data from the Tx buffer.
*
* Inputs:        TxSessionPtr   - the Tx session.
*                PduRoutePtr    - the PduRoute.
*                Length         - the Length of data.
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(Std_ReturnType, SOAD_CODE) SoAd__CopyUdpTpTxData
(
    P2VAR(SoAd_TxSessionType, AUTOMATIC, AUTOMATIC) TxSessionPtr,
    P2CONST(SoAd_PduRouteType, SOAD_CONFIG_DATA, AUTOMATIC) PduRoutePtr,
    uint16 Length
)
{
    PduInfoType pdu;
    PduLengthType dummy = 0;
    RetryInfoType retry = {TP_DATACONF, 0};

    pdu.SduDataPtr = &TxSessionPtr->UdpTxBuffer[TxSessionPtr->BufferOffset];
    pdu.SduLength = Length;

    SOAD_ENTER_CRITICAL_SECTION_TX_SESSION_IDX();
    TxSessionPtr->BufferOffset += Length;
    TxSessionPtr->UsedTxLength += Length;
    SOAD_LEAVE_CRITICAL_SECTION_TX_SESSION_IDX();

    return SoAd__CallUpCopyTxData(PduRoutePtr, &pdu, &retry, &dummy);
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: SoAd__TpRxProcess
*
* Description:   the process of TP reception in the MainFunction.
*
* Inputs:        ConnPtr    - the socket connection's runtime data.
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, SOAD_CODE) SoAd__TpRxProcess
(
    P2VAR(SoAd_ConnectionType, AUTOMATIC, AUTOMATIC) ConnPtr
)
{
    P2CONST(SoAd_SocketRouteType, SOAD_CONFIG_DATA, AUTOMATIC) socketRoutePtr;
    uint16 processedLen = 0;

    if(!SOAD_SOCON_IS_PDUHEADER_ENABLED(ConnPtr))
    {
        PduInfoType pdu = {NULL_PTR, 0};
        PduLengthType bufferSize;

        socketRoutePtr = ConnPtr->RxSession.ProcessPduInfo.SocketRoutePtr;
        if((socketRoutePtr != NULL_PTR)
            /*SWS_SoAd_00569*/
            && (SoAd__CallUpCopyRxData(socketRoutePtr, &pdu, &bufferSize) == BUFREQ_OK)
            && (SoAd__DispatchTpRxData(ConnPtr, socketRoutePtr, &bufferSize) == E_OK))
        {
        	processedLen = bufferSize;
        }
        else
        {
            /*SWS_SoAd_00570*/
            SoAd__CancelRxSession(ConnPtr);
            SOAD_SOCON_SET_CLOSE_EVENT(ConnPtr);
        }
    }
    else
    {
        P2VAR(SoAd_RxPduInfoType, AUTOMATIC, AUTOMATIC) processInfoPtr;
        PduInfoType pdu = {NULL_PTR, 0};
        PduLengthType bufferSize;

        processInfoPtr = &ConnPtr->RxSession.ProcessPduInfo;
        socketRoutePtr = processInfoPtr->SocketRoutePtr;
        if(NULL_PTR == socketRoutePtr)
        {
            uint16 discardLen;
            SoAd_PduHeaderType pduHeader;

            if(processInfoPtr->RemainLength > 0)
            {
                /*Discard this PDU*/
                discardLen = SoAd__DiscardTpRxData(ConnPtr, processInfoPtr->RemainLength);
                processInfoPtr->RemainLength -= discardLen;
                processedLen += discardLen;
                if(processInfoPtr->RemainLength == 0)
                {
                	SoAd__StopRxSession(ConnPtr);
                }
            }

            /*try to get new PDU*/
            if((0 == processInfoPtr->RemainLength) && (SoAd__MakePduHeaderFromTpBuffer(ConnPtr, &pduHeader) == E_OK))
            {
            	processedLen += SOAD_PDUHEADER_LENGTH;

                SoAd_SocketRouteIdType socketRouteId;
                if(SoAd__FindSocketRoutebyPduHeader(ConnPtr, pduHeader.PduHeaderId, &socketRouteId) == E_OK)
                {
                    PduLengthType sduLen = pduHeader.PduLength;

                    socketRoutePtr = SOAD_GET_SOCKETROUTE_PTR(socketRouteId);
                    if(SoAd__StartTpReception(ConnPtr, socketRoutePtr, sduLen, &bufferSize) != E_OK)
                    {
                        socketRoutePtr = NULL_PTR;
                    }
                }
                else
                {
                    /*SWS_SoAd_00559(3)*/
                    SOAD_DET_REPORT_ERROR(SOAD_API_RX_INDICATION, SOAD_E_INV_PDUHEADER_ID);
                }
            }
        }

        /*SWS_SoAd_00574(1)*/
        if((socketRoutePtr != NULL_PTR) && (SoAd__CallUpCopyRxData(socketRoutePtr, &pdu, &bufferSize) == BUFREQ_OK))
        {
            PduLengthType rxLen = SOAD_MIN_LEN(processInfoPtr->RemainLength, bufferSize);
            /*SWS_SoAd_00574(2)*/
            if(SoAd__DispatchTpRxData(ConnPtr, socketRoutePtr, &rxLen) == E_OK)
            {
            	processedLen += rxLen;
            	if(SoAd__UpdateRxRemainLength(ConnPtr, rxLen) == 0)
            	{
            		/*SWS_SoAd_00574(3)*/
            		SoAd__CallUpTpRxIndication(processInfoPtr->SocketRoutePtr, E_OK);
            		SoAd__StopRxSession(ConnPtr);
            	}
            }
            else
            {
            	SoAd__CallUpTpRxIndication(processInfoPtr->SocketRoutePtr, E_NOT_OK);
                processInfoPtr->SocketRoutePtr = NULL_PTR;
            }
        }
    }
	if((processedLen > 0) && (SOAD_SOCON_IS_TCP(ConnPtr)))
	{
		TcpIp_TcpReceived(ConnPtr->SocketId, processedLen);
	}
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: SoAd__UdpRxIndication
*
* Description:   Receive a UDP data.
*
* Inputs:        ConnPtr    - the socket connection's runtime data.
*                DataPtr    - the buffer of received data.
*                DataLength - the length of received data.
*
* Outputs:       If this UDP data is dispatch to Up Layer Module return E_OK,
*                otherwise returns E_NOT_OK.
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(Std_ReturnType, SOAD_CODE) SoAd__UdpRxIndication
(
    P2VAR(SoAd_ConnectionType, AUTOMATIC, AUTOMATIC) ConnPtr,
    P2VAR(uint8, AUTOMATIC, SOAD_APPL_DATA) DataPtr,
    uint16 DataLength
)
{
    P2CONST(SoAd_SocketRouteType, SOAD_CONFIG_DATA, AUTOMATIC) socketRoutePtr;
    Std_ReturnType ret = E_NOT_OK;

    if(!SOAD_SOCON_IS_PDUHEADER_ENABLED(ConnPtr))
    {
        if(SOAD_SOCON_GET_SOCKETROUTE_NUM(ConnPtr) > 0)
        {
            PduInfoType pduInfo;
            uint16 dummy;

            socketRoutePtr = SOAD_GET_SOCKETROUTE_PTR(SOAD_SOCON_GET_SOCKETROUTE_ID(ConnPtr, 0));
            if(SoAd__IsEnabledRxRouting(ConnPtr, socketRoutePtr) != E_OK)
            {
               /*SWS_SoAd_00600*/ /*Discard this PDU*/
                ret = E_NOT_OK;
            }
            else
            {
                /*SWS_SoAd_00563*/
                pduInfo.SduDataPtr = DataPtr;
                pduInfo.SduLength = DataLength;
                if(SOAD_SOCKETROUTE_IS_IF(socketRoutePtr))
                {
                    SoAd__CallUpIfRxIndication(socketRoutePtr, &pduInfo);
                    ret = E_OK;
                }
                else if(SoAd__TpRxIndication(ConnPtr, socketRoutePtr, &pduInfo, &dummy) == E_OK)
                {
                    ret = E_OK;
                }
                else
                {
                    /*Discard this PDU*/
                }
            }    
        }
    }
    /*SOAD_SOCON_IS_PDUHEADER_ENABLED(ConnPtr) == TRUE*/
    else if(SOAD_CHECK_UDP_PDUHEADER_LEN(ConnPtr, DataPtr, DataLength))
    {
        SoAd_SocketRouteIdType socketRouteId;
        SoAd_PduHeaderType pduHeader;
        uint32 remainLength = (uint32)DataLength;

        while(remainLength >= SOAD_PDUHEADER_LENGTH)
        {
            /*SWS_SoAd_00559(2)*/
            SoAd__MakePduHeader(DataPtr, &pduHeader);
            if(pduHeader.PduLength > (remainLength - SOAD_PDUHEADER_LENGTH))
            {
                /*we get a incomplete PDU and discard it.*/
                break;
            }
            else if(SoAd__FindSocketRoutebyPduHeader(ConnPtr, pduHeader.PduHeaderId, &socketRouteId) != E_OK)
            {
                /*SWS_SoAd_00559(3)*/
                SOAD_DET_REPORT_ERROR(SOAD_API_RX_INDICATION, SOAD_E_INV_PDUHEADER_ID);
            }
            else
            {
                PduInfoType pduInfo;

                socketRoutePtr = SOAD_GET_SOCKETROUTE_PTR(socketRouteId);
                if(SoAd__IsEnabledRxRouting(ConnPtr, socketRoutePtr) != E_OK) /* cp739 */
                {
                    /*SWS_SoAd_00600*/ /*Discard this PDU*/
                    ret = E_NOT_OK;
                }
                else
                {
                    /*SWS_SoAd_00562(3)*/
                    pduInfo.SduDataPtr = &DataPtr[SOAD_PDUHEADER_LENGTH];
                    pduInfo.SduLength = (PduLengthType)pduHeader.PduLength;
                    if(SOAD_SOCKETROUTE_IS_IF(socketRoutePtr))
                    {
                        SoAd__CallUpIfRxIndication(socketRoutePtr, &pduInfo);
                        ret = E_OK;
                    }
                    else if(pduInfo.SduLength > 0)
                    {
                        uint16 dummy;
                        if(SoAd__TpWithHeaderRxIndication(ConnPtr, socketRoutePtr, &pduInfo, &pduHeader, &dummy) == E_OK)
                        {
                            ret = E_OK;
                        }
                    }
                    else
                    {
                        /*SWS_SoAd_00562(4)*/
                        /*PDU Length == 0 && UL == TP*/
                    }
                }
            }
            /*SWS_SoAd_00559(4)*/
            remainLength -= pduHeader.PduLength + SOAD_PDUHEADER_LENGTH;
            DataPtr = &DataPtr[pduHeader.PduLength + SOAD_PDUHEADER_LENGTH];
        }
    }
    else
    {
        /*SWS_SoAd_00709*/
    }

     return ret;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: SoAd__TcpRxIndication
*
* Description:   Receives a TCP data.
*
* Inputs:        ConnPtr    - the socket connection's runtime data.
*                DataPtr    - the buffer of received data.
*                DataLength - the length of received data.
*
* Outputs:       If this TCP data is processed return processed length of data,
*                otherwise returns 0.
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(uint16, SOAD_CODE) SoAd__TcpRxIndication
(
    P2VAR(SoAd_ConnectionType, AUTOMATIC, AUTOMATIC) ConnPtr,
    P2VAR(uint8, AUTOMATIC, SOAD_APPL_DATA) DataPtr,
    uint16 DataLength
)
{
    P2CONST(SoAd_SocketRouteType, SOAD_CONFIG_DATA, AUTOMATIC) socketRoutePtr;
    uint16 processedLen = DataLength;
    uint16 cachedLen = 0;

    if(!SOAD_SOCON_IS_PDUHEADER_ENABLED(ConnPtr))
    {
        if(SOAD_SOCON_GET_SOCKETROUTE_NUM(ConnPtr) > 0)
        {
            PduInfoType pduInfo;
            socketRoutePtr = SOAD_GET_SOCKETROUTE_PTR(SOAD_SOCON_GET_SOCKETROUTE_ID(ConnPtr, 0));
            if(SoAd__IsEnabledRxRouting(ConnPtr, socketRoutePtr) != E_OK)  /* cp739 */
            {
                /*SWS_SoAd_00600*/ /*Discard this PDU*/
                socketRoutePtr = NULL_PTR;
            }
            else
            {
                /*SWS_SoAd_00563*/
                pduInfo.SduDataPtr = DataPtr;
                pduInfo.SduLength = DataLength;
                if(SOAD_SOCKETROUTE_IS_IF(socketRoutePtr))
                {
                    SoAd__CallUpIfRxIndication(socketRoutePtr, &pduInfo);
                }
                else
                {
                    (void)SoAd__TpRxIndication(ConnPtr, socketRoutePtr, &pduInfo, &cachedLen);
                }
            }
        }
        else
        {
            /*nothing*/
        }
    }
    else /*SOAD_SOCON_IS_PDUHEADER_ENABLED(ConnPtr) == TRUE*/
    {
        P2VAR(SoAd_RxPduInfoType, AUTOMATIC, AUTOMATIC) rxPduInfoPtr;
        SoAd_PduHeaderType pduHeader;

        /*Check if the PDU is not received completely*/
        rxPduInfoPtr = &ConnPtr->RxSession.RxPduInfo;
        if(rxPduInfoPtr->PduLength > 0)
        {
            uint16 rxLen = SOAD_MIN_LEN(rxPduInfoPtr->RemainLength, DataLength);
            rxPduInfoPtr->RemainLength -= rxLen;
            if(NULL_PTR == rxPduInfoPtr->SocketRoutePtr)
            {
                /*discard PDU's data*/
            }
            else if(SOAD_SOCKETROUTE_IS_IF(rxPduInfoPtr->SocketRoutePtr))
            {
                P2VAR(SoAd_RxBufferType, AUTOMATIC, AUTOMATIC) rxBufferPtr;

                rxBufferPtr = SOAD_IFRX_GET_BUFFER(ConnPtr);

                SoAd__SaveIfRxData(rxBufferPtr, DataPtr, rxLen);
                if(0 == rxPduInfoPtr->RemainLength)
                {
                    if(SoAd__IsEnabledRxRouting(ConnPtr, socketRoutePtr) != E_OK)  /* change cp739 */
                    {
                        /*SWS_SoAd_00600*/ /*Discard this PDU*/
                        socketRoutePtr = NULL_PTR;
                    }
                    else
                    {
                        PduInfoType pduInfo;

                        pduInfo.SduDataPtr = SOAD_IFRX_GET_BUFFER_PTR(rxBufferPtr);
                        pduInfo.SduLength = rxPduInfoPtr->PduLength;
                        /*SWS_SoAd_00567(2)*/
                        SoAd__CallUpIfRxIndication(socketRoutePtr, &pduInfo);
                        SOAD_IFRX_CLEAR_BUFFER(rxBufferPtr);
                    }   
                }
            }
            else /*SOAD_SOCKETROUTE_IS_TP == TRUE*/
            {
                SoAd__SaveTpRxData(ConnPtr, DataPtr, rxLen);
            }

            if(0 == rxPduInfoPtr->RemainLength)
            {
                rxPduInfoPtr->SocketRoutePtr = NULL_PTR;
                rxPduInfoPtr->PduLength = 0;
            }

            DataLength -= rxLen;
            DataPtr = &DataPtr[rxLen];
        }

        while(DataLength > 0)
        {
            uint16 rxPduLen;
            SoAd_SocketRouteIdType socketRoutId;

            uint8 usedLen = SoAd__TcpMakePduHeader(ConnPtr, DataPtr, DataLength, &pduHeader);
            if(0 == usedLen)
            {
                break;
            }

            DataLength -= usedLen;
            DataPtr = &DataPtr[usedLen];
            rxPduLen = SOAD_MIN_LEN(pduHeader.PduLength, DataLength);

            if(SoAd__FindSocketRoutebyPduHeader(ConnPtr, pduHeader.PduHeaderId, &socketRoutId) != E_OK)
            {
                /*This PDU is discarded*/
                /*SWS_SoAd_00559(3)*/
                SOAD_DET_REPORT_ERROR(SOAD_API_RX_INDICATION, SOAD_E_INV_PDUHEADER_ID);
            }
            else if(SOAD_SOCKETROUTE_IS_IF(SOAD_GET_SOCKETROUTE_PTR(socketRoutId)))
            {
                /*SWS_SoAd_00567(3)*/
                socketRoutePtr = SOAD_GET_SOCKETROUTE_PTR(socketRoutId);
                if(SoAd__IsEnabledRxRouting(ConnPtr, socketRoutePtr) != E_OK)
                {
                    /*SWS_SoAd_00600*/ /*Discard this PDU*/
                    socketRoutePtr = NULL_PTR;
                }
                else if(pduHeader.PduLength <= rxPduLen)
                {
                    PduInfoType pduInfo;
                    pduInfo.SduDataPtr = DataPtr;
                    pduInfo.SduLength = pduHeader.PduLength;
                    /*SWS_SoAd_00567(2)*/
                    SoAd__CallUpIfRxIndication(socketRoutePtr, &pduInfo);
                }
                else if(SOAD_IFRX_IS_VALID_LENGTH(SOAD_IFRX_GET_BUFFER(ConnPtr), rxPduLen))
                {
                    /*SWS_SoAd_00567(1)*/
                    SoAd__SaveIfRxData(SOAD_IFRX_GET_BUFFER(ConnPtr), DataPtr, rxPduLen);
                }
                else
                {
                    /*SWS_SoAd_00693*/
                    SOAD_DET_REPORT_ERROR(SOAD_API_RX_INDICATION, SOAD_E_NOBUFS);
                    /*This PDU is discarded*/
                    socketRoutePtr = NULL_PTR;
                }
            }
            /*TP*/
            else if(pduHeader.PduLength > 0)
            {
                uint16 tmp = 0;
                PduInfoType pduInfo;

                socketRoutePtr = SOAD_GET_SOCKETROUTE_PTR(socketRoutId);
                pduInfo.SduDataPtr = DataPtr;
                pduInfo.SduLength = rxPduLen;
                if(SoAd__TpWithHeaderRxIndication(ConnPtr, socketRoutePtr, &pduInfo, &pduHeader, &tmp) != E_OK)
                {
                    /*This PDU is discarded*/
                    socketRoutePtr = NULL_PTR;
                }

                cachedLen += tmp;
            }
            else
            {
                /*SWS_SoAd_00562(4)*/
                /*PDU Length == 0 && UL == TP*/
                socketRoutePtr = NULL_PTR;
            }

            if(pduHeader.PduLength > DataLength)
            {
                /*These is the last PDU in received data.*/
                rxPduInfoPtr->SocketRoutePtr = socketRoutePtr;
                rxPduInfoPtr->PduLength = pduHeader.PduLength;
                rxPduInfoPtr->RemainLength = pduHeader.PduLength - DataLength;
            }

            /*SWS_SoAd_00559(4)*/
            DataLength -= rxPduLen;
            DataPtr = &DataPtr[rxPduLen];
        }
    }

    return processedLen - cachedLen;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: SoAd__StartTpReception
*
* Description:   Starts a TP session of reception.
*
* Inputs:        ConnPtr        - the socket connection's runtime data.
*                SocketRoutePtr - the Socket Route for receptions.
*                SduLength      - the SDU's length.
*                BufferSizePtr  - the buffer size Received by UpLayer Modules.
*
* Outputs:       If the session is started returns E_OK, otherwise returns E_NOT_OK.
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(Std_ReturnType, SOAD_CODE) SoAd__StartTpReception
(
    P2VAR(SoAd_ConnectionType, AUTOMATIC, AUTOMATIC) ConnPtr,
    P2CONST(SoAd_SocketRouteType, SOAD_CONFIG_DATA, AUTOMATIC) SocketRoutePtr,
    PduLengthType SduLength,
    P2VAR(PduLengthType, AUTOMATIC, AUTOMATIC) BufferSizePtr
)
{
    Std_ReturnType ret = E_NOT_OK;
    PduInfoType pdu = {NULL_PTR, 0};

    if(SoAd__IsEnabledRxRouting(ConnPtr, SocketRoutePtr) != E_OK)
    {
        /*SWS_SoAd_00600*/ /*Discard this PDU*/
    }
    /*SWS_SoAd_00571(1.a)*/
    else if(SoAd__CallUpStartOfReception(SocketRoutePtr, &pdu, SduLength, BufferSizePtr) != BUFREQ_OK)
    {
        /*SWS_SoAd_00572*/
        /*All received data will be discarded.*/
    }
    else if(SoAd__StartRxSession(ConnPtr, SocketRoutePtr, SduLength) == E_OK)
    {
        ret = E_OK;
    }
    else
    {
        /*Discard this PDU*/
        SoAd__CallUpTpRxIndication(SocketRoutePtr, E_NOT_OK);
    }

    return ret;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: SoAd__TpWithHeaderRxIndication
*
* Description:   Receives a TP's data with PduHeader.
*
* Inputs:        ConnPtr        - the socket connection's runtime data.
*                SocketRoutePtr - the Socket Route for reception.
*                PduInfoPtr     - the PDU information.
*                PduHeaderPtr   - the PDU header.
*                CachedLength   - the length of data cached into TP buffer
*
* Outputs:       If this data is processed returns E_OK, otherwise returns E_NOT_OK.
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(Std_ReturnType, SOAD_CODE) SoAd__TpWithHeaderRxIndication
(
    P2VAR(SoAd_ConnectionType, AUTOMATIC, AUTOMATIC) ConnPtr,
    P2CONST(SoAd_SocketRouteType, SOAD_CONFIG_DATA, AUTOMATIC) SocketRoutePtr,
    P2CONST(PduInfoType, AUTOMATIC, AUTOMATIC) PduInfoPtr,
    P2CONST(SoAd_PduHeaderType, AUTOMATIC, AUTOMATIC) PduHeaderPtr,
    P2VAR(uint16, AUTOMATIC, AUTOMATIC) CachedLength
)
{
    PduLengthType pduTotalLen = PduHeaderPtr->PduLength;
    Std_ReturnType ret = E_NOT_OK;
    uint16 cachedLen = 0;
    PduLengthType bufferSize = 0;

    if(SoAd__IsTpRxBufferEmpty(ConnPtr) != E_OK)
    {
        /*Save all data, including PduHeader, to the TpBuffer.*/
        pduTotalLen += SOAD_PDUHEADER_LENGTH;
        if(SoAd__CheckTpBufferLength(ConnPtr, pduTotalLen) == E_OK)
        {
            /*SWS_SoAd_00571(2)*/
            PduLengthType rxPduLen = PduInfoPtr->SduLength + SOAD_PDUHEADER_LENGTH;
            SoAd__SaveTpRxData(ConnPtr, &PduInfoPtr->SduDataPtr[-SOAD_PDUHEADER_LENGTH], rxPduLen);
            ret = E_OK;
            cachedLen = pduTotalLen;
        }
        else
        {
            /*SWS_SoAd_00693*/
            SOAD_DET_REPORT_ERROR(SOAD_API_RX_INDICATION, SOAD_E_NOBUFS);
        }
    }
    else if(SoAd__StartTpReception(ConnPtr, SocketRoutePtr, PduHeaderPtr->PduLength, &bufferSize) == E_OK)
    {
        PduInfoType pdu;
        PduLengthType rxLen = SOAD_MIN_LEN(bufferSize, PduInfoPtr->SduLength);

        pdu.SduLength = rxLen;
        pdu.SduDataPtr = PduInfoPtr->SduDataPtr;
        if((rxLen < pduTotalLen) && (SoAd__CheckTpBufferLength(ConnPtr, pduTotalLen - rxLen) != E_OK))
        {
            /*SWS_SoAd_00571(1.b)*/
            SoAd__StopRxSession(ConnPtr);
            SoAd__CallUpTpRxIndication(SocketRoutePtr, E_NOT_OK);
            /*SWS_SoAd_00693*/
            SOAD_DET_REPORT_ERROR(SOAD_API_RX_INDICATION, SOAD_E_NOBUFS);
        }
        else if(SoAd__IsCancelledRxSession(ConnPtr) == E_OK)
        {
            /*Discard this PDU*/
        }
        /*SWS_SoAd_00571(1.c)*/
        else if(SoAd__CallUpCopyRxData(SocketRoutePtr, &pdu, &bufferSize) == BUFREQ_OK)
        {
            if(rxLen < PduInfoPtr->SduLength)
            {
                /*Copy remain data to TpBuffer*/
                SoAd__SaveTpRxData(ConnPtr, &pdu.SduDataPtr[rxLen],
                                        PduInfoPtr->SduLength - rxLen);
                cachedLen = PduInfoPtr->SduLength - rxLen;
            }
            else if(SoAd__UpdateRxRemainLength(ConnPtr, rxLen) == 0)
            {
                /*SWS_SoAd_00571(1.d)*/
                SoAd__StopRxSession(ConnPtr);
                /*SWS_SoAd_00562(5)*/
                SoAd__CallUpTpRxIndication(SocketRoutePtr, E_OK);
            }
            else
            {
                /*
                 *  All received data were forwarded to Upper Layer Module.
                 *  But this PDU is not received completely.
                 */
            }
            ret = E_OK;
        }
        else
        {
            /*SWS_SoAd_00573*/
            SoAd__StopRxSession(ConnPtr);
            SoAd__CallUpTpRxIndication(SocketRoutePtr, E_NOT_OK);
            /*Discard this PDU*/
        }
    }
    else
    {
        /*Discard this PDU*/
    }

    *CachedLength = cachedLen;
    return ret;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: SoAd__TpRxIndication
*
* Description:   Receives a TP's data.
*
* Inputs:        ConnPtr        - the socket connection's runtime data.
*                SocketRoutePtr - the Socket Route for reception.
*                PduInfoPtr     - the PDU information.
*                CachedLength   - the length of data cached into TP buffer
*
* Outputs:       If this data is processed returns E_OK, otherwise returns E_NOT_OK.
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(Std_ReturnType, SOAD_CODE) SoAd__TpRxIndication
(
    P2VAR(SoAd_ConnectionType, AUTOMATIC, AUTOMATIC) ConnPtr,
    P2CONST(SoAd_SocketRouteType, SOAD_CONFIG_DATA, AUTOMATIC) SocketRoutePtr,
    P2CONST(PduInfoType, AUTOMATIC, AUTOMATIC) PduInfoPtr,
    P2VAR(uint16, AUTOMATIC, AUTOMATIC) CachedLength
)
{
    PduInfoType tmp = {NULL_PTR, 0};
    PduLengthType bufferSize = 0;
    uint16 cachedLen = 0;
    Std_ReturnType ret = E_NOT_OK;

    if(SoAd__IsCancelledRxSession(ConnPtr) == E_OK)
    {
        /*Discard this PDU*/
        /*the Cancel request will be handled in SoAd_MainFunction*/
    }
    else if(SoAd__IsTpRxBufferEmpty(ConnPtr) != E_OK)
    {
        /*SWS_SoAd_00568(2)*/
        if(SoAd__CheckTpBufferLength(ConnPtr, PduInfoPtr->SduLength) == E_OK)
        {
            SoAd__SaveTpRxData(ConnPtr, PduInfoPtr->SduDataPtr, PduInfoPtr->SduLength);
            cachedLen = PduInfoPtr->SduLength;
            ret = E_OK;
        }
        else
        {
            /*SWS_SoAd_00693*/
            SOAD_DET_REPORT_ERROR(SOAD_API_RX_INDICATION, SOAD_E_NOBUFS);
        }
    }
    else if(SoAd__CallUpCopyRxData(SocketRoutePtr, &tmp, &bufferSize) != E_OK)
    {
        /*SWS_SoAd_00570*/
        SoAd__CancelRxSession(ConnPtr);
        SOAD_SOCON_SET_CLOSE_EVENT(ConnPtr);
    }
    else if((bufferSize < PduInfoPtr->SduLength)
            && (SoAd__CheckTpBufferLength(ConnPtr, PduInfoPtr->SduLength - bufferSize) != E_OK))
    {
        /*Discard this PDU*/
        /*SWS_SoAd_00568(1.b)*/ /*SWS_SoAd_00693*/
        SOAD_DET_REPORT_ERROR(SOAD_API_RX_INDICATION, SOAD_E_NOBUFS);
    }
    else
    {
    	PduLengthType dummy;
        PduInfoType pdu;
        pdu.SduLength = SOAD_MIN_LEN(bufferSize, PduInfoPtr->SduLength);
        pdu.SduDataPtr = PduInfoPtr->SduDataPtr;
        /*SWS_SoAd_00571(1.c)*/
        if(SoAd__CallUpCopyRxData(SocketRoutePtr, &pdu, &dummy) == BUFREQ_OK)
        {
            if(bufferSize < PduInfoPtr->SduLength)
            {
                /*SWS_SoAd_00571(1.d)*/ /*Copy remain data to TpBuffer*/
                SoAd__SaveTpRxData(ConnPtr, &PduInfoPtr->SduDataPtr[bufferSize], PduInfoPtr->SduLength - bufferSize);
                cachedLen = PduInfoPtr->SduLength - bufferSize;
            }
            ret = E_OK;
        }
        else
        {
            /*SWS_SoAd_00570*/
            SoAd__CancelRxSession(ConnPtr);
            SOAD_SOCON_SET_CLOSE_EVENT(ConnPtr);
        }
    }

    *CachedLength = cachedLen;

    return ret;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: SoAd__CheckStrictPduHeaderLen
*
* Description:   Checks if the length of all contained PDUs match the length of
*                the whole message.
*                Shall only be set to TRUE if SoAdPduHeaderEnable is also set
*                to TRUE.
*
* Inputs:        DataPtr    - the data include PDU
*                DataLength - the length of data
*
* Outputs:       If the length is matched returns E_OK, otherwise returns E_NOT_OK.
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(Std_ReturnType, SOAD_CODE) SoAd__CheckStrictPduHeaderLen
(
    P2CONST(uint8, AUTOMATIC, AUTOMATIC) DataPtr,
    uint16 DataLength
)
{
    uint32 headerLen;
    Std_ReturnType ret = E_NOT_OK;

    while(DataLength >= SOAD_PDUHEADER_LENGTH)
    {
        headerLen = SOAD_ATOUL(&DataPtr[4]);
        DataLength -= SOAD_PDUHEADER_LENGTH;
        if(headerLen > DataLength)
        {
            /*avoid the length of the last PDU greater than zero, but without any data*/
            DataLength = headerLen;
            break;
        }
        else
        {
            DataLength -= headerLen;
            DataPtr = &DataPtr[headerLen + SOAD_PDUHEADER_LENGTH];
        }
    }

    if(0 == DataLength)
    {
        ret = E_OK;
    }

    return ret;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: SoAd__TcpMakePduHeader
*
* Description:   read and make the PduHeader from the buffer.
*
* Inputs:        DataPtr        - The Serialized PduHeader.
*                PduHeaderPtr   - The buffer to save structural PduHeader.
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(uint8, SOAD_CODE) SoAd__TcpMakePduHeader
(
    P2VAR(SoAd_ConnectionType, AUTOMATIC, AUTOMATIC) ConnPtr,
    P2CONST(uint8, AUTOMATIC, AUTOMATIC) DataPtr,
    PduLengthType DataLength,
    P2VAR(SoAd_PduHeaderType, AUTOMATIC, AUTOMATIC) PduHeaderPtr
)
{
    uint8 headerLen = ConnPtr->RxSession.ValidHeaderLen;
    uint8 usedLen = 0;

    if(DataLength >= SOAD_PDUHEADER_LENGTH - headerLen)
    {
        if(headerLen > 0)
        {
            /*SWS_SoAd_00559(2)*/
            P2VAR(uint8, AUTOMATIC, AUTOMATIC) bufferPtr = ConnPtr->RxSession.PduHeader;
            usedLen = SOAD_PDUHEADER_LENGTH - headerLen;
            SoAd__CopyData(&bufferPtr[headerLen], DataPtr, usedLen);
            SoAd__MakePduHeader(bufferPtr, PduHeaderPtr);
            ConnPtr->RxSession.ValidHeaderLen = 0;
        }
        else
        {
            usedLen = SOAD_PDUHEADER_LENGTH;
            SoAd__MakePduHeader(DataPtr, PduHeaderPtr);
        }
    }
    else
    {
        P2VAR(uint8, AUTOMATIC, AUTOMATIC) bufferPtr = ConnPtr->RxSession.PduHeader;

        /*SWS_SoAd_00559(1)*/
        SoAd__CopyData(&bufferPtr[headerLen], DataPtr, DataLength);
        ConnPtr->RxSession.ValidHeaderLen += DataLength;
    }

    return usedLen;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: SoAd__MakePduHeader
*
* Description:   read and make the PduHeader from the buffer.
*
* Inputs:        DataPtr        - The Serialized PduHeader.
*                PduHeaderPtr   - The buffer to save structural PduHeader.
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, SOAD_CODE) SoAd__MakePduHeader
(
    P2CONST(uint8, AUTOMATIC, AUTOMATIC) DataPtr,
    P2VAR(SoAd_PduHeaderType, AUTOMATIC, AUTOMATIC) PduHeaderPtr
)
{
    PduHeaderPtr->PduHeaderId = SOAD_ATOUL(DataPtr);
    DataPtr = &DataPtr[4];
    PduHeaderPtr->PduLength = SOAD_ATOUL(DataPtr);
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: SoAd__SerializePduHeader
*
* Description:   Serialize the PduHeaderId and PduHeaderLength to buffer.
*
* Inputs:        PduHeaderId        - The id of PduHeader
*                PduHeaderLength    - The length of PduData.
*                DataPtr            - The buffer used to save the PduHeader.
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, SOAD_CODE) SoAd__SerializePduHeader
(
    uint32 PduHeaderId,
    uint32 PduHeaderLength,
    P2VAR(uint8, AUTOMATIC, AUTOMATIC) DataPtr
)
{
    SOAD_ULTOA(PduHeaderId, DataPtr);
    DataPtr = &DataPtr[4];
    SOAD_ULTOA(PduHeaderLength, DataPtr);
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: SoAd__InitRxSession
*
* Description:   Initialize the TP session of reception.
*
* Inputs:        ConnPtr        - the socket connection's runtime data.
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, SOAD_CODE) SoAd__InitRxSession
(
    P2VAR(SoAd_ConnectionType, AUTOMATIC, AUTOMATIC) ConnPtr
)
{
    P2VAR(SoAd_RxSessionType, AUTOMATIC, AUTOMATIC) sessionPtr;
    P2CONST(SoAd_SocketConnectionType, SOAD_CONFIG_DATA, AUTOMATIC) configPtr;

    sessionPtr = &ConnPtr->RxSession;
    configPtr = ConnPtr->ConfigPtr;
    SoAd__ClearRxSession(sessionPtr);

    if(SOAD_SOCON_IS_TCP(ConnPtr))
    {
        /*initialize the Tcp rx buffer*/
        if(configPtr->IfBufferLength > 0)
        {
            sessionPtr->IfBuffer.TotalLength = configPtr->IfBufferLength;
            sessionPtr->IfBuffer.BufferPtr = SOAD_GET_BUFFER_PTR(configPtr->IfBufferOffset);
            sessionPtr->IfBuffer.UsedLength = 0;
        }

        if(configPtr->TpBufferLength > 0)
        {
            sessionPtr->TpBuffer.TotalLength = configPtr->TpBufferLength;
            sessionPtr->TpBuffer.BufferPtr = SOAD_GET_BUFFER_PTR(configPtr->TpBufferOffset);
            sessionPtr->TpBuffer.In = 0;
            sessionPtr->TpBuffer.Out = 0;
        }
    }
    else
    {     
         /*initialize the Udp rx buffer*/
        if(configPtr->IfBufferLength > 0)
        {
            sessionPtr->IfBuffer.TotalLength = configPtr->IfBufferLength;
            sessionPtr->IfBuffer.BufferPtr = SOAD_GET_BUFFER_PTR(configPtr->IfBufferOffset);
            sessionPtr->IfBuffer.UsedLength = 0;
        }

        if(configPtr->TpBufferLength > 0)
        {
            sessionPtr->TpBuffer.TotalLength = configPtr->TpBufferLength;
            sessionPtr->TpBuffer.BufferPtr = SOAD_GET_BUFFER_PTR(configPtr->TpBufferOffset);
            sessionPtr->TpBuffer.In = 0;
            sessionPtr->TpBuffer.Out = 0;
        }
    }
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: SoAd__ClearRxSession
*
* Description:   Clear the TP session of reception.
*
* Inputs:        SessionPtr        - the RX session
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, SOAD_CODE) SoAd__ClearRxSession
(
    P2VAR(SoAd_RxSessionType, AUTOMATIC, AUTOMATIC) SessionPtr
)
{
    SessionPtr->ValidHeaderLen = 0;
    SessionPtr->ProcessPduInfo.PduLength = 0;
    SessionPtr->ProcessPduInfo.RemainLength = 0;
    SessionPtr->ProcessPduInfo.SocketRoutePtr = NULL_PTR;
    SessionPtr->RxPduInfo.PduLength = 0;
    SessionPtr->RxPduInfo.RemainLength = 0;
    SessionPtr->RxPduInfo.SocketRoutePtr = NULL_PTR;
    SessionPtr->IfBuffer.UsedLength = 0;
    SessionPtr->TpBuffer.In = 0;
    SessionPtr->TpBuffer.Out = 0;
    SOAD_SESSION_SET_IDLE(SessionPtr);
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: SoAd__StartRxSession
*
* Description:   Start the TP session of reception.
*
* Inputs:        ConnPtr        - the socket connection's runtime data.
*                SocketRoutePtr - the pointer of the SocketRoute configuration.
*
* Outputs:       If the Session is IDLE returns OK, otherwise returns NOT_OK.
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(Std_ReturnType, SOAD_CODE) SoAd__StartRxSession
(
    P2VAR(SoAd_ConnectionType, AUTOMATIC, AUTOMATIC) ConnPtr,
    P2CONST(SoAd_SocketRouteType, SOAD_CONFIG_DATA, AUTOMATIC) SocketRoutePtr,
    PduLengthType PduLength
)
{
    Std_ReturnType ret = E_NOT_OK;
    
    SOAD_ENTER_CRITICAL_SECTION_RX_SESSION_IDX();
    if(SOAD_SESSION_IS_IDLE(&ConnPtr->RxSession))
    {
        SOAD_SESSION_SET_TP(&ConnPtr->RxSession);
        ConnPtr->RxSession.ProcessPduInfo.SocketRoutePtr = SocketRoutePtr;
        ConnPtr->RxSession.ProcessPduInfo.PduLength = PduLength;
        ConnPtr->RxSession.ProcessPduInfo.RemainLength = PduLength;

        ret = E_OK;
    }
    else if(SOAD_SESSION_IS_TP(&ConnPtr->RxSession))
    {
        ret = E_OK;
    }
    
    SOAD_LEAVE_CRITICAL_SECTION_RX_SESSION_IDX();

    return ret;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: SoAd__CancelRxSession
*
* Description:   Cancels the TP session of reception.
*
* Inputs:        ConnPtr        - the socket connection's runtime data.
*                SocketRoutePtr - the pointer of the SocketRoute configuration.
*
* Outputs:       If the Session is TP returns OK, otherwise returns NOT_OK.
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(Std_ReturnType, SOAD_CODE) SoAd__CancelRxSession
(
    P2VAR(SoAd_ConnectionType, AUTOMATIC, AUTOMATIC) ConnPtr
)
{
    Std_ReturnType ret = E_NOT_OK;
    
    SOAD_ENTER_CRITICAL_SECTION_RX_SESSION_IDX();
    if(SOAD_SESSION_IS_TP(&ConnPtr->RxSession))
    {
        SOAD_SESSION_SET_TP_CANCELLED(&ConnPtr->RxSession);
        ret = E_OK;
    }
    
    SOAD_LEAVE_CRITICAL_SECTION_RX_SESSION_IDX();

    return ret;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: SoAd__DisactiveRxSession
*
* Description:   Disactive the Rx session.
*
* Inputs:        ConnPtr    - the socket connection's runtime data.
*
* Outputs:       none
*
* Limitations:   The () must be locked before this function is called.
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, SOAD_CODE) SoAd__DisactiveRxSession
(
    P2VAR(SoAd_ConnectionType, AUTOMATIC, AUTOMATIC) ConnPtr
)
{
    P2VAR(SoAd_RxSessionType, AUTOMATIC, AUTOMATIC) rxSessionPtr;
    P2CONST(SoAd_SocketRouteType, SOAD_CONFIG_DATA, AUTOMATIC) routePtr;

	SOAD_ENTER_CRITICAL_SECTION_RX_SESSION_IDX();
    rxSessionPtr = &ConnPtr->RxSession;
    if(rxSessionPtr->ProcessPduInfo.SocketRoutePtr != NULL_PTR)
    {
        routePtr = rxSessionPtr->ProcessPduInfo.SocketRoutePtr;
        SoAd__ClearRxSession(rxSessionPtr);
        
        SOAD_LEAVE_CRITICAL_SECTION_RX_SESSION_IDX();

        /*SWS_SoAd_00641*/ /*SWS_SoAd_00570*/
        SoAd__CallUpTpRxIndication(routePtr, E_NOT_OK);
        
    }
    else
    {
        SOAD_LEAVE_CRITICAL_SECTION_RX_SESSION_IDX();
    }
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: SoAd__IsCancelledRxSession
*
* Description:   Check if the state of session is TP_CANCELLED.
*
* Inputs:        ConnPtr        - the socket connection's runtime data.
*
* Outputs:       If the Session is TP_CANCELLED returns OK, otherwise returns  NOT_OK.
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(Std_ReturnType, SOAD_CODE) SoAd__IsCancelledRxSession
(
    P2VAR(SoAd_ConnectionType, AUTOMATIC, AUTOMATIC) ConnPtr
)
{
    Std_ReturnType ret = E_NOT_OK;
    
    if(SOAD_SESSION_IS_TP_CANCELLED(&ConnPtr->RxSession))
    {
        ret = E_OK;
    }
    
    return ret;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: SoAd__StopRxSession
*
* Description:   Stops a active TP Reception.
*
* Inputs:        ConnPtr    - the socket connection's runtime data.
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, SOAD_CODE) SoAd__StopRxSession
(
    P2VAR(SoAd_ConnectionType, AUTOMATIC, AUTOMATIC) ConnPtr
)
{
    
	SOAD_ENTER_CRITICAL_SECTION_RX_SESSION_IDX();
    if(!SOAD_SESSION_IS_IDLE(&ConnPtr->RxSession))
    {
        ConnPtr->RxSession.ProcessPduInfo.SocketRoutePtr = NULL_PTR;
        ConnPtr->RxSession.ProcessPduInfo.PduLength = 0;
        ConnPtr->RxSession.ProcessPduInfo.RemainLength = 0;
        SOAD_SESSION_SET_IDLE(&ConnPtr->RxSession);
    }
    
    SOAD_LEAVE_CRITICAL_SECTION_RX_SESSION_IDX();
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: SoAd__UpdateRxRemainLength
*
* Description:   Update the remain length and returns it.
*
* Inputs:        ConnPtr        - the socket connection's runtime data.
*                ReceivedLen    - the received length of data
*
* Outputs:       The updated remain length
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(uint16, SOAD_CODE) SoAd__UpdateRxRemainLength
(
    P2VAR(SoAd_ConnectionType, AUTOMATIC, AUTOMATIC) ConnPtr,
    uint16 ReceivedLen
)
{
    uint16 remainLength;
    
    SOAD_ENTER_CRITICAL_SECTION_RX_SESSION_IDX();
    remainLength = ConnPtr->RxSession.ProcessPduInfo.RemainLength;
    if(remainLength > ReceivedLen)
    {
        remainLength -= ReceivedLen;
    }
    else
    {
        remainLength = 0;
    }
    ConnPtr->RxSession.ProcessPduInfo.RemainLength = remainLength;
    
    SOAD_LEAVE_CRITICAL_SECTION_RX_SESSION_IDX();

    return remainLength;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: SoAd__SaveIfRxData
*
* Description:   Save the data to RxBuffer.
*
* Inputs:        RxBufferPtr    - the Rx buffer in a socket connection's Rx session
*                DataPtr        - the data
*                DataLength     - the length of data
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, SOAD_CODE) SoAd__SaveIfRxData
(
    P2VAR(SoAd_RxBufferType, AUTOMATIC, AUTOMATIC) RxBufferPtr,
    P2CONST(uint8, AUTOMATIC, AUTOMATIC) DataPtr,
    uint16 DataLength
)
{
    SoAd__CopyData(&RxBufferPtr->BufferPtr[RxBufferPtr->UsedLength], DataPtr, DataLength);
    RxBufferPtr->UsedLength += DataLength;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: SoAd__SaveTpRxData
*
* Description:   Save the data to TpRxBuffer.
*
* Inputs:        ConnPtr    - the socket connection's runtime data.
*                DataPtr    - the data
*                DataLength - the length of data
*
* Outputs:       None
*
* Limitations:   call SoAd__CheckTpBufferLength to check if the DataLength is valid
*                before save the data to TpBuffer.
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, SOAD_CODE) SoAd__SaveTpRxData
(
    P2VAR(SoAd_ConnectionType, AUTOMATIC, AUTOMATIC) ConnPtr,
    P2CONST(uint8, AUTOMATIC, AUTOMATIC) DataPtr,
    uint16 DataLength
)
{
    P2VAR(SoAd_RxFifoType, AUTOMATIC, AUTOMATIC) tpBuffer;
    uint16 in;
    uint16 length;

    tpBuffer = SOAD_TPRX_GET_BUFFER(ConnPtr);

    in = tpBuffer->In;
    length = SOAD_MIN_LEN(DataLength, tpBuffer->TotalLength - in);

    SoAd__CopyData(&tpBuffer->BufferPtr[in], DataPtr, length);
    SoAd__CopyData(tpBuffer->BufferPtr, &DataPtr[length], DataLength - length);

    tpBuffer->In += DataLength;

}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: SoAd__IsTpRxBufferEmpty
*
* Description:   check if the TP buffer is empty.
*
* Inputs:        ConnPtr    - the socket connection's runtime data.
*
* Outputs:       If the TP buffer is empty returns E_Ok, otherwise returns E_NOT_OK.
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(Std_ReturnType, SOAD_CODE) SoAd__IsTpRxBufferEmpty
(
    P2VAR(SoAd_ConnectionType, AUTOMATIC, AUTOMATIC) ConnPtr
)
{
    P2VAR(SoAd_RxFifoType, AUTOMATIC, AUTOMATIC) tpBuffer;
    Std_ReturnType ret = E_NOT_OK;

    tpBuffer = SOAD_TPRX_GET_BUFFER(ConnPtr);
    if(0 == (SOAD_TPRX_GET_USED_LENGTH(tpBuffer)))
    {
        ret = E_OK;
    }

    return ret;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: SoAd__CheckTpBufferLength
*
* Description:   check if the DataLength is valid.
*
* Inputs:        ConnPtr    - the socket connection's runtime data.
*                DataLength - the length of data
*
* Outputs:       If the DataLength is valid returns E_Ok, otherwise returns E_NOT_OK
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(Std_ReturnType, SOAD_CODE) SoAd__CheckTpBufferLength
(
    P2VAR(SoAd_ConnectionType, AUTOMATIC, AUTOMATIC) ConnPtr,
    uint16 DataLength
)
{
    P2VAR(SoAd_RxFifoType, AUTOMATIC, AUTOMATIC) tpBuffer;
    Std_ReturnType ret = E_NOT_OK;

    tpBuffer = SOAD_TPRX_GET_BUFFER(ConnPtr);
    if((DataLength > 0) && (SOAD_TPRX_GET_UNUSED_LENGTH(tpBuffer) >= DataLength))
    {
        ret = E_OK;
    }

    return ret;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: SoAd__DiscardTpRxData
*
* Description:   Discard the data in the TP Buffer.
*
* Inputs:        ConnPtr        - the socket connection's runtime data.
*                DataLength     - the max length of discarded data.
*
* Outputs:       the length of discarded data.
*
* Limitations:   This function is only called by SoAd__MainFunction
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(uint16, SOAD_CODE) SoAd__DiscardTpRxData
(
    P2VAR(SoAd_ConnectionType, AUTOMATIC, AUTOMATIC) ConnPtr,
    uint16 DataLength
)
{
    P2VAR(SoAd_RxFifoType, AUTOMATIC, AUTOMATIC) tpBuffer;
    uint16 discardLen;
    uint16 usedLen;

    tpBuffer = SOAD_TPRX_GET_BUFFER(ConnPtr);
    usedLen = SOAD_TPRX_GET_USED_LENGTH(tpBuffer);
    discardLen = SOAD_MIN_LEN(usedLen, DataLength);

    tpBuffer->Out += discardLen;
    return discardLen;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: SoAd__MakePduHeaderFromTpBuffer
*
* Description:   read and make the PduHeader from the buffer.
*
* Inputs:        ConnPtr        - the socket connection's runtime data.
*                PduHeaderPtr   - The buffer to save structural PduHeader.
*
* Outputs:       If the Pdu Header is maked returns E_OK, otherwise returns E_NOT_OK.
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(Std_ReturnType, SOAD_CODE) SoAd__MakePduHeaderFromTpBuffer
(
    P2VAR(SoAd_ConnectionType, AUTOMATIC, AUTOMATIC) ConnPtr,
    P2VAR(SoAd_PduHeaderType, SOAD_CONFIG_DATA, AUTOMATIC) PduHeaderPtr
)
{
    P2VAR(SoAd_RxFifoType, AUTOMATIC, AUTOMATIC) tpBuffer;
    uint8 pduBuffer[SOAD_PDUHEADER_LENGTH];
    uint16 tmp;
    uint16 out;
    uint16 usedLen;
    Std_ReturnType ret = E_NOT_OK;

    tpBuffer = SOAD_TPRX_GET_BUFFER(ConnPtr);
    usedLen = SOAD_TPRX_GET_USED_LENGTH(tpBuffer);
    if(usedLen >= SOAD_PDUHEADER_LENGTH)
    {
        out = tpBuffer->Out;
        tmp = SOAD_MIN_LEN(SOAD_PDUHEADER_LENGTH, tpBuffer->TotalLength - out);
        SoAd__CopyData(pduBuffer, &tpBuffer->BufferPtr[out], tmp);
        SoAd__CopyData(&pduBuffer[tmp], tpBuffer->BufferPtr, SOAD_PDUHEADER_LENGTH - tmp);

        SoAd__MakePduHeader(pduBuffer, PduHeaderPtr);

        tpBuffer->Out += SOAD_PDUHEADER_LENGTH;
        ret = E_OK;
    }

    return ret;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: SoAd__DispatchTpRxData
*
* Description:   Read the data from TpRxBuffer and dispatch them to UpLayer Module.
*                If all of data were dispatch to UpLayer Module Call the TpRxIndication.
*
* Inputs:        ConnPtr        - the socket connection's runtime data.
*                SocketRoutePtr - the socket route's configuration.
*                DataLength     - the max length of data dispatched to UpLayer.
*
* Outputs:       If the data are dispatched to UpLayer Module returns E_OK, otherwise
*                returns E_NOT_OK.
*
* Limitations:   This function is only called by SoAd__MainFunction
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(Std_ReturnType, SOAD_CODE) SoAd__DispatchTpRxData
(
    P2VAR(SoAd_ConnectionType, AUTOMATIC, AUTOMATIC) ConnPtr,
    P2CONST(SoAd_SocketRouteType, SOAD_CONFIG_DATA, AUTOMATIC) SocketRoutePtr,
    P2VAR(uint16, AUTOMATIC, AUTOMATIC) DataLength
)
{
    P2VAR(SoAd_RxFifoType, AUTOMATIC, AUTOMATIC) tpBuffer;
    PduInfoType pdu;
    uint16 tmp;
    uint16 out;
    uint16 usedLen;
    uint16 rxLen;
    uint16 length = *DataLength;
    Std_ReturnType ret = E_NOT_OK;
    PduLengthType bufferSize = 0;

    tpBuffer = SOAD_TPRX_GET_BUFFER(ConnPtr);
    usedLen = SOAD_TPRX_GET_USED_LENGTH(tpBuffer);

    rxLen = SOAD_MIN_LEN(usedLen, length);
    out = tpBuffer->Out;
    tmp = rxLen;

    pdu.SduDataPtr = &tpBuffer->BufferPtr[out];
    pdu.SduLength = tmp;
    /*Dispatch data to UpLayer Module*/
    if(SoAd__CallUpCopyRxData(SocketRoutePtr, &pdu, &bufferSize) != BUFREQ_OK)
    {
        length = 0;
    }
    else if((bufferSize > 0) && (tmp < rxLen))
    {
        length = tmp;

        tmp = SOAD_MIN_LEN(bufferSize, rxLen - tmp);
        pdu.SduDataPtr = tpBuffer->BufferPtr;
        pdu.SduLength = tmp;
        if(SoAd__CallUpCopyRxData(SocketRoutePtr, &pdu, &bufferSize) == BUFREQ_OK)
        {
            length += tmp;
            ret = E_OK;
        }
        else
        {
            length = 0;
        }
    }
    else
    {
        ret = E_OK;
        length = tmp;
    }

    /*Update the TP buffer index*/
    *DataLength = length;
    tpBuffer->Out += length;

    if(tpBuffer->Out == tpBuffer->In)
    {
        /* Clear buffer index when it is empty */
        tpBuffer->Out = 0;
        tpBuffer->In = 0;
    }

    return ret;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: SoAd__IsEnabledRxRouting
*
* Description:   Check If the routing Group is enabled.
*
* Inputs:        ConnPtr        - the socket connection's runtime data.
*                SocketRoutePtr - the configuration of socket route.
*
* Outputs:       If any routing group is enabled returns E_OK, otherwise returns
*                E_NOT_OK.
*
* Limitations:   the SocketRoute must refer to the SocketConnection.
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(Std_ReturnType, SOAD_CODE) SoAd__IsEnabledRxRouting
(
    P2VAR(SoAd_ConnectionType, AUTOMATIC, AUTOMATIC) ConnPtr,
    P2CONST(SoAd_SocketRouteType, SOAD_CONFIG_DATA, AUTOMATIC) SocketRoutePtr
)
{
    SoAd_SoConIdType idx;

    idx = ConnPtr->SoConId - SocketRoutePtr->SoConId;
    return SoAd_IsEnabledRouting(&SocketRoutePtr->RoutingCtrlList[idx]);
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: SoAd__CallUpSoConModeChg
*
* Description:   Call the SoConModeChg callback of the UpLayer Module
*
* Inputs:        Index      - The index of UpLayer Module.
*                SoConId    - The Socket Connection's Id.
*                SoConMode  - The Socket Connection's mode.
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, SOAD_CODE) SoAd__CallUpSoConModeChg
(
    SoAd_ULIndexType Index,
    SoAd_SoConIdType SoConId,
    SoAd_SoConModeType SoConMode
)
{
    P2CONST(SoAd_UpLayerInterfaceType, SOAD_CONFIG_DATA, AUTOMATIC) interface;
    /*SWS_SoAd_00597*/
    interface = SOAD_GET_UL_INTERFACE(Index);
    if(interface->SoConModeChg != NULL_PTR)
    {
        interface->SoConModeChg(SoConId, SoConMode);
    }
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: SoAd__CallUpLocalIpAddrAssignmentChg
*
* Description:   Call the LocalIpAddrAssignmentChg callback of the UpLayer Module
*
* Inputs:        Index      - The index of UpLayer Module.
*                SoConId    - The Socket Connection's Id.
*                State      - The Local IP's State.
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, SOAD_CODE) SoAd__CallUpLocalIpAddrAssignmentChg
(
    SoAd_ULIndexType Index,
    SoAd_SoConIdType SoConId,
    TcpIp_IpAddrStateType State
)
{
    P2CONST(SoAd_UpLayerInterfaceType, SOAD_CONFIG_DATA, AUTOMATIC) interface;

    interface = SOAD_GET_UL_INTERFACE(Index);
    if(interface->LocalIpAddrAssignmentChg != NULL_PTR)
    {
        interface->LocalIpAddrAssignmentChg(SoConId, State);
    }
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: SoAd__CallUpIfRxIndication
*
* Description:   Call the IfRxIndication callback of the UpLayer Module by Socket
*                Route's RxPduId
*
* Inputs:        SocketRoutePtr - the pointer of the SocketRoute configuration.
*                PduInfoPtr     - the pointer of the PDU information.
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, SOAD_CODE) SoAd__CallUpIfRxIndication
(
    P2CONST(SoAd_SocketRouteType, SOAD_CONFIG_DATA, AUTOMATIC) SocketRoutePtr,
    P2CONST(PduInfoType, AUTOMATIC, AUTOMATIC) PduInfoPtr
)
{
    P2CONST(SoAd_UpLayerInterfaceType, SOAD_CONFIG_DATA, AUTOMATIC) interface;

    interface = SOAD_GET_UL_INTERFACE(SocketRoutePtr->ULIndex);
    if(interface->IfRxIndication != NULL_PTR)
    {
        interface->IfRxIndication(SocketRoutePtr->RxPduId, PduInfoPtr);
    }
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: SoAd__CallUpIfTriggerTransmit
*
* Description:   Call the IfTriggerTransmit callback of the UpLayer Module by PDU
*                Route's TxPduId
*
* Inputs:        PduRoutePtr    - the pointer of the PduRoute configuration.
*                PduInfoPtr     - the pointer of the PDU information.
*
* Outputs:       If the data has been copied into buffer returns OK, otherwise
*                returns NOT_OK.
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(Std_ReturnType, SOAD_CODE) SoAd__CallUpIfTriggerTransmit
(
    P2CONST(SoAd_PduRouteType, SOAD_CONFIG_DATA, AUTOMATIC) PduRoutePtr,
    P2VAR(PduInfoType, AUTOMATIC, AUTOMATIC) PduInfoPtr
)
{
    P2CONST(SoAd_UpLayerInterfaceType, SOAD_CONFIG_DATA, AUTOMATIC) interface;
    Std_ReturnType ret = E_NOT_OK;

    interface = SOAD_GET_UL_INTERFACE(PduRoutePtr->ULIndex);
    if(interface->IfTriggerTransmit != NULL_PTR)
    {
        ret = interface->IfTriggerTransmit(PduRoutePtr->TxPduId, PduInfoPtr);
    }

    return ret;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: SoAd__CallUpIfTxConfirmation
*
* Description:   Call the IfTxConfirmation callback of the UpLayer Module by PDU
*                Route's TxPduId
*
* Inputs:        PduRoutePtr    - the pointer of the PduRoute configuration.
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, SOAD_CODE) SoAd__CallUpIfTxConfirmation
(
    P2CONST(SoAd_PduRouteType, SOAD_CONFIG_DATA, AUTOMATIC) PduRoutePtr
)
{
    P2CONST(SoAd_UpLayerInterfaceType, SOAD_CONFIG_DATA, AUTOMATIC) interface;

    interface = SOAD_GET_UL_INTERFACE(PduRoutePtr->ULIndex);
    if(interface->IfTxConfirmation != NULL_PTR)
    {
        interface->IfTxConfirmation(PduRoutePtr->TxPduId);
    }
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: SoAd__CallUpCopyTxData
*
* Description:   Call the CopyTxData callback of the UpLayer Module by PDU Route's
*                TxPduId
*
* Inputs:        PduRoutePtr        - the pointer of the PduRoute configuration.
*                PduInfoPtr         - the pointer of the PDU information.
*                RetryPtr           - the pointer of the Retry information.
*                AvailableDataPtr   - the pointer of the available data.
*
* Outputs:       If the data were copied by the UpLayer modlue returns OK,
*                otherwise returns NOT_OK.
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(BufReq_ReturnType, SOAD_CODE) SoAd__CallUpCopyTxData
(
    P2CONST(SoAd_PduRouteType, SOAD_CONFIG_DATA, AUTOMATIC) PduRoutePtr,
    P2CONST(PduInfoType, AUTOMATIC, AUTOMATIC) PduInfoPtr,
    P2VAR(RetryInfoType, AUTOMATIC, AUTOMATIC) RetryPtr,
    P2VAR(PduLengthType, AUTOMATIC, AUTOMATIC) AvailableDataPtr
)
{
    P2CONST(SoAd_UpLayerInterfaceType, SOAD_CONFIG_DATA, AUTOMATIC) interface;
    BufReq_ReturnType ret = BUFREQ_E_NOT_OK;

    interface = SOAD_GET_UL_INTERFACE(PduRoutePtr->ULIndex);
    if(interface->CopyTxData != NULL_PTR)
    {
        ret = interface->CopyTxData(PduRoutePtr->TxPduId, PduInfoPtr, RetryPtr, AvailableDataPtr);
    }

    return ret;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: SoAd__CallUpTpTxConfirmation
*
* Description:   Call the TpTxConfirmation callback of the UpLayer Module by PDU
*                Route's TxPduId
*
* Inputs:        PduRoutePtr    - the pointer of the PduRoute configuration.
*                Result         - the result of TP Transmission.
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, SOAD_CODE) SoAd__CallUpTpTxConfirmation
(
    P2CONST(SoAd_PduRouteType, SOAD_CONFIG_DATA, AUTOMATIC) PduRoutePtr,
    Std_ReturnType Result
)
{
    P2CONST(SoAd_UpLayerInterfaceType, SOAD_CONFIG_DATA, AUTOMATIC) interface;

    interface = SOAD_GET_UL_INTERFACE(PduRoutePtr->ULIndex);
    if(interface->TpTxConfirmation != NULL_PTR)
    {
        interface->TpTxConfirmation(PduRoutePtr->TxPduId, Result);
    }
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: SoAd__CallUpStartOfReception
*
* Description:   Call the StartOfReception callback of the UpLayer Module by Socket
*                Route's RxPduId
*
* Inputs:        SocketRoutePtr - the pointer of the SocketRoute configuration.
*                PduInfoPtr     - the pointer of the PDU information.
*                TpSduLength    - the Total Length of the PDU
*                bufferSizePtr  - the pointer of the available size.
*
* Outputs:       If the connection has been accepted returns OK, otherwise returns
*                NOT_OK
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(BufReq_ReturnType, SOAD_CODE) SoAd__CallUpStartOfReception
(
    P2CONST(SoAd_SocketRouteType, SOAD_CONFIG_DATA, AUTOMATIC) SocketRoutePtr,
    P2CONST(PduInfoType, AUTOMATIC, AUTOMATIC) PduInfoPtr,
    PduLengthType TpSduLength,
    P2VAR(PduLengthType, AUTOMATIC, AUTOMATIC) bufferSizePtr
)
{
    P2CONST(SoAd_UpLayerInterfaceType, SOAD_CONFIG_DATA, AUTOMATIC) interface;
    BufReq_ReturnType ret = BUFREQ_E_NOT_OK;

    interface = SOAD_GET_UL_INTERFACE(SocketRoutePtr->ULIndex);
    if(interface->StartOfReception != NULL_PTR)
    {
        ret = interface->StartOfReception(SocketRoutePtr->RxPduId, PduInfoPtr, TpSduLength, bufferSizePtr);
    }

    return ret;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: SoAd__CallUpCopyRxData
*
* Description:   Call the CopyRxData callback of the UpLayer Module by PDU Route's
*                RxPduId
*
* Inputs:        SocketRoutePtr - the pointer of the SocketRoute configuration.
*                PduInfoPtr     - the pointer of the PDU information.
*                bufferSizePtr  - the pointer of the available size.
*
* Outputs:       If the data has been received returns OK, otherwise returns NOT_OK.
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(BufReq_ReturnType, SOAD_CODE) SoAd__CallUpCopyRxData
(
    P2CONST(SoAd_SocketRouteType, SOAD_CONFIG_DATA, AUTOMATIC) SocketRoutePtr,
    P2CONST(PduInfoType, AUTOMATIC, AUTOMATIC) PduInfoPtr,
    P2VAR(PduLengthType, AUTOMATIC, AUTOMATIC) bufferSizePtr
)
{
    P2CONST(SoAd_UpLayerInterfaceType, SOAD_CONFIG_DATA, AUTOMATIC) interface;
    BufReq_ReturnType ret = BUFREQ_E_NOT_OK;

    interface = SOAD_GET_UL_INTERFACE(SocketRoutePtr->ULIndex);
    if(interface->CopyRxData != NULL_PTR)
    {
        ret = interface->CopyRxData(SocketRoutePtr->RxPduId, PduInfoPtr, bufferSizePtr);
    }

    return ret;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: SoAd__CallUpTpRxIndication
*
* Description:   Call the TpRxIndication callback of the UpLayer Module by Socket
*                Route's RxPduId
*
* Inputs:        SocketRoutePtr - the pointer of the SocketRoute configuration.
*                Result         - the result of TP Reception.
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, SOAD_CODE) SoAd__CallUpTpRxIndication
(
    P2CONST(SoAd_SocketRouteType, SOAD_CONFIG_DATA, AUTOMATIC) SocketRoutePtr,
    Std_ReturnType Result
)
{
    P2CONST(SoAd_UpLayerInterfaceType, SOAD_CONFIG_DATA, AUTOMATIC) interface;

    interface = SOAD_GET_UL_INTERFACE(SocketRoutePtr->ULIndex);
    if(interface->TpRxIndication != NULL_PTR)
    {
        interface->TpRxIndication(SocketRoutePtr->RxPduId, Result);
    }
}

#define SOAD_STOP_SEC_CODE
#include "MemMap.h"
