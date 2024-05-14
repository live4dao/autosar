/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
*   File Name       : Xcp_Process.c
********************************************************************************
*   Project/Product : AUTOSAR 4.2
*   Title           : Xcp module source File
*   Author          : Hirain
********************************************************************************
*   Description     : Implementation of Xcp provided functionality
*
********************************************************************************
*   Limitations     : None
*
********************************************************************************
*
********************************************************************************
*   Revision History:
********************************************************************************
* END_FILE_HDR*/

/*******************************************************************************
* PRQA S 842 MISRA-C:2004 Rule 19.5
* These macro are only used in single cmd function, define them in block to make
* the code easy to read
* This part of code is verified manually and has no impact.
*******************************************************************************/

/*******************************************************************************
* PRQA S 3138 MISRA-C:2004 Rule 14.3
* PRQA S 3141
* These macro are configed by user if needed.If no use ,keep null
* This part of code is verified manually and has no impact.
*******************************************************************************/

/*******************************************************************************
* PRQA S 306 MISRA-C:2004 Rule 11.3
* PRQA S 506
* Xcp have to case MTA to pointer when use MTA to access memory.
* If MTA is valid has been checked by master of Xcp and user callback if configed.
* This part of code is verified manually and has no impact.
*******************************************************************************/



/*******************************************************************************
*   Includes
*******************************************************************************/
#include "Xcp_Std.h"
#include "Xcp_Cal.h"
#include "Xcp_Pag.h"
#include "Xcp_Daq.h"
#include "Xcp_Pgm.h"

/*******************************************************************************
*   Macro
*******************************************************************************/
#define XCP_INVALID_CMD_HANDLE   ((uint8)255)
#define XCP_CONNECT_CMD_LENGTH   ((PduLengthType)2)
/*******************************************************************************
*   local Data Define
*******************************************************************************/
#define XCP_START_SEC_CODE
#include "MemMap.h"

#define XCP_STOP_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
*   local Data Define
*******************************************************************************/
#define XCP_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

