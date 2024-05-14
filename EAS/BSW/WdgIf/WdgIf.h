/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
*   File Name       : WdgIf.h
********************************************************************************
*   Project/Product : AUTOSAR 4.2
*   Title           : WdgIf module Header File
*   Author          : Hirain
********************************************************************************
*   Description     : WdgIf module Header File
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
#ifndef WDGIF_H_
#define WDGIF_H_

/*******************************************************************************
*   Includes
*******************************************************************************/
#include "WdgIf_Types.h"
#include "WdgIf_Cfg.h"

/*******************************************************************************
*   Macro
*******************************************************************************/

/*SWS_WdgIf_00006: The WDGIF module shall be able to detect the following errors and
exceptions depending on its configuration (development/production)*/
#if(STD_ON == WDGIF_DEV_ERROR_DETECT)
/*API Service called with wrong device index parameter;Development*/
#define WDGIF_E_PARAM_DEVICE         ((uint8)0x01)
#define WDGIF_E_INV_POINTER          ((uint8)0x02)
#define WDGIF_E_PARAM_POINTER        ((uint8)0x03)

#define WDGIF_SETMODE_APIID          ((uint8)0x01)
#define WDGIF_SETTRIGGER_APIID       ((uint8)0x02)
#define WDGIF_GETVERSIONINFO_APIID   ((uint8)0x03)
#endif



/*******************************************************************************
*   Global Function Declaration   SWS_WdgIf_00010
*******************************************************************************/
#if(WDGIF_NUMBER_OF_DEVICE > 1)
typedef Std_ReturnType (*WdgSetModeFctPtrTyp)(WdgIf_ModeType Mode);
typedef void (*WdgTriggerFctPtrTyp)(uint16 Timeout);

#define WDGIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"

extern CONST(WdgSetModeFctPtrTyp, WDGIF_CONST) WdgSetModeFctPtrCfg [WDGIF_NUMBER_OF_DEVICE];
extern CONST(WdgTriggerFctPtrTyp, WDGIF_CONST) WdgTriggerFctPtrCfg[WDGIF_NUMBER_OF_DEVICE];

#define WDGIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"
#endif


#define WDGIF_START_SEC_CODE
#include "MemMap.h"

#if(WDGIF_NUMBER_OF_DEVICE > 1)
extern FUNC(Std_ReturnType, WDGIF_CODE) WdgIf_SetMode
(
    uint8 DeviceIndex,
    WdgIf_ModeType WdgMode
);

extern FUNC(void, WDGIF_CODE) WdgIf_SetTriggerCondition
(
    uint8 DeviceIndex,
    uint16 Timeout
);
#endif

#if (STD_ON ==  WDGIF_VERSION_INFO_API)
extern FUNC(void, WDGIF_CODE) WdgIf_GetVersionInfo
(
    P2VAR(Std_VersionInfoType, AUTOMATIC, WDGIF_APPL_DATA) VersionInfoPtr
);
#endif

#define WDGIF_STOP_SEC_CODE
#include "MemMap.h"


#endif /* WDGIF_H_ */
