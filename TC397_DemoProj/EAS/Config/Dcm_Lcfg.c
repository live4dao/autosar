/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : Dcm_Lcfg.c
********************************************************************************
*   Project/Product : AUTOSAR BSW PROJECT
*   Title           : Dcm module configuration File
*   Author          : Hirain
********************************************************************************
*   Description     : Dcm module configuration File
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
* Include files
*******************************************************************************/
#include "Rte_Dcm.h"
#include "SchM_Dcm.h"
#include "Dcm_Lcfg.h"
#include "PduR_Dcm.h"
#include "ComM_Dcm.h"
#include "NvM_Types.h"


/*******************************************************************************
* Configuration
*******************************************************************************/


#define DCM_START_SEC_CONFIG_DATA_8
#include "MemMap.h"

STATIC VAR(Dcm_MsgItemType, DCM_VAR) Buffer_0[512];
CONST(uint8, DCM_CONST) Dcm_RxPduToProtocolMap[4] =
{
    0,
    0,
    0,
    0
};

#define DCM_STOP_SEC_CONFIG_DATA_8
#include "MemMap.h"


#define DCM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"


STATIC CONST(Dcm_DsdSubServiceType, DCM_CONST) Dcm_DsdSubService_10_0[3] =
{
    {
        0x01,
        TRUE,
        DCM_REQ_PHY_MASK | DCM_REQ_FUN_MASK,
        DCM_LOCKED_MASK | DCM_L2_MASK | DCM_L9_MASK,
        DCM_DEFAULT_MASK | DCM_PROGRAMMING_MASK | DCM_EXTENDED_MASK,
        NULL_PTR
    },
    {
        0x02,
        TRUE,
        DCM_REQ_PHY_MASK | DCM_REQ_FUN_MASK,
        DCM_LOCKED_MASK | DCM_L2_MASK | DCM_L9_MASK,
        DCM_PROGRAMMING_MASK | DCM_EXTENDED_MASK,
        NULL_PTR
    },
    {
        0x03,
        TRUE,
        DCM_REQ_PHY_MASK | DCM_REQ_FUN_MASK,
        DCM_LOCKED_MASK | DCM_L2_MASK | DCM_L9_MASK,
        DCM_DEFAULT_MASK | DCM_EXTENDED_MASK,
        NULL_PTR
    }
};
STATIC CONST(Dcm_DsdSubServiceType, DCM_CONST) Dcm_DsdSubService_11_0[2] =
{
    {
        0x01,
        TRUE,
        DCM_REQ_PHY_MASK | DCM_REQ_FUN_MASK,
        DCM_LOCKED_MASK | DCM_L2_MASK | DCM_L9_MASK,
        DCM_PROGRAMMING_MASK | DCM_EXTENDED_MASK,
        NULL_PTR
    },
    {
        0x03,
        TRUE,
        DCM_REQ_PHY_MASK | DCM_REQ_FUN_MASK,
        DCM_LOCKED_MASK | DCM_L2_MASK | DCM_L9_MASK,
        DCM_PROGRAMMING_MASK | DCM_EXTENDED_MASK,
        NULL_PTR
    }
};
STATIC CONST(Dcm_DsdSubServiceType, DCM_CONST) Dcm_DsdSubService_19_0[5] =
{
    {
        0x01,
        TRUE,
        DCM_REQ_PHY_MASK | DCM_REQ_FUN_MASK,
        DCM_LOCKED_MASK | DCM_L2_MASK | DCM_L9_MASK,
        DCM_DEFAULT_MASK | DCM_EXTENDED_MASK,
        NULL_PTR
    },
    {
        0x02,
        TRUE,
        DCM_REQ_PHY_MASK | DCM_REQ_FUN_MASK,
        DCM_LOCKED_MASK | DCM_L2_MASK | DCM_L9_MASK,
        DCM_DEFAULT_MASK | DCM_EXTENDED_MASK,
        NULL_PTR
    },
    {
        0x04,
        TRUE,
        DCM_REQ_PHY_MASK | DCM_REQ_FUN_MASK,
        DCM_LOCKED_MASK | DCM_L2_MASK | DCM_L9_MASK,
        DCM_DEFAULT_MASK | DCM_PROGRAMMING_MASK | DCM_EXTENDED_MASK,
        NULL_PTR
    },
    {
        0x06,
        TRUE,
        DCM_REQ_PHY_MASK | DCM_REQ_FUN_MASK,
        DCM_LOCKED_MASK | DCM_L2_MASK | DCM_L9_MASK,
        DCM_DEFAULT_MASK | DCM_PROGRAMMING_MASK | DCM_EXTENDED_MASK,
        NULL_PTR
    },
    {
        0x0A,
        TRUE,
        DCM_REQ_PHY_MASK | DCM_REQ_FUN_MASK,
        DCM_LOCKED_MASK | DCM_L2_MASK | DCM_L9_MASK,
        DCM_DEFAULT_MASK | DCM_EXTENDED_MASK,
        NULL_PTR
    }
};
STATIC CONST(Dcm_DsdSubServiceType, DCM_CONST) Dcm_DsdSubService_27_0[4] =
{
    {
        0x03,
        TRUE,
        DCM_REQ_PHY_MASK,
        DCM_LOCKED_MASK | DCM_L9_MASK,
        DCM_PROGRAMMING_MASK | DCM_EXTENDED_MASK,
        NULL_PTR
    },
    {
        0x04,
        TRUE,
        DCM_REQ_PHY_MASK,
        DCM_LOCKED_MASK | DCM_L9_MASK,
        DCM_PROGRAMMING_MASK | DCM_EXTENDED_MASK,
        NULL_PTR
    },
    {
        0x11,
        TRUE,
        DCM_REQ_PHY_MASK,
        DCM_LOCKED_MASK | DCM_L2_MASK,
        DCM_PROGRAMMING_MASK,
        NULL_PTR
    },
    {
        0x12,
        TRUE,
        DCM_REQ_PHY_MASK,
        DCM_LOCKED_MASK | DCM_L2_MASK,
        DCM_PROGRAMMING_MASK,
        NULL_PTR
    }
};
STATIC CONST(Dcm_DsdSubServiceType, DCM_CONST) Dcm_DsdSubService_28_0[4] =
{
    {
        0x00,
        TRUE,
        DCM_REQ_PHY_MASK | DCM_REQ_FUN_MASK,
        DCM_L2_MASK,
        DCM_EXTENDED_MASK,
        NULL_PTR
    },
    {
        0x01,
        TRUE,
        DCM_REQ_PHY_MASK | DCM_REQ_FUN_MASK,
        DCM_LOCKED_MASK | DCM_L2_MASK | DCM_L9_MASK,
        DCM_PROGRAMMING_MASK | DCM_EXTENDED_MASK,
        NULL_PTR
    },
    {
        0x02,
        TRUE,
        DCM_REQ_PHY_MASK | DCM_REQ_FUN_MASK,
        DCM_LOCKED_MASK | DCM_L2_MASK | DCM_L9_MASK,
        DCM_PROGRAMMING_MASK | DCM_EXTENDED_MASK,
        NULL_PTR
    },
    {
        0x03,
        TRUE,
        DCM_REQ_PHY_MASK | DCM_REQ_FUN_MASK,
        DCM_L2_MASK,
        DCM_EXTENDED_MASK,
        NULL_PTR
    }
};
STATIC CONST(Dcm_DsdSubServiceType, DCM_CONST) Dcm_DsdSubService_3E_0[1] =
{
    {
        0x00,
        TRUE,
        DCM_REQ_PHY_MASK | DCM_REQ_FUN_MASK,
        DCM_LOCKED_MASK | DCM_L2_MASK | DCM_L9_MASK,
        DCM_DEFAULT_MASK | DCM_PROGRAMMING_MASK | DCM_EXTENDED_MASK,
        NULL_PTR
    }
};
STATIC CONST(Dcm_DsdSubServiceType, DCM_CONST) Dcm_DsdSubService_85_0[2] =
{
    {
        0x01,
        TRUE,
        DCM_REQ_PHY_MASK | DCM_REQ_FUN_MASK,
        DCM_L2_MASK,
        DCM_EXTENDED_MASK,
        NULL_PTR
    },
    {
        0x02,
        TRUE,
        DCM_REQ_PHY_MASK | DCM_REQ_FUN_MASK,
        DCM_L2_MASK,
        DCM_EXTENDED_MASK,
        NULL_PTR
    }
};

/*DcmDsdSericeTable*/
STATIC CONST(Dcm_DsdServiceType, DCM_CONST) DsdServiceTable_0[11] =
{
    {
        0x10,
        TRUE,
        DCM_REQ_PHY_MASK | DCM_REQ_FUN_MASK,
        2,
        NULL_PTR,
        TRUE,
        DCM_LOCKED_MASK | DCM_L2_MASK | DCM_L9_MASK,
        DCM_DEFAULT_MASK | DCM_PROGRAMMING_MASK | DCM_EXTENDED_MASK,
        3,
        Dcm_DsdSubService_10_0,
    },
    {
        0x11,
        TRUE,
        DCM_REQ_PHY_MASK | DCM_REQ_FUN_MASK,
        2,
        NULL_PTR,
        TRUE,
        DCM_LOCKED_MASK | DCM_L2_MASK | DCM_L9_MASK,
        DCM_PROGRAMMING_MASK | DCM_EXTENDED_MASK,
        2,
        Dcm_DsdSubService_11_0,
    },
    {
        0x14,
        TRUE,
        DCM_REQ_PHY_MASK | DCM_REQ_FUN_MASK,
        4,
        NULL_PTR,
        FALSE,
        DCM_LOCKED_MASK | DCM_L2_MASK | DCM_L9_MASK,
        DCM_DEFAULT_MASK | DCM_EXTENDED_MASK,
        0,
        NULL_PTR,
    },
    {
        0x19,
        TRUE,
        DCM_REQ_PHY_MASK | DCM_REQ_FUN_MASK,
        2,
        NULL_PTR,
        TRUE,
        DCM_LOCKED_MASK | DCM_L2_MASK | DCM_L9_MASK,
        DCM_DEFAULT_MASK | DCM_PROGRAMMING_MASK | DCM_EXTENDED_MASK,
        5,
        Dcm_DsdSubService_19_0,
    },
    {
        0x22,
        TRUE,
        DCM_REQ_PHY_MASK | DCM_REQ_FUN_MASK,
        3,
        NULL_PTR,
        FALSE,
        DCM_LOCKED_MASK | DCM_L2_MASK | DCM_L9_MASK,
        DCM_DEFAULT_MASK | DCM_PROGRAMMING_MASK | DCM_EXTENDED_MASK,
        0,
        NULL_PTR,
    },
    {
        0x27,
        TRUE,
        DCM_REQ_PHY_MASK,
        2,
        NULL_PTR,
        TRUE,
        DCM_LOCKED_MASK | DCM_L2_MASK | DCM_L9_MASK,
        DCM_PROGRAMMING_MASK | DCM_EXTENDED_MASK,
        4,
        Dcm_DsdSubService_27_0,
    },
    {
        0x28,
        TRUE,
        DCM_REQ_PHY_MASK | DCM_REQ_FUN_MASK,
        3,
        NULL_PTR,
        TRUE,
        DCM_LOCKED_MASK | DCM_L2_MASK | DCM_L9_MASK,
        DCM_PROGRAMMING_MASK | DCM_EXTENDED_MASK,
        4,
        Dcm_DsdSubService_28_0,
    },
    {
        0x2E,
        TRUE,
        DCM_REQ_PHY_MASK,
        4,
        NULL_PTR,
        FALSE,
        DCM_L2_MASK | DCM_L9_MASK,
        DCM_PROGRAMMING_MASK | DCM_EXTENDED_MASK,
        0,
        NULL_PTR,
    },
    {
        0x31,
        TRUE,
        DCM_REQ_PHY_MASK,
        4,
        NULL_PTR,
        TRUE,
        DCM_L2_MASK,
        DCM_EXTENDED_MASK,
        0,
        NULL_PTR,
    },
    {
        0x3E,
        TRUE,
        DCM_REQ_PHY_MASK | DCM_REQ_FUN_MASK,
        2,
        NULL_PTR,
        TRUE,
        DCM_LOCKED_MASK | DCM_L2_MASK | DCM_L9_MASK,
        DCM_DEFAULT_MASK | DCM_PROGRAMMING_MASK | DCM_EXTENDED_MASK,
        1,
        Dcm_DsdSubService_3E_0,
    },
    {
        0x85,
        TRUE,
        DCM_REQ_PHY_MASK | DCM_REQ_FUN_MASK,
        2,
        NULL_PTR,
        TRUE,
        DCM_L2_MASK,
        DCM_EXTENDED_MASK,
        2,
        Dcm_DsdSubService_85_0,
    },
};
STATIC CONST(Dcm_DsdServiceTableType, DCM_CONST) Dcm_DsdServiceTable[1] =
{
    {
        0,
        11,
        DsdServiceTable_0
    }
};
STATIC CONST(Dcm_DslProtocolRxType, DCM_CONST) Dcm_DslConnection_ACAN_Model_FunGroup0_ProtocolRx[2] =
{
    {
        DCM_FUNCTIONAL_TYPE,
        Dcm_PduR_CanConfigSet_Rx_ACAN_UDS_FuncDiagReq,
        Dcm_PduR_CanConfigSet_Rx_ACAN_UDS_FuncDiagReq
    },
    {
        DCM_PHYSICAL_TYPE,
        Dcm_PduR_CanConfigSet_Rx_ACAN_UDS_PhyDiagReq_ADAS,
        Dcm_PduR_CanConfigSet_Rx_ACAN_UDS_PhyDiagReq_ADAS
    }
};

