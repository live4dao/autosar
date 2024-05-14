/*  BEGIN_FILE_HDR
********************************************************************************
*     NOTICE
*     This software is the property of HiRain Technologies. Any information
*     contained in this doc should not be reproduced, or used, or disclosed
*     without the written authorization from HiRain Technologies.
********************************************************************************
*     File Name         : PduR_J1939Rm.h
********************************************************************************
*     Project/Product : AUTOSAR 4.2
*     Title             : PduR_J1939Rm.h
*     Author          : Hirain
********************************************************************************
*     Description     : The header file PduR_J1939Rm.h contains the declaration of
*                       functions which is called by the J1939Rm module
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
#ifndef PDUR_J1939RM_H
#define PDUR_J1939RM_H

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

#if(STD_ON == PDUR_J1939RM_MODULE_SUPPORT)
extern FUNC(Std_ReturnType, PDUR_CODE) PduR_J1939RmTransmit
(
    PduIdType id,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_CONST) info
);

#endif

#define PDUR_STOP_SEC_CODE
#include "MemMap.h"

#endif/* PDUR_J1939RM_H */

