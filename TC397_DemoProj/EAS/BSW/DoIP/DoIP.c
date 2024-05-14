/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
*   File Name       : DoIP.c
********************************************************************************
*   Project/Product : DoIP Module
*   Title           : DoIP.c
*   Author          : qing.wang
********************************************************************************
*   Description     : DoIP source code
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
*   01.00.00    01/09/2017    qing.wang     N/A          Original
*   01.00.01    15/02/2019    jinbao.tang   N/A          1.add critical section protection
                                                         2.add MemMap define
                                                         3.change the function DoIP_DiagnosticMessageReceive return value,
                                                         prevent SoAd close socket; and change the initial value of return value
                                                         4.repair routActiv request length calculation err,and add OEM reserved filed
                                                         5.clear DOIP_GEN_HDR_NACK_OUT_OF_MEMORY flag
    01.00.02    24/03/2019    jinbao.tang   N/A          1.QAC test
    01.00.03    02/04/2019    jinbao.tang   N/A          1.after debugging
    01.00.04    21/10/2019    beibei.xing   N/A          ETH422_DoIP_20191021_01
	01.00.05    22/11/2019    beibei.xing   N/A          ETH422_DoIP_20191122_01
    01.00.06    04/09/2020    beibei.xing   N/A          ETH422_DoIP_20200904_01
    01.00.07    08/04/2022    zeyu.ren      N/A          Bug fix: routing activation response with correct OEM reserved field length
    01.00.08    16/09/2022    zeyu.ren      N/A          ETH422_DoIP_20220916_01
    01.00.09    09/10/2022    zeyu.ren      N/A          ETH422_DoIP_20221009_01
    01.00.10    16/01/2023    yanheng.he    N/A          Bug fix: 1.DoIP node can also request for ip assignment
                                                                  2.GetGidCallback can be used
                                                                  3.Fix GID error
                                                                  4.Fix vehicle announcement time error
    01.00.11    21/04/2023    yanheng.he    N/A          Bug fix: 1.Fix option OEM in routing activation response.  
                                                                  2.Fix uninitialized parameter in DoIP_TryRoutingActivation: routActivId. 
    01.00.12    23/04/2023    yanheng.he    N/A          Bug fix: 1.Fix uninitialized ISO bytes in routing activation response. 
    01.00.13    15/05/2023    yanheng.he    N/A          Bug fix: 1. Cancel unstable type cast
    01.00.14    26/05/2023    yanheng.he    N/A          Bug fix: 1. Parameters allClose and id of DoIP_SoConModeChg are undefined. 
    01.00.15    01/06/2023    yanheng.he    N/A          QAC warning fix:  Add "#if" to parameters allClose and id.
    01.01.00    06/06/2023    yanheng.he    N/A          New function: 1.Diagnostic Ack/Nack can carry last diagnostic message data.
    01.01.01    13/07/2023    yanheng.he    N/A          Bug fix: 1.DoIP quickly send TCP non-diagnostic packets and the coverage will occur.
                                                                  2.If connection is closed and UL response a diagnostic packet by DoIP_TpTransmit,
                                                                    the array access violation will occur because of error 'conId'.
    01.01.02    21/07/2023    yanheng.he    N/A          Stack space optimization.
    01.01.03    04/08/2023    yanheng.he    N/A          Bug fix: Uninitial parameter 'routActivId' in function 'DoIP_RoutingActivationReqHandler'
    01.01.04    10/10/2023    yanheng.he    N/A          Bug fix: 1.FutherAction Byte of Vehicle Announcement error;
                                                                  2.User defined function 'GetPowerMode' can not be used in Power-Mode message;
                                                                  3.Fix 'DoIP_TpCancelReceive' error;
                                                                  4.Add Det for function 'DoIP_LocalIpAddrAssignmentChg'.
    01.01.05    13/10/2023    yanheng.he    N/A          Bug fix: 1.Add Det for DoIP_SoAdTpCopyTxData to check if the socket is ONLINE.
    01.02.00    17/10/2023    zeyu.ren      N/A          Add support for HOZON standard.
    01.02.01    14/11/2023    min.zhang3    N/A          HOZON standard test.
    01.02.02    28/11/2023    yanheng.he    N/A          Add macro "DOIP_HOZON_PLATFORM"
********************************************************************************
* END_FILE_HDR*/

/******************************************************************************
*   General QAC Suppression
******************************************************************************/
/*PRQA S 791,792 EOF*/
/* Relevant names of WDGM_AR_RELEASE_REVISION_VERSION may not follow relevant naming rule */

/*PRQA S 1860-1864,3383,3384 EOF*/
/* Comparison,++,equal operation,will change into integer.This problem is risk-free and can't be revised */

/*PRQA S 3429,3453 EOF*/
/* P2VAR and other macros in the Compiler conforms to AUTOSAR standard.There's no need to revise */

/*PRQA S 3138,3141 EOF*/
/* The code of critical segments can be configured as void when QAC testing */

/*PRQA S 3214,3614,862 EOF*/
/* According to the requirements of AUTOSAR Specification,when locating address segments in the files of each module,
 * #include "MemMap.h" is required.Defined XXX_START_SEC_ will undefine in MemMap.h */

/*PRQA S 3138 EOF*/
/* P2VAR and other macros in the Compiler conforms to AUTOSAR standard.There's no need to revise */

/*PRQA S 4700 EOF*/
/* Caused by some long branches */

/*PRQA S 310,751 EOF*/
/* Transfor the steam data into the structure */
/*******************************************************************************
*   Includes
*******************************************************************************/
/*SWS_DoIP_00158, SWS_DoIP_00157*/

#include "DoIP.h"
#include "DoIP_Version.h"
#include "DoIP_Cbk.h"
#include "SchM_DoIP.h"
#include "Rte_DoIP.h"
#include "SoAd.h"
#include "Bsw_Common.h"
#include "Dcm.h"

#if (STD_ON == DOIP_DEV_ERROR_DETECT)
#include "Det.h"
#endif

/******************************************************************************
 * Version Check
 ******************************************************************************/
#if(STD_ON == DOIP_PRIVATE_VERSION_CHECK)
/* check Version with other import module */


/* check Version with cfg file */
#if ((DOIP_AR_RELEASE_MAJOR_VERSION != DOIP_AR_RELEASE_MAJOR_VERSION_CFG) || \
(DOIP_AR_RELEASE_MINOR_VERSION != DOIP_AR_RELEASE_MINOR_VERSION_CFG))
#error "AutoSar Version Numbers of DOIP and its cfg file are different"
#endif

#if ((DOIP_SW_MAJOR_VERSION != DOIP_SW_MAJOR_VERSION_CFG) || \
(DOIP_SW_MINOR_VERSION != DOIP_SW_MINOR_VERSION_CFG))
#error "SW Version Numbers of DOIP and its cfg file are different"
#endif


#endif/* #if(STD_ON == DOIP_PRIVATE_AR_VERSION_CHECK) */


/******************************************************************************
 * Macro
 ******************************************************************************/
#if(STD_ON == DOIP_DEV_ERROR_DETECT)

#define DOIP_DET_ERROR_DETECT(cond, ApiId, errcode) \
    DET_ERROR_DETECT((cond), DOIP_MODULE_ID, DOIP_INSTANCE_ID,(ApiId),(errcode))

#define DOIP_DET_ERROR_DETECT_RET(cond, ApiId, errcode, ret) \
    DET_ERROR_DETECT_RET((cond), DOIP_MODULE_ID,DOIP_INSTANCE_ID,(ApiId),(errcode), (ret))

#define DOIP_DET_REPORT_ERROR(ApiId, errcode) \
    DET_REPORT_ERROR(DOIP_MODULE_ID, DOIP_INSTANCE_ID, (ApiId), (errcode))

#else

#define DOIP_DET_ERROR_DETECT(cond, ApiId, errcode)
#define DOIP_DET_ERROR_DETECT_RET(cond, ApiId, errcode, ret)
#define DOIP_DET_REPORT_ERROR(ApiId, errcode)

#endif



/* Define the protocol version that is supportted by DoIP module */
#define DOIP_PROTOCOL_VERSION_SUPPORT ((uint8)0x02)
#define DOIP_PROTOCOL_VERSION_DEFAULT ((uint8)0xFF)

/* DoIP message payload type definition */
#define DOIP_PAYLOAD_TYPE_GEN_HDR_NACK                              ((uint16)0x0000)
#define DOIP_PAYLOAD_TYPE_VEHICLE_IDENTIFICATION_REQ                ((uint16)0x0001)
#define DOIP_PAYLOAD_TYPE_VEHICLE_IDENTIFICATION_EID_REQ            ((uint16)0x0002)
#define DOIP_PAYLOAD_TYPE_VEHICLE_IDENTIFICATION_VIN_REQ            ((uint16)0x0003)
#define DOIP_PAYLOAD_TYPE_VEHICLE_ANNOUCEMENT                       ((uint16)0x0004)
#define DOIP_PAYLOAD_TYPE_ROUTING_ACTIVATION_REQ                    ((uint16)0x0005)
#define DOIP_PAYLOAD_TYPE_ROUTING_ACTIVATION_RES                    ((uint16)0x0006)
#define DOIP_PAYLOAD_TYPE_ALIVE_CHECK_REQ                           ((uint16)0x0007)
#define DOIP_PAYLOAD_TYPE_ALIVE_CHECK_RES                           ((uint16)0x0008)
#define DOIP_PAYLOAD_TYPE_ENTITY_STATUS_REQ                         ((uint16)0x4001)
#define DOIP_PAYLOAD_TYPE_ENTITY_STATUS_RES                         ((uint16)0x4002)
#define DOIP_PAYLOAD_TYPE_DIAG_PWR_MODE_REQ                         ((uint16)0x4003)
#define DOIP_PAYLOAD_TYPE_DIAG_PWR_MODE_RES                         ((uint16)0x4004)
#define DOIP_PAYLOAD_TYPE_DIAG_MSG                                  ((uint16)0x8001)
#define DOIP_PAYLOAD_TYPE_DIAG_MSG_ACK                              ((uint16)0x8002)
#define DOIP_PAYLOAD_TYPE_DIAG_MSG_NACK                             ((uint16)0x8003)
#define DOIP_PAYLOAD_TYPE_AUTH_RES_WITH_SEED                        ((uint16)0xF100)
#define DOIP_PAYLOAD_TYPE_AUTH_RES_WITH_KEY                         ((uint16)0xF101)

/* Generic NACK code define */
#define DOIP_GEN_HDR_NACK_INCORRECT_PATTERN                         ((uint8)0x00)
#define DOIP_GEN_HDR_NACK_UNKNOWN_PAYLOAD_TYPE                      ((uint8)0x01)
#define DOIP_GEN_HDR_NACK_MSG_TOO_LARGE                             ((uint8)0x02)
#define DOIP_GEN_HDR_NACK_OUT_OF_MEMORY                             ((uint8)0x03)
#define DOIP_GEN_HDR_NACK_INVALID_LEN                               ((uint8)0x04)

/* Diagnostic message NACK code definition */
#define DOIP_DIAG_MSG_NACK_UNKONWN_SA                               ((uint8)0x02)
#define DOIP_DIAG_MSG_NACK_UNKONWN_TA                               ((uint8)0x03)
#define DOIP_DIAG_MSG_NACK_TOO_LARGE                                ((uint8)0x04)
#define DOIP_DIAG_MSG_NACK_OUT_OF_MEMORY                            ((uint8)0x05)
#define DOIP_DIAG_MSG_NACK_TA_INACTIVED                             ((uint8)0x06)
#define DOIP_DIAG_MSG_NACK_TP_ERROR                                 ((uint8)0x08)

/* Routing activiation response code definition */
#define DOIP_ROUTING_ACTIVATION_RES_CODE_UNKNOWN_SA                 ((uint8)0)
#define DOIP_ROUTING_ACTIVATION_RES_CODE_NO_SOCK                    ((uint8)1)
#define DOIP_ROUTING_ACTIVATION_RES_CODE_SA_DIFF                    ((uint8)2)
#define DOIP_ROUTING_ACTIVATION_RES_CODE_SA_ACTIVED_ON_OTHER_SOCK   ((uint8)3)
#define DOIP_ROUTING_ACTIVATION_RES_CODE_MISSING_AUTH               ((uint8)4)
#define DOIP_ROUTING_ACTIVATION_RES_CODE_CONFIRMATION_REJECTED      ((uint8)5)
#define DOIP_ROUTING_ACTIVATION_RES_CODE_ACTION_TYPE_UNSUPPORTTED   ((uint8)6)
#define DOIP_ROUTING_ACTIVATION_RES_CODE_SUCCESS                    ((uint8)0x10)
#define DOIP_ROUTING_ACTIVATION_RES_CODE_CONFIRMATION_REQUIRED      ((uint8)0x11)
#define DOIP_ROUTING_ACTIVATION_RES_CODE_INVALID_VALUE              ((uint8)0xff)
#define DOIP_ROUTING_ACTIVATION_RES_CODE_INVALID_KEY                ((uint8)0x55)
#if (DOIP_GREATWALL_PLATFORM == DOIP_OEM_PLATFORM)
#define DOIP_ROUTING_ACTIVATION_RES_OEM_RESERVED                    ((uint8)0xFF)
#else
#define DOIP_ROUTING_ACTIVATION_RES_OEM_RESERVED                    ((uint8)0x0)
#endif

/*Further Action Byte*/
#define DOIP_FURTHER_ACTION_NO_REQUIRED                             ((uint8)0x00)
#define DOIP_FURTHER_ACTION_CENTRAL_SECURITY                        ((uint8)0x10)

#define DOIP_VINGID_NOT_SYNCH                                       (uint8)0x10
#define DOIP_CENTRAL_SECURITY_ACTION_TYPE                           (uint8)0xE0
#define DOIP_ACTIONTYPE_INVALID                                     0xff
#define DOIP_DIAGPORT                                               (uint16)13400
#define DOIP_TCPIP_AF_INET                                          (TcpIp_DomainType)0x02
#define DOIP_TCPIP_BROADCAT                                         0xffffffff
#define DOIP_DHCPHOSTNAMES                                          "DOIP-"
/*magic number change*/

#define DOIP_PAYLOAD_TYPE_VEHICLE_IDENTIFICATION_REQ_LENGTH          0 /* 0x0001 */
/* SWS_DoIP_00063 */
#define DOIP_PAYLOAD_TYPE_VEHICLE_IDENTIFICATION_EID_REQ_LENGTH      6 /* 0x0002 */
/*SWS_DoIP_00068*/
#define DOIP_PAYLOAD_TYPE_VEHICLE_IDENTIFICATION_VIN_REQ_LENGTH      17 /* 0x0003 */
#define DOIP_PAYLOAD_TYPE_ENTITY_STATUS_REQ_LENGTH                   0 /* 0x4001 */
#define DOIP_PAYLOAD_TYPE_DIAG_PWR_MODE_REQ_LENGTH                   0 /* 0x4003 */
/* Tcp connection received */
#define DOIP_PAYLOAD_TYPE_ROUTING_ACTIVATION_REQ_LENGTH1             7 /* 0x0005 */
#define DOIP_PAYLOAD_TYPE_ROUTING_ACTIVATION_REQ_LENGTH2             11 /* 0x0005 */
#define DOIP_PAYLOAD_TYPE_ALIVE_CHECK_RES_LENGTH                     2 /* 0x0008 */
#define DOIP_PAYLOAD_TYPE_AUTH_RES_WITH_KEY_LENGTH                   20 /* 0xF101 */

/* Pre-defined key length */
#define DOIP_PAYLOAD_TYPE_AUTH_KEY_LENGTH                            16
#define DOIP_PAYLOAD_TYPE_AUTH_SEED_LENGTH                           16 

#define DOIP_VIN_LENGTH                                              17
#define DOIP_GID_LENGTH                                              6
#define DOIP_EID_LENGTH                                              6
#define DOIP_AUTH_COMFIRM_RES_LENGTH                                 (uint8)4
#define DOIP_REVE_LENGTH                                             (uint8)4
#define DOIP_DIAGDATA_LEAST_LENGTH                                   (PduLengthType)5/*SWS_DoIP_00122*/
/*response Pdu.SduLength*/
/*general*/
#define DoIP_NACK_RESPONSE_LENGTH                                   ((PduLengthType)0x01)
/*UDP SWS_DoIP_00086*/
#if (DOIP_USE_VEHICLE_IDENTIFICATION_SYNC_STATUS == STD_ON)
#define DOIP_VEHICLEANNOUCEMENT_RESPONSE_LENGTH                     ((PduLengthType)((PduLengthType)0x21 + DOIP_GEN_HDR_LEN))
#else
#define DOIP_VEHICLEANNOUCEMENT_RESPONSE_LENGTH                     ((PduLengthType)((PduLengthType)0x20 + DOIP_GEN_HDR_LEN))
#endif

#if (DOIP_ENTITY_STATUS_MAX_BYTE_FIELD_USE == STD_ON)
#define DOIP_ENTITYSTATUS_RESPONSE_LENGTH                           ((PduLengthType)((PduLengthType)0x07 + DOIP_GEN_HDR_LEN))
#else
#define DOIP_ENTITYSTATUS_RESPONSE_LENGTH                           ((PduLengthType)((PduLengthType)0x03 + DOIP_GEN_HDR_LEN))
#endif

#define DOIP_GENERICHEADERNACK_RESPONSE_LENGTH                      ((PduLengthType)((PduLengthType)0x01 + DOIP_GEN_HDR_LEN))
#define DOIP_DIAGPOWERINFO_RESPONSE_LENGTH                          ((PduLengthType)((PduLengthType)0x01 + DOIP_GEN_HDR_LEN))

#define DOIP_ROUTACTIVE_REQ_OEMRESV_LENGTH                          ((PduLengthType)0x0B)
#define DOIP_ROUTACTIVE_REQ_NOOEMRESV_LENGTH                        ((PduLengthType)0x07)
/*TCP*/
#define DOIP_ROUTACTIVE_RESPONSE_NOOEMRESV_LENGTH                   ((PduLengthType)0x09)
#define DOIP_ROUTACTIVE_RESPONSE_LENGTH                             ((PduLengthType)0x0D)
#define DOIP_ALIVECHECK_REQUEST_LENGTH                              ((PduLengthType)0X00)

#define DOIP_GEN_HDR_LEN                                            ((PduLengthType)8)
#define DOIP_DIAG_MSG_ADDR_INFO_LEN                                 ((PduLengthType)4)
#define DOIP_DIAG_MSG_HDR_LEN                                       (DOIP_GEN_HDR_LEN + DOIP_DIAG_MSG_ADDR_INFO_LEN)
#define DOIP_ACK_CODE_LEN                                           ((PduLengthType)1)

#define DOIP_INVALID_LOGIC_ADDR                                     ((DoIP_LogicAddrType)0x0000)
#define DOIP_INVALID_PDUID                                          COMSTACK_INVALID_PDUID
#define DOIP_INVALID_PAYLOAD_TYPE                                   ((uint16)0xffff)
#define DOIP_INVALID_TESTER_INDEX                                   ((uint8)0xff)
#define DOIP_INVALID_ID                                             ((uint8)0xff)

#define DOIP_ACTIVATION_LINE_SWITCH_NONE                            0
#define DOIP_ACTIVATION_LINE_SWITCH_INACTIVE2ACTIVE                 1
#define DOIP_ACTIVATION_LINE_SWITCH_ACTIVE2INACTIVE                 2

#define DOIP_PROTOCOL_UDP 0
#define DOIP_PROTOCOL_TCP 1

#define DOIP_TCP_CON_BUF_SIZE                                       (DOIP_GEN_HDR_LEN + DOIP_MAX_REQUEST_BYTES)

#define DOIP_TP_TX_LIST_SIZE                                        (DOIP_CHANNEL_NUM+(uint8)1)

#define DOIP_GID_SYNC_STATE_IDLE                                    (uint8)0
#define DOIP_GID_SYNC_STATE_PENDING                                 (uint8)1
#define DOIP_GID_SYNC_STATE_FINISH                                  (uint8)2

#define DOIP_UDP_REQ_MAX_PARAM_LEN                                  17/* Equal to VIN length ,Req max length is  17*/

#if(DOIP_HOZON_PLATFORM == DOIP_OEM_PLATFORM)
#define DOIP_SPECIFIC_PAYLOAD_LEN_INFO_NUM                          9 /*receive message type num*/
#else
#define DOIP_SPECIFIC_PAYLOAD_LEN_INFO_NUM                          8 /*receive message type num*/
#endif

#define DOIP_ENTER_CRITICAL_SECTION_SOCONSTATUS()                   SchM_Enter_DoIP_DOIP_EXCLUSIVE_AREA_0()
#define DOIP_LEAVE_CRITICAL_SECTION_SOCONSTATUS()                   SchM_Exit_DoIP_DOIP_EXCLUSIVE_AREA_0()
#define DOIP_ENTER_CRITICAL_SECTION_TXSESSION()                     SchM_Enter_DoIP_DOIP_EXCLUSIVE_AREA_1()
#define DOIP_LEAVE_CRITICAL_SECTION_TXSESSION()                     SchM_Exit_DoIP_DOIP_EXCLUSIVE_AREA_1()
#define DOIP_ENTER_CRITICAL_SECTION_ROUTINGACTIVATION()             SchM_Enter_DoIP_DOIP_EXCLUSIVE_AREA_2()
#define DOIP_LEAVE_CRITICAL_SECTION_ROUTINGACTIVATION()             SchM_Exit_DoIP_DOIP_EXCLUSIVE_AREA_2()
#define DOIP_ENTER_CRITICAL_SECTION_ALVECHECK()                     SchM_Enter_DoIP_DOIP_EXCLUSIVE_AREA_3()
#define DOIP_LEAVE_CRITICAL_SECTION_ALVECHECK()                     SchM_Exit_DoIP_DOIP_EXCLUSIVE_AREA_3()
#define DOIP_ENTER_CRITICAL_SECTION_UDPPROCESS()                    SchM_Enter_DoIP_DOIP_EXCLUSIVE_AREA_4()
#define DOIP_LEAVE_CRITICAL_SECTION_UDPPROCESS()                    SchM_Exit_DoIP_DOIP_EXCLUSIVE_AREA_4()
 
#if(DOIP_HOZON_PLATFORM == DOIP_OEM_PLATFORM)
#define DOIP_GET_SEED(s,l)                                        (void)DoIP_GenerateSeed(s,l)
#define DOIP_VALIDATE_KEY(k,l)                                    DoIP_ValidateKey(k,l)
#endif

/******************************************************************************
 * Function-like Macros
 *
 ******************************************************************************/
/*PRQA S 3435,3456 ++*/
/* Using a macro parameter more than once for judgment */

#define DOIP_UNUSED(x)                      (void)(x)
#if (DOIP_CPU_ENDIAN_TYPE == HIGH_BYTE_FIRST)

#define DOIP_U16(b)  ((uint16)(((uint32)((uint16)((b)[0]))) << (uint32)8) | (uint16)((b)[1]))

#define DOIP_U32(b)  (((uint32)(b)[0] << (uint32)24) |\
                      ((uint32)(b)[1] << (uint32)16) |\
                      ((uint32)(b)[2] << (uint32)8)  |\
                      (uint32)(b)[3])

/*PRQA S 3459 ++*/
/* Use do-while-zero construct */
#define DOIP_U16TOBUF(b,dw)  do{\
        (b)[0] = (uint8)((dw) >> (uint16)8);\
        (b)[1] = (uint8)((dw) >> (uint16)0);\
    } while (0)

#define DOIP_U32TOBUF(b,dw)  do{\
        (b)[0] = (uint8)((dw) >> (uint32)24);\
        (b)[1] = (uint8)((dw) >> (uint32)16);\
        (b)[2] = (uint8)((dw) >> (uint32)8);\
        (b)[3] = (uint8)((dw) >> (uint32)0);\
    } while (0)

#else/*(DOIP_CPU_ENDIAN_TYPE == LOW_BYTE_FIRST)*/

#define DOIP_U16(b)   ((uint16)((uint16)(b)[1] << (uint16)8)  |\
                       (uint16)((uint16)(b)[0]))

#define DOIP_U32(b)  (((uint32)((uint32)(b)[3]) << (uint32)24) |\
                      ((uint32)((uint32)(b)[2]) << (uint32)16) |\
                      ((uint32)((uint32)(b)[1]) << (uint32)8)  |\
                      (uint32)((uint32)(b)[0]))

#define DOIP_U16TOBUF(b,dw)  do{\
        (b)[1] = (uint8)((dw) >> (uint16)0);\
        (b)[0] = (uint8)((dw) >> (uint16)8);\
    } while (0)

#define DOIP_U32TOBUF(b,dw)  do{\
        (b)[3] = (uint8)((dw) >> (uint32)0);\
        (b)[2] = (uint8)((dw) >> (uint32)8);\
        (b)[1] = (uint8)((dw) >> (uint32)16);\
        (b)[0] = (uint8)((dw) >> (uint32)24);\
    } while (0)

#endif/* DOIP_CPU_ENDIAN_TYPE */

#define DOIP_IS_SOCON_MODE_VALID(m) (((m) == SOAD_SOCON_UNINIT) || \
                                     ((m) == SOAD_SOCON_ONLINE) || \
                                     ((m) == SOAD_SOCON_OFFLINE) || \
                                     ((m) == SOAD_SOCON_RECONN))

#define DOIP_IS_HDR_SYNC_PATTERN_VALID(h) ((uint8)((uint8)(h)[0]+ (uint8)(h)[1]) == (uint8)0xFF)
#define DOIP_IS_PROTO_VERSION_SUPPORT(v) ((v) == DOIP_PROTOCOL_VERSION_SUPPORT)

/* SWS_DoIP_00008, SWS_DoIP_00061,SWS_DoIP_00062,SWS_DoIP_00067, SWS_DoIP_00090,
   SWS_DoIP_00094
 * Following payload types were supportted for reception on udp connection
 */
#define DOIP_IS_UDP_RX_PAYLOAD_TYPE_SUPPORT(t)   (\
        (DOIP_PAYLOAD_TYPE_VEHICLE_IDENTIFICATION_REQ == (t))                ||\
        (DOIP_PAYLOAD_TYPE_VEHICLE_IDENTIFICATION_EID_REQ == (t))       ||\
        (DOIP_PAYLOAD_TYPE_VEHICLE_IDENTIFICATION_VIN_REQ  == (t))      ||\
        (DOIP_PAYLOAD_TYPE_ENTITY_STATUS_REQ== (t))       ||\
        (DOIP_PAYLOAD_TYPE_DIAG_PWR_MODE_REQ == (t))    ||\
        (DOIP_PAYLOAD_TYPE_VEHICLE_ANNOUCEMENT == (t)))

/* SWS_DoIP_00008, SWS_DoIP_00101, SWS_DoIP_00121
 * Following payload types were supportted for reception on tcp connection
 */
#define DOIP_IS_TCP_RX_PAYLOAD_TYPE_SUPPORT(t)   (\
        (DOIP_PAYLOAD_TYPE_ALIVE_CHECK_RES== (t))                ||\
        (DOIP_PAYLOAD_TYPE_DIAG_MSG== (t))       ||\
        (DOIP_PAYLOAD_TYPE_ROUTING_ACTIVATION_REQ== (t)) ||\
        (DOIP_PAYLOAD_TYPE_AUTH_RES_WITH_KEY== (t)))

#define DOIP_TCP_TX_JOB_CLR(j) do\
    {\
        (j)->PayloadType = DOIP_INVALID_PAYLOAD_TYPE;\
        (j)->ChannelId = DOIP_INVALID_PDUID;\
        (j)->TotalLen = (uint16)0;\
    }while(0)

#define DOIP_TCP_TX_JOB_SET(dest,src) do\
    {\
        (dest)->PayloadType = (src)->PayloadType;\
        (dest)->ChannelId = (src)->ChannelId;\
        (dest)->TotalLen = (src)->TotalLen;\
    } while (0)

#define DOIP_TP_SESSION_CLR(s) do\
    {\
        (s)->TotalLen = (uint16)0;\
        (s)->Offset = (uint16)0;\
        (s)->PayloadType = DOIP_INVALID_PAYLOAD_TYPE;\
        (s)->ChannelId = DOIP_INVALID_PDUID;\
        (s)->SkipMsg = FALSE;\
    }while(0)
/*PRQA S 3459,3435,3456 --*/

#if (DOIP_CONFIG_VARIANTS != STD_CONFIG_VARIANTS_PRECOMPILE)

#define DOIP_GET_LOCAL_ADDR()                        (DoIP_ConfigPtr->LA)
#define DOIP_GET_TARGET_ADDR(id)                     (DoIP_ConfigPtr->TargetAddrs[id])
#define DOIP_GET_NUM_TESTER()                        (DoIP_ConfigPtr->NumTester)
#define DOIP_GET_NUM_ROUT_ACTIV()                    (DoIP_ConfigPtr->NumRoutActiv)
#define DOIP_GET_EID()                               (&DoIP_ConfigPtr->Eid[0])

/* Get udp connection configuration */
#define DOIP_GET_UDPCON_SOAD_TX_PDUID(id)            (DoIP_ConfigPtr->UdpCons[id].SoAdTxPduId)
#define DOIP_GET_UDPCON_SOAD_RX_PDUID(id)            (DoIP_ConfigPtr->UdpCons[id].SoAdRxPduId)
#define DOIP_GET_UDPCON_SOAD_SOCONID(id)             (DoIP_ConfigPtr->UdpCons[id].SoConId)

/* Get tcp connection configuration */
#define DOIP_GET_TCPCON_SOAD_TX_PDUID(id)            (DoIP_ConfigPtr->TcpCons[id].SoAdTxPduId)
#define DOIP_GET_TCPCON_SOAD_RX_PDUID(id)            (DoIP_ConfigPtr->TcpCons[id].SoAdRxPduId)
#define DOIP_GET_TCPCON_SOAD_SOCONID(id)             (DoIP_ConfigPtr->TcpCons[id].SoConId)

