/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : UdpNm_Callout.h
********************************************************************************
*   Project/Product : AUTOSAR BSW PROJECT
*   Title           : UdpNm module configuration File
*   Author          : Hirain
********************************************************************************
*   Description     : UdpNm module configuration File
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

#ifndef UDPNM_CALLOUT_H
#define UDPNM_CALLOUT_H

/*******************************************************************************
*   Includes
*******************************************************************************/
#include "UdpNm_Lcfg.h"

#define UDPNM_START_SEC_CODE
#include "MemMap.h"

extern FUNC(void, UDPNM_CODE) UdpNm_SetUserDataCall
(    
    P2VAR(uint8, AUTOMATIC, UDPNM_APPL_DATA) dataBuffPtr,
    P2CONST(uint8, AUTOMATIC, UDPNM_APPL_DATA) nmUserDataPtr,
    const uint32 size
);


extern FUNC(void, UDPNM_CODE) UdpNm_GetUserDataCall
(    
    P2CONST(uint8, AUTOMATIC, UDPNM_APPL_DATA) dataBuffPtr,
    P2VAR(uint8, AUTOMATIC, UDPNM_APPL_DATA) nmUserDataPtr,
    const uint32 size
);


#define UDPNM_STOP_SEC_CODE
#include "MemMap.h"

#endif
