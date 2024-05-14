/*  BEGIN_FILE_HDR
********************************************************************************
*     NOTICE
*     This software is the property of HiRain Technologies. Any information
*     contained in this doc should not be reproduced, or used, or disclosed
*     without the written authorization from HiRain Technologies.
********************************************************************************
*     File Name       : PduR_Cdd.h
********************************************************************************
*     Project/Product : AUTOSAR 4.2
*     Title           : PduR_Cdd.h
*     Author          : Hirain
********************************************************************************
*     Description     : The header file PduR_Cdd.h contains the declaration of
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
#ifndef PDUR_CDD_H
#define PDUR_CDD_H

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

#if(STD_ON == PDUR_CDD_MODULE_SUPPORT)
extern FUNC(Std_ReturnType, PDUR_CODE) PduR_CddTransmit
(
    PduIdType id,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_CONST) info
);

#if(STD_ON == PDUR_CDD_CANCELTRANSMIT_ENABLED)
extern FUNC(Std_ReturnType, PDUR_CODE) PduR_CddCancelTransmit
(
    PduIdType id
);
#endif

#if(STD_ON == PDUR_CDD_CHANGEPARAMETER_API_ENABLED)
extern FUNC(Std_ReturnType, PDUR_CODE) PduR_CddChangeParameter
(
    PduIdType id,
    TPParameterType parameter,
    uint16 value
);
#endif

#if(STD_ON == PDUR_CDD_CANCELRECEIVE_ENABLED)
extern FUNC(Std_ReturnType, PDUR_CODE) PduR_CddCancelReceive
(
    PduIdType id
);
#endif

#endif

#define PDUR_STOP_SEC_CODE
#include "MemMap.h"

#endif/*PDUR_CDD_H*/

