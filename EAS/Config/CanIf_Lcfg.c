/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : CanIf_Lcfg.c
********************************************************************************
*   Project/Product : AUTOSAR BSW PROJECT
*   Title           : CanIf module configuration File
*   Author          : Hirain
********************************************************************************
*   Description     : CanIf module configuration File
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

/*******************************************************************************
*   Includes
*******************************************************************************/
#include "CanIf.h"
#include "Can.h"
#include "CanTSyn.h"
#include "CanTSyn_Cbk.h"

/*******************************************************************************
*   Global Vars
*******************************************************************************/
#define CANIF_START_SEC_VAR_NOINIT_8
#include "MemMap.h"
VAR(CanIf_ControllerModeType, CANIF_VAR_NOINIT) CanIf_ControllerMode[2];
VAR(CanIf_PduModeType, CANIF_VAR_NOINIT) CanIf_PduMode[2];
VAR(boolean, CANIF_VAR_NOINIT) CanIf_TxBufActiveFlag[14];
STATIC VAR(uint8, CANIF_VAR_NOINIT) CanIf_TxQueueBuf0[64];
STATIC VAR(uint8, CANIF_VAR_NOINIT) CanIf_TxQueueBuf1[64];
STATIC VAR(uint8, CANIF_VAR_NOINIT) CanIf_TxQueueBuf2[64];
STATIC VAR(uint8, CANIF_VAR_NOINIT) CanIf_TxQueueBuf3[64];
STATIC VAR(uint8, CANIF_VAR_NOINIT) CanIf_TxQueueBuf4[64];
STATIC VAR(uint8, CANIF_VAR_NOINIT) CanIf_TxQueueBuf5[64];
STATIC VAR(uint8, CANIF_VAR_NOINIT) CanIf_TxQueueBuf6[64];
STATIC VAR(uint8, CANIF_VAR_NOINIT) CanIf_TxQueueBuf7[64];
STATIC VAR(uint8, CANIF_VAR_NOINIT) CanIf_TxQueueBuf8[64];
STATIC VAR(uint8, CANIF_VAR_NOINIT) CanIf_TxQueueBuf9[64];
STATIC VAR(uint8, CANIF_VAR_NOINIT) CanIf_TxQueueBuf10[64];
STATIC VAR(uint8, CANIF_VAR_NOINIT) CanIf_TxQueueBuf11[64];
STATIC VAR(uint8, CANIF_VAR_NOINIT) CanIf_TxQueueBuf12[64];
STATIC VAR(uint8, CANIF_VAR_NOINIT) CanIf_TxQueueBuf13[64];
#define CANIF_STOP_SEC_VAR_NOINIT_8
#include "MemMap.h"

#define CANIF_START_SEC_VAR_NOINIT_8
#include "MemMap.h"
VAR(PduIdType, CANIF_VAR_NOINIT) CanIf_TxBufferFillCount[33];
#define CANIF_STOP_SEC_VAR_NOINIT_8
#include "MemMap.h"

#define CANIF_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"
VAR(Can_PduType, CANIF_VAR_NOINIT) CanIf_TxBufPdu[14];
#define CANIF_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"


