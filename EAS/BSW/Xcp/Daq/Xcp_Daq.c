/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
*   File Name       : Xcp_Daq.c
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
#include "Xcp_Daq.h"

#if(STD_ON == XCP_DAQ_SUPPORTED)
/*******************************************************************************
*   Macro
*******************************************************************************/
#define XCP_GET_DAQ_LIST_MODE_POS_LEN       ((PduLengthType)8)
#define XCP_START_STOP_DAQ_LIST_POS_LEN     ((PduLengthType)2)
#define XCP_START_STOP_DAQ_LIST_STOP        ((uint8)0)
#define XCP_START_STOP_DAQ_LIST_START       ((uint8)1)
#define XCP_START_STOP_DAQ_LIST_SEL         ((uint8)2)
#define XCP_START_STOP_SYNCH_STOPALL        ((uint8)0)
#define XCP_START_STOP_SYNCH_START          ((uint8)1)
#define XCP_START_STOP_SYNCH_STOP           ((uint8)2)
#define XCP_GET_DAQ_CLOCK_POS_LEN           ((PduLengthType)8)
#define XCP_READ_DAQ_POS_LEN                ((PduLengthType)8)
#define XCP_GET_DAQ_PROCESSOR_INFO_POS_LEN  ((PduLengthType)8)
#define XCP_GET_DAQ_RESOLUTION_INFO_POS_LEN ((PduLengthType)8)
#define XCP_GET_DAQ_LIST_INFO_POS_LEN       ((PduLengthType)6)
#define XCP_GET_DAQ_EVENT_INFO_POS_LEN      ((PduLengthType)7)
#define XCP_TIME_UINT_1MS                   ((uint8)0x06U)
#if(STD_ON == XCP_BITOFFSET_SUPPORT)
#define XCP_BITOFFSET_DIVISOR               ((uint8)8)
#define XCP_BITOFFSET_SHIFTER               ((uint8)3)
#define XCP_BITOFFSET_MAXINDEX              ((uint8)3)
#endif

/*******************************************************************************
*   local Data Define
*******************************************************************************/
#define XCP_START_SEC_CODE
#include "MemMap.h"
STATIC FUNC(void, XCP_CODE) Xcp_InitDaq
(
    const uint16 daqIndex
);

STATIC FUNC(void, XCP_CODE) Xcp_InitAllDaq
(
    void
);
STATIC FUNC(void, XCP_CODE) Xcp_TransmitDAQ
(
    void
);
STATIC FUNC(void, XCP_CODE) Xcp_CheckAndStopDaq
(
    void
);


STATIC FUNC(boolean, XCP_CODE) Xcp_CopyODTData
(
    const uint16 daqIndex,
    const uint8 odtIndex
);

STATIC  FUNC(boolean, XCP_CODE) Xcp_SearchAndTransmitNextODT
(
    void
);

#define XCP_STOP_SEC_CODE
#include "MemMap.h"



#define XCP_START_SEC_VAR_NOINIT_8
#include "MemMap.h"
STATIC VAR (uint8, XCP_VAR_NOINIT) Xcp_DaqTxData[XCP_TX_BUFFER_SIZE];

#if(XCP_MAX_DAQ > 0)
STATIC VAR (Xcp_Daq_Mode_Type, XCP_VAR_NOINIT)   Xcp_Daq_Mode[XCP_MAX_DAQ];

#if(STD_ON == XCP_PRESCALER_SUPPORTED)
STATIC VAR (uint8, XCP_VAR_NOINIT)  Xcp_Daq_Prescale[XCP_MAX_DAQ];
#endif

#if(STD_ON == XCP_DAQ_PRIORITY_SUPPORTED)
STATIC VAR (uint8, XCP_VAR_NOINIT)  Xcp_Daq_Priority[XCP_MAX_DAQ];
#endif

STATIC VAR (uint8, XCP_VAR_NOINIT)  Xcp_SavedOdtIndex[XCP_MAX_DAQ] ;
STATIC VAR (Xcp_DaqSubState_Type, XCP_VAR_NOINIT)  Xcp_DaqSubState[XCP_MAX_DAQ];

#endif

STATIC VAR (boolean, XCP_VAR_NOINIT)  Xcp_DaqTxFlag;
#define XCP_STOP_SEC_VAR_NOINIT_8
#include "MemMap.h"

#define XCP_START_SEC_VAR_NOINIT_16
#include "MemMap.h"
STATIC VAR (uint16, XCP_VAR_NOINIT)  Xcp_CurrentDaqIndex;
#if(XCP_MAX_EVENT_CHANNEL > 0)
STATIC VAR (uint16, XCP_VAR_NOINIT) Xcp_EventCnt[XCP_MAX_EVENT_CHANNEL];
#endif
#define XCP_STOP_SEC_VAR_NOINIT_16
#include "MemMap.h"


#define XCP_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"

STATIC VAR (PduInfoType, XCP_VAR_NOINIT) Xcp_DaqTxPduInfo;
STATIC VAR (Xcp_DAQ_Ptr_Type, XCP_VAR_NOINIT) Xcp_DaqPointer;

#define XCP_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"

/*******************************************************************************
*   Internal Function Define
*******************************************************************************/
#define XCP_START_SEC_CODE
#include "MemMap.h"



/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name : Xcp_InitDaq
*
* Description   : Init vars used in single daq
*
* Inputs        : daqIndex