/*******************************************************************************
* PRQA S  3635 MISRA-C:2004 Rule 16.9
* PRQA 3120 2213
* this table is used to config xcp cmmond table, for Xcp's special implement
* This part of code is verified manually and has no impact.
*******************************************************************************/
STATIC CONST (Xcp_ServiceInfoType, XCP_CONST) XCP_gCmdTable[XCP_NUMBER_OF_COMMAND] =
{
    {(uint8)XCP_PGM_SUPPORTED, Xcp_FuncProgramVerify, (uint8)8, XCP_PGM_PROTECTED}, /* 0xC8 PROGRAM_VERIFY*/
    {(uint8)XCP_PGM_SUPPORTED, Xcp_FuncProgramMax, (uint8)2, XCP_PGM_PROTECTED}, /* 0xC9 PROGRAM_MAX*/
    {(uint8)XCP_PGM_SUPPORTED & (uint8)XCP_MASTER_BLOCK_MODE_PGM_SUPPORT, Xcp_FuncProgramNext, (uint8)2, XCP_PGM_PROTECTED}, /* 0xCA PROGRAM_NEXT*/
    {(uint8)XCP_PGM_SUPPORTED, Xcp_FuncProgramFormat, (uint8)5, XCP_PGM_PROTECTED},  /* 0xCB PROGRAM_FORMAT*/
    {(uint8)XCP_PGM_SUPPORTED, Xcp_FuncProgram_Prepare, (uint8)3, XCP_PGM_PROTECTED}, /* 0xCC PROGRAM_PREPARE*/
    {(uint8)XCP_PGM_SUPPORTED, Xcp_FuncGetSectorInfo, (uint8)3, XCP_PGM_PROTECTED},  /* 0xCD GET_SECTOR_INFO*/
    {(uint8)XCP_PGM_SUPPORTED, Xcp_FuncGetPgmProcessorInfo, (uint8)1, XCP_PGM_PROTECTED},  /* 0xCE GET_PGM_PROCESSOR_INFO*/

    {(uint8)XCP_PGM_SUPPORTED, Xcp_FuncProgramReset, (uint8)1, XCP_PGM_PROTECTED},  /* 0xCF PROGRAM_RESET*/
    {(uint8)XCP_PGM_SUPPORTED, Xcp_FuncProgram, (uint8)2, XCP_PGM_PROTECTED},       /* 0xD0 PROGRAM*/
    {(uint8)XCP_PGM_SUPPORTED, Xcp_FuncProgramClear, (uint8)8, XCP_PGM_PROTECTED},  /* 0xD1 PROGRAM_CLEAR*/
    {(uint8)XCP_PGM_SUPPORTED, Xcp_FuncProgramStart, (uint8)1, XCP_PGM_PROTECTED},  /* 0xD2 PROGRAM_START*/

    {(uint8)XCP_DAQ_SUPPORTED & (uint8)XCP_DAQ_CONFIG_DYNAMIC_SUPPORTED, NULL_PTR, (uint8)6, XCP_DAQ_PROTECTED}, /* 0xD3 */
    {(uint8)XCP_DAQ_SUPPORTED & (uint8)XCP_DAQ_CONFIG_DYNAMIC_SUPPORTED, NULL_PTR, (uint8)5, XCP_DAQ_PROTECTED}, /* 0xD4 */
    {(uint8)XCP_DAQ_SUPPORTED & (uint8)XCP_DAQ_CONFIG_DYNAMIC_SUPPORTED, NULL_PTR, (uint8)4, XCP_DAQ_PROTECTED}, /* 0xD5 */
    {(uint8)XCP_DAQ_SUPPORTED & (uint8)XCP_DAQ_CONFIG_DYNAMIC_SUPPORTED, NULL_PTR, (uint8)1, XCP_DAQ_PROTECTED}, /* 0xD6 */

    {(uint8)XCP_DAQ_SUPPORTED, Xcp_FuncGetDaqEventInfo, (uint8)4, XCP_NO_PROTECTED},  /* 0xD7 */
    {(uint8)XCP_DAQ_SUPPORTED, Xcp_FuncGetDaqListInfo, (uint8)4, XCP_NO_PROTECTED},    /* 0xD8 */
    {(uint8)XCP_DAQ_SUPPORTED, Xcp_FuncGetDaqResolution_Info, (uint8)1, XCP_NO_PROTECTED},    /* 0xD9 */
    {(uint8)XCP_DAQ_SUPPORTED, Xcp_FuncGetDaqProcessorInfo, (uint8)1, XCP_NO_PROTECTED},    /* 0xDA */
    {(uint8)XCP_DAQ_SUPPORTED, Xcp_FuncReadDaq, (uint8)1, XCP_DAQ_PROTECTED},    /* 0xDB */
    {(uint8)XCP_DAQ_SUPPORTED, Xcp_FuncGetDaqClock, (uint8)1, XCP_DAQ_PROTECTED},    /* 0xDC */

    {(uint8)XCP_DAQ_SUPPORTED, Xcp_FuncStartStopSynch, (uint8)2, XCP_DAQ_PROTECTED},    /* 0xDD */
    {(uint8)XCP_DAQ_SUPPORTED, Xcp_FuncStartStopDaqList, (uint8)4, XCP_DAQ_PROTECTED},    /* 0xDE */
    {(uint8)XCP_DAQ_SUPPORTED, Xcp_FuncGetDaqListMode, (uint8)4, XCP_DAQ_PROTECTED},    /* 0xDF */
    {(uint8)XCP_DAQ_SUPPORTED, Xcp_FuncSetDaqListMode, (uint8)8, XCP_DAQ_PROTECTED},    /* 0xE0 */
    {(uint8)XCP_DAQ_SUPPORTED, Xcp_FuncWriteDaq, (uint8)8, XCP_DAQ_PROTECTED},    /* 0xE1 */
    {(uint8)XCP_DAQ_SUPPORTED, Xcp_FuncSetDaqPtr, (uint8)6, XCP_DAQ_PROTECTED},    /* 0xE2 */
    {(uint8)XCP_DAQ_SUPPORTED, Xcp_FuncClearDaqList, (uint8)4, XCP_DAQ_PROTECTED},   /* 0xE3 */

    {(uint8)XCP_COPYPAG_SUPPORT, Xcp_FuncCopyCalPage, (uint8)5, XCP_CAL_PROTECTED},/* 0xE4 COPY_CAL_PAGE*/
    {(uint8)XCP_PAG_SUPPORTED, Xcp_FuncGetSegmentMode, (uint8)3, XCP_CAL_PROTECTED},/* 0xE5 GET_SEGMENT_MODE*/
    {(uint8)XCP_PAG_SUPPORTED, Xcp_FuncSetSegmentMode, (uint8)3, XCP_CAL_PROTECTED},/* 0xE6 SET_SEGMENT_MODE*/
    {(uint8)XCP_PAG_SUPPORTED, Xcp_FuncGetPageInfo, (uint8)4, XCP_CAL_PROTECTED},/* 0xE7 GET_PAGE_INFO*/
    {(uint8)XCP_PAG_SUPPORTED, Xcp_FuncGetSegmentInfo, (uint8)5, XCP_CAL_PROTECTED},/* 0xE8 GET_SEGMENT_INFO*/
    {(uint8)XCP_PAG_SUPPORTED, Xcp_FuncGetPageProcessorInfo, (uint8)1, XCP_CAL_PROTECTED},/* 0xE9 GET_PAG_PROCESSOR_INFO*/

    {(uint8)XCP_PAG_SUPPORTED, Xcp_FuncGetCalPage, (uint8)3, XCP_CAL_PROTECTED},/* 0xEA GET_CAL_PAGE*/
    {(uint8)XCP_PAG_SUPPORTED, Xcp_FuncSetCalPage, (uint8)4, XCP_CAL_PROTECTED},/* 0xEB SET_CAL_PAGE*/

    {(uint8)XCP_CAL_SUPPORTED & (uint8)XCP_MODIFYBITS_SUPPORT, Xcp_FuncModifyBits, (uint8)5, XCP_CAL_PROTECTED}, /* 0xEC MODIFY_BITS*/
    {(uint8)XCP_CAL_SUPPORTED, Xcp_FuncShortDownload, (uint8)8, XCP_CAL_PROTECTED},/* 0xED DOWNLOAD_SHORT*/
    {(uint8)XCP_CAL_SUPPORTED, Xcp_FuncDownloadMax, (uint8)2, XCP_CAL_PROTECTED},  /* 0xEE DOWNLOAD_MAX*/
    {(uint8)XCP_CAL_SUPPORTED & (uint8)XCP_MASTER_BLOCK_MODE_SUPPORT, Xcp_FuncDownloadNext, (uint8)3, XCP_CAL_PROTECTED}, /* 0xEF DOWNLOAD_NEXT*/

    {(uint8)XCP_CAL_SUPPORTED, Xcp_FuncDownload, (uint8)3, XCP_CAL_PROTECTED},  /* 0xF0 DOWNLOAD*/

    {(uint8)XCP_AUX_CMD_SUPPORT, Xcp_FuncUserCMD, (uint8)0, XCP_NO_PROTECTED},          /* 0xF1 USER_CMD */
    {(uint8)XCP_AUX_CMD_SUPPORT, Xcp_FuncTransportLayerCMD, (uint8)0, XCP_NO_PROTECTED},          /* 0xF1 TRANSPORT_LAYER_CMD */

    {(uint8)XCP_BUILDCS_SUPPORT, Xcp_FuncBuildCheckSum, (uint8)8, XCP_NO_PROTECTED}, /* 0xF3 BUILD_CHECKSUM */
    {(uint8)STD_ON, Xcp_FuncShortUpload, (uint8)8, XCP_NO_PROTECTED},/* 0xF4 SHORT_UPLOAD */
    {(uint8)STD_ON, Xcp_FuncUpload, (uint8)2, XCP_NO_PROTECTED},     /* 0xF5 UPLOAD*/
    {(uint8)STD_ON, Xcp_FuncSetMta, (uint8)8, XCP_NO_PROTECTED},     /* 0xF6 SET_MTA*/
    {(uint8)XCP_SEEDKEY_SUPPORT, Xcp_FuncUnlock, (uint8)3, XCP_NO_PROTECTED},     /* 0xF7 UNLOCK */
    {(uint8)XCP_SEEDKEY_SUPPORT, Xcp_FuncGetSeed, (uint8)3, XCP_NO_PROTECTED},    /* 0xF8 GET_SEED */
    {(uint8)STD_ON, Xcp_FuncSetRequest,(uint8) 4, XCP_NO_PROTECTED}, /* 0xF9 SET_REQUEST*/
    {(uint8)XCP_GETSLAVEID_SUPPORT, Xcp_FuncGetID, (uint8)2, XCP_NO_PROTECTED},      /* 0xFA GET_ID */
    {(uint8)STD_ON, Xcp_FuncGetCommModeInfo, (uint8)1, XCP_NO_PROTECTED},   /*0xFB GET_COMM_MODE_INFO*/

    {(uint8)STD_ON, Xcp_FuncSynch, (uint8)1, XCP_NO_PROTECTED},      /* 0xFC SYNCH*/
    {(uint8)STD_ON, Xcp_FuncGetStatus, (uint8)1, XCP_NO_PROTECTED},  /* 0xFD GET_STATUS*/
    {(uint8)STD_ON, Xcp_FuncDisconnect, (uint8)1, XCP_NO_PROTECTED}, /* 0xFE DISCONNECT*/
    {(uint8)STD_ON, Xcp_FuncConnect, (uint8)2, XCP_NO_PROTECTED}     /* 0xFF CONNECT*/
};

