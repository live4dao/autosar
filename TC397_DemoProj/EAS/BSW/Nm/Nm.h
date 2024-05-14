/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
*   File Name       : Nm.h
********************************************************************************
*   Project/Product : AUTOSAR 4.2
*   Title           : Nm.h
*   Author          : Hirain
********************************************************************************
*   Description     : Nm.h
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
#ifndef NM_H
#define NM_H

/*******************************************************************************
*   Includes
*******************************************************************************/
#include "Nm_Lcfg.h"
#include "Nm_Version.h"

/*****************************************************************************
 *  General QAC Suppression
 *****************************************************************************/
/*PRQA S 3432 EOF*/
/*
P2VAR and other macros in the Compiler conforms to AUTOSAR standard.There's no 
need to revise.
*/

/*******************************************************************************
*   Macro
*******************************************************************************/
/* Development Error */
#if (STD_ON == NM_DEV_ERROR_DETECT)
/* Nm232 */
#define NM_E_UNINIT                            (0x00u)
#define NM_E_HANDLE_UNDEF                      (0x01u)
#define NM_E_PARAM_POINTER                     (0x02u)

/* Non Autosar Standard */
#define NM_E_WRONG_INDICATION                  (0x03u)

/* API ID*/
#define NM_INIT_APIID                          (0x00u)
#define NM_PASSIVESTARTUP_APIID                (0x01u)
#define NM_NETWORKREQUEST_APIID                (0x02u)
#define NM_NETWORKRELEASE_APIID                (0x03u)
#define NM_DISABLECOMMUNICATION_APIID          (0x04u)
#define NM_ENABLECOMMUNICATION_APIID           (0x05u)
#define NM_SETUSERDATA_APIID                   (0x06u)
#define NM_GETUSERDATA_APIID                   (0x07u)
#define NM_GETPDUDATA_APIID                    (0x08u)
#define NM_REPEATEMESSAGEREQUEST_APIID         (0x09u)
#define NM_GETNODEIDENTIFIER_APIID             (0x0au)
#define NM_GETLOCALNODEIDENTIFIER_APIID        (0x0bu)
#define NM_CHECKREMOTESLEEPINDICATION_APIID    (0x0du)
#define NM_GETSTATE_APIID                      (0x0eu)
#define NM_GETVERSIONINFO_APIID                (0x0fu)
#define NM_NETWORKSTARTINDICATION_APIID        (0x11u)
#define NM_NETWORKMODE_APIID                   (0x12u)
#define NM_PREPAREBUSSLEEPMODE_APIID           (0x13u)
#define NM_BUSSLEEPMODE_APIID                  (0x14u)
#define NM_REMOTESLEEPINDICATION_APIID         (0x17u)
#define NM_REMOTESLEEPCANCELLATION_APIID       (0x18u)
#define NM_SYNCHRONIZATIONPOINT_APIID          (0x19u)
#define NM_COORDREADYTOSLEEPINDICATION_APIID   (0x1eu)
#define NM_COORDREADYTOSLEEPCANCELLATION_APIID (0x1fu)
#define NM_PDURXINDICATION_APIID               (0x15u)
#define NM_STATECHANGENOTIFICATION_APIID       (0x16u)
#define NM_REPEATMESSAGEINDICATION_APIID       (0x1au)
#define NM_TXTIMEOUTEXCEPTION_APIID            (0x1bu)
#define NM_CARWAKEUPINDICATION_APIID           (0x1du)
#define NM_MAINFUNCTION_APIID                  (0x10u)

#endif



/*******************************************************************************
*   Global Function Declaration
*******************************************************************************/
#define NM_START_SEC_CODE
#include "MemMap.h"

extern FUNC(void, NM_CODE) Nm_Init
(
    void
);

extern FUNC(Std_ReturnType, NM_CODE) Nm_PassiveStartUp
(
    CONST(NetworkHandleType, NMIF_CONST) NetworkHandle
);