/* Get channel configuration */
#define DOIP_GET_CHANNEL_SA(ch)                      (DoIP_ConfigPtr->Channels[ch].SA)
#define DOIP_GET_CHANNEL_TA(ch)                      (DoIP_ConfigPtr->Channels[ch].TA)
#define DOIP_GET_CHANNEL_PDUR_RX_PDUID(ch)           (DoIP_ConfigPtr->Channels[ch].PduRRxPduId)
#define DOIP_GET_CHANNEL_PDUR_TX_PDUID(ch)           (DoIP_ConfigPtr->Channels[ch].PduRTxPduId)
#define DOIP_GET_CHANNEL_PDU_TYPE(ch)                (DoIP_ConfigPtr->Channels[ch].PduType)
#define DOIP_GET_CHANNEL_IFPDU_BUFID(ch)             (DoIP_ConfigPtr->Channels[ch].IfPduBufId)

/* Get tester configuration */
#define DOIP_GET_TESTER_NUM_BYTE_DIAG_ACK_NACK(id)   (DoIP_ConfigPtr->Testers[id].NumByteDiagAckNack)
#define DOIP_GET_TESTER_NUM_ROUT_ACTIV(id)           (DoIP_ConfigPtr->Testers[id].NumRoutActiv)
#define DOIP_GET_TESTER_SA(id)                       (DoIP_ConfigPtr->Testers[id].SA)
#define DOIP_GET_TESTER_ROUT_ACTIV_ID(id,ra)         (DoIP_ConfigPtr->Testers[id].RoutActivIdList[ra])

/* Get routing activation configuration */
#define DOIP_GET_ROUT_ACTIV_ACTION_TYPE(i)           (DoIP_ConfigPtr->RoutActivs[i].ActionType)
#define DOIP_GET_ROUT_ACTIV_NUM_TARGET_ADDR(i)       (DoIP_ConfigPtr->RoutActivs[i].NumTargetAddr)
#define DOIP_GET_ROUT_ACTIV_TARGET_ADDR_ID(i,ta)     (DoIP_ConfigPtr->RoutActivs[i].TargetAddrIdList[ta])
#define DOIP_GET_ROUT_ACTIV_AUTH_REQ_LEN(i)          (DoIP_ConfigPtr->RoutActivs[i].AuthReqLen)
#define DOIP_GET_ROUT_ACTIV_AUTH_RES_LEN(i)          (DoIP_ConfigPtr->RoutActivs[i].AuthResLen)
#define DOIP_GET_ROUT_ACTIV_AUTH_CALLBACK(i)         (DoIP_ConfigPtr->RoutActivs[i].AuthCallback)
#define DOIP_GET_ROUT_ACTIV_CONFIRM_REQ_LEN(i)       (DoIP_ConfigPtr->RoutActivs[i].ConfirmReqLen)
#define DOIP_GET_ROUT_ACTIV_CONFIRM_RES_LEN(i)       (DoIP_ConfigPtr->RoutActivs[i].ConfirmResLen)
#define DOIP_GET_ROUT_ACTIV_CONFIRM_CALLBACK(i)      (DoIP_ConfigPtr->RoutActivs[i].ConfirmCallback)

#else
#define DOIP_GET_LOCAL_ADDR()                        (DoIP_Config.LA)
#define DOIP_GET_TARGET_ADDR(id)                     (DoIP_Config.TargetAddrs[id])
#define DOIP_GET_NUM_TESTER()                        (DoIP_Config.NumTester)
#define DOIP_GET_NUM_ROUT_ACTIV()                    (DoIP_Config.NumRoutActiv)
#define DOIP_GET_EID()                               (&DoIP_Config.Eid[0])

/* Get udp connection configuration */
#define DOIP_GET_UDPCON_SOAD_TX_PDUID(id)            (DoIP_Config.UdpCons[id].SoAdTxPduId)
#define DOIP_GET_UDPCON_SOAD_RX_PDUID(id)            (DoIP_Config.UdpCons[id].SoAdRxPduId)
#define DOIP_GET_UDPCON_SOAD_SOCONID(id)             (DoIP_Config.UdpCons[id].SoConId)

/* Get tcp connection configuration */
#define DOIP_GET_TCPCON_SOAD_TX_PDUID(id)            (DoIP_Config.TcpCons[id].SoAdTxPduId)
#define DOIP_GET_TCPCON_SOAD_RX_PDUID(id)            (DoIP_Config.TcpCons[id].SoAdRxPduId)
#define DOIP_GET_TCPCON_SOAD_SOCONID(id)             (DoIP_Config.TcpCons[id].SoConId)

/* Get channel configuration */
#define DOIP_GET_CHANNEL_SA(ch)                      (DoIP_Config.Channels[ch].SA)
#define DOIP_GET_CHANNEL_TA(ch)                      (DoIP_Config.Channels[ch].TA)
#define DOIP_GET_CHANNEL_PDUR_RX_PDUID(ch)           (DoIP_Config.Channels[ch].PduRRxPduId)
#define DOIP_GET_CHANNEL_PDUR_TX_PDUID(ch)           (DoIP_Config.Channels[ch].PduRTxPduId)
#define DOIP_GET_CHANNEL_PDU_TYPE(ch)                (DoIP_Config.Channels[ch].PduType)
#define DOIP_GET_CHANNEL_IFPDU_BUFID(ch)             (DoIP_Config.Channels[ch].IfPduBufId)

/* Get tester configuration */
#define DOIP_GET_TESTER_NUM_BYTE_DIAG_ACK_NACK(id)   (DoIP_Config.Testers[id].NumByteDiagAckNack)
#define DOIP_GET_TESTER_NUM_ROUT_ACTIV(id)           (DoIP_Config.Testers[id].NumRoutActiv)
#define DOIP_GET_TESTER_SA(id)                       (DoIP_Config.Testers[id].SA)
#define DOIP_GET_TESTER_ROUT_ACTIV_ID(id,ra)         (DoIP_Config.Testers[id].RoutActivIdList[ra])

/* Get routing activation configuration */
#define DOIP_GET_ROUT_ACTIV_ACTION_TYPE(i)           (DoIP_Config.RoutActivs[i].ActionType)
#define DOIP_GET_ROUT_ACTIV_NUM_TARGET_ADDR(i)       (DoIP_Config.RoutActivs[i].NumTargetAddr)
#define DOIP_GET_ROUT_ACTIV_TARGET_ADDR_ID(i,ta)     (DoIP_Config.RoutActivs[i].TargetAddrIdList[ta])
#define DOIP_GET_ROUT_ACTIV_AUTH_REQ_LEN(i)          (DoIP_Config.RoutActivs[i].AuthReqLen)
#define DOIP_GET_ROUT_ACTIV_AUTH_RES_LEN(i)          (DoIP_Config.RoutActivs[i].AuthResLen)
#define DOIP_GET_ROUT_ACTIV_AUTH_CALLBACK(i)         (DoIP_Config.RoutActivs[i].AuthCallback)
#define DOIP_GET_ROUT_ACTIV_CONFIRM_REQ_LEN(i)       (DoIP_Config.RoutActivs[i].ConfirmReqLen)
#define DOIP_GET_ROUT_ACTIV_CONFIRM_RES_LEN(i)       (DoIP_Config.RoutActivs[i].ConfirmResLen)
#define DOIP_GET_ROUT_ACTIV_CONFIRM_CALLBACK(i)      (DoIP_Config.RoutActivs[i].ConfirmCallback)

#endif

#define DOIP_TCP_CON_MGMT_PTR(id)                    (&DoIP_TcpConMgmt[id])
#define DOIP_TCP_CON_MGMT_TX_SESSION_PTR(id)         (&DoIP_TcpConMgmt[id].TxSes)
#define DOIP_TCP_CON_MGMT_RX_SESSION_PTR(id)         (&DoIP_TcpConMgmt[id].RxSes)
#define DOIP_TCP_CON_MGMT_SEND_BUF_PTR(id)           (DoIP_TcpConMgmt[id].SendBuf)
#define DOIP_TCP_CON_MGMT_SEND_BUF_OFFSET(id)        (DoIP_TcpConMgmt[id].SendBufOffset)
#define DOIP_TCP_CON_MGMT_RECV_BUF_PTR(id)           (DoIP_TcpConMgmt[id].RecvBuf)

#define DOIP_ROUT_ACTIV_MGMT_PTR(id)                 (&DoIP_RoutActivMgmt[id])
#define DOIP_ROUT_ACTIV_MGMT_REQ_PARAM_PTR(id)       (&DoIP_RoutActivMgmt[id].ReqParam)

#define DOIP_UDP_CON_MGMT_PTR(id)                    (&DoIP_UdpConMgmt[id])

#define DOIP_CHANNEL_CTRL_PTR(ch)                    (&DoIP_ChannelCtrl[ch])

#if(DOIP_TCP_TX_IF_PDU_BUF_NUM > 0)
#define DOIP_TCP_TX_IFPDU_BUF_PTR(id)                (DoIP_TcpTxIfPduBuf[id])
#else
#define DOIP_TCP_TX_IFPDU_BUF_PTR(id)                (NULL_PTR)
#endif

#define DOIP_TP_TX_LIST_PTR(id)                      (&DoIP_TpTxList[id])
#define DOIP_TP_TX_LIST_IS_EMPTY(id)                 (DoIP_TpTxList[id].Head == NULL_PTR)

/*******************************************************************************
 * DoIP message structure defined here as below:
 ******************************************************************************/
typedef struct
{
    uint8 Ver;/* SWS_DoIP_00005 */
    uint8 VerInv;/* SWS_DoIP_00006 */
    uint8 PayloadType[DOIP_TWO];/* SWS_DoIP_00007 */
    uint8 Length[DOIP_FOUR];/* SWS_DoIP_00010 */
} DoIP_GenHdrType;/* SWS_DoIP_00004 */

typedef struct
{
    DoIP_GenHdrType Hdr;
    uint8 SA[DOIP_TWO];
    uint8 TA[DOIP_TWO];
} DoIP_DiagMsgHdrType;

typedef struct
{
    DoIP_GenHdrType Hdr;
    uint8 Vin[DOIP_SEVENTEEN];
    uint8 LogicAddr[DOIP_TWO];
    uint8 Eid[DOIP_EID_LENGTH];
    uint8 Gid[DOIP_GID_LENGTH];
    uint8 FutherAction;
#if (DOIP_USE_VEHICLE_IDENTIFICATION_SYNC_STATUS == STD_ON)/*SWS_DoIP_00086*/
    uint8 Status;
#endif
} DoIP_VehicleAnnouncementType;

typedef struct
{
    DoIP_GenHdrType Hdr;
    uint8 NackCode;
} DoIP_GenericHeaderNackType;

typedef struct
{
    DoIP_GenHdrType Hdr;
    DoIP_PowerStateType PowerMode;
} DoIP_DiagPowerInfoType;

typedef struct
{
    DoIP_GenHdrType Hdr;
    uint8 NodeType;
    uint8 MaxOpenSocket;
    uint8 CurrentOpenSocket;
#if (DOIP_ENTITY_STATUS_MAX_BYTE_FIELD_USE == STD_ON)
    uint8 MaxDataSize[DOIP_FOUR];
#endif
} DoIP_EntityStatusResType;

typedef struct
{
    uint8 SA[DOIP_TWO];
    uint8 TA[DOIP_TWO];
    uint8 ResCode;
    uint8 Resv[DOIP_REVE_LENGTH];
    uint8 OemResv[DOIP_REVE_LENGTH];
} DoIP_RoutActivResType;

typedef struct             
{
    uint8 SA[DOIP_TWO];
    uint8 TA[DOIP_TWO];
    uint8 seed[DOIP_PAYLOAD_TYPE_AUTH_SEED_LENGTH];
} DoIP_RoutActivAUTHResType;

typedef struct
{
    DoIP_GenHdrType Hdr;
    uint8 SA[DOIP_TWO];
    uint8 ActionType;
    uint8 Resv[DOIP_REVE_LENGTH];
    uint8 OemResv[DOIP_REVE_LENGTH];
} DoIP_RoutActivReqMsgType;

typedef struct
{
    DoIP_GenHdrType Hdr;
    uint8 Payload[DOIP_MAX_REQUEST_BYTES];
} DoIP_GenMsgType;

typedef struct
{
    DoIP_GenHdrType Hdr;
    uint8 SA[DOIP_TWO];
    uint8 TA[DOIP_TWO];
    uint8 UserData[ ( DOIP_MAX_REQUEST_BYTES - DOIP_DIAG_MSG_ADDR_INFO_LEN)];
} DoIP_DiagMsgType;

typedef struct
{
    uint8 SA[DOIP_TWO];
    uint8 TA[DOIP_TWO];
    uint8 AckCode;
    uint8 DiagMsg[DOIP_MAX_BYTES_DIAG_ACK_NACK];
} DoIP_DiagMsgAckType;

typedef struct
{
    uint16 PayloadType;
    uint32 Length;
} DoIP_SpecPayloadLenInfoType;

typedef struct
{
    uint16 PayloadType;
    PduLengthType TotalLen;
    PduIdType ChannelId;/* Diagnostic message must refrence to a channel */
} DoIP_TpTxJobType;

typedef struct tag_DoIPTpTxElementType
{
    DoIP_TpTxJobType Job;
    struct tag_DoIPTpTxElementType *Next;
} DoIP_TpTxElementType;

typedef struct
{
    DoIP_TpTxElementType *Head;
    DoIP_TpTxElementType EleArray[DOIP_TP_TX_LIST_SIZE];
} DoIP_TpTxListType;

typedef struct
{
    uint16 PayloadType;
    PduLengthType TotalLen;
    PduIdType ChannelId;/* Diagnostic message must refrence to a channel */
    boolean SkipMsg;
    PduLengthType Offset;
} DoIP_TpSessionType;

typedef struct
{
    uint16 PayloadType;
    uint8 Param[DOIP_UDP_REQ_MAX_PARAM_LEN];
    DoIP_SoConCloseStateType SoConCloseStatus;
} DoIP_UdpReqType;

typedef struct
{
    DoIP_LogicAddrType SA;/* Tester SA parameter */
    uint8 ActionType;/* Which type of security action is needed */
    uint8 OemResv[DOIP_REVE_LENGTH];/* OEM specific information */
    uint8 TesterId;/* Which tester is request routing activation */
    uint8 RoutActivId;/* Routing activation index in tester configuration, Reference to Routing activation configuration */
} DoIP_RoutActivReqParamType;

typedef struct
{
    DoIP_RoutActivStatusType Status;
    DoIP_RoutActivReqParamType ReqParam;
    uint8 AliveCheckCount;
    boolean AliveCheckOnlyOne;
} DoIP_RoutActivMgmtType;

typedef struct
{
    SoAd_SoConModeType SoConMode;/* SWS_DoIP_00001 */
    DoIP_SoConCloseStateType SoConCloseStatus;

    TcpIp_SockAddrRealType RemoteAddr;

    /* Request Queue for each udp connection */
    uint8 ReqCount;
    uint8 QIn;
    uint8 QOut;
    DoIP_UdpReqType ReqQ[DOIP_MAX_UDP_REQ_PER_MESSAGE + (uint8) 1];
    /**/
    uint8 VehicleIdentificationRequest_0001_flag;
    uint8 ReqCount_OutOfMemory_flag;
    /* Vehicle announcement message control */
    uint32 AnnounceTimer;
    uint8 VehicleAnnouncementCount;
} DoIP_UdpConMgmtType;

/* SWS_DoIP_00002  */
typedef struct
{
    /*
     * Socket connection state management
     */
    SoAd_SoConModeType SoConMode;
    DoIP_SoConCloseStateType SoConCloseStatus;

    /* Tester connection active status monitor */
    uint32 InactiveTimer;/* SWS_DoIP_00142 */

    uint8 TesterId;/* Refrence to registed tester */

    /* Alive check status */
    boolean AliveCheckPerformed;
    uint8 OwnerId;/* Alive check is triggered by which tcp connection */
    uint32 AliveCheckTimer;/* Timer is start when alive check performed */

    /*
     * Receive session control
     */
    DoIP_TpSessionType RxSes;

    /*
     * Transmission session control
     */
    DoIP_TpSessionType TxSes;

    /* Receive buffer for this connection */
    uint8 RecvBuf[DOIP_TCP_CON_BUF_SIZE];
    /* Transmit buffer for this connection, only used by non-diagnostic message */
    uint8 SendBuf[DOIP_TCP_CON_BUF_SIZE];
    uint16 SendBufOffset;
} DoIP_TcpConMgmtType;

typedef struct
{
    PduIdType TcpConId;/* Means Which TCP connection channel is binded to */
    boolean RoutingActived;/* Whether this channel is active or not */
} DoIP_ChannelCtrlType;


/******************************************************************************
 * Local Functions Declaration
 *
 *
 *
 ******************************************************************************/
#define DOIP_START_SEC_CODE
#include "MemMap.h"

STATIC FUNC (Std_ReturnType, DOIP_CODE) DoIP_TcpSendDiagnosticMessageAck
(
    PduIdType ConId,
    DoIP_LogicAddrType TesterSA,
    uint8 AckCode,
    PduInfoType DiagMsg
);
STATIC FUNC (Std_ReturnType, DOIP_CODE) DoIP_TcpSendDiagnosticMessageNack
(
    PduIdType ConId,
    DoIP_LogicAddrType TesterSA,
    uint8 AckCode,
    PduInfoType DiagMsg
);
STATIC FUNC (void, DOIP_CODE) DoIP_TcpTxReqHandler
(
    uint8 TcpConId
);
STATIC FUNC (Std_ReturnType, DOIP_CODE) DoIP_GenericHeaderCheckSyncPattern
(
    const uint8 *BufPtr,
    uint8 Proto
);
STATIC FUNC (Std_ReturnType, DOIP_CODE) DoIP_AliveCheckResTimeOutIndication
(
    uint8 OwnerId
);
STATIC FUNC (void, DOIP_CODE) DoIP_AliveCheckResReceived
(
    PduIdType id,
    const uint8 *MsgBufPtr
);
STATIC FUNC (Std_ReturnType, DOIP_CODE) DoIP_AliveCheckResIndication
(
    uint8 OwnerId
);
STATIC FUNC (Std_ReturnType, DOIP_CODE) DoIP_TcpWaitForData
(
    PduIdType id,
    PduInfoType *PduInfoPtr,
    PduLengthType WaitLen
);
STATIC FUNC (BufReq_ReturnType, DOIP_CODE) DoIP_DiagnosticMessageReceive
(
    PduIdType id,
    PduInfoType *info,
    PduLengthType *bufferSizePtr
);
STATIC FUNC (BufReq_ReturnType, DOIP_CODE) DoIP_QueryTxAvailableDataLen
(
    PduIdType id,
    const PduInfoType *info,
    RetryInfoType *retry,
    PduLengthType *AvailableDataPtr
);
STATIC FUNC (Std_ReturnType, DOIP_CODE) DoIP_MemCompare
(
    const uint8 *DataPtr1,
    const uint8 *DataPtr2,
    uint8 LenByte
);
STATIC FUNC (void, DOIP_CODE) DoIP_GenericHeaderConstruct
(
    uint8 *BufPtr,
    uint16 PayloadType,
    uint32 LenByte
);
STATIC FUNC (Std_ReturnType, DOIP_CODE) DoIP_GenericHeaderCheck
(
    const uint8 *BufPtr,
    uint8 Proto,
    uint8 *Nack,
    boolean *SoConClose,
    boolean *IsVehicleAnnounce
);
STATIC FUNC (Std_ReturnType, DOIP_CODE) DoIP_GetChannelId
(
    DoIP_LogicAddrType TesterSA,
    DoIP_LogicAddrType TA,
    PduIdType *ChannelIdPtr
);
STATIC FUNC (Std_ReturnType, DOIP_CODE) DoIP_CheckPayloadLength
(
    uint16 PayloadType,
    uint32 LenByte
);
STATIC FUNC (Std_ReturnType, DOIP_CODE) DoIP_GetTesterId
(
    DoIP_LogicAddrType TesterSA,
    uint8 *TesterIdPtr
);
STATIC FUNC (Std_ReturnType, DOIP_CODE) DoIP_GetTesterRoutActivId
(
    uint8 TesterId,
    uint8 ActionType,
    uint8 *RoutActivIdPtr
);
STATIC FUNC (Std_ReturnType, DOIP_CODE) DoIP_GetUdpConIdBySoConId
(
    SoAd_SoConIdType SoConId,
    uint8 *ConIdPtr
);
#if(DOIP_NODE_TYPE == DOIP_GATEWAY)
STATIC FUNC (boolean, DOIP_CODE) DoIP_UdpIsAllConClose
(
    void
);
#endif
STATIC FUNC (Std_ReturnType, DOIP_CODE) DoIP_UdpTransmit
(
    PduIdType UdpConId,
    PduInfoType *PduInfoPtr,
    uint16 PayloadType
);
STATIC FUNC (Std_ReturnType, DOIP_CODE) DoIP_UdpSendGenericHeaderNack
(
    PduIdType UdpConId,
    SduDataPtrType GenericHeaderNack
);
STATIC FUNC (Std_ReturnType, DOIP_CODE) DoIP_VehicleAnnouncement
(
    PduIdType ConId
);
STATIC FUNC (Std_ReturnType, DOIP_CODE) DoIP_VehicleIdentificationEidReqHandler
(
    PduIdType ConId,
    const DoIP_UdpReqType *ReqPtr
);
STATIC FUNC (Std_ReturnType, DOIP_CODE) DoIP_VehicleIdentificationVinReqHandler
(
    PduIdType ConId,
    const DoIP_UdpReqType *ReqPtr
);
STATIC FUNC (Std_ReturnType, DOIP_CODE) DoIP_EntityStatusReqHandler
(
    PduIdType ConId
);
STATIC FUNC (Std_ReturnType, DOIP_CODE) DoIP_DiagPowerInfoReqHandler
(
    PduIdType ConId
);
STATIC FUNC (void, DOIP_CODE) DoIP_UdpRequestDispatch
(
    PduIdType ConId,
    const DoIP_UdpReqType *ReqPtr
);
STATIC FUNC (void, DOIP_CODE) DoIP_MainFunctionUdp
(
    void
);
STATIC void DoIP_TpTxListInit
(
    DoIP_TpTxListType *TxListPtr
);
STATIC FUNC (Std_ReturnType, DOIP_CODE) DoIP_TpTxListGetOldestJob
(
    DoIP_TpTxListType *TxListPtr,
    DoIP_TpTxJobType *OldestJobPtr
);
STATIC FUNC (Std_ReturnType, DOIP_CODE) DoIP_TpTxListAppend
(
    DoIP_TpTxListType *TxListPtr,
    const DoIP_TpTxJobType *NewJobPtr
);
STATIC FUNC (boolean, DOIP_CODE) DoIP_TpTxListFindPduId
(
    DoIP_TpTxListType *TxListPtr,
    PduIdType DoIPPduRTxId
);
STATIC FUNC (boolean, DOIP_CODE) DoIP_TpTxListFindPayloadType
(
    DoIP_TpTxListType *TxListPtr,
    uint16 PayloadType
);
STATIC FUNC (Std_ReturnType, DOIP_CODE) DoIP_TpTxListRemovePduId
(
    DoIP_TpTxListType *TxListPtr,
    PduIdType DoIPPduRTxId
);
STATIC FUNC (void, DOIP_CODE) DoIP_TpTxListRemoveAll
(
    DoIP_TpTxListType *TxListPtr
);
STATIC FUNC (Std_ReturnType, DOIP_CODE) DoIP_TcpRequestTransmit
(
    PduIdType ConId,
    PduIdType ChannelId,
    const PduInfoType *PduInfoPtr,
    uint16 PayloadType
);
STATIC FUNC (Std_ReturnType, DOIP_CODE) DoIP_TcpGetConIdBySoConId
(
    SoAd_SoConIdType SoConId,
    uint8 *ConIdPtr
);
STATIC FUNC (Std_ReturnType, DOIP_CODE) DoIP_TcpSendGenericHeaderNack
(
    PduIdType ConId,
    uint8 Nack
);
STATIC FUNC (Std_ReturnType, DOIP_CODE) DoIP_TcpGetConIdByTesterSA
(
    DoIP_LogicAddrType SA,
    uint8 *ConIdPtr
);
STATIC FUNC (uint8, DOIP_CODE) DoIP_TcpGetCurrentTesterConNum
(
    void
);
STATIC FUNC (BufReq_ReturnType, DOIP_CODE) DoIP_DiagnosticMessageRoute
(
    PduIdType id,
    PduInfoType *info,
    PduLengthType *bufferSizePtr
);
STATIC FUNC (Std_ReturnType, DOIP_CODE) DoIP_TryAuthentication
(
    PduIdType ConId,
    uint8 *ResDataPtr
);
STATIC FUNC (Std_ReturnType, DOIP_CODE) DoIP_TryConfirmation
(
    PduIdType ConId,
    uint8 *ResDataPtr
);
STATIC FUNC (Std_ReturnType, DOIP_CODE) DoIP_TryRoutingActivation
(
    PduIdType ConId
);
STATIC FUNC (BufReq_ReturnType, DOIP_CODE) DoIP_TcpReceive
(
    PduIdType id,
    const PduInfoType *info,
    PduLengthType *bufferSizePtr
);
STATIC FUNC (Std_ReturnType, DOIP_CODE) DoIP_AliveCheckAllActivedTcpCon
(
    uint8 OwnerId
);
STATIC FUNC (Std_ReturnType, DOIP_CODE) DoIP_AliveCheck
(
    PduIdType ConId
);
STATIC FUNC (void, DOIP_CODE) DoIP_RoutingActivationReqHandler
(
    uint8 ConId,
    const uint8 *MsgBufPtr
);
STATIC FUNC (void, DOIP_CODE) DoIP_MainFunctionTcp
(
    void
);
STATIC FUNC (void, DOIP_CODE) DoIP_ActivationLineStatusHandler
(
    void
);
STATIC FUNC (uint8, DOIP_CODE) DoIP_GetCurrentTcpConOnlineNum
(
    void
);
STATIC FUNC (BufReq_ReturnType, DOIP_CODE) DoIP_CopyTpTxData
(
    PduIdType id,
    const PduInfoType *info,
    RetryInfoType *retry,
    PduLengthType *AvailableDataPtr
);
STATIC FUNC (BufReq_ReturnType, DOIP_CODE) DoIP_CopyNonTpTxData
(
    PduIdType id,
    const PduInfoType *info,
    PduLengthType *AvailableDataPtr
);
STATIC FUNC (uint16, DOIP_CODE) DoIP_GetMinValue (uint16 a, uint16 b);
STATIC FUNC (uint16, DOIP_CODE) DoIP_GetAnnounceIntialTimer
(
    void
);
/*tbd*/
STATIC FUNC (void, DOIP_CODE) DoIP_IncreaseRandomNum
(
    void
);
#if(DOIP_HOZON_PLATFORM == DOIP_OEM_PLATFORM)
STATIC FUNC (Std_ReturnType, DOIP_CODE) DoIP_SendAuthRespWithSeed
(
    PduIdType ConId,
    uint8* SA,
    uint8* TA
);
STATIC FUNC (void, DOIP_CODE) DoIP_KeyReceived
(
    PduIdType ConId,
    uint8 *RxBuffer
);
#endif
#define DOIP_STOP_SEC_CODE
#include "MemMap.h"
/*tbd*/
#define DOIP_INCREASERANDOMMAXNUM                  ((uint16)450)

/******************************************************************************
 * Local Data Deifine
 *
 ******************************************************************************/
/*
 * Activation line status management
 */
#define DOIP_START_SEC_VAR_INIT_8
#include "MemMap.h"
STATIC Std_InitStateType DoIP_InitState = STD_UNINITIALIZED;
/* SWS_DoIP_00201 */
STATIC DoIP_ActivationLineStatusType DoIP_ActivationLineStatus = DOIP_ACTIVATION_LINE_INACTIVE;
STATIC uint8 DoIP_ActivationLineSwitchAction = (uint8) DOIP_ACTIVATION_LINE_SWITCH_NONE;
STATIC uint8 DoIP_GidSyncStatus = DOIP_GID_SYNC_STATE_IDLE;
#define DOIP_STOP_SEC_VAR_INIT_8
#include "MemMap.h"

#define DOIP_START_SEC_VAR_NOINIT_16
#include "MemMap.h"
STATIC uint16 DoIP_AnnounceIntialTimer[DOIP_UDP_CON_NUM];
/*tbd*/
STATIC uint16 DoIP_RandomNum = DOIP_INITIAL_VEHICLE_ANNOUNCEMENT_TIME;
#define DOIP_STOP_SEC_VAR_NOINIT_16
#include "MemMap.h"

#define DOIP_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"
STATIC P2CONST (DoIP_ConfigType, DOIP_VAR, DOIP_CONST) DoIP_ConfigPtr = NULL_PTR;
STATIC DoIP_UdpConMgmtType DoIP_UdpConMgmt[DOIP_UDP_CON_NUM];
STATIC DoIP_TcpConMgmtType DoIP_TcpConMgmt[DOIP_TCP_CON_NUM];
STATIC DoIP_RoutActivMgmtType DoIP_RoutActivMgmt[DOIP_TCP_CON_NUM];
STATIC DoIP_TpTxListType DoIP_TpTxList[DOIP_TCP_CON_NUM];
STATIC DoIP_ChannelCtrlType DoIP_ChannelCtrl[DOIP_CHANNEL_NUM];
#define DOIP_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"

#if(DOIP_TCP_TX_IF_PDU_BUF_NUM > 0)
#define DOIP_START_SEC_VAR_NOINIT_8
#include "MemMap.h"
STATIC uint8 DoIP_TcpTxIfPduBuf[DOIP_TCP_TX_IF_PDU_BUF_NUM][DOIP_TCP_CON_BUF_SIZE];
#define DOIP_STOP_SEC_VAR_NOINIT_8
#include "MemMap.h"
#endif

