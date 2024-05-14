/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
*   File Name       : StbM.h
********************************************************************************
*   Project/Product : AUTOSAR 4.2
*   Title           : StbM.h
*   Author          : Hirain
********************************************************************************
*   Description     : Main header file of the AUTOSAR Synchronized Time Base Manager,
*                     according to AUTOSAR_SWS_SynchronizedTimeBaseManager.pdf(Release4.2).
*                     The header file contains the declaration of the Can module
*                     API;contains 'extern' declarations of constants,global data,
*                     type definitions and services that are specified in the
*                     StbM module SWS.
*
********************************************************************************
*   Limitations     : None
*
********************************************************************************
*
********************************************************************************
*   Revision History:
*   Reference to Core C File
********************************************************************************
* END_FILE_HDR*/

#ifndef STBM_H
#define STBM_H

/*******************************************************************************
*   Includes
*******************************************************************************/
#include "StbM_Types.h"
#include "StbM_Version.h"


/**************************************************************************************************
* Global defines
**************************************************************************************************/

/*Development Error*/
/*SWS_StbM_00041*/
#define STBM_E_PARAM                            (0x0A)
#define STBM_E_NOT_INITIALIZED                  (0x0B)
#define STBM_E_PARAM_POINTER                    (0x10)
#define STBM_E_INIT_FAILED                      (0x11)

/*API Service IDs*/
#define STBM_SID_GETVERSIONINFO                 (0x05)
#define STBM_SID_INIT                           (0x00)
#define STBM_SID_GETCURRENTTIME                 (0x07)
#define STBM_SID_GETCURRENTTIMEEXTENDED         (0x08)
#define STBM_SID_GETCURRENTTIMERAW              (0x09)
#define STBM_SID_GETCURRENTTIMEDIFF             (0x0a)
#define STBM_SID_SETGLOBALTIME                  (0x0b)
#define STBM_SID_SETUSERDATA                    (0x0c)
#define STBM_SID_SETOFFSET                      (0x0d)
#define STBM_SID_GETOFFSET                      (0x0e)
#define STBM_SID_BUSSETGLOBALTIME               (0x0f)

#define STBM_SID_GETCURRENTTIMETOBESTORED       (0x06)

#define STBM_SID_MAINFUNCTION                   (0x04)

/**************************************************************************************************
* Gloable Data definitions
**************************************************************************************************/

/**************************************************************************************************
* Prototypes of export functions
**************************************************************************************************/
#define STBM_START_SEC_CODE
#include "MemMap.h"

extern FUNC(void, STBM_CODE) StbM_Init
(
    P2CONST(StbM_ConfigType, STBM_APPL_CONST, AUTOMATIC) ConfigPtr
);

extern FUNC(Std_ReturnType, STBM_CODE) StbM_GetCurrentTime
(
    StbM_SynchronizedTimeBaseType timeBaseId,
    P2VAR(StbM_TimeStampType, AUTOMATIC, STBM_APPL_DATA) timeStampPtr,
    P2VAR(StbM_UserDataType, AUTOMATIC, STBM_APPL_DATA) userDataPtr
);

#if(STBM_NONVOLATILE_SUPPORT == STD_ON)
extern FUNC(Std_ReturnType, STBM_CODE) StbM_GetCurrentTimeToBeStored
(
    StbM_SynchronizedTimeBaseType timeBaseId,
    P2VAR(StbM_TimeStampType, AUTOMATIC, STBM_APPL_DATA) timeStampPtr,
    P2VAR(StbM_UserDataType, AUTOMATIC, STBM_APPL_DATA) userDataPtr
);
#endif

#if(STBM_GETCURRENTTIMEEXTENDED_AVAILABLE == STD_ON)
extern FUNC(Std_ReturnType, STBM_CODE) StbM_GetCurrentTimeExtended
(
    StbM_SynchronizedTimeBaseType timeBaseId,
    P2VAR(StbM_TimeStampExtendedType, AUTOMATIC, STBM_APPL_DATA) timeStampPtr,
    P2VAR(StbM_UserDataType, AUTOMATIC, STBM_APPL_DATA) userDataPtr
);
#endif

extern FUNC(Std_ReturnType, STBM_CODE) StbM_GetCurrentTimeRaw
(
    P2VAR(StbM_TimeStampRawType, AUTOMATIC, STBM_APPL_DATA) timeStampRawPtr
);

extern FUNC(Std_ReturnType, STBM_CODE) StbM_GetCurrentTimeDiff
(
    StbM_TimeStampRawType givenTimeStamp,
    P2VAR(StbM_TimeStampRawType, AUTOMATIC, STBM_APPL_DATA) timeStampDiffPtr
);


extern FUNC(Std_ReturnType, STBM_CODE) StbM_SetGlobalTime
(
    StbM_SynchronizedTimeBaseType timeBaseId,
    P2CONST(StbM_TimeStampType, STBM_APPL_CONST, AUTOMATIC) timeStampPtr,
    P2CONST(StbM_UserDataType, STBM_APPL_CONST, AUTOMATIC) userDataPtr
);

extern FUNC(Std_ReturnType, STBM_CODE) StbM_SetUserData
(
    StbM_SynchronizedTimeBaseType timeBaseId,
    P2CONST(StbM_UserDataType, STBM_APPL_CONST, AUTOMATIC) userDataPtr
);

extern FUNC(Std_ReturnType, STBM_CODE) StbM_SetOffset
(
    StbM_SynchronizedTimeBaseType timeBaseId,
    P2CONST(StbM_TimeStampType, STBM_APPL_CONST, AUTOMATIC) timeStampPtr
);

extern FUNC(Std_ReturnType, STBM_CODE) StbM_GetOffset
(
    StbM_SynchronizedTimeBaseType timeBaseId,
    P2VAR(StbM_TimeStampType, AUTOMATIC, STBM_APPL_DATA) timeStampPtr
);

extern FUNC(Std_ReturnType, STBM_CODE) StbM_BusSetGlobalTime
(
    StbM_SynchronizedTimeBaseType timeBaseId,
    P2CONST(StbM_TimeStampType, STBM_APPL_CONST, AUTOMATIC) timeStampPtr,
    P2CONST(StbM_UserDataType, STBM_APPL_CONST, AUTOMATIC) userDataPtr,
    boolean syncToTimeBase
);

extern FUNC(void, STBM_CODE) StbM_MainFunction
(
    void
);

#if(STBM_VERSION_INFO_API == STD_ON)
extern FUNC(void, STBM_CODE) StbM_GetVersionInfo
(
    P2VAR(Std_VersionInfoType, AUTOMATIC, STBM_APPL_DATA) versioninfo
);
#endif

#define STBM_STOP_SEC_CODE
#include "MemMap.h"

#endif/*STBM_H*/

