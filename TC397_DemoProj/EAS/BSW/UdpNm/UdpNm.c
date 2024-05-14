/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE                              
*   This software is the property of HiRain Technologies. Any information 
*   contained in this doc should not be reproduced, or used, or disclosed 
*   without the written authorization from HiRain Technologies.
********************************************************************************
*   File Name       : UdpNm.c
********************************************************************************
*   Project/Product : AUTOSAR 4.2.2
*   Title           : UDP Network Management module Source File
*   Author          : Hirain
********************************************************************************
*   Description     : Implementation of UDP Network Management 
*                     provided functionality
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
*   01.00.00    14/08/2017    junfei.chen   N/A          Original
*   01.00.01    10/03/2020    hao.liu       N/A          Original
*   01.00.02    05/08/2020    hao.liu       N/A          QAC and Function
*   01.00.03    27/09/2021    zeyu.Ren      N/A          ETH422_UdpNm_20210927_01
*   01.01.04    22/04/2022    zeyu.ren      N/A          Test problem fixed
*   01.00.05    09/01/2023    shengguo.liu  N/A          Test problem fixed
*   01.00.06    05/05/2023    shengguo.liu  N/A          TPA problem fixed
*   01.00.07    01/06/2023    shengguo.liu  N/A          TPA problem fixed
*   01.00.08    28/11/2023    yuxiu.ling    N/A          Receive packet problem fixed
********************************************************************************
* END_FILE_HDR*/

/*******************************************************************************
*   Includes
*******************************************************************************/                     
#include "UdpNm.h"
#include "SoAd.h"
#include "UdpNm_Cbk.h"
#include "UdpNm_Cfg.h"
#include "ComStack_Types.h"
#include "Nm_Cbk.h"
#include "NmStack_Types.h"
#if(UDPNM_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"
#endif
#if(UDPNM_DEM_ENABLED == STD_ON)
#include "Dem.h"
#endif
#include "SchM_UdpNm.h"
#include "Platform_Types.h"
/*[SWS_UdpNm_00311]*/
#include "SoAd_Cfg.h"
#include "Nm_Cfg.h"
#if((UDPNM_COM_USER_DATA_SUPPORT == STD_ON) || (UDPNM_GLOBAL_PN_SUPPORT == STD_ON))
#include "PduR_UdpNm.h"
#endif

#include "Bsw_Common.h"
#include "UdpNm_Callout.h"

/*Version Check*/
#if(STD_ON == UDPNM_PRIVATE_VERSION_CHECK)
/* check Version with other import module */
/* check Version with cfg file */
#if((UDPNM_AR_RELEASE_MAJOR_VERSION != UDPNM_AR_RELEASE_MAJOR_VERSION_CFG) || \
   (UDPNM_AR_RELEASE_MINOR_VERSION != UDPNM_AR_RELEASE_MINOR_VERSION_CFG))
#error "AutoSar Version Numbers of UdpNm and its cfg file are different"
#endif

#if((UDPNM_SW_MAJOR_VERSION != UDPNM_SW_MAJOR_VERSION_CFG) || \
   (UDPNM_SW_MINOR_VERSION != UDPNM_SW_MINOR_VERSION_CFG))
#error "SW Version Numbers of UdpNm and its cfg file are different"
#endif
#endif

/*Dependency Check*/
/*[SWS_UdpNm_00163]*/
#if(UDPNM_PASSIVE_MODE_ENABLED == STD_ON)
#if(UDPNM_BUS_SYNCHRONIZATION_ENABLED== STD_ON)
#error: "If UDPNM_PASSIVE_MODE_ENABLED == STD_ON then UDPNM_BUS_SYNCHRONIZATION_ENABLED = STD_OFF"
#endif
#if(UDPNM_COM_USER_DATA_SUPPORT == STD_ON)
#error: "If UDPNM_PASSIVE_MODE_ENABLED == STD_ON then UDPNM_COM_USER_DATA_SUPPORT = STD_OFF"
#endif
#if(UDPNM_COORDINATOR_SYNC_SUPPORT == STD_ON)
#error: "If UDPNM_PASSIVE_MODE_ENABLED == STD_ON then UDPNM_COORDINATOR_SYNC_SUPPORT = STD_OFF"
#endif
#if(UDPNM_IMMEDIATE_RESTART_ENABLED == STD_ON)
#error: "If UDPNM_PASSIVE_MODE_ENABLED == STD_ON then UDPNM_IMMEDIATE_RESTART_ENABLED = STD_OFF"
#endif
#if(UDPNM_NODE_ID_ENABLED == STD_OFF)
#if(UDPNM_NODE_DETECTION_ENABLED == STD_ON)
#error: "If UDPNM_PASSIVE_MODE_ENABLED == STD_ON or UDPNM_NODE_ID_ENABLED == STD_OFF\
        then UDPNM_NODE_DETECTION_ENABLED = STD_OFF"
#endif
#endif
#if(UDPNM_REMOTE_SLEEP_IND_ENABLED == STD_ON)
#error: "If UDPNM_PASSIVE_MODE_ENABLED == STD_ON then UDPNM_REMOTE_SLEEP_IND_ENABLED = STD_OFF"
#endif
#endif

#if(STD_ON == UDPNM_DEV_ERROR_DETECT)
#define UDPNM_DET_ERROR_DETECT(cond, ApiId, errcode)  \
        DET_ERROR_DETECT((cond), UDPNM_MODULE_ID, UDPNM_INSTANCE_ID,(ApiId),(errcode))
    
#define UDPNM_DET_ERROR_DETECT_RET(cond, ApiId, errcode, ret) \
        DET_ERROR_DETECT_RET((cond), UDPNM_MODULE_ID,UDPNM_INSTANCE_ID,(ApiId),(errcode), (ret))
    
#define UDPNM_DET_REPORT_ERROR(ApiId, errcode)  \
        DET_REPORT_ERROR(UDPNM_MODULE_ID, UDPNM_INSTANCE_ID, (ApiId), (errcode))    
#else
#define UDPNM_DET_ERROR_DETECT(cond, ApiId, errcode)
#define UDPNM_DET_ERROR_DETECT_RET(cond, ApiId, errcode, ret)
#define UDPNM_DET_REPORT_ERROR(ApiId, errcode)
#endif

#ifdef UDPNM_E_NETWORK_TIMEOUT
#define UDPNM_DEM_REPORT_ERROR_NETWORK_TIMEOUT(state)   \
        Dem_ReportErrorStatus(UDPNM_E_NETWORK_TIMEOUT, (state))    
#else
#define UDPNM_DEM_REPORT_ERROR_NETWORK_TIMEOUT(state)
#endif

#ifdef UDPNM_E_TCPIP_TRANSMIT_ERROR
#define UDPNM_DEM_REPORT_ERROR_TCPIP_TRANSMIT_ERROR(state)   \
        Dem_ReportErrorStatus(UDPNM_E_TCPIP_TRANSMIT_ERROR, (state))    
#else
#define UDPNM_DEM_REPORT_ERROR_TCPIP_TRANSMIT_ERROR(state)
#endif

#define UDPNM_START_SEC_VAR_INIT_8
#include "MemMap.h"
STATIC VAR(Std_InitStateType, UDPNM_VAR_POWER_ON_INIT) UdpNm_InitState = STD_UNINITIALIZED;
#define UDPNM_STOP_SEC_VAR_INIT_8
#include "MemMap.h"

#define UDPNM_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" 
#if(UDPNM_CONFIG_VARIANTS == STD_CONFIG_VARIANTS_POSTBUILD)
STATIC P2CONST(UdpNm_ConfigType, AUTOMATIC, UDPNM_VAR_NOINIT) UdpNm_PBCConfig;
#endif
#define UDPNM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"     

#define UDPNM_USER_DATA_DEFAULT_VALUE                ((uint8)0xFF)
#define UDPNM_ACTIVE_WU_MASK                         ((uint8)0x10)
#define UDPNM_RMB_MASK                               ((uint8)0x01)
#define UDPNM_CAR_WAKEUP_FILTER_ENABLED_MASK         ((uint8)0x01)
#define UDPNM_CAR_WAKEUP_RX_ENABLED_MASK             ((uint8)0x02)

#define UDPNM_PDU_START_INDEX(index)                 UdpNm_LConfig[(index)].UdpNmPduStartIndex
#define UDPNM_PDU_CBV_INDEX(index)                   UdpNm_LConfig[(index)].UdpNmPduCBVIndex
#define UDPNM_PDU_NID_INDEX(index)                   UdpNm_LConfig[(index)].UdpNmPduNIDIndex
#define UDPNM_PDU_LENGTH(index)                      UdpNm_LConfig[(index)].UdpNmPduLength
#if(UDPNM_USER_DATA_ENABLED == STD_ON || UDPNM_COM_USER_DATA_SUPPORT == STD_ON)
#define UDPNM_USER_DATA_LENGTH(index)                UdpNm_LConfig[(index)].UdpNmPduUserDataLength
#define UDPNM_USER_DATA_START_INDEX(index)           UdpNm_LConfig[(index)].UdpNmPduUserDataStartIndex
#endif
#if(UDPNM_PASSIVE_MODE_ENABLED == STD_OFF)
#define UDPNM_TX_PDU_DATA(index)                     (&UdpNm_TxPduData[UDPNM_PDU_START_INDEX(index)])
#define UDPNM_TX_PDU_BYTE(Index)                     UdpNm_TxPduData[Index]
#define UDPNM_TX_PDU_BYTE_CBV(index)                 UdpNm_TxPduData[UDPNM_PDU_CBV_INDEX(index)]
#define UDPNM_TX_PDU_BYTE_NID(index)                 UdpNm_TxPduData[UDPNM_PDU_NID_INDEX(index)]
#if(UDPNM_USER_DATA_ENABLED == STD_ON || UDPNM_COM_USER_DATA_SUPPORT == STD_ON)
#define UDPNM_TX_PDU_BYTE_USER_DATA(Index)           UdpNm_TxPduData[Index]
#endif
#endif
#define UDPNM_RX_PDU_DATA(index)                     (&UdpNm_RxPduData[UDPNM_PDU_START_INDEX(index)])
#define UDPNM_RX_PDU_BYTE(Index)                     UdpNm_RxPduData[(Index)]
#define UDPNM_RX_PDU_BYTE_CBV(index)                 UdpNm_RxPduData[UDPNM_PDU_CBV_INDEX(index)]
#define UDPNM_RX_PDU_BYTE_NID(index)                 UdpNm_RxPduData[UDPNM_PDU_NID_INDEX(index)]
#if(UDPNM_USER_DATA_ENABLED == STD_ON || UDPNM_COM_USER_DATA_SUPPORT == STD_ON)
#define UDPNM_RX_PDU_BYTE_USER_DATA(index)           UdpNm_RxPduData[UDPNM_USER_DATA_START_INDEX(index)]
#endif

/*UdpNm_ChannelConfig*/
#if(UDPNM_PASSIVE_MODE_ENABLED == STD_OFF)
/*ECUC_UdpNm_00084*/
#define UDPNM_ACTIVE_WU_BIT_ENABLED(index)           UdpNm_LConfig[(index)].UdpNmActiveWakeupBitEnabled
#endif
/*ECUC_UdpNm_00074*/
#define UDPNM_CWU_RX_ENABLED(index)                  (UdpNm_LConfig[(index)].UdpNmCarWakeUpFilterEnabled\
                                                                                     & UDPNM_CAR_WAKEUP_RX_ENABLED_MASK)
/*ECUC_UdpNm_00077*/
#define UDPNM_CWU_FILTER_ENABLED(index)              (UdpNm_LConfig[(index)].UdpNmCarWakeUpFilterEnabled\
                                                                                 & UDPNM_CAR_WAKEUP_FILTER_ENABLED_MASK)
/*ECUC_UdpNm_00078*/
#define UDPNM_CWU_FILTER_NODE_ID(index)              UdpNm_LConfig[(index)].UdpNmCarWakeUpFilterNodeId
/*ECUC_UdpNm_00028*/
#define UDPNM_MSG_CYCLE_TIME(index)                  UdpNm_LConfig[(index)].UdpNmMsgCycleTime  
/*ECUC_UdpNm_00029*/
#define UDPNM_MSG_CYCLE_OFFSET(index)                UdpNm_LConfig[(index)].UdpNmMsgCycleOffset
/*ECUC_UdpNm_00030*/
#define UDPNM_TXTO_TIME(index)                       UdpNm_LConfig[(index)].UdpNmMsgTimeoutTime
/*ECUC_UdpNm_00020*/
/*[SWS_UdpNm_00246]*/
#define UDPNM_NMTO_TIME(index)                       UdpNm_LConfig[(index)].UdpNmTimeoutTime
/*ECUC_UdpNm_00021*/
/*[SWS_UdpNm_00248]*/
#define UDPNM_WBS_TIME(index)                        UdpNm_LConfig[(index)].UdpNmWaitBusSleepTime
/*ECUC_UdpNm_00022*/
/*[SWS_UdpNm_00247]*/
#define UDPNM_RPT_MSG_TIME(index)                    UdpNm_LConfig[(index)].UdpNmRepeatMessageTime

/*????*/
#define UDPNM_IMM_NM_TRANS(index)                   UdpNm_LConfig[(index)].UdpNmImmediateNmTransmissions

/*ECUC_UdpNm_00026*/
/*[SWS_UdpNm_00075]*/
#define UDPNM_PDU_CBV_POS(index)                     UdpNm_LConfig[(index)].UdpNmPduCbvPosition
/*ECUC_UdpNm_00025*/
/*[SWS_UdpNm_00074]*/
#define UDPNM_PDU_NID_POS(index)                     UdpNm_LConfig[(index)].UdpNmPduNidPosition
#if(UDPNM_PASSIVE_MODE_ENABLED == STD_OFF)
#if(UDPNM_REMOTE_SLEEP_IND_ENABLED == STD_ON)
/*ECUC_UdpNm_00023*/
/*[SWS_UdpNm_00249]*/
#define UDPNM_RMT_SLP_IND_TIME(index)                UdpNm_LConfig[(index)].UdpNmRemoteSleepIndTime
#endif
#endif

/*ECUC_UdpNm_00018*/
#define UDPNM_COMM_NETWORK_HANDLE(index)             UdpNm_LConfig[(index)].ComMNetworkHandleRef
                                                         
#define UDPNM_GET_NMCHANNELID_FROM_TXPDUID(TxPduId)  UdpNm__GetChannelIdFromTxPdu(TxPduId)

#if(UDPNM_NODE_ID_ENABLED == STD_ON)
/*ECUC_UdpNm_00031*/
#if(UDPNM_CONFIG_VARIANTS == STD_CONFIG_VARIANTS_POSTBUILD)
#define UDPNM_NODE_ID(index)                         (&UdpNm_PBCConfig[(index)])->UdpNmNodeId
#else
#define UDPNM_NODE_ID(index)                         UdpNm_LConfig[(index)].UdpNmNodeId
#endif
#endif 

#if(UDPNM_PASSIVE_MODE_ENABLED == STD_OFF)
#if(UDPNM_CONFIG_VARIANTS == STD_CONFIG_VARIANTS_POSTBUILD)
#define UDPNM_TX_PDU_ID(index)                       (&UdpNm_PBCConfig[(index)])->UdpNmTxPduId
#else
#define UDPNM_TX_PDU_ID(index)                       UdpNm_LConfig[(index)].UdpNmTxPduId
#endif