STATIC CONST(Dcm_DslProtocolTxType, DCM_CONST) Dcm_DslConnection_ACAN_Model_FunGroup0_ProtocolTx =
{
    Dcm_PduR_CanConfigSet_Tx_ACAN_UDS_DiagResp_ADAS,
    PduR_Dcm_CanConfigSet_Tx_ACAN_UDS_DiagResp_ADAS
};

STATIC CONST(Dcm_DslMainConnectionType, DCM_CONST) Dcm_DslConnection_ACAN_Model_FunGroup0_MainConnection_0 =
{
    0x1234,
    ComM_ComM_CanCtrl_0,
    2,
    Dcm_DslConnection_ACAN_Model_FunGroup0_ProtocolRx,
    &Dcm_DslConnection_ACAN_Model_FunGroup0_ProtocolTx
};

STATIC CONST(Dcm_DslProtocolRxType, DCM_CONST) DslConnectionOnDoIP_ProtocolRx[2] =
{
    {
        DCM_FUNCTIONAL_TYPE,
        Dcm_PduR_DoIPDefaultConfig_DoIP_To_Dcm_Fun,
        Dcm_PduR_DoIPDefaultConfig_DoIP_To_Dcm_Fun
    },
    {
        DCM_PHYSICAL_TYPE,
        Dcm_PduR_DoIPDefaultConfig_DoIP_To_Dcm_Phy,
        Dcm_PduR_DoIPDefaultConfig_DoIP_To_Dcm_Phy
    }
};

STATIC CONST(Dcm_DslProtocolTxType, DCM_CONST) DslConnectionOnDoIP_ProtocolTx =
{
    Dcm_PduR_DoIPDefaultConfig_Dcm_To_DoIP,
    PduR_Dcm_DoIPDefaultConfig_Dcm_To_DoIP
};

STATIC CONST(Dcm_DslMainConnectionType, DCM_CONST) DslConnectionOnDoIP_MainConnection_0 =
{
    0x1234,
    ComM_ComM_EthCtrl,
    2,
    DslConnectionOnDoIP_ProtocolRx,
    &DslConnectionOnDoIP_ProtocolTx
};

STATIC CONST(Dcm_DslConnectionType, DCM_CONST) DslProtocolRow0_ConnectionTable_0[2] =
{
    {
        &Dcm_DslConnection_ACAN_Model_FunGroup0_MainConnection_0,
        NULL_PTR
    },
    {
        &DslConnectionOnDoIP_MainConnection_0,
        NULL_PTR
    }
};
CONST(Dcm_DslProtocolRowType, DCM_CONST) Dcm_DslProtocolRow[DCM_CFG_NUM_OF_PROTOCOL] =
{
    {
        DCM_UDS_ON_CAN,
        4095,
        0,
        1,
        TRUE,
        DCM_TYPE1,
        FALSE,
        0,
        0,
        {
            512,
            Buffer_0
        },
        {
            512,
            Buffer_0
        },
        &(Dcm_DsdServiceTable[0]),
        2,
        DslProtocolRow0_ConnectionTable_0,
        5000
    }
};


#define DCM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"

#define DCM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"

STATIC CONST(Dcm_DspSessionRowType, DCM_CONST) Dcm_DspSessionRow_0[3] =
{
    {
        DCM_NO_BOOT,
        DCM_DEFAULT_SESSION,
        DCM_DEFAULT_MASK,
        50,
        5000
    },
    {
        DCM_SYS_BOOT_RESPAPP,
        DCM_PROGRAMMING_SESSION,
        DCM_PROGRAMMING_MASK,
        50,
        5000
    },
    {
        DCM_NO_BOOT,
        DCM_EXTENDED_SESSION,
        DCM_EXTENDED_MASK,
        50,
        5000
    }
};
CONST(Dcm_DspSessionType, DCM_CONST) Dcm_DspSession[DCM_CFG_NUM_OF_PROTOCOL] =
{
    {
        3,
        Dcm_DspSessionRow_0
    }
};

STATIC CONST(Dcm_DspSecurityRowType, DCM_CONST) Dcm_DspSecurityRow_0[2] =
{
    {
        0,
        TRUE,
        Dcm_Rte_SecurityAccess_L2_CompareKey,
        20000,
        5000,
        Dcm_Rte_SecurityAccess_L2_GetSecurityAttemptCounter,
        0,
        4,
        0x2,
        3,
        4,
        Dcm_Rte_SecurityAccess_L2_SetSecurityAttemptCounter,
        DCM_USE_ASYNCH_CLIENT_SERVER,
        DCM_L2_MASK
    },
    {
        0,
        FALSE,
        Dcm_Rte_SecurityAccess_L9_CompareKey,
        20000,
        5000,
        NULL_PTR,
        1,
        4,
        0x9,
        3,
        4,
        NULL_PTR,
        DCM_USE_ASYNCH_CLIENT_SERVER,
        DCM_L9_MASK
    }
};
STATIC CONST(EcucFncGetSeedDefB, DCM_CONST) Dcm_DspSecurityGetSeedFncB_0[2] =
{
    Dcm_Rte_SecurityAccess_L2_GetSeed,
    Dcm_Rte_SecurityAccess_L9_GetSeed
};
CONST(Dcm_DspSecurityType, DCM_CONST) Dcm_DspSecurity[DCM_CFG_NUM_OF_PROTOCOL] =
{
    {
        2,
        Dcm_DspSecurityRow_0,
        NULL_PTR,
        Dcm_DspSecurityGetSeedFncB_0
    }
};

STATIC CONST(Dcm_DspComControlAllChannelType, DCM_CONST) Dcm_DspComControlAllChannel_0[3] =
{
    {
        TRUE,
        ComM_ComM_CanCtrl_0,
        SchM_Switch_DcmCommunicationControl_ComM_CanCtrl_0
    },
    {
        TRUE,
        ComM_ComM_CanCtrl_1,
        SchM_Switch_DcmCommunicationControl_ComM_CanCtrl_1
    },
    {
        TRUE,
        ComM_ComM_EthCtrl,
        SchM_Switch_DcmCommunicationControl_ComM_EthCtrl
    }
};
CONST(Dcm_DspComControlType, DCM_CONST) Dcm_DspComControl[DCM_CFG_NUM_OF_PROTOCOL] =
{
    {
        3,
        Dcm_DspComControlAllChannel_0,
        0,
        NULL_PTR,
        0,
        NULL_PTR
    }
};

