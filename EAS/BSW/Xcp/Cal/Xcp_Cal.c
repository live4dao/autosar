/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
*   File Name       : Xcp_Cal.c
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
#include "Xcp_Cal.h"

#if(STD_ON == XCP_CAL_SUPPORTED)
/*******************************************************************************
*   Macro
*******************************************************************************/
#if(STD_ON == XCP_MASTER_BLOCK_MODE_SUPPORT)
#define XCP_DOWNLOADNEXT_NAGRES_LEN   ((PduLengthType)3)
#endif

#define XCP_DOWNLOADMAX_POSRES_LEN    ((PduLengthType)1)
#define XCP_DOWNLOAD_SHORT_OFFSET     ((uint16)8)

#if(STD_ON == XCP_MODIFYBITS_SUPPORT)
#define XCP_MODIFY_BYTES              (4)
#endif

/*******************************************************************************
*   local Data Define
*******************************************************************************/
#define XCP_START_SEC_CODE
#include "MemMap.h"


#define XCP_STOP_SEC_CODE
#include "MemMap.h"


#if(STD_ON == XCP_MASTER_BLOCK_MODE_SUPPORT)
#define XCP_START_SEC_VAR_NOINIT_8
#include "MemMap.h"
STATIC VAR (uint8, XCP_VAR_NOINIT) Xcp_BlockBuffer[XCP_MASTER_BLOCK_BUFFER_SIZE];
#define XCP_STOP_SEC_VAR_NOINIT_8
#include "MemMap.h"


#define XCP_START_SEC_VAR_NOINIT_16
#include "MemMap.h"
STATIC VAR (uint16, XCP_VAR_NOINIT) Xcp_DownloadLength;
STATIC VAR (uint16, XCP_VAR_NOINIT) Xcp_BlockBufIndex;
#define XCP_STOP_SEC_VAR_NOINIT_16
#include "MemMap.h"
#endif
/*******************************************************************************
*   Internal Function Define
*******************************************************************************/
#define XCP_START_SEC_CODE
#include "MemMap.h"

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name : Xcp_CalInit
*
* Description   : Init vars used in Cal cmd
*
* Inputs        : None

* Outputs       : None
*
* Limitations   : None
********************************************************************************
END_FUNCTION_HDR */
FUNC(void, XCP_CODE) Xcp_CalInit (void)
{
#if(STD_ON == XCP_MASTER_BLOCK_MODE_SUPPORT)
    uint16 bufferIndex;

    Xcp_DownloadLength = (uint16)0;
    Xcp_BlockBufIndex = (uint16)0;

    for (bufferIndex = (uint16)0 ; bufferIndex < XCP_MASTER_BLOCK_BUFFER_SIZE; bufferIndex++)
    {
        Xcp_BlockBuffer[bufferIndex] = (uint8)0;
    }

#endif
}


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name : Xcp_FuncDownload
*
* Description   : Implementation of Xcp_FuncDownload command
*
* Inputs        : None