#if(UDPNM_COM_USER_DATA_SUPPORT == STD_ON)
#if(UDPNM_CONFIG_VARIANTS == STD_CONFIG_VARIANTS_POSTBUILD)
#define UDPNM_USER_DATA_TX_PDU_ID(index)             (&UdpNm_PBCConfig[(index)])->UdpNmUserDataTxPduId
#else
#define UDPNM_USER_DATA_TX_PDU_ID(index)             UdpNm_LConfig[(index)].UdpNmUserDataTxPduId
#endif
#endif
#endif
        
#if(UDPNM_PASSIVE_MODE_ENABLED == STD_OFF)
#define UDPNM_START_MSG_CYC_TIMER(index)             (UdpNm_Timer[(index)].MsgCycTimer = (UDPNM_MSG_CYCLE_TIME(index)))
#define UDPNM_STOP_MSG_CYC_TIMER(index)              (UdpNm_Timer[(index)].MsgCycTimer = (uint16)0)
#define UDPNM_DEC_MSG_CYC_TIMER(index)               (UdpNm_Timer[(index)].MsgCycTimer--)
#define UDPNM_EXP_MSG_CYC_TIMER(index)               (UdpNm_Timer[(index)].MsgCycTimer == (uint16)0)
#define UDPNM_GET_MSG_CYC_TIMER(index)               (UdpNm_Timer[(index)].MsgCycTimer)

#define UDPNM_START_MSG_CYCLE_OFFSET(index)          (UdpNm_Timer[(index)].MsgCycOffsetTimer = (UDPNM_MSG_CYCLE_OFFSET(index)))
#define UDPNM_STOP_MSG_CYCLE_OFFSET(index)           (UdpNm_Timer[(index)].MsgCycOffsetTimer = (uint16)0)
#define UDPNM_DEC_MSG_CYCLE_OFFSET(index)            (UdpNm_Timer[(index)].MsgCycOffsetTimer--)
#define UDPNM_EXP_MSG_CYCLE_OFFSET(index)            (UdpNm_Timer[(index)].MsgCycOffsetTimer == (uint16)0)       
#define UDPNM_GET_MSG_CYCLE_OFFSET(index)            (UdpNm_Timer[(index)].MsgCycOffsetTimer)

#define UDPNM_START_TXTO_TIMER(index)                (UdpNm_Timer[(index)].TxTOTimer = (UDPNM_TXTO_TIME(index)))
#define UDPNM_STOP_TXTO_TIMER(index)                 (UdpNm_Timer[(index)].TxTOTimer = (uint16)0)
#define UDPNM_DEC_TXTO_TIMER(index)                  (UdpNm_Timer[(index)].TxTOTimer--)
#define UDPNM_EXP_TXTO_TIMER(index)                  (UdpNm_Timer[(index)].TxTOTimer == (uint16)0)
#define UDPNM_GET_TXTO_TIMER(index)                  (UdpNm_Timer[(index)].TxTOTimer)      
#endif

#define UDPNM_GET_IMMTRANS(index)                    (UdpNm_ImmTrans[(index)])
#define UDPNM_SET_IMMTRANS(index,num)                (UdpNm_ImmTrans[(index)] = num)
#define UDPNM_DEC_IMMTRANS(index)                    (UdpNm_ImmTrans[(index)] --)

#if(UDPNM_REMOTE_SLEEP_IND_ENABLED == STD_ON)
#define UDPNM_START_RMT_SLP_IND_TIMER(index)         (UdpNm_Timer[(index)].RmtSlpIndTimer = (UDPNM_RMT_SLP_IND_TIME(index)))
#define UDPNM_STOP_RMT_SLP_IND_TIMER(index)          (UdpNm_Timer[(index)].RmtSlpIndTimer = (uint16)0)
#define UDPNM_DEC_RMT_SLP_IND_TIMER(index)           (UdpNm_Timer[(index)].RmtSlpIndTimer--)
#define UDPNM_EXP_RMT_SLP_IND_TIMER(index)           (UdpNm_Timer[(index)].RmtSlpIndTimer == (uint16)0)
#define UDPNM_GET_RMT_SLP_IND_TIMER(index)           (UdpNm_Timer[(index)].RmtSlpIndTimer)       
#endif

/*[SWS_UdpNm_00206]*/
#define UDPNM_START_NMTO_TIMER(index)                (UdpNm_Timer[(index)].NmTOTimer = (UDPNM_NMTO_TIME(index)))
#define UDPNM_STOP_NMTO_TIMER(index)                 (UdpNm_Timer[(index)].NmTOTimer = (uint16)0)
#define UDPNM_DEC_NMTO_TIMER(index)                  (UdpNm_Timer[(index)].NmTOTimer--)
#define UDPNM_EXP_NMTO_TIMER(index)                  (UdpNm_Timer[(index)].NmTOTimer == (uint16)0)
#define UDPNM_GET_NMTO_TIMER(index)                  (UdpNm_Timer[(index)].NmTOTimer)

#define UDPNM_START_WBS_TIMER(index)                 (UdpNm_Timer[(index)].WbsTimer = (UDPNM_WBS_TIME(index)))
#define UDPNM_STOP_WBS_TIMER(index)                  (UdpNm_Timer[(index)].WbsTimer = (uint16)0)
#define UDPNM_DEC_WBS_TIMER(index)                   (UdpNm_Timer[(index)].WbsTimer--)
#define UDPNM_EXP_WBS_TIMER(index)                   (UdpNm_Timer[(index)].WbsTimer == (uint16)0)
#define UDPNM_GET_WBS_TIMER(index)                   (UdpNm_Timer[(index)].WbsTimer)

#define UDPNM_START_RPT_MSG_TIMER(index)             (UdpNm_Timer[(index)].RptMsgTimer = (UDPNM_RPT_MSG_TIME(index)))
#define UDPNM_STOP_RPT_MSG_TIMER(index)              (UdpNm_Timer[(index)].RptMsgTimer = (uint16)0)
#define UDPNM_DEC_RPT_MSG_TIMER(index)               (UdpNm_Timer[(index)].RptMsgTimer--)
#define UDPNM_EXP_RPT_MSG_TIMER(index)               (UdpNm_Timer[(index)].RptMsgTimer == (uint16)0)
#define UDPNM_GET_RPT_MSG_TIMER(index)               (UdpNm_Timer[(index)].RptMsgTimer) 

#define UDPNM_SET_MODE(index, mode)                  (UdpNm_Mode[(index)] = (mode))
#define UDPNM_GET_MODE(index)                        (UdpNm_Mode[(index)])

#define UDPNM_SET_STATE(index, state)                (UdpNm_State[(index)] = (state))
#define UDPNM_GET_STATE(index)                       (UdpNm_State[(index)])

#define UDPNM_SET_NETWORK_STATE(index, state)        (UdpNm_NetworkState[(index)] = (state))
#define UDPNM_GET_NETWORK_STATE(index)               (UdpNm_NetworkState[(index)])

#define UDPNM_SET_NETWORK_REQ_CMD(index, req)        (UdpNm_NetworkReqCmd[(index)] = (req))
#define UDPNM_GET_NETWORK_REQ_CMD(index)             (UdpNm_NetworkReqCmd[(index)])


#if(UDPNM_PASSIVE_MODE_ENABLED == STD_OFF)
#if(UDPNM_NODE_DETECTION_ENABLED == STD_ON)
#define UDPNM_IS_RPT_MSG_REQ(index)                  (UdpNm_RptMsgReq[(index)] == TRUE)
#define UDPNM_SET_RPT_MSG_REQ(index)                 (UdpNm_RptMsgReq[(index)] = TRUE)
#define UDPNM_CLR_RPT_MSG_REQ(index)                 (UdpNm_RptMsgReq[(index)] = FALSE)
#endif

#define UDPNM_IS_TX_PDU_REQ(index)                   (UdpNm_TxReqFlg[(index)] == TRUE)
#define UDPNM_SET_TX_PDU_REQ(index)                  (UdpNm_TxReqFlg[(index)] = TRUE)
#define UDPNM_CLR_TX_PDU_REQ(index)                  (UdpNm_TxReqFlg[(index)] = FALSE)

#define UDPNM_IS_TX_CONF_FLAG(index)                 (UdpNm_TxConfFlg[(index)] == TRUE)
#define UDPNM_SET_TX_CONF_FLAG(index)                (UdpNm_TxConfFlg[(index)] = TRUE)
#define UDPNM_CLR_TX_CONF_FLAG(index)                (UdpNm_TxConfFlg[(index)] = FALSE)

#if(UDPNM_COM_CONTROL_ENABLED == STD_ON)
#define UDPNM_SET_COM_CTRL_REQ(index, state)         (UdpNm_ComCtrlReq[(index)] = (state))
#define UDPNM_GET_COM_CTRL_REQ(index)                (UdpNm_ComCtrlReq[(index)])

#define UDPNM_SET_COM_CTRL_STATE(index, state)       (UdpNm_ComCtrlState[(index)] = (state))
#define UDPNM_GET_COM_CTRL_STATE(index)              (UdpNm_ComCtrlState[(index)])
#endif

#if(UDPNM_REMOTE_SLEEP_IND_ENABLED == STD_ON)
#define UDPNM_IS_RMT_SLP_IND(index)                  (UdpNm_RmtSlpInd[(index)] == TRUE)
#define UDPNM_SET_RMT_SLP_IND(index)                 (UdpNm_RmtSlpInd[(index)] = TRUE)
#define UDPNM_GET_RMT_SLP_IND(index)                 (UdpNm_RmtSlpInd[(index)])
#define UDPNM_CLR_RMT_SLP_IND(index)                 (UdpNm_RmtSlpInd[(index)] = FALSE)
#endif
#endif

#define UDPNM_IS_RX_IND_FLAG(index)                  (UdpNm_RxIndFlg[(index)] == TRUE)
#define UDPNM_SET_RX_IND_FLAG(index)                 (UdpNm_RxIndFlg[(index)] = TRUE)
#define UDPNM_CLR_RX_IND_FLAG(index)                 (UdpNm_RxIndFlg[(index)] = FALSE)

#define UDPNM_SET_RESTART_STATE(index, state)        (UdpNm_RestartState[(index)] = (state))  

/***************************************************************************************
*   PN  Releated
****************************************************************************************/
#if(STD_ON == UDPNM_GLOBAL_PN_SUPPORT)
#define UDPNM_CBV_PN_MASK                               ((uint8)0x40u)
#define UDPNM_GET_PN_RESET_CNT                          (UDPNM_PN_RESET_TIME/UDPNM_MAIN_FUNCTION_PERIOD)

#define UDPNM_PN_ERA_ENABLED(nmChannelHandle)           UdpNm_LConfig[nmChannelHandle].UdpNmPnEraCalcEnabled
#define UDPNM_PN_MULTIPLE_REQ(nmChannelHandle)          UdpNm_LConfig[nmChannelHandle].UdpNmPnHandleMultipleNetworkRequests
#define UDPNM_PN_ERA_RXNSDU_REF(nmChannelHandle)        UdpNm_LConfig[nmChannelHandle].UdpNmPnEraRxNSduRef
#define UDPNM_PN_ENABLED(nmChannelHandle)               UdpNm_LConfig[nmChannelHandle].UdpNmPnEnabled
#define UDPNM_PN_FILTERMASK_BYTE_VALUE(idx)				UdpNm_Config.UdpNmPnFilterMask[idx].UdpNmPnFilterMaskByteValue
#define UDPNM_PN_INFO_LENGTH                            UdpNm_PnInfo.UdpNmPnInfoLength
#define UDPNM_PN_INFO_OFFSET                            UdpNm_PnInfo.UdpNmPnInfoOffset
#endif
/***************************************************************************************
*   Function Declaration
****************************************************************************************/
#define UDPNM_START_SEC_CODE
#include "MemMap.h"
STATIC FUNC(void, UDPNM_CODE) UdpNm__NetworkReqHandling
(
    const NetworkHandleType nmChannelHandle
);
#if(UDPNM_PASSIVE_MODE_ENABLED == STD_OFF)
#if(UDPNM_NODE_DETECTION_ENABLED == STD_ON)
STATIC FUNC(void, UDPNM_CODE) UdpNm__RptMsgReqHandling
(
    const NetworkHandleType nmChannelHandle
);
#endif   
#if(UDPNM_COM_CONTROL_ENABLED == STD_ON)
STATIC FUNC(void, UDPNM_CODE) UdpNm__ComCtrlHandling
(
    const NetworkHandleType nmChannelHandle
);
#endif
#endif
STATIC FUNC(void, UDPNM_CODE) UdpNm__TimerHandling
(
    const NetworkHandleType nmChannelHandle
);
STATIC FUNC(void, UDPNM_CODE) UdpNm__TxConfHandling
(
    const NetworkHandleType nmChannelHandle
);
STATIC FUNC(void, UDPNM_CODE) UdpNm__RxIndHandling
(
    const NetworkHandleType nmChannelHandle
);
/*[SWS_UdpNm_00072]*/
#if(UDPNM_PASSIVE_MODE_ENABLED == STD_OFF)
STATIC FUNC(void, UDPNM_CODE) UdpNm__TxPduHandling
(
    const NetworkHandleType nmChannelHandle
);
STATIC FUNC(void, UDPNM_CODE) UdpNm__MsgCycTimerProcess
(
    const NetworkHandleType nmChannelHandle
);
STATIC FUNC(void, UDPNM_CODE) UdpNm__MsgCycOffsetProcess
(
    const NetworkHandleType nmChannelHandle
);
STATIC FUNC(void, UDPNM_CODE) UdpNm__TxTOTimerProcess
(
    const NetworkHandleType nmChannelHandle
);
#endif

