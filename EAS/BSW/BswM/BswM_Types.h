/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
*   File Name       : BswM_Types.h
********************************************************************************
*   Project/Product : AUTOSAR 4.2
*   Title           : BswM_Types.h
*   Author          : Hirain
********************************************************************************
*   Description     : The header file BswM_Types.h contains the  common type
*                     definitions of the module BSW Mode Manager
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
#ifndef BSWM_TYPES_H
#define BSWM_TYPES_H

/*******************************************************************************
*   Includes
*******************************************************************************/
#include "Std_Types.h"
#include "BswM_Cfg.h"

#if(STD_ON == BSWM_DEM_ENABLED)
#include "Dem.h"
#endif

/*******************************************************************************
*   Type define
*******************************************************************************/
typedef uint8 BswMRuleType;
typedef uint8 BswMPortType;
typedef uint8 BswMActionListIdType;
typedef P2FUNC(Std_ReturnType, BSWM_CODE, BswM_ActionFuncType)(void);

/*BswM_Timer Status*/
typedef enum
{
    BSWM_TIMER_STOPPED = 0,
    BSWM_TIMER_STARTED,
    BSWM_TIMER_EXPIRED
} BswM_TimerState;

typedef enum
{
    BSWM_FALSE = 0,
    BSWM_TRUE = 1,
    BSWM_UNDEFINED = 0xff
} BswMRuleStateType;


typedef P2FUNC(BswMRuleStateType, BSWM_CODE, BswMRuleFuncType)(void);

#if(BSWM_MAX_GENERAL_REQUESTING_USER < 256U)
typedef uint8 BswM_UserType;
#elif(BSWM_MAX_GENERAL_REQUESTING_USER < 65536U)
typedef uint16 BswM_UserType;
#endif

#if(BSWM_MAX_GENERAL_REQUESTED_MODE < 256U)
typedef uint8 BswM_ModeType;
#elif(BSWM_MAX_GENERAL_REQUESTED_MODE < 65536U)
typedef uint16 BswM_ModeType;
#endif

typedef enum
{
    BSWM_DEFERRED = 0,
    BSWM_IMMEDIATE = 1
} BswMRequestProcessingType;

typedef enum
{
    BSWM_CONDITION = 0,
    BSWM_TRIGGER = 1
} BswMActionListExecutionType;

typedef enum
{
    BSWM_ACTION,
    BSWM_ACTIONLIST,
    BSWM_RULE
} BswMActionType;

typedef struct _sBswMActionListItem
{
#if(STD_ON == BSWM_ABORTONFAIL_ENABLED)
    boolean AbortOnFail;                  /*ECUC_BswM_00902*/
#endif
    BswMActionType ActionType;
    BswM_ActionFuncType ActionFunc;     /*ECUC_BswM_00825*/
    BswMActionListIdType ActionListId;
    BswMRuleType RuleId;
#if(STD_ON == BSWM_DEM_ENABLED)
    Dem_EventIdType EventId;               /*ECUC_BswM_00933*/
    Dem_EventStatusType EventStatus;
#endif
    P2CONST(struct _sBswMActionListItem, AUTOMATIC, BSWM_CONST) next;
} BswM_ActionListItemType;


typedef struct
{
    BswMActionListExecutionType Excution;
    P2CONST(BswM_ActionListItemType, AUTOMATIC, BSWM_CONST) ActionListHead;
} BswMActionList;


/*ECUC_BswM_00806*/
typedef struct
{
    BswMRuleStateType RuleInitState;          /*ECUC_BswM_00888*/
    BswMRuleFuncType RuleFunc;                /*ECUC_BswM_00819*/
    BswMActionListIdType RuleTrueActionList;  /*ECUC_BswM_00817*/
    BswMActionListIdType RuleFalseActionList; /*ECUC_BswM_00818*/
    BswMRequestProcessingType RequestProcessing;
} BswM_RuleCfgType;


/*SWS_BswM_00213 SWS_BswM_00042*/
typedef struct
{
    uint8   unused;
} BswM_ConfigType;


#endif/* BSWM_TYPES_H */

