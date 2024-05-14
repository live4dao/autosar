/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
*   File Name:       Com.c
********************************************************************************
*   Project/Product : AUTOSAR 4.2
*   Title:          : Com module Source File
*   Author:         : Hirain
********************************************************************************
*   Description:      Implementation of Com provided functionality
*
********************************************************************************
*   Limitations:      None
*
********************************************************************************
*
********************************************************************************
*   Revision History:
*
*   Version    Date        Initials         CR#        Descriptions
*   --------   ----------  -------------    -------    -------------------
*   01.00.00   12/05/2017  ning.chen        N/A        Original
*   01.01.00   12/04/2018  ning.chen        N/A        EAS422_COM_20180412_01
*   01.02.00   12/07/2018  ning.chen        N/A        EAS422_COM_20180712_01
*   01.02.01   12/07/2018  ning.chen        N/A        EAS422_COM_20181010_01
*   01.02.02   22/11/2018  ning.chen        N/A        EAS422_COM_20181122_01
*   01.02.03   14/02/2019  ning.chen        N/A        EAS422_COM_20190214_01
*   01.02.04   25/04/2019  beibei.xing      N/A        EAS422_COM_20190425_01
*   01.02.05   04/06/2019  ning.chen        N/A        EAS422_COM_20190604_01
*   01.02.06   06/09/2019  ning.chen        N/A        EAS422_COM_20190906_01
*   01.02.07   15/07/2020  feixiang.dong    N/A        EAS422_COM_20200715_01
*   01.02.08   11/06/2021  boxue.li         N/A        EAS422_COM_20210611_01
*   01.02.09   03/08/2021  feixiang.dong    N/A        EAS422_COM_20210803_01
*   01.02.10   22/09/2021  feixiang.dong    N/A        EAS422_COM_20210922_01
*   01.02.11   29/12/2021  feixiang.dong    N/A        EAS422_COM_20211229_01
*   01.02.12   17/07/2022  ziyi.zhao        N/A        EAS422_COM_20220717_01
*   01.02.13   02/03/2023  keyu.wu          N/A        EAS422_COM_20230203_01
*   01.03.00   28/03/2023  ning.chen        N/A        EAS422_COM_20230328_01
*   01.04.00   27/06/2023  keyu.wu          N/A        EAS422_COM_20230627_01
*   01.04.01   04/01/2024  keyu.wu          N/A        EAS422_COM_20240104_01
********************************************************************************
*END_FILE_HDR*/

/*******************************************************************************
*    Includes
*******************************************************************************/
#include "SchM_Com.h"
#include "Com.h"
#include "Com_Cbk.h"
#if(STD_ON == COM_DEV_ERROR_DETECT)
#include "Det.h"
#endif



/*******************************************************************************
*   Version Check
*******************************************************************************/
#if(STD_ON == COM_VERSION_CHECK)
/* check Version with cfg file */
#if ((COM_AR_RELEASE_MAJOR_VERSION != COM_AR_RELEASE_MAJOR_VERSION_CFG) || \
   (COM_AR_RELEASE_MINOR_VERSION != COM_AR_RELEASE_MINOR_VERSION_CFG))
#error "AutoSar Version Numbers of CanIf and its cfg file are different"
#endif

#if ((COM_SW_MAJOR_VERSION != COM_SW_MAJOR_VERSION_CFG) || \
   (COM_SW_MINOR_VERSION != COM_SW_MINOR_VERSION_CFG))
#error "SW Version Numbers of Com and its cfg file are different"
#endif
#endif

/*******************************************************************************
*   Private Data
*******************************************************************************/
#define COM_START_SEC_VAR_INIT_8
#include "MemMap.h"
STATIC VAR(Com_StatusType, COM_VAR) Com_InitStateFlag = COM_UNINIT;
#define COM_STOP_SEC_VAR_INIT_8
#include "MemMap.h"

#if(COM_CONFIG_VARIANTS == STD_CONFIG_VARIANTS_POSTBUILD)
#define COM_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"
STATIC P2CONST(Com_ConfigType, COM_VAR, COM_CONST) Com_PBConfig;
#define COM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"
#endif


/*******************************************************************************
*   Macro Tx
*******************************************************************************/
/* tx Pdu reg access  */
#define COM_TXPDU_TMS_FLAG(TxIpduId)             (Com_TxPduTable[TxIpduId].IpduTMSFlag)
#define COM_TXPDU_PERIOD(TxIpduId)               (Com_TxPduTable[TxIpduId].TxModeTimePeriod)
#define COM_TXPDU_TXTIME_OFFSET(TxIpduId)        (Com_TxPduTable[TxIpduId].TxModeTimeOffset)
#define COM_TXPDU_MIN_DELAY_TIMER(TxIpduId)      (Com_TxPduTable[TxIpduId].MininumDelayTimer)
#define COM_TXPDU_REP_NUM(TxIpduId)              (Com_TxPduTable[TxIpduId].TxModeNumOfRep)
#define COM_TXPDU_PERIOD_BACKUP(TxIpduId)        (Com_TxPduTable[TxIpduId].TimePeriodBackUp)
#define COM_TXPDU_TIMEOUT(TxIpduId)              (Com_TxPduTable[TxIpduId].TxIpduTimeOut)
#define COM_TXPDU_TXMODE_PTR(TxIpduId)           (Com_TxPduTable[TxIpduId].TxModeSelectPtr)
#define COM_TXPDU_DYN_LENGTH(TxIpduId)           (Com_TxPduTable[TxIpduId].TxDynLength)
#define COM_TXPDU_REQ_CONF_NUM(TxIpduId)         (Com_TxPduTable[TxIpduId].TxConfNumOfRep)
#define COM_TXPDU_TX_REQ_MINDELAY_BACKUP(TxIpduId)  (Com_TxPduTable[TxIpduId].txMinDelayReqBackUp)
#define COM_TXPDU_TP_INDEX(TxIpduId)                (Com_TxPduTable[TxIpduId].tpPduIndex)
#define COM_TXPDU_IFACTIVE_FLAG(TxIpduId)                (Com_TxPduTable[TxIpduId].txActiveFlag)



#define COM_TXPDU_TXMODE(TxIpduId)               (Com_TxPduTable[TxIpduId].TxModeSelectPtr->TxModeMode)
#define COM_TXPDU_TXMODE_PERIOD(TxIpduId)        (Com_TxPduTable[TxIpduId].TxModeSelectPtr->TxModeTimePeriod)
#define COM_TXPDU_TXMODE_REP_NUM(TxIpduId)       (Com_TxPduTable[TxIpduId].TxModeSelectPtr->TxModeNumberOfRepetitions)
#define COM_TXPDU_TXMOD_REP_PERIOD(TxIpduId)     (Com_TxPduTable[TxIpduId].TxModeSelectPtr->TxModeRepetitionPeriod)
/*#define COM_TXPDU_TXMOD_TXTIME_OFFSET(TxIpduId)  (Com_TxPduTable[TxIpduId].TxModeSelectPtr->TxModeTimeOffset)not used in this version*/


/* tx Pdu cfg access  */
#define COM_CFG_TXPDU_IS_IMM_PROCESSING(TxIpduId)    (COM_CFG_TXPDU_INFO[TxIpduId].isImmProcess)
#define COM_CFG_TXPDU_SIG_START_NUM(TxIpduId)        (COM_CFG_TXPDU_INFO[TxIpduId].SignalStartNum)
#define COM_CFG_TXPDU_SIG_STOP_NUM(TxIpduId)         (COM_CFG_TXPDU_INFO[TxIpduId].SignalStopNum)
#define COM_CFG_TXPDU_MIN_DELAY_TIMER(TxIpduId)      (COM_CFG_TXPDU_INFO[TxIpduId].MinimumDelayTime)
#define COM_CFG_TXPDU_PERIOD_TIMEOUT(TxIpduId)       (COM_CFG_TXPDU_INFO[TxIpduId].PeriodTimeOut)
#define COM_CFG_TXPDU_TIMEOUT_MONITOR_FLAG(TxIpduId) (COM_CFG_TXPDU_INFO[TxIpduId].TimeOutMonitorFlag)
#define COM_CFG_TXPDUGROUP_FLAG(TxIpduId)            (COM_CFG_TXPDU_INFO[TxIpduId].TxIPDUGroupFlag)
#define COM_CFG_TXPDU_MAP_PDUR(TxIpduId)             (COM_CFG_TXPDU_INFO[TxIpduId].IpduMapPdur)
#define COM_CFG_TXPDU_FILTER_SIZE(TxIpduId)          (COM_CFG_TXPDU_INFO[TxIpduId].FilterByteNum)
#define COM_CFG_TXPDU_FILTER_PTR(TxIpduId)           (COM_CFG_TXPDU_INFO[TxIpduId].TMCFilterFlagPtr)
#define COM_CFG_TXPDU_DATA_PTR(TxIpduId)             (COM_CFG_TXPDU_INFO[TxIpduId].SduDataPtr)
#define COM_CFG_TXPDU_LENGTH(TxIpduId)               (COM_CFG_TXPDU_INFO[TxIpduId].SduLength)
#define COM_CFG_TXPDU_TXMODE_TRUE_PTR(TxIpduId)      (COM_CFG_TXPDU_INFO[TxIpduId].TxModeTrueCfgTablePtr)
#define COM_CFG_TXPDU_TXMODE_FALSE_PTR(TxIpduId)     (COM_CFG_TXPDU_INFO[TxIpduId].TxModeFalseCfgTablePtr)
#define COM_CFG_TXPDU_IS_DYN(TxIpduId)               (COM_CFG_TXPDU_INFO[TxIpduId].isTxDynPdu)
#define COM_CFG_TXPDU_IS_TP_PDU(TxIpduId)            (COM_CFG_TXPDU_INFO[TxIpduId].isTpPdu)
#define COM_CFG_TXPDU_CALLOUT(TxIpduId)              (COM_CFG_TXPDU_INFO[TxIpduId].Callout)
#define COM_CFG_TXPDU_CANCEL_TRANSMIT_FLAG(TxIpduId) (COM_CFG_TXPDU_INFO[TxIpduId].TxCancelTransmitSupportFlag)
#define COM_CFG_TXPDU_TRIGGER_CALLOUT(TxIpduId)      (COM_CFG_TXPDU_INFO[TxIpduId].TxTriggerCallout)
#define COM_CFG_TXPDU_UPDATEBIT_INFO(TxIpduId)       (COM_CFG_TXPDU_INFO[TxIpduId].updateBitInfo)
#define COM_CFG_TXPDU_UPDATEBIT_NUM(TxIpduId)        (COM_CFG_TXPDU_INFO[TxIpduId].updateBitNum)
#define COM_CFG_TXPDU_UPDATEBIT_CLEARTYPE(TxIpduId)  (COM_CFG_TXPDU_INFO[TxIpduId].cubType)
#define COM_CFG_TXPDU_UNUSED_BYTE(TxIpduId)          (COM_CFG_TXPDU_INFO[TxIpduId].unusedAreaByte)
/*#define COM_CFG_TX_TRUE_MODE(TxIpduId)               (COM_CFG_TXPDU_TXMODE_TRUE_PTR(TxIpduId)->TxModeMode) not used in this version*/
/*#define COM_CFG_TX_FALSE_MODE(TxIpduId)              (COM_CFG_TXPDU_TXMODE_FALSE_PTR(TxIpduId)->TxModeMode) not used in this version*/
#define COM_CFG_TXPDU_IN_PDUGRP_NUM(TxIpduId)        (COM_CFG_TXPDU_INFO[TxIpduId].numOfPduGrp)
#define COM_CFG_TXPDU_IN_PDUGRP_PTR(TxIpduId)        (COM_CFG_TXPDU_INFO[TxIpduId].PduGrpPtr)





/* tx signal cfg access  */
#define COM_CFG_TXSIG_TXPDU_ID(TxSigId)             (COM_CFG_TXSIG_INFO[TxSigId].TxPduId)
#define COM_CFG_TXSIG_TRANSPROPERTY(TxSigId)        (COM_CFG_TXSIG_INFO[TxSigId].SigTransferProperty)
#define COM_CFG_TXSIG_TYPE(TxSigId)                 (COM_CFG_TXSIG_INFO[TxSigId].SigType)
#define COM_CFG_TXSIG_LENGTH(TxSigId)               (COM_CFG_TXSIG_INFO[TxSigId].SigLen)
#define COM_CFG_TXSIG_START_BYTE_INDEX(TxSigId)     (COM_CFG_TXSIG_INFO[TxSigId].SigStartByteIndex)
#define COM_CFG_TXSIG_INIT_VALUE_PTR(TxSigId)       (COM_CFG_TXSIG_INFO[TxSigId].InitValPtr)
#define COM_CFG_TXSIG_INIT_VALUE_LEN(TxSigId)       (COM_CFG_TXSIG_INFO[TxSigId].InitLen)
#define COM_CFG_TXSIG_INVALID_VALUE_PTR(TxSigId)    (COM_CFG_TXSIG_INFO[TxSigId].InvalidValPtr)
#define COM_CFG_TXSIG_INVALID_VALUE_LEN(TxSigId)    (COM_CFG_TXSIG_INFO[TxSigId].InvalidLen)
#define COM_CFG_TXSIG_IS_GROUP_SIGNAL(TxSigId)      (COM_CFG_TXSIG_INFO[TxSigId].isGroupSignal)
#define COM_CFG_TXSIG_GET_SIGGROUPID(TxSigId)       (COM_CFG_TXSIG_INFO[TxSigId].groupId)
#define COM_CFG_TXSIG_GROUP_TEMP_BUF(TxSigId)       (COM_CFG_TXSIG_INFO[TxSigId].GroupSigTempBuf)
#define COM_CFG_TXSIG_GROUP_TEMPLENGTH_PTR(TxSigId) (COM_CFG_TXSIG_INFO[TxSigId].GroupDynSigLengthBuf)
#define COM_CFG_TXSIG_UPDATEBIT_INDEX(TxSigId)      (COM_CFG_TXSIG_INFO[TxSigId].updateBitIndex)
#if(COM_TX_FILTER_SUPPORT == STD_ON)
#define COM_CFG_TXSIG_FILTER_PTR(TxSigId)           (COM_CFG_TXSIG_INFO[TxSigId].TxSigFilter)
#define COM_CFG_TXSIG_CHECK_FILTER(TxSigId)         (COM_CFG_TXSIG_INFO[TxSigId].checkFilter)
#endif
#define COM_CFG_TXSIG_INACTIVE_VALUE_PTR(TxSigId)    (COM_CFG_TXSIG_INFO[TxSigId].InvalidValPtr)

#define COM_CFG_TXSIG_INACTIVE_OFFSET(TxSigId)    (COM_CFG_TXSIG_INFO[TxSigId].txActiveFlagOffset)



#define COM_CFG_TXSIG_WRITE_SIG_FUN(TxSigId)        (COM_CFG_TXSIG_INFO[TxSigId].WriteSignalFun)
/*#define COM_CFG_TXSIG_READ_SIG_FUN(TxSigId)         (COM_CFG_TXSIG_INFO[TxSigId].ReadSignalFun) not used in this version*/
#define COM_CFG_TXSIG_COPY_SIG_FUN(TxSigId)         (COM_CFG_TXSIG_INFO[TxSigId].CopySignalFun)
#define COM_CFG_TXSIG_CHECKCHANGE_SIG_FUN(TxSigId)  (COM_CFG_TXSIG_INFO[TxSigId].CheckChangeSignalFun)
#define COM_CFG_TXSIG_TXTOINDICATION_FUN(TxSigId)   (COM_CFG_TXSIG_INFO[TxSigId].SigTxTOIndicationFun)
#define COM_CFG_TXSIG_CBKTXACK_FUN(TxSigId)         (COM_CFG_TXSIG_INFO[TxSigId].SigCbkTxAckFun)
#define COM_CFG_TXSIG_TXERR_FUN(TxSigId)            (COM_CFG_TXSIG_INFO[TxSigId].CbkTxErrFun)



/*******************************************************************************
*   Macro Rx
*******************************************************************************/
/* rx Pdu reg access  */
#define COM_RXPDU_TP_INDEX(RxIpduId)          (Com_RxPduTable[RxIpduId].tpPduIndex)
#define COM_RXPDU_TIMEOUT(RxIpduId)           (Com_RxPduTable[RxIpduId].RxPeriodTimeOut)
#define COM_RXPDU_MONITOR_FLAG(RxIpduId)      (Com_RxPduTable[RxIpduId].RxIpduTimeoutMonitorFlag)
#define COM_RXPDU_DYN_LENGTH(RxIpduId)        (Com_RxPduTable[RxIpduId].dynLength)
#define COM_RXPDU_TEMP_LENGTH(RxIpduId)       (Com_RxPduTable[RxIpduId].tempLength)


/* rx Pdu cfg access  */
#define COM_CFG_RXPDU_IS_IMM_PROCESSING(RxIpduId)   (COM_CFG_RXPDU_INFO[RxIpduId].isImmProcess)
#define COM_CFG_RXPDU_SIG_STOP_NUM(RxIpduId)        (COM_CFG_RXPDU_INFO[RxIpduId].SignalStopNum)
#define COM_CFG_RXPDU_SIG_START_NUM(RxIpduId)       (COM_CFG_RXPDU_INFO[RxIpduId].SignalStartNum)
#define COM_CFG_RXPDU_PERIOD_TIMEOUT(RxIpduId)      (COM_CFG_RXPDU_INFO[RxIpduId].RxPeriodTimeOut)
#define COM_CFG_RXPDU_FIRST_TIMEOUT(RxIpduId)       (COM_CFG_RXPDU_INFO[RxIpduId].RxFirstTimeOut)
#define COM_CFG_RXPDU_MONITOR_FLAG(RxIpduId)        (COM_CFG_RXPDU_INFO[RxIpduId].RxIpduTimeoutMonitorFlag)
#define COM_CFG_RXPDU_DATA_PTR(RxIpduId)            (COM_CFG_RXPDU_INFO[RxIpduId].SduDataPtr)
#define COM_CFG_RXPDU_LENGTH(RxIpduId)              (COM_CFG_RXPDU_INFO[RxIpduId].SduLength)
#define COM_CFG_RXPDUGROUP_FLAG(RxIpduId)           (COM_CFG_RXPDU_INFO[RxIpduId].RxIPDUGroupFlag)
#define COM_CFG_RXPDU_IS_TP_PDU(RxIpduId)           (COM_CFG_RXPDU_INFO[RxIpduId].isTpPdu)
#define COM_CFG_RXPDU_CALLOUT(RxIpduId)             (COM_CFG_RXPDU_INFO[RxIpduId].Callout)
#define COM_CFG_RXPDU_IS_DYN(RxIpduId)              (COM_CFG_RXPDU_INFO[RxIpduId].isRxDynPdu)
#define COM_CFG_RXPDU_FIX_LENGTH(RxIpduId)          (COM_CFG_RXPDU_INFO[RxIpduId].RxPduFixLength)
#define COM_CFG_RXPDU_DATA_PTR_TEMP(RxIpduId)       (COM_CFG_RXPDU_INFO[RxIpduId].RxBufTemp)
#define COM_CFG_RXPDU_UPDATEBIT_INFO(RxIpduId)      (COM_CFG_RXPDU_INFO[RxIpduId].updateBitInfo)
#define COM_CFG_RXPDU_UPDATEBIT_NUM(RxIpduId)       (COM_CFG_RXPDU_INFO[RxIpduId].updateBitNum)
#define COM_CFG_RXPDU_IN_PDUGRP_NUM(RxIpduId)       (COM_CFG_RXPDU_INFO[RxIpduId].numOfPduGrp)
#define COM_CFG_RXPDU_IN_PDUGRP_PTR(RxIpduId)       (COM_CFG_RXPDU_INFO[RxIpduId].PduGrpPtr)


/* rx sig cfg access  */
#define COM_CFG_RXSIG_RXPDU_ID(RxSigId)            (COM_CFG_RXSIG_INFO[RxSigId].RxPduId)
#define COM_CFG_RXSIG_TYPE(RxSigId)                (COM_CFG_RXSIG_INFO[RxSigId].SigType)
#define COM_CFG_RXSIG_LENGTH(RxSigId)              (COM_CFG_RXSIG_INFO[RxSigId].SigLen)
#define COM_CFG_RXSIG_START_BYTE_INDEX(RxSigId)    (COM_CFG_RXSIG_INFO[RxSigId].SigStartByteIndex)
#define COM_CFG_RXSIG_INIT_VALUE_PTR(RxSigId)      (COM_CFG_RXSIG_INFO[RxSigId].InitValPtr)
#define COM_CFG_RXSIG_INIT_VALUE_LEN(RxSigId)      (COM_CFG_RXSIG_INFO[RxSigId].InitLen)
#define COM_CFG_RXSIG_INVALID_ACTION(RxSigId)      (COM_CFG_RXSIG_INFO[RxSigId].DataInvalidAction)
/*#define COM_CFG_RXSIG_INVALID_VALUE_PTR(RxSigId)   (COM_CFG_RXSIG_INFO[RxSigId].InvalidValPtr) not used in this version*/
/*#define COM_CFG_RXSIG_INVALID_VALUE_LEN(RxSigId)   (COM_CFG_RXSIG_INFO[RxSigId].InvalidLen) not used in this version*/
#define COM_CFG_RXSIG_GW_INDEX(RxSigId)            (COM_CFG_RXSIG_INFO[RxSigId].GwSigIndex)
#if((COM_RX_FILTER_SUPPORT == STD_ON) || (STD_ON == COM_RX_INVALID_SUPPORT))
#define COM_CFG_RXSIG_FILTER_PTR(RxSigId)          (COM_CFG_RXSIG_INFO[RxSigId].RxSigFilter)
#define COM_CFG_RXSIG_CHECK_SIG_FUN(RxSigId)       (COM_CFG_RXSIG_INFO[RxSigId].CheckRxSigFun)
#endif
#define COM_CFG_RXSIG_UPDATEBIT_INDEX(RxSigId)     (COM_CFG_RXSIG_INFO[RxSigId].updateBitIndex)
#define COM_CFG_RXSIG_UPTO_INDEX(RxSigId)          (COM_CFG_RXSIG_INFO[RxSigId].upTimeoutIndex)
#define COM_CFG_RXSIG_UPTO_PERIOD(RxSigId)         (COM_CFG_RXSIG_INFO[RxSigId].RxPeriodTimeOut)
#define COM_CFG_RXSIG_UPTO_FIRSTPERIOD(RxSigId)    (COM_CFG_RXSIG_INFO[RxSigId].RxFirstTimeOut)
#define COM_CFG_RXSIG_TO_REPLACE(RxSigId)          (COM_CFG_RXSIG_INFO[RxSigId].isTimeoutReplace)

#define COM_CFG_RXSIG_IS_GROUP_SIGNAL(RxSigId)       (COM_CFG_RXSIG_INFO[RxSigId].isGroupSignal)
#define COM_CFG_RXSIG_GET_SIGGROUPID(RxSigId)        (COM_CFG_RXSIG_INFO[RxSigId].groupId)
#define COM_CFG_RXSIG_GROUP_TEMP_BUF(RxSigId)        (COM_CFG_RXSIG_INFO[RxSigId].GroupSigTempBuf)
#define COM_CFG_RXSIG_GROUP_TEMPLENGTH_PTR(RxSigId)  (COM_CFG_RXSIG_INFO[RxSigId].GroupDynSigLengthBuf)

#define COM_CFG_RXSIG_MIN_BYTE(RxSigId)              (COM_CFG_RXSIG_INFO[RxSigId].MinSigByte)


#define COM_CFG_RXSIG_CBKRXACK_FUN(RxSigId)        (COM_CFG_RXSIG_INFO[RxSigId].RxSigCbkRxAckFun)
#define COM_CFG_RXSIG_CBKINV_FUN(RxSigId)          (COM_CFG_RXSIG_INFO[RxSigId].RxSigCbkInvFun)
#define COM_CFG_RXSIG_CBKRXTOUT_FUN(RxSigId)       (COM_CFG_RXSIG_INFO[RxSigId].RxSigCbkRxTOutFun)

#define COM_CFG_RXSIG_MOVE_FUN(RxSigId)            (COM_CFG_RXSIG_INFO[RxSigId].MoveSignalFun)
#define COM_CFG_RXSIG_WRITE_SIG_FUN(RxSigId)       (COM_CFG_RXSIG_INFO[RxSigId].WriteSignalFun)
#define COM_CFG_RXSIG_READ_SIG_FUN(RxSigId)        (COM_CFG_RXSIG_INFO[RxSigId].ReadSignalFun)
#define COM_CFG_RXSIG_COPY_SIG_FUN(RxSigId)        (COM_CFG_RXSIG_INFO[RxSigId].CopySignalFun)


/*******************************************************************************
*   Macro ipdu group
*******************************************************************************/
#if (STD_ON == COM_IPDU_GROUP_FUN)
#define COM_CFG_TX_PDUGROUP_PTR(IpduGroupId)                (COM_CFG_PDU_GROUP_INFO[IpduGroupId].TxIpduGroupPtr)
#define COM_CFG_TX_PDUGROUP_NUM(IpduGroupId)                (COM_CFG_PDU_GROUP_INFO[IpduGroupId].TxIpduGroupNum)


#define COM_CFG_RX_PDUGROUP_PTR(IpduGroupId)                (COM_CFG_PDU_GROUP_INFO[IpduGroupId].RxIpduGroupPtr)
#define COM_CFG_RX_PDUGROUP_NUM(IpduGroupId)                (COM_CFG_PDU_GROUP_INFO[IpduGroupId].RxIpduGroupNum)

#endif


/*******************************************************************************
*   Macro signal group
*******************************************************************************/
/* Signal Group Access*/
#define COM_CFG_TXSIGGRP_SUPPORT_ARRAY(SigGrpId)         (COM_CFG_TXSIG_GROUP_INFO[SigGrpId].isArrayAccessSupport)
#define COM_CFG_TXSIGGRP_SIGSTOP(SigGrpId)               (COM_CFG_TXSIG_GROUP_INFO[SigGrpId].SignalStopNum)
#define COM_CFG_TXSIGGRP_SIGSTART(SigGrpId)              (COM_CFG_TXSIG_GROUP_INFO[SigGrpId].SignalStartNum)
#define COM_CFG_TXSIGGRP_UPDATEBIT_INDEX(SigGrpId)       (COM_CFG_TXSIG_GROUP_INFO[SigGrpId].updateBitIndex)
#define COM_CFG_TXSIGGRP_TRPROP(SigGrpId)                (COM_CFG_TXSIG_GROUP_INFO[SigGrpId].SigGrpTransferProperty)
#define COM_CFG_TXSIGGRP_PDUID(SigGrpId)                 (COM_CFG_TXSIG_GROUP_INFO[SigGrpId].PduId)
#define COM_CFG_TXSIGGRP_STARTBYTE(SigGrpId)             (COM_CFG_TXSIG_GROUP_INFO[SigGrpId].StartByte)
#define COM_CFG_TXSIGGRP_SIZE(SigGrpId)                  (COM_CFG_TXSIG_GROUP_INFO[SigGrpId].ByteNum)
#define COM_CFG_TXSIGGRP_HAS_INVALID_VAL(SigGrpId)       (COM_CFG_TXSIG_GROUP_INFO[SigGrpId].hasInValidVal)
/*#define COM_CFG_TXSIGGRP_HAS_FILTER(SigGrpId)            (COM_CFG_TXSIG_GROUP_INFO[SigGrpId].hasFilter) not used in this version*/


#define COM_CFG_RXSIGGRP_SUPPORT_ARRAY(SigGrpId)         (COM_CFG_RXSIG_GROUP_INFO[SigGrpId].isArrayAccessSupport)
#define COM_CFG_RXSIGGRP_SIGSTOP(SigGrpId)               (COM_CFG_RXSIG_GROUP_INFO[SigGrpId].SignalStopNum)
#define COM_CFG_RXSIGGRP_SIGSTART(SigGrpId)              (COM_CFG_RXSIG_GROUP_INFO[SigGrpId].SignalStartNum)
/*#define COM_CFG_RXSIGGRP_UPDATEBIT_INDEX(SigGrpId)       (COM_CFG_RXSIG_GROUP_INFO[SigGrpId].updateBitIndex)not used in this version*/
/*#define COM_CFG_RXSIGGRP_TRPROP(SigGrpId)                (COM_CFG_RXSIG_GROUP_INFO[SigGrpId].SigGrpTransferProperty)not used in this version*/
#define COM_CFG_RXSIGGRP_PDUID(SigGrpId)                 (COM_CFG_RXSIG_GROUP_INFO[SigGrpId].PduId)
#define COM_CFG_RXSIGGRP_STARTBYTE(SigGrpId)             (COM_CFG_RXSIG_GROUP_INFO[SigGrpId].StartByte)
#define COM_CFG_RXSIGGRP_SIZE(SigGrpId)                  (COM_CFG_RXSIG_GROUP_INFO[SigGrpId].ByteNum)
#define COM_CFG_RXSIGGRP_HAS_INVALID_VAL(SigGrpId)       (COM_CFG_RXSIG_GROUP_INFO[SigGrpId].hasInValidVal)
#define COM_CFG_RXSIGGRP_HAS_FILTER(SigGrpId)            (COM_CFG_RXSIG_GROUP_INFO[SigGrpId].hasFilter)



/*******************************************************************************
*   Macro
*******************************************************************************/
#if(STD_ON == COM_DEV_ERROR_DETECT)

#define  COM_DET_ERROR_DETECT(cond, ApiId, errcode)  \
    DET_ERROR_DETECT((cond), COM_MODULE_ID, COM_INSTANCE_ID,(ApiId),(errcode))

#define  COM_DET_ERROR_DETECT_RET(cond, ApiId, errcode, ret) \
    DET_ERROR_DETECT_RET((cond), COM_MODULE_ID,COM_INSTANCE_ID,(ApiId),(errcode), (ret))

#define  COM_DET_REPORT_ERROR(ApiId, errcode)  \
    DET_REPORT_ERROR(COM_MODULE_ID, COM_INSTANCE_ID, (ApiId), (errcode))

#define  COM_DET_REPORT_RUNTIME_ERROR(ApiId, errcode)  \
    DET_REPORT_RUNTIME_ERROR(COM_MODULE_ID, COM_INSTANCE_ID, (ApiId), (errcode))

#else

#define  COM_DET_ERROR_DETECT(cond, ApiId, errcode)
#define  COM_DET_ERROR_DETECT_RET(cond, ApiId, errcode, ret)
#define  COM_DET_REPORT_ERROR(ApiId, errcode)
#define  COM_DET_REPORT_RUNTIME_ERROR(ApiId, errcode)

#endif


/*******************************************************************************
*   Static Api of Com
*******************************************************************************/
#define COM_START_SEC_CODE
#include "MemMap.h"

#if(STD_ON == COM_TXPDU_FUN)

STATIC FUNC(void, COM_CODE) Com_InitTxPdu
(
    PduIdType TxIpduId,
    boolean   isStartFlag
);

STATIC FUNC(void, COM_CODE) Com_InitTxPduValue
(
    PduIdType TxIpduId
);

