/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : PduR_Cfg.c
********************************************************************************
*   Project/Product : AUTOSAR BSW PROJECT
*   Title           : PduR module configuration File
*   Author          : Hirain
********************************************************************************
*   Description     : PduR module configuration File
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
#include "PduR_Types.h"
#include "SoAd_Cbk.h"
#include "DoIP_Cbk.h"
#include "CanIf.h"
#include "Com_Cbk.h"
#include "Dcm_Cbk.h"

#include "CanTp.h"

#define PDUR_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"

/*******************************************************************************
*	PduRRoutingTable 
*******************************************************************************/
CONST(PduRRoutingPathInfoType, PDUR_CONST) PduRRoutingTable[PDUR_NUMPDURROUTPATH] =
{
    /*0*/
    {
        {PduR_CanIf_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq, MODULE_CANIF},
        {Com_PduR_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq, MODULE_COM, PDUR_DIRECT, 7, PDUR_TPGW_TRIGGER_IND, PDUR_UNUSED, PDUR_RPGROUP_NONE},
        0x0
    },

    /*1*/
    {
        {PduR_CanIf_CanConfigSet_Rx_ACAN_BCM_LIGHT_0x106, MODULE_CANIF},
        {Com_PduR_CanConfigSet_Rx_ACAN_BCM_LIGHT_0x106, MODULE_COM, PDUR_DIRECT, 7, PDUR_TPGW_TRIGGER_IND, PDUR_UNUSED, PDUR_RPGROUP_NONE},
        0x0
    },

    /*2*/
    {
        {PduR_CanIf_CanConfigSet_Rx_ACAN_BCM_SwitchSts_0x109, MODULE_CANIF},
        {Com_PduR_CanConfigSet_Rx_ACAN_BCM_SwitchSts_0x109, MODULE_COM, PDUR_DIRECT, 7, PDUR_TPGW_TRIGGER_IND, PDUR_UNUSED, PDUR_RPGROUP_NONE},
        0x0
    },

    /*3*/
    {
        {PduR_CanIf_CanConfigSet_Rx_ACAN_ABS_FrontWheelSpeMCUKPH, MODULE_CANIF},
        {Com_PduR_CanConfigSet_Rx_ACAN_ABS_FrontWheelSpeMCUKPH, MODULE_COM, PDUR_DIRECT, 7, PDUR_TPGW_TRIGGER_IND, PDUR_UNUSED, PDUR_RPGROUP_NONE},
        0x0
    },

    /*4*/
    {
        {PduR_CanIf_CanConfigSet_Rx_ACAN_ABS_RearWheelSpeMCUKPH, MODULE_CANIF},
        {Com_PduR_CanConfigSet_Rx_ACAN_ABS_RearWheelSpeMCUKPH, MODULE_COM, PDUR_DIRECT, 7, PDUR_TPGW_TRIGGER_IND, PDUR_UNUSED, PDUR_RPGROUP_NONE},
        0x0
    },

    /*5*/
    {
        {PduR_CanIf_CanConfigSet_Rx_ACAN_ABS_WheelSpeedRC, MODULE_CANIF},
        {Com_PduR_CanConfigSet_Rx_ACAN_ABS_WheelSpeedRC, MODULE_COM, PDUR_DIRECT, 7, PDUR_TPGW_TRIGGER_IND, PDUR_UNUSED, PDUR_RPGROUP_NONE},
        0x0
    },

    /*6*/
    {
        {PduR_CanIf_CanConfigSet_Rx_ACAN_ABS_Status, MODULE_CANIF},
        {Com_PduR_CanConfigSet_Rx_ACAN_ABS_Status, MODULE_COM, PDUR_DIRECT, 7, PDUR_TPGW_TRIGGER_IND, PDUR_UNUSED, PDUR_RPGROUP_NONE},
        0x0
    },

    /*7*/
    {
        {PduR_CanIf_CanConfigSet_Rx_ACAN_ESC_Status_0x132, MODULE_CANIF},
        {Com_PduR_CanConfigSet_Rx_ACAN_ESC_Status_0x132, MODULE_COM, PDUR_DIRECT, 7, PDUR_TPGW_TRIGGER_IND, PDUR_UNUSED, PDUR_RPGROUP_NONE},
        0x0
    },

    /*8*/
    {
        {PduR_CanIf_CanConfigSet_Rx_ACAN_VCU_Ctrl, MODULE_CANIF},
        {Com_PduR_CanConfigSet_Rx_ACAN_VCU_Ctrl, MODULE_COM, PDUR_DIRECT, 7, PDUR_TPGW_TRIGGER_IND, PDUR_UNUSED, PDUR_RPGROUP_NONE},
        0x0
    },

    /*9*/
    {
        {PduR_CanIf_CanConfigSet_Rx_ACAN_VCU_StsEpt, MODULE_CANIF},
        {Com_PduR_CanConfigSet_Rx_ACAN_VCU_StsEpt, MODULE_COM, PDUR_DIRECT, 7, PDUR_TPGW_TRIGGER_IND, PDUR_UNUSED, PDUR_RPGROUP_NONE},
        0x0
    },

    /*10*/
    {
        {PduR_CanIf_CanConfigSet_Rx_ACAN_SAS_Sensor_0x17E, MODULE_CANIF},
        {Com_PduR_CanConfigSet_Rx_ACAN_SAS_Sensor_0x17E, MODULE_COM, PDUR_DIRECT, 7, PDUR_TPGW_TRIGGER_IND, PDUR_UNUSED, PDUR_RPGROUP_NONE},
        0x0
    },

    /*11*/
    {
        {PduR_CanIf_CanConfigSet_Rx_ACAN_EPS_LKA_Sts, MODULE_CANIF},
        {Com_PduR_CanConfigSet_Rx_ACAN_EPS_LKA_Sts, MODULE_COM, PDUR_DIRECT, 7, PDUR_TPGW_TRIGGER_IND, PDUR_UNUSED, PDUR_RPGROUP_NONE},
        0x0
    },

    /*12*/
    {
        {PduR_CanIf_CanConfigSet_Rx_ACAN_BCM_PEPS_Sts, MODULE_CANIF},
        {Com_PduR_CanConfigSet_Rx_ACAN_BCM_PEPS_Sts, MODULE_COM, PDUR_DIRECT, 7, PDUR_TPGW_TRIGGER_IND, PDUR_UNUSED, PDUR_RPGROUP_NONE},
        0x0
    },

    /*13*/
    {
        {PduR_CanIf_CanConfigSet_Rx_ACAN_MHU_ADSA01, MODULE_CANIF},
        {Com_PduR_CanConfigSet_Rx_ACAN_MHU_ADSA01, MODULE_COM, PDUR_DIRECT, 7, PDUR_TPGW_TRIGGER_IND, PDUR_UNUSED, PDUR_RPGROUP_NONE},
        0x0
    },

    /*14*/
    {
        {PduR_CanIf_CanConfigSet_Rx_ACAN_MHU_ADAS02, MODULE_CANIF},
        {Com_PduR_CanConfigSet_Rx_ACAN_MHU_ADAS02, MODULE_COM, PDUR_DIRECT, 7, PDUR_TPGW_TRIGGER_IND, PDUR_UNUSED, PDUR_RPGROUP_NONE},
        0x0
    },

    /*15*/
    {
        {PduR_CanIf_CanConfigSet_Rx_ACAN_MHU_ADAS03, MODULE_CANIF},
        {Com_PduR_CanConfigSet_Rx_ACAN_MHU_ADAS03, MODULE_COM, PDUR_DIRECT, 7, PDUR_TPGW_TRIGGER_IND, PDUR_UNUSED, PDUR_RPGROUP_NONE},
        0x0
    },

    /*16*/
    {
        {PduR_CanIf_CanConfigSet_Rx_ACAN_BCM_WindowSts, MODULE_CANIF},
        {Com_PduR_CanConfigSet_Rx_ACAN_BCM_WindowSts, MODULE_COM, PDUR_DIRECT, 7, PDUR_TPGW_TRIGGER_IND, PDUR_UNUSED, PDUR_RPGROUP_NONE},
        0x0
    },

    /*17*/
    {
        {PduR_CanIf_CanConfigSet_Rx_ACAN_ESC_EPB_0x230, MODULE_CANIF},
        {Com_PduR_CanConfigSet_Rx_ACAN_ESC_EPB_0x230, MODULE_COM, PDUR_DIRECT, 7, PDUR_TPGW_TRIGGER_IND, PDUR_UNUSED, PDUR_RPGROUP_NONE},
        0x0
    },

    /*18*/
    {
        {PduR_CanIf_CanConfigSet_Rx_ACAN_IBS_ADAS_Info, MODULE_CANIF},
        {Com_PduR_CanConfigSet_Rx_ACAN_IBS_ADAS_Info, MODULE_COM, PDUR_DIRECT, 7, PDUR_TPGW_TRIGGER_IND, PDUR_UNUSED, PDUR_RPGROUP_NONE},
        0x0
    },

    /*19*/
    {
        {PduR_CanIf_CanConfigSet_Rx_ACAN_IBS_Info, MODULE_CANIF},
        {Com_PduR_CanConfigSet_Rx_ACAN_IBS_Info, MODULE_COM, PDUR_DIRECT, 7, PDUR_TPGW_TRIGGER_IND, PDUR_UNUSED, PDUR_RPGROUP_NONE},
        0x0
    },

    /*20*/
    {
        {PduR_CanIf_CanConfigSet_Rx_ACAN_TBOX_DateTime1, MODULE_CANIF},
        {Com_PduR_CanConfigSet_Rx_ACAN_TBOX_DateTime1, MODULE_COM, PDUR_DIRECT, 7, PDUR_TPGW_TRIGGER_IND, PDUR_UNUSED, PDUR_RPGROUP_NONE},
        0x0
    },

    /*21*/
    {
        {PduR_CanIf_CanConfigSet_Rx_ACAN_MHU_Status_Info, MODULE_CANIF},
        {Com_PduR_CanConfigSet_Rx_ACAN_MHU_Status_Info, MODULE_COM, PDUR_DIRECT, 7, PDUR_TPGW_TRIGGER_IND, PDUR_UNUSED, PDUR_RPGROUP_NONE},
        0x0
    },

    /*22*/
    {
        {PduR_CanIf_CanConfigSet_Rx_ACAN_CCU_StsInfo1, MODULE_CANIF},
        {Com_PduR_CanConfigSet_Rx_ACAN_CCU_StsInfo1, MODULE_COM, PDUR_DIRECT, 7, PDUR_TPGW_TRIGGER_IND, PDUR_UNUSED, PDUR_RPGROUP_NONE},
        0x0
    },

    /*23*/
    {
        {PduR_CanIf_CanConfigSet_Rx_ACAN_ESC_YawAngle_0x3E2, MODULE_CANIF},
        {Com_PduR_CanConfigSet_Rx_ACAN_ESC_YawAngle_0x3E2, MODULE_COM, PDUR_DIRECT, 7, PDUR_TPGW_TRIGGER_IND, PDUR_UNUSED, PDUR_RPGROUP_NONE},
        0x0
    },

    /*24*/
    {
        {PduR_CanIf_CanConfigSet_Rx_ACAN_IPC_TotalOdometer, MODULE_CANIF},
        {Com_PduR_CanConfigSet_Rx_ACAN_IPC_TotalOdometer, MODULE_COM, PDUR_DIRECT, 7, PDUR_TPGW_TRIGGER_IND, PDUR_UNUSED, PDUR_RPGROUP_NONE},
        0x0
    },

    /*25*/
    {
        {PduR_CanIf_CanConfigSet_Rx_ACAN_MFS_L_Control_Button2_0x3F7, MODULE_CANIF},
        {Com_PduR_CanConfigSet_Rx_ACAN_MFS_L_Control_Button2_0x3F7, MODULE_COM, PDUR_DIRECT, 7, PDUR_TPGW_TRIGGER_IND, PDUR_UNUSED, PDUR_RPGROUP_NONE},
        0x0
    },

    /*26*/
    {
        {PduR_CanIf_CanConfigSet_Rx_ACAN_BCM_RLS, MODULE_CANIF},
        {Com_PduR_CanConfigSet_Rx_ACAN_BCM_RLS, MODULE_COM, PDUR_DIRECT, 7, PDUR_TPGW_TRIGGER_IND, PDUR_UNUSED, PDUR_RPGROUP_NONE},
        0x0
    },

    /*27*/
    {
        {PduR_CanIf_CanConfigSet_Rx_ACAN_BCM_TPMS_Info2, MODULE_CANIF},
        {Com_PduR_CanConfigSet_Rx_ACAN_BCM_TPMS_Info2, MODULE_COM, PDUR_DIRECT, 7, PDUR_TPGW_TRIGGER_IND, PDUR_UNUSED, PDUR_RPGROUP_NONE},
        0x0
    },

    /*28*/
    {
        {PduR_CanIf_CanConfigSet_Rx_ACAN_BCM_DoorState_0x4D4, MODULE_CANIF},
        {Com_PduR_CanConfigSet_Rx_ACAN_BCM_DoorState_0x4D4, MODULE_COM, PDUR_DIRECT, 7, PDUR_TPGW_TRIGGER_IND, PDUR_UNUSED, PDUR_RPGROUP_NONE},
        0x0
    },

    /*29*/
    {
        {PduR_CanIf_CanConfigSet_Rx_Radar_ARS_TIME_SYNC, MODULE_CANIF},
        {Com_PduR_CanConfigSet_Rx_Radar_ARS_TIME_SYNC, MODULE_COM, PDUR_DIRECT, 7, PDUR_TPGW_TRIGGER_IND, PDUR_UNUSED, PDUR_RPGROUP_NONE},
        0x0
    },

    /*30*/
    {
        {PduR_CanIf_CanConfigSet_Rx_Radar_ARS_SYS_PERFORM, MODULE_CANIF},
        {Com_PduR_CanConfigSet_Rx_Radar_ARS_SYS_PERFORM, MODULE_COM, PDUR_DIRECT, 7, PDUR_TPGW_TRIGGER_IND, PDUR_UNUSED, PDUR_RPGROUP_NONE},
        0x0
    },

    /*31*/
    {
        {PduR_CanIf_CanConfigSet_Rx_Radar_ARS_OD_Header, MODULE_CANIF},
        {Com_PduR_CanConfigSet_Rx_Radar_ARS_OD_Header, MODULE_COM, PDUR_DIRECT, 7, PDUR_TPGW_TRIGGER_IND, PDUR_UNUSED, PDUR_RPGROUP_NONE},
        0x0
    },

    /*32*/
    {
        {PduR_CanIf_CanConfigSet_Rx_Radar_ARS_OD_00_01, MODULE_CANIF},
        {Com_PduR_CanConfigSet_Rx_Radar_ARS_OD_00_01, MODULE_COM, PDUR_DIRECT, 7, PDUR_TPGW_TRIGGER_IND, PDUR_UNUSED, PDUR_RPGROUP_NONE},
        0x0
    },

    /*33*/
    {
        {PduR_CanIf_CanConfigSet_Rx_Radar_ARS_OD_02_03, MODULE_CANIF},
        {Com_PduR_CanConfigSet_Rx_Radar_ARS_OD_02_03, MODULE_COM, PDUR_DIRECT, 7, PDUR_TPGW_TRIGGER_IND, PDUR_UNUSED, PDUR_RPGROUP_NONE},
        0x0
    },

    /*34*/
    {
        {PduR_CanIf_CanConfigSet_Rx_Radar_ARS_OD_04_05, MODULE_CANIF},
        {Com_PduR_CanConfigSet_Rx_Radar_ARS_OD_04_05, MODULE_COM, PDUR_DIRECT, 7, PDUR_TPGW_TRIGGER_IND, PDUR_UNUSED, PDUR_RPGROUP_NONE},
        0x0
    },

    /*35*/
    {
        {PduR_CanIf_CanConfigSet_Rx_Radar_ARS_OD_06_07, MODULE_CANIF},
        {Com_PduR_CanConfigSet_Rx_Radar_ARS_OD_06_07, MODULE_COM, PDUR_DIRECT, 7, PDUR_TPGW_TRIGGER_IND, PDUR_UNUSED, PDUR_RPGROUP_NONE},
        0x0
    },

    /*36*/
    {
        {PduR_CanIf_CanConfigSet_Rx_Radar_ARS_OD_08_09, MODULE_CANIF},
        {Com_PduR_CanConfigSet_Rx_Radar_ARS_OD_08_09, MODULE_COM, PDUR_DIRECT, 7, PDUR_TPGW_TRIGGER_IND, PDUR_UNUSED, PDUR_RPGROUP_NONE},
        0x0
    },

    /*37*/
    {
        {PduR_CanIf_CanConfigSet_Rx_Radar_ARS_OD_10_11, MODULE_CANIF},
        {Com_PduR_CanConfigSet_Rx_Radar_ARS_OD_10_11, MODULE_COM, PDUR_DIRECT, 7, PDUR_TPGW_TRIGGER_IND, PDUR_UNUSED, PDUR_RPGROUP_NONE},
        0x0
    },

    /*38*/
    {
        {PduR_CanIf_CanConfigSet_Rx_Radar_ARS_OD_12_13, MODULE_CANIF},
        {Com_PduR_CanConfigSet_Rx_Radar_ARS_OD_12_13, MODULE_COM, PDUR_DIRECT, 7, PDUR_TPGW_TRIGGER_IND, PDUR_UNUSED, PDUR_RPGROUP_NONE},
        0x0
    },

    /*39*/
    {
        {PduR_CanIf_CanConfigSet_Rx_Radar_ARS_OD_14_15, MODULE_CANIF},
        {Com_PduR_CanConfigSet_Rx_Radar_ARS_OD_14_15, MODULE_COM, PDUR_DIRECT, 7, PDUR_TPGW_TRIGGER_IND, PDUR_UNUSED, PDUR_RPGROUP_NONE},
        0x0
    },

    /*40*/
    {
        {PduR_CanIf_CanConfigSet_Rx_Radar_ARS_OD_16_17, MODULE_CANIF},
        {Com_PduR_CanConfigSet_Rx_Radar_ARS_OD_16_17, MODULE_COM, PDUR_DIRECT, 7, PDUR_TPGW_TRIGGER_IND, PDUR_UNUSED, PDUR_RPGROUP_NONE},
        0x0
    },

    /*41*/
    {
        {PduR_CanIf_CanConfigSet_Rx_Radar_ARS_OD_18_19, MODULE_CANIF},
        {Com_PduR_CanConfigSet_Rx_Radar_ARS_OD_18_19, MODULE_COM, PDUR_DIRECT, 7, PDUR_TPGW_TRIGGER_IND, PDUR_UNUSED, PDUR_RPGROUP_NONE},
        0x0
    },

    /*42*/
    {
        {PduR_CanIf_CanConfigSet_Rx_Radar_ARS_OD_20_21, MODULE_CANIF},
        {Com_PduR_CanConfigSet_Rx_Radar_ARS_OD_20_21, MODULE_COM, PDUR_DIRECT, 7, PDUR_TPGW_TRIGGER_IND, PDUR_UNUSED, PDUR_RPGROUP_NONE},
        0x0
    },

    /*43*/
    {
        {PduR_CanIf_CanConfigSet_Rx_Radar_ARS_OD_22_23, MODULE_CANIF},
        {Com_PduR_CanConfigSet_Rx_Radar_ARS_OD_22_23, MODULE_COM, PDUR_DIRECT, 7, PDUR_TPGW_TRIGGER_IND, PDUR_UNUSED, PDUR_RPGROUP_NONE},
        0x0
    },

    /*44*/
    {
        {PduR_CanIf_CanConfigSet_Rx_Radar_ARS_OD_24_25, MODULE_CANIF},
        {Com_PduR_CanConfigSet_Rx_Radar_ARS_OD_24_25, MODULE_COM, PDUR_DIRECT, 7, PDUR_TPGW_TRIGGER_IND, PDUR_UNUSED, PDUR_RPGROUP_NONE},
        0x0
    },

    /*45*/
    {
        {PduR_CanIf_CanConfigSet_Rx_Radar_ARS_OD_26_27, MODULE_CANIF},
        {Com_PduR_CanConfigSet_Rx_Radar_ARS_OD_26_27, MODULE_COM, PDUR_DIRECT, 7, PDUR_TPGW_TRIGGER_IND, PDUR_UNUSED, PDUR_RPGROUP_NONE},
        0x0
    },

    /*46*/
    {
        {PduR_CanIf_CanConfigSet_Rx_Radar_ARS_OD_28_29, MODULE_CANIF},
        {Com_PduR_CanConfigSet_Rx_Radar_ARS_OD_28_29, MODULE_COM, PDUR_DIRECT, 7, PDUR_TPGW_TRIGGER_IND, PDUR_UNUSED, PDUR_RPGROUP_NONE},
        0x0
    },

    /*47*/
    {
        {PduR_CanIf_CanConfigSet_Rx_Radar_ARS_OD_30_31, MODULE_CANIF},
        {Com_PduR_CanConfigSet_Rx_Radar_ARS_OD_30_31, MODULE_COM, PDUR_DIRECT, 7, PDUR_TPGW_TRIGGER_IND, PDUR_UNUSED, PDUR_RPGROUP_NONE},
        0x0
    },

    /*48*/
    {
        {PduR_Com_CanConfigSet_Tx_ACAN_ADAS_01, MODULE_COM},
        {CanIf_CanConfigSet_Tx_ACAN_ADAS_01, MODULE_CANIF, PDUR_DIRECT, 7, PDUR_TPGW_TRIGGER_IND, PDUR_UNUSED, PDUR_RPGROUP_NONE},
        0x1
    },

    /*49*/
    {
        {PduR_Com_CanConfigSet_Tx_ACAN_ADAS_02, MODULE_COM},
        {CanIf_CanConfigSet_Tx_ACAN_ADAS_02, MODULE_CANIF, PDUR_DIRECT, 7, PDUR_TPGW_TRIGGER_IND, PDUR_UNUSED, PDUR_RPGROUP_NONE},
        0x1
    },

    /*50*/
    {
        {PduR_Com_CanConfigSet_Tx_ACAN_ADAS_03, MODULE_COM},
        {CanIf_CanConfigSet_Tx_ACAN_ADAS_03, MODULE_CANIF, PDUR_DIRECT, 7, PDUR_TPGW_TRIGGER_IND, PDUR_UNUSED, PDUR_RPGROUP_NONE},
        0x1
    },

    /*51*/
    {
        {PduR_Com_CanConfigSet_Tx_ACAN_ADAS_04, MODULE_COM},
        {CanIf_CanConfigSet_Tx_ACAN_ADAS_04, MODULE_CANIF, PDUR_DIRECT, 7, PDUR_TPGW_TRIGGER_IND, PDUR_UNUSED, PDUR_RPGROUP_NONE},
        0x1
    },

    /*52*/
    {
        {PduR_Com_CanConfigSet_Tx_ACAN_ADAS_06, MODULE_COM},
        {CanIf_CanConfigSet_Tx_ACAN_ADAS_06, MODULE_CANIF, PDUR_DIRECT, 7, PDUR_TPGW_TRIGGER_IND, PDUR_UNUSED, PDUR_RPGROUP_NONE},
        0x1
    },

    /*53*/
    {
        {PduR_Com_CanConfigSet_Tx_ACAN_ADAS_07, MODULE_COM},
        {CanIf_CanConfigSet_Tx_ACAN_ADAS_07, MODULE_CANIF, PDUR_DIRECT, 7, PDUR_TPGW_TRIGGER_IND, PDUR_UNUSED, PDUR_RPGROUP_NONE},
        0x1
    },

    /*54*/
    {
        {PduR_Com_CanConfigSet_Tx_ACAN_ADAS_08, MODULE_COM},
        {CanIf_CanConfigSet_Tx_ACAN_ADAS_08, MODULE_CANIF, PDUR_DIRECT, 7, PDUR_TPGW_TRIGGER_IND, PDUR_UNUSED, PDUR_RPGROUP_NONE},
        0x1
    },

    /*55*/
    {
        {PduR_Com_CanConfigSet_Tx_ACAN_ADAS_Info15, MODULE_COM},
        {CanIf_CanConfigSet_Tx_ACAN_ADAS_Info15, MODULE_CANIF, PDUR_DIRECT, 7, PDUR_TPGW_TRIGGER_IND, PDUR_UNUSED, PDUR_RPGROUP_NONE},
        0x1
    },

    /*56*/
    {
        {PduR_Com_CanConfigSet_Tx_ACAN_ADAS_Info17, MODULE_COM},
        {CanIf_CanConfigSet_Tx_ACAN_ADAS_Info17, MODULE_CANIF, PDUR_DIRECT, 7, PDUR_TPGW_TRIGGER_IND, PDUR_UNUSED, PDUR_RPGROUP_NONE},
        0x1
    },

    /*57*/
    {
        {PduR_Com_CanConfigSet_Tx_ACAN_ADAS_Info23, MODULE_COM},
        {CanIf_CanConfigSet_Tx_ACAN_ADAS_Info23, MODULE_CANIF, PDUR_DIRECT, 7, PDUR_TPGW_TRIGGER_IND, PDUR_UNUSED, PDUR_RPGROUP_NONE},
        0x1
    },

    /*58*/
    {
        {PduR_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info1, MODULE_COM},
        {CanIf_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info1, MODULE_CANIF, PDUR_DIRECT, 7, PDUR_TPGW_TRIGGER_IND, PDUR_UNUSED, PDUR_RPGROUP_NONE},
        0x1
    },

    /*59*/
    {
        {PduR_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info3, MODULE_COM},
        {CanIf_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info3, MODULE_CANIF, PDUR_DIRECT, 7, PDUR_TPGW_TRIGGER_IND, PDUR_UNUSED, PDUR_RPGROUP_NONE},
        0x1
    },

    /*60*/
    {
        {PduR_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info5, MODULE_COM},
        {CanIf_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info5, MODULE_CANIF, PDUR_DIRECT, 7, PDUR_TPGW_TRIGGER_IND, PDUR_UNUSED, PDUR_RPGROUP_NONE},
        0x1
    },

    /*61*/
    {
        {PduR_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info7, MODULE_COM},
        {CanIf_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info7, MODULE_CANIF, PDUR_DIRECT, 7, PDUR_TPGW_TRIGGER_IND, PDUR_UNUSED, PDUR_RPGROUP_NONE},
        0x1
    },

    /*62*/
    {
        {PduR_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info9, MODULE_COM},
        {CanIf_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info9, MODULE_CANIF, PDUR_DIRECT, 7, PDUR_TPGW_TRIGGER_IND, PDUR_UNUSED, PDUR_RPGROUP_NONE},
        0x1
    },

    /*63*/
    {
        {PduR_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info11, MODULE_COM},
        {CanIf_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info11, MODULE_CANIF, PDUR_DIRECT, 7, PDUR_TPGW_TRIGGER_IND, PDUR_UNUSED, PDUR_RPGROUP_NONE},
        0x1
    },

    /*64*/
    {
        {PduR_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info13, MODULE_COM},
        {CanIf_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info13, MODULE_CANIF, PDUR_DIRECT, 7, PDUR_TPGW_TRIGGER_IND, PDUR_UNUSED, PDUR_RPGROUP_NONE},
        0x1
    },

    /*65*/
    {
        {PduR_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info15, MODULE_COM},
        {CanIf_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info15, MODULE_CANIF, PDUR_DIRECT, 7, PDUR_TPGW_TRIGGER_IND, PDUR_UNUSED, PDUR_RPGROUP_NONE},
        0x1
    },

    /*66*/
    {
        {PduR_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info17, MODULE_COM},
        {CanIf_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info17, MODULE_CANIF, PDUR_DIRECT, 7, PDUR_TPGW_TRIGGER_IND, PDUR_UNUSED, PDUR_RPGROUP_NONE},
        0x1
    },

    /*67*/
    {
        {PduR_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info19, MODULE_COM},
        {CanIf_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info19, MODULE_CANIF, PDUR_DIRECT, 7, PDUR_TPGW_TRIGGER_IND, PDUR_UNUSED, PDUR_RPGROUP_NONE},
        0x1
    },

    /*68*/
    {
        {PduR_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info21, MODULE_COM},
        {CanIf_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info21, MODULE_CANIF, PDUR_DIRECT, 7, PDUR_TPGW_TRIGGER_IND, PDUR_UNUSED, PDUR_RPGROUP_NONE},
        0x1
    },

    /*69*/
    {
        {PduR_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info23, MODULE_COM},
        {CanIf_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info23, MODULE_CANIF, PDUR_DIRECT, 7, PDUR_TPGW_TRIGGER_IND, PDUR_UNUSED, PDUR_RPGROUP_NONE},
        0x1
    },

    /*70*/
    {
        {PduR_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info2, MODULE_COM},
        {CanIf_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info2, MODULE_CANIF, PDUR_DIRECT, 7, PDUR_TPGW_TRIGGER_IND, PDUR_UNUSED, PDUR_RPGROUP_NONE},
        0x1
    },

    /*71*/
    {
        {PduR_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info4, MODULE_COM},
        {CanIf_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info4, MODULE_CANIF, PDUR_DIRECT, 7, PDUR_TPGW_TRIGGER_IND, PDUR_UNUSED, PDUR_RPGROUP_NONE},
        0x1
    },

    /*72*/
    {
        {PduR_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info6, MODULE_COM},
        {CanIf_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info6, MODULE_CANIF, PDUR_DIRECT, 7, PDUR_TPGW_TRIGGER_IND, PDUR_UNUSED, PDUR_RPGROUP_NONE},
        0x1
    },

    /*73*/
    {
        {PduR_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info8, MODULE_COM},
        {CanIf_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info8, MODULE_CANIF, PDUR_DIRECT, 7, PDUR_TPGW_TRIGGER_IND, PDUR_UNUSED, PDUR_RPGROUP_NONE},
        0x1
    },

    /*74*/
    {
        {PduR_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info10, MODULE_COM},
        {CanIf_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info10, MODULE_CANIF, PDUR_DIRECT, 7, PDUR_TPGW_TRIGGER_IND, PDUR_UNUSED, PDUR_RPGROUP_NONE},
        0x1
    },

    /*75*/
    {
        {PduR_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info12, MODULE_COM},
        {CanIf_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info12, MODULE_CANIF, PDUR_DIRECT, 7, PDUR_TPGW_TRIGGER_IND, PDUR_UNUSED, PDUR_RPGROUP_NONE},
        0x1
    },

    /*76*/
    {
        {PduR_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info14, MODULE_COM},
        {CanIf_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info14, MODULE_CANIF, PDUR_DIRECT, 7, PDUR_TPGW_TRIGGER_IND, PDUR_UNUSED, PDUR_RPGROUP_NONE},
        0x1
    },

    /*77*/
    {
        {PduR_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info16, MODULE_COM},
        {CanIf_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info16, MODULE_CANIF, PDUR_DIRECT, 7, PDUR_TPGW_TRIGGER_IND, PDUR_UNUSED, PDUR_RPGROUP_NONE},
        0x1
    },

    /*78*/
    {
        {PduR_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info18, MODULE_COM},
        {CanIf_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info18, MODULE_CANIF, PDUR_DIRECT, 7, PDUR_TPGW_TRIGGER_IND, PDUR_UNUSED, PDUR_RPGROUP_NONE},
        0x1
    },

    /*79*/
    {
        {PduR_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info20, MODULE_COM},
        {CanIf_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info20, MODULE_CANIF, PDUR_DIRECT, 7, PDUR_TPGW_TRIGGER_IND, PDUR_UNUSED, PDUR_RPGROUP_NONE},
        0x1
    },

    /*80*/
    {
        {PduR_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info22, MODULE_COM},
        {CanIf_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info22, MODULE_CANIF, PDUR_DIRECT, 7, PDUR_TPGW_TRIGGER_IND, PDUR_UNUSED, PDUR_RPGROUP_NONE},
        0x1
    },

    /*81*/
    {
        {PduR_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info24, MODULE_COM},
        {CanIf_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info24, MODULE_CANIF, PDUR_DIRECT, 7, PDUR_TPGW_TRIGGER_IND, PDUR_UNUSED, PDUR_RPGROUP_NONE},
        0x1
    },

    /*82*/
    {
        {PduR_Com_CanConfigSet_Tx_ACAN_ADAS_Info20, MODULE_COM},
        {CanIf_CanConfigSet_Tx_ACAN_ADAS_Info20, MODULE_CANIF, PDUR_DIRECT, 7, PDUR_TPGW_TRIGGER_IND, PDUR_UNUSED, PDUR_RPGROUP_NONE},
        0x1
    },

    /*83*/
    {
        {PduR_Com_CanConfigSet_Tx_ACAN_ADAS_Info21, MODULE_COM},
        {CanIf_CanConfigSet_Tx_ACAN_ADAS_Info21, MODULE_CANIF, PDUR_DIRECT, 7, PDUR_TPGW_TRIGGER_IND, PDUR_UNUSED, PDUR_RPGROUP_NONE},
        0x1
    },

    /*84*/
    {
        {PduR_Com_CanConfigSet_Tx_ACAN_ADAS_Info22, MODULE_COM},
        {CanIf_CanConfigSet_Tx_ACAN_ADAS_Info22, MODULE_CANIF, PDUR_DIRECT, 7, PDUR_TPGW_TRIGGER_IND, PDUR_UNUSED, PDUR_RPGROUP_NONE},
        0x1
    },

    /*85*/
    {
        {PduR_Com_Tcp_Send, MODULE_COM},
        {SoAd_PduR_Tcp_Send, MODULE_SOADIF, PDUR_DIRECT, 7, PDUR_TPGW_TRIGGER_IND, PDUR_UNUSED, PDUR_RPGROUP_NONE},
        0x2
    },

    /*86*/
    {
        {PduR_Com_Udp_Send, MODULE_COM},
        {SoAd_PduR_Udp_Send, MODULE_SOADIF, PDUR_DIRECT, 7, PDUR_TPGW_TRIGGER_IND, PDUR_UNUSED, PDUR_RPGROUP_NONE},
        0x2
    },

    /*87*/
    {
        {PduR_Com_Tcp_Send, MODULE_COM},
        {SoAd_PduR_Tcp_Send, MODULE_SOADIF, PDUR_DIRECT, 7, PDUR_TPGW_TRIGGER_IND, PDUR_UNUSED, PDUR_RPGROUP_NONE},
        0x2
    },

    /*88*/
    {
        {PduR_Com_Udp_Send, MODULE_COM},
        {SoAd_PduR_Udp_Send, MODULE_SOADIF, PDUR_DIRECT, 7, PDUR_TPGW_TRIGGER_IND, PDUR_UNUSED, PDUR_RPGROUP_NONE},
        0x2
    },

    /*89*/
    {
        {PduR_Com_Udp_Send_1501, MODULE_COM},
        {SoAd_PduR_Udp_Send_1501, MODULE_SOADIF, PDUR_DIRECT, 7, PDUR_TPGW_TRIGGER_IND, PDUR_UNUSED, PDUR_RPGROUP_NONE},
        0x1
    },

    /*90*/
    {
        {PduR_Com_Udp_Send_1502, MODULE_COM},
        {SoAd_PduR_Udp_Send_1502, MODULE_SOADIF, PDUR_DIRECT, 7, PDUR_TPGW_TRIGGER_IND, PDUR_UNUSED, PDUR_RPGROUP_NONE},
        0x1
    },

    /*91*/
    {
        {PduR_Com_Udp_Send_1503, MODULE_COM},
        {SoAd_PduR_Udp_Send_1503, MODULE_SOADIF, PDUR_DIRECT, 7, PDUR_TPGW_TRIGGER_IND, PDUR_UNUSED, PDUR_RPGROUP_NONE},
        0x1
    },

    /*92*/
    {
        {PduR_Com_Udp_Send_1504, MODULE_COM},
        {SoAd_PduR_Udp_Send_1504, MODULE_SOADIF, PDUR_DIRECT, 7, PDUR_TPGW_TRIGGER_IND, PDUR_UNUSED, PDUR_RPGROUP_NONE},
        0x1
    },

    /*93*/
    {
        {PduR_Com_Udp_Send_1505, MODULE_COM},
        {SoAd_PduR_Udp_Send_1505, MODULE_SOADIF, PDUR_DIRECT, 7, PDUR_TPGW_TRIGGER_IND, PDUR_UNUSED, PDUR_RPGROUP_NONE},
        0x1
    },

    /*94*/
    {
        {PduR_Com_Udp_Send_1506, MODULE_COM},
        {SoAd_PduR_Udp_Send_1506, MODULE_SOADIF, PDUR_DIRECT, 7, PDUR_TPGW_TRIGGER_IND, PDUR_UNUSED, PDUR_RPGROUP_NONE},
        0x1
    },

    /*95*/
    {
        {PduR_Com_Udp_Send_1507, MODULE_COM},
        {SoAd_PduR_Udp_Send_1507, MODULE_SOADIF, PDUR_DIRECT, 7, PDUR_TPGW_TRIGGER_IND, PDUR_UNUSED, PDUR_RPGROUP_NONE},
        0x1
    },

    /*96*/
    {
        {PduR_CanTp_CanConfigSet_Rx_ACAN_UDS_PhyDiagReq_ADAS, MODULE_CANTP},
        {Dcm_PduR_CanConfigSet_Rx_ACAN_UDS_PhyDiagReq_ADAS, MODULE_DCM, PDUR_DIRECT, 7, PDUR_TPGW_TRIGGER_IND, PDUR_UNUSED, PDUR_RPGROUP_NONE},
        0x0
    },

    /*97*/
    {
        {PduR_CanTp_CanConfigSet_Rx_ACAN_UDS_FuncDiagReq, MODULE_CANTP},
        {Dcm_PduR_CanConfigSet_Rx_ACAN_UDS_FuncDiagReq, MODULE_DCM, PDUR_DIRECT, 7, PDUR_TPGW_TRIGGER_IND, PDUR_UNUSED, PDUR_RPGROUP_NONE},
        0x0
    },

    /*98*/
    {
        {PduR_Dcm_CanConfigSet_Tx_ACAN_UDS_DiagResp_ADAS, MODULE_DCM},
        {CanTp_PduR_CanConfigSet_Tx_ACAN_UDS_DiagResp_ADAS, MODULE_CANTP, PDUR_DIRECT, 7, PDUR_TPGW_TRIGGER_IND, PDUR_UNUSED, PDUR_RPGROUP_NONE},
        0x1
    },

    /*99*/
    {
        {PduR_Dcm_DoIPDefaultConfig_Dcm_To_DoIP, MODULE_DCM},
        {DoIP_PduR_DoIPDefaultConfig_Dcm_To_DoIP, MODULE_DOIPTP, PDUR_DIRECT, 7, PDUR_TPGW_TRIGGER_IND, PDUR_UNUSED, PDUR_RPGROUP_NONE},
        0x1
    },

    /*100*/
    {
        {PduR_SoAd_Tcp_Receive, MODULE_SOADIF},
        {Com_PduR_Tcp_Receive, MODULE_COM, PDUR_DIRECT, 7, PDUR_TPGW_TRIGGER_IND, PDUR_UNUSED, PDUR_RPGROUP_NONE},
        0x0
    },

    /*101*/
    {
        {PduR_SoAd_Udp_Receive, MODULE_SOADIF},
        {Com_PduR_Udp_Receive, MODULE_COM, PDUR_DIRECT, 7, PDUR_TPGW_TRIGGER_IND, PDUR_UNUSED, PDUR_RPGROUP_NONE},
        0x0
    },

    /*102*/
    {
        {PduR_SoAd_Tcp_Receive_1601, MODULE_SOADIF},
        {Com_PduR_Tcp_Receive_1601, MODULE_COM, PDUR_DIRECT, 7, PDUR_TPGW_TRIGGER_IND, PDUR_UNUSED, PDUR_RPGROUP_NONE},
        0x0
    },

    /*103*/
    {
        {PduR_SoAd_Tcp_Receive_1602, MODULE_SOADIF},
        {Com_PduR_Tcp_Receive_1602, MODULE_COM, PDUR_DIRECT, 7, PDUR_TPGW_TRIGGER_IND, PDUR_UNUSED, PDUR_RPGROUP_NONE},
        0x0
    },

    /*104*/
    {
        {PduR_SoAd_Tcp_Receive_1604, MODULE_SOADIF},
        {Com_PduR_Tcp_Receive_1604, MODULE_COM, PDUR_DIRECT, 7, PDUR_TPGW_TRIGGER_IND, PDUR_UNUSED, PDUR_RPGROUP_NONE},
        0x0
    },

    /*105*/
    {
        {PduR_SoAd_Tcp_Receive_1605, MODULE_SOADIF},
        {Com_PduR_Tcp_Receive_1605, MODULE_COM, PDUR_DIRECT, 7, PDUR_TPGW_TRIGGER_IND, PDUR_UNUSED, PDUR_RPGROUP_NONE},
        0x0
    },

    /*106*/
    {
        {PduR_SoAd_Udp_Send_1501, MODULE_SOADIF},
        {Com_PduR_Udp_Send_1501, MODULE_COM, PDUR_DIRECT, 7, PDUR_TPGW_TRIGGER_IND, PDUR_UNUSED, PDUR_RPGROUP_NONE},
        0x1
    },

    /*107*/
    {
        {PduR_SoAd_Udp_Send_1502, MODULE_SOADIF},
        {Com_PduR_Udp_Send_1502, MODULE_COM, PDUR_DIRECT, 7, PDUR_TPGW_TRIGGER_IND, PDUR_UNUSED, PDUR_RPGROUP_NONE},
        0x1
    },

    /*108*/
    {
        {PduR_SoAd_Udp_Send_1504, MODULE_SOADIF},
        {Com_PduR_Udp_Send_1504, MODULE_COM, PDUR_DIRECT, 7, PDUR_TPGW_TRIGGER_IND, PDUR_UNUSED, PDUR_RPGROUP_NONE},
        0x1
    },

    /*109*/
    {
        {PduR_SoAd_Udp_Send_1505, MODULE_SOADIF},
        {Com_PduR_Udp_Send_1505, MODULE_COM, PDUR_DIRECT, 7, PDUR_TPGW_TRIGGER_IND, PDUR_UNUSED, PDUR_RPGROUP_NONE},
        0x1
    },

    /*110*/
    {
        {PduR_SoAd_Udp_Send_1506, MODULE_SOADIF},
        {Com_PduR_Udp_Send_1506, MODULE_COM, PDUR_DIRECT, 7, PDUR_TPGW_TRIGGER_IND, PDUR_UNUSED, PDUR_RPGROUP_NONE},
        0x1
    },

    /*111*/
    {
        {PduR_SoAd_Udp_Send_1507, MODULE_SOADIF},
        {Com_PduR_Udp_Send_1507, MODULE_COM, PDUR_DIRECT, 7, PDUR_TPGW_TRIGGER_IND, PDUR_UNUSED, PDUR_RPGROUP_NONE},
        0x1
    },

    /*112*/
    {
        {PduR_SoAd_Tcp_Receive, MODULE_SOADIF},
        {Com_PduR_Tcp_Receive, MODULE_COM, PDUR_DIRECT, 7, PDUR_TPGW_TRIGGER_IND, PDUR_UNUSED, PDUR_RPGROUP_NONE},
        0x0
    },

    /*113*/
    {
        {PduR_SoAd_Udp_Receive, MODULE_SOADIF},
        {Com_PduR_Udp_Receive, MODULE_COM, PDUR_DIRECT, 7, PDUR_TPGW_TRIGGER_IND, PDUR_UNUSED, PDUR_RPGROUP_NONE},
        0x0
    },

    /*114*/
    {
        {PduR_SoAd_Tcp_Receive_1601, MODULE_SOADIF},
        {Com_PduR_Tcp_Receive_1601, MODULE_COM, PDUR_DIRECT, 7, PDUR_TPGW_TRIGGER_IND, PDUR_UNUSED, PDUR_RPGROUP_NONE},
        0x0
    },

    /*115*/
    {
        {PduR_SoAd_Tcp_Receive_1602, MODULE_SOADIF},
        {Com_PduR_Tcp_Receive_1602, MODULE_COM, PDUR_DIRECT, 7, PDUR_TPGW_TRIGGER_IND, PDUR_UNUSED, PDUR_RPGROUP_NONE},
        0x0
    },

    /*116*/
    {
        {PduR_SoAd_Tcp_Receive_1603, MODULE_SOADIF},
        {Com_PduR_Tcp_Receive_1603, MODULE_COM, PDUR_DIRECT, 7, PDUR_TPGW_TRIGGER_IND, PDUR_UNUSED, PDUR_RPGROUP_NONE},
        0x0
    },

    /*117*/
    {
        {PduR_SoAd_Tcp_Receive_1604, MODULE_SOADIF},
        {Com_PduR_Tcp_Receive_1604, MODULE_COM, PDUR_DIRECT, 7, PDUR_TPGW_TRIGGER_IND, PDUR_UNUSED, PDUR_RPGROUP_NONE},
        0x0
    },

    /*118*/
    {
        {PduR_SoAd_Tcp_Receive_1605, MODULE_SOADIF},
        {Com_PduR_Tcp_Receive_1605, MODULE_COM, PDUR_DIRECT, 7, PDUR_TPGW_TRIGGER_IND, PDUR_UNUSED, PDUR_RPGROUP_NONE},
        0x0
    },

    /*119*/
    {
        {PduR_SoAd_Tcp_Receive_1606, MODULE_SOADIF},
        {Com_PduR_Tcp_Receive_1606, MODULE_COM, PDUR_DIRECT, 7, PDUR_TPGW_TRIGGER_IND, PDUR_UNUSED, PDUR_RPGROUP_NONE},
        0x0
    },

    /*120*/
    {
        {PduR_SoAd_Tcp_Receive_1607, MODULE_SOADIF},
        {Com_PduR_Tcp_Receive_1607, MODULE_COM, PDUR_DIRECT, 7, PDUR_TPGW_TRIGGER_IND, PDUR_UNUSED, PDUR_RPGROUP_NONE},
        0x0
    },

    /*121*/
    {
        {PduR_SoAd_Tcp_Receive_1608, MODULE_SOADIF},
        {Com_PduR_Tcp_Receive_1608, MODULE_COM, PDUR_DIRECT, 7, PDUR_TPGW_TRIGGER_IND, PDUR_UNUSED, PDUR_RPGROUP_NONE},
        0x0
    },

    /*122*/
    {
        {PduR_SoAd_Tcp_Receive_1603, MODULE_SOADIF},
        {Com_PduR_Tcp_Receive_1603, MODULE_COM, PDUR_DIRECT, 7, PDUR_TPGW_TRIGGER_IND, PDUR_UNUSED, PDUR_RPGROUP_NONE},
        0x0
    },

    /*123*/
    {
        {PduR_SoAd_Tcp_Receive_1606, MODULE_SOADIF},
        {Com_PduR_Tcp_Receive_1606, MODULE_COM, PDUR_DIRECT, 7, PDUR_TPGW_TRIGGER_IND, PDUR_UNUSED, PDUR_RPGROUP_NONE},
        0x0
    },

    /*124*/
    {
        {PduR_SoAd_Tcp_Receive_1607, MODULE_SOADIF},
        {Com_PduR_Tcp_Receive_1607, MODULE_COM, PDUR_DIRECT, 7, PDUR_TPGW_TRIGGER_IND, PDUR_UNUSED, PDUR_RPGROUP_NONE},
        0x0
    },

    /*125*/
    {
        {PduR_SoAd_Tcp_Receive_1608, MODULE_SOADIF},
        {Com_PduR_Tcp_Receive_1608, MODULE_COM, PDUR_DIRECT, 7, PDUR_TPGW_TRIGGER_IND, PDUR_UNUSED, PDUR_RPGROUP_NONE},
        0x0
    },

    /*126*/
    {
        {PduR_SoAd_Udp_Send_1503, MODULE_SOADIF},
        {Com_PduR_Udp_Send_1503, MODULE_COM, PDUR_DIRECT, 7, PDUR_TPGW_TRIGGER_IND, PDUR_UNUSED, PDUR_RPGROUP_NONE},
        0x1
    },

    /*127*/
    {
        {PduR_DoIP_DoIPDefaultConfig_DoIP_To_Dcm_Phy, MODULE_DOIPTP},
        {Dcm_PduR_DoIPDefaultConfig_DoIP_To_Dcm_Phy, MODULE_DCM, PDUR_DIRECT, 7, PDUR_TPGW_TRIGGER_IND, PDUR_UNUSED, PDUR_RPGROUP_NONE},
        0x0
    },

    /*128*/
    {
        {PduR_DoIP_DoIPDefaultConfig_DoIP_To_Dcm_Fun, MODULE_DOIPTP},
        {Dcm_PduR_DoIPDefaultConfig_DoIP_To_Dcm_Fun, MODULE_DCM, PDUR_DIRECT, 7, PDUR_TPGW_TRIGGER_IND, PDUR_UNUSED, PDUR_RPGROUP_NONE},
        0x0
    },

};

