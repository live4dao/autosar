/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
*   File Name       : EthTSyn.c
********************************************************************************
*   Project/Product : AUTOSAR 4.2
*   Title           : EthTSyn module Source File
*   Author          : Hirain
********************************************************************************
*   Description     : EthTSyn module Source File
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
*   01.00.00    06/03/2021    dongdong.sun   N/A          Original
*   01.00.01    15/06/2021    dongdong.sun   N/A          EAS422_EthTSyn_20210615_01
*   01.00.02    23/08/2022    xin.yang1      N/A          EAS422_EthTSyn_20220823_01
*   01.00.03    11/09/2022    xin.yang1      N/A          EAS422_EthTSyn_20220911_01
*   01.00.04    21/11/2022    xin.yang1      N/A          EAS422_EthTSyn_20221121_01
*   01.00.05    26/12/2022    xin.yang1      N/A          EAS422_EthTSyn_20221226_01
*   01.00.06    23/02/2023    xin.yang1      N/A          EAS422_EthTSyn_20230223_01
*   01.00.07    08/05/2023    zeyu.ren       N/A          Update version.h
*   01.01.00    02/01/2023    yanheng.he     N/A          EAS422_EthTSyn_20240102_01
********************************************************************************
* END_FILE_HDR*/

/*******************************************************************************
*   Includes
*******************************************************************************/
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "Eth.h"
#include "EthIf.h"
#include "EthTSyn.h"
#include "EthTSyn_Cbk.h"
#include "SchM_EthTSyn.h"
#include "Bsw_Common.h"
#include "StbM.h"
#include "EthTrcv_Types.h" //modified by Yibo
#if (STD_ON == ETHTSYN_DEV_ERROR_DETECT)
#include "Det.h"
#endif


/*******************************************************************************
*   Version Check
*******************************************************************************/
#if(STD_ON == ETHTSYN_PRIVATE_VERSION_CHECK)
/* check Version with other import module */


/* check Version with cfg file */
#if ((ETHTSYN_AR_RELEASE_MAJOR_VERSION != ETHTSYN_AR_RELEASE_MAJOR_VERSION_CFG) || \
   (ETHTSYN_AR_RELEASE_MINOR_VERSION != ETHTSYN_AR_RELEASE_MINOR_VERSION_CFG))
#error "AutoSar Version Numbers of EthTSyn and its cfg file are different"
#endif

#if ((ETHTSYN_SW_MAJOR_VERSION != ETHTSYN_SW_MAJOR_VERSION_CFG) || \
   (ETHTSYN_SW_MINOR_VERSION != ETHTSYN_SW_MINOR_VERSION_CFG))
#error "SW Version Numbers of EthTSyn and its cfg file are different"
#endif

#endif/*#if(STD_ON == ETHTSYN_PRIVATE_VERSION_CHECK)*/

/*******************************************************************************
*   Macro define
*******************************************************************************/
/*PRQA S 3432,3410,3206,3119 EOF*/
/*PRQA S 3453,3429,3673,3416 EOF*/
/*PRQA S 3138,3141 EOF*/
/*PRQA S 3383,3384 EOF*/
/*PRQA S 3132,3120,3214 EOF*/
/*PRQA S 315,702,2213 EOF*/
/*PRQA S 791,792 EOF*/
/*PRQA S 4395,3892,3617 EOF*/
/*PRQA S 861,862 EOF*/
/*PRQA S 2790 ++*/
/*PRQA S 790 ++*/
/*PRQA S 4640,4641,4471 EOF*/
/*<errno.h> will not be used*/
/*PRQA S 4119 ++*/
/*cast from float type to int type is necessary*/
#if (STD_ON == ETHTSYN_DEV_ERROR_DETECT)
#define ETHTSYN_DET_REPORT_ERROR(ApiId, errcode)  \
    DET_REPORT_ERROR(ETHTSYN_MODULE_ID, ETHTSYN_INSTANCE_ID, (ApiId), (errcode))
#else
#define ETHTSYN_DET_REPORT_ERROR(ApiId, errcode)
#endif

#define ETHTSYN_SECOND_TO_NANOSECOND                                     ((uint32)1000000000)
#define ETHTSYN_MILLISECOND_TO_NANOSECOND                                ((uint32)1000000)
#define ETHTSYN_SECOND_TO_MILLISECOND                                    ((uint16)1000)
#define ETHTSYN_GET_PDELAYREQ_TX_INTERVAL                                (uint16)((EthTSyn_DefaultCfgPtr->EthTSyn_SlaveCtrlConfigPtr->PdelayReqTxInterval)*((float32)ETHTSYN_SECOND_TO_MILLISECOND/(float32)ETHTSYN_MAINFUNCTION_PERIOD))
#define ETHTSYN_GET_DEFAULT_PDELAY                                       (EthTSyn_DefaultCfgPtr->EthTSyn_SlaveCtrlConfigPtr->DefaultLinkDelay)
#define ETHTSYN_GET_ETHTSYN_CTRL_INDEX(index)							 (EthTSyn_DefaultCfgPtr->EthTSynMappedToEthIfIdxArray[index][0])
#define ETHTSYN_MAPPED_TO_ETHIF_CTRL_IDX(index)                          (EthTSyn_DefaultCfgPtr->EthTSynMappedToEthIfIdxArray[index][1])
#define ETHTSYN_GET_SLAVE_TIMEBASEID                                     (EthTSyn_DefaultCfgPtr->EthTSyn_SlaveCtrlConfigPtr->TimeBaseId)
#define ETHTSYN_GET_SLAVE_PORTNUMBER                                     (EthTSyn_DefaultCfgPtr->EthTSyn_SlaveCtrlConfigPtr->PortNumber)
#if(STD_ON == ETHTSYN_PORT_MASTER_SUPPORT)
#define ETHTSYN_GET_SYNC_TX_INTERVAL                                     (uint16)((EthTSyn_DefaultCfgPtr->EthTSyn_MasterCtrlConfigPtr->SyncTxInterval)*((float32)ETHTSYN_SECOND_TO_MILLISECOND/(float32)ETHTSYN_MAINFUNCTION_PERIOD))
#define ETHTSYN_GET_MASTER_TIMEBASEID                                    (EthTSyn_DefaultCfgPtr->EthTSyn_MasterCtrlConfigPtr->TimeBaseId)
#define ETHTSYN_GET_MASTER_PORTNUMBER                                    (EthTSyn_DefaultCfgPtr->EthTSyn_MasterCtrlConfigPtr->PortNumber)
#define ETHTSYN_GET_MASTER_SYNCTXMSGLOGINTERVAL                          (EthTSyn_DefaultCfgPtr->EthTSyn_MasterCtrlConfigPtr->SyncTxMsgLogInterval)
#define ETHTSYN_GET_FOLLOWUP_OFFSET                                      (uint16)((ETHTSYN_GT_TX_FOLLOWUP_OFFSET)/((uint16)ETHTSYN_MAINFUNCTION_PERIOD))
#define ETHTSYN_TIMESTAMP_SIZE                                           ((uint16)10) 
#define ETHTSYN_PTP_PAYLOADSIZE_SYNC_FUP                                 ((uint16)42) 
#endif
#define ETHTSYN_GET_SLAVE_PDELAYREQTXMSGLOGINTERVAL                      (EthTSyn_DefaultCfgPtr->EthTSyn_SlaveCtrlConfigPtr->PdelayReqTxMsgLogInterval)
#define ETHTSYN_GET_TOTAL_CTRL_NUMBER                                    (uint8)((ETHTSYN_GET_SLAVE_MAX_NUMBER) + (ETHTSYN_GET_MASTER_MAX_NUMBER))
#define ETHTSYN_GET_PTP_MESSAGE_PRIORITY                                 (EthTSyn_DefaultCfgPtr->EthTSyn_MessagePriority)
/*PRQA S 4571 ++*/
/*unsigned short is enough for << 8*/
/*PRQA S 3435,3456 EOF*/
#define ETHTSYN_GET_SEQUENCEID_FROM_RCVDMESSAGE(PTPHeaderPtr)            (uint16)((uint16)(((uint16)PTPHeaderPtr[ETHTSYN_PTP_HEADER_OFFSET_SECQUENCEID_BYTE0]) << (uint16)8) + (uint16)(PTPHeaderPtr[ETHTSYN_PTP_HEADER_OFFSET_SECQUENCEID_BYTE1]))
#define ETHTSYN_CONVERT_ARRAY_TO_TIMESTAMP_NANOSECONDS(BufPtr)           (uint32)((uint32)(((uint32)BufPtr[ETHTSYN_PTP_HEADER_SIZE + (uint16)6]) << (uint32)24) + (uint32)(((uint32)BufPtr[ETHTSYN_PTP_HEADER_SIZE + (uint16)7]) << (uint32)16) + (uint32)(((uint32)BufPtr[ETHTSYN_PTP_HEADER_SIZE + (uint16)8]) << (uint32)8) + (uint32)BufPtr[ETHTSYN_PTP_HEADER_SIZE + (uint16)9])
#define ETHTSYN_CONVERT_ARRAY_TO_TIMESTAMP_SECONDS(BufPtr)               (uint32)((uint32)(((uint32)BufPtr[ETHTSYN_PTP_HEADER_SIZE + (uint16)2]) << (uint32)24) + (uint32)(((uint32)BufPtr[ETHTSYN_PTP_HEADER_SIZE + (uint16)3]) << (uint32)16) + (uint32)(((uint32)BufPtr[ETHTSYN_PTP_HEADER_SIZE + (uint16)4]) << (uint32)8) + (uint32)BufPtr[ETHTSYN_PTP_HEADER_SIZE + (uint16)5])
#define ETHTSYN_CONVERT_ARRAY_TO_TIMESTAMP_SECONDSHI(BufPtr)             (uint16)((uint16)(((uint16)BufPtr[ETHTSYN_PTP_HEADER_SIZE]) << (uint16)8) + ((uint16)BufPtr[ETHTSYN_PTP_HEADER_SIZE + (uint16)1]))
#define ETHTSYN_INVALID_BUFIDX                                           ((uint32)0xFFFFFFFF)
#define ETHTSYN_MAC_ADD_SIZE                                             ((uint8)6)
#define ETHTSYN_PTP_SYNC_PADDING_SIZE                                    ((uint16)2)
#define ETHTSYN_PTP_ETHERNET_FCS_SIZE                                    ((uint16)4)
#define ETHTSYN_SEQUENCEID_MAX                                           ((uint16)0xFFFF)
#define ETHTSYN_PTP_HEADER_SIZE                                          ((uint16)34) 
#define ETHTSYN_PTP_PAYLOADSIZE_SYNC                                     ((uint16)10) 
#define ETHTSYN_PTP_PAYLOADSIZE_PDELAY                                   ((uint16)20) 
#define ETHTSYN_32BIT_UNSIGNED_MAX_VALUE                                 ((uint32)0xFFFFFFFF) 
#define ETHTSYN_NANOSEC_MAX                                              ((uint32)999999999)
#define ETHTSYN_PTP_FRAMETYPE                                            ((Eth_FrameType)0x88F7)
#define ETHTSYN_PTP_HEADER_OFFSET_MSGTYPE                                ((uint8)0) 
#define ETHTSYN_PTP_HEADER_OFFSET_CORRECTIONFIELD_BYTE0                  ((uint8)8) 
#define ETHTSYN_PTP_HEADER_OFFSET_SRCPORTIDENTITY_BYTE0                  ((uint8)20) 
#define ETHTSYN_PTP_HEADER_OFFSET_SECQUENCEID_BYTE0                      ((uint8)30) 
#define ETHTSYN_PTP_HEADER_OFFSET_SECQUENCEID_BYTE1                      ((uint8)31) 

#define ETHTSYN_MASK_DWORD_LOW_WORD_LOW_BYTE                             (uint32)(0x000000FF)
#define ETHTSYN_MASK_DWORD_LOW_WORD_HIGH_BYTE                            (uint32)(0x0000FF00) 
#define ETHTSYN_MASK_DWORD_HIGH_WORD_LOW_BYTE                            (uint32)(0x00FF0000) 
#define ETHTSYN_MASK_DWORD_HIGH_WORD_HIGH_BYTE                           (uint32)(0xFF000000) 
#define ETHTSYN_MASK_WORD_LOW_BYTE                                       (uint16)(0x00FF)
#define ETHTSYN_MASK_WORD_HIGH_BYTE                                      (uint16)(0xFF00)
#define ETHTSYN_MASK_BYTE_LOW_NIBBLE                                     (uint8)(0x0F)

#define ETHTSYN_PTP_HEADER_VALUE_TRANSSPEC                               ((uint8)0x10) 
#define ETHTSYN_PTP_HEADER_VALUE_MSGTYPE_SYNC                            ((uint8)0x00) 
#define ETHTSYN_PTP_HEADER_VALUE_MSGTYPE_PDELAYREQ                       ((uint8)0x02) 
#define ETHTSYN_PTP_HEADER_VALUE_MSGTYPE_PDELAYRESP                      ((uint8)0x03) 
#define ETHTSYN_PTP_HEADER_VALUE_MSGTYPE_SYNCFUP                         ((uint8)0x08) 
#define ETHTSYN_PTP_HEADER_VALUE_MSGTYPE_PDELAYRESPFUP                   ((uint8)0x0A) 
#define ETHTSYN_PTP_HEADER_VALUE_VERSION                                 ((uint8)0x02) 
#define ETHTSYN_PTP_HEADER_VALUE_DOMAINNUMBER                            ((uint8)0x00)  
#define ETHTSYN_PTP_HEADER_VALUE_RESERVED                                ((uint8)0x00)
#if(STD_ON == ETHTSYN_PORT_MASTER_SUPPORT)
#define ETHTSYN_PTP_HEADER_VALUE_FLAG_TWOSTEP                            ((uint16)0x0200)
#define ETHTSYN_PTP_HEADER_VALUE_LOGMSGINTERVAL_RESERVED                 ((uint8)0x7F) 
#define ETHTSYN_PTP_HEADER_VALUE_CONTROL_SYNC                            ((uint8)0x00) 
#define ETHTSYN_PTP_HEADER_VALUE_CONTROL_FUP                             ((uint8)0x02) 
#endif
#define ETHTSYN_PTP_HEADER_VALUE_FLAG_PTPTIMESCALE                       ((uint16)0x0008)
#define ETHTSYN_PTP_HEADER_VALUE_NOFLAGS                                 ((uint16)0x0000) 
#define ETHTSYN_PTP_HEADER_VALUE_SRCPORTIDENTITY_BYTE3                   ((uint8)0xFF) 
#define ETHTSYN_PTP_HEADER_VALUE_SRCPORTIDENTITY_BYTE4                   ((uint8)0xFE) 
#define ETHTSYN_PTP_HEADER_VALUE_CONTROL_PDELAY                          ((uint8)0x05)  

#define ETHTSYN_SYNCFUP_TLV_VALUE_TLVTYPE                                ((uint16)0x0003) 
#define ETHTSYN_SYNCFUP_TLV_VALUE_LENGTH                                 ((uint16)0x001C) 
#define ETHTSYN_SYNCFUP_TLV_VALUE_ORGID_BYTE0                            ((uint8)0x00)  
#define ETHTSYN_SYNCFUP_TLV_VALUE_ORGID_BYTE1                            ((uint8)0x80) 
#define ETHTSYN_SYNCFUP_TLV_VALUE_ORGID_BYTE2                            ((uint8)0xC2) 
#define ETHTSYN_SYNCFUP_TLV_VALUE_ORG_SUBTYPE_BYTE0                      ((uint8)0x00) 
#define ETHTSYN_SYNCFUP_TLV_VALUE_ORG_SUBTYPE_BYTE1                      ((uint8)0x00) 
#define ETHTSYN_SYNCFUP_TLV_VALUE_ORG_SUBTYPE_BYTE2                      ((uint8)0x01) 
#define ETHTSYN_SYNCFUP_TLV_VALUE_GM_TIMEBASE                            ((uint16)0x0001)

#define ETHTSYN_PDELAY_TIMEOUT                                           (())

/*******************************************************************************
*   Local Data Define
*******************************************************************************/

#define ETHTSYN_START_SEC_VAR_INIT_8
#include "EthTSyn_MemMap.h"
STATIC VAR(Std_InitStateType, ETHTSYN_VAR) EthTSyn_InitStatus = STD_UNINITIALIZED;
#define ETHTSYN_STOP_SEC_VAR_INIT_8
#include "EthTSyn_MemMap.h"

#define ETHTSYN_START_SEC_VAR_INIT_16
#include "EthTSyn_MemMap.h"
#if(STD_ON == ETHTSYN_PORT_MASTER_SUPPORT)
STATIC VAR(uint16, ETHTSYN_VAR) EthTSyn_MasterCounter = (uint16)0;
#endif
#if(STD_ON == ETHTSYN_PORT_SLAVE_SUPPORT)
STATIC VAR(uint16, ETHTSYN_VAR) EthTSyn_SlaveCounter = (uint16)0;
#endif
#define ETHTSYN_STOP_SEC_VAR_INIT_16
#include "EthTSyn_MemMap.h"

#define ETHTSYN_START_SEC_VAR_INIT_UNSPECIFIED
#include "EthTSyn_MemMap.h"
STATIC VAR(uint8, ETHTSYN_VAR) SrcMacAddr[ETHTSYN_MAC_ADD_SIZE] = { (uint8)0, (uint8)0, (uint8)0, (uint8)0, (uint8)0, (uint8)0};
STATIC P2CONST(EthTSyn_ConfigType, ETHTSYN_VAR, ETHTSYN_APPL_CONST) EthTSyn_DefaultCfgPtr = NULL_PTR;

#define ETHTSYN_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "EthTSyn_MemMap.h"

#define ETHTSYN_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "EthTSyn_MemMap.h"
#if(STD_ON == ETHTSYN_PORT_MASTER_SUPPORT)
STATIC VAR(EthTSyn_MasterControllerType, ETHTSYN_VAR) EthTSyn_MasterController[ETHTSYN_GET_MASTER_MAX_NUMBER];
#endif
#if(STD_ON == ETHTSYN_PORT_SLAVE_SUPPORT)
STATIC VAR(EthTSyn_SlaveControllerType, ETHTSYN_VAR) EthTSyn_SlaveController[1];
#endif
#define ETHTSYN_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "EthTSyn_MemMap.h"

/*******************************************************************************
*   Local Function Declaration
*******************************************************************************/
#if(STD_ON == ETHTSYN_PORT_MASTER_SUPPORT)
STATIC FUNC(void, ETHTSYN_CODE) EthTSyn_TransmitPTPSyncFrame
(
    uint8 CtrlIdx
);

STATIC FUNC(void, ETHTSYN_CODE) EthTSyn_TransmitPTPSyncFUpFrame
(
    uint8 CtrlIdx
);

STATIC FUNC(void, ETHTSYN_CODE) EthTSyn_TransmitPTPPdelayRespFrame
(
    uint8 CtrlIdx
);