#define DOIP_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
STATIC CONST (DoIP_SpecPayloadLenInfoType, DOIP_PRIVATE_DATA) DoIP_SpecPayloadLenInfo[DOIP_SPECIFIC_PAYLOAD_LEN_INFO_NUM] =
{
    /* Udp connection received */
    /* SWS_DoIP_00059 */
    {
        DOIP_PAYLOAD_TYPE_VEHICLE_IDENTIFICATION_REQ,
        (uint32) DOIP_PAYLOAD_TYPE_VEHICLE_IDENTIFICATION_REQ_LENGTH
    },/* 0x0001 */
    /* SWS_DoIP_00063 */
    {
        DOIP_PAYLOAD_TYPE_VEHICLE_IDENTIFICATION_EID_REQ,
        (uint32) DOIP_PAYLOAD_TYPE_VEHICLE_IDENTIFICATION_EID_REQ_LENGTH
    },/* 0x0002 */
    /*SWS_DoIP_00068*/
    {
        DOIP_PAYLOAD_TYPE_VEHICLE_IDENTIFICATION_VIN_REQ,
        (uint32) DOIP_PAYLOAD_TYPE_VEHICLE_IDENTIFICATION_VIN_REQ_LENGTH
    },/* 0x0003 */
    {
        DOIP_PAYLOAD_TYPE_ENTITY_STATUS_REQ,
        (uint32) DOIP_PAYLOAD_TYPE_ENTITY_STATUS_REQ_LENGTH
    },/* 0x4001 SWS_DoIP_00095*/
    {
        DOIP_PAYLOAD_TYPE_DIAG_PWR_MODE_REQ,
        (uint32) DOIP_PAYLOAD_TYPE_DIAG_PWR_MODE_REQ_LENGTH
    },/* 0x4003, SWS_DoIP_00091*/
    /* Tcp connection received */
    {
        DOIP_PAYLOAD_TYPE_ROUTING_ACTIVATION_REQ,
        (uint32) DOIP_PAYLOAD_TYPE_ROUTING_ACTIVATION_REQ_LENGTH1
    },/* 0x0005 SWS_DoIP_00117*/
    {
        DOIP_PAYLOAD_TYPE_ROUTING_ACTIVATION_REQ,
        (uint32) DOIP_PAYLOAD_TYPE_ROUTING_ACTIVATION_REQ_LENGTH2
    },/* 0x0005 SWS_DoIP_00117*/
    {
        DOIP_PAYLOAD_TYPE_ALIVE_CHECK_RES,
        (uint32) DOIP_PAYLOAD_TYPE_ALIVE_CHECK_RES_LENGTH
    },/* 0x0008 */
#if(DOIP_HOZON_PLATFORM == DOIP_OEM_PLATFORM)
    {
        DOIP_PAYLOAD_TYPE_AUTH_RES_WITH_KEY,
        (uint32) DOIP_PAYLOAD_TYPE_AUTH_RES_WITH_KEY_LENGTH
    }/* 0x0008 */
#endif
};
#define DOIP_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"


#define DOIP_START_SEC_CODE
#include "MemMap.h"
/******************************************************************************
 * Private Functions
 ******************************************************************************/
STATIC FUNC (Std_ReturnType, DOIP_CODE) DoIP_MemCompare
(
    const uint8 *DataPtr1,
    const uint8 *DataPtr2,
    uint8 LenByte
)
{
    Std_ReturnType retVal = E_OK;
    uint8 count = (uint8) 0;

    while (count < LenByte)
    {
        if (DataPtr1[count] != DataPtr2[count])
        {
            retVal = E_NOT_OK;
            break;
        }

        count++;
    }

    return retVal;
}

STATIC FUNC (void, DOIP_CODE) DoIP_GenericHeaderConstruct
(
    uint8 *BufPtr,
    uint16 PayloadType,
    uint32 LenByte
)
{
    ( (DoIP_GenHdrType *) BufPtr)->Ver = DOIP_PROTOCOL_VERSION_SUPPORT;
    ( (DoIP_GenHdrType *) BufPtr)->VerInv = (uint8)(~(uint32)DOIP_PROTOCOL_VERSION_SUPPORT);
    DOIP_U16TOBUF ( ( (DoIP_GenHdrType *) BufPtr)->PayloadType, PayloadType);
    DOIP_U32TOBUF ( ( (DoIP_GenHdrType *) BufPtr)->Length, LenByte);
}

STATIC FUNC (Std_ReturnType, DOIP_CODE) DoIP_GenericHeaderCheckSyncPattern
(
    const uint8 *BufPtr,
    uint8 Proto
)
{
    Std_ReturnType retVal;
    const DoIP_GenHdrType *hdr = NULL_PTR;
    uint16 PayLoadType;
    retVal = E_OK;

    /* Check protocol pattern and version */
    if (! (DOIP_IS_HDR_SYNC_PATTERN_VALID (BufPtr) ) )
    {
        retVal = E_NOT_OK;
    }
    else
    {
        hdr = (const DoIP_GenHdrType *) BufPtr;
        PayLoadType = DOIP_U16 (hdr->PayloadType);

        if (!DOIP_IS_PROTO_VERSION_SUPPORT (hdr->Ver) )
        {
            if (Proto == (uint8) DOIP_PROTOCOL_UDP)
            {
                /* SWS_DoIP_00015
                 * Protocol version can be  DOIP_PROTOCOL_VERSION_DEFAULT when udp communication and
                 * vehicle identification request
                 */
                if ( ( (hdr->Ver != DOIP_PROTOCOL_VERSION_DEFAULT)
                        || (! ( (PayLoadType == DOIP_PAYLOAD_TYPE_VEHICLE_IDENTIFICATION_REQ)
                                || (PayLoadType == DOIP_PAYLOAD_TYPE_VEHICLE_IDENTIFICATION_EID_REQ)
                                || (PayLoadType == DOIP_PAYLOAD_TYPE_VEHICLE_IDENTIFICATION_VIN_REQ) ) ) ) )
                {
                    retVal = E_NOT_OK;
                }
            }
            else
            {
                retVal = E_NOT_OK;
            }
        }
    }

    return retVal;
}

STATIC FUNC (Std_ReturnType, DOIP_CODE) DoIP_GenericHeaderCheck
(
    const uint8 *BufPtr,
    uint8 Proto,
    uint8 *Nack,
    boolean *SoConClose,
    boolean *IsVehicleAnnounce
)
{
    Std_ReturnType retVal;
    uint16 type;
    uint32 len;

    retVal = E_OK;
    *IsVehicleAnnounce = FALSE;

    /* Step1: Check protocol pattern and version */
    retVal = DoIP_GenericHeaderCheckSyncPattern (BufPtr, Proto);

    if (E_OK != retVal)
    {
        *Nack = DOIP_GEN_HDR_NACK_INCORRECT_PATTERN;/* SWS_DoIP_00014 */
        *SoConClose = TRUE;
    }
    else /* Step 2 : Check payload type */
    {
        /*u8 2 u16*/
        type = DOIP_U16 ( ( (const DoIP_GenHdrType *) BufPtr)->PayloadType);

        if ( (Proto == (uint8) DOIP_PROTOCOL_TCP)
                && (!DOIP_IS_TCP_RX_PAYLOAD_TYPE_SUPPORT (type) ) )
        {
            *Nack = DOIP_GEN_HDR_NACK_UNKNOWN_PAYLOAD_TYPE;/* SWS_DoIP_00016 */
            *SoConClose = FALSE;
            retVal = E_NOT_OK;
        }
        else if ( (Proto == (uint8) DOIP_PROTOCOL_UDP)
                  && (!DOIP_IS_UDP_RX_PAYLOAD_TYPE_SUPPORT (type) ) )
        {
            *Nack = DOIP_GEN_HDR_NACK_UNKNOWN_PAYLOAD_TYPE;/* SWS_DoIP_00016 */
            *SoConClose = FALSE;
            retVal = E_NOT_OK;
        }
        
        else if ( (Proto != (uint8) DOIP_PROTOCOL_UDP) && (Proto != (uint8) DOIP_PROTOCOL_TCP) )
        {
            DOIP_DET_REPORT_ERROR (DOIP_API_ID_IF_RX_INDICATION, DOIP_E_INVALID_PARAMETER);
            retVal = E_NOT_OK;
        }
        else if ( (Proto == (uint8) DOIP_PROTOCOL_UDP)
                  && (type == DOIP_PAYLOAD_TYPE_VEHICLE_ANNOUCEMENT) )
        {
            *IsVehicleAnnounce = TRUE;
            *SoConClose = FALSE;
        }        
        else
        {
            /* do nothing */
        }

    }

    if(*IsVehicleAnnounce == TRUE)
    {
        retVal = E_OK;
    }
    else
    {
        /* Step3 : Check payload length */
        if (retVal == E_OK)
        {
            len = DOIP_U32 ( ( ( const DoIP_GenHdrType *) BufPtr)->Length);

            if (len > (uint32) DOIP_MAX_REQUEST_BYTES)
            {
                *Nack = DOIP_GEN_HDR_NACK_MSG_TOO_LARGE;/* SWS_DoIP_00017 */
                *SoConClose = FALSE;
                retVal = E_NOT_OK;
            }
        }

        /* Step4 : Check specific payload length for message type */
        if (retVal == E_OK)
        {
            retVal = DoIP_CheckPayloadLength (type, len);

            if (E_OK != retVal)
            {
                *Nack = DOIP_GEN_HDR_NACK_INVALID_LEN;/* SWS_DoIP_00019 */
                *SoConClose = TRUE;
            }
        }
    }

    return retVal;
}

STATIC FUNC (Std_ReturnType, DOIP_CODE) DoIP_GetChannelId
(
    DoIP_LogicAddrType TesterSA,
    DoIP_LogicAddrType TA,
    PduIdType *ChannelIdPtr
)
{
    Std_ReturnType retVal;
    PduIdType i;

    retVal = E_NOT_OK;

    for (i = (PduIdType) 0; i < DOIP_CHANNEL_NUM; i++)
    {
        if ( (TesterSA == DOIP_GET_CHANNEL_SA (i) )
                && (TA == DOIP_GET_CHANNEL_TA (i) ) )
        {
            *ChannelIdPtr = i;
            retVal = E_OK;
            break;
        }
    }

    return retVal;
}

STATIC FUNC (Std_ReturnType, DOIP_CODE) DoIP_CheckPayloadLength
(
    uint16 PayloadType,
    uint32 LenByte
)
{
    uint8 i;
    Std_ReturnType retVal = E_NOT_OK;

    for (i = (uint8) 0; i < (uint8) DOIP_SPECIFIC_PAYLOAD_LEN_INFO_NUM; i++)
    {
        if ( (DoIP_SpecPayloadLenInfo[i].PayloadType == PayloadType)
                && (DoIP_SpecPayloadLenInfo[i].Length == LenByte) )
        {
            retVal = E_OK;
            break;
        }
    }

    return retVal;
}

STATIC FUNC (Std_ReturnType, DOIP_CODE) DoIP_GetTesterId
(
    DoIP_LogicAddrType TesterSA,
    uint8 *TesterIdPtr
)
{
    Std_ReturnType retVal;
    uint8 i;

    retVal = E_NOT_OK;

    for (i = (uint8) 0; i < DOIP_GET_NUM_TESTER(); i++)
    {
        if (DOIP_GET_TESTER_SA (i) == TesterSA)
        {
            *TesterIdPtr = i;
            retVal = E_OK;
            break;
        }
    }

    return retVal;
}

STATIC FUNC (Std_ReturnType, DOIP_CODE) DoIP_GetTesterRoutActivId
(
    uint8 TesterId,
    uint8 ActionType,
    uint8 *RoutActivIdPtr
)
{
    Std_ReturnType retVal;
    uint8 i, id;

    retVal = E_NOT_OK;

    for (i = (uint8) 0; i < DOIP_GET_TESTER_NUM_ROUT_ACTIV (TesterId); i++)
    {
        id = DOIP_GET_TESTER_ROUT_ACTIV_ID (TesterId, i);

        if (DOIP_GET_ROUT_ACTIV_ACTION_TYPE (id) == ActionType)
        {
            *RoutActivIdPtr = id;
            retVal = E_OK;
            break;
        }
    }

    return retVal;
}

STATIC FUNC (Std_ReturnType, DOIP_CODE) DoIP_GetUdpConIdBySoConId
(
    SoAd_SoConIdType SoConId,
    uint8 *ConIdPtr
)
{
    uint8 conId;
    Std_ReturnType retVal;

    retVal = E_NOT_OK;

    for (conId = (uint8) 0; conId < (uint8) DOIP_UDP_CON_NUM; conId++)
    {
        if (DOIP_GET_UDPCON_SOAD_SOCONID (conId) == SoConId)
        {
            *ConIdPtr = conId;
            retVal = E_OK;
            break;
        }
    }

    return retVal;
}

#if(DOIP_NODE_TYPE == DOIP_GATEWAY)
STATIC FUNC (boolean, DOIP_CODE) DoIP_UdpIsAllConClose (void)
{
    boolean allClose;
    uint8 conId;

    allClose = FALSE;

    for (conId = (uint8) 0; conId < (uint8) DOIP_UDP_CON_NUM; conId++)
    {
        if (DoIP_UdpConMgmt[conId].SoConMode == SOAD_SOCON_ONLINE)
        {
            break;
        }

        if (conId == ( (uint8) DOIP_UDP_CON_NUM - (uint8) 1) )
        {
            allClose = TRUE;
        }
    }

    return allClose;
}
#endif

STATIC FUNC (Std_ReturnType, DOIP_CODE) DoIP_UdpTransmit
(
    PduIdType UdpConId,
    PduInfoType *PduInfoPtr,
    uint16 PayloadType
)
{
    Std_ReturnType retVal;
    PduIdType soadTxPduId;

    DoIP_GenericHeaderConstruct (PduInfoPtr->SduDataPtr, PayloadType, ( (uint32) PduInfoPtr->SduLength - (uint32) DOIP_GEN_HDR_LEN) );
    soadTxPduId = DOIP_GET_UDPCON_SOAD_TX_PDUID (UdpConId);
    /* SWS_DoIP_00198 */
    retVal = SoAd_IfTransmit (soadTxPduId, PduInfoPtr);

    return retVal;
}

/*SWS_DoIP_00009, SWS_DoIP_00012*/
STATIC FUNC (Std_ReturnType, DOIP_CODE) DoIP_UdpSendGenericHeaderNack
(
    PduIdType UdpConId,
    SduDataPtrType GenericHeaderNack
)
{
    PduInfoType txPdu;
    Std_ReturnType retVal;

    txPdu.SduDataPtr =  GenericHeaderNack;
    txPdu.SduLength = DOIP_GENERICHEADERNACK_RESPONSE_LENGTH;
    retVal = DoIP_UdpTransmit (UdpConId, &txPdu, DOIP_PAYLOAD_TYPE_GEN_HDR_NACK);

    return retVal;
}

STATIC FUNC (Std_ReturnType, DOIP_CODE) DoIP_VehicleAnnouncement
(
    PduIdType ConId
)
{
    DoIP_VehicleAnnouncementType vehicleAnnoucement;
    PduInfoType pdu;
    SoAd_SoConIdType soconId;
    Std_ReturnType retVal;
    uint8 i, j;

    /* SWS_DoIP_00072 */
    retVal = DOIP_CALL_GET_VIN_FUNC (vehicleAnnoucement.Vin);

    if (E_OK !=  retVal)
    {
        Bsw_MemSet (&vehicleAnnoucement.Vin[0], (uint8) DOIP_VIN_INVALIDATIY_PATTERN, (uint32) DOIP_VIN_LENGTH);

#if (DOIP_USE_VEHICLE_IDENTIFICATION_SYNC_STATUS == STD_ON)
#if (DOIP_VIN_GID_MASTER == STD_ON)

        if (DoIP_GidSyncStatus == DOIP_GID_SYNC_STATE_FINISH)
        {
            /* SWS_DoIP_00089 */
            vehicleAnnoucement.Status = (uint8) 0x0;
        }
        else
#endif
        {
            /* SWS_DoIP_00088 */
            vehicleAnnoucement.Status = DOIP_VINGID_NOT_SYNCH;
        }

#endif

    }

#if (DOIP_USE_VEHICLE_IDENTIFICATION_SYNC_STATUS == STD_ON)
    else
    {
        /* SWS_DoIP_00087 */
        vehicleAnnoucement.Status = (uint8) 0x0;
    }

#endif

    /* SWS_DoIP_00073 */
    DOIP_U16TOBUF (vehicleAnnoucement.LogicAddr, DOIP_GET_LOCAL_ADDR() );

#if (DOIP_USE_MAC_FOR_IDENTIFICATION == STD_ON)
    /* SWS_DoIP_00074 */
    soconId = DOIP_GET_UDPCON_SOAD_SOCONID (ConId);
    (void) SoAd_GetPhysAddr (soconId, &vehicleAnnoucement.Eid[0]);
#else
    /* SWS_DoIP_00075 */
    Bsw_MemCpy (&vehicleAnnoucement.Eid[0], &DoIP_EID[0], DOIP_EID_LENGTH);
#endif

#if (DOIP_USE_EID_AS_GID == STD_ON)
    /* SWS_DoIP_00077 */
    Bsw_MemCpy (vehicleAnnoucement.Gid, vehicleAnnoucement.Eid, (uint32) DOIP_EID_LENGTH);
    /*PRQA S 3608 ++*/ 
    /* Use elif */
#elif (DOIP_GID_CONFIGURED == STD_ON)
    /* SWS_DoIP_00078, SWS_DoIP_00080
     * No matter DOIP_VIN_GID_MASTER is TRUE or FALSE, use DoIP_GID
     */
    Bsw_MemCpy (vehicleAnnoucement.Gid, DoIP_GID, DOIP_GID_LENGTH);
#else/*(DOIP_GID_CONFIGURED == STD_OFF)*/
    /* SWS_DoIP_00079, SWS_DoIP_00081
     * No matter DOIP_VIN_GID_MASTER is TRUE or FALSE, call GetGidCallback
     */
    /*SWS_DoIP_00051*/
    if((DoIP_GetGidCallbackType)NULL_PTR != DoIP_ConfigPtr->GetGidCallback)
    {
        retVal = DoIP_ConfigPtr->GetGidCallback(vehicleAnnoucement.Gid);
    }
    else if(((DoIP_GetGidCallbackType)NULL_PTR == DoIP_ConfigPtr->GetGidCallback) || (E_NOT_OK == retVal))
    {
    	Bsw_MemSet (&vehicleAnnoucement.Gid[0], DOIP_GID_INVALIDATIY_PATTERN, DOIP_GID_LENGTH);
    }
#endif

    /*PRQA S 3608 --*/ 
    /*SWS_DoIP_00083*//*SWS_DoIP_00084*/
    /*Further Byte Process:*/
    /* Configed 0xE0 ? ------->(N) Fur = 0x00
     *                 ------->(Y) Routing Actived? ------->(Y) Fur = 0x00
     *                                              ------->(N) Fur = 0x10
     */
    vehicleAnnoucement.FutherAction = DOIP_FURTHER_ACTION_NO_REQUIRED;

    for (i = (uint8)0; i < DOIP_GET_NUM_ROUT_ACTIV(); i++)
    {
        if (DOIP_GET_ROUT_ACTIV_ACTION_TYPE (i) == DOIP_CENTRAL_SECURITY_ACTION_TYPE)
        {
            if ( (DoIP_RoutActivMgmt[i].ReqParam.ActionType == DOIP_CENTRAL_SECURITY_ACTION_TYPE)
                    && (DoIP_RoutActivMgmt[i].Status == DOIP_ROUTING_ACTIVATION_ACTIVED) )
            {
                /* SWS_DoIP_00082 */
                vehicleAnnoucement.FutherAction = DOIP_FURTHER_ACTION_NO_REQUIRED;
                break;
            }
            else
            {
                vehicleAnnoucement.FutherAction = DOIP_FURTHER_ACTION_CENTRAL_SECURITY;
            }
        }
    }

    pdu.SduLength = DOIP_VEHICLEANNOUCEMENT_RESPONSE_LENGTH;
    pdu.SduDataPtr = (SduDataPtrType)(&vehicleAnnoucement);

    retVal = SoAd_SetRemoteAddr (DOIP_GET_UDPCON_SOAD_SOCONID (ConId), (const TcpIp_SockAddrType *) &DoIP_UdpConMgmt[ConId].RemoteAddr );

    if (E_OK == retVal)
    {
        /*SWS_DoIP_00009*/
        retVal = DoIP_UdpTransmit (ConId, &pdu, DOIP_PAYLOAD_TYPE_VEHICLE_ANNOUCEMENT);
    }

    return retVal;
}

STATIC FUNC (Std_ReturnType, DOIP_CODE) DoIP_VehicleIdentificationEidReqHandler
(
    PduIdType ConId,
    const DoIP_UdpReqType *ReqPtr
)
{
    SoAd_SoConIdType soconId;
    uint8 physAddr[DOIP_SIX];
    Std_ReturnType retVal;

    /* SWS_DoIP_00065 */
#if (DOIP_USE_MAC_FOR_IDENTIFICATION == STD_ON)
    soconId = DOIP_GET_UDPCON_SOAD_SOCONID (ConId);
    (void) SoAd_GetPhysAddr (soconId, physAddr);
#else
    /*SWS_DoIP_00066*/
    Bsw_MemCpy (&physAddr[0], DOIP_GET_EID(), (uint8) DOIP_EID_LENGTH);
#endif

    retVal = DoIP_MemCompare (&physAddr[0], & (ReqPtr->Param[0]), (uint8) DOIP_EID_LENGTH);

    if (E_OK == retVal)
    {
        retVal = DoIP_VehicleAnnouncement (ConId);
    }

    return retVal;
}

STATIC FUNC (Std_ReturnType, DOIP_CODE) DoIP_VehicleIdentificationVinReqHandler
(
    PduIdType ConId,
    const DoIP_UdpReqType *ReqPtr
)
{
    uint8 localVin[DOIP_VIN_LENGTH];
    Std_ReturnType retVal;

    /*SWS_DoIP_00070*/
    retVal = DOIP_CALL_GET_VIN_FUNC (&localVin[0]);

    if (E_OK !=  retVal)
    {
        Bsw_MemSet (&localVin[0], (uint8) DOIP_VIN_INVALIDATIY_PATTERN, (uint32) DOIP_VIN_LENGTH);
    }

    retVal = DoIP_MemCompare (&localVin[0], & (ReqPtr->Param[0]), (uint8) DOIP_VIN_LENGTH);

    if (E_OK == retVal)
    {
        retVal = DoIP_VehicleAnnouncement (ConId);
    }

    return retVal;
}

STATIC FUNC (uint8, DOIP_CODE) DoIP_GetCurrentTcpConOnlineNum
(
    void
)
{
    uint8 OnlineConNum = (uint8) 0;
    uint8 i;

    for (i = (uint8) 0; i < (uint8) DOIP_TCP_CON_NUM; i++)
    {
        if (DoIP_TcpConMgmt[i].SoConMode == SOAD_SOCON_ONLINE)
        {
            OnlineConNum++;
        }
    }

    return OnlineConNum;
}

STATIC FUNC (Std_ReturnType, DOIP_CODE) DoIP_EntityStatusReqHandler
(
    PduIdType ConId
)
{

    DoIP_EntityStatusResType entityStatusResData;
    PduInfoType pdu;
    Std_ReturnType retVal;

    /*SWS_DoIP_00097*/
    entityStatusResData.NodeType = (uint8) DOIP_NODE_TYPE;
    /*SWS_DoIP_00098*/
    entityStatusResData.MaxOpenSocket = DOIP_MAX_TESTER_CONNECTION_NUM;
    /*SWS_DoIP_00099*/
    entityStatusResData.CurrentOpenSocket = DoIP_GetCurrentTcpConOnlineNum();

    /*SWS_DoIP_00100*/
#if (DOIP_ENTITY_STATUS_MAX_BYTE_FIELD_USE == STD_ON)
    DOIP_U32TOBUF (entityStatusResData.MaxDataSize, (uint32) DOIP_MAX_REQUEST_BYTES);
#endif

    pdu.SduLength = DOIP_ENTITYSTATUS_RESPONSE_LENGTH;
    pdu.SduDataPtr = (SduDataPtrType) &entityStatusResData;

    retVal = SoAd_SetRemoteAddr (DOIP_GET_UDPCON_SOAD_SOCONID (ConId), (const TcpIp_SockAddrType *) & (DoIP_UdpConMgmt[ConId].RemoteAddr) );

    if (E_OK == retVal)
    {
        /*SWS_DoIP_00009, SWS_DoIP_00096*/
        retVal = DoIP_UdpTransmit (ConId, &pdu, DOIP_PAYLOAD_TYPE_ENTITY_STATUS_RES);
    }

    return retVal;
}

STATIC FUNC (Std_ReturnType, DOIP_CODE) DoIP_DiagPowerInfoReqHandler
(
    PduIdType ConId
)
{
    DoIP_DiagPowerInfoType DiagPowerInfo;
    Std_ReturnType retVal;
    DoIP_PowerModeCallbackType callback;
    PduInfoType pdu;

    /*SWS_DoIP_00047*/
    callback = DoIP_ConfigPtr->PowerModeCallback;

    if (callback == NULL_PTR)
    {
        DiagPowerInfo.PowerMode = DOIP_POWER_STATE_NOT_SUPPORT;
    }
    else
    {
        /*SWS_DoIP_00093*/
        retVal = callback(&DiagPowerInfo.PowerMode);

        if (E_OK != retVal)
        {
            DiagPowerInfo.PowerMode = DOIP_POWER_STATE_NOT_READY;
        }
        else
        {
            //DiagPowerInfo.PowerMode = DOIP_POWER_STATE_READY; //modified by Yibo 
        }
    }

    pdu.SduDataPtr = (SduDataPtrType)&DiagPowerInfo;
    pdu.SduLength = DOIP_DIAGPOWERINFO_RESPONSE_LENGTH;

    retVal = SoAd_SetRemoteAddr (DOIP_GET_UDPCON_SOAD_SOCONID (ConId), (const TcpIp_SockAddrType *) & (DoIP_UdpConMgmt[ConId].RemoteAddr) );

    if (E_OK == retVal)
    {
        /*SWS_DoIP_00009, SWS_DoIP_00092*/
        retVal = DoIP_UdpTransmit (ConId, &pdu, DOIP_PAYLOAD_TYPE_DIAG_PWR_MODE_RES);
    }

    return retVal;
}

STATIC FUNC (void, DOIP_CODE) DoIP_UdpRequestDispatch
(
    PduIdType ConId,
    const DoIP_UdpReqType *ReqPtr
)
{
    DoIP_GenericHeaderNackType GenericHeaderNack;

    switch (ReqPtr->PayloadType)
    {
    case DOIP_PAYLOAD_TYPE_GEN_HDR_NACK:
        GenericHeaderNack.NackCode = ReqPtr->Param[0];
        /*SWS_DoIP_00013*/
        (void) DoIP_UdpSendGenericHeaderNack (ConId, (uint8 *) &GenericHeaderNack);
        break;

    /* SWS_DoIP_00061 */
    case DOIP_PAYLOAD_TYPE_VEHICLE_IDENTIFICATION_REQ:
        DoIP_UdpConMgmt[ConId].VehicleAnnouncementCount++ ;
        DoIP_UdpConMgmt[ConId].AnnounceTimer = (uint32) 0;
        DoIP_UdpConMgmt[ConId].VehicleIdentificationRequest_0001_flag = (uint8) 1;
        DoIP_AnnounceIntialTimer[ConId] = DoIP_GetAnnounceIntialTimer();
        break;

    /* SWS_DoIP_00064 */
    case DOIP_PAYLOAD_TYPE_VEHICLE_IDENTIFICATION_EID_REQ:
        (void) DoIP_VehicleIdentificationEidReqHandler (ConId, ReqPtr);
        break;

    /*SWS_DoIP_00069*/
    case DOIP_PAYLOAD_TYPE_VEHICLE_IDENTIFICATION_VIN_REQ:
        (void) DoIP_VehicleIdentificationVinReqHandler (ConId, ReqPtr);
        break;

    case DOIP_PAYLOAD_TYPE_ENTITY_STATUS_REQ:
        (void) DoIP_EntityStatusReqHandler (ConId);
        break;

    case DOIP_PAYLOAD_TYPE_DIAG_PWR_MODE_REQ:
        (void) DoIP_DiagPowerInfoReqHandler (ConId);
        break;

    default:/* do nothing */
        break;
    }
}