STATIC CONST(PduR_RoutingPathIdType, PDUR_CONST) PduR_TblIdxComSrc_0[1]={48};
STATIC CONST(PduR_RoutingPathIdType, PDUR_CONST) PduR_TblIdxComSrc_1[1]={49};
STATIC CONST(PduR_RoutingPathIdType, PDUR_CONST) PduR_TblIdxComSrc_2[1]={50};
STATIC CONST(PduR_RoutingPathIdType, PDUR_CONST) PduR_TblIdxComSrc_3[1]={51};
STATIC CONST(PduR_RoutingPathIdType, PDUR_CONST) PduR_TblIdxComSrc_4[1]={52};
STATIC CONST(PduR_RoutingPathIdType, PDUR_CONST) PduR_TblIdxComSrc_5[1]={53};
STATIC CONST(PduR_RoutingPathIdType, PDUR_CONST) PduR_TblIdxComSrc_6[1]={54};
STATIC CONST(PduR_RoutingPathIdType, PDUR_CONST) PduR_TblIdxComSrc_7[1]={55};
STATIC CONST(PduR_RoutingPathIdType, PDUR_CONST) PduR_TblIdxComSrc_8[1]={56};
STATIC CONST(PduR_RoutingPathIdType, PDUR_CONST) PduR_TblIdxComSrc_9[1]={57};
STATIC CONST(PduR_RoutingPathIdType, PDUR_CONST) PduR_TblIdxComSrc_10[1]={58};
STATIC CONST(PduR_RoutingPathIdType, PDUR_CONST) PduR_TblIdxComSrc_11[1]={59};
STATIC CONST(PduR_RoutingPathIdType, PDUR_CONST) PduR_TblIdxComSrc_12[1]={60};
STATIC CONST(PduR_RoutingPathIdType, PDUR_CONST) PduR_TblIdxComSrc_13[1]={61};
STATIC CONST(PduR_RoutingPathIdType, PDUR_CONST) PduR_TblIdxComSrc_14[1]={62};
STATIC CONST(PduR_RoutingPathIdType, PDUR_CONST) PduR_TblIdxComSrc_15[1]={63};
STATIC CONST(PduR_RoutingPathIdType, PDUR_CONST) PduR_TblIdxComSrc_16[1]={64};
STATIC CONST(PduR_RoutingPathIdType, PDUR_CONST) PduR_TblIdxComSrc_17[1]={65};
STATIC CONST(PduR_RoutingPathIdType, PDUR_CONST) PduR_TblIdxComSrc_18[1]={66};
STATIC CONST(PduR_RoutingPathIdType, PDUR_CONST) PduR_TblIdxComSrc_19[1]={67};
STATIC CONST(PduR_RoutingPathIdType, PDUR_CONST) PduR_TblIdxComSrc_20[1]={68};
STATIC CONST(PduR_RoutingPathIdType, PDUR_CONST) PduR_TblIdxComSrc_21[1]={69};
STATIC CONST(PduR_RoutingPathIdType, PDUR_CONST) PduR_TblIdxComSrc_22[1]={70};
STATIC CONST(PduR_RoutingPathIdType, PDUR_CONST) PduR_TblIdxComSrc_23[1]={71};
STATIC CONST(PduR_RoutingPathIdType, PDUR_CONST) PduR_TblIdxComSrc_24[1]={72};
STATIC CONST(PduR_RoutingPathIdType, PDUR_CONST) PduR_TblIdxComSrc_25[1]={73};
STATIC CONST(PduR_RoutingPathIdType, PDUR_CONST) PduR_TblIdxComSrc_26[1]={74};
STATIC CONST(PduR_RoutingPathIdType, PDUR_CONST) PduR_TblIdxComSrc_27[1]={75};
STATIC CONST(PduR_RoutingPathIdType, PDUR_CONST) PduR_TblIdxComSrc_28[1]={76};
STATIC CONST(PduR_RoutingPathIdType, PDUR_CONST) PduR_TblIdxComSrc_29[1]={77};
STATIC CONST(PduR_RoutingPathIdType, PDUR_CONST) PduR_TblIdxComSrc_30[1]={78};
STATIC CONST(PduR_RoutingPathIdType, PDUR_CONST) PduR_TblIdxComSrc_31[1]={79};
STATIC CONST(PduR_RoutingPathIdType, PDUR_CONST) PduR_TblIdxComSrc_32[1]={80};
STATIC CONST(PduR_RoutingPathIdType, PDUR_CONST) PduR_TblIdxComSrc_33[1]={81};
STATIC CONST(PduR_RoutingPathIdType, PDUR_CONST) PduR_TblIdxComSrc_34[1]={82};
STATIC CONST(PduR_RoutingPathIdType, PDUR_CONST) PduR_TblIdxComSrc_35[1]={83};
STATIC CONST(PduR_RoutingPathIdType, PDUR_CONST) PduR_TblIdxComSrc_36[1]={84};
STATIC CONST(PduR_RoutingPathIdType, PDUR_CONST) PduR_TblIdxComSrc_37[2]={85,87};
STATIC CONST(PduR_RoutingPathIdType, PDUR_CONST) PduR_TblIdxComSrc_38[2]={86,88};
STATIC CONST(PduR_RoutingPathIdType, PDUR_CONST) PduR_TblIdxComSrc_39[1]={89};
STATIC CONST(PduR_RoutingPathIdType, PDUR_CONST) PduR_TblIdxComSrc_40[1]={90};
STATIC CONST(PduR_RoutingPathIdType, PDUR_CONST) PduR_TblIdxComSrc_41[1]={91};
STATIC CONST(PduR_RoutingPathIdType, PDUR_CONST) PduR_TblIdxComSrc_42[1]={92};
STATIC CONST(PduR_RoutingPathIdType, PDUR_CONST) PduR_TblIdxComSrc_43[1]={93};
STATIC CONST(PduR_RoutingPathIdType, PDUR_CONST) PduR_TblIdxComSrc_44[1]={94};
STATIC CONST(PduR_RoutingPathIdType, PDUR_CONST) PduR_TblIdxComSrc_45[1]={95};
CONST(PduRRoutingPduInfoType, PDUR_CONST) PduRComTxPduInfo[PDUR_NUMOFCOMTXPDU] =
{
    {1,PduR_TblIdxComSrc_0, 0x1},
    {1,PduR_TblIdxComSrc_1, 0x1},
    {1,PduR_TblIdxComSrc_2, 0x1},
    {1,PduR_TblIdxComSrc_3, 0x1},
    {1,PduR_TblIdxComSrc_4, 0x1},
    {1,PduR_TblIdxComSrc_5, 0x1},
    {1,PduR_TblIdxComSrc_6, 0x1},
    {1,PduR_TblIdxComSrc_7, 0x1},
    {1,PduR_TblIdxComSrc_8, 0x1},
    {1,PduR_TblIdxComSrc_9, 0x1},
    {1,PduR_TblIdxComSrc_10, 0x1},
    {1,PduR_TblIdxComSrc_11, 0x1},
    {1,PduR_TblIdxComSrc_12, 0x1},
    {1,PduR_TblIdxComSrc_13, 0x1},
    {1,PduR_TblIdxComSrc_14, 0x1},
    {1,PduR_TblIdxComSrc_15, 0x1},
    {1,PduR_TblIdxComSrc_16, 0x1},
    {1,PduR_TblIdxComSrc_17, 0x1},
    {1,PduR_TblIdxComSrc_18, 0x1},
    {1,PduR_TblIdxComSrc_19, 0x1},
    {1,PduR_TblIdxComSrc_20, 0x1},
    {1,PduR_TblIdxComSrc_21, 0x1},
    {1,PduR_TblIdxComSrc_22, 0x1},
    {1,PduR_TblIdxComSrc_23, 0x1},
    {1,PduR_TblIdxComSrc_24, 0x1},
    {1,PduR_TblIdxComSrc_25, 0x1},
    {1,PduR_TblIdxComSrc_26, 0x1},
    {1,PduR_TblIdxComSrc_27, 0x1},
    {1,PduR_TblIdxComSrc_28, 0x1},
    {1,PduR_TblIdxComSrc_29, 0x1},
    {1,PduR_TblIdxComSrc_30, 0x1},
    {1,PduR_TblIdxComSrc_31, 0x1},
    {1,PduR_TblIdxComSrc_32, 0x1},
    {1,PduR_TblIdxComSrc_33, 0x1},
    {1,PduR_TblIdxComSrc_34, 0x1},
    {1,PduR_TblIdxComSrc_35, 0x1},
    {1,PduR_TblIdxComSrc_36, 0x1},
    {2,PduR_TblIdxComSrc_37, 0x2},
    {2,PduR_TblIdxComSrc_38, 0x2},
    {1,PduR_TblIdxComSrc_39, 0x1},
    {1,PduR_TblIdxComSrc_40, 0x1},
    {1,PduR_TblIdxComSrc_41, 0x1},
    {1,PduR_TblIdxComSrc_42, 0x1},
    {1,PduR_TblIdxComSrc_43, 0x1},
    {1,PduR_TblIdxComSrc_44, 0x1},
    {1,PduR_TblIdxComSrc_45, 0x1},
};