/*******************************************************************************
*   Config Parameters
*******************************************************************************/
#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"
CONST(CanIf_CanWriteType, CANIF_CONST)                CanIf_Can_Write[1] =
{
    &Can_Write
};
CONST(CanIf_CanSetControllerModeType, CANIF_CONST)    CanIf_Can_SetControllerMode[1] =
{
    &Can_SetControllerMode
};
CONST(CanIf_User_TxConfirmationType, CANIF_CONST)           CanIf_TxConfirmationName[4] =
{
    &CanTSyn_TxConfirmation,
    &PduR_CanIfTxConfirmation,
    &CanNm_TxConfirmation,
    &CanTp_TxConfirmation,
};
CONST(CanIf_User_RxIndicationType, CANIF_CONST)           CanIf_RxIndicationName[3] =
{
    &PduR_CanIfRxIndication,
    &CanNm_RxIndication,
    &CanTp_RxIndication,
};
CONST(CanIf_CtrlCfgType, CANIF_CONST)           CanIf_CtrlCfg[2] =
{
    {FALSE},
    {FALSE},
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"
CONST(CanIf_HthCfgType, CANIF_CONST) CanIf_HthCfg[33] =
{
    {CanIf_CanIf_CanCtrl_0, FALSE, 51, (PduIdType)0, (PduIdType)2},
    {CanIf_CanIf_CanCtrl_0, FALSE, 52, (PduIdType)2, (PduIdType)2},
    {CanIf_CanIf_CanCtrl_0, FALSE, 53, (PduIdType)4, (PduIdType)2},
    {CanIf_CanIf_CanCtrl_0, FALSE, 54, (PduIdType)6, (PduIdType)2},
    {CanIf_CanIf_CanCtrl_0, FALSE, 55, (PduIdType)8, (PduIdType)2},
    {CanIf_CanIf_CanCtrl_0, FALSE, 56, (PduIdType)10, (PduIdType)2},
    {CanIf_CanIf_CanCtrl_0, FALSE, 57, (PduIdType)12, (PduIdType)2},
    {CanIf_CanIf_CanCtrl_0, TRUE, 58, (PduIdType)0, (PduIdType)0},
    {CanIf_CanIf_CanCtrl_0, TRUE, 59, (PduIdType)0, (PduIdType)0},
    {CanIf_CanIf_CanCtrl_0, TRUE, 60, (PduIdType)0, (PduIdType)0},
    {CanIf_CanIf_CanCtrl_0, TRUE, 61, (PduIdType)0, (PduIdType)0},
    {CanIf_CanIf_CanCtrl_0, TRUE, 62, (PduIdType)0, (PduIdType)0},
    {CanIf_CanIf_CanCtrl_0, TRUE, 63, (PduIdType)0, (PduIdType)0},
    {CanIf_CanIf_CanCtrl_0, TRUE, 64, (PduIdType)0, (PduIdType)0},
    {CanIf_CanIf_CanCtrl_0, TRUE, 65, (PduIdType)0, (PduIdType)0},
    {CanIf_CanIf_CanCtrl_0, TRUE, 66, (PduIdType)0, (PduIdType)0},
    {CanIf_CanIf_CanCtrl_0, TRUE, 67, (PduIdType)0, (PduIdType)0},
    {CanIf_CanIf_CanCtrl_0, TRUE, 68, (PduIdType)0, (PduIdType)0},
    {CanIf_CanIf_CanCtrl_0, TRUE, 69, (PduIdType)0, (PduIdType)0},
    {CanIf_CanIf_CanCtrl_0, TRUE, 70, (PduIdType)0, (PduIdType)0},
    {CanIf_CanIf_CanCtrl_0, TRUE, 71, (PduIdType)0, (PduIdType)0},
    {CanIf_CanIf_CanCtrl_0, TRUE, 72, (PduIdType)0, (PduIdType)0},
    {CanIf_CanIf_CanCtrl_0, TRUE, 73, (PduIdType)0, (PduIdType)0},
    {CanIf_CanIf_CanCtrl_0, TRUE, 74, (PduIdType)0, (PduIdType)0},
    {CanIf_CanIf_CanCtrl_0, TRUE, 75, (PduIdType)0, (PduIdType)0},
    {CanIf_CanIf_CanCtrl_0, TRUE, 76, (PduIdType)0, (PduIdType)0},
    {CanIf_CanIf_CanCtrl_0, TRUE, 77, (PduIdType)0, (PduIdType)0},
    {CanIf_CanIf_CanCtrl_0, TRUE, 78, (PduIdType)0, (PduIdType)0},
    {CanIf_CanIf_CanCtrl_0, TRUE, 79, (PduIdType)0, (PduIdType)0},
    {CanIf_CanIf_CanCtrl_0, TRUE, 80, (PduIdType)0, (PduIdType)0},
    {CanIf_CanIf_CanCtrl_0, TRUE, 81, (PduIdType)0, (PduIdType)0},
    {CanIf_CanIf_CanCtrl_0, TRUE, 82, (PduIdType)0, (PduIdType)0},
    {CanIf_CanIf_CanCtrl_1, TRUE, 83, (PduIdType)0, (PduIdType)0},
};
CONST(CanIf_TxPduCfgType, CANIF_CONST) CanIf_TxPduCfg[40] =
{
    /*0 CanConfigSet_Tx_Radar_ADCU_SYNC_FUP*/
    {
        (Can_IdType)0x40000021,/*CanId*/
        STANDARD_FD_CAN,/*CanIdType*/
        (uint8)8,/*dlc*/
        COMSTACK_INVALID_PDUID,/*TxBufferIndex*/
        NULL_PTR,/*TxBufferPtr*/
        (Can_HwHandleType)32,/*TxBufRef*/
        (uint8)0,/*TxConfUL*/
        CanTSyn_CanConfigSet_Tx_Radar_ADCU_SYNC_FUP/*uplayyer handle*/
    },
    /*1 CanConfigSet_Tx_ACAN_ADAS_01*/
    {
        (Can_IdType)0x1d1,/*CanId*/
        STANDARD_NO_FD_CAN,/*CanIdType*/
        (uint8)8,/*dlc*/
        (PduIdType)0,/*TxBufferIndex*/
        CanIf_TxQueueBuf0,/*TxBufferPtr*/
        (Can_HwHandleType)0,/*TxBufRef*/
        (uint8)1,/*TxConfUL*/
        PduR_CanIf_CanConfigSet_Tx_ACAN_ADAS_01/*uplayyer handle*/
    },
    /*2 CanConfigSet_Tx_ACAN_ADAS_02*/
    {
        (Can_IdType)0x1d2,/*CanId*/
        STANDARD_NO_FD_CAN,/*CanIdType*/
        (uint8)8,/*dlc*/
        (PduIdType)2,/*TxBufferIndex*/
        CanIf_TxQueueBuf2,/*TxBufferPtr*/
        (Can_HwHandleType)1,/*TxBufRef*/
        (uint8)1,/*TxConfUL*/
        PduR_CanIf_CanConfigSet_Tx_ACAN_ADAS_02/*uplayyer handle*/
    },
    /*3 CanConfigSet_Tx_ACAN_ADAS_03*/
    {
        (Can_IdType)0x1d3,/*CanId*/
        STANDARD_NO_FD_CAN,/*CanIdType*/
        (uint8)8,/*dlc*/
        (PduIdType)4,/*TxBufferIndex*/
        CanIf_TxQueueBuf4,/*TxBufferPtr*/
        (Can_HwHandleType)2,/*TxBufRef*/
        (uint8)1,/*TxConfUL*/
        PduR_CanIf_CanConfigSet_Tx_ACAN_ADAS_03/*uplayyer handle*/
    },
    /*4 CanConfigSet_Tx_ACAN_ADAS_04*/
    {
        (Can_IdType)0x1d4,/*CanId*/
        STANDARD_NO_FD_CAN,/*CanIdType*/
        (uint8)8,/*dlc*/
        (PduIdType)6,/*TxBufferIndex*/
        CanIf_TxQueueBuf6,/*TxBufferPtr*/
        (Can_HwHandleType)3,/*TxBufRef*/
        (uint8)1,/*TxConfUL*/
        PduR_CanIf_CanConfigSet_Tx_ACAN_ADAS_04/*uplayyer handle*/
    },
    /*5 CanConfigSet_Tx_ACAN_ADAS_06*/
    {
        (Can_IdType)0x1d6,/*CanId*/
        STANDARD_NO_FD_CAN,/*CanIdType*/
        (uint8)8,/*dlc*/
        (PduIdType)8,/*TxBufferIndex*/
        CanIf_TxQueueBuf8,/*TxBufferPtr*/
        (Can_HwHandleType)4,/*TxBufRef*/
        (uint8)1,/*TxConfUL*/
        PduR_CanIf_CanConfigSet_Tx_ACAN_ADAS_06/*uplayyer handle*/
    },
    /*6 CanConfigSet_Tx_ACAN_ADAS_07*/
    {
        (Can_IdType)0x1d7,/*CanId*/
        STANDARD_NO_FD_CAN,/*CanIdType*/
        (uint8)8,/*dlc*/
        (PduIdType)10,/*TxBufferIndex*/
        CanIf_TxQueueBuf10,/*TxBufferPtr*/
        (Can_HwHandleType)5,/*TxBufRef*/
        (uint8)1,/*TxConfUL*/
        PduR_CanIf_CanConfigSet_Tx_ACAN_ADAS_07/*uplayyer handle*/
    },
    /*7 CanConfigSet_Tx_ACAN_ADAS_08*/
    {
        (Can_IdType)0x1d8,/*CanId*/
        STANDARD_NO_FD_CAN,/*CanIdType*/
        (uint8)8,/*dlc*/
        (PduIdType)12,/*TxBufferIndex*/
        CanIf_TxQueueBuf12,/*TxBufferPtr*/
        (Can_HwHandleType)6,/*TxBufRef*/
        (uint8)1,/*TxConfUL*/
        PduR_CanIf_CanConfigSet_Tx_ACAN_ADAS_08/*uplayyer handle*/
    },
    /*8 CanConfigSet_Tx_ACAN_ADAS_Info15*/
    {
        (Can_IdType)0x1db,/*CanId*/
        STANDARD_NO_FD_CAN,/*CanIdType*/
        (uint8)8,/*dlc*/
        COMSTACK_INVALID_PDUID,/*TxBufferIndex*/
        NULL_PTR,/*TxBufferPtr*/
        (Can_HwHandleType)7,/*TxBufRef*/
        (uint8)1,/*TxConfUL*/
        PduR_CanIf_CanConfigSet_Tx_ACAN_ADAS_Info15/*uplayyer handle*/
    },
    /*9 CanConfigSet_Tx_ACAN_ADAS_Info17*/
    {
        (Can_IdType)0x1dd,/*CanId*/
        STANDARD_NO_FD_CAN,/*CanIdType*/
        (uint8)8,/*dlc*/
        COMSTACK_INVALID_PDUID,/*TxBufferIndex*/
        NULL_PTR,/*TxBufferPtr*/
        (Can_HwHandleType)8,/*TxBufRef*/
        (uint8)1,/*TxConfUL*/
        PduR_CanIf_CanConfigSet_Tx_ACAN_ADAS_Info17/*uplayyer handle*/
    },
    /*10 CanConfigSet_Tx_ACAN_ADAS_Info23*/
    {
        (Can_IdType)0x1f8,/*CanId*/
        STANDARD_NO_FD_CAN,/*CanIdType*/
        (uint8)8,/*dlc*/
        COMSTACK_INVALID_PDUID,/*TxBufferIndex*/
        NULL_PTR,/*TxBufferPtr*/
        (Can_HwHandleType)9,/*TxBufRef*/
        (uint8)1,/*TxConfUL*/
        PduR_CanIf_CanConfigSet_Tx_ACAN_ADAS_Info23/*uplayyer handle*/
    },
    /*11 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info1*/
    {
        (Can_IdType)0x3a1,/*CanId*/
        STANDARD_NO_FD_CAN,/*CanIdType*/
        (uint8)8,/*dlc*/
        COMSTACK_INVALID_PDUID,/*TxBufferIndex*/
        NULL_PTR,/*TxBufferPtr*/
        (Can_HwHandleType)10,/*TxBufRef*/
        (uint8)1,/*TxConfUL*/
        PduR_CanIf_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info1/*uplayyer handle*/
    },
    /*12 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info3*/
    {
        (Can_IdType)0x3a2,/*CanId*/
        STANDARD_NO_FD_CAN,/*CanIdType*/
        (uint8)8,/*dlc*/
        COMSTACK_INVALID_PDUID,/*TxBufferIndex*/
        NULL_PTR,/*TxBufferPtr*/
        (Can_HwHandleType)11,/*TxBufRef*/
        (uint8)1,/*TxConfUL*/
        PduR_CanIf_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info3/*uplayyer handle*/
    },
    /*13 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info5*/
    {
        (Can_IdType)0x3a3,/*CanId*/
        STANDARD_NO_FD_CAN,/*CanIdType*/
        (uint8)8,/*dlc*/
        COMSTACK_INVALID_PDUID,/*TxBufferIndex*/
        NULL_PTR,/*TxBufferPtr*/
        (Can_HwHandleType)12,/*TxBufRef*/
        (uint8)1,/*TxConfUL*/
        PduR_CanIf_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info5/*uplayyer handle*/
    },
    /*14 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info7*/
    {
        (Can_IdType)0x3a4,/*CanId*/
        STANDARD_NO_FD_CAN,/*CanIdType*/
        (uint8)8,/*dlc*/
        COMSTACK_INVALID_PDUID,/*TxBufferIndex*/
        NULL_PTR,/*TxBufferPtr*/
        (Can_HwHandleType)13,/*TxBufRef*/
        (uint8)1,/*TxConfUL*/
        PduR_CanIf_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info7/*uplayyer handle*/
    },
    /*15 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info9*/
    {
        (Can_IdType)0x3a5,/*CanId*/
        STANDARD_NO_FD_CAN,/*CanIdType*/
        (uint8)8,/*dlc*/
        COMSTACK_INVALID_PDUID,/*TxBufferIndex*/
        NULL_PTR,/*TxBufferPtr*/
        (Can_HwHandleType)14,/*TxBufRef*/
        (uint8)1,/*TxConfUL*/
        PduR_CanIf_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info9/*uplayyer handle*/
    },
    /*16 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info11*/
    {
        (Can_IdType)0x3a6,/*CanId*/
        STANDARD_NO_FD_CAN,/*CanIdType*/
        (uint8)8,/*dlc*/
        COMSTACK_INVALID_PDUID,/*TxBufferIndex*/
        NULL_PTR,/*TxBufferPtr*/
        (Can_HwHandleType)15,/*TxBufRef*/
        (uint8)1,/*TxConfUL*/
        PduR_CanIf_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info11/*uplayyer handle*/
    },
    /*17 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info13*/
    {
        (Can_IdType)0x3a7,/*CanId*/
        STANDARD_NO_FD_CAN,/*CanIdType*/
        (uint8)8,/*dlc*/
        COMSTACK_INVALID_PDUID,/*TxBufferIndex*/
        NULL_PTR,/*TxBufferPtr*/
        (Can_HwHandleType)16,/*TxBufRef*/
        (uint8)1,/*TxConfUL*/
        PduR_CanIf_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info13/*uplayyer handle*/
    },
    /*18 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info15*/
    {
        (Can_IdType)0x3a8,/*CanId*/
        STANDARD_NO_FD_CAN,/*CanIdType*/
        (uint8)8,/*dlc*/
        COMSTACK_INVALID_PDUID,/*TxBufferIndex*/
        NULL_PTR,/*TxBufferPtr*/
        (Can_HwHandleType)17,/*TxBufRef*/
        (uint8)1,/*TxConfUL*/
        PduR_CanIf_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info15/*uplayyer handle*/
    },
    /*19 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info17*/
    {
        (Can_IdType)0x3a9,/*CanId*/
        STANDARD_NO_FD_CAN,/*CanIdType*/
        (uint8)8,/*dlc*/
        COMSTACK_INVALID_PDUID,/*TxBufferIndex*/
        NULL_PTR,/*TxBufferPtr*/
        (Can_HwHandleType)18,/*TxBufRef*/
        (uint8)1,/*TxConfUL*/
        PduR_CanIf_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info17/*uplayyer handle*/
    },
    /*20 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info19*/
    {
        (Can_IdType)0x3aa,/*CanId*/
        STANDARD_NO_FD_CAN,/*CanIdType*/
        (uint8)8,/*dlc*/
        COMSTACK_INVALID_PDUID,/*TxBufferIndex*/
        NULL_PTR,/*TxBufferPtr*/
        (Can_HwHandleType)19,/*TxBufRef*/
        (uint8)1,/*TxConfUL*/
        PduR_CanIf_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info19/*uplayyer handle*/
    },
    /*21 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info21*/
    {
        (Can_IdType)0x3ab,/*CanId*/
        STANDARD_NO_FD_CAN,/*CanIdType*/
        (uint8)8,/*dlc*/
        COMSTACK_INVALID_PDUID,/*TxBufferIndex*/
        NULL_PTR,/*TxBufferPtr*/
        (Can_HwHandleType)20,/*TxBufRef*/
        (uint8)1,/*TxConfUL*/
        PduR_CanIf_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info21/*uplayyer handle*/
    },
    /*22 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info23*/
    {
        (Can_IdType)0x3ac,/*CanId*/
        STANDARD_NO_FD_CAN,/*CanIdType*/
        (uint8)8,/*dlc*/
        COMSTACK_INVALID_PDUID,/*TxBufferIndex*/
        NULL_PTR,/*TxBufferPtr*/
        (Can_HwHandleType)21,/*TxBufRef*/
        (uint8)1,/*TxConfUL*/
        PduR_CanIf_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info23/*uplayyer handle*/
    },
    /*23 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info2*/
    {
        (Can_IdType)0x3b1,/*CanId*/
        STANDARD_NO_FD_CAN,/*CanIdType*/
        (uint8)8,/*dlc*/
        COMSTACK_INVALID_PDUID,/*TxBufferIndex*/
        NULL_PTR,/*TxBufferPtr*/
        (Can_HwHandleType)22,/*TxBufRef*/
        (uint8)1,/*TxConfUL*/
        PduR_CanIf_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info2/*uplayyer handle*/
    },
    /*24 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info4*/
    {
        (Can_IdType)0x3b2,/*CanId*/
        STANDARD_NO_FD_CAN,/*CanIdType*/
        (uint8)8,/*dlc*/
        COMSTACK_INVALID_PDUID,/*TxBufferIndex*/
        NULL_PTR,/*TxBufferPtr*/
        (Can_HwHandleType)23,/*TxBufRef*/
        (uint8)1,/*TxConfUL*/
        PduR_CanIf_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info4/*uplayyer handle*/
    },
    /*25 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info6*/
    {
        (Can_IdType)0x3b3,/*CanId*/
        STANDARD_NO_FD_CAN,/*CanIdType*/
        (uint8)8,/*dlc*/
        COMSTACK_INVALID_PDUID,/*TxBufferIndex*/
        NULL_PTR,/*TxBufferPtr*/
        (Can_HwHandleType)24,/*TxBufRef*/
        (uint8)1,/*TxConfUL*/
        PduR_CanIf_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info6/*uplayyer handle*/
    },
    /*26 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info8*/
    {
        (Can_IdType)0x3b4,/*CanId*/
        STANDARD_NO_FD_CAN,/*CanIdType*/
        (uint8)8,/*dlc*/
        COMSTACK_INVALID_PDUID,/*TxBufferIndex*/
        NULL_PTR,/*TxBufferPtr*/
        (Can_HwHandleType)25,/*TxBufRef*/
        (uint8)1,/*TxConfUL*/
        PduR_CanIf_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info8/*uplayyer handle*/
    },
    /*27 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info10*/
    {
        (Can_IdType)0x3b5,/*CanId*/
        STANDARD_NO_FD_CAN,/*CanIdType*/
        (uint8)8,/*dlc*/
        COMSTACK_INVALID_PDUID,/*TxBufferIndex*/
        NULL_PTR,/*TxBufferPtr*/
        (Can_HwHandleType)26,/*TxBufRef*/
        (uint8)1,/*TxConfUL*/
        PduR_CanIf_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info10/*uplayyer handle*/
    },
    /*28 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info12*/
    {
        (Can_IdType)0x3b6,/*CanId*/
        STANDARD_NO_FD_CAN,/*CanIdType*/
        (uint8)8,/*dlc*/
        COMSTACK_INVALID_PDUID,/*TxBufferIndex*/
        NULL_PTR,/*TxBufferPtr*/
        (Can_HwHandleType)27,/*TxBufRef*/
        (uint8)1,/*TxConfUL*/
        PduR_CanIf_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info12/*uplayyer handle*/
    },
    /*29 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info14*/
    {
        (Can_IdType)0x3b7,/*CanId*/
        STANDARD_NO_FD_CAN,/*CanIdType*/
        (uint8)8,/*dlc*/
        COMSTACK_INVALID_PDUID,/*TxBufferIndex*/
        NULL_PTR,/*TxBufferPtr*/
        (Can_HwHandleType)28,/*TxBufRef*/
        (uint8)1,/*TxConfUL*/
        PduR_CanIf_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info14/*uplayyer handle*/
    },
    /*30 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info16*/
    {
        (Can_IdType)0x3b8,/*CanId*/
        STANDARD_NO_FD_CAN,/*CanIdType*/
        (uint8)8,/*dlc*/
        COMSTACK_INVALID_PDUID,/*TxBufferIndex*/
        NULL_PTR,/*TxBufferPtr*/
        (Can_HwHandleType)29,/*TxBufRef*/
        (uint8)1,/*TxConfUL*/
        PduR_CanIf_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info16/*uplayyer handle*/
    },
    /*31 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info18*/
    {
        (Can_IdType)0x3b9,/*CanId*/
        STANDARD_NO_FD_CAN,/*CanIdType*/
        (uint8)8,/*dlc*/
        COMSTACK_INVALID_PDUID,/*TxBufferIndex*/
        NULL_PTR,/*TxBufferPtr*/
        (Can_HwHandleType)30,/*TxBufRef*/
        (uint8)1,/*TxConfUL*/
        PduR_CanIf_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info18/*uplayyer handle*/
    },
    /*32 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info20*/
    {
        (Can_IdType)0x3ba,/*CanId*/
        STANDARD_NO_FD_CAN,/*CanIdType*/
        (uint8)8,/*dlc*/
        COMSTACK_INVALID_PDUID,/*TxBufferIndex*/
        NULL_PTR,/*TxBufferPtr*/
        (Can_HwHandleType)31,/*TxBufRef*/
        (uint8)1,/*TxConfUL*/
        PduR_CanIf_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info20/*uplayyer handle*/
    },
    /*33 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info22*/
    {
        (Can_IdType)0x3bb,/*CanId*/
        STANDARD_NO_FD_CAN,/*CanIdType*/
        (uint8)8,/*dlc*/
        (PduIdType)1,/*TxBufferIndex*/
        CanIf_TxQueueBuf1,/*TxBufferPtr*/
        (Can_HwHandleType)0,/*TxBufRef*/
        (uint8)1,/*TxConfUL*/
        PduR_CanIf_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info22/*uplayyer handle*/
    },
    /*34 CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info24*/
    {
        (Can_IdType)0x3bc,/*CanId*/
        STANDARD_NO_FD_CAN,/*CanIdType*/
        (uint8)8,/*dlc*/
        (PduIdType)3,/*TxBufferIndex*/
        CanIf_TxQueueBuf3,/*TxBufferPtr*/
        (Can_HwHandleType)1,/*TxBufRef*/
        (uint8)1,/*TxConfUL*/
        PduR_CanIf_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info24/*uplayyer handle*/
    },
    /*35 CanConfigSet_Tx_ACAN_ADAS_Info20*/
    {
        (Can_IdType)0x3d5,/*CanId*/
        STANDARD_NO_FD_CAN,/*CanIdType*/
        (uint8)8,/*dlc*/
        (PduIdType)5,/*TxBufferIndex*/
        CanIf_TxQueueBuf5,/*TxBufferPtr*/
        (Can_HwHandleType)2,/*TxBufRef*/
        (uint8)1,/*TxConfUL*/
        PduR_CanIf_CanConfigSet_Tx_ACAN_ADAS_Info20/*uplayyer handle*/
    },
    /*36 CanConfigSet_Tx_ACAN_ADAS_Info21*/
    {
        (Can_IdType)0x3d6,/*CanId*/
        STANDARD_NO_FD_CAN,/*CanIdType*/
        (uint8)8,/*dlc*/
        (PduIdType)7,/*TxBufferIndex*/
        CanIf_TxQueueBuf7,/*TxBufferPtr*/
        (Can_HwHandleType)3,/*TxBufRef*/
        (uint8)1,/*TxConfUL*/
        PduR_CanIf_CanConfigSet_Tx_ACAN_ADAS_Info21/*uplayyer handle*/
    },
    /*37 CanConfigSet_Tx_ACAN_ADAS_Info22*/
    {
        (Can_IdType)0x3d7,/*CanId*/
        STANDARD_NO_FD_CAN,/*CanIdType*/
        (uint8)8,/*dlc*/
        (PduIdType)9,/*TxBufferIndex*/
        CanIf_TxQueueBuf9,/*TxBufferPtr*/
        (Can_HwHandleType)4,/*TxBufRef*/
        (uint8)1,/*TxConfUL*/
        PduR_CanIf_CanConfigSet_Tx_ACAN_ADAS_Info22/*uplayyer handle*/
    },
    /*38 CanConfigSet_Tx_ACAN_ADAS_NM*/
    {
        (Can_IdType)0x6b1,/*CanId*/
        STANDARD_NO_FD_CAN,/*CanIdType*/
        (uint8)8,/*dlc*/
        (PduIdType)11,/*TxBufferIndex*/
        CanIf_TxQueueBuf11,/*TxBufferPtr*/
        (Can_HwHandleType)5,/*TxBufRef*/
        (uint8)2,/*TxConfUL*/
        CanNm_CanIf_CanConfigSet_Tx_ACAN_ADAS_NM/*uplayyer handle*/
    },
    /*39 CanConfigSet_Tx_ACAN_UDS_DiagResp_ADAS*/
    {
        (Can_IdType)0x7b9,/*CanId*/
        STANDARD_NO_FD_CAN,/*CanIdType*/
        (uint8)8,/*dlc*/
        (PduIdType)13,/*TxBufferIndex*/
        CanIf_TxQueueBuf13,/*TxBufferPtr*/
        (Can_HwHandleType)6,/*TxBufRef*/
        (uint8)3,/*TxConfUL*/
        CanTp_CanIf_CanConfigSet_Tx_ACAN_UDS_DiagResp_ADAS/*uplayyer handle*/
    },
};
CONST(CanIf_HrhCfgType, CANIF_CONST) CanIf_HrhCfg[51] =
{
    {CanIf_CanIf_CanCtrl_0, FALSE, 0, (PduIdType)48},
    {CanIf_CanIf_CanCtrl_0, TRUE, 1, (PduIdType)2},
    {CanIf_CanIf_CanCtrl_0, TRUE, 2, (PduIdType)3},
    {CanIf_CanIf_CanCtrl_0, TRUE, 3, (PduIdType)4},
    {CanIf_CanIf_CanCtrl_0, TRUE, 4, (PduIdType)5},
    {CanIf_CanIf_CanCtrl_0, TRUE, 5, (PduIdType)6},
    {CanIf_CanIf_CanCtrl_0, TRUE, 6, (PduIdType)7},
    {CanIf_CanIf_CanCtrl_0, TRUE, 7, (PduIdType)8},
    {CanIf_CanIf_CanCtrl_0, TRUE, 8, (PduIdType)9},
    {CanIf_CanIf_CanCtrl_0, TRUE, 9, (PduIdType)10},
    {CanIf_CanIf_CanCtrl_0, TRUE, 10, (PduIdType)11},
    {CanIf_CanIf_CanCtrl_0, TRUE, 11, (PduIdType)12},
    {CanIf_CanIf_CanCtrl_0, TRUE, 12, (PduIdType)13},
    {CanIf_CanIf_CanCtrl_0, TRUE, 13, (PduIdType)14},
    {CanIf_CanIf_CanCtrl_0, TRUE, 14, (PduIdType)15},
    {CanIf_CanIf_CanCtrl_0, TRUE, 15, (PduIdType)16},
    {CanIf_CanIf_CanCtrl_0, TRUE, 16, (PduIdType)17},
    {CanIf_CanIf_CanCtrl_0, TRUE, 17, (PduIdType)20},
    {CanIf_CanIf_CanCtrl_0, TRUE, 18, (PduIdType)36},
    {CanIf_CanIf_CanCtrl_0, TRUE, 19, (PduIdType)37},
    {CanIf_CanIf_CanCtrl_0, TRUE, 20, (PduIdType)38},
    {CanIf_CanIf_CanCtrl_0, TRUE, 21, (PduIdType)39},
    {CanIf_CanIf_CanCtrl_0, TRUE, 22, (PduIdType)40},
    {CanIf_CanIf_CanCtrl_0, TRUE, 23, (PduIdType)41},
    {CanIf_CanIf_CanCtrl_0, TRUE, 24, (PduIdType)42},
    {CanIf_CanIf_CanCtrl_0, TRUE, 25, (PduIdType)43},
    {CanIf_CanIf_CanCtrl_0, TRUE, 26, (PduIdType)44},
    {CanIf_CanIf_CanCtrl_0, TRUE, 27, (PduIdType)45},
    {CanIf_CanIf_CanCtrl_0, TRUE, 28, (PduIdType)46},
    {CanIf_CanIf_CanCtrl_0, TRUE, 29, (PduIdType)47},
    {CanIf_CanIf_CanCtrl_0, TRUE, 30, (PduIdType)49},
    {CanIf_CanIf_CanCtrl_0, TRUE, 31, (PduIdType)50},
    {CanIf_CanIf_CanCtrl_1, TRUE, 32, (PduIdType)0},
    {CanIf_CanIf_CanCtrl_1, TRUE, 33, (PduIdType)1},
    {CanIf_CanIf_CanCtrl_1, TRUE, 34, (PduIdType)18},
    {CanIf_CanIf_CanCtrl_1, TRUE, 35, (PduIdType)19},
    {CanIf_CanIf_CanCtrl_1, TRUE, 36, (PduIdType)21},
    {CanIf_CanIf_CanCtrl_1, TRUE, 37, (PduIdType)22},
    {CanIf_CanIf_CanCtrl_1, TRUE, 38, (PduIdType)23},
    {CanIf_CanIf_CanCtrl_1, TRUE, 39, (PduIdType)24},
    {CanIf_CanIf_CanCtrl_1, TRUE, 40, (PduIdType)25},
    {CanIf_CanIf_CanCtrl_1, TRUE, 41, (PduIdType)26},
    {CanIf_CanIf_CanCtrl_1, TRUE, 42, (PduIdType)27},
    {CanIf_CanIf_CanCtrl_1, TRUE, 43, (PduIdType)28},
    {CanIf_CanIf_CanCtrl_1, TRUE, 44, (PduIdType)29},
    {CanIf_CanIf_CanCtrl_1, TRUE, 45, (PduIdType)30},
    {CanIf_CanIf_CanCtrl_1, TRUE, 46, (PduIdType)31},
    {CanIf_CanIf_CanCtrl_1, TRUE, 47, (PduIdType)32},
    {CanIf_CanIf_CanCtrl_1, TRUE, 48, (PduIdType)33},
    {CanIf_CanIf_CanCtrl_1, TRUE, 49, (PduIdType)34},
    {CanIf_CanIf_CanCtrl_1, TRUE, 50, (PduIdType)35},
};
STATIC CONST(CanIf_RxPduCanIdRangeCfgType, CANIF_CONST) CanIfRangePdu_CanConfigSet_Rx_ACAN_VCA_NM =
{(Can_IdType)0x600, (Can_IdType)0x6ff};
CONST(CanIf_RxPduCfgType, CANIF_CONST) CanIf_RxPduCfg[51] =
{
    /*0 CanConfigSet_Rx_Radar_ARS_TIME_SYNC*/
    {
        (Can_IdType)0x40000030,/*CanId*/
        (Can_IdType)0xdfffffff,/*CanIdMask*/
        STANDARD_FD_CAN,/*CanIdType*/
        (uint8)16,/*dlc*/
        COMSTACK_INVALID_PDUID,/*nextPduIndex*/
        NULL_PTR,/*rangePduRef*/
        (uint8)0,/*RxIndUL*/
        PduR_CanIf_CanConfigSet_Rx_Radar_ARS_TIME_SYNC,/*uplayyer handle*/
        (Can_HwHandleType)32/*hrh ref*/
    },
    /*1 CanConfigSet_Rx_Radar_ARS_SYS_PERFORM*/
    {
        (Can_IdType)0x40000052,/*CanId*/
        (Can_IdType)0xdfffffff,/*CanIdMask*/
        STANDARD_FD_CAN,/*CanIdType*/
        (uint8)16,/*dlc*/
        COMSTACK_INVALID_PDUID,/*nextPduIndex*/
        NULL_PTR,/*rangePduRef*/
        (uint8)0,/*RxIndUL*/
        PduR_CanIf_CanConfigSet_Rx_Radar_ARS_SYS_PERFORM,/*uplayyer handle*/
        (Can_HwHandleType)33/*hrh ref*/
    },
    /*2 CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq*/
    {
        (Can_IdType)0x80,/*CanId*/
        (Can_IdType)0xdfffffff,/*CanIdMask*/
        STANDARD_NO_FD_CAN,/*CanIdType*/
        (uint8)8,/*dlc*/
        COMSTACK_INVALID_PDUID,/*nextPduIndex*/
        NULL_PTR,/*rangePduRef*/
        (uint8)0,/*RxIndUL*/
        PduR_CanIf_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq,/*uplayyer handle*/
        (Can_HwHandleType)1/*hrh ref*/
    },
    /*3 CanConfigSet_Rx_ACAN_BCM_LIGHT_0x106*/
    {
        (Can_IdType)0x106,/*CanId*/
        (Can_IdType)0xdfffffff,/*CanIdMask*/
        STANDARD_NO_FD_CAN,/*CanIdType*/
        (uint8)8,/*dlc*/
        COMSTACK_INVALID_PDUID,/*nextPduIndex*/
        NULL_PTR,/*rangePduRef*/
        (uint8)0,/*RxIndUL*/
        PduR_CanIf_CanConfigSet_Rx_ACAN_BCM_LIGHT_0x106,/*uplayyer handle*/
        (Can_HwHandleType)2/*hrh ref*/
    },
    /*4 CanConfigSet_Rx_ACAN_BCM_SwitchSts_0x109*/
    {
        (Can_IdType)0x109,/*CanId*/
        (Can_IdType)0xdfffffff,/*CanIdMask*/
        STANDARD_NO_FD_CAN,/*CanIdType*/
        (uint8)8,/*dlc*/
        COMSTACK_INVALID_PDUID,/*nextPduIndex*/
        NULL_PTR,/*rangePduRef*/
        (uint8)0,/*RxIndUL*/
        PduR_CanIf_CanConfigSet_Rx_ACAN_BCM_SwitchSts_0x109,/*uplayyer handle*/
        (Can_HwHandleType)3/*hrh ref*/
    },
    /*5 CanConfigSet_Rx_ACAN_ABS_FrontWheelSpeMCUKPH*/
    {
        (Can_IdType)0x122,/*CanId*/
        (Can_IdType)0xdfffffff,/*CanIdMask*/
        STANDARD_NO_FD_CAN,/*CanIdType*/
        (uint8)8,/*dlc*/
        COMSTACK_INVALID_PDUID,/*nextPduIndex*/
        NULL_PTR,/*rangePduRef*/
        (uint8)0,/*RxIndUL*/
        PduR_CanIf_CanConfigSet_Rx_ACAN_ABS_FrontWheelSpeMCUKPH,/*uplayyer handle*/
        (Can_HwHandleType)4/*hrh ref*/
    },
    /*6 CanConfigSet_Rx_ACAN_ABS_RearWheelSpeMCUKPH*/
    {
        (Can_IdType)0x123,/*CanId*/
        (Can_IdType)0xdfffffff,/*CanIdMask*/
        STANDARD_NO_FD_CAN,/*CanIdType*/
        (uint8)8,/*dlc*/
        COMSTACK_INVALID_PDUID,/*nextPduIndex*/
        NULL_PTR,/*rangePduRef*/
        (uint8)0,/*RxIndUL*/
        PduR_CanIf_CanConfigSet_Rx_ACAN_ABS_RearWheelSpeMCUKPH,/*uplayyer handle*/
        (Can_HwHandleType)5/*hrh ref*/
    },
    /*7 CanConfigSet_Rx_ACAN_ABS_WheelSpeedRC*/
    {
        (Can_IdType)0x124,/*CanId*/
        (Can_IdType)0xdfffffff,/*CanIdMask*/
        STANDARD_NO_FD_CAN,/*CanIdType*/
        (uint8)8,/*dlc*/
        COMSTACK_INVALID_PDUID,/*nextPduIndex*/
        NULL_PTR,/*rangePduRef*/
        (uint8)0,/*RxIndUL*/
        PduR_CanIf_CanConfigSet_Rx_ACAN_ABS_WheelSpeedRC,/*uplayyer handle*/
        (Can_HwHandleType)6/*hrh ref*/
    },
    /*8 CanConfigSet_Rx_ACAN_ABS_Status*/
    {
        (Can_IdType)0x125,/*CanId*/
        (Can_IdType)0xdfffffff,/*CanIdMask*/
        STANDARD_NO_FD_CAN,/*CanIdType*/
        (uint8)8,/*dlc*/
        COMSTACK_INVALID_PDUID,/*nextPduIndex*/
        NULL_PTR,/*rangePduRef*/
        (uint8)0,/*RxIndUL*/
        PduR_CanIf_CanConfigSet_Rx_ACAN_ABS_Status,/*uplayyer handle*/
        (Can_HwHandleType)7/*hrh ref*/
    },
    /*9 CanConfigSet_Rx_ACAN_ESC_Status_0x132*/
    {
        (Can_IdType)0x132,/*CanId*/
        (Can_IdType)0xdfffffff,/*CanIdMask*/
        STANDARD_NO_FD_CAN,/*CanIdType*/
        (uint8)8,/*dlc*/
        COMSTACK_INVALID_PDUID,/*nextPduIndex*/
        NULL_PTR,/*rangePduRef*/
        (uint8)0,/*RxIndUL*/
        PduR_CanIf_CanConfigSet_Rx_ACAN_ESC_Status_0x132,/*uplayyer handle*/
        (Can_HwHandleType)8/*hrh ref*/
    },
    /*10 CanConfigSet_Rx_ACAN_VCU_Ctrl*/
    {
        (Can_IdType)0x162,/*CanId*/
        (Can_IdType)0xdfffffff,/*CanIdMask*/
        STANDARD_NO_FD_CAN,/*CanIdType*/
        (uint8)8,/*dlc*/
        COMSTACK_INVALID_PDUID,/*nextPduIndex*/
        NULL_PTR,/*rangePduRef*/
        (uint8)0,/*RxIndUL*/
        PduR_CanIf_CanConfigSet_Rx_ACAN_VCU_Ctrl,/*uplayyer handle*/
        (Can_HwHandleType)9/*hrh ref*/
    },
    /*11 CanConfigSet_Rx_ACAN_VCU_StsEpt*/
    {
        (Can_IdType)0x167,/*CanId*/
        (Can_IdType)0xdfffffff,/*CanIdMask*/
        STANDARD_NO_FD_CAN,/*CanIdType*/
        (uint8)8,/*dlc*/
        COMSTACK_INVALID_PDUID,/*nextPduIndex*/
        NULL_PTR,/*rangePduRef*/
        (uint8)0,/*RxIndUL*/
        PduR_CanIf_CanConfigSet_Rx_ACAN_VCU_StsEpt,/*uplayyer handle*/
        (Can_HwHandleType)10/*hrh ref*/
    },
    /*12 CanConfigSet_Rx_ACAN_SAS_Sensor_0x17E*/
    {
        (Can_IdType)0x17e,/*CanId*/
        (Can_IdType)0xdfffffff,/*CanIdMask*/
        STANDARD_NO_FD_CAN,/*CanIdType*/
        (uint8)8,/*dlc*/
        COMSTACK_INVALID_PDUID,/*nextPduIndex*/
        NULL_PTR,/*rangePduRef*/
        (uint8)0,/*RxIndUL*/
        PduR_CanIf_CanConfigSet_Rx_ACAN_SAS_Sensor_0x17E,/*uplayyer handle*/
        (Can_HwHandleType)11/*hrh ref*/
    },
    /*13 CanConfigSet_Rx_ACAN_EPS_LKA_Sts*/
    {
        (Can_IdType)0x17f,/*CanId*/
        (Can_IdType)0xdfffffff,/*CanIdMask*/
        STANDARD_NO_FD_CAN,/*CanIdType*/
        (uint8)8,/*dlc*/
        COMSTACK_INVALID_PDUID,/*nextPduIndex*/
        NULL_PTR,/*rangePduRef*/
        (uint8)0,/*RxIndUL*/
        PduR_CanIf_CanConfigSet_Rx_ACAN_EPS_LKA_Sts,/*uplayyer handle*/
        (Can_HwHandleType)12/*hrh ref*/
    },
    /*14 CanConfigSet_Rx_ACAN_BCM_PEPS_Sts*/
    {
        (Can_IdType)0x1e2,/*CanId*/
        (Can_IdType)0xdfffffff,/*CanIdMask*/
        STANDARD_NO_FD_CAN,/*CanIdType*/
        (uint8)8,/*dlc*/
        COMSTACK_INVALID_PDUID,/*nextPduIndex*/
        NULL_PTR,/*rangePduRef*/
        (uint8)0,/*RxIndUL*/
        PduR_CanIf_CanConfigSet_Rx_ACAN_BCM_PEPS_Sts,/*uplayyer handle*/
        (Can_HwHandleType)13/*hrh ref*/
    },
    /*15 CanConfigSet_Rx_ACAN_MHU_ADSA01*/
    {
        (Can_IdType)0x1f0,/*CanId*/
        (Can_IdType)0xdfffffff,/*CanIdMask*/
        STANDARD_NO_FD_CAN,/*CanIdType*/
        (uint8)8,/*dlc*/
        COMSTACK_INVALID_PDUID,/*nextPduIndex*/
        NULL_PTR,/*rangePduRef*/
        (uint8)0,/*RxIndUL*/
        PduR_CanIf_CanConfigSet_Rx_ACAN_MHU_ADSA01,/*uplayyer handle*/
        (Can_HwHandleType)14/*hrh ref*/
    },
    /*16 CanConfigSet_Rx_ACAN_MHU_ADAS02*/
    {
        (Can_IdType)0x1f1,/*CanId*/
        (Can_IdType)0xdfffffff,/*CanIdMask*/
        STANDARD_NO_FD_CAN,/*CanIdType*/
        (uint8)8,/*dlc*/
        COMSTACK_INVALID_PDUID,/*nextPduIndex*/
        NULL_PTR,/*rangePduRef*/
        (uint8)0,/*RxIndUL*/
        PduR_CanIf_CanConfigSet_Rx_ACAN_MHU_ADAS02,/*uplayyer handle*/
        (Can_HwHandleType)15/*hrh ref*/
    },
    /*17 CanConfigSet_Rx_ACAN_MHU_ADAS03*/
    {
        (Can_IdType)0x1f2,/*CanId*/
        (Can_IdType)0xdfffffff,/*CanIdMask*/
        STANDARD_NO_FD_CAN,/*CanIdType*/
        (uint8)8,/*dlc*/
        COMSTACK_INVALID_PDUID,/*nextPduIndex*/
        NULL_PTR,/*rangePduRef*/
        (uint8)0,/*RxIndUL*/
        PduR_CanIf_CanConfigSet_Rx_ACAN_MHU_ADAS03,/*uplayyer handle*/
        (Can_HwHandleType)16/*hrh ref*/
    },
    /*18 CanConfigSet_Rx_Radar_ARS_OD_Header*/
    {
        (Can_IdType)0x40000200,/*CanId*/
        (Can_IdType)0xdfffffff,/*CanIdMask*/
        STANDARD_FD_CAN,/*CanIdType*/
        (uint8)32,/*dlc*/
        COMSTACK_INVALID_PDUID,/*nextPduIndex*/
        NULL_PTR,/*rangePduRef*/
        (uint8)0,/*RxIndUL*/
        PduR_CanIf_CanConfigSet_Rx_Radar_ARS_OD_Header,/*uplayyer handle*/
        (Can_HwHandleType)34/*hrh ref*/
    },
    /*19 CanConfigSet_Rx_Radar_ARS_OD_00_01*/
    {
        (Can_IdType)0x40000201,/*CanId*/
        (Can_IdType)0xdfffffff,/*CanIdMask*/
        STANDARD_FD_CAN,/*CanIdType*/
        (uint8)64,/*dlc*/
        COMSTACK_INVALID_PDUID,/*nextPduIndex*/
        NULL_PTR,/*rangePduRef*/
        (uint8)0,/*RxIndUL*/
        PduR_CanIf_CanConfigSet_Rx_Radar_ARS_OD_00_01,/*uplayyer handle*/
        (Can_HwHandleType)35/*hrh ref*/
    },
    /*20 CanConfigSet_Rx_ACAN_BCM_WindowSts*/
    {
        (Can_IdType)0x202,/*CanId*/
        (Can_IdType)0xdfffffff,/*CanIdMask*/
        STANDARD_NO_FD_CAN,/*CanIdType*/
        (uint8)8,/*dlc*/
        COMSTACK_INVALID_PDUID,/*nextPduIndex*/
        NULL_PTR,/*rangePduRef*/
        (uint8)0,/*RxIndUL*/
        PduR_CanIf_CanConfigSet_Rx_ACAN_BCM_WindowSts,/*uplayyer handle*/
        (Can_HwHandleType)17/*hrh ref*/
    },
    /*21 CanConfigSet_Rx_Radar_ARS_OD_02_03*/
    {
        (Can_IdType)0x40000202,/*CanId*/
        (Can_IdType)0xdfffffff,/*CanIdMask*/
        STANDARD_FD_CAN,/*CanIdType*/
        (uint8)64,/*dlc*/
        COMSTACK_INVALID_PDUID,/*nextPduIndex*/
        NULL_PTR,/*rangePduRef*/
        (uint8)0,/*RxIndUL*/
        PduR_CanIf_CanConfigSet_Rx_Radar_ARS_OD_02_03,/*uplayyer handle*/
        (Can_HwHandleType)36/*hrh ref*/
    },
    /*22 CanConfigSet_Rx_Radar_ARS_OD_04_05*/
    {
        (Can_IdType)0x40000203,/*CanId*/
        (Can_IdType)0xdfffffff,/*CanIdMask*/
        STANDARD_FD_CAN,/*CanIdType*/
        (uint8)64,/*dlc*/
        COMSTACK_INVALID_PDUID,/*nextPduIndex*/
        NULL_PTR,/*rangePduRef*/
        (uint8)0,/*RxIndUL*/
        PduR_CanIf_CanConfigSet_Rx_Radar_ARS_OD_04_05,/*uplayyer handle*/
        (Can_HwHandleType)37/*hrh ref*/
    },
    /*23 CanConfigSet_Rx_Radar_ARS_OD_06_07*/
    {
        (Can_IdType)0x40000204,/*CanId*/
        (Can_IdType)0xdfffffff,/*CanIdMask*/
        STANDARD_FD_CAN,/*CanIdType*/
        (uint8)64,/*dlc*/
        COMSTACK_INVALID_PDUID,/*nextPduIndex*/
        NULL_PTR,/*rangePduRef*/
        (uint8)0,/*RxIndUL*/
        PduR_CanIf_CanConfigSet_Rx_Radar_ARS_OD_06_07,/*uplayyer handle*/
        (Can_HwHandleType)38/*hrh ref*/
    },
    /*24 CanConfigSet_Rx_Radar_ARS_OD_08_09*/
    {
        (Can_IdType)0x40000205,/*CanId*/
        (Can_IdType)0xdfffffff,/*CanIdMask*/
        STANDARD_FD_CAN,/*CanIdType*/
        (uint8)64,/*dlc*/
        COMSTACK_INVALID_PDUID,/*nextPduIndex*/
        NULL_PTR,/*rangePduRef*/
        (uint8)0,/*RxIndUL*/
        PduR_CanIf_CanConfigSet_Rx_Radar_ARS_OD_08_09,/*uplayyer handle*/
        (Can_HwHandleType)39/*hrh ref*/
    },
    /*25 CanConfigSet_Rx_Radar_ARS_OD_10_11*/
    {
        (Can_IdType)0x40000206,/*CanId*/
        (Can_IdType)0xdfffffff,/*CanIdMask*/
        STANDARD_FD_CAN,/*CanIdType*/
        (uint8)64,/*dlc*/
        COMSTACK_INVALID_PDUID,/*nextPduIndex*/
        NULL_PTR,/*rangePduRef*/
        (uint8)0,/*RxIndUL*/
        PduR_CanIf_CanConfigSet_Rx_Radar_ARS_OD_10_11,/*uplayyer handle*/
        (Can_HwHandleType)40/*hrh ref*/
    },
    /*26 CanConfigSet_Rx_Radar_ARS_OD_12_13*/
    {
        (Can_IdType)0x40000207,/*CanId*/
        (Can_IdType)0xdfffffff,/*CanIdMask*/
        STANDARD_FD_CAN,/*CanIdType*/
        (uint8)64,/*dlc*/
        COMSTACK_INVALID_PDUID,/*nextPduIndex*/
        NULL_PTR,/*rangePduRef*/
        (uint8)0,/*RxIndUL*/
        PduR_CanIf_CanConfigSet_Rx_Radar_ARS_OD_12_13,/*uplayyer handle*/
        (Can_HwHandleType)41/*hrh ref*/
    },
    /*27 CanConfigSet_Rx_Radar_ARS_OD_14_15*/
    {
        (Can_IdType)0x40000208,/*CanId*/
        (Can_IdType)0xdfffffff,/*CanIdMask*/
        STANDARD_FD_CAN,/*CanIdType*/
        (uint8)64,/*dlc*/
        COMSTACK_INVALID_PDUID,/*nextPduIndex*/
        NULL_PTR,/*rangePduRef*/
        (uint8)0,/*RxIndUL*/
        PduR_CanIf_CanConfigSet_Rx_Radar_ARS_OD_14_15,/*uplayyer handle*/
        (Can_HwHandleType)42/*hrh ref*/
    },
    /*28 CanConfigSet_Rx_Radar_ARS_OD_16_17*/
    {
        (Can_IdType)0x40000209,/*CanId*/
        (Can_IdType)0xdfffffff,/*CanIdMask*/
        STANDARD_FD_CAN,/*CanIdType*/
        (uint8)64,/*dlc*/
        COMSTACK_INVALID_PDUID,/*nextPduIndex*/
        NULL_PTR,/*rangePduRef*/
        (uint8)0,/*RxIndUL*/
        PduR_CanIf_CanConfigSet_Rx_Radar_ARS_OD_16_17,/*uplayyer handle*/
        (Can_HwHandleType)43/*hrh ref*/
    },
    /*29 CanConfigSet_Rx_Radar_ARS_OD_18_19*/
    {
        (Can_IdType)0x4000020a,/*CanId*/
        (Can_IdType)0xdfffffff,/*CanIdMask*/
        STANDARD_FD_CAN,/*CanIdType*/
        (uint8)64,/*dlc*/
        COMSTACK_INVALID_PDUID,/*nextPduIndex*/
        NULL_PTR,/*rangePduRef*/
        (uint8)0,/*RxIndUL*/
        PduR_CanIf_CanConfigSet_Rx_Radar_ARS_OD_18_19,/*uplayyer handle*/
        (Can_HwHandleType)44/*hrh ref*/
    },
    /*30 CanConfigSet_Rx_Radar_ARS_OD_20_21*/
    {
        (Can_IdType)0x4000020b,/*CanId*/
        (Can_IdType)0xdfffffff,/*CanIdMask*/
        STANDARD_FD_CAN,/*CanIdType*/
        (uint8)64,/*dlc*/
        COMSTACK_INVALID_PDUID,/*nextPduIndex*/
        NULL_PTR,/*rangePduRef*/
        (uint8)0,/*RxIndUL*/
        PduR_CanIf_CanConfigSet_Rx_Radar_ARS_OD_20_21,/*uplayyer handle*/
        (Can_HwHandleType)45/*hrh ref*/
    },
    /*31 CanConfigSet_Rx_Radar_ARS_OD_22_23*/
    {
        (Can_IdType)0x4000020c,/*CanId*/
        (Can_IdType)0xdfffffff,/*CanIdMask*/
        STANDARD_FD_CAN,/*CanIdType*/
        (uint8)64,/*dlc*/
        COMSTACK_INVALID_PDUID,/*nextPduIndex*/
        NULL_PTR,/*rangePduRef*/
        (uint8)0,/*RxIndUL*/
        PduR_CanIf_CanConfigSet_Rx_Radar_ARS_OD_22_23,/*uplayyer handle*/
        (Can_HwHandleType)46/*hrh ref*/
    },
    /*32 CanConfigSet_Rx_Radar_ARS_OD_24_25*/
    {
        (Can_IdType)0x4000020d,/*CanId*/
        (Can_IdType)0xdfffffff,/*CanIdMask*/
        STANDARD_FD_CAN,/*CanIdType*/
        (uint8)64,/*dlc*/
        COMSTACK_INVALID_PDUID,/*nextPduIndex*/
        NULL_PTR,/*rangePduRef*/
        (uint8)0,/*RxIndUL*/
        PduR_CanIf_CanConfigSet_Rx_Radar_ARS_OD_24_25,/*uplayyer handle*/
        (Can_HwHandleType)47/*hrh ref*/
    },
    /*33 CanConfigSet_Rx_Radar_ARS_OD_26_27*/
    {
        (Can_IdType)0x4000020e,/*CanId*/
        (Can_IdType)0xdfffffff,/*CanIdMask*/
        STANDARD_FD_CAN,/*CanIdType*/
        (uint8)64,/*dlc*/
        COMSTACK_INVALID_PDUID,/*nextPduIndex*/
        NULL_PTR,/*rangePduRef*/
        (uint8)0,/*RxIndUL*/
        PduR_CanIf_CanConfigSet_Rx_Radar_ARS_OD_26_27,/*uplayyer handle*/
        (Can_HwHandleType)48/*hrh ref*/
    },
    /*34 CanConfigSet_Rx_Radar_ARS_OD_28_29*/
    {
        (Can_IdType)0x4000020f,/*CanId*/
        (Can_IdType)0xdfffffff,/*CanIdMask*/
        STANDARD_FD_CAN,/*CanIdType*/
        (uint8)64,/*dlc*/
        COMSTACK_INVALID_PDUID,/*nextPduIndex*/
        NULL_PTR,/*rangePduRef*/
        (uint8)0,/*RxIndUL*/
        PduR_CanIf_CanConfigSet_Rx_Radar_ARS_OD_28_29,/*uplayyer handle*/
        (Can_HwHandleType)49/*hrh ref*/
    },
    /*35 CanConfigSet_Rx_Radar_ARS_OD_30_31*/
    {
        (Can_IdType)0x40000210,/*CanId*/
        (Can_IdType)0xdfffffff,/*CanIdMask*/
        STANDARD_FD_CAN,/*CanIdType*/
        (uint8)64,/*dlc*/
        COMSTACK_INVALID_PDUID,/*nextPduIndex*/
        NULL_PTR,/*rangePduRef*/
        (uint8)0,/*RxIndUL*/
        PduR_CanIf_CanConfigSet_Rx_Radar_ARS_OD_30_31,/*uplayyer handle*/
        (Can_HwHandleType)50/*hrh ref*/
    },
    /*36 CanConfigSet_Rx_ACAN_ESC_EPB_0x230*/
    {
        (Can_IdType)0x230,/*CanId*/
        (Can_IdType)0xdfffffff,/*CanIdMask*/
        STANDARD_NO_FD_CAN,/*CanIdType*/
        (uint8)8,/*dlc*/
        COMSTACK_INVALID_PDUID,/*nextPduIndex*/
        NULL_PTR,/*rangePduRef*/
        (uint8)0,/*RxIndUL*/
        PduR_CanIf_CanConfigSet_Rx_ACAN_ESC_EPB_0x230,/*uplayyer handle*/
        (Can_HwHandleType)18/*hrh ref*/
    },
    /*37 CanConfigSet_Rx_ACAN_IBS_ADAS_Info*/
    {
        (Can_IdType)0x269,/*CanId*/
        (Can_IdType)0xdfffffff,/*CanIdMask*/
        STANDARD_NO_FD_CAN,/*CanIdType*/
        (uint8)8,/*dlc*/
        COMSTACK_INVALID_PDUID,/*nextPduIndex*/
        NULL_PTR,/*rangePduRef*/
        (uint8)0,/*RxIndUL*/
        PduR_CanIf_CanConfigSet_Rx_ACAN_IBS_ADAS_Info,/*uplayyer handle*/
        (Can_HwHandleType)19/*hrh ref*/
    },
    /*38 CanConfigSet_Rx_ACAN_IBS_Info*/
    {
        (Can_IdType)0x270,/*CanId*/
        (Can_IdType)0xdfffffff,/*CanIdMask*/
        STANDARD_NO_FD_CAN,/*CanIdType*/
        (uint8)8,/*dlc*/
        COMSTACK_INVALID_PDUID,/*nextPduIndex*/
        NULL_PTR,/*rangePduRef*/
        (uint8)0,/*RxIndUL*/
        PduR_CanIf_CanConfigSet_Rx_ACAN_IBS_Info,/*uplayyer handle*/
        (Can_HwHandleType)20/*hrh ref*/
    },
    /*39 CanConfigSet_Rx_ACAN_TBOX_DateTime1*/
    {
        (Can_IdType)0x29e,/*CanId*/
        (Can_IdType)0xdfffffff,/*CanIdMask*/
        STANDARD_NO_FD_CAN,/*CanIdType*/
        (uint8)8,/*dlc*/
        COMSTACK_INVALID_PDUID,/*nextPduIndex*/
        NULL_PTR,/*rangePduRef*/
        (uint8)0,/*RxIndUL*/
        PduR_CanIf_CanConfigSet_Rx_ACAN_TBOX_DateTime1,/*uplayyer handle*/
        (Can_HwHandleType)21/*hrh ref*/
    },
    /*40 CanConfigSet_Rx_ACAN_MHU_Status_Info*/
    {
        (Can_IdType)0x2a4,/*CanId*/
        (Can_IdType)0xdfffffff,/*CanIdMask*/
        STANDARD_NO_FD_CAN,/*CanIdType*/
        (uint8)8,/*dlc*/
        COMSTACK_INVALID_PDUID,/*nextPduIndex*/
        NULL_PTR,/*rangePduRef*/
        (uint8)0,/*RxIndUL*/
        PduR_CanIf_CanConfigSet_Rx_ACAN_MHU_Status_Info,/*uplayyer handle*/
        (Can_HwHandleType)22/*hrh ref*/
    },
    /*41 CanConfigSet_Rx_ACAN_CCU_StsInfo1*/
    {
        (Can_IdType)0x32b,/*CanId*/
        (Can_IdType)0xdfffffff,/*CanIdMask*/
        STANDARD_NO_FD_CAN,/*CanIdType*/
        (uint8)8,/*dlc*/
        COMSTACK_INVALID_PDUID,/*nextPduIndex*/
        NULL_PTR,/*rangePduRef*/
        (uint8)0,/*RxIndUL*/
        PduR_CanIf_CanConfigSet_Rx_ACAN_CCU_StsInfo1,/*uplayyer handle*/
        (Can_HwHandleType)23/*hrh ref*/
    },
    /*42 CanConfigSet_Rx_ACAN_ESC_YawAngle_0x3E2*/
    {
        (Can_IdType)0x3e2,/*CanId*/
        (Can_IdType)0xdfffffff,/*CanIdMask*/
        STANDARD_NO_FD_CAN,/*CanIdType*/
        (uint8)8,/*dlc*/
        COMSTACK_INVALID_PDUID,/*nextPduIndex*/
        NULL_PTR,/*rangePduRef*/
        (uint8)0,/*RxIndUL*/
        PduR_CanIf_CanConfigSet_Rx_ACAN_ESC_YawAngle_0x3E2,/*uplayyer handle*/
        (Can_HwHandleType)24/*hrh ref*/
    },
    /*43 CanConfigSet_Rx_ACAN_IPC_TotalOdometer*/
    {
        (Can_IdType)0x3f1,/*CanId*/
        (Can_IdType)0xdfffffff,/*CanIdMask*/
        STANDARD_NO_FD_CAN,/*CanIdType*/
        (uint8)8,/*dlc*/
        COMSTACK_INVALID_PDUID,/*nextPduIndex*/
        NULL_PTR,/*rangePduRef*/
        (uint8)0,/*RxIndUL*/
        PduR_CanIf_CanConfigSet_Rx_ACAN_IPC_TotalOdometer,/*uplayyer handle*/
        (Can_HwHandleType)25/*hrh ref*/
    },
    /*44 CanConfigSet_Rx_ACAN_MFS_L_Control_Button2_0x3F7*/
    {
        (Can_IdType)0x3f7,/*CanId*/
        (Can_IdType)0xdfffffff,/*CanIdMask*/
        STANDARD_NO_FD_CAN,/*CanIdType*/
        (uint8)8,/*dlc*/
        COMSTACK_INVALID_PDUID,/*nextPduIndex*/
        NULL_PTR,/*rangePduRef*/
        (uint8)0,/*RxIndUL*/
        PduR_CanIf_CanConfigSet_Rx_ACAN_MFS_L_Control_Button2_0x3F7,/*uplayyer handle*/
        (Can_HwHandleType)26/*hrh ref*/
    },
    /*45 CanConfigSet_Rx_ACAN_BCM_RLS*/
    {
        (Can_IdType)0x420,/*CanId*/
        (Can_IdType)0xdfffffff,/*CanIdMask*/
        STANDARD_NO_FD_CAN,/*CanIdType*/
        (uint8)8,/*dlc*/
        COMSTACK_INVALID_PDUID,/*nextPduIndex*/
        NULL_PTR,/*rangePduRef*/
        (uint8)0,/*RxIndUL*/
        PduR_CanIf_CanConfigSet_Rx_ACAN_BCM_RLS,/*uplayyer handle*/
        (Can_HwHandleType)27/*hrh ref*/
    },
    /*46 CanConfigSet_Rx_ACAN_BCM_TPMS_Info2*/
    {
        (Can_IdType)0x42b,/*CanId*/
        (Can_IdType)0xdfffffff,/*CanIdMask*/
        STANDARD_NO_FD_CAN,/*CanIdType*/
        (uint8)8,/*dlc*/
        COMSTACK_INVALID_PDUID,/*nextPduIndex*/
        NULL_PTR,/*rangePduRef*/
        (uint8)0,/*RxIndUL*/
        PduR_CanIf_CanConfigSet_Rx_ACAN_BCM_TPMS_Info2,/*uplayyer handle*/
        (Can_HwHandleType)28/*hrh ref*/
    },
    /*47 CanConfigSet_Rx_ACAN_BCM_DoorState_0x4D4*/
    {
        (Can_IdType)0x4d4,/*CanId*/
        (Can_IdType)0xdfffffff,/*CanIdMask*/
        STANDARD_NO_FD_CAN,/*CanIdType*/
        (uint8)8,/*dlc*/
        COMSTACK_INVALID_PDUID,/*nextPduIndex*/
        NULL_PTR,/*rangePduRef*/
        (uint8)0,/*RxIndUL*/
        PduR_CanIf_CanConfigSet_Rx_ACAN_BCM_DoorState_0x4D4,/*uplayyer handle*/
        (Can_HwHandleType)29/*hrh ref*/
    },
    /*48 CanConfigSet_Rx_ACAN_VCA_NM*/
    {
        (Can_IdType)0x6e0,/*CanId*/
        (Can_IdType)0xdfffffff,/*CanIdMask*/
        STANDARD_NO_FD_CAN,/*CanIdType*/
        (uint8)8,/*dlc*/
        COMSTACK_INVALID_PDUID,/*nextPduIndex*/
        &CanIfRangePdu_CanConfigSet_Rx_ACAN_VCA_NM,/*rangePduRef*/
        (uint8)1,/*RxIndUL*/
        CanNm_CanConfigSet_Rx_ACAN_VCA_NM,/*uplayyer handle*/
        (Can_HwHandleType)0/*hrh ref*/
    },
    /*49 CanConfigSet_Rx_ACAN_UDS_PhyDiagReq_ADAS*/
    {
        (Can_IdType)0x7b1,/*CanId*/
        (Can_IdType)0xdfffffff,/*CanIdMask*/
        STANDARD_NO_FD_CAN,/*CanIdType*/
        (uint8)8,/*dlc*/
        COMSTACK_INVALID_PDUID,/*nextPduIndex*/
        NULL_PTR,/*rangePduRef*/
        (uint8)2,/*RxIndUL*/
        CanTp_CanConfigSet_Rx_ACAN_UDS_PhyDiagReq_ADAS,/*uplayyer handle*/
        (Can_HwHandleType)30/*hrh ref*/
    },
    /*50 CanConfigSet_Rx_ACAN_UDS_FuncDiagReq*/
    {
        (Can_IdType)0x7df,/*CanId*/
        (Can_IdType)0xdfffffff,/*CanIdMask*/
        STANDARD_NO_FD_CAN,/*CanIdType*/
        (uint8)8,/*dlc*/
        COMSTACK_INVALID_PDUID,/*nextPduIndex*/
        NULL_PTR,/*rangePduRef*/
        (uint8)2,/*RxIndUL*/
        CanTp_CanConfigSet_Rx_ACAN_UDS_FuncDiagReq,/*uplayyer handle*/
        (Can_HwHandleType)31/*hrh ref*/
    },
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"
