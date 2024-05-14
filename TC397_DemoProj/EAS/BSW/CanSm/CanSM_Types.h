/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
*   File Name       : CanSM_Types.h
********************************************************************************
*   Project/Product : AUTOSAR 4.2
*   Title           : CANSM module type definitions head File
*   Author          : HeYang
********************************************************************************
*   Description     : The header file CanSM_Types.h contains the  common type
*                     definitions of the module CanSM
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
#ifndef CANSM_TYPES_H
#define CANSM_TYPES_H

/*******************************************************************************
*   Includes
*******************************************************************************/
#include "CanSM_Cfg.h"/*CANSM254*/
#include "CanSM_Version.h"
/*SWS_CanSM_00017 to get API and modeType */
#include "CanIf.h"
/*SWS_CanSM_00191 to get ComM_BusSM_ModeIndication and ComM_ModeType*/
#include "ComM_BusSM.h"
#if(STD_ON == CANSM_DEM_SUPPORT)
#include "Dem.h"
#endif

/*******************************************************************************
*   Typedef
*******************************************************************************/

/*SWS_CanSM_00596*/
typedef enum
{
    CANSM_UNINITED = 0,
    CANSM_INITED = 1
} CanSM_StateType;

typedef enum
{
    CANSM_BSM_S_NOT_INITALIZED       = 0u,
    CANSM_BSM_S_NOCOM                = 1u,
    CANSM_BSM_S_SILENTCOM            = 2u,
    /* follow substate may need process in every main function */
    CANSM_BSM_S_FULLCOM              = 3u,
    CANSM_BSM_S_CHANGE_BAUDRATE      = 4u,
    CANSM_BSM_S_PRE_FULLCOM          = 5u,
    CANSM_BSM_S_PRE_NOCOM            = 6u,
    CANSM_BSM_S_WUVALIDATION         = 7u,
    CANSM_BSM_S_SILENTCOM_BOR        = 8u
} CanSM_MainStateType;


typedef enum
{
    CANSM_NO_SUBSTATE = 0u,
    CANSM_S_NO_BUS_OFF,
    /* follow substate may need process in every main function */
    CANSM_S_CHANGE_BR_SYNC,
    CANSM_S_TX_TIMEOUT_EXCEPTION,
    CANSM_S_BUS_OFF_CHECK,
    CANSM_S_TX_OFF,
    CANSM_S_CC_STOPPED,
    CANSM_S_CC_STOPPED_IND,
    CANSM_S_CC_SLEEP,
    CANSM_S_CC_SLEEP_IND,
    CANSM_S_CC_STARTED,
    CANSM_S_CC_START_IND,
    CANSM_S_TRCV_NORMAL,
    CANSM_S_TRCV_NORMAL_IND,
    CANSM_S_TRCV_STANDBY,
    CANSM_S_TRCV_STANDBY_IND,
    CANSM_S_RESTART_CC,
    CANSM_S_RESTART_CC_IND,
    CANSM_S_CC_STOPPED_WAIT,
    CANSM_S_CC_SLEEP_WAIT,
    CANSM_S_CC_STARTED_WAIT,
    CANSM_S_RESTART_CC_WAIT,
    CANSM_S_TRCV_NORMAL_WAIT,
    CANSM_S_TRCV_STANDBY_WAIT,
    CANSM_S_PN_CLEAR_WUF,
    CANSM_S_PN_CLEAR_WUF_WAIT,
    CANSM_S_PN_CLEAR_WUF_IND,
    CANSM_S_PN_CC_STOPPED,
    CANSM_S_CHECK_WFLAG_IN_NOT_CC_SLEEP,
    CANSM_S_CHECK_WFLAG_IN_CC_SLEEP,
    CANSM_S_CHECK_WFLAG_IN_CC_SLEEP_WAIT,
    CANSM_S_CHECK_WFLAG_IN_CC_SLEEP_IND,
    CANSM_S_CHECK_WUF_IN_NOT_CC_SLEEP_WAIT,
    CANSM_S_CHECK_WUF_IN_NOT_CC_SLEEP_IND,
    CANSM_S_CHECK_WUF_IN_CC_SLEEP_WAIT
} CanSM_subStateType;


typedef struct
{
    ComM_ModeType                ComMMode;  /* only saved when report to ComM */
    CanSM_MainStateType          CanSMState;
    CanSM_subStateType           CanSMSubState;
    uint8                        retryNum;
    uint16                       durationTime;
    uint16                       borDurationTime;/* bor delay time */
    uint8                        borCnt;        /* num of try to bor */
    uint16                       borEnSureTime;
#if(STD_ON == CANSM_SET_BAUDRATE_API)
    uint16                       savedBDId;
#endif
    boolean                      StateChangeFlag;
} CanSM_NeworkInfoType;

typedef struct
{
#if(STD_OFF == CANSM_CTRLOPT_SUPPORT)
    uint8  CanIfCtrlId;
#endif
    NetworkHandleType ComMNetworfRef;
#if(STD_ON == CANSM_CANTRCV_SUPPORT)
    uint8  CanIfTrcvId;
#endif
    uint8  cntL1toL2;
    uint16 BorTimeL1;
    uint16 BorTimeL2;
    /*all configured networkhandle is false that CANSM_BOR_TX_CONFIRMATION_POLLING = STD_OFF*/
#if(STD_ON == CANSM_BOR_TX_CONFIRMATION_POLLING)
    boolean BorTxConfirmationPoll;
#endif
    uint16 BorTimeEnsure;
#if(STD_ON == CANSM_DEM_SUPPORT)
    Dem_EventIdType BusOffEventId;
#endif
#if(STD_ON == CANSM_OSEKNM_SUPPORT)
    NetworkHandleType OsekNmHandle;
#endif
#if((STD_ON == CANSM_PNC_SUPPORT) && (STD_ON == CANSM_CANTRCV_SUPPORT))
    NetworkHandleType CanNmHandle;
#endif
} CanSM_NetworkCfgType;

/*SWS_CanSM_00597*/
typedef struct
{
    uint8   maxReqCnt;
    uint16  reqDuration;
    CONSTP2CONST(CanSM_NetworkCfgType, TYPEDEF, CANSM_CONST) netWorkCfg;
} CanSM_ConfigType;


#endif/*#ifndef CANSM_TYPES_H*/