* Outputs       : None
*
* Limitations   : None
********************************************************************************
END_FUNCTION_HDR */
STATIC FUNC(void, XCP_CODE) Xcp_InitDaq
(
    const uint16 daqIndex
)
{
    Xcp_SavedOdtIndex[daqIndex] = (uint8)0;
    Xcp_Daq_Mode[daqIndex].Bit.RUNNING = (uint8)FALSE;
    Xcp_DaqSubState[daqIndex] = XCP_DAQ_STOP;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name : Xcp_InitAllDaq
*
* Description   : Init vars used in all daq
*
* Inputs        : None

* Outputs       : None
*
* Limitations   : None
********************************************************************************
END_FUNCTION_HDR */
STATIC FUNC(void, XCP_CODE) Xcp_InitAllDaq (void)
{
    uint16 i;

    Xcp_SessionStatus.Bit.DAQ_RUNNING = (uint8)FALSE;
    Xcp_CurrentDaqIndex = XCP_INVALID_DAQ_NUM;

#if(XCP_MAX_DAQ > 0)

    for (i = (uint16)0; i < (uint16)XCP_MAX_DAQ; i++)
    {
        Xcp_InitDaq (i);
    }

#endif


#if(XCP_MAX_EVENT_CHANNEL > 0)

    for (i = (uint16)0; i < (uint16)XCP_MAX_EVENT_CHANNEL; i++)
    {
        Xcp_EventCnt[i] = (uint16)0;
    }

#endif

}



/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name : Xcp_CheckAndStopDaq
*
* Description   : when stop single daq,call this funtion to check if all daq is stopped
*
* Inputs        : None

* Outputs       : None
*
* Limitations   : None
********************************************************************************
END_FUNCTION_HDR */
STATIC FUNC(void, XCP_CODE) Xcp_CheckAndStopDaq (void)
{
    boolean  allDaqStopFlag = TRUE;
    uint16 i;

    /* check if all daq is stop */
    for (i = (uint16)0; i < (uint16)XCP_MAX_DAQ; i++)
    {
        if (TRUE == Xcp_Daq_Mode[i].Bit.RUNNING)
        {
            allDaqStopFlag = FALSE;
            break;
        }
    }

    if (TRUE == allDaqStopFlag)
    {
        Xcp_InitAllDaq();
    }

}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name : Xcp_DaqInit
*
* Description   : Init vars used in Daq cmd
*
* Inputs        : None

* Outputs       : None
*
* Limitations   : None
********************************************************************************
END_FUNCTION_HDR */
FUNC(void, XCP_CODE) Xcp_DaqInit (void)
{
#if(XCP_MAX_DAQ > 0)
    uint16 i;
#endif

    Xcp_DaqPointer.DaqIndex = XCP_INVALID_DAQ_NUM;
    Xcp_DaqPointer.OdtIndex = XCP_INVALID_ODT_NUM;
    Xcp_DaqPointer.OdtEntryIndex = XCP_INVALID_ODTENTRY_NUM;
    Xcp_InitAllDaq();

#if(XCP_MAX_DAQ > 0)

    for (i = (uint16)0; i < (uint16)XCP_MAX_DAQ; i++)
    {
        Xcp_Daq_Mode[i].Byte = (uint8)0;

#if(STD_ON == XCP_PRESCALER_SUPPORTED)
        Xcp_Daq_Prescale[i] = (uint8)1;
#endif
#if(STD_ON == XCP_DAQ_PRIORITY_SUPPORTED)
        Xcp_Daq_Priority[i] = (uint8)0;
#endif
    }

#endif

    Xcp_DaqTxFlag = FALSE;

}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name : Xcp_FuncClearDaqList
*
* Description   : Implementation of Xcp_FuncClearDaqList command
*
* Inputs        : None

* Outputs       : None
*
* Limitations   : None
********************************************************************************
END_FUNCTION_HDR */
FUNC(void, XCP_CODE) Xcp_FuncClearDaqList (void)
{
    uint16 DaqList;
    uint8 j;
    uint8 k;

    SchM_Enter_Xcp_XCP_EXCLUSIVE_AREA_0();
    DaqList = Xcp_Make16Bits (Xcp_RxData[XCP_PACKET_BYTE2], Xcp_RxData[XCP_PACKET_BYTE3]);
    SchM_Exit_Xcp_XCP_EXCLUSIVE_AREA_0();

    /* this cmd will clear daq no matter the daq is running or stoping*/
    if (DaqList >= (uint16)XCP_MAX_DAQ)
    {
        Xcp_CreatErrResponse (XCP_ERR_OUT_OF_RANGE);
    }
    else
    {

        Xcp_InitDaq (DaqList);

        for (j = (uint8)0; j < Xcp_DAQConfig[DaqList].XcpMaxOdt; j++)
        {
            for (k = (uint8)0; k < Xcp_DAQConfig[DaqList].XcpMaxOdtEntries; k++)
            {
                Xcp_DAQConfig[DaqList].XcpOdt[j].XcpOdtEntry[k].XcpOdtEntryAddress = (uint32)0;
                Xcp_DAQConfig[DaqList].XcpOdt[j].XcpOdtEntry[k].XcpOdtEntryAddressExt = (uint8)0;
                Xcp_DAQConfig[DaqList].XcpOdt[j].XcpOdtEntry[k].XcpOdtEntryLength = (uint8)0;
                Xcp_DAQConfig[DaqList].XcpOdt[j].XcpOdtEntry[k].XcpOdtEntryBitOffset = XCP_WRITE_DAQ_NO_BIT_MASK;
            }
        }

        Xcp_Daq_Mode[DaqList].Byte = (uint8)0;/* also reset mode */
        Xcp_CheckAndStopDaq();

        Xcp_TxData[XCP_PACKET_BYTE0] = XCP_CMD_RES_CODE;
        Xcp_TxPduInfo.SduLength = XCP_NORMAL_POSLEN;
        Xcp_TxPduInfo.SduDataPtr = Xcp_TxData;

    }

    Xcp_Transmit();
}



/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name : Xcp_FuncSetDaqPtr
*
* Description   : Implementation of Xcp_FuncSetDaqPtr command
*
* Inputs        : None

* Outputs       : None
*
* Limitations   : None
********************************************************************************
END_FUNCTION_HDR */
FUNC(void, XCP_CODE) Xcp_FuncSetDaqPtr (void)
{
    uint16 DAQ_Index;
    uint8 ODT_Index;
    uint8 ODT_Entry_Index;

    SchM_Enter_Xcp_XCP_EXCLUSIVE_AREA_0();
    DAQ_Index = Xcp_Make16Bits (Xcp_RxData[XCP_PACKET_BYTE2], Xcp_RxData[XCP_PACKET_BYTE3]);
    ODT_Index = Xcp_RxData[XCP_PACKET_BYTE4];
    ODT_Entry_Index = Xcp_RxData[XCP_PACKET_BYTE5];
    SchM_Exit_Xcp_XCP_EXCLUSIVE_AREA_0();


    /* when DAQ running, canset ptr to this daq, but can not write this daq */
    if (DAQ_Index >= (uint16)XCP_MAX_DAQ)
    {
        Xcp_CreatErrResponse (XCP_ERR_OUT_OF_RANGE);
    }
    else if (ODT_Index >= Xcp_DAQConfig[DAQ_Index].XcpMaxOdt)
    {
        Xcp_CreatErrResponse (XCP_ERR_OUT_OF_RANGE);
    }
    else if (ODT_Entry_Index >= Xcp_DAQConfig[DAQ_Index].XcpMaxOdtEntries)
    {
        Xcp_CreatErrResponse (XCP_ERR_OUT_OF_RANGE);
    }
    else
    {
        Xcp_DaqPointer.DaqIndex = DAQ_Index;
        Xcp_DaqPointer.OdtIndex = ODT_Index;
        Xcp_DaqPointer.OdtEntryIndex = ODT_Entry_Index;

        /*Send Positive Response*/
        Xcp_TxData[XCP_PACKET_BYTE0] = XCP_CMD_RES_CODE;
        Xcp_TxPduInfo.SduLength = XCP_NORMAL_POSLEN;
        Xcp_TxPduInfo.SduDataPtr = Xcp_TxData;
    }

    Xcp_Transmit();
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name : Xcp_FuncWriteDaq
*
* Description   : Implementation of Xcp_FuncWriteDaq command
*
* Inputs        : None

* Outputs       : None
*
* Limitations   : None
********************************************************************************
END_FUNCTION_HDR */
FUNC(void, XCP_CODE) Xcp_FuncWriteDaq (void)
{
    uint8 bitOffset;
    uint8 size;
    uint8 addrExt;
    uint32 addr;
    uint8 entryIndex;
    uint16 totalsize = (uint16)0;
    P2VAR (Xcp_OdtEntry_Type, AUTOMATIC, XCP_PRIVATE_DATA) entry;



    SchM_Enter_Xcp_XCP_EXCLUSIVE_AREA_0();
    bitOffset = Xcp_RxData[XCP_PACKET_BYTE1];
    size = Xcp_RxData[XCP_PACKET_BYTE2];
    addrExt = Xcp_RxData[XCP_PACKET_BYTE3];
    addr = Xcp_Make32Bits (Xcp_RxData[XCP_PACKET_BYTE4], Xcp_RxData[XCP_PACKET_BYTE5],
                           Xcp_RxData[XCP_PACKET_BYTE6], Xcp_RxData[XCP_PACKET_BYTE7]);
    SchM_Exit_Xcp_XCP_EXCLUSIVE_AREA_0();

#if(XCP_GRANULARITY_ODT_ENTRY_SIZE_DAQ > 1)
    size = size * XCP_GRANULARITY_ODT_ENTRY_SIZE_DAQ;
#endif


    if (Xcp_DaqPointer.DaqIndex >= (uint16)XCP_MAX_DAQ)
    {
        Xcp_CreatErrResponse (XCP_ERR_WRITE_PROTECTED);
    }
    else if ((uint8)TRUE == Xcp_Daq_Mode[Xcp_DaqPointer.DaqIndex].Bit.RUNNING)
    {
        /* can not config DAQ when DAQ running */
        Xcp_CreatErrResponse (XCP_ERR_DAQ_ACTIVE);
    }
    else if (Xcp_DaqPointer.OdtIndex >= Xcp_DAQConfig[Xcp_DaqPointer.DaqIndex].XcpMaxOdt)
    {
        Xcp_CreatErrResponse (XCP_ERR_WRITE_PROTECTED);
    }
    else if (Xcp_DaqPointer.OdtEntryIndex >= Xcp_DAQConfig[Xcp_DaqPointer.DaqIndex].XcpMaxOdtEntries)
    {
        Xcp_CreatErrResponse (XCP_ERR_WRITE_PROTECTED);
    }
    else if ( (XCP_WRITE_DAQ_NO_BIT_MASK != bitOffset)
              && (bitOffset > XCP_WRITE_DAQ_BIT_MASK_MAX) )
    {
        Xcp_CreatErrResponse (XCP_ERR_WRITE_PROTECTED);
    }
    else
    {
        entry = Xcp_DAQConfig[Xcp_DaqPointer.DaqIndex].XcpOdt[Xcp_DaqPointer.OdtIndex].XcpOdtEntry;

        /* check if odt has enough space to add new element */
        for (entryIndex = (uint8)0; entryIndex < Xcp_DAQConfig[Xcp_DaqPointer.DaqIndex].XcpMaxOdtEntries; entryIndex++)
        {
            if (entryIndex == Xcp_DaqPointer.OdtEntryIndex)
            {
                totalsize = totalsize + (uint16)size;
            }
            else
            {
                totalsize = totalsize + (uint16)entry[entryIndex].XcpOdtEntryLength;
            }
        }

        /*
        here totalsize should add pid header bytes .
        accroding different ID type, the headersize is different, simple method to get header type XCP_ID_FIELD_TYPE+1
        refer to xcp docments, 1Byte in ABS ID TYPE, 2Byte in relative type ...
        */
        totalsize = totalsize + ((uint16)XCP_ID_FIELD_TYPE + (uint16)1);

        if (totalsize > Xcp_TpProConfig[Xcp_ActiveLink.XcpTpHandle].MaxDto)
        {
            Xcp_CreatErrResponse (XCP_ERR_WRITE_PROTECTED);
        }
        else
        {
            /* write odt element */
            entry[Xcp_DaqPointer.OdtEntryIndex].XcpOdtEntryAddress = addr;
            entry[Xcp_DaqPointer.OdtEntryIndex].XcpOdtEntryAddressExt = addrExt;
            entry[Xcp_DaqPointer.OdtEntryIndex].XcpOdtEntryLength = size;
            entry[Xcp_DaqPointer.OdtEntryIndex].XcpOdtEntryBitOffset = bitOffset;

            /* move ptr to next entry, if odt is full, reset ptr*/
            if (Xcp_DaqPointer.OdtEntryIndex < Xcp_DAQConfig[Xcp_DaqPointer.DaqIndex].XcpMaxOdtEntries)
            {
                Xcp_DaqPointer.OdtEntryIndex++;
            }
            else
            {
                Xcp_DaqPointer.DaqIndex = XCP_INVALID_DAQ_NUM;
                Xcp_DaqPointer.OdtIndex = XCP_INVALID_ODT_NUM;
                Xcp_DaqPointer.OdtEntryIndex = XCP_INVALID_ODTENTRY_NUM;
            }

            /*Send Positive Response*/
            Xcp_TxData[XCP_PACKET_BYTE0] = XCP_CMD_RES_CODE;
            Xcp_TxPduInfo.SduLength = XCP_NORMAL_POSLEN;
            Xcp_TxPduInfo.SduDataPtr = Xcp_TxData;

        }
    }

    Xcp_Transmit();

}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name : Xcp_FuncSetDaqListMode
*
* Description   : Implementation of Xcp_FuncSetDaqListMode command
*
* Inputs        : None

* Outputs       : None
*
* Limitations   : None
*
********************************************************************************
END_FUNCTION_HDR */
FUNC(void, XCP_CODE) Xcp_FuncSetDaqListMode (void)
{
    /* as all info in setmode fun cannot be modified in this version
       PID STAMP DIRECTION is not supported
       in autosar , daq in event is static configed by user
       daq priority is not supported
       daq's Transmission rate is static configed by user in event

       so in this version , this function only give pos resp
       but has no effect
    */
    /***************************************************************************
    * PRQA S 759 MISRA-C:2004 Rule 18.4
    * Use union to fullfill xcp protocol and also union make the code easy to
    * read and implement.
    * This part of code is verified manually and has no impact.
    ***************************************************************************/
    Xcp_Daq_Mode_Type mode;
    uint16 tempDaqIndex;
    uint16 eventIndex;
    uint8 prescaler;
    uint8 priority;


    SchM_Enter_Xcp_XCP_EXCLUSIVE_AREA_0();
    mode.Byte = Xcp_RxData[XCP_PACKET_BYTE1];
    tempDaqIndex = Xcp_Make16Bits (Xcp_RxData[XCP_PACKET_BYTE2], Xcp_RxData[XCP_PACKET_BYTE3]);
    eventIndex = Xcp_Make16Bits (Xcp_RxData[XCP_PACKET_BYTE4], Xcp_RxData[XCP_PACKET_BYTE5]);
    prescaler = Xcp_RxData[XCP_PACKET_BYTE6];
    priority = Xcp_RxData[XCP_PACKET_BYTE7];
    SchM_Exit_Xcp_XCP_EXCLUSIVE_AREA_0();


    if (tempDaqIndex >= (uint16)XCP_MAX_DAQ)
    {
        Xcp_CreatErrResponse (XCP_ERR_OUT_OF_RANGE);
    }
    else if (eventIndex >= (uint16)XCP_MAX_EVENT_CHANNEL)
    {
        Xcp_CreatErrResponse (XCP_ERR_OUT_OF_RANGE);
    }
    else if ((uint8)TRUE == Xcp_Daq_Mode[tempDaqIndex].Bit.RUNNING)
    {
        /* can not config DAQ when DAQ running */
        Xcp_CreatErrResponse (XCP_ERR_DAQ_ACTIVE);
    }

#if(STD_OFF == XCP_PRESCALER_SUPPORTED)
    else if (prescaler > (uint8)1)
    {
        Xcp_CreatErrResponse (XCP_ERR_OUT_OF_RANGE);
    }

#endif
#if(STD_OFF == XCP_DAQ_PRIORITY_SUPPORTED)
    else if (priority > (uint8)0)
    {
        Xcp_CreatErrResponse (XCP_ERR_OUT_OF_RANGE);
    }

#endif
#if(STD_OFF == XCP_PIDOFF_SUPPORTED)
    else if ((uint8)0 != mode.Bit.PID_OFF)
    {
        Xcp_CreatErrResponse (XCP_ERR_CMD_SYNTAX);
    }

#endif
#if(STD_OFF == XCP_TIMESTAMP_SUPPORTED)
    else if ((uint8)0 != mode.Bit.TIMESTAMP)
    {
        Xcp_CreatErrResponse (XCP_ERR_CMD_SYNTAX);
    }

#endif
#if(STD_OFF == XCP_STIM_SUPPORTED)
    else if ((uint8)0 != mode.Bit.DIRECTION)
    {
        Xcp_CreatErrResponse (XCP_ERR_CMD_SYNTAX);
    }

#endif
    else
    {
        Xcp_Daq_Mode[tempDaqIndex].Bit.PID_OFF = mode.Bit.PID_OFF;
        Xcp_Daq_Mode[tempDaqIndex].Bit.TIMESTAMP = mode.Bit.TIMESTAMP;
        Xcp_Daq_Mode[tempDaqIndex].Bit.DIRECTION = mode.Bit.DIRECTION;

#if(STD_ON == XCP_PRESCALER_SUPPORTED)
        Xcp_Daq_Prescale[tempDaqIndex] = prescaler;
#endif
#if(STD_ON == XCP_DAQ_PRIORITY_SUPPORTED)
        Xcp_Daq_Priority[tempDaqIndex] = priority;
#endif

        /*Send Positive Response*/
        Xcp_TxData[XCP_PACKET_BYTE0] = XCP_CMD_RES_CODE;
        Xcp_TxPduInfo.SduLength = XCP_NORMAL_POSLEN;
        Xcp_TxPduInfo.SduDataPtr = Xcp_TxData;
    }

    Xcp_Transmit();

}


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name : Xcp_FuncGetDaqListMode
*
* Description   : Implementation of Xcp_FuncGetDaqListMode command
*
* Inputs        : None

* Outputs       : None
*
* Limitations   : None
********************************************************************************
END_FUNCTION_HDR */
FUNC(void, XCP_CODE) Xcp_FuncGetDaqListMode (void)
{

    uint16 tempDaqIndex;
    uint16 event;

    SchM_Enter_Xcp_XCP_EXCLUSIVE_AREA_0();
    tempDaqIndex = Xcp_Make16Bits (Xcp_RxData[XCP_PACKET_BYTE2], Xcp_RxData[XCP_PACKET_BYTE3]);
    SchM_Exit_Xcp_XCP_EXCLUSIVE_AREA_0();

    if (tempDaqIndex >= (uint16)XCP_MAX_DAQ)
    {
        Xcp_CreatErrResponse (XCP_ERR_OUT_OF_RANGE);
    }
    else
    {
        event = Xcp_DAQConfig[tempDaqIndex].XcpRelateEvent;

        Xcp_TxData[XCP_PACKET_BYTE0] = XCP_CMD_RES_CODE;
        Xcp_TxData[XCP_PACKET_BYTE1] = Xcp_Daq_Mode[tempDaqIndex].Byte;
        Xcp_TxData[XCP_PACKET_BYTE2] = XCP_RESERVED_BYTE;
        Xcp_TxData[XCP_PACKET_BYTE3] = XCP_RESERVED_BYTE;
        Xcp_TxData[XCP_PACKET_BYTE4] = Xcp_GetHighByte (event);
        Xcp_TxData[XCP_PACKET_BYTE5] = Xcp_GetLowByte (event);

#if(STD_OFF == XCP_PRESCALER_SUPPORTED)
        Xcp_TxData[XCP_PACKET_BYTE6] = (uint8)1;
#else
        Xcp_TxData[XCP_PACKET_BYTE6] = Xcp_Daq_Prescale[tempDaqIndex];
#endif

#if(STD_OFF == XCP_DAQ_PRIORITY_SUPPORTED)
        Xcp_TxData[XCP_PACKET_BYTE7] = (uint8)0;
#else
        Xcp_TxData[XCP_PACKET_BYTE7] = Xcp_Daq_Priority[tempDaqIndex];
#endif

        Xcp_TxPduInfo.SduLength = XCP_GET_DAQ_LIST_MODE_POS_LEN;
        Xcp_TxPduInfo.SduDataPtr = Xcp_TxData;
    }

    Xcp_Transmit();
}


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name : Xcp_FuncStartStopDaqList
*
* Description   : Implementation of Xcp_FuncStartStopDaqList command
*
* Inputs        : None

* Outputs       : None
*
* Limitations   : None
********************************************************************************
END_FUNCTION_HDR */
FUNC(void, XCP_CODE) Xcp_FuncStartStopDaqList (void)
{
    uint16 tempDaqIndex;
    uint8  mode;
    uint8  firstPid;

    SchM_Enter_Xcp_XCP_EXCLUSIVE_AREA_0();
    mode = Xcp_RxData[XCP_PACKET_BYTE1];
    tempDaqIndex = Xcp_Make16Bits (Xcp_RxData[XCP_PACKET_BYTE2], Xcp_RxData[XCP_PACKET_BYTE3]);
    SchM_Exit_Xcp_XCP_EXCLUSIVE_AREA_0();

    if (tempDaqIndex >= (uint16)XCP_MAX_DAQ)
    {
        Xcp_CreatErrResponse (XCP_ERR_OUT_OF_RANGE);
    }
    else if (mode > XCP_START_STOP_DAQ_LIST_SEL)
    {
        Xcp_CreatErrResponse (XCP_ERR_OUT_OF_RANGE);
    }
    else
    {
        if (XCP_START_STOP_DAQ_LIST_STOP == mode)
        {
            Xcp_InitDaq (tempDaqIndex);
            Xcp_CheckAndStopDaq();
        }
        else if (XCP_START_STOP_DAQ_LIST_START == mode)
        {
            Xcp_Daq_Mode[tempDaqIndex].Bit.RUNNING = (uint8)TRUE;
            Xcp_SessionStatus.Bit.DAQ_RUNNING = (uint8)TRUE;
            Xcp_DaqSubState[tempDaqIndex] = XCP_DAQ_WAIT_EVENT;
        }
        else
        {
            Xcp_Daq_Mode[tempDaqIndex].Bit.SELECTED = (uint8)TRUE;
        }

#if(XCP_ID_ABS_TYPE == XCP_ID_FIELD_TYPE)
        firstPid = Xcp_DAQConfig[tempDaqIndex].XcpOdt[0].XcpDtoPid;
#endif

        Xcp_TxData[XCP_PACKET_BYTE0] = XCP_CMD_RES_CODE;
        Xcp_TxData[XCP_PACKET_BYTE1] = firstPid;
        Xcp_TxPduInfo.SduLength = XCP_START_STOP_DAQ_LIST_POS_LEN;
        Xcp_TxPduInfo.SduDataPtr = Xcp_TxData;
    }

    Xcp_Transmit();

}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name : Xcp_FuncStartStopSynch
*
* Description   : Implementation of Xcp_FuncStartStopSynch command
*
* Inputs        : None

* Outputs       : None
*
* Limitations   : None
********************************************************************************
END_FUNCTION_HDR */
FUNC(void, XCP_CODE) Xcp_FuncStartStopSynch (void)
{
    uint8  mode;
    uint16 i;

    SchM_Enter_Xcp_XCP_EXCLUSIVE_AREA_0();
    mode = Xcp_RxData[XCP_PACKET_BYTE1];
    SchM_Exit_Xcp_XCP_EXCLUSIVE_AREA_0();

    if (mode > XCP_START_STOP_SYNCH_STOP)
    {
        Xcp_CreatErrResponse (XCP_ERR_OUT_OF_RANGE);
    }
    else
    {
        if (XCP_START_STOP_SYNCH_STOPALL == mode)
        {
            Xcp_InitAllDaq();
        }
        else if (XCP_START_STOP_SYNCH_START == mode)
        {
            for (i = (uint16)0; i < (uint16)XCP_MAX_DAQ; i++)
            {
                if ((uint8)TRUE == Xcp_Daq_Mode[i].Bit.SELECTED)
                {
                    Xcp_Daq_Mode[i].Bit.RUNNING = (uint8)TRUE;
                    Xcp_SessionStatus.Bit.DAQ_RUNNING = (uint8)TRUE;
                    Xcp_DaqSubState[i] = XCP_DAQ_WAIT_EVENT;
                }
            }
        }
        else
        {
            for (i = (uint16)0; i < (uint16)XCP_MAX_DAQ; i++)
            {
                if ((uint8)TRUE == Xcp_Daq_Mode[i].Bit.SELECTED)
                {
                    Xcp_InitDaq (i);
                }
            }

            Xcp_CheckAndStopDaq();
        }

        for (i = (uint16)0; i < (uint16)XCP_MAX_DAQ; i++)
        {
            Xcp_Daq_Mode[i].Bit.SELECTED = (uint8)FALSE;
        }

        Xcp_TxData[XCP_PACKET_BYTE0] = XCP_CMD_RES_CODE;
        Xcp_TxPduInfo.SduLength = XCP_NORMAL_POSLEN;
        Xcp_TxPduInfo.SduDataPtr = Xcp_TxData;
    }

    Xcp_Transmit();

}


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name : Xcp_FuncGetDaqClock
*
* Description   : Implementation of Xcp_FuncGetDaqClock command
*
* Inputs        : None

* Outputs       : None
*
* Limitations   : None
********************************************************************************
END_FUNCTION_HDR */
FUNC(void, XCP_CODE) Xcp_FuncGetDaqClock (void)
{
    const uint32 TS = (uint32)0;   /* not support ts yet keep 0 */

#if(STD_ON == XCP_TIMESTAMP_SUPPORTED)
    /* get TS here */
#endif

    /* Set response data */
    Xcp_TxData[XCP_PACKET_BYTE0] = XCP_CMD_RES_CODE;
    Xcp_TxData[XCP_PACKET_BYTE1] = XCP_RESERVED_BYTE;
    Xcp_TxData[XCP_PACKET_BYTE2] = XCP_RESERVED_BYTE;
    Xcp_TxData[XCP_PACKET_BYTE3] = XCP_RESERVED_BYTE;
    Xcp_TxData[XCP_PACKET_BYTE4] = Xcp_GetFirstByte (TS);
    Xcp_TxData[XCP_PACKET_BYTE5] = Xcp_GetSecondByte (TS);
    Xcp_TxData[XCP_PACKET_BYTE6] = Xcp_GetThirdByte (TS);
    Xcp_TxData[XCP_PACKET_BYTE7] = Xcp_GetFourthByte (TS);

    /* Send Positive Response */
    Xcp_TxPduInfo.SduLength = XCP_GET_DAQ_CLOCK_POS_LEN;
    Xcp_TxPduInfo.SduDataPtr = Xcp_TxData;

    Xcp_Transmit();

}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name : Xcp_FuncReadDaq
*
* Description   : Implementation of Xcp_FuncReadDaq command
*
* Inputs        : None

* Outputs       : None
*
* Limitations   : None
********************************************************************************
END_FUNCTION_HDR */
FUNC(void, XCP_CODE) Xcp_FuncReadDaq (void)
{

    uint8 size;
    Xcp_OdtEntry_Type *entry;

    if (Xcp_DaqPointer.DaqIndex >= (uint16)XCP_MAX_DAQ)
    {
        Xcp_CreatErrResponse (XCP_ERR_OUT_OF_RANGE);
    }
    else if (Xcp_DaqPointer.OdtIndex >= Xcp_DAQConfig[Xcp_DaqPointer.DaqIndex].XcpMaxOdt)
    {
        Xcp_CreatErrResponse (XCP_ERR_OUT_OF_RANGE);
    }
    else if (Xcp_DaqPointer.OdtEntryIndex >= Xcp_DAQConfig[Xcp_DaqPointer.DaqIndex].XcpMaxOdtEntries)
    {
        Xcp_DaqPointer.DaqIndex = XCP_INVALID_DAQ_NUM;
        Xcp_DaqPointer.OdtIndex = XCP_INVALID_ODT_NUM;
        Xcp_DaqPointer.OdtEntryIndex = XCP_INVALID_ODTENTRY_NUM;       
        Xcp_CreatErrResponse (XCP_ERR_OUT_OF_RANGE);
    }
    else
    {
        entry = &Xcp_DAQConfig[Xcp_DaqPointer.DaqIndex].XcpOdt[Xcp_DaqPointer.OdtIndex].XcpOdtEntry[Xcp_DaqPointer.OdtEntryIndex];
        size = entry->XcpOdtEntryLength;
#if(XCP_GRANULARITY_ODT_ENTRY_SIZE_DAQ > 1)
        size = size / XCP_GRANULARITY_ODT_ENTRY_SIZE_DAQ;
#endif

        /* Set response data */
        Xcp_TxData[XCP_PACKET_BYTE1] = entry->XcpOdtEntryBitOffset;
        Xcp_TxData[XCP_PACKET_BYTE2] = size;
        Xcp_TxData[XCP_PACKET_BYTE3] = entry->XcpOdtEntryAddressExt;
        Xcp_TxData[XCP_PACKET_BYTE4] = Xcp_GetFirstByte (entry->XcpOdtEntryAddress);
        Xcp_TxData[XCP_PACKET_BYTE5] = Xcp_GetSecondByte (entry->XcpOdtEntryAddress);
        Xcp_TxData[XCP_PACKET_BYTE6] = Xcp_GetThirdByte (entry->XcpOdtEntryAddress);
        Xcp_TxData[XCP_PACKET_BYTE7] = Xcp_GetFourthByte (entry->XcpOdtEntryAddress);

        /* move ptr to next entry, if last odt , reset ptr*/
        if (Xcp_DaqPointer.OdtEntryIndex < Xcp_DAQConfig[Xcp_DaqPointer.DaqIndex].XcpMaxOdtEntries)
        {
            Xcp_DaqPointer.OdtEntryIndex++;
        }
        /*other possibilities have been included above*/

        /* Send Positive Response */
        Xcp_TxPduInfo.SduLength = XCP_READ_DAQ_POS_LEN;
        Xcp_TxPduInfo.SduDataPtr = Xcp_TxData;
    }

    Xcp_Transmit();

}


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name : Xcp_FuncGetDaqProcessorInfo
*
* Description   : Implementation of Xcp_FuncGetDaqProcessorInfo command
*
* Inputs        : None

* Outputs       : None
*
* Limitations   : None
********************************************************************************
END_FUNCTION_HDR */
FUNC(void, XCP_CODE) Xcp_FuncGetDaqProcessorInfo (void)
{

    Xcp_TxData[XCP_PACKET_BYTE0] = XCP_CMD_RES_CODE;
    Xcp_TxData[XCP_PACKET_BYTE1] = DAQ_PROCESSOR_INFO;
    Xcp_TxData[XCP_PACKET_BYTE2] = Xcp_GetHighByte ( (uint16) XCP_MAX_DAQ);
    Xcp_TxData[XCP_PACKET_BYTE3] = Xcp_GetLowByte ( (uint16) XCP_MAX_DAQ);
    Xcp_TxData[XCP_PACKET_BYTE4] = Xcp_GetHighByte ( (uint16) XCP_MAX_EVENT_CHANNEL);
    Xcp_TxData[XCP_PACKET_BYTE5] = Xcp_GetLowByte ( (uint16) XCP_MAX_EVENT_CHANNEL);
    Xcp_TxData[XCP_PACKET_BYTE6] = (uint8)XCP_MIN_DAQ;
    Xcp_TxData[XCP_PACKET_BYTE7] = (uint8)DAQ_KEY_BYTE;

    Xcp_TxPduInfo.SduLength = XCP_GET_DAQ_PROCESSOR_INFO_POS_LEN;
    Xcp_TxPduInfo.SduDataPtr = Xcp_TxData;

    Xcp_Transmit();
}


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name : Xcp_FuncGetDaqResolution_Info
*
* Description   : Implementation of Xcp_FuncGetDaqResolution_Info command
*
* Inputs        : None

* Outputs       : None
*
* Limitations   : None
********************************************************************************
END_FUNCTION_HDR */
FUNC(void, XCP_CODE) Xcp_FuncGetDaqResolution_Info (void)
{

    /* Set response data */
    Xcp_TxData[XCP_PACKET_BYTE0] = XCP_CMD_RES_CODE;
    Xcp_TxData[XCP_PACKET_BYTE1] = (uint8)XCP_GRANULARITY_ODT_ENTRY_SIZE_DAQ;
    Xcp_TxData[XCP_PACKET_BYTE2] = (uint8)XCP_MAX_ODT_ENTRY_SIZE_DAQ;
    Xcp_TxData[XCP_PACKET_BYTE3] = (uint8)0;
    Xcp_TxData[XCP_PACKET_BYTE4] = (uint8)0;
    Xcp_TxData[XCP_PACKET_BYTE5] = (uint8)0;
    Xcp_TxData[XCP_PACKET_BYTE6] = (uint8)0;
    Xcp_TxData[XCP_PACKET_BYTE7] = (uint8)0;

    Xcp_TxPduInfo.SduLength = XCP_GET_DAQ_RESOLUTION_INFO_POS_LEN;
    Xcp_TxPduInfo.SduDataPtr = Xcp_TxData;
    /* Send Positive Response */
    Xcp_Transmit();
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name : Xcp_FuncGetDaqListInfo
*
* Description   : Implementation of Xcp_FuncGetDaqListInfo command
*
* Inputs        : None

* Outputs       : None
*
* Limitations   : None
********************************************************************************
END_FUNCTION_HDR */
FUNC(void, XCP_CODE) Xcp_FuncGetDaqListInfo (void)
{

    uint16 tempDaqIndex;

    SchM_Enter_Xcp_XCP_EXCLUSIVE_AREA_0();
    tempDaqIndex = Xcp_Make16Bits (Xcp_RxData[XCP_PACKET_BYTE2], Xcp_RxData[XCP_PACKET_BYTE3]);
    SchM_Exit_Xcp_XCP_EXCLUSIVE_AREA_0();

    if (tempDaqIndex >= (uint16)XCP_MAX_DAQ)
    {
        Xcp_CreatErrResponse (XCP_ERR_OUT_OF_RANGE);
    }
    else
    {
        Xcp_TxData[XCP_PACKET_BYTE0] = XCP_CMD_RES_CODE;
        Xcp_TxData[XCP_PACKET_BYTE1] = Xcp_DAQConfig[tempDaqIndex].XcpDaqProperties;
        Xcp_TxData[XCP_PACKET_BYTE2] = Xcp_DAQConfig[tempDaqIndex].XcpMaxOdt;
        Xcp_TxData[XCP_PACKET_BYTE3] = Xcp_DAQConfig[tempDaqIndex].XcpMaxOdtEntries;
        Xcp_TxData[XCP_PACKET_BYTE4] = Xcp_GetHighByte (Xcp_DAQConfig[tempDaqIndex].XcpRelateEvent);
        Xcp_TxData[XCP_PACKET_BYTE5] = Xcp_GetLowByte (Xcp_DAQConfig[tempDaqIndex].XcpRelateEvent);

        Xcp_TxPduInfo.SduLength = XCP_GET_DAQ_LIST_INFO_POS_LEN;
        Xcp_TxPduInfo.SduDataPtr = Xcp_TxData;

    }

    Xcp_Transmit();

}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name : Xcp_FuncGetDaqEventInfo
*
* Description   : Implementation of Xcp_FuncGetDaqEventInfo command
*
* Inputs        : None

* Outputs       : None
*
* Limitations   : None
********************************************************************************
END_FUNCTION_HDR */
FUNC(void, XCP_CODE) Xcp_FuncGetDaqEventInfo (void)
{
    uint16 eventIndex;

    SchM_Enter_Xcp_XCP_EXCLUSIVE_AREA_0();
    eventIndex = Xcp_Make16Bits (Xcp_RxData[XCP_PACKET_BYTE2], Xcp_RxData[XCP_PACKET_BYTE3]);
    SchM_Exit_Xcp_XCP_EXCLUSIVE_AREA_0();

    if (eventIndex >= (uint16)XCP_MAX_EVENT_CHANNEL)
    {
        Xcp_CreatErrResponse (XCP_ERR_OUT_OF_RANGE);
    }
    else
    {
        /* Set response data */
        Xcp_TxData[XCP_PACKET_BYTE0] = XCP_CMD_RES_CODE;
        Xcp_TxData[XCP_PACKET_BYTE1] = Xcp_EventConfig[eventIndex].XcpEventProperties;
        Xcp_TxData[XCP_PACKET_BYTE2] = Xcp_EventConfig[eventIndex].XcpEventChannelMaxDaqList;
        Xcp_TxData[XCP_PACKET_BYTE3] = Xcp_EventConfig[eventIndex].XcpEventNameInBytes;
        Xcp_TxData[XCP_PACKET_BYTE4] = Xcp_EventConfig[eventIndex].XcpEventTimeCycle * (uint8)XCP_MAIN_FUNCTION_PERIOD;
        Xcp_TxData[XCP_PACKET_BYTE5] = XCP_TIME_UINT_1MS;
        Xcp_TxData[XCP_PACKET_BYTE6] = Xcp_EventConfig[eventIndex].XcpEventChannelPriority;

        Xcp_MTA = (uint32) Xcp_EventConfig[eventIndex].XcpEventName;

        Xcp_TxPduInfo.SduLength = XCP_GET_DAQ_EVENT_INFO_POS_LEN;
        Xcp_TxPduInfo.SduDataPtr = Xcp_TxData;
    }

    Xcp_Transmit();
}


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name : Xcp_CopyODTData
*
* Description   : copy 1 odt data to tx buffer and send
*
* Inputs        : None

* Outputs       : None
*
* Limitations   : None
********************************************************************************
END_FUNCTION_HDR */
STATIC FUNC(boolean, XCP_CODE) Xcp_CopyODTData
(
    const uint16 daqIndex,
    const uint8 odtIndex
)
{
    P2CONST (Xcp_ODT_Config_Type, AUTOMATIC, XCP_CONST) odt;
    uint8 odtEntryIndex;
    uint16 size = (uint16)0;
    uint16 i;
    uint8 data;
    boolean temRet = TRUE;
#if(STD_ON == XCP_BITOFFSET_SUPPORT)
    uint8  bitoffsetindex;
    uint8  tempbitoffset;
    boolean bitflag;
    uint8 bitoffset;
#endif

    odt = &Xcp_DAQConfig[daqIndex].XcpOdt[odtIndex];

    SchM_Enter_Xcp_XCP_EXCLUSIVE_AREA_1();

    for (odtEntryIndex = (uint8)0; odtEntryIndex < Xcp_DAQConfig[Xcp_CurrentDaqIndex].XcpMaxOdtEntries; odtEntryIndex++)
    {
        if (odt->XcpOdtEntry[odtEntryIndex].XcpOdtEntryLength > (uint8)0)
        {

#if(STD_ON == XCP_BITOFFSET_SUPPORT)
            bitflag = FALSE;
            bitoffsetindex = (uint8)0;
            tempbitoffset = (uint8)0;
            bitoffset = odt->XcpOdtEntry[odtEntryIndex].XcpOdtEntryBitOffset;

            if (bitoffset <= XCP_WRITE_DAQ_BIT_MASK_MAX)
            {
                bitflag = TRUE;
#if(XCP_BYTE_ORDER  == XCP_MSB_FIRST)
                bitoffsetindex = XCP_BITOFFSET_MAXINDEX - (bitoffset >> XCP_BITOFFSET_SHIFTER);
#else
                bitoffsetindex = bitoffset >> XCP_BITOFFSET_SHIFTER;
#endif
                tempbitoffset = bitoffset % XCP_BITOFFSET_DIVISOR;
            }

#endif

            for (i = (uint16)0; i < odt->XcpOdtEntry[odtEntryIndex].XcpOdtEntryLength; i++)
            {
#if(STD_OFF == XCP_SPECIAL_ACCESS_RAM)
                data = * (uint8 *) (odt->XcpOdtEntry[odtEntryIndex].XcpOdtEntryAddress + i);
#else
                Xcp_App_ReadRam (odt->XcpOdtEntry[odtEntryIndex].XcpOdtEntryAddress + i, 1, &data);
#endif


#if(STD_ON == XCP_BITOFFSET_SUPPORT)

                if (TRUE == bitflag)
                {
                    if (i == bitoffsetindex)
                    {
                        data = (uint8) (data & ( (uint8) (1 << tempbitoffset) ) ); /* handle bit mask */
                    }
                    else
                    {
                        data = (uint8)0;
                    }
                }

#endif

                Xcp_DaqTxData[XCP_PACKET_BYTE1 + size] = data;/* Add data after Pid byte */
                size++;
            }
        }
        else
        {
            break;
        }
    }

    SchM_Exit_Xcp_XCP_EXCLUSIVE_AREA_1();

    if (size > (uint16)0)
    {
        Xcp_DaqTxData[XCP_PACKET_BYTE0] = odt->XcpDtoPid;
        Xcp_DaqTxPduInfo.SduLength = size + (uint16)1;/* datasize + Pidsize */
        Xcp_DaqTxPduInfo.SduDataPtr = Xcp_DaqTxData;
    }
    else
    {
        Xcp_DaqTxPduInfo.SduLength = (PduLengthType)0;
        temRet = FALSE;
    }

    return temRet;


}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name : Xcp_SearchAndTransmitNextODT
*
* Description   : This function is used to handle daq transmit job
*
* Inputs        : None

* Outputs       : None
*
* Limitations   : None
********************************************************************************
END_FUNCTION_HDR */
STATIC  FUNC(boolean, XCP_CODE) Xcp_SearchAndTransmitNextODT (void)
{
    boolean copyResult;
    boolean tryNextDaqFlag = TRUE;
    boolean ret = FALSE;

    if (Xcp_CurrentDaqIndex < (uint16)XCP_MAX_DAQ)
    {
        do
        {
            if (Xcp_SavedOdtIndex[Xcp_CurrentDaqIndex] >= Xcp_DAQConfig[Xcp_CurrentDaqIndex].XcpMaxOdt)
            {
                Xcp_SavedOdtIndex[Xcp_CurrentDaqIndex] = (uint8)0;
                Xcp_DaqSubState[Xcp_CurrentDaqIndex] = XCP_DAQ_WAIT_EVENT;

                do
                {
                    Xcp_CurrentDaqIndex++;

                    if ( (Xcp_CurrentDaqIndex < (uint16)XCP_MAX_DAQ)
                            && (XCP_DAQ_PENDING == Xcp_DaqSubState[Xcp_CurrentDaqIndex]) )
                    {
                        break;
                    }

                }
                while(Xcp_CurrentDaqIndex < (uint16)XCP_MAX_DAQ);

                if (Xcp_CurrentDaqIndex >= (uint16)XCP_MAX_DAQ)
                {
                    tryNextDaqFlag = FALSE;
                    Xcp_CurrentDaqIndex = XCP_INVALID_DAQ_NUM;
                }
            }
            else
            {
                /* copy data first */
                copyResult = Xcp_CopyODTData (Xcp_CurrentDaqIndex, Xcp_SavedOdtIndex[Xcp_CurrentDaqIndex]);

                if (FALSE == copyResult)
                {
                    /* no data in this daq , try next daq */
                    Xcp_SavedOdtIndex[Xcp_CurrentDaqIndex] = (uint8)0;
                    Xcp_DaqSubState[Xcp_CurrentDaqIndex] = XCP_DAQ_WAIT_EVENT;

                    do
                    {
                        Xcp_CurrentDaqIndex++;

                        if ( (Xcp_CurrentDaqIndex < (uint16)XCP_MAX_DAQ)
                                && (XCP_DAQ_PENDING == Xcp_DaqSubState[Xcp_CurrentDaqIndex]) )
                        {
                            break;
                        }

                    }
                    while(Xcp_CurrentDaqIndex < (uint16)XCP_MAX_DAQ);

                    if (Xcp_CurrentDaqIndex >= (uint16)XCP_MAX_DAQ)
                    {
                        tryNextDaqFlag = FALSE;
                        Xcp_CurrentDaqIndex = XCP_INVALID_DAQ_NUM;
                    }
                }
                else
                {
                    ret = TRUE;
                    tryNextDaqFlag = FALSE;
                }
            }
        }
        while(TRUE == tryNextDaqFlag);
    }


    return ret;
}


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name : Xcp_DaqMainFuntion
*
* Description   : This function is used to handle daq transmit job
*
* Inputs        : None

* Outputs       : None
*
* Limitations   : None
********************************************************************************
END_FUNCTION_HDR */
FUNC(void, XCP_CODE) Xcp_DaqMainFuntion (void)
{
    uint16 eventIndex;
    uint16 daqIndex;
    uint16 absDaqIndex;
    uint16 highDaqIndex = XCP_INVALID_DAQ_NUM;
    boolean newDaqSet = FALSE;
    boolean sendFlag = FALSE;




    /* only handle event priority here
       event channel is sorted by priority
       daq priority is ignored
       In next version, shall consider daq and event priority together
    */

    if ((uint8)TRUE == Xcp_SessionStatus.Bit.DAQ_RUNNING)
    {
        SchM_Enter_Xcp_XCP_EXCLUSIVE_AREA_2();

        for (eventIndex = (uint16)0; eventIndex < (uint16)XCP_MAX_EVENT_CHANNEL; eventIndex++)
        {
            Xcp_EventCnt[eventIndex]++;

            if (Xcp_EventCnt[eventIndex] >= Xcp_EventConfig[eventIndex].XcpEventTimeCycle)
            {
                Xcp_EventCnt[eventIndex] = (uint16)0;

                for (daqIndex = (uint16)0; daqIndex < Xcp_EventConfig[eventIndex].XcpEventChannelMaxDaqList; daqIndex++)
                {
                    absDaqIndex = Xcp_EventConfig[eventIndex].XcpEventChannelTriggeredDaqListRef[daqIndex];

                    if ( ((uint8)TRUE == Xcp_Daq_Mode[absDaqIndex].Bit.RUNNING)
                            && (XCP_DAQ_STOP != Xcp_DaqSubState[absDaqIndex]) )
                    {
                        if (XCP_DAQ_WAIT_EVENT == Xcp_DaqSubState[absDaqIndex])
                        {

                            Xcp_DaqSubState[absDaqIndex] = XCP_DAQ_PENDING;
                            newDaqSet = TRUE;
                        }
                        else /* pending or busy */
                        {
                            /* daq overflow, ignor this daq in this event slot */
                        }

                        /*save the highest priority daq index, the event and daq list  will be sort by priority from high to low */
                        if (XCP_INVALID_DAQ_NUM == highDaqIndex)
                        {
                            highDaqIndex = absDaqIndex;
                        }
                    }
                }
            }
        }

        /* new daq is set, may start new cycle transmit or change the priority */
        if (TRUE == newDaqSet)
        {
            if (XCP_INVALID_DAQ_NUM  == Xcp_CurrentDaqIndex)
            {
                /* no other daq is busy and no packet is transmiting,
                   start the highest daq transmit
                */
                Xcp_CurrentDaqIndex = highDaqIndex;

                if (FALSE == Xcp_TransmitingFlag)
                {
                    sendFlag = Xcp_SearchAndTransmitNextODT();
                }
            }

#if(STD_ON == XCP_DAQ_PRIORITY_SUPPORTED)
            else
            {
                /* check the priority to see if need to switch */
            }

#endif
        }

        SchM_Exit_Xcp_XCP_EXCLUSIVE_AREA_2();

        /* no new daq set in this cycle , do nothing */
        if (TRUE == sendFlag)
        {
            Xcp_TransmitDAQ();
        }

    }
}


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name : Xcp_TransmitDAQ
*
* Description   : Implementation of XCP daq packet transmit
*
* Inputs        : None

* Outputs       : None
*
* Limitations   : None
********************************************************************************
END_FUNCTION_HDR */

STATIC FUNC(void, XCP_CODE) Xcp_TransmitDAQ (void)
{
    Std_ReturnType tem;

    tem = Xcp_TpProConfig[Xcp_ActiveLink.XcpTpHandle].TpTxFunc (&Xcp_DaqTxPduInfo);

    if (E_OK == tem)
    {
        Xcp_TransmitingFlag = TRUE;
        Xcp_DaqTxFlag = TRUE;
    }

    /* if lowlayer is busy, ignor this daq transmit
       this will be retried in next confirmation
    */
}


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name : Xcp_DaqTxContinue
*
* Description   : This function is called in TxConfirmation, to handle the next ODT
*
* Inputs        : None

* Outputs       : None
*
* Limitations   : Called in interrupt context or high pirority task
********************************************************************************
END_FUNCTION_HDR */
FUNC(void, XCP_CODE) Xcp_DaqTxContinue (void)
{
    boolean sendFlag;

    if ( ((uint8)TRUE == Xcp_SessionStatus.Bit.DAQ_RUNNING)
            && (XCP_INVALID_DAQ_NUM != Xcp_CurrentDaqIndex) )
    {
        SchM_Enter_Xcp_XCP_EXCLUSIVE_AREA_2();

        if (TRUE == Xcp_DaqTxFlag)
        {
            Xcp_SavedOdtIndex[Xcp_CurrentDaqIndex]++;
            Xcp_DaqTxFlag = FALSE;
        }

        sendFlag = Xcp_SearchAndTransmitNextODT();
        SchM_Exit_Xcp_XCP_EXCLUSIVE_AREA_2();

        if (TRUE == sendFlag)
        {
            Xcp_TransmitDAQ();
        }
    }
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name : Xcp_RestartDaqPending
*
* Description   : This function is called to restart daq when daq tx time out
*
* Inputs        : None

* Outputs       : None
*
* Limitations   : This function shall be called only when DAQ_RUNNING is true
********************************************************************************
END_FUNCTION_HDR */
FUNC(void, XCP_CODE) Xcp_RestartDaqPending (void)
{
    uint16 daqIndex;
    uint16 absDaqIndex;
    uint16 eventIndex;

    Xcp_CurrentDaqIndex = XCP_INVALID_DAQ_NUM;

    for(eventIndex = (uint16)0; eventIndex < (uint16)XCP_MAX_EVENT_CHANNEL; eventIndex++)
    {
        Xcp_EventCnt[eventIndex] = (uint16)0;

        for (daqIndex = (uint16)0; daqIndex < Xcp_EventConfig[eventIndex].XcpEventChannelMaxDaqList; daqIndex++)
        {
            absDaqIndex = Xcp_EventConfig[eventIndex].XcpEventChannelTriggeredDaqListRef[daqIndex];

            Xcp_SavedOdtIndex[absDaqIndex] = (uint8)0;

            if(Xcp_DaqSubState[absDaqIndex] == XCP_DAQ_PENDING)
            {
                Xcp_DaqSubState[absDaqIndex] = XCP_DAQ_WAIT_EVENT;
            }
        }
    }
}


#define XCP_STOP_SEC_CODE
#include "MemMap.h"

#endif /*#if(STD_ON == XCP_DAQ_SUPPORTED)*/

