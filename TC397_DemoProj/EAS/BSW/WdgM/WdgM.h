/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
*   File Name       : WdgM.h
********************************************************************************
*   Project/Product : AUTOSAR 4.2
*   Title           : Watchdog Manager module Header File
*   Author          : Hirain
********************************************************************************
*   Description     : Watchdog Manager module Header File
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
#ifndef WDGM_H
#define WDGM_H

/*******************************************************************************
*   Includes
*******************************************************************************/
#include "WdgM_PBcfg.h"


/*******************************************************************************
*   Macro
*******************************************************************************/
/* DET error code */
#define WDGM_E_NO_INIT               ((uint8)0x10)
#define WDGM_E_PARAM_CONFIG          ((uint8)0x11)
#define WDGM_E_PARAM_MODE            ((uint8)0x12)
#define WDGM_E_PARAM_SEID            ((uint8)0x13)
#define WDGM_E_NULL_POINTER          ((uint8)0x14)
#define WDGM_E_DISABLE_NOT_ALLOWED   ((uint8)0x15)
#define WDGM_E_CPID                  ((uint8)0x16)
#define WDGM_E_DEPRECATED            ((uint8)0x17)
#define WDGM_E_AMBIGIOUS             ((uint8)0x18)
#define WDGM_E_SEDEACTIVATED         ((uint8)0x19)

/* ApiId*/
#define WDGM_INIT_APIID              ((uint8)0x00)
#define WDGM_DEINIT_APIID            ((uint8)0x01)
#define WDGM_GETVERSION_APIID        ((uint8)0x02)
#define WDGM_SETMODE_APIID           ((uint8)0x03)
#define WDGM_GETMODE_APIID           ((uint8)0x0B)
#define WDGM_CPREACH_APIID           ((uint8)0x0E)
#define WDGM_UPDATEALIVECNT_APIID    ((uint8)0x04)
#define WDGM_GETLOCALSTATUS_APIID    ((uint8)0x0C)
#define WDGM_GETGLOBALSTATUS_APIID   ((uint8)0x0D)
#define WDGM_PERFORMRESET_APIID      ((uint8)0x0F)
#define WDGM_GET1STEXPSEID_APIID     ((uint8)0x10)

#define WDGM_MAINFUNCTION_APIID      ((uint8)0x08)

/* dead line cp type */
#define WDGM_CP_NO_DEADLINE                ((uint8)0x0)
#define WDGM_CP_DEADLINE_START             ((uint8)0x1)
#define WDGM_CP_DEADLINE_STOP              ((uint8)0x2)

/* flow cp type */
#define WDGM_CP_NO_FLOW                    ((uint8)0x0)
#define WDGM_CP_FLOW_INIT                  ((uint8)0x1)
#define WDGM_CP_FLOW_END                   ((uint8)0x2)
#define WDGM_CP_FLOW_NORMAL                ((uint8)0x3)



/* deadline state */
#define WDGM_DEADLINE_INACTIVE             ((uint8)0x0)
#define WDGM_DEADLINE_BUSY                 ((uint8)0x1)

#define WDGM_UNUSED_MODE                   ((WdgM_ModeType)0xFF)
#define WDGM_INVALID_ALIVE_INDEX           ((uint16)0xFFFF)
#define WDGM_INVALID_FLOW_INDEX            ((uint16)0xFFFF)

/* Error Code */
#define WDGM_NO_ERROR             ((uint8)0)
#define WDGM_ALIVE_ERROR          ((uint8)1)
#define WDGM_DEADLINE_ERROR       ((uint8)2)
#define WDGM_FLOW_ERROR           ((uint8)4)
#define WDGM_ALIVE_ERROR_TEMP     ((uint8)8)
#define WDGM_FLOW_DEAFLINE_MASK   ((uint8)0x6)

#if(STD_ON == WDGM_DEM_USED)
#define WDGM_INVALID_DEM_EVENT    ((Dem_EventIdType)0xFFFF)
#endif

/*******************************************************************************
*   Global Function Declaration
*******************************************************************************/
#define WDGM_START_SEC_CODE
#include "MemMap.h"

extern FUNC(void, WDGM_CODE)  WdgM_Init
(
    P2CONST(WdgM_ConfigType, AUTOMATIC, WDGM_CONST)  ConfigPtr
);

extern FUNC(void, WDGM_CODE) WdgM_DeInit(void);

extern FUNC(Std_ReturnType, WDGM_CODE)  WdgM_SetMode
(
    WdgM_ModeType Mode,
    uint16 CallerID
);

extern FUNC(Std_ReturnType, WDGM_CODE)  WdgM_GetMode
(
    P2VAR(WdgM_ModeType, AUTOMATIC, WDGM_APPL_DATA) Mode
);

extern FUNC(Std_ReturnType, WDGM_CODE)  WdgM_CheckpointReached
(
    WdgM_SupervisedEntityIdType SEID,
    WdgM_CheckpointIdType CheckpointID
);

extern FUNC(Std_ReturnType, WDGM_CODE)  WdgM_UpdateAliveCounter
(
    WdgM_SupervisedEntityIdType SEID
);

extern FUNC(Std_ReturnType, WDGM_CODE) WdgM_GetLocalStatus
(
    WdgM_SupervisedEntityIdType SEID,
    P2VAR(WdgM_LocalStatusType, AUTOMATIC, WDGM_APPL_DATA) Status
);

extern FUNC(Std_ReturnType, WDGM_CODE) WdgM_GetGlobalStatus
(
    P2VAR(WdgM_GlobalStatusType, AUTOMATIC, WDGM_APPL_DATA) Status
);

extern FUNC(void, WDGM_CODE) WdgM_PerformReset(void);

extern FUNC(void, WDGM_CODE) WdgM_MainFunction(void);

#if (STD_ON == WDGM_VERSION_INFO_API)
extern FUNC(void, WDGM_CODE) WdgM_GetVersionInfo
(
    P2VAR(Std_VersionInfoType, AUTOMATIC, WDGM_APPL_DATA) VersionInfo
);
#endif

extern FUNC(Std_ReturnType, WDGM_CODE) WdgM_GetFirstExpiredSEID
(
    P2VAR(WdgM_SupervisedEntityIdType, AUTOMATIC, WDGM_APPL_DATA) SEID
) ;


#define WDGM_STOP_SEC_CODE
#include "MemMap.h"


#endif
