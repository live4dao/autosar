/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
*   File Name       : XcpOnEth.c
********************************************************************************
*   Project/Product : AUTOSAR 4.2
*   Title           : XcpOnEth module source File
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
*   local Data Define
*******************************************************************************/


/*******************************************************************************
*   Global Function Define
*******************************************************************************/
#define XCP_START_SEC_CODE
#include "MemMap.h"

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name : Xcp_TransmitOnEth
*
* Description   : This service transmit the DTO to Ethernet Bus.
*
* Inputs        : None
*
* Outputs       : Std_ReturnType
*
* Limitations   : None
********************************************************************************
END_FUNCTION_HDR */

/*******************************************************************************
* PRQA S 3673 MISRA-C:2004 Rule 16.7
* Transmit function must fufill XcpTxFunctionNameDef type. As Can transmit may
* write pduInfo's data ,so pduInfo cannot be const type.
* This part of code is verified manually and has no impact.
*******************************************************************************/

FUNC(Std_ReturnType, XCP_CODE) Xcp_TransmitOnEth
(
    CONSTP2VAR(PduInfoType, AUTOMATIC, XCP_VAR_NOINIT) pduInfo
)
{
    uint16 tem_Dlc;
    uint16 tem_Ctr;
    PduInfoType tem_EthPdu;
    Std_ReturnType tem_Ret;

    /*******************************************************************
    * PRQA S 506
    * Dereferencing pointer value that is possibly NULL.
    * this function is only used in Xcp internal,Xcp will ensure that
    * pduInfo is valid
    * This part of code is verified manually and has no impact.
    ******************************************************************/
    tem_Dlc = pduInfo->SduLength;

    tem_EthPdu.SduLength =  (tem_Dlc + Xcp_TpProConfig[Xcp_ActiveLink.XcpTpHandle].Header);
    tem_EthPdu.SduDataPtr = pduInfo->SduDataPtr;

    /*******************************************************************
    * PRQA S 3120
    * Hard-coded 'magic' integer constant used.
    * these numbers are only used here to make eth packet header,
    * not necessary to define macro
    * This part of code is verified manually and has no impact.
    ******************************************************************/

    /* fullfill eth length of header, intel format */
    tem_EthPdu.SduDataPtr[0] = (uint8)(tem_Dlc >> 0);
    tem_EthPdu.SduDataPtr[1] = (uint8)(tem_Dlc >> 8);

    /* fullfill Eth CTR of header, intel format */
    tem_Ctr = tem_EthPdu.SduDataPtr[3];
    tem_Ctr = tem_Ctr << 8;
    tem_Ctr = tem_Ctr | tem_EthPdu.SduDataPtr[2];

    /* reset to 0 when reach ffff */
    tem_Ctr++;
    tem_EthPdu.SduDataPtr[2] = (uint8)(tem_Ctr >> 0);
    tem_EthPdu.SduDataPtr[3] = (uint8)(tem_Ctr >> 8);

    tem_Ret = SoAd_IfTransmit(Xcp_ActiveLink.XcpTxPduId, &tem_EthPdu);
    return tem_Ret;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name : Xcp_InitEth
*
* Description   : This function is used to Init the Xcp on Eth.
*
* Inputs        : None

* Outputs       : None
*
* Limitations   : None
********************************************************************************
END_FUNCTION_HDR */
FUNC(void, XCP_CODE) Xcp_InitEth(void)
{
    /*udp socket connections*/
    Std_ReturnType tem_Ret = E_OK;
    uint8 i;
    SoAd_SoConIdType SoConId = 0;

    /*******************************************************************
    * PRQA S 506
    * Dereferencing pointer value that is possibly NULL.
    * this function is only used in Xcp internal,Xcp will ensure that
    * XcpConfigInfoPtr is valid
    * This part of code is verified manually and has no impact.
    ******************************************************************/

    for(i = 0; i < XcpConfigInfoPtr->NumOfConnections; i++)
    {
        if(XCP_PRO_HANDLE_ON_ETH == XcpConfigInfoPtr->Connections[i].XcpTpType)
        {
            if(E_OK == SoAd_GetSoConId(XcpConfigInfoPtr->Connections[i].XcpTxPduId, &SoConId))
            {
                if(E_NOT_OK == SoAd_OpenSoCon(SoConId))
                {
                    tem_Ret = E_NOT_OK;
                    break;
                }
            }
            else
            {
                tem_Ret = E_NOT_OK;
                break;
            }
        }
    }

    if(E_NOT_OK == tem_Ret)
    {
        /* reprot deterror*/
        XCP_DET_REPORT_ERROR(XCP_INIT_APIID, XCP_E_NOT_INITIALIZED);
    }
}

#define XCP_STOP_SEC_CODE
#include "MemMap.h"

#endif