STATIC FUNC(void, UDPNM_CODE) UdpNm__NmTOTimerProcess
(
    const NetworkHandleType nmChannelHandle
);
STATIC FUNC(void, UDPNM_CODE) UdpNm__WbsTimerProcess
(
    const NetworkHandleType nmChannelHandle
);
STATIC FUNC(void, UDPNM_CODE) UdpNm__RptMsgTimerProcess
(
    const NetworkHandleType nmChannelHandle
);
#if(UDPNM_PASSIVE_MODE_ENABLED == STD_OFF)
#if(UDPNM_REMOTE_SLEEP_IND_ENABLED == STD_ON)
STATIC FUNC(void, UDPNM_CODE) UdpNm__RmtSlpIndTimerProcess
(
    const NetworkHandleType nmChannelHandle
);
#endif
#endif
STATIC FUNC(void, UDPNM_CODE) UdpNm__RptMsgStateTransition
(
    const NetworkHandleType nmChannelHandle
);
STATIC FUNC(void, UDPNM_CODE) UdpNm__NormalOpStateTransition
(
    const NetworkHandleType nmChannelHandle
);
STATIC FUNC(void, UDPNM_CODE) UdpNm__RdySlpStateTransition
(
    const NetworkHandleType nmChannelHandle
);
STATIC FUNC(void, UDPNM_CODE) UdpNm__NetworkModeTransition
(
    const NetworkHandleType nmChannelHandle
);
STATIC FUNC(void, UDPNM_CODE) UdpNm__PreBusSlpModeTransition
(
    const NetworkHandleType nmChannelHandle
);
STATIC FUNC(void, UDPNM_CODE) UdpNm__BusSlpModeTransition
(
    const NetworkHandleType nmChannelHandle
);
#if(STD_ON == UDPNM_GLOBAL_PN_SUPPORT)
#if(STD_ON == UDPNM_PN_EIRA_CALC_ENABLED)
STATIC FUNC(void, UDPM_CODE) UdpNm_PnEiraHandling
(
    const NetworkHandleType nmChannelHandle
);
#endif
STATIC FUNC(void, UDPNM_CODE) UdpNm_PnEraHandling
(
    const NetworkHandleType nmChannelHandle
);
#endif
STATIC FUNC(NetworkHandleType, UDPNM_CODE) UdpNm__GetChannelIdFromTxPdu
(
    const PduIdType PduId
);
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: UdpNm_Init
*                
* Description:   Initialize the complete UdpNm module. 
*                             
* Inputs:        UdpNmConfigPtr: Pointer to a selected configuration structure.
*             
* Outputs:       None
* 
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, UDPNM_CODE) UdpNm_Init
( 
    P2CONST(UdpNm_ConfigType, AUTOMATIC, UDPNM_APPL_DATA) UdpNmConfigPtr 
)
{
    NetworkHandleType nmChannelHandle;
#if(UDPNM_USER_DATA_ENABLED == STD_ON || UDPNM_GLOBAL_PN_SUPPORT == STD_ON)  
    uint8 i = 0;
#if(UDPNM_GLOBAL_PN_SUPPORT == STD_ON)
    uint8 j = 0;
#endif
#endif

#if(UDPNM_CONFIG_VARIANTS == STD_CONFIG_VARIANTS_POSTBUILD)    
    /*[SWS_UdpNm_00244]*/
    if(NULL_PTR == UdpNmConfigPtr)
    {
        UDPNM_DET_REPORT_ERROR(UDPNM_API_ID_INIT, UDPNM_E_PARAM_POINTER);
    }
    else
#else
    (void)UdpNmConfigPtr;
#endif
    {
#if(UDPNM_CONFIG_VARIANTS == STD_CONFIG_VARIANTS_POSTBUILD) 
        /*[SWS_UdpNm_00060]*/
        UdpNm_PBCConfig = UdpNmConfigPtr;
#endif
        for(nmChannelHandle = (uint8)0; nmChannelHandle < UDPNM_NUMBER_OF_CHANNELS; nmChannelHandle++)
        {        
            /*[SWS_UdpNm_00141]*/
            UDPNM_SET_STATE(nmChannelHandle, NM_STATE_BUS_SLEEP);
            /*[SWS_UdpNm_00144]*/
            UDPNM_SET_MODE(nmChannelHandle, NM_MODE_BUS_SLEEP);
            /*[SWS_UdpNm_00143]*/
            UDPNM_SET_NETWORK_STATE(nmChannelHandle,UDPNM_NETWORK_RELEASED);            
            UDPNM_SET_NETWORK_REQ_CMD(nmChannelHandle, UDPNM_NULL_CMD);

            UDPNM_STOP_RPT_MSG_TIMER(nmChannelHandle);

#if(UDPNM_PASSIVE_MODE_ENABLED == STD_OFF)
#if(UDPNM_NODE_DETECTION_ENABLED == STD_ON)
            UDPNM_CLR_RPT_MSG_REQ(nmChannelHandle); 
#endif

#if(UDPNM_COM_CONTROL_ENABLED == STD_ON)
            UDPNM_SET_COM_CTRL_REQ(nmChannelHandle, UDPNM_COM_ENABLED);
            UDPNM_SET_COM_CTRL_STATE(nmChannelHandle, UDPNM_COM_ENABLED);
#endif
            UDPNM_STOP_MSG_CYCLE_OFFSET(nmChannelHandle);            
            /*[SWS_UdpNm_00061]*/
            UDPNM_STOP_MSG_CYC_TIMER(nmChannelHandle);
            UDPNM_STOP_TXTO_TIMER(nmChannelHandle);

            UDPNM_CLR_TX_PDU_REQ(nmChannelHandle);
            UDPNM_CLR_TX_CONF_FLAG(nmChannelHandle);
            UdpNm_TxPdu[nmChannelHandle].SduLength = UDPNM_PDU_LENGTH(nmChannelHandle);
            UdpNm_TxPdu[nmChannelHandle].SduDataPtr = (SduDataPtrType)UDPNM_TX_PDU_DATA(nmChannelHandle);
            
#if(UDPNM_REMOTE_SLEEP_IND_ENABLED == STD_ON)
            UDPNM_CLR_RMT_SLP_IND(nmChannelHandle);
            UDPNM_STOP_RMT_SLP_IND_TIMER(nmChannelHandle);
#endif

#if(UDPNM_NODE_ID_ENABLED == STD_ON)
            if(UDPNM_PDU_OFF != UDPNM_PDU_NID_POS(nmChannelHandle))
            {
                /*[SWS_UdpNm_00013]*/
                UDPNM_TX_PDU_BYTE_NID(nmChannelHandle) = UDPNM_NODE_ID(nmChannelHandle); 
            }
#endif
            
            if(UDPNM_PDU_OFF != UDPNM_PDU_CBV_POS(nmChannelHandle))
            {
                /*[SWS_UdpNm_00085]*/
                UDPNM_TX_PDU_BYTE_CBV(nmChannelHandle)= 0x00u;    
            }
#if(UDPNM_USER_DATA_ENABLED == STD_ON)
            /*[SWS_UdpNm_00025]*/
            for(i = UDPNM_USER_DATA_START_INDEX(nmChannelHandle); i < (UDPNM_USER_DATA_START_INDEX(nmChannelHandle) + 
                                                                       UDPNM_USER_DATA_LENGTH(nmChannelHandle)); i++)
            {
                UDPNM_TX_PDU_BYTE_USER_DATA(i) = UDPNM_USER_DATA_DEFAULT_VALUE;      
            }  
#endif
#endif
            UDPNM_STOP_NMTO_TIMER(nmChannelHandle);
            UDPNM_STOP_WBS_TIMER(nmChannelHandle);

            UDPNM_CLR_RX_IND_FLAG(nmChannelHandle);
            UdpNm_RxPdu[nmChannelHandle].SduLength = (uint16)0;
            UdpNm_RxPdu[nmChannelHandle].SduDataPtr = (SduDataPtrType)UDPNM_RX_PDU_DATA(nmChannelHandle);

#if(STD_ON == UDPNM_GLOBAL_PN_SUPPORT)                          
            for(i = (uint8)0; i < UDPNM_PN_INFO_LENGTH; i++)
            {                
                UdpNm_PnEraArray[nmChannelHandle][i] = (uint8)0;
                UdpNm_PnEraNewReq[nmChannelHandle][i] = (uint8)0;
                for(j = (uint8)0; j < (uint8)UDPNM_NUMBER_8; j++)
                {
                    UdpNm_PnEraPnTimer[nmChannelHandle][(i * (uint8)UDPNM_NUMBER_8) + j] = (uint16)0;
                }
            }
#endif

        }
#if(STD_ON == UDPNM_GLOBAL_PN_SUPPORT)
#if(STD_ON == UDPNM_PN_EIRA_CALC_ENABLED)
        for(i = (uint8)0; i < UDPNM_PN_INFO_LENGTH; i++)
        {            
            UdpNm_PnEiraArray[i] = (uint8)0;
            UdpNm_PnEiraNewReq[i] = (uint8)0;
            for(j = (uint8)0; j < (uint8)8; j++)
            {
                UdpNm_PnEiraPnTimer[(i * 8) + j] = (uint8)0;
            }
        }
#endif
#endif

        UdpNm_InitState = STD_INITIALIZED;
    }
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: UdpNm_MainFunction
*                
* Description:   Local mainfunction that processes all the internal state transition.
*                             
* Inputs:        nmChannelHandle: Identification of the NM-channel.
*             
* Outputs:       None
* 
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, UDPNM_CODE) UdpNm_MainFunction
(
    const NetworkHandleType nmChannelHandle
)
{
	/*[SWS_UdpNm_00244]*/
    if(STD_UNINITIALIZED == UdpNm_InitState)
    {
        /*[SWS_UdpNm_00039]*//*[SWS_UdpNm_00191]*/
        UDPNM_DET_REPORT_ERROR(UDPNM_API_ID_MAINFUNC, UDPNM_E_NO_INIT);     
    }
    else
    {
        UdpNm__TimerHandling(nmChannelHandle);
        UdpNm__NetworkReqHandling(nmChannelHandle);
#if(UDPNM_PASSIVE_MODE_ENABLED == STD_OFF) 
#if(UDPNM_COM_CONTROL_ENABLED == STD_ON)
        UdpNm__ComCtrlHandling(nmChannelHandle);           
#endif
#if(UDPNM_NODE_DETECTION_ENABLED == STD_ON)
        UdpNm__RptMsgReqHandling(nmChannelHandle);
#endif
#endif
        UdpNm__RxIndHandling(nmChannelHandle);
#if(UDPNM_PASSIVE_MODE_ENABLED == STD_OFF)            
        UdpNm__TxConfHandling(nmChannelHandle);
        UdpNm__TxPduHandling(nmChannelHandle);
#endif

#if(STD_ON == UDPNM_GLOBAL_PN_SUPPORT)
#if(STD_ON == UDPNM_PN_EIRA_CALC_ENABLED)
        UdpNm_PnEiraHandling(nmChannelHandle);
#endif
        if((boolean)STD_ON == UDPNM_PN_ERA_ENABLED(nmChannelHandle))
        {
            UdpNm_PnEraHandling(nmChannelHandle);
        }
#endif            
    }
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: UdpNm_SoAdIfTxConfirmation
*                
* Description:   The lower layer communication interface module confirms the 
*                transmission of an IPDU.
*                             
* Inputs:        TxPduId: ID of the I-PDU that has been transmitted.
*             
* Outputs:       None
* 
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, UDPNM_CODE) UdpNm_SoAdIfTxConfirmation
(
    PduIdType TxPduId
)
{
#if(UDPNM_PASSIVE_MODE_ENABLED == STD_OFF)
    NetworkHandleType nmChannelHandle;
    nmChannelHandle = TxPduId;

  	/*[SWS_UdpNm_00244]*//*[SWS_UdpNm_00229]*/
    if(STD_UNINITIALIZED == UdpNm_InitState)
    {
        /*[SWS_UdpNm_00039]*//*[SWS_UdpNm_00191]*/
        UDPNM_DET_REPORT_ERROR(UDPNM_API_ID_TXCFM, UDPNM_E_NO_INIT);
    }	
    else if(nmChannelHandle >= UDPNM_NUMBER_OF_CHANNELS)
    {
        UDPNM_DET_REPORT_ERROR(UDPNM_API_ID_TXCFM, UDPNM_E_INVALID_CHANNEL);
    }      
    else if(TxPduId >= (PduIdType)UDPNM_NUMBER_OF_TXPDUID)
    {
        UDPNM_DET_REPORT_ERROR(UDPNM_API_ID_TXCFM, UDPNM_E_INVALID_PDUID);
    } 
    else
    {    
        if(0xFF != nmChannelHandle)
        {
            UDPNM_SET_TX_CONF_FLAG(nmChannelHandle);
#if(UDPNM_COM_USER_DATA_SUPPORT == STD_ON)
            PduR_UdpNmTxConfirmation(UDPNM_USER_DATA_TX_PDU_ID(nmChannelHandle));
#endif
        }    
    }
#else
    (void)TxPduId;
#endif
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: UdpNm_SoAdIfRxIndication
*                
* Description:   Indication of a received I-PDU from a lower layer communication 
*                interface module.
*                             
* Inputs:        RxPduId: ID of the received I-PDU.
*                PduInfoPtr:  Contains the length (SduLength) of the received 
*                             I-PDU and a pointer to a buffer (SduDataPtr) 
*                             containing the I-PDU.
*             
* Outputs:       None
* 
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, UDPNM_CODE) UdpNm_SoAdIfRxIndication 
(
    PduIdType RxPduId,
    P2CONST(PduInfoType, AUTOMATIC, UDPNM_APPL_DATA) PduInfoPtr 
)
{
    NetworkHandleType nmChannelHandle = RxPduId;
    boolean DropRxPduFlag = TRUE;
#if(STD_ON == UDPNM_GLOBAL_PN_SUPPORT)
    uint8 Rx_CBV;
    uint8 i;
    uint8 PnMask;
    uint8 ReqPn;
#endif    
    
    /*[SWS_UdpNm_00232]*//*[SWS_UdpNm_00244]*/
    if(STD_UNINITIALIZED == UdpNm_InitState)
    {
        /*[SWS_UdpNm_00039]*//*[SWS_UdpNm_00191]*/
        UDPNM_DET_REPORT_ERROR(UDPNM_API_ID_RXIND, UDPNM_E_NO_INIT);
    }
    else if(nmChannelHandle >= UDPNM_NUMBER_OF_CHANNELS)
    {
        /*[SWS_UdpNm_00192]*/
        UDPNM_DET_REPORT_ERROR(UDPNM_API_ID_RXIND, UDPNM_E_INVALID_CHANNEL);    
    }
    else if(NULL_PTR == PduInfoPtr)
    {
        UDPNM_DET_REPORT_ERROR(UDPNM_API_ID_RXIND, UDPNM_E_PARAM_POINTER);
    }
    else if(UdpNm_LConfig[nmChannelHandle].UdpNmPduLength < (PduInfoPtr->SduLength))
    {
        /*do nothing*/
    }
#if(STD_ON == UDPNM_GLOBAL_PN_SUPPORT)
    else if((boolean)STD_ON == UDPNM_PN_ENABLED(nmChannelHandle))
    {
        Rx_CBV = (PduInfoPtr->SduDataPtr[UDPNM_PDU_CBV_POS(nmChannelHandle)]);

        if((Rx_CBV & UDPNM_CBV_PN_MASK) != UDPNM_CBV_PN_MASK)
        {            
            /*Ignore the received NM-PDU*/
        }        
        else
        {
            for(i = (uint8)0; i < UDPNM_PN_INFO_LENGTH; i++)
            {
                PnMask = UDPNM_PN_FILTERMASK_BYTE_VALUE(i);
                ReqPn = (PduInfoPtr->SduDataPtr[UDPNM_PN_INFO_OFFSET + i]);
                if((PnMask & ReqPn) != (uint8)0)
                {
                    DropRxPduFlag = FALSE;
#if(STD_ON == UDPNM_PN_EIRA_CALC_ENABLED)
                    UdpNm_PnEiraNewReq[i] |= (PnMask & ReqPn);
#endif                    
                    if((boolean)STD_ON == UDPNM_PN_ERA_ENABLED(nmChannelHandle))
                    {
                        UdpNm_PnEraNewReq[nmChannelHandle][i] |= (PnMask & ReqPn);
                    }
                }
            }
        }
    }
#endif
    else
    {
        DropRxPduFlag = FALSE;
    }

    if(DropRxPduFlag == FALSE)
    {        
        UDPNM_SET_RX_IND_FLAG(nmChannelHandle);
            
        /*[SWS_UdpNm_00035]*/
        UdpNm_RxPdu[nmChannelHandle].SduLength = PduInfoPtr->SduLength;
        SchM_Enter_UdpNm_UDPNM_EXCLUSIVE_AREA_0();
        Bsw_MemCpy(UdpNm_RxPdu[nmChannelHandle].SduDataPtr, PduInfoPtr->SduDataPtr, (uint32)PduInfoPtr->SduLength);
        SchM_Exit_UdpNm_UDPNM_EXCLUSIVE_AREA_0(); 
        
        if(NM_MODE_BUS_SLEEP == UdpNm_Mode[nmChannelHandle])
        {
            Nm_NetworkStartIndication(UDPNM_COMM_NETWORK_HANDLE(nmChannelHandle));                       
        }
        
#if(UDPNM_PDU_RX_INDICATION_ENABLED == STD_ON)
        Nm_PduRxIndication(UDPNM_COMM_NETWORK_HANDLE(nmChannelHandle));
#endif

#if(UDPNM_PASSIVE_MODE_ENABLED == STD_OFF)
#if(UDPNM_NODE_DETECTION_ENABLED == STD_ON)
        if((UDPNM_PDU_OFF != (UDPNM_PDU_CBV_POS(nmChannelHandle)))
                && (0x00 != (UDPNM_RX_PDU_BYTE_CBV(nmChannelHandle) & UDPNM_RMB_MASK)))
        {                       
#if(UDPNM_REPEAT_MSG_IND_ENABLED == STD_ON)
            Nm_RepeatMessageIndication(UDPNM_COMM_NETWORK_HANDLE(nmChannelHandle));
#endif
        }
#endif
#endif

    }
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: UdpNm_GetState
*                
* Description:   Returns the state and the mode of the network management.
*                             
* Inputs:        nmChannelHandle: Identification of the NM-channel.
*             
* Outputs:       nmStatePtr: Pointer where state of the network management shall 
*                            be copied to.
*                nmModePtr: Pointer where the mode of the network management 
*                           shall be copied to.
* 
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, UDPNM_CODE) UdpNm_GetState
(
    NetworkHandleType nmChannelHandle, 
    P2VAR(Nm_StateType, AUTOMATIC, UDPNM_APPL_DATA) nmStatePtr,
    P2VAR(Nm_ModeType, AUTOMATIC, UDPNM_APPL_DATA) nmModePtr
)
{
    Std_ReturnType ret = E_NOT_OK;

    /*[SWS_UdpNm_00244]*/
    if(STD_UNINITIALIZED == UdpNm_InitState)
    {
	    /*[SWS_UdpNm_00039]*//*[SWS_UdpNm_00191]*/
        UDPNM_DET_REPORT_ERROR(UDPNM_API_ID_GETSTATE, UDPNM_E_NO_INIT);	  
    }
    else if(nmChannelHandle >= UDPNM_NUMBER_OF_CHANNELS)
    {
        /*[SWS_UdpNm_00192]*/
        UDPNM_DET_REPORT_ERROR(UDPNM_API_ID_GETSTATE, UDPNM_E_INVALID_CHANNEL);    
    } 
    else if((NULL_PTR == nmStatePtr) || (NULL_PTR == nmModePtr))
    {
        UDPNM_DET_REPORT_ERROR(UDPNM_API_ID_GETSTATE, UDPNM_E_PARAM_POINTER);  
    }
    else
    {
        SchM_Enter_UdpNm_UDPNM_EXCLUSIVE_AREA_1(); 
        *nmStatePtr = UDPNM_GET_STATE(nmChannelHandle);
        *nmModePtr = UDPNM_GET_MODE(nmChannelHandle);
        SchM_Exit_UdpNm_UDPNM_EXCLUSIVE_AREA_1();
        ret = E_OK;
    }
    return ret;
}

