/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
*   File Name       : CanTSyn.c
********************************************************************************
*   Project/Product : AUTOSAR 4.2
*   Title           : CanTSyn module Source File
*   Author          : Hirain
********************************************************************************
*   Description     : CanTSyn module Source File
*
********************************************************************************
*   Limitations     : None
*
********************************************************************************
*
********************************************************************************
*   Revision History:
*
*   Version     Date          Initials        CR#       Descriptions
*   ---------   ----------    ------------  ----------  ---------------
*   01.00.00    05/10/2019    JunCheng.Li     N/A       Beta
*   01.00.01    16/12/2020    Feixiang.Dong   N/A       EAS422_CanTSyn_20201216_01 
*   01.00.02    28/05/2021    Xin.Yang1       N/A       EAS422_CanTSyn_20210528_01 
*   01.00.03    11/04/2022    Ziyi.Zhao       N/A       EAS422_CanTSyn_20220411_01
*   01.00.04    13/05/2022    Ziyi.Zhao       N/A       EAS422_CanTSyn_20220513_01
*   01.01.00    15/08/2023    Yaping.Jin      N/A       EAS422_CanTSyn_20230815_01
********************************************************************************
* END_FILE_HDR*/

/*******************************************************************************
*   Includes
*******************************************************************************/
#include "CanTSyn.h"
#include "CanTSyn_Version.h"
#include "CanTSyn_Cbk.h"
#include "SchM_CanTSyn.h"
#include "StbM.h"
#include "Bsw_Common.h"
#if (STD_ON == CANTSYN_DEV_ERROR_DETECT)
#include "Det.h"
#endif

/*******************************************************************************
*   Version Check
*******************************************************************************/
#if(STD_ON == CANTSYN_PRIVATE_VERSION_CHECK)
/* check Version with other import module */


/* check Version with cfg file */
#if ((CANTSYN_AR_RELEASE_MAJOR_VERSION != CANTSYN_AR_RELEASE_MAJOR_VERSION_CFG) || \
   (CANTSYN_AR_RELEASE_MINOR_VERSION != CANTSYN_AR_RELEASE_MINOR_VERSION_CFG))
#error "AutoSar Version Numbers of CanTSyn and its cfg file are different"
#endif

#if ((CANTSYN_SW_MAJOR_VERSION != CANTSYN_SW_MAJOR_VERSION_CFG) || \
   (CANTSYN_SW_MINOR_VERSION != CANTSYN_SW_MINOR_VERSION_CFG))
#error "SW Version Numbers of CanTSyn and its cfg file are different"
#endif

#endif/*#if(STD_ON == CANTSYN_PRIVATE_VERSION_CHECK)*/

/*******************************************************************************
*  Macros
*******************************************************************************/
#if (STD_ON == CANTSYN_DEV_ERROR_DETECT)

#define CANTSYN_DET_REPORT_ERROR(ApiId, errcode)  \
    DET_REPORT_ERROR(CANTSYN_MODULE_ID, CANTSYN_INSTANCE_ID, (ApiId), (errcode))
#else
#define CANTSYN_DET_REPORT_ERROR(ApiId, errcode)
#endif

/*******************************************************************************
*   Local Data Define
*******************************************************************************/
#define CANTSYN_START_SEC_VAR_INIT_8
#include "MemMap.h"
STATIC VAR(Std_InitStateType, CANTSYN_VAR) CanTSyn_InitStatus = STD_UNINITIALIZED;
#define CANTSYN_STOP_SEC_VAR_INIT_8
#include "MemMap.h"

#define CANTSYN_START_SEC_VAR_NOINIT_8
#include "MemMap.h"
#if(0 < (CANTSYN_SYNC_SLAVE_NUM + CANTSYN_OFS_SLAVE_NUM))
STATIC VAR(uint8,CANTSYN_VAR) CanTSyn_RxData[CANTSYN_MSG_LENGTH];
#endif
#if (0 < (CANTSYN_SYNC_MASTER_NUM + CANTSYN_OFS_MASTER_NUM))
STATIC VAR(uint8,CANTSYN_VAR) CanTSyn_TxData[CANTSYN_MSG_LENGTH];
#endif
#define CANTSYN_STOP_SEC_VAR_NOINIT_8
#include "MemMap.h"

#define CANTSYN_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
STATIC P2CONST(CanTSyn_ConfigType, CANTSYN_VAR, CANTSYN_CONST) CanTSyn_ConfigPtr = NULL_PTR;
#define CANTSYN_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"

#define CANTSYN_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"
#if (0 < CANTSYN_SYNC_SLAVE_NUM)
STATIC VAR(CanTSyn_SYNCSlaveParameterType, CANTSYN_VAR) CanTSyn_SYNCSlaveParm[CANTSYN_SYNC_SLAVE_NUM];
#endif
#if (0 < CANTSYN_OFS_SLAVE_NUM)
STATIC VAR(CanTSyn_OFSSlaveParameterType, CANTSYN_VAR) CanTSyn_OFSSlaveParm[CANTSYN_OFS_SLAVE_NUM];
#endif

#if (0 < CANTSYN_SYNC_MASTER_NUM)
STATIC VAR(CanTSyn_SYNCMasterParameterType, CANTSYN_VAR) CanTSyn_SYNCMasterParm[CANTSYN_SYNC_MASTER_NUM];
#endif

#if (0 < CANTSYN_OFS_MASTER_NUM)
STATIC VAR(CanTSyn_OFSMasterParameterType, CANTSYN_VAR) CanTSyn_OFSMasterParm[CANTSYN_OFS_MASTER_NUM];
#endif

#if(0 < CANTSYN_TXPDU_NUM)
STATIC VAR(CanTSyn_PduStsType, CANTSYN_VAR) CanTSyn_PduStsParm[CANTSYN_TXPDU_NUM];
#endif

#define CANTSYN_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"
/*******************************************************************************
*   Local Functions declare
*******************************************************************************/
#define CANTSYN_START_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
*   Local Functions define
*******************************************************************************/
#if(0 < CANTSYN_SYNC_SLAVE_NUM)
STATIC FUNC(void, CANTSYN_CODE) CanTSyn_SYNCRxProcessing
(
    uint8 Index
);
#endif
#if(0 < CANTSYN_OFS_SLAVE_NUM)
STATIC FUNC(void, CANTSYN_CODE) CanTSyn_OFSRxProcessing
(
    uint8 Index
);
#endif
#if(0 < CANTSYN_SYNC_SLAVE_NUM)
STATIC FUNC(void, CANTSYN_CODE) CanTSyn_RxSYNCMsg
(
    uint8 Index
);

STATIC FUNC(void, CANTSYN_CODE) CanTSyn_RxFUPMsg
(
    uint8 Index
);
#endif
#if(0 < CANTSYN_OFS_SLAVE_NUM)
STATIC FUNC(void, CANTSYN_CODE) CanTSyn_RxOFSMsg
(
    uint8 Index
);

STATIC FUNC(void, CANTSYN_CODE) CanTSyn_RxOFNSMsg
(
    uint8 Index
);
#endif
#if(0 < CANTSYN_SYNC_SLAVE_NUM || 0 < CANTSYN_OFS_SLAVE_NUM)
STATIC FUNC(void, CANTSYN_CODE) CanTSyn_uint8Packuint32
(
    P2VAR(uint8, AUTOMATIC, CANTSYN_APPL_DATA) SduDataPtr,
    P2VAR(uint32, AUTOMATIC, CANTSYN_APPL_DATA) dataPtr
);
STATIC FUNC(Std_ReturnType, CANTSYN_CODE)CanTSyn_CheckRxPduId
(
    PduIdType RxPduId
);
#endif

#if (0 < CANTSYN_SYNC_MASTER_NUM)
STATIC FUNC(void, CANTSYN_CODE) CanTSyn_SYNCTxProcessing
(
    uint8 DomainIndex
);    
#endif

#if (0 < CANTSYN_OFS_MASTER_NUM)
STATIC FUNC(void, CANTSYN_CODE) CanTSyn_OFSTxProcessing
(
    uint8 DomainIndex
);
#endif
#if (0 < CANTSYN_SYNC_MASTER_NUM || 0 < CANTSYN_OFS_MASTER_NUM)
STATIC FUNC(void, CANTSYN_CODE)CanTSyn_Uint32UnpackUint8
(
    P2VAR(uint32, AUTOMATIC, CANTSYN_APPL_DATA) dataPtr,
    P2VAR(uint8, AUTOMATIC, CANTSYN_APPL_DATA) SduDataPtr    
);

STATIC FUNC(Std_ReturnType, CANTSYN_CODE)CanTSyn_CheckTxPduId
(
    PduIdType TxPduId
);
#endif
#if (0 < CANTSYN_SYNC_MASTER_NUM)
STATIC FUNC(Std_ReturnType, CANTSYN_CODE)CanTSyn_TxSyncMsg
(
    uint8 Index
);

STATIC FUNC(Std_ReturnType, CANTSYN_CODE)CanTSyn_TxFupMsg
(
    uint8 Index
);
#endif
#if (0 < CANTSYN_OFS_MASTER_NUM)
STATIC FUNC(Std_ReturnType, CANTSYN_CODE)CanTSyn_TxOfsMsg
(
    uint8 Index
);

