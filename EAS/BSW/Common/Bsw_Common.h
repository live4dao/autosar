/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
*   File Name       : Bsw_Common.h
********************************************************************************
*   Project/Product : AUTOSAR 4.2
*   Title           : Bsw Common File
*   Author          : Hirain
********************************************************************************
*   Description     : Bsw_Common header file.
*
********************************************************************************
*   Limitations     : None
*
********************************************************************************
*
********************************************************************************
*   Revision History:
*
********************************************************************************
* END_FILE_HDR*/

#ifndef BSW_COMMON_H
#define BSW_COMMON_H
/*******************************************************************************
*   Includes
*******************************************************************************/
#include "Std_Types.h"

/*****************************************************************************
 *  General QAC Suppression
 *****************************************************************************/
/*PRQA S 3432,3410,3409 EOF*/
/*
P2VAR and other macros in the Compiler conforms to AUTOSAR standard.There's no
need to revise.
*/

#define BSW_CANFD_LENGTH_TABLE_SIZE     ((uint8)16)
#define BSW_START_SEC_CONST_8
#include "MemMap.h"

extern CONST(uint8, BSW_CONST) Bsw_CanFDDlcMap[BSW_CANFD_LENGTH_TABLE_SIZE];

#define BSW_STOP_SEC_CONST_8
#include "MemMap.h"

#define BSW_START_SEC_CODE
#include "MemMap.h"
/*******************************************************************************
*   Declare
*******************************************************************************/
extern FUNC(void, BSW_CODE) Bsw_MemCpy
(
    CONSTP2VAR(uint8, AUTOMATIC, BSW_APPL_DATA) dest,
    CONSTP2CONST(uint8, AUTOMATIC, BSW_APPL_DATA) src,
    const uint32 size
);
extern FUNC(void, BSW_CODE) Bsw_MemSet
(
    CONSTP2VAR(uint8, AUTOMATIC, BSW_APPL_DATA) dest,
    const uint8 src,
    const uint32 size
);
extern FUNC(Std_ReturnType, BSW_CODE) Bsw_MemCmp
(
    CONSTP2CONST (uint8, AUTOMATIC, BSW_APPL_DATA) CmpA,
    CONSTP2CONST (uint8, AUTOMATIC, BSW_APPL_DATA) CmpB,
    const uint32 size
);
#define BSW_STOP_SEC_CODE
#include "MemMap.h"

#endif /* BSW_COMMON_H */

