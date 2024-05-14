/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : RamTst_Cfg.h
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
#include "RamTst.h"

#define RAMTST_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"
CONST(RamTst_AlgorithmFunType,RAMTST_CONST)RamTstAlgorithm[RAMTST_ALGORITHM_CHECKER] =
{
    &RamTst_DefaultTest,
    &RamTst_CheckerBoardTest,
};

#define RAMTST_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"