#if((STD_ON == COM_TX_FILTER_SUPPORT) && (COM_MAX_FILTER_OCCURRENCE_NUM > 0))
STATIC FUNC(void, COM_CODE) Com_InitTxOccOfPdu
(
    PduIdType TxIpduId
);
#endif


#if(STD_ON == COM_IPDU_GROUP_FUN)
STATIC FUNC(void, COM_CODE) Com_SwitchTxPduMode
(
    PduIdType TxIpduId,
    boolean   isStartFlag,
    boolean   InitFlag
);

STATIC FUNC(void, COM_CODE) Com_CbkTxErrAck_PDU
(
    PduIdType TxIpduId
);

#endif

STATIC FUNC(void, COM_CODE) Com_TxInit(void);

#if (STD_ON == COM_TX_FILTER_SUPPORT)
STATIC FUNC(boolean, COM_CODE) Com_GetTMSResult
(
    PduIdType TxIpduId
);

STATIC FUNC(void, COM_CODE) Com_SelectPduTxMode
(
    PduIdType TxIpduId,
    uint8 TxSendSwitchTxModeFlag
);

#endif

#if(STD_ON == COM_TX_TIMEOUT_MONITOR)
STATIC FUNC(void, COM_CODE) Com_StartTxDeadlineMotitor
(
    PduIdType TxIpduId,
    boolean needRestartTimer
);
#endif

#if(STD_OFF == COM_TXMODE_PERIODIC_ONLY)
STATIC FUNC(uint8, COM_CODE) Com_HandleDirect
(
    PduIdType TxIpduId
);
#endif

#if((STD_ON == COM_TXMODE_PERIODIC) || (STD_ON == COM_TXMODE_MIXED))
STATIC FUNC(boolean, COM_CODE) Com_HandlePeriod
(
    PduIdType TxIpduId
);
#endif

#if(STD_ON == COM_TXMODE_MIXED)
STATIC FUNC(boolean, COM_CODE) Com_HandleMixed
(
    PduIdType TxIpduId
);
#endif

#if(STD_ON == COM_TXMODE_NONE)
STATIC FUNC(void, COM_CODE) Com_HandleNone
(
    PduIdType TxIpduId
);
#endif

#if (STD_ON == COM_TXMODE_IFACTIVE_SUPPORT)
STATIC FUNC(void, COM_CODE) Com_CheckTxSigIfActive
(
    PduIdType TxIpduId,
    Com_SignalIdType TxSigId,
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) newDataPtr,
    P2CONST(void, AUTOMATIC, COM_CONST)     cfgInActiveValPtr
);

STATIC FUNC(boolean, COM_CODE) Com_HandleIfActive
(
    PduIdType TxIpduId
);

#endif


STATIC FUNC(boolean, COM_CODE) Com_TxModeProcess
(
    PduIdType TxIpduId
);

STATIC FUNC(void, COM_CODE) Com_TransmitPdu
(
    PduIdType TxIpduId
);

#if(STD_ON == COM_TX_TIMEOUT_MONITOR)
STATIC FUNC(void, COM_CODE) Com_CbkTxTOut_PDU
(
    PduIdType TxIpduId
);
STATIC FUNC(void, COM_CODE) Com_TxTimerOutMonitor
(
    PduIdType TxIpduId
);
#endif

STATIC FUNC(void, COM_CODE) Com_CbkTxAck_PDU
(
    PduIdType TxIpduId
);



#if(STD_OFF == COM_TXMODE_PERIODIC_ONLY)
STATIC FUNC(void, COM_CODE) Com_SetIpduTrigRepFlag
(
    Com_SignalTxPropertyType txProperty,
    PduIdType TxIpduId,
    boolean changeFlag
);

#endif


#if(STD_ON == COM_TX_FILTER_SUPPORT)
STATIC FUNC(void, COM_CODE) Com_TxSignalFilter
(
    Com_SignalIdType  ComTxSigId,
    P2CONST(void, AUTOMATIC, AUTOMATIC) value
);

#endif

#if(STD_ON == COM_TX_UPDATEBIT_SUPPORT)
STATIC FUNC(void, COM_CODE) Com_SetSigUpdateBit
(
    PduIdType TxIpduId,
    uint16  index
);
STATIC FUNC(void, COM_CODE) Com_ClearUpdateBit
(
    PduIdType TxIpduId
);

#endif


STATIC FUNC(void, COM_CODE) Com_ProcessTxConf
(
    PduIdType TxIpduId,
    Com_TxPduStateType pduState
);


#endif/*#if(STD_ON == COM_TXPDU_FUN)*/


#if(STD_ON == COM_RXPDU_FUN)


#if (STD_ON == COM_RX_INVALID_SUPPORT)
STATIC FUNC(void, COM_CODE) Com_RxPduInvalid
(
    PduIdType RxPduId
);
#endif

STATIC FUNC(boolean, COM_CODE) Com_CheckRxLength
(
    PduIdType RxPduId,
    PduLengthType length
);


STATIC FUNC(void, COM_CODE) Com_ReplaceRxSignalWithInit
(
    PduIdType RxPduId,
    uint16 sigId,
    boolean needRoutOut
);


STATIC FUNC(void, COM_CODE) Com_InitRxPdu
(
    PduIdType RxIpduId,
    boolean   isStartFlag
);


#if(STD_ON == COM_IPDU_GROUP_FUN)
STATIC FUNC(void, COM_CODE) Com_SwitchRxPduMode
(
    PduIdType RxIpduId,
    boolean   isStartFlag,
    boolean   InitFlag
);
#endif

STATIC FUNC(void, COM_CODE) Com_RxInit
(
    void
);

#if(STD_ON == COM_RX_TIMEOUT_MONITOR)
STATIC FUNC(void, COM_CODE) Com_RxTimerOutMonitor
(
    PduIdType RxIpduId
);
#if(STD_ON == COM_RX_UPDATEBIT_SUPPORT)
STATIC FUNC(void, COM_CODE) Com_ResetUpdateRxToTimer
(
    PduIdType RxIpduId
);

STATIC FUNC(void, COM_CODE) Com_UpdateRxTimerOutMonitor
(
    PduIdType RxIpduId
);
#endif
#endif

#if(STD_ON == COM_RX_UPDATEBIT_SUPPORT)
STATIC FUNC(boolean, COM_CODE) Com_CheckSigUpdateBit
(
    PduIdType RxIpduId,
    Com_SignalIdType index
);
#endif

#if((COM_RX_FILTER_SUPPORT == STD_ON) && (COM_MAX_FILTER_OCCURRENCE_NUM > 0))
STATIC FUNC(void, COM_CODE) Com_InitRxOccOfPdu
(
    PduIdType RxIpduId
);
#endif



STATIC FUNC(void, COM_CODE) Com_InitRxPduValue
(
    PduIdType RxIpduId
);

STATIC FUNC(void, COM_CODE) Com_HandleRxPdu_DirectCopy
(
    PduIdType RxPduId
);

#if(STD_OFF == COM_RX_DIRECT_COPY)
#if (STD_ON == COM_RX_SIGNAL_GROUP_SUPPORT)
#if ((COM_RX_FILTER_SUPPORT == STD_ON) || (STD_ON == COM_RX_INVALID_SUPPORT))
STATIC FUNC(uint8, COM_CODE) Com_CheckRxSignalGroup_Invalid_Filter
(
    PduIdType RxPduId,
    Com_SignalGroupIdType SigGrpId
);
#endif

STATIC FUNC(void, COM_CODE) Com_RxSignalGroup_ProcessAfterCheck
(
    PduIdType RxPduId,
    uint8 filterResult,
    Com_SignalIdType RxSigId,
    Com_SignalGroupIdType SigGrpId
);
#endif

STATIC FUNC(void, COM_CODE) Com_RxSignal_ProcessAfterCheck
(
    uint8 filterResult,
    PduIdType RxPduId,
    Com_SignalIdType RxSigId
);

STATIC FUNC(void, COM_CODE) Com_HandleRxPdu
(
    PduIdType RxPduId
);

#endif



#endif/*#if(STD_ON == COM_RXPDU_FUN)*/


#if(STD_ON == COM_IPDU_GROUP_FUN)
STATIC FUNC(void, COM_CODE) Com_IpduGroupStart_Internal
(
    Com_IpduGroupIdType IpduGroupId,
    boolean Initialize
);
STATIC FUNC(void, COM_CODE) Com_IpduGroupStop_Internal
(
    Com_IpduGroupIdType IpduGroupId
);
STATIC FUNC(boolean, COM_CODE) Com_IsPduStart
(
    PduIdType pduId,
    boolean isTx
);
#endif
#if(STD_ON == COM_RX_TIMEOUT_MONITOR)
STATIC FUNC(boolean, COM_CODE) Com_IsPduDMEnable_Internal
(
    PduIdType pduId
);
#endif


#if(STD_ON == COM_IPDU_GROUP_FUN)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Com_IsPduStart
*
* Description:   This service check if pdu need to be started based on pdu group state
*
* Inputs:        pduId, isTx
*
* Outputs:       boolean
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(boolean, COM_CODE) Com_IsPduStart
(
    PduIdType pduId,
    boolean isTx
)
{
    boolean flag = FALSE;
    Com_IpduGroupIdType grpIdx = (Com_IpduGroupIdType)0;
    PduIdType tmpNum = (PduIdType)0;
    P2CONST(PduIdType, AUTOMATIC, COM_CONST) tmpPtr = NULL_PTR;

    if(TRUE == isTx)
    {
#if(STD_ON == COM_TXPDU_FUN)
        tmpNum = COM_CFG_TXPDU_IN_PDUGRP_NUM(pduId);
        tmpPtr = COM_CFG_TXPDU_IN_PDUGRP_PTR(pduId);
#endif
    }
    else
    {
#if(STD_ON == COM_RXPDU_FUN)
        tmpNum = COM_CFG_RXPDU_IN_PDUGRP_NUM(pduId);
        tmpPtr = COM_CFG_RXPDU_IN_PDUGRP_PTR(pduId);
#endif
    }

    /* search all pdugroup which contains thia pdu, if any one is start, retuan True = Start*/
    for(grpIdx =  (Com_IpduGroupIdType)0; grpIdx < tmpNum; grpIdx++)
    {
        if(TRUE == Com_IpduGroupStartFlag[tmpPtr[grpIdx]])
        {
            flag = TRUE;
            break;
        }
    }


    return flag;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Com_IpduGroupStart_Internal SWS_Com_00751 792
*
* Description:   start target group and keep other group unchange
*
* Inputs:        IpduGroupId
*                Initialize
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, COM_CODE) Com_IpduGroupStart_Internal
(
    Com_IpduGroupIdType IpduGroupId,
    boolean Initialize
)
{
    PduIdType pduIndex = (PduIdType)0;
    PduIdType pduId = (PduIdType)0;
    
    /* SWS_COM 7.3.5.2, starts group if it was previously stopped*/
    if(FALSE == Com_IpduGroupStartFlag[IpduGroupId])
    {

        Com_IpduGroupStartFlag[IpduGroupId] = TRUE;
#if(STD_ON == COM_RX_TIMEOUT_MONITOR)
        Com_IpduGroupDMEnableFlag[IpduGroupId] = TRUE;
#endif
    /* start group  */
#if(STD_ON == COM_TXPDU_FUN)
        for(pduIndex = (PduIdType)0; pduIndex < COM_CFG_TX_PDUGROUP_NUM(IpduGroupId); pduIndex++)
        {
            pduId = COM_CFG_TX_PDUGROUP_PTR(IpduGroupId)[pduIndex];
            if(Com_TxPduState[pduId] == COM_TXPDU_STOP)
            {
                Com_SwitchTxPduMode(pduId, TRUE, Initialize);
            }
            /* when pdu is already in start state, do nothing even Initialize = true, donot reset signal value or tx period*/


        }
#endif
#if(STD_ON == COM_RXPDU_FUN)
        for(pduIndex = (PduIdType)0; pduIndex < COM_CFG_RX_PDUGROUP_NUM(IpduGroupId); pduIndex++)
        {
            pduId = COM_CFG_RX_PDUGROUP_PTR(IpduGroupId)[pduIndex];
            if(Com_RxPduState[pduId] == COM_RXPDU_STOP)
            {
                Com_SwitchRxPduMode(pduId, TRUE, Initialize);
            }
            /* when pdu is already in start state, do nothing even Initialize = true, donot reset signal value */
        
        }
#endif
    }
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Com_IpduGroupStop_Internal SWS_Com_00751 792
*
* Description:   stop target group and keep other group unchange
*
* Inputs:        IpduGroupId
*
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, COM_CODE) Com_IpduGroupStop_Internal
(
    Com_IpduGroupIdType IpduGroupId
)
{
    PduIdType pduIndex = (PduIdType)0;
    PduIdType pduId = (PduIdType)0;
    boolean tmpPduStartFlag = FALSE;
  
    /* SWS_COM 7.3.5.3, stop group if it was previously started*/
    if(TRUE == Com_IpduGroupStartFlag[IpduGroupId])
    {
        /* must set group = false first , as following code will use this flag to decide the pdu state*/
        Com_IpduGroupStartFlag[IpduGroupId] = FALSE;
#if(STD_ON == COM_RX_TIMEOUT_MONITOR)
        Com_IpduGroupDMEnableFlag[IpduGroupId] = FALSE;
#endif
#if(STD_ON == COM_TXPDU_FUN)
        /* Stop group  */
        for(pduIndex = (PduIdType)0; pduIndex < COM_CFG_TX_PDUGROUP_NUM(IpduGroupId); pduIndex++)
        {
            pduId = COM_CFG_TX_PDUGROUP_PTR(IpduGroupId)[pduIndex];

            /* search all pdugroup which contains thia pdu, if any one is start, retuan True*/
            tmpPduStartFlag = Com_IsPduStart(pduId, TRUE);

            if((tmpPduStartFlag == FALSE) && (Com_TxPduState[pduId] != COM_TXPDU_STOP))
            {
                Com_SwitchTxPduMode(pduId, FALSE, FALSE);
        
                /* Err Ack when pdu is sending out*/
                if((COM_TXPDU_START_BUSY == Com_TxPduState[pduId])
                        || (COM_TXPDU_START_RETX == Com_TxPduState[pduId]))
                {
                    Com_CbkTxErrAck_PDU(pduId);
                }

            }

            /* if pdu already in stop state  do nothing*/
            /* if pdu need to keep start ,  do nothing*/

        }
#endif
#if(STD_ON == COM_RXPDU_FUN)
        for(pduIndex = (PduIdType)0; pduIndex < COM_CFG_RX_PDUGROUP_NUM(IpduGroupId); pduIndex++)
        {
            pduId = COM_CFG_RX_PDUGROUP_PTR(IpduGroupId)[pduIndex];
            /* search all pdugroup which contains thia pdu, if any one is start, retuan True*/
            tmpPduStartFlag = Com_IsPduStart(pduId, FALSE);

            if((tmpPduStartFlag == FALSE) && (Com_RxPduState[pduId] != COM_RXPDU_STOP))
            {
                Com_SwitchRxPduMode(pduId, FALSE, FALSE);
            }

            /* if pdu already in stop state  do nothing*/
            /* if pdu need to keep start ,  do nothing*/
        }
#endif
    }
}

#endif/* #if(STD_ON == COM_IPDU_GROUP_FUN) */


#if(STD_ON == COM_TXPDU_FUN)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Com_WriteSignal_Internal
*
* Description:   This service write signal into txbuf or shadow buffer
*
* Inputs:        SignalId, SignalDataPtr, length
*
* Outputs:       uint8
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(uint8, COM_CODE) Com_WriteSignal_Internal
(
    Com_SignalIdType SignalId,
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr,
    PduLengthType length
)
{


    PduIdType TxIpduId = COM_CFG_TXSIG_TXPDU_ID(SignalId);
#if(STD_OFF == COM_TXMODE_PERIODIC_ONLY)
    boolean ChangeFlag = FALSE;
#endif
    uint8 result = COM_SERVICE_NOT_AVAILABLE;

#if(STD_ON == COM_TX_SIGNAL_GROUP_SUPPORT)
    if(FALSE == COM_CFG_TXSIG_IS_GROUP_SIGNAL(SignalId))
#endif
    {
        /* SWS_Com_00334, signal can be updated when pdu is stop
           in stop mode, tms result, txmode and data will be saved
           but trigger will not be saved,
           so that the msg will not be send at once when pdu is started
        */
        if((COM_TXPDU_START_BUSY == Com_TxPduState[TxIpduId]) && (TRUE == COM_CFG_TXPDU_IS_TP_PDU(TxIpduId)))
        {
            result = COM_BUSY;
        }
        else
        {
#if(STD_ON == COM_TXSIG_ON_CHANGE_SUPPORT)
            if( ( COM_CFG_TXSIG_TRANSPROPERTY(SignalId) >= COM_TRIGGERED_ON_CHANGE ) && ( COM_CFG_TXSIG_TRANSPROPERTY(SignalId) < COM_IFACTIVE_SIG ) )
            {
                ChangeFlag = COM_CFG_TXSIG_CHECKCHANGE_SIG_FUN(SignalId)(TxIpduId, SignalId, SignalDataPtr, length);
            }
#endif

            /* do Tx Filter if configured , must filter before write data , as maybe mask oldNew*/
#if(STD_ON == COM_TX_FILTER_SUPPORT)
            Com_TxSignalFilter(SignalId, SignalDataPtr);
#endif

            COM_CFG_TXSIG_WRITE_SIG_FUN(SignalId)(SignalDataPtr, COM_CFG_TXPDU_DATA_PTR(TxIpduId), length);

#if(STD_ON == COM_TXMODE_IFACTIVE_SUPPORT)
            Com_CheckTxSigIfActive(TxIpduId, SignalId,SignalDataPtr, COM_CFG_TXSIG_INACTIVE_VALUE_PTR(SignalId));
#endif



#if(STD_ON == COM_TX_DYN_PDU_SUPPORT)
            if(COM_SIG_DYN == COM_CFG_TXSIG_TYPE(SignalId))
            {
                COM_TXPDU_DYN_LENGTH(TxIpduId) = COM_CFG_TXSIG_START_BYTE_INDEX(SignalId) + length;
            }
#endif

#if(COM_TX_UPDATEBIT_SUPPORT == STD_ON)
            /* set update bit if configured*/
            if(COM_INVALID_SIG_INDEX != COM_CFG_TXSIG_UPDATEBIT_INDEX(SignalId))
            {
                Com_SetSigUpdateBit(TxIpduId, COM_CFG_TXSIG_UPDATEBIT_INDEX(SignalId));
            }
#endif

            /* this Asr req Page54 Table3, when pdu is stop, data canbe updated, but return COM_SERVICE_NOT_AVAILABLE*/
            /*SWS_Com_334 dont save trigger when stop*/
            if(COM_TXPDU_STOP != Com_TxPduState[TxIpduId])
            {
#if(STD_OFF == COM_TXMODE_PERIODIC_ONLY)
                Com_SetIpduTrigRepFlag(COM_CFG_TXSIG_TRANSPROPERTY(SignalId), TxIpduId, ChangeFlag);
#endif
                result = E_OK;
            }



        }
    }
#if(STD_ON == COM_TX_SIGNAL_GROUP_SUPPORT)
    else
    {
        /* if group signal, only update shadow buffer */
        /*shadow buffer can be updated even txstate is busy*/
        /* if group enable array access, dont do anything here*/
        if(FALSE == COM_CFG_TXSIGGRP_SUPPORT_ARRAY(COM_CFG_TXSIG_GET_SIGGROUPID(SignalId)))
        {
            COM_CFG_TXSIG_COPY_SIG_FUN(SignalId)(SignalDataPtr, COM_CFG_TXSIG_GROUP_TEMP_BUF(SignalId), length);
#if(STD_ON == COM_TX_DYN_PDU_SUPPORT)
            if(COM_SIG_DYN == COM_CFG_TXSIG_TYPE(SignalId))
            {
                *COM_CFG_TXSIG_GROUP_TEMPLENGTH_PTR(SignalId) = length;
            }
#endif
            /* this Asr req Page54 Table3, when pdu is stop, data canbe updated, but return COM_SERVICE_NOT_AVAILABLE*/
            if(COM_TXPDU_STOP != Com_TxPduState[TxIpduId])
            {
                result = E_OK;
            }
        }
    }
#endif

    return result;

}



#if(STD_ON == COM_TX_UPDATEBIT_SUPPORT)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Com_ClearUpdateBit
*
* Description:   This service set target update bits of signal
*
* Inputs:        TxIpduId, index
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, COM_CODE) Com_SetSigUpdateBit
(
    PduIdType TxIpduId,
    uint16  index
)
{
    PduLengthType tempByteIndex = COM_CFG_TXPDU_UPDATEBIT_INFO(TxIpduId)[index].UpdateByteIndex;
    uint8 tempMaskValue = COM_CFG_TXPDU_UPDATEBIT_INFO(TxIpduId)[index].UpdateMaskValue;

    tempMaskValue = (uint8)(~tempMaskValue);

    ((uint8 *)COM_CFG_TXPDU_DATA_PTR(TxIpduId))[tempByteIndex] |= tempMaskValue;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Com_ClearUpdateBit
*
* Description:   This service clear all update bits of pdu
*
* Inputs:        TxIpduId:
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, COM_CODE) Com_ClearUpdateBit
(
    PduIdType TxIpduId
)
{
    uint16 index = (uint16)0;
    PduLengthType tempByteIndex;
    uint8 tempMaskValue;

    for(index = (uint16)0; index < COM_CFG_TXPDU_UPDATEBIT_NUM(TxIpduId); index++)
    {
        tempByteIndex = COM_CFG_TXPDU_UPDATEBIT_INFO(TxIpduId)[index].UpdateByteIndex;
        tempMaskValue = COM_CFG_TXPDU_UPDATEBIT_INFO(TxIpduId)[index].UpdateMaskValue;

        ((uint8 *)COM_CFG_TXPDU_DATA_PTR(TxIpduId))[tempByteIndex] &= tempMaskValue;
    }

}
#endif/*COM_TX_UPDATEBIT_SUPPORT*/



/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Com_InitTxOccOfPdu
*
* Description:   Init Tx signal's occ counter to 0, if configured
*
* Inputs:        TxIpduId
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
#if((STD_ON == COM_TX_FILTER_SUPPORT) && (COM_MAX_FILTER_OCCURRENCE_NUM > 0))
STATIC FUNC(void, COM_CODE) Com_InitTxOccOfPdu
(
    PduIdType TxIpduId
)
{
    Com_SignalIdType SigIndex = (Com_SignalIdType)0;

    for(SigIndex = COM_CFG_TXPDU_SIG_START_NUM(TxIpduId); SigIndex <= COM_CFG_TXPDU_SIG_STOP_NUM(TxIpduId); SigIndex++)
    {
        if(NULL_PTR != COM_CFG_TXSIG_FILTER_PTR(SigIndex))
        {
            if(COM_INVALID_SIG_INDEX != COM_CFG_TXSIG_FILTER_PTR(SigIndex)->occIndex)
            {
                Com_Sig_Occurrence[COM_CFG_TXSIG_FILTER_PTR(SigIndex)->occIndex] = (Com_SignalIdType)0;
            }
        }
    }
}
#endif



/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Com_InitTxPduValue
*
* Description:   Init Rx Pdu values
*
* Inputs:        RxIpduId
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, COM_CODE) Com_InitTxPduValue
(
    PduIdType TxIpduId
)
{
    PduLengthType IndexData = (PduLengthType)0;
    Com_SignalIdType SigIndex = (Com_SignalIdType)0;
    PduLengthType sigLen = (PduLengthType)0;

    /* Step 1 set all byte to unused byte*/
    for(IndexData = (PduLengthType)0; IndexData < COM_CFG_TXPDU_LENGTH(TxIpduId); IndexData++)
    {
        ((uint8 *)COM_CFG_TXPDU_DATA_PTR(TxIpduId))[IndexData] = COM_CFG_TXPDU_UNUSED_BYTE(TxIpduId);
    }
    /* Step 2 init all signals of this pdu*/
    for(SigIndex = COM_CFG_TXPDU_SIG_START_NUM(TxIpduId); SigIndex <= COM_CFG_TXPDU_SIG_STOP_NUM(TxIpduId); SigIndex++)
    {
#if ((STD_ON == COM_TX_DYN_PDU_SUPPORT) || (STD_ON == COM_TX_U8N_SUPPORT))
        sigLen = COM_CFG_TXSIG_LENGTH(SigIndex);
#if (STD_ON == COM_TX_DYN_PDU_SUPPORT)
        if(COM_SIG_DYN == COM_CFG_TXSIG_TYPE(SigIndex))
        {
            sigLen = COM_CFG_TXSIG_INIT_VALUE_LEN(SigIndex);
            COM_TXPDU_DYN_LENGTH(TxIpduId) = COM_CFG_TXSIG_START_BYTE_INDEX(SigIndex) + sigLen ;
        }
#endif
#endif

        /* copy init value to real buffer*/
        COM_CFG_TXSIG_WRITE_SIG_FUN(SigIndex)(COM_CFG_TXSIG_INIT_VALUE_PTR(SigIndex), COM_CFG_TXPDU_DATA_PTR(TxIpduId),  sigLen);
#if (STD_ON == COM_TX_SIGNAL_GROUP_SUPPORT)
        /* Also copy to shadow buffer*/
        if(NULL_PTR != COM_CFG_TXSIG_GROUP_TEMP_BUF(SigIndex))
        {
            COM_CFG_TXSIG_COPY_SIG_FUN(SigIndex)(COM_CFG_TXSIG_INIT_VALUE_PTR(SigIndex), COM_CFG_TXSIG_GROUP_TEMP_BUF(SigIndex),  sigLen);
        }
#if (STD_ON == COM_TX_DYN_PDU_SUPPORT)
        if(NULL_PTR != COM_CFG_TXSIG_GROUP_TEMPLENGTH_PTR(SigIndex))
        {
            *COM_CFG_TXSIG_GROUP_TEMPLENGTH_PTR(SigIndex) = sigLen;
        }
#endif
#endif

    }
    /* Step 3 clear all update bit*/
#if (STD_ON == COM_TX_UPDATEBIT_SUPPORT)
    Com_ClearUpdateBit(TxIpduId);
#endif

}




/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Com_InitTxPdu
*
* Description:   used to Init TxPduRegs, only called when Init
*
* Inputs:         TxIpduId,isStartFlag
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, COM_CODE) Com_InitTxPdu
(
    PduIdType TxIpduId,
    boolean   isStartFlag
)
{

    /*TxMode Init*/
#if(STD_ON == COM_TX_FILTER_SUPPORT)
    COM_TXPDU_TMS_FLAG(TxIpduId) = TRUE;
    Com_SendSwitchTxModeFlag[TxIpduId] = COM_NO_TXMODE_SWITCH;
#endif
    COM_TXPDU_TXMODE_PTR(TxIpduId) = COM_CFG_TXPDU_TXMODE_TRUE_PTR(TxIpduId);


    /*Timer Init*/
    COM_TXPDU_PERIOD(TxIpduId) = COM_TIMER_STOP_VAL;/* tx period will be Init in Tx Main */
    COM_TXPDU_TXTIME_OFFSET(TxIpduId) = COM_TXPDU_TXMODE_PTR(TxIpduId)->TxModeTimeOffset;

#if (STD_ON == COM_MDT_CYCLIC_TRANSMISSION)
    COM_TXPDU_MIN_DELAY_TIMER(TxIpduId) = COM_TIMER_STOP_VAL;
    COM_TXPDU_TX_REQ_MINDELAY_BACKUP(TxIpduId) = FALSE;
#endif

#if (STD_ON == COM_TXMODE_REPTITION)
    COM_TXPDU_REP_NUM(TxIpduId) = (uint8)0;
    COM_TXPDU_PERIOD_BACKUP(TxIpduId) = COM_TIMER_STOP_VAL;
    COM_TXPDU_REQ_CONF_NUM(TxIpduId) = (uint8)0;
#endif

#if(STD_OFF == COM_TXMODE_PERIODIC_ONLY)
    Com_PDUTrigRepFlag[TxIpduId] = (uint8)0;
#endif

#if(STD_ON ==     COM_TX_TIMEOUT_MONITOR)
    /* dont need to check if txto is enable for this pdu*/
    COM_TXPDU_TIMEOUT(TxIpduId) = COM_TIMER_STOP_VAL;
#endif

#if(STD_ON == COM_TX_LONG_PDU_FUN)
    COM_TXPDU_TP_INDEX(TxIpduId) = (PduLengthType)0;
#endif

#if(STD_ON == COM_TXMODE_IFACTIVE_SUPPORT)
    COM_TXPDU_IFACTIVE_FLAG(TxIpduId) = (uint32)0;
#endif


    /*Pdu Data Length Init*/
    Com_InitTxPduValue(TxIpduId);


#if(STD_ON == COM_TriggerIPDUSend_API)
    Com_TriggerPDUSendFlag[TxIpduId] = FALSE;
#endif

    if(FALSE == isStartFlag)
    {
        Com_TxPduState[TxIpduId] = COM_TXPDU_STOP;/*SWS_Com_444 all group stop at Init*/
    }
    else
    {
        Com_TxPduState[TxIpduId] = COM_TXPDU_START_IDLE;/*SWS_Com_840*/
    }



}