#if(UDPNM_VERSION_INFO_API == STD_ON)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: UdpNm_GetVersionInfo
*                
* Description:   Get the version of UdpNm module. 
*                             
* Inputs:        None
*             
* Outputs:       VersionInfoPtr: Pointer to store version information.                                   
* 
* Limitations:   
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, UDPNM_CODE) UdpNm_GetVersionInfo
(
    P2VAR(Std_VersionInfoType, AUTOMATIC, UDPNM_APPL_DATA) versioninfo
)
{
        /*[SWS_UdpNm_00244]*/   
    if(STD_UNINITIALIZED == UdpNm_InitState)
    {
	    /*[SWS_UdpNm_00039]*//*[SWS_UdpNm_00191]*/
        UDPNM_DET_REPORT_ERROR(UDPNM_API_ID_GETSTATE, UDPNM_E_NO_INIT);	  
    }
    else if(NULL_PTR == versioninfo)
    {
        /*[SWS_UdpNm_00318]*/
        UDPNM_DET_REPORT_ERROR(UDPNM_API_ID_GETVERSIONINFO, UDPNM_E_PARAM_POINTER);    
    }
    else
    {
        versioninfo->vendorID = UDPNM_VENDOR_ID;
        versioninfo->moduleID = (uint16)UDPNM_MODULE_ID;
        versioninfo->sw_major_version = (uint8)UDPNM_SW_MAJOR_VERSION;
        versioninfo->sw_minor_version = (uint8)UDPNM_SW_MINOR_VERSION;
        versioninfo->sw_patch_version = (uint8)UDPNM_SW_PATCH_VERSION;
    }
}
#endif

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: UdpNm_NetworkRequest
*                
* Description:   Request the network, since ECU needs to communicate on the bus. 
*                             
* Inputs:        nmChannelHandle: Identification of the NM-channel.
*             
* Outputs:       None   
* 
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, UDPNM_CODE) UdpNm_NetworkRequest
(
    NetworkHandleType nmChannelHandle
)
{
/*[SWS_UdpNm_00257]*/
#if(UDPNM_PASSIVE_MODE_ENABLED == STD_OFF)
    Std_ReturnType ret = E_NOT_OK;
    
    /*[SWS_UdpNm_00244]*/
    if(STD_UNINITIALIZED == UdpNm_InitState)
    {
        /*[SWS_UdpNm_00039]*//*[SWS_UdpNm_00191]*/
        UDPNM_DET_REPORT_ERROR(UDPNM_API_ID_NETWORKREQUEST, UDPNM_E_NO_INIT);
    }
    else if(nmChannelHandle >= UDPNM_NUMBER_OF_CHANNELS)
    {
        /*[SWS_UdpNm_00192]*/
        UDPNM_DET_REPORT_ERROR(UDPNM_API_ID_NETWORKREQUEST, UDPNM_E_INVALID_CHANNEL);
    } 
    else
    {
        UDPNM_SET_NETWORK_REQ_CMD(nmChannelHandle, UDPNM_NETWORK_REQUEST_CMD);
        UDPNM_SET_RESTART_STATE(nmChannelHandle, UDPNM_ACTIVE_RESTART);
        ret = E_OK; 
    }
    return ret;
#endif
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: UdpNm_PassiveStartUp
*                
* Description:   Passive startup of the AUTOSAR UdpNm. 
*                It triggers the transition from Bus-Sleep Mode or Prepare Bus 
*                Sleep Mode to the Network Mode in Repeat Message State.
*                             
* Inputs:        nmChannelHandle: Identification of the NM-channel.
*             
* Outputs:       None
* 
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, UDPNM_CODE) UdpNm_PassiveStartUp
(
    NetworkHandleType nmChannelHandle
)
{
    Std_ReturnType ret = E_NOT_OK;
    
    /*[SWS_UdpNm_00244]*/
    if(STD_UNINITIALIZED == UdpNm_InitState)
    {
        /*[SWS_UdpNm_00039]*//*[SWS_UdpNm_00191]*/
        UDPNM_DET_REPORT_ERROR(UDPNM_API_ID_PASSIVESTARTUP, UDPNM_E_NO_INIT);                 
    }   
    else if(nmChannelHandle >= UDPNM_NUMBER_OF_CHANNELS)
    {
        /*[SWS_UdpNm_00192]*/
        UDPNM_DET_REPORT_ERROR(UDPNM_API_ID_PASSIVESTARTUP, UDPNM_E_INVALID_CHANNEL);                  
    }    
	/*[SWS_UdpNm_00147]*/
    else if(NM_MODE_NETWORK != UDPNM_GET_MODE(nmChannelHandle))
    {
        UDPNM_SET_NETWORK_REQ_CMD(nmChannelHandle, UDPNM_PASSIVE_STARTUP_CMD);
        UDPNM_SET_RESTART_STATE(nmChannelHandle, UDPNM_PASSIVE_RESTART);
        ret = E_OK;
    } 
    else
    {
		/* do nothing */
    }
    return ret;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: UdpNm_NetworkRelease
*                
* Description:   Release the network. 
*                             
* Inputs:        nmChannelHandle: Identification of the NM-channel.
*             
* Outputs:       None
* 
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, UDPNM_CODE) UdpNm_NetworkRelease
(
    NetworkHandleType nmChannelHandle
)
{
/*[SWS_UdpNm_00260]*/
#if(UDPNM_PASSIVE_MODE_ENABLED == STD_OFF)
    Std_ReturnType ret = E_NOT_OK;

	/*[SWS_UdpNm_00244]*/
    if(STD_UNINITIALIZED == UdpNm_InitState)
    {
        /*[SWS_UdpNm_00039]*//*[SWS_UdpNm_00191]*/
        UDPNM_DET_REPORT_ERROR(UDPNM_API_ID_NETWORKRELEASE, UDPNM_E_NO_INIT);
    }    
    else if(nmChannelHandle >= UDPNM_NUMBER_OF_CHANNELS)
    {
        /*[SWS_UdpNm_00192]*/
        UDPNM_DET_REPORT_ERROR(UDPNM_API_ID_NETWORKRELEASE, UDPNM_E_INVALID_CHANNEL);
    }
    else
    {
        UDPNM_SET_NETWORK_REQ_CMD(nmChannelHandle, UDPNM_NETWORK_RELEASE_CMD);
        ret = E_OK;
    }    
    return ret;
#endif
}

/*[SWS_UdpNm_00158]*/
#if(UDPNM_USER_DATA_ENABLED == STD_ON)
/*[SWS_UdpNm_00266]*/
#if(UDPNM_PASSIVE_MODE_ENABLED == STD_OFF)
/*[SWS_UdpNm_00312]*/
#if(UDPNM_COM_USER_DATA_SUPPORT == STD_OFF)
/*[SWS_UdpNm_00217]*/
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: UdpNm_SetUserData
*                
* Description:   Set user data for all NM messages transmitted on the bus.
*                             
* Inputs:        nmChannelHandle: Identification of the NM-channel.
*                nmUserDataPtr: Pointer where the user data for the next 
*                               transmitted NM message shall be copied from.
*             
* Outputs:       None
* 
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, UDPNM_CODE) UdpNm_SetUserData
(
    NetworkHandleType nmChannelHandle, 
    P2CONST(uint8, AUTOMATIC, UDPNM_APPL_DATA) nmUserDataPtr
)
{
    Std_ReturnType ret = E_NOT_OK;
  
  	/*[SWS_UdpNm_00244]*/
    if(STD_UNINITIALIZED == UdpNm_InitState)
    {
        /*[SWS_UdpNm_00039]*//*[SWS_UdpNm_00191]*/
        UDPNM_DET_REPORT_ERROR(UDPNM_API_ID_SETUSERDATA, UDPNM_E_NO_INIT);
    }    
    else if(nmChannelHandle >= UDPNM_NUMBER_OF_CHANNELS)
    {
        /*[SWS_UdpNm_00192]*/
        UDPNM_DET_REPORT_ERROR(UDPNM_API_ID_SETUSERDATA, UDPNM_E_INVALID_CHANNEL);    
    }
    else if(NULL_PTR == nmUserDataPtr)
    {
        UDPNM_DET_REPORT_ERROR(UDPNM_API_ID_SETUSERDATA, UDPNM_E_PARAM_POINTER);    
    }
    else if(UDPNM_IS_TX_PDU_REQ(nmChannelHandle))
    {
		/* wait for transmit completed and return E_NOT_OK */
    }
    else
    {
        SchM_Enter_UdpNm_UDPNM_EXCLUSIVE_AREA_2();
        /*[SWS_UdpNm_00159]*/
        UdpNm_SetUserDataCall(&UDPNM_TX_PDU_BYTE_USER_DATA(UDPNM_USER_DATA_START_INDEX(nmChannelHandle)), nmUserDataPtr, UDPNM_USER_DATA_LENGTH(nmChannelHandle));
        SchM_Exit_UdpNm_UDPNM_EXCLUSIVE_AREA_2();
        ret = E_OK;
    }
    return ret;
}
#endif 
#endif

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: UdpNm_GetUserData
*                
* Description:   Get user data from the most recently received NM message.
*                             
* Inputs:        nmChannelHandle: Identification of the NM-channel.
*             
* Outputs:       nmUserDataPtr: Pointer where user data out of the most recently
*                               received NM message shall be copied to.
* 
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, UDPNM_CODE) UdpNm_GetUserData
(
    NetworkHandleType nmChannelHandle, 
    P2VAR(uint8, AUTOMATIC, UDPNM_APPL_DATA) nmUserDataPtr
)
{
    Std_ReturnType ret = E_NOT_OK;

  	/*[SWS_UdpNm_00244]*/
    if(STD_UNINITIALIZED == UdpNm_InitState)
    {
        /*[SWS_UdpNm_00039]*//*[SWS_UdpNm_00191]*/
        UDPNM_DET_REPORT_ERROR(UDPNM_API_ID_GETUSERDATA, UDPNM_E_NO_INIT);	 
    }	
    else if(nmChannelHandle >= UDPNM_NUMBER_OF_CHANNELS)
    {
        /*[SWS_UdpNm_00192]*/
        UDPNM_DET_REPORT_ERROR(UDPNM_API_ID_GETUSERDATA, UDPNM_E_INVALID_CHANNEL);    
    } 
    else if(NULL_PTR == nmUserDataPtr)
    {
        UDPNM_DET_REPORT_ERROR(UDPNM_API_ID_GETUSERDATA, UDPNM_E_PARAM_POINTER);    
    }
    else
    {
        SchM_Enter_UdpNm_UDPNM_EXCLUSIVE_AREA_3();
        /*[SWS_UdpNm_00160]*/
        UdpNm_GetUserDataCall(&UDPNM_RX_PDU_BYTE_USER_DATA(nmChannelHandle), nmUserDataPtr, UDPNM_USER_DATA_LENGTH(nmChannelHandle));
        SchM_Exit_UdpNm_UDPNM_EXCLUSIVE_AREA_3();
        ret = E_OK;
    }
    return ret;
}
#endif

