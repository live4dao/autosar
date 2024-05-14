/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
*   File Name       : CanSM.h
********************************************************************************
*   Project/Product : AUTOSAR 4.2
*   Title           : CanSM module Header File
*   Author          : Hirain
********************************************************************************
*   Description     : CanSM module Header File
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

#ifndef CANSM_H
#define CANSM_H

/*******************************************************************************
*   Includes
*******************************************************************************/
#include "CanSM_Lcfg.h"
#include "CanSM_PBcfg.h"


/*******************************************************************************
*   Macro
*******************************************************************************/
/*APIID*/
#define   CANSM_INIT_SERVICE_ID                               (0x00u)
#define   CANSM_GETVERSIONINFO_SERVICE_ID                     (0x01u)
#define   CANSM_REQUESTCOMMODE_SERVICE_ID                     (0x02u)
#define   CANSM_GETCURRENTCOMMODE_SERVICE_ID                  (0x03u)
#define   CANSM_CONTROLLERBUSOFF_SERVICE_ID                   (0x04u)
#define   CANSM_MAINFUNCTION_SERVICE_ID                       (0x05u)
#define   CANSM_CONFPN_SERVICE_ID                             (0x06u)
#define   CANSM_CTRLMODEIND_SERVICE_ID                        (0x07u)
#define   CANSM_CLEARTRCVWUFFLAG_SERVICE_ID                   (0x08u)
#define   CANSM_TRCVMODEIND_SERVICE_ID                        (0x09u)
#define   CANSM_CHECKTRCVWUKFLAGIND_SERVICE_ID                (0x0Au)
#define   CANSM_TXTIMEOUTEX_SERVICE_ID                        (0x0Bu)
#define   CANSM_SETBAUDRATE_SERVICE_ID                        (0x0Du)
#define   CANSM_SETICOMCONIFGURATION_SERVICE_ID               (0x0Fu)
#define   CANSM_CURRENTICOMCONFIGURATION_SERVICE_ID           (0x10u)
#define   CANSM_STARTWAKEUPSOURCE_SERVICE_ID                  (0x11u)
#define   CANSM_STOPWAKEUPSOURCE_SERVICE_ID                   (0x12u)
#define   CANSM_SETECUPASSIVE_SERVICE_ID                      (0x13u)

#define   CANSM_WAITPROCESS_SERVICE_ID                        (0x50u)

/*Det Error Code CANSM069*/
#define   CANSM_E_UNINIT                      (0x01u)
#define   CANSM_E_PARAM_POINTER               (0x02u)
#define   CANSM_E_INVALID_NETWORK_HANDLE      (0x03u)
#define   CANSM_E_PARAM_CONTROLLER            (0x04u)
#define   CANSM_E_PARAM_TRANSCEIVER           (0x05u)
#define   CANSM_E_BUSOFF_RECOVERY_ACTIVE      (0x06u)
#define   CANSM_E_WAIT_MODE_INDICATION        (0x07u)
#define   CANSM_E_INVALID_COMM_REQUEST        (0x08u)
#define   CANSM_E_MODE_REQUEST_TIMEOUT        (0x0Au)

#define   CANSM_E_INVALID_NETWORK_STATE       (0x50u)



/*******************************************************************************
*   API Declare
*******************************************************************************/
#define CANSM_START_SEC_CODE
#include "MemMap.h"

/*SWS_CanSM_00008*/
extern FUNC(void, CANSM_CODE) CanSM_MainFunction(void);

#if(STD_ON ==  CANSM_VERSION_INFO_API)
extern FUNC(void, CANSM_CODE) CanSM_GetVersionInfo
(
    P2VAR(Std_VersionInfoType, AUTOMATIC, CANSM_APPL_DATA) VersionInfo
);
#endif

extern FUNC(void, CANSM_CODE) CanSM_Init
(
    P2CONST(CanSM_ConfigType, AUTOMATIC, CANSM_APPL_CONST) ConfigPtr
);

#if(STD_ON == CANSM_SET_BAUDRATE_API)/*SWS_CanSM_00569 SWS_CanSM_00570*/
extern FUNC(Std_ReturnType, CANSM_CODE) CanSM_SetBaudrate
(
    NetworkHandleType  network,
    uint16 BaudRateConfigID
);
#endif

#if(STD_ON == CANSM_ICOM_SUPPORT)/*SWS_CanSM_00599*/
extern FUNC(Std_ReturnType, CANSM_CODE) CanSM_SetIcomConfiguration
(
    NetworkHandleType  network,
    IcomConfigIdType ConfigurationId
);
#endif

#if(STD_ON == CANSM_TXOFFLINEACTIVE_SUPPORT)/*SWS_CanSM_00645*/
extern FUNC(Std_ReturnType, CANSM_CODE)  CanSM_SetEcuPassive
(
    boolean CanSM_Passive
);
#endif


#define CANSM_STOP_SEC_CODE
#include "MemMap.h"


#endif/*#ifndef CANSM_H*/

