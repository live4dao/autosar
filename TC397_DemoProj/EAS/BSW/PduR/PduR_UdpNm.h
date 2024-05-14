/*  BEGIN_FILE_HDR
********************************************************************************
*     NOTICE
*     This software is the property of HiRain Technologies. Any information
*     contained in this doc should not be reproduced, or used, or disclosed
*     without the written authorization from HiRain Technologies.
********************************************************************************
*     File Name         : PduR_UdpNm.h
********************************************************************************
*     Project/Product : AUTOSAR 4.2
*     Title             : PduR_UdpNm.h
*     Author          : Hirain
********************************************************************************
*     Description     : The header file PduR_UdpNm.h contains the declaration of
*                       functions which is called by the UdpNm module
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
#ifndef PDUR_UDPNM_H
#define PDUR_UDPNM_H

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

#if(STD_ON == PDUR_UDPNM_MODULE_SUPPORT)
#if(STD_OFF == PDUR_ZERO_COST_OPERATION)
extern FUNC(void, PDUR_CODE) PduR_UdpNmRxIndication
(
    PduIdType RxPduId,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_CONST) PduInfoPtr
);

extern FUNC(void, PDUR_CODE) PduR_UdpNmTxConfirmation
(
    PduIdType TxPduId
);

extern FUNC(Std_ReturnType, PDUR_CODE) PduR_UdpNmTriggerTransmit
(
    PduIdType TxPduId,
    P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) PduInfoPtr
);
#else
extern CONST(PduIdType, PDUR_CONST) PduRUdpNmToComIdTable[PDUR_NUMOFUDPNMRXPDU];
extern CONST(PduIdType, PDUR_CONST) PduRComToUdpNmTxConfIdTable[PDUR_NUMOFUDPNMTXPDU];
extern CONST(PduIdType, PDUR_CONST) PduRComToUdpNmIdTable[PDUR_NUMOFCANTPRXPDU];

#define PduR_UdpNmRxIndication(RxPduId, PduInfoPtr)      Com_RxIndication((PduRUdpNmToComIdTable[RxPduId]), (PduInfoPtr))
#define PduR_UdpNmTxConfirmation(TxPduId)  Com_TxConfirmation((PduRComToUdpNmTxConfIdTable[TxPduId]))
#define PduR_UdpNmTriggerTransmit(TxPduId, PduInfoPtr)  Com_TriggerTransmit((PduRComToUdpNmIdTable[TxPduId]), (PduInfoPtr))
#endif
#endif

#define PDUR_STOP_SEC_CODE
#include "MemMap.h"

#endif/* PDUR_UDPNM_H */