/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Com_SwitchTxPduMode
*
* Description:   used to Init TxPduRegs when pdu mode switch,
*
* Inputs:          TxIpduId,isStartFlag,InitFlag
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
#if(STD_ON == COM_IPDU_GROUP_FUN)
STATIC FUNC(void, COM_CODE) Com_SwitchTxPduMode
(
    PduIdType TxIpduId,
    boolean   isStartFlag,
    boolean   InitFlag
)
{

#if(STD_ON == COM_TX_LONG_PDU_FUN)
    COM_TXPDU_TP_INDEX(TxIpduId) = (PduLengthType)0;
#endif

#if(STD_OFF == COM_TXMODE_PERIODIC_ONLY)
    Com_PDUTrigRepFlag[TxIpduId] = (uint8)0;
#endif

    /*Timer Init
      Start->Stop, Stop-Start,timers will all stop.
      except txOffset timer, will keep unchange, until restart

      data and length
      keep unchange until restart with init

      trigger flag and rep num must reset

    */
    COM_TXPDU_PERIOD(TxIpduId) = COM_TIMER_STOP_VAL;/* tx period will be Init in Tx Main */
    /* offset will reset when pdu restart, so that, the pdu will send like init SWS_Com_00222 -4*/
    COM_TXPDU_TXTIME_OFFSET(TxIpduId) = COM_TXPDU_TXMODE_PTR(TxIpduId)->TxModeTimeOffset;

#if (STD_ON == COM_MDT_CYCLIC_TRANSMISSION)/*SWS_Com_00787-1*/
    COM_TXPDU_MIN_DELAY_TIMER(TxIpduId) = COM_TIMER_STOP_VAL;
    COM_TXPDU_TX_REQ_MINDELAY_BACKUP(TxIpduId) = FALSE;
#endif

#if (STD_ON == COM_TXMODE_REPTITION)
    COM_TXPDU_REP_NUM(TxIpduId) = (uint8)0;
    COM_TXPDU_PERIOD_BACKUP(TxIpduId) = COM_TIMER_STOP_VAL;
    COM_TXPDU_REQ_CONF_NUM(TxIpduId) = (uint8)0;
#endif


#if(STD_ON ==     COM_TX_TIMEOUT_MONITOR)
    /* dont need to check if txto is enable for this pdu*/
    COM_TXPDU_TIMEOUT(TxIpduId) = COM_TIMER_STOP_VAL;/*SWS_Com_00787-2*/
#endif


#if(STD_ON == COM_TriggerIPDUSend_API)
    Com_TriggerPDUSendFlag[TxIpduId] = FALSE;
#endif


#if((STD_ON == COM_TX_FILTER_SUPPORT) && (COM_MAX_FILTER_OCCURRENCE_NUM > 0))
    Com_InitTxOccOfPdu(TxIpduId);/*SWS_Com_00787-4*/
#endif

    /* if InitFlag = false, the value write when pdu stop will keep ,alsp the updatebit and Com_SendSwitchTxModeFlag will keep
       so that the TMS will be caculated in next mainfunctiontx
    */

    if((TRUE == isStartFlag) && (TRUE == InitFlag))
    {
        /*TxMode Init*/

#if(STD_ON == COM_TX_FILTER_SUPPORT)
        COM_TXPDU_TMS_FLAG(TxIpduId) = TRUE;
        Com_SendSwitchTxModeFlag[TxIpduId] = COM_NO_TXMODE_SWITCH;
#endif
        COM_TXPDU_TXMODE_PTR(TxIpduId) = COM_CFG_TXPDU_TXMODE_TRUE_PTR(TxIpduId);

        /*Pdu Data Length Init SWS_Com_00222 -1-2-3*/
        Com_InitTxPduValue(TxIpduId);

    }

    if(FALSE == isStartFlag)
    {
        Com_TxPduState[TxIpduId] = COM_TXPDU_STOP;/*SWS_Com_444 all group stop at Init*/
    }
    else
    {
        Com_TxPduState[TxIpduId] = COM_TXPDU_START_IDLE;/*SWS_Com_114*/
    }

}

/* BEGIN_FUNCTION_HDR
*******************************************************************************
* Function Name: Com_CbkTxErrAck_PDU
*
* Description:   Called when Pdu is Stoped, but msg is onGoing
*
* Inputs:        TxIpduId
*
* Outputs:       None
*
* Limitations:   None
*******************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, COM_CODE) Com_CbkTxErrAck_PDU
(
    PduIdType TxIpduId
)
{

    Com_SignalIdType TxSigId = (Com_SignalIdType)0;
#if(STD_ON == COM_TX_SIGNAL_GROUP_SUPPORT)
    Com_SignalGroupIdType SignalGroupId = (Com_SignalGroupIdType)0;
#endif


    for(TxSigId = COM_CFG_TXPDU_SIG_START_NUM(TxIpduId);
            TxSigId <= COM_CFG_TXPDU_SIG_STOP_NUM(TxIpduId);
            TxSigId++)
    {
        if(NULL_PTR != COM_CFG_TXSIG_TXERR_FUN(TxSigId))
        {
            COM_CFG_TXSIG_TXERR_FUN(TxSigId)();
        }
#if(STD_ON == COM_TX_SIGNAL_GROUP_SUPPORT)
        if(TRUE == COM_CFG_TXSIG_IS_GROUP_SIGNAL(TxSigId))
        {
            SignalGroupId = COM_CFG_TXSIG_GET_SIGGROUPID(TxSigId);
            /* set sigId to the end of this group, 1 group only ack once */
            TxSigId = COM_CFG_TXSIGGRP_SIGSTOP(SignalGroupId);
        }
#endif


    }
}





#endif/* #if(STD_ON == COM_IPDU_GROUP_FUN)*/



/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Com_TxInit
*
* Description:   Tx initialize.
*
* Inputs:        None
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, COM_CODE) Com_TxInit
(
    void
)
{

    PduIdType IpduIndex = (PduIdType)0;

    for(IpduIndex = (PduIdType)0; IpduIndex < COM_TXPDU_NUM; IpduIndex++)
    {
#if (STD_ON == COM_IPDU_GROUP_FUN)
        if(TRUE == COM_CFG_TXPDUGROUP_FLAG(IpduIndex))
        {
            Com_InitTxPdu(IpduIndex, FALSE);
        }
        else
#endif
        {
            Com_InitTxPdu(IpduIndex, TRUE);
        }
    }
}

/* BEGIN_FUNCTION_HDR
*******************************************************************************
* Function Name: Com_GetTMSResult
*
* Description:   get tms result when tx sig updated
*
* Inputs:        TxIpduId: Ipdu Id
*
* Outputs:       boolean
*
* Limitations:   None
*******************************************************************************
END_FUNCTION_HDR*/
#if (STD_ON == COM_TX_FILTER_SUPPORT)
STATIC FUNC(boolean, COM_CODE) Com_GetTMSResult
(
    PduIdType TxIpduId
)
{

    Com_SignalIdType Index;
    boolean Result = FALSE;

    for(Index = (Com_SignalIdType)0; Index < COM_CFG_TXPDU_FILTER_SIZE(TxIpduId); Index++)
    {
        if((uint8)0 != COM_CFG_TXPDU_FILTER_PTR(TxIpduId)[Index])
        {
            Result = TRUE;
            break;
        }
    }

    return Result;
}

/* BEGIN_FUNCTION_HDR
*******************************************************************************
* Function Name: Com_SelectPduTxMode
*
* Description:
*
* Inputs:        None
*
* Outputs:       None
*
* Limitations:   None
*******************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, COM_CODE) Com_SelectPduTxMode
(
    PduIdType TxIpduId,
    uint8 TxSendSwitchTxModeFlag
)
{

    boolean CurrentTMSResult = FALSE;
    boolean result = FALSE;

    if(COM_NO_TXMODE_SWITCH != TxSendSwitchTxModeFlag)
    {
        if(COM_TXMODE_SWITCH_SEND_SIGNAL == TxSendSwitchTxModeFlag)
        {
            CurrentTMSResult = Com_GetTMSResult(TxIpduId);
        }


        if(((COM_TXMODE_SWITCH_SEND_SIGNAL == TxSendSwitchTxModeFlag)
                && (FALSE == CurrentTMSResult))
                || (COM_TXMODE_SWITCH_API_FALSE == TxSendSwitchTxModeFlag))
        {
            /* SWS_Com_799 TMS true->false*/
            if(TRUE == COM_TXPDU_TMS_FLAG(TxIpduId))
            {
                COM_TXPDU_TXMODE_PTR(TxIpduId) = COM_CFG_TXPDU_TXMODE_FALSE_PTR(TxIpduId);
                COM_TXPDU_TMS_FLAG(TxIpduId) = FALSE;
                result = TRUE;
            }
        }
        else
        {
            /* SWS_Com_032 TMS false->true*/
            if(FALSE == COM_TXPDU_TMS_FLAG(TxIpduId))
            {
                COM_TXPDU_TXMODE_PTR(TxIpduId) = COM_CFG_TXPDU_TXMODE_TRUE_PTR(TxIpduId);
                COM_TXPDU_TMS_FLAG(TxIpduId) = TRUE;
                result = TRUE;
            }
        }
    }

    /* Mode Switch, reset all mode AttriButes*/
    /* should not clear occ counter here, as it may cause mode swith back*/
    /* dont clear Com_PDUTrigRepFlag as the request need be process at  once after mode switch */

    if(TRUE == result)
    {
        COM_TXPDU_PERIOD(TxIpduId) = COM_TIMER_STOP_VAL;/* STOP Val will cause period Msg tx at once in this cycle */
        COM_TXPDU_TXTIME_OFFSET(TxIpduId) = COM_TXPDU_TXMODE_PTR(TxIpduId)->TxModeTimeOffset; /*SWS_Com_00495 set new offset as mode may be changed in offset time segment*/
#if (STD_ON == COM_MDT_CYCLIC_TRANSMISSION)
        /*COM_TXPDU_MIN_DELAY_TIMER(TxIpduId) = COM_TIMER_STOP_VAL;  do not reset mindelay when mode switch SWS_Com_00495*/
        COM_TXPDU_TX_REQ_MINDELAY_BACKUP(TxIpduId) = FALSE;

#endif

#if (STD_ON == COM_TXMODE_REPTITION)
        COM_TXPDU_PERIOD_BACKUP(TxIpduId) = COM_TIMER_STOP_VAL;
        COM_TXPDU_REP_NUM(TxIpduId) = (uint8)0;
        COM_TXPDU_REQ_CONF_NUM(TxIpduId) = (uint8)0;
#endif

#if(STD_ON == COM_TX_TIMEOUT_MONITOR)
        COM_TXPDU_TIMEOUT(TxIpduId) = COM_TIMER_STOP_VAL;
#endif

#if(STD_ON == COM_TX_LONG_PDU_FUN)
        COM_TXPDU_TP_INDEX(TxIpduId) = (PduLengthType)0;
#endif
        Com_TxPduState[TxIpduId] = COM_TXPDU_START_IDLE;/* return idle if state is busy or RETX, SWS_Com_00773 is not affected by transmission mode changes.*/


    }
}
#endif/*#if (STD_ON == COM_TX_FILTER_SUPPORT)*/

/* BEGIN_FUNCTION_HDR
*******************************************************************************
* Function Name: Com_StartTxDeadlineMotitor
*
* Description:   start deadlne monitor when sendreq is set
*
* Inputs:        None
*
* Outputs:       None
*
* Limitations:   None
*******************************************************************************
END_FUNCTION_HDR*/
#if(STD_ON == COM_TX_TIMEOUT_MONITOR)
STATIC FUNC(void, COM_CODE) Com_StartTxDeadlineMotitor
(
    PduIdType TxIpduId,
    boolean needRestartTimer
)
{
    if(TRUE == COM_CFG_TXPDU_TIMEOUT_MONITOR_FLAG(TxIpduId))
    {
        if((COM_TIMER_STOP_VAL == COM_TXPDU_TIMEOUT(TxIpduId))
                || (TRUE == needRestartTimer))
        {
            COM_TXPDU_TIMEOUT(TxIpduId) = COM_CFG_TXPDU_PERIOD_TIMEOUT(TxIpduId);
        }
    }

}
#endif


/* BEGIN_FUNCTION_HDR
*******************************************************************************
* Function Name: Com_HandleDirect
*
* Description:   process the tx Msg in Direct Mode
*
* Inputs:        None
*
* Outputs:       None
*
* Limitations:   None
*******************************************************************************
END_FUNCTION_HDR*/
#if(STD_OFF == COM_TXMODE_PERIODIC_ONLY)
STATIC FUNC(uint8, COM_CODE) Com_HandleDirect
(
    PduIdType TxIpduId
)
{
    uint8 result = COM_EVENT_TX_NONE;

    if(COM_TRIGGER == Com_PDUTrigRepFlag[TxIpduId])
    {
        result = COM_EVENT_TX_ONCE;
#if(STD_ON == COM_TX_TIMEOUT_MONITOR)
        Com_StartTxDeadlineMotitor(TxIpduId, FALSE);
#endif

    }
#if(STD_ON == COM_TXMODE_REPTITION)
    else if(COM_TRIGGER_REP == Com_PDUTrigRepFlag[TxIpduId])
    {
        /* SWS_Com_00279 anytime get rep triger, reset all rep counter */
        result = COM_EVENT_TX_REP;
        if(COM_TXPDU_TXMODE_REP_NUM(TxIpduId) > (uint8)0)
        {
            COM_TXPDU_REP_NUM(TxIpduId) = COM_TXPDU_TXMODE_REP_NUM(TxIpduId);/*SWS_Com_00305  ComTxModeNumberOfRepetitions + 1*/
        }
        else
        {
            COM_TXPDU_REP_NUM(TxIpduId) = (uint8)0;
        }

        COM_TXPDU_PERIOD_BACKUP(TxIpduId) = COM_TXPDU_TXMOD_REP_PERIOD(TxIpduId);

#if (STD_ON == COM_MDT_CYCLIC_TRANSMISSION)
        if((COM_CFG_TXPDU_MIN_DELAY_TIMER(TxIpduId) != (uint16)0) &&
            (COM_CFG_TXPDU_MIN_DELAY_TIMER(TxIpduId) > COM_TXPDU_TXMOD_REP_PERIOD(TxIpduId)))
        {
            COM_TXPDU_PERIOD_BACKUP(TxIpduId) = COM_CFG_TXPDU_MIN_DELAY_TIMER(TxIpduId);
        }
#endif

        /*SWS_Com_00305  ComTxModeNumberOfRepetitions + 1*/
        COM_TXPDU_REQ_CONF_NUM(TxIpduId) = COM_TXPDU_TXMODE_REP_NUM(TxIpduId) + (uint8)1;
#if(STD_ON == COM_TX_TIMEOUT_MONITOR)
        Com_StartTxDeadlineMotitor(TxIpduId, TRUE);/*SWS_Com_00739, restart deadline monitor, when new trigger is get */
#endif

    }
    else
    {
        /* no new trigger*/
        if((uint8)0 != COM_TXPDU_REP_NUM(TxIpduId))
        {
            result = COM_EVENT_NOTX_REP;
            if( COM_TXPDU_PERIOD_BACKUP(TxIpduId) > (uint16)0)
            {
                COM_TXPDU_PERIOD_BACKUP(TxIpduId)--;
            }

            if((uint16)0 == COM_TXPDU_PERIOD_BACKUP(TxIpduId))
            {
                COM_TXPDU_REP_NUM(TxIpduId)--;
                if((uint8)0 != COM_TXPDU_REP_NUM(TxIpduId))
                {
                    COM_TXPDU_PERIOD_BACKUP(TxIpduId) = COM_TXPDU_TXMOD_REP_PERIOD(TxIpduId);

#if (STD_ON == COM_MDT_CYCLIC_TRANSMISSION)
                    if((COM_CFG_TXPDU_MIN_DELAY_TIMER(TxIpduId) != (uint16)0) &&
                        (COM_CFG_TXPDU_MIN_DELAY_TIMER(TxIpduId) > COM_TXPDU_TXMOD_REP_PERIOD(TxIpduId)))
                    {
                        COM_TXPDU_PERIOD_BACKUP(TxIpduId) = COM_CFG_TXPDU_MIN_DELAY_TIMER(TxIpduId);
                    }
#endif

                }
                else
                {
                    COM_TXPDU_PERIOD_BACKUP(TxIpduId) = COM_TIMER_STOP_VAL;
                }

                result = COM_EVENT_TX_REP;
            }
        }
    }
#endif
    Com_PDUTrigRepFlag[TxIpduId] = (uint8)0;

    return result;

}
#endif

/* BEGIN_FUNCTION_HDR
*******************************************************************************
* Function Name: Com_HandlePeriod
*
* Description:   process the tx Msg in Period Mode
*
* Inputs:        None
*
* Outputs:       None
*
* Limitations:   None
*******************************************************************************
END_FUNCTION_HDR*/
#if((STD_ON == COM_TXMODE_PERIODIC) || (STD_ON == COM_TXMODE_MIXED))
STATIC FUNC(boolean, COM_CODE) Com_HandlePeriod
(
    PduIdType TxIpduId
)
{
    boolean sendFlag = FALSE;
	
    if((uint16)0 == COM_TXPDU_TXTIME_OFFSET(TxIpduId))
    {
        if(COM_TIMER_STOP_VAL == COM_TXPDU_PERIOD(TxIpduId))
        {
            /* first start, Init period = 0, Send 1 frame at once */
            COM_TXPDU_PERIOD(TxIpduId) = (uint16)0;
        }

        if(COM_TXPDU_PERIOD(TxIpduId) > (uint16)0)
        {
            COM_TXPDU_PERIOD(TxIpduId)--;
        }

        if((uint16)0 == COM_TXPDU_PERIOD(TxIpduId))
        {
            COM_TXPDU_PERIOD(TxIpduId) = COM_TXPDU_TXMODE_PERIOD(TxIpduId);
            sendFlag = TRUE;
#if(STD_ON == COM_TX_TIMEOUT_MONITOR)
            Com_StartTxDeadlineMotitor(TxIpduId, FALSE);
#endif
        }

    }
    if(COM_TXPDU_TXTIME_OFFSET(TxIpduId) > (uint16)0)
    {
        COM_TXPDU_TXTIME_OFFSET(TxIpduId)--;
    }
    return sendFlag;

}
#endif


/* BEGIN_FUNCTION_HDR
*******************************************************************************
* Function Name: Com_HandleMixed
*
* Description:   process the tx Msg in mix Mode
*
* Inputs:        None
*
* Outputs:       None
*
* Limitations:   None
*******************************************************************************
END_FUNCTION_HDR*/
#if(STD_ON == COM_TXMODE_MIXED)
STATIC FUNC(boolean, COM_CODE) Com_HandleMixed
(
    PduIdType TxIpduId
)
{
    /*
        mix mode 1: when overlap , stop period counter, only process tigger event. period will not restart until rep tx end
        mix mode 2: when overlap , keep running period counter, period request will consider as  triger
        mix mode 3 not support yet : when overlap , keep running period counter,  process triger and period only with limit of MDT
    */

    uint8 triggerSendFlag = COM_EVENT_TX_NONE;
    boolean result = FALSE;

    if((uint16)0 == COM_TXPDU_TXTIME_OFFSET(TxIpduId))
    {
        triggerSendFlag = Com_HandleDirect(TxIpduId);

#if (STD_ON == COM_FIRST_HANDLE_MIXED)
        /* rep or trigger is active, normal cycle is stop */
        if(triggerSendFlag != COM_EVENT_TX_NONE)
        {
            COM_TXPDU_PERIOD(TxIpduId) = COM_TXPDU_TXMODE_PERIOD(TxIpduId);
            if(triggerSendFlag > COM_EVENT_NOTX_REP)
            {
                result = TRUE;
            }
        }
        else
        {
            result = Com_HandlePeriod(TxIpduId);

        }
#endif

#if (STD_ON == COM_SECOND_HANDLE_MIXED)/* 2nd options  SWS_Com_00494*/
        /* rep or trigger is active, normal cycle is running but ignor send request */
        if(triggerSendFlag != COM_EVENT_TX_NONE)
        {
            (void)Com_HandlePeriod(TxIpduId);
            if(triggerSendFlag > COM_EVENT_NOTX_REP)
            {
                result = TRUE;
            }
        }
        else
        {
            result = Com_HandlePeriod(TxIpduId);
        }
#endif
    }
    else
    {
        COM_TXPDU_TXTIME_OFFSET(TxIpduId)--;
    }
    /*save trigger info before offset arrived, it may cause multipul transmission */
    /*Com_PDUTrigRepFlag[TxIpduId] = (uint8)0;*/
    return result;


}
#endif

/* BEGIN_FUNCTION_HDR
*******************************************************************************
* Function Name: Com_HandleNone
*
* Description:
*
* Inputs:        None
*
* Outputs:       None
*
* Limitations:   None
*******************************************************************************
END_FUNCTION_HDR*/
#if(STD_ON == COM_TXMODE_NONE)
STATIC FUNC(void, COM_CODE) Com_HandleNone
(
    PduIdType TxIpduId
)
{
#if(STD_OFF == COM_TX_TIMEOUT_MONITOR)
    (void)TxIpduId;
#endif
    /* None only, Start tx deadline motitor  SWS_Com_00696
       not none only, stop tx deadline motitor  SWS_Com_00835

       so that, lin  signals can be monitored by com

       this use false_ptr = null , to define the pdu has none mode only

    */
#if(STD_ON == COM_TX_TIMEOUT_MONITOR)
    if(NULL_PTR == COM_CFG_TXPDU_TXMODE_FALSE_PTR(TxIpduId))
    {
        Com_StartTxDeadlineMotitor(TxIpduId, FALSE);
    }
    else
    {
        COM_TXPDU_TIMEOUT(TxIpduId) = COM_TIMER_STOP_VAL;

    }
#endif


}
#endif



#if    (STD_ON == COM_TXMODE_IFACTIVE_SUPPORT)

#if 0
/* BEGIN_FUNCTION_HDR
*******************************************************************************
* Function Name: Com_CheckTxPduIfAcive
*
* Description:
*
* Inputs:        None
*
* Outputs:       boolean pdu active, false pdu not active
*
* Limitations:   None
*******************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(boolean, COM_CODE) Com_CheckTxPduIfAcive
(
    PduIdType TxIpduId
)
{
    Com_SignalIdType SigIndex = (Com_SignalIdType)0;
    boolean activeFlag = FALSE;

    for(SigIndex = COM_CFG_TXPDU_SIG_START_NUM(TxIpduId); SigIndex <= COM_CFG_TXPDU_SIG_STOP_NUM(TxIpduId); SigIndex++)
    {
        if((COM_CFG_TXSIG_TRANSPROPERTY(SigIndex) == COM_IFACTIVE_SIG)  && (COM_CFG_TXSIG_CHECKCHANGE_SIG_FUN(SigIndex) != NULL_PTR))
        {
            activeFlag = COM_CFG_TXSIG_CHECKCHANGE_SIG_FUN(SigIndex)(TxIpduId, SigIndex, COM_CFG_TXSIG_INACTIVE_VALUE_PTR(SigIndex), COM_CFG_TXSIG_LENGTH(SigIndex))
            /*if not = inactive value, meas active, break
            any signal active means pdu active
            */
            if(activeFlag == TRUE)
            {
                break;
            }
        }
    }


    return activeFlag;

}

#endif


/* BEGIN_FUNCTION_HDR
*******************************************************************************
* Function Name: Com_CheckTxSigIfAcive
*
* Description:   if active, set target pdu flag bit active, other wise clear target pdu flag bit
*
* Inputs:        None
*
* Outputs:       None
*
* Limitations:   None
*******************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, COM_CODE) Com_CheckTxSigIfActive
(
    PduIdType TxIpduId,
    Com_SignalIdType TxSigId,
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) newDataPtr,
    P2CONST(void, AUTOMATIC, COM_CONST)     cfgInActiveValPtr
)
{
    Com_SigType type  = COM_CFG_TXSIG_TYPE(TxSigId);
    boolean flag = FALSE;
    PduLengthType sigIdx = (PduLengthType)0;

    if((COM_CFG_TXSIG_TRANSPROPERTY(TxSigId) == COM_IFACTIVE_SIG) 
        && (COM_TXPDU_TXMODE(TxIpduId) == COM_IFACTIVE_PDU)
        &&(COM_CFG_TXSIG_INACTIVE_OFFSET(TxSigId)!= COM_INVALID_IFACTIVE_OFFSET_VALUE)
        &&(cfgInActiveValPtr != NULL_PTR)
        &&(newDataPtr != NULL_PTR))
    {
        switch(type)
        {
        case COM_SIG_U8:
            if(*(uint8 *)newDataPtr != * (uint8 *)cfgInActiveValPtr)
            {
                flag = TRUE;
            }
            break;
        case COM_SIG_U16:
            if(*(uint16 *)newDataPtr != * (uint16 *)cfgInActiveValPtr)
            {
                flag = TRUE;
            }
            break;
        case COM_SIG_U32:
            if(*(uint32 *)newDataPtr != * (uint32 *)cfgInActiveValPtr)
            {
                flag = TRUE;
            }
            break;
        case COM_SIG_BOOLEAN:
            if(*(boolean *)newDataPtr != * (boolean *)cfgInActiveValPtr)
            {
                flag = TRUE;
            }
            break;
        case COM_SIG_S8:
            if(*(sint8 *)newDataPtr != * (sint8 *)cfgInActiveValPtr)
            {
                flag = TRUE;
            }
            break;
        case COM_SIG_S16:
            if(*(sint16 *)newDataPtr != * (sint16 *)cfgInActiveValPtr)
            {
                flag = TRUE;
            }
            break;
        case COM_SIG_S32:
            if(*(sint32 *)newDataPtr != * (sint32 *)cfgInActiveValPtr)
            {
                flag = TRUE;
            }
            break;
        case COM_SIG_F32:
            if(*(float32 *)newDataPtr != * (float32 *)cfgInActiveValPtr)
            {
                flag = TRUE;
            }
            break;
        case COM_SIG_U64:
            if(*(uint64 *)newDataPtr != * (uint64 *)cfgInActiveValPtr)
            {
                flag = TRUE;
            }
            break;
        case COM_SIG_S64:
            if(*(sint64 *)newDataPtr != * (sint64 *)cfgInActiveValPtr)
            {
                flag = TRUE;
            }
            break;

        case COM_SIG_F64:
            if(*(float64 *)newDataPtr != * (float64 *)cfgInActiveValPtr)
            {
                flag = TRUE;
            }
            break;

        case COM_SIG_U8N:
            for(sigIdx = (PduLengthType)0; sigIdx < COM_CFG_TXSIG_LENGTH(TxSigId); sigIdx)
            {
                if( ((uint8*)newDataPtr)[sigIdx] != ((uint8*)cfgInActiveValPtr)[sigIdx])
                {
                    flag = TRUE;
                    break;
                }
            }
            break;
        /*DYN not support */

        default:
            break;
        }

        if(flag == TRUE)
        {
            COM_TXPDU_IFACTIVE_FLAG(TxIpduId) |= (uint32)((uint8)1 << COM_CFG_TXSIG_INACTIVE_OFFSET(TxSigId));
        }
        else
        {
            COM_TXPDU_IFACTIVE_FLAG(TxIpduId) &= (uint32)(~((uint8)1 << COM_CFG_TXSIG_INACTIVE_OFFSET(TxSigId)));
        }
    }
}



/* BEGIN_FUNCTION_HDR
*******************************************************************************
* Function Name: Com_HandleIfActive
*
* Description:
*
* Inputs:        None
*
* Outputs:       boolean pdu send, false pdu not send
*
* Limitations:   None
*******************************************************************************
END_FUNCTION_HDR*/

STATIC FUNC(boolean, COM_CODE) Com_HandleIfActive
(
    PduIdType TxIpduId
)
{
    boolean result = FALSE;


    if(((uint32)0 == COM_TXPDU_IFACTIVE_FLAG(TxIpduId)) && (COM_TXPDU_REP_NUM(TxIpduId) == (uint8)0))
    {
        /* inactive mode and no rep number, do nothing, just set period to stop value*/
        COM_TXPDU_PERIOD(TxIpduId) = COM_TIMER_STOP_VAL;
    }
    else
    {
        /* if-active mode do not send out when init, so dont check time offset here */
        /* actvive or rep>0. need to count the period */
        if(COM_TIMER_STOP_VAL == COM_TXPDU_PERIOD(TxIpduId))
        {
            /* first start, Init period = 0, Send 1 frame at once */
            COM_TXPDU_PERIOD(TxIpduId) = (uint16)0;
        }

        if(COM_TXPDU_PERIOD(TxIpduId) > (uint16)0)
        {
            COM_TXPDU_PERIOD(TxIpduId)--;
        }

        if((uint16)0 == COM_TXPDU_PERIOD(TxIpduId))
        {
            COM_TXPDU_PERIOD(TxIpduId) = COM_TXPDU_TXMOD_REP_PERIOD(TxIpduId);
            result = TRUE;
    #if(STD_ON == COM_TX_TIMEOUT_MONITOR)
            Com_StartTxDeadlineMotitor(TxIpduId, FALSE);
    #endif
            if((uint32)0 != COM_TXPDU_IFACTIVE_FLAG(TxIpduId)) /* active mode */
            {
                /*when active, keep rep num as init value */
                COM_TXPDU_REP_NUM(TxIpduId) = COM_TXPDU_TXMODE_REP_NUM(TxIpduId);
            }
            else /* inacive mode*/
            {
                if(COM_TXPDU_REP_NUM(TxIpduId) > (uint8)0)
                {
                    COM_TXPDU_REP_NUM(TxIpduId)--;
                    if(COM_TXPDU_REP_NUM(TxIpduId) == (uint8)0)
                    {
                        COM_TXPDU_PERIOD(TxIpduId) = COM_TIMER_STOP_VAL;
                    }
                }
                
            }

        }
    }
    return result;


}
#endif




/* BEGIN_FUNCTION_HDR
*******************************************************************************
* Function Name: Com_TxModeProcess
*
* Description:   Called in MainTx, decide if the Pdu can be send out this cycle
*
* Inputs:        TxIpduId,TxIPDUTrigRepFlag
*
* Outputs:       TRUE: PDU need to be sendout
*                  FALSE: PDU need not to be sendout
* Limitations:   None
*******************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(boolean, COM_CODE) Com_TxModeProcess
(
    PduIdType TxIpduId
)
{

    boolean sendFlag = FALSE;

    /* SWS_Com_239   new tx Mode will be used at once*/
    switch(COM_TXPDU_TXMODE(TxIpduId))
    {
#if    (STD_ON == COM_TXMODE_DIRECT)
    case COM_DIRECT:
        if(Com_HandleDirect(TxIpduId) > COM_EVENT_NOTX_REP)/* COM_EVENT_TX_ONCE or COM_EVENT_TX_REP*/
        {
            sendFlag = TRUE;
        }
        break;
#endif

#if    (STD_ON == COM_TXMODE_PERIODIC)
    case COM_PERIODIC:
        sendFlag = Com_HandlePeriod(TxIpduId);
        break;
#endif

#if    (STD_ON == COM_TXMODE_MIXED)
    case COM_MIXED:
        sendFlag = Com_HandleMixed(TxIpduId);
        break;
#endif

#if    (STD_ON == COM_TXMODE_NONE)
    case COM_PDU_NONE:
        Com_HandleNone(TxIpduId);
        break;
#endif

#if    (STD_ON == COM_TXMODE_IFACTIVE_SUPPORT)
    case COM_IFACTIVE_PDU:
    	sendFlag = Com_HandleIfActive(TxIpduId);
        break;
#endif


    default:
        /* NONE */
        break;

    }

    /* other reason may enable tx request */
#if (STD_ON == COM_TriggerIPDUSend_API)
    if(TRUE == Com_TriggerPDUSendFlag[TxIpduId])
    {
        sendFlag = TRUE;
        Com_TriggerPDUSendFlag[TxIpduId] = FALSE;
    }
#endif

#if (STD_ON == COM_RETRY_TRANSMIT_REQUESTS)
    if(COM_TXPDU_START_RETX == Com_TxPduState[TxIpduId])
    {
        sendFlag = TRUE;
    }
#endif

#if (STD_ON == COM_MDT_CYCLIC_TRANSMISSION)
    if(TRUE == COM_TXPDU_TX_REQ_MINDELAY_BACKUP(TxIpduId))
    {
        sendFlag = TRUE;
        COM_TXPDU_TX_REQ_MINDELAY_BACKUP(TxIpduId) = FALSE;
    }
#endif

    return sendFlag;
}