#define XCP_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

#define XCP_START_SEC_VAR_NOINIT_8
#include "MemMap.h"
VAR (uint8, XCP_VAR_NOINIT) Xcp_RxData[XCP_RX_BUFFER_SIZE];
VAR (uint8, XCP_VAR_NOINIT) Xcp_TxData[XCP_TX_BUFFER_SIZE];
VAR (uint8, XCP_VAR_NOINIT) Xcp_AsynJob;
VAR (boolean, XCP_VAR_NOINIT) Xcp_TransmitingFlag;
STATIC VAR (boolean, XCP_VAR_NOINIT) Xcp_ReTransmitCmdFlag;
#if(XCP_TX_TIMEOUT > 0)
STATIC VAR (uint8, XCP_VAR_NOINIT) Xcp_TransmitingCnt;
#endif
#define XCP_STOP_SEC_VAR_NOINIT_8
#include "MemMap.h"


#define XCP_START_SEC_VAR_NOINIT_16
#include "MemMap.h"
#if(XCP_ASYN_TIMEOUT > 0)
STATIC VAR (uint16, XCP_VAR_NOINIT) Xcp_AsynCnt;
#endif
VAR (PduLengthType, XCP_VAR_NOINIT) Xcp_RxPduLength;
#define XCP_STOP_SEC_VAR_NOINIT_16
#include "MemMap.h"


