/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
*   File Name       : Xcp_Pag.c
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
*   Includes
*******************************************************************************/
#include "Xcp_Pgm.h"

#if(STD_ON == XCP_PGM_SUPPORTED)
/*******************************************************************************
*   Macro
*******************************************************************************/
#define XCP_PROGRAM_ADDR_ABS_MODE             ((uint8)0)
#define XCP_PROGRAM_ADDR_FUN_MODE             ((uint8)1)

#define XCP_PROGRAM_START_POSLEN              ((PduLengthType)7)
#if(STD_ON == XCP_MASTER_BLOCK_MODE_PGM_SUPPORT)
#define XCP_PROG_FIX_BYTES                    ((uint8)2)
#endif

#define XCP_PROGRAM_CLEAR_POSLEN              ((PduLengthType)1)

#define XCP_GET_PGM_PROCESSOR_INFO_POSLEN     ((PduLengthType)3)

#define XCP_GET_SECTOR_INFO_ADDRMODE          ((uint8)0)
#define XCP_GET_SECTOR_INFO_LENGTHMODE        ((uint8)1)
#define XCP_GET_SECTOR_INFO_POSLEN            ((PduLengthType)8)

#define  XCP_PGMNEXT_NAGRES_LEN               (3)

#define XCP_PROGRAM_VERIFY_FUN_MODE           (0)
#define XCP_PROGRAM_VERIFY_VAL_MODE           (1)
/*******************************************************************************
*   local Data Define
*******************************************************************************/
#define XCP_START_SEC_CODE
#include "MemMap.h"

#define XCP_STOP_SEC_CODE
#include "MemMap.h"



#define XCP_START_SEC_VAR_NOINIT_8
#include "MemMap.h"

VAR (boolean, XCP_VAR_NOINIT) Xcp_PgmStartFlag;
#if(STD_ON == XCP_PGM_FUN_ADDR_SUPPORTED)
STATIC VAR (uint8, XCP_VAR_NOINIT) Xcp_PGMMode;
#endif
/* the download data will copy to this buffer first,then write to flash
  this buffer is used for masterblock mode , also for data consistance
*/
STATIC VAR (uint8, XCP_VAR_NOINIT) Xcp_BlockBuffer_PGM[XCP_PGM_BUFFER_SIZE];


#define XCP_STOP_SEC_VAR_NOINIT_8
#include "MemMap.h"

#define XCP_START_SEC_VAR_NOINIT_16
#include "MemMap.h"

#if(STD_ON == XCP_MASTER_BLOCK_MODE_PGM_SUPPORT)
STATIC VAR (uint16, XCP_VAR_NOINIT) Xcp_DownloadLength_PGM;
STATIC VAR (uint16, XCP_VAR_NOINIT) Xcp_BlockBufIndex_PGM;
#endif

#define XCP_STOP_SEC_VAR_NOINIT_16
#include "MemMap.h"

/*******************************************************************************
*   Internal Function Define
*******************************************************************************/
#define XCP_START_SEC_CODE
#include "MemMap.h"

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name : Xcp_PgmInit
*
* Description   : Init vars used in Pgm cmd
*
* Inputs        : None

* Outputs       : None
*
* Limitations   : None
********************************************************************************
END_FUNCTION_HDR */
FUNC(void, XCP_CODE) Xcp_PgmInit (void)
{
    uint16 bufferIndex;

    Xcp_PgmStartFlag = FALSE;

    for (bufferIndex = (uint16)0; bufferIndex < (uint16)XCP_PGM_BUFFER_SIZE; bufferIndex++)
    {
        Xcp_BlockBuffer_PGM[bufferIndex] = (uint8)0;
    }

#if(STD_ON == XCP_MASTER_BLOCK_MODE_PGM_SUPPORT)
    Xcp_DownloadLength_PGM = (uint16)0;
    Xcp_BlockBufIndex_PGM = (uint16)0;
#endif
}


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name : Xcp_FuncProgramStart
*
* Description    : Implementation of Xcp_FuncProgramStart command
*
* Inputs        : None

