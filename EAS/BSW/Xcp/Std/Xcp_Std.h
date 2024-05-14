/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
*   File Name       : Xcp_Std.h
********************************************************************************
*   Project/Product : AUTOSAR 4.2
*   Title           : Xcp_Std module head File
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

#ifndef XCP_STD_H
#define XCP_STD_H

/*******************************************************************************
*   Includes
*******************************************************************************/
#include "Xcp_Process.h"

/*******************************************************************************
*   macro define
*******************************************************************************/

/*******************************************************************************
*   extern data declair
*******************************************************************************/


/*******************************************************************************
*   extern function declair
*******************************************************************************/
#define XCP_START_SEC_CODE
#include "MemMap.h"

extern FUNC(void, XCP_CODE) Xcp_StdInit (void);
#if(STD_ON == XCP_SLAVE_BLOCK_MODE_SUPPORT)
extern  FUNC(void, XCP_CODE) Xcp_BlockUploadContinue (void);
#endif

#if((STD_ON == XCP_BUILDCS_SUPPORT) && (STD_ON == XCP_BUILDCS_ASYN_SUPPORT))
extern FUNC(void, XCP_CODE) Xcp_BuildCSEndNotification (void);
#endif




/* STD*/
extern FUNC(void, XCP_CODE) Xcp_FuncConnect (void);
extern FUNC(void, XCP_CODE) Xcp_FuncDisconnect (void);
extern FUNC(void, XCP_CODE) Xcp_FuncGetStatus (void);
extern FUNC(void, XCP_CODE) Xcp_FuncSynch (void);

/* STD Option */
extern FUNC(void, XCP_CODE) Xcp_FuncGetCommModeInfo (void);
#if(STD_ON == XCP_GETSLAVEID_SUPPORT)
extern FUNC(void, XCP_CODE) Xcp_FuncGetID (void);
#else
#define Xcp_FuncGetID NULL_PTR
#endif

#if(STD_ON == XCP_SETREQ_SUPPORT)
extern FUNC(void, XCP_CODE) Xcp_FuncSetRequest (void);
#else
#define Xcp_FuncSetRequest NULL_PTR
#endif

#if(STD_ON == XCP_SEEDKEY_SUPPORT)
extern FUNC(void, XCP_CODE) Xcp_FuncGetSeed (void);
extern FUNC(void, XCP_CODE) Xcp_FuncUnlock (void);
#else
#define Xcp_FuncGetSeed NULL_PTR
#define Xcp_FuncUnlock  NULL_PTR
#endif

extern FUNC(void, XCP_CODE) Xcp_FuncSetMta (void);
extern FUNC(void, XCP_CODE) Xcp_FuncUpload (void);
extern FUNC(void, XCP_CODE) Xcp_FuncShortUpload (void);

#if(STD_ON == XCP_BUILDCS_SUPPORT)
extern FUNC(void, XCP_CODE) Xcp_FuncBuildCheckSum (void);
#else
#define Xcp_FuncBuildCheckSum  NULL_PTR
#endif

#if(STD_ON == XCP_AUX_CMD_SUPPORT)
extern FUNC(void, XCP_CODE) Xcp_FuncTransportLayerCMD (void);
extern FUNC(void, XCP_CODE) Xcp_FuncUserCMD (void);
#else
#define Xcp_FuncTransportLayerCMD   NULL_PTR
#define Xcp_FuncUserCMD             NULL_PTR
#endif




#define XCP_STOP_SEC_CODE
#include "MemMap.h"

#endif  /* ifndef XCP_STD_H*/

