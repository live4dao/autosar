/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
*   File Name       : Xcp_Pgm.h
********************************************************************************
*   Project/Product : AUTOSAR 4.2
*   Title           : Xcp_Pgm module head File
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

#ifndef XCP_PGM_H
#define XCP_PGM_H

/*******************************************************************************
*   Includes
*******************************************************************************/
#include "Xcp_Process.h"

#if(STD_ON == XCP_PGM_SUPPORTED)
/*******************************************************************************
*   macro define
*******************************************************************************/
#define  XCP_PROGRAM_REQ_LEN          (2)
#if(XCP_AG > 2)
#define  XCP_PROGRAM_DATA_OFFSET       XCP_AG
#else
#define  XCP_PROGRAM_DATA_OFFSET       XCP_PROGRAM_REQ_LEN
#endif

/*******************************************************************************
*   extern data declair
*******************************************************************************/
#define XCP_START_SEC_VAR_NOINIT_8
#include "MemMap.h"
extern VAR (boolean, XCP_PRIVATE_DATA) Xcp_PgmStartFlag;

#define XCP_STOP_SEC_VAR_NOINIT_8
#include "MemMap.h"

#define XCP_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"

#if(XCP_MAX_SECTOR > 0)
extern CONST (Xcp_Sector_Info_Type, XCP_CONST)
XCP_Sector_Info[XCP_MAX_SECTOR];
#endif

#define XCP_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"


/*******************************************************************************
*   extern function declair
*******************************************************************************/
#define XCP_START_SEC_CODE
#include "MemMap.h"

extern FUNC(void, XCP_CODE) Xcp_PgmInit (void);

/*PGM*/
extern FUNC(void, XCP_CODE) Xcp_FuncProgramStart (void);
extern FUNC(void, XCP_CODE) Xcp_FuncProgramClear (void);
extern FUNC(void, XCP_CODE) Xcp_FuncProgram (void);
extern FUNC(void, XCP_CODE) Xcp_FuncProgramReset (void);

/*PGM Option*/
extern FUNC(void, XCP_CODE) Xcp_FuncGetPgmProcessorInfo (void);
extern FUNC(void, XCP_CODE) Xcp_FuncGetSectorInfo (void);
extern FUNC(void, XCP_CODE) Xcp_FuncProgram_Prepare (void);
extern FUNC(void, XCP_CODE) Xcp_FuncProgramFormat (void);
extern FUNC(void, XCP_CODE) Xcp_FuncProgramMax (void);
extern FUNC(void, XCP_CODE) Xcp_FuncProgramVerify (void);

#if(STD_ON == XCP_MASTER_BLOCK_MODE_PGM_SUPPORT)
extern FUNC(void, XCP_CODE) Xcp_FuncProgramNext (void);
#else
#define Xcp_FuncProgramNext           NULL_PTR
#endif


#define XCP_STOP_SEC_CODE
#include "MemMap.h"

#else

#define Xcp_FuncProgramStart          NULL_PTR
#define Xcp_FuncProgramClear          NULL_PTR
#define Xcp_FuncProgram               NULL_PTR
#define Xcp_FuncProgramReset          NULL_PTR

#define Xcp_FuncGetPgmProcessorInfo   NULL_PTR
#define Xcp_FuncGetSectorInfo         NULL_PTR
#define Xcp_FuncProgram_Prepare       NULL_PTR
#define Xcp_FuncProgramFormat         NULL_PTR
#define Xcp_FuncProgramMax            NULL_PTR
#define Xcp_FuncProgramVerify         NULL_PTR
#define Xcp_FuncProgramNext           NULL_PTR

#endif/* #if(STD_ON == XCP_PGM_SUPPORTED) */

#endif  /* ifndef XCP_PGM_H*/

