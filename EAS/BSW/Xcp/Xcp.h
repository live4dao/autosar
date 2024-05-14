/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
*   File Name       : Xcp.h
********************************************************************************
*   Project/Product : AUTOSAR 4.2
*   Title           : Xcp module head File
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
#ifndef XCP_H
#define XCP_H

/*******************************************************************************
*   Includes
*******************************************************************************/
#include "Xcp_Process.h"

/*******************************************************************************
*   macro define
*******************************************************************************/


/*******************************************************************************
*   Global Function Declare
*******************************************************************************/
#define XCP_START_SEC_CODE
#include "MemMap.h"

#if(STD_ON == XCP_VERSION_INFO_API)
extern FUNC(void, XCP_CODE) Xcp_GetVersionInfo
(
    P2VAR (Std_VersionInfoType, AUTOMATIC, XCP_APPL_DATA) versioninfo
);
#endif

extern FUNC(void, XCP_CODE) Xcp_Init
(
    P2CONST (Xcp_ConfigType, AUTOMATIC, XCP_CONST) Xcp_ConfigPtr
);

extern FUNC(void, XCP_CODE) Xcp_MainFunction
(
    void
);


#define XCP_STOP_SEC_CODE
#include "MemMap.h"

#endif
