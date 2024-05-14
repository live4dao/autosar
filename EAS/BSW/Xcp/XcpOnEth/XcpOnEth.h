/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
*   File Name       : XcpOnEth.h
********************************************************************************
*   Project/Product : AUTOSAR 4.2
*   Title           : XcpOnEth module head File
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

#ifndef XCP_ON_ETH_H
#define XCP_ON_ETH_H

/*******************************************************************************
*   Includes
*******************************************************************************/
#include "Xcp_Process.h"
#if(STD_ON == XCP_ON_ETHERNET_ENABLED)
#include "SoAd.h"
/*******************************************************************************
*   macro define
*******************************************************************************/

/*******************************************************************************
*   extern function declair
*******************************************************************************/
#define XCP_START_SEC_CODE
#include "MemMap.h"

extern FUNC (Std_ReturnType, XCP_CODE) Xcp_TransmitOnEth
(
    CONSTP2VAR (PduInfoType, AUTOMATIC, XCP_VAR_NOINIT) pduInfo
);

extern FUNC (void, XCP_CODE) Xcp_InitEth (void);

#define XCP_STOP_SEC_CODE
#include "MemMap.h"

#endif

#endif  /* ifndef XCP_ON_ETH_H*/

