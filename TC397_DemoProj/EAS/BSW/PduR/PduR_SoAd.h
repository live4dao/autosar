/*  BEGIN_FILE_HDR
********************************************************************************
*      NOTICE
*      This software is the property of HiRain Technologies. Any information
*      contained in this doc should not be reproduced, or used, or disclosed
*      without the written authorization from HiRain Technologies.
********************************************************************************
*      File Name       : PduR_SoAd.h
********************************************************************************
*      Project/Product : AUTOSAR 4.2
*      Title           : PduR_SoAd.h
*      Author          : Hirain
********************************************************************************
*      Description      : The header file PduR_SoAd.h contains the declaration of
*                        functions which is called by the SoAd module
*
********************************************************************************
*      Limitations      : None
*
********************************************************************************
*
********************************************************************************
*      Revision History:
*      Reference to Core C File
********************************************************************************
* END_FILE_HDR*/
#ifndef PDUR_SOAD_H
#define PDUR_SOAD_H

/*******************************************************************************
*     Includes
*******************************************************************************/
#include "PduR_Types.h"
#include "PduR_Version.h"

/*******************************************************************************
*     Function Declaration
*******************************************************************************/
#define PDUR_START_SEC_CODE
#include "MemMap.h"

#if(STD_ON == PDUR_SOADIF_MODULE_SUPPORT)
extern FUNC(void, PDUR_CODE) PduR_SoAdIfRxIndication
(
    PduIdType RxPduId,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) PduInfoPtr
);

extern FUNC(void, PDUR_CODE) PduR_SoAdIfTxConfirmation
(
    PduIdType TxPduId
);

extern FUNC(Std_ReturnType, PDUR_CODE) PduR_SoAdIfTriggerTransmit
(
    PduIdType TxPduId,
    P2VAR(PduInfoType, AUTOMATIC, PDUR_CONST) PduInfoPtr
);

#endif

#if(STD_ON == PDUR_SOADTP_MODULE_SUPPORT)
extern FUNC(BufReq_ReturnType, PDUR_CODE) PduR_SoAdTpCopyRxData
(
    PduIdType id,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_CONST) info,
    P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) bufferSizePtr
);

extern FUNC(void, PDUR_CODE) PduR_SoAdTpRxIndication
(
    PduIdType id,
    Std_ReturnType result
);

extern FUNC(BufReq_ReturnType, PDUR_CODE) PduR_SoAdTpStartOfReception
(
    PduIdType id,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info,
    PduLengthType TpSduLength,
    P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) bufferSizePtr
);

extern FUNC(void, PDUR_CODE) PduR_SoAdTpTxConfirmation
(
    PduIdType id,
    Std_ReturnType result
);

extern FUNC(BufReq_ReturnType, PDUR_CODE) PduR_SoAdTpCopyTxData
(
    PduIdType id,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info,
    P2VAR(RetryInfoType, AUTOMATIC, PDUR_APPL_DATA) retry,
    P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) availableDataPtr
);

#endif


#define PDUR_STOP_SEC_CODE
#include "MemMap.h"

#endif/* PDUR_SOAD_H */

