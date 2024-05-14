/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
*   File Name       : Xcp_Pag.h
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

#ifndef XCP_PAG_H
#define XCP_PAG_H

/*******************************************************************************
*   Includes
*******************************************************************************/
#include "Xcp_Process.h"

#if(STD_ON == XCP_PAG_SUPPORTED)
/*******************************************************************************
*   macro define
*******************************************************************************/

/*******************************************************************************
*   extern data declair
*******************************************************************************/

#define XCP_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"

#if(XCP_MAX_SEGMENT > 0)
extern CONST (Xcp_Info_of_Segment_Type, XCP_CONST)
XCP_Info_of_Segment[XCP_MAX_SEGMENT];
#endif


#define XCP_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"


/*******************************************************************************
*   extern function declair
*******************************************************************************/
#define XCP_START_SEC_CODE
#include "MemMap.h"

extern FUNC(void, XCP_CODE) Xcp_PagInit
(
    void
);

/*PAG*/
extern FUNC(void, XCP_CODE) Xcp_FuncSetCalPage
(
    void
);
extern FUNC(void, XCP_CODE) Xcp_FuncGetCalPage
(
    void
);

/*PAG Option*/
extern FUNC(void, XCP_CODE) Xcp_FuncGetPageProcessorInfo
(
    void
);
extern FUNC(void, XCP_CODE) Xcp_FuncGetSegmentInfo
(
    void
);
extern FUNC(void, XCP_CODE) Xcp_FuncGetPageInfo
(
    void
);
extern FUNC(void, XCP_CODE) Xcp_FuncSetSegmentMode
(
    void
);
extern FUNC(void, XCP_CODE) Xcp_FuncGetSegmentMode
(
    void
);

#if(STD_ON == XCP_COPYPAG_SUPPORT)
extern FUNC(void, XCP_CODE) Xcp_FuncCopyCalPage
(
    void
);
#else
#define Xcp_FuncCopyCalPage          NULL_PTR
#endif

#define XCP_STOP_SEC_CODE
#include "MemMap.h"

#else

#define Xcp_FuncSetCalPage           NULL_PTR
#define Xcp_FuncGetCalPage           NULL_PTR

#define Xcp_FuncGetPageProcessorInfo NULL_PTR
#define Xcp_FuncGetSegmentInfo       NULL_PTR
#define Xcp_FuncGetPageInfo          NULL_PTR
#define Xcp_FuncSetSegmentMode       NULL_PTR
#define Xcp_FuncGetSegmentMode       NULL_PTR
#define Xcp_FuncCopyCalPage          NULL_PTR

#endif  /*#if(STD_ON == XCP_PAG_SUPPORTED)*/

#endif  /* ifndef XCP_PAG_H*/