/*[SWS_UdpNm_00168]*/
#if(UDPNM_COM_CONTROL_ENABLED == STD_ON)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: UdpNm_DisableCommunication
*                
* Description:   Disable the NM PDU transmission ability due to a ISO14229
*                Communication Control (0x28) service.
*                             
* Inputs:        nmChannelHandle: Identification of the NM-channel.
*             
* Outputs:       None
* 
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, UDPNM_CODE) UdpNm_DisableCommunication
(
    NetworkHandleType nmChannelHandle
)
{
    Std_ReturnType ret = E_NOT_OK;
    
/*[SWS_UdpNm_00306]*/    
#if(UDPNM_PASSIVE_MODE_ENABLED == STD_OFF)
    if(STD_UNINITIALIZED == UdpNm_InitState)
    {
        /*[SWS_UdpNm_00039]*//*[SWS_UdpNm_00191]*/
        UDPNM_DET_REPORT_ERROR(UDPNM_API_ID_DISABLECOMM, UDPNM_E_NO_INIT);
    }
    /*[SWS_UdpNm_00244]*/
    else if(nmChannelHandle >= UDPNM_NUMBER_OF_CHANNELS)
    {
        /*[SWS_UdpNm_00192]*/
        UDPNM_DET_REPORT_ERROR(UDPNM_API_ID_DISABLECOMM, UDPNM_E_INVALID_CHANNEL);
    }     
  	/*[SWS_UdpNm_00172]*/
    else if((NM_MODE_NETWORK == UDPNM_GET_MODE(nmChannelHandle))
             && (UDPNM_COM_ENABLED == UDPNM_GET_COM_CTRL_REQ(nmChannelHandle)))
    {
        /*[SWS_UdpNm_00170]*/
        UDPNM_SET_COM_CTRL_REQ(nmChannelHandle, UDPNM_COM_DISABLED);
        ret = E_OK;
    }
    else
    {
        /* do nothing */
    }
#endif
    return ret;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: UdpNm_EnableCommunication
*                
* Description:   Enable the NM PDU transmission ability due to a ISO14229 
*                Communication Control (0x28) service.
*                             
* Inputs:        nmChannelHandle: Identification of the NM-channel.       
*             
* Outputs:       None
* 
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, UDPNM_CODE) UdpNm_EnableCommunication
(
    NetworkHandleType nmChannelHandle
)
{
    Std_ReturnType ret = E_NOT_OK;
    
/*[SWS_UdpNm_00307]*/
#if(UDPNM_PASSIVE_MODE_ENABLED == STD_OFF)
    if(STD_UNINITIALIZED == UdpNm_InitState)
    {
        /*[SWS_UdpNm_00039]*//*[SWS_UdpNm_00191]*/
        UDPNM_DET_REPORT_ERROR(UDPNM_API_ID_ENABLECOMM, UDPNM_E_NO_INIT);    
    }
    /*[SWS_UdpNm_00244]*/
    else if(nmChannelHandle >= UDPNM_NUMBER_OF_CHANNELS)
    {
        /*[SWS_UdpNm_00192]*/
        UDPNM_DET_REPORT_ERROR(UDPNM_API_ID_ENABLECOMM, UDPNM_E_INVALID_CHANNEL);
    }
	  /*[SWS_UdpNm_00177]*//*[SWS_UdpNm_00305]*/
    else if((NM_MODE_NETWORK == UDPNM_GET_MODE(nmChannelHandle))
		        && (UDPNM_COM_DISABLED == UDPNM_GET_COM_CTRL_REQ(nmChannelHandle)))
    {
        /*[SWS_UdpNm_00176]*/
        UDPNM_SET_COM_CTRL_REQ(nmChannelHandle, UDPNM_COM_ENABLED);
#if(UDPNM_REMOTE_SLEEP_IND_ENABLED == STD_ON)
       UDPNM_START_RMT_SLP_IND_TIMER(nmChannelHandle);
#endif        
        ret = E_OK; 
    }
    else
    {
        /* do nothing */
    }
#endif    
    return ret;
}
#endif

#if(UDPNM_PASSIVE_MODE_ENABLED == STD_OFF)
/*[SWS_UdpNm_00274]*/
#if(UDPNM_NODE_DETECTION_ENABLED == STD_ON)   
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: UdpNm_RepeatMessageRequest
*                
* Description:   Set Repeat Message Request Bit for all NM messages transmitted 
*                on the bus.
*                             
* Inputs:        nmChannelHandle: Identification of the NM-channel.
*             
* Outputs:       None
* 
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, UDPNM_CODE) UdpNm_RepeatMessageRequest 
(
    NetworkHandleType nmChannelHandle
)
{
    Std_ReturnType ret = E_NOT_OK;

  	/*[SWS_UdpNm_00244]*/
    if(STD_UNINITIALIZED == UdpNm_InitState)
    {
        /*[SWS_UdpNm_00039]*//*[SWS_UdpNm_00191]*/
        UDPNM_DET_REPORT_ERROR(UDPNM_API_ID_RPTMSGREQ, UDPNM_E_NO_INIT); 
    }	
    else if(nmChannelHandle >= UDPNM_NUMBER_OF_CHANNELS)
    {
        /*[SWS_UdpNm_00192]*/
        UDPNM_DET_REPORT_ERROR(UDPNM_API_ID_RPTMSGREQ, UDPNM_E_INVALID_CHANNEL);    
    } 
    else if((NM_STATE_REPEAT_MESSAGE == UDPNM_GET_STATE(nmChannelHandle))
             || (NM_MODE_BUS_SLEEP == UDPNM_GET_MODE(nmChannelHandle))
             || (NM_MODE_PREPARE_BUS_SLEEP == UDPNM_GET_MODE(nmChannelHandle)))
    {
        /*[SWS_UdpNm_00137]*/
        /* do nothing */
    }
    else
    {
        UDPNM_SET_RPT_MSG_REQ(nmChannelHandle);
        ret = E_OK;
    }      
    return ret;
}
#endif
#endif

/*[SWS_UdpNm_00139]*/
#if((UDPNM_NODE_DETECTION_ENABLED == STD_ON)||(UDPNM_USER_DATA_ENABLED == STD_ON)||(UDPNM_NODE_ID_ENABLED == STD_ON))
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: UdpNm_GetPduData
*                
* Description:   Get the whole PDU data out of the most recently received NM 
*                message.
*                             
* Inputs:        nmChannelHandle: Identification of the NM-channel.
*                          
* Outputs:       nmPduDataPtr: Pointer where NM PDU shall be copied to.
* 
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, UDPNM_CODE) UdpNm_GetPduData
(
    NetworkHandleType nmChannelHandle,
    P2VAR(uint8, AUTOMATIC, UDPNM_APPL_DATA) nmPduDataPtr
)
{
    Std_ReturnType ret = E_NOT_OK;

    /*[SWS_UdpNm_00244]*/
    if(STD_UNINITIALIZED == UdpNm_InitState)
    {
        /*[SWS_UdpNm_00039]*//*[SWS_UdpNm_00191]*/
        UDPNM_DET_REPORT_ERROR(UDPNM_API_ID_GETPDUDATA, UDPNM_E_NO_INIT);    
    }
    else if(nmChannelHandle >= UDPNM_NUMBER_OF_CHANNELS)
    {
        /*[SWS_UdpNm_00192]*/
        UDPNM_DET_REPORT_ERROR(UDPNM_API_ID_GETPDUDATA, UDPNM_E_INVALID_CHANNEL);    
    } 
    else if(NULL_PTR == nmPduDataPtr)
    {
        UDPNM_DET_REPORT_ERROR(UDPNM_API_ID_GETPDUDATA, UDPNM_E_PARAM_POINTER);  
    }
    else
    {
        /*[SWS_UdpNm_00138]*/
        SchM_Enter_UdpNm_UDPNM_EXCLUSIVE_AREA_0();
        Bsw_MemCpy(nmPduDataPtr, UdpNm_RxPdu[nmChannelHandle].SduDataPtr, (uint32)UdpNm_RxPdu[nmChannelHandle].SduLength);
        SchM_Exit_UdpNm_UDPNM_EXCLUSIVE_AREA_0(); 
        ret = E_OK;
    }    
    return ret;
}
#endif

#if(UDPNM_PASSIVE_MODE_ENABLED == STD_OFF)
#if(UDPNM_REMOTE_SLEEP_IND_ENABLED == STD_ON)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: UdpNm_CheckRemoteSleepIndication
*                
* Description:   Check if remote sleep indication takes place or not.
*                             
* Inputs:        nmChannelHandle: Identification of the NM-channel.
*             
* Outputs:       NmRemoteSleepIndPtr:  Pointer where check result of remote sleep
*                                      indication shall be copied to.
* 
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, UDPNM_CODE) UdpNm_CheckRemoteSleepIndication
(
    NetworkHandleType nmChannelHandle, 
    P2VAR(boolean, AUTOMATIC, UDPNM_APPL_DATA) nmRemoteSleepIndPtr
)
{
    Std_ReturnType ret = E_NOT_OK;

  	/*[SWS_UdpNm_00244]*/
    if(STD_UNINITIALIZED == UdpNm_InitState)
    {
        /*[SWS_UdpNm_00039]*//*[SWS_UdpNm_00191]*/
        UDPNM_DET_REPORT_ERROR(UDPNM_API_ID_CHECKRMTSLEEPIND, UDPNM_E_NO_INIT);
    }	
    else if(nmChannelHandle >= UDPNM_NUMBER_OF_CHANNELS)
    {   
        /*[SWS_UdpNm_00192]*/
        UDPNM_DET_REPORT_ERROR(UDPNM_API_ID_CHECKRMTSLEEPIND, UDPNM_E_INVALID_CHANNEL);    
    }
    /*[SWS_UdpNm_00039]*/
    else if(NULL_PTR == nmRemoteSleepIndPtr)
    {
        UDPNM_DET_REPORT_ERROR(UDPNM_API_ID_CHECKRMTSLEEPIND, UDPNM_E_PARAM_POINTER);
        
    }
    /*[SWS_UdpNm_00154]*/
    else if((NM_MODE_BUS_SLEEP == UDPNM_GET_MODE(nmChannelHandle))
             || (NM_MODE_PREPARE_BUS_SLEEP == UDPNM_GET_MODE(nmChannelHandle))
             || (NM_STATE_REPEAT_MESSAGE == UDPNM_GET_STATE(nmChannelHandle)))
    {
        ret = E_NOT_OK;
    }
    else
    {
        /*[SWS_UdpNm_00153]*/
        *nmRemoteSleepIndPtr = UDPNM_GET_RMT_SLP_IND(nmChannelHandle);
        ret = E_OK;
    }
    return ret;
}
#endif

/*[SWS_UdpNm_0185]*/
#if(UDPNM_BUS_SYNCHRONIZATION_ENABLED == STD_ON)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: UdpNm_RequestBusSynchronization
*                
* Description:   Request bus synchronization.
*                             
* Inputs:        nmChannelHandle: Identification of the NM-channel.
*             
* Outputs:       None
* 
* Limitations:   None  
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, UDPNM_CODE) UdpNm_RequestBusSynchronization
(
    NetworkHandleType nmChannelHandle
)
{
    Std_ReturnType ret = E_NOT_OK;

    /*[SWS_UdpNm_00244]*/
    if(STD_UNINITIALIZED == UdpNm_InitState)
    {
        /*[SWS_UdpNm_00039]*//*[SWS_UdpNm_00191]*/
        UDPNM_DET_REPORT_ERROR(UDPNM_API_ID_REQBUSSYNCH, UDPNM_E_NO_INIT);     
    }
    else if(nmChannelHandle >= UDPNM_NUMBER_OF_CHANNELS)
    {
        /*[SWS_UdpNm_00192]*/
        UDPNM_DET_REPORT_ERROR(UDPNM_API_ID_REQBUSSYNCH, UDPNM_E_INVALID_CHANNEL);     
    }
#if(UDPNM_COM_CONTROL_ENABLED == STD_ON)    
    else if(UDPNM_COM_ENABLED != UDPNM_GET_COM_CTRL_STATE(nmChannelHandle))
    {
        /*[SWS_UdpNm_00181]*/
        ret = E_NOT_OK;        
    }
#endif    
    else if((NM_MODE_BUS_SLEEP == UDPNM_GET_MODE(nmChannelHandle))
             || (NM_MODE_PREPARE_BUS_SLEEP == UDPNM_GET_MODE(nmChannelHandle)))
    {
        /*[SWS_UdpNm_00187]*/
        ret = E_NOT_OK;
    }
    else
    {
        ret = E_OK;
    } 
    
    return ret;
}
#endif
#endif


#if(UDPNM_NODE_ID_ENABLED == STD_ON)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: UdpNm_GetNodeIdentifier
*                
* Description:   Get node identifier from the most recently received NM PDU.
*                             
* Inputs:        nmChannelHandle: Identification of the NM-channel.
*             
* Outputs:       nmNodeIdPtr: Pointer where the source node identifier from the 
*                             most recently received NM PDU shall be copied to.
* 
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, UDPNM_CODE) UdpNm_GetNodeIdentifier
(
    NetworkHandleType nmChannelHandle,
    P2VAR(uint8, AUTOMATIC, UDPNM_APPL_DATA) nmNodeIdPtr
)
{
    Std_ReturnType ret = E_NOT_OK;
    
    /*[SWS_UdpNm_00244]*/
    if(STD_UNINITIALIZED == UdpNm_InitState)
    {
        /*[SWS_UdpNm_00039]*//*[SWS_UdpNm_00191]*/
        UDPNM_DET_REPORT_ERROR(UDPNM_API_ID_GETNODEID, UDPNM_E_NO_INIT);
    }
    else if(nmChannelHandle >= UDPNM_NUMBER_OF_CHANNELS)
    {
        /*[SWS_UdpNm_00192]*/
        UDPNM_DET_REPORT_ERROR(UDPNM_API_ID_GETNODEID, UDPNM_E_INVALID_CHANNEL);    
    } 
    else if(NULL_PTR == nmNodeIdPtr)
    {   
        UDPNM_DET_REPORT_ERROR(UDPNM_API_ID_GETNODEID, UDPNM_E_PARAM_POINTER);
    }
    else
    {
        /*[SWS_UdpNm_00132]*/
        *nmNodeIdPtr = UDPNM_RX_PDU_BYTE_NID(nmChannelHandle); 
        ret = E_OK;
    }    
    return ret;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: UdpNm_GetLocalNodeIdentifier
*                
* Description:   Get node identifier configured for the local node.
*                             
* Inputs:        nmChannelHandle: Identification of the NM-channel.
*             
* Outputs:       nmNodeIdPtr: Pointer where node identifier of the local node 
*                             shall be copied to.
* 
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, UDPNM_CODE) UdpNm_GetLocalNodeIdentifier 
(
    NetworkHandleType nmChannelHandle, 
    P2VAR(uint8, AUTOMATIC, UDPNM_APPL_DATA) nmNodeIdPtr
)
{
    Std_ReturnType ret = E_NOT_OK;
    
    /*[SWS_UdpNm_00244]*/
    if(STD_UNINITIALIZED == UdpNm_InitState)
    {
        /*[SWS_UdpNm_00039]*//*[SWS_UdpNm_00191]*/
        UDPNM_DET_REPORT_ERROR(UDPNM_API_ID_GETLOCALNODEID, UDPNM_E_NO_INIT);    
    }
    else if(nmChannelHandle >= UDPNM_NUMBER_OF_CHANNELS)
    {   
        /*[SWS_UdpNm_00192]*/
        UDPNM_DET_REPORT_ERROR(UDPNM_API_ID_GETLOCALNODEID, UDPNM_E_INVALID_CHANNEL);    
    }
    else if(NULL_PTR == nmNodeIdPtr)
    {
        UDPNM_DET_REPORT_ERROR(UDPNM_API_ID_GETLOCALNODEID, UDPNM_E_PARAM_POINTER);    
    }
    else
    {
        /*[SWS_UdpNm_00133]*/
        *nmNodeIdPtr = UDPNM_NODE_ID(nmChannelHandle);
        ret = E_OK;
    }    
    return ret;
}
#endif

