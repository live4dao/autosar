/*  BEGIN_FILE_HDR
********************************************************************************
*     NOTICE
*     This software is the property of HiRain Technologies. Any information
*     contained in this doc should not be reproduced, or used, or disclosed
*     without the written authorization from HiRain Technologies.
********************************************************************************
*     File Name         : PduR_CanNm.h
********************************************************************************
*     Project/Product : AUTOSAR 4.2
*     Title             : PduR_CanNm.h
*     Author          : Hirain
********************************************************************************
*     Description     : The header file PduR_CanNm.h contains the declaration of
*                       functions which is called by the CanNm module
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
#ifndef PDUR_CANNM_H
#define PDUR_CANNM_H

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

#if(STD_ON == PDUR_CANNM_MODULE_SUPPORT)
#if(STD_OFF == PDUR_ZERO_COST_OPERATION)
extern FUNC(void, PDUR_CODE) PduR_CanNmRxIndication
(
    PduIdType RxPduId,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_CONST) PduInfoPtr
);

extern FUNC(void, PDUR_CODE) PduR_CanNmTxConfirmation
(
    PduIdType TxPduId
);

extern FUNC(Std_ReturnType, PDUR_CODE) PduR_CanNmTriggerTransmit
(
    PduIdType TxPduId,
    P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) PduInfoPtr
);
#else
extern CONST(PduIdType, PDUR_CONST) PduRCanNmToComIdTable[PDUR_NUMOFCANNMRXPDU];
extern CONST(PduIdType, PDUR_CONST) PduRComToCanNmTxConfIdTable[PDUR_NUMOFCANNMTXPDU];
extern CONST(PduIdType, PDUR_CONST) PduRComToCanNmIdTable[PDUR_NUMOFCANTPRXPDU];

#define PduR_CanNmRxIndication(RxPduId, PduInfoPtr)      Com_RxIndication((PduRCanNmToComIdTable[RxPduId]), (PduInfoPtr))
#define PduR_CanNmTxConfirmation(TxPduId)  Com_TxConfirmation((PduRComToCanNmTxConfIdTable[TxPduId]))
#define PduR_CanNmTriggerTransmit(TxPduId, PduInfoPtr)  Com_TriggerTransmit((PduRComToCanNmIdTable[TxPduId]), (PduInfoPtr))
#endif
#endif

#define PDUR_STOP_SEC_CODE
#include "MemMap.h"

#endif/* PDUR_CANNM_H */

