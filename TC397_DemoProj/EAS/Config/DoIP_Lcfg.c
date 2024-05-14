/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : DoIP_Lcfg.c
********************************************************************************
*   Project/Product : AUTOSAR BSW PROJECT
*   Title           : DoIP module configuration File
*   Author          : Hirain
********************************************************************************
*   Description     : DoIP module configuration File
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
/******************************************************************************
*   General QAC Suppression
******************************************************************************/
/*PRQA S 3214,3614,862 EOF*/
/* According to the requirements of AUTOSAR Specification,when locating address segments in the files of each module,
 * #include "MemMap.h" is required.Defined XXX_START_SEC_ will undefine in MemMap.h */

/*PRQA S 3132 EOF*/
/* Particularity of configuration files */


/*******************************************************************************
*   Include files
*******************************************************************************/
#include "Rte_DoIP.h"
#include "SchM_DoIP.h"
#include "DoIP_Lcfg.h"
#include "SoAd.h"
#include "DoIP_Cfg.h"

#define DOIP_START_SEC_CONFIG_DATA_8
#include "MemMap.h"

/* DoIPEID */
CONST(uint8, DOIP_CONST) DoIP_EID[6] =
{
    (uint8)0,
    (uint8)1,
    (uint8)2,
    (uint8)3,
    (uint8)4,
    (uint8)5
};


/* DoIPRoutingActivations */
STATIC CONST(uint8, DOIP_CONST) DoIP_RoutingActivationTargetAddrList0[2] =
{
    (uint8)0,
    (uint8)1
};

/* DoIPTester */
STATIC CONST(uint8, DOIP_CONST) DoIP_TesterRoutingActivationGroup0[1] =
{
    (uint8)0
};

#define DOIP_STOP_SEC_CONFIG_DATA_8
#include "MemMap.h"

#define DOIP_START_SEC_CONFIG_DATA_16
#include "MemMap.h"

/* DoIPTargetAddr */
STATIC CONST(DoIP_LogicAddrType, DOIP_CONST) DoIP_TargetAddr[2] =
{
    (DoIP_LogicAddrType)0x2,
    (DoIP_LogicAddrType)0xE40
};

#define DOIP_STOP_SEC_CONFIG_DATA_16
#include "MemMap.h"

#define DOIP_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"

/* DoIPUdpConnections */
STATIC CONST(DoIP_ConType, DOIP_CONST) DoIP_UdpCons[1] =
{
    {
        (SoAd_SoConIdType)0,
        (PduIdType)SoAd_DoIP_DoIPDefaultConfig_DoIP_To_SoAd_UDP,
        (PduIdType)SoAd_DoIP_DoIPDefaultConfig_SoAd_To_DoIP_UDP
    }
};

/* DoIPTcpConnectionList */
STATIC CONST(DoIP_ConType, DOIP_CONST) DoIP_TcpCons[3] =
{
    {
        (SoAd_SoConIdType)1,
        (PduIdType)SoAd_DoIP_DoIPDefaultConfig_DoIP_To_SoAd_TCP0,
        (PduIdType)SoAd_DoIP_DoIPDefaultConfig_SoAd_To_DoIP_TCP0
    },
    {
        (SoAd_SoConIdType)2,
        (PduIdType)SoAd_DoIP_DoIPDefaultConfig_DoIP_To_SoAd_TCP1,
        (PduIdType)SoAd_DoIP_DoIPDefaultConfig_SoAd_To_DoIP_TCP1
    },
    {
        (SoAd_SoConIdType)3,
        (PduIdType)SoAd_DoIP_DoIPDefaultConfig_DoIP_To_SoAd_TCP2,
        (PduIdType)SoAd_DoIP_DoIPDefaultConfig_SoAd_To_DoIP_TCP2
    }
};

/* DoIPRoutingActivations */
STATIC CONST(DoIP_RoutingActivationType, DOIP_CONST) DoIP_RoutingActivations[1] =
{
    {
        (uint8)0,/* Action type */
        (uint8)2,/* Target address number */
        (const uint8 *)DoIP_RoutingActivationTargetAddrList0,
        (uint8)0,
        (uint8)0,
        NULL_PTR,
        (uint8)0,
        (uint8)0,
        NULL_PTR
    }
};

/* DoIPTester */
STATIC CONST(DoIP_TesterType, DOIP_CONST) DoIP_Testers[1] =
{
    {
        (uint32)1,
        (DoIP_LogicAddrType)0x1,
        (uint8)1,
        DoIP_TesterRoutingActivationGroup0
    }
};

/* DoIPChannel */
STATIC CONST(DoIP_ChannelType, DOIP_CONST) DoIP_Channels[2] =
{
    {
        (DoIP_LogicAddrType)0x1,
        (DoIP_LogicAddrType)0x2,
        (PduIdType)PduR_DoIP_DoIPDefaultConfig_DoIP_To_Dcm_Phy,
        (PduIdType)PduR_DoIP_DoIPDefaultConfig_Dcm_To_DoIP,
        DOIP_TPPDU,
        (uint8)0xFF
    },
    {
        (DoIP_LogicAddrType)0x1,
        (DoIP_LogicAddrType)0xE40,
        (PduIdType)PduR_DoIP_DoIPDefaultConfig_DoIP_To_Dcm_Fun,
        (PduIdType)PduR_DoIP_DoIPDefaultConfig_Dcm_To_DoIP,
        DOIP_TPPDU,
        (uint8)0xFF
    }
};


/*PRQA S 3211 ++*/
/* DoIP_Config is not used in DoIP_Lcfg.c*/
CONST(DoIP_ConfigType, DOIP_CONST) DoIP_Config =
{
    DoIP_EID,
    NULL_PTR,
    (uint8)DOIP_TESTER_NUM,
    (uint8)DOIP_ROUTING_ACTIVATION_NUM,
    (DoIP_LogicAddrType)0x2,
    DoIP_TargetAddr,
    DoIP_UdpCons,
    DoIP_TcpCons,
    &DoIP_Channels[0],
    &DoIP_Testers[0],
    &DoIP_RoutingActivations[0],
    (DoIP_GetGidCallbackType)NULL_PTR,
    (DoIP_PowerModeCallbackType)&Rte_Call_DoIP_CBGetPowerMode_GetPowerMode,
    (DoIP_TriggerGidSyncCbkType) NULL_PTR
};
/*PRQA S 3211 --*/
#define DOIP_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"