STATIC FUNC(void, ETHTSYN_CODE) EthTSyn_TransmitPTPPdelayRespFupFrame
(
    uint8 CtrlIdx
);
#endif
STATIC FUNC(void, ETHTSYN_CODE) EthTSyn_PaddingPTPHeader
(
    uint8 CtrlIdx,
    P2CONST(EthTSyn_PTPHeaderType, AUTOMATIC, ETHTSYN_APPL_DATA)PTPHeaderPtr, 
    P2VAR(uint8, AUTOMATIC, ETHTSYN_APPL_DATA) CurrentPTPHeaderPtr
);

#if(STD_ON == ETHTSYN_PORT_MASTER_SUPPORT)
STATIC FUNC(void, ETHTSYN_CODE) EthTSyn_ConvertTimeStamp2Array
(
#if(STD_ON == ETHTSYN_HW_TIMESTAMP_SUPPORT)
    P2VAR(Eth_TimeStampType, AUTOMATIC, ETHTSYN_APPL_DATA) TimeStampPtr,
#else
    P2VAR(StbM_TimeStampType, AUTOMATIC, ETHTSYN_APPL_DATA) TimeStampPtr,
#endif
    P2VAR(uint8, AUTOMATIC, ETHTSYN_APPL_DATA) CurrentBufferPtr   
);

STATIC FUNC(void, ETHTSYN_CODE) EthTSyn_PaddingSyncFUpTLV
(
    P2VAR(uint8, AUTOMATIC, ETHTSYN_APPL_DATA) CurrentSyncFUpTLVPtr
);
#endif

STATIC FUNC(Std_ReturnType, ETHTSYN_CODE) EthTSyn_GetTxBuffer
(
    uint8 CtrlIdx,
    uint16 PTPLength,
    P2VAR(Eth_BufIdxType, AUTOMATIC, ETHTSYN_APPL_DATA) BufIdxPtr,
    P2VAR(P2VAR(uint8, AUTOMATIC, AUTOMATIC), AUTOMATIC, ETHTSYN_APPL_DATA) BufPtr
);

STATIC FUNC(Std_ReturnType, ETHTSYN_CODE) EthTSyn_TransmitPTPFrame
(
    uint8 CtrlIdx,
    Eth_BufIdxType BufIdx,
    uint16 PTPLength,
    boolean EnableTimeStampFlag
);

#if(STD_ON == ETHTSYN_PORT_SLAVE_SUPPORT)
STATIC FUNC(void, ETHTSYN_CODE) EthTSyn_SlaveProcessRxPTPMsg
(
    uint8 CtrlIdx,
    P2VAR(uint8, AUTOMATIC, ETHTSYN_APPL_DATA) RxDataPtr,
    uint16 PTPMsgLength
);

STATIC FUNC(void, ETHTSYN_CODE) EthTSyn_SlaveControllerUpdateLocalClock
(
    uint8 CtrlIdx
);

STATIC FUNC(void, ETHTSYN_CODE) EthTSyn_ProcessRxPTPPdelayRespFrame
(
    uint8 CtrlIdx,
    P2VAR(uint8, AUTOMATIC, ETHTSYN_APPL_DATA) RxDataPtr
);

STATIC FUNC(void, ETHTSYN_CODE) EthTSyn_SlaveControllerMeasuringDelay
(
    uint8 CtrlIdx
);
STATIC FUNC(Std_ReturnType, ETHTSYN_CODE) EthTSyn_GetEthCurrentTime
(
#if(ETHTSYN_HW_TIMESTAMP_SUPPORT == STD_ON)
    P2VAR(Eth_TimeStampType, AUTOMATIC, ETHTSYN_APPL_DATA) TimeStampPtr,
#else
    StbM_SynchronizedTimeBaseType timeBaseId,
    P2VAR(StbM_TimeStampType, AUTOMATIC, ETHTSYN_APPL_DATA) TimeStampPtr,
#endif
    P2VAR(EthTSyn_SyncStateType, AUTOMATIC, ETHTSYN_APPL_DATA) syncState
);


STATIC FUNC(void, ETHTSYN_CODE) EthTSyn_TransmitPTPPdelayReqFrame
(
    uint8 CtrlIdx
);

STATIC FUNC(void, ETHTSYN_CODE) EthTSyn_DiffEthTimeStamp
(
#if(ETHTSYN_HW_TIMESTAMP_SUPPORT == STD_ON)
    P2CONST(Eth_TimeStampType, AUTOMATIC, ETHTSYN_APPL_DATA) SubtractedTimeStampPtr,
    P2CONST(Eth_TimeStampType, AUTOMATIC, ETHTSYN_APPL_DATA) MinusTimeStampPtr,
#else
    P2CONST(StbM_TimeStampType, AUTOMATIC, ETHTSYN_APPL_DATA) SubtractedTimeStampPtr,
    P2CONST(StbM_TimeStampType, AUTOMATIC, ETHTSYN_APPL_DATA) MinusTimeStampPtr,
#endif
    P2VAR(Eth_TimeIntDiffType, AUTOMATIC, ETHTSYN_APPL_DATA) DiffTimeStampPtr
);
#endif

STATIC FUNC(Std_ReturnType, ETHTSYN_CODE) EthTSyn_GetIngressTimeStamp
(
    uint8 CtrlIdx,
    P2VAR(uint8, AUTOMATIC, ETHTSYN_APPL_DATA) RxDataPtr,
#if(ETHTSYN_HW_TIMESTAMP_SUPPORT == STD_ON)
    P2VAR(Eth_TimeStampType, AUTOMATIC, ETHTSYN_APPL_DATA) TimeStampPtr
#else
    P2VAR(StbM_TimeStampType, AUTOMATIC, ETHTSYN_APPL_DATA) TimeStampPtr
#endif
);

STATIC FUNC(Std_ReturnType, ETHTSYN_CODE) EthTSyn_GetEgressTimeStamp
(
    uint8 CtrlIdx,
    Eth_BufIdxType BufIdx,
#if(ETHTSYN_HW_TIMESTAMP_SUPPORT == STD_ON)
    P2VAR(Eth_TimeStampType, AUTOMATIC, ETHTSYN_APPL_DATA) TimeStampPtr
#else
    P2VAR(StbM_TimeStampType, AUTOMATIC, ETHTSYN_APPL_DATA) TimeStampPtr
#endif
);

