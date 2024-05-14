/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
*   File Name       : Dcm.h
********************************************************************************
*   Project/Product : AUTOSAR 4.2
*   Title           : Dcm.h
*   Author          : Hirain
********************************************************************************
*   Description:
*
********************************************************************************
*   Limitations:
*
********************************************************************************
*
********************************************************************************
*   Revision History:
*   Reference to Core C File
********************************************************************************
* END_FILE_HDR*/

#ifndef DCM_H
#define DCM_H

/*******************************************************************************
* Include files
*******************************************************************************/
#include "Dcm_Types.h"
#include "Dcm_Version.h"


/*******************************************************************************
* Macros and Typedef
*******************************************************************************/
/* Service ID[hex] */
#define DCM_SID_INIT                       0x01U
#define DCM_SID_GETVERSIONINFO             0x24U
#define DCM_SID_DEMTRIGGERONDTCSTATUS      0x2BU
#define DCM_SID_GETVIN                     0x07U

#define DCM_SID_SETSECURITYLEVEL           0x0CU
#define DCM_SID_GETSECURITYLEVEL           0x0DU
#define DCM_SID_GETSESCTRLTYPE             0x06U
#define DCM_SID_GETACTIVEPROTOCOL          0x0FU
#define DCM_SID_RESETTODEFAULTSESSION      0x2AU
#define DCM_SID_TRIGGERONEVENT             0x2DU
#define DCM_SID_SETACTIVEDIAGNOSTIC        0x56U

#define DCM_SID_STARTOFRECEPTION           0x46U
#define DCM_SID_COPYRXDATA                 0x44U
#define DCM_SID_TPRXINDICATION             0x45U
#define DCM_SID_COPYTXDATA                 0x43U
#define DCM_SID_TPTXCONFIRMATION           0x48U
#define DCM_SID_TXCONFIRMATION             0x40U
#define DCM_SID_COMMNOCOMMODEENTERED       0x21U
#define DCM_SID_COMMSILENTCOMMODEENTERED   0x22U
#define DCM_SID_COMMFULLCOMMODEENTERED     0x23U

#define DCM_SID_MAINFUNCTION               0x25U


/*SWS_Dcm_00044*/
/*SWS_Dcm_00040*/
#define DCM_E_INTERFACE_TIMEOUT            0x01U
#define DCM_E_INTERFACE_RETURN_VALUE       0x02U
#define DCM_E_INTERFACE_BUFFER_OVERFLOW    0x03U
#define DCM_E_UNINIT                       0x05U
#define DCM_E_PARAM                        0x06U
#define DCM_E_PARAM_POINTER                0x07U
#define DCM_E_INIT_FAILED                  0x08U
#define DCM_E_SET_PROG_CONDITIONS_FAIL     0x09U

#define DCM_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"
#if((DCM_UDS_2C_SERVICE == STD_ON)&&(DCM_DDDID_STORAGE == STD_ON))
extern VAR(Dcm_DspDDDIDElementInfoType, DCM_VAR)Dcm_DspDDDIDElement[DCM_CFG_ALL_DDDID_ELEMENT_NUM];
#endif
#define DCM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"

/*******************************************************************************
* Global Function Prototype
*******************************************************************************/
#define DCM_START_SEC_CODE
#include "MemMap.h"

/*SWS_Dcm_00037*/
extern FUNC(void, DCM_CODE) Dcm_Init
(
    P2CONST(uint32, AUTOMATIC, DCM_APPL_DATA) ConfigPtr
);

#if(STD_ON == DCM_VERSION_INFO_API)
/*SWS_Dcm_00065*/
extern FUNC(void, DCM_CODE) Dcm_GetVersionInfo
(
    P2VAR(Std_VersionInfoType, AUTOMATIC, DCM_APPL_DATA) versionInfo
);
#endif

/*SWS_Dcm_00614*/
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DemTriggerOnDTCStatus
(
    uint32 DTC,
    uint8 DTCStatusOld,
    uint8 DTCStatusNew
);


/*SWS_Dcm_00950*/
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_GetVin
(
    P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data
);

/*SWS_Dcm_00053*/
extern FUNC(void, DCM_CODE) Dcm_MainFunction
(
    void
);

#if(DCM_UDS_27_SERVICE == STD_ON)
/*SWS_Dcm_00338*/
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_GetSecurityLevel
(
    P2VAR(Dcm_SecLevelType, AUTOMATIC, DCM_APPL_DATA) SecLevel
);
#endif
/*SWS_Dcm_00339*/
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_GetSesCtrlType
(
    P2VAR(Dcm_SesCtrlType, AUTOMATIC, DCM_APPL_DATA) SesCtrlType
);

/*SWS_Dcm_00340*/
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_GetActiveProtocol
(
    P2VAR(Dcm_ProtocolType, AUTOMATIC, DCM_APPL_DATA) ActiveProtocol
);

/*SWS_Dcm_00520*/
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_ResetToDefaultSession
(
    void
);

/*SWS_Dcm_00521*/
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_TriggerOnEvent
(
    uint8 RoeEventId
);

#if(DCM_COMM_SUPPORT == STD_ON)
/*SWS_Dcm_01068*/
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_SetActiveDiagnostic
(
    boolean active
);
#endif

extern FUNC(Std_ReturnType, DCM_CODE) Dcm_ExternalSubServiceCheck
(
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
);


#define DCM_STOP_SEC_CODE
#include "MemMap.h"

#endif/*DCM_H*/


