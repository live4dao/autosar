/*  BEGIN_FILE_HDR
********************************************************************************
*     NOTICE
*     This software is the property of HiRain Technologies. Any information
*     contained in this doc should not be reproduced, or used, or disclosed
*     without the written authorization from HiRain Technologies.
********************************************************************************
*     File Name         : PduR_DoIP.h
********************************************************************************
*     Project/Product : AUTOSAR 4.2
*     Title             : PduR_DoIP.h
*     Author          : Hirain
********************************************************************************
*     Description     : The header file PduR_DoIP.h contains the declaration of
*                       functions which is called by the DoIP module
*
********************************************************************************
*     Limitations     : None
*
********************************************************************************
*
********************************************************************************
*     Revision History:
*     Reference to Core C File
********************************************************************************
* END_FILE_HDR*/
#ifndef PDUR_DOIP_H
#define PDUR_DOIP_H

/*******************************************************************************
*   Includes
*******************************************************************************/
#include "PduR_Types.h"
#include "PduR_Version.h"

/*******************************************************************************
*   Function Declaration
*******************************************************************************/
#define PDUR_START_SEC_CODE
#include "MemMap.h"

#if(STD_ON == PDUR_DOIPTP_MODULE_SUPPORT)
extern FUNC(BufReq_ReturnType, PDUR_CODE) PduR_DoIPTpStartOfReception
(
    PduIdType id,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_CONST) info,
    PduLengthType TpSduLength,
    P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) bufferSizePtr
);

extern FUNC(BufReq_ReturnType, PDUR_CODE) PduR_DoIPTpCopyRxData
(
    PduIdType id,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info,
    P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) bufferSizePtr
);

extern FUNC(void, PDUR_CODE) PduR_DoIPTpRxIndication
(
    PduIdType id,
    Std_ReturnType result
);

extern FUNC(BufReq_ReturnType, PDUR_CODE) PduR_DoIPTpCopyTxData
(
    PduIdType id,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info,
    P2VAR(RetryInfoType, AUTOMATIC, PDUR_APPL_DATA) retry,
    P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) availableDataPtr
);

extern FUNC(void, PDUR_CODE) PduR_DoIPTpTxConfirmation
(
    PduIdType id,
    Std_ReturnType result
);

#endif

#if(STD_ON == PDUR_DOIPIF_MODULE_SUPPORT)
extern FUNC(void, PDUR_CODE) PduR_DoIPIfTxConfirmation
(
    PduIdType TxPduId
);
#endif

#define PDUR_STOP_SEC_CODE
#include "MemMap.h"

#endif/* PDUR_DOIP_H */