#define XCP_START_SEC_VAR_NOINIT_32
#include "MemMap.h"
VAR (uint32, XCP_VAR_NOINIT) Xcp_MTA;

#define XCP_STOP_SEC_VAR_NOINIT_32
#include "MemMap.h"

#define XCP_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"
VAR (PduInfoType, XCP_VAR_NOINIT) Xcp_TxPduInfo;
/* xcp link infomation
   only 1 link is allowed in one xcp process
   switch link must reset
*/
VAR (Xcp_LinkType, XCP_VAR_NOINIT) Xcp_ActiveLink;
#define XCP_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"



/*******************************************************************************
*   Internal Function Define
*******************************************************************************/
#define XCP_START_SEC_CODE
#include "MemMap.h"


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name : Xcp_CreatErrResponse
*
* Description   : This service set the error response.
*
* Inputs        : uint8 ErrorCode

* Outputs       : void
*
* Limitations   : None
********************************************************************************
END_FUNCTION_HDR */
FUNC(void, XCP_CODE) Xcp_CreatErrResponse
(
    const uint8 ErrorCode
)
{
    Xcp_TxData[XCP_PACKET_BYTE0] = XCP_CMD_ERROR_CODE;
    Xcp_TxData[XCP_PACKET_BYTE1] = ErrorCode;
    Xcp_TxPduInfo.SduLength = XCP_ERR_RES_BASIC_LENGTH;
    Xcp_TxPduInfo.SduDataPtr = Xcp_TxData;
}


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name : Xcp_PreReset
*
* Description   : reset vars before send disconnect response
*
* Inputs        : None

* Outputs       : None
*
* Limitations   : None
********************************************************************************
END_FUNCTION_HDR */
FUNC(void, XCP_CODE) Xcp_PreReset (void)
{
    uint16 bufferIndex;

    for (bufferIndex = (uint16)0 ; bufferIndex < XCP_RX_BUFFER_SIZE; bufferIndex++)
    {
        Xcp_RxData[bufferIndex] = (uint8)0;
    }

    Xcp_StdInit();

#if(STD_ON == XCP_CAL_SUPPORTED)
    Xcp_CalInit();
#endif

#if(STD_ON == XCP_PAG_SUPPORTED)
    Xcp_PagInit();
#endif

#if(STD_ON == XCP_PGM_SUPPORTED)
    Xcp_PgmInit();
#endif

#if(STD_ON == XCP_DAQ_SUPPORTED)
    Xcp_DaqInit();
#endif

    Xcp_MTA = (uint32)0;
    Xcp_AsynJob = XCP_NO_ASYN_JOB;
#if(XCP_ASYN_TIMEOUT > 0)
    Xcp_AsynCnt = (uint16)0;
#endif

}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name : Xcp_PostReset
*
* Description   : reset left vars after sending disconnect response
*
* Inputs        : None

