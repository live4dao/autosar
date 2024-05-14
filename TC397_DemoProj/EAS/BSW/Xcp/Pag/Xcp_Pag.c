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
#include "Xcp_Pag.h"

#if(STD_ON == XCP_PAG_SUPPORTED)
/*******************************************************************************
*   Macro
*******************************************************************************/
#define XCP_PAGE_XCP_ACCESS                      ((uint8)0x02U)
#define XCP_PAGE_ECU_ACCESS                      ((uint8)0x01U)
#define XCP_PAGE_XCP_ACCESS_MASK                 ((uint8)0xFDU)
#define XCP_PAGE_ECU_ACCESS_MASK                 ((uint8)0xFEU)

#define XCP_SET_CAL_PAGE_ALL                     ((uint8)0x80U)
#define XCP_SET_CAL_PAGE_ALL_MASK                ((uint8)0x7FU)

#define XCP_SET_CAL_PAGE_ACCESS_MASK             ((uint8)0x03U)

#define XCP_PAGEPRO_ECUACCESS_MASK               ((uint8)0x03U)
#define XCP_PAGEPRO_XCPACCESS_MASK               ((uint8)0x3CU)

#define XCP_GET_CAL_PAGE_POSLEN                  ((PduLengthType)4)

#define XCP_GET_PAG_PROCESSOR_INFO_POSLEN        ((PduLengthType)3)

#define XCP_GET_SEGMENT_INFO_BASIC_SEG_MODE      ((uint8)0)
#define XCP_GET_SEGMENT_INFO_STANDARD_MODE       ((uint8)1)
#define XCP_GET_SEGMENT_INFO_MAP_MODE            ((uint8)2)

#define XCP_GET_SEGMENT_INFO_BASIC_ADDRESS_MODE  ((uint8)0)
#define XCP_GET_SEGMENT_INFO_BASIC_LENGTH_MODE   ((uint8)1)

#define XCP_GET_SEGMENT_INFO_MAP_SRC_MODE        ((uint8)0)
#define XCP_GET_SEGMENT_INFO_MAP_DEST_MODE       ((uint8)1)
#define XCP_GET_SEGMENT_INFO_MAP_LENGTH_MODE     ((uint8)2)

#define XCP_GET_SEGMENT_INFO_POSLEN_8            ((PduLengthType)8)
#define XCP_GET_SEGMENT_INFO_POSLEN_5            ((PduLengthType)6)

#define XCP_GET_PAGE_INFO_POSLEN                 ((PduLengthType)3)

#define XCP_SET_SEGMENT_MODE_FREEZE              ((uint8)1)
#define XCP_SET_SEGMENT_MODE_NOFREEZE            ((uint8)0)

#define XCP_GET_SEGMENT_MODE_POSLEN              ((PduLengthType)3)
/*******************************************************************************
*   local Data Define
*******************************************************************************/
#define XCP_START_SEC_CODE
#include "MemMap.h"

STATIC FUNC(Std_ReturnType, XCP_CODE) Xcp_CheckPageMode
(
    const uint8 mode,
    const uint8 PagePro
);


#define XCP_STOP_SEC_CODE
#include "MemMap.h"



#define XCP_START_SEC_VAR_NOINIT_8
#include "MemMap.h"

/* PAG related */
#if(XCP_MAX_SEGMENT > 0)
/* PageMode XCP access or ECU access */
STATIC VAR (uint8, XCP_VAR_NOINIT) Xcp_PageMode[XCP_MAX_SEGMENT];
/* Current pagenum of each segment */
STATIC VAR (uint8, XCP_VAR_NOINIT) Xcp_ActivedPage[XCP_MAX_SEGMENT];
#if(STD_ON == XCP_PAGE_FREEZE_SUPPORTED)
STATIC VAR (uint8, XCP_VAR_NOINIT) Xcp_FreezeStatus[XCP_MAX_SEGMENT];
#endif
#endif


#define XCP_STOP_SEC_VAR_NOINIT_8
#include "MemMap.h"

/*******************************************************************************
*   Internal Function Define
*******************************************************************************/
#define XCP_START_SEC_CODE
#include "MemMap.h"
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name : Xcp_PagInit
*
* Description   : Init vars used in Pag cmd
*
* Inputs        : None

