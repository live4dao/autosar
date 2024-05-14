/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
*   File Name       : XcpOnCan_Cbk.h
********************************************************************************
*   Project/Product : AUTOSAR 4.2
*   Title           : XcpOnCan_Cbk module head File
*   Author          : Hirain
********************************************************************************
*   Description     : Implementation of Xcp provided functionality
*
********************************************************************************
*   Limitations     : None
*
********************************************************************************
*
********************************************************************************
*   Revision History:
********************************************************************************
* END_FILE_HDR*/

#ifndef XCP_ON_ETH_CBK_H
#define XCP_ON_ETH_CBK_H

/*******************************************************************************
*   Includes
*******************************************************************************/
#include "Xcp_Types.h"

#if(STD_ON == XCP_ON_ETHERNET_ENABLED)
/*******************************************************************************
*   macro define
*******************************************************************************/

/*******************************************************************************
*   extern function declair
*******************************************************************************/
#define XCP_START_SEC_CODE
#include "MemMap.h"

extern FUNC (void, XCP_CODE) Xcp_SoAdIfRxIndication
(
    PduIdType XcpRxPduId,
    P2CONST (PduInfoType, AUTOMATIC, XCP_APPL_DATA) XcpRxPduPtr
);
extern FUNC (void, XCP_CODE) Xcp_SoAdIfTxConfirmation
(
    VAR (PduIdType, XCP_APPL_DATA) XcpTxPduId
);

#define XCP_STOP_SEC_CODE
#include "MemMap.h"

#endif/*#if(STD_ON == XCP_ON_ETHERNET_ENABLED)*/
#endif

