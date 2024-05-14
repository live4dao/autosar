/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
*   File Name       : FiM_Types.h
********************************************************************************
*   Project/Product : AUTOSAR 4.2
*   Title           : FiM module type definitions Header File
*   Author          : Hirain
********************************************************************************
*   Description     : The header file FiM_Types.h contains the  common type
*                     definitions of FiM module
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

#ifndef FIM_TYPES_H
#define FIM_TYPES_H

/*******************************************************************************
*   Includes
*******************************************************************************/
#include "Dem_Types.h"
#include "Std_Types.h"
#include "FiM_Cfg.h"

/*******************************************************************************
*   Typedef AutoSar standard FiM_Type
*******************************************************************************/

/*ECUC_FiM_00096*/
#define	FIM_LAST_FAILED                                                							   ((uint8)0x41)
#define	FIM_NOT_TESTED                                                							   ((uint8)0x40)
#define	FIM_TESTED                                                    							   ((uint8)0x00)
#define	FIM_TESTED_AND_FAILED                                          							   ((uint8)0x01)


#define FIM_CYCLICALLY 																			   1
#define FIM_ON_CALL_FUNCTION																	   2

/*
 SWS_Fim_00027
 AUTOSAR: 1..65535, 0 is not a valid value.
  Code: 0..65534, 65535 is not a valid value.
 */
typedef uint16 	  FiM_FunctionIdType;
typedef uint8 	  FiM_InhibitionMaskType;

typedef enum
{
	FIM_UNINITIALIZED = 0,
	FIM_INITIALIZED = 1,
	FIM_INITIALIZED_FULL = 2
} FiM_InitType;
#if(FIM_EVENT_UPDATE_TRIGGERED_BY_DEM == STD_OFF)
typedef struct
{
	const uint16 EventCfgNum;
	const Dem_EventIdType *EventIdPtr;
	const FiM_InhibitionMaskType *InhibitionMaskPtr;
}FiM_FunCfgType;
#else
typedef enum
{
	FIM_EVENT_OCCURED = 0,
	FIM_EVENT_NOT_OCCURED = 1,
	FIM_EVENT_NOT_CARED = 2
}FiM_EventStatusType;
typedef struct
{
	const Dem_EventIdType EventId;
	const uint16 FunctionNum;
	const FiM_FunctionIdType *FunctionIdPtr;
	const FiM_InhibitionMaskType *InhibitionMaskPtr;
	FiM_EventStatusType *EventNotOccuredFlag;
}FiM_EventCfgType;
#endif

#if(FIM_DEM_COMPONENT_SUPPORT == STD_ON)
typedef struct
{
	const uint16 FunctionCfgNum;
	const FiM_FunctionIdType *FunctionIdPtr;
}FiM_ComponentCfgType;
#endif

typedef struct
{
#if(FIM_EVENT_UPDATE_TRIGGERED_BY_DEM == STD_ON)
	const FiM_EventCfgType *EventCfgPtr;
#else
	const FiM_FunCfgType *FunCfgPtr;
#endif
#if(FIM_DEM_COMPONENT_SUPPORT == STD_ON)
	const FiM_ComponentCfgType *ComponentCfgPtr;
#endif
	const boolean *AvailabilityPtr;

}FiM_ConfigType;/*SWS_Fim_00092*/

/*ECUC_FiM_00085*/

#endif /*FIM_TYPES_H*/

