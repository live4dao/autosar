/*  BEGIN_FILE_HDR
********************************************************************************
*     NOTICE
*     This software is the property of HiRain Technologies. Any information
*     contained in this doc should not be reproduced, or used, or disclosed
*     without the written authorization from HiRain Technologies.
********************************************************************************
*     File Name         : PduR_Com.h
********************************************************************************
*     Project/Product : AUTOSAR 4.2
*     Title             : PduR_Com.h
*     Author          : Hirain
********************************************************************************
*     Description     : The header file PduR_Com.h contains the declaration of
*                       functions which is called by the Com module
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
#ifndef PDUR_COM_H
#define PDUR_COM_H

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

#if(STD_ON == PDUR_COM_MODULE_SUPPORT)
#if(STD_OFF == PDUR_ZERO_COST_OPERATION)
extern FUNC(Std_ReturnType, PDUR_CODE) PduR_ComTransmit
(
    PduIdType id,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_CONST) info
);

extern FUNC(Std_ReturnType, PDUR_CODE) PduR_ComCancelTransmit
(
    PduIdType id
);
#else
extern CONST(PduIdType, PDUR_CONST) PduRComToCanIfIdTable[PDUR_NUMOFCOMTXPDU];
#define PduR_ComTransmit(id, info)    CanIf_Transmit((PduRComToCanIfIdTable[id]), (info))
#endif
#endif

#define PDUR_STOP_SEC_CODE
#include "MemMap.h"

#endif/* PDUR_COM_H */