#if(STD_ON == ETHTSYN_PORT_SLAVE_SUPPORT)
STATIC FUNC(void, ETHTSYN_CODE)EthTSyn_AddEthTimeStamp
(
#if(ETHTSYN_HW_TIMESTAMP_SUPPORT == STD_ON)
    P2VAR(Eth_TimeStampType, AUTOMATIC, ETHTSYN_APPL_DATA) TimeStampPtr1,
    P2VAR(Eth_TimeStampType, AUTOMATIC, ETHTSYN_APPL_DATA) TimeStampPtr2
#else
    P2VAR(StbM_TimeStampType, AUTOMATIC, ETHTSYN_APPL_DATA) TimeStampPtr1,
    P2VAR(StbM_TimeStampType, AUTOMATIC, ETHTSYN_APPL_DATA) TimeStampPtr2
#endif
);
#endif
/*******************************************************************************
*   Global Function Define
*******************************************************************************/

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name : EthTSyn_MainFunction
*
* Description   : Main function for cyclic call/resp Sync and Follow_Up and Pdelay_Req transmissions
*
* Inputs        : None
*
* Outputs       : None
*
* return        : None
*
* Limitations   : None
********************************************************************************
END_FUNCTION_HDR */
FUNC(void, ETHTSYN_CODE) EthTSyn_MainFunction
(
    void
)
{
#if(STD_ON == ETHTSYN_PORT_MASTER_SUPPORT)
    uint8 index = (uint8)0;
#endif
    if(STD_UNINITIALIZED == EthTSyn_InitStatus)
    {
        /*[SWS_EthTSyn_00007]*/
        ETHTSYN_DET_REPORT_ERROR(ETHTSYN_SERVICEID_MAINFUNCTION, ETHTSYN_E_NOT_INITIALIZED);
    }
    else
    {
#if(STD_ON == ETHTSYN_PORT_MASTER_SUPPORT)
        if(EthTSyn_MasterController[index].TxMode == ETHTSYN_TX_ON)
        {
            EthTSyn_MasterCounter++;
            for( ; index < ETHTSYN_GET_MASTER_MAX_NUMBER; index++)
            {
                if(ETHTSYN_SYNC_STATE_MASTER_SENDING_FOLLOW_UP == EthTSyn_MasterController[index].ControllerSyncState)
                {
#if(STD_ON == ETHTSYN_PORT_SLAVE_SUPPORT)
                    if(ETHTSYN_SYNC_STATE_SLAVE_UPDATING == EthTSyn_SlaveController[0].ControllerSyncState)
                    {
                        EthTSyn_SlaveControllerUpdateLocalClock((uint8)0);
                    }
#endif
                    if(EthTSyn_MasterController[index].TxFollowUpOffsetCounter < ETHTSYN_GET_FOLLOWUP_OFFSET)
                    {
                        EthTSyn_MasterController[index].TxFollowUpOffsetCounter++;
                    }
                    else
                    {
                        EthTSyn_MasterController[index].TxFollowUpOffsetCounter = (uint16)0;
#if(STD_ON == ETHTSYN_PORT_SLAVE_SUPPORT)
                        if((EthTSyn_SlaveController[0].CurrentSyncReceived == FALSE) || \
                        ((EthTSyn_SlaveController[0].CurrentSyncReceived == TRUE) && (ETHTSYN_SYNC_STATE_SLAVE_UPDATING == EthTSyn_SlaveController[0].ControllerSyncState)))
                        {
                            EthTSyn_TransmitPTPSyncFUpFrame(index);
                            EthTSyn_SlaveController[0].ControllerSyncState = ETHTSYN_SYNC_STATE_SLAVE_WAITING_SYNC;
                        }
                        else
                        {
                            /*do nothing*/                      
                        }
#else
                        EthTSyn_TransmitPTPSyncFUpFrame(index);
#endif
                    }
                }
                else if((EthTSyn_MasterCounter >= ETHTSYN_GET_SYNC_TX_INTERVAL) || (ETHTSYN_SYNC_STATE_MASTER_RETRANSMISSION_SYNC == EthTSyn_MasterController[index].ControllerSyncState))
                {
                    EthTSyn_MasterCounter = (uint16)0;
                    EthTSyn_TransmitPTPSyncFrame(index);
                }
                else
                {
                    /* do nothing */
                }

                if(ETHTSYN_PDELAY_STATE_MASTER_SENDING_PDELAYRESP == EthTSyn_MasterController[index].ControllerPdelayState)
                {
                    EthTSyn_TransmitPTPPdelayRespFrame(index);
                }
                else if(ETHTSYN_PDELAY_STATE_MASTER_SENDING_PDELAYRESPFUP == EthTSyn_MasterController[index].ControllerPdelayState)
                {
                    if(EthTSyn_MasterController[index].TxPdelayRespFUpOffsetCounter < ETHTSYN_GET_FOLLOWUP_OFFSET)
                    {
                        EthTSyn_MasterController[index].TxPdelayRespFUpOffsetCounter++;
                    }
                    else
                    {
                        EthTSyn_MasterController[index].TxPdelayRespFUpOffsetCounter = (uint16)0;
                        EthTSyn_TransmitPTPPdelayRespFupFrame(index);
                    } 
                }
                else
                {
                    /* do nothing */
                }
            }
        }
#endif
#if(STD_ON == ETHTSYN_PORT_SLAVE_SUPPORT)
        if(EthTSyn_SlaveController[0].TxMode == ETHTSYN_TX_ON)
        {
            EthTSyn_SlaveCounter++;

        	if((EthTSyn_SlaveCounter >= ETHTSYN_GET_PDELAYREQ_TX_INTERVAL) &&
        			((ETHTSYN_PDELAY_STATE_SLAVE_WAITING_PDELAYRESP == EthTSyn_SlaveController[0].ControllerPdelayState) ||
        			(ETHTSYN_PDELAY_STATE_SLAVE_WAITING_PDELAYRESPFUP == EthTSyn_SlaveController[0].ControllerPdelayState)))
        	{
        	     EthTSyn_SlaveController[0].ControllerPdelayState = ETHTSYN_PDELAY_STATE_SLAVE_RETRANSMISSION_PDELAYREQ;
        	}

#if(STD_OFF == ETHTSYN_PORT_MASTER_SUPPORT)
            if(ETHTSYN_SYNC_STATE_SLAVE_UPDATING == EthTSyn_SlaveController[0].ControllerSyncState)
            {
                EthTSyn_SlaveControllerUpdateLocalClock((uint8)0);
                EthTSyn_SlaveController[0].ControllerSyncState = ETHTSYN_SYNC_STATE_SLAVE_WAITING_SYNC;
            } 
            else
#endif
            if(((EthTSyn_SlaveCounter >= ETHTSYN_GET_PDELAYREQ_TX_INTERVAL) && (ETHTSYN_PDELAY_STATE_SLAVE_SENDING_PDELAYREQ == EthTSyn_SlaveController[0].ControllerPdelayState)) \
                || (ETHTSYN_PDELAY_STATE_SLAVE_RETRANSMISSION_PDELAYREQ == EthTSyn_SlaveController[0].ControllerPdelayState))
            {
                EthTSyn_TransmitPTPPdelayReqFrame((uint8)0);
                EthTSyn_SlaveCounter = (uint16)0;
            }
            else if(ETHTSYN_PDELAY_STATE_SLAVE_MEASUREING_DELAY == EthTSyn_SlaveController[0].ControllerPdelayState)
            {
                EthTSyn_SlaveControllerMeasuringDelay((uint8)0);
                EthTSyn_SlaveController[0].ControllerPdelayState = ETHTSYN_PDELAY_STATE_SLAVE_SENDING_PDELAYREQ;
            }
            else
            {
                /* do nothing */
            }
        }
#endif
    }
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name : EthTSyn_RxIndication
*
* Description   : By this API service the EthTSyn gets an indication and the data of a received frame.
*
* Inputs        : CtrlIdx : Index of the Ethernet controller
*                 FrameType : frame type of received Ethernet frame
*                 IsBroadcast : parameter to indicate a broadcast frame
*                 PhysAddrPtr : pointer to Physical source address (MAC address in network byte order)
*                                of received Ethernet frame
*                 DataPtr : Pointer to the payload of the received Ethernet frame
*                             (i.e. Ethernet header is not provided).
*                 PTPMsgLength : Length of received data
*
* Outputs       : None
*
* return        : None
*
* Limitations   : None
********************************************************************************
END_FUNCTION_HDR */
FUNC(void, ETHTSYN_CODE) EthTSyn_RxIndication
(
    uint8 CtrlIdx,
    Eth_FrameType FrameType,
    boolean IsBroadcast,
    P2CONST(uint8, AUTOMATIC, ETHTSYN_APPL_DATA) PhysAddrPtr,
    P2VAR(uint8, AUTOMATIC, ETHTSYN_APPL_DATA) RxDataPtr,
    uint16 PTPMsgLength
)
{
#if(STD_ON == ETHTSYN_PORT_MASTER_SUPPORT)
    Std_ReturnType ret = E_NOT_OK;
    uint8 index = (uint8)0;
#endif

    (void)IsBroadcast;
    (void)FrameType;

    if (STD_UNINITIALIZED == EthTSyn_InitStatus)
    {
        ETHTSYN_DET_REPORT_ERROR(ETHTSYN_SERVICEID_RXINDICATION, ETHTSYN_E_NOT_INITIALIZED);
    }
    else if(ETHTSYN_PTP_FRAMETYPE != FrameType)
    {
        ETHTSYN_DET_REPORT_ERROR(ETHTSYN_SERVICEID_RXINDICATION, ETHTSYN_E_PARAM);
    }
    else if ((NULL_PTR == PhysAddrPtr) || (NULL_PTR == RxDataPtr))
    {
        ETHTSYN_DET_REPORT_ERROR(ETHTSYN_SERVICEID_RXINDICATION, ETHTSYN_E_PARAM_POINTER);
    }
    else if(ETHTSYN_PTP_HEADER_SIZE > PTPMsgLength)
    {
        ETHTSYN_DET_REPORT_ERROR(ETHTSYN_SERVICEID_RXINDICATION, ETHTSYN_E_PARAM);
    }
    else
    {
#if(STD_ON == ETHTSYN_PORT_SLAVE_SUPPORT)
        (void)CtrlIdx;
        EthTSyn_SlaveProcessRxPTPMsg((uint8)0, RxDataPtr, PTPMsgLength);
#endif

#if(STD_ON == ETHTSYN_PORT_MASTER_SUPPORT)
        if(ETHTSYN_PTP_HEADER_VALUE_MSGTYPE_PDELAYREQ == (RxDataPtr[ETHTSYN_PTP_HEADER_OFFSET_MSGTYPE] & ETHTSYN_MASK_BYTE_LOW_NIBBLE))
        {
            if(((ETHTSYN_PTP_HEADER_SIZE + ETHTSYN_PTP_PAYLOADSIZE_PDELAY) == PTPMsgLength) || ((ETHTSYN_PTP_HEADER_SIZE + ETHTSYN_PTP_PAYLOADSIZE_PDELAY + ETHTSYN_PTP_ETHERNET_FCS_SIZE) == PTPMsgLength))
            {
                for(index = (uint8)0; index < ETHTSYN_GET_MASTER_MAX_NUMBER; index++)
                {
                    if(ETHTSYN_MAPPED_TO_ETHIF_CTRL_IDX(EthTSyn_MasterController[index].EthTSynCtrlIdx) == CtrlIdx)
                    {
                        EthTSyn_MasterController[index].Ingress_PdelayReqSequId = ETHTSYN_GET_SEQUENCEID_FROM_RCVDMESSAGE(RxDataPtr);
                        Bsw_MemCpy(&EthTSyn_MasterController[index].PdelayReqRxSrcPortId[0], &RxDataPtr[ETHTSYN_PTP_HEADER_OFFSET_SRCPORTIDENTITY_BYTE0], sizeof(EthTSyn_MasterController[index].PdelayReqRxSrcPortId));
                        ret = EthTSyn_GetIngressTimeStamp(CtrlIdx, RxDataPtr, &EthTSyn_MasterController[0].IngressTimeStampPdelay_t2);
                        if(ret == E_OK)
                        {
                            EthTSyn_MasterController[0].ControllerPdelayState = ETHTSYN_PDELAY_STATE_MASTER_SENDING_PDELAYRESP;
                        }
                        else
                        {
                            EthTSyn_MasterController[0].ControllerPdelayState = ETHTSYN_PDELAY_STATE_MASTER_WAITING_PDELAYREQ;
                        }
                    }
                }
            }
        }
#endif
    }
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name : EthTSyn_TxConfirmation
*
* Description   : Confirms the transmission of an Ethernet frame
*
* Inputs        : CtrlIdx : Index of the Ethernet controller within the context of the Ethernet Interface
*                 BufIdx : Index of the buffer resource
*
* Outputs       : None
*
* return        : None
*
* Limitations   : None
********************************************************************************
END_FUNCTION_HDR */
FUNC(void, ETHTSYN_CODE) EthTSyn_TxConfirmation
(
    uint8 CtrlIdx,
    Eth_BufIdxType BufIdx
)
{
    Std_ReturnType ret = E_NOT_OK;
#if(STD_ON == ETHTSYN_PORT_MASTER_SUPPORT)
    uint8 index = (uint8)0;
#endif
#if(STD_ON == ETHTSYN_HW_TIMESTAMP_SUPPORT)
    Eth_TimeStampType EgressTimeStamp;
#else
    StbM_TimeStampType EgressTimeStamp;
#endif
    if(STD_UNINITIALIZED == EthTSyn_InitStatus)
    {
        ETHTSYN_DET_REPORT_ERROR(ETHTSYN_SERVICEID_TXCONFIRMATION, ETHTSYN_E_NOT_INITIALIZED);
    }
    else
    {
#if(STD_ON == ETHTSYN_PORT_MASTER_SUPPORT)
        for( ; index < ETHTSYN_GET_MASTER_MAX_NUMBER; index++)
        {
            if((ETHTSYN_MAPPED_TO_ETHIF_CTRL_IDX(EthTSyn_MasterController[index].EthTSynCtrlIdx) == CtrlIdx) && (EthTSyn_MasterController[index].TxSyncBufIdx == BufIdx))
            {
                ret = EthTSyn_GetEgressTimeStamp(CtrlIdx, EthTSyn_MasterController[index].TxSyncBufIdx, &EgressTimeStamp);
                if(E_OK == ret)
                {
                    EthTSyn_MasterController[index].Sync_EgressTimeStamp_TS = EgressTimeStamp;
                    EthTSyn_MasterController[index].ControllerSyncState = ETHTSYN_SYNC_STATE_MASTER_SENDING_FOLLOW_UP;
                }
                else
                {
                    EthTSyn_MasterController[index].ControllerSyncState = ETHTSYN_SYNC_STATE_MASTER_RETRANSMISSION_SYNC;
                }
                EthTSyn_MasterController[index].TxSyncBufIdx = ETHTSYN_INVALID_BUFIDX;
            }
            else if((ETHTSYN_MAPPED_TO_ETHIF_CTRL_IDX(EthTSyn_MasterController[index].EthTSynCtrlIdx) == CtrlIdx) && (EthTSyn_MasterController[index].TxFollowUpBufIdx == BufIdx))
            {
            	EthTSyn_MasterController[index].TxFollowUpBufIdx = ETHTSYN_INVALID_BUFIDX;
            }
            else
            {
                /* do nothing */
            }
            if((ETHTSYN_MAPPED_TO_ETHIF_CTRL_IDX(EthTSyn_MasterController[index].EthTSynCtrlIdx) == CtrlIdx) && (EthTSyn_MasterController[index].TxPdelayRespBufIdx == BufIdx))
            {
                ret = EthTSyn_GetEgressTimeStamp(CtrlIdx, EthTSyn_MasterController[index].TxPdelayRespBufIdx, &EgressTimeStamp);
                if(E_OK == ret)
                {
                    EthTSyn_MasterController[index].EgressTimeStampPdelay_t3 = EgressTimeStamp;
                    EthTSyn_MasterController[index].ControllerPdelayState = ETHTSYN_PDELAY_STATE_MASTER_SENDING_PDELAYRESPFUP;
                }
                else
                {
                    EthTSyn_MasterController[index].ControllerPdelayState = ETHTSYN_PDELAY_STATE_MASTER_SENDING_PDELAYRESP;
                }
                EthTSyn_MasterController[index].TxPdelayRespBufIdx = ETHTSYN_INVALID_BUFIDX;
            }
            else if((ETHTSYN_MAPPED_TO_ETHIF_CTRL_IDX(EthTSyn_MasterController[index].EthTSynCtrlIdx) == CtrlIdx) && (EthTSyn_MasterController[index].TxPdelayRespFUpBufIdx == BufIdx))
            {
                EthTSyn_MasterController[index].TxPdelayRespFUpBufIdx = ETHTSYN_INVALID_BUFIDX;
            }
            else
            {
                /* do nothing */
            }
        }
#endif
#if(STD_ON == ETHTSYN_PORT_SLAVE_SUPPORT)
        if((ETHTSYN_MAPPED_TO_ETHIF_CTRL_IDX(EthTSyn_SlaveController[0].EthTSynCtrlIdx) == CtrlIdx) && (EthTSyn_SlaveController[0].TxPdelayReqBufIdx == BufIdx))
        {
            ret = EthTSyn_GetEgressTimeStamp(CtrlIdx, EthTSyn_SlaveController[0].TxPdelayReqBufIdx, &EgressTimeStamp);
            if(E_OK == ret)
            {
                EthTSyn_SlaveController[0].Pdelay_EgressTimeStamp_t1 = EgressTimeStamp;
                EthTSyn_SlaveController[0].ControllerPdelayState = ETHTSYN_PDELAY_STATE_SLAVE_WAITING_PDELAYRESP;
            }
            else
            {
                EthTSyn_SlaveController[0].ControllerPdelayState = ETHTSYN_PDELAY_STATE_SLAVE_RETRANSMISSION_PDELAYREQ;
            }
            EthTSyn_SlaveController[0].TxPdelayReqBufIdx = ETHTSYN_INVALID_BUFIDX;
        }    
#endif
    }
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name : EthTSyn_GetVersionInfo
*
* Description   :Returns the version information of this module.
*
* Inputs        : None
*
* Outputs       :-versioninfo:Pointer to where to store the version information of this module.
*
* return        : None
*
* Limitations   : None
********************************************************************************
END_FUNCTION_HDR */
#if(STD_ON == ETHTSYN_VERSION_INFO)
FUNC(void, ETHTSYN_CODE) EthTSyn_GetVersionInfo
(
    P2VAR(Std_VersionInfoType, AUTOMATIC, ETHTSYN_APPL_DATA) versionInfo
)
{
    if(versionInfo == NULL_PTR)
    {
        ETHTSYN_DET_REPORT_ERROR(ETHTSYN_SERVICEID_GETVERSIONINFO, ETHTSYN_E_PARAM_POINTER);
    }
    else
    {
        versionInfo->vendorID = ETHTSYN_VENDOR_ID;
        versionInfo->moduleID = ETHTSYN_MODULE_ID;
        versionInfo->sw_major_version = (uint8)ETHTSYN_SW_MAJOR_VERSION;
        versionInfo->sw_minor_version = (uint8)ETHTSYN_SW_MINOR_VERSION;
        versionInfo->sw_patch_version = (uint8)ETHTSYN_SW_PATCH_VERSION;
    }
}
#endif

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name : EthTSyn_SetTransmissionMode
*
* Description   : This API is used to turn on and off the TX capabilities of the EthTSyn.
*
* Inputs        : -CtrlIdx : Index of the Ethernet controller
*                 -Mode : ETHTSYN_TX_OFF,ETHTSYN_TX_ON
*
* Outputs       : None
*
* return        : None
*
* Limitations   : None
********************************************************************************
END_FUNCTION_HDR */
FUNC(void, ETHTSYN_CODE) EthTSyn_SetTransmissionMode
(
    uint8 CtrlIdx,
    EthTSyn_TransmissionModeType Mode
)
{
    uint8 index = (uint8)0;
    if(STD_UNINITIALIZED == EthTSyn_InitStatus)
    {
        ETHTSYN_DET_REPORT_ERROR(ETHTSYN_SERVICEID_SETTRANSMISSIONMODE, ETHTSYN_E_NOT_INITIALIZED);
    }
    else if((Mode != ETHTSYN_TX_ON) && (Mode != ETHTSYN_TX_OFF))
    {
        ETHTSYN_DET_REPORT_ERROR(ETHTSYN_SERVICEID_SETTRANSMISSIONMODE, ETHTSYN_E_PARAM);
    }
    else
    {
        for( ; index < ETHTSYN_GET_TOTAL_CTRL_NUMBER; index++)
        {
            if(ETHTSYN_MAPPED_TO_ETHIF_CTRL_IDX(index) == CtrlIdx)
            {
                if(index < ETHTSYN_GET_SLAVE_MAX_NUMBER)
                {
#if(STD_ON == ETHTSYN_PORT_SLAVE_SUPPORT)
                    if(EthTSyn_SlaveController[index].TxMode != Mode)
                    {
                        EthTSyn_SlaveController[index].TxMode = Mode;
                    }
#endif
                }
                else
                {
#if(STD_ON == ETHTSYN_PORT_MASTER_SUPPORT)
                    if(EthTSyn_MasterController[index - ETHTSYN_GET_SLAVE_MAX_NUMBER].TxMode != Mode)
                    {
                        EthTSyn_MasterController[index - ETHTSYN_GET_SLAVE_MAX_NUMBER].TxMode = Mode;
                    }
#endif
                }
                break;
            }
        }
    }
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name : EthTSyn_TrcvLinkStateChg
*
* Description   : Allows resetting state machine in case of unexpected Link loss
*                 to avoid inconsistent Sync and Follow_Up sequences.
*
* Inputs        : CtrlIdx: Index of the Ethernet controller
*                 LinkState: ETHTRCV_LINK_STATE_DOWN,ETHTRCV_LINK_STATE_ACTIVE
*
* Outputs       : None
*
* return        : None
*
* Limitations   : None
********************************************************************************
END_FUNCTION_HDR */

FUNC(void, ETHTSYN_CODE) EthTSyn_TrcvLinkStateChg
(
    uint8 CtrlIdx,
    EthTrcv_LinkStateType LinkState
)
{
    boolean updateMacAddrFlag = FALSE;
    uint8 index = (uint8)0;
    if (STD_UNINITIALIZED == EthTSyn_InitStatus)
    {
        ETHTSYN_DET_REPORT_ERROR(ETHTSYN_SERVICEID_TRCVLINKSTATECHG, ETHTSYN_E_NOT_INITIALIZED);
    }
    else
    {
        for( ; index < ETHTSYN_GET_TOTAL_CTRL_NUMBER; index++)
        {
            if(ETHTSYN_MAPPED_TO_ETHIF_CTRL_IDX(index) == CtrlIdx)
            {
                updateMacAddrFlag = TRUE;
#if(STD_ON == ETHTSYN_PORT_MASTER_SUPPORT)
                EthTSyn_MasterController[index - ETHTSYN_GET_SLAVE_MAX_NUMBER].LinkState = LinkState;
                if(ETHTRCV_LINK_STATE_ACTIVE != LinkState)
                {
                    EthTSyn_MasterController[index - ETHTSYN_GET_SLAVE_MAX_NUMBER].ControllerSyncState = ETHTSYN_SYNC_STATE_INIT;
                }
#endif
                break;
            }
        }
        if(updateMacAddrFlag == TRUE)
        {
            if(ETHTRCV_LINK_STATE_ACTIVE == LinkState)
            {
                (void)EthIf_UpdatePhysAddrFilter(CtrlIdx, EthTSyn_DestMacAddr_PTP, ETH_ADD_TO_FILTER);
            }
            else
            {
                (void)EthIf_UpdatePhysAddrFilter(CtrlIdx, EthTSyn_DestMacAddr_PTP, ETH_REMOVE_FROM_FILTER);
            }
        }
    }
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name : EthTSyn_GetCurrentTime
*
* Description   : Return a time value according its definition out of the HW registers
*
* Inputs        : timeBaseId : time base reference index
*
* Outputs       : timeStampPtr : current time stamp
*                 syncState : to inform wheter Ethernet is time synchronous or not
*
* return        : E_OK : successful
*                 E_NOT_OK : failed
*
* Limitations   : None
********************************************************************************
END_FUNCTION_HDR */
FUNC(Std_ReturnType, ETHTSYN_CODE) EthTSyn_GetCurrentTime
(
    StbM_SynchronizedTimeBaseType timeBaseId,
    P2VAR(StbM_TimeStampType, AUTOMATIC, ETHTSYN_APPL_DATA) timeStampPtr,
    P2VAR(EthTSyn_SyncStateType, AUTOMATIC, ETHTSYN_APPL_DATA) syncState
)
{
    Std_ReturnType ret = E_NOT_OK;
#if(ETHTSYN_HW_TIMESTAMP_SUPPORT == STD_ON)
    uint8 index = (uint8)0;
    Eth_TimeStampQualType TimeQuality;
    Eth_TimeStampType EthTimeStamp;
#endif /* ETHTSYN_HW_TIMESTAMP_SUPPORT == STD_ON */
    if(STD_UNINITIALIZED == EthTSyn_InitStatus)
    {
        ETHTSYN_DET_REPORT_ERROR(ETHTSYN_SERVICEID_GETCURRENTTIME, ETHTSYN_E_NOT_INITIALIZED);
    }
    else if(NULL_PTR == timeStampPtr)
    {
        ETHTSYN_DET_REPORT_ERROR(ETHTSYN_SERVICEID_GETCURRENTTIME, ETHTSYN_E_PARAM_POINTER);
    }
    else if(syncState == NULL_PTR)
    {
        ETHTSYN_DET_REPORT_ERROR(ETHTSYN_SERVICEID_GETCURRENTTIME, ETHTSYN_E_PARAM_POINTER);
    }
    else
    {
#if(ETHTSYN_HW_TIMESTAMP_SUPPORT == STD_ON)
        (void)timeBaseId;
        ret = Eth_GetCurrentTime(ETHTSYN_MAPPED_TO_ETHIF_CTRL_IDX(index), &TimeQuality, &EthTimeStamp);
        if(TimeQuality != ETH_VALID)
        {
            *syncState = ETHTSYN_UNCERTAIN;
        }
        else
        {
            /* *syncState = EthTSyn_SlaveController[0].EcuSyncState; */
        }
        timeStampPtr->nanoseconds = EthTimeStamp.nanoseconds;
        timeStampPtr->seconds = EthTimeStamp.seconds;
        timeStampPtr->secondsHi = EthTimeStamp.secondsHi;
        if(((*syncState) == ETHTSYN_UNCERTAIN) || ((*syncState) == ETHTSYN_UNSYNC) || ((*syncState) == ETHTSYN_NEVERSYNC))
        {
            timeStampPtr->timeBaseStatus.GLOBAL_TIME_BASE = (uint8)0;
            timeStampPtr->timeBaseStatus.SYNC_TO_GATEWAY = (uint8)0;
            timeStampPtr->timeBaseStatus.TIMELEAP = (uint8)0;
            timeStampPtr->timeBaseStatus.TIMEOUT = (uint8)1;
        }
        else
        {
            timeStampPtr->timeBaseStatus.GLOBAL_TIME_BASE = (uint8)1;
            timeStampPtr->timeBaseStatus.SYNC_TO_GATEWAY = (uint8)0;
            timeStampPtr->timeBaseStatus.TIMELEAP = (uint8)0;
            timeStampPtr->timeBaseStatus.TIMEOUT = (uint8)0;
        }

#else /* ETHTSYN_HW_TIMESTAMP_SUPPORT == STD_ON */
        (void)timeBaseId;
        (void)timeStampPtr;
        (void)syncState;
#endif /* ETHTSYN_HW_TIMESTAMP_SUPPORT == STD_ON */
    }
    return ret;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name : EthTSyn_SetGlobalTime
*
* Description   : Allow the Time Master to adjust the global ETH Reference clock in HW.
*                 This method is used to set a Global Time Base on ETH in general or to synchronize
*                 the Global ETH Time Base with another time base, e.g. Ethernet.
*
* Inputs        : timeBaseId : time base reference index
*                 timeStampPtr : new time stamp
*
* Outputs       : None
*
* return        : E_OK : successful
*                 E_NOT_OK : failed
*
* Limitations   : None
********************************************************************************
END_FUNCTION_HDR */
FUNC(Std_ReturnType, ETHTSYN_CODE) EthTSyn_SetGlobalTime
(
    StbM_SynchronizedTimeBaseType timeBaseId,
    P2CONST(StbM_TimeStampType, AUTOMATIC, ETHTSYN_APPL_DATA) timeStampPtr
)
{
    Std_ReturnType ret = E_NOT_OK;
#if(ETHTSYN_HW_TIMESTAMP_SUPPORT == STD_ON)
    uint8 index = (uint8)0;
    Eth_TimeStampType EthTimeStamp;
#endif /* ETHTSYN_HW_TIMESTAMP_SUPPORT == STD_ON */
    if(STD_UNINITIALIZED == EthTSyn_InitStatus)
    {
        ETHTSYN_DET_REPORT_ERROR(ETHTSYN_SERVICEID_SETGLOBALTIME, ETHTSYN_E_NOT_INITIALIZED);
    }
    else if(NULL_PTR == timeStampPtr)
    {
        ETHTSYN_DET_REPORT_ERROR(ETHTSYN_SERVICEID_SETGLOBALTIME, ETHTSYN_E_PARAM_POINTER);
    }
    else
    {
#if(ETHTSYN_HW_TIMESTAMP_SUPPORT == STD_ON)
        for( ; index < ETHTSYN_GET_TOTAL_CTRL_NUMBER; index++)
        {
#if(STD_ON == ETHTSYN_PORT_SLAVE_SUPPORT)
            if(ETHTSYN_GET_SLAVE_TIMEBASEID == timeBaseId)
            {
                EthTimeStamp.nanoseconds = timeStampPtr->nanoseconds;
                EthTimeStamp.seconds = timeStampPtr->seconds;
                EthTimeStamp.secondsHi = timeStampPtr->secondsHi;
                ret = Eth_SetGlobalTime(index, &EthTimeStamp);
            }
#endif
#if(STD_ON == ETHTSYN_PORT_MASTER_SUPPORT)
            if(ETHTSYN_GET_MASTER_TIMEBASEID == timeBaseId)
            {
                EthTimeStamp.nanoseconds = timeStampPtr->nanoseconds;
                EthTimeStamp.seconds = timeStampPtr->seconds;
                EthTimeStamp.secondsHi = timeStampPtr->secondsHi;
                ret = Eth_SetGlobalTime(index, &EthTimeStamp);
            }
#endif
            if(ret == E_OK)
            {
                break;
            }
        }
#endif
    }
    return ret;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: EthTSyn_Init
*
* Description:   Initializes the Time Synchronization over Ethernet
*
* Inputs:        EthTSyn_ConfigType * CfgPtr : Pointer to selected configuration structure
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, ETHTSYN_CODE) EthTSyn_Init
(
    P2CONST(EthTSyn_ConfigType, AUTOMATIC, ETHTSYN_APPL_CONST) CfgPtr
)
{
    uint8 index = (uint8)0;
#if(ETHTSYN_CONFIG_VARIANTS == STD_CONFIG_VARIANTS_POSTBUILD)
    if(NULL_PTR == CfgPtr)
    {
        ETHTSYN_DET_REPORT_ERROR(ETHTSYN_SERVICEID_INIT, ETHTSYN_E_PARAM_POINTER);
    }
    else
#endif
    {
#if(ETHTSYN_CONFIG_VARIANTS == STD_CONFIG_VARIANTS_POSTBUILD)
        EthTSyn_DefaultCfgPtr = CfgPtr;
#else
        EthTSyn_DefaultCfgPtr = &EthTSyn_Config;
#endif
        EthTSyn_InitStatus = STD_INITIALIZED;

#if(STD_ON == ETHTSYN_PORT_SLAVE_SUPPORT)
		/*[SWS_EthTSyn_00006]*/
		/*[SWS_EthTSyn_00008]*/
        for(index = (uint8)0; index < ETHTSYN_GET_SLAVE_MAX_NUMBER; index++)
        {
            /* commom variable */
            EthTSyn_SlaveController[index].EthTSynCtrlIdx = ETHTSYN_GET_ETHTSYN_CTRL_INDEX(index);
            EthTSyn_SlaveController[index].ControllerSyncState = ETHTSYN_SYNC_STATE_SLAVE_WAITING_SYNC;
            EthTSyn_SlaveController[index].ControllerPdelayState = ETHTSYN_PDELAY_STATE_SLAVE_SENDING_PDELAYREQ;
            EthTSyn_SlaveController[index].TimeBaseId = ETHTSYN_GET_SLAVE_TIMEBASEID;
            /* Sync Variable */
            EthTSyn_SlaveController[index].Sync_IngressTimeStamp_TR.nanoseconds = (uint32)0;
            EthTSyn_SlaveController[index].Sync_IngressTimeStamp_TR.seconds = (uint32)0;
            EthTSyn_SlaveController[index].Sync_IngressTimeStamp_TR.secondsHi = (uint16)0;
            EthTSyn_SlaveController[index].Sync_OriginTimeStamp.nanoseconds = (uint32)0;
            EthTSyn_SlaveController[index].Sync_OriginTimeStamp.seconds = (uint32)0;
            EthTSyn_SlaveController[index].Sync_OriginTimeStamp.secondsHi = (uint16)0;
            EthTSyn_SlaveController[index].EcuSyncState = ETHTSYN_NEVERSYNC;
            EthTSyn_SlaveController[index].CurrentSyncReceived = FALSE;
            /*PRQA S 4447 ++*/
            /*type conversion here is necessary and no negative influence*/
            (void)memset(&EthTSyn_SlaveController[index].CorrectionField_Fraction[0], (uint8)0, sizeof(EthTSyn_SlaveController[index].CorrectionField_Fraction));
            EthTSyn_SlaveController[index].PortNumber = ETHTSYN_GET_SLAVE_PORTNUMBER;
            EthTSyn_SlaveController[index].Ingress_SyncSequId = (uint16)0;
            EthTSyn_SlaveController[index].TxMode = ETHTSYN_TX_ON;
            EthTSyn_SlaveController[index].LinkState = ETHTRCV_LINK_STATE_DOWN;
            /* Pdelay Variable */
            EthTSyn_SlaveController[index].Pdelay_EgressTimeStamp_t1.nanoseconds = (uint32)0;
            EthTSyn_SlaveController[index].Pdelay_EgressTimeStamp_t1.seconds = (uint32)0;
            EthTSyn_SlaveController[index].Pdelay_EgressTimeStamp_t1.secondsHi = (uint16)0;
            EthTSyn_SlaveController[index].Pdelay_IngressTimeStamp_t2.nanoseconds = (uint32)0;
            EthTSyn_SlaveController[index].Pdelay_IngressTimeStamp_t2.seconds = (uint32)0;
            EthTSyn_SlaveController[index].Pdelay_IngressTimeStamp_t2.secondsHi = (uint16)0;
            EthTSyn_SlaveController[index].Pdelay_EgressTimeStamp_t3.nanoseconds = (uint32)0;
            EthTSyn_SlaveController[index].Pdelay_EgressTimeStamp_t3.seconds = (uint32)0;
            EthTSyn_SlaveController[index].Pdelay_EgressTimeStamp_t3.secondsHi = (uint16)0;
            EthTSyn_SlaveController[index].Pdelay_IngressTimeStamp_t4.nanoseconds = (uint32)0;
            EthTSyn_SlaveController[index].Pdelay_IngressTimeStamp_t4.seconds = (uint32)0;
            EthTSyn_SlaveController[index].Pdelay_IngressTimeStamp_t4.secondsHi = (uint16)0;
            EthTSyn_SlaveController[index].Diff_TimeStamp_t4_t1.nanoseconds = (uint32)0;
            EthTSyn_SlaveController[index].Diff_TimeStamp_t4_t1.seconds = (uint32)0;
            EthTSyn_SlaveController[index].Diff_TimeStamp_t4_t1.secondsHi = (uint16)0;
            EthTSyn_SlaveController[index].AccomplishMeasuringDelay = FALSE;
            EthTSyn_SlaveController[index].TxPdelayReqBufIdx = ETHTSYN_INVALID_BUFIDX;
            EthTSyn_SlaveController[index].TxPdelayReqSequId = (uint16)0;
            EthTSyn_SlaveController[index].NeighborMeanPropDelay = (uint32)0;
            EthTSyn_SlaveController[index].DefaultLinkDelay = ETHTSYN_GET_DEFAULT_PDELAY;
            EthIf_GetPhysAddr(ETHTSYN_MAPPED_TO_ETHIF_CTRL_IDX(index), &SrcMacAddr[0]);
        }
#endif
#if(STD_ON == ETHTSYN_PORT_MASTER_SUPPORT)
        for(index = (uint8)0; index < ETHTSYN_GET_MASTER_MAX_NUMBER; index++)
        {
            /* commom variable */
            EthTSyn_MasterController[index].EthTSynCtrlIdx = ETHTSYN_GET_ETHTSYN_CTRL_INDEX(index + ETHTSYN_GET_SLAVE_MAX_NUMBER);
            EthTSyn_MasterController[index].ControllerSyncState = ETHTSYN_SYNC_STATE_INIT;
            EthTSyn_MasterController[index].ControllerPdelayState = ETHTSYN_PDELAY_STATE_INIT;
            EthTSyn_MasterController[index].TimeBaseId = ETHTSYN_GET_MASTER_TIMEBASEID;
            /* Sync Variable */
            EthTSyn_MasterController[index].Sync_EgressTimeStamp_TS.nanoseconds = (uint32)0;
            EthTSyn_MasterController[index].Sync_EgressTimeStamp_TS.seconds = (uint32)0;
            EthTSyn_MasterController[index].Sync_EgressTimeStamp_TS.secondsHi = (uint16)0;
            EthTSyn_MasterController[index].TxSyncBufIdx = ETHTSYN_INVALID_BUFIDX;
            EthTSyn_MasterController[index].TxFollowUpBufIdx = ETHTSYN_INVALID_BUFIDX;
            EthTSyn_MasterController[index].TxSyncSequId = (uint16)0;
            EthTSyn_MasterController[index].TxFollowUpOffsetCounter = (uint16)0;
            EthTSyn_MasterController[index].PortNumber = ETHTSYN_GET_MASTER_PORTNUMBER;
#if(STD_ON == ETHTSYN_PORT_SLAVE_SUPPORT)
            EthTSyn_MasterController[index].CorrectionField_Integer = (uint64)0;
#endif
            EthTSyn_MasterController[index].TxMode = ETHTSYN_TX_ON;
            EthTSyn_MasterController[index].LinkState = ETHTRCV_LINK_STATE_DOWN;
            /* Pdelay Variable */
            EthTSyn_MasterController[index].IngressTimeStampPdelay_t2.nanoseconds = (uint32)0;
            EthTSyn_MasterController[index].IngressTimeStampPdelay_t2.seconds = (uint32)0;
            EthTSyn_MasterController[index].IngressTimeStampPdelay_t2.secondsHi = (uint16)0;
            EthTSyn_MasterController[index].EgressTimeStampPdelay_t3.nanoseconds = (uint32)0;
            EthTSyn_MasterController[index].EgressTimeStampPdelay_t3.seconds = (uint32)0;
            EthTSyn_MasterController[index].EgressTimeStampPdelay_t3.secondsHi = (uint16)0;
            EthTSyn_MasterController[index].TxPdelayRespBufIdx = ETHTSYN_INVALID_BUFIDX;
            EthTSyn_MasterController[index].TxPdelayRespFUpBufIdx = ETHTSYN_INVALID_BUFIDX;
            EthTSyn_MasterController[index].TxPdelayRespFUpOffsetCounter = (uint16)0;
            (void)memset(&EthTSyn_MasterController[index].PdelayReqRxSrcPortId[0], (uint8)0, sizeof(EthTSyn_MasterController[index].PdelayReqRxSrcPortId));
            EthTSyn_MasterController[index].Ingress_PdelayReqSequId = (uint16)0;
            EthTSyn_MasterController[index].ControllerPdelayState = ETHTSYN_PDELAY_STATE_MASTER_WAITING_PDELAYREQ;
            EthIf_GetPhysAddr(ETHTSYN_MAPPED_TO_ETHIF_CTRL_IDX(index + ETHTSYN_GET_SLAVE_MAX_NUMBER), &SrcMacAddr[0]);
        }
#endif
    }
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: EthTSyn_TransmitPTPSyncFrame
*
* Description:   Service to transmit a Sync frame
*
* Inputs:        uint8 CtrlIdx : Index of the EthTSyn controller
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
#if(STD_ON == ETHTSYN_PORT_MASTER_SUPPORT)
STATIC FUNC(void, ETHTSYN_CODE) EthTSyn_TransmitPTPSyncFrame
(
    uint8 CtrlIdx
)
{
    Eth_BufIdxType txSyncBufIdx = (uint8)0;
    EthTSyn_PTPHeaderType txSyncPTPHeader;
    P2VAR(uint8, AUTOMATIC, ETHTSYN_APPL_DATA) txSyncPtr;
    Std_ReturnType ret = E_NOT_OK;

    txSyncPTPHeader.Flags = ETHTSYN_PTP_HEADER_VALUE_FLAG_TWOSTEP;
    txSyncPTPHeader.Flags |= ETHTSYN_PTP_HEADER_VALUE_FLAG_PTPTIMESCALE;
    txSyncPTPHeader.MsgType = ETHTSYN_PTP_HEADER_VALUE_MSGTYPE_SYNC;
    txSyncPTPHeader.Control = ETHTSYN_PTP_HEADER_VALUE_CONTROL_SYNC;
#if(STD_ON == ETHTSYN_PORT_SLAVE_SUPPORT)
    SchM_Enter_EthTSyn_ETHTSYN_EXCLUSIVE_AREA_0();
    if((ETHTSYN_SYNC_STATE_SLAVE_WAITING_FOLLOW_UP == EthTSyn_SlaveController[0].ControllerSyncState) || (ETHTSYN_SYNC_STATE_SLAVE_UPDATING == EthTSyn_SlaveController[0].ControllerSyncState))
    {
        txSyncPTPHeader.SequID = EthTSyn_SlaveController[0].Ingress_SyncSequId;
        EthTSyn_SlaveController[0].CurrentSyncReceived = TRUE;
    }
    else
    {
        txSyncPTPHeader.SequID = EthTSyn_MasterController[CtrlIdx].TxSyncSequId;
        EthTSyn_SlaveController[0].CurrentSyncReceived = FALSE;
    }
    SchM_Exit_EthTSyn_ETHTSYN_EXCLUSIVE_AREA_0();
#else
    txSyncPTPHeader.SequID = EthTSyn_MasterController[CtrlIdx].TxSyncSequId;
#endif
    txSyncPTPHeader.LogMsgInterval = ETHTSYN_GET_MASTER_SYNCTXMSGLOGINTERVAL;
    txSyncPTPHeader.MsgLength = ETHTSYN_PTP_HEADER_SIZE + ETHTSYN_PTP_PAYLOADSIZE_SYNC;

    /* [SWS_EthTSyn_00016] */
    ret = EthTSyn_GetTxBuffer(ETHTSYN_MAPPED_TO_ETHIF_CTRL_IDX(EthTSyn_MasterController[CtrlIdx].EthTSynCtrlIdx), txSyncPTPHeader.MsgLength, &txSyncBufIdx, &txSyncPtr);

    if(E_OK == ret)
    {
        (void)memset(txSyncPtr, (uint8)0, sizeof(txSyncPtr));
        EthTSyn_PaddingPTPHeader(EthTSyn_MasterController[CtrlIdx].EthTSynCtrlIdx, &txSyncPTPHeader, &txSyncPtr[0]);       
        ret = EthTSyn_TransmitPTPFrame(ETHTSYN_MAPPED_TO_ETHIF_CTRL_IDX(EthTSyn_MasterController[CtrlIdx].EthTSynCtrlIdx), txSyncBufIdx, txSyncPTPHeader.MsgLength, TRUE);
        if(E_OK == ret)
        {
            EthTSyn_MasterController[CtrlIdx].TxSyncBufIdx = txSyncBufIdx;
        }
        else
        {
            EthTSyn_MasterController[CtrlIdx].ControllerSyncState = ETHTSYN_SYNC_STATE_MASTER_RETRANSMISSION_SYNC;
        }
    }
    else
    {
        EthTSyn_MasterController[CtrlIdx].ControllerSyncState = ETHTSYN_SYNC_STATE_MASTER_RETRANSMISSION_SYNC;
    }   
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: EthTSyn_TransmitPTPSyncFUpFrame
*
* Description:   Service to transmit a Sync follow up frame
*
* Inputs:        uint8 index : Index of the EthTSyn controller
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, ETHTSYN_CODE) EthTSyn_TransmitPTPSyncFUpFrame
(
    uint8 CtrlIdx
)
{
    Eth_BufIdxType txFollowUpBufIdx = (Eth_BufIdxType)0;
    EthTSyn_PTPHeaderType txFollowUpPTPHeader;
    P2VAR(uint8, AUTOMATIC, ETHTSYN_APPL_DATA) txFollowUpPtr;
    Std_ReturnType ret = E_NOT_OK;
#if(STD_ON == ETHTSYN_PORT_SLAVE_SUPPORT)
    Eth_TimeIntDiffType residenceInCurrentJump;
#endif

    txFollowUpPTPHeader.MsgType = ETHTSYN_PTP_HEADER_VALUE_MSGTYPE_SYNCFUP;
    txFollowUpPTPHeader.Flags = ETHTSYN_PTP_HEADER_VALUE_FLAG_PTPTIMESCALE;
    txFollowUpPTPHeader.Control = ETHTSYN_PTP_HEADER_VALUE_CONTROL_FUP;
    txFollowUpPTPHeader.LogMsgInterval = ETHTSYN_GET_MASTER_SYNCTXMSGLOGINTERVAL;
    txFollowUpPTPHeader.MsgLength = ETHTSYN_PTP_HEADER_SIZE + ETHTSYN_PTP_PAYLOADSIZE_SYNC_FUP;
#if(STD_ON == ETHTSYN_PORT_SLAVE_SUPPORT)
    if(EthTSyn_SlaveController[0].CurrentSyncReceived == TRUE)
    {
    	txFollowUpPTPHeader.SequID = EthTSyn_SlaveController[0].Ingress_SyncSequId;
    }
    else
    {
        txFollowUpPTPHeader.SequID = EthTSyn_MasterController[CtrlIdx].TxSyncSequId;
        if(ETHTSYN_SEQUENCEID_MAX == EthTSyn_MasterController[CtrlIdx].TxSyncSequId)
        {
            EthTSyn_MasterController[CtrlIdx].TxSyncSequId = (uint16)0;
        }
        else
        {
            EthTSyn_MasterController[CtrlIdx].TxSyncSequId++;
        }
    }
#else
    txFollowUpPTPHeader.SequID = EthTSyn_MasterController[CtrlIdx].TxSyncSequId;
    if(ETHTSYN_SEQUENCEID_MAX ==  EthTSyn_MasterController[CtrlIdx].TxSyncSequId)
    {
        EthTSyn_MasterController[CtrlIdx].TxSyncSequId = (uint16)0;
    }
    else
    {
        EthTSyn_MasterController[CtrlIdx].TxSyncSequId++;
    }
#endif
#if(STD_ON == ETHTSYN_PORT_SLAVE_SUPPORT)
    if(EthTSyn_SlaveController[0].CurrentSyncReceived == TRUE)
    {
        EthTSyn_DiffEthTimeStamp(&EthTSyn_MasterController[CtrlIdx].Sync_EgressTimeStamp_TS, &EthTSyn_SlaveController[0].Sync_IngressTimeStamp_TR, &residenceInCurrentJump);
        if((TRUE == residenceInCurrentJump.sign) && ((uint32)0 == residenceInCurrentJump.diff.secondsHi))
        {
            EthTSyn_MasterController[CtrlIdx].CorrectionField_Integer += (uint64)residenceInCurrentJump.diff.nanoseconds;
            if((uint64)0 != residenceInCurrentJump.diff.seconds)
            {
                EthTSyn_MasterController[CtrlIdx].CorrectionField_Integer += ((uint64)residenceInCurrentJump.diff.seconds * (uint64)ETHTSYN_SECOND_TO_NANOSECOND);
            }
            /* SWS_EthTSyn_00018 */
            ret = EthTSyn_GetTxBuffer(ETHTSYN_MAPPED_TO_ETHIF_CTRL_IDX(EthTSyn_MasterController[CtrlIdx].EthTSynCtrlIdx), txFollowUpPTPHeader.MsgLength, &txFollowUpBufIdx, &txFollowUpPtr);
            if(E_OK == ret)
            {
                (void)memset(txFollowUpPtr, (uint8)0, (uint8)txFollowUpPTPHeader.MsgLength);
                EthTSyn_PaddingPTPHeader(EthTSyn_MasterController[CtrlIdx].EthTSynCtrlIdx, &txFollowUpPTPHeader, &txFollowUpPtr[0]);
                EthTSyn_MasterController[CtrlIdx].CorrectionField_Integer = (uint64)0;
                EthTSyn_ConvertTimeStamp2Array(&EthTSyn_SlaveController[0].Sync_OriginTimeStamp, &txFollowUpPtr[ETHTSYN_PTP_HEADER_SIZE]);
                EthTSyn_PaddingSyncFUpTLV(&txFollowUpPtr[ETHTSYN_PTP_HEADER_SIZE + ETHTSYN_TIMESTAMP_SIZE]);
                ret = EthTSyn_TransmitPTPFrame(ETHTSYN_MAPPED_TO_ETHIF_CTRL_IDX(EthTSyn_MasterController[CtrlIdx].EthTSynCtrlIdx), txFollowUpBufIdx, txFollowUpPTPHeader.MsgLength, FALSE);
                if(E_OK == ret)
                {
                    EthTSyn_MasterController[CtrlIdx].TxFollowUpBufIdx = txFollowUpBufIdx;
                    EthTSyn_MasterController[CtrlIdx].ControllerSyncState = ETHTSYN_SYNC_STATE_MASTER_CURRENT_CYCLE_SENDINF_SUCCESSFULLY;
                }
                else
                {
                    EthTSyn_MasterController[CtrlIdx].ControllerSyncState = ETHTSYN_SYNC_STATE_MASTER_RETRANSMISSION_SYNC;
                }
            }
            else
            {
                EthTSyn_MasterController[CtrlIdx].ControllerSyncState = ETHTSYN_SYNC_STATE_MASTER_RETRANSMISSION_SYNC;
            }
        }
        else
        {
            /* SWS_EthTSyn_00018 */
            ret = EthTSyn_GetTxBuffer(ETHTSYN_MAPPED_TO_ETHIF_CTRL_IDX(EthTSyn_MasterController[CtrlIdx].EthTSynCtrlIdx), txFollowUpPTPHeader.MsgLength, &txFollowUpBufIdx, &txFollowUpPtr);
            if(E_OK == ret)
            {
                (void)memset(txFollowUpPtr, (uint8)0, (uint8)txFollowUpPTPHeader.MsgLength);
                EthTSyn_PaddingPTPHeader(EthTSyn_MasterController[CtrlIdx].EthTSynCtrlIdx, &txFollowUpPTPHeader, &txFollowUpPtr[0]);
                EthTSyn_ConvertTimeStamp2Array(&EthTSyn_MasterController[CtrlIdx].Sync_EgressTimeStamp_TS, &txFollowUpPtr[ETHTSYN_PTP_HEADER_SIZE]);
                EthTSyn_PaddingSyncFUpTLV(&txFollowUpPtr[ETHTSYN_PTP_HEADER_SIZE + ETHTSYN_TIMESTAMP_SIZE]);
                ret = EthTSyn_TransmitPTPFrame(ETHTSYN_MAPPED_TO_ETHIF_CTRL_IDX(EthTSyn_MasterController[CtrlIdx].EthTSynCtrlIdx), txFollowUpBufIdx, txFollowUpPTPHeader.MsgLength, FALSE);
                if(E_OK == ret)
                {
                    EthTSyn_MasterController[CtrlIdx].TxFollowUpBufIdx = txFollowUpBufIdx;
                }
                else
                {
                    EthTSyn_MasterController[CtrlIdx].ControllerSyncState = ETHTSYN_SYNC_STATE_MASTER_RETRANSMISSION_SYNC;
                }
            }
            else
            {
                EthTSyn_MasterController[CtrlIdx].ControllerSyncState = ETHTSYN_SYNC_STATE_MASTER_RETRANSMISSION_SYNC;
            }
        }
    }
    else
    {
        /* SWS_EthTSyn_00018 */
        ret = EthTSyn_GetTxBuffer(ETHTSYN_MAPPED_TO_ETHIF_CTRL_IDX(EthTSyn_MasterController[CtrlIdx].EthTSynCtrlIdx), txFollowUpPTPHeader.MsgLength, &txFollowUpBufIdx, &txFollowUpPtr);
        if(E_OK == ret)
        {
            (void)memset(txFollowUpPtr, (uint8)0, (uint8)txFollowUpPTPHeader.MsgLength);
            EthTSyn_PaddingPTPHeader(EthTSyn_MasterController[CtrlIdx].EthTSynCtrlIdx, &txFollowUpPTPHeader, &txFollowUpPtr[0]);
            EthTSyn_ConvertTimeStamp2Array(&EthTSyn_MasterController[CtrlIdx].Sync_EgressTimeStamp_TS, &txFollowUpPtr[ETHTSYN_PTP_HEADER_SIZE]);
            EthTSyn_PaddingSyncFUpTLV(&txFollowUpPtr[ETHTSYN_PTP_HEADER_SIZE + ETHTSYN_TIMESTAMP_SIZE]);
            ret = EthTSyn_TransmitPTPFrame(ETHTSYN_MAPPED_TO_ETHIF_CTRL_IDX(EthTSyn_MasterController[CtrlIdx].EthTSynCtrlIdx), txFollowUpBufIdx, txFollowUpPTPHeader.MsgLength, FALSE);
            if(E_OK == ret)
            {
                EthTSyn_MasterController[CtrlIdx].TxFollowUpBufIdx = txFollowUpBufIdx;
                EthTSyn_MasterController[CtrlIdx].ControllerSyncState = ETHTSYN_SYNC_STATE_MASTER_CURRENT_CYCLE_SENDINF_SUCCESSFULLY;
            }
            else
            {
                EthTSyn_MasterController[CtrlIdx].ControllerSyncState = ETHTSYN_SYNC_STATE_MASTER_RETRANSMISSION_SYNC;
            }
        }
        else
        {
            EthTSyn_MasterController[CtrlIdx].ControllerSyncState = ETHTSYN_SYNC_STATE_MASTER_RETRANSMISSION_SYNC;
        }
    }
#else
    /* SWS_EthTSyn_00018 */
    ret = EthTSyn_GetTxBuffer(ETHTSYN_MAPPED_TO_ETHIF_CTRL_IDX(EthTSyn_MasterController[CtrlIdx].EthTSynCtrlIdx), txFollowUpPTPHeader.MsgLength, &txFollowUpBufIdx, &txFollowUpPtr);
    if(E_OK == ret)
    {
        (void)memset(txFollowUpPtr, (uint8)0, (uint8)txFollowUpPTPHeader.MsgLength);
        EthTSyn_PaddingPTPHeader(EthTSyn_MasterController[CtrlIdx].EthTSynCtrlIdx, &txFollowUpPTPHeader, &txFollowUpPtr[0]);
        EthTSyn_ConvertTimeStamp2Array(&EthTSyn_MasterController[CtrlIdx].Sync_EgressTimeStamp_TS, &txFollowUpPtr[ETHTSYN_PTP_HEADER_SIZE]);
        EthTSyn_PaddingSyncFUpTLV(&txFollowUpPtr[ETHTSYN_PTP_HEADER_SIZE + ETHTSYN_TIMESTAMP_SIZE]);
        ret = EthTSyn_TransmitPTPFrame(ETHTSYN_MAPPED_TO_ETHIF_CTRL_IDX(EthTSyn_MasterController[CtrlIdx].EthTSynCtrlIdx), txFollowUpBufIdx, txFollowUpPTPHeader.MsgLength, FALSE);
        if(E_OK == ret)
        {
            EthTSyn_MasterController[CtrlIdx].TxFollowUpBufIdx = txFollowUpBufIdx;
            EthTSyn_MasterController[CtrlIdx].ControllerSyncState = ETHTSYN_SYNC_STATE_MASTER_CURRENT_CYCLE_SENDINF_SUCCESSFULLY;            
        }
        else
        {
            EthTSyn_MasterController[CtrlIdx].ControllerSyncState = ETHTSYN_SYNC_STATE_MASTER_RETRANSMISSION_SYNC;
        }
    }
    else
    {
        EthTSyn_MasterController[CtrlIdx].ControllerSyncState = ETHTSYN_SYNC_STATE_MASTER_RETRANSMISSION_SYNC;
    }
#endif
    
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: EthTSyn_TransmitPTPPdelayRespFrame
*
* Description:   Service to transmit a Pdelay response frame
*
* Inputs:        uint8 index : Index of the EthTSyn controller
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, ETHTSYN_CODE) EthTSyn_TransmitPTPPdelayRespFrame
(
    uint8 CtrlIdx
)
{
    Std_ReturnType ret = E_NOT_OK;
    Eth_BufIdxType txPdelayRespBufIdx = (Eth_BufIdxType)0;
    EthTSyn_PTPHeaderType txPdelayRespPTPHeader;
    P2VAR(uint8, AUTOMATIC, ETHTSYN_APPL_DATA) txPdelayRespPtr;

    txPdelayRespPTPHeader.SequID = EthTSyn_MasterController[CtrlIdx].Ingress_PdelayReqSequId;
    txPdelayRespPTPHeader.Flags = ETHTSYN_PTP_HEADER_VALUE_FLAG_TWOSTEP;
    txPdelayRespPTPHeader.Flags |= ETHTSYN_PTP_HEADER_VALUE_FLAG_PTPTIMESCALE;
    txPdelayRespPTPHeader.MsgType =  ETHTSYN_PTP_HEADER_VALUE_MSGTYPE_PDELAYRESP;
    txPdelayRespPTPHeader.Control = ETHTSYN_PTP_HEADER_VALUE_CONTROL_PDELAY;
    txPdelayRespPTPHeader.LogMsgInterval = ETHTSYN_PTP_HEADER_VALUE_LOGMSGINTERVAL_RESERVED;
    txPdelayRespPTPHeader.MsgLength = ETHTSYN_PTP_HEADER_SIZE + ETHTSYN_PTP_PAYLOADSIZE_PDELAY;
    /* SWS_EthTSyn_00012 */
    ret = EthTSyn_GetTxBuffer(ETHTSYN_MAPPED_TO_ETHIF_CTRL_IDX(EthTSyn_MasterController[CtrlIdx].EthTSynCtrlIdx), txPdelayRespPTPHeader.MsgLength, &txPdelayRespBufIdx, &txPdelayRespPtr);

    if(E_OK == ret)
    {
        (void)memset(txPdelayRespPtr, (uint8)0, sizeof(txPdelayRespPtr));
        EthTSyn_PaddingPTPHeader(EthTSyn_MasterController[CtrlIdx].EthTSynCtrlIdx, &txPdelayRespPTPHeader, &txPdelayRespPtr[0]);
        EthTSyn_ConvertTimeStamp2Array(&EthTSyn_MasterController[CtrlIdx].IngressTimeStampPdelay_t2, &txPdelayRespPtr[ETHTSYN_PTP_HEADER_SIZE]);
        Bsw_MemCpy(&txPdelayRespPtr[ETHTSYN_PTP_HEADER_SIZE + ETHTSYN_TIMESTAMP_SIZE], &EthTSyn_MasterController[CtrlIdx].PdelayReqRxSrcPortId[0], sizeof(EthTSyn_MasterController[CtrlIdx].PdelayReqRxSrcPortId));
        if(E_OK == EthTSyn_TransmitPTPFrame(ETHTSYN_MAPPED_TO_ETHIF_CTRL_IDX(EthTSyn_MasterController[CtrlIdx].EthTSynCtrlIdx), txPdelayRespBufIdx, txPdelayRespPTPHeader.MsgLength, TRUE))
        {
            EthTSyn_MasterController[CtrlIdx].TxPdelayRespBufIdx = txPdelayRespBufIdx;
        }
        else
        {
            EthTSyn_MasterController[CtrlIdx].ControllerPdelayState = ETHTSYN_PDELAY_STATE_MASTER_SENDING_PDELAYRESP;
        }
    }
    else
    {
        EthTSyn_MasterController[CtrlIdx].ControllerPdelayState = ETHTSYN_PDELAY_STATE_MASTER_SENDING_PDELAYRESP;
    }
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: EthTSyn_TransmitPTPPdelayRespFupFrame
*
* Description:   Service to transmit a Pdelay response follow up frame
*
* Inputs:        uint8 CtrlIdx : Index of the Ethernet controller
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, ETHTSYN_CODE) EthTSyn_TransmitPTPPdelayRespFupFrame
(
    uint8 CtrlIdx
)
{
    Std_ReturnType ret = E_NOT_OK;
    Eth_BufIdxType txPdelayRespFUpBufIdx = (Eth_BufIdxType)0;
    EthTSyn_PTPHeaderType txPdelayRespFUpPTPHeader;
    P2VAR(uint8, AUTOMATIC, ETHTSYN_APPL_DATA) txPdelayRespFUpPtr;

    txPdelayRespFUpPTPHeader.SequID = EthTSyn_MasterController[CtrlIdx].Ingress_PdelayReqSequId;
    txPdelayRespFUpPTPHeader.Flags = ETHTSYN_PTP_HEADER_VALUE_NOFLAGS;
    txPdelayRespFUpPTPHeader.Flags |= ETHTSYN_PTP_HEADER_VALUE_FLAG_PTPTIMESCALE;
    txPdelayRespFUpPTPHeader.MsgType =  ETHTSYN_PTP_HEADER_VALUE_MSGTYPE_PDELAYRESPFUP;
    txPdelayRespFUpPTPHeader.Control = ETHTSYN_PTP_HEADER_VALUE_CONTROL_PDELAY;
    txPdelayRespFUpPTPHeader.LogMsgInterval = ETHTSYN_PTP_HEADER_VALUE_LOGMSGINTERVAL_RESERVED;
    txPdelayRespFUpPTPHeader.MsgLength = ETHTSYN_PTP_HEADER_SIZE + ETHTSYN_PTP_PAYLOADSIZE_PDELAY;

    ret = EthTSyn_GetTxBuffer(ETHTSYN_MAPPED_TO_ETHIF_CTRL_IDX(EthTSyn_MasterController[CtrlIdx].EthTSynCtrlIdx), txPdelayRespFUpPTPHeader.MsgLength, &txPdelayRespFUpBufIdx, &txPdelayRespFUpPtr);

    if(E_OK == ret)
    {
        (void)memset(txPdelayRespFUpPtr, (uint8)0, sizeof(txPdelayRespFUpPtr));
        EthTSyn_PaddingPTPHeader(EthTSyn_MasterController[CtrlIdx].EthTSynCtrlIdx, &txPdelayRespFUpPTPHeader, &txPdelayRespFUpPtr[0]);
        EthTSyn_ConvertTimeStamp2Array(&EthTSyn_MasterController[CtrlIdx].EgressTimeStampPdelay_t3, &txPdelayRespFUpPtr[ETHTSYN_PTP_HEADER_SIZE]);
        Bsw_MemCpy(&txPdelayRespFUpPtr[ETHTSYN_PTP_HEADER_SIZE + ETHTSYN_TIMESTAMP_SIZE], &EthTSyn_MasterController[CtrlIdx].PdelayReqRxSrcPortId[0], ETHTSYN_PTP_HEADER_OFFSET_SRCPORTIDENTITY_BYTE0);
        if(E_OK == EthTSyn_TransmitPTPFrame(ETHTSYN_MAPPED_TO_ETHIF_CTRL_IDX(EthTSyn_MasterController[CtrlIdx].EthTSynCtrlIdx), txPdelayRespFUpBufIdx, txPdelayRespFUpPTPHeader.MsgLength, FALSE))
        {
            EthTSyn_MasterController[CtrlIdx].TxPdelayRespFUpBufIdx = txPdelayRespFUpBufIdx;
            EthTSyn_MasterController[CtrlIdx].ControllerPdelayState = ETHTSYN_PDELAY_STATE_MASTER_WAITING_PDELAYREQ;
        }
        else
        {
            EthTSyn_MasterController[CtrlIdx].ControllerPdelayState = ETHTSYN_PDELAY_STATE_MASTER_SENDING_PDELAYRESPFUP;
        }
    }
    else
    {
        EthTSyn_MasterController[CtrlIdx].ControllerPdelayState = ETHTSYN_PDELAY_STATE_MASTER_SENDING_PDELAYRESPFUP;
    }
}
#endif

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: EthTSyn_PaddingPTPHeader
*
* Description:   Service to fill the PTP header for all outgoing EthTSyn frames
*
* Inputs:        uint8 CtrlIdx : Index of the Ethernet controller
*                EthTSyn_PTPHeaderType* PTPHeaderPtr : PTP header containing all bytes which do not have common values
*
* Outputs:       uint8* CurrentPTPHeaderPtr : Pointer to store the created 34 byte PTP header
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, ETHTSYN_CODE) EthTSyn_PaddingPTPHeader
(
    uint8 CtrlIdx,
    P2CONST(EthTSyn_PTPHeaderType, AUTOMATIC, ETHTSYN_APPL_DATA)PTPHeaderPtr, 
    P2VAR(uint8, AUTOMATIC, ETHTSYN_APPL_DATA) CurrentPTPHeaderPtr
)
{
    uint8 index;
    uint8 ControllerIndex = (uint8)0;

    ControllerIndex = CtrlIdx;

    CurrentPTPHeaderPtr[0] = PTPHeaderPtr->MsgType & ETHTSYN_MASK_BYTE_LOW_NIBBLE;
    CurrentPTPHeaderPtr[0] |= ETHTSYN_PTP_HEADER_VALUE_TRANSSPEC;
    CurrentPTPHeaderPtr[1] = ETHTSYN_PTP_HEADER_VALUE_VERSION;
    CurrentPTPHeaderPtr[2] = (uint8)((uint16)(PTPHeaderPtr->MsgLength & ETHTSYN_MASK_WORD_HIGH_BYTE) >> (uint16)8);
    CurrentPTPHeaderPtr[3] = (uint8)(PTPHeaderPtr->MsgLength & ETHTSYN_MASK_WORD_LOW_BYTE);
    CurrentPTPHeaderPtr[4] = ETHTSYN_PTP_HEADER_VALUE_DOMAINNUMBER;
    CurrentPTPHeaderPtr[5] = ETHTSYN_PTP_HEADER_VALUE_RESERVED;
    CurrentPTPHeaderPtr[6] = (uint8)((uint16)(PTPHeaderPtr->Flags & ETHTSYN_MASK_WORD_HIGH_BYTE) >> (uint16)8);
    CurrentPTPHeaderPtr[7] = (uint8)(PTPHeaderPtr->Flags & ETHTSYN_MASK_WORD_LOW_BYTE);
    if(PTPHeaderPtr->MsgType == ETHTSYN_PTP_HEADER_VALUE_MSGTYPE_SYNCFUP)
    {
#if((STD_ON == ETHTSYN_PORT_MASTER_SUPPORT) && (STD_ON == ETHTSYN_PORT_SLAVE_SUPPORT))
        if(EthTSyn_SlaveController[0].CurrentSyncReceived == TRUE)
        {
            CurrentPTPHeaderPtr[8] = (uint8)((EthTSyn_MasterController[ControllerIndex].CorrectionField_Integer) >> (uint8)40);
            CurrentPTPHeaderPtr[9] = (uint8)((EthTSyn_MasterController[ControllerIndex].CorrectionField_Integer) >> (uint8)32);
            CurrentPTPHeaderPtr[10] = (uint8)((EthTSyn_MasterController[ControllerIndex].CorrectionField_Integer) >> (uint8)24);
            CurrentPTPHeaderPtr[11] = (uint8)((EthTSyn_MasterController[ControllerIndex].CorrectionField_Integer) >> (uint8)16);
            CurrentPTPHeaderPtr[12] = (uint8)((EthTSyn_MasterController[ControllerIndex].CorrectionField_Integer) >> (uint8)8);
            CurrentPTPHeaderPtr[13] = (uint8)(EthTSyn_MasterController[ControllerIndex].CorrectionField_Integer);
            CurrentPTPHeaderPtr[14] = EthTSyn_SlaveController[0].CorrectionField_Fraction[0];
            CurrentPTPHeaderPtr[15] = EthTSyn_SlaveController[0].CorrectionField_Fraction[1];
            EthTSyn_SlaveController[0].CurrentSyncReceived = FALSE;
        }
        else
        {
            for(index = (uint8)8; index < (uint8)16; index++)
            {
                CurrentPTPHeaderPtr[index] = (uint8)0;
            }
        }
#else
        for(index = (uint8)8; index < (uint8)16; index++)
        {
            CurrentPTPHeaderPtr[index] = (uint8)0;
        }
#endif
    }
    else
    {
        for(index = (uint8)8; index < (uint8)16; index++)
        {
            CurrentPTPHeaderPtr[index] = (uint8)0;
        }
    }
    CurrentPTPHeaderPtr[16] = ETHTSYN_PTP_HEADER_VALUE_RESERVED;
    CurrentPTPHeaderPtr[17] = ETHTSYN_PTP_HEADER_VALUE_RESERVED;
    CurrentPTPHeaderPtr[18] = ETHTSYN_PTP_HEADER_VALUE_RESERVED;
    CurrentPTPHeaderPtr[19] = ETHTSYN_PTP_HEADER_VALUE_RESERVED;

    CurrentPTPHeaderPtr[20] = SrcMacAddr[0];
    CurrentPTPHeaderPtr[21] = SrcMacAddr[1];
    CurrentPTPHeaderPtr[22] = SrcMacAddr[2];
    CurrentPTPHeaderPtr[23] = ETHTSYN_PTP_HEADER_VALUE_SRCPORTIDENTITY_BYTE3;
    CurrentPTPHeaderPtr[24] = ETHTSYN_PTP_HEADER_VALUE_SRCPORTIDENTITY_BYTE4;
    CurrentPTPHeaderPtr[25] = SrcMacAddr[3];
    CurrentPTPHeaderPtr[26] = SrcMacAddr[4];
    CurrentPTPHeaderPtr[27] = SrcMacAddr[5];

#if(STD_ON == ETHTSYN_PORT_SLAVE_SUPPORT)
    if(ControllerIndex < ETHTSYN_GET_SLAVE_MAX_NUMBER)
    {
        CurrentPTPHeaderPtr[28] = (uint8)((uint16)(ETHTSYN_GET_SLAVE_PORTNUMBER & ETHTSYN_MASK_WORD_HIGH_BYTE) >> (uint16)8);
        CurrentPTPHeaderPtr[29] = (uint8)(ETHTSYN_GET_SLAVE_PORTNUMBER & ETHTSYN_MASK_WORD_LOW_BYTE);
    }
#endif
#if(STD_ON == ETHTSYN_PORT_MASTER_SUPPORT)
    if(ControllerIndex >= ETHTSYN_GET_SLAVE_MAX_NUMBER)
    {
        ControllerIndex -= ETHTSYN_GET_SLAVE_MAX_NUMBER;
        CurrentPTPHeaderPtr[28] = (uint8)((uint16)(ETHTSYN_GET_MASTER_PORTNUMBER & ETHTSYN_MASK_WORD_HIGH_BYTE) >> (uint16)8);
        CurrentPTPHeaderPtr[29] = (uint8)(ETHTSYN_GET_MASTER_PORTNUMBER & ETHTSYN_MASK_WORD_LOW_BYTE);
    }
#endif

    CurrentPTPHeaderPtr[30] = (uint8)((uint16)(PTPHeaderPtr->SequID & ETHTSYN_MASK_WORD_HIGH_BYTE) >> (uint16)8);
    CurrentPTPHeaderPtr[31] = (uint8)((uint16)(PTPHeaderPtr->SequID & ETHTSYN_MASK_WORD_LOW_BYTE));
    CurrentPTPHeaderPtr[32] = (uint8)PTPHeaderPtr->Control;
    CurrentPTPHeaderPtr[33] = (uint8)PTPHeaderPtr->LogMsgInterval;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: EthTSyn_ConvertTimeStamp2Array
*
* Description:   Service to convert the time stamp to a byte array ready to send via frame
*
* Inputs:        Eth_TimeStampType* TimeStampPtr : Pointer to time stamp which requires conversion
*
* Outputs:       uint8* BufPtr : Pointer to store the converted time stamp.
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
#if(STD_ON == ETHTSYN_PORT_MASTER_SUPPORT)
STATIC FUNC(void, ETHTSYN_CODE) EthTSyn_ConvertTimeStamp2Array
(
#if(STD_ON == ETHTSYN_HW_TIMESTAMP_SUPPORT)
    P2VAR(Eth_TimeStampType, AUTOMATIC, ETHTSYN_APPL_DATA) TimeStampPtr,
#else
    P2VAR(StbM_TimeStampType, AUTOMATIC, ETHTSYN_APPL_DATA) TimeStampPtr,
#endif
    P2VAR(uint8, AUTOMATIC, ETHTSYN_APPL_DATA) CurrentBufferPtr   
)
{
    CurrentBufferPtr[0] = (uint8)((uint16)(TimeStampPtr->secondsHi & ETHTSYN_MASK_WORD_HIGH_BYTE) >> (uint16)8);
    CurrentBufferPtr[1] = (uint8)(TimeStampPtr->secondsHi & ETHTSYN_MASK_WORD_LOW_BYTE);
    CurrentBufferPtr[2] = (uint8)((uint32)(TimeStampPtr->seconds & ETHTSYN_MASK_DWORD_HIGH_WORD_HIGH_BYTE) >> (uint32)24);
    CurrentBufferPtr[3] = (uint8)((uint32)(TimeStampPtr->seconds & ETHTSYN_MASK_DWORD_HIGH_WORD_LOW_BYTE) >> (uint32)16);
    CurrentBufferPtr[4] = (uint8)((uint32)(TimeStampPtr->seconds & ETHTSYN_MASK_DWORD_LOW_WORD_HIGH_BYTE) >> (uint32)8);
    CurrentBufferPtr[5] = (uint8)(TimeStampPtr->seconds & ETHTSYN_MASK_DWORD_LOW_WORD_LOW_BYTE);
    CurrentBufferPtr[6] = (uint8)((uint32)(TimeStampPtr->nanoseconds & ETHTSYN_MASK_DWORD_HIGH_WORD_HIGH_BYTE) >> (uint32)24);
    CurrentBufferPtr[7] = (uint8)((uint32)(TimeStampPtr->nanoseconds & ETHTSYN_MASK_DWORD_HIGH_WORD_LOW_BYTE) >> (uint32)16);
    CurrentBufferPtr[8] = (uint8)((uint32)(TimeStampPtr->nanoseconds & ETHTSYN_MASK_DWORD_LOW_WORD_HIGH_BYTE) >> (uint32)8);
    CurrentBufferPtr[9] = (uint8)((TimeStampPtr->nanoseconds & ETHTSYN_MASK_DWORD_LOW_WORD_LOW_BYTE));
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: EthTSyn_PaddingSyncFUpTLV
*
* Description:   Service to fill the TLV information of the follow up frame
*
* Inputs:        None
*
* Outputs:       uint8* CurrentSyncFUpTLVPtr : Pointer to store the created 32 byte follow_Up TLV information
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, ETHTSYN_CODE) EthTSyn_PaddingSyncFUpTLV
(
    P2VAR(uint8, AUTOMATIC, ETHTSYN_APPL_DATA) CurrentSyncFUpTLVPtr
)
{
    uint8 Index = (uint8)0;

    CurrentSyncFUpTLVPtr[0] = (uint8)((ETHTSYN_SYNCFUP_TLV_VALUE_TLVTYPE) >> (uint8)8);
    CurrentSyncFUpTLVPtr[1] = (uint8)ETHTSYN_SYNCFUP_TLV_VALUE_TLVTYPE;
    CurrentSyncFUpTLVPtr[2] = (uint8)((ETHTSYN_SYNCFUP_TLV_VALUE_LENGTH) >> (uint8)8);
    CurrentSyncFUpTLVPtr[3] = (uint8)ETHTSYN_SYNCFUP_TLV_VALUE_LENGTH;
    CurrentSyncFUpTLVPtr[4] = ETHTSYN_SYNCFUP_TLV_VALUE_ORGID_BYTE0;
    CurrentSyncFUpTLVPtr[5] = ETHTSYN_SYNCFUP_TLV_VALUE_ORGID_BYTE1;
    CurrentSyncFUpTLVPtr[6] = ETHTSYN_SYNCFUP_TLV_VALUE_ORGID_BYTE2;
    CurrentSyncFUpTLVPtr[7] = ETHTSYN_SYNCFUP_TLV_VALUE_ORG_SUBTYPE_BYTE0;
    CurrentSyncFUpTLVPtr[8] = ETHTSYN_SYNCFUP_TLV_VALUE_ORG_SUBTYPE_BYTE1;
    CurrentSyncFUpTLVPtr[9] = ETHTSYN_SYNCFUP_TLV_VALUE_ORG_SUBTYPE_BYTE2;
    CurrentSyncFUpTLVPtr[10] = (uint8)0;
    CurrentSyncFUpTLVPtr[11] = (uint8)0;
    CurrentSyncFUpTLVPtr[12] = (uint8)0;
    CurrentSyncFUpTLVPtr[13] = (uint8)0;
    CurrentSyncFUpTLVPtr[14] = (uint8)((ETHTSYN_SYNCFUP_TLV_VALUE_GM_TIMEBASE) >> (uint8)8);
    CurrentSyncFUpTLVPtr[15] = (uint8)ETHTSYN_SYNCFUP_TLV_VALUE_GM_TIMEBASE;

    for(Index = (uint8)16; Index < (uint8)32; Index++)
    {
        CurrentSyncFUpTLVPtr[Index] = (uint8)0;
    }
}
#endif

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: EthTSyn_GetTxBuffer
*
* Description:   Service to get Tx buffer and fill the PTP header
*
* Inputs:        uint8 CtrlIdx : Index of the EthIf controller
*                uint16 PTPLength : Length of the frame payload
*
* Outputs:       Eth_BufIdxType* BufIdxPtr : Pointer to the buffer index of the requested Tx frame buffer
*                EthTSyn_PtrUint8* BufPtr : Pointer to return the pointer of the Ethernet Tx frame buffer
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(Std_ReturnType, ETHTSYN_CODE) EthTSyn_GetTxBuffer
(
    uint8 CtrlIdx,
    uint16 PTPLength,
    P2VAR(Eth_BufIdxType, AUTOMATIC, ETHTSYN_APPL_DATA) BufIdxPtr,
    P2VAR(P2VAR(uint8, AUTOMATIC, AUTOMATIC), AUTOMATIC, ETHTSYN_APPL_DATA) BufPtr
)
{
    Std_ReturnType ret = E_NOT_OK;
    BufReq_ReturnType buf_ret = BUFREQ_E_NOT_OK;
    uint16 bufferSize = PTPLength;

    buf_ret = EthIf_ProvideTxBuffer(CtrlIdx, ETHTSYN_PTP_FRAMETYPE, ETHTSYN_GET_PTP_MESSAGE_PRIORITY, BufIdxPtr, BufPtr, &bufferSize);

    if(BUFREQ_OK == buf_ret)
    {
        ret = E_OK;
    }
    return ret;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: EthTSyn_TransmitPTPFrame
*
* Description:   Service to send the PTP frame
*
* Inputs:        uint8 CtrlIdx : Index of the EthIf controller
*                Eth_BufIdxType BufIdx : Buffer index of used Tx frame buffer.
*                uint16 PTPLength : Length of the PTP Frame
*                boolean TimeStampFlag : Activates egress time stamping.
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(Std_ReturnType, ETHTSYN_CODE) EthTSyn_TransmitPTPFrame
(
    uint8 CtrlIdx,
    Eth_BufIdxType BufIdx,
    uint16 PTPLength,
    boolean EnableTimeStampFlag
)
{
    Std_ReturnType ret = E_NOT_OK;

#if(STD_ON == ETHTSYN_HW_TIMESTAMP_SUPPORT)
    if(EnableTimeStampFlag == TRUE)
    {
        Eth_EnableEgressTimeStamp(CtrlIdx, BufIdx);
    }
#else
    (void)EnableTimeStampFlag;
#endif
    ret = EthIf_Transmit(CtrlIdx, BufIdx, ETHTSYN_PTP_FRAMETYPE, TRUE, PTPLength, &EthTSyn_DestMacAddr_PTP[0]);
    return ret;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name : EthTSyn_GetEthCurrentTime
*
* Description   : Return a time value according its definition out of the HW registers in Eth_TimeStampType
*
* Inputs        : timeBaseId : time base reference index
*
* Outputs       : timeStampPtr : current time stamp
*                 syncState : to inform wheter Ethernet is time synchronous or not
*
* return        : E_OK : successful
*                 E_NOT_OK : failed
*
* Limitations   : None
********************************************************************************
END_FUNCTION_HDR */
#if(STD_ON == ETHTSYN_PORT_SLAVE_SUPPORT)
STATIC FUNC(Std_ReturnType, ETHTSYN_CODE) EthTSyn_GetEthCurrentTime
(
#if(ETHTSYN_HW_TIMESTAMP_SUPPORT == STD_ON)
    P2VAR(Eth_TimeStampType, AUTOMATIC, ETHTSYN_APPL_DATA) TimeStampPtr,
#else
    StbM_SynchronizedTimeBaseType timeBaseId,
    P2VAR(StbM_TimeStampType, AUTOMATIC, ETHTSYN_APPL_DATA) TimeStampPtr,
#endif
    P2VAR(EthTSyn_SyncStateType, AUTOMATIC, ETHTSYN_APPL_DATA) syncState
)
{
    Std_ReturnType ret = E_NOT_OK;
#if(ETHTSYN_HW_TIMESTAMP_SUPPORT == STD_ON)
    uint8 index = (uint8)0;
    Eth_TimeStampQualType TimeQuality;
#else
    StbM_UserDataType UserDataPtr;
#endif /* ETHTSYN_HW_TIMESTAMP_SUPPORT == STD_ON */
    if(STD_UNINITIALIZED == EthTSyn_InitStatus)
    {
        ETHTSYN_DET_REPORT_ERROR(ETHTSYN_SERVICEID_GETCURRENTTIME, ETHTSYN_E_NOT_INITIALIZED);
    }
    else if(NULL_PTR == TimeStampPtr)
    {
        ETHTSYN_DET_REPORT_ERROR(ETHTSYN_SERVICEID_GETCURRENTTIME, ETHTSYN_E_PARAM_POINTER);
    }
    else if(syncState == NULL_PTR)
    {
        ETHTSYN_DET_REPORT_ERROR(ETHTSYN_SERVICEID_GETCURRENTTIME, ETHTSYN_E_PARAM);
    }
    else
    {
#if(ETHTSYN_HW_TIMESTAMP_SUPPORT == STD_ON)
        ret = Eth_GetCurrentTime(ETHTSYN_MAPPED_TO_ETHIF_CTRL_IDX(index), &TimeQuality, TimeStampPtr);
        if(TimeQuality != ETH_VALID)
        {
            *syncState = ETHTSYN_UNCERTAIN;
        }
        else
        {
            *syncState = EthTSyn_SlaveController[0].EcuSyncState;
        }
#else /* ETHTSYN_HW_TIMESTAMP_SUPPORT == STD_ON */
        UserDataPtr.userDataLength = (uint8)3;
        UserDataPtr.userByte0 = (uint8)1;
        UserDataPtr.userByte1 = (uint8)1;
        UserDataPtr.userByte2 = (uint8)1;
        ret = StbM_GetCurrentTime(timeBaseId, TimeStampPtr, &UserDataPtr);
#endif /* ETHTSYN_HW_TIMESTAMP_SUPPORT == STD_ON */
    }
    return ret;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: EthTSyn_TransmitPTPPdelayReqFrame
*
* Description:   Service to transmit a Pdelay request frame
*
* Inputs:        uint8 index : Index of the EthTSyn controller
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, ETHTSYN_CODE) EthTSyn_TransmitPTPPdelayReqFrame
(
    uint8 CtrlIdx
)
{
    Std_ReturnType ret = E_NOT_OK;
    Eth_BufIdxType txPdelayReqBufIdx = (Eth_BufIdxType)0;
    EthTSyn_PTPHeaderType txPdelayReqPTPHeader;
    P2VAR(uint8, AUTOMATIC, ETHTSYN_APPL_DATA) txPdelayReqPtr;

    txPdelayReqPTPHeader.SequID = EthTSyn_SlaveController[CtrlIdx].TxPdelayReqSequId;
    txPdelayReqPTPHeader.Flags = ETHTSYN_PTP_HEADER_VALUE_NOFLAGS;
    txPdelayReqPTPHeader.Flags |= ETHTSYN_PTP_HEADER_VALUE_FLAG_PTPTIMESCALE;
    txPdelayReqPTPHeader.MsgType =  ETHTSYN_PTP_HEADER_VALUE_MSGTYPE_PDELAYREQ;
    txPdelayReqPTPHeader.Control = ETHTSYN_PTP_HEADER_VALUE_CONTROL_PDELAY;
    txPdelayReqPTPHeader.LogMsgInterval = ETHTSYN_GET_SLAVE_PDELAYREQTXMSGLOGINTERVAL;
    txPdelayReqPTPHeader.MsgLength = ETHTSYN_PTP_HEADER_SIZE + ETHTSYN_PTP_PAYLOADSIZE_PDELAY;
    /* SWS_EthTSyn_00011 */
    ret = EthTSyn_GetTxBuffer(ETHTSYN_MAPPED_TO_ETHIF_CTRL_IDX(EthTSyn_SlaveController[CtrlIdx].EthTSynCtrlIdx), txPdelayReqPTPHeader.MsgLength, &txPdelayReqBufIdx, &txPdelayReqPtr);

    if(E_OK == ret)
    {
        (void)memset(txPdelayReqPtr, (uint8)0, sizeof(txPdelayReqPtr));
        EthTSyn_PaddingPTPHeader(ETHTSYN_MAPPED_TO_ETHIF_CTRL_IDX(EthTSyn_SlaveController[CtrlIdx].EthTSynCtrlIdx), &txPdelayReqPTPHeader, &txPdelayReqPtr[0]);
        ret = EthTSyn_TransmitPTPFrame(ETHTSYN_MAPPED_TO_ETHIF_CTRL_IDX(EthTSyn_SlaveController[CtrlIdx].EthTSynCtrlIdx), txPdelayReqBufIdx, txPdelayReqPTPHeader.MsgLength, TRUE);
        if(E_OK == ret)
        {
            EthTSyn_SlaveController[CtrlIdx].TxPdelayReqBufIdx = txPdelayReqBufIdx;
        }
        else
        {
            EthTSyn_SlaveController[CtrlIdx].ControllerPdelayState = ETHTSYN_PDELAY_STATE_SLAVE_RETRANSMISSION_PDELAYREQ;
        }
    }
    else
    {
        EthTSyn_SlaveController[CtrlIdx].ControllerPdelayState = ETHTSYN_PDELAY_STATE_SLAVE_RETRANSMISSION_PDELAYREQ;
    }
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: EthTSyn_SlaveProcessRxPTPMsg
*
* Description:   Slave controller process the received message
*
* Inputs:        uint8 CtrlIdx : Index of the EthTSyn controller
*                uint8* RxDataPtr : Pointer to the received PTP frames
*                uint16 LenByte : Length of the payload contained in the received Rx buffer
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, ETHTSYN_CODE) EthTSyn_SlaveProcessRxPTPMsg
(
    uint8 CtrlIdx,
    P2VAR(uint8, AUTOMATIC, ETHTSYN_APPL_DATA) RxDataPtr,
    uint16 PTPMsgLength
)
{
    uint16 rcvdPTPMsgSequID = (uint16)0;
    Std_ReturnType ret = E_NOT_OK;
    uint8 msgType = (uint8)((uint8)RxDataPtr[ETHTSYN_PTP_HEADER_OFFSET_MSGTYPE] & ETHTSYN_MASK_BYTE_LOW_NIBBLE);
    uint16 MsgLength = PTPMsgLength;

    if((ETHTSYN_SYNC_STATE_SLAVE_WAITING_SYNC == EthTSyn_SlaveController[CtrlIdx].ControllerSyncState) && (ETHTSYN_PTP_HEADER_VALUE_MSGTYPE_SYNC == msgType))
    {
        if(((ETHTSYN_PTP_HEADER_SIZE + ETHTSYN_PTP_PAYLOADSIZE_SYNC) == MsgLength) ||  /*with vlan*/
            ((ETHTSYN_PTP_HEADER_SIZE + ETHTSYN_PTP_PAYLOADSIZE_SYNC + ETHTSYN_PTP_SYNC_PADDING_SIZE) == MsgLength) || /*without vlan*/
            ((ETHTSYN_PTP_HEADER_SIZE + ETHTSYN_PTP_PAYLOADSIZE_SYNC + ETHTSYN_PTP_SYNC_PADDING_SIZE + ETHTSYN_PTP_ETHERNET_FCS_SIZE) == MsgLength) || /*without vlan and CS length not decreased*/
            ((ETHTSYN_PTP_HEADER_SIZE + ETHTSYN_PTP_PAYLOADSIZE_SYNC + ETHTSYN_PTP_ETHERNET_FCS_SIZE) == MsgLength))/*with vlan and CS length not decreased*/
        {
            Bsw_MemCpy(&EthTSyn_SlaveController[CtrlIdx].RxSyncSourcePortId[0], &RxDataPtr[ETHTSYN_PTP_HEADER_OFFSET_SRCPORTIDENTITY_BYTE0], ETHTSYN_PTP_HEADER_SRCPORTIDENTITY_SIZE);
            EthTSyn_SlaveController[CtrlIdx].Ingress_SyncSequId = ETHTSYN_GET_SEQUENCEID_FROM_RCVDMESSAGE(RxDataPtr);
            ret = EthTSyn_GetIngressTimeStamp(CtrlIdx, RxDataPtr, &EthTSyn_SlaveController[CtrlIdx].Sync_IngressTimeStamp_TR);
            if(E_OK == ret)
            {
                EthTSyn_SlaveController[CtrlIdx].ControllerSyncState = ETHTSYN_SYNC_STATE_SLAVE_WAITING_FOLLOW_UP;
            }
            else
            {
                EthTSyn_SlaveController[CtrlIdx].ControllerSyncState = ETHTSYN_SYNC_STATE_SLAVE_WAITING_SYNC;   
            }
        }
        else
        {
            EthTSyn_SlaveController[CtrlIdx].ControllerSyncState = ETHTSYN_SYNC_STATE_SLAVE_WAITING_SYNC;  
        }
    }
    else if((ETHTSYN_SYNC_STATE_SLAVE_WAITING_FOLLOW_UP == EthTSyn_SlaveController[CtrlIdx].ControllerSyncState) && (ETHTSYN_PTP_HEADER_VALUE_MSGTYPE_SYNCFUP == msgType))
    {
        rcvdPTPMsgSequID = ETHTSYN_GET_SEQUENCEID_FROM_RCVDMESSAGE(RxDataPtr);
        if(rcvdPTPMsgSequID == EthTSyn_SlaveController[CtrlIdx].Ingress_SyncSequId)
        {
            if(E_OK == Bsw_MemCmp(&EthTSyn_SlaveController[CtrlIdx].RxSyncSourcePortId[0],
                                  &RxDataPtr[ETHTSYN_PTP_HEADER_OFFSET_SRCPORTIDENTITY_BYTE0],
                                  ETHTSYN_PTP_HEADER_SRCPORTIDENTITY_SIZE))
            {
                EthTSyn_SlaveController[CtrlIdx].Sync_OriginTimeStamp.secondsHi = ETHTSYN_CONVERT_ARRAY_TO_TIMESTAMP_SECONDSHI(RxDataPtr);
                EthTSyn_SlaveController[CtrlIdx].Sync_OriginTimeStamp.seconds = ETHTSYN_CONVERT_ARRAY_TO_TIMESTAMP_SECONDS(RxDataPtr);
                EthTSyn_SlaveController[CtrlIdx].Sync_OriginTimeStamp.nanoseconds = ETHTSYN_CONVERT_ARRAY_TO_TIMESTAMP_NANOSECONDS(RxDataPtr);
                Bsw_MemCpy(&EthTSyn_SlaveController[CtrlIdx].CorrectionField_Fraction[0], &RxDataPtr[ETHTSYN_PTP_HEADER_OFFSET_CORRECTIONFIELD_BYTE0 + (uint8)6], (uint32)2);
#if(STD_ON == ETHTSYN_PORT_MASTER_SUPPORT) 
                EthTSyn_MasterController[CtrlIdx].CorrectionField_Integer = ((uint64)RxDataPtr[ETHTSYN_PTP_HEADER_OFFSET_CORRECTIONFIELD_BYTE0 + (uint8)0] << (uint64)40) + ((uint64)RxDataPtr[ETHTSYN_PTP_HEADER_OFFSET_CORRECTIONFIELD_BYTE0 + (uint8)1] << (uint64)32) +  \
                                                                            ((uint64)RxDataPtr[ETHTSYN_PTP_HEADER_OFFSET_CORRECTIONFIELD_BYTE0 + (uint8)2] << (uint64)24) + ((uint64)RxDataPtr[ETHTSYN_PTP_HEADER_OFFSET_CORRECTIONFIELD_BYTE0 + (uint8)3] << (uint64)16) + \
                                                                            ((uint64)RxDataPtr[ETHTSYN_PTP_HEADER_OFFSET_CORRECTIONFIELD_BYTE0 + (uint8)4] << (uint64)8) + ((uint64)RxDataPtr[ETHTSYN_PTP_HEADER_OFFSET_CORRECTIONFIELD_BYTE0+ (uint8)5]);
                if(EthTSyn_SlaveController[CtrlIdx].AccomplishMeasuringDelay == TRUE)
                {
                    EthTSyn_MasterController[CtrlIdx].CorrectionField_Integer += (uint64)EthTSyn_SlaveController[CtrlIdx].NeighborMeanPropDelay;
                }
                else
                {
                    EthTSyn_MasterController[CtrlIdx].CorrectionField_Integer += (uint64)EthTSyn_SlaveController[CtrlIdx].DefaultLinkDelay;
                }
#else 
                EthTSyn_SlaveController[CtrlIdx].CorrectionField_Integer = ((uint64)RxDataPtr[ETHTSYN_PTP_HEADER_OFFSET_CORRECTIONFIELD_BYTE0 + (uint8)0] << (uint64)40) + ((uint64)RxDataPtr[ETHTSYN_PTP_HEADER_OFFSET_CORRECTIONFIELD_BYTE0 + (uint8)1] << (uint64)32) +  \
                                                                        ((uint64)RxDataPtr[ETHTSYN_PTP_HEADER_OFFSET_CORRECTIONFIELD_BYTE0 + (uint8)2] << (uint64)24) + ((uint64)RxDataPtr[ETHTSYN_PTP_HEADER_OFFSET_CORRECTIONFIELD_BYTE0 + (uint8)3] << (uint64)16) + \
                                                                        ((uint64)RxDataPtr[ETHTSYN_PTP_HEADER_OFFSET_CORRECTIONFIELD_BYTE0 + (uint8)4] << (uint64)8) + ((uint64)RxDataPtr[ETHTSYN_PTP_HEADER_OFFSET_CORRECTIONFIELD_BYTE0+ (uint8)5]);
                if(EthTSyn_SlaveController[CtrlIdx].AccomplishMeasuringDelay == TRUE)
                {
                    EthTSyn_SlaveController[CtrlIdx].CorrectionField_Integer += (uint64)EthTSyn_SlaveController[CtrlIdx].NeighborMeanPropDelay;
                }
                else
                {
                    EthTSyn_SlaveController[CtrlIdx].CorrectionField_Integer += (uint64)EthTSyn_SlaveController[CtrlIdx].DefaultLinkDelay;
                }
    #endif
                EthTSyn_SlaveController[CtrlIdx].ControllerSyncState = ETHTSYN_SYNC_STATE_SLAVE_UPDATING;
            }
            else
            {
                EthTSyn_SlaveController[CtrlIdx].ControllerSyncState = ETHTSYN_SYNC_STATE_SLAVE_WAITING_SYNC; 
            }
        }
        else
        {
            EthTSyn_SlaveController[CtrlIdx].ControllerSyncState = ETHTSYN_SYNC_STATE_SLAVE_WAITING_SYNC;   
        }        
    }
    else
    {
        /*do nothing*/
    }

    if((ETHTSYN_PDELAY_STATE_SLAVE_WAITING_PDELAYRESP == EthTSyn_SlaveController[CtrlIdx].ControllerPdelayState) && (ETHTSYN_PTP_HEADER_VALUE_MSGTYPE_PDELAYRESP == msgType))
    {
        rcvdPTPMsgSequID = ETHTSYN_GET_SEQUENCEID_FROM_RCVDMESSAGE(RxDataPtr);

        Bsw_MemCpy(&EthTSyn_SlaveController[CtrlIdx].RxPdelayRespSourcePortId[0],
                              &RxDataPtr[ETHTSYN_PTP_HEADER_OFFSET_SRCPORTIDENTITY_BYTE0],
                              ETHTSYN_PTP_HEADER_SRCPORTIDENTITY_SIZE);
		if(rcvdPTPMsgSequID == EthTSyn_SlaveController[CtrlIdx].TxPdelayReqSequId)
		{
			EthTSyn_ProcessRxPTPPdelayRespFrame(CtrlIdx, RxDataPtr);
		}
		else
		{
			EthTSyn_SlaveController[CtrlIdx].ControllerPdelayState = ETHTSYN_PDELAY_STATE_SLAVE_RETRANSMISSION_PDELAYREQ;
		}
        
        
    }
    else if((ETHTSYN_PDELAY_STATE_SLAVE_WAITING_PDELAYRESPFUP == EthTSyn_SlaveController[CtrlIdx].ControllerPdelayState) && (ETHTSYN_PTP_HEADER_VALUE_MSGTYPE_PDELAYRESPFUP == msgType))
    {
        rcvdPTPMsgSequID = ETHTSYN_GET_SEQUENCEID_FROM_RCVDMESSAGE(RxDataPtr);

        if(E_OK == Bsw_MemCmp(&EthTSyn_SlaveController[CtrlIdx].RxPdelayRespSourcePortId[0],
                                &RxDataPtr[ETHTSYN_PTP_HEADER_OFFSET_SRCPORTIDENTITY_BYTE0],
                                ETHTSYN_PTP_HEADER_SRCPORTIDENTITY_SIZE))
        {
            if(rcvdPTPMsgSequID == EthTSyn_SlaveController[CtrlIdx].TxPdelayReqSequId)
            {
                EthTSyn_SlaveController[CtrlIdx].Pdelay_EgressTimeStamp_t3.secondsHi = ETHTSYN_CONVERT_ARRAY_TO_TIMESTAMP_SECONDSHI(RxDataPtr);
                EthTSyn_SlaveController[CtrlIdx].Pdelay_EgressTimeStamp_t3.seconds = ETHTSYN_CONVERT_ARRAY_TO_TIMESTAMP_SECONDS(RxDataPtr);
                EthTSyn_SlaveController[CtrlIdx].Pdelay_EgressTimeStamp_t3.nanoseconds = ETHTSYN_CONVERT_ARRAY_TO_TIMESTAMP_NANOSECONDS(RxDataPtr);
                EthTSyn_SlaveController[CtrlIdx].ControllerPdelayState = ETHTSYN_PDELAY_STATE_SLAVE_MEASUREING_DELAY;
                if(ETHTSYN_SEQUENCEID_MAX ==  EthTSyn_SlaveController[CtrlIdx].TxPdelayReqSequId)
                {
                    EthTSyn_SlaveController[CtrlIdx].TxPdelayReqSequId = (uint16)0;
                }
                else
                {
                    EthTSyn_SlaveController[CtrlIdx].TxPdelayReqSequId++;
                }
            }
            else
            {
                EthTSyn_SlaveController[CtrlIdx].ControllerPdelayState = ETHTSYN_PDELAY_STATE_SLAVE_RETRANSMISSION_PDELAYREQ;
            } 
        }
        else
        {
            EthTSyn_SlaveController[CtrlIdx].ControllerPdelayState = ETHTSYN_PDELAY_STATE_SLAVE_RETRANSMISSION_PDELAYREQ;
        } 
    }
    else
    {
        /*do nothing*/
    }
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: EthTSyn_SlaveControllerUpdateLocalClock
*
* Description:   Service to process received Pdelay response frames
*
* Inputs:        -CtrlIdx : EthTSyn controller index the frame belongs to
*                -DataPtr : Pointer to the payload of the frame
*
* Outputs:       Sequence number which is stored in the PTP header
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, ETHTSYN_CODE) EthTSyn_SlaveControllerUpdateLocalClock
(
    uint8 CtrlIdx
)
{
    Std_ReturnType ret = E_NOT_OK;
    Eth_TimeIntDiffType timeOffsetInCurrentJump;
#if(ETHTSYN_HW_TIMESTAMP_SUPPORT == STD_ON)
    Eth_TimeStampType currentTimeInCurrentJump;
    Eth_TimeStampType sync_RcvdGMTimeStamp;
    Eth_TimeStampType correctionField_TimeStamp;
#else
    StbM_TimeStampType currentTimeInCurrentJump;
    StbM_TimeStampType sync_RcvdGMTimeStamp;
    StbM_TimeStampType correctionField_TimeStamp;
#endif
    StbM_TimeStampType givenGMTimeStamp;
    EthTSyn_SyncStateType ecuSyncState;
    StbM_UserDataType *userdata = NULL_PTR;

    sync_RcvdGMTimeStamp.nanoseconds = (uint32)0;
    sync_RcvdGMTimeStamp.seconds = (uint32)0;
    sync_RcvdGMTimeStamp.secondsHi = (uint16)0;

    sync_RcvdGMTimeStamp.secondsHi = EthTSyn_SlaveController[CtrlIdx].Sync_OriginTimeStamp.secondsHi;
    sync_RcvdGMTimeStamp.seconds = EthTSyn_SlaveController[CtrlIdx].Sync_OriginTimeStamp.seconds;
    sync_RcvdGMTimeStamp.nanoseconds = EthTSyn_SlaveController[CtrlIdx].Sync_OriginTimeStamp.nanoseconds;

#if(STD_ON == ETHTSYN_PORT_MASTER_SUPPORT)
    correctionField_TimeStamp.nanoseconds = (uint32)(EthTSyn_MasterController[CtrlIdx].CorrectionField_Integer % (uint64)(ETHTSYN_NANOSEC_MAX + (uint32)1));
    correctionField_TimeStamp.seconds = (uint32)(EthTSyn_MasterController[CtrlIdx].CorrectionField_Integer / (uint64)(ETHTSYN_NANOSEC_MAX + (uint32)1));
    correctionField_TimeStamp.secondsHi = (uint16)(((EthTSyn_MasterController[CtrlIdx].CorrectionField_Integer / (uint64)(ETHTSYN_NANOSEC_MAX + (uint32)1)) >> (uint32)32));
#else
    correctionField_TimeStamp.nanoseconds = (uint32)(EthTSyn_SlaveController[CtrlIdx].CorrectionField_Integer % (uint64)(ETHTSYN_NANOSEC_MAX + (uint32)1));
    correctionField_TimeStamp.seconds = (uint32)(EthTSyn_SlaveController[CtrlIdx].CorrectionField_Integer / (uint64)(ETHTSYN_NANOSEC_MAX + (uint32)1));
    correctionField_TimeStamp.secondsHi = (uint16)(((EthTSyn_SlaveController[CtrlIdx].CorrectionField_Integer / (uint64)(ETHTSYN_NANOSEC_MAX + (uint32)1)) >> (uint64)32));
#endif

    EthTSyn_AddEthTimeStamp(&sync_RcvdGMTimeStamp, &correctionField_TimeStamp);
    EthTSyn_DiffEthTimeStamp(&sync_RcvdGMTimeStamp, &EthTSyn_SlaveController[CtrlIdx].Sync_IngressTimeStamp_TR, &timeOffsetInCurrentJump);
    if((timeOffsetInCurrentJump.diff.nanoseconds > (ETHTSYN_HW_CORRECTION_THRESHOLD * ETHTSYN_MILLISECOND_TO_NANOSECOND)) || (timeOffsetInCurrentJump.diff.seconds != (uint32)0) || (timeOffsetInCurrentJump.diff.secondsHi != (uint16)0))
    {
#if(ETHTSYN_HW_TIMESTAMP_SUPPORT == STD_ON)
        ret = EthTSyn_GetEthCurrentTime(&currentTimeInCurrentJump, &ecuSyncState);
#else
        ret = EthTSyn_GetEthCurrentTime(ETHTSYN_GET_SLAVE_TIMEBASEID, &currentTimeInCurrentJump, &ecuSyncState);
#endif
        if(ret == E_OK)
        {
            EthTSyn_DiffEthTimeStamp(&currentTimeInCurrentJump, &EthTSyn_SlaveController[CtrlIdx].Sync_IngressTimeStamp_TR, &timeOffsetInCurrentJump);
            currentTimeInCurrentJump.nanoseconds = timeOffsetInCurrentJump.diff.nanoseconds;
            currentTimeInCurrentJump.seconds = timeOffsetInCurrentJump.diff.seconds;
            currentTimeInCurrentJump.secondsHi = timeOffsetInCurrentJump.diff.secondsHi;
            EthTSyn_AddEthTimeStamp(&sync_RcvdGMTimeStamp, &currentTimeInCurrentJump);
            givenGMTimeStamp.nanoseconds = sync_RcvdGMTimeStamp.nanoseconds;
            givenGMTimeStamp.seconds = sync_RcvdGMTimeStamp.seconds;
            givenGMTimeStamp.secondsHi = sync_RcvdGMTimeStamp.secondsHi;
            givenGMTimeStamp.timeBaseStatus.GLOBAL_TIME_BASE = (uint8)1;
            givenGMTimeStamp.timeBaseStatus.SYNC_TO_GATEWAY = (uint8)0;
            if(ETHTSYN_NEVERSYNC == EthTSyn_SlaveController[CtrlIdx].EcuSyncState)
            {
#if(ETHTSYN_HW_TIMESTAMP_SUPPORT == STD_ON)
                ret = EthTSyn_GetEthCurrentTime(&EthTSyn_SlaveController[0].TimeStampInFirstSync, &ecuSyncState);
#else
                ret = EthTSyn_GetEthCurrentTime(ETHTSYN_GET_SLAVE_TIMEBASEID, &EthTSyn_SlaveController[0].TimeStampInFirstSync, &ecuSyncState);
#endif
            }
            if(ret == E_OK)
            {
                /*PRQA S 3416 ++*/
                if(E_OK == StbM_BusSetGlobalTime(ETHTSYN_GET_SLAVE_TIMEBASEID, (const StbM_TimeStampType *)&givenGMTimeStamp, (const StbM_UserDataType *)userdata, (boolean)givenGMTimeStamp.timeBaseStatus.SYNC_TO_GATEWAY))
                {
                    EthTSyn_SlaveController[CtrlIdx].EcuSyncState = ETHTSYN_SYNC;
                }
                /*PRQA S 3416 --*/
            }
        }
        if(ret != E_OK)
        {
            EthTSyn_SlaveController[CtrlIdx].ControllerSyncState = ETHTSYN_SYNC_STATE_SLAVE_WAITING_SYNC;   
        }
    }
    else
    {
        EthTSyn_SlaveController[CtrlIdx].EcuSyncState = ETHTSYN_SYNC;
    }    
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: EthTSyn_ProcessRxPTPPdelayRespFrame
*
* Description:   Service to process received Pdelay response frames
*
* Inputs:        -CtrlIdx : EthTSyn controller index the frame belongs to
*                -DataPtr : Pointer to the payload of the frame
*
* Outputs:       Sequence number which is stored in the PTP header
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, ETHTSYN_CODE) EthTSyn_ProcessRxPTPPdelayRespFrame
(
    uint8 CtrlIdx,
    P2VAR(uint8, AUTOMATIC, ETHTSYN_APPL_DATA) RxDataPtr
)
{
    Eth_TimeIntDiffType TimeStampDiff;

    if(E_OK == EthTSyn_GetIngressTimeStamp(CtrlIdx, RxDataPtr, &EthTSyn_SlaveController[CtrlIdx].Pdelay_IngressTimeStamp_t4))
    {
        EthTSyn_DiffEthTimeStamp(&EthTSyn_SlaveController[CtrlIdx].Pdelay_IngressTimeStamp_t4, &EthTSyn_SlaveController[CtrlIdx].Pdelay_EgressTimeStamp_t1, &TimeStampDiff);

        if((FALSE == TimeStampDiff.sign) || ((uint16)0 != TimeStampDiff.diff.secondsHi) || ((uint32)0 != TimeStampDiff.diff.seconds) || (ETHTSYN_NANOSEC_MAX < TimeStampDiff.diff.nanoseconds))
        {
            EthTSyn_SlaveController[CtrlIdx].ControllerPdelayState = ETHTSYN_PDELAY_STATE_SLAVE_RETRANSMISSION_PDELAYREQ;
        }
        else
        {
            EthTSyn_SlaveController[CtrlIdx].Diff_TimeStamp_t4_t1.nanoseconds = TimeStampDiff.diff.nanoseconds;
            EthTSyn_SlaveController[CtrlIdx].Pdelay_IngressTimeStamp_t2.secondsHi = ETHTSYN_CONVERT_ARRAY_TO_TIMESTAMP_SECONDSHI(RxDataPtr);
            EthTSyn_SlaveController[CtrlIdx].Pdelay_IngressTimeStamp_t2.seconds = ETHTSYN_CONVERT_ARRAY_TO_TIMESTAMP_SECONDS(RxDataPtr);
            EthTSyn_SlaveController[CtrlIdx].Pdelay_IngressTimeStamp_t2.nanoseconds = ETHTSYN_CONVERT_ARRAY_TO_TIMESTAMP_NANOSECONDS(RxDataPtr);
            if(ETHTSYN_NANOSEC_MAX > EthTSyn_SlaveController[CtrlIdx].Pdelay_IngressTimeStamp_t2.nanoseconds)
            {
                EthTSyn_SlaveController[CtrlIdx].ControllerPdelayState = ETHTSYN_PDELAY_STATE_SLAVE_WAITING_PDELAYRESPFUP; // @suppress("Field cannot be resolved")
            }
            else
            {
                EthTSyn_SlaveController[CtrlIdx].ControllerPdelayState = ETHTSYN_PDELAY_STATE_SLAVE_RETRANSMISSION_PDELAYREQ;
            }
        }
    }
    else
    {
        EthTSyn_SlaveController[CtrlIdx].ControllerPdelayState = ETHTSYN_PDELAY_STATE_SLAVE_RETRANSMISSION_PDELAYREQ;
    }
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: EthTSyn_SlaveControllerMeasuringDelay
*
* Description:   Service to process received follow up frames
*
* Inputs:        CtrlIdx : index of the EthTSyn controller
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, ETHTSYN_CODE) EthTSyn_SlaveControllerMeasuringDelay
(
    uint8 CtrlIdx
)
{
    Eth_TimeIntDiffType TimeStampDiff;
#if(ETHTSYN_HW_TIMESTAMP_SUPPORT == STD_ON)
    Eth_TimeStampType TmpTimeStamp_t3_t2;
#else
    StbM_TimeStampType TmpTimeStamp_t3_t2;
#endif
    uint32 neighborDelay = (uint32)0;

    EthTSyn_DiffEthTimeStamp(&EthTSyn_SlaveController[CtrlIdx].Pdelay_EgressTimeStamp_t3, &EthTSyn_SlaveController[CtrlIdx].Pdelay_IngressTimeStamp_t2, &TimeStampDiff);
    if((FALSE == TimeStampDiff.sign) || ((uint16)0 != TimeStampDiff.diff.secondsHi) || ((uint32)0 != TimeStampDiff.diff.seconds) || (ETHTSYN_NANOSEC_MAX < TimeStampDiff.diff.nanoseconds))
    {
        EthTSyn_SlaveController[CtrlIdx].ControllerPdelayState = ETHTSYN_PDELAY_STATE_SLAVE_RETRANSMISSION_PDELAYREQ;
    }
    else
    {
        TmpTimeStamp_t3_t2.nanoseconds = TimeStampDiff.diff.nanoseconds;
        TmpTimeStamp_t3_t2.seconds = TimeStampDiff.diff.seconds;
        TmpTimeStamp_t3_t2.secondsHi = TimeStampDiff.diff.secondsHi;
        EthTSyn_DiffEthTimeStamp(&EthTSyn_SlaveController[CtrlIdx].Diff_TimeStamp_t4_t1, &TmpTimeStamp_t3_t2, &TimeStampDiff);
        if((FALSE == TimeStampDiff.sign) || ((uint16)0 != TimeStampDiff.diff.secondsHi) || ((uint32)0 != TimeStampDiff.diff.seconds) || (ETHTSYN_NANOSEC_MAX < TimeStampDiff.diff.nanoseconds))
        {
            EthTSyn_SlaveController[CtrlIdx].ControllerPdelayState = ETHTSYN_PDELAY_STATE_SLAVE_RETRANSMISSION_PDELAYREQ;
        }
        else
        {
            neighborDelay = TimeStampDiff.diff.nanoseconds/(uint32)2;
            EthTSyn_SlaveController[CtrlIdx].NeighborMeanPropDelay = neighborDelay;
            EthTSyn_SlaveController[CtrlIdx].AccomplishMeasuringDelay = TRUE;
        }       
    }
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: EthTSyn_DiffEthTimeStamp
*
* Description:   Service to subtract two time stamps
*
* Inputs:        TimeStamp_MinuendPtr : Minuend pointer to a time stamp for subtraction
*                TimeStamp_SubtrahendPtr : Subtrahend pointer to a time stamp for subtraction.
*
* Outputs:       TimeStamp_ResultPtr : Result pointer provides a variable for the result of the
*                                      subtraction.
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, ETHTSYN_CODE) EthTSyn_DiffEthTimeStamp
(
#if(ETHTSYN_HW_TIMESTAMP_SUPPORT == STD_ON)
    P2CONST(Eth_TimeStampType, AUTOMATIC, ETHTSYN_APPL_DATA) SubtractedTimeStampPtr,
    P2CONST(Eth_TimeStampType, AUTOMATIC, ETHTSYN_APPL_DATA) MinusTimeStampPtr,
#else
    P2CONST(StbM_TimeStampType, AUTOMATIC, ETHTSYN_APPL_DATA) SubtractedTimeStampPtr,
    P2CONST(StbM_TimeStampType, AUTOMATIC, ETHTSYN_APPL_DATA) MinusTimeStampPtr,
#endif
    P2VAR(Eth_TimeIntDiffType, AUTOMATIC, ETHTSYN_APPL_DATA) DiffTimeStampPtr
)
{
    boolean signFlag = FALSE;
#if(ETHTSYN_HW_TIMESTAMP_SUPPORT == STD_ON)
    Eth_TimeStampType subtractedTimeStamp;
    Eth_TimeStampType minusTimeStamp;
    Eth_TimeStampType tempTimeStamp;
#else
    StbM_TimeStampType subtractedTimeStamp;
    StbM_TimeStampType minusTimeStamp;
    StbM_TimeStampType tempTimeStamp;
#endif
    subtractedTimeStamp = *SubtractedTimeStampPtr;
    minusTimeStamp = *MinusTimeStampPtr;

    if(SubtractedTimeStampPtr->secondsHi < MinusTimeStampPtr->secondsHi)
    {

    }
    else if(SubtractedTimeStampPtr->secondsHi == MinusTimeStampPtr->secondsHi)
    {
        if(SubtractedTimeStampPtr->seconds < MinusTimeStampPtr->seconds)
        {

        }
        else if(SubtractedTimeStampPtr->seconds == MinusTimeStampPtr->seconds)
        {
            if(SubtractedTimeStampPtr->nanoseconds < MinusTimeStampPtr->nanoseconds)
            {

            }
            else
            {
                signFlag = TRUE;
            }
        }
        else
        {
            signFlag = TRUE;
        }        
    }
    else
    {
        signFlag = TRUE;
    }
    if(signFlag == FALSE)
    {
        tempTimeStamp = subtractedTimeStamp;
        subtractedTimeStamp = minusTimeStamp;
        minusTimeStamp = tempTimeStamp;
    }

    if(subtractedTimeStamp.nanoseconds >= minusTimeStamp.nanoseconds)
    {
        DiffTimeStampPtr->diff.nanoseconds = subtractedTimeStamp.nanoseconds - minusTimeStamp.nanoseconds;
    }
    else
    {
        DiffTimeStampPtr->diff.nanoseconds = (uint32)((subtractedTimeStamp.nanoseconds + ETHTSYN_NANOSEC_MAX + (uint32)1) - minusTimeStamp.nanoseconds);
        subtractedTimeStamp.seconds--;
        if(ETHTSYN_32BIT_UNSIGNED_MAX_VALUE == subtractedTimeStamp.seconds)
        {
            subtractedTimeStamp.secondsHi--;
        }
    }
    if(subtractedTimeStamp.seconds >= minusTimeStamp.seconds)
    {
        DiffTimeStampPtr->diff.seconds = subtractedTimeStamp.seconds - minusTimeStamp.seconds;
    }
    else
    {
        DiffTimeStampPtr->diff.seconds = (uint32)(((uint64)subtractedTimeStamp.seconds + (uint64)ETHTSYN_32BIT_UNSIGNED_MAX_VALUE + (uint64)1) - (uint64)minusTimeStamp.seconds);
        subtractedTimeStamp.secondsHi--;    
    }

    DiffTimeStampPtr->diff.secondsHi = subtractedTimeStamp.secondsHi - minusTimeStamp.secondsHi;
    DiffTimeStampPtr->sign = signFlag;
}

#endif
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: EthTSyn_GetIngressTimeStamp
*
* Description:   Service to get the ingress time stamp
*
* Inputs:        uint8* CtrlIdx : EthTSyn controller index the frame belongs to
*                uint8* RxDataPtr Pointer to the received frame
*
* Outputs:       Eth_TimeStampType* TimeStampPtr : Pointer to return the actual time stamp
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(Std_ReturnType, ETHTSYN_CODE) EthTSyn_GetIngressTimeStamp
(
    uint8 CtrlIdx,
    P2VAR(uint8, AUTOMATIC, ETHTSYN_APPL_DATA) RxDataPtr,
#if(ETHTSYN_HW_TIMESTAMP_SUPPORT == STD_ON)
    P2VAR(Eth_TimeStampType, AUTOMATIC, ETHTSYN_APPL_DATA) TimeStampPtr
#else
    P2VAR(StbM_TimeStampType, AUTOMATIC, ETHTSYN_APPL_DATA) TimeStampPtr
#endif
)
{
    Std_ReturnType ret = E_NOT_OK;
#if(ETHTSYN_HW_TIMESTAMP_SUPPORT == STD_ON)
    Eth_TimeStampQualType TimeQuality;
#else
    StbM_UserDataType UserDataPtr;
#endif 
#if(ETHTSYN_HW_TIMESTAMP_SUPPORT == STD_ON)
    Eth_GetIngressTimeStamp(CtrlIdx, RxDataPtr, &TimeQuality, TimeStampPtr);
    if(ETH_VALID == TimeQuality)
    {
        ret = E_OK;
    }
    else
    {
        ret = E_NOT_OK;
    }
    if(ETHTSYN_NANOSEC_MAX < TimeStampPtr->nanoseconds)
    {
        ret = E_NOT_OK;
    }
#else
    (void)CtrlIdx;
    UserDataPtr.userDataLength = (uint8)3;
    UserDataPtr.userByte0 = (uint8)1;
    UserDataPtr.userByte1 = (uint8)1;
    UserDataPtr.userByte2 = (uint8)1;
#if(STD_ON == ETHTSYN_PORT_SLAVE_SUPPORT)
    ret = StbM_GetCurrentTime(EthTSyn_SlaveController[0].TimeBaseId, TimeStampPtr, &UserDataPtr);
#else
    ret = StbM_GetCurrentTime(EthTSyn_MasterController[0].TimeBaseId, TimeStampPtr, &UserDataPtr);
#endif
#endif /* ETHTSYN_HW_TIMESTAMP_SUPPORT == STD_ON */
    return ret;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: EthTSyn_GetEgressTimeStamp
*
* Description:   Service to get the egress time stamp
*
* Inputs:        uint8* CtrlIdx : EthIf controller index the frame belongs to
*                Eth_BufIdxType BufIdx : Tx frame buffer index
*
* Outputs:       Eth_TimeStampType* TimeStampPtr : Pointer to return the actual time stamp
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(Std_ReturnType, ETHTSYN_CODE) EthTSyn_GetEgressTimeStamp
(
    uint8 CtrlIdx,
    Eth_BufIdxType BufIdx,
#if(ETHTSYN_HW_TIMESTAMP_SUPPORT == STD_ON)
    P2VAR(Eth_TimeStampType, AUTOMATIC, ETHTSYN_APPL_DATA) TimeStampPtr
#else
    P2VAR(StbM_TimeStampType, AUTOMATIC, ETHTSYN_APPL_DATA) TimeStampPtr
#endif
)
{
#if(ETHTSYN_HW_TIMESTAMP_SUPPORT == STD_ON)
    Eth_TimeStampQualType TimeQuality;
#else
    StbM_UserDataType UserDataPtr;
#endif
    Std_ReturnType ret = E_NOT_OK;
#if(ETHTSYN_HW_TIMESTAMP_SUPPORT == STD_ON)
    Eth_GetEgressTimeStamp(CtrlIdx, BufIdx, &TimeQuality, TimeStampPtr);
    if((ETH_VALID == TimeQuality))
    {
        ret = E_OK;
    }
    else
    {
        ret = E_NOT_OK;
    }
    if(ETHTSYN_NANOSEC_MAX < TimeStampPtr->nanoseconds)
    {
        ret = E_NOT_OK;
    }
#else
    (void)BufIdx;
    (void)CtrlIdx;
    UserDataPtr.userDataLength = (uint8)3;
    UserDataPtr.userByte0 = (uint8)1;
    UserDataPtr.userByte1 = (uint8)1;
    UserDataPtr.userByte2 = (uint8)1;
#if(STD_ON == ETHTSYN_PORT_SLAVE_SUPPORT)
    ret = StbM_GetCurrentTime(EthTSyn_SlaveController[0].TimeBaseId, TimeStampPtr, &UserDataPtr);
#else
    ret = StbM_GetCurrentTime(EthTSyn_MasterController[0].TimeBaseId, TimeStampPtr, &UserDataPtr);
#endif
#endif
    return ret;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: EthTSyn_AddEthTimeStamp
*
* Description:   Calculate the sum of the two EthTimeStamp
*
* Inputs:        TimeStampPtr1 : Pointer to the first EthTimeStamp
*                TimeStampPtr2 : Pointer to the second EthTimeStamp
*
* Outputs:       TimeStampPtr1 : Pointer to return the sun of the two time stamp
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
#if(STD_ON == ETHTSYN_PORT_SLAVE_SUPPORT)
STATIC FUNC(void, ETHTSYN_CODE)EthTSyn_AddEthTimeStamp
(
#if(ETHTSYN_HW_TIMESTAMP_SUPPORT == STD_ON)
    P2VAR(Eth_TimeStampType, AUTOMATIC, ETHTSYN_APPL_DATA) TimeStampPtr1,
    P2VAR(Eth_TimeStampType, AUTOMATIC, ETHTSYN_APPL_DATA) TimeStampPtr2
#else
    P2VAR(StbM_TimeStampType, AUTOMATIC, ETHTSYN_APPL_DATA) TimeStampPtr1,
    P2VAR(StbM_TimeStampType, AUTOMATIC, ETHTSYN_APPL_DATA) TimeStampPtr2
#endif
)
{
    uint8 i = (uint8)0;
    uint8 counter = (uint8)0;

    for(i = (uint8)0; i < (uint8)4; i++)
    {
        if(TimeStampPtr1->nanoseconds > ETHTSYN_NANOSEC_MAX)
        {
            TimeStampPtr1->nanoseconds = TimeStampPtr1->nanoseconds - (ETHTSYN_NANOSEC_MAX + (uint32)1);
            counter++;
        }
        if(TimeStampPtr2->nanoseconds > ETHTSYN_NANOSEC_MAX)
        {
            TimeStampPtr2->nanoseconds = TimeStampPtr2->nanoseconds - (ETHTSYN_NANOSEC_MAX + (uint32)1);
            counter++;
        }
    }
    TimeStampPtr1->nanoseconds += TimeStampPtr2->nanoseconds;
    if(ETHTSYN_NANOSEC_MAX < TimeStampPtr1->nanoseconds)
    {
        TimeStampPtr1->nanoseconds = TimeStampPtr1->nanoseconds - (ETHTSYN_NANOSEC_MAX + (uint32)1);
        counter++;
    }
    TimeStampPtr1->seconds += TimeStampPtr2->seconds;
    if(TimeStampPtr1->seconds < TimeStampPtr2->seconds)
    {
        TimeStampPtr1->secondsHi++;
    }
    TimeStampPtr1->seconds += counter;
    if(TimeStampPtr1->seconds < counter)
    {
    	TimeStampPtr1->secondsHi++;
    }
    TimeStampPtr1->secondsHi += TimeStampPtr2->secondsHi;
}
#endif
