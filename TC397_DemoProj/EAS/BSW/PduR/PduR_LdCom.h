/*  BEGIN_FILE_HDR
********************************************************************************
*     NOTICE
*     This software is the property of HiRain Technologies. Any information
*     contained in this doc should not be reproduced, or used, or disclosed
*     without the written authorization from HiRain Technologies.
********************************************************************************
*     File Name       : PduR_LdCom.h
********************************************************************************
*     Project/Product : AUTOSAR 4.2
*     Title           : PduR_LdCom.h
*     Author          : Hirain
********************************************************************************
*     Description     : The header file PduR_LdCom.h contains the declaration of
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
#ifndef PDUR_LDCOM_H
#define PDUR_LDCOM_H

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

#if(STD_ON == PDUR_LDCOM_MODULE_SUPPORT)
extern FUNC(Std_ReturnType, PDUR_CODE) PduR_LdComTransmit
(
    PduIdType id,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_CONST) info
);
#endif

#define PDUR_STOP_SEC_CODE
#include "MemMap.h"

#endif/*PDUR_LDCOM_H*/