STATIC CONST(PduR_RoutingPathIdType, PDUR_CONST) PduR_TblIdxDcmSrc_0[1]={98};
STATIC CONST(PduR_RoutingPathIdType, PDUR_CONST) PduR_TblIdxDcmSrc_1[1]={99};
CONST(PduRRoutingPduInfoType, PDUR_CONST) PduRDcmTxPduInfo[PDUR_NUMOFDCMTXPDU] =
{
    {1,PduR_TblIdxDcmSrc_0, 0x1},
    {1,PduR_TblIdxDcmSrc_1, 0x1},
};

STATIC CONST(PduR_RoutingPathIdType, PDUR_CONST) PduR_TblIdxCanIfSrc_0[1]={0};
STATIC CONST(PduR_RoutingPathIdType, PDUR_CONST) PduR_TblIdxCanIfSrc_1[1]={1};
STATIC CONST(PduR_RoutingPathIdType, PDUR_CONST) PduR_TblIdxCanIfSrc_2[1]={2};
STATIC CONST(PduR_RoutingPathIdType, PDUR_CONST) PduR_TblIdxCanIfSrc_3[1]={3};
STATIC CONST(PduR_RoutingPathIdType, PDUR_CONST) PduR_TblIdxCanIfSrc_4[1]={4};
STATIC CONST(PduR_RoutingPathIdType, PDUR_CONST) PduR_TblIdxCanIfSrc_5[1]={5};
STATIC CONST(PduR_RoutingPathIdType, PDUR_CONST) PduR_TblIdxCanIfSrc_6[1]={6};
STATIC CONST(PduR_RoutingPathIdType, PDUR_CONST) PduR_TblIdxCanIfSrc_7[1]={7};
STATIC CONST(PduR_RoutingPathIdType, PDUR_CONST) PduR_TblIdxCanIfSrc_8[1]={8};
STATIC CONST(PduR_RoutingPathIdType, PDUR_CONST) PduR_TblIdxCanIfSrc_9[1]={9};
STATIC CONST(PduR_RoutingPathIdType, PDUR_CONST) PduR_TblIdxCanIfSrc_10[1]={10};
STATIC CONST(PduR_RoutingPathIdType, PDUR_CONST) PduR_TblIdxCanIfSrc_11[1]={11};
STATIC CONST(PduR_RoutingPathIdType, PDUR_CONST) PduR_TblIdxCanIfSrc_12[1]={12};
STATIC CONST(PduR_RoutingPathIdType, PDUR_CONST) PduR_TblIdxCanIfSrc_13[1]={13};
STATIC CONST(PduR_RoutingPathIdType, PDUR_CONST) PduR_TblIdxCanIfSrc_14[1]={14};
STATIC CONST(PduR_RoutingPathIdType, PDUR_CONST) PduR_TblIdxCanIfSrc_15[1]={15};
STATIC CONST(PduR_RoutingPathIdType, PDUR_CONST) PduR_TblIdxCanIfSrc_16[1]={16};
STATIC CONST(PduR_RoutingPathIdType, PDUR_CONST) PduR_TblIdxCanIfSrc_17[1]={17};
STATIC CONST(PduR_RoutingPathIdType, PDUR_CONST) PduR_TblIdxCanIfSrc_18[1]={18};
STATIC CONST(PduR_RoutingPathIdType, PDUR_CONST) PduR_TblIdxCanIfSrc_19[1]={19};
STATIC CONST(PduR_RoutingPathIdType, PDUR_CONST) PduR_TblIdxCanIfSrc_20[1]={20};
STATIC CONST(PduR_RoutingPathIdType, PDUR_CONST) PduR_TblIdxCanIfSrc_21[1]={21};
STATIC CONST(PduR_RoutingPathIdType, PDUR_CONST) PduR_TblIdxCanIfSrc_22[1]={22};
STATIC CONST(PduR_RoutingPathIdType, PDUR_CONST) PduR_TblIdxCanIfSrc_23[1]={23};
STATIC CONST(PduR_RoutingPathIdType, PDUR_CONST) PduR_TblIdxCanIfSrc_24[1]={24};
STATIC CONST(PduR_RoutingPathIdType, PDUR_CONST) PduR_TblIdxCanIfSrc_25[1]={25};
STATIC CONST(PduR_RoutingPathIdType, PDUR_CONST) PduR_TblIdxCanIfSrc_26[1]={26};
STATIC CONST(PduR_RoutingPathIdType, PDUR_CONST) PduR_TblIdxCanIfSrc_27[1]={27};
STATIC CONST(PduR_RoutingPathIdType, PDUR_CONST) PduR_TblIdxCanIfSrc_28[1]={28};
STATIC CONST(PduR_RoutingPathIdType, PDUR_CONST) PduR_TblIdxCanIfSrc_29[1]={29};
STATIC CONST(PduR_RoutingPathIdType, PDUR_CONST) PduR_TblIdxCanIfSrc_30[1]={30};
STATIC CONST(PduR_RoutingPathIdType, PDUR_CONST) PduR_TblIdxCanIfSrc_31[1]={31};
STATIC CONST(PduR_RoutingPathIdType, PDUR_CONST) PduR_TblIdxCanIfSrc_32[1]={32};
STATIC CONST(PduR_RoutingPathIdType, PDUR_CONST) PduR_TblIdxCanIfSrc_33[1]={33};
STATIC CONST(PduR_RoutingPathIdType, PDUR_CONST) PduR_TblIdxCanIfSrc_34[1]={34};
STATIC CONST(PduR_RoutingPathIdType, PDUR_CONST) PduR_TblIdxCanIfSrc_35[1]={35};
STATIC CONST(PduR_RoutingPathIdType, PDUR_CONST) PduR_TblIdxCanIfSrc_36[1]={36};
STATIC CONST(PduR_RoutingPathIdType, PDUR_CONST) PduR_TblIdxCanIfSrc_37[1]={37};
STATIC CONST(PduR_RoutingPathIdType, PDUR_CONST) PduR_TblIdxCanIfSrc_38[1]={38};
STATIC CONST(PduR_RoutingPathIdType, PDUR_CONST) PduR_TblIdxCanIfSrc_39[1]={39};
STATIC CONST(PduR_RoutingPathIdType, PDUR_CONST) PduR_TblIdxCanIfSrc_40[1]={40};
STATIC CONST(PduR_RoutingPathIdType, PDUR_CONST) PduR_TblIdxCanIfSrc_41[1]={41};
STATIC CONST(PduR_RoutingPathIdType, PDUR_CONST) PduR_TblIdxCanIfSrc_42[1]={42};
STATIC CONST(PduR_RoutingPathIdType, PDUR_CONST) PduR_TblIdxCanIfSrc_43[1]={43};
STATIC CONST(PduR_RoutingPathIdType, PDUR_CONST) PduR_TblIdxCanIfSrc_44[1]={44};
STATIC CONST(PduR_RoutingPathIdType, PDUR_CONST) PduR_TblIdxCanIfSrc_45[1]={45};
STATIC CONST(PduR_RoutingPathIdType, PDUR_CONST) PduR_TblIdxCanIfSrc_46[1]={46};
STATIC CONST(PduR_RoutingPathIdType, PDUR_CONST) PduR_TblIdxCanIfSrc_47[1]={47};
CONST(PduRRoutingPduInfoType, PDUR_CONST) PduRCanIfRxPduInfo[PDUR_NUMOFCANIFRXPDU] =
{
    {1,PduR_TblIdxCanIfSrc_0, 0x0},
    {1,PduR_TblIdxCanIfSrc_1, 0x0},
    {1,PduR_TblIdxCanIfSrc_2, 0x0},
    {1,PduR_TblIdxCanIfSrc_3, 0x0},
    {1,PduR_TblIdxCanIfSrc_4, 0x0},
    {1,PduR_TblIdxCanIfSrc_5, 0x0},
    {1,PduR_TblIdxCanIfSrc_6, 0x0},
    {1,PduR_TblIdxCanIfSrc_7, 0x0},
    {1,PduR_TblIdxCanIfSrc_8, 0x0},
    {1,PduR_TblIdxCanIfSrc_9, 0x0},
    {1,PduR_TblIdxCanIfSrc_10, 0x0},
    {1,PduR_TblIdxCanIfSrc_11, 0x0},
    {1,PduR_TblIdxCanIfSrc_12, 0x0},
    {1,PduR_TblIdxCanIfSrc_13, 0x0},
    {1,PduR_TblIdxCanIfSrc_14, 0x0},
    {1,PduR_TblIdxCanIfSrc_15, 0x0},
    {1,PduR_TblIdxCanIfSrc_16, 0x0},
    {1,PduR_TblIdxCanIfSrc_17, 0x0},
    {1,PduR_TblIdxCanIfSrc_18, 0x0},
    {1,PduR_TblIdxCanIfSrc_19, 0x0},
    {1,PduR_TblIdxCanIfSrc_20, 0x0},
    {1,PduR_TblIdxCanIfSrc_21, 0x0},
    {1,PduR_TblIdxCanIfSrc_22, 0x0},
    {1,PduR_TblIdxCanIfSrc_23, 0x0},
    {1,PduR_TblIdxCanIfSrc_24, 0x0},
    {1,PduR_TblIdxCanIfSrc_25, 0x0},
    {1,PduR_TblIdxCanIfSrc_26, 0x0},
    {1,PduR_TblIdxCanIfSrc_27, 0x0},
    {1,PduR_TblIdxCanIfSrc_28, 0x0},
    {1,PduR_TblIdxCanIfSrc_29, 0x0},
    {1,PduR_TblIdxCanIfSrc_30, 0x0},
    {1,PduR_TblIdxCanIfSrc_31, 0x0},
    {1,PduR_TblIdxCanIfSrc_32, 0x0},
    {1,PduR_TblIdxCanIfSrc_33, 0x0},
    {1,PduR_TblIdxCanIfSrc_34, 0x0},
    {1,PduR_TblIdxCanIfSrc_35, 0x0},
    {1,PduR_TblIdxCanIfSrc_36, 0x0},
    {1,PduR_TblIdxCanIfSrc_37, 0x0},
    {1,PduR_TblIdxCanIfSrc_38, 0x0},
    {1,PduR_TblIdxCanIfSrc_39, 0x0},
    {1,PduR_TblIdxCanIfSrc_40, 0x0},
    {1,PduR_TblIdxCanIfSrc_41, 0x0},
    {1,PduR_TblIdxCanIfSrc_42, 0x0},
    {1,PduR_TblIdxCanIfSrc_43, 0x0},
    {1,PduR_TblIdxCanIfSrc_44, 0x0},
    {1,PduR_TblIdxCanIfSrc_45, 0x0},
    {1,PduR_TblIdxCanIfSrc_46, 0x0},
    {1,PduR_TblIdxCanIfSrc_47, 0x0},
};

