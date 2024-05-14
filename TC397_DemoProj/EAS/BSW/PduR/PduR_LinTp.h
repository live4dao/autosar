/*  BEGIN_FILE_HDR
********************************************************************************
*     NOTICE
*     This software is the property of HiRain Technologies. Any information
*     contained in this doc should not be reproduced, or used, or disclosed
*     without the written authorization from HiRain Technologies.
********************************************************************************
*     File Name       : PduR_LinTp.h
********************************************************************************
*     Project/Product : AUTOSAR 4.2
*     Title           : PduR_LinTp.h
*     Author          : Hirain
********************************************************************************
*     Description     : The header file PduR_LinTp.h contains the declaration of
*                       functions which is called by the LinIf module
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
#ifndef PDUR_LINTP_H
#define PDUR_LINTP_H

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

#if(STD_ON == PDUR_LINTP_MODULE_SUPPORT)
extern FUNC(BufReq_ReturnType, PDUR_CODE) PduR_LinTpCopyRxData
(
    PduIdType id,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_CONST) info,
    P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) bufferSizePtr
);

extern FUNC(void, PDUR_CODE) PduR_LinTpRxIndication
(
    PduIdType id,
    Std_ReturnType result
);

extern FUNC(BufReq_ReturnType, PDUR_CODE) PduR_LinTpStartOfReception
(
    PduIdType id,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info,
    PduLengthType TpSduLength,
    P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) bufferSizePtr
);

extern FUNC(void, PDUR_CODE) PduR_LinTpTxConfirmation
(
    PduIdType id,
    Std_ReturnType result
);

extern FUNC(BufReq_ReturnType, PDUR_CODE) PduR_LinTpCopyTxData
(
    PduIdType id,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info,
    P2VAR(RetryInfoType, AUTOMATIC, PDUR_APPL_DATA) retry,
    P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) availableDataPtr
);
#endif

#define PDUR_STOP_SEC_CODE
#include "MemMap.h"

#endif/*PDUR_LINTP_H*/