* Outputs       : None
*
* Limitations   : None
********************************************************************************
END_FUNCTION_HDR */
FUNC(void, XCP_CODE) Xcp_PostReset (void)
{
    uint16 bufferIndex;

    for (bufferIndex = (uint16)0 ; bufferIndex < XCP_TX_BUFFER_SIZE; bufferIndex++)
    {
        Xcp_TxData[bufferIndex] = (uint8)0;
    }

    Xcp_TxPduInfo.SduLength = (PduLengthType)0;
    Xcp_TxPduInfo.SduDataPtr = NULL_PTR;
    /***************************************************************************
    * PRQA S 0277 MISRA-C:2004 Rule 3.1
    * ((PduIdType)(-1)) can dufill different size of PduIdType
    * This part of code is verified manually and has no impact.
    ***************************************************************************/
    Xcp_ActiveLink.XcpTpHandle = XCP_PRO_HANDLE_INVALID;
    Xcp_ActiveLink.XcpRxPduId = XCP_PDUID_HANDLE_INVALID;
    Xcp_ActiveLink.XcpTxPduId = XCP_PDUID_HANDLE_INVALID;
    Xcp_ActiveLink.XcpTxConfirmationPduId = XCP_PDUID_HANDLE_INVALID;
    Xcp_TransmitingFlag = FALSE;
    Xcp_ReTransmitCmdFlag = FALSE;
#if(XCP_TX_TIMEOUT > 0)
    Xcp_TransmitingCnt = (uint8)0;
#endif

}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name : Xcp_Reset
*
* Description   : Init process vars
*
* Inputs        : None

* Outputs       : None
*
* Limitations   : None
********************************************************************************
END_FUNCTION_HDR */
FUNC(void, XCP_CODE) Xcp_Reset (void)
{
    Xcp_PreReset();
    Xcp_PostReset();
}



/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name : Xcp_ProcessInit
*
* Description   : Init process vars
*
* Inputs        : None

