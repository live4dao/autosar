/*  BEGIN_FILE_HDR
********************************************************************************
*     NOTICE
*     This software is the property of HiRain Technologies. Any information
*     contained in this doc should not be reproduced, or used, or disclosed
*     without the written authorization from HiRain Technologies.
********************************************************************************
*     File Name         : PduR_CanTp.h
********************************************************************************
*     Project/Product : AUTOSAR 4.2
*     Title             : PduR_CanTp.h
*     Author          : Hirain
********************************************************************************
*     Description     : The header file PduR_CanTp.h contains the declaration of
*                       functions which is called by the CanTp module
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
#ifndef PDUR_CANTP_H
#define PDUR_CANTP_H

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

#if(STD_ON == PDUR_CANTP_MODULE_SUPPORT)
#if(STD_OFF == PDUR_ZERO_COST_OPERATION)
extern FUNC(BufReq_ReturnType, PDUR_CODE) PduR_CanTpStartOfReception
(
    PduIdType id,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_CONST) info,
    PduLengthType TpSduLength,
    P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) bufferSizePtr
);

extern FUNC(BufReq_ReturnType, PDUR_CODE) PduR_CanTpCopyRxData
(
    PduIdType id,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info,
    P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) bufferSizePtr
);

extern FUNC(void, PDUR_CODE) PduR_CanTpRxIndication
(
    PduIdType id,
    Std_ReturnType result
);

extern FUNC(BufReq_ReturnType, PDUR_CODE) PduR_CanTpCopyTxData
(
    PduIdType id,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info,
    P2VAR(RetryInfoType, AUTOMATIC, PDUR_APPL_DATA) retry,
    P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) availableDataPtr
);

extern FUNC(void, PDUR_CODE) PduR_CanTpTxConfirmation
(
    PduIdType id,
    Std_ReturnType result
);
#else
extern CONST(PduIdType, PDUR_CONST) PduRDcmToCanTpTxConfIdTable[PDUR_NUMOFCANTPTXPDU];
extern CONST(PduIdType, PDUR_CONST) PduRCanTpToDcmIdTable[PDUR_NUMOFCANTPRXPDU];

#define PduR_CanTpTxConfirmation(id, result)      Dcm_TpTxConfirmation((PduRDcmToCanTpTxConfIdTable[id]), (result))
#define PduR_CanTpCopyTxData(id, info, retry, avalableDataPtr)  Dcm_CopyTxData((PduRDcmToCanTpTxConfIdTable[id]), (info), (retry), (avalableDataPtr))
#define PduR_CanTpStartOfReception(id, info, TpSduLength, bufferSizePtr)  Dcm_StartOfReception((PduRCanTpToDcmIdTable[id]), (info), (TpSduLength), (bufferSizePtr))
#define PduR_CanTpCopyRxData(id, info, bufferSizePtr)  Dcm_CopyRxData((PduRCanTpToDcmIdTable[id]), (info), (bufferSizePtr))
#define PduR_CanTpRxIndication(id, result)  Dcm_TpRxIndication((PduRCanTpToDcmIdTable[id]), (result))
#endif
#endif

#define PDUR_STOP_SEC_CODE
#include "MemMap.h"

#endif/* PDUR_CANTP_H */