* Outputs       : None
*
* Limitations   : None
********************************************************************************
END_FUNCTION_HDR */
FUNC(void, XCP_CODE) Xcp_FuncDownload (void)
{
    uint8 NumOfElement;
#if(STD_ON == XCP_CHECK_WRITEMTA_CBK_SUPPORT)
    Std_ReturnType tem;
    uint8 errorcode = XCP_NO_ERR;    
#endif
    uint16 lengthInBytes;
    const uint16 maxCto = Xcp_TpProConfig[Xcp_ActiveLink.XcpTpHandle].MaxCto;
#if((STD_OFF == XCP_SPECIAL_ACCESS_RAM) || (STD_ON == XCP_MASTER_BLOCK_MODE_SUPPORT))
    uint16 index;
#endif
#if(STD_ON == XCP_MASTER_BLOCK_MODE_SUPPORT)
    boolean respFlag = TRUE;
#endif


    SchM_Enter_Xcp_XCP_EXCLUSIVE_AREA_0();
    NumOfElement = Xcp_RxData[XCP_PACKET_BYTE1];
    SchM_Exit_Xcp_XCP_EXCLUSIVE_AREA_0();

    lengthInBytes = NumOfElement;
#if(XCP_AG > 1)
    lengthInBytes = lengthInBytes * (uint16)XCP_AG;
#endif


    if ((uint8)0 == NumOfElement)
    {
        Xcp_CreatErrResponse (XCP_ERR_OUT_OF_RANGE);
    }

#if(STD_OFF == XCP_MASTER_BLOCK_MODE_SUPPORT)
    /* when no master block , num can not bigger than CTO*/
    else if ( (lengthInBytes + XCP_DOWNLOAD_DATA_OFFSET) > maxCto)
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
    else if (lengthInBytes > XCP_MASTER_BLOCK_BUFFER_SIZE)
    {
        /* numElement = MAXDTO/AG - 1*/
        Xcp_CreatErrResponse (XCP_ERR_OUT_OF_RANGE);
    }

#endif
    else
    {
        /*  App need to check MTA is valid or not
            MTA + length is valid or not
            if the target addr is write protected
        */
#if(STD_ON == XCP_CHECK_WRITEMTA_CBK_SUPPORT)
        tem = Xcp_AppCheckWriteAddr (Xcp_MTA, Xcp_AddressExtension, lengthInBytes, &errorcode);

        if (E_OK != tem)
        {
            Xcp_CreatErrResponse (errorcode);
        }
        else
#endif
        {
#if(STD_ON == XCP_MASTER_BLOCK_MODE_SUPPORT)

            if ( (lengthInBytes + XCP_DOWNLOAD_DATA_OFFSET) > maxCto)
            {
                respFlag = FALSE;

                for (index = (uint16)0; index < (maxCto - XCP_DOWNLOAD_DATA_OFFSET); index++)
                {
                    Xcp_BlockBuffer[Xcp_BlockBufIndex] = Xcp_RxData[XCP_PACKET_HEADER + XCP_DOWNLOAD_DATA_OFFSET + index];
                    Xcp_BlockBufIndex++;
                    /* dont add mta here ,in block mode , only when all bytes received
                       copy to mta
                    */
                }

                Xcp_DownloadLength = lengthInBytes - (maxCto - XCP_DOWNLOAD_DATA_OFFSET);
            }
            else
#endif
            {

                SchM_Enter_Xcp_XCP_EXCLUSIVE_AREA_1();
#if(STD_ON == XCP_SPECIAL_ACCESS_RAM)
                Xcp_App_WriteRam (Xcp_MTA, lengthInBytes, &Xcp_RxData[XCP_PACKET_HEADER + XCP_DOWNLOAD_DATA_OFFSET]);
                Xcp_MTA = Xcp_MTA + lengthInBytes;
#else

                for (index = (uint16)0; index < lengthInBytes; index++)
                {
                    * (uint8 *) (Xcp_MTA) = Xcp_RxData[XCP_PACKET_HEADER + XCP_DOWNLOAD_DATA_OFFSET + index];
                    Xcp_MTA++;
                }

#endif
                SchM_Exit_Xcp_XCP_EXCLUSIVE_AREA_1();
                Xcp_TxData[XCP_PACKET_BYTE0] = XCP_CMD_RES_CODE;
                Xcp_TxPduInfo.SduLength = XCP_NORMAL_POSLEN;
                Xcp_TxPduInfo.SduDataPtr = Xcp_TxData;
            }
        }

    }

#if(STD_ON == XCP_MASTER_BLOCK_MODE_SUPPORT)

    if (TRUE == respFlag)
#endif
    {
        Xcp_Transmit();
    }
}

#if(STD_ON == XCP_MASTER_BLOCK_MODE_SUPPORT)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name : Xcp_FuncDownloadNext
*
* Description   : Implementation of Xcp_FuncDownloadNext command
*
* Inputs        : None

