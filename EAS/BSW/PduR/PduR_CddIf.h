/*  BEGIN_FILE_HDR
********************************************************************************
*     NOTICE
*     This software is the property of HiRain Technologies. Any information
*     contained in this doc should not be reproduced, or used, or disclosed
*     without the written authorization from HiRain Technologies.
********************************************************************************
*     File Name       : PduR_CddIf.h
********************************************************************************
*     Project/Product : AUTOSAR 4.2
*     Title           : PduR_CddIf.h
*     Author          : Hirain
********************************************************************************
*     Description     : The header file PduR_CddIf.h contains the declaration of
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
#ifndef PDUR_CDDIF_H
#define PDUR_CDDIF_H

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

#if(STD_ON == PDUR_CDDIF_MODULE_SUPPORT)
extern FUNC(void, PDUR_CODE) PduR_CddIfRxIndication
(
    PduIdType RxPduId,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_CONST) PduInfoPtr
);

extern FUNC(void, PDUR_CODE) PduR_CddIfTxConfirmation
(
    PduIdType TxPduId
);
#endif

#define PDUR_STOP_SEC_CODE
#include "MemMap.h"

#endif/*PDUR_CDDIF_H*/

