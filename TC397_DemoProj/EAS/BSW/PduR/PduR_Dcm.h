/*  BEGIN_FILE_HDR
********************************************************************************
*     NOTICE
*     This software is the property of HiRain Technologies. Any information
*     contained in this doc should not be reproduced, or used, or disclosed
*     without the written authorization from HiRain Technologies.
********************************************************************************
*     File Name         : PduR_Dcm.h
********************************************************************************
*     Project/Product : AUTOSAR 4.2
*     Title             : PduR_Dcm.h
*     Author          : Hirain
********************************************************************************
*     Description     : The header file PduR_Dcm.h contains the declaration of
*                       functions which is called by the Dcm module
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
#ifndef PDUR_DCM_H
#define PDUR_DCM_H

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

#if(STD_ON == PDUR_DCM_MODULE_SUPPORT)
#if(STD_OFF == PDUR_ZERO_COST_OPERATION)
extern FUNC(Std_ReturnType, PDUR_CODE) PduR_DcmTransmit
(
    PduIdType id,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info
);

extern FUNC(Std_ReturnType, PDUR_CODE) PduR_DcmCancelTransmit
(
    PduIdType id
);

extern FUNC(Std_ReturnType, PDUR_CODE) PduR_DcmChangeParameter
(
    PduIdType id,
    TPParameterType parameter,
    uint16 value
);

extern FUNC(Std_ReturnType, PDUR_CODE) PduR_DcmCancelReceive
(
    PduIdType id
);
#else
extern CONST(PduIdType, PDUR_CONST) PduRDcmToCanTpIdTable[PDUR_NUMOFDCMTXPDU];
#define PduR_DcmTransmit(id, info)     CanTp_Transmit((PduRDcmToCanTpIdTable[id]), (info))
#endif
#endif

#define PDUR_STOP_SEC_CODE
#include "MemMap.h"

#endif/* PDUR_DCM_H */