* Outputs        : None
*
* Limitations    : None
********************************************************************************
END_FUNCTION_HDR */
FUNC(void, XCP_CODE) Xcp_FuncProgramStart (void)
{
#if(STD_ON == XCP_PGMSTART_SUPPORT)
    Std_ReturnType tem;
#endif

    uint8 maxBS;
#if(STD_ON == XCP_MASTER_BLOCK_MODE_PGM_SUPPORT)
    uint8 tempLength;
#endif



    if ((uint8)1 == Xcp_SessionStatus.Bit.DAQ_RUNNING)
    {
        Xcp_CreatErrResponse (XCP_ERR_DAQ_ACTIVE);
    }
    else
    {
#if(STD_ON == XCP_PGMSTART_SUPPORT)
        tem = Xcp_AppPGMStart();

        if (E_OK != tem)
        {
            Xcp_CreatErrResponse (XCP_ERR_GENERIC);
        }
        else
#endif
        {
#if(STD_ON == XCP_MASTER_BLOCK_MODE_PGM_SUPPORT)
#if(XCP_AG > 2)
            tempLength = XCP_AG;
#else
            tempLength = XCP_PROG_FIX_BYTES;
#endif
            /* if buffersize is too small ,maxBS =0, the config tool must report error */
            maxBS = (uint8) (XCP_PGM_BUFFER_SIZE / (Xcp_TpProConfig[Xcp_ActiveLink.XcpTpHandle].MaxCtoPGM - tempLength) );
#else
            maxBS = (uint8)0;
#endif

            Xcp_PgmStartFlag = TRUE;
            Xcp_TxData[XCP_PACKET_BYTE0] = XCP_CMD_RES_CODE;
            Xcp_TxData[XCP_PACKET_BYTE1] = XCP_RESERVED_BYTE;
            Xcp_TxData[XCP_PACKET_BYTE2] = XCP_COMM_MODE_PGM;
            Xcp_TxData[XCP_PACKET_BYTE3] = Xcp_TpProConfig[Xcp_ActiveLink.XcpTpHandle].MaxCtoPGM;
            Xcp_TxData[XCP_PACKET_BYTE4] = maxBS;
            Xcp_TxData[XCP_PACKET_BYTE5] = XCP_MIN_ST_PGM;
            Xcp_TxData[XCP_PACKET_BYTE6] = XCP_QUEUE_SIZE_PGM;

            Xcp_TxPduInfo.SduLength = XCP_PROGRAM_START_POSLEN;
            Xcp_TxPduInfo.SduDataPtr = Xcp_TxData;
        }
    }

    Xcp_Transmit();

}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name : Xcp_FuncProgramClear
*
* Description   : Implementation of Xcp_FuncProgramClear command
*
* Inputs        : None

