/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : SchM_CanTp.h
********************************************************************************
*   Project/Product : AUTOSAR BSW PROJECT
*   Title           : SchM module configuration File
*   Author          : Hirain
********************************************************************************
*   Description     : SchM module configuration File
*
********************************************************************************
*   Limitations     : None
*
********************************************************************************
*
********************************************************************************
*   Revision History:
*
*   Version     Date          Initials      CR#          Descriptions
*   ---------   ----------    ------------  ----------   ---------------
*   V1.0.0_3.5.5_AZ240046       27/03/2024    Eas           N/A          N/A
*
********************************************************************************
* END_FILE_HDR*/
#ifndef SCHM_CANTP_H
#define SCHM_CANTP_H
/*******************************************************************************
*   Include
*******************************************************************************/
#include "SchM_CanTp_Type.h"
#include "Os.h"

/*PRQA S 3453,3429 EOF*/
/*
1.The unified requirement of EAS is that the error reporting functions of Det
and Dem moduls are accessed by macro functions.This part has been verified and
has no problem.
2.Macro functions are allowed to use to access parameters and do some simple operations.
*/

/*PRQA S 792,791 EOF*/
/*
Name of macros may not follow relevant naming rules.
*/

/*******************************************************************************
*   exclusive Area
*******************************************************************************/
#define SchM_Enter_CanTp_CANTP_EXCLUSIVE_AREA_0()
#define SchM_Exit_CanTp_CANTP_EXCLUSIVE_AREA_0()


#endif



