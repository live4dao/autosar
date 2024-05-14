/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
*   File Name       : XcpOnCan_Cbk.c
********************************************************************************
*   Project/Product : AUTOSAR 4.2
*   Title           : XcpOnCan_Cbk module source File
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
#include "XcpOnEth.h"

#if(STD_ON == XCP_ON_ETHERNET_ENABLED)
/*******************************************************************************
*   Internal Function Define
*******************************************************************************/
#define XCP_START_SEC_CODE
#include "MemMap.h"

#define XCP_RX_ETH_MESSAGE_MIN_LENGTH      ((PduLengthType)0x05)

STATIC FUNC (Std_ReturnType, XCP_CODE) Xcp_CheckEthLink
(
    const PduIdType EthPduId
);

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name : Xcp_CheckEthLink
*
* Description   : This function is used to check if xcp can link to eth
*
* Inputs        : CanPduId

* Outputs       : None
*
* Limitations   : None
********************************************************************************
END_FUNCTION_HDR */
STATIC FUNC (Std_ReturnType, XCP_CODE) Xcp_CheckEthLink
(
    const PduIdType EthPduId
)
{
    Std_ReturnType tem_Ret = E_NOT_OK;

    /*******************************************************************
    * PRQA S 506
    * Dereferencing pointer value that is possibly NULL.
    * this function is only used in Xcp internal,Xcp will ensure that
    * XcpConfigInfoPtr is valid
    * This part of code is verified manually and has no impact.
    ******************************************************************/
    if (XCP_PRO_HANDLE_INVALID == Xcp_ActiveLink.XcpTpHandle)
    {
        if ( (EthPduId < XcpConfigInfoPtr->NumOfConnections)
                && (XCP_PRO_HANDLE_ON_ETH == XcpConfigInfoPtr->Connections[EthPduId].XcpTpType) )
        {
            Xcp_ActiveLink.XcpTpHandle = XCP_PRO_HANDLE_ON_ETH;
            Xcp_ActiveLink.XcpRxPduId = EthPduId;
            Xcp_ActiveLink.XcpTxPduId = XcpConfigInfoPtr->Connections[EthPduId].XcpTxPduId;
            Xcp_ActiveLink.XcpTxConfirmationPduId = EthPduId;
            tem_Ret = E_OK;
        }
    }
    else
    {
        if ( (XCP_PRO_HANDLE_ON_ETH == Xcp_ActiveLink.XcpTpHandle)
                && (EthPduId == Xcp_ActiveLink.XcpRxPduId) )
        {
            tem_Ret = E_OK;
        }
    }

    return tem_Ret;
}
#define XCP_STOP_SEC_CODE
#include "MemMap.h"


/*******************************************************************************
*   global function Define
*******************************************************************************/
#define XCP_START_SEC_CODE
#include "MemMap.h"

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name : Xcp_SoAdIfRxIndication
*
* Description   : This function is called by the lower layers(i.e. FlexRay Interface, TTCAN Interface
*                 and Socket Adaptor or CDD) when an AUTOSAR XCP PDU has been received
*
* Inputs        : XcpRxPduId:PDU-ID that has been received
*                 XcpRxPduPtr:Pointer to SDU (Buffer of received payload)
*
* Outputs       : None
*
* Limitations   : None
********************************************************************************
END_FUNCTION_HDR */
FUNC (void, XCP_CODE) Xcp_SoAdIfRxIndication
(
    PduIdType XcpRxPduId,
    P2CONST (PduInfoType, AUTOMATIC, XCP_APPL_DATA) XcpRxPduPtr
)
{
    Std_ReturnType tem;
    uint16 i;


    if (STD_UNINITIALIZED == Xcp_State)
    {
        XCP_DET_REPORT_ERROR (XCP_RXIND_APIID, XCP_E_NOT_INITIALIZED);
    }
    else if (NULL_PTR == XcpRxPduPtr)
    {
        XCP_DET_REPORT_ERROR (XCP_RXIND_APIID, XCP_E_INV_POINTER);
    }
    else if (XcpRxPduPtr->SduLength < XCP_RX_ETH_MESSAGE_MIN_LENGTH)
    {
        XCP_DET_REPORT_ERROR (XCP_RXIND_APIID, XCP_E_INVALID_PDULEN);
    }
    {
        /* check if can link to eth
           the follow confition,will link fail,this request will be ignore:
           1.other tp like eth flexray is linking
           2.can is linking, but not the same can pdu

           if link fail, xcp will not give any responce
        */
        tem = Xcp_CheckEthLink (XcpRxPduId);

        if (E_OK == tem)
        {
            /* copy data */
            for (i = 0; i < XcpRxPduPtr->SduLength; i++)
            {
                Xcp_RxData[i] = XcpRxPduPtr->SduDataPtr[i];
            }

            Xcp_RxPduLength =  XcpRxPduPtr->SduLength;

            Xcp_RxIndication();
        }
        else
        {
            XCP_DET_REPORT_ERROR (XCP_RXIND_APIID, XCP_E_INVALID_PDUID);
        }
    }
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name : Xcp_SoAdIfTxConfirmation
*
* Description   : This function is called by the lower layers(i.e. FlexRay Interface, TTCAN Interface
*                 and Socket Adaptor or CDD) when an AUTOSAR XCP PDU has been transmitted
*
* Inputs        : XcpRxPduId:PDU-ID that has been transmitted
*
* Outputs       : None
*
* Limitations   : None
********************************************************************************
END_FUNCTION_HDR */
FUNC (void, XCP_CODE) Xcp_SoAdIfTxConfirmation
(
    PduIdType XcpTxPduId
)
{
    if (STD_UNINITIALIZED == Xcp_State)
    {
        XCP_DET_REPORT_ERROR (XCP_TXCONF_APIID, XCP_E_NOT_INITIALIZED);
    }
    else if (Xcp_ActiveLink.XcpTxConfirmationPduId != XcpTxPduId)
    {
        XCP_DET_REPORT_ERROR (XCP_TXCONF_APIID, XCP_E_INVALID_PDUID);
    }
    else
    {
        Xcp_TxConfirmation();
    }
}

#define XCP_STOP_SEC_CODE
#include "MemMap.h"

#endif