STATIC CONST(Dcm_DspDataTableType, DCM_CONST) Dcm_DspDataTable_0[58] =
{
    {/*0*/
        DCM_OPAQUE,
        DCM_FNC_INVALID_INDEX,
        FALSE,
        DCM_FNC_INVALID_INDEX,
        0,
        8,
        DCM_UINT8,
        DCM_USE_DATA_ASYNCH_CLIENT_SERVER_ERROR,
        DCM_FNC_INVALID_INDEX,
        0
    },
    {/*1*/
        DCM_OPAQUE,
        DCM_FNC_INVALID_INDEX,
        FALSE,
        DCM_FNC_INVALID_INDEX,
        1,
        24,
        DCM_UINT8_N,
        DCM_USE_DATA_ASYNCH_CLIENT_SERVER_ERROR,
        DCM_FNC_INVALID_INDEX,
        0
    },
    {/*2*/
        DCM_OPAQUE,
        DCM_FNC_INVALID_INDEX,
        FALSE,
        DCM_FNC_INVALID_INDEX,
        2,
        48,
        DCM_UINT8_N,
        DCM_USE_DATA_ASYNCH_CLIENT_SERVER_ERROR,
        DCM_FNC_INVALID_INDEX,
        0
    },
    {/*3*/
        DCM_OPAQUE,
        DCM_FNC_INVALID_INDEX,
        FALSE,
        DCM_FNC_INVALID_INDEX,
        3,
        16,
        DCM_UINT8_N,
        DCM_USE_DATA_ASYNCH_CLIENT_SERVER_ERROR,
        DCM_FNC_INVALID_INDEX,
        0
    },
    {/*4*/
        DCM_OPAQUE,
        DCM_FNC_INVALID_INDEX,
        FALSE,
        DCM_FNC_INVALID_INDEX,
        4,
        8,
        DCM_UINT8,
        DCM_USE_DATA_ASYNCH_CLIENT_SERVER_ERROR,
        DCM_FNC_INVALID_INDEX,
        0
    },
    {/*5*/
        DCM_OPAQUE,
        DCM_FNC_INVALID_INDEX,
        FALSE,
        DCM_FNC_INVALID_INDEX,
        5,
        8,
        DCM_UINT8,
        DCM_USE_DATA_ASYNCH_CLIENT_SERVER_ERROR,
        0,
        0
    },
    {/*6*/
        DCM_OPAQUE,
        DCM_FNC_INVALID_INDEX,
        FALSE,
        DCM_FNC_INVALID_INDEX,
        6,
        8,
        DCM_UINT8,
        DCM_USE_DATA_ASYNCH_CLIENT_SERVER_ERROR,
        1,
        0
    },
    {/*7*/
        DCM_OPAQUE,
        DCM_FNC_INVALID_INDEX,
        FALSE,
        DCM_FNC_INVALID_INDEX,
        7,
        8,
        DCM_UINT8,
        DCM_USE_DATA_ASYNCH_CLIENT_SERVER_ERROR,
        2,
        0
    },
    {/*8*/
        DCM_OPAQUE,
        DCM_FNC_INVALID_INDEX,
        FALSE,
        DCM_FNC_INVALID_INDEX,
        8,
        96,
        DCM_UINT8_N,
        DCM_USE_DATA_ASYNCH_CLIENT_SERVER_ERROR,
        DCM_FNC_INVALID_INDEX,
        0
    },
    {/*9*/
        DCM_OPAQUE,
        DCM_FNC_INVALID_INDEX,
        FALSE,
        DCM_FNC_INVALID_INDEX,
        9,
        96,
        DCM_UINT8_N,
        DCM_USE_DATA_ASYNCH_CLIENT_SERVER_ERROR,
        DCM_FNC_INVALID_INDEX,
        0
    },
    {/*10*/
        DCM_OPAQUE,
        DCM_FNC_INVALID_INDEX,
        FALSE,
        DCM_FNC_INVALID_INDEX,
        10,
        8,
        DCM_UINT8,
        DCM_USE_DATA_ASYNCH_CLIENT_SERVER_ERROR,
        DCM_FNC_INVALID_INDEX,
        0
    },
    {/*11*/
        DCM_OPAQUE,
        DCM_FNC_INVALID_INDEX,
        FALSE,
        DCM_FNC_INVALID_INDEX,
        11,
        96,
        DCM_UINT8_N,
        DCM_USE_DATA_ASYNCH_CLIENT_SERVER_ERROR,
        DCM_FNC_INVALID_INDEX,
        0
    },
    {/*12*/
        DCM_OPAQUE,
        DCM_FNC_INVALID_INDEX,
        FALSE,
        DCM_FNC_INVALID_INDEX,
        12,
        96,
        DCM_UINT8_N,
        DCM_USE_DATA_ASYNCH_CLIENT_SERVER_ERROR,
        DCM_FNC_INVALID_INDEX,
        0
    },
    {/*13*/
        DCM_OPAQUE,
        DCM_FNC_INVALID_INDEX,
        FALSE,
        DCM_FNC_INVALID_INDEX,
        13,
        16,
        DCM_UINT8_N,
        DCM_USE_DATA_ASYNCH_CLIENT_SERVER_ERROR,
        DCM_FNC_INVALID_INDEX,
        0
    },
    {/*14*/
        DCM_OPAQUE,
        DCM_FNC_INVALID_INDEX,
        FALSE,
        DCM_FNC_INVALID_INDEX,
        14,
        72,
        DCM_UINT8_N,
        DCM_USE_DATA_ASYNCH_CLIENT_SERVER_ERROR,
        DCM_FNC_INVALID_INDEX,
        0
    },
    {/*15*/
        DCM_OPAQUE,
        DCM_FNC_INVALID_INDEX,
        FALSE,
        DCM_FNC_INVALID_INDEX,
        15,
        64,
        DCM_UINT8_N,
        DCM_USE_DATA_ASYNCH_CLIENT_SERVER_ERROR,
        DCM_FNC_INVALID_INDEX,
        0
    },
    {/*16*/
        DCM_OPAQUE,
        DCM_FNC_INVALID_INDEX,
        FALSE,
        DCM_FNC_INVALID_INDEX,
        16,
        64,
        DCM_UINT8_N,
        DCM_USE_DATA_ASYNCH_CLIENT_SERVER_ERROR,
        DCM_FNC_INVALID_INDEX,
        0
    },
    {/*17*/
        DCM_OPAQUE,
        DCM_FNC_INVALID_INDEX,
        FALSE,
        DCM_FNC_INVALID_INDEX,
        17,
        64,
        DCM_UINT8_N,
        DCM_USE_DATA_ASYNCH_CLIENT_SERVER_ERROR,
        DCM_FNC_INVALID_INDEX,
        0
    },
    {/*18*/
        DCM_OPAQUE,
        DCM_FNC_INVALID_INDEX,
        FALSE,
        DCM_FNC_INVALID_INDEX,
        18,
        64,
        DCM_UINT8_N,
        DCM_USE_DATA_ASYNCH_CLIENT_SERVER_ERROR,
        DCM_FNC_INVALID_INDEX,
        0
    },
    {/*19*/
        DCM_OPAQUE,
        DCM_FNC_INVALID_INDEX,
        FALSE,
        DCM_FNC_INVALID_INDEX,
        19,
        8,
        DCM_UINT8,
        DCM_USE_DATA_ASYNCH_CLIENT_SERVER_ERROR,
        DCM_FNC_INVALID_INDEX,
        0
    },
    {/*20*/
        DCM_OPAQUE,
        DCM_FNC_INVALID_INDEX,
        FALSE,
        DCM_FNC_INVALID_INDEX,
        20,
        40,
        DCM_UINT8_N,
        DCM_USE_DATA_ASYNCH_CLIENT_SERVER_ERROR,
        DCM_FNC_INVALID_INDEX,
        0
    },
    {/*21*/
        DCM_OPAQUE,
        DCM_FNC_INVALID_INDEX,
        FALSE,
        DCM_FNC_INVALID_INDEX,
        21,
        200,
        DCM_UINT8_N,
        DCM_USE_DATA_ASYNCH_CLIENT_SERVER_ERROR,
        DCM_FNC_INVALID_INDEX,
        0
    },
    {/*22*/
        DCM_OPAQUE,
        DCM_FNC_INVALID_INDEX,
        FALSE,
        DCM_FNC_INVALID_INDEX,
        22,
        200,
        DCM_UINT8_N,
        DCM_USE_DATA_ASYNCH_CLIENT_SERVER_ERROR,
        DCM_FNC_INVALID_INDEX,
        0
    },
    {/*23*/
        DCM_OPAQUE,
        DCM_FNC_INVALID_INDEX,
        FALSE,
        DCM_FNC_INVALID_INDEX,
        23,
        200,
        DCM_UINT8_N,
        DCM_USE_DATA_ASYNCH_CLIENT_SERVER_ERROR,
        DCM_FNC_INVALID_INDEX,
        0
    },
    {/*24*/
        DCM_OPAQUE,
        DCM_FNC_INVALID_INDEX,
        FALSE,
        DCM_FNC_INVALID_INDEX,
        24,
        8,
        DCM_UINT8,
        DCM_USE_DATA_ASYNCH_CLIENT_SERVER_ERROR,
        DCM_FNC_INVALID_INDEX,
        0
    },
    {/*25*/
        DCM_OPAQUE,
        DCM_FNC_INVALID_INDEX,
        FALSE,
        DCM_FNC_INVALID_INDEX,
        25,
        288,
        DCM_UINT8_N,
        DCM_USE_DATA_ASYNCH_CLIENT_SERVER_ERROR,
        DCM_FNC_INVALID_INDEX,
        0
    },
    {/*26*/
        DCM_OPAQUE,
        DCM_FNC_INVALID_INDEX,
        FALSE,
        DCM_FNC_INVALID_INDEX,
        26,
        240,
        DCM_UINT8_N,
        DCM_USE_DATA_ASYNCH_CLIENT_SERVER_ERROR,
        DCM_FNC_INVALID_INDEX,
        0
    },
    {/*27*/
        DCM_OPAQUE,
        DCM_FNC_INVALID_INDEX,
        FALSE,
        DCM_FNC_INVALID_INDEX,
        27,
        48,
        DCM_UINT8_N,
        DCM_USE_DATA_ASYNCH_CLIENT_SERVER_ERROR,
        DCM_FNC_INVALID_INDEX,
        0
    },
    {/*28*/
        DCM_OPAQUE,
        DCM_FNC_INVALID_INDEX,
        FALSE,
        DCM_FNC_INVALID_INDEX,
        28,
        16,
        DCM_UINT8_N,
        DCM_USE_DATA_ASYNCH_CLIENT_SERVER_ERROR,
        DCM_FNC_INVALID_INDEX,
        0
    },
    {/*29*/
        DCM_OPAQUE,
        DCM_FNC_INVALID_INDEX,
        FALSE,
        DCM_FNC_INVALID_INDEX,
        29,
        128,
        DCM_UINT8_N,
        DCM_USE_DATA_ASYNCH_CLIENT_SERVER_ERROR,
        3,
        0
    },
    {/*30*/
        DCM_OPAQUE,
        DCM_FNC_INVALID_INDEX,
        FALSE,
        DCM_FNC_INVALID_INDEX,
        30,
        104,
        DCM_UINT8_N,
        DCM_USE_DATA_ASYNCH_CLIENT_SERVER_ERROR,
        DCM_FNC_INVALID_INDEX,
        0
    },
    {/*31*/
        DCM_OPAQUE,
        DCM_FNC_INVALID_INDEX,
        FALSE,
        DCM_FNC_INVALID_INDEX,
        31,
        8,
        DCM_UINT8,
        DCM_USE_DATA_ASYNCH_CLIENT_SERVER_ERROR,
        4,
        0
    },
    {/*32*/
        DCM_OPAQUE,
        DCM_FNC_INVALID_INDEX,
        FALSE,
        DCM_FNC_INVALID_INDEX,
        32,
        8,
        DCM_UINT8,
        DCM_USE_DATA_ASYNCH_CLIENT_SERVER_ERROR,
        5,
        0
    },
    {/*33*/
        DCM_OPAQUE,
        DCM_FNC_INVALID_INDEX,
        FALSE,
        DCM_FNC_INVALID_INDEX,
        33,
        64,
        DCM_UINT8_N,
        DCM_USE_DATA_ASYNCH_CLIENT_SERVER_ERROR,
        DCM_FNC_INVALID_INDEX,
        0
    },
    {/*34*/
        DCM_OPAQUE,
        DCM_FNC_INVALID_INDEX,
        FALSE,
        DCM_FNC_INVALID_INDEX,
        34,
        104,
        DCM_UINT8_N,
        DCM_USE_DATA_ASYNCH_CLIENT_SERVER_ERROR,
        DCM_FNC_INVALID_INDEX,
        0
    },
    {/*35*/
        DCM_OPAQUE,
        DCM_FNC_INVALID_INDEX,
        FALSE,
        DCM_FNC_INVALID_INDEX,
        35,
        208,
        DCM_UINT8_N,
        DCM_USE_DATA_ASYNCH_CLIENT_SERVER_ERROR,
        DCM_FNC_INVALID_INDEX,
        0
    },
    {/*36*/
        DCM_OPAQUE,
        DCM_FNC_INVALID_INDEX,
        FALSE,
        DCM_FNC_INVALID_INDEX,
        36,
        8,
        DCM_UINT8,
        DCM_USE_DATA_ASYNCH_CLIENT_SERVER_ERROR,
        DCM_FNC_INVALID_INDEX,
        0
    },
    {/*37*/
        DCM_OPAQUE,
        DCM_FNC_INVALID_INDEX,
        FALSE,
        DCM_FNC_INVALID_INDEX,
        37,
        208,
        DCM_UINT8_N,
        DCM_USE_DATA_ASYNCH_CLIENT_SERVER_ERROR,
        DCM_FNC_INVALID_INDEX,
        0
    },
    {/*38*/
        DCM_OPAQUE,
        DCM_FNC_INVALID_INDEX,
        FALSE,
        DCM_FNC_INVALID_INDEX,
        38,
        48,
        DCM_UINT8_N,
        DCM_USE_DATA_ASYNCH_CLIENT_SERVER_ERROR,
        DCM_FNC_INVALID_INDEX,
        0
    },
    {/*39*/
        DCM_OPAQUE,
        DCM_FNC_INVALID_INDEX,
        FALSE,
        DCM_FNC_INVALID_INDEX,
        39,
        240,
        DCM_UINT8_N,
        DCM_USE_DATA_ASYNCH_CLIENT_SERVER_ERROR,
        DCM_FNC_INVALID_INDEX,
        0
    },
    {/*40*/
        DCM_OPAQUE,
        DCM_FNC_INVALID_INDEX,
        FALSE,
        DCM_FNC_INVALID_INDEX,
        40,
        136,
        DCM_UINT8_N,
        DCM_USE_DATA_ASYNCH_CLIENT_SERVER_ERROR,
        6,
        0
    },
    {/*41*/
        DCM_OPAQUE,
        DCM_FNC_INVALID_INDEX,
        FALSE,
        DCM_FNC_INVALID_INDEX,
        41,
        208,
        DCM_UINT8_N,
        DCM_USE_DATA_ASYNCH_CLIENT_SERVER_ERROR,
        DCM_FNC_INVALID_INDEX,
        0
    },
    {/*42*/
        DCM_OPAQUE,
        DCM_FNC_INVALID_INDEX,
        FALSE,
        DCM_FNC_INVALID_INDEX,
        42,
        208,
        DCM_UINT8_N,
        DCM_USE_DATA_ASYNCH_CLIENT_SERVER_ERROR,
        DCM_FNC_INVALID_INDEX,
        0
    },
    {/*43*/
        DCM_OPAQUE,
        DCM_FNC_INVALID_INDEX,
        FALSE,
        DCM_FNC_INVALID_INDEX,
        43,
        48,
        DCM_UINT8_N,
        DCM_USE_DATA_ASYNCH_CLIENT_SERVER_ERROR,
        DCM_FNC_INVALID_INDEX,
        0
    },
    {/*44*/
        DCM_OPAQUE,
        DCM_FNC_INVALID_INDEX,
        FALSE,
        DCM_FNC_INVALID_INDEX,
        44,
        128,
        DCM_UINT8_N,
        DCM_USE_DATA_ASYNCH_CLIENT_SERVER_ERROR,
        7,
        0
    },
    {/*45*/
        DCM_OPAQUE,
        DCM_FNC_INVALID_INDEX,
        FALSE,
        DCM_FNC_INVALID_INDEX,
        45,
        32,
        DCM_UINT8_N,
        DCM_USE_DATA_ASYNCH_CLIENT_SERVER_ERROR,
        DCM_FNC_INVALID_INDEX,
        0
    },
    {/*46*/
        DCM_OPAQUE,
        DCM_FNC_INVALID_INDEX,
        FALSE,
        DCM_FNC_INVALID_INDEX,
        46,
        32,
        DCM_UINT8_N,
        DCM_USE_DATA_ASYNCH_CLIENT_SERVER_ERROR,
        DCM_FNC_INVALID_INDEX,
        0
    },
    {/*47*/
        DCM_OPAQUE,
        DCM_FNC_INVALID_INDEX,
        FALSE,
        DCM_FNC_INVALID_INDEX,
        47,
        16,
        DCM_UINT8_N,
        DCM_USE_DATA_ASYNCH_CLIENT_SERVER_ERROR,
        DCM_FNC_INVALID_INDEX,
        0
    },
    {/*48*/
        DCM_OPAQUE,
        DCM_FNC_INVALID_INDEX,
        FALSE,
        DCM_FNC_INVALID_INDEX,
        48,
        8,
        DCM_UINT8,
        DCM_USE_DATA_ASYNCH_CLIENT_SERVER_ERROR,
        8,
        0
    },
    {/*49*/
        DCM_OPAQUE,
        DCM_FNC_INVALID_INDEX,
        FALSE,
        DCM_FNC_INVALID_INDEX,
        49,
        8,
        DCM_UINT8,
        DCM_USE_DATA_ASYNCH_CLIENT_SERVER_ERROR,
        9,
        0
    },
    {/*50*/
        DCM_OPAQUE,
        DCM_FNC_INVALID_INDEX,
        FALSE,
        DCM_FNC_INVALID_INDEX,
        50,
        48,
        DCM_UINT8_N,
        DCM_USE_DATA_ASYNCH_CLIENT_SERVER_ERROR,
        DCM_FNC_INVALID_INDEX,
        0
    },
    {/*51*/
        DCM_OPAQUE,
        DCM_FNC_INVALID_INDEX,
        FALSE,
        DCM_FNC_INVALID_INDEX,
        51,
        16,
        DCM_UINT8_N,
        DCM_USE_DATA_ASYNCH_CLIENT_SERVER_ERROR,
        DCM_FNC_INVALID_INDEX,
        0
    },
    {/*52*/
        DCM_OPAQUE,
        DCM_FNC_INVALID_INDEX,
        FALSE,
        DCM_FNC_INVALID_INDEX,
        52,
        16,
        DCM_UINT8_N,
        DCM_USE_DATA_ASYNCH_CLIENT_SERVER_ERROR,
        10,
        0
    },
    {/*53*/
        DCM_OPAQUE,
        DCM_FNC_INVALID_INDEX,
        FALSE,
        DCM_FNC_INVALID_INDEX,
        53,
        16,
        DCM_UINT8_N,
        DCM_USE_DATA_ASYNCH_CLIENT_SERVER_ERROR,
        DCM_FNC_INVALID_INDEX,
        0
    },
    {/*54*/
        DCM_OPAQUE,
        DCM_FNC_INVALID_INDEX,
        FALSE,
        DCM_FNC_INVALID_INDEX,
        54,
        32,
        DCM_UINT8_N,
        DCM_USE_DATA_ASYNCH_CLIENT_SERVER_ERROR,
        DCM_FNC_INVALID_INDEX,
        0
    },
    {/*55*/
        DCM_OPAQUE,
        DCM_FNC_INVALID_INDEX,
        FALSE,
        DCM_FNC_INVALID_INDEX,
        55,
        56,
        DCM_UINT8_N,
        DCM_USE_DATA_ASYNCH_CLIENT_SERVER_ERROR,
        11,
        0
    },
    {/*56*/
        DCM_OPAQUE,
        DCM_FNC_INVALID_INDEX,
        FALSE,
        DCM_FNC_INVALID_INDEX,
        56,
        16,
        DCM_UINT8_N,
        DCM_USE_DATA_ASYNCH_CLIENT_SERVER_ERROR,
        DCM_FNC_INVALID_INDEX,
        0
    },
    {/*57*/
        DCM_OPAQUE,
        DCM_FNC_INVALID_INDEX,
        FALSE,
        DCM_FNC_INVALID_INDEX,
        57,
        40,
        DCM_UINT8_N,
        DCM_USE_DATA_ASYNCH_CLIENT_SERVER_ERROR,
        DCM_FNC_INVALID_INDEX,
        0
    }
};
STATIC CONST(EcucFncDataServicesReadDataDefB, DCM_CONST) Dcm_DspDataReadDataFncB_0[58U] =
{
    Dcm_Rte_DataServices_DspData_0x4F01_0_ReadData,
    Dcm_Rte_DataServices_DspData_0x4F02_0_ReadData,
    Dcm_Rte_DataServices_DspData_0x4F03_0_ReadData,
    Dcm_Rte_DataServices_DspData_0x4F04_0_ReadData,
    Dcm_Rte_DataServices_DspData_0x4F05_0_ReadData,
    Dcm_Rte_DataServices_DspData_0x4F30_0_ReadData,
    Dcm_Rte_DataServices_DspData_0x4F31_0_ReadData,
    Dcm_Rte_DataServices_DspData_0x4F32_0_ReadData,
    Dcm_Rte_DataServices_DspData_0x4F33_0_ReadData,
    Dcm_Rte_DataServices_DspData_0x4F34_0_ReadData,
    Dcm_Rte_DataServices_DspData_0x4F35_0_ReadData,
    Dcm_Rte_DataServices_DspData_0x4F36_0_ReadData,
    Dcm_Rte_DataServices_DspData_0x4F37_0_ReadData,
    Dcm_Rte_DataServices_DspData_0x4F38_0_ReadData,
    Dcm_Rte_DataServices_DspData_0x4F39_0_ReadData,
    Dcm_Rte_DataServices_DspData_0x4F3A_0_ReadData,
    Dcm_Rte_DataServices_DspData_0x4F3B_0_ReadData,
    Dcm_Rte_DataServices_DspData_0x4F3C_0_ReadData,
    Dcm_Rte_DataServices_DspData_0x4F3D_0_ReadData,
    Dcm_Rte_DataServices_DspData_0x4F3E_0_ReadData,
    Dcm_Rte_DataServices_DspData_0x4F3F_0_ReadData,
    Dcm_Rte_DataServices_DspData_0x4F40_0_ReadData,
    Dcm_Rte_DataServices_DspData_0x4F41_0_ReadData,
    Dcm_Rte_DataServices_DspData_0x4F42_0_ReadData,
    Dcm_Rte_DataServices_DspData_0x4F43_0_ReadData,
    Dcm_Rte_DataServices_DspData_0x4F44_0_ReadData,
    Dcm_Rte_DataServices_DspData_0x4F45_0_ReadData,
    Dcm_Rte_DataServices_DspData_0x4F46_0_ReadData,
    Dcm_Rte_DataServices_DspData_0x4F48_0_ReadData,
    Dcm_Rte_DataServices_DspData_0x4F4A_0_ReadData,
    Dcm_Rte_DataServices_DspData_0x4F4B_0_ReadData,
    Dcm_Rte_DataServices_DspData_0x4F4C_0_ReadData,
    Dcm_Rte_DataServices_DspData_0x4F4D_0_ReadData,
    Dcm_Rte_DataServices_DspData_0xF112_0_ReadData,
    Dcm_Rte_DataServices_DspData_0xF15A_0_ReadData,
    Dcm_Rte_DataServices_DspData_0xF180_0_ReadData,
    Dcm_Rte_DataServices_DspData_0xF186_0_ReadData,
    Dcm_Rte_DataServices_DspData_0xF187_0_ReadData,
    Dcm_Rte_DataServices_DspData_0xF18A_0_ReadData,
    Dcm_Rte_DataServices_DspData_0xF18C_0_ReadData,
    Dcm_Rte_DataServices_DspData_0xF190_0_ReadData,
    Dcm_Rte_DataServices_DspData_0xF192_0_ReadData,
    Dcm_Rte_DataServices_DspData_0xF193_0_ReadData,
    Dcm_Rte_DataServices_DspData_0xF195_0_ReadData,
    Dcm_Rte_DataServices_DspData_0xF198_0_ReadData,
    Dcm_Rte_DataServices_DspData_0xF199_0_ReadData,
    Dcm_Rte_DataServices_DspData_0xF19D_0_ReadData,
    Dcm_Rte_DataServices_DspData_0xF1C1_0_ReadData,
    Dcm_Rte_DataServices_DspData_0xF1C2_0_ReadData,
    Dcm_Rte_DataServices_DspData_0xF1C3_0_ReadData,
    Dcm_Rte_DataServices_DspData_0xF1C6_0_ReadData,
    Dcm_Rte_DataServices_DspData_0xF1C7_0_ReadData,
    Dcm_Rte_DataServices_DspData_0xF1C8_0_ReadData,
    Dcm_Rte_DataServices_DspData_0xF1C9_0_ReadData,
    Dcm_Rte_DataServices_DspData_0xF1CA_0_ReadData,
    Dcm_Rte_DataServices_DspData_0xF1CB_0_ReadData,
    Dcm_Rte_DataServices_DspData_0xF1CC_0_ReadData,
    Dcm_Rte_DataServices_DspData_0xF1CD_0_ReadData
};
STATIC CONST(EcucFncDataServicesWriteDataDefA, DCM_CONST) Dcm_DspDataWriteDataFncA_0[12U] =
{
    Dcm_Rte_DataServices_DspData_0x4F30_0_WriteData,
    Dcm_Rte_DataServices_DspData_0x4F31_0_WriteData,
    Dcm_Rte_DataServices_DspData_0x4F32_0_WriteData,
    Dcm_Rte_DataServices_DspData_0x4F4A_0_WriteData,
    Dcm_Rte_DataServices_DspData_0x4F4C_0_WriteData,
    Dcm_Rte_DataServices_DspData_0x4F4D_0_WriteData,
    Dcm_Rte_DataServices_DspData_0xF190_0_WriteData,
    Dcm_Rte_DataServices_DspData_0xF198_0_WriteData,
    Dcm_Rte_DataServices_DspData_0xF1C2_0_WriteData,
    Dcm_Rte_DataServices_DspData_0xF1C3_0_WriteData,
    Dcm_Rte_DataServices_DspData_0xF1C8_0_WriteData,
    Dcm_Rte_DataServices_DspData_0xF1CB_0_WriteData
};
CONST(Dcm_DspDataType, DCM_CONST) Dcm_DspData[DCM_CFG_NUM_OF_PROTOCOL] =
{
    {
        58,
        Dcm_DspDataTable_0,
        NULL_PTR,
        NULL_PTR,
        NULL_PTR,
        NULL_PTR,
        NULL_PTR,
        Dcm_DspDataReadDataFncB_0,
        NULL_PTR,
        Dcm_DspDataWriteDataFncA_0,
        NULL_PTR,
        NULL_PTR,
        NULL_PTR,
    }
};
STATIC CONST(Dcm_DspDidSignalType, DCM_CONST) Dcm_DspDidSignal_0x4F01_0[1] =
{
    {
        0,
        0
    }
};
STATIC CONST(Dcm_DspDidSignalType, DCM_CONST) Dcm_DspDidSignal_0x4F02_0[1] =
{
    {
        0,
        1
    }
};
STATIC CONST(Dcm_DspDidSignalType, DCM_CONST) Dcm_DspDidSignal_0x4F03_0[1] =
{
    {
        0,
        2
    }
};
STATIC CONST(Dcm_DspDidSignalType, DCM_CONST) Dcm_DspDidSignal_0x4F04_0[1] =
{
    {
        0,
        3
    }
};
STATIC CONST(Dcm_DspDidSignalType, DCM_CONST) Dcm_DspDidSignal_0x4F05_0[1] =
{
    {
        0,
        4
    }
};
STATIC CONST(Dcm_DspDidSignalType, DCM_CONST) Dcm_DspDidSignal_0x4F30_0[1] =
{
    {
        0,
        5
    }
};
STATIC CONST(Dcm_DspDidSignalType, DCM_CONST) Dcm_DspDidSignal_0x4F31_0[1] =
{
    {
        0,
        6
    }
};
STATIC CONST(Dcm_DspDidSignalType, DCM_CONST) Dcm_DspDidSignal_0x4F32_0[1] =
{
    {
        0,
        7
    }
};
STATIC CONST(Dcm_DspDidSignalType, DCM_CONST) Dcm_DspDidSignal_0x4F33_0[1] =
{
    {
        0,
        8
    }
};
STATIC CONST(Dcm_DspDidSignalType, DCM_CONST) Dcm_DspDidSignal_0x4F34_0[1] =
{
    {
        0,
        9
    }
};
STATIC CONST(Dcm_DspDidSignalType, DCM_CONST) Dcm_DspDidSignal_0x4F35_0[1] =
{
    {
        0,
        10
    }
};
STATIC CONST(Dcm_DspDidSignalType, DCM_CONST) Dcm_DspDidSignal_0x4F36_0[1] =
{
    {
        0,
        11
    }
};
STATIC CONST(Dcm_DspDidSignalType, DCM_CONST) Dcm_DspDidSignal_0x4F37_0[1] =
{
    {
        0,
        12
    }
};
STATIC CONST(Dcm_DspDidSignalType, DCM_CONST) Dcm_DspDidSignal_0x4F38_0[1] =
{
    {
        0,
        13
    }
};
STATIC CONST(Dcm_DspDidSignalType, DCM_CONST) Dcm_DspDidSignal_0x4F39_0[1] =
{
    {
        0,
        14
    }
};
STATIC CONST(Dcm_DspDidSignalType, DCM_CONST) Dcm_DspDidSignal_0x4F3A_0[1] =
{
    {
        0,
        15
    }
};
STATIC CONST(Dcm_DspDidSignalType, DCM_CONST) Dcm_DspDidSignal_0x4F3B_0[1] =
{
    {
        0,
        16
    }
};
STATIC CONST(Dcm_DspDidSignalType, DCM_CONST) Dcm_DspDidSignal_0x4F3C_0[1] =
{
    {
        0,
        17
    }
};
STATIC CONST(Dcm_DspDidSignalType, DCM_CONST) Dcm_DspDidSignal_0x4F3D_0[1] =
{
    {
        0,
        18
    }
};
STATIC CONST(Dcm_DspDidSignalType, DCM_CONST) Dcm_DspDidSignal_0x4F3E_0[1] =
{
    {
        0,
        19
    }
};
STATIC CONST(Dcm_DspDidSignalType, DCM_CONST) Dcm_DspDidSignal_0x4F3F_0[1] =
{
    {
        0,
        20
    }
};
STATIC CONST(Dcm_DspDidSignalType, DCM_CONST) Dcm_DspDidSignal_0x4F40_0[1] =
{
    {
        0,
        21
    }
};
STATIC CONST(Dcm_DspDidSignalType, DCM_CONST) Dcm_DspDidSignal_0x4F41_0[1] =
{
    {
        0,
        22
    }
};
STATIC CONST(Dcm_DspDidSignalType, DCM_CONST) Dcm_DspDidSignal_0x4F42_0[1] =
{
    {
        0,
        23
    }
};
STATIC CONST(Dcm_DspDidSignalType, DCM_CONST) Dcm_DspDidSignal_0x4F43_0[1] =
{
    {
        0,
        24
    }
};
STATIC CONST(Dcm_DspDidSignalType, DCM_CONST) Dcm_DspDidSignal_0x4F44_0[1] =
{
    {
        0,
        25
    }
};
STATIC CONST(Dcm_DspDidSignalType, DCM_CONST) Dcm_DspDidSignal_0x4F45_0[1] =
{
    {
        0,
        26
    }
};
STATIC CONST(Dcm_DspDidSignalType, DCM_CONST) Dcm_DspDidSignal_0x4F46_0[1] =
{
    {
        0,
        27
    }
};
STATIC CONST(Dcm_DspDidSignalType, DCM_CONST) Dcm_DspDidSignal_0x4F48_0[1] =
{
    {
        0,
        28
    }
};
STATIC CONST(Dcm_DspDidSignalType, DCM_CONST) Dcm_DspDidSignal_0x4F4A_0[1] =
{
    {
        0,
        29
    }
};
STATIC CONST(Dcm_DspDidSignalType, DCM_CONST) Dcm_DspDidSignal_0x4F4B_0[1] =
{
    {
        0,
        30
    }
};
STATIC CONST(Dcm_DspDidSignalType, DCM_CONST) Dcm_DspDidSignal_0x4F4C_0[1] =
{
    {
        0,
        31
    }
};
STATIC CONST(Dcm_DspDidSignalType, DCM_CONST) Dcm_DspDidSignal_0x4F4D_0[1] =
{
    {
        0,
        32
    }
};
STATIC CONST(Dcm_DspDidSignalType, DCM_CONST) Dcm_DspDidSignal_0xF112_0[1] =
{
    {
        0,
        33
    }
};
STATIC CONST(Dcm_DspDidSignalType, DCM_CONST) Dcm_DspDidSignal_0xF15A_0[1] =
{
    {
        0,
        34
    }
};
STATIC CONST(Dcm_DspDidSignalType, DCM_CONST) Dcm_DspDidSignal_0xF180_0[1] =
{
    {
        0,
        35
    }
};
STATIC CONST(Dcm_DspDidSignalType, DCM_CONST) Dcm_DspDidSignal_0xF186_0[1] =
{
    {
        0,
        36
    }
};
STATIC CONST(Dcm_DspDidSignalType, DCM_CONST) Dcm_DspDidSignal_0xF187_0[1] =
{
    {
        0,
        37
    }
};
STATIC CONST(Dcm_DspDidSignalType, DCM_CONST) Dcm_DspDidSignal_0xF18A_0[1] =
{
    {
        0,
        38
    }
};
STATIC CONST(Dcm_DspDidSignalType, DCM_CONST) Dcm_DspDidSignal_0xF18C_0[1] =
{
    {
        0,
        39
    }
};
STATIC CONST(Dcm_DspDidSignalType, DCM_CONST) Dcm_DspDidSignal_0xF190_0[1] =
{
    {
        0,
        40
    }
};
STATIC CONST(Dcm_DspDidSignalType, DCM_CONST) Dcm_DspDidSignal_0xF192_0[1] =
{
    {
        0,
        41
    }
};
STATIC CONST(Dcm_DspDidSignalType, DCM_CONST) Dcm_DspDidSignal_0xF193_0[1] =
{
    {
        0,
        42
    }
};
STATIC CONST(Dcm_DspDidSignalType, DCM_CONST) Dcm_DspDidSignal_0xF195_0[1] =
{
    {
        0,
        43
    }
};
STATIC CONST(Dcm_DspDidSignalType, DCM_CONST) Dcm_DspDidSignal_0xF198_0[1] =
{
    {
        0,
        44
    }
};
STATIC CONST(Dcm_DspDidSignalType, DCM_CONST) Dcm_DspDidSignal_0xF199_0[1] =
{
    {
        0,
        45
    }
};
STATIC CONST(Dcm_DspDidSignalType, DCM_CONST) Dcm_DspDidSignal_0xF19D_0[1] =
{
    {
        0,
        46
    }
};
STATIC CONST(Dcm_DspDidSignalType, DCM_CONST) Dcm_DspDidSignal_0xF1C1_0[1] =
{
    {
        0,
        47
    }
};
STATIC CONST(Dcm_DspDidSignalType, DCM_CONST) Dcm_DspDidSignal_0xF1C2_0[1] =
{
    {
        0,
        48
    }
};
STATIC CONST(Dcm_DspDidSignalType, DCM_CONST) Dcm_DspDidSignal_0xF1C3_0[1] =
{
    {
        0,
        49
    }
};
STATIC CONST(Dcm_DspDidSignalType, DCM_CONST) Dcm_DspDidSignal_0xF1C6_0[1] =
{
    {
        0,
        50
    }
};
STATIC CONST(Dcm_DspDidSignalType, DCM_CONST) Dcm_DspDidSignal_0xF1C7_0[1] =
{
    {
        0,
        51
    }
};
STATIC CONST(Dcm_DspDidSignalType, DCM_CONST) Dcm_DspDidSignal_0xF1C8_0[1] =
{
    {
        0,
        52
    }
};
STATIC CONST(Dcm_DspDidSignalType, DCM_CONST) Dcm_DspDidSignal_0xF1C9_0[1] =
{
    {
        0,
        53
    }
};
STATIC CONST(Dcm_DspDidSignalType, DCM_CONST) Dcm_DspDidSignal_0xF1CA_0[1] =
{
    {
        0,
        54
    }
};
STATIC CONST(Dcm_DspDidSignalType, DCM_CONST) Dcm_DspDidSignal_0xF1CB_0[1] =
{
    {
        0,
        55
    }
};
STATIC CONST(Dcm_DspDidSignalType, DCM_CONST) Dcm_DspDidSignal_0xF1CC_0[1] =
{
    {
        0,
        56
    }
};
STATIC CONST(Dcm_DspDidSignalType, DCM_CONST) Dcm_DspDidSignal_0xF1CD_0[1] =
{
    {
        0,
        57
    }
};
STATIC CONST(Dcm_DspDidReadType, DCM_CONST) Dcm_DspDidRead_0x4F01_0 =
{
    DCM_REQ_PHY_MASK,
    DCM_LOCKED_MASK | DCM_L2_MASK,
    DCM_DEFAULT_MASK | DCM_EXTENDED_MASK
};
STATIC CONST(Dcm_DspDidReadType, DCM_CONST) Dcm_DspDidRead_0x4F02_0 =
{
    DCM_REQ_PHY_MASK,
    DCM_LOCKED_MASK | DCM_L2_MASK,
    DCM_DEFAULT_MASK | DCM_EXTENDED_MASK
};
STATIC CONST(Dcm_DspDidReadType, DCM_CONST) Dcm_DspDidRead_0x4F03_0 =
{
    DCM_REQ_PHY_MASK,
    DCM_LOCKED_MASK | DCM_L2_MASK,
    DCM_DEFAULT_MASK | DCM_EXTENDED_MASK
};
STATIC CONST(Dcm_DspDidReadType, DCM_CONST) Dcm_DspDidRead_0x4F04_0 =
{
    DCM_REQ_PHY_MASK,
    DCM_LOCKED_MASK | DCM_L2_MASK,
    DCM_DEFAULT_MASK | DCM_EXTENDED_MASK
};
STATIC CONST(Dcm_DspDidReadType, DCM_CONST) Dcm_DspDidRead_0x4F05_0 =
{
    DCM_REQ_PHY_MASK,
    DCM_LOCKED_MASK | DCM_L2_MASK,
    DCM_DEFAULT_MASK | DCM_EXTENDED_MASK
};
STATIC CONST(Dcm_DspDidReadType, DCM_CONST) Dcm_DspDidRead_0x4F30_0 =
{
    DCM_REQ_PHY_MASK,
    DCM_LOCKED_MASK | DCM_L2_MASK,
    DCM_DEFAULT_MASK | DCM_EXTENDED_MASK
};
STATIC CONST(Dcm_DspDidWriteType, DCM_CONST) Dcm_DspDidWrite_0x4F30_0 =
{
    DCM_REQ_PHY_MASK,
    DCM_L2_MASK,
    DCM_EXTENDED_MASK
};
STATIC CONST(Dcm_DspDidReadType, DCM_CONST) Dcm_DspDidRead_0x4F31_0 =
{
    DCM_REQ_PHY_MASK,
    DCM_LOCKED_MASK | DCM_L2_MASK | DCM_L9_MASK,
    DCM_DEFAULT_MASK | DCM_PROGRAMMING_MASK | DCM_EXTENDED_MASK
};
STATIC CONST(Dcm_DspDidWriteType, DCM_CONST) Dcm_DspDidWrite_0x4F31_0 =
{
    DCM_REQ_PHY_MASK,
    DCM_L2_MASK | DCM_L9_MASK,
    DCM_PROGRAMMING_MASK | DCM_EXTENDED_MASK
};
STATIC CONST(Dcm_DspDidReadType, DCM_CONST) Dcm_DspDidRead_0x4F32_0 =
{
    DCM_REQ_PHY_MASK,
    DCM_LOCKED_MASK | DCM_L2_MASK | DCM_L9_MASK,
    DCM_DEFAULT_MASK | DCM_PROGRAMMING_MASK | DCM_EXTENDED_MASK
};
STATIC CONST(Dcm_DspDidWriteType, DCM_CONST) Dcm_DspDidWrite_0x4F32_0 =
{
    DCM_REQ_PHY_MASK,
    DCM_L2_MASK | DCM_L9_MASK,
    DCM_PROGRAMMING_MASK | DCM_EXTENDED_MASK
};
STATIC CONST(Dcm_DspDidReadType, DCM_CONST) Dcm_DspDidRead_0x4F33_0 =
{
    DCM_REQ_PHY_MASK,
    DCM_LOCKED_MASK | DCM_L2_MASK,
    DCM_DEFAULT_MASK | DCM_EXTENDED_MASK
};
STATIC CONST(Dcm_DspDidReadType, DCM_CONST) Dcm_DspDidRead_0x4F34_0 =
{
    DCM_REQ_PHY_MASK,
    DCM_LOCKED_MASK | DCM_L2_MASK,
    DCM_DEFAULT_MASK | DCM_EXTENDED_MASK
};
STATIC CONST(Dcm_DspDidReadType, DCM_CONST) Dcm_DspDidRead_0x4F35_0 =
{
    DCM_REQ_PHY_MASK,
    DCM_LOCKED_MASK | DCM_L2_MASK,
    DCM_DEFAULT_MASK | DCM_EXTENDED_MASK
};
STATIC CONST(Dcm_DspDidReadType, DCM_CONST) Dcm_DspDidRead_0x4F36_0 =
{
    DCM_REQ_PHY_MASK,
    DCM_LOCKED_MASK | DCM_L2_MASK | DCM_L9_MASK,
    DCM_DEFAULT_MASK | DCM_PROGRAMMING_MASK | DCM_EXTENDED_MASK
};
STATIC CONST(Dcm_DspDidReadType, DCM_CONST) Dcm_DspDidRead_0x4F37_0 =
{
    DCM_REQ_PHY_MASK,
    DCM_LOCKED_MASK | DCM_L2_MASK | DCM_L9_MASK,
    DCM_DEFAULT_MASK | DCM_PROGRAMMING_MASK | DCM_EXTENDED_MASK
};
STATIC CONST(Dcm_DspDidReadType, DCM_CONST) Dcm_DspDidRead_0x4F38_0 =
{
    DCM_REQ_PHY_MASK,
    DCM_LOCKED_MASK | DCM_L2_MASK | DCM_L9_MASK,
    DCM_DEFAULT_MASK | DCM_PROGRAMMING_MASK | DCM_EXTENDED_MASK
};
STATIC CONST(Dcm_DspDidReadType, DCM_CONST) Dcm_DspDidRead_0x4F39_0 =
{
    DCM_REQ_PHY_MASK,
    DCM_LOCKED_MASK | DCM_L2_MASK,
    DCM_DEFAULT_MASK | DCM_EXTENDED_MASK
};
STATIC CONST(Dcm_DspDidReadType, DCM_CONST) Dcm_DspDidRead_0x4F3A_0 =
{
    DCM_REQ_PHY_MASK,
    DCM_LOCKED_MASK | DCM_L2_MASK,
    DCM_DEFAULT_MASK | DCM_EXTENDED_MASK
};
STATIC CONST(Dcm_DspDidReadType, DCM_CONST) Dcm_DspDidRead_0x4F3B_0 =
{
    DCM_REQ_PHY_MASK,
    DCM_LOCKED_MASK | DCM_L2_MASK,
    DCM_DEFAULT_MASK | DCM_EXTENDED_MASK
};
STATIC CONST(Dcm_DspDidReadType, DCM_CONST) Dcm_DspDidRead_0x4F3C_0 =
{
    DCM_REQ_PHY_MASK,
    DCM_LOCKED_MASK | DCM_L2_MASK,
    DCM_DEFAULT_MASK | DCM_EXTENDED_MASK
};
STATIC CONST(Dcm_DspDidReadType, DCM_CONST) Dcm_DspDidRead_0x4F3D_0 =
{
    DCM_REQ_PHY_MASK,
    DCM_LOCKED_MASK | DCM_L2_MASK,
    DCM_DEFAULT_MASK | DCM_EXTENDED_MASK
};
STATIC CONST(Dcm_DspDidReadType, DCM_CONST) Dcm_DspDidRead_0x4F3E_0 =
{
    DCM_REQ_PHY_MASK,
    DCM_LOCKED_MASK | DCM_L2_MASK,
    DCM_DEFAULT_MASK | DCM_EXTENDED_MASK
};
STATIC CONST(Dcm_DspDidReadType, DCM_CONST) Dcm_DspDidRead_0x4F3F_0 =
{
    DCM_REQ_PHY_MASK,
    DCM_LOCKED_MASK | DCM_L2_MASK,
    DCM_DEFAULT_MASK | DCM_EXTENDED_MASK
};
STATIC CONST(Dcm_DspDidReadType, DCM_CONST) Dcm_DspDidRead_0x4F40_0 =
{
    DCM_REQ_PHY_MASK,
    DCM_LOCKED_MASK | DCM_L2_MASK,
    DCM_DEFAULT_MASK | DCM_EXTENDED_MASK
};
STATIC CONST(Dcm_DspDidReadType, DCM_CONST) Dcm_DspDidRead_0x4F41_0 =
{
    DCM_REQ_PHY_MASK,
    DCM_LOCKED_MASK | DCM_L2_MASK,
    DCM_DEFAULT_MASK | DCM_EXTENDED_MASK
};
STATIC CONST(Dcm_DspDidReadType, DCM_CONST) Dcm_DspDidRead_0x4F42_0 =
{
    DCM_REQ_PHY_MASK,
    DCM_LOCKED_MASK | DCM_L2_MASK,
    DCM_DEFAULT_MASK | DCM_EXTENDED_MASK
};
STATIC CONST(Dcm_DspDidReadType, DCM_CONST) Dcm_DspDidRead_0x4F43_0 =
{
    DCM_REQ_PHY_MASK,
    DCM_LOCKED_MASK | DCM_L2_MASK,
    DCM_DEFAULT_MASK | DCM_EXTENDED_MASK
};
STATIC CONST(Dcm_DspDidReadType, DCM_CONST) Dcm_DspDidRead_0x4F44_0 =
{
    DCM_REQ_PHY_MASK,
    DCM_LOCKED_MASK | DCM_L2_MASK,
    DCM_DEFAULT_MASK | DCM_EXTENDED_MASK
};
STATIC CONST(Dcm_DspDidReadType, DCM_CONST) Dcm_DspDidRead_0x4F45_0 =
{
    DCM_REQ_PHY_MASK,
    DCM_LOCKED_MASK | DCM_L2_MASK,
    DCM_DEFAULT_MASK | DCM_EXTENDED_MASK
};
STATIC CONST(Dcm_DspDidReadType, DCM_CONST) Dcm_DspDidRead_0x4F46_0 =
{
    DCM_REQ_PHY_MASK,
    DCM_LOCKED_MASK | DCM_L2_MASK,
    DCM_DEFAULT_MASK | DCM_EXTENDED_MASK
};
STATIC CONST(Dcm_DspDidReadType, DCM_CONST) Dcm_DspDidRead_0x4F48_0 =
{
    DCM_REQ_PHY_MASK,
    DCM_LOCKED_MASK | DCM_L2_MASK,
    DCM_DEFAULT_MASK | DCM_EXTENDED_MASK
};
STATIC CONST(Dcm_DspDidReadType, DCM_CONST) Dcm_DspDidRead_0x4F4A_0 =
{
    DCM_REQ_PHY_MASK,
    DCM_LOCKED_MASK | DCM_L2_MASK,
    DCM_DEFAULT_MASK | DCM_EXTENDED_MASK
};
STATIC CONST(Dcm_DspDidWriteType, DCM_CONST) Dcm_DspDidWrite_0x4F4A_0 =
{
    DCM_REQ_PHY_MASK,
    DCM_L2_MASK,
    DCM_EXTENDED_MASK
};
STATIC CONST(Dcm_DspDidReadType, DCM_CONST) Dcm_DspDidRead_0x4F4B_0 =
{
    DCM_REQ_PHY_MASK,
    DCM_LOCKED_MASK | DCM_L2_MASK,
    DCM_DEFAULT_MASK | DCM_EXTENDED_MASK
};
STATIC CONST(Dcm_DspDidReadType, DCM_CONST) Dcm_DspDidRead_0x4F4C_0 =
{
    DCM_REQ_PHY_MASK,
    DCM_LOCKED_MASK | DCM_L2_MASK,
    DCM_DEFAULT_MASK | DCM_EXTENDED_MASK
};
STATIC CONST(Dcm_DspDidWriteType, DCM_CONST) Dcm_DspDidWrite_0x4F4C_0 =
{
    DCM_REQ_PHY_MASK,
    DCM_L2_MASK,
    DCM_EXTENDED_MASK
};
STATIC CONST(Dcm_DspDidReadType, DCM_CONST) Dcm_DspDidRead_0x4F4D_0 =
{
    DCM_REQ_PHY_MASK,
    DCM_LOCKED_MASK | DCM_L2_MASK,
    DCM_DEFAULT_MASK | DCM_EXTENDED_MASK
};
STATIC CONST(Dcm_DspDidWriteType, DCM_CONST) Dcm_DspDidWrite_0x4F4D_0 =
{
    DCM_REQ_PHY_MASK,
    DCM_L2_MASK,
    DCM_EXTENDED_MASK
};
STATIC CONST(Dcm_DspDidReadType, DCM_CONST) Dcm_DspDidRead_0xF112_0 =
{
    DCM_REQ_PHY_MASK,
    DCM_LOCKED_MASK | DCM_L2_MASK | DCM_L9_MASK,
    DCM_DEFAULT_MASK | DCM_PROGRAMMING_MASK | DCM_EXTENDED_MASK
};
STATIC CONST(Dcm_DspDidReadType, DCM_CONST) Dcm_DspDidRead_0xF15A_0 =
{
    DCM_REQ_PHY_MASK,
    DCM_LOCKED_MASK | DCM_L2_MASK | DCM_L9_MASK,
    DCM_DEFAULT_MASK | DCM_PROGRAMMING_MASK | DCM_EXTENDED_MASK
};
STATIC CONST(Dcm_DspDidReadType, DCM_CONST) Dcm_DspDidRead_0xF180_0 =
{
    DCM_REQ_PHY_MASK,
    DCM_LOCKED_MASK | DCM_L2_MASK | DCM_L9_MASK,
    DCM_DEFAULT_MASK | DCM_PROGRAMMING_MASK | DCM_EXTENDED_MASK
};
STATIC CONST(Dcm_DspDidReadType, DCM_CONST) Dcm_DspDidRead_0xF186_0 =
{
    DCM_REQ_PHY_MASK,
    DCM_LOCKED_MASK | DCM_L2_MASK | DCM_L9_MASK,
    DCM_DEFAULT_MASK | DCM_PROGRAMMING_MASK | DCM_EXTENDED_MASK
};
STATIC CONST(Dcm_DspDidReadType, DCM_CONST) Dcm_DspDidRead_0xF187_0 =
{
    DCM_REQ_PHY_MASK,
    DCM_LOCKED_MASK | DCM_L2_MASK,
    DCM_DEFAULT_MASK | DCM_EXTENDED_MASK
};
STATIC CONST(Dcm_DspDidReadType, DCM_CONST) Dcm_DspDidRead_0xF18A_0 =
{
    DCM_REQ_PHY_MASK,
    DCM_LOCKED_MASK | DCM_L2_MASK,
    DCM_DEFAULT_MASK | DCM_EXTENDED_MASK
};
STATIC CONST(Dcm_DspDidReadType, DCM_CONST) Dcm_DspDidRead_0xF18C_0 =
{
    DCM_REQ_PHY_MASK,
    DCM_LOCKED_MASK | DCM_L2_MASK,
    DCM_DEFAULT_MASK | DCM_EXTENDED_MASK
};
STATIC CONST(Dcm_DspDidReadType, DCM_CONST) Dcm_DspDidRead_0xF190_0 =
{
    DCM_REQ_PHY_MASK,
    DCM_LOCKED_MASK | DCM_L2_MASK,
    DCM_DEFAULT_MASK | DCM_EXTENDED_MASK
};
STATIC CONST(Dcm_DspDidWriteType, DCM_CONST) Dcm_DspDidWrite_0xF190_0 =
{
    DCM_REQ_PHY_MASK,
    DCM_L2_MASK,
    DCM_EXTENDED_MASK
};
STATIC CONST(Dcm_DspDidReadType, DCM_CONST) Dcm_DspDidRead_0xF192_0 =
{
    DCM_REQ_PHY_MASK,
    DCM_LOCKED_MASK | DCM_L2_MASK,
    DCM_DEFAULT_MASK | DCM_EXTENDED_MASK
};
STATIC CONST(Dcm_DspDidReadType, DCM_CONST) Dcm_DspDidRead_0xF193_0 =
{
    DCM_REQ_PHY_MASK,
    DCM_LOCKED_MASK | DCM_L2_MASK,
    DCM_DEFAULT_MASK | DCM_EXTENDED_MASK
};
STATIC CONST(Dcm_DspDidReadType, DCM_CONST) Dcm_DspDidRead_0xF195_0 =
{
    DCM_REQ_PHY_MASK,
    DCM_LOCKED_MASK | DCM_L2_MASK,
    DCM_DEFAULT_MASK | DCM_EXTENDED_MASK
};
STATIC CONST(Dcm_DspDidReadType, DCM_CONST) Dcm_DspDidRead_0xF198_0 =
{
    DCM_REQ_PHY_MASK,
    DCM_LOCKED_MASK | DCM_L2_MASK,
    DCM_DEFAULT_MASK | DCM_EXTENDED_MASK
};
STATIC CONST(Dcm_DspDidWriteType, DCM_CONST) Dcm_DspDidWrite_0xF198_0 =
{
    DCM_REQ_PHY_MASK,
    DCM_L2_MASK,
    DCM_EXTENDED_MASK
};
STATIC CONST(Dcm_DspDidReadType, DCM_CONST) Dcm_DspDidRead_0xF199_0 =
{
    DCM_REQ_PHY_MASK,
    DCM_LOCKED_MASK | DCM_L2_MASK,
    DCM_DEFAULT_MASK | DCM_EXTENDED_MASK
};
STATIC CONST(Dcm_DspDidReadType, DCM_CONST) Dcm_DspDidRead_0xF19D_0 =
{
    DCM_REQ_PHY_MASK|DCM_REQ_FUN_MASK,
    DCM_LOCKED_MASK | DCM_L2_MASK | DCM_L9_MASK,
    DCM_DEFAULT_MASK | DCM_PROGRAMMING_MASK | DCM_EXTENDED_MASK
};
STATIC CONST(Dcm_DspDidReadType, DCM_CONST) Dcm_DspDidRead_0xF1C1_0 =
{
    DCM_REQ_PHY_MASK,
    DCM_LOCKED_MASK | DCM_L2_MASK,
    DCM_DEFAULT_MASK | DCM_EXTENDED_MASK
};
STATIC CONST(Dcm_DspDidReadType, DCM_CONST) Dcm_DspDidRead_0xF1C2_0 =
{
    DCM_REQ_PHY_MASK,
    DCM_LOCKED_MASK | DCM_L2_MASK,
    DCM_DEFAULT_MASK | DCM_EXTENDED_MASK
};
STATIC CONST(Dcm_DspDidWriteType, DCM_CONST) Dcm_DspDidWrite_0xF1C2_0 =
{
    DCM_REQ_PHY_MASK,
    DCM_L2_MASK,
    DCM_EXTENDED_MASK
};
STATIC CONST(Dcm_DspDidReadType, DCM_CONST) Dcm_DspDidRead_0xF1C3_0 =
{
    DCM_REQ_PHY_MASK,
    DCM_LOCKED_MASK | DCM_L2_MASK,
    DCM_DEFAULT_MASK | DCM_EXTENDED_MASK
};
STATIC CONST(Dcm_DspDidWriteType, DCM_CONST) Dcm_DspDidWrite_0xF1C3_0 =
{
    DCM_REQ_PHY_MASK,
    DCM_L2_MASK,
    DCM_EXTENDED_MASK
};
STATIC CONST(Dcm_DspDidReadType, DCM_CONST) Dcm_DspDidRead_0xF1C6_0 =
{
    DCM_REQ_PHY_MASK,
    DCM_LOCKED_MASK | DCM_L2_MASK,
    DCM_DEFAULT_MASK | DCM_EXTENDED_MASK
};
STATIC CONST(Dcm_DspDidReadType, DCM_CONST) Dcm_DspDidRead_0xF1C7_0 =
{
    DCM_REQ_PHY_MASK,
    DCM_LOCKED_MASK | DCM_L2_MASK,
    DCM_DEFAULT_MASK | DCM_EXTENDED_MASK
};
STATIC CONST(Dcm_DspDidReadType, DCM_CONST) Dcm_DspDidRead_0xF1C8_0 =
{
    DCM_REQ_PHY_MASK,
    DCM_LOCKED_MASK | DCM_L2_MASK,
    DCM_DEFAULT_MASK | DCM_EXTENDED_MASK
};
STATIC CONST(Dcm_DspDidWriteType, DCM_CONST) Dcm_DspDidWrite_0xF1C8_0 =
{
    DCM_REQ_PHY_MASK,
    DCM_L2_MASK,
    DCM_EXTENDED_MASK
};
STATIC CONST(Dcm_DspDidReadType, DCM_CONST) Dcm_DspDidRead_0xF1C9_0 =
{
    DCM_REQ_PHY_MASK,
    DCM_LOCKED_MASK | DCM_L2_MASK,
    DCM_DEFAULT_MASK | DCM_EXTENDED_MASK
};
STATIC CONST(Dcm_DspDidReadType, DCM_CONST) Dcm_DspDidRead_0xF1CA_0 =
{
    DCM_REQ_PHY_MASK,
    DCM_LOCKED_MASK | DCM_L2_MASK,
    DCM_DEFAULT_MASK | DCM_EXTENDED_MASK
};
STATIC CONST(Dcm_DspDidReadType, DCM_CONST) Dcm_DspDidRead_0xF1CB_0 =
{
    DCM_REQ_PHY_MASK,
    DCM_LOCKED_MASK | DCM_L2_MASK,
    DCM_DEFAULT_MASK | DCM_EXTENDED_MASK
};
STATIC CONST(Dcm_DspDidWriteType, DCM_CONST) Dcm_DspDidWrite_0xF1CB_0 =
{
    DCM_REQ_PHY_MASK,
    DCM_L2_MASK,
    DCM_EXTENDED_MASK
};
STATIC CONST(Dcm_DspDidReadType, DCM_CONST) Dcm_DspDidRead_0xF1CC_0 =
{
    DCM_REQ_PHY_MASK,
    DCM_LOCKED_MASK | DCM_L2_MASK,
    DCM_DEFAULT_MASK | DCM_EXTENDED_MASK
};
STATIC CONST(Dcm_DspDidReadType, DCM_CONST) Dcm_DspDidRead_0xF1CD_0 =
{
    DCM_REQ_PHY_MASK,
    DCM_LOCKED_MASK | DCM_L2_MASK,
    DCM_DEFAULT_MASK | DCM_EXTENDED_MASK
};
STATIC CONST(Dcm_DspDidTableType, DCM_CONST) Dcm_DspDidTable_0[58] =
{
    {/*0*/
        0x4F01,
        TRUE,
        {
            &Dcm_DspDidRead_0x4F01_0,
            NULL_PTR
        },
        1,
        Dcm_DspDidSignal_0x4F01_0
    },
    {/*1*/
        0x4F02,
        TRUE,
        {
            &Dcm_DspDidRead_0x4F02_0,
            NULL_PTR
        },
        1,
        Dcm_DspDidSignal_0x4F02_0
    },
    {/*2*/
        0x4F03,
        TRUE,
        {
            &Dcm_DspDidRead_0x4F03_0,
            NULL_PTR
        },
        1,
        Dcm_DspDidSignal_0x4F03_0
    },
    {/*3*/
        0x4F04,
        TRUE,
        {
            &Dcm_DspDidRead_0x4F04_0,
            NULL_PTR
        },
        1,
        Dcm_DspDidSignal_0x4F04_0
    },
    {/*4*/
        0x4F05,
        TRUE,
        {
            &Dcm_DspDidRead_0x4F05_0,
            NULL_PTR
        },
        1,
        Dcm_DspDidSignal_0x4F05_0
    },
    {/*5*/
        0x4F30,
        TRUE,
        {
            &Dcm_DspDidRead_0x4F30_0,
            &Dcm_DspDidWrite_0x4F30_0
        },
        1,
        Dcm_DspDidSignal_0x4F30_0
    },
    {/*6*/
        0x4F31,
        TRUE,
        {
            &Dcm_DspDidRead_0x4F31_0,
            &Dcm_DspDidWrite_0x4F31_0
        },
        1,
        Dcm_DspDidSignal_0x4F31_0
    },
    {/*7*/
        0x4F32,
        TRUE,
        {
            &Dcm_DspDidRead_0x4F32_0,
            &Dcm_DspDidWrite_0x4F32_0
        },
        1,
        Dcm_DspDidSignal_0x4F32_0
    },
    {/*8*/
        0x4F33,
        TRUE,
        {
            &Dcm_DspDidRead_0x4F33_0,
            NULL_PTR
        },
        1,
        Dcm_DspDidSignal_0x4F33_0
    },
    {/*9*/
        0x4F34,
        TRUE,
        {
            &Dcm_DspDidRead_0x4F34_0,
            NULL_PTR
        },
        1,
        Dcm_DspDidSignal_0x4F34_0
    },
    {/*10*/
        0x4F35,
        TRUE,
        {
            &Dcm_DspDidRead_0x4F35_0,
            NULL_PTR
        },
        1,
        Dcm_DspDidSignal_0x4F35_0
    },
    {/*11*/
        0x4F36,
        TRUE,
        {
            &Dcm_DspDidRead_0x4F36_0,
            NULL_PTR
        },
        1,
        Dcm_DspDidSignal_0x4F36_0
    },
    {/*12*/
        0x4F37,
        TRUE,
        {
            &Dcm_DspDidRead_0x4F37_0,
            NULL_PTR
        },
        1,
        Dcm_DspDidSignal_0x4F37_0
    },
    {/*13*/
        0x4F38,
        TRUE,
        {
            &Dcm_DspDidRead_0x4F38_0,
            NULL_PTR
        },
        1,
        Dcm_DspDidSignal_0x4F38_0
    },
    {/*14*/
        0x4F39,
        TRUE,
        {
            &Dcm_DspDidRead_0x4F39_0,
            NULL_PTR
        },
        1,
        Dcm_DspDidSignal_0x4F39_0
    },
    {/*15*/
        0x4F3A,
        TRUE,
        {
            &Dcm_DspDidRead_0x4F3A_0,
            NULL_PTR
        },
        1,
        Dcm_DspDidSignal_0x4F3A_0
    },
    {/*16*/
        0x4F3B,
        TRUE,
        {
            &Dcm_DspDidRead_0x4F3B_0,
            NULL_PTR
        },
        1,
        Dcm_DspDidSignal_0x4F3B_0
    },
    {/*17*/
        0x4F3C,
        TRUE,
        {
            &Dcm_DspDidRead_0x4F3C_0,
            NULL_PTR
        },
        1,
        Dcm_DspDidSignal_0x4F3C_0
    },
    {/*18*/
        0x4F3D,
        TRUE,
        {
            &Dcm_DspDidRead_0x4F3D_0,
            NULL_PTR
        },
        1,
        Dcm_DspDidSignal_0x4F3D_0
    },
    {/*19*/
        0x4F3E,
        TRUE,
        {
            &Dcm_DspDidRead_0x4F3E_0,
            NULL_PTR
        },
        1,
        Dcm_DspDidSignal_0x4F3E_0
    },
    {/*20*/
        0x4F3F,
        TRUE,
        {
            &Dcm_DspDidRead_0x4F3F_0,
            NULL_PTR
        },
        1,
        Dcm_DspDidSignal_0x4F3F_0
    },
    {/*21*/
        0x4F40,
        TRUE,
        {
            &Dcm_DspDidRead_0x4F40_0,
            NULL_PTR
        },
        1,
        Dcm_DspDidSignal_0x4F40_0
    },
    {/*22*/
        0x4F41,
        TRUE,
        {
            &Dcm_DspDidRead_0x4F41_0,
            NULL_PTR
        },
        1,
        Dcm_DspDidSignal_0x4F41_0
    },
    {/*23*/
        0x4F42,
        TRUE,
        {
            &Dcm_DspDidRead_0x4F42_0,
            NULL_PTR
        },
        1,
        Dcm_DspDidSignal_0x4F42_0
    },
    {/*24*/
        0x4F43,
        TRUE,
        {
            &Dcm_DspDidRead_0x4F43_0,
            NULL_PTR
        },
        1,
        Dcm_DspDidSignal_0x4F43_0
    },
    {/*25*/
        0x4F44,
        TRUE,
        {
            &Dcm_DspDidRead_0x4F44_0,
            NULL_PTR
        },
        1,
        Dcm_DspDidSignal_0x4F44_0
    },
    {/*26*/
        0x4F45,
        TRUE,
        {
            &Dcm_DspDidRead_0x4F45_0,
            NULL_PTR
        },
        1,
        Dcm_DspDidSignal_0x4F45_0
    },
    {/*27*/
        0x4F46,
        TRUE,
        {
            &Dcm_DspDidRead_0x4F46_0,
            NULL_PTR
        },
        1,
        Dcm_DspDidSignal_0x4F46_0
    },
    {/*28*/
        0x4F48,
        TRUE,
        {
            &Dcm_DspDidRead_0x4F48_0,
            NULL_PTR
        },
        1,
        Dcm_DspDidSignal_0x4F48_0
    },
    {/*29*/
        0x4F4A,
        TRUE,
        {
            &Dcm_DspDidRead_0x4F4A_0,
            &Dcm_DspDidWrite_0x4F4A_0
        },
        1,
        Dcm_DspDidSignal_0x4F4A_0
    },
    {/*30*/
        0x4F4B,
        TRUE,
        {
            &Dcm_DspDidRead_0x4F4B_0,
            NULL_PTR
        },
        1,
        Dcm_DspDidSignal_0x4F4B_0
    },
    {/*31*/
        0x4F4C,
        TRUE,
        {
            &Dcm_DspDidRead_0x4F4C_0,
            &Dcm_DspDidWrite_0x4F4C_0
        },
        1,
        Dcm_DspDidSignal_0x4F4C_0
    },
    {/*32*/
        0x4F4D,
        TRUE,
        {
            &Dcm_DspDidRead_0x4F4D_0,
            &Dcm_DspDidWrite_0x4F4D_0
        },
        1,
        Dcm_DspDidSignal_0x4F4D_0
    },
    {/*33*/
        0xF112,
        TRUE,
        {
            &Dcm_DspDidRead_0xF112_0,
            NULL_PTR
        },
        1,
        Dcm_DspDidSignal_0xF112_0
    },
    {/*34*/
        0xF15A,
        TRUE,
        {
            &Dcm_DspDidRead_0xF15A_0,
            NULL_PTR
        },
        1,
        Dcm_DspDidSignal_0xF15A_0
    },
    {/*35*/
        0xF180,
        TRUE,
        {
            &Dcm_DspDidRead_0xF180_0,
            NULL_PTR
        },
        1,
        Dcm_DspDidSignal_0xF180_0
    },
    {/*36*/
        0xF186,
        TRUE,
        {
            &Dcm_DspDidRead_0xF186_0,
            NULL_PTR
        },
        1,
        Dcm_DspDidSignal_0xF186_0
    },
    {/*37*/
        0xF187,
        TRUE,
        {
            &Dcm_DspDidRead_0xF187_0,
            NULL_PTR
        },
        1,
        Dcm_DspDidSignal_0xF187_0
    },
    {/*38*/
        0xF18A,
        TRUE,
        {
            &Dcm_DspDidRead_0xF18A_0,
            NULL_PTR
        },
        1,
        Dcm_DspDidSignal_0xF18A_0
    },
    {/*39*/
        0xF18C,
        TRUE,
        {
            &Dcm_DspDidRead_0xF18C_0,
            NULL_PTR
        },
        1,
        Dcm_DspDidSignal_0xF18C_0
    },
    {/*40*/
        0xF190,
        TRUE,
        {
            &Dcm_DspDidRead_0xF190_0,
            &Dcm_DspDidWrite_0xF190_0
        },
        1,
        Dcm_DspDidSignal_0xF190_0
    },
    {/*41*/
        0xF192,
        TRUE,
        {
            &Dcm_DspDidRead_0xF192_0,
            NULL_PTR
        },
        1,
        Dcm_DspDidSignal_0xF192_0
    },
    {/*42*/
        0xF193,
        TRUE,
        {
            &Dcm_DspDidRead_0xF193_0,
            NULL_PTR
        },
        1,
        Dcm_DspDidSignal_0xF193_0
    },
    {/*43*/
        0xF195,
        TRUE,
        {
            &Dcm_DspDidRead_0xF195_0,
            NULL_PTR
        },
        1,
        Dcm_DspDidSignal_0xF195_0
    },
    {/*44*/
        0xF198,
        TRUE,
        {
            &Dcm_DspDidRead_0xF198_0,
            &Dcm_DspDidWrite_0xF198_0
        },
        1,
        Dcm_DspDidSignal_0xF198_0
    },
    {/*45*/
        0xF199,
        TRUE,
        {
            &Dcm_DspDidRead_0xF199_0,
            NULL_PTR
        },
        1,
        Dcm_DspDidSignal_0xF199_0
    },
    {/*46*/
        0xF19D,
        TRUE,
        {
            &Dcm_DspDidRead_0xF19D_0,
            NULL_PTR
        },
        1,
        Dcm_DspDidSignal_0xF19D_0
    },
    {/*47*/
        0xF1C1,
        TRUE,
        {
            &Dcm_DspDidRead_0xF1C1_0,
            NULL_PTR
        },
        1,
        Dcm_DspDidSignal_0xF1C1_0
    },
    {/*48*/
        0xF1C2,
        TRUE,
        {
            &Dcm_DspDidRead_0xF1C2_0,
            &Dcm_DspDidWrite_0xF1C2_0
        },
        1,
        Dcm_DspDidSignal_0xF1C2_0
    },
    {/*49*/
        0xF1C3,
        TRUE,
        {
            &Dcm_DspDidRead_0xF1C3_0,
            &Dcm_DspDidWrite_0xF1C3_0
        },
        1,
        Dcm_DspDidSignal_0xF1C3_0
    },
    {/*50*/
        0xF1C6,
        TRUE,
        {
            &Dcm_DspDidRead_0xF1C6_0,
            NULL_PTR
        },
        1,
        Dcm_DspDidSignal_0xF1C6_0
    },
    {/*51*/
        0xF1C7,
        TRUE,
        {
            &Dcm_DspDidRead_0xF1C7_0,
            NULL_PTR
        },
        1,
        Dcm_DspDidSignal_0xF1C7_0
    },
    {/*52*/
        0xF1C8,
        TRUE,
        {
            &Dcm_DspDidRead_0xF1C8_0,
            &Dcm_DspDidWrite_0xF1C8_0
        },
        1,
        Dcm_DspDidSignal_0xF1C8_0
    },
    {/*53*/
        0xF1C9,
        TRUE,
        {
            &Dcm_DspDidRead_0xF1C9_0,
            NULL_PTR
        },
        1,
        Dcm_DspDidSignal_0xF1C9_0
    },
    {/*54*/
        0xF1CA,
        TRUE,
        {
            &Dcm_DspDidRead_0xF1CA_0,
            NULL_PTR
        },
        1,
        Dcm_DspDidSignal_0xF1CA_0
    },
    {/*55*/
        0xF1CB,
        TRUE,
        {
            &Dcm_DspDidRead_0xF1CB_0,
            &Dcm_DspDidWrite_0xF1CB_0
        },
        1,
        Dcm_DspDidSignal_0xF1CB_0
    },
    {/*56*/
        0xF1CC,
        TRUE,
        {
            &Dcm_DspDidRead_0xF1CC_0,
            NULL_PTR
        },
        1,
        Dcm_DspDidSignal_0xF1CC_0
    },
    {/*57*/
        0xF1CD,
        TRUE,
        {
            &Dcm_DspDidRead_0xF1CD_0,
            NULL_PTR
        },
        1,
        Dcm_DspDidSignal_0xF1CD_0
    }
};
CONST(Dcm_DspDidType, DCM_CONST) Dcm_DspDid[DCM_CFG_NUM_OF_PROTOCOL] =
{
    {
        58,
        Dcm_DspDidTable_0
    }
};
STATIC CONST(Dcm_DspCommonAuthorizationType, DCM_CONST) Dcm_DspCommonAuthorization_0[1] =
{
    {
        DCM_REQ_PHY_MASK,
        DCM_L2_MASK,
        DCM_EXTENDED_MASK
    },
};
STATIC CONST(Dcm_DspStartRoutineType, DCM_CONST) Dcm_DspStartRoutine_0xFF02_0 =
{
    0,
    &(Dcm_DspCommonAuthorization_0[0]),
    {
        DCM_OPAQUE,
        0,
        0,
        DCM_UINT8
    },
    {
        DCM_OPAQUE,
        1,
        0,
        DCM_UINT8
    },
};


STATIC CONST(Dcm_DspRoutineIdInfoType, DCM_CONST) Dcm_DspRoutineIdInfo_0[1] =
{
    {
        0xFF02,
        TRUE,
        TRUE,
        &Dcm_DspStartRoutine_0xFF02_0,
        NULL_PTR,
        NULL_PTR
    }
};

STATIC CONST(EcucFncRoutineStartStopDefA, DCM_CONST) Dcm_DspRoutineStartFncA_0[1U] =
{
    Dcm_Rte_RoutineServices_0xFF02_Start
};
CONST(Dcm_DspRoutineType, DCM_CONST) Dcm_DspRoutine[DCM_CFG_NUM_OF_PROTOCOL] =
{
    {
        1,
        Dcm_DspRoutineIdInfo_0,
        Dcm_DspRoutineStartFncA_0,
        NULL_PTR,
        NULL_PTR,
        NULL_PTR,
        NULL_PTR,
        NULL_PTR,
        NULL_PTR,
        NULL_PTR,
        NULL_PTR,
        NULL_PTR,
    }
};

#define DCM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"


