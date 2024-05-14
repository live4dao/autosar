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
#ifndef WDGM_TYPES_H
#define WDGM_TYPES_H

/*******************************************************************************
*   Includes
*******************************************************************************/
#include "WdgM_Cfg.h"
#include "WdgM_Version.h"
#include "WdgIf.h"

#if(STD_ON == WDGM_OS_USED)
#include "Os.h"
#endif
#if(STD_ON == WDGM_DEM_USED)
#include "Dem.h"
#endif
#if(STD_ON == WDGM_BSWM_USED)
#include "BswM.h"
#endif

#if(STD_ON == WDGM_IMMEDIATE_RESET)
#include "Mcu.h" /* this header file may be changed when different mcal is used*/
#endif




/*******************************************************************************
*   Typedef
*******************************************************************************/

/*SWS_WdgM_00356*/
typedef uint16 WdgM_SupervisedEntityIdType;
#define WDGM_INVALID_SE      ((WdgM_SupervisedEntityIdType)0xFFFF)

/*SWS_WdgM_00357*/
typedef uint16 WdgM_CheckpointIdType;
#define WDGM_INVALID_CP      ((WdgM_CheckpointIdType)0xFFFF)



typedef uint8 WdgM_ModeType;
typedef uint8 WdgM_LocalStatusType;
typedef uint8 WdgM_GlobalStatusType;


/*SWS_WdgM_00358 - 360*/
#define WDGM_LOCAL_STATUS_OK          ((WdgM_LocalStatusType)0)
#define WDGM_LOCAL_STATUS_FAILED      ((WdgM_LocalStatusType)1)
#define WDGM_LOCAL_STATUS_EXPIRED     ((WdgM_LocalStatusType)2)
#define WDGM_LOCAL_STATUS_DEACTIVATED ((WdgM_LocalStatusType)4)

#define WDGM_GLOBAL_STATUS_OK          ((WdgM_GlobalStatusType)0)
#define WDGM_GLOBAL_STATUS_FAILED      ((WdgM_GlobalStatusType)1)
#define WDGM_GLOBAL_STATUS_EXPIRED     ((WdgM_GlobalStatusType)2)
#define WDGM_GLOBAL_STATUS_STOPPED     ((WdgM_GlobalStatusType)3)
#define WDGM_GLOBAL_STATUS_DEACTIVATED ((WdgM_GlobalStatusType)4)





typedef Std_ReturnType (*WdgM_ModeIndFunPtrType)(uint8 status);

typedef struct
{
#if(STD_ON == WDGM_BSWM_USED)
    ApplicationType           WdgMOsApplicationRef ;
#endif
#if(WDGM_TOTAL_DEADLINE_NUM > 0)
    CounterType               osCounterRef;
#endif
    WdgM_ModeIndFunPtrType    seModeInd;
} WdgM_SupervisedEntityType;


typedef struct
{
    uint16    trOffset;
    uint16    trNum;
    P2CONST(WdgM_CheckpointIdType, TYPEDEF, WDGM_CONST) FlowPtr;
    uint8     flowCpType;
    uint16    flowIndex;

    uint16    AliveIndex;

    uint16    DeadlineNum;
    P2CONST(uint16, TYPEDEF, WDGM_CONST) DeadlinePtr;
    uint8     DeadlineCpType;

} WdgM_CheckPointInModeCfgType;



typedef struct
{
    WdgM_SupervisedEntityIdType    seRef;
    uint16    trOffset;
    uint16    trNum;
    P2CONST(WdgM_CheckpointIdType, TYPEDEF, WDGM_CONST) FlowPtr;
    uint8     flowCpType; /* start or end cp pf flow*/
    uint16    flowIndex;
} WdgM_CheckPointCfgType;


/*  not used in this version
typedef struct
{
    uint8               WdgMWatchdogDeviceRef;
    WdgMWatchdogName
}WdgM_WatchdogType;
*/

typedef struct
{
    uint8               WdgMWatchdogDeviceRef;
    /*WdgMWatchdogName*/
    uint16              WdgMTriggerConditionValue;
    WdgIf_ModeType      WdgMWatchdogMode;
} WdgM_TriggerType;

typedef struct
{
    uint16                   WdgMMaxMargin;/* expexted + max*/
    uint16                   WdgMMinMargin;/* expexted - min*/
    uint16                   WdgMSupervisionReferenceCycle;
    WdgM_CheckpointIdType    WdgMAliveSupervisionCheckpointRef;
} WdgM_AliveSupervisionType;

typedef struct
{
    uint16                    WdgMDeadlineMax;
    uint16                    WdgMDeadlineMin;
    WdgM_CheckpointIdType     WdgMDeadlineStartRef;
    WdgM_CheckpointIdType     WdgMDeadlineStopRef;
} WdgM_DeadlineSupervisionType;




typedef struct
{
    uint8                         WdgMFailedAliveSupervisionRefCycleTol;
    WdgM_SupervisedEntityIdType   WdgMLocalStatusSupervisionEntityRef;
} WdgM_LocalStatusParamsType;

typedef struct
{
    uint16                                  WdgMExpiredSupervisionCycleTol;
    P2CONST(WdgM_CheckPointInModeCfgType, TYPEDEF, WDGM_CONST) WdgCpInMode;
    P2CONST(WdgM_AliveSupervisionType, TYPEDEF, WDGM_CONST)    WdgMAliveSupervision;
    P2CONST(WdgM_DeadlineSupervisionType, TYPEDEF, WDGM_CONST) WdgMDeadlineSupervision;
    P2CONST(WdgM_TriggerType, TYPEDEF, WDGM_CONST)             WdgMTrigger;
    P2CONST(WdgM_LocalStatusParamsType, TYPEDEF, WDGM_CONST)   WdgMLocalStatusParams;
    uint16                                  numOfAlive;
    uint16                                  numOfDeadline;
    uint8                                   numOfTrigger;
    WdgM_SupervisedEntityIdType             numOfLocalStatus;

} WdgM_ModeCfgType;

/*WDGM042*/
typedef struct
{
#if(STD_ON == WDGM_DEM_USED)
    Dem_EventIdType  setModeEventId;
    Dem_EventIdType  stopEventId;
#endif
    WdgM_ModeType    WdgMInitialMode;
    WdgM_ModeType    WdgMNumOfMode;
    P2CONST(WdgM_ModeCfgType, TYPEDEF, WDGM_CONST)  WdgMMode;
} WdgM_ConfigType;


#endif
