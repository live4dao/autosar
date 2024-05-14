/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : Rte_Dcm_Type.h
********************************************************************************
*   Project/Product : AUTOSAR BSW PROJECT
*   Title           : Rte module configuration File
*   Author          : Hirain
********************************************************************************
*   Description     : Rte module configuration File
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
#ifndef RTE_DCM_TYPE_H
#define RTE_DCM_TYPE_H
#include "Rte_Type.h"
/*******************************************************************************
* Macros and Typedef
*******************************************************************************/
/*Sub Service Id*/
#define DCM_DEFAULT_SESSION                                 (uint8)0x01
#define DCM_PROGRAMMING_SESSION                             (uint8)0x02
#define DCM_EXTENDED_SESSION                                (uint8)0x03


/*******************************************************************************
* Mode Type Definition
*******************************************************************************/
#ifndef RTE_MODETYPE_DcmCommunicationControl_ComM_CanCtrl_0
#define RTE_MODETYPE_DcmCommunicationControl_ComM_CanCtrl_0
typedef uint8 Rte_ModeType_DcmCommunicationControl_ComM_CanCtrl_0;
#endif
#ifndef RTE_MODE_DcmCommunicationControl_ComM_CanCtrl_0_DCM_ENABLE_RX_TX_NORM
#define RTE_MODE_DcmCommunicationControl_ComM_CanCtrl_0_DCM_ENABLE_RX_TX_NORM   0U
#endif
#ifndef RTE_MODE_DcmCommunicationControl_ComM_CanCtrl_0_DCM_ENABLE_RX_DISABLE_TX_NORM
#define RTE_MODE_DcmCommunicationControl_ComM_CanCtrl_0_DCM_ENABLE_RX_DISABLE_TX_NORM     1U
#endif
#ifndef RTE_MODE_DcmCommunicationControl_ComM_CanCtrl_0_DCM_DISABLE_RX_ENABLE_TX_NORM
#define RTE_MODE_DcmCommunicationControl_ComM_CanCtrl_0_DCM_DISABLE_RX_ENABLE_TX_NORM     2U
#endif
#ifndef RTE_MODE_DcmCommunicationControl_ComM_CanCtrl_0_DCM_DISABLE_RX_TX_NORMAL
#define RTE_MODE_DcmCommunicationControl_ComM_CanCtrl_0_DCM_DISABLE_RX_TX_NORMAL          3U
#endif
#ifndef RTE_MODE_DcmCommunicationControl_ComM_CanCtrl_0_DCM_ENABLE_RX_TX_NM
#define RTE_MODE_DcmCommunicationControl_ComM_CanCtrl_0_DCM_ENABLE_RX_TX_NM     4U
#endif
#ifndef RTE_MODE_DcmCommunicationControl_ComM_CanCtrl_0_DCM_ENABLE_RX_DISABLE_TX_NM
#define RTE_MODE_DcmCommunicationControl_ComM_CanCtrl_0_DCM_ENABLE_RX_DISABLE_TX_NM       5U
#endif
#ifndef RTE_MODE_DcmCommunicationControl_ComM_CanCtrl_0_DCM_DISABLE_RX_ENABLE_TX_NM
#define RTE_MODE_DcmCommunicationControl_ComM_CanCtrl_0_DCM_DISABLE_RX_ENABLE_TX_NM       6U
#endif
#ifndef RTE_MODE_DcmCommunicationControl_ComM_CanCtrl_0_DCM_DISABLE_RX_TX_NM
#define RTE_MODE_DcmCommunicationControl_ComM_CanCtrl_0_DCM_DISABLE_RX_TX_NM    7U
#endif
#ifndef RTE_MODE_DcmCommunicationControl_ComM_CanCtrl_0_DCM_ENABLE_RX_TX_NORM_NM
#define RTE_MODE_DcmCommunicationControl_ComM_CanCtrl_0_DCM_ENABLE_RX_TX_NORM_NM          8U
#endif
#ifndef RTE_MODE_DcmCommunicationControl_ComM_CanCtrl_0_DCM_ENABLE_RX_DISABLE_TX_NORM_NM
#define RTE_MODE_DcmCommunicationControl_ComM_CanCtrl_0_DCM_ENABLE_RX_DISABLE_TX_NORM_NM  9U
#endif
#ifndef RTE_MODE_DcmCommunicationControl_ComM_CanCtrl_0_DCM_DISABLE_RX_ENABLE_TX_NORM_NM
#define RTE_MODE_DcmCommunicationControl_ComM_CanCtrl_0_DCM_DISABLE_RX_ENABLE_TX_NORM_NM  10U
#endif
#ifndef RTE_MODE_DcmCommunicationControl_ComM_CanCtrl_0_DCM_DISABLE_RX_TX_NORM_NM
#define RTE_MODE_DcmCommunicationControl_ComM_CanCtrl_0_DCM_DISABLE_RX_TX_NORM_NM         11U
#endif
#ifndef RTE_TRANSITION_DcmCommunicationControl_ComM_CanCtrl_0
#define RTE_TRANSITION_DcmCommunicationControl_ComM_CanCtrl_0         12U
#endif
#ifndef RTE_MODETYPE_DcmCommunicationControl_ComM_CanCtrl_1
#define RTE_MODETYPE_DcmCommunicationControl_ComM_CanCtrl_1
typedef uint8 Rte_ModeType_DcmCommunicationControl_ComM_CanCtrl_1;
#endif
#ifndef RTE_MODE_DcmCommunicationControl_ComM_CanCtrl_1_DCM_ENABLE_RX_TX_NORM
#define RTE_MODE_DcmCommunicationControl_ComM_CanCtrl_1_DCM_ENABLE_RX_TX_NORM   0U
#endif
#ifndef RTE_MODE_DcmCommunicationControl_ComM_CanCtrl_1_DCM_ENABLE_RX_DISABLE_TX_NORM
#define RTE_MODE_DcmCommunicationControl_ComM_CanCtrl_1_DCM_ENABLE_RX_DISABLE_TX_NORM     1U
#endif
#ifndef RTE_MODE_DcmCommunicationControl_ComM_CanCtrl_1_DCM_DISABLE_RX_ENABLE_TX_NORM
#define RTE_MODE_DcmCommunicationControl_ComM_CanCtrl_1_DCM_DISABLE_RX_ENABLE_TX_NORM     2U
#endif
#ifndef RTE_MODE_DcmCommunicationControl_ComM_CanCtrl_1_DCM_DISABLE_RX_TX_NORMAL
#define RTE_MODE_DcmCommunicationControl_ComM_CanCtrl_1_DCM_DISABLE_RX_TX_NORMAL          3U
#endif
#ifndef RTE_MODE_DcmCommunicationControl_ComM_CanCtrl_1_DCM_ENABLE_RX_TX_NM
#define RTE_MODE_DcmCommunicationControl_ComM_CanCtrl_1_DCM_ENABLE_RX_TX_NM     4U
#endif
#ifndef RTE_MODE_DcmCommunicationControl_ComM_CanCtrl_1_DCM_ENABLE_RX_DISABLE_TX_NM
#define RTE_MODE_DcmCommunicationControl_ComM_CanCtrl_1_DCM_ENABLE_RX_DISABLE_TX_NM       5U
#endif
#ifndef RTE_MODE_DcmCommunicationControl_ComM_CanCtrl_1_DCM_DISABLE_RX_ENABLE_TX_NM
#define RTE_MODE_DcmCommunicationControl_ComM_CanCtrl_1_DCM_DISABLE_RX_ENABLE_TX_NM       6U
#endif
#ifndef RTE_MODE_DcmCommunicationControl_ComM_CanCtrl_1_DCM_DISABLE_RX_TX_NM
#define RTE_MODE_DcmCommunicationControl_ComM_CanCtrl_1_DCM_DISABLE_RX_TX_NM    7U
#endif
#ifndef RTE_MODE_DcmCommunicationControl_ComM_CanCtrl_1_DCM_ENABLE_RX_TX_NORM_NM
#define RTE_MODE_DcmCommunicationControl_ComM_CanCtrl_1_DCM_ENABLE_RX_TX_NORM_NM          8U
#endif
#ifndef RTE_MODE_DcmCommunicationControl_ComM_CanCtrl_1_DCM_ENABLE_RX_DISABLE_TX_NORM_NM
#define RTE_MODE_DcmCommunicationControl_ComM_CanCtrl_1_DCM_ENABLE_RX_DISABLE_TX_NORM_NM  9U
#endif
#ifndef RTE_MODE_DcmCommunicationControl_ComM_CanCtrl_1_DCM_DISABLE_RX_ENABLE_TX_NORM_NM
#define RTE_MODE_DcmCommunicationControl_ComM_CanCtrl_1_DCM_DISABLE_RX_ENABLE_TX_NORM_NM  10U
#endif
#ifndef RTE_MODE_DcmCommunicationControl_ComM_CanCtrl_1_DCM_DISABLE_RX_TX_NORM_NM
#define RTE_MODE_DcmCommunicationControl_ComM_CanCtrl_1_DCM_DISABLE_RX_TX_NORM_NM         11U
#endif
#ifndef RTE_TRANSITION_DcmCommunicationControl_ComM_CanCtrl_1
#define RTE_TRANSITION_DcmCommunicationControl_ComM_CanCtrl_1         12U
#endif
#ifndef RTE_MODETYPE_DcmCommunicationControl_ComM_EthCtrl
#define RTE_MODETYPE_DcmCommunicationControl_ComM_EthCtrl
typedef uint8 Rte_ModeType_DcmCommunicationControl_ComM_EthCtrl;
#endif
#ifndef RTE_MODE_DcmCommunicationControl_ComM_EthCtrl_DCM_ENABLE_RX_TX_NORM
#define RTE_MODE_DcmCommunicationControl_ComM_EthCtrl_DCM_ENABLE_RX_TX_NORM     0U
#endif
#ifndef RTE_MODE_DcmCommunicationControl_ComM_EthCtrl_DCM_ENABLE_RX_DISABLE_TX_NORM
#define RTE_MODE_DcmCommunicationControl_ComM_EthCtrl_DCM_ENABLE_RX_DISABLE_TX_NORM       1U
#endif
#ifndef RTE_MODE_DcmCommunicationControl_ComM_EthCtrl_DCM_DISABLE_RX_ENABLE_TX_NORM
#define RTE_MODE_DcmCommunicationControl_ComM_EthCtrl_DCM_DISABLE_RX_ENABLE_TX_NORM       2U
#endif
#ifndef RTE_MODE_DcmCommunicationControl_ComM_EthCtrl_DCM_DISABLE_RX_TX_NORMAL
#define RTE_MODE_DcmCommunicationControl_ComM_EthCtrl_DCM_DISABLE_RX_TX_NORMAL  3U
#endif
#ifndef RTE_MODE_DcmCommunicationControl_ComM_EthCtrl_DCM_ENABLE_RX_TX_NM
#define RTE_MODE_DcmCommunicationControl_ComM_EthCtrl_DCM_ENABLE_RX_TX_NM       4U
#endif
#ifndef RTE_MODE_DcmCommunicationControl_ComM_EthCtrl_DCM_ENABLE_RX_DISABLE_TX_NM
#define RTE_MODE_DcmCommunicationControl_ComM_EthCtrl_DCM_ENABLE_RX_DISABLE_TX_NM         5U
#endif
#ifndef RTE_MODE_DcmCommunicationControl_ComM_EthCtrl_DCM_DISABLE_RX_ENABLE_TX_NM
#define RTE_MODE_DcmCommunicationControl_ComM_EthCtrl_DCM_DISABLE_RX_ENABLE_TX_NM         6U
#endif
#ifndef RTE_MODE_DcmCommunicationControl_ComM_EthCtrl_DCM_DISABLE_RX_TX_NM
#define RTE_MODE_DcmCommunicationControl_ComM_EthCtrl_DCM_DISABLE_RX_TX_NM      7U
#endif
#ifndef RTE_MODE_DcmCommunicationControl_ComM_EthCtrl_DCM_ENABLE_RX_TX_NORM_NM
#define RTE_MODE_DcmCommunicationControl_ComM_EthCtrl_DCM_ENABLE_RX_TX_NORM_NM  8U
#endif
#ifndef RTE_MODE_DcmCommunicationControl_ComM_EthCtrl_DCM_ENABLE_RX_DISABLE_TX_NORM_NM
#define RTE_MODE_DcmCommunicationControl_ComM_EthCtrl_DCM_ENABLE_RX_DISABLE_TX_NORM_NM    9U
#endif
#ifndef RTE_MODE_DcmCommunicationControl_ComM_EthCtrl_DCM_DISABLE_RX_ENABLE_TX_NORM_NM
#define RTE_MODE_DcmCommunicationControl_ComM_EthCtrl_DCM_DISABLE_RX_ENABLE_TX_NORM_NM    10U
#endif
#ifndef RTE_MODE_DcmCommunicationControl_ComM_EthCtrl_DCM_DISABLE_RX_TX_NORM_NM
#define RTE_MODE_DcmCommunicationControl_ComM_EthCtrl_DCM_DISABLE_RX_TX_NORM_NM 11U
#endif
#ifndef RTE_TRANSITION_DcmCommunicationControl_ComM_EthCtrl
#define RTE_TRANSITION_DcmCommunicationControl_ComM_EthCtrl 12U
#endif
#ifndef RTE_MODETYPE_DcmControlDtcSetting
#define RTE_MODETYPE_DcmControlDtcSetting
typedef uint8 Rte_ModeType_DcmControlDtcSetting;
#endif
#ifndef RTE_MODE_DcmControlDtcSetting_ENABLEDTCSETTING
#define RTE_MODE_DcmControlDtcSetting_ENABLEDTCSETTING      0U
#endif
#ifndef RTE_MODE_DcmControlDtcSetting_DISABLEDTCSETTING
#define RTE_MODE_DcmControlDtcSetting_DISABLEDTCSETTING     1U
#endif
#ifndef RTE_TRANSITION_DcmControlDtcSetting
#define RTE_TRANSITION_DcmControlDtcSetting                 2U
#endif
#ifndef RTE_MODETYPE_DcmDiagnosticSessionControl
#define RTE_MODETYPE_DcmDiagnosticSessionControl
typedef uint8 Rte_ModeType_DcmDiagnosticSessionControl;
#endif
#ifndef RTE_MODE_DcmDiagnosticSessionControl_DEFAULT_SESSION
#define RTE_MODE_DcmDiagnosticSessionControl_DEFAULT_SESSION          0U
#endif
#ifndef RTE_MODE_DcmDiagnosticSessionControl_PROGRAMMING_SESSION
#define RTE_MODE_DcmDiagnosticSessionControl_PROGRAMMING_SESSION      1U
#endif
#ifndef RTE_MODE_DcmDiagnosticSessionControl_EXTENDED_SESSION
#define RTE_MODE_DcmDiagnosticSessionControl_EXTENDED_SESSION         2U
#endif
#ifndef RTE_TRANSITION_DcmDiagnosticSessionControl
#define RTE_TRANSITION_DcmDiagnosticSessionControl          3U
#endif
#ifndef RTE_MODETYPE_DcmEcuReset
#define RTE_MODETYPE_DcmEcuReset
typedef uint8 Rte_ModeType_DcmEcuReset;
#endif
#ifndef RTE_MODE_DcmEcuReset_NONE
#define RTE_MODE_DcmEcuReset_NONE                           0U
#endif
#ifndef RTE_MODE_DcmEcuReset_HARD
#define RTE_MODE_DcmEcuReset_HARD                           1U
#endif
#ifndef RTE_MODE_DcmEcuReset_KEYONOFF
#define RTE_MODE_DcmEcuReset_KEYONOFF                       2U
#endif
#ifndef RTE_MODE_DcmEcuReset_SOFT
#define RTE_MODE_DcmEcuReset_SOFT                           3U
#endif
#ifndef RTE_MODE_DcmEcuReset_JUMPTOBOOTLOADER
#define RTE_MODE_DcmEcuReset_JUMPTOBOOTLOADER               4U
#endif
#ifndef RTE_MODE_DcmEcuReset_JUMPTOSYSSUPPLIERBOOTLOADER
#define RTE_MODE_DcmEcuReset_JUMPTOSYSSUPPLIERBOOTLOADER    5U
#endif
#ifndef RTE_MODE_DcmEcuReset_EXECUTE
#define RTE_MODE_DcmEcuReset_EXECUTE                        6U
#endif
#ifndef RTE_TRANSITION_DcmEcuReset
#define RTE_TRANSITION_DcmEcuReset                          7U
#endif


#endif



