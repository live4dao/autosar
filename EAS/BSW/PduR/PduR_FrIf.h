/*  BEGIN_FILE_HDR
********************************************************************************
*     NOTICE
*     This software is the property of HiRain Technologies. Any information
*     contained in this doc should not be reproduced, or used, or disclosed
*     without the written authorization from HiRain Technologies.
********************************************************************************
*     File Name         : PduR_FrIf.h
********************************************************************************
*     Project/Product : AUTOSAR 4.2
*     Title             : PduR_FrIf.h
*     Author          : Hirain
********************************************************************************
*     Description     : The header file PduR_FrIf.h contains the declaration of
*                       functions which is called by the FrIf module
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
#ifndef PDUR_FRIF_H
#define PDUR_FRIF_H

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

#if(STD_ON == PDUR_FRIF_MODULE_SUPPORT)
extern FUNC(void, PDUR_CODE) PduR_FrIfRxIndication
(
    PduIdType RxPduId,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_CONST) PduInfoPtr
);

extern FUNC(void, PDUR_CODE) PduR_FrIfTxConfirmation
(
    PduIdType TxPduId
);

extern FUNC(Std_ReturnType, PDUR_CODE) PduR_FrIfTriggerTransmit
(
    PduIdType TxPduId,
    P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) PduInfoPtr
);

#endif

#define PDUR_STOP_SEC_CODE
#include "MemMap.h"

#endif/* PDUR_FRIF_H */