* Outputs       : None
*
* Limitations   : None
********************************************************************************
END_FUNCTION_HDR */
FUNC(void, XCP_CODE) Xcp_FuncDownloadNext (void)
{
    uint8 NumOfElement;
    uint16 lengthInBytes;
    const uint16 maxCto = Xcp_TpProConfig[Xcp_ActiveLink.XcpTpHandle].MaxCto;
    uint16 index;
    boolean respFlag = TRUE;


    SchM_Enter_Xcp_XCP_EXCLUSIVE_AREA_0();
    NumOfElement = Xcp_RxData[XCP_PACKET_BYTE1];
    SchM_Exit_Xcp_XCP_EXCLUSIVE_AREA_0();

    lengthInBytes = NumOfElement;
#if(XCP_AG > 1)
    lengthInBytes = lengthInBytes * XCP_AG;
#endif

    if ( ((uint16)0 == Xcp_DownloadLength) || (Xcp_DownloadLength != lengthInBytes) )
    {
        /* not waiting download next*/
        /* need to report remain length of download */
        Xcp_TxData[XCP_PACKET_BYTE0] = XCP_CMD_ERROR_CODE;
        Xcp_TxData[XCP_PACKET_BYTE1] = XCP_ERR_SEQUENCE;
#if(XCP_AG > 1)
        Xcp_TxData[XCP_PACKET_BYTE2] = (uint8) Xcp_DownloadLength / XCP_AG;
#else
        Xcp_TxData[XCP_PACKET_BYTE2] = (uint8) Xcp_DownloadLength;
#endif
        Xcp_TxPduInfo.SduLength = XCP_DOWNLOADNEXT_NAGRES_LEN;
        Xcp_TxPduInfo.SduDataPtr = Xcp_TxData;
        Xcp_DownloadLength = (uint16)0;
        Xcp_BlockBufIndex = (uint16)0;
    }
    else
    {
        if ( (Xcp_DownloadLength + XCP_DOWNLOAD_DATA_OFFSET) > maxCto)
        {
            respFlag = FALSE;

            for (index = (uint16)0; index < (maxCto - XCP_DOWNLOAD_DATA_OFFSET); index++)
            {
                Xcp_BlockBuffer[Xcp_BlockBufIndex] = Xcp_RxData[XCP_PACKET_HEADER + XCP_DOWNLOAD_DATA_OFFSET + index];
                Xcp_BlockBufIndex++;
                /* dont add mta here ,in block mode , only when all bytes received
                   copy to mta
                */
            }

            Xcp_DownloadLength = Xcp_DownloadLength - (maxCto - XCP_DOWNLOAD_DATA_OFFSET);
        }
        else
        {
            for (index = (uint16)0; index < Xcp_DownloadLength; index++)
            {
                Xcp_BlockBuffer[Xcp_BlockBufIndex] = Xcp_RxData[XCP_PACKET_HEADER + XCP_DOWNLOAD_DATA_OFFSET + index];
                Xcp_BlockBufIndex++;
            }

            SchM_Enter_Xcp_XCP_EXCLUSIVE_AREA_1();
#if(STD_ON == XCP_SPECIAL_ACCESS_RAM)
            Xcp_App_WriteRam (Xcp_MTA, Xcp_BlockBufIndex, Xcp_BlockBuffer);
            Xcp_MTA = Xcp_MTA + Xcp_BlockBufIndex;
#else

            /* all data received , copy to MTA */
            for (index = (uint16)0; index < Xcp_BlockBufIndex; index++)
            {
                * (uint8 *) (Xcp_MTA) = Xcp_BlockBuffer[index];
                Xcp_MTA++;
            }

#endif
            SchM_Exit_Xcp_XCP_EXCLUSIVE_AREA_1();

            Xcp_DownloadLength = (uint16)0;
            Xcp_BlockBufIndex = (uint16)0;

            Xcp_TxData[XCP_PACKET_BYTE0] = XCP_CMD_RES_CODE;
            Xcp_TxPduInfo.SduLength = XCP_NORMAL_POSLEN;
            Xcp_TxPduInfo.SduDataPtr = Xcp_TxData;
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
* Function Name : Xcp_FuncDownloadMax
*
* Description   : Implementation of Xcp_FuncDownloadMax command
*
* Inputs        : None

* Outputs       : None
*
* Limitations   : None
********************************************************************************
END_FUNCTION_HDR */
FUNC(void, XCP_CODE) Xcp_FuncDownloadMax (void)
{
    const uint16 maxCto = Xcp_TpProConfig[Xcp_ActiveLink.XcpTpHandle].MaxCto;
#if(STD_ON == XCP_CHECK_WRITEMTA_CBK_SUPPORT)
    Std_ReturnType tem;
    uint8 errorcode = XCP_NO_ERR;
#endif
#if(STD_OFF == XCP_SPECIAL_ACCESS_RAM)
    uint16 index;
#endif

    const uint16 lengthInBytes = maxCto - (uint16)XCP_AG;


    /*  App need to check MTA is valid or not
        MTA + length is valid or not
        if the target addr is write protected
    */

#if(STD_ON == XCP_CHECK_WRITEMTA_CBK_SUPPORT)
    tem = Xcp_AppCheckWriteAddr (Xcp_MTA, Xcp_AddressExtension, lengthInBytes, &errorcode);

    if (E_OK != tem)
    {
        Xcp_CreatErrResponse (errorcode);
    }
    else
#endif
    {
#if(STD_ON == XCP_SPECIAL_ACCESS_RAM)
        Xcp_App_WriteRam (Xcp_MTA, lengthInBytes, &Xcp_RxData[XCP_PACKET_HEADER + XCP_AG ]);
        Xcp_MTA = Xcp_MTA + lengthInBytes;
#else
        SchM_Enter_Xcp_XCP_EXCLUSIVE_AREA_1();

        for (index = (uint16)0; index < lengthInBytes; index++)
        {
            * (uint8 *) (Xcp_MTA)= Xcp_RxData[XCP_PACKET_HEADER + XCP_AG + index];
            Xcp_MTA++;
        }

        SchM_Exit_Xcp_XCP_EXCLUSIVE_AREA_1();
#endif

        Xcp_TxData[XCP_PACKET_BYTE0] = XCP_CMD_RES_CODE;
        Xcp_TxPduInfo.SduLength = XCP_DOWNLOADMAX_POSRES_LEN;
        Xcp_TxPduInfo.SduDataPtr = Xcp_TxData;
    }

    Xcp_Transmit();

}


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name : Xcp_FuncShortDownload
*
* Description   : Implementation of Xcp_FuncShortDownload command
*
* Inputs        : None

* Outputs       : None
*
* Limitations   : None
********************************************************************************
END_FUNCTION_HDR */
FUNC(void, XCP_CODE) Xcp_FuncShortDownload (void)
{
    uint8 NumOfElement;
#if(STD_ON == XCP_CHECK_WRITEMTA_CBK_SUPPORT)
    Std_ReturnType tem;
    uint8 errorcode = XCP_NO_ERR;
#endif
    uint16 lengthInBytes;
    const uint16 maxCto = Xcp_TpProConfig[Xcp_ActiveLink.XcpTpHandle].MaxCto;
#if(STD_OFF == XCP_SPECIAL_ACCESS_RAM)
    uint16 index;
#endif
    uint32 tempMTA;
    uint8 tempAddrExt;

    SchM_Enter_Xcp_XCP_EXCLUSIVE_AREA_0();
    tempMTA = Xcp_Make32Bits (Xcp_RxData[XCP_PACKET_BYTE4], Xcp_RxData[XCP_PACKET_BYTE5],
                              Xcp_RxData[XCP_PACKET_BYTE6], Xcp_RxData[XCP_PACKET_BYTE7]);
    tempAddrExt = Xcp_RxData[XCP_PACKET_BYTE3];
    NumOfElement = Xcp_RxData[XCP_PACKET_BYTE1];
    SchM_Exit_Xcp_XCP_EXCLUSIVE_AREA_0();

    /* caculate data size from element AG to bytes */
    lengthInBytes = NumOfElement;
#if(XCP_AG > 1)
    lengthInBytes = lengthInBytes * XCP_AG;
#endif

    if ( (lengthInBytes + (uint16)XCP_AG) > maxCto)
    {
        Xcp_CreatErrResponse (XCP_ERR_OUT_OF_RANGE);
    }
    else
    {
        /*  App need to check MTA is valid or not
            MTA + length is valid or not
            if the target addr is write protected
        */
#if(STD_ON == XCP_CHECK_WRITEMTA_CBK_SUPPORT)
        tem = Xcp_AppCheckWriteAddr (Xcp_MTA, Xcp_AddressExtension, lengthInBytes, &errorcode);

        if (E_OK != tem)
        {
            Xcp_CreatErrResponse (errorcode);
        }
        else
#endif
        {
            Xcp_MTA = tempMTA;
            Xcp_AddressExtension = tempAddrExt;

            SchM_Enter_Xcp_XCP_EXCLUSIVE_AREA_1();
#if(STD_ON == XCP_SPECIAL_ACCESS_RAM)
            Xcp_App_WriteRam (Xcp_MTA, lengthInBytes, &Xcp_RxData[XCP_PACKET_HEADER + XCP_DOWNLOAD_SHORT_OFFSET]);
            Xcp_MTA = Xcp_MTA + lengthInBytes;
#else

            for (index = (uint16)0; index < lengthInBytes; index++)
            {
                * (uint8 *) (Xcp_MTA) = Xcp_RxData[XCP_PACKET_HEADER + XCP_DOWNLOAD_SHORT_OFFSET + index];
                Xcp_MTA++;
            }

#endif
            SchM_Exit_Xcp_XCP_EXCLUSIVE_AREA_1();

            Xcp_TxData[XCP_PACKET_BYTE0] = XCP_CMD_RES_CODE;
            Xcp_TxPduInfo.SduLength = XCP_NORMAL_POSLEN;
            Xcp_TxPduInfo.SduDataPtr = Xcp_TxData;
        }
    }

    Xcp_Transmit();

}

#if(STD_ON == XCP_MODIFYBITS_SUPPORT)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name : Xcp_FuncModifyBits
*
* Description   : Implementation of Xcp_FuncModifyBits command
*
* Inputs        : None

* Outputs       : None
*
* Limitations   : None
********************************************************************************
END_FUNCTION_HDR */
FUNC(void, XCP_CODE) Xcp_FuncModifyBits (void)
{
    uint32 value;
    uint32 MA;
    uint32 MX;
    uint8  tempS;
#if(STD_ON == XCP_CHECK_WRITEMTA_CBK_SUPPORT)
    Std_ReturnType tem;
#endif
    uint8 errorcode = XCP_NO_ERR;


    /*  App need to check MTA is valid or not
        MTA + length is valid or not
        if the target addr is write protected
    */
#if(STD_ON == XCP_CHECK_WRITEMTA_CBK_SUPPORT)
    tem = Xcp_AppCheckWriteAddr (Xcp_MTA, Xcp_AddressExtension, XCP_MODIFY_BYTES, &errorcode);

    if (E_OK != tem)
    {
        Xcp_CreatErrResponse (errorcode);
    }
    else
#endif
    {
        SchM_Enter_Xcp_XCP_EXCLUSIVE_AREA_0();
        tempS = Xcp_RxData[XCP_PACKET_BYTE1];
        MA = Xcp_Make16Bits (Xcp_RxData[XCP_PACKET_BYTE2], Xcp_RxData[XCP_PACKET_BYTE3]);
        MX = Xcp_Make16Bits (Xcp_RxData[XCP_PACKET_BYTE4], Xcp_RxData[XCP_PACKET_BYTE5]);
        SchM_Exit_Xcp_XCP_EXCLUSIVE_AREA_0();

        SchM_Enter_Xcp_XCP_EXCLUSIVE_AREA_1();
#if(STD_ON == XCP_SPECIAL_ACCESS_RAM)
        Xcp_App_Read32BitData (Xcp_MTA, &value);
#else

        value = * (uint32 *) Xcp_MTA;
#endif
        /* xcp standard modify bits formula */
        /*value = (value & (~(((uint32)(~MA)) << tempS)) ^ (((uint32)MX) << tempS));*/


        MX = MX << tempS;
        MA = (uint16) (~MA);
        MA = MA << tempS;
        MA = ~MA;
        value = ( (value & MA) ^ MX);

#if(STD_ON == XCP_SPECIAL_ACCESS_RAM)
        Xcp_App_Write32BitData (Xcp_MTA, value);
#else
        * (uint32 *) Xcp_MTA = value;
#endif
        SchM_Exit_Xcp_XCP_EXCLUSIVE_AREA_1();

        Xcp_TxData[XCP_PACKET_BYTE0] = XCP_CMD_RES_CODE;
        Xcp_TxPduInfo.SduLength = XCP_NORMAL_POSLEN;
        Xcp_TxPduInfo.SduDataPtr = Xcp_TxData;
    }

    Xcp_Transmit();
}
#endif

#define XCP_STOP_SEC_CODE
#include "MemMap.h"

#endif/*#if(STD_ON == XCP_CAL_SUPPORTED)*/