STATIC FUNC (void, DOIP_CODE) DoIP_MainFunctionUdp (void)
{
    uint8 udpConId, out;

    for (udpConId = (uint8) 0; udpConId < (uint8) DOIP_UDP_CON_NUM; udpConId++)
    {
        /* Repeat vehicle announcement message after ip address assignment is finish */
        /*when change to Udp connection open is finish*/
        if (DoIP_UdpConMgmt[udpConId].SoConMode == SOAD_SOCON_ONLINE)
        {
            if (DoIP_UdpConMgmt[udpConId].VehicleAnnouncementCount > (uint8) 0)
            {
                DoIP_UdpConMgmt[udpConId].AnnounceTimer += (uint32)DOIP_MAINFUNCTION_PERIOD;/*SWS_DoIP_00043*/

                /*SWS_DoIP_00071*/
                if ( (DoIP_UdpConMgmt[udpConId].VehicleAnnouncementCount == DOIP_VEHICLE_ANNOUNCEMENT_REPETITION)
                        || ( (DoIP_UdpConMgmt[udpConId].VehicleIdentificationRequest_0001_flag == (uint8) 1)
                             && ( (uint8) 1 == DoIP_UdpConMgmt[udpConId].VehicleAnnouncementCount) ) )
                {
                    /* SWS_DoIP_00060
                       First message or Vihecle Identification requet with 00 01
                       must wait DOIP_INITIAL_VEHICLE_ANNOUNCEMENT_TIME ms */
                    if (DoIP_UdpConMgmt[udpConId].AnnounceTimer >= (uint32)DoIP_AnnounceIntialTimer[udpConId])
                    {
                        DoIP_UdpConMgmt[udpConId].VehicleAnnouncementCount--;

                        if ( (uint8) 0 == DoIP_UdpConMgmt[udpConId].VehicleAnnouncementCount)
                        {
                            DoIP_UdpConMgmt[udpConId].VehicleIdentificationRequest_0001_flag = (uint8) 0;
                        }

                        DoIP_UdpConMgmt[udpConId].AnnounceTimer = (uint32) 0;
                        (void) DoIP_VehicleAnnouncement (udpConId);
                    }
                }
                else
                {
                    /*SWS_DoIP_00071*/
                    if (DoIP_UdpConMgmt[udpConId].AnnounceTimer >= (uint32)DOIP_VEHICLE_ANNOUNCEMENT_INTERVAL)
                    {
                        DoIP_UdpConMgmt[udpConId].VehicleAnnouncementCount--;
                        DoIP_UdpConMgmt[udpConId].AnnounceTimer = (uint32) 0;
                        (void) DoIP_VehicleAnnouncement (udpConId);
                    }
                }

            }
        }

        DOIP_ENTER_CRITICAL_SECTION_UDPPROCESS();

        while ( (DoIP_UdpConMgmt[udpConId].ReqCount > (uint8) 0 )
                && (DoIP_UdpConMgmt[udpConId].VehicleIdentificationRequest_0001_flag == (uint8) 0) )
        {
            out = DoIP_UdpConMgmt[udpConId].QOut;
            DoIP_UdpRequestDispatch (udpConId, &DoIP_UdpConMgmt[udpConId].ReqQ[out]);

            if (DoIP_UdpConMgmt[udpConId].ReqQ[out].SoConCloseStatus == DOIP_SOCON_CLOSE_REQ_PENDING)
            {
                DoIP_UdpConMgmt[udpConId].SoConCloseStatus = DOIP_SOCON_CLOSE_REQ_PENDING;
            }

            DoIP_UdpConMgmt[udpConId].QOut++;
            DoIP_UdpConMgmt[udpConId].ReqCount--;

            if (DoIP_UdpConMgmt[udpConId].ReqCount_OutOfMemory_flag == (uint8) 1)
            {
                if (DoIP_UdpConMgmt[udpConId].QOut >= DOIP_MAX_UDP_REQ_PER_MESSAGE)
                {
                    /*when nack code is  DOIP_GEN_HDR_NACK_OUT_OF_MEMORY is sent,must clear flag*/
                    DoIP_UdpConMgmt[udpConId].ReqCount_OutOfMemory_flag = (uint8) 0;
                    DoIP_UdpConMgmt[udpConId].QOut = DOIP_MAX_UDP_REQ_PER_MESSAGE;
                }
            }
            else
            {
                if (DoIP_UdpConMgmt[udpConId].QOut >= DOIP_MAX_UDP_REQ_PER_MESSAGE)
                {
                    DoIP_UdpConMgmt[udpConId].QOut = (uint8) 0x0; /* roll back */
                }
            }

            if (DoIP_UdpConMgmt[udpConId].VehicleIdentificationRequest_0001_flag == (uint8) 1)
            {
                break;
            }
        }

        DOIP_LEAVE_CRITICAL_SECTION_UDPPROCESS();
    }
}

STATIC FUNC (void, DOIP_CODE) DoIP_TpTxListInit
(
    DoIP_TpTxListType *TxListPtr
)
{
    DoIP_TpTxElementType *elePtr;
    uint8 i;

    /* Clear job array */
    for (i = (uint8) 0; i < DOIP_TP_TX_LIST_SIZE; i++)
    {
        elePtr = &TxListPtr->EleArray[i];
        DOIP_TCP_TX_JOB_CLR (&elePtr->Job);
        elePtr->Next = NULL_PTR;
    }

    /* Clear list pointer */
    TxListPtr->Head = NULL_PTR;
}

STATIC FUNC (Std_ReturnType, DOIP_CODE) DoIP_TpTxListGetOldestJob
(
    DoIP_TpTxListType *TxListPtr,
    DoIP_TpTxJobType *OldestJobPtr
)
{
    Std_ReturnType retVal = E_NOT_OK;
    DoIP_TpTxElementType *TempTxHeadPtr;

    if ( (TxListPtr != NULL_PTR) && (OldestJobPtr != NULL_PTR) )
    {
        if (TxListPtr->Head != NULL_PTR)
        {
            DOIP_TCP_TX_JOB_SET (OldestJobPtr, & (TxListPtr->Head->Job) ); /* Fetch the job information */
            DOIP_TCP_TX_JOB_CLR (& (TxListPtr->Head->Job) ); /* Clear the element */
            TempTxHeadPtr = (DoIP_TpTxElementType *)TxListPtr->Head;
            TxListPtr->Head = (DoIP_TpTxElementType *)TxListPtr->Head->Next;/* Move list header to next element */
            TempTxHeadPtr->Next = NULL_PTR; /*Clear the element */

            retVal = E_OK;
        }
    }

    return retVal;
}

STATIC FUNC (Std_ReturnType, DOIP_CODE) DoIP_TpTxListAppend
(
    DoIP_TpTxListType *TxListPtr,
    const DoIP_TpTxJobType *NewJobPtr
)
{
    Std_ReturnType retVal;
    DoIP_TpTxElementType *elePtr;
    DoIP_TpTxElementType *tailPtr;
    uint8 idx;

    elePtr = NULL_PTR;
    retVal = E_NOT_OK;

    idx = (uint8) 0;

    do
    {
        if (TxListPtr->EleArray[idx].Job.PayloadType == DOIP_INVALID_PAYLOAD_TYPE)
        {
            elePtr = & (TxListPtr->EleArray[idx]);
            retVal = E_OK;
            break;
        }

        idx++;
    }
    while (idx < (uint8) DOIP_TP_TX_LIST_SIZE);

    if (elePtr != NULL_PTR)
    {
        DOIP_TCP_TX_JOB_SET (& (elePtr->Job), NewJobPtr);

        if (NULL_PTR == TxListPtr->Head)
        {
            TxListPtr->Head = elePtr;
            TxListPtr->Head->Next = NULL_PTR;
        }
        else
        {
            idx = (uint8) 0;
            tailPtr = TxListPtr->Head;
            retVal = E_NOT_OK;

            do
            {
                if (tailPtr->Next == NULL_PTR)
                {
                    tailPtr->Next = elePtr;
                    tailPtr->Next->Next = NULL_PTR;
                    retVal = E_OK;
                    break;
                }

                tailPtr = tailPtr->Next;

                idx++;
            }
            while (idx < (uint8) DOIP_TP_TX_LIST_SIZE);
        }
    }

    return retVal;
}

STATIC FUNC (boolean, DOIP_CODE) DoIP_TpTxListFindPduId
(
    DoIP_TpTxListType *TxListPtr,
    PduIdType DoIPPduRTxId
)
{
    boolean exist;
    DoIP_TpTxElementType *elePtr;

    elePtr = TxListPtr->Head;
    exist = FALSE;

    while (elePtr != NULL_PTR)
    {
        if (elePtr->Job.ChannelId == DoIPPduRTxId)
        {
            exist = TRUE;
            break;
        }

        elePtr = elePtr->Next;
    }

    return exist;
}

STATIC FUNC (boolean, DOIP_CODE) DoIP_TpTxListFindPayloadType
(
    DoIP_TpTxListType *TxListPtr,
    uint16 PayloadType
)
{
    boolean exist;
    DoIP_TpTxElementType *elePtr;

    elePtr = TxListPtr->Head;
    exist = FALSE;

    while (elePtr != NULL_PTR)
    {
        if (elePtr->Job.PayloadType == PayloadType)
        {
            exist = TRUE;
            break;
        }

        elePtr = elePtr->Next;
    }

    return exist;
}

STATIC FUNC (Std_ReturnType, DOIP_CODE) DoIP_TpTxListRemovePduId
(
    DoIP_TpTxListType *TxListPtr,
    PduIdType DoIPPduRTxId
)
{
    Std_ReturnType retVal = E_NOT_OK;
    DoIP_TpTxElementType *elePtr = TxListPtr->Head;
    DoIP_TpTxElementType *prev = NULL_PTR;
    DoIP_TpTxElementType *temp = NULL_PTR;

    while (elePtr != NULL_PTR)
    {
        if (elePtr->Job.ChannelId == DoIPPduRTxId)
        {
            DOIP_TCP_TX_JOB_CLR (& (elePtr->Job) );

            if (prev == NULL_PTR) /* current elePtr is head */
            {
                if (TxListPtr->Head->Next == NULL_PTR) /* Only one element in list, empty the list */
                {
                    TxListPtr->Head = NULL_PTR;
                }
                else
                {
                    temp = TxListPtr->Head;
                    TxListPtr->Head = TxListPtr->Head->Next;/* Move the head to next */
                    temp->Next = NULL_PTR;
                }

            }
            else/* In the middle of the list */
            {
                prev->Next = elePtr->Next;
                elePtr->Next = NULL_PTR;
            }

            retVal = E_OK;
            break;
        }

        prev = elePtr;
        elePtr = elePtr->Next;
    }


    return retVal;
}

STATIC FUNC (void, DOIP_CODE)  DoIP_TpTxListRemoveAll
(
    DoIP_TpTxListType *TxListPtr
)
{
    DoIP_TpTxElementType *elePtr = TxListPtr->Head;
    DoIP_TpTxElementType *tempelePtr;

    /*Clear all job in list */
    while (elePtr != NULL_PTR)
    {
        DOIP_TCP_TX_JOB_CLR (& (elePtr->Job) );
        tempelePtr = elePtr;
        elePtr = elePtr->Next;
        tempelePtr->Next = NULL_PTR;
    }

    TxListPtr->Head = NULL_PTR;
}

STATIC FUNC (void, DOIP_CODE) DoIP_TcpTxReqHandler
(
    uint8 TcpConId
)
{
    DoIP_TpSessionType *txSesPtr;
    Std_ReturnType retVal;
    PduIdType PduRTxPduId;
    DoIP_TpTxListType *list;
    DoIP_TpTxJobType job;
    PduInfoType pdu;
    DoIP_PduType pduType;
    PduIdType soadTxPduId;

    /* Start a new transmission session in tx list */
    txSesPtr = DOIP_TCP_CON_MGMT_TX_SESSION_PTR (TcpConId);

    if (txSesPtr->PayloadType == DOIP_INVALID_PAYLOAD_TYPE)
    {
        list = DOIP_TP_TX_LIST_PTR (TcpConId);
        retVal = DoIP_TpTxListGetOldestJob (list, &job);

        if (E_OK == retVal)
        {
            /* Fill the pdu info below */
            pdu.SduLength = job.TotalLen;

            /* It's a diagnostic message and relevant to a doip channel */
            if (job.PayloadType == DOIP_PAYLOAD_TYPE_DIAG_MSG)
            {
                pduType = DOIP_GET_CHANNEL_PDU_TYPE (job.ChannelId);

                if (pduType == DOIP_IFPDU)
                {
                    /* Find IF-PDU buffer, data is already in buffer */
                    pdu.SduDataPtr = DOIP_TCP_TX_IFPDU_BUF_PTR (DOIP_GET_CHANNEL_IFPDU_BUFID (job.ChannelId));
                }
                else
                {
                    pdu.SduDataPtr = NULL_PTR;/*TP-PDU is copied from PduR*/
                }
            }
            else
            {
                /* Non-diagnositc message , data is keeped in tcp connection send buffer */
                pdu.SduDataPtr = DOIP_TCP_CON_MGMT_SEND_BUF_PTR (TcpConId);
            }

            /* Tryting to send pdu */
            soadTxPduId = DOIP_GET_TCPCON_SOAD_TX_PDUID (TcpConId);
            /*SWS_DoIP_00220*/
            retVal = SoAd_TpTransmit (soadTxPduId, &pdu);

            if (retVal == E_OK)
            {
                /* Update the session infomation */
                txSesPtr->TotalLen = job.TotalLen;
                txSesPtr->PayloadType = job.PayloadType;
                txSesPtr->ChannelId = job.ChannelId;
                txSesPtr->Offset = (uint16) 0;
                DOIP_TCP_CON_MGMT_SEND_BUF_OFFSET(TcpConId) = (uint16)0;
            }
            else/*SWS_DoIP_00223 If the call to SoAd_TpTransmit returns E_NOT_OK the DoIP module shall discard the DoIP message.*/
            {
                /* Indicate PduR result if is needed *//*SWS_DoIP_00228*/
                if (job.PayloadType == DOIP_PAYLOAD_TYPE_DIAG_MSG)
                {
                    /* Indicate PduR transmission is failure */
                    PduRTxPduId = DOIP_GET_CHANNEL_PDUR_TX_PDUID (job.ChannelId);

                    if (pduType == DOIP_TPPDU)
                    {
                        /*SWS_DoIP_00233*/
                        DOIP_CALL_UL_DOIP_TP_TX_CONFIRMATION (PduRTxPduId, E_NOT_OK);
                    }
                    else if (pduType == DOIP_IFPDU)
                    {
                        /*SWS_DoIP_00233*/
                        DOIP_CALL_UL_DOIP_IF_TX_CONFIRMATION (PduRTxPduId);
                    }
                    else
                    {
                        /*do nothing*/
                    }
                }
            }
        }
    }
}

STATIC FUNC (Std_ReturnType, DOIP_CODE) DoIP_TcpRequestTransmit
(
    PduIdType ConId,
    PduIdType ChannelId,
    const PduInfoType *PduInfoPtr,
    uint16 PayloadType
)
{
    Std_ReturnType retVal;
    DoIP_TpSessionType *txSesPtr;
    DoIP_TpTxJobType job;
    DoIP_TpTxListType *list;
    PduIdType soadTxPduId;
    SduDataPtrType bufPtr;
    PduInfoType txPdu;
    DoIP_PduType pduType;
    boolean isInList;

    list = DOIP_TP_TX_LIST_PTR (ConId);

    if (PayloadType == DOIP_PAYLOAD_TYPE_DIAG_MSG)
    {
        isInList = DoIP_TpTxListFindPduId (list, ChannelId);
    }
    else
    {
        isInList = DoIP_TpTxListFindPayloadType (list, PayloadType);
    }

    retVal = E_NOT_OK;

    if (TRUE != isInList)
    {
        /* Prepare PDU info */
        bufPtr = NULL_PTR;

        if (PayloadType == DOIP_PAYLOAD_TYPE_DIAG_MSG)
        {
            /*SWS_DoIP_00284*/
            txPdu.SduLength = PduInfoPtr->SduLength + DOIP_DIAG_MSG_HDR_LEN;

            pduType = DOIP_GET_CHANNEL_PDU_TYPE (ChannelId);

            if (DOIP_IFPDU == pduType)
            {
                bufPtr = DOIP_TCP_TX_IFPDU_BUF_PTR (DOIP_GET_CHANNEL_IFPDU_BUFID (ChannelId));

                Bsw_MemSet (bufPtr, (uint8) 0, ( (uint32) DOIP_DIAG_MSG_HDR_LEN + (uint32) PduInfoPtr->SduLength) );

                /* For diagnostic message, set logical address info, SWS_DoIP_00131*/
                DOIP_U16TOBUF ( ( (DoIP_DiagMsgType *) bufPtr)->SA, DOIP_GET_LOCAL_ADDR() );
                DOIP_U16TOBUF ( ( (DoIP_DiagMsgType *) bufPtr)->TA, DOIP_GET_CHANNEL_SA (ChannelId) );

                /*protect*/
                DOIP_ENTER_CRITICAL_SECTION_TXSESSION();
                /* Copy payload to user data buffer, SWS_DoIP_00173 *//*SWS_DoIP_00279*/
                Bsw_MemCpy ( ( (DoIP_DiagMsgType *) bufPtr)->UserData, PduInfoPtr->SduDataPtr, (uint32) PduInfoPtr->SduLength);
                /*unprotect*/
                DOIP_LEAVE_CRITICAL_SECTION_TXSESSION();
            }

        }
        else
        {
            txPdu.SduLength = PduInfoPtr->SduLength + DOIP_GEN_HDR_LEN;

            bufPtr = DOIP_TCP_CON_MGMT_SEND_BUF_PTR (ConId);
            /* Copy payload to send buffer */
            /*protect*/
            DOIP_ENTER_CRITICAL_SECTION_TXSESSION();
            Bsw_MemCpy (( (DoIP_GenMsgType *)(bufPtr + DOIP_TCP_CON_MGMT_SEND_BUF_OFFSET(ConId)))->Payload, PduInfoPtr->SduDataPtr, (uint32) PduInfoPtr->SduLength);
            DOIP_TCP_CON_MGMT_SEND_BUF_OFFSET(ConId) += (PduInfoPtr->SduLength + DOIP_GEN_HDR_LEN);
            /*unprotect*/
            DOIP_LEAVE_CRITICAL_SECTION_TXSESSION();
        }

        if (bufPtr != NULL_PTR)
        {
            /* Make generic header */
            DoIP_GenericHeaderConstruct (bufPtr, PayloadType, (uint32) ((uint32)txPdu.SduLength - (uint32)DOIP_GEN_HDR_LEN) );

            txPdu.SduDataPtr = bufPtr;
        }
        else
        {
            txPdu.SduDataPtr = (SduDataPtrType) &txPdu; /* no use */
        }

        txSesPtr = DOIP_TCP_CON_MGMT_TX_SESSION_PTR (ConId);
        /*SWS_DoIP_00230
        If the connection to the SoAd is idle, the DoIP shall call the SoAd_TpTransmit function, otherwise
        the DoIP shall store the transmission request and call SoAd_TpTransmit as soon as the connection is idle again.
        */
        /*protect*/
        DOIP_ENTER_CRITICAL_SECTION_TXSESSION();

        if ( (DOIP_TP_TX_LIST_IS_EMPTY (ConId) ) && (txSesPtr->TotalLen == (uint16) 0) )
        {
            soadTxPduId = DOIP_GET_TCPCON_SOAD_TX_PDUID (ConId);
            /*SWS_DoIP_00220*/
            retVal = SoAd_TpTransmit (soadTxPduId, &txPdu);

            /*SWS_DoIP_00223 If the call to SoAd_TpTransmit returns E_NOT_OK the DoIP module shall discard the DoIP message.*/
            if (retVal == E_OK)
            {
                /* Transmit request was acceptted, start new transmission session */
                txSesPtr->TotalLen = txPdu.SduLength;
                txSesPtr->Offset = (uint16) 0;
                txSesPtr->ChannelId = ChannelId;
                txSesPtr->PayloadType = PayloadType;
                DOIP_TCP_CON_MGMT_SEND_BUF_OFFSET(ConId) = (uint16)0;
            }
        }
        else
        {
            /* Fill the job information */
            job.ChannelId = ChannelId;
            job.PayloadType = PayloadType;
            job.TotalLen = txPdu.SduLength;
            retVal = DoIP_TpTxListAppend (list, &job);
        }

        /*unprotect*/
        DOIP_LEAVE_CRITICAL_SECTION_TXSESSION();
    }

    return retVal;
}

STATIC FUNC (Std_ReturnType, DOIP_CODE) DoIP_TcpGetConIdBySoConId
(
    SoAd_SoConIdType SoConId,
    uint8 *ConIdPtr
)
{
    uint8 conId;
    Std_ReturnType retVal;

    retVal = E_NOT_OK;

    for (conId = (uint8) 0; conId < (uint8) DOIP_TCP_CON_NUM; conId++)
    {
        if (DOIP_GET_TCPCON_SOAD_SOCONID (conId) == SoConId)
        {
            *ConIdPtr = conId;
            retVal = E_OK;
            break;
        }
    }

    return retVal;
}

/*SWS_DoIP_00009,SWS_DoIP_00012*/
STATIC FUNC (Std_ReturnType, DOIP_CODE) DoIP_TcpSendGenericHeaderNack
(
    PduIdType ConId,
    uint8 Nack
)
{
    PduInfoType pdu;
    Std_ReturnType retVal;
    uint8 ResNack;

    ResNack = Nack;
    pdu.SduLength = DoIP_NACK_RESPONSE_LENGTH;
    pdu.SduDataPtr = (SduDataPtrType)&ResNack;

    retVal = DoIP_TcpRequestTransmit (ConId, DOIP_INVALID_PDUID, &pdu, DOIP_PAYLOAD_TYPE_GEN_HDR_NACK);

    return retVal;
}

STATIC FUNC (Std_ReturnType, DOIP_CODE) DoIP_TcpSendDiagnosticMessageAck
(
    PduIdType ConId,
    DoIP_LogicAddrType TesterSA,
    uint8 AckCode,
    PduInfoType DiagMsg
)
{
    PduInfoType txPdu;
    Std_ReturnType retVal;
    DoIP_DiagMsgAckType resData;
    uint16 AckNacklength = DOIP_GET_TESTER_NUM_BYTE_DIAG_ACK_NACK(DOIP_TCP_CON_MGMT_PTR(ConId)->TesterId);

    /* Send diagnostic message */
    /*SWS_DoIP_00132*/
    DOIP_U16TOBUF (resData.SA, DOIP_GET_LOCAL_ADDR() );
    /*SWS_DoIP_00133*/
    DOIP_U16TOBUF (resData.TA, TesterSA);
    resData.AckCode = AckCode;

    AckNacklength = DoIP_GetMinValue(DiagMsg.SduLength, AckNacklength);
    Bsw_MemCpy(&resData.DiagMsg, DiagMsg.SduDataPtr, AckNacklength);

    txPdu.SduDataPtr = (SduDataPtrType) &resData;
    txPdu.SduLength = DOIP_DIAG_MSG_ADDR_INFO_LEN + DOIP_ACK_CODE_LEN + AckNacklength;
    /*SWS_DoIP_00009*/
    retVal = DoIP_TcpRequestTransmit (ConId, DOIP_INVALID_ID, &txPdu, DOIP_PAYLOAD_TYPE_DIAG_MSG_ACK);

    return retVal;
}

STATIC FUNC (Std_ReturnType, DOIP_CODE) DoIP_TcpSendDiagnosticMessageNack
(
    PduIdType ConId,
    DoIP_LogicAddrType TesterSA,
    uint8 AckCode,
    PduInfoType DiagMsg
)
{
    PduInfoType txPdu;
    Std_ReturnType retVal;
    DoIP_DiagMsgAckType resData;
    uint16 AckNacklength = DOIP_GET_TESTER_NUM_BYTE_DIAG_ACK_NACK(DOIP_TCP_CON_MGMT_PTR(ConId)->TesterId);

    /* Send diagnostic message nack */
    /*SWS_DoIP_00135*/
    DOIP_U16TOBUF (resData.SA, DOIP_GET_LOCAL_ADDR() );
    /*SWS_DoIP_00136*/
    DOIP_U16TOBUF (resData.TA, TesterSA);
    /*SWS_DoIP_00137*/
    resData.AckCode = AckCode;

    AckNacklength = DoIP_GetMinValue(DiagMsg.SduLength, AckNacklength);
    Bsw_MemCpy(&resData.DiagMsg, DiagMsg.SduDataPtr, AckNacklength);

    txPdu.SduDataPtr = (SduDataPtrType) &resData;
    txPdu.SduLength = DOIP_DIAG_MSG_ADDR_INFO_LEN + DOIP_ACK_CODE_LEN + AckNacklength;
    /*SWS_DoIP_00009*/
    retVal = DoIP_TcpRequestTransmit (ConId, DOIP_INVALID_ID, &txPdu, DOIP_PAYLOAD_TYPE_DIAG_MSG_NACK);

    return retVal;
}

STATIC FUNC (Std_ReturnType, DOIP_CODE) DoIP_TcpGetConIdByTesterSA
(
    DoIP_LogicAddrType SA,
    uint8 *ConIdPtr
)
{
    uint8 i, testerId;
    Std_ReturnType retVal = E_NOT_OK;

    for (i = (uint8) 0; i < (uint8) DOIP_TCP_CON_NUM; i++)
    {
        testerId = DoIP_TcpConMgmt[i].TesterId;

        if ( (testerId < DOIP_TESTER_NUM) && (DOIP_GET_TESTER_SA (testerId) == SA) )
        {
            *ConIdPtr = i;
            retVal = E_OK;
            break;
        }
    }

    return retVal;
}

STATIC FUNC (uint8, DOIP_CODE) DoIP_TcpGetCurrentTesterConNum
(
    void
)
{
    uint8 testerConNum = (uint8) 0;
    uint8 i;

    for (i = (uint8) 0; i < (uint8) DOIP_TCP_CON_NUM; i++)
    {
        if ( (DoIP_RoutActivMgmt[i].Status == DOIP_ROUTING_ACTIVATION_ACTIVED) ||
                (DoIP_RoutActivMgmt[i].Status == DOIP_ROUTING_ACTIVATION_AUTH_PENDING) ||
                (DoIP_RoutActivMgmt[i].Status == DOIP_ROUTING_ACTIVATION_CONFIRM_PENDING) )
        {
            testerConNum++;
        }
    }

    return testerConNum;
}

STATIC FUNC (Std_ReturnType, DOIP_CODE) DoIP_TryAuthentication
(
    PduIdType ConId,
    uint8 *ResDataPtr
)
{
    boolean authentified;
    uint8 authRes[DOIP_AUTH_COMFIRM_RES_LENGTH];
    DoIP_RoutActivMgmtType *routActivMgmtPtr;
    Std_ReturnType retVal;
    P2VAR (void, AUTOMATIC, AUTOMATIC) authcallback;
    uint8 resLen;
    uint8 reqLen;

    retVal = E_OK;
    routActivMgmtPtr = DOIP_ROUT_ACTIV_MGMT_PTR (ConId);
    /* SWS_DoIP_00109 */
    authcallback = DOIP_GET_ROUT_ACTIV_AUTH_CALLBACK (routActivMgmtPtr->ReqParam.RoutActivId);

    if (NULL_PTR != authcallback)
    {
        reqLen = DOIP_GET_ROUT_ACTIV_AUTH_REQ_LEN (routActivMgmtPtr->ReqParam.RoutActivId);
        resLen = DOIP_GET_ROUT_ACTIV_AUTH_RES_LEN (routActivMgmtPtr->ReqParam.RoutActivId);

        /* SWS_DoIP_00109 */
        if ( ( (uint8) 0 != reqLen) && ( (uint8) 0 != resLen) )
        {
            /*SWS_DoIP_00049*/
            /* PRQA S 307 ++ */
            /* Need cast pointer type */
            retVal = ((DoIP_AuthCallbackReqResType) authcallback)(&authentified, & (routActivMgmtPtr->ReqParam.OemResv[0]), &authRes[0]);
        }
        else if ( (uint8) 0 != reqLen)
        {
            /*SWS_DoIP_00049*/
            retVal = ((DoIP_AuthCallbackReqType) authcallback)(&authentified, & (routActivMgmtPtr->ReqParam.OemResv[0]) );
        }
        else if ( (uint8) 0 != resLen)
        {
            /*SWS_DoIP_00049*/
            retVal = ((DoIP_AuthCallbackResType) authcallback)(&authentified, &authRes[0]);
        }
        else
        {
            /*SWS_DoIP_00049*/
            retVal = ( (DoIP_AuthCallbackType) authcallback)(&authentified);
        }

        /* SWS_DoIP_00049
         * E_OK only means authentified and resOemResv valid.
         */
        if (E_OK == retVal)
        {
            if (authentified != TRUE)
            {
                retVal = E_NOT_OK;
            }
            else /*authentified*/
            {
                if (resLen != (uint8) 0)
                {
                    /* copy to response message oem reserved, SWS_DoIP_00161, SWS_DoIP_00120 */
                    Bsw_MemCpy (& ( ( (DoIP_RoutActivResType *) ResDataPtr)->OemResv[0]), &authRes[0], (uint32) resLen);
        		/* PRQA S 307 -- */
                }
            }
        }
    }

    return retVal;
}

STATIC FUNC (Std_ReturnType, DOIP_CODE) DoIP_TryConfirmation
(
    PduIdType ConId,
    uint8 *ResDataPtr
)
{
    boolean confirmed;
    uint8 confirmRes[DOIP_AUTH_COMFIRM_RES_LENGTH];
    DoIP_RoutActivMgmtType *routActivMgmtPtr;
    Std_ReturnType retVal;
    P2VAR (void, AUTOMATIC, AUTOMATIC) confirmcallback;
    uint8 reqlen;
    uint8 reslen;

    retVal = E_OK;
    routActivMgmtPtr = DOIP_ROUT_ACTIV_MGMT_PTR (ConId);

    /* SWS_DoIP_00112 */
    confirmcallback = DOIP_GET_ROUT_ACTIV_CONFIRM_CALLBACK (routActivMgmtPtr->ReqParam.RoutActivId);

    if (NULL_PTR != confirmcallback)
    {
        reqlen = DOIP_GET_ROUT_ACTIV_CONFIRM_REQ_LEN (routActivMgmtPtr->ReqParam.RoutActivId);
        reslen = DOIP_GET_ROUT_ACTIV_CONFIRM_RES_LEN (routActivMgmtPtr->ReqParam.RoutActivId);

        /*SWS_DoIP_00112*/
        if ( ( (uint8) 0 != reqlen) && ( (uint8) 0 != reslen) )
        {
            /*SWS_DoIP_00048*/
	  /*PRQA S 307 ++*/
            /* Need cast to function pointer */
            retVal = ( (DoIP_ConfirmCallbackReqResType) confirmcallback) (&confirmed,
                     & (routActivMgmtPtr->ReqParam.OemResv[DOIP_AUTH_COMFIRM_RES_LENGTH - reqlen]),
                     &confirmRes[0]);
        }
        else if ( (uint8) 0 != reqlen)
        {
            /*SWS_DoIP_00048*/
            retVal = ( (DoIP_ConfirmCallbackReqType) confirmcallback) (&confirmed,
                     & (routActivMgmtPtr->ReqParam.OemResv[DOIP_AUTH_COMFIRM_RES_LENGTH - reqlen]) );
        }
        else if ( (uint8) 0 != reslen)
        {
            /*SWS_DoIP_00048*/
            retVal = ( (DoIP_ConfirmCallbackResType) confirmcallback) (&confirmed, &confirmRes[0]);
        }
        else
        {
            /*SWS_DoIP_00048*/
            retVal = ( (DoIP_ConfirmCallbackType) confirmcallback) (&confirmed);
            /*PRQA S 307 --*/
        }

        if (E_OK == retVal)
        {
            if (confirmed != TRUE)
            {
                retVal = E_NOT_OK;
            }
            else /*confirmed*/
            {
                if (reslen != (uint8) 0)
                {
                    /* copy to response message oem reserved, SWS_DoIP_00112, SWS_DoIP_00120*/
                    Bsw_MemCpy (& ( ( (DoIP_RoutActivResType *) ResDataPtr)->OemResv[DOIP_AUTH_COMFIRM_RES_LENGTH - reslen]), &confirmRes[0], (uint32) reslen);
                }
            }
        }
    }

    return retVal;
}