#if((STD_ON == UDPNM_COM_USER_DATA_SUPPORT)||(STD_ON == UDPNM_GLOBAL_PN_SUPPORT))
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: UdpNm_Transmit
*                
* Description:   It is implemented as an empty function and shall always return 
*                E_OK.
*                             
* Inputs:        UdpNmTxPduId: This parameter contains a unique identifier 
*                              referencing to the PDU Routing Table and therby 
*                              specifiying the socket to be used for tranmission 
*                              of the data.
*                UdpNmSrcPduInfoPtr: A pointer to a structure with socket related
*                                    data: data length and pointer to a data 
*                                    buffer.
*             
* Outputs:       None
* 
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, UDPNM_CODE) UdpNm_Transmit
(
    PduIdType UdpNmTxPduId,
    P2CONST(PduInfoType, AUTOMATIC, UDPNM_APPL_DATA)  UdpNmSrcPduInfoPtr
)
{
    Std_ReturnType ret = E_NOT_OK;
    /*[SWS_UdpNm_00244]*/
    if(STD_UNINITIALIZED == UdpNm_InitState)
    {
        /*[SWS_UdpNm_00039]*//*[SWS_UdpNm_00191]*/
        UDPNM_DET_REPORT_ERROR(UDPNM_API_ID_GETLOCALNODEID, UDPNM_E_NO_INIT);    
    }
    else if(UdpNmTxPduId >= UDPNM_NUMBER_OF_TXPDUID)
    {   
        /*[SWS_UdpNm_00192]*/
        UDPNM_DET_REPORT_ERROR(UDPNM_API_ID_GETLOCALNODEID, UDPNM_E_INVALID_PDUID);    		
	}	
    else if(NULL_PTR == UdpNmSrcPduInfoPtr)
    {
        UDPNM_DET_REPORT_ERROR(UDPNM_API_ID_TRANSMIT, UDPNM_E_PARAM_POINTER);    
    }
    else
    {
        ret = E_OK;
    }
    return ret;
}
#endif

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: UdpNm__NetworkReqHandling
*                
* Description:   Network request process function.
*                             
* Inputs:        nmChannelHandle: Identification of the NM-channel.
*             
* Outputs:       None
* 
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, UDPNM_CODE) UdpNm__NetworkReqHandling
(
    const NetworkHandleType nmChannelHandle
)
{
    UdpNm_NetworkReqType cmd;
    
    SchM_Enter_UdpNm_UDPNM_EXCLUSIVE_AREA_4();
    cmd = UDPNM_GET_NETWORK_REQ_CMD(nmChannelHandle);
    UDPNM_SET_NETWORK_REQ_CMD(nmChannelHandle, UDPNM_NULL_CMD);
    SchM_Exit_UdpNm_UDPNM_EXCLUSIVE_AREA_4();
    
#if(UDPNM_PASSIVE_MODE_ENABLED == STD_OFF)    
    if(UDPNM_NETWORK_RELEASE_CMD == cmd)
    {
        /*[SWS_UdpNm_00105]*/
        UDPNM_SET_NETWORK_STATE(nmChannelHandle, UDPNM_NETWORK_RELEASED);
        
        if(NM_STATE_NORMAL_OPERATION == UDPNM_GET_STATE(nmChannelHandle))
        {
            /*[SWS_UdpNm_00118]*/
            UdpNm__RdySlpStateTransition(nmChannelHandle);            
        }
    }
    else if(UDPNM_NETWORK_REQUEST_CMD == cmd)
    {
        /*[SWS_UdpNm_00104]*/
        UDPNM_SET_NETWORK_STATE(nmChannelHandle, UDPNM_NETWORK_REQUESTED);
        
        if((NM_MODE_BUS_SLEEP == UDPNM_GET_MODE(nmChannelHandle))
            || (NM_MODE_PREPARE_BUS_SLEEP == UDPNM_GET_MODE(nmChannelHandle)))
        {
            /*[SWS_UdpNm_00366]*/
            if((boolean)STD_ON == UDPNM_ACTIVE_WU_BIT_ENABLED(nmChannelHandle))
            {
                if(UDPNM_PDU_OFF != UDPNM_PDU_CBV_POS(nmChannelHandle))
                {
                    UDPNM_TX_PDU_BYTE_CBV(nmChannelHandle) |= UDPNM_ACTIVE_WU_MASK;  
                }
            }
            if(NM_MODE_PREPARE_BUS_SLEEP == UDPNM_GET_MODE(nmChannelHandle))
            {
/*[SWS_UdpNm_00122]*/
#if(UDPNM_IMMEDIATE_RESTART_ENABLED == STD_ON)
                UDPNM_SET_TX_PDU_REQ(nmChannelHandle); 
#endif
                UDPNM_STOP_WBS_TIMER(nmChannelHandle);
            }
            /*[SWS_UdpNm_00123]*//*[SWS_UdpNm_00129]*/            
            UdpNm__NetworkModeTransition(nmChannelHandle);
        }
#if(STD_ON == UDPNM_GLOBAL_PN_SUPPORT)
        else if((NM_MODE_NETWORK == UdpNm_Mode[nmChannelHandle]) \
                || ((boolean)STD_ON == UDPNM_PN_MULTIPLE_REQ(nmChannelHandle)))
        {            
            UdpNm__RptMsgStateTransition(nmChannelHandle);
        }
#endif        
        else if(NM_STATE_READY_SLEEP == UDPNM_GET_STATE(nmChannelHandle))
        {
#if(UDPNM_COM_CONTROL_ENABLED == STD_ON)            
            /*[SWS_UdpNm_00116]*/
            if(UDPNM_COM_ENABLED == UDPNM_GET_COM_CTRL_STATE(nmChannelHandle))
#endif
            {
                UDPNM_SET_TX_PDU_REQ(nmChannelHandle);
                UDPNM_START_MSG_CYC_TIMER(nmChannelHandle);
            }
            /*[SWS_UdpNm_00110]*/
            UdpNm__NormalOpStateTransition(nmChannelHandle);            
        }
        else
        {
            /* do nothing */
        }
    }
    else 
#endif
    if(UDPNM_PASSIVE_STARTUP_CMD == cmd)
    {
        /*[SWS_UdpNm_00128]*/
        if((NM_MODE_BUS_SLEEP == UDPNM_GET_MODE(nmChannelHandle))
            || (NM_MODE_PREPARE_BUS_SLEEP == UDPNM_GET_MODE(nmChannelHandle)))
        {
#if(UDPNM_PASSIVE_MODE_ENABLED == STD_OFF)               
            if((boolean)STD_ON == UDPNM_ACTIVE_WU_BIT_ENABLED(nmChannelHandle))
            {
                if(UDPNM_PDU_OFF != UDPNM_PDU_CBV_POS(nmChannelHandle))
                {
                    UDPNM_TX_PDU_BYTE_CBV(nmChannelHandle) &= (uint8)(~(uint32)UDPNM_ACTIVE_WU_MASK);  
                }
            }
#endif
            UDPNM_STOP_WBS_TIMER(nmChannelHandle);
            UdpNm__NetworkModeTransition(nmChannelHandle); 
        }
    }
    else
    {
        /* do nothing */
    }            
}

#if(UDPNM_PASSIVE_MODE_ENABLED == STD_OFF)
/*[SWS_UdpNm_00135]*/  
#if(UDPNM_NODE_DETECTION_ENABLED == STD_ON)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: UdpNm__RptMsgReqHandling
*                
* Description:   Repeat message request process function.
*                             
* Inputs:        nmChannelHandle: Identification of the NM-channel.
*             
* Outputs:       None
* 
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, UDPNM_CODE)UdpNm__RptMsgReqHandling
(
    const NetworkHandleType nmChannelHandle
)
{
    if(UDPNM_IS_RPT_MSG_REQ(nmChannelHandle))
    {
        UDPNM_CLR_RPT_MSG_REQ(nmChannelHandle); 
        
        if((NM_STATE_NORMAL_OPERATION == UDPNM_GET_STATE(nmChannelHandle))
            || (NM_STATE_READY_SLEEP == UDPNM_GET_STATE(nmChannelHandle)))
        {
            /*[SWS_UdpNm_00112]*//*[SWS_UdpNm_00120]*/            
            UdpNm__RptMsgStateTransition(nmChannelHandle);
            
/*[SWS_UdpNm_00149]*/
#if(UDPNM_REMOTE_SLEEP_IND_ENABLED == STD_ON)
            if(UDPNM_IS_RMT_SLP_IND(nmChannelHandle))
            {
                UDPNM_CLR_RMT_SLP_IND(nmChannelHandle);
                /*[SWS_UdpNm_00152]*/
                Nm_RemoteSleepCancellation(UDPNM_COMM_NETWORK_HANDLE(nmChannelHandle));
                UDPNM_STOP_RMT_SLP_IND_TIMER(nmChannelHandle);
            }
#endif
            /*[SWS_UdpNm_00113]*//*[SWS_UdpNm_00121]*/
            if(UDPNM_PDU_OFF != UDPNM_PDU_CBV_POS(nmChannelHandle)) 
            {
                UDPNM_TX_PDU_BYTE_CBV(nmChannelHandle) |= UDPNM_RMB_MASK;  
            }
        }
    }            
}
#endif
#endif

#if(UDPNM_PASSIVE_MODE_ENABLED == STD_OFF)            
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: UdpNm__TxConfHandling
*                
* Description:   Tx confirmation process function when a nm pdu already transmitted.
*                             
* Inputs:        nmChannelHandle: Identification of the NM-channel.
*             
* Outputs:       None
* 
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, UDPNM_CODE) UdpNm__TxConfHandling
(
    const NetworkHandleType nmChannelHandle
)
{
    if(UDPNM_IS_TX_CONF_FLAG(nmChannelHandle))
    {
        UDPNM_CLR_TX_CONF_FLAG(nmChannelHandle); 
        
        /*[SWS_UdpNm_00099]*/
        UDPNM_START_NMTO_TIMER(nmChannelHandle);
        /*[SWS_UdpNm_00065]*/
        UDPNM_STOP_TXTO_TIMER(nmChannelHandle); 
    }
}
#endif

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: UdpNm__RxIndHandling
*                
* Description:   Rx indication process function when a nm pdu received.
*                             
* Inputs:        nmChannelHandle: Identification of the NM-channel.
*             
* Outputs:       None
* 
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, UDPNM_CODE) UdpNm__RxIndHandling
(
    const NetworkHandleType nmChannelHandle
)
{
    if(UDPNM_IS_RX_IND_FLAG(nmChannelHandle))
    {
        UDPNM_CLR_RX_IND_FLAG(nmChannelHandle);

/*[SWS_UdpNm_00037]*//*[SWS_UdpNm_00164]*//*[SWS_UdpNm_00165]*/
#if(UDPNM_PDU_RX_INDICATION_ENABLED == STD_ON)
        Nm_PduRxIndication(UDPNM_COMM_NETWORK_HANDLE(nmChannelHandle));
#endif

#if(UDPNM_PASSIVE_MODE_ENABLED == STD_OFF)
/*[SWS_UdpNm_00135]*/
#if(UDPNM_NODE_DETECTION_ENABLED == STD_ON)
        if((UDPNM_PDU_OFF != (UDPNM_PDU_CBV_POS(nmChannelHandle)))
            && (0 != (((uint8)UDPNM_RX_PDU_BYTE_CBV(nmChannelHandle) & UDPNM_RMB_MASK))))
        {
            /*[SWS_UdpNm_00111]*//*[SWS_UdpNm_00119]*/
            if((NM_STATE_NORMAL_OPERATION == UDPNM_GET_STATE(nmChannelHandle))
                || (NM_STATE_READY_SLEEP == UDPNM_GET_STATE(nmChannelHandle)))
            {
/*[SWS_UdpNm_00149]*/
#if(UDPNM_REMOTE_SLEEP_IND_ENABLED == STD_ON)
                        if(NM_STATE_NORMAL_OPERATION == UDPNM_GET_STATE(nmChannelHandle))
                        {
                            UDPNM_START_RMT_SLP_IND_TIMER(nmChannelHandle);
                        }
                        /*[SWS_UdpNm_00151]*/
                        if(((NM_STATE_NORMAL_OPERATION == UDPNM_GET_STATE(nmChannelHandle))
                            || (NM_STATE_READY_SLEEP == UDPNM_GET_STATE(nmChannelHandle)))
                            && (UDPNM_IS_RMT_SLP_IND(nmChannelHandle)))
                        {
                            UDPNM_CLR_RMT_SLP_IND(nmChannelHandle);
                            Nm_RemoteSleepCancellation(UDPNM_COMM_NETWORK_HANDLE(nmChannelHandle));
                        }        
#endif 
                UdpNm__RptMsgStateTransition(nmChannelHandle);
                
                /*[SWS_UdpNm_00098]*/ 
                UDPNM_START_NMTO_TIMER(nmChannelHandle);
            }
/*[SWS_UdpNm_00014]*/
#if(UDPNM_REPEAT_MSG_IND_ENABLED == STD_ON)                
            Nm_RepeatMessageIndication(UDPNM_COMM_NETWORK_HANDLE(nmChannelHandle));
#endif                 
        }
#endif 
#endif

        /*[SWS_UdpNm_00124]*/
        if(NM_MODE_PREPARE_BUS_SLEEP == UDPNM_GET_MODE(nmChannelHandle))
        {
/*[SWS_UdpNm_00122]*/   
#if(UDPNM_IMMEDIATE_RESTART_ENABLED == STD_ON)  
            UDPNM_SET_TX_PDU_REQ(nmChannelHandle); 
#endif
            UdpNm__NetworkModeTransition(nmChannelHandle);
            UDPNM_STOP_WBS_TIMER(nmChannelHandle);
        }  

        /*[SWS_UdpNm_00127]*/
        if(NM_MODE_BUS_SLEEP == UDPNM_GET_MODE(nmChannelHandle))
        {
            Nm_NetworkStartIndication(UDPNM_COMM_NETWORK_HANDLE(nmChannelHandle));
        }
    }
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: UdpNm__NmTOTimerProcess
*                
* Description:   Nm timeout timer timeout process function.
*                             
* Inputs:        nmChannelHandle: Identification of the NM-channel.
*             
* Outputs:       None
* 
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, UDPNM_CODE) UdpNm__NmTOTimerProcess
(
    const NetworkHandleType nmChannelHandle
)
{
    if((uint16)0 < UDPNM_GET_NMTO_TIMER(nmChannelHandle))
    {
        UDPNM_DEC_NMTO_TIMER(nmChannelHandle);

        if(UDPNM_EXP_NMTO_TIMER(nmChannelHandle))
        {
            /*[SWS_UdpNm_00101]*//*[SWS_UdpNm_00117]*/
            if((NM_STATE_REPEAT_MESSAGE == UDPNM_GET_STATE(nmChannelHandle))
                || (NM_STATE_NORMAL_OPERATION == UDPNM_GET_STATE(nmChannelHandle)))
            {
                UDPNM_START_NMTO_TIMER(nmChannelHandle);

                /*[SWS_UdpNm_00193]*//*[SWS_UdpNm_00194]*/
                UDPNM_DEM_REPORT_ERROR_NETWORK_TIMEOUT(DEM_EVENT_STATUS_FAILED);
            }
            else if(NM_STATE_READY_SLEEP == UDPNM_GET_STATE(nmChannelHandle))
            {
#if(UDPNM_PASSIVE_MODE_ENABLED == STD_OFF)       
                /*[SWS_UdpNm_00402]*//*[SWS_UdpNm_00367]*/
                if(((boolean)STD_ON == UDPNM_ACTIVE_WU_BIT_ENABLED(nmChannelHandle))
                    && (UDPNM_PDU_OFF != UDPNM_PDU_CBV_POS(nmChannelHandle))
                    && (0 != (UDPNM_TX_PDU_BYTE_CBV(nmChannelHandle) & UDPNM_ACTIVE_WU_MASK)))
                {
                    UDPNM_TX_PDU_BYTE_CBV(nmChannelHandle) &= (uint8)(~(uint32)UDPNM_ACTIVE_WU_MASK);  
                }
#endif
                /*[SWS_UdpNm_00109]*/
                UdpNm__PreBusSlpModeTransition(nmChannelHandle);
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
* Function Name: UdpNm__RptMsgTimerProcess
*                
* Description:   Repeat message timer timeout process function.
*                             
* Inputs:        nmChannelHandle: Identification of the NM-channel.
*             
* Outputs:       None
* 
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, UDPNM_CODE) UdpNm__RptMsgTimerProcess
(
    const NetworkHandleType nmChannelHandle
)
{
    if((uint16)0 < UDPNM_GET_RPT_MSG_TIMER(nmChannelHandle))
    {
        UDPNM_DEC_RPT_MSG_TIMER(nmChannelHandle);

        if(UDPNM_EXP_RPT_MSG_TIMER(nmChannelHandle))
        {
            /*[SWS_UdpNm_00102]*//*[SWS_UdpNm_00103]*/
            if(UDPNM_NETWORK_REQUESTED == UDPNM_GET_NETWORK_STATE(nmChannelHandle))
            {
                UdpNm__NormalOpStateTransition(nmChannelHandle);
            }
            /*[SWS_UdpNm_00106]*/
            if(UDPNM_NETWORK_RELEASED == UDPNM_GET_NETWORK_STATE(nmChannelHandle))
            {
                UdpNm__RdySlpStateTransition(nmChannelHandle);  
            }

#if(UDPNM_PASSIVE_MODE_ENABLED == STD_OFF)    
#if(UDPNM_NODE_DETECTION_ENABLED == STD_ON)
            /*[SWS_UdpNm_00107]*/
            if((UDPNM_PDU_OFF != UDPNM_PDU_CBV_POS(nmChannelHandle))
                && (0 != (UDPNM_TX_PDU_BYTE_CBV(nmChannelHandle) & UDPNM_RMB_MASK)))
            {
                UDPNM_TX_PDU_BYTE_CBV(nmChannelHandle) &= (uint8)(~(uint32)UDPNM_RMB_MASK);
            }
#endif
#endif
        }
    }
}

#if(UDPNM_PASSIVE_MODE_ENABLED == STD_OFF)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: UdpNm__MsgCycTimerProcess
*                
* Description:   Message cycle timer timeout process function.
*                             
* Inputs:        nmChannelHandle: Identification of the NM-channel.
*             
* Outputs:       None
* 
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, UDPNM_CODE) UdpNm__MsgCycTimerProcess
(
    const NetworkHandleType nmChannelHandle
)
{
    if((uint16)0 < UDPNM_GET_MSG_CYC_TIMER(nmChannelHandle))
    {
        UDPNM_DEC_MSG_CYC_TIMER(nmChannelHandle);

        if(UDPNM_EXP_MSG_CYC_TIMER(nmChannelHandle))
        {
            /*[SWS_UdpNm_00032]*//*[SWS_UdpNm_00169]*/
            UDPNM_SET_TX_PDU_REQ(nmChannelHandle);
            /*[SWS_UdpNm_00040]*//*[SWS_UdpNm_00335]*/            
            UDPNM_START_MSG_CYC_TIMER(nmChannelHandle);                                
        } 
    }
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: UdpNm__MsgCycOffsetProcess
*                
* Description:   Message cycle offset timer timeout process function.
*                             
* Inputs:        nmChannelHandle: Identification of the NM-channel.
*             
* Outputs:       None
* 
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, UDPNM_CODE) UdpNm__MsgCycOffsetProcess
(
    const NetworkHandleType nmChannelHandle
)
{
    if((uint16)0 < UDPNM_GET_MSG_CYCLE_OFFSET(nmChannelHandle))
    {
        UDPNM_DEC_MSG_CYCLE_OFFSET(nmChannelHandle);

        if(UDPNM_EXP_MSG_CYCLE_OFFSET(nmChannelHandle))
        {
            /*[SWS_UdpNm_00005]*/
            UDPNM_SET_TX_PDU_REQ(nmChannelHandle);
            UDPNM_START_MSG_CYC_TIMER(nmChannelHandle);
        }
    }
}
#endif

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: UdpNm__WbsTimerProcess
*                
* Description:   Wait bus sleep timer timeout process function.
*                             
* Inputs:        nmChannelHandle: Identification of the NM-channel.
*             
* Outputs:       None
* 
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, UDPNM_CODE) UdpNm__WbsTimerProcess
(
    const NetworkHandleType nmChannelHandle
)
{
    if((uint16)0 < UDPNM_GET_WBS_TIMER(nmChannelHandle))
    {
        UDPNM_DEC_WBS_TIMER(nmChannelHandle);

        if(UDPNM_EXP_WBS_TIMER(nmChannelHandle))
        {
            /*[SWS_UdpNm_00088]*//*[SWS_UdpNm_00115]*/
            UdpNm__BusSlpModeTransition(nmChannelHandle);
        }
    }
}

#if(UDPNM_PASSIVE_MODE_ENABLED == STD_OFF)
/*[SWS_UdpNm_00149]*/
#if(UDPNM_REMOTE_SLEEP_IND_ENABLED == STD_ON)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: UdpNm__RmtSlpIndTimerProcess
*                
* Description:   Remote sleep indication timer timeout process function.
*                             
* Inputs:        nmChannelHandle: Identification of the NM-channel.
*             
* Outputs:       None
* 
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, UDPNM_CODE) UdpNm__RmtSlpIndTimerProcess
(
    const NetworkHandleType nmChannelHandle
)
{
    if(0 < UDPNM_GET_RMT_SLP_IND_TIMER(nmChannelHandle))
    {
        UDPNM_DEC_RMT_SLP_IND_TIMER(nmChannelHandle);
            
        if(UDPNM_EXP_RMT_SLP_IND_TIMER(nmChannelHandle))
        {
            /*[SWS_UdpNm_00150]*/
            if((NM_STATE_NORMAL_OPERATION == UDPNM_GET_STATE(nmChannelHandle))
#if(UDPNM_COM_CONTROL_ENABLED == STD_ON)            
                && (UDPNM_COM_ENABLED == UDPNM_GET_COM_CTRL_STATE(nmChannelHandle))
#endif                
                )
            {
                UDPNM_SET_RMT_SLP_IND(nmChannelHandle);
                Nm_RemoteSleepIndication(UDPNM_COMM_NETWORK_HANDLE(nmChannelHandle));
            }
        }
    }
}
#endif
#endif

