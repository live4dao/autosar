/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : RamTst_Lcfg.h
********************************************************************************
*   Project/Product : AUTOSAR BSW PROJECT
*   Title           : RamTst module configuration File
*   Author          : Hirain
********************************************************************************
*   Description     : RamTst module configuration File
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
#ifndef RAMTST_LCFG_H
#define RAMTST_LCFG_H

/*******************************************************************************
*   Includes
*******************************************************************************/

#include "RamTst_Types.h"

#define RAMTST_START_SEC_CONFIG_DATA_UNSPECIFIED

#include "MemMap.h"

extern CONST(RamTst_ConfigParamsType,RAMTST_CONST) RamTstConfig;
extern CONST(RamTst_AlgorithmFunType,RAMTST_CONST) RamTstAlgorithm[];

#define RAMTST_STOP_SEC_CONFIG_DATA_UNSPECIFIED

#include "MemMap.h"

#define RAMTST_START_SEC_VAR_NOINIT_8

#include "MemMap.h"

extern VAR(RamTst_TestResultType,RAMTST_VAR) RamTstBlockTestResult[];

#define RAMTST_STOP_SEC_VAR_NOINIT_8

#include "MemMap.h"

#define RamTst_ClearCache()

#endif /*RAMTST_LCFG_H*/



