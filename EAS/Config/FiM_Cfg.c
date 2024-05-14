/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : FiM_Cfg.c
********************************************************************************
*   Project/Product : AUTOSAR BSW PROJECT
*   Title           : FiM module configuration File
*   Author          : Hirain
********************************************************************************
*   Description     : FiM module configuration File
*
********************************************************************************
*   Limitations     : None
*
********************************************************************************
*
********************************************************************************
*   Revision History:
*
*   Version     Date          Initials      CR#          Descriptions
*   ---------   ----------    ------------  ----------   ---------------
*   V1.0.2_3.5.5_AZ240046       09/05/2024    Eas           N/A          N/A
*
********************************************************************************
* END_FILE_HDR*/





#include "FiM_Lcfg.h"

#define FIM_START_SEC_CONFIG_DATA_8
#include "MemMap.h"
const FiM_InhibitionMaskType FiM_Event_0x940009_Mask[1] =
{
	FIM_TESTED_AND_FAILED
};

FiM_EventStatusType EventNotOccuredFlag_Event_0x940009[1];

boolean FiM_Permission[FIM_FUNCTION_NUM_CFG];

const boolean FiM_AvailabilityCfg[FIM_FUNCTION_NUM_CFG] =
{
	TRUE	
};
boolean FiM_Availability[FIM_FUNCTION_NUM_CFG];	
#define FIM_STOP_SEC_CONFIG_DATA_8
#include "MemMap.h"


#define FIM_START_SEC_CONFIG_DATA_16
#include "MemMap.h"



const FiM_FunctionIdType FiM_Event_0x940009_Function[1] =
{
	(FiM_FunctionIdType)0	
};




#define FIM_STOP_SEC_CONFIG_DATA_16
#include "MemMap.h"

#define FIM_START_SEC_CONFIG_DATA_32
#include "MemMap.h"
#define FIM_STOP_SEC_CONFIG_DATA_32
#include "MemMap.h"


#define FIM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"

const FiM_EventCfgType FiM_EventCfg[FIM_EVENT_NUM_CFG] =
{
	{
		(uint16)0,
		(uint16)1,
        &FiM_Event_0x940009_Function[0],
        &FiM_Event_0x940009_Mask[0],
        &EventNotOccuredFlag_Event_0x940009[0]
	},
};




CONST(FiM_ConfigType, FiM_CONST) FiM_Config =
{
	&FiM_EventCfg[0],
	&FiM_AvailabilityCfg[0]	
};
#define FIM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"


