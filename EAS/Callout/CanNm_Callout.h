/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : CanNm_Callout.h
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
#ifndef CANNM_CALLOUT_H
#define CANNM_CALLOUT_H

/*******************************************************************************
*   Includes
*******************************************************************************/
#include "CanNm_Lcfg.h"

#define CANNM_START_SEC_CODE
#include "MemMap.h"

extern FUNC(Std_ReturnType, CANNM_CODE) CanNm_UserData_TriggerTransmit_Callout
(
    NetworkHandleType nmChannelHandle,
    CONSTP2VAR(uint8, AUTOMATIC, CANNM_APPL_DATA) nmUserDataPtr
);


#define CANNM_STOP_SEC_CODE
#include "MemMap.h"

#endif

