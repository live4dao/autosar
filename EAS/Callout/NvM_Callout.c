/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : NvM_Callout.c
********************************************************************************
*   Project/Product : AUTOSAR BSW PROJECT
*   Title           : NvM module configuration File
*   Author          : Hirain
********************************************************************************
*   Description     : NvM module configuration File
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
#include "NvM.h"
      
/*******************************************************************************
*   Callout declare
*******************************************************************************/
#define NVM_START_SEC_CODE
#include "MemMap.h"

FUNC(uint8, NVM_CALLOUT_CODE) NvM_Crc8CalculateCallout
(
    P2CONST(uint8, AUTOMATIC,NVM_APPL_DATA) Crc_DataPtr,
    uint32 Crc_Length,
    uint8 Crc_StartValue8,
    boolean Crc_IsFirstCall
)
{
    uint8 ret = 0x55;
    /*APP define*/
    /* NvM_Crc8CalculateCallout User Code start*/
    ret = Crc_CalculateCRC8(Crc_DataPtr, Crc_Length, Crc_StartValue8, Crc_IsFirstCall);
    /* NvM_Crc8CalculateCallout User Code end*/
    return ret;
}
#define NVM_STOP_SEC_CODE
#include "MemMap.h"