/*[SWS_UdpNm_00073]*/
#if(UDPNM_PASSIVE_MODE_ENABLED == STD_OFF)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: UdpNm__TxTOTimerProcess
*                
* Description:   Tx timeout process function.
*                             
* Inputs:        nmChannelHandle: Identification of the NM-channel.
*             
* Outputs:       None
* 
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, UDPNM_CODE) UdpNm__TxTOTimerProcess
(
    const NetworkHandleType nmChannelHandle
)
{
    if((uint16)0 < UDPNM_GET_TXTO_TIMER(nmChannelHandle))
    {
        UDPNM_DEC_TXTO_TIMER(nmChannelHandle);
            
        if(UDPNM_EXP_TXTO_TIMER(nmChannelHandle))
        {
            /*[SWS_UdpNm_00066]*/
            Nm_TxTimeoutException(UDPNM_COMM_NETWORK_HANDLE(nmChannelHandle));
        }
    }
}
#endif

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: UdpNm__TimerHandling
*                
* Description:   All the internal timers process function.
*                             
* Inputs:        nmChannelHandle: Identification of the NM-channel.
*             
* Outputs:       None
* 
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, UDPNM_CODE) UdpNm__TimerHandling
(
    const NetworkHandleType nmChannelHandle
)
{
    UdpNm__NmTOTimerProcess(nmChannelHandle);
    UdpNm__WbsTimerProcess(nmChannelHandle);
#if(UDPNM_PASSIVE_MODE_ENABLED == STD_OFF)
    UdpNm__MsgCycOffsetProcess(nmChannelHandle);
    UdpNm__MsgCycTimerProcess(nmChannelHandle);
    UdpNm__TxTOTimerProcess(nmChannelHandle);
#if(UDPNM_REMOTE_SLEEP_IND_ENABLED == STD_ON)
    UdpNm__RmtSlpIndTimerProcess(nmChannelHandle);
#endif
#endif
    UdpNm__RptMsgTimerProcess(nmChannelHandle);
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: UdpNm__RptMsgStateTransition
*                
* Description:   Transit to the repeat message state.
*                             
* Inputs:        nmChannelHandle: Identification of the NM-channel.
*             
* Outputs:       None
* 
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, UDPNM_CODE) UdpNm__RptMsgStateTransition
(
    const NetworkHandleType nmChannelHandle
)
{
/*[SWS_UdpNm_00166]*/
#if(UDPNM_STATE_CHANGE_IND_ENABLED == STD_ON)
    Nm_StateChangeNotification(UDPNM_COMM_NETWORK_HANDLE(nmChannelHandle), 
                               UdpNm_State[nmChannelHandle],
                               NM_STATE_REPEAT_MESSAGE);    
#endif

    UDPNM_SET_STATE(nmChannelHandle, NM_STATE_REPEAT_MESSAGE);

    /*[SWS_UdpNm_00102]*/
    UDPNM_START_RPT_MSG_TIMER(nmChannelHandle);

    if(UDPNM_RPT_MSG_TIME(nmChannelHandle) == 0) 
    {
        /* If Repeat Message Timer is configured to 0, add 1 so the state will change in the next main function */
        (UDPNM_GET_RPT_MSG_TIMER(nmChannelHandle))++;
    }
/*[SWS_UdpNm_00100]*/
#if(UDPNM_PASSIVE_MODE_ENABLED == STD_OFF)
#if(UDPNM_COM_CONTROL_ENABLED == STD_ON)
    if(UDPNM_COM_ENABLED == UDPNM_GET_COM_CTRL_STATE(nmChannelHandle))
#endif
    {

        if(UDPNM_IMM_NM_TRANS(nmChannelHandle) > (uint8)0)
        {
            UDPNM_SET_TX_PDU_REQ(nmChannelHandle);
            UDPNM_SET_IMMTRANS(nmChannelHandle, (UDPNM_IMM_NM_TRANS(nmChannelHandle)-(uint8)1));
            UDPNM_START_MSG_CYC_TIMER(nmChannelHandle);
        }
        else
        {
            /* immdiate restart msg cycle msg offset */
            if((uint16)0u != UDPNM_MSG_CYCLE_OFFSET(nmChannelHandle))
            {
                UDPNM_START_MSG_CYCLE_OFFSET(nmChannelHandle);
            }
            else
            {
                UDPNM_SET_TX_PDU_REQ(nmChannelHandle);
                UDPNM_START_MSG_CYC_TIMER(nmChannelHandle);
            }
        }
    }
#endif
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: UdpNm__NormalOpStateTransition
*                
* Description:   Transit to the normal operation state.
*                             
* Inputs:        nmChannelHandle: Identification of the NM-channel.
*             
* Outputs:       None
* 
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, UDPNM_CODE) UdpNm__NormalOpStateTransition
(
    const NetworkHandleType nmChannelHandle
)
{
/*[SWS_UdpNm_00166]*/
#if(UDPNM_STATE_CHANGE_IND_ENABLED == STD_ON)
    Nm_StateChangeNotification(UDPNM_COMM_NETWORK_HANDLE(nmChannelHandle), 
                               UdpNm_State[nmChannelHandle],
                               NM_STATE_NORMAL_OPERATION);    
#endif

    UDPNM_SET_STATE(nmChannelHandle, NM_STATE_NORMAL_OPERATION);

/*[SWS_UdpNm_00116]*/
#if(UDPNM_REMOTE_SLEEP_IND_ENABLED == STD_ON)
    UDPNM_START_RMT_SLP_IND_TIMER(nmChannelHandle);
#endif 
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: UdpNm__RdySlpStateTransition
*                
* Description:   Transit to the ready sleep state.
*                             
* Inputs:        nmChannelHandle: Identification of the NM-channel.
*             
* Outputs:       None
* 
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, UDPNM_CODE) UdpNm__RdySlpStateTransition
(
    const NetworkHandleType nmChannelHandle
)
{
/*[SWS_UdpNm_00166]*/
#if(UDPNM_STATE_CHANGE_IND_ENABLED == STD_ON)
    Nm_StateChangeNotification(UDPNM_COMM_NETWORK_HANDLE(nmChannelHandle), 
                               UdpNm_State[nmChannelHandle],
                               NM_STATE_READY_SLEEP);    
#endif

    UDPNM_SET_STATE(nmChannelHandle, NM_STATE_READY_SLEEP);


/*[SWS_UdpNm_00051]*//*[SWS_UdpNm_00108]]*/
#if(UDPNM_PASSIVE_MODE_ENABLED == STD_OFF)
    UDPNM_CLR_TX_PDU_REQ(nmChannelHandle);  
    UDPNM_STOP_MSG_CYC_TIMER(nmChannelHandle); 
#endif
/*[SWS_UdpNm_00175]*/
#if(UDPNM_REMOTE_SLEEP_IND_ENABLED == STD_ON)
    UDPNM_STOP_RMT_SLP_IND_TIMER(nmChannelHandle);
#endif 
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: UdpNm__NetworkModeTransition
*                
* Description:   Transit to the network mode.
*                             
* Inputs:        nmChannelHandle: Identification of the NM-channel.
*             
* Outputs:       None
* 
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, UDPNM_CODE) UdpNm__NetworkModeTransition
(
    const NetworkHandleType nmChannelHandle
)
{    
    UDPNM_SET_MODE(nmChannelHandle, NM_MODE_NETWORK);
    /*[SWS_UdpNm_00095]*/
    UdpNm__RptMsgStateTransition(nmChannelHandle);
    /*[SWS_UdpNm_00096]*/
    UDPNM_START_NMTO_TIMER(nmChannelHandle);
    /*[SWS_UdpNm_00097]*//*[SWS_UdpNm_00093]*/
    Nm_NetworkMode(UDPNM_COMM_NETWORK_HANDLE(nmChannelHandle));
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: UdpNm__PreBusSlpModeTransition
*                
* Description:   Transit to the prepare bus sleep mode.
*                             
* Inputs:        nmChannelHandle: Identification of the NM-channel.
*             
* Outputs:       None
* 
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, UDPNM_CODE) UdpNm__PreBusSlpModeTransition
(
    const NetworkHandleType nmChannelHandle
)
{
/*[SWS_UdpNm_00166]*/
#if(UDPNM_STATE_CHANGE_IND_ENABLED == STD_ON)
    Nm_StateChangeNotification(UDPNM_COMM_NETWORK_HANDLE(nmChannelHandle), 
                               UdpNm_State[nmChannelHandle],
                               NM_STATE_PREPARE_BUS_SLEEP);    
#endif    

    UDPNM_SET_STATE(nmChannelHandle, NM_STATE_PREPARE_BUS_SLEEP); 
    UDPNM_SET_MODE(nmChannelHandle, NM_MODE_PREPARE_BUS_SLEEP);
#if(UDPNM_PASSIVE_MODE_ENABLED == STD_OFF)
#if(UDPNM_REMOTE_SLEEP_IND_ENABLED == STD_ON)
    UDPNM_CLR_RMT_SLP_IND(nmChannelHandle);    
#endif
#endif
    /*[SWS_UdpNm_00092]*//*[SWS_UdpNm_00093]*//*[SWS_UdpNm_00114]*/
    Nm_PrepareBusSleepMode(UDPNM_COMM_NETWORK_HANDLE(nmChannelHandle));
    /*[SWS_UdpNm_00115]*/
    UDPNM_START_WBS_TIMER(nmChannelHandle);
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: UdpNm__BusSlpModeTransition
*                
* Description:   Transit to the bus sleep mode.
*                             
* Inputs:        nmChannelHandle: Identification of the NM-channel.
*             
* Outputs:       None
* 
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, UDPNM_CODE) UdpNm__BusSlpModeTransition
(
    const NetworkHandleType nmChannelHandle
)
{
/*[SWS_UdpNm_00166]*/
#if(UDPNM_STATE_CHANGE_IND_ENABLED == STD_ON)
    Nm_StateChangeNotification(UDPNM_COMM_NETWORK_HANDLE(nmChannelHandle), 
                               UdpNm_State[nmChannelHandle],
                               NM_STATE_BUS_SLEEP);    
#endif
  
    UDPNM_SET_STATE(nmChannelHandle, NM_STATE_BUS_SLEEP); 
    UDPNM_SET_MODE(nmChannelHandle, NM_MODE_BUS_SLEEP);
    
    /*[SWS_UdpNm_00092]*//*[SWS_UdpNm_00093]*//*[SWS_UdpNm_00126]*/
    Nm_BusSleepMode(UDPNM_COMM_NETWORK_HANDLE(nmChannelHandle));
}

