/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : RamTst_Lcfg.c
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


/*******************************************************************************
*   Includes
*******************************************************************************/

#include "RamTst_Lcfg.h"


#define RAMTST_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"

STATIC CONST(RamTst_ConfigBlockParamsType,RAMTST_CONST) RamTstBlockParams_0[1] =
{
    {
        (RamTst_NumberOfBlocksType)0,
        RamTstBlock_1,
        RAMTEST_NON_DESTRUCTIVE,
        (uint32)0xCCCCCCCC,
        (uint32)0x0,
        (uint32)0x7
    }
};

STATIC CONST(RamTst_ConfigAlgParamsType,RAMTST_CONST) RamTstAlgParams[1] =
{
    {
        RamTstAlgParams_1,
        RAMTST_CHECKERBOARD_TEST,
        (RamTst_NumberOfBlocksType)1,
        (RamTst_NumberOfTestedCellsType)8,
        (RamTst_NumberOfTestedCellsType)8,
        (RamTst_NumberOfTestedCellsType)8,
        RamTstBlockParams_0
    }
};

CONST(RamTst_ConfigParamsType,RAMTST_CONST)  RamTstConfig =
{
    (RamTst_AlgParamsIdType)1,
    (RamTst_AlgParamsIdType)1,
    (RamTst_NumberOfTestedCellsType)8,
    RamTstAlgParams,
    NULL_PTR,
    NULL_PTR
};

#define RAMTST_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"

#define RAMTST_START_SEC_VAR_NOINIT_8
#include "MemMap.h"

VAR(RamTst_TestResultType,RAMTST_VAR) RamTstBlockTestResult[RAMTST_MAX_NUMBER_OF_BLOCKS];

#define RAMTST_STOP_SEC_VAR_NOINIT_8
#include "MemMap.h"