STATIC FUNC (Std_ReturnType, DOIP_CODE) DoIP_AliveCheckResTimeOutIndication
(
    uint8 OwnerId
)
{
    if (DoIP_RoutActivMgmt[OwnerId].Status == DOIP_ROUTING_ACTIVATION_ALIVE_CHECK)
    {
        /*SWS_DoIP_00105*/
        DoIP_RoutActivMgmt[OwnerId].AliveCheckCount = (uint8) 0;
        DoIP_RoutActivMgmt[OwnerId].Status = DOIP_ROUTING_ACTIVATION_AUTH_PENDING;
        DoIP_RoutActivMgmt[OwnerId].AliveCheckOnlyOne = FALSE;
        DoIP_TcpConMgmt[OwnerId].TesterId = DoIP_RoutActivMgmt[OwnerId].ReqParam.TesterId;
    }

    return E_OK;
}

STATIC FUNC (Std_ReturnType, DOIP_CODE) DoIP_AliveCheckResIndication
(
    uint8 OwnerId
)
{
    Std_ReturnType retVal = E_OK;
    DoIP_RoutActivResType routActivRes;
    PduInfoType txPdu;
    DoIP_RoutActivReqParamType *reqParam;
    uint8 i;

    if (DoIP_RoutActivMgmt[OwnerId].Status == DOIP_ROUTING_ACTIVATION_ALIVE_CHECK)
    {
        /*protect*/
        DOIP_ENTER_CRITICAL_SECTION_ALVECHECK();
        DoIP_RoutActivMgmt[OwnerId].AliveCheckCount--;

        if (DoIP_RoutActivMgmt[OwnerId].AliveCheckCount == (uint8) 0)
        {
            reqParam = DOIP_ROUT_ACTIV_MGMT_REQ_PARAM_PTR (OwnerId);

            /* Prepare the response message, SWS_DoIP_00105,  SWS_DoIP_00116 */
            DOIP_U16TOBUF (routActivRes.SA, reqParam->SA);
            /*SWS_DoIP_00118*/
            DOIP_U16TOBUF (routActivRes.TA, DOIP_GET_LOCAL_ADDR() );

            if (TRUE == DoIP_RoutActivMgmt[OwnerId].AliveCheckOnlyOne)
            {
                DoIP_RoutActivMgmt[OwnerId].AliveCheckOnlyOne = FALSE;
                /*SWS_DoIP_00119, SWS_DoIP_00105*/
                routActivRes.ResCode = DOIP_ROUTING_ACTIVATION_RES_CODE_SA_ACTIVED_ON_OTHER_SOCK;
            }
            else
            {
                /*SWS_DoIP_00119, SWS_DoIP_00107*/
                routActivRes.ResCode = DOIP_ROUTING_ACTIVATION_RES_CODE_NO_SOCK;
            }

            for (i = (uint8) 0; i < DOIP_REVE_LENGTH; i++)
            {
                routActivRes.Resv[i] = (uint8) 0;
                routActivRes.OemResv[i] = DOIP_ROUTING_ACTIVATION_RES_OEM_RESERVED;
            }

            txPdu.SduDataPtr = (SduDataPtrType) &routActivRes;
            txPdu.SduLength = DOIP_ROUTACTIVE_RESPONSE_LENGTH;
            /*SWS_DoIP_00009*/
            retVal = DoIP_TcpRequestTransmit (OwnerId, DOIP_INVALID_PDUID, &txPdu, DOIP_PAYLOAD_TYPE_ROUTING_ACTIVATION_RES);
            /* Reset the routing activation information */
            DoIP_RoutActivMgmt[OwnerId].Status = DOIP_ROUTING_ACTIVATION_REQ_NONE;
            reqParam->SA = DOIP_INVALID_LOGIC_ADDR;
            reqParam->TesterId = DOIP_INVALID_TESTER_INDEX;
            reqParam->ActionType = DOIP_INVALID_ID;
            reqParam->RoutActivId = DOIP_INVALID_ID;
            Bsw_MemSet (&reqParam->OemResv[0], DOIP_ROUTING_ACTIVATION_RES_OEM_RESERVED, (uint32) DOIP_REVE_LENGTH);
        }

        /*unprotect*/
        DOIP_LEAVE_CRITICAL_SECTION_ALVECHECK();
    }
    else
    {
        retVal = E_NOT_OK;
    }

    return retVal;
}

STATIC FUNC (Std_ReturnType, DOIP_CODE) DoIP_TryRoutingActivation
(
    PduIdType ConId
)
{
    uint8 routActivId, i, targetAddrId;
    DoIP_RoutActivMgmtType *routActivMgmtPtr;
    Std_ReturnType retVal = E_OK;
    boolean done;
    PduIdType channelId;
    DoIP_RoutActivResType resData;
    PduInfoType txPdu;
    PduLengthType resLen;

    done = FALSE;
    routActivMgmtPtr = DOIP_ROUT_ACTIV_MGMT_PTR (ConId);
    routActivId = routActivMgmtPtr->ReqParam.RoutActivId;

    if((DOIP_GET_ROUT_ACTIV_AUTH_RES_LEN(routActivId) + DOIP_GET_ROUT_ACTIV_CONFIRM_RES_LEN(routActivId)) == 0)
    {
        /* OEM Reserve NOT Configured */
        resLen = DOIP_ROUTACTIVE_RESPONSE_NOOEMRESV_LENGTH;
    }
    else
    {
        /* OEM Reserve Configured */
        resLen = DOIP_ROUTACTIVE_RESPONSE_LENGTH;
    }

    /*
    if not actived with confirmed and authenticated ,
    init Resv and OemResv,response code default
    */
    for (i = (uint8) 0; i < DOIP_REVE_LENGTH; i++)
    {
        resData.Resv[i] = (uint8)0;
        resData.OemResv[i] = DOIP_ROUTING_ACTIVATION_RES_OEM_RESERVED;
    }

    while ((done == FALSE) && (retVal == E_OK))
    {
        /*protect*/
        DOIP_ENTER_CRITICAL_SECTION_ROUTINGACTIVATION();

        switch ((*routActivMgmtPtr).Status)
        {
        case DOIP_ROUTING_ACTIVATION_ALIVE_CHECK:
            retVal = E_NOT_OK;
            break;

        case DOIP_ROUTING_ACTIVATION_AUTH_PENDING:
#if(DOIP_HOZON_PLATFORM == DOIP_OEM_PLATFORM)
                /* Send Seed */
                /*SWS_DoIP_00116*/
                DOIP_U16TOBUF (resData.SA, DOIP_GET_TESTER_SA (routActivMgmtPtr->ReqParam.TesterId) );
                /*SWS_DoIP_00118*/
                DOIP_U16TOBUF (resData.TA, DOIP_GET_LOCAL_ADDR() );
                if(E_OK == DoIP_SendAuthRespWithSeed(ConId, resData.SA, resData.TA))
                {
                    routActivMgmtPtr->Status = DOIP_ROUTING_ACTIVATION_WAIT_KEY;
                    retVal = E_OK;
                }
                else
                {
                    /*clear the tester id set when routing activation requested is acceptted */
                    DoIP_TcpConMgmt[ConId].TesterId = DOIP_INVALID_TESTER_INDEX;
                    /* SWS_DoIP_00111 */
                    routActivMgmtPtr->Status = DOIP_ROUTING_ACTIVATION_REQ_NONE;
                    /*SWS_DoIP_00119*/
                    resData.ResCode = DOIP_ROUTING_ACTIVATION_RES_CODE_INVALID_KEY;

                    txPdu.SduLength = resLen;
                    txPdu.SduDataPtr = (SduDataPtrType) &resData;
                    retVal = DoIP_TcpRequestTransmit(ConId, DOIP_INVALID_PDUID, &txPdu, DOIP_PAYLOAD_TYPE_ROUTING_ACTIVATION_RES);
                }
                done = TRUE;
                break;

            case DOIP_ROUTING_ACTIVATION_WAIT_KEY:
                retVal = E_NOT_OK;
                break;

            case DOIP_ROUTING_ACTIVATION_KEY_RECEIVED:
#endif
            retVal = DoIP_TryAuthentication (ConId, (uint8 *) &resData);

            if (E_OK == retVal)
            {
                routActivMgmtPtr->Status = DOIP_ROUTING_ACTIVATION_CONFIRM_PENDING;
            }
            else if (DOIP_E_PENDING == retVal)
            {
                /* SWS_DoIP_00110
                 * Try authentification next main loop
                 * Tester is registed to this tcp connection but not actived yet
                 */
            }
            else
            {
                /*clear the tester id setted when routing activation requested is acceptted */
                DoIP_TcpConMgmt[ConId].TesterId = DOIP_INVALID_TESTER_INDEX;
                /* SWS_DoIP_00111 */
                routActivMgmtPtr->Status = DOIP_ROUTING_ACTIVATION_REQ_NONE;
                /*SWS_DoIP_00116*/
                DOIP_U16TOBUF (resData.SA, DOIP_GET_TESTER_SA (routActivMgmtPtr->ReqParam.TesterId) );
                /*SWS_DoIP_00118*/
                DOIP_U16TOBUF (resData.TA, DOIP_GET_LOCAL_ADDR() );
                /*SWS_DoIP_00119*/
                resData.ResCode = DOIP_ROUTING_ACTIVATION_RES_CODE_MISSING_AUTH;

                txPdu.SduLength = resLen;
                txPdu.SduDataPtr = (SduDataPtrType) &resData;
                /*SWS_DoIP_00009*/
                retVal = DoIP_TcpRequestTransmit (ConId, DOIP_INVALID_PDUID, &txPdu, DOIP_PAYLOAD_TYPE_ROUTING_ACTIVATION_RES);
                done = TRUE;
            }

            break;

        case DOIP_ROUTING_ACTIVATION_CONFIRM_PENDING:
            retVal = DoIP_TryConfirmation (ConId, (uint8 *) &resData);

            /*SWS_DoIP_00113*/
            if (E_OK == retVal)
            {
                DoIP_RoutActivMgmt[ConId].Status = DOIP_ROUTING_ACTIVATION_ACTIVED;
            }
            /*SWS_DoIP_00114*/
            else if (DOIP_E_PENDING == retVal)
            {
                /* Tester is registed to this tcp connection but not actived yet */
                /*SWS_DoIP_00116*/
                DOIP_U16TOBUF (resData.SA, DOIP_GET_TESTER_SA (routActivMgmtPtr->ReqParam.TesterId) );
                /*SWS_DoIP_00118*/
                DOIP_U16TOBUF (resData.TA, DOIP_GET_LOCAL_ADDR() );
                /*SWS_DoIP_00119*/
                resData.ResCode = DOIP_ROUTING_ACTIVATION_RES_CODE_CONFIRMATION_REQUIRED;

                txPdu.SduLength = resLen;
                txPdu.SduDataPtr = (SduDataPtrType) &resData;
                /*SWS_DoIP_00009*/
                retVal = DoIP_TcpRequestTransmit (ConId, DOIP_INVALID_PDUID, &txPdu, DOIP_PAYLOAD_TYPE_ROUTING_ACTIVATION_RES);
                /* Try confirmation next main loop */
                done = TRUE;
            }
            /*SWS_DoIP_00274*/
            else
            {
                /*clear the tester id setted when routing activation requested is acceptted */
                DoIP_TcpConMgmt[ConId].TesterId = DOIP_INVALID_TESTER_INDEX;

                routActivMgmtPtr->Status = DOIP_ROUTING_ACTIVATION_REQ_NONE;
                /*SWS_DoIP_00116*/
                DOIP_U16TOBUF (resData.SA, DOIP_GET_TESTER_SA (routActivMgmtPtr->ReqParam.TesterId) );
                /*SWS_DoIP_00118*/
                DOIP_U16TOBUF (resData.TA, DOIP_GET_LOCAL_ADDR() );
                /*SWS_DoIP_00119*/
                resData.ResCode = DOIP_ROUTING_ACTIVATION_RES_CODE_CONFIRMATION_REJECTED;

                txPdu.SduLength = resLen;
                txPdu.SduDataPtr = (SduDataPtrType) &resData;
                /*SWS_DoIP_00009*/
                retVal = DoIP_TcpRequestTransmit (ConId, DOIP_INVALID_PDUID, &txPdu, DOIP_PAYLOAD_TYPE_ROUTING_ACTIVATION_RES);
                done = TRUE;
            }

            break;

        case DOIP_ROUTING_ACTIVATION_ACTIVED:
            DoIP_TcpConMgmt[ConId].TesterId = routActivMgmtPtr->ReqParam.TesterId;

            /* Active all relevent channels */
            for (i = (uint8) 0; i < DOIP_GET_ROUT_ACTIV_NUM_TARGET_ADDR (routActivId); i++)
            {
                targetAddrId = DOIP_GET_ROUT_ACTIV_TARGET_ADDR_ID (routActivId, i);
                retVal = DoIP_GetChannelId (DOIP_GET_TESTER_SA (routActivMgmtPtr->ReqParam.TesterId), DOIP_GET_TARGET_ADDR (targetAddrId), &channelId);

                if (retVal != E_NOT_OK)
                {
                    DoIP_ChannelCtrl[channelId].TcpConId = ConId;
                    DoIP_ChannelCtrl[channelId].RoutingActived = TRUE;
                }
            }

            /*SWS_DoIP_00116*/
            DOIP_U16TOBUF (resData.SA, DOIP_GET_TESTER_SA (routActivMgmtPtr->ReqParam.TesterId) );
            /*SWS_DoIP_00118*/
            DOIP_U16TOBUF (resData.TA, DOIP_GET_LOCAL_ADDR() );
            /*SWS_DoIP_00119*/
            resData.ResCode = DOIP_ROUTING_ACTIVATION_RES_CODE_SUCCESS;

            txPdu.SduLength = resLen;
            txPdu.SduDataPtr = (SduDataPtrType) &resData;
            /*SWS_DoIP_00009, SWS_DoIP_00113*/
            retVal = DoIP_TcpRequestTransmit (ConId, DOIP_INVALID_PDUID, &txPdu, DOIP_PAYLOAD_TYPE_ROUTING_ACTIVATION_RES);
            done = TRUE;
            break;

        default:
            routActivMgmtPtr->Status = DOIP_ROUTING_ACTIVATION_REQ_NONE;
            retVal = E_NOT_OK;
            break;
        }

        /*unprotect*/
        DOIP_LEAVE_CRITICAL_SECTION_ROUTINGACTIVATION();
    }

    return retVal;
}

STATIC FUNC (void, DOIP_CODE) DoIP_AliveCheckResReceived
(
    PduIdType id,
    const uint8 *MsgBufPtr
)
{
    DoIP_LogicAddrType SA;
    uint8 testerId;

    SA =  DOIP_U16 ( ( (const DoIP_RoutActivReqMsgType *) MsgBufPtr)->SA);
    testerId = DoIP_TcpConMgmt[id].TesterId;

    /*the received SA matches the registered SA*/
    if (SA == DOIP_GET_TESTER_SA (testerId) )
    {
        if (TRUE == DoIP_TcpConMgmt[id].AliveCheckPerformed)
        {
            /* Indicate the connection who triggered this alive check */
            (void) DoIP_AliveCheckResIndication (DoIP_TcpConMgmt[id].OwnerId);

            /* Reset alive check status */
            DoIP_TcpConMgmt[id].OwnerId = DOIP_INVALID_ID;
            DoIP_TcpConMgmt[id].AliveCheckTimer = (uint32) 0;
            DoIP_TcpConMgmt[id].AliveCheckPerformed = FALSE;
        }
        else
        {
            /*do nothing*/
        }
    }
    else
    {
        /*SWS_DoIP_00141*/
        DoIP_TcpConMgmt[id].SoConCloseStatus = DOIP_SOCON_CLOSE_REQ_PENDING;/*SWS_DoIP_00058*/
    }

}

STATIC FUNC (uint16, DOIP_CODE) DoIP_GetMinValue (uint16 a, uint16 b)
{
    uint16 ret;

    if (a < b)
    {
        ret = a;
    }
    else
    {
        ret = b;
    }

    return ret;
}

STATIC FUNC (Std_ReturnType, DOIP_CODE) DoIP_TcpWaitForData
(
    PduIdType id,
    PduInfoType *PduInfoPtr,
    PduLengthType WaitLen
)
{
    PduLengthType copyLen;
    uint8 *rxBufPtr;
    Std_ReturnType retVal;
    DoIP_TpSessionType *tpSessionPtr;

    retVal = E_NOT_OK;
    tpSessionPtr = DOIP_TCP_CON_MGMT_RX_SESSION_PTR (id);

    if (tpSessionPtr->Offset < WaitLen)
    {
        /* Trying to copy whole generic header */
        rxBufPtr = DOIP_TCP_CON_MGMT_RECV_BUF_PTR (id);
        copyLen = (PduLengthType)(DoIP_GetMinValue ( (uint16)WaitLen - (uint16)tpSessionPtr->Offset, (uint16)PduInfoPtr->SduLength ));
        Bsw_MemCpy (&rxBufPtr[tpSessionPtr->Offset], PduInfoPtr->SduDataPtr, (uint32) copyLen);
        tpSessionPtr->Offset += copyLen;
        PduInfoPtr->SduLength -= copyLen;
        PduInfoPtr->SduDataPtr = (SduDataPtrType)(&PduInfoPtr->SduDataPtr[copyLen]);
    }

    if (tpSessionPtr->Offset >= WaitLen)
    {
        retVal = E_OK;
    }

    return retVal;
}

STATIC FUNC (BufReq_ReturnType, DOIP_CODE) DoIP_DiagnosticMessageRoute
(
    PduIdType id,
    PduInfoType *info,
    PduLengthType *bufferSizePtr
)
{
    BufReq_ReturnType bufReq;
    PduIdType pdurRxPduId;
    DoIP_TpSessionType *tpSessionPtr;

    bufReq = BUFREQ_E_NOT_OK;
    tpSessionPtr = DOIP_TCP_CON_MGMT_RX_SESSION_PTR (id);
    pdurRxPduId = DOIP_GET_CHANNEL_PDUR_RX_PDUID (tpSessionPtr->ChannelId);

    tpSessionPtr->Offset += info->SduLength;

    /* SWS_DoIP_00218 *//*SWS_DoIP_00260*//*SWS_DoIP_00044*/
    bufReq = DOIP_CALL_UL_DOIP_TP_COPY_RX_DATA (pdurRxPduId, info, bufferSizePtr);

    if (bufReq == BUFREQ_OK)
    {
        /* SWS_DoIP_00259
         * Modify the bufferSizePtr at the end
         */
        if (tpSessionPtr->Offset == tpSessionPtr->TotalLen)
        {
            *bufferSizePtr = (uint16) 0;
            /*SWS_DoIP_00221*/
            DOIP_CALL_UL_DOIP_TP_RX_INDICATION (pdurRxPduId, E_OK);
            /*SWS_DoIP_00129*/
            (void) DoIP_TcpSendDiagnosticMessageAck (id, DOIP_GET_CHANNEL_SA (tpSessionPtr->ChannelId), (uint8)0, *info);
            DOIP_TP_SESSION_CLR (tpSessionPtr);
        }
    }
    else/*SWS_DoIP_00217*/
    {
        DOIP_CALL_UL_DOIP_TP_RX_INDICATION (pdurRxPduId, E_NOT_OK);
        /* SWS_DoIP_00174*/
        (void) DoIP_TcpSendDiagnosticMessageNack (id, DOIP_GET_CHANNEL_SA (tpSessionPtr->ChannelId), DOIP_DIAG_MSG_NACK_TP_ERROR, *info);

        tpSessionPtr->SkipMsg = TRUE;
        /*return OK,in order to SoAd donot close connection*/
        /*if((bufReq == BUFREQ_E_OVFL) || (bufReq == BUFREQ_E_BUSY))*/

        bufReq = BUFREQ_OK;
    }

    info->SduLength = (uint16)0;
    return bufReq;
}

STATIC FUNC (BufReq_ReturnType, DOIP_CODE) DoIP_DiagnosticMessageReceive
(
    PduIdType id,
    PduInfoType *info,
    PduLengthType *bufferSizePtr
)
{
    BufReq_ReturnType bufReq;
    uint8 *rxBufPtr;
    Std_ReturnType retVal;
    DoIP_TpSessionType *tpSessionPtr;
    DoIP_TcpConMgmtType *tcpMgmtPtr;
    DoIP_LogicAddrType sa, ta;
    PduIdType pdurRxPduId;
    uint8 testerId;
    PduIdType channelId;

    bufReq = BUFREQ_OK;
    retVal = E_NOT_OK;
    tpSessionPtr = DOIP_TCP_CON_MGMT_RX_SESSION_PTR (id);
    tcpMgmtPtr = DOIP_TCP_CON_MGMT_PTR (id);
    rxBufPtr = DOIP_TCP_CON_MGMT_RECV_BUF_PTR (id);

    /* Check logical address is valid or not  */
    testerId = DoIP_TcpConMgmt[id].TesterId;

    if (tpSessionPtr->Offset < DOIP_DIAG_MSG_HDR_LEN)
    {
        retVal = DoIP_TcpWaitForData (id, info, DOIP_DIAG_MSG_HDR_LEN);

        if (E_OK == retVal)
        {
            /* Parse logical address infomation */
            sa = DOIP_U16 ( ( (DoIP_DiagMsgHdrType *) rxBufPtr)->SA);
            ta = DOIP_U16 ( ( (DoIP_DiagMsgHdrType *) rxBufPtr)->TA);

            if ( (testerId < DOIP_TESTER_NUM) && (DOIP_GET_TESTER_SA (testerId) == sa) )
            {
                retVal = DoIP_GetChannelId (sa, ta, &channelId );

                if (retVal == E_NOT_OK) /*unknown ta*/
                {
                    /* Send diagnostic message nack, SWS_DoIP_00124 */
                    (void) DoIP_TcpSendDiagnosticMessageNack (id, sa, DOIP_DIAG_MSG_NACK_UNKONWN_TA, *info);
                    tpSessionPtr->SkipMsg = TRUE;
                    retVal = E_NOT_OK;
                }
                else if (DoIP_ChannelCtrl[channelId].RoutingActived != TRUE) /* check current channel is routing actived or not */
                {
                    tpSessionPtr->ChannelId = channelId;
                    /* Send diagnostic message nack, TA was not activated SWS_DoIP_00127 */
                    (void) DoIP_TcpSendDiagnosticMessageNack (id, sa, DOIP_DIAG_MSG_NACK_TA_INACTIVED, *info);
                    tpSessionPtr->SkipMsg = TRUE;
                    retVal = E_NOT_OK;
                }
                else
                {
                    tpSessionPtr->ChannelId = channelId;
                }

                *bufferSizePtr = tpSessionPtr->TotalLen - tpSessionPtr->Offset;
            }
            else/*SWS_DoIP_00123, a "Source Address" (equals DoIPTesterSA) which is not registered on an established socket connection*/
            {
                (void) DoIP_TcpSendDiagnosticMessageNack (id, sa, DOIP_DIAG_MSG_NACK_UNKONWN_SA, *info);
                /*SWS_DoIP_00058*/
                tcpMgmtPtr->SoConCloseStatus = DOIP_SOCON_CLOSE_REQ_PENDING;
                DOIP_TP_SESSION_CLR (tpSessionPtr);
                /*the remainning data will be abandoned*/
                info->SduLength = (PduLengthType) 0;
                retVal = E_NOT_OK;
            }

            if (E_OK == retVal)
            {
                pdurRxPduId = DOIP_GET_CHANNEL_PDUR_RX_PDUID (tpSessionPtr->ChannelId);
                /*SWS_DoIP_00212*//*SWS_DoIP_00044*/
                bufReq = DOIP_CALL_UL_DOIP_TP_START_OF_RECEPTION (pdurRxPduId, NULL_PTR, (tpSessionPtr->TotalLen - DOIP_DIAG_MSG_HDR_LEN), bufferSizePtr);

                switch (bufReq)
                {
                case BUFREQ_E_OVFL:
                   /*SWS_DoIP_00126*/
                    (void) DoIP_TcpSendDiagnosticMessageNack (id, sa, DOIP_DIAG_MSG_NACK_OUT_OF_MEMORY, *info);

                    tpSessionPtr->SkipMsg = TRUE;
                    bufReq = BUFREQ_OK;

                    DOIP_CALL_UL_DOIP_TP_RX_INDICATION (pdurRxPduId, E_NOT_OK);
                    break;

                case BUFREQ_OK:
                    /* NO Operation*/
                    break;
                    
                default: /* BUFREQ_E_NOT_OK || BUFREQ_E_BUSY */
                    /*SWS_DoIP_00216*/
                    /* SWS_DoIP_00174
                    * If  the  PduR  is  not  accepting  the  data  totally,  the
                    * DoIP module shall send a diagnostic message negative acknowledge
                    * message with the diagnostic message negative acknowledge code
                    * set  to  0x08. Additionally the message shall be discarded.
                    */
                    /* Send diagnostic message nack */
                    (void) DoIP_TcpSendDiagnosticMessageNack (id, sa, DOIP_DIAG_MSG_NACK_TP_ERROR, *info);

                    tpSessionPtr->SkipMsg = TRUE;
                    /*return OK,in order to SoAd donot close connection*/
                    /* beibei.xing the BUFREQ_E_NOT_OK may be returned by Dcm */
                    /*if((bufReq == BUFREQ_E_OVFL) || (bufReq == BUFREQ_E_BUSY))*/
                    bufReq = BUFREQ_OK;
                    break;
                }
            }
        }
        else
        {
            /* had't received enough data*/
            *bufferSizePtr = tpSessionPtr->TotalLen - tpSessionPtr->Offset;
        }

    }
    else/* Receiving, SWS_DoIP_00128*/
    {
        /* Copy to local buffer for DoIPNumByteDiagAckNack*/
        /*Bsw_MemCpy(&rxBufPtr[tpSessionPtr->Offset], info->SduDataPtr, info->SduLength);*/
        bufReq = DoIP_DiagnosticMessageRoute (id, info, bufferSizePtr);
    }

    return bufReq;
}

STATIC FUNC (BufReq_ReturnType, DOIP_CODE) DoIP_TcpReceive
(
    PduIdType id,
    const PduInfoType *info,
    PduLengthType *bufferSizePtr
)
{
    DoIP_TcpConMgmtType *tcpMgmtPtr;
    PduInfoType rxPduInfo;
    uint8 *rxBufPtr;
    BufReq_ReturnType bufReq;
    Std_ReturnType err;
    DoIP_TpSessionType *tpSessionPtr;
    uint16 type;
    uint32 len;

    bufReq = BUFREQ_OK;

    tcpMgmtPtr = DOIP_TCP_CON_MGMT_PTR (id);

    tpSessionPtr = DOIP_TCP_CON_MGMT_RX_SESSION_PTR (id);
    rxBufPtr = DOIP_TCP_CON_MGMT_RECV_BUF_PTR (id);

    rxPduInfo.SduLength = info->SduLength;
    rxPduInfo.SduDataPtr = info->SduDataPtr;

    /*SWS_DoIP_00209*/
    while (rxPduInfo.SduLength > (uint16) 0)
    {
        if (tpSessionPtr->Offset < DOIP_GEN_HDR_LEN)
        {
            err = DoIP_TcpWaitForData (id, &rxPduInfo, DOIP_GEN_HDR_LEN);

            if (E_OK == err)
            {
                err = DoIP_GenericHeaderCheckSyncPattern (rxBufPtr, (uint8)DOIP_PROTOCOL_TCP);

                if (E_OK == err)
                {
                    /* We consume that payload type and payload length are valid when sync pattern is ok */
                    type = DOIP_U16 (((DoIP_GenHdrType*)rxBufPtr)->PayloadType );
                    len = DOIP_U32 (((DoIP_GenHdrType*)rxBufPtr)->Length );

                    /* Once sync pattern is valid, record the length info for futher process,
                     * even this message will be skipped
                     */
                    tpSessionPtr->TotalLen = ( (uint16) len + DOIP_GEN_HDR_LEN);

                    if (!DOIP_IS_TCP_RX_PAYLOAD_TYPE_SUPPORT (type) )
                    {
                        /*SWS_DoIP_00013*/
                        (void) DoIP_TcpSendGenericHeaderNack (id, DOIP_GEN_HDR_NACK_UNKNOWN_PAYLOAD_TYPE); /* SWS_DoIP_00016 */
                        err = E_NOT_OK;
                        tpSessionPtr->SkipMsg = TRUE;
                    }
                    else
                    {
                        if (len > (uint32) DOIP_MAX_REQUEST_BYTES)
                        {
                            tpSessionPtr->SkipMsg = TRUE;
                            /*SWS_DoIP_00013*/
                            (void) DoIP_TcpSendGenericHeaderNack (id, DOIP_GEN_HDR_NACK_MSG_TOO_LARGE); /* SWS_DoIP_00017 */
                            err = E_NOT_OK;
                        }
                    }

                    /* Payload length is fixed for a specific payload type message */
                    if (err == E_OK)
                    {
                        if (type == DOIP_PAYLOAD_TYPE_DIAG_MSG)
                        {
                            /*SWS_DoIP_00122*/
                            if (len < (uint32) DOIP_DIAGDATA_LEAST_LENGTH)
                            {
                                err = E_NOT_OK;
                            }
                        }
                        else
                        {
                            err = DoIP_CheckPayloadLength (type, len);
                        }

                        if (E_OK != err)
                        {
                            /*SWS_DoIP_00013*/
                            (void) DoIP_TcpSendGenericHeaderNack (id, DOIP_GEN_HDR_NACK_INVALID_LEN); /* SWS_DoIP_00019 */
                            tcpMgmtPtr->SoConCloseStatus = DOIP_SOCON_CLOSE_REQ_PENDING;/*SWS_DoIP_00058*/
                            DOIP_TP_SESSION_CLR (tpSessionPtr);
                            rxPduInfo.SduLength = (PduLengthType) 0;
                            *bufferSizePtr = DOIP_GEN_HDR_LEN;
                        }
                        else
                        {
                            /* Only record the type when generic header info is all valid */
                            tpSessionPtr->PayloadType = type;
                        }
                    }

                }
                else
                {
                    /* SWS_DoIP_00013,SWS_DoIP_00014
                     * Send negative response with 1 byte NACK code and close the socket connection
                     */
                    (void) DoIP_TcpSendGenericHeaderNack (id, DOIP_GEN_HDR_NACK_INCORRECT_PATTERN);
                    tcpMgmtPtr->SoConCloseStatus = DOIP_SOCON_CLOSE_REQ_PENDING;/*SWS_DoIP_00058*/
                    DOIP_TP_SESSION_CLR (tpSessionPtr);
                    rxPduInfo.SduLength = (PduLengthType) 0;
                    *bufferSizePtr = DOIP_GEN_HDR_LEN;
                }
            }
            else
            {
                *bufferSizePtr = DOIP_DIAG_MSG_HDR_LEN;
            }
        }

        if ( (tpSessionPtr->Offset >= DOIP_GEN_HDR_LEN) && (tpSessionPtr->SkipMsg != TRUE) )
        {
            if (tpSessionPtr->PayloadType == DOIP_PAYLOAD_TYPE_DIAG_MSG)
            {
                bufReq = DoIP_DiagnosticMessageReceive (id, &rxPduInfo, bufferSizePtr);
            }
            else/* Routing active or alive check response */
            {
                /*SWS_DoIP_00214
                If the DoIP module has received sufficient data to evaluate the DoIP header and the payload type is not diagnostic message the DoIP shall
                copy all data of this DoIP message to the internal DoIP TCP buffer, lock the according buffer for other TCP connections and process the DoIP
                message*//*SWS_DoIP_00219*/
                err = DoIP_TcpWaitForData (id, &rxPduInfo, tpSessionPtr->TotalLen);

                if (E_OK == err)
                {
                    if (tpSessionPtr->PayloadType == DOIP_PAYLOAD_TYPE_ROUTING_ACTIVATION_REQ)
                    {
                        /* SWS_DoIP_00159 */
                        DoIP_RoutingActivationReqHandler (id, rxBufPtr);
                        tcpMgmtPtr->InactiveTimer = (uint32) 0;
                    }
                    else if (tpSessionPtr->PayloadType == DOIP_PAYLOAD_TYPE_ALIVE_CHECK_RES)
                    {
                        DoIP_AliveCheckResReceived (id, rxBufPtr);
                    }
#if(DOIP_HOZON_PLATFORM == DOIP_OEM_PLATFORM)
                    else if (tpSessionPtr->PayloadType == DOIP_PAYLOAD_TYPE_AUTH_RES_WITH_KEY)
                    {
                        DoIP_KeyReceived (id, rxBufPtr);
                        tcpMgmtPtr->InactiveTimer = (uint32) 0;
                    }
#endif            
                    else
                    {
                        /* should never be here */
                    }

                    DOIP_TP_SESSION_CLR (tpSessionPtr);
                    *bufferSizePtr = DOIP_GEN_HDR_LEN;
                }
                else
                {
                    *bufferSizePtr = tpSessionPtr->TotalLen - tpSessionPtr->Offset;
                }

            }
        }

        if (tpSessionPtr->SkipMsg == TRUE) /* Skip the invalid message */
        {
            if (rxPduInfo.SduLength >= (tpSessionPtr->TotalLen - tpSessionPtr->Offset) )
            {
                rxPduInfo.SduLength -= (tpSessionPtr->TotalLen - tpSessionPtr->Offset);
                rxPduInfo.SduDataPtr = (SduDataPtrType)(&rxPduInfo.SduDataPtr[tpSessionPtr->TotalLen - tpSessionPtr->Offset]);
                DOIP_TP_SESSION_CLR (tpSessionPtr);
                *bufferSizePtr = DOIP_GEN_HDR_LEN;
            }
            else
            {
                tpSessionPtr->Offset += rxPduInfo.SduLength;
                *bufferSizePtr = tpSessionPtr->TotalLen - tpSessionPtr->Offset;
                rxPduInfo.SduLength = (PduLengthType) 0;
            }
        }

    }

    return bufReq;
}