#if(UDPNM_PASSIVE_MODE_ENABLED == STD_OFF)
#if(UDPNM_COM_CONTROL_ENABLED == STD_ON)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: UdpNm__ComCtrlHandling
*                
* Description:   Communication control process function.
*                             
* Inputs:        nmChannelHandle: Identification of the NM-channel.
*             
* Outputs:       None
* 
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/  
STATIC FUNC(void, UDPNM_CODE) UdpNm__ComCtrlHandling
(
    const NetworkHandleType nmChannelHandle
)
{
    UdpNm_ComCtrlType ComCtrlState;
    
    SchM_Enter_UdpNm_UDPNM_EXCLUSIVE_AREA_5();
    ComCtrlState = UDPNM_GET_COM_CTRL_REQ(nmChannelHandle);
    SchM_Exit_UdpNm_UDPNM_EXCLUSIVE_AREA_5();

    if(UDPNM_GET_COM_CTRL_STATE(nmChannelHandle) != ComCtrlState)
    {
        UDPNM_SET_COM_CTRL_STATE(nmChannelHandle, ComCtrlState);
        
        if(UDPNM_COM_ENABLED == ComCtrlState)
        { 
            /*[SWS_UdpNm_00178]*//*[SWS_UdpNm_00179]*/
            if((NM_STATE_NORMAL_OPERATION == UDPNM_GET_STATE(nmChannelHandle)) 
                || (NM_STATE_REPEAT_MESSAGE == UDPNM_GET_STATE(nmChannelHandle)))
            {
                UDPNM_START_MSG_CYCLE_OFFSET(nmChannelHandle);
                UDPNM_START_NMTO_TIMER(nmChannelHandle);
            }            

/*[SWS_UdpNm_00180]*/            
#if(UDPNM_REMOTE_SLEEP_IND_ENABLED == STD_ON)            
            if(NM_STATE_NORMAL_OPERATION == UDPNM_GET_STATE(nmChannelHandle))
            {
                UDPNM_START_RMT_SLP_IND_TIMER(nmChannelHandle); 
            }
#endif
        }
        else
        {
            /*[SWS_UdpNm_00170]*//*[SWS_UdpNm_00173]*/            
            UDPNM_STOP_MSG_CYC_TIMER(nmChannelHandle);
            /*[SWS_UdpNm_00174]*/
            UDPNM_STOP_NMTO_TIMER(nmChannelHandle);
/*[SWS_UdpNm_00175]*/
#if(UDPNM_REMOTE_SLEEP_IND_ENABLED == STD_ON)
            UDPNM_STOP_RMT_SLP_IND_TIMER(nmChannelHandle);
            UDPNM_CLR_RMT_SLP_IND(nmChannelHandle);
#endif
        }
    }
}
#endif
#endif

/*[SWS_UdpNm_00072]*/
#if(UDPNM_PASSIVE_MODE_ENABLED == STD_OFF)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: UdpNm__TxPduHandling
*                
* Description:   Transmit a nm pdu while tx request is available.
*                             
* Inputs:        nmChannelHandle: Identification of the NM-channel.
*             
* Outputs:       None
* 
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, UDPNM_CODE) UdpNm__TxPduHandling
(
    const NetworkHandleType nmChannelHandle
)
{    
    Std_ReturnType ret = E_NOT_OK;
#if(STD_ON == UDPNM_COM_USER_DATA_SUPPORT)
    PduInfoType TriggerTxInfo;
    uint8 TriggerData[UDPNM_USER_DATA_LENGTH(nmChannelHandle)];
#endif
#if(STD_ON == UDPNM_PN_EIRA_CALC_ENABLED)
#if(STD_ON == UDPNM_PN_EIRA_CALC_ENABLED)
    uint8 ByteIdx;
#endif
#endif

    if(UDPNM_IS_TX_PDU_REQ(nmChannelHandle))
    {        
        UDPNM_CLR_TX_PDU_REQ(nmChannelHandle);
#if(UDPNM_COM_CONTROL_ENABLED == STD_ON)
        if(UDPNM_COM_ENABLED== UDPNM_GET_COM_CTRL_REQ(nmChannelHandle))
#endif       
        {
#if(STD_ON == UDPNM_COM_USER_DATA_SUPPORT)            
            TriggerTxInfo.SduDataPtr = TriggerData;
            TriggerTxInfo.SduLength = UDPNM_USER_DATA_LENGTH(nmChannelHandle);
            ret = PduR_UdpNmTriggerTransmit(UDPNM_USER_DATA_TX_PDU_ID(nmChannelHandle), &TriggerTxInfo);
            if(ret == E_OK)
            {
                SchM_Enter_UdpNm_UDPNM_EXCLUSIVE_AREA_6();
                Bsw_MemCpy(&(UdpNm_TxPdu[nmChannelHandle].SduDataPtr[UDPNM_PDU_LENGTH(nmChannelHandle) - UDPNM_USER_DATA_LENGTH(nmChannelHandle)]), \
                           TriggerData, UDPNM_USER_DATA_LENGTH(nmChannelHandle) );
                SchM_Exit_UdpNm_UDPNM_EXCLUSIVE_AREA_6();
            }
            else
            {                
                /*do nothing*/
            }
#endif
#if(STD_ON == UDPNM_GLOBAL_PN_SUPPORT)
            if((boolean)STD_ON == UDPNM_PN_ENABLED(nmChannelHandle))
            {                
                /*Set Pnbit*/
                UDPNM_TX_PDU_BYTE_CBV(nmChannelHandle) |= UDPNM_CBV_PN_MASK;
#if(STD_ON == UDPNM_PN_EIRA_CALC_ENABLED)
                for(ByteIdx = 0; ByteIdx < UDPNM_PN_INFO_LENGTH; ByteIdx++)
                {                    
                    UdpNm_PnEiraNewReq[ByteIdx] |= (UdpNm_TxPdu[nmChannelHandle].SduDataPtr[UDPNM_PN_INFO_OFFSET + ByteIdx]);
                }
#endif
            }
            else
            {
                /*Clear Pnbit*/
                UDPNM_TX_PDU_BYTE_CBV(nmChannelHandle) &= (uint8)(~(uint32)UDPNM_CBV_PN_MASK);                
            }
#endif/*(STD_ON == UDPANNM_GLOBAL_PN_SUPPORT)*/

            SchM_Enter_UdpNm_UDPNM_EXCLUSIVE_AREA_6(); 
            ret = SoAd_IfTransmit(UDPNM_TX_PDU_ID(nmChannelHandle), &UdpNm_TxPdu[nmChannelHandle]);
            SchM_Exit_UdpNm_UDPNM_EXCLUSIVE_AREA_6();
			
            if(E_OK == ret)
            {
                /*[SWS_UdpNm_00064]*/
                UDPNM_START_TXTO_TIMER(nmChannelHandle);
            }
            else
            {
#ifdef UDPNM_E_TCPIP_TRANSMIT_ERROR
                UDPNM_DEM_REPORT_ERROR_TCPIP_TRANSMIT_ERROR(DEM_EVENT_STATUS_FAILED);
#endif
            }    
        }       
    }
}
#endif

#if(STD_ON == UDPNM_GLOBAL_PN_SUPPORT)
#if(STD_ON == UDPNM_PN_EIRA_CALC_ENABLED)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: UdpNm_PnEiraHandling
*
* Description:
*
* Inputs:
*
* Outputs:
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, UDPM_CODE) UdpNm_PnEiraHandling
(
    const NetworkHandleType nmChannelHandle
)
{
    uint8 ByteIdx;
    uint8 BitIdx;
    uint8 PnReq[7];
    PduInfoType Com_PduInfo;
    boolean PnEiraChangedFlag = FALSE;
    
    if(NM_MODE_BUS_SLEEP !=  UDPNM_GET_MODE(nmChannelHandle))
    {
        SchM_Enter_UdpNm_UDPNM_EXCLUSIVE_AREA_4();
        Bsw_MemCpy(PnReq, UdpNm_PnEiraNewReq, UDPNM_PN_INFO_LENGTH);
        for(ByteIdx = 0; ByteIdx < UDPNM_PN_INFO_LENGTH; ByteIdx++)
        {
            UdpNm_PnEiraNewReq[ByteIdx] = 0;
        }
        SchM_Exit_UdpNm_UDPNM_EXCLUSIVE_AREA_4();

        for(ByteIdx = 0; ByteIdx < UDPNM_PN_INFO_LENGTH; ByteIdx++)
        {
            if((UdpNm_PnEiraArray[ByteIdx] & PnReq[ByteIdx]) != PnReq[ByteIdx])
            {
                PnEiraChangedFlag = TRUE;                
                UdpNm_PnEiraArray[ByteIdx] |= PnReq[ByteIdx];
            }

            for(BitIdx = 0; BitIdx < 8; BitIdx++)
            {
                if(((PnReq[ByteIdx] >> BitIdx) & (uint8)0x01) != 0)
                {                    
                    UdpNm_PnEiraPnTimer[(ByteIdx * 8) + BitIdx] = (uint16)UDPNM_GET_PN_RESET_CNT;
                }

                if(UdpNm_PnEiraPnTimer[(ByteIdx * 8) + BitIdx] != 0)
                {
                    UdpNm_PnEiraPnTimer[(ByteIdx * 8) + BitIdx]--;
                    if(UdpNm_PnEiraPnTimer[(ByteIdx * 8) + BitIdx] == 0)
                    {                                                
                        UdpNm_PnEiraArray[ByteIdx] &= (~((uint8)0x01 << BitIdx));
                        PnEiraChangedFlag = TRUE;
                    }
                }
            }
        }

        if(PnEiraChangedFlag == TRUE)
        {        
            Com_PduInfo.SduLength = UDPNM_PN_INFO_LENGTH;
            Com_PduInfo.SduDataPtr = UdpNm_PnEiraArray;
            PduR_UdpNmRxIndication(UDPNM_PN_EIRA_RXNSDU_REF, &Com_PduInfo);
        }
    }
}
#endif/*(STD_ON == UDPNM_PN_EIRA_CALC_ENABLED)*/

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: UdpNm_PnEraHandling
*
* Description:
*
* Inputs:
*
* Outputs:
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, UDPNM_CODE) UdpNm_PnEraHandling
(
    const NetworkHandleType nmChannelHandle
)
{
    uint8 ByteIdx;
    uint8 BitIdx;
    uint8 PnReq[UDPNM_NUMBER_7];
    PduInfoType Com_PduInfo;
    boolean PnEraChangedFlag = FALSE;

    if(NM_MODE_BUS_SLEEP != UDPNM_GET_MODE(nmChannelHandle))
    {
        SchM_Enter_UdpNm_UDPNM_EXCLUSIVE_AREA_4();
        Bsw_MemCpy(PnReq, UdpNm_PnEraNewReq[nmChannelHandle], (uint32)UDPNM_PN_INFO_LENGTH);
        for(ByteIdx = (uint8)0; ByteIdx < UDPNM_PN_INFO_LENGTH; ByteIdx++)
        {
            UdpNm_PnEraNewReq[nmChannelHandle][ByteIdx] = (uint8)0;
        }
        SchM_Exit_UdpNm_UDPNM_EXCLUSIVE_AREA_4();

        for(ByteIdx = (uint8)0; ByteIdx < UDPNM_PN_INFO_LENGTH; ByteIdx++)
        {
            if((UdpNm_PnEraArray[nmChannelHandle][ByteIdx] & PnReq[ByteIdx]) != PnReq[ByteIdx])
            {
                PnEraChangedFlag = TRUE;                
                UdpNm_PnEraArray[nmChannelHandle][ByteIdx] |= PnReq[ByteIdx];
            }

            for(BitIdx = (uint8)0; BitIdx < (uint8)UDPNM_NUMBER_8; BitIdx++)
            {
                if(((PnReq[ByteIdx] >> BitIdx) & (uint8)0x01) != (uint8)0)
                {                    
                    UdpNm_PnEraPnTimer[nmChannelHandle][((uint8)ByteIdx * (uint8)UDPNM_NUMBER_8) + (uint8)BitIdx] = (uint16)UDPNM_GET_PN_RESET_CNT;
                }

                if(UdpNm_PnEraPnTimer[nmChannelHandle][((uint8)ByteIdx * (uint8)UDPNM_NUMBER_8) + (uint8)BitIdx] != (uint16)0)
                {
                    UdpNm_PnEraPnTimer[nmChannelHandle][((uint8)ByteIdx * (uint8)UDPNM_NUMBER_8) + (uint8)BitIdx]--;
                    if(UdpNm_PnEraPnTimer[nmChannelHandle][((uint8)ByteIdx * (uint8)UDPNM_NUMBER_8) + (uint8)BitIdx] == (uint16)0)
                    {
                        UdpNm_PnEraArray[nmChannelHandle][ByteIdx] &= (uint8)(~((uint32)0x01 << BitIdx));
                        PnEraChangedFlag = TRUE;
                    }
                }
            }
        }

        if(PnEraChangedFlag == TRUE)
        {            
            Com_PduInfo.SduLength = UDPNM_PN_INFO_LENGTH;
            Com_PduInfo.SduDataPtr = UdpNm_PnEraArray[nmChannelHandle];
            PduR_UdpNmRxIndication(UDPNM_PN_ERA_RXNSDU_REF(nmChannelHandle), &Com_PduInfo);
        }
    }
}

#endif/*(STD_ON == UDPNM_GLOBAL_PN_SUPPORT)*/

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: UdpNm__GetChannelIdFromTxPdu
*
* Description:
*
* Inputs:
*
* Outputs:
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(NetworkHandleType, UDPNM_CODE) UdpNm__GetChannelIdFromTxPdu
(
    const PduIdType PduId
)
{
    NetworkHandleType ChannelId = 0xff;
    NetworkHandleType i;

    for (i = (NetworkHandleType)0; (NetworkHandleType)i < UDPNM_NUMBER_OF_TXPDUID; (NetworkHandleType)i++)
    {
        if(PduId == UDPNM_TX_PDU_ID(i))
        {
            ChannelId = i;
            break;
        }
    }

    return ChannelId; 
}

#define UDPNM_STOP_SEC_CODE
#include "MemMap.h"

