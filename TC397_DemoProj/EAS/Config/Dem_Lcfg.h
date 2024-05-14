/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : Dem_Lcfg.h
********************************************************************************
*   Project/Product : AUTOSAR BSW PROJECT
*   Title           : Dem module configuration File
*   Author          : Hirain
********************************************************************************
*   Description     : Dem module configuration File
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
*   V1.0.0_3.5.5_AZ240046       27/03/2024    Eas           N/A          N/A
*
********************************************************************************
* END_FILE_HDR*/
#ifndef DEM_LCFG_H
#define DEM_LCFG_H

/*******************************************************************************
*   Include files
*******************************************************************************/
#include "Dem_Types.h"

/*******************************************************************************
*   Dem Container:DemGeneral
*******************************************************************************/
#define DEM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"


/*DemOperationCycle*/
extern CONST(Dem_OperationCycleInfoType,DEM_CONST) Dem_OperationCycleTable[DEM_NUM_OF_OPCYCLE];

/*DemEnableCondition*/
extern CONST(Dem_EnableConditionType,DEM_CONST) Dem_EnConditionTable[DEM_NUM_OF_EN_CONDITION];

/*DemEnableConditionGroup*/
extern CONST(Dem_EnableConditionGroupType,DEM_CONST) Dem_EnConditionGroupTable[DEM_NUM_OF_EN_GROUP];

/*DemNvRamBlockId*/
extern CONST(Dem_NvRamBlockIdType,DEM_CONST) Dem_NvRamBlockIdTable[DEM_NUM_OF_BLOCKID];

#define DEM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"

#define DEM_START_SEC_CONFIG_DATA_32
#include "MemMap.h"


/*DemGroupOfDTC*/
extern CONST(Dem_DTCGroupType,DEM_CONST) Dem_GroupOfDTCTable[DEM_NUM_OF_DTCGROUP];

#define DEM_STOP_SEC_CONFIG_DATA_32
#include "MemMap.h"

#define DEM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"


/*DemFreezeFrameRecNumClass*/
extern CONST(Dem_FreezeFrameRecNumClassType,DEM_CONST) Dem_FFRecNumClassTable[DEM_NUM_OF_FFRECNUM];

/*DemFreezeFrameRecordClass*/
extern CONST(Dem_FreezeFrameRecordClassType,DEM_CONST) Dem_FFRecClassTable[DEM_NUM_OF_FFRECCLASS];

/*DemDidClass*/
extern CONST(Dem_DidClassType,DEM_CONST) Dem_DidClassTable[DEM_NUM_OF_DID];

/*DemDataElementClass*/
extern CONST(Dem_DataElementClassType,DEM_CONST) Dem_DataElementClassTable[DEM_NUM_OF_DATA];

/*DemExtendedDataClass*/
extern CONST(Dem_ExtendedDataClassType,DEM_CONST) Dem_ExtDataClassTable[DEM_NUM_OF_EXTDATACLASS];

/*DemExtendedDataRecordClass*/
extern CONST(Dem_ExtendedDataRecordClassType,DEM_CONST) Dem_ExtDataRecClassTable[DEM_NUM_OF_EXTDATAREC];

/*DemCallbackDTCStatusChangedFnc*/
extern CONST(Dem_DTCStatusChangedNotificationType,DEM_CONST) Dem_DtcStatusChangedNotificationArray[1];

/*******************************************************************************
*   Dem Container:DemConfigSet
*******************************************************************************/

/*DemEventParameter*/
extern CONST(Dem_EventParameterType,DEM_CONST) Dem_EventTable[DEM_NUM_OF_EVENT];

/*DemDTC*/
extern CONST(Dem_DTCInfoType,DEM_CONST) Dem_DTCTable[DEM_NUM_OF_DTC];

/*DemDTCAttributes*/
extern CONST(Dem_DTCAttributesType,DEM_CONST) Dem_DTCAttributesTable[DEM_NUM_OF_DTCATB];

/*DemDebounceCounterBasedClass*/
extern CONST(Dem_DebounceCounterBasedClassType,DEM_CONST) Dem_DebounceCounterBasedClassTable[DEM_NUM_OF_COUNTER_BASED];

/*DemDebounceTimeBaseClass*/
extern CONST(Dem_DebounceTimeBaseClassType,DEM_CONST) Dem_DebounceTimeBaseClassTable[DEM_NUM_OF_TIME_BASED];
#define DEM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"


#endif




