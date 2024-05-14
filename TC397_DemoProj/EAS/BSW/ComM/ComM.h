/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
*   File Name       : ComM.h
********************************************************************************
*   Project/Product : AUTOSAR 4.2
*   Title           : ComM.h
*   Author          : Hirain
********************************************************************************
*   Description     : ComM.h
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
#ifndef COMM_H
#define COMM_H

/*SWS_ComM_00463*/
/*******************************************************************************
*   Includes
*******************************************************************************/
#include "ComM_PBcfg.h"
#include "ComM_Version.h"

/*******************************************************************************
*   Macro
*******************************************************************************/
/* Development Error */
#if (STD_ON == COMM_DEV_ERROR_DETECT)
/* SWS_ComM_00234 */
#define COMM_E_NOT_INITED                    (0x01u)
#define COMM_E_WRONG_PARAMETERS              (0x02u)
#define COMM_E_PARAM_POINTER                 (0x03u)
#define COMM_E_INIT_FAILED                   (0x04u)

/* Non Autosar Standard */
#define COMM_E_ILLEGAL_REQUEST               (0x05u)

/* API ID*/
#define COMM_INIT_APIID                          (0x01u)
#define COMM_DEINIT_APIID                        (0x02u)
#define COMM_GETSTATUS_APIID                     (0x03u)
#define COMM_GETINHIBITIONSTATUS_APIID           (0x04u)
#define COMM_REQUESTCOMMODE_APIID                (0x05u)
#define COMM_GETMAXCOMMODE_APIID                 (0x06u)
#define COMM_GETREQUESTEDCOMMODE_APIID           (0x07u)
#define COMM_GETCURRENTCOMMODE_APIID             (0x08u)
#define COMM_PREVENTWAKEUP_APIID                 (0x09u)
#define COMM_LIMITCHANNELTONOCOMMODE_APIID       (0x0bu)
#define COMM_LIMITECUTONOCOMMODE_APIID           (0x0cu)
#define COMM_READINHIBITCOUNTER_APIID            (0x0du)
#define COMM_RESETINHIBITCOUNTER_APIID           (0x0eu)
#define COMM_SETECUGROUPCLASSIFICATION_APIID     (0x0fu)
#define COMM_GETVERSIONINFO_APIID                (0x10u)

#define COMM_NM_NETWORKSTARTINDICATION_APIID     (0x15u)
#define COMM_NM_NETWORKMODE_APIID                (0x18u)
#define COMM_NM_PREPAREBUSSLEEPMODE_APIID        (0x19u)
#define COMM_NM_BUSSLEEPMODE_APIID               (0x1au)
#define COMM_NM_RESTARTINDICATION_APIID          (0x1bu)

#define COMM_DCM_ACTIVEDIAGNOSTIC_APIID          (0x1fu)
#define COMM_DCM_INACTIVEDIAGNOSTIC_APIID        (0x20u)

#define COMM_ECUM_WAKEUPINDICATION_APIID         (0x2au)

#define COMM_COMMUNICATIONALLOWED_APIID          (0x35u)

#define COMM_BUSSM_MODEINDICATION_APIID          (0x33u)
#define COMM_GETSTATE_APIID                      (0x34u)

#define COMM_MAINFUNCTION_APIID                  (0x60u)
#endif

/*******************************************************************************
* Global Vars Declaration
*******************************************************************************/
#define COMM_START_SEC_VAR_INIT_8
#include "MemMap.h"
/*SWS_ComM_00910*/
#if((STD_ON == COMM_PNC_SUPPORT) && (STD_ON == COMM_USED_PNC_ENABLED))
extern VAR(boolean, COMM_VAR) ComM_EIRAUpdateFlag;
#endif
#define COMM_STOP_SEC_VAR_INIT_8
#include "MemMap.h"

#define COMM_START_SEC_VAR_NOINIT_8
#include "MemMap.h"
/*This varible is not static since it will be access by NvM*/
extern VAR(ComM_InhibitionStatusType, COMM_VAR) ComMEcuGroupClassification;
#if(STD_ON == COMM_WAKEUP_INHIBITION_ENABLED)
/*This varible is not static since it will be access by NvM*/
extern VAR(boolean, COMM_VAR) ComMNoWakeup[COMM_NUM_OF_CHANNEL];
#endif
#define COMM_STOP_SEC_VAR_NOINIT_8
#include "MemMap.h"

