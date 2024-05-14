/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
*   File Name       : Xcp_Cal.h
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
#ifndef XCP_CAL_H
#define XCP_CAL_H

/*******************************************************************************
*   Includes
*******************************************************************************/
#include "Xcp_Process.h"

#if(STD_ON == XCP_CAL_SUPPORTED)
/*******************************************************************************
*   macro define
*******************************************************************************/
#define  XCP_DOWNLOAD_REQ_LEN          (2)
#if(XCP_AG > 2)
#define  XCP_DOWNLOAD_DATA_OFFSET       XCP_AG
#else
#define  XCP_DOWNLOAD_DATA_OFFSET       XCP_DOWNLOAD_REQ_LEN
#endif

/*******************************************************************************
*   extern data declair
*******************************************************************************/


/*******************************************************************************
*   extern function declair
*******************************************************************************/
#define XCP_START_SEC_CODE
#include "MemMap.h"

extern FUNC(void, XCP_CODE) Xcp_CalInit (void);

/*CAL*/
extern FUNC(void, XCP_CODE) Xcp_FuncDownload (void);

/*CAL Option*/
extern FUNC(void, XCP_CODE) Xcp_FuncDownloadMax (void);
extern FUNC(void, XCP_CODE) Xcp_FuncShortDownload (void);
#if(STD_ON == XCP_MODIFYBITS_SUPPORT)
extern FUNC(void, XCP_CODE) Xcp_FuncModifyBits (void);
#else
#define Xcp_FuncModifyBits    NULL_PTR
#endif
#if(STD_ON == XCP_MASTER_BLOCK_MODE_SUPPORT)
extern FUNC(void, XCP_CODE) Xcp_FuncDownloadNext (void);
#else
#define Xcp_FuncDownloadNext NULL_PTR
#endif


#define XCP_STOP_SEC_CODE
#include "MemMap.h"
#else

#define Xcp_FuncDownload      NULL_PTR
#define Xcp_FuncDownloadMax   NULL_PTR
#define Xcp_FuncShortDownload NULL_PTR
#define Xcp_FuncModifyBits    NULL_PTR
#define Xcp_FuncDownloadNext  NULL_PTR

#endif

#endif  /* ifndef XCP_CAL_H*/

