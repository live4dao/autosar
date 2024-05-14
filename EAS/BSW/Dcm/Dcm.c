/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
*   File Name       : Dcm.c
********************************************************************************
*   Project/Product : AUTOSAR 4.2
*   Title           : Dcm.c
*   Author          : Hirain
********************************************************************************
*   Description: Main source file of the AUTOSAR Diagnositc communcation manager,
*                according to AUTOSAR_SWS_DiagnosticCommunicationManager.pdf
*                (Release 4.2) and ISO14229-1(2013).pdf.
*
********************************************************************************
*   Limitations: None
*
********************************************************************************
*
********************************************************************************
*   Revision History:
*
*   Version      Date         Initials          CR#       Descriptions
*   ---------   ----------    ------------  ----------   ---------------
*   01.00.00    13/09/2017    Feixiang.Dong     N/A       Beta
*   01.01.00    06/06/2018    Feixiang.Dong     N/A       Original
*   01.01.01    27/09/2018    Feixiang.Dong     N/A       EAS422_Dcm_20180927_01
*   01.01.02    28/11/2018    Feixiang.Dong     N/A       EAS422_Dcm_20181128_01
*   01.01.03    28/12/2018    Feixiang.Dong     N/A       EAS422_Dcm_20181228_01
*   01.01.04    28/01/2019    Feixiang.Dong     N/A       EAS422_Dcm_20190128_01
*   01.01.05    24/03/2019    Feixiang.Dong     N/A       EAS422_Dcm_20190324_01
*   01.01.06    23/04/2019    Feixiang.Dong     N/A       EAS422_Dcm_20190423_01
*   01.01.07    06/05/2019    Feixiang.Dong     N/A       EAS422_Dcm_20190506_01
*   01.01.08    17/07/2019    Feixiang.Dong     N/A       EAS422_Dcm_20190717_01
*   01.01.09    31/07/2019    Feixiang.Dong     N/A       EAS422_Dcm_20190731_01
*   01.01.10    19/08/2019    Feixiang.Dong     N/A       EAS422_Dcm_20190819_01
*   01.01.11    24/09/2019    Feixiang.Dong     N/A       EAS422_Dcm_20190924_01
*   01.01.12    18/10/2019    Feixiang.Dong     N/A       EAS422_Dcm_20191018_01
*   01.01.13    19/01/2020    Feixiang.Dong     N/A       EAS422_Dcm_20200119_01
*   01.01.14    13/03/2020    Feixiang.Dong     N/A       EAS422_Dcm_20200313_01
*   01.01.15    15/12/2020    Feixiang.Dong     N/A       EAS422_Dcm_20201215_01
*   01.01.16    22/12/2020    Feixiang.Dong     N/A       EAS422_Dcm_20201222_01
*   01.01.17    16/04/2021    Heyan.Li          N/A       EAS422_Dcm_20210416_01
*   01.01.18    10/05/2021    Feixiang.Dong     N/A       EAS422_Dcm_20210510_01
*   01.01.19    18/06/2021    Feixiang.Dong     N/A       EAS422_Dcm_20210618_01
*   01.01.20    27/09/2021    Feixiang.Dong     N/A       EAS422_Dcm_20210927_01
*   01.01.21    01/11/2021    Feixiang.Dong     N/A       EAS422_Dcm_20211101_01
*   01.01.22    25/10/2022    Feixiang.Dong     N/A       EAS422_Dcm_20221025_01
*   01.02.00    18/01/2023    Feixiang.Dong     N/A       EAS422_Dcm_20230118_01
*   01.02.01    21/07/2023    Feixiang.Dong     N/A       EAS422_Dcm_20230721_01
********************************************************************************
* END_FILE_HDR*/

/*******************************************************************************
* Includes
*******************************************************************************/
#include "Dcm.h"
#include "Dcm_Cbk.h"
#include "Dcm_Callout.h"
#include "Dcm_NvM.h"
#include "Dcm_Lcfg.h"
#if(DCM_CONFIG_VARIANTS == STD_CONFIG_VARIANTS_POSTBUILD)
#include "Dcm_PBcfg.h"
#endif
#if(STD_ON == DCM_DEM_SUPPORT)
#include "Dem_Dcm.h"
#endif
#if(STD_ON == DCM_DEV_ERROR_DETECT)
#include "Det.h"
#endif
#if(STD_ON == DCM_COMM_SUPPORT)
#include "ComM_Dcm.h"
#endif
#if(STD_ON == DCM_NVM_SUPPORT)
#include "NvM.h"
#endif
#if(DCM_BSWM_SUPPORT == STD_ON)
#include "BswM_Dcm.h"
#endif
#include "SchM_Dcm.h"
#include "Rte_Dcm.h"
#include "Bsw_Common.h"
#include "PduR_Dcm.h"
/*******************************************************************************
*   Version Check
*******************************************************************************/
#if(STD_ON == DCM_PRIVATE_VERSION_CHECK)
/* Check version of source file with cfg file */
#if((DCM_AR_RELEASE_MAJOR_VERSION != DCM_AR_RELEASE_MAJOR_VERSION_CFG)|| \
       (DCM_AR_RELEASE_MINOR_VERSION != DCM_AR_RELEASE_MINOR_VERSION_CFG))
#error "AutoSar Version Numbers of Dcm and its cfg file are different"
#endif

#if((DCM_SW_MAJOR_VERSION != DCM_SW_MAJOR_VERSION_CFG)|| \
       (DCM_SW_MINOR_VERSION != DCM_SW_MINOR_VERSION_CFG))
#error "SW Version Numbers of Dcm and its cfg file are different"
#endif

#endif/*#if(STD_ON == DCM_PRIVATE_VERSION_CHECK)*/

/*******************************************************************************
*   Macro
*******************************************************************************/
#if(STD_ON == DCM_DEV_ERROR_DETECT)
#define DCM_DET_ERROR_DETECT(cond, ApiId, errcode)  \
    DET_ERROR_DETECT((cond),DCM_MODULE_ID,DCM_INSTANCE_ID,(ApiId),(errcode))

#define DCM_DET_ERROR_DETECT_RET(cond, ApiId, errcode, ret) \
    DET_ERROR_DETECT_RET((cond),DCM_MODULE_ID,DCM_INSTANCE_ID,(ApiId),(errcode),(ret))

#define DCM_DET_REPORT_ERROR(ApiId, errcode)  \
    DET_REPORT_ERROR(DCM_MODULE_ID,DCM_INSTANCE_ID,(ApiId),(errcode))
#else
#define DCM_DET_ERROR_DETECT(cond, ApiId, errcode)
#define DCM_DET_ERROR_DETECT_RET(cond, ApiId, errcode, ret)
#define DCM_DET_REPORT_ERROR(ApiId, errcode)
#endif


#if(DCM_COMM_SUPPORT == STD_ON)
#define COMM_DCM_ACTIVEDIAGNOSTIC(i,j)         \
    ComM_DCM_ActiveDiagnostic(DCM_CFG_PROTOCOL_CONNECTION_MAIN_COMM_CHN(i,j))
#define COMM_DCM_INACTIVEDIAGNOSTIC(i,j)       \
    ComM_DCM_InactiveDiagnostic(DCM_CFG_PROTOCOL_CONNECTION_MAIN_COMM_CHN(i,j))
#else
#define COMM_DCM_ACTIVEDIAGNOSTIC(i,j)
#define COMM_DCM_INACTIVEDIAGNOSTIC(i,j)
#endif

#define DCM_DATA_CLEAR                         0U
#define DCM_DATA_U8_MAX                        0xFFU
#define DCM_UDS_NEG_RES_LEN                    3U

#define DCM_SID_INDEX                          0U
#define DCM_SUB_SID_INDEX                      1U
#define DCM_INDEX_1                            1U
#define DCM_INDEX_2                            2U
#define DCM_INDEX_3                            3U
#define DCM_INDEX_4                            4U
#define DCM_INDEX_5                            5U
#define DCM_INDEX_6                            6U
#define DCM_INDEX_7                            7U
#define DCM_INDEX_8                            8U

#define DCM_SID_RESP_OFFSET                    ((uint8)0x40)

#define DCM_SUPPRESS_POS_RSP_MASK              ((uint8)0x80)
#define DCM_SUPPRESS_POS_RSP_MASK_FLIP         ((uint8)0x7F)

#if((DCM_CAR_PLATFORM == DCM_NISSAN_PLATFORM) || (DCM_CAR_PLATFORM == DCM_RNDS_PLATFORM))
#define DCM_RNDS_READ_LENGTH                   3U
#define DCM_NISSAN_READ_LENGTH                 4U
#define DCM_RNDS_READ_DATA_LENGTH              32U
#define DCM_RNDS_READ_READ_ID                  ((uint8)0xDF)
#define DCM_RNDS_READ_WRITE_ID                 ((uint8)0xEC)
#define DCM_RNDS_READ_IO_ID                    ((uint8)0xED)
#define DCM_RNDS_READ_ROUTINE_ID               ((uint8)0xEE)
#define DCM_RNDS_READ_ID_HIGH_BYTE             ((uint8)0xDF)
#define DCM_RNDS_ID_HIGH_MASK                  ((uint16)0xFF00)
#define DCM_RNDS_ID_LOW_MASK                   ((uint16)0x00FF)
#endif

/*UDS Service length:fixed*/
#define DCM_10_11_3E_REQ_LEN                   2U
#if(DCM_RESPONSE_WITHP2TIMER==STD_ON)
#define DCM_10_RESPONSE_LENGTH                 6U
#else
#define DCM_10_RESPONSE_LENGTH                 2U
#endif

#if(DCM_UDS_14_SERVICE == STD_ON)
#define DCM_14_REQ_LEN                         4U
#endif

#if(DCM_UDS_28_SERVICE == STD_ON)
#define DCM_28_REQ_LEN                         3U
#define DCM_28_REQ_LEN_ENHANCED                5U
#endif

#if(DCM_UDS_2C_SERVICE == STD_ON)
#define DCM_2C_01_MIN_REQ_LEN                  8U
#define DCM_2C_02_MIN_REQ_LEN                  7U
#define DCM_2C_03_MIN_REQ_LEN                  2U
#endif

#if(DCM_UDS_85_SERVICE == STD_ON)
#define DCM_85_REQ_LEN                         2U
#endif

#if(DCM_UDS_87_SERVICE == STD_ON)
#define DCM_87_FIXED_LEN                       3U
#define DCM_87_SPECIFIC_LEN                    5U
#define DCM_87_TRANSITION_LEN                  2U
#endif

/*Used by OBD services start*/
#define DCM_OBD_AVAILABILITY_PARAMETER         (uint8)0x20
#define DCM_OBD_AVAILABILITY_PARA0             (uint8)0x00
#define DCM_OBD_AVAILABILITY_PARA1             (uint8)0x20
#define DCM_OBD_AVAILABILITY_PARA2             (uint8)0x40
#define DCM_OBD_AVAILABILITY_PARA3             (uint8)0x60
#define DCM_OBD_AVAILABILITY_PARA4             (uint8)0x80
#define DCM_OBD_AVAILABILITY_PARA5             (uint8)0xA0
#define DCM_OBD_AVAILABILITY_PARA6             (uint8)0xC0
#define DCM_OBD_AVAILABILITY_PARA7             (uint8)0xE0

#define DCM_OBD_REQUEST_MAX_LENGTH             7U
/*Used by OBD services end*/

#define Make16Bit(HiByte,LoByte)         \
    ((uint16)((((uint16)(HiByte)) << 8U) \
              |((uint16)(LoByte))))
#define Make32Bit(HiByte1,HiByte0,MiByte,LoByte) \
    ((uint32)((((uint32)(HiByte1)) << 24U)       \
              |((uint32)(HiByte0) << 16U)        \
              |((uint32)(MiByte) << 8U)          \
              |((uint32)(LoByte))))

#if(DCM_CONFIG_VARIANTS == STD_CONFIG_VARIANTS_LINKTIME)
/*ECUC_Dcm_00693,DcmDslDiagRespMaxNumRespPend*/
#define DCM_CFG_RESP_PEND_MAX_NUM              (Dcm_DslDiagResp.DcmDslDiagRespMaxNumRespPend)
/*ECUC_Dcm_00914,DcmDslDiagRespOnSecondDeclinedRequest*/
#define DCM_CFG_RESP_ON_SECOND_REQ             (Dcm_DslDiagResp.DcmDslDiagRespOnSecondDeclinedRequest)

/*ECUC_Dcm_00966,DcmDspDDDIDcheckPerSourceDID*/
#define DCM_CFG_DSP_DDDID_CHECK_SRC_DID        (Dcm_DspGeneral.DcmDspDDDIDcheckPerSourceDID)
/*ECUC_Dcm_00987,DcmDspDataDefaultEndianness*/
#define DCM_CFG_DSP_DEFAULT_ENDIANNESS         (Dcm_DspGeneral.DcmDspDataDefaultEndianness)
/*ECUC_Dcm_01061,DcmDspEnableObdMirror*/
#define DCM_CFG_DSP_EN_OBD_MIRROR              (Dcm_DspGeneral.DcmDspEnableObdMirror)
/*ECUC_Dcm_00638,DcmDspMaxDidToRead,1..65535*/
#define DCM_CFG_DSP_MAX_DID_READ               (Dcm_DspGeneral.DcmDspMaxDidToRead)
/*ECUC_Dcm_00818,DcmDspPowerDownTime,valid:00-FE,unit:s*/
#define DCM_CFG_DSP_POWER_DOWN_TIME            (Dcm_DspGeneral.DcmDspPowerDownTime)
/*ECUC_Dcm_01039,DcmResponseToEcuReset*/
#define DCM_CFG_DSP_RESP_TO_RESET              (Dcm_DspGeneral.DcmResponseToEcuReset)
#if(DCM_UDS_2A_SERVICE == STD_ON)
/*ECUC_Dcm_00956,DcmDspMaxPeriodicDidToRead,1..65535*/
#define DCM_CFG_DSP_MAX_PERIODIC_DID_READ      (Dcm_DspGeneral.DcmDspMaxPeriodicDidToRead)
/*ECUC_Dcm_00962,DcmDspMaxPeriodicDidScheduler,1..255*/
#define DCM_CFG_DSP_MAX_PERIODIC_DID_SCHEDULER (Dcm_DspGeneral.DcmDspMaxPeriodicDidScheduler)
#endif
#endif


#define DCM_CFG_RXPDU_TO_PROTOCOL_MAP(i)       (Dcm_RxPduToProtocolMap[i])
#define DCM_CFG_PROTOCOL_USED(i)               (Dcm_DslProtocolRow[i].DcmDslProtocolRowUsed)
#define DCM_CFG_PROTOCOL_ID(i)                 (Dcm_DslProtocolRow[i].DcmDslProtocolID)
#define DCM_CFG_PROTOCOL_CONNECTION_NUM(i)     (Dcm_DslProtocolRow[i].NumOfConnection)
#define DCM_CFG_PROTOCOL_CONNECTION(i)         (Dcm_DslProtocolRow[i].DcmDslConnection)
#define DCM_CFG_PROTOCOL_PRIORITY(i)           (Dcm_DslProtocolRow[i].DcmDslProtocolPriority)   
#define DCM_CFG_PROTOCOL_CONNECTION_MAIN(i,j)                \
    (Dcm_DslProtocolRow[i].DcmDslConnection[j].DcmDslMainConnection)
#define DCM_CFG_PROTOCOL_CONNECTION_MAIN_TESTER_ADDR(i,j)    \
    (DCM_CFG_PROTOCOL_CONNECTION_MAIN(i,j)->DcmDslProtocolRxTesterSourceAddr)
#define DCM_CFG_PROTOCOL_CONNECTION_MAIN_COMM_CHN(i,j)       \
    (DCM_CFG_PROTOCOL_CONNECTION_MAIN(i,j)->DcmDslProtocolComMChannelRef)
#define DCM_CFG_PROTOCOL_CONNECTION_MAIN_RX_NUM(i,j)         \
    (DCM_CFG_PROTOCOL_CONNECTION_MAIN(i,j)->NumOfRxPdu)
#define DCM_CFG_PROTOCOL_CONNECTION_MAIN_RX(i,j)             \
    (DCM_CFG_PROTOCOL_CONNECTION_MAIN(i,j)->DcmDslProtocolRx)
#define DCM_CFG_PROTOCOL_CONNECTION_MAIN_RX_PDUID(i,j,k)     \
    (DCM_CFG_PROTOCOL_CONNECTION_MAIN(i,j)->DcmDslProtocolRx[k].DcmDslProtocolRxPduId)
#define DCM_CFG_PROTOCOL_CONNECTION_MAIN_RX_ADDR_TYPE(i,j,k) \
    (DCM_CFG_PROTOCOL_CONNECTION_MAIN(i,j)->DcmDslProtocolRx[k].DcmDslProtocolRxAddrType)
#define DCM_CFG_PROTOCOL_CONNECTION_MAIN_TX(i,j)             \
    (DCM_CFG_PROTOCOL_CONNECTION_MAIN(i,j)->DcmDslProtocolTx)
#define DCM_CFG_PROTOCOL_CONNECTION_MAIN_TX_PDUID(i,j)       \
    (DCM_CFG_PROTOCOL_CONNECTION_MAIN(i,j)->DcmDslProtocolTx[0].DcmDslProtocolTxPduRef)
#define DCM_CFG_PROTOCOL_CONNECTION_MAIN_TX_CONID(i,j)       \
    (DCM_CFG_PROTOCOL_CONNECTION_MAIN(i,j)->DcmDslProtocolTx[0].DcmDslTxConfirmationPduId)
#if(DCM_UDS_2A_SERVICE == STD_ON)
#define DCM_CFG_PROTOCOL_CONNECTION_PERIODIC(i,j)            \
    (Dcm_DslProtocolRow[i].DcmDslConnection[j].DcmDslPeriodicTransmission)
#define DCM_CFG_PROTOCOL_CONNECTION_PERIODIC_NUM(i,j)        \
    (DCM_CFG_PROTOCOL_CONNECTION_PERIODIC(i,j)->NumOfPeriodicConnection)
#define DCM_CFG_PROTOCOL_CONNECTION_PERIODIC_TX_PDUID(i,j,k) \
    (DCM_CFG_PROTOCOL_CONNECTION_PERIODIC(i,j)->DcmDslPeriodicConnection[k].DcmDslPeriodicTxPduRef)
#define DCM_CFG_PROTOCOL_CONNECTION_PERIODIC_TX_CONID(i,j,k) \
    (DCM_CFG_PROTOCOL_CONNECTION_PERIODIC(i,j)->DcmDslPeriodicConnection[k].DcmDslPeriodicTxConfirmationPduId)
#endif

#define DCM_CFG_PROTOCOL_RXBUFFER_SIZE(i)      \
    (Dcm_DslProtocolRow[i].DcmDslProtocolRxBufferRef.DcmDslBufferSize)
#define DCM_CFG_PROTOCOL_RXBUFFER(i)           \
    (Dcm_DslProtocolRow[i].DcmDslProtocolRxBufferRef.DataPtr)
#define DCM_CFG_PROTOCOL_TXBUFFER_SIZE(i)      \
    (Dcm_DslProtocolRow[i].DcmDslProtocolTxBufferRef.DcmDslBufferSize)
#define DCM_CFG_PROTOCOL_TXBUFFER(i)           \
    (Dcm_DslProtocolRow[i].DcmDslProtocolTxBufferRef.DataPtr)
#define DCM_CFG_PROTOCOL_RPOTTB(i)             \
    (Dcm_DslProtocolRow[i].DcmSendRespPendOnTransToBoot)
#define DCM_CFG_PROTOCOL_SIDTABLE(i)           \
    (Dcm_DslProtocolRow[i].DcmDslProtocolSIDTable)
#define DCM_CFG_PROTOCOL_SIDTABLE_ID(i)        \
    (Dcm_DslProtocolRow[i].DcmDslProtocolSIDTable->DcmDsdSidTabId)
#define DCM_CFG_PROTOCOL_SIDTABLE_S_NUM(i)     \
    (Dcm_DslProtocolRow[i].DcmDslProtocolSIDTable->NumOfService)
#define DCM_CFG_PROTOCOL_SIDTABLE_S(i)         \
    (Dcm_DslProtocolRow[i].DcmDslProtocolSIDTable->DcmDsdService)
#define DCM_CFG_PROTOCOL_S3SERVER(i)           \
    (Dcm_DslProtocolRow[i].S3Server)


#define DCM_CFG_SESSION_NUM                    (Dcm_DspSession[DCM_ACTIVE_PROTOCOL_ID].NumOfSessionRow)
#define DCM_CFG_SESSION_ROW                    (Dcm_DspSession[DCM_ACTIVE_PROTOCOL_ID].DcmDspSessionRow)
#define DCM_CFG_SESSION_BOOT(i)                (DCM_CFG_SESSION_ROW[i].DcmDspSessionBoot)
#define DCM_CFG_SESSION_LEVEL(i)               (DCM_CFG_SESSION_ROW[i].DcmDspSessionLevel)
#define DCM_CFG_SESSION_MASK(i)                (DCM_CFG_SESSION_ROW[i].DcmDspSessionMask)
#define DCM_CFG_SESSION_P2(i)                  (DCM_CFG_SESSION_ROW[i].DcmDspSessionP2ServerMax)
#define DCM_CFG_SESSION_P2STAR(i)              (DCM_CFG_SESSION_ROW[i].DcmDspSessionP2StarServerMax)


#if(DCM_UDS_27_SERVICE == STD_ON)
#define DCM_CFG_SECURITY_NUM(i)                (Dcm_DspSecurity[i].NumOfSecurityRow)
#define DCM_CFG_SECURITY_ROW_I(i)              (Dcm_DspSecurity[i].DcmDspSecurityRow)
#define DCM_CFG_SECURITY_ROW                   (Dcm_DspSecurity[DCM_ACTIVE_PROTOCOL_ID].DcmDspSecurityRow)
#define DCM_CFG_SECURITY_ADR_SIZE(i)           \
    (DCM_CFG_SECURITY_ROW[i].DcmDspSecurityADRSize)
#define DCM_CFG_SECURITY_KEY_SIZE(i)           \
    (DCM_CFG_SECURITY_ROW[i].DcmDspSecurityKeySize)
#define DCM_CFG_SECURITY_SEED_SIZE(i)          \
    (DCM_CFG_SECURITY_ROW[i].DcmDspSecuritySeedSize)
#define DCM_CFG_SECURITY_ATTEMPFNC_EN(i)       \
    (DCM_CFG_SECURITY_ROW[i].DcmDspSecurityAttemptCounterEnabled)
#define DCM_CFG_SECURITY_GET_ATTEMP_FNC(i)     \
    (DCM_CFG_SECURITY_ROW[i].DcmDspSecurityGetAttemptCounterFnc)
#define DCM_CFG_SECURITY_SET_ATTEMP_FNC(i)     \
    (DCM_CFG_SECURITY_ROW[i].DcmDspSecuritySetAttemptCounterFnc)
#define DCM_CFG_SECURITY_GETSEED_FNC_INDEX(i)  \
    (DCM_CFG_SECURITY_ROW[i].DcmDspSecurityGetSeedFncIndex)
#define DCM_CFG_SECURITY_COMPAREKEY_FNC(i)     \
    (DCM_CFG_SECURITY_ROW[i].DcmDspSecurityCompareKeyFnc)
#define DCM_CFG_SECURITY_DELAYTIME(i)          \
    ((DCM_CFG_SECURITY_ROW[i].DcmDspSecurityDelayTime)/DCM_TASK_TIME)
#define DCM_CFG_SECURITY_ATTEMPNUM(i)          \
    (DCM_CFG_SECURITY_ROW[i].DcmDspSecurityNumAttDelay)
#define DCM_CFG_SECURITY_DELAYTIMEONBOOT(i)    \
    ((DCM_CFG_SECURITY_ROW[i].DcmDspSecurityDelayTimeOnBoot)/DCM_TASK_TIME)
#define DCM_CFG_SECURITY_PORT(i)               \
    (DCM_CFG_SECURITY_ROW[i].DcmDspSecurityUsePort)
#define DCM_CFG_SECURITY_MASK(i)               \
    (DCM_CFG_SECURITY_ROW[i].DcmDspSecurityMask)
#define DCM_CFG_SECURITY_GETSEED_FNC_A(i)      \
    (Dcm_DspSecurity[DCM_ACTIVE_PROTOCOL_ID].DcmDspGetSeedFncATable[i])
#define DCM_CFG_SECURITY_GETSEED_FNC_B(i)      \
    (Dcm_DspSecurity[DCM_ACTIVE_PROTOCOL_ID].DcmDspGetSeedFncBTable[i])
#endif

#if(DCM_UDS_28_SERVICE == STD_ON)
#define DCM_CFG_COM_CTRL                       (Dcm_DspComControl[DCM_ACTIVE_PROTOCOL_ID])

#define DCM_CFG_COM_ALLCHL_NUM                 (DCM_CFG_COM_CTRL.NumOfControlAllChannel)
#define DCM_CFG_COM_ALLCHL                     (DCM_CFG_COM_CTRL.DcmDspComControlAllChannel)
#define DCM_CFG_COM_ALLCHL_USED(i)             \
    (DCM_CFG_COM_ALLCHL[i].DcmDspComControlAllChannelUsed)
#define DCM_CFG_COM_ALLCHL_REF(i)              \
    (DCM_CFG_COM_ALLCHL[i].DcmDspAllComMChannelRef)
#define DCM_CFG_COM_ALLCHL_SWITCH_FNC(i)       \
    (DCM_CFG_COM_ALLCHL[i].SwitchCommunicationControlAllChannelFnc)
#define DCM_CFG_COM_SPECHL_NUM                 (DCM_CFG_COM_CTRL.NumOfControlSpecificChannel)
#define DCM_CFG_COM_SPECHL                     (DCM_CFG_COM_CTRL.DcmDspComControlSpecificChannel)
#define DCM_CFG_COM_SPECHL_USED(i)             \
    (DCM_CFG_COM_SPECHL[i].DcmDspComControlSpecificChannelUsed)
#define DCM_CFG_COM_SPECHL_REF(i)              \
    (DCM_CFG_COM_SPECHL[i].DcmDspComMChannelRef)
#define DCM_CFG_COM_SPECHL_SWITCH_FNC(i)       \
    (DCM_CFG_COM_SPECHL[i].SwitchCommunicationControlSpecificChannelFnc)
#define DCM_CFG_COM_SPECHL_NETNUN(i)           \
    (DCM_CFG_COM_SPECHL[i].DcmDspSubnetNumber)
#define DCM_CFG_COM_SUBNODE_NUM                (DCM_CFG_COM_CTRL.NumOfControlSubNode)
#define DCM_CFG_COM_SUBNODE                    (DCM_CFG_COM_CTRL.DcmDspComControlSubNode)
#define DCM_CFG_COM_SUBNODE_USED(i)            \
    (DCM_CFG_COM_SUBNODE[i].DcmDspComControlSubNodeUsed)
#define DCM_CFG_COM_SUBNODE_CHLREF(i)          \
    (DCM_CFG_COM_SUBNODE[i].DcmDspComControlSubNodeComMChannelRef)
#define DCM_CFG_COM_SUBNODE_CHL_SWITCH_FNC(i)  \
    (DCM_CFG_COM_SUBNODE[i].SwitchCommunicationControlSubNodeFnc)
#define DCM_CFG_COM_SUBNODE_ID(i)              \
    (DCM_CFG_COM_SUBNODE[i].DcmDspComControlSubNodeId)
#endif

#if((DCM_UDS_22_SERVICE == STD_ON)||(DCM_UDS_2A_SERVICE == STD_ON) \
  ||(DCM_UDS_2C_SERVICE == STD_ON)||(DCM_UDS_2E_SERVICE == STD_ON) \
  ||(DCM_UDS_2F_SERVICE == STD_ON))

#define DCM_CFG_DID_NUM                        (Dcm_DspDid[DCM_ACTIVE_PROTOCOL_ID].NumOfDid)
#define DCM_CFG_DID_TABLE                      (Dcm_DspDid[DCM_ACTIVE_PROTOCOL_ID].Dcm_DspDidTable)
#define DCM_CFG_DATA                           (Dcm_DspData[DCM_ACTIVE_PROTOCOL_ID])
#define DCM_CFG_DATA_TABLE                     (Dcm_DspData[DCM_ACTIVE_PROTOCOL_ID].DcmDspDataTable)

#if(DCM_CONFIG_VARIANTS != STD_CONFIG_VARIANTS_POSTBUILD)
#define DCM_CFG_DID_USED(i)                    (DCM_CFG_DID_TABLE[i].DcmDspDidUsed)
#else

#endif
#define DCM_CFG_DID_ID(i)                      (DCM_CFG_DID_TABLE[i].DcmDspDidIdentifier)
#define DCM_CFG_DID_SIGNAL_NUM(i)              (DCM_CFG_DID_TABLE[i].NumOfDidSignal)
#define DCM_CFG_DID_SIGNAL(i)                  (DCM_CFG_DID_TABLE[i].DcmDspDidSignal)


#define DCM_CFG_DATA_USEPORT(i)                (DCM_CFG_DATA_TABLE[i].DcmDspDataUsePort)
#define DCM_CFG_DATA_SIZE(i)                   (DCM_CFG_DATA_TABLE[i].DcmDspDataSize)
#define DCM_CFG_DATA_TYPE(i)                   (DCM_CFG_DATA_TABLE[i].DcmDspDataType)
#if(DCM_NVM_SUPPORT == STD_ON)
#define DCM_CFG_DATA_BLOCKID(i)                (DCM_CFG_DATA_TABLE[i].DcmDspDataBlockIdRef)
#endif/*#if(DCM_NVM_SUPPORT == STD_ON)*/
#endif

#if((DCM_UDS_22_SERVICE == STD_ON)||(DCM_UDS_2A_SERVICE == STD_ON))
#define DCM_CFG_DID_INFO_READ(i)               (DCM_CFG_DID_TABLE[i].DcmDspDidInfoRef.DcmDspDidRead)
#endif
#if((DCM_UDS_22_SERVICE == STD_ON)||(DCM_UDS_2A_SERVICE == STD_ON)||(DCM_UDS_2F_SERVICE == STD_ON))
#define DCM_CFG_DATA_CONDITION_EN(i)           (DCM_CFG_DATA_TABLE[i].DcmDspDataConditionCheckReadFncUsed)
#define DCM_CFG_DATA_CONDITION_CHECK_FNC_INDEX(i) \
    (DCM_CFG_DATA_TABLE[i].DcmDspDataConditionCheckReadFncIndex)
#define DCM_CFG_DATA_LENGTH_FNC_INDEX(i)       (DCM_CFG_DATA_TABLE[i].DcmDspDataReadDataLengthFncIndex)
#define DCM_CFG_DATA_READ_FNC_INDEX(i)         (DCM_CFG_DATA_TABLE[i].DcmDspDataReadFncIndex)
#define DCM_CFG_DATA_CONDITION_CHECK_FNC_A(i)  (DCM_CFG_DATA.DcmDspDataConditionCheckReadFncATable[i])
#define DCM_CFG_DATA_CONDITION_CHECK_FNC_B(i)  (DCM_CFG_DATA.DcmDspDataConditionCheckReadFncBTable[i])
#define DCM_CFG_DATA_LENGTH_FNC_A(i)           (DCM_CFG_DATA.DcmDspDataReadDataLengthFncATable[i])
#define DCM_CFG_DATA_LENGTH_FNC_B(i)           (DCM_CFG_DATA.DcmDspDataReadDataLengthFncBTable[i])
#define DCM_CFG_DATA_READ_FNC_A(i)             (DCM_CFG_DATA.DcmDspDataReadDataFncATable[i])
#define DCM_CFG_DATA_READ_FNC_B(i)             (DCM_CFG_DATA.DcmDspDataReadDataFncBTable[i])
#define DCM_CFG_DATA_READ_FNC_C(i)             (DCM_CFG_DATA.DcmDspDataReadDataFncCTable[i])
#endif

#if(DCM_UDS_2A_SERVICE == STD_ON)
#define DCM_CFG_2A_FAST_RATE                   \
    (Dcm_DspPeriodicTransmission.DcmDspPeriodicTransmissionFastRate)
#define DCM_CFG_2A_MEDIUM_RATE                 \
    (Dcm_DspPeriodicTransmission.DcmDspPeriodicTransmissionMediumRate)
#define DCM_CFG_2A_SLOW_RATE                   \
    (Dcm_DspPeriodicTransmission.DcmDspPeriodicTransmissionSlowRate)
#endif

#if(DCM_UDS_2C_SERVICE == STD_ON)
#define DCM_CFG_DID_INFO_DDDID_MAX_ELE(i)      \
    (DCM_CFG_DID_TABLE[i].DcmDspDidInfoRef.DcmDspDDDIDMaxElements)
#define DCM_CFG_DID_INFO_DYN_DEF(i)            \
    (DCM_CFG_DID_TABLE[i].DcmDspDidInfoRef.DcmDspDidDynamicallyDefined)
#define DCM_CFG_DID_INFO_DDDID_BUF_INDEX(i)    \
    (DCM_CFG_DID_TABLE[i].DcmDspDidInfoRef.DcmDspDDDIDBufferIndex)
#endif

#if(DCM_UDS_2E_SERVICE == STD_ON)
#define DCM_CFG_DID_INFO_WRITE(i)              (DCM_CFG_DID_TABLE[i].DcmDspDidInfoRef.DcmDspDidWrite)
#define DCM_CFG_DATA_WRITE_FNC_INDEX(i)        (DCM_CFG_DATA_TABLE[i].DcmDspDataWriteFncIndex)
#define DCM_CFG_DATA_WRITE_FNC_A(i)            (DCM_CFG_DATA.DcmDspDataWriteDataFncATable[i])
#define DCM_CFG_DATA_WRITE_FNC_B(i)            (DCM_CFG_DATA.DcmDspDataWriteDataFncBTable[i])
#define DCM_CFG_DATA_WRITE_FNC_C(i)            (DCM_CFG_DATA.DcmDspDataWriteDataFncCTable[i])
#define DCM_CFG_DATA_WRITE_FNC_D(i)            (DCM_CFG_DATA.DcmDspDataWriteDataFncDTable[i])
#endif

#if(DCM_UDS_2F_SERVICE == STD_ON)
#define DCM_CFG_DID_INFO_CONTROL(i)            (DCM_CFG_DID_TABLE[i].DcmDspDidInfoRef.DcmDspDidControl)
#define DCM_CFG_DID_CONTROL_MASK(i)            (DCM_CFG_DID_INFO_CONTROL(i)->DcmDspDidControlMask)
#define DCM_CFG_DID_CONTROL_MASK_SIZE(i)       (DCM_CFG_DID_INFO_CONTROL(i)->DcmDspDidControlMaskSize)
#define DCM_CFG_DID_CONTROL_FREEZE(i)          (DCM_CFG_DID_INFO_CONTROL(i)->DcmDspDidFreezeCurrentState)
#define DCM_CFG_DID_CONTROL_RESET(i)           (DCM_CFG_DID_INFO_CONTROL(i)->DcmDspDidResetToDefault)
#define DCM_CFG_DID_CONTROL_SHORT(i)           (DCM_CFG_DID_INFO_CONTROL(i)->DcmDspDidShortTermAdjustment)
#define DCM_CFG_DID_CONTROL_EN_MASK_NUM(i)     (DCM_CFG_DID_INFO_CONTROL(i)->NumOfControlEnableMask)
#define DCM_CFG_DID_CONTROL_EN_MASK(i)         (DCM_CFG_DID_INFO_CONTROL(i)->DcmDspDidControlEnableMask)
#define DCM_CFG_DID_CONTROL_EN_MASK_POS(i,j)   \
    (DCM_CFG_DID_CONTROL_EN_MASK(i)[j].DcmDspDidControlMaskBitPosition)
#define DCM_CFG_DID_CONTROL_ADDRREF(i)         (DCM_CFG_DID_INFO_CONTROL(i)->DcmDspDidControlSupportAddress)
#define DCM_CFG_DID_CONTROL_SESREF(i)          (DCM_CFG_DID_INFO_CONTROL(i)->DcmDspDidControlSessionRef)
#if(DCM_UDS_27_SERVICE == STD_ON)
#define DCM_CFG_DID_CONTROL_SECREF(i)          (DCM_CFG_DID_INFO_CONTROL(i)->DcmDspDidControlSecurityLevelRef)
#endif
#define DCM_CFG_DATA_RETURN_FNC_INDEX(i)       (DCM_CFG_DATA_TABLE[i].DcmDspDataReturnControlToEcuFncIndex)
#define DCM_CFG_DATA_RESET_FNC_INDEX(i)        (DCM_CFG_DATA_TABLE[i].DcmDspDataResetToDefaultFncIndex)
#define DCM_CFG_DATA_FREEZE_FNC_INDEX(i)       (DCM_CFG_DATA_TABLE[i].DcmDspDataFreezeCurrentStateFncIndex)
#define DCM_CFG_DATA_SHORT_FNC_INDEX(i)        (DCM_CFG_DATA_TABLE[i].DcmDspDataShortTermAdjustmentFncIndex)

#define DCM_CFG_DATA_RETURN_FNC_C(i)           (DCM_CFG_DATA.DcmDspDataReturnControlToEcuFncCTable[i])
#define DCM_CFG_DATA_RETURN_FNC_D(i)           (DCM_CFG_DATA.DcmDspDataReturnControlToEcuFncDTable[i])

#define DCM_CFG_DATA_RESET_FNC_A(i)            (DCM_CFG_DATA.DcmDspDataResetToDefaultFncATable[i])
#define DCM_CFG_DATA_RESET_FNC_B(i)            (DCM_CFG_DATA.DcmDspDataResetToDefaultFncBTable[i])
#define DCM_CFG_DATA_RESET_FNC_C(i)            (DCM_CFG_DATA.DcmDspDataResetToDefaultFncCTable[i])
#define DCM_CFG_DATA_RESET_FNC_D(i)            (DCM_CFG_DATA.DcmDspDataResetToDefaultFncDTable[i])

#define DCM_CFG_DATA_FREEZE_FNC_A(i)           (DCM_CFG_DATA.DcmDspDataFreezeCurrentStateFncATable[i])
#define DCM_CFG_DATA_FREEZE_FNC_B(i)           (DCM_CFG_DATA.DcmDspDataFreezeCurrentStateFncBTable[i])
#define DCM_CFG_DATA_FREEZE_FNC_C(i)           (DCM_CFG_DATA.DcmDspDataFreezeCurrentStateFncCTable[i])
#define DCM_CFG_DATA_FREEZE_FNC_D(i)           (DCM_CFG_DATA.DcmDspDataFreezeCurrentStateFncDTable[i])

#define DCM_CFG_DATA_SHORT_FNC_A(i)            (DCM_CFG_DATA.DcmDspDataShortTermAdjustmentFncATable[i])
#define DCM_CFG_DATA_SHORT_FNC_B(i)            (DCM_CFG_DATA.DcmDspDataShortTermAdjustmentFncBTable[i])
#define DCM_CFG_DATA_SHORT_FNC_C(i)            (DCM_CFG_DATA.DcmDspDataShortTermAdjustmentFncCTable[i])
#define DCM_CFG_DATA_SHORT_FNC_D(i)            (DCM_CFG_DATA.DcmDspDataShortTermAdjustmentFncDTable[i])
#define DCM_CFG_DATA_SHORT_FNC_E(i)            (DCM_CFG_DATA.DcmDspDataShortTermAdjustmentFncETable[i])
#define DCM_CFG_DATA_SHORT_FNC_F(i)            (DCM_CFG_DATA.DcmDspDataShortTermAdjustmentFncFTable[i])
#define DCM_CFG_DATA_SHORT_FNC_G(i)            (DCM_CFG_DATA.DcmDspDataShortTermAdjustmentFncGTable[i])
#define DCM_CFG_DATA_SHORT_FNC_H(i)            (DCM_CFG_DATA.DcmDspDataShortTermAdjustmentFncHTable[i])
#endif/*#if(DCM_UDS_2F_SERVICE == STD_ON)*/

#if((DCM_UDS_23_SERVICE == STD_ON)||(DCM_UDS_3D_SERVICE == STD_ON) \
    || (DCM_UDS_34_SERVICE == STD_ON)||(DCM_UDS_35_SERVICE == STD_ON))
#define DCM_CFG_MEM                            (Dcm_DspMemory[DCM_ACTIVE_PROTOCOL_ID])
#define DCM_CFG_MEM_FORMAT_NUM                 \
    (DCM_CFG_MEM.DcmDspAddressAndLengthFormatIdentifier.NumOfFormat)
#define DCM_CFG_MEM_FORMAT(i)                  \
    (DCM_CFG_MEM.DcmDspAddressAndLengthFormatIdentifier.DcmDspSupportedAddressAndLengthFormatIdentifier[i])
#define DCM_CFG_MEM_ID_NUM                     (DCM_CFG_MEM.NumOfMemoryId)
#define DCM_CFG_MEM_ID_INFO(i)                 (DCM_CFG_MEM.DcmDspMemoryIdInfo[i])
#define DCM_CFG_MEM_ID_VALUE(i)                (DCM_CFG_MEM_ID_INFO(i).DcmDspMemoryIdValue)

#if((DCM_UDS_23_SERVICE == STD_ON)||(DCM_UDS_35_SERVICE == STD_ON))
#define DCM_CFG_MEM_ID_READ_NUM(i)             (DCM_CFG_MEM_ID_INFO(i).NumofReadMemory)
#define DCM_CFG_MEM_ID_READ_INFO(i)            (DCM_CFG_MEM_ID_INFO(i).DcmDspReadMemoryRangeInfo)
#define DCM_CFG_MEM_ID_READ_HIGH(i,j)          \
    (DCM_CFG_MEM_ID_INFO(i).DcmDspReadMemoryRangeInfo[j].DcmDspReadMemoryRangeHigh)
#define DCM_CFG_MEM_ID_READ_LOW(i,j)           \
    (DCM_CFG_MEM_ID_INFO(i).DcmDspReadMemoryRangeInfo[j].DcmDspReadMemoryRangeLow)
#if(STD_ON == DCM_UDS_27_SERVICE)
#define DCM_CFG_MEM_ID_READ_SECREF(i,j)        \
    (DCM_CFG_MEM_ID_INFO(i).DcmDspReadMemoryRangeInfo[j].DcmDspReadMemoryRangeSecurityLevelRef)
#endif
#define DCM_CFG_MEM_ID_READ_SESREF(i,j)        \
    (DCM_CFG_MEM_ID_INFO(i).DcmDspReadMemoryRangeInfo[j].DcmDspReadMemoryRangeSessionLevelRef)
#endif

#if((DCM_UDS_3D_SERVICE == STD_ON)||(DCM_UDS_34_SERVICE == STD_ON))
#define DCM_CFG_MEM_ID_WRITE_NUM(i)            (DCM_CFG_MEM_ID_INFO(i).NumofWriteMemory)
#define DCM_CFG_MEM_ID_WRITE_INFO(i)           (DCM_CFG_MEM_ID_INFO(i).DcmDspWriteMemoryRangeInfo)
#define DCM_CFG_MEM_ID_WRITE_HIGH(i,j)         \
    (DCM_CFG_MEM_ID_INFO(i).DcmDspWriteMemoryRangeInfo[j].DcmDspWriteMemoryRangeHigh)
#define DCM_CFG_MEM_ID_WRITE_LOW(i,j)          \
    (DCM_CFG_MEM_ID_INFO(i).DcmDspWriteMemoryRangeInfo[j].DcmDspWriteMemoryRangeLow)
#if(STD_ON == DCM_UDS_27_SERVICE)
#define DCM_CFG_MEM_ID_WRITE_SECREF(i,j)       \
    (DCM_CFG_MEM_ID_INFO(i).DcmDspWriteMemoryRangeInfo[j].DcmDspWriteMemoryRangeSecurityLevelRef)
#endif
#define DCM_CFG_MEM_ID_WRITE_SESREF(i,j)       \
    (DCM_CFG_MEM_ID_INFO(i).DcmDspWriteMemoryRangeInfo[j].DcmDspWriteMemoryRangeSessionLevelRef)
#endif

#endif/*#if((DCM_UDS_23_SERVICE == STD_ON)||(DCM_UDS_3D_SERVICE == STD_ON) \
    || (DCM_UDS_34_SERVICE == STD_ON)||(DCM_UDS_35_SERVICE == STD_ON))*/

#if(STD_ON == DCM_UDS_31_SERVICE)
#define DCM_CFG_ROUTINE                        (Dcm_DspRoutine[DCM_ACTIVE_PROTOCOL_ID])
#define DCM_CFG_ROUTINE_NUM                    (DCM_CFG_ROUTINE.NumOfRoutineId)
#define DCM_CFG_ROUTINE_INFO                   (DCM_CFG_ROUTINE.DcmDspRoutineIdInfo)
#define DCM_CFG_ROUTINE_ID(i)                  (DCM_CFG_ROUTINE_INFO[i].DcmDspRoutineIdentifier)
#define DCM_CFG_ROUTINE_PORT(i)                (DCM_CFG_ROUTINE_INFO[i].DcmDspRoutineUsePort)
#define DCM_CFG_ROUTINE_USED(i)                (DCM_CFG_ROUTINE_INFO[i].DcmDspRoutineUsed)

#define DCM_CFG_ROUTINE_RESULT(i)              (DCM_CFG_ROUTINE_INFO[i].DcmDspRequestRoutineResults)
#define DCM_CFG_ROUTINE_RESULT_FNC_INDEX(i)    \
    (DCM_CFG_ROUTINE_RESULT(i)->DcmDspRequestRoutineResultsFncIndex)
#define DCM_CFG_ROUTINE_RESULT_AUTH(i)         \
    (DCM_CFG_ROUTINE_RESULT(i)->DcmDspRequestRoutineResultsCommonAuthorizationRef)
#define DCM_CFG_ROUTINE_RESULT_ADDR(i)         \
    (DCM_CFG_ROUTINE_RESULT_AUTH(i)->DcmDspCommonAuthorizationSupportAddress)
#if(STD_ON == DCM_UDS_27_SERVICE)
#define DCM_CFG_ROUTINE_RESULT_SEC(i)          \
    (DCM_CFG_ROUTINE_RESULT_AUTH(i)->DcmDspCommonAuthorizationSecurityLevelRef)
#endif
#define DCM_CFG_ROUTINE_RESULT_SES(i)          \
    (DCM_CFG_ROUTINE_RESULT_AUTH(i)->DcmDspCommonAuthorizationSessionRef)
#define DCM_CFG_ROUTINE_RESULT_ENDI(i)         \
    (DCM_CFG_ROUTINE_RESULT(i)->DcmDspRequestRoutineResultsOut.DcmDspRoutineSignalEndianness)
#define DCM_CFG_ROUTINE_RESULT_LEN(i)          \
    (DCM_CFG_ROUTINE_RESULT(i)->DcmDspRequestRoutineResultsOut.DcmDspRoutineSignalLength)
#define DCM_CFG_ROUTINE_RESULT_POS(i)          \
    (DCM_CFG_ROUTINE_RESULT(i)->DcmDspRequestRoutineResultsOut.DcmDspRoutineSignalPos)
#define DCM_CFG_ROUTINE_RESULT_TYPE(i)         \
    (DCM_CFG_ROUTINE_RESULT(i)->DcmDspRequestRoutineResultsOut.DcmDspRoutineSignalType)
#if(DCM_CAR_PLATFORM == DCM_GEELY_PLATFORM)
#define DCM_CFG_ROUTINE_RESULT_P4(i)           \
    (DCM_CFG_ROUTINE_RESULT(i)->P4ServerMax)
#endif

#define DCM_CFG_ROUTINE_START(i)               (DCM_CFG_ROUTINE_INFO[i].DcmDspStartRoutine)
#define DCM_CFG_ROUTINE_START_FNC_INDEX(i)     \
    (DCM_CFG_ROUTINE_START(i)->DcmDspStartRoutineFncIndex)
#define DCM_CFG_ROUTINE_START_AUTH(i)          \
    (DCM_CFG_ROUTINE_START(i)->DcmDspStartRoutineCommonAuthorizationRef)
#define DCM_CFG_ROUTINE_START_ADDR(i)          \
    (DCM_CFG_ROUTINE_START_AUTH(i)->DcmDspCommonAuthorizationSupportAddress)
#if(STD_ON == DCM_UDS_27_SERVICE)
#define DCM_CFG_ROUTINE_START_SEC(i)           \
    (DCM_CFG_ROUTINE_START_AUTH(i)->DcmDspCommonAuthorizationSecurityLevelRef)
#endif
#define DCM_CFG_ROUTINE_START_SES(i)           \
    (DCM_CFG_ROUTINE_START_AUTH(i)->DcmDspCommonAuthorizationSessionRef)
#define DCM_CFG_ROUTINE_START_IN_ENDI(i)       \
    (DCM_CFG_ROUTINE_START(i)->DcmDspStartRoutineIn.DcmDspRoutineSignalEndianness)
#define DCM_CFG_ROUTINE_START_IN_LEN(i)        \
    (DCM_CFG_ROUTINE_START(i)->DcmDspStartRoutineIn.DcmDspRoutineSignalLength)
#define DCM_CFG_ROUTINE_START_IN_POS(i)        \
    (DCM_CFG_ROUTINE_START(i)->DcmDspStartRoutineIn.DcmDspRoutineSignalPos)
#define DCM_CFG_ROUTINE_START_IN_TYPE(i)       \
    (DCM_CFG_ROUTINE_START(i)->DcmDspStartRoutineIn.DcmDspRoutineSignalType)
#define DCM_CFG_ROUTINE_START_OUT_ENDI(i)      \
    (DCM_CFG_ROUTINE_START(i)->DcmDspStartRoutineOut.DcmDspRoutineSignalEndianness)
#define DCM_CFG_ROUTINE_START_OUT_LEN(i)       \
    (DCM_CFG_ROUTINE_START(i)->DcmDspStartRoutineOut.DcmDspRoutineSignalLength)
#define DCM_CFG_ROUTINE_START_OUT_POS(i)       \
    (DCM_CFG_ROUTINE_START(i)->DcmDspStartRoutineOut.DcmDspRoutineSignalPos)
#define DCM_CFG_ROUTINE_START_OUT_TYPE(i)      \
    (DCM_CFG_ROUTINE_START(i)->DcmDspStartRoutineOut.DcmDspRoutineSignalType)
#if(DCM_CAR_PLATFORM == DCM_GEELY_PLATFORM)
#define DCM_CFG_ROUTINE_START_P4(i)            \
    (DCM_CFG_ROUTINE_START(i)->P4ServerMax)
#endif

#define DCM_CFG_ROUTINE_STOP(i)                (DCM_CFG_ROUTINE_INFO[i].DcmDspStopRoutine)
#define DCM_CFG_ROUTINE_STOP_FNC_INDEX(i)      \
    (DCM_CFG_ROUTINE_STOP(i)->DcmDspStopRoutineFncIndex)
#define DCM_CFG_ROUTINE_STOP_AUTH(i)           \
    (DCM_CFG_ROUTINE_STOP(i)->DcmDspStopRoutineCommonAuthorizationRef)
#define DCM_CFG_ROUTINE_STOP_ADDR(i)           \
    (DCM_CFG_ROUTINE_STOP_AUTH(i)->DcmDspCommonAuthorizationSupportAddress)
#if(STD_ON == DCM_UDS_27_SERVICE)
#define DCM_CFG_ROUTINE_STOP_SEC(i)            \
    (DCM_CFG_ROUTINE_STOP_AUTH(i)->DcmDspCommonAuthorizationSecurityLevelRef)
#endif
#define DCM_CFG_ROUTINE_STOP_SES(i)            \
    (DCM_CFG_ROUTINE_STOP_AUTH(i)->DcmDspCommonAuthorizationSessionRef)
#define DCM_CFG_ROUTINE_STOP_IN_ENDI(i)        \
    (DCM_CFG_ROUTINE_STOP(i)->DcmDspStopRoutineIn.DcmDspRoutineSignalEndianness)
#define DCM_CFG_ROUTINE_STOP_IN_LEN(i)         \
    (DCM_CFG_ROUTINE_STOP(i)->DcmDspStopRoutineIn.DcmDspRoutineSignalLength)
#define DCM_CFG_ROUTINE_STOP_IN_POS(i)         \
    (DCM_CFG_ROUTINE_STOP(i)->DcmDspStopRoutineIn.DcmDspRoutineSignalPos)
#define DCM_CFG_ROUTINE_STOP_IN_TYPE(i)        \
    (DCM_CFG_ROUTINE_STOP(i)->DcmDspStopRoutineIn.DcmDspRoutineSignalType)
#define DCM_CFG_ROUTINE_STOP_OUT_ENDI(i)       \
    (DCM_CFG_ROUTINE_STOP(i)->DcmDspStopRoutineOut.DcmDspRoutineSignalEndianness)
#define DCM_CFG_ROUTINE_STOP_OUT_LEN(i)        \
    (DCM_CFG_ROUTINE_STOP(i)->DcmDspStopRoutineOut.DcmDspRoutineSignalLength)
#define DCM_CFG_ROUTINE_STOP_OUT_POS(i)        \
    (DCM_CFG_ROUTINE_STOP(i)->DcmDspStopRoutineOut.DcmDspRoutineSignalPos)
#define DCM_CFG_ROUTINE_STOP_OUT_TYPE(i)       \
    (DCM_CFG_ROUTINE_STOP(i)->DcmDspStopRoutineOut.DcmDspRoutineSignalType)
#if(DCM_CAR_PLATFORM == DCM_GEELY_PLATFORM)
#define DCM_CFG_ROUTINE_STOP_P4(i)             \
    (DCM_CFG_ROUTINE_STOP(i)->P4ServerMax)
#endif

#define DCM_CFG_ROUTINE_START_FNC_A(i)         \
    (DCM_CFG_ROUTINE.DcmDspRoutineStartFncATable[i])
#define DCM_CFG_ROUTINE_START_FNC_B(i)         \
    (DCM_CFG_ROUTINE.DcmDspRoutineStartFncBTable[i])
#define DCM_CFG_ROUTINE_START_FNC_C(i)         \
    (DCM_CFG_ROUTINE.DcmDspRoutineStartFncCTable[i])
#define DCM_CFG_ROUTINE_START_FNC_D(i)         \
    (DCM_CFG_ROUTINE.DcmDspRoutineStartFncDTable[i])

#define DCM_CFG_ROUTINE_STOP_FNC_A(i)          \
    (DCM_CFG_ROUTINE.DcmDspRoutineStopFncATable[i])
#define DCM_CFG_ROUTINE_STOP_FNC_B(i)          \
    (DCM_CFG_ROUTINE.DcmDspRoutineStopFncBTable[i])
#define DCM_CFG_ROUTINE_STOP_FNC_C(i)          \
    (DCM_CFG_ROUTINE.DcmDspRoutineStopFncCTable[i])
#define DCM_CFG_ROUTINE_STOP_FNC_D(i)          \
    (DCM_CFG_ROUTINE.DcmDspRoutineStopFncDTable[i])

#define DCM_CFG_ROUTINE_RESULT_FNC_A(i)        \
    (DCM_CFG_ROUTINE.DcmDspRoutineRequestResulDefATable[i])
#define DCM_CFG_ROUTINE_RESULT_FNC_B(i)        \
    (DCM_CFG_ROUTINE.DcmDspRoutineRequestResulDefBTable[i])
#endif/*#if(STD_ON == DCM_UDS_31_SERVICE)*/



/*For OBD services*/
#if((DCM_OBD_01_SERVICE == STD_ON)||(DCM_OBD_02_SERVICE == STD_ON))
#define DCM_CFG_PID_ID(i)                      (Dcm_DspPidTable[i].DcmDspPidIdentifier)
#define DCM_CFG_PID_SERVICE(i)                 (Dcm_DspPidTable[i].DcmDspPidService)
#define DCM_CFG_PID_SIZE(i)                    (Dcm_DspPidTable[i].DcmDspPidSize)
#if(DCM_CONFIG_VARIANTS != STD_CONFIG_VARIANTS_POSTBUILD)
#define DCM_CFG_PID_USED(i)                    (Dcm_DspPidTable[i].DcmDspPidUsed)
#endif
#define DCM_CFG_PID_DATA_NUM(i)                (Dcm_DspPidTable[i].NumOfPidData)
#define DCM_CFG_PID_DATA(i)                    (Dcm_DspPidTable[i].DcmDspPidData)
#define DCM_CFG_PID_DATA_POS(i,j)              \
    (Dcm_DspPidTable[i].DcmDspPidData[j].DcmDspPidDataPos)
#define DCM_CFG_PID_DATA_SIZE(i,j)             \
    (Dcm_DspPidTable[i].DcmDspPidData[j].DcmDspPidDataSize)
#define DCM_CFG_PID_DATA_SUPPORTINFO(i,j)      \
    (Dcm_DspPidTable[i].DcmDspPidData[j].DcmDspPidDataSupportInfo)

#if(DCM_OBD_01_SERVICE == STD_ON)
#define DCM_CFG_PID_DATA_SERVICE01(i,j)        \
    (Dcm_DspPidTable[i].DcmDspPidData[j].DcmDspPidService01)
#define DCM_CFG_PID_DATA_SERVICE01_ENDIAN(i,j) \
    (Dcm_DspPidTable[i].DcmDspPidData[j].DcmDspPidService01->DcmDspPidDataEndianness)
#define DCM_CFG_PID_DATA_SERVICE01_FNC(i,j)    \
    (Dcm_DspPidTable[i].DcmDspPidData[j].DcmDspPidService01->DcmDspPidDataReadFnc)
#define DCM_CFG_PID_DATA_SERVICE01_TYPE(i,j)   \
    (Dcm_DspPidTable[i].DcmDspPidData[j].DcmDspPidService01->DcmDspPidDataType)
#define DCM_CFG_PID_DATA_SERVICE01_PORT(i,j)   \
    (Dcm_DspPidTable[i].DcmDspPidData[j].DcmDspPidService01->DcmDspPidDataUsePort)
#endif

#define DCM_CFG_PID_SUPPORTINFO_NUM(i)         (Dcm_DspPidTable[i].NumOfPidSupportInfo)
#define DCM_CFG_PID_SUPPORTINFO(i)             (Dcm_DspPidTable[i].DcmDspPidSupportInfo)

#endif/*#if((DCM_OBD_01_SERVICE == STD_ON)||(DCM_OBD_02_SERVICE == STD_ON))*/


#if(DCM_OBD_08_SERVICE == STD_ON)
#define DCM_CFG_TID_CONTROL_IN_SIZE(i)         \
    (Dcm_DspRequestControlTable[i].DcmDspRequestControlInBufferSize)
#define DCM_CFG_TID_CONTROL_OUT_SIZE(i)        \
    (Dcm_DspRequestControlTable[i].DcmDspRequestControlOutBufferSize)
#define DCM_CFG_TID_CONTROL_TEST_ID(i)         \
    (Dcm_DspRequestControlTable[i].DcmDspRequestControlTestId)
#define DCM_CFG_TID_CONTROL_FNC(i)             \
    (Dcm_DspRequestControlTable[i].DcmDspRequestControlFunction)
#endif/*#if(DCM_OBD_08_SERVICE == STD_ON)*/


#if(DCM_OBD_09_SERVICE == STD_ON)
#define DCM_CFG_INFOTYPE_ID(i)                 \
    (Dcm_DspVehInfoTable[i].DcmDspVehInfoInfoType)
#define DCM_CFG_INFOTYPE_NOD_PRO(i)            \
    (Dcm_DspVehInfoTable[i].DcmDspVehInfoNODIProvResp)
#define DCM_CFG_INFOTYPE_DATA_NUM(i)           \
    (Dcm_DspVehInfoTable[i].NumOfVehInfoData)
#define DCM_CFG_INFOTYPE_DATA(i)               \
    (Dcm_DspVehInfoTable[i].DcmDspVehInfoData)
#define DCM_CFG_INFOTYPE_DATA_ORDER(i,j)       \
    (Dcm_DspVehInfoTable[i].DcmDspVehInfoData[j].DcmDspVehInfoDataOrder)
#define DCM_CFG_INFOTYPE_DATA_FNC(i,j)         \
    (Dcm_DspVehInfoTable[i].DcmDspVehInfoData[j].DcmDspVehInfoDataReadFnc)
#define DCM_CFG_INFOTYPE_DATA_SIZE(i,j)        \
    (Dcm_DspVehInfoTable[i].DcmDspVehInfoData[j].DcmDspVehInfoDataSize)
#define DCM_CFG_INFOTYPE_DATA_PORT(i,j)        \
    (Dcm_DspVehInfoTable[i].DcmDspVehInfoData[j].DcmDspVehInfoDataUsePort)
#endif/*#if(DCM_OBD_09_SERVICE == STD_ON)*/



#if(DCM_UDS_27_SERVICE == STD_ON)
typedef struct
{
    uint8 AcessAttempNum;
    uint32 AcessDelayTime;
    boolean DelayTimeOnBoot;
    boolean AcessSequence;
} Dcm_SecLevelStateType;
#endif

#if(DCM_UDS_2A_SERVICE == STD_ON)
#define DCM_PERIODIC_BUFFER_LEN     (uint8)9
typedef struct
{
    uint8 PeriodicDid;/*low byte of the DID*/
    uint16 PeriodicDidIndex;/*Did index in the Did table*/
    uint8 PeriodicTimer;
    uint8 PeriodicRate;
    uint8 PeriodicDidDataBuffer[DCM_PERIODIC_BUFFER_LEN];
} Dcm_PeriodicScheduleType;
#endif

#if(DCM_UDS_31_SERVICE == STD_ON)
typedef enum
{
    DCM_ROUTINE_NONE     = 0,
    DCM_ROUTINE_STARTED  = 1,
    DCM_ROUTINE_STOPPED  = 2
} Dcm_RoutineStatusType;
#endif

#if((DCM_UDS_34_SERVICE == STD_ON)||(DCM_UDS_35_SERVICE == STD_ON))
typedef enum
{
    DCM_LOAD_NONE     = 0,
    DCM_LOAD_DOWN     = 1,
    DCM_LOAD_UP       = 2
} Dcm_LoadStatusType;
/*define the init value and max value of block sequence counter*/
#define DCM_BSC_INIT_VALUE        ((uint8)0x01)
#define DCM_BSC_MAX_VALUE         ((uint8)0xFF)
#endif

typedef struct
{
    Dcm_StateType ModuleState;
    boolean RxIndFlag;
    uint8 RespPendCounter;
    boolean SetProgFlag;/*for programming session*/
#if(DCM_NVM_SUPPORT == STD_ON)
    boolean NvMReadBlockCalled;
    boolean NvMWriteBlockCalled;
#endif
#if(DCM_DEM_SUPPORT == STD_ON)
#if(DCM_UDS_14_SERVICE == STD_ON)
    boolean ClearDtcFlag;
#endif
#if(DCM_UDS_19_SERVICE == STD_ON)
    Dem_UdsStatusByteType DtcStatus;
    uint16 DtcCounter;
    uint16 DtcFilteredNum;
    uint32 Dtc;
    uint8 DtcRecordNum;
    boolean GetDtcStatusFlag;
    boolean DisableDtcRecordUpdateFlag;
    boolean GetSizeFlag;
#endif
#endif/*#if(DCM_DEM_SUPPORT == STD_ON)*/
#if(DCM_UDS_22_SERVICE == STD_ON)
    uint16 DidCounter;
    uint16 DidPos;/*Did Position of DidIndexList*/
    uint16 DidIndexList[DCM_CFG_DSP_MAX_DID_READ];
#endif
#if((DCM_UDS_22_SERVICE == STD_ON)||(DCM_UDS_2F_SERVICE == STD_ON))
    boolean DidIsReading;
    boolean CheckReadFlag;
    boolean GetDataLengthFlag;
    uint16 DidDataLength;/*include Did length and all data(signals) length*/
    Dcm_MsgType DidRespDataPtr;
    Dcm_MsgLenType DidRespDataLen;
#endif
#if((DCM_UDS_22_SERVICE == STD_ON)||(DCM_UDS_2E_SERVICE == STD_ON)||(DCM_UDS_2F_SERVICE == STD_ON))
    uint16 DidSignalIndex;/*Signal index in one DID*/
#endif
#if(DCM_UDS_2A_SERVICE == STD_ON)
    uint8 CurrentDidService;
    uint8 PeriodicScheduleIndex;
    uint8 PeriodicScheduleUsedNum;
    Dcm_PeriodicScheduleType PeriodicSchedule[DCM_CFG_DSP_MAX_PERIODIC_DID_SCHEDULER];
#endif

#if(DCM_UDS_2C_SERVICE == STD_ON)
    Dcm_DspDDDIDType DcmDspDDDID[DCM_CFG_DDDID_NUM];
#if(DCM_DDDID_STORAGE == STD_OFF)
    Dcm_DspDDDIDElementInfoType DcmDspDDDIDElement[DCM_CFG_ALL_DDDID_ELEMENT_NUM];
#endif
#endif

#if((DCM_UDS_2E_SERVICE == STD_ON)||(DCM_UDS_2F_SERVICE == STD_ON))
    uint16 WriteControlDidIndex;
#endif
#if(DCM_UDS_2F_SERVICE == STD_ON)
    uint8 InputOutputControlParameter;
    boolean InputOutputControlFlag;
#endif
#if(DCM_UDS_27_SERVICE == STD_ON)
    Dcm_SecLevelType SecurityLevel;
    Dcm_SecLevelStateType SecLevelState[DCM_CFG_NUM_OF_PROTOCOL][DCM_CFG_NUM_SECURITY_LEVEL];
#endif
#if(DCM_UDS_28_SERVICE == STD_ON)
    uint8 ComControlReqSubService;
    Dcm_SesRefType ComControlReqSubServiceSupportSession;
    uint8 ComControlReqMsgType;
    uint8 ComControlReqSubNet;
    uint16 ComControlReqSubNode;
#endif
#if((DCM_UDS_23_SERVICE == STD_ON)||(DCM_UDS_3D_SERVICE == STD_ON))
    uint32 MemoryStartAddr;
    uint32 MemorySize;
    uint8 MemoryId;
    uint8 *MemoryDataPtr;
#endif
#if((DCM_UDS_34_SERVICE == STD_ON)||(DCM_UDS_35_SERVICE == STD_ON))
    uint32 DownUpLoadMemoryAddress;
    uint32 DownUpLoadMemorySize;
    uint32 MaxNumberOfBytesForWriteReadMemory;
    uint8 DownUpLoadMemoryId;
    uint8 DownUpLoadNextBlockSequenceCounter;
    uint8 DownUpLoadPreviousBlockSequenceCounter;
    uint8 DataFormatIdentifier;
    Dcm_LoadStatusType LoadStatus;
#endif
#if(DCM_UDS_31_SERVICE == STD_ON)
    uint16 RoutineIdIndex;
    Dcm_RoutineStatusType RoutineStatus[DCM_CFG_RID_NUM];
#endif
#if(DCM_UDS_85_SERVICE == STD_ON)
    Dcm_SesRefType DtcSettingSubServiceSessionRef;
#endif
#if(DCM_UDS_87_SERVICE == STD_ON)
    uint8 LinkControlVerifiedService;/*need initialized*/
#endif

#if((DCM_OBD_01_SERVICE == STD_ON)||(DCM_OBD_02_SERVICE == STD_ON) \
    ||(DCM_OBD_08_SERVICE == STD_ON)||(DCM_OBD_09_SERVICE == STD_ON))
    uint8 OBDServiceReqData[7];
#endif
#if(DCM_OBD_01_SERVICE == STD_ON)
    uint8 OBDService01_AvailPID[8][4];/*Be assigned in Dcm_Init() function*/
#endif
#if(DCM_OBD_02_SERVICE == STD_ON)
    uint8 OBDService02_AvailPID[8][4];/*Be assigned in Dcm_Init() function*/
#endif
#if(DCM_OBD_08_SERVICE == STD_ON)
    uint8 OBDService08_AvailTID[8][4];/*Be assigned in Dcm_Init() function*/
#endif
#if(DCM_OBD_09_SERVICE == STD_ON)
    uint8 OBDService09_AvailInfoType[8][4];/*Be assigned in Dcm_Init() function*/
    uint8 OBDInfoTypeIndex;
    uint8 OBDInfoTypeDataIndex;
#endif
#if((DCM_OBD_03_SERVICE == STD_ON)||(DCM_OBD_07_SERVICE == STD_ON) \
    ||(DCM_OBD_0A_SERVICE == STD_ON))
    uint8 OBDDtcCounter;
#endif

    Dcm_SesCtrlType SessionLevel;
    uint32 P2Timer;
#if(DCM_CAR_PLATFORM == DCM_GEELY_PLATFORM)
    uint32 P4Timer;
#endif
    uint32 S3Timer;
#if(DCM_COMM_SUPPORT == STD_ON)
    boolean ActiveDiagnostic;
    Dcm_ComM_ModeType ComMMode[DCM_NUM_COMM_CHANNEL];
#endif
    uint8 ProtocolId;
    uint8 ProtocolConnectionId;
    uint8 ProtocolRxId;
    Dcm_OpStatusType OpStatus;
    Dcm_MsgContextType MsgContext;
    uint8 ReqService;
    const Dcm_DsdServiceType *ReqServiceInfo;
    EcucFunctionServiceFncDef ServiceFnc;
    uint8 ReqSubService;
    uint8 ReqSubServiceIndex;
    const Dcm_DsdSubServiceType *ReqSubServiceInfo;
    EcucFunctionServiceFncDef SubServiceFnc;
    Dcm_NegativeResponseCodeType *pErrorCode;
} Dcm_ContextType;

typedef struct
{
    PduIdType RxPduId;
    Dcm_MsgLenType reqDataLen;
    Dcm_MsgLenType CopyDataIndex;
    uint8 ConnectionId;
    uint8 RxId;
    Dcm_NegativeResponseCodeType ErrorCode;
    uint8 NegativeRespBuffer[DCM_UDS_NEG_RES_LEN];
} Dcm_ProtocolInfoType;


#define DCM_START_SEC_VAR_INIT_8
#include "MemMap.h"

STATIC VAR(Std_InitStateType, DCM_VAR) Dcm_InitState = STD_UNINITIALIZED;

#if(DCM_APP_CLEARDTCCHECK_ENABLE == STD_ON)
STATIC VAR(Std_InitStateType, DCM_VAR) Dcm_ClearDTCAppCheckFinished = FALSE;
#endif

#define DCM_STOP_SEC_VAR_INIT_8
#include "MemMap.h"



#define DCM_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"
STATIC VAR(Dcm_ContextType, DCM_VAR) DcmContext;

/*It is used to record diagnostic requests and negative responses related to protocols*/
STATIC VAR(Dcm_ProtocolInfoType, DCM_VAR) Dcm_ProtocolInfo[DCM_CFG_NUM_OF_PROTOCOL];

#if((DCM_UDS_2C_SERVICE == STD_ON)&&(DCM_DDDID_STORAGE == STD_ON))
VAR(Dcm_DspDDDIDElementInfoType, DCM_VAR) Dcm_DspDDDIDElement[DCM_CFG_ALL_DDDID_ELEMENT_NUM];
#endif
#define DCM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"


#define DCM_STATE                     (DcmContext.ModuleState)
#define DCM_RX_IND_FLAG               (DcmContext.RxIndFlag)
#define DCM_RESP_PEND_COUNTER         (DcmContext.RespPendCounter)
#define DCM_SET_PROG_FLAG             (DcmContext.SetProgFlag)
#if(DCM_NVM_SUPPORT == STD_ON)
#define DCM_NVM_READBLOCK_CALLED      (DcmContext.NvMReadBlockCalled)
#define DCM_NVM_WRITEBLOCK_CALLED     (DcmContext.NvMWriteBlockCalled)
#endif

#if(DCM_DEM_SUPPORT == STD_ON)
#if(DCM_UDS_14_SERVICE == STD_ON)
#define DCM_CLEAR_DTC_FLAG            (DcmContext.ClearDtcFlag)
#endif
#if(DCM_UDS_19_SERVICE == STD_ON)
#define DCM_DTC_STATUS                (DcmContext.DtcStatus)
#define DCM_DTC_COUNTER               (DcmContext.DtcCounter)
#define DCM_DTC_FILTEREDNUM           (DcmContext.DtcFilteredNum)
#define DCM_DTC_DTC                   (DcmContext.Dtc)
#define DCM_DTC_RECORDNUM             (DcmContext.DtcRecordNum)
#define DCM_DTC_GETSTATUS_FLAG        (DcmContext.GetDtcStatusFlag)
#define DCM_DTC_DISRECUP_FLAG         (DcmContext.DisableDtcRecordUpdateFlag)
#define DCM_DTC_GETSIZE_FLAG          (DcmContext.GetSizeFlag)
#endif
#endif/*#if(DCM_DEM_SUPPORT == STD_ON)*/
#if(DCM_UDS_22_SERVICE == STD_ON)
#define DCM_DID_COUNTER               (DcmContext.DidCounter)
#define DCM_DID_POS                   (DcmContext.DidPos)
#define DCM_DID_INDEX_LIST            (DcmContext.DidIndexList)
#endif
#if((DCM_UDS_22_SERVICE == STD_ON)||(DCM_UDS_2F_SERVICE == STD_ON))
#define DCM_DID_IS_READING            (DcmContext.DidIsReading)
#define DCM_DID_CHECK_READ_FLAG       (DcmContext.CheckReadFlag)
#define DCM_DID_GET_LEN_FLAG          (DcmContext.GetDataLengthFlag)
#define DCM_DID_DATA_LEN              (DcmContext.DidDataLength)
#define DCM_DID_RESP_DATA             (DcmContext.DidRespDataPtr)
#define DCM_DID_RESP_LEN              (DcmContext.DidRespDataLen)
#endif
#if((DCM_UDS_22_SERVICE == STD_ON)||(DCM_UDS_2E_SERVICE == STD_ON)||(DCM_UDS_2F_SERVICE == STD_ON))
#define DCM_DID_SIG_INDEX             (DcmContext.DidSignalIndex)
#endif
#if(DCM_UDS_2A_SERVICE == STD_ON)
#define DCM_CURRENT_DID_SERVICE       (DcmContext.CurrentDidService)
#define DCM_PERIODIC_SCHEDULE_INDEX   (DcmContext.PeriodicScheduleIndex)
#define DCM_PERIODIC_SCHEDULE_USEDNUM (DcmContext.PeriodicScheduleUsedNum)
#define DCM_PERIODIC_SCHEDULE         (DcmContext.PeriodicSchedule)
#define DCM_PERIODIC_DID(i)           (DCM_PERIODIC_SCHEDULE[i].PeriodicDid)
#define DCM_PERIODIC_DID_INDEX(i)     (DCM_PERIODIC_SCHEDULE[i].PeriodicDidIndex)
#define DCM_PERIODIC_TIMER(i)         (DCM_PERIODIC_SCHEDULE[i].PeriodicTimer)
#define DCM_PERIODIC_RATE(i)          (DCM_PERIODIC_SCHEDULE[i].PeriodicRate)
#define DCM_PERIODIC_BUFFER(i)        (DCM_PERIODIC_SCHEDULE[i].PeriodicDidDataBuffer)
#endif

#if(DCM_UDS_2C_SERVICE == STD_ON)
#define DCM_DDDID_INDEX(i)            (DcmContext.DcmDspDDDID[i].DcmDspDDDIDIndex)
#define DCM_DDDID_DEFINED(i)          (DcmContext.DcmDspDDDID[i].DcmDspDDDIDDefined)
#define DCM_DDDID_ELE_USED_NUM(i)     (DcmContext.DcmDspDDDID[i].DcmDspDDDIDElementUsedNum)
#define DCM_DDDID_ELE_PTR(i)          (DcmContext.DcmDspDDDID[i].DcmDspDDDIDElementPtr)
#define DCM_DDDID_ELE_SDID_INDEX(i,j) (DCM_DDDID_ELE_PTR(i)[j].DcmDspDDDIDSourceDidIndex)
#define DCM_DDDID_ELE_SDID_POS(i,j)   (DCM_DDDID_ELE_PTR(i)[j].DcmDspDDDIDDataPositionInSourceDid)
#define DCM_DDDID_ELE_DATA_INDEX(i,j) (DCM_DDDID_ELE_PTR(i)[j].DcmDspDataIndex)
#define DCM_DDDID_ELE_MEM_ID(i,j)     (DCM_DDDID_ELE_PTR(i)[j].DcmDspDDDIDMemoryId)
#define DCM_DDDID_ELE_MEM_ADDR(i,j)   (DCM_DDDID_ELE_PTR(i)[j].DcmDspDDDIDDataMemoryAddress)
#define DCM_DDDID_ELE_DATA_SIZE(i,j)  (DCM_DDDID_ELE_PTR(i)[j].DcmDspDDDIDDataSize)
#if(DCM_DDDID_STORAGE == STD_OFF)
#define DCM_DDDID_ELEMENT(i)          (DcmContext.DcmDspDDDIDElement[i])
#else
#define DCM_DDDID_ELEMENT(i)          (Dcm_DspDDDIDElement[i])
#endif
#endif

#if((DCM_UDS_2E_SERVICE == STD_ON)||(DCM_UDS_2F_SERVICE == STD_ON))
#define DCM_DID_FOR2E2F_INDEX         (DcmContext.WriteControlDidIndex)
#endif
#if(DCM_UDS_2F_SERVICE == STD_ON)
#define DCM_REQ_IOCONTROL             (DcmContext.InputOutputControlParameter)
#define DCM_IOCONTROL_FLAG            (DcmContext.InputOutputControlFlag)
#endif

#if(DCM_UDS_27_SERVICE == STD_ON)
#define DCM_SECURITY_LEVEL               (DcmContext.SecurityLevel)
#define DCM_SECURITY_ATTEMP_NUM(i, j)    (DcmContext.SecLevelState[i][j].AcessAttempNum)
#define DCM_SECURITY_DELAY_TIME(i, j)    (DcmContext.SecLevelState[i][j].AcessDelayTime)
#define DCM_SECURITY_SEQUENCE(i, j)      (DcmContext.SecLevelState[i][j].AcessSequence)
#define DCM_SECURITY_DELAY_ON_BOOT(i, j) (DcmContext.SecLevelState[i][j].DelayTimeOnBoot)
#endif

#if(DCM_UDS_28_SERVICE == STD_ON)
#define DCM_COM_REQSUBSERVICE         (DcmContext.ComControlReqSubService)
#define DCM_COM_REQSUBSERVICE_SESSION (DcmContext.ComControlReqSubServiceSupportSession)
#define DCM_COM_REQMSGTYPE            (DcmContext.ComControlReqMsgType)
#define DCM_COM_REQSUBNET             (DcmContext.ComControlReqSubNet)
#define DCM_COM_REQSUBNODE            (DcmContext.ComControlReqSubNode)
#endif

#if((DCM_UDS_23_SERVICE == STD_ON)||(DCM_UDS_3D_SERVICE == STD_ON))
#define DCM_MEM_START_ADDR            (DcmContext.MemoryStartAddr)
#define DCM_MEM_SIZE                  (DcmContext.MemorySize)
#define DCM_MEM_ID                    (DcmContext.MemoryId)
#define DCM_MEM_DATA_PTR              (DcmContext.MemoryDataPtr)
#endif

#if((DCM_UDS_34_SERVICE == STD_ON)||(DCM_UDS_35_SERVICE == STD_ON))
#define DCM_DOWN_UP_LOAD_MA           (DcmContext.DownUpLoadMemoryAddress)
#define DCM_DOWN_UP_LOAD_MS           (DcmContext.DownUpLoadMemorySize)
#define DCM_DOWN_UP_LOAD_MI           (DcmContext.DownUpLoadMemoryId)
#define DCM_DOWN_UP_LOAD_DFI          (DcmContext.DataFormatIdentifier)
#define DCM_DOWN_UP_LOAD_MNOBFWRM     (DcmContext.MaxNumberOfBytesForWriteReadMemory)
#define DCM_DOWN_UP_LOAD_STATUS       (DcmContext.LoadStatus)
#define DCM_DOWN_UP_LOAD_NEXT_BSC     (DcmContext.DownUpLoadNextBlockSequenceCounter)
#define DCM_DOWN_UP_LOAD_PRE_BSC      (DcmContext.DownUpLoadPreviousBlockSequenceCounter)
#endif

#if(DCM_UDS_31_SERVICE == STD_ON)
#define DCM_RID_INDEX                 (DcmContext.RoutineIdIndex)
#define DCM_RID_STATUS(i)             (DcmContext.RoutineStatus[i])
#endif

#if(DCM_UDS_85_SERVICE == STD_ON)
#define DCM_85_SUB_SESREF             (DcmContext.DtcSettingSubServiceSessionRef)
#endif

#if(DCM_UDS_87_SERVICE == STD_ON)
#define DCM_87_VERIFIED               (DcmContext.LinkControlVerifiedService)
#endif

#if((DCM_OBD_01_SERVICE == STD_ON)||(DCM_OBD_02_SERVICE == STD_ON) \
    ||(DCM_OBD_08_SERVICE == STD_ON)||(DCM_OBD_09_SERVICE == STD_ON))
#define DCM_OBD_SERVICE_REQ_DATA      (DcmContext.OBDServiceReqData)
#endif
#if(DCM_OBD_01_SERVICE == STD_ON)
#define DCM_OBD_SERVICE01_AVAIL_PID   (DcmContext.OBDService01_AvailPID)
#endif
#if(DCM_OBD_02_SERVICE == STD_ON)
#define DCM_OBD_SERVICE02_AVAIL_PID   (DcmContext.OBDService02_AvailPID)
#endif
#if(DCM_OBD_08_SERVICE == STD_ON)
#define DCM_OBD_SERVICE08_AVAIL_TID   (DcmContext.OBDService08_AvailTID)
#endif
#if(DCM_OBD_09_SERVICE == STD_ON) 
#define DCM_OBD_SERVICE09_AVAIL_INFO  (DcmContext.OBDService09_AvailInfoType)
#define DCM_OBD_INFOTYPE_INDEX        (DcmContext.OBDInfoTypeIndex)
#define DCM_OBD_INFOTYPE_DATA_INDEX   (DcmContext.OBDInfoTypeDataIndex)
#endif
#if((DCM_OBD_03_SERVICE == STD_ON)||(DCM_OBD_07_SERVICE == STD_ON) \
    ||(DCM_OBD_0A_SERVICE == STD_ON))
#define DCM_OBD_DTC_COUNTER           (DcmContext.OBDDtcCounter)
#endif

#define DCM_SESSION_LEVEL             (DcmContext.SessionLevel)
#define DCM_P2_TIMER                  (DcmContext.P2Timer)
#if(DCM_CAR_PLATFORM == DCM_GEELY_PLATFORM)
#define DCM_P4_TIMER                  (DcmContext.P4Timer)
#endif
#define DCM_S3_TIMER                  (DcmContext.S3Timer)
#if(DCM_COMM_SUPPORT == STD_ON)
#define DCM_ACTIVE_DIAGNOSTIC         (DcmContext.ActiveDiagnostic)
#define DCM_COMM_CHANNEL_MODE(i)      (DcmContext.ComMMode[i])
#endif

#define DCM_ACTIVE_PROTOCOL_ID        (DcmContext.ProtocolId)
#define DCM_ACTIVE_CONNECTION_ID      (DcmContext.ProtocolConnectionId)
#define DCM_ACTIVE_RX_ID              (DcmContext.ProtocolRxId)


#define DCM_OP_STATUS                 (DcmContext.OpStatus)
#define DCM_MSGCONTEXT                (DcmContext.MsgContext)
#define DCM_REQ_SERVICE               (DcmContext.ReqService)
#define DCM_REQ_SERVICEINFO           (DcmContext.ReqServiceInfo)
#define DCM_SERVICE_FNC               (DcmContext.ServiceFnc)

#define DCM_CFG_SUB_SERVICE(i)        (DCM_REQ_SERVICEINFO->DcmDsdSubService[i])
#define DCM_CFG_SUB_SERVICE_ID(i)     (DCM_REQ_SERVICEINFO->DcmDsdSubService[i].DcmDsdSubServiceId)
#define DCM_CFG_SUB_SERVICE_USED(i)   (DCM_REQ_SERVICEINFO->DcmDsdSubService[i].DcmDsdSubServiceUsed)

#define DCM_REQ_SUBSERVICE            (DcmContext.ReqSubService)
#define DCM_SUBSERVICE_FNC            (DcmContext.SubServiceFnc)
#define DCM_REQ_SUBSERVICE_INDEX      (DcmContext.ReqSubServiceIndex)
#define DCM_REQ_SUBSERVICEINFO        (DcmContext.ReqSubServiceInfo)

#define DCM_P_ERRORCODE               (DcmContext.pErrorCode)
#define DCM_ERRORCODE                 (*(DcmContext.pErrorCode))

/*Temporary information of the protocol*/
#define DCM_PCL_RX_PDU_ID(Idx)        (Dcm_ProtocolInfo[Idx].RxPduId)
#define DCM_PCL_RX_DATA_LEN(Idx)      (Dcm_ProtocolInfo[Idx].reqDataLen)
#define DCM_PCL_DATA_INDEX(Idx)       (Dcm_ProtocolInfo[Idx].CopyDataIndex)
#define DCM_PCL_RX_CON_ID(Idx)        (Dcm_ProtocolInfo[Idx].ConnectionId)
#define DCM_PCL_RX_ID(Idx)            (Dcm_ProtocolInfo[Idx].RxId)
#define DCM_PCL_ERROR_CODE(Idx)       (Dcm_ProtocolInfo[Idx].ErrorCode)
#define DCM_PCL_NEG_BUFFER(Idx)       (Dcm_ProtocolInfo[Idx].NegativeRespBuffer)

#define ClearSuppressPosRespBit()     (DCM_MSGCONTEXT.msgAddInfo.suppressPosResponse = FALSE)

#define SetDcmState(State)            (DCM_STATE |= (State))
#define ClearDcmState(State)          (DCM_STATE &= (~(State)))
#define ResetDcmState()               (DCM_STATE = DCM_IDLE)
#define CheckDcmState(State)          (((DCM_STATE) & (State)) != 0U)

#define SetRxFlag()                   (DCM_RX_IND_FLAG = TRUE)
#define ClearRxFlag()                 (DCM_RX_IND_FLAG = FALSE)
#define CheckRxFlag()                 (DCM_RX_IND_FLAG == TRUE)


#define SetRespPendCounter(Counter)   (DCM_RESP_PEND_COUNTER = Counter)
#define RunRespPendCounter()          (DCM_RESP_PEND_COUNTER--)
#define ClearRespPendCounter()        (DCM_RESP_PEND_COUNTER = 0U)
#define CheckRespPendCounter()        (DCM_RESP_PEND_COUNTER == 0U)

/*(time/DCM_TASK_TIME - 1U) this is to aviod Client timeout.*/
#define SetP2Timer(time)              (DCM_P2_TIMER = (time/DCM_TASK_TIME - 1U))
#define RunP2Timer()                  (DCM_P2_TIMER--)
#define ClearP2Timer()                (DCM_P2_TIMER = 0U)
#define CheckP2Timer()                (DCM_P2_TIMER > 0U)

#if(DCM_CAR_PLATFORM == DCM_GEELY_PLATFORM)
#define SetP4Timer(time)              (DCM_P4_TIMER = (time/DCM_TASK_TIME))
#define RunP4Timer()                  (DCM_P4_TIMER--)
#define ClearP4Timer()                (DCM_P4_TIMER = 0U)
#define CheckP4Timer()                (DCM_P4_TIMER > 0U)
#endif

#define SetS3Timer(time)              (DCM_S3_TIMER = (time/DCM_TASK_TIME))
#define RunS3Timer()                  (DCM_S3_TIMER--)
#define ClearS3Timer()                (DCM_S3_TIMER = 0U)
#define CheckS3Timer()                (DCM_S3_TIMER <= 0U)

#define ResetNegRespBuffer(Idx)       DCM_PCL_NEG_BUFFER(Idx)[0] = DCM_DATA_CLEAR; \
    DCM_PCL_NEG_BUFFER(Idx)[1] = DCM_DATA_CLEAR; \
    DCM_PCL_NEG_BUFFER(Idx)[2] = DCM_POSITIVE_RESPONSE
#define SetNegRespBuffer(Idx,Sid,Error)  DCM_PCL_NEG_BUFFER(Idx)[0] = 0x7FU; \
    DCM_PCL_NEG_BUFFER(Idx)[1] = Sid;   \
    DCM_PCL_NEG_BUFFER(Idx)[2] = Error


#define DCM_START_SEC_CODE
#include "MemMap.h"

STATIC FUNC(void, DCM_CODE) DcmInternal_InitMsgContext
(
    void
);
STATIC FUNC(void, DCM_CODE) DcmInternal_InitDcmContext
(
    void
);

#if((DCM_OBD_01_SERVICE == STD_ON)||(DCM_OBD_02_SERVICE == STD_ON) \
    ||(DCM_OBD_08_SERVICE == STD_ON)||(DCM_OBD_09_SERVICE == STD_ON))
/*For OBD services 01,02,08,09*/
STATIC FUNC(void, DCM_CODE) DcmInternal_Init_AvailabilityParameters
(
    void
);
#endif

/*******************************************************************************
* DSL:Internal interfaces
*******************************************************************************/
STATIC FUNC(void, DCM_CODE) DslInternal_SetSesCtrlType
(
    Dcm_SesCtrlType SesCtrlType
);
#if(DCM_UDS_27_SERVICE == STD_ON)
STATIC FUNC(void, DCM_CODE) DslInternal_SetSecurityLevel
(
    Dcm_SecLevelType SecurityLevel
);
STATIC FUNC(Dcm_SecRefType, DCM_CODE) DslInternal_GetSecurityMask
(
    void
);
#endif
STATIC FUNC(void, DCM_CODE) DslInternal_MainFunction
(
    void
);

STATIC FUNC(void, DCM_CODE) DslInternal_CheckProtocolPermission
(
    uint8 ProtocolId
);
/*******************************************************************************
* DSD:Internal interfaces
*******************************************************************************/
STATIC FUNC(Std_ReturnType, DCM_CODE) DsdInternal_CheckServiceId
(
    void
);
STATIC FUNC(Std_ReturnType, DCM_CODE) DsdInternal_CheckSubServiceId
(
    void
);
STATIC FUNC(Std_ReturnType, DCM_CODE) DsdInternal_MatchServiceFnc
(
    void
);
STATIC FUNC(void, DCM_CODE) DsdInternal_DcmConfirmation
(
    Dcm_IdContextType idContext,
    uint16 SourceAddress,
    Dcm_ConfirmationStatusType status
);
STATIC FUNC(void, DCM_CODE) DsdInternal_CreatNegResponse
(
    void
);
STATIC FUNC(Std_ReturnType, DCM_CODE) DsdInternal_RCRResponsePending
(
    boolean ForceRCRRP
);
STATIC FUNC(void, DCM_CODE) DsdInternal_ProcessingDone
(
    void
);

#if(DCM_OBD_SUPPORT == STD_ON)
STATIC FUNC(void, DCM_CODE) DsdInternal_OBD_ReqErrorReset
(
    void
);
#endif

STATIC FUNC(void, DCM_CODE) DsdInternal_MainFunction
(
    void
);
/*******************************************************************************
* DSP:Internal interfaces
*******************************************************************************/
STATIC FUNC(void, DCM_CODE) DspInternal_MainFunction
(
    void
);
STATIC FUNC(void, DCM_CODE) DspInternal_DcmConfirmation
(
    Dcm_IdContextType idContext,
    uint16 SourceAddress,
    Dcm_ConfirmationStatusType status
);
STATIC FUNC(void, DCM_CODE) DspInternal_PostProcessor
(
    void
);
STATIC FUNC(Std_ReturnType, DCM_CODE) DspInternal_AddrSesSecCheck
(
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
);

/*10 Service*//*SWS_Dcm_00250*/
STATIC FUNC(Std_ReturnType, DCM_CODE) DspInternal_10_DiagnosticSessionControl
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
);
STATIC FUNC(Std_ReturnType, DCM_CODE) DspInternal_10_Sub_Processor
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
);
STATIC FUNC(void, DCM_CODE) DspInternal_10_Sub_Post
(
    void
);

#if(DCM_UDS_11_SERVICE == STD_ON)
/*11 Service*//*SWS_Dcm_00260*/
STATIC FUNC(Std_ReturnType, DCM_CODE) DspInternal_11_ECUReset
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
);
STATIC FUNC(Std_ReturnType, DCM_CODE) DspInternal_11_Sub_Processor
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
);
#endif

#if((DCM_UDS_14_SERVICE == STD_ON)&&(DCM_DEM_SUPPORT == STD_ON))
/*14 Service*//*SWS_Dcm_00247*/
STATIC FUNC(Std_ReturnType, DCM_CODE) DspInternal_14_ClearDiagnosticInformation
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
);
#endif

#if(DCM_UDS_19_SERVICE == STD_ON)
/*19 Service*//*SWS_Dcm_00248*/
STATIC FUNC(Std_ReturnType, DCM_CODE) DspInternal_19_ReadDTCInformation
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
);
#if(DCM_DEM_SUPPORT == STD_ON)
STATIC FUNC(Std_ReturnType, DCM_CODE) DspInternal_19_Sub_Processor
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
);
STATIC FUNC(Std_ReturnType, DCM_CODE) DspInternal_19_01_11_12_Processor
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
);
STATIC FUNC(Std_ReturnType, DCM_CODE) DspInternal_19_02_0A_0F_15_Processor
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
);
STATIC FUNC(Std_ReturnType, DCM_CODE) DspInternal_19_06_10_Processor
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
);
STATIC FUNC(Std_ReturnType, DCM_CODE) DspInternal_19_03_Processor
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
);
STATIC FUNC(Std_ReturnType, DCM_CODE) DspInternal_19_04_Processor
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
);
STATIC FUNC(Std_ReturnType, DCM_CODE) DspInternal_19_14_Processor
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
);
#endif/*#if(DCM_DEM_SUPPORT == STD_ON)*/
#endif

#if(DCM_UDS_22_SERVICE == STD_ON)
/*22 Service*//*SWS_Dcm_00253*/
STATIC FUNC(Std_ReturnType, DCM_CODE) DspInternal_22_ReadDataByIdentifier
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
);
STATIC FUNC(Std_ReturnType, DCM_CODE) DspInternal_22_CheckReadDid
(
    uint16 ReqDid,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode,
    P2VAR(uint16, AUTOMATIC, DCM_VAR) pDidIndex
);

#if(DCM_CAR_PLATFORM == DCM_RNDS_PLATFORM)
STATIC FUNC(Std_ReturnType, DCM_CODE) DspInternal_Rnds_ReadSupportedIdentifier
(
    uint8 DidHighByte,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
);
#endif/*#if(DCM_CAR_PLATFORM == DCM_RNDS_PLATFORM)*/

#if(DCM_CAR_PLATFORM == DCM_NISSAN_PLATFORM)
STATIC FUNC(Std_ReturnType, RTE_CODE) DspInternal_0x22_ReadSupportedIdentifier
(
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
);
#endif/*#if(DCM_CAR_PLATFORM == DCM_NISSAN_PLATFORM)*/

#endif/*#if(DCM_UDS_22_SERVICE == STD_ON)*/

#if((DCM_UDS_22_SERVICE == STD_ON)||(DCM_UDS_2F_SERVICE == STD_ON))
STATIC FUNC(Std_ReturnType, DCM_CODE) DspInternal_DidReadAllRefData
(
    uint16 DidIndex,
    uint32 MaxBufferSize,
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
);
#endif

#if(DCM_UDS_23_SERVICE == STD_ON)
/*23 Service*//*SWS_Dcm_00492*/
STATIC FUNC(Std_ReturnType, DCM_CODE) DspInternal_23_ReadMemoryByAddress
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
);
#endif

#if(DCM_UDS_27_SERVICE == STD_ON)
/*27 Service*//*SWS_Dcm_00252*/
STATIC FUNC(Std_ReturnType, DCM_CODE) DspInternal_27_SecurityAccess
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
);
#endif

#if(DCM_UDS_28_SERVICE == STD_ON)
/*28 Service*//*SWS_Dcm_00511*/
STATIC FUNC(Std_ReturnType, DCM_CODE) DspInternal_28_CommunicationControl
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
);
STATIC FUNC(Std_ReturnType, DCM_CODE) DspInternal_28_Sub_Processor
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
);
STATIC FUNC(Std_ReturnType, DCM_CODE) DspInternal_28_EnhancedSub_Processor
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
);
STATIC FUNC(void, DCM_CODE) DspInternal_28_Sub_Post
(
    void
);
STATIC FUNC(void, DCM_CODE) DspInternal_28_ResumeCommunication
(
    void
);
#endif

#if(DCM_UDS_2A_SERVICE == STD_ON)
/*2A Service*//*SWS_Dcm_00254*/
STATIC FUNC(Std_ReturnType, DCM_CODE) DspInternal_2A_ReadDataByPeriodicIdentifier
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
);
STATIC FUNC(Std_ReturnType, DCM_CODE) DspInternal_2A_StopSending
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
);
STATIC FUNC(void, DCM_CODE) DspInternal_2A_StopOneDid
(
    uint8 DidPos
);
STATIC FUNC(void, DCM_CODE) DspInternal_2A_SetRateTimer
(
    uint8 ScheduleIndex
);
STATIC FUNC(Std_ReturnType, DCM_CODE) DspInternal_2A_RequestSending
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
);
STATIC FUNC(void, DCM_CODE) DspInternal_2A_PeriodicTransmission
(
    void
);
#endif

#if(DCM_UDS_2C_SERVICE == STD_ON)
/*2C Service*//*SWS_Dcm_00259*/
STATIC FUNC(Std_ReturnType, DCM_CODE) DspInternal_2C_DynamicallyDefineDataIdentifier
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
);
STATIC FUNC(Std_ReturnType, DCM_CODE) DspInternal_2C_CheckDDDID
(
    P2VAR(uint16, AUTOMATIC, DCM_VAR) DDDidPos,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
);
STATIC FUNC(Std_ReturnType, DCM_CODE) DspInternal_2C_01_Processor
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
);
STATIC FUNC(Std_ReturnType, DCM_CODE) DspInternal_2C_02_Processor
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
);
STATIC FUNC(Std_ReturnType, DCM_CODE) DspInternal_2C_03_Processor
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
);
STATIC FUNC(void, DCM_CODE) DspInternal_2C_ClearOneDDDID
(
    uint16 DDDIDBufferIndex
);
STATIC FUNC(Std_ReturnType, DCM_CODE) DspInternal_DDDidReadAllRefData
(
    uint16 DidIndex,
    uint32 MaxBufferSize,
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
);
#endif

#if(DCM_UDS_2E_SERVICE == STD_ON)
/*2E Service*//*SWS_Dcm_00255*/
STATIC FUNC(Std_ReturnType, DCM_CODE) DspInternal_2E_WriteDataByIdentifier
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
);

#if(DCM_CAR_PLATFORM == DCM_NISSAN_PLATFORM)
STATIC FUNC(Std_ReturnType, RTE_CODE) DspInternal_0x2E_ReadSupportedIdentifier
(
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
);
#endif/*#if(DCM_CAR_PLATFORM == DCM_NISSAN_PLATFORM)*/

#endif

#if(DCM_UDS_2F_SERVICE == STD_ON)
/*2F Service*//*SWS_Dcm_00256*/
STATIC FUNC(Std_ReturnType, DCM_CODE) DspInternal_2F_InputOutputControlByIdentifier
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
);
STATIC FUNC(Std_ReturnType, DCM_CODE) DspInternal_2F_IOControlPrecess
(
    Dcm_OpStatusType OpStatus,
    uint32 ControlMask,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
);

#if(DCM_CAR_PLATFORM == DCM_NISSAN_PLATFORM)
STATIC FUNC(Std_ReturnType, RTE_CODE) DspInternal_0x2F_ReadSupportedIdentifier
(
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
);
#endif/*#if(DCM_CAR_PLATFORM == DCM_NISSAN_PLATFORM)*/

#endif

#if(DCM_UDS_31_SERVICE == STD_ON)
/*31 Service*//*SWS_Dcm_00257*/
STATIC FUNC(Std_ReturnType, DCM_CODE) DspInternal_31_RoutineControl
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
);
STATIC FUNC(Std_ReturnType, DCM_CODE) DspInternal_31_Sub_Processor
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
);

#if(DCM_CAR_PLATFORM == DCM_NISSAN_PLATFORM)
STATIC FUNC(Std_ReturnType, RTE_CODE) DspInternal_0x31_ReadSupportedIdentifier
(
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
);
#endif/*#if(DCM_CAR_PLATFORM == DCM_NISSAN_PLATFORM)*/

#endif

#if(DCM_UDS_34_SERVICE == STD_ON)
/*34 Service*//*SWS_Dcm_00496*/
STATIC FUNC(Std_ReturnType, DCM_CODE) DspInternal_34_RequestDownload
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
);
#endif

#if((DCM_UDS_34_SERVICE == STD_ON) || (DCM_UDS_3D_SERVICE == STD_ON))
STATIC FUNC(Std_ReturnType, DCM_CODE) DspInternal_WriteMemory
(
    Dcm_OpStatusType OpStatus,
    uint8 MemoryIdentifier,
    uint32 MemoryAddress,
    uint32 MemorySize,
    uint8* MemoryData,
    Dcm_NegativeResponseCodeType* ErrorCode
);
#endif

#if((DCM_UDS_23_SERVICE == STD_ON) || (DCM_UDS_35_SERVICE == STD_ON))
STATIC FUNC(Std_ReturnType, DCM_CODE) DspInternal_ReadMemory
(
    Dcm_OpStatusType OpStatus,
    uint8 MemoryIdentifier,
    uint32 MemoryAddress,
    uint32 MemorySize,
    uint8* MemoryData,
    Dcm_NegativeResponseCodeType* ErrorCode
);
#endif

#if(DCM_UDS_35_SERVICE == STD_ON)
/*35 Service*//*SWS_Dcm_00499*/
STATIC FUNC(Std_ReturnType, DCM_CODE) DspInternal_35_RequestUpload
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
);
#endif

#if(DCM_UDS_36_SERVICE == STD_ON)
/*36 Service*//*SWS_Dcm_00502*/
STATIC FUNC(Std_ReturnType, DCM_CODE) DspInternal_36_TransferData
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
);
#endif

#if(DCM_UDS_37_SERVICE == STD_ON)
/*37 Service*//*SWS_Dcm_00505*/
STATIC FUNC(Std_ReturnType, DCM_CODE) DspInternal_37_RequestTransferExit
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
);
#endif

#if(DCM_UDS_3D_SERVICE == STD_ON)
/*3D Service*//*SWS_Dcm_00488*/
STATIC FUNC(Std_ReturnType, DCM_CODE) DspInternal_3D_WriteMemoryByAddress
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
);
#endif

#if(DCM_UDS_3E_SERVICE == STD_ON)
/*3E Service*//*SWS_Dcm_00251*/
STATIC FUNC(Std_ReturnType, DCM_CODE) DspInternal_3E_TesterPresent
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
);
#endif

#if(DCM_UDS_85_SERVICE == STD_ON)
/*85 Service*//*SWS_Dcm_00249*/
STATIC FUNC(Std_ReturnType, DCM_CODE) DspInternal_85_ControlDTCSetting
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
);
#endif

#if(DCM_UDS_87_SERVICE == STD_ON)
/*87 Service*/
STATIC FUNC(Std_ReturnType, DCM_CODE) DspInternal_87_LinkControl
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
);
#endif

/*******************************************************************************
* OBD Services
*******************************************************************************/
#if(DCM_OBD_01_SERVICE == STD_ON)
/*01 Service*/
STATIC FUNC(Std_ReturnType, DCM_CODE) DspInternal_01_RequestCurrentPowertrainDiagnosticData
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
);

STATIC FUNC(Std_ReturnType, DCM_CODE) DspInternal_01_ReadPidData
(
    uint8 ReqPID,
    uint8 *DataBuffer,
    uint32 *Length
);
#endif

#if(DCM_OBD_02_SERVICE == STD_ON)
/*02 Service*/
STATIC FUNC(Std_ReturnType, DCM_CODE) DspInternal_02_RequestPowertrainFreezeFrameData
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
);

STATIC FUNC(Std_ReturnType, DCM_CODE) DspInternal_02_ReadPidData
(
    uint8 ReqPID,
    uint8 ReqFrame,
    uint8 *DataBuffer,
    uint32 *Length
);
#endif

#if((DCM_OBD_03_SERVICE == STD_ON)||(DCM_OBD_07_SERVICE == STD_ON)||(DCM_OBD_0A_SERVICE == STD_ON))
/*03/07/0A Service*/
STATIC FUNC(Std_ReturnType, DCM_CODE) DspInternal_03_07_0A_ObtainingDTC
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
);
#endif

#if(DCM_OBD_04_SERVICE == STD_ON)
/*04 Service*/
STATIC FUNC(Std_ReturnType, DCM_CODE) DspInternal_04_ClearEmissionRelatedDiagnosticInformation
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
);
#endif

#if(DCM_OBD_06_SERVICE == STD_ON)
/*06 Service*/
STATIC FUNC(Std_ReturnType, DCM_CODE) DspInternal_06_RequestOnBoardMonitoringTestResults
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
);
#endif

#if(DCM_OBD_08_SERVICE == STD_ON)
/*08 Service*/
STATIC FUNC(Std_ReturnType, DCM_CODE) DspInternal_08_RequestControlOfOnBoardSystem
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
);
#endif

#if(DCM_OBD_09_SERVICE == STD_ON)
/*09 Service*/
STATIC FUNC(Std_ReturnType, DCM_CODE) DspInternal_09_RequestVehicleInformation
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
);

STATIC FUNC(Std_ReturnType, DCM_CODE) DspInternal_09_ReadInfoTypeData
(
    Dcm_OpStatusType OpStatus,
    uint8 *DataBuffer,
    uint8 *Length
);
#endif

#define DCM_STOP_SEC_CODE
#include "MemMap.h"



#define DCM_START_SEC_CODE
#include "MemMap.h"

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DcmInternal_InitMsgContext
*
* Description: Init message context
*
* Inputs: None
*
* Outputs: None
*
* Return: None
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, DCM_CODE) DcmInternal_InitMsgContext
(
    void
)
{
    DCM_MSGCONTEXT.reqData = NULL_PTR;
    DCM_MSGCONTEXT.reqDataLen = DCM_DATA_CLEAR;
    DCM_MSGCONTEXT.resData = NULL_PTR;
    DCM_MSGCONTEXT.resDataLen = DCM_DATA_CLEAR;
    DCM_MSGCONTEXT.CopyDataIndex = DCM_DATA_CLEAR;
    DCM_MSGCONTEXT.msgAddInfo.reqType = DCM_DATA_CLEAR;
    ClearSuppressPosRespBit();
    DCM_MSGCONTEXT.resMaxDataLen = DCM_DATA_CLEAR;
    DCM_MSGCONTEXT.idContext = DCM_DATA_CLEAR;
    DCM_MSGCONTEXT.RxPduId = DCM_DATA_CLEAR;

    /*Since this function is called at various points in the code that do not require
    a response, the following statement is most appropriate here.*/
    /*Clear the received PDUs of the protocol means the protocol is idle.*/
    if(DCM_ACTIVE_PROTOCOL_ID < DCM_CFG_NUM_OF_PROTOCOL)
    {
        DCM_PCL_RX_PDU_ID(DCM_ACTIVE_PROTOCOL_ID) = COMSTACK_INVALID_PDUID;
    }
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DcmInternal_InitDcmContext
*
* Description: Init context of Dcm module
*
* Inputs: None
*
* Outputs: None
*
* Return: None
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, DCM_CODE) DcmInternal_InitDcmContext
(
    void
)
{
#if((DCM_UDS_2A_SERVICE == STD_ON)||(DCM_UDS_2C_SERVICE == STD_ON))
    uint16 i;
    uint16 j;
#endif
#if(DCM_UDS_2C_SERVICE == STD_ON)
    uint16 DDDIDBufferIndex;
#endif
#if(DCM_COMM_SUPPORT == STD_ON)
    uint8 channel;
#endif
    uint8 ProtocolId;
#if(DCM_UDS_28_SERVICE == STD_ON)
    DCM_COM_REQSUBSERVICE = DCM_DATA_U8_MAX;
#endif

    ResetDcmState();           /*ModuleState*/
    ClearRxFlag();             /*RxIndFlag*/
    ClearRespPendCounter();    /*RespPendCounter*/
    DCM_SET_PROG_FLAG = FALSE; /*SetProgFlag*/
    /*SecurityLevel*/
    /*SecLevelState[DCM_CFG_NUM_SECURITY_LEVEL]*/

    /*SWS_Dcm_00034*/
    DslInternal_SetSesCtrlType(DCM_DEFAULT_LEVEL);/*SessionLevel*/
    ClearP2Timer();                               /*P2Timer*/
    ClearS3Timer();                               /*S3Timer*/

#if(DCM_UDS_2A_SERVICE == STD_ON)
    DCM_PERIODIC_SCHEDULE_INDEX = DCM_DATA_CLEAR;
    DCM_PERIODIC_SCHEDULE_USEDNUM = DCM_DATA_CLEAR;
    /*SWS_Dcm_01100*/
    for(i = 0U; i < DCM_CFG_DSP_MAX_PERIODIC_DID_SCHEDULER; i++)
    {
        DspInternal_2A_StopOneDid(i);
    }
#endif

#if(DCM_UDS_2C_SERVICE == STD_ON)
    j = 0U;
    for(i = 0U; i < DCM_CFG_DID_NUM; i++)
    {
        if(TRUE == DCM_CFG_DID_INFO_DYN_DEF(i))
        {
            DDDIDBufferIndex = DCM_CFG_DID_INFO_DDDID_BUF_INDEX(i);
            DCM_DDDID_INDEX(DDDIDBufferIndex) = i;
            DCM_DDDID_ELE_PTR(DDDIDBufferIndex) = &(DCM_DDDID_ELEMENT(j));
#if(DCM_DDDID_STORAGE == STD_OFF)
            /*SWS_Dcm_00866*/
            DspInternal_2C_ClearOneDDDID(DDDIDBufferIndex);
#else
            /*SWS_Dcm_00867*//*SWS_Dcm_00868,realized by ReadAll/WriteAll function of NvM*/
            if((DCM_DDDID_ELE_SDID_INDEX(DDDIDBufferIndex, 0U) == DCM_INVALID_DID) \
                    && (DCM_DDDID_ELE_MEM_ID(DDDIDBufferIndex, 0U) == DCM_INVALID_MEMORY_ID))
            {
                DCM_DDDID_DEFINED(DDDIDBufferIndex) = FALSE;
            }
            else
            {
                DCM_DDDID_DEFINED(DDDIDBufferIndex) = TRUE;
            }
#endif
            j += DCM_CFG_DID_INFO_DDDID_MAX_ELE(i);
        }
    }
#endif

#if(DCM_UDS_87_SERVICE == STD_ON)
    DCM_87_VERIFIED = DCM_DATA_CLEAR;
#endif

#if(DCM_COMM_SUPPORT == STD_ON)
    DCM_ACTIVE_DIAGNOSTIC = FALSE;                /*ActiveDiagnostic*/
    for(channel = 0U; channel < DCM_NUM_COMM_CHANNEL; channel++)
    {
        DCM_COMM_CHANNEL_MODE(channel) = DCM_COMM_NOCOM;
    } /*ComMMode[DCM_NUM_COMM_CHANNEL]*/
#endif

    for(ProtocolId = (uint8)0; ProtocolId < DCM_CFG_NUM_OF_PROTOCOL; ProtocolId++)
    {
        DCM_PCL_RX_PDU_ID(ProtocolId) = COMSTACK_INVALID_PDUID;
        DCM_PCL_ERROR_CODE(ProtocolId) = DCM_POSITIVE_RESPONSE;
        ResetNegRespBuffer(ProtocolId);
    }

    DCM_ACTIVE_PROTOCOL_ID = DCM_CFG_NUM_OF_PROTOCOL;     /*ProtocolId*/
    DCM_ACTIVE_CONNECTION_ID = DCM_DATA_CLEAR;    /*ProtocolConnectionId*/
    DCM_ACTIVE_RX_ID = DCM_DATA_CLEAR;            /*ProtocolRxId*/
    DCM_OP_STATUS = DCM_INITIAL;                  /*OpStatus*/
    DcmInternal_InitMsgContext();                 /*MsgContext*/
    DCM_REQ_SERVICE = DCM_DATA_CLEAR;             /*ReqService*/
    DCM_REQ_SERVICEINFO = NULL_PTR;               /*ReqServiceInfo*/
    DCM_SERVICE_FNC = NULL_PTR;                   /*ServiceFnc*/
    DCM_REQ_SUBSERVICE = DCM_DATA_CLEAR;          /*ReqSubService*/
    DCM_REQ_SUBSERVICE_INDEX = DCM_DATA_CLEAR;    /*ReqSubServiceIndex*/
    DCM_REQ_SUBSERVICEINFO = NULL_PTR;            /*ReqSubServiceInfo*/
    DCM_SUBSERVICE_FNC = NULL_PTR;                /*SubServiceFnc*/
    DCM_P_ERRORCODE = NULL_PTR;                   /*pErrorCode*/
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DslInternal_SetSesCtrlType
*
* Description: Set session level
*
* Inputs: SesCtrlType
*
* Outputs: None
*
* Return: None
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, DCM_CODE) DslInternal_SetSesCtrlType
(
    Dcm_SesCtrlType SesCtrlType
)
{
    uint16 i;

    DCM_SESSION_LEVEL = SesCtrlType;
    SchM_Switch_DcmDiagnosticSessionControl(SesCtrlType);

#if(DCM_UDS_27_SERVICE == STD_ON)
#if(DCM_CFG_MANUFACTORY_MODE_SUPPORT == STD_ON)
    if(FALSE == Dcm_CheckManufactoryMode())
    {
#endif
        for(i = 0U; i < DCM_CFG_NUM_SECURITY_LEVEL; i++)
        {
            DCM_SECURITY_SEQUENCE(DCM_ACTIVE_PROTOCOL_ID, i) = FALSE;
        }
        /*SWS_Dcm_00139*/
        DslInternal_SetSecurityLevel(DCM_SECURITY_LOCKED_LEVEL);
#if(DCM_CFG_MANUFACTORY_MODE_SUPPORT == STD_ON)
    }
#endif
#endif/*#if(DCM_UDS_27_SERVICE == STD_ON)*/

#if(DCM_UDS_28_SERVICE == STD_ON)
    DspInternal_28_ResumeCommunication();
#endif

#if(DCM_UDS_2A_SERVICE == STD_ON)
    for(i = 0U; i < DCM_CFG_DSP_MAX_PERIODIC_DID_SCHEDULER; i++)
    {
        DspInternal_2A_StopOneDid(i);
    }
    DCM_PERIODIC_SCHEDULE_USEDNUM = DCM_DATA_CLEAR;
    DCM_PERIODIC_SCHEDULE_INDEX = DCM_DATA_CLEAR;
#endif

#if(DCM_UDS_2C_SERVICE == STD_ON)

#endif

#if(DCM_UDS_2F_SERVICE == STD_ON)
    /*SWS_Dcm_00858*/
#endif

#if(DCM_UDS_31_SERVICE == STD_ON)
    for(i = 0U; i < DCM_CFG_ROUTINE_NUM; i++)
    {
        if(DCM_RID_STATUS(i) != DCM_ROUTINE_NONE)
        {
            DCM_RID_STATUS(i) = DCM_ROUTINE_STOPPED;
        }
    }
#endif
#if((DCM_UDS_34_SERVICE == STD_ON)||(DCM_UDS_35_SERVICE == STD_ON))
    DCM_DOWN_UP_LOAD_STATUS = DCM_LOAD_NONE;
#endif

#if(DCM_UDS_85_SERVICE == STD_ON)
    if(!(DCM_CFG_SESSION_MASK(DCM_SESSION_LEVEL) & DCM_85_SUB_SESREF))
    {
#if(DCM_DEM_SUPPORT == STD_ON)
        (void)Dem_DcmEnableDTCSetting(DEM_DTC_GROUP_ALL, DEM_DTC_KIND_ALL_DTCS);
#else
        Dcm_Rte_ControlDTCSetting_EnableDtcSetting();
#endif
    }
#endif
}

#if(DCM_UDS_27_SERVICE == STD_ON)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DslInternal_SetSecurityLevel
*
* Description: Set security level
*
* Inputs: None
*
* Outputs: None
*
* Return: None
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, DCM_CODE) DslInternal_SetSecurityLevel
(
    Dcm_SecLevelType SecurityLevel
)
{
#if(DCM_CFG_MANUFACTORY_MODE_SUPPORT == STD_ON)
    if(SecurityLevel == DCM_SECURITY_ALL_LEVEL)
    {
        DCM_SECURITY_LEVEL = SecurityLevel;
    }
    else
#endif
        if(SecurityLevel > DCM_CFG_NUM_SECURITY_LEVEL)
        {
            DCM_DET_REPORT_ERROR(DCM_SID_SETSECURITYLEVEL, DCM_E_PARAM);
        }
        else
        {
            DCM_SECURITY_LEVEL = SecurityLevel;
        }
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DslInternal_GetSecurityMask
*
* Description: Get the security mask of current security level
*
* Inputs: None
*
* Outputs: None
*
* Return: The mask value
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Dcm_SecRefType, DCM_CODE) DslInternal_GetSecurityMask
(
    void
)
{
    Dcm_SecRefType Mask;

    if(DCM_SECURITY_LEVEL == DCM_SECURITY_ALL_LEVEL)
    {
        Mask = DCM_ALL_MASK;
    }
    else if(DCM_SECURITY_LEVEL == DCM_SECURITY_LOCKED_LEVEL)
    {
        Mask = DCM_LOCKED_MASK;
    }
    else
    {
        Mask = DCM_CFG_SECURITY_MASK((DCM_SECURITY_LEVEL - (Dcm_SecLevelType)1));
    }
    return Mask;
}
#endif

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DslInternal_MainFunction
*
* Description: Munction to process timing parameters
*
* Inputs: None
*
* Outputs: None
*
* Return: None
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, DCM_CODE) DslInternal_MainFunction
(
    void
)
{
#if(DCM_UDS_27_SERVICE == STD_ON)
    uint8 i;
    uint8 j;
#endif

#if(DCM_UDS_27_SERVICE == STD_ON)
    /*0x27, DelayTimeOnBoot,DelayTime*/
    for(i = (uint8)0; i < DCM_CFG_NUM_OF_PROTOCOL; i++)
    {
        for(j = (uint8)0; j < DCM_CFG_SECURITY_NUM(i); j++)
        {
            if((DCM_SECURITY_ATTEMP_NUM(i, j) == (uint8)0) || (DCM_SECURITY_DELAY_ON_BOOT(i, j) == TRUE))
            {
                if(DCM_SECURITY_DELAY_TIME(i, j) != (uint32)0)
                {
                    DCM_SECURITY_DELAY_TIME(i, j)--;
                }
                else
                {
                    if(DCM_SECURITY_DELAY_ON_BOOT(i, j) == TRUE)
                    {
                        DCM_SECURITY_DELAY_ON_BOOT(i, j) = FALSE;
                    }
                    else
                    {
#if(DCM_CAR_PLATFORM != DCM_FAW_PLATFORM)
                        DCM_SECURITY_ATTEMP_NUM(i, j)++;
#else
                        DCM_SECURITY_ATTEMP_NUM(i, j) = DCM_CFG_SECURITY_ROW_I(i)[j].DcmDspSecurityNumAttDelay;
#endif
                        if((DCM_CFG_SECURITY_ROW_I(i)[j].DcmDspSecurityAttemptCounterEnabled) == TRUE)
                        {
                            (void)(DCM_CFG_SECURITY_ROW_I(i)[j].DcmDspSecuritySetAttemptCounterFnc)(DCM_INITIAL, DCM_SECURITY_ATTEMP_NUM(i, j));
                        }
                    }
                    DCM_SECURITY_DELAY_TIME(i, j) = ((DCM_CFG_SECURITY_ROW_I(i)[j].DcmDspSecurityDelayTime)/DCM_TASK_TIME);
                    DCM_SECURITY_SEQUENCE(i, j) = FALSE;
                }
            }
        }
    }
#endif

    SchM_Enter_Dcm_DCM_EXCLUSIVE_AREA_1();
    /*S3 Server*/
    if(!CheckS3Timer())
    {
        RunS3Timer();
        if(CheckS3Timer())
        {
            Dcm_ResetToDefaultSession();
        }
    }
    SchM_Exit_Dcm_DCM_EXCLUSIVE_AREA_1();

#if(DCM_CAR_PLATFORM == DCM_GEELY_PLATFORM)
    /*P4Server*/
    if(CheckP4Timer())
    {
        RunP4Timer();
        if(!CheckP4Timer())
        {
            ClearP2Timer();
            ClearRespPendCounter();

            (*DCM_SERVICE_FNC)(DCM_CANCEL, &DCM_MSGCONTEXT, DCM_P_ERRORCODE);

            ResetDcmState();
            SetDcmState(DCM_PROCESSING);
            DCM_ERRORCODE = DCM_E_CONDITIONSNOTCORRECT;
            DsdInternal_CreatNegResponse();
            DsdInternal_ProcessingDone();
        }
    }
#endif

    /*P2Server and P2StarServer*/
    if(CheckP2Timer())
    {
        RunP2Timer();
        if((!CheckP2Timer()) && (!CheckDcmState((DCM_RCRRP_FORCE | DCM_RCRRP_REPEATTX))))
        {
            /*SWS_Dcm_00024*/
            (void)DsdInternal_RCRResponsePending(FALSE);
        }
    }
    else if(CheckDcmState(DCM_RCRRP_REPEATTX))
    {
        /*Retry send 0x78.*/
        (void)DsdInternal_RCRResponsePending(FALSE);
    }
    else
    {
        /*do nothing.*/
    }
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DslInternal_CheckProtocolPermission
*
* Description: Determines whether the newly received diagnostic request can be
*              processed.
*
* Inputs: ProtocolId: Protocol to which the newly received diagnostic request belongs
*
* Outputs: None
*
* Return: None
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, DCM_CODE) DslInternal_CheckProtocolPermission
(
    uint8 ProtocolId
)
{
    Std_ReturnType ret = E_NOT_OK;
    PduIdType TxPduId;
    PduInfoType TransmitPdu;

    ResetNegRespBuffer(ProtocolId);

    /*Step 1: Check whether any protocol is currently activated and compare its
    priority with the protocol for receiving new diagnostic request.*/
    if(DCM_ACTIVE_PROTOCOL_ID == DCM_CFG_NUM_OF_PROTOCOL)
    {
        /*SWS_Dcm_00036*/
        /*No protocol is activated.*/
        ret = E_OK;
    }
    else if(DCM_ACTIVE_PROTOCOL_ID == ProtocolId)
    {
        /*New request belongs to the current active protocol.*/
        ret = E_OK;
    }
    else if((DCM_PCL_RX_PDU_ID(DCM_ACTIVE_PROTOCOL_ID) == COMSTACK_INVALID_PDUID) \
        && (DCM_SESSION_LEVEL == DCM_DEFAULT_LEVEL))
    {
        /*SWS_Dcm_00459*//*SWS_Dcm_00625*//*SWS_Dcm_00728*/
        /*The current active protocol is in default session and no active request is in execution phase.*/
        ret = Dcm_Rte_CallbackDCMRequestServices_User_StopProtocol(DCM_CFG_PROTOCOL_ID(DCM_ACTIVE_PROTOCOL_ID));

        if(ret != E_OK)
        {
            /*SWS_Dcm_01190*/
            /*Negative response with NRC 0x22 will be issued.*/
            SetNegRespBuffer(ProtocolId, (DCM_CFG_PROTOCOL_RXBUFFER(ProtocolId)[DCM_SID_INDEX]), DCM_E_CONDITIONSNOTCORRECT);
        }
    }
    else
    {
        /*SWS_Dcm_00015*/
        /*Lower numeric values represent higher protocol priority:
        0 - Highest protocol priority, 255 - Lowest protocol priority.*/
        /*SWS_Dcm_01144*/
        /*Protocol preemption cann't be activated with a concurrent TesterPresent of a higher priority protocol*/
        if((DCM_CFG_PROTOCOL_PRIORITY(DCM_ACTIVE_PROTOCOL_ID) > DCM_CFG_PROTOCOL_PRIORITY(ProtocolId)) \
            && (DCM_CFG_PROTOCOL_RXBUFFER(ProtocolId)[DCM_SID_INDEX] != DCM_3E_SERVICE))
        {
            /*SWS_Dcm_00459*/
            ret = Dcm_Rte_CallbackDCMRequestServices_User_StopProtocol(DCM_CFG_PROTOCOL_ID(DCM_ACTIVE_PROTOCOL_ID));

            if(ret != E_OK)
            {
                /*SWS_Dcm_01190*/
                /*Negative response with NRC 0x22 will be issued.*/
                SetNegRespBuffer(ProtocolId, (DCM_CFG_PROTOCOL_RXBUFFER(ProtocolId)[DCM_SID_INDEX]), DCM_E_CONDITIONSNOTCORRECT);
            }
            else
            {
                if(CheckDcmState(DCM_PROCESSING_DONE | DCM_RCRRP | DCM_RCRRP_FORCE | DCM_RCRRP_REPEATTX))
                {
                    /*SWS_Dcm_00079*/
                    TxPduId = DCM_CFG_PROTOCOL_CONNECTION_MAIN_TX_PDUID(DCM_ACTIVE_PROTOCOL_ID, DCM_ACTIVE_CONNECTION_ID);
                    /*SWS_Dcm_00460*//*Canceling the transmit will be always successful*/
                    DcmCancelTransmit(TxPduId);
                }

                if((CheckDcmState(DCM_PROCESSING)) && (DCM_SERVICE_FNC != NULL_PTR))
                {
                    /*SWS_Dcm_01046*/
                    (void)(*DCM_SERVICE_FNC)(DCM_CANCEL, &DCM_MSGCONTEXT, DCM_P_ERRORCODE);
                }
                
                if(DCM_PCL_RX_PDU_ID(DCM_ACTIVE_PROTOCOL_ID) != COMSTACK_INVALID_PDUID)
                {
                    /*SWS_Dcm_00575*/
                    /*SWS_Dcm_00576*//*Canceling the reception will be always successful*/
                    DcmCancelReceive(DCM_PCL_RX_PDU_ID(DCM_ACTIVE_PROTOCOL_ID));
                }

                if(DCM_SESSION_LEVEL != DCM_DEFAULT_LEVEL)
                {
                    Dcm_ResetToDefaultSession();
                }
                /*Reset Dcm state*/
                ResetDcmState();
                /*Clear the received pdu info of current active protocol.*/
                DCM_PCL_RX_PDU_ID(DCM_ACTIVE_PROTOCOL_ID) = COMSTACK_INVALID_PDUID;
            }
        }
        else
        {
            /*Negative response with NRC 0x21 will be issued.*/
            SetNegRespBuffer(ProtocolId, (DCM_CFG_PROTOCOL_RXBUFFER(ProtocolId)[DCM_SID_INDEX]), DCM_E_BUSYREPEATREQUEST);
        }
    }

    /*Step2: Start the protocol to which the new receive diagnostic request belongs.*/
    if((ret == E_OK) && (DCM_ACTIVE_PROTOCOL_ID != ProtocolId))
    {
        /*Clear the current active protocol*/
        DCM_ACTIVE_PROTOCOL_ID = DCM_CFG_NUM_OF_PROTOCOL;
        /*SWS_Dcm_00036*/
        ret = Dcm_Rte_CallbackDCMRequestServices_User_StartProtocol(DCM_CFG_PROTOCOL_ID(ProtocolId));

        if(ret != E_OK)
        {
            /*SWS_Dcm_00674*/
            /*Negative response with NRC 0x22 will be issued.*/
            SetNegRespBuffer(ProtocolId, (DCM_CFG_PROTOCOL_RXBUFFER(ProtocolId)[DCM_SID_INDEX]), DCM_E_CONDITIONSNOTCORRECT);
        }
    }

    /*Step3: Initializes the diagnostic request processing flow.*/
    if(ret == E_OK)
    {
        /*SWS_Dcm_00145*//*The service table can be accessed directly with the DCM_ACTIVE_PROTOCOL_ID parameter.*/
        DCM_ACTIVE_PROTOCOL_ID = ProtocolId;

#if(DCM_UDS_3E_SERVICE == STD_ON)
        /*SWS_Dcm_00112*//*SWS_Dcm_00113*//*SWS_Dcm_01168*/
        if((DCM_CFG_PROTOCOL_RXBUFFER(ProtocolId)[DCM_SID_INDEX] == DCM_3E_SERVICE) \
            && (DCM_CFG_PROTOCOL_RXBUFFER(ProtocolId)[DCM_SUB_SID_INDEX] == (uint8)0x80) \
            && (DCM_PCL_RX_DATA_LEN(ProtocolId) == DCM_10_11_3E_REQ_LEN))
        {
            if(DCM_SESSION_LEVEL != DCM_DEFAULT_LEVEL)
            {
                SetS3Timer(DCM_CFG_PROTOCOL_S3SERVER(ProtocolId));
            }
            DcmInternal_InitMsgContext();
            ResetDcmState();
        }
        else
#endif
        {
            DCM_P_ERRORCODE = &(DCM_PCL_ERROR_CODE(ProtocolId));
            DCM_ACTIVE_CONNECTION_ID = DCM_PCL_RX_CON_ID(ProtocolId);
            DCM_ACTIVE_RX_ID = DCM_PCL_RX_ID(ProtocolId);
            DCM_MSGCONTEXT.reqDataLen = DCM_PCL_RX_DATA_LEN(ProtocolId);
            DCM_MSGCONTEXT.RxPduId = DCM_PCL_RX_PDU_ID(ProtocolId);

            DCM_MSGCONTEXT.reqData = DCM_CFG_PROTOCOL_RXBUFFER(ProtocolId);
            DCM_MSGCONTEXT.resData = DCM_CFG_PROTOCOL_TXBUFFER(ProtocolId);
            DCM_MSGCONTEXT.resDataLen = DCM_DATA_CLEAR;
            DCM_MSGCONTEXT.CopyDataIndex = DCM_DATA_CLEAR;
            DCM_MSGCONTEXT.msgAddInfo.reqType = \
                DCM_CFG_PROTOCOL_CONNECTION_MAIN_RX_ADDR_TYPE(ProtocolId, DCM_ACTIVE_CONNECTION_ID, DCM_ACTIVE_RX_ID);
            DCM_MSGCONTEXT.resMaxDataLen = DCM_CFG_PROTOCOL_TXBUFFER_SIZE(ProtocolId);

            /*SWS_Dcm_00146*//*Generally, the security level is activated in a non-default session. Therefore, when priority
            preemption occurs, the session must be converted to the default session. Therefore, there is no need to reset the
            security level.*/
            /*SWS_Dcm_00147*//*When switching to the default session, the SchM_Switch function has already been called.*/

            SetRxFlag();
            /*SWS_Dcm_00144*/
            SetP2Timer(DCM_CFG_SESSION_P2(DCM_SESSION_LEVEL));
            SetRespPendCounter(DCM_CFG_RESP_PEND_MAX_NUM);

#if(DCM_COMM_SUPPORT == STD_ON)
            /*SWS_Dcm_00169*/
            if((DCM_SESSION_LEVEL == DCM_DEFAULT_LEVEL) && (DCM_ACTIVE_DIAGNOSTIC == TRUE))
            {
                COMM_DCM_ACTIVEDIAGNOSTIC(DCM_ACTIVE_PROTOCOL_ID, DCM_ACTIVE_CONNECTION_ID);
            }
#endif
        }
    }
    else
    {
        /*SWS_Dcm_00727*/
        if((TRUE == DCM_CFG_RESP_ON_SECOND_REQ) || (DCM_PCL_NEG_BUFFER(ProtocolId)[DCM_INDEX_2] != DCM_E_BUSYREPEATREQUEST))
        {
            TransmitPdu.SduDataPtr = DCM_PCL_NEG_BUFFER(ProtocolId);
            TransmitPdu.SduLength  = DCM_UDS_NEG_RES_LEN;
            TxPduId = DCM_CFG_PROTOCOL_CONNECTION_MAIN_TX_PDUID(ProtocolId, DCM_PCL_RX_CON_ID(ProtocolId));
            DcmTransmit(TxPduId, &TransmitPdu);
        }
        else
        {
            /*Reset the state of the protocol.*/
            DCM_PCL_RX_PDU_ID(ProtocolId) = COMSTACK_INVALID_PDUID;
        }
    }
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DsdInternal_CheckServiceId
*
* Description: Check the request service id is supported or not
*
* Inputs: None
*
* Outputs: None
*
* Return: E_OK:service is supported
*         E_NOT_OK:service isn't supported
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, DCM_CODE) DsdInternal_CheckServiceId
(
    void
)
{
    uint8 i;
    Std_ReturnType Result = E_NOT_OK;

    for(i = 0; i < DCM_CFG_PROTOCOL_SIDTABLE_S_NUM(DCM_ACTIVE_PROTOCOL_ID); i++)
    {
        /*SWS_Dcm_00193*//*SWS_Dcm_00195*//*SWS_Dcm_00035*/
        if((DCM_REQ_SERVICE == (DCM_CFG_PROTOCOL_SIDTABLE_S(DCM_ACTIVE_PROTOCOL_ID)[i].DcmDsdSidTabServiceId)) \
                && (TRUE == (DCM_CFG_PROTOCOL_SIDTABLE_S(DCM_ACTIVE_PROTOCOL_ID)[i].DcmDsdServiceUsed)))
        {
            DCM_REQ_SERVICEINFO = &(DCM_CFG_PROTOCOL_SIDTABLE_S(DCM_ACTIVE_PROTOCOL_ID)[i]);
            /*SWS_Dcm_00221*/
            Result = DsdInternal_MatchServiceFnc();
            break;
        }
    }
    return Result;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DsdInternal_CheckSubServiceId
*
* Description: Check the request sub service id is supported or not
*
* Inputs: None
*
* Outputs: None
*
* Return: E_OK:sub service is supported
*         E_NOT_OK:sub service isn't supported
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, DCM_CODE) DsdInternal_CheckSubServiceId
(
    void
)
{
    Std_ReturnType Result = E_NOT_OK;
    uint8 i;

    for(i = 0U; i < (DCM_REQ_SERVICEINFO->NumOfSubService); i++)
    {
        if((DCM_REQ_SUBSERVICE == DCM_CFG_SUB_SERVICE_ID(i)) \
                && (TRUE == DCM_CFG_SUB_SERVICE_USED(i)))
        {
            DCM_REQ_SUBSERVICE_INDEX = i;
            DCM_REQ_SUBSERVICEINFO = &(DCM_CFG_SUB_SERVICE(i));
            Result = E_OK;
            break;
        }
    }
    return Result;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DsdInternal_MatchServiceFnc
*
* Description: Match the service handler
*
* Inputs: None
*
* Outputs: None
*
* Return: E_OK:service handler is matched
*         E_NOT_OK:service handler isn't matched
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, DCM_CODE) DsdInternal_MatchServiceFnc
(
    void
)
{
    Std_ReturnType Result = E_OK;

    switch(DCM_REQ_SERVICE)
    {
        case DCM_10_SERVICE:
            DCM_SERVICE_FNC = &(DspInternal_10_DiagnosticSessionControl);
            break;
#if(DCM_UDS_11_SERVICE == STD_ON)
        case DCM_11_SERVICE:
            DCM_SERVICE_FNC = &(DspInternal_11_ECUReset);
            break;
#endif
#if((DCM_UDS_14_SERVICE == STD_ON)&&(DCM_DEM_SUPPORT == STD_ON))
        case DCM_14_SERVICE:
            DCM_SERVICE_FNC = &(DspInternal_14_ClearDiagnosticInformation);
            break;
#endif
#if(DCM_UDS_19_SERVICE == STD_ON)
        case DCM_19_SERVICE:
            DCM_SERVICE_FNC = &(DspInternal_19_ReadDTCInformation);
            break;
#endif
#if(DCM_UDS_22_SERVICE == STD_ON)
        case DCM_22_SERVICE:
            DCM_SERVICE_FNC = &(DspInternal_22_ReadDataByIdentifier);
            break;
#endif
#if(DCM_UDS_23_SERVICE == STD_ON)
        case DCM_23_SERVICE:
            DCM_SERVICE_FNC = &(DspInternal_23_ReadMemoryByAddress);
            break;
#endif
#if(DCM_UDS_27_SERVICE == STD_ON)
        case DCM_27_SERVICE:
            DCM_SERVICE_FNC = &(DspInternal_27_SecurityAccess);
            break;
#endif
#if(DCM_UDS_28_SERVICE == STD_ON)
        case DCM_28_SERVICE:
            DCM_SERVICE_FNC = &(DspInternal_28_CommunicationControl);
            break;
#endif
#if(DCM_UDS_2A_SERVICE == STD_ON)
        case DCM_2A_SERVICE:
            DCM_SERVICE_FNC = &(DspInternal_2A_ReadDataByPeriodicIdentifier);
            break;
#endif
#if(DCM_UDS_2C_SERVICE == STD_ON)
        case DCM_2C_SERVICE:
            DCM_SERVICE_FNC = &(DspInternal_2C_DynamicallyDefineDataIdentifier);
            break;
#endif
#if(DCM_UDS_2E_SERVICE == STD_ON)
        case DCM_2E_SERVICE:
            DCM_SERVICE_FNC = &(DspInternal_2E_WriteDataByIdentifier);
            break;
#endif
#if(DCM_UDS_2F_SERVICE == STD_ON)
        case DCM_2F_SERVICE:
            DCM_SERVICE_FNC = &(DspInternal_2F_InputOutputControlByIdentifier);
            break;
#endif
#if(DCM_UDS_31_SERVICE == STD_ON)
        case DCM_31_SERVICE:
            DCM_SERVICE_FNC = &(DspInternal_31_RoutineControl);
            break;
#endif
#if(DCM_UDS_34_SERVICE == STD_ON)
        case DCM_34_SERVICE:
            DCM_SERVICE_FNC = &(DspInternal_34_RequestDownload);
            break;
#endif
#if(DCM_UDS_35_SERVICE == STD_ON)
        case DCM_35_SERVICE:
            DCM_SERVICE_FNC = &(DspInternal_35_RequestUpload);
            break;
#endif
#if(DCM_UDS_36_SERVICE == STD_ON)
        case DCM_36_SERVICE:
            DCM_SERVICE_FNC = &(DspInternal_36_TransferData);
            break;
#endif
#if(DCM_UDS_37_SERVICE == STD_ON)
        case DCM_37_SERVICE:
            DCM_SERVICE_FNC = &(DspInternal_37_RequestTransferExit);
            break;
#endif
#if(DCM_UDS_3D_SERVICE == STD_ON)
        case DCM_3D_SERVICE:
            DCM_SERVICE_FNC = &(DspInternal_3D_WriteMemoryByAddress);
            break;
#endif
#if(DCM_UDS_3E_SERVICE == STD_ON)
        case DCM_3E_SERVICE:
            DCM_SERVICE_FNC = &(DspInternal_3E_TesterPresent);
            break;
#endif
#if(DCM_UDS_85_SERVICE == STD_ON)
        case DCM_85_SERVICE:
            DCM_SERVICE_FNC = &(DspInternal_85_ControlDTCSetting);
            break;
#endif
#if(DCM_UDS_87_SERVICE == STD_ON)
        case DCM_87_SERVICE:
            DCM_SERVICE_FNC = &(DspInternal_87_LinkControl);
            break;
#endif
        /*OBD service*/
#if(DCM_OBD_01_SERVICE == STD_ON)
        case DCM_01_SERVICE:
            DCM_SERVICE_FNC = &(DspInternal_01_RequestCurrentPowertrainDiagnosticData);
            break;
#endif
#if(DCM_OBD_02_SERVICE == STD_ON)
        case DCM_02_SERVICE:
            DCM_SERVICE_FNC = &(DspInternal_02_RequestPowertrainFreezeFrameData);
            break;
#endif
#if((DCM_OBD_03_SERVICE == STD_ON)||(DCM_OBD_07_SERVICE == STD_ON)||(DCM_OBD_0A_SERVICE == STD_ON))
        case DCM_03_SERVICE:
        case DCM_07_SERVICE:
        case DCM_0A_SERVICE:
            DCM_SERVICE_FNC = &(DspInternal_03_07_0A_ObtainingDTC);
            break;
#endif
#if(DCM_OBD_04_SERVICE == STD_ON)
        case DCM_04_SERVICE:
            DCM_SERVICE_FNC = &(DspInternal_04_ClearEmissionRelatedDiagnosticInformation);
            break;
#endif
#if(DCM_OBD_06_SERVICE == STD_ON)
        case DCM_06_SERVICE:
            DCM_SERVICE_FNC = &(DspInternal_06_RequestOnBoardMonitoringTestResults);
            break;
#endif
#if(DCM_OBD_08_SERVICE == STD_ON)
        case DCM_08_SERVICE:
            DCM_SERVICE_FNC = &(DspInternal_08_RequestControlOfOnBoardSystem);
            break;
#endif
#if(DCM_OBD_09_SERVICE == STD_ON)
        case DCM_09_SERVICE:
            DCM_SERVICE_FNC = &(DspInternal_09_RequestVehicleInformation);
            break;
#endif
        default:
            DCM_SERVICE_FNC = (DCM_REQ_SERVICEINFO->DcmDsdSidTabFnc);
            if(DCM_SERVICE_FNC == NULL_PTR)
            {
                Result = E_NOT_OK;
            }
            break;
    }
    return Result;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DsdInternal_DcmConfirmation
*
* Description: None
*
* Inputs: None
*
* Outputs: None
*
* Return: None
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, DCM_CODE) DsdInternal_DcmConfirmation
(
    Dcm_IdContextType idContext,
    uint16 SourceAddress,
    Dcm_ConfirmationStatusType status
)
{
    DspInternal_DcmConfirmation(idContext, SourceAddress, status);
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DsdInternal_CreatNegResponse
*
* Description: Creat the negtive response message
*
* Inputs: None
*
* Outputs: None
*
* Return: None
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, DCM_CODE) DsdInternal_CreatNegResponse
(
    void
)
{
    if((DCM_ERRORCODE != DCM_POSITIVE_RESPONSE) && (DCM_ERRORCODE != DCM_E_RESPONSEPENDING))
    {
        SetNegRespBuffer(DCM_ACTIVE_PROTOCOL_ID, DCM_REQ_SERVICE, DCM_ERRORCODE);
        DCM_MSGCONTEXT.resData = DCM_PCL_NEG_BUFFER(DCM_ACTIVE_PROTOCOL_ID);
        DCM_MSGCONTEXT.resDataLen = DCM_UDS_NEG_RES_LEN;
    }
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DsdInternal_RCRResponsePending
*
* Description: Forced to send a response pengding message
*
* Inputs: ForceRCRRP
*
* Outputs: None
*
* Return: Std_ReturnType
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, DCM_CODE) DsdInternal_RCRResponsePending
(
    boolean ForceRCRRP
)
{
    Std_ReturnType Result = E_OK;
    PduInfoType TxRCRRP;
    PduIdType id;

    if(!CheckDcmState((DCM_PROCESSING_DONE | DCM_RCRRP_FORCE | DCM_RCRRP)))
    {
        /*Clear suppress positive response bit*/
        ClearSuppressPosRespBit();

        if(!CheckRespPendCounter())
        {
            /*SWS_Dcm_00119*/
            SetNegRespBuffer(DCM_ACTIVE_PROTOCOL_ID, DCM_REQ_SERVICE, DCM_E_RESPONSEPENDING);
            TxRCRRP.SduDataPtr = DCM_PCL_NEG_BUFFER(DCM_ACTIVE_PROTOCOL_ID);
            TxRCRRP.SduLength = DCM_UDS_NEG_RES_LEN;

            if(ForceRCRRP == TRUE)
            {
                ClearDcmState(DCM_RCRRP_FORCE_OK);
                SetDcmState(DCM_RCRRP_FORCE);/*do not ReTx*/
            }
            else
            {
                SetDcmState(DCM_RCRRP);/* ReTx */
            }
            /* Transmite 0x78 negative response(NR) */
            id = DCM_CFG_PROTOCOL_CONNECTION_MAIN_TX_PDUID(DCM_ACTIVE_PROTOCOL_ID, DCM_ACTIVE_CONNECTION_ID);
            if(E_OK != DcmTransmit(id, &TxRCRRP))
            {
                ClearDcmState(DCM_RCRRP);

                if(ForceRCRRP == FALSE)
                {
                    SetDcmState(DCM_RCRRP_REPEATTX);
                }
                Result = E_NOT_OK;
            }
        }
        else/*SWS_Dcm_00120*/
        {
#if(DCM_CAR_PLATFORM == DCM_GEELY_PLATFORM)
            ClearP4Timer();
#endif
            (*DCM_SERVICE_FNC)(DCM_CANCEL, &DCM_MSGCONTEXT, DCM_P_ERRORCODE);
            DCM_SERVICE_FNC = NULL_PTR;
            DCM_SUBSERVICE_FNC = NULL_PTR;

            ResetDcmState();
            SetDcmState(DCM_PROCESSING);
#if(DCM_CAR_PLATFORM == DCM_GEELY_PLATFORM)
            DCM_ERRORCODE = DCM_E_CONDITIONSNOTCORRECT;
#else
            DCM_ERRORCODE = DCM_E_GENERALREJECT;
#endif
            DsdInternal_CreatNegResponse();
            DsdInternal_ProcessingDone();
            Result = E_NOT_OK;
        }
    }
    else
    {
        Result = E_NOT_OK;
    }
    return Result;
}


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DsdInternal_ProcessingDone
*
* Description: Means the processing is complete, the final response packet will
*              be sent.
*
* Inputs: None
*
* Outputs: None
*
* Return: None
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, DCM_CODE) DsdInternal_ProcessingDone
(
    void
)
{
    PduInfoType TransmitPdu;
    PduIdType id;
    uint16 SourceAddress;
    boolean RespFlag = FALSE;
    Std_ReturnType ret = E_OK;

    if((CheckDcmState(DCM_PROCESSING)) && (!CheckDcmState(DCM_PROCESSING_DONE)))
    {
        ClearDcmState(DCM_PROCESSING);
        SetDcmState(DCM_PROCESSING_DONE);
        DCM_OP_STATUS = DCM_INITIAL;

        /* Check whether the response length is over the related buffer's buffersize */
        /* Response is always put in physical buffer */
        if((DCM_MSGCONTEXT.resDataLen) > (DCM_MSGCONTEXT.resMaxDataLen))
        {
            DCM_ERRORCODE = DCM_E_RESPONSETOOLONG;
            DsdInternal_CreatNegResponse();
        }
        /*SWS_Dcm_00222*/
        if(DCM_ERRORCODE == DCM_POSITIVE_RESPONSE)
        {
            DCM_MSGCONTEXT.resData[DCM_SID_INDEX] = (DCM_REQ_SERVICE + DCM_SID_RESP_OFFSET);
            if((DCM_MSGCONTEXT.msgAddInfo.suppressPosResponse) == TRUE)
            {
                /*No Response*/
            }
            else
            {
                /*Send Positive Response*/
                RespFlag = TRUE;
            }
        }
        else
        {
            if(((DCM_MSGCONTEXT.msgAddInfo.reqType) == DCM_FUNCTIONAL_TYPE) \
                && ((DCM_ERRORCODE == DCM_E_SERVICENOTSUPPORTED) \
                    || (DCM_ERRORCODE == DCM_E_SUBFUNCTIONNOTSUPPORTED) \
                    || (DCM_ERRORCODE == DCM_E_REQUESTOUTOFRANGE) \
                    || (DCM_ERRORCODE == DCM_E_SUBFUNCTIONNOTSUPPORTEDINACTIVESESSION) \
                    || (DCM_ERRORCODE == DCM_E_SERVICENOTSUPPORTEDINACTIVESESSION)))
            {
                /*No Response*/
            }
            else
            {
                /*Send Negative Response*/
                RespFlag = TRUE;
            }
        }

        if(RespFlag == FALSE)
        {
            /* Start S3 Timer */
            if(DCM_SESSION_LEVEL != DCM_DEFAULT_LEVEL)
            {
                SetS3Timer(DCM_CFG_PROTOCOL_S3SERVER(DCM_ACTIVE_PROTOCOL_ID));
            }
            else if(((DCM_REQ_SERVICE != DCM_10_SERVICE) \
                     && (DCM_REQ_SERVICE != DCM_11_SERVICE)) \
                    || (DCM_ERRORCODE != DCM_POSITIVE_RESPONSE))
            {
                /*SWS_Dcm_00697*/
                COMM_DCM_INACTIVEDIAGNOSTIC(DCM_ACTIVE_PROTOCOL_ID, DCM_ACTIVE_CONNECTION_ID);
            }
            else
            {
                /*ComM_DCM_InactiveDiagnostic of 0x10,0x11 will be executed in their ServicePostFunction*/
            }

            if(DCM_ERRORCODE == DCM_POSITIVE_RESPONSE)
            {
                SourceAddress = DCM_CFG_PROTOCOL_CONNECTION_MAIN_TESTER_ADDR(DCM_ACTIVE_PROTOCOL_ID, \
                                DCM_ACTIVE_CONNECTION_ID);
                DspInternal_DcmConfirmation(DCM_MSGCONTEXT.idContext, SourceAddress, DCM_RES_POS_OK);
            }
            else
            {
                DCM_ERRORCODE = DCM_POSITIVE_RESPONSE;
                DcmInternal_InitMsgContext();
                ResetDcmState();
            }
        }
        else
        {
            /* Positive response or negative response */
            TransmitPdu.SduDataPtr = DCM_MSGCONTEXT.resData;
            TransmitPdu.SduLength  = (uint16)(DCM_MSGCONTEXT.resDataLen);
            DCM_MSGCONTEXT.CopyDataIndex = DCM_DATA_CLEAR;
            /*SWS_Dcm_00114*//*SWS_Dcm_00115*//*SWS_Dcm_00118*/
            id = DCM_CFG_PROTOCOL_CONNECTION_MAIN_TX_PDUID(DCM_ACTIVE_PROTOCOL_ID, DCM_ACTIVE_CONNECTION_ID);
            ret = DcmTransmit(id, &TransmitPdu);
            if(ret != E_OK)
            {
                if(DCM_SESSION_LEVEL != DCM_DEFAULT_LEVEL)
                {
                    SetS3Timer(DCM_CFG_PROTOCOL_S3SERVER(DCM_ACTIVE_PROTOCOL_ID));
                }
                else
                {
                    COMM_DCM_INACTIVEDIAGNOSTIC(DCM_ACTIVE_PROTOCOL_ID, DCM_ACTIVE_CONNECTION_ID);
                }

                DCM_ERRORCODE = DCM_POSITIVE_RESPONSE;
                DcmInternal_InitMsgContext();
                ResetDcmState();
            }
        }
        ClearP2Timer();
        ClearRespPendCounter();
    }
}

#if(DCM_OBD_SUPPORT == STD_ON)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DsdInternal_OBD_ReqErrorReset
*
* Description: This function is used by OBD services to reset Dcm state when
*              there is something wrong in request data.
*
* Inputs: None
*
* Outputs: None
*
* Return: None
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, DCM_CODE) DsdInternal_OBD_ReqErrorReset
(
    void
)
{
    /* Start S3 Timer */
    if(DCM_SESSION_LEVEL != DCM_DEFAULT_LEVEL)
    {
        SetS3Timer(DCM_CFG_PROTOCOL_S3SERVER(DCM_ACTIVE_PROTOCOL_ID));
    }
    else
    {
        COMM_DCM_INACTIVEDIAGNOSTIC(DCM_ACTIVE_PROTOCOL_ID, DCM_ACTIVE_CONNECTION_ID);
    }

    DcmInternal_InitMsgContext();
    ClearP2Timer();
    ClearRespPendCounter();
    ResetDcmState();
}
#endif

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DsdInternal_MainFunction
*
* Description: Mainfunction to check the service is supported or not.
*
* Inputs: None
*
* Outputs: None
*
* Return: None
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, DCM_CODE) DsdInternal_MainFunction
(
    void
)
{
    Std_ReturnType Result = E_OK;
    uint8 SupportAddr;
    Dcm_SesRefType SesLevelRef;
#if(DCM_UDS_27_SERVICE == STD_ON)
    Dcm_SecRefType SecLevelRef;
    Dcm_SecRefType CurSecMask;
#endif

    if(CheckRxFlag())
    {
        ClearRxFlag();
        SetDcmState(DCM_PROCESSING);
        DCM_OP_STATUS = DCM_INITIAL;
        DCM_ERRORCODE = DCM_POSITIVE_RESPONSE;
        DCM_REQ_SERVICE = DCM_MSGCONTEXT.reqData[DCM_SID_INDEX];

#if(DCM_DSD_MANUFACTURER_NOTIFICATION_ENABLED == STD_ON)
        /*SWS_Dcm_00218*/
        Result = Dcm_Rte_ServiceRequestManufacturerNotification_Indication
                (
                    /*SID*/
                    DCM_REQ_SERVICE,
                    /*RequestData:This parameter contains the complete request data (diagnostic buffer),
                                except the service ID*/
                    &(DCM_MSGCONTEXT.reqData[DCM_INDEX_1]),
                    /*DataSize:This parameter defines how many bytes in the RequestData parameter are valid*/
                    (DCM_MSGCONTEXT.reqDataLen - DCM_INDEX_1),
                    /*ReqType*/
                    DCM_MSGCONTEXT.msgAddInfo.reqType,
                    /*SourceAddress*/
                    DCM_CFG_PROTOCOL_CONNECTION_MAIN_TESTER_ADDR(DCM_ACTIVE_PROTOCOL_ID, DCM_ACTIVE_CONNECTION_ID),
                    /*ErrorCode*/
                    DCM_P_ERRORCODE
                );
        /*SWS_Dcm_00462*/
        if(Result == DCM_E_REQUEST_NOT_ACCEPTED)
        {
            if(DCM_SESSION_LEVEL != DCM_DEFAULT_LEVEL)
            {
                SetS3Timer(DCM_CFG_PROTOCOL_S3SERVER(DCM_ACTIVE_PROTOCOL_ID));
            }
            else
            {
                COMM_DCM_INACTIVEDIAGNOSTIC(DCM_ACTIVE_PROTOCOL_ID, DCM_ACTIVE_CONNECTION_ID);
            }
            DcmInternal_InitMsgContext();
            ClearP2Timer();
            ClearRespPendCounter();
            ResetDcmState();
        }
        else
        {
            /*SWS_Dcm_00463,Result = E_NOT_OK,SetNegResponse*/
            /*Result = E_OK;*/
        }
#endif
        /*ECUC_Dcm_00600*//*SWS_Dcm_00084*/
#if(DCM_RESPOND_ALL_REQUEST == STD_OFF)
#if(DCM_DSD_MANUFACTURER_NOTIFICATION_ENABLED == STD_ON)
        if(Result == E_OK)
#endif
        {
            if(((DCM_REQ_SERVICE <= 0x7FU) && (0x40U <= DCM_REQ_SERVICE)) \
                    || (0xC0U <= DCM_REQ_SERVICE))
            {
                if(DCM_SESSION_LEVEL != DCM_DEFAULT_LEVEL)
                {
                    SetS3Timer(DCM_CFG_PROTOCOL_S3SERVER(DCM_ACTIVE_PROTOCOL_ID));
                }
                else
                {
                    COMM_DCM_INACTIVEDIAGNOSTIC(DCM_ACTIVE_PROTOCOL_ID, DCM_ACTIVE_CONNECTION_ID);
                }
                DcmInternal_InitMsgContext();
                ClearP2Timer();
                ClearRespPendCounter();
                ResetDcmState();
                Result = E_NOT_OK;
            }
        }
#endif

#if((DCM_DSD_MANUFACTURER_NOTIFICATION_ENABLED == STD_ON)||(DCM_RESPOND_ALL_REQUEST == STD_OFF))
        if(Result == E_OK)
#endif
        {
            /*SWS_Dcm_00178*//*SWS_Dcm_00827*/
            /*SWS_Dcm_00192*//*SWS_Dcm_00198*/
            if(E_OK != DsdInternal_CheckServiceId())
            {
                /*SWS_Dcm_00197*/
                DCM_ERRORCODE = DCM_E_SERVICENOTSUPPORTED;
                Result = E_NOT_OK;
            }
            else
            {
                SupportAddr = (DCM_REQ_SERVICEINFO->DcmDsdServiceSupportAddress);
                SesLevelRef = (DCM_REQ_SERVICEINFO->DcmDsdSidTabSessionLevelRef);
#if(DCM_UDS_27_SERVICE == STD_ON)
                CurSecMask = DslInternal_GetSecurityMask();
                SecLevelRef = (DCM_REQ_SERVICEINFO->DcmDsdSidTabSecurityLevelRef);
#endif
                if(!(SupportAddr & (((uint8)0x01) << ((uint8)DCM_MSGCONTEXT.msgAddInfo.reqType))))
                {
                    /*check support addressing type*/
                    DCM_ERRORCODE = DCM_E_SERVICENOTSUPPORTED;
                    Result = E_NOT_OK;
                }
                else if(!(DCM_CFG_SESSION_MASK(DCM_SESSION_LEVEL) & SesLevelRef))
                {
                    /*SWS_Dcm_00211*/
                    DCM_ERRORCODE = DCM_E_SERVICENOTSUPPORTEDINACTIVESESSION;
                    Result = E_NOT_OK;
                }
#if(DCM_UDS_27_SERVICE == STD_ON)
                else if(!(CurSecMask & SecLevelRef))
                {
                    /*SWS_Dcm_00217*/
                    DCM_ERRORCODE = DCM_E_SECURITYACCESSDENIED;
                    Result = E_NOT_OK;
                }
#endif
                else
                {
                    /*Result = E_OK; NextStep:processed by DSP*/
                }
            }
        }
#if(DCM_DSD_SUPPLIER_NOTIFICATION_ENABLED == STD_ON)
        if(Result == E_OK)
        {
            /*SWS_Dcm_00516*/
            Result = Dcm_Rte_ServiceRequestSupplierNotification_Indication
                    (
                        DCM_REQ_SERVICE,
                        &(DCM_MSGCONTEXT.reqData[DCM_INDEX_1]),
                        (DCM_MSGCONTEXT.reqDataLen - DCM_INDEX_1),
                        DCM_MSGCONTEXT.msgAddInfo.reqType,
                        DCM_CFG_PROTOCOL_CONNECTION_MAIN_TESTER_ADDR(DCM_ACTIVE_PROTOCOL_ID, DCM_ACTIVE_CONNECTION_ID),
                        DCM_P_ERRORCODE
                    );
            /*SWS_Dcm_00517*/
            if(Result == DCM_E_REQUEST_NOT_ACCEPTED)
            {
                if(DCM_SESSION_LEVEL != DCM_DEFAULT_LEVEL)
                {
                    SetS3Timer(DCM_CFG_PROTOCOL_S3SERVER(DCM_ACTIVE_PROTOCOL_ID));
                }
                else
                {
                    COMM_DCM_INACTIVEDIAGNOSTIC(DCM_ACTIVE_PROTOCOL_ID, DCM_ACTIVE_CONNECTION_ID);
                }
                DcmInternal_InitMsgContext();
                ClearP2Timer();
                ClearRespPendCounter();
                ResetDcmState();
            }
            /*SWS_Dcm_00518*/
            else
            {
                /*SWS_Dcm_00518, Result = E_NOT_OK,SetNegResponse*/
                /*Result = E_OK;*/
            }
        }
#endif
        /*SWS_Dcm_00696*/
        if((Result == E_OK) && (DCM_MSGCONTEXT.reqDataLen < (DCM_REQ_SERVICEINFO->DcmDsdServiceMinLength)))
        {
            DCM_ERRORCODE = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
            Result = E_NOT_OK;
        }

        if(Result == E_OK)
        {
            /*SWS_Dcm_00204*/
            if((DCM_REQ_SERVICEINFO->DcmDsdSidTabSubfuncAvail) == TRUE)
            {
                DCM_REQ_SUBSERVICE = (DCM_MSGCONTEXT.reqData[DCM_SUB_SID_INDEX]);
                if((DCM_REQ_SUBSERVICE & DCM_SUPPRESS_POS_RSP_MASK))
                {
                    /*SWS_Dcm_00202*/
                    DCM_MSGCONTEXT.msgAddInfo.suppressPosResponse = TRUE;
                    /*SWS_Dcm_00201*/
                    DCM_REQ_SUBSERVICE = (DCM_REQ_SUBSERVICE & DCM_SUPPRESS_POS_RSP_MASK_FLIP);
                    DCM_MSGCONTEXT.reqData[DCM_SUB_SID_INDEX] = DCM_REQ_SUBSERVICE;
                }
            }
        }
        else if(DCM_ERRORCODE != DCM_POSITIVE_RESPONSE)
        {
            /*send negative reponse,process over*/
            DsdInternal_CreatNegResponse();
            DsdInternal_ProcessingDone();
        }
        else
        {
            /*do nothing*/
        }
    }
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DspInternal_MainFunction
*
* Description: Mainfunction to check if sub-service is supported or not and 
*              the subsequent processing
*
* Inputs: None
*
* Outputs: None
*
* Return: None
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, DCM_CODE) DspInternal_MainFunction
(
    void
)
{
    Std_ReturnType Result = E_OK;

    /*SWS_Dcm_00196*/
    if((DCM_SERVICE_FNC != NULL_PTR) \
            && (CheckDcmState(DCM_PROCESSING)) \
            && (!CheckDcmState((DCM_RCRRP | DCM_RCRRP_REPEATTX | DCM_RCRRP_FORCE))))
    {
#if(DCM_UDS_2A_SERVICE == STD_ON)
        if((DCM_CURRENT_DID_SERVICE == DCM_2A_SERVICE) \
                && ((DCM_REQ_SERVICE == DCM_22_SERVICE) \
                    || (DCM_REQ_SERVICE == DCM_23_SERVICE) \
                    || (DCM_REQ_SERVICE == DCM_2E_SERVICE) \
                    || (DCM_REQ_SERVICE == DCM_2F_SERVICE)))
        {
            DCM_ERRORCODE = DCM_E_GENERALREJECT;
            /*send negative response*/
            DsdInternal_CreatNegResponse();
            DsdInternal_ProcessingDone();
        }
        else
#endif
        {
#if(DCM_UDS_2A_SERVICE == STD_ON)
            if((DCM_REQ_SERVICE == DCM_22_SERVICE) \
                    || (DCM_REQ_SERVICE == DCM_23_SERVICE) \
                    || (DCM_REQ_SERVICE == DCM_2E_SERVICE) \
                    || (DCM_REQ_SERVICE == DCM_2F_SERVICE))
            {
                DCM_CURRENT_DID_SERVICE = DCM_REQ_SERVICE;
            }
#endif
            Result = (*DCM_SERVICE_FNC)(DCM_OP_STATUS, &DCM_MSGCONTEXT, &DCM_ERRORCODE);

            if(DCM_OP_STATUS != DCM_CANCEL)
            {
                if(Result == E_OK)
                {
#if(DCM_CAR_PLATFORM == DCM_GEELY_PLATFORM)
                    ClearP4Timer();
#endif
                    DCM_ERRORCODE = DCM_POSITIVE_RESPONSE;
                    /*send postive response*/
                    DsdInternal_ProcessingDone();
#if(DCM_UDS_2A_SERVICE == STD_ON)
                    if((DCM_REQ_SERVICE == DCM_22_SERVICE) \
                            || (DCM_REQ_SERVICE == DCM_23_SERVICE) \
                            || (DCM_REQ_SERVICE == DCM_2F_SERVICE))
                    {
                        DCM_CURRENT_DID_SERVICE = DCM_DATA_CLEAR;
                    }
#endif
                }
                else if(Result == DCM_E_PENDING)
                {
                    DCM_OP_STATUS = DCM_PENDING;
                }
                else if(Result == DCM_E_FORCE_RCRRP)
                {
                    DsdInternal_RCRResponsePending(TRUE);
                }
                else if(Result == E_NOT_OK)
                {
                    if((DCM_ERRORCODE == DCM_POSITIVE_RESPONSE) \
                            || (DCM_ERRORCODE == DCM_E_RESPONSEPENDING))
                    {
                        DCM_ERRORCODE = DCM_E_GENERALREJECT;
                    }
#if(DCM_CAR_PLATFORM == DCM_GEELY_PLATFORM)
                    ClearP4Timer();
#endif
                    /*send negative response*/
                    DsdInternal_CreatNegResponse();
                    DsdInternal_ProcessingDone();
#if(DCM_UDS_2A_SERVICE == STD_ON)
                    if((DCM_REQ_SERVICE == DCM_22_SERVICE) \
                            || (DCM_REQ_SERVICE == DCM_23_SERVICE) \
                            || (DCM_REQ_SERVICE == DCM_2F_SERVICE))
                    {
                        DCM_CURRENT_DID_SERVICE = DCM_DATA_CLEAR;
                    }
#endif
                }
                else
                {
                    /*do nothing*/
                }
            }
            else
            {
                /*No Response*/
                DcmInternal_InitMsgContext();
                ResetDcmState();
                DCM_OP_STATUS = DCM_INITIAL;
#if(DCM_UDS_2A_SERVICE == STD_ON)
                if((DCM_REQ_SERVICE == DCM_22_SERVICE) \
                        || (DCM_REQ_SERVICE == DCM_23_SERVICE) \
                        || (DCM_REQ_SERVICE == DCM_2F_SERVICE))
                {
                    DCM_CURRENT_DID_SERVICE = DCM_DATA_CLEAR;
                }
#endif
            }
        }
    }

#if(DCM_UDS_2A_SERVICE == STD_ON)
    DspInternal_2A_PeriodicTransmission();
#endif
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name:
*
* Description:
*
* Inputs:
*
* Outputs:
*
* Return:
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, DCM_CODE) DspInternal_DcmConfirmation
(
    Dcm_IdContextType idContext,
    uint16 SourceAddress,
    Dcm_ConfirmationStatusType status
)
{
   (void)idContext;
   (void)SourceAddress;
	switch(status)
    {
        case DCM_RES_POS_OK:
            DspInternal_PostProcessor();
            break;

        case DCM_RES_POS_NOT_OK:
        case DCM_RES_NEG_OK:
        case DCM_RES_NEG_NOT_OK:
        default:

            break;
    }
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name:
*
* Description:
*
* Inputs:
*
* Outputs:
*
* Return:
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, DCM_CODE) DspInternal_PostProcessor
(
    void
)
{
    switch(DCM_REQ_SERVICE)
    {
        case DCM_10_SERVICE:/*Session Transition*/
            DspInternal_10_Sub_Post();
            break;
#if(DCM_UDS_11_SERVICE == STD_ON)
        case DCM_11_SERVICE:
            SchM_Switch_DcmEcuReset(RTE_MODE_DcmEcuReset_EXECUTE);
            Dcm_ResetToDefaultSession();
            break;
#endif
#if(DCM_UDS_28_SERVICE == STD_ON)
        case DCM_28_SERVICE:
            DspInternal_28_Sub_Post();
            break;
#endif
        default:
            break;
    }
    DcmInternal_InitMsgContext();
    ResetDcmState();
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name:
*
* Description:
*
* Inputs:
*
* Outputs:
*
* Return:
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, DCM_CODE) DspInternal_AddrSesSecCheck
(
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
)

{
    Std_ReturnType Result = E_NOT_OK;
    uint8 SupportAddress = (DCM_REQ_SUBSERVICEINFO->DcmDsdSubServiceSupportAddress);
    Dcm_SesRefType SesLevelRef = (DCM_REQ_SUBSERVICEINFO->DcmDsdSubServiceSessionLevelRef);
#if(DCM_UDS_27_SERVICE == STD_ON)
    Dcm_SecRefType SecLevelRef = (DCM_REQ_SUBSERVICEINFO->DcmDsdSubServiceSecurityLevelRef);
    Dcm_SecRefType CurSecMask = DslInternal_GetSecurityMask();
#endif
#if(DCM_UDS_28_SERVICE == STD_ON)
    DCM_COM_REQSUBSERVICE_SESSION = SesLevelRef;
#endif

    if(!(SupportAddress & (((uint8)0x01) << ((uint8)DCM_MSGCONTEXT.msgAddInfo.reqType))))
    {
        *pErrorCode = DCM_E_SUBFUNCTIONNOTSUPPORTED;
    }
    else if(!(DCM_CFG_SESSION_MASK(DCM_SESSION_LEVEL)& SesLevelRef))
    {
        *pErrorCode = DCM_E_SUBFUNCTIONNOTSUPPORTEDINACTIVESESSION;
    }
#if(DCM_UDS_27_SERVICE == STD_ON)
    else if(!(CurSecMask & SecLevelRef))
    {
        *pErrorCode = DCM_E_SECURITYACCESSDENIED;
    }
#endif
    else
    {
        Result = E_OK;
    }
    return Result;
}


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name:
*
* Description:
*
* Inputs:
*
* Outputs:
*
* Return:
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
/*10 Service*//*SWS_Dcm_00250*/
FUNC(Std_ReturnType, DCM_CODE) DspInternal_10_DiagnosticSessionControl
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
)
{
    Std_ReturnType Result = E_OK;

    if(OpStatus == DCM_INITIAL)
    {
#if(DCM_UDS_10_SUPPORT_SUPPRESSPOSRESBIT != STD_ON)
        ClearSuppressPosRespBit();
#endif
        Result = DsdInternal_CheckSubServiceId();

        if(Result != E_OK)
        {
            /*SWS_Dcm_00307*/
            *pErrorCode = DCM_E_SUBFUNCTIONNOTSUPPORTED;
        }
        else if((pMsgContext->reqDataLen) != DCM_10_11_3E_REQ_LEN)
        {
            /*SWS_Dcm_00272*/
            *pErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
            Result = E_NOT_OK;
        }
        else
        {
            /*SWS_Dcm_00616*//*SWS_Dcm_00617*/
            Result = DspInternal_AddrSesSecCheck(pErrorCode);

            if(Result == E_OK)
            {
#if(DCM_CAR_PLATFORM == DCM_GEELY_PLATFORM)
                SetP4Timer(DCM_REQ_SERVICEINFO->P4ServerMax);
#endif
                DCM_SUBSERVICE_FNC = &(DspInternal_10_Sub_Processor);
                Result = (*DCM_SUBSERVICE_FNC)(OpStatus, pMsgContext, pErrorCode);
            }
        }
    }
    else
    {
        Result = (*DCM_SUBSERVICE_FNC)(OpStatus, pMsgContext, pErrorCode);
    }

    if((Result == E_OK) && (OpStatus != DCM_CANCEL))
    {
        pMsgContext->resData[DCM_SUB_SID_INDEX] = DCM_REQ_SUBSERVICE;
#if(DCM_RESPONSE_WITHP2TIMER==STD_ON)
        pMsgContext->resData[2U] = (uint8)(DCM_CFG_SESSION_P2(DCM_REQ_SUBSERVICE_INDEX) >> 8U);
        pMsgContext->resData[3U] = (uint8)(DCM_CFG_SESSION_P2(DCM_REQ_SUBSERVICE_INDEX));
        pMsgContext->resData[4U] = (uint8)((DCM_CFG_SESSION_P2STAR(DCM_REQ_SUBSERVICE_INDEX) / 10U) >> 8U);
        pMsgContext->resData[5U] = (uint8)(DCM_CFG_SESSION_P2STAR(DCM_REQ_SUBSERVICE_INDEX) / 10U);
#endif
        pMsgContext->resDataLen = DCM_10_RESPONSE_LENGTH;
    }
    return Result;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name:
*
* Description:
*
* Inputs:
*
* Outputs:
*
* Return:
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, DCM_CODE) DspInternal_10_Sub_Processor
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
)
{
    Std_ReturnType Result = E_OK;
    Dcm_ProgConditionsType ProgConditions;
    uint16 SrcAddr;

    (void)pMsgContext;
    if(OpStatus == DCM_INITIAL)
    {
        DCM_SET_PROG_FLAG = FALSE;
    }

    if(DCM_CFG_SESSION_BOOT(DCM_REQ_SUBSERVICE_INDEX) == DCM_NO_BOOT)
    {
        /*Result = E_OK; positive response*/
    }
    else if((DCM_CFG_SESSION_BOOT(DCM_REQ_SUBSERVICE_INDEX) == DCM_OEM_BOOT) \
            || (DCM_CFG_SESSION_BOOT(DCM_REQ_SUBSERVICE_INDEX) == DCM_SYS_BOOT))
    {
        if(DCM_SET_PROG_FLAG == FALSE)
        {
            if(DCM_CFG_SESSION_BOOT(DCM_REQ_SUBSERVICE_INDEX) == DCM_OEM_BOOT)
            {
#ifdef RTE_MODE_DcmEcuReset_JUMPTOBOOTLOADER
                /*SWS_Dcm_00532*/
                Result = SchM_Switch_DcmEcuReset(RTE_MODE_DcmEcuReset_JUMPTOBOOTLOADER);
#endif
            }
            else
            {
#ifdef RTE_MODE_DcmEcuReset_JUMPTOSYSSUPPLIERBOOTLOADER
                /*SWS_Dcm_00592*/
                Result = SchM_Switch_DcmEcuReset(RTE_MODE_DcmEcuReset_JUMPTOSYSSUPPLIERBOOTLOADER);
#endif
            }

            if((Result == E_OK) && (DCM_CFG_PROTOCOL_RPOTTB(DCM_ACTIVE_PROTOCOL_ID) == TRUE))
            {
                /*SWS_Dcm_00654*/
                DCM_SET_PROG_FLAG = TRUE;
                Result = DCM_E_FORCE_RCRRP;
            }
            else if((Result == E_OK) && (DCM_CFG_PROTOCOL_RPOTTB(DCM_ACTIVE_PROTOCOL_ID) == FALSE))
            {
                /*SWS_Dcm_00720*/
                DCM_SET_PROG_FLAG = TRUE;
                Result = DCM_E_PENDING;
            }
            else if(Result == E_NOT_OK)
            {
                /*SWS_Dcm_01175*/
                *pErrorCode = DCM_E_CONDITIONSNOTCORRECT;
            }
            else
            {
                /*Result = DCM_E_PENDING*/
            }
        }
        else
        {
            SrcAddr = DCM_CFG_PROTOCOL_CONNECTION_MAIN_TESTER_ADDR(DCM_ACTIVE_PROTOCOL_ID, \
                      DCM_ACTIVE_CONNECTION_ID);
            ProgConditions.TesterSourceAddr = SrcAddr;
            ProgConditions.ProtocolId = DCM_CFG_PROTOCOL_ID(DCM_ACTIVE_PROTOCOL_ID);
            ProgConditions.Sid = DCM_REQ_SERVICE;
            ProgConditions.SubFncId = DCM_REQ_SUBSERVICE;
            ProgConditions.ReprogramingRequest = TRUE;
            ProgConditions.ApplUpdated = FALSE;
            if(DCM_MSGCONTEXT.msgAddInfo.suppressPosResponse == FALSE)
            {
                ProgConditions.ResponseRequired = TRUE;
            }
            else
            {
                ProgConditions.ResponseRequired = FALSE;
            }
            /*SWS_Dcm_00535*//*SWS_Dcm_01184*/
            Result = Dcm_SetProgConditions(OpStatus, &ProgConditions);

            if(Result == E_OK)
            {
#ifdef RTE_MODE_DcmEcuReset_EXECUTE
                /*SWS_Dcm_01163*//*SWS_Dcm_00719*/
                SchM_Switch_DcmEcuReset(RTE_MODE_DcmEcuReset_EXECUTE);
#endif
                ResetDcmState();
                ClearP2Timer();
#if(DCM_CAR_PLATFORM == DCM_GEELY_PLATFORM)
                ClearP4Timer();
#endif
            }
            else if(Result == E_NOT_OK)
            {
                /*SWS_Dcm_00715*/
                *pErrorCode = DCM_E_CONDITIONSNOTCORRECT;
            }
            else
            {
                /*Result = DCM_E_PENDING*/
            }
        }
    }
    else if((DCM_CFG_SESSION_BOOT(DCM_REQ_SUBSERVICE_INDEX) == DCM_OEM_BOOT_RESPAPP) \
            || (DCM_CFG_SESSION_BOOT(DCM_REQ_SUBSERVICE_INDEX) == DCM_SYS_BOOT_RESPAPP))
    {
        if(DCM_SET_PROG_FLAG == FALSE)
        {
            if(DCM_CFG_SESSION_BOOT(DCM_REQ_SUBSERVICE_INDEX) == DCM_OEM_BOOT_RESPAPP)
            {
#ifdef RTE_MODE_DcmEcuReset_JUMPTOBOOTLOADER
                /*SWS_Dcm_00532*/
                Result = SchM_Switch_DcmEcuReset(RTE_MODE_DcmEcuReset_JUMPTOBOOTLOADER);
#endif
            }
            else
            {
#ifdef RTE_MODE_DcmEcuReset_JUMPTOSYSSUPPLIERBOOTLOADER
                /*SWS_Dcm_00592*/
                Result = SchM_Switch_DcmEcuReset(RTE_MODE_DcmEcuReset_JUMPTOSYSSUPPLIERBOOTLOADER);
#endif
            }

            if((Result == E_OK) && (DCM_CFG_PROTOCOL_RPOTTB(DCM_ACTIVE_PROTOCOL_ID) == TRUE))
            {
                DCM_SET_PROG_FLAG = TRUE;
                Result = DCM_E_FORCE_RCRRP;
            }
            else if((Result == E_OK) && (DCM_CFG_PROTOCOL_RPOTTB(DCM_ACTIVE_PROTOCOL_ID) == FALSE))
            {
                /*SWS_Dcm_01178*/
                DCM_SET_PROG_FLAG = TRUE;
                Result = DCM_E_PENDING;
            }
            else if(Result == E_NOT_OK)
            {
                /*SWS_Dcm_01175*/
                *pErrorCode = DCM_E_CONDITIONSNOTCORRECT;
            }
            else
            {
                /*Result = DCM_E_PENDING*/
            }
        }
        else
        {
            /*SWS_Dcm_01177*//*SWS_Dcm_01178*/
            /*Result = E_OK; positive response*/
            /*SetProgFlag = DCM_BIT_CLEAR;*/
        }
    }
    else
    {
        *pErrorCode = DCM_E_REQUESTOUTOFRANGE;
        Result = E_NOT_OK;
    }
    return Result;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name:
*
* Description:
*
* Inputs:
*
* Outputs:
*
* Return:
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, DCM_CODE) DspInternal_10_Sub_Post
(
    void
)
{
    Dcm_ProgConditionsType ProgConditions;
    uint16 SrcAddr;
    Std_ReturnType ret = E_OK;

    if(DCM_REQ_SUBSERVICE == DCM_DEFAULT_SESSION)
    {
        /*request default session*/
        Dcm_ResetToDefaultSession();
    }
    else
    {
        /*non default session*/
        /*Session level equals to DCM_REQ_SUBSERVICE_INDEX*/
        DslInternal_SetSesCtrlType(DCM_REQ_SUBSERVICE_INDEX);

        SetS3Timer(DCM_CFG_PROTOCOL_S3SERVER(DCM_ACTIVE_PROTOCOL_ID));
        /*SWS_Dcm_00167*/
#if(DCM_COMM_SUPPORT == STD_ON)
        if(DCM_ACTIVE_DIAGNOSTIC == TRUE)
        {
            COMM_DCM_ACTIVEDIAGNOSTIC(DCM_ACTIVE_PROTOCOL_ID, DCM_ACTIVE_CONNECTION_ID);
        }
#endif
    }

    if((DCM_CFG_SESSION_BOOT(DCM_SESSION_LEVEL) == DCM_OEM_BOOT_RESPAPP) \
            || (DCM_CFG_SESSION_BOOT(DCM_SESSION_LEVEL) == DCM_SYS_BOOT_RESPAPP))
    {
        SrcAddr = DCM_CFG_PROTOCOL_CONNECTION_MAIN_TESTER_ADDR(DCM_ACTIVE_PROTOCOL_ID, \
                  DCM_ACTIVE_CONNECTION_ID);

        ProgConditions.TesterSourceAddr = SrcAddr;
        ProgConditions.ProtocolId = DCM_CFG_PROTOCOL_ID(DCM_ACTIVE_PROTOCOL_ID);
        ProgConditions.Sid = DCM_REQ_SERVICE;
        ProgConditions.SubFncId = DCM_REQ_SUBSERVICE;
        ProgConditions.ReprogramingRequest = TRUE;
        ProgConditions.ApplUpdated = FALSE;
        ProgConditions.ResponseRequired = FALSE;
        /*SWS_Dcm_01179*/
        ret = Dcm_SetProgConditions(DCM_INITIAL, &ProgConditions);
        if(ret == E_OK)
        {
#ifdef RTE_MODE_DcmEcuReset_EXECUTE
            /*SWS_Dcm_01180*/
            SchM_Switch_DcmEcuReset(RTE_MODE_DcmEcuReset_EXECUTE);
#endif
        }
        else
        {
            /*SWS_Dcm_01181*/
            /*ret = E_NOT_OK/ret = DCM_E_PENDING*/
            /*do nothing*/
        }
    }
}

#if(DCM_UDS_11_SERVICE == STD_ON)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name:
*
* Description:
*
* Inputs:
*
* Outputs:
*
* Return:
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
/*11 Service*//*SWS_Dcm_00260*/
FUNC(Std_ReturnType, DCM_CODE) DspInternal_11_ECUReset
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
)
{
    Std_ReturnType Result = E_OK;

    if(OpStatus == DCM_INITIAL)
    {
#if(DCM_UDS_11_SUPPORT_SUPPRESSPOSRESBIT != STD_ON)
        ClearSuppressPosRespBit();
#endif
        Result = DsdInternal_CheckSubServiceId();

        if(Result != E_OK)
        {
            /*SWS_Dcm_00273*/
            *pErrorCode = DCM_E_SUBFUNCTIONNOTSUPPORTED;
        }
        else if(pMsgContext->reqDataLen != DCM_10_11_3E_REQ_LEN)
        {
            /*SWS_Dcm_00272*/
            *pErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
            Result = E_NOT_OK;
        }
        else
        {
            /*SWS_Dcm_00616*//*SWS_Dcm_00617*/
            Result = DspInternal_AddrSesSecCheck(pErrorCode);

            if(Result == E_OK)
            {
#if(DCM_CAR_PLATFORM == DCM_GEELY_PLATFORM)
                SetP4Timer(DCM_REQ_SERVICEINFO->P4ServerMax);
#endif
                DCM_SUBSERVICE_FNC = &(DspInternal_11_Sub_Processor);
                Result = (*DCM_SUBSERVICE_FNC)(OpStatus, pMsgContext, pErrorCode);
            }
        }
    }
    else
    {
        Result = (*DCM_SUBSERVICE_FNC)(OpStatus, pMsgContext, pErrorCode);
    }

    if(Result == E_OK)
    {
        pMsgContext->resData[DCM_SUB_SID_INDEX] = DCM_REQ_SUBSERVICE;
        pMsgContext->resDataLen = 2U;
    }
    return Result;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name:
*
* Description:
*
* Inputs:
*
* Outputs:
*
* Return:
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, DCM_CODE) DspInternal_11_Sub_Processor
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
)
{
    Std_ReturnType Result = E_OK;
    Dcm_ProgConditionsType ProgConditions;
    uint16 SrcAddr;

    (void)pMsgContext;
    if(OpStatus == DCM_INITIAL)
    {
        if(DCM_REQ_SUBSERVICE == DCM_HARD_RESET)
        {
            Result = SchM_Switch_DcmEcuReset(RTE_MODE_DcmEcuReset_HARD);
        }
        else if(DCM_REQ_SUBSERVICE == DCM_KEYOFFON_RESET)
        {
            Result = SchM_Switch_DcmEcuReset(RTE_MODE_DcmEcuReset_KEYONOFF);
        }
        else/*(DCM_REQ_SUBSERVICE == DCM_SOFT_RESET)*/
        {
            Result = SchM_Switch_DcmEcuReset(RTE_MODE_DcmEcuReset_SOFT);
        }

        if((Result == E_OK) && (DCM_CFG_DSP_RESP_TO_RESET == DCM_AFTER_RESET))
        {
            SrcAddr = DCM_CFG_PROTOCOL_CONNECTION_MAIN_TESTER_ADDR(DCM_ACTIVE_PROTOCOL_ID, \
                      DCM_ACTIVE_CONNECTION_ID);
            ProgConditions.TesterSourceAddr = SrcAddr;
            ProgConditions.ProtocolId = DCM_CFG_PROTOCOL_ID(DCM_ACTIVE_PROTOCOL_ID);
            ProgConditions.Sid = DCM_REQ_SERVICE;
            ProgConditions.SubFncId = DCM_REQ_SUBSERVICE;
            ProgConditions.ReprogramingRequest = FALSE;
            ProgConditions.ApplUpdated = FALSE;
            if(DCM_MSGCONTEXT.msgAddInfo.suppressPosResponse == FALSE)
            {
                ProgConditions.ResponseRequired = TRUE;
            }
            else
            {
                ProgConditions.ResponseRequired = FALSE;
            }
            /*7.4.4.2 Jump due to ECUReset*/
            Result = Dcm_SetProgConditions(OpStatus, &ProgConditions);

            if(Result == E_OK)
            {
                DCM_MSGCONTEXT.msgAddInfo.suppressPosResponse = TRUE;
            }
        }
    }
    else
    {
        if(DCM_CFG_DSP_RESP_TO_RESET == DCM_AFTER_RESET)
        {
            SrcAddr = DCM_CFG_PROTOCOL_CONNECTION_MAIN_TESTER_ADDR(DCM_ACTIVE_PROTOCOL_ID, \
                      DCM_ACTIVE_CONNECTION_ID);
            ProgConditions.TesterSourceAddr = SrcAddr;
            ProgConditions.ProtocolId = DCM_CFG_PROTOCOL_ID(DCM_ACTIVE_PROTOCOL_ID);
            ProgConditions.Sid = DCM_REQ_SERVICE;
            ProgConditions.SubFncId = DCM_REQ_SUBSERVICE;
            ProgConditions.ReprogramingRequest = FALSE;
            ProgConditions.ApplUpdated = FALSE;
            if(DCM_MSGCONTEXT.msgAddInfo.suppressPosResponse == FALSE)
            {
                ProgConditions.ResponseRequired = TRUE;
            }
            else
            {
                ProgConditions.ResponseRequired = FALSE;
            }
            /*7.4.4.2 Jump due to ECUReset*/
            Result = Dcm_SetProgConditions(OpStatus, &ProgConditions);

            if(Result == E_OK)
            {
                DCM_MSGCONTEXT.msgAddInfo.suppressPosResponse = TRUE;
            }
        }
    }

    if(Result == E_NOT_OK)
    {
        *pErrorCode = DCM_E_GENERALREJECT;
    }
    return Result;
}
#endif

#if((DCM_UDS_14_SERVICE == STD_ON)&&(DCM_DEM_SUPPORT == STD_ON))
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name:
*
* Description:
*
* Inputs:
*
* Outputs:
*
* Return:
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
/*14 Service*//*SWS_Dcm_00247*/
FUNC(Std_ReturnType, DCM_CODE) DspInternal_14_ClearDiagnosticInformation
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
)
{
    Std_ReturnType Result = E_OK;
    uint32 Dtc;
    Dem_ReturnClearDTCType ClearResult = DEM_CLEAR_OK;

    if(OpStatus == DCM_INITIAL)
    {
        DCM_CLEAR_DTC_FLAG = FALSE;
#if(DCM_APP_CLEARDTCCHECK_ENABLE == STD_ON)
        Dcm_ClearDTCAppCheckFinished = FALSE;
#endif
        if((pMsgContext->reqDataLen) != DCM_14_REQ_LEN)
        {
            *pErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
            Result = E_NOT_OK;
        }
        else
        {
#if(DCM_CAR_PLATFORM == DCM_GEELY_PLATFORM)
            SetP4Timer(DCM_REQ_SERVICEINFO->P4ServerMax);
#endif
        }
    }/*if(OpStatus == DCM_INITIAL)*/

    if(Result == E_OK)
    {
        Dtc = Make32Bit(0U, pMsgContext->reqData[DCM_INDEX_1], \
                        pMsgContext->reqData[DCM_INDEX_2], \
                        pMsgContext->reqData[DCM_INDEX_3]);
        if(DCM_CLEAR_DTC_FLAG == FALSE)
        {
            /*SWS_Dcm_01263*/
            ClearResult = Dem_DcmCheckClearParameter(Dtc, DEM_DTC_FORMAT_UDS, DEM_DTC_ORIGIN_PRIMARY_MEMORY);
            switch(ClearResult)
            {
                /*SWS_Dcm_01264*/
                case DEM_CLEAR_PENDING:
                    Result = DCM_E_PENDING;
                    break;
                /*SWS_Dcm_01265*/
                case DEM_CLEAR_WRONG_DTC:
                    Result = E_NOT_OK;
                    *pErrorCode = DCM_E_REQUESTOUTOFRANGE;
                    break;
                /*SWS_Dcm_01267*/
                case DEM_CLEAR_FAILED:
                    Result = E_NOT_OK;
                    *pErrorCode = DCM_E_CONDITIONSNOTCORRECT;
                    break;

                case DEM_CLEAR_OK:
                    DCM_CLEAR_DTC_FLAG = TRUE;
                    break;

                default:
                    Result = E_NOT_OK;
                    *pErrorCode = DCM_E_GENERALREJECT;
                    break;
            }
        }
#if(DCM_APP_CLEARDTCCHECK_ENABLE == STD_ON)
        if((Dcm_ClearDTCAppCheckFinished == FALSE) && (DCM_CLEAR_DTC_FLAG == TRUE))
        {
            /*SWS_Dcm_01268*/
            Result = Dcm_Rte_ClearDiagnosticInformation_ClearDTCCheckFnc(Dtc, pErrorCode);
            switch(Result)
            {
                case E_OK:
                    Dcm_ClearDTCAppCheckFinished = TRUE;
                    break;

                default:
                    break;
            }
        }

        if((Dcm_ClearDTCAppCheckFinished == TRUE) && (DCM_CLEAR_DTC_FLAG == TRUE))
#else/*#if(DCM_APP_CLEARDTCCHECK_ENABLE == STD_ON)*/
        if(DCM_CLEAR_DTC_FLAG == TRUE)
#endif/*#if(DCM_APP_CLEARDTCCHECK_ENABLE == STD_ON)*/
        {
            /*SWS_Dcm_00005*/
            ClearResult = Dem_DcmClearDTC(Dtc, DEM_DTC_FORMAT_UDS, DEM_DTC_ORIGIN_PRIMARY_MEMORY);
            switch(ClearResult)
            {
                /*SWS_Dcm_00706*/
                case DEM_CLEAR_PENDING:
                    Result = DCM_E_PENDING;
                    break;
                /*SWS_Dcm_00708*/
                case DEM_CLEAR_WRONG_DTC:
                    Result = E_NOT_OK;
                    *pErrorCode = DCM_E_REQUESTOUTOFRANGE;
                    break;
                /*SWS_Dcm_00707*/
                case DEM_CLEAR_FAILED:
                /*SWS_Dcm_00966*/
                case DEM_CLEAR_BUSY:
                    Result = E_NOT_OK;
                    *pErrorCode = DCM_E_CONDITIONSNOTCORRECT;
                    break;
                /*SWS_Dcm_01060*/
                case DEM_CLEAR_MEMORY_ERROR:
                    Result = E_NOT_OK;
                    *pErrorCode = DCM_E_GENERALPROGRAMMINGFAILURE;
                    break;
                /*SWS_Dcm_00705*/
                case DEM_CLEAR_OK:
                    /*Result = E_OK;*/
                    break;

                default:
                    Result = E_NOT_OK;
                    *pErrorCode = DCM_E_GENERALREJECT;
                    break;
            }
        }
    }

    if(Result == E_OK)
    {
        pMsgContext->resDataLen = 1U;
    }
    return Result;
}
#endif

#if(DCM_UDS_19_SERVICE == STD_ON)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name:
*
* Description:
*
* Inputs:
*
* Outputs:
*
* Return:
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
/*19 Service*//*SWS_Dcm_00248*/
FUNC(Std_ReturnType, DCM_CODE) DspInternal_19_ReadDTCInformation
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
)
{
    Std_ReturnType Result = E_OK;

    if(OpStatus == DCM_INITIAL)
    {
#if(DCM_UDS_19_SUPPORT_SUPPRESSPOSRESBIT != STD_ON)
        ClearSuppressPosRespBit();
#endif
        Result = DsdInternal_CheckSubServiceId();

        if(Result != E_OK)
        {
            *pErrorCode = DCM_E_SUBFUNCTIONNOTSUPPORTED;
        }
        else
        {
            /*Check message length*/
            /*SWS_Dcm_00272*/
            switch(DCM_REQ_SUBSERVICE)
            {
                case Dcm_reportNumberOfDTCByStatusMask:
                case Dcm_reportDTCByStatusMask:
                case Dcm_reportMirrorMemoryDTCByStatusMask:
                case Dcm_reportNumberOfMirrorMemoryDTCByStatusMask:
                case Dcm_reportNumberOfEmissionsRelatedOBDDTCByStatusMask:
                    if(pMsgContext->reqDataLen != 3U)
                    {
                        Result = E_NOT_OK;
                    }
                    break;

                case Dcm_reportDTCSnapshotIdentification:
                case Dcm_reportSupportedDTC:
                case Dcm_reportDTCFaultDetectionCounter:
                case Dcm_reportDTCWithPermanentStatus:
                    if(pMsgContext->reqDataLen != 2U)
                    {
                        Result = E_NOT_OK;
                    }
                    break;

                case Dcm_reportDTCSnapshotRecordByDTCNumber:
                case Dcm_reportDTCExtDataRecordByDTCNumber:
                case Dcm_reportMirrorMemoryDTCExtDataRecordByDTCNumber:
                    if(pMsgContext->reqDataLen != 6U)
                    {
                        Result = E_NOT_OK;
                    }
                    break;

                default:
                    break;
            }
            /*Check Address&Session&Security*/
            if(Result == E_NOT_OK)
            {
                *pErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
            }
            else
            {
                /*SWS_Dcm_00616*//*SWS_Dcm_00617*/
                Result = DspInternal_AddrSesSecCheck(pErrorCode);
            }

            if(Result == E_OK)
            {
#if(DCM_CAR_PLATFORM == DCM_GEELY_PLATFORM)
                SetP4Timer(DCM_REQ_SERVICEINFO->P4ServerMax);
#endif
#if(DCM_DEM_SUPPORT == STD_ON)
                DCM_SUBSERVICE_FNC = &(DspInternal_19_Sub_Processor);
#else
                if((DCM_REQ_SUBSERVICEINFO->DcmDsdSubServiceFnc) == NULL_PTR)
                {
                    *pErrorCode = DCM_E_GENERALREJECT;
                    Result = E_NOT_OK;
                }
                else
                {
                    DCM_SUBSERVICE_FNC = (DCM_REQ_SUBSERVICEINFO->DcmDsdSubServiceFnc);
                }
#endif
            }
        }
    }/*if(OpStatus == DCM_INITIAL)*/
    /*Executive subservice*/
    if(Result == E_OK)
    {
        Result = (*DCM_SUBSERVICE_FNC)(OpStatus, pMsgContext, pErrorCode);
    }
    /*Send positive response*/
    if(Result == E_OK)
    {
        pMsgContext->resData[DCM_SUB_SID_INDEX] = DCM_REQ_SUBSERVICE;
    }
    return Result;
}
#if(DCM_DEM_SUPPORT == STD_ON)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name:
*
* Description:
*
* Inputs:
*
* Outputs:
*
* Return:
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, DCM_CODE) DspInternal_19_Sub_Processor
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
)
{
    Std_ReturnType Result = E_OK;

    switch(DCM_REQ_SUBSERVICE)
    {
        case Dcm_reportNumberOfDTCByStatusMask:
        case Dcm_reportNumberOfMirrorMemoryDTCByStatusMask:
        case Dcm_reportNumberOfEmissionsRelatedOBDDTCByStatusMask:
            Result = DspInternal_19_01_11_12_Processor(OpStatus, pMsgContext, pErrorCode);
            break;

        case Dcm_reportDTCByStatusMask:
        case Dcm_reportSupportedDTC:
        case Dcm_reportMirrorMemoryDTCByStatusMask:
        case Dcm_reportDTCWithPermanentStatus:
            Result = DspInternal_19_02_0A_0F_15_Processor(OpStatus, pMsgContext, pErrorCode);
            break;

        case Dcm_reportDTCExtDataRecordByDTCNumber:
        case Dcm_reportMirrorMemoryDTCExtDataRecordByDTCNumber:
            Result = DspInternal_19_06_10_Processor(OpStatus, pMsgContext, pErrorCode);
            break;

        case Dcm_reportDTCSnapshotIdentification:
            Result = DspInternal_19_03_Processor(OpStatus, pMsgContext, pErrorCode);
            break;

        case Dcm_reportDTCSnapshotRecordByDTCNumber:
            Result = DspInternal_19_04_Processor(OpStatus, pMsgContext, pErrorCode);
            break;

        case Dcm_reportDTCFaultDetectionCounter:
            Result = DspInternal_19_14_Processor(OpStatus, pMsgContext, pErrorCode);
            break;

        default:
            Result = E_NOT_OK;
            *pErrorCode = DCM_E_SUBFUNCTIONNOTSUPPORTED;
            break;
    }
    return Result;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name:
*
* Description:
*
* Inputs:
*
* Outputs:
*
* Return:
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, DCM_CODE) DspInternal_19_01_11_12_Processor
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
)
{
    Std_ReturnType Result = E_OK;
    Dem_UdsStatusByteType DTCStatusAvailabilityMask;
    uint16 DTCCounter = 0U;
    Dem_ReturnSetFilterType SetFilterResult = DEM_FILTER_ACCEPTED;
    Dem_ReturnGetNumberOfFilteredDTCType GetNumberResult = DEM_NUMBER_OK;

    if(OpStatus == DCM_INITIAL)
    {
        DCM_DTC_STATUS = pMsgContext->reqData[DCM_INDEX_2];
        if(DCM_DTC_STATUS == (uint8)0x00)
        {
            /*SWS_Dcm_00700*/
            Dem_DcmGetDTCStatusAvailabilityMask(&DTCStatusAvailabilityMask);
            pMsgContext->resData[DCM_INDEX_2] = DTCStatusAvailabilityMask;
            pMsgContext->resData[DCM_INDEX_3] = Dem_DcmGetTranslationType();
            pMsgContext->resData[DCM_INDEX_4] = DCM_DATA_CLEAR;
            pMsgContext->resData[DCM_INDEX_5] = DCM_DATA_CLEAR;
            pMsgContext->resDataLen = 6U;/* Always equals 6 */
        }
        else
        {
            /*SWS_Dcm_00835*//*SWS_Dcm_00293*/
            if(DCM_REQ_SUBSERVICE == Dcm_reportNumberOfDTCByStatusMask)
            {
                SetFilterResult = Dem_DcmSetDTCFilter(DCM_DTC_STATUS, DEM_DTC_KIND_ALL_DTCS, DEM_DTC_FORMAT_UDS, \
                                                      DEM_DTC_ORIGIN_PRIMARY_MEMORY, FALSE, 0U, FALSE);
            }
            else if(DCM_REQ_SUBSERVICE == Dcm_reportNumberOfMirrorMemoryDTCByStatusMask)
            {
                SetFilterResult = Dem_DcmSetDTCFilter(DCM_DTC_STATUS, DEM_DTC_KIND_ALL_DTCS, DEM_DTC_FORMAT_UDS, \
                                                      DEM_DTC_ORIGIN_MIRROR_MEMORY, FALSE, 0U, FALSE);
            }
            else/*(DCM_REQ_SUBSERVICE == Dcm_reportNumberOfEmissionsRelatedOBDDTCByStatusMask)*/
            {
                SetFilterResult = Dem_DcmSetDTCFilter(DCM_DTC_STATUS, DEM_DTC_KIND_EMISSION_REL_DTCS, DEM_DTC_FORMAT_UDS, \
                                                      DEM_DTC_ORIGIN_PRIMARY_MEMORY, FALSE, 0U, FALSE);
            }

            if(SetFilterResult != DEM_FILTER_ACCEPTED)
            {
                /*SWS_Dcm_01043*//*SWS_Dcm_01255*/
                *pErrorCode = DCM_E_REQUESTOUTOFRANGE;
                Result = E_NOT_OK;
            }
        }
    }

    if((DCM_DTC_STATUS != (uint8)0x00) && (Result == E_OK))
    {
        /*SWS_Dcm_00293*/
        GetNumberResult = Dem_DcmGetNumberOfFilteredDTC(&DTCCounter);
        if(GetNumberResult == DEM_NUMBER_FAILED)
        {
            *pErrorCode = DCM_E_CONDITIONSNOTCORRECT;
            Result = E_NOT_OK;
        }
        else if(GetNumberResult == DEM_NUMBER_PENDING)
        {
            /*SWS_Dcm_01239*/
            Result = DCM_E_PENDING;
        }
        else/*GetNumberResult == DEM_NUMBER_OK*/
        {
            /*SWS_Dcm_00007*/
            if(Dem_DcmGetDTCStatusAvailabilityMask(&DTCStatusAvailabilityMask) == E_OK)
            {
                /*SWS_Dcm_00376*/
                pMsgContext->resData[2U] = DTCStatusAvailabilityMask;
                /* Get DTC Format */
                pMsgContext->resData[3U] = Dem_DcmGetTranslationType();
                pMsgContext->resData[4U] = (uint8)(DTCCounter >> 8U);
                pMsgContext->resData[5U] = (uint8)(DTCCounter);
                pMsgContext->resDataLen = 6U;/* Always equals 6 */
            }
            else
            {
                *pErrorCode = DCM_E_GENERALREJECT;
                Result = E_NOT_OK;
            }
        }
    }
    return Result;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name:
*
* Description:
*
* Inputs:
*
* Outputs:
*
* Return:
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, DCM_CODE) DspInternal_19_02_0A_0F_15_Processor
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
)
{
    Std_ReturnType Result = E_OK;
    Dem_UdsStatusByteType DTCStatusAvailabilityMask;
    Dem_ReturnSetFilterType SetFilterResult = DEM_FILTER_ACCEPTED;
    uint32 GetDtc;
    Dem_UdsStatusByteType GetDtcStatus;
    Dem_ReturnGetNextFilteredElementType GetNextDtcResult = DEM_FILTERED_OK;

    if(OpStatus == DCM_INITIAL)
    {
        DCM_DTC_COUNTER = DCM_DATA_CLEAR;
        /*Dcm_reportSupportedDTC doesn't have the data*/
        DCM_DTC_STATUS = pMsgContext->reqData[DCM_INDEX_2];
        if((DCM_REQ_SUBSERVICE != Dcm_reportSupportedDTC) \
                && (DCM_REQ_SUBSERVICE != Dcm_reportDTCWithPermanentStatus) \
                && (DCM_DTC_STATUS == (uint8)0x00))
        {
            (void)Dem_DcmGetDTCStatusAvailabilityMask(&DTCStatusAvailabilityMask);
            /*SWS_Dcm_00700*//*SWS_Dcm_01160*/
            pMsgContext->resData[2U] = DTCStatusAvailabilityMask;
            pMsgContext->resDataLen = 3U;
        }
        else
        {
            /*SWS_Dcm_00378*/
            if(DCM_REQ_SUBSERVICE == Dcm_reportDTCByStatusMask)
            {
                SetFilterResult = Dem_DcmSetDTCFilter(DCM_DTC_STATUS, DEM_DTC_KIND_ALL_DTCS, DEM_DTC_FORMAT_UDS, \
                                                      DEM_DTC_ORIGIN_PRIMARY_MEMORY, FALSE, 0U, FALSE);
            }
            else if(DCM_REQ_SUBSERVICE == Dcm_reportSupportedDTC)
            {
                SetFilterResult = Dem_DcmSetDTCFilter(0U, DEM_DTC_KIND_ALL_DTCS, DEM_DTC_FORMAT_UDS, \
                                                      DEM_DTC_ORIGIN_PRIMARY_MEMORY, FALSE, 0U, FALSE);
            }
            else if(DCM_REQ_SUBSERVICE == Dcm_reportMirrorMemoryDTCByStatusMask)
            {
                SetFilterResult = Dem_DcmSetDTCFilter(DCM_DTC_STATUS, DEM_DTC_KIND_ALL_DTCS, DEM_DTC_FORMAT_UDS, \
                                                      DEM_DTC_ORIGIN_MIRROR_MEMORY, FALSE, 0U, FALSE);
            }
            else/*(DCM_REQ_SUBSERVICE == Dcm_reportDTCWithPermanentStatus)*/
            {
                SetFilterResult = Dem_DcmSetDTCFilter(0U, DEM_DTC_KIND_ALL_DTCS, DEM_DTC_FORMAT_UDS, \
                                                      DEM_DTC_ORIGIN_PERMANENT_MEMORY, FALSE, 0U, FALSE);
            }

            if(SetFilterResult != DEM_FILTER_ACCEPTED)
            {
                /*SWS_Dcm_01043*//*SWS_Dcm_01255*/
                *pErrorCode = DCM_E_REQUESTOUTOFRANGE;
                Result = E_NOT_OK;
            }
        }
    }

    if(((DCM_REQ_SUBSERVICE == Dcm_reportSupportedDTC) || (DCM_DTC_STATUS != (uint8)0x00)) \
            && (Result == E_OK))
    {
        do
        {
            /*SWS_Dcm_00378*/
            GetNextDtcResult = Dem_DcmGetNextFilteredDTC(&GetDtc, &GetDtcStatus);

            if(GetNextDtcResult == DEM_FILTERED_OK)
            {
                /*SWS_Dcm_00377*/
                pMsgContext->resData[3U + (DCM_DTC_COUNTER * 4U)] = (uint8)(GetDtc >> 16U);
                pMsgContext->resData[4U + (DCM_DTC_COUNTER * 4U)] = (uint8)(GetDtc >> 8U);
                pMsgContext->resData[5U + (DCM_DTC_COUNTER * 4U)] = (uint8)(GetDtc);
                pMsgContext->resData[6U + (DCM_DTC_COUNTER * 4U)] = GetDtcStatus;
                DCM_DTC_COUNTER++;
            }
            else if(GetNextDtcResult == DEM_FILTERED_PENDING)
            {
                /*SWS_Dcm_01231*/
                Result = DCM_E_PENDING;
            }
            else/*GetNextDtcResult == DEM_FILTERED_NO_MATCHING_ELEMENT*/
            {
                /*GetNextFilteredDTC is over*/
            }
        }
        while((GetNextDtcResult != DEM_FILTERED_NO_MATCHING_ELEMENT) && (Result == E_OK));

        if(Result == E_OK)
        {
            (void)Dem_DcmGetDTCStatusAvailabilityMask(&DTCStatusAvailabilityMask);
            /*SWS_Dcm_01229*//*SWS_Dcm_01230*//*SWS_Dcm_00008*/
            pMsgContext->resData[2U] = DTCStatusAvailabilityMask;
            pMsgContext->resDataLen = (3U + (DCM_DTC_COUNTER * 4U));
        }
    }
    return Result;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name:
*
* Description:
*
* Inputs:
*
* Outputs:
*
* Return:
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, DCM_CODE) DspInternal_19_06_10_Processor
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
)
{
    Std_ReturnType Result = E_OK;
    uint16 RecordSize;
    uint8 DtcStatus;
    Dem_ReturnGetStatusOfDTCType GetStatusOfDTCResult = DEM_STATUS_OK;
    Dem_ReturnDisableDTCRecordUpdateType DisDTCRecUpResult = DEM_DISABLE_DTCRECUP_OK;
    Dem_ReturnGetSizeOfDataByDTCType GetSizeResult = DEM_GETSIZEBYDTC_OK;
    Dem_ReturnGetExtendedDataRecordByDTCType GetExtendedDataResult = DEM_RECORD_OK;

    if(OpStatus == DCM_INITIAL)
    {
        DCM_DTC_DTC = Make32Bit(0U, pMsgContext->reqData[DCM_INDEX_2], \
                                pMsgContext->reqData[DCM_INDEX_3], \
                                pMsgContext->reqData[DCM_INDEX_4]);
        DCM_DTC_RECORDNUM = pMsgContext->reqData[DCM_INDEX_5];
        DCM_DTC_GETSTATUS_FLAG = FALSE;
        DCM_DTC_DISRECUP_FLAG = FALSE;
        DCM_DTC_GETSIZE_FLAG = FALSE;
    }

    /*Step1: GetStatusOfDTC*/
    if(DCM_DTC_GETSTATUS_FLAG == FALSE)
    {
        if(DCM_REQ_SUBSERVICE == Dcm_reportDTCExtDataRecordByDTCNumber)
        {
            /*SWS_Dcm_00295*/
            GetStatusOfDTCResult = Dem_DcmGetStatusOfDTC(DCM_DTC_DTC, DEM_DTC_ORIGIN_PRIMARY_MEMORY, &DtcStatus);
        }
        else/*(DCM_REQ_SUBSERVICE == Dcm_reportMirrorMemoryDTCExtDataRecordByDTCNumber)*/
        {
            GetStatusOfDTCResult = Dem_DcmGetStatusOfDTC(DCM_DTC_DTC, DEM_DTC_ORIGIN_MIRROR_MEMORY, &DtcStatus);
        }

        if(GetStatusOfDTCResult == DEM_STATUS_PENDING)
        {
            /*SWS_Dcm_00739*/
            Result = DCM_E_PENDING;
        }
        else if((GetStatusOfDTCResult == DEM_STATUS_WRONG_DTC) \
                || (GetStatusOfDTCResult == DEM_STATUS_WRONG_DTCORIGIN))
        {
            /*SWS_Dcm_01250*//*SWS_Dcm_01251*/
            *pErrorCode = DCM_E_REQUESTOUTOFRANGE;
            Result = E_NOT_OK;
        }
        else if(GetStatusOfDTCResult == DEM_STATUS_FAILED)
        {
            *pErrorCode = DCM_E_GENERALREJECT;
            Result = E_NOT_OK;
        }
        else/*(GetStatusOfDTCResult == DEM_STATUS_OK)*/
        {
            DCM_DTC_GETSTATUS_FLAG = TRUE;
            pMsgContext->resData[5U] = DtcStatus;
        }
    }
    /*Step2: DisableDTCRecordUpdate*//*SWS_Dcm_00371*/
    if((DCM_DTC_GETSTATUS_FLAG == TRUE) && (DCM_DTC_DISRECUP_FLAG == FALSE))
    {
        if(DCM_REQ_SUBSERVICE == Dcm_reportDTCExtDataRecordByDTCNumber)
        {
            DisDTCRecUpResult = Dem_DcmDisableDTCRecordUpdate(DCM_DTC_DTC, DEM_DTC_ORIGIN_PRIMARY_MEMORY);
        }
        else/*(DCM_REQ_SUBSERVICE == Dcm_reportMirrorMemoryDTCExtDataRecordByDTCNumber)*/
        {
            DisDTCRecUpResult = Dem_DcmDisableDTCRecordUpdate(DCM_DTC_DTC, DEM_DTC_ORIGIN_MIRROR_MEMORY);
        }

        if(DisDTCRecUpResult == DEM_DISABLE_DTCRECUP_PENDING)
        {
            /*SWS_Dcm_00702*/
            Result = DCM_E_PENDING;
        }
        else if((DisDTCRecUpResult == DEM_DISABLE_DTCRECUP_WRONG_DTC) \
                || (DisDTCRecUpResult == DEM_DISABLE_DTCRECUP_WRONG_DTCORIGIN))
        {
            /*SWS_Dcm_01212*//*SWS_Dcm_01213*/
            *pErrorCode = DCM_E_REQUESTOUTOFRANGE;
            Result = E_NOT_OK;
        }
        else/*(DisDTCRecUpResult == DEM_DISABLE_DTCRECUP_OK)*/
        {
            DCM_DTC_DISRECUP_FLAG = TRUE;
        }
    }
    /*Step3: GetSizeOfExtendedDataRecordByDTC*/
    if((DCM_DTC_DISRECUP_FLAG == TRUE) && (DCM_DTC_GETSIZE_FLAG == FALSE))
    {
        if(DCM_REQ_SUBSERVICE == Dcm_reportDTCExtDataRecordByDTCNumber)
        {
            GetSizeResult = Dem_DcmGetSizeOfExtendedDataRecordByDTC(DCM_DTC_DTC, DEM_DTC_ORIGIN_PRIMARY_MEMORY, \
                            DCM_DTC_RECORDNUM, &RecordSize);
        }
        else/*(DCM_REQ_SUBSERVICE == Dcm_reportMirrorMemoryDTCExtDataRecordByDTCNumber)*/
        {
            GetSizeResult = Dem_DcmGetSizeOfExtendedDataRecordByDTC(DCM_DTC_DTC, DEM_DTC_ORIGIN_MIRROR_MEMORY, \
                            DCM_DTC_RECORDNUM, &RecordSize);
        }

        if(GetSizeResult == DEM_GETSIZEBYDTC_PENDING)
        {
            /*SWS_Dcm_01245*/
            Result = DCM_E_PENDING;
        }
        else if((GetSizeResult == DEM_GETSIZEBYDTC_WRONG_DTC) \
                || (GetSizeResult == DEM_GETSIZEBYDTC_WRONG_DTCORIGIN) \
                || (GetSizeResult == DEM_GETSIZEBYDTC_WRONG_RECNUM))
        {
            /*SWS_Dcm_01242*//*SWS_Dcm_01243*//*SWS_Dcm_01244*/
            *pErrorCode = DCM_E_REQUESTOUTOFRANGE;
            Result = E_NOT_OK;
        }
        else/*(GetSizeResult == DEM_GETSIZEBYDTC_OK)*/
        {
            /*6 is 1(0x19)+1(06/10)+3(DTC)+1(DTCStatus)*/
            if(RecordSize > ((pMsgContext->resMaxDataLen) - 6U))
            {
                *pErrorCode = DCM_E_RESPONSETOOLONG;
                Result = E_NOT_OK;
            }
            else if(RecordSize == 0U)
            {
                /*Result = E_OK*/
            }
            else
            {
                DCM_DTC_GETSIZE_FLAG = TRUE;
            }
        }
    }
    /*Step4: GetExtendedDataRecordByDTC*/
    if((Result == E_OK) && (DCM_DTC_GETSIZE_FLAG == TRUE))
    {
        RecordSize = ((pMsgContext->resMaxDataLen) - 6U);

        if(DCM_REQ_SUBSERVICE == Dcm_reportDTCExtDataRecordByDTCNumber)
        {
            GetExtendedDataResult = Dem_DcmGetExtendedDataRecordByDTC(DCM_DTC_DTC, DEM_DTC_ORIGIN_PRIMARY_MEMORY, \
                                    DCM_DTC_RECORDNUM, &(pMsgContext->resData[6U]), &RecordSize);
        }
        else/*(DCM_REQ_SUBSERVICE == Dcm_reportMirrorMemoryDTCExtDataRecordByDTCNumber)*/
        {
            GetExtendedDataResult = Dem_DcmGetExtendedDataRecordByDTC(DCM_DTC_DTC, DEM_DTC_ORIGIN_MIRROR_MEMORY, \
                                    DCM_DTC_RECORDNUM, &(pMsgContext->resData[6U]), &RecordSize);
        }

        if(GetExtendedDataResult == DEM_RECORD_PENDING)
        {
            /*SWS_Dcm_01219*/
            Result = DCM_E_PENDING;
        }
        else if((GetExtendedDataResult == DEM_RECORD_WRONG_DTC) \
                || (GetExtendedDataResult == DEM_RECORD_WRONG_DTCORIGIN) \
                || (GetExtendedDataResult == DEM_RECORD_WRONG_NUMBER))
        {
            /*SWS_Dcm_01214*//*SWS_Dcm_01215*//*SWS_Dcm_01216*/
            *pErrorCode = DCM_E_REQUESTOUTOFRANGE;
            Result = E_NOT_OK;
        }
        else if(GetExtendedDataResult == DEM_RECORD_WRONG_BUFFERSIZE)
        {
            *pErrorCode = DCM_E_GENERALREJECT;
            Result = E_NOT_OK;
        }
        else/*(GetExtendedDataResult == DEM_RECORD_OK)*/
        {
            /*Positive response*/
        }
    }
    /*Step5: EnableDTCRecordUpdate & Creat the response message*/
    if(Result == E_OK)
    {
        (void)Dem_DcmEnableDTCRecordUpdate();/*Always E_OK is returned*/

        pMsgContext->resData[2U] = (uint8)(DCM_DTC_DTC >> 16U);/*DTC High Byte*/
        pMsgContext->resData[3U] = (uint8)(DCM_DTC_DTC >> 8U); /*DTC Middle Byte*/
        pMsgContext->resData[4U] = (uint8)(DCM_DTC_DTC);       /*DTC Low Byte*/
        pMsgContext->resDataLen = (6U + RecordSize);
    }
    else if(Result == E_NOT_OK)
    {
        (void)Dem_DcmEnableDTCRecordUpdate();
    }
    else
    {
        /*Result = DCM_E_PENDING*/
    }
    return Result;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name:
*
* Description:
*
* Inputs:
*
* Outputs:
*
* Return:
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, DCM_CODE) DspInternal_19_03_Processor
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
)
{
    Std_ReturnType Result = E_OK;
    Dem_ReturnSetFilterType SetFilterResult = DEM_FILTER_ACCEPTED;
    Dem_ReturnGetNextFilteredElementType GetNextElementResult = DEM_FILTERED_OK;
    uint32 Dtc;
    uint8 RecordNumber;

    if(OpStatus == DCM_INITIAL)
    {
        DCM_DTC_FILTEREDNUM = DCM_DATA_CLEAR;
        DCM_DTC_COUNTER = DCM_DATA_CLEAR;
        /*SWS_Dcm_00298*/
        SetFilterResult = Dem_DcmSetFreezeFrameRecordFilter(DEM_DTC_FORMAT_UDS, &DCM_DTC_FILTEREDNUM);
        if(SetFilterResult != DEM_FILTER_ACCEPTED)
        {
            /*SWS_Dcm_01256*/
            *pErrorCode = DCM_E_REQUESTOUTOFRANGE;
            Result = E_NOT_OK;
        }
    }

    if((Result == E_OK) && (DCM_DTC_FILTEREDNUM != DCM_DATA_CLEAR))
    {
        do
        {
            /*SWS_Dcm_00299*/
            GetNextElementResult = Dem_DcmGetNextFilteredRecord(&Dtc, &RecordNumber);

            if(GetNextElementResult == DEM_FILTERED_OK)
            {
                /*SWS_Dcm_00300*/
                pMsgContext->resData[2U + (DCM_DTC_COUNTER * 4U)] = (uint8)(Dtc >> 16U);
                pMsgContext->resData[3U + (DCM_DTC_COUNTER * 4U)] = (uint8)(Dtc >> 8U);
                pMsgContext->resData[4U + (DCM_DTC_COUNTER * 4U)] = (uint8)(Dtc);
                pMsgContext->resData[5U + (DCM_DTC_COUNTER * 4U)] = RecordNumber;
                DCM_DTC_COUNTER++;
            }
            else if(GetNextElementResult == DEM_FILTERED_PENDING)
            {
                /*SWS_Dcm_01231*/
                Result = DCM_E_PENDING;
            }
            else if(GetNextElementResult == DEM_FILTERED_BUFFER_TOO_SMALL)
            {
                *pErrorCode = DCM_E_GENERALREJECT;/*to be confirmed*/
                Result = E_NOT_OK;
            }
            else/*GetNextElementResult == DEM_FILTERED_NO_MATCHING_ELEMENT*/
            {
                /*GetNextFilteredRecord is over*/
            }
        }
        while((GetNextElementResult != DEM_FILTERED_NO_MATCHING_ELEMENT) && (Result == E_OK));
    }

    if(Result == E_OK)
    {
        /*SWS_Dcm_01237*//*SWS_Dcm_01238*/
        pMsgContext->resDataLen = (2U + (DCM_DTC_COUNTER * 4U));
    }
    return Result;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name:
*
* Description:
*
* Inputs:
*
* Outputs:
*
* Return:
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, DCM_CODE) DspInternal_19_04_Processor
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
)
{
    Std_ReturnType Result = E_OK;
    uint8 DTCStatus;
    uint16 RecordSize;
    Dem_ReturnGetStatusOfDTCType GetStatusOfDTCResult = DEM_STATUS_OK;
    Dem_ReturnDisableDTCRecordUpdateType DisDTCRecUpResult = DEM_DISABLE_DTCRECUP_OK;
    Dem_ReturnGetSizeOfDataByDTCType GetSizeResult = DEM_GETSIZEBYDTC_OK;
    Dem_ReturnGetFreezeFrameDataByDTCType GetFreezeDataResult = DEM_GET_FFDATABYDTC_OK;

    if(OpStatus == DCM_INITIAL)
    {
        DCM_DTC_DTC = Make32Bit(0U, pMsgContext->reqData[DCM_INDEX_2], \
                                pMsgContext->reqData[DCM_INDEX_3], \
                                pMsgContext->reqData[DCM_INDEX_4]);
        DCM_DTC_RECORDNUM = pMsgContext->reqData[DCM_INDEX_5];
        DCM_DTC_GETSTATUS_FLAG = FALSE;
        DCM_DTC_DISRECUP_FLAG = FALSE;
        DCM_DTC_GETSIZE_FLAG = FALSE;
    }

    /*Step1: GetStatusOfDTC*/
    if(DCM_DTC_GETSTATUS_FLAG == FALSE)
    {
        /*SWS_Dcm_00383*/
        GetStatusOfDTCResult = Dem_DcmGetStatusOfDTC(DCM_DTC_DTC, DEM_DTC_ORIGIN_PRIMARY_MEMORY, &DTCStatus);
        if(GetStatusOfDTCResult == DEM_STATUS_PENDING)
        {
            Result = DCM_E_PENDING;
        }
        else if((GetStatusOfDTCResult == DEM_STATUS_WRONG_DTC) \
                || (GetStatusOfDTCResult == DEM_STATUS_WRONG_DTCORIGIN))
        {
            *pErrorCode = DCM_E_REQUESTOUTOFRANGE;
            Result = E_NOT_OK;
        }
        else if(GetStatusOfDTCResult == DEM_STATUS_FAILED)
        {
            *pErrorCode = DCM_E_CONDITIONSNOTCORRECT;
            Result = E_NOT_OK;
        }
        else/*(GetStatusOfDTCResult == DEM_STATUS_OK)*/
        {
            DCM_DTC_GETSTATUS_FLAG = TRUE;
            pMsgContext->resData[5U] = DTCStatus;
        }
    }
    /*Step2: DisableDTCRecordUpdate*/
    if((DCM_DTC_GETSTATUS_FLAG == TRUE) && (DCM_DTC_DISRECUP_FLAG == FALSE))
    {
        DisDTCRecUpResult = Dem_DcmDisableDTCRecordUpdate(DCM_DTC_DTC, DEM_DTC_ORIGIN_PRIMARY_MEMORY);
        if(DisDTCRecUpResult == DEM_DISABLE_DTCRECUP_PENDING)
        {
            Result = DCM_E_PENDING;
        }
        else if((DisDTCRecUpResult == DEM_DISABLE_DTCRECUP_WRONG_DTC) \
                || (DisDTCRecUpResult == DEM_DISABLE_DTCRECUP_WRONG_DTCORIGIN))
        {
            *pErrorCode = DCM_E_REQUESTOUTOFRANGE;
            Result = E_NOT_OK;
        }
        else/*(DisDTCRecUpResult == DEM_DISABLE_DTCRECUP_OK)*/
        {
            DCM_DTC_DISRECUP_FLAG = TRUE;
        }
    }
    /*Step3: GetSizeOfFreezeFrameByDTC*/
    if((DCM_DTC_DISRECUP_FLAG == TRUE) && (DCM_DTC_GETSIZE_FLAG == FALSE))
    {
        /*SWS_Dcm_00441*/
        GetSizeResult = Dem_DcmGetSizeOfFreezeFrameByDTC(DCM_DTC_DTC, DEM_DTC_ORIGIN_PRIMARY_MEMORY, \
                        DCM_DTC_RECORDNUM, &RecordSize);

        if(GetSizeResult == DEM_GETSIZEBYDTC_PENDING)
        {
            /*SWS_Dcm_01249*/
            Result = DCM_E_PENDING;
        }
        else if((GetSizeResult == DEM_GETSIZEBYDTC_WRONG_DTC) \
                || (GetSizeResult == DEM_GETSIZEBYDTC_WRONG_DTCORIGIN) \
                || (GetSizeResult == DEM_GETSIZEBYDTC_WRONG_RECNUM))
        {
            /*SWS_Dcm_01246*//*SWS_Dcm_01247*//*SWS_Dcm_01248*/
            *pErrorCode = DCM_E_REQUESTOUTOFRANGE;
            Result = E_NOT_OK;
        }
        else/*(GetSizeResult == DEM_GETSIZEBYDTC_OK)*/
        {
            /*6 is 1(0x19)+1(04)+3(DTC)+1(DTCStatus)*/
            if(RecordSize > ((pMsgContext->resMaxDataLen) - 6U))
            {
                *pErrorCode = DCM_E_RESPONSETOOLONG;
                Result = E_NOT_OK;
            }
            else if(RecordSize == 0U)
            {
                /*Result = E_OK*/
            }
            else
            {
                DCM_DTC_GETSIZE_FLAG = TRUE;
            }
        }
    }
    /*Step4: GetFreezeFrameDataByDTC*/
    if((Result == E_OK) && (DCM_DTC_GETSIZE_FLAG == TRUE))
    {
        /*SWS_Dcm_00384*//*SWS_Dcm_00385*/
        RecordSize = ((pMsgContext->resMaxDataLen) - 6U);

        GetFreezeDataResult = Dem_DcmGetFreezeFrameDataByDTC(DCM_DTC_DTC, DEM_DTC_ORIGIN_PRIMARY_MEMORY, \
                              DCM_DTC_RECORDNUM, &(pMsgContext->resData[6U]), &RecordSize);

        if(GetFreezeDataResult == DEM_GET_FFDATABYDTC_PENDING)
        {
            /*SWS_Dcm_01225*/
            Result = DCM_E_PENDING;
        }
        else if((GetFreezeDataResult == DEM_GET_FFDATABYDTC_WRONG_DTC) \
                || (GetFreezeDataResult == DEM_GET_FFDATABYDTC_WRONG_DTCORIGIN) \
                || (GetFreezeDataResult == DEM_GET_FFDATABYDTC_WRONG_RECORDNUMBER))
        {
            /*SWS_Dcm_01220*//*SWS_Dcm_01221*/
            /*SWS_Dcm_01222*//*SWS_Dcm_01223*/
            *pErrorCode = DCM_E_REQUESTOUTOFRANGE;
            Result = E_NOT_OK;
        }
        else/*(GetFreezeDataResult == DEM_GET_FFDATABYDTC_OK)*/
        {
            /*positive response*/
        }
    }
    /*Step5: EnableDTCRecordUpdate & collect the response message*/
    if(Result == E_OK)
    {
        (void)Dem_DcmEnableDTCRecordUpdate();

        pMsgContext->resData[2U] = (uint8)(DCM_DTC_DTC >> 16U);/*DTC High Byte*/
        pMsgContext->resData[3U] = (uint8)(DCM_DTC_DTC >> 8U); /*DTC Middle Byte*/
        pMsgContext->resData[4U] = (uint8)(DCM_DTC_DTC);       /*DTC Low Byte*/
        pMsgContext->resDataLen = (6U + RecordSize);
    }
    else if(Result == E_NOT_OK)
    {
        (void)Dem_DcmEnableDTCRecordUpdate();
    }
    else
    {
        /*Result = DCM_E_PENDING*/
    }
    return Result;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name:
*
* Description:
*
* Inputs:
*
* Outputs:
*
* Return:
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, DCM_CODE) DspInternal_19_14_Processor
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
)
{
    uint32 GetDtc;
    sint8 GetDtcFdc;
    uint16 DTCCounter = 0U;
    Std_ReturnType Result = E_OK;
    Dem_ReturnSetFilterType SetFilterResult = DEM_FILTER_ACCEPTED;
    Dem_ReturnGetNumberOfFilteredDTCType GetNumberResult = DEM_NUMBER_OK;
    Dem_ReturnGetNextFilteredElementType GetNextDtcResult = DEM_FILTERED_OK;

    if(OpStatus == DCM_INITIAL)
    {
        DCM_DTC_COUNTER = DCM_DATA_CLEAR;
        DCM_DTC_GETSIZE_FLAG = FALSE;

        /*Step1: Set Filter*/
        /*SWS_Dcm_00465*//*SWS_Dcm_00519*/
        SetFilterResult = Dem_DcmSetDTCFilter((Dem_UdsStatusByteType)0x00, DEM_DTC_KIND_ALL_DTCS, DEM_DTC_FORMAT_UDS, \
                                              DEM_DTC_ORIGIN_PRIMARY_MEMORY, FALSE, DEM_SEVERITY_NO_SEVERITY, TRUE);
        if(SetFilterResult != DEM_FILTER_ACCEPTED)
        {
            *pErrorCode = DCM_E_REQUESTOUTOFRANGE;
            Result = E_NOT_OK;
        }
    }
    /*Step2: Get Number Of Filtered DTC*/
    if((Result == E_OK) && (DCM_DTC_GETSIZE_FLAG == FALSE))
    {
        /*SWS_Dcm_00681*/
        GetNumberResult = Dem_DcmGetNumberOfFilteredDTC(&DTCCounter);
        if(GetNumberResult == DEM_NUMBER_FAILED)
        {
            *pErrorCode = DCM_E_GENERALREJECT;
            Result = E_NOT_OK;
        }
        else if(GetNumberResult == DEM_NUMBER_PENDING)
        {
            /*SWS_Dcm_01239*/
            Result = DCM_E_PENDING;
        }
        else/*GetNumberResult == DEM_NUMBER_OK*/
        {
            /*Continue Step3*/
            DCM_DTC_GETSIZE_FLAG = TRUE;
        }
    }
    /*Step3: Get Filtered DTC And FDC*/
    if(Result == E_OK)
    {
        do
        {
            /*SWS_Dcm_00465*/
            GetNextDtcResult = Dem_DcmGetNextFilteredDTCAndFDC(&GetDtc, &GetDtcFdc);

            if(GetNextDtcResult == DEM_FILTERED_OK)
            {
                /*SWS_Dcm_00464*/
                pMsgContext->resData[2U + (DCM_DTC_COUNTER * 4U)] = (uint8)(GetDtc >> 16U);
                pMsgContext->resData[3U + (DCM_DTC_COUNTER * 4U)] = (uint8)(GetDtc >> 8U);
                pMsgContext->resData[4U + (DCM_DTC_COUNTER * 4U)] = (uint8)(GetDtc);
                pMsgContext->resData[5U + (DCM_DTC_COUNTER * 4U)] = GetDtcFdc;
                DCM_DTC_COUNTER++;
            }
            else if(GetNextDtcResult == DEM_FILTERED_PENDING)
            {
                Result = DCM_E_PENDING;
            }
            else/*GetNextDtcResult == DEM_FILTERED_NO_MATCHING_ELEMENT*/
            {
                /*GetNextFilteredDTC is over*/
            }
        }
        while((GetNextDtcResult != DEM_FILTERED_NO_MATCHING_ELEMENT) && (Result == E_OK));

        if(Result == E_OK)
        {
            /*SWS_Dcm_01232*//*SWS_Dcm_01233*/
            pMsgContext->resDataLen = (2U + (DCM_DTC_COUNTER * 4U));
        }
    }
    return Result;
}
#endif/*#if(DCM_DEM_SUPPORT == STD_ON)*/
#endif/*#if(DCM_UDS_19_SERVICE == STD_ON)*/

#if(DCM_UDS_22_SERVICE == STD_ON)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DspInternal_22_ReadDataByIdentifier
*
* Description: 
*
* Inputs: OpStatus, pMsgContext, pErrorCode
*
* Outputs: None
*
* Return:
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
/*22 Service*//*SWS_Dcm_00253*/
FUNC(Std_ReturnType, DCM_CODE) DspInternal_22_ReadDataByIdentifier
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
)
{
    Std_ReturnType Result = E_OK;
    uint16 Did;
    uint16 DidIndex;
    uint32 i;
#if((DCM_CAR_PLATFORM == DCM_RNDS_PLATFORM)||(DCM_CAR_PLATFORM == DCM_NISSAN_PLATFORM))
    uint8 DidHighByte;
    boolean ReadSupportedId = FALSE;
#endif
    if(OpStatus == DCM_INITIAL)
    {
#if((DCM_CAR_PLATFORM == DCM_RNDS_PLATFORM)||(DCM_CAR_PLATFORM == DCM_NISSAN_PLATFORM))
        DidHighByte = (pMsgContext->reqData[DCM_INDEX_1]);
#endif
        /*SWS_Dcm_00272*/
        if(!((pMsgContext->reqDataLen) & 0x01U))
        {
            /* the correct request length should be even number and bigger than 0 */
            *pErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
            Result = E_NOT_OK;
        }
        else if(((pMsgContext->reqDataLen) >> 1U) > DCM_CFG_DSP_MAX_DID_READ)
        {
            *pErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
            Result = E_NOT_OK;
        }
#if(DCM_CAR_PLATFORM == DCM_RNDS_PLATFORM)
        else if((DidHighByte == DCM_RNDS_READ_READ_ID) \
            || (DidHighByte == DCM_RNDS_READ_WRITE_ID) \
            || (DidHighByte == DCM_RNDS_READ_IO_ID) \
            || (DidHighByte == DCM_RNDS_READ_ROUTINE_ID))
        {
            /*Getting Identifiers supported by the ECU*/
            Result = DspInternal_Rnds_ReadSupportedIdentifier(DidHighByte, pMsgContext, pErrorCode);
            ReadSupportedId = TRUE;
        }
#endif
#if(DCM_CAR_PLATFORM == DCM_NISSAN_PLATFORM)
        else if(DidHighByte == DCM_RNDS_READ_ID_HIGH_BYTE)
        {
            /*Getting Identifiers supported by the ECU*/
            Result = DspInternal_0x22_ReadSupportedIdentifier(pMsgContext, pErrorCode);
            ReadSupportedId = TRUE;
        }
#endif
        else/*Step1: Check all request did*/
        {
            DCM_DID_IS_READING = FALSE;
            DCM_DID_CHECK_READ_FLAG = FALSE;
            DCM_DID_GET_LEN_FLAG = FALSE;
            DCM_DID_COUNTER = DCM_DATA_CLEAR;
            DCM_DID_POS = DCM_DATA_CLEAR;
            DCM_DID_SIG_INDEX = DCM_DATA_CLEAR;
#if(DCM_NVM_SUPPORT == STD_ON)
            DCM_NVM_READBLOCK_CALLED = FALSE;
#endif
            for(i = 1U; i < (pMsgContext->reqDataLen); i += 2U)
            {
                Did = Make16Bit(pMsgContext->reqData[i], pMsgContext->reqData[i + 1U]);
                Result = DspInternal_22_CheckReadDid(Did, pMsgContext, pErrorCode, &DidIndex);
                if(Result == E_OK)
                {
                    DCM_DID_INDEX_LIST[DCM_DID_COUNTER] = DidIndex;
                    DCM_DID_COUNTER++;
                    DCM_DID_RESP_LEN = 1U;
                }
                else if((Result == E_NOT_OK) && (*pErrorCode != DCM_POSITIVE_RESPONSE))
                {
                    break;
                }
                else
                {
                    /*Continue to check the next request DID*/
                    Result = E_OK;
                }
            }

            if((Result == E_OK) && (DCM_DID_COUNTER == DCM_DATA_CLEAR))
            {
                /*SWS_Dcm_00434*/
                *pErrorCode = DCM_E_REQUESTOUTOFRANGE;
                Result = E_NOT_OK;
            }
        }
#if(DCM_CAR_PLATFORM == DCM_GEELY_PLATFORM)
        SetP4Timer(DCM_REQ_SERVICEINFO->P4ServerMax);
#endif
    }
    /*Step2: Read data of request did that check passed*/
#if((DCM_CAR_PLATFORM == DCM_RNDS_PLATFORM)||(DCM_CAR_PLATFORM == DCM_NISSAN_PLATFORM))
    if((ReadSupportedId == FALSE) && (Result == E_OK))
#else
    if(Result == E_OK)
#endif
    {
        for( ; DCM_DID_POS < DCM_DID_COUNTER; )
        {
            if(DCM_DID_IS_READING == FALSE)
            {
                DCM_DID_IS_READING = TRUE;
                Did = DCM_CFG_DID_ID(DCM_DID_INDEX_LIST[DCM_DID_POS]);
                DCM_DID_RESP_DATA = (pMsgContext->resData + DCM_DID_RESP_LEN);
                DCM_DID_RESP_DATA[0U] = (uint8)(Did >> 8U); /*Did high byte*/
                DCM_DID_RESP_DATA[1U] = (uint8)Did;         /*Did low byte*/
                DCM_DID_DATA_LEN  = 2U;
                DCM_DID_RESP_DATA = (pMsgContext->resData + DCM_DID_RESP_LEN + DCM_DID_DATA_LEN);
            }
            /*read all reference data*/
#if(DCM_UDS_2C_SERVICE == STD_ON)
            if(TRUE == DCM_CFG_DID_INFO_DYN_DEF(DCM_DID_INDEX_LIST[DCM_DID_POS]))
            {
                /*SWS_Dcm_00652*/
                Result = DspInternal_DDDidReadAllRefData(DCM_DID_INDEX_LIST[DCM_DID_POS], \
                         (pMsgContext->resMaxDataLen), \
                         OpStatus, pErrorCode);
            }
            else
#endif
            {
                Result = DspInternal_DidReadAllRefData(DCM_DID_INDEX_LIST[DCM_DID_POS], \
                                                       (pMsgContext->resMaxDataLen), \
                                                       OpStatus, pErrorCode);
            }

            if(Result == E_OK)
            {
                /*continue read next Did*/
                DCM_DID_POS++;
                DCM_DID_RESP_LEN += DCM_DID_DATA_LEN;
                DCM_DID_IS_READING = FALSE;
            }
            else if(Result == E_NOT_OK)
            {
                DCM_DID_POS = DCM_DID_COUNTER;
            }
            else/*Result == DCM_E_PENDING*/
            {
                /*Call again next mainfunction*/
                break;
            }
        }/*for( ; DCM_DID_POS < DCM_DID_COUNTER; )*/
    }
    /*Step3: Send response*/
    if(Result == E_OK)
    {
        pMsgContext->resDataLen = DCM_DID_RESP_LEN;
    }
    else
    {
        /*return Result*/
    }
    return Result;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name:
*
* Description:
*
* Inputs:
*
* Outputs:
*
* Return:
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, DCM_CODE) DspInternal_22_CheckReadDid
(
    uint16 ReqDid,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode,
    P2VAR(uint16, AUTOMATIC, DCM_VAR) pDidIndex
)
{
    Std_ReturnType Result = E_NOT_OK;
    uint32 i;
#if(DCM_UDS_2C_SERVICE == STD_ON)
    uint16 BufferIndex;
    uint8 k;
    uint16 SDidIndex;
#endif
    uint8 SupportAddress;
    Dcm_SesRefType SesLevelRef;
#if(DCM_UDS_27_SERVICE == STD_ON)
    Dcm_SecRefType SecLevelRef;
    Dcm_SecRefType CurSecMask;
#endif

    for(i = 0U; i < DCM_CFG_DID_NUM; i++)
    {
#if(DCM_UDS_2C_SERVICE == STD_ON)
        if((ReqDid == DCM_CFG_DID_ID(i)) && (TRUE == DCM_CFG_DID_USED(i)) \
                && (NULL_PTR != DCM_CFG_DID_INFO_READ(i)) \
                && (TRUE == DCM_CFG_DID_INFO_DYN_DEF(i)))
        {
            BufferIndex = DCM_CFG_DID_INFO_DDDID_BUF_INDEX(i);
            if(TRUE == DCM_DDDID_DEFINED(BufferIndex))
            {
                /*Check address&session&security*/
                Result = E_OK;
            }
            else
            {
                /*SWS_Dcm_00651*/
                *pErrorCode = DCM_E_REQUESTOUTOFRANGE;
                i = DCM_CFG_DID_NUM;
            }
        }
        else
#endif
            if((ReqDid == DCM_CFG_DID_ID(i)) && (TRUE == DCM_CFG_DID_USED(i)) \
                    && (NULL_PTR != DCM_CFG_DID_INFO_READ(i)))
            {
                /*Check address&session&security*/
                Result = E_OK;
            }
            else
            {
                /*i++;*/
            }

        /*SWS_Dcm_00433*//*SWS_Dcm_00438*//*SWS_Dcm_00561*/
        if(Result == E_OK)
        {
            /*Check address&session&security*/
            SupportAddress = (DCM_CFG_DID_INFO_READ(i)->DcmDspDidReadSupportAddress);
            SesLevelRef = (DCM_CFG_DID_INFO_READ(i)->DcmDspDidReadSessionRef);
#if(DCM_UDS_27_SERVICE == STD_ON)
            CurSecMask = DslInternal_GetSecurityMask();
            SecLevelRef = (DCM_CFG_DID_INFO_READ(i)->DcmDspDidReadSecurityLevelRef);
#endif
            if(!(SupportAddress & (((uint8)0x01) << (pMsgContext->msgAddInfo.reqType))))
            {
                i = DCM_CFG_DID_NUM;
                Result = E_NOT_OK;
            }
            else if(!(DCM_CFG_SESSION_MASK(DCM_SESSION_LEVEL) & SesLevelRef))
            {
                /*SWS_Dcm_00434*//*SWS_Dcm_00721*/
                i = DCM_CFG_DID_NUM;
                Result = E_NOT_OK;
            }
#if(DCM_UDS_27_SERVICE == STD_ON)
            else if(!(CurSecMask & SecLevelRef))
            {
                /*SWS_Dcm_00435*//*SWS_Dcm_00722*/
                *pErrorCode = DCM_E_SECURITYACCESSDENIED;
                Result = E_NOT_OK;
                i = DCM_CFG_DID_NUM;
            }
#endif
            else
            {
                /*do nothing*/
                *pDidIndex = i;
            }
        }
        /*SWS_Dcm_00864,SWS_Dcm_00865*//*SWS_Dcm_01097*/
        /*Check session, security for all source DIDs*/
#if(DCM_UDS_2C_SERVICE == STD_ON)
        if((Result == E_OK) && (DCM_CFG_DSP_DDDID_CHECK_SRC_DID == TRUE) \
                && (TRUE == DCM_CFG_DID_INFO_DYN_DEF(i)))
        {
            for(k = 0U; k < DCM_DDDID_ELE_USED_NUM(BufferIndex); k++)
            {
                if(DCM_DDDID_ELE_SDID_INDEX(BufferIndex, k) != DCM_INVALID_DID)
                {
                    SDidIndex = DCM_DDDID_ELE_SDID_INDEX(BufferIndex, k);
                    /*Check address&session&security*/
                    SupportAddress = (DCM_CFG_DID_INFO_READ(SDidIndex)->DcmDspDidReadSupportAddress);
                    SesLevelRef = (DCM_CFG_DID_INFO_READ(SDidIndex)->DcmDspDidReadSessionRef);
#if(DCM_UDS_27_SERVICE == STD_ON)
                    CurSecMask = DslInternal_GetSecurityMask();
                    SecLevelRef = (DCM_CFG_DID_INFO_READ(SDidIndex)->DcmDspDidReadSecurityLevelRef);
#endif
                    if(!(SupportAddress & (((uint8)0x01) << (pMsgContext->msgAddInfo.reqType))))
                    {
                        i = DCM_CFG_DID_NUM;
                        Result = E_NOT_OK;
                        break;
                    }
                    else if(!(DCM_CFG_SESSION_MASK(DCM_SESSION_LEVEL) & SesLevelRef))
                    {
                        /*SWS_Dcm_00434*/
                        i = DCM_CFG_DID_NUM;
                        Result = E_NOT_OK;
                        break;
                    }
#if(DCM_UDS_27_SERVICE == STD_ON)
                    else if(!(CurSecMask & SecLevelRef))
                    {
                        /*SWS_Dcm_00435*/
                        *pErrorCode = DCM_E_SECURITYACCESSDENIED;
                        Result = E_NOT_OK;
                        i = DCM_CFG_DID_NUM;
                        break;
                    }
#endif
                    else
                    {
                        /*do nothing*/
                    }
                }
            }/*for(k = 0U; k < DCM_DDDID_ELE_USED_NUM(j); k++)*/
        }
#endif
        if(Result == E_OK)
        {
            i = DCM_CFG_DID_NUM;
        }
    }/*for(i = 0U; i < DCM_CFG_DID_NUM; i++)*/
    return Result;
}

#if(DCM_CAR_PLATFORM == DCM_RNDS_PLATFORM)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DspInternal_Rnds_ReadSupportedIdentifier
*
* Description: Read supported identifier of 0x22/0x2E/0x2F/0x31 service.
*
* Inputs: DidHighByte, pMsgContext, pErrorCode
*
* Outputs: None
*
* Return: Std_ReturnType
*
* Limitations: Only used to meet Renault's specification
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, DCM_CODE) DspInternal_Rnds_ReadSupportedIdentifier
(
    uint8 DidHighByte,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
)
{
    uint16 i;
    uint8 BytePos;
    uint8 BitPos;
    uint8 ResponseData[DCM_RNDS_READ_DATA_LENGTH];
    Std_ReturnType Result = E_OK;
    uint8 DidLowByte = (pMsgContext->reqData[DCM_INDEX_2]);

    if((pMsgContext->reqDataLen) != DCM_RNDS_READ_LENGTH)
    {
        /*the correct request length should be 3?*/
        *pErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
        Result = E_NOT_OK;
    }
    else
    {
        for(i = 0U; i < DCM_RNDS_READ_DATA_LENGTH; i++)
        {
            /*reset the data value with zero*/
            ResponseData[i] = DCM_DATA_CLEAR;
        }

        switch(DidHighByte)
        {
            case DCM_RNDS_READ_READ_ID:
                if(DCM_RNDS_READ_ID_HIGH_BYTE == DidLowByte)
                {
                    for(i = (uint16)0; i < DCM_CFG_DID_NUM; i++)
                    {
                        if((TRUE == DCM_CFG_DID_USED(i)) && (NULL_PTR != DCM_CFG_DID_INFO_READ(i)))
                        {
                            BytePos = (uint8)(DCM_CFG_DID_ID(i) >> 11);
                            BitPos = (uint8)((DCM_CFG_DID_ID(i) >> 8) % 8);
                            ResponseData[BytePos] |= ((uint8)0x80 >> BitPos);
                        }
                    }
                }
                else
                {
                    for(i = (uint16)0; i < DCM_CFG_DID_NUM; i++)
                    {
                        if((TRUE == DCM_CFG_DID_USED(i)) && (NULL_PTR != DCM_CFG_DID_INFO_READ(i)) \
                                && (((DCM_CFG_DID_ID(i) & DCM_RNDS_ID_HIGH_MASK) >> 8) == DidLowByte))
                        {
                            BytePos = (uint8)((DCM_CFG_DID_ID(i) & DCM_RNDS_ID_LOW_MASK) / 8);
                            BitPos = (uint8)((DCM_CFG_DID_ID(i) & DCM_RNDS_ID_LOW_MASK) % 8);
                            ResponseData[BytePos] |= ((uint8)0x80 >> BitPos);
                        }
                    }
                }
                break;
#if(DCM_UDS_2E_SERVICE == STD_ON)
            case DCM_RNDS_READ_WRITE_ID:
                if(DCM_RNDS_READ_ID_HIGH_BYTE == DidLowByte)
                {
                    for(i = (uint16)0; i < DCM_CFG_DID_NUM; i++)
                    {
                        if((TRUE == DCM_CFG_DID_USED(i)) && (NULL_PTR != DCM_CFG_DID_INFO_WRITE(i)))
                        {
                            BytePos = (uint8)(DCM_CFG_DID_ID(i) >> 11);
                            BitPos = (uint8)((DCM_CFG_DID_ID(i) >> 8) % 8);
                            ResponseData[BytePos] |= ((uint8)0x80 >> BitPos);
                        }
                    }
                }
                else
                {
                    for(i = (uint16)0; i < DCM_CFG_DID_NUM; i++)
                    {
                        if((TRUE == DCM_CFG_DID_USED(i)) && (NULL_PTR != DCM_CFG_DID_INFO_WRITE(i)) \
                                && (((DCM_CFG_DID_ID(i) & DCM_RNDS_ID_HIGH_MASK) >> 8) == DidLowByte))
                        {
                            BytePos = (uint8)((DCM_CFG_DID_ID(i) & DCM_RNDS_ID_LOW_MASK) / 8);
                            BitPos = (uint8)((DCM_CFG_DID_ID(i) & DCM_RNDS_ID_LOW_MASK) % 8);
                            ResponseData[BytePos] |= ((uint8)0x80 >> BitPos);
                        }
                    }
                }
                break;
#endif
#if(DCM_UDS_2F_SERVICE == STD_ON)
            case DCM_RNDS_READ_IO_ID:
                if(DCM_RNDS_READ_ID_HIGH_BYTE == DidLowByte)
                {
                    for(i = (uint16)0; i < DCM_CFG_DID_NUM; i++)
                    {
                        if((TRUE == DCM_CFG_DID_USED(i)) && (NULL_PTR != DCM_CFG_DID_INFO_CONTROL(i)))
                        {
                            BytePos = (uint8)(DCM_CFG_DID_ID(i) >> 11);
                            BitPos = (uint8)((DCM_CFG_DID_ID(i) >> 8) % 8);
                            ResponseData[BytePos] |= ((uint8)0x80 >> BitPos);
                        }
                    }
                }
                else
                {
                    for(i = (uint16)0; i < DCM_CFG_DID_NUM; i++)
                    {
                        if((TRUE == DCM_CFG_DID_USED(i)) && (NULL_PTR != DCM_CFG_DID_INFO_CONTROL(i)) \
                                && (((DCM_CFG_DID_ID(i) & DCM_RNDS_ID_HIGH_MASK) >> 8) == DidLowByte))
                        {
                            BytePos = (uint8)((DCM_CFG_DID_ID(i) & DCM_RNDS_ID_LOW_MASK) / 8);
                            BitPos = (uint8)((DCM_CFG_DID_ID(i) & DCM_RNDS_ID_LOW_MASK) % 8);
                            ResponseData[BytePos] |= ((uint8)0x80 >> BitPos);
                        }
                    }
                }
                break;
#endif
#if(DCM_UDS_31_SERVICE == STD_ON)
            case DCM_RNDS_READ_ROUTINE_ID:
                if(DCM_RNDS_READ_ID_HIGH_BYTE == DidLowByte)
                {
                    for(i = (uint16)0; i < DCM_CFG_ROUTINE_NUM; i++)
                    {
                        if(TRUE == DCM_CFG_ROUTINE_USED(i))
                        {
                            BytePos = (uint8)(DCM_CFG_ROUTINE_ID(i) >> 11);
                            BitPos = (uint8)((DCM_CFG_ROUTINE_ID(i) >> 8) % 8);
                            ResponseData[BytePos] |= ((uint8)0x80 >> BitPos);
                        }
                    }
                }
                else
                {
                    for(i = (uint16)0; i < DCM_CFG_ROUTINE_NUM; i++)
                    {
                        if((TRUE == DCM_CFG_ROUTINE_USED(i)) \
                                && (((DCM_CFG_ROUTINE_ID(i) & DCM_RNDS_ID_HIGH_MASK) >> 8) == DidLowByte))
                        {
                            BytePos = (uint8)((DCM_CFG_ROUTINE_ID(i) & DCM_RNDS_ID_LOW_MASK) / 8);
                            BitPos = (uint8)((DCM_CFG_ROUTINE_ID(i) & DCM_RNDS_ID_LOW_MASK) % 8);
                            ResponseData[BytePos] |= ((uint8)0x80 >> BitPos);
                        }
                    }
                }
                break;
#endif
            default:
                *pErrorCode = DCM_E_REQUESTOUTOFRANGE;
                Result = E_NOT_OK;
                break;
        }
    }

    if(Result == E_OK)
    {
        for(i = 0U; i < DCM_RNDS_READ_DATA_LENGTH; i++)
        {
            /*Copy the data to the response buffer*/
            pMsgContext->resData[DCM_INDEX_3 + i] = ResponseData[i];
        }
        pMsgContext->resData[DCM_INDEX_1] = pMsgContext->reqData[DCM_INDEX_1];
        pMsgContext->resData[DCM_INDEX_2] = pMsgContext->reqData[DCM_INDEX_2];
        DCM_DID_RESP_LEN = (DCM_INDEX_3 + DCM_RNDS_READ_DATA_LENGTH);
    }
    return Result;
}
#endif/*#if(DCM_CAR_PLATFORM == DCM_RNDS_PLATFORM)*/

#if(DCM_CAR_PLATFORM == DCM_NISSAN_PLATFORM)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DspInternal_0x22_ReadSupportedIdentifier
*
* Description: Read supported identifier of 0x22 service.
*
* Inputs: pMsgContext, pErrorCode
*
* Outputs: None
*
* Return: E_OK, E_NOT_OK
*
* Limitations: Only used to meet nissan specification
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, DCM_CODE) DspInternal_0x22_ReadSupportedIdentifier
(
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
)
{
    uint16 i;
    uint8 BytePos;
    uint8 BitPos;
    uint8 ResponseData[DCM_RNDS_READ_DATA_LENGTH];
    Std_ReturnType Result = E_OK;
    uint8 DidLowByte = (pMsgContext->reqData[DCM_INDEX_2]);

    if((pMsgContext->reqDataLen) != DCM_RNDS_READ_LENGTH)
    {
        /*the correct request length should be 2*/
        *pErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
        Result = E_NOT_OK;
    }
    else
    {
        for(i = 0U; i < DCM_RNDS_READ_DATA_LENGTH; i++)
        {
            /*reset the data value with zero*/
            ResponseData[i] = DCM_DATA_CLEAR;
        }

        if(DCM_RNDS_READ_ID_HIGH_BYTE == DidLowByte)
        {
            for(i = (uint16)0; i < DCM_CFG_DID_NUM; i++)
            {
                if((TRUE == DCM_CFG_DID_USED(i)) && (NULL_PTR != DCM_CFG_DID_INFO_READ(i)))
                {
                    BytePos = (uint8)(DCM_CFG_DID_ID(i) >> 11);
                    BitPos = (uint8)((DCM_CFG_DID_ID(i) >> 8) % 8);
                    ResponseData[BytePos] |= ((uint8)0x80 >> BitPos);
                }
            }
        }
        else
        {
            for(i = (uint16)0; i < DCM_CFG_DID_NUM; i++)
            {
                if((TRUE == DCM_CFG_DID_USED(i)) && (NULL_PTR != DCM_CFG_DID_INFO_READ(i)) \
                    && (((DCM_CFG_DID_ID(i) & DCM_RNDS_ID_HIGH_MASK) >> 8) == DidLowByte))
                {
                    BytePos = (uint8)((DCM_CFG_DID_ID(i) & DCM_RNDS_ID_LOW_MASK) / 8);
                    BitPos = (uint8)((DCM_CFG_DID_ID(i) & DCM_RNDS_ID_LOW_MASK) % 8);
                    ResponseData[BytePos] |= ((uint8)0x80 >> BitPos);
                }
            }
        }
    }

    if(Result == E_OK)
    {
        /*Copy the data to the response buffer*/
        Bsw_MemCpy(&(pMsgContext->resData[DCM_INDEX_3]), ResponseData, DCM_RNDS_READ_DATA_LENGTH);

        pMsgContext->resData[DCM_INDEX_1] = pMsgContext->reqData[DCM_INDEX_1];
        pMsgContext->resData[DCM_INDEX_2] = pMsgContext->reqData[DCM_INDEX_2];
        DCM_DID_RESP_LEN = (DCM_INDEX_3 + DCM_RNDS_READ_DATA_LENGTH);
    }
    return Result;
}
#endif/*#if(DCM_CAR_PLATFORM == DCM_NISSAN_PLATFORM)*/

#endif/*#if(DCM_UDS_22_SERVICE == STD_ON)*/

#if((DCM_UDS_22_SERVICE == STD_ON)||(DCM_UDS_2F_SERVICE == STD_ON))
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name:
*
* Description:
*
* Inputs:
*
* Outputs:
*
* Return:
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, DCM_CODE) DspInternal_DidReadAllRefData
(
    uint16 DidIndex,
    uint32 MaxBufferSize,
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
)
{
    Std_ReturnType Result = E_OK;
    uint16 DataPos;
    uint16 DataRef;
    uint16 DataLength = 0U;
#if(DCM_NVM_SUPPORT == STD_ON)
    NvM_RequestResultType NvMResult = NVM_REQ_OK;
#endif
    uint16 FncIndex;

    /*read all reference data*/
    for( ; DCM_DID_SIG_INDEX < DCM_CFG_DID_SIGNAL_NUM(DidIndex); )
    {
        DataPos = DCM_CFG_DID_SIGNAL(DidIndex)[DCM_DID_SIG_INDEX].DcmDspDidDataPos;
        DataRef = DCM_CFG_DID_SIGNAL(DidIndex)[DCM_DID_SIG_INDEX].DcmDspDidDataRef;
        DataPos = (DataPos >> 3U);
        /*SWS_Dcm_00439*/
        /*Step1: Condition check read*/
        if((DCM_DID_CHECK_READ_FLAG == FALSE) && (TRUE == DCM_CFG_DATA_CONDITION_EN(DataRef)) \
                && ((DCM_USE_DATA_ASYNCH_FNC == DCM_CFG_DATA_USEPORT(DataRef)) \
                    || (DCM_USE_DATA_ASYNCH_FNC_ERROR == DCM_CFG_DATA_USEPORT(DataRef)) \
                    || (DCM_USE_DATA_ASYNCH_CLIENT_SERVER == DCM_CFG_DATA_USEPORT(DataRef)) \
                    || (DCM_USE_DATA_ASYNCH_CLIENT_SERVER_ERROR == DCM_CFG_DATA_USEPORT(DataRef))))
        {
            FncIndex = DCM_CFG_DATA_CONDITION_CHECK_FNC_INDEX(DataRef);
            /*return value: E_OK/E_NOT_OK/DCM_E_PENDING*/
            Result = DCM_CFG_DATA_CONDITION_CHECK_FNC_A(FncIndex)(OpStatus, pErrorCode);
        }
        else if((DCM_DID_CHECK_READ_FLAG == FALSE) && (TRUE == DCM_CFG_DATA_CONDITION_EN(DataRef)) \
                && ((DCM_USE_DATA_SYNCH_FNC == DCM_CFG_DATA_USEPORT(DataRef)) \
                    || (DCM_USE_DATA_SYNCH_CLIENT_SERVER == DCM_CFG_DATA_USEPORT(DataRef))))
        {
            FncIndex = DCM_CFG_DATA_CONDITION_CHECK_FNC_INDEX(DataRef);
            /*return value: E_OK/E_NOT_OK*/
            Result = DCM_CFG_DATA_CONDITION_CHECK_FNC_B(FncIndex)(pErrorCode);
            if(Result != E_OK)
            {
                /*In case the return value is DCM_E_PENDING*/
                Result = E_NOT_OK;
            }
        }
        else
        {
            /*Condition check read not execute,to step2*/
        }

        if((Result == E_OK) && (DCM_DID_CHECK_READ_FLAG == FALSE))
        {
            /*to step2*/
            DCM_DID_CHECK_READ_FLAG = TRUE;
        }
        else
        {
            /*send negtive response or to step2 or condition check next mainfunction*/
        }

        /*SWS_Dcm_00436*/
        /*Step2: Get the data length*/
        if((Result == E_OK) && (DCM_DID_GET_LEN_FLAG == FALSE) \
                && (DCM_UINT8_DYN == DCM_CFG_DATA_TYPE(DataRef)) \
                && ((DCM_USE_DATA_ASYNCH_FNC == DCM_CFG_DATA_USEPORT(DataRef)) \
                    || (DCM_USE_DATA_ASYNCH_FNC_ERROR == DCM_CFG_DATA_USEPORT(DataRef))\
                    || (DCM_USE_DATA_ASYNCH_CLIENT_SERVER == DCM_CFG_DATA_USEPORT(DataRef)) \
                    || (DCM_USE_DATA_ASYNCH_CLIENT_SERVER_ERROR == DCM_CFG_DATA_USEPORT(DataRef))))
        {
            FncIndex = DCM_CFG_DATA_LENGTH_FNC_INDEX(DataRef);
            /*return value: E_OK/E_NOT_OK/DCM_E_PENDING*/
            Result = DCM_CFG_DATA_LENGTH_FNC_A(FncIndex)(OpStatus, &DataLength);
        }
        else if((Result == E_OK) && (DCM_DID_GET_LEN_FLAG == FALSE) \
                && (DCM_UINT8_DYN == DCM_CFG_DATA_TYPE(DataRef)) \
                && ((DCM_USE_DATA_SYNCH_FNC == DCM_CFG_DATA_USEPORT(DataRef)) \
                    || (DCM_USE_DATA_SYNCH_CLIENT_SERVER == DCM_CFG_DATA_USEPORT(DataRef))))
        {
            FncIndex = DCM_CFG_DATA_LENGTH_FNC_INDEX(DataRef);
            /*return value: E_OK/E_NOT_OK*/
            Result = DCM_CFG_DATA_LENGTH_FNC_B(FncIndex)(&DataLength);
            if(Result != E_OK)
            {
                /*In case the return value is DCM_E_PENDING*/
                Result = E_NOT_OK;
            }
        }
        else if((Result == E_OK) && (DCM_DID_GET_LEN_FLAG == FALSE) \
                && (DCM_UINT8_DYN != DCM_CFG_DATA_TYPE(DataRef)))
        {
            DataLength = DCM_CFG_DATA_SIZE(DataRef);/*unit:bit*/
            if((DataLength % 8U) != 0U)
            {
                DataLength = (DataLength >> 3U) + 1U;
            }
            else
            {
                DataLength = (DataLength >> 3U);
            }
        }
        else
        {
            /*do nothing*/
        }
        /*compare response length with the response buffer max length*/
        if((Result == E_OK) && (DCM_DID_GET_LEN_FLAG == FALSE) \
                && ((DCM_DID_RESP_LEN + DCM_DID_DATA_LEN + DataLength) <= MaxBufferSize))
        {
            /*to step3*/
            DCM_DID_GET_LEN_FLAG = TRUE;

            DCM_DID_DATA_LEN += DataLength;
        }
        else if((Result == E_OK) && (DCM_DID_GET_LEN_FLAG == FALSE))
        {
            *pErrorCode = DCM_E_RESPONSETOOLONG;
            Result = E_NOT_OK;
        }
        else if((Result == E_NOT_OK) && (DCM_DID_GET_LEN_FLAG == FALSE))
        {
            *pErrorCode = DCM_E_CONDITIONSNOTCORRECT;
        }
        else
        {
            /*do nothing*/
        }

        /*SWS_Dcm_00437*/
        /*Step3: Read data*/
        if((Result == E_OK) \
                && ((DCM_USE_DATA_ASYNCH_FNC == DCM_CFG_DATA_USEPORT(DataRef)) \
                    || (DCM_USE_DATA_ASYNCH_CLIENT_SERVER == DCM_CFG_DATA_USEPORT(DataRef))))
        {
            FncIndex = DCM_CFG_DATA_READ_FNC_INDEX(DataRef);
            /*return value: E_OK/E_NOT_OK/DCM_E_PENDING*/
            Result = DCM_CFG_DATA_READ_FNC_A(FncIndex)(OpStatus, (DCM_DID_RESP_DATA + DataPos));
            if((Result != E_OK) && (Result != DCM_E_PENDING))
            {
                *pErrorCode = DCM_E_CONDITIONSNOTCORRECT;
                Result = E_NOT_OK;
            }
        }
        else if((Result == E_OK) \
                && ((DCM_USE_DATA_ASYNCH_FNC_ERROR == DCM_CFG_DATA_USEPORT(DataRef)) \
                    || (DCM_USE_DATA_ASYNCH_CLIENT_SERVER_ERROR == DCM_CFG_DATA_USEPORT(DataRef))))
        {
            FncIndex = DCM_CFG_DATA_READ_FNC_INDEX(DataRef);
            /*return value: E_OK/E_NOT_OK/DCM_E_PENDING*/
            Result = DCM_CFG_DATA_READ_FNC_B(FncIndex)(OpStatus, (DCM_DID_RESP_DATA + DataPos), pErrorCode);
        }
        else if((Result == E_OK) \
                && ((DCM_USE_DATA_SYNCH_FNC == DCM_CFG_DATA_USEPORT(DataRef)) \
                    || (DCM_USE_DATA_SYNCH_CLIENT_SERVER == DCM_CFG_DATA_USEPORT(DataRef))))
        {
            FncIndex = DCM_CFG_DATA_READ_FNC_INDEX(DataRef);
            /*return value: E_OK/E_NOT_OK*/
            Result = DCM_CFG_DATA_READ_FNC_C(FncIndex)((DCM_DID_RESP_DATA + DataPos));
            if(Result != E_OK)
            {
                /*In case the return value is DCM_E_PENDING*/
                *pErrorCode = DCM_E_GENERALREJECT;
                Result = E_NOT_OK;
            }
        }
#if(DCM_NVM_SUPPORT == STD_ON)
        else if((Result == E_OK) && (DCM_DID_GET_LEN_FLAG == TRUE) \
                && (DCM_NVM_READBLOCK_CALLED == FALSE) \
                && (DCM_USE_BLOCK_ID == DCM_CFG_DATA_USEPORT(DataRef)))
        {
            Result = NvM_ReadBlock(DCM_CFG_DATA_BLOCKID(DataRef), (DCM_DID_RESP_DATA + DataPos));
            if(Result == E_OK)
            {
                /*The reading process is asynchronous*/
                DCM_NVM_READBLOCK_CALLED = TRUE;
                Result = DCM_E_PENDING;
            }
            else
            {
                *pErrorCode = DCM_E_GENERALREJECT;
            }
        }
        else if((Result == E_OK) && (DCM_DID_GET_LEN_FLAG == TRUE) \
                && (DCM_NVM_READBLOCK_CALLED == TRUE) \
                && (DCM_USE_BLOCK_ID == DCM_CFG_DATA_USEPORT(DataRef)))
        {
            Result = NvM_GetErrorStatus(DCM_CFG_DATA_BLOCKID(DataRef), &NvMResult);
            if((Result == E_OK) && (NvMResult == NVM_REQ_OK))
            {
                /*continue read next signal*/
            }
            else if((Result == E_OK) && (NvMResult == NVM_REQ_PENDING))
            {
                /*Call again next mainfunction*/
                Result = DCM_E_PENDING;
            }
            else
            {
                *pErrorCode = DCM_E_GENERALREJECT;
                Result = E_NOT_OK;
            }
        }
#endif
        else
        {
            /*do nothing*/
        }

        if(Result == E_OK)/*DCM_DID_GET_LEN_FLAG must be true*/
        {
            /*continue read next signal*/
            DCM_DID_SIG_INDEX++;
            DCM_DID_CHECK_READ_FLAG = FALSE;
            DCM_DID_GET_LEN_FLAG = FALSE;
#if(DCM_NVM_SUPPORT == STD_ON)
            DCM_NVM_READBLOCK_CALLED = FALSE;
#endif
        }
        else if(Result == DCM_E_PENDING)
        {
            /*The fuction will be called again next mainfunction cycle.*/
            break;
        }
        else
        {
            /*send negative response*/
            Result = E_NOT_OK;
            break;
        }
    }/*for( ; DCM_DID_SIG_INDEX < DCM_CFG_DID_SIGNAL_NUM(DidIndex); )*/

    if((Result == E_OK) || (Result == E_NOT_OK))
    {
        DCM_DID_SIG_INDEX = DCM_DATA_CLEAR;
    }
    return Result;
}
#endif

#if(DCM_UDS_23_SERVICE == STD_ON)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name:
*
* Description:
*
* Inputs:
*
* Outputs:
*
* Return:
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
/*23 Service*//*SWS_Dcm_00492*/
FUNC(Std_ReturnType, DCM_CODE) DspInternal_23_ReadMemoryByAddress
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
)
{
    Std_ReturnType Result = E_OK;

    Dcm_SesRefType SesLevelRef;
#if(DCM_UDS_27_SERVICE == STD_ON)
    Dcm_SecRefType SecLevelRef;
    Dcm_SecRefType CurSecMask;
#endif

    uint8 AddrSizeFormat;
    uint8 AddrLength;
    uint8 SizeLength;
    uint8 i;
    uint16 j;

    if(OpStatus == DCM_INITIAL)
    {
        DCM_MEM_START_ADDR = DCM_DATA_CLEAR;
        DCM_MEM_SIZE = DCM_DATA_CLEAR;
        DCM_MEM_ID = DCM_DATA_CLEAR;
        AddrSizeFormat = (pMsgContext->reqData[DCM_INDEX_1]);
        AddrLength = (AddrSizeFormat & (0x0FU));
        SizeLength = ((AddrSizeFormat & (0xF0U)) >> 4U);
        /*SWS_Dcm_00853,Check addressAndLengthFormatIdentifier*/
        if(DCM_CFG_MEM_FORMAT_NUM != DCM_DATA_CLEAR)
        {
            Result = E_NOT_OK;
            for(i = 0U; i < DCM_CFG_MEM_FORMAT_NUM; i++)
            {
                if(AddrSizeFormat == DCM_CFG_MEM_FORMAT(i))
                {
                    Result = E_OK;
                    break;
                }
            }
        }

        if(Result == E_NOT_OK)
        {
            *pErrorCode = DCM_E_REQUESTOUTOFRANGE;
            Result = E_NOT_OK;
        }
        /*total length check*/
        else if((pMsgContext->reqDataLen) != (2U + AddrLength + SizeLength))
        {
            *pErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
            Result = E_NOT_OK;
        }
        else
        {
            /*Calculate start address*/
            for(i = 0U; i < AddrLength; i++)
            {
                DCM_MEM_START_ADDR |= (uint32)(pMsgContext->reqData[DCM_INDEX_2 + i]) << \
                                      (uint8)(8U * (AddrLength - 1U - i));
            }
            /*Calculate size*/
            for(i = 0U; i < SizeLength; i++)
            {
                DCM_MEM_SIZE |= (uint32)(pMsgContext->reqData[DCM_INDEX_2 + AddrLength + i]) << \
                                (uint8)(8U * (SizeLength - 1U - i));
            }
            /* memoryAddress and memorySize are correct? */
            if(DCM_MEM_SIZE == DCM_DATA_CLEAR)
            {
                *pErrorCode = DCM_E_REQUESTOUTOFRANGE;
                Result = E_NOT_OK;
            }
            else
            {
                /*check memory range & security & session*/
            }
        }
        /*check memory range & security & session*/
        if(Result == E_OK)
        {
            Result = E_NOT_OK;
            /*SWS_Dcm_00493*//*SWS_Dcm_01053*/
            for(i = 0U; i < DCM_CFG_MEM_ID_NUM; i++)
            {
                for(j = 0U; j < DCM_CFG_MEM_ID_READ_NUM(i); j++)
                {
                    if((DCM_MEM_START_ADDR <= DCM_CFG_MEM_ID_READ_HIGH(i, j)) \
                            && (DCM_MEM_START_ADDR >= DCM_CFG_MEM_ID_READ_LOW(i, j)) \
                            && ((DCM_MEM_START_ADDR + DCM_MEM_SIZE - 1U) <= DCM_CFG_MEM_ID_READ_HIGH(i, j)))
                    {
                        Result = E_OK;
                        break;
                    }
                }

                if(Result == E_OK)
                {
                    DCM_MEM_ID = DCM_CFG_MEM_ID_VALUE(i);
                    break;
                }
            }

            if(Result == E_NOT_OK)
            {
                *pErrorCode = DCM_E_REQUESTOUTOFRANGE;
            }
            else
            {
                /*check security & session*/
                SesLevelRef = DCM_CFG_MEM_ID_READ_SESREF(i, j);
#if(DCM_UDS_27_SERVICE == STD_ON)
                SecLevelRef = DCM_CFG_MEM_ID_READ_SECREF(i, j);
                CurSecMask = DslInternal_GetSecurityMask();;
#endif
                if(!(DCM_CFG_SESSION_MASK(DCM_SESSION_LEVEL) & SesLevelRef))
                {
                    *pErrorCode = DCM_E_REQUESTOUTOFRANGE;
                    Result = E_NOT_OK;
                }
#if(DCM_UDS_27_SERVICE == STD_ON)
                else if(!(CurSecMask & SecLevelRef))
                {
                    /*SWS_Dcm_00494*/
                    *pErrorCode = DCM_E_SECURITYACCESSDENIED;
                    Result = E_NOT_OK;
                }
#endif
                else
                {
#if(DCM_CAR_PLATFORM == DCM_GEELY_PLATFORM)
                    SetP4Timer(DCM_REQ_SERVICEINFO->P4ServerMax);
#endif
                    /*Call Dcm_ReadMemory()*/
                }
            }
        }
    }/*if(OpStatus == DCM_INITIAL)*/

    if(Result == E_OK)
    {
        /*SWS_Dcm_00495*/
        Result = DspInternal_ReadMemory(OpStatus, DCM_MEM_ID, DCM_MEM_START_ADDR, DCM_MEM_SIZE, &(pMsgContext->resData[DCM_INDEX_1]), pErrorCode);

        if(Result == E_OK)
        {
            pMsgContext->resDataLen = 1U + DCM_MEM_SIZE;
        }
    }
    return Result;
}
#endif

#if(DCM_UDS_27_SERVICE == STD_ON)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name:
*
* Description:
*
* Inputs:
*
* Outputs:
*
* Return:
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
/*27 Service*//*SWS_Dcm_00252*/
FUNC(Std_ReturnType, DCM_CODE) DspInternal_27_SecurityAccess
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
)
{
    Std_ReturnType Result = E_OK;
    uint8 SecurityRowId = 0U;
    uint8 GetSeedFncIndex = 0U;
    uint32 i;
    boolean CounterChanged = FALSE;

    if(OpStatus == DCM_INITIAL)
    {
#if(DCM_UDS_27_SUPPORT_SUPPRESSPOSRESBIT != STD_ON)
        ClearSuppressPosRespBit();
#endif
        Result = DsdInternal_CheckSubServiceId();

        if(Result == E_NOT_OK)
        {
            /*SWS_Dcm_00321*/
            *pErrorCode = DCM_E_SUBFUNCTIONNOTSUPPORTED;
        }
        else/*check Session&Security level*/
        {
            /*SWS_Dcm_00616*//*SWS_Dcm_00617*/
            Result = DspInternal_AddrSesSecCheck(pErrorCode);
        }

        if(Result == E_OK) /*check counter&format&sequence*/
        {
            SecurityRowId = (uint8)(DCM_REQ_SUBSERVICE_INDEX >> 1U);
            /********** Request Seed **********/
            if(DCM_REQ_SUBSERVICE & 0x01U)
            {
                if(pMsgContext->reqDataLen != DCM_CFG_SECURITY_ADR_SIZE(SecurityRowId) + 2U)
                {
                    *pErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
                    Result = E_NOT_OK;
                }
                else if((DCM_SECURITY_DELAY_ON_BOOT(DCM_ACTIVE_PROTOCOL_ID, SecurityRowId) != FALSE) \
                    || (DCM_SECURITY_ATTEMP_NUM(DCM_ACTIVE_PROTOCOL_ID, SecurityRowId) == DCM_DATA_CLEAR))
                {
                    *pErrorCode = DCM_E_REQUIREDTIMEDELAYNOTEXPIRED;
                    Result = E_NOT_OK;
                }
                else if((DCM_SECURITY_LEVEL == (SecurityRowId + 1U)) || (DCM_SECURITY_LEVEL == DCM_SECURITY_ALL_LEVEL))
                {
                    /*SWS_Dcm_00323*/
                    for (i = 0U; i < DCM_CFG_SECURITY_SEED_SIZE(SecurityRowId); i++)
                    {
                        pMsgContext->resData[2U + i] = 0U;
                    }
                    pMsgContext->resDataLen = DCM_CFG_SECURITY_SEED_SIZE(SecurityRowId) + 2U;
                }
                else
                {
                    GetSeedFncIndex = DCM_CFG_SECURITY_GETSEED_FNC_INDEX(SecurityRowId);
#if(DCM_UDS_27_REQUESTSEEDCONTINOUS == STD_ON)
                    if(DCM_SECURITY_SEQUENCE(DCM_ACTIVE_PROTOCOL_ID, SecurityRowId) == TRUE)
                    {
                        DCM_SECURITY_SEQUENCE(DCM_ACTIVE_PROTOCOL_ID, SecurityRowId) = FALSE;
                        DCM_SECURITY_ATTEMP_NUM(DCM_ACTIVE_PROTOCOL_ID, SecurityRowId)--;
                        CounterChanged = TRUE;
                    }
#endif
                    if(DCM_SECURITY_ATTEMP_NUM(DCM_ACTIVE_PROTOCOL_ID, SecurityRowId) == DCM_DATA_CLEAR)
                    {
                        *pErrorCode = DCM_E_REQUIREDTIMEDELAYNOTEXPIRED;
                        Result = E_NOT_OK;
                    }
                    else if(DCM_CFG_SECURITY_ADR_SIZE(SecurityRowId) != DCM_DATA_CLEAR)
                    {
                        Result = DCM_CFG_SECURITY_GETSEED_FNC_A(GetSeedFncIndex) \
                                 (
                                     &(pMsgContext->reqData[DCM_INDEX_2]),
                                     OpStatus,
                                     &(pMsgContext->resData[DCM_INDEX_2]),
                                     pErrorCode
                                 );
                        pMsgContext->resDataLen = DCM_CFG_SECURITY_SEED_SIZE(SecurityRowId) + 2U;
                    }
                    else/*(DCM_CFG_SECURITY_ADR_SIZE(SecurityRowId) == DCM_DATA_CLEAR)*/
                    {
                        Result = DCM_CFG_SECURITY_GETSEED_FNC_B(GetSeedFncIndex) \
                                 (
                                     OpStatus,
                                     &(pMsgContext->resData[DCM_INDEX_2]),
                                     pErrorCode
                                 );
                        pMsgContext->resDataLen = DCM_CFG_SECURITY_SEED_SIZE(SecurityRowId) + 2U;
                    }
                }
            }
            else/********** Receive Key **********/
            {
                if(DCM_SECURITY_SEQUENCE(DCM_ACTIVE_PROTOCOL_ID, SecurityRowId) != TRUE)
                {
                    *pErrorCode = DCM_E_REQUESTSEQUENCEERROR;
                    Result = E_NOT_OK;
                }
                else if(pMsgContext->reqDataLen != (DCM_CFG_SECURITY_KEY_SIZE(SecurityRowId) + 2U))
                {
                    DCM_SECURITY_SEQUENCE(DCM_ACTIVE_PROTOCOL_ID, SecurityRowId) = FALSE;
                    /*Decrease allowed attmept number */
                    DCM_SECURITY_ATTEMP_NUM(DCM_ACTIVE_PROTOCOL_ID, SecurityRowId)--;
                    CounterChanged = TRUE;
                    if(DCM_SECURITY_ATTEMP_NUM(DCM_ACTIVE_PROTOCOL_ID, SecurityRowId) == DCM_DATA_CLEAR)
                    {
                        *pErrorCode = DCM_E_EXCEEDNUMBEROFATTEMPTS;
                    }
                    else
                    {
                        *pErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
                    }
                    Result = E_NOT_OK;
                }
                /* Check the requested security leve has already been cracked, if so, send PosResp */
                else if(DCM_SECURITY_LEVEL == (SecurityRowId + 1U))
                {
                    pMsgContext->resDataLen = 2U;
                }
                else
                {
                    Result = DCM_CFG_SECURITY_COMPAREKEY_FNC(SecurityRowId) \
                             (
                                 &(pMsgContext->reqData[DCM_INDEX_2]),
                                 OpStatus,
                                 pErrorCode
                             );
                    pMsgContext->resDataLen = 2U;

                    if(Result == E_NOT_OK)
                    {
                        DCM_SECURITY_SEQUENCE(DCM_ACTIVE_PROTOCOL_ID, SecurityRowId) = FALSE;
                        /*If key is not valid,decrease allowed attmept number */
                        DCM_SECURITY_ATTEMP_NUM(DCM_ACTIVE_PROTOCOL_ID, SecurityRowId)--;
                        CounterChanged = TRUE;
                        if(DCM_SECURITY_ATTEMP_NUM(DCM_ACTIVE_PROTOCOL_ID, SecurityRowId) == DCM_DATA_CLEAR)
                        {
                            *pErrorCode = DCM_E_EXCEEDNUMBEROFATTEMPTS;
                        }
                        else
                        {
                            /*return Result*/
                        }
                    }
                }
            }
        }
#if(DCM_CAR_PLATFORM == DCM_GEELY_PLATFORM)
        SetP4Timer(DCM_REQ_SERVICEINFO->P4ServerMax);
#endif
    }
    else/*(OpStatus != DCM_INITIAL)*/
    {
        SecurityRowId = (uint8)(DCM_REQ_SUBSERVICE_INDEX >> 1U);
        if(DCM_REQ_SUBSERVICE & 0x01U)
        {
            GetSeedFncIndex = DCM_CFG_SECURITY_GETSEED_FNC_INDEX(SecurityRowId);
            if(DCM_CFG_SECURITY_ADR_SIZE(SecurityRowId) != DCM_DATA_CLEAR)
            {
                Result = DCM_CFG_SECURITY_GETSEED_FNC_A(GetSeedFncIndex) \
                         (
                             &(pMsgContext->reqData[DCM_INDEX_2]),
                             OpStatus,
                             &(pMsgContext->resData[DCM_INDEX_2]),
                             pErrorCode
                         );
                pMsgContext->resDataLen = DCM_CFG_SECURITY_SEED_SIZE(SecurityRowId) + 2U;
            }
            else/*(DCM_CFG_SECURITY_ADR_SIZE(SecurityRowId) == DCM_DATA_CLEAR)*/
            {
                Result = DCM_CFG_SECURITY_GETSEED_FNC_B(GetSeedFncIndex) \
                         (
                             OpStatus,
                             &(pMsgContext->resData[DCM_INDEX_2]),
                             pErrorCode
                         );
                pMsgContext->resDataLen = DCM_CFG_SECURITY_SEED_SIZE(SecurityRowId) + 2U;
            }
        }
        else
        {
            Result = DCM_CFG_SECURITY_COMPAREKEY_FNC(SecurityRowId) \
                     (
                         &(pMsgContext->reqData[DCM_INDEX_2]),
                         OpStatus,
                         pErrorCode
                     );
            pMsgContext->resDataLen = 2U;
        }

        if((Result == E_NOT_OK) && (!(DCM_REQ_SUBSERVICE & 0x01U)))
        {
            DCM_SECURITY_SEQUENCE(DCM_ACTIVE_PROTOCOL_ID, SecurityRowId) = FALSE;
            /*If key is not valid,decrease allowed attmept number */
            DCM_SECURITY_ATTEMP_NUM(DCM_ACTIVE_PROTOCOL_ID, SecurityRowId)--;
            CounterChanged = TRUE;
            if(DCM_SECURITY_ATTEMP_NUM(DCM_ACTIVE_PROTOCOL_ID, SecurityRowId) == DCM_DATA_CLEAR)
            {
                *pErrorCode = DCM_E_EXCEEDNUMBEROFATTEMPTS;
            }
        }
    }

    if(Result == E_OK)
    {
#if(DCM_UDS_27_NCR24AFTERZEROSEED == STD_ON)
        if((DCM_SECURITY_LEVEL == (SecurityRowId + 1U)) && (DCM_REQ_SUBSERVICE & 0x01U))
        {
            /* just like the client has not got the seeds */
            /*DCM_SECURITY_SEQUENCE(DCM_ACTIVE_PROTOCOL_ID, SecurityRowId) = FALSE;*/
        }
        else
#endif
            if(DCM_REQ_SUBSERVICE & 0x01U)
            {
                DCM_SECURITY_SEQUENCE(DCM_ACTIVE_PROTOCOL_ID, SecurityRowId) = TRUE;
            }
            else
            {
                if(DCM_SECURITY_ATTEMP_NUM(DCM_ACTIVE_PROTOCOL_ID, SecurityRowId) != DCM_CFG_SECURITY_ATTEMPNUM(SecurityRowId))
                {
                    DCM_SECURITY_ATTEMP_NUM(DCM_ACTIVE_PROTOCOL_ID, SecurityRowId) = DCM_CFG_SECURITY_ATTEMPNUM(SecurityRowId);
                    CounterChanged = TRUE;
                }
                DCM_SECURITY_DELAY_TIME(DCM_ACTIVE_PROTOCOL_ID, SecurityRowId) = DCM_CFG_SECURITY_DELAYTIME(SecurityRowId);
                DCM_SECURITY_SEQUENCE(DCM_ACTIVE_PROTOCOL_ID, SecurityRowId) = FALSE;
                DslInternal_SetSecurityLevel((SecurityRowId + 1U));
            }
        pMsgContext->resData[DCM_SUB_SID_INDEX] = DCM_REQ_SUBSERVICE;
    }
    else
    {
        /*return Result*/
    }

    if((CounterChanged == TRUE) && (DCM_CFG_SECURITY_ATTEMPFNC_EN(SecurityRowId) == TRUE))
    {
        (void)DCM_CFG_SECURITY_SET_ATTEMP_FNC(SecurityRowId)(OpStatus, DCM_SECURITY_ATTEMP_NUM(DCM_ACTIVE_PROTOCOL_ID, SecurityRowId));
    }
    return Result;
}
#endif

#if(DCM_UDS_28_SERVICE == STD_ON)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name:
*
* Description:
*
* Inputs:
*
* Outputs:
*
* Return:
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
/*28 Service*//*SWS_Dcm_00511*/
FUNC(Std_ReturnType, DCM_CODE) DspInternal_28_CommunicationControl
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
)
{
    Std_ReturnType Result = E_OK;

#if(DCM_UDS_28_SUPPORT_SUPPRESSPOSRESBIT != STD_ON)
    ClearSuppressPosRespBit();
#endif

    Result = DsdInternal_CheckSubServiceId();

    if(Result != E_OK)
    {
        *pErrorCode = DCM_E_SUBFUNCTIONNOTSUPPORTED;
    }
    else/*check message length*/
    {
        switch(DCM_REQ_SUBSERVICE)
        {
            case DCM_ENABLE_RX_TX:
            case DCM_ENABLE_RX_DISABLE_TX:
            case DCM_DISABLE_RX_ENABLE_TX:
            case DCM_DISABLE_RX_TX:
                if(pMsgContext->reqDataLen != DCM_28_REQ_LEN)
                {
                    *pErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
                    Result = E_NOT_OK;
                }
                break;

            case DCM_ENABLE_RX_DISABLE_TX_ENHANCED:
            case DCM_ENABLE_RX_TX_ENHANCED:
                if(pMsgContext->reqDataLen != DCM_28_REQ_LEN_ENHANCED)
                {
                    *pErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
                    Result = E_NOT_OK;
                }
                break;

            default:
                break;
        }
    }
    /*check SupportAddress&Session&Security level*/
    if(Result == E_OK)
    {
        /*SWS_Dcm_00616*//*SWS_Dcm_00617*/
        Result = DspInternal_AddrSesSecCheck(pErrorCode);
    }
    /*check Msg Type*/
    if(Result == E_OK)
    {
        DCM_COM_REQMSGTYPE = ((pMsgContext->reqData[DCM_INDEX_2]) & (0x0FU));
        if((DCM_COM_REQMSGTYPE < DCM_NORMAL_MSG) \
                || (DCM_COM_REQMSGTYPE > DCM_NM_NORMAL_MSG))
        {
            *pErrorCode = DCM_E_REQUESTOUTOFRANGE;
            Result = E_NOT_OK;
        }
        else
        {
            switch(DCM_REQ_SUBSERVICE)
            {
                case DCM_ENABLE_RX_TX:
                case DCM_ENABLE_RX_DISABLE_TX:
                case DCM_DISABLE_RX_ENABLE_TX:
                case DCM_DISABLE_RX_TX:
                    Result = DspInternal_28_Sub_Processor(OpStatus, pMsgContext, pErrorCode);
                    break;

                default:
                    Result = DspInternal_28_EnhancedSub_Processor(OpStatus, pMsgContext, pErrorCode);
                    break;
            }
        }
    }
    /*Send positive response*/
    if(Result == E_OK)
    {
        DCM_COM_REQSUBSERVICE = DCM_REQ_SUBSERVICE;
        pMsgContext->resData[DCM_SUB_SID_INDEX] = DCM_REQ_SUBSERVICE;
        pMsgContext->resDataLen = 2U;
    }
    return Result;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name:
*
* Description:
*
* Inputs:
*
* Outputs:
*
* Return:
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, DCM_CODE) DspInternal_28_Sub_Processor
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
)
{
    Std_ReturnType Result = E_OK;
    uint8 i;

    (void)OpStatus;
    DCM_COM_REQSUBNET = (((pMsgContext->reqData[DCM_INDEX_2]) & (0xF0U)) >> 4U);

    if(DCM_COM_REQSUBNET == DCM_DATA_CLEAR)
    {
        if((DCM_CFG_COM_ALLCHL_NUM == DCM_DATA_CLEAR) \
                || (DCM_CFG_COM_ALLCHL == NULL_PTR))
        {
            *pErrorCode = DCM_E_REQUESTOUTOFRANGE;
            Result = E_NOT_OK;
        }
    }
    else if(DCM_COM_REQSUBNET == (uint8)0x0F)
    {
        /*Result = E_OK;*/
    }
    else/*0<ReqSubNet<0x0F*/
    {
        if((DCM_CFG_COM_SPECHL_NUM == DCM_DATA_CLEAR) \
                || (DCM_CFG_COM_SPECHL == NULL_PTR))
        {
            *pErrorCode = DCM_E_REQUESTOUTOFRANGE;
            Result = E_NOT_OK;
        }
        else
        {
            Result = E_NOT_OK;
            for(i = 0U; i < DCM_CFG_COM_SPECHL_NUM; i++)
            {
                if((DCM_COM_REQSUBNET == DCM_CFG_COM_SPECHL_NETNUN(i)) \
                        && (TRUE == DCM_CFG_COM_SPECHL_USED(i)))
                {
                    Result = E_OK;
                    break;
                }
            }

            if(Result == E_NOT_OK)
            {
                /*SWS_Dcm_00786*/
                *pErrorCode = DCM_E_REQUESTOUTOFRANGE;
            }
        }
    }
    return Result;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name:
*
* Description:
*
* Inputs:
*
* Outputs:
*
* Return:
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, DCM_CODE) DspInternal_28_EnhancedSub_Processor
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
)
{
    Std_ReturnType Result = E_OK;
    uint16 i;

    (void)OpStatus;
    DCM_COM_REQSUBNODE = Make16Bit(pMsgContext->reqData[DCM_INDEX_3], \
                                   pMsgContext->reqData[DCM_INDEX_4]);
    if((DCM_CFG_COM_SUBNODE_NUM == DCM_DATA_CLEAR) \
            || (DCM_CFG_COM_SUBNODE == NULL_PTR))
    {
        /*SWS_Dcm_01078*//*SWS_Dcm_01080*/
        /*SWS_Dcm_01081*//*SWS_Dcm_01082*/
        *pErrorCode = DCM_E_REQUESTOUTOFRANGE;
        Result = E_NOT_OK;
    }
    else
    {
        Result = E_NOT_OK;
        for(i = 0U; i < DCM_CFG_COM_SUBNODE_NUM; i++)
        {
            if((DCM_COM_REQSUBNODE == DCM_CFG_COM_SUBNODE_ID(i)) \
                    && (TRUE == DCM_CFG_COM_SUBNODE_USED(i)))
            {
                Result = E_OK;
                break;
            }
        }

        if(Result == E_NOT_OK)
        {
            /*SWS_Dcm_01078*//*SWS_Dcm_01080*/
            /*SWS_Dcm_01081*//*SWS_Dcm_01082*/
            *pErrorCode = DCM_E_REQUESTOUTOFRANGE;
        }
    }
    return Result;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name:
*
* Description:
*
* Inputs:
*
* Outputs:
*
* Return:
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, DCM_CODE) DspInternal_28_Sub_Post
(
    void
)
{
    uint16 i;
    NetworkHandleType NetworkHandle;
    Dcm_CommunicationModeType ReqMode;

    switch(DCM_COM_REQSUBSERVICE)
    {
        case DCM_ENABLE_RX_TX:
        case DCM_ENABLE_RX_DISABLE_TX:
        case DCM_DISABLE_RX_ENABLE_TX:
        case DCM_DISABLE_RX_TX:
            ReqMode = (((DCM_COM_REQMSGTYPE << 2U) | DCM_COM_REQSUBSERVICE) - 4U);
            if(DCM_COM_REQSUBNET == DCM_DATA_CLEAR)
            {
                /*SWS_Dcm_00512*/
                for(i = 0U; i < DCM_CFG_COM_ALLCHL_NUM; i++)
                {
                    if(TRUE == DCM_CFG_COM_ALLCHL_USED(i))
                    {
                        NetworkHandle = DCM_CFG_COM_ALLCHL_REF(i);
                        (void)DCM_CFG_COM_ALLCHL_SWITCH_FNC(i)(ReqMode);
                        Dcm_Rte_CommunicationMode_CurrentState(NetworkHandle, ReqMode);
                    }
                }
            }
            else if(DCM_COM_REQSUBNET == (uint8)0x0F)
            {
                /*SWS_Dcm_00785*/
                NetworkHandle = DCM_CFG_PROTOCOL_CONNECTION_MAIN_COMM_CHN(DCM_ACTIVE_PROTOCOL_ID, \
                                DCM_ACTIVE_CONNECTION_ID);
                for(i = 0U; i < DCM_CFG_COM_ALLCHL_NUM; i++)
                {
                    if((TRUE == DCM_CFG_COM_ALLCHL_USED(i)) \
                            && (NetworkHandle == DCM_CFG_COM_ALLCHL_REF(i)))
                    {
                        (void)DCM_CFG_COM_ALLCHL_SWITCH_FNC(i)(ReqMode);
                        break;
                    }
                }
                Dcm_Rte_CommunicationMode_CurrentState(NetworkHandle, ReqMode);
            }
            else/*0<DCM_COM_REQSUBNET<0x0F*/
            {
                /*SWS_Dcm_00786*/
                for(i = 0U; i < DCM_CFG_COM_ALLCHL_NUM; i++)
                {
                    if(DCM_COM_REQSUBNET == DCM_CFG_COM_SPECHL_NETNUN(i))
                    {
                        NetworkHandle = DCM_CFG_COM_SPECHL_REF(i);
                        (void)DCM_CFG_COM_SPECHL_SWITCH_FNC(i)(ReqMode);
                        Dcm_Rte_CommunicationMode_CurrentState(NetworkHandle, ReqMode);
                        break;
                    }
                }
            }
            break;

        default:
            if(DCM_COM_REQSUBSERVICE == DCM_ENABLE_RX_TX_ENHANCED)
            {
                ReqMode = (((DCM_COM_REQMSGTYPE << 2U) | DCM_ENABLE_RX_TX) - 4U);
            }
            else
            {
                ReqMode = (((DCM_COM_REQMSGTYPE << 2U) | DCM_ENABLE_RX_DISABLE_TX) - 4U);
            }

            for(i = 0U; i < DCM_CFG_COM_SUBNODE_NUM; i++)
            {
                /*SWS_Dcm_01077*//*SWS_Dcm_01079*/
                if(DCM_COM_REQSUBNODE == DCM_CFG_COM_SUBNODE_ID(i))
                {
                    NetworkHandle = DCM_CFG_COM_SUBNODE_CHLREF(i);
                    (void)DCM_CFG_COM_SUBNODE_CHL_SWITCH_FNC(i)(ReqMode);
                    Dcm_Rte_CommunicationMode_CurrentState(NetworkHandle, ReqMode);
                    break;
                }
            }
            break;
    }
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name:
*
* Description:
*
* Inputs:
*
* Outputs:
*
* Return:
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, DCM_CODE) DspInternal_28_ResumeCommunication
(
    void
)
{
    uint16 i;
    uint8 NetworkHandle;
    Dcm_CommunicationModeType ReqMode;
    /*SWS_Dcm_00860*/
    if(((!(DCM_CFG_SESSION_MASK(DCM_SESSION_LEVEL)& DCM_COM_REQSUBSERVICE_SESSION)) \
            || (DCM_SESSION_LEVEL == DCM_DEFAULT_LEVEL)) \
            && (DCM_COM_REQSUBSERVICE != DCM_DATA_U8_MAX))
    {
        ReqMode = DCM_ENABLE_RX_TX_NORM_NM;

        switch(DCM_COM_REQSUBSERVICE)
        {
            case DCM_ENABLE_RX_TX:
            case DCM_ENABLE_RX_DISABLE_TX:
            case DCM_DISABLE_RX_ENABLE_TX:
            case DCM_DISABLE_RX_TX:
                if(DCM_COM_REQSUBNET == DCM_DATA_CLEAR)
                {
                    for(i = 0U; i < DCM_CFG_COM_ALLCHL_NUM; i++)
                    {
                        if(TRUE == DCM_CFG_COM_ALLCHL_USED(i))
                        {
                            NetworkHandle = DCM_CFG_COM_ALLCHL_REF(i);
                            (void)DCM_CFG_COM_ALLCHL_SWITCH_FNC(i)(ReqMode);
                            Dcm_Rte_CommunicationMode_CurrentState(NetworkHandle, ReqMode);
                        }
                    }
                }
                else if(DCM_COM_REQSUBNET == (uint8)0x0F)
                {
                    NetworkHandle = DCM_CFG_PROTOCOL_CONNECTION_MAIN_COMM_CHN(DCM_ACTIVE_PROTOCOL_ID, \
                                    DCM_ACTIVE_CONNECTION_ID);
                    for(i = 0U; i < DCM_CFG_COM_ALLCHL_NUM; i++)
                    {
                        if((TRUE == DCM_CFG_COM_ALLCHL_USED(i)) \
                                && (NetworkHandle == DCM_CFG_COM_ALLCHL_REF(i)))
                        {
                            (void)DCM_CFG_COM_ALLCHL_SWITCH_FNC(i)(ReqMode);
                            break;
                        }
                    }
                    Dcm_Rte_CommunicationMode_CurrentState(NetworkHandle, ReqMode);
                }
                else/*0<DCM_COM_REQSUBNET<0x0F*/
                {
                    for(i = 0U; i < DCM_CFG_COM_ALLCHL_NUM; i++)
                    {
                        if(DCM_COM_REQSUBNET == DCM_CFG_COM_SPECHL_NETNUN(i))
                        {
                            NetworkHandle = DCM_CFG_COM_SPECHL_REF(i);
                            (void)DCM_CFG_COM_SPECHL_SWITCH_FNC(i)(ReqMode);
                            Dcm_Rte_CommunicationMode_CurrentState(NetworkHandle, ReqMode);
                            break;
                        }
                    }
                }
                break;

            default:
                for(i = 0U; i < DCM_CFG_COM_SUBNODE_NUM; i++)
                {
                    if(DCM_COM_REQSUBNODE == DCM_CFG_COM_SUBNODE_ID(i))
                    {
                        NetworkHandle = DCM_CFG_COM_SUBNODE_CHLREF(i);
                        (void)DCM_CFG_COM_SUBNODE_CHL_SWITCH_FNC(i)(ReqMode);
                        Dcm_Rte_CommunicationMode_CurrentState(NetworkHandle, ReqMode);
                        break;
                    }
                }
                break;
        }
        DCM_COM_REQSUBSERVICE = DCM_ENABLE_RX_TX;
    }
}
#endif/*#if(DCM_UDS_28_SERVICE == STD_ON)*/

#if(DCM_UDS_2A_SERVICE == STD_ON)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name:
*
* Description:
*
* Inputs:
*
* Outputs:
*
* Return:
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
/*2A Service*//*SWS_Dcm_00254*/
FUNC(Std_ReturnType, DCM_CODE) DspInternal_2A_ReadDataByPeriodicIdentifier
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
)
{
    Std_ReturnType Result = E_OK;
    uint8 TransmissionMode;

    if(OpStatus == DCM_INITIAL)
    {
        DCM_DID_COUNTER = DCM_DATA_CLEAR;
        DCM_DID_POS = DCM_DATA_CLEAR;
        TransmissionMode = (pMsgContext->reqData[DCM_INDEX_1]);

        if((pMsgContext->reqDataLen - 2U) > DCM_CFG_DSP_MAX_PERIODIC_DID_READ)
        {
            /*SWS_Dcm_00843*/
            *pErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
            Result = E_NOT_OK;
        }
        else if((TransmissionMode != DCM_2A_STOPSENDING) \
                && ((pMsgContext->reqDataLen) < 3U))
        {
            /*SWS_Dcm_01093*/
            *pErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
            Result = E_NOT_OK;
        }
        else if((TransmissionMode < DCM_2A_SENDATSLOWRATE) \
                || (TransmissionMode > DCM_2A_STOPSENDING))
        {
            /*SWS_Dcm_01094*/
            *pErrorCode = DCM_E_REQUESTOUTOFRANGE;
            Result = E_NOT_OK;
        }
        else if(((TransmissionMode == DCM_2A_SENDATSLOWRATE) && (DCM_CFG_2A_SLOW_RATE == 0U)) \
                || ((TransmissionMode == DCM_2A_SENDATMEDIUMRATE) && (DCM_CFG_2A_MEDIUM_RATE == 0U)) \
                || ((TransmissionMode == DCM_2A_SENDATFASTRATE) && (DCM_CFG_2A_FAST_RATE == 0U)))
        {
            /*SWS_Dcm_01094*/
            *pErrorCode = DCM_E_REQUESTOUTOFRANGE;
            Result = E_NOT_OK;
        }
        else
        {
#if(DCM_CAR_PLATFORM == DCM_GEELY_PLATFORM)
            SetP4Timer(DCM_REQ_SERVICEINFO->P4ServerMax);
#endif
            switch(TransmissionMode)
            {
                case DCM_2A_SENDATSLOWRATE:
                case DCM_2A_SENDATMEDIUMRATE:
                case DCM_2A_SENDATFASTRATE:
                    DCM_SUBSERVICE_FNC = &(DspInternal_2A_RequestSending);
                    break;

                default:
                    DCM_SUBSERVICE_FNC = &(DspInternal_2A_StopSending);
                    break;
            }
            Result = (*DCM_SUBSERVICE_FNC)(OpStatus, pMsgContext, pErrorCode);
        }
    }/*if(OpStatus == DCM_INITIAL)*/
    else
    {
        Result = (*DCM_SUBSERVICE_FNC)(OpStatus, pMsgContext, pErrorCode);
    }

    if(Result == E_OK)
    {
        pMsgContext->resDataLen = 1U;
    }
    return Result;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name:
*
* Description:
*
* Inputs:
*
* Outputs:
*
* Return:
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, DCM_CODE) DspInternal_2A_StopSending
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
)
{
    Std_ReturnType Result = E_OK;
    uint16 i;
    uint8 j;
    uint8 ReqDid;
    /*SWS_Dcm_01100*/
    if((pMsgContext->reqData[DCM_SUB_SID_INDEX] == DCM_2A_STOPSENDING) \
            && ((pMsgContext->reqDataLen) == 2U))
    {
        DCM_PERIODIC_SCHEDULE_INDEX = DCM_DATA_CLEAR;
        DCM_PERIODIC_SCHEDULE_USEDNUM = DCM_DATA_CLEAR;
        for(i = 0U; i < DCM_CFG_DSP_MAX_PERIODIC_DID_SCHEDULER; i++)
        {
            DspInternal_2A_StopOneDid(i);
        }
    }
    else/*((pMsgContext->reqDataLen) > 2U)*/
    {
        Result = E_NOT_OK;

        for(i = 2U; i < (pMsgContext->reqDataLen); i++)
        {
            ReqDid = (pMsgContext->reqData[i]);
            for(j = 0U; j < DCM_CFG_DSP_MAX_PERIODIC_DID_SCHEDULER; j++)
            {
                if((ReqDid == DCM_PERIODIC_DID(j)) \
                        && (DCM_PERIODIC_RATE(j) != DCM_2A_STOPSENDING))
                {
                    DspInternal_2A_StopOneDid(j);
                    DCM_PERIODIC_SCHEDULE_USEDNUM--;
                    Result = E_OK;
                }
            }
        }

        if(Result == E_NOT_OK)
        {
            *pErrorCode = DCM_E_REQUESTOUTOFRANGE;
        }
    }
    return Result;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name:
*
* Description:
*
* Inputs:
*
* Outputs:
*
* Return:
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, DCM_CODE) DspInternal_2A_StopOneDid
(
    uint8 DidPos
)
{
    DCM_PERIODIC_DID(DidPos) = DCM_DATA_CLEAR;
    DCM_PERIODIC_DID_INDEX(DidPos) = DCM_DATA_CLEAR;
    DCM_PERIODIC_TIMER(DidPos) = DCM_DATA_CLEAR;
    DCM_PERIODIC_RATE(DidPos) = DCM_2A_STOPSENDING;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name:
*
* Description:
*
* Inputs:
*
* Outputs:
*
* Return:
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, DCM_CODE) DspInternal_2A_SetRateTimer
(
    uint8 ScheduleIndex
)
{
    switch(DCM_PERIODIC_RATE(ScheduleIndex))
    {
        case DCM_2A_SENDATSLOWRATE:
            DCM_PERIODIC_TIMER(ScheduleIndex) = (DCM_CFG_2A_SLOW_RATE / DCM_TASK_TIME);
            break;

        case DCM_2A_SENDATMEDIUMRATE:
            DCM_PERIODIC_TIMER(ScheduleIndex) = (DCM_CFG_2A_MEDIUM_RATE / DCM_TASK_TIME);
            break;

        case DCM_2A_SENDATFASTRATE:
            DCM_PERIODIC_TIMER(ScheduleIndex) = (DCM_CFG_2A_FAST_RATE / DCM_TASK_TIME);
            break;

        default:
            DCM_PERIODIC_TIMER(ScheduleIndex) = DCM_DATA_CLEAR;
            break;
    }
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name:
*
* Description:
*
* Inputs:
*
* Outputs:
*
* Return:
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, DCM_CODE) DspInternal_2A_RequestSending
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
)
{
    Std_ReturnType Result = E_OK;
    uint16 i;
    uint16 ReqDid;
    uint16 DidIndex;
    uint8 TransmissionMode = (pMsgContext->reqData[DCM_INDEX_1]);

    if((pMsgContext->reqDataLen - 2U + DCM_PERIODIC_SCHEDULE_USEDNUM) \
            > DCM_CFG_DSP_MAX_PERIODIC_DID_SCHEDULER)
    {
        /*SWS_Dcm_00851*/
        *pErrorCode = DCM_E_REQUESTOUTOFRANGE;
        Result = E_NOT_OK;
    }
    else
    {
        for(i = 2U; i < (pMsgContext->reqDataLen); i++)
        {
            ReqDid = Make16Bit(DCM_2A_HIGHBYTE, (pMsgContext->reqData[i]));
            Result = DspInternal_22_CheckReadDid(ReqDid, pMsgContext, pErrorCode, &DidIndex);
            if(Result == E_OK)
            {
                DCM_DID_INDEX_LIST[DCM_DID_COUNTER] = DidIndex;
                DCM_DID_COUNTER++;
            }
            else if((Result == E_NOT_OK) && (*pErrorCode != DCM_POSITIVE_RESPONSE))
            {
                break;
            }
            else
            {
                /*Continue to check the next request DID*/
            }
        }/*for(i = 2U; i < (pMsgContext->reqDataLen); i++)*/
    }

    if((Result == E_OK) && (DCM_DID_COUNTER == DCM_DATA_CLEAR))
    {
        /*SWS_Dcm_01095*//*SWS_Dcm_00721*/
        *pErrorCode = DCM_E_REQUESTOUTOFRANGE;
        Result = E_NOT_OK;
    }
    /*Put the valid Did into the Scheduler*/
    if(Result == E_OK)
    {
        for(DCM_DID_POS = 0U ; DCM_DID_POS < DCM_DID_COUNTER; DCM_DID_POS++)
        {
            Result = E_NOT_OK;
            /*Check if requested Did currently in the periodic scheduler*/
            for(i = 0U; i < DCM_CFG_DSP_MAX_PERIODIC_DID_SCHEDULER; i++)
            {
                if((DCM_PERIODIC_DID_INDEX(i) == DCM_DID_INDEX_LIST[DCM_DID_POS])
                        && (DCM_PERIODIC_RATE(i) != DCM_2A_STOPSENDING))
                {
                    DCM_PERIODIC_RATE(i) = TransmissionMode;
                    Result = E_OK;
                    break;
                }
            }
            /*Requested Did not currently in the periodic scheduler*/
            if(Result == E_NOT_OK)
            {
                for(i = 0U; i < DCM_CFG_DSP_MAX_PERIODIC_DID_SCHEDULER; i++)
                {
                    if(DCM_PERIODIC_RATE(i) == DCM_2A_STOPSENDING)
                    {
                        DCM_PERIODIC_DID(i) = ((uint8)DCM_CFG_DID_ID(DCM_DID_INDEX_LIST[DCM_DID_POS]));
                        DCM_PERIODIC_DID_INDEX(i) = DCM_DID_INDEX_LIST[DCM_DID_POS];
                        DCM_PERIODIC_RATE(i) = TransmissionMode;
                        DCM_PERIODIC_SCHEDULE_USEDNUM++;
                        Result = E_OK;
                        break;
                    }
                }
            }
            /*Set the periodic timer*/
            if(Result == E_OK)
            {
                DspInternal_2A_SetRateTimer(i);
            }
            else
            {
                *pErrorCode = DCM_E_REQUESTOUTOFRANGE;
                break;
            }
        }
    }
    return Result;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name:
*
* Description:
*
* Inputs:
*
* Outputs:
*
* Return:
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, DCM_CODE) DspInternal_2A_PeriodicTransmission
(
    void
)
{
    uint8 i;
    uint8 ScheduleStartIndex;
    uint16 DidIndex;
    PduIdType DcmTxPduId;
    PduInfoType PduInfo;
    boolean TransmitFlag;
    Dcm_NegativeResponseCodeType ErrorCode = DCM_POSITIVE_RESPONSE;

    /*Manage the rate timer*/
    for(i = 0U; i < DCM_CFG_DSP_MAX_PERIODIC_DID_SCHEDULER; i++)
    {
        if((DCM_PERIODIC_RATE(i) != DCM_2A_STOPSENDING) \
                && (DCM_PERIODIC_TIMER(i) != DCM_DATA_CLEAR))
        {
            DCM_PERIODIC_TIMER(i)--;
        }
    }
    /*Transmit periodic pdu*/
    if((NULL_PTR != DCM_CFG_PROTOCOL_CONNECTION_PERIODIC(0U, 0U)) \
            && (DCM_CFG_PROTOCOL_CONNECTION_PERIODIC_NUM(0U, 0U) != DCM_DATA_CLEAR))
    {
        if((DCM_CURRENT_DID_SERVICE == DCM_DATA_CLEAR) \
                || (DCM_CURRENT_DID_SERVICE == DCM_2A_SERVICE))
        {
            DCM_CURRENT_DID_SERVICE = DCM_UDS_2A_SERVICE;
            ScheduleStartIndex = DCM_PERIODIC_SCHEDULE_INDEX;
            for(i = 0U; i < DCM_CFG_PROTOCOL_CONNECTION_PERIODIC_NUM(0U, 0U); i++)
            {
                do
                {
                    TransmitFlag = FALSE;
                    /*SWS_Dcm_01113*//*SWS_Dcm_01114*//*SWS_Dcm_01117*/
                    if((DCM_PERIODIC_RATE(DCM_PERIODIC_SCHEDULE_INDEX) != DCM_2A_STOPSENDING) \
                            && (DCM_PERIODIC_TIMER(DCM_PERIODIC_SCHEDULE_INDEX) == DCM_DATA_CLEAR))
                    {
                        TransmitFlag = TRUE;
                        /*SWS_Dcm_01102*/
                        DspInternal_2A_SetRateTimer(DCM_PERIODIC_SCHEDULE_INDEX);
                        DidIndex = DCM_PERIODIC_DID_INDEX(DCM_PERIODIC_SCHEDULE_INDEX);
                        DCM_DID_RESP_LEN = DCM_DATA_CLEAR;
                        DCM_DID_DATA_LEN = 2U;
                        DCM_DID_RESP_DATA = DCM_PERIODIC_BUFFER(DCM_PERIODIC_SCHEDULE_INDEX);
                        DCM_DID_RESP_DATA[DCM_INDEX_1] = DCM_PERIODIC_DID(DCM_PERIODIC_SCHEDULE_INDEX);
                        DCM_DID_RESP_DATA += DCM_DID_DATA_LEN;
#if(DCM_UDS_2C_SERVICE == STD_ON)
                        if((TRUE == DCM_CFG_DID_INFO_DYN_DEF(DidIndex)) \
                                && (TRUE == DCM_DDDID_DEFINED(DCM_CFG_DID_INFO_DDDID_BUF_INDEX(DidIndex))))
                        {
                            /*Max length of IF-PDUs is 8U for Can,and 64U for CanFD.*/
                            (void)DspInternal_DDDidReadAllRefData(DidIndex, DCM_PERIODIC_BUFFER_LEN, \
                                                                  DCM_INITIAL, &ErrorCode);
                        }
                        else if(TRUE == DCM_CFG_DID_INFO_DYN_DEF(DidIndex))
                        {
                            TransmitFlag = FALSE;
                            DspInternal_2A_StopOneDid(DCM_PERIODIC_SCHEDULE_INDEX);
                        }
                        else
#endif
                        {
                            (void)DspInternal_DidReadAllRefData(DidIndex, DCM_PERIODIC_BUFFER_LEN, \
                                                                DCM_INITIAL, &ErrorCode);
                        }

                        if(TransmitFlag == TRUE)
                        {
                            /*SWS_Dcm_01105*//*Transmit IF-PDU*/
                            PduInfo.SduDataPtr = &(DCM_PERIODIC_BUFFER(DCM_PERIODIC_SCHEDULE_INDEX)[DCM_INDEX_1]);
                            PduInfo.SduLength = (DCM_DID_DATA_LEN - 1U);
                            DcmTxPduId = DCM_CFG_PROTOCOL_CONNECTION_PERIODIC_TX_PDUID(0U, 0U, i);
                            /*SWS_Dcm_01118*/
                            (void)DcmTransmit(DcmTxPduId, &PduInfo);
                        }
                    }
                    else
                    {
                        /*do nothing*/
                    }
                    DCM_PERIODIC_SCHEDULE_INDEX++;

                    if(DCM_PERIODIC_SCHEDULE_INDEX >= DCM_CFG_DSP_MAX_PERIODIC_DID_SCHEDULER)
                    {
                        DCM_PERIODIC_SCHEDULE_INDEX = DCM_DATA_CLEAR;
                    }
                }
                while((TransmitFlag == FALSE) && (ScheduleStartIndex != DCM_PERIODIC_SCHEDULE_INDEX));

                if(ScheduleStartIndex == DCM_PERIODIC_SCHEDULE_INDEX)
                {
                    break;
                }
            }
            DCM_CURRENT_DID_SERVICE = DCM_DATA_CLEAR;
        }
    }
    else
    {
        if(DCM_STATE == DCM_IDLE)
        {
            /*SWS_Dcm_01103*/
            SetDcmState(DCM_PERIODIC_TX);
            ScheduleStartIndex = DCM_PERIODIC_SCHEDULE_INDEX;
            do
            {
                TransmitFlag = FALSE;
                /*SWS_Dcm_01113*//*SWS_Dcm_01114*//*SWS_Dcm_01117*/
                if((DCM_PERIODIC_RATE(DCM_PERIODIC_SCHEDULE_INDEX) != DCM_2A_STOPSENDING) \
                        && (DCM_PERIODIC_TIMER(DCM_PERIODIC_SCHEDULE_INDEX) == DCM_DATA_CLEAR))
                {
                    TransmitFlag = TRUE;
                    /*SWS_Dcm_01102*/
                    DspInternal_2A_SetRateTimer(DCM_PERIODIC_SCHEDULE_INDEX);
                    DidIndex = DCM_PERIODIC_DID_INDEX(DCM_PERIODIC_SCHEDULE_INDEX);
                    DCM_DID_RESP_LEN = DCM_DATA_CLEAR;
                    DCM_DID_DATA_LEN = 2U;
                    DCM_DID_RESP_DATA = DCM_PERIODIC_BUFFER(DCM_PERIODIC_SCHEDULE_INDEX);
                    DCM_DID_RESP_DATA[DCM_INDEX_1] = DCM_PERIODIC_DID(DCM_PERIODIC_SCHEDULE_INDEX);
                    DCM_DID_RESP_DATA += DCM_DID_DATA_LEN;
#if(DCM_UDS_2C_SERVICE == STD_ON)
                    if((TRUE == DCM_CFG_DID_INFO_DYN_DEF(DidIndex)) \
                            && (TRUE == DCM_DDDID_DEFINED(DCM_CFG_DID_INFO_DDDID_BUF_INDEX(DidIndex))))
                    {
                        /*Max length of IF-PDUs is 8U for Can,and 64U for CanFD.*/
                        (void)DspInternal_DDDidReadAllRefData(DidIndex, DCM_PERIODIC_BUFFER_LEN, \
                                                              DCM_INITIAL, &ErrorCode);
                    }
                    else if(TRUE == DCM_CFG_DID_INFO_DYN_DEF(DidIndex))
                    {
                        TransmitFlag = FALSE;
                        DspInternal_2A_StopOneDid(DCM_PERIODIC_SCHEDULE_INDEX);
                    }
                    else
#endif
                    {
                        (void)DspInternal_DidReadAllRefData(DidIndex, DCM_PERIODIC_BUFFER_LEN, \
                                                            DCM_INITIAL, &ErrorCode);
                    }
                    if(TransmitFlag == TRUE)
                    {
                        /*SWS_Dcm_01105*//*Transmit IF-PDU*/
                        DCM_MSGCONTEXT.resData = &(DCM_PERIODIC_BUFFER(DCM_PERIODIC_SCHEDULE_INDEX)[DCM_INDEX_1]);
                        DCM_MSGCONTEXT.resDataLen = (DCM_DID_DATA_LEN - 1U);
                        DCM_MSGCONTEXT.CopyDataIndex = DCM_DATA_CLEAR;
                        PduInfo.SduDataPtr = DCM_MSGCONTEXT.resData;
                        PduInfo.SduLength  = (uint16)(DCM_MSGCONTEXT.resDataLen);
                        DcmTxPduId = DCM_CFG_PROTOCOL_CONNECTION_MAIN_TX_PDUID(DCM_ACTIVE_PROTOCOL_ID, \
                                     DCM_ACTIVE_CONNECTION_ID);
                        /*SWS_Dcm_01118*/
                        (void)DcmTransmit(DcmTxPduId, &PduInfo);
                    }
                }
                else
                {
                    /*do nothing*/
                }
                DCM_PERIODIC_SCHEDULE_INDEX++;

                if(DCM_PERIODIC_SCHEDULE_INDEX >= DCM_CFG_DSP_MAX_PERIODIC_DID_SCHEDULER)
                {
                    DCM_PERIODIC_SCHEDULE_INDEX = DCM_DATA_CLEAR;
                }
            }
            while((TransmitFlag == FALSE) && (ScheduleStartIndex != DCM_PERIODIC_SCHEDULE_INDEX));

            if(TransmitFlag == FALSE)
            {
                ResetDcmState();
            }
        }
    }
}
#endif

#if(DCM_UDS_2C_SERVICE == STD_ON)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name:
*
* Description:
*
* Inputs:
*
* Outputs:
*
* Return:
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
/*2C Service*//*SWS_Dcm_00259*/
FUNC(Std_ReturnType, DCM_CODE) DspInternal_2C_DynamicallyDefineDataIdentifier
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
)
{
    Std_ReturnType Result = E_OK;

    if(OpStatus == DCM_INITIAL)
    {
#if(DCM_UDS_2C_SUPPORT_SUPPRESSPOSRESBIT != STD_ON)
        ClearSuppressPosRespBit();
#endif
        Result = DsdInternal_CheckSubServiceId();

        if(Result != E_OK)
        {
            *pErrorCode = DCM_E_SUBFUNCTIONNOTSUPPORTED;
        }
        else if((DCM_REQ_SUBSERVICE == DCM_2C_BY_IDENTIFIER) \
                && (((pMsgContext->reqDataLen) < DCM_2C_01_MIN_REQ_LEN) \
                    || ((pMsgContext->reqDataLen) % 4U != 0U)))
        {
            *pErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
            Result = E_NOT_OK;
        }
        else if((DCM_REQ_SUBSERVICE == DCM_2C_BY_MEMORYADDR) \
                && ((pMsgContext->reqDataLen) < DCM_2C_02_MIN_REQ_LEN))
        {
            *pErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
            Result = E_NOT_OK;
        }
        else if((DCM_REQ_SUBSERVICE == DCM_2C_CLEAR_DDDID) \
                && ((pMsgContext->reqDataLen) % 2U != 0U))
        {
            *pErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
            Result = E_NOT_OK;
        }
        else
        {
            Result = DspInternal_AddrSesSecCheck(pErrorCode);

            if(Result == E_OK)
            {
#if(DCM_CAR_PLATFORM == DCM_GEELY_PLATFORM)
                SetP4Timer(DCM_REQ_SERVICEINFO->P4ServerMax);
#endif
                switch(DCM_REQ_SUBSERVICE)
                {
                    case DCM_2C_BY_IDENTIFIER:
                        DCM_SUBSERVICE_FNC = &(DspInternal_2C_01_Processor);
                        break;

                    case DCM_2C_BY_MEMORYADDR:
                        DCM_SUBSERVICE_FNC = &(DspInternal_2C_02_Processor);
                        break;

                    default:
                        DCM_SUBSERVICE_FNC = &(DspInternal_2C_03_Processor);
                        break;
                }
                Result = (*DCM_SUBSERVICE_FNC)(OpStatus, pMsgContext, pErrorCode);
            }
        }
    }
    else
    {
        Result = (*DCM_SUBSERVICE_FNC)(OpStatus, pMsgContext, pErrorCode);
    }

    if((Result == E_OK) && ((pMsgContext->reqDataLen) > DCM_2C_03_MIN_REQ_LEN))
    {
        pMsgContext->resData[DCM_SUB_SID_INDEX] = DCM_REQ_SUBSERVICE;
        pMsgContext->resData[DCM_INDEX_2] = pMsgContext->reqData[DCM_INDEX_2];
        pMsgContext->resData[DCM_INDEX_3] = pMsgContext->reqData[DCM_INDEX_3];
        pMsgContext->resDataLen = 4U;
    }
    else if(Result == E_OK)
    {
        pMsgContext->resData[DCM_SUB_SID_INDEX] = DCM_REQ_SUBSERVICE;
        pMsgContext->resDataLen = 2U;
    }
    else
    {
        /*Result = E_NOT_OK/DCM_E_PENDING*/
    }
    return Result;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DspInternal_2C_CheckDDDID
*
* Description:
*
* Inputs:
*
* Outputs:
*
* Return:
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, DCM_CODE) DspInternal_2C_CheckDDDID
(
    P2VAR(uint16, AUTOMATIC, DCM_VAR) DDDidPos,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
)
{
    Std_ReturnType Result = E_NOT_OK;
    uint16 i;
    uint16 DDDid;
    uint8 ReqElements;
    uint8 RemainElements;
    uint8 SupportAddress;
    Dcm_SesRefType SesLevelRef;
#if(DCM_UDS_27_SERVICE == STD_ON)
    Dcm_SecRefType SecLevelRef;
    Dcm_SecRefType CurSecMask;
#endif


    DDDid = Make16Bit(pMsgContext->reqData[DCM_INDEX_2], pMsgContext->reqData[DCM_INDEX_3]);
    for(i = 0U; i < DCM_CFG_DDDID_NUM; i++)
    {
        if((DDDid == DCM_CFG_DID_ID(DCM_DDDID_INDEX(i))) \
                && (TRUE == DCM_CFG_DID_USED(DCM_DDDID_INDEX(i))))
        {
            *DDDidPos = i;
            ReqElements = (((pMsgContext->reqDataLen) / 4U) - 1U);
            RemainElements = (DCM_CFG_DID_INFO_DDDID_MAX_ELE(DCM_DDDID_INDEX(i)) - \
                              DCM_DDDID_ELE_USED_NUM(i));
            Result = E_OK;
            break;
        }
    }

    if(Result == E_NOT_OK)
    {
        *pErrorCode = DCM_E_REQUESTOUTOFRANGE;
    }
    else
    {
        if(ReqElements > RemainElements)
        {
            /*SWS_Dcm_00861*/
            *pErrorCode = DCM_E_REQUESTOUTOFRANGE;
            Result = E_NOT_OK;
        }
    }
    /*Check Address,Session and Security of DDDID*/
    if(Result == E_OK)
    {
        SupportAddress = (DCM_CFG_DID_INFO_READ((DCM_DDDID_INDEX(i)))->DcmDspDidReadSupportAddress);
        SesLevelRef = (DCM_CFG_DID_INFO_READ((DCM_DDDID_INDEX(i)))->DcmDspDidReadSessionRef);
#if(DCM_UDS_27_SERVICE == STD_ON)
        CurSecMask = DslInternal_GetSecurityMask();
        SecLevelRef = (DCM_CFG_DID_INFO_READ((DCM_DDDID_INDEX(i)))->DcmDspDidReadSecurityLevelRef);
#endif
        if(!(SupportAddress & (((uint8)0x01) << (pMsgContext->msgAddInfo.reqType))))
        {
            *pErrorCode = DCM_E_REQUESTOUTOFRANGE;
            Result = E_NOT_OK;
        }
        else if(!(DCM_CFG_SESSION_MASK(DCM_SESSION_LEVEL) & SesLevelRef))
        {
            /*SWS_Dcm_00723*/
            *pErrorCode = DCM_E_REQUESTOUTOFRANGE;
            Result = E_NOT_OK;
        }
#if(DCM_UDS_27_SERVICE == STD_ON)
        else if(!(CurSecMask & SecLevelRef))
        {
            /*SWS_Dcm_00724*/
            *pErrorCode = DCM_E_SECURITYACCESSDENIED;
            Result = E_NOT_OK;
        }
#endif
        else
        {
            /*do nothing*/
        }
    }
    return Result;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name:
*
* Description:
*
* Inputs:
*
* Outputs:
*
* Return:
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, DCM_CODE) DspInternal_2C_01_Processor
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
)
{
    Std_ReturnType Result = E_OK;
    uint16 DDDidPos;
    uint16 i;
    uint16 j;
    uint16 k;
    uint16 SourceDid;
    uint16 DataPos;
    uint16 DataRef;
    uint8 DataSize;
    uint8 SupportAddress;
    Dcm_SesRefType SesLevelRef;
#if(DCM_UDS_27_SERVICE == STD_ON)
    Dcm_SecRefType SecLevelRef;
    Dcm_SecRefType CurSecMask;
#endif

    Result = DspInternal_2C_CheckDDDID(&DDDidPos, pMsgContext, pErrorCode);
    /*Check ID,DataPosition,Address,Session and Security of Source DID*/
    if(Result == E_OK)
    {
        for(i = 4U; i < (pMsgContext->reqDataLen); i += 4U)
        {
            SourceDid = Make16Bit(pMsgContext->reqData[i], pMsgContext->reqData[i + 1U]);
            DataPos = (pMsgContext->reqData[i + 2U]);
            if(DataPos == DCM_DATA_CLEAR)
            {
                *pErrorCode = DCM_E_REQUESTOUTOFRANGE;
                Result = E_NOT_OK;
                break;
            }
            /*Converte byte position in request message to bit position*/
            DataPos = ((DataPos - 1U) * 8U);
            /*unit:byte*/
            DataSize = (pMsgContext->reqData[i + 3U]);
            for(j = 0U; j < DCM_CFG_DID_NUM; j++)
            {
                if((SourceDid == DCM_CFG_DID_ID(j)) \
                        && (TRUE == DCM_CFG_DID_USED(j)) \
                        && (NULL_PTR != DCM_CFG_DID_INFO_READ(j)))
                {
                    /* Check address&session&security of Source DID*/
                    SupportAddress = (DCM_CFG_DID_INFO_READ(j)->DcmDspDidReadSupportAddress);
                    SesLevelRef = (DCM_CFG_DID_INFO_READ(j)->DcmDspDidReadSessionRef);
#if(DCM_UDS_27_SERVICE == STD_ON)
                    CurSecMask = DslInternal_GetSecurityMask();
                    SecLevelRef = (DCM_CFG_DID_INFO_READ(j)->DcmDspDidReadSecurityLevelRef);
#endif
                    if(!(SupportAddress & (((uint8)0x01) << (pMsgContext->msgAddInfo.reqType))))
                    {
                        i = (pMsgContext->reqDataLen);
                        j = DCM_CFG_DID_NUM;
                        *pErrorCode = DCM_E_REQUESTOUTOFRANGE;
                        Result = E_NOT_OK;
                    }
                    else if(!(DCM_CFG_SESSION_MASK(DCM_SESSION_LEVEL) & SesLevelRef))
                    {
                        /*SWS_Dcm_00725*/
                        i = (pMsgContext->reqDataLen);
                        j = DCM_CFG_DID_NUM;
                        *pErrorCode = DCM_E_REQUESTOUTOFRANGE;
                        Result = E_NOT_OK;
                    }
#if(DCM_UDS_27_SERVICE == STD_ON)
                    else if(!(CurSecMask & SecLevelRef))
                    {
                        /*SWS_Dcm_00726*/
                        i = (pMsgContext->reqDataLen);
                        j = DCM_CFG_DID_NUM;
                        *pErrorCode = DCM_E_SECURITYACCESSDENIED;
                        Result = E_NOT_OK;
                    }
#endif
                    else
                    {
                        Result = E_NOT_OK;
                        /*Check data position and data size*/
                        for(k = 0U; k < DCM_CFG_DID_SIGNAL_NUM(j); k++)
                        {
                            DataRef = DCM_CFG_DID_SIGNAL(j)[k].DcmDspDidDataRef;
                            if((DataPos == (DCM_CFG_DID_SIGNAL(j)[k].DcmDspDidDataPos)) \
                                    && ((DataSize * 8U) == DCM_CFG_DATA_SIZE(DataRef)))
                            {
                                /*SWS_Dcm_00646*/
                                DCM_DDDID_ELE_SDID_INDEX(DDDidPos, DCM_DDDID_ELE_USED_NUM(DDDidPos)) = j;
                                DCM_DDDID_ELE_SDID_POS(DDDidPos, DCM_DDDID_ELE_USED_NUM(DDDidPos)) = DataPos;
                                DCM_DDDID_ELE_DATA_INDEX(DDDidPos, DCM_DDDID_ELE_USED_NUM(DDDidPos)) = DataRef;
                                DCM_DDDID_ELE_DATA_SIZE(DDDidPos, DCM_DDDID_ELE_USED_NUM(DDDidPos)) = DataSize;
                                DCM_DDDID_ELE_USED_NUM(DDDidPos)++;
                                DCM_DDDID_DEFINED(DDDidPos) = TRUE;
                                Result = E_OK;
                                break;
                            }
                        }

                        if(Result == E_NOT_OK)
                        {
                            i = (pMsgContext->reqDataLen);
                            j = DCM_CFG_DID_NUM;
                            DspInternal_2C_ClearOneDDDID(DDDidPos);
                            *pErrorCode = DCM_E_REQUESTOUTOFRANGE;
                            Result = E_NOT_OK;
                        }
                    }
                }
            }/*for(j = 0U; j < DCM_CFG_DID_NUM; j++)*/
        }/*for(i = 4U; i < (pMsgContext->reqDataLen); i += 4U)*/
    }
    return Result;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name:
*
* Description:
*
* Inputs:
*
* Outputs:
*
* Return:
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, DCM_CODE) DspInternal_2C_02_Processor
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
)
{
    Std_ReturnType Result = E_OK;
    uint16 DDDidPos;
    uint16 i;
    uint16 j;
    uint16 k;

    uint8 AddrSizeFormat;
    uint8 AddrLength;
    uint8 SizeLength;
    Dcm_SesRefType SesLevelRef;
#if(DCM_UDS_27_SERVICE == STD_ON)
    Dcm_SecRefType SecLevelRef;
    Dcm_SecRefType CurSecMask;
#endif

    Result = DspInternal_2C_CheckDDDID(&DDDidPos, pMsgContext, pErrorCode);
    /*Check Memory address&length format of Source Memory*/
    if(Result == E_OK)
    {
        DCM_MEM_START_ADDR = DCM_DATA_CLEAR;
        DCM_MEM_SIZE = DCM_DATA_CLEAR;
        DCM_MEM_ID = DCM_DATA_CLEAR;
        AddrSizeFormat = (pMsgContext->reqData[DCM_INDEX_4]);
        AddrLength = (AddrSizeFormat & (0x0FU));
        SizeLength = ((AddrSizeFormat & (0xF0U)) >> 4U);
        /*Check addressAndLengthFormatIdentifier*/
        if(DCM_CFG_MEM_FORMAT_NUM != DCM_DATA_CLEAR)
        {
            Result = E_NOT_OK;
            for(i = 0U; i < DCM_CFG_MEM_FORMAT_NUM; i++)
            {
                if(AddrSizeFormat == DCM_CFG_MEM_FORMAT(i))
                {
                    Result = E_OK;
                    break;
                }
            }
        }

        if(Result == E_NOT_OK)
        {
            /*SWS_Dcm_00854*/
            *pErrorCode = DCM_E_REQUESTOUTOFRANGE;
        }
        /*Check length*/
        else if(!((pMsgContext->reqDataLen - 5U) % (AddrLength + SizeLength)))
        {
            *pErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
            Result = E_NOT_OK;
        }
        else
        {
            /*Check Memory*/
        }
    }
    /*Check MemoryAddress,MemorySize,Address,Session and Security of Source Memory*/
    if(Result == E_OK)
    {
        for(i = 5U; i < (pMsgContext->reqDataLen); i += (AddrLength + SizeLength))
        {
            /*Calculate start address*/
            for(j = 0U; j < AddrLength; j++)
            {
                DCM_MEM_START_ADDR |= (uint32)(pMsgContext->reqData[i + j]) << \
                                      (uint8)(8U * (AddrLength - 1U - j));
            }
            /*Calculate size*/
            for(j = 0U; j < SizeLength; j++)
            {
                DCM_MEM_SIZE |= (uint32)(pMsgContext->reqData[i + AddrLength + j]) << \
                                (uint8)(8U * (SizeLength - 1U - j));
            }
            /* memoryAddress and memorySize are correct? */
            if(DCM_MEM_SIZE == DCM_DATA_CLEAR)
            {
                i = (pMsgContext->reqDataLen);
                *pErrorCode = DCM_E_REQUESTOUTOFRANGE;
                Result = E_NOT_OK;
            }
            else
            {
                /*check memory range*/
                Result = E_NOT_OK;
                for(j = 0U; j < DCM_CFG_MEM_ID_NUM; j++)
                {
                    for(k = 0U; k < DCM_CFG_MEM_ID_READ_NUM(j); k++)
                    {
                        if((DCM_MEM_START_ADDR <= DCM_CFG_MEM_ID_READ_HIGH(j, k)) \
                                && (DCM_MEM_START_ADDR >= DCM_CFG_MEM_ID_READ_LOW(j, k)) \
                                && ((DCM_MEM_START_ADDR + DCM_MEM_SIZE - 1U) <= DCM_CFG_MEM_ID_READ_HIGH(j, k)))
                        {
                            Result = E_OK;
                            break;
                        }
                    }

                    if(Result == E_OK)
                    {
                        DCM_MEM_ID = DCM_CFG_MEM_ID_VALUE(j);
                        break;
                    }
                }/*for(j = 0U; j < DCM_CFG_MEM_ID_NUM; j++)*/

                if(Result == E_NOT_OK)
                {
                    /*SWS_Dcm_01051*/
                    i = (pMsgContext->reqDataLen);
                    *pErrorCode = DCM_E_REQUESTOUTOFRANGE;
                    Result = E_NOT_OK;
                }
            }
            /*check security & session*/
            if(Result == E_OK)
            {
                /*check security & session*/
                SesLevelRef = DCM_CFG_MEM_ID_READ_SESREF(j, k);
#if(DCM_UDS_27_SERVICE == STD_ON)
                SecLevelRef = DCM_CFG_MEM_ID_READ_SECREF(j, k);
                CurSecMask = DslInternal_GetSecurityMask();
#endif
                if(!(DCM_CFG_SESSION_MASK(DCM_SESSION_LEVEL) & SesLevelRef))
                {
                    /*SWS_Dcm_00725*/
                    *pErrorCode = DCM_E_REQUESTOUTOFRANGE;
                    Result = E_NOT_OK;
                }
                else if(!(CurSecMask & SecLevelRef))
                {
                    /*SWS_Dcm_00726*/
                    *pErrorCode = DCM_E_SECURITYACCESSDENIED;
                    Result = E_NOT_OK;
                }
                else
                {
                    /*SWS_Dcm_00646*/
                    DCM_DDDID_ELE_MEM_ID(DDDidPos, DCM_DDDID_ELE_USED_NUM(DDDidPos)) = DCM_MEM_ID;
                    DCM_DDDID_ELE_MEM_ADDR(DDDidPos, DCM_DDDID_ELE_USED_NUM(DDDidPos)) = DCM_MEM_START_ADDR;
                    DCM_DDDID_ELE_DATA_SIZE(DDDidPos, DCM_DDDID_ELE_USED_NUM(DDDidPos)) = DCM_MEM_SIZE;
                    DCM_DDDID_ELE_USED_NUM(DDDidPos)++;
                    DCM_DDDID_DEFINED(DDDidPos) = TRUE;
                    Result = E_OK;
                    break;
                }
            }
            else
            {
                i = (pMsgContext->reqDataLen);
                DspInternal_2C_ClearOneDDDID(DDDidPos);
                *pErrorCode = DCM_E_REQUESTOUTOFRANGE;
                Result = E_NOT_OK;
            }
        }/*for(i = 5U; i < (pMsgContext->reqDataLen); i += (AddrLength + SizeLength))*/
    }
    return Result;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name:
*
* Description:
*
* Inputs:
*
* Outputs:
*
* Return:
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, DCM_CODE) DspInternal_2C_03_Processor
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
)
{
    /*SWS_Dcm_00647*/
    Std_ReturnType Result = E_NOT_OK;
    uint16 i;
    uint16 DDDid;

    if((pMsgContext->reqDataLen) == DCM_2C_03_MIN_REQ_LEN)
    {
        for(i = 0U; i < DCM_CFG_DDDID_NUM; i++)
        {
            DspInternal_2C_ClearOneDDDID(i);
        }
        Result = E_OK;
    }
    else/*((pMsgContext->reqDataLen) > DCM_2C_03_MIN_REQ_LEN)*/
    {
        DDDid = Make16Bit(pMsgContext->reqData[DCM_INDEX_2], pMsgContext->reqData[DCM_INDEX_3]);
        for(i = 0U; i < DCM_CFG_DDDID_NUM; i++)
        {
            if((DDDid == DCM_CFG_DID_ID(DCM_DDDID_INDEX(i))) \
                    && (TRUE == DCM_DDDID_DEFINED(i)))
            {
                DspInternal_2C_ClearOneDDDID(i);
                Result = E_OK;
                break;
            }
        }
    }

    if(Result == E_NOT_OK)
    {
        *pErrorCode = DCM_E_REQUESTOUTOFRANGE;
    }
    return Result;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name:
*
* Description:
*
* Inputs:
*
* Outputs:
*
* Return:
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, DCM_CODE) DspInternal_2C_ClearOneDDDID
(
    uint16 DDDIDBufferIndex
)
{
    uint16 i;

    DCM_DDDID_DEFINED(DDDIDBufferIndex) = FALSE;
    DCM_DDDID_ELE_USED_NUM(DDDIDBufferIndex) = DCM_DATA_CLEAR;
    for(i = 0U; i < DCM_CFG_DID_INFO_DDDID_MAX_ELE(DCM_DDDID_INDEX(DDDIDBufferIndex)); i++)
    {
        DCM_DDDID_ELE_SDID_INDEX(DDDIDBufferIndex, i) = DCM_INVALID_DID;
        DCM_DDDID_ELE_SDID_POS(DDDIDBufferIndex, i) = DCM_DATA_CLEAR;
        DCM_DDDID_ELE_DATA_INDEX(DDDIDBufferIndex, i) = DCM_DATA_CLEAR;
        DCM_DDDID_ELE_MEM_ID(DDDIDBufferIndex, i) = DCM_INVALID_MEMORY_ID;
        DCM_DDDID_ELE_MEM_ADDR(DDDIDBufferIndex, i) = DCM_DATA_CLEAR;
        DCM_DDDID_ELE_DATA_SIZE(DDDIDBufferIndex, i) = DCM_DATA_CLEAR;
    }
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name:
*
* Description:
*
* Inputs:
*
* Outputs:
*
* Return:
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, DCM_CODE) DspInternal_DDDidReadAllRefData
(
    uint16 DidIndex,
    uint32 MaxBufferSize,
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
)
{
    Std_ReturnType Result = E_OK;
    uint16 BufferIndex;
    uint16 DataRef;
#if(DCM_NVM_SUPPORT == STD_ON)
    NvM_RequestResultType NvMResult = NVM_REQ_OK;
#endif
    uint16 FncIndex;

    BufferIndex = DCM_CFG_DID_INFO_DDDID_BUF_INDEX(DidIndex);

    /*read all reference data*/
    for( ; DCM_DID_SIG_INDEX < DCM_CFG_DID_INFO_DDDID_MAX_ELE(DidIndex); )
    {
        if(DCM_INVALID_DID != DCM_DDDID_ELE_SDID_INDEX(BufferIndex, DCM_DID_SIG_INDEX))
        {
            /*Read DcmDspData*/
            DataRef = DCM_DDDID_ELE_DATA_INDEX(BufferIndex, DCM_DID_SIG_INDEX);
            /*Step1: Condition check read*/
            if((DCM_DID_CHECK_READ_FLAG == FALSE) && (TRUE == DCM_CFG_DATA_CONDITION_EN(DataRef)) \
                    && ((DCM_USE_DATA_ASYNCH_FNC == DCM_CFG_DATA_USEPORT(DataRef)) \
                        || (DCM_USE_DATA_ASYNCH_FNC_ERROR == DCM_CFG_DATA_USEPORT(DataRef)) \
                        || (DCM_USE_DATA_ASYNCH_CLIENT_SERVER == DCM_CFG_DATA_USEPORT(DataRef)) \
                        || (DCM_USE_DATA_ASYNCH_CLIENT_SERVER_ERROR == DCM_CFG_DATA_USEPORT(DataRef))))
            {
                FncIndex = DCM_CFG_DATA_CONDITION_CHECK_FNC_INDEX(DataRef);
                /*return value: E_OK/E_NOT_OK/DCM_E_PENDING*/
                Result = DCM_CFG_DATA_CONDITION_CHECK_FNC_A(FncIndex)(OpStatus, pErrorCode);
            }
            else if((DCM_DID_CHECK_READ_FLAG == FALSE) && (TRUE == DCM_CFG_DATA_CONDITION_EN(DataRef)) \
                    && ((DCM_USE_DATA_SYNCH_FNC == DCM_CFG_DATA_USEPORT(DataRef)) \
                        || (DCM_USE_DATA_SYNCH_CLIENT_SERVER == DCM_CFG_DATA_USEPORT(DataRef))))
            {
                FncIndex = DCM_CFG_DATA_CONDITION_CHECK_FNC_INDEX(DataRef);
                /*return value: E_OK/E_NOT_OK*/
                Result = DCM_CFG_DATA_CONDITION_CHECK_FNC_B(FncIndex)(pErrorCode);
                if(Result != E_OK)
                {
                    /*In case the return value is DCM_E_PENDING*/
                    Result = E_NOT_OK;
                }
            }
            else
            {
                /*Condition check read not execute,to step2*/
            }

            if((Result == E_OK) && (DCM_DID_CHECK_READ_FLAG == FALSE))
            {
                /*to step2*/
                DCM_DID_CHECK_READ_FLAG = TRUE;
            }
            else
            {
                /*send negtive response or to step2 or condition check next mainfunction*/
            }

            /*compare response length with the response buffer max length*/
            if((Result == E_OK) && (DCM_DID_GET_LEN_FLAG == FALSE) \
                    && ((DCM_DID_RESP_LEN + DCM_DID_DATA_LEN + \
                         DCM_DDDID_ELE_DATA_SIZE(BufferIndex, DCM_DID_SIG_INDEX)) <= MaxBufferSize))
            {
                /*to step3*/
                DCM_DID_GET_LEN_FLAG = TRUE;

                DCM_DID_DATA_LEN += DCM_DDDID_ELE_DATA_SIZE(BufferIndex, DCM_DID_SIG_INDEX);
            }
            else if((Result == E_OK) && (DCM_DID_GET_LEN_FLAG == FALSE))
            {
                *pErrorCode = DCM_E_RESPONSETOOLONG;
                Result = E_NOT_OK;
            }
            else
            {
                /*do nothing*/
            }

            /*SWS_Dcm_00437*/
            /*Step2: Read data*/
            if((Result == E_OK) && (DCM_DID_GET_LEN_FLAG == TRUE) \
                    && ((DCM_USE_DATA_ASYNCH_FNC == DCM_CFG_DATA_USEPORT(DataRef)) \
                        || (DCM_USE_DATA_ASYNCH_CLIENT_SERVER == DCM_CFG_DATA_USEPORT(DataRef))))
            {
                FncIndex = DCM_CFG_DATA_READ_FNC_INDEX(DataRef);
                /*return value: E_OK/E_NOT_OK/DCM_E_PENDING*/
                Result = DCM_CFG_DATA_READ_FNC_A(FncIndex)(OpStatus, \
                         (DCM_DID_RESP_DATA + DCM_DID_DATA_LEN - 2U - \
                          DCM_DDDID_ELE_DATA_SIZE(BufferIndex, DCM_DID_SIG_INDEX)));
                if(Result == E_NOT_OK)
                {
                    *pErrorCode = DCM_E_GENERALREJECT;
                }
            }
            else if((Result == E_OK) && (DCM_DID_GET_LEN_FLAG == TRUE) \
                    && ((DCM_USE_DATA_ASYNCH_FNC_ERROR == DCM_CFG_DATA_USEPORT(DataRef)) \
                        || (DCM_USE_DATA_ASYNCH_CLIENT_SERVER_ERROR == DCM_CFG_DATA_USEPORT(DataRef))))
            {
                FncIndex = DCM_CFG_DATA_READ_FNC_INDEX(DataRef);
                /*return value: E_OK/E_NOT_OK/DCM_E_PENDING*/
                Result = DCM_CFG_DATA_READ_FNC_B(FncIndex)(OpStatus, \
                         (DCM_DID_RESP_DATA + DCM_DID_DATA_LEN - 2U - \
                          DCM_DDDID_ELE_DATA_SIZE(BufferIndex, DCM_DID_SIG_INDEX)), pErrorCode);
            }
            else if((Result == E_OK) && (DCM_DID_GET_LEN_FLAG == TRUE) \
                    && ((DCM_USE_DATA_SYNCH_FNC == DCM_CFG_DATA_USEPORT(DataRef)) \
                        || (DCM_USE_DATA_SYNCH_CLIENT_SERVER == DCM_CFG_DATA_USEPORT(DataRef))))
            {
                FncIndex = DCM_CFG_DATA_READ_FNC_INDEX(DataRef);
                /*return value: E_OK/E_NOT_OK*/
                Result = DCM_CFG_DATA_READ_FNC_C(FncIndex)( \
                         (DCM_DID_RESP_DATA + DCM_DID_DATA_LEN - 2U - \
                          DCM_DDDID_ELE_DATA_SIZE(BufferIndex, DCM_DID_SIG_INDEX)));
                if(Result != E_OK)
                {
                    /*In case the return value is DCM_E_PENDING*/
                    *pErrorCode = DCM_E_GENERALREJECT;
                    Result = E_NOT_OK;
                }
            }
#if(DCM_NVM_SUPPORT == STD_ON)
            else if((Result == E_OK) && (DCM_DID_GET_LEN_FLAG == TRUE) \
                    && (DCM_NVM_READBLOCK_CALLED == FALSE) \
                    && (DCM_USE_BLOCK_ID == DCM_CFG_DATA_USEPORT(DataRef)))
            {
                Result = NvM_ReadBlock(DCM_CFG_DATA_BLOCKID(DataRef), \
                                       (DCM_DID_RESP_DATA + DCM_DID_DATA_LEN - 2U - \
                                        DCM_DDDID_ELE_DATA_SIZE(BufferIndex, DCM_DID_SIG_INDEX)));
                if(Result == E_OK)
                {
                    /*The reading process is asynchronous*/
                    DCM_NVM_READBLOCK_CALLED = TRUE;
                    Result = DCM_E_PENDING;
                }
                else
                {
                    *pErrorCode = DCM_E_GENERALREJECT;
                }
            }
            else if((Result == E_OK) && (DCM_DID_GET_LEN_FLAG == TRUE) \
                    && (DCM_NVM_READBLOCK_CALLED == TRUE) \
                    && (DCM_USE_BLOCK_ID == DCM_CFG_DATA_USEPORT(DataRef)))
            {
                Result = NvM_GetErrorStatus(DCM_CFG_DATA_BLOCKID(DataRef), &NvMResult);
                if((Result == E_OK) && (NvMResult == NVM_REQ_OK))
                {
                    /*continue read next signal*/
                }
                else if((Result == E_OK) && (NvMResult == NVM_REQ_PENDING))
                {
                    /*Call again next mainfunction*/
                    Result = DCM_E_PENDING;
                }
                else
                {
                    *pErrorCode = DCM_E_GENERALREJECT;
                    Result = E_NOT_OK;
                }
            }
#endif
            else
            {
                /*do nothing*/
            }
        }
        else if(DCM_INVALID_MEMORY_ID != DCM_DDDID_ELE_MEM_ID(BufferIndex, DCM_DID_SIG_INDEX))
        {
            /*compare response length with the response buffer max length*/
            if((DCM_DID_RESP_LEN + DCM_DID_DATA_LEN + \
                    DCM_DDDID_ELE_DATA_SIZE(BufferIndex, DCM_DID_SIG_INDEX)) > MaxBufferSize)
            {
                *pErrorCode = DCM_E_RESPONSETOOLONG;
                Result = E_NOT_OK;
            }
            else
            {
                /*SWS_Dcm_00653*/
                /*Read DcmDspMemory*/
                Result = DspInternal_ReadMemory(OpStatus, \
                            DCM_DDDID_ELE_MEM_ID(BufferIndex, DCM_DID_SIG_INDEX), \
                            DCM_DDDID_ELE_MEM_ADDR(BufferIndex, DCM_DID_SIG_INDEX), \
                            DCM_DDDID_ELE_DATA_SIZE(BufferIndex, DCM_DID_SIG_INDEX), \
                            (DCM_DID_RESP_DATA + DCM_DID_DATA_LEN - 2U), pErrorCode);
                if(Result == E_OK)
                {
                    DCM_DID_DATA_LEN += DCM_DDDID_ELE_DATA_SIZE(BufferIndex, DCM_DID_SIG_INDEX);;
                }
            }
        }
        else
        {
            break;
        }

        if(Result == E_OK)/*DCM_DID_GET_LEN_FLAG must be true*/
        {
            /*continue read next signal*/
            DCM_DID_SIG_INDEX++;
            DCM_DID_CHECK_READ_FLAG = FALSE;
            DCM_DID_GET_LEN_FLAG = FALSE;
#if(DCM_NVM_SUPPORT == STD_ON)
            DCM_NVM_READBLOCK_CALLED = FALSE;
#endif
        }
        else if(Result == DCM_E_PENDING)
        {
            /*The fuction will be called again next mainfunction cycle.*/
            break;
        }
        else
        {
            /*send negative response*/
            Result = E_NOT_OK;
            break;
        }
    }/*for( ; DCM_DID_SIG_INDEX < DCM_CFG_DID_SIGNAL_NUM(DCM_DID_INDEX_LIST[DCM_DID_POS]); )*/

    if((Result == E_OK) || (Result == E_NOT_OK))
    {
        DCM_DID_SIG_INDEX = DCM_DATA_CLEAR;
    }
    return Result;
}
#endif

#if(DCM_UDS_2E_SERVICE == STD_ON)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name:
*
* Description:
*
* Inputs:
*
* Outputs:
*
* Return:
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
/*2E Service*//*SWS_Dcm_00255*/
FUNC(Std_ReturnType, DCM_CODE) DspInternal_2E_WriteDataByIdentifier
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
)
{
    Std_ReturnType Result = E_OK;
    uint16 ReqDID;
    Dcm_MsgType DataPtr;
    uint16 DynDataLength;
    uint16 i;
    uint16 DataRef;
    uint16 DataPos;
    uint16 TotalLength = 0U;
    uint8 SupportAddress;
    Dcm_SesRefType SesLevelRef;
#if(DCM_UDS_27_SERVICE == STD_ON)
    Dcm_SecRefType SecLevelRef;
    Dcm_SecRefType CurSecMask;
#endif
#if(DCM_NVM_SUPPORT == STD_ON)
    NvM_RequestResultType NvMResult = NVM_REQ_OK;
#endif
    uint16 FncIndex;

#if(DCM_CAR_PLATFORM == DCM_NISSAN_PLATFORM)
    uint8 DidHighByte = (pMsgContext->reqData[DCM_INDEX_1]);

    if(DidHighByte == DCM_RNDS_READ_ID_HIGH_BYTE)
    {
        /*Getting Identifiers supported by the ECU*/
        Result = DspInternal_0x2E_ReadSupportedIdentifier(pMsgContext, pErrorCode);
    }
    else
    {
#endif
        ReqDID = Make16Bit(pMsgContext->reqData[DCM_INDEX_1], pMsgContext->reqData[DCM_INDEX_2]);

        if(OpStatus == DCM_INITIAL)
        {
            DCM_DID_FOR2E2F_INDEX = DCM_DATA_CLEAR;
            DCM_DID_SIG_INDEX = DCM_DATA_CLEAR;
#if(DCM_NVM_SUPPORT == STD_ON)
            DCM_NVM_WRITEBLOCK_CALLED = FALSE;
#endif
            Result = E_NOT_OK;
            for(i = 0U; i < DCM_CFG_DID_NUM; i++)
            {
                if((ReqDID == DCM_CFG_DID_ID(i)) && (TRUE == DCM_CFG_DID_USED(i)) \
                        && (NULL_PTR != DCM_CFG_DID_INFO_WRITE(i)))
                {
                    DCM_DID_FOR2E2F_INDEX = i;
                    Result = E_OK;
                    break;
                }
            }

            if(Result != E_OK)
            {
                /*SWS_Dcm_00467*//*SWS_Dcm_00562*//*SWS_Dcm_00468*/
                *pErrorCode = DCM_E_REQUESTOUTOFRANGE;
            }
            else
            {
                SupportAddress = (DCM_CFG_DID_INFO_WRITE(DCM_DID_FOR2E2F_INDEX)->DcmDspDidWriteSupportAddress);
                SesLevelRef = (DCM_CFG_DID_INFO_WRITE(DCM_DID_FOR2E2F_INDEX)->DcmDspDidWriteSessionRef);

                if(!(SupportAddress & (((uint8)0x01) << (pMsgContext->msgAddInfo.reqType))))
                {
                    *pErrorCode = DCM_E_REQUESTOUTOFRANGE;
                    Result = E_NOT_OK;
                }
                else if(!(DCM_CFG_SESSION_MASK(DCM_SESSION_LEVEL) & SesLevelRef))
                {
                    /*SWS_Dcm_00469*/
                    *pErrorCode = DCM_E_REQUESTOUTOFRANGE;
                    Result = E_NOT_OK;
                }
                else
                {
                    /*to check the total length*/
                }
            }
            /*total length check*/
            if(Result == E_OK)
            {
                for(i = 0U; i < DCM_CFG_DID_SIGNAL_NUM(DCM_DID_FOR2E2F_INDEX); i++)
                {
                    DataRef = DCM_CFG_DID_SIGNAL(DCM_DID_FOR2E2F_INDEX)[i].DcmDspDidDataRef;
                    if(DCM_CFG_DATA_TYPE(DataRef) == DCM_UINT8_DYN)
                    {
                        break;
                    }
                    else
                    {
                        if((DCM_CFG_DATA_SIZE(DataRef) % 8U) != 0U)
                        {
                            TotalLength += ((DCM_CFG_DATA_SIZE(DataRef) >> 3U) + 1U);
                        }
                        else
                        {
                            TotalLength += (DCM_CFG_DATA_SIZE(DataRef) >> 3U);
                        }
                    }
                }

                if((i == DCM_CFG_DID_SIGNAL_NUM(DCM_DID_FOR2E2F_INDEX)) \
                        && ((pMsgContext->reqDataLen) != (3U + TotalLength)))
                {
                    /*SWS_Dcm_00473*/
                    *pErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
                    Result = E_NOT_OK;
                }
            }
#if(DCM_UDS_27_SERVICE == STD_ON)
            /*DID security check*/
            if(Result == E_OK)
            {
                CurSecMask = DslInternal_GetSecurityMask();
                SecLevelRef = (DCM_CFG_DID_INFO_WRITE(DCM_DID_FOR2E2F_INDEX)->DcmDspDidWriteSecurityLevelRef);

                if(!(CurSecMask & SecLevelRef))
                {
                    /*SWS_Dcm_00470*/
                    *pErrorCode = DCM_E_SECURITYACCESSDENIED;
                    Result = E_NOT_OK;
                }
            }
#endif
#if(DCM_CAR_PLATFORM == DCM_GEELY_PLATFORM)
            SetP4Timer(DCM_REQ_SERVICEINFO->P4ServerMax);
#endif
        }/*if(OpStatus == DCM_INITIAL)*/

        if(Result == E_OK)
        {
            DataPtr = (pMsgContext->reqData) + 3U;
            for( ; DCM_DID_SIG_INDEX < DCM_CFG_DID_SIGNAL_NUM(DCM_DID_FOR2E2F_INDEX); )
            {
                DataPos = DCM_CFG_DID_SIGNAL(DCM_DID_FOR2E2F_INDEX)[DCM_DID_SIG_INDEX].DcmDspDidDataPos;
                DataRef = DCM_CFG_DID_SIGNAL(DCM_DID_FOR2E2F_INDEX)[DCM_DID_SIG_INDEX].DcmDspDidDataRef;
                DataPos = (DataPos >> 3U);
                /*SWS_Dcm_00395*/
                if(((DCM_USE_DATA_ASYNCH_FNC == DCM_CFG_DATA_USEPORT(DataRef)) \
                        || (DCM_USE_DATA_ASYNCH_FNC_ERROR == DCM_CFG_DATA_USEPORT(DataRef)) \
                        || (DCM_USE_DATA_ASYNCH_CLIENT_SERVER == DCM_CFG_DATA_USEPORT(DataRef)) \
                        || (DCM_USE_DATA_ASYNCH_CLIENT_SERVER_ERROR == DCM_CFG_DATA_USEPORT(DataRef))) \
                        && (DCM_UINT8_DYN != DCM_CFG_DATA_TYPE(DataRef)))
                {
                    FncIndex = DCM_CFG_DATA_WRITE_FNC_INDEX(DataRef);
                    /*return value: E_OK/E_NOT_OK/DCM_E_PENDING*/
                    Result = DCM_CFG_DATA_WRITE_FNC_A(FncIndex)((DataPtr + DataPos), OpStatus, pErrorCode);
                }
                else if((DCM_USE_DATA_ASYNCH_FNC == DCM_CFG_DATA_USEPORT(DataRef)) \
                         || (DCM_USE_DATA_ASYNCH_FNC_ERROR == DCM_CFG_DATA_USEPORT(DataRef)) \
                         || (DCM_USE_DATA_ASYNCH_CLIENT_SERVER == DCM_CFG_DATA_USEPORT(DataRef)) \
                         || (DCM_USE_DATA_ASYNCH_CLIENT_SERVER_ERROR == DCM_CFG_DATA_USEPORT(DataRef)))
                {
                    FncIndex = DCM_CFG_DATA_WRITE_FNC_INDEX(DataRef);
                    /*[constr_6039] Signals with variable datalength.
                    Only the last signal (DcmDspDidSignal) of a DID can have
                    variable datalength (DcmDspDataType is set to UINT8_DYN).*/
                    DynDataLength = ((pMsgContext->reqDataLen) - 3U - DataPos);
                    /*return value: E_OK/E_NOT_OK/DCM_E_PENDING*/
                    Result = DCM_CFG_DATA_WRITE_FNC_B(FncIndex)((DataPtr + DataPos), DynDataLength, OpStatus, pErrorCode);
                }
                else if(((DCM_USE_DATA_SYNCH_FNC == DCM_CFG_DATA_USEPORT(DataRef)) \
                         || (DCM_USE_DATA_SYNCH_CLIENT_SERVER == DCM_CFG_DATA_USEPORT(DataRef))) \
                        && (DCM_UINT8_DYN != DCM_CFG_DATA_TYPE(DataRef)))
                {
                    FncIndex = DCM_CFG_DATA_WRITE_FNC_INDEX(DataRef);
                    /*return value: E_OK/E_NOT_OK*/
                    Result = DCM_CFG_DATA_WRITE_FNC_C(FncIndex)((DataPtr + DataPos), pErrorCode);
                    if(Result != E_OK)
                    {
                        /*In case the return value is DCM_E_PENDING*/
                        Result = E_NOT_OK;
                    }
                }
                else if((DCM_USE_DATA_SYNCH_FNC == DCM_CFG_DATA_USEPORT(DataRef)) \
                         || (DCM_USE_DATA_SYNCH_CLIENT_SERVER == DCM_CFG_DATA_USEPORT(DataRef)))
                {
                    FncIndex = DCM_CFG_DATA_WRITE_FNC_INDEX(DataRef);
                    /*[constr_6039] Signals with variable datalength.
                    Only the last signal (DcmDspDidSignal) of a DID can have
                    variable datalength (DcmDspDataType is set to UINT8_DYN).*/
                    DynDataLength = ((pMsgContext->reqDataLen) - 3U - DataPos);
                    /*return value: E_OK/E_NOT_OK*/
                    Result = DCM_CFG_DATA_WRITE_FNC_D(FncIndex)((DataPtr + DataPos), DynDataLength, pErrorCode);
                    if(Result != E_OK)
                    {
                        /*In case the return value is DCM_E_PENDING*/
                        Result = E_NOT_OK;
                    }
                }
#if(DCM_NVM_SUPPORT == STD_ON)
                /*SWS_Dcm_00541*/
                else if((DCM_USE_BLOCK_ID == DCM_CFG_DATA_USEPORT(DataRef)) \
                        && (DCM_NVM_WRITEBLOCK_CALLED == FALSE))
                {
                    Result = NvM_WriteBlock(DCM_CFG_DATA_BLOCKID(DataRef), (DataPtr + DataPos));
                    if(Result == E_OK)
                    {
                        /*The writing process is asynchronous*/
                        DCM_NVM_WRITEBLOCK_CALLED = TRUE;
                        Result = DCM_E_PENDING;
                    }
                    else
                    {
                        *pErrorCode = DCM_E_GENERALREJECT;
                    }
                }
                else if(DCM_USE_BLOCK_ID == DCM_CFG_DATA_USEPORT(DataRef))
                {
                    Result = NvM_GetErrorStatus(DCM_CFG_DATA_BLOCKID(DataRef), &NvMResult);
                    if((Result == E_OK) && (NvMResult == NVM_REQ_OK))
                    {
                        /*continue read next signal*/
                    }
                    else if((Result == E_OK) && (NvMResult == NVM_REQ_PENDING))
                    {
                        /*Call again next mainfunction*/
						Result = DCM_E_PENDING;
                    }
                    else
                    {
#if(DCM_CAR_PLATFORM == DCM_GEELY_PLATFORM)
                        *pErrorCode = DCM_E_CONDITIONSNOTCORRECT;
#else
                        *pErrorCode = DCM_E_GENERALREJECT;
#endif
                        Result = E_NOT_OK;
                    }
                }
#endif
                else
                {
                    *pErrorCode = DCM_E_GENERALREJECT;
                    Result = E_NOT_OK;
                }

                if(Result == E_OK)
                {
                    /*continue read next signal*/
                    DCM_DID_SIG_INDEX++;
#if(DCM_NVM_SUPPORT == STD_ON)
                    DCM_NVM_WRITEBLOCK_CALLED = FALSE;
#endif
                }
                else if(Result == DCM_E_PENDING)
                {
                    /*The fuction will be called again next mainfunction cycle.*/
                    break;
                }
                else
                {
                    /*send negative response*/
                    Result = E_NOT_OK;
                    break;
                }
            }/*for( ; DCM_DID_SIG_INDEX < DCM_CFG_DID_SIGNAL_NUM(DCM_DID_FOR2E2F_INDEX); )*/
        }

        if(Result == E_OK)
        {
            pMsgContext->resData[DCM_INDEX_1] = pMsgContext->reqData[DCM_INDEX_1];
            pMsgContext->resData[DCM_INDEX_2] = pMsgContext->reqData[DCM_INDEX_2];
            pMsgContext->resDataLen = 3U;
        }
#if(DCM_CAR_PLATFORM == DCM_NISSAN_PLATFORM)
    }
#endif
    return Result;
}

#if(DCM_CAR_PLATFORM == DCM_NISSAN_PLATFORM)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DspInternal_0x2E_ReadSupportedIdentifier
*
* Description: Read supported identifier of 0x2E service.
*
* Inputs: pMsgContext, pErrorCode
*
* Outputs: None
*
* Return: E_OK, E_NOT_OK
*
* Limitations: Only used to meet nissan specification
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, DCM_CODE) DspInternal_0x2E_ReadSupportedIdentifier
(
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
)
{
    uint16 i;
    uint8 BytePos;
    uint8 BitPos;
    uint8 ResponseData[DCM_RNDS_READ_DATA_LENGTH];
    Std_ReturnType Result = E_OK;
    uint8 DidLowByte = (pMsgContext->reqData[DCM_INDEX_2]);
    uint8 SubData = (pMsgContext->reqData[DCM_INDEX_3]);

    if((pMsgContext->reqDataLen) != DCM_NISSAN_READ_LENGTH)
    {
        /*the correct request length should be 3*/
        *pErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
        Result = E_NOT_OK;
    }
    else if(SubData != 0U)
    {
        *pErrorCode = DCM_E_REQUESTOUTOFRANGE;
        Result = E_NOT_OK;
    }
    else
    {
        for(i = 0U; i < DCM_RNDS_READ_DATA_LENGTH; i++)
        {
            /*reset the data value with zero*/
            ResponseData[i] = DCM_DATA_CLEAR;
        }

        if(DCM_RNDS_READ_ID_HIGH_BYTE == DidLowByte)
        {
            for(i = (uint16)0; i < DCM_CFG_DID_NUM; i++)
            {
                if((TRUE == DCM_CFG_DID_USED(i)) && (NULL_PTR != DCM_CFG_DID_INFO_WRITE(i)))
                {
                    BytePos = (uint8)(DCM_CFG_DID_ID(i) >> 11);
                    BitPos = (uint8)((DCM_CFG_DID_ID(i) >> 8) % 8);
                    ResponseData[BytePos] |= ((uint8)0x80 >> BitPos);
                }
            }
        }
        else
        {
            for(i = (uint16)0; i < DCM_CFG_DID_NUM; i++)
            {
                if((TRUE == DCM_CFG_DID_USED(i)) && (NULL_PTR != DCM_CFG_DID_INFO_WRITE(i)) \
                    && (((DCM_CFG_DID_ID(i) & DCM_RNDS_ID_HIGH_MASK) >> 8) == DidLowByte))
                {
                    BytePos = (uint8)((DCM_CFG_DID_ID(i) & DCM_RNDS_ID_LOW_MASK) / 8);
                    BitPos = (uint8)((DCM_CFG_DID_ID(i) & DCM_RNDS_ID_LOW_MASK) % 8);
                    ResponseData[BytePos] |= ((uint8)0x80 >> BitPos);
                }
            }
        }
    }

    if(Result == E_OK)
    {
        /*Copy the data to the response buffer*/
        Bsw_MemCpy(&(pMsgContext->resData[DCM_INDEX_3]), ResponseData, DCM_RNDS_READ_DATA_LENGTH);

        pMsgContext->resData[DCM_INDEX_1] = pMsgContext->reqData[DCM_INDEX_1];
        pMsgContext->resData[DCM_INDEX_2] = pMsgContext->reqData[DCM_INDEX_2];
        pMsgContext->resDataLen = (DCM_INDEX_3 + DCM_RNDS_READ_DATA_LENGTH);
    }
    return Result;
}
#endif/*#if(DCM_CAR_PLATFORM == DCM_NISSAN_PLATFORM)*/

#endif

#if(DCM_UDS_2F_SERVICE == STD_ON)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name:
*
* Description:
*
* Inputs:
*
* Outputs:
*
* Return:
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
/*2F Service*//*SWS_Dcm_00256*/
FUNC(Std_ReturnType, DCM_CODE) DspInternal_2F_InputOutputControlByIdentifier
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
)
{
    Std_ReturnType Result = E_OK;
    uint16 ReqDID;
    uint16 i;
    uint16 DataRef;
    uint16 DataPos = 0U;
    uint8 MaskBitPos;
    uint8 MaskBytePos;
    uint16 ControlStateLength = 0U;
    uint8 SupportAddress;
    Dcm_SesRefType SesLevelRef;
#if(DCM_UDS_27_SERVICE == STD_ON)
    Dcm_SecRefType SecLevelRef;
    Dcm_SecRefType CurSecMask;
#endif
    uint32 ControlMask = 0U;
#if(DCM_CAR_PLATFORM == DCM_NISSAN_PLATFORM)
    uint8 DidHighByte = (pMsgContext->reqData[DCM_INDEX_1]);

    if(DidHighByte == DCM_RNDS_READ_ID_HIGH_BYTE)
    {
        /*Getting Identifiers supported by the ECU from App*/
        Result = DspInternal_0x2F_ReadSupportedIdentifier(pMsgContext, pErrorCode);
    }
    else
    {
#endif
        ReqDID = Make16Bit(pMsgContext->reqData[DCM_INDEX_1], pMsgContext->reqData[DCM_INDEX_2]);

        if(OpStatus == DCM_INITIAL)
        {
            DCM_IOCONTROL_FLAG = FALSE;
            DCM_DID_IS_READING = FALSE;
            DCM_DID_CHECK_READ_FLAG = FALSE;
            DCM_DID_GET_LEN_FLAG = FALSE;
            DCM_DID_SIG_INDEX = DCM_DATA_CLEAR;

            DCM_REQ_IOCONTROL = (pMsgContext->reqData[DCM_INDEX_3]);
            Result = E_NOT_OK;
            for(i = 0U; i < DCM_CFG_DID_NUM; i++)
            {
                if((ReqDID == DCM_CFG_DID_ID(i)) && (TRUE == DCM_CFG_DID_USED(i)) \
                        && (NULL_PTR != DCM_CFG_DID_INFO_CONTROL(i)))
                {
                    DCM_DID_FOR2E2F_INDEX = i;
                    SupportAddress = DCM_CFG_DID_CONTROL_ADDRREF(i);
                    SesLevelRef = DCM_CFG_DID_CONTROL_SESREF(i);
                    Result = E_OK;
                    break;
                }
            }

            /*SWS_Dcm_00579*/
            if(Result != E_OK)
            {
                /*SWS_Dcm_00563*//*SWS_Dcm_00564*/
                *pErrorCode = DCM_E_REQUESTOUTOFRANGE;
            }
            /*check the support address type*/
            else if(!(SupportAddress & (((uint8)0x01) << (pMsgContext->msgAddInfo.reqType))))
            {
                *pErrorCode = DCM_E_REQUESTOUTOFRANGE;
                Result = E_NOT_OK;
            }
            /*check the support session level*/
            else if(!(DCM_CFG_SESSION_MASK(DCM_SESSION_LEVEL) & SesLevelRef))
            {
                /*SWS_Dcm_00566*/
                *pErrorCode = DCM_E_REQUESTOUTOFRANGE;
                Result = E_NOT_OK;
            }
            /*check if support ResetToDefault inputOutputControlParameter*/
            else if((DCM_REQ_IOCONTROL == DCM_RESET_TO_DEFAULT) \
                    && (DCM_CFG_DID_CONTROL_RESET(DCM_DID_FOR2E2F_INDEX) == FALSE))
            {
                /*SWS_Dcm_00565*/
                *pErrorCode = DCM_E_REQUESTOUTOFRANGE;
                Result = E_NOT_OK;
            }
            /*check if support FreezeCurrentState inputOutputControlParameter*/
            else if((DCM_REQ_IOCONTROL == DCM_FREEZE_CURRENT_STATE) \
                    && (DCM_CFG_DID_CONTROL_FREEZE(DCM_DID_FOR2E2F_INDEX) == FALSE))
            {
                /*SWS_Dcm_00565*/
                *pErrorCode = DCM_E_REQUESTOUTOFRANGE;
                Result = E_NOT_OK;
            }
            /*check if support ShortTermAdjustment inputOutputControlParameter*/
            else if((DCM_REQ_IOCONTROL == DCM_SHORT_TERM_ADJUSTMENT) \
                    && (DCM_CFG_DID_CONTROL_SHORT(DCM_DID_FOR2E2F_INDEX) == FALSE))
            {
                /*SWS_Dcm_00565*/
                *pErrorCode = DCM_E_REQUESTOUTOFRANGE;
                Result = E_NOT_OK;
            }
            else if(DCM_REQ_IOCONTROL > DCM_SHORT_TERM_ADJUSTMENT)
            {
                /*SWS_Dcm_00565*/
                *pErrorCode = DCM_E_REQUESTOUTOFRANGE;
                Result = E_NOT_OK;
            }
            /*check request length*/
            /*SWS_Dcm_01273*//*SWS_Dcm_01274*/
            else if(((DCM_REQ_IOCONTROL == DCM_RETURN_CONTROL_TO_ECU) \
                     || (DCM_REQ_IOCONTROL == DCM_RESET_TO_DEFAULT) \
                     || (DCM_REQ_IOCONTROL == DCM_FREEZE_CURRENT_STATE)) \
                    && ((pMsgContext->reqDataLen) != (4U + DCM_CFG_DID_CONTROL_MASK_SIZE(DCM_DID_FOR2E2F_INDEX))))
            {
                *pErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
                Result = E_NOT_OK;
            }
            else if(DCM_REQ_IOCONTROL == DCM_SHORT_TERM_ADJUSTMENT)
            {
                for(i = 0U; i < DCM_CFG_DID_SIGNAL_NUM(DCM_DID_FOR2E2F_INDEX); i++)
                {
                    if(DataPos <= (DCM_CFG_DID_SIGNAL(DCM_DID_FOR2E2F_INDEX)[i].DcmDspDidDataPos))
                    {
                        DataPos = DCM_CFG_DID_SIGNAL(DCM_DID_FOR2E2F_INDEX)[i].DcmDspDidDataPos;
                        DataRef = DCM_CFG_DID_SIGNAL(DCM_DID_FOR2E2F_INDEX)[i].DcmDspDidDataRef;
                        if((DCM_CFG_DATA_SIZE(DataRef) % 8U) != 0U)
                        {
                            ControlStateLength = (((DataPos + DCM_CFG_DATA_SIZE(DataRef)) >> 3U) + 1U);
                        }
                        else
                        {
                            ControlStateLength = ((DataPos + DCM_CFG_DATA_SIZE(DataRef)) >> 3U);
                        }
                    }
                }
                /*4U is 0x2F + DID + IOControl*/
                if((DCM_CFG_DATA_TYPE(DataRef) == DCM_UINT8_DYN) \
                        && ((pMsgContext->reqDataLen) > (4U +  ControlStateLength + \
                                DCM_CFG_DID_CONTROL_MASK_SIZE(DCM_DID_FOR2E2F_INDEX))))
                {
                    *pErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
                    Result = E_NOT_OK;
                }
                else if((pMsgContext->reqDataLen) != (4U + ControlStateLength + \
                                                      DCM_CFG_DID_CONTROL_MASK_SIZE(DCM_DID_FOR2E2F_INDEX)))
                {
                    *pErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
                    Result = E_NOT_OK;
                }
                else
                {
                    /*length is valid*/
                }
            }
            else
            {
                /*do nothing*/
            }

#if(DCM_UDS_27_SERVICE == STD_ON)
            /*check the support security level*/
            if(Result == E_OK)
            {
                CurSecMask = DslInternal_GetSecurityMask();
                SecLevelRef = DCM_CFG_DID_CONTROL_SECREF(DCM_DID_FOR2E2F_INDEX);
                if(!(CurSecMask & SecLevelRef))
                {
                    /*SWS_Dcm_00567*/
                    *pErrorCode = DCM_E_SECURITYACCESSDENIED;
                    Result = E_NOT_OK;
                }
            }
#endif
#if(DCM_CAR_PLATFORM == DCM_GEELY_PLATFORM)
            SetP4Timer(DCM_REQ_SERVICEINFO->P4ServerMax);
#endif
        }/*if(OpStatus == DCM_INITIAL)*/

        /*IO Control*/
        if((Result == E_OK) && (DCM_IOCONTROL_FLAG == FALSE) \
                && (DCM_CFG_DID_SIGNAL_NUM(DCM_DID_FOR2E2F_INDEX) == 1U))
        {
            /*SWS_Dcm_01272*//*SWS_Dcm_00581*/
            if(DCM_CFG_DID_CONTROL_MASK_SIZE(DCM_DID_FOR2E2F_INDEX) == (uint8)0x01)
            {
                ControlMask = (pMsgContext->reqData[pMsgContext->reqDataLen - 1U]);
            }
            else if(DCM_CFG_DID_CONTROL_MASK_SIZE(DCM_DID_FOR2E2F_INDEX) == (uint8)0x02)
            {
                ControlMask = Make16Bit(pMsgContext->reqData[pMsgContext->reqDataLen - 2U], \
                                        pMsgContext->reqData[pMsgContext->reqDataLen - 1U]);
            }
            else if(DCM_CFG_DID_CONTROL_MASK_SIZE(DCM_DID_FOR2E2F_INDEX) == (uint8)0x03)
            {
                ControlMask = Make32Bit(0U, pMsgContext->reqData[pMsgContext->reqDataLen - 3U], \
                                        pMsgContext->reqData[pMsgContext->reqDataLen - 2U], \
                                        pMsgContext->reqData[pMsgContext->reqDataLen - 1U]);
            }
            else if(DCM_CFG_DID_CONTROL_MASK_SIZE(DCM_DID_FOR2E2F_INDEX) == (uint8)0x04)
            {
                ControlMask = Make32Bit(pMsgContext->reqData[pMsgContext->reqDataLen - 4U], \
                                        pMsgContext->reqData[pMsgContext->reqDataLen - 3U], \
                                        pMsgContext->reqData[pMsgContext->reqDataLen - 2U], \
                                        pMsgContext->reqData[pMsgContext->reqDataLen - 1U]);
            }
            else
            {
                ControlMask = 0U;
            }
            /*IO Control process*/
            Result = DspInternal_2F_IOControlPrecess(OpStatus, ControlMask, pMsgContext, pErrorCode);
            if(Result == E_OK)
            {
                DCM_IOCONTROL_FLAG = TRUE;
            }
        }
        else if((Result == E_OK) && (DCM_IOCONTROL_FLAG == FALSE) \
                && (DCM_CFG_DID_SIGNAL_NUM(DCM_DID_FOR2E2F_INDEX) > 1U))
        {
            for( ; DCM_DID_SIG_INDEX < DCM_CFG_DID_SIGNAL_NUM(DCM_DID_FOR2E2F_INDEX); )
            {
                MaskBitPos = DCM_CFG_DID_CONTROL_EN_MASK_POS(DCM_DID_FOR2E2F_INDEX, DCM_DID_SIG_INDEX);
                MaskBytePos = (pMsgContext->reqDataLen - 1U - \
                               DCM_CFG_DID_CONTROL_MASK_SIZE(DCM_DID_FOR2E2F_INDEX) + \
                               (MaskBitPos >> 3U));
                MaskBitPos = (MaskBitPos % 8U);

                if((pMsgContext->reqData[MaskBytePos]) & ((uint8)0x80 >> MaskBitPos))
                {
                    /*IO Control process*/
                    Result = DspInternal_2F_IOControlPrecess(OpStatus, 1U, pMsgContext, pErrorCode);
                }
                else if(DCM_CONTROLMASK_EXTERNAL == DCM_CFG_DID_CONTROL_MASK(DCM_DID_FOR2E2F_INDEX))
                {
                    Result = DspInternal_2F_IOControlPrecess(OpStatus, 0U, pMsgContext, pErrorCode);
                }
                else
                {
                    /*do nothing*/
                }

                if(Result == E_OK)
                {
                    DCM_DID_SIG_INDEX++;
                }
                else
                {
                    break;
                }
            }
            if(Result == E_OK)
            {
                DCM_DID_SIG_INDEX = DCM_DATA_CLEAR;
                DCM_IOCONTROL_FLAG = TRUE;
            }
        }
        else
        {
            /*do nothing*/
        }

        /*SWS_Dcm_00682,Read the controlState*/
        if((Result == E_OK) && (DCM_IOCONTROL_FLAG == TRUE))
        {
            if(DCM_DID_IS_READING == FALSE)
            {
                DCM_DID_IS_READING = TRUE;
                DCM_DID_RESP_LEN = 2U;/*0x2F + IOControl*/
                DCM_DID_DATA_LEN = 2U;/*DID length*/
                DCM_DID_RESP_DATA = (pMsgContext->resData + DCM_DID_RESP_LEN + DCM_DID_DATA_LEN);
            }
            /*read all reference data*/
            Result = DspInternal_DidReadAllRefData(DCM_DID_FOR2E2F_INDEX, \
                                                   (pMsgContext->resMaxDataLen), \
                                                   OpStatus, pErrorCode);
            if(Result == E_OK)
            {
                DCM_DID_RESP_LEN += DCM_DID_DATA_LEN;

                pMsgContext->resData[DCM_INDEX_1] = pMsgContext->reqData[DCM_INDEX_1];
                pMsgContext->resData[DCM_INDEX_2] = pMsgContext->reqData[DCM_INDEX_2];
                pMsgContext->resData[DCM_INDEX_3] = DCM_REQ_IOCONTROL;
                pMsgContext->resDataLen = DCM_DID_RESP_LEN;
            }
        }
#if(DCM_CAR_PLATFORM == DCM_NISSAN_PLATFORM)
    }
#endif
    return Result;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name:
*
* Description:
*
* Inputs:
*
* Outputs:
*
* Return:
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, DCM_CODE) DspInternal_2F_IOControlPrecess
(
    Dcm_OpStatusType OpStatus,
    uint32 ControlMask,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
)
{
    Std_ReturnType Result = E_OK;
    uint8 *ControlStateInfo = NULL_PTR;
    uint16 DataLength = 0U;
    uint16 FncIndex;

    uint16 DataPos = DCM_CFG_DID_SIGNAL(DCM_DID_FOR2E2F_INDEX)[DCM_DID_SIG_INDEX].DcmDspDidDataPos;
    uint16 DataRef = DCM_CFG_DID_SIGNAL(DCM_DID_FOR2E2F_INDEX)[DCM_DID_SIG_INDEX].DcmDspDidDataRef;
    DataPos = (DataPos >> 3U);

    if(DCM_REQ_IOCONTROL == DCM_RETURN_CONTROL_TO_ECU)
    {
        FncIndex = DCM_CFG_DATA_RETURN_FNC_INDEX(DataRef);
        /*SWS_Dcm_00396*//*SWS_Dcm_01285*/
        if(DCM_CONTROLMASK_EXTERNAL != DCM_CFG_DID_CONTROL_MASK(DCM_DID_FOR2E2F_INDEX))
        {
            /*return value: E_OK/E_NOT_OK*/
            Result = DCM_CFG_DATA_RETURN_FNC_C(FncIndex)(pErrorCode);
            if(Result != E_OK)
            {
                /*In case the return value is DCM_E_PENDING*/
                Result = E_NOT_OK;
            }
        }
        else/*(DCM_CONTROLMASK_EXTERNAL == DCM_CFG_DID_CONTROL_MASK(DCM_DID_FOR2E2F_INDEX))*/
        {
            /*return value: E_OK/E_NOT_OK*/
            Result = DCM_CFG_DATA_RETURN_FNC_D(FncIndex)(ControlMask, pErrorCode);
            if(Result != E_OK)
            {
                /*In case the return value is DCM_E_PENDING*/
                Result = E_NOT_OK;
            }
        }
    }
    else if(DCM_REQ_IOCONTROL == DCM_RESET_TO_DEFAULT)
    {
        FncIndex = DCM_CFG_DATA_RESET_FNC_INDEX(DataRef);
        /*SWS_Dcm_00397*/
        if((DCM_CONTROLMASK_EXTERNAL != DCM_CFG_DID_CONTROL_MASK(DCM_DID_FOR2E2F_INDEX)) \
                && ((DCM_USE_DATA_ASYNCH_FNC == DCM_CFG_DATA_USEPORT(DataRef)) \
                    || (DCM_USE_DATA_ASYNCH_FNC_ERROR == DCM_CFG_DATA_USEPORT(DataRef)) \
                    || (DCM_USE_DATA_ASYNCH_CLIENT_SERVER == DCM_CFG_DATA_USEPORT(DataRef)) \
                    || (DCM_USE_DATA_ASYNCH_CLIENT_SERVER_ERROR == DCM_CFG_DATA_USEPORT(DataRef))))
        {
            /*return value: E_OK/E_NOT_OK/DCM_E_PENDING*/
            Result = DCM_CFG_DATA_RESET_FNC_A(FncIndex)(OpStatus, pErrorCode);
        }
        else if((DCM_CONTROLMASK_EXTERNAL == DCM_CFG_DID_CONTROL_MASK(DCM_DID_FOR2E2F_INDEX)) \
                && ((DCM_USE_DATA_ASYNCH_FNC == DCM_CFG_DATA_USEPORT(DataRef)) \
                    || (DCM_USE_DATA_ASYNCH_FNC_ERROR == DCM_CFG_DATA_USEPORT(DataRef)) \
                    || (DCM_USE_DATA_ASYNCH_CLIENT_SERVER == DCM_CFG_DATA_USEPORT(DataRef)) \
                    || (DCM_USE_DATA_ASYNCH_CLIENT_SERVER_ERROR == DCM_CFG_DATA_USEPORT(DataRef))))
        {
            /*return value: E_OK/E_NOT_OK/DCM_E_PENDING*/
            Result = DCM_CFG_DATA_RESET_FNC_B(FncIndex)(OpStatus, ControlMask, pErrorCode);
        }
        else if((DCM_CONTROLMASK_EXTERNAL != DCM_CFG_DID_CONTROL_MASK(DCM_DID_FOR2E2F_INDEX)) \
                && ((DCM_USE_DATA_SYNCH_FNC == DCM_CFG_DATA_USEPORT(DataRef)) \
                    || (DCM_USE_DATA_SYNCH_CLIENT_SERVER == DCM_CFG_DATA_USEPORT(DataRef))))
        {
            /*return value: E_OK/E_NOT_OK/DCM_E_PENDING*/
            Result = DCM_CFG_DATA_RESET_FNC_C(FncIndex)(pErrorCode);
            if(Result != E_OK)
            {
                /*In case the return value is DCM_E_PENDING*/
                Result = E_NOT_OK;
            }
        }
        else if((DCM_CONTROLMASK_EXTERNAL == DCM_CFG_DID_CONTROL_MASK(DCM_DID_FOR2E2F_INDEX)) \
                && ((DCM_USE_DATA_SYNCH_FNC == DCM_CFG_DATA_USEPORT(DataRef)) \
                    || (DCM_USE_DATA_SYNCH_CLIENT_SERVER == DCM_CFG_DATA_USEPORT(DataRef))))
        {
            /*return value: E_OK/E_NOT_OK/DCM_E_PENDING*/
            Result = DCM_CFG_DATA_RESET_FNC_D(FncIndex)(ControlMask, pErrorCode);
            if(Result != E_OK)
            {
                /*In case the return value is DCM_E_PENDING*/
                Result = E_NOT_OK;
            }
        }
        else
        {
            *pErrorCode = DCM_E_REQUESTOUTOFRANGE;
            Result = E_NOT_OK;
        }
    }
    else if(DCM_REQ_IOCONTROL == DCM_FREEZE_CURRENT_STATE)
    {
        FncIndex = DCM_CFG_DATA_FREEZE_FNC_INDEX(DataRef);
        /*SWS_Dcm_00398*/
        if((DCM_CONTROLMASK_EXTERNAL != DCM_CFG_DID_CONTROL_MASK(DCM_DID_FOR2E2F_INDEX)) \
                && ((DCM_USE_DATA_ASYNCH_FNC == DCM_CFG_DATA_USEPORT(DataRef)) \
                    || (DCM_USE_DATA_ASYNCH_FNC_ERROR == DCM_CFG_DATA_USEPORT(DataRef)) \
                    || (DCM_USE_DATA_ASYNCH_CLIENT_SERVER == DCM_CFG_DATA_USEPORT(DataRef)) \
                    || (DCM_USE_DATA_ASYNCH_CLIENT_SERVER_ERROR == DCM_CFG_DATA_USEPORT(DataRef))))
        {
            /*return value: E_OK/E_NOT_OK/DCM_E_PENDING*/
            Result = DCM_CFG_DATA_FREEZE_FNC_A(FncIndex)(OpStatus, pErrorCode);
        }
        else if((DCM_CONTROLMASK_EXTERNAL == DCM_CFG_DID_CONTROL_MASK(DCM_DID_FOR2E2F_INDEX)) \
                && ((DCM_USE_DATA_ASYNCH_FNC == DCM_CFG_DATA_USEPORT(DataRef)) \
                    || (DCM_USE_DATA_ASYNCH_FNC_ERROR == DCM_CFG_DATA_USEPORT(DataRef)) \
                    || (DCM_USE_DATA_ASYNCH_CLIENT_SERVER == DCM_CFG_DATA_USEPORT(DataRef)) \
                    || (DCM_USE_DATA_ASYNCH_CLIENT_SERVER_ERROR == DCM_CFG_DATA_USEPORT(DataRef))))
        {
            /*return value: E_OK/E_NOT_OK/DCM_E_PENDING*/
            Result = DCM_CFG_DATA_FREEZE_FNC_B(FncIndex)(OpStatus, ControlMask, pErrorCode);
        }
        else if((DCM_CONTROLMASK_EXTERNAL != DCM_CFG_DID_CONTROL_MASK(DCM_DID_FOR2E2F_INDEX)) \
                && ((DCM_USE_DATA_SYNCH_FNC == DCM_CFG_DATA_USEPORT(DataRef)) \
                    || (DCM_USE_DATA_SYNCH_CLIENT_SERVER == DCM_CFG_DATA_USEPORT(DataRef))))
        {
            /*return value: E_OK/E_NOT_OK/DCM_E_PENDING*/
            Result = DCM_CFG_DATA_FREEZE_FNC_C(FncIndex)(pErrorCode);
            if(Result != E_OK)
            {
                /*In case the return value is DCM_E_PENDING*/
                Result = E_NOT_OK;
            }
        }
        else if((DCM_CONTROLMASK_EXTERNAL == DCM_CFG_DID_CONTROL_MASK(DCM_DID_FOR2E2F_INDEX)) \
                && ((DCM_USE_DATA_SYNCH_FNC == DCM_CFG_DATA_USEPORT(DataRef)) \
                    || (DCM_USE_DATA_SYNCH_CLIENT_SERVER == DCM_CFG_DATA_USEPORT(DataRef))))
        {
            /*return value: E_OK/E_NOT_OK/DCM_E_PENDING*/
            Result = DCM_CFG_DATA_FREEZE_FNC_D(FncIndex)(ControlMask, pErrorCode);
            if(Result != E_OK)
            {
                /*In case the return value is DCM_E_PENDING*/
                Result = E_NOT_OK;
            }
        }
        else
        {
            *pErrorCode = DCM_E_REQUESTOUTOFRANGE;
            Result = E_NOT_OK;
        }
    }
    else if(DCM_REQ_IOCONTROL == DCM_SHORT_TERM_ADJUSTMENT)
    {
        FncIndex = DCM_CFG_DATA_SHORT_FNC_INDEX(DataRef);
        /*SWS_Dcm_00399*/
        /*4U is 0x2F + DID + IOControl*/
        ControlStateInfo = (pMsgContext->reqData + 4U + DataPos);
        /*Only used when data type is DCM_UINT8_DYN,the data must be the last one.*/
        DataLength = (pMsgContext->reqDataLen - 4U - DataPos - \
                      DCM_CFG_DID_CONTROL_MASK_SIZE(DCM_DID_FOR2E2F_INDEX));
        if((DCM_CONTROLMASK_EXTERNAL != DCM_CFG_DID_CONTROL_MASK(DCM_DID_FOR2E2F_INDEX)) \
                && (DCM_UINT8_DYN != DCM_CFG_DATA_TYPE(DataRef)) \
                && ((DCM_USE_DATA_ASYNCH_FNC == DCM_CFG_DATA_USEPORT(DataRef)) \
                    || (DCM_USE_DATA_ASYNCH_FNC_ERROR == DCM_CFG_DATA_USEPORT(DataRef)) \
                    || (DCM_USE_DATA_ASYNCH_CLIENT_SERVER == DCM_CFG_DATA_USEPORT(DataRef)) \
                    || (DCM_USE_DATA_ASYNCH_CLIENT_SERVER_ERROR == DCM_CFG_DATA_USEPORT(DataRef))))
        {
            /*return value: E_OK/E_NOT_OK/DCM_E_PENDING*/
            Result = DCM_CFG_DATA_SHORT_FNC_A(FncIndex)(ControlStateInfo, OpStatus, pErrorCode);
        }
        else if((DCM_CONTROLMASK_EXTERNAL == DCM_CFG_DID_CONTROL_MASK(DCM_DID_FOR2E2F_INDEX)) \
                && (DCM_UINT8_DYN != DCM_CFG_DATA_TYPE(DataRef)) \
                && ((DCM_USE_DATA_ASYNCH_FNC == DCM_CFG_DATA_USEPORT(DataRef)) \
                    || (DCM_USE_DATA_ASYNCH_FNC_ERROR == DCM_CFG_DATA_USEPORT(DataRef)) \
                    || (DCM_USE_DATA_ASYNCH_CLIENT_SERVER == DCM_CFG_DATA_USEPORT(DataRef)) \
                    || (DCM_USE_DATA_ASYNCH_CLIENT_SERVER_ERROR == DCM_CFG_DATA_USEPORT(DataRef))))
        {
            /*return value: E_OK/E_NOT_OK/DCM_E_PENDING*/
            Result = DCM_CFG_DATA_SHORT_FNC_B(FncIndex)(ControlStateInfo, OpStatus, \
                     ControlMask, pErrorCode);
        }
        else if((DCM_CONTROLMASK_EXTERNAL != DCM_CFG_DID_CONTROL_MASK(DCM_DID_FOR2E2F_INDEX)) \
                && (DCM_UINT8_DYN == DCM_CFG_DATA_TYPE(DataRef)) \
                && ((DCM_USE_DATA_ASYNCH_FNC == DCM_CFG_DATA_USEPORT(DataRef)) \
                    || (DCM_USE_DATA_ASYNCH_FNC_ERROR == DCM_CFG_DATA_USEPORT(DataRef)) \
                    || (DCM_USE_DATA_ASYNCH_CLIENT_SERVER == DCM_CFG_DATA_USEPORT(DataRef)) \
                    || (DCM_USE_DATA_ASYNCH_CLIENT_SERVER_ERROR == DCM_CFG_DATA_USEPORT(DataRef))))
        {
            /*return value: E_OK/E_NOT_OK/DCM_E_PENDING*/
            Result = DCM_CFG_DATA_SHORT_FNC_C(FncIndex)(ControlStateInfo, DataLength, \
                     OpStatus, pErrorCode);
        }
        else if((DCM_CONTROLMASK_EXTERNAL == DCM_CFG_DID_CONTROL_MASK(DCM_DID_FOR2E2F_INDEX)) \
                && (DCM_UINT8_DYN == DCM_CFG_DATA_TYPE(DataRef)) \
                && ((DCM_USE_DATA_ASYNCH_FNC == DCM_CFG_DATA_USEPORT(DataRef)) \
                    || (DCM_USE_DATA_ASYNCH_FNC_ERROR == DCM_CFG_DATA_USEPORT(DataRef)) \
                    || (DCM_USE_DATA_ASYNCH_CLIENT_SERVER == DCM_CFG_DATA_USEPORT(DataRef)) \
                    || (DCM_USE_DATA_ASYNCH_CLIENT_SERVER_ERROR == DCM_CFG_DATA_USEPORT(DataRef))))
        {
            /*return value: E_OK/E_NOT_OK/DCM_E_PENDING*/
            Result = DCM_CFG_DATA_SHORT_FNC_D(FncIndex)(ControlStateInfo, DataLength, \
                     OpStatus, ControlMask, pErrorCode);
        }
        else if((DCM_CONTROLMASK_EXTERNAL != DCM_CFG_DID_CONTROL_MASK(DCM_DID_FOR2E2F_INDEX)) \
                && (DCM_UINT8_DYN != DCM_CFG_DATA_TYPE(DataRef)) \
                && ((DCM_USE_DATA_SYNCH_FNC == DCM_CFG_DATA_USEPORT(DataRef)) \
                    || (DCM_USE_DATA_SYNCH_CLIENT_SERVER == DCM_CFG_DATA_USEPORT(DataRef))))
        {
            /*return value: E_OK/E_NOT_OK*/
            Result = DCM_CFG_DATA_SHORT_FNC_E(FncIndex)(ControlStateInfo, pErrorCode);
            if(Result != E_OK)
            {
                /*In case the return value is DCM_E_PENDING*/
                Result = E_NOT_OK;
            }
        }
        else if((DCM_CONTROLMASK_EXTERNAL == DCM_CFG_DID_CONTROL_MASK(DCM_DID_FOR2E2F_INDEX)) \
                && (DCM_UINT8_DYN != DCM_CFG_DATA_TYPE(DataRef)) \
                && ((DCM_USE_DATA_SYNCH_FNC == DCM_CFG_DATA_USEPORT(DataRef)) \
                    || (DCM_USE_DATA_SYNCH_CLIENT_SERVER == DCM_CFG_DATA_USEPORT(DataRef))))
        {
            /*return value: E_OK/E_NOT_OK*/
            Result = DCM_CFG_DATA_SHORT_FNC_F(FncIndex)(ControlStateInfo, ControlMask, pErrorCode);
            if(Result != E_OK)
            {
                /*In case the return value is DCM_E_PENDING*/
                Result = E_NOT_OK;
            }
        }
        else if((DCM_CONTROLMASK_EXTERNAL != DCM_CFG_DID_CONTROL_MASK(DCM_DID_FOR2E2F_INDEX)) \
                && (DCM_UINT8_DYN == DCM_CFG_DATA_TYPE(DataRef)) \
                && ((DCM_USE_DATA_SYNCH_FNC == DCM_CFG_DATA_USEPORT(DataRef)) \
                    || (DCM_USE_DATA_SYNCH_CLIENT_SERVER == DCM_CFG_DATA_USEPORT(DataRef))))
        {
            /*return value: E_OK/E_NOT_OK*/
            Result = DCM_CFG_DATA_SHORT_FNC_G(FncIndex)(ControlStateInfo, DataLength, pErrorCode);
            if(Result != E_OK)
            {
                /*In case the return value is DCM_E_PENDING*/
                Result = E_NOT_OK;
            }
        }
        else if((DCM_CONTROLMASK_EXTERNAL == DCM_CFG_DID_CONTROL_MASK(DCM_DID_FOR2E2F_INDEX)) \
                && (DCM_UINT8_DYN == DCM_CFG_DATA_TYPE(DataRef)) \
                && ((DCM_USE_DATA_SYNCH_FNC == DCM_CFG_DATA_USEPORT(DataRef)) \
                    || (DCM_USE_DATA_SYNCH_CLIENT_SERVER == DCM_CFG_DATA_USEPORT(DataRef))))
        {
            /*return value: E_OK/E_NOT_OK*/
            Result = DCM_CFG_DATA_SHORT_FNC_H(FncIndex)(ControlStateInfo, DataLength, \
                     ControlMask, pErrorCode);
            if(Result != E_OK)
            {
                /*In case the return value is DCM_E_PENDING*/
                Result = E_NOT_OK;
            }
        }
        else
        {
            *pErrorCode = DCM_E_REQUESTOUTOFRANGE;
            Result = E_NOT_OK;
        }
    }
    else
    {
        /*SWS_Dcm_00565*/
        *pErrorCode = DCM_E_REQUESTOUTOFRANGE;
        Result = E_NOT_OK;
    }
    return Result;
}

#if(DCM_CAR_PLATFORM == DCM_NISSAN_PLATFORM)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DspInternal_0x2F_ReadSupportedIdentifier
*
* Description: Read supported identifier of 0x2F service.
*
* Inputs: pMsgContext, pErrorCode
*
* Outputs: None
*
* Return: E_OK, E_NOT_OK
*
* Limitations: Only used to meet nissan specification
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, DCM_CODE) DspInternal_0x2F_ReadSupportedIdentifier
(
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
)
{
    uint16 i;
    uint8 BytePos;
    uint8 BitPos;
    uint8 ResponseData[DCM_RNDS_READ_DATA_LENGTH];
    Std_ReturnType Result = E_OK;
    uint8 DidLowByte = (pMsgContext->reqData[DCM_INDEX_2]);
    uint8 SubData = (pMsgContext->reqData[DCM_INDEX_3]);

    if((pMsgContext->reqDataLen) != DCM_NISSAN_READ_LENGTH)
    {
        /*the correct request length should be 3*/
        *pErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
        Result = E_NOT_OK;
    }
    else if(SubData != DCM_SHORT_TERM_ADJUSTMENT)
    {
        *pErrorCode = DCM_E_REQUESTOUTOFRANGE;
        Result = E_NOT_OK;
    }
    else
    {
        for(i = 0U; i < DCM_RNDS_READ_DATA_LENGTH; i++)
        {
            /*reset the data value with zero*/
            ResponseData[i] = DCM_DATA_CLEAR;
        }

        if(DCM_RNDS_READ_ID_HIGH_BYTE == DidLowByte)
        {
            for(i = (uint16)0; i < DCM_CFG_DID_NUM; i++)
            {
                if((TRUE == DCM_CFG_DID_USED(i)) && (NULL_PTR != DCM_CFG_DID_INFO_CONTROL(i)))
                {
                    BytePos = (uint8)(DCM_CFG_DID_ID(i) >> 11);
                    BitPos = (uint8)((DCM_CFG_DID_ID(i) >> 8) % 8);
                    ResponseData[BytePos] |= ((uint8)0x80 >> BitPos);
                }
            }
        }
        else
        {
            for(i = (uint16)0; i < DCM_CFG_DID_NUM; i++)
            {
                if((TRUE == DCM_CFG_DID_USED(i)) && (NULL_PTR != DCM_CFG_DID_INFO_CONTROL(i)) \
                    && (((DCM_CFG_DID_ID(i) & DCM_RNDS_ID_HIGH_MASK) >> 8) == DidLowByte))
                {
                    BytePos = (uint8)((DCM_CFG_DID_ID(i) & DCM_RNDS_ID_LOW_MASK) / 8);
                    BitPos = (uint8)((DCM_CFG_DID_ID(i) & DCM_RNDS_ID_LOW_MASK) % 8);
                    ResponseData[BytePos] |= ((uint8)0x80 >> BitPos);
                }
            }
        }
    }

    if(Result == E_OK)
    {
        /*Copy the data to the response buffer*/
        Bsw_MemCpy(&(pMsgContext->resData[DCM_INDEX_4]), ResponseData, DCM_RNDS_READ_DATA_LENGTH);

        pMsgContext->resData[DCM_INDEX_1] = pMsgContext->reqData[DCM_INDEX_1];
        pMsgContext->resData[DCM_INDEX_2] = pMsgContext->reqData[DCM_INDEX_2];
        pMsgContext->resData[DCM_INDEX_3] = pMsgContext->reqData[DCM_INDEX_3];
        pMsgContext->resDataLen = (DCM_INDEX_4 + DCM_RNDS_READ_DATA_LENGTH);
    }
    return Result;
}
#endif/*#if(DCM_CAR_PLATFORM == DCM_NISSAN_PLATFORM)*/
#endif

#if(DCM_UDS_31_SERVICE == STD_ON)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DspInternal_31_RoutineControl
*
* Description: The entry function of the 0x31 service
*
* Inputs: OpStatus, pMsgContext, pErrorCode
*
* Outputs: None
*
* Return: Std_ReturnType
*
* Limitations: Only used when 0x31 service is enabled.
********************************************************************************
END_FUNCTION_HDR*/
/*31 Service*//*SWS_Dcm_00257*/
FUNC(Std_ReturnType, DCM_CODE) DspInternal_31_RoutineControl
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
)
{
    Std_ReturnType Result = E_OK;

    uint16 RID;
    uint16 i;
    Dcm_SesRefType SesLevelRef;
#if(DCM_UDS_27_SERVICE == STD_ON)
    Dcm_SecRefType SecLevelRef;
    Dcm_SecRefType CurSecMask = DslInternal_GetSecurityMask();
#endif
    uint8 SupportAddress = DCM_DATA_CLEAR;

#if(DCM_CAR_PLATFORM == DCM_NISSAN_PLATFORM)
    uint8 RidHighByte = (pMsgContext->reqData[DCM_INDEX_2]);

    if(RidHighByte == DCM_RNDS_READ_ID_HIGH_BYTE)
    {
        /*Getting Identifiers supported by the ECU from App*/
        Result = DspInternal_0x31_ReadSupportedIdentifier(pMsgContext, pErrorCode);
    }
    else
    {
#endif
        if(OpStatus == DCM_INITIAL)
        {
    #if(DCM_UDS_31_SUPPORT_SUPPRESSPOSRESBIT != STD_ON)
            ClearSuppressPosRespBit();
    #endif
            RID = Make16Bit(pMsgContext->reqData[DCM_INDEX_2], pMsgContext->reqData[DCM_INDEX_3]);
            Result = E_NOT_OK;
            if(NULL_PTR != DCM_CFG_ROUTINE_INFO)
            {
                for(i = 0U; i < DCM_CFG_ROUTINE_NUM; i++)
                {
                    if((RID == DCM_CFG_ROUTINE_ID(i)) \
                            && (TRUE == DCM_CFG_ROUTINE_USED(i)))
                    {
                        DCM_RID_INDEX = i;
                        Result = E_OK;
                        break;
                    }
                }
            }
            /*SWS_Dcm_01139*/
            if(Result != E_OK)
            {
                /*SWS_Dcm_00568*//*SWS_Dcm_00569*/
                *pErrorCode = DCM_E_REQUESTOUTOFRANGE;
            }
            else
            {
                switch(DCM_REQ_SUBSERVICE)
                {
                    case DCM_START_ROUTINE:
                        if(NULL_PTR == DCM_CFG_ROUTINE_START(DCM_RID_INDEX))
                        {
                            /*SWS_Dcm_00869*/
                            *pErrorCode = DCM_E_SUBFUNCTIONNOTSUPPORTED;
                            Result = E_NOT_OK;
                        }
                        /*check request length*/
                        else if((DCM_VARIABLE_LENGTH != DCM_CFG_ROUTINE_START_IN_TYPE(DCM_RID_INDEX)) \
                                && (pMsgContext->reqDataLen != (4U + DCM_CFG_ROUTINE_START_IN_LEN(DCM_RID_INDEX))))
                        {
                            /*SWS_Dcm_01140*/
                            *pErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
                            Result = E_NOT_OK;
                        }
                        else if(NULL_PTR != DCM_CFG_ROUTINE_START_AUTH(DCM_RID_INDEX))
                        {
                            /*Next step:Address&Session&Security check*/
                            SupportAddress = DCM_CFG_ROUTINE_START_ADDR(DCM_RID_INDEX);
                            SesLevelRef = DCM_CFG_ROUTINE_START_SES(DCM_RID_INDEX);
    #if(DCM_UDS_27_SERVICE == STD_ON)
                            SecLevelRef = DCM_CFG_ROUTINE_START_SEC(DCM_RID_INDEX);
    #endif
    #if(DCM_CAR_PLATFORM == DCM_GEELY_PLATFORM)
                            SetP4Timer(DCM_CFG_ROUTINE_START_P4(DCM_RID_INDEX));
    #endif
                        }
                        else
                        {
                            /*Address&Session&Security don't need check*/
    #if(DCM_CAR_PLATFORM == DCM_GEELY_PLATFORM)
                            SetP4Timer(DCM_CFG_ROUTINE_START_P4(DCM_RID_INDEX));
    #endif
                        }
                        break;

                    case DCM_STOP_ROUTINE:
                        if(NULL_PTR == DCM_CFG_ROUTINE_STOP(DCM_RID_INDEX))
                        {
                            /*SWS_Dcm_00869*/
                            *pErrorCode = DCM_E_SUBFUNCTIONNOTSUPPORTED;
                            Result = E_NOT_OK;
                        }
                        /*check request length*/
                        else if((DCM_VARIABLE_LENGTH != DCM_CFG_ROUTINE_STOP_IN_TYPE(DCM_RID_INDEX)) \
                                && (pMsgContext->reqDataLen != (4U + DCM_CFG_ROUTINE_STOP_IN_LEN(DCM_RID_INDEX))))
                        {
                            /*SWS_Dcm_01140*/
                            *pErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
                            Result = E_NOT_OK;
                        }
                        else if(NULL_PTR != DCM_CFG_ROUTINE_STOP_AUTH(DCM_RID_INDEX))
                        {
                            /*Next step:Address&Session&Security check*/
                            SupportAddress = DCM_CFG_ROUTINE_STOP_ADDR(DCM_RID_INDEX);
                            SesLevelRef = DCM_CFG_ROUTINE_STOP_SES(DCM_RID_INDEX);
    #if(DCM_UDS_27_SERVICE == STD_ON)
                            SecLevelRef = DCM_CFG_ROUTINE_STOP_SEC(DCM_RID_INDEX);
    #endif
    #if(DCM_CAR_PLATFORM == DCM_GEELY_PLATFORM)
                            SetP4Timer(DCM_CFG_ROUTINE_STOP_P4(DCM_RID_INDEX));
    #endif
                        }
                        else
                        {
                            /*Address&Session&Security don't need check*/
    #if(DCM_CAR_PLATFORM == DCM_GEELY_PLATFORM)
                            SetP4Timer(DCM_CFG_ROUTINE_STOP_P4(DCM_RID_INDEX));
    #endif
                        }
                        break;

                    case DCM_REQUEST_ROUTINE_RESULTS:
                        if(NULL_PTR == DCM_CFG_ROUTINE_RESULT(DCM_RID_INDEX))
                        {
                            /*SWS_Dcm_00869*/
                            *pErrorCode = DCM_E_SUBFUNCTIONNOTSUPPORTED;
                            Result = E_NOT_OK;
                        }
                        /*check request length*/
                        else if(pMsgContext->reqDataLen != 4U)
                        {
                            /*SWS_Dcm_01140*/
                            *pErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
                            Result = E_NOT_OK;
                        }
                        else if(NULL_PTR != DCM_CFG_ROUTINE_RESULT_AUTH(DCM_RID_INDEX))
                        {
                            /*Next step:Address&Session&Security check*/
                            SupportAddress = DCM_CFG_ROUTINE_RESULT_ADDR(DCM_RID_INDEX);
                            SesLevelRef = DCM_CFG_ROUTINE_RESULT_SES(DCM_RID_INDEX);
    #if(DCM_UDS_27_SERVICE == STD_ON)
                            SecLevelRef = DCM_CFG_ROUTINE_RESULT_SEC(DCM_RID_INDEX);
    #endif
    #if(DCM_CAR_PLATFORM == DCM_GEELY_PLATFORM)
                            SetP4Timer(DCM_CFG_ROUTINE_RESULT_P4(DCM_RID_INDEX));
    #endif
                        }
                        else
                        {
                            /*Address&Session&Security don't need check*/
    #if(DCM_CAR_PLATFORM == DCM_GEELY_PLATFORM)
                            SetP4Timer(DCM_CFG_ROUTINE_RESULT_P4(DCM_RID_INDEX));
    #endif
                        }
                        break;
                        
                    default:
                        *pErrorCode = DCM_E_SUBFUNCTIONNOTSUPPORTED;
                        Result = E_NOT_OK;
                        break;
                }
            }
            /*Address&Session&Security check*/
            if((Result == E_OK) && (SupportAddress != DCM_DATA_CLEAR))
            {
                if(!(SupportAddress & (((uint8)0x01) << (pMsgContext->msgAddInfo.reqType))))
                {
                    *pErrorCode = DCM_E_REQUESTOUTOFRANGE;
                    Result = E_NOT_OK;
                }
                else if(!(DCM_CFG_SESSION_MASK(DCM_SESSION_LEVEL) & SesLevelRef))
                {
                    /*SWS_Dcm_00570*/
                    *pErrorCode = DCM_E_REQUESTOUTOFRANGE;
                    Result = E_NOT_OK;
                }
    #if(DCM_UDS_27_SERVICE == STD_ON)
                else if(!(CurSecMask & SecLevelRef))
                {
                    /*SWS_Dcm_00571*/
                    *pErrorCode = DCM_E_SECURITYACCESSDENIED;
                    Result = E_NOT_OK;
                }
    #endif
                else
                {
                    /*Next step:Sub service process*/
                }
            }
            /*check routine sequence*/
            if(Result == E_OK)
            {
                if((DCM_REQ_SUBSERVICE == DCM_STOP_ROUTINE) \
                    && (DCM_ROUTINE_STARTED != DCM_RID_STATUS(DCM_RID_INDEX)))
                {
                    *pErrorCode = DCM_E_REQUESTSEQUENCEERROR;
                    Result = E_NOT_OK;
                }
                else if((DCM_REQ_SUBSERVICE == DCM_REQUEST_ROUTINE_RESULTS) \
                    && (DCM_ROUTINE_NONE == DCM_RID_STATUS(DCM_RID_INDEX)))
                {
                    *pErrorCode = DCM_E_REQUESTSEQUENCEERROR;
                    Result = E_NOT_OK;
                }
                else
                {
                    /*do nothing*/
                }
            }
        }/*if(OpStatus == DCM_INITIAL)*/
        /*Sub service process*/
        if(Result == E_OK)
        {
            Result = DspInternal_31_Sub_Processor(OpStatus, pMsgContext, pErrorCode);
        }
        /*Creat the positive response*/
        if(Result == E_OK)
        {
            if(DCM_REQ_SUBSERVICE == DCM_START_ROUTINE)
            {
                DCM_RID_STATUS(DCM_RID_INDEX) = DCM_ROUTINE_STARTED;
            }
            else if(DCM_REQ_SUBSERVICE == DCM_STOP_ROUTINE)
            {
                DCM_RID_STATUS(DCM_RID_INDEX) = DCM_ROUTINE_STOPPED;
            }
            else
            {
                /*do nothing*/
            }
            pMsgContext->resData[DCM_SUB_SID_INDEX] = DCM_REQ_SUBSERVICE;
            pMsgContext->resData[DCM_INDEX_2] = pMsgContext->reqData[DCM_INDEX_2];
            pMsgContext->resData[DCM_INDEX_3] = pMsgContext->reqData[DCM_INDEX_3];
        }
#if(DCM_CAR_PLATFORM == DCM_NISSAN_PLATFORM)
    }
#endif
    return Result;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name:
*
* Description:
*
* Inputs:
*
* Outputs:
*
* Return:
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, DCM_CODE) DspInternal_31_Sub_Processor
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
)
{
    Std_ReturnType Result = E_OK;
    uint8 *DataIn = &(pMsgContext->reqData[DCM_INDEX_4]);
    uint8 *DataOut = &(pMsgContext->resData[DCM_INDEX_4]);
    uint16 currentDataLength = (pMsgContext->reqDataLen - 4U);
    uint16 FncIndex;

    switch(DCM_REQ_SUBSERVICE)
    {
        case DCM_START_ROUTINE:
            FncIndex = DCM_CFG_ROUTINE_START_FNC_INDEX(DCM_RID_INDEX);
            /*SWS_Dcm_00400*//*SWS_Dcm_00401*/
            if((DCM_VARIABLE_LENGTH != DCM_CFG_ROUTINE_START_IN_TYPE(DCM_RID_INDEX)) \
                    && (DCM_VARIABLE_LENGTH != DCM_CFG_ROUTINE_START_OUT_TYPE(DCM_RID_INDEX)))
            {
                Result = DCM_CFG_ROUTINE_START_FNC_A(FncIndex)(DataIn, OpStatus, \
                         DataOut, pErrorCode);
                currentDataLength = DCM_CFG_ROUTINE_START_OUT_LEN(DCM_RID_INDEX);
            }
            else if(DCM_VARIABLE_LENGTH != DCM_CFG_ROUTINE_START_IN_TYPE(DCM_RID_INDEX))
            {
                Result = DCM_CFG_ROUTINE_START_FNC_B(FncIndex)(DataIn, OpStatus, \
                         DataOut, &currentDataLength, pErrorCode);
            }
            else if(DCM_VARIABLE_LENGTH != DCM_CFG_ROUTINE_START_OUT_TYPE(DCM_RID_INDEX))
            {
                Result = DCM_CFG_ROUTINE_START_FNC_C(FncIndex)(DataIn, OpStatus, \
                         DataOut, currentDataLength, pErrorCode);
                currentDataLength = DCM_CFG_ROUTINE_START_OUT_LEN(DCM_RID_INDEX);
            }
            else/*((DCM_VARIABLE_LENGTH == DCM_CFG_ROUTINE_START_IN_TYPE(DCM_RID_INDEX)) \
                    && (DCM_VARIABLE_LENGTH == DCM_CFG_ROUTINE_START_OUT_TYPE(DCM_RID_INDEX)))*/
            {
                Result = DCM_CFG_ROUTINE_START_FNC_D(FncIndex)(DataIn, OpStatus, \
                         DataOut, &currentDataLength, pErrorCode);
            }
            break;

        case DCM_STOP_ROUTINE:
            FncIndex = DCM_CFG_ROUTINE_STOP_FNC_INDEX(DCM_RID_INDEX);
            /*SWS_Dcm_00402*//*SWS_Dcm_00403*/
            if((DCM_VARIABLE_LENGTH != DCM_CFG_ROUTINE_STOP_IN_TYPE(DCM_RID_INDEX)) \
                    && (DCM_VARIABLE_LENGTH != DCM_CFG_ROUTINE_STOP_OUT_TYPE(DCM_RID_INDEX)))
            {
                Result = DCM_CFG_ROUTINE_STOP_FNC_A(FncIndex)(DataIn, OpStatus, \
                         DataOut, pErrorCode);
                currentDataLength = DCM_CFG_ROUTINE_STOP_OUT_LEN(DCM_RID_INDEX);
            }
            else if(DCM_VARIABLE_LENGTH != DCM_CFG_ROUTINE_STOP_IN_TYPE(DCM_RID_INDEX))
            {
                Result = DCM_CFG_ROUTINE_STOP_FNC_B(FncIndex)(DataIn, OpStatus, \
                         DataOut, &currentDataLength, pErrorCode);
            }
            else if(DCM_VARIABLE_LENGTH != DCM_CFG_ROUTINE_STOP_OUT_TYPE(DCM_RID_INDEX))
            {
                Result = DCM_CFG_ROUTINE_STOP_FNC_C(FncIndex)(DataIn, OpStatus, \
                         DataOut, currentDataLength, pErrorCode);
                currentDataLength = DCM_CFG_ROUTINE_STOP_OUT_LEN(DCM_RID_INDEX);
            }
            else/*((DCM_VARIABLE_LENGTH == DCM_CFG_ROUTINE_STOP_IN_TYPE(DCM_RID_INDEX)) \
                    && (DCM_VARIABLE_LENGTH == DCM_CFG_ROUTINE_STOP_OUT_TYPE(DCM_RID_INDEX)))*/
            {
                Result = DCM_CFG_ROUTINE_STOP_FNC_D(FncIndex)(DataIn, OpStatus, \
                         DataOut, &currentDataLength, pErrorCode);
            }
            break;

        default:/*DCM_REQUEST_ROUTINE_RESULTS*/
            FncIndex = DCM_CFG_ROUTINE_RESULT_FNC_INDEX(DCM_RID_INDEX);
            /*SWS_Dcm_00404*//*SWS_Dcm_00405*/
            if(DCM_VARIABLE_LENGTH != DCM_CFG_ROUTINE_RESULT_TYPE(DCM_RID_INDEX))
            {
                Result = DCM_CFG_ROUTINE_RESULT_FNC_A(FncIndex)(OpStatus, \
                         DataOut, pErrorCode);
                currentDataLength = DCM_CFG_ROUTINE_RESULT_LEN(DCM_RID_INDEX);
            }
            else/*(DCM_VARIABLE_LENGTH == DCM_CFG_ROUTINE_RESULT_TYPE(DCM_RID_INDEX))*/
            {
                Result = DCM_CFG_ROUTINE_RESULT_FNC_B(FncIndex)(OpStatus, \
                         DataOut, &currentDataLength, pErrorCode);
            }
            break;
    }
    /*Calculate the positive response*/
    if(Result == E_OK)
    {
        (pMsgContext->resDataLen) = (4U + currentDataLength);
    }
    return Result;
}

#if(DCM_CAR_PLATFORM == DCM_NISSAN_PLATFORM)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DspInternal_0x31_ReadSupportedIdentifier
*
* Description: Read supported identifier of 0x31 service.
*
* Inputs: pMsgContext, pErrorCode
*
* Outputs: None
*
* Return: E_OK, E_NOT_OK
*
* Limitations: Only used to meet nissan specification
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, DCM_CODE) DspInternal_0x31_ReadSupportedIdentifier
(
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
)
{
    uint16 i;
    uint8 BytePos;
    uint8 BitPos;
    uint8 ResponseData[DCM_RNDS_READ_DATA_LENGTH];
    Std_ReturnType Result = E_OK;
    uint8 RidLowByte = (pMsgContext->reqData[DCM_INDEX_3]);
    uint8 SubData = (pMsgContext->reqData[DCM_INDEX_1]);

    if((pMsgContext->reqDataLen) != DCM_NISSAN_READ_LENGTH)
    {
        /*the correct request length should be 4*/
        *pErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
        Result = E_NOT_OK;
    }
    else if(SubData != DCM_START_ROUTINE)
    {
        *pErrorCode = DCM_E_REQUESTOUTOFRANGE;
        Result = E_NOT_OK;
    }
    else
    {
        for(i = 0U; i < DCM_RNDS_READ_DATA_LENGTH; i++)
        {
            /*reset the data value with zero*/
            ResponseData[i] = DCM_DATA_CLEAR;
        }

        if(DCM_RNDS_READ_ID_HIGH_BYTE == RidLowByte)
        {
            for(i = (uint16)0; i < DCM_CFG_ROUTINE_NUM; i++)
            {
                if(TRUE == DCM_CFG_ROUTINE_USED(i))
                {
                    BytePos = (uint8)(DCM_CFG_ROUTINE_ID(i) >> 11);
                    BitPos = (uint8)((DCM_CFG_ROUTINE_ID(i) >> 8) % 8);
                    ResponseData[BytePos] |= ((uint8)0x80 >> BitPos);
                }
            }
        }
        else
        {
            for(i = (uint16)0; i < DCM_CFG_ROUTINE_NUM; i++)
            {
                if((TRUE == DCM_CFG_ROUTINE_USED(i)) \
                    && (((DCM_CFG_ROUTINE_ID(i) & DCM_RNDS_ID_HIGH_MASK) >> 8) == RidLowByte))
                {
                    BytePos = (uint8)((DCM_CFG_ROUTINE_ID(i) & DCM_RNDS_ID_LOW_MASK) / 8);
                    BitPos = (uint8)((DCM_CFG_ROUTINE_ID(i) & DCM_RNDS_ID_LOW_MASK) % 8);
                    ResponseData[BytePos] |= ((uint8)0x80 >> BitPos);
                }
            }
        }
    }

    if(Result == E_OK)
    {
        /*Copy the data to the response buffer*/
        Bsw_MemCpy(&(pMsgContext->resData[DCM_INDEX_4]), ResponseData, DCM_RNDS_READ_DATA_LENGTH);

        pMsgContext->resData[DCM_INDEX_1] = pMsgContext->reqData[DCM_INDEX_1];
        pMsgContext->resData[DCM_INDEX_2] = pMsgContext->reqData[DCM_INDEX_2];
        pMsgContext->resData[DCM_INDEX_3] = pMsgContext->reqData[DCM_INDEX_3];
        pMsgContext->resDataLen = (DCM_INDEX_4 + DCM_RNDS_READ_DATA_LENGTH);
    }
    return Result;
}
#endif/*#if(DCM_CAR_PLATFORM == DCM_NISSAN_PLATFORM)*/

#endif

#if(DCM_UDS_34_SERVICE == STD_ON)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DspInternal_34_RequestDownload
*
* Description: Processing function of UDS 0x34 service.
*
* Inputs: OpStatus,pMsgContext
*
* Outputs: pMsgContext,pErrorCode
*
* Return: Std_ReturnType
*
* Limitations: Only used by UDS 0x34 service
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, DCM_CODE) DspInternal_34_RequestDownload
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
)
{
    Std_ReturnType Result = E_OK;

    Dcm_SesRefType SesLevelRef;
#if(DCM_UDS_27_SERVICE == STD_ON)
    Dcm_SecRefType SecLevelRef;
    Dcm_SecRefType CurSecMask;
#endif

    uint8 AddrSizeFormat;
    uint8 AddrLength;
    uint8 SizeLength;
    uint8 i;
    uint16 j;
    uint32 MaxNumberOfBlockLength;

    if(OpStatus == DCM_INITIAL)
    {
        DCM_DOWN_UP_LOAD_MA = DCM_DATA_CLEAR;
        DCM_DOWN_UP_LOAD_MS = DCM_DATA_CLEAR;
        DCM_DOWN_UP_LOAD_MI = DCM_DATA_CLEAR;
        DCM_DOWN_UP_LOAD_STATUS = DCM_LOAD_NONE;
        DCM_DOWN_UP_LOAD_MNOBFWRM = DCM_DATA_CLEAR;
        DCM_DOWN_UP_LOAD_DFI = (pMsgContext->reqData[DCM_INDEX_1]);
        AddrSizeFormat = (pMsgContext->reqData[DCM_INDEX_2]);
        AddrLength = (AddrSizeFormat & (0x0FU));
        SizeLength = ((AddrSizeFormat & (0xF0U)) >> 4U);
        /*SWS_Dcm_00856,Check addressAndLengthFormatIdentifier*/
        if((AddrLength == DCM_DATA_CLEAR) || (SizeLength == DCM_DATA_CLEAR))
        {
            Result = E_NOT_OK;
        }
        else if(DCM_CFG_MEM_FORMAT_NUM != DCM_DATA_CLEAR)
        {
            Result = E_NOT_OK;
            for(i = 0U; i < DCM_CFG_MEM_FORMAT_NUM; i++)
            {
                if(AddrSizeFormat == DCM_CFG_MEM_FORMAT(i))
                {
                    Result = E_OK;
                    break;
                }
            }
        }
        else
        {
            /*Dcm shall accept all possible AddressAndLengthFormatIdentifiers.*/
        }

        if(Result == E_NOT_OK)
        {
            /*SWS_Dcm_00856*/
            *pErrorCode = DCM_E_REQUESTOUTOFRANGE;
            Result = E_NOT_OK;
        }
        else if(pMsgContext->reqDataLen != (DCM_INDEX_3 + AddrLength + SizeLength))
        {
            /*Full length check*/
            *pErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
            Result = E_NOT_OK;
        }
        else
        {
            /* Calculate start address */
            for(i = 0U; i < AddrLength; i++)
            {
                DCM_DOWN_UP_LOAD_MA |= (uint32)(pMsgContext->reqData[DCM_INDEX_3 + i]) << \
                                       (uint8)(8U * (AddrLength - 1U - i));
            }
            /* Calculate size */
            for(i = 0U; i < SizeLength; i++)
            {
                DCM_DOWN_UP_LOAD_MS |= (uint32)(pMsgContext->reqData[DCM_INDEX_3 + AddrLength + i]) << \
                                       (uint8)(8U * (SizeLength - 1U - i));
            }
            /*Memory length check*/
            if(DCM_DOWN_UP_LOAD_MS == DCM_DATA_CLEAR)
            {
                /*NRC TBD*/
                *pErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
                Result = E_NOT_OK;
            }
            else
            {
                /*check memory range & security & session*/
            }
        }
        /*check memory range & security & session*/
        if(Result == E_OK)
        {
            Result = E_NOT_OK;
            /*SWS_Dcm_01057*/
            for(i = 0U; i < DCM_CFG_MEM_ID_NUM; i++)
            {
                for(j = 0U; j < DCM_CFG_MEM_ID_WRITE_NUM(i); j++)
                {
                    if((DCM_DOWN_UP_LOAD_MA <= DCM_CFG_MEM_ID_WRITE_HIGH(i, j)) \
                        && (DCM_DOWN_UP_LOAD_MA >= DCM_CFG_MEM_ID_WRITE_LOW(i, j)) \
                        && ((DCM_DOWN_UP_LOAD_MA + DCM_DOWN_UP_LOAD_MS - 1U) <= DCM_CFG_MEM_ID_WRITE_HIGH(i, j)))
                    {
                        Result = E_OK;
                        break;
                    }
                }

                if(Result == E_OK)
                {
                    DCM_DOWN_UP_LOAD_MI = DCM_CFG_MEM_ID_VALUE(i);
                    break;
                }
            }

            if(Result != E_OK)
            {
                *pErrorCode = DCM_E_REQUESTOUTOFRANGE;
            }
            else
            {
                /*check security & session*/
                SesLevelRef = DCM_CFG_MEM_ID_WRITE_SESREF(i, j);
#if(DCM_UDS_27_SERVICE == STD_ON)
                SecLevelRef = DCM_CFG_MEM_ID_WRITE_SECREF(i, j);
                CurSecMask = DslInternal_GetSecurityMask();;
#endif
                if(!(DCM_CFG_SESSION_MASK(DCM_SESSION_LEVEL) & SesLevelRef))
                {
                    *pErrorCode = DCM_E_REQUESTOUTOFRANGE;
                    Result = E_NOT_OK;
                }
#if(DCM_UDS_27_SERVICE == STD_ON)
                else if(!(CurSecMask & SecLevelRef))
                {
                    *pErrorCode = DCM_E_SECURITYACCESSDENIED;
                    Result = E_NOT_OK;
                }
#endif
                else
                {
                    /*Call Dcm_ProcessRequestDownload()*/
                }
            }
        }
    }/*if(OpStatus == DCM_INITIAL)*/

    if(Result == E_OK)
    {
        /*SWS_Dcm_01132*//*SWS_Dcm_00757*/
        Result = Dcm_ProcessRequestDownload(OpStatus, DCM_DOWN_UP_LOAD_DFI, DCM_DOWN_UP_LOAD_MA, \
                        DCM_DOWN_UP_LOAD_MS, &DCM_DOWN_UP_LOAD_MNOBFWRM, pErrorCode);

        if(Result == E_OK)
        {
            DCM_DOWN_UP_LOAD_STATUS = DCM_LOAD_DOWN;
            DCM_DOWN_UP_LOAD_PRE_BSC = DCM_BSC_INIT_VALUE;
            DCM_DOWN_UP_LOAD_NEXT_BSC = DCM_BSC_INIT_VALUE;
            /*MaxNumberOfBlockLength in positive response reflects the complete message length, including the service
            identifier and the data-parameters present in the TransferData request message,*/
            MaxNumberOfBlockLength = DCM_DOWN_UP_LOAD_MNOBFWRM + 2U;
            /*Creat the response data*/
            pMsgContext->resData[DCM_INDEX_1] = 0x40U;/*Length format identifier*/
            pMsgContext->resData[DCM_INDEX_2] = (uint8)(MaxNumberOfBlockLength >> 24);
            pMsgContext->resData[DCM_INDEX_3] = (uint8)(MaxNumberOfBlockLength >> 16);
            pMsgContext->resData[DCM_INDEX_4] = (uint8)(MaxNumberOfBlockLength >> 8);
            pMsgContext->resData[DCM_INDEX_5] = (uint8)MaxNumberOfBlockLength;
            pMsgContext->resDataLen = 6U;
        }
    }

    return Result;
}
#endif

#if((DCM_UDS_34_SERVICE == STD_ON) || (DCM_UDS_3D_SERVICE == STD_ON))
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DspInternal_WriteMemory
*
* Description: Call the Dcm_WriteMemory() function and change the return value to
*              Std_ReturnType.
*
* Inputs: OpStatus,MemoryIdentifier,MemoryAddress,MemorySize,MemoryData
*
* Outputs: pErrorCode
*
* Return: Std_ReturnType
*
* Limitations: Used for writing memory
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, DCM_CODE) DspInternal_WriteMemory
(
    Dcm_OpStatusType OpStatus,
    uint8 MemoryIdentifier,
    uint32 MemoryAddress,
    uint32 MemorySize,
    uint8* MemoryData,
    Dcm_NegativeResponseCodeType* ErrorCode
)
{
    Std_ReturnType Result = E_OK;
    Dcm_ReturnWriteMemoryType WriteResult = DCM_WRITE_OK;

    WriteResult = Dcm_WriteMemory(OpStatus, MemoryIdentifier, MemoryAddress, MemorySize, MemoryData, ErrorCode);

    switch(WriteResult)
    {
        case DCM_WRITE_OK:
            Result = E_OK;
        break;

        case DCM_WRITE_PENDIN:
            Result = DCM_E_PENDING;
        break;

        case DCM_WRITE_FAILED:
            Result = E_NOT_OK;
        break;

        case DCM_WRITE_FORCE_RCRRP:
            Result = DCM_E_FORCE_RCRRP;
        break;

        default:
            *ErrorCode = DCM_E_GENERALREJECT;
            Result = E_NOT_OK;
        break;
    }

    return Result;
}
#endif

#if((DCM_UDS_23_SERVICE == STD_ON) || (DCM_UDS_35_SERVICE == STD_ON))
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DspInternal_WriteMemory
*
* Description: Call the Dcm_ReadMemory() function and change the return value to
*              Std_ReturnType.
*
* Inputs: OpStatus,MemoryIdentifier,MemoryAddress,MemorySize
*
* Outputs: MemoryData,pErrorCode
*
* Return: Std_ReturnType
*
* Limitations: Used for reading memory
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, DCM_CODE) DspInternal_ReadMemory
(
    Dcm_OpStatusType OpStatus,
    uint8 MemoryIdentifier,
    uint32 MemoryAddress,
    uint32 MemorySize,
    uint8* MemoryData,
    Dcm_NegativeResponseCodeType* ErrorCode
)
{
    Std_ReturnType Result = E_OK;
    Dcm_ReturnReadMemoryType ReadResult = DCM_READ_OK;

    ReadResult = Dcm_ReadMemory(OpStatus, MemoryIdentifier, MemoryAddress, MemorySize, MemoryData, ErrorCode);

    switch(ReadResult)
    {
        case DCM_READ_OK:
            Result = E_OK;
        break;

        case DCM_READ_PENDIN:
            Result = DCM_E_PENDING;
        break;

        case DCM_READ_FAILED:
            Result = E_NOT_OK;
        break;

        case DCM_READ_FORCE_RCRRP:
            Result = DCM_E_FORCE_RCRRP;
        break;

        default:
            *ErrorCode = DCM_E_GENERALREJECT;
            Result = E_NOT_OK;
        break;
    }

    return Result;
}
#endif

#if(DCM_UDS_35_SERVICE == STD_ON)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DspInternal_35_RequestUpload
*
* Description: Processing function of UDS 0x35 service.
*
* Inputs: OpStatus,pMsgContext
*
* Outputs: pMsgContext,pErrorCode
*
* Return: Std_ReturnType
*
* Limitations: Only used by UDS 0x35 service
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, DCM_CODE) DspInternal_35_RequestUpload
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
)
{
    Std_ReturnType Result = E_OK;

    Dcm_SesRefType SesLevelRef;
#if(DCM_UDS_27_SERVICE == STD_ON)
    Dcm_SecRefType SecLevelRef;
    Dcm_SecRefType CurSecMask;
#endif

    uint8 AddrSizeFormat;
    uint8 AddrLength;
    uint8 SizeLength;
    uint8 i;
    uint16 j;
    uint32 MaxNumberOfBlockLength;

    if(OpStatus == DCM_INITIAL)
    {
        DCM_DOWN_UP_LOAD_MA = DCM_DATA_CLEAR;
        DCM_DOWN_UP_LOAD_MS = DCM_DATA_CLEAR;
        DCM_DOWN_UP_LOAD_MI = DCM_DATA_CLEAR;
        DCM_DOWN_UP_LOAD_STATUS = DCM_LOAD_NONE;
        DCM_DOWN_UP_LOAD_MNOBFWRM = DCM_DATA_CLEAR;
        DCM_DOWN_UP_LOAD_DFI = (pMsgContext->reqData[DCM_INDEX_1]);
        AddrSizeFormat = (pMsgContext->reqData[DCM_INDEX_2]);
        AddrLength = (AddrSizeFormat & (0x0FU));
        SizeLength = ((AddrSizeFormat & (0xF0U)) >> 4U);
        /*SWS_Dcm_00857, Check addressAndLengthFormatIdentifier*/
        if((AddrLength == DCM_DATA_CLEAR) || (SizeLength == DCM_DATA_CLEAR))
        {
            Result = E_NOT_OK;
        }
        else if(DCM_CFG_MEM_FORMAT_NUM != DCM_DATA_CLEAR)
        {
            Result = E_NOT_OK;
            for(i = 0U; i < DCM_CFG_MEM_FORMAT_NUM; i++)
            {
                if(AddrSizeFormat == DCM_CFG_MEM_FORMAT(i))
                {
                    Result = E_OK;
                    break;
                }
            }
        }
        else
        {
            /*Dcm shall accept all possible AddressAndLengthFormatIdentifiers.*/
        }

        if(Result == E_NOT_OK)
        {
            /*SWS_Dcm_00857*/
            *pErrorCode = DCM_E_REQUESTOUTOFRANGE;
            Result = E_NOT_OK;
        }
        else if(pMsgContext->reqDataLen != (DCM_INDEX_3 + AddrLength + SizeLength))
        {
            /*Full length check*/
            *pErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
            Result = E_NOT_OK;
        }
        else
        {
            /* Calculate start address */
            for(i = 0U; i < AddrLength; i++)
            {
                DCM_DOWN_UP_LOAD_MA |= (uint32)(pMsgContext->reqData[DCM_INDEX_3 + i]) << \
                                       (uint8)(8U * (AddrLength - 1U - i));
            }
            /* Calculate size */
            for(i = 0U; i < SizeLength; i++)
            {
                DCM_DOWN_UP_LOAD_MS |= (uint32)(pMsgContext->reqData[DCM_INDEX_3 + AddrLength + i]) << \
                                       (uint8)(8U * (SizeLength - 1U - i));
            }
            /*Memory length check*/
            if(DCM_DOWN_UP_LOAD_MS == DCM_DATA_CLEAR)
            {
                /*NRC 0x31*/
                *pErrorCode = DCM_E_REQUESTOUTOFRANGE;
                Result = E_NOT_OK;
            }
            else
            {
                /*check memory range & security & session*/
            }
        }
        /*check memory range & security & session*/
        if(Result == E_OK)
        {
            Result = E_NOT_OK;
            /*SWS_Dcm_01055*/
            for(i = 0U; i < DCM_CFG_MEM_ID_NUM; i++)
            {
                for(j = 0U; j < DCM_CFG_MEM_ID_READ_NUM(i); j++)
                {
                    if((DCM_DOWN_UP_LOAD_MA <= DCM_CFG_MEM_ID_READ_HIGH(i, j)) \
                        && (DCM_DOWN_UP_LOAD_MA >= DCM_CFG_MEM_ID_READ_LOW(i, j)) \
                        && ((DCM_DOWN_UP_LOAD_MA + DCM_DOWN_UP_LOAD_MS - 1U) <= DCM_CFG_MEM_ID_READ_HIGH(i, j)))
                    {
                        Result = E_OK;
                        break;
                    }
                }

                if(Result == E_OK)
                {
                    DCM_DOWN_UP_LOAD_MI = DCM_CFG_MEM_ID_VALUE(i);
                    break;
                }
            }

            if(Result != E_OK)
            {
                *pErrorCode = DCM_E_REQUESTOUTOFRANGE;
            }
            else
            {
                /*check security & session*/
                SesLevelRef = DCM_CFG_MEM_ID_READ_SESREF(i, j);
#if(DCM_UDS_27_SERVICE == STD_ON)
                SecLevelRef = DCM_CFG_MEM_ID_READ_SECREF(i, j);
                CurSecMask = DslInternal_GetSecurityMask();;
#endif
                if(!(DCM_CFG_SESSION_MASK(DCM_SESSION_LEVEL) & SesLevelRef))
                {
                    *pErrorCode = DCM_E_REQUESTOUTOFRANGE;
                    Result = E_NOT_OK;
                }
#if(DCM_UDS_27_SERVICE == STD_ON)
                else if(!(CurSecMask & SecLevelRef))
                {
                    *pErrorCode = DCM_E_SECURITYACCESSDENIED;
                    Result = E_NOT_OK;
                }
#endif
                else
                {
                    /*Call Dcm_ProcessRequestUpload()*/
                }
            }
        }
    }/*if(OpStatus == DCM_INITIAL)*/

    if(Result == E_OK)
    {
        /*SWS_Dcm_01133*//*SWS_Dcm_00758*/
        Result = Dcm_ProcessRequestUpload(OpStatus, DCM_DOWN_UP_LOAD_DFI, DCM_DOWN_UP_LOAD_MA, \
                        DCM_DOWN_UP_LOAD_MS, &DCM_DOWN_UP_LOAD_MNOBFWRM, pErrorCode);

        if(Result == E_OK)
        {
            DCM_DOWN_UP_LOAD_STATUS = DCM_LOAD_UP;
            DCM_DOWN_UP_LOAD_PRE_BSC = DCM_BSC_INIT_VALUE;
            DCM_DOWN_UP_LOAD_NEXT_BSC = DCM_BSC_INIT_VALUE;
            /*MaxNumberOfBlockLength in positive response reflects the complete message length, including the service
            identifier and the data-parameters present in the TransferData request message,*/
            MaxNumberOfBlockLength = DCM_DOWN_UP_LOAD_MNOBFWRM + 2U;
            /*Creat the response data*/
            pMsgContext->resData[DCM_INDEX_1] = 0x40U;/*Length format identifier*/
            pMsgContext->resData[DCM_INDEX_2] = (uint8)(MaxNumberOfBlockLength >> 24);
            pMsgContext->resData[DCM_INDEX_3] = (uint8)(MaxNumberOfBlockLength >> 16);
            pMsgContext->resData[DCM_INDEX_4] = (uint8)(MaxNumberOfBlockLength >> 8);
            pMsgContext->resData[DCM_INDEX_5] = (uint8)MaxNumberOfBlockLength;
            pMsgContext->resDataLen = 6U;
        }
    }

    return Result;
}
#endif

#if(DCM_UDS_36_SERVICE == STD_ON)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DspInternal_36_TransferData
*
* Description: Processing function of UDS 0x36 service.
*
* Inputs: OpStatus,pMsgContext
*
* Outputs: pMsgContext,pErrorCode
*
* Return: Std_ReturnType
*
* Limitations: Only used by UDS 0x36 service
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, DCM_CODE) DspInternal_36_TransferData
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
)
{
    Std_ReturnType Result = E_OK;
    uint32 DataSize = DCM_DATA_CLEAR;

    if(OpStatus == DCM_INITIAL)
    {
#if(DCM_UDS_34_SERVICE == STD_ON)
        if(DCM_DOWN_UP_LOAD_STATUS == DCM_LOAD_DOWN)
        {
            /*If the RequestDownload service is active, but the server has already received all data, the NRC24 should be sent.*/
            if((DCM_DOWN_UP_LOAD_MS == DCM_DATA_CLEAR) && ((pMsgContext->reqData[DCM_INDEX_1]) != DCM_DOWN_UP_LOAD_PRE_BSC))
            {
                /*Sequence error*/
                *pErrorCode = DCM_E_REQUESTSEQUENCEERROR;
                Result = E_NOT_OK;
            }
            /*Check if the received block sequence counter equals to the expected value.*/
            else if(((pMsgContext->reqData[DCM_INDEX_1]) != DCM_DOWN_UP_LOAD_NEXT_BSC) \
                && ((pMsgContext->reqData[DCM_INDEX_1]) != DCM_DOWN_UP_LOAD_PRE_BSC))
            {
                /*SWS_Dcm_00645*/
                *pErrorCode = DCM_E_WRONGBLOCKSEQUENCECOUNTER;
                Result = E_NOT_OK;
            }
            else if(DCM_DOWN_UP_LOAD_MS > DCM_DOWN_UP_LOAD_MNOBFWRM)
            {
                /*If the message is not the last frame, the data length should equal to the
                MaxNumberOfBlockLength returned in the positive response to the 0x34 service.*/
                if((pMsgContext->reqDataLen) != (DCM_INDEX_2 + DCM_DOWN_UP_LOAD_MNOBFWRM))
                {
                    *pErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
                    Result = E_NOT_OK;
                }
            }
            else
            {
                /*If the message is the last frame, the data length should equal to the
                length of the remaining unreceived data.*/
                if((pMsgContext->reqData[DCM_INDEX_1]) == DCM_DOWN_UP_LOAD_NEXT_BSC)
                {
                    if((pMsgContext->reqDataLen) != (DCM_INDEX_2 + DCM_DOWN_UP_LOAD_MS))
                    {
                        *pErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
                        Result = E_NOT_OK;
                    }
                }
                else
                {
                    /*TransferData request is repeated.*/
                    if((pMsgContext->reqDataLen) != (DCM_INDEX_2 + DCM_DOWN_UP_LOAD_MNOBFWRM))
                    {
                        *pErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
                        Result = E_NOT_OK;
                    }
                }
                
            }
        }
        else
#endif
#if(DCM_UDS_35_SERVICE == STD_ON)
        if(DCM_DOWN_UP_LOAD_STATUS == DCM_LOAD_UP)
        {
            /*If the RequestUpload service is active, but the server has already sended all data, the NRC24 should be sent.*/
            if((DCM_DOWN_UP_LOAD_MS == DCM_DATA_CLEAR) && ((pMsgContext->reqData[DCM_INDEX_1]) != DCM_DOWN_UP_LOAD_PRE_BSC))
            {
                /*Sequence error*/
                *pErrorCode = DCM_E_REQUESTSEQUENCEERROR;
                Result = E_NOT_OK;
            }
            /*Check if the received block sequence counter equals to the expected value.*/
            else if(((pMsgContext->reqData[DCM_INDEX_1]) != DCM_DOWN_UP_LOAD_NEXT_BSC) \
                && ((pMsgContext->reqData[DCM_INDEX_1]) != DCM_DOWN_UP_LOAD_PRE_BSC))
            {
                /*SWS_Dcm_00645*/
                *pErrorCode = DCM_E_WRONGBLOCKSEQUENCECOUNTER;
                Result = E_NOT_OK;
            }
            /*if the previous request is RequestUpload(0x35 service), the length of current request message should be 2 bytes.*/
            else if((pMsgContext->reqDataLen) != DCM_INDEX_2)
            {
                *pErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
                Result = E_NOT_OK;
            }
            else
            {
                /*Call Dcm_ReadMemory()*/
            }
            
        }
        else
#endif
        {
            /*Sequence error*/
            *pErrorCode = DCM_E_REQUESTSEQUENCEERROR;
            Result = E_NOT_OK;
        }
    }

    if(Result == E_OK)
    {
#if(DCM_UDS_34_SERVICE == STD_ON)
        /*SWS_Dcm_01173*/
        if(DCM_DOWN_UP_LOAD_STATUS == DCM_LOAD_DOWN)
        {
            /*SWS_Dcm_00503*/
            if((pMsgContext->reqData[DCM_INDEX_1]) == DCM_DOWN_UP_LOAD_NEXT_BSC)
            {
                DataSize = (pMsgContext->reqDataLen - DCM_INDEX_2);

                Result = DspInternal_WriteMemory(OpStatus, DCM_DOWN_UP_LOAD_MI, DCM_DOWN_UP_LOAD_MA, DataSize, \
                                &(pMsgContext->reqData[DCM_INDEX_2]), pErrorCode);
                if(Result == E_OK)
                {
                    DCM_DOWN_UP_LOAD_MS -= DataSize;
                    DCM_DOWN_UP_LOAD_MA += DataSize;
                    /*Assign the last data length to the DCM_DOWN_UP_LOAD_MNOBFWRM variable to realize the data retransmission function.*/
                    DCM_DOWN_UP_LOAD_MNOBFWRM = DataSize;

                    DCM_DOWN_UP_LOAD_PRE_BSC = DCM_DOWN_UP_LOAD_NEXT_BSC;
                    DCM_DOWN_UP_LOAD_NEXT_BSC++;

                    pMsgContext->resData[DCM_INDEX_1] = pMsgContext->reqData[DCM_INDEX_1];
                    pMsgContext->resDataLen = 2U;
                }
            }
            else
            {
                /*The server would send positive response message immediately without writing the data once again inte its memory.*/
                pMsgContext->resData[DCM_INDEX_1] = pMsgContext->reqData[DCM_INDEX_1];
                pMsgContext->resDataLen = 2U;
            }
            
        }
        else
#endif
        {
            /*Read memory*/
#if(DCM_UDS_35_SERVICE == STD_ON)
            if((pMsgContext->reqData[DCM_INDEX_1]) == DCM_DOWN_UP_LOAD_NEXT_BSC)
            {
                if(DCM_DOWN_UP_LOAD_MS > DCM_DOWN_UP_LOAD_MNOBFWRM)
                {
                    /*If the message is not the last frame, the data length should equal to the
                    MaxNumberOfBlockLength returned in the positive response to the 0x34 service.*/
                    DataSize = DCM_DOWN_UP_LOAD_MNOBFWRM;
                }
                else
                {
                    /*If the message is the last frame, the data length should equal to the
                    length of the remaining unreceived data.*/
                    DataSize = DCM_DOWN_UP_LOAD_MS;
                }
                /*SWS_Dcm_00504*/
                Result = DspInternal_ReadMemory(OpStatus, DCM_DOWN_UP_LOAD_MI, DCM_DOWN_UP_LOAD_MA, DataSize, \
                                &(pMsgContext->resData[DCM_INDEX_2]), pErrorCode);
                if(Result == E_OK)
                {
                    DCM_DOWN_UP_LOAD_MS -= DataSize;
                    DCM_DOWN_UP_LOAD_MA += DataSize;
                    /*Assign the last data length to the DCM_DOWN_UP_LOAD_MNOBFWRM variable to realize the data retransmission function.*/
                    DCM_DOWN_UP_LOAD_MNOBFWRM = DataSize;

                    DCM_DOWN_UP_LOAD_PRE_BSC = DCM_DOWN_UP_LOAD_NEXT_BSC;
                    DCM_DOWN_UP_LOAD_NEXT_BSC++;

                    pMsgContext->resData[DCM_INDEX_1] = pMsgContext->reqData[DCM_INDEX_1];
                    pMsgContext->resDataLen = (DCM_INDEX_2 + DataSize);
                }
            }
            else
            {
                /*The length of the last frame of data is stored in the DCM_DOWN_UP_LOAD_MNOBFWRM parameter.*/
                DataSize = DCM_DOWN_UP_LOAD_MNOBFWRM;
                /*Read the data once again in its memory.*/
                Result = DspInternal_ReadMemory(OpStatus, DCM_DOWN_UP_LOAD_MI, (DCM_DOWN_UP_LOAD_MA - DataSize), DataSize, \
                                &(pMsgContext->resData[DCM_INDEX_2]), pErrorCode);
                if(Result == E_OK)
                {
                    pMsgContext->resData[DCM_INDEX_1] = pMsgContext->reqData[DCM_INDEX_1];
                    pMsgContext->resDataLen = (DCM_INDEX_2 + DataSize);
                }
            }
#endif
        }
    }

    if((Result == E_NOT_OK) && (*pErrorCode != DCM_E_WRONGBLOCKSEQUENCECOUNTER))
    {
        DCM_DOWN_UP_LOAD_STATUS = DCM_LOAD_NONE;
    }

    return Result;
}
#endif

#if(DCM_UDS_37_SERVICE == STD_ON)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DspInternal_37_RequestTransferExit
*
* Description: Processing function of UDS 0x37 service.
*
* Inputs: OpStatus,pMsgContext
*
* Outputs: pMsgContext,pErrorCode
*
* Return: Std_ReturnType
*
* Limitations: Only used by UDS 0x37 service
********************************************************************************
END_FUNCTION_HDR*/FUNC(Std_ReturnType, DCM_CODE) DspInternal_37_RequestTransferExit
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
)
{
    Std_ReturnType Result = E_OK;
    uint32 ReqRecSize = DCM_DATA_CLEAR;
    uint32 ResRecSize = DCM_DATA_CLEAR;

    if(OpStatus == DCM_INITIAL)
    {
        if((DCM_DOWN_UP_LOAD_STATUS == DCM_LOAD_NONE) || (DCM_DOWN_UP_LOAD_MS != DCM_DATA_CLEAR))
        {
            /*Sequence error*/
            *pErrorCode = DCM_E_REQUESTSEQUENCEERROR;
            Result = E_NOT_OK;
        }
    }

    if(Result == E_OK)
    {
        ReqRecSize = (pMsgContext->reqDataLen - DCM_INDEX_1);
        Result = Dcm_ProcessRequestTransferExit(OpStatus, &(pMsgContext->reqData[DCM_INDEX_1]), ReqRecSize, \
                    &(pMsgContext->resData[DCM_INDEX_1]), &ResRecSize, pErrorCode);
        
        if(Result == E_OK)
        {
            /*Reset the Down/Up load state.*/
            DCM_DOWN_UP_LOAD_STATUS = DCM_LOAD_NONE;

            /*Calculate the positive response message length.*/
            pMsgContext->resDataLen = (DCM_INDEX_1 + ResRecSize);
        }
    }

    if((Result == E_NOT_OK) && (*pErrorCode != DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT))
    {
        /*Stop the data transmission.*/
        DCM_DOWN_UP_LOAD_STATUS = DCM_LOAD_NONE;
    }

    return Result;
}
#endif

#if(DCM_UDS_3D_SERVICE == STD_ON)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name:
*
* Description:
*
* Inputs:
*
* Outputs:
*
* Return:
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
/*3D Service*//*SWS_Dcm_00488*/
FUNC(Std_ReturnType, DCM_CODE) DspInternal_3D_WriteMemoryByAddress
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
)
{
    Std_ReturnType Result = E_OK;

    Dcm_SesRefType SesLevelRef;
#if(DCM_UDS_27_SERVICE == STD_ON)
    Dcm_SecRefType SecLevelRef;
    Dcm_SecRefType CurSecMask;
#endif

    uint8 AddrSizeFormat;
    uint8 AddrLength;
    uint8 SizeLength;
    uint8 i;
    uint16 j;

    if(OpStatus == DCM_INITIAL)
    {
        DCM_MEM_START_ADDR = DCM_DATA_CLEAR;
        DCM_MEM_SIZE = DCM_DATA_CLEAR;
        DCM_MEM_ID = DCM_DATA_CLEAR;
        AddrSizeFormat = (pMsgContext->reqData[DCM_INDEX_1]);
        AddrLength = (AddrSizeFormat & (0x0FU));
        SizeLength = ((AddrSizeFormat & (0xF0U)) >> 4U);
        DCM_MEM_DATA_PTR = &(pMsgContext->reqData[DCM_INDEX_2 + AddrLength + SizeLength]);
        /*SWS_Dcm_00855,Check addressAndLengthFormatIdentifier*/
        if(DCM_CFG_MEM_FORMAT_NUM != DCM_DATA_CLEAR)
        {
            Result = E_NOT_OK;
            for(i = 0U; i < DCM_CFG_MEM_FORMAT_NUM; i++)
            {
                if(AddrSizeFormat == DCM_CFG_MEM_FORMAT(i))
                {
                    Result = E_OK;
                    break;
                }
            }
        }

        if(Result == E_NOT_OK)
        {
            *pErrorCode = DCM_E_REQUESTOUTOFRANGE;
            Result = E_NOT_OK;
        }
        else
        {
            /* Calculate start address */
            for(i = 0U; i < AddrLength; i++)
            {
                DCM_MEM_START_ADDR |= (uint32)(pMsgContext->reqData[DCM_INDEX_2 + i]) << \
                                      (uint8)(8U * (AddrLength - 1U - i));
            }
            /* Calculate size */
            for(i = 0U; i < SizeLength; i++)
            {
                DCM_MEM_SIZE |= (uint32)(pMsgContext->reqData[DCM_INDEX_2 + AddrLength + i]) << \
                                (uint8)(8U * (SizeLength - 1U - i));
            }
            /*total length check*/
            if(pMsgContext->reqDataLen != (2U + AddrLength + SizeLength + DCM_MEM_SIZE))
            {
                *pErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
                Result = E_NOT_OK;
            }
            else if(DCM_MEM_SIZE == DCM_DATA_CLEAR)
            {
                /*For Diva test*/
                *pErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
                Result = E_NOT_OK;
            }
            else
            {
                /*check memory range & security & session*/
            }
        }
        /*check memory range & security & session*/
        if(Result == E_OK)
        {
            Result = E_NOT_OK;
            /*SWS_Dcm_00489*//*SWS_Dcm_01052*/
            for(i = 0U; i < DCM_CFG_MEM_ID_NUM; i++)
            {
                for(j = 0U; j < DCM_CFG_MEM_ID_WRITE_NUM(i); j++)
                {
                    if((DCM_MEM_START_ADDR <= DCM_CFG_MEM_ID_WRITE_HIGH(i, j)) \
                            && (DCM_MEM_START_ADDR >= DCM_CFG_MEM_ID_WRITE_LOW(i, j)) \
                            && ((DCM_MEM_START_ADDR + DCM_MEM_SIZE - 1U) <= DCM_CFG_MEM_ID_WRITE_HIGH(i, j)))
                    {
                        Result = E_OK;
                        break;
                    }
                }

                if(Result == E_OK)
                {
                    DCM_MEM_ID = DCM_CFG_MEM_ID_VALUE(i);
                    break;
                }
            }

            if(Result != E_OK)
            {
                *pErrorCode = DCM_E_REQUESTOUTOFRANGE;
            }
            else
            {
                /*check security & session*/
                SesLevelRef = DCM_CFG_MEM_ID_WRITE_SESREF(i, j);
#if(DCM_UDS_27_SERVICE == STD_ON)
                SecLevelRef = DCM_CFG_MEM_ID_WRITE_SECREF(i, j);
                CurSecMask = DslInternal_GetSecurityMask();;
#endif
                if(!(DCM_CFG_SESSION_MASK(DCM_SESSION_LEVEL) & SesLevelRef))
                {
                    *pErrorCode = DCM_E_REQUESTOUTOFRANGE;
                    Result = E_NOT_OK;
                }
#if(DCM_UDS_27_SERVICE == STD_ON)
                else if(!(CurSecMask & SecLevelRef))
                {
                    /*SWS_Dcm_00490*/
                    *pErrorCode = DCM_E_SECURITYACCESSDENIED;
                    Result = E_NOT_OK;
                }
#endif
                else
                {
                    for(i = 0U; i < (2U + AddrLength + SizeLength); i++)
                    {
                        pMsgContext->resData[i] = pMsgContext->reqData[i];
                    }
                    pMsgContext->resDataLen = (2U + AddrLength + SizeLength);
#if(DCM_CAR_PLATFORM == DCM_GEELY_PLATFORM)
                    SetP4Timer(DCM_REQ_SERVICEINFO->P4ServerMax);
#endif
                    /*Call Dcm_WriteMemory()*/
                }
            }
        }
    }/*if(OpStatus == DCM_INITIAL)*/

    if(Result == E_OK)
    {
        /*SWS_Dcm_00491*/
        Result = DspInternal_WriteMemory(OpStatus, DCM_MEM_ID, DCM_MEM_START_ADDR, DCM_MEM_SIZE, DCM_MEM_DATA_PTR, pErrorCode);
    }
    return Result;
}
#endif

#if(DCM_UDS_3E_SERVICE == STD_ON)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name:
*
* Description:
*
* Inputs:
*
* Outputs:
*
* Return:
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
/*3E Service*//*SWS_Dcm_00251*/
FUNC(Std_ReturnType, DCM_CODE) DspInternal_3E_TesterPresent
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
)
{
    Std_ReturnType Result = E_NOT_OK;

    (void)OpStatus;
#if(DCM_UDS_3E_SUPPORT_SUPPRESSPOSRESBIT != STD_ON)
    ClearSuppressPosRespBit();
#endif

    Result = DsdInternal_CheckSubServiceId();

    if(Result == E_NOT_OK)
    {
        *pErrorCode = DCM_E_SUBFUNCTIONNOTSUPPORTED;
    }
    else if((pMsgContext->reqDataLen) != DCM_10_11_3E_REQ_LEN)
    {
        *pErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
        Result = E_NOT_OK;
    }
    else
    {
        Result = DspInternal_AddrSesSecCheck(pErrorCode);

        if(Result == E_OK)/*positive response*/
        {
            pMsgContext->resData[DCM_SUB_SID_INDEX] = DCM_REQ_SUBSERVICE;
            pMsgContext->resDataLen = 2U;
        }
    }
    return Result;
}
#endif

#if(DCM_UDS_85_SERVICE == STD_ON)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name:
*
* Description:
*
* Inputs:
*
* Outputs:
*
* Return:
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
/*85 Service*//*SWS_Dcm_00249*/
FUNC(Std_ReturnType, DCM_CODE) DspInternal_85_ControlDTCSetting
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
)
{
    Std_ReturnType Result = E_OK;
#if(DCM_DEM_SUPPORT == STD_ON)
    Dem_ReturnControlDTCSettingType DemResult = DEM_CONTROL_DTC_SETTING_OK;
#if(DCM_SUPPORT_DTC_RECORD == STD_ON)
    uint32 i;
    uint32 Dtc;
#endif
#endif

    if(OpStatus == DCM_INITIAL)
    {
#if(DCM_UDS_85_SUPPORT_SUPPRESSPOSRESBIT != STD_ON)
        ClearSuppressPosRespBit();
#endif
        Result = DsdInternal_CheckSubServiceId();

        if(Result == E_NOT_OK)
        {
            *pErrorCode = DCM_E_SUBFUNCTIONNOTSUPPORTED;
        }
#if(DCM_SUPPORT_DTC_RECORD == STD_OFF)
        /*SWS_Dcm_00852*/
        else if(pMsgContext->reqDataLen != DCM_85_REQ_LEN)
#else
        /*SWS_Dcm_00829*/
        else if((((pMsgContext->reqDataLen) - DCM_85_REQ_LEN) % 3) != 0U)
#endif
        {
            /*check length&format*/
            *pErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
            Result = E_NOT_OK;
        }
        else/*check Address&Session&Security level*/
        {
            Result = DspInternal_AddrSesSecCheck(pErrorCode);
        }

        if(Result == E_OK)
        {
#if(DCM_DEM_SUPPORT == STD_ON)
            switch(DCM_REQ_SUBSERVICE)
            {
                case DCM_DTC_SETTING_ON:
#if(DCM_SUPPORT_DTC_RECORD == STD_OFF)
                    /*SWS_Dcm_00304*/
                    DemResult = Dem_DcmEnableDTCSetting(DEM_DTC_GROUP_ALL, DEM_DTC_KIND_ALL_DTCS);
#else
                    if((pMsgContext->reqDataLen) > DCM_85_REQ_LEN)
                    {
                        /*SWS_Dcm_01063*/
                        for(i = 2U; i < (pMsgContext->reqDataLen); i += 3U)
                        {
                            Dtc = Make32Bit(0U, pMsgContext->reqData[i],  \
                                            pMsgContext->reqData[i + 1U], \
                                            pMsgContext->reqData[i + 2U]);
                            DemResult = Dem_DcmEnableDTCSetting(Dtc, DEM_DTC_KIND_ALL_DTCS);
                            if(DemResult != DEM_CONTROL_DTC_SETTING_OK)
                            {
                                break;
                            }
                        }
                    }
                    else
                    {
                        /*SWS_Dcm_00304*/
                        DemResult = Dem_DcmEnableDTCSetting(DEM_DTC_GROUP_ALL, DEM_DTC_KIND_ALL_DTCS);
                    }
#endif
                    if(DemResult == DEM_CONTROL_DTC_SETTING_OK)
                    {
                        /*SWS_Dcm_00783*/
                        SchM_Switch_DcmControlDtcSetting(RTE_MODE_DcmControlDtcSetting_ENABLEDTCSETTING);
                    }
                    break;

                case DCM_DTC_SETTING_OFF:
#if(DCM_SUPPORT_DTC_RECORD == STD_OFF)
                    /*SWS_Dcm_01064*/
                    DemResult = Dem_DcmDisableDTCSetting(DEM_DTC_GROUP_ALL, DEM_DTC_KIND_ALL_DTCS);
#else
                    if((pMsgContext->reqDataLen) > DCM_85_REQ_LEN)
                    {
                        /*SWS_Dcm_00406*/
                        for(i = 2U; i < (pMsgContext->reqDataLen); i += 3U)
                        {
                            Dtc = Make32Bit(0U, pMsgContext->reqData[i],  \
                                            pMsgContext->reqData[i + 1U], \
                                            pMsgContext->reqData[i + 2U]);
                            DemResult = Dem_DcmDisableDTCSetting(Dtc, DEM_DTC_KIND_ALL_DTCS);
                            if(DemResult != DEM_CONTROL_DTC_SETTING_OK)
                            {
                                break;
                            }
                        }
                    }
                    else
                    {
                        /*SWS_Dcm_01064*/
                        DemResult = Dem_DcmDisableDTCSetting(DEM_DTC_GROUP_ALL, DEM_DTC_KIND_ALL_DTCS);
                    }
#endif
                    if(DemResult == DEM_CONTROL_DTC_SETTING_OK)
                    {
                        /*SWS_Dcm_00784*/
                        SchM_Switch_DcmControlDtcSetting(RTE_MODE_DcmControlDtcSetting_DISABLEDTCSETTING);
                    }
                    break;

                default:
                    *pErrorCode = DCM_E_SUBFUNCTIONNOTSUPPORTED;
                    Result = E_NOT_OK;
                    break;
            }

            if(DemResult == DEM_CONTROL_DTC_WRONG_DTCGROUP)
            {
                /*SWS_Dcm_00830*/
                *pErrorCode = DCM_E_REQUESTOUTOFRANGE;
                Result = E_NOT_OK;
            }
            else if(DemResult == DEM_CONTROL_DTC_SETTING_N_OK)
            {
                *pErrorCode = DCM_E_GENERALREJECT;
                Result = E_NOT_OK;
            }
            else/*positive response*/
            {
                Result = E_OK;
            }
#else/*#if(DCM_DEM_SUPPORT == STD_ON)*/
            if((DCM_REQ_SUBSERVICEINFO->DcmDsdSubServiceFnc) == NULL_PTR)
            {
                *pErrorCode = DCM_E_GENERALREJECT;
                Result = E_NOT_OK;
            }
            else
            {
                DCM_SUBSERVICE_FNC = (DCM_REQ_SUBSERVICEINFO->DcmDsdSubServiceFnc);
                Result = (*DCM_SUBSERVICE_FNC)(OpStatus, pMsgContext, pErrorCode);
            }
#endif/*#if(DCM_DEM_SUPPORT == STD_ON)*/
        }
    }/*if(OpStatus == DCM_INITIAL)*/
    else
    {
#if(DCM_DEM_SUPPORT != STD_ON)
        Result = (*DCM_SUBSERVICE_FNC)(OpStatus, pMsgContext, pErrorCode);
#endif
    }

    if(Result == E_OK)
    {
        DCM_85_SUB_SESREF = (DCM_REQ_SUBSERVICEINFO->DcmDsdSubServiceSessionLevelRef);
        pMsgContext->resData[DCM_SUB_SID_INDEX] = DCM_REQ_SUBSERVICE;
        pMsgContext->resDataLen = 2U;
    }
    return Result;
}
#endif

#if(DCM_UDS_87_SERVICE == STD_ON)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name:
*
* Description:
*
* Inputs:
*
* Outputs:
*
* Return:
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
/*87 Service*/
FUNC(Std_ReturnType, DCM_CODE) DspInternal_87_LinkControl
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
)
{
    Std_ReturnType Result = E_OK;

    if(OpStatus == DCM_INITIAL)
    {
#if(DCM_UDS_87_SUPPORT_SUPPRESSPOSRESBIT != STD_ON)
        ClearSuppressPosRespBit();
#endif

        Result = DsdInternal_CheckSubServiceId();

        if(Result != E_OK)
        {
            *pErrorCode = DCM_E_SUBFUNCTIONNOTSUPPORTED;
        }
        /*check message length*/
        else if((DCM_REQ_SUBSERVICE == DCM_VERIFY_FIXED_PARAMETER) \
                && (pMsgContext->reqDataLen != DCM_87_FIXED_LEN))
        {
            *pErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
            Result = E_NOT_OK;
        }
        else if((DCM_REQ_SUBSERVICE == DCM_VERIFY_SPECIFIC_PARAMETER) \
                && (pMsgContext->reqDataLen != DCM_87_SPECIFIC_LEN))
        {
            *pErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
            Result = E_NOT_OK;
        }
        else if((DCM_REQ_SUBSERVICE == DCM_TRANSITION_MODE) \
                && (pMsgContext->reqDataLen != DCM_87_TRANSITION_LEN))
        {
            *pErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
            Result = E_NOT_OK;
        }
        /*Check sequence*/
        else if((DCM_REQ_SUBSERVICE == DCM_TRANSITION_MODE) \
                && (DCM_87_VERIFIED == DCM_DATA_CLEAR))
        {
            *pErrorCode = DCM_E_REQUESTSEQUENCEERROR;
            Result = E_NOT_OK;
        }
        /*check SupportAddress&Session&Security level*/
        else
        {
            /*SWS_Dcm_00616*//*SWS_Dcm_00617*/
            Result = DspInternal_AddrSesSecCheck(pErrorCode);
        }
        /*Get the sub service function*/
        if(Result == E_OK)
        {
            if(NULL_PTR != (DCM_REQ_SUBSERVICEINFO->DcmDsdSubServiceFnc))
            {
                DCM_SUBSERVICE_FNC = (DCM_REQ_SUBSERVICEINFO->DcmDsdSubServiceFnc);
            }
            else
            {
                *pErrorCode = DCM_E_REQUESTSEQUENCEERROR;
                Result = E_NOT_OK;
            }
        }
    }/*if(OpStatus == DCM_INITIAL)*/

    if(Result == E_OK)
    {
        Result = (*DCM_SUBSERVICE_FNC)(OpStatus, pMsgContext, pErrorCode);
    }
    /*Send positive response*/
    if(Result == E_OK)
    {
        if(DCM_REQ_SUBSERVICE != DCM_TRANSITION_MODE)
        {
            DCM_87_VERIFIED = DCM_REQ_SUBSERVICE;
        }
        else
        {
            DCM_87_VERIFIED = DCM_DATA_CLEAR;
        }
        pMsgContext->resData[DCM_SUB_SID_INDEX] = DCM_REQ_SUBSERVICE;
        pMsgContext->resDataLen = 2U;
    }
    return Result;
}
#endif


/*******************************************************************************
* OBD Services
*******************************************************************************/
#if((DCM_OBD_01_SERVICE == STD_ON)||(DCM_OBD_02_SERVICE == STD_ON) \
    ||(DCM_OBD_08_SERVICE == STD_ON)||(DCM_OBD_09_SERVICE == STD_ON))
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DcmInternal_Init_AvailabilityParameters
*
* Description:
*
* Inputs:
*
* Outputs:
*
* Return:
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
/*For OBD services 01,02,08,09*/
FUNC(void, DCM_CODE) DcmInternal_Init_AvailabilityParameters
(
    void
)
{
    uint16 i;
    uint8 RowPara = 0;
#if(DCM_OBD_01_SERVICE == STD_ON)
    uint8 RowMax_Service01 = 0;
#endif
#if(DCM_OBD_02_SERVICE == STD_ON)
    uint8 RowMax_Service02 = 0;
#endif
#if(DCM_OBD_08_SERVICE == STD_ON)
    uint8 RowMax_Service08 = 0;
#endif
#if(DCM_OBD_09_SERVICE == STD_ON)
    uint8 RowMax_Service09 = 0;
#endif
    uint8 BytePos = 0;
    uint8 BitPos = 0;

    for(RowPara = 0; RowPara < (uint8)8; RowPara++)
    {
        for(i = 0; i < (uint8)4; i++)
        {
#if(DCM_OBD_01_SERVICE == STD_ON)
            DCM_OBD_SERVICE01_AVAIL_PID[RowPara][i] = (uint8)0;
#endif
#if(DCM_OBD_02_SERVICE == STD_ON)
            DCM_OBD_SERVICE02_AVAIL_PID[RowPara][i] = (uint8)0;
#endif
#if(DCM_OBD_08_SERVICE == STD_ON)
            DCM_OBD_SERVICE08_AVAIL_TID[RowPara][i] = (uint8)0;
#endif
#if(DCM_OBD_09_SERVICE == STD_ON)
            DCM_OBD_SERVICE09_AVAIL_INFO[RowPara][i] = (uint8)0;
#endif
        }
    }

#if((DCM_OBD_01_SERVICE == STD_ON)||(DCM_OBD_02_SERVICE == STD_ON))
    for(i = 0; i < DCM_CFG_PID_NUM; i++)
    {
        if(DCM_CFG_PID_USED(i) == TRUE)
        {
            RowPara = (DCM_CFG_PID_ID(i)/(uint8)0x20);
            BytePos = ((DCM_CFG_PID_ID(i)%(uint8)0x20 - 1)/(uint8)8);
            BitPos = (7 - ((DCM_CFG_PID_ID(i)%(uint8)0x20 - 1)%(uint8)8));

#if(DCM_OBD_01_SERVICE == STD_ON)
            if(DCM_CFG_PID_SERVICE(i) != DCM_SERVICE_02)
            {
                DCM_OBD_SERVICE01_AVAIL_PID[RowPara][BytePos] |= ((uint8)0x01 << BitPos);
                if(RowMax_Service01 < RowPara)
                {
                    RowMax_Service01 = RowPara;
                }
            }
#endif/*#if(DCM_OBD_01_SERVICE == STD_ON)*/

#if(DCM_OBD_02_SERVICE == STD_ON)
            if(DCM_CFG_PID_SERVICE(i) != DCM_SERVICE_01)
            {
                DCM_OBD_SERVICE02_AVAIL_PID[RowPara][BytePos] |= ((uint8)0x01 << BitPos);
                if(RowMax_Service02 < RowPara)
                {
                    RowMax_Service02 = RowPara;
                }
            }
#endif/*#if(DCM_OBD_02_SERVICE == STD_ON)*/
        }
    }

#if(DCM_OBD_01_SERVICE == STD_ON)
    for(i = 0; i < RowMax_Service01; i++)
    {
        DCM_OBD_SERVICE01_AVAIL_PID[i][3] |= ((uint8)0x01);
    }
#endif/*#if(DCM_OBD_01_SERVICE == STD_ON)*/

#if(DCM_OBD_02_SERVICE == STD_ON)
    for(i = 0; i < RowMax_Service02; i++)
    {
        DCM_OBD_SERVICE02_AVAIL_PID[i][3] |= ((uint8)0x01);
    }
#endif/*#if(DCM_OBD_02_SERVICE == STD_ON)*/
#endif/*#if((DCM_OBD_01_SERVICE == STD_ON)||(DCM_OBD_02_SERVICE == STD_ON))*/


#if(DCM_OBD_08_SERVICE == STD_ON)
    for(i = 0; i < DCM_CFG_TID_NUM; i++)
    {
        RowPara = (DCM_CFG_TID_CONTROL_TEST_ID(i)/(uint8)0x20);
        BytePos = ((DCM_CFG_TID_CONTROL_TEST_ID(i)%(uint8)0x20 - 1)/(uint8)8);
        BitPos = (7 - ((DCM_CFG_TID_CONTROL_TEST_ID(i)%(uint8)0x20 - 1)%(uint8)8));

        DCM_OBD_SERVICE08_AVAIL_TID[RowPara][BytePos] |= ((uint8)0x01 << BitPos);
        if(RowMax_Service08 < RowPara)
        {
            RowMax_Service08 = RowPara;
        }
    }

    for(i = 0; i < RowMax_Service08; i++)
    {
        DCM_OBD_SERVICE08_AVAIL_TID[i][3] |= ((uint8)0x01);
    }
#endif/*#if(DCM_OBD_08_SERVICE == STD_ON)*/


#if(DCM_OBD_09_SERVICE == STD_ON)
    for(i = 0; i < DCM_CFG_INFOTYPE_NUM; i++)
    {
        RowPara = (DCM_CFG_INFOTYPE_ID(i)/(uint8)0x20);
        BytePos = ((DCM_CFG_INFOTYPE_ID(i)%(uint8)0x20 - 1)/(uint8)8);
        BitPos = (7 - ((DCM_CFG_INFOTYPE_ID(i)%(uint8)0x20 - 1)%(uint8)8));

        DCM_OBD_SERVICE09_AVAIL_INFO[RowPara][BytePos] |= ((uint8)0x01 << BitPos);
        if(RowMax_Service09 < RowPara)
        {
            RowMax_Service09 = RowPara;
        }
    }

    for(i = 0; i < RowMax_Service09; i++)
    {
        DCM_OBD_SERVICE09_AVAIL_INFO[i][3] |= ((uint8)0x01);
    }
#endif/*#if(DCM_OBD_09_SERVICE == STD_ON)*/
}
#endif/*#if((DCM_OBD_01_SERVICE == STD_ON)||(DCM_OBD_02_SERVICE == STD_ON) \
            (DCM_OBD_08_SERVICE == STD_ON)||(DCM_OBD_09_SERVICE == STD_ON))*/


#if(DCM_OBD_01_SERVICE == STD_ON)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DspInternal_01_RequestCurrentPowertrainDiagnosticData
*
* Description:
*
* Inputs:
*
* Outputs:
*
* Return:
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
/*01 Service*//*SWS_Dcm_00243*/
FUNC(Std_ReturnType, DCM_CODE) DspInternal_01_RequestCurrentPowertrainDiagnosticData
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
)
{
    Std_ReturnType Result = E_OK;
    uint8 i;
    uint8 j;
    uint8 RowPara;
    uint8 ReqPID;
    Dcm_MsgLenType DataLength;
    (void)OpStatus;

    if((pMsgContext->reqDataLen) > DCM_OBD_REQUEST_MAX_LENGTH)
    {
        Result = E_NOT_OK;
        /*Reset Dcm, do not send NRC 0x13.*/
        /*DsdInternal_OBD_ReqErrorReset();*/
    }
    else
    {
        /*SWS_Dcm_00943*/
        if(((pMsgContext->reqData[DCM_INDEX_1]) % DCM_OBD_AVAILABILITY_PARAMETER) == 0)
        {
            for(i = DCM_INDEX_1; i < pMsgContext->reqDataLen; i++)
            {
                DCM_OBD_SERVICE_REQ_DATA[i - (uint8)1] = (pMsgContext->reqData[i]);
                if(((pMsgContext->reqData[i]) % DCM_OBD_AVAILABILITY_PARAMETER) != 0)
                {
                    Result = E_NOT_OK;
                    /*SWS_Dcm_00943*/
                    /*Reset Dcm, do not send any negative response.*/
                    /*DsdInternal_OBD_ReqErrorReset();*/
                    break;
                }
            }
        }
        else
        {
            for(i = DCM_INDEX_1; i < pMsgContext->reqDataLen; i++)
            {
                DCM_OBD_SERVICE_REQ_DATA[i - (uint8)1] = (pMsgContext->reqData[i]);
                if(((pMsgContext->reqData[i]) % DCM_OBD_AVAILABILITY_PARAMETER) == 0)
                {
                    Result = E_NOT_OK;
                    /*SWS_Dcm_00943*/
                    /*Reset Dcm, do not send any negative response.*/
                    /*DsdInternal_OBD_ReqErrorReset();*/
                    break;
                }
            }
        }
    }

    if(Result == E_OK)
    {
        if(((DCM_OBD_SERVICE_REQ_DATA[0]) % DCM_OBD_AVAILABILITY_PARAMETER) == 0)
        {
            /*SWS_Dcm_00407*/
            /*Request PIDs are availability PIDs.*/
            pMsgContext->resDataLen = (Dcm_MsgLenType)1;

            for(i = 0; i < (pMsgContext->reqDataLen - (Dcm_MsgLenType)1); i++)
            {
                RowPara = ((DCM_OBD_SERVICE_REQ_DATA[i]) / DCM_OBD_AVAILABILITY_PARAMETER);

                if((RowPara == (uint8)0) || \
                    ((DCM_OBD_SERVICE01_AVAIL_PID[RowPara - 1][3] & (uint8)0x01) != (uint8)0))
                {
                    /*Put the request availability PID in response message buffer.*/
                    pMsgContext->resData[pMsgContext->resDataLen] = DCM_OBD_SERVICE_REQ_DATA[i];
                    pMsgContext->resDataLen += (Dcm_MsgLenType)1;

                    for(j = 0; j < (uint8)4; j++)
                    {
                        pMsgContext->resData[pMsgContext->resDataLen + j] = DCM_OBD_SERVICE01_AVAIL_PID[RowPara][j];
                    }
                    pMsgContext->resDataLen += (Dcm_MsgLenType)4;
                }
            }
        }
        else
        {
            /*One byte PID*/
            pMsgContext->resDataLen = (Dcm_MsgLenType)1;

            for(i = 0; i < (pMsgContext->reqDataLen - (Dcm_MsgLenType)1); i++)
            {
                ReqPID = (DCM_OBD_SERVICE_REQ_DATA[i]);
                /*One byte PID*/
                DataLength = (pMsgContext->resMaxDataLen - pMsgContext->resDataLen - (Dcm_MsgLenType)1);

                Result = DspInternal_01_ReadPidData(ReqPID, \
                        &(pMsgContext->resData[pMsgContext->resDataLen + (Dcm_MsgLenType)1]), &DataLength);
                if((Result == E_OK) && (DataLength != 0))
                {
                    pMsgContext->resData[pMsgContext->resDataLen] = ReqPID;
                    pMsgContext->resDataLen += (Dcm_MsgLenType)1;
                    pMsgContext->resDataLen += DataLength;
                }
            }
        }
    }

    if((Result == E_NOT_OK) || (pMsgContext->resDataLen == (Dcm_MsgLenType)1))
    {
        /*if Result equals E_OK and the response length is 1,
        it means that no request PIDs supported in the ECU.*/
        DsdInternal_OBD_ReqErrorReset();
    }
    else
    {
        /*Send positive response.*/
        pMsgContext->resData[DCM_SID_INDEX] = DCM_REQ_SERVICE;
    }

    return Result;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DspInternal_01_ReadPidData
*
* Description: Read the data of one PID.
*
* Inputs:
*
* Outputs:
*
* Return:
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, DCM_CODE) DspInternal_01_ReadPidData
(
    uint8 ReqPID,
    uint8 *DataBuffer,
    uint32 *Length
)
{
    Std_ReturnType Result = E_OK;
    uint8 i;
    uint8 j;
    uint8 BytePos;

    for(i = (uint8)0; i < DCM_CFG_PID_NUM; i++)
    {
        if((DCM_CFG_PID_ID(i) == ReqPID) && (DCM_CFG_PID_USED(i) == TRUE) \
            && (DCM_CFG_PID_SERVICE(i) != DCM_SERVICE_02))
        {
            if(*Length <  DCM_CFG_PID_SIZE(i))
            {
                Result = E_NOT_OK;
            }
            else
            {
                *Length = DCM_CFG_PID_SIZE(i);
                for(j = (uint8)0; j < (*Length); j++)
                {
                    /*SWS_Dcm_00623*//*SWS_Dcm_00944*/
                    DataBuffer[j] = DCM_DATA_CLEAR;
                }
                /*Read the data value of the PID.*/
                for(j = (uint8)0; j < DCM_CFG_PID_DATA_NUM(i); j++)
                {
                    if(DCM_CFG_PID_DATA_SERVICE01(i,j) != NULL_PTR)
                    {
                        /*constr_6017*/
                        BytePos = (uint8)(DCM_CFG_PID_DATA_POS(i,j)>>3U);
                        /*SWS_Dcm_00408*/
                        Result = (*DCM_CFG_PID_DATA_SERVICE01_FNC(i,j))((DataBuffer + BytePos));
                        if(Result != E_OK)
                        {
                            Result = E_NOT_OK;
                            break;/*for(j = 0; j < DCM_CFG_PID_DATA_NUM(i); j++)*/
                        }
                    }
                }/*for(j = 0; j < DCM_CFG_PID_DATA_NUM(i); j++)*/
            }/*if(*Length <  DCM_CFG_PID_SIZE(i))*/

            break;/*for(i = 0; i < DCM_CFG_PID_NUM; i++)*/
        }
    }

    if(i == DCM_CFG_PID_NUM)
    {
        /*It means that the ReqPID is not supported in the ECU.*/
        *Length = (uint32)0;
    }
    return Result;
}
#endif

#if(DCM_OBD_02_SERVICE == STD_ON)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name:
*
* Description:
*
* Inputs:
*
* Outputs:
*
* Return:
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
/*02 Service*//*SWS_Dcm_00244*/
FUNC(Std_ReturnType, DCM_CODE) DspInternal_02_RequestPowertrainFreezeFrameData
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
)
{
    Std_ReturnType Result = E_OK;
    uint8 i;
    uint8 j;
    uint8 RowPara;
    uint8 ReqPID;
    uint8 ReqFrame;
    Dcm_MsgLenType DataLength;
    (void)OpStatus;

    if(((pMsgContext->reqDataLen) > DCM_OBD_REQUEST_MAX_LENGTH) \
        || (!((pMsgContext->reqDataLen) & 0x01U)))
    {
        Result = E_NOT_OK;
        /*Reset Dcm, do not send NRC 0x13.*/
        DsdInternal_OBD_ReqErrorReset();
    }
    else
    {
        /*Check the validity of request data.*/
        /*SWS_Dcm_00972*//*SWS_Dcm_00409*/
        if(((pMsgContext->reqData[DCM_INDEX_1]) % DCM_OBD_AVAILABILITY_PARAMETER) == 0)
        {
            for(i = DCM_INDEX_1; i < pMsgContext->reqDataLen; i += (uint8)2)
            {
                if((((pMsgContext->reqData[i]) % DCM_OBD_AVAILABILITY_PARAMETER) != 0) \
                    || (pMsgContext->reqData[i+(uint8)1] != 0))
                {
                    Result = E_NOT_OK;
                    /*SWS_Dcm_00972*//*SWS_Dcm_00409*/
                    /*Reset Dcm, do not send any negative response.*/
                    /*DsdInternal_OBD_ReqErrorReset();*/
                    break;
                }
            }
        }
        else
        {
            for(i = DCM_INDEX_1; i < pMsgContext->reqDataLen; i += (uint8)2)
            {
                if((((pMsgContext->reqData[i]) % DCM_OBD_AVAILABILITY_PARAMETER) == 0) \
                    || (pMsgContext->reqData[i+(uint8)1] != 0))
                {
                    Result = E_NOT_OK;
                    /*SWS_Dcm_00972*//*SWS_Dcm_00409*/
                    /*Reset Dcm, do not send any negative response.*/
                    /*DsdInternal_OBD_ReqErrorReset();*/
                    break;
                }
            }
        }
    }

    if(Result == E_OK)
    {
        /*Copy the request data into local buffer.*/
        for(i = DCM_INDEX_1; i < pMsgContext->reqDataLen; i++)
        {
            DCM_OBD_SERVICE_REQ_DATA[i - (uint8)1] = (pMsgContext->reqData[i]);
        }

        /*Calculate the response message.*/
        if(((DCM_OBD_SERVICE_REQ_DATA[0]) % DCM_OBD_AVAILABILITY_PARAMETER) == 0)
        {
            /*SWS_Dcm_00284*/
            /*Request PIDs are availability PIDs.*/
            pMsgContext->resDataLen = (Dcm_MsgLenType)1;

            for(i = 0; i < (pMsgContext->reqDataLen - (Dcm_MsgLenType)1); i += (uint8)2)
            {
                RowPara = ((DCM_OBD_SERVICE_REQ_DATA[i]) / DCM_OBD_AVAILABILITY_PARAMETER);

                if((RowPara == (uint8)0) || \
                    ((DCM_OBD_SERVICE02_AVAIL_PID[RowPara - 1][3] & (uint8)0x01) != (uint8)0))
                {
                    /*Put the request availability PID in response message buffer.*/
                    pMsgContext->resData[pMsgContext->resDataLen] = DCM_OBD_SERVICE_REQ_DATA[i];
                    pMsgContext->resDataLen += (Dcm_MsgLenType)1;
                    /*Put the request frame number in response message buffer.*/
                    pMsgContext->resData[pMsgContext->resDataLen] = DCM_OBD_SERVICE_REQ_DATA[i + (uint8)1];
                    pMsgContext->resDataLen += (Dcm_MsgLenType)1;

                    for(j = 0; j < (uint8)4; j++)
                    {
                        pMsgContext->resData[pMsgContext->resDataLen + j] = DCM_OBD_SERVICE02_AVAIL_PID[RowPara][j];
                    }
                    pMsgContext->resDataLen += (Dcm_MsgLenType)4;
                }
            }
        }
        else
        {
            /*Request PIDs are not availability PIDs.*/
            pMsgContext->resDataLen = (Dcm_MsgLenType)1;

            for(i = 0; i < (pMsgContext->reqDataLen - (Dcm_MsgLenType)1); i += (uint8)2)
            {
                ReqPID = (DCM_OBD_SERVICE_REQ_DATA[i]);
                ReqFrame = (DCM_OBD_SERVICE_REQ_DATA[i + (uint8)1]);
                /*One byte PID and one byte frame*/
                DataLength = (pMsgContext->resMaxDataLen - pMsgContext->resDataLen - (Dcm_MsgLenType)2);

                Result = DspInternal_02_ReadPidData(ReqPID, ReqFrame, \
                        &(pMsgContext->resData[pMsgContext->resDataLen + (Dcm_MsgLenType)2]), &DataLength);
                if((Result == E_OK) && (DataLength != 0))
                {
                    /*SWS_Dcm_00287*//*SWS_Dcm_01254*/
                    pMsgContext->resData[pMsgContext->resDataLen] = ReqPID;
                    pMsgContext->resDataLen += (Dcm_MsgLenType)1;
                    pMsgContext->resData[pMsgContext->resDataLen] = ReqFrame;
                    pMsgContext->resDataLen += (Dcm_MsgLenType)1;
                    pMsgContext->resDataLen += DataLength;
                }
            }
        }
    }

    /*SWS_Dcm_01252*//*SWS_Dcm_01253*//*SWS_Dcm_01254*/
    if((Result == E_NOT_OK) || (pMsgContext->resDataLen == (Dcm_MsgLenType)1))
    {
        /*if Result equals E_OK and the response length is 1,
        it means that no request PIDs supported in the ECU.*/
        DsdInternal_OBD_ReqErrorReset();
    }
    else
    {
        /*Send positve respnse.*/
        pMsgContext->resData[DCM_SID_INDEX] = DCM_REQ_SERVICE;
    }

    return Result;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DspInternal_02_ReadPidData
*
* Description:
*
* Inputs:
*
* Outputs:
*
* Return:
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, DCM_CODE) DspInternal_02_ReadPidData
(
    uint8 ReqPID,
    uint8 ReqFrame,
    uint8 *DataBuffer,
    uint32 *Length
)
{
    Std_ReturnType Result = E_OK;
    uint8 i;
    uint8 j;
    uint8 BytePos;
    uint16 DemDataLength;/*Temporarily no effect*/
#if(DCM_DEM_SUPPORT == STD_ON)
    uint32 Dtc = 0;
#endif

    for(i = (uint8)0; i < DCM_CFG_PID_NUM; i++)
    {
        if((DCM_CFG_PID_ID(i) == ReqPID) && (DCM_CFG_PID_USED(i) == TRUE) \
            && (DCM_CFG_PID_SERVICE(i) != DCM_SERVICE_01))
        {
            if(*Length <  DCM_CFG_PID_SIZE(i))
            {
                Result = E_NOT_OK;
            }
            else
            {
                *Length = DCM_CFG_PID_SIZE(i);
                DemDataLength = DCM_CFG_PID_SIZE(i);

                for(j = (uint8)0; j < (*Length); j++)
                {
                    /*SWS_Dcm_00973*//*SWS_Dcm_00974*/
                    DataBuffer[j] = DCM_DATA_CLEAR;
                }

#if(DCM_DEM_SUPPORT == STD_ON)
                /*Read the data value of the PID.*/
                if(ReqPID == (uint8)0x02)
                {
                    /*SWS_Dcm_00279*/
                    /*Special PID need processed specially.*/
                    Result = Dem_DcmGetDTCOfOBDFreezeFrame(ReqFrame, &Dtc, DEM_DTC_FORMAT_OBD);
                    if(Result == E_OK)
                    {
                        DataBuffer[0] = (uint8)(Dtc>>8);
                        DataBuffer[1] = (uint8)Dtc;
                    }
                    else
                    {
                        Result = E_OK;
                        /*SWS_Dcm_01061*/
                    }
                }
                else/*(ReqPID != (uint8)0x02)*/
#endif/*#if(DCM_DEM_SUPPORT == STD_ON)*/
                {
                    for(j = (uint8)0; j < DCM_CFG_PID_DATA_NUM(i); j++)
                    {
                        /*constr_6017*/
                        BytePos = (uint8)(DCM_CFG_PID_DATA_POS(i,j)>>3U);
                        /*SWS_Dcm_00286*/
#if(DCM_DEM_SUPPORT == STD_ON)
                        Result = Dem_DcmReadDataOfOBDFreezeFrame(ReqPID, j, \
                                    (DataBuffer + BytePos), &DemDataLength);
#else
                        Result = Dcm_Rte_OBD_ReadDataOfOBDFreezeFrame(ReqPID, j, \
                                    (DataBuffer + BytePos), &DemDataLength);
#endif
                        if(Result != E_OK)
                        {
                            Result = E_NOT_OK;
                            break;/*for(j = 0; j < DCM_CFG_PID_DATA_NUM(i); j++)*/
                        }
                    }
                }/*if(ReqPID == (uint8)0x02)*/
            }/*if(*Length <  DCM_CFG_PID_SIZE(i))*/

            break;/*for(i = 0; i < DCM_CFG_PID_NUM; i++)*/
        }
    }

    if(i == DCM_CFG_PID_NUM)
    {
        /*It means that the ReqPID is not supported in the ECU.*/
        *Length = (uint32)0;
    }
    return Result;
}
#endif

#if((DCM_OBD_03_SERVICE == STD_ON)||(DCM_OBD_07_SERVICE == STD_ON)||(DCM_OBD_0A_SERVICE == STD_ON))
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name:
*
* Description:
*
* Inputs:
*
* Outputs:
*
* Return:
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
/*03/07/0A Service*//*SWS_Dcm_00245*//*SWS_Dcm_00410*//*SWS_Dcm_00411*/
FUNC(Std_ReturnType, DCM_CODE) DspInternal_03_07_0A_ObtainingDTC
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
)
{
    Std_ReturnType Result = E_OK;
#if(DCM_DEM_SUPPORT == STD_ON)
    Dem_ReturnSetFilterType SetFilterResult = DEM_FILTER_ACCEPTED;
    uint32 GetDtc;
    Dem_UdsStatusByteType GetDtcStatus;
    Dem_ReturnGetNextFilteredElementType GetNextDtcResult = DEM_FILTERED_OK;
#endif

    if(OpStatus == DCM_INITIAL)
    {
        if((pMsgContext->reqDataLen) != (Dcm_MsgLenType)1)
        {
            Result = E_NOT_OK;
            /*Reset Dcm, do not send NRC 0x13.*/
            /*DsdInternal_OBD_ReqErrorReset();*/
        }
        else
        {
            DCM_OBD_DTC_COUNTER = DCM_DATA_CLEAR;
#if(DCM_DEM_SUPPORT == STD_ON)
            if(DCM_REQ_SERVICE == DCM_03_SERVICE)
            {
                /*SWS_Dcm_00289*/
                SetFilterResult = Dem_DcmSetDTCFilter((Dem_UdsStatusByteType)0x08, DEM_DTC_KIND_EMISSION_REL_DTCS, \
                                  DEM_DTC_FORMAT_OBD, DEM_DTC_ORIGIN_PRIMARY_MEMORY, FALSE, 0U, FALSE);
            }
            else if(DCM_REQ_SERVICE == DCM_07_SERVICE)
            {
                /*SWS_Dcm_00412*/
                SetFilterResult = Dem_DcmSetDTCFilter((Dem_UdsStatusByteType)0x04, DEM_DTC_KIND_EMISSION_REL_DTCS, \
                                  DEM_DTC_FORMAT_OBD, DEM_DTC_ORIGIN_PRIMARY_MEMORY, FALSE, 0U, FALSE);
            }
            else/*(DCM_REQ_SERVICE == DCM_0A_SERVICE)*/
            {
                /*permanent memory*//*SWS_Dcm_00330*/
                SetFilterResult = Dem_DcmSetDTCFilter((Dem_UdsStatusByteType)0, DEM_DTC_KIND_EMISSION_REL_DTCS, \
                                  DEM_DTC_FORMAT_OBD, DEM_DTC_ORIGIN_PERMANENT_MEMORY, FALSE, 0U, FALSE);
            }

            if(SetFilterResult != DEM_FILTER_ACCEPTED)
            {
                /*Reset Dcm, do not send any negative response.*/
                Result = E_NOT_OK;
            }
#endif
        }/*if((pMsgContext->reqDataLen) != (Dcm_MsgLenType)1)*/
    }/*if(OpStatus == DCM_INITIAL)*/

    if(Result == E_OK)
    {
#if(DCM_DEM_SUPPORT == STD_ON)
        do
        {
            /*SWS_Dcm_01227*//*SWS_Dcm_01228*/
            GetNextDtcResult = Dem_DcmGetNextFilteredDTC(&GetDtc, &GetDtcStatus);

            if(GetNextDtcResult == DEM_FILTERED_OK)
            {
                pMsgContext->resData[2U + (DCM_OBD_DTC_COUNTER * 2U)] = (uint8)(GetDtc >> 8U);
                pMsgContext->resData[3U + (DCM_OBD_DTC_COUNTER * 2U)] = (uint8)GetDtc;
                DCM_OBD_DTC_COUNTER++;
            }
            else if(GetNextDtcResult == DEM_FILTERED_PENDING)
            {
                /*03/07/0A are not allowed to send 0x78 negtive response.*/
                Result = E_NOT_OK;
            }
            else/*GetNextDtcResult == DEM_FILTERED_NO_MATCHING_ELEMENT*/
            {
                /*GetNextFilteredDTC is over*/
            }
        }
        while((GetNextDtcResult != DEM_FILTERED_NO_MATCHING_ELEMENT) && (Result == E_OK));
#else
        Result = Dcm_Rte_OBD_ObtainingDTC(DCM_REQ_SERVICE, \
                 &(pMsgContext->resData[DCM_INDEX_2]), &DCM_OBD_DTC_COUNTER);
#endif
    }

    if(Result == E_OK)
    {
        /*SWS_Dcm_01227*//*SWS_Dcm_01228*/
        /*Send positve respnse.*/
        pMsgContext->resData[DCM_SID_INDEX] = DCM_REQ_SERVICE;
        pMsgContext->resData[DCM_INDEX_1] = DCM_OBD_DTC_COUNTER;
        pMsgContext->resDataLen = (DCM_INDEX_2 + (DCM_OBD_DTC_COUNTER * 2U));
    }
    else
    {
        /*Reset Dcm*/
        DsdInternal_OBD_ReqErrorReset();
    }

    return Result;
}
#endif

#if(DCM_OBD_04_SERVICE == STD_ON)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name:
*
* Description:
*
* Inputs:
*
* Outputs:
*
* Return:
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
/*04 Service*//*SWS_Dcm_00246*/
FUNC(Std_ReturnType, DCM_CODE) DspInternal_04_ClearEmissionRelatedDiagnosticInformation
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
)
{
    Std_ReturnType Result = E_OK;
#if(DCM_DEM_SUPPORT == STD_ON)
    Dem_ReturnClearDTCType ClearResult = DEM_CLEAR_OK;
#endif

    if(OpStatus == DCM_INITIAL)
    {
        if((pMsgContext->reqDataLen) != (Dcm_MsgLenType)1)
        {
            Result = E_NOT_OK;
            /*Reset Dcm, do not send NRC 0x13.*/
            DsdInternal_OBD_ReqErrorReset();
        }
    }

    if(Result == E_OK)
    {
#if(DCM_DEM_SUPPORT == STD_ON)
        /*SWS_Dcm_00004*/
        ClearResult = Dem_DcmClearDTC(DEM_DTC_GROUP_ALL, DEM_DTC_FORMAT_OBD, DEM_DTC_ORIGIN_PRIMARY_MEMORY);

        if(ClearResult == DEM_CLEAR_OK)
        {
            /*SWS_Dcm_00413*/
            /*Send positve respnse.*/
            pMsgContext->resData[DCM_SID_INDEX] = DCM_REQ_SERVICE;
            pMsgContext->resDataLen = (Dcm_MsgLenType)1;
        }
        else if(ClearResult == DEM_CLEAR_PENDING)
        {
            /*SWS_Dcm_00703*/
            Result = DCM_E_PENDING;
        }
        else/*(ClearResult == DEM_CLEAR_FAILED)*/
        {
            /*SWS_Dcm_00704*//*SWS_Dcm_00967*//*SWS_Dcm_01067*/
            *pErrorCode = DCM_E_CONDITIONSNOTCORRECT;
            Result = E_NOT_OK;
        }
#else
        Result = Dcm_Rte_OBD_ClearDTC(OpStatus);

        if(Result == E_OK)
        {
            /*SWS_Dcm_00413*/
            /*Send positve respnse.*/
            pMsgContext->resData[DCM_SID_INDEX] = DCM_REQ_SERVICE;
            pMsgContext->resDataLen = (Dcm_MsgLenType)1;
        }
        else if(Result == DCM_E_PENDING)
        {
            /*SWS_Dcm_00703*/
            Result = DCM_E_PENDING;
        }
        else/*(Result == E_NOT_OK)*/
        {
            /*SWS_Dcm_00704*//*SWS_Dcm_00967*//*SWS_Dcm_01067*/
            *pErrorCode = DCM_E_CONDITIONSNOTCORRECT;
            Result = E_NOT_OK;
        }
#endif
    }

    return Result;
}
#endif

#if(DCM_OBD_06_SERVICE == STD_ON)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name:
*
* Description:
*
* Inputs:
*
* Outputs:
*
* Return:
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
/*06 Service*//*SWS_Dcm_00414*/
FUNC(Std_ReturnType, DCM_CODE) DspInternal_06_RequestOnBoardMonitoringTestResults
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
)
{
    Std_ReturnType Result = E_OK;
    uint8 i;
    uint8 ReqMID;
    uint32 MIDValue;/*Used for availability MID*/
#if(DCM_DEM_SUPPORT == STD_ON)
    uint8 NumOfTIDs;/*Number of TIDs*/
    uint8 TIDValue;/*Std./Manuf. Defined TID*/
    uint8 UaSID;/*Unit And Scaling ID*/
    uint16 TestValue;/*Test Value*/
    uint16 LowLimValue;/*Min Test Limit/Lower limit value*/
    uint16 UppLimValue;/*Max Test Limit/Upper limit value*/
#else
    uint32 DataLength = 0;
#endif
    (void)OpStatus;

    if((((pMsgContext->reqData[DCM_INDEX_1]) % DCM_OBD_AVAILABILITY_PARAMETER) == 0) \
        && ((pMsgContext->reqDataLen) > DCM_OBD_REQUEST_MAX_LENGTH))
    {
        Result = E_NOT_OK;
        /*Reset Dcm, do not send NRC 0x13.*/
        /*DsdInternal_OBD_ReqErrorReset();*/
    }
    else if(((pMsgContext->reqData[DCM_INDEX_1]) % DCM_OBD_AVAILABILITY_PARAMETER) == 0)
    {
        /*SWS_Dcm_00945*/
        for(i = DCM_INDEX_1; i < pMsgContext->reqDataLen; i++)
        {
            DCM_OBD_SERVICE_REQ_DATA[i - (uint8)1] = (pMsgContext->reqData[i]);
            if(((pMsgContext->reqData[i]) % DCM_OBD_AVAILABILITY_PARAMETER) != 0)
            {
                /*SWS_Dcm_00945*/
                Result = E_NOT_OK;
                /*Reset Dcm, do not send any negative response.*/
                /*DsdInternal_OBD_ReqErrorReset();*/
                break;
            }
        }
    }
    else if((pMsgContext->reqDataLen) != (Dcm_MsgLenType)2)
    {
        /*SWS_Dcm_00956*/
        Result = E_NOT_OK;
        /*Reset Dcm, do not send NRC 0x13.*/
        /*DsdInternal_OBD_ReqErrorReset();*/
    }
    else
    {
        /*do nothig*/
    }

    if((Result == E_OK) \
        && (((pMsgContext->reqData[DCM_INDEX_1]) % DCM_OBD_AVAILABILITY_PARAMETER) == 0))
    {
        pMsgContext->resDataLen = (Dcm_MsgLenType)1;
        /*SWS_Dcm_00957*/
        for(i = (uint8)0; i < (pMsgContext->reqDataLen - (Dcm_MsgLenType)1); i++)
        {
            ReqMID = DCM_OBD_SERVICE_REQ_DATA[i];
#if(DCM_DEM_SUPPORT == STD_ON)
            Result = Dem_DcmGetAvailableOBDMIDs(ReqMID, &MIDValue);
#else
            Result = Dcm_Rte_OBD_GetAvailableOBDMIDs(ReqMID, &MIDValue);
#endif
            if(Result == E_OK)
            {
                pMsgContext->resData[pMsgContext->resDataLen] = DCM_OBD_SERVICE_REQ_DATA[i];
                pMsgContext->resDataLen += (Dcm_MsgLenType)1;

                pMsgContext->resData[pMsgContext->resDataLen] = (uint8)(MIDValue>>24);
                pMsgContext->resData[pMsgContext->resDataLen + (Dcm_MsgLenType)1] = (uint8)(MIDValue>>16);
                pMsgContext->resData[pMsgContext->resDataLen + (Dcm_MsgLenType)2] = (uint8)(MIDValue>>8);
                pMsgContext->resData[pMsgContext->resDataLen + (Dcm_MsgLenType)3] = (uint8)MIDValue;
                pMsgContext->resDataLen += (Dcm_MsgLenType)4;
            }
        }
    }
    else if(Result == E_OK)
    {
        /*SWS_Dcm_00958*/
        ReqMID = (pMsgContext->reqData[DCM_INDEX_1]);
        pMsgContext->resDataLen = (Dcm_MsgLenType)1;
#if(DCM_DEM_SUPPORT == STD_ON)
        Result = Dem_DcmGetNumTIDsOfOBDMID(ReqMID, &NumOfTIDs);

        if((Result == E_OK) && (NumOfTIDs > (uint8)0))
        {
            for(i = 0; i < NumOfTIDs; i++)
            {
                Result = Dem_DcmGetDTRData(ReqMID, i, &TIDValue, &UaSID, &TestValue, &LowLimValue, &UppLimValue);
                if(Result == E_OK)
                {
                    pMsgContext->resData[pMsgContext->resDataLen] = ReqMID;
                    pMsgContext->resData[pMsgContext->resDataLen + (Dcm_MsgLenType)1] = TIDValue;
                    pMsgContext->resData[pMsgContext->resDataLen + (Dcm_MsgLenType)2] = UaSID;
                    pMsgContext->resData[pMsgContext->resDataLen + (Dcm_MsgLenType)3] = (uint8)(TestValue>>8);
                    pMsgContext->resData[pMsgContext->resDataLen + (Dcm_MsgLenType)4] = (uint8)TestValue;
                    pMsgContext->resData[pMsgContext->resDataLen + (Dcm_MsgLenType)5] = (uint8)(LowLimValue>>8);
                    pMsgContext->resData[pMsgContext->resDataLen + (Dcm_MsgLenType)6] = (uint8)LowLimValue;
                    pMsgContext->resData[pMsgContext->resDataLen + (Dcm_MsgLenType)7] = (uint8)(UppLimValue>>8);
                    pMsgContext->resData[pMsgContext->resDataLen + (Dcm_MsgLenType)8] = (uint8)UppLimValue;
                    pMsgContext->resDataLen += (Dcm_MsgLenType)9;
                }
                else
                {
                    Result = E_NOT_OK;
                    break;
                }
            }/*for(i = 0; i < NumOfTIDs; i++)*/
        }
        else
        {
            Result = E_NOT_OK;
        }/*if((Result == E_OK) && (NumOfTIDs > (uint8)0))*/
#else
        Result = Dcm_Rte_OBD_GetDTRData(ReqMID, &(pMsgContext->resData[DCM_INDEX_2]), &DataLength);

        if(Result == E_OK)
        {
            pMsgContext->resData[DCM_INDEX_1] = ReqMID;
            pMsgContext->resDataLen += DataLength;
        }
#endif
    }
    else
    {
        /*do nothing*/
    }

    if(Result != E_OK)
    {
        DsdInternal_OBD_ReqErrorReset();
    }
    else
    {
        /*Send positve respnse.*/
        pMsgContext->resData[DCM_SID_INDEX] = DCM_REQ_SERVICE;
    }

    return Result;
}
#endif

#if(DCM_OBD_08_SERVICE == STD_ON)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name:
*
* Description:
*
* Inputs:
*
* Outputs:
*
* Return:
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
/*08 Service*//*SWS_Dcm_00417*/
FUNC(Std_ReturnType, DCM_CODE) DspInternal_08_RequestControlOfOnBoardSystem
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
)
{
    Std_ReturnType Result = E_OK;
    uint8 i;
    uint8 j;
    uint8 RowPara;
    uint8 ReqTID;
    (void)OpStatus;

    if((pMsgContext->reqDataLen) > DCM_OBD_REQUEST_MAX_LENGTH)
    {
        Result = E_NOT_OK;
        /*Reset Dcm, do not send NRC 0x13.*/
        DsdInternal_OBD_ReqErrorReset();
    }
    else
    {
        /*SWS_Dcm_00947*/
        if(((pMsgContext->reqData[DCM_INDEX_1]) % DCM_OBD_AVAILABILITY_PARAMETER) == 0)
        {
            for(i = DCM_INDEX_1; i < pMsgContext->reqDataLen; i++)
            {
                DCM_OBD_SERVICE_REQ_DATA[i - (uint8)1] = (pMsgContext->reqData[i]);
                if(((pMsgContext->reqData[i]) % DCM_OBD_AVAILABILITY_PARAMETER) != 0)
                {
                    Result = E_NOT_OK;
                    /*SWS_Dcm_00947*/
                    /*Reset Dcm, do not send any negative response.*/
                    DsdInternal_OBD_ReqErrorReset();
                    break;
                }
            }/*for(i = DCM_INDEX_1; i < pMsgContext->reqDataLen; i++)*/
        }
    }

    if((Result == E_OK) \
        && (((pMsgContext->reqData[DCM_INDEX_1]) % DCM_OBD_AVAILABILITY_PARAMETER) == 0))
    {
        /*SWS_Dcm_00418*/
        /*Request TIDs are availability TIDs.*/
        pMsgContext->resDataLen = (Dcm_MsgLenType)1;

        for(i = 0; i < (pMsgContext->reqDataLen - (Dcm_MsgLenType)1); i++)
        {
            RowPara = ((DCM_OBD_SERVICE_REQ_DATA[i]) / DCM_OBD_AVAILABILITY_PARAMETER);

            if((RowPara == (uint8)0) || ((RowPara != (uint8)0) && \
                ((DCM_OBD_SERVICE08_AVAIL_TID[RowPara - 1][3] & (uint8)0x01) != (uint8)0)))
            {
                /*Put the request availability TID in response message buffer.*/
                pMsgContext->resData[pMsgContext->resDataLen] = DCM_OBD_SERVICE_REQ_DATA[i];
                pMsgContext->resDataLen += (Dcm_MsgLenType)1;

                for(j = 0; j < (uint8)4; j++)
                {
                    pMsgContext->resData[pMsgContext->resDataLen + j] = DCM_OBD_SERVICE08_AVAIL_TID[RowPara][j];
                }
                pMsgContext->resDataLen += (Dcm_MsgLenType)4;
            }
        }
    }
    else if((Result == E_OK) \
        && (((pMsgContext->reqData[DCM_INDEX_1]) % DCM_OBD_AVAILABILITY_PARAMETER) != 0))
    {
        /*Copy the request data into local buffer.*/
        for(i = DCM_INDEX_2; i < pMsgContext->reqDataLen; i++)
        {
            DCM_OBD_SERVICE_REQ_DATA[i - (uint8)2] = (pMsgContext->reqData[i]);
        }

        /*Check the request TID whether supported in the ECU
        and the request data length equals to the value in configuration.*/
        Result = E_NOT_OK;
        ReqTID = (pMsgContext->reqData[DCM_INDEX_1]);

        for(i = 0; i < DCM_CFG_TID_NUM; i++)
        {
            if((ReqTID == DCM_CFG_TID_CONTROL_TEST_ID(i)) \
                && ((pMsgContext->reqDataLen - (Dcm_MsgLenType)2) == DCM_CFG_TID_CONTROL_IN_SIZE(i)))
            {
                Result = E_OK;
                break;
            }
        }

        if(Result == E_OK)
        {
            /*SWS_Dcm_00948*/
            for(j = 0; j < DCM_CFG_TID_CONTROL_OUT_SIZE(i); j++)
            {
                pMsgContext->resData[j + DCM_INDEX_2] = DCM_DATA_CLEAR;
            }
            /*SWS_Dcm_00419*//*SWS_Dcm_00691*/
            /*Call the function to process the request data.*/
            Result = (*DCM_CFG_TID_CONTROL_FNC(i))(&(pMsgContext->resData[DCM_INDEX_2]), \
                                                   DCM_OBD_SERVICE_REQ_DATA);
            /*SWS_Dcm_00420*/
            if(Result == E_OK)
            {
                /*Send positve respnse.*/
                pMsgContext->resData[DCM_SID_INDEX] = DCM_REQ_SERVICE;
                pMsgContext->resData[DCM_INDEX_1] = ReqTID;
                pMsgContext->resDataLen = (DCM_INDEX_2 + DCM_CFG_TID_CONTROL_OUT_SIZE(i));
            }
            else
            {
                /*SWS_Dcm_01192*/
                *pErrorCode = DCM_E_CONDITIONSNOTCORRECT;
                Result = E_NOT_OK;
            }
        }
        else/*Result == E_NOT_OK*/
        {
            /*Reset Dcm, do not send any negative response.*/
            DsdInternal_OBD_ReqErrorReset();
        }
    }
    else
    {
        /*do nothing*/
    }

    return Result;
}
#endif

#if(DCM_OBD_09_SERVICE == STD_ON)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name:
*
* Description:
*
* Inputs:
*
* Outputs:
*
* Return:
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
/*09 Service*//*SWS_Dcm_00421*/
FUNC(Std_ReturnType, DCM_CODE) DspInternal_09_RequestVehicleInformation
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
)
{
    Std_ReturnType Result = E_OK;
    uint8 i;
    uint8 j;
    uint8 RowPara;
    uint8 ReqInfoType;
    uint8 DataLength;
    uint8 *DataBuffer;

    if(OpStatus == DCM_INITIAL)
    {
        DCM_OBD_INFOTYPE_INDEX = DCM_DATA_CLEAR;
        DCM_OBD_INFOTYPE_DATA_INDEX = DCM_DATA_CLEAR;

        if(((pMsgContext->reqData[DCM_INDEX_1]) % DCM_OBD_AVAILABILITY_PARAMETER) == 0)
        {
            if((pMsgContext->reqDataLen) > DCM_OBD_REQUEST_MAX_LENGTH)
            {
                Result = E_NOT_OK;
                /*Reset Dcm, do not send NRC 0x13.*/
                DsdInternal_OBD_ReqErrorReset();
            }
            else
            {
                /*SWS_Dcm_00949*/
                for(i = DCM_INDEX_1; i < pMsgContext->reqDataLen; i++)
                {
                    DCM_OBD_SERVICE_REQ_DATA[i - (uint8)1] = (pMsgContext->reqData[i]);
                    if(((pMsgContext->reqData[i]) % DCM_OBD_AVAILABILITY_PARAMETER) != 0)
                    {
                        /*SWS_Dcm_00949*/
                        Result = E_NOT_OK;
                        /*Reset Dcm, do not send any negative response.*/
                        DsdInternal_OBD_ReqErrorReset();
                        break;
                    }
                }
            }
            
        }
        else
        {
            if((pMsgContext->reqDataLen) != (Dcm_MsgLenType)2)
            {
                /*request InfoType not supported*/
                Result = E_NOT_OK;
                /*Reset Dcm, do not send NRC 0x13.*/
                DsdInternal_OBD_ReqErrorReset();
            }
            else
            {
                /*One byte ServiceId and one byte InfoType, then continue to read InfoType data.*/
                ReqInfoType = (pMsgContext->reqData[DCM_INDEX_1]);
                Result = E_NOT_OK;

                for(i = (uint8)0; i < DCM_CFG_INFOTYPE_NUM; i++)
                {
                    if(ReqInfoType == DCM_CFG_INFOTYPE_ID(i))
                    {
                        Result = E_OK;
                        DCM_OBD_INFOTYPE_INDEX = i;
                        break;
                    }
                }

                if(Result == E_NOT_OK)
                {
                    /*request InfoType not supported*/
                    /*Reset Dcm, do not send NRC 0x13.*/
                    DsdInternal_OBD_ReqErrorReset();
                }
                else
                {
                    /*One byte ServiceId and one byte InfoType, then continue to read InfoType data.*/
                    pMsgContext->resDataLen = (Dcm_MsgLenType)2;
                }
            }
        }
    }

    /*Read data*/
    if((Result == E_OK) \
        && (((pMsgContext->reqData[DCM_INDEX_1]) % DCM_OBD_AVAILABILITY_PARAMETER) == 0))
    {
        pMsgContext->resDataLen = (Dcm_MsgLenType)1;
        /*SWS_Dcm_00422*/
        for(i = (uint8)0; i < (pMsgContext->reqDataLen - (Dcm_MsgLenType)1); i++)
        {
            RowPara = ((DCM_OBD_SERVICE_REQ_DATA[i]) / DCM_OBD_AVAILABILITY_PARAMETER);

            if((RowPara == (uint8)0) || ((DCM_OBD_SERVICE09_AVAIL_INFO[RowPara - 1][3] & (uint8)0x01) != (uint8)0))
            {
                /*Put the request availability PID in response message buffer.*/
                pMsgContext->resData[pMsgContext->resDataLen] = DCM_OBD_SERVICE_REQ_DATA[i];
                pMsgContext->resDataLen += (Dcm_MsgLenType)1;

                for(j = 0; j < (uint8)4; j++)
                {
                    pMsgContext->resData[pMsgContext->resDataLen + j] = DCM_OBD_SERVICE09_AVAIL_INFO[RowPara][j];
                }
                pMsgContext->resDataLen += (Dcm_MsgLenType)4;
            }
        }/*for(i = (uint8)0; i < (pMsgContext->reqDataLen - (Dcm_MsgLenType)1); i++)*/
    }
    else if(Result == E_OK)
    {
        /*One byte ServiceId and one byte InfoType.*/
        if(pMsgContext->resMaxDataLen > (DCM_DATA_U8_MAX + DCM_INDEX_2))
        {
            DataLength = DCM_DATA_U8_MAX;
        }
        else
        {
            DataLength = (pMsgContext->resMaxDataLen - DCM_INDEX_2);
        }
        DataBuffer = &(pMsgContext->resData[DCM_INDEX_2]);
        /*SWS_Dcm_00423*//*Read the InfoType data*/
        Result = DspInternal_09_ReadInfoTypeData(OpStatus, DataBuffer, &DataLength);

        if(Result == E_OK)
        {
            /*Send positve respnse.*/
            pMsgContext->resData[DCM_SID_INDEX] = DCM_REQ_SERVICE;
            pMsgContext->resData[DCM_INDEX_1] = (pMsgContext->reqData[DCM_INDEX_1]);
            pMsgContext->resDataLen = (DCM_INDEX_2 + DataLength);
        }
        else if(Result == E_NOT_OK)
        {
            /*SWS_Dcm_01191,but i think the NRC should be 0x22, not 0x12.*/
            *pErrorCode = DCM_E_CONDITIONSNOTCORRECT;
        }
        else/*Result == DCM_E_PENDING*/
        {
            /*Call the function next task loop.*/
        }
    }
    else
    {
        /*do nothing*/
    }

    if((Result == E_NOT_OK) || (pMsgContext->resDataLen == (Dcm_MsgLenType)1))
    {
        /*if Result equals E_OK and the response length is 1,
        it means that no request infotypes supported in the ECU.*/
        DsdInternal_OBD_ReqErrorReset();
    }
    else
    {
        /*Send positive response.*/
        pMsgContext->resData[DCM_SID_INDEX] = DCM_REQ_SERVICE;
    }

    return Result;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DspInternal_09_ReadInfoTypeData
*
* Description: Read the data of one InfoType.
*
* Inputs:
*
* Outputs:
*
* Return:
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, DCM_CODE) DspInternal_09_ReadInfoTypeData
(
    Dcm_OpStatusType OpStatus,
    uint8 *DataBuffer,
    uint8 *Length
)
{
    Std_ReturnType Result = E_OK;
    uint8 DataOrder;
    uint8 *DataElementBuffer;
    uint8 DataLength;
    EcucFncVehInfoDataReadDef DataReadFnc;

    for( ; DCM_OBD_INFOTYPE_DATA_INDEX < DCM_CFG_INFOTYPE_DATA_NUM(DCM_OBD_INFOTYPE_INDEX); )
    {
        /*SWS_Dcm_00423*/
        DataReadFnc = DCM_CFG_INFOTYPE_DATA_FNC(DCM_OBD_INFOTYPE_INDEX, DCM_OBD_INFOTYPE_DATA_INDEX);
        DataOrder = DCM_CFG_INFOTYPE_DATA_ORDER(DCM_OBD_INFOTYPE_INDEX, DCM_OBD_INFOTYPE_DATA_INDEX);
        DataElementBuffer = (DataBuffer + DataOrder);
        DataLength = (*Length - DataOrder);
        Result = (*DataReadFnc)(OpStatus, DataElementBuffer, &DataLength);

        if(Result != E_OK)
        {
            break;
        }
        else/*Result == E_OK*/
        {
            if(DCM_CFG_INFOTYPE_NOD_PRO(DCM_OBD_INFOTYPE_INDEX) == TRUE)
            {
                /*SWS_Dcm_01167*//*constr_6045: In case the responsibility is on provider side
                (DcmDspVehInfoNODIProvResp is set to TRUE), only one DcmDspVehInfoData container
                shall be allowed.*/
                *Length = (DataOrder + DataLength);
                break;/*for( ; DCM_OBD_INFOTYPE_DATA_INDEX < DCM_CFG_INFOTYPE_DATA_NUM(DCM_OBD_INFOTYPE_INDEX); )*/
            }
            else
            {
                /*SWS_Dcm_00684*/
                if((DCM_OBD_INFOTYPE_DATA_INDEX + (uint8)1) == DCM_CFG_INFOTYPE_DATA_NUM(DCM_OBD_INFOTYPE_INDEX))
                {
                    DataLength = DCM_CFG_INFOTYPE_DATA_SIZE(DCM_OBD_INFOTYPE_INDEX, DCM_OBD_INFOTYPE_DATA_INDEX);
                    *Length = (DataOrder + DataLength);
                }

                DCM_OBD_INFOTYPE_DATA_INDEX++;
            }
        }
    }

    return Result;
}
#endif

#define DCM_STOP_SEC_CODE
#include "MemMap.h"


/*******************************************************************************
* Global Function definition
*******************************************************************************/
#define DCM_START_SEC_CODE
#include "MemMap.h"
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dcm_Init
*
* Description: Service for basic initialization of DCM module.
*
* Inputs: ConfigPtr: Pointer pointing to the configure parameter of Dcm
*
* Outputs: None
*
* Return: None
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
/*SWS_Dcm_00037*/
FUNC(void, DCM_CODE) Dcm_Init
(
    P2CONST(uint32, AUTOMATIC, DCM_APPL_DATA) ConfigPtr
)
{
#if(DCM_UDS_27_SERVICE == STD_ON)
    uint8 i;
    uint8 j;
    Std_ReturnType ret = E_OK;
#endif

#if(DCM_CONFIG_VARIANTS == STD_CONFIG_VARIANTS_POSTBUILD)
    if(NULL_PTR == ConfigPtr)
    {
        DCM_DET_REPORT_ERROR(DCM_SID_INIT, DCM_E_PARAM_POINTER);
    }
    else
    {
        Dcm_ConfigPtr = ConfigPtr;
#else
    (void)ConfigPtr;
#endif

#if(DCM_UDS_27_SERVICE == STD_ON)
        /*SWS_Dcm_00033*/
        DslInternal_SetSecurityLevel(DCM_SECURITY_LOCKED_LEVEL);

        for(i = (uint8)0; i < DCM_CFG_NUM_OF_PROTOCOL; i++)
        {
            DCM_ACTIVE_PROTOCOL_ID = i;

            for(j = (uint8)0; j < DCM_CFG_SECURITY_NUM(i); j++)
            {
                /*SWS_Dcm_01157*/
                if((DCM_CFG_SECURITY_ATTEMPFNC_EN(j) == TRUE) \
                    && (DCM_CFG_SECURITY_GET_ATTEMP_FNC(j) != NULL_PTR))
                {
                    /*SWS_Dcm_01154*/
                    ret = DCM_CFG_SECURITY_GET_ATTEMP_FNC(j)(DCM_INITIAL, &(DCM_SECURITY_ATTEMP_NUM(i, j)));

                    if(ret == E_NOT_OK)
                    {
                        /*SWS_Dcm_01156*/
                        DCM_SECURITY_ATTEMP_NUM(i, j) = DCM_DATA_CLEAR;
                    }
                    DCM_SECURITY_DELAY_TIME(i, j) = DCM_CFG_SECURITY_DELAYTIME(j);
                    DCM_SECURITY_DELAY_ON_BOOT(i, j) = FALSE;
                }
                else
                {
                    DCM_SECURITY_ATTEMP_NUM(i, j) = DCM_CFG_SECURITY_ATTEMPNUM(j);
                    DCM_SECURITY_DELAY_TIME(i, j) = DCM_CFG_SECURITY_DELAYTIMEONBOOT(j);
                    DCM_SECURITY_DELAY_ON_BOOT(i, j) = TRUE;
                }
                DCM_SECURITY_SEQUENCE(i, j) = FALSE;
            }
        }
#if(DCM_CFG_MANUFACTORY_MODE_SUPPORT == STD_ON)
        if(TRUE == Dcm_CheckManufactoryMode())
        {
            DslInternal_SetSecurityLevel(DCM_SECURITY_ALL_LEVEL);
        }
#endif
#endif/*#if(DCM_UDS_27_SERVICE == STD_ON)*/

#if((DCM_OBD_01_SERVICE == STD_ON)||(DCM_OBD_02_SERVICE == STD_ON) \
    ||(DCM_OBD_08_SERVICE == STD_ON)||(DCM_OBD_09_SERVICE == STD_ON))
        DcmInternal_Init_AvailabilityParameters();
#endif
        /*Init Dcm context*/
        DcmInternal_InitDcmContext();

        Dcm_InitState = STD_INITIALIZED;
#if(DCM_CONFIG_VARIANTS == STD_CONFIG_VARIANTS_POSTBUILD)
    }
#endif
}


#if(STD_ON == DCM_VERSION_INFO_API)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dcm_GetVersionInfo
*
* Description: Returns the version information of this module
*
* Inputs: None
*
* Outputs: versionInfo:Pointer to where to store the version information of
*          this module.
*
* Return: None
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
/*SWS_Dcm_00065*/
FUNC(void, DCM_CODE) Dcm_GetVersionInfo
(
    P2VAR(Std_VersionInfoType, AUTOMATIC, DCM_APPL_DATA) versionInfo
)
{
    if(NULL_PTR == versionInfo)
    {
        DCM_DET_REPORT_ERROR(DCM_SID_GETVERSIONINFO, DCM_E_PARAM_POINTER);
    }
    else
    {
        versionInfo->vendorID = DCM_VENDOR_ID;
        versionInfo->moduleID = DCM_MODULE_ID;

        versionInfo->sw_major_version = DCM_SW_MAJOR_VERSION;
        versionInfo->sw_minor_version = DCM_SW_MINOR_VERSION;
        versionInfo->sw_patch_version = DCM_SW_PATCH_VERSION;
    }
}
#endif

#if 0
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dcm_DemTriggerOnDTCStatus
*
* Description: Triggers on changes of the UDS DTC status byte. Allows to
*              trigger on ROE Event for subservice OnDTCStatusChanged
*
* Inputs: DTC: This is the DTC the change trigger is assigned to.
*         DTCStatusOld: DTC status before change
*         DTCStatusNew: DTC status after change
*
* Outputs: None
*
* Return: E_OK: this value is always returned.
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
/*SWS_Dcm_00614*/
FUNC(Std_ReturnType, DCM_CODE) Dcm_DemTriggerOnDTCStatus
(
    uint32 DTC,
    uint8 DTCStatusOld,
    uint8 DTCStatusNew
)
{
    return E_OK;
}
#endif


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dcm_GetVin
*
* Description: Function to get the VIN (as defined in SAE J1979-DA)
*
* Inputs: None
*
* Outputs: Data: Pointer to where to store the VIN
*
* Return: E_OK: The Data pointer has been filled with valid VIN
*         E_NOT_OK: The default VIN will be used in the DoIP
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
/*SWS_Dcm_00950*/
FUNC(Std_ReturnType, DCM_CODE) Dcm_GetVin
(
    P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data
)
{
    Std_ReturnType Result = E_NOT_OK;
#if((DCM_UDS_22_SERVICE == STD_ON) && (DCM_VIN_REF != DCM_INVALID_DID))
    uint16 DataNum;
    uint16 DataIndex;
    uint16 DataPos;
    uint16 DataRef;
    uint16 FncIndex;
    Dcm_NegativeResponseCodeType ErrorCode;/*useless*/
    uint8 ProtocolIdTempBuf = DCM_ACTIVE_PROTOCOL_ID;
    DCM_ACTIVE_PROTOCOL_ID = DCM_VIN_IN_PROTOCOL;

    if(Data == NULL_PTR)
    {
        DCM_DET_REPORT_ERROR(DCM_SID_GETVIN, DCM_E_PARAM_POINTER);
    }
    else if(DCM_VIN_REF >= DCM_CFG_DID_NUM)
    {
        DCM_DET_REPORT_ERROR(DCM_SID_GETVIN, DCM_E_PARAM);
    }
    else if(FALSE == DCM_CFG_DID_USED(DCM_VIN_REF))
    {
        /*Result = E_NOT_OK;*/
    }
    else
    {
        /*read all reference data*/
        for(DataIndex = 0; DataIndex < DCM_CFG_DID_SIGNAL_NUM(DCM_VIN_REF); DataIndex++)
        {
            DataPos = DCM_CFG_DID_SIGNAL(DCM_VIN_REF)[DataIndex].DcmDspDidDataPos;
            DataRef = DCM_CFG_DID_SIGNAL(DCM_VIN_REF)[DataIndex].DcmDspDidDataRef;
            DataPos = (DataPos >> 3U);

            if((DCM_USE_DATA_ASYNCH_FNC == DCM_CFG_DATA_USEPORT(DataRef)) \
                || (DCM_USE_DATA_ASYNCH_CLIENT_SERVER == DCM_CFG_DATA_USEPORT(DataRef)))
            {
                FncIndex = DCM_CFG_DATA_READ_FNC_INDEX(DataRef);
                /*return value: E_OK/E_NOT_OK/DCM_E_PENDING*/
                Result = DCM_CFG_DATA_READ_FNC_A(FncIndex)(DCM_INITIAL, (Data + DataPos));
            }
            else if((DCM_USE_DATA_ASYNCH_FNC_ERROR == DCM_CFG_DATA_USEPORT(DataRef)) \
                || (DCM_USE_DATA_ASYNCH_CLIENT_SERVER_ERROR == DCM_CFG_DATA_USEPORT(DataRef)))
            {
                FncIndex = DCM_CFG_DATA_READ_FNC_INDEX(DataRef);
                /*return value: E_OK/E_NOT_OK/DCM_E_PENDING*/
                Result = DCM_CFG_DATA_READ_FNC_B(FncIndex)(DCM_INITIAL, (Data + DataPos), &ErrorCode);
            }
            else if((DCM_USE_DATA_SYNCH_FNC == DCM_CFG_DATA_USEPORT(DataRef)) \
                || (DCM_USE_DATA_SYNCH_CLIENT_SERVER == DCM_CFG_DATA_USEPORT(DataRef)))
            {
                FncIndex = DCM_CFG_DATA_READ_FNC_INDEX(DataRef);
                /*return value: E_OK/E_NOT_OK*/
                Result = DCM_CFG_DATA_READ_FNC_C(FncIndex)((Data + DataPos));
            }
            else
            {
                Result = E_NOT_OK;
            }

            if(Result != E_OK)
            {
                Result = E_NOT_OK;
                break;
            }
        }
    }
    DCM_ACTIVE_PROTOCOL_ID = ProtocolIdTempBuf;
#endif
    return Result;
}


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dcm_MainFunction
*
* Description: This service is used for processing the tasks of the main loop.
*
* Inputs: None
*
* Outputs: None
*
* Return: None
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
/*SWS_Dcm_00053*/
FUNC(void, DCM_CODE) Dcm_MainFunction
(
    void
)
{
    if(STD_UNINITIALIZED != Dcm_InitState)
    {
        SchM_Enter_Dcm_DCM_EXCLUSIVE_AREA_0();
        DsdInternal_MainFunction();
        DspInternal_MainFunction();
        DslInternal_MainFunction();
        SchM_Exit_Dcm_DCM_EXCLUSIVE_AREA_0();
    }
}

#if(DCM_UDS_27_SERVICE == STD_ON)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dcm_GetSecurityLevel
*
* Description: This function provides the active security level value.
*
* Inputs: None
*
* Outputs: Active Security Level value
*
* Return: E_OK: this value is always returned.
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
/*SWS_Dcm_00338*/
FUNC(Std_ReturnType, DCM_CODE) Dcm_GetSecurityLevel
(
    P2VAR(Dcm_SecLevelType, AUTOMATIC, DCM_APPL_DATA) SecLevel
)
{
    Std_ReturnType Result = E_NOT_OK;

    if(STD_UNINITIALIZED == Dcm_InitState)
    {
        DCM_DET_REPORT_ERROR(DCM_SID_GETSECURITYLEVEL, DCM_E_UNINIT);
    }
    else if(SecLevel == NULL_PTR)
    {
        DCM_DET_REPORT_ERROR(DCM_SID_GETSECURITYLEVEL, DCM_E_PARAM_POINTER);
    }
    else
    {
        *SecLevel = DCM_SECURITY_LEVEL;
        Result = E_OK;
    }
    return Result;
}
#endif

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dcm_GetSesCtrlType
*
* Description: This function provides the active session control type value.
*
* Inputs: None
*
* Outputs: Active Session Control Type value
*
* Return: E_OK: this value is always returned.
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
/*SWS_Dcm_00339*/
FUNC(Std_ReturnType, DCM_CODE) Dcm_GetSesCtrlType
(
    P2VAR(Dcm_SesCtrlType, AUTOMATIC, DCM_APPL_DATA) SesCtrlType
)
{
    Std_ReturnType Result = E_OK;

    if(STD_UNINITIALIZED == Dcm_InitState)
    {
        DCM_DET_REPORT_ERROR(DCM_SID_GETSESCTRLTYPE, DCM_E_UNINIT);
        Result = E_NOT_OK;
    }
    else if(SesCtrlType == NULL_PTR)
    {
        DCM_DET_REPORT_ERROR(DCM_SID_GETSESCTRLTYPE, DCM_E_PARAM_POINTER);
        Result = E_NOT_OK;
    }
    else
    {
        *SesCtrlType = DCM_CFG_SESSION_LEVEL(DCM_SESSION_LEVEL);
    }
    return Result;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dcm_GetActiveProtocol
*
* Description: This function returns the active protocol name.
*
* Inputs: None
*
* Outputs: Active protocol type value
*
* Return: E_OK: this value is always returned.
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
/*SWS_Dcm_00340*/
FUNC(Std_ReturnType, DCM_CODE) Dcm_GetActiveProtocol
(
    P2VAR(Dcm_ProtocolType, AUTOMATIC, DCM_APPL_DATA) ActiveProtocol
)
{
    Std_ReturnType Result = E_OK;

    if(STD_INITIALIZED != Dcm_InitState)
    {
        DCM_DET_REPORT_ERROR(DCM_SID_GETACTIVEPROTOCOL, DCM_E_UNINIT);
        Result = E_NOT_OK;
    }
    else if(ActiveProtocol == NULL_PTR)
    {
        DCM_DET_REPORT_ERROR(DCM_SID_GETACTIVEPROTOCOL, DCM_E_PARAM_POINTER);
        Result = E_NOT_OK;
    }
    else
    {
        *ActiveProtocol = DCM_CFG_PROTOCOL_ID(DCM_ACTIVE_PROTOCOL_ID);
    }
    return Result;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dcm_ResetToDefaultSession
*
* Description: The call to this function allows the application to reset the
*              current session to Default session.
*
* Inputs: None
*
* Outputs: None
*
* Return: E_OK: this value is always returned.
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
/*SWS_Dcm_00520*/
FUNC(Std_ReturnType, DCM_CODE) Dcm_ResetToDefaultSession
(
    void
)
{
    Std_ReturnType Result = E_OK;

    if(STD_INITIALIZED != Dcm_InitState)
    {
        DCM_DET_REPORT_ERROR(DCM_SID_RESETTODEFAULTSESSION, DCM_E_UNINIT);
        Result = E_NOT_OK;
    }
    else
    {
        ClearS3Timer();

        if(DCM_SESSION_LEVEL != DCM_DEFAULT_LEVEL)
        {
            COMM_DCM_INACTIVEDIAGNOSTIC(DCM_ACTIVE_PROTOCOL_ID, DCM_ACTIVE_CONNECTION_ID);
        }
        /*SWS_Dcm_01062*//*SWS_Dcm_00140*/
        DslInternal_SetSesCtrlType(DCM_DEFAULT_LEVEL);
    }
    return Result;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dcm_TriggerOnEvent
*
* Description: The call to this function allows to trigger an event linked to a
*              ResponseOnEvent request.
*
* Inputs: RoeEventId: Identifier of the event that is triggered
*
* Outputs: None
*
* Return: E_OK: RoeEventId value is valid
*         E_NOT_OK: RoeEventId value is not valid
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
/*SWS_Dcm_00521*/
FUNC(Std_ReturnType, DCM_CODE) Dcm_TriggerOnEvent
(
    uint8 RoeEventId
)
{
    Std_ReturnType Result = E_NOT_OK;

    (void)RoeEventId;
    /*Not implemented*/

    return Result;
}

#if(DCM_COMM_SUPPORT == STD_ON)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dcm_SetActiveDiagnostic
*
* Description: Allows to activate and deactivate the call of
*              ComM_DCM_ActiveDiagnostic() function.
*
* Inputs: active: If false Dcm shall not call ComM_DCM_ActiveDiagnostic().
*                 If true Dcm will call ComM_DCM_ActiveDiagnostic().
*
* Outputs: None
*
* Return: E_OK: this value is always returned.
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
/*SWS_Dcm_01068*/
FUNC(Std_ReturnType, DCM_CODE) Dcm_SetActiveDiagnostic
(
    boolean active
)
{
    Std_ReturnType Result = E_NOT_OK;

    if(STD_INITIALIZED == Dcm_InitState)
    {
        DCM_ACTIVE_DIAGNOSTIC = active;
        Result = E_OK;
    }
    return Result;
}
#endif

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dcm_ExternalSubServiceCheck
*
* Description:
*
* Inputs:
*
* Outputs:
*
* Return:
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, DCM_CODE) Dcm_ExternalSubServiceCheck
(
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
)
{
    Std_ReturnType Result = E_OK;

    Result = DsdInternal_CheckSubServiceId();

    if(Result != E_OK)
    {
        *pErrorCode = DCM_E_SUBFUNCTIONNOTSUPPORTED;
    }
    else
    {
        Result = DspInternal_AddrSesSecCheck(pErrorCode);

        if(Result == E_OK)
        {
#if(DCM_CAR_PLATFORM == DCM_GEELY_PLATFORM)
            SetP4Timer(DCM_REQ_SERVICEINFO->P4ServerMax);
#endif
        }
    }
    return Result;
}


#define DCM_STOP_SEC_CODE
#include "MemMap.h"


#define DCM_START_SEC_CODE
#include "MemMap.h"

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dcm_StartOfReception
*
* Description: This function is called at the start of receiving an N-SDU. The
*              N-SDU might be fragmented into multiple N-PDUs (FF with one or more
*              following CFs) or might consist of a single N-PDU (SF).
*
* Inputs: id: Identification of the I-PDU.
*         info: Pointer to a PduInfoType structure containing the payload data
*               (without protocol information) and payload length of the first
*               frame or single frame of a transport protocol I-PDU reception.
*         TpSduLength: Total length of the N-SDU to be received.
*
* Outputs: bufferSizePtr: Available receive buffer in the receiving module.This
*                         parameter will be used to compute the Block Size (BS)
*                         in the transport protocol module.
*
* Return: BUFREQ_OK: Connection has been accepted.
*         BUFREQ_E_NOT_OK: Connection has been rejected.
*         BUFREQ_E_OVFL: No buffer of the required length can be provided.
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
/*SWS_Dcm_00094*/
FUNC(BufReq_ReturnType, DCM_CODE) Dcm_StartOfReception
(
    PduIdType id,
    P2CONST(PduInfoType, AUTOMATIC, DCM_APPL_DATA) info,
    PduLengthType TpSduLength,
    P2VAR(PduLengthType, AUTOMATIC, DCM_APPL_DATA) bufferSizePtr
)
{
    Std_ReturnType ret = E_NOT_OK;
    BufReq_ReturnType Result = BUFREQ_E_NOT_OK;
    uint8 ProtocolRowId;
    uint8 i;
    uint8 j;

    (void)info;
    if(STD_INITIALIZED != Dcm_InitState)
    {
        DCM_DET_REPORT_ERROR(DCM_SID_STARTOFRECEPTION, DCM_E_UNINIT);
    }
    else if(id >= DCM_CFG_RXPDU_NUM)
    {
        DCM_DET_REPORT_ERROR(DCM_SID_STARTOFRECEPTION, DCM_E_PARAM);
    }
    else if(TpSduLength == 0U)
    {
        DCM_DET_REPORT_ERROR(DCM_SID_STARTOFRECEPTION, DCM_E_PARAM);
    }
    else if(NULL_PTR == bufferSizePtr)
    {
        DCM_DET_REPORT_ERROR(DCM_SID_STARTOFRECEPTION, DCM_E_PARAM_POINTER);
    }
    else if((DCM_CFG_RXPDU_TO_PROTOCOL_MAP(id) > DCM_CFG_NUM_OF_PROTOCOL) \
        || (DCM_CFG_PROTOCOL_USED(DCM_CFG_RXPDU_TO_PROTOCOL_MAP(id)) == FALSE))
    {
        /*Result = BUFREQ_E_NOT_OK;*/
    }
    else if((NULL_PTR == DCM_CFG_PROTOCOL_CONNECTION(DCM_CFG_RXPDU_TO_PROTOCOL_MAP(id))) \
        || (DCM_CFG_PROTOCOL_CONNECTION_NUM(DCM_CFG_RXPDU_TO_PROTOCOL_MAP(id)) == 0U))
    {
        /*Result = BUFREQ_E_NOT_OK;*/
    }
    else
    {
        ProtocolRowId = DCM_CFG_RXPDU_TO_PROTOCOL_MAP(id);

        for(i = 0U; i < DCM_CFG_PROTOCOL_CONNECTION_NUM(ProtocolRowId); i++)
        {
            if(NULL_PTR != (DCM_CFG_PROTOCOL_CONNECTION_MAIN(ProtocolRowId, i)))
            {
                for(j = 0U; j < DCM_CFG_PROTOCOL_CONNECTION_MAIN_RX_NUM(ProtocolRowId, i); j++)
                {
                    if((NULL_PTR != DCM_CFG_PROTOCOL_CONNECTION_MAIN_RX(ProtocolRowId, i)) \
                        && (id == DCM_CFG_PROTOCOL_CONNECTION_MAIN_RX_PDUID(ProtocolRowId, i, j)))
                    {
                        ret = E_OK;
                        break;
                    }
                }
            }

            if(ret == E_OK)
            {
                break;
            }
        }
    }

    if(ret == E_OK)
    {
        if(DCM_PCL_RX_PDU_ID(ProtocolRowId) != COMSTACK_INVALID_PDUID)
        {
            /*Result = BUFREQ_E_NOT_OK;*/
        }
        else if((TpSduLength > DCM_CFG_PROTOCOL_RXBUFFER_SIZE(ProtocolRowId)) \
            || (NULL_PTR == DCM_CFG_PROTOCOL_RXBUFFER(ProtocolRowId)))
        {
            /*SWS_Dcm_00444*/
            Result = BUFREQ_E_OVFL;
        }
        else
        {
            DCM_PCL_RX_PDU_ID(ProtocolRowId) = id;
            DCM_PCL_RX_DATA_LEN(ProtocolRowId) = TpSduLength;
            DCM_PCL_DATA_INDEX(ProtocolRowId) = DCM_DATA_CLEAR;
            DCM_PCL_RX_CON_ID(ProtocolRowId) = i;
            DCM_PCL_RX_ID(ProtocolRowId) = j;

            *bufferSizePtr = DCM_CFG_PROTOCOL_RXBUFFER_SIZE(ProtocolRowId);

            if(DCM_ACTIVE_PROTOCOL_ID == ProtocolRowId)
            {
                ClearS3Timer();
            }

            Result = BUFREQ_OK;
        }
    }
    return Result;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dcm_CopyRxData
*
* Description: This function is called to provide the received data of an I-PDU
*              segment (N-PDU) to the upper layer.Each call to this function
*              provides the next part of the I-PDU data.The size of the remaining
*              data is written to the position indicated by bufferSizePtr.
*
* Inputs: id: Identification of the received I-PDU.
*         info: Provides the source buffer (SduDataPtr) and the number of bytes
*               to be copied (SduLength)
*
* Outputs: bufferSizePtr: Available receive buffer after data has been copied.
*
* Return: BUFREQ_OK: Data copied successfully
*         BUFREQ_E_NOT_OK: Data was not copied because an error occurred.
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
/*SWS_Dcm_00556*/
FUNC(BufReq_ReturnType, DCM_CODE) Dcm_CopyRxData
(
    PduIdType id,
    P2CONST(PduInfoType, AUTOMATIC, DCM_APPL_DATA) info,
    P2VAR(PduLengthType, AUTOMATIC, DCM_APPL_DATA) bufferSizePtr
)
{
    BufReq_ReturnType Result = BUFREQ_E_NOT_OK;
    uint8 *DestPtr = NULL_PTR;
    uint8 ProtocolRowId;

    if(STD_INITIALIZED != Dcm_InitState)
    {
        DCM_DET_REPORT_ERROR(DCM_SID_COPYRXDATA, DCM_E_UNINIT);
    }
    else if(id >= DCM_CFG_RXPDU_NUM)
    {
        DCM_DET_REPORT_ERROR(DCM_SID_COPYRXDATA, DCM_E_PARAM);
    }
    else if(NULL_PTR == info)
    {
        DCM_DET_REPORT_ERROR(DCM_SID_COPYRXDATA, DCM_E_PARAM_POINTER);
    }
    else if(NULL_PTR == info->SduDataPtr)
    {
        DCM_DET_REPORT_ERROR(DCM_SID_COPYRXDATA, DCM_E_PARAM_POINTER);
    }
    else if(NULL_PTR == bufferSizePtr)
    {
        DCM_DET_REPORT_ERROR(DCM_SID_COPYRXDATA, DCM_E_PARAM_POINTER);
    }
    else
    {
        ProtocolRowId = DCM_CFG_RXPDU_TO_PROTOCOL_MAP(id);

        if(DCM_PCL_RX_PDU_ID(ProtocolRowId) == id)
        {
            if((PduLengthType)0 == (info->SduLength))
            {
                *bufferSizePtr = DCM_PCL_RX_DATA_LEN(ProtocolRowId) - DCM_PCL_DATA_INDEX(ProtocolRowId);
            }
            else if((info->SduLength) > (DCM_PCL_RX_DATA_LEN(ProtocolRowId) - DCM_PCL_DATA_INDEX(ProtocolRowId)))
            {
                *bufferSizePtr = DCM_PCL_RX_DATA_LEN(ProtocolRowId) - DCM_PCL_DATA_INDEX(ProtocolRowId);
                Result = BUFREQ_E_OVFL;
            }
            else
            {
                SchM_Enter_Dcm_DCM_EXCLUSIVE_AREA_0();

                DestPtr = (DCM_CFG_PROTOCOL_RXBUFFER(ProtocolRowId) + DCM_PCL_DATA_INDEX(ProtocolRowId));
                Bsw_MemCpy(DestPtr, info->SduDataPtr, info->SduLength);
                DCM_PCL_DATA_INDEX(ProtocolRowId) += (info->SduLength);
                *bufferSizePtr = DCM_PCL_RX_DATA_LEN(ProtocolRowId) - DCM_PCL_DATA_INDEX(ProtocolRowId);

                SchM_Exit_Dcm_DCM_EXCLUSIVE_AREA_0();

                Result = BUFREQ_OK;
            }
        }
    }
    return Result;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dcm_TpRxIndication
*
* Description: Called after an I-PDU has been received via the TP API, the
*              result indicates whether the transmission was successful or not.
*
* Inputs: id: Identification of the received I-PDU.
*         result: Result of the reception.
*
* Outputs: None
*
* Return: None
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
/*SWS_Dcm_00093*/
FUNC(void, DCM_CODE) Dcm_TpRxIndication
(
    PduIdType id,
    Std_ReturnType result
)
{
    uint8 ProtocolRowId;

    if(STD_INITIALIZED != Dcm_InitState)
    {
        DCM_DET_REPORT_ERROR(DCM_SID_TPRXINDICATION, DCM_E_UNINIT);
    }
    else if(id >= DCM_CFG_RXPDU_NUM)
    {
        DCM_DET_REPORT_ERROR(DCM_SID_TPRXINDICATION, DCM_E_PARAM);
    }
    else
    {
        ProtocolRowId = DCM_CFG_RXPDU_TO_PROTOCOL_MAP(id);

        /*SWS_Dcm_00111*//*SWS_Dcm_00241*/
        if(DCM_PCL_RX_PDU_ID(ProtocolRowId) == id)
        {
            if(result == E_OK)
            {
                DslInternal_CheckProtocolPermission(ProtocolRowId);
            }
            else
            {
                if((DCM_ACTIVE_PROTOCOL_ID == ProtocolRowId) && (DCM_SESSION_LEVEL != DCM_DEFAULT_LEVEL))
                {
                    SetS3Timer(DCM_CFG_PROTOCOL_S3SERVER(DCM_ACTIVE_PROTOCOL_ID));
                }

                /*Clear the new received pdu info of protocol identified by ProtocolRowId.*/
                DCM_PCL_RX_PDU_ID(ProtocolRowId) = COMSTACK_INVALID_PDUID;
            }
        }
    }
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dcm_CopyTxData
*
* Description: This function is called to acquire the transmit data of an I-PDU
*              segment (N-PDU).
*
* Inputs: id: Identification of the transmitted I-PDU.
*         info: Provides the destination buffer (SduDataPtr) and the number of
*               bytes to be copied (SduLength).
*         retry: This parameter is used to acknowledge transmitted data or to
*                retransmit data after transmission problems.
*
* Outputs: availableDataPtr: Indicates the remaining number of bytes that are
*                            available in the upper layer module's Tx buffer.
*
* Return: BUFREQ_OK: Data has been copied to the transmit buffer completely as
*                    requested.
*         BUFREQ_E_BUSY: Request could not be fulfilled, because the required
*                        amount of Tx data is not available. The lower layer
*                        module may retry this call later on. No data has been
*                        copied.
*         BUFREQ_E_NOT_OK: Data has not been copied. Request failed.
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
/*SWS_Dcm_00092*/
FUNC(BufReq_ReturnType, DCM_CODE) Dcm_CopyTxData
(
    PduIdType id,
    P2CONST(PduInfoType, AUTOMATIC, DCM_APPL_DATA) info,
    P2VAR(RetryInfoType, AUTOMATIC, DCM_APPL_DATA) retry,
    P2VAR(PduLengthType, AUTOMATIC, DCM_APPL_DATA) availableDataPtr
)
{
    BufReq_ReturnType Result = BUFREQ_E_NOT_OK;
    uint8 *SrcPtr = NULL_PTR;
    uint8 ProtocolId;

    (void)retry;
    if(STD_INITIALIZED != Dcm_InitState)
    {
        DCM_DET_REPORT_ERROR(DCM_SID_COPYTXDATA, DCM_E_UNINIT);
    }
    else if(NULL_PTR == info)
    {
        DCM_DET_REPORT_ERROR(DCM_SID_COPYTXDATA, DCM_E_PARAM_POINTER);
    }
    else if((0U != info->SduLength) && (NULL_PTR == info->SduDataPtr))
    {
        DCM_DET_REPORT_ERROR(DCM_SID_COPYTXDATA, DCM_E_PARAM_POINTER);
    }
    else if(NULL_PTR == availableDataPtr)
    {
        DCM_DET_REPORT_ERROR(DCM_SID_COPYTXDATA, DCM_E_PARAM_POINTER);
    }
    else
    {
        SchM_Enter_Dcm_DCM_EXCLUSIVE_AREA_0();

        if((DCM_ACTIVE_PROTOCOL_ID != DCM_CFG_NUM_OF_PROTOCOL) \
            && (id == DCM_CFG_PROTOCOL_CONNECTION_MAIN_TX_CONID(DCM_ACTIVE_PROTOCOL_ID, DCM_ACTIVE_CONNECTION_ID)))
        {
            if((CheckDcmState((DCM_RCRRP | DCM_RCRRP_FORCE))) || (DCM_ERRORCODE != DCM_POSITIVE_RESPONSE))
            {
                if(0U == info->SduLength)
                {
                    *availableDataPtr = DCM_UDS_NEG_RES_LEN;
                }
                else
                {
                    Bsw_MemCpy(info->SduDataPtr, DCM_PCL_NEG_BUFFER(DCM_ACTIVE_PROTOCOL_ID), DCM_UDS_NEG_RES_LEN);
                    *availableDataPtr = DCM_DATA_CLEAR;
                }
            }
            else
            {
                if(0U == info->SduLength)
                {
                    *availableDataPtr = (DCM_MSGCONTEXT.resDataLen - DCM_MSGCONTEXT.CopyDataIndex);
                }
                else
                {
                    SrcPtr = (DCM_MSGCONTEXT.resData + DCM_MSGCONTEXT.CopyDataIndex);
                    Bsw_MemCpy(info->SduDataPtr, SrcPtr, info->SduLength);
                    DCM_MSGCONTEXT.CopyDataIndex += (info->SduLength);
                    *availableDataPtr = (DCM_MSGCONTEXT.resDataLen - DCM_MSGCONTEXT.CopyDataIndex);
                }
            }

            Result = BUFREQ_OK;
        }
        else
        {
            for(ProtocolId = (uint8)0; ProtocolId < DCM_CFG_NUM_OF_PROTOCOL; ProtocolId++)
            {
                if((DCM_PCL_RX_PDU_ID(ProtocolId) != COMSTACK_INVALID_PDUID) \
                    && (id == DCM_CFG_PROTOCOL_CONNECTION_MAIN_TX_CONID(ProtocolId, DCM_PCL_RX_CON_ID(ProtocolId))))
                {
                    if(0U == info->SduLength)
                    {
                        *availableDataPtr = DCM_UDS_NEG_RES_LEN;
                    }
                    else
                    {
                        Bsw_MemCpy(info->SduDataPtr, DCM_PCL_NEG_BUFFER(ProtocolId), DCM_UDS_NEG_RES_LEN);
                        *availableDataPtr = DCM_DATA_CLEAR;
                    }
                    Result = BUFREQ_OK;

                    break;
                }
            }
        }
        SchM_Exit_Dcm_DCM_EXCLUSIVE_AREA_0();
    }
    return Result;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dcm_TpTxConfirmation
*
* Description: This function is called after the I-PDU has been transmitted on
*              its network, the result indicates whether the transmission was
*              successful or not.
*
* Inputs: id: Identification of the transmitted I-PDU.
*         result: Result of the transmission of the I-PDU.
*
* Outputs: None
*
* Return: None
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
/*SWS_Dcm_00351*/
FUNC(void, DCM_CODE) Dcm_TpTxConfirmation
(
    PduIdType id,
    Std_ReturnType result
)
{
    uint16 SourceAddress;
     uint8 ProtocolId;

    if(STD_INITIALIZED != Dcm_InitState)
    {
        DCM_DET_REPORT_ERROR(DCM_SID_TPTXCONFIRMATION, DCM_E_UNINIT);
    }
    else
    {
        if((DCM_ACTIVE_PROTOCOL_ID != DCM_CFG_NUM_OF_PROTOCOL) \
            && (id == DCM_CFG_PROTOCOL_CONNECTION_MAIN_TX_CONID(DCM_ACTIVE_PROTOCOL_ID, DCM_ACTIVE_CONNECTION_ID)))
        {
            if(CheckDcmState((DCM_RCRRP | DCM_RCRRP_FORCE | DCM_RCRRP_REPEATTX)))
            {
                if(result == E_OK)
                {
                    if(CheckDcmState(DCM_RCRRP_FORCE))
                    {
                        SetDcmState(DCM_RCRRP_FORCE_OK);
                        DCM_OP_STATUS = DCM_FORCE_RCRRP_OK;
                    }
                    SetP2Timer(DCM_CFG_SESSION_P2STAR(DCM_SESSION_LEVEL));

                    if(!CheckRespPendCounter())
                    {
                        RunRespPendCounter();
                    }
                }
                else
                {
                    DCM_OP_STATUS = DCM_CANCEL;
                }
                ClearDcmState((DCM_RCRRP | DCM_RCRRP_REPEATTX | DCM_RCRRP_FORCE));
            }
            else if(CheckDcmState(DCM_PERIODIC_TX))
            {
                Dcm_TxConfirmation(id);
            }
            else/* Positive response or other negative response */
            {
                /*SWS_Dcm_00141*/
                if(DCM_SESSION_LEVEL != DCM_DEFAULT_LEVEL)
                {
                    SetS3Timer(DCM_CFG_PROTOCOL_S3SERVER(DCM_ACTIVE_PROTOCOL_ID));
                }
                else if(((DCM_REQ_SERVICE != DCM_10_SERVICE) \
                        && (DCM_REQ_SERVICE != DCM_11_SERVICE)) \
                        || (result != E_OK) || (DCM_ERRORCODE != DCM_POSITIVE_RESPONSE))
                {
                    COMM_DCM_INACTIVEDIAGNOSTIC(DCM_ACTIVE_PROTOCOL_ID, DCM_ACTIVE_CONNECTION_ID);
                }
                else
                {
                    /*ComM_DCM_InactiveDiagnostic of 0x10,0x11 will be executed in their ServicePostFunction*/
                }

                if((result == E_OK) && (DCM_ERRORCODE == DCM_POSITIVE_RESPONSE))
                {
                    SourceAddress = DCM_CFG_PROTOCOL_CONNECTION_MAIN_TESTER_ADDR(DCM_ACTIVE_PROTOCOL_ID, \
                                    DCM_ACTIVE_CONNECTION_ID);
                    DsdInternal_DcmConfirmation(DCM_MSGCONTEXT.idContext, SourceAddress, DCM_RES_POS_OK);
                }
                else
                {
                    DCM_ERRORCODE = DCM_POSITIVE_RESPONSE;
                    DcmInternal_InitMsgContext();
                    ResetDcmState();
                }
            }
        }
        else
        {
            for(ProtocolId = (uint8)0; ProtocolId < DCM_CFG_NUM_OF_PROTOCOL; ProtocolId++)
            {
                if((DCM_PCL_RX_PDU_ID(ProtocolId) != COMSTACK_INVALID_PDUID) \
                    && (id == DCM_CFG_PROTOCOL_CONNECTION_MAIN_TX_CONID(ProtocolId, DCM_PCL_RX_CON_ID(ProtocolId))))
                {
                    DCM_PCL_RX_PDU_ID(ProtocolId) = COMSTACK_INVALID_PDUID;

                    break;
                }
            }
        }
    }
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dcm_TxConfirmation
*
* Description: The lower layer communication interface module confirms the
*              transmission of an I-PDU.
*
* Inputs: TxPduId: ID of the I-PDU that has been transmitted.
*
* Outputs: None
*
* Return: None
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
/*SWS_Dcm_01092*/
FUNC(void, DCM_CODE) Dcm_TxConfirmation
(
    PduIdType TxPduId
)
{
	(void)TxPduId;
    ResetDcmState();
}

#define DCM_STOP_SEC_CODE
#include "MemMap.h"


#define DCM_START_SEC_CODE
#include "MemMap.h"

#if(DCM_COMM_SUPPORT == STD_ON)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dcm_ComM_NoComModeEntered
*
* Description: This call informs the Dcm module about a ComM mode change to
*              COMM_NO_COMMUNICATION.
*
* Inputs: NetworkId: Identifier of the network concerned by the mode change
*
* Outputs: None
*
* Return: None
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
/*SWS_Dcm_00356*/
FUNC(void, DCM_CODE) Dcm_ComM_NoComModeEntered
(
    uint8 NetworkId
)
{
    if(STD_INITIALIZED == Dcm_InitState)
    {
        DCM_COMM_CHANNEL_MODE(NetworkId) = DCM_COMM_NOCOM;
    }
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dcm_ComM_SilentComModeEntered
*
* Description: This call informs the Dcm module about a ComM mode change to
*              COMM_SILENT_COMMUNICATION.
*
* Inputs: NetworkId: Identifier of the network concerned by the mode change
*
* Outputs: None
*
* Return: None
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
/*SWS_Dcm_00358*/
FUNC(void, DCM_CODE) Dcm_ComM_SilentComModeEntered
(
    uint8 NetworkId
)
{
    if(STD_INITIALIZED == Dcm_InitState)
    {
        DCM_COMM_CHANNEL_MODE(NetworkId) = DCM_COMM_SILENTCOM;
    }
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dcm_ComM_FullComModeEntered
*
* Description: This call informs the Dcm module about a ComM mode change to
*              COMM_FULL_COMMUNICATION.
*
* Inputs: NetworkId: Identifier of the network concerned by the mode change
*
* Outputs: None
*
* Return: None
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
/*SWS_Dcm_00360*/
FUNC(void, DCM_CODE) Dcm_ComM_FullComModeEntered
(
    uint8 NetworkId
)
{
    if(STD_INITIALIZED == Dcm_InitState)
    {
        DCM_COMM_CHANNEL_MODE(NetworkId) = DCM_COMM_FULLCOM;
    }
}
#endif/*(DCM_COMM_SUPPORT == STD_ON)*/



#if((DCM_UDS_2C_SERVICE == STD_ON)&&(DCM_DDDID_STORAGE == STD_OFF))
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dcm_NvM_InitStorageMem
*
* Description:
*
* Inputs:
*
* Outputs:
*
* Return:
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, Dcm_CODE) Dcm_NvM_InitStorageMem
(
    void
)
{
    uint16 i;

    for(i = 0U; i < DCM_CFG_ALL_DDDID_ELEMENT_NUM; i++)
    {
        DCM_DDDID_ELEMENT(i).DcmDspDDDIDSourceDidIndex = DCM_INVALID_DID;
        DCM_DDDID_ELEMENT(i).DcmDspDDDIDDataPositionInSourceDid = DCM_DATA_CLEAR;
        DCM_DDDID_ELEMENT(i).DcmDspDataIndex = DCM_DATA_CLEAR;
        DCM_DDDID_ELEMENT(i).DcmDspDDDIDMemoryId = DCM_INVALID_MEMORY_ID;
        DCM_DDDID_ELEMENT(i).DcmDspDDDIDDataMemoryAddress = DCM_DATA_CLEAR;
        DCM_DDDID_ELEMENT(i).DcmDspDDDIDDataSize = DCM_DATA_CLEAR;
    }
    return E_OK;
}

#if(STD_ON == DCM_NVM_SUPPORT)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dcm_NvM_JobResultInd
*
* Description:
*
* Inputs:
*
* Outputs:
*
* Return:
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, Dcm_CODE) Dcm_NvM_JobResultInd
(
    uint8 ServiceId,
    NvM_RequestResultType JobResult
)
{
    Std_ReturnType Result = E_NOT_OK;

    if(JobResult == NVM_REQ_NOT_OK)
    {
        Result = Dcm_NvM_InitStorageMem();
    }
    return Result;
}
#endif
#endif

#define DCM_STOP_SEC_CODE
#include "MemMap.h"