* Outputs       : None
*
* Limitations   : None
********************************************************************************
END_FUNCTION_HDR */
FUNC(void, XCP_CODE) Xcp_FuncProgramClear (void)
{
    uint8 mode;
    uint32 Clear_Range;
    Std_ReturnType result;
#if(STD_ON == XCP_PGM_ASYN_SUPPORT)
    boolean sendRespFlag = TRUE;
#endif



    SchM_Enter_Xcp_XCP_EXCLUSIVE_AREA_0();
    mode = Xcp_RxData[XCP_PACKET_BYTE1];
    Clear_Range = Xcp_Make32Bits (Xcp_RxData[XCP_PACKET_BYTE4], Xcp_RxData[XCP_PACKET_BYTE5],
                                  Xcp_RxData[XCP_PACKET_BYTE6], Xcp_RxData[XCP_PACKET_BYTE7]);
    SchM_Exit_Xcp_XCP_EXCLUSIVE_AREA_0();

    if (FALSE ==  Xcp_PgmStartFlag)
    {
        Xcp_CreatErrResponse (XCP_ERR_SEQUENCE);
    }
    else if (mode != XCP_PROGRAM_ADDR_ABS_MODE)
    {
        Xcp_CreatErrResponse (XCP_ERR_OUT_OF_RANGE);
    }
    else
    {

        /* user need to check the address valid or not
           if valid need to do the clear job in this callback
           if the clear job must be done asyn, this callback need to retuen pending
           and the response will not send immdiatly
           the clear job will be done in mainfuction
        */
        result = Xcp_AppClearMemory (mode, Xcp_AddressExtension, Xcp_MTA, Clear_Range);

        if (XCP_ASYN_JOB_OK == result)
        {
            Xcp_TxData[XCP_PACKET_BYTE0] = XCP_CMD_RES_CODE;
            Xcp_TxPduInfo.SduLength = XCP_NORMAL_POSLEN;
            Xcp_TxPduInfo.SduDataPtr = Xcp_TxData;
        }

#if(STD_ON == XCP_PGM_ASYN_SUPPORT)
        else if (XCP_ASYN_JOB_PENDING == result)
        {
            sendRespFlag = FALSE;
            Xcp_AsynJob = XCP_PGM_CLEAR_JOB;
        }

#endif
        else
        {
            Xcp_CreatErrResponse (XCP_ERR_ACCESS_DENIED);
        }
    }

#if(STD_ON == XCP_PGM_ASYN_SUPPORT)

    if (TRUE == sendRespFlag)
#endif
    {
        Xcp_Transmit();
    }
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name : Xcp_FuncProgram
*
* Description   : Implementation of Xcp_FuncProgram command
*
* Inputs        : None

* Outputs       : None
*
* Limitations   : None
********************************************************************************
END_FUNCTION_HDR */
FUNC(void, XCP_CODE) Xcp_FuncProgram (void)
{
    uint8 NumOfElement;
    Std_ReturnType tem;
    uint16 lengthInBytes;
    const uint16 maxCto = Xcp_TpProConfig[Xcp_ActiveLink.XcpTpHandle].MaxCto;
    uint16 index;
#if(STD_ON == XCP_PGM_ASYN_SUPPORT || STD_ON == XCP_MASTER_BLOCK_MODE_PGM_SUPPORT)
    boolean respFlag = TRUE;
#endif

#if(STD_ON == XCP_CHECKPROGADDR_CBK_SUPPORT)
    uint8 errorcode = XCP_NO_ERR;
#endif

    SchM_Enter_Xcp_XCP_EXCLUSIVE_AREA_0();
    NumOfElement = Xcp_RxData[XCP_PACKET_BYTE1];
    SchM_Exit_Xcp_XCP_EXCLUSIVE_AREA_0();

    lengthInBytes = NumOfElement;
#if(XCP_AG > 1)
    lengthInBytes = lengthInBytes * XCP_AG;
#endif

    if (FALSE ==  Xcp_PgmStartFlag)
    {
        Xcp_CreatErrResponse (XCP_ERR_SEQUENCE);
    }

#if(STD_OFF == XCP_MASTER_BLOCK_MODE_PGM_SUPPORT)
    /* when no master block , num can not bigger than CTO*/
    else if ( (lengthInBytes + XCP_PROGRAM_DATA_OFFSET) > maxCto)
    {
        /* numElement = MAXDTO/AG - 1*/
        Xcp_CreatErrResponse (XCP_ERR_OUT_OF_RANGE);
    }

#else
    /* when master block , num can not bigger than BS*/
    /***************************************************************************
    * PRQA S 3356 3359  MISRA-C:2004 Rule 13.7
    * PRQA S 3201 MISRA-C:2004 Rule 14.1
    * The result may always false in some user configration, but different in
    * other configration.Keep this for all config.
    * This part of code is verified manually and has no impact.
    ***************************************************************************/
    else if (lengthInBytes > XCP_PGM_BUFFER_SIZE)
    {
        /* numElement = MAXDTO/AG - 1*/
        Xcp_CreatErrResponse (XCP_ERR_OUT_OF_RANGE);
    }

#endif
    else
    {
        if ((uint8)0 == NumOfElement)
        {
            /* this means the end of this segment */
#if(STD_ON == XCP_PROGSEGMENTEND_CBK_SUPPORT)
            Xcp_AppProgSegmentEnd();
#endif
            Xcp_TxData[XCP_PACKET_BYTE0] = XCP_CMD_RES_CODE;
            Xcp_TxPduInfo.SduLength = XCP_NORMAL_POSLEN;
            Xcp_TxPduInfo.SduDataPtr = Xcp_TxData;

        }
        else
        {
            /*    App need to check MTA is valid or not
                MTA + length is valid or not
                if the target addr is write protected
            */
#if(STD_ON == XCP_CHECKPROGADDR_CBK_SUPPORT)
            tem = Xcp_AppCheckProgAddr (XCP_PROGRAM_ADDR_ABS_MODE, Xcp_AddressExtension, Xcp_MTA, lengthInBytes, &errorcode);

            if (E_OK != tem)
            {
                Xcp_CreatErrResponse (errorcode);
            }
            else
#endif
            {
#if(STD_ON == XCP_MASTER_BLOCK_MODE_PGM_SUPPORT)

                if ( (lengthInBytes + XCP_PROGRAM_DATA_OFFSET) > maxCto)
                {
                    respFlag = FALSE;
                    SchM_Enter_Xcp_XCP_EXCLUSIVE_AREA_0();

                    for (index = (uint16)0; index < (maxCto - XCP_PROGRAM_DATA_OFFSET); index++)
                    {
                        Xcp_BlockBuffer_PGM[Xcp_BlockBufIndex_PGM] = Xcp_RxData[XCP_PACKET_HEADER + XCP_PROGRAM_DATA_OFFSET + index];
                        Xcp_BlockBufIndex_PGM++;
                        /* dont add mta here ,in block mode , only when all bytes received
                           copy to mta
                        */
                    }

                    SchM_Exit_Xcp_XCP_EXCLUSIVE_AREA_0();
                    Xcp_DownloadLength_PGM = lengthInBytes - (maxCto - XCP_PROGRAM_DATA_OFFSET);
                }
                else
#endif
                {
                    SchM_Enter_Xcp_XCP_EXCLUSIVE_AREA_0();

                    for (index = (uint16)0; index < lengthInBytes; index++)
                    {
                        Xcp_BlockBuffer_PGM[index] = Xcp_RxData[XCP_PACKET_HEADER + XCP_PROGRAM_DATA_OFFSET + index];
                    }

                    SchM_Exit_Xcp_XCP_EXCLUSIVE_AREA_0();

                    tem = Xcp_AppProgMemory (XCP_PROGRAM_ADDR_ABS_MODE, Xcp_AddressExtension, Xcp_MTA, lengthInBytes, Xcp_BlockBuffer_PGM);

                    if (XCP_ASYN_JOB_OK == tem)
                    {
                        Xcp_MTA = Xcp_MTA + (uint32)lengthInBytes;
                        Xcp_TxData[XCP_PACKET_BYTE0] = XCP_CMD_RES_CODE;
                        Xcp_TxPduInfo.SduLength = XCP_NORMAL_POSLEN;
                        Xcp_TxPduInfo.SduDataPtr = Xcp_TxData;
                    }

#if(STD_ON == XCP_PGM_ASYN_SUPPORT)
                    else if (XCP_ASYN_JOB_PENDING == tem)
                    {
                        respFlag = FALSE;
                        Xcp_AsynJob = XCP_PGM_PROG_JOB;
                    }

#endif
                    else
                    {
                        /* notok or other invalid return code */
                        Xcp_CreatErrResponse (XCP_ERR_ACCESS_DENIED);
                    }
                }
            }
        }
    }

#if(STD_ON == XCP_PGM_ASYN_SUPPORT || STD_ON == XCP_MASTER_BLOCK_MODE_PGM_SUPPORT)
    if (TRUE == respFlag)
#endif
    {
        Xcp_Transmit();
    }

}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name : Xcp_FuncProgramReset
*
* Description   : Implementation of Xcp_FuncProgramReset command
*
* Inputs        : None

* Outputs       : None
*
* Limitations   : None
********************************************************************************
END_FUNCTION_HDR */
FUNC(void, XCP_CODE) Xcp_FuncProgramReset (void)
{
#if(STD_ON == XCP_PRERESET_CBK_SUPPORT)
    Std_ReturnType tem;
#endif

    if (FALSE ==  Xcp_PgmStartFlag)
    {
        Xcp_CreatErrResponse (XCP_ERR_SEQUENCE);
        Xcp_Transmit();
    }
    else
    {
        /*
            if this call back retrun notok, the xcp will not send response and reset hw
        */
#if(STD_ON == XCP_PRERESET_CBK_SUPPORT)
        tem = Xcp_AppPGMPreReset();

        if (E_OK == tem)
#endif
        {
            Xcp_TxData[XCP_PACKET_BYTE0] = XCP_CMD_RES_CODE;
            Xcp_TxPduInfo.SduLength = XCP_NORMAL_POSLEN;
            Xcp_TxPduInfo.SduDataPtr = Xcp_TxData;
            Xcp_Transmit();
        }

        Xcp_Reset();

        /* do hw reset in this call back if needed*/
#if(STD_ON == XCP_RESET_CBK_SUPPORT)
        Xcp_AppPGMReset();
#endif
    }
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name : Xcp_FuncGetPgmProcessorInfo
*
* Description   : Implementation of Xcp_FuncGetPgmProcessorInfo command
*
* Inputs        : None

* Outputs       : None
*
* Limitations   : None
********************************************************************************
END_FUNCTION_HDR */
FUNC(void, XCP_CODE) Xcp_FuncGetPgmProcessorInfo (void)
{
    Xcp_TxData[XCP_PACKET_BYTE0] = XCP_CMD_RES_CODE;
    Xcp_TxData[XCP_PACKET_BYTE1] = XCP_PGM_PROPERTIES;
    Xcp_TxData[XCP_PACKET_BYTE2] = (uint8)XCP_MAX_SECTOR;

    Xcp_TxPduInfo.SduLength = XCP_GET_PGM_PROCESSOR_INFO_POSLEN;
    Xcp_TxPduInfo.SduDataPtr = Xcp_TxData;
    Xcp_Transmit();
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name : Xcp_FuncGetSectorInfo
*
* Description   : Implementation of Xcp_FuncGetSectorInfo command
*
* Inputs        : None

* Outputs       : None
*
* Limitations   : None
********************************************************************************
END_FUNCTION_HDR */
FUNC(void, XCP_CODE) Xcp_FuncGetSectorInfo (void)
{
    uint8 mode;
    uint8 secNum;
#if(XCP_MAX_SECTOR > 0)
    uint32 info;
    uint8 clearSeqNum = (uint8)0;
    uint8 progSeqNum = (uint8)0;
#endif


    SchM_Enter_Xcp_XCP_EXCLUSIVE_AREA_0();
    mode = Xcp_RxData[XCP_PACKET_BYTE1];
    secNum = Xcp_RxData[XCP_PACKET_BYTE2];
    SchM_Exit_Xcp_XCP_EXCLUSIVE_AREA_0();

    if (mode > XCP_GET_SECTOR_INFO_LENGTHMODE)
    {
        Xcp_CreatErrResponse (XCP_ERR_OUT_OF_RANGE);
    }
    else if (secNum >= (uint8)XCP_MAX_SECTOR)
    {
        Xcp_CreatErrResponse (XCP_ERR_OUT_OF_RANGE);
    }
    else
    {
#if(XCP_MAX_SECTOR > 0)
        /* if app cannot set seqnum or dont need seqnum or dont supported seqnum
           this callback has no impact seqnum will keep zero
        */
#if(STD_ON == XCP_GETSEQNUM_CBK_SUPPORT)
        Xcp_AppGetSequenceNumber (secNum, &clearSeqNum, &progSeqNum);
#endif
        Xcp_TxData[XCP_PACKET_BYTE0] = XCP_CMD_RES_CODE;
        Xcp_TxData[XCP_PACKET_BYTE1] = clearSeqNum;
        Xcp_TxData[XCP_PACKET_BYTE2] = progSeqNum;
        Xcp_TxData[XCP_PACKET_BYTE3] = (uint8)0;/* not supported progmethod */

        if (XCP_GET_SECTOR_INFO_ADDRMODE == mode)
        {
            info = XCP_Sector_Info[secNum].Start_Address;
        }
        else
        {
            info = XCP_Sector_Info[secNum].Sector_Length;
        }

        Xcp_TxData[XCP_PACKET_BYTE4] = Xcp_GetFirstByte (info);
        Xcp_TxData[XCP_PACKET_BYTE5] = Xcp_GetSecondByte (info);
        Xcp_TxData[XCP_PACKET_BYTE6] = Xcp_GetThirdByte (info);
        Xcp_TxData[XCP_PACKET_BYTE7] = Xcp_GetFourthByte (info);


        Xcp_TxPduInfo.SduLength = XCP_GET_SECTOR_INFO_POSLEN;
        Xcp_TxPduInfo.SduDataPtr = Xcp_TxData;
#endif

    }

    Xcp_Transmit();

}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name : Xcp_FuncProgram_Prepare
*
* Description   : Implementation of Xcp_FuncProgram_Prepare command
*
* Inputs        : None

* Outputs       : None
*
* Limitations   : None
********************************************************************************
END_FUNCTION_HDR */
FUNC(void, XCP_CODE) Xcp_FuncProgram_Prepare (void)
{
#if(STD_ON == XCP_PREPAREPROG_SUPPORT)

    Std_ReturnType tem;
    uint8 errorcode = XCP_NO_ERR;
    uint32 Size;

    SchM_Enter_Xcp_XCP_EXCLUSIVE_AREA_0();
    Size = (uint32) (Xcp_Make16Bits (Xcp_RxData[XCP_PACKET_BYTE2], Xcp_RxData[XCP_PACKET_BYTE3]) );
    SchM_Exit_Xcp_XCP_EXCLUSIVE_AREA_0();

    /* turn to size in bytes */
#if(XCP_AG > 1)
    Size = Size * XCP_AG;
#endif

    /* check addr range in abs addr mode, and set the target range into ready to prog mode
       if addr is not valid return not ok
       if the target cannot be set into ready, return not ok
    */
    tem = Xcp_AppPrepareProg (Xcp_AddressExtension, Xcp_MTA, Size, &errorcode);

    if (E_OK != tem)
    {
        Xcp_CreatErrResponse (errorcode);
    }
    else
#endif
    {
        Xcp_TxData[XCP_PACKET_BYTE0] = XCP_CMD_RES_CODE;
        Xcp_TxPduInfo.SduLength = XCP_NORMAL_POSLEN;
        Xcp_TxPduInfo.SduDataPtr = Xcp_TxData;
    }

    Xcp_Transmit();
}

#if(STD_ON == XCP_MASTER_BLOCK_MODE_PGM_SUPPORT)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name : Xcp_FuncProgramNext
*
* Description   : Implementation of Xcp_FuncProgramNext command
*
* Inputs        : None

* Outputs       : None
*
* Limitations   : None
********************************************************************************
END_FUNCTION_HDR */
FUNC(void, XCP_CODE) Xcp_FuncProgramNext (void)
{
    uint8 NumOfElement;
    uint16 lengthInBytes;
    const uint16 maxCto = Xcp_TpProConfig[Xcp_ActiveLink.XcpTpHandle].MaxCto;
    uint16 index;
    boolean respFlag = TRUE;
    uint8 tem;


    SchM_Enter_Xcp_XCP_EXCLUSIVE_AREA_0();
    NumOfElement = Xcp_RxData[XCP_PACKET_BYTE1];
    SchM_Exit_Xcp_XCP_EXCLUSIVE_AREA_0();

    lengthInBytes = NumOfElement;
#if(XCP_AG > 1)
    lengthInBytes = lengthInBytes * (uint16)XCP_AG;
#endif



    if ( ((uint16)0 == Xcp_DownloadLength_PGM) || (Xcp_DownloadLength_PGM != lengthInBytes) )
    {
        /* not waiting download next*/
        /* need to report remain length of download */
        Xcp_TxData[XCP_PACKET_BYTE0] = XCP_CMD_ERROR_CODE;
        Xcp_TxData[XCP_PACKET_BYTE1] = XCP_ERR_SEQUENCE;
#if(XCP_AG > 1)
        Xcp_TxData[XCP_PACKET_BYTE2] = (uint8) Xcp_DownloadLength_PGM / (uint8)XCP_AG;
#else
        Xcp_TxData[XCP_PACKET_BYTE2] = (uint8) Xcp_DownloadLength_PGM;
#endif
        Xcp_TxPduInfo.SduLength = XCP_PGMNEXT_NAGRES_LEN;
        Xcp_TxPduInfo.SduDataPtr = Xcp_TxData;
        Xcp_DownloadLength_PGM = (uint16)0;
        Xcp_BlockBufIndex_PGM = (uint16)0;
    }
    else
    {
        if ( (Xcp_DownloadLength_PGM + (uint16)XCP_PROGRAM_DATA_OFFSET) > maxCto)
        {
            respFlag = FALSE;
            SchM_Enter_Xcp_XCP_EXCLUSIVE_AREA_0();

            for (index = (uint16)0; index < (maxCto - (uint16)XCP_PROGRAM_DATA_OFFSET); index++)
            {
                Xcp_BlockBuffer_PGM[Xcp_BlockBufIndex_PGM] = Xcp_RxData[XCP_PACKET_HEADER + (uint16)XCP_PROGRAM_DATA_OFFSET + index];
                Xcp_BlockBufIndex_PGM++;
                /* dont add mta here ,in block mode , only when all bytes received
                   copy to mta
                */
            }

            SchM_Exit_Xcp_XCP_EXCLUSIVE_AREA_0();
            Xcp_DownloadLength_PGM = Xcp_DownloadLength_PGM - (maxCto - (uint16)XCP_PROGRAM_DATA_OFFSET);
        }
        else
        {
            SchM_Enter_Xcp_XCP_EXCLUSIVE_AREA_0();

            for (index = (uint16)0; index < Xcp_DownloadLength_PGM; index++)
            {
                Xcp_BlockBuffer_PGM[Xcp_BlockBufIndex_PGM] = Xcp_RxData[XCP_PACKET_HEADER + (uint16)XCP_PROGRAM_DATA_OFFSET + index];
                Xcp_BlockBufIndex_PGM++;
            }

            SchM_Exit_Xcp_XCP_EXCLUSIVE_AREA_0();

            /* all data received , copy to MTA */
            tem = Xcp_AppProgMemory (XCP_PROGRAM_ADDR_ABS_MODE, Xcp_AddressExtension, Xcp_MTA, Xcp_BlockBufIndex_PGM, Xcp_BlockBuffer_PGM);

            if (XCP_ASYN_JOB_OK == tem)
            {

                Xcp_MTA = Xcp_MTA + Xcp_BlockBufIndex_PGM;
                Xcp_TxData[XCP_PACKET_BYTE0] = XCP_CMD_RES_CODE;
                Xcp_TxPduInfo.SduLength = XCP_NORMAL_POSLEN;
                Xcp_TxPduInfo.SduDataPtr = Xcp_TxData;
            }

#if(STD_ON == XCP_PGM_ASYN_SUPPORT)
            else if (XCP_ASYN_JOB_PENDING == tem)
            {
                respFlag = FALSE;
                Xcp_AsynJob = XCP_PGM_PROG_JOB;
            }

#endif
            else
            {
                /* notok or other invalid return code */
                Xcp_CreatErrResponse (XCP_ERR_ACCESS_DENIED);
            }


            Xcp_DownloadLength_PGM = (uint16)0;
            Xcp_BlockBufIndex_PGM = (uint16)0;

        }
    }

    if (TRUE == respFlag)
    {
        Xcp_Transmit();
    }
}
#endif

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name : Xcp_FuncProgramMax
*
* Description   : Implementation of Xcp_FuncProgramMax command
*
* Inputs        : None

* Outputs       : None
*
* Limitations   : None
********************************************************************************
END_FUNCTION_HDR */
FUNC(void, XCP_CODE) Xcp_FuncProgramMax (void)
{
    const uint16 maxCto = Xcp_TpProConfig[Xcp_ActiveLink.XcpTpHandle].MaxCto;
#if(STD_ON == XCP_CHECKPROGADDR_CBK_SUPPORT)
    uint8 errorcode = XCP_NO_ERR;
#endif
    Std_ReturnType tem;
    uint16 index;
#if(STD_ON == XCP_PGM_ASYN_SUPPORT)
    boolean respFlag = TRUE;
#endif

    const uint16 lengthInBytes = maxCto - (uint16)XCP_AG;


    /*  App need to check MTA is valid or not
        MTA + length is valid or not
        if the target addr is write protected
    */

#if(STD_ON == XCP_CHECKPROGADDR_CBK_SUPPORT)
    tem = Xcp_AppCheckProgAddr (XCP_PROGRAM_ADDR_ABS_MODE, Xcp_AddressExtension, Xcp_MTA, lengthInBytes, &errorcode);

    if (E_OK != tem)
    {
        Xcp_CreatErrResponse (errorcode);
    }
    else
#endif
    {
        /* copy data form rx buffer */
        SchM_Enter_Xcp_XCP_EXCLUSIVE_AREA_0();

        for (index = (uint16)0; index < lengthInBytes; index++)
        {
            Xcp_BlockBuffer_PGM[index] = Xcp_RxData[XCP_PACKET_HEADER + XCP_AG + index];
        }

        SchM_Exit_Xcp_XCP_EXCLUSIVE_AREA_0();

        /* all data received , copy to MTA */
        tem = Xcp_AppProgMemory (XCP_PROGRAM_ADDR_ABS_MODE, Xcp_AddressExtension, Xcp_MTA, lengthInBytes, Xcp_BlockBuffer_PGM);

        if (XCP_ASYN_JOB_OK == tem)
        {
            Xcp_MTA = Xcp_MTA + lengthInBytes;
            Xcp_TxData[XCP_PACKET_BYTE0] = XCP_CMD_RES_CODE;
            Xcp_TxPduInfo.SduLength = XCP_NORMAL_POSLEN;
            Xcp_TxPduInfo.SduDataPtr = Xcp_TxData;
        }

#if(STD_ON == XCP_PGM_ASYN_SUPPORT)
        else if (XCP_ASYN_JOB_PENDING == tem)
        {
            respFlag = FALSE;
            Xcp_AsynJob = XCP_PGM_PROG_JOB;
        }

#endif
        else
        {
            /* notok or other invalid return code */
            Xcp_CreatErrResponse (XCP_ERR_ACCESS_DENIED);
        }
    }

#if(STD_ON == XCP_PGM_ASYN_SUPPORT)

    if (TRUE == respFlag)
#endif
    {
        Xcp_Transmit();
    }
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name : Xcp_FuncProgramFormat
*
* Description   : Implementation of Xcp_FuncProgramFormat command
*
* Inputs        : None

* Outputs       : None
*
* Limitations   : None
********************************************************************************
END_FUNCTION_HDR */
FUNC(void, XCP_CODE) Xcp_FuncProgramFormat (void)
{
    uint8 CompMethod;
    uint8 EncMethod;
    uint8 ProgMethod;
    uint8 AccessMethod;


    SchM_Enter_Xcp_XCP_EXCLUSIVE_AREA_0();
    CompMethod = Xcp_RxData[XCP_PACKET_BYTE1];
    EncMethod = Xcp_RxData[XCP_PACKET_BYTE2];
    ProgMethod = Xcp_RxData[XCP_PACKET_BYTE3];
    AccessMethod = Xcp_RxData[XCP_PACKET_BYTE4];
    SchM_Exit_Xcp_XCP_EXCLUSIVE_AREA_0();

    /*
    dont support extra Compression Encryption Programming method
    only support Absolute Access Mode or Functional Access Mode
    in this version
    */
    if ( ((uint8)0 == CompMethod)
            && ((uint8)0 == EncMethod)
            && ((uint8)0 == ProgMethod)
            && (AccessMethod == XCP_PROGRAM_ADDR_ABS_MODE) )
    {
        Xcp_TxData[XCP_PACKET_BYTE0] = XCP_CMD_RES_CODE;
        Xcp_TxPduInfo.SduLength = XCP_NORMAL_POSLEN;
        Xcp_TxPduInfo.SduDataPtr = Xcp_TxData;
    }
    else
    {
        Xcp_CreatErrResponse (XCP_ERR_OUT_OF_RANGE);
    }

    Xcp_Transmit();

}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name : Xcp_FuncProgramVerify
*
* Description   : Implementation of Xcp_FuncProgramVerify command
*
* Inputs        : None

* Outputs       : None
*
* Limitations   : None
********************************************************************************
END_FUNCTION_HDR */
FUNC(void, XCP_CODE) Xcp_FuncProgramVerify (void)
{
    uint8 VerMode;
    uint16 VerType;
    uint32 VerValue;
#if(STD_ON == XCP_PGM_ASYN_SUPPORT)
    boolean respFlag = TRUE;
#endif
    uint8 tem;

    SchM_Enter_Xcp_XCP_EXCLUSIVE_AREA_0();
    VerMode = Xcp_RxData[XCP_PACKET_BYTE1];
    VerType = Xcp_Make16Bits (Xcp_RxData[XCP_PACKET_BYTE2], Xcp_RxData[XCP_PACKET_BYTE3]);
    VerValue = Xcp_Make32Bits (Xcp_RxData[XCP_PACKET_BYTE4], Xcp_RxData[XCP_PACKET_BYTE5],
                               Xcp_RxData[XCP_PACKET_BYTE6], Xcp_RxData[XCP_PACKET_BYTE7]);
    SchM_Exit_Xcp_XCP_EXCLUSIVE_AREA_0();

    if (VerMode > (uint8)XCP_PROGRAM_VERIFY_VAL_MODE)
    {
        Xcp_CreatErrResponse (XCP_ERR_OUT_OF_RANGE);
    }
    else
    {
        tem = Xcp_AppProgVerify (VerMode, VerType, VerValue);

        if (XCP_ASYN_JOB_OK == tem)
        {
            Xcp_TxData[XCP_PACKET_BYTE0] = XCP_CMD_RES_CODE;
            Xcp_TxPduInfo.SduLength = XCP_NORMAL_POSLEN;
            Xcp_TxPduInfo.SduDataPtr = Xcp_TxData;
        }

#if(STD_ON == XCP_PGM_ASYN_SUPPORT)
        else if (XCP_ASYN_JOB_PENDING == tem)
        {
            respFlag = FALSE;
            Xcp_AsynJob = XCP_PGM_VERIFY_JOB;
        }

#endif
        else
        {
            /* notok or other invalid return code */
            Xcp_CreatErrResponse (XCP_ERR_VERIFY);
        }
    }

#if(STD_ON == XCP_PGM_ASYN_SUPPORT)

    if (TRUE == respFlag)
#endif
    {
        Xcp_Transmit();
    }
}


#define XCP_STOP_SEC_CODE
#include "MemMap.h"

#endif/* #if(STD_ON == XCP_PGM_SUPPORTED) */
