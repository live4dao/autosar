/*  BEGIN_FILE_HDR
********************************************************************************
*     NOTICE
*     This software is the property of HiRain Technologies. Any information
*     contained in this doc should not be reproduced, or used, or disclosed
*     without the written authorization from HiRain Technologies.
********************************************************************************
*     File Name       : PduR_LinIf.h
********************************************************************************
*     Project/Product : AUTOSAR 4.2
*     Title           : PduR_LinIf.h
*     Author          : Hirain
********************************************************************************
*     Description     : The header file PduR_LinIf.h contains the declaration of
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
#ifndef PDUR_LINIF_H
#define PDUR_LINIF_H

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

#if(STD_ON == PDUR_LINIF_MODULE_SUPPORT)
extern FUNC(void, PDUR_CODE) PduR_LinIfRxIndication
(
    PduIdType RxPduId,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_CONST) PduInfoPtr
);

extern FUNC(void, PDUR_CODE) PduR_LinIfTxConfirmation
(
    PduIdType TxPduId
);

extern FUNC(Std_ReturnType, PDUR_CODE) PduR_LinIfTriggerTransmit
(
    PduIdType TxPduId,
    P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) PduInfoPtr
);
#endif

#define PDUR_STOP_SEC_CODE
#include "MemMap.h"

#endif/*PDUR_LINIF_H*/