/* BEGIN_FUNCTION_HDR
*******************************************************************************
* Function Name: Com_TransmitPdu
*
* Description:
*
* Inputs:        None
*
* Outputs:       None
*
* Limitations:   None
*******************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, COM_CODE) Com_TransmitPdu
(
    PduIdType TxIpduId
)
{


    PduInfoType PduInfo;
    Std_ReturnType txReqResult = E_NOT_OK;

#if (COM_TXIPDU_CALLOUT == STD_ON)
    boolean TxIpduCalloutResultFlag = TRUE;
#endif


    PduInfo.SduDataPtr = (SduDataPtrType)COM_CFG_TXPDU_DATA_PTR(TxIpduId);
    PduInfo.SduLength = COM_CFG_TXPDU_LENGTH(TxIpduId);
#if (COM_TX_DYN_PDU_SUPPORT == STD_ON)
    if(TRUE == COM_CFG_TXPDU_IS_DYN(TxIpduId))
    {
        PduInfo.SduLength = COM_TXPDU_DYN_LENGTH(TxIpduId);
    }
#endif


#if (COM_TXIPDU_CALLOUT == STD_ON)
    if(NULL_PTR != COM_CFG_TXPDU_CALLOUT(TxIpduId))
    {
        TxIpduCalloutResultFlag = COM_CFG_TXPDU_CALLOUT(TxIpduId)(TxIpduId, &PduInfo);/*SWS_Com_00492*/
    }

    if(TRUE == TxIpduCalloutResultFlag)
#endif
    {
        /*SWS_Com_00138 759 760*/
        txReqResult = PduR_ComTransmit(COM_CFG_TXPDU_MAP_PDUR(TxIpduId), &PduInfo);

        if(E_OK == txReqResult)
        {
#if(COM_TX_UPDATEBIT_SUPPORT == STD_ON)
            if(COM_CUB_TX == COM_CFG_TXPDU_UPDATEBIT_CLEARTYPE(TxIpduId))
            {
                Com_ClearUpdateBit(TxIpduId);
            }
#endif

            Com_TxPduState[TxIpduId] = COM_TXPDU_START_BUSY;
#if(STD_ON == COM_TX_LONG_PDU_FUN)
            COM_TXPDU_TP_INDEX(TxIpduId) = (PduLengthType)0;
#endif

#if(STD_ON == COM_MDT_CYCLIC_TRANSMISSION)
            if(COM_CFG_TXPDU_MIN_DELAY_TIMER(TxIpduId) > (uint16)0)
            {
                COM_TXPDU_MIN_DELAY_TIMER(TxIpduId) = COM_CFG_TXPDU_MIN_DELAY_TIMER(TxIpduId);/* start MDT*/
            }
#endif
        }
        else
        {
#if(STD_ON == COM_RETRY_TRANSMIT_REQUESTS)/*SWS_Com_00698 828 */
            /* if PduR_ComTransmit retrun notok, and last msg is not finish,
               new txReq will be ignor, keep sending last msg
            */
            if(COM_TXPDU_START_BUSY != Com_TxPduState[TxIpduId])
            {
                Com_TxPduState[TxIpduId] = COM_TXPDU_START_RETX;
            }
#else
            Com_ProcessTxConf(TxIpduId, COM_TXPDU_START_TXNOTOK);/*consider it as tx not ok*/
#endif
        }
    }

}

/* BEGIN_FUNCTION_HDR
*******************************************************************************
* Function Name: Com_CbkTxTOut_PDU
*
* Description:
*
* Inputs:        None
*
* Outputs:       None
*
* Limitations:   None
*******************************************************************************
END_FUNCTION_HDR*/
#if(STD_ON == COM_TX_TIMEOUT_MONITOR)
STATIC FUNC(void, COM_CODE) Com_CbkTxTOut_PDU
(
    PduIdType TxIpduId
)
{

    Com_SignalIdType SigId = (Com_SignalIdType)0;
#if(STD_ON == COM_TX_SIGNAL_GROUP_SUPPORT)
    Com_SignalGroupIdType SignalGroupId = (Com_SignalGroupIdType)0;
#endif



    for(SigId = COM_CFG_TXPDU_SIG_START_NUM(TxIpduId);
            SigId <= COM_CFG_TXPDU_SIG_STOP_NUM(TxIpduId);
            SigId++)
    {

        if(NULL_PTR != COM_CFG_TXSIG_TXTOINDICATION_FUN(SigId))
        {
            COM_CFG_TXSIG_TXTOINDICATION_FUN(SigId)();
        }

#if(STD_ON == COM_TX_SIGNAL_GROUP_SUPPORT)
        if(TRUE == COM_CFG_TXSIG_IS_GROUP_SIGNAL(SigId))
        {
            SignalGroupId = COM_CFG_TXSIG_GET_SIGGROUPID(SigId);
            /* set sigId to the end of this group, 1 group only ack once */
            SigId = COM_CFG_TXSIGGRP_SIGSTOP(SignalGroupId);
        }
#endif

    }
}

/* BEGIN_FUNCTION_HDR
*******************************************************************************
* Function Name: Com_TxTimerOutMonitor
*
* Description:
*
* Inputs:        None
*
* Outputs:       None
*
* Limitations:   None
*******************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, COM_CODE) Com_TxTimerOutMonitor
(
    PduIdType TxIpduId
)
{

    if((TRUE == COM_CFG_TXPDU_TIMEOUT_MONITOR_FLAG(TxIpduId))
            && (COM_TIMER_STOP_VAL != COM_TXPDU_TIMEOUT(TxIpduId)))
    {
        /*SWS_Com_00445 */
        if((uint16)0 != COM_TXPDU_TIMEOUT(TxIpduId))
        {
            COM_TXPDU_TIMEOUT(TxIpduId)--;
        }

        if((uint16)0 == COM_TXPDU_TIMEOUT(TxIpduId))
        {
#if(STD_ON == COM_CANCEL_SUPPORT)
            if(TRUE == COM_CFG_TXPDU_CANCEL_TRANSMIT_FLAG(TxIpduId))
            {
                (void)PduR_ComCancelTransmit(COM_CFG_TXPDU_MAP_PDUR(TxIpduId));/*SWS_Com_00708*/
            }
#endif

            COM_TXPDU_TIMEOUT(TxIpduId) = COM_TIMER_STOP_VAL;
            Com_TxPduState[TxIpduId] = COM_TXPDU_START_IDLE;/* SWS_Com_00775no Tx any more*/
#if(STD_ON == COM_TXMODE_REPTITION)
            COM_TXPDU_REQ_CONF_NUM(TxIpduId) = (uint8)0;
            COM_TXPDU_REP_NUM(TxIpduId) = (uint8)0;/*SWS_Com_00392 ignor rest repetition tx*/
#endif

#if (STD_ON == COM_MDT_CYCLIC_TRANSMISSION)
            COM_TXPDU_MIN_DELAY_TIMER(TxIpduId) = COM_TIMER_STOP_VAL;/* SWS_Com_00812 Stop MDT if TxTimeout */
#endif

            /*SWS_Com_00812 do not reset Pengding txRequest, when txTimeout,
              like COM_TXPDU_TX_REQ_BACKUP  COM_TXPDU_TX_REQ_MINDELAY_BACKUP
            */

#if(STD_ON == COM_TX_LONG_PDU_FUN)
            COM_TXPDU_TP_INDEX(TxIpduId) = (PduLengthType)0;
#endif


            Com_CbkTxTOut_PDU(TxIpduId);/*SWS_Com_00304*/

        }
    }
}
#endif
/* BEGIN_FUNCTION_HDR
*******************************************************************************
* Function Name: Com_CbkTxAck_PDU
*
* Description:
*
* Inputs:        None
*
* Outputs:       None
*
* Limitations:   None
*******************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, COM_CODE) Com_CbkTxAck_PDU
(
    PduIdType TxIpduId
)
{

    Com_SignalIdType TxSigId = (Com_SignalIdType)0;

#if(STD_ON == COM_TX_SIGNAL_GROUP_SUPPORT)
    Com_SignalGroupIdType SignalGroupId = (Com_SignalGroupIdType)0;
#endif

    for(TxSigId = COM_CFG_TXPDU_SIG_START_NUM(TxIpduId);
            TxSigId <= COM_CFG_TXPDU_SIG_STOP_NUM(TxIpduId);
            TxSigId++)
    {
        if(NULL_PTR != COM_CFG_TXSIG_CBKTXACK_FUN(TxSigId))
        {
            COM_CFG_TXSIG_CBKTXACK_FUN(TxSigId)();
        }

#if(STD_ON == COM_TX_SIGNAL_GROUP_SUPPORT)
        if(TRUE == COM_CFG_TXSIG_IS_GROUP_SIGNAL(TxSigId))
        {
            SignalGroupId = COM_CFG_TXSIG_GET_SIGGROUPID(TxSigId);
            /* set sigId to the end of this group, 1 group only ack once */
            TxSigId = COM_CFG_TXSIGGRP_SIGSTOP(SignalGroupId);
        }
#endif




    }
}



/* BEGIN_FUNCTION_HDR
*******************************************************************************
* Function Name: Com_ProcessTxConf
*
* Description:   process tx confirmation
*
* Inputs:        TxIpduId,pduState
*
* Outputs:       None
*
* Limitations:   None
*******************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, COM_CODE) Com_ProcessTxConf
(
    PduIdType TxIpduId,
    Com_TxPduStateType pduState
)
{
    Com_TxPduStateType tmpState = pduState;
#if(STD_ON == COM_TXMODE_REPTITION)
    /* if notok, the error confirmation dont count*/
    /* confnum <= repnum, means unexpected frame may insert to repetition transmission, like tx from Com_TriggerIPDUSend, in this case, this confirmation dont count*/
    if((tmpState == COM_TXPDU_START_TXOK)
        && (COM_TXPDU_REQ_CONF_NUM(TxIpduId) > COM_TXPDU_REP_NUM(TxIpduId)))/* this also cover the COM_TXPDU_REQ_CONF_NUM(TxIpduId) > 0, as repnum is unsigned*/
    {
        COM_TXPDU_REQ_CONF_NUM(TxIpduId)--;
    }
    if((uint8)0 == COM_TXPDU_REP_NUM(TxIpduId))
    {
        if(COM_TXPDU_REQ_CONF_NUM(TxIpduId) > (uint8)0)
        {
            COM_TXPDU_REQ_CONF_NUM(TxIpduId) = (uint8)0;
            COM_TXPDU_REP_NUM(TxIpduId) = (uint8)0;
            /*rep = 0, but confrep > 0 means lost txconf  */
            tmpState = COM_TXPDU_START_TXNOTOK;
        }
    }
#endif

    if(tmpState == COM_TXPDU_START_TXOK)
    {
        Com_CbkTxAck_PDU(TxIpduId);
    }
    else
    {
        Com_CbkTxErrAck_PDU(TxIpduId);
    }

#if(COM_TX_TIMEOUT_MONITOR == STD_ON)
    /* Stop Tx Time out monitor*/
    /*SWS_Com_00308, rep txpdu, deadline is stopped when all rep is send out*/
    if(TRUE == COM_CFG_TXPDU_TIMEOUT_MONITOR_FLAG(TxIpduId))
    {
        COM_TXPDU_TIMEOUT(TxIpduId) = COM_TIMER_STOP_VAL;
    }
#endif

    Com_TxPduState[TxIpduId] = COM_TXPDU_START_IDLE;

}



#endif/*#if(STD_ON == COM_TXPDU_FUN)*/

#if(STD_ON == COM_RXPDU_FUN)


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Com_CheckRxLength
*
* Description:   check if rx length is valid
*
* Inputs:        RxPduId,length
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(boolean, COM_CODE) Com_CheckRxLength
(
    PduIdType RxPduId,
    PduLengthType length
)
{
    boolean ret = FALSE;

    /*length check */ /*SWS_Com_00574*/
#if (STD_ON == COM_PADDING_SUPPORT)
    if(length <= COM_CFG_RXPDU_LENGTH(RxPduId))
    {
        ret = TRUE;
    }
#else

#if (STD_ON == COM_RX_DYN_PDU_SUPPORT)
    if(TRUE == COM_CFG_RXPDU_IS_DYN(RxPduId))
    {
        if((length <= COM_CFG_RXPDU_LENGTH(RxPduId)) && (length >= COM_CFG_RXPDU_FIX_LENGTH(RxPduId)))
        {
            ret = TRUE;
        }
    }
    else
#endif
    {
        if(length == COM_CFG_RXPDU_LENGTH(RxPduId))
        {
            ret = TRUE;
        }
    }
#endif/* #if (STD_ON == COM_PADDING_SUPPORT) */

    return ret;

}



/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Com_CheckSigUpdateBit
*
* Description:   This service check if rx  signal's update bit is set
*
* Inputs:        RxIpduId, index
*
* Outputs:       boolean
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
#if(STD_ON == COM_RX_UPDATEBIT_SUPPORT)
STATIC FUNC(boolean, COM_CODE) Com_CheckSigUpdateBit
(
    PduIdType RxIpduId,
    Com_SignalIdType index
)
{
    boolean ret = FALSE;
    PduLengthType tempByteIndex = COM_CFG_RXPDU_UPDATEBIT_INFO(RxIpduId)[index].UpdateByteIndex;
    uint8 tempMaskValue = (uint8)(~(COM_CFG_RXPDU_UPDATEBIT_INFO(RxIpduId)[index].UpdateMaskValue));
    uint8 tempValue = ((uint8 *)COM_CFG_RXPDU_DATA_PTR_TEMP(RxIpduId))[tempByteIndex];

    /* update bit will only copied in temp rx buffer, it will not copy to real buffer*/
    if((uint8)0 != (uint8)(tempValue & tempMaskValue))
    {
        ret = TRUE;
    }
    return ret;

}
#endif



/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Com_InitRxOccOfPdu
*
* Description:   Init Rx signal's occ counter to 0, if configured
*
* Inputs:        sigId
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
#if((COM_RX_FILTER_SUPPORT == STD_ON) && (COM_MAX_FILTER_OCCURRENCE_NUM > 0))
STATIC FUNC(void, COM_CODE) Com_InitRxOccOfPdu
(
    PduIdType RxIpduId
)
{
    Com_SignalIdType SigIndex = (Com_SignalIdType)0;

    for(SigIndex = COM_CFG_RXPDU_SIG_START_NUM(RxIpduId); SigIndex <= COM_CFG_RXPDU_SIG_STOP_NUM(RxIpduId); SigIndex++)
    {
        if(NULL_PTR != COM_CFG_RXSIG_FILTER_PTR(SigIndex))
        {
            if(COM_INVALID_SIG_INDEX != COM_CFG_RXSIG_FILTER_PTR(SigIndex)->occIndex)
            {
                Com_Sig_Occurrence[COM_CFG_RXSIG_FILTER_PTR(SigIndex)->occIndex] = (uint16)0;
            }
        }
    }
}
#endif



/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Com_InitRxPduValue
*
* Description:   Init Rx Pdu values
*
* Inputs:        RxIpduId
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, COM_CODE) Com_InitRxPduValue
(
    PduIdType RxIpduId
)
{
    PduLengthType IndexData = (PduLengthType)0;
    Com_SignalIdType SigIndex = (Com_SignalIdType)0;

    /* Step 1 clear all byte to 0*/
    for(IndexData = (PduLengthType)0; IndexData < COM_CFG_RXPDU_LENGTH(RxIpduId); IndexData++)
    {
        ((uint8 *)COM_CFG_RXPDU_DATA_PTR(RxIpduId))[IndexData] = (uint8)0;
    }
    /* Step 2 init all signals of this pdu*/
    for(SigIndex = COM_CFG_RXPDU_SIG_START_NUM(RxIpduId); SigIndex <= COM_CFG_RXPDU_SIG_STOP_NUM(RxIpduId); SigIndex++)
    {
        Com_ReplaceRxSignalWithInit(RxIpduId, SigIndex, FALSE);
    }

}


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Com_InitRxPdu
*
* Description:   Init Rx Pdu Regs, called when Init only
*
* Inputs:         RxIpduId, isStartFlag,InitFlag
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/

STATIC FUNC(void, COM_CODE) Com_InitRxPdu
(
    PduIdType RxIpduId,
    boolean   isStartFlag
)
{




#if(STD_ON == COM_RX_LONG_PDU_FUN)
    COM_RXPDU_TP_INDEX(RxIpduId) = (PduLengthType)0;
#endif


    COM_RXPDU_TEMP_LENGTH(RxIpduId) = (PduLengthType)0;


    /* time out monitor Init*/
#if (STD_ON == COM_RX_TIMEOUT_MONITOR)
    COM_RXPDU_TIMEOUT(RxIpduId) = COM_TIMER_STOP_VAL;
#if (STD_ON == COM_RX_UPDATEBIT_SUPPORT)
    Com_ResetUpdateRxToTimer(RxIpduId);
#endif
    if(FALSE == isStartFlag)
    {
        COM_RXPDU_MONITOR_FLAG(RxIpduId) = FALSE;
    }
    else
    {
        COM_RXPDU_MONITOR_FLAG(RxIpduId) = COM_CFG_RXPDU_MONITOR_FLAG(RxIpduId);
    }
#endif

    /*Pdu Data Length Init*/
    Com_InitRxPduValue(RxIpduId);


    if(FALSE == isStartFlag)
    {
        Com_RxPduState[RxIpduId] = COM_RXPDU_STOP;/*SWS_Com_444 all group stop at Init*/
    }
    else
    {
        Com_RxPduState[RxIpduId] = COM_RXPDU_START_IDLE;/*SWS_Com_840*/
    }

}


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Com_SwitchRxPduMode
*
* Description:   Init Rx Pdu Regs When PduGroupMode Switch, called PduMode Switch
*
* Inputs:         RxIpduId, isStartFlag,InitFlag
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
#if(STD_ON == COM_IPDU_GROUP_FUN)
STATIC FUNC(void, COM_CODE) Com_SwitchRxPduMode
(
    PduIdType RxIpduId,
    boolean   isStartFlag,
    boolean   InitFlag
)
{
    COM_RXPDU_TEMP_LENGTH(RxIpduId) = (PduLengthType)0;

#if(STD_ON == COM_RX_LONG_PDU_FUN)
    COM_RXPDU_TP_INDEX(RxIpduId) = (PduLengthType)0;
#endif



    /*Pdu Data Length Init
      Start-> Stop keep payload data unchange
      Stop->start, decide by InitFlag SWS_Com_222
    */

    if((TRUE == isStartFlag) && (TRUE == InitFlag))
    {
        Com_InitRxPduValue(RxIpduId);
    }

#if((COM_RX_FILTER_SUPPORT == STD_ON) && (COM_MAX_FILTER_OCCURRENCE_NUM > 0))
    /* clear all occ signal's occ counter of this pdu */
    Com_InitRxOccOfPdu(RxIpduId);/*SWS_Com_00787-4*/
#endif



#if (STD_ON == COM_RX_TIMEOUT_MONITOR)
    COM_RXPDU_TIMEOUT(RxIpduId) = COM_TIMER_STOP_VAL;/*SWS_Com_00787-2*/

    if(FALSE == isStartFlag)/* SWS_Com_685 ,Start-> Stop, time monitor is disable*/
    {
        COM_RXPDU_MONITOR_FLAG(RxIpduId) = FALSE;
    }
    else
    {
        /*SWS_Com_787 stop->start, timer must be restart*/
        COM_RXPDU_MONITOR_FLAG(RxIpduId) = COM_CFG_RXPDU_MONITOR_FLAG(RxIpduId);
    }
#endif

    if(FALSE == isStartFlag)
    {
        Com_RxPduState[RxIpduId] = COM_RXPDU_STOP;
    }
    else
    {
        Com_RxPduState[RxIpduId] = COM_RXPDU_START_IDLE;/*SWS_Com_114*/
    }


}
#endif/* #if(STD_ON == COM_IPDU_GROUP_FUN)*/



/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Com_RxInit
*
* Description:   rx initialize.
*
* Inputs:         None
*
* Outputs:          None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, COM_CODE) Com_RxInit
(
    void
)
{

    PduIdType IpduIndex = (PduIdType)0;
#if (STD_ON == COM_GW_FUN)
    Com_SignalIdType Index = (Com_SignalIdType)0;
#endif

#if (STD_ON == COM_GW_FUN)
    for(Index = (Com_SignalIdType)0; Index < COM_GWSIG_NUM; Index++)
    {
        Com_GWSigFlag[Index] = FALSE;
    }
#endif

    for(IpduIndex = (PduIdType)0; IpduIndex < COM_RXPDU_NUM; IpduIndex++)
    {

#if (STD_ON == COM_IPDU_GROUP_FUN)
        if(TRUE == COM_CFG_RXPDUGROUP_FLAG(IpduIndex))
        {
            Com_InitRxPdu(IpduIndex, FALSE);
        }
        else
#endif
        {
            Com_InitRxPdu(IpduIndex, TRUE);
        }
    }

}




/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Com_ReplaceRxSignalWithInit
*
* Description:   replace signal with init value, called when init or rxsignal timeout
*
* Inputs:        sigId
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, COM_CODE) Com_ReplaceRxSignalWithInit
(
    PduIdType RxPduId,
    uint16 sigId,
    boolean needRoutOut
)
{
    PduLengthType sigLen = (PduLengthType)0;

    sigLen = COM_CFG_RXSIG_LENGTH(sigId);
#if (STD_ON == COM_RX_DYN_PDU_SUPPORT)
    if(COM_SIG_DYN == COM_CFG_RXSIG_TYPE(sigId))
    {
        sigLen = COM_CFG_RXSIG_INIT_VALUE_LEN(sigId);
        COM_RXPDU_DYN_LENGTH(RxPduId) = COM_CFG_RXSIG_START_BYTE_INDEX(sigId) + sigLen;
    }
#endif

    /* copy init value to real buffer*/
    COM_CFG_RXSIG_WRITE_SIG_FUN(sigId)(COM_CFG_RXSIG_INIT_VALUE_PTR(sigId), COM_CFG_RXPDU_DATA_PTR(RxPduId),  sigLen);
#if (STD_ON == COM_RX_SIGNAL_GROUP_SUPPORT)
    /* Also copy to shadow buffer*/
    if(NULL_PTR != COM_CFG_RXSIG_GROUP_TEMP_BUF(sigId))
    {
        COM_CFG_RXSIG_COPY_SIG_FUN(sigId)(COM_CFG_RXSIG_INIT_VALUE_PTR(sigId), COM_CFG_RXSIG_GROUP_TEMP_BUF(sigId), sigLen);
    }
#if (STD_ON == COM_RX_DYN_PDU_SUPPORT)
    if(NULL_PTR != COM_CFG_RXSIG_GROUP_TEMPLENGTH_PTR(sigId))
    {
        *COM_CFG_RXSIG_GROUP_TEMPLENGTH_PTR(sigId) = sigLen;
    }
#endif
#endif


#if (STD_ON == COM_GW_FUN)
    if(TRUE == needRoutOut)
    {
        /*if signal is rx ok, set GwFlag, GwFlag will only be cleared*/
        if(COM_INVALID_SIG_INDEX != COM_CFG_RXSIG_GW_INDEX(sigId))
        {
            Com_GWSigFlag[COM_CFG_RXSIG_GW_INDEX(sigId)] = TRUE;

        }
    }
#endif

}



#if (STD_ON == COM_RX_INVALID_SUPPORT)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Com_RxPduInvalid
*
* Description:   do all invalid action when rx pdu got following cases:
*                1.rxCallout return not ok
*                2.tp rx result is not ok
*
* Inputs:        RxPduId:
*                invalidFlag:tp packet result only
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, COM_CODE) Com_RxPduInvalid
(
    PduIdType RxPduId
)
{
    Com_SignalIdType signalIndex =  (Com_SignalIdType)0;
#if (STD_ON == COM_RX_SIGNAL_GROUP_SUPPORT)
    Com_SignalIdType grpSigIndex = (Com_SignalIdType)0;
    Com_SignalGroupIdType grpId = (Com_SignalGroupIdType)0;
#endif

    for(signalIndex = COM_CFG_RXPDU_SIG_START_NUM(RxPduId); signalIndex <= COM_CFG_RXPDU_SIG_STOP_NUM(RxPduId); signalIndex++)
    {
        if(COM_NOTIFY == COM_CFG_RXSIG_INVALID_ACTION(signalIndex))
        {
            COM_CFG_RXSIG_CBKINV_FUN(signalIndex)();
        }
        else if(COM_REPLACE == COM_CFG_RXSIG_INVALID_ACTION(signalIndex))
        {

#if (STD_ON == COM_RX_SIGNAL_GROUP_SUPPORT)
            if(TRUE == COM_CFG_RXSIG_IS_GROUP_SIGNAL(signalIndex))
            {
                grpId = COM_CFG_RXSIG_GET_SIGGROUPID(signalIndex);
                for(grpSigIndex = COM_CFG_RXSIGGRP_SIGSTART(grpId); grpSigIndex <= COM_CFG_RXSIGGRP_SIGSTOP(grpId); grpSigIndex++)
                {
                    Com_ReplaceRxSignalWithInit(RxPduId, grpSigIndex, TRUE);
                }
            }
            else
#endif
            {
                Com_ReplaceRxSignalWithInit(RxPduId, signalIndex, TRUE);
            }

        }
        else
        {
            /* do nothing*/
        }

#if (STD_ON == COM_RX_SIGNAL_GROUP_SUPPORT)
        if(TRUE == COM_CFG_RXSIG_IS_GROUP_SIGNAL(signalIndex))
        {
            grpId = COM_CFG_RXSIG_GET_SIGGROUPID(signalIndex);
            /* set sigId to the end of this group */
            signalIndex = COM_CFG_RXSIGGRP_SIGSTOP(grpId);
        }
#endif

    }
}
#endif


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Com_HandleRxPdu_DirectCopy
*
* Description:   rx process if directcopy rx pdu is received
*
* Inputs:        RxPduId:
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, COM_CODE) Com_HandleRxPdu_DirectCopy
(
    PduIdType RxPduId
)
{
    Com_SignalIdType RxSigId = (Com_SignalIdType)0;

    for(RxSigId = COM_CFG_RXPDU_SIG_START_NUM(RxPduId);
            RxSigId <= COM_CFG_RXPDU_SIG_STOP_NUM(RxPduId);
            RxSigId++)
    {
#if(STD_ON == COM_PADDING_SUPPORT)
        if(COM_CFG_RXSIG_MIN_BYTE(RxSigId) <= COM_RXPDU_TEMP_LENGTH(RxPduId))/* rx data length may be smaller than cfg length*/
#endif
        {
            /*if signal is rx ok, set GwFlag, GwFlag will only be cleared in mainfunctionR*/
#if (STD_ON == COM_GW_FUN)
            if(COM_INVALID_SIG_INDEX != COM_CFG_RXSIG_GW_INDEX(RxSigId))
            {
                Com_GWSigFlag[COM_CFG_RXSIG_GW_INDEX(RxSigId)] = TRUE;
            }
#endif
            if(NULL_PTR != COM_CFG_RXSIG_CBKRXACK_FUN(RxSigId))
            {
                COM_CFG_RXSIG_CBKRXACK_FUN(RxSigId)();/*SWS_Com_00574*/
            }
        }

    }
}


/*
 0-OK,
 1- NO UPDATED
 2- INVALID VALUE RX
 3- FILTER FAIL

*/
#if(STD_OFF == COM_RX_DIRECT_COPY)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Com_CheckRxSignalGroup_Invalid_Filter
*
* Description:   check all signals within a signal group
*
* Inputs:        RxPduId:
*
* Outputs:       uint8
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
#if (STD_ON == COM_RX_SIGNAL_GROUP_SUPPORT)
#if ((COM_RX_FILTER_SUPPORT == STD_ON) || (STD_ON == COM_RX_INVALID_SUPPORT))
STATIC FUNC(uint8, COM_CODE) Com_CheckRxSignalGroup_Invalid_Filter
(
    PduIdType RxPduId,
    Com_SignalGroupIdType SigGrpId
)
{
    uint8 ret = COM_RX_SIGNAL_OK;
    Com_SignalIdType signalIndex =  (Com_SignalIdType)0;


    if((TRUE == COM_CFG_RXSIGGRP_HAS_INVALID_VAL(SigGrpId)) || (TRUE == COM_CFG_RXSIGGRP_HAS_FILTER(SigGrpId)))
    {
        for(signalIndex = COM_CFG_RXSIGGRP_SIGSTART(SigGrpId); signalIndex <= COM_CFG_RXSIGGRP_SIGSTOP(SigGrpId);  signalIndex++)
        {
            if(NULL_PTR != COM_CFG_RXSIG_CHECK_SIG_FUN(signalIndex))
            {
                ret = COM_CFG_RXSIG_CHECK_SIG_FUN(signalIndex)(RxPduId, signalIndex, COM_CFG_RXSIG_FILTER_PTR(signalIndex));
                if(ret != COM_RX_SIGNAL_OK)
                {
                    break;
                }

            }
        }
    }

    return ret;
}
#endif

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Com_RxSignalGroup_ProcessAfterCheck
*
* Description:   process ack indication  after signal group check
*
* Inputs:        RxPduId, filterResult,RxSigId,SigGrpId
*
* Outputs:       uint8
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, COM_CODE) Com_RxSignalGroup_ProcessAfterCheck
(
    PduIdType RxPduId,
    uint8 filterResult,
    Com_SignalIdType RxSigId,
    Com_SignalGroupIdType SigGrpId
)
{
    Com_SignalIdType signalIndex =  (Com_SignalIdType)0;


    if(COM_RX_SIGNAL_OK == filterResult)
    {
        /* COPY RX DATA*/
        for(signalIndex = COM_CFG_RXSIGGRP_SIGSTART(SigGrpId); signalIndex <= COM_CFG_RXSIGGRP_SIGSTOP(SigGrpId);  signalIndex++)
        {
            COM_CFG_RXSIG_MOVE_FUN(signalIndex)();
#if (STD_ON == COM_RX_DYN_PDU_SUPPORT)
            if(COM_SIG_DYN == COM_CFG_RXSIG_TYPE(signalIndex))
            {
                COM_RXPDU_DYN_LENGTH(RxPduId) = COM_RXPDU_TEMP_LENGTH(RxPduId);
            }
#endif

#if (STD_ON == COM_GW_FUN)
            /*if signal is rx ok, set GwFlag, GwFlag will only be cleared*/
            if(COM_INVALID_SIG_INDEX != COM_CFG_RXSIG_GW_INDEX(signalIndex))
            {
                Com_GWSigFlag[COM_CFG_RXSIG_GW_INDEX(signalIndex)] = TRUE;
            }
#endif
        }

        if(NULL_PTR != COM_CFG_RXSIG_CBKRXACK_FUN(RxSigId))
        {
            COM_CFG_RXSIG_CBKRXACK_FUN(RxSigId)();/*SWS_Com_00574*/
        }

    }
#if (STD_ON == COM_RX_INVALID_SUPPORT)
    else if(COM_RX_SIGNAL_INVALD == filterResult)
    {
        if(COM_NOTIFY == COM_CFG_RXSIG_INVALID_ACTION(RxSigId))
        {
            COM_CFG_RXSIG_CBKINV_FUN(RxSigId)();
        }
        else if(COM_REPLACE == COM_CFG_RXSIG_INVALID_ACTION(RxSigId))
        {
            /* replace data*/
            for(signalIndex = COM_CFG_RXSIGGRP_SIGSTART(SigGrpId); signalIndex <= COM_CFG_RXSIGGRP_SIGSTOP(SigGrpId);  signalIndex++)
            {
                /* SWS_Com_00683*/
                Com_ReplaceRxSignalWithInit(RxPduId, signalIndex, TRUE);
            }
            if(NULL_PTR != COM_CFG_RXSIG_CBKRXACK_FUN(RxSigId))
            {
                COM_CFG_RXSIG_CBKRXACK_FUN(RxSigId)();/*SWS_Com_00683*/
            }
        }
        else
        {
            /* do nothing*/
        }

    }
#endif
    else
    {
        /* just ignor sgnal when rxfilter not pass */
    }



}
#endif

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Com_RxSignal_ProcessAfterCheck
*
* Description:   process ack indication  after signal check
*
* Inputs:        filterResult,RxSigId
*
* Outputs:       uint8
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/