#if(NM_PASSIVEMODE != NM_PASSIVEMODE_ENABLED_ONLY)
extern FUNC(Std_ReturnType, NM_CODE) Nm_NetworkRequest
(
    CONST(NetworkHandleType, NMIF_CONST) NetworkHandle
);

extern FUNC(Std_ReturnType, NM_CODE) Nm_NetworkRelease
(
    CONST(NetworkHandleType, NMIF_CONST) NetworkHandle
);
#endif

#if(STD_ON == NM_COM_CONTROL_ENABLED)
extern FUNC(Std_ReturnType, NM_CODE) Nm_DisableCommunication
(
    CONST(NetworkHandleType, NMIF_CONST) NetworkHandle
);

extern FUNC(Std_ReturnType, NM_CODE) Nm_EnableCommunication
(
    CONST(NetworkHandleType, NMIF_CONST) NetworkHandle
);
#endif


#if(STD_ON == NM_USER_DATA_ENABLED)
extern FUNC(Std_ReturnType, NM_CODE) Nm_SetUserData
(
    CONST(NetworkHandleType, NMIF_CONST) NetworkHandle,
    CONSTP2CONST(uint8, AUTOMATIC, NMIF_CONST) nmUserDataPtr
);

extern FUNC(Std_ReturnType, NM_CODE) Nm_GetUserData
(
    CONST(NetworkHandleType, NMIF_CONST) NetworkHandle,
    CONSTP2VAR(uint8, AUTOMATIC, NMIF_CONST) nmUserDataPtr
);

extern FUNC(Std_ReturnType, NM_CODE) Nm_GetPduData
(
    CONST(NetworkHandleType, NMIF_CONST) NetworkHandle,
    CONSTP2VAR(uint8, AUTOMATIC, NMIF_CONST) nmPduData
);
#endif

#if(STD_ON == NM_REMOTE_SLEEP_IND_ENABLED)
extern FUNC(Std_ReturnType, NM_CODE) Nm_CheckRemoteSleepIndication
(
    CONST(NetworkHandleType, NMIF_CONST) NetworkHandle,
    CONSTP2VAR(boolean, AUTOMATIC, NMIF_CONST) nmRemoteSleepIndPtr
);
#endif

extern FUNC(Std_ReturnType, NM_CODE) Nm_GetState
(
    CONST(NetworkHandleType, NMIF_CONST) NetworkHandle,
    CONSTP2VAR(Nm_StateType, AUTOMATIC, NMIF_CONST) nmStatePtr,
    CONSTP2VAR(Nm_ModeType, AUTOMATIC, NMIF_CONST) nmModePtr
);

#if(STD_ON == NM_NODE_DETECTION_ENABLED)
extern FUNC(Std_ReturnType, NM_CODE) Nm_RepeatMessageRequest
(
    CONST(NetworkHandleType, NMIF_CONST) NetworkHandle
);
#endif

#if(STD_ON == NM_NODE_ID_ENABLED)
FUNC(Std_ReturnType, NM_CODE) Nm_GetNodeIdentifier
(
    CONST(NetworkHandleType, NMIF_CONST) NetworkHandle,
    CONSTP2VAR(uint8, AUTOMATIC, NMIF_CONST) nmNodeIdPtr
);

FUNC(Std_ReturnType, NM_CODE) Nm_GetLocalNodeIdentifier
(
    CONST(NetworkHandleType, NMIF_CONST) NetworkHandle,
    CONSTP2VAR(uint8, AUTOMATIC, NMIF_CONST) nmNodeIdPtr
);
#endif

#if(NM_VERSION_INFO_API == STD_ON)
extern FUNC(void, NM_CODE) Nm_GetVersionInfo
(
    P2VAR(Std_VersionInfoType, AUTOMATIC, NM_APPL_DATA) nmVerInfoPtr
);
#endif

#define NM_STOP_SEC_CODE
#include "MemMap.h"


#endif/* _NM_H_ */