STATIC FUNC (Std_ReturnType, DOIP_CODE) DoIP_AliveCheckAllActivedTcpCon
(
    uint8 OwnerId
)
{
    uint8 i;
    Std_ReturnType retVal = E_NOT_OK;
    DoIP_TcpConMgmtType *tcpMgmtPtr;

    for (i = (uint8) 0; i < (uint8) DOIP_TCP_CON_NUM; i++)
    {
        tcpMgmtPtr = DOIP_TCP_CON_MGMT_PTR (i);

        if (tcpMgmtPtr->TesterId != DOIP_INVALID_TESTER_INDEX)
        {
            retVal = DoIP_AliveCheck (i);

            if (retVal == E_OK)
            {
                tcpMgmtPtr->OwnerId = OwnerId;
                DoIP_RoutActivMgmt[OwnerId].AliveCheckCount++;
            }
        }
    }

    return retVal;
}

STATIC FUNC (Std_ReturnType, DOIP_CODE) DoIP_AliveCheck
(
    PduIdType ConId
)
{
    DoIP_GenHdrType aliveCheckMsg;
    PduInfoType pdu;
    Std_ReturnType retVal;

    /*SWS_DoIP_00139, no payload data*/
    pdu.SduLength = DOIP_ALIVECHECK_REQUEST_LENGTH;
    pdu.SduDataPtr = (SduDataPtrType) &aliveCheckMsg;
    /*SWS_DoIP_00009, SWS_DoIP_00139*/
    retVal = DoIP_TcpRequestTransmit (ConId, DOIP_INVALID_PDUID, &pdu, DOIP_PAYLOAD_TYPE_ALIVE_CHECK_REQ);

    if (E_OK == retVal)
    {
        DoIP_TcpConMgmt[ConId].AliveCheckPerformed = TRUE;
        DoIP_TcpConMgmt[ConId].AliveCheckTimer = (uint32) 0;
    }

    return retVal;
}

STATIC FUNC (void, DOIP_PRVATE_CODE) DoIP_RoutingActivationReqHandler
(
    uint8 ConId,
    const uint8 *MsgBufPtr
)
{
    Std_ReturnType retVal;
    DoIP_LogicAddrType sa;
    PduInfoType txPdu;
    DoIP_RoutActivResType resData;
    DoIP_TcpConMgmtType *tcpMgmtPtr;
    DoIP_RoutActivMgmtType *routActiv;
    uint8 tcpconIndex, testerIndex, tcpconNumber, routActivId;
    uint8 resCode;
    uint8 i;
    uint32 len;
    uint8 routActivAuthReqLen, routActivConfReqLen;
    boolean generalErr = FALSE;

    tcpMgmtPtr = DOIP_TCP_CON_MGMT_PTR (ConId);
    resCode = DOIP_ROUTING_ACTIVATION_RES_CODE_INVALID_VALUE;
    routActiv = DOIP_ROUT_ACTIV_MGMT_PTR (ConId);
    len = DOIP_U32 ( ( (const DoIP_RoutActivReqMsgType *) MsgBufPtr)->Hdr.Length );
    sa = DOIP_U16 ( ( (const DoIP_RoutActivReqMsgType *) MsgBufPtr)->SA); /* Get logic address which tester request to be registed */

    /* SWS_DoIP_00102 */
    retVal = DoIP_GetTesterId (sa, &testerIndex);/* Check tester index is invalid or not */

    if (E_OK == retVal)
    {
        /* SWS_DoIP_00108 */
        retVal = DoIP_GetTesterRoutActivId (testerIndex, ( (const DoIP_RoutActivReqMsgType *) MsgBufPtr)->ActionType, &routActivId);

        if (retVal == E_NOT_OK)
        {
            /* Action type is not supportted  SWS_DoIP_00160*/
            resCode = DOIP_ROUTING_ACTIVATION_RES_CODE_ACTION_TYPE_UNSUPPORTTED;
            tcpMgmtPtr->SoConCloseStatus = DOIP_SOCON_CLOSE_REQ_PENDING;/*SWS_DoIP_00058*/
        }
    }
    else/* SWS_DoIP_00104 : It's a unknown SA */
    {
        /* set response code 0x00 and close the socket connection */
        resCode = DOIP_ROUTING_ACTIVATION_RES_CODE_UNKNOWN_SA;
        tcpMgmtPtr->SoConCloseStatus = DOIP_SOCON_CLOSE_REQ_PENDING;/*SWS_DoIP_00058*/
    }

    /*The SA and ActionType are valid*/
    if (E_OK == retVal)
    {
        /* SWS_DoIP_00106 */ /*The connection this Routing activation was received on is already registered to another source address */
        if ( (tcpMgmtPtr->TesterId != DOIP_INVALID_TESTER_INDEX) && (tcpMgmtPtr->TesterId != testerIndex) )
        {
            resCode = DOIP_ROUTING_ACTIVATION_RES_CODE_SA_DIFF;
            tcpMgmtPtr->SoConCloseStatus = DOIP_SOCON_CLOSE_REQ_PENDING;/*SWS_DoIP_00058*/
            retVal = E_NOT_OK;
        }
        /* SWS_DoIP_00103 Same SA is registed with this connection, or this connection has not been registed */
        else
        {
            /* Store routing activation request parameters for futher process */
            routActiv->ReqParam.TesterId = testerIndex;
            routActiv->ReqParam.ActionType = ( (const DoIP_RoutActivReqMsgType *) MsgBufPtr)->ActionType;
            routActiv->ReqParam.SA = sa;
            routActiv->ReqParam.RoutActivId = routActivId;
            routActivAuthReqLen = DOIP_GET_ROUT_ACTIV_AUTH_REQ_LEN (routActivId);
            routActivConfReqLen = DOIP_GET_ROUT_ACTIV_CONFIRM_REQ_LEN (routActivId);

            /*should judge whether there is OemResv*/
            if ( (routActivAuthReqLen > (uint8) 0) || (routActivConfReqLen > (uint8) 0) )
            {
                if (len == (uint32) DOIP_ROUTACTIVE_REQ_OEMRESV_LENGTH)
                {
                    Bsw_MemCpy (&routActiv->ReqParam.OemResv[0], & ( (const DoIP_RoutActivReqMsgType *) MsgBufPtr)->OemResv[0], (uint32) DOIP_REVE_LENGTH);
                }
                else
                {
                    /*the requested length is incorrect*/
                    retVal = E_NOT_OK;
                    generalErr = TRUE;
                }

            }
            else /*no OemResv*/
            {
                if (len != (uint32) DOIP_ROUTACTIVE_REQ_NOOEMRESV_LENGTH)
                {
                    /*the requested length is incorrect*/
                    retVal = E_NOT_OK;
                    generalErr = TRUE;
                }
                else
                {
                    /* do nothing */
                }

            }

            if (E_OK == retVal)
            {
                /* check all the tcp connection */
                retVal = DoIP_TcpGetConIdByTesterSA (sa, &tcpconIndex );

                /* SA(tester) has been registed with TCP connection */
                if (E_OK == retVal)
                {
                    /* SWS_DoIP_00105 *//* SA(tester) has been registed with other TCP connection */
                    if (tcpconIndex != ConId)
                    {
                        /* Send a alive check to this connection and wait the response */
                        retVal = DoIP_AliveCheck (tcpconIndex);

                        if (E_OK == retVal)
                        {
                            routActiv->Status = DOIP_ROUTING_ACTIVATION_ALIVE_CHECK;
                            routActiv->AliveCheckCount = (uint8) 1;
                            routActiv->AliveCheckOnlyOne = TRUE;
                            DoIP_TcpConMgmt[tcpconIndex].OwnerId = ConId;
                        }
                        else
                        {
                            /*go to process*/
                        }
                    }
                    else/* SA(tester) has been registed with this TCP connection */
                    {
                        routActiv->Status = DOIP_ROUTING_ACTIVATION_AUTH_PENDING;
                        tcpMgmtPtr->TesterId = testerIndex;
                    }
                }
                /*this connection has not been registed*/
                else
                {
                    retVal = E_OK;
                    tcpconNumber = DoIP_TcpGetCurrentTesterConNum();

                    /* SWS_DoIP_00107 */
                    if (tcpconNumber >= DOIP_MAX_TESTER_CONNECTION_NUM)
                    {
                        /* Send alive check to all registed tester */
                        retVal = DoIP_AliveCheckAllActivedTcpCon (ConId);

                        if (E_OK == retVal)
                        {
                            routActiv->Status = DOIP_ROUTING_ACTIVATION_ALIVE_CHECK;
                        }
                        else
                        {
                            /*go to process*/
                        }
                    }
                    else
                    {
                        routActiv->Status = DOIP_ROUTING_ACTIVATION_AUTH_PENDING;
                        tcpMgmtPtr->TesterId = testerIndex;
                    }
                }
            }
        }
    }

    if (E_OK != retVal)
    {
        if (generalErr != TRUE)
        {
            /*SWS_DoIP_00116*/
            DOIP_U16TOBUF (resData.SA, sa);
            /*SWS_DoIP_00118*/
            DOIP_U16TOBUF (resData.TA, DOIP_GET_LOCAL_ADDR() );
            /*SWS_DoIP_00119*/
            resData.ResCode = resCode;
            
            if(len <= (uint32)DOIP_ROUTACTIVE_REQ_OEMRESV_LENGTH)
            {
                /* OEM Reserve NOT Configured */
                txPdu.SduLength = DOIP_ROUTACTIVE_RESPONSE_NOOEMRESV_LENGTH;
                for (i = (uint8) 0; i < DOIP_REVE_LENGTH; i++)
                {
                    resData.Resv[i] = (uint8)0;
                }
            }
            else
            {
                /* OEM Reserve Configured */
                txPdu.SduLength = DOIP_ROUTACTIVE_RESPONSE_LENGTH;

                for (i = (uint8) 0; i < DOIP_REVE_LENGTH; i++)
                {
                    resData.Resv[i] = (uint8)0;
                    resData.OemResv[i] = DOIP_ROUTING_ACTIVATION_RES_OEM_RESERVED;
                }
            }

            txPdu.SduDataPtr = (SduDataPtrType) &resData;
            /*SWS_DoIP_00009*/
            retVal = DoIP_TcpRequestTransmit (ConId, DOIP_INVALID_PDUID, &txPdu, DOIP_PAYLOAD_TYPE_ROUTING_ACTIVATION_RES);
        }
        else
        {
            /*SWS_DoIP_00013*/
            (void) DoIP_TcpSendGenericHeaderNack (ConId, DOIP_GEN_HDR_NACK_INVALID_LEN); /* SWS_DoIP_00019 */
            tcpMgmtPtr->SoConCloseStatus = DOIP_SOCON_CLOSE_REQ_PENDING;/*SWS_DoIP_00058*/
        }

    }
}

/*input id: tcpconnection id*/
STATIC FUNC (BufReq_ReturnType, DOIP_CODE) DoIP_QueryTxAvailableDataLen

(
    PduIdType id,
    const PduInfoType *info,
    RetryInfoType *retry,
    PduLengthType *AvailableDataPtr
)
{
    BufReq_ReturnType bufReq;
    DoIP_PduType type;
    PduIdType pdurTxPduId;
    DoIP_TpSessionType *tpSessionPtr;

    bufReq = BUFREQ_OK;
    tpSessionPtr = DOIP_TCP_CON_MGMT_TX_SESSION_PTR (id);    

    if (tpSessionPtr->PayloadType == DOIP_PAYLOAD_TYPE_DIAG_MSG) 
    {
        type = DOIP_GET_CHANNEL_PDU_TYPE (tpSessionPtr->ChannelId);

        if (type == DOIP_TPPDU) 
        {
            pdurTxPduId = DOIP_GET_CHANNEL_PDUR_TX_PDUID (tpSessionPtr->ChannelId);
            /* For TP-PDU, Payload data is kept by upper layer module, forward to PduR directly */
            bufReq = DOIP_CALL_UL_DOIP_TP_COPY_TX_DATA (pdurTxPduId, info, retry, AvailableDataPtr);

            if ( (BUFREQ_OK == bufReq) && (tpSessionPtr->Offset < DOIP_DIAG_MSG_HDR_LEN) )
            {
                /* DoIP module keep the diagnostic message header internally */
                *AvailableDataPtr += (DOIP_DIAG_MSG_HDR_LEN - tpSessionPtr->Offset);
            }
        }
        else /* IF-PDU and Diagnostic message, all data is kept in internal buffer */
        {
            *AvailableDataPtr = tpSessionPtr->TotalLen - tpSessionPtr->Offset;
        }                
    }
    else/*Non-Diagnostic message, all data is kept in internal buffer */
    {
        *AvailableDataPtr = tpSessionPtr->TotalLen - tpSessionPtr->Offset;
    }

    return bufReq;
}
STATIC void DoIP_MainFunctionTcp (void)
{
    DoIP_TcpConMgmtType *tcpMgmtPtr;
    uint8 conId;
    Std_ReturnType retVal;
    SoAd_SoConIdType soconId;

    for (conId = (uint8) 0; conId < (uint8) DOIP_TCP_CON_NUM; conId++)
    {
        tcpMgmtPtr = DOIP_TCP_CON_MGMT_PTR (conId);

        if (tcpMgmtPtr->SoConMode == SOAD_SOCON_ONLINE)
        {
            /*SWS_DoIP_00143*/
            tcpMgmtPtr->InactiveTimer += (uint32)DOIP_MAINFUNCTION_PERIOD;/*SWS_DoIP_00043*/

            if (DoIP_RoutActivMgmt[conId].Status == DOIP_ROUTING_ACTIVATION_REQ_NONE)
            {
                if (tcpMgmtPtr->InactiveTimer > (uint32)DOIP_INITIAL_INACTIVE_TIMEOUT)
                {
                    /* SWS_DoIP_00058 *//*SWS_DoIP_00144*/
                    tcpMgmtPtr->SoConCloseStatus = DOIP_SOCON_CLOSE_REQ_PENDING;
                    tcpMgmtPtr->InactiveTimer = (uint32) 0;
                }
            }
            else if (DoIP_RoutActivMgmt[conId].Status == DOIP_ROUTING_ACTIVATION_ACTIVED)
            {
                if (tcpMgmtPtr->InactiveTimer > DOIP_GEN_INACTIVE_TIMEOUT) /* Inactive timer timeout */
                {
                    /* SWS_DoIP_00058 *//* SWS_DoIP_00146 */
                    tcpMgmtPtr->SoConCloseStatus = DOIP_SOCON_CLOSE_REQ_PENDING;
                    tcpMgmtPtr->InactiveTimer = (uint32) 0;
                }
                else
                {
                    DoIP_TcpTxReqHandler (conId);
                }
            }
            else
            {
                /* Routing activation is under processing */
                (void) DoIP_TryRoutingActivation (conId);
            }

            /* Alive check handler, SWS_DoIP_00140*/
            if (DoIP_TcpConMgmt[conId].AliveCheckPerformed == TRUE)
            {
                DoIP_TcpConMgmt[conId].AliveCheckTimer += (uint32)DOIP_MAINFUNCTION_PERIOD;/*SWS_DoIP_00043*/

                if (DoIP_TcpConMgmt[conId].AliveCheckTimer > (uint32)DOIP_ALIVE_CHECK_RES_TIMEOUT)
                {
                    DoIP_TcpConMgmt[conId].AliveCheckTimer = (uint32) 0;
                    /*SWS_DoIP_00107*/
                    tcpMgmtPtr->SoConCloseStatus = DOIP_SOCON_CLOSE_REQ_PENDING;/*SWS_DoIP_00058*/
                    (void) DoIP_AliveCheckResTimeOutIndication (DoIP_TcpConMgmt[conId].OwnerId);
                }
            }

            /*protect*/
            DOIP_ENTER_CRITICAL_SECTION_SOCONSTATUS() ;

            /* Close the tcp connection if there is a pending request */
            if ( (tcpMgmtPtr->SoConCloseStatus == DOIP_SOCON_CLOSE_REQ_PENDING)
                    && (tcpMgmtPtr->TxSes.TotalLen == (PduLengthType) 0) )
            {
                /*SWS_DoIP_00058*/
                soconId = DOIP_GET_TCPCON_SOAD_SOCONID (conId);
                retVal = SoAd_CloseSoCon (soconId, TRUE);

                if (E_OK == retVal)
                {
                    tcpMgmtPtr->SoConCloseStatus = DOIP_SOCON_CLOSE_REQ_PROCESSING;
                }
            }

            /*unprotect*/
            DOIP_LEAVE_CRITICAL_SECTION_SOCONSTATUS();
        }
    }
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DoIP_ActivationLineStatusHandler
*
* Description:   Handling IP Address assignment and sockets switches based on
*                activation line status.
*
* Inputs:        None
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC (void, DOIP_CODE) DoIP_ActivationLineStatusHandler
(
    void
)
{
    SoAd_SoConIdType soconId;
    PduIdType udpConId;
    Std_ReturnType retVal;

    if (DoIP_ActivationLineSwitchAction == (uint8) DOIP_ACTIVATION_LINE_SWITCH_INACTIVE2ACTIVE)
    {
        /* SWS_DoIP_00204 */
        soconId = DOIP_GET_UDPCON_SOAD_SOCONID (0);
        (void) SoAd_RequestIpAddrAssignment (soconId, TCPIP_IPADDR_ASSIGNMENT_LINKLOCAL_DOIP, NULL_PTR, (uint8) 0, NULL_PTR);

        (void) SoAd_RequestIpAddrAssignment (soconId, TCPIP_IPADDR_ASSIGNMENT_DHCP, NULL_PTR, (uint8) 0, NULL_PTR);

        DoIP_ActivationLineSwitchAction = (uint8) DOIP_ACTIVATION_LINE_SWITCH_NONE;
    }
    else if (DoIP_ActivationLineSwitchAction == (uint8) DOIP_ACTIVATION_LINE_SWITCH_ACTIVE2INACTIVE)
    {
        DoIP_ActivationLineSwitchAction = (uint8) DOIP_ACTIVATION_LINE_SWITCH_NONE;

        /* SWS_DoIP_00234 */
        for (udpConId = (uint8) 0; udpConId < (uint8) DOIP_UDP_CON_NUM; udpConId++)
        {
            if ( (DoIP_UdpConMgmt[udpConId].SoConCloseStatus == DOIP_SOCON_CLOSE_REQ_NONE) && ( DoIP_UdpConMgmt[udpConId].SoConMode != SOAD_SOCON_OFFLINE) )
            {
                /* SWS_DoIP_00058 */
                soconId = DOIP_GET_UDPCON_SOAD_SOCONID (udpConId);
                retVal = SoAd_CloseSoCon (soconId, TRUE);

                if (E_OK == retVal)
                {
                    DoIP_UdpConMgmt[udpConId].SoConCloseStatus = DOIP_SOCON_CLOSE_REQ_PROCESSING;
                }
                else
                {
                    /* Not all udp connection request close successfully, continue next loop */
                    DoIP_ActivationLineSwitchAction = (uint8) DOIP_ACTIVATION_LINE_SWITCH_ACTIVE2INACTIVE;
                }
            }
        }


    }
    else
    {
        /* Do nothing */
    }
}

STATIC FUNC (BufReq_ReturnType, DOIP_CODE) DoIP_CopyTpTxData
(
    PduIdType id,
    const PduInfoType *info,
    RetryInfoType *retry,
    PduLengthType *AvailableDataPtr
)
{
    PduIdType pdurTxPduId;
    DoIP_TpSessionType *tpSessionPtr;
    BufReq_ReturnType bufReq = BUFREQ_OK;
    DoIP_DiagMsgHdrType diagMsgHdr;
    uint8 *buf;
    PduLengthType copy = (PduLengthType) 0;
    PduInfoType remain;
    RetryInfoType upRetry;

    tpSessionPtr = DOIP_TCP_CON_MGMT_TX_SESSION_PTR (id);
    pdurTxPduId = DOIP_GET_CHANNEL_PDUR_TX_PDUID (tpSessionPtr->ChannelId);

    /* Diagnostic message header has not been copied completely */
    if (tpSessionPtr->Offset < DOIP_DIAG_MSG_HDR_LEN)
    {
        /* Constructe diagnostic message header here
         *
         * |----------------Generic header----------------------------| Diagnostic specific infomation       |
         * | VERSION | INVERSE_VERSION |PAYLOAD_TYPE | PAYLOAD_LENGTH | Destination Address | Source Address |
         */
        /*if retry->TpDataState == TP_DATARETRY, the following will be done repeatedly.*/
        DoIP_GenericHeaderConstruct ( (uint8 *) &diagMsgHdr, DOIP_PAYLOAD_TYPE_DIAG_MSG, ( (uint32) tpSessionPtr->TotalLen - (uint32) DOIP_GEN_HDR_LEN) );

        DOIP_U16TOBUF (diagMsgHdr.SA, DOIP_GET_LOCAL_ADDR() );
        DOIP_U16TOBUF (diagMsgHdr.TA, DOIP_GET_CHANNEL_SA (tpSessionPtr->ChannelId) );

        /* Copy message header from local buffer */
        buf = (uint8 *) &diagMsgHdr;
        copy = (PduLengthType)(DoIP_GetMinValue ( (DOIP_DIAG_MSG_HDR_LEN - tpSessionPtr->Offset), info->SduLength ));
        Bsw_MemCpy (info->SduDataPtr, & (buf[tpSessionPtr->Offset]), (uint32) copy);
        tpSessionPtr->Offset += copy;

        /* SWS_DoIP_00232 */
        if (info->SduLength > copy) /* SoAd wants more data, Copy data from PduR */
        {
            remain.SduDataPtr = (SduDataPtrType)(&info->SduDataPtr[copy]);
            remain.SduLength = info->SduLength - copy;

            if ( (retry != NULL_PTR) && (retry->TpDataState == TP_DATARETRY) )
            {
                if (retry->TxTpDataCnt > copy)
                {
                    upRetry.TxTpDataCnt = retry->TxTpDataCnt - copy;
                    upRetry.TpDataState = retry->TpDataState;
                }
                else
                {
                    upRetry.TpDataState = TP_DATACONF;
                    upRetry.TxTpDataCnt = (PduLengthType) 0;
                }

                /*SWS_DoIP_00173*//*SWS_DoIP_00254*/
                bufReq = DOIP_CALL_UL_DOIP_TP_COPY_TX_DATA (pdurTxPduId, &remain, &upRetry, AvailableDataPtr);
            }
            else/* no roll back*/
            {
                /*SWS_DoIP_00173*//*SWS_DoIP_00254*/
                bufReq = DOIP_CALL_UL_DOIP_TP_COPY_TX_DATA (pdurTxPduId, &remain, retry, AvailableDataPtr);
            }

            if (BUFREQ_OK == bufReq)
            {
                tpSessionPtr->Offset += remain.SduLength;
            }
            else
            {
                /* Do Nothing. SoAd will close socket connection */
            }
        }
    }
    else
    {
        /* Diagnostic header is copied completely, call PduR directly */ /*SWS_DoIP_00173*//*SWS_DoIP_00254*/
        bufReq = DOIP_CALL_UL_DOIP_TP_COPY_TX_DATA (pdurTxPduId, info, retry, AvailableDataPtr);

        if (BUFREQ_OK == bufReq)
        {
            tpSessionPtr->Offset += info->SduLength;
        }
        else
        {
            /* Do Nothing. SoAd will close socket connection */
        }
    }

    return bufReq;
}

STATIC FUNC (BufReq_ReturnType, DOIP_CODE) DoIP_CopyNonTpTxData
(
    PduIdType id,
    const PduInfoType *info,
    PduLengthType *AvailableDataPtr
)
{
    BufReq_ReturnType bufReq;
    uint8 *buf;
    PduLengthType copy = (uint16) 0;
    DoIP_TpSessionType *tpSessionPtr;
    uint16 bufId;
	
    tpSessionPtr = DOIP_TCP_CON_MGMT_TX_SESSION_PTR (id);
    /*copy is avaliable data length*/
    copy = tpSessionPtr->TotalLen - tpSessionPtr->Offset;

    if (copy >= info->SduLength)
    {
        if ( (tpSessionPtr->PayloadType == DOIP_PAYLOAD_TYPE_DIAG_MSG)
                && (DOIP_GET_CHANNEL_PDU_TYPE (tpSessionPtr->ChannelId) == DOIP_IFPDU) )
        {
            bufId = DOIP_GET_CHANNEL_IFPDU_BUFID (tpSessionPtr->ChannelId);
            buf = DOIP_TCP_TX_IFPDU_BUF_PTR (bufId);
        }
        else
        {
            buf = DOIP_TCP_CON_MGMT_SEND_BUF_PTR (id);
        }

        /*SWS_DoIP_00225*/
        Bsw_MemCpy (info->SduDataPtr, &buf[tpSessionPtr->Offset], (uint32) info->SduLength);
        tpSessionPtr->Offset += info->SduLength;
        *AvailableDataPtr = tpSessionPtr->TotalLen - tpSessionPtr->Offset;

        bufReq = BUFREQ_OK;
    }
    else/* Less data left than SoAd expected */
    {
        /*SoAd will close socket connection*/
        bufReq = BUFREQ_E_BUSY;
    }

    return bufReq;
}

STATIC FUNC (uint16, DOIP_CODE) DoIP_GetAnnounceIntialTimer
(
    void
)
{
    return DoIP_RandomNum;
}

STATIC FUNC (void, DOIP_CODE) DoIP_IncreaseRandomNum
(
    void
)
{
    DoIP_RandomNum++;
    if(DoIP_RandomNum > DOIP_INCREASERANDOMMAXNUM)
    {
        DoIP_RandomNum = (uint16)0;
    }
}

#if(DOIP_HOZON_PLATFORM == DOIP_OEM_PLATFORM)
STATIC FUNC (Std_ReturnType, DOIP_CODE) DoIP_SendAuthRespWithSeed
(
    PduIdType ConId,
    uint8* SA,
    uint8* TA
)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 Seed[DOIP_PAYLOAD_TYPE_AUTH_SEED_LENGTH];
    DoIP_RoutActivAUTHResType resData;
    PduInfoType TxPdu;

    DOIP_GET_SEED(resData.seed, DOIP_PAYLOAD_TYPE_AUTH_SEED_LENGTH);
    
    resData.SA[0] = TA[0];
    resData.SA[1] = TA[1];
    resData.TA[0] = SA[0];
    resData.TA[1] = SA[1];

    TxPdu.SduLength = (PduLengthType)(DOIP_PAYLOAD_TYPE_AUTH_SEED_LENGTH + 4);
    TxPdu.SduDataPtr = (SduDataPtrType)&resData;

    ret = DoIP_TcpRequestTransmit (ConId, DOIP_INVALID_PDUID, &TxPdu, DOIP_PAYLOAD_TYPE_AUTH_RES_WITH_SEED);

    return ret;
}