#define COMM_START_SEC_VAR_NOINIT_16
#include "MemMap.h"
#if(STD_ON == COMM_MODE_LIMITATION_ENABLED)
/*SWS_ComM_00141*//*This varible is not static since it will be access by NvM*/
extern VAR(uint16, COMM_VAR) ComMInhibitCounter;
#endif
#define COMM_STOP_SEC_VAR_NOINIT_16
#include "MemMap.h"

/*******************************************************************************
*   Global Function Declaration
*******************************************************************************/
#define COMM_START_SEC_CODE
#include "MemMap.h"

extern FUNC(void, COMM_CODE) ComM_Init
(
    P2CONST(ComM_ConfigType, AUTOMATIC, COMM_CONST) ConfigPtr
);


extern FUNC(void, COMM_CODE) ComM_DeInit
(
    void
);

extern FUNC(Std_ReturnType, COMM_CODE) ComM_GetState
(
    NetworkHandleType Channel,
    P2VAR(ComM_StateType, AUTOMATIC, COMM_APPL_DATA) State
);

extern FUNC(void, COMM_CODE) ComM_MainFunction
(
    NetworkHandleType Channel
);


extern FUNC(Std_ReturnType, COMM_CODE) ComM_GetStatus
(
    P2VAR(ComM_InitStatusType, AUTOMATIC, COMM_APPL_DATA) Status
);

extern FUNC(Std_ReturnType, COMM_CODE) ComM_GetInhibitionStatus
(
    NetworkHandleType Channel,
    P2VAR(ComM_InhibitionStatusType, AUTOMATIC, COMM_APPL_DATA) Status
);

#if((STD_OFF == COMM_NMVARIANT_PASSIVE_ENABLED) || (STD_ON == COMM_NMVARIANT_ENABLED))
extern FUNC(Std_ReturnType, COMM_CODE) ComM_RequestComMode
(
    ComM_UserHandleType User,
    ComM_ModeType ComMode
);

extern FUNC(Std_ReturnType, COMM_CODE) ComM_GetMaxComMode
(
    ComM_UserHandleType User,
    P2VAR(ComM_ModeType, AUTOMATIC, COMM_APPL_DATA) ComMode
);

extern FUNC(Std_ReturnType, COMM_CODE) ComM_GetRequestedComMode
(
    ComM_UserHandleType User,
    P2VAR(ComM_ModeType, AUTOMATIC, COMM_APPL_DATA) ComMode
);

extern FUNC(Std_ReturnType, COMM_CODE) ComM_GetCurrentComMode
(
    ComM_UserHandleType User,
    P2VAR(ComM_ModeType, AUTOMATIC, COMM_APPL_DATA) ComMode
);
#endif

#if(STD_ON == COMM_WAKEUP_INHIBITION_ENABLED)
extern FUNC(Std_ReturnType, COMM_CODE) ComM_PreventWakeUp
(
    NetworkHandleType Channel,
    boolean Status
);
#endif

#if(STD_ON == COMM_MODE_LIMITATION_ENABLED)
extern FUNC(Std_ReturnType, COMM_CODE) ComM_LimitChannelToNoComMode
(
    NetworkHandleType Channel,
    boolean Status
);

extern FUNC(Std_ReturnType, COMM_CODE) ComM_LimitECUToNoComMode
(
    boolean Status
);

extern FUNC(Std_ReturnType, COMM_CODE) ComM_ReadInhibitCounter
(
    P2VAR(uint16, AUTOMATIC, COMM_APPL_DATA) CounterValue
);

extern FUNC(Std_ReturnType, COMM_CODE) ComM_ResetInhibitCounter
(
    void
);
#endif

extern FUNC(Std_ReturnType, COMM_CODE) ComM_SetECUGroupClassification
(
    ComM_InhibitionStatusType Status
);

#if(STD_ON == COMM_VERSION_INFO_API)
extern FUNC(void, COMM_CODE) ComM_GetVersionInfo
(
    P2VAR(Std_VersionInfoType, AUTOMATIC, COMM_APPL_DATA) VersionInfo
);
#endif

#define COMM_STOP_SEC_CODE
#include "MemMap.h"


#endif/* COMM_H */

