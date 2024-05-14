/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
*   File Name       : StbM_Types.h
********************************************************************************
*   Project/Product : AUTOSAR 4.2
*   Title           : StbM_Types.h
*   Author          : Hirain
********************************************************************************
*   Description     : The header file StbM_Types.h contains the declaration of
*                     types which is used by the StbM module
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
#ifndef STBM_TYPES_H
#define STBM_TYPES_H

/*******************************************************************************
*   Includes
*******************************************************************************/
#include "StbM_Cfg.h"
#include "Rte_StbM_Type.h"

#if(StbM_OS_ENABLED == STD_ON)
#include "Os_Types.h"
#else
typedef    uint8                      StatusType;
typedef    uint32                     TickType;
typedef    uint8                      CounterType;
typedef    uint32*                    TickRefType;
#define    E_OS_OK                    ((StatusType)0x00)
#define    E_OS_ACCESS                ((StatusType)0x01)
#endif 

/*******************************************************************************
*   typedef
*******************************************************************************/
#define STBM_ETH_TIMEDOMIN_INVALID            ((uint8)0xFF)
#define STBM_TIME_BASE_INVALID                ((StbM_SynchronizedTimeBaseType)32)


/*SWS_StbM_00249*/
typedef struct
{
    /*Stbm only supports pre-compile in autosr 422*/
    uint8 ConfigSetId;
} StbM_ConfigType;


/*SWS_StbM_00194*/
typedef uint64 StbM_TimeStampRawType;


typedef enum
{
    STBM_NO_STORAGE           = 0U,
    STBM_STORAGE_AT_SHUTDOWN  = 1U
} StbM_StoreTimebaseNonVolatileType;
typedef enum
{
    STBM_USERDEF = 0,
    STBM_OS
}StbM_LocalTimeHardwareType;  

typedef struct
{
    CounterType CounterId;
    TickType CounterMaxAllowedValue;
    uint32 NanosecondsPerTick;
    StbM_LocalTimeHardwareType StbMLocalTimeHardware;
} StbM_CounterInfoType;

typedef struct
{
    uint32 Seconds;
    uint32 Nanoseconds;
} StbM_SyncLossTimeBaseType;

/*ECUC_StbM_00003*/
typedef struct
{
    /*ECUC_StbM_00021*/
    StbM_SynchronizedTimeBaseType StbMSynchronizedTimeBaseIdentifier;
    /*ECUC_StbM_00036*/
    boolean StbMIsSystemWideGlobalTimeMaster;
    /*ECUC_StbM_00031*/
#if(STBM_NONVOLATILE_SUPPORT == STD_ON)
    StbM_StoreTimebaseNonVolatileType StbMStoreTimebaseNonVolatile;
#endif
    /*ECUC_StbM_00029*/
    P2CONST(StbM_SyncLossTimeBaseType, TYPEDEF, STBM_CONST) StbMSyncLossThreshold;
    /*ECUC_StbM_00028*/
    P2CONST(StbM_SyncLossTimeBaseType, TYPEDEF, STBM_CONST) StbMSyncLossTimeout;
    /*ECUC_StbM_00033*/
#if(STBM_ETH_GLOBALTIME_USED == STD_ON)
    uint8 StbMEthGlobalTimeDomainRef;/*0xFF means no reference*/
#endif
    /*ECUC_StbM_00006*/
    P2CONST(StbM_CounterInfoType, TYPEDEF, STBM_CONST) StbMLocalTimeRef;
    /*ECUC_StbM_00030*//*SWS_StbM_00193*/
#if(STBM_OFFSETTIMEBASE_USED == STD_ON)
    StbM_SynchronizedTimeBaseType StbMOffsetTimeBase;
#endif
    
} StbM_SynchronizedTimeBaseInfoType;

#if(STBM_NUM_OF_TRIGGEREDCUSTOMER > 0)
/*ECUC_StbM_00004*/
typedef struct
{
    /*ECUC_StbM_00020*//*SWS_StbM_00093*/
    uint32 StbMTriggeredCustomerPeriod;/*unit:us*/
    /*ECUC_StbM_00007*/
    ScheduleTableType StbMOSScheduleTableRef;
    uint32 StbMOSScheduleTableDuration;/*unit: tick*/
    uint32 StbMOSScheduleTableNanosecondsPerTick;
    /*ECUC_StbM_00010*//*SWS_StbM_00022*/
    StbM_SynchronizedTimeBaseType StbMSynchronizedTimeBaseRef;
} StbM_TriggeredCustomerType;
#endif

#endif /*STBM_TYPES_H*/

