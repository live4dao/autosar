/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
*   File Name       : CanTSyn.h
********************************************************************************
*   Project/Product : AUTOSAR 4.2
*   Title           : CanTSyn  module Header File
*   Author          : Hirain
********************************************************************************
*   Description     : CanTSyn module Header File
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

#ifndef CANTSYN_H
#define CANTSYN_H

/*******************************************************************************
*   Includes
*******************************************************************************/
#include "CanTSyn_Lcfg.h"
/*******************************************************************************
*   Macro define
*******************************************************************************/
/*SWS_CanTSyn_00089*/
#define CANTSYN_E_INVALID_PDUID                 ((uint8)0x01)
#define CANTSYN_E_NOT_INITIALIZED               ((uint8)0x02)
#define CANTSYN_E_NULL_POINTER                  ((uint8)0x03)
#define CANTSYN_E_INVALID_LENGTH                ((uint8)0x04)

#define CANTSYN_INIT_API_ID                     ((uint8)0x01)
#define CANTSYN_GET_VERSION_INFO_API_ID         ((uint8)0x02)
#define CANTSYN_SET_TRANSMISSION_MODE_API_ID    ((uint8)0x03)
#define CANTSYN_RX_INDICATION_API_ID            ((uint8)0x42)
#define CANTSYN_TX_CONFIRMATION_API_ID          ((uint8)0x40)
#define CANTSYN_MAIN_FUNCTION_API_ID            ((uint8)0x06)

#define CANTSYN_BYTE_0                          (0)
#define CANTSYN_BYTE_1                          (1)
#define CANTSYN_BYTE_2                          (2)
#define CANTSYN_BYTE_3                          (3)
#define CANTSYN_BYTE_4                          (4)
#define CANTSYN_BYTE_5                          (5)
#define CANTSYN_BYTE_6                          (6)
#define CANTSYN_BYTE_7                          (7)

#define CANTSYN_SYNC_NOT_CRC                    ((uint8)0x10)
#define CANTSYN_SYNC_CRC                        ((uint8)0x20)
#define CANTSYN_FUP_NOT_CRC                     ((uint8)0x18)
#define CANTSYN_FUP_CRC                         ((uint8)0x28)
#define CANTSYN_OFS_NOT_CRC                     ((uint8)0x30)
#define CANTSYN_OFS_CRC                         ((uint8)0x40)
#define CANTSYN_OFNS_NOT_CRC                    ((uint8)0x38)
#define CANTSYN_OFNS_CRC                        ((uint8)0x48)

#define CANTSYN_NS_MAXVALUE                     ((uint32)0x3B9ACA00)
#define CANTSYN_S_MAXVALUE                      ((uint32)0xFFFFFFFF)

#define CANTSYN_CRCSIZE                         ((uint8)7)
#define CANTSYN_CRC_OFFSET                      ((uint8)2)
#define CANTSYN_MSG_LENGTH                      ((PduLengthType)8)
#define CANTSYN_SC_OFFSET                       ((uint8)0x10)
#define CANTSYN_CRC_DATA_LENGTH                 ((uint8)1)
#define CANTSYN_NOT_CRC_DATA_LENGTH             ((uint8)3)

#define CANTSYN_SC_MASK                         ((uint8)0x0F)
#define CANTSYN_TD_MASK                         ((uint8)0xF0)
#define CANTSYN_OVS_MASK                        ((uint8)0x03)
#define CANTSYN_SGW_MASK                        ((uint8)0x04)

#define CANTSYN_SC_INVALID                      ((uint8)16)
#define CANTSYN_TD_SHIFT_BITS                   ((uint8)4)
#define CANTSYN_SGW_SHIFT_BITS                  ((uint8)2)
#define CANTSYN_SECONDSHIGH_SHIFT_BITS          ((uint8)8)
#define CANTSYN_UINT8_MASK                      ((uint8)0xFF)
#define CANTSYN_DATA_SHIFT_ONE_BYTE             ((uint8)8)
#define CANTSYN_DATA_SHIFT_TWO_BYTES            ((uint8)16)
#define CANTSYN_DATA_SHIFT_THREE_BYTES          ((uint8)24)
/*******************************************************************************
*  Global Function Declaration
*******************************************************************************/
#define CANTSYN_START_SEC_CODE
#include "MemMap.h"

extern FUNC(void, CANTSYN_CODE) CanTSyn_Init
( 
    P2CONST(CanTSyn_ConfigType, AUTOMATIC, CANTSYN_CONST) configPtr 
);

#if(STD_ON == CANTSYN_VERSION_INFO)
extern FUNC(void, CANTSYN_CODE) CanTSyn_GetVersionInfo
(
    P2VAR(Std_VersionInfoType, AUTOMATIC, CANTSYN_APPL_DATA) versioninfo
);
#endif

#if (0 < CANTSYN_SYNC_MASTER_NUM || 0 < CANTSYN_OFS_MASTER_NUM)
extern FUNC(void, CANTSYN_CODE) CanTSyn_SetTransmissionMode
(
    uint8 CtrlIdx,
    CanTSyn_TransmissionModeType Mode
);
#endif

extern FUNC(void, CANTSYN_CODE) CanTSyn_MainFunction
(
    void
);

extern FUNC(boolean, CANTSYN_CODE) CanTSyn_BeyondJumpWidth
(
    uint8 TimeDomainId
);

#define CANTSYN_STOP_SEC_CODE
#include "MemMap.h"


#endif/* CANTSYN_H */
