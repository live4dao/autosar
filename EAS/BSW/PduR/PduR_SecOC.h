/*  BEGIN_FILE_HDR
********************************************************************************
*     NOTICE
*     This software is the property of HiRain Technologies. Any information
*     contained in this doc should not be reproduced, or used, or disclosed
*     without the written authorization from HiRain Technologies.
********************************************************************************
*     File Name       : PduR_SecOC.h
********************************************************************************
*     Project/Product : AUTOSAR 4.2
*     Title           : PduR_SecOC.h
*     Author          : Hirain
********************************************************************************
*     Description     : The header file PduR_SecOC.h contains the declaration of
*                       functions which is called by the SecOC module
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
#ifndef PDUR_SECOC_H
#define PDUR_SECOC_H

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

#if(STD_ON == PDUR_SECOC_MODULE_SUPPORT)
extern FUNC(Std_ReturnType, PDUR_CODE) PduR_SecOCTransmit
(
    PduIdType id,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_CONST) info
);

extern FUNC(Std_ReturnType, PDUR_CODE) PduR_SecOCCancelTransmit
(
    PduIdType id
);
extern FUNC(Std_ReturnType, PDUR_CODE) PduR_SecOCCancelReceive
(
    PduIdType id
);
#endif

#if(STD_ON == PDUR_SECOCIF_MODULE_SUPPORT)
extern FUNC(void, PDUR_CODE) PduR_SecOCIfTxConfirmation
(
    PduIdType TxPduId
);
extern FUNC(void, PDUR_CODE) PduR_SecOCIfRxIndication
(
    PduIdType RxPduId,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_CONST) PduInfoPtr
);
#endif

#if(STD_ON == PDUR_SECOCTP_MODULE_SUPPORT)

extern FUNC(BufReq_ReturnType, PDUR_CODE) PduR_SecOCStartOfReception
(
    PduIdType id,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_CONST) info,
    PduLengthType TpSduLength,
    P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) bufferSizePtr
);

extern FUNC(void, PDUR_CODE) PduR_SecOCTpTxConfirmation
(
    PduIdType id,
    Std_ReturnType result
);

extern FUNC(BufReq_ReturnType, PDUR_CODE) PduR_SecOCTpCopyRxData
(
    PduIdType id,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info,
    P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) bufferSizePtr
);

extern FUNC(BufReq_ReturnType, PDUR_CODE) PduR_SecOCTpCopyTxData
(
    PduIdType id,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info,
    P2VAR(RetryInfoType, AUTOMATIC, PDUR_APPL_DATA) retry,
    P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) availableDataPtr
);

extern FUNC(void, PDUR_CODE) PduR_SecOCTpRxIndication
(
    PduIdType id,
    Std_ReturnType result
);
#endif


#define PDUR_STOP_SEC_CODE
#include "MemMap.h"

#endif/* PDUR_SECOC_H */