STATIC FUNC(Std_ReturnType, CANTSYN_CODE)CanTSyn_TxOfnsMsg
(
    uint8 Index
);
#endif
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name : CanTSyn_Init
*
* Description   : This function initializes the Time Synchronization over CAN.
*
* Inputs        : -configPtr:Pointer to selected configuration structure.
*
* Outputs       : None
*
* return        : None
*
* Limitations   : None
********************************************************************************
END_FUNCTION_HDR */
FUNC(void, CANTSYN_CODE) CanTSyn_Init
( 
    P2CONST(CanTSyn_ConfigType, AUTOMATIC, CANTSYN_CONST) configPtr 
)
{
    uint8 PduIdx;
    uint8 DomainIndex = (uint8)0;

#if(CANTSYN_CONFIG_VARIANTS == STD_CONFIG_VARIANTS_POSTBUILD)
    if(NULL_PTR == configPtr)
    {
        CANTSYN_DET_REPORT_ERROR(CANTSYN_INIT_API_ID, CANTSYN_E_NULL_POINTER); /*SWS_CanTSyn_00089*/
    }
    else
#else
    (void)configPtr;
#endif
    {    
#if(CANTSYN_CONFIG_VARIANTS == STD_CONFIG_VARIANTS_POSTBUILD)
        CanTSyn_ConfigPtr = configPtr;
#else
        CanTSyn_ConfigPtr = &CanTSyn_Config;
#endif

#if (0 < CANTSYN_SYNC_SLAVE_NUM)
        for(DomainIndex = (uint8)0; DomainIndex < CANTSYN_SYNC_SLAVE_NUM; DomainIndex++)
        {
            CanTSyn_SYNCSlaveParm[DomainIndex].Status = CANTSYN_IDLE;
            CanTSyn_SYNCSlaveParm[DomainIndex].CurrentSC = (uint8)0;/*SWS_CanTSyn_00007*/
            CanTSyn_SYNCSlaveParm[DomainIndex].SYNC_LastSC = (uint8)0;
            CanTSyn_SYNCSlaveParm[DomainIndex].RxSYNCIsFirst = TRUE;
            CanTSyn_SYNCSlaveParm[DomainIndex].RxFollowUpTimeOut = (uint32)0;
            CanTSyn_SYNCSlaveParm[DomainIndex].SyncTimeSec = (uint32)0;
            CanTSyn_SYNCSlaveParm[DomainIndex].SyncTimeNSec = (uint32)0;
            CanTSyn_SYNCSlaveParm[DomainIndex].TimeStampRaw = (StbM_TimeStampRawType)0;
            CanTSyn_SYNCSlaveParm[DomainIndex].UserData.userDataLength = (uint8)0;
            CanTSyn_SYNCSlaveParm[DomainIndex].UserData.userByte0 = (uint8)0;
            CanTSyn_SYNCSlaveParm[DomainIndex].UserData.userByte1 = (uint8)0;
            CanTSyn_SYNCSlaveParm[DomainIndex].UserData.userByte2 = (uint8)0;
        }
#endif
#if (0 < CANTSYN_OFS_SLAVE_NUM)
        for(DomainIndex = (uint8)0; DomainIndex < CANTSYN_OFS_SLAVE_NUM; DomainIndex++)
        {
            CanTSyn_OFSSlaveParm[DomainIndex].Status = CANTSYN_IDLE;
            CanTSyn_OFSSlaveParm[DomainIndex].CurrentSC = (uint8)0;/*SWS_CanTSyn_00007*/
            CanTSyn_OFSSlaveParm[DomainIndex].OFS_LastSC = (uint8)0;
            CanTSyn_OFSSlaveParm[DomainIndex].RxOFSIsFirst = TRUE;
            CanTSyn_OFSSlaveParm[DomainIndex].RxFollowUpTimeOut = (uint32)0;
            CanTSyn_OFSSlaveParm[DomainIndex].OfsTimeSecHi = (uint16)0;
            CanTSyn_OFSSlaveParm[DomainIndex].OfsTimeSec = (uint32)0;
            CanTSyn_OFSSlaveParm[DomainIndex].OfsTimeNSec = (uint32)0;
            CanTSyn_OFSSlaveParm[DomainIndex].TimeStampRaw = (StbM_TimeStampRawType)0;
            CanTSyn_OFSSlaveParm[DomainIndex].UserData.userDataLength = (uint8)0;
            CanTSyn_OFSSlaveParm[DomainIndex].UserData.userByte0 = (uint8)0;
            CanTSyn_OFSSlaveParm[DomainIndex].UserData.userByte1 = (uint8)0;
            CanTSyn_OFSSlaveParm[DomainIndex].UserData.userByte2 = (uint8)0;            
        }
#endif
#if (0 < CANTSYN_SYNC_MASTER_NUM)
        for(DomainIndex = (uint8)0; DomainIndex < CANTSYN_SYNC_MASTER_NUM; DomainIndex++)
        {
            CanTSyn_SYNCMasterParm[DomainIndex].Status = CANTSYN_IDLE;
            CanTSyn_SYNCMasterParm[DomainIndex].TxMode = CANTSYN_TX_ON;
            CanTSyn_SYNCMasterParm[DomainIndex].TransmittingFlag = FALSE;
            CanTSyn_SYNCMasterParm[DomainIndex].TxTimeOut = (uint16)0;
            CanTSyn_SYNCMasterParm[DomainIndex].DebounceTime = CanTSyn_ConfigPtr->SYNCMaster_Cfg[DomainIndex].DebounceTime;
            CanTSyn_SYNCMasterParm[DomainIndex].SyncTxPeriod = CanTSyn_ConfigPtr->SYNCMaster_Cfg[DomainIndex].TxOffset;
            CanTSyn_SYNCMasterParm[DomainIndex].SyncTxOffsetTime = CanTSyn_ConfigPtr->SYNCMaster_Cfg[DomainIndex].TxOffset;
            CanTSyn_SYNCMasterParm[DomainIndex].TxSyncSC = (uint8)0;/*SWS_CanTSyn_00007*/
            CanTSyn_SYNCMasterParm[DomainIndex].TxSyncTimeStamp.timeBaseStatus.GLOBAL_TIME_BASE = FALSE;
            CanTSyn_SYNCMasterParm[DomainIndex].TxSyncTimeStamp.timeBaseStatus.Reserved = (uint8)0;
			CanTSyn_SYNCMasterParm[DomainIndex].TxSyncTimeStamp.timeBaseStatus.SYNC_TO_GATEWAY = FALSE;
			CanTSyn_SYNCMasterParm[DomainIndex].TxSyncTimeStamp.timeBaseStatus.TIMELEAP = FALSE;
			CanTSyn_SYNCMasterParm[DomainIndex].TxSyncTimeStamp.timeBaseStatus.TIMEOUT = FALSE;
            CanTSyn_SYNCMasterParm[DomainIndex].TxSyncTimeStamp.secondsHi = (uint32)0;
            CanTSyn_SYNCMasterParm[DomainIndex].TxSyncTimeStamp.seconds = (uint32)0;
            CanTSyn_SYNCMasterParm[DomainIndex].TxSyncTimeStamp.nanoseconds = (uint32)0;
            CanTSyn_SYNCMasterParm[DomainIndex].TxSyncTimeStampRaw = (uint32)0;
            CanTSyn_SYNCMasterParm[DomainIndex].TxSyncTimeStampDiff = (uint32)0;
            CanTSyn_SYNCMasterParm[DomainIndex].UserData.userDataLength = (uint8)0;
            CanTSyn_SYNCMasterParm[DomainIndex].UserData.userByte0 = (uint8)0;
            CanTSyn_SYNCMasterParm[DomainIndex].UserData.userByte1 = (uint8)0;
            CanTSyn_SYNCMasterParm[DomainIndex].UserData.userByte2 = (uint8)0;
        }
#endif
#if (0 < CANTSYN_OFS_MASTER_NUM)
        for(DomainIndex = (uint8)0; DomainIndex < CANTSYN_OFS_MASTER_NUM; DomainIndex++)
        {
            CanTSyn_OFSMasterParm[DomainIndex].Status = CANTSYN_IDLE;
            CanTSyn_OFSMasterParm[DomainIndex].TxMode = CANTSYN_TX_ON;
            CanTSyn_OFSMasterParm[DomainIndex].TransmittingFlag = FALSE;
            CanTSyn_OFSMasterParm[DomainIndex].TxTimeOut = (uint16)0;
            CanTSyn_OFSMasterParm[DomainIndex].DebounceTime = CanTSyn_ConfigPtr->OFSMaster_Cfg[DomainIndex].DebounceTime;
            CanTSyn_OFSMasterParm[DomainIndex].OfsTxPeriod = CanTSyn_ConfigPtr->OFSMaster_Cfg[DomainIndex].TxOffset;
            CanTSyn_OFSMasterParm[DomainIndex].OfsTxOffsetTime = CanTSyn_ConfigPtr->OFSMaster_Cfg[DomainIndex].TxOffset;
            CanTSyn_OFSMasterParm[DomainIndex].TxOfsSC = (uint8)0;/*SWS_CanTSyn_00007*/
            CanTSyn_OFSMasterParm[DomainIndex].TxOfsTimeStamp.timeBaseStatus.GLOBAL_TIME_BASE = FALSE;
            CanTSyn_OFSMasterParm[DomainIndex].TxOfsTimeStamp.timeBaseStatus.Reserved = (uint8)0;
			CanTSyn_OFSMasterParm[DomainIndex].TxOfsTimeStamp.timeBaseStatus.SYNC_TO_GATEWAY = FALSE;
			CanTSyn_OFSMasterParm[DomainIndex].TxOfsTimeStamp.timeBaseStatus.TIMELEAP = FALSE;
			CanTSyn_OFSMasterParm[DomainIndex].TxOfsTimeStamp.timeBaseStatus.TIMEOUT = FALSE;
            CanTSyn_OFSMasterParm[DomainIndex].TxOfsTimeStamp.secondsHi = (uint32)0;
            CanTSyn_OFSMasterParm[DomainIndex].TxOfsTimeStamp.seconds = (uint32)0;
            CanTSyn_OFSMasterParm[DomainIndex].TxOfsTimeStamp.nanoseconds = (uint32)0;        
        }    
#endif
#if(0 < CANTSYN_TXPDU_NUM)
        for(PduIdx = (uint8)0; PduIdx < CANTSYN_TXPDU_NUM; PduIdx++)
        {
            CanTSyn_PduStsParm[PduIdx].TrsSYNCIdx = CANTSYN_IDX_INVALID;
            CanTSyn_PduStsParm[PduIdx].TrsOFSIdx = CANTSYN_IDX_INVALID;
        }     
#endif
        CanTSyn_InitStatus = STD_INITIALIZED; /*SWS_CanTSyn_00003*/
    }
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name : CanTSyn_GetVersionInfo
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
#if(STD_ON == CANTSYN_VERSION_INFO)
FUNC(void, CANTSYN_CODE) CanTSyn_GetVersionInfo
(
    P2VAR(Std_VersionInfoType,  AUTOMATIC, CANTSYN_APPL_DATA) versioninfo
)
{
    if(versioninfo == NULL_PTR)
    {
        CANTSYN_DET_REPORT_ERROR(CANTSYN_GET_VERSION_INFO_API_ID, CANTSYN_E_NULL_POINTER); /*SWS_CanTSyn_00089*/
    }
    else
    {
        versioninfo->vendorID = CANTSYN_VENDOR_ID;
        versioninfo->moduleID = CANTSYN_MODULE_ID;
        versioninfo->sw_major_version = (uint8)CANTSYN_SW_MAJOR_VERSION;
        versioninfo->sw_minor_version = (uint8)CANTSYN_SW_MINOR_VERSION;
        versioninfo->sw_patch_version = (uint8)CANTSYN_SW_PATCH_VERSION;
    }
}
#endif
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name : CanTSyn_SetTransmissionMode
*
* Description   : This API is used to turn on and off the TX capabilities of the CanTSyn.
*
* Inputs        : -CtrlIdx: Index of the CAN channel
*                 -Mode: CANTSYN_TX_OFF,CANTSYN_TX_ON
*
* Outputs       : None
*
* return        : None
*
* Limitations   : None
********************************************************************************
END_FUNCTION_HDR */
#if (0 < CANTSYN_SYNC_MASTER_NUM || 0 < CANTSYN_OFS_MASTER_NUM)
FUNC(void, CANTSYN_CODE) CanTSyn_SetTransmissionMode
(
    uint8 CtrlIdx,
    CanTSyn_TransmissionModeType Mode
)
{
    uint8 DomainIndex;
    if(STD_UNINITIALIZED == CanTSyn_InitStatus)
    {
        CANTSYN_DET_REPORT_ERROR(CANTSYN_SET_TRANSMISSION_MODE_API_ID, CANTSYN_E_NOT_INITIALIZED);/*SWS_CanTSyn_00005*/
    }
    else
    {
        /*SWS_CanTSyn_00043*//*SWS_CanTSyn_00044*/
#if(0 < CANTSYN_SYNC_MASTER_NUM)
        for(DomainIndex = (uint8)0; DomainIndex < CANTSYN_SYNC_MASTER_NUM; DomainIndex++)
        {
            if(CtrlIdx == CanTSyn_ConfigPtr->SYNCMaster_Cfg[DomainIndex].ControllerId)
            {
                CanTSyn_SYNCMasterParm[DomainIndex].TxMode = Mode;
            }
        }
#endif
#if(0 < CANTSYN_OFS_MASTER_NUM)
        for(DomainIndex = (uint8)0; DomainIndex < CANTSYN_OFS_MASTER_NUM; DomainIndex++)
        {
            if(CtrlIdx == CanTSyn_ConfigPtr->OFSMaster_Cfg[DomainIndex].ControllerId)
            {
                CanTSyn_OFSMasterParm[DomainIndex].TxMode = Mode;
            }
        }  
#endif      
    }
}
#endif


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name : CanTSyn_RxIndication
*
* Description   : Indication of a received I-PDU from a lower layer communication interface module.
*
* Inputs        : -RxPduId: ID of the received I-PDU.
*                 -PduInfoPtr: Contains the length (SduLength) of the received I-PDU and a pointer 
*                              to a buffer (SduDataPtr) containing the I-PDU.
*
* Outputs       : None
*
* return        : None
*
* Limitations   : None
********************************************************************************
END_FUNCTION_HDR */
#if(0 < CANTSYN_SYNC_SLAVE_NUM || 0 < CANTSYN_OFS_SLAVE_NUM)
FUNC(void, CANTSYN_CODE) CanTSyn_RxIndication
(
    PduIdType RxPduId,
    P2CONST(PduInfoType, AUTOMATIC, CANTSYN_APPL_DATA) PduInfoPtr
)
{    
    uint8 DomainIndex;
    uint8 DomainId;
    if(STD_UNINITIALIZED == CanTSyn_InitStatus)
    {
        CANTSYN_DET_REPORT_ERROR(CANTSYN_RX_INDICATION_API_ID, CANTSYN_E_NOT_INITIALIZED); /*SWS_CanTSyn_00097*/
    }
    else if(E_OK != CanTSyn_CheckRxPduId(RxPduId))
    {
        CANTSYN_DET_REPORT_ERROR(CANTSYN_RX_INDICATION_API_ID, CANTSYN_E_INVALID_PDUID); /*SWS_CanTSyn_00097*/
    }
    else if((NULL_PTR == PduInfoPtr) || (NULL_PTR == PduInfoPtr->SduDataPtr))
    {
        CANTSYN_DET_REPORT_ERROR(CANTSYN_RX_INDICATION_API_ID, CANTSYN_E_NULL_POINTER); /*SWS_CanTSyn_00097*/
    }
    else if(PduInfoPtr->SduLength != CANTSYN_MSG_LENGTH)
    {
        CANTSYN_DET_REPORT_ERROR(CANTSYN_RX_INDICATION_API_ID, CANTSYN_E_INVALID_LENGTH);
    }
    else
    {
        SchM_Enter_CanTSyn_CANTSYN_EXCLUSIVE_AREA_0();
        Bsw_MemCpy(CanTSyn_RxData,PduInfoPtr->SduDataPtr,CANTSYN_MSG_LENGTH);
        SchM_Exit_CanTSyn_CANTSYN_EXCLUSIVE_AREA_0();
#if (0 < CANTSYN_SYNC_SLAVE_NUM)
        if((CanTSyn_RxData[CANTSYN_BYTE_0] == CANTSYN_SYNC_NOT_CRC) ||
            (CanTSyn_RxData[CANTSYN_BYTE_0] == CANTSYN_SYNC_CRC) ||
            (CanTSyn_RxData[CANTSYN_BYTE_0] == CANTSYN_FUP_NOT_CRC) ||
            (CanTSyn_RxData[CANTSYN_BYTE_0] == CANTSYN_FUP_CRC))
        {
            DomainId = (uint8)(((CanTSyn_RxData[CANTSYN_BYTE_2]) & CANTSYN_TD_MASK) >> CANTSYN_TD_SHIFT_BITS);
            for(DomainIndex = (uint8)0; DomainIndex < CANTSYN_SYNC_SLAVE_NUM; DomainIndex++)
            {
                if(DomainId == CanTSyn_ConfigPtr->SYNCSlave_Cfg[DomainIndex].DomainId)
                {
                    CanTSyn_SYNCRxProcessing(DomainIndex);
                    break;
                }
            }
        }
#endif

#if (0 < CANTSYN_OFS_SLAVE_NUM)
        if((CanTSyn_RxData[CANTSYN_BYTE_0] == CANTSYN_OFS_NOT_CRC) ||
            (CanTSyn_RxData[CANTSYN_BYTE_0] == CANTSYN_OFS_CRC) ||
            (CanTSyn_RxData[CANTSYN_BYTE_0] == CANTSYN_OFNS_NOT_CRC) ||
            (CanTSyn_RxData[CANTSYN_BYTE_0] == CANTSYN_OFNS_CRC))
        {
            DomainId = CANTSYN_SC_OFFSET + (uint8)(((CanTSyn_RxData[CANTSYN_BYTE_2]) & CANTSYN_TD_MASK) >> CANTSYN_TD_SHIFT_BITS);
            for(DomainIndex = (uint8)0; DomainIndex < CANTSYN_OFS_SLAVE_NUM; DomainIndex++)
            {
                if(DomainId == CanTSyn_ConfigPtr->OFSSlave_Cfg[DomainIndex].DomainId)
                {
                    CanTSyn_OFSRxProcessing(DomainIndex);
                    break;
                }
            }
        }
#endif
    }
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name : CanTSyn_CheckRxPduId
*
* Description   : check RxPduId is valid or not.
*

*
* Outputs       : None
*
* return        : None
*
* Limitations   : None
********************************************************************************
END_FUNCTION_HDR */
STATIC FUNC(Std_ReturnType, CANTSYN_CODE)CanTSyn_CheckRxPduId
(
    PduIdType RxPduId
)
{
    Std_ReturnType ret = E_NOT_OK;

    if(RxPduId < (CANTSYN_SYNC_SLAVE_NUM + CANTSYN_OFS_SLAVE_NUM))
    {
        ret = E_OK;
    }
    return ret;
}
#endif
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name : CanTSyn_TxConfirmation
*
* Description   : The lower layer communication interface module confirms the
*                 transmission of an I-PDU.
*
* Inputs        : -TxPduId: ID of the I-PDU that has been transmitted.
*
* Outputs       : None
*
* return        : None
*
* Limitations   : None
********************************************************************************
END_FUNCTION_HDR */
#if (0 < CANTSYN_SYNC_MASTER_NUM || 0 < CANTSYN_OFS_MASTER_NUM)
FUNC(void, CANTSYN_CODE) CanTSyn_TxConfirmation
(
    PduIdType TxPduId
)
{ 
#if(0 < CANTSYN_SYNC_MASTER_NUM)
    uint8 SyncDomainIndex = (uint8)0;
#endif
#if(0 < CANTSYN_OFS_MASTER_NUM)
    uint8 OfsDomainIndex = (uint8)0;
#endif
    if(STD_UNINITIALIZED == CanTSyn_InitStatus)
    {
        CANTSYN_DET_REPORT_ERROR(CANTSYN_TX_CONFIRMATION_API_ID, CANTSYN_E_NOT_INITIALIZED);/*SWS_CanTSyn_00100*/
    }
    else if (E_OK != CanTSyn_CheckTxPduId(TxPduId))
    {
        CANTSYN_DET_REPORT_ERROR(CANTSYN_TX_CONFIRMATION_API_ID, CANTSYN_E_INVALID_PDUID);/*SWS_CanTSyn_00100*/
    }   
    else
    {
#if(0 < CANTSYN_SYNC_MASTER_NUM)
        SyncDomainIndex = CanTSyn_PduStsParm[TxPduId].TrsSYNCIdx;
        if(SyncDomainIndex != CANTSYN_IDX_INVALID)
        {
            CanTSyn_SYNCMasterParm[SyncDomainIndex].TransmittingFlag = FALSE;
            switch(CanTSyn_SYNCMasterParm[SyncDomainIndex].Status)
            {
                case CANTSYN_SYNC:
                    CanTSyn_SYNCMasterParm[SyncDomainIndex].Status = CANTSYN_SYNC_DONE;
                    CanTSyn_SYNCMasterParm[SyncDomainIndex].SyncTxPeriod = CanTSyn_ConfigPtr->SYNCMaster_Cfg[SyncDomainIndex].TxPeriod;
                    (void)StbM_GetCurrentTimeDiff(CanTSyn_SYNCMasterParm[SyncDomainIndex].TxSyncTimeStampRaw, &CanTSyn_SYNCMasterParm[SyncDomainIndex].TxSyncTimeStampDiff);                 
                    break;
                case CANTSYN_FUP:
                    CanTSyn_SYNCMasterParm[SyncDomainIndex].Status = CANTSYN_FUP_DONE;
                    CanTSyn_SYNCMasterParm[SyncDomainIndex].TxSyncSC++;
                    if(CanTSyn_SYNCMasterParm[SyncDomainIndex].TxSyncSC == CANTSYN_SC_INVALID)
                    {
                        CanTSyn_SYNCMasterParm[SyncDomainIndex].TxSyncSC = (uint8)0;
                    }
                    break;
                default:
                    break;
            }
        }
#endif
#if(0 < CANTSYN_OFS_MASTER_NUM)
        OfsDomainIndex = CanTSyn_PduStsParm[TxPduId].TrsOFSIdx;
        if(OfsDomainIndex != CANTSYN_IDX_INVALID)
        {
            CanTSyn_OFSMasterParm[OfsDomainIndex].TransmittingFlag = FALSE;
            switch(CanTSyn_OFSMasterParm[OfsDomainIndex].Status)
            {
                case CANTSYN_OFS:
                    CanTSyn_OFSMasterParm[OfsDomainIndex].Status = CANTSYN_OFS_DONE;
                    CanTSyn_OFSMasterParm[OfsDomainIndex].OfsTxPeriod = CanTSyn_ConfigPtr->OFSMaster_Cfg[OfsDomainIndex].TxPeriod;
                    break;
                case CANTSYN_OFNS:
                    CanTSyn_OFSMasterParm[OfsDomainIndex].Status = CANTSYN_OFNS_DONE;
                    CanTSyn_OFSMasterParm[OfsDomainIndex].TxOfsSC++;
                    if(CanTSyn_OFSMasterParm[OfsDomainIndex].TxOfsSC == CANTSYN_SC_INVALID)
                    {
                        CanTSyn_OFSMasterParm[OfsDomainIndex].TxOfsSC = (uint8)0;
                    }
                    break;
                default:
                    break;                  
            }
        }           
#endif
    }
}
#endif
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name : CanTSyn_MainFunction
*
* Description   : Main function for cyclic call / resp. SYNC and FUP transmission
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
extern FUNC(void, CANTSYN_CODE) CanTSyn_MainFunction
(
    void
)
{
	uint8 DomainIndex;

    if(STD_UNINITIALIZED == CanTSyn_InitStatus)
    {
        CANTSYN_DET_REPORT_ERROR(CANTSYN_MAIN_FUNCTION_API_ID, CANTSYN_E_NOT_INITIALIZED); /*SWS_CanTSyn_00104*/
    }
    else
    {
    
#if (0 < CANTSYN_SYNC_SLAVE_NUM)
        for(DomainIndex = (uint8)0; DomainIndex < CANTSYN_SYNC_SLAVE_NUM; DomainIndex++)
        {
            if(CANTSYN_SYNC_DONE == CanTSyn_SYNCSlaveParm[DomainIndex].Status)
            {
                if(CanTSyn_SYNCSlaveParm[DomainIndex].RxFollowUpTimeOut != (uint32)0)
                {
                    CanTSyn_SYNCSlaveParm[DomainIndex].RxFollowUpTimeOut--;
                }
                else
                {
                    SchM_Enter_CanTSyn_CANTSYN_EXCLUSIVE_AREA_1();
                    CanTSyn_SYNCSlaveParm[DomainIndex].Status = CANTSYN_IDLE;
                    SchM_Exit_CanTSyn_CANTSYN_EXCLUSIVE_AREA_1();                    
                }
            }
        }
#endif
#if (0 < CANTSYN_OFS_SLAVE_NUM)
        for(DomainIndex = (uint8)0; DomainIndex < CANTSYN_OFS_SLAVE_NUM; DomainIndex++)
        {
            if(CANTSYN_OFS_DONE == CanTSyn_OFSSlaveParm[DomainIndex].Status)
            {
                if(CanTSyn_OFSSlaveParm[DomainIndex].RxFollowUpTimeOut != (uint32)0)
                {
                    CanTSyn_OFSSlaveParm[DomainIndex].RxFollowUpTimeOut--;
                }
                else
                {
                    SchM_Enter_CanTSyn_CANTSYN_EXCLUSIVE_AREA_1();
                    CanTSyn_OFSSlaveParm[DomainIndex].Status = CANTSYN_IDLE;
                    SchM_Exit_CanTSyn_CANTSYN_EXCLUSIVE_AREA_1();
                }
            }
        }
#endif
#if (0 < CANTSYN_SYNC_MASTER_NUM)
        for(DomainIndex = (uint8)0; DomainIndex < CANTSYN_SYNC_MASTER_NUM; DomainIndex++)
        {
            if(CanTSyn_SYNCMasterParm[DomainIndex].TxMode == CANTSYN_TX_ON)
            {
                CanTSyn_SYNCTxProcessing(DomainIndex);  
            } 
        }   
#endif
#if (0 < CANTSYN_OFS_MASTER_NUM)
        for(DomainIndex = (uint8)0; DomainIndex < CANTSYN_OFS_MASTER_NUM; DomainIndex++)
        {
            if(CanTSyn_OFSMasterParm[DomainIndex].TxMode == CANTSYN_TX_ON)
            {
                CanTSyn_OFSTxProcessing(DomainIndex);
            } 
        }           
#endif
    }
}

#if (0 < CANTSYN_SYNC_MASTER_NUM)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name : CanTSyn_TxProcessing
*
* Description   : Process the transmitted data.
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
STATIC FUNC(void, CANTSYN_CODE)  CanTSyn_SYNCTxProcessing
(
    uint8 DomainIndex
)
{
    if(CanTSyn_SYNCMasterParm[DomainIndex].SyncTxPeriod > (uint16)0)
    {
        CanTSyn_SYNCMasterParm[DomainIndex].SyncTxPeriod--;
    }
    if((CanTSyn_SYNCMasterParm[DomainIndex].Status == CANTSYN_IDLE) && (CanTSyn_SYNCMasterParm[DomainIndex].SyncTxPeriod == (uint16)0))
    {
        CanTSyn_SYNCMasterParm[DomainIndex].Status = CANTSYN_SYNC;
    }

    if(CanTSyn_SYNCMasterParm[DomainIndex].Status == CANTSYN_SYNC)
    {
        if(CanTSyn_SYNCMasterParm[DomainIndex].TransmittingFlag == FALSE)
        {
           
            if(E_OK == CanTSyn_TxSyncMsg(DomainIndex))
            {
                CanTSyn_PduStsParm[CanTSyn_ConfigPtr->SYNCMaster_Cfg[DomainIndex].PduRef].TrsSYNCIdx = DomainIndex;
                CanTSyn_PduStsParm[CanTSyn_ConfigPtr->SYNCMaster_Cfg[DomainIndex].PduRef].TrsOFSIdx = CANTSYN_IDX_INVALID; 
                CanTSyn_SYNCMasterParm[DomainIndex].TransmittingFlag = TRUE;
                CanTSyn_SYNCMasterParm[DomainIndex].TxTimeOut = CanTSyn_ConfigPtr->SYNCMaster_Cfg[DomainIndex].TxTimeOut;
            }   
        }

        if(CanTSyn_SYNCMasterParm[DomainIndex].TransmittingFlag == TRUE)
        {
            if(CanTSyn_SYNCMasterParm[DomainIndex].TxTimeOut > (uint16)0)
            {
                CanTSyn_SYNCMasterParm[DomainIndex].TxTimeOut--;
            }
            else
            {
                CanTSyn_PduStsParm[CanTSyn_ConfigPtr->SYNCMaster_Cfg[DomainIndex].PduRef].TrsSYNCIdx = CANTSYN_IDX_INVALID;
                CanTSyn_PduStsParm[CanTSyn_ConfigPtr->SYNCMaster_Cfg[DomainIndex].PduRef].TrsOFSIdx = CANTSYN_IDX_INVALID;
                /*SWS_CanTSyn_000027*/
                SchM_Enter_CanTSyn_CANTSYN_EXCLUSIVE_AREA_1();
                CanTSyn_SYNCMasterParm[DomainIndex].TransmittingFlag = FALSE;
                SchM_Exit_CanTSyn_CANTSYN_EXCLUSIVE_AREA_1();
            }  
        }         
    }

    if(CanTSyn_SYNCMasterParm[DomainIndex].Status == CANTSYN_SYNC_DONE)
    {
        if(CanTSyn_SYNCMasterParm[DomainIndex].DebounceTime > (uint16)0)
        {
            CanTSyn_SYNCMasterParm[DomainIndex].DebounceTime--;
        }
        else
        {
            CanTSyn_SYNCMasterParm[DomainIndex].Status = CANTSYN_FUP;
            CanTSyn_SYNCMasterParm[DomainIndex].DebounceTime = CanTSyn_ConfigPtr->SYNCMaster_Cfg[DomainIndex].DebounceTime;
        }              
    }

    if(CanTSyn_SYNCMasterParm[DomainIndex].Status == CANTSYN_FUP)
    {
        if(CanTSyn_SYNCMasterParm[DomainIndex].TransmittingFlag == FALSE)
        {
            if(E_OK == CanTSyn_TxFupMsg(DomainIndex))
            {
                CanTSyn_SYNCMasterParm[DomainIndex].TransmittingFlag = TRUE;
                CanTSyn_SYNCMasterParm[DomainIndex].TxTimeOut = CanTSyn_ConfigPtr->SYNCMaster_Cfg[DomainIndex].TxTimeOut;
                CanTSyn_PduStsParm[CanTSyn_ConfigPtr->SYNCMaster_Cfg[DomainIndex].PduRef].TrsSYNCIdx = DomainIndex;
                CanTSyn_PduStsParm[CanTSyn_ConfigPtr->SYNCMaster_Cfg[DomainIndex].PduRef].TrsOFSIdx = CANTSYN_IDX_INVALID;
            }
        }

        if(CanTSyn_SYNCMasterParm[DomainIndex].TransmittingFlag == TRUE)
        {
            if(CanTSyn_SYNCMasterParm[DomainIndex].TxTimeOut > (uint16)0)
            {
                CanTSyn_SYNCMasterParm[DomainIndex].TxTimeOut--;
            }
            else
            {
                /*SWS_CanTSyn_000027*/
                CanTSyn_PduStsParm[CanTSyn_ConfigPtr->SYNCMaster_Cfg[DomainIndex].PduRef].TrsSYNCIdx = CANTSYN_IDX_INVALID;
                CanTSyn_PduStsParm[CanTSyn_ConfigPtr->SYNCMaster_Cfg[DomainIndex].PduRef].TrsOFSIdx = CANTSYN_IDX_INVALID;
                SchM_Enter_CanTSyn_CANTSYN_EXCLUSIVE_AREA_1();
                CanTSyn_SYNCMasterParm[DomainIndex].Status = CANTSYN_SYNC;
                CanTSyn_SYNCMasterParm[DomainIndex].TransmittingFlag = FALSE;
                SchM_Exit_CanTSyn_CANTSYN_EXCLUSIVE_AREA_1();
            }
        }        
    }

    if(CanTSyn_SYNCMasterParm[DomainIndex].Status == CANTSYN_FUP_DONE)
    {
        if(CanTSyn_SYNCMasterParm[DomainIndex].SyncTxOffsetTime > (uint16)0)
        {
            CanTSyn_SYNCMasterParm[DomainIndex].SyncTxOffsetTime--;
            if(CanTSyn_SYNCMasterParm[DomainIndex].SyncTxOffsetTime == (uint16)0)
            {
                CanTSyn_SYNCMasterParm[DomainIndex].Status = CANTSYN_IDLE;
                CanTSyn_SYNCMasterParm[DomainIndex].SyncTxOffsetTime = CanTSyn_ConfigPtr->SYNCMaster_Cfg[DomainIndex].TxOffset;  
            }
        }
    }        
}
#endif
#if (0 < CANTSYN_OFS_MASTER_NUM)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name : CanTSyn_OFSTxProcessing
*
* Description   : Process the transmitted OFS Messages.
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
STATIC FUNC(void, CANTSYN_CODE) CanTSyn_OFSTxProcessing
(
    uint8 DomainIndex
)
{
    if(CanTSyn_OFSMasterParm[DomainIndex].OfsTxPeriod > (uint16)0)
    {
        CanTSyn_OFSMasterParm[DomainIndex].OfsTxPeriod--;
    }
    if((CanTSyn_OFSMasterParm[DomainIndex].Status == CANTSYN_IDLE) && (CanTSyn_OFSMasterParm[DomainIndex].OfsTxPeriod == (uint16)0))
    {
        CanTSyn_OFSMasterParm[DomainIndex].Status = CANTSYN_OFS;
    }
    if(CanTSyn_OFSMasterParm[DomainIndex].Status == CANTSYN_OFS)
    {
        if(CanTSyn_OFSMasterParm[DomainIndex].TransmittingFlag == FALSE)
        {
            if(E_OK == CanTSyn_TxOfsMsg(DomainIndex))
            {
                CanTSyn_OFSMasterParm[DomainIndex].TransmittingFlag = TRUE;
                CanTSyn_OFSMasterParm[DomainIndex].TxTimeOut = CanTSyn_ConfigPtr->OFSMaster_Cfg[DomainIndex].TxTimeOut;
                CanTSyn_PduStsParm[CanTSyn_ConfigPtr->OFSMaster_Cfg[DomainIndex].PduRef].TrsSYNCIdx = CANTSYN_IDX_INVALID;
                CanTSyn_PduStsParm[CanTSyn_ConfigPtr->OFSMaster_Cfg[DomainIndex].PduRef].TrsOFSIdx = DomainIndex; 
            }
        }

        if(CanTSyn_OFSMasterParm[DomainIndex].TransmittingFlag == TRUE)
        {
            if(CanTSyn_OFSMasterParm[DomainIndex].TxTimeOut > (uint16)0)
            {
                CanTSyn_OFSMasterParm[DomainIndex].TxTimeOut--;
            }
            else
            {
                CanTSyn_PduStsParm[CanTSyn_ConfigPtr->OFSMaster_Cfg[DomainIndex].PduRef].TrsSYNCIdx = CANTSYN_IDX_INVALID;
                CanTSyn_PduStsParm[CanTSyn_ConfigPtr->OFSMaster_Cfg[DomainIndex].PduRef].TrsOFSIdx = CANTSYN_IDX_INVALID;
                /*SWS_CanTSyn_00037*/
                SchM_Enter_CanTSyn_CANTSYN_EXCLUSIVE_AREA_1();
                CanTSyn_OFSMasterParm[DomainIndex].TransmittingFlag = FALSE;
                SchM_Exit_CanTSyn_CANTSYN_EXCLUSIVE_AREA_1();
            }
        }
    }

    if(CanTSyn_OFSMasterParm[DomainIndex].Status == CANTSYN_OFS_DONE)
    {
        if(CanTSyn_OFSMasterParm[DomainIndex].DebounceTime > (uint16)0)
        {
            CanTSyn_OFSMasterParm[DomainIndex].DebounceTime--;
        }
        else
        {
            CanTSyn_OFSMasterParm[DomainIndex].Status = CANTSYN_OFNS;
            CanTSyn_OFSMasterParm[DomainIndex].DebounceTime = CanTSyn_ConfigPtr->OFSMaster_Cfg[DomainIndex].DebounceTime;                
        }                           
    }

    if(CanTSyn_OFSMasterParm[DomainIndex].Status == CANTSYN_OFNS)
    {
        if(CanTSyn_OFSMasterParm[DomainIndex].TransmittingFlag == FALSE)
        {
            if(E_OK == CanTSyn_TxOfnsMsg(DomainIndex))
            {
                CanTSyn_OFSMasterParm[DomainIndex].TransmittingFlag = TRUE;
                CanTSyn_OFSMasterParm[DomainIndex].TxTimeOut = CanTSyn_ConfigPtr->OFSMaster_Cfg[DomainIndex].TxTimeOut;
                CanTSyn_PduStsParm[CanTSyn_ConfigPtr->OFSMaster_Cfg[DomainIndex].PduRef].TrsSYNCIdx = CANTSYN_IDX_INVALID;
                CanTSyn_PduStsParm[CanTSyn_ConfigPtr->OFSMaster_Cfg[DomainIndex].PduRef].TrsOFSIdx = DomainIndex; 
            }
        }
        if(CanTSyn_OFSMasterParm[DomainIndex].TransmittingFlag == TRUE)
        {
            if(CanTSyn_OFSMasterParm[DomainIndex].TxTimeOut > (uint16)0)
            {
                CanTSyn_OFSMasterParm[DomainIndex].TxTimeOut--;
            }
            else
            {
                CanTSyn_PduStsParm[CanTSyn_ConfigPtr->OFSMaster_Cfg[DomainIndex].PduRef].TrsSYNCIdx = CANTSYN_IDX_INVALID;
                CanTSyn_PduStsParm[CanTSyn_ConfigPtr->OFSMaster_Cfg[DomainIndex].PduRef].TrsOFSIdx = CANTSYN_IDX_INVALID;
                /*SWS_CanTSyn_00037*/
                SchM_Enter_CanTSyn_CANTSYN_EXCLUSIVE_AREA_1();
                CanTSyn_OFSMasterParm[DomainIndex].Status = CANTSYN_OFS;
                CanTSyn_OFSMasterParm[DomainIndex].TransmittingFlag = FALSE;
                SchM_Exit_CanTSyn_CANTSYN_EXCLUSIVE_AREA_1();
            }
        }
    }

    if(CanTSyn_OFSMasterParm[DomainIndex].Status == CANTSYN_OFNS_DONE)
    {
        if(CanTSyn_OFSMasterParm[DomainIndex].OfsTxOffsetTime > (uint16)0)
        {
            CanTSyn_OFSMasterParm[DomainIndex].OfsTxOffsetTime--;
            if(CanTSyn_OFSMasterParm[DomainIndex].OfsTxOffsetTime == (uint16)0)
            {
                CanTSyn_OFSMasterParm[DomainIndex].Status = CANTSYN_IDLE;
                CanTSyn_OFSMasterParm[DomainIndex].OfsTxOffsetTime = CanTSyn_ConfigPtr->OFSMaster_Cfg[DomainIndex].TxOffset;                 
            }
        }
    }
}
#endif
#if (0 < CANTSYN_SYNC_MASTER_NUM)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name : CanTSyn_TxSyncMsg
*
* Description   : Transmit Sync Message.
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
STATIC FUNC(Std_ReturnType, CANTSYN_CODE)CanTSyn_TxSyncMsg
(
    uint8 Index
)
{
    PduInfoType TxPduInfo;
    Std_ReturnType ret;
    uint8 DomainId;
#if (CANTSYN_CRC_ENABLED == STD_ON)
    uint8 Crc_Data[CANTSYN_CRCSIZE];
#endif

    /*SWS_CanTSyn_00031*/
    if(CRC_SUPPORTED == CanTSyn_ConfigPtr->SYNCMaster_Cfg[Index].CrcMode)
    {
        CanTSyn_TxData[CANTSYN_BYTE_0] = CANTSYN_SYNC_CRC;
    }
    else
    {
        CanTSyn_TxData[CANTSYN_BYTE_0] = CANTSYN_SYNC_NOT_CRC;
    }

    if(E_OK == StbM_GetCurrentTime(CanTSyn_ConfigPtr->SYNCMaster_Cfg[Index].timeBaseId, &(CanTSyn_SYNCMasterParm[Index].TxSyncTimeStamp), &(CanTSyn_SYNCMasterParm[Index].UserData)))
    {
        (void)StbM_GetCurrentTimeRaw(&(CanTSyn_SYNCMasterParm[Index].TxSyncTimeStampRaw));
        if(CRC_SUPPORTED == CanTSyn_ConfigPtr->SYNCMaster_Cfg[Index].CrcMode)
        {
            CanTSyn_TxData[CANTSYN_BYTE_3] = CanTSyn_SYNCMasterParm[Index].UserData.userByte0;
        }
        else
        {
            CanTSyn_TxData[CANTSYN_BYTE_3] = CanTSyn_SYNCMasterParm[Index].UserData.userByte0;
            CanTSyn_TxData[CANTSYN_BYTE_1] = CanTSyn_SYNCMasterParm[Index].UserData.userByte1;
        }
        CanTSyn_Uint32UnpackUint8(&(CanTSyn_SYNCMasterParm[Index].TxSyncTimeStamp.seconds), &CanTSyn_TxData[CANTSYN_BYTE_4]);        
    }
    DomainId = CanTSyn_ConfigPtr->SYNCMaster_Cfg[Index].DomainId;
    CanTSyn_TxData[CANTSYN_BYTE_2] = ((DomainId << CANTSYN_TD_SHIFT_BITS) & CANTSYN_TD_MASK) | (CanTSyn_SYNCMasterParm[Index].TxSyncSC & CANTSYN_SC_MASK);
#if (CANTSYN_CRC_ENABLED == STD_ON)
    if(CRC_SUPPORTED == CanTSyn_ConfigPtr->SYNCMaster_Cfg[Index].CrcMode)
    {
        /*SWS_CanTSyn_00050*//*SWS_CanTSyn_00051*//*SWS_CanTSyn_00054*//*SWS_CanTSyn_00055*/
        SchM_Enter_CanTSyn_CANTSYN_EXCLUSIVE_AREA_0();
        Bsw_MemCpy(Crc_Data, &CanTSyn_TxData[CANTSYN_CRC_OFFSET], CANTSYN_CRCSIZE - 1);
        Crc_Data[CANTSYN_BYTE_6] = CanTSyn_SYNCDataList[CanTSyn_SYNCMasterParm[Index].TxSyncSC];
        SchM_Exit_CanTSyn_CANTSYN_EXCLUSIVE_AREA_0();
        CanTSyn_TxData[CANTSYN_BYTE_1] = CANTSYN_CALCULATE_CRC(&Crc_Data[CANTSYN_BYTE_0], CANTSYN_CRCSIZE, CANTSYN_CRC_START_VALUE, TRUE);
    }
#endif
    TxPduInfo.SduDataPtr = CanTSyn_TxData;
    TxPduInfo.SduLength = CANTSYN_MSG_LENGTH;

    ret = CanIf_Transmit(CanTSyn_ConfigPtr->SYNCMaster_Cfg[Index].PduId, &TxPduInfo); 

    return ret;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name : CanTSyn_TxFupMsg
*
* Description   : Transmit Fup Message.
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
STATIC FUNC(Std_ReturnType, CANTSYN_CODE)CanTSyn_TxFupMsg
(
    uint8 Index
)
{
    PduInfoType TxPduInfo;
    uint8 sgw;
    uint32 ovs;
    uint32 time;
    uint32 syncTimeNSec;
    Std_ReturnType ret;
    uint8 DomainId;
#if (CANTSYN_CRC_ENABLED == STD_ON)
    uint8 Crc_Data[CANTSYN_CRCSIZE];
#endif

    /*SWS_CanTSyn_00031*/
    if(CRC_SUPPORTED == CanTSyn_ConfigPtr->SYNCMaster_Cfg[Index].CrcMode)
    {
        CanTSyn_TxData[CANTSYN_BYTE_0] = CANTSYN_FUP_CRC;
    }
    else
    {
        CanTSyn_TxData[CANTSYN_BYTE_0] = CANTSYN_FUP_NOT_CRC;
    }
    DomainId = CanTSyn_ConfigPtr->SYNCMaster_Cfg[Index].DomainId;
    CanTSyn_TxData[CANTSYN_BYTE_2] = ((DomainId << CANTSYN_TD_SHIFT_BITS) & CANTSYN_TD_MASK) | (CanTSyn_SYNCMasterParm[Index].TxSyncSC & CANTSYN_SC_MASK);
    CanTSyn_TxData[CANTSYN_BYTE_3] = (uint8)0;
    if(CanTSyn_SYNCMasterParm[Index].TxSyncTimeStamp.timeBaseStatus.SYNC_TO_GATEWAY == FALSE)
    {
        sgw = (uint8)0;
    }
    else
    {
        sgw = (uint8)1;
    }
    time = CanTSyn_SYNCMasterParm[Index].TxSyncTimeStamp.nanoseconds + CanTSyn_SYNCMasterParm[Index].TxSyncTimeStampDiff;
    ovs = time / CANTSYN_NS_MAXVALUE;
    syncTimeNSec = time % CANTSYN_NS_MAXVALUE;

    CanTSyn_TxData[CANTSYN_BYTE_3] = ((sgw << CANTSYN_SGW_SHIFT_BITS) & CANTSYN_SGW_MASK) | (uint8)(ovs & CANTSYN_OVS_MASK);
    CanTSyn_Uint32UnpackUint8(&syncTimeNSec, &CanTSyn_TxData[CANTSYN_BYTE_4]); 
#if (CANTSYN_CRC_ENABLED == STD_ON)
    if(CRC_SUPPORTED == CanTSyn_ConfigPtr->SYNCMaster_Cfg[Index].CrcMode)
    {
        SchM_Enter_CanTSyn_CANTSYN_EXCLUSIVE_AREA_0();
        Bsw_MemCpy(Crc_Data, &CanTSyn_TxData[CANTSYN_CRC_OFFSET], CANTSYN_CRCSIZE - 1);
        Crc_Data[CANTSYN_BYTE_6] = CanTSyn_FUPDataList[CanTSyn_SYNCMasterParm[Index].TxSyncSC];
        SchM_Exit_CanTSyn_CANTSYN_EXCLUSIVE_AREA_0();
        CanTSyn_TxData[CANTSYN_BYTE_1] = CANTSYN_CALCULATE_CRC(&Crc_Data[CANTSYN_BYTE_0], CANTSYN_CRCSIZE, CANTSYN_CRC_START_VALUE, TRUE);  
    }  
    else
    {
        CanTSyn_TxData[CANTSYN_BYTE_1] = CanTSyn_SYNCMasterParm[Index].UserData.userByte2;
    }
#else
    CanTSyn_TxData[CANTSYN_BYTE_1] = CanTSyn_SYNCMasterParm[Index].UserData.userByte2;
#endif

    TxPduInfo.SduDataPtr = CanTSyn_TxData;
    TxPduInfo.SduLength = CANTSYN_MSG_LENGTH;

    ret = CanIf_Transmit(CanTSyn_ConfigPtr->SYNCMaster_Cfg[Index].PduId, &TxPduInfo);

    return ret;    
}
#endif
#if (0 < CANTSYN_OFS_MASTER_NUM)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name : CanTSyn_TxOfsMsg
*
* Description   : Transmit Ofs Message.
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
STATIC FUNC(Std_ReturnType, CANTSYN_CODE)CanTSyn_TxOfsMsg
(
    uint8 Index
)
{
    PduInfoType TxPduInfo; 
    StbM_TimeStampType timeStamp;
    Std_ReturnType ret;
    uint8 DomainId;
#if (CANTSYN_CRC_ENABLED == STD_ON)
    uint8 Crc_Data[CANTSYN_CRCSIZE];
#endif

    /*SWS_CanTSyn_00041*/
    if(CRC_SUPPORTED == CanTSyn_ConfigPtr->OFSMaster_Cfg[Index].CrcMode)
    {
        CanTSyn_TxData[CANTSYN_BYTE_0] = CANTSYN_OFS_CRC;
    }
    else
    {
        CanTSyn_TxData[CANTSYN_BYTE_0] = CANTSYN_OFS_NOT_CRC;
    }
    DomainId = CanTSyn_ConfigPtr->OFSMaster_Cfg[Index].DomainId;
    CanTSyn_TxData[CANTSYN_BYTE_2] = (((DomainId - CANTSYN_SC_OFFSET) << CANTSYN_TD_SHIFT_BITS) & CANTSYN_TD_MASK) | (CanTSyn_OFSMasterParm[Index].TxOfsSC & CANTSYN_SC_MASK);
    if(E_OK == StbM_GetOffset(CanTSyn_ConfigPtr->OFSMaster_Cfg[Index].timeBaseId, &timeStamp))
    {
        CanTSyn_OFSMasterParm[Index].TxOfsTimeStamp.secondsHi = timeStamp.secondsHi;
        CanTSyn_OFSMasterParm[Index].TxOfsTimeStamp.seconds = timeStamp.seconds;
        CanTSyn_OFSMasterParm[Index].TxOfsTimeStamp.nanoseconds = timeStamp.nanoseconds;
    }
    CanTSyn_TxData[CANTSYN_BYTE_3] = (uint8)(CanTSyn_OFSMasterParm[Index].TxOfsTimeStamp.secondsHi & CANTSYN_UINT8_MASK);
    CanTSyn_Uint32UnpackUint8(&(CanTSyn_OFSMasterParm[Index].TxOfsTimeStamp.seconds), &CanTSyn_TxData[CANTSYN_BYTE_4]);
#if (CANTSYN_CRC_ENABLED == STD_ON)
    if(CRC_SUPPORTED == CanTSyn_ConfigPtr->OFSMaster_Cfg[Index].CrcMode)
    {
        SchM_Enter_CanTSyn_CANTSYN_EXCLUSIVE_AREA_0();
        Bsw_MemCpy(Crc_Data, &CanTSyn_TxData[CANTSYN_CRC_OFFSET], CANTSYN_CRCSIZE - 1);
        Crc_Data[CANTSYN_BYTE_6] = CanTSyn_OFSDataList[CanTSyn_OFSMasterParm[Index].TxOfsSC];
        SchM_Exit_CanTSyn_CANTSYN_EXCLUSIVE_AREA_0();
        CanTSyn_TxData[CANTSYN_BYTE_1] = CANTSYN_CALCULATE_CRC(&Crc_Data[CANTSYN_BYTE_0], CANTSYN_CRCSIZE, CANTSYN_CRC_START_VALUE, TRUE);
    }
    else
    {
        CanTSyn_TxData[CANTSYN_BYTE_1] = (uint8)0;
    } 
#else
    CanTSyn_TxData[CANTSYN_BYTE_1] = (uint8)0;
#endif     

    TxPduInfo.SduDataPtr = CanTSyn_TxData;
    TxPduInfo.SduLength = CANTSYN_MSG_LENGTH;

    ret = CanIf_Transmit(CanTSyn_ConfigPtr->OFSMaster_Cfg[Index].PduId, &TxPduInfo); 

    return ret;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name : CanTSyn_TxOfnsMsg
*
* Description   : Transmit Ofns Message.
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
STATIC FUNC(Std_ReturnType, CANTSYN_CODE)CanTSyn_TxOfnsMsg
(
    uint8 Index
)
{
    PduInfoType TxPduInfo;
    Std_ReturnType ret; 
    uint8 DomainId;
#if (CANTSYN_CRC_ENABLED == STD_ON)
    uint8 Crc_Data[CANTSYN_CRCSIZE];
#endif

    /*SWS_CanTSyn_00041*/    
    if(CRC_SUPPORTED == CanTSyn_ConfigPtr->OFSMaster_Cfg[Index].CrcMode)
    {
        CanTSyn_TxData[CANTSYN_BYTE_0] = CANTSYN_OFNS_CRC;
    }
    else
    {
        CanTSyn_TxData[CANTSYN_BYTE_0] = CANTSYN_OFNS_NOT_CRC;
    }
    DomainId = CanTSyn_ConfigPtr->OFSMaster_Cfg[Index].DomainId;
    CanTSyn_TxData[CANTSYN_BYTE_2] = (((DomainId - CANTSYN_SC_OFFSET) << CANTSYN_TD_SHIFT_BITS) & CANTSYN_TD_MASK) | (CanTSyn_OFSMasterParm[Index].TxOfsSC & CANTSYN_SC_MASK);
    CanTSyn_TxData[CANTSYN_BYTE_3] = (uint8)((CanTSyn_OFSMasterParm[Index].TxOfsTimeStamp.secondsHi >> CANTSYN_SECONDSHIGH_SHIFT_BITS) & CANTSYN_UINT8_MASK);
    CanTSyn_Uint32UnpackUint8(&(CanTSyn_OFSMasterParm[Index].TxOfsTimeStamp.nanoseconds), &CanTSyn_TxData[CANTSYN_BYTE_4]);
#if (CANTSYN_CRC_ENABLED == STD_ON)
    if(CRC_SUPPORTED == CanTSyn_ConfigPtr->OFSMaster_Cfg[Index].CrcMode)
    {
        SchM_Enter_CanTSyn_CANTSYN_EXCLUSIVE_AREA_0();
        Bsw_MemCpy(Crc_Data, &CanTSyn_TxData[CANTSYN_CRC_OFFSET], CANTSYN_CRCSIZE - 1);
        Crc_Data[CANTSYN_BYTE_6] = CanTSyn_OFNSDataList[CanTSyn_OFSMasterParm[Index].TxOfsSC];
        SchM_Exit_CanTSyn_CANTSYN_EXCLUSIVE_AREA_0();
        CanTSyn_TxData[CANTSYN_BYTE_1] = CANTSYN_CALCULATE_CRC(&Crc_Data[CANTSYN_BYTE_0], CANTSYN_CRCSIZE, CANTSYN_CRC_START_VALUE, TRUE);   
    }   
    else
    {
        CanTSyn_TxData[CANTSYN_BYTE_1] = (uint8)0;
    }
#else
    CanTSyn_TxData[CANTSYN_BYTE_1] = (uint8)0;
#endif
    TxPduInfo.SduDataPtr = CanTSyn_TxData;
    TxPduInfo.SduLength = CANTSYN_MSG_LENGTH;

    ret = CanIf_Transmit(CanTSyn_ConfigPtr->OFSMaster_Cfg[Index].PduId, &TxPduInfo); 

    return ret;
}
#endif
#if (0 < CANTSYN_SYNC_MASTER_NUM || 0 < CANTSYN_OFS_MASTER_NUM)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name : CanTSyn_Uint32UnpackUint8
*
* Description   : unpack uint32 into uint8.
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
STATIC FUNC(void, CANTSYN_CODE)CanTSyn_Uint32UnpackUint8
(
    P2VAR(uint32, AUTOMATIC, CANTSYN_APPL_DATA) dataPtr,
    P2VAR(uint8, AUTOMATIC, CANTSYN_APPL_DATA) SduDataPtr    
)
{
    SduDataPtr[CANTSYN_BYTE_0] = (uint8)(*dataPtr >> CANTSYN_DATA_SHIFT_THREE_BYTES);
    SduDataPtr[CANTSYN_BYTE_1] = (uint8)(*dataPtr >> CANTSYN_DATA_SHIFT_TWO_BYTES);
    SduDataPtr[CANTSYN_BYTE_2] = (uint8)(*dataPtr >> CANTSYN_DATA_SHIFT_ONE_BYTE);
    SduDataPtr[CANTSYN_BYTE_3] = (uint8)(*dataPtr);
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name : CanTSyn_CheckTxPduId
*
* Description   : check TxPduId is valid or not.
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
STATIC FUNC(Std_ReturnType, CANTSYN_CODE)CanTSyn_CheckTxPduId
(
    PduIdType TxPduId
)
{
    Std_ReturnType ret = E_NOT_OK;

    if(TxPduId < (CANTSYN_SYNC_MASTER_NUM + CANTSYN_OFS_MASTER_NUM))
    {
        ret = E_OK;
    }
    return ret;
}
#endif

#if(0 < CANTSYN_SYNC_SLAVE_NUM)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name : CanTSyn_RxProcessing
*
* Description   : Process the received data.
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
STATIC FUNC(void, CANTSYN_CODE) CanTSyn_SYNCRxProcessing
(
    uint8 Index
)
{
    uint8 MsgType;
    CanTSyn_StatusType Status = CANTSYN_IDLE;
    MsgType = CanTSyn_RxData[CANTSYN_BYTE_0];

    if(CanTSyn_ConfigPtr->SYNCSlave_Cfg[Index].CrcMode == CRC_VALIDATED)
    {
        if(CANTSYN_SYNC_CRC == MsgType)
        {
            Status = CANTSYN_SYNC;
        }
        else if(CANTSYN_FUP_CRC == MsgType)
        {
            Status = CANTSYN_FUP;
        }
        else
        {
            /*do nothing*/
        }
    }
    else if(CanTSyn_ConfigPtr->SYNCSlave_Cfg[Index].CrcMode == CRC_NOT_VALIDATED)
    {
        if(CANTSYN_SYNC_NOT_CRC == MsgType)
        {
            Status = CANTSYN_SYNC;
        }
        else if(CANTSYN_FUP_NOT_CRC == MsgType)
        {
            Status = CANTSYN_FUP;
        }
        else
        {
            /*do nothing*/       
        }
    }
    else
    {
        if((CANTSYN_SYNC_CRC == MsgType) || (CANTSYN_SYNC_NOT_CRC == MsgType))
        {
            Status = CANTSYN_SYNC;
        }
        else if((CANTSYN_FUP_CRC == MsgType) || (CANTSYN_FUP_NOT_CRC == MsgType))
        {
            Status = CANTSYN_FUP;
        }
        else
        {
            /*do nothing*/ 
        }
    }
    switch(CanTSyn_SYNCSlaveParm[Index].Status)
    {
        case CANTSYN_IDLE:
            if(CANTSYN_SYNC ==  Status)
            {
                CanTSyn_SYNCSlaveParm[Index].Status = CANTSYN_SYNC;
                CanTSyn_RxSYNCMsg(Index);
            }
            break;
        case CANTSYN_SYNC_DONE:
            if(CANTSYN_FUP ==  Status)
            {
                CanTSyn_SYNCSlaveParm[Index].Status = CANTSYN_FUP;
                CanTSyn_RxFUPMsg(Index);
            }
            break;
        default:
            break;
    }
}
#endif
#if(0 < CANTSYN_OFS_SLAVE_NUM)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name : CanTSyn_OFSRxProcessing
*
* Description   : Process the received OFS Messages.
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
STATIC FUNC(void, CANTSYN_CODE) CanTSyn_OFSRxProcessing
(
    uint8 Index
)
{
    uint8 MsgType;
    CanTSyn_StatusType Status = CANTSYN_IDLE;
    MsgType = CanTSyn_RxData[CANTSYN_BYTE_0];

    if(CanTSyn_ConfigPtr->OFSSlave_Cfg[Index].CrcMode == CRC_VALIDATED)
    {
        if(CANTSYN_OFS_CRC == MsgType)
        {
            Status = CANTSYN_OFS;
        }
        else if(CANTSYN_OFNS_CRC == MsgType)
        {
            Status = CANTSYN_OFNS;
        }
        else
        {
            /*do nothing*/
        }
    }
    else if(CanTSyn_ConfigPtr->OFSSlave_Cfg[Index].CrcMode == CRC_NOT_VALIDATED)
    {
        if(CANTSYN_OFS_NOT_CRC == MsgType)
        {
            Status = CANTSYN_OFS;
        }
        else if(CANTSYN_OFNS_NOT_CRC == MsgType)
        {
            Status = CANTSYN_OFNS;
        }
        else
        {
            /*do nothing*/       
        }
    }
    else
    {
        if((CANTSYN_OFS_CRC == MsgType) || (CANTSYN_OFS_NOT_CRC == MsgType))
        {
            Status = CANTSYN_OFS;
        }
        else if((CANTSYN_OFNS_CRC == MsgType) || (CANTSYN_OFNS_NOT_CRC == MsgType))
        {
            Status = CANTSYN_OFNS;
        }
        else
        {
            /*do nothing*/       
        }        
    }
    
    switch(CanTSyn_OFSSlaveParm[Index].Status)
    {
        case CANTSYN_IDLE:
            if(CANTSYN_OFS ==  Status)
            {
                CanTSyn_OFSSlaveParm[Index].Status = CANTSYN_OFS;
                CanTSyn_RxOFSMsg(Index);
            }
            break;
        case CANTSYN_OFS_DONE:
            if(CANTSYN_OFNS ==  Status)
            {
                CanTSyn_OFSSlaveParm[Index].Status = CANTSYN_OFNS;
                CanTSyn_RxOFNSMsg(Index);
            }
            break;
        default:
            break;
    }
}
#endif
#if(0 < CANTSYN_SYNC_SLAVE_NUM)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name : CanTSyn_RxSYNCMsg
*
* Description   : Accept the SYNC message
*
* Inputs        : -PduInfoPtr: Contains the length (SduLength) of the received I-PDU 
*                        and a pointer to a buffer (SduDataPtr) containing the I-PDU.
*
* Outputs       : None
*
* return        : None
*
* Limitations   : None
********************************************************************************
END_FUNCTION_HDR */
STATIC FUNC(void, CANTSYN_CODE) CanTSyn_RxSYNCMsg
(
    uint8 Index
)
{    
#if (CANTSYN_CRC_ENABLED == STD_ON)
    uint8 Crc_Data[CANTSYN_CRCSIZE];
    uint8 crcResult;
#endif
    Std_ReturnType result = E_NOT_OK;
    uint8 offset;
    boolean ReTransmittingFlag = FALSE;   
    CanTSyn_SYNCSlaveParm[Index].CurrentSC = (CanTSyn_RxData[CANTSYN_BYTE_2]) & CANTSYN_SC_MASK;   
    if((CanTSyn_ConfigPtr->SYNCSlave_Cfg[Index].DomainId) == (((CanTSyn_RxData[CANTSYN_BYTE_2]) & CANTSYN_TD_MASK) >> CANTSYN_TD_SHIFT_BITS))
    {
        if(CANTSYN_SYNC_NOT_CRC == CanTSyn_RxData[CANTSYN_BYTE_0])
        {
            /*SWS_CanTSyn_00015*/
            CanTSyn_SYNCSlaveParm[Index].UserData.userDataLength = CANTSYN_NOT_CRC_DATA_LENGTH;
            CanTSyn_SYNCSlaveParm[Index].UserData.userByte0 = CanTSyn_RxData[CANTSYN_BYTE_3];
            CanTSyn_SYNCSlaveParm[Index].UserData.userByte1 = CanTSyn_RxData[CANTSYN_BYTE_1];
            result = E_OK;
        }         
        else
        {
            /*SWS_CanTSyn_00017*/
            CanTSyn_SYNCSlaveParm[Index].UserData.userDataLength= CANTSYN_CRC_DATA_LENGTH;
            CanTSyn_SYNCSlaveParm[Index].UserData.userByte0 = CanTSyn_RxData[CANTSYN_BYTE_3];
            if(CanTSyn_ConfigPtr->SYNCSlave_Cfg[Index].CrcMode == CRC_IGNORED)
            {
                result = E_OK;
            }
            else
            {
#if (CANTSYN_CRC_ENABLED == STD_ON)
                /*SWS_CanTSyn_00080,SWS_CanTSyn_00081,SWS_CanTSyn_00084,SWS_CanTSyn_00085*/
                SchM_Enter_CanTSyn_CANTSYN_EXCLUSIVE_AREA_0();
                Bsw_MemCpy(Crc_Data, &CanTSyn_RxData[CANTSYN_CRC_OFFSET], CANTSYN_CRCSIZE - 1);
                Crc_Data[CANTSYN_BYTE_6] = CanTSyn_SYNCDataList[CanTSyn_SYNCSlaveParm[Index].CurrentSC];
                SchM_Exit_CanTSyn_CANTSYN_EXCLUSIVE_AREA_0();  
                crcResult = CANTSYN_CALCULATE_CRC(&Crc_Data[CANTSYN_BYTE_0], CANTSYN_CRCSIZE, CANTSYN_CRC_START_VALUE, TRUE);
                if(crcResult == CanTSyn_RxData[CANTSYN_BYTE_1])
                {
                    result = E_OK;
                }    
#endif       
            }
        }
    }
    
    if(E_OK == result)
    {
        /*SWS_CanTSyn_00015,SWS_CanTSyn_00017*/
        CanTSyn_uint8Packuint32(&CanTSyn_RxData[CANTSYN_BYTE_4], &(CanTSyn_SYNCSlaveParm[Index].SyncTimeSec));

        if(E_OK == StbM_GetCurrentTimeRaw(&(CanTSyn_SYNCSlaveParm[Index].TimeStampRaw))) /*SWS_CanTSyn_00073*/
        {
            if(TRUE == CanTSyn_SYNCSlaveParm[Index].RxSYNCIsFirst)
            {
                CanTSyn_SYNCSlaveParm[Index].RxSYNCIsFirst = FALSE; /*SWS_CanTSyn_00079*/
                CanTSyn_SYNCSlaveParm[Index].Status = CANTSYN_SYNC_DONE;
                CanTSyn_SYNCSlaveParm[Index].RxFollowUpTimeOut = CanTSyn_ConfigPtr->SYNCSlave_Cfg[Index].RxFollowUpTimeOut;/*SWS_CanTSyn_00063*/
            }
            else
            {
                /*SWS_CanTSyn_00078*/
                if(CanTSyn_SYNCSlaveParm[Index].CurrentSC > CanTSyn_SYNCSlaveParm[Index].SYNC_LastSC)
                {
                    offset = (uint8)0;
                }
                else
                {
                    offset = CANTSYN_SC_OFFSET;
                }
                CanTSyn_SYNCSlaveParm[Index].CurrentSC += offset;

                if((CanTSyn_SYNCSlaveParm[Index].CurrentSC - CanTSyn_SYNCSlaveParm[Index].SYNC_LastSC) > (CanTSyn_ConfigPtr->SYNCSlave_Cfg[Index].JumpWidth))
                {
                    ReTransmittingFlag = CanTSyn_BeyondJumpWidth(CanTSyn_ConfigPtr->SYNCSlave_Cfg[Index].DomainId); /*Offer to user*/
                }

                if(ReTransmittingFlag == FALSE)
                {
                    CanTSyn_SYNCSlaveParm[Index].Status = CANTSYN_SYNC_DONE;
                    CanTSyn_SYNCSlaveParm[Index].RxFollowUpTimeOut = CanTSyn_ConfigPtr->SYNCSlave_Cfg[Index].RxFollowUpTimeOut;/*SWS_CanTSyn_00063*/
                }
                else
                {
                    CanTSyn_SYNCSlaveParm[Index].Status = CANTSYN_IDLE;
                }                
                CanTSyn_SYNCSlaveParm[Index].CurrentSC -= offset;
            } 
            CanTSyn_SYNCSlaveParm[Index].SYNC_LastSC = CanTSyn_SYNCSlaveParm[Index].CurrentSC;
        }
        else
        {
            CanTSyn_SYNCSlaveParm[Index].Status = CANTSYN_IDLE;
        }
    }
    else
    {
        CanTSyn_SYNCSlaveParm[Index].Status = CANTSYN_IDLE;
    }

}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name : CanTSyn_RxFUPMsg
*
* Description   : Accept the FUP message
*
* Inputs        : -PduInfoPtr: Contains the length (SduLength) of the received I-PDU 
*                        and a pointer to a buffer (SduDataPtr) containing the I-PDU.
*
* Outputs       : None
*
* return        : None
*
* Limitations   : None
********************************************************************************
END_FUNCTION_HDR */
STATIC FUNC(void, CANTSYN_CODE) CanTSyn_RxFUPMsg
(
    uint8 Index
)
{
    Std_ReturnType result = E_NOT_OK;
    StbM_TimeStampRawType timeStampDiff; 
    uint32 ovs;
    uint8 sgw;
    StbM_TimeStampType timeStamp;
#if (CANTSYN_CRC_ENABLED == STD_ON)
    uint8 Crc_Data[CANTSYN_CRCSIZE];
    uint8 crcResult;
#endif

    /*SWS_CanTSyn_00076*/
    if((CanTSyn_ConfigPtr->SYNCSlave_Cfg[Index].DomainId) == (((CanTSyn_RxData[CANTSYN_BYTE_2]) & CANTSYN_TD_MASK) >> CANTSYN_TD_SHIFT_BITS))
    {
        if(CanTSyn_SYNCSlaveParm[Index].CurrentSC == ((CanTSyn_RxData[CANTSYN_BYTE_2]) & CANTSYN_SC_MASK))
        {
            if(CANTSYN_FUP_NOT_CRC == CanTSyn_RxData[CANTSYN_BYTE_0])
            {
                /*SWS_CanTSyn_00016*/
                CanTSyn_SYNCSlaveParm[Index].UserData.userByte2 = CanTSyn_RxData[CANTSYN_BYTE_1];
                result = E_OK;
            }
            else
            {
                if(CanTSyn_ConfigPtr->SYNCSlave_Cfg[Index].CrcMode == CRC_IGNORED)
                {
                    result = E_OK;
                }
                else
                {
#if (CANTSYN_CRC_ENABLED == STD_ON)
                    /*SWS_CanTSyn_00080,SWS_CanTSyn_00081,SWS_CanTSyn_00084,SWS_CanTSyn_00085*/
                    SchM_Enter_CanTSyn_CANTSYN_EXCLUSIVE_AREA_0();
                    Bsw_MemCpy(Crc_Data, &CanTSyn_RxData[CANTSYN_CRC_OFFSET], CANTSYN_CRCSIZE - 1);
                    Crc_Data[CANTSYN_BYTE_6] = CanTSyn_FUPDataList[CanTSyn_SYNCSlaveParm[Index].CurrentSC];
                    SchM_Exit_CanTSyn_CANTSYN_EXCLUSIVE_AREA_0();
                    crcResult = CANTSYN_CALCULATE_CRC(&Crc_Data[CANTSYN_BYTE_0], CANTSYN_CRCSIZE, CANTSYN_CRC_START_VALUE, TRUE);
                    if(crcResult == CanTSyn_RxData[CANTSYN_BYTE_1])
                    {
                        result = E_OK;
                    }
                    else
                    {
                        CanTSyn_SYNCSlaveParm[Index].Status = CANTSYN_IDLE;
                    }
#endif
                }
            }
        }
        else
        {
            CanTSyn_SYNCSlaveParm[Index].Status = CANTSYN_IDLE;
        }
    }
    else
    {
        CanTSyn_SYNCSlaveParm[Index].Status = CANTSYN_IDLE;
    }
        
    if(E_OK == result)
    {
        /*SWS_CanTSyn_00016,SWS_CanTSyn_00018*/
        CanTSyn_uint8Packuint32(&CanTSyn_RxData[CANTSYN_BYTE_4], &(CanTSyn_SYNCSlaveParm[Index].SyncTimeNSec));

        ovs = (uint32)((CanTSyn_RxData[CANTSYN_BYTE_3]) & CANTSYN_OVS_MASK);
        sgw = (CanTSyn_RxData[CANTSYN_BYTE_3]) & CANTSYN_SGW_MASK;
        if(CanTSyn_SYNCSlaveParm[Index].SyncTimeNSec <= CANTSYN_NS_MAXVALUE)
        {
            if(E_OK == StbM_GetCurrentTimeDiff(CanTSyn_SYNCSlaveParm[Index].TimeStampRaw, &timeStampDiff)) /*SWS_CanTSyn_00073*/
            {
                timeStamp.secondsHi = (uint16)0;
                timeStamp.seconds = CanTSyn_SYNCSlaveParm[Index].SyncTimeSec;
                timeStamp.nanoseconds = timeStampDiff + CanTSyn_SYNCSlaveParm[Index].SyncTimeNSec;

                if(timeStamp.nanoseconds >= CANTSYN_NS_MAXVALUE)
                {
                    ovs++;
                    timeStamp.nanoseconds -= CANTSYN_NS_MAXVALUE;
                }

                if((CANTSYN_S_MAXVALUE - ovs) < timeStamp.seconds)
                {
                    timeStamp.secondsHi += (uint16)1;
                }
                timeStamp.seconds += ovs;
                
                timeStamp.timeBaseStatus.GLOBAL_TIME_BASE = TRUE;
                timeStamp.timeBaseStatus.SYNC_TO_GATEWAY = sgw;
                
                /*SWS_CanTSyn_00064*/
                (void)StbM_BusSetGlobalTime(CanTSyn_ConfigPtr->SYNCSlave_Cfg[Index].timeBaseId, &timeStamp, &CanTSyn_SYNCSlaveParm[Index].UserData, sgw);
            }
            else
            {
                /*do nothing*/
            }
        }
        else
        {
            /*do nothing*/
        }
        CanTSyn_SYNCSlaveParm[Index].Status = CANTSYN_IDLE;
    }
    else
    {
        /*do nothing*/
    }

}
#endif
#if(0 < CANTSYN_OFS_SLAVE_NUM)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name : CanTSyn_RxOFSMsg
*
* Description   : Accept the OFS message
*
* Inputs        : -PduInfoPtr: Contains the length (SduLength) of the received I-PDU 
*                        and a pointer to a buffer (SduDataPtr) containing the I-PDU.
*
* Outputs       : None
*
* return        : None
*
* Limitations   : None
********************************************************************************
END_FUNCTION_HDR */
STATIC FUNC(void, CANTSYN_CODE) CanTSyn_RxOFSMsg
(
    uint8 Index
)
{   
    Std_ReturnType result = E_NOT_OK;
    uint8 offset;
    boolean ReTransmittingFlag = FALSE;  
#if (CANTSYN_CRC_ENABLED == STD_ON) 
    uint8 Crc_Data[CANTSYN_CRCSIZE];
    uint8 crcResult;
#endif
    CanTSyn_OFSSlaveParm[Index].CurrentSC = (CanTSyn_RxData[CANTSYN_BYTE_2]) & CANTSYN_SC_MASK;
    if((CanTSyn_ConfigPtr->OFSSlave_Cfg[Index].DomainId - CANTSYN_SC_OFFSET) == (((CanTSyn_RxData[CANTSYN_BYTE_2]) & CANTSYN_TD_MASK) >> CANTSYN_TD_SHIFT_BITS))
    {
        if(CANTSYN_OFS_NOT_CRC == CanTSyn_RxData[CANTSYN_BYTE_0])
        {
            result = E_OK;
        }
        else
        {
            if(CRC_IGNORED == CanTSyn_ConfigPtr->OFSSlave_Cfg[Index].CrcMode)
            {
                result = E_OK;
            }
            else
            {
#if (CANTSYN_CRC_ENABLED == STD_ON)
                /*SWS_CanTSyn_00080,SWS_CanTSyn_00081,SWS_CanTSyn_00084,SWS_CanTSyn_00085*/
                SchM_Enter_CanTSyn_CANTSYN_EXCLUSIVE_AREA_0();
                Bsw_MemCpy(Crc_Data, &CanTSyn_RxData[CANTSYN_CRC_OFFSET], CANTSYN_CRCSIZE - 1);
                Crc_Data[CANTSYN_BYTE_6] = CanTSyn_OFSDataList[CanTSyn_OFSSlaveParm[Index].CurrentSC];
                SchM_Exit_CanTSyn_CANTSYN_EXCLUSIVE_AREA_0();
                crcResult = CANTSYN_CALCULATE_CRC(&Crc_Data[CANTSYN_BYTE_0], CANTSYN_CRCSIZE, CANTSYN_CRC_START_VALUE, TRUE);
                if(crcResult == CanTSyn_RxData[CANTSYN_BYTE_1])
                {
                    result = E_OK;
                }
#endif
            }
        }
    }
    
    if(E_OK == result)
    {       
        /*SWS_CanTSyn_00019,SWS_CanTSyn_00021*/
        CanTSyn_OFSSlaveParm[Index].OfsTimeSecHi = (uint16)CanTSyn_RxData[CANTSYN_BYTE_3];
        CanTSyn_uint8Packuint32(&CanTSyn_RxData[CANTSYN_BYTE_4], &CanTSyn_OFSSlaveParm[Index].OfsTimeSec);
        if(TRUE == CanTSyn_OFSSlaveParm[Index].RxOFSIsFirst)
        {
            CanTSyn_OFSSlaveParm[Index].RxOFSIsFirst = FALSE; /*SWS_CanTSyn_00079*/
            CanTSyn_OFSSlaveParm[Index].Status = CANTSYN_OFS_DONE;
            CanTSyn_OFSSlaveParm[Index].RxFollowUpTimeOut = CanTSyn_ConfigPtr->OFSSlave_Cfg[Index].RxFollowUpTimeOut;/*SWS_CanTSyn_00063*/
        }
        else
        {
            /*SWS_CanTSyn_00078*/
            if(CanTSyn_OFSSlaveParm[Index].CurrentSC > CanTSyn_OFSSlaveParm[Index].OFS_LastSC)
            {
                offset = (uint8)0;
            }
            else
            {
                offset = CANTSYN_SC_OFFSET;
            }
            CanTSyn_OFSSlaveParm[Index].CurrentSC += offset;
            if((CanTSyn_OFSSlaveParm[Index].CurrentSC - CanTSyn_OFSSlaveParm[Index].OFS_LastSC) > (CanTSyn_ConfigPtr->OFSSlave_Cfg[Index].JumpWidth))
            {
                ReTransmittingFlag = CanTSyn_BeyondJumpWidth(CanTSyn_ConfigPtr->OFSSlave_Cfg[Index].DomainId); /*Offer to user*/
            }
    
            if(ReTransmittingFlag == FALSE)
            {
                CanTSyn_OFSSlaveParm[Index].Status = CANTSYN_OFS_DONE;
                CanTSyn_OFSSlaveParm[Index].RxFollowUpTimeOut = CanTSyn_ConfigPtr->OFSSlave_Cfg[Index].RxFollowUpTimeOut;/*SWS_CanTSyn_00063*/
            }
            else
            {
                CanTSyn_OFSSlaveParm[Index].Status = CANTSYN_IDLE;
            } 
			CanTSyn_OFSSlaveParm[Index].CurrentSC -= offset;
        }
        CanTSyn_OFSSlaveParm[Index].OFS_LastSC = CanTSyn_OFSSlaveParm[Index].CurrentSC;
    }
    else
    {
        CanTSyn_OFSSlaveParm[Index].Status = CANTSYN_IDLE;
    }
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name : CanTSyn_RxOFNSMsg
*
* Description   : Accept the OFNS message
*
* Inputs        : -PduInfoPtr: Contains the length (SduLength) of the received I-PDU 
*                        and a pointer to a buffer (SduDataPtr) containing the I-PDU.
*
* Outputs       : None
*
* return        : None
*
* Limitations   : None
********************************************************************************
END_FUNCTION_HDR */
STATIC FUNC(void, CANTSYN_CODE) CanTSyn_RxOFNSMsg
(
    uint8 Index
)
{
    Std_ReturnType result = E_NOT_OK;
    StbM_TimeStampType timeStamp;
#if (CANTSYN_CRC_ENABLED == STD_ON)
    uint8 Crc_Data[CANTSYN_CRCSIZE];
    uint8 crcResult;
#endif

    /*SWS_CanTSyn_00077*/
    if((CanTSyn_ConfigPtr->OFSSlave_Cfg[Index].DomainId - CANTSYN_SC_OFFSET) == (((CanTSyn_RxData[CANTSYN_BYTE_2]) & CANTSYN_TD_MASK) >> CANTSYN_TD_SHIFT_BITS))
    {
        if(CanTSyn_OFSSlaveParm[Index].CurrentSC == ((CanTSyn_RxData[CANTSYN_BYTE_2]) & CANTSYN_SC_MASK))
        {
            if(CANTSYN_OFNS_NOT_CRC == CanTSyn_RxData[CANTSYN_BYTE_0])
            {
                result = E_OK;
            }
            else
            {
                if(CRC_IGNORED == CanTSyn_ConfigPtr->OFSSlave_Cfg[Index].CrcMode)
                {
                    result = E_OK;
                }
                else
                {
#if (CANTSYN_CRC_ENABLED == STD_ON)
                    /*SWS_CanTSyn_00080,SWS_CanTSyn_00081,SWS_CanTSyn_00084,SWS_CanTSyn_00085*/
                    SchM_Enter_CanTSyn_CANTSYN_EXCLUSIVE_AREA_0();
                    Bsw_MemCpy(Crc_Data, &CanTSyn_RxData[CANTSYN_CRC_OFFSET], CANTSYN_CRCSIZE - 1);
                    Crc_Data[CANTSYN_BYTE_6] = CanTSyn_OFNSDataList[CanTSyn_OFSSlaveParm[Index].CurrentSC];
                    SchM_Exit_CanTSyn_CANTSYN_EXCLUSIVE_AREA_0();
                    crcResult = CANTSYN_CALCULATE_CRC(&Crc_Data[CANTSYN_BYTE_0], CANTSYN_CRCSIZE, CANTSYN_CRC_START_VALUE, TRUE);
                    if(crcResult == CanTSyn_RxData[CANTSYN_BYTE_1])
                    {
                        result = E_OK;
                    }
                    else
                    {
                        CanTSyn_OFSSlaveParm[Index].Status = CANTSYN_IDLE;
                    } 
#endif                   
                }
            }
        }
        else
        {
            CanTSyn_OFSSlaveParm[Index].Status = CANTSYN_IDLE;
        }
    }
    else
    {
        CanTSyn_OFSSlaveParm[Index].Status = CANTSYN_IDLE;
    }
        
    if(E_OK == result)
    {
        /*SWS_CanTSyn_00020,SWS_CanTSyn_00022*/
        CanTSyn_OFSSlaveParm[Index].OfsTimeSecHi |= (((uint16)CanTSyn_RxData[CANTSYN_BYTE_3]) << (uint16)CANTSYN_SECONDSHIGH_SHIFT_BITS);
        CanTSyn_uint8Packuint32(&CanTSyn_RxData[CANTSYN_BYTE_4], &(CanTSyn_OFSSlaveParm[Index].OfsTimeNSec));

        if(CanTSyn_OFSSlaveParm[Index].OfsTimeNSec <= CANTSYN_NS_MAXVALUE)
        {
            timeStamp.secondsHi = CanTSyn_OFSSlaveParm[Index].OfsTimeSecHi;
            timeStamp.seconds = CanTSyn_OFSSlaveParm[Index].OfsTimeSec;
            timeStamp.nanoseconds = CanTSyn_OFSSlaveParm[Index].OfsTimeNSec;           
            timeStamp.timeBaseStatus.GLOBAL_TIME_BASE = TRUE;
            (void)StbM_SetOffset(CanTSyn_ConfigPtr->OFSSlave_Cfg[Index].timeBaseId, &timeStamp); /*SWS_CanTSyn_00072*/
        }
        else
        {
            /*do nothing*/
        }
        CanTSyn_OFSSlaveParm[Index].Status = CANTSYN_IDLE;
    }
    else
    {
        /*do nothing*/
    }

}
#endif
#if(0 < CANTSYN_SYNC_SLAVE_NUM || 0 < CANTSYN_OFS_SLAVE_NUM)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name : CanTSyn_uint8Packuint32
*
* Description   : Converts four uint8 digits to one uint32 digit
*
* Inputs        : -SduDataPtr:pointer to a buffer
*
* Outputs       : -dataPtr: uint32 data Ptr
*
* return        : None
*
* Limitations   : None
********************************************************************************
END_FUNCTION_HDR */

STATIC FUNC (void, CANTSYN_CODE) CanTSyn_uint8Packuint32
(
    P2VAR(uint8, AUTOMATIC, CANTSYN_APPL_DATA) SduDataPtr,
    P2VAR(uint32, AUTOMATIC, CANTSYN_APPL_DATA) dataPtr
    
)
{
    *dataPtr = ((uint32)SduDataPtr[CANTSYN_BYTE_0] << CANTSYN_DATA_SHIFT_THREE_BYTES) |\
           ((uint32)SduDataPtr[CANTSYN_BYTE_1] << CANTSYN_DATA_SHIFT_TWO_BYTES) |\
           ((uint32)SduDataPtr[CANTSYN_BYTE_2] << CANTSYN_DATA_SHIFT_ONE_BYTE) |\
           ((uint32)SduDataPtr[CANTSYN_BYTE_3]);            
}
#endif

#define CANTSYN_STOP_SEC_CODE
#include "MemMap.h"