* Outputs       : None
*
* Limitations   : None
********************************************************************************
END_FUNCTION_HDR */
FUNC(void, XCP_CODE) Xcp_ProcessInit (void)
{
    Xcp_Reset();

#if(STD_ON == XCP_ON_ETHERNET_ENABLED)
    Xcp_InitEth();
#endif
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name : Xcp_InternalProcessing
*
* Description   : This function is used to check internal status,and process asyn job
*
* Inputs        : None

* Outputs       : None
*
* Limitations   : None
********************************************************************************
END_FUNCTION_HDR */
FUNC(void, XCP_CODE) Xcp_InternalProcessing (void)
{
#if(XCP_ASYN_TIMEOUT > 0)

    if (XCP_NO_ASYN_JOB != Xcp_AsynJob)
    {
        /* time out must be handle here  */
        Xcp_AsynCnt++;

        if (Xcp_AsynCnt > XCP_ASYN_TIMEOUT)
        {
            /* callout here to report timeout */
#if(STD_ON == XCP_ASYN_TIMEOUT_CBK_SUPPORT)
            Xcp_AppAsynJobTimeout (Xcp_AsynJob);
#endif
            Xcp_AsynErrorNotification (XCP_ERR_GENERIC);
            Xcp_AsynCnt = (uint16)0;
        }
    }
    else
    {
        Xcp_AsynCnt = (uint16)0;
    }

#endif

#if(XCP_TX_TIMEOUT > 0)

    if (TRUE == Xcp_TransmitingFlag)
    {
        Xcp_TransmitingCnt++;

        if (Xcp_TransmitingCnt > XCP_TX_TIMEOUT)
        {
#if(STD_ON == XCP_TX_TIMEOUT_CBK_SUPPORT)
            Xcp_AppTxTimeout();
#endif

            Xcp_TransmitingFlag = FALSE;
            Xcp_TransmitingCnt = (uint8)0;
            if (TRUE == Xcp_SessionStatus.Bit.DAQ_RUNNING)
            {
                Xcp_RestartDaqPending();
            }
        }
    }

#endif

#if(STD_ON == XCP_DAQ_SUPPORTED)
    Xcp_DaqMainFuntion();
#endif

}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name : Xcp_TxConfirmation
*
* Description   : This function is used to move the DAQ_PTR to next ODT entry automatically.
*
* Inputs        : uint8 size

* Outputs       : None
*
* Limitations   : None
********************************************************************************
END_FUNCTION_HDR */
FUNC(void, XCP_CODE) Xcp_TxConfirmation (void)
{

    /* tx confirmed, clear counter */
    Xcp_TransmitingFlag = FALSE;
#if(XCP_TX_TIMEOUT > 0)
    Xcp_TransmitingCnt = (uint8)0;
#endif

    if (TRUE == Xcp_ReTransmitCmdFlag)
    {
        Xcp_ReTransmitCmdFlag = FALSE;
        Xcp_Transmit();
    }

#if(STD_ON == XCP_DAQ_SUPPORTED)
    else
    {
        Xcp_DaqTxContinue();
    }

#endif

#if(STD_ON == XCP_SLAVE_BLOCK_MODE_SUPPORT)
    Xcp_BlockUploadContinue();
#endif

}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name : Xcp_RxIndication
*
* Description   : Implementation of XCP command
*
* Inputs        : None

* Outputs       : None
*
* Limitations   : None
********************************************************************************
END_FUNCTION_HDR */
FUNC(void, XCP_CODE) Xcp_RxIndication (void)
{
    uint8 cmd;
    uint8 cmdhandle = XCP_INVALID_CMD_HANDLE;
    uint8 errcode = XCP_ERR_GENERIC;
    boolean errflag = FALSE;


    SchM_Enter_Xcp_XCP_EXCLUSIVE_AREA_0();
    cmd = Xcp_RxData[XCP_PACKET_BYTE0];
    SchM_Exit_Xcp_XCP_EXCLUSIVE_AREA_0();


    /* non connected status only process connected cmd
       or autodetected cmd
     */
    if (XCP_STATUS_CONNECTED != Xcp_Status)
    {
        if (cmd == XCP_CONNECT)
        {
            if (Xcp_RxPduLength < XCP_CONNECT_CMD_LENGTH)
            {
                errcode = XCP_ERR_CMD_SYNTAX;
                errflag = TRUE;
            }
            else
            {
                Xcp_FuncConnect();
            }
        }
    }
    else
    {
        /* check if cmd is valid  */
        if (cmd < XCP_PROGRAM_VERIFY)
        {
            errcode = XCP_ERR_CMD_UNKNOWN;
            errflag = TRUE;
        }
        else
        {
            /* check if cmd is supported */
            cmdhandle =  cmd - XCP_PROGRAM_VERIFY;

            if ((uint8)STD_OFF == XCP_gCmdTable[cmdhandle].CmdSwitch)
            {
                errcode = XCP_ERR_CMD_UNKNOWN;
                errflag = TRUE;
            }
            else
            {
                /* check if cmd length is shorter than min length  */
                if (Xcp_RxPduLength < XCP_gCmdTable[cmdhandle].MinPacketLength)
                {
                    errcode = XCP_ERR_CMD_SYNTAX;
                    errflag = TRUE;
                }
                else
                {
                    /* check if cmd is locked by seed&key */
                    if ((uint8)0 != (Xcp_ProtectMask & XCP_gCmdTable[cmdhandle].ProtectRes) )
                    {
                        errcode = XCP_ERR_ACCESS_LOCKED;
                        errflag = TRUE;
                    }
                }
            }
        }

#if(STD_ON == XCP_PGM_SUPPORTED)

        if (FALSE == errflag)
        {
            /*Connect GetStatus Synch GetCommModeInfo  GetID setMta dont need to report ERR_PGM_ACTIVE */
            /*PGM CMDs dont need to report ERR_PGM_ACTIVE */
            if ( (cmd != XCP_CONNECT)
                    && (cmd != XCP_GET_STATUS)
                    && (cmd != XCP_SYNCH)
                    && (cmd != XCP_GET_COMM_MODE_INFO)
                    && (cmd != XCP_GET_ID)
                    && (cmd != XCP_SET_MTA)
                    && (cmd != XCP_UPLOAD)
                    && (cmd != XCP_BUILD_CHECKSUM)
                    && (cmd > XCP_PROGRAM_START) )
            {
                if (TRUE == Xcp_PgmStartFlag)
                {
                    errcode = XCP_ERR_PGM_ACTIVE;
                    errflag = TRUE;
                }
            }
        }

#endif

        if (FALSE == errflag)
        {
            /*Connect GetStatus  Synch dont need to report ERR_CMD_BUSY */
            if ( (cmd != XCP_CONNECT)
                    && (cmd != XCP_GET_STATUS)
                    && (cmd != XCP_SYNCH) )
            {
                if (XCP_NO_ASYN_JOB != Xcp_AsynJob)
                {
                    errcode = XCP_ERR_CMD_BUSY;
                    errflag = TRUE;
                }
            }
        }

        if (FALSE == errflag)
        {
            if (NULL_PTR != XCP_gCmdTable[cmdhandle].XCPCmdFunc)
            {
                XCP_gCmdTable[cmdhandle].XCPCmdFunc();
            }
        }
    }


    if (TRUE == errflag)
    {
        Xcp_CreatErrResponse (errcode);
        Xcp_Transmit();
    }


}



/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name : Xcp_Transmit
*
* Description   : Implementation of XCP normal packet transmit
*
* Inputs        : None

* Outputs       : None
*
* Limitations   : None
********************************************************************************
END_FUNCTION_HDR */
FUNC(void, XCP_CODE) Xcp_Transmit (void)
{
    Std_ReturnType tem;

    if (TRUE == Xcp_TransmitingFlag)
    {
        Xcp_ReTransmitCmdFlag = TRUE;
    }
    else
    {
        tem = Xcp_TpProConfig[Xcp_ActiveLink.XcpTpHandle].TpTxFunc (&Xcp_TxPduInfo);

        if (E_OK == tem)
        {
            Xcp_TransmitingFlag = TRUE;
        }
        else
        {
            /* transmit fail */
            /* set flag , this packet will be retransmit in txconfirmation */
            Xcp_ReTransmitCmdFlag = TRUE;
        }
    }
}

/*******************************************************************************
* PRQA 3120
* this numbers are used to combine or split word and byte, only used here
* This part of code is verified manually and has no impact.
*******************************************************************************/

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name : Xcp_Make32Bits
*
* Description   : combine 4 bytes into a 32 bit dword
*
* Inputs        : byte0 - byte4

* Outputs       : None
*
* Limitations   : None
********************************************************************************
END_FUNCTION_HDR */
FUNC(uint32, XCP_CODE) Xcp_Make32Bits
(
    const uint8 byte0,
    const uint8 byte1,
    const uint8 byte2,
    const uint8 byte3
)
{
    uint32 temp1;
    uint32 temp2;
    uint32 temp3;
    uint32 temp4;

#if(XCP_MSB_FIRST  == XCP_BYTE_ORDER)
    temp1 = byte0;
    temp2 = byte1;
    temp3 = byte2;
    temp4 = byte3;
#else
    temp1 = byte3;
    temp2 = byte2;
    temp3 = byte1;
    temp4 = byte0;
#endif

    temp1 = (uint32)(temp1 << (uint8)24);
    temp2 = (uint32)(temp2 << (uint8)16);
    temp3 = (uint32)(temp3 << (uint8)8);
    temp1 = temp1 | temp2 | temp3 | temp4;

    return temp1;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name : Xcp_Make16Bits
*
* Description   : combine 2 bytes into a 16 bit word
*
* Inputs        : byte0 - byte1

* Outputs       : None
*
* Limitations   : None
********************************************************************************
END_FUNCTION_HDR */
FUNC(uint16, XCP_CODE) Xcp_Make16Bits
(
    const uint8 byte0,
    const uint8 byte1
)
{
    uint16 temp1;
    uint16 temp2;

#if(XCP_MSB_FIRST  == XCP_BYTE_ORDER)
    temp1 = byte0;
    temp2 = byte1;
#else
    temp1 = byte1;
    temp2 = byte0;
#endif

    temp1 = (uint16)(temp1 << (uint8)8);
    temp1 = temp1 | temp2;

    return temp1;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name : Xcp_GetByteOf16Bits
*
* Description   : get bytes from a 16 bit word
*
* Inputs        : High byte or loe byte

* Outputs       : None
*
* Limitations   : None
********************************************************************************
END_FUNCTION_HDR */
FUNC(uint8, XCP_CODE) Xcp_GetByteOf16Bits
(
    const uint16 value,
    const boolean highByte
)
{
    uint8 temp;

#if(XCP_MSB_FIRST  == XCP_BYTE_ORDER)

    if (TRUE == highByte)
    {
        temp = (uint8) (value >> (uint8)8);
    }
    else
    {
        temp = (uint8) value;
    }

#else

    if (FALSE == highByte)
    {
        temp = (uint8) (value >> (uint8)8);
    }
    else
    {
        temp = (uint8) value;
    }

#endif

    return temp;
}


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name : Xcp_GetByteOf32Bits
*
* Description   : get bytes from a 32 bit word
*
* Inputs        : byte index

* Outputs       : None
*
* Limitations   : None
********************************************************************************
END_FUNCTION_HDR */
FUNC(uint8, XCP_CODE) Xcp_GetByteOf32Bits
(
    const uint32 value,
    const uint8 index
)
{
    uint8 temp;
    uint8 tempShift;

#if(XCP_MSB_FIRST  == XCP_BYTE_ORDER)
    tempShift = ((uint8)3 - index) * (uint8)8;
#else
    tempShift = index * (uint8)8;
#endif

    temp = (uint8) (value >> tempShift);

    return temp;
}

#if((STD_ON == XCP_REQ_STORECALDATA_ASYN_SUPPORT) \
  ||(STD_ON == XCP_PGM_ASYN_SUPPORT)\
  ||(STD_ON == XCP_BUILDCS_ASYN_SUPPORT) \
  ||(STD_ON == XCP_COPYPAG_ASYN_SUPPORT))
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name : Xcp_AsynJobEndNotification
*
* Description   : this function is used to notify xcp that asyn job is finished
*
* Inputs        : None

* Outputs       : None
*
* Limitations   : None
********************************************************************************
END_FUNCTION_HDR */
FUNC(void, XCP_CODE) Xcp_AsynJobEndNotification (void)
{
    if (XCP_NO_ASYN_JOB != Xcp_AsynJob)
    {
#if((STD_ON == XCP_BUILDCS_SUPPORT) && (STD_ON == XCP_BUILDCS_ASYN_SUPPORT))

        if (XCP_BUILDCS_JOB == Xcp_AsynJob)
        {
            Xcp_BuildCSEndNotification();
        }
        else
#endif
        {
#if(STD_ON == XCP_SETREQ_SUPPORT)
#if((STD_ON == XCP_REQ_STORECALDATA_SUPPORT) && (STD_ON == XCP_REQ_STORECALDATA_ASYN_SUPPORT))

            if ( (XCP_STORECALDATA_JOB == Xcp_AsynJob) && (1 == Xcp_SessionStatus.Bit.STORE_CAL_REQ) )
            {
                Xcp_SessionStatus.Bit.STORE_CAL_REQ = 0;
            }

#endif
#endif
            Xcp_AsynJob = XCP_NO_ASYN_JOB;
            /* send pos reponse */
            Xcp_TxData[XCP_PACKET_BYTE0] = XCP_CMD_RES_CODE;
            Xcp_TxPduInfo.SduLength = XCP_NORMAL_POSLEN;
            Xcp_TxPduInfo.SduDataPtr = Xcp_TxData;
            Xcp_Transmit();
        }
    }

}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name : Xcp_AsynErrorNotification
*
* Description   : this function is used to notify xcp that asyn job is failed
*
* Inputs        : None

* Outputs       : None
*
* Limitations   : None
********************************************************************************
END_FUNCTION_HDR */
FUNC(void, XCP_CODE) Xcp_AsynErrorNotification
(
    const uint8 errcode
)
{
    if (XCP_NO_ASYN_JOB != Xcp_AsynJob)
    {
        /* if  buildcs asyn job err here, only reprot FF as other err packet. */


#if(STD_ON == XCP_SETREQ_SUPPORT)
#if((STD_ON == XCP_REQ_STORECALDATA_SUPPORT) && (STD_ON == XCP_REQ_STORECALDATA_ASYN_SUPPORT))

        if ( (XCP_STORECALDATA_JOB == Xcp_AsynJob) && (1 == Xcp_SessionStatus.Bit.STORE_CAL_REQ) )
        {
            Xcp_SessionStatus.Bit.STORE_CAL_REQ = 0;
        }

#endif
#endif
        Xcp_AsynJob = XCP_NO_ASYN_JOB;
        /* send neg reponse */
        Xcp_CreatErrResponse (errcode);
        Xcp_Transmit();
    }
}
#endif


#define XCP_STOP_SEC_CODE
#include "MemMap.h"
