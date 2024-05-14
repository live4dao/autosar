/*  BEGIN_FILE_HDR
********************************************************************************
*     NOTICE
*     This software is the property of HiRain Technologies. Any information
*     contained in this doc should not be reproduced, or used, or disclosed
*     without the written authorization from HiRain Technologies.
********************************************************************************
*     File Name       : PduR_CanIf.h
********************************************************************************
*     Project/Product : AUTOSAR 4.2
*     Title           : PduR_CanIf.h
*     Author          : Hirain
********************************************************************************
*     Description     : The header file PduR_CanIf.h contains the declaration of
*                       functions which is called by the CanIf module
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
#ifndef PDUR_CANIF_H
#define PDUR_CANIF_H

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

#if(STD_ON == PDUR_CANIF_MODULE_SUPPORT)
extern FUNC(void, PDUR_CODE) PduR_CanIfRxIndication
(
    PduIdType RxPduId,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_CONST) PduInfoPtr
);

extern FUNC(void, PDUR_CODE) PduR_CanIfTxConfirmation
(
    PduIdType TxPduId
);
#endif

#define PDUR_STOP_SEC_CODE
#include "MemMap.h"

#endif/*PDUR_CANIF_H*/

