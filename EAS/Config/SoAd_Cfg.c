/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : SoAd_PBcfg.c
********************************************************************************
*   Project/Product : AUTOSAR BSW PROJECT
*   Title           : SoAd module configuration File
*   Author          : Hirain
********************************************************************************
*   Description     : SoAd module configuration File
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
*   V1.0.0_3.5.5_AZ240046       27/03/2024    Eas           N/A          N/A
*
********************************************************************************
* END_FILE_HDR*/
#include "SoAd_Cfg.h"
#include "SoAd_Types.h"

/* Include the header file of UpLayer Callback*/
#include "DoIP_Cbk.h"
#include "UdpNm_Cbk.h"
#include "PduR_SoAd.h"
#include "XcpOnEth_Cbk.h"

/*******************************************************************************
*   Macro
*******************************************************************************/

#define SOAD_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"
/*******************************************************************************
*   Global Data Define
*******************************************************************************/
/* ECUC_SoAd_00102 */
CONST(SoAd_UpLayerInterfaceType, SOAD_CONST) SoAd_UpLayerInterfaces[SOAD_UL_MAX] =
{
    {
        /*<Up>_SoConModeChg*/
        DoIP_SoConModeChg,
        /*<Up>_LocalIpAddrAssignmentChg*/
        DoIP_LocalIpAddrAssignmentChg,
        /*IF Interfaces*/
        /*<Up>_IfRxIndication*/
        DoIP_SoAdIfRxIndication,
        /*<Up>IfTriggerTransmit*/
        NULL_PTR,
        /*<Up>_IfTxConfirmation*/
        DoIP_SoAdIfTxConfirmation,
        /*TP Interfaces*/
        /*<Up>_CopyTxData*/
        DoIP_SoAdTpCopyTxData,
        /*<Up>_TpTxConfirmation*/
        DoIP_SoAdTpTxConfirmation,
        /*<Up>_StartOfReception*/
        DoIP_SoAdTpStartOfReception,
        /*<Up>_CopyRxData*/
        DoIP_SoAdTpCopyRxData,
        /*<Up>_TpRxIndication*/
        DoIP_SoAdTpRxIndication
    },
    {
        /*<Up>_SoConModeChg*/
        NULL_PTR,
        /*<Up>_LocalIpAddrAssignmentChg*/
        NULL_PTR,
        /*IF Interfaces*/
        /*<Up>_IfRxIndication*/
        UdpNm_SoAdIfRxIndication,
        /*<Up>IfTriggerTransmit*/
        NULL_PTR,
        /*<Up>_IfTxConfirmation*/
        UdpNm_SoAdIfTxConfirmation,
        /*TP Interfaces*/
        NULL_PTR,
        /*<Up>_TpTxConfirmation*/
        NULL_PTR,
        /*<Up>_StartOfReception*/
        NULL_PTR,
        /*<Up>_CopyRxData*/
        NULL_PTR,
        /*<Up>_TpRxIndication*/
        NULL_PTR
    },
    {
        /*<Up>_SoConModeChg*/
        NULL_PTR,
        /*<Up>_LocalIpAddrAssignmentChg*/
        NULL_PTR,
        /*IF Interfaces*/
        /*<Up>_IfRxIndication*/
        PduR_SoAdIfRxIndication,
        /*<Up>IfTriggerTransmit*/
        PduR_SoAdIfTriggerTransmit,
        /*<Up>_IfTxConfirmation*/
        PduR_SoAdIfTxConfirmation,
        /*TP Interfaces*/
        NULL_PTR,
        /*<Up>_TpTxConfirmation*/
        NULL_PTR,
        /*<Up>_StartOfReception*/
        NULL_PTR,
        /*<Up>_CopyRxData*/
        NULL_PTR,
        /*<Up>_TpRxIndication*/
        NULL_PTR
    },
    {
        /*<Up>_SoConModeChg*/
        NULL_PTR,
        /*<Up>_LocalIpAddrAssignmentChg*/
        NULL_PTR,
        /*IF Interfaces*/
        /*<Up>_IfRxIndication*/
        Xcp_SoAdIfRxIndication,
        /*<Up>IfTriggerTransmit*/
        NULL_PTR,
        /*<Up>_IfTxConfirmation*/
        Xcp_SoAdIfTxConfirmation,
        /*TP Interfaces*/
        NULL_PTR,
        /*<Up>_TpTxConfirmation*/
        NULL_PTR,
        /*<Up>_StartOfReception*/
        NULL_PTR,
        /*<Up>_CopyRxData*/
        NULL_PTR,
        /*<Up>_TpRxIndication*/
        NULL_PTR
    },
};

#define SOAD_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"

/******************************************************************************
*   Function Define
******************************************************************************/
#define SOAD_START_SEC_CODE
#include "MemMap.h"
FUNC(void, SOAD_CALLOUT_CODE) SoAd_SetRoutingGroup
(
    P2VAR(SoAd_RoutingGroupCtrlType, SOAD_CONST, AUTOMATIC) RoutingCtrlPtr,
    SoAd_RoutingGroupIdType GroupId,
    uint8 State
)
{
    SoAd_RoutingGroupIdType n = GroupId >> 3;
	uint8 k = (uint8)(GroupId & 0x07);
	
    /*there is only one routingGroup referenced by SocketRoute or PduRoute*/
    if((RoutingCtrlPtr->Mask[n] & (1 << k)) > 0)
    {
    	if(State == SOAD_ROUTING_GROUP_ENABLED)
    	{
    		RoutingCtrlPtr->RoutingState[n] |= (1 << k);
    	}
    	else
    	{
    		RoutingCtrlPtr->RoutingState[n] &= ((uint8)~(1 << k));
    	}
    }
}

FUNC(Std_ReturnType, SOAD_CALLOUT_CODE) SoAd_IsEnabledRouting
(
    P2CONST(SoAd_RoutingGroupCtrlType, SOAD_CONST, AUTOMATIC) RoutingCtrlPtr
)
{
    uint8 i;
    Std_ReturnType ret = E_NOT_OK;

    if(NULL_PTR == RoutingCtrlPtr)
    {
        ret = E_OK;
    }
    else
    {
        for(i = 0; i < SOAD_ROUTINGGROUP_MASK_LEN; i++)
        {
            if((RoutingCtrlPtr->RoutingState[i] & RoutingCtrlPtr->Mask[i]) > 0)
            {
                 ret = E_OK;
                 break;
            }
        }
    }
    return ret;
}
#define SOAD_STOP_SEC_CODE
#include "MemMap.h"