STATIC FUNC(void, COM_CODE) Com_RxSignal_ProcessAfterCheck
(
    uint8 filterResult,
    PduIdType RxPduId,
    Com_SignalIdType RxSigId
)
{
    if(COM_RX_SIGNAL_OK == filterResult)
    {
        /* COPY RX DATA*/
        COM_CFG_RXSIG_MOVE_FUN(RxSigId)();

#if (STD_ON == COM_GW_FUN)
        /*if signal is rx ok, set GwFlag, GwFlag will only be cleared*/
        if(COM_INVALID_SIG_INDEX != COM_CFG_RXSIG_GW_INDEX(RxSigId))
        {
            Com_GWSigFlag[COM_CFG_RXSIG_GW_INDEX(RxSigId)] = TRUE;
        }
#endif

#if (STD_ON == COM_RX_DYN_PDU_SUPPORT)
        if(COM_SIG_DYN == COM_CFG_RXSIG_TYPE(RxSigId))
        {
            COM_RXPDU_DYN_LENGTH(RxPduId) = COM_RXPDU_TEMP_LENGTH(RxPduId);
        }
#endif

        if(NULL_PTR != COM_CFG_RXSIG_CBKRXACK_FUN(RxSigId))
        {
            COM_CFG_RXSIG_CBKRXACK_FUN(RxSigId)();/*SWS_Com_00574*/
        }



    }
#if (STD_ON == COM_RX_INVALID_SUPPORT)
    else if(COM_RX_SIGNAL_INVALD == filterResult)
    {
        if(COM_NOTIFY == COM_CFG_RXSIG_INVALID_ACTION(RxSigId))
        {
            COM_CFG_RXSIG_CBKINV_FUN(RxSigId)();
        }
        else if(COM_REPLACE == COM_CFG_RXSIG_INVALID_ACTION(RxSigId))
        {
            /* replace data with Init SWS_COM_00681*/
            Com_ReplaceRxSignalWithInit(RxPduId, RxSigId, TRUE);

            if(NULL_PTR != COM_CFG_RXSIG_CBKRXACK_FUN(RxSigId))
            {
                COM_CFG_RXSIG_CBKRXACK_FUN(RxSigId)();
            }
        }
        else
        {
            /* do nothing*/
        }

    }
#endif
    else
    {
        /* just ignor sgnal when rxfilter not pass */
    }

}


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Com_HandleRxPdu
*
* Description:   rx indication when rx Ipdu.
*
* Inputs:        RxPduId:
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, COM_CODE) Com_HandleRxPdu
(
    PduIdType RxPduId
)
{
    Com_SignalIdType RxSigId = COM_CFG_RXPDU_SIG_START_NUM(RxPduId);
    uint8 filterResult = (uint8)0;


#if(COM_RX_UPDATEBIT_SUPPORT == STD_ON)
    boolean updateflag = TRUE;
#endif


    while(RxSigId <= COM_CFG_RXPDU_SIG_STOP_NUM(RxPduId))
    {
        filterResult = COM_RX_SIGNAL_OK;
#if(STD_ON == COM_PADDING_SUPPORT)
        if(COM_CFG_RXSIG_MIN_BYTE(RxSigId) <= COM_RXPDU_TEMP_LENGTH(RxPduId))/* rx data length may be smaller than cfg length*/
#endif
        {
#if(COM_RX_UPDATEBIT_SUPPORT == STD_ON)
            updateflag = TRUE;
            /* set update bit if configured*/
            if(COM_INVALID_SIG_INDEX != COM_CFG_RXSIG_UPDATEBIT_INDEX(RxSigId))
            {
                if(FALSE == Com_CheckSigUpdateBit(RxPduId, COM_CFG_RXSIG_UPDATEBIT_INDEX(RxSigId)))
                {
                    updateflag = FALSE;
#if(COM_RX_SIGNAL_GROUP_SUPPORT == STD_ON)
                    if(TRUE == COM_CFG_RXSIG_IS_GROUP_SIGNAL(RxSigId))
                    {
                        RxSigId = COM_CFG_RXSIGGRP_SIGSTOP(COM_CFG_RXSIG_GET_SIGGROUPID(RxSigId));
                    }
#endif
                }
#if(COM_RX_TIMEOUT_MONITOR == STD_ON)
                else
                {
                    
                    if((COM_INVALID_SIG_INDEX != COM_CFG_RXSIG_UPTO_INDEX(RxSigId))
                            && (COM_TIMER_STOP_VAL != Com_UpdateTimeoutCnt[COM_CFG_RXSIG_UPTO_INDEX(RxSigId)]))
                    {
                        /* reset signal rx timeout timer*/
                        Com_UpdateTimeoutCnt[COM_CFG_RXSIG_UPTO_INDEX(RxSigId)] = COM_CFG_RXSIG_UPTO_PERIOD(RxSigId);
                    }
                }
#endif
            }
            if(TRUE == updateflag)
#endif
            {
                /* reset timerout first */
#if(COM_RX_SIGNAL_GROUP_SUPPORT == STD_ON)
                if(TRUE == COM_CFG_RXSIG_IS_GROUP_SIGNAL(RxSigId))
                {
#if ((COM_RX_FILTER_SUPPORT == STD_ON) || (STD_ON == COM_RX_INVALID_SUPPORT))
                    filterResult = Com_CheckRxSignalGroup_Invalid_Filter(RxPduId, COM_CFG_RXSIG_GET_SIGGROUPID(RxSigId));
#endif
                    Com_RxSignalGroup_ProcessAfterCheck(RxPduId, filterResult, RxSigId, COM_CFG_RXSIG_GET_SIGGROUPID(RxSigId));
                    RxSigId = COM_CFG_RXSIGGRP_SIGSTOP(COM_CFG_RXSIG_GET_SIGGROUPID(RxSigId));
                }
                else
#endif
                {
#if ((COM_RX_FILTER_SUPPORT == STD_ON) || (STD_ON == COM_RX_INVALID_SUPPORT))
                    if(NULL_PTR != COM_CFG_RXSIG_CHECK_SIG_FUN(RxSigId))
                    {
                        filterResult = COM_CFG_RXSIG_CHECK_SIG_FUN(RxSigId)(RxPduId, RxSigId, COM_CFG_RXSIG_FILTER_PTR(RxSigId));
                    }
#endif
                    Com_RxSignal_ProcessAfterCheck(filterResult, RxPduId, RxSigId);
                }
            }
        }
        RxSigId++;
    }



}
#endif/*#if(STD_OFF == COM_RX_DIRECT_COPY)*/

#if(STD_ON == COM_RX_TIMEOUT_MONITOR)
/* BEGIN_FUNCTION_HDR
*******************************************************************************
* Function Name: Com_ResetUpdateRxToTimer
*
* Description:   stop  timeout of signals with update bit, when DM is disabled or pdu is stopped
*
* Inputs:        RxIpduId
*
* Outputs:       None
*
* Limitations:   None
*******************************************************************************
END_FUNCTION_HDR*/
#if(STD_ON == COM_RX_UPDATEBIT_SUPPORT)
STATIC FUNC(void, COM_CODE) Com_ResetUpdateRxToTimer
(
    PduIdType RxIpduId
)
{
    Com_SignalIdType RxSigId = (Com_SignalIdType)0;
    Com_SignalIdType RxIndex = (Com_SignalIdType)0;
    uint16 upIndex = (uint16)0;


    if(COM_CFG_RXPDU_UPDATEBIT_NUM(RxIpduId) > (Com_SignalIdType)0)
    {
        for(RxIndex = (Com_SignalIdType)0; RxIndex < COM_CFG_RXPDU_UPDATEBIT_NUM(RxIpduId); RxIndex++)
        {
            RxSigId = COM_CFG_RXPDU_UPDATEBIT_INFO(RxIpduId)[RxIndex].updateSignalId;

            upIndex = COM_CFG_RXSIG_UPTO_INDEX(RxSigId);

            Com_UpdateTimeoutCnt[upIndex] = COM_TIMER_STOP_VAL;
        }
    }


}


/* BEGIN_FUNCTION_HDR
*******************************************************************************
* Function Name: Com_UpdateRxTimerOutMonitor
*
* Description:   process rx timeout of signals with update bit
*
* Inputs:        RxIpduId
*
* Outputs:       None
*
* Limitations:   None
*******************************************************************************
END_FUNCTION_HDR*/

STATIC FUNC(void, COM_CODE) Com_UpdateRxTimerOutMonitor
(
    PduIdType RxIpduId
)
{
    Com_SignalIdType RxSigId = (Com_SignalIdType)0;
    Com_SignalIdType RxIndex = (Com_SignalIdType)0;
    uint16 upIndex = (uint16)0;
#if(STD_ON == COM_RX_SIGNAL_GROUP_SUPPORT)
    Com_SignalIdType grpSignalIndex = (Com_SignalIdType)0;
    Com_SignalGroupIdType SigGrpId = (Com_SignalGroupIdType)0;
#endif



    if(COM_CFG_RXPDU_UPDATEBIT_NUM(RxIpduId) > (Com_SignalIdType)0)
    {
        for(RxIndex = (Com_SignalIdType)0; RxIndex < COM_CFG_RXPDU_UPDATEBIT_NUM(RxIpduId); RxIndex++)
        {
            RxSigId = COM_CFG_RXPDU_UPDATEBIT_INFO(RxIpduId)[RxIndex].updateSignalId;

            upIndex = COM_CFG_RXSIG_UPTO_INDEX(RxSigId);
            if((uint16)0 != COM_CFG_RXSIG_UPTO_PERIOD(RxSigId))/* may be no timeout */
            {
                if(COM_TIMER_STOP_VAL == Com_UpdateTimeoutCnt[upIndex])
                {
                    Com_UpdateTimeoutCnt[upIndex] = COM_CFG_RXSIG_UPTO_FIRSTPERIOD(RxSigId);
                }

                if((uint16)0 != Com_UpdateTimeoutCnt[upIndex])
                {
                    Com_UpdateTimeoutCnt[upIndex]--;
                }
                if((uint16)0 == Com_UpdateTimeoutCnt[upIndex])
                {
                    Com_UpdateTimeoutCnt[upIndex] = COM_CFG_RXSIG_UPTO_PERIOD(RxSigId);

                    if(TRUE == COM_CFG_RXSIG_TO_REPLACE(RxSigId))
                    {
#if(STD_ON == COM_RX_SIGNAL_GROUP_SUPPORT)
                        if(TRUE == COM_CFG_RXSIG_IS_GROUP_SIGNAL(RxSigId))
                        {
                            SigGrpId = COM_CFG_RXSIG_GET_SIGGROUPID(RxSigId);
                            for(grpSignalIndex = COM_CFG_RXSIGGRP_SIGSTART(SigGrpId); grpSignalIndex <= COM_CFG_RXSIGGRP_SIGSTOP(SigGrpId);  grpSignalIndex++)
                            {
                                Com_ReplaceRxSignalWithInit(RxIpduId, grpSignalIndex, TRUE);
                            }
                        }
                        else
#endif
                        {
                            Com_ReplaceRxSignalWithInit(RxIpduId, RxSigId, TRUE);

                        }
                    }

                    if(NULL_PTR != COM_CFG_RXSIG_CBKRXTOUT_FUN(RxSigId))
                    {
                        COM_CFG_RXSIG_CBKRXTOUT_FUN(RxSigId)();
                    }
                }
            }
        }
    }
}
#endif



/* BEGIN_FUNCTION_HDR
*******************************************************************************
* Function Name: Com_RxTimerOutMonitor
*
* Description:   process rx timeout
*
* Inputs:        RxIpduId
*
* Outputs:       None
*
* Limitations:   None
*******************************************************************************
END_FUNCTION_HDR*/

STATIC FUNC(void, COM_CODE) Com_RxTimerOutMonitor
(
    PduIdType RxIpduId
)
{

    Com_SignalIdType RxSigId = (Com_SignalIdType)0;
#if(STD_ON == COM_RX_UPDATEBIT_SUPPORT)
#if(STD_ON == COM_RX_SIGNAL_GROUP_SUPPORT)
    Com_SignalGroupIdType grpId = (Com_SignalGroupIdType)0;
#endif
#endif

    if(COM_TIMER_STOP_VAL == COM_RXPDU_TIMEOUT(RxIpduId))
    {
        COM_RXPDU_TIMEOUT(RxIpduId) =
            COM_CFG_RXPDU_FIRST_TIMEOUT(RxIpduId);/* First time start*/
    }
    if((uint16)0 != COM_RXPDU_TIMEOUT(RxIpduId))
    {
        COM_RXPDU_TIMEOUT(RxIpduId)--;
    }
    else
    {
        COM_RXPDU_TIMEOUT(RxIpduId) =
            COM_CFG_RXPDU_PERIOD_TIMEOUT(RxIpduId);
        COM_RXPDU_TIMEOUT(RxIpduId)--;

        /* SWS_Com_00290 291 all signal timeout is monitor by pdu*/
        for(RxSigId = COM_CFG_RXPDU_SIG_START_NUM(RxIpduId);
                RxSigId <= COM_CFG_RXPDU_SIG_STOP_NUM(RxIpduId);
                RxSigId++)
        {
            /*SWS_Com_00744 first ComRxDataTimeoutAction then ComTimeoutNotification*/
            /* can not copy all pdu's init value, as some sig may be configed not replace*/

#if(STD_ON == COM_RX_UPDATEBIT_SUPPORT)
            if(COM_INVALID_SIG_INDEX == COM_CFG_RXSIG_UPTO_INDEX(RxSigId))
#endif
            {
                /* replace attibute will generated for all signal of group ,  not only for the first signal,
                   so no need to replace all group signal here
                */
                if(TRUE == COM_CFG_RXSIG_TO_REPLACE(RxSigId))
                {
                    Com_ReplaceRxSignalWithInit(RxIpduId, RxSigId, TRUE);
                }

                /*SWS_Com_00470 500 513*/
                if(NULL_PTR != COM_CFG_RXSIG_CBKRXTOUT_FUN(RxSigId))
                {
                    COM_CFG_RXSIG_CBKRXTOUT_FUN(RxSigId)();
                }

            }
#if(STD_ON == COM_RX_UPDATEBIT_SUPPORT)
			else
			{
			    /* has updatebit and this is signal group , jump all groupsiganl*/
#if(STD_ON == COM_RX_SIGNAL_GROUP_SUPPORT)
				if(TRUE == COM_CFG_RXSIG_IS_GROUP_SIGNAL(RxSigId))
				{
					grpId = COM_CFG_RXSIG_GET_SIGGROUPID(RxSigId);
					RxSigId = COM_CFG_RXSIGGRP_SIGSTOP(grpId);/* set sigId to the end of this group */
				}
#endif
			}
#endif

        }

        /* time out reset */
        Com_RxPduState[RxIpduId] = COM_RXPDU_START_IDLE;
        COM_RXPDU_TEMP_LENGTH(RxIpduId) = (PduLengthType)0;
#if(STD_ON == COM_RX_LONG_PDU_FUN)
        COM_RXPDU_TP_INDEX(RxIpduId) = (PduLengthType)0;
#endif
    }

}
#endif



#endif/*#if(STD_ON == COM_RXPDU_FUN)*/


/*******************************************************************************
*   Api Used by generate file
*******************************************************************************/

#if(STD_ON == COM_TX_FILTER_SUPPORT)
/* BEGIN_FUNCTION_HDR
*******************************************************************************
* Function Name: Com_TxSignalFilter
*
* Description:   only called when tx signal's value updated, this funtion only
*                caculate single signal's filter result, the whole Pdu result will
*                be caculated in mainfunction tx
* Inputs:        ComTxSigId, ComSigValuePtr
*
* Outputs:       None
*
* Limitations:   None
*******************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, COM_CODE) Com_TxSignalFilter
(
    Com_SignalIdType  ComTxSigId,
    P2CONST(void, AUTOMATIC, AUTOMATIC) value
)
{

    PduIdType TxIpduId = (PduIdType)0;
    uint16 TxSigSetBitNum = (uint16)0;
    boolean TxSigFilterResult = TRUE;
    uint8 Position_Bit = (uint8)0;
    uint16 Position_Byte = (uint16)0;
    P2CONST(Com_CfgSigFilterParsType, AUTOMATIC, COM_CONST) algPtr = COM_CFG_TXSIG_FILTER_PTR(ComTxSigId);
    uint8 tempByte = (uint8)0;

    if(NULL_PTR != COM_CFG_TXSIG_CHECK_FILTER(ComTxSigId))
    {

        TxIpduId = COM_CFG_TXSIG_TXPDU_ID(ComTxSigId);
        TxSigFilterResult = COM_CFG_TXSIG_CHECK_FILTER(ComTxSigId)(TxIpduId, ComTxSigId, value, algPtr);


        TxSigSetBitNum = ComTxSigId - COM_CFG_TXPDU_SIG_START_NUM(TxIpduId);
        Position_Byte = (TxSigSetBitNum >> COM_GET_BYTEINX_SHIFT_VALUE);
        Position_Bit = (uint8)(TxSigSetBitNum % COM_GET_BITPOS_RES_VALUE);
        tempByte = (uint8)(((uint8)1) << Position_Bit);

        if(TRUE != TxSigFilterResult)
        {
            tempByte = (uint8)~tempByte;
            COM_CFG_TXPDU_FILTER_PTR(TxIpduId)[Position_Byte] &= tempByte;
        }
        else
        {

            COM_CFG_TXPDU_FILTER_PTR(TxIpduId)[Position_Byte] |= tempByte;
        }

        Com_SendSwitchTxModeFlag[TxIpduId] = COM_TXMODE_SWITCH_SEND_SIGNAL;
    }

}
#endif/*#if(STD_ON == COM_TX_FILTER_SUPPORT)*/

#if(STD_ON == COM_TXPDU_FUN)
#if(STD_OFF == COM_TXMODE_PERIODIC_ONLY)
/* BEGIN_FUNCTION_HDR
*******************************************************************************
* Function Name: Com_SetIpduTrigRepFlag
*
* Description:   only called when tx signal's value updated, this funtion only
*                set trigger and reptition flag, the flag will
*                be caculated in mainfunction tx
*
* Inputs:        None
*
* Outputs:       None
*
* Limitations:   None
*******************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, COM_CODE) Com_SetIpduTrigRepFlag
(
    Com_SignalTxPropertyType txProperty,
    PduIdType TxIpduId,
    boolean changeFlag
)
{
    switch(txProperty)
    {
#if(STD_ON == COM_TXMODE_REPTITION)
    case COM_TRIGGERED:
        /*This is not possible to confirm the txmodeof the message, which must be confirmed after aaa and then determine the BBB*/
        Com_PDUTrigRepFlag[TxIpduId] = COM_TRIGGER_REP;
        break;

    case COM_TRIGGERED_ON_CHANGE:
        if(TRUE == changeFlag)
        {
            Com_PDUTrigRepFlag[TxIpduId] = COM_TRIGGER_REP;
        }
        break;
#endif

    case COM_TRIGGERED_WITHOUT_REPETITION:
        Com_PDUTrigRepFlag[TxIpduId] = COM_TRIGGER;
        break;

    case COM_TRIGGERED_ON_CHANGE_WITHOUT_REPETITION:
        if(TRUE == changeFlag)
        {
            Com_PDUTrigRepFlag[TxIpduId] = COM_TRIGGER;
        }
        break;

    default:
        /* pending do nothing*/
        break;


    }

}
#endif/*#if(STD_OFF == COM_TXMODE_PERIODIC_ONLY)*/
#endif/*#if(STD_ON == COM_TXPDU_FUN)*/


/*******************************************************************************
*   Asr Stabdard Api
*******************************************************************************/


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Com_Init SWS_Com_432
*
* Description:   tx/rx initialize.  SWS_Com_128
*
* Inputs:        ConfigPtr
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, COM_CODE) Com_Init
(
    P2CONST(Com_ConfigType, AUTOMATIC, COM_CONST) ConfigPtr
)
{
#if (COM_MAX_FILTER_OCCURRENCE_NUM > 0)
    Com_SignalIdType Index = (Com_SignalIdType)0;
#endif

#if (STD_ON == COM_IPDU_GROUP_FUN)    
    Com_IpduGroupIdType grpIdx = (Com_IpduGroupIdType)0;
#endif

#if(COM_CONFIG_VARIANTS == STD_CONFIG_VARIANTS_POSTBUILD)
    if(NULL_PTR == ConfigPtr)
    {
        COM_DET_REPORT_ERROR(COMServiceId_Init, COM_E_PARAM_POINTER);
    }
    else
#endif
    {
#if(COM_CONFIG_VARIANTS == STD_CONFIG_VARIANTS_POSTBUILD)
        Com_PBConfig = ConfigPtr;
        (void)Com_PBConfig;
#else
        (void)ConfigPtr;
#endif

#if (STD_ON == COM_RXPDU_FUN)
        Com_RxInit();
#endif

#if (STD_ON == COM_TXPDU_FUN)
        Com_TxInit();
#endif

#if (STD_ON == COM_IPDU_GROUP_FUN)      
        for(grpIdx = 0; grpIdx < (Com_IpduGroupIdType)COM_PDUGROUP_MAX_NUM; grpIdx++)
        {
            Com_IpduGroupStartFlag[grpIdx] = FALSE;
        }
        
#endif

#if (STD_ON == COM_RX_TIMEOUT_MONITOR)      
        for(grpIdx = 0; grpIdx < (Com_IpduGroupIdType)COM_PDUGROUP_MAX_NUM; grpIdx++)
        {
            Com_IpduGroupDMEnableFlag[grpIdx] = TRUE;
        }
        
#endif

#if (COM_MAX_FILTER_OCCURRENCE_NUM > 0)
        /* Occurrence is only used in config file, so there is no offset index reg for pdu*/
        for(Index = (uint16)0; Index < (uint16)COM_MAX_FILTER_OCCURRENCE_NUM; Index++)
        {
            Com_Sig_Occurrence[Index] = (uint16)0;
        }
#endif
        Com_InitStateFlag = COM_INIT;

    }

}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Com_DeInit SWS_Com_130
*
* Description:   tx/rx Deinitialize.
*
* Inputs:        None
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, COM_CODE) Com_DeInit
(
    void
)
{

    PduIdType IpduIndex = (PduIdType)0;/* sigID PduId will not exceed u16*/
#if (COM_MAX_FILTER_OCCURRENCE_NUM > 0)
    Com_SignalIdType Index = (Com_SignalIdType)0;
#endif


#if (STD_ON == COM_GW_FUN)
    for(IpduIndex = (PduIdType)0; IpduIndex < (PduIdType)COM_GWSIG_MAX_NUM; IpduIndex++)
    {
        Com_GWSigFlag[IpduIndex] = FALSE;
    }
#endif

    /*SWS_Com_129*/
#if (COM_RXPDU_MAX_NUM > 0)
    for(IpduIndex = (PduIdType)0; IpduIndex < COM_RXPDU_NUM; IpduIndex++)
    {
        Com_InitRxPdu(IpduIndex, FALSE);
    }
#endif

#if (COM_TXPDU_MAX_NUM > 0)
    for(IpduIndex = (PduIdType)0; IpduIndex < COM_TXPDU_NUM; IpduIndex++)
    {
        Com_InitTxPdu(IpduIndex, FALSE);
    }
#endif


#if (COM_MAX_FILTER_OCCURRENCE_NUM > 0)
    /* Occurrence is only used in config file, so there is no offset index reg for pdu*/
    for(Index = (uint16)0; Index < (uint16)COM_MAX_FILTER_OCCURRENCE_NUM; Index++)
    {
        Com_Sig_Occurrence[Index] = (uint16)0;
    }
#endif


    Com_InitStateFlag = COM_UNINIT;
}


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Com_GetStatus SWS_Com_00194
*
* Description:   Get If Com is Init
*
* Inputs:        None
*
* Outputs:       Com_StatusType
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Com_StatusType, COM_CODE) Com_GetStatus
(
    void
)
{
    return Com_InitStateFlag;
}



/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Com_SendSignal SWS_Com_00197
*
* Description:   This service updates the signal object identified by
*                SignalId with the signal referenced by the SignalDataPtr
*                parameter
*
* Inputs:        SignalId: Signal handle
*                SignalDataPtr: Reference to the Signal data to be transmitted
*
* Outputs:       E_OK:                      service has been accepted
*                COM_SERVICE_NOT_AVAILABLE: corresponding I-PDU group was
*                                           stopped
*                COM_BUSY:                  in case the TP-Buffer is lock for
                                            large data type handling
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(uint8, COM_CODE) Com_SendSignal
(
    Com_SignalIdType SignalId,
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
    uint8 result = COM_SERVICE_NOT_AVAILABLE;
#if(STD_ON == COM_TXPDU_FUN)
    if(COM_INIT != Com_InitStateFlag)
    {
        COM_DET_REPORT_ERROR(COMServiceId_SendSignal, COM_E_UNINIT);
    }
    else if(SignalId >= COM_TXSIG_NUM)
    {
        COM_DET_REPORT_ERROR(COMServiceId_SendSignal, COM_E_PARAM);
    }
    else if(COM_SIG_DYN == COM_CFG_TXSIG_TYPE(SignalId))
    {
        COM_DET_REPORT_ERROR(COMServiceId_SendSignal, COM_E_PARAM);
    }
    else if(NULL_PTR == SignalDataPtr)
    {
        COM_DET_REPORT_ERROR(COMServiceId_SendSignal, COM_E_PARAM_POINTER);
    }
    else
    {
        SchM_Enter_Com_COM_EXCLUSIVE_AREA_0();
        result = Com_WriteSignal_Internal(SignalId, SignalDataPtr, COM_CFG_TXSIG_LENGTH(SignalId));
        SchM_Exit_Com_COM_EXCLUSIVE_AREA_0();

    }
#endif/*#if(STD_ON == COM_TXPDU_FUN)*/


    return  result;

}


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Com_InvalidateSignal  SWS_Com_00203
*
* Description:   This service copies the invalid data of signal identified by CFG
*
* Inputs:        SignalId: ignal handle
*
* Outputs:       E_OK
*                COM_SERVICE_NOT_AVAILABLE
*                COM_BUSY
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(uint8, COM_CODE) Com_InvalidateSignal
(
    Com_SignalIdType SignalId
)
{
    uint8 result = COM_SERVICE_NOT_AVAILABLE;
#if((STD_ON == COM_TXPDU_FUN) && (STD_ON == COM_TX_INVALID_SUPPORT))
    PduLengthType length = (PduLengthType)0;
#endif

#if((STD_ON == COM_TXPDU_FUN) && (STD_ON == COM_TX_INVALID_SUPPORT))
    if(COM_INIT != Com_InitStateFlag)
    {
        COM_DET_REPORT_ERROR(COMServiceId_InvalidateSignal, COM_E_UNINIT);
    }
    else if(SignalId >= COM_TXSIG_NUM)
    {
        COM_DET_REPORT_ERROR(COMServiceId_InvalidateSignal, COM_E_PARAM);
    }
    else if(NULL_PTR == COM_CFG_TXSIG_INVALID_VALUE_PTR(SignalId))
    {
        COM_DET_REPORT_ERROR(COMServiceId_InvalidateSignal, COM_E_PARAM);
    }
#if(STD_ON == COM_TX_SIGNAL_GROUP_SUPPORT)
    /* in this version, only invalidateSignalGrp is allowed*/
    else if(TRUE == COM_CFG_TXSIG_IS_GROUP_SIGNAL(SignalId))
    {
        COM_DET_REPORT_ERROR(COMServiceId_InvalidateSignal, COM_E_PARAM);
    }
#endif
    else
    {
        length = COM_CFG_TXSIG_LENGTH(SignalId);
#if(STD_ON == COM_TX_DYN_PDU_SUPPORT)
        if(COM_SIG_DYN == COM_CFG_TXSIG_TYPE(SignalId))
        {
            length = COM_CFG_TXSIG_INVALID_VALUE_LEN(SignalId);
        }
#endif
        SchM_Enter_Com_COM_EXCLUSIVE_AREA_0();
        result = Com_WriteSignal_Internal(SignalId, COM_CFG_TXSIG_INVALID_VALUE_PTR(SignalId), length);
        SchM_Exit_Com_COM_EXCLUSIVE_AREA_0();
    }
#endif/*#if((STD_ON == COM_TXPDU_FUN) && (STD_ON == COM_TX_INVALID_SUPPORT))*/

    return    result;

}



/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Com_SendDynSignal  SWS_Com_00627
*
* Description:   This service updates the signal object identified by
*                SignalId with the signal referenced by the SignalDataPtr
*                parameter
*
* Inputs:        SignalId: Signal handle
*                SignalDataPtr: Reference to the Signal data to be transmitted
*                Length: Dyn-Signal length
*
* Outputs:       E_OK
*                COM_SERVICE_NOT_AVAILABLE
*                COM_BUSY
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(uint8, COM_CODE) Com_SendDynSignal
(
    Com_SignalIdType SignalId,
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr,
    uint16 Length
)
{
    uint8 result = COM_SERVICE_NOT_AVAILABLE;

    if(COM_INIT != Com_InitStateFlag)
    {
        COM_DET_REPORT_ERROR(COMServiceId_SendDynSignal, COM_E_UNINIT);
    }
#if(STD_ON == COM_TX_DYN_PDU_SUPPORT)
    else if((SignalId >= COM_TXSIG_NUM)
            || (COM_SIG_DYN != COM_CFG_TXSIG_TYPE(SignalId)))
    {
        COM_DET_REPORT_ERROR(COMServiceId_SendDynSignal, COM_E_PARAM);
    }
    else if(NULL_PTR == SignalDataPtr)
    {
        COM_DET_REPORT_ERROR(COMServiceId_SendDynSignal, COM_E_PARAM_POINTER);
    }
    else
    {
        /* SWS_Com_00334, signal can be updated when pdu is stop
           in stop mode, tms result, txmode and data will be saved
           but trigger will not be saved,
           so that the msg will not be send at once when pdu is started
        */
        if(Length > COM_CFG_TXSIG_LENGTH(SignalId))
        {
            COM_DET_REPORT_ERROR(COMServiceId_SendDynSignal, COM_E_PARAM);
            result = E_NOT_OK;
        }
        else
        {

            SchM_Enter_Com_COM_EXCLUSIVE_AREA_0();
            result = Com_WriteSignal_Internal(SignalId, SignalDataPtr, Length);
            SchM_Exit_Com_COM_EXCLUSIVE_AREA_0();
        }
    }
#else
    else
    {
        COM_DET_REPORT_ERROR(COMServiceId_SendDynSignal, COM_E_PARAM);
    }
#endif/*#if(STD_ON == COM_TX_DYN_PDU_SUPPORT)*/



    return  result;

}


