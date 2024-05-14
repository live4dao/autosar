/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : CanTSyn_Callout.c
********************************************************************************
*   Project/Product : AUTOSAR BSW PROJECT
*   Title           : CanTSyn module configuration File
*   Author          : Hirain
********************************************************************************
*   Description     : CanTSyn module configuration File
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
#include "CanTSyn.h"

#define CANTSYN_START_SEC_CODE
#include "MemMap.h"

FUNC(boolean, CANTSYN_CODE) CanTSyn_BeyondJumpWidth
(
    uint8 TimeDomainId
)
{
    boolean ret = FALSE;
    /* CanTSyn_BeyondJumpWidth User Code start*/

    /* CanTSyn_BeyondJumpWidth User Code end*/
    return ret;
}
#define CANTSYN_STOP_SEC_CODE
#include "MemMap.h"