* Outputs       : None
*
* Limitations   : None
********************************************************************************
END_FUNCTION_HDR */
FUNC(void, XCP_CODE) Xcp_PagInit (void)
{
#if(XCP_MAX_SEGMENT > 0)
    uint8 i;

    for (i = (uint8)0 ; i < (uint8)XCP_MAX_SEGMENT; i++)
    {
#if(STD_ON == XCP_PAGE_FREEZE_SUPPORTED)
        Xcp_FreezeStatus[i] = STD_OFF;
#endif
        Xcp_PageMode[i] = (uint8)0;
        Xcp_ActivedPage[i] = (uint8)0;
    }

#endif
}



/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name : Xcp_CheckPageMode
*
* Description   : Check if page can be set to target mode
*
* Inputs        : mode   :target mode
*               : PagePro: user configed page property
*
* Outputs       : None
*
* Limitations   : None
********************************************************************************
END_FUNCTION_HDR */
STATIC FUNC(Std_ReturnType, XCP_CODE) Xcp_CheckPageMode
(
    const uint8 mode,
    const uint8 PagePro
)
{
    uint8 tempMode = (uint8)0;
    Std_ReturnType ret = E_OK;

    /*
    ECU_ACCESS_WITH_XCP and ECU_ACCESS_WITHOUT_XCP are both 0
    means ECU access is not allowed,
    otherwise ECU access is  allowed
    */
    if ((uint8)0 == (PagePro & XCP_PAGEPRO_ECUACCESS_MASK) )
    {
        tempMode = (tempMode & XCP_PAGE_ECU_ACCESS_MASK);
    }
    else
    {
        tempMode = (tempMode | XCP_PAGE_ECU_ACCESS);
    }


    /*
    XCP_WRITE_ACCESS_WITH_ECU and XCP_WRITE_ACCESS_WITHOUT_ECU are both 0
    XCP_READ_ACCESS_WITH_ECU and XCP_READ_ACCESS_WITHOUT_ECU are both 0
    means XCP access is not allowed,
    otherwise XCP access is allowed
    */
    if ((uint8)0 == (PagePro & XCP_PAGEPRO_XCPACCESS_MASK) )
    {
        tempMode = (tempMode & XCP_PAGE_XCP_ACCESS_MASK);
    }
    else
    {
        tempMode = (tempMode | XCP_PAGE_XCP_ACCESS);
    }

    /*
    E_OK:mode & tempMode
         0x01 & 0x01
         0x02 & 0x02
         0x03 & 0x03
         0x01 & 0x03
         0x02 & 0x03
    */


    if (mode != (mode & tempMode) )
    {
        ret = E_NOT_OK;
    }

    return ret;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name : Xcp_FuncSetCalPage
*
* Description   : Implementation of Xcp_FuncSetCalPage command
*
* Inputs        : None

* Outputs       : None
*
* Limitations   : None
********************************************************************************
END_FUNCTION_HDR */
FUNC(void, XCP_CODE) Xcp_FuncSetCalPage (void)
{
    uint8 mode;
    uint8 segNum;
    uint8 pageNum;
    boolean errflag = FALSE;
    uint8 errorcode = XCP_ERR_GENERIC;

#if(XCP_MAX_SEGMENT > 0)
    uint8 i;
    Std_ReturnType tem;
#endif


    SchM_Enter_Xcp_XCP_EXCLUSIVE_AREA_0();
    mode = Xcp_RxData[XCP_PACKET_BYTE1];
    segNum = Xcp_RxData[XCP_PACKET_BYTE2];
    pageNum = Xcp_RxData[XCP_PACKET_BYTE3];
    SchM_Exit_Xcp_XCP_EXCLUSIVE_AREA_0();

    if ((uint8)0 == (mode & XCP_SET_CAL_PAGE_ACCESS_MASK) )
    {
        /* only 0x01 0x02 0x03 is valid*/
        errorcode = XCP_ERR_MODE_NOT_VALID;
        errflag = TRUE;
    }
    else
    {
        if ((uint8)0 != (mode & XCP_SET_CAL_PAGE_ALL) )
        {
#if(XCP_MAX_SEGMENT > 0)
            /* clear all bit */
            mode = (mode & XCP_SET_CAL_PAGE_ALL_MASK);

            /* all segment opration,need to check page in all segment*/
            for (i = (uint8)0; i < (uint8)XCP_MAX_SEGMENT; i++)
            {
                if (pageNum >= XCP_Info_of_Segment[i].Number_of_Pages)
                {
                    errflag = TRUE;
                    errorcode = XCP_ERR_PAGE_NOT_VALID;
                }
                else
                {
                    tem = Xcp_CheckPageMode (mode, XCP_Info_of_Segment[i].PageInfo[pageNum].Page_Property);

                    if (E_NOT_OK == tem)
                    {
                        errflag = TRUE;
                        errorcode = XCP_ERR_MODE_NOT_VALID;
                    }
                }

                if (TRUE == errflag)
                {
                    break;
                }
            }

            if (FALSE == errflag)
            {
                /* set all segments' mode and active page*/
                for (i = (uint8)0; i < (uint8)XCP_MAX_SEGMENT; i++)
                {
                    /* call back to user to do the  page switch */
#if(STD_ON == XCP_SETPAG_CBK_SUPPORT)
                    Xcp_AppSetCalPage (i, pageNum, mode);
#endif
                    Xcp_PageMode[i] = mode;
                    Xcp_ActivedPage[i] = pageNum;
                }
            }

#else
            errflag = TRUE;
            errorcode = XCP_ERR_SEGMENT_NOT_VALID;
#endif
        }
        else
        {
            if (segNum >= (uint8)XCP_MAX_SEGMENT)
            {
                errflag = TRUE;
                errorcode = XCP_ERR_SEGMENT_NOT_VALID;
            }
            else
            {
                if (pageNum >= XCP_Info_of_Segment[segNum].Number_of_Pages)
                {
                    errflag = TRUE;
                    errorcode = XCP_ERR_PAGE_NOT_VALID;
                }
                else
                {
                    tem = Xcp_CheckPageMode (mode, XCP_Info_of_Segment[segNum].PageInfo[pageNum].Page_Property);

                    if (E_NOT_OK == tem)
                    {
                        errflag = TRUE;
                        errorcode = XCP_ERR_MODE_NOT_VALID;
                    }
                    else
                    {
                        /* call back to user to do the  page switch */
#if(STD_ON == XCP_SETPAG_CBK_SUPPORT)
                        Xcp_AppSetCalPage (segNum, pageNum, mode);
#endif
                        Xcp_PageMode[segNum] = mode;
                        Xcp_ActivedPage[segNum] = pageNum;
                    }
                }
            }
        }
    }

    if (TRUE == errflag)
    {
        Xcp_CreatErrResponse (errorcode);
    }
    else
    {
        Xcp_TxData[XCP_PACKET_BYTE0] = XCP_CMD_RES_CODE;
        Xcp_TxPduInfo.SduLength = XCP_NORMAL_POSLEN;
        Xcp_TxPduInfo.SduDataPtr = Xcp_TxData;
    }

    Xcp_Transmit();
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name : Xcp_FuncGetCalPage
*
* Description   : Implementation of Xcp_FuncGetCalPage command
*
* Inputs        : None

* Outputs       : None
*
* Limitations   : None
********************************************************************************
END_FUNCTION_HDR */
FUNC(void, XCP_CODE) Xcp_FuncGetCalPage (void)
{


    uint8 segNum;
    uint8 mode;

    SchM_Enter_Xcp_XCP_EXCLUSIVE_AREA_0();
    mode = Xcp_RxData[XCP_PACKET_BYTE1];
    segNum = Xcp_RxData[XCP_PACKET_BYTE2];
    SchM_Exit_Xcp_XCP_EXCLUSIVE_AREA_0();


    if ( (mode != XCP_PAGE_XCP_ACCESS) && (mode != XCP_PAGE_ECU_ACCESS) )
    {
        Xcp_CreatErrResponse (XCP_ERR_MODE_NOT_VALID);
    }
    else if (segNum >= (uint8)XCP_MAX_SEGMENT)
    {
        Xcp_CreatErrResponse (XCP_ERR_SEGMENT_NOT_VALID);
    }
    else
    {
#if(XCP_MAX_SEGMENT > 0)

        if ((uint8)0 != (mode & Xcp_PageMode[segNum]) )
        {
            Xcp_TxData[XCP_PACKET_BYTE0] = XCP_CMD_RES_CODE;
            Xcp_TxData[XCP_PACKET_BYTE1] = XCP_RESERVED_BYTE;
            Xcp_TxData[XCP_PACKET_BYTE2] = XCP_RESERVED_BYTE;
            Xcp_TxData[XCP_PACKET_BYTE3] = Xcp_ActivedPage[segNum];
            Xcp_TxPduInfo.SduLength = XCP_GET_CAL_PAGE_POSLEN;
            Xcp_TxPduInfo.SduDataPtr = Xcp_TxData;
        }
        else
        {
            Xcp_CreatErrResponse (XCP_ERR_PAGE_NOT_VALID);
        }

#endif
    }

    Xcp_Transmit();
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name : Xcp_FuncGetPageProcessorInfo
*
* Description   : Implementation of Xcp_FuncGetPageProcessorInfo command
*
* Inputs        : None

* Outputs       : None
*
* Limitations   : None
********************************************************************************
END_FUNCTION_HDR */
FUNC(void, XCP_CODE) Xcp_FuncGetPageProcessorInfo (void)
{



    /* Set response data */
    Xcp_TxData[XCP_PACKET_BYTE0] = XCP_CMD_RES_CODE;
    Xcp_TxData[XCP_PACKET_BYTE1] = (uint8)XCP_MAX_SEGMENT;
    Xcp_TxData[XCP_PACKET_BYTE2] = (uint8)XCP_PAG_PROPERTIES;  /*segments  FREEZE mode*/
    Xcp_TxPduInfo.SduLength = XCP_GET_PAG_PROCESSOR_INFO_POSLEN;
    Xcp_TxPduInfo.SduDataPtr = Xcp_TxData;

    /* Send Positive Response */
    Xcp_Transmit();
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name : Xcp_FuncGetSegmentInfo
*
* Description   : Implementation of Xcp_FuncGetSegmentInfo command
*
* Inputs        : None

* Outputs       : None
*
* Limitations   : None
********************************************************************************
END_FUNCTION_HDR */
FUNC(void, XCP_CODE) Xcp_FuncGetSegmentInfo (void)
{
    uint8 mode;
    uint8 segNum;
    uint8 segInfo;
    uint8 mapIndex;
#if(XCP_MAX_SEGMENT > 0)
    uint32 info;
#endif

    SchM_Enter_Xcp_XCP_EXCLUSIVE_AREA_0();
    mode = Xcp_RxData[XCP_PACKET_BYTE1];
    segNum = Xcp_RxData[XCP_PACKET_BYTE2];
    segInfo = Xcp_RxData[XCP_PACKET_BYTE3];
    mapIndex = Xcp_RxData[XCP_PACKET_BYTE4];
    SchM_Exit_Xcp_XCP_EXCLUSIVE_AREA_0();



    if (mode > XCP_GET_SEGMENT_INFO_MAP_MODE)
    {
        Xcp_CreatErrResponse (XCP_ERR_OUT_OF_RANGE);
    }
    else if (segNum >= (uint8)XCP_MAX_SEGMENT)
    {
        Xcp_CreatErrResponse (XCP_ERR_OUT_OF_RANGE);
    }
    else
    {
#if(XCP_MAX_SEGMENT > 0)

        if (XCP_GET_SEGMENT_INFO_BASIC_SEG_MODE == mode)
        {
            if (segInfo > XCP_GET_SEGMENT_INFO_BASIC_LENGTH_MODE)
            {
                Xcp_CreatErrResponse (XCP_ERR_OUT_OF_RANGE);
            }
            else
            {
                if (XCP_GET_SEGMENT_INFO_BASIC_ADDRESS_MODE == segInfo)
                {
                    /* return segment's start address */
                    info = XCP_Info_of_Segment[segNum].Basic_Address;
                }
                else
                {
                    /* return segment's length */
                    info = XCP_Info_of_Segment[segNum].Segment_Length;
                }

                Xcp_TxData[XCP_PACKET_BYTE0] = XCP_CMD_RES_CODE;
                Xcp_TxData[XCP_PACKET_BYTE1] = XCP_RESERVED_BYTE;
                Xcp_TxData[XCP_PACKET_BYTE2] = XCP_RESERVED_BYTE;
                Xcp_TxData[XCP_PACKET_BYTE3] = XCP_RESERVED_BYTE;
                Xcp_TxData[XCP_PACKET_BYTE4] = Xcp_GetFirstByte (info);
                Xcp_TxData[XCP_PACKET_BYTE5] = Xcp_GetSecondByte (info);
                Xcp_TxData[XCP_PACKET_BYTE6] = Xcp_GetThirdByte (info);
                Xcp_TxData[XCP_PACKET_BYTE7] = Xcp_GetFourthByte (info);
                Xcp_TxPduInfo.SduLength = XCP_GET_SEGMENT_INFO_POSLEN_8;
                Xcp_TxPduInfo.SduDataPtr = Xcp_TxData;
            }
        }
        else if (XCP_GET_SEGMENT_INFO_STANDARD_MODE == mode)
        {
            Xcp_TxData[XCP_PACKET_BYTE0] = XCP_CMD_RES_CODE;
            Xcp_TxData[XCP_PACKET_BYTE1] = XCP_Info_of_Segment[segNum].Number_of_Pages;
            Xcp_TxData[XCP_PACKET_BYTE2] = XCP_Info_of_Segment[segNum].Address_Extension;
            Xcp_TxData[XCP_PACKET_BYTE3] = XCP_Info_of_Segment[segNum].Number_of_Mapping;
            Xcp_TxData[XCP_PACKET_BYTE4] = XCP_Info_of_Segment[segNum].Compression_method;
            Xcp_TxData[XCP_PACKET_BYTE5] = XCP_Info_of_Segment[segNum].Encryption_method;
            Xcp_TxPduInfo.SduLength = XCP_GET_SEGMENT_INFO_POSLEN_5;
            Xcp_TxPduInfo.SduDataPtr = Xcp_TxData;
        }
        else/* XCP_GET_SEGMENT_INFO_MAP_MODE == mode */
        {
            if (segInfo > XCP_GET_SEGMENT_INFO_MAP_LENGTH_MODE)
            {
                Xcp_CreatErrResponse (XCP_ERR_OUT_OF_RANGE);
            }
            else if (mapIndex >= XCP_Info_of_Segment[segNum].Number_of_Mapping)
            {
                Xcp_CreatErrResponse (XCP_ERR_OUT_OF_RANGE);
            }
            else
            {
                if (XCP_GET_SEGMENT_INFO_MAP_SRC_MODE == segInfo)
                {
                    info = XCP_Info_of_Segment[segNum].MapInfo[mapIndex].Source_Address;
                }
                else if (XCP_GET_SEGMENT_INFO_MAP_DEST_MODE == segInfo)
                {
                    info = XCP_Info_of_Segment[segNum].MapInfo[mapIndex].Source_Address +
                           XCP_Info_of_Segment[segNum].MapInfo[mapIndex].Map_Length;
                }
                else /*if(XCP_GET_SEGMENT_INFO_MAP_LENGTH_MODE == segInfo)*/
                {
                    info = XCP_Info_of_Segment[segNum].MapInfo[mapIndex].Map_Length;
                }

                Xcp_TxData[XCP_PACKET_BYTE0] = XCP_CMD_RES_CODE;
                Xcp_TxData[XCP_PACKET_BYTE1] = XCP_RESERVED_BYTE;
                Xcp_TxData[XCP_PACKET_BYTE2] = XCP_RESERVED_BYTE;
                Xcp_TxData[XCP_PACKET_BYTE3] = XCP_RESERVED_BYTE;
                Xcp_TxData[XCP_PACKET_BYTE4] = Xcp_GetFirstByte (info);
                Xcp_TxData[XCP_PACKET_BYTE5] = Xcp_GetSecondByte (info);
                Xcp_TxData[XCP_PACKET_BYTE6] = Xcp_GetThirdByte (info);
                Xcp_TxData[XCP_PACKET_BYTE7] = Xcp_GetFourthByte (info);
                Xcp_TxPduInfo.SduLength = XCP_GET_SEGMENT_INFO_POSLEN_8;
                Xcp_TxPduInfo.SduDataPtr = Xcp_TxData;
            }
        }

#endif
    }

    Xcp_Transmit();

}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name : Xcp_FuncGetPageInfo
*
* Description   : Implementation of Xcp_FuncGetPageInfo command
*
* Inputs        : None

* Outputs       : None
*
* Limitations   : None
********************************************************************************
END_FUNCTION_HDR */
FUNC(void, XCP_CODE) Xcp_FuncGetPageInfo (void)
{
    uint8 segNum;
    uint8 pageNum;

    SchM_Enter_Xcp_XCP_EXCLUSIVE_AREA_0();
    segNum = Xcp_RxData[XCP_PACKET_BYTE2];
    pageNum = Xcp_RxData[XCP_PACKET_BYTE3];
    SchM_Exit_Xcp_XCP_EXCLUSIVE_AREA_0();

    if (segNum >= XCP_MAX_SEGMENT)
    {
        Xcp_CreatErrResponse (XCP_ERR_OUT_OF_RANGE);
    }
    else
    {
#if(XCP_MAX_SEGMENT > 0)

        if (pageNum >= XCP_Info_of_Segment[segNum].Number_of_Pages)
        {
            Xcp_CreatErrResponse (XCP_ERR_OUT_OF_RANGE);
        }
        else
        {
            Xcp_TxData[XCP_PACKET_BYTE0] = XCP_CMD_RES_CODE;
            Xcp_TxData[XCP_PACKET_BYTE1] = XCP_Info_of_Segment[segNum].PageInfo[pageNum].Page_Property;
            Xcp_TxData[XCP_PACKET_BYTE2] = XCP_Info_of_Segment[segNum].PageInfo[pageNum].Init_Segment;
            Xcp_TxPduInfo.SduLength = XCP_GET_PAGE_INFO_POSLEN;
            Xcp_TxPduInfo.SduDataPtr = Xcp_TxData;
        }

#endif
    }

    Xcp_Transmit();
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name : Xcp_FuncSetSegmentMode
*
* Description   : Implementation of Xcp_FuncSetSegmentMode command
*
* Inputs        : None

* Outputs       : None
*
* Limitations   : None
********************************************************************************
END_FUNCTION_HDR */
FUNC(void, XCP_CODE) Xcp_FuncSetSegmentMode (void)
{
    uint8 segNum;
    uint8 mode;

    SchM_Enter_Xcp_XCP_EXCLUSIVE_AREA_0();
    mode = Xcp_RxData[XCP_PACKET_BYTE1];
    segNum = Xcp_RxData[XCP_PACKET_BYTE2];
    SchM_Exit_Xcp_XCP_EXCLUSIVE_AREA_0();

    if (mode > XCP_SET_SEGMENT_MODE_FREEZE)
    {
        Xcp_CreatErrResponse (XCP_ERR_OUT_OF_RANGE);
    }
    else if (segNum >= (uint8)XCP_MAX_SEGMENT)
    {
        Xcp_CreatErrResponse (XCP_ERR_OUT_OF_RANGE);
    }
    else
    {
#if(XCP_MAX_SEGMENT > 0)
#if(STD_OFF == XCP_PAGE_FREEZE_SUPPORTED)

        if (mode == XCP_SET_SEGMENT_MODE_FREEZE)
        {
            Xcp_CreatErrResponse (XCP_ERR_MODE_NOT_VALID);
        }
        else
#endif
        {
#if(STD_ON == XCP_PAGE_FREEZE_SUPPORTED)
            Xcp_FreezeStatus[segNum] = mode;
#endif
            Xcp_TxData[XCP_PACKET_BYTE0] = XCP_CMD_RES_CODE;
            Xcp_TxPduInfo.SduLength = XCP_NORMAL_POSLEN;
            Xcp_TxPduInfo.SduDataPtr = Xcp_TxData;
        }

#endif
    }

    Xcp_Transmit();

}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name : Xcp_FuncGetSegmentMode
*
* Description   : Implementation of Xcp_FuncGetSegmentMode command
*
* Inputs        : None

* Outputs       : None
*
* Limitations   : None
********************************************************************************
END_FUNCTION_HDR */
FUNC(void, XCP_CODE) Xcp_FuncGetSegmentMode (void)
{
    uint8 segNum;

    SchM_Enter_Xcp_XCP_EXCLUSIVE_AREA_0();
    segNum = Xcp_RxData[XCP_PACKET_BYTE2];
    SchM_Exit_Xcp_XCP_EXCLUSIVE_AREA_0();

    if (segNum >= (uint8)XCP_MAX_SEGMENT)
    {
        Xcp_CreatErrResponse (XCP_ERR_OUT_OF_RANGE);
    }
    else
    {
#if(XCP_MAX_SEGMENT > 0)
        Xcp_TxData[XCP_PACKET_BYTE0] = XCP_CMD_RES_CODE;
        Xcp_TxData[XCP_PACKET_BYTE1] = XCP_RESERVED_BYTE;
#if(STD_ON == XCP_PAGE_FREEZE_SUPPORTED)
        Xcp_TxData[XCP_PACKET_BYTE2] = Xcp_FreezeStatus[segNum];
#else
        Xcp_TxData[XCP_PACKET_BYTE2] = (uint8)0;
#endif
        Xcp_TxPduInfo.SduLength = XCP_GET_SEGMENT_MODE_POSLEN;
        Xcp_TxPduInfo.SduDataPtr = Xcp_TxData;
#endif
    }

    Xcp_Transmit();

}

#if(STD_ON == XCP_COPYPAG_SUPPORT)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name : Xcp_FuncCopyCalPage
*
* Description   : Implementation of Xcp_FuncCopyCalPage command
*
* Inputs        : None

* Outputs       : None
*
* Limitations   : Only ram pages can copy fron each other
********************************************************************************
END_FUNCTION_HDR */
FUNC(void, XCP_CODE) Xcp_FuncCopyCalPage (void)
{
    uint8 Source_Segment;
    uint8 Source_Page;
    uint8 Destination_Segment;
    uint8 Destination_Page;
    Std_ReturnType result;
#if(STD_ON == XCP_COPYPAG_ASYN_SUPPORT)
    boolean respFlag = TRUE;
#endif
    uint8 errcode;


    SchM_Enter_Xcp_XCP_EXCLUSIVE_AREA_0();
    Source_Segment = Xcp_RxData[XCP_PACKET_BYTE1];
    Source_Page = Xcp_RxData[XCP_PACKET_BYTE2];
    Destination_Segment = Xcp_RxData[XCP_PACKET_BYTE3];
    Destination_Page = Xcp_RxData[XCP_PACKET_BYTE4];
    SchM_Exit_Xcp_XCP_EXCLUSIVE_AREA_0();

    if ( (Source_Segment >= XCP_MAX_SEGMENT) || (Destination_Segment >= XCP_MAX_SEGMENT) )
    {
        Xcp_CreatErrResponse (XCP_ERR_SEGMENT_NOT_VALID);
    }
    else
    {
#if(XCP_MAX_SEGMENT > 0)

        if ( (Source_Page >= XCP_Info_of_Segment[Source_Segment].Number_of_Pages) ||
                (Destination_Page >= XCP_Info_of_Segment[Destination_Segment].Number_of_Pages) )
        {
            Xcp_CreatErrResponse (XCP_ERR_PAGE_NOT_VALID);
        }
        else
        {
            /* Copy Page */
            result = Xcp_AppCopyCalPage (Source_Segment, Source_Page, Destination_Segment, Destination_Page, &errcode);

            if (XCP_ASYN_JOB_OK == result)
            {
                /* Send Positive Response */
                Xcp_TxData[XCP_PACKET_BYTE0] = XCP_CMD_RES_CODE;
                Xcp_TxPduInfo.SduLength = XCP_NORMAL_POSLEN;
                Xcp_TxPduInfo.SduDataPtr = Xcp_TxData;
            }

#if(STD_ON == XCP_COPYPAG_ASYN_SUPPORT)
            else if (XCP_ASYN_JOB_PENDING == result)
            {
                respFlag = FALSE;
                Xcp_AsynJob = XCP_COPYPAGE_JOB;
            }

#endif
            else
            {
                Xcp_CreatErrResponse (errcode);
            }
        }

#endif
    }

#if(STD_ON == XCP_COPYPAG_ASYN_SUPPORT)

    if (TRUE == respFlag)
#endif
    {
        Xcp_Transmit();
    }


}
#endif


#define XCP_STOP_SEC_CODE
#include "MemMap.h"
#endif  /*#if(STD_ON == XCP_PAG_SUPPORTED)*/