STATIC CONST(PduR_RoutingPathIdType, PDUR_CONST) PduR_TblIdxCanTpSrc_0[1]={96};
STATIC CONST(PduR_RoutingPathIdType, PDUR_CONST) PduR_TblIdxCanTpSrc_1[1]={97};
CONST(PduRRoutingPduInfoType, PDUR_CONST) PduRCanTpRxPduInfo[PDUR_NUMOFCANTPRXPDU] =
{
    {1,PduR_TblIdxCanTpSrc_0, 0x0},
    {1,PduR_TblIdxCanTpSrc_1, 0x0},
};

STATIC CONST(PduR_RoutingPathIdType, PDUR_CONST) PduR_TblIdxSoAdIfSrc_0[2]={100,112};
STATIC CONST(PduR_RoutingPathIdType, PDUR_CONST) PduR_TblIdxSoAdIfSrc_1[2]={101,113};
STATIC CONST(PduR_RoutingPathIdType, PDUR_CONST) PduR_TblIdxSoAdIfSrc_2[2]={102,114};
STATIC CONST(PduR_RoutingPathIdType, PDUR_CONST) PduR_TblIdxSoAdIfSrc_3[2]={103,115};
STATIC CONST(PduR_RoutingPathIdType, PDUR_CONST) PduR_TblIdxSoAdIfSrc_4[2]={104,117};
STATIC CONST(PduR_RoutingPathIdType, PDUR_CONST) PduR_TblIdxSoAdIfSrc_5[2]={105,118};
STATIC CONST(PduR_RoutingPathIdType, PDUR_CONST) PduR_TblIdxSoAdIfSrc_6[1]={106};
STATIC CONST(PduR_RoutingPathIdType, PDUR_CONST) PduR_TblIdxSoAdIfSrc_7[1]={107};
STATIC CONST(PduR_RoutingPathIdType, PDUR_CONST) PduR_TblIdxSoAdIfSrc_8[1]={108};
STATIC CONST(PduR_RoutingPathIdType, PDUR_CONST) PduR_TblIdxSoAdIfSrc_9[1]={109};
STATIC CONST(PduR_RoutingPathIdType, PDUR_CONST) PduR_TblIdxSoAdIfSrc_10[1]={110};
STATIC CONST(PduR_RoutingPathIdType, PDUR_CONST) PduR_TblIdxSoAdIfSrc_11[1]={111};
STATIC CONST(PduR_RoutingPathIdType, PDUR_CONST) PduR_TblIdxSoAdIfSrc_12[2]={116,122};
STATIC CONST(PduR_RoutingPathIdType, PDUR_CONST) PduR_TblIdxSoAdIfSrc_13[2]={119,123};
STATIC CONST(PduR_RoutingPathIdType, PDUR_CONST) PduR_TblIdxSoAdIfSrc_14[2]={120,124};
STATIC CONST(PduR_RoutingPathIdType, PDUR_CONST) PduR_TblIdxSoAdIfSrc_15[2]={121,125};
STATIC CONST(PduR_RoutingPathIdType, PDUR_CONST) PduR_TblIdxSoAdIfSrc_16[1]={126};
CONST(PduRRoutingPduInfoType, PDUR_CONST) PduRSoAdIfRxPduInfo[PDUR_NUMOFSOADIFRXPDU] =
{
    {2,PduR_TblIdxSoAdIfSrc_0, 0x0},
    {2,PduR_TblIdxSoAdIfSrc_1, 0x0},
    {2,PduR_TblIdxSoAdIfSrc_2, 0x0},
    {2,PduR_TblIdxSoAdIfSrc_3, 0x0},
    {2,PduR_TblIdxSoAdIfSrc_4, 0x0},
    {2,PduR_TblIdxSoAdIfSrc_5, 0x0},
    {1,PduR_TblIdxSoAdIfSrc_6, 0x1},
    {1,PduR_TblIdxSoAdIfSrc_7, 0x1},
    {1,PduR_TblIdxSoAdIfSrc_8, 0x1},
    {1,PduR_TblIdxSoAdIfSrc_9, 0x1},
    {1,PduR_TblIdxSoAdIfSrc_10, 0x1},
    {1,PduR_TblIdxSoAdIfSrc_11, 0x1},
    {2,PduR_TblIdxSoAdIfSrc_12, 0x0},
    {2,PduR_TblIdxSoAdIfSrc_13, 0x0},
    {2,PduR_TblIdxSoAdIfSrc_14, 0x0},
    {2,PduR_TblIdxSoAdIfSrc_15, 0x0},
    {1,PduR_TblIdxSoAdIfSrc_16, 0x1},
};