/* BEGIN_FUNCTION_HDR
*******************************************************************************
* Function Name: Com_TxConfirmation SWS_Com_00124
*
* Description:   tx confirmation when transmit successful.
*
* Inputs:        TxPduId
*
* Outputs:       None
*
* Limitations:   None
*******************************************************************************
END_FUNCTION_HDR*/
FUNC(void, COM_CODE) Com_TxConfirmation
(
    PduIdType TxPduId
)
{

    if(COM_INIT != Com_InitStateFlag)
    {
        COM_DET_REPORT_ERROR(COMServiceId_TxConfirmation, COM_E_UNINIT);
    }
#if(STD_ON == COM_TXPDU_FUN)
    else if(TxPduId >= COM_TXPDU_NUM)
    {
        COM_DET_REPORT_ERROR(COMServiceId_TxConfirmation, COM_E_PARAM);
    }
    else if(TRUE == COM_CFG_TXPDU_IS_TP_PDU(TxPduId))
    {
        COM_DET_REPORT_ERROR(COMServiceId_TxConfirmation, COM_E_PARAM);
    }
    else
    {
        /* None type Pdu like Lin Pdu, is controlled by other module like linif,
           but com may need to monitor timeout with this txconfirmation ,
           also need to call rte_TxAck to uplayer module*/
        /*SWS_Com_00800 STOP Pdu ignor txConf*/
        if((COM_TXPDU_START_BUSY == Com_TxPduState[TxPduId]) || (COM_TXPDU_TXMODE(TxPduId) == COM_PDU_NONE))
        {
            SchM_Enter_Com_COM_EXCLUSIVE_AREA_0();

            if(TRUE == COM_CFG_TXPDU_IS_IMM_PROCESSING(TxPduId))
            {
                /* switch IDLE in this fucntion as nothinf need to do in mainfuntionTx*/
                Com_ProcessTxConf(TxPduId, COM_TXPDU_START_TXOK);
            }
            else
            {
                /* set to OK, process will be done in mainfuntionTx*/
                Com_TxPduState[TxPduId] = COM_TXPDU_START_TXOK;
            }

#if(COM_TX_UPDATEBIT_SUPPORT == STD_ON)
            if(COM_CUB_CONF == COM_CFG_TXPDU_UPDATEBIT_CLEARTYPE(TxPduId))
            {
                Com_ClearUpdateBit(TxPduId);
            }
#endif

#if(STD_ON == COM_MDT_CYCLIC_TRANSMISSION)/*SWS_Com_00469, reset min delay timer when txConf is received*/
            if((COM_TXPDU_TXMODE(TxPduId) != COM_PDU_NONE)
                    && (COM_CFG_TXPDU_MIN_DELAY_TIMER(TxPduId) > (uint16)0)
                    && (COM_TXPDU_MIN_DELAY_TIMER(TxPduId) != (uint16)0)
                    && (COM_TXPDU_MIN_DELAY_TIMER(TxPduId) != COM_TIMER_STOP_VAL))
            {
                /* no MDT for NONE pdu*/
                COM_TXPDU_MIN_DELAY_TIMER(TxPduId) = COM_CFG_TXPDU_MIN_DELAY_TIMER(TxPduId);
            }
#endif
            SchM_Exit_Com_COM_EXCLUSIVE_AREA_0();
        }
    }

#endif/*#if(STD_ON == COM_TXPDU_FUN)*/
}


