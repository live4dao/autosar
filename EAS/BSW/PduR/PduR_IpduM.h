/*  BEGIN_FILE_HDR
********************************************************************************
*     NOTICE
*     This software is the property of HiRain Technologies. Any information
*     contained in this doc should not be reproduced, or used, or disclosed
*     without the written authorization from HiRain Technologies.
********************************************************************************
*     File Name         : PduR_IpduM.h
********************************************************************************
*     Project/Product : AUTOSAR 4.2
*     Title             : PduR_IpduM.h
*     Author          : Hirain
********************************************************************************
*     Description     : The header file PduR_IpduM.h contains the declaration of
*                       functions which is called by the IpduM module
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
#ifndef PDUR_IPDUM_H
#define PDUR_IPDUM_H

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

#if(STD_ON == PDUR_IPDUM_MODULE_SUPPORT)
extern FUNC(void, PDUR_CODE) PduR_IpduMRxIndication
(
    PduIdType RxPduId,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_CONST) PduInfoPtr
);

extern FUNC(Std_ReturnType, PDUR_CODE) PduR_IpduMTransmit
(
    PduIdType id,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_CONST) info
);

extern FUNC(void, PDUR_CODE) PduR_IpduMTxConfirmation
(
    PduIdType TxPduId
);

extern FUNC(Std_ReturnType, PDUR_CODE) PduR_IpduMTriggerTransmit
(
    PduIdType TxPduId,
    P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) PduInfoPtr
);

#endif

#define PDUR_STOP_SEC_CODE
#include "MemMap.h"

#endif/* PDUR_IPDUM_H */

