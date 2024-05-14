/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
*   File Name       : PduR.c
********************************************************************************
*   Project/Product : AUTOSAR 4.2
*   Title           : PduR.c
*   Author          : Hirain
********************************************************************************
*   Description     : Implementation of PDUR
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
*   01.00.00    05/08/2016    Rui.Guo       N/A          Beta
*   01.01.00    26/06/2018    Boxue.Li      N/A          Original
*   01.01.01    29/08/2018    Boxue.Li      N/A          EAS422_PduR_20180829_01
*   01.01.02    14/09/2018    Boxue.Li      N/A          EAS422_PduR_20180914_01
*   01.01.03    09/11/2018    Boxue.Li      N/A          EAS422_PduR_20181109_01
*   01.01.04    21/01/2019    Boxue.Li      N/A          EAS422_PduR_20190121_01
*   01.01.05    12/06/2019    Boxue.Li      N/A          EAS422_PduR_20190612_01
*   01.01.06    21/10/2019    Boxue.Li      N/A          EAS422_PduR_20191021_01
*   01.01.07    22/10/2019    Boxue.Li      N/A          EAS422_PduR_20191022_01
*   01.01.08    12/02/2020    Boxue.Li      N/A          EAS422_PduR_20200212_01
*   01.01.09    26/05/2020    Boxue.Li      N/A          EAS422_PduR_20200526_01
*   01.01.10    01/07/2020    Boxue.Li      N/A          EAS422_PduR_20200701_01
*   01.01.11    04/08/2020    Boxue.Li      N/A          EAS422_PduR_20200804_01
*   01.01.12    19/08/2020    Boxue.Li      N/A          EAS422_PduR_20200819_01
*   01.01.13    24/09/2020    Feixiang.Dong N/A          EAS422_PduR_20200924_01
*   01.01.14    24/12/2020    Xin.Yang1     N/A          EAS422_PduR_20201224_01
*   01.01.15    11/06/2021    Boxue.Li      N/A          EAS422_PduR_20210611_01
*   01.01.16    01/06/2022    Ziyi.Zhao     N/A          EAS422_PduR_20220601_01
*   01.01.17    16/03/2023    Feixiang.Dong N/A          EAS422_PduR_20230316_01
*   01.01.18    26/07/2023    Feixiang.Dong N/A          EAS422_PduR_20230726_01
*   01.01.19    08/08/2023    Feixiang.Dong N/A          EAS422_PduR_20230808_01
********************************************************************************
* END_FILE_HDR*/

/*******************************************************************************
*   Includes
*******************************************************************************/
#include "PduR.h"
#include "SchM_PduR.h"
#include "Bsw_Common.h"

#if(STD_OFF == PDUR_ZERO_COST_OPERATION)

#if(STD_ON == PDUR_DEV_ERROR_DETECT)
#include "Det.h"
#endif
#if(STD_ON == PDUR_COM_MODULE_SUPPORT)
#include "PduR_Com.h"
#include "Com_Cbk.h"
#endif
#if(STD_ON == PDUR_LDCOM_MODULE_SUPPORT)
#include "PduR_LdCom.h"
#include "LdCom_Cbk.h"
#endif
#if(STD_ON == PDUR_DCM_MODULE_SUPPORT)
#include "PduR_Dcm.h"
#include "Dcm_Cbk.h"
#endif
#if(STD_ON == PDUR_DOIPGW_MODULE_SUPPORT)
#include "DoIPGW_Cbk.h"
#endif
#if(STD_ON == PDUR_J1939DCM_MODULE_SUPPORT)
#include "PduR_J1939Dcm.h"
#include "J1939Dcm_Cbk.h"
#endif
#if(STD_ON == PDUR_J1939RM_MODULE_SUPPORT)
#include "PduR_J1939Rm.h"
#include "J1939Rm_Cbk.h"
#endif
#if(STD_ON == PDUR_CANIF_MODULE_SUPPORT)
#include "PduR_CanIf.h"
#include "CanIf.h"
#endif
#if(STD_ON == PDUR_CANTP_MODULE_SUPPORT)
#include "PduR_CanTp.h"
#include "CanTp.h"
#endif
#if(STD_ON == PDUR_CANNM_MODULE_SUPPORT)
#include "PduR_CanNm.h"
#include "CanNm.h"
#endif
#if(STD_ON == PDUR_UDPNM_MODULE_SUPPORT)
#include "PduR_UdpNm.h"
#include "UdpNm.h"
#endif
#if(STD_ON == PDUR_LINIF_MODULE_SUPPORT)
#include "PduR_LinIf.h"
#include "LinIf.h"
#endif
#if(STD_ON == PDUR_LINTP_MODULE_SUPPORT)
#include "PduR_LinTp.h"
#include "LinTp.h"
#endif
#if(STD_ON == PDUR_FRIF_MODULE_SUPPORT)
#include "PduR_FrIf.h"
#include "FrIf.h"
#endif
#if(STD_ON == PDUR_FRTP_MODULE_SUPPORT)
#include "PduR_FrTp.h"
#include "FrTp.h"
#endif
#if(STD_ON == PDUR_DOIPTP_MODULE_SUPPORT)
#include "PduR_DoIP.h"
#include "DoIP.h"
#endif
#if(STD_ON == PDUR_SOADIF_MODULE_SUPPORT)
#include "PduR_SoAd.h"
#include "SoAd.h"
#endif
#if(STD_ON == PDUR_J1939TP_MODULE_SUPPORT)
#include "PduR_J1939Tp.h"
#include "J1939Tp.h"
#endif

#if(STD_ON == PDUR_CDD_MODULE_SUPPORT)
#include "PduR_Cdd.h"
#include "Cdd_Cbk.h"
#endif

#if(STD_ON == PDUR_CDDIF_MODULE_SUPPORT)
#include "PduR_CddIf.h"
#include "CddIf.h"
#endif

#if(STD_ON == PDUR_CDDTP_MODULE_SUPPORT)
#include "PduR_CddTp.h"
#include "CddTp.h"
#endif

#if(STD_ON == PDUR_IPDUM_MODULE_SUPPORT)
#include "PduR_IpduM.h"
#include "IpduM.h"
#endif

#if(STD_ON == PDUR_SOMEIPTP_MODULE_SUPPORT)
#include "PduR_SomeIpTp.h"
#include "SomeIpTp.h"
#endif

#if(STD_ON == PDUR_SECOC_MODULE_SUPPORT)
#include "PduR_SecOC.h"
#include "SecOC.h"
#endif
/*******************************************************************************
*   Version Check
*******************************************************************************/
/*ComM0136 */
#if(STD_ON == PDUR_VERSION_CHECK)
/* check Version with other import module */

/* check Version with cfg file */
#if ((PDUR_CONFIG_VARIANTS != STD_CONFIG_VARIANTS_PRECOMPILE) && \
    (PDUR_CONFIG_VARIANTS != STD_CONFIG_VARIANTS_POSTBUILD))
#error "The PduR module only supports Pre-Compile and Post-Build Configuration."
#endif

#if ((PDUR_AR_RELEASE_MAJOR_VERSION != PDUR_AR_RELEASE_MAJOR_VERSION_CFG) || \
   (PDUR_AR_RELEASE_MINOR_VERSION != PDUR_AR_RELEASE_MINOR_VERSION_CFG))
#error "AutoSar Version Numbers of PduR and its cfg file are incompatible"
#endif

#if ((PDUR_SW_MAJOR_VERSION != PDUR_SW_MAJOR_VERSION_CFG) || \
   (PDUR_SW_MINOR_VERSION != PDUR_SW_MINOR_VERSION_CFG))
#error "SW Version Numbers of PduR and its cfg file are incompatible"
#endif


#endif/*#if(STD_ON == PDUR_VERSION_CHECK)*/


/*Cfg compatibility check*/


/*******************************************************************************
*   Macro
*******************************************************************************/
#if(STD_ON == PDUR_DEV_ERROR_DETECT)

#define  PDUR_DET_REPORT_ERROR(ApiId, errcode)  \
    DET_REPORT_ERROR(PDUR_MODULE_ID, PDUR_INSTANCE_ID, ((uint8)ApiId), ((uint8)errcode))

#else

#define  PDUR_DET_REPORT_ERROR(ApiId, errcode)

#endif

#if(PDUR_MAX_NUMOFBUFFER > 0)
/*PDUR Dest dedicated Buffer State */
#define PDUR_BUFFER_IDLE                   ((uint8)0x00)
#define PDUR_BUFFER_TRANSMITING            ((uint8)0x01)
#define PDUR_BUFFER_RECEIVING              ((uint8)0x02)
#define PDUR_BUFFER_GW_FLYING              ((uint8)0x04)
#endif

#if(PDUR_CONFIG_VARIANTS == STD_CONFIG_VARIANTS_PRECOMPILE)
#define PDUR_GET_NUM_ROUTPATH()                     ((PduR_RoutingPathIdType)PDUR_NUMPDURROUTPATH)
#define PDUR_GET_NUM_ROUTPATHGROUP()                ((PduR_RoutingPathGroupIdType)PDUR_NUMOFROUTINGPATHGROUP)
#if(PDUR_MAX_NUMOFBUFFER > 0)
#define PDUR_GET_NUM_BUFFER()                       ((uint16)PDUR_NUMOFBUFFER)
#endif
#define PDUR_GET_NUM_CANTPRXPDU()                   ((PduIdType)PDUR_NUMOFCANTPRXPDU)
#define PDUR_GET_NUM_LINTPRXPDU()                   ((PduIdType)PDUR_NUMOFLINTPRXPDU)
#define PDUR_GET_NUM_FRTPRXPDU()                    ((PduIdType)PDUR_NUMOFFRTPRXPDU)
#define PDUR_GET_NUM_CDDTPRXPDU()                   ((PduIdType)PDUR_NUMOFCDDTPRXPDU)
#define PDUR_GET_NUM_SOADTPRXPDU()                  ((PduIdType)PDUR_NUMOFSOADTPRXPDU)
#define PDUR_GET_NUM_DOIPTPRXPDU()                  ((PduIdType)PDUR_NUMOFDOIPTPRXPDU)
#define PDUR_GET_NUM_J1939TPRXPDU()                 ((PduIdType)PDUR_NUMOFJ1939TPRXPDU)
#define PDUR_GET_NUM_CANTPTXPDU()                   ((PduIdType)PDUR_NUMOFCANTPTXPDU)
#define PDUR_GET_NUM_LINTPTXPDU()                   ((PduIdType)PDUR_NUMOFLINTPTXPDU)
#define PDUR_GET_NUM_FRTPTXPDU()                    ((PduIdType)PDUR_NUMOFFRTPTXPDU)
#define PDUR_GET_NUM_SOADTPTXPDU()                  ((PduIdType)PDUR_NUMOFSOADTPTXPDU)
#define PDUR_GET_NUM_CDDTPTXPDU()                   ((PduIdType)PDUR_NUMOFCDDTPTXPDU)
#define PDUR_GET_NUM_DOIPTPTXPDU()                  ((PduIdType)PDUR_NUMOFDOIPTPTXPDU)
#define PDUR_GET_NUM_J1939TPTXPDU()                 ((PduIdType)PDUR_NUMOFJ1939TPTXPDU)
#define PDUR_GET_NUM_CANIFTXPDU()                   ((PduIdType)PDUR_NUMOFCANIFTXPDU)
#define PDUR_GET_NUM_CANIFRXPDU()                   ((PduIdType)PDUR_NUMOFCANIFRXPDU)
#define PDUR_GET_NUM_CANNMTXPDU()                   ((PduIdType)PDUR_NUMOFCANNMTXPDU)
#define PDUR_GET_NUM_CANNMRXPDU()                   ((PduIdType)PDUR_NUMOFCANNMRXPDU)
#define PDUR_GET_NUM_UDPNMTXPDU()                   ((PduIdType)PDUR_NUMOFUDPNMTXPDU)
#define PDUR_GET_NUM_UDPNMRXPDU()                   ((PduIdType)PDUR_NUMOFUDPNMRXPDU)
#define PDUR_GET_NUM_LINIFRXPDU()                   ((PduIdType)PDUR_NUMOFLINIFRXPDU)
#define PDUR_GET_NUM_LINIFTXPDU()                   ((PduIdType)PDUR_NUMOFLINIFTXPDU)
#define PDUR_GET_NUM_FRIFRXPDU()                    ((PduIdType)PDUR_NUMOFFRIFRXPDU)
#define PDUR_GET_NUM_FRIFTXPDU()                    ((PduIdType)PDUR_NUMOFFRIFTXPDU)
#define PDUR_GET_NUM_SOADIFRXPDU()                  ((PduIdType)PDUR_NUMOFSOADIFRXPDU)
#define PDUR_GET_NUM_SOADIFTXPDU()                  ((PduIdType)PDUR_NUMOFSOADIFTXPDU)
#define PDUR_GET_NUM_DOIPIFTXPDU()                  ((PduIdType)PDUR_NUMOFDOIPIFTXPDU)
#define PDUR_GET_NUM_CDDIFRXPDU()                   ((PduIdType)PDUR_NUMOFCDDIFRXPDU)
#define PDUR_GET_NUM_CDDIFTXPDU()                   ((PduIdType)PDUR_NUMOFCDDIFTXPDU)
#define PDUR_GET_NUM_DOIPIFRXPDU()                  ((PduIdType)PDUR_NUMOFDOIPIFRXPDU)
#define PDUR_GET_NUM_DCMRXPDU()                     ((PduIdType)PDUR_NUMOFDCMRXPDU)
#define PDUR_GET_NUM_DCMTXPDU()                     ((PduIdType)PDUR_NUMOFDCMTXPDU)
#define PDUR_GET_NUM_COMTXPDU()                     ((PduIdType)PDUR_NUMOFCOMTXPDU)
#define PDUR_GET_NUM_LDCOMTXPDU()                   ((PduIdType)PDUR_NUMOFLDCOMTXPDU)
#define PDUR_GET_NUM_J1939RMTXPDU()                 ((PduIdType)PDUR_NUMOFJ1939RMTXPDU)
#define PDUR_GET_NUM_J1939DCMRXPDU()                ((PduIdType)PDUR_NUMOFJ1939DCMRXPDU)
#define PDUR_GET_NUM_J1939DCMTXPDU()                ((PduIdType)PDUR_NUMOFJ1939DCMTXPDU)
#define PDUR_GET_NUM_CDDTXPDU()                     ((PduIdType)PDUR_NUMOFCDDTXPDU)
#define PDUR_GET_NUM_CDDRXPDU()                     ((PduIdType)PDUR_NUMOFCDDRXPDU)
#define PDUR_GET_NUM_IPDUMTXPDU()                   ((PduIdType)PDUR_NUMOFIPDUMTXPDU)
#define PDUR_GET_NUM_IPDUMIFRXPDU()                 ((PduIdType)PDUR_NUMOFIPDUMIFRXPDU)
#define PDUR_GET_NUM_IPDUMIFTXPDU()                 ((PduIdType)PDUR_NUMOFIPDUMIFTXPDU)
#define PDUR_GET_NUM_SOMEIPTXPDU()                  ((PduIdType)PDUR_NUMOFSOMEIPTXPDU)
#define PDUR_GET_NUM_SOMEIPTPRXPDU()                ((PduIdType)PDUR_NUMOFSOMEIPTPRXPDU)
#define PDUR_GET_NUM_SOMEIPTPTXPDU()                ((PduIdType)PDUR_NUMOFSOMEIPTPTXPDU)
#define PDUR_GET_NUM_SECOCTXPDU()                   ((PduIdType)PDUR_NUMOFSECOCTXPDU)
#define PDUR_GET_NUM_SECOCRXPDU()                   ((PduIdType)PDUR_NUMOFSECOCRXPDU)
#define PDUR_GET_NUM_SECOCIFTXPDU()                 ((PduIdType)PDUR_NUMOFSECOCIFTXPDU)
#define PDUR_GET_NUM_SECOCIFRXPDU()                 ((PduIdType)PDUR_NUMOFSECOCIFRXPDU)
#define PDUR_GET_NUM_SECOCTPTXPDU()                 ((PduIdType)PDUR_NUMOFSECOCTPTXPDU)
#define PDUR_GET_NUM_SECOCTPRXPDU()                 ((PduIdType)PDUR_NUMOFSECOCTPRXPDU)
#define PDUR_ROUTINGPATHINFO(PathId)                (PduRRoutingTable[PathId])
#define PDUR_GET_RPGROUP_ENABLED_ATINIT(GroupId)    (PduR_RPGroupEnabledAtInit[GroupId])
#define PDUR_COM_TXPDUINFO(PduId)                   (PduRComTxPduInfo[PduId])
#define PDUR_LDCOM_TXPDUINFO(PduId)                 (PduRLdComTxPduInfo[PduId])
#define PDUR_DCM_TXPDUINFO(PduId)                   (PduRDcmTxPduInfo[PduId])
#define PDUR_J1939DCM_TXPDUINFO(PduId)              (PduRJ1939DcmTxPduInfo[PduId])
#define PDUR_J1939RM_TXPDUINFO(PduId)               (PduRJ1939RmTxPduInfo[PduId])
#define PDUR_CDD_TXPDUINFO(PduId)                   (PduRCddTxPduInfo[PduId])
#define PDUR_CANTP_RXPDUINFO(PduId)                 (PduRCanTpRxPduInfo[PduId])
#define PDUR_LINTP_RXPDUINFO(PduId)                 (PduRLinTpRxPduInfo[PduId])
#define PDUR_FRTP_RXPDUINFO(PduId)                  (PduRFrTpRxPduInfo[PduId])
#define PDUR_SOADTP_RXPDUINFO(PduId)                (PduRSoAdTpRxPduInfo[PduId])
#define PDUR_DOIPTP_RXPDUINFO(PduId)                (PduRDoIPTpRxPduInfo[PduId])
#define PDUR_J1939TP_RXPDUINFO(PduId)               (PduRJ1939TpRxPduInfo[PduId])
#define PDUR_CDDTP_RXPDUINFO(PduId)                 (PduRCddTpRxPduInfo[PduId])
#define PDUR_DCM_CANCELRXPDUINFO(PduId)             (PduRDcmCancelRxPduInfo[PduId])
#define PDUR_J1939DCM_CANCELRXPDUINFO(PduId)        (PduRJ1939DcmCancelRxPduInfo[PduId])
#define PDUR_CDD_CANCELRXPDUINFO(PduId)             (PduRCddCancelRxPduInfo[PduId])
#define PDUR_CANIF_RXPDUINFO(PduId)                 (PduRCanIfRxPduInfo[PduId])
#define PDUR_CANIF_TXCONFPDUINFO(PduId)             (PduRCanIfTxConfPduInfo[PduId])
#define PDUR_IPDUMIF_RXPDUINFO(PduId)               (PduRIpduMIfRxPduInfo[PduId])
#define PDUR_IPDUM_TXPDUINFO(PduId)                 (PduRIpduMTxPduInfo[PduId])
#define PDUR_IPDUMIF_TXCONFPDUINFO(PduId)           (PduRIpduMIfTxConfPduInfo[PduId])
#define PDUR_SOMEIP_TXPDUINFO(PduId)                (PduRSomeIpTxPduInfo[PduId])
#define PDUR_SOMEIPTP_RXPDUINFO(PduId)              (PduRSomeIpTpRxPduInfo[PduId])
#define PDUR_SOMEIPTP_TXCONFPDUINFO(PduId)          (PduRSomeIpTpTxConfPduInfo[PduId])
#if(PDUR_MAX_NUMOFSECOCTXPDU > 0)
#define PDUR_SECOC_TXPDUINFO(PduId)                 (PduRSecOCTxPduInfo[PduId])
#endif
#define PDUR_SECOC_CANCELRXPDUINFO(PduId)           (PduRSecOCCancelRxPduInfo[PduId])
#define PDUR_SECOCIF_TXCONFPDUINFO(PduId)           (PduRSecOCIfTxConfPduInfo[PduId])
#define PDUR_SECOCIF_RXPDUINFO(PduId)               (PduRSecOCIfRxPduInfo[PduId])
#define PDUR_SECOCTP_TXCONFPDUINFO(PduId)           (PduRSecOCTpTxConfPduInfo[PduId])
#define PDUR_SECOCTP_RXPDUINFO(PduId)               (PduRSecOCTpRxPduInfo[PduId])
#define PDUR_CANNM_RXPDUINFO(PduId)                 (PduRCanNmRxPduInfo[PduId])
#define PDUR_CANNM_TXCONFPDUINFO(PduId)             (PduRCanNmTxConfPduInfo[PduId])
#define PDUR_UDPNM_RXPDUINFO(PduId)                 (PduRUdpNmRxPduInfo[PduId])
#define PDUR_UDPNM_TXCONFPDUINFO(PduId)             (PduRUdpNmTxConfPduInfo[PduId])
#define PDUR_LINIF_RXPDUINFO(PduId)                 (PduRLinIfRxPduInfo[PduId])
#define PDUR_LINIF_TXCONFPDUINFO(PduId)             (PduRLinIfTxConfPduInfo[PduId])
#define PDUR_FRIF_RXPDUINFO(PduId)                  (PduRFrIfRxPduInfo[PduId])
#define PDUR_FRIF_TXCONFPDUINFO(PduId)              (PduRFrIfTxConfPduInfo[PduId])
#define PDUR_SOADIF_RXPDUINFO(PduId)                (PduRSoAdIfRxPduInfo[PduId])
#define PDUR_SOADIF_TXCONFPDUINFO(PduId)            (PduRSoAdIfTxConfPduInfo[PduId])
#define PDUR_DOIPIF_TXCONFPDUINFO(PduId)            (PduRDoIPIfTxConfPduInfo[PduId])
#define PDUR_CDDIF_RXPDUINFO(PduId)                 (PduRCddIfRxPduInfo[PduId])
#define PDUR_CDDIF_TXCONFPDUINFO(PduId)             (PduRCddIfTxConfPduInfo[PduId])
#define PDUR_CANTP_TXCONFPDUINFO(PduId)             (PduRCanTpTxConfPduInfo[PduId])
#define PDUR_LINTP_TXCONFPDUINFO(PduId)             (PduRLinTpTxConfPduInfo[PduId])
#define PDUR_FRTP_TXCONFPDUINFO(PduId)              (PduRFrTpTxConfPduInfo[PduId])
#define PDUR_SOADTP_TXCONFPDUINFO(PduId)            (PduRSoAdTpTxConfPduInfo[PduId])
#define PDUR_CDDTP_TXCONFPDUINFO(PduId)             (PduRCddTpTxConfPduInfo[PduId])
#define PDUR_DOIPTP_TXCONFPDUINFO(PduId)            (PduRDoIPTpTxConfPduInfo[PduId])
#define PDUR_J1939TP_TXCONFPDUINFO(PduId)           (PduRJ1939TpTxConfPduInfo[PduId])
#else
#define PDUR_GET_NUM_ROUTPATH()                     (PduR_ConfigSet->RoutingPathNum)
#define PDUR_GET_NUM_ROUTPATHGROUP()                (PduR_ConfigSet->RoutingPathGroupNum)
#if(PDUR_MAX_NUMOFBUFFER > 0)
#define PDUR_GET_NUM_BUFFER()                       (PduR_ConfigSet->BufferNum)
#endif
#define PDUR_GET_NUM_CANTPRXPDU()                   (PduR_ConfigSet->CanTpRxPathNum)
#define PDUR_GET_NUM_LINTPRXPDU()                   (PduR_ConfigSet->LinTpRxPathNum)
#define PDUR_GET_NUM_FRTPRXPDU()                    (PduR_ConfigSet->FrTpRxPathNum)
#define PDUR_GET_NUM_CDDTPRXPDU()                   (PduR_ConfigSet->CddTpRxPathNum)
#define PDUR_GET_NUM_SOADTPRXPDU()                  (PduR_ConfigSet->SoAdTpRxPathNum)
#define PDUR_GET_NUM_DOIPTPRXPDU()                  (PduR_ConfigSet->DoIPTpRxPathNum)
#define PDUR_GET_NUM_J1939TPRXPDU()                 (PduR_ConfigSet->J1939TpRxPathNum)
#define PDUR_GET_NUM_CANTPTXPDU()                   (PduR_ConfigSet->CanTpTxConfPathNum)
#define PDUR_GET_NUM_LINTPTXPDU()                   (PduR_ConfigSet->LinTpTxConfPathNum)
#define PDUR_GET_NUM_FRTPTXPDU()                    (PduR_ConfigSet->FrTpTxConfPathNum)
#define PDUR_GET_NUM_SOADTPTXPDU()                  (PduR_ConfigSet->SoAdTpTxConfPathNum)
#define PDUR_GET_NUM_CDDTPTXPDU()                   (PduR_ConfigSet->CddTpTxConfPathNum)
#define PDUR_GET_NUM_DOIPTPTXPDU()                  (PduR_ConfigSet->DoIPTpTxConfPathNum)
#define PDUR_GET_NUM_J1939TPTXPDU()                 (PduR_ConfigSet->J1939TpTxConfPathNum)
#define PDUR_GET_NUM_CANIFTXPDU()                   (PduR_ConfigSet->CanIfTxConfPathNum)
#define PDUR_GET_NUM_CANIFRXPDU()                   (PduR_ConfigSet->CanIfRxPathNum)
#define PDUR_GET_NUM_CANNMTXPDU()                   (PduR_ConfigSet->CanNmTxConfPathNum)
#define PDUR_GET_NUM_CANNMRXPDU()                   (PduR_ConfigSet->CanNmRxPathNum)
#define PDUR_GET_NUM_UDPNMTXPDU()                   (PduR_ConfigSet->UdpNmTxConfPathNum)
#define PDUR_GET_NUM_UDPNMRXPDU()                   (PduR_ConfigSet->UdpNmRxPathNum)
#define PDUR_GET_NUM_LINIFRXPDU()                   (PduR_ConfigSet->LinIfRxPathNum)
#define PDUR_GET_NUM_LINIFTXPDU()                   (PduR_ConfigSet->LinIfTxConfPathNum)
#define PDUR_GET_NUM_FRIFRXPDU()                    (PduR_ConfigSet->FrIfRxPathNum)
#define PDUR_GET_NUM_FRIFTXPDU()                    (PduR_ConfigSet->FrIfTxConfPathNum)
#define PDUR_GET_NUM_SOADIFRXPDU()                  (PduR_ConfigSet->SoAdIfRxPathNum)
#define PDUR_GET_NUM_SOADIFTXPDU()                  (PduR_ConfigSet->SoAdIfTxConfPathNum)
#define PDUR_GET_NUM_DOIPIFTXPDU()                  (PduR_ConfigSet->DoIPIfTxConfPathNum)
#define PDUR_GET_NUM_CDDIFRXPDU()                   (PduR_ConfigSet->CddIfRxPathNum)
#define PDUR_GET_NUM_CDDIFTXPDU()                   (PduR_ConfigSet->CddIfTxConfPathNum)
#define PDUR_GET_NUM_DOIPIFRXPDU()                  (PduR_ConfigSet->DoIPIfRxPathNum)
#define PDUR_GET_NUM_DCMRXPDU()                     (PduR_ConfigSet->DcmRxPathNum)
#define PDUR_GET_NUM_DCMTXPDU()                     (PduR_ConfigSet->DcmTxPathNum)
#define PDUR_GET_NUM_COMTXPDU()                     (PduR_ConfigSet->ComTxPathNum)
#define PDUR_GET_NUM_LDCOMTXPDU()                   (PduR_ConfigSet->LdComTxPathNum)
#define PDUR_GET_NUM_J1939RMTXPDU()                 (PduR_ConfigSet->J1939RmTxPathNum)
#define PDUR_GET_NUM_J1939DCMRXPDU()                (PduR_ConfigSet->J1939DcmRxPathNum)
#define PDUR_GET_NUM_J1939DCMTXPDU()                (PduR_ConfigSet->J1939DcmTxPathNum)
#define PDUR_GET_NUM_CDDTXPDU()                     (PduR_ConfigSet->CddTxPathNum)
#define PDUR_GET_NUM_CDDRXPDU()                     (PduR_ConfigSet->CddRxPathNum)
#define PDUR_GET_NUM_IPDUMTXPDU()                   (PduR_ConfigSet->IpduMTxPathNum)
#define PDUR_GET_NUM_IPDUMIFRXPDU()                 (PduR_ConfigSet->IpduMIfRxPathNum)
#define PDUR_GET_NUM_IPDUMIFTXPDU()                 (PduR_ConfigSet->IpduMIfTxConfPathNum)
#define PDUR_GET_NUM_SOMEIPTXPDU()                  (PduR_ConfigSet->SomeIpTxPathNum)
#define PDUR_GET_NUM_SOMEIPTPRXPDU()                (PduR_ConfigSet->SomeIpTpRxPathNum)
#define PDUR_GET_NUM_SOMEIPTPTXPDU()                (PduR_ConfigSet->SomeIpTpTxConfPathNum)
#define PDUR_GET_NUM_SECOCTXPDU()                   (PduR_ConfigSet->SecOCTxConfPathNum)
#define PDUR_GET_NUM_SECOCRXPDU()                   (PduR_ConfigSet->SecOCRxPathNum)
#define PDUR_GET_NUM_SECOCIFTXPDU()                 (PduR_ConfigSet->SecOCIfTxConfPathNum)
#define PDUR_GET_NUM_SECOCIFRXPDU()                 (PduR_ConfigSet->SecOCIfRxPathNum)
#define PDUR_GET_NUM_SECOCTPTXPDU()                 (PduR_ConfigSet->SecOCTpTxConfPathNum)
#define PDUR_ROUTINGPATHINFO(PathId)                (PduR_ConfigSet->pRoutingTbl[PathId])
#define PDUR_GET_RPGROUP_ENABLED_ATINIT(GroupId)    (PduR_ConfigSet->RPGroupEnabledAtInit[GroupId])
#define PDUR_COM_TXPDUINFO(PduId)                   (PduR_ConfigSet->pComTxPduInfo[PduId])
#define PDUR_LDCOM_TXPDUINFO(PduId)                 (PduR_ConfigSet->pLdComTxPduInfo[PduId])
#define PDUR_DCM_TXPDUINFO(PduId)                   (PduR_ConfigSet->pDcmTxPduInfo[PduId])
#define PDUR_J1939DCM_TXPDUINFO(PduId)              (PduR_ConfigSet->pJ1939DcmTxPduInfo[PduId])
#define PDUR_J1939RM_TXPDUINFO(PduId)               (PduR_ConfigSet->pJ1939RmTxPduInfo[PduId])
#define PDUR_CDD_TXPDUINFO(PduId)                   (PduR_ConfigSet->pCddTxPduInfo[PduId])
#define PDUR_CANTP_RXPDUINFO(PduId)                 (PduR_ConfigSet->pCanTpRxPduInfo[PduId])
#define PDUR_LINTP_RXPDUINFO(PduId)                 (PduR_ConfigSet->pLinTpRxPduInfo[PduId])
#define PDUR_FRTP_RXPDUINFO(PduId)                  (PduR_ConfigSet->pFrTpRxPduInfo[PduId])
#define PDUR_SOADTP_RXPDUINFO(PduId)                (PduR_ConfigSet->pSoAdTpRxPduInfo[PduId])
#define PDUR_DOIPTP_RXPDUINFO(PduId)                (PduR_ConfigSet->pDoIPTpRxPduInfo[PduId])
#define PDUR_J1939TP_RXPDUINFO(PduId)               (PduR_ConfigSet->pJ1939TpRxPduInfo[PduId])
#define PDUR_CDDTP_RXPDUINFO(PduId)                 (PduR_ConfigSet->pCddTpRxPduInfo[PduId])
#define PDUR_DCM_CANCELRXPDUINFO(PduId)             (PduR_ConfigSet->pDcmCancelRxPduInfo[PduId])
#define PDUR_J1939DCM_CANCELRXPDUINFO(PduId)        (PduR_ConfigSet->pJ1939DcmCancelRxPduInfo[PduId])
#define PDUR_CDD_CANCELRXPDUINFO(PduId)             (PduR_ConfigSet->pCddCancelRxPduInfo[PduId])
#define PDUR_SECOC_CANCELRXPDUINFO(PduId)           (PduR_ConfigSet->pSecOCCancelRxPduInfo[PduId])
#define PDUR_CANIF_RXPDUINFO(PduId)                 (PduR_ConfigSet->pCanIfRxPduInfo[PduId])
#define PDUR_CANIF_TXCONFPDUINFO(PduId)             (PduR_ConfigSet->pCanIfTxConfPduInfo[PduId])
#define PDUR_IPDUMIF_RXPDUINFO(PduId)               (PduR_ConfigSet->pIpduMIfRxPduInfo[PduId])
#define PDUR_IPDUM_TXPDUINFO(PduId)                 (PduR_ConfigSet->pIpduMTxConfPduInfo[PduId])
#define PDUR_IPDUMIF_TXCONFPDUINFO(PduId)           (PduR_ConfigSet->pIpduMIfTxConfPduInfo[PduId])
#define PDUR_SOMEIP_TXPDUINFO(PduId)                (PduR_ConfigSet->pSomeIpTxConfPduInfo[PduId])
#define PDUR_SOMEIPTP_RXPDUINFO(PduId)              (PduR_ConfigSet->pSomeIpTpRxPduInfo[PduId])
#define PDUR_SOMEIPTP_TXCONFPDUINFO(PduId)          (PduR_ConfigSet->pSomeIpTpTxConfPduInfo[PduId])
#if(PDUR_MAX_NUMOFSECOCTXPDU > 0)
#define PDUR_SECOC_TXPDUINFO(PduId)                 (PduR_ConfigSet->pSecOCTxConfPduInfo[PduId])
#endif
#define PDUR_SECOC_RXPDUINFO(PduId)                 (PduR_ConfigSet->pSecOCRxPduInfo[PduId])
#define PDUR_SECOCIF_TXCONFPDUINFO(PduId)           (PduR_ConfigSet->pSecOCIfTxConfPduInfo[PduId])
#define PDUR_SECOCIF_RXPDUINFO(PduId)               (PduR_ConfigSet->pSecOCIfRxPduInfo[PduId])
#define PDUR_SECOCTP_TXCONFPDUINFO(PduId)           (PduR_ConfigSet->pSecOCTpTxConfPduInfo[PduId])
#define PDUR_SECOCTP_RXPDUINFO(PduId)               (PduR_ConfigSet->pSecOCTpRxPduInfo[PduId])
#define PDUR_CANNM_RXPDUINFO(PduId)                 (PduR_ConfigSet->pCanNmRxPduInfo[PduId])
#define PDUR_CANNM_TXCONFPDUINFO(PduId)             (PduR_ConfigSet->pCanNmTxConfPduInfo[PduId])
#define PDUR_UDPNM_RXPDUINFO(PduId)                 (PduR_ConfigSet->pUdpNmRxPduInfo[PduId])
#define PDUR_UDPNM_TXCONFPDUINFO(PduId)             (PduR_ConfigSet->pUdpNmTxConfPduInfo[PduId])
#define PDUR_LINIF_RXPDUINFO(PduId)                 (PduR_ConfigSet->pLinIfRxPduInfo[PduId])
#define PDUR_LINIF_TXCONFPDUINFO(PduId)             (PduR_ConfigSet->pLinIfTxConfPduInfo[PduId])
#define PDUR_FRIF_RXPDUINFO(PduId)                  (PduR_ConfigSet->pFrIfRxPduInfo[PduId])
#define PDUR_FRIF_TXCONFPDUINFO(PduId)              (PduR_ConfigSet->pFrIfTxConfPduInfo[PduId])
#define PDUR_SOADIF_RXPDUINFO(PduId)                (PduR_ConfigSet->pSoAdIfRxPduInfo[PduId])
#define PDUR_SOADIF_TXCONFPDUINFO(PduId)            (PduR_ConfigSet->pSoAdIfTxConfPduInfo[PduId])
#define PDUR_DOIPIF_TXCONFPDUINFO(PduId)            (PduR_ConfigSet->pDoIPIfTxConfPduInfo[PduId])
#define PDUR_CDDIF_RXPDUINFO(PduId)                 (PduR_ConfigSet->pCddIfRxPduInfo[PduId])
#define PDUR_CDDIF_TXCONFPDUINFO(PduId)             (PduR_ConfigSet->pCddIfTxConfPduInfo[PduId])
#define PDUR_CANTP_TXCONFPDUINFO(PduId)             (PduR_ConfigSet->pCanTpTxConfPduInfo[PduId])
#define PDUR_LINTP_TXCONFPDUINFO(PduId)             (PduR_ConfigSet->pLinTpTxConfPduInfo[PduId])
#define PDUR_FRTP_TXCONFPDUINFO(PduId)              (PduR_ConfigSet->pFrTpTxConfPduInfo[PduId])
#define PDUR_SOADTP_TXCONFPDUINFO(PduId)            (PduR_ConfigSet->pSoAdTpTxConfPduInfo[PduId])
#define PDUR_CDDTP_TXCONFPDUINFO(PduId)             (PduR_ConfigSet->pCddTpTxConfPduInfo[PduId])
#define PDUR_DOIPTP_TXCONFPDUINFO(PduId)            (PduR_ConfigSet->pDoIPTpTxConfPduInfo[PduId])
#define PDUR_J1939TP_TXCONFPDUINFO(PduId)           (PduR_ConfigSet->pJ1939TpTxConfPduInfo[PduId])
#endif

/*Initialization status*/
#define PDUR_IS_INITIALIZED()                       (PDUR_ONLINE == PduR_InitStatus)
#define PDUR_SET_INITIALIZED()                      (PduR_InitStatus = PDUR_ONLINE)
#define PDUR_SET_UNINITIALIZED()                    (PduR_InitStatus = PDUR_UNINIT)


/*******************************************************************************
*   Local Data Define
*******************************************************************************/
#define PDUR_START_SEC_VAR_INIT_8
#include "MemMap.h"

/*PDUR global state*/
/*SWS_PduR_00325*/
STATIC VAR(PduR_StateType, PDUR_VAR) PduR_InitStatus = PDUR_UNINIT;

#define PDUR_STOP_SEC_VAR_INIT_8
#include "MemMap.h"



#define PDUR_START_SEC_CONST_32
#include "MemMap.h"

/*!!!IMPORTANT!!!
  The order of the members must be the same as in PduRModuleType*/
STATIC CONST(PduR_ModuleFunc, PDUR_CONST) PduR_ModuleFunctions[MODULE_NUM] =
{
#if(STD_ON == PDUR_COM_MODULE_SUPPORT)
    /*Com*/
    {
#if(STD_ON == PDUR_CANCEL_TRANSMIT_ENABLED)
        NULL_PTR,/*IfCancelTransmitFunc;*/
#endif
        NULL_PTR,/*IfTransmitFunc;*/
#if(STD_ON == PDUR_CANCEL_RECEIVE_ENABLED)
        NULL_PTR,/*TpCancelReceiveFunc;*/
#endif
#if(STD_ON == PDUR_CANCEL_TRANSMIT_ENABLED)
        NULL_PTR,/*TpCancelTransmitFunc;*/
#endif
        NULL_PTR,/*TpTransmitFunc;*/
#if(STD_ON == PDUR_CHANGEPARAMETER_API_ENABLED)
        NULL_PTR,/*TpChangeParameterFunc;*/
#endif
        Com_RxIndication,/*UpIfRxIndicationFunc;*/
        Com_TriggerTransmit,/*UpIfTriggerTransmitFunc;*/
        Com_TxConfirmation,/*UpIfTxConfirmationFunc;*/
        Com_CopyRxData,/*UpTpCopyRxDataFunc;*/
        Com_CopyTxData,/*UpTpCopyTxDataFunc;*/
        Com_StartOfReception,/*UpTpStartOfReceptionFunc;*/
        Com_TpRxIndication,/*UpTpRxIndicationFunc;*/
        Com_TpTxConfirmation/*UpTpTxConfirmationFunc;*/
    },
#endif
#if(STD_ON == PDUR_LDCOM_MODULE_SUPPORT)
    /*LdCom*/
    {
#if(STD_ON == PDUR_CANCEL_TRANSMIT_ENABLED)
        NULL_PTR,/*IfCancelTransmitFunc;*/
#endif
        NULL_PTR,/*IfTransmitFunc;*/
#if(STD_ON == PDUR_CANCEL_RECEIVE_ENABLED)
        NULL_PTR,/*TpCancelReceiveFunc;*/
#endif
#if(STD_ON == PDUR_CANCEL_TRANSMIT_ENABLED)
        NULL_PTR,/*TpCancelTransmitFunc;*/
#endif
        NULL_PTR,/*TpTransmitFunc;*/
#if(STD_ON == PDUR_CHANGEPARAMETER_API_ENABLED)
        NULL_PTR,/*TpChangeParameterFunc;*/
#endif
        LdCom_RxIndication,/*UpIfRxIndicationFunc;*/
        LdCom_TriggerTransmit,/*UpIfTriggerTransmitFunc;*/
        LdCom_TxConfirmation,/*UpIfTxConfirmationFunc;*/
        LdCom_CopyRxData,/*UpTpCopyRxDataFunc;*/
        LdCom_CopyTxData,/*UpTpCopyTxDataFunc;*/
        LdCom_StartOfReception,/*UpTpStartOfReceptionFunc;*/
        LdCom_TpRxIndication,/*UpTpRxIndicationFunc;*/
        LdCom_TpTxConfirmation/*UpTpTxConfirmationFunc;*/
    },
#endif
#if(STD_ON == PDUR_DCM_MODULE_SUPPORT)
    /*Dcm*/
    {
#if(STD_ON == PDUR_CANCEL_TRANSMIT_ENABLED)
        NULL_PTR,/*IfCancelTransmitFunc;*/
#endif
        NULL_PTR,/*IfTransmitFunc;*/
#if(STD_ON == PDUR_CANCEL_RECEIVE_ENABLED)
        NULL_PTR,/*TpCancelReceiveFunc;*/
#endif
#if(STD_ON == PDUR_CANCEL_TRANSMIT_ENABLED)
        NULL_PTR,/*TpCancelTransmitFunc;*/
#endif
        NULL_PTR,/*TpTransmitFunc;*/
#if(STD_ON == PDUR_CHANGEPARAMETER_API_ENABLED)
        NULL_PTR,/*TpChangeParameterFunc;*/
#endif
        NULL_PTR,/*UpIfRxIndicationFunc;*/
        NULL_PTR,/*UpIfTriggerTransmitFunc;*/
        Dcm_TxConfirmation,/*UpIfTxConfirmationFunc;*/
        Dcm_CopyRxData,/*UpTpCopyRxDataFunc;*/
        Dcm_CopyTxData,/*UpTpCopyTxDataFunc;*/
        Dcm_StartOfReception,/*UpTpStartOfReceptionFunc;*/
        Dcm_TpRxIndication,/*UpTpRxIndicationFunc;*/
        Dcm_TpTxConfirmation/*UpTpTxConfirmationFunc;*/
    },
#endif
#if(STD_ON == PDUR_DOIPGW_MODULE_SUPPORT)
    /*DoIPGW*/
    {
#if(STD_ON == PDUR_CANCEL_TRANSMIT_ENABLED)
        NULL_PTR,/*IfCancelTransmitFunc;*/
#endif
        NULL_PTR,/*IfTransmitFunc;*/
#if(STD_ON == PDUR_CANCEL_RECEIVE_ENABLED)
        NULL_PTR,/*TpCancelReceiveFunc;*/
#endif
#if(STD_ON == PDUR_CANCEL_TRANSMIT_ENABLED)
        NULL_PTR,/*TpCancelTransmitFunc;*/
#endif
        NULL_PTR,/*TpTransmitFunc;*/
#if(STD_ON == PDUR_CHANGEPARAMETER_API_ENABLED)
        NULL_PTR,/*TpChangeParameterFunc;*/
#endif
        NULL_PTR,/*UpIfRxIndicationFunc;*/
        NULL_PTR,/*UpIfTriggerTransmitFunc;*/
        NULL_PTR,/*UpIfTxConfirmationFunc;*/
        DoIPGW_CopyRxData,/*UpTpCopyRxDataFunc;*/
        NULL_PTR,/*UpTpCopyTxDataFunc;*/
        DoIPGW_StartOfReception,/*UpTpStartOfReceptionFunc;*/
        DoIPGW_TpRxIndication,/*UpTpRxIndicationFunc;*/
        NULL_PTR/*UpTpTxConfirmationFunc;*/
    },
#endif
#if(STD_ON == PDUR_J1939DCM_MODULE_SUPPORT)
    /*J1939Dcm*/
    {
#if(STD_ON == PDUR_CANCEL_TRANSMIT_ENABLED)
        NULL_PTR,/*IfCancelTransmitFunc;*/
#endif
        NULL_PTR,/*IfTransmitFunc;*/
#if(STD_ON == PDUR_CANCEL_RECEIVE_ENABLED)
        NULL_PTR,/*TpCancelReceiveFunc;*/
#endif
#if(STD_ON == PDUR_CANCEL_TRANSMIT_ENABLED)
        NULL_PTR,/*TpCancelTransmitFunc;*/
#endif
        NULL_PTR,/*TpTransmitFunc;*/
#if(STD_ON == PDUR_CHANGEPARAMETER_API_ENABLED)
        NULL_PTR,/*TpChangeParameterFunc;*/
#endif
        NULL_PTR,/*UpIfRxIndicationFunc;*/
        NULL_PTR,/*UpIfTriggerTransmitFunc;*/
        J1939Dcm_TxConfirmation,/*UpIfTxConfirmationFunc;*/
        J1939Dcm_CopyRxData,/*UpTpCopyRxDataFunc;*/
        J1939Dcm_CopyTxData,/*UpTpCopyTxDataFunc;*/
        J1939Dcm_StartOfReception,/*UpTpStartOfReceptionFunc;*/
        J1939Dcm_TpRxIndication,/*UpTpRxIndicationFunc;*/
        J1939Dcm_TpTxConfirmation/*UpTpTxConfirmationFunc;*/
    },
#endif
#if(STD_ON == PDUR_J1939RM_MODULE_SUPPORT)
    /*J1939Rm*/
    {
#if(STD_ON == PDUR_CANCEL_TRANSMIT_ENABLED)
        NULL_PTR,/*IfCancelTransmitFunc;*/
#endif
        NULL_PTR,/*IfTransmitFunc;*/
#if(STD_ON == PDUR_CANCEL_RECEIVE_ENABLED)
        NULL_PTR,/*TpCancelReceiveFunc;*/
#endif
#if(STD_ON == PDUR_CANCEL_TRANSMIT_ENABLED)
        NULL_PTR,/*TpCancelTransmitFunc;*/
#endif
        NULL_PTR,/*TpTransmitFunc;*/
#if(STD_ON == PDUR_CHANGEPARAMETER_API_ENABLED)
        NULL_PTR,/*TpChangeParameterFunc;*/
#endif
        J1939Rm_RxIndication,/*UpIfRxIndicationFunc;*/
        NULL_PTR,/*UpIfTriggerTransmitFunc;*/
        J1939Rm_TxConfirmation,/*UpIfTxConfirmationFunc;*/
        NULL_PTR,/*UpTpCopyRxDataFunc;*/
        NULL_PTR,/*UpTpCopyTxDataFunc;*/
        NULL_PTR,/*UpTpStartOfReceptionFunc;*/
        NULL_PTR,/*UpTpRxIndicationFunc;*/
        NULL_PTR/*UpTpTxConfirmationFunc;*/
    },
#endif
#if(STD_ON == PDUR_CDD_MODULE_SUPPORT)
    /*Cdd*/
    {
#if(STD_ON == PDUR_CANCEL_TRANSMIT_ENABLED)
        NULL_PTR,/*IfCancelTransmitFunc;*/
#endif
        NULL_PTR,/*IfTransmitFunc;*/
#if(STD_ON == PDUR_CANCEL_RECEIVE_ENABLED)
        NULL_PTR,/*TpCancelReceiveFunc;*/
#endif
#if(STD_ON == PDUR_CANCEL_TRANSMIT_ENABLED)
        NULL_PTR,/*TpCancelTransmitFunc;*/
#endif
        NULL_PTR,/*TpTransmitFunc;*/
#if(STD_ON == PDUR_CHANGEPARAMETER_API_ENABLED)
        NULL_PTR,/*TpChangeParameterFunc;*/
#endif
        Cdd_RxIndication,/*UpIfRxIndicationFunc;*/
        Cdd_TriggerTransmit,/*UpIfTriggerTransmitFunc;*/
        Cdd_TxConfirmation,/*UpIfTxConfirmationFunc;*/
        Cdd_CopyRxData,/*UpTpCopyRxDataFunc;*/
        Cdd_CopyTxData,/*UpTpCopyTxDataFunc;*/
        Cdd_StartOfReception,/*UpTpStartOfReceptionFunc;*/
        Cdd_TpRxIndication,/*UpTpRxIndicationFunc;*/
        Cdd_TpTxConfirmation/*UpTpTxConfirmationFunc;*/
    },
#endif
#if(STD_ON == PDUR_IPDUM_MODULE_SUPPORT)
    /*IpduM*/
    {
#if(STD_ON == PDUR_CANCEL_TRANSMIT_ENABLED)
        NULL_PTR,/*IfCancelTransmitFunc;*/
#endif
        NULL_PTR,/*IfTransmitFunc;*/
#if(STD_ON == PDUR_CANCEL_RECEIVE_ENABLED)
        NULL_PTR,/*TpCancelReceiveFunc;*/
#endif
#if(STD_ON == PDUR_CANCEL_TRANSMIT_ENABLED)
        NULL_PTR,/*TpCancelTransmitFunc;*/
#endif
        NULL_PTR,/*TpTransmitFunc;*/
#if(STD_ON == PDUR_CHANGEPARAMETER_API_ENABLED)
        NULL_PTR,/*TpChangeParameterFunc;*/
#endif
        IpduM_RxIndication,/*UpIfRxIndicationFunc;*/
        IpduM_TriggerTransmit,/*UpIfTriggerTransmitFunc;*/
        IpduM_TxConfirmation,/*UpIfTxConfirmationFunc;*/
        NULL_PTR,/*UpTpCopyRxDataFunc;*/
        NULL_PTR,/*UpTpCopyTxDataFunc;*/
        NULL_PTR,/*UpTpStartOfReceptionFunc;*/
        NULL_PTR,/*UpTpRxIndicationFunc;*/
        NULL_PTR/*UpTpTxConfirmationFunc;*/
    },
#endif
#if(STD_ON == PDUR_IPDUMIF_MODULE_SUPPORT)
    /*IpduMIf*/
    {
#if(STD_ON == PDUR_CANCEL_TRANSMIT_ENABLED)
        NULL_PTR,/*IfCancelTransmitFunc;*/
#endif
        IpduM_Transmit,/*IfTransmitFunc;*/
#if(STD_ON == PDUR_CANCEL_RECEIVE_ENABLED)
        NULL_PTR,/*TpCancelReceiveFunc;*/
#endif
#if(STD_ON == PDUR_CANCEL_TRANSMIT_ENABLED)
        NULL_PTR,/*TpCancelTransmitFunc;*/
#endif
        NULL_PTR,/*TpTransmitFunc;*/
#if(STD_ON == PDUR_CHANGEPARAMETER_API_ENABLED)
        NULL_PTR,/*TpChangeParameterFunc;*/
#endif
        NULL_PTR,/*UpIfRxIndicationFunc;*/
        NULL_PTR,/*UpIfTriggerTransmitFunc;*/
        NULL_PTR,/*UpIfTxConfirmationFunc;*/
        NULL_PTR,/*UpTpCopyRxDataFunc;*/
        NULL_PTR,/*UpTpCopyTxDataFunc;*/
        NULL_PTR,/*UpTpStartOfReceptionFunc;*/
        NULL_PTR,/*UpTpRxIndicationFunc;*/
        NULL_PTR/*UpTpTxConfirmationFunc;*/
    },
#endif
#if(STD_ON == PDUR_SOMEIP_MODULE_SUPPORT)
    /*SomeIp*/
    {
#if(STD_ON == PDUR_CANCEL_TRANSMIT_ENABLED)
        NULL_PTR,/*IfCancelTransmitFunc;*/
#endif
        NULL_PTR,/*IfTransmitFunc;*/
#if(STD_ON == PDUR_CANCEL_RECEIVE_ENABLED)
        NULL_PTR,/*TpCancelReceiveFunc;*/
#endif
#if(STD_ON == PDUR_CANCEL_TRANSMIT_ENABLED)
        NULL_PTR,/*TpCancelTransmitFunc;*/
#endif
        NULL_PTR,/*TpTransmitFunc;*/
#if(STD_ON == PDUR_CHANGEPARAMETER_API_ENABLED)
        NULL_PTR,/*TpChangeParameterFunc;*/
#endif
        SomeIpTp_RxIndication,/*UpIfRxIndicationFunc;*/
        SomeIpTp_TriggerTransmit,/*UpIfTriggerTransmitFunc;*/
        SomeIpTp_TxConfirmation,/*UpIfTxConfirmationFunc;*/
        NULL_PTR,/*UpTpCopyRxDataFunc;*/
        NULL_PTR,/*UpTpCopyTxDataFunc;*/
        NULL_PTR,/*UpTpStartOfReceptionFunc;*/
        NULL_PTR,/*UpTpRxIndicationFunc;*/
        NULL_PTR/*UpTpTxConfirmationFunc;*/
    },
#endif
#if(STD_ON == PDUR_SOMEIPTP_MODULE_SUPPORT)
    /*SomeIpTp*/
    {
#if(STD_ON == PDUR_CANCEL_TRANSMIT_ENABLED)
        NULL_PTR,/*IfCancelTransmitFunc;*/
#endif
        NULL_PTR,/*IfTransmitFunc;*/
#if(STD_ON == PDUR_CANCEL_RECEIVE_ENABLED)
        NULL_PTR,/*TpCancelReceiveFunc;*/
#endif
#if(STD_ON == PDUR_CANCEL_TRANSMIT_ENABLED)
        NULL_PTR,/*TpCancelTransmitFunc;*/
#endif
        SomeIpTp_Transmit,/*TpTransmitFunc;*/
#if(STD_ON == PDUR_CHANGEPARAMETER_API_ENABLED)
        NULL_PTR,/*TpChangeParameterFunc;*/
#endif
        NULL_PTR,/*UpIfRxIndicationFunc;*/
        NULL_PTR,/*UpIfTriggerTransmitFunc;*/
        NULL_PTR,/*UpIfTxConfirmationFunc;*/
        NULL_PTR,/*UpTpCopyRxDataFunc;*/
        NULL_PTR,/*UpTpCopyTxDataFunc;*/
        NULL_PTR,/*UpTpStartOfReceptionFunc;*/
        NULL_PTR,/*UpTpRxIndicationFunc;*/
        NULL_PTR/*UpTpTxConfirmationFunc;*/
    },
#endif
#if(STD_ON == PDUR_CANIF_MODULE_SUPPORT)
    /*CanIf*/
    {
#if(STD_ON == PDUR_CANCEL_TRANSMIT_ENABLED)
#if(STD_ON == PDUR_CANIF_CANCELTRANSMIT_ENABLED)
        CanIf_CancelTransmit,/*IfCancelTransmitFunc;*/
#else
        NULL_PTR,/*IfCancelTransmitFunc;*/
#endif
#endif
        CanIf_Transmit,/*IfTransmitFunc;*/
#if(STD_ON == PDUR_CANCEL_RECEIVE_ENABLED)
        NULL_PTR,/*TpCancelReceiveFunc;*/
#endif
#if(STD_ON == PDUR_CANCEL_TRANSMIT_ENABLED)
        NULL_PTR,/*TpCancelTransmitFunc;*/
#endif
        NULL_PTR,/*TpTransmitFunc;*/
#if(STD_ON == PDUR_CHANGEPARAMETER_API_ENABLED)
        NULL_PTR,/*TpChangeParameterFunc;*/
#endif
        NULL_PTR,/*UpIfRxIndicationFunc;*/
        NULL_PTR,/*UpIfTriggerTransmitFunc;*/
        NULL_PTR,/*UpIfTxConfirmationFunc;*/
        NULL_PTR,/*UpTpCopyRxDataFunc;*/
        NULL_PTR,/*UpTpCopyTxDataFunc;*/
        NULL_PTR,/*UpTpStartOfReceptionFunc;*/
        NULL_PTR,/*UpTpRxIndicationFunc;*/
        NULL_PTR/*UpTpTxConfirmationFunc;*/
    },
#endif
#if(STD_ON == PDUR_CANTP_MODULE_SUPPORT)
    /*CanTp*/
    {
#if(STD_ON == PDUR_CANCEL_TRANSMIT_ENABLED)
        NULL_PTR,/*IfCancelTransmitFunc;*/
#endif
        NULL_PTR,/*IfTransmitFunc;*/
#if(STD_ON == PDUR_CANCEL_RECEIVE_ENABLED)
#if(STD_ON == PDUR_CANTP_CANCELRECEIVE_ENABLED)
        CanTp_CancelReceive,/*TpCancelReceiveFunc;*/
#else
        NULL_PTR,
#endif
#endif
#if(STD_ON == PDUR_CANCEL_TRANSMIT_ENABLED)
#if(STD_ON == PDUR_CANTP_CANCELTRANSMIT_ENABLED)
        CanTp_CancelTransmit,/*TpCancelTransmitFunc;*/
#else
        NULL_PTR,
#endif
#endif
        CanTp_Transmit,/*TpTransmitFunc;*/
#if(STD_ON == PDUR_CHANGEPARAMETER_API_ENABLED)
#if(STD_ON == PDUR_CANTP_CHANGEPARAMETER_API_ENABLED)
        CanTp_ChangeParameter,/*TpChangeParameterFunc;*/
#else
        NULL_PTR,
#endif
#endif
        NULL_PTR,/*UpIfRxIndicationFunc;*/
        NULL_PTR,/*UpIfTriggerTransmitFunc;*/
        NULL_PTR,/*UpIfTxConfirmationFunc;*/
        NULL_PTR,/*UpTpCopyRxDataFunc;*/
        NULL_PTR,/*UpTpCopyTxDataFunc;*/
        NULL_PTR,/*UpTpStartOfReceptionFunc;*/
        NULL_PTR,/*UpTpRxIndicationFunc;*/
        NULL_PTR/*UpTpTxConfirmationFunc;*/
    },
#endif
#if(STD_ON == PDUR_CANNM_MODULE_SUPPORT)
    /*CanNm*/
    {
#if(STD_ON == PDUR_CANCEL_TRANSMIT_ENABLED)
        NULL_PTR,/*IfCancelTransmitFunc;*/
#endif
        CanNm_Transmit,/*IfTransmitFunc;*/
#if(STD_ON == PDUR_CANCEL_RECEIVE_ENABLED)
        NULL_PTR,/*TpCancelReceiveFunc;*/
#endif
#if(STD_ON == PDUR_CANCEL_TRANSMIT_ENABLED)
        NULL_PTR,/*TpCancelTransmitFunc;*/
#endif
        NULL_PTR,/*TpTransmitFunc;*/
#if(STD_ON == PDUR_CHANGEPARAMETER_API_ENABLED)
        NULL_PTR,/*TpChangeParameterFunc;*/
#endif
        NULL_PTR,/*UpIfRxIndicationFunc;*/
        NULL_PTR,/*UpIfTriggerTransmitFunc;*/
        NULL_PTR,/*UpIfTxConfirmationFunc;*/
        NULL_PTR,/*UpTpCopyRxDataFunc;*/
        NULL_PTR,/*UpTpCopyTxDataFunc;*/
        NULL_PTR,/*UpTpStartOfReceptionFunc;*/
        NULL_PTR,/*UpTpRxIndicationFunc;*/
        NULL_PTR/*UpTpTxConfirmationFunc;*/
    },
#endif
#if(STD_ON == PDUR_UDPNM_MODULE_SUPPORT)
    /*UdpNm*/
    {
#if(STD_ON == PDUR_CANCEL_TRANSMIT_ENABLED)
        NULL_PTR,/*IfCancelTransmitFunc;*/
#endif
        UdpNm_Transmit,/*IfTransmitFunc;*/
#if(STD_ON == PDUR_CANCEL_RECEIVE_ENABLED)
        NULL_PTR,/*TpCancelReceiveFunc;*/
#endif
#if(STD_ON == PDUR_CANCEL_TRANSMIT_ENABLED)
        NULL_PTR,/*TpCancelTransmitFunc;*/
#endif
        NULL_PTR,/*TpTransmitFunc;*/
#if(STD_ON == PDUR_CHANGEPARAMETER_API_ENABLED)
        NULL_PTR,/*TpChangeParameterFunc;*/
#endif
        NULL_PTR,/*UpIfRxIndicationFunc;*/
        NULL_PTR,/*UpIfTriggerTransmitFunc;*/
        NULL_PTR,/*UpIfTxConfirmationFunc;*/
        NULL_PTR,/*UpTpCopyRxDataFunc;*/
        NULL_PTR,/*UpTpCopyTxDataFunc;*/
        NULL_PTR,/*UpTpStartOfReceptionFunc;*/
        NULL_PTR,/*UpTpRxIndicationFunc;*/
        NULL_PTR/*UpTpTxConfirmationFunc;*/
    },
#endif
#if(STD_ON == PDUR_LINIF_MODULE_SUPPORT)
    /*LinIf*/
    {
#if(STD_ON == PDUR_CANCEL_TRANSMIT_ENABLED)
#if(STD_ON == PDUR_LINIF_CANCELTRANSMIT_ENABLED)
        LinIf_CancelTransmit,/*IfCancelTransmitFunc;*/
#else
        NULL_PTR,/*IfCancelTransmitFunc;*/
#endif
#endif
        LinIf_Transmit,/*IfTransmitFunc;*/
#if(STD_ON == PDUR_CANCEL_RECEIVE_ENABLED)
        NULL_PTR,/*TpCancelReceiveFunc;*/
#endif
#if(STD_ON == PDUR_CANCEL_TRANSMIT_ENABLED)
        NULL_PTR,/*TpCancelTransmitFunc;*/
#endif
        NULL_PTR,/*TpTransmitFunc;*/
#if(STD_ON == PDUR_CHANGEPARAMETER_API_ENABLED)
        NULL_PTR,/*TpChangeParameterFunc;*/
#endif
        NULL_PTR,/*UpIfRxIndicationFunc;*/
        NULL_PTR,/*UpIfTriggerTransmitFunc;*/
        NULL_PTR,/*UpIfTxConfirmationFunc;*/
        NULL_PTR,/*UpTpCopyRxDataFunc;*/
        NULL_PTR,/*UpTpCopyTxDataFunc;*/
        NULL_PTR,/*UpTpStartOfReceptionFunc;*/
        NULL_PTR,/*UpTpRxIndicationFunc;*/
        NULL_PTR/*UpTpTxConfirmationFunc;*/
    },
#endif
#if(STD_ON == PDUR_LINTP_MODULE_SUPPORT)
    /*LinTp*/
    {
#if(STD_ON == PDUR_CANCEL_TRANSMIT_ENABLED)
        NULL_PTR,/*IfCancelTransmitFunc;*/
#endif
        NULL_PTR,/*IfTransmitFunc;*/
#if(STD_ON == PDUR_CANCEL_RECEIVE_ENABLED)
#if(STD_ON == PDUR_LINTP_CANCELRECEIVE_ENABLED)
        LinTp_CancelReceive,/*TpCancelReceiveFunc;*/
#else
        NULL_PTR,
#endif
#endif
#if(STD_ON == PDUR_CANCEL_TRANSMIT_ENABLED)
#if(STD_ON == PDUR_LINTP_CANCELTRANSMIT_ENABLED)
        LinTp_CancelTransmit,/*TpCancelTransmitFunc;*/
#else
        NULL_PTR,
#endif
#endif
        LinTp_Transmit,/*TpTransmitFunc;*/
#if(STD_ON == PDUR_CHANGEPARAMETER_API_ENABLED)
#if(STD_ON == PDUR_LINTP_CHANGEPARAMETER_API_ENABLED)
        LinTp_ChangeParameter,/*TpChangeParameterFunc;*/
#else
        NULL_PTR,
#endif
#endif
        NULL_PTR,/*UpIfRxIndicationFunc;*/
        NULL_PTR,/*UpIfTriggerTransmitFunc;*/
        NULL_PTR,/*UpIfTxConfirmationFunc;*/
        NULL_PTR,/*UpTpCopyRxDataFunc;*/
        NULL_PTR,/*UpTpCopyTxDataFunc;*/
        NULL_PTR,/*UpTpStartOfReceptionFunc;*/
        NULL_PTR,/*UpTpRxIndicationFunc;*/
        NULL_PTR/*UpTpTxConfirmationFunc;*/
    },
#endif
#if(STD_ON == PDUR_FRIF_MODULE_SUPPORT)
    /*FrIf*/
    {
#if(STD_ON == PDUR_CANCEL_TRANSMIT_ENABLED)
#if(STD_ON == PDUR_FRIF_CANCELTRANSMIT_ENABLED)
        FrIf_CancelTransmit,/*IfCancelTransmitFunc;*/
#else
        NULL_PTR,/*IfCancelTransmitFunc;*/
#endif
#endif
        FrIf_Transmit,/*IfTransmitFunc;*/
#if(STD_ON == PDUR_CANCEL_RECEIVE_ENABLED)
        NULL_PTR,/*TpCancelReceiveFunc;*/
#endif
#if(STD_ON == PDUR_CANCEL_TRANSMIT_ENABLED)
        NULL_PTR,/*TpCancelTransmitFunc;*/
#endif
        NULL_PTR,/*TpTransmitFunc;*/
#if(STD_ON == PDUR_CHANGEPARAMETER_API_ENABLED)
        NULL_PTR,/*TpChangeParameterFunc;*/
#endif
        NULL_PTR,/*UpIfRxIndicationFunc;*/
        NULL_PTR,/*UpIfTriggerTransmitFunc;*/
        NULL_PTR,/*UpIfTxConfirmationFunc;*/
        NULL_PTR,/*UpTpCopyRxDataFunc;*/
        NULL_PTR,/*UpTpCopyTxDataFunc;*/
        NULL_PTR,/*UpTpStartOfReceptionFunc;*/
        NULL_PTR,/*UpTpRxIndicationFunc;*/
        NULL_PTR/*UpTpTxConfirmationFunc;*/
    },
#endif
#if(STD_ON == PDUR_FRTP_MODULE_SUPPORT)
    /*FrTp*/
    {
#if(STD_ON == PDUR_CANCEL_TRANSMIT_ENABLED)
        NULL_PTR,/*IfCancelTransmitFunc;*/
#endif
        NULL_PTR,/*IfTransmitFunc;*/
#if(STD_ON == PDUR_CANCEL_RECEIVE_ENABLED)
#if(STD_ON == PDUR_FRTP_CANCELRECEIVE_ENABLED)
        FrTp_CancelReceive,/*TpCancelReceiveFunc;*/
#else
        NULL_PTR,
#endif
#endif
#if(STD_ON == PDUR_CANCEL_TRANSMIT_ENABLED)
#if(STD_ON == PDUR_FRTP_CANCELTRANSMIT_ENABLED)
        FrTp_CancelTransmit,/*TpCancelTransmitFunc;*/
#else
        NULL_PTR,
#endif
#endif
        FrTp_Transmit,/*TpTransmitFunc;*/
#if(STD_ON == PDUR_CHANGEPARAMETER_API_ENABLED)
#if(STD_ON == PDUR_FRTP_CHANGEPARAMETER_API_ENABLED)
        FrTp_ChangeParameter,/*TpChangeParameterFunc;*/
#else
        NULL_PTR,
#endif
#endif
        NULL_PTR,/*UpIfRxIndicationFunc;*/
        NULL_PTR,/*UpIfTriggerTransmitFunc;*/
        NULL_PTR,/*UpIfTxConfirmationFunc;*/
        NULL_PTR,/*UpTpCopyRxDataFunc;*/
        NULL_PTR,/*UpTpCopyTxDataFunc;*/
        NULL_PTR,/*UpTpStartOfReceptionFunc;*/
        NULL_PTR,/*UpTpRxIndicationFunc;*/
        NULL_PTR/*UpTpTxConfirmationFunc;*/
    },
#endif
#if(STD_ON == PDUR_DOIPIF_MODULE_SUPPORT)
    /*DoIPIf*/
    {
#if(STD_ON == PDUR_CANCEL_TRANSMIT_ENABLED)
#if(STD_ON == PDUR_DOIPIF_CANCELTRANSMIT_ENABLED)
        DoIP_IfCancelTransmit,/*IfCancelTransmitFunc;*/
#else
        NULL_PTR,/*IfCancelTransmitFunc;*/
#endif
#endif
        DoIP_IfTransmit,/*IfTransmitFunc;*/
#if(STD_ON == PDUR_CANCEL_RECEIVE_ENABLED)
        NULL_PTR,/*TpCancelReceiveFunc;*/
#endif
#if(STD_ON == PDUR_CANCEL_TRANSMIT_ENABLED)
        NULL_PTR,/*TpCancelTransmitFunc;*/
#endif
        NULL_PTR,/*TpTransmitFunc;*/
#if(STD_ON == PDUR_CHANGEPARAMETER_API_ENABLED)
        NULL_PTR,/*TpChangeParameterFunc;*/
#endif
        NULL_PTR,/*UpIfRxIndicationFunc;*/
        NULL_PTR,/*UpIfTriggerTransmitFunc;*/
        NULL_PTR,/*UpIfTxConfirmationFunc;*/
        NULL_PTR,/*UpTpCopyRxDataFunc;*/
        NULL_PTR,/*UpTpCopyTxDataFunc;*/
        NULL_PTR,/*UpTpStartOfReceptionFunc;*/
        NULL_PTR,/*UpTpRxIndicationFunc;*/
        NULL_PTR/*UpTpTxConfirmationFunc;*/
    },
#endif
#if(STD_ON == PDUR_DOIPTP_MODULE_SUPPORT)
    /*DoIPTp*/
    {
#if(STD_ON == PDUR_CANCEL_TRANSMIT_ENABLED)
        NULL_PTR,/*IfCancelTransmitFunc;*/
#endif
        NULL_PTR,/*IfTransmitFunc;*/
#if(STD_ON == PDUR_CANCEL_RECEIVE_ENABLED)
#if(STD_ON == PDUR_DOIPTP_CANCELRECEIVE_ENABLED)
        DoIP_TpCancelReceive,/*TpCancelReceiveFunc;*/
#else
        NULL_PTR,
#endif
#endif
#if(STD_ON == PDUR_CANCEL_TRANSMIT_ENABLED)
#if(STD_ON == PDUR_DOIPTP_CANCELTRANSMIT_ENABLED)
        DoIP_TpCancelTransmit,/*TpCancelTransmitFunc;*/
#else
        NULL_PTR,
#endif
#endif
        DoIP_TpTransmit,/*TpTransmitFunc;*/
#if(STD_ON == PDUR_CHANGEPARAMETER_API_ENABLED)
        NULL_PTR,/*TpChangeParameterFunc;*/
#endif
        NULL_PTR,/*UpIfRxIndicationFunc;*/
        NULL_PTR,/*UpIfTriggerTransmitFunc;*/
        NULL_PTR,/*UpIfTxConfirmationFunc;*/
        NULL_PTR,/*UpTpCopyRxDataFunc;*/
        NULL_PTR,/*UpTpCopyTxDataFunc;*/
        NULL_PTR,/*UpTpStartOfReceptionFunc;*/
        NULL_PTR,/*UpTpRxIndicationFunc;*/
        NULL_PTR/*UpTpTxConfirmationFunc;*/
    },
#endif
#if(STD_ON == PDUR_J1939TP_MODULE_SUPPORT)
    /*J1939Tp*/
    {
#if(STD_ON == PDUR_CANCEL_TRANSMIT_ENABLED)
        NULL_PTR,/*IfCancelTransmitFunc;*/
#endif
        NULL_PTR,/*IfTransmitFunc;*/
#if(STD_ON == PDUR_CANCEL_RECEIVE_ENABLED)
#if(STD_ON == PDUR_J1939TP_CANCELRECEIVE_ENABLED)
        J1939Tp_CancelReceive,/*TpCancelReceiveFunc;*/
#else
        NULL_PTR,
#endif
#endif
#if(STD_ON == PDUR_CANCEL_TRANSMIT_ENABLED)
#if(STD_ON == PDUR_J1939TP_CANCELTRANSMIT_ENABLED)
        J1939Tp_CancelTransmit,/*TpCancelTransmitFunc;*/
#else
        NULL_PTR,
#endif
#endif
        J1939Tp_Transmit,/*TpTransmitFunc;*/
#if(STD_ON == PDUR_CHANGEPARAMETER_API_ENABLED)
#if(STD_ON == PDUR_J1939TP_CHANGEPARAMETER_API_ENABLED)
        J1939Tp_ChangeParameter,/*TpChangeParameterFunc;*/
#else
        NULL_PTR,
#endif
#endif
        NULL_PTR,/*UpIfRxIndicationFunc;*/
        NULL_PTR,/*UpIfTriggerTransmitFunc;*/
        NULL_PTR,/*UpIfTxConfirmationFunc;*/
        NULL_PTR,/*UpTpCopyRxDataFunc;*/
        NULL_PTR,/*UpTpCopyTxDataFunc;*/
        NULL_PTR,/*UpTpStartOfReceptionFunc;*/
        NULL_PTR,/*UpTpRxIndicationFunc;*/
        NULL_PTR/*UpTpTxConfirmationFunc;*/
    },
#endif
#if(STD_ON == PDUR_SOADIF_MODULE_SUPPORT)
    /*SoAdIf*/
    {
#if(STD_ON == PDUR_CANCEL_TRANSMIT_ENABLED)
        NULL_PTR,/*IfCancelTransmitFunc;*/
#endif
        SoAd_IfTransmit,/*IfTransmitFunc;*/
#if(STD_ON == PDUR_CANCEL_RECEIVE_ENABLED)
        NULL_PTR,/*TpCancelReceiveFunc;*/
#endif
#if(STD_ON == PDUR_CANCEL_TRANSMIT_ENABLED)
        NULL_PTR,/*TpCancelTransmitFunc;*/
#endif
        NULL_PTR,/*TpTransmitFunc;*/
#if(STD_ON == PDUR_CHANGEPARAMETER_API_ENABLED)
        NULL_PTR,/*TpChangeParameterFunc;*/
#endif
        NULL_PTR,/*UpIfRxIndicationFunc;*/
        NULL_PTR,/*UpIfTriggerTransmitFunc;*/
        NULL_PTR,/*UpIfTxConfirmationFunc;*/
        NULL_PTR,/*UpTpCopyRxDataFunc;*/
        NULL_PTR,/*UpTpCopyTxDataFunc;*/
        NULL_PTR,/*UpTpStartOfReceptionFunc;*/
        NULL_PTR,/*UpTpRxIndicationFunc;*/
        NULL_PTR/*UpTpTxConfirmationFunc;*/
    },
#endif
#if(STD_ON == PDUR_SOADTP_MODULE_SUPPORT)
    /*SoAdTp*/
    {
#if(STD_ON == PDUR_CANCEL_TRANSMIT_ENABLED)
        NULL_PTR,/*IfCancelTransmitFunc;*/
#endif
        NULL_PTR,/*IfTransmitFunc;*/
#if(STD_ON == PDUR_CANCEL_RECEIVE_ENABLED)
#if(STD_ON == PDUR_SOADTP_CANCELRECEIVE_ENABLED)
        SoAd_TpCancelReceive,/*TpCancelReceiveFunc;*/
#else
        NULL_PTR,
#endif
#endif
#if(STD_ON == PDUR_CANCEL_TRANSMIT_ENABLED)
#if(STD_ON == PDUR_SOADTP_CANCELTRANSMIT_ENABLED)
        SoAd_TpCancelTransmit,/*TpCancelTransmitFunc;*/
#else
        NULL_PTR,
#endif
#endif
        SoAd_TpTransmit,/*TpTransmitFunc;*/
#if(STD_ON == PDUR_CHANGEPARAMETER_API_ENABLED)
#if(STD_ON == PDUR_SOADTP_CHANGEPARAMETER_API_ENABLED)
        SoAd_TpChangeParameter,/*TpChangeParameterFunc;*/
#else
        NULL_PTR,
#endif
#endif
        NULL_PTR,/*UpIfRxIndicationFunc;*/
        NULL_PTR,/*UpIfTriggerTransmitFunc;*/
        NULL_PTR,/*UpIfTxConfirmationFunc;*/
        NULL_PTR,/*UpTpCopyRxDataFunc;*/
        NULL_PTR,/*UpTpCopyTxDataFunc;*/
        NULL_PTR,/*UpTpStartOfReceptionFunc;*/
        NULL_PTR,/*UpTpRxIndicationFunc;*/
        NULL_PTR/*UpTpTxConfirmationFunc;*/
    },
#endif
#if(STD_ON == PDUR_CDDIF_MODULE_SUPPORT)
    /*CddIf*/
    {
#if(STD_ON == PDUR_CANCEL_TRANSMIT_ENABLED)
#if(STD_ON == PDUR_CDDIF_CANCELTRANSMIT_ENABLED)
        CddIf_CancelTransmit,/*IfCancelTransmitFunc;*/
#else
        NULL_PTR,/*IfCancelTransmitFunc;*/
#endif
#endif
        CddIf_Transmit,/*IfTransmitFunc;*/
#if(STD_ON == PDUR_CANCEL_RECEIVE_ENABLED)
        NULL_PTR,/*TpCancelReceiveFunc;*/
#endif
#if(STD_ON == PDUR_CANCEL_TRANSMIT_ENABLED)
        NULL_PTR,/*TpCancelTransmitFunc;*/
#endif
        NULL_PTR,/*TpTransmitFunc;*/
#if(STD_ON == PDUR_CHANGEPARAMETER_API_ENABLED)
        NULL_PTR,/*TpChangeParameterFunc;*/
#endif
        NULL_PTR,/*UpIfRxIndicationFunc;*/
        NULL_PTR,/*UpIfTriggerTransmitFunc;*/
        NULL_PTR,/*UpIfTxConfirmationFunc;*/
        NULL_PTR,/*UpTpCopyRxDataFunc;*/
        NULL_PTR,/*UpTpCopyTxDataFunc;*/
        NULL_PTR,/*UpTpStartOfReceptionFunc;*/
        NULL_PTR,/*UpTpRxIndicationFunc;*/
        NULL_PTR/*UpTpTxConfirmationFunc;*/
    },
#endif
#if(STD_ON == PDUR_CDDTP_MODULE_SUPPORT)
    /*CddTp*/
    {
#if(STD_ON == PDUR_CANCEL_TRANSMIT_ENABLED)
        NULL_PTR,/*IfCancelTransmitFunc;*/
#endif
        NULL_PTR,/*IfTransmitFunc;*/
#if(STD_ON == PDUR_CANCEL_RECEIVE_ENABLED)
        Cdd_TpCancelReceive,/*TpCancelReceiveFunc;*/
#endif
#if(STD_ON == PDUR_CANCEL_TRANSMIT_ENABLED)
#if(STD_ON == PDUR_CDDTP_CANCELTRANSMIT_ENABLED)
        Cdd_TpCancelTransmit,/*TpCancelTransmitFunc;*/
#else
        NULL_PTR,
#endif
#endif
        Cdd_TpTransmit,/*TpTransmitFunc;*/
#if(STD_ON == PDUR_CHANGEPARAMETER_API_ENABLED)
        Cdd_TpChangeParameter,/*TpChangeParameterFunc;*/
#endif
        NULL_PTR,/*UpIfRxIndicationFunc;*/
        NULL_PTR,/*UpIfTriggerTransmitFunc;*/
        NULL_PTR,/*UpIfTxConfirmationFunc;*/
        NULL_PTR,/*UpTpCopyRxDataFunc;*/
        NULL_PTR,/*UpTpCopyTxDataFunc;*/
        NULL_PTR,/*UpTpStartOfReceptionFunc;*/
        NULL_PTR,/*UpTpRxIndicationFunc;*/
        NULL_PTR/*UpTpTxConfirmationFunc;*/
    },
#endif
#if(STD_ON == PDUR_SECOC_MODULE_SUPPORT)
    {
#if(STD_ON == PDUR_CANCEL_TRANSMIT_ENABLED)
        SecOC_IfCancelTransmit,/*IfCancelTransmitFunc;*/
#endif
        SecOC_IfTransmit,/*IfTransmitFunc;*/
#if(STD_ON == PDUR_CANCEL_RECEIVE_ENABLED)
		SecOC_TpCancelReceive,/*TpCancelReceiveFunc;*/
#endif
#if(STD_ON == PDUR_CANCEL_TRANSMIT_ENABLED)
        NULL_PTR,/*TpCancelTransmitFunc;*/
#endif
        NULL_PTR,/*TpTransmitFunc;*/ 
#if(STD_ON == PDUR_CHANGEPARAMETER_API_ENABLED)
        NULL_PTR,/*TpChangeParameterFunc;*/
#endif
        SecOC_RxIndication,/*UpIfRxIndicationFunc;*/
#if(STD_ON == PDUR_SECOC_TRIGGER_TRANSMIT_ENABLED)
        SecOC_TriggerTransmit,/*UpIfTriggerTransmitFunc;*/
#else
		NULL_PTR,/*UpIfTriggerTransmitFunc;*/
#endif
        SecOC_TxConfirmation,/*UpIfTxConfirmationFunc;*/
        SecOC_CopyRxData,/*UpTpCopyRxDataFunc;*/
        SecOC_CopyTxData,/*UpTpCopyTxDataFunc;*/
        SecOC_StartOfReception,/*UpTpStartOfReceptionFunc;*/
        SecOC_TpRxIndication,/*UpTpRxIndicationFunc;*/
        SecOC_TpTxConfirmation/*UpTpTxConfirmationFunc;*/
    },
#endif
#if(STD_ON == PDUR_SECOCIF_MODULE_SUPPORT)
    /*SecOCIf*/
    {
#if(STD_ON == PDUR_CANCEL_TRANSMIT_ENABLED)
        SecOC_IfCancelTransmit,/*IfCancelTransmitFunc;*/
#endif
        SecOC_IfTransmit,/*IfTransmitFunc;*/
#if(STD_ON == PDUR_CANCEL_RECEIVE_ENABLED)
        NULL_PTR,/*TpCancelReceiveFunc;*/
#endif
#if(STD_ON == PDUR_CANCEL_TRANSMIT_ENABLED)
        NULL_PTR,/*TpCancelTransmitFunc;*/
#endif
        NULL_PTR,/*TpTransmitFunc;*/
#if(STD_ON == PDUR_CHANGEPARAMETER_API_ENABLED)
        NULL_PTR,/*TpChangeParameterFunc;*/
#endif
        NULL_PTR,/*UpIfRxIndicationFunc;*/
        NULL_PTR,/*UpIfTriggerTransmitFunc;*/
        NULL_PTR,/*UpIfTxConfirmationFunc;*/
        NULL_PTR,/*UpTpCopyRxDataFunc;*/
        NULL_PTR,/*UpTpCopyTxDataFunc;*/
        NULL_PTR,/*UpTpStartOfReceptionFunc;*/
        NULL_PTR,/*UpTpRxIndicationFunc;*/
        NULL_PTR/*UpTpTxConfirmationFunc;*/
    },
#endif
#if(STD_ON == PDUR_SECOCTP_MODULE_SUPPORT)
    /*SecOCTp*/
    {
#if(STD_ON == PDUR_CANCEL_TRANSMIT_ENABLED)
        NULL_PTR,/*IfCancelTransmitFunc;*/
#endif
        NULL_PTR,/*IfTransmitFunc;*/
#if(STD_ON == PDUR_CANCEL_RECEIVE_ENABLED)
        NULL_PTR,/*TpCancelReceiveFunc;*/
#endif
#if(STD_ON == PDUR_CANCEL_TRANSMIT_ENABLED)
        SecOC_TpCancelTransmit,/*TpCancelTransmitFunc;*/
#endif
        SecOC_TpTransmit,/*TpTransmitFunc;*/
#if(STD_ON == PDUR_CHANGEPARAMETER_API_ENABLED)
        NULL_PTR,/*TpChangeParameterFunc;*/
#endif
        NULL_PTR,/*UpIfRxIndicationFunc;*/
        NULL_PTR,/*UpIfTriggerTransmitFunc;*/
        SecOC_TxConfirmation,/*UpIfTxConfirmationFunc;*/
        SecOC_CopyRxData,/*UpTpCopyRxDataFunc;*/
        SecOC_CopyTxData,/*UpTpCopyTxDataFunc;*/
        SecOC_StartOfReception,/*UpTpStartOfReceptionFunc;*/
        SecOC_TpRxIndication,/*UpTpRxIndicationFunc;*/
        SecOC_TpTxConfirmation/*UpTpTxConfirmationFunc;*/
    },
#endif

};

#define PDUR_STOP_SEC_CONST_32
#include "MemMap.h"

#define PDUR_START_SEC_NOINIT_UNSPECIFIED
#include "MemMap.h"

#if(PDUR_CONFIG_VARIANTS == STD_CONFIG_VARIANTS_POSTBUILD)
STATIC P2CONST(PduR_PBConfigType, PDUR_VAR_NOINIT, PDUR_CONST) PduR_ConfigSet;
#endif

#if(PDUR_MAX_NUMOFBUFFER > 0)
STATIC PduRBuffInfoType PduRBufferInfo[PDUR_MAX_NUMOFBUFFER];
#endif

#define PDUR_STOP_SEC_NOINIT_UNSPECIFIED
#include "MemMap.h"

#define PDUR_START_SEC_VAR_NOINIT_8
#include "MemMap.h"

STATIC VAR(boolean, PDUR_VAR) PduR_RoutingPathGroupEnabled[PDUR_MAX_NUMOFROUTINGPATHGROUP];

#define PDUR_STOP_SEC_VAR_NOINIT_8
#include "MemMap.h"

#define PDUR_START_SEC_VAR_INIT_32
#include "MemMap.h"

#if(PDUR_MAX_NUMOFCOMTXPDU > 0)
STATIC VAR(PduR_MulticastMaskType, PDUR_VAR) ComTxConfMask[PDUR_MAX_NUMOFCOMTXPDU] =
{
    0
};
STATIC VAR(PduR_MulticastMaskType, PDUR_VAR) ComTxErrorMask[PDUR_MAX_NUMOFCOMTXPDU] =
{
    0
};
#endif
#if(PDUR_MAX_NUMOFLDCOMTXPDU > 0)
STATIC VAR(PduR_MulticastMaskType, PDUR_VAR) LdComTxConfMask[PDUR_MAX_NUMOFLDCOMTXPDU] =
{
    0
};
STATIC VAR(PduR_MulticastMaskType, PDUR_VAR) LdComTxErrorMask[PDUR_MAX_NUMOFLDCOMTXPDU] =
{
    0
};
#endif
#if(PDUR_MAX_NUMOFDCMTXPDU > 0)
STATIC VAR(PduR_MulticastMaskType, PDUR_VAR) DcmTxConfMask[PDUR_MAX_NUMOFDCMTXPDU] =
{
    0
};
STATIC VAR(PduR_MulticastMaskType, PDUR_VAR) DcmTxErrorMask[PDUR_MAX_NUMOFDCMTXPDU] =
{
    0
};
#endif
#if(PDUR_MAX_NUMOFJ1939DCMTXPDU > 0)
STATIC VAR(PduR_MulticastMaskType, PDUR_VAR) J1939DcmTxConfMask[PDUR_MAX_NUMOFJ1939DCMTXPDU] =
{
    0
};
STATIC VAR(PduR_MulticastMaskType, PDUR_VAR) J1939DcmTxErrorMask[PDUR_MAX_NUMOFJ1939DCMTXPDU] =
{
    0
};
#endif
#if(PDUR_MAX_NUMOFJ1939RMTXPDU > 0)
STATIC VAR(PduR_MulticastMaskType, PDUR_VAR) J1939RmTxConfMask[PDUR_MAX_NUMOFJ1939RMTXPDU] =
{
    0
};
STATIC VAR(PduR_MulticastMaskType, PDUR_VAR) J1939RmTxErrorMask[PDUR_MAX_NUMOFJ1939RMTXPDU] =
{
    0
};
#endif
#if(PDUR_MAX_NUMOFCDDTXPDU > 0)
STATIC VAR(PduR_MulticastMaskType, PDUR_VAR) CddTxConfMask[PDUR_MAX_NUMOFCDDTXPDU] =
{
    0
};
STATIC VAR(PduR_MulticastMaskType, PDUR_VAR) CddTxErrorMask[PDUR_MAX_NUMOFCDDTXPDU] =
{
    0
};
#endif
#if(PDUR_MAX_NUMOFIPDUMTXPDU > 0)
STATIC VAR(PduR_MulticastMaskType, PDUR_VAR) IpduMTxConfMask[PDUR_MAX_NUMOFIPDUMTXPDU] =
{
    0
};
STATIC VAR(PduR_MulticastMaskType, PDUR_VAR) IpduMTxErrorMask[PDUR_MAX_NUMOFIPDUMTXPDU] =
{
    0
};
#endif
#if(PDUR_MAX_NUMOFSOMEIPTXPDU > 0)
STATIC VAR(PduR_MulticastMaskType, PDUR_VAR) SomeIpTxConfMask[PDUR_MAX_NUMOFSOMEIPTXPDU] =
{
    0
};
STATIC VAR(PduR_MulticastMaskType, PDUR_VAR) SomeIpTxErrorMask[PDUR_MAX_NUMOFSOMEIPTXPDU] =
{
    0
};
#endif
#if(PDUR_MAX_NUMOFSECOCTXPDU > 0)
STATIC VAR(PduR_MulticastMaskType, PDUR_VAR) SecOCTxConfMask[PDUR_MAX_NUMOFSECOCTXPDU] =
{
    0
};
STATIC VAR(PduR_MulticastMaskType, PDUR_VAR) SecOCTxErrorMask[PDUR_MAX_NUMOFSECOCTXPDU] =
{
    0
};
#endif


#define PDUR_STOP_SEC_VAR_INIT_32
#include "MemMap.h"


/*******************************************************************************
*   Local Functions define
*******************************************************************************/
#define PDUR_START_SEC_CODE
#include "MemMap.h"

#if(PDUR_MAX_NUMOFBUFFER > 0)
STATIC FUNC(void, PDUR_CODE) PduR_BufferInit
(
    uint16 BufferId
);

STATIC FUNC(Std_ReturnType, PDUR_CODE) PduR_BufferEnqueue
(
    uint16 BufferId,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info
);

#if(STD_ON == PDUR_GW_TP_SUPPORT)
STATIC FUNC(Std_ReturnType, PDUR_CODE) PduR_BufferDequeue
(
    uint16 BufferId,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info
);
#endif
#endif

#if(STD_ON == PDUR_IF_SUPPORT)
STATIC FUNC(void, PDUR_CODE) PduR_LowerIfRxIndication
(
    CONST(PduR_RoutingPathIdType, PDUR_CONST) PathId,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_CONST) PduInfoPtr
);

STATIC FUNC(void, PDUR_CODE) PduR_LowerIfTxConfirmation
(
    PduR_RoutingPathIdType PathId,
    PduIdType ConfId
);

#if((PDUR_MAX_NUMOFIPDUMIFTXPDU > 0) || (PDUR_MAX_NUMOFLINIFTXPDU > 0) || (PDUR_MAX_NUMOFSOADIFTXPDU > 0) ||  (PDUR_MAX_NUMOFCANNMTXPDU > 0))
STATIC FUNC(Std_ReturnType, PDUR_CODE) PduR_LowerIfTriggerTransmit
(
    PduR_RoutingPathIdType PathId,
    PduIdType ConfId,
    P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) PduInfoPtr
);
#endif

STATIC FUNC(void, PDUR_CODE) PduR_LowerIfMultiRxIndication
(
    P2CONST(PduRRoutingPduInfoType, AUTOMATIC, PDUR_CONST) pRxPduInfo,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_CONST) PduInfoPtr
);
#endif

#if(PDUR_MAX_NUMOFBUFFER > 0)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: PduR_BufferInit
*
* Description:     Init the dedicated buffer
*
* Inputs:         BufferId
*
* Outputs:         None
*
* Limitations:     None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, PDUR_CODE) PduR_BufferInit
(
    uint16 BufferId
)
{
    PduRBufferInfo[BufferId].BufState = PDUR_BUFFER_IDLE;
    PduRBufferInfo[BufferId].TotalLen = 0;
    PduRBufferInfo[BufferId].ValidLen = 0;
    PduRBufferInfo[BufferId].ReceivedLen = 0;
    PduRBufferInfo[BufferId].AvailableLen = PduR_BufferLen[BufferId];
    PduRBufferInfo[BufferId].WritePos = 0;
    PduRBufferInfo[BufferId].ReadPos = 0;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: PduR_BufferEnqueue
*
* Description:     Enqueue the data to the dedicated buffer
*
* Inputs:         BufferId
*                info contain the data and data length
*
* Outputs:         None
*
* Limitations:     None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(Std_ReturnType, PDUR_CODE) PduR_BufferEnqueue
(
    uint16 BufferId,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info
)
{
    Std_ReturnType ret = E_NOT_OK;
    PduLengthType TailDataLen = 0;

    if(PduRBufferInfo[BufferId].AvailableLen >= info->SduLength)
    {
        /*[- - - 0 1 - - -]*/
        TailDataLen = PduR_BufferLen[BufferId] - PduRBufferInfo[BufferId].WritePos;
        if(info->SduLength < TailDataLen)
        {
            /*[- - - 0 1 2 3 -]*/
            Bsw_MemCpy(PduR_Buffer[BufferId] + PduRBufferInfo[BufferId].WritePos, info->SduDataPtr, info->SduLength);
            PduRBufferInfo[BufferId].WritePos += info->SduLength;
        }
        else
        {
            /*[- - - 0 1 2 3 4]*/
            Bsw_MemCpy(PduR_Buffer[BufferId] + PduRBufferInfo[BufferId].WritePos, info->SduDataPtr, TailDataLen);
            /*[5 6 - 0 1 2 3 4]*/
            Bsw_MemCpy(PduR_Buffer[BufferId], info->SduDataPtr + TailDataLen, info->SduLength - TailDataLen);
            PduRBufferInfo[BufferId].WritePos = info->SduLength - TailDataLen;
        }
        PduRBufferInfo[BufferId].ValidLen += info->SduLength;
        PduRBufferInfo[BufferId].AvailableLen -= (info->SduLength);
        PduRBufferInfo[BufferId].ReceivedLen += info->SduLength;
        ret = E_OK;
    }

    return ret;
}

#if(STD_ON == PDUR_GW_TP_SUPPORT)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name:   PduR_BufferDequeue
*
* Description:     Dequeue the data from the dedicated buffer
*
* Inputs:          BufferId
*
* Outputs:         info contain the data and data length
*
* Limitations:     None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(Std_ReturnType, PDUR_CODE) PduR_BufferDequeue
(
    uint16 BufferId,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info
)
{
    Std_ReturnType ret = E_NOT_OK;
    PduLengthType TailDataLen = 0;

    if(PduRBufferInfo[BufferId].ValidLen >= info->SduLength)
    {
        /*[3 4 5 - - 0 1 2]*/
        TailDataLen = PduR_BufferLen[BufferId] - PduRBufferInfo[BufferId].ReadPos;
        if(info->SduLength < TailDataLen)
        {
            /*[1 2 3 - - - - 0]*/
            Bsw_MemCpy(info->SduDataPtr, PduR_Buffer[BufferId] + PduRBufferInfo[BufferId].ReadPos, info->SduLength);
            PduRBufferInfo[BufferId].ReadPos += info->SduLength;
        }
        else
        {
            /*[0 1 2 - - - - -]*/
            Bsw_MemCpy(info->SduDataPtr, PduR_Buffer[BufferId] + PduRBufferInfo[BufferId].ReadPos, TailDataLen);
            /*[- - 0 - - - - -]*/
            Bsw_MemCpy(info->SduDataPtr + TailDataLen, PduR_Buffer[BufferId], info->SduLength - TailDataLen);
            PduRBufferInfo[BufferId].ReadPos = info->SduLength - TailDataLen;
        }
        /*SWS_PduR_00696*/
        PduRBufferInfo[BufferId].ValidLen -= (info->SduLength);
        PduRBufferInfo[BufferId].AvailableLen += (info->SduLength);
        ret = E_OK;
    }

    return ret;
}
#endif
#endif

#if(STD_ON == PDUR_IF_SUPPORT)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: PduR_LowerIfRxIndication
*
* Description:   RxIndication processing of lower interface module
*
* Inputs:        PathId id of the routing path
*                PduInfoPtr Data info of received data
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, PDUR_CODE) PduR_LowerIfRxIndication
(
    CONST(PduR_RoutingPathIdType, PDUR_CONST) PathId,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_CONST) PduInfoPtr
)
{
    PduIdType DestPduId = PDUR_ROUTINGPATHINFO(PathId).PduRDestPdu.PduRDestPduId;
    PduRModuleType DestModuleType = PDUR_ROUTINGPATHINFO(PathId).PduRDestPdu.PduRDestModuleType;
#if(STD_ON == PDUR_GW_IF_SUPPORT)
    uint16 BufferId = PDUR_ROUTINGPATHINFO(PathId).PduRDestPdu.PduRDestTxBufferId;
#endif

    if(NULL_PTR != PduR_ModuleFunctions[DestModuleType].UpIfRxIndicationFunc)
    {
        /*Up modules*/
        /*SWS_PduR_00621 SWS_PduR_00744*/
        PduR_ModuleFunctions[DestModuleType].UpIfRxIndicationFunc(DestPduId, PduInfoPtr);
    }
#if(STD_ON == PDUR_GW_IF_SUPPORT)
    else if(NULL_PTR != PduR_ModuleFunctions[DestModuleType].IfTransmitFunc)
    {
#if(PDUR_MAX_NUMOFBUFFER > 0)
        /*Interface modules*/
        if(PDUR_UNUSED != BufferId)
        {
            /*TRIGGERTRANSMIT such as LinIf*/
            /*SWS_PduR_00306 SWS_PDUR_00809 SWS_PduR_00746 SWS_PduR_00786 SWS_PduR_00787 SWS_PduR_00255*/
            /*always save fresh data*/
            PduR_BufferInit(BufferId);
            if(E_OK == PduR_BufferEnqueue(BufferId, PduInfoPtr))
            {
                /*SWS_PduR_00256 SWS_PduR_00788 */
                (void)PduR_ModuleFunctions[DestModuleType].IfTransmitFunc(DestPduId, PduInfoPtr);
            }
        }
        else
#endif
        {
            /*DIRECT*/
            /*SWS_PduR_00303 SWS_PduR_00783 SWS_PduR_00665 SWS_PduR_00256 SWS_PduR_00788*/
            (void)PduR_ModuleFunctions[DestModuleType].IfTransmitFunc(DestPduId, PduInfoPtr);
        }
    }
#endif
    else
    {
    }

}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: PduR_LowerIfTxConfirmation
*
* Description:     This function is called by the communication interface module to
*                 confirm the transmit data of an I-PDU.
*
* Inputs:         PathId   Identification of the transmitted path.
*                 ConfId Identification passed to up layer.
*
* Outputs:         None
*
* Limitations:     None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, PDUR_CODE) PduR_LowerIfTxConfirmation
(
    PduR_RoutingPathIdType PathId,
    PduIdType ConfId
)
{
    PduR_MulticastMaskType mask = PDUR_ROUTINGPATHINFO(PathId).ConfMask;
    PduRModuleType SrcModuleType = PDUR_ROUTINGPATHINFO(PathId).PduRSrcPdu.PduRSrcModuleType;
    PduIdType SrcPduId = PDUR_ROUTINGPATHINFO(PathId).PduRSrcPdu.PduRSrcPduHandleId;
    P2VAR(PduR_MulticastMaskType, AUTOMATIC, PDUR_VAR) pTxConfMask = NULL_PTR;
    P2VAR(PduR_MulticastMaskType, AUTOMATIC, PDUR_VAR) pTxErrorMask = NULL_PTR;

#if(STD_ON == PDUR_COM_MODULE_SUPPORT)
#if(PDUR_MAX_NUMOFCOMTXPDU > 0)
    if(MODULE_COM == SrcModuleType)
    {
        pTxConfMask = ComTxConfMask;
        pTxErrorMask = ComTxErrorMask;
    }
#endif
#endif
#if(STD_ON == PDUR_LDCOM_MODULE_SUPPORT)
#if(PDUR_MAX_NUMOFLDCOMTXPDU > 0)
    if(MODULE_LDCOM == SrcModuleType)
    {
        pTxConfMask = LdComTxConfMask;
        pTxErrorMask = LdComTxErrorMask;
    }
#endif
#endif
#if(STD_ON == PDUR_DCM_MODULE_SUPPORT)
#if(PDUR_MAX_NUMOFDCMTXPDU > 0)
    if(MODULE_DCM == SrcModuleType)
    {
        pTxConfMask = DcmTxConfMask;
        pTxErrorMask = DcmTxErrorMask;
    }
#endif
#endif
#if(STD_ON == PDUR_J1939DCM_MODULE_SUPPORT)
#if(PDUR_MAX_NUMOFJ1939DCMTXPDU > 0)
    if(MODULE_J1939DCM == SrcModuleType)
    {
        pTxConfMask = J1939DcmTxConfMask;
        pTxErrorMask = J1939DcmTxErrorMask;
    }
#endif
#endif
#if(STD_ON == PDUR_J1939RM_MODULE_SUPPORT)
#if(PDUR_MAX_NUMOFJ1939RMTXPDU > 0)
    if(MODULE_J1939RM == SrcModuleType)
    {
        pTxConfMask = J1939RmTxConfMask;
        pTxErrorMask = J1939RmTxErrorMask;
    }
#endif
#endif
#if(STD_ON == PDUR_CDD_MODULE_SUPPORT)
#if(PDUR_MAX_NUMOFCDDTXPDU > 0)
    if(MODULE_CDD == SrcModuleType)
    {
        pTxConfMask = CddTxConfMask;
        pTxErrorMask = CddTxErrorMask;
    }
#endif
#endif
#if(STD_ON == PDUR_IPDUM_MODULE_SUPPORT)
#if(PDUR_MAX_NUMOFIPDUMTXPDU > 0)
    if(MODULE_IPDUM == SrcModuleType)
    {
        pTxConfMask = IpduMTxConfMask;
        pTxErrorMask = IpduMTxErrorMask;
    }
#endif
#endif
#if(STD_ON == PDUR_SOMEIP_MODULE_SUPPORT)
#if(PDUR_MAX_NUMOFSOMEIPTXPDU > 0)
    if(MODULE_SOMEIP == SrcModuleType)
    {
        pTxConfMask = SomeIpTxConfMask;
        pTxErrorMask = SomeIpTxErrorMask;
    }
#endif
#endif
#if(STD_ON == PDUR_SECOC_MODULE_SUPPORT)
#if(PDUR_MAX_NUMOFSECOCTXPDU > 0)
    if(MODULE_SECOC == SrcModuleType)
    {
        pTxConfMask = SecOCTxConfMask;
        pTxErrorMask = SecOCTxErrorMask;
    }
#endif
#endif

    if(NULL_PTR != PduR_ModuleFunctions[SrcModuleType].UpIfTxConfirmationFunc)
    {
        /*Up module*/
        if((NULL_PTR != pTxConfMask) && (NULL_PTR != pTxErrorMask))
        {
            if(pTxErrorMask[SrcPduId] == pTxConfMask[SrcPduId])
            {
                /*The first valid TxConfirmation*/
                /*SWS_PduR_00589 SWS_PduR_00627*/
                PduR_ModuleFunctions[SrcModuleType].UpIfTxConfirmationFunc(ConfId);
            }
            pTxConfMask[SrcPduId] |= mask;
            /*Ignore other TxConfirmations*/
        }
    }
#if(STD_ON == PDUR_GW_IF_SUPPORT)
    else
    {
        /*ignore this TxConfirmations*/
        /*SWS_PduR_00640*/
    }
#endif

}

#if((PDUR_MAX_NUMOFIPDUMIFTXPDU > 0) || (PDUR_MAX_NUMOFLINIFTXPDU > 0) || (PDUR_MAX_NUMOFSOADIFTXPDU > 0) ||  (PDUR_MAX_NUMOFCANNMTXPDU > 0))
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: PduR_LowerIfTriggerTransmit
*
* Description:     This function is called by the communication interface module to
*                 confirm the transmit data of an I-PDU.
*
* Inputs:         PathId   Identification of the transmitted path.
*                 ConfId Identification passed to up layer.
*
* Outputs:         None
*
* Limitations:     None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(Std_ReturnType, PDUR_CODE) PduR_LowerIfTriggerTransmit
(
    PduR_RoutingPathIdType PathId,
    PduIdType ConfId,
    P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) PduInfoPtr
)
{
    Std_ReturnType ret = E_NOT_OK;
    PduR_MulticastMaskType mask = PDUR_ROUTINGPATHINFO(PathId).ConfMask;
    PduRModuleType SrcModuleType = PDUR_ROUTINGPATHINFO(PathId).PduRSrcPdu.PduRSrcModuleType;
    PduIdType SrcPduId = PDUR_ROUTINGPATHINFO(PathId).PduRSrcPdu.PduRSrcPduHandleId;
#if(STD_ON == PDUR_GW_IF_SUPPORT)
    uint16 BufferId = PDUR_ROUTINGPATHINFO(PathId).PduRDestPdu.PduRDestTxBufferId;
#endif
    P2VAR(PduR_MulticastMaskType, AUTOMATIC, PDUR_VAR) pTxConfMask = NULL_PTR;
    P2VAR(PduR_MulticastMaskType, AUTOMATIC, PDUR_VAR) pTxErrorMask = NULL_PTR;

#if(STD_ON == PDUR_COM_MODULE_SUPPORT)
#if(PDUR_MAX_NUMOFCOMTXPDU > 0)
    if(MODULE_COM == SrcModuleType)
    {
        pTxConfMask = ComTxConfMask;
        pTxErrorMask = ComTxErrorMask;
    }
#endif
#endif
#if(STD_ON == PDUR_LDCOM_MODULE_SUPPORT)
#if(PDUR_MAX_NUMOFLDCOMTXPDU > 0)
    if(MODULE_LDCOM == SrcModuleType)
    {
        pTxConfMask = LdComTxConfMask;
        pTxErrorMask = LdComTxErrorMask;
    }
#endif
#endif
#if(STD_ON == PDUR_DCM_MODULE_SUPPORT)
#if(PDUR_MAX_NUMOFDCMTXPDU > 0)
    if(MODULE_DCM == SrcModuleType)
    {
        pTxConfMask = DcmTxConfMask;
        pTxErrorMask = DcmTxErrorMask;
    }
#endif
#endif
#if(STD_ON == PDUR_CDD_MODULE_SUPPORT)
#if(PDUR_MAX_NUMOFCDDTXPDU > 0)
    if(MODULE_CDD == SrcModuleType)
    {
        pTxConfMask = CddTxConfMask;
        pTxErrorMask = CddTxErrorMask;
    }
#endif
#endif
#if(STD_ON == PDUR_IPDUM_MODULE_SUPPORT)
#if(PDUR_MAX_NUMOFIPDUMTXPDU > 0)
    if(MODULE_IPDUM == SrcModuleType)
    {
        pTxConfMask = IpduMTxConfMask;
        pTxErrorMask = IpduMTxErrorMask;
    }
#endif
#endif
#if(STD_ON == PDUR_SOMEIP_MODULE_SUPPORT)
#if(PDUR_MAX_NUMOFSOMEIPTXPDU > 0)
    if(MODULE_SOMEIP == SrcModuleType)
    {
        pTxConfMask = SomeIpTxConfMask;
        pTxErrorMask = SomeIpTxErrorMask;
    }
#endif
#endif
#if(STD_ON == PDUR_SECOC_MODULE_SUPPORT)
#if(PDUR_MAX_NUMOFSECOCTXPDU > 0)
    if(MODULE_SECOC == SrcModuleType)
    {
        pTxConfMask = SecOCTxConfMask;
        pTxErrorMask = SecOCTxErrorMask;
    }
#endif
#endif

    if(NULL_PTR != PduR_ModuleFunctions[SrcModuleType].UpIfTriggerTransmitFunc)
    {
        if((NULL_PTR != pTxConfMask) && (NULL_PTR != pTxErrorMask))
        {
            pTxConfMask[SrcPduId] &= ~mask;
            pTxErrorMask[SrcPduId] &= ~mask;
        }
        /*SWS_PduR_00430 SWS_PduR_00661*/
        ret = PduR_ModuleFunctions[SrcModuleType].UpIfTriggerTransmitFunc(ConfId, PduInfoPtr);
        if(E_OK != ret)
        {
            pTxConfMask[SrcPduId] |= mask;
            pTxErrorMask[SrcPduId] |= mask;
        }
    }
#if(STD_ON == PDUR_GW_IF_SUPPORT)
#if(PDUR_MAX_NUMOFBUFFER > 0)
    else if(PDUR_UNUSED != BufferId)
    {
        /*GW, Copy Txbuff to PduInfoPtr*/
        /*SWS_PduR_00306 SWS_PDUR_00819*/
        /*check whether the valid data fits into PduInfoPtr->SduLength*/
        if(PduRBufferInfo[BufferId].ValidLen <= PduInfoPtr->SduLength)
        {
            /*Do not remove data after copy*/
            /*SWS_PduR_00666 SWS_PduR_00667*/
            Bsw_MemCpy(PduInfoPtr->SduDataPtr, PduR_Buffer[BufferId], PduRBufferInfo[BufferId].ValidLen);
            PduInfoPtr->SduLength = PduRBufferInfo[BufferId].ValidLen;
            ret = E_OK;
        }
        else
        {
            /*SWS_PduR_00662*/
            ret = E_NOT_OK;
        }
    }
#endif
#endif
    else
    {
    }
    return ret;
}
#endif

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: PduR_LowerIfMultiRxIndication
*
* Description:   RxIndication processing of lower interface module
*
* Inputs:        PathId id of the routing path
*                PduInfoPtr Data info of received data
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, PDUR_CODE) PduR_LowerIfMultiRxIndication
(
    P2CONST(PduRRoutingPduInfoType, AUTOMATIC, PDUR_CONST) pRxPduInfo,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_CONST) PduInfoPtr
)
{
    PduR_RoutingPathIdType i;
    PduR_RoutingPathIdType PathId;
    PduR_RoutingPathGroupIdType GroupId;

    /*SWS_PduR_00164*/
    for(i = (PduR_RoutingPathIdType)0; i < pRxPduInfo->NumPaths; i++)
    {
        PathId = pRxPduInfo->PathIdx[i];
        GroupId = PDUR_ROUTINGPATHINFO(PathId).PduRDestPdu.PduRRoutingGroup;

        /*SWS_PduR_00726*/
        if((PDUR_RPGROUP_NONE == GroupId) || (TRUE == PduR_RoutingPathGroupEnabled[GroupId]))
        {
            PduR_LowerIfRxIndication(PathId, PduInfoPtr);
        }
    }
}
#endif
#define PDUR_STOP_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
*  PUBLIC Functions define
*******************************************************************************/
#define PDUR_START_SEC_CODE
#include "MemMap.h"

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: PduR_UpTransmit
*
* Description:   Transmit of up module
*
* Inputs:        idx id of the routing path
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, PDUR_CODE) PduR_UpTransmit
(
    CONST(PduR_RoutingPathIdType, PDUR_CONST) PathId,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_CONST) info
)
{
    Std_ReturnType ret = E_NOT_OK;
    PduIdType DestPduId = PDUR_ROUTINGPATHINFO(PathId).PduRDestPdu.PduRDestPduId;
    PduR_RoutingPathGroupIdType GroupId = PDUR_ROUTINGPATHINFO(PathId).PduRDestPdu.PduRRoutingGroup;
    PduRModuleType DestModuleType = PDUR_ROUTINGPATHINFO(PathId).PduRDestPdu.PduRDestModuleType;

    /*SWS_PduR_00629 SWS_PduR_00745 SWS_PduR_00717*/
    if((PDUR_RPGROUP_NONE == GroupId) || (TRUE == PduR_RoutingPathGroupEnabled[GroupId]))
    {
        if(NULL_PTR != PduR_ModuleFunctions[DestModuleType].IfTransmitFunc)
        {
            /*Interface module*/
            /*SWS_PduR_00625 SWS_PduR_00626 SWS_PduR_00432*/
            ret = PduR_ModuleFunctions[DestModuleType].IfTransmitFunc(DestPduId, info);
        }
        else if(NULL_PTR != PduR_ModuleFunctions[DestModuleType].TpTransmitFunc)
        {
            /*Tp module*/
            /*SWS_PduR_00634*/
            ret = PduR_ModuleFunctions[DestModuleType].TpTransmitFunc(DestPduId, info);
        }
        else
        {
            /* Intentionally Empty */
        }
    }

    return ret;
}

#if(STD_ON == PDUR_CANCEL_TRANSMIT_ENABLED)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: PduR_UpCancelTransmit
*
* Description:   CancelTransmit of up module
*
* Inputs:        idx id of the routing path
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(Std_ReturnType, PDUR_CODE) PduR_UpCancelTransmit
(
    CONST(PduR_RoutingPathIdType, PDUR_CONST) PathId
)
{
    Std_ReturnType ret = E_NOT_OK;
    PduIdType DstPduId = PDUR_ROUTINGPATHINFO(PathId).PduRDestPdu.PduRDestPduId;
    PduR_RoutingPathGroupIdType GroupId = PDUR_ROUTINGPATHINFO(PathId).PduRDestPdu.PduRRoutingGroup;
    PduRModuleType DestModuleType = PDUR_ROUTINGPATHINFO(PathId).PduRDestPdu.PduRDestModuleType;

    /*SWS_PduR_00710 SWS_PduR_00717*/
    if((PDUR_RPGROUP_NONE == GroupId) || (TRUE == PduR_RoutingPathGroupEnabled[GroupId]))
    {
        if(NULL_PTR != PduR_ModuleFunctions[DestModuleType].IfCancelTransmitFunc)
        {
            /*Interface module*/
            /*SWS_PduR_00721 SWS_PduR_00723 SWS_PduR_00700*/
            ret = PduR_ModuleFunctions[DestModuleType].IfCancelTransmitFunc(DstPduId);
        }
        else if(NULL_PTR != PduR_ModuleFunctions[DestModuleType].TpCancelTransmitFunc)
        {
            /*Tp module*/
            /*SWS_PduR_00722 SWS_PduR_00724*/
            ret = PduR_ModuleFunctions[DestModuleType].TpCancelTransmitFunc(DstPduId);
        }
        else
        {
            /* Intentionally Empty */
        }
    }

    return ret;
}
#endif

#if(STD_ON == PDUR_CHANGEPARAMETER_API_ENABLED)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: PduR_UpChangeParameter
*
* Description:   ChangeParameter of up module
*
* Inputs:        idx id of the routing path
*                parameter which parameter is to be changed
*                value what value changed to
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(Std_ReturnType, PDUR_CODE) PduR_UpChangeParameter
(
    CONST(PduR_RoutingPathIdType, PDUR_CONST) PathId,
    TPParameterType parameter,
    uint16 value
)
{
    Std_ReturnType ret = E_NOT_OK;

    /*Tp ChangeParameter id same as rx id*/
    PduIdType SrcPduId = PDUR_ROUTINGPATHINFO(PathId).PduRSrcPdu.PduRSrcPduHandleId;
    PduR_RoutingPathGroupIdType GroupId = PDUR_ROUTINGPATHINFO(PathId).PduRDestPdu.PduRRoutingGroup;
    PduRModuleType SrcModuleType = PDUR_ROUTINGPATHINFO(PathId).PduRSrcPdu.PduRSrcModuleType;

    /*SWS_PduR_00717*/
    if((PDUR_RPGROUP_NONE == GroupId) || (TRUE == PduR_RoutingPathGroupEnabled[GroupId]))
    {
        if(NULL_PTR != PduR_ModuleFunctions[SrcModuleType].TpChangeParameterFunc)
        {
            /*SWS_PduR_00733 SWS_PduR_00734*/
            ret = PduR_ModuleFunctions[SrcModuleType].TpChangeParameterFunc(SrcPduId, parameter, value);
        }
    }
    return ret;
}
#endif

#if(STD_ON == PDUR_CANCEL_RECEIVE_ENABLED)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: PduR_UpCancelReceive
*
* Description:   CancelReceive of up module
*
* Inputs:        idx id of the routing path
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(Std_ReturnType, PDUR_CODE) PduR_UpCancelReceive
(
    CONST(PduR_RoutingPathIdType, PDUR_CONST) PathId
)
{
    Std_ReturnType ret = E_NOT_OK;

    /*Tp CancelReceive id same as rx id*/
    PduIdType SrcPduId = PDUR_ROUTINGPATHINFO(PathId).PduRSrcPdu.PduRSrcPduHandleId;
    PduR_RoutingPathGroupIdType GroupId = PDUR_ROUTINGPATHINFO(PathId).PduRDestPdu.PduRRoutingGroup;
    PduRModuleType SrcModuleType = PDUR_ROUTINGPATHINFO(PathId).PduRSrcPdu.PduRSrcModuleType;

    /*SWS_PduR_00726 SWS_PduR_00717*/
    if((PDUR_RPGROUP_NONE == GroupId) || (TRUE == PduR_RoutingPathGroupEnabled[GroupId]))
    {
        if(NULL_PTR != PduR_ModuleFunctions[SrcModuleType].TpCancelReceiveFunc)
        {
            /*SWS_PduR_00727 SWS_PduR_00732*/
            ret = PduR_ModuleFunctions[SrcModuleType].TpCancelReceiveFunc(SrcPduId);
        }
    }

    return ret;
}
#endif


#if(STD_ON == PDUR_TP_SUPPORT)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: PduR_LowerTpStartOfReception
*
* Description:   StartOfReception processing of lower Tp module
*
* Inputs:        PathId id of the routing path
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(BufReq_ReturnType, PDUR_CODE) PduR_LowerTpStartOfReception
(
    PduR_RoutingPathIdType PathId,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info,
    PduLengthType TpSduLength,
    P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) bufferSizePtr
)
{
    BufReq_ReturnType result = BUFREQ_E_NOT_OK;
    PduRModuleType DestModuleType = PDUR_ROUTINGPATHINFO(PathId).PduRDestPdu.PduRDestModuleType;
    PduIdType DestPduId = PDUR_ROUTINGPATHINFO(PathId).PduRDestPdu.PduRDestPduId;
#if(STD_ON == PDUR_GW_TP_SUPPORT)
    uint16 BufferId = PDUR_ROUTINGPATHINFO(PathId).PduRDestPdu.PduRDestTxBufferId;
    uint16 PduRTpThreshold = PDUR_ROUTINGPATHINFO(PathId).PduRDestPdu.PduRTpThreshold;
    PduInfoType TxPduInfo;
#endif

    if(NULL_PTR != PduR_ModuleFunctions[DestModuleType].UpTpStartOfReceptionFunc)
    {
        /*Up modules*/
        /*SWS_PduR_00549 SWS_PduR_00623*/
        result = PduR_ModuleFunctions[DestModuleType].UpTpStartOfReceptionFunc(DestPduId, info, TpSduLength, bufferSizePtr);
    }
#if(STD_ON == PDUR_GW_TP_SUPPORT)
#if(PDUR_MAX_NUMOFBUFFER > 0)
    else if(PDUR_UNUSED != BufferId)
    {
        /*Tp modules*/
        if(PDUR_BUFFER_IDLE == PduRBufferInfo[BufferId].BufState)
        {
            if(PduRBufferInfo[BufferId].AvailableLen < info->SduLength)
            {
                /*SWS_PduR_00799*/
                result = BUFREQ_E_OVFL;
            }
            else
            {
                if(0 == PduRTpThreshold)
                {
                    /*SWS_PDUR_00811*/
                    PduRBufferInfo[BufferId].TotalLen = TpSduLength;
                    TxPduInfo.SduLength = PduRBufferInfo[BufferId].TotalLen;
                    /*!!!CAUTION!!! TpTransmitFunc must not read data for now*/
                    TxPduInfo.SduDataPtr = PduR_Buffer[BufferId] + PduRBufferInfo[BufferId].ReadPos;
                    if(E_OK == PduR_ModuleFunctions[DestModuleType].TpTransmitFunc(DestPduId, &TxPduInfo))
                    {
                        *bufferSizePtr = PduRBufferInfo[BufferId].AvailableLen;
                        PduRBufferInfo[BufferId].BufState = PDUR_BUFFER_RECEIVING | PDUR_BUFFER_TRANSMITING;
                        result = BUFREQ_OK;
                    }
                    else
                    {
                        PduR_BufferInit(BufferId);
                    }
                }
                else
                {
                    /*SWS_PDUR_00818*/
                    PduRBufferInfo[BufferId].TotalLen = TpSduLength;
                    *bufferSizePtr = PduRBufferInfo[BufferId].AvailableLen;
                    PduRBufferInfo[BufferId].BufState = PDUR_BUFFER_RECEIVING;
                    result = BUFREQ_OK;
                }
            }
        }
    }
#endif
#endif
    else
    {
        /* Intentionally Empty */
    }

    return result;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: PduR_LowerTpCopyRxData
*
* Description:   CopyRxData processing of lower Tp module
*
* Inputs:        PathId id of the routing path
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(BufReq_ReturnType, PDUR_CODE) PduR_LowerTpCopyRxData
(
    PduR_RoutingPathIdType PathId,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info,
    P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) bufferSizePtr
)
{
    BufReq_ReturnType result = BUFREQ_E_NOT_OK;
    PduRModuleType DestModuleType = PDUR_ROUTINGPATHINFO(PathId).PduRDestPdu.PduRDestModuleType;
    PduIdType DestPduId = PDUR_ROUTINGPATHINFO(PathId).PduRDestPdu.PduRDestPduId;
#if(STD_ON == PDUR_GW_TP_SUPPORT)
    uint16 BufferId = PDUR_ROUTINGPATHINFO(PathId).PduRDestPdu.PduRDestTxBufferId;
    uint16 PduRTpThreshold = PDUR_ROUTINGPATHINFO(PathId).PduRDestPdu.PduRTpThreshold;
    PduInfoType TxPduInfo;
#endif

    if(NULL_PTR != PduR_ModuleFunctions[DestModuleType].UpTpCopyRxDataFunc)
    {
        /*Up modules*/
        /*SWS_PduR_00428*/
        result = PduR_ModuleFunctions[DestModuleType].UpTpCopyRxDataFunc(DestPduId, info, bufferSizePtr);
    }
#if(STD_ON == PDUR_GW_TP_SUPPORT)
#if(PDUR_MAX_NUMOFBUFFER > 0)
    else if(PDUR_UNUSED != BufferId)
    {
        /*GW*/
        if(0 != (PduRBufferInfo[BufferId].BufState & PDUR_BUFFER_RECEIVING))
        {
            if(0 == info->SduLength)
            {
                /*SWS_PduR_00740*/
                *bufferSizePtr = PduRBufferInfo[BufferId].AvailableLen;
                result = BUFREQ_OK;
            }
            else
            {
                /*SWS_PduR_00793*/
                if(E_OK != PduR_BufferEnqueue(BufferId, info))
                {
                    /*Cancel transport*/
                    /*SWS_PduR_00687*/
                    PduR_BufferInit(BufferId);
                }
                else
                {
                    *bufferSizePtr = PduRBufferInfo[BufferId].AvailableLen;

                    if((PduRBufferInfo[BufferId].ReceivedLen >= PduRTpThreshold)
                            && ((PduRBufferInfo[BufferId].ReceivedLen - info->SduLength) < PduRTpThreshold))
                    {
                        /*First time getting above the threshold*/
                        /*SWS_PduR_00317*/
                        TxPduInfo.SduLength = PduRBufferInfo[BufferId].TotalLen;
                        /*!!!CAUTION!!! TpTransmitFunc must not read data for now*/
                        TxPduInfo.SduDataPtr = PduR_Buffer[BufferId] + PduRBufferInfo[BufferId].ReadPos;
                        if(E_OK == PduR_ModuleFunctions[DestModuleType].TpTransmitFunc(DestPduId, &TxPduInfo))
                        {
                            PduRBufferInfo[BufferId].BufState |= PDUR_BUFFER_TRANSMITING;
                            result = BUFREQ_OK;
                        }
                        else
                        {
                            PduR_BufferInit(BufferId);
                        }
                    }
                    else
                    {
                        result = BUFREQ_OK;
                    }
                }
            }

        }
    }
#endif
#endif
    else
    {
        /* Intentionally Empty */
    }

    return result;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: PduR_LowerTpRxIndication
*
* Description:   RxIndication processing of lower Tp module
*
* Inputs:        PathId id of the routing path
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, PDUR_CODE) PduR_LowerTpRxIndication
(
    PduR_RoutingPathIdType PathId,
    Std_ReturnType result
)
{
    PduRModuleType DestModuleType = PDUR_ROUTINGPATHINFO(PathId).PduRDestPdu.PduRDestModuleType;
    PduIdType DestPduId = PDUR_ROUTINGPATHINFO(PathId).PduRDestPdu.PduRDestPduId;
#if(STD_ON == PDUR_GW_TP_SUPPORT)
    uint16 BufferId = PDUR_ROUTINGPATHINFO(PathId).PduRDestPdu.PduRDestTxBufferId;
    uint16 PduRTpThreshold = PDUR_ROUTINGPATHINFO(PathId).PduRDestPdu.PduRTpThreshold;
    PduInfoType TxPduInfo;
#endif

    if(NULL_PTR != PduR_ModuleFunctions[DestModuleType].UpTpRxIndicationFunc)
    {
        /*Up modules*/
        /*SWS_PduR_00429 SWS_PduR_00207*/
        PduR_ModuleFunctions[DestModuleType].UpTpRxIndicationFunc(DestPduId, result);
    }
#if(STD_ON == PDUR_GW_TP_SUPPORT)
#if(PDUR_MAX_NUMOFBUFFER > 0)
    else if(PDUR_UNUSED != BufferId)
    {
        /*GW*/
        if(result == E_OK)
        {
            if(0 != (PduRBufferInfo[BufferId].BufState & PDUR_BUFFER_RECEIVING))
            {
                /*Clear receiving flag*/
                PduRBufferInfo[BufferId].BufState &= ~PDUR_BUFFER_RECEIVING;

                if(PduRBufferInfo[BufferId].ReceivedLen < PduRTpThreshold)
                {
                    /*Never getting above the threshold before, start now*/
                    /*SWS_PDUR_00808*/
                    TxPduInfo.SduLength = PduRBufferInfo[BufferId].ValidLen;
                    /*!!!CAUTION!!! TpTransmitFunc must not read data for now*/
                    TxPduInfo.SduDataPtr = PduR_Buffer[BufferId] + PduRBufferInfo[BufferId].ReadPos;
                    if(E_OK == PduR_ModuleFunctions[DestModuleType].TpTransmitFunc(DestPduId, &TxPduInfo))
                    {
                        PduRBufferInfo[BufferId].BufState |= PDUR_BUFFER_TRANSMITING;
                    }
                    else
                    {
                        PduR_BufferInit(BufferId);
                    }
                }
            }

        }
        else/* Rx not OK*/
        {
            /*SWS_PduR_00689*/
            PduR_BufferInit(BufferId);
        }
    }
#endif
#endif
    else
    {
        /* Intentionally Empty */
    }

}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: PduR_LowerTpCopyTxData
*
* Description:   CopyTxData of lower tp module
*
* Inputs:        pRoutPath pointer to the routing path
*                info infomation of rx pdu
*
* Outputs:       availableDataPtr pointer to buffersize
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(BufReq_ReturnType, PDUR_CODE) PduR_LowerTpCopyTxData
(
    PduR_RoutingPathIdType PathId,
    PduIdType ConfId,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info,
    P2VAR(RetryInfoType, AUTOMATIC, PDUR_APPL_DATA) retry,
    P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) availableDataPtr
)
{
    BufReq_ReturnType result = BUFREQ_E_NOT_OK;
    PduR_MulticastMaskType mask = PDUR_ROUTINGPATHINFO(PathId).ConfMask;
    RetryInfoType PduRRetry;
    PduRModuleType SrcModuleType = PDUR_ROUTINGPATHINFO(PathId).PduRSrcPdu.PduRSrcModuleType;
    PduIdType TxPduId = PDUR_ROUTINGPATHINFO(PathId).PduRSrcPdu.PduRSrcPduHandleId;
    P2VAR(PduR_MulticastMaskType, AUTOMATIC, PDUR_VAR) pTxConfMask = NULL_PTR;
    P2VAR(PduR_MulticastMaskType, AUTOMATIC, PDUR_VAR) pTxErrorMask = NULL_PTR;
    PduR_MulticastMaskType CopyFinishMask;
#if(STD_ON == PDUR_GW_TP_SUPPORT)
    uint16 BufferId = PDUR_ROUTINGPATHINFO(PathId).PduRDestPdu.PduRDestTxBufferId;
#endif
    (void)retry;

#if(STD_ON == PDUR_COM_MODULE_SUPPORT)
#if(PDUR_MAX_NUMOFCOMTXPDU > 0)
    if(MODULE_COM == SrcModuleType)
    {
        pTxConfMask = ComTxConfMask;
        pTxErrorMask = ComTxErrorMask;
        CopyFinishMask = PDUR_COM_TXPDUINFO(TxPduId).ConfMask;
    }
#endif
#endif
#if(STD_ON == PDUR_LDCOM_MODULE_SUPPORT)
#if(PDUR_MAX_NUMOFLDCOMTXPDU > 0)
    if(MODULE_LDCOM == SrcModuleType)
    {
        pTxConfMask = LdComTxConfMask;
        pTxErrorMask = LdComTxErrorMask;
        CopyFinishMask = PDUR_LDCOM_TXPDUINFO(TxPduId).ConfMask;
    }
#endif
#endif
#if(STD_ON == PDUR_DCM_MODULE_SUPPORT)
#if(PDUR_MAX_NUMOFDCMTXPDU > 0)
    if(MODULE_DCM == SrcModuleType)
    {
        pTxConfMask = DcmTxConfMask;
        pTxErrorMask = DcmTxErrorMask;
        CopyFinishMask = PDUR_DCM_TXPDUINFO(TxPduId).ConfMask;
    }
#endif
#endif
#if(STD_ON == PDUR_J1939DCM_MODULE_SUPPORT)
#if(PDUR_MAX_NUMOFJ1939DCMTXPDU > 0)
    if(MODULE_J1939DCM == SrcModuleType)
    {
        pTxConfMask = J1939DcmTxConfMask;
        pTxErrorMask = J1939DcmTxErrorMask;
        CopyFinishMask = PDUR_J1939DCM_TXPDUINFO(TxPduId).ConfMask;
    }
#endif
#endif
#if(STD_ON == PDUR_CDD_MODULE_SUPPORT)
#if(PDUR_MAX_NUMOFCDDTXPDU > 0)
    if(MODULE_CDD == SrcModuleType)
    {
        pTxConfMask = CddTxConfMask;
        pTxErrorMask = CddTxErrorMask;
        CopyFinishMask = PDUR_CDD_TXPDUINFO(TxPduId).ConfMask;
    }
#endif
#endif
#if(STD_ON == PDUR_SECOC_MODULE_SUPPORT)
#if(PDUR_MAX_NUMOFSECOCTXPDU > 0)
    if(MODULE_SECOC == SrcModuleType)
    {
        pTxConfMask = SecOCTxConfMask;
        pTxErrorMask = SecOCTxErrorMask;
        CopyFinishMask = PDUR_SECOC_TXPDUINFO(TxPduId).ConfMask;
    }
#endif
#endif

    if(NULL_PTR != PduR_ModuleFunctions[SrcModuleType].UpTpCopyTxDataFunc)
    {
        /*Up module*/
        if((NULL_PTR != pTxConfMask) && (NULL_PTR != pTxErrorMask))
        {
            if(0 != (pTxConfMask[TxPduId] & mask))
            {
                /*already copied or error occurred*/
                result = BUFREQ_E_NOT_OK;
            }
            else
            {
                if(pTxErrorMask[TxPduId] == pTxConfMask[TxPduId])
                {
                    /*First copy*/
                    /*SWS_PduR_00631*/
                    PduRRetry.TpDataState = TP_CONFPENDING;
                }
                else
                {
                    /*Assume that every copy use the same SduLength*/
                    /*SWS_PduR_00632*/
                    PduRRetry.TpDataState = TP_DATARETRY;
                    PduRRetry.TxTpDataCnt = info->SduLength;
                }

                pTxConfMask[TxPduId] |= mask;
                if(pTxConfMask[TxPduId] == CopyFinishMask)
                {
                    /*The last copy*/
                    PduRRetry.TpDataState = TP_DATACONF;
                }
                /*SWS_PduR_00299 SWS_PduR_00676*/
                result = PduR_ModuleFunctions[SrcModuleType].UpTpCopyTxDataFunc(ConfId, info, &PduRRetry, availableDataPtr);
                if(BUFREQ_OK != result)
                {
                    /*Record this error, and not processing this path any more*/
                    pTxErrorMask[TxPduId] |= mask;
                }

                /*The last copy of this piece of data, clear successed paths*/
                if(pTxConfMask[TxPduId] == CopyFinishMask)
                {
                    pTxConfMask[TxPduId] = pTxErrorMask[TxPduId];
                }
            }
        }
    }
#if(STD_ON == PDUR_GW_TP_SUPPORT)
#if(PDUR_MAX_NUMOFBUFFER > 0)
    else if(PDUR_UNUSED != BufferId)
    {
        /*SWS_PduR_00707 SWS_PduR_00696*/
        if(0 != (PduRBufferInfo[BufferId].BufState & PDUR_BUFFER_TRANSMITING))
        {
            if(E_OK == PduR_BufferDequeue(BufferId, info))
            {
                result = BUFREQ_OK;
            }
            else
            {
                /*SWS_PduR_00697*//*SWS_PDUR_00814*/
                result = BUFREQ_E_BUSY;
            }
            *availableDataPtr = PduRBufferInfo[BufferId].ValidLen;
        }
        else
        {
            PduR_BufferInit(BufferId);
            result = BUFREQ_E_NOT_OK;
        }
    }
#endif
#endif
    else
    {
        /* Intentionally Empty */
    }

    return result;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: PduR_LowerTpTxConfirmation
*
* Description:   TxConfirmation of lower tp module
*
* Inputs:        pRoutPath pointer to the routing path
*                info infomation of rx pdu
*
* Outputs:       availableDataPtr pointer to buffersize
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, PDUR_CODE) PduR_LowerTpTxConfirmation
(
    PduR_RoutingPathIdType PathId,
    PduIdType ConfId,
    Std_ReturnType Result
)
{
    PduR_MulticastMaskType mask = PDUR_ROUTINGPATHINFO(PathId).ConfMask;
    PduRModuleType SrcModuleType = PDUR_ROUTINGPATHINFO(PathId).PduRSrcPdu.PduRSrcModuleType;
    PduIdType TxPduId = PDUR_ROUTINGPATHINFO(PathId).PduRSrcPdu.PduRSrcPduHandleId;
    P2VAR(PduR_MulticastMaskType, AUTOMATIC, PDUR_VAR) pTxConfMask = NULL_PTR;
    P2VAR(PduR_MulticastMaskType, AUTOMATIC, PDUR_VAR) pTxErrorMask = NULL_PTR;
    PduR_MulticastMaskType ConfirmFinishMask;
#if(STD_ON == PDUR_GW_TP_SUPPORT)
    uint16 BufferId = PDUR_ROUTINGPATHINFO(PathId).PduRDestPdu.PduRDestTxBufferId;
#endif

#if(STD_ON == PDUR_COM_MODULE_SUPPORT)
#if(PDUR_MAX_NUMOFCOMTXPDU > 0)
    if(MODULE_COM == SrcModuleType)
    {
        pTxConfMask = ComTxConfMask;
        pTxErrorMask = ComTxErrorMask;
        ConfirmFinishMask = PDUR_COM_TXPDUINFO(TxPduId).ConfMask;
    }
#endif
#endif
#if(STD_ON == PDUR_LDCOM_MODULE_SUPPORT)
#if(PDUR_MAX_NUMOFLDCOMTXPDU > 0)
    if(MODULE_LDCOM == SrcModuleType)
    {
        pTxConfMask = LdComTxConfMask;
        pTxErrorMask = LdComTxErrorMask;
        ConfirmFinishMask = PDUR_LDCOM_TXPDUINFO(TxPduId).ConfMask;
    }
#endif
#endif
#if(STD_ON == PDUR_DCM_MODULE_SUPPORT)
#if(PDUR_MAX_NUMOFDCMTXPDU > 0)
    if(MODULE_DCM == SrcModuleType)
    {
        pTxConfMask = DcmTxConfMask;
        pTxErrorMask = DcmTxErrorMask;
        ConfirmFinishMask = PDUR_DCM_TXPDUINFO(TxPduId).ConfMask;
    }
#endif
#endif
#if(STD_ON == PDUR_J1939DCM_MODULE_SUPPORT)
#if(PDUR_MAX_NUMOFJ1939DCMTXPDU > 0)
    if(MODULE_J1939DCM == SrcModuleType)
    {
        pTxConfMask = J1939DcmTxConfMask;
        pTxErrorMask = J1939DcmTxErrorMask;
        ConfirmFinishMask = PDUR_J1939DCM_TXPDUINFO(TxPduId).ConfMask;
    }
#endif
#endif

#if(STD_ON == PDUR_CDD_MODULE_SUPPORT)
#if(PDUR_MAX_NUMOFCDDTXPDU > 0)
    if(MODULE_CDD == SrcModuleType)
    {
        pTxConfMask = CddTxConfMask;
        pTxErrorMask = CddTxErrorMask;
        ConfirmFinishMask = PDUR_CDD_TXPDUINFO(TxPduId).ConfMask;
    }
#endif
#endif

#if(STD_ON == PDUR_SECOC_MODULE_SUPPORT)
#if(PDUR_MAX_NUMOFSECOCTXPDU > 0)
    if(MODULE_SECOC == SrcModuleType)
    {
        pTxConfMask = SecOCTxConfMask;
        pTxErrorMask = SecOCTxErrorMask;
        ConfirmFinishMask = PDUR_SECOC_TXPDUINFO(TxPduId).ConfMask;
    }
#endif
#endif

    if(NULL_PTR != PduR_ModuleFunctions[SrcModuleType].UpTpTxConfirmationFunc)
    {
        if((NULL_PTR != pTxConfMask) && (NULL_PTR != pTxErrorMask))
        {
            if(E_OK == Result)
            {
                if(pTxErrorMask[TxPduId] == pTxConfMask[TxPduId])
                {
                    /*The first valid TxConfirmation*/
                    /*SWS_PduR_00301 SWS_PduR_00765*/
                    PduR_ModuleFunctions[SrcModuleType].UpTpTxConfirmationFunc(ConfId, Result);
                }
            }            
            else
            {
                pTxErrorMask[TxPduId] |= mask;
                if(pTxErrorMask[TxPduId] == ConfirmFinishMask)
                {
                    /*All paths failed, call TxConfirmation with E_NOT_OK*/
                    PduR_ModuleFunctions[SrcModuleType].UpTpTxConfirmationFunc(ConfId, Result);
                }
            }
            pTxConfMask[TxPduId] |= mask;
            if(pTxConfMask[TxPduId] == ConfirmFinishMask)
            {
                /*The last TxConfirmation*/
                pTxConfMask[TxPduId] = 0;
                pTxErrorMask[TxPduId] = 0;
            }
        }
    }
#if(STD_ON == PDUR_GW_TP_SUPPORT)
#if(PDUR_MAX_NUMOFBUFFER > 0)
    else if(PDUR_UNUSED != BufferId)
    {
        /*SWS_PduR_00637*/
        if(PduRBufferInfo[BufferId].BufState & PDUR_BUFFER_TRANSMITING)
        {
            PduR_BufferInit(BufferId);
        }
    }
#endif
#endif
    else
    {
        /* Intentionally Empty */
    }
}


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: PduR_LowerTpMultiStartOfReception
*
* Description:   StartOfReception processing of lower Tp module
*
* Inputs:        PathId id of the routing path
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(BufReq_ReturnType, PDUR_CODE) PduR_LowerTpMultiStartOfReception
(
    P2CONST(PduRRoutingPduInfoType, AUTOMATIC, PDUR_CONST) pRxPduInfo,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info,
    PduLengthType TpSduLength,
    P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) bufferSizePtr
)
{
    BufReq_ReturnType result = BUFREQ_E_NOT_OK;
    PduR_RoutingPathIdType PathId;
    PduR_RoutingPathIdType i;
    PduR_RoutingPathGroupIdType GroupId;
    boolean Flag = FALSE;
    PduLengthType LargestBuffSize = 0;

    /*SWS_PduR_00803*/
    for(i = 0; i < pRxPduInfo->NumPaths; i++)
    {
        PathId = pRxPduInfo->PathIdx[i];
        GroupId = PDUR_ROUTINGPATHINFO(PathId).PduRDestPdu.PduRRoutingGroup;

        /*SWS_PduR_00717*/
        if((PDUR_RPGROUP_NONE == GroupId) || (TRUE == PduR_RoutingPathGroupEnabled[GroupId]))
        {
            result = PduR_LowerTpStartOfReception(PathId, info, TpSduLength, bufferSizePtr);
            if(BUFREQ_OK == result)
            {
                Flag = TRUE;
                /*return the largest*/
                if(*bufferSizePtr > LargestBuffSize)
                {
                    LargestBuffSize = *bufferSizePtr;
                }
            }
        }
    }

    /*SWS_PduR_00804*/
    if(TRUE == Flag)
    {
        result = BUFREQ_OK;
        *bufferSizePtr = LargestBuffSize;
    }

    return result;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: PduR_LowerTpMultiCopyRxData
*
* Description:   CopyRxData processing of lower Tp module
*
* Inputs:        PathId id of the routing path
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(BufReq_ReturnType, PDUR_CODE) PduR_LowerTpMultiCopyRxData
(
    P2CONST(PduRRoutingPduInfoType, AUTOMATIC, PDUR_CONST) pRxPduInfo,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info,
    P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) bufferSizePtr
)
{
    PduR_RoutingPathIdType PathId;
    BufReq_ReturnType result = BUFREQ_E_NOT_OK;
    PduR_RoutingPathIdType  i;
    PduR_RoutingPathGroupIdType GroupId;
    boolean Flag = FALSE;
    PduLengthType LargestBuffSize = 0;

    /*SWS_PduR_00803*/
    for(i = 0; i < pRxPduInfo->NumPaths; i++)
    {
        PathId = pRxPduInfo->PathIdx[i];
        GroupId = PDUR_ROUTINGPATHINFO(PathId).PduRDestPdu.PduRRoutingGroup;

        /*SWS_PduR_00717*/
        if((PDUR_RPGROUP_NONE == GroupId) || (TRUE == PduR_RoutingPathGroupEnabled[GroupId]))
        {
            result = PduR_LowerTpCopyRxData(PathId, info, bufferSizePtr);
            if(BUFREQ_OK == result)
            {
                Flag = TRUE;
                /*return the largest*/
                if(*bufferSizePtr > LargestBuffSize)
                {
                    LargestBuffSize = *bufferSizePtr;
                }
            }
        }
    }

    /*SWS_PduR_00804*/
    if(TRUE == Flag)
    {
        result = BUFREQ_OK;
        *bufferSizePtr = LargestBuffSize;
    }
    else
    {
        result = BUFREQ_E_NOT_OK;
    }
    return result;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: PduR_LowerTpMultiRxIndication
*
* Description:   RxIndication processing of lower Tp module
*
* Inputs:        PathId id of the routing path
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, PDUR_CODE) PduR_LowerTpMultiRxIndication
(
    P2CONST(PduRRoutingPduInfoType, AUTOMATIC, PDUR_CONST) pRxPduInfo,
    Std_ReturnType result
)
{
    PduR_RoutingPathIdType PathId;
    PduR_RoutingPathIdType i;
    PduR_RoutingPathGroupIdType GroupId;

    for(i = 0; i < pRxPduInfo->NumPaths; i++)
    {
        PathId = pRxPduInfo->PathIdx[i];
        GroupId = PDUR_ROUTINGPATHINFO(PathId).PduRDestPdu.PduRRoutingGroup;

        /*SWS_PduR_00717*/
        if((PDUR_RPGROUP_NONE == GroupId) || (TRUE == PduR_RoutingPathGroupEnabled[GroupId]))
        {
            PduR_LowerTpRxIndication(PathId, result);
        }
    }
}

#endif

/*******************************************************************************
*  PUBLIC Functions define
*******************************************************************************/

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: PduR_Init    SWS_PduR_00334
*
* Description:     Initializes the PDU Router.
*
* Inputs:         ConfigPtr Pointer to post build configuration
*
* Outputs:         None
*
* Limitations:     None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, PDUR_CODE) PduR_Init
(
    P2CONST(PduR_PBConfigType, AUTOMATIC, PDUR_CONST) ConfigPtr
)
{
#if(STD_ON == PDUR_DEV_ERROR_DETECT)
    PduR_RoutingPathIdType PathId = (PduR_RoutingPathIdType)0;
    PduIdType PduId = (PduIdType)0;
#endif
#if(PDUR_MAX_NUMOFROUTINGPATHGROUP > 0)
    PduR_RoutingPathGroupIdType GroupId = (PduR_RoutingPathGroupIdType)0;
#endif
#if(PDUR_MAX_NUMOFBUFFER > 0)
    uint8 BufferId;
#endif

    if(PDUR_IS_INITIALIZED())
    {
        /*delete it, since PduR has no deinit*/
        PDUR_DET_REPORT_ERROR(PDUR_INIT_APIID, PDUR_E_INVALID_REQUEST);
    }
    else
    {
#if(PDUR_CONFIG_VARIANTS == STD_CONFIG_VARIANTS_POSTBUILD)
        if(NULL_PTR == ConfigPtr)
        {
            PDUR_DET_REPORT_ERROR(PDUR_INIT_APIID, PDUR_E_PARAM_POINTER);
        }
        else
#else
        (void)ConfigPtr;
#endif
        {
#if(PDUR_CONFIG_VARIANTS == STD_CONFIG_VARIANTS_POSTBUILD)
            PduR_ConfigSet = ConfigPtr;
#endif
            /*Cfg compatibility check*/
#if(STD_ON == PDUR_DEV_ERROR_DETECT)

#if(PDUR_MAX_NUMOFCOMTXPDU > 0)
            for(PduId = (PduIdType)0; PduId < PDUR_GET_NUM_COMTXPDU(); PduId++)
            {
                for(PathId = (PduR_RoutingPathIdType)0; PathId < PDUR_COM_TXPDUINFO(PduId).NumPaths; PathId++)
                {
                    if(PDUR_COM_TXPDUINFO(PduId).PathIdx[PathId] >= PDUR_GET_NUM_ROUTPATH())
                    {
                        PDUR_DET_REPORT_ERROR(PDUR_INIT_APIID, PDUR_E_PDU_ID_INVALID);
                    }
                }
            }
#endif
#if(PDUR_MAX_NUMOFDCMTXPDU > 0)
            for(PduId = (PduIdType)0; PduId < PDUR_GET_NUM_DCMTXPDU(); PduId++)
            {
                for(PathId = (PduR_RoutingPathIdType)0; PathId < PDUR_DCM_TXPDUINFO(PduId).NumPaths; PathId++)
                {
                    if(PDUR_DCM_TXPDUINFO(PduId).PathIdx[PathId] >= PDUR_GET_NUM_ROUTPATH())
                    {
                        PDUR_DET_REPORT_ERROR(PDUR_INIT_APIID, PDUR_E_PDU_ID_INVALID);
                    }
                }
            }
#endif
#if(PDUR_MAX_NUMOFCDDTXPDU > 0)
            for(PduId = (PduIdType)0; PduId < PDUR_GET_NUM_CDDTXPDU(); PduId++)
            {
                for(PathId = (PduR_RoutingPathIdType)0; PathId < PDUR_CDD_TXPDUINFO(PduId).NumPaths; PathId++)
                {
                    if(PDUR_CDD_TXPDUINFO(PduId).PathIdx[PathId] >= PDUR_GET_NUM_ROUTPATH())
                    {
                        PDUR_DET_REPORT_ERROR(PDUR_INIT_APIID, PDUR_E_PDU_ID_INVALID);
                    }
                }
            }
#endif
#if(PDUR_MAX_NUMOFCANIFTXPDU > 0)
            for(PduId = (PduIdType)0; PduId < PDUR_GET_NUM_CANIFTXPDU(); PduId++)
            {
                if(PDUR_CANIF_TXCONFPDUINFO(PduId).PathId >= PDUR_GET_NUM_ROUTPATH())
                {
                    PDUR_DET_REPORT_ERROR(PDUR_INIT_APIID, PDUR_E_PDU_ID_INVALID);
                }
            }
#endif
#if(PDUR_MAX_NUMOFCANIFRXPDU > 0)
            for(PduId = (PduIdType)0; PduId < PDUR_GET_NUM_CANIFRXPDU(); PduId++)
            {
                for(PathId = (PduR_RoutingPathIdType)0; PathId < PDUR_CANIF_RXPDUINFO(PduId).NumPaths; PathId++)
                {
                    if(PDUR_CANIF_RXPDUINFO(PduId).PathIdx[PathId] >= PDUR_GET_NUM_ROUTPATH())
                    {
                        PDUR_DET_REPORT_ERROR(PDUR_INIT_APIID, PDUR_E_PDU_ID_INVALID);
                    }
                }
            }
#endif
#if(PDUR_MAX_NUMOFCANTPTXPDU > 0)
            for(PduId = (PduIdType)0; PduId < PDUR_GET_NUM_CANTPTXPDU(); PduId++)
            {
                if(PDUR_CANTP_TXCONFPDUINFO(PduId).PathId >= PDUR_GET_NUM_ROUTPATH())
                {
                    PDUR_DET_REPORT_ERROR(PDUR_INIT_APIID, PDUR_E_PDU_ID_INVALID);
                }
            }
#endif
#if(PDUR_MAX_NUMOFCANTPRXPDU > 0)
            for(PduId = (PduIdType)0; PduId < PDUR_GET_NUM_CANTPRXPDU(); PduId++)
            {
                for(PathId = (PduR_RoutingPathIdType)0; PathId < PDUR_CANTP_RXPDUINFO(PduId).NumPaths; PathId++)
                {
                    if(PDUR_CANTP_RXPDUINFO(PduId).PathIdx[PathId] >= PDUR_GET_NUM_ROUTPATH())
                    {
                        PDUR_DET_REPORT_ERROR(PDUR_INIT_APIID, PDUR_E_PDU_ID_INVALID);
                    }
                }
            }
#endif
#if(PDUR_MAX_NUMOFLINIFTXPDU > 0)
            for(PduId = (PduIdType)0; PduId < PDUR_GET_NUM_LINIFTXPDU(); PduId++)
            {
                if(PDUR_LINIF_TXCONFPDUINFO(PduId).PathId >= PDUR_GET_NUM_ROUTPATH())
                {
                    PDUR_DET_REPORT_ERROR(PDUR_INIT_APIID, PDUR_E_PDU_ID_INVALID);
                }
            }
#endif
#if(PDUR_MAX_NUMOFLINIFRXPDU > 0)
            for(PduId = (PduIdType)0; PduId < PDUR_GET_NUM_LINIFRXPDU(); PduId++)
            {
                for(PathId = (PduR_RoutingPathIdType)0; PathId < PDUR_LINIF_RXPDUINFO(PduId).NumPaths; PathId++)
                {
                    if(PDUR_LINIF_RXPDUINFO(PduId).PathIdx[PathId] >= PDUR_GET_NUM_ROUTPATH())
                    {
                        PDUR_DET_REPORT_ERROR(PDUR_INIT_APIID, PDUR_E_PDU_ID_INVALID);
                    }
                }
            }
#endif
#if(PDUR_MAX_NUMOFLINTPTXPDU > 0)
            for(PduId = (PduIdType)0; PduId < PDUR_GET_NUM_LINTPTXPDU(); PduId++)
            {
                if(PDUR_LINTP_TXCONFPDUINFO(PduId).PathId >= PDUR_GET_NUM_ROUTPATH())
                {
                    PDUR_DET_REPORT_ERROR(PDUR_INIT_APIID, PDUR_E_PDU_ID_INVALID);
                }
            }
#endif
#if(PDUR_MAX_NUMOFLINTPRXPDU > 0)
            for(PduId = (PduIdType)0; PduId < PDUR_GET_NUM_LINTPRXPDU(); PduId++)
            {
                for(PathId = (PduR_RoutingPathIdType)0; PathId < PDUR_LINTP_RXPDUINFO(PduId).NumPaths; PathId++)
                {
                    if(PDUR_LINTP_RXPDUINFO(PduId).PathIdx[PathId] >= PDUR_GET_NUM_ROUTPATH())
                    {
                        PDUR_DET_REPORT_ERROR(PDUR_INIT_APIID, PDUR_E_PDU_ID_INVALID);
                    }
                }
            }
#endif
#if(PDUR_MAX_NUMOFFRIFTXPDU > 0)
            for(PduId = (PduIdType)0; PduId < PDUR_GET_NUM_FRIFTXPDU(); PduId++)
            {
                if(PDUR_FRIF_TXCONFPDUINFO(PduId).PathId >= PDUR_GET_NUM_ROUTPATH())
                {
                    PDUR_DET_REPORT_ERROR(PDUR_INIT_APIID, PDUR_E_PDU_ID_INVALID);
                }
            }
#endif
#if(PDUR_MAX_NUMOFFRIFRXPDU > 0)
            for(PduId = (PduIdType)0; PduId < PDUR_GET_NUM_FRIFRXPDU(); PduId++)
            {
                for(PathId = (PduR_RoutingPathIdType)0; PathId < PDUR_FRIF_RXPDUINFO(PduId).NumPaths; PathId++)
                {
                    if(PDUR_FRIF_RXPDUINFO(PduId).PathIdx[PathId] >= PDUR_GET_NUM_ROUTPATH())
                    {
                        PDUR_DET_REPORT_ERROR(PDUR_INIT_APIID, PDUR_E_PDU_ID_INVALID);
                    }
                }
            }
#endif
#if(PDUR_MAX_NUMOFFRTPTXPDU > 0)
            for(PduId = (PduIdType)0; PduId < PDUR_GET_NUM_FRTPTXPDU(); PduId++)
            {
                if(PDUR_FRTP_TXCONFPDUINFO(PduId).PathId >= PDUR_GET_NUM_ROUTPATH())
                {
                    PDUR_DET_REPORT_ERROR(PDUR_INIT_APIID, PDUR_E_PDU_ID_INVALID);
                }
            }
#endif
#if(PDUR_MAX_NUMOFFRTPRXPDU > 0)
            for(PduId = (PduIdType)0; PduId < PDUR_GET_NUM_FRTPRXPDU(); PduId++)
            {
                for(PathId = (PduR_RoutingPathIdType)0; PathId < PDUR_FRTP_RXPDUINFO(PduId).NumPaths; PathId++)
                {
                    if(PDUR_FRTP_RXPDUINFO(PduId).PathIdx[PathId] >= PDUR_GET_NUM_ROUTPATH())
                    {
                        PDUR_DET_REPORT_ERROR(PDUR_INIT_APIID, PDUR_E_PDU_ID_INVALID);
                    }
                }
            }
#endif
#if(PDUR_MAX_NUMOFDOIPTPTXPDU > 0)
            for(PduId = (PduIdType)0; PduId < PDUR_GET_NUM_DOIPTPTXPDU(); PduId++)
            {
                if(PDUR_DOIPTP_TXCONFPDUINFO(PduId).PathId >= PDUR_GET_NUM_ROUTPATH())
                {
                    PDUR_DET_REPORT_ERROR(PDUR_INIT_APIID, PDUR_E_PDU_ID_INVALID);
                }
            }
#endif
#if(PDUR_MAX_NUMOFDOIPTPRXPDU > 0)
            for(PduId = (PduIdType)0; PduId < PDUR_GET_NUM_DOIPTPRXPDU(); PduId++)
            {
                for(PathId = (PduR_RoutingPathIdType)0; PathId < PDUR_DOIPTP_RXPDUINFO(PduId).NumPaths; PathId++)
                {
                    if(PDUR_DOIPTP_RXPDUINFO(PduId).PathIdx[PathId] >= PDUR_GET_NUM_ROUTPATH())
                    {
                        PDUR_DET_REPORT_ERROR(PDUR_INIT_APIID, PDUR_E_PDU_ID_INVALID);
                    }
                }
            }
#endif
#if(PDUR_MAX_NUMOFSOADIFTXPDU > 0)
            for(PduId = (PduIdType)0; PduId < PDUR_GET_NUM_SOADIFTXPDU(); PduId++)
            {
                if(PDUR_SOADIF_TXCONFPDUINFO(PduId).PathId >= PDUR_GET_NUM_ROUTPATH())
                {
                    PDUR_DET_REPORT_ERROR(PDUR_INIT_APIID, PDUR_E_PDU_ID_INVALID);
                }
            }
#endif
#if(PDUR_MAX_NUMOFSOADIFRXPDU > 0)
            for(PduId = (PduIdType)0; PduId < PDUR_GET_NUM_SOADIFRXPDU(); PduId++)
            {
                for(PathId = (PduR_RoutingPathIdType)0; PathId < PDUR_SOADIF_RXPDUINFO(PduId).NumPaths; PathId++)
                {
                    if(PDUR_SOADIF_RXPDUINFO(PduId).PathIdx[PathId] >= PDUR_GET_NUM_ROUTPATH())
                    {
                        PDUR_DET_REPORT_ERROR(PDUR_INIT_APIID, PDUR_E_PDU_ID_INVALID);
                    }
                }
            }
#endif
#if(PDUR_MAX_NUMOFSOADTPRXPDU > 0)
            for(PduId = (PduIdType)0; PduId < PDUR_GET_NUM_SOADTPRXPDU(); PduId++)
            {
                for(PathId = (PduR_RoutingPathIdType)0; PathId < PDUR_SOADTP_RXPDUINFO(PduId).NumPaths; PathId++)
                {
                    if(PDUR_SOADTP_RXPDUINFO(PduId).PathIdx[PathId] >= PDUR_GET_NUM_ROUTPATH())
                    {
                        PDUR_DET_REPORT_ERROR(PDUR_INIT_APIID, PDUR_E_PDU_ID_INVALID);
                    }
                }
            }
#endif
#if(PDUR_MAX_NUMOFCDDIFTXPDU > 0)
            for(PduId = (PduIdType)0; PduId < PDUR_GET_NUM_CDDIFTXPDU(); PduId++)
            {
                if(PDUR_CDDIF_TXCONFPDUINFO(PduId).PathId >= PDUR_GET_NUM_ROUTPATH())
                {
                    PDUR_DET_REPORT_ERROR(PDUR_INIT_APIID, PDUR_E_PDU_ID_INVALID);
                }
            }
#endif
#if(PDUR_MAX_NUMOFCDDIFRXPDU > 0)
            for(PduId = (PduIdType)0; PduId < PDUR_GET_NUM_CDDIFRXPDU(); PduId++)
            {
                for(PathId = (PduR_RoutingPathIdType)0; PathId < PDUR_CDDIF_RXPDUINFO(PduId).NumPaths; PathId++)
                {
                    if(PDUR_CDDIF_RXPDUINFO(PduId).PathIdx[PathId] >= PDUR_GET_NUM_ROUTPATH())
                    {
                        PDUR_DET_REPORT_ERROR(PDUR_INIT_APIID, PDUR_E_PDU_ID_INVALID);
                    }
                }
            }
#endif
#if(PDUR_MAX_NUMOFCDDTPTXPDU > 0)
            for(PduId = (PduIdType)0; PduId < PDUR_GET_NUM_CDDTPTXPDU(); PduId++)
            {
                if(PDUR_CDDTP_TXCONFPDUINFO(PduId).PathId >= PDUR_GET_NUM_ROUTPATH())
                {
                    PDUR_DET_REPORT_ERROR(PDUR_INIT_APIID, PDUR_E_PDU_ID_INVALID);
                }
            }
#endif
#if(PDUR_MAX_NUMOFCDDTPRXPDU > 0)
            for(PduId = (PduIdType)0; PduId < PDUR_GET_NUM_CDDTPRXPDU(); PduId++)
            {
                for(PathId = (PduR_RoutingPathIdType)0; PathId < PDUR_CDDTP_RXPDUINFO(PduId).NumPaths; PathId++)
                {
                    if(PDUR_CDDTP_RXPDUINFO(PduId).PathIdx[PathId] >= PDUR_GET_NUM_ROUTPATH())
                    {
                        PDUR_DET_REPORT_ERROR(PDUR_INIT_APIID, PDUR_E_PDU_ID_INVALID);
                    }
                }
            }
#endif
#if(PDUR_MAX_NUMOFIPDUMIFRXPDU > 0)
            for(PduId = (PduIdType)0; PduId < PDUR_GET_NUM_IPDUMIFRXPDU(); PduId++)
            {
                for(PathId = (PduR_RoutingPathIdType)0; PathId < PDUR_IPDUMIF_RXPDUINFO(PduId).NumPaths; PathId++)
                {
                    if(PDUR_IPDUMIF_RXPDUINFO(PduId).PathIdx[PathId] >= PDUR_GET_NUM_ROUTPATH())
                    {
                        PDUR_DET_REPORT_ERROR(PDUR_INIT_APIID, PDUR_E_PDU_ID_INVALID);
                    }
                }
            }
#endif
#if(PDUR_MAX_NUMOFSECOCRXPDU > 0)
            for(PduId = (PduIdType)0; PduId < PDUR_GET_NUM_SECOCRXPDU(); PduId++)
            {
                for(PathId = (PduR_RoutingPathIdType)0; PathId < PDUR_SECOC_RXPDUINFO(PduId).NumPaths; PathId++)
                {
                    if(PDUR_SECOC_RXPDUINFO(PduId).PathIdx[PathId] >= PDUR_GET_NUM_ROUTPATH())
                    {
                        PDUR_DET_REPORT_ERROR(PDUR_INIT_APIID, PDUR_E_PDU_ID_INVALID);
                    }
                }
            }
#endif

            for(PathId = (PduR_RoutingPathIdType)0; PathId < PDUR_GET_NUM_ROUTPATH(); PathId++)
            {
#if(PDUR_MAX_NUMOFCOMTXPDU > 0)
                if((PDUR_ROUTINGPATHINFO(PathId).PduRSrcPdu.PduRSrcModuleType == MODULE_COM)
                        && (PDUR_ROUTINGPATHINFO(PathId).PduRSrcPdu.PduRSrcPduHandleId >= PDUR_GET_NUM_COMTXPDU()))
                {
                    PDUR_DET_REPORT_ERROR(PDUR_INIT_APIID, PDUR_E_PDU_ID_INVALID);
                }
#endif
#if(PDUR_MAX_NUMOFDCMTXPDU > 0)
                if((PDUR_ROUTINGPATHINFO(PathId).PduRSrcPdu.PduRSrcModuleType == MODULE_DCM)
                        && (PDUR_ROUTINGPATHINFO(PathId).PduRSrcPdu.PduRSrcPduHandleId >= PDUR_GET_NUM_DCMTXPDU()))
                {
                    PDUR_DET_REPORT_ERROR(PDUR_INIT_APIID, PDUR_E_PDU_ID_INVALID);
                }
#endif
#if(PDUR_MAX_NUMOFCDDTXPDU > 0)
                if((PDUR_ROUTINGPATHINFO(PathId).PduRSrcPdu.PduRSrcModuleType == MODULE_CDD)
                        && (PDUR_ROUTINGPATHINFO(PathId).PduRSrcPdu.PduRSrcPduHandleId >= PDUR_GET_NUM_CDDTXPDU()))
                {
                    PDUR_DET_REPORT_ERROR(PDUR_INIT_APIID, PDUR_E_PDU_ID_INVALID);
                }
#endif
#if(PDUR_MAX_NUMOFCANIFRXPDU > 0)
                if((PDUR_ROUTINGPATHINFO(PathId).PduRSrcPdu.PduRSrcModuleType == MODULE_CANIF)
                        && (PDUR_ROUTINGPATHINFO(PathId).PduRSrcPdu.PduRSrcPduHandleId >= PDUR_GET_NUM_CANIFRXPDU()))
                {
                    PDUR_DET_REPORT_ERROR(PDUR_INIT_APIID, PDUR_E_PDU_ID_INVALID);
                }
#endif
#if(PDUR_MAX_NUMOFIPDUMIFRXPDU > 0)
                if((PDUR_ROUTINGPATHINFO(PathId).PduRSrcPdu.PduRSrcModuleType == MODULE_IPDUMIF)
                        && (PDUR_ROUTINGPATHINFO(PathId).PduRSrcPdu.PduRSrcPduHandleId >= PDUR_GET_NUM_IPDUMIFRXPDU()))
                {
                    PDUR_DET_REPORT_ERROR(PDUR_INIT_APIID, PDUR_E_PDU_ID_INVALID);
                }
#endif
#if(PDUR_MAX_NUMOFSECOCRXPDU > 0)
                if((PDUR_ROUTINGPATHINFO(PathId).PduRSrcPdu.PduRSrcModuleType == MODULE_SECOC)
                        && (PDUR_ROUTINGPATHINFO(PathId).PduRSrcPdu.PduRSrcPduHandleId >= PDUR_GET_NUM_SECOCRXPDU()))
                {
                    PDUR_DET_REPORT_ERROR(PDUR_INIT_APIID, PDUR_E_PDU_ID_INVALID);
                }
#endif
#if(PDUR_MAX_NUMOFLINIFRXPDU > 0)
                if((PDUR_ROUTINGPATHINFO(PathId).PduRSrcPdu.PduRSrcModuleType == MODULE_LINIF)
                        && (PDUR_ROUTINGPATHINFO(PathId).PduRSrcPdu.PduRSrcPduHandleId >= PDUR_GET_NUM_LINIFRXPDU()))
                {
                    PDUR_DET_REPORT_ERROR(PDUR_INIT_APIID, PDUR_E_PDU_ID_INVALID);
                }
#endif
#if(PDUR_MAX_NUMOFFRIFRXPDU > 0)
                if((PDUR_ROUTINGPATHINFO(PathId).PduRSrcPdu.PduRSrcModuleType == MODULE_FRIF)
                        && (PDUR_ROUTINGPATHINFO(PathId).PduRSrcPdu.PduRSrcPduHandleId >= PDUR_GET_NUM_FRIFRXPDU()))
                {
                    PDUR_DET_REPORT_ERROR(PDUR_INIT_APIID, PDUR_E_PDU_ID_INVALID);
                }
#endif
#if(PDUR_MAX_NUMOFDOIPIFRXPDU > 0)
                if((PDUR_ROUTINGPATHINFO(PathId).PduRSrcPdu.PduRSrcModuleType == MODULE_DOIPIF)
                        && (PDUR_ROUTINGPATHINFO(PathId).PduRSrcPdu.PduRSrcPduHandleId >= PDUR_GET_NUM_DOIPIFRXPDU()))
                {
                    PDUR_DET_REPORT_ERROR(PDUR_INIT_APIID, PDUR_E_PDU_ID_INVALID);
                }
#endif
#if(PDUR_MAX_NUMOFCANTPRXPDU > 0)
                if((PDUR_ROUTINGPATHINFO(PathId).PduRSrcPdu.PduRSrcModuleType == MODULE_CANTP)
                        && (PDUR_ROUTINGPATHINFO(PathId).PduRSrcPdu.PduRSrcPduHandleId >= PDUR_GET_NUM_CANTPRXPDU()))
                {
                    PDUR_DET_REPORT_ERROR(PDUR_INIT_APIID, PDUR_E_PDU_ID_INVALID);
                }
#endif
#if(PDUR_MAX_NUMOFLINTPRXPDU > 0)
                if((PDUR_ROUTINGPATHINFO(PathId).PduRSrcPdu.PduRSrcModuleType == MODULE_LINTP)
                        && (PDUR_ROUTINGPATHINFO(PathId).PduRSrcPdu.PduRSrcPduHandleId >= PDUR_GET_NUM_LINTPRXPDU()))
                {
                    PDUR_DET_REPORT_ERROR(PDUR_INIT_APIID, PDUR_E_PDU_ID_INVALID);
                }
#endif
#if(PDUR_MAX_NUMOFFRTPRXPDU > 0)
                if((PDUR_ROUTINGPATHINFO(PathId).PduRSrcPdu.PduRSrcModuleType == MODULE_FRTP)
                        && (PDUR_ROUTINGPATHINFO(PathId).PduRSrcPdu.PduRSrcPduHandleId >= PDUR_GET_NUM_FRTPRXPDU()))
                {
                    PDUR_DET_REPORT_ERROR(PDUR_INIT_APIID, PDUR_E_PDU_ID_INVALID);
                }
#endif
#if(PDUR_MAX_NUMOFBUFFER > 0)
                if((PDUR_ROUTINGPATHINFO(PathId).PduRDestPdu.PduRDestTxBufferId != PDUR_UNUSED)
                        && (PDUR_ROUTINGPATHINFO(PathId).PduRDestPdu.PduRDestTxBufferId >= PDUR_GET_NUM_BUFFER()))
                {
                    PDUR_DET_REPORT_ERROR(PDUR_INIT_APIID, PDUR_E_DEST_TXBUF_ID_INVALID);
                }
#endif
#if(PDUR_MAX_NUMOFROUTINGPATHGROUP> 0)
                if((PDUR_ROUTINGPATHINFO(PathId).PduRDestPdu.PduRRoutingGroup != PDUR_RPGROUP_NONE)
                        && (PDUR_ROUTINGPATHINFO(PathId).PduRDestPdu.PduRRoutingGroup >= PDUR_GET_NUM_ROUTPATHGROUP()))
                {
                    PDUR_DET_REPORT_ERROR(PDUR_INIT_APIID, PDUR_E_ROUTING_PATH_GROUP_ID_INVALID);
                }
#endif
                if((PDUR_ROUTINGPATHINFO(PathId).PduRDestPdu.PduRTpGWTrigger != PDUR_TPGW_TRIGGER_FLY)
                        && (PDUR_ROUTINGPATHINFO(PathId).PduRDestPdu.PduRTpGWTrigger != PDUR_TPGW_TRIGGER_IND))
                {
                    PDUR_DET_REPORT_ERROR(PDUR_INIT_APIID, PDUR_E_DEST_TRIGGER_INVALID);
                }
            }

#endif
#if(PDUR_MAX_NUMOFBUFFER > 0)
            for(BufferId = (uint8)0; BufferId < PDUR_GET_NUM_BUFFER(); BufferId++)
            {
                /*SWS_PduR_00645 SWS_PduR_00308*/
                PduR_BufferInit(BufferId);
            }
#endif
#if(PDUR_MAX_NUMOFROUTINGPATHGROUP > 0)
            /*SWS_PduR_00709*/
            for(GroupId = (PduR_RoutingPathGroupIdType)0; GroupId < PDUR_GET_NUM_ROUTPATHGROUP(); GroupId++)
            {
                PduR_RoutingPathGroupEnabled[GroupId] = PDUR_GET_RPGROUP_ENABLED_ATINIT(GroupId);
            }
#endif
            /*SWS_PduR_00326*/
            PDUR_SET_INITIALIZED();
        }
    }
}


#if(STD_ON == PDUR_VERSION_INFO_API)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: PduR_GetVersionInfo  SWS_PduR_00338
*
* Description:   Returns the version information of this module
*
* Inputs:        None
*
* Outputs:       VersionInfo  Pointer to where to store the version information
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, PDUR_CODE) PduR_GetVersionInfo
(
    P2VAR(Std_VersionInfoType, AUTOMATIC, PDUR_APPL_DATA) versionInfo
)
{
    if(NULL_PTR == versionInfo)
    {
        PDUR_DET_REPORT_ERROR(PDUR_GETVERSIONINFO_APIID, PDUR_E_PARAM_POINTER);
    }
    else
    {
        versionInfo->vendorID = PDUR_VENDOR_ID;
        versionInfo->moduleID = PDUR_MODULE_ID;

        versionInfo->sw_major_version = (uint8)PDUR_SW_MAJOR_VERSION;
        versionInfo->sw_minor_version = (uint8)PDUR_SW_MINOR_VERSION;
        versionInfo->sw_patch_version = (uint8)PDUR_SW_PATCH_VERSION;
    }
}
#endif


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: PduR_GetConfigurationId  SWS_PduR_00341
*
* Description:   Returns the unique identifier of the post-build time configuration
*
* Inputs:        None
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(PduR_PBConfigIdType, PDUR_CODE) PduR_GetConfigurationId
(
    void
)
{
    PduR_PBConfigIdType retId = (PduR_PBConfigIdType)PDUR_INVALID_CONFIG_ID;

    if(!PDUR_IS_INITIALIZED())
    {
        /*SWS_PduR_00328 SWS_PduR_00330 SWS_PduR_00119*/
        PDUR_DET_REPORT_ERROR(PDUR_GETCONFIGURATIONID_APIID, PDUR_E_INVALID_REQUEST);
    }
    else
    {
        /*SWS_PduR_00280*/
#if(PDUR_CONFIG_VARIANTS == STD_CONFIG_VARIANTS_POSTBUILD)
        retId = PduR_ConfigSet->PBConfigId;
#endif
    }
    return retId;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: PduR_EnableRouting  SWS_PduR_00615
*
* Description:   Enables a routing path table.
*
* Inputs:        id Identification of the routing path group.
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, PDUR_CODE) PduR_EnableRouting
(
    PduR_RoutingPathGroupIdType id
)
{
    if(!PDUR_IS_INITIALIZED())
    {
        /*SWS_PduR_00328 SWS_PduR_00330 SWS_PduR_00119*/
        PDUR_DET_REPORT_ERROR(PDUR_ENABLE_ROUTING_APIID, PDUR_E_INVALID_REQUEST);
    }
    else if(id >= PDUR_GET_NUM_ROUTPATHGROUP())
    {
        /*SWS_PduR_00647 SWS_PduR_00648*/
        PDUR_DET_REPORT_ERROR(PDUR_ENABLE_ROUTING_APIID, PDUR_E_ROUTING_PATH_GROUP_ID_INVALID);
    }
    else
    {
        /*SWS_PduR_00715*/
        PduR_RoutingPathGroupEnabled[id] = TRUE;
    }

}


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: PduR_DisableRouting  SWS_PduR_00617
*
* Description:   Disables a routing path table.
*
* Inputs:        id Identification of the routing path group.
*                initialize - true: initialize single buffers to the default value
*                             false: retain current value of single buffers
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, PDUR_CODE) PduR_DisableRouting
(
    PduR_RoutingPathGroupIdType id,
    boolean initialize
)
{
    (void) initialize;

    if(!PDUR_IS_INITIALIZED())
    {
        /*SWS_PduR_00328 SWS_PduR_00330 SWS_PduR_00119*/
        PDUR_DET_REPORT_ERROR(PDUR_DISABLE_ROUTING_APIID, PDUR_E_INVALID_REQUEST);
    }
    else if(id >= PDUR_GET_NUM_ROUTPATHGROUP())
    {
        /*SWS_PduR_00716 SWS_PduR_00649*/
        PDUR_DET_REPORT_ERROR(PDUR_DISABLE_ROUTING_APIID, PDUR_E_ROUTING_PATH_GROUP_ID_INVALID);
    }
    else
    {
        /*SWS_PduR_00646 SWS_PDUR_00805 SWS_PDUR_00810*/
        PduR_RoutingPathGroupEnabled[id] = FALSE;
    }

}


#if(STD_ON == PDUR_COM_MODULE_SUPPORT)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: PduR_ComTransmit    SWS_PduR_00406
*
* Description:     Requests transmission of an I-PDU.
*
* Inputs:         id   Identification of the I-PDU.
*                info Length and pointer to the buffer of the I-PDU
*
* Outputs:         None
*
* Limitations:     None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, PDUR_CODE) PduR_ComTransmit
(
    PduIdType id,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_CONST) info
)
{
    PduR_RoutingPathIdType i;
    Std_ReturnType ret = E_NOT_OK;
    boolean Flag = FALSE;
    PduR_MulticastMaskType mask;
    PduR_RoutingPathIdType PathId;

    if(!PDUR_IS_INITIALIZED())
    {
        /*SWS_PduR_00328 SWS_PduR_00330 SWS_PduR_00119*/
        PDUR_DET_REPORT_ERROR(PDUR_COM_TRANSMIT_APIID, PDUR_E_INVALID_REQUEST);
    }
    else if(id >= PDUR_GET_NUM_COMTXPDU())
    {
        /*SWS_PduR_00221*/
        PDUR_DET_REPORT_ERROR(PDUR_COM_TRANSMIT_APIID, PDUR_E_PDU_ID_INVALID);
    }
    else if(NULL_PTR == info)
    {
        PDUR_DET_REPORT_ERROR(PDUR_COM_TRANSMIT_APIID, PDUR_E_PARAM_POINTER);
    }
    else
    {
#if(PDUR_MAX_NUMOFCOMTXPDU > 0)
        SchM_Enter_PduR_PDUR_EXCLUSIVE_AREA_0();

        ComTxErrorMask[id] = (PduR_MulticastMaskType)0;
        ComTxConfMask[id] = (PduR_MulticastMaskType)0;
        for(i = (PduR_RoutingPathIdType)0; i < PDUR_COM_TXPDUINFO(id).NumPaths; i++)
        {
            PathId = PDUR_COM_TXPDUINFO(id).PathIdx[i];
            ret = PduR_UpTransmit(PathId, info);
            if(ret == E_OK)
            {
                Flag = TRUE;
            }
            else
            {
                /*Set mask as if the wrong path has finished*/
                mask = PDUR_ROUTINGPATHINFO(PathId).ConfMask;
                ComTxErrorMask[id] |= mask;
                ComTxConfMask[id] |= mask;
            }
        }

        SchM_Exit_PduR_PDUR_EXCLUSIVE_AREA_0();
#endif
    }

    /*SWS_PduR_00218*/
    if(TRUE == Flag)
    {
        ret = E_OK;
    }
    else
    {
        ret = E_NOT_OK;
    }
    return ret;
}


#if(STD_ON == PDUR_COM_CANCELTRANSMIT_ENABLED)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: PduR_ComCancelTransmit     SWS_PduR_00769
*
* Description:     Request for cancellation of an ongoing transmission of an I-Pdu
*                in transport protocol or communication interface.
*
* Inputs:         id   Identification of the I-PDU to be cancelled.
*
*
* Outputs:         None
*
* Limitations:     None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, PDUR_CODE) PduR_ComCancelTransmit
(
    PduIdType id
)
{
    Std_ReturnType ret = E_NOT_OK;
    PduR_RoutingPathIdType i;
    boolean ErrorFlag = FALSE;

    if(!PDUR_IS_INITIALIZED())
    {
        /*SWS_PduR_00328 SWS_PduR_00330 SWS_PduR_00119*/
        PDUR_DET_REPORT_ERROR(PDUR_COM_CANCEL_TRANSMIT_APIID, PDUR_E_INVALID_REQUEST);
    }
    else if(id >= PDUR_GET_NUM_COMTXPDU())
    {
        /*SWS_PduR_00221*/
        PDUR_DET_REPORT_ERROR(PDUR_COM_CANCEL_TRANSMIT_APIID, PDUR_E_PDU_ID_INVALID);
    }
    else
    {
        SchM_Enter_PduR_PDUR_EXCLUSIVE_AREA_0();
        for(i = 0; i < PDUR_COM_TXPDUINFO(id).NumPaths; i++)
        {
            ret = PduR_UpCancelTransmit(PDUR_COM_TXPDUINFO(id).PathIdx[i]);
            if(ret != E_OK)
            {
                ErrorFlag = TRUE;
            }

        }
        SchM_Exit_PduR_PDUR_EXCLUSIVE_AREA_0();
    }

    /*SWS_PduR_00701*/
    if(ErrorFlag)
    {
        ret = E_NOT_OK;
    }
    else
    {
        ret = E_OK;
    }
    return ret;
}
#endif
#endif/*#if(STD_ON == PDUR_COM_MODULE_SUPPORT)*/

#if(STD_ON == PDUR_LDCOM_MODULE_SUPPORT)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: PduR_LdComTransmit
*
* Description:   Requests transmission of an I-PDU.
*
* Inputs:        id   Identification of the I-PDU.
*                info Length and pointer to the buffer of the I-PDU
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, PDUR_CODE) PduR_LdComTransmit
(
    PduIdType id,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_CONST) info
)
{
    PduR_RoutingPathIdType i;
    Std_ReturnType ret = E_NOT_OK;
    boolean Flag = FALSE;
    PduR_MulticastMaskType mask;
    PduR_RoutingPathIdType PathId;

    if(!PDUR_IS_INITIALIZED())
    {
        /*SWS_PduR_00328 SWS_PduR_00330 SWS_PduR_00119*/
        PDUR_DET_REPORT_ERROR(PDUR_LDCOM_TRANSMIT_APIID, PDUR_E_INVALID_REQUEST);
    }
    else if(id >= PDUR_GET_NUM_LDCOMTXPDU())
    {
        /*SWS_PduR_00221*/
        PDUR_DET_REPORT_ERROR(PDUR_LDCOM_TRANSMIT_APIID, PDUR_E_PDU_ID_INVALID);
    }
    else if(NULL_PTR == info)
    {
        PDUR_DET_REPORT_ERROR(PDUR_LDCOM_TRANSMIT_APIID, PDUR_E_PARAM_POINTER);
    }
    else
    {
#if(PDUR_MAX_NUMOFLDCOMTXPDU > 0)
        SchM_Enter_PduR_PDUR_EXCLUSIVE_AREA_0();

        LdComTxErrorMask[id] = (PduR_MulticastMaskType)0;
        LdComTxConfMask[id] = (PduR_MulticastMaskType)0;
        for(i = (PduR_RoutingPathIdType)0; i < PDUR_LDCOM_TXPDUINFO(id).NumPaths; i++)
        {
            PathId = PDUR_LDCOM_TXPDUINFO(id).PathIdx[i];
            ret = PduR_UpTransmit(PathId, info);
            if(ret == E_OK)
            {
                Flag = TRUE;
            }
            else
            {
                /*Set mask as if the wrong path has finished*/
                mask = PDUR_ROUTINGPATHINFO(PathId).ConfMask;
                LdComTxErrorMask[id] |= mask;
                LdComTxConfMask[id] |= mask;
            }
        }

        SchM_Exit_PduR_PDUR_EXCLUSIVE_AREA_0();
#endif
    }

    /*SWS_PduR_00218*/
    if(TRUE == Flag)
    {
        ret = E_OK;
    }
    else
    {
        ret = E_NOT_OK;
    }
    return ret;
}
#endif

#if(STD_ON == PDUR_IPDUM_MODULE_SUPPORT)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: PduR_IpduMTransmit
*
* Description:     Requests transmission of an I-PDU.
*
* Inputs:         id   Identification of the I-PDU.
*                info Length and pointer to the buffer of the I-PDU
*
* Outputs:         None
*
* Limitations:     None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, PDUR_CODE) PduR_IpduMTransmit
(
    PduIdType id,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_CONST) info
)
{
    PduR_RoutingPathIdType i;
    Std_ReturnType ret = E_NOT_OK;
    boolean Flag = FALSE;
    PduR_MulticastMaskType mask;
    PduR_RoutingPathIdType PathId;

    if(!PDUR_IS_INITIALIZED())
    {
        /*SWS_PduR_00328 SWS_PduR_00330 SWS_PduR_00119*/
        PDUR_DET_REPORT_ERROR(PDUR_IPDUM_TRANSMIT_APIID, PDUR_E_INVALID_REQUEST);
    }
    else if(id >= PDUR_GET_NUM_IPDUMTXPDU())
    {
        /*SWS_PduR_00221*/
        PDUR_DET_REPORT_ERROR(PDUR_IPDUM_TRANSMIT_APIID, PDUR_E_PDU_ID_INVALID);
    }
    else if(NULL_PTR == info)
    {
        PDUR_DET_REPORT_ERROR(PDUR_IPDUM_TRANSMIT_APIID, PDUR_E_PARAM_POINTER);
    }
    else
    {
#if(PDUR_MAX_NUMOFIPDUMTXPDU > 0)
        SchM_Enter_PduR_PDUR_EXCLUSIVE_AREA_0();

        IpduMTxErrorMask[id] = (PduR_MulticastMaskType)0;
        IpduMTxConfMask[id] = (PduR_MulticastMaskType)0;
        for(i = (PduR_RoutingPathIdType)0; i < PDUR_IPDUM_TXPDUINFO(id).NumPaths; i++)
        {
            PathId = PDUR_IPDUM_TXPDUINFO(id).PathIdx[i];
            ret = PduR_UpTransmit(PathId, info);
            if(ret == E_OK)
            {
                Flag = TRUE;
            }
            else
            {
                /*Set mask as if the wrong path has finished*/
                mask = PDUR_ROUTINGPATHINFO(PathId).ConfMask;
                IpduMTxErrorMask[id] |= mask;
                IpduMTxConfMask[id] |= mask;
            }
        }

        SchM_Exit_PduR_PDUR_EXCLUSIVE_AREA_0();
#endif
    }

    /*SWS_PduR_00218*/
    if(TRUE == Flag)
    {
        ret = E_OK;
    }
    else
    {
        ret = E_NOT_OK;
    }
    return ret;
}
#endif

#if(STD_ON == PDUR_SOMEIP_MODULE_SUPPORT)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: PduR_SomeIpTpTransmit
*
* Description:   Requests transmission of an I-PDU.
*
* Inputs:        id   Identification of the I-PDU.
*                info Length and pointer to the buffer of the I-PDU
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, PDUR_CODE) PduR_SomeIpTpTransmit
(
    PduIdType id,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_CONST) info
)
{
    PduR_RoutingPathIdType i;
    Std_ReturnType ret = E_NOT_OK;
    boolean Flag = FALSE;
    PduR_MulticastMaskType mask;
    PduR_RoutingPathIdType PathId;

    if(!PDUR_IS_INITIALIZED())
    {
        /*SWS_PduR_00328 SWS_PduR_00330 SWS_PduR_00119*/
        PDUR_DET_REPORT_ERROR(PDUR_SOMEIPTP_TRANSMIT_APIID, PDUR_E_INVALID_REQUEST);
    }
    else if(id >= PDUR_GET_NUM_SOMEIPTXPDU())
    {
        /*SWS_PduR_00221*/
        PDUR_DET_REPORT_ERROR(PDUR_SOMEIPTP_TRANSMIT_APIID, PDUR_E_PDU_ID_INVALID);
    }
    else if(NULL_PTR == info)
    {
        PDUR_DET_REPORT_ERROR(PDUR_SOMEIPTP_TRANSMIT_APIID, PDUR_E_PARAM_POINTER);
    }
    else
    {
#if(PDUR_MAX_NUMOFSOMEIPTXPDU > 0)
        SchM_Enter_PduR_PDUR_EXCLUSIVE_AREA_0();

        SomeIpTxErrorMask[id] = (PduR_MulticastMaskType)0;
        SomeIpTxConfMask[id] = (PduR_MulticastMaskType)0;
        for(i = (PduR_RoutingPathIdType)0; i < PDUR_SOMEIP_TXPDUINFO(id).NumPaths; i++)
        {
            PathId = PDUR_SOMEIP_TXPDUINFO(id).PathIdx[i];
            ret = PduR_UpTransmit(PathId, info);
            if(ret == E_OK)
            {
                Flag = TRUE;
            }
            else
            {
                /*Set mask as if the wrong path has finished*/
                mask = PDUR_ROUTINGPATHINFO(PathId).ConfMask;
                SomeIpTxErrorMask[id] |= mask;
                SomeIpTxConfMask[id] |= mask;
            }
        }

        SchM_Exit_PduR_PDUR_EXCLUSIVE_AREA_0();
#endif
    }

    /*SWS_PduR_00218*/
    if(TRUE == Flag)
    {
        ret = E_OK;
    }
    else
    {
        ret = E_NOT_OK;
    }
    return ret;
}
#endif

#if(STD_ON == PDUR_DCM_MODULE_SUPPORT)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: PduR_DcmTransmit    SWS_PduR_00406
*
* Description:     Requests transmission of an I-PDU.
*
* Inputs:         id   Identification of the I-PDU.
*                info Length and pointer to the buffer of the I-PDU
*
* Outputs:         None
*
* Limitations:     None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, PDUR_CODE) PduR_DcmTransmit
(
    PduIdType id,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info
)
{
    PduR_RoutingPathIdType i;
    Std_ReturnType ret = E_NOT_OK;
    boolean Flag = FALSE;
    PduR_MulticastMaskType mask;
    PduR_RoutingPathIdType PathId;

    if(!PDUR_IS_INITIALIZED())
    {
        /*SWS_PduR_00328 SWS_PduR_00330 SWS_PduR_00119*/
        PDUR_DET_REPORT_ERROR(PDUR_DCM_TRANSMIT_APIID, PDUR_E_INVALID_REQUEST);
    }
    else if(id >= PDUR_GET_NUM_DCMTXPDU())
    {
        /*SWS_PduR_00221*/
        PDUR_DET_REPORT_ERROR(PDUR_DCM_TRANSMIT_APIID, PDUR_E_PDU_ID_INVALID);
    }
    else if(NULL_PTR == info)
    {
        PDUR_DET_REPORT_ERROR(PDUR_DCM_TRANSMIT_APIID, PDUR_E_PARAM_POINTER);
    }
    else
    {
#if(PDUR_MAX_NUMOFDCMTXPDU > 0)
        SchM_Enter_PduR_PDUR_EXCLUSIVE_AREA_0();

        DcmTxErrorMask[id] = 0;
        DcmTxConfMask[id] = 0;
        for(i = 0; i < PDUR_DCM_TXPDUINFO(id).NumPaths; i++)
        {
            PathId = PDUR_DCM_TXPDUINFO(id).PathIdx[i];
            ret = PduR_UpTransmit(PathId, info);
            if(ret == E_OK)
            {
                Flag = TRUE;
            }
            else
            {
                /*Set mask as if the wrong path has finished*/
                mask = PDUR_ROUTINGPATHINFO(PathId).ConfMask;
                DcmTxErrorMask[id] |= mask;
                DcmTxConfMask[id] |= mask;
            }
        }

        SchM_Exit_PduR_PDUR_EXCLUSIVE_AREA_0();
#endif
    }

    /*SWS_PduR_00218*/
    if(TRUE == Flag)
    {
        ret = E_OK;
    }
    else
    {
        ret = E_NOT_OK;
    }
    return ret;
}

#if(STD_ON == PDUR_DCM_CANCELTRANSMIT_ENABLED)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: PduR_DcmCancelTransmit     SWS_PduR_00769
*
* Description:     Request for cancellation of an ongoing transmission of an I-Pdu
*                in transport protocol or communication interface.
*
* Inputs:         id   Identification of the I-PDU to be cancelled.
*
*
* Outputs:         None
*
* Limitations:     None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, PDUR_CODE) PduR_DcmCancelTransmit
(
    PduIdType id
)
{
    Std_ReturnType ret = E_NOT_OK;
    PduR_RoutingPathIdType i;
    boolean ErrorFlag = FALSE;

    if(!PDUR_IS_INITIALIZED())
    {
        /*SWS_PduR_00328 SWS_PduR_00330 SWS_PduR_00119*/
        PDUR_DET_REPORT_ERROR(PDUR_DCM_CANCEL_TRANSMIT_APIID, PDUR_E_INVALID_REQUEST);
    }
    else if(id >= PDUR_GET_NUM_DCMTXPDU())
    {
        /*SWS_PduR_00221*/
        PDUR_DET_REPORT_ERROR(PDUR_DCM_CANCEL_TRANSMIT_APIID, PDUR_E_PDU_ID_INVALID);
    }
    else
    {
        SchM_Enter_PduR_PDUR_EXCLUSIVE_AREA_0();
        for(i = 0; i < PDUR_DCM_TXPDUINFO(id).NumPaths; i++)
        {
            ret = PduR_UpCancelTransmit(PDUR_DCM_TXPDUINFO(id).PathIdx[i]);

            if(ret != E_OK)
            {
                ErrorFlag = TRUE;
            }
        }
        SchM_Exit_PduR_PDUR_EXCLUSIVE_AREA_0();
    }

    /*SWS_PduR_00701*/
    if(ErrorFlag)
    {
        ret = E_NOT_OK;
    }
    else
    {
        ret = E_OK;
    }
    return ret;
}
#endif

#if(STD_ON == PDUR_DCM_CHANGEPARAMETER_API_ENABLED)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: PduR_DcmChangeParameter     SWS_PduR_00482
*
* Description:     Request to change a specific transport protocol parameter
*                (e.g. block-size). The affected transport protocol module is
*                selected using the I-PDU ID.
*
* Inputs:         id   Identification of the I-PDU to which the parameter the request shall affect.
*                parameter  The selected parameter that the request shall changed.
*                value   The value that the request shall change to.
*
*
* Outputs:         None
*
* Limitations:     None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, PDUR_CODE) PduR_DcmChangeParameter
(
    PduIdType id,
    TPParameterType parameter,
    uint16 value
)
{
    Std_ReturnType ret = E_NOT_OK;

    if(!PDUR_IS_INITIALIZED())
    {
        /*SWS_PduR_00328 SWS_PduR_00330 SWS_PduR_00119*/
        PDUR_DET_REPORT_ERROR(PDUR_DCM_CHANGEPARAMETER_APIID, PDUR_E_INVALID_REQUEST);
    }
    else if(id >= PDUR_GET_NUM_DCMRXPDU())
    {
        /*SWS_PduR_00221*/
        PDUR_DET_REPORT_ERROR(PDUR_DCM_CHANGEPARAMETER_APIID, PDUR_E_PDU_ID_INVALID);
    }
    else
    {
        SchM_Enter_PduR_PDUR_EXCLUSIVE_AREA_0();
        /*SWS_PduR_00747*/
        ret = PduR_UpChangeParameter(PDUR_DCM_CANCELRXPDUINFO(id).PathId, parameter, value);
        SchM_Exit_PduR_PDUR_EXCLUSIVE_AREA_0();
    }

    return ret;
}
#endif

#if(STD_ON == PDUR_DCM_CANCELRECEIVE_ENABLED)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: PduR_DcmCancelReceive   SWS_PduR_00767
*
* Description:     Requests for cancellation of an ongoing reception of an I-Pdu
*                in transport protocol
*
* Inputs:         id   Identification of the I-PDU.
*
*
* Outputs:         None
*
* Limitations:     None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, PDUR_CODE) PduR_DcmCancelReceive
(
    PduIdType id
)
{
    Std_ReturnType ret = E_NOT_OK;

    if(!PDUR_IS_INITIALIZED())
    {
        /*SWS_PduR_00328 SWS_PduR_00330 SWS_PduR_00119*/
        PDUR_DET_REPORT_ERROR(PDUR_DCM_CANCEL_RECEIVE_APIID, PDUR_E_INVALID_REQUEST);
    }
    else if(id >= PDUR_GET_NUM_DCMRXPDU())
    {
        /*SWS_PduR_00221*/
        PDUR_DET_REPORT_ERROR(PDUR_DCM_CANCEL_RECEIVE_APIID, PDUR_E_PDU_ID_INVALID);
    }
    else
    {
        SchM_Enter_PduR_PDUR_EXCLUSIVE_AREA_0();
        /*SWS_PduR_00736*/
        ret = PduR_UpCancelReceive(PDUR_DCM_CANCELRXPDUINFO(id).PathId);
        SchM_Exit_PduR_PDUR_EXCLUSIVE_AREA_0();
    }
    return ret;
}
#endif
#endif

#if(STD_ON == PDUR_J1939DCM_MODULE_SUPPORT)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: PduR_J1939DcmTransmit    SWS_PduR_00406
*
* Description:     Requests transmission of an I-PDU.
*
* Inputs:         id   Identification of the I-PDU.
*                info Length and pointer to the buffer of the I-PDU
*
* Outputs:         None
*
* Limitations:     None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, PDUR_CODE) PduR_J1939DcmTransmit
(
    PduIdType id,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info
)
{
    PduR_RoutingPathIdType i;
    Std_ReturnType ret = E_NOT_OK;
    boolean Flag = FALSE;
    PduR_MulticastMaskType mask;
    PduR_RoutingPathIdType PathId;

    if(!PDUR_IS_INITIALIZED())
    {
        /*SWS_PduR_00328 SWS_PduR_00330 SWS_PduR_00119*/
        PDUR_DET_REPORT_ERROR(PDUR_J1939DCM_TRANSMIT_APIID, PDUR_E_INVALID_REQUEST);
    }
    else if(id >= PDUR_GET_NUM_J1939DCMTXPDU())
    {
        /*SWS_PduR_00221*/
        PDUR_DET_REPORT_ERROR(PDUR_J1939DCM_TRANSMIT_APIID, PDUR_E_PDU_ID_INVALID);
    }
    else if(NULL_PTR == info)
    {
        PDUR_DET_REPORT_ERROR(PDUR_J1939DCM_TRANSMIT_APIID, PDUR_E_PARAM_POINTER);
    }
    else
    {
#if(PDUR_MAX_NUMOFJ1939DCMTXPDU > 0)
        SchM_Enter_PduR_PDUR_EXCLUSIVE_AREA_0();

        J1939DcmTxErrorMask[id] = 0;
        J1939DcmTxConfMask[id] = 0;
        for(i = 0; i < PDUR_J1939DCM_TXPDUINFO(id).NumPaths; i++)
        {
            PathId = PDUR_J1939DCM_TXPDUINFO(id).PathIdx[i];
            ret = PduR_UpTransmit(PathId, info);
            if(ret == E_OK)
            {
                Flag = TRUE;
            }
            else
            {
                /*Set mask as if the wrong path has finished*/
                mask = PDUR_ROUTINGPATHINFO(PathId).ConfMask;
                J1939DcmTxErrorMask[id] |= mask;
                J1939DcmTxConfMask[id] |= mask;
            }
        }

        SchM_Exit_PduR_PDUR_EXCLUSIVE_AREA_0();
#endif
    }

    /*SWS_PduR_00218*/
    if(TRUE == Flag)
    {
        ret = E_OK;
    }
    else
    {
        ret = E_NOT_OK;
    }
    return ret;
}

#if(STD_ON == PDUR_J1939DCM_CANCELTRANSMIT_ENABLED)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: PduR_J1939DcmCancelTransmit     SWS_PduR_00769
*
* Description:     Request for cancellation of an ongoing transmission of an I-Pdu
*                in transport protocol or communication interface.
*
* Inputs:         id   Identification of the I-PDU to be cancelled.
*
*
* Outputs:         None
*
* Limitations:     None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, PDUR_CODE) PduR_J1939DcmCancelTransmit
(
    PduIdType id
)
{
    Std_ReturnType ret = E_NOT_OK;
    PduR_RoutingPathIdType i;
    boolean ErrorFlag = FALSE;

    if(!PDUR_IS_INITIALIZED())
    {
        /*SWS_PduR_00328 SWS_PduR_00330 SWS_PduR_00119*/
        PDUR_DET_REPORT_ERROR(PDUR_J1939DCM_CANCEL_TRANSMIT_APIID, PDUR_E_INVALID_REQUEST);
    }
    else if(id >= PDUR_GET_NUM_J1939DCMTXPDU())
    {
        /*SWS_PduR_00221*/
        PDUR_DET_REPORT_ERROR(PDUR_J1939DCM_CANCEL_TRANSMIT_APIID, PDUR_E_PDU_ID_INVALID);
    }
    else
    {
        SchM_Enter_PduR_PDUR_EXCLUSIVE_AREA_0();
        for(i = 0; i < PDUR_J1939DCM_TXPDUINFO(id).NumPaths; i++)
        {
            ret = PduR_UpCancelTransmit(PDUR_J1939DCM_TXPDUINFO(id).PathIdx[i]);

            if(ret != E_OK)
            {
                ErrorFlag = TRUE;
            }
        }
        SchM_Exit_PduR_PDUR_EXCLUSIVE_AREA_0();
    }

    /*SWS_PduR_00701*/
    if(ErrorFlag)
    {
        ret = E_NOT_OK;
    }
    else
    {
        ret = E_OK;
    }
    return ret;
}
#endif

#if(STD_ON == PDUR_J1939DCM_CANCELRECEIVE_ENABLED)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: PduR_J1939DcmCancelReceive   SWS_PduR_00767
*
* Description:     Requests for cancellation of an ongoing reception of an I-Pdu
*                in transport protocol
*
* Inputs:         id   Identification of the I-PDU.
*
*
* Outputs:         None
*
* Limitations:     None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, PDUR_CODE) PduR_J1939DcmCancelReceive
(
    PduIdType id
)
{
    Std_ReturnType ret = E_NOT_OK;

    if(!PDUR_IS_INITIALIZED())
    {
        /*SWS_PduR_00328 SWS_PduR_00330 SWS_PduR_00119*/
        PDUR_DET_REPORT_ERROR(PDUR_J1939DCM_CANCEL_RECEIVE_APIID, PDUR_E_INVALID_REQUEST);
    }
    else if(id >= PDUR_GET_NUM_J1939DCMRXPDU())
    {
        /*SWS_PduR_00221*/
        PDUR_DET_REPORT_ERROR(PDUR_J1939DCM_CANCEL_RECEIVE_APIID, PDUR_E_PDU_ID_INVALID);
    }
    else
    {
        SchM_Enter_PduR_PDUR_EXCLUSIVE_AREA_0();
        /*SWS_PduR_00736*/
        ret = PduR_UpCancelReceive(PDUR_J1939DCM_CANCELRXPDUINFO(id).PathId);
        SchM_Exit_PduR_PDUR_EXCLUSIVE_AREA_0();
    }
    return ret;
}
#endif
#endif

#if(STD_ON == PDUR_J1939RM_MODULE_SUPPORT)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: PduR_J1939RmTransmit    SWS_PduR_00406
*
* Description:     Requests transmission of an I-PDU.
*
* Inputs:         id   Identification of the I-PDU.
*                info Length and pointer to the buffer of the I-PDU
*
* Outputs:         None
*
* Limitations:     None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, PDUR_CODE) PduR_J1939RmTransmit
(
    PduIdType id,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info
)
{
    PduR_RoutingPathIdType i;
    Std_ReturnType ret = E_NOT_OK;
    boolean Flag = FALSE;
    PduR_MulticastMaskType mask;
    PduR_RoutingPathIdType PathId;

    if(!PDUR_IS_INITIALIZED())
    {
        /*SWS_PduR_00328 SWS_PduR_00330 SWS_PduR_00119*/
        PDUR_DET_REPORT_ERROR(PDUR_J1939RM_TRANSMIT_APIID, PDUR_E_INVALID_REQUEST);
    }
    else if(id >= PDUR_GET_NUM_J1939RMTXPDU())
    {
        /*SWS_PduR_00221*/
        PDUR_DET_REPORT_ERROR(PDUR_J1939RM_TRANSMIT_APIID, PDUR_E_PDU_ID_INVALID);
    }
    else if(NULL_PTR == info)
    {
        PDUR_DET_REPORT_ERROR(PDUR_J1939RM_TRANSMIT_APIID, PDUR_E_PARAM_POINTER);
    }
    else
    {
#if(PDUR_MAX_NUMOFJ1939RMTXPDU > 0)
        SchM_Enter_PduR_PDUR_EXCLUSIVE_AREA_0();

        J1939RmTxErrorMask[id] = 0;
        J1939RmTxConfMask[id] = 0;
        for(i = 0; i < PDUR_J1939RM_TXPDUINFO(id).NumPaths; i++)
        {
            PathId = PDUR_J1939RM_TXPDUINFO(id).PathIdx[i];
            ret = PduR_UpTransmit(PathId, info);
            if(ret == E_OK)
            {
                Flag = TRUE;
            }
            else
            {
                /*Set mask as if the wrong path has finished*/
                mask = PDUR_ROUTINGPATHINFO(PathId).ConfMask;
                J1939RmTxErrorMask[id] |= mask;
                J1939RmTxConfMask[id] |= mask;
            }
        }

        SchM_Exit_PduR_PDUR_EXCLUSIVE_AREA_0();
#endif
    }

    /*SWS_PduR_00218*/
    if(TRUE == Flag)
    {
        ret = E_OK;
    }
    else
    {
        ret = E_NOT_OK;
    }
    return ret;
}
#endif

#if(STD_ON == PDUR_CDD_MODULE_SUPPORT)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: PduR_CddTransmit    SWS_PduR_00406
*
* Description:     Requests transmission of an I-PDU.
*
* Inputs:         id   Identification of the I-PDU.
*                info Length and pointer to the buffer of the I-PDU
*
* Outputs:         None
*
* Limitations:     None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, PDUR_CODE) PduR_CddTransmit
(
    PduIdType id,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_CONST) info
)
{
    PduR_RoutingPathIdType i;
    Std_ReturnType ret = E_NOT_OK;
    boolean Flag = FALSE;
    PduR_MulticastMaskType mask;
    PduR_RoutingPathIdType PathId;

    if(!PDUR_IS_INITIALIZED())
    {
        /*SWS_PduR_00328 SWS_PduR_00330 SWS_PduR_00119*/
        PDUR_DET_REPORT_ERROR(PDUR_CDD_TRANSMIT_APIID, PDUR_E_INVALID_REQUEST);
    }
    else if(id >= PDUR_GET_NUM_CDDTXPDU())
    {
        /*SWS_PduR_00221*/
        PDUR_DET_REPORT_ERROR(PDUR_CDD_TRANSMIT_APIID, PDUR_E_PDU_ID_INVALID);
    }
    else if(NULL_PTR == info)
    {
        PDUR_DET_REPORT_ERROR(PDUR_CDD_TRANSMIT_APIID, PDUR_E_PARAM_POINTER);
    }
    else
    {
#if(PDUR_MAX_NUMOFCDDTXPDU > 0)
        SchM_Enter_PduR_PDUR_EXCLUSIVE_AREA_0();

        CddTxErrorMask[id] = 0;
        CddTxConfMask[id] = 0;
        for(i = 0; i < PDUR_CDD_TXPDUINFO(id).NumPaths; i++)
        {
            PathId = PDUR_CDD_TXPDUINFO(id).PathIdx[i];
            ret = PduR_UpTransmit(PathId, info);
            if(ret == E_OK)
            {
                Flag = TRUE;
            }
            else
            {
                /*Set mask as if the wrong path has finished*/
                mask = PDUR_ROUTINGPATHINFO(PathId).ConfMask;
                CddTxErrorMask[id] |= mask;
                CddTxConfMask[id] |= mask;
            }
        }

        SchM_Exit_PduR_PDUR_EXCLUSIVE_AREA_0();
#endif
    }

    if(TRUE == Flag)
    {
        ret = E_OK;
    }
    else
    {
        ret = E_NOT_OK;
    }

    return ret;
}

#if(STD_ON == PDUR_CDD_CANCELTRANSMIT_ENABLED)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: PduR_CddCancelTransmit     SWS_PduR_00769
*
* Description:     Request for cancellation of an ongoing transmission of an I-Pdu
*                in transport protocol or communication interface.
*
* Inputs:         id   Identification of the I-PDU to be cancelled.
*
*
* Outputs:         None
*
* Limitations:     None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, PDUR_CODE) PduR_CddCancelTransmit
(
    PduIdType id
)
{
    Std_ReturnType ret = E_NOT_OK;
    PduR_RoutingPathIdType idx;
    PduR_RoutingPathIdType i;
    PduIdType dstid;
    boolean ErrorFlag = FALSE;

    if(!PDUR_IS_INITIALIZED())
    {
        /*SWS_PduR_00328 SWS_PduR_00330 SWS_PduR_00119*/
        PDUR_DET_REPORT_ERROR(PDUR_CDD_CANCEL_TRANSMIT_APIID, PDUR_E_INVALID_REQUEST);
    }
    else if(id >= PDUR_GET_NUM_CDDTXPDU())
    {
        /*SWS_PduR_00221*/
        PDUR_DET_REPORT_ERROR(PDUR_CDD_CANCEL_TRANSMIT_APIID, PDUR_E_PDU_ID_INVALID);
    }
    else
    {
        SchM_Enter_PduR_PDUR_EXCLUSIVE_AREA_0();
        for(i = 0; i < PDUR_CDD_TXPDUINFO(id).NumPaths; i++)
        {
            ret = PduR_UpCancelTransmit(PDUR_CDD_TXPDUINFO(id).PathIdx[i]);

            if(ret != E_OK)
            {
                ErrorFlag = TRUE;
            }
        }
        SchM_Exit_PduR_PDUR_EXCLUSIVE_AREA_0();
    }

    /*SWS_PduR_00701*/
    if(ErrorFlag)
    {
        ret = E_NOT_OK;
    }
    else
    {
        ret = E_OK;
    }
    return ret;
}
#endif

#if(STD_ON == PDUR_CDD_CHANGEPARAMETER_API_ENABLED)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: PduR_CddChangeParameter     SWS_PduR_00482
*
* Description:     Request to change a specific transport protocol parameter
*                (e.g. block-size). The affected transport protocol module is
*                selected using the I-PDU ID.
*
* Inputs:         id   Identification of the I-PDU to which the parameter the request shall affect.
*                parameter  The selected parameter that the request shall changed.
*                value   The value that the request shall change to.
*
*
* Outputs:         None
*
* Limitations:     None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, PDUR_CODE) PduR_CddChangeParameter
(
    PduIdType id,
    TPParameterType parameter,
    uint16 value
)
{
    Std_ReturnType ret = E_NOT_OK;

    if(!PDUR_IS_INITIALIZED())
    {
        /*SWS_PduR_00328 SWS_PduR_00330 SWS_PduR_00119*/
        PDUR_DET_REPORT_ERROR(PDUR_CDD_CHANGEPARAMETER_APIID, PDUR_E_INVALID_REQUEST);
    }
    else if(id >= PDUR_GET_NUM_CDDRXPDU())
    {
        /*SWS_PduR_00221*/
        PDUR_DET_REPORT_ERROR(PDUR_CDD_CHANGEPARAMETER_APIID, PDUR_E_PDU_ID_INVALID);
    }
    else
    {
#if(PDUR_MAX_NUMOFCDDTPRXPDU > 0)
        SchM_Enter_PduR_PDUR_EXCLUSIVE_AREA_0();
        /*SWS_PduR_00747*/
        ret = PduR_UpChangeParameter(PDUR_CDD_CANCELRXPDUINFO(id).PathId, parameter, value);
        SchM_Exit_PduR_PDUR_EXCLUSIVE_AREA_0();
#endif
    }

    return ret;
}
#endif

#if(STD_ON == PDUR_CDD_CANCELRECEIVE_ENABLED)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: PduR_CddCancelReceive   SWS_PduR_00767
*
* Description:     Requests for cancellation of an ongoing reception of an I-Pdu
*                in transport protocol
*
* Inputs:         id   Identification of the I-PDU.
*
*
* Outputs:         None
*
* Limitations:     None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, PDUR_CODE) PduR_CddCancelReceive
(
    PduIdType id
)
{
    Std_ReturnType ret = E_NOT_OK;
    PduIdType srcId;
    PduR_RoutingPathIdType idx;

    if(!PDUR_IS_INITIALIZED())
    {
        /*SWS_PduR_00328 SWS_PduR_00330 SWS_PduR_00119*/
        PDUR_DET_REPORT_ERROR(PDUR_CDD_CANCEL_RECEIVE_APIID, PDUR_E_INVALID_REQUEST);
    }
    else if(id >= PDUR_GET_NUM_CDDRXPDU())
    {
        /*SWS_PduR_00221*/
        PDUR_DET_REPORT_ERROR(PDUR_CDD_CANCEL_RECEIVE_APIID, PDUR_E_PDU_ID_INVALID);
    }
    else
    {
#if(PDUR_MAX_NUMOFCDDIFRXPDU > 0)
        SchM_Enter_PduR_PDUR_EXCLUSIVE_AREA_0();
        /*SWS_PduR_00736*/
        ret = PduR_UpCancelReceive(PDUR_CDD_CANCELRXPDUINFO(id).PathId);
        SchM_Exit_PduR_PDUR_EXCLUSIVE_AREA_0();
#endif
    }
    return ret;
}
#endif
#endif

#if(STD_ON == PDUR_IPDUM_MODULE_SUPPORT)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: PduR_IpduMRxIndication SWS_PduR_00362
*
* Description:     Indication of a received I-PDU from a lower layer communication module.
*
* Inputs:         RxPduId   Identification of the transmitted I-PDU.
*                 PduInfoPtr Contains the length (SduLength) of the received I-PDU
*                           and a pointer to a buffer (SduDataPtr) containing the I-PDU.
*
* Outputs:         None
*
* Limitations:     None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, PDUR_CODE) PduR_IpduMRxIndication
(
    PduIdType RxPduId,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_CONST) PduInfoPtr
)
{
    P2CONST(PduRRoutingPduInfoType, AUTOMATIC, PDUR_CONST) pRxPduInfo;

    if(!PDUR_IS_INITIALIZED())
    {
        /*SWS_PduR_00328 SWS_PduR_00330 SWS_PduR_00119*/
        PDUR_DET_REPORT_ERROR(PDUR_IPDUM_RXINDICATION_APIID, PDUR_E_INVALID_REQUEST);
    }
    else if(RxPduId >= PDUR_GET_NUM_IPDUMIFRXPDU())
    {
        /*SWS_PduR_00221*/
        PDUR_DET_REPORT_ERROR(PDUR_IPDUM_RXINDICATION_APIID, PDUR_E_PDU_ID_INVALID);
    }
    else if(NULL_PTR == PduInfoPtr)
    {
        PDUR_DET_REPORT_ERROR(PDUR_IPDUM_RXINDICATION_APIID, PDUR_E_PARAM_POINTER);
    }
    else
    {
#if(PDUR_MAX_NUMOFIPDUMIFRXPDU > 0)
        SchM_Enter_PduR_PDUR_EXCLUSIVE_AREA_0();
        pRxPduInfo = &(PDUR_IPDUMIF_RXPDUINFO(RxPduId));
        PduR_LowerIfMultiRxIndication(pRxPduInfo, PduInfoPtr);
        SchM_Exit_PduR_PDUR_EXCLUSIVE_AREA_0();
#endif
    }

}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: PduR_IpduMTxConfirmation    SWS_PduR_00365
*
* Description:     The lower layer communication module confirms the transmission
*                of an I-PDU.
*
* Inputs:         TxPduId   ID of the I-PDU that has been transmitted.
*
* Outputs:         None
*
* Limitations:     None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, PDUR_CODE) PduR_IpduMTxConfirmation
(
    PduIdType TxPduId
)
{
    PduR_RoutingPathIdType PathId;
    PduR_RoutingPathGroupIdType GroupId;

    if(!PDUR_IS_INITIALIZED())
    {
        /*SWS_PduR_00328 SWS_PduR_00330 SWS_PduR_00119*/
        PDUR_DET_REPORT_ERROR(PDUR_IPDUM_TXCONFIRMATION_APIID, PDUR_E_INVALID_REQUEST);
    }
    else if(TxPduId >= PDUR_GET_NUM_IPDUMIFTXPDU())
    {
        /*SWS_PduR_00221*/
        PDUR_DET_REPORT_ERROR(PDUR_IPDUM_TXCONFIRMATION_APIID, PDUR_E_PDU_ID_INVALID);
    }
    else
    {
#if(PDUR_MAX_NUMOFIPDUMIFTXPDU > 0)
        SchM_Enter_PduR_PDUR_EXCLUSIVE_AREA_0();
        PathId = PDUR_IPDUMIF_TXCONFPDUINFO(TxPduId).PathId;
        GroupId = PDUR_ROUTINGPATHINFO(PathId).PduRDestPdu.PduRRoutingGroup;
        if((PDUR_RPGROUP_NONE == GroupId) || (TRUE == PduR_RoutingPathGroupEnabled[GroupId]))
        {
            PduR_LowerIfTxConfirmation(PathId, PDUR_IPDUMIF_TXCONFPDUINFO(TxPduId).UpperPduId);
        }
        SchM_Exit_PduR_PDUR_EXCLUSIVE_AREA_0();
#endif
    }
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: PduR_IpduMTriggerTransmit    SWS_PduR_00369
*
* Description:     The lower layer communication module requests the buffer of the
*                SDU for transmission from the upper layer module.
*
* Inputs:         TxPduId   ID of the SDU that is requested to be transmitted.
*                PduInfoPtr Contains a pointer to a buffer (SduDataPtr) to where
*                           the SDU shall be copied to. On return, the service will
*                           indicate the length of the copied SDU data in SduLength
*
* Outputs:         None
*
* Limitations:     None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, PDUR_CODE) PduR_IpduMTriggerTransmit
(
    PduIdType TxPduId,
    P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) PduInfoPtr
)
{
    Std_ReturnType ret = E_NOT_OK;
#if(PDUR_MAX_NUMOFIPDUMIFTXPDU > 0)
    PduR_RoutingPathIdType PathId;
    PduR_RoutingPathGroupIdType GroupId;
#endif

    if(!PDUR_IS_INITIALIZED())
    {
        /*SWS_PduR_00328 SWS_PduR_00330 SWS_PduR_00119*/
        PDUR_DET_REPORT_ERROR(PDUR_IPDUM_TRIGGERTRANSMIT_APIID, PDUR_E_INVALID_REQUEST);
    }
    else if(TxPduId >= PDUR_GET_NUM_IPDUMIFTXPDU())
    {
        /*SWS_PduR_00221*/
        PDUR_DET_REPORT_ERROR(PDUR_IPDUM_TRIGGERTRANSMIT_APIID, PDUR_E_PDU_ID_INVALID);
    }
    else if(NULL_PTR == PduInfoPtr)
    {
        PDUR_DET_REPORT_ERROR(PDUR_IPDUM_TRIGGERTRANSMIT_APIID, PDUR_E_PARAM_POINTER);
    }
    else
    {
#if(PDUR_MAX_NUMOFIPDUMIFTXPDU > 0)
        SchM_Enter_PduR_PDUR_EXCLUSIVE_AREA_0();
        PathId = PDUR_IPDUMIF_TXCONFPDUINFO(TxPduId).PathId;
        GroupId = PDUR_ROUTINGPATHINFO(PathId).PduRDestPdu.PduRRoutingGroup;
        if((PDUR_RPGROUP_NONE == GroupId) || (TRUE == PduR_RoutingPathGroupEnabled[GroupId]))
        {
            ret = PduR_LowerIfTriggerTransmit(PathId, PDUR_IPDUMIF_TXCONFPDUINFO(TxPduId).UpperPduId, PduInfoPtr);
        }
        SchM_Exit_PduR_PDUR_EXCLUSIVE_AREA_0();
#endif
    }

    return ret;
}
#endif

#if(STD_ON == PDUR_CANIF_MODULE_SUPPORT)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: PduR_CanIfRxIndication SWS_PduR_00362
*
* Description:     Indication of a received I-PDU from a lower layer communication module.
*
* Inputs:         RxPduId   Identification of the transmitted I-PDU.
*                 PduInfoPtr Contains the length (SduLength) of the received I-PDU
*                           and a pointer to a buffer (SduDataPtr) containing the I-PDU.
*
* Outputs:         None
*
* Limitations:     None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, PDUR_CODE) PduR_CanIfRxIndication
(
    PduIdType RxPduId,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_CONST) PduInfoPtr
)
{
    P2CONST(PduRRoutingPduInfoType, AUTOMATIC, PDUR_CONST) pRxPduInfo;

    if(!PDUR_IS_INITIALIZED())
    {
        /*SWS_PduR_00328 SWS_PduR_00330 SWS_PduR_00119*/
        PDUR_DET_REPORT_ERROR(PDUR_CANIF_RXINDICATION_APIID, PDUR_E_INVALID_REQUEST);
    }
    else if(RxPduId >= PDUR_GET_NUM_CANIFRXPDU())
    {
        /*SWS_PduR_00221*/
        PDUR_DET_REPORT_ERROR(PDUR_CANIF_RXINDICATION_APIID, PDUR_E_PDU_ID_INVALID);
    }
    else if(NULL_PTR == PduInfoPtr)
    {
        PDUR_DET_REPORT_ERROR(PDUR_CANIF_RXINDICATION_APIID, PDUR_E_PARAM_POINTER);
    }
    else
    {
#if(PDUR_MAX_NUMOFCANIFRXPDU > 0)
        SchM_Enter_PduR_PDUR_EXCLUSIVE_AREA_0();
        pRxPduInfo = &(PDUR_CANIF_RXPDUINFO(RxPduId));
        PduR_LowerIfMultiRxIndication(pRxPduInfo, PduInfoPtr);
        SchM_Exit_PduR_PDUR_EXCLUSIVE_AREA_0();
#endif
    }

}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: PduR_CanIfTxConfirmation    SWS_PduR_00365
*
* Description:     The lower layer communication module confirms the transmission
*                of an I-PDU.
*
* Inputs:         TxPduId   ID of the I-PDU that has been transmitted.
*
* Outputs:         None
*
* Limitations:     None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, PDUR_CODE) PduR_CanIfTxConfirmation
(
    PduIdType TxPduId
)
{
    PduR_RoutingPathIdType PathId;
    PduR_RoutingPathGroupIdType GroupId;

    if(!PDUR_IS_INITIALIZED())
    {
        /*SWS_PduR_00328 SWS_PduR_00330 SWS_PduR_00119*/
        PDUR_DET_REPORT_ERROR(PDUR_CANIF_TXCONFIRMATION_APIID, PDUR_E_INVALID_REQUEST);
    }
    else if(TxPduId >= PDUR_GET_NUM_CANIFTXPDU())
    {
        /*SWS_PduR_00221*/
        PDUR_DET_REPORT_ERROR(PDUR_CANIF_TXCONFIRMATION_APIID, PDUR_E_PDU_ID_INVALID);
    }
    else
    {
#if(PDUR_MAX_NUMOFCANIFTXPDU > 0)
        SchM_Enter_PduR_PDUR_EXCLUSIVE_AREA_0();
        PathId = PDUR_CANIF_TXCONFPDUINFO(TxPduId).PathId;
        GroupId = PDUR_ROUTINGPATHINFO(PathId).PduRDestPdu.PduRRoutingGroup;
        if((PDUR_RPGROUP_NONE == GroupId) || (TRUE == PduR_RoutingPathGroupEnabled[GroupId]))
        {
            PduR_LowerIfTxConfirmation(PathId, PDUR_CANIF_TXCONFPDUINFO(TxPduId).UpperPduId);
        }
        SchM_Exit_PduR_PDUR_EXCLUSIVE_AREA_0();
#endif
    }
}
#endif

#if(STD_ON == PDUR_LINIF_MODULE_SUPPORT)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: PduR_LinIfRxIndication SWS_PduR_00362
*
* Description:     Indication of a received I-PDU from a lower layer communication module.
*
* Inputs:         RxPduId   Identification of the transmitted I-PDU.
*                 PduInfoPtr Contains the length (SduLength) of the received I-PDU
*                            and a pointer to a buffer (SduDataPtr) containing the I-PDU.
*
* Outputs:         None
*
* Limitations:     None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, PDUR_CODE) PduR_LinIfRxIndication
(
    PduIdType RxPduId,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_CONST) PduInfoPtr
)
{
#if(PDUR_MAX_NUMOFLINIFRXPDU > 0)
    P2CONST(PduRRoutingPduInfoType, AUTOMATIC, PDUR_CONST) pRxPduInfo;
#endif

    if(!PDUR_IS_INITIALIZED())
    {
        /*SWS_PduR_00328 SWS_PduR_00330 SWS_PduR_00119*/
        PDUR_DET_REPORT_ERROR(PDUR_LINIF_RXINDICATION_APIID, PDUR_E_INVALID_REQUEST);
    }
    else if(RxPduId >= PDUR_GET_NUM_LINIFRXPDU())
    {
        /*SWS_PduR_00221*/
        PDUR_DET_REPORT_ERROR(PDUR_LINIF_RXINDICATION_APIID, PDUR_E_PDU_ID_INVALID);
    }
    else if(NULL_PTR == PduInfoPtr)
    {
        PDUR_DET_REPORT_ERROR(PDUR_LINIF_RXINDICATION_APIID, PDUR_E_PARAM_POINTER);
    }
    else
    {
#if(PDUR_MAX_NUMOFLINIFRXPDU > 0)
        SchM_Enter_PduR_PDUR_EXCLUSIVE_AREA_0();
        pRxPduInfo = &(PDUR_LINIF_RXPDUINFO(RxPduId));
        PduR_LowerIfMultiRxIndication(pRxPduInfo, PduInfoPtr);
        SchM_Exit_PduR_PDUR_EXCLUSIVE_AREA_0();
#endif
    }
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: PduR_LinIfTxConfirmation    SWS_PduR_00365
*
* Description:     The lower layer communication module confirms the transmission
*                of an I-PDU.
*
* Inputs:         TxPduId   ID of the I-PDU that has been transmitted.
*
* Outputs:         bufferSizePtr    Available receive buffer after data has been copied.
*
* Limitations:     None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, PDUR_CODE) PduR_LinIfTxConfirmation
(
    PduIdType TxPduId
)
{
#if(PDUR_MAX_NUMOFLINIFTXPDU > 0)
    PduR_RoutingPathIdType PathId;
    PduR_RoutingPathGroupIdType GroupId;
#endif

    if(!PDUR_IS_INITIALIZED())
    {
        /*SWS_PduR_00328 SWS_PduR_00330 SWS_PduR_00119*/
        PDUR_DET_REPORT_ERROR(PDUR_LINIF_TXCONFIRMATION_APIID, PDUR_E_INVALID_REQUEST);
    }
    else if(TxPduId >= PDUR_GET_NUM_LINIFTXPDU())
    {
        /*SWS_PduR_00221*/
        PDUR_DET_REPORT_ERROR(PDUR_LINIF_TXCONFIRMATION_APIID, PDUR_E_PDU_ID_INVALID);
    }
    else
    {
#if(PDUR_MAX_NUMOFLINIFTXPDU > 0)
        SchM_Enter_PduR_PDUR_EXCLUSIVE_AREA_0();
        PathId = PDUR_LINIF_TXCONFPDUINFO(TxPduId).PathId;
        GroupId = PDUR_ROUTINGPATHINFO(PathId).PduRDestPdu.PduRRoutingGroup;
        if((PDUR_RPGROUP_NONE == GroupId) || (TRUE == PduR_RoutingPathGroupEnabled[GroupId]))
        {
            PduR_LowerIfTxConfirmation(PathId, PDUR_LINIF_TXCONFPDUINFO(TxPduId).UpperPduId);
        }
        SchM_Exit_PduR_PDUR_EXCLUSIVE_AREA_0();
#endif
    }
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: PduR_LinIfTriggerTransmit    SWS_PduR_00369
*
* Description:     The lower layer communication module requests the buffer of the
*                SDU for transmission from the upper layer module.
*
* Inputs:         TxPduId   ID of the SDU that is requested to be transmitted.
*                PduInfoPtr Contains a pointer to a buffer (SduDataPtr) to where
*                           the SDU shall be copied to. On return, the service will
*                           indicate the length of the copied SDU data in SduLength
*
* Outputs:         None
*
* Limitations:     None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, PDUR_CODE) PduR_LinIfTriggerTransmit
(
    PduIdType TxPduId,
    P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) PduInfoPtr
)
{
    Std_ReturnType ret = E_NOT_OK;
#if(PDUR_MAX_NUMOFLINIFTXPDU > 0)
    PduR_RoutingPathIdType PathId;
    PduR_RoutingPathGroupIdType GroupId;
#endif

    if(!PDUR_IS_INITIALIZED())
    {
        /*SWS_PduR_00328 SWS_PduR_00330 SWS_PduR_00119*/
        PDUR_DET_REPORT_ERROR(PDUR_LINIF_TRIGGERTRANSMIT_APIID, PDUR_E_INVALID_REQUEST);
    }
    else if(TxPduId >= PDUR_GET_NUM_LINIFTXPDU())
    {
        /*SWS_PduR_00221*/
        PDUR_DET_REPORT_ERROR(PDUR_LINIF_TRIGGERTRANSMIT_APIID, PDUR_E_PDU_ID_INVALID);
    }
    else if(NULL_PTR == PduInfoPtr)
    {
        PDUR_DET_REPORT_ERROR(PDUR_LINIF_TRIGGERTRANSMIT_APIID, PDUR_E_PARAM_POINTER);
    }
    else
    {
#if(PDUR_MAX_NUMOFLINIFTXPDU > 0)
        SchM_Enter_PduR_PDUR_EXCLUSIVE_AREA_0();
        PathId = PDUR_LINIF_TXCONFPDUINFO(TxPduId).PathId;
        GroupId = PDUR_ROUTINGPATHINFO(PathId).PduRDestPdu.PduRRoutingGroup;
        if((PDUR_RPGROUP_NONE == GroupId) || (TRUE == PduR_RoutingPathGroupEnabled[GroupId]))
        {
            ret = PduR_LowerIfTriggerTransmit(PathId, PDUR_LINIF_TXCONFPDUINFO(TxPduId).UpperPduId, PduInfoPtr);
        }
        SchM_Exit_PduR_PDUR_EXCLUSIVE_AREA_0();
#endif
    }

    return ret;
}
#endif

#if(STD_ON == PDUR_FRIF_MODULE_SUPPORT)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: PduR_FrIfRxIndication SWS_PduR_00362
*
* Description:     Indication of a received I-PDU from a lower layer communication module.
*
* Inputs:         RxPduId   Identification of the transmitted I-PDU.
*                 PduInfoPtr Contains the length (SduLength) of the received I-PDU
*                            and a pointer to a buffer (SduDataPtr) containing the I-PDU.
*
* Outputs:         None
*
* Limitations:     None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, PDUR_CODE) PduR_FrIfRxIndication
(
    PduIdType RxPduId,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_CONST) PduInfoPtr
)
{
#if(PDUR_MAX_NUMOFFRIFRXPDU > 0)
    P2CONST(PduRRoutingPduInfoType, AUTOMATIC, PDUR_CONST) pRxPduInfo;
#endif

    if(!PDUR_IS_INITIALIZED())
    {
        /*SWS_PduR_00328 SWS_PduR_00330 SWS_PduR_00119*/
        PDUR_DET_REPORT_ERROR(PDUR_FRIF_RXINDICATION_APIID, PDUR_E_INVALID_REQUEST);
    }
    else if(RxPduId >= PDUR_GET_NUM_FRIFRXPDU())
    {
        /*SWS_PduR_00221*/
        PDUR_DET_REPORT_ERROR(PDUR_FRIF_RXINDICATION_APIID, PDUR_E_PDU_ID_INVALID);
    }
    else if(NULL_PTR == PduInfoPtr)
    {
        PDUR_DET_REPORT_ERROR(PDUR_FRIF_RXINDICATION_APIID, PDUR_E_PARAM_POINTER);
    }
    else
    {
#if(PDUR_MAX_NUMOFFRIFRXPDU > 0)
        SchM_Enter_PduR_PDUR_EXCLUSIVE_AREA_0();
        pRxPduInfo = &(PDUR_FRIF_RXPDUINFO(RxPduId));
        PduR_LowerIfMultiRxIndication(pRxPduInfo, PduInfoPtr);
        SchM_Exit_PduR_PDUR_EXCLUSIVE_AREA_0();
#endif
    }
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: PduR_FrIfTxConfirmation    SWS_PduR_00365
*
* Description:     The lower layer communication module confirms the transmission
*                of an I-PDU.
*
* Inputs:         TxPduId   ID of the I-PDU that has been transmitted.
*
* Outputs:         bufferSizePtr    Available receive buffer after data has been copied.
*
* Limitations:     None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, PDUR_CODE) PduR_FrIfTxConfirmation
(
    PduIdType TxPduId
)
{
#if(PDUR_MAX_NUMOFFRIFTXPDU > 0)
    PduR_RoutingPathIdType PathId;
    PduR_RoutingPathGroupIdType GroupId;
#endif

    if(!PDUR_IS_INITIALIZED())
    {
        /*SWS_PduR_00328 SWS_PduR_00330 SWS_PduR_00119*/
        PDUR_DET_REPORT_ERROR(PDUR_FRIF_TXCONFIRMATION_APIID, PDUR_E_INVALID_REQUEST);
    }
    else if(TxPduId >= PDUR_GET_NUM_FRIFTXPDU())
    {
        /*SWS_PduR_00221*/
        PDUR_DET_REPORT_ERROR(PDUR_FRIF_TXCONFIRMATION_APIID, PDUR_E_PDU_ID_INVALID);
    }
    else
    {
#if(PDUR_MAX_NUMOFFRIFTXPDU > 0)
        SchM_Enter_PduR_PDUR_EXCLUSIVE_AREA_0();
        PathId = PDUR_FRIF_TXCONFPDUINFO(TxPduId).PathId;
        GroupId = PDUR_ROUTINGPATHINFO(PathId).PduRDestPdu.PduRRoutingGroup;
        if((PDUR_RPGROUP_NONE == GroupId) || (TRUE == PduR_RoutingPathGroupEnabled[GroupId]))
        {
            PduR_LowerIfTxConfirmation(PathId, PDUR_FRIF_TXCONFPDUINFO(TxPduId).UpperPduId);
        }
        SchM_Exit_PduR_PDUR_EXCLUSIVE_AREA_0();
#endif
    }
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: PduR_FrIfTriggerTransmit    SWS_PduR_00369
*
* Description:     The lower layer communication module requests the buffer of the
*                SDU for transmission from the upper layer module.
*
* Inputs:         TxPduId   ID of the SDU that is requested to be transmitted.
*                PduInfoPtr Contains a pointer to a buffer (SduDataPtr) to where
*                           the SDU shall be copied to. On return, the service will
*                           indicate the length of the copied SDU data in SduLength
*
* Outputs:         None
*
* Limitations:     None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, PDUR_CODE) PduR_FrIfTriggerTransmit
(
    PduIdType TxPduId,
    P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) PduInfoPtr
)
{
    Std_ReturnType ret = E_NOT_OK;
#if(PDUR_MAX_NUMOFFRIFTXPDU > 0)
    PduR_RoutingPathIdType PathId;
    PduR_RoutingPathGroupIdType GroupId;
#endif

    if(!PDUR_IS_INITIALIZED())
    {
        /*SWS_PduR_00328 SWS_PduR_00330 SWS_PduR_00119*/
        PDUR_DET_REPORT_ERROR(PDUR_FRIF_TRIGGERTRANSMIT_APIID, PDUR_E_INVALID_REQUEST);
    }
    else if(TxPduId >= PDUR_GET_NUM_FRIFTXPDU())
    {
        /*SWS_PduR_00221*/
        PDUR_DET_REPORT_ERROR(PDUR_FRIF_TRIGGERTRANSMIT_APIID, PDUR_E_PDU_ID_INVALID);
    }
    else if(NULL_PTR == PduInfoPtr)
    {
        PDUR_DET_REPORT_ERROR(PDUR_FRIF_TRIGGERTRANSMIT_APIID, PDUR_E_PARAM_POINTER);
    }
    else
    {
#if(PDUR_MAX_NUMOFFRIFTXPDU > 0)
        SchM_Enter_PduR_PDUR_EXCLUSIVE_AREA_0();
        PathId = PDUR_FRIF_TXCONFPDUINFO(TxPduId).PathId;
        GroupId = PDUR_ROUTINGPATHINFO(PathId).PduRDestPdu.PduRRoutingGroup;
        if((PDUR_RPGROUP_NONE == GroupId) || (TRUE == PduR_RoutingPathGroupEnabled[GroupId]))
        {
            ret = PduR_LowerIfTriggerTransmit(PathId, PDUR_FRIF_TXCONFPDUINFO(TxPduId).UpperPduId, PduInfoPtr);
        }
        SchM_Exit_PduR_PDUR_EXCLUSIVE_AREA_0();
#endif
    }

    return ret;
}
#endif

#if(STD_ON == PDUR_SOADIF_MODULE_SUPPORT)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: PduR_SoAdIfRxIndication SWS_PduR_00362
*
* Description:     Indication of a received I-PDU from a lower layer communication module.
*
* Inputs:         RxPduId   Identification of the transmitted I-PDU.
*                 PduInfoPtr Contains the length (SduLength) of the received I-PDU
*                           and a pointer to a buffer (SduDataPtr) containing the I-PDU.
*
* Outputs:         None
*
* Limitations:     None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, PDUR_CODE) PduR_SoAdIfRxIndication
(
    PduIdType RxPduId,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) PduInfoPtr
)
{
    P2CONST(PduRRoutingPduInfoType, AUTOMATIC, PDUR_CONST) pRxPduInfo;

    if(!PDUR_IS_INITIALIZED())
    {
        /*SWS_PduR_00328 SWS_PduR_00330 SWS_PduR_00119*/
        PDUR_DET_REPORT_ERROR(PDUR_SOADIF_RXINDICATION_APIID, PDUR_E_INVALID_REQUEST);
    }
    else if(RxPduId >= PDUR_GET_NUM_SOADIFRXPDU())
    {
        /*SWS_PduR_00221*/
        PDUR_DET_REPORT_ERROR(PDUR_SOADIF_RXINDICATION_APIID, PDUR_E_PDU_ID_INVALID);
    }
    else if(NULL_PTR == PduInfoPtr)
    {
        PDUR_DET_REPORT_ERROR(PDUR_SOADIF_RXINDICATION_APIID, PDUR_E_PARAM_POINTER);
    }
    else
    {
#if(PDUR_MAX_NUMOFSOADIFRXPDU > 0)
        SchM_Enter_PduR_PDUR_EXCLUSIVE_AREA_0();
        pRxPduInfo = &(PDUR_SOADIF_RXPDUINFO(RxPduId));
        PduR_LowerIfMultiRxIndication(pRxPduInfo, PduInfoPtr);
        SchM_Exit_PduR_PDUR_EXCLUSIVE_AREA_0();
#endif
    }
}
#endif

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: PduR_SoAdIfTxConfirmation    SWS_PduR_00365
*
* Description:     The lower layer communication module confirms the transmission
*                of an I-PDU.
*
* Inputs:         TxPduId   ID of the I-PDU that has been transmitted.
*
* Outputs:         None
*
* Limitations:     None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, PDUR_CODE) PduR_SoAdIfTxConfirmation
(
    PduIdType TxPduId
)
{
#if(PDUR_MAX_NUMOFSOADIFTXPDU > 0)
    PduR_RoutingPathIdType PathId;
    PduR_RoutingPathGroupIdType GroupId;
#endif

    if(!PDUR_IS_INITIALIZED())
    {
        /*SWS_PduR_00328 SWS_PduR_00330 SWS_PduR_00119*/
        PDUR_DET_REPORT_ERROR(PDUR_SOADIF_TXCONFIRMATION_APIID, PDUR_E_INVALID_REQUEST);
    }
#if(PDUR_MAX_NUMOFSOADIFTXPDU > 0)
    else if(TxPduId >= PDUR_GET_NUM_SOADIFTXPDU())
    {
        /*SWS_PduR_00221*/
        PDUR_DET_REPORT_ERROR(PDUR_SOADIF_TXCONFIRMATION_APIID, PDUR_E_PDU_ID_INVALID);
    }
#endif
    else
    {
#if(PDUR_MAX_NUMOFSOADIFTXPDU > 0)
        PathId = PDUR_SOADIF_TXCONFPDUINFO(TxPduId).PathId;
        GroupId = PDUR_ROUTINGPATHINFO(PathId).PduRDestPdu.PduRRoutingGroup;
        if((PDUR_RPGROUP_NONE == GroupId) || (TRUE == PduR_RoutingPathGroupEnabled[GroupId]))
        {
            PduR_LowerIfTxConfirmation(PathId, PDUR_SOADIF_TXCONFPDUINFO(TxPduId).UpperPduId);
        }
#endif
    }
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: PduR_SoAdIfTriggerTransmit    SWS_PduR_00369
*
* Description:     The lower layer communication module requests the buffer of the
*                SDU for transmission from the upper layer module.
*
* Inputs:         TxPduId   ID of the SDU that is requested to be transmitted.
*                PduInfoPtr Contains a pointer to a buffer (SduDataPtr) to where
*                           the SDU shall be copied to. On return, the service will
*                           indicate the length of the copied SDU data in SduLength
*
* Outputs:         None
*
* Limitations:     None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, PDUR_CODE) PduR_SoAdIfTriggerTransmit
(
    PduIdType TxPduId,
    P2VAR(PduInfoType, AUTOMATIC, PDUR_CONST) PduInfoPtr
)
{
    Std_ReturnType ret = E_NOT_OK;
#if(PDUR_MAX_NUMOFSOADIFTXPDU > 0)
    PduR_RoutingPathIdType PathId;
    PduR_RoutingPathGroupIdType GroupId;
#endif

    if(!PDUR_IS_INITIALIZED())
    {
        /*SWS_PduR_00328 SWS_PduR_00330 SWS_PduR_00119*/
        PDUR_DET_REPORT_ERROR(PDUR_SOADIF_TRIGGERTRANSMIT_APIID, PDUR_E_INVALID_REQUEST);
    }
#if(PDUR_MAX_NUMOFSOADIFTXPDU > 0)
    else if(TxPduId >= PDUR_GET_NUM_SOADIFTXPDU())
    {
        /*SWS_PduR_00221*/
        PDUR_DET_REPORT_ERROR(PDUR_SOADIF_TRIGGERTRANSMIT_APIID, PDUR_E_PDU_ID_INVALID);
    }
#endif
    else if(NULL_PTR == PduInfoPtr)
    {
        PDUR_DET_REPORT_ERROR(PDUR_SOADIF_TRIGGERTRANSMIT_APIID, PDUR_E_PARAM_POINTER);
    }
    else
    {
#if(PDUR_MAX_NUMOFSOADIFTXPDU > 0)
        SchM_Enter_PduR_PDUR_EXCLUSIVE_AREA_0();
        PathId = PDUR_SOADIF_TXCONFPDUINFO(TxPduId).PathId;
        GroupId = PDUR_ROUTINGPATHINFO(PathId).PduRDestPdu.PduRRoutingGroup;
        if((PDUR_RPGROUP_NONE == GroupId) || (TRUE == PduR_RoutingPathGroupEnabled[GroupId]))
        {
            ret = PduR_LowerIfTriggerTransmit(PathId, PDUR_SOADIF_TXCONFPDUINFO(TxPduId).UpperPduId, PduInfoPtr);
        }
        SchM_Exit_PduR_PDUR_EXCLUSIVE_AREA_0();
#endif
    }

    return ret;
}

#if(STD_ON == PDUR_DOIPIF_MODULE_SUPPORT)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: PduR_DoIPIfTxConfirmation    SWS_PduR_00365
*
* Description:     The lower layer communication module confirms the transmission
*                of an I-PDU.
*
* Inputs:         TxPduId   ID of the I-PDU that has been transmitted.
*
* Outputs:         None
*
* Limitations:     None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, PDUR_CODE) PduR_DoIPIfTxConfirmation
(
    PduIdType TxPduId
)
{
    PduR_RoutingPathIdType PathId;
    PduR_RoutingPathGroupIdType GroupId;

    if(!PDUR_IS_INITIALIZED())
    {
        /*SWS_PduR_00328 SWS_PduR_00330 SWS_PduR_00119*/
        PDUR_DET_REPORT_ERROR(PDUR_DOIPIF_TXCONFIRMATION_APIID, PDUR_E_INVALID_REQUEST);
    }
    else if(TxPduId >= PDUR_GET_NUM_DOIPIFTXPDU())
    {
        /*SWS_PduR_00221*/
        PDUR_DET_REPORT_ERROR(PDUR_DOIPIF_TXCONFIRMATION_APIID, PDUR_E_PDU_ID_INVALID);
    }
    else
    {
#if(PDUR_MAX_NUMOFDOIPIFTXPDU > 0)
        PathId = PDUR_DOIPIF_TXCONFPDUINFO(TxPduId).PathId;
        GroupId = PDUR_ROUTINGPATHINFO(PathId).PduRDestPdu.PduRRoutingGroup;
        if((PDUR_RPGROUP_NONE == GroupId) || (TRUE == PduR_RoutingPathGroupEnabled[GroupId]))
        {
            PduR_LowerIfTxConfirmation(PathId, PDUR_DOIPIF_TXCONFPDUINFO(TxPduId).UpperPduId);
        }
#endif
    }
}

#endif


#if(STD_ON == PDUR_CDDIF_MODULE_SUPPORT)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: PduR_CddIfRxIndication SWS_PduR_00362
*
* Description:     Indication of a received I-PDU from a lower layer communication module.
*
* Inputs:         RxPduId   Identification of the transmitted I-PDU.
*                 PduInfoPtr Contains the length (SduLength) of the received I-PDU
*                           and a pointer to a buffer (SduDataPtr) containing the I-PDU.
*
* Outputs:         None
*
* Limitations:     None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, PDUR_CODE) PduR_CddIfRxIndication
(
    PduIdType RxPduId,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) PduInfoPtr
)
{
    P2CONST(PduRRoutingPduInfoType, AUTOMATIC, PDUR_CONST) pRxPduInfo;

    if(!PDUR_IS_INITIALIZED())
    {
        /*SWS_PduR_00328 SWS_PduR_00330 SWS_PduR_00119*/
        PDUR_DET_REPORT_ERROR(PDUR_CDDIF_RXINDICATION_APIID, PDUR_E_INVALID_REQUEST);
    }
    else if(RxPduId >= PDUR_GET_NUM_CDDIFRXPDU())
    {
        /*SWS_PduR_00221*/
        PDUR_DET_REPORT_ERROR(PDUR_CDDIF_RXINDICATION_APIID, PDUR_E_PDU_ID_INVALID);
    }
    else if(NULL_PTR == PduInfoPtr)
    {
        PDUR_DET_REPORT_ERROR(PDUR_CDDIF_RXINDICATION_APIID, PDUR_E_PARAM_POINTER);
    }
    else
    {
#if(PDUR_MAX_NUMOFCDDIFRXPDU > 0)
        SchM_Enter_PduR_PDUR_EXCLUSIVE_AREA_0();
        pRxPduInfo = &(PDUR_CDDIF_RXPDUINFO(RxPduId));
        PduR_LowerIfMultiRxIndication(pRxPduInfo, PduInfoPtr);
        SchM_Exit_PduR_PDUR_EXCLUSIVE_AREA_0();
#endif
    }

}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: PduR_CddIfTxConfirmation    SWS_PduR_00365
*
* Description:     The lower layer communication module confirms the transmission
*                of an I-PDU.
*
* Inputs:         TxPduId   ID of the I-PDU that has been transmitted.
*
* Outputs:         None
*
* Limitations:     None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, PDUR_CODE) PduR_CddIfTxConfirmation
(
    PduIdType TxPduId
)
{
    PduR_RoutingPathIdType PathId;
    PduR_RoutingPathGroupIdType GroupId;

    if(!PDUR_IS_INITIALIZED())
    {
        /*SWS_PduR_00328 SWS_PduR_00330 SWS_PduR_00119*/
        PDUR_DET_REPORT_ERROR(PDUR_CDDIF_TXCONFIRMATION_APIID, PDUR_E_INVALID_REQUEST);
    }
    else if(TxPduId >= PDUR_GET_NUM_CDDIFTXPDU())
    {
        /*SWS_PduR_00221*/
        PDUR_DET_REPORT_ERROR(PDUR_CDDIF_TXCONFIRMATION_APIID, PDUR_E_PDU_ID_INVALID);
    }
    else
    {
#if(PDUR_MAX_NUMOFCDDIFTXPDU > 0)
        SchM_Enter_PduR_PDUR_EXCLUSIVE_AREA_0();
        PathId = PDUR_CDDIF_TXCONFPDUINFO(TxPduId).PathId;
        GroupId = PDUR_ROUTINGPATHINFO(PathId).PduRDestPdu.PduRRoutingGroup;
        if((PDUR_RPGROUP_NONE == GroupId) || (TRUE == PduR_RoutingPathGroupEnabled[GroupId]))
        {
            PduR_LowerIfTxConfirmation(PathId, PDUR_CDDIF_TXCONFPDUINFO(TxPduId).UpperPduId);
        }
        SchM_Exit_PduR_PDUR_EXCLUSIVE_AREA_0();
#endif
    }
}
#endif

#if(STD_ON == PDUR_CANTP_MODULE_SUPPORT)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: PduR_CanTpStartOfReception    SWS_PduR_00507
*
* Description:     This function is called at the start of receiving an N-SDU.
*                The N-SDU might be fragmented into multiple N-PDUs (FF with one
*                or more following CFs) or might consist of a single N-PDU (SF).
*
* Inputs:         id   Identification of the I-PDU.
*                 TpSduLength  Total length of the PDU to be received.
*
* Outputs:         bufferSizePtr  Available receive buffer in the receiving module.
*                               This parameter will be used to compute the Block
*                               Size (BS) in the transport protocol module
*
* Limitations:     None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(BufReq_ReturnType, PDUR_CODE) PduR_CanTpStartOfReception
(
    PduIdType id,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info,
    PduLengthType TpSduLength,
    P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) bufferSizePtr
)
{
    BufReq_ReturnType result = BUFREQ_E_NOT_OK;
#if(PDUR_MAX_NUMOFCANTPRXPDU > 0)
    P2CONST(PduRRoutingPduInfoType, AUTOMATIC, PDUR_CONST) pRxPduInfo;
#endif

    if(!PDUR_IS_INITIALIZED())
    {
        /*SWS_PduR_00328 SWS_PduR_00330 SWS_PduR_00119*/
        PDUR_DET_REPORT_ERROR(PDUR_CANTP_STARTOFRECEPTION_APIID, PDUR_E_INVALID_REQUEST);
    }
    else if(id >= PDUR_GET_NUM_CANTPRXPDU())
    {
        /*SWS_PduR_00221*/
        PDUR_DET_REPORT_ERROR(PDUR_CANTP_STARTOFRECEPTION_APIID, PDUR_E_PDU_ID_INVALID);
    }
    else if(NULL_PTR == bufferSizePtr)
    {
        PDUR_DET_REPORT_ERROR(PDUR_CANTP_STARTOFRECEPTION_APIID, PDUR_E_PARAM_POINTER);
    }
    else
    {
#if(PDUR_MAX_NUMOFCANTPRXPDU > 0)
        SchM_Enter_PduR_PDUR_EXCLUSIVE_AREA_0();
        pRxPduInfo = &(PDUR_CANTP_RXPDUINFO(id));
        result = PduR_LowerTpMultiStartOfReception(pRxPduInfo, info, TpSduLength, bufferSizePtr);
        SchM_Exit_PduR_PDUR_EXCLUSIVE_AREA_0();
#endif
    }

    return result;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: PduR_CanTpCopyRxData    SWS_PduR_00512
*
* Description:     This function is called when a transport protocol module has data
*                to copy for the receiving module. Several calls may be made during
*                one transportation of an I-PDU.
*
* Inputs:         id   Identification of the transmitted I-PDU.
*                 info Pointer to the buffer (SduDataPtr) and its length (SduLength)
*                      containing the data to be copied by PDU Router module in case
*                      of gateway or upper layer module in case of reception
*
* Outputs:         bufferSizePtr    Available receive buffer after data has been copied.
*
* Limitations:     None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(BufReq_ReturnType, PDUR_CODE) PduR_CanTpCopyRxData
(
    PduIdType id,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info,
    P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) bufferSizePtr
)
{
    BufReq_ReturnType result = BUFREQ_E_NOT_OK;
#if(PDUR_MAX_NUMOFCANTPRXPDU > 0)
    P2CONST(PduRRoutingPduInfoType, AUTOMATIC, PDUR_CONST) pRxPduInfo;
#endif

    if(!PDUR_IS_INITIALIZED())
    {
        /*SWS_PduR_00328 SWS_PduR_00330 SWS_PduR_00119*/
        PDUR_DET_REPORT_ERROR(PDUR_CANTP_COPYRXDATA_APIID, PDUR_E_INVALID_REQUEST);
    }
    else if(id >= PDUR_GET_NUM_CANTPRXPDU())
    {
        /*SWS_PduR_00221*/
        PDUR_DET_REPORT_ERROR(PDUR_CANTP_COPYRXDATA_APIID, PDUR_E_PDU_ID_INVALID);
    }
    else if(NULL_PTR == info)
    {
        PDUR_DET_REPORT_ERROR(PDUR_CANTP_COPYRXDATA_APIID, PDUR_E_PARAM_POINTER);
    }
    else
    {
#if(PDUR_MAX_NUMOFCANTPRXPDU > 0)
        SchM_Enter_PduR_PDUR_EXCLUSIVE_AREA_0();
        pRxPduInfo = &(PDUR_CANTP_RXPDUINFO(id));
        result = PduR_LowerTpMultiCopyRxData(pRxPduInfo, info, bufferSizePtr);
        SchM_Exit_PduR_PDUR_EXCLUSIVE_AREA_0();
#endif
    }

    return result;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: PduR_CanTpRxIndication    SWS_PduR_00375
*
* Description:     Called by the transport protocol module after an I-PDU has been
*                received successfully or when an error occurred. It is also used
*                to confirm cancellation of an I-PDU.
*
* Inputs:         id   Identification of the transmitted I-PDU.
*                 result Result of the reception.
*
* Outputs:         bufferSizePtr  Available receive buffer after data has been copied.
*
* Limitations:     None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, PDUR_CODE) PduR_CanTpRxIndication
(
    PduIdType id,
    Std_ReturnType result
)
{
#if(PDUR_MAX_NUMOFCANTPRXPDU > 0)
    P2CONST(PduRRoutingPduInfoType, AUTOMATIC, PDUR_CONST) pRxPduInfo;
#endif

    if(!PDUR_IS_INITIALIZED())
    {
        /*SWS_PduR_00328 SWS_PduR_00330 SWS_PduR_00119*/
        PDUR_DET_REPORT_ERROR(PDUR_CANTP_RXINDICATION_APIID, PDUR_E_INVALID_REQUEST);
    }
    else if(id >= PDUR_GET_NUM_CANTPRXPDU())
    {
        /*SWS_PduR_00221*/
        PDUR_DET_REPORT_ERROR(PDUR_CANTP_RXINDICATION_APIID, PDUR_E_PDU_ID_INVALID);
    }
    else
    {
#if(PDUR_MAX_NUMOFCANTPRXPDU > 0)
        SchM_Enter_PduR_PDUR_EXCLUSIVE_AREA_0();
        pRxPduInfo = &(PDUR_CANTP_RXPDUINFO(id));
        PduR_LowerTpMultiRxIndication(pRxPduInfo, result);
        SchM_Exit_PduR_PDUR_EXCLUSIVE_AREA_0();
#endif
    }
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: PduR_CanTpCopyTxData    SWS_PduR_00518
*
* Description:     This function is called by the transport protocol module to query
*                the transmit data of an I-PDU segment.
*
* Inputs:         id   Identification of the transmitted I-PDU.
*                 info Provides destination buffer and the number of bytes to copy.
*                     In case of gateway the PDU Router module will copy, otherwise
*                     the source upper layer module will copy the data. If not enough
*                     transmit data is available, no data is copied. The transport
*                     protocol module will retry. A copy size of 0 can be used to
*                     indicate state changes in the retry parameter.
*                retry This parameter is used to retransmit data because problems
*                      during the last service call.
*
*
* Outputs:         availableDataPtr  Indicates the remaining number of bytes that are
*                                  available in the PduR Tx buffer. AvailableTxDataCntPtr
*                                  can be used by TP modules that support dynamic payload
*                                  lengths (e.g. Iso FrTp) to determine the size of the
*                                  following CFs.
*
* Limitations:     None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(BufReq_ReturnType, PDUR_CODE) PduR_CanTpCopyTxData
(
    PduIdType id,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info,
    P2VAR(RetryInfoType, AUTOMATIC, PDUR_APPL_DATA) retry,
    P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) availableDataPtr
)
{
    BufReq_ReturnType result = BUFREQ_E_NOT_OK;
#if(PDUR_MAX_NUMOFCANTPTXPDU > 0)
    PduR_RoutingPathIdType PathId;
    PduR_RoutingPathGroupIdType GroupId;
#endif

    if(!PDUR_IS_INITIALIZED())
    {
        /*SWS_PduR_00328 SWS_PduR_00330 SWS_PduR_00119*/
        PDUR_DET_REPORT_ERROR(PDUR_CANTP_COPYTXDATA_APIID, PDUR_E_INVALID_REQUEST);
    }
    else if(id >= PDUR_GET_NUM_CANTPTXPDU())
    {
        /*SWS_PduR_00221*/
        PDUR_DET_REPORT_ERROR(PDUR_CANTP_COPYTXDATA_APIID, PDUR_E_PDU_ID_INVALID);
    }
    else if(NULL_PTR == info)
    {
        PDUR_DET_REPORT_ERROR(PDUR_CANTP_COPYTXDATA_APIID, PDUR_E_PARAM_POINTER);
    }
    else if(NULL_PTR == availableDataPtr)
    {
        PDUR_DET_REPORT_ERROR(PDUR_CANTP_COPYTXDATA_APIID, PDUR_E_PARAM_POINTER);
    }
    else
    {
#if(PDUR_MAX_NUMOFCANTPTXPDU > 0)
        SchM_Enter_PduR_PDUR_EXCLUSIVE_AREA_0();
        PathId = PDUR_CANTP_TXCONFPDUINFO(id).PathId;
        GroupId = PDUR_ROUTINGPATHINFO(PathId).PduRDestPdu.PduRRoutingGroup;
        if((PDUR_RPGROUP_NONE == GroupId) || (TRUE == PduR_RoutingPathGroupEnabled[GroupId]))
        {
            result = PduR_LowerTpCopyTxData(PathId, PDUR_CANTP_TXCONFPDUINFO(id).UpperPduId, info, retry, availableDataPtr);
        }
        SchM_Exit_PduR_PDUR_EXCLUSIVE_AREA_0();
#endif
    }
    return result;
}


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: PduR_CanTpTxConfirmation    SWS_PduR_00381
*
* Description:     This function is called after the I-PDU has been transmitted on
*                its network, the result indicates whether the transmission was
*                successful or not
*
* Inputs:         id - Identification of the transmitted I-PDU.
*                result - Result of the transmission of the I-PDU.
*
* Outputs:         None
*
* Limitations:     None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, PDUR_CODE) PduR_CanTpTxConfirmation
(
    PduIdType id,
    Std_ReturnType result
)
{
#if(PDUR_MAX_NUMOFCANTPTXPDU > 0)
    PduR_RoutingPathIdType PathId;
    PduR_RoutingPathGroupIdType GroupId;
#endif

    if(!PDUR_IS_INITIALIZED())
    {
        /*SWS_PduR_00328 SWS_PduR_00330 SWS_PduR_00119*/
        PDUR_DET_REPORT_ERROR(PDUR_CANTP_TXCONFIRMATION_APIID, PDUR_E_INVALID_REQUEST);
    }
    else if(id >= PDUR_GET_NUM_CANTPTXPDU())
    {
        /*SWS_PduR_00221*/
        PDUR_DET_REPORT_ERROR(PDUR_CANTP_TXCONFIRMATION_APIID, PDUR_E_PDU_ID_INVALID);
    }
    else
    {
#if(PDUR_MAX_NUMOFCANTPTXPDU > 0)
        SchM_Enter_PduR_PDUR_EXCLUSIVE_AREA_0();
        PathId = PDUR_CANTP_TXCONFPDUINFO(id).PathId;
        GroupId = PDUR_ROUTINGPATHINFO(PathId).PduRDestPdu.PduRRoutingGroup;
        if((PDUR_RPGROUP_NONE == GroupId) || (TRUE == PduR_RoutingPathGroupEnabled[GroupId]))
        {
            PduR_LowerTpTxConfirmation(PathId, PDUR_CANTP_TXCONFPDUINFO(id).UpperPduId, result);
        }
        SchM_Exit_PduR_PDUR_EXCLUSIVE_AREA_0();
#endif
    }
}
#endif

#if(STD_ON == PDUR_SOMEIPTP_MODULE_SUPPORT)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: PduR_SomeIpTpStartOfReception
*
* Description:   This function is called at the start of receiving an N-SDU.
*                The N-SDU might be fragmented into multiple N-PDUs (FF with one
*                or more following CFs) or might consist of a single N-PDU (SF).
*
* Inputs:        id   Identification of the I-PDU.
*                TpSduLength  Total length of the PDU to be received.
*
* Outputs:       bufferSizePtr  Available receive buffer in the receiving module.
*                               This parameter will be used to compute the Block
*                               Size (BS) in the transport protocol module
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(BufReq_ReturnType, PDUR_CODE) PduR_SomeIpTpStartOfReception
(
    PduIdType id,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info,
    PduLengthType TpSduLength,
    P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) bufferSizePtr
)
{
    BufReq_ReturnType result = BUFREQ_E_NOT_OK;
#if(PDUR_MAX_NUMOFSOMEIPTPRXPDU > 0)
    P2CONST(PduRRoutingPduInfoType, AUTOMATIC, PDUR_CONST) pRxPduInfo;
#endif

    if(!PDUR_IS_INITIALIZED())
    {
        /*SWS_PduR_00328 SWS_PduR_00330 SWS_PduR_00119*/
        PDUR_DET_REPORT_ERROR(PDUR_SOMEIPTP_STARTOFRECEPTION_APIID, PDUR_E_INVALID_REQUEST);
    }
    else if(id >= PDUR_GET_NUM_SOMEIPTPRXPDU())
    {
        /*SWS_PduR_00221*/
        PDUR_DET_REPORT_ERROR(PDUR_SOMEIPTP_STARTOFRECEPTION_APIID, PDUR_E_PDU_ID_INVALID);
    }
    else if(NULL_PTR == bufferSizePtr)
    {
        PDUR_DET_REPORT_ERROR(PDUR_SOMEIPTP_STARTOFRECEPTION_APIID, PDUR_E_PARAM_POINTER);
    }
    else
    {
#if(PDUR_MAX_NUMOFSOMEIPTPRXPDU > 0)
        SchM_Enter_PduR_PDUR_EXCLUSIVE_AREA_0();
        pRxPduInfo = &(PDUR_SOMEIPTP_RXPDUINFO(id));
        result = PduR_LowerTpMultiStartOfReception(pRxPduInfo, info, TpSduLength, bufferSizePtr);
        SchM_Exit_PduR_PDUR_EXCLUSIVE_AREA_0();
#endif
    }

    return result;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: PduR_SomeIpTpCopyRxData
*
* Description:   This function is called when a transport protocol module has data
*                to copy for the receiving module. Several calls may be made during
*                one transportation of an I-PDU.
*
* Inputs:        id   Identification of the transmitted I-PDU.
*                info Pointer to the buffer (SduDataPtr) and its length (SduLength)
*                      containing the data to be copied by PDU Router module in case
*                      of gateway or upper layer module in case of reception
*
* Outputs:       bufferSizePtr    Available receive buffer after data has been copied.
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(BufReq_ReturnType, PDUR_CODE) PduR_SomeIpTpCopyRxData
(
    PduIdType id,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info,
    P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) bufferSizePtr
)
{
    BufReq_ReturnType result = BUFREQ_E_NOT_OK;
#if(PDUR_MAX_NUMOFSOMEIPTPRXPDU > 0)
    P2CONST(PduRRoutingPduInfoType, AUTOMATIC, PDUR_CONST) pRxPduInfo;
#endif

    if(!PDUR_IS_INITIALIZED())
    {
        /*SWS_PduR_00328 SWS_PduR_00330 SWS_PduR_00119*/
        PDUR_DET_REPORT_ERROR(PDUR_SOMEIPTP_COPYRXDATA_APIID, PDUR_E_INVALID_REQUEST);
    }
    else if(id >= PDUR_GET_NUM_SOMEIPTPRXPDU())
    {
        /*SWS_PduR_00221*/
        PDUR_DET_REPORT_ERROR(PDUR_SOMEIPTP_COPYRXDATA_APIID, PDUR_E_PDU_ID_INVALID);
    }
    else if(NULL_PTR == info)
    {
        PDUR_DET_REPORT_ERROR(PDUR_SOMEIPTP_COPYRXDATA_APIID, PDUR_E_PARAM_POINTER);
    }
    else
    {
#if(PDUR_MAX_NUMOFSOMEIPTPRXPDU > 0)
        SchM_Enter_PduR_PDUR_EXCLUSIVE_AREA_0();
        pRxPduInfo = &(PDUR_SOMEIPTP_RXPDUINFO(id));
        result = PduR_LowerTpMultiCopyRxData(pRxPduInfo, info, bufferSizePtr);
        SchM_Exit_PduR_PDUR_EXCLUSIVE_AREA_0();
#endif
    }

    return result;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: PduR_SomeIpTpRxIndication
*
* Description:   Called by the transport protocol module after an I-PDU has been
*                received successfully or when an error occurred. It is also used
*                to confirm cancellation of an I-PDU.
*
* Inputs:        id   Identification of the transmitted I-PDU.
*                result Result of the reception.
*
* Outputs:       bufferSizePtr  Available receive buffer after data has been copied.
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, PDUR_CODE) PduR_SomeIpTpRxIndication
(
    PduIdType id,
    Std_ReturnType result
)
{
#if(PDUR_MAX_NUMOFSOMEIPTPRXPDU > 0)
    P2CONST(PduRRoutingPduInfoType, AUTOMATIC, PDUR_CONST) pRxPduInfo;
#endif

    if(!PDUR_IS_INITIALIZED())
    {
        /*SWS_PduR_00328 SWS_PduR_00330 SWS_PduR_00119*/
        PDUR_DET_REPORT_ERROR(PDUR_SOMEIPTP_RXINDICATION_APIID, PDUR_E_INVALID_REQUEST);
    }
    else if(id >= PDUR_GET_NUM_SOMEIPTPRXPDU())
    {
        /*SWS_PduR_00221*/
        PDUR_DET_REPORT_ERROR(PDUR_SOMEIPTP_RXINDICATION_APIID, PDUR_E_PDU_ID_INVALID);
    }
    else
    {
#if(PDUR_MAX_NUMOFSOMEIPTPRXPDU > 0)
        SchM_Enter_PduR_PDUR_EXCLUSIVE_AREA_0();
        pRxPduInfo = &(PDUR_SOMEIPTP_RXPDUINFO(id));
        PduR_LowerTpMultiRxIndication(pRxPduInfo, result);
        SchM_Exit_PduR_PDUR_EXCLUSIVE_AREA_0();
#endif
    }
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: PduR_SomeIpTpCopyTxData
*
* Description:   This function is called by the transport protocol module to query
*                the transmit data of an I-PDU segment.
*
* Inputs:        id   Identification of the transmitted I-PDU.
*                info Provides destination buffer and the number of bytes to copy.
*                     In case of gateway the PDU Router module will copy, otherwise
*                     the source upper layer module will copy the data. If not enough
*                     transmit data is available, no data is copied. The transport
*                     protocol module will retry. A copy size of 0 can be used to
*                     indicate state changes in the retry parameter.
*                retry This parameter is used to retransmit data because problems
*                      during the last service call.
*
*
* Outputs:       availableDataPtr  Indicates the remaining number of bytes that are
*                                  available in the PduR Tx buffer. AvailableTxDataCntPtr
*                                  can be used by TP modules that support dynamic payload
*                                  lengths (e.g. Iso FrTp) to determine the size of the
*                                  following CFs.
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(BufReq_ReturnType, PDUR_CODE) PduR_SomeIpTpCopyTxData
(
    PduIdType id,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info,
    P2VAR(RetryInfoType, AUTOMATIC, PDUR_APPL_DATA) retry,
    P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) availableDataPtr
)
{
    BufReq_ReturnType result = BUFREQ_E_NOT_OK;
#if(PDUR_MAX_NUMOFSOMEIPTPTXPDU > 0)
    PduR_RoutingPathIdType PathId;
    PduR_RoutingPathGroupIdType GroupId;
#endif

    if(!PDUR_IS_INITIALIZED())
    {
        /*SWS_PduR_00328 SWS_PduR_00330 SWS_PduR_00119*/
        PDUR_DET_REPORT_ERROR(PDUR_SOMEIPTP_COPYTXDATA_APIID, PDUR_E_INVALID_REQUEST);
    }
    else if(id >= PDUR_GET_NUM_SOMEIPTPTXPDU())
    {
        /*SWS_PduR_00221*/
        PDUR_DET_REPORT_ERROR(PDUR_SOMEIPTP_COPYTXDATA_APIID, PDUR_E_PDU_ID_INVALID);
    }
    else if(NULL_PTR == info)
    {
        PDUR_DET_REPORT_ERROR(PDUR_SOMEIPTP_COPYTXDATA_APIID, PDUR_E_PARAM_POINTER);
    }
    else if(NULL_PTR == availableDataPtr)
    {
        PDUR_DET_REPORT_ERROR(PDUR_SOMEIPTP_COPYTXDATA_APIID, PDUR_E_PARAM_POINTER);
    }
    else
    {
#if(PDUR_MAX_NUMOFSOMEIPTPTXPDU > 0)
        SchM_Enter_PduR_PDUR_EXCLUSIVE_AREA_0();
        PathId = PDUR_SOMEIPTP_TXCONFPDUINFO(id).PathId;
        GroupId = PDUR_ROUTINGPATHINFO(PathId).PduRDestPdu.PduRRoutingGroup;
        if((PDUR_RPGROUP_NONE == GroupId) || (TRUE == PduR_RoutingPathGroupEnabled[GroupId]))
        {
            result = PduR_LowerTpCopyTxData(PathId, PDUR_SOMEIPTP_TXCONFPDUINFO(id).UpperPduId, info, retry, availableDataPtr);
        }
        SchM_Exit_PduR_PDUR_EXCLUSIVE_AREA_0();
#endif
    }
    return result;
}


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: PduR_SomeIpTpTxConfirmation
*
* Description:   This function is called after the I-PDU has been transmitted on
*                its network, the result indicates whether the transmission was
*                successful or not
*
* Inputs:        id - Identification of the transmitted I-PDU.
*                result - Result of the transmission of the I-PDU.
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, PDUR_CODE) PduR_SomeIpTpTxConfirmation
(
    PduIdType id,
    Std_ReturnType result
)
{
#if(PDUR_MAX_NUMOFSOMEIPTPTXPDU > 0)
    PduR_RoutingPathIdType PathId;
    PduR_RoutingPathGroupIdType GroupId;
#endif

    if(!PDUR_IS_INITIALIZED())
    {
        /*SWS_PduR_00328 SWS_PduR_00330 SWS_PduR_00119*/
        PDUR_DET_REPORT_ERROR(PDUR_SOMEIPTP_TXCONFIRMATION_APIID, PDUR_E_INVALID_REQUEST);
    }
    else if(id >= PDUR_GET_NUM_SOMEIPTPTXPDU())
    {
        /*SWS_PduR_00221*/
        PDUR_DET_REPORT_ERROR(PDUR_SOMEIPTP_TXCONFIRMATION_APIID, PDUR_E_PDU_ID_INVALID);
    }
    else
    {
#if(PDUR_MAX_NUMOFSOMEIPTPTXPDU > 0)
        SchM_Enter_PduR_PDUR_EXCLUSIVE_AREA_0();
        PathId = PDUR_SOMEIPTP_TXCONFPDUINFO(id).PathId;
        GroupId = PDUR_ROUTINGPATHINFO(PathId).PduRDestPdu.PduRRoutingGroup;
        if((PDUR_RPGROUP_NONE == GroupId) || (TRUE == PduR_RoutingPathGroupEnabled[GroupId]))
        {
            PduR_LowerTpTxConfirmation(PathId, PDUR_SOMEIPTP_TXCONFPDUINFO(id).UpperPduId, result);
        }
        SchM_Exit_PduR_PDUR_EXCLUSIVE_AREA_0();
#endif
    }
}
#endif/*#if(STD_ON == PDUR_SOMEIPTP_MODULE_SUPPORT)*/

#if(STD_ON == PDUR_LINTP_MODULE_SUPPORT)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: PduR_LinTpStartOfReception    SWS_PduR_00507
*
* Description:     This function will be called by the transport protocol module at
*                the start of receiving an I-PDU. The I-PDU might be fragmented into
*                multiple N-PDUs (FF with one or more following CFs) or might consist
*                of a single N-PDU (SF). The service shall provide the currently
*                available maximum buffer size when invoked with TpSduLength equal to 0.
*
* Inputs:         id   Identification of the I-PDU.
*                 TpSduLength  Total length of the PDU to be received.
*
* Outputs:         bufferSizePtr  Available receive buffer in the receiving module.
*                               This parameter will be used to compute the Block
*                               Size (BS) in the transport protocol module
*
* Limitations:     None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(BufReq_ReturnType, PDUR_CODE) PduR_LinTpStartOfReception
(
    PduIdType id,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info,
    PduLengthType TpSduLength,
    P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) bufferSizePtr
)
{
    BufReq_ReturnType result = BUFREQ_E_NOT_OK;
#if(PDUR_MAX_NUMOFLINTPRXPDU > 0)
    P2CONST(PduRRoutingPduInfoType, AUTOMATIC, PDUR_CONST) pRxPduInfo;
#endif

    if(!PDUR_IS_INITIALIZED())
    {
        /*SWS_PduR_00328 SWS_PduR_00330 SWS_PduR_00119*/
        PDUR_DET_REPORT_ERROR(PDUR_LINTP_STARTOFRECEPTION_APIID, PDUR_E_INVALID_REQUEST);
    }
    else if(id >= PDUR_GET_NUM_LINTPRXPDU())
    {
        /*SWS_PduR_00221*/
        PDUR_DET_REPORT_ERROR(PDUR_LINTP_STARTOFRECEPTION_APIID, PDUR_E_PDU_ID_INVALID);
    }
    else if(NULL_PTR == bufferSizePtr)
    {
        PDUR_DET_REPORT_ERROR(PDUR_LINTP_STARTOFRECEPTION_APIID, PDUR_E_PARAM_POINTER);
    }
    else
    {
#if(PDUR_MAX_NUMOFLINTPRXPDU > 0)
        SchM_Enter_PduR_PDUR_EXCLUSIVE_AREA_0();
        pRxPduInfo = &(PDUR_LINTP_RXPDUINFO(id));
        result = PduR_LowerTpMultiStartOfReception(pRxPduInfo, info, TpSduLength, bufferSizePtr);
        SchM_Exit_PduR_PDUR_EXCLUSIVE_AREA_0();
#endif
    }

    return result;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: PduR_LinTpCopyRxData    SWS_PduR_00512
*
* Description:     This function is called when a transport protocol module has data
*                to copy for the receiving module. Several calls may be made during
*                one transportation of an I-PDU.
*
* Inputs:         id   Identification of the transmitted I-PDU.
*                 info Pointer to the buffer (SduDataPtr) and its length (SduLength)
*                      containing the data to be copied by PDU Router module in case
*                      of gateway or upper layer module in case of reception
*
* Outputs:         bufferSizePtr    Available receive buffer after data has been copied.
*
* Limitations:     None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(BufReq_ReturnType, PDUR_CODE) PduR_LinTpCopyRxData
(
    PduIdType id,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info,
    P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) bufferSizePtr
)
{
    BufReq_ReturnType result = BUFREQ_E_NOT_OK;
#if(PDUR_MAX_NUMOFLINTPRXPDU > 0)
    P2CONST(PduRRoutingPduInfoType, AUTOMATIC, PDUR_CONST) pRxPduInfo;
#endif

    if(!PDUR_IS_INITIALIZED())
    {
        /*SWS_PduR_00328 SWS_PduR_00330 SWS_PduR_00119*/
        PDUR_DET_REPORT_ERROR(PDUR_LINTP_COPYRXDATA_APIID, PDUR_E_INVALID_REQUEST);
    }
    else if(id >= PDUR_GET_NUM_LINTPRXPDU())
    {
        /*SWS_PduR_00221*/
        PDUR_DET_REPORT_ERROR(PDUR_LINTP_COPYRXDATA_APIID, PDUR_E_PDU_ID_INVALID);
    }
    else if(NULL_PTR == info)
    {
        PDUR_DET_REPORT_ERROR(PDUR_LINTP_COPYRXDATA_APIID, PDUR_E_PARAM_POINTER);
    }
    else if(NULL_PTR == bufferSizePtr)
    {
        PDUR_DET_REPORT_ERROR(PDUR_LINTP_COPYRXDATA_APIID, PDUR_E_PARAM_POINTER);
    }
    else
    {
#if(PDUR_MAX_NUMOFLINTPRXPDU > 0)
        SchM_Enter_PduR_PDUR_EXCLUSIVE_AREA_0();
        pRxPduInfo = &(PDUR_LINTP_RXPDUINFO(id));
        result = PduR_LowerTpMultiCopyRxData(pRxPduInfo, info, bufferSizePtr);
        SchM_Exit_PduR_PDUR_EXCLUSIVE_AREA_0();
#endif
    }

    return result;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: PduR_LinTpRxIndication    SWS_PduR_00375
*
* Description:     Called by the transport protocol module after an I-PDU has been
*                received successfully or when an error occurred. It is also used
*                to confirm cancellation of an I-PDU.
*
* Inputs:         id   Identification of the transmitted I-PDU.
*                 result Result of the reception.
*
* Outputs:         bufferSizePtr  Available receive buffer after data has been copied.
*
* Limitations:     None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, PDUR_CODE) PduR_LinTpRxIndication
(
    PduIdType id,
    Std_ReturnType result
)
{
#if(PDUR_MAX_NUMOFLINTPRXPDU > 0)
    P2CONST(PduRRoutingPduInfoType, AUTOMATIC, PDUR_CONST) pRxPduInfo;
#endif

    if(!PDUR_IS_INITIALIZED())
    {
        /*SWS_PduR_00328 SWS_PduR_00330 SWS_PduR_00119*/
        PDUR_DET_REPORT_ERROR(PDUR_LINTP_RXINDICATION_APIID, PDUR_E_INVALID_REQUEST);
    }
    else if(id >= PDUR_GET_NUM_LINTPRXPDU())
    {
        /*SWS_PduR_00221*/
        PDUR_DET_REPORT_ERROR(PDUR_LINTP_RXINDICATION_APIID, PDUR_E_PDU_ID_INVALID);
    }
    else
    {
#if(PDUR_MAX_NUMOFLINTPRXPDU > 0)
        SchM_Enter_PduR_PDUR_EXCLUSIVE_AREA_0();
        pRxPduInfo = &(PDUR_LINTP_RXPDUINFO(id));
        PduR_LowerTpMultiRxIndication(pRxPduInfo, result);
        SchM_Exit_PduR_PDUR_EXCLUSIVE_AREA_0();
#endif
    }
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: PduR_LinTpCopyTxData    SWS_PduR_00518
*
* Description:     This function is called by the transport protocol module to query
*                the transmit data of an I-PDU segment.
*
* Inputs:         id   Identification of the transmitted I-PDU.
*                 info Provides destination buffer and the number of bytes to copy.
*                     In case of gateway the PDU Router module will copy, otherwise
*                     the source upper layer module will copy the data. If not enough
*                     transmit data is available, no data is copied. The transport
*                     protocol module will retry. A copy size of 0 can be used to
*                     indicate state changes in the retry parameter.
*                retry This parameter is used to retransmit data because problems
*                      during the last service call.
*
*
* Outputs:         availableDataPtr  Indicates the remaining number of bytes that are
*                                  available in the PduR Tx buffer. AvailableTxDataCntPtr
*                                  can be used by TP modules that support dynamic payload
*                                  lengths (e.g. Iso FrTp) to determine the size of the
*                                  following CFs.
*
* Limitations:     None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(BufReq_ReturnType, PDUR_CODE) PduR_LinTpCopyTxData
(
    PduIdType id,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info,
    P2VAR(RetryInfoType, AUTOMATIC, PDUR_APPL_DATA) retry,
    P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) availableDataPtr
)
{
    BufReq_ReturnType result = BUFREQ_E_NOT_OK;
#if(PDUR_MAX_NUMOFLINTPTXPDU > 0)
    PduR_RoutingPathIdType PathId;
    PduR_RoutingPathGroupIdType GroupId;
#endif

    if(!PDUR_IS_INITIALIZED())
    {
        /*SWS_PduR_00328 SWS_PduR_00330 SWS_PduR_00119*/
        PDUR_DET_REPORT_ERROR(PDUR_LINTP_COPYTXDATA_APIID, PDUR_E_INVALID_REQUEST);
    }
    else if(id >= PDUR_GET_NUM_LINTPTXPDU())
    {
        /*SWS_PduR_00221*/
        PDUR_DET_REPORT_ERROR(PDUR_LINTP_COPYTXDATA_APIID, PDUR_E_PDU_ID_INVALID);
    }
    else if(NULL_PTR == info)
    {
        PDUR_DET_REPORT_ERROR(PDUR_LINTP_COPYTXDATA_APIID, PDUR_E_PARAM_POINTER);
    }
    else if(NULL_PTR == availableDataPtr)
    {
        PDUR_DET_REPORT_ERROR(PDUR_LINTP_COPYTXDATA_APIID, PDUR_E_PARAM_POINTER);
    }
    else
    {
#if(PDUR_MAX_NUMOFLINTPTXPDU > 0)
        SchM_Enter_PduR_PDUR_EXCLUSIVE_AREA_0();
        PathId = PDUR_LINTP_TXCONFPDUINFO(id).PathId;
        GroupId = PDUR_ROUTINGPATHINFO(PathId).PduRDestPdu.PduRRoutingGroup;
        if((PDUR_RPGROUP_NONE == GroupId) || (TRUE == PduR_RoutingPathGroupEnabled[GroupId]))
        {
            result = PduR_LowerTpCopyTxData(PathId, PDUR_LINTP_TXCONFPDUINFO(id).UpperPduId, info, retry, availableDataPtr);
        }
        SchM_Exit_PduR_PDUR_EXCLUSIVE_AREA_0();
#endif
    }
    return result;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: PduR_LinTpTxConfirmation    SWS_PduR_00381
*
* Description:     This function is called after the I-PDU has been transmitted on
*                 its network, the result indicates whether the transmission was
*                 successful or not
*
* Inputs:         id - Identification of the transmitted I-PDU.
*                 result - Result of the transmission of the I-PDU.
*
* Outputs:         None
*
* Limitations:     None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, PDUR_CODE) PduR_LinTpTxConfirmation
(
    PduIdType id,
    Std_ReturnType result
)
{
#if(PDUR_MAX_NUMOFLINTPTXPDU > 0)
    PduR_RoutingPathIdType PathId;
    PduR_RoutingPathGroupIdType GroupId;
#endif

    if(!PDUR_IS_INITIALIZED())
    {
        /*SWS_PduR_00328 SWS_PduR_00330 SWS_PduR_00119*/
        PDUR_DET_REPORT_ERROR(PDUR_LINTP_TXCONFIRMATION_APIID, PDUR_E_INVALID_REQUEST);
    }
    else if(id >= PDUR_GET_NUM_LINTPTXPDU())
    {
        /*SWS_PduR_00221*/
        PDUR_DET_REPORT_ERROR(PDUR_LINTP_TXCONFIRMATION_APIID, PDUR_E_PDU_ID_INVALID);
    }
    else
    {
#if(PDUR_MAX_NUMOFLINTPTXPDU > 0)
        SchM_Enter_PduR_PDUR_EXCLUSIVE_AREA_0();
        PathId = PDUR_LINTP_TXCONFPDUINFO(id).PathId;
        GroupId = PDUR_ROUTINGPATHINFO(PathId).PduRDestPdu.PduRRoutingGroup;
        if((PDUR_RPGROUP_NONE == GroupId) || (TRUE == PduR_RoutingPathGroupEnabled[GroupId]))
        {
            PduR_LowerTpTxConfirmation(PathId, PDUR_LINTP_TXCONFPDUINFO(id).UpperPduId, result);
        }
        SchM_Exit_PduR_PDUR_EXCLUSIVE_AREA_0();
#endif
    }
}

#endif

#if(STD_ON == PDUR_FRTP_MODULE_SUPPORT)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: PduR_FrTpStartOfReception    SWS_PduR_00507
*
* Description:     This function will be called by the transport protocol module at
*                the start of receiving an I-PDU. The I-PDU might be fragmented into
*                multiple N-PDUs (FF with one or more following CFs) or might consist
*                of a single N-PDU (SF). The service shall provide the currently
*                available maximum buffer size when invoked with TpSduLength equal to 0.
*
* Inputs:         id   Identification of the I-PDU.
*                 TpSduLength  Total length of the PDU to be received.
*
* Outputs:         bufferSizePtr  Available receive buffer in the receiving module.
*                               This parameter will be used to compute the Block
*                               Size (BS) in the transport protocol module
*
* Limitations:     None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(BufReq_ReturnType, PDUR_CODE) PduR_FrTpStartOfReception
(
    PduIdType id,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info,
    PduLengthType TpSduLength,
    P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) bufferSizePtr
)
{
    BufReq_ReturnType result = BUFREQ_E_NOT_OK;
#if(PDUR_MAX_NUMOFFRTPRXPDU > 0)
    P2CONST(PduRRoutingPduInfoType, AUTOMATIC, PDUR_CONST) pRxPduInfo;
#endif

    if(!PDUR_IS_INITIALIZED())
    {
        /*SWS_PduR_00328 SWS_PduR_00330 SWS_PduR_00119*/
        PDUR_DET_REPORT_ERROR(PDUR_FRTP_STARTOFRECEPTION_APIID, PDUR_E_INVALID_REQUEST);
    }
    else if(id >= PDUR_GET_NUM_FRTPRXPDU())
    {
        /*SWS_PduR_00221*/
        PDUR_DET_REPORT_ERROR(PDUR_FRTP_STARTOFRECEPTION_APIID, PDUR_E_PDU_ID_INVALID);
    }
    else if(NULL_PTR == bufferSizePtr)
    {
        PDUR_DET_REPORT_ERROR(PDUR_FRTP_STARTOFRECEPTION_APIID, PDUR_E_PARAM_POINTER);
    }
    else
    {
#if(PDUR_MAX_NUMOFFRTPRXPDU > 0)
        SchM_Enter_PduR_PDUR_EXCLUSIVE_AREA_0();
        pRxPduInfo = &(PDUR_FRTP_RXPDUINFO(id));
        result = PduR_LowerTpMultiStartOfReception(pRxPduInfo, info, TpSduLength, bufferSizePtr);
        SchM_Exit_PduR_PDUR_EXCLUSIVE_AREA_0();
#endif
    }

    return result;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: PduR_FrTpCopyRxData    SWS_PduR_00512
*
* Description:     This function is called when a transport protocol module has data
*                to copy for the receiving module. Several calls may be made during
*                one transportation of an I-PDU.
*
* Inputs:         id   Identification of the transmitted I-PDU.
*                 info Pointer to the buffer (SduDataPtr) and its length (SduLength)
*                      containing the data to be copied by PDU Router module in case
*                      of gateway or upper layer module in case of reception
*
* Outputs:         bufferSizePtr    Available receive buffer after data has been copied.
*
* Limitations:     None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(BufReq_ReturnType, PDUR_CODE) PduR_FrTpCopyRxData
(
    PduIdType id,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info,
    P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) bufferSizePtr
)
{
    BufReq_ReturnType result = BUFREQ_E_NOT_OK;
#if(PDUR_MAX_NUMOFFRTPRXPDU > 0)
    P2CONST(PduRRoutingPduInfoType, AUTOMATIC, PDUR_CONST) pRxPduInfo;
#endif

    if(!PDUR_IS_INITIALIZED())
    {
        /*SWS_PduR_00328 SWS_PduR_00330 SWS_PduR_00119*/
        PDUR_DET_REPORT_ERROR(PDUR_FRTP_COPYRXDATA_APIID, PDUR_E_INVALID_REQUEST);
    }
    else if(id >= PDUR_GET_NUM_FRTPRXPDU())
    {
        /*SWS_PduR_00221*/
        PDUR_DET_REPORT_ERROR(PDUR_FRTP_COPYRXDATA_APIID, PDUR_E_PDU_ID_INVALID);
    }
    else if(NULL_PTR == info)
    {
        PDUR_DET_REPORT_ERROR(PDUR_FRTP_COPYRXDATA_APIID, PDUR_E_PARAM_POINTER);
    }
    else if(NULL_PTR == bufferSizePtr)
    {
        PDUR_DET_REPORT_ERROR(PDUR_FRTP_COPYRXDATA_APIID, PDUR_E_PARAM_POINTER);
    }
    else
    {
#if(PDUR_MAX_NUMOFFRTPRXPDU > 0)
        SchM_Enter_PduR_PDUR_EXCLUSIVE_AREA_0();
        pRxPduInfo = &(PDUR_FRTP_RXPDUINFO(id));
        result = PduR_LowerTpMultiCopyRxData(pRxPduInfo, info, bufferSizePtr);
        SchM_Exit_PduR_PDUR_EXCLUSIVE_AREA_0();
#endif
    }

    return result;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: PduR_FrTpRxIndication    SWS_PduR_00375
*
* Description:     Called by the transport protocol module after an I-PDU has been
*                received successfully or when an error occurred. It is also used
*                to confirm cancellation of an I-PDU.
*
* Inputs:         id   Identification of the transmitted I-PDU.
*                 result Result of the reception.
*
* Outputs:         bufferSizePtr  Available receive buffer after data has been copied.
*
* Limitations:     None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, PDUR_CODE) PduR_FrTpRxIndication
(
    PduIdType id,
    Std_ReturnType result
)
{
#if(PDUR_MAX_NUMOFFRTPRXPDU > 0)
    P2CONST(PduRRoutingPduInfoType, AUTOMATIC, PDUR_CONST) pRxPduInfo;
#endif

    if(!PDUR_IS_INITIALIZED())
    {
        /*SWS_PduR_00328 SWS_PduR_00330 SWS_PduR_00119*/
        PDUR_DET_REPORT_ERROR(PDUR_FRTP_RXINDICATION_APIID, PDUR_E_INVALID_REQUEST);
    }
    else if(id >= PDUR_GET_NUM_FRTPRXPDU())
    {
        /*SWS_PduR_00221*/
        PDUR_DET_REPORT_ERROR(PDUR_FRTP_RXINDICATION_APIID, PDUR_E_PDU_ID_INVALID);
    }
    else
    {
#if(PDUR_MAX_NUMOFFRTPRXPDU > 0)
        SchM_Enter_PduR_PDUR_EXCLUSIVE_AREA_0();
        pRxPduInfo = &(PDUR_FRTP_RXPDUINFO(id));
        PduR_LowerTpMultiRxIndication(pRxPduInfo, result);
        SchM_Exit_PduR_PDUR_EXCLUSIVE_AREA_0();
#endif
    }
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: PduR_FrTpCopyTxData    SWS_PduR_00518
*
* Description:     This function is called by the transport protocol module to query
*                the transmit data of an I-PDU segment.
*
* Inputs:         id   Identification of the transmitted I-PDU.
*                 info Provides destination buffer and the number of bytes to copy.
*                     In case of gateway the PDU Router module will copy, otherwise
*                     the source upper layer module will copy the data. If not enough
*                     transmit data is available, no data is copied. The transport
*                     protocol module will retry. A copy size of 0 can be used to
*                     indicate state changes in the retry parameter.
*                retry This parameter is used to retransmit data because problems
*                      during the last service call.
*
*
* Outputs:         availableDataPtr  Indicates the remaining number of bytes that are
*                                  available in the PduR Tx buffer. AvailableTxDataCntPtr
*                                  can be used by TP modules that support dynamic payload
*                                  lengths (e.g. Iso FrTp) to determine the size of the
*                                  following CFs.
*
* Limitations:     None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(BufReq_ReturnType, PDUR_CODE) PduR_FrTpCopyTxData
(
    PduIdType id,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info,
    P2VAR(RetryInfoType, AUTOMATIC, PDUR_APPL_DATA) retry,
    P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) availableDataPtr
)
{
    BufReq_ReturnType result = BUFREQ_E_NOT_OK;
#if(PDUR_MAX_NUMOFFRTPTXPDU > 0)
    PduR_RoutingPathIdType PathId;
    PduR_RoutingPathGroupIdType GroupId;
#endif

    if(!PDUR_IS_INITIALIZED())
    {
        /*SWS_PduR_00328 SWS_PduR_00330 SWS_PduR_00119*/
        PDUR_DET_REPORT_ERROR(PDUR_FRTP_COPYTXDATA_APIID, PDUR_E_INVALID_REQUEST);
    }
    else if(id >= PDUR_GET_NUM_FRTPTXPDU())
    {
        /*SWS_PduR_00221*/
        PDUR_DET_REPORT_ERROR(PDUR_FRTP_COPYTXDATA_APIID, PDUR_E_PDU_ID_INVALID);
    }
    else if(NULL_PTR == info)
    {
        PDUR_DET_REPORT_ERROR(PDUR_FRTP_COPYTXDATA_APIID, PDUR_E_PARAM_POINTER);
    }
    else if(NULL_PTR == availableDataPtr)
    {
        PDUR_DET_REPORT_ERROR(PDUR_FRTP_COPYTXDATA_APIID, PDUR_E_PARAM_POINTER);
    }
    else
    {
#if(PDUR_MAX_NUMOFFRTPTXPDU > 0)
        SchM_Enter_PduR_PDUR_EXCLUSIVE_AREA_0();
        PathId = PDUR_FRTP_TXCONFPDUINFO(id).PathId;
        GroupId = PDUR_ROUTINGPATHINFO(PathId).PduRDestPdu.PduRRoutingGroup;
        if((PDUR_RPGROUP_NONE == GroupId) || (TRUE == PduR_RoutingPathGroupEnabled[GroupId]))
        {
            result = PduR_LowerTpCopyTxData(PathId, PDUR_FRTP_TXCONFPDUINFO(id).UpperPduId, info, retry, availableDataPtr);
        }
        SchM_Exit_PduR_PDUR_EXCLUSIVE_AREA_0();
#endif
    }
    return result;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: PduR_FrTpTxConfirmation    SWS_PduR_00381
*
* Description:     This function is called after the I-PDU has been transmitted on
*                 its network, the result indicates whether the transmission was
*                 successful or not
*
* Inputs:         id - Identification of the transmitted I-PDU.
*                 result - Result of the transmission of the I-PDU.
*
* Outputs:         None
*
* Limitations:     None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, PDUR_CODE) PduR_FrTpTxConfirmation
(
    PduIdType id,
    Std_ReturnType result
)
{
#if(PDUR_MAX_NUMOFFRTPTXPDU > 0)
    PduR_RoutingPathIdType PathId;
    PduR_RoutingPathGroupIdType GroupId;
#endif

    if(!PDUR_IS_INITIALIZED())
    {
        /*SWS_PduR_00328 SWS_PduR_00330 SWS_PduR_00119*/
        PDUR_DET_REPORT_ERROR(PDUR_FRTP_TXCONFIRMATION_APIID, PDUR_E_INVALID_REQUEST);
    }
    else if(id >= PDUR_GET_NUM_FRTPTXPDU())
    {
        /*SWS_PduR_00221*/
        PDUR_DET_REPORT_ERROR(PDUR_FRTP_TXCONFIRMATION_APIID, PDUR_E_PDU_ID_INVALID);
    }
    else
    {
#if(PDUR_MAX_NUMOFFRTPTXPDU > 0)
        SchM_Enter_PduR_PDUR_EXCLUSIVE_AREA_0();
        PathId = PDUR_FRTP_TXCONFPDUINFO(id).PathId;
        GroupId = PDUR_ROUTINGPATHINFO(PathId).PduRDestPdu.PduRRoutingGroup;
        if((PDUR_RPGROUP_NONE == GroupId) || (TRUE == PduR_RoutingPathGroupEnabled[GroupId]))
        {
            PduR_LowerTpTxConfirmation(PathId, PDUR_FRTP_TXCONFPDUINFO(id).UpperPduId, result);
        }
        SchM_Exit_PduR_PDUR_EXCLUSIVE_AREA_0();
#endif
    }
}

#endif

#if(STD_ON == PDUR_SOADTP_MODULE_SUPPORT)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: PduR_SoAdTpStartOfReception    SWS_PduR_00507
*
* Description:     This function will be called by the transport protocol module at
*                the start of receiving an I-PDU. The I-PDU might be fragmented into
*                multiple N-PDUs (FF with one or more following CFs) or might consist
*                of a single N-PDU (SF). The service shall provide the currently
*                available maximum buffer size when invoked with TpSduLength equal to 0.
*
* Inputs:         id   Identification of the I-PDU.
*                 TpSduLength  Total length of the PDU to be received.
*
* Outputs:         bufferSizePtr  Available receive buffer in the receiving module.
*                               This parameter will be used to compute the Block
*                               Size (BS) in the transport protocol module
*
* Limitations:     None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(BufReq_ReturnType, PDUR_CODE) PduR_SoAdTpStartOfReception
(
    PduIdType id,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info,
    PduLengthType TpSduLength,
    P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) bufferSizePtr
)
{
    BufReq_ReturnType result = BUFREQ_E_NOT_OK;
    P2CONST(PduRRoutingPduInfoType, AUTOMATIC, PDUR_CONST) pRxPduInfo;

    if(!PDUR_IS_INITIALIZED())
    {
        /*SWS_PduR_00328 SWS_PduR_00330 SWS_PduR_00119*/
        PDUR_DET_REPORT_ERROR(PDUR_SOADTP_STARTOFRECEPTION_APIID, PDUR_E_INVALID_REQUEST);
    }
    else if(id >= PDUR_GET_NUM_SOADTPRXPDU())
    {
        /*SWS_PduR_00221*/
        PDUR_DET_REPORT_ERROR(PDUR_SOADTP_STARTOFRECEPTION_APIID, PDUR_E_PDU_ID_INVALID);
    }
    else if(NULL_PTR == bufferSizePtr)
    {
        PDUR_DET_REPORT_ERROR(PDUR_SOADTP_STARTOFRECEPTION_APIID, PDUR_E_PARAM_POINTER);
    }
    else
    {
#if(PDUR_MAX_NUMOFSOADTPRXPDU > 0)
        SchM_Enter_PduR_PDUR_EXCLUSIVE_AREA_0();
        pRxPduInfo = &(PDUR_SOADTP_RXPDUINFO(id));
        result = PduR_LowerTpMultiStartOfReception(pRxPduInfo, info, TpSduLength, bufferSizePtr);
        SchM_Exit_PduR_PDUR_EXCLUSIVE_AREA_0();
#endif
    }

    return result;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: PduR_SoAdTpCopyRxData    SWS_PduR_00512
*
* Description:     This function is called when a transport protocol module has data
*                to copy for the receiving module. Several calls may be made during
*                one transportation of an I-PDU.
*
* Inputs:         id   Identification of the transmitted I-PDU.
*                 info Pointer to the buffer (SduDataPtr) and its length (SduLength)
*                      containing the data to be copied by PDU Router module in case
*                      of gateway or upper layer module in case of reception
*
* Outputs:         bufferSizePtr    Available receive buffer after data has been copied.
*
* Limitations:     None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(BufReq_ReturnType, PDUR_CODE) PduR_SoAdTpCopyRxData
(
    PduIdType id,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info,
    P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) bufferSizePtr
)
{
    BufReq_ReturnType result = BUFREQ_E_NOT_OK;
    P2CONST(PduRRoutingPduInfoType, AUTOMATIC, PDUR_CONST) pRxPduInfo;

    if(!PDUR_IS_INITIALIZED())
    {
        /*SWS_PduR_00328 SWS_PduR_00330 SWS_PduR_00119*/
        PDUR_DET_REPORT_ERROR(PDUR_SOADTP_COPYRXDATA_APIID, PDUR_E_INVALID_REQUEST);
    }
    else if(id >= PDUR_GET_NUM_SOADTPRXPDU())
    {
        /*SWS_PduR_00221*/
        PDUR_DET_REPORT_ERROR(PDUR_SOADTP_COPYRXDATA_APIID, PDUR_E_PDU_ID_INVALID);
    }
    else if(NULL_PTR == info)
    {
        PDUR_DET_REPORT_ERROR(PDUR_SOADTP_COPYRXDATA_APIID, PDUR_E_PARAM_POINTER);
    }
    else if(NULL_PTR == bufferSizePtr)
    {
        PDUR_DET_REPORT_ERROR(PDUR_SOADTP_COPYRXDATA_APIID, PDUR_E_PARAM_POINTER);
    }
    else
    {
#if(PDUR_MAX_NUMOFSOADTPRXPDU > 0)
        SchM_Enter_PduR_PDUR_EXCLUSIVE_AREA_0();
        pRxPduInfo = &(PDUR_SOADTP_RXPDUINFO(id));
        result = PduR_LowerTpMultiCopyRxData(pRxPduInfo, info, bufferSizePtr);
        SchM_Exit_PduR_PDUR_EXCLUSIVE_AREA_0();
#endif
    }

    return result;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: PduR_SoAdTpRxIndication    SWS_PduR_00375
*
* Description:     Called by the transport protocol module after an I-PDU has been
*                received successfully or when an error occurred. It is also used
*                to confirm cancellation of an I-PDU.
*
* Inputs:         id   Identification of the transmitted I-PDU.
*                 result Result of the reception.
*
* Outputs:         bufferSizePtr  Available receive buffer after data has been copied.
*
* Limitations:     None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, PDUR_CODE) PduR_SoAdTpRxIndication
(
    PduIdType id,
    Std_ReturnType result
)
{
    P2CONST(PduRRoutingPduInfoType, AUTOMATIC, PDUR_CONST) pRxPduInfo;

    if(!PDUR_IS_INITIALIZED())
    {
        /*SWS_PduR_00328 SWS_PduR_00330 SWS_PduR_00119*/
        PDUR_DET_REPORT_ERROR(PDUR_SOADTP_RXINDICATION_APIID, PDUR_E_INVALID_REQUEST);
    }
    else if(id >= PDUR_GET_NUM_SOADTPRXPDU())
    {
        /*SWS_PduR_00221*/
        PDUR_DET_REPORT_ERROR(PDUR_SOADTP_RXINDICATION_APIID, PDUR_E_PDU_ID_INVALID);
    }
    else
    {
#if(PDUR_MAX_NUMOFSOADTPRXPDU > 0)
        SchM_Enter_PduR_PDUR_EXCLUSIVE_AREA_0();
        pRxPduInfo = &(PDUR_SOADTP_RXPDUINFO(id));
        PduR_LowerTpMultiRxIndication(pRxPduInfo, result);
        SchM_Exit_PduR_PDUR_EXCLUSIVE_AREA_0();
#endif
    }
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: PduR_SoAdTpCopyTxData    SWS_PduR_00518
*
* Description:     This function is called by the transport protocol module to query
*                the transmit data of an I-PDU segment.
*
* Inputs:         id   Identification of the transmitted I-PDU.
*                 info Provides destination buffer and the number of bytes to copy.
*                     In case of gateway the PDU Router module will copy, otherwise
*                     the source upper layer module will copy the data. If not enough
*                     transmit data is available, no data is copied. The transport
*                     protocol module will retry. A copy size of 0 can be used to
*                     indicate state changes in the retry parameter.
*                retry This parameter is used to retransmit data because problems
*                      during the last service call.
*
*
* Outputs:         availableDataPtr  Indicates the remaining number of bytes that are
*                                  available in the PduR Tx buffer. AvailableTxDataCntPtr
*                                  can be used by TP modules that support dynamic payload
*                                  lengths (e.g. Iso FrTp) to determine the size of the
*                                  following CFs.
*
* Limitations:     None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(BufReq_ReturnType, PDUR_CODE) PduR_SoAdTpCopyTxData
(
    PduIdType id,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info,
    P2VAR(RetryInfoType, AUTOMATIC, PDUR_APPL_DATA) retry,
    P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) availableDataPtr
)
{
    BufReq_ReturnType result = BUFREQ_E_NOT_OK;
    PduR_RoutingPathIdType PathId;
    PduR_RoutingPathGroupIdType GroupId;

    if(!PDUR_IS_INITIALIZED())
    {
        /*SWS_PduR_00328 SWS_PduR_00330 SWS_PduR_00119*/
        PDUR_DET_REPORT_ERROR(PDUR_SOADTP_COPYTXDATA_APIID, PDUR_E_INVALID_REQUEST);
    }
    else if(id >= PDUR_GET_NUM_SOADTPTXPDU())
    {
        /*SWS_PduR_00221*/
        PDUR_DET_REPORT_ERROR(PDUR_SOADTP_COPYTXDATA_APIID, PDUR_E_PDU_ID_INVALID);
    }
    else if(NULL_PTR == info)
    {
        PDUR_DET_REPORT_ERROR(PDUR_SOADTP_COPYTXDATA_APIID, PDUR_E_PARAM_POINTER);
    }
    else if(NULL_PTR == availableDataPtr)
    {
        PDUR_DET_REPORT_ERROR(PDUR_SOADTP_COPYTXDATA_APIID, PDUR_E_PARAM_POINTER);
    }
    else
    {
#if(PDUR_MAX_NUMOFSOADTPTXPDU > 0)
        SchM_Enter_PduR_PDUR_EXCLUSIVE_AREA_0();
        PathId = PDUR_SOADTP_TXCONFPDUINFO(id).PathId;
        GroupId = PDUR_ROUTINGPATHINFO(PathId).PduRDestPdu.PduRRoutingGroup;
        if((PDUR_RPGROUP_NONE == GroupId) || (TRUE == PduR_RoutingPathGroupEnabled[GroupId]))
        {
            result = PduR_LowerTpCopyTxData(PathId, PDUR_SOADTP_TXCONFPDUINFO(id).UpperPduId, info, retry, availableDataPtr);
        }
        SchM_Exit_PduR_PDUR_EXCLUSIVE_AREA_0();
#endif
    }
    return result;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: PduR_SoAdTpTxConfirmation    SWS_PduR_00381
*
* Description:     This function is called after the I-PDU has been transmitted on
*                 its network, the result indicates whether the transmission was
*                 successful or not
*
* Inputs:         id - Identification of the transmitted I-PDU.
*                 result - Result of the transmission of the I-PDU.
*
* Outputs:         None
*
* Limitations:     None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, PDUR_CODE) PduR_SoAdTpTxConfirmation
(
    PduIdType id,
    Std_ReturnType result
)
{
    PduR_RoutingPathIdType PathId;
    PduR_RoutingPathGroupIdType GroupId;

    if(!PDUR_IS_INITIALIZED())
    {
        /*SWS_PduR_00328 SWS_PduR_00330 SWS_PduR_00119*/
        PDUR_DET_REPORT_ERROR(PDUR_SOADTP_TXCONFIRMATION_APIID, PDUR_E_INVALID_REQUEST);
    }
    else if(id >= PDUR_GET_NUM_SOADTPTXPDU())
    {
        /*SWS_PduR_00221*/
        PDUR_DET_REPORT_ERROR(PDUR_SOADTP_TXCONFIRMATION_APIID, PDUR_E_PDU_ID_INVALID);
    }
    else
    {
#if(PDUR_MAX_NUMOFSOADTPTXPDU > 0)
        SchM_Enter_PduR_PDUR_EXCLUSIVE_AREA_0();
        PathId = PDUR_SOADTP_TXCONFPDUINFO(id).PathId;
        GroupId = PDUR_ROUTINGPATHINFO(PathId).PduRDestPdu.PduRRoutingGroup;
        if((PDUR_RPGROUP_NONE == GroupId) || (TRUE == PduR_RoutingPathGroupEnabled[GroupId]))
        {
            PduR_LowerTpTxConfirmation(PathId, PDUR_SOADTP_TXCONFPDUINFO(id).UpperPduId, result);
        }
        SchM_Exit_PduR_PDUR_EXCLUSIVE_AREA_0();
#endif
    }
}

#endif

#if(STD_ON == PDUR_CDDTP_MODULE_SUPPORT)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: PduR_CddTpStartOfReception    SWS_PduR_00507
*
* Description:     This function will be called by the transport protocol module at
*                the start of receiving an I-PDU. The I-PDU might be fragmented into
*                multiple N-PDUs (FF with one or more following CFs) or might consist
*                of a single N-PDU (SF). The service shall provide the currently
*                available maximum buffer size when invoked with TpSduLength equal to 0.
*
* Inputs:         id   Identification of the I-PDU.
*                 TpSduLength  Total length of the PDU to be received.
*
* Outputs:         bufferSizePtr  Available receive buffer in the receiving module.
*                               This parameter will be used to compute the Block
*                               Size (BS) in the transport protocol module
*
* Limitations:     None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(BufReq_ReturnType, PDUR_CODE) PduR_CddTpStartOfReception
(
    PduIdType id,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info,
    PduLengthType TpSduLength,
    P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) bufferSizePtr
)
{
    BufReq_ReturnType result = BUFREQ_E_NOT_OK;
    P2CONST(PduRRoutingPduInfoType, AUTOMATIC, PDUR_CONST) pRxPduInfo;

    if(!PDUR_IS_INITIALIZED())
    {
        /*SWS_PduR_00328 SWS_PduR_00330 SWS_PduR_00119*/
        PDUR_DET_REPORT_ERROR(PDUR_CDDTP_STARTOFRECEPTION_APIID, PDUR_E_INVALID_REQUEST);
    }
    else if(id >= PDUR_GET_NUM_CDDTPRXPDU())
    {
        /*SWS_PduR_00221*/
        PDUR_DET_REPORT_ERROR(PDUR_CDDTP_STARTOFRECEPTION_APIID, PDUR_E_PDU_ID_INVALID);
    }
    else if(NULL_PTR == bufferSizePtr)
    {
        PDUR_DET_REPORT_ERROR(PDUR_CDDTP_STARTOFRECEPTION_APIID, PDUR_E_PARAM_POINTER);
    }
    else
    {
#if(PDUR_MAX_NUMOFCDDTPRXPDU > 0)
        SchM_Enter_PduR_PDUR_EXCLUSIVE_AREA_0();
        pRxPduInfo = &(PDUR_CDDTP_RXPDUINFO(id));
        result = PduR_LowerTpMultiStartOfReception(pRxPduInfo, info, TpSduLength, bufferSizePtr);
        SchM_Exit_PduR_PDUR_EXCLUSIVE_AREA_0();
#endif
    }

    return result;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: PduR_CddTpCopyRxData    SWS_PduR_00512
*
* Description:     This function is called when a transport protocol module has data
*                to copy for the receiving module. Several calls may be made during
*                one transportation of an I-PDU.
*
* Inputs:         id   Identification of the transmitted I-PDU.
*                 info Pointer to the buffer (SduDataPtr) and its length (SduLength)
*                      containing the data to be copied by PDU Router module in case
*                      of gateway or upper layer module in case of reception
*
* Outputs:         bufferSizePtr    Available receive buffer after data has been copied.
*
* Limitations:     None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(BufReq_ReturnType, PDUR_CODE) PduR_CddTpCopyRxData
(
    PduIdType id,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info,
    P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) bufferSizePtr
)
{
    BufReq_ReturnType result = BUFREQ_E_NOT_OK;
    P2CONST(PduRRoutingPduInfoType, AUTOMATIC, PDUR_CONST) pRxPduInfo;

    if(!PDUR_IS_INITIALIZED())
    {
        /*SWS_PduR_00328 SWS_PduR_00330 SWS_PduR_00119*/
        PDUR_DET_REPORT_ERROR(PDUR_CDDTP_COPYRXDATA_APIID, PDUR_E_INVALID_REQUEST);
    }
    else if(id >= PDUR_GET_NUM_CDDTPRXPDU())
    {
        /*SWS_PduR_00221*/
        PDUR_DET_REPORT_ERROR(PDUR_CDDTP_COPYRXDATA_APIID, PDUR_E_PDU_ID_INVALID);
    }
    else if(NULL_PTR == info)
    {
        PDUR_DET_REPORT_ERROR(PDUR_CDDTP_COPYRXDATA_APIID, PDUR_E_PARAM_POINTER);
    }
    else if(NULL_PTR == bufferSizePtr)
    {
        PDUR_DET_REPORT_ERROR(PDUR_CDDTP_COPYRXDATA_APIID, PDUR_E_PARAM_POINTER);
    }
    else
    {
#if(PDUR_MAX_NUMOFCDDTPRXPDU > 0)
        SchM_Enter_PduR_PDUR_EXCLUSIVE_AREA_0();
        pRxPduInfo = &(PDUR_CDDTP_RXPDUINFO(id));
        result = PduR_LowerTpMultiCopyRxData(pRxPduInfo, info, bufferSizePtr);
        SchM_Exit_PduR_PDUR_EXCLUSIVE_AREA_0();
#endif
    }

    return result;
}


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: PduR_CddTpRxIndication    SWS_PduR_00375
*
* Description:     Called by the transport protocol module after an I-PDU has been
*                received successfully or when an error occurred. It is also used
*                to confirm cancellation of an I-PDU.
*
* Inputs:         id   Identification of the transmitted I-PDU.
*                 result Result of the reception.
*
* Outputs:         bufferSizePtr  Available receive buffer after data has been copied.
*
* Limitations:     None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, PDUR_CODE) PduR_CddTpRxIndication
(
    PduIdType id,
    NotifResultType result
)
{
    P2CONST(PduRRoutingPduInfoType, AUTOMATIC, PDUR_CONST) pRxPduInfo;

    if(!PDUR_IS_INITIALIZED())
    {
        /*SWS_PduR_00328 SWS_PduR_00330 SWS_PduR_00119*/
        PDUR_DET_REPORT_ERROR(PDUR_CDDTP_RXINDICATION_APIID, PDUR_E_INVALID_REQUEST);
    }
    else if(id >= PDUR_GET_NUM_CDDTPRXPDU())
    {
        /*SWS_PduR_00221*/
        PDUR_DET_REPORT_ERROR(PDUR_CDDTP_RXINDICATION_APIID, PDUR_E_PDU_ID_INVALID);
    }
    else
    {
#if(PDUR_MAX_NUMOFCDDTPRXPDU > 0)
        SchM_Enter_PduR_PDUR_EXCLUSIVE_AREA_0();
        pRxPduInfo = &(PDUR_CDDTP_RXPDUINFO(id));
        PduR_LowerTpMultiRxIndication(pRxPduInfo, result);
        SchM_Exit_PduR_PDUR_EXCLUSIVE_AREA_0();
#endif
    }
}


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: PduR_CddTpCopyTxData    SWS_PduR_00518
*
* Description:     This function is called by the transport protocol module to query
*                the transmit data of an I-PDU segment.
*
* Inputs:         id   Identification of the transmitted I-PDU.
*                 info Provides destination buffer and the number of bytes to copy.
*                     In case of gateway the PDU Router module will copy, otherwise
*                     the source upper layer module will copy the data. If not enough
*                     transmit data is available, no data is copied. The transport
*                     protocol module will retry. A copy size of 0 can be used to
*                     indicate state changes in the retry parameter.
*                retry This parameter is used to retransmit data because problems
*                      during the last service call.
*
*
* Outputs:         availableDataPtr  Indicates the remaining number of bytes that are
*                                  available in the PduR Tx buffer. AvailableTxDataCntPtr
*                                  can be used by TP modules that support dynamic payload
*                                  lengths (e.g. Iso FrTp) to determine the size of the
*                                  following CFs.
*
* Limitations:     None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(BufReq_ReturnType, PDUR_CODE) PduR_CddTpCopyTxData
(
    PduIdType id,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info,
    P2VAR(RetryInfoType, AUTOMATIC, PDUR_APPL_DATA) retry,
    P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) availableDataPtr
)
{
    BufReq_ReturnType result = BUFREQ_E_NOT_OK;
    PduR_RoutingPathIdType PathId;
    PduR_RoutingPathGroupIdType GroupId;

    if(!PDUR_IS_INITIALIZED())
    {
        /*SWS_PduR_00328 SWS_PduR_00330 SWS_PduR_00119*/
        PDUR_DET_REPORT_ERROR(PDUR_CDDTP_COPYTXDATA_APIID, PDUR_E_INVALID_REQUEST);
    }
    else if(id >= PDUR_GET_NUM_CDDTPTXPDU())
    {
        /*SWS_PduR_00221*/
        PDUR_DET_REPORT_ERROR(PDUR_CDDTP_COPYTXDATA_APIID, PDUR_E_PDU_ID_INVALID);
    }
    else if(NULL_PTR == info)
    {
        PDUR_DET_REPORT_ERROR(PDUR_CDDTP_COPYTXDATA_APIID, PDUR_E_PARAM_POINTER);
    }
    else if(NULL_PTR == availableDataPtr)
    {
        PDUR_DET_REPORT_ERROR(PDUR_CDDTP_COPYTXDATA_APIID, PDUR_E_PARAM_POINTER);
    }
    else
    {
#if(PDUR_MAX_NUMOFCDDTPTXPDU > 0)
        SchM_Enter_PduR_PDUR_EXCLUSIVE_AREA_0();
        PathId = PDUR_CDDTP_TXCONFPDUINFO(id).PathId;
        GroupId = PDUR_ROUTINGPATHINFO(PathId).PduRDestPdu.PduRRoutingGroup;
        if((PDUR_RPGROUP_NONE == GroupId) || (TRUE == PduR_RoutingPathGroupEnabled[GroupId]))
        {
            result = PduR_LowerTpCopyTxData(PathId, PDUR_CDDTP_TXCONFPDUINFO(id).UpperPduId, info, retry, availableDataPtr);
        }
        SchM_Exit_PduR_PDUR_EXCLUSIVE_AREA_0();
#endif
    }
    return result;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: PduR_CddTpTxConfirmation    SWS_PduR_00381
*
* Description:     This function is called after the I-PDU has been transmitted on
*                 its network, the result indicates whether the transmission was
*                 successful or not
*
* Inputs:         id - Identification of the transmitted I-PDU.
*                 result - Result of the transmission of the I-PDU.
*
* Outputs:         None
*
* Limitations:     None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, PDUR_CODE) PduR_CddTpTxConfirmation
(
    PduIdType id,
    Std_ReturnType result
)
{
    PduR_RoutingPathIdType PathId;
    PduR_RoutingPathGroupIdType GroupId;

    if(!PDUR_IS_INITIALIZED())
    {
        /*SWS_PduR_00328 SWS_PduR_00330 SWS_PduR_00119*/
        PDUR_DET_REPORT_ERROR(PDUR_CDDTP_TXCONFIRMATION_APIID, PDUR_E_INVALID_REQUEST);
    }
    else if(id >= PDUR_GET_NUM_CDDTPTXPDU())
    {
        /*SWS_PduR_00221*/
        PDUR_DET_REPORT_ERROR(PDUR_CDDTP_TXCONFIRMATION_APIID, PDUR_E_PDU_ID_INVALID);
    }
    else
    {
#if(PDUR_MAX_NUMOFCDDTPTXPDU > 0)
        SchM_Enter_PduR_PDUR_EXCLUSIVE_AREA_0();
        PathId = PDUR_CDDTP_TXCONFPDUINFO(id).PathId;
        GroupId = PDUR_ROUTINGPATHINFO(PathId).PduRDestPdu.PduRRoutingGroup;
        if((PDUR_RPGROUP_NONE == GroupId) || (TRUE == PduR_RoutingPathGroupEnabled[GroupId]))
        {
            PduR_LowerTpTxConfirmation(PathId, PDUR_CDDTP_TXCONFPDUINFO(id).UpperPduId, result);
        }
        SchM_Exit_PduR_PDUR_EXCLUSIVE_AREA_0();
#endif
    }
}
#endif/*#if(STD_ON == PDUR_CDDTP_MODULE_SUPPORT)*/

#if(STD_ON == PDUR_DOIPTP_MODULE_SUPPORT)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: PduR_DoIPTpStartOfReception    SWS_PduR_00507
*
* Description:     This function is called at the start of receiving an N-SDU.
*                The N-SDU might be fragmented into multiple N-PDUs (FF with one
*                or more following CFs) or might consist of a single N-PDU (SF).
*
* Inputs:         id   Identification of the I-PDU.
*                 TpSduLength  Total length of the PDU to be received.
*
* Outputs:         bufferSizePtr  Available receive buffer in the receiving module.
*                               This parameter will be used to compute the Block
*                               Size (BS) in the transport protocol module
*
* Limitations:     None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(BufReq_ReturnType, PDUR_CODE) PduR_DoIPTpStartOfReception
(
    PduIdType id,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info,
    PduLengthType TpSduLength,
    P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) bufferSizePtr
)
{
    BufReq_ReturnType result = BUFREQ_E_NOT_OK;
    P2CONST(PduRRoutingPduInfoType, AUTOMATIC, PDUR_CONST) pRxPduInfo;

    if(!PDUR_IS_INITIALIZED())
    {
        /*SWS_PduR_00328 SWS_PduR_00330 SWS_PduR_00119*/
        PDUR_DET_REPORT_ERROR(PDUR_DOIPTP_STARTOFRECEPTION_APIID, PDUR_E_INVALID_REQUEST);
    }
    else if(id >= PDUR_GET_NUM_DOIPTPRXPDU())
    {
        /*SWS_PduR_00221*/
        PDUR_DET_REPORT_ERROR(PDUR_DOIPTP_STARTOFRECEPTION_APIID, PDUR_E_PDU_ID_INVALID);
    }
    else if(NULL_PTR == bufferSizePtr)
    {
        PDUR_DET_REPORT_ERROR(PDUR_DOIPTP_STARTOFRECEPTION_APIID, PDUR_E_PARAM_POINTER);
    }
    else
    {
#if(PDUR_MAX_NUMOFDOIPTPRXPDU > 0)
        SchM_Enter_PduR_PDUR_EXCLUSIVE_AREA_0();
        pRxPduInfo = &(PDUR_DOIPTP_RXPDUINFO(id));
        result = PduR_LowerTpMultiStartOfReception(pRxPduInfo, info, TpSduLength, bufferSizePtr);
        SchM_Exit_PduR_PDUR_EXCLUSIVE_AREA_0();
#endif
    }

    return result;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: PduR_DoIPTpCopyRxData    SWS_PduR_00512
*
* Description:     This function is called when a transport protocol module has data
*                to copy for the receiving module. Several calls may be made during
*                one transportation of an I-PDU.
*
* Inputs:         id   Identification of the transmitted I-PDU.
*                 info Pointer to the buffer (SduDataPtr) and its length (SduLength)
*                      containing the data to be copied by PDU Router module in case
*                      of gateway or upper layer module in case of reception
*
* Outputs:         bufferSizePtr    Available receive buffer after data has been copied.
*
* Limitations:     None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(BufReq_ReturnType, PDUR_CODE) PduR_DoIPTpCopyRxData
(
    PduIdType id,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info,
    P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) bufferSizePtr
)
{
    BufReq_ReturnType result = BUFREQ_E_NOT_OK;
    P2CONST(PduRRoutingPduInfoType, AUTOMATIC, PDUR_CONST) pRxPduInfo;

    if(!PDUR_IS_INITIALIZED())
    {
        /*SWS_PduR_00328 SWS_PduR_00330 SWS_PduR_00119*/
        PDUR_DET_REPORT_ERROR(PDUR_DOIPTP_COPYRXDATA_APIID, PDUR_E_INVALID_REQUEST);
    }
    else if(id >= PDUR_GET_NUM_DOIPTPRXPDU())
    {
        /*SWS_PduR_00221*/
        PDUR_DET_REPORT_ERROR(PDUR_DOIPTP_COPYRXDATA_APIID, PDUR_E_PDU_ID_INVALID);
    }
    else if(NULL_PTR == info)
    {
        PDUR_DET_REPORT_ERROR(PDUR_DOIPTP_COPYRXDATA_APIID, PDUR_E_PARAM_POINTER);
    }
    else
    {
#if(PDUR_MAX_NUMOFDOIPTPRXPDU > 0)
        SchM_Enter_PduR_PDUR_EXCLUSIVE_AREA_0();
        pRxPduInfo = &(PDUR_DOIPTP_RXPDUINFO(id));
        result = PduR_LowerTpMultiCopyRxData(pRxPduInfo, info, bufferSizePtr);
        SchM_Exit_PduR_PDUR_EXCLUSIVE_AREA_0();
#endif
    }

    return result;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: PduR_DoIPRxIndication    SWS_PduR_00375
*
* Description:     Called by the transport protocol module after an I-PDU has been
*                received successfully or when an error occurred. It is also used
*                to confirm cancellation of an I-PDU.
*
* Inputs:         id   Identification of the transmitted I-PDU.
*                 result Result of the reception.
*
* Outputs:         bufferSizePtr  Available receive buffer after data has been copied.
*
* Limitations:     None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, PDUR_CODE) PduR_DoIPTpRxIndication
(
    PduIdType id,
    Std_ReturnType result
)
{
    P2CONST(PduRRoutingPduInfoType, AUTOMATIC, PDUR_CONST) pRxPduInfo;

    if(!PDUR_IS_INITIALIZED())
    {
        /*SWS_PduR_00328 SWS_PduR_00330 SWS_PduR_00119*/
        PDUR_DET_REPORT_ERROR(PDUR_DOIPTP_RXINDICATION_APIID, PDUR_E_INVALID_REQUEST);
    }
    else if(id >= PDUR_GET_NUM_DOIPTPRXPDU())
    {
        /*SWS_PduR_00221*/
        PDUR_DET_REPORT_ERROR(PDUR_DOIPTP_RXINDICATION_APIID, PDUR_E_PDU_ID_INVALID);
    }
    else
    {
#if(PDUR_MAX_NUMOFDOIPTPRXPDU > 0)
        SchM_Enter_PduR_PDUR_EXCLUSIVE_AREA_0();
        pRxPduInfo = &(PDUR_DOIPTP_RXPDUINFO(id));
        PduR_LowerTpMultiRxIndication(pRxPduInfo, result);
        SchM_Exit_PduR_PDUR_EXCLUSIVE_AREA_0();
#endif
    }
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: PduR_DoIPTpCopyTxData    SWS_PduR_00518
*
* Description:     This function is called by the transport protocol module to query
*                the transmit data of an I-PDU segment.
*
* Inputs:         id   Identification of the transmitted I-PDU.
*                 info Provides destination buffer and the number of bytes to copy.
*                     In case of gateway the PDU Router module will copy, otherwise
*                     the source upper layer module will copy the data. If not enough
*                     transmit data is available, no data is copied. The transport
*                     protocol module will retry. A copy size of 0 can be used to
*                     indicate state changes in the retry parameter.
*                retry This parameter is used to retransmit data because problems
*                      during the last service call.
*
*
* Outputs:         availableDataPtr  Indicates the remaining number of bytes that are
*                                  available in the PduR Tx buffer. AvailableTxDataCntPtr
*                                  can be used by TP modules that support dynamic payload
*                                  lengths (e.g. Iso FrTp) to determine the size of the
*                                  following CFs.
*
* Limitations:     None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(BufReq_ReturnType, PDUR_CODE) PduR_DoIPTpCopyTxData
(
    PduIdType id,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info,
    P2VAR(RetryInfoType, AUTOMATIC, PDUR_APPL_DATA) retry,
    P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) availableDataPtr
)
{
    BufReq_ReturnType result = BUFREQ_E_NOT_OK;
    PduR_RoutingPathIdType PathId;
    PduR_RoutingPathGroupIdType GroupId;

    if(!PDUR_IS_INITIALIZED())
    {
        /*SWS_PduR_00328 SWS_PduR_00330 SWS_PduR_00119*/
        PDUR_DET_REPORT_ERROR(PDUR_DOIPTP_COPYTXDATA_APIID, PDUR_E_INVALID_REQUEST);
    }
    else if(id >= PDUR_GET_NUM_DOIPTPTXPDU())
    {
        /*SWS_PduR_00221*/
        PDUR_DET_REPORT_ERROR(PDUR_DOIPTP_COPYTXDATA_APIID, PDUR_E_PDU_ID_INVALID);
    }
    else if(NULL_PTR == info)
    {
        PDUR_DET_REPORT_ERROR(PDUR_DOIPTP_COPYTXDATA_APIID, PDUR_E_PARAM_POINTER);
    }
    else if(NULL_PTR == availableDataPtr)
    {
        PDUR_DET_REPORT_ERROR(PDUR_DOIPTP_COPYTXDATA_APIID, PDUR_E_PARAM_POINTER);
    }
    else
    {
#if(PDUR_MAX_NUMOFDOIPTPTXPDU > 0)
        SchM_Enter_PduR_PDUR_EXCLUSIVE_AREA_0();
        PathId = PDUR_DOIPTP_TXCONFPDUINFO(id).PathId;
        GroupId = PDUR_ROUTINGPATHINFO(PathId).PduRDestPdu.PduRRoutingGroup;
        if((PDUR_RPGROUP_NONE == GroupId) || (TRUE == PduR_RoutingPathGroupEnabled[GroupId]))
        {
            result = PduR_LowerTpCopyTxData(PathId, PDUR_DOIPTP_TXCONFPDUINFO(id).UpperPduId, info, retry, availableDataPtr);
        }
        SchM_Exit_PduR_PDUR_EXCLUSIVE_AREA_0();
#endif
    }
    return result;
}


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: PduR_DoIPTpTxConfirmation    SWS_PduR_00381
*
* Description:     This function is called after the I-PDU has been transmitted on
*                its network, the result indicates whether the transmission was
*                successful or not
*
* Inputs:         id - Identification of the transmitted I-PDU.
*                result - Result of the transmission of the I-PDU.
*
* Outputs:         None
*
* Limitations:     None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, PDUR_CODE) PduR_DoIPTpTxConfirmation
(
    PduIdType id,
    Std_ReturnType result
)
{
    PduR_RoutingPathIdType PathId;
    PduR_RoutingPathGroupIdType GroupId;

    if(!PDUR_IS_INITIALIZED())
    {
        /*SWS_PduR_00328 SWS_PduR_00330 SWS_PduR_00119*/
        PDUR_DET_REPORT_ERROR(PDUR_DOIPTP_TXCONFIRMATION_APIID, PDUR_E_INVALID_REQUEST);
    }
    else if(id >= PDUR_GET_NUM_DOIPTPTXPDU())
    {
        /*SWS_PduR_00221*/
        PDUR_DET_REPORT_ERROR(PDUR_DOIPTP_TXCONFIRMATION_APIID, PDUR_E_PDU_ID_INVALID);
    }
    else
    {
#if(PDUR_MAX_NUMOFDOIPTPTXPDU > 0)
        SchM_Enter_PduR_PDUR_EXCLUSIVE_AREA_0();
        PathId = PDUR_DOIPTP_TXCONFPDUINFO(id).PathId;
        GroupId = PDUR_ROUTINGPATHINFO(PathId).PduRDestPdu.PduRRoutingGroup;
        if((PDUR_RPGROUP_NONE == GroupId) || (TRUE == PduR_RoutingPathGroupEnabled[GroupId]))
        {
            PduR_LowerTpTxConfirmation(PathId, PDUR_DOIPTP_TXCONFPDUINFO(id).UpperPduId, result);
        }
        SchM_Exit_PduR_PDUR_EXCLUSIVE_AREA_0();
#endif
    }
}

#endif

#if(STD_ON == PDUR_J1939TP_MODULE_SUPPORT)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: PduR_J1939TpStartOfReception    SWS_PduR_00507
*
* Description:     This function is called by the transport protocol module to query
*                the transmit data of an I-PDU segment.
*
* Inputs:         id   Identification of the transmitted I-PDU.
*                 TpSduLength  Total length of the PDU to be received.
*
* Outputs:         bufferSizePtr  Available receive buffer in the receiving module.
*                               This parameter will be used to compute the Block
*                               Size (BS) in the transport protocol module
*
* Limitations:     None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(BufReq_ReturnType, PDUR_CODE) PduR_J1939TpStartOfReception
(
    PduIdType id,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info,
    PduLengthType TpSduLength,
    P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) bufferSizePtr
)
{
    BufReq_ReturnType result = BUFREQ_E_NOT_OK;
    P2CONST(PduRRoutingPduInfoType, AUTOMATIC, PDUR_CONST) pRxPduInfo;

    if(!PDUR_IS_INITIALIZED())
    {
        /*SWS_PduR_00328 SWS_PduR_00330 SWS_PduR_00119*/
        PDUR_DET_REPORT_ERROR(PDUR_J1939TP_STARTOFRECEPTION_APIID, PDUR_E_INVALID_REQUEST);
    }
    else if(id >= PDUR_GET_NUM_J1939TPRXPDU())
    {
        /*SWS_PduR_00221*/
        PDUR_DET_REPORT_ERROR(PDUR_J1939TP_STARTOFRECEPTION_APIID, PDUR_E_PDU_ID_INVALID);
    }
    else if(NULL_PTR == bufferSizePtr)
    {
        PDUR_DET_REPORT_ERROR(PDUR_J1939TP_STARTOFRECEPTION_APIID, PDUR_E_PARAM_POINTER);
    }
    else
    {
#if(PDUR_MAX_NUMOFJ1939TPRXPDU > 0)
        SchM_Enter_PduR_PDUR_EXCLUSIVE_AREA_0();
        pRxPduInfo = &(PDUR_J1939TP_RXPDUINFO(id));
        result = PduR_LowerTpMultiStartOfReception(pRxPduInfo, info, TpSduLength, bufferSizePtr);
        SchM_Exit_PduR_PDUR_EXCLUSIVE_AREA_0();
#endif
    }

    return result;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: PduR_J1939TpCopyRxData    SWS_PduR_00512
*
* Description:     This function is called by the transport protocol module to query
*                the transmit data of an I-PDU segment.
*
* Inputs:         id   Identification of the transmitted I-PDU.
*                 info Pointer to the buffer (SduDataPtr) and its length (SduLength)
*                     containing the data to be copied by PDU Router module in case
*                     of gateway or upper layer module in case of reception
*
* Outputs:         bufferSizePtr  Available receive buffer after data has been copied.
*
* Limitations:     None
********************************************************************************
END_FUNCTION_HDR*/
BufReq_ReturnType PduR_J1939TpCopyRxData
(
    PduIdType id,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info,
    P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) bufferSizePtr
)
{
    BufReq_ReturnType result = BUFREQ_E_NOT_OK;
    P2CONST(PduRRoutingPduInfoType, AUTOMATIC, PDUR_CONST) pRxPduInfo;

    if(!PDUR_IS_INITIALIZED())
    {
        /*SWS_PduR_00328 SWS_PduR_00330 SWS_PduR_00119*/
        PDUR_DET_REPORT_ERROR(PDUR_J1939TP_COPYRXDATA_APIID, PDUR_E_INVALID_REQUEST);
    }
    else if(id >= PDUR_GET_NUM_J1939TPRXPDU())
    {
        /*SWS_PduR_00221*/
        PDUR_DET_REPORT_ERROR(PDUR_J1939TP_COPYRXDATA_APIID, PDUR_E_PDU_ID_INVALID);
    }
    else if(NULL_PTR == info)
    {
        PDUR_DET_REPORT_ERROR(PDUR_J1939TP_COPYRXDATA_APIID, PDUR_E_PARAM_POINTER);
    }
    else if(NULL_PTR == bufferSizePtr)
    {
        PDUR_DET_REPORT_ERROR(PDUR_J1939TP_COPYRXDATA_APIID, PDUR_E_PARAM_POINTER);
    }
    else
    {
#if(PDUR_MAX_NUMOFJ1939TPRXPDU > 0)
        SchM_Enter_PduR_PDUR_EXCLUSIVE_AREA_0();
        pRxPduInfo = &(PDUR_J1939TP_RXPDUINFO(id));
        result = PduR_LowerTpMultiCopyRxData(pRxPduInfo, info, bufferSizePtr);
        SchM_Exit_PduR_PDUR_EXCLUSIVE_AREA_0();
#endif
    }

    return result;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: PduR_J1939TpRxIndication    SWS_PduR_00375
*
* Description:     This function is called by the transport protocol module to query
*                the transmit data of an I-PDU segment.
*
* Inputs:         id   Identification of the transmitted I-PDU.
*                 result Result of the reception.
*
* Outputs:         bufferSizePtr  Available receive buffer after data has been copied.
*
* Limitations:     None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, PDUR_CODE) PduR_J1939TpRxIndication
(
    PduIdType id,
    NotifResultType result
)
{
    P2CONST(PduRRoutingPduInfoType, AUTOMATIC, PDUR_CONST) pRxPduInfo;

    if(!PDUR_IS_INITIALIZED())
    {
        /*SWS_PduR_00328 SWS_PduR_00330 SWS_PduR_00119*/
        PDUR_DET_REPORT_ERROR(PDUR_J1939TP_RXINDICATION_APIID, PDUR_E_INVALID_REQUEST);
    }
    else if(id >= PDUR_GET_NUM_J1939TPRXPDU())
    {
        /*SWS_PduR_00221*/
        PDUR_DET_REPORT_ERROR(PDUR_J1939TP_RXINDICATION_APIID, PDUR_E_PDU_ID_INVALID);
    }
    else
    {
#if(PDUR_MAX_NUMOFJ1939TPRXPDU > 0)
        SchM_Enter_PduR_PDUR_EXCLUSIVE_AREA_0();
        pRxPduInfo = &(PDUR_J1939TP_RXPDUINFO(id));
        PduR_LowerTpMultiRxIndication(pRxPduInfo, result);
        SchM_Exit_PduR_PDUR_EXCLUSIVE_AREA_0();
#endif
    }
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: PduR_J1939TpCopyTxData    SWS_PduR_00518
*
* Description:     This function is called by the transport protocol module to query
*                the transmit data of an I-PDU segment.
*
* Inputs:         id   Identification of the transmitted I-PDU.
*                 info Provides destination buffer and the number of bytes to copy.
*                     In case of gateway the PDU Router module will copy, otherwise
*                     the source upper layer module will copy the data. If not enough
*                     transmit data is available, no data is copied. The transport
*                     protocol module will retry. A copy size of 0 can be used to
*                     indicate state changes in the retry parameter.
*                retry This parameter is used to retransmit data because problems
*                      during the last service call.
*
*
* Outputs:         availableDataPtr  Indicates the remaining number of bytes that are
*                                  available in the PduR Tx buffer. AvailableTxDataCntPtr
*                                  can be used by TP modules that support dynamic payload
*                                  lengths (e.g. Iso FrTp) to determine the size of the
*                                  following CFs.
*
* Limitations:     None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(BufReq_ReturnType, PDUR_CODE) PduR_J1939TpCopyTxData
(
    PduIdType id,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info,
    P2VAR(RetryInfoType, AUTOMATIC, PDUR_APPL_DATA) retry,
    P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) availableDataPtr
)
{
    BufReq_ReturnType result = BUFREQ_E_NOT_OK;
    PduR_RoutingPathIdType PathId;
    PduR_RoutingPathGroupIdType GroupId;

    if(!PDUR_IS_INITIALIZED())
    {
        /*SWS_PduR_00328 SWS_PduR_00330 SWS_PduR_00119*/
        PDUR_DET_REPORT_ERROR(PDUR_J1939TP_COPYTXDATA_APIID, PDUR_E_INVALID_REQUEST);
    }
    else if(id >= PDUR_GET_NUM_J1939TPTXPDU())
    {
        /*SWS_PduR_00221*/
        PDUR_DET_REPORT_ERROR(PDUR_J1939TP_COPYTXDATA_APIID, PDUR_E_PDU_ID_INVALID);
    }
    else if(NULL_PTR == info)
    {
        PDUR_DET_REPORT_ERROR(PDUR_J1939TP_COPYTXDATA_APIID, PDUR_E_PARAM_POINTER);
    }
    else if(NULL_PTR == availableDataPtr)
    {
        PDUR_DET_REPORT_ERROR(PDUR_J1939TP_COPYTXDATA_APIID, PDUR_E_PARAM_POINTER);
    }
    else
    {
#if(PDUR_MAX_NUMOFJ1939TPTXPDU > 0)
        SchM_Enter_PduR_PDUR_EXCLUSIVE_AREA_0();
        PathId = PDUR_J1939TP_TXCONFPDUINFO(id).PathId;
        GroupId = PDUR_ROUTINGPATHINFO(PathId).PduRDestPdu.PduRRoutingGroup;
        if((PDUR_RPGROUP_NONE == GroupId) || (TRUE == PduR_RoutingPathGroupEnabled[GroupId]))
        {
            result = PduR_LowerTpCopyTxData(PathId, PDUR_J1939TP_TXCONFPDUINFO(id).UpperPduId, info, retry, availableDataPtr);
        }
        SchM_Exit_PduR_PDUR_EXCLUSIVE_AREA_0();
#endif
    }
    return result;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: PduR_J1939TpTxConfirmation    SWS_PduR_00381
*
* Description:     This function is called after the I-PDU has been transmitted on
*                 its network, the result indicates whether the transmission was
*                 successful or not
*
* Inputs:         id - Identification of the transmitted I-PDU.
*                 result - Result of the transmission of the I-PDU.
*
* Outputs:         None
*
* Limitations:     None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, PDUR_CODE) PduR_J1939TpTxConfirmation
(
    PduIdType id,
    Std_ReturnType result
)
{
    PduR_RoutingPathIdType PathId;
    PduR_RoutingPathGroupIdType GroupId;

    if(!PDUR_IS_INITIALIZED())
    {
        /*SWS_PduR_00328 SWS_PduR_00330 SWS_PduR_00119*/
        PDUR_DET_REPORT_ERROR(PDUR_J1939TP_TXCONFIRMATION_APIID, PDUR_E_INVALID_REQUEST);
    }
    else if(id >= PDUR_GET_NUM_J1939TPTXPDU())
    {
        /*SWS_PduR_00221*/
        PDUR_DET_REPORT_ERROR(PDUR_J1939TP_TXCONFIRMATION_APIID, PDUR_E_PDU_ID_INVALID);
    }
    else
    {
#if(PDUR_MAX_NUMOFJ1939TPTXPDU > 0)
        SchM_Enter_PduR_PDUR_EXCLUSIVE_AREA_0();
        PathId = PDUR_J1939TP_TXCONFPDUINFO(id).PathId;
        GroupId = PDUR_ROUTINGPATHINFO(PathId).PduRDestPdu.PduRRoutingGroup;
        if((PDUR_RPGROUP_NONE == GroupId) || (TRUE == PduR_RoutingPathGroupEnabled[GroupId]))
        {
            PduR_LowerTpTxConfirmation(PathId, PDUR_J1939TP_TXCONFPDUINFO(id).UpperPduId, result);
        }
        SchM_Exit_PduR_PDUR_EXCLUSIVE_AREA_0();
#endif
    }
}

#endif

#if(STD_ON == PDUR_CANNM_MODULE_SUPPORT)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: PduR_CanNmRxIndication SWS_PduR_00362
*
* Description:     Indication of a received I-PDU from a lower layer communication module.
*
* Inputs:         RxPduId   Identification of the transmitted I-PDU.
*                 PduInfoPtr Contains the length (SduLength) of the received I-PDU
*                            and a pointer to a buffer (SduDataPtr) containing the I-PDU.
*
* Outputs:         None
*
* Limitations:     None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, PDUR_CODE) PduR_CanNmRxIndication
(
    PduIdType RxPduId,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_CONST) PduInfoPtr
)
{
#if(PDUR_MAX_NUMOFCANNMRXPDU > 0)
    P2CONST(PduRRoutingPduInfoType, AUTOMATIC, PDUR_CONST) pRxPduInfo;
#endif

    if(!PDUR_IS_INITIALIZED())
    {
        /*SWS_PduR_00328 SWS_PduR_00330 SWS_PduR_00119*/
        PDUR_DET_REPORT_ERROR(PDUR_CANNM_RXINDICATION_APIID, PDUR_E_INVALID_REQUEST);
    }
    else if(RxPduId >= PDUR_GET_NUM_CANNMRXPDU())
    {
        /*SWS_PduR_00221*/
        PDUR_DET_REPORT_ERROR(PDUR_CANNM_RXINDICATION_APIID, PDUR_E_PDU_ID_INVALID);
    }
    else if(NULL_PTR == PduInfoPtr)
    {
        PDUR_DET_REPORT_ERROR(PDUR_CANNM_RXINDICATION_APIID, PDUR_E_PARAM_POINTER);
    }
    else
    {
#if(PDUR_MAX_NUMOFCANNMRXPDU > 0)
        SchM_Enter_PduR_PDUR_EXCLUSIVE_AREA_0();
        pRxPduInfo = &(PDUR_CANNM_RXPDUINFO(RxPduId));
        PduR_LowerIfMultiRxIndication(pRxPduInfo, PduInfoPtr);
        SchM_Exit_PduR_PDUR_EXCLUSIVE_AREA_0();
#endif
    }
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: PduR_CanNmTxConfirmation    SWS_PduR_00365
*
* Description:     The lower layer communication module confirms the transmission
*                of an I-PDU.
*
* Inputs:         TxPduId   ID of the I-PDU that has been transmitted.
*
* Outputs:         bufferSizePtr    Available receive buffer after data has been copied.
*
* Limitations:     None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, PDUR_CODE) PduR_CanNmTxConfirmation
(
    PduIdType TxPduId
)
{
    PduR_RoutingPathIdType PathId;
    PduR_RoutingPathGroupIdType GroupId;

    if(!PDUR_IS_INITIALIZED())
    {
        /*SWS_PduR_00328 SWS_PduR_00330 SWS_PduR_00119*/
        PDUR_DET_REPORT_ERROR(PDUR_CANNM_TXCONFIRMATION_APIID, PDUR_E_INVALID_REQUEST);
    }
    else if(TxPduId >= PDUR_GET_NUM_CANNMTXPDU())
    {
        /*SWS_PduR_00221*/
        PDUR_DET_REPORT_ERROR(PDUR_CANNM_TXCONFIRMATION_APIID, PDUR_E_PDU_ID_INVALID);
    }
    else
    {
#if(PDUR_MAX_NUMOFCANNMTXPDU > 0)
        SchM_Enter_PduR_PDUR_EXCLUSIVE_AREA_0();
        PathId = PDUR_CANNM_TXCONFPDUINFO(TxPduId).PathId;
        GroupId = PDUR_ROUTINGPATHINFO(PathId).PduRDestPdu.PduRRoutingGroup;
        if((PDUR_RPGROUP_NONE == GroupId) || (TRUE == PduR_RoutingPathGroupEnabled[GroupId]))
        {
            PduR_LowerIfTxConfirmation(PathId, PDUR_CANNM_TXCONFPDUINFO(TxPduId).UpperPduId);
        }
        SchM_Exit_PduR_PDUR_EXCLUSIVE_AREA_0();
#endif
    }
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: PduR_CanNmTriggerTransmit    SWS_PduR_00369
*
* Description:     The lower layer communication module requests the buffer of the
*                SDU for transmission from the upper layer module.
*
* Inputs:         TxPduId   ID of the SDU that is requested to be transmitted.
*                PduInfoPtr Contains a pointer to a buffer (SduDataPtr) to where
*                           the SDU shall be copied to. On return, the service will
*                           indicate the length of the copied SDU data in SduLength
*
* Outputs:         None
*
* Limitations:     None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, PDUR_CODE) PduR_CanNmTriggerTransmit
(
    PduIdType TxPduId,
    P2VAR(PduInfoType, AUTOMATIC, PDUR_CONST) PduInfoPtr
)
{
    Std_ReturnType ret = E_NOT_OK;
#if(PDUR_MAX_NUMOFCANNMTXPDU > 0)
    PduR_RoutingPathIdType PathId;
    PduR_RoutingPathGroupIdType GroupId;
#endif

    if(!PDUR_IS_INITIALIZED())
    {
        /*SWS_PduR_00328 SWS_PduR_00330 SWS_PduR_00119*/
        PDUR_DET_REPORT_ERROR(PDUR_CANNM_TRIGGERTRANSMIT_APIID, PDUR_E_INVALID_REQUEST);
    }
    else if(TxPduId >= PDUR_GET_NUM_CANNMTXPDU())
    {
        /*SWS_PduR_00221*/
        PDUR_DET_REPORT_ERROR(PDUR_CANNM_TRIGGERTRANSMIT_APIID, PDUR_E_PDU_ID_INVALID);
    }
    else if(NULL_PTR == PduInfoPtr)
    {
        PDUR_DET_REPORT_ERROR(PDUR_CANNM_TRIGGERTRANSMIT_APIID, PDUR_E_PARAM_POINTER);
    }
    else
    {
#if(PDUR_MAX_NUMOFCANNMTXPDU > 0)
        SchM_Enter_PduR_PDUR_EXCLUSIVE_AREA_0();
        PathId = PDUR_CANNM_TXCONFPDUINFO(TxPduId).PathId;
        GroupId = PDUR_ROUTINGPATHINFO(PathId).PduRDestPdu.PduRRoutingGroup;
        if((PDUR_RPGROUP_NONE == GroupId) || (TRUE == PduR_RoutingPathGroupEnabled[GroupId]))
        {
            ret = PduR_LowerIfTriggerTransmit(PathId, PDUR_CANNM_TXCONFPDUINFO(TxPduId).UpperPduId, PduInfoPtr);
        }
        SchM_Exit_PduR_PDUR_EXCLUSIVE_AREA_0();
#endif
    }

    return ret;
}
#endif

#if(STD_ON == PDUR_UDPNM_MODULE_SUPPORT)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: PduR_UdpNmRxIndication SWS_PduR_00362
*
* Description:     Indication of a received I-PDU from a lower layer communication module.
*
* Inputs:         RxPduId   Identification of the transmitted I-PDU.
*                 PduInfoPtr Contains the length (SduLength) of the received I-PDU
*                            and a pointer to a buffer (SduDataPtr) containing the I-PDU.
*
* Outputs:         None
*
* Limitations:     None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, PDUR_CODE) PduR_UdpNmRxIndication
(
    PduIdType RxPduId,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_CONST) PduInfoPtr
)
{
#if(PDUR_MAX_NUMOFUDPNMRXPDU > 0)
    P2CONST(PduRRoutingPduInfoType, AUTOMATIC, PDUR_CONST) pRxPduInfo;
#endif

    if(!PDUR_IS_INITIALIZED())
    {
        /*SWS_PduR_00328 SWS_PduR_00330 SWS_PduR_00119*/
        PDUR_DET_REPORT_ERROR(PDUR_UDPNM_RXINDICATION_APIID, PDUR_E_INVALID_REQUEST);
    }
    else if(RxPduId >= PDUR_GET_NUM_UDPNMRXPDU())
    {
        /*SWS_PduR_00221*/
        PDUR_DET_REPORT_ERROR(PDUR_UDPNM_RXINDICATION_APIID, PDUR_E_PDU_ID_INVALID);
    }
    else if(NULL_PTR == PduInfoPtr)
    {
        PDUR_DET_REPORT_ERROR(PDUR_UDPNM_RXINDICATION_APIID, PDUR_E_PARAM_POINTER);
    }
    else
    {
#if(PDUR_MAX_NUMOFUDPNMRXPDU > 0)
        SchM_Enter_PduR_PDUR_EXCLUSIVE_AREA_0();
        pRxPduInfo = &(PDUR_UDPNM_RXPDUINFO(RxPduId));
        PduR_LowerIfMultiRxIndication(pRxPduInfo, PduInfoPtr);
        SchM_Exit_PduR_PDUR_EXCLUSIVE_AREA_0();
#endif
    }
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: PduR_UdpNmTxConfirmation    SWS_PduR_00365
*
* Description:     The lower layer communication module confirms the transmission
*                of an I-PDU.
*
* Inputs:         TxPduId   ID of the I-PDU that has been transmitted.
*
* Outputs:         bufferSizePtr    Available receive buffer after data has been copied.
*
* Limitations:     None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, PDUR_CODE) PduR_UdpNmTxConfirmation
(
    PduIdType TxPduId
)
{
    PduR_RoutingPathIdType PathId;
    PduR_RoutingPathGroupIdType GroupId;

    if(!PDUR_IS_INITIALIZED())
    {
        /*SWS_PduR_00328 SWS_PduR_00330 SWS_PduR_00119*/
        PDUR_DET_REPORT_ERROR(PDUR_UDPNM_TXCONFIRMATION_APIID, PDUR_E_INVALID_REQUEST);
    }
    else if(TxPduId >= PDUR_GET_NUM_UDPNMTXPDU())
    {
        /*SWS_PduR_00221*/
        PDUR_DET_REPORT_ERROR(PDUR_UDPNM_TXCONFIRMATION_APIID, PDUR_E_PDU_ID_INVALID);
    }
    else
    {
#if(PDUR_MAX_NUMOFUDPNMTXPDU > 0)
        SchM_Enter_PduR_PDUR_EXCLUSIVE_AREA_0();
        PathId = PDUR_UDPNM_TXCONFPDUINFO(TxPduId).PathId;
        GroupId = PDUR_ROUTINGPATHINFO(PathId).PduRDestPdu.PduRRoutingGroup;
        if((PDUR_RPGROUP_NONE == GroupId) || (TRUE == PduR_RoutingPathGroupEnabled[GroupId]))
        {
            PduR_LowerIfTxConfirmation(PathId, PDUR_UDPNM_TXCONFPDUINFO(TxPduId).UpperPduId);
        }
        SchM_Exit_PduR_PDUR_EXCLUSIVE_AREA_0();
#endif
    }
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: PduR_UdpNmTriggerTransmit    SWS_PduR_00369
*
* Description:     The lower layer communication module requests the buffer of the
*                SDU for transmission from the upper layer module.
*
* Inputs:         TxPduId   ID of the SDU that is requested to be transmitted.
*                PduInfoPtr Contains a pointer to a buffer (SduDataPtr) to where
*                           the SDU shall be copied to. On return, the service will
*                           indicate the length of the copied SDU data in SduLength
*
* Outputs:         None
*
* Limitations:     None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, PDUR_CODE) PduR_UdpNmTriggerTransmit
(
    PduIdType TxPduId,
    P2VAR(PduInfoType, AUTOMATIC, PDUR_CONST) PduInfoPtr
)
{
    Std_ReturnType ret = E_NOT_OK;
#if(PDUR_MAX_NUMOFUDPNMTXPDU > 0)
    PduR_RoutingPathIdType PathId;
    PduR_RoutingPathGroupIdType GroupId;
#endif

    if(!PDUR_IS_INITIALIZED())
    {
        /*SWS_PduR_00328 SWS_PduR_00330 SWS_PduR_00119*/
        PDUR_DET_REPORT_ERROR(PDUR_UDPNM_TRIGGERTRANSMIT_APIID, PDUR_E_INVALID_REQUEST);
    }
    else if(TxPduId >= PDUR_GET_NUM_UDPNMTXPDU())
    {
        /*SWS_PduR_00221*/
        PDUR_DET_REPORT_ERROR(PDUR_UDPNM_TRIGGERTRANSMIT_APIID, PDUR_E_PDU_ID_INVALID);
    }
    else if(NULL_PTR == PduInfoPtr)
    {
        PDUR_DET_REPORT_ERROR(PDUR_UDPNM_TRIGGERTRANSMIT_APIID, PDUR_E_PARAM_POINTER);
    }
    else
    {
#if(PDUR_MAX_NUMOFUDPNMTXPDU > 0)
        SchM_Enter_PduR_PDUR_EXCLUSIVE_AREA_0();
        PathId = PDUR_UDPNM_TXCONFPDUINFO(TxPduId).PathId;
        GroupId = PDUR_ROUTINGPATHINFO(PathId).PduRDestPdu.PduRRoutingGroup;
        if((PDUR_RPGROUP_NONE == GroupId) || (TRUE == PduR_RoutingPathGroupEnabled[GroupId]))
        {
            ret = PduR_LowerIfTriggerTransmit(PathId, PDUR_UDPNM_TXCONFPDUINFO(TxPduId).UpperPduId, PduInfoPtr);
        }
        SchM_Exit_PduR_PDUR_EXCLUSIVE_AREA_0();
#endif
    }

    return ret;
}
#endif


#if(STD_ON == PDUR_SECOC_MODULE_SUPPORT)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: PduR_IpduMTransmit
*
* Description:     Requests transmission of an I-PDU.
*
* Inputs:         id   Identification of the I-PDU.
*                info Length and pointer to the buffer of the I-PDU
*
* Outputs:         None
*
* Limitations:     None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, PDUR_CODE) PduR_SecOCTransmit
(
    PduIdType id,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_CONST) info
)
{
    PduR_RoutingPathIdType i;
    Std_ReturnType ret = E_NOT_OK;
    boolean Flag = FALSE;
    PduR_MulticastMaskType mask;
    PduR_RoutingPathIdType PathId;

    if(!PDUR_IS_INITIALIZED())
    {
        /*SWS_PduR_00328 SWS_PduR_00330 SWS_PduR_00119*/
        PDUR_DET_REPORT_ERROR(PDUR_SECOC_TRANSMIT_APIID, PDUR_E_INVALID_REQUEST);
    }
    else if(id >= PDUR_GET_NUM_SECOCTXPDU())
    {
        /*SWS_PduR_00221*/
        PDUR_DET_REPORT_ERROR(PDUR_SECOC_TRANSMIT_APIID, PDUR_E_PDU_ID_INVALID);
    }
    else if(NULL_PTR == info)
    {
        PDUR_DET_REPORT_ERROR(PDUR_SECOC_TRANSMIT_APIID, PDUR_E_PARAM_POINTER);
    }
    else
    {
#if(PDUR_MAX_NUMOFSECOCTXPDU > 0)
        SchM_Enter_PduR_PDUR_EXCLUSIVE_AREA_0();

        SecOCTxErrorMask[id] = (PduR_MulticastMaskType)0;
        SecOCTxConfMask[id] = (PduR_MulticastMaskType)0;
        for(i = (PduR_RoutingPathIdType)0; i < PDUR_SECOC_TXPDUINFO(id).NumPaths; i++)
        {
            PathId = PDUR_SECOC_TXPDUINFO(id).PathIdx[i];
            ret = PduR_UpTransmit(PathId, info);
            if(ret == E_OK)
            {
                Flag = TRUE;
            }
            else
            {
                /*Set mask as if the wrong path has finished*/
                mask = PDUR_ROUTINGPATHINFO(PathId).ConfMask;
                SecOCTxErrorMask[id] |= mask;
                SecOCTxConfMask[id] |= mask;
            }
        }

        SchM_Exit_PduR_PDUR_EXCLUSIVE_AREA_0();
#endif
    }

    /*SWS_PduR_00218*/
    if(TRUE == Flag)
    {
        ret = E_OK;
    }
    else
    {
        ret = E_NOT_OK;
    }
    return ret;
}

#if(STD_ON == PDUR_SECOCTP_MODULE_SUPPORT)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: PduR_J1939TpStartOfReception    SWS_PduR_00507
*
* Description:     This function is called by the transport protocol module to query
*                the transmit data of an I-PDU segment.
*
* Inputs:         id   Identification of the transmitted I-PDU.
*                 TpSduLength  Total length of the PDU to be received.
*
* Outputs:         bufferSizePtr  Available receive buffer in the receiving module.
*                               This parameter will be used to compute the Block
*                               Size (BS) in the transport protocol module
*
* Limitations:     None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(BufReq_ReturnType, PDUR_CODE) PduR_SecOCStartOfReception
(
    PduIdType id,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info,
    PduLengthType TpSduLength,
    P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) bufferSizePtr
)
{
    BufReq_ReturnType result = BUFREQ_E_NOT_OK;
    P2CONST(PduRRoutingPduInfoType, AUTOMATIC, PDUR_CONST) pRxPduInfo;

    if(!PDUR_IS_INITIALIZED())
    {
        /*SWS_PduR_00328 SWS_PduR_00330 SWS_PduR_00119*/
        PDUR_DET_REPORT_ERROR(PDUR_SECOCTP_STARTOFRECEPTION_APIID, PDUR_E_INVALID_REQUEST);
    }
    else if(id >= PDUR_GET_NUM_SECOCTPRXPDU())
    {
        /*SWS_PduR_00221*/
        PDUR_DET_REPORT_ERROR(PDUR_SECOCTP_STARTOFRECEPTION_APIID, PDUR_E_PDU_ID_INVALID);
    }
    else if(NULL_PTR == bufferSizePtr)
    {
        PDUR_DET_REPORT_ERROR(PDUR_SECOCTP_STARTOFRECEPTION_APIID, PDUR_E_PARAM_POINTER);
    }
    else
    {
#if(PDUR_MAX_NUMOFSECOCTPRXPDU > 0)
        SchM_Enter_PduR_PDUR_EXCLUSIVE_AREA_0();
        pRxPduInfo = &(PDUR_SECOCTP_RXPDUINFO(id));
        result = PduR_LowerTpMultiStartOfReception(pRxPduInfo, info, TpSduLength, bufferSizePtr);
        SchM_Exit_PduR_PDUR_EXCLUSIVE_AREA_0();
#endif
    }

    return result;
}
#endif
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: PduR_ComCancelTransmit     SWS_PduR_00769
*
* Description:     Request for cancellation of an ongoing transmission of an I-Pdu
*                in transport protocol or communication interface.
*
* Inputs:         id   Identification of the I-PDU to be cancelled.
*
*
* Outputs:         None
*
* Limitations:     None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, PDUR_CODE) PduR_SecOCCancelTransmit
(
    PduIdType id
)
{
    Std_ReturnType ret = E_NOT_OK;
    PduR_RoutingPathIdType i;
    boolean ErrorFlag = FALSE;

    if(!PDUR_IS_INITIALIZED())
    {
        /*SWS_PduR_00328 SWS_PduR_00330 SWS_PduR_00119*/
        PDUR_DET_REPORT_ERROR(PDUR_SECOC_CANCELTRANSMIT_APIID, PDUR_E_INVALID_REQUEST);
    }
    else if(id >= PDUR_GET_NUM_SECOCTXPDU())
    {
        /*SWS_PduR_00221*/
        PDUR_DET_REPORT_ERROR(PDUR_SECOC_CANCELTRANSMIT_APIID, PDUR_E_PDU_ID_INVALID);
    }
    else
    {
#if(PDUR_MAX_NUMOFSECOCTXPDU > 0)
        SchM_Enter_PduR_PDUR_EXCLUSIVE_AREA_0();
        for(i = 0; i < PDUR_SECOC_TXPDUINFO(id).NumPaths; i++)
        {
            ret = PduR_UpCancelTransmit(PDUR_SECOC_TXPDUINFO(id).PathIdx[i]);
            if(ret != E_OK)
            {
                ErrorFlag = TRUE;
            }

        }
        SchM_Exit_PduR_PDUR_EXCLUSIVE_AREA_0();
#endif
    }

    /*SWS_PduR_00701*/
    if(ErrorFlag)
    {
        ret = E_NOT_OK;
    }
    else
    {
        ret = E_OK;
    }
    return ret;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: PduR_DcmCancelReceive   SWS_PduR_00767
*
* Description:     Requests for cancellation of an ongoing reception of an I-Pdu
*                in transport protocol
*
* Inputs:         id   Identification of the I-PDU.
*
*
* Outputs:         None
*
* Limitations:     None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, PDUR_CODE) PduR_SecOCCancelReceive
(
    PduIdType id
)
{
    Std_ReturnType ret = E_NOT_OK;

    if(!PDUR_IS_INITIALIZED())
    {
        /*SWS_PduR_00328 SWS_PduR_00330 SWS_PduR_00119*/
        PDUR_DET_REPORT_ERROR(PDUR_SECOC_CANCELRECEIVE_APIID, PDUR_E_INVALID_REQUEST);
    }
    else if(id >= PDUR_GET_NUM_SECOCRXPDU())
    {
        /*SWS_PduR_00221*/
        PDUR_DET_REPORT_ERROR(PDUR_SECOC_CANCELRECEIVE_APIID, PDUR_E_PDU_ID_INVALID);
    }
    else
    {
        SchM_Enter_PduR_PDUR_EXCLUSIVE_AREA_0();
        /*SWS_PduR_00736*/
        ret = PduR_UpCancelReceive(PDUR_SECOC_CANCELRXPDUINFO(id).PathId);
        SchM_Exit_PduR_PDUR_EXCLUSIVE_AREA_0();
    }
    return ret;
}
#endif

#if(STD_ON == PDUR_SECOCTP_MODULE_SUPPORT)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: PduR_J1939TpCopyTxData    SWS_PduR_00518
*
* Description:     This function is called by the transport protocol module to query
*                the transmit data of an I-PDU segment.
*
* Inputs:         id   Identification of the transmitted I-PDU.
*                 info Provides destination buffer and the number of bytes to copy.
*                     In case of gateway the PDU Router module will copy, otherwise
*                     the source upper layer module will copy the data. If not enough
*                     transmit data is available, no data is copied. The transport
*                     protocol module will retry. A copy size of 0 can be used to
*                     indicate state changes in the retry parameter.
*                retry This parameter is used to retransmit data because problems
*                      during the last service call.
*
*
* Outputs:         availableDataPtr  Indicates the remaining number of bytes that are
*                                  available in the PduR Tx buffer. AvailableTxDataCntPtr
*                                  can be used by TP modules that support dynamic payload
*                                  lengths (e.g. Iso FrTp) to determine the size of the
*                                  following CFs.
*
* Limitations:     None
********************************************************************************
END_FUNCTION_HDR*/

FUNC(BufReq_ReturnType, PDUR_CODE) PduR_SecOCTpCopyTxData
(
    PduIdType id,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info,
    P2VAR(RetryInfoType, AUTOMATIC, PDUR_APPL_DATA) retry,
    P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) availableDataPtr
)
{
    BufReq_ReturnType result = BUFREQ_E_NOT_OK;
    PduR_RoutingPathIdType PathId;
    PduR_RoutingPathGroupIdType GroupId;

    if(!PDUR_IS_INITIALIZED())
    {
        /*SWS_PduR_00328 SWS_PduR_00330 SWS_PduR_00119*/
        PDUR_DET_REPORT_ERROR(PDUR_SECOCTP_COPYTXDATA_APIID, PDUR_E_INVALID_REQUEST);
    }
    else if(id >= PDUR_GET_NUM_SECOCTPTXPDU())
    {
        /*SWS_PduR_00221*/
        PDUR_DET_REPORT_ERROR(PDUR_SECOCTP_COPYTXDATA_APIID, PDUR_E_PDU_ID_INVALID);
    }
    else if(NULL_PTR == info)
    {
        PDUR_DET_REPORT_ERROR(PDUR_SECOCTP_COPYTXDATA_APIID, PDUR_E_PARAM_POINTER);
    }
    else if(NULL_PTR == availableDataPtr)
    {
        PDUR_DET_REPORT_ERROR(PDUR_SECOCTP_COPYTXDATA_APIID, PDUR_E_PARAM_POINTER);
    }
    else
    {
#if(PDUR_MAX_NUMOFSECOCTPTXPDU > 0)
        SchM_Enter_PduR_PDUR_EXCLUSIVE_AREA_0();
        PathId = PDUR_SECOCTP_TXCONFPDUINFO(id).PathId;
        GroupId = PDUR_ROUTINGPATHINFO(PathId).PduRDestPdu.PduRRoutingGroup;
        if((PDUR_RPGROUP_NONE == GroupId) || (TRUE == PduR_RoutingPathGroupEnabled[GroupId]))
        {
            result = PduR_LowerTpCopyTxData(PathId, PDUR_SECOCTP_TXCONFPDUINFO(id).UpperPduId, info, retry, availableDataPtr);//PDUR_SECOCTP_TXCONFPDUINFO
        }
        SchM_Exit_PduR_PDUR_EXCLUSIVE_AREA_0();
#endif
    }
    return result;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: PduR_SecOCTpTxConfirmation    SWS_PduR_00381
*
* Description:     This function is called after the I-PDU has been transmitted on
*                 its network, the result indicates whether the transmission was
*                 successful or not
*
* Inputs:         id - Identification of the transmitted I-PDU.
*                 result - Result of the transmission of the I-PDU.
*
* Outputs:         None
*
* Limitations:     None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, PDUR_CODE) PduR_SecOCTpTxConfirmation
(
    PduIdType id,
    Std_ReturnType result
)
{
    PduR_RoutingPathIdType PathId;
    PduR_RoutingPathGroupIdType GroupId;

    if(!PDUR_IS_INITIALIZED())
    {
        /*SWS_PduR_00328 SWS_PduR_00330 SWS_PduR_00119*/
        PDUR_DET_REPORT_ERROR(PDUR_SECOCTP_TXCONFIRMATION_APIID, PDUR_E_INVALID_REQUEST);
    }
    else if(id >= PDUR_GET_NUM_SECOCTPTXPDU()) 
    {
        /*SWS_PduR_00221*/
        PDUR_DET_REPORT_ERROR(PDUR_SECOCTP_TXCONFIRMATION_APIID, PDUR_E_PDU_ID_INVALID);
    }
    else
    {
#if(PDUR_MAX_NUMOFSECOCTPTXPDU > 0)
        SchM_Enter_PduR_PDUR_EXCLUSIVE_AREA_0();
        PathId = PDUR_SECOCTP_TXCONFPDUINFO(id).PathId;
        GroupId = PDUR_ROUTINGPATHINFO(PathId).PduRDestPdu.PduRRoutingGroup;
        if((PDUR_RPGROUP_NONE == GroupId) || (TRUE == PduR_RoutingPathGroupEnabled[GroupId]))
        {
            PduR_LowerTpTxConfirmation(PathId, PDUR_SECOCTP_TXCONFPDUINFO(id).UpperPduId, result);//PDUR_SECOCTP_TXCONFPDUINFO
        }
        SchM_Exit_PduR_PDUR_EXCLUSIVE_AREA_0();
#endif
    }
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: PduR_J1939TpCopyRxData    SWS_PduR_00512
*
* Description:     This function is called by the transport protocol module to query
*                the transmit data of an I-PDU segment.
*
* Inputs:         id   Identification of the transmitted I-PDU.
*                 info Pointer to the buffer (SduDataPtr) and its length (SduLength)
*                     containing the data to be copied by PDU Router module in case
*                     of gateway or upper layer module in case of reception
*
* Outputs:         bufferSizePtr  Available receive buffer after data has been copied.
*
* Limitations:     None
********************************************************************************
END_FUNCTION_HDR*/
BufReq_ReturnType PduR_SecOCTpCopyRxData
(
    PduIdType id,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info,
    P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) bufferSizePtr
)
{
    BufReq_ReturnType result = BUFREQ_E_NOT_OK;
    P2CONST(PduRRoutingPduInfoType, AUTOMATIC, PDUR_CONST) pRxPduInfo;

    if(!PDUR_IS_INITIALIZED())
    {
        /*SWS_PduR_00328 SWS_PduR_00330 SWS_PduR_00119*/
        PDUR_DET_REPORT_ERROR(PDUR_SECOCTP_COPYRXDATA_APIID, PDUR_E_INVALID_REQUEST);
    }
    else if(id >= PDUR_GET_NUM_SECOCTPRXPDU())
    {
        /*SWS_PduR_00221*/
        PDUR_DET_REPORT_ERROR(PDUR_SECOCTP_COPYRXDATA_APIID, PDUR_E_PDU_ID_INVALID);
    }
    else if(NULL_PTR == info)
    {
        PDUR_DET_REPORT_ERROR(PDUR_SECOCTP_COPYRXDATA_APIID, PDUR_E_PARAM_POINTER);
    }
    else if(NULL_PTR == bufferSizePtr)
    {
        PDUR_DET_REPORT_ERROR(PDUR_SECOCTP_COPYRXDATA_APIID, PDUR_E_PARAM_POINTER);
    }
    else
    {
#if(PDUR_MAX_NUMOFSECOCTPRXPDU > 0)
        SchM_Enter_PduR_PDUR_EXCLUSIVE_AREA_0();
        pRxPduInfo = &(PDUR_SECOCTP_RXPDUINFO(id));
        result = PduR_LowerTpMultiCopyRxData(pRxPduInfo, info, bufferSizePtr);
        SchM_Exit_PduR_PDUR_EXCLUSIVE_AREA_0();
#endif
    }

    return result;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: PduR_J1939TpRxIndication    SWS_PduR_00375
*
* Description:     This function is called by the transport protocol module to query
*                the transmit data of an I-PDU segment.
*
* Inputs:         id   Identification of the transmitted I-PDU.
*                 result Result of the reception.
*
* Outputs:         bufferSizePtr  Available receive buffer after data has been copied.
*
* Limitations:     None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, PDUR_CODE) PduR_SecOCTpRxIndication
(
    PduIdType id,
    NotifResultType result
)
{
    P2CONST(PduRRoutingPduInfoType, AUTOMATIC, PDUR_CONST) pRxPduInfo;

    if(!PDUR_IS_INITIALIZED())
    {
        /*SWS_PduR_00328 SWS_PduR_00330 SWS_PduR_00119*/
        PDUR_DET_REPORT_ERROR(PDUR_SECOCTP_RXINDICATION_APIID, PDUR_E_INVALID_REQUEST);
    }
    else if(id >= PDUR_GET_NUM_SECOCTPRXPDU())
    {
        /*SWS_PduR_00221*/
        PDUR_DET_REPORT_ERROR(PDUR_SECOCTP_RXINDICATION_APIID, PDUR_E_PDU_ID_INVALID);
    }
    else
    {
#if(PDUR_MAX_NUMOFSECOCTPRXPDU > 0)
        SchM_Enter_PduR_PDUR_EXCLUSIVE_AREA_0();
        pRxPduInfo = &(PDUR_SECOCTP_RXPDUINFO(id));
        PduR_LowerTpMultiRxIndication(pRxPduInfo, result);
        SchM_Exit_PduR_PDUR_EXCLUSIVE_AREA_0();
#endif
    }
}

#endif

#if(STD_ON == PDUR_SECOCIF_MODULE_SUPPORT)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: PduR_IpduMTxConfirmation    SWS_PduR_00365
*
* Description:     The lower layer communication module confirms the transmission
*                of an I-PDU.
*
* Inputs:         TxPduId   ID of the I-PDU that has been transmitted.
*
* Outputs:         None
*
* Limitations:     None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, PDUR_CODE) PduR_SecOCIfTxConfirmation
(
    PduIdType TxPduId
)
{
    PduR_RoutingPathIdType PathId;
    PduR_RoutingPathGroupIdType GroupId;

    if(!PDUR_IS_INITIALIZED())
    {
        /*SWS_PduR_00328 SWS_PduR_00330 SWS_PduR_00119*/
        PDUR_DET_REPORT_ERROR(PDUR_SECOCIF_TXCONFIRMATION_APIID, PDUR_E_INVALID_REQUEST);
    }
    else if(TxPduId >= PDUR_GET_NUM_SECOCIFTXPDU())
    {
        /*SWS_PduR_00221*/
        PDUR_DET_REPORT_ERROR(PDUR_SECOCIF_TXCONFIRMATION_APIID, PDUR_E_PDU_ID_INVALID);
    }
    else
    {
#if( PDUR_MAX_NUMOFSECOCIFTXPDU > 0)
        SchM_Enter_PduR_PDUR_EXCLUSIVE_AREA_0();
        PathId = PDUR_SECOCIF_TXCONFPDUINFO(TxPduId).PathId;
        GroupId = PDUR_ROUTINGPATHINFO(PathId).PduRDestPdu.PduRRoutingGroup;
        if((PDUR_RPGROUP_NONE == GroupId) || (TRUE == PduR_RoutingPathGroupEnabled[GroupId]))
        {
            PduR_LowerIfTxConfirmation(PathId, PDUR_SECOCIF_TXCONFPDUINFO(TxPduId).UpperPduId);
        }
        SchM_Exit_PduR_PDUR_EXCLUSIVE_AREA_0();
#endif
    }
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: PduR_CanIfRxIndication SWS_PduR_00362
*
* Description:     Indication of a received I-PDU from a lower layer communication module.
*
* Inputs:         RxPduId   Identification of the transmitted I-PDU.
*                 PduInfoPtr Contains the length (SduLength) of the received I-PDU
*                           and a pointer to a buffer (SduDataPtr) containing the I-PDU.
*
* Outputs:         None
*
* Limitations:     None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, PDUR_CODE) PduR_SecOCIfRxIndication
(
    PduIdType RxPduId,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_CONST) PduInfoPtr
)
{
    P2CONST(PduRRoutingPduInfoType, AUTOMATIC, PDUR_CONST) pRxPduInfo;

    if(!PDUR_IS_INITIALIZED())
    {
        /*SWS_PduR_00328 SWS_PduR_00330 SWS_PduR_00119*/
        PDUR_DET_REPORT_ERROR(PDUR_SECOCIF_RXINDICATION_APIID, PDUR_E_INVALID_REQUEST);
    }
    else if(RxPduId >= PDUR_GET_NUM_SECOCIFRXPDU())
    {
        /*SWS_PduR_00221*/
        PDUR_DET_REPORT_ERROR(PDUR_SECOCIF_RXINDICATION_APIID, PDUR_E_PDU_ID_INVALID);
    }
    else if(NULL_PTR == PduInfoPtr)
    {
        PDUR_DET_REPORT_ERROR(PDUR_SECOCIF_RXINDICATION_APIID, PDUR_E_PARAM_POINTER);
    }
    else
    {
#if(PDUR_MAX_NUMOFSECOCIFRXPDU > 0)
        SchM_Enter_PduR_PDUR_EXCLUSIVE_AREA_0();
        pRxPduInfo = &(PDUR_SECOCIF_RXPDUINFO(RxPduId));
        PduR_LowerIfMultiRxIndication(pRxPduInfo, PduInfoPtr);
        SchM_Exit_PduR_PDUR_EXCLUSIVE_AREA_0();
#endif
    }
}
#endif

#define PDUR_STOP_SEC_CODE
#include "MemMap.h"

#endif/*#if(STD_ON == PDUR_ZERO_COST_OPERATION)*/

