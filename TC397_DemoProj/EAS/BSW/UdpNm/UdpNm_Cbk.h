/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE                              
*   This software is the property of HiRain Technologies. Any information 
*   contained in this doc should not be reproduced, or used, or disclosed 
*   without the written authorization from HiRain Technologies.
********************************************************************************
*   File Name       : UdpNm_Cbk.h
********************************************************************************
*   Project/Product : AUTOSAR 4.2.2
*   Title           : UDP Network Management module call back head File
*   Author          : Hirain
********************************************************************************
*   Description     : UDP Network Management module call back head File
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
*   01.00.00    14/08/2017    junfei.chen   N/A          Original
********************************************************************************
* END_FILE_HDR*/
#ifndef _UDPNM_CBK_H_
#define _UDPNM_CBK_H_

/*******************************************************************************
*   Includes
*******************************************************************************/
#include "UdpNm_Types.h"


/*******************************************************************************
* Functions
*******************************************************************************/
#define UDPNM_START_SEC_CODE
#include "MemMap.h"

/*[SWS_UdpNm_00228]*/
extern FUNC(void, UDPNM_CODE) UdpNm_SoAdIfTxConfirmation
(
    PduIdType TxPduId
);

/*[SWS_UdpNm_00231]*/
extern FUNC(void, UDPNM_CODE) UdpNm_SoAdIfRxIndication 
(
    PduIdType RxPduId,
    P2CONST(PduInfoType, AUTOMATIC, UDPNM_APPL_DATA) PduInfoPtr 
);

/*[SWS_UdpNm_00313]*/
extern FUNC(Std_ReturnType, UDPNM_CODE) UdpNm_Transmit
(
    PduIdType UdpNmTxPduId,
    P2CONST(PduInfoType, AUTOMATIC, UDPNM_APPL_DATA)  UdpNmSrcPduInfoPtr
);
#define UDPNM_STOP_SEC_CODE
#include "MemMap.h"

#endif/*_UDPNM_CBK_H_*/

