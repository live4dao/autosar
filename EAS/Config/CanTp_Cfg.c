/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : CanTp_Cfg.c
********************************************************************************
*   Project/Product : AUTOSAR BSW PROJECT
*   Title           : CanTp module configuration File
*   Author          : Hirain
********************************************************************************
*   Description     : CanTp module configuration File
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


/*******************************************************************************
*   Includes
*******************************************************************************/
#include "CanTp_PBcfg.h"
#include "CanIf.h"
#include "PduR_CanTp.h"

/*****************************************************************************
 *  General QAC Suppression
 *****************************************************************************/
/*PRQA S 862,3214,3614 EOF*/
/*
According to the requirements of AUTOSAR Specification,when locating address 
segments in the files of each module,#include "MemMap.h" is required.Defined 
XXX_START_SEC_ will undefine in MemMap.h
*/

/*PRQA S 3132,3211,3111,2213 EOF*/
/*
Particularity of configuration files
*/

#define CANTP_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"


/*******************************************************************************
*   RxNsdu 
*******************************************************************************/
CONST(CanTp_RxNsduCfgType, CANTP_CONST) CanTp_RxNsduCfgInfo[CANTP_NUM_RX_SDUS] =
{
    /* NSDU ID 0:RxNSdu_UDS_PhyDiagReq_ADAS */
    {
        (CanTp_ChannelIdType)0,    /* Tp Channel Num */
        CanTp_CanConfigSet_Rx_ACAN_UDS_PhyDiagReq_ADAS,    /* CANTP_RXNPDU_ID; from  CanIf */
        CanIf_CanConfigSet_Tx_ACAN_UDS_DiagResp_ADAS,    /* CANTP_TXFC_NPDU_ID; to CanIf */
        PduR_CanTp_CanConfigSet_Rx_ACAN_UDS_PhyDiagReq_ADAS,    /* to PduR */
        (uint16)14,    /* CANTP_NAR */
        (uint16)14,    /* CANTP_NBR (N_Br+N_Ar) < 0.9*N_Bs */
        (uint16)30,    /* CANTP_NCR */
        (uint8)8,    /* CANTP_BS */
        (uint8)20,    /* CANTP_STMIN */
        (uint8)0,    /* CANTP_WFTMAX */
        (uint8)8,
        CANTP_PHYSICAL,    
    },
    /* NSDU ID 1:RxNSdu_UDS_FuncDiagReq */
    {
        (CanTp_ChannelIdType)1,    /* Tp Channel Num */
        CanTp_CanConfigSet_Rx_ACAN_UDS_FuncDiagReq,    /* CANTP_RXNPDU_ID; from  CanIf */
        COMSTACK_INVALID_PDUID,    /* CANTP_TXFC_NPDU_ID; to CanIf */
        PduR_CanTp_CanConfigSet_Rx_ACAN_UDS_FuncDiagReq,    /* to PduR */
        (uint16)14,    /* CANTP_NAR */
        (uint16)14,    /* CANTP_NBR (N_Br+N_Ar) < 0.9*N_Bs */
        (uint16)30,    /* CANTP_NCR */
        (uint8)8,    /* CANTP_BS */
        (uint8)20,    /* CANTP_STMIN */
        (uint8)0,    /* CANTP_WFTMAX */
        (uint8)8,
        CANTP_FUNCTIONAL,    
    },
};



/*******************************************************************************
*   TxNsdu 
*******************************************************************************/
CONST(CanTp_TxNsduCfgType, CANTP_CONST) CanTp_TxNsduCfgInfo[CANTP_NUM_TX_SDUS] =
{
    /* NSDU ID 0:TxNSdu_UDS_DiagResp_ADAS */
    {
        (CanTp_ChannelIdType)0,    /* Tp Channel Num */
        CanIf_CanConfigSet_Tx_ACAN_UDS_DiagResp_ADAS,    /*  CANTP_TXNPDU_ID; to CanIf and conf from CanIf */
        CanTp_CanConfigSet_Rx_ACAN_UDS_PhyDiagReq_ADAS,    /* CANTP_RXFC_NPDU_ID; from CanIf */
        PduR_CanTp_CanConfigSet_Tx_ACAN_UDS_DiagResp_ADAS,    /* to PduR*/
        (uint16)14,    /* CANTP_NAS */
        (uint16)30,    /* CANTP_NBS (N_Br+N_Ar) < 0.9*N_Bs */
        (uint16)14,    /* CANTP_NCS */
        (PduLengthType)8, 
        CANTP_PHYSICAL,    
    },
};


#define CANTP_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"