STATIC CONST(PduR_RoutingPathIdType, PDUR_CONST) PduR_TblIdxDoIPTpSrc_0[1]={127};
STATIC CONST(PduR_RoutingPathIdType, PDUR_CONST) PduR_TblIdxDoIPTpSrc_1[1]={128};
CONST(PduRRoutingPduInfoType, PDUR_CONST) PduRDoIPTpRxPduInfo[PDUR_NUMOFDOIPTPRXPDU] =
{
    {1,PduR_TblIdxDoIPTpSrc_0, 0x0},
    {1,PduR_TblIdxDoIPTpSrc_1, 0x0},
};

CONST(PduRTxConfMapping_Type, PDUR_CONST) PduRCanIfTxConfPduInfo[PDUR_NUMOFCANIFTXPDU] =
{
    {48,Com_PduR_CanConfigSet_Tx_ACAN_ADAS_01},
    {49,Com_PduR_CanConfigSet_Tx_ACAN_ADAS_02},
    {50,Com_PduR_CanConfigSet_Tx_ACAN_ADAS_03},
    {51,Com_PduR_CanConfigSet_Tx_ACAN_ADAS_04},
    {52,Com_PduR_CanConfigSet_Tx_ACAN_ADAS_06},
    {53,Com_PduR_CanConfigSet_Tx_ACAN_ADAS_07},
    {54,Com_PduR_CanConfigSet_Tx_ACAN_ADAS_08},
    {55,Com_PduR_CanConfigSet_Tx_ACAN_ADAS_Info15},
    {56,Com_PduR_CanConfigSet_Tx_ACAN_ADAS_Info17},
    {57,Com_PduR_CanConfigSet_Tx_ACAN_ADAS_Info23},
    {58,Com_PduR_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info1},
    {59,Com_PduR_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info3},
    {60,Com_PduR_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info5},
    {61,Com_PduR_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info7},
    {62,Com_PduR_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info9},
    {63,Com_PduR_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info11},
    {64,Com_PduR_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info13},
    {65,Com_PduR_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info15},
    {66,Com_PduR_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info17},
    {67,Com_PduR_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info19},
    {68,Com_PduR_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info21},
    {69,Com_PduR_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info23},
    {70,Com_PduR_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info2},
    {71,Com_PduR_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info4},
    {72,Com_PduR_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info6},
    {73,Com_PduR_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info8},
    {74,Com_PduR_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info10},
    {75,Com_PduR_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info12},
    {76,Com_PduR_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info14},
    {77,Com_PduR_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info16},
    {78,Com_PduR_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info18},
    {79,Com_PduR_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info20},
    {80,Com_PduR_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info22},
    {81,Com_PduR_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info24},
    {82,Com_PduR_CanConfigSet_Tx_ACAN_ADAS_Info20},
    {83,Com_PduR_CanConfigSet_Tx_ACAN_ADAS_Info21},
    {84,Com_PduR_CanConfigSet_Tx_ACAN_ADAS_Info22}
};
CONST(PduRTxConfMapping_Type, PDUR_CONST) PduRCanTpTxConfPduInfo[PDUR_NUMOFCANTPTXPDU] =
{
    {98,Dcm_PduR_CanConfigSet_Tx_ACAN_UDS_DiagResp_ADAS}
};
CONST(PduRTxConfMapping_Type, PDUR_CONST) PduRSoAdIfTxConfPduInfo[PDUR_NUMOFSOADIFTXPDU] =
{
    {85,Com_PduR_Tcp_Send},
    {86,Com_PduR_Udp_Send},
    {87,Com_PduR_Tcp_Send},
    {88,Com_PduR_Udp_Send},
    {89,Com_PduR_Udp_Send_1501},
    {90,Com_PduR_Udp_Send_1502},
    {91,Com_PduR_Udp_Send_1503},
    {92,Com_PduR_Udp_Send_1504},
    {93,Com_PduR_Udp_Send_1505},
    {94,Com_PduR_Udp_Send_1506},
    {95,Com_PduR_Udp_Send_1507}
};
CONST(PduRTxConfMapping_Type, PDUR_CONST) PduRDoIPTpTxConfPduInfo[PDUR_NUMOFDOIPTPTXPDU] =
{
    {99,Dcm_PduR_DoIPDefaultConfig_Dcm_To_DoIP}
};
CONST(PduRRxCancelMapping_Type, PDUR_CONST) PduRDcmCancelRxPduInfo[PDUR_NUMOFDCMRXPDU] =
{
    {96},
    {97},
    {127},
    {128},
};


#define PDUR_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"

/*******************************************************************************
*	PduRRoutingPathGroup 
*******************************************************************************/

#define PDUR_START_SEC_CONFIG_DATA_8
#include "MemMap.h"

/*PDUR329_Conf*/
CONST(boolean, PDUR_CONST) PduR_RPGroupEnabledAtInit[PDUR_NUMOFROUTINGPATHGROUP] = {TRUE};
#define PDUR_STOP_SEC_CONFIG_DATA_8
#include "MemMap.h"




