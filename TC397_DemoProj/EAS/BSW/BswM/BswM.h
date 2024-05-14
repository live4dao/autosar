/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
*   File Name       : BswM.h
********************************************************************************
*   Project/Product : AUTOSAR 4.2
*   Title           : BswM.h
*   Author          : Hirain
********************************************************************************
*   Description     : BswM.h
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
#ifndef BSWM_H
#define BSWM_H

/*******************************************************************************
*   Includes
*******************************************************************************/
#include "BswM_Version.h"
#include "BswM_Lcfg.h"
#include "BswM_PBcfg.h"


/*******************************************************************************
*   Macro
*******************************************************************************/
/* Development Error */
#if (STD_ON == BSWM_DEV_ERROR_DETECT)
/*SWS_EcuM_04032*/
#define BSWM_E_NO_INIT                       (0x01u)
#define BSWM_E_NULL_POINTER                  (0x02u)
#define BSWM_E_INVALID_PAR                   (0x03u)
#define BSWM_E_REQ_USER_OUT_OF_RANGE         (0x04u)
#define BSWM_E_REQ_MODE_OUT_OF_RANGE         (0x05u)
#define BSWM_E_PARAM_CONFIG                  (0x06u)
#define BSWM_E_PARAM_POINTER                 (0x07u)
#define BSWM_E_ACTION_FAILED                 (0x08u)

/* Non Autosar Standard */

/* API ID*/
#define BSWM_INIT_APIID                          (0x00u)
#define BSWM_GETVERSIONINFO_APIID                (0x01u)
#define BSWM_REQUESTMODE_APIID                   (0x02u)
#define BSWM_MAINFUNCTION_APIID                  (0x03u)
#define BSWM_DEINIT_APIID                        (0x04u)
#define BSWM_CANSM_CURRENTSTATE_APIID            (0x05u)
#define BSWM_DCM_COMMUNICATIONMODE_CURRENTSTATE_APIID              (0x06u)
#define BSWM_LINSM_CURRENTSTATE_APIID            (0x09u)
#define BSWM_LINSM_CURRENTSCHEDULE_APIID         (0x0au)
#define BSWM_LINTP_REQUESTMODE_APIID             (0x0bu)
#define BSWM_FRSM_CURRENTSTATE_APIID             (0x0cu)
#define BSWM_ETHSM_CURRENTSTATE_APIID            (0x0du)
#define BSWM_COMM_CURRENTMODE_APIID              (0x0eu)
#define BSWM_ECUM_CURRENTSTATE_APIID             (0x0fu)
#define BSWM_ECUM_CURRENTWAKEUP_APIID            (0x10u)
#define BSWM_WDGM_REQUESTPARTITIONRESET_APIID    (0x11u)
#define BSWM_TRIGGERSTARTUPPHASE2_APIID          (0x12u)
#define BSWM_TRIGGERSLAVERTESTOP_APIID           (0x13u)
#define BSWM_DCM_APPLICATIONUPDATED_APIID        (0x14u)
#define BSWM_COMM_CURRENTPNCMODE_APIID           (0x15u)
#define BSWM_NVM_CURRENTBLOCKMODE_APIID          (0x16u)
#define BSWM_NVM_CURRENTJOBMODE_APIID            (0x17u)
#define BSWM_J1938NM_STATECHANGENOTIFICATION_APIID (0x18u)
#define BSWM_CANSM_CURRENTICOMCONF_APIID         (0x1au)
#define BSWM_J1938DCMBROADCASTSTATUS_APIID       (0x1bu)
#define BSWM_BSWMMODEREQUEST_APIID               (0x1cu)
#define BSWM_BSWMMODESWITCHNOTIFICATION_APIID    (0x1du)
#define BSWM_BSWMPARTITIONRESTARTED_APIID        (0x1eu)
#define BSWM_SD_CLENTSERVICECURRENTSTATE_APIID   (0x1fu)
#define BSWM_SD_EVENTHANDLERCURRENTSTATE_APIID   (0x20u)
#define BSWM_SD_CONSUMEDEVENTGROUPCURRENTSTATE_APIID   (0x21u)
#define BSWM_COMM_INITIATERESET_APIID            (0x22u)
#define BSWM_ECUM_REQUESTEDSTATE_APIID           (0x23u)
#define BSWM_NMIF_CARWAKEUPINDICATION_APIID      (0x24u)
#endif


/*******************************************************************************
*   API Declaration
*******************************************************************************/
#define BSWM_START_SEC_CODE
#include "MemMap.h"

extern FUNC(void, BSWM_CODE) BswM_Init
(
    P2CONST(BswM_ConfigType, AUTOMATIC, BSWM_CONST) ConfigPtr
);


extern FUNC(void, BSWM_CODE) BswM_Deinit
(
    void
);

#if(STD_ON == BSWM_VERSION_INFO_API)
extern FUNC(void, BSWM_CODE) BswM_GetVersionInfo
(
    P2VAR(Std_VersionInfoType, AUTOMATIC, BSWM_APPL_DATA) VersionInfo
);
#endif

#if(STD_ON == BSWM_GENERIC_REQUEST_ENABLED)
extern FUNC(void, BSWM_CODE) BswM_RequestMode
(
    BswM_UserType requesting_user,
    BswM_ModeType requested_mode
);
#endif

#if(STD_ON == BSWM_MULTIPATITION_ENABLED)
extern FUNC(void, BSWM_CODE) BswM_BswMPartitionRestarted
(
    void
);

#endif

extern FUNC(void, BSWM_CODE) BswM_MainFunction
(
    void
);

#if(STD_ON == BSWM_TIMER_ENABLED)
extern FUNC(void, BSWM_CODE) BswM_SetTimer
(
    uint8 TimerValue
);
#endif

#define BSWM_STOP_SEC_CODE
#include "MemMap.h"


#endif/* BSWM_H */

