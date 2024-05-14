/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
*   File Name       : CanTSyn_Type.h
********************************************************************************
*   Project/Product : AUTOSAR 4.2
*   Title           : CanTSyn module type definitions Header File
*   Author          : Hirain
********************************************************************************
*   Description     : The header file CanTSyn_Type.h contains the  common type
*                     definitions of CanTSyn module
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

#ifndef CANTSYN_TYPE_H
#define CANTSYN_TYPE_H

/*******************************************************************************
*   Includes
*******************************************************************************/
#include "ComStack_Types.h"
#include "CanTSyn_Cfg.h"
#include "StbM_Types.h"
#if (CANTSYN_CRC_ENABLED == STD_ON)
#include "Crc.h"
#endif
/*******************************************************************************
*   Typedef AutoSar standard CanTSyn_Type
*******************************************************************************/
typedef enum
{
    CANTSYN_IDLE,
    CANTSYN_SYNC,
    CANTSYN_SYNC_DONE,
    CANTSYN_FUP,
    CANTSYN_FUP_DONE,
    CANTSYN_OFS,
    CANTSYN_OFS_DONE,
    CANTSYN_OFNS,
    CANTSYN_OFNS_DONE
}CanTSyn_StatusType;

/*ECUC_CanTSyn_00021*/
#define CRC_IGNORED         (0)
#define CRC_NOT_VALIDATED   (1)
#define CRC_VALIDATED       (2)

#define CRC_NOT_SUPPORTED (0)
#define CRC_SUPPORTED     (1)


#if (CANTSYN_CRC_ENABLED == STD_ON)
#define CANTSYN_CALCULATE_CRC                               Crc_CalculateCRC8H2F
#endif
#define CANTSYN_IDX_INVALID                     ((uint8)0xFF)

/*SWS_CanTSyn_00092*/
typedef enum
{
    CANTSYN_TX_OFF, /*Transmission Disabled*/
    CANTSYN_TX_ON   /*Transmission Enabled*/
}CanTSyn_TransmissionModeType;


typedef struct
{
    uint8 TrsSYNCIdx;
    uint8 TrsOFSIdx;
}CanTSyn_PduStsType;
#if(0 < CANTSYN_SYNC_MASTER_NUM || 0 < CANTSYN_OFS_MASTER_NUM)
typedef struct
{
    uint8 PduRef;
    StbM_SynchronizedTimeBaseType timeBaseId;
    uint8 DomainId;
    PduIdType PduId;
    uint16 TxTimeOut;
    uint16 DebounceTime;
    uint16 TxOffset;
    uint16 TxPeriod;
    uint8 CrcMode;
    uint8 ControllerId;
}CanTSyn_MasterTimerDomainType;
#endif
#if(0 < CANTSYN_SYNC_MASTER_NUM)
typedef struct
{
    CanTSyn_TransmissionModeType TxMode;
    CanTSyn_StatusType Status;
    boolean TransmittingFlag;
    uint16 TxTimeOut;
    uint16 DebounceTime;
    uint16 SyncTxOffsetTime;
    uint16 SyncTxPeriod;
    uint8 TxSyncSC;
    StbM_TimeStampType TxSyncTimeStamp;
    StbM_TimeStampRawType TxSyncTimeStampRaw;
    StbM_TimeStampRawType TxSyncTimeStampDiff;
    StbM_UserDataType UserData;
}CanTSyn_SYNCMasterParameterType;
#endif
#if(0 < CANTSYN_SYNC_MASTER_NUM || 0 < CANTSYN_OFS_MASTER_NUM)
typedef struct
{
    CanTSyn_TransmissionModeType TxMode;
    CanTSyn_StatusType Status;
    boolean TransmittingFlag;
    uint16 TxTimeOut;
    uint16 DebounceTime;
    uint16 OfsTxOffsetTime;
    uint16 OfsTxPeriod;
    uint8 TxOfsSC;
    StbM_TimeStampType TxOfsTimeStamp;
}CanTSyn_OFSMasterParameterType;
#endif

#if(0 < CANTSYN_SYNC_SLAVE_NUM || 0 < CANTSYN_OFS_SLAVE_NUM)
typedef struct
{
    StbM_SynchronizedTimeBaseType timeBaseId;
    uint8 DomainId;
    uint32 RxFollowUpTimeOut;
    uint8 JumpWidth;
    uint8 CrcMode;
    PduIdType PduId;
}CanTSyn_SlaveTimerDomainType;
#endif

#if(0 < CANTSYN_SYNC_SLAVE_NUM)
typedef struct
{    
    CanTSyn_StatusType Status;
    uint8 CurrentSC;
    uint8 SYNC_LastSC;
    boolean RxSYNCIsFirst;
    uint32 SyncTimeSec;
    uint32 SyncTimeNSec;
    StbM_TimeStampRawType TimeStampRaw;
    uint32 RxFollowUpTimeOut;
    StbM_UserDataType UserData;
}CanTSyn_SYNCSlaveParameterType;
#endif

#if(0 < CANTSYN_OFS_SLAVE_NUM)
typedef struct
{
    CanTSyn_StatusType Status;
    uint8 CurrentSC;
    uint8 OFS_LastSC;
    boolean RxOFSIsFirst;
    uint16 OfsTimeSecHi;
    uint32 OfsTimeSec;
    uint32 OfsTimeNSec;
    StbM_TimeStampRawType TimeStampRaw;
    uint32 RxFollowUpTimeOut;
    StbM_UserDataType UserData;
}CanTSyn_OFSSlaveParameterType;
#endif


typedef struct
{
#if(0 < CANTSYN_SYNC_MASTER_NUM)
    P2CONST(CanTSyn_MasterTimerDomainType, AUTOMATIC, CANTSYN_CONST) SYNCMaster_Cfg;
#endif
#if(0 < CANTSYN_OFS_MASTER_NUM)
    P2CONST(CanTSyn_MasterTimerDomainType, AUTOMATIC, CANTSYN_CONST) OFSMaster_Cfg;
#endif
#if(0 < CANTSYN_SYNC_SLAVE_NUM)
    P2CONST(CanTSyn_SlaveTimerDomainType, AUTOMATIC, CANTSYN_CONST) SYNCSlave_Cfg;
#endif
#if(0 < CANTSYN_OFS_SLAVE_NUM)
    P2CONST(CanTSyn_SlaveTimerDomainType, AUTOMATIC, CANTSYN_CONST) OFSSlave_Cfg;
#endif
}CanTSyn_ConfigType;

#endif /*CANTSYN_TYPE_H*/