/* BEGIN_FUNCTION_HDR
*******************************************************************************
* Function Name: Com_MainFunctionTx SWS_Com_00399
*
* Description:    process tx msg of com
*
* Inputs:        None
*
* Outputs:       None
*
* Limitations:   None
*******************************************************************************
END_FUNCTION_HDR*/
FUNC(void, COM_CODE) Com_MainFunctionTx
(
    void
)
{
#if(STD_ON == COM_TXPDU_FUN)
    PduIdType TxIpduId = (PduIdType)0;
    boolean sendFlag = FALSE;
#endif

    if(COM_INIT != Com_InitStateFlag) /*SWS_Com_00665*/
    {
        COM_DET_REPORT_ERROR(COMServiceId_MainFunctionTx, COM_E_UNINIT);
    }
#if(STD_ON == COM_TXPDU_FUN)
    else
    {
        for(TxIpduId = (PduIdType)0; TxIpduId < COM_TXPDU_NUM; TxIpduId++)
        {
            if(COM_TXPDU_STOP != Com_TxPduState[TxIpduId])
            {
                SchM_Enter_Com_COM_EXCLUSIVE_AREA_0();

                if(Com_TxPduState[TxIpduId] >= COM_TXPDU_START_TXOK)
                {
                    if(FALSE == COM_CFG_TXPDU_IS_IMM_PROCESSING(TxIpduId))
                    {
                        Com_ProcessTxConf(TxIpduId, Com_TxPduState[TxIpduId]);
                    }
                }

#if (STD_ON == COM_TX_TIMEOUT_MONITOR)
                Com_TxTimerOutMonitor(TxIpduId);
#endif

#if (STD_ON == COM_TX_FILTER_SUPPORT)
                /* switch txMode if needed, reset TxRegs acrroding to the new TxMode*/
                Com_SelectPduTxMode(TxIpduId, Com_SendSwitchTxModeFlag[TxIpduId]);
                Com_SendSwitchTxModeFlag[TxIpduId] = (uint8)0;
#endif

#if(STD_OFF == COM_TXMODE_PERIODIC_ONLY)
#if(STD_ON == COM_TXMODE_REPTITION)
                if((Com_PDUTrigRepFlag[TxIpduId] == COM_TRIGGER_REP) &&
                    ((uint8)0 == COM_TXPDU_TXMODE_REP_NUM(TxIpduId)))
                {
                    Com_PDUTrigRepFlag[TxIpduId] = COM_TRIGGER;
                }
#endif
#endif

                /* check if there is tx request this cycle*/
                sendFlag = Com_TxModeProcess(TxIpduId);

#if (STD_ON == COM_MDT_CYCLIC_TRANSMISSION)
                if(COM_TIMER_STOP_VAL != COM_TXPDU_MIN_DELAY_TIMER(TxIpduId))
                {
                    if((uint16)0 != COM_TXPDU_MIN_DELAY_TIMER(TxIpduId))
                    {
                        COM_TXPDU_MIN_DELAY_TIMER(TxIpduId)--;
                    }
                    if((uint16)0 == COM_TXPDU_MIN_DELAY_TIMER(TxIpduId))
                    {
                        COM_TXPDU_MIN_DELAY_TIMER(TxIpduId) = COM_TIMER_STOP_VAL;
                    }
                    else
                    {
                        if(TRUE == sendFlag)
                        {
                            COM_TXPDU_TX_REQ_MINDELAY_BACKUP(TxIpduId) = TRUE;
                        }

                        sendFlag = FALSE;

                    }
                }
#endif

#if(STD_ON == COM_TX_LONG_PDU_FUN)/*SWS_Com_00863*/
                if((TRUE == sendFlag)
                        && (TRUE == COM_CFG_TXPDU_IS_TP_PDU(TxIpduId))
                        && (COM_TXPDU_START_BUSY == Com_TxPduState[TxIpduId]))
                {
                    sendFlag = FALSE;
                    COM_DET_REPORT_RUNTIME_ERROR(COMServiceId_MainFunctionTx, COM_E_SKIP_TRANSMISSION);
                }
#endif



                if(TRUE == sendFlag)
                {
                    Com_TransmitPdu(TxIpduId);/*SWS_Com_478*/
                }
                SchM_Exit_Com_COM_EXCLUSIVE_AREA_0();

            }
        }
    }
#endif /*#if(STD_ON == COM_TXPDU_FUN)*/

}


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Com_RxIndication  SWS_Com_00123
*
* Description:   rx indication when rx Ipdu.
*
* Inputs:        RxPduId,PduInfoPtr
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, COM_CODE) Com_RxIndication
(
    PduIdType RxPduId,
    P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr
)
{

#if(COM_RXIPDU_CALLOUT == STD_ON)
    boolean Com_RxCalResult = TRUE;
#endif
#if(COM_RXIPDU_CALLOUT == STD_ON)
    /* this ptr must remove const as e2e may need change*/
    P2VAR(PduInfoType, AUTOMATIC, COM_APPL_DATA) tempPduInfoPtr = (PduInfoType *)PduInfoPtr;
#endif

    if(COM_INIT != Com_InitStateFlag)
    {
        COM_DET_REPORT_ERROR(COMServiceId_RxIndication, COM_E_UNINIT);
    }
    else if(RxPduId >= COM_RXPDU_NUM)
    {
        COM_DET_REPORT_ERROR(COMServiceId_RxIndication, COM_E_PARAM);
    }
    else if(PduInfoPtr == NULL_PTR)
    {
        COM_DET_REPORT_ERROR(COMServiceId_RxIndication, COM_E_PARAM_POINTER);
    }
    else if(PduInfoPtr->SduDataPtr == NULL_PTR)
    {
        COM_DET_REPORT_ERROR(COMServiceId_RxIndication, COM_E_PARAM_POINTER);
    }
#if(STD_ON == COM_RXPDU_FUN)
    else if(TRUE == COM_CFG_RXPDU_IS_TP_PDU(RxPduId))
    {
        COM_DET_REPORT_ERROR(COMServiceId_RxIndication, COM_E_PARAM);
    }
    else if(FALSE == Com_CheckRxLength(RxPduId, PduInfoPtr->SduLength))
    {
        COM_DET_REPORT_ERROR(COMServiceId_RxIndication, COM_E_PARAM);
    }
    else
    {

        if(COM_RXPDU_START_IDLE == Com_RxPduState[RxPduId])
        {
		    /* when imm pdu, reset timeout at once*/
#if(STD_ON == COM_RX_TIMEOUT_MONITOR)
			if((TRUE == COM_RXPDU_MONITOR_FLAG(RxPduId)) && (TRUE == COM_CFG_RXPDU_IS_IMM_PROCESSING(RxPduId)))
			{
				COM_RXPDU_TIMEOUT(RxPduId) = COM_CFG_RXPDU_PERIOD_TIMEOUT(RxPduId);/*SWS_Com_00715*/
			}
#endif
#if(COM_RXIPDU_CALLOUT == STD_ON)
            if(NULL_PTR != COM_CFG_RXPDU_CALLOUT(RxPduId))
            {
                Com_RxCalResult = COM_CFG_RXPDU_CALLOUT(RxPduId)(RxPduId, tempPduInfoPtr);
            }
            if(FALSE == Com_RxCalResult)
            {
                Com_RxPduState[RxPduId] = COM_RXPDU_START_RXSTOP;
#if (STD_ON == COM_RX_INVALID_SUPPORT)
                if(TRUE == COM_CFG_RXPDU_IS_IMM_PROCESSING(RxPduId))
                {
                    /*call invalid ack, or replace invalid value to signal SWS_Com_00839*/
                    Com_RxPduInvalid(RxPduId);
					Com_RxPduState[RxPduId] = COM_RXPDU_START_IDLE;
                }
#endif
            }
            else
#endif
            {
                SchM_Enter_Com_COM_EXCLUSIVE_AREA_2();
                Com_RxPduState[RxPduId] = COM_RXPDU_START_RXOK;

                /* temp buf is not null, copy to temp first
                   data may need to be copy in following cases:
                   1. need rx filter
                   2. need check invalid
                   3. has update bit
                */
                /* Copy data and length, if pdu is dyn pdu, dyn length also copied*/
                /* process if imm*/
                COM_RXPDU_TEMP_LENGTH(RxPduId)  = PduInfoPtr->SduLength;
#if (STD_OFF == COM_RX_DIRECT_COPY)
                if(NULL_PTR != COM_CFG_RXPDU_DATA_PTR_TEMP(RxPduId))
                {
                    Bsw_MemCpy((uint8 *)COM_CFG_RXPDU_DATA_PTR_TEMP(RxPduId), PduInfoPtr->SduDataPtr, (uint32)PduInfoPtr->SduLength);
                    if(TRUE == COM_CFG_RXPDU_IS_IMM_PROCESSING(RxPduId))/*SWS_Com_00300*/
                    {
                        Com_HandleRxPdu(RxPduId);
						Com_RxPduState[RxPduId] = COM_RXPDU_START_IDLE;
                    }
                }
                else
#endif
                {
                    Bsw_MemCpy((uint8 *)COM_CFG_RXPDU_DATA_PTR(RxPduId), PduInfoPtr->SduDataPtr, (uint32)PduInfoPtr->SduLength);

#if (STD_ON == COM_RX_DYN_PDU_SUPPORT)/* dynlength must be copy here too*/
                    if(TRUE == COM_CFG_RXPDU_IS_DYN(RxPduId))
                    {
                        COM_RXPDU_DYN_LENGTH(RxPduId) = COM_RXPDU_TEMP_LENGTH(RxPduId);
                    }
#endif



                    if(TRUE == COM_CFG_RXPDU_IS_IMM_PROCESSING(RxPduId))/*SWS_Com_00300*/
                    {
                        Com_HandleRxPdu_DirectCopy(RxPduId);
						Com_RxPduState[RxPduId] = COM_RXPDU_START_IDLE;
                    }
                }
                SchM_Exit_Com_COM_EXCLUSIVE_AREA_2();
            }

        }
    }
#endif/* #if(STD_ON == COM_RXPDU_FUN) */
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Com_MainFunctionRx SWS_Com_0039
*
* Description:   process rx msg of com
*
* Inputs:        None
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, COM_CODE) Com_MainFunctionRx
(
    void
)
{
#if(STD_ON == COM_RXPDU_FUN)
    PduIdType RxIpduId = (PduIdType)0;
#endif

    if(COM_INIT != Com_InitStateFlag)/*SWS_Com_00664*/
    {
        COM_DET_REPORT_ERROR(COMServiceId_MainFunctionRx, COM_E_UNINIT);
    }
#if(STD_ON == COM_RXPDU_FUN)
    else
    {
        for(RxIpduId = (PduIdType)0; RxIpduId < COM_RXPDU_NUM; RxIpduId++)
        {
            if(COM_RXPDU_STOP != Com_RxPduState[RxIpduId])
            {
                SchM_Enter_Com_COM_EXCLUSIVE_AREA_2();

                if((Com_RxPduState[RxIpduId] >= COM_RXPDU_START_RXOK)
				&&(FALSE == COM_CFG_RXPDU_IS_IMM_PROCESSING(RxIpduId)))
                {

#if(STD_ON == COM_RX_LONG_PDU_FUN)
                    COM_RXPDU_TP_INDEX(RxIpduId) = (PduLengthType)0;
#endif

#if(STD_ON == COM_RX_TIMEOUT_MONITOR)
                    if(TRUE == COM_RXPDU_MONITOR_FLAG(RxIpduId))
                    {
                        COM_RXPDU_TIMEOUT(RxIpduId) = COM_CFG_RXPDU_PERIOD_TIMEOUT(RxIpduId);/*SWS_Com_00715*/
                    }
#endif


                    if(Com_RxPduState[RxIpduId] == COM_RXPDU_START_RXOK)
                    {

#if(STD_OFF == COM_RX_DIRECT_COPY)
                        if(NULL_PTR != COM_CFG_RXPDU_DATA_PTR_TEMP(RxIpduId))
                        {
                            Com_HandleRxPdu(RxIpduId);
                        }
                        else
#endif
                        {
                            Com_HandleRxPdu_DirectCopy(RxIpduId);
                        }
                    }
                    /* RXSTOP or NOTOK, do invalid action*/
#if (STD_ON == COM_RX_INVALID_SUPPORT)
                    else
                    {
                        Com_RxPduInvalid(RxIpduId);/*SWS_Com_00839*/
                    }
#endif


                    Com_RxPduState[RxIpduId] = COM_RXPDU_START_IDLE;
                }

#if(STD_ON == COM_RX_TIMEOUT_MONITOR)
                if(TRUE == COM_RXPDU_MONITOR_FLAG(RxIpduId))
                {
                    Com_RxTimerOutMonitor(RxIpduId);
#if(STD_ON == COM_RX_UPDATEBIT_SUPPORT)
                    Com_UpdateRxTimerOutMonitor(RxIpduId);
#endif
                }
#endif

                SchM_Exit_Com_COM_EXCLUSIVE_AREA_2();
            }

        }
    }
#endif/* #if(STD_ON == COM_RXPDU_FUN)*/
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Com_ReceivedSignal
*
* Description:   This service copies the data of signal identified by SignalId
*                to the location specified by SignalDataPtr
*
* Inputs:        SignalId: ignal handle
*                SignalDataPtr: Reference to the location where the received
*                               signal data shall be stored
*
* Outputs:       E_OK:                      service has been accepted
*                COM_SERVICE_NOT_AVAILABLE: corresponding I-PDU group was
*                                           stopped
*                COM_BUSY:                  in case the TP-Buffer is lock for
                                            large data type handling
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(uint8, COM_CODE) Com_ReceiveSignal
(
    Com_SignalIdType SignalId,
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{

    uint8 result = COM_SERVICE_NOT_AVAILABLE;
#if(STD_ON == COM_RXPDU_FUN)
    PduIdType RxIpduId = (PduIdType)0;
#endif


    if(COM_INIT != Com_InitStateFlag)
    {
        COM_DET_REPORT_ERROR(COMServiceId_ReceiveSignal, COM_E_UNINIT);
    }
    else if(SignalId >= COM_RXSIG_NUM)
    {
        COM_DET_REPORT_ERROR(COMServiceId_ReceiveSignal, COM_E_PARAM);
    }
#if(STD_ON == COM_RXPDU_FUN)
    else if(COM_SIG_DYN == COM_CFG_RXSIG_TYPE(SignalId))
    {
        COM_DET_REPORT_ERROR(COMServiceId_ReceiveSignal, COM_E_PARAM);
    }
    else if(NULL_PTR == SignalDataPtr)
    {
        COM_DET_REPORT_ERROR(COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
    }
    else
    {

        RxIpduId = COM_CFG_RXSIG_RXPDU_ID(SignalId);
        /* dont need report busy , as copy process is protected by Area2
           and always read old data
        */

        SchM_Enter_Com_COM_EXCLUSIVE_AREA_2();
#if(COM_RX_SIGNAL_GROUP_SUPPORT == STD_ON)
        if(TRUE == COM_CFG_RXSIG_IS_GROUP_SIGNAL(SignalId))
        {
            if(NULL_PTR == COM_CFG_RXSIG_GROUP_TEMP_BUF(SignalId))/* SWS_Com_00843 not support groupsignal with arrayaccess = true*/
            {
                COM_DET_REPORT_ERROR(COMServiceId_ReceiveSignal, COM_E_PARAM);
            }
            else
            {
                COM_CFG_RXSIG_COPY_SIG_FUN(SignalId)(COM_CFG_RXSIG_GROUP_TEMP_BUF(SignalId), SignalDataPtr, COM_CFG_RXSIG_LENGTH(SignalId));
            }
        }
        else
#endif
        {
            COM_CFG_RXSIG_READ_SIG_FUN(SignalId)(SignalDataPtr, COM_CFG_RXPDU_DATA_PTR(RxIpduId), COM_CFG_RXSIG_LENGTH(SignalId));
        }
        SchM_Exit_Com_COM_EXCLUSIVE_AREA_2();

        /*
           when stop , read old data but return COM_SERVICE_NOT_AVAILABLE, no det err
           See Page54 Table3
        */

        if(COM_RXPDU_STOP != Com_RxPduState[RxIpduId])
        {
            result = E_OK;
        }

    }

#endif/* #if(STD_ON == COM_RXPDU_FUN)*/
    return    result;

}


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Com_ReceiveDynSignal
*
* Description:   This service copies the data of signal identified by SignalId
*                to the location specified by SignalDataPtr
*
* Inputs:        SignalId: ignal handle
*                SignalDataPtr: Reference to the location where the received
*                               signal data shall be stored
*                Length
*
* Outputs:       E_OK:                      service has been accepted
*                COM_SERVICE_NOT_AVAILABLE: corresponding I-PDU group was
*                                           stopped
*                COM_BUSY:                  in case the TP-Buffer is lock for
                                            large data type handling
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(uint8, COM_CODE) Com_ReceiveDynSignal
(
    Com_SignalIdType SignalId,
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr,
    P2VAR(uint16, AUTOMATIC, COM_APPL_DATA) Length
)
{

    uint8 result = COM_SERVICE_NOT_AVAILABLE;
#if(STD_ON == COM_RX_DYN_PDU_SUPPORT)
    PduIdType RxIpduId = (PduIdType)0;
    PduLengthType dynlength = (PduLengthType)0;
    /* as dyn signal must be byte aligned, so the temp srcDataPtr canbe uint8 * Ptr*/
    P2VAR(uint8, AUTOMATIC, COM_VAR) srcDataPtr = NULL_PTR;
#endif

    if(COM_INIT != Com_InitStateFlag)
    {
        COM_DET_REPORT_ERROR(COMServiceId_ReceiveDynSignal, COM_E_UNINIT);
    }
#if(STD_ON == COM_RX_DYN_PDU_SUPPORT)
    else if(SignalId >= COM_RXSIG_NUM)
    {
        COM_DET_REPORT_ERROR(COMServiceId_ReceiveDynSignal, COM_E_PARAM);
    }
    else if(COM_SIG_DYN != COM_CFG_RXSIG_TYPE(SignalId))
    {
        COM_DET_REPORT_ERROR(COMServiceId_ReceiveDynSignal, COM_E_PARAM);
    }

    else if(NULL_PTR == SignalDataPtr)
    {
        COM_DET_REPORT_ERROR(COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
    }
    else if(NULL_PTR == Length)
    {
        COM_DET_REPORT_ERROR(COMServiceId_ReceiveSignal, COM_E_PARAM_POINTER);
    }
    else
    {
        RxIpduId = COM_CFG_RXSIG_RXPDU_ID(SignalId);
        /* dont need report busy , as copy process is protected by Area2
           and always read old data
        */

#if(COM_RX_SIGNAL_GROUP_SUPPORT == STD_ON)
        if(TRUE == COM_CFG_RXSIG_IS_GROUP_SIGNAL(SignalId))
        {
            dynlength = *COM_CFG_RXSIG_GROUP_TEMPLENGTH_PTR(SignalId);
            srcDataPtr = (uint8 *)COM_CFG_RXSIG_GROUP_TEMP_BUF(SignalId);
        }
        else
#endif
        {
            dynlength = COM_RXPDU_DYN_LENGTH(RxIpduId) - COM_CFG_RXSIG_START_BYTE_INDEX(SignalId);
            srcDataPtr = &((uint8 *)COM_CFG_RXPDU_DATA_PTR(RxIpduId)) [COM_CFG_RXSIG_START_BYTE_INDEX(SignalId)];
        }
        if(*Length < dynlength)
        {
            COM_DET_REPORT_ERROR(COMServiceId_ReceiveDynSignal, COM_E_PARAM);
            result = E_NOT_OK;
        }
        else
        {
            SchM_Enter_Com_COM_EXCLUSIVE_AREA_2();
            Bsw_MemCpy((uint8 *)SignalDataPtr,  srcDataPtr, (uint32)dynlength);
            *Length = dynlength;
            SchM_Exit_Com_COM_EXCLUSIVE_AREA_2();
        }

        /*
           when stop , read old data but return COM_SERVICE_NOT_AVAILABLE, no det err
           See Page54 Table3
        */

        if(COM_RXPDU_STOP != Com_RxPduState[RxIpduId])
        {
            result = E_OK;
        }

    }
#else
    else
    {
        COM_DET_REPORT_ERROR(COMServiceId_ReceiveDynSignal, COM_E_PARAM);
    }
#endif/*#if(STD_ON == COM_RX_DYN_PDU_SUPPORT)*/

    return    result;

}





/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Com_SwitchIpduTxMode SWS_Com_00784
*
* Description:   This service copies the data of signal identified by SignalId
*                to the location specified by SignalDataPtr
*
* Inputs:        PduId
*                Mode
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, COM_CODE) Com_SwitchIpduTxMode
(
    PduIdType PduId,
    boolean Mode
)
{
    if(COM_INIT != Com_InitStateFlag)
    {
        COM_DET_REPORT_ERROR(COMServiceId_SwitchIpduTxMode, COM_E_UNINIT);
    }
    else if(PduId >= COM_TXPDU_NUM)
    {
        COM_DET_REPORT_ERROR(COMServiceId_SwitchIpduTxMode, COM_E_PARAM);
    }
    else
    {
#if(STD_ON == COM_TX_FILTER_SUPPORT)
        /*
            Can switch mode when pdu is stop
            new txmode will be active when pdu is restart
        */
        SchM_Enter_Com_COM_EXCLUSIVE_AREA_0();
        if(TRUE == Mode)
        {
            if(NULL_PTR != COM_CFG_TXPDU_TXMODE_TRUE_PTR(PduId))
            {
                Com_SendSwitchTxModeFlag[PduId] = COM_TXMODE_SWITCH_API_TRUE;
            }
        }
        else
        {
            if(NULL_PTR != COM_CFG_TXPDU_TXMODE_FALSE_PTR(PduId))
            {
                Com_SendSwitchTxModeFlag[PduId] = COM_TXMODE_SWITCH_API_FALSE;
            }

        }
        SchM_Exit_Com_COM_EXCLUSIVE_AREA_0();
#endif

    }
}



/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Com_TriggerIPDUSend SWS_Com_00348
*
* Description:
*
* Inputs:        PduId: ignal handle
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, COM_CODE) Com_TriggerIPDUSend
(
    PduIdType PduId
)
{
    Std_ReturnType ret = E_NOT_OK;


    if(COM_INIT != Com_InitStateFlag)
    {
        COM_DET_REPORT_ERROR(COMServiceId_TriggerIPDUSend, COM_E_UNINIT);
    }
    else if(PduId >= COM_TXPDU_NUM)
    {
        COM_DET_REPORT_ERROR(COMServiceId_TriggerIPDUSend, COM_E_PARAM);
    }
    else
    {
#if(STD_ON == COM_TriggerIPDUSend_API)
        if(COM_TXPDU_STOP != Com_TxPduState[PduId])/*SWS_Com_00861*/
        {
            Com_TriggerPDUSendFlag[PduId] = TRUE;
            ret = E_OK;
        }
#endif
    }

    return ret;
}



/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Com_TriggerTransmit SWS_Com_00001
*
* Description:   This service copies the data  to  PduInfoPtr
*
* Inputs:        TxPduId: ignal handle
*                PduInfoPtr: Reference to the location where the tx
*                            data shall be stored
*
* Outputs:       E_OK
*                E_NOT_OK
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, COM_CODE)Com_TriggerTransmit
(
    PduIdType TxPduId,
    P2VAR(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr
)
{

    Std_ReturnType result = E_NOT_OK;
#if(STD_ON == COM_TXPDU_FUN)
    PduLengthType length = (PduLengthType)0;
#endif

    if(COM_INIT != Com_InitStateFlag)
    {
        COM_DET_REPORT_ERROR(COMServiceId_TriggerTransmit, COM_E_UNINIT);
    }
#if(STD_ON == COM_TXPDU_FUN)
    else if(TxPduId >= COM_TXPDU_NUM)
    {
        COM_DET_REPORT_ERROR(COMServiceId_TriggerTransmit, COM_E_PARAM);
    }
    else if(NULL_PTR == PduInfoPtr)
    {
        COM_DET_REPORT_ERROR(COMServiceId_TriggerTransmit, COM_E_PARAM_POINTER);
    }
    else if(NULL_PTR == (PduInfoPtr->SduDataPtr))
    {
        COM_DET_REPORT_ERROR(COMServiceId_TriggerTransmit, COM_E_PARAM_POINTER);
    }
    else
    {
        /*length check */ /*SWS_Com_869*/
        length = COM_CFG_TXPDU_LENGTH(TxPduId);
#if (STD_ON == COM_TX_DYN_PDU_SUPPORT)
        if(TRUE == COM_CFG_TXPDU_IS_DYN(TxPduId))
        {
            length = COM_TXPDU_DYN_LENGTH(TxPduId);
        }
#endif

        if(PduInfoPtr->SduLength < length)
        {
            COM_DET_REPORT_ERROR(COMServiceId_TriggerTransmit, COM_E_PARAM);
        }
        else
        {
            if(COM_TXPDU_STOP != Com_TxPduState[TxPduId])
            {
                SchM_Enter_Com_COM_EXCLUSIVE_AREA_6();

                /*SWS_Com_647*/
                Bsw_MemCpy(PduInfoPtr->SduDataPtr, (uint8 *)COM_CFG_TXPDU_DATA_PTR(TxPduId), (uint32)length);
                PduInfoPtr->SduLength = length;

#if(COM_TX_UPDATEBIT_SUPPORT == STD_ON)
                if(COM_CUB_TRIGGER == COM_CFG_TXPDU_UPDATEBIT_CLEARTYPE(TxPduId))

                {
                    Com_ClearUpdateBit(TxPduId);
                }
#endif

                SchM_Exit_Com_COM_EXCLUSIVE_AREA_6();

#if (STD_ON == COM_TX_TRIGGER_CALLOUT_SUPPORT)
                if(NULL_PTR != COM_CFG_TXPDU_TRIGGER_CALLOUT(TxPduId))
                {
                    /*SWS_Com_395 ignor the return value of this callout. why?*/
                    (void)COM_CFG_TXPDU_TRIGGER_CALLOUT(TxPduId)(TxPduId, PduInfoPtr); /*SWS_Com_766 */
                }
#endif

                result = E_OK;
            }

        }
    }
#endif/*#if(STD_ON == COM_TXPDU_FUN)*/
    return result;
}


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Com_TpTxConfirmation SWS_Com_00725
*
* Description:   Callbak function Com provided by Com to Tp
*
* Inputs:        PduId:  Receive PduId
*                Result: NTFRSLT_OK means the complete N-PDU has been eceived
*                        and is stored in the receive buffer.Any other value
*                        means the N_PDU has not been received,
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, COM_CODE) Com_TpTxConfirmation
(
    PduIdType TxPduId,
    Std_ReturnType Result
)
{
#if(STD_ON == COM_TX_LONG_PDU_FUN)
    Com_TxPduStateType pduState;
#endif

    if(COM_INIT != Com_InitStateFlag)
    {
        COM_DET_REPORT_ERROR(COMServiceId_TpTxConfirmation, COM_E_UNINIT);
    }
#if(STD_ON == COM_TX_LONG_PDU_FUN)
    else if(TxPduId >= COM_TXPDU_NUM)
    {
        COM_DET_REPORT_ERROR(COMServiceId_TpTxConfirmation, COM_E_PARAM);
    }
    else if(FALSE == COM_CFG_TXPDU_IS_TP_PDU(TxPduId))
    {
        COM_DET_REPORT_ERROR(COMServiceId_TpTxConfirmation, COM_E_PARAM);
    }
    else
    {
        /* dont consider None Pdu here as  tp will callCopyTxDta first*/
        /*SWS_Com_00800 STOP Pdu ignor txConf*/
        if(COM_TXPDU_START_BUSY == Com_TxPduState[TxPduId])
        {
            SchM_Enter_Com_COM_EXCLUSIVE_AREA_0();
            if(E_OK == Result)
            {
                pduState = COM_TXPDU_START_TXOK;

            }
            else
            {
                pduState = COM_TXPDU_START_TXNOTOK;/*TXNOTOK not used in this version*/
            }

            if(TRUE == COM_CFG_TXPDU_IS_IMM_PROCESSING(TxPduId))
            {
                /* switch IDLE in this fucntion as nothinf need to do in mainfuntionTx*/
                Com_ProcessTxConf(TxPduId, pduState);
            }
            else
            {
                /* set to OK or notok, process will be done in mainfuntionTx*/
                Com_TxPduState[TxPduId] = pduState;
            }


#if(COM_TX_UPDATEBIT_SUPPORT == STD_ON)
            if(COM_CUB_CONF == COM_CFG_TXPDU_UPDATEBIT_CLEARTYPE(TxPduId))
            {
                Com_ClearUpdateBit(TxPduId);
            }
#endif

#if(STD_ON == COM_MDT_CYCLIC_TRANSMISSION)/*SWS_Com_00469, reset min delay timer when txConf is received*/
            if((COM_TXPDU_TXMODE(TxPduId) != COM_PDU_NONE)
                    && (COM_CFG_TXPDU_MIN_DELAY_TIMER(TxPduId) > (uint16)0)
                    && (COM_TXPDU_MIN_DELAY_TIMER(TxPduId) != (uint16)0)
                    && (COM_TXPDU_MIN_DELAY_TIMER(TxPduId) != COM_TIMER_STOP_VAL))
            {
                /* no MDT for NONE pdu*/
                COM_TXPDU_MIN_DELAY_TIMER(TxPduId) = COM_CFG_TXPDU_MIN_DELAY_TIMER(TxPduId);
            }
#endif
            SchM_Exit_Com_COM_EXCLUSIVE_AREA_0();

        }
    }
#else
    else
    {
        COM_DET_REPORT_ERROR(COMServiceId_TpTxConfirmation, COM_E_PARAM);
    }
#endif /*#if(STD_ON == COM_TX_LONG_PDU_FUN)*/

}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Com_CopyTxData SWS_Com_00693
*
* Description:   Callbak function Com provided by Com to Tp
*
* Inputs:        PduId:   Transmitt PduId
*                PduInfoPtr:   Pointer to a PduInfoType, which indicates the
*                              number of bytes to be copied (SduLength) and the
*                              location where the data have to be copied to
*                              SduDataPtr).
*                RetryInfoPtr: None used
*                TxDataCntPtr: Remaining Tx data after completion of this call
*
* Outputs:       BUFREQ_OK, BUFREQ_E_NOT_OK
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(BufReq_ReturnType, COM_CODE) Com_CopyTxData
(
    PduIdType PduId,
    P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr,
    P2VAR(RetryInfoType, AUTOMATIC, COM_APPL_DATA) RetryInfoPtr,
    P2VAR(PduLengthType, AUTOMATIC, COM_APPL_DATA) TxDataCntPtr
)
{

    BufReq_ReturnType result = BUFREQ_E_NOT_OK;
#if(STD_ON == COM_TX_LONG_PDU_FUN)
    PduLengthType maxLength;
#endif

    if(COM_INIT != Com_InitStateFlag)
    {
        COM_DET_REPORT_ERROR(COMServiceId_CopyTxData, COM_E_UNINIT);
    }
#if(STD_ON == COM_TX_LONG_PDU_FUN)
    else if(PduId >= COM_TXPDU_NUM)
    {
        COM_DET_REPORT_ERROR(COMServiceId_CopyTxData, COM_E_PARAM);
    }
    else if(FALSE == COM_CFG_TXPDU_IS_TP_PDU(PduId))
    {
        COM_DET_REPORT_ERROR(COMServiceId_CopyTxData, COM_E_PARAM);
    }
    else if(COM_TXPDU_STOP == Com_TxPduState[PduId])/*SWS_Com_00783*/
    {
        /* do nothing only return notok*/
    }
    else if(NULL_PTR == TxDataCntPtr)
    {
        COM_DET_REPORT_ERROR(COMServiceId_CopyTxData, COM_E_PARAM_POINTER);
    }
    else if(NULL_PTR == PduInfoPtr)
    {
        COM_DET_REPORT_ERROR(COMServiceId_CopyTxData, COM_E_PARAM_POINTER);
    }
    else if(NULL_PTR == PduInfoPtr->SduDataPtr)
    {
        COM_DET_REPORT_ERROR(COMServiceId_CopyTxData, COM_E_PARAM_POINTER);
    }
    else
    {
        (void)RetryInfoPtr;
        /* 1.current version com dont support LinTp  message
           2.normally LinTp dont tx tp packet by itsself, if support lintp, com need to start tp tx request bu call LinTp_Transmit
           so here we dont consider NONE type pdu.
        */
        if(COM_TXPDU_START_BUSY == Com_TxPduState[PduId])
        {

            maxLength = COM_CFG_TXPDU_LENGTH(PduId);

#if(STD_ON == COM_TX_DYN_PDU_SUPPORT)
            if(TRUE == COM_CFG_TXPDU_IS_DYN(PduId))
            {
                maxLength = COM_TXPDU_DYN_LENGTH(PduId);

            }
#endif

            if((COM_TXPDU_TP_INDEX(PduId) + PduInfoPtr->SduLength) > maxLength)
            {
                COM_DET_REPORT_ERROR(COMServiceId_CopyTxData, COM_E_PARAM);
            }
            else
            {
                /* no Exclusive  Area, as the tp buffer is locked by busy state */
                Bsw_MemCpy(PduInfoPtr->SduDataPtr, &(((uint8 *)COM_CFG_TXPDU_DATA_PTR(PduId))[COM_TXPDU_TP_INDEX(PduId)]), (uint32)PduInfoPtr->SduLength);
                COM_TXPDU_TP_INDEX(PduId) += (PduInfoPtr->SduLength);
                *TxDataCntPtr =  maxLength - COM_TXPDU_TP_INDEX(PduId);
                result = BUFREQ_OK;
            }
        }
    }
#else
    else
    {
        COM_DET_REPORT_ERROR(COMServiceId_CopyTxData, COM_E_PARAM);
    }
#endif /*#if(STD_ON == COM_TX_LONG_PDU_FUN)*/

    return result;

}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Com_StartOfReception SWS_Com_00691
*
* Description:   Callbak function Com provided by Com to J1939Tp
*
* Inputs:        ComRxPduId:      Receive PduId
*                TpSduLength:     Length in Single Frame or Fist Frame
*                RxBufferSizePtr: Avaliable buffer size Com can provided
*
* Outputs:       BUFREQ_E_NOT_OK, BUFREQ_E_BUSY and BUFREQ_E_OVFL
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(BufReq_ReturnType, COM_CODE) Com_StartOfReception
(
    PduIdType ComRxPduId,
    P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPointer,
    PduLengthType TpSduLength,
    P2VAR(PduLengthType, AUTOMATIC, COM_APPL_DATA) RxBufferSizePtr
)
{

    BufReq_ReturnType result = BUFREQ_E_NOT_OK;

    if(COM_INIT != Com_InitStateFlag)
    {
        COM_DET_REPORT_ERROR(COMServiceId_StartOfReception, COM_E_UNINIT);
    }
#if(STD_ON == COM_RX_LONG_PDU_FUN)
    else if((ComRxPduId >= COM_RXPDU_NUM)
            || (FALSE == COM_CFG_RXPDU_IS_TP_PDU(ComRxPduId)))
    {
        COM_DET_REPORT_ERROR(COMServiceId_StartOfReception, COM_E_PARAM);
    }
    else if(COM_RXPDU_STOP == Com_RxPduState[ComRxPduId])
    {
        /*SWS_Com_00721  SWS_Com_00684 713 do nothing, only return BUFREQ_E_NOT_OK*/
    }
    else if(NULL_PTR == RxBufferSizePtr)
    {
        COM_DET_REPORT_ERROR(COMServiceId_StartOfReception, COM_E_PARAM_POINTER);
    }
    else if(COM_RXPDU_START_BUSY == Com_RxPduState[ComRxPduId])
    {
        result = BUFREQ_E_BUSY;
    }
    /*length check */ /*SWS_Com_00574*/
    else if(TpSduLength > COM_CFG_RXPDU_LENGTH(ComRxPduId))
    {
        result = BUFREQ_E_OVFL;/* SWS_Com_00654 655*/
        COM_DET_REPORT_ERROR(COMServiceId_StartOfReception, COM_E_PARAM);
    }
    else if(FALSE == Com_CheckRxLength(ComRxPduId, TpSduLength))
    {
        COM_DET_REPORT_ERROR(COMServiceId_StartOfReception, COM_E_PARAM);
    }
    else
    {

        (void)PduInfoPointer;/* dont support metaData in this version, ignor this parameter*/

        Com_RxPduState[ComRxPduId] = COM_RXPDU_START_BUSY;
        COM_RXPDU_TP_INDEX(ComRxPduId) = (PduLengthType)0;

        /* save length to tempLength reg, both for dyn or fix pdu
             as the rx length may be smaller than cfg length*/
        COM_RXPDU_TEMP_LENGTH(ComRxPduId) = TpSduLength;

        *RxBufferSizePtr = TpSduLength;/* if dyn pdu , only tell the dyn length*/
        result = BUFREQ_OK;

    }
#else
    else
    {
        COM_DET_REPORT_ERROR(COMServiceId_StartOfReception, COM_E_PARAM);
    }
#endif/*#if(STD_ON == COM_RX_LONG_PDU_FUN)*/

    return result;

}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Com_CopyRxData SWS_Com_00692
*
* Description:   Callbak function Comm provided by Comm to J1939Tp
*
* Inputs:        PduId:     Receive PduId
*                PduInfoPointer:  Pointer to a PduInfoType which indicates
*                                 the number of bytes to be copied (SduLength)
*                                 and the location of the source data
*                                 (SduDataPtr).
*                RxBufferSizePtr: Remaining free place in receive buffer after
*                                 completion of this call.
*
* Outputs:       BUFREQ_OK, BUFREQ_E_BUSY
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(BufReq_ReturnType, COM_CODE) Com_CopyRxData
(
    PduIdType PduId,
    P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPointer,
    P2VAR(PduLengthType, AUTOMATIC, COM_APPL_DATA) RxBufferSizePtr
)
{

    BufReq_ReturnType result = BUFREQ_E_NOT_OK;
#if(STD_ON == COM_RX_LONG_PDU_FUN)
    PduLengthType maxLength = (PduLengthType)0;
#endif

    if(COM_INIT != Com_InitStateFlag)
    {
        COM_DET_REPORT_ERROR(COMServiceId_CopyRxData, COM_E_UNINIT);
    }
#if(STD_ON == COM_RX_LONG_PDU_FUN)
    else if((PduId >= COM_RXPDU_NUM)
            || (FALSE == COM_CFG_RXPDU_IS_TP_PDU(PduId)))
    {
        COM_DET_REPORT_ERROR(COMServiceId_CopyRxData, COM_E_PARAM);
    }
    else if(COM_RXPDU_START_BUSY != Com_RxPduState[PduId])
    {
        /*SWS_Com_00782  SWS_Com_00684 713 do nothing, only return BUFREQ_E_NOT_OK*/
        /* Only copy data when buffer is lock by startofrx */
    }
    else if(NULL_PTR == RxBufferSizePtr)
    {
        COM_DET_REPORT_ERROR(COMServiceId_CopyRxData, COM_E_PARAM_POINTER);

    }
    else if(NULL_PTR == PduInfoPointer)
    {
        COM_DET_REPORT_ERROR(COMServiceId_CopyRxData, COM_E_PARAM_POINTER);
    }
    else if(NULL_PTR == PduInfoPointer->SduDataPtr)
    {
        COM_DET_REPORT_ERROR(COMServiceId_CopyRxData, COM_E_PARAM_POINTER);
    }
    else
    {

        maxLength = COM_RXPDU_TEMP_LENGTH(PduId);

        if((COM_RXPDU_TP_INDEX(PduId) + PduInfoPointer->SduLength) > maxLength)
        {
            /* dont reset rxState here, as com will expected a rxTpIndication with result = notok*/
            result = BUFREQ_E_OVFL;
        }
        else
        {
            Bsw_MemCpy(&(((uint8 *)COM_CFG_RXPDU_DATA_PTR_TEMP(PduId))[COM_RXPDU_TP_INDEX(PduId)]), PduInfoPointer->SduDataPtr, (uint32)PduInfoPointer->SduLength);

            COM_RXPDU_TP_INDEX(PduId) += (PduInfoPointer->SduLength);

            *RxBufferSizePtr = maxLength - COM_RXPDU_TP_INDEX(PduId);
            result = BUFREQ_OK;

        }

    }
#else
    else
    {
        COM_DET_REPORT_ERROR(COMServiceId_CopyRxData, COM_E_PARAM);
    }
#endif/*#if(STD_ON == COM_RX_LONG_PDU_FUN)*/


    return result;
}


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Com_TpRxIndication SWS_Com_00650
*
* Description:   Callbak function Com provided by Com to J1939Tp
*
* Inputs:        PduId:  Receive PduId
*                Result: NTFRSLT_OK means the complete N-PDU has been eceived
*                        and is stored in the receive buffer.Any other value
*                        means the N_PDU has not been received,
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, COM_CODE) Com_TpRxIndication
(
    PduIdType PduId,
    Std_ReturnType Result
)
{
#if(COM_RXIPDU_CALLOUT == STD_ON)
    boolean Com_RxCalResult = TRUE;
    PduInfoType PduInfo;
#endif

    if(COM_INIT != Com_InitStateFlag)
    {
        COM_DET_REPORT_ERROR(COMServiceId_TpRxIndication, COM_E_UNINIT);
    }
#if(STD_ON == COM_RX_LONG_PDU_FUN)
    else if((PduId >= COM_RXPDU_NUM)
            || (FALSE == COM_CFG_RXPDU_IS_TP_PDU(PduId)))
    {
        COM_DET_REPORT_ERROR(COMServiceId_TpRxIndication, COM_E_PARAM);
    }
    else
    {
        if(COM_RXPDU_START_BUSY == Com_RxPduState[PduId])/*SWS_Com_00684 713*/
        {
#if(STD_ON == COM_RX_TIMEOUT_MONITOR)
			if((TRUE == COM_RXPDU_MONITOR_FLAG(PduId)) && (TRUE == COM_CFG_RXPDU_IS_IMM_PROCESSING(PduId)))
			{
				COM_RXPDU_TIMEOUT(PduId) = COM_CFG_RXPDU_PERIOD_TIMEOUT(PduId);/*SWS_Com_00715*/
			}
#endif
            /* not reset tempDynLength, as it will not affect anything*/
            if(E_OK == Result)
            {
                /* Ipdu received */
#if(COM_RXIPDU_CALLOUT == STD_ON)
                if(NULL_PTR != COM_CFG_RXPDU_CALLOUT(PduId))
                {
                    PduInfo.SduLength = COM_RXPDU_TEMP_LENGTH(PduId);
                    PduInfo.SduDataPtr = (SduDataPtrType)COM_CFG_RXPDU_DATA_PTR_TEMP(PduId);
                    Com_RxCalResult = COM_CFG_RXPDU_CALLOUT(PduId)(PduId, &PduInfo);
                }

                if(FALSE == Com_RxCalResult)
                {
                    Com_RxPduState[PduId] = COM_RXPDU_START_RXSTOP;
#if (STD_ON == COM_RX_INVALID_SUPPORT)
                    if(TRUE == COM_CFG_RXPDU_IS_IMM_PROCESSING(PduId))
                    {
                        /*call invalid ack, or replace invalid value to signa l SWS_Com_00839*/
                        Com_RxPduInvalid(PduId);
						Com_RxPduState[PduId] = COM_RXPDU_START_IDLE;
                    }
#endif
                }
                else
#endif
                {
                    SchM_Enter_Com_COM_EXCLUSIVE_AREA_2();
					Com_RxPduState[PduId] = COM_RXPDU_START_RXOK;
                    /* data and length has been saved in temp buffer*/
                    if(TRUE == COM_CFG_RXPDU_IS_IMM_PROCESSING(PduId))
                    {
                        Com_HandleRxPdu(PduId);/*SWS_Com_00300*/
						Com_RxPduState[PduId] = COM_RXPDU_START_IDLE;
                    }
                    SchM_Exit_Com_COM_EXCLUSIVE_AREA_2();
                }
            }
            else
            {
                /* can not reset dynRxLength, as old data may be read again*/
                Com_RxPduState[PduId] = COM_RXPDU_START_RXNOTOK;
#if (STD_ON == COM_RX_INVALID_SUPPORT)
                if(TRUE == COM_CFG_RXPDU_IS_IMM_PROCESSING(PduId))
                {
                    Com_RxPduInvalid(PduId);/*SWS_Com_00838*/
					Com_RxPduState[PduId] = COM_RXPDU_START_IDLE;
                }
#endif
            }


        }
    }
#else
    else
    {
        COM_DET_REPORT_ERROR(COMServiceId_TpRxIndication, COM_E_PARAM);
    }
#endif/*#if(STD_ON == COM_RX_LONG_PDU_FUN)*/

}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Com_ClearIpduGroupVector SWS_Com_00749
*
* Description:
*
* Inputs:        ipduGroupVector: ignal handle
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
#if (STD_ON == COM_IPDU_GROUP_FUN)
FUNC(void, COM_CODE) Com_ClearIpduGroupVector
(
    Com_IpduGroupVector ipduGroupVector
)
{

    uint16 Index = (uint16)0;
    uint16 PduGroupVectorSize = COM_PDU_GROUP_NUM - (uint16)1;

    if(COM_INIT != Com_InitStateFlag)
    {
        COM_DET_REPORT_ERROR(COMServiceId_ClearIpduGroupVector, COM_E_UNINIT);
    }
    else if(NULL_PTR == ipduGroupVector)
    {
        COM_DET_REPORT_ERROR(COMServiceId_ClearIpduGroupVector, COM_E_PARAM_POINTER);
    }
    else
    {
        PduGroupVectorSize = PduGroupVectorSize >> COM_GET_BYTEINX_SHIFT_VALUE;
        PduGroupVectorSize = PduGroupVectorSize + (uint16)1;

        SchM_Enter_Com_COM_EXCLUSIVE_AREA_7();
        for(Index = (uint16)0; Index < PduGroupVectorSize; Index++)
        {
            ipduGroupVector[Index] = (uint8)0;
        }
        SchM_Exit_Com_COM_EXCLUSIVE_AREA_7();
    }
}


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Com_SetIpduGroup SWS_Com_00750
*
* Description:
*
* Inputs:        ipduGroupVector
*                IpduGroupId
*                bitval
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, COM_CODE) Com_SetIpduGroup
(
    Com_IpduGroupVector ipduGroupVector,
    Com_IpduGroupIdType  ipduGroupId,
    boolean bitval
)
{

    uint8 Position_Bit = (uint8)0;
    uint16 Position_Byte = (uint16)0;
    uint8 tempByte = (uint8)0;

    if(COM_INIT != Com_InitStateFlag)
    {
        COM_DET_REPORT_ERROR(COMServiceId_SetIpduGroup, COM_E_UNINIT);
    }
    else if(NULL_PTR == ipduGroupVector)
    {
        COM_DET_REPORT_ERROR(COMServiceId_SetIpduGroup, COM_E_PARAM_POINTER);
    }
    else if(ipduGroupId >= COM_PDU_GROUP_NUM)
    {
        COM_DET_REPORT_ERROR(COMServiceId_SetIpduGroup, COM_E_PARAM);
    }
    else
    {
        /*SWS_Com_00623*/
        SchM_Enter_Com_COM_EXCLUSIVE_AREA_7();
        Position_Byte = (ipduGroupId >> COM_GET_BYTEINX_SHIFT_VALUE);
        Position_Bit = (uint8)(ipduGroupId % COM_GET_BITPOS_RES_VALUE);

        tempByte = (uint8)(((uint8)1) << Position_Bit);

        if(FALSE == bitval)
        {
            tempByte = (uint8)~tempByte;
            ipduGroupVector[Position_Byte] &= tempByte;
        }
        else
        {
            ipduGroupVector[Position_Byte] |= tempByte;
        }

        SchM_Exit_Com_COM_EXCLUSIVE_AREA_7();
    }

}
#if(STD_ON == COM_RX_TIMEOUT_MONITOR)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Com_IsPduDMEnable_Internal
*
* Description:   This interface is used to check if the PduDM can be enabled
*
* Inputs:        pduId
*
* Outputs:       boolean
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(boolean, COM_CODE) Com_IsPduDMEnable_Internal
(
    PduIdType RxIpduId
)
{
    boolean flag = FALSE;
    Com_IpduGroupIdType grpIdx = (Com_IpduGroupIdType)0;
    PduIdType tmpNum = (PduIdType)0;
    P2CONST(PduIdType, AUTOMATIC, COM_CONST) tmpPtr = NULL_PTR;
    tmpNum = COM_CFG_RXPDU_IN_PDUGRP_NUM(RxIpduId);
    tmpPtr = COM_CFG_RXPDU_IN_PDUGRP_PTR(RxIpduId);
    /* search all pdugroup which contains this pdu, if any one is enable, retuan TRUE(Enable)*/
    for(grpIdx =  (Com_IpduGroupIdType)0; grpIdx < tmpNum; grpIdx++)
    {
        if(TRUE == Com_IpduGroupDMEnableFlag[tmpPtr[grpIdx]])
        {
            flag = TRUE;
            break;
        }
    }
    return flag;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Com_ReceptionDMControl SWS_Com_752
*
* Description:   Used to start or stop rx time out monitor of group's rxPdu
*
* Inputs:        ipduGroupVector
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, COM_CODE) Com_ReceptionDMControl
(
    Com_IpduGroupVector ipduGroupVector
)
{

    Com_IpduGroupIdType GroupIDIndex = (Com_IpduGroupIdType)0;
    PduIdType RxIpduId = (PduIdType)0;
    uint8 Position_Bit = (uint8)0;
    uint16 Position_Byte = (uint16)0;
    uint8 tempByte = (uint8)0;
    boolean tmpPduDMEnableFlag = TRUE;

    if(COM_INIT != Com_InitStateFlag)
    {
        COM_DET_REPORT_ERROR(COMServiceId_ReceptionDMControl, COM_E_UNINIT);
    }
    else if(NULL_PTR == ipduGroupVector)
    {
        COM_DET_REPORT_ERROR(COMServiceId_ReceptionDMControl, COM_E_PARAM_POINTER);
    }
    else
    {
        SchM_Enter_Com_COM_EXCLUSIVE_AREA_8();
        for(GroupIDIndex = (Com_IpduGroupIdType)0; GroupIDIndex < COM_PDU_GROUP_NUM; GroupIDIndex++)
        {
            Position_Byte = (GroupIDIndex >> COM_GET_BYTEINX_SHIFT_VALUE);
            Position_Bit = (uint8)(GroupIDIndex % COM_GET_BITPOS_RES_VALUE);
            tempByte = (uint8)(((uint8)1) << Position_Bit);

            if((uint8)0 != (uint8)(ipduGroupVector[Position_Byte] & tempByte))
            {
                Com_IpduGroupDMEnableFlag[GroupIDIndex] = TRUE;
            }
            else
            {
                Com_IpduGroupDMEnableFlag[GroupIDIndex] = FALSE;
            }
        }
        /*SWS_Com_00534 ignor txPdu of this group*/
        for(RxIpduId = (PduIdType)0; RxIpduId < COM_RXPDU_MAX_NUM; RxIpduId++)
        {
            if((PduIdType)0 != COM_CFG_RXPDU_IN_PDUGRP_NUM(RxIpduId))
            {
                if(TRUE == COM_CFG_RXPDU_MONITOR_FLAG(RxIpduId))
                {
                    /* when pdu stop, time out monitor must be disable*/
                    if(COM_RXPDU_STOP != Com_RxPduState[RxIpduId])
                    {
                        tmpPduDMEnableFlag = Com_IsPduDMEnable_Internal(RxIpduId);
                        /*SWS_Com_00224 486 225 616 617 618 process only when state change*/
                        if(COM_RXPDU_MONITOR_FLAG(RxIpduId) != tmpPduDMEnableFlag)
                        {
                            if(TRUE == tmpPduDMEnableFlag)
                            {
                                COM_RXPDU_MONITOR_FLAG(RxIpduId) = TRUE;
                            }
                            else
                            {
                                COM_RXPDU_MONITOR_FLAG(RxIpduId) = FALSE;
                            }
                            COM_RXPDU_TIMEOUT(RxIpduId) = COM_TIMER_STOP_VAL;
#if (STD_ON == COM_RX_UPDATEBIT_SUPPORT)
                            Com_ResetUpdateRxToTimer(RxIpduId);
#endif
                        }

                    }
                }

            }
        }
        SchM_Exit_Com_COM_EXCLUSIVE_AREA_8();
    }

}
#endif
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Com_IpduGroupControl SWS_Com_00751 792
*
* Description:
*
* Inputs:        ipduGroupVector
*                Initialize
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, COM_CODE) Com_IpduGroupControl
(
    Com_IpduGroupVector ipduGroupVector,
    boolean Initialize
)
{

    Com_IpduGroupIdType GroupIDIndex = (Com_IpduGroupIdType)0;
    uint8 Position_Bit = (uint8)0;
    uint16 Position_Byte = (uint16)0;
    PduIdType pduIndex = (PduIdType)0;
    PduIdType pduId = (PduIdType)0;
    uint8 tempByte = (uint8)0;

    if(COM_INIT != Com_InitStateFlag)
    {
        COM_DET_REPORT_ERROR(COMServiceId_IpduGroupControl, COM_E_UNINIT);
    }
    else if(NULL_PTR == ipduGroupVector)
    {
        COM_DET_REPORT_ERROR(COMServiceId_IpduGroupControl, COM_E_PARAM_POINTER);
    }
    else
    {
        SchM_Enter_Com_COM_EXCLUSIVE_AREA_8();
        /*
         * first process stop -> start group 
         * 2nd  process start -> stop group 
         * this order make sure that if txpdu keep start in this call cycle,  nothing will affect this txpdu 
         */
        /* if group state not change,  do nothing */

        for(GroupIDIndex = (Com_IpduGroupIdType)0; GroupIDIndex < COM_PDU_GROUP_NUM; GroupIDIndex++)
        {
            Position_Byte = (GroupIDIndex >> COM_GET_BYTEINX_SHIFT_VALUE);
            Position_Bit = (uint8)(GroupIDIndex % COM_GET_BITPOS_RES_VALUE);
            tempByte = (uint8)(((uint8)1) << Position_Bit);

            /* if group state switch from 0 to 1,  call Com_IpduGroupStart */
            if(((uint8)0 != (uint8)(ipduGroupVector[Position_Byte] & tempByte)) && (FALSE == Com_IpduGroupStartFlag[GroupIDIndex]))
            {
                Com_IpduGroupStart_Internal(GroupIDIndex, Initialize);
            }

            
        }

        for(GroupIDIndex = (Com_IpduGroupIdType)0; GroupIDIndex < COM_PDU_GROUP_NUM; GroupIDIndex++)
        {
            Position_Byte = (GroupIDIndex >> COM_GET_BYTEINX_SHIFT_VALUE);
            Position_Bit = (uint8)(GroupIDIndex % COM_GET_BITPOS_RES_VALUE);
            tempByte = (uint8)(((uint8)1) << Position_Bit);

            /* if group state switch from 1 to 0,  call Com_IpduGroupStop */
            if(((uint8)0 == (uint8)(ipduGroupVector[Position_Byte] & tempByte)) && (TRUE == Com_IpduGroupStartFlag[GroupIDIndex]))
            {
                Com_IpduGroupStop_Internal(GroupIDIndex);
            }
           
        }

        SchM_Exit_Com_COM_EXCLUSIVE_AREA_8();
    }

}
#endif/*#if (STD_ON == COM_IPDU_GROUP_FUN)*/





#if (STD_ON == COM_IPDU_GROUP_FUN)
#if (STD_ON == COM_GROUP_API_R3_SUPPORT)

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Com_IpduGroupStart SWS_Com_00751 792
*
* Description:   start target group and keep other group unchange
*
* Inputs:        IpduGroupId
*                Initialize
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, COM_CODE) Com_IpduGroupStart
(
    Com_IpduGroupIdType IpduGroupId,
    boolean Initialize
)
{
    if(COM_INIT != Com_InitStateFlag)
    {
        COM_DET_REPORT_ERROR(COMServiceId_StartGroup, COM_E_UNINIT);
    }
    else if(IpduGroupId >= COM_PDU_GROUP_NUM)
    {
        COM_DET_REPORT_ERROR(COMServiceId_StartGroup, COM_E_PARAM);
    }
    else
    {
        SchM_Enter_Com_COM_EXCLUSIVE_AREA_8();

        Com_IpduGroupStart_Internal(IpduGroupId, Initialize);
        
        SchM_Exit_Com_COM_EXCLUSIVE_AREA_8();

    }

}



/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Com_IpduGroupStop SWS_Com_00751 792
*
* Description:   stop target group and keep other group unchange
*
* Inputs:        IpduGroupId
*
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, COM_CODE) Com_IpduGroupStop
(
    Com_IpduGroupIdType IpduGroupId
)
{
    if(COM_INIT != Com_InitStateFlag)
    {
        COM_DET_REPORT_ERROR(COMServiceId_StopGroup, COM_E_UNINIT);
    }
    else if(IpduGroupId >= COM_PDU_GROUP_NUM)
    {
        COM_DET_REPORT_ERROR(COMServiceId_StopGroup, COM_E_PARAM);
    }
    else
    {
        SchM_Enter_Com_COM_EXCLUSIVE_AREA_8();

        Com_IpduGroupStop_Internal(IpduGroupId);

        SchM_Exit_Com_COM_EXCLUSIVE_AREA_8();

    }

}


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Com_GetIpduGroupState 
*
* Description:   return start or stop state of IpduGroup
*
* Inputs:        IpduGroupId
*
*
* Outputs:       boolean
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(boolean, COM_CODE) Com_GetIpduGroupState
(
    Com_IpduGroupIdType IpduGroupId
)
{
    boolean flag = FALSE;


    if(COM_INIT != Com_InitStateFlag)
    {
        COM_DET_REPORT_ERROR(COMServiceId_GetIpduGroupState, COM_E_UNINIT);
    }
    else if(IpduGroupId >= COM_PDU_GROUP_NUM)
    {
        COM_DET_REPORT_ERROR(COMServiceId_GetIpduGroupState, COM_E_PARAM);
    }
    else
    {
        flag = Com_IpduGroupStartFlag[IpduGroupId];
    }

    return flag;
}



