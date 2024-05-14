/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : CanNm_Callout.c
********************************************************************************
*   Project/Product : AUTOSAR BSW PROJECT
*   Title           : CanNm module configuration File
*   Author          : Hirain
********************************************************************************
*   Description     : CanNm module configuration File
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
#include "CanNm_Callout.h"
#include "Bsw_Common.h"

/* Input File User Code start*/

/* Input File User Code end*/

#define CANNM_START_SEC_CODE
#include "MemMap.h"

FUNC(Std_ReturnType, CANNM_CODE) CanNm_UserData_TriggerTransmit_Callout
(
    NetworkHandleType nmChannelHandle,
    CONSTP2VAR(uint8, AUTOMATIC, CANNM_APPL_DATA) nmUserDataPtr
)
{
    Std_ReturnType ret = E_NOT_OK;
    /* CanNm_UserData_TriggerTransmit_Callout User Code start*/

    /* CanNm_UserData_TriggerTransmit_Callout User Code end*/
    return ret;
}


#define CANNM_STOP_SEC_CODE
#include "MemMap.h"