STATIC FUNC (void, DOIP_CODE) DoIP_KeyReceived
(
    PduIdType ConId,
    uint8 *RxBuffer
)
{
    DoIP_RoutActivMgmtType *routActiveMgmtPtr = DOIP_ROUT_ACTIV_MGMT_PTR(ConId);
    uint8 *key_received = (RxBuffer + 12);

    if(routActiveMgmtPtr->Status == DOIP_ROUTING_ACTIVATION_WAIT_KEY)
    {
        if(E_OK != DOIP_VALIDATE_KEY (key_received, DOIP_PAYLOAD_TYPE_AUTH_KEY_LENGTH))
        {
            /*clear the tester id setted when routing activation requested is acceptted */
            DoIP_TcpConMgmt[ConId].TesterId = DOIP_INVALID_TESTER_INDEX;
            /* SWS_DoIP_00111 */
            routActiveMgmtPtr->Status = DOIP_ROUTING_ACTIVATION_REQ_NONE;
        }
        else
        {
        	routActiveMgmtPtr->Status = DOIP_ROUTING_ACTIVATION_KEY_RECEIVED;
        }
    }
    else
    {
        /* Invalid status, ignore message */
    }
}
#endif
/******************************************************************************
 * Public Functions
 ******************************************************************************/

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DoIP_Init
*
* Description:   Initialize DoIP module
*
* Inputs:        DoIPConfigPtr: DoIP configuration set
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
/* PRQA S 3206 ++ */
/*No use DoIPConfigPtr*/
FUNC (void, DOIP_CODE) DoIP_Init
(
    P2CONST (DoIP_ConfigType, AUTOMATIC, DOIP_CONST) DoIPConfigPtr
)
{
    uint8 i, j;

#if (DOIP_CONFIG_VARIANTS == STD_CONFIG_VARIANTS_POSTBUILD)

    if (NULL_PTR != DoIPConfigPtr)
    {
        DoIP_ConfigPtr = (DoIP_ConfigType *) DoIPConfigPtr;
    }
    else
    {
        DOIP_DET_REPORT_ERROR (DOIP_API_ID_INIT, DOIP_E_PARAM_POINTER);
    }

#else
    DoIP_ConfigPtr = &DoIP_Config;
#endif

    if (STD_INITIALIZED != DoIP_InitState)
    {
        DoIP_ActivationLineStatus = DOIP_ACTIVATION_LINE_INACTIVE;
        DoIP_ActivationLineSwitchAction = (uint8) DOIP_ACTIVATION_LINE_SWITCH_NONE;

        DoIP_GidSyncStatus = DOIP_GID_SYNC_STATE_IDLE;

        for (i = (uint8) 0; i < (uint8) DOIP_TCP_CON_NUM; i++)
        {
            /* Tcp connection management */
            DoIP_TcpConMgmt[i].SoConMode = SOAD_SOCON_OFFLINE;
            DoIP_TcpConMgmt[i].SoConCloseStatus = DOIP_SOCON_CLOSE_REQ_NONE;
            DoIP_TcpConMgmt[i].TesterId = DOIP_INVALID_ID;
            DoIP_TcpConMgmt[i].InactiveTimer = (uint32) 0;
            DOIP_TP_SESSION_CLR (&DoIP_TcpConMgmt[i].TxSes);
            DOIP_TP_SESSION_CLR (&DoIP_TcpConMgmt[i].RxSes);
            Bsw_MemSet (DoIP_TcpConMgmt[i].SendBuf, (uint8) 0, (uint32) DOIP_TCP_CON_BUF_SIZE);
            Bsw_MemSet (DoIP_TcpConMgmt[i].RecvBuf, (uint8) 0, (uint32) DOIP_TCP_CON_BUF_SIZE);
            DOIP_TCP_CON_MGMT_SEND_BUF_OFFSET(i) = (uint16)0;

            /* Routing activation management */
            DoIP_TcpConMgmt[i].AliveCheckPerformed = FALSE;
            DoIP_TcpConMgmt[i].AliveCheckTimer = (uint32) 0;
            DoIP_TcpConMgmt[i].OwnerId = DOIP_INVALID_ID;
            DoIP_RoutActivMgmt[i].Status = DOIP_ROUTING_ACTIVATION_REQ_NONE;
            /*ReqParam  Request parameter*/
            DoIP_RoutActivMgmt[i].ReqParam.ActionType = (uint8) DOIP_ACTIONTYPE_INVALID;
            Bsw_MemSet (DoIP_RoutActivMgmt[i].ReqParam.OemResv, (uint8) 0, (uint32) DOIP_REVE_LENGTH);
            DoIP_RoutActivMgmt[i].ReqParam.RoutActivId = DOIP_INVALID_ID;
            DoIP_RoutActivMgmt[i].ReqParam.SA = DOIP_INVALID_LOGIC_ADDR;
            DoIP_RoutActivMgmt[i].ReqParam.TesterId = DOIP_INVALID_ID;
            DoIP_RoutActivMgmt[i].AliveCheckCount = (uint8) 0;
            DoIP_RoutActivMgmt[i].AliveCheckOnlyOne = FALSE;
            /* TP transmit list */
            DoIP_TpTxListInit (&DoIP_TpTxList[i]);
        }

        for (i = (uint8) 0; i < (uint8) DOIP_UDP_CON_NUM; i++)
        {
            DoIP_UdpConMgmt[i].SoConMode = SOAD_SOCON_OFFLINE;
            DoIP_UdpConMgmt[i].SoConCloseStatus = DOIP_SOCON_CLOSE_REQ_NONE;

            DoIP_UdpConMgmt[i].RemoteAddr.Domain = DOIP_TCPIP_AF_INET;
            DoIP_UdpConMgmt[i].RemoteAddr.Port = TCPIP_PORT_ANY;
            DoIP_UdpConMgmt[i].RemoteAddr.Addr[0] = (uint32) TCPIP_IPADDR_ANY;
            DoIP_UdpConMgmt[i].ReqCount = (uint8) 0;
            DoIP_UdpConMgmt[i].QIn = (uint8) 0;
            DoIP_UdpConMgmt[i].QOut = (uint8) 0;
            DoIP_UdpConMgmt[i].VehicleIdentificationRequest_0001_flag = (uint8) 0;
            DoIP_UdpConMgmt[i].ReqCount_OutOfMemory_flag = (uint8) 0;

            DoIP_UdpConMgmt[i].VehicleAnnouncementCount = (uint8) 0;
            DoIP_UdpConMgmt[i].AnnounceTimer = (uint32) 0;

            for (j = (uint8) 0; j < (DOIP_MAX_UDP_REQ_PER_MESSAGE + (uint8) 1); j++)
            {
                DoIP_UdpConMgmt[i].ReqQ[j].PayloadType = DOIP_INVALID_PAYLOAD_TYPE;
                Bsw_MemSet (DoIP_UdpConMgmt[i].ReqQ[j].Param, (uint8) 0, (uint32) DOIP_UDP_REQ_MAX_PARAM_LEN);

            }
        }

        for (i = (uint8) 0; i < DOIP_CHANNEL_NUM; i++)
        {
            DoIP_ChannelCtrl[i].RoutingActived = FALSE;
            DoIP_ChannelCtrl[i].TcpConId = DOIP_INVALID_ID;
        }

#if(DOIP_TCP_TX_IF_PDU_BUF_NUM > 0)

        for (i = (uint8) 0; i < (uint8) DOIP_TCP_TX_IF_PDU_BUF_NUM; i++)
        {
            Bsw_MemSet (&DoIP_TcpTxIfPduBuf[i][0], (uint8) 0, (uint32) DOIP_TCP_CON_BUF_SIZE);
        }

#endif       

        DoIP_InitState = STD_INITIALIZED;
    }
}
/* PRQA S 3206 -- */

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DoIP_GetVersionInfo
*
* Description:   This service is called to request version infomation.
* Inputs:        None.
*
* Outputs:       versioninfo: DoIP module version.
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
#if(DOIP_VERSION_INFO_API == STD_ON)
FUNC (void, DOIP_CODE) DoIP_GetVersionInfo
(
    Std_VersionInfoType *versioninfo
)
{
    if (versioninfo != NULL_PTR)
    {
        versioninfo->sw_major_version = (uint8) DOIP_SW_MAJOR_VERSION;
        versioninfo->sw_minor_version = (uint8) DOIP_SW_MINOR_VERSION;
        versioninfo->sw_patch_version = (uint8) DOIP_SW_PATCH_VERSION;
        versioninfo->moduleID = DOIP_MODULE_ID;
        versioninfo->vendorID = DOIP_VENDOR_ID;
    }
    else
    {
        /*SWS_DoIP_00172*/
        DOIP_DET_REPORT_ERROR (DOIP_API_ID_GET_VERSION_INFO, DOIP_E_PARAM_POINTER);
    }

}
#endif

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DoIP_TpTransmit
*
* Description:   This service is called to request the transfer data from the
*                PduRouter to the SoAd.
* Inputs:        DoIPPduRTxId: DoIP unique identifier of the PDU to be transmitted
*                by the PduR
*                DoIPPduRTxInfoPtr: Tx Pdu information structure which contains
*                                   the length of the DoIPTxMessage.
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC (Std_ReturnType, DOIP_CODE) DoIP_TpTransmit
(
    PduIdType DoIPPduRTxId,
    const PduInfoType *DoIPPduRTxInfoPtr
)
{
    Std_ReturnType retVal;/* SWS_DoIP_00226 */
    PduIdType conId;

    retVal = E_NOT_OK;
    conId = DoIP_ChannelCtrl[DoIPPduRTxId].TcpConId;

    if (STD_INITIALIZED != DoIP_InitState) /* SWS_DoIP_00162 */
    {
        DOIP_DET_REPORT_ERROR (DOIP_API_ID_TP_TRANSMIT, DOIP_E_UNINIT);
    }
    else if (DoIPPduRTxId >= DOIP_CHANNEL_NUM) /* SWS_DoIP_00163 */
    {
        DOIP_DET_REPORT_ERROR (DOIP_API_ID_TP_TRANSMIT, DOIP_E_INVALID_PDU_SDU_ID);
    }
    else if (DoIPPduRTxInfoPtr == NULL_PTR) /* SWS_DoIP_00164 */
    {
        DOIP_DET_REPORT_ERROR (DOIP_API_ID_TP_TRANSMIT, DOIP_E_PARAM_POINTER);
    }
    else if(conId == DOIP_INVALID_PDUID)
    {
        /*SoCon had been closed*/
    }
    else if ( (DOIP_ACTIVATION_LINE_ACTIVE == DoIP_ActivationLineStatus ) /* SWS_DoIP_00202 */
              && (DoIPPduRTxInfoPtr->SduLength > (uint16)0)
              && (DOIP_GET_CHANNEL_PDU_TYPE (DoIPPduRTxId) == DOIP_TPPDU) /* Only TP-PDU can be sent by DoIP_TpTransmit */
              && (DoIP_TcpConMgmt[conId].SoConMode == SOAD_SOCON_ONLINE) ) /*SWS_DoIP_00130*/
    {
        /*SWS_DoIP_00230*/
        retVal = DoIP_TcpRequestTransmit (conId, DoIPPduRTxId, DoIPPduRTxInfoPtr, DOIP_PAYLOAD_TYPE_DIAG_MSG);
    }
    else
    {
        /* do nothing */
    }

    return retVal;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DoIP_TpCancelTransmit
*
* Description:   This service primitive is used to cancel the transfer of pending
*                DoIPPduRTxIds. The connection is identified by DoIPPduRTxId.
* Inputs:        DoIPPduRTxId: DoIP unique identifier of the PDU to be canceled by
*                          the PduR.
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC (Std_ReturnType, DOIP_CODE) DoIP_TpCancelTransmit
(
    PduIdType DoIPPduRTxId
)
{
    DoIP_TpSessionType *tpSessionPtr;
    DoIP_TpTxListType *list;
    Std_ReturnType retVal;
    PduIdType soadTxPduId;
    PduIdType conId;
    boolean inlist;

    retVal = E_NOT_OK;

    if (STD_INITIALIZED != DoIP_InitState) /* SWS_DoIP_00166 */
    {
        /*SWS_DoIP_00045*/
        DOIP_DET_REPORT_ERROR (DOIP_API_ID_TP_CANCEL_TRANSMIT, DOIP_E_UNINIT);
    }
    else if (DoIPPduRTxId >= DOIP_CHANNEL_NUM) /* SWS_DoIP_00167 */
    {
        DOIP_DET_REPORT_ERROR (DOIP_API_ID_TP_CANCEL_TRANSMIT, DOIP_E_INVALID_PDU_SDU_ID);
    }
    else if (DOIP_ACTIVATION_LINE_ACTIVE == DoIP_ActivationLineStatus) /* SWS_DoIP_00202 */
    {
        conId = DoIP_ChannelCtrl[DoIPPduRTxId].TcpConId;

        if (conId < (uint8) DOIP_TCP_CON_NUM)
        {
            tpSessionPtr = DOIP_TCP_CON_MGMT_TX_SESSION_PTR (conId);

            if (tpSessionPtr->ChannelId == DoIPPduRTxId) /* PDU is in progress */
            {
                soadTxPduId = DOIP_GET_TCPCON_SOAD_TX_PDUID (conId);
                /*SWS_DoIP_00257*/
                retVal = SoAd_TpCancelTransmit (soadTxPduId);

                if (E_OK == retVal)
                {
                    DOIP_TP_SESSION_CLR (tpSessionPtr);
                }
            }
            else/* PDU is in transmission job list */
            {
                list = DOIP_TP_TX_LIST_PTR (conId);
                inlist = DoIP_TpTxListFindPduId (list, DoIPPduRTxId);

                if (TRUE == inlist)
                {
                    retVal = DoIP_TpTxListRemovePduId (list, DoIPPduRTxId);
                }
            }
        }
    }
    else
    {
        /* do nothing */
    }

    return retVal;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DoIP_TpCancelReceive
*
* Description:   By calling this API with the corresponding PduRRxPduId the
*                currently ongoing data reception is terminated immediately.
* Inputs:        PduRRxPduId: DoIP unique identifier of the PDU for which
*                reception shall be canceled by the PduR
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC (Std_ReturnType, DOIP_CODE) DoIP_TpCancelReceive
(
    PduIdType PduRRxPduId
)
{
    PduIdType conId;
    Std_ReturnType retVal;

    retVal = E_NOT_OK;

    if (STD_INITIALIZED != DoIP_InitState) /* SWS_DoIP_00169 */
    {
        DOIP_DET_REPORT_ERROR (DOIP_API_ID_TP_CANCEL_RECEIVE, DOIP_E_UNINIT);
    }
    else if (PduRRxPduId >= DOIP_CHANNEL_NUM) /* SWS_DoIP_00170 */
    {
        DOIP_DET_REPORT_ERROR (DOIP_API_ID_TP_CANCEL_RECEIVE, DOIP_E_INVALID_PDU_SDU_ID);
    }
    else if (DOIP_ACTIVATION_LINE_ACTIVE == DoIP_ActivationLineStatus) /* SWS_DoIP_00202 */
    {
        conId = DOIP_CHANNEL_CTRL_PTR(PduRRxPduId)->TcpConId;

        /*Check ConId and RoutingActivation is valid*/
        if (conId < (uint8) DOIP_TCP_CON_NUM)
        {
            /*Consider the time between connection established to connection disconnected as Tp reception*/
            /*SWS_DoIP_00258*/
            retVal = SoAd_TpCancelReceive (DOIP_GET_TCPCON_SOAD_RX_PDUID (conId));

            if (E_OK == retVal)
            {
                DOIP_TP_SESSION_CLR (DOIP_TCP_CON_MGMT_RX_SESSION_PTR (conId));
            }
        }
    }
    else
    {
        /* do nothing */
    }

    return retVal;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DoIP_IfTransmit
*
* Description:   Requests transmission of an I-PDU.
* Inputs:        id: Identification of the I-PDU.
*                info: Length and pointer to the buffer of the I-PDU.
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC (Std_ReturnType, DOIP_CODE) DoIP_IfTransmit
(
    PduIdType id,
    const PduInfoType *info
)
{
    Std_ReturnType retVal;/* SWS_DoIP_00226 */
    PduIdType conId;

    retVal = E_NOT_OK;

    if (STD_INITIALIZED != DoIP_InitState)
    {
        DOIP_DET_REPORT_ERROR (DOIP_API_ID_IF_TRANSMIT, DOIP_E_UNINIT);
    }
    else if (id >= DOIP_CHANNEL_NUM)
    {
        DOIP_DET_REPORT_ERROR (DOIP_API_ID_IF_TRANSMIT, DOIP_E_INVALID_PDU_SDU_ID);
    }
    else if ( (NULL_PTR == info) || (NULL_PTR == info->SduDataPtr) )
    {
        DOIP_DET_REPORT_ERROR (DOIP_API_ID_IF_TRANSMIT, DOIP_E_PARAM_POINTER);
    }
    else if ( (DOIP_ACTIVATION_LINE_ACTIVE == DoIP_ActivationLineStatus) /* SWS_DoIP_00202 */
              && (info->SduLength > (uint16) 0)
              && (DOIP_GET_CHANNEL_PDU_TYPE (id) == DOIP_IFPDU)
              && (DoIP_TcpConMgmt[DoIP_ChannelCtrl[id].TcpConId].SoConMode == SOAD_SOCON_ONLINE) ) /*SWS_DoIP_00130*/
    {
        conId = DoIP_ChannelCtrl[id].TcpConId;
        /*SWS_DoIP_00230*/
        retVal = DoIP_TcpRequestTransmit (conId, id, info, DOIP_PAYLOAD_TYPE_DIAG_MSG);
    }
    else
    {
        /* do nothing */
    }

    return retVal;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DoIP_IfCancelTransmit
*
* Description:   Requests cancellation of an ongoing transmission of an I-PDU
*                in a lower layer communication interface module.
* Inputs:        id: Identification of the I-PDU to be cancelled.
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC (Std_ReturnType, DOIP_CODE) DoIP_IfCancelTransmit
(
    PduIdType id
)
{
    PduIdType conId;
    DoIP_TpSessionType *tpSessionPtr;
    DoIP_TpTxListType *list;
    Std_ReturnType retVal;
    PduIdType soadTxPduId;
    boolean inlist;

    retVal = E_NOT_OK;

    if (DOIP_ACTIVATION_LINE_ACTIVE == DoIP_ActivationLineStatus) /* SWS_DoIP_00202 */
    {
        conId = DoIP_ChannelCtrl[id].TcpConId;
        tpSessionPtr = DOIP_TCP_CON_MGMT_TX_SESSION_PTR (conId);

        if (tpSessionPtr->ChannelId == id) /* PDU is in progress */
        {
            soadTxPduId = DOIP_GET_TCPCON_SOAD_TX_PDUID (conId);
            /*SWS_DoIP_00257*/
            retVal = SoAd_TpCancelTransmit (soadTxPduId);

            if (E_OK == retVal)
            {
                DOIP_TP_SESSION_CLR (tpSessionPtr);
            }
        }
        else/* PDU is in transmission job list */
        {
            list = DOIP_TP_TX_LIST_PTR (conId);
            inlist = DoIP_TpTxListFindPduId (list, id);

            if (TRUE == inlist)
            {
                retVal = DoIP_TpTxListRemovePduId (list, id);
            }
            else
            {
                retVal = E_OK;
            }
        }
    }

    return retVal;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DoIP_MainFunction
*
* Description:   Main function of DoIP module
*
* Inputs:        None
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC (void, DOIP_CODE) DoIP_MainFunction (void)
{
#if (DOIP_VIN_GID_MASTER == STD_ON)
    Std_ReturnType retVal;
#endif
    /* DOIP_MAINFUNCTION_PERIOD */
    DoIP_ActivationLineStatusHandler();

    /* SWS_DoIP_00076 */
#if (DOIP_VIN_GID_MASTER == STD_ON)

    if ( (DoIP_ConfigPtr->TriggerGidSyncCallback != NULL_PTR) &&
            (DoIP_GidSyncStatus == DOIP_GID_SYNC_STATE_PENDING) )
    {
        /*SWS_DoIP_00050*/
        retVal = DoIP_ConfigPtr->TriggerGidSyncCallback();

        if (E_OK == retVal)
        {
            DoIP_GidSyncStatus = DOIP_GID_SYNC_STATE_FINISH;
        }
    }

#endif
    DoIP_IncreaseRandomNum();
    DoIP_MainFunctionUdp();
    DoIP_MainFunctionTcp();
}

/******************************************************************************
 * Callback Functions for connection establish
 * List as follow:
 * - DoIP_SoConModeChg
 * - DoIP_ActivationLineSwitch
 * - DoIP_LocalIpAddrAssignmentChg
 ******************************************************************************/

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DoIP_SoConModeChg
*
* Description:   This Api is call by SoAd module to indicate a Socket Connection
*                mode change
*
* Inputs:        SoConId: Sockt Connection ConId
*                Mode: Current Socket Connection mode
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC (void, DOIP_CODE) DoIP_SoConModeChg
(
    SoAd_SoConIdType SoConId,
    SoAd_SoConModeType Mode
)
{
    uint8 i;
    uint8 conId;
    Std_ReturnType retVal;
#if(DOIP_NODE_TYPE == DOIP_GATEWAY)
    boolean allClose;
    SoAd_SoConIdType id;
#endif

    if (STD_INITIALIZED != DoIP_InitState) /* SWS_DoIP_00193 */
    {
        DOIP_DET_REPORT_ERROR (DOIP_API_ID_SO_CON_MODE_CHG, DOIP_E_UNINIT);
    }
    else if (!DOIP_IS_SOCON_MODE_VALID (Mode) ) /* SWS_DoIP_00194 */
    {
        DOIP_DET_REPORT_ERROR (DOIP_API_ID_SO_CON_MODE_CHG, DOIP_E_INVALID_PARAMETER);
    }
    else
    {
        /* UDP connection */
        conId = DOIP_INVALID_ID;
        retVal = DoIP_GetUdpConIdBySoConId (SoConId, &conId);

        if (E_OK == retVal)
        {
            if ( (Mode == SOAD_SOCON_ONLINE) || (Mode == SOAD_SOCON_RECONN) )
            {
                DoIP_UdpConMgmt[conId].SoConMode = SOAD_SOCON_ONLINE;/* SWS_DoIP_00241 */
            }
            else
            {
                DoIP_UdpConMgmt[conId].SoConMode = SOAD_SOCON_OFFLINE;/* SWS_DoIP_00243 */
                DoIP_UdpConMgmt[conId].SoConCloseStatus = DOIP_SOCON_CLOSE_REQ_NONE;

                DoIP_UdpConMgmt[conId].RemoteAddr.Domain = DOIP_TCPIP_AF_INET;
                DoIP_UdpConMgmt[conId].RemoteAddr.Port = TCPIP_PORT_ANY;
                DoIP_UdpConMgmt[conId].RemoteAddr.Addr[0] = (uint32) TCPIP_IPADDR_ANY;
                DoIP_UdpConMgmt[conId].ReqCount = (uint8) 0;
                DoIP_UdpConMgmt[conId].QIn = (uint8) 0;
                DoIP_UdpConMgmt[conId].QOut = (uint8) 0;

                DoIP_UdpConMgmt[conId].VehicleAnnouncementCount = (uint8) 0;
                DoIP_UdpConMgmt[conId].AnnounceTimer = (uint32) 0;

                for (i = (uint8) 0; i < DOIP_MAX_UDP_REQ_PER_MESSAGE; i++)
                {
                    DoIP_UdpConMgmt[conId].ReqQ[i].PayloadType = DOIP_INVALID_PAYLOAD_TYPE;
                    Bsw_MemSet (DoIP_UdpConMgmt[conId].ReqQ[i].Param, (uint8) 0, (uint32) DOIP_UDP_REQ_MAX_PARAM_LEN);
                }

#if(DOIP_NODE_TYPE == DOIP_GATEWAY)
                /* SWS_DoIP_00235 */
                allClose = DoIP_UdpIsAllConClose();

                if (allClose == TRUE)
                {
                    /* First udp connection */
                    id = DOIP_GET_UDPCON_SOAD_SOCONID (0);
                    (void) SoAd_ReleaseIpAddrAssignment (id);
                }
#endif
            }
        }
        else
        {
            /* TCP connection */
            retVal = DoIP_TcpGetConIdBySoConId (SoConId, &conId);

            if (E_OK == retVal)
            {
                if (Mode == SOAD_SOCON_ONLINE)
                {
                    /* SWS_DoIP_00241 */
                    /* SWS_DoIP_00143 */
                    DoIP_TcpConMgmt[conId].SoConMode = Mode;
                }

                /*else if (Mode == SOAD_SOCON_RECONN)
                {*/
                /* Listen to 13400 port, no client yet*/
                /*}*/

                else
                {
                    DoIP_TcpConMgmt[conId].SoConCloseStatus = DOIP_SOCON_CLOSE_REQ_NONE;

                    /* SWS_DoIP_00243 */
                    DoIP_TcpConMgmt[conId].SoConMode = SOAD_SOCON_OFFLINE;
                    /* SWS_DoIP_00115 */
                    DoIP_TcpConMgmt[conId].TesterId = DOIP_INVALID_TESTER_INDEX;
                    DoIP_TcpConMgmt[conId].InactiveTimer = (uint32) 0;

                    /* Routing activation management */
                    DoIP_TcpConMgmt[conId].AliveCheckPerformed = FALSE;
                    DoIP_TcpConMgmt[conId].AliveCheckTimer = (uint32) 0;
                    DoIP_TcpConMgmt[conId].OwnerId = DOIP_INVALID_ID;
                    DoIP_RoutActivMgmt[conId].Status = DOIP_ROUTING_ACTIVATION_REQ_NONE;
                    DoIP_RoutActivMgmt[conId].ReqParam.ActionType = (uint8) DOIP_ACTIONTYPE_INVALID;
                    Bsw_MemSet (DoIP_RoutActivMgmt[conId].ReqParam.OemResv, (uint8) 0, (uint32) DOIP_REVE_LENGTH);
                    DoIP_RoutActivMgmt[conId].ReqParam.RoutActivId = DOIP_INVALID_ID;
                    DoIP_RoutActivMgmt[conId].ReqParam.SA = DOIP_INVALID_LOGIC_ADDR;
                    DoIP_RoutActivMgmt[conId].ReqParam.TesterId = DOIP_INVALID_ID;

                    if (Mode == SOAD_SOCON_OFFLINE)
                    {
                        /* Open the socket again to listen the 13400 port */
                        (void) SoAd_OpenSoCon (SoConId);
                    }
                    else
                    {
                        /*do nothing*/
                    }
                }

            }
            else/* DET error report */
            {
                /* SWS_DoIP_00194 */
                DOIP_DET_REPORT_ERROR (DOIP_API_ID_SO_CON_MODE_CHG, DOIP_E_INVALID_PARAMETER);
            }
        }
    }

}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DoIP_ActivationLineSwitch
*
* Description:   This Api is call by upperlayer module to indicate Activiation
*                line state change.
*
* Inputs:        None
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC (void, DOIP_CODE) DoIP_ActivationLineSwitch (void) /* SWS_DoIP_00201 */
{
    DoIP_ActivationLineStatusType currentStatus;

    if (STD_INITIALIZED != DoIP_InitState) /* SWS_DoIP_00252 */
    {
        DOIP_DET_REPORT_ERROR (DOIP_API_ID_ACTIVATION_LINE_SWITCH, DOIP_E_UNINIT);
    }
    else
    {
        /* SWS_DoIP_00203 */
        currentStatus = DOIP_CURRENT_ACTIVATION_LINE_STATUS();

        if (DoIP_ActivationLineStatus != currentStatus)
        {
            DoIP_ActivationLineStatus = currentStatus;

            if (DOIP_ACTIVATION_LINE_ACTIVE == currentStatus)
            {
                DoIP_ActivationLineSwitchAction = (uint8) DOIP_ACTIVATION_LINE_SWITCH_INACTIVE2ACTIVE;
            }
            else if (DOIP_ACTIVATION_LINE_INACTIVE == currentStatus)
            {
                DoIP_ActivationLineSwitchAction = (uint8) DOIP_ACTIVATION_LINE_SWITCH_ACTIVE2INACTIVE;
            }
            else
            {
                /* do nothing */
            }
        }
    }

}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DoIP_LocalIpAddrAssignmentChg
*
* Description:   This Api is call by SoAd module to indicate the Change of Local
*                Ip Address.
*
* Inputs:        SoConId: Sockt Connection ConId
*                State: Current Ip Address state
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC (void, DOIP_CODE) DoIP_LocalIpAddrAssignmentChg
(
    SoAd_SoConIdType SoConId,
    TcpIp_IpAddrStateType State
)
{
    SoAd_SoConIdType id;
    uint8 conId;
#if (DOIP_VIN_GID_MASTER == STD_ON)
    Std_ReturnType retVal;
#endif
    Std_ReturnType retValGetUdp, retValGetTcp;

    if (STD_INITIALIZED != DoIP_InitState) /* SWS_DoIP_00195 */
    {
        DOIP_DET_REPORT_ERROR (DOIP_API_ID_LOC_IP_ADDR_ASSIGN_CHG, DOIP_E_UNINIT);
    }
    else
    {
        retValGetUdp = DoIP_GetUdpConIdBySoConId (SoConId, &conId);
        retValGetTcp = DoIP_TcpGetConIdBySoConId (SoConId, &conId);

        /* SWS_DoIP_00196  check soconId */
        if ( (E_OK != retValGetUdp) && (E_OK != retValGetTcp) )
        {
            DOIP_DET_REPORT_ERROR (DOIP_API_ID_LOC_IP_ADDR_ASSIGN_CHG, DOIP_E_INVALID_PARAMETER);
        }
        else
        {
            if (TCPIP_IPADDR_STATE_ASSIGNED == State)
            {
                /* SWS_DoIP_00003
                 * Open all UDP connections.
                 */
                for (conId = (uint8) 0; conId < (uint8) DOIP_UDP_CON_NUM; conId++)
                {
                    id = DOIP_GET_UDPCON_SOAD_SOCONID (conId);
                    (void) SoAd_OpenSoCon (id);

                    /* SWS_DoIP_00205
                     * Send vehicle announcement message via this socket connection
                     */
                    DoIP_UdpConMgmt[conId].VehicleAnnouncementCount = DOIP_VEHICLE_ANNOUNCEMENT_REPETITION;
                    DoIP_AnnounceIntialTimer[conId] = DoIP_GetAnnounceIntialTimer();
                    /* Vehicle announcement is broadcast */
                    DoIP_UdpConMgmt[conId].RemoteAddr.Domain = DOIP_TCPIP_AF_INET;
                    DoIP_UdpConMgmt[conId].RemoteAddr.Addr[0] = DOIP_TCPIP_BROADCAT;
                    DoIP_UdpConMgmt[conId].RemoteAddr.Port = DOIP_DIAGPORT;
                }

                /* Open all TCP connections */
                for (conId = (uint8) 0; conId < (uint8) DOIP_TCP_CON_NUM; conId++)
                {
                    id = DOIP_GET_TCPCON_SOAD_SOCONID (conId);
                    (void) SoAd_OpenSoCon (id);
                }

#if 0
                /* SWS_DoIP_00154
                 * SWS_DoIP_00155
                 * SWS_DoIP_00156
                 * Implement as below.
                 */
                retVal = SoAd_ReadDhcpHostNameOption (SoConId, &copy, &opt[0]);

                if (E_OK == retVal && copy > 5)
                {
                    /* Check dhcp host name option ascii is "DoIP-" or not */
                    retVal = DoIP_MemCompare (buf, opt, 5);

                    if (E_OK != retVal)
                    {
#if (DOIP_DHCP_OPTION_VIN_USE == STD_ON)
                        retVal = Dcm_GetVin (&opt[5]);

                        if (E_OK != retVal)
                        {
                            for (idx = 5; idx < 23; idx++)
                            {
                                opt[idx] = DOIP_VIN_INVALIDATIY_PATTERN;
                            }
                        }

                        retVal = SoAd_WriteDhcpHostNameOption (SoConId, sizeof (opt), opt);
#else
                        retVal = SoAd_WriteDhcpHostNameOption (SoConId, sizeof (buf), buf);
#endif
                    }
                }
#endif

                /* SWS_DoIP_00076 */
#if (DOIP_VIN_GID_MASTER == STD_ON)

                if (DoIP_ConfigPtr->TriggerGidSyncCallback != NULL_PTR)
                {
                    /*SWS_DoIP_00050*/
                    retVal = DoIP_ConfigPtr->TriggerGidSyncCallback();

                    if (retVal == E_OK)
                    {
                        DoIP_GidSyncStatus = DOIP_GID_SYNC_STATE_FINISH;
                    }
                    else
                    {
                        DoIP_GidSyncStatus = DOIP_GID_SYNC_STATE_PENDING;
                    }
                }

#endif
            }
            else
            {
                /*SWS_DoIP_00196*/
                if((TCPIP_IPADDR_STATE_ONHOLD != State) || (TCPIP_IPADDR_STATE_UNASSIGNED != State))
                {
                    DOIP_DET_REPORT_ERROR (DOIP_API_ID_LOC_IP_ADDR_ASSIGN_CHG, DOIP_E_INVALID_PARAMETER);
                }
                else
                {
#if (DOIP_VIN_GID_MASTER == STD_ON)
                    /*SWS_DoIP_00085*/
                	DoIP_GidSyncStatus = DOIP_GID_SYNC_STATE_IDLE;
#endif
                }
            }
        }
    }

}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DoIP_SoAdIfRxIndication
*
* Description:   SoAd call this function to indicate new I-PDU received.
*
* Inputs:        RxPduId: PduId realated to the I-PDU
*                PduInfoPtr: Content of the I-PDU
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC (void, DOIP_CODE) DoIP_SoAdIfRxIndication
(
    PduIdType RxPduId,
    const PduInfoType *PduInfoPtr
)
{
    DoIP_GenericHeaderNackType GenericHeaderNack;
    DoIP_UdpConMgmtType *udpMgmt;
    uint16 payloadType;
    uint32 payloadLength;
    PduInfoType rxPduInfo;

    boolean soconClose;
    boolean IsVehicleAnnounce;
    Std_ReturnType retVal;


    if (STD_INITIALIZED != DoIP_InitState) /* SWS_DoIP_00246 */
    {
        DOIP_DET_REPORT_ERROR (DOIP_API_ID_IF_RX_INDICATION, DOIP_E_UNINIT);
    }
    else if (RxPduId >= (uint8) DOIP_UDP_CON_NUM) /* SWS_DoIP_00247 */
    {
        DOIP_DET_REPORT_ERROR (DOIP_API_ID_IF_RX_INDICATION, DOIP_E_INVALID_PDU_SDU_ID);
    }
    else if ( (PduInfoPtr == NULL_PTR) || (PduInfoPtr->SduDataPtr == NULL_PTR) ) /* SWS_DoIP_00248 */
    {
        DOIP_DET_REPORT_ERROR (DOIP_API_ID_IF_RX_INDICATION, DOIP_E_PARAM_POINTER);
    }
    else if (DOIP_ACTIVATION_LINE_ACTIVE == DoIP_ActivationLineStatus) /* SWS_DoIP_00202 */
    {
        udpMgmt = DOIP_UDP_CON_MGMT_PTR (RxPduId);

        udpMgmt->RemoteAddr.Domain = DOIP_TCPIP_AF_INET;
        (void) SoAd_GetRemoteAddr (DOIP_GET_UDPCON_SOAD_SOCONID (RxPduId), (TcpIp_SockAddrType *) &udpMgmt->RemoteAddr);

        rxPduInfo.SduDataPtr = PduInfoPtr->SduDataPtr;
        rxPduInfo.SduLength = PduInfoPtr->SduLength;

        /* SWS_DoIP_00276 means that multiple DOIP requests may in one UDP Message.
         * One request will be paresed in one loop.
         */
        while (rxPduInfo.SduLength >= DOIP_GEN_HDR_LEN)
        {
            /*the repeated request will be ignored, when all bufs are full*/
            if (DOIP_MAX_UDP_REQ_PER_MESSAGE >= udpMgmt->ReqCount)
            {
                udpMgmt->ReqCount++;
            }

            /* SWS_DoIP_00276
             * DOIP_MAX_UDP_REQ_PER_MESSAGE also means the number of requests that
             * a udp connection can accept totoally, maybe from two or more PDUs.
             */
            if (udpMgmt->ReqCount > DOIP_MAX_UDP_REQ_PER_MESSAGE)
            {
                GenericHeaderNack.NackCode = DOIP_GEN_HDR_NACK_OUT_OF_MEMORY;
                udpMgmt->ReqCount_OutOfMemory_flag = (uint8) 1;
                soconClose = FALSE;
                retVal = E_NOT_OK;
            }
            else
            {
                retVal = DoIP_GenericHeaderCheck (rxPduInfo.SduDataPtr, (uint8) DOIP_PROTOCOL_UDP, &GenericHeaderNack.NackCode, &soconClose, &IsVehicleAnnounce);
            }

            /* donot care payloadType is correct or not */
            payloadLength = DOIP_U32 ( ( (DoIP_GenHdrType *) (rxPduInfo.SduDataPtr) )->Length);

            if (retVal == E_OK)
            {
                if(IsVehicleAnnounce == TRUE)
                {
                    /*Ignore Message*/
                }
                else
                {
                    payloadType = DOIP_U16 ( ( (DoIP_GenHdrType *) (rxPduInfo.SduDataPtr) )->PayloadType);

                    /* SWS_DoIP_00197
                    * Request has been acceptted and stored.
                    */
                    udpMgmt->ReqQ[udpMgmt->QIn].PayloadType = payloadType;
                    Bsw_MemCpy (& (udpMgmt->ReqQ[udpMgmt->QIn].Param[0]), ( (DoIP_GenMsgType *) (rxPduInfo.SduDataPtr) )->Payload, payloadLength);
                }
            }
            else
            {
                if (udpMgmt->ReqCount_OutOfMemory_flag == (uint8) 1)
                {
                    udpMgmt->ReqQ[(uint32)DOIP_MAX_UDP_REQ_PER_MESSAGE].PayloadType = DOIP_PAYLOAD_TYPE_GEN_HDR_NACK;
                    udpMgmt->ReqQ[(uint32)DOIP_MAX_UDP_REQ_PER_MESSAGE].Param[0] = GenericHeaderNack.NackCode;
                }
                else
                {
                    udpMgmt->ReqQ[udpMgmt->QIn].PayloadType = DOIP_PAYLOAD_TYPE_GEN_HDR_NACK;
                    udpMgmt->ReqQ[udpMgmt->QIn].Param[0] = GenericHeaderNack.NackCode;
                }

                if (soconClose == TRUE)
                {
                    /*udpMgmt->SoConCloseStatus = DOIP_SOCON_CLOSE_REQ_PENDING;*/
                    udpMgmt->ReqQ[udpMgmt->QIn].SoConCloseStatus = DOIP_SOCON_CLOSE_REQ_PENDING;
                    break;/* Loop is terminated when socket connection is going to be closed */
                }

                /*break;*/
            }

            if (DOIP_MAX_UDP_REQ_PER_MESSAGE >= udpMgmt->ReqCount)
            {
                udpMgmt->QIn++;

                if (udpMgmt->QIn == DOIP_MAX_UDP_REQ_PER_MESSAGE)
                {
                    udpMgmt->QIn = (uint8) 0; /* roll back */
                }
            }

            rxPduInfo.SduDataPtr = (SduDataPtrType)&rxPduInfo.SduDataPtr[ (PduLengthType) payloadLength + DOIP_GEN_HDR_LEN];
            rxPduInfo.SduLength -= ( (PduLengthType) payloadLength + DOIP_GEN_HDR_LEN);

        }

    }
    else
    {
        /*do nothing*/
    }

}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DoIP_SoAdIfTxConfirmation
*
* Description:   Lowerlayer call this function to indicate An I-PDU has been
*                successfully transmited.
*
* Inputs:        TxPduId: PduId realated to the I-PDU
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC (void, DOIP_CODE) DoIP_SoAdIfTxConfirmation
(
    PduIdType TxPduId
)
{

    DoIP_UdpConMgmtType *udpMgmt;
    Std_ReturnType retVal;
    SoAd_SoConIdType soconId;


    /* SWS_DoIP_00249 */
    if (STD_INITIALIZED != DoIP_InitState)
    {
        DOIP_DET_REPORT_ERROR (DOIP_API_ID_IF_TX_CONFIRMATION, DOIP_E_UNINIT);
    }
    /* SWS_DoIP_00250 */
    else if (TxPduId >= (uint8) DOIP_UDP_CON_NUM)
    {
        DOIP_DET_REPORT_ERROR (DOIP_API_ID_IF_TX_CONFIRMATION, DOIP_E_INVALID_PDU_SDU_ID);
    }
    /* SWS_DoIP_00202 */
    else if (DOIP_ACTIVATION_LINE_INACTIVE != DoIP_ActivationLineStatus)
    {
        /*protect*/
        DOIP_ENTER_CRITICAL_SECTION_SOCONSTATUS();
        /* SWS_DoIP_00199 */
        udpMgmt = DOIP_UDP_CON_MGMT_PTR (TxPduId);
        soconId = DOIP_GET_UDPCON_SOAD_SOCONID (TxPduId);

        /* Clear the remote address */
        if (udpMgmt->VehicleAnnouncementCount == (uint8) 0)
        {
            udpMgmt->RemoteAddr.Domain = DOIP_TCPIP_AF_INET;
            udpMgmt->RemoteAddr.Addr[0] = (uint32) TCPIP_IPADDR_ANY;
            udpMgmt->RemoteAddr.Port = TCPIP_PORT_ANY;

            (void) SoAd_SetRemoteAddr (soconId, (const TcpIp_SockAddrType *) &udpMgmt->RemoteAddr);
        }

        /* Close udp socket */
        if (udpMgmt->SoConCloseStatus == DOIP_SOCON_CLOSE_REQ_PENDING)
        {
            /*SWS_DoIP_00058*/
            retVal = SoAd_CloseSoCon (soconId, TRUE);
            (void) SoAd_OpenSoCon (soconId);

            if (E_OK == retVal)
            {
                udpMgmt->SoConCloseStatus = DOIP_SOCON_CLOSE_REQ_PROCESSING;
            }
        }

        /*unprotect*/
        DOIP_LEAVE_CRITICAL_SECTION_SOCONSTATUS();
    }
    else
    {
        /* do nothing */
    }
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DoIP_SoAdTpStartOfReception
*
* Description:   This function is called at the start of receiving an N-SDU.
*                The N-SDU might be fragmented into multiple N-PDUs (FF with
*                one or more following CFs) or might consist of a single N-PDU
*                (SF).
*
* Inputs:        id: Identification of the I-PDU
*                info: Pointer to a PduInfoType structure containing the payload
*                      data (without protocol information) and payload length of
*                      the first frame or single frame of a transport protocol
*                      I-PDU reception.
*                TpSduLength: TotalLen length of the N-SDU to be received.
*
* Outputs:       bufferSizePtr: Available receive buffer in the receiving module
*
* Limitations:   This API will be called from SoAd only once per TCP connection,
*                directly when the  socket  is  connected.  All  the  data  will
*                be  transferred  to  DoIP  via  the  API DoIP_SoAdTpCopyRxData.
********************************************************************************
END_FUNCTION_HDR*/
/* PRQA S 3206 ++ */
/*No use info*/
FUNC (BufReq_ReturnType, DOIP_CODE) DoIP_SoAdTpStartOfReception
(
    PduIdType id,
    const PduInfoType *info,
    PduLengthType TpSduLength,
    PduLengthType *bufferSizePtr
)
{
    BufReq_ReturnType retVal;

    retVal = BUFREQ_E_NOT_OK;

    /* SWS_DoIP_00186 */
    if (STD_INITIALIZED != DoIP_InitState)
    {
        DOIP_DET_REPORT_ERROR (DOIP_API_ID_TP_START_OF_RECEPTION, DOIP_E_UNINIT);
    }
    /* SWS_DoIP_00188 */
    else if (bufferSizePtr == NULL_PTR)
    {
        DOIP_DET_REPORT_ERROR (DOIP_API_ID_TP_START_OF_RECEPTION, DOIP_E_PARAM_POINTER);
    }
    /* SWS_DoIP_00189 */
    else if (TpSduLength != (PduLengthType) 0)
    {
        DOIP_DET_REPORT_ERROR (DOIP_API_ID_TP_START_OF_RECEPTION, DOIP_E_INVALID_PARAMETER);
    }
    /* SWS_DoIP_00187 */
    else if (id >= (uint8) DOIP_TCP_CON_NUM)
    {
        DOIP_DET_REPORT_ERROR (DOIP_API_ID_TP_START_OF_RECEPTION, DOIP_E_INVALID_PDU_SDU_ID);
    }
    /* SWS_DoIP_00202 */
    else if (DOIP_ACTIVATION_LINE_INACTIVE != DoIP_ActivationLineStatus)
    {
        /*SWS_DoIP_00207*/
        *bufferSizePtr = (uint16) DOIP_TCP_CON_BUF_SIZE;
        retVal = BUFREQ_OK;
    }
    else
    {
        /* Ignore the request */
    }

    return retVal;
}
/*PRQA S 3206 --*/
/*No use info*/

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DoIP_SoAdTpCopyRxData
*
* Description:   This function is called to provide the received data of an
*                I-PDU segment (N-PDU) to the upper layer.
*
* Inputs:        id: Identification of the received I-PDU
*                info: Provides the source buffer (SduDataPtr) and the number
*                      of bytes to be copied (SduLength).
*
* Outputs:       bufferSizePtr: Available receive buffer after data has been
*                               copied.
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC (BufReq_ReturnType, DOIP_CODE) DoIP_SoAdTpCopyRxData
(
    PduIdType id,
    const PduInfoType *info,
    PduLengthType *bufferSizePtr
)
{
    BufReq_ReturnType bufReq;
    DoIP_TcpConMgmtType *tcpMgmtPtr;
    DoIP_TpSessionType *tpSessionPtr;

    bufReq = BUFREQ_E_NOT_OK;

    if (STD_INITIALIZED != DoIP_InitState) /* SWS_DoIP_00183 */
    {
        DOIP_DET_REPORT_ERROR (DOIP_API_ID_TP_COPY_RX_DATA, DOIP_E_UNINIT);
    }
    else if (id >= (uint8) DOIP_TCP_CON_NUM) /* SWS_DoIP_00036*/
    {
        DOIP_DET_REPORT_ERROR (DOIP_API_ID_TP_COPY_RX_DATA, DOIP_E_INVALID_PDU_SDU_ID);
    }
    else if ( (info == NULL_PTR) || (bufferSizePtr == NULL_PTR) ) /* SWS_DoIP_00184 */
    {
        DOIP_DET_REPORT_ERROR (DOIP_API_ID_TP_COPY_RX_DATA, DOIP_E_PARAM_POINTER);
    }
    else if (DOIP_ACTIVATION_LINE_ACTIVE == DoIP_ActivationLineStatus) /* SWS_DoIP_00202 */
    {
        tcpMgmtPtr = DOIP_TCP_CON_MGMT_PTR (id);
        tpSessionPtr = DOIP_TCP_CON_MGMT_RX_SESSION_PTR (id);

        if ( (tcpMgmtPtr->SoConMode == SOAD_SOCON_ONLINE)
                && (tcpMgmtPtr->SoConCloseStatus == DOIP_SOCON_CLOSE_REQ_NONE) )
        {
            if (DoIP_RoutActivMgmt[id].Status == DOIP_ROUTING_ACTIVATION_ACTIVED)
            {
                tcpMgmtPtr->InactiveTimer = (uint32) 0; /* SWS_DoIP_00145 */
            }

            /* SoAd trying to query avalible buffer size */
            if (info->SduLength == (uint16) 0)
            {
                /* At the start of a new DoIP message, directly  after  DoIPSoAdTpStartOfReception
                 * succeeded  or  previous DoIP message processed completely
                 */
                if (tpSessionPtr->TotalLen == (uint16) 0) /* Start of a new message */
                {
                    /* SWS_DoIP_00208
                     * Evaluate the DoIP relevant data for routing of diagnostic data
                     */
                    *bufferSizePtr = (PduLengthType)DOIP_GEN_HDR_LEN;
                }
                else /* If total Length != 0, that means previous message is already in buffer */
                {
                    *bufferSizePtr = (PduLengthType)tpSessionPtr->TotalLen - (PduLengthType)(tpSessionPtr->Offset);
                }

                bufReq = BUFREQ_OK;
            }
            else if ( ( (uint16) DOIP_TCP_CON_BUF_SIZE - tpSessionPtr->Offset) < info->SduLength) /*SWS_DoIP_00210*/
            {
                bufReq = BUFREQ_E_NOT_OK;
            }
            else
            {
                bufReq = DoIP_TcpReceive (id, info, bufferSizePtr);
            }
        }
    }
    else
    {
        /* Do nothing */
    }

    return bufReq;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DoIP_SoAdTpRxIndication
*
* Description:   Called after an I-PDU has been received via the TP API, the
*                result indicates whether the transmission was successful or not.
* Inputs:        id: ConId of the Rx I-PDU
*                result: Reception result
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC (void, DOIP_CODE) DoIP_SoAdTpRxIndication
(
    PduIdType id,
    Std_ReturnType result
)
{
    uint8 i;

    DoIP_ChannelCtrlType *ctrl;
    DoIP_TpTxListType *list;
    PduIdType pdurRxPduId;

    if (STD_INITIALIZED != DoIP_InitState) /* SWS_DoIP_00190 */
    {
        DOIP_DET_REPORT_ERROR (DOIP_API_ID_TP_RX_INDICATION, DOIP_E_UNINIT);
    }
    else if (id >= (uint8) DOIP_TCP_CON_NUM) /* SWS_DoIP_00191 */
    {
        DOIP_DET_REPORT_ERROR (DOIP_API_ID_TP_RX_INDICATION, DOIP_E_INVALID_PDU_SDU_ID);
    }
    else if ( (result != E_OK) && (result != E_NOT_OK) ) /* SWS_DoIP_00192 */
    {
        DOIP_DET_REPORT_ERROR (DOIP_API_ID_TP_RX_INDICATION, DOIP_E_INVALID_PARAMETER);
    }
    else if (DOIP_ACTIVATION_LINE_ACTIVE == DoIP_ActivationLineStatus) /* SWS_DoIP_00202 */
    {
        /*SWS_DoIP_00200*/
        /*call PduR_DoIPTpRxIndication if a reception for diagnostic message is currently ongoing*/
        if ( (DoIP_TcpConMgmt[id].RxSes.TotalLen != DoIP_TcpConMgmt[id].RxSes.Offset) &&
                (DoIP_TcpConMgmt[id].RxSes.ChannelId < DOIP_CHANNEL_NUM) )
        {
            pdurRxPduId = DOIP_GET_CHANNEL_PDUR_RX_PDUID (DoIP_TcpConMgmt[id].RxSes.ChannelId);
            DOIP_CALL_UL_DOIP_TP_RX_INDICATION (pdurRxPduId, E_NOT_OK);
        }

        /* Clear current transmission / receiving session */
        DOIP_TP_SESSION_CLR (&DoIP_TcpConMgmt[id].RxSes);
        DOIP_TP_SESSION_CLR (&DoIP_TcpConMgmt[id].TxSes);

        /* Clear tx job list */
        list = DOIP_TP_TX_LIST_PTR (id);
        DoIP_TpTxListRemoveAll (list);

        Bsw_MemSet (DoIP_TcpConMgmt[id].SendBuf, (uint8) 0, (uint32) DOIP_TCP_CON_BUF_SIZE);
        Bsw_MemSet (DoIP_TcpConMgmt[id].RecvBuf, (uint8) 0, (uint32) DOIP_TCP_CON_BUF_SIZE);

        /* Reset reletive channel */
        for (i = (uint8) 0; i < DOIP_CHANNEL_NUM; i++)
        {
            ctrl = DOIP_CHANNEL_CTRL_PTR (i);

            if (ctrl->TcpConId == id)
            {
                ctrl->TcpConId = DOIP_INVALID_PDUID;
                ctrl->RoutingActived = (uint8) DOIP_ROUTING_ACTIVATION_REQ_NONE;
            }
        }
    }
    else
    {
        /*do nothing*/
    }
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DoIP_SoAdTpCopyTxData
*
* Description:   Provides the destination buffer and the number of bytes to
*                be copied.
*
* Inputs:        id: Identification of the transmitted N-PDU.
*                info: Provides the destination buffer (SduDataPtr) and the
*                      number of bytes to be copied (SduLength).
*                retry: This parameter is used to acknowledge transmitted data
*                       or to retransmit data after transmission problems.
*
* Outputs:       AvailableDataPtr: Indicates the remaining number of bytes that
*                                  are available in the upper layer module's
*                                  Tx buffer
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC (BufReq_ReturnType, DOIP_CODE) DoIP_SoAdTpCopyTxData
(
    PduIdType id,
    const PduInfoType *info,
    RetryInfoType *retry,
    PduLengthType *AvailableDataPtr
)
{
    BufReq_ReturnType bufReq;
    DoIP_TpSessionType *tpSessionPtr;

    bufReq = BUFREQ_E_NOT_OK;

    if (STD_INITIALIZED != DoIP_InitState) /* SWS_DoIP_00175 */
    {
        DOIP_DET_REPORT_ERROR (DOIP_API_ID_TP_COPY_TX_DATA, DOIP_E_UNINIT);
    }
    else if (id >= (uint8) DOIP_TCP_CON_NUM) /* SWS_DoIP_00176 */
    {
        DOIP_DET_REPORT_ERROR (DOIP_API_ID_TP_COPY_TX_DATA, DOIP_E_INVALID_PDU_SDU_ID);
    }
    else if (DoIP_TcpConMgmt[id].SoConMode != SOAD_SOCON_ONLINE) /* SWS_DoIP_00176 */
    {
        DOIP_DET_REPORT_ERROR (DOIP_API_ID_TP_COPY_TX_DATA, DOIP_E_INVALID_PDU_SDU_ID);
    }
    else if ( (info == NULL_PTR) || (AvailableDataPtr == NULL_PTR) ) /* SWS_DoIP_00177 */
    {
        DOIP_DET_REPORT_ERROR (DOIP_API_ID_TP_COPY_TX_DATA, DOIP_E_PARAM_POINTER);
    }
    else if ( (NULL_PTR == info->SduDataPtr) && ( (PduLengthType) 0 != info->SduLength) )
    {
        DOIP_DET_REPORT_ERROR (DOIP_API_ID_TP_COPY_TX_DATA, DOIP_E_PARAM_POINTER);
    }
    else if (DOIP_ACTIVATION_LINE_ACTIVE == DoIP_ActivationLineStatus) /* SWS_DoIP_00202 */
    {
        bufReq = BUFREQ_OK;

        if (DoIP_RoutActivMgmt[id].Status == DOIP_ROUTING_ACTIVATION_ACTIVED)
        {
            DoIP_TcpConMgmt[id].InactiveTimer = (uint32) 0; /* SWS_DoIP_00145 */
        }

        tpSessionPtr = DOIP_TCP_CON_MGMT_TX_SESSION_PTR (id);

        /* SoAd is quering available data
         * Case 1 : Transmission session just start, this means after a successful call to SoAd_TpTransmit
         * Case 2 : In a transmission session, some data already been copied to SoAd.
         */

        /*SWS_DoIP_00231*//*SWS_DoIP_00224*/
        if (info->SduLength == (uint16) 0)
        {
            bufReq = DoIP_QueryTxAvailableDataLen (id, info, retry, AvailableDataPtr);
        }
        else
        {
            /*
             * Ignore TP_DATACONF and TP_CONFPENDING
             *
             * If current message is UUDT(IFPDU) or not a diagnostic message, all data is kept
             * in internal buffer until whole message is comfirmed .
             *
             * If current message is a diagnostic message, we forward the retry info directly to PduR.
             */
            if ( (retry != NULL_PTR) && (retry->TpDataState == TP_DATARETRY) )
            {
                if (retry->TxTpDataCnt <= tpSessionPtr->Offset)
                {
                    tpSessionPtr->Offset -= retry->TxTpDataCnt;/* roll back*/
                }
                else
                {
                    /*SoAd will close socket connection*/
                    bufReq = BUFREQ_E_NOT_OK;
                }
            }

            if (bufReq == BUFREQ_OK)
            {
                if ( (tpSessionPtr->PayloadType == DOIP_PAYLOAD_TYPE_DIAG_MSG )
                        && (DOIP_GET_CHANNEL_PDU_TYPE (tpSessionPtr->ChannelId) == DOIP_TPPDU) )
                {
                    bufReq = DoIP_CopyTpTxData (id, info, retry, AvailableDataPtr);
                }

                else/* non-diagnostic message or UUDT message*/
                {
                    /*
                     * When non-diagnostic message or UUDT message are transmitted,
                     * all data is in internal buffer.
                     */
                    bufReq = DoIP_CopyNonTpTxData (id, info, AvailableDataPtr);
                }
            }
        }
    }
    else
    {
        /**do nothing*/
    }

    return bufReq;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DoIP_SoAdTpTxConfirmation
*
* Description:   This function is called after the I-PDU has been transmitted on
*                its network, the result indicates whether the transmission was
*                successful or not.
* Inputs:        id: Identification of the transmitted N-PDU.
*                result: Result of the transmission of the N-PDU.
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC (void, DOIP_CODE) DoIP_SoAdTpTxConfirmation
(
    PduIdType id,
    Std_ReturnType result
)
{
    DoIP_TpSessionType *tpSessionPtr;
    PduIdType PduRTxPduId;
    PduIdType channelId;
    DoIP_PduType pduType;

    if (STD_INITIALIZED != DoIP_InitState) /* SWS_DoIP_00180 */
    {
        DOIP_DET_REPORT_ERROR (DOIP_API_ID_TP_TX_CONFIRMATION, DOIP_E_UNINIT);
    }
    else if (id >= (uint8) DOIP_TCP_CON_NUM) /* SWS_DoIP_00181 */
    {
        DOIP_DET_REPORT_ERROR (DOIP_API_ID_TP_TX_CONFIRMATION, DOIP_E_INVALID_PDU_SDU_ID);
    }
    else if ( (result != E_OK) && (result != E_NOT_OK) ) /* SWS_DoIP_00182 */
    {
        DOIP_DET_REPORT_ERROR (DOIP_API_ID_TP_TX_CONFIRMATION, DOIP_E_INVALID_PARAMETER);
    }
    else if (DOIP_ACTIVATION_LINE_ACTIVE == DoIP_ActivationLineStatus) /* SWS_DoIP_00202 */
    {
        tpSessionPtr = DOIP_TCP_CON_MGMT_TX_SESSION_PTR (id);
        channelId = tpSessionPtr->ChannelId;

        /* Check if this session is invoked by PduR or not */
        if (channelId != DOIP_INVALID_PDUID)
        {
            /* Indicate PduR the result */
            PduRTxPduId = DOIP_GET_CHANNEL_PDUR_TX_PDUID (channelId);
            pduType = DOIP_GET_CHANNEL_PDU_TYPE (channelId);

            if (pduType == DOIP_TPPDU)
            {
                /*SWS_DoIP_00233*/
                DOIP_CALL_UL_DOIP_TP_TX_CONFIRMATION (PduRTxPduId, result);
            }
            else if (pduType == DOIP_IFPDU)
            {
                /*SWS_DoIP_00233*/
                DOIP_CALL_UL_DOIP_IF_TX_CONFIRMATION (PduRTxPduId);
            }
            else
            {
                /*do nothing*/
            }
        }

        /* Clear current transmission session *//*SWS_DoIP_00229*/
        DOIP_TP_SESSION_CLR (tpSessionPtr);
    }
    else
    {
        /* Do nothing */
    }
}

#define DOIP_STOP_SEC_CODE
#include "MemMap.h"
