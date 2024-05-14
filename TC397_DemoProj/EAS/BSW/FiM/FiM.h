/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
*   File Name       : FiM.h
********************************************************************************
*   Project/Product : AUTOSAR 4.2
*   Title           : FiM module Header File
*   Author          : Hirain
********************************************************************************
*   Description     : FiM module Header File
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
#ifndef FIM_H
#define FIM_H

/*******************************************************************************
*   Includes
*******************************************************************************/
#include "FiM_Types.h"
/*******************************************************************************
*   Macro define
*******************************************************************************/
/*errors*/
#define FIM_E_UNINIT                                  ((uint8)0x01)
#define FIM_E_FID_OUT_OF_RANGE                        ((uint8)0x02)
#define FIM_E_EVENTID_OUT_OF_RANGE                    ((uint8)0x03)
#define FIM_E_PARAM_POINTER                           ((uint8)0x04)
#define FIM_E_INIT_FAILED                             ((uint8)0x05)
#define FIM_E_COMPONENTID_OUT_OF_RANGE				  ((uint8)0x06)
#define FIM_E_INVALID_PARAMETER                       ((uint8)0x07)
/*SWS_Fim_00076*/
/*API ID*/
#define FIM_INIT_API_ID                               ((uint8)0x00)
/*ECU State Manager<->FIM*/
#define FIM_GET_FUNCTION_PERMISSION_API_ID            ((uint8)0x01)
#define FIM_SET_FUNCTION_AVAILABLE_API_ID             ((uint8)0x07)
/*SWC<->FIM*/
#define FIM_DEM_TRIGGER_ON_EVENT_STATUS_API_ID        ((uint8)0x02)
#define FIM_DEM_TRIGGER_ON_COMPONENT_STATUS_API_ID    ((uint8)0x06)
#define FIM_DEMINIT_API_ID                            ((uint8)0x03)
#define FIM_GET_VERSION_INFO_API_ID                   ((uint8)0x04)
/*DEM<->FIM*/
#define FIM_MAIN_FUNCTION_API_ID                      ((uint8)0x05)
/*Scheduled function*/
#define FIM_INHIBITIONCALCULATION_API_ID			  ((uint8)0x08)

#define FIM_EVENT_TEST_BIT							  ((uint8)0x41)
/*******************************************************************************
*  Global Function Declaration
*******************************************************************************/
#define FIM_START_SEC_CODE
#include "MemMap.h"

extern FUNC(void, FIM_CODE) FiM_Init
( 
	P2CONST(FiM_ConfigType, AUTOMATIC, FIM_CONST) configPtr
);

extern FUNC(Std_ReturnType, FIM_CODE) FiM_GetFunctionPermission
( 
	FiM_FunctionIdType FID,
	P2VAR(boolean, AUTOMATIC, FIM_APPL_DATA) Permission
);

#if(FIM_AVAILABILITY_SUPPORT == STD_ON)
extern FUNC(Std_ReturnType,FIM_CODE) FiM_SetFunctionAvailable
(
    FiM_FunctionIdType FID,
    boolean Availability
);
#endif

#if(FIM_EVENT_UPDATE_TRIGGERED_BY_DEM == STD_ON)
extern FUNC(void,FIM_CODE) FiM_DemTriggerOnEventStatus
(
	Dem_EventIdType EventId,
	Dem_UdsStatusByteType EventStatusByteOld,
	Dem_UdsStatusByteType EventStatusByteNew
);
#endif

#if(FIM_DEM_COMPONENT_SUPPORT == STD_ON)
#if(FIM_EVENT_UPDATE_TRIGGERED_BY_DEM == STD_ON)
extern FUNC(void,FIM_CODE) FiM_DemTriggerOnComponentStatus
(
	Dem_ComponentIdType ComponentId,
	boolean ComponentFailedStatus
);
#endif
#endif

extern FUNC(void,FIM_CODE) FiM_DemInit
(
    void
);

#if(STD_ON == FIM_VERSION_INFO_API)
extern FUNC(void, FIM_CODE) FiM_GetVersionInfo
(
	P2VAR(Std_VersionInfoType,  AUTOMATIC, FIM_APPL_DATA) versioninfo
);
#endif

#if(FIM_EVENT_UPDATE_TRIGGERED_BY_DEM == STD_OFF && FIM_QUARY_MODE == FIM_CYCLICALLY)
extern FUNC(void, FIM_CODE) FiM_MainFunction
(
    void
);
#endif

#define FIM_STOP_SEC_CODE
#include "MemMap.h"

#endif/* FIM_H */