/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Com_EnableReceptionDM
*
* Description:   Used to start rx time out monitor of group's rxPdu
*
* Inputs:        IpduGroupId
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
#if(STD_ON == COM_RX_TIMEOUT_MONITOR)
FUNC(void, COM_CODE) Com_EnableReceptionDM
(
    Com_IpduGroupIdType IpduGroupId
)
{

    PduIdType RxIpduIdIndex = (PduIdType)0;
    PduIdType RxIpduId = (PduIdType)0;

    if(COM_INIT != Com_InitStateFlag)
    {
        COM_DET_REPORT_ERROR(COMServiceId_StartRXDMGroup, COM_E_UNINIT);
    }
    else if(IpduGroupId >= COM_PDU_GROUP_NUM)
    {
        COM_DET_REPORT_ERROR(COMServiceId_StartRXDMGroup, COM_E_PARAM);
    }
    else
    {


        SchM_Enter_Com_COM_EXCLUSIVE_AREA_8();
        if((PduIdType)0 != COM_CFG_RX_PDUGROUP_NUM(IpduGroupId))
        {
            Com_IpduGroupDMEnableFlag[IpduGroupId] = TRUE;
            /*SWS_Com_00534 ignor txPdu of this group*/
            for(RxIpduIdIndex = (PduIdType)0;
                    RxIpduIdIndex < COM_CFG_RX_PDUGROUP_NUM(IpduGroupId);
                    RxIpduIdIndex++)
            {
                RxIpduId = COM_CFG_RX_PDUGROUP_PTR(IpduGroupId)[RxIpduIdIndex];

                if(TRUE == COM_CFG_RXPDU_MONITOR_FLAG(RxIpduId))
                {
                    /* when pdu stop, time out monitor must be disable*/
                    if(COM_RXPDU_STOP != Com_RxPduState[RxIpduId])
                    {
                        /*SWS_Com_00224 486 225 616 617 618 process only when state change*/
                        if(COM_RXPDU_MONITOR_FLAG(RxIpduId) != TRUE)
                        {
                            COM_RXPDU_MONITOR_FLAG(RxIpduId) = TRUE;
                            COM_RXPDU_TIMEOUT(RxIpduId) = COM_TIMER_STOP_VAL;
#if (STD_ON == COM_RX_UPDATEBIT_SUPPORT)
                            Com_ResetUpdateRxToTimer(RxIpduId);
#endif
                        }

                    }
                }

            }
        }
        SchM_Exit_Com_COM_EXCLUSIVE_AREA_8();
    }

}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Com_DisableReceptionDM
*
* Description:   Used to stOP rx time out monitor of group's rxPdu
*
* Inputs:        IpduGroupId
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, COM_CODE) Com_DisableReceptionDM
(
    Com_IpduGroupIdType IpduGroupId
)
{

    PduIdType RxIpduIdIndex = (PduIdType)0;
    PduIdType RxIpduId = (PduIdType)0;
    boolean tmpPduDMEnableFlag = TRUE;
    if(COM_INIT != Com_InitStateFlag)
    {
        COM_DET_REPORT_ERROR(COMServiceId_StopRXDMGroup, COM_E_UNINIT);
    }
    else if(IpduGroupId >= COM_PDU_GROUP_NUM)
    {
        COM_DET_REPORT_ERROR(COMServiceId_StopRXDMGroup, COM_E_PARAM);
    }
    else
    {


        SchM_Enter_Com_COM_EXCLUSIVE_AREA_8();
        if((PduIdType)0 != COM_CFG_RX_PDUGROUP_NUM(IpduGroupId))
        {
            Com_IpduGroupDMEnableFlag[IpduGroupId] = FALSE;
            /*SWS_Com_00534 ignor txPdu of this group*/
            for(RxIpduIdIndex = (PduIdType)0;
                    RxIpduIdIndex < COM_CFG_RX_PDUGROUP_NUM(IpduGroupId);
                    RxIpduIdIndex++)
            {
                RxIpduId = COM_CFG_RX_PDUGROUP_PTR(IpduGroupId)[RxIpduIdIndex];
                if(TRUE == COM_CFG_RXPDU_MONITOR_FLAG(RxIpduId))
                {
                    /* when pdu stop, time out monitor must be disable*/
                    if(COM_RXPDU_STOP != Com_RxPduState[RxIpduId])
                    {
                        tmpPduDMEnableFlag = Com_IsPduDMEnable_Internal(RxIpduId);
                        /*SWS_Com_00224 486 225 616 617 618 process only when state change*/
                        if((COM_RXPDU_MONITOR_FLAG(RxIpduId) != FALSE) && (tmpPduDMEnableFlag == FALSE))
                        {
                            COM_RXPDU_MONITOR_FLAG(RxIpduId) = FALSE;
                            COM_RXPDU_TIMEOUT(RxIpduId) = COM_TIMER_STOP_VAL;
#if (STD_ON == COM_RX_UPDATEBIT_SUPPORT)
                            Com_ResetUpdateRxToTimer(RxIpduId);
#endif
                        }
                    }
                }

            }
        }
        SchM_Exit_Com_COM_EXCLUSIVE_AREA_8();
    }
}


#endif
#endif
#endif


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Com_MainFunctionRouteSignals SWS_Com_00400
*
* Description:   process signal routing of com
*
* Inputs:        None
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, COM_CODE) Com_MainFunctionRouteSignals
(
    void
)
{

#if (STD_ON == COM_GW_FUN)
    Com_SignalIdType GWSigIndex = (Com_SignalIdType)0;
#endif

    if(COM_INIT != Com_InitStateFlag)/*SWS_Com_00666*/
    {
        COM_DET_REPORT_ERROR(COMServiceId_MainFunctionRouteSignals, COM_E_UNINIT);
    }
    else
    {
#if (STD_ON == COM_GW_FUN)
        for(GWSigIndex = (Com_SignalIdType)0; GWSigIndex < COM_GWSIG_NUM; GWSigIndex++)
        {
            if(TRUE == Com_GWSigFlag[GWSigIndex])
            {
                SchM_Enter_Com_COM_EXCLUSIVE_AREA_5();
                /*SWS_Com_00377 357 359 466 539*/
                Com_GWSigFlag[GWSigIndex] = FALSE;
                if(NULL_PTR != COM_CFG_GWPDU_INFO[GWSigIndex])
                {
                    COM_CFG_GWPDU_INFO[GWSigIndex]();
                }
                SchM_Exit_Com_COM_EXCLUSIVE_AREA_5();
            }
        }
#endif
    }
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Com_GetVersionInfo  SWS_Com_00426
*
* Description:   This service returns the version information of the called
*                CAN Interface module
*
* Inputs:        VersionInfo  Pointer to where to store the version information
*                             of this module.DLC and pointer to CAN L-SDU buffer
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
#if (STD_ON == COM_PUBLIC_VERSION_INFO_API)
FUNC(void, COM_CODE) Com_GetVersionInfo
(
    P2VAR(Std_VersionInfoType, AUTOMATIC, COM_APPL_DATA) VersionInfo
)
{

    if(NULL_PTR == VersionInfo)
    {
        COM_DET_REPORT_ERROR(COMServiceId_GetVersionInfo, COM_E_PARAM_POINTER);
    }
    else
    {
        VersionInfo->vendorID = COM_VENDOR_ID;
        VersionInfo->moduleID = COM_MODULE_ID;

        VersionInfo->sw_major_version = (uint8)COM_SW_MAJOR_VERSION;
        VersionInfo->sw_minor_version = (uint8)COM_SW_MINOR_VERSION;
        VersionInfo->sw_patch_version = (uint8)COM_SW_PATCH_VERSION;
    }
}
#endif






/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Com_SendSignalGroup SWS_Com_00197
*
* Description:   This service updates the signal object identified by
*                SignalId with the signal referenced by the SignalDataPtr
*                parameter
*
* Inputs:        SignalId: Signal handle
*                SignalDataPtr: Reference to the Signal data to be transmitted
*
* Outputs:       E_OK:                      service has been accepted
*                COM_SERVICE_NOT_AVAILABLE: corresponding I-PDU group was
*                                           stopped
*                COM_BUSY:                  in case the TP-Buffer is lock for
                                            large data type handling
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(uint8, COM_CODE) Com_SendSignalGroup
(
    Com_SignalGroupIdType SignalGroupId
)
{
    uint8 result = COM_SERVICE_NOT_AVAILABLE;/* return not available when det err*/

#if(STD_ON == COM_TX_SIGNAL_GROUP_SUPPORT)
    PduIdType TxIpduId = (PduIdType)0;
    Com_SignalIdType GrpSigIndex = (Com_SignalIdType)0;
    P2VAR(void, AUTOMATIC, COM_VAR) destDataPtr = NULL_PTR;
    PduLengthType length = (PduLengthType)0;
#if(STD_OFF == COM_TXMODE_PERIODIC_ONLY)
    boolean changeflag = FALSE;
#endif
#endif

    if(COM_INIT != Com_InitStateFlag)
    {
        COM_DET_REPORT_ERROR(COMServiceId_SendSignalGroup, COM_E_UNINIT);
    }
#if(STD_ON == COM_TX_SIGNAL_GROUP_SUPPORT)
    else if(SignalGroupId >= COM_TXSIG_GROUP_NUM)
    {
        COM_DET_REPORT_ERROR(COMServiceId_SendSignalGroup, COM_E_PARAM);
    }
    else if(COM_CFG_TXSIGGRP_SUPPORT_ARRAY(SignalGroupId) == TRUE)
    {
        COM_DET_REPORT_ERROR(COMServiceId_SendSignalGroup, COM_E_PARAM);
    }
    else
    {

        TxIpduId = COM_CFG_TXSIGGRP_PDUID(SignalGroupId);

        if((COM_TXPDU_START_BUSY == Com_TxPduState[TxIpduId]) && (TRUE == COM_CFG_TXPDU_IS_TP_PDU(TxIpduId)))
        {
            result = COM_BUSY;
        }
        else
        {

            SchM_Enter_Com_COM_EXCLUSIVE_AREA_0();
            for(GrpSigIndex = COM_CFG_TXSIGGRP_SIGSTART(SignalGroupId); GrpSigIndex <= COM_CFG_TXSIGGRP_SIGSTOP(SignalGroupId); GrpSigIndex++)
            {

                destDataPtr = COM_CFG_TXSIG_GROUP_TEMP_BUF(GrpSigIndex);
                length = COM_CFG_TXSIG_LENGTH(GrpSigIndex);

#if(STD_ON == COM_TX_DYN_PDU_SUPPORT)
                if(COM_CFG_TXSIG_TYPE(GrpSigIndex) == COM_SIG_DYN)
                {
                    length = *COM_CFG_TXSIG_GROUP_TEMPLENGTH_PTR(GrpSigIndex);
                    COM_TXPDU_DYN_LENGTH(TxIpduId) = length + COM_CFG_TXSIG_START_BYTE_INDEX(GrpSigIndex);
                }
#endif

#if(STD_ON == COM_TXSIG_ON_CHANGE_SUPPORT)
                if(COM_CFG_TXSIG_TRANSPROPERTY(GrpSigIndex) >= COM_TRIGGERED_ON_CHANGE)
                {
                    if(FALSE == changeflag)
                    {
                        changeflag = COM_CFG_TXSIG_CHECKCHANGE_SIG_FUN(GrpSigIndex)(TxIpduId, GrpSigIndex, destDataPtr, length);
                    }
                }
#endif

#if(STD_ON == COM_TX_FILTER_SUPPORT)
                Com_TxSignalFilter(GrpSigIndex, destDataPtr);
#endif

                COM_CFG_TXSIG_WRITE_SIG_FUN(GrpSigIndex)(destDataPtr, COM_CFG_TXPDU_DATA_PTR(TxIpduId), length);

#if(STD_ON == COM_TXMODE_IFACTIVE_SUPPORT)
                Com_CheckTxSigIfActive(TxIpduId, GrpSigIndex,destDataPtr, COM_CFG_TXSIG_INACTIVE_VALUE_PTR(GrpSigIndex));
#endif


            }

#if(COM_TX_UPDATEBIT_SUPPORT == STD_ON)
            /* set update bit if configured*/
            if(COM_INVALID_SIG_INDEX != COM_CFG_TXSIGGRP_UPDATEBIT_INDEX(SignalGroupId))
            {
                Com_SetSigUpdateBit(TxIpduId, COM_CFG_TXSIGGRP_UPDATEBIT_INDEX(SignalGroupId));
            }
#endif

            /* this Asr req, when pdu is stop, data canbe updated, but return COM_SERVICE_NOT_AVAILABLE*/
            /*SWS_Com_334 dont save trigger when stop*/
            if(COM_TXPDU_STOP != Com_TxPduState[TxIpduId])
            {
#if(STD_OFF == COM_TXMODE_PERIODIC_ONLY)
                Com_SetIpduTrigRepFlag(COM_CFG_TXSIGGRP_TRPROP(SignalGroupId), TxIpduId, changeflag);
#endif
                result = E_OK;
            }


            SchM_Exit_Com_COM_EXCLUSIVE_AREA_0();
        }

    }
#endif/*#if(STD_ON == COM_TXPDU_FUN)*/


    return  result;

}




/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Com_InvalidateSignalGroup SWS_Com_00557
*
* Description:   This service updates all group signal to invalid value
* Inputs:        SignalGroupId: Signal group handle
*
* Outputs:       E_OK:                      service has been accepted
*                COM_SERVICE_NOT_AVAILABLE: corresponding I-PDU group was
*                                           stopped
*                COM_BUSY:                  in case the TP-Buffer is lock for
                                            large data type handling
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(uint8, COM_CODE) Com_InvalidateSignalGroup
(
    Com_SignalGroupIdType SignalGroupId
)
{


    uint8 result = COM_SERVICE_NOT_AVAILABLE;/* return not available when det err*/
#if((STD_ON == COM_TX_SIGNAL_GROUP_SUPPORT) && (STD_ON == COM_TX_INVALID_SUPPORT))
    PduIdType TxIpduId = (PduIdType)0;
    Com_SignalIdType GrpSigIndex = (Com_SignalIdType)0;
    P2VAR(void, AUTOMATIC, COM_VAR) destDataPtr = NULL_PTR;
    P2CONST(void, AUTOMATIC, COM_CONST) srcDataPtr = NULL_PTR;
    PduLengthType length = (PduLengthType)0;
#if(STD_OFF == COM_TXMODE_PERIODIC_ONLY)
    boolean changeflag = FALSE;
#endif

#endif


    if(COM_INIT != Com_InitStateFlag)
    {
        COM_DET_REPORT_ERROR(COMServiceId_InvalidateSignalGroup, COM_E_UNINIT);
    }
#if((STD_ON == COM_TX_SIGNAL_GROUP_SUPPORT) && (STD_ON == COM_TX_INVALID_SUPPORT))
    else if(SignalGroupId >= COM_TXSIG_GROUP_NUM)
    {
        COM_DET_REPORT_ERROR(COMServiceId_InvalidateSignalGroup, COM_E_PARAM);
    }
    else if(FALSE == COM_CFG_TXSIGGRP_HAS_INVALID_VAL(SignalGroupId))
    {
        COM_DET_REPORT_ERROR(COMServiceId_InvalidateSignalGroup, COM_E_PARAM);
    }

    /* this api support array signal group*/
    else
    {
        TxIpduId = COM_CFG_TXSIGGRP_PDUID(SignalGroupId);

        if(COM_TXPDU_START_BUSY == Com_TxPduState[TxIpduId])
        {
            result = COM_BUSY;
        }
        else
        {

            SchM_Enter_Com_COM_EXCLUSIVE_AREA_0();
            for(GrpSigIndex = COM_CFG_TXSIGGRP_SIGSTART(SignalGroupId); GrpSigIndex <= COM_CFG_TXSIGGRP_SIGSTOP(SignalGroupId); GrpSigIndex++)
            {
                if(NULL_PTR != COM_CFG_TXSIG_INVALID_VALUE_PTR(GrpSigIndex))
                {
                    destDataPtr = COM_CFG_TXSIG_GROUP_TEMP_BUF(GrpSigIndex);
                    srcDataPtr = COM_CFG_TXSIG_INVALID_VALUE_PTR(GrpSigIndex);
                    length = COM_CFG_TXSIG_LENGTH(GrpSigIndex);
#if(STD_ON == COM_TX_DYN_PDU_SUPPORT)
                    if(COM_CFG_TXSIG_TYPE(GrpSigIndex) == COM_SIG_DYN)
                    {
                        length = COM_CFG_TXSIG_INVALID_VALUE_LEN(GrpSigIndex);
                        COM_TXPDU_DYN_LENGTH(TxIpduId) = length + COM_CFG_TXSIG_START_BYTE_INDEX(GrpSigIndex);
                    }
#endif

#if(STD_ON == COM_TXSIG_ON_CHANGE_SUPPORT)
                    if(COM_CFG_TXSIG_TRANSPROPERTY(GrpSigIndex) >= COM_TRIGGERED_ON_CHANGE)
                    {
                        changeflag = COM_CFG_TXSIG_CHECKCHANGE_SIG_FUN(GrpSigIndex)(TxIpduId, GrpSigIndex, destDataPtr, length);
                    }
#endif

#if(STD_ON == COM_TX_FILTER_SUPPORT)
                    Com_TxSignalFilter(GrpSigIndex, srcDataPtr);
#endif
                    COM_CFG_TXSIG_WRITE_SIG_FUN(GrpSigIndex)(srcDataPtr, COM_CFG_TXPDU_DATA_PTR(TxIpduId), length);
                    if((NULL_PTR != COM_CFG_TXSIG_COPY_SIG_FUN(GrpSigIndex)) && (NULL_PTR != destDataPtr))
                    {
                        COM_CFG_TXSIG_COPY_SIG_FUN(GrpSigIndex)(srcDataPtr, destDataPtr, length);
                    }

#if(STD_ON == COM_TXMODE_IFACTIVE_SUPPORT)
                    Com_CheckTxSigIfActive(TxIpduId, GrpSigIndex,srcDataPtr, COM_CFG_TXSIG_INACTIVE_VALUE_PTR(GrpSigIndex));
#endif

                }

            }

#if(COM_TX_UPDATEBIT_SUPPORT == STD_ON)
            /* set update bit if configured*/
            if(COM_INVALID_SIG_INDEX != COM_CFG_TXSIGGRP_UPDATEBIT_INDEX(SignalGroupId))
            {
                Com_SetSigUpdateBit(TxIpduId, COM_CFG_TXSIGGRP_UPDATEBIT_INDEX(SignalGroupId));
            }
#endif

            /* this Asr req, when pdu is stop, data canbe updated, but return COM_SERVICE_NOT_AVAILABLE*/
            /*SWS_Com_334 dont save trigger when stop*/
            if(COM_TXPDU_STOP != Com_TxPduState[TxIpduId])
            {
#if(STD_OFF == COM_TXMODE_PERIODIC_ONLY)
                Com_SetIpduTrigRepFlag(COM_CFG_TXSIGGRP_TRPROP(SignalGroupId), TxIpduId, changeflag);
#endif
                result = E_OK;
            }


            SchM_Exit_Com_COM_EXCLUSIVE_AREA_0();
        }

    }
#endif/*#if(STD_ON == COM_TXPDU_FUN)*/


    return  result;

}





/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Com_SendSignalGroupArray SWS_Com_00851
*
* Description:   This service send signal group data in array type
*
* Inputs:        SignalGroupId: Signal group handle
*                SignalGroupArrayPtr: Reference to the Signal data to be read
*
* Outputs:       E_OK:                      service has been accepted
*                COM_SERVICE_NOT_AVAILABLE: corresponding I-PDU group was
*                                           stopped
*                COM_BUSY:                  in case the TP-Buffer is lock for
                                            large data type handling
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/

#if((STD_ON == COM_Enable_SignalGroupArrayApi) && (STD_ON == COM_TX_SIGNAL_GROUP_SUPPORT))
FUNC(uint8, COM_CODE) Com_SendSignalGroupArray
(
    Com_SignalGroupIdType SignalGroupId,
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA)  SignalGroupArrayPtr
)
{
    uint8 result = COM_SERVICE_NOT_AVAILABLE;/* return not available when det err*/
    P2VAR(uint8, AUTOMATIC, COM_VAR) destDataPtr = NULL_PTR;
    PduIdType TxIpduId = (PduIdType)0;



    if(COM_INIT != Com_InitStateFlag)
    {
        COM_DET_REPORT_ERROR(COMServiceId_SendSignalGroupArray, COM_E_UNINIT);
    }
    else if(SignalGroupId >= COM_TXSIG_GROUP_NUM)
    {
        COM_DET_REPORT_ERROR(COMServiceId_SendSignalGroupArray, COM_E_PARAM);
    }
    else if(SignalGroupArrayPtr == NULL_PTR)
    {
        COM_DET_REPORT_ERROR(COMServiceId_SendSignalGroupArray, COM_E_PARAM);
    }
    else if(COM_CFG_TXSIGGRP_SUPPORT_ARRAY(SignalGroupId) == FALSE)
    {
        COM_DET_REPORT_ERROR(COMServiceId_SendSignalGroupArray, COM_E_PARAM);
    }
    else
    {
        TxIpduId = COM_CFG_TXSIGGRP_PDUID(SignalGroupId);
        if((COM_TXPDU_START_BUSY == Com_TxPduState[TxIpduId]) && (TRUE == COM_CFG_TXPDU_IS_TP_PDU(TxIpduId)))
        {
            result = COM_BUSY;
        }
        else
        {
            SchM_Enter_Com_COM_EXCLUSIVE_AREA_0();
            destDataPtr = &((uint8 *)COM_CFG_TXPDU_DATA_PTR(TxIpduId))[COM_CFG_TXSIGGRP_STARTBYTE(SignalGroupId)];

            Bsw_MemCpy(destDataPtr, SignalGroupArrayPtr, (uint32)COM_CFG_TXSIGGRP_SIZE(SignalGroupId));

            /* No filter and onchange check not support this version */

#if(COM_TX_UPDATEBIT_SUPPORT == STD_ON)
            /* set update bit if configured*/
            if(COM_INVALID_SIG_INDEX != COM_CFG_TXSIGGRP_UPDATEBIT_INDEX(SignalGroupId))
            {
                Com_SetSigUpdateBit(TxIpduId, COM_CFG_TXSIGGRP_UPDATEBIT_INDEX(SignalGroupId));
            }
#endif

            /* this Asr req, when pdu is stop, data canbe updated, but return COM_SERVICE_NOT_AVAILABLE*/
            /*SWS_Com_334 dont save trigger when stop*/
            if(COM_TXPDU_STOP != Com_TxPduState[TxIpduId])
            {
#if(STD_OFF == COM_TXMODE_PERIODIC_ONLY)
                Com_SetIpduTrigRepFlag(COM_CFG_TXSIGGRP_TRPROP(SignalGroupId), TxIpduId, FALSE);
#endif
                result = E_OK;
            }
            SchM_Exit_Com_COM_EXCLUSIVE_AREA_0();

        }

    }

    return result;


}
#endif





/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Com_ReceiveSignalGroup SWS_Com_00201
*
* Description:   This service updates the signal object identified by
*                SignalId with the signal referenced by the SignalDataPtr
*                parameter
*
* Inputs:        SignalId: Signal handle
*                SignalDataPtr: Reference to the Signal data to be transmitted
*
* Outputs:       E_OK:                      service has been accepted
*                COM_SERVICE_NOT_AVAILABLE: corresponding I-PDU group was
*                                           stopped
*                COM_BUSY:                  in case the TP-Buffer is lock for
                                            large data type handling
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(uint8, COM_CODE) Com_ReceiveSignalGroup
(
    Com_SignalGroupIdType SignalGroupId
)
{
    uint8 result = COM_SERVICE_NOT_AVAILABLE;/* return not available when det err*/
#if(STD_ON == COM_RX_SIGNAL_GROUP_SUPPORT)
    PduIdType RxIpduId = (PduIdType)0;
    Com_SignalIdType GrpSigIndex = (Com_SignalIdType)0;
    P2VAR(void, AUTOMATIC, COM_VAR) destDataPtr = NULL_PTR;
    PduLengthType length = (PduLengthType)0;
#endif

    if(COM_INIT != Com_InitStateFlag)
    {
        COM_DET_REPORT_ERROR(COMServiceId_ReceiveSignalGroup, COM_E_UNINIT);
    }
#if(STD_ON == COM_RX_SIGNAL_GROUP_SUPPORT)
    else if(SignalGroupId >= COM_RXSIG_GROUP_NUM)
    {
        COM_DET_REPORT_ERROR(COMServiceId_ReceiveSignalGroup, COM_E_PARAM);
    }
    else if(COM_CFG_RXSIGGRP_SUPPORT_ARRAY(SignalGroupId) == TRUE)
    {
        COM_DET_REPORT_ERROR(COMServiceId_ReceiveSignalGroup, COM_E_PARAM);
    }
    else
    {
        RxIpduId = COM_CFG_RXSIGGRP_PDUID(SignalGroupId);
        /* dont need report busy , as copy process is protected by Area2
           and always read old data
        */

        SchM_Enter_Com_COM_EXCLUSIVE_AREA_2();
        for(GrpSigIndex = COM_CFG_RXSIGGRP_SIGSTART(SignalGroupId); GrpSigIndex <= COM_CFG_RXSIGGRP_SIGSTOP(SignalGroupId); GrpSigIndex++)
        {
            destDataPtr = COM_CFG_RXSIG_GROUP_TEMP_BUF(GrpSigIndex);
            length = COM_CFG_RXSIG_LENGTH(GrpSigIndex);

#if(STD_ON == COM_RX_DYN_PDU_SUPPORT)
            if(COM_SIG_DYN == COM_CFG_RXSIG_TYPE(GrpSigIndex))
            {
                length = COM_RXPDU_DYN_LENGTH(RxIpduId) - COM_CFG_RXSIG_START_BYTE_INDEX(GrpSigIndex);
                *COM_CFG_RXSIG_GROUP_TEMPLENGTH_PTR(GrpSigIndex) = length;
            }
#endif

            COM_CFG_RXSIG_READ_SIG_FUN(GrpSigIndex)(destDataPtr, COM_CFG_RXPDU_DATA_PTR(RxIpduId), length);
        }
        SchM_Exit_Com_COM_EXCLUSIVE_AREA_2();

        /*
           when stop , read old data but return COM_SERVICE_NOT_AVAILABLE, no det err
           See Page54 Table3
        */

        if(COM_RXPDU_STOP != Com_RxPduState[RxIpduId])
        {
            result = E_OK;
        }

    }
#endif
    return result;

}


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Com_ReceiveSignalGroupArray SWS_Com_00854
*
* Description:   This service copy signal group data in array type
*
* Inputs:        SignalGroupId: Signal group handle
*                SignalGroupArrayPtr: Reference to the Signal data to be read
*
* Outputs:       E_OK:                      service has been accepted
*                COM_SERVICE_NOT_AVAILABLE: corresponding I-PDU group was
*                                           stopped
*                COM_BUSY:                  in case the TP-Buffer is lock for
                                            large data type handling
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
#if((STD_ON == COM_Enable_SignalGroupArrayApi) && (STD_ON == COM_RX_SIGNAL_GROUP_SUPPORT))
FUNC(uint8, COM_CODE) Com_ReceiveSignalGroupArray
(
    Com_SignalGroupIdType SignalGroupId,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA)  SignalGroupArrayPtr
)
{
    uint8 result = COM_SERVICE_NOT_AVAILABLE;/* return not available when det err*/
    P2VAR(uint8, AUTOMATIC, COM_VAR) srcDataPtr = NULL_PTR;
    PduIdType RxIpduId = (PduIdType)0;



    if(COM_INIT != Com_InitStateFlag)
    {
        COM_DET_REPORT_ERROR(COMServiceId_ReceiveSignalGroupArray, COM_E_UNINIT);
    }
    else if(SignalGroupId >= COM_RXSIG_GROUP_NUM)
    {
        COM_DET_REPORT_ERROR(COMServiceId_ReceiveSignalGroupArray, COM_E_PARAM);
    }
    else if(SignalGroupArrayPtr == NULL_PTR)
    {
        COM_DET_REPORT_ERROR(COMServiceId_ReceiveSignalGroupArray, COM_E_PARAM);
    }
    else if(COM_CFG_RXSIGGRP_SUPPORT_ARRAY(SignalGroupId) == FALSE)
    {
        COM_DET_REPORT_ERROR(COMServiceId_ReceiveSignalGroupArray, COM_E_PARAM);
    }
    else
    {
        /* dont need report busy , as copy process is protected by Area2
           and always read old data
        */

        RxIpduId = COM_CFG_RXSIGGRP_PDUID(SignalGroupId);
        srcDataPtr = &((uint8 *)COM_CFG_RXPDU_DATA_PTR(RxIpduId))[COM_CFG_RXSIGGRP_STARTBYTE(SignalGroupId)];

        SchM_Enter_Com_COM_EXCLUSIVE_AREA_2();
        Bsw_MemCpy(SignalGroupArrayPtr, srcDataPtr, (uint32)COM_CFG_RXSIGGRP_SIZE(SignalGroupId));
        SchM_Exit_Com_COM_EXCLUSIVE_AREA_2();

        /*
           when stop , read old data but return COM_SERVICE_NOT_AVAILABLE, no det err
           See Page54 Table3
        */

        if(COM_RXPDU_STOP != Com_RxPduState[RxIpduId])
        {
            result = E_OK;
        }

    }

    return result;
}

#endif



#if(STD_ON == COM_TXPDU_FUN)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Com_GetTxIpduState 
*
* Description:   return start or stop state of PDU
*
* Inputs:        TxPduId
*
*
* Outputs:       boolean
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(boolean, COM_CODE) Com_GetTxIpduState
(
     PduIdType TxPduId
)
{
    boolean flag = FALSE;


    if(COM_INIT != Com_InitStateFlag)
    {
        COM_DET_REPORT_ERROR(COMServiceId_GetTxIpduState, COM_E_UNINIT);
    }
    else if(TxPduId >= COM_TXPDU_NUM)
    {
        COM_DET_REPORT_ERROR(COMServiceId_GetTxIpduState, COM_E_PARAM);
    }
    else
    {
        if(COM_TXPDU_STOP != Com_TxPduState[TxPduId])
        {
            flag = TRUE;
        }
    }

    return flag;
}
#endif


#if(STD_ON == COM_RXPDU_FUN)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Com_GetRxIpduState 
*
* Description:   return start or stop state of PDU
*
* Inputs:        RxPduId
*
*
* Outputs:       boolean
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(boolean, COM_CODE) Com_GetRxIpduState
(
     PduIdType RxPduId
)
{
    boolean flag = FALSE;


    if(COM_INIT != Com_InitStateFlag)
    {
        COM_DET_REPORT_ERROR(COMServiceId_GetRxIpduState, COM_E_UNINIT);
    }
    else if(RxPduId >= COM_RXPDU_NUM)
    {
        COM_DET_REPORT_ERROR(COMServiceId_GetRxIpduState, COM_E_PARAM);
    }
    else
    {
        if(COM_RXPDU_STOP != Com_RxPduState[RxPduId])
        {
            flag = TRUE;
        }
    }

    return flag;
}
#endif




#define COM_STOP_SEC_CODE
#include "MemMap.h"

