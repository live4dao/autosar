/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : FlsTst_Cfg.c
********************************************************************************
*   Project/Product : AUTOSAR BSW PROJECT
*   Title           : FlsTst module configuration File
*   Author          : Hirain
********************************************************************************
*   Description     : FlsTst module configuration File
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
#include "FlsTst.h"
#include "FlsTst_Callout.h"

#define FLSTST_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"

CONST(FlsTst_AlgorithmFunType, FLSTST_CONST) FlsTstAlgorithm[1] =
{
    &FlsTst_Crc16Algorithm,
};


CONST( FlsTst_ConfigType, FLSTST_CONST) FlsTstConfig =
{
    FLSTST_NUMBER_OF_BGND_BLOCKS,
    FLSTST_NUMBER_OF_FGND_BLOCKS,
    NULL_PTR,
    NULL_PTR,
    NULL_PTR
};

#define FLSTST_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"




