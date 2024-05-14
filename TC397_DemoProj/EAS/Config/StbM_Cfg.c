/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : StbM_Cfg.c
********************************************************************************
*   Project/Product : AUTOSAR BSW PROJECT
*   Title           : StbM module configuration File
*   Author          : Hirain
********************************************************************************
*   Description     : StbM module configuration File
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


/*******************************************************************************
    Includes Files
*******************************************************************************/
#include "StbM_Lcfg.h"
/*******************************************************************************
*   Config Parameters
*******************************************************************************/
#define STBM_START_SEC_CONFIG_DATA_8
#include "MemMap.h"
CONST(uint8, STBM_CONST) StbM_TimeBaseIdMap[(uint8)32] =
{
	(uint8)0, (uint8)32, (uint8)32, (uint8)32, (uint8)32, (uint8)32, (uint8)32, (uint8)32,
    (uint8)32, (uint8)32, (uint8)32, (uint8)32, (uint8)32, (uint8)32, (uint8)32, (uint8)32,
    (uint8)32, (uint8)32, (uint8)32, (uint8)32, (uint8)32, (uint8)32, (uint8)32, (uint8)32, 
    (uint8)32, (uint8)32, (uint8)32, (uint8)32, (uint8)32, (uint8)32, (uint8)32, (uint8)32
};
#define STBM_STOP_SEC_CONFIG_DATA_8
#include "MemMap.h"

#define STBM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"

/*******************************************************************************
*   StbMSynchronizedTimeBase
*******************************************************************************/
STATIC CONST(StbM_SyncLossTimeBaseType, STBM_CONST) StbMSyncLossThreshold[1] =
{
    {
    	(uint32)0,            /* Seconds */
    	(uint32)0            /* Nanoseconds */
    }
};

STATIC CONST(StbM_SyncLossTimeBaseType, STBM_CONST) StbMSyncLossTimeout[1] =
{
    {
    	(uint32)0,            /* Seconds */
    	(uint32)0            /* Nanoseconds */
    }
};
STATIC CONST(StbM_CounterInfoType, STBM_CONST) StbM_LocalTimeInfo[1] =
{
    {
        (CounterType)0,     /*CounterId*/
        (TickType)65535, /*CounterMaxAllowedValue*/
        (uint32)1000000,   /*NanosecondsPerTick*/
		1                /*LocalTimeHardwareType*/
    }
};


CONST(StbM_SynchronizedTimeBaseInfoType, STBM_CONST) StbM_SynchronizedTimeBaseInfo[STBM_NUM_OF_TIMEBASE] =
{
    /*Index 0*/
    {
        (StbM_SynchronizedTimeBaseType)STBM_TBID_StbMSynchronizedTimeBase,        /*StbMSynchronizedTimeBaseIdentifier*/
        TRUE,        /*StbMIsSystemWideGlobalTimeMaster*/
        STBM_STORAGE_AT_SHUTDOWN,        /*StbMStoreTimebaseNonVolatile*/
        &(StbMSyncLossThreshold[0]),        /*StbMSyncLossThreshold, Range:0-65535000000000, unit:ns*/
        &(StbMSyncLossTimeout[0]),        /*StbMSyncLossTimeout, Range:0-65535000000000, unit:ns*/
        &(StbM_LocalTimeInfo[0]),        /*StbMLocalTimeRef*/
    }
};

/*******************************************************************************
*   StbMTriggeredCustomer
*******************************************************************************/

#define STBM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"

