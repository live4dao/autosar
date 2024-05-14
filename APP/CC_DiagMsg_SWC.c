/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : CC_DiagMsg_SWC.c
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
*   V1.0.2_3.5.5_AZ240046       10/05/2024    Eas           N/A          N/A
*
********************************************************************************
* END_FILE_HDR*/
/*******************************************************************************
*   Includes.
*******************************************************************************/
#include "Rte_CC_DiagMsg_SWC.h"

/* CC_DiagMsg_SWCInput File User Code start*/

/* CC_DiagMsg_SWCInput File User Code end*/

/* CC_DiagMsg_SWC.c Custom Code (#define variable etc.) User Code start*/

/* CC_DiagMsg_SWC.c Custom Code (#define variable etc.) User Code end*/

/*******************************************************************************
*   Runnable Extended
*******************************************************************************/

#define CC_DiagMsg_SWC_START_SEC_CODE
#include "CC_DiagMsg_SWC_MemMap.h"

FUNC(void, CC_DiagMsg_SWC_CODE) CC_DiagMsg_SWC
(
    void
)
{
    /* CC_DiagMsg_SWC_10ms_Start User Code start*/

    /* CC_DiagMsg_SWC_10ms_Start User Code end*/
    ABSFailed_IDT Read_ABSFailed_ABSFailed;
    ABS_EBDFailed_IDT Read_ABS_EBDFailed_ABS_EBDFailed;
    ABS_FLWheelSpeedInvalid_IDT Read_ABS_FLWheelSpeedInvalid_ABS_FLWheelSpeedInvalid;
    ABS_FLWheelSpeedRCSts_IDT Read_ABS_FLWheelSpeedRCSts_ABS_FLWheelSpeedRCSts;
    ABS_FRWheelSpeedInvalid_IDT Read_ABS_FRWheelSpeedInvalid_ABS_FRWheelSpeedInvalid;
    ABS_FRWheelSpeedRCSts_IDT Read_ABS_FRWheelSpeedRCSts_ABS_FRWheelSpeedRCSts;
    ABS_FWSpeMCUKPH_AliveCounter_IDT Read_ABS_FWSpeMCUKPH_AliveCounter_ABS_FWSpeMCUKPH_AliveCounter;
    ABS_FWSpeMCUKPH_CheckSum_IDT Read_ABS_FWSpeMCUKPH_CheckSum_ABS_FWSpeMCUKPH_CheckSum;
    ABS_RLWheelSpeedInvalid_IDT Read_ABS_RLWheelSpeedInvalid_ABS_RLWheelSpeedInvalid;
    ABS_RLWheelSpeedRCSts_IDT Read_ABS_RLWheelSpeedRCSts_ABS_RLWheelSpeedRCSts;
    ABS_RRWheelSpeedInvalid_IDT Read_ABS_RRWheelSpeedInvalid_ABS_RRWheelSpeedInvalid;
    ABS_RRWheelSpeedRCSts_IDT Read_ABS_RRWheelSpeedRCSts_ABS_RRWheelSpeedRCSts;
    ABS_RWSpeMCUKPH_AliveCounter_IDT Read_ABS_RWSpeMCUKPH_AliveCounter_ABS_RWSpeMCUKPH_AliveCounter;
    ABS_RWSpeMCUKPH_CheckSum_IDT Read_ABS_RWSpeMCUKPH_CheckSum_ABS_RWSpeMCUKPH_CheckSum;
    ABS_Status_AliveCounter_IDT Read_ABS_Status_AliveCounter_ABS_Status_AliveCounter;
    ABS_Status_CheckSum_IDT Read_ABS_Status_CheckSum_ABS_Status_CheckSum;
    ABS_VehicleSpeedInvalid_IDT Read_ABS_VehicleSpeedInvalid_ABS_VehicleSpeedInvalid;
    ABS_WheelSpeMCURC_AliveCounter_IDT Read_ABS_WheelSpeMCURC_AliveCounter_ABS_WheelSpeMCURC_AliveCounter;
    ABS_WheelSpeMCURC_CheckSum_IDT Read_ABS_WheelSpeMCURC_CheckSum_ABS_WheelSpeMCURC_CheckSum;
    AB_BrkPedalSwStsV_IDT Read_AB_BrkPedalSwStsV_AB_BrkPedalSwStsV;
    AB_Fault_Status_IDT Read_AB_Fault_Status_AB_Fault_Status;
    ACU_AliveCounter_IDT Read_ACU_AliveCounter_ACU_AliveCounter;
    ACU_CheckSum_IDT Read_ACU_CheckSum_ACU_CheckSum;
    BCM_TurnLight_FaultSts_IDT Read_BCM_TurnLight_FaultSts_BCM_TurnLight_FaultSts;
    CCU_ExternalTemperatureFailSts_IDT Read_CCU_ExternalTemperatureFailSts_CCU_ExternalTemperatureFailSts;
    CheckSum_0x106_IDT Read_CheckSum_0x106_CheckSum_0x106;
    CheckSum_0x109_IDT Read_CheckSum_0x109_CheckSum_0x109;
    CheckSum_0x17F_IDT Read_CheckSum_0x17F_CheckSum_0x17F;
    CheckSum_0x3F1_IDT Read_CheckSum_0x3F1_CheckSum_0x3F1;
    CheckSum_0x3F7_IDT Read_CheckSum_0x3F7_CheckSum_0x3F7;
    Checksum_0x132_IDT Read_Checksum_0x132_Checksum_0x132;
    Checksum_0x17E_IDT Read_Checksum_0x17E_Checksum_0x17E;
    Checksum_0x3E2_IDT Read_Checksum_0x3E2_Checksum_0x3E2;
    Checksum_230_IDT Read_Checksum_230_Checksum_230;
    EPS_ADAS_ModAvail_IDT Read_EPS_ADAS_ModAvail_EPS_ADAS_ModAvail;
    ESC_LateralACC_Valid_IDT Read_ESC_LateralACC_Valid_ESC_LateralACC_Valid;
    ESC_LongitudeACC_Valid_IDT Read_ESC_LongitudeACC_Valid_ESC_LongitudeACC_Valid;
    ESC_MasterCylinderPressureV_IDT Read_ESC_MasterCylinderPressureV_ESC_MasterCylinderPressureV;
    ESC_VehDynYawRate_Valid_IDT Read_ESC_VehDynYawRate_Valid_ESC_VehDynYawRate_Valid;
    MFS_L2_Failure_IDT Read_MFS_L2_Failure_MFS_L2_Failure;
    Nav_errorSts_IDT Read_Nav_Error_Nav_errorSts;
    PEPS_IGN1RelayValidity_IDT Read_PEPS_IGN1RelayValidity_PEPS_IGN1RelayValidity;
    PEPS_Message_Sts_AliveCounter_IDT Read_PEPS_Message_Sts_AliveCounter_PEPS_Message_Sts_AliveCounter;
    PEPS_Message_Sts_CheckSum_IDT Read_PEPS_Message_Sts_CheckSum_PEPS_Message_Sts_CheckSum;
    PEPS_PowerModeValidity_IDT Read_PEPS_PowerModeValidity_PEPS_PowerModeValidity;
    RollingCounter_0x106_IDT Read_RollingCounter_0x106_RollingCounter_0x106;
    RollingCounter_0x109_IDT Read_RollingCounter_0x109_RollingCounter_0x109;
    RollingCounter_0x132_IDT Read_RollingCounter_0x132_RollingCounter_0x132;
    RollingCounter_0x17F_IDT Read_RollingCounter_0x17F_RollingCounter_0x17F;
    RollingCounter_0x3E2_IDT Read_RollingCounter_0x3E2_RollingCounter_0x3E2;
    RollingCounter_0x3F1_IDT Read_RollingCounter_0x3F1_RollingCounter_0x3F1;
    RollingCounter_0x3F7_IDT Read_RollingCounter_0x3F7_RollingCounter_0x3F7;
    RollingCounter_230_IDT Read_RollingCounter_230_RollingCounter_230;
    Rolling_counter_0x17E_IDT Read_Rolling_counter_0x17E_Rolling_counter_0x17E;
    SAS_Calibrated_IDT Read_SAS_Calibrated_SAS_Calibrated;
    SAS_SASFailure_IDT Read_SAS_SASFailure_SAS_SASFailure;
    SAS_SASStsSnsr_IDT Read_SAS_SASStsSnsr_SAS_SASStsSnsr;
    SAS_SteerWhlRotSpdStatus_IDT Read_SAS_SteerWhlRotSpdStatus_SAS_SteerWhlRotSpdStatus;
    SAS_SteeringAngleValid_IDT Read_SAS_SteeringAngleValid_SAS_SteeringAngleValid;
    TPMS_LFpressureV_IDT Read_TPMS_LFpressureV_TPMS_LFpressureV;
    TPMS_LRpressureV_IDT Read_TPMS_LRpressureV_TPMS_LRpressureV;
    TPMS_RFpressureV_IDT Read_TPMS_RFpressureV_TPMS_RFpressureV;
    TPMS_RRpressureV_IDT Read_TPMS_RRpressureV_TPMS_RRpressureV;
    VCU_AccPedal_Valid_IDT Read_VCU_AccPedal_Valid_VCU_AccPedal_Valid;
    VCU_Ctrl_AliveCounter_IDT Read_VCU_Ctrl_AliveCounter_VCU_Ctrl_AliveCounter;
    VCU_Ctrl_CheckSum_IDT Read_VCU_Ctrl_CheckSum_VCU_Ctrl_CheckSum;
    VCU_ModeGearSts_IDT Read_VCU_ModeGearSts_VCU_ModeGearSts;
    VCU_StsEpt_AliveCounter_IDT Read_VCU_StsEpt_AliveCounter_VCU_StsEpt_AliveCounter;
    VCU_StsEpt_CheckSum_IDT Read_VCU_StsEpt_CheckSum_VCU_StsEpt_CheckSum;
    WCBS_ABAAva_IDT Read_WCBS_ABAAva_WCBS_ABAAva;
    WCBS_ABPAva_IDT Read_WCBS_ABPAva_WCBS_ABPAva;
    WCBS_ACC_VLC_Avl_IDT Read_WCBS_ACC_VLC_Avl_WCBS_ACC_VLC_Avl;
    WCBS_AEBAva_IDT Read_WCBS_AEBAva_WCBS_AEBAva;
    WCBS_AWBAvl_IDT Read_WCBS_AWBAvl_WCBS_AWBAvl;
    WCBS_ESCDeteACCErroSta_IDT Read_WCBS_ESCDeteACCErroSta_WCBS_ESCDeteACCErroSta;
    Dem_EventStatusType Call_Event_Event_0x9401A3_SetEventStatus_EventStatus;
    Dem_EventStatusType Call_Event_Event_0x940354_SetEventStatus_EventStatus;
    Dem_EventStatusType Call_Event_Event_0x940406_SetEventStatus_EventStatus;
    Dem_EventStatusType Call_Event_Event_0x942009_SetEventStatus_EventStatus;
    Dem_EventStatusType Call_Event_Event_0x942209_SetEventStatus_EventStatus;
    Dem_EventStatusType Call_Event_Event_0x942309_SetEventStatus_EventStatus;
    Dem_EventStatusType Call_Event_Event_0x942409_SetEventStatus_EventStatus;
    Dem_EventStatusType Call_Event_Event_0x942509_SetEventStatus_EventStatus;
    Dem_EventStatusType Call_Event_Event_0x942609_SetEventStatus_EventStatus;
    Dem_EventStatusType Call_Event_Event_0x942D09_SetEventStatus_EventStatus;
    Dem_EventStatusType Call_Event_Event_0x942F09_SetEventStatus_EventStatus;
    Dem_EventStatusType Call_Event_Event_0x943009_SetEventStatus_EventStatus;
    Dem_EventStatusType Call_Event_Event_0xD20008_SetEventStatus_EventStatus;
    Dem_EventStatusType Call_Event_Event_0xD20086_SetEventStatus_EventStatus;
    Dem_EventStatusType Call_Event_Event_0xD20087_SetEventStatus_EventStatus;
    Dem_EventStatusType Call_Event_Event_0xD20108_SetEventStatus_EventStatus;
    Dem_EventStatusType Call_Event_Event_0xD20186_SetEventStatus_EventStatus;
    Dem_EventStatusType Call_Event_Event_0xD20187_SetEventStatus_EventStatus;
    Dem_EventStatusType Call_Event_Event_0xD20208_SetEventStatus_EventStatus;
    Dem_EventStatusType Call_Event_Event_0xD20286_SetEventStatus_EventStatus;
    Dem_EventStatusType Call_Event_Event_0xD20287_SetEventStatus_EventStatus;
    Dem_EventStatusType Call_Event_Event_0xD20308_SetEventStatus_EventStatus;
    Dem_EventStatusType Call_Event_Event_0xD20386_SetEventStatus_EventStatus;
    Dem_EventStatusType Call_Event_Event_0xD20387_SetEventStatus_EventStatus;
    Dem_EventStatusType Call_Event_Event_0xD20408_SetEventStatus_EventStatus;
    Dem_EventStatusType Call_Event_Event_0xD20486_SetEventStatus_EventStatus;
    Dem_EventStatusType Call_Event_Event_0xD20508_SetEventStatus_EventStatus;
    Dem_EventStatusType Call_Event_Event_0xD20586_SetEventStatus_EventStatus;
    Dem_EventStatusType Call_Event_Event_0xD20608_SetEventStatus_EventStatus;
    Dem_EventStatusType Call_Event_Event_0xD20686_SetEventStatus_EventStatus;
    Dem_EventStatusType Call_Event_Event_0xD20708_SetEventStatus_EventStatus;
    Dem_EventStatusType Call_Event_Event_0xD20786_SetEventStatus_EventStatus;
    Dem_EventStatusType Call_Event_Event_0xD20808_SetEventStatus_EventStatus;
    Dem_EventStatusType Call_Event_Event_0xD20886_SetEventStatus_EventStatus;
    Dem_EventStatusType Call_Event_Event_0xD20908_SetEventStatus_EventStatus;
    Dem_EventStatusType Call_Event_Event_0xD20986_SetEventStatus_EventStatus;
    Dem_EventStatusType Call_Event_Event_0xD20A08_SetEventStatus_EventStatus;
    Dem_EventStatusType Call_Event_Event_0xD20A86_SetEventStatus_EventStatus;
    Dem_EventStatusType Call_Event_Event_0xD20B08_SetEventStatus_EventStatus;
    Dem_EventStatusType Call_Event_Event_0xD20B86_SetEventStatus_EventStatus;
    Dem_EventStatusType Call_Event_Event_0xD20C08_SetEventStatus_EventStatus;
    Dem_EventStatusType Call_Event_Event_0xD20C86_SetEventStatus_EventStatus;
    Dem_EventStatusType Call_Event_Event_0xD20D08_SetEventStatus_EventStatus;
    Dem_EventStatusType Call_Event_Event_0xD20D86_SetEventStatus_EventStatus;
    Dem_EventStatusType Call_Event_Event_0xD20E08_SetEventStatus_EventStatus;
    Dem_EventStatusType Call_Event_Event_0xD20E86_SetEventStatus_EventStatus;
    Dem_EventStatusType Call_Event_Event_0xD20F08_SetEventStatus_EventStatus;
    Dem_EventStatusType Call_Event_Event_0xD20F86_SetEventStatus_EventStatus;
    Dem_EventStatusType Call_Event_Event_0xD21008_SetEventStatus_EventStatus;
    Dem_EventStatusType Call_Event_Event_0xD21087_SetEventStatus_EventStatus;
    Dem_EventStatusType Call_Event_Event_0xD21208_SetEventStatus_EventStatus;
    Dem_EventStatusType Call_Event_Event_0xD21287_SetEventStatus_EventStatus;
    Dem_EventStatusType Call_Event_Event_0xD21308_SetEventStatus_EventStatus;
    Dem_EventStatusType Call_Event_Event_0xD21387_SetEventStatus_EventStatus;
    Dem_EventStatusType Call_Event_Event_0xD21408_SetEventStatus_EventStatus;
    Dem_EventStatusType Call_Event_Event_0xD21487_SetEventStatus_EventStatus;
    Dem_EventStatusType Call_Event_Event_0xD21508_SetEventStatus_EventStatus;
    Dem_EventStatusType Call_Event_Event_0xD21608_SetEventStatus_EventStatus;
    Dem_EventStatusType Call_Event_Event_0xD21708_SetEventStatus_EventStatus;
    Dem_EventStatusType Call_Event_Event_0xD22086_SetEventStatus_EventStatus;
    Dem_EventStatusType Call_Event_Event_0xD22186_SetEventStatus_EventStatus;
    Dem_EventStatusType Call_Event_Event_0xD22286_SetEventStatus_EventStatus;
    Dem_EventStatusType Call_Event_Event_0xD22386_SetEventStatus_EventStatus;
    Dem_EventStatusType Call_Event_Event_0xD22486_SetEventStatus_EventStatus;
    Dem_EventStatusType Call_Event_Event_0xD22586_SetEventStatus_EventStatus;
    Dem_EventStatusType Call_Event_Event_0xD22686_SetEventStatus_EventStatus;
    Dem_EventStatusType Call_Event_Event_0xD22786_SetEventStatus_EventStatus;
    Dem_EventStatusType Call_Event_Event_0xD23087_SetEventStatus_EventStatus;
    Dem_EventStatusType Call_Event_Event_0xD23187_SetEventStatus_EventStatus;
    Dem_EventStatusType Call_Event_Event_0xD23487_SetEventStatus_EventStatus;
    Dem_EventStatusType Call_Event_Event_0xD23587_SetEventStatus_EventStatus;
    Dem_EventStatusType Call_Event_Event_0xD23687_SetEventStatus_EventStatus;
    /* CC_DiagMsg_SWC_10ms Varaible Define User Code start*/

    /* CC_DiagMsg_SWC_10ms Varaible Define User Code end*/




    Rte_Read_ABSFailed_ABSFailed(&Read_ABSFailed_ABSFailed);
    /* Rte_Read_ABSFailed_ABSFailed User Code start*/

    /* Rte_Read_ABSFailed_ABSFailed User Code end*/
    Rte_Read_ABS_EBDFailed_ABS_EBDFailed(&Read_ABS_EBDFailed_ABS_EBDFailed);
    /* Rte_Read_ABS_EBDFailed_ABS_EBDFailed User Code start*/

    /* Rte_Read_ABS_EBDFailed_ABS_EBDFailed User Code end*/
    Rte_Read_ABS_FLWheelSpeedInvalid_ABS_FLWheelSpeedInvalid(&Read_ABS_FLWheelSpeedInvalid_ABS_FLWheelSpeedInvalid);
    /* Rte_Read_ABS_FLWheelSpeedInvalid_ABS_FLWheelSpeedInvalid User Code start*/

    /* Rte_Read_ABS_FLWheelSpeedInvalid_ABS_FLWheelSpeedInvalid User Code end*/
    Rte_Read_ABS_FLWheelSpeedRCSts_ABS_FLWheelSpeedRCSts(&Read_ABS_FLWheelSpeedRCSts_ABS_FLWheelSpeedRCSts);
    /* Rte_Read_ABS_FLWheelSpeedRCSts_ABS_FLWheelSpeedRCSts User Code start*/

    /* Rte_Read_ABS_FLWheelSpeedRCSts_ABS_FLWheelSpeedRCSts User Code end*/
    Rte_Read_ABS_FRWheelSpeedInvalid_ABS_FRWheelSpeedInvalid(&Read_ABS_FRWheelSpeedInvalid_ABS_FRWheelSpeedInvalid);
    /* Rte_Read_ABS_FRWheelSpeedInvalid_ABS_FRWheelSpeedInvalid User Code start*/

    /* Rte_Read_ABS_FRWheelSpeedInvalid_ABS_FRWheelSpeedInvalid User Code end*/
    Rte_Read_ABS_FRWheelSpeedRCSts_ABS_FRWheelSpeedRCSts(&Read_ABS_FRWheelSpeedRCSts_ABS_FRWheelSpeedRCSts);
    /* Rte_Read_ABS_FRWheelSpeedRCSts_ABS_FRWheelSpeedRCSts User Code start*/

    /* Rte_Read_ABS_FRWheelSpeedRCSts_ABS_FRWheelSpeedRCSts User Code end*/
    Rte_Read_ABS_FWSpeMCUKPH_AliveCounter_ABS_FWSpeMCUKPH_AliveCounter(&Read_ABS_FWSpeMCUKPH_AliveCounter_ABS_FWSpeMCUKPH_AliveCounter);
    /* Rte_Read_ABS_FWSpeMCUKPH_AliveCounter_ABS_FWSpeMCUKPH_AliveCounter User Code start*/

    /* Rte_Read_ABS_FWSpeMCUKPH_AliveCounter_ABS_FWSpeMCUKPH_AliveCounter User Code end*/
    Rte_Read_ABS_FWSpeMCUKPH_CheckSum_ABS_FWSpeMCUKPH_CheckSum(&Read_ABS_FWSpeMCUKPH_CheckSum_ABS_FWSpeMCUKPH_CheckSum);
    /* Rte_Read_ABS_FWSpeMCUKPH_CheckSum_ABS_FWSpeMCUKPH_CheckSum User Code start*/

    /* Rte_Read_ABS_FWSpeMCUKPH_CheckSum_ABS_FWSpeMCUKPH_CheckSum User Code end*/
    Rte_Read_ABS_RLWheelSpeedInvalid_ABS_RLWheelSpeedInvalid(&Read_ABS_RLWheelSpeedInvalid_ABS_RLWheelSpeedInvalid);
    /* Rte_Read_ABS_RLWheelSpeedInvalid_ABS_RLWheelSpeedInvalid User Code start*/

    /* Rte_Read_ABS_RLWheelSpeedInvalid_ABS_RLWheelSpeedInvalid User Code end*/
    Rte_Read_ABS_RLWheelSpeedRCSts_ABS_RLWheelSpeedRCSts(&Read_ABS_RLWheelSpeedRCSts_ABS_RLWheelSpeedRCSts);
    /* Rte_Read_ABS_RLWheelSpeedRCSts_ABS_RLWheelSpeedRCSts User Code start*/

    /* Rte_Read_ABS_RLWheelSpeedRCSts_ABS_RLWheelSpeedRCSts User Code end*/
    Rte_Read_ABS_RRWheelSpeedInvalid_ABS_RRWheelSpeedInvalid(&Read_ABS_RRWheelSpeedInvalid_ABS_RRWheelSpeedInvalid);
    /* Rte_Read_ABS_RRWheelSpeedInvalid_ABS_RRWheelSpeedInvalid User Code start*/

    /* Rte_Read_ABS_RRWheelSpeedInvalid_ABS_RRWheelSpeedInvalid User Code end*/
    Rte_Read_ABS_RRWheelSpeedRCSts_ABS_RRWheelSpeedRCSts(&Read_ABS_RRWheelSpeedRCSts_ABS_RRWheelSpeedRCSts);
    /* Rte_Read_ABS_RRWheelSpeedRCSts_ABS_RRWheelSpeedRCSts User Code start*/

    /* Rte_Read_ABS_RRWheelSpeedRCSts_ABS_RRWheelSpeedRCSts User Code end*/
    Rte_Read_ABS_RWSpeMCUKPH_AliveCounter_ABS_RWSpeMCUKPH_AliveCounter(&Read_ABS_RWSpeMCUKPH_AliveCounter_ABS_RWSpeMCUKPH_AliveCounter);
    /* Rte_Read_ABS_RWSpeMCUKPH_AliveCounter_ABS_RWSpeMCUKPH_AliveCounter User Code start*/

    /* Rte_Read_ABS_RWSpeMCUKPH_AliveCounter_ABS_RWSpeMCUKPH_AliveCounter User Code end*/
    Rte_Read_ABS_RWSpeMCUKPH_CheckSum_ABS_RWSpeMCUKPH_CheckSum(&Read_ABS_RWSpeMCUKPH_CheckSum_ABS_RWSpeMCUKPH_CheckSum);
    /* Rte_Read_ABS_RWSpeMCUKPH_CheckSum_ABS_RWSpeMCUKPH_CheckSum User Code start*/

    /* Rte_Read_ABS_RWSpeMCUKPH_CheckSum_ABS_RWSpeMCUKPH_CheckSum User Code end*/
    Rte_Read_ABS_Status_AliveCounter_ABS_Status_AliveCounter(&Read_ABS_Status_AliveCounter_ABS_Status_AliveCounter);
    /* Rte_Read_ABS_Status_AliveCounter_ABS_Status_AliveCounter User Code start*/

    /* Rte_Read_ABS_Status_AliveCounter_ABS_Status_AliveCounter User Code end*/
    Rte_Read_ABS_Status_CheckSum_ABS_Status_CheckSum(&Read_ABS_Status_CheckSum_ABS_Status_CheckSum);
    /* Rte_Read_ABS_Status_CheckSum_ABS_Status_CheckSum User Code start*/

    /* Rte_Read_ABS_Status_CheckSum_ABS_Status_CheckSum User Code end*/
    Rte_Read_ABS_VehicleSpeedInvalid_ABS_VehicleSpeedInvalid(&Read_ABS_VehicleSpeedInvalid_ABS_VehicleSpeedInvalid);
    /* Rte_Read_ABS_VehicleSpeedInvalid_ABS_VehicleSpeedInvalid User Code start*/

    /* Rte_Read_ABS_VehicleSpeedInvalid_ABS_VehicleSpeedInvalid User Code end*/
    Rte_Read_ABS_WheelSpeMCURC_AliveCounter_ABS_WheelSpeMCURC_AliveCounter(&Read_ABS_WheelSpeMCURC_AliveCounter_ABS_WheelSpeMCURC_AliveCounter);
    /* Rte_Read_ABS_WheelSpeMCURC_AliveCounter_ABS_WheelSpeMCURC_AliveCounter User Code start*/

    /* Rte_Read_ABS_WheelSpeMCURC_AliveCounter_ABS_WheelSpeMCURC_AliveCounter User Code end*/
    Rte_Read_ABS_WheelSpeMCURC_CheckSum_ABS_WheelSpeMCURC_CheckSum(&Read_ABS_WheelSpeMCURC_CheckSum_ABS_WheelSpeMCURC_CheckSum);
    /* Rte_Read_ABS_WheelSpeMCURC_CheckSum_ABS_WheelSpeMCURC_CheckSum User Code start*/

    /* Rte_Read_ABS_WheelSpeMCURC_CheckSum_ABS_WheelSpeMCURC_CheckSum User Code end*/
    Rte_Read_AB_BrkPedalSwStsV_AB_BrkPedalSwStsV(&Read_AB_BrkPedalSwStsV_AB_BrkPedalSwStsV);
    /* Rte_Read_AB_BrkPedalSwStsV_AB_BrkPedalSwStsV User Code start*/

    /* Rte_Read_AB_BrkPedalSwStsV_AB_BrkPedalSwStsV User Code end*/
    Rte_Read_AB_Fault_Status_AB_Fault_Status(&Read_AB_Fault_Status_AB_Fault_Status);
    /* Rte_Read_AB_Fault_Status_AB_Fault_Status User Code start*/

    /* Rte_Read_AB_Fault_Status_AB_Fault_Status User Code end*/
    Rte_Read_ACU_AliveCounter_ACU_AliveCounter(&Read_ACU_AliveCounter_ACU_AliveCounter);
    /* Rte_Read_ACU_AliveCounter_ACU_AliveCounter User Code start*/

    /* Rte_Read_ACU_AliveCounter_ACU_AliveCounter User Code end*/
    Rte_Read_ACU_CheckSum_ACU_CheckSum(&Read_ACU_CheckSum_ACU_CheckSum);
    /* Rte_Read_ACU_CheckSum_ACU_CheckSum User Code start*/

    /* Rte_Read_ACU_CheckSum_ACU_CheckSum User Code end*/
    Rte_Read_BCM_TurnLight_FaultSts_BCM_TurnLight_FaultSts(&Read_BCM_TurnLight_FaultSts_BCM_TurnLight_FaultSts);
    /* Rte_Read_BCM_TurnLight_FaultSts_BCM_TurnLight_FaultSts User Code start*/

    /* Rte_Read_BCM_TurnLight_FaultSts_BCM_TurnLight_FaultSts User Code end*/
    Rte_Read_CCU_ExternalTemperatureFailSts_CCU_ExternalTemperatureFailSts(&Read_CCU_ExternalTemperatureFailSts_CCU_ExternalTemperatureFailSts);
    /* Rte_Read_CCU_ExternalTemperatureFailSts_CCU_ExternalTemperatureFailSts User Code start*/

    /* Rte_Read_CCU_ExternalTemperatureFailSts_CCU_ExternalTemperatureFailSts User Code end*/
    Rte_Read_CheckSum_0x106_CheckSum_0x106(&Read_CheckSum_0x106_CheckSum_0x106);
    /* Rte_Read_CheckSum_0x106_CheckSum_0x106 User Code start*/

    /* Rte_Read_CheckSum_0x106_CheckSum_0x106 User Code end*/
    Rte_Read_CheckSum_0x109_CheckSum_0x109(&Read_CheckSum_0x109_CheckSum_0x109);
    /* Rte_Read_CheckSum_0x109_CheckSum_0x109 User Code start*/

    /* Rte_Read_CheckSum_0x109_CheckSum_0x109 User Code end*/
    Rte_Read_CheckSum_0x17F_CheckSum_0x17F(&Read_CheckSum_0x17F_CheckSum_0x17F);
    /* Rte_Read_CheckSum_0x17F_CheckSum_0x17F User Code start*/

    /* Rte_Read_CheckSum_0x17F_CheckSum_0x17F User Code end*/
    Rte_Read_CheckSum_0x3F1_CheckSum_0x3F1(&Read_CheckSum_0x3F1_CheckSum_0x3F1);
    /* Rte_Read_CheckSum_0x3F1_CheckSum_0x3F1 User Code start*/

    /* Rte_Read_CheckSum_0x3F1_CheckSum_0x3F1 User Code end*/
    Rte_Read_CheckSum_0x3F7_CheckSum_0x3F7(&Read_CheckSum_0x3F7_CheckSum_0x3F7);
    /* Rte_Read_CheckSum_0x3F7_CheckSum_0x3F7 User Code start*/

    /* Rte_Read_CheckSum_0x3F7_CheckSum_0x3F7 User Code end*/
    Rte_Read_Checksum_0x132_Checksum_0x132(&Read_Checksum_0x132_Checksum_0x132);
    /* Rte_Read_Checksum_0x132_Checksum_0x132 User Code start*/

    /* Rte_Read_Checksum_0x132_Checksum_0x132 User Code end*/
    Rte_Read_Checksum_0x17E_Checksum_0x17E(&Read_Checksum_0x17E_Checksum_0x17E);
    /* Rte_Read_Checksum_0x17E_Checksum_0x17E User Code start*/

    /* Rte_Read_Checksum_0x17E_Checksum_0x17E User Code end*/
    Rte_Read_Checksum_0x3E2_Checksum_0x3E2(&Read_Checksum_0x3E2_Checksum_0x3E2);
    /* Rte_Read_Checksum_0x3E2_Checksum_0x3E2 User Code start*/

    /* Rte_Read_Checksum_0x3E2_Checksum_0x3E2 User Code end*/
    Rte_Read_Checksum_230_Checksum_230(&Read_Checksum_230_Checksum_230);
    /* Rte_Read_Checksum_230_Checksum_230 User Code start*/

    /* Rte_Read_Checksum_230_Checksum_230 User Code end*/
    Rte_Read_EPS_ADAS_ModAvail_EPS_ADAS_ModAvail(&Read_EPS_ADAS_ModAvail_EPS_ADAS_ModAvail);
    /* Rte_Read_EPS_ADAS_ModAvail_EPS_ADAS_ModAvail User Code start*/

    /* Rte_Read_EPS_ADAS_ModAvail_EPS_ADAS_ModAvail User Code end*/
    Rte_Read_ESC_LateralACC_Valid_ESC_LateralACC_Valid(&Read_ESC_LateralACC_Valid_ESC_LateralACC_Valid);
    /* Rte_Read_ESC_LateralACC_Valid_ESC_LateralACC_Valid User Code start*/

    /* Rte_Read_ESC_LateralACC_Valid_ESC_LateralACC_Valid User Code end*/
    Rte_Read_ESC_LongitudeACC_Valid_ESC_LongitudeACC_Valid(&Read_ESC_LongitudeACC_Valid_ESC_LongitudeACC_Valid);
    /* Rte_Read_ESC_LongitudeACC_Valid_ESC_LongitudeACC_Valid User Code start*/

    /* Rte_Read_ESC_LongitudeACC_Valid_ESC_LongitudeACC_Valid User Code end*/
    Rte_Read_ESC_MasterCylinderPressureV_ESC_MasterCylinderPressureV(&Read_ESC_MasterCylinderPressureV_ESC_MasterCylinderPressureV);
    /* Rte_Read_ESC_MasterCylinderPressureV_ESC_MasterCylinderPressureV User Code start*/

    /* Rte_Read_ESC_MasterCylinderPressureV_ESC_MasterCylinderPressureV User Code end*/
    Rte_Read_ESC_VehDynYawRate_Valid_ESC_VehDynYawRate_Valid(&Read_ESC_VehDynYawRate_Valid_ESC_VehDynYawRate_Valid);
    /* Rte_Read_ESC_VehDynYawRate_Valid_ESC_VehDynYawRate_Valid User Code start*/

    /* Rte_Read_ESC_VehDynYawRate_Valid_ESC_VehDynYawRate_Valid User Code end*/
    Rte_Read_MFS_L2_Failure_MFS_L2_Failure(&Read_MFS_L2_Failure_MFS_L2_Failure);
    /* Rte_Read_MFS_L2_Failure_MFS_L2_Failure User Code start*/

    /* Rte_Read_MFS_L2_Failure_MFS_L2_Failure User Code end*/
    Rte_Read_Nav_Error_Nav_errorSts(&Read_Nav_Error_Nav_errorSts);
    /* Rte_Read_Nav_Error_Nav_errorSts User Code start*/

    /* Rte_Read_Nav_Error_Nav_errorSts User Code end*/
    Rte_Read_PEPS_IGN1RelayValidity_PEPS_IGN1RelayValidity(&Read_PEPS_IGN1RelayValidity_PEPS_IGN1RelayValidity);
    /* Rte_Read_PEPS_IGN1RelayValidity_PEPS_IGN1RelayValidity User Code start*/

    /* Rte_Read_PEPS_IGN1RelayValidity_PEPS_IGN1RelayValidity User Code end*/
    Rte_Read_PEPS_Message_Sts_AliveCounter_PEPS_Message_Sts_AliveCounter(&Read_PEPS_Message_Sts_AliveCounter_PEPS_Message_Sts_AliveCounter);
    /* Rte_Read_PEPS_Message_Sts_AliveCounter_PEPS_Message_Sts_AliveCounter User Code start*/

    /* Rte_Read_PEPS_Message_Sts_AliveCounter_PEPS_Message_Sts_AliveCounter User Code end*/
    Rte_Read_PEPS_Message_Sts_CheckSum_PEPS_Message_Sts_CheckSum(&Read_PEPS_Message_Sts_CheckSum_PEPS_Message_Sts_CheckSum);
    /* Rte_Read_PEPS_Message_Sts_CheckSum_PEPS_Message_Sts_CheckSum User Code start*/

    /* Rte_Read_PEPS_Message_Sts_CheckSum_PEPS_Message_Sts_CheckSum User Code end*/
    Rte_Read_PEPS_PowerModeValidity_PEPS_PowerModeValidity(&Read_PEPS_PowerModeValidity_PEPS_PowerModeValidity);
    /* Rte_Read_PEPS_PowerModeValidity_PEPS_PowerModeValidity User Code start*/

    /* Rte_Read_PEPS_PowerModeValidity_PEPS_PowerModeValidity User Code end*/
    Rte_Read_RollingCounter_0x106_RollingCounter_0x106(&Read_RollingCounter_0x106_RollingCounter_0x106);
    /* Rte_Read_RollingCounter_0x106_RollingCounter_0x106 User Code start*/

    /* Rte_Read_RollingCounter_0x106_RollingCounter_0x106 User Code end*/
    Rte_Read_RollingCounter_0x109_RollingCounter_0x109(&Read_RollingCounter_0x109_RollingCounter_0x109);
    /* Rte_Read_RollingCounter_0x109_RollingCounter_0x109 User Code start*/

    /* Rte_Read_RollingCounter_0x109_RollingCounter_0x109 User Code end*/
    Rte_Read_RollingCounter_0x132_RollingCounter_0x132(&Read_RollingCounter_0x132_RollingCounter_0x132);
    /* Rte_Read_RollingCounter_0x132_RollingCounter_0x132 User Code start*/

    /* Rte_Read_RollingCounter_0x132_RollingCounter_0x132 User Code end*/
    Rte_Read_RollingCounter_0x17F_RollingCounter_0x17F(&Read_RollingCounter_0x17F_RollingCounter_0x17F);
    /* Rte_Read_RollingCounter_0x17F_RollingCounter_0x17F User Code start*/

    /* Rte_Read_RollingCounter_0x17F_RollingCounter_0x17F User Code end*/
    Rte_Read_RollingCounter_0x3E2_RollingCounter_0x3E2(&Read_RollingCounter_0x3E2_RollingCounter_0x3E2);
    /* Rte_Read_RollingCounter_0x3E2_RollingCounter_0x3E2 User Code start*/

    /* Rte_Read_RollingCounter_0x3E2_RollingCounter_0x3E2 User Code end*/
    Rte_Read_RollingCounter_0x3F1_RollingCounter_0x3F1(&Read_RollingCounter_0x3F1_RollingCounter_0x3F1);
    /* Rte_Read_RollingCounter_0x3F1_RollingCounter_0x3F1 User Code start*/

    /* Rte_Read_RollingCounter_0x3F1_RollingCounter_0x3F1 User Code end*/
    Rte_Read_RollingCounter_0x3F7_RollingCounter_0x3F7(&Read_RollingCounter_0x3F7_RollingCounter_0x3F7);
    /* Rte_Read_RollingCounter_0x3F7_RollingCounter_0x3F7 User Code start*/

    /* Rte_Read_RollingCounter_0x3F7_RollingCounter_0x3F7 User Code end*/
    Rte_Read_RollingCounter_230_RollingCounter_230(&Read_RollingCounter_230_RollingCounter_230);
    /* Rte_Read_RollingCounter_230_RollingCounter_230 User Code start*/

    /* Rte_Read_RollingCounter_230_RollingCounter_230 User Code end*/
    Rte_Read_Rolling_counter_0x17E_Rolling_counter_0x17E(&Read_Rolling_counter_0x17E_Rolling_counter_0x17E);
    /* Rte_Read_Rolling_counter_0x17E_Rolling_counter_0x17E User Code start*/

    /* Rte_Read_Rolling_counter_0x17E_Rolling_counter_0x17E User Code end*/
    Rte_Read_SAS_Calibrated_SAS_Calibrated(&Read_SAS_Calibrated_SAS_Calibrated);
    /* Rte_Read_SAS_Calibrated_SAS_Calibrated User Code start*/

    /* Rte_Read_SAS_Calibrated_SAS_Calibrated User Code end*/
    Rte_Read_SAS_SASFailure_SAS_SASFailure(&Read_SAS_SASFailure_SAS_SASFailure);
    /* Rte_Read_SAS_SASFailure_SAS_SASFailure User Code start*/

    /* Rte_Read_SAS_SASFailure_SAS_SASFailure User Code end*/
    Rte_Read_SAS_SASStsSnsr_SAS_SASStsSnsr(&Read_SAS_SASStsSnsr_SAS_SASStsSnsr);
    /* Rte_Read_SAS_SASStsSnsr_SAS_SASStsSnsr User Code start*/

    /* Rte_Read_SAS_SASStsSnsr_SAS_SASStsSnsr User Code end*/
    Rte_Read_SAS_SteerWhlRotSpdStatus_SAS_SteerWhlRotSpdStatus(&Read_SAS_SteerWhlRotSpdStatus_SAS_SteerWhlRotSpdStatus);
    /* Rte_Read_SAS_SteerWhlRotSpdStatus_SAS_SteerWhlRotSpdStatus User Code start*/

    /* Rte_Read_SAS_SteerWhlRotSpdStatus_SAS_SteerWhlRotSpdStatus User Code end*/
    Rte_Read_SAS_SteeringAngleValid_SAS_SteeringAngleValid(&Read_SAS_SteeringAngleValid_SAS_SteeringAngleValid);
    /* Rte_Read_SAS_SteeringAngleValid_SAS_SteeringAngleValid User Code start*/

    /* Rte_Read_SAS_SteeringAngleValid_SAS_SteeringAngleValid User Code end*/
    Rte_Read_TPMS_LFpressureV_TPMS_LFpressureV(&Read_TPMS_LFpressureV_TPMS_LFpressureV);
    /* Rte_Read_TPMS_LFpressureV_TPMS_LFpressureV User Code start*/

    /* Rte_Read_TPMS_LFpressureV_TPMS_LFpressureV User Code end*/
    Rte_Read_TPMS_LRpressureV_TPMS_LRpressureV(&Read_TPMS_LRpressureV_TPMS_LRpressureV);
    /* Rte_Read_TPMS_LRpressureV_TPMS_LRpressureV User Code start*/

    /* Rte_Read_TPMS_LRpressureV_TPMS_LRpressureV User Code end*/
    Rte_Read_TPMS_RFpressureV_TPMS_RFpressureV(&Read_TPMS_RFpressureV_TPMS_RFpressureV);
    /* Rte_Read_TPMS_RFpressureV_TPMS_RFpressureV User Code start*/

    /* Rte_Read_TPMS_RFpressureV_TPMS_RFpressureV User Code end*/
    Rte_Read_TPMS_RRpressureV_TPMS_RRpressureV(&Read_TPMS_RRpressureV_TPMS_RRpressureV);
    /* Rte_Read_TPMS_RRpressureV_TPMS_RRpressureV User Code start*/

    /* Rte_Read_TPMS_RRpressureV_TPMS_RRpressureV User Code end*/
    Rte_Read_VCU_AccPedal_Valid_VCU_AccPedal_Valid(&Read_VCU_AccPedal_Valid_VCU_AccPedal_Valid);
    /* Rte_Read_VCU_AccPedal_Valid_VCU_AccPedal_Valid User Code start*/

    /* Rte_Read_VCU_AccPedal_Valid_VCU_AccPedal_Valid User Code end*/
    Rte_Read_VCU_Ctrl_AliveCounter_VCU_Ctrl_AliveCounter(&Read_VCU_Ctrl_AliveCounter_VCU_Ctrl_AliveCounter);
    /* Rte_Read_VCU_Ctrl_AliveCounter_VCU_Ctrl_AliveCounter User Code start*/

    /* Rte_Read_VCU_Ctrl_AliveCounter_VCU_Ctrl_AliveCounter User Code end*/
    Rte_Read_VCU_Ctrl_CheckSum_VCU_Ctrl_CheckSum(&Read_VCU_Ctrl_CheckSum_VCU_Ctrl_CheckSum);
    /* Rte_Read_VCU_Ctrl_CheckSum_VCU_Ctrl_CheckSum User Code start*/

    /* Rte_Read_VCU_Ctrl_CheckSum_VCU_Ctrl_CheckSum User Code end*/
    Rte_Read_VCU_ModeGearSts_VCU_ModeGearSts(&Read_VCU_ModeGearSts_VCU_ModeGearSts);
    /* Rte_Read_VCU_ModeGearSts_VCU_ModeGearSts User Code start*/

    /* Rte_Read_VCU_ModeGearSts_VCU_ModeGearSts User Code end*/
    Rte_Read_VCU_StsEpt_AliveCounter_VCU_StsEpt_AliveCounter(&Read_VCU_StsEpt_AliveCounter_VCU_StsEpt_AliveCounter);
    /* Rte_Read_VCU_StsEpt_AliveCounter_VCU_StsEpt_AliveCounter User Code start*/

    /* Rte_Read_VCU_StsEpt_AliveCounter_VCU_StsEpt_AliveCounter User Code end*/
    Rte_Read_VCU_StsEpt_CheckSum_VCU_StsEpt_CheckSum(&Read_VCU_StsEpt_CheckSum_VCU_StsEpt_CheckSum);
    /* Rte_Read_VCU_StsEpt_CheckSum_VCU_StsEpt_CheckSum User Code start*/

    /* Rte_Read_VCU_StsEpt_CheckSum_VCU_StsEpt_CheckSum User Code end*/
    Rte_Read_WCBS_ABAAva_WCBS_ABAAva(&Read_WCBS_ABAAva_WCBS_ABAAva);
    /* Rte_Read_WCBS_ABAAva_WCBS_ABAAva User Code start*/

    /* Rte_Read_WCBS_ABAAva_WCBS_ABAAva User Code end*/
    Rte_Read_WCBS_ABPAva_WCBS_ABPAva(&Read_WCBS_ABPAva_WCBS_ABPAva);
    /* Rte_Read_WCBS_ABPAva_WCBS_ABPAva User Code start*/

    /* Rte_Read_WCBS_ABPAva_WCBS_ABPAva User Code end*/
    Rte_Read_WCBS_ACC_VLC_Avl_WCBS_ACC_VLC_Avl(&Read_WCBS_ACC_VLC_Avl_WCBS_ACC_VLC_Avl);
    /* Rte_Read_WCBS_ACC_VLC_Avl_WCBS_ACC_VLC_Avl User Code start*/

    /* Rte_Read_WCBS_ACC_VLC_Avl_WCBS_ACC_VLC_Avl User Code end*/
    Rte_Read_WCBS_AEBAva_WCBS_AEBAva(&Read_WCBS_AEBAva_WCBS_AEBAva);
    /* Rte_Read_WCBS_AEBAva_WCBS_AEBAva User Code start*/

    /* Rte_Read_WCBS_AEBAva_WCBS_AEBAva User Code end*/
    Rte_Read_WCBS_AWBAvl_WCBS_AWBAvl(&Read_WCBS_AWBAvl_WCBS_AWBAvl);
    /* Rte_Read_WCBS_AWBAvl_WCBS_AWBAvl User Code start*/

    /* Rte_Read_WCBS_AWBAvl_WCBS_AWBAvl User Code end*/
    Rte_Read_WCBS_ESCDeteACCErroSta_WCBS_ESCDeteACCErroSta(&Read_WCBS_ESCDeteACCErroSta_WCBS_ESCDeteACCErroSta);
    /* Rte_Read_WCBS_ESCDeteACCErroSta_WCBS_ESCDeteACCErroSta User Code start*/

    /* Rte_Read_WCBS_ESCDeteACCErroSta_WCBS_ESCDeteACCErroSta User Code end*/
    Rte_Call_Event_Event_0x9401A3_SetEventStatus(Call_Event_Event_0x9401A3_SetEventStatus_EventStatus);
    /* Rte_Call_Event_Event_0x9401A3_SetEventStatus User Code start*/

    /* Rte_Call_Event_Event_0x9401A3_SetEventStatus User Code end*/
    Rte_Call_Event_Event_0x940354_SetEventStatus(Call_Event_Event_0x940354_SetEventStatus_EventStatus);
    /* Rte_Call_Event_Event_0x940354_SetEventStatus User Code start*/

    /* Rte_Call_Event_Event_0x940354_SetEventStatus User Code end*/
    Rte_Call_Event_Event_0x940406_SetEventStatus(Call_Event_Event_0x940406_SetEventStatus_EventStatus);
    /* Rte_Call_Event_Event_0x940406_SetEventStatus User Code start*/

    /* Rte_Call_Event_Event_0x940406_SetEventStatus User Code end*/
    Rte_Call_Event_Event_0x942009_SetEventStatus(Call_Event_Event_0x942009_SetEventStatus_EventStatus);
    /* Rte_Call_Event_Event_0x942009_SetEventStatus User Code start*/

    /* Rte_Call_Event_Event_0x942009_SetEventStatus User Code end*/
    Rte_Call_Event_Event_0x942209_SetEventStatus(Call_Event_Event_0x942209_SetEventStatus_EventStatus);
    /* Rte_Call_Event_Event_0x942209_SetEventStatus User Code start*/

    /* Rte_Call_Event_Event_0x942209_SetEventStatus User Code end*/
    Rte_Call_Event_Event_0x942309_SetEventStatus(Call_Event_Event_0x942309_SetEventStatus_EventStatus);
    /* Rte_Call_Event_Event_0x942309_SetEventStatus User Code start*/

    /* Rte_Call_Event_Event_0x942309_SetEventStatus User Code end*/
    Rte_Call_Event_Event_0x942409_SetEventStatus(Call_Event_Event_0x942409_SetEventStatus_EventStatus);
    /* Rte_Call_Event_Event_0x942409_SetEventStatus User Code start*/

    /* Rte_Call_Event_Event_0x942409_SetEventStatus User Code end*/
    Rte_Call_Event_Event_0x942509_SetEventStatus(Call_Event_Event_0x942509_SetEventStatus_EventStatus);
    /* Rte_Call_Event_Event_0x942509_SetEventStatus User Code start*/

    /* Rte_Call_Event_Event_0x942509_SetEventStatus User Code end*/
    Rte_Call_Event_Event_0x942609_SetEventStatus(Call_Event_Event_0x942609_SetEventStatus_EventStatus);
    /* Rte_Call_Event_Event_0x942609_SetEventStatus User Code start*/

    /* Rte_Call_Event_Event_0x942609_SetEventStatus User Code end*/
    Rte_Call_Event_Event_0x942D09_SetEventStatus(Call_Event_Event_0x942D09_SetEventStatus_EventStatus);
    /* Rte_Call_Event_Event_0x942D09_SetEventStatus User Code start*/

    /* Rte_Call_Event_Event_0x942D09_SetEventStatus User Code end*/
    Rte_Call_Event_Event_0x942F09_SetEventStatus(Call_Event_Event_0x942F09_SetEventStatus_EventStatus);
    /* Rte_Call_Event_Event_0x942F09_SetEventStatus User Code start*/

    /* Rte_Call_Event_Event_0x942F09_SetEventStatus User Code end*/
    Rte_Call_Event_Event_0x943009_SetEventStatus(Call_Event_Event_0x943009_SetEventStatus_EventStatus);
    /* Rte_Call_Event_Event_0x943009_SetEventStatus User Code start*/

    /* Rte_Call_Event_Event_0x943009_SetEventStatus User Code end*/
    Rte_Call_Event_Event_0xD20008_SetEventStatus(Call_Event_Event_0xD20008_SetEventStatus_EventStatus);
    /* Rte_Call_Event_Event_0xD20008_SetEventStatus User Code start*/

    /* Rte_Call_Event_Event_0xD20008_SetEventStatus User Code end*/
    Rte_Call_Event_Event_0xD20086_SetEventStatus(Call_Event_Event_0xD20086_SetEventStatus_EventStatus);
    /* Rte_Call_Event_Event_0xD20086_SetEventStatus User Code start*/

    /* Rte_Call_Event_Event_0xD20086_SetEventStatus User Code end*/
    Rte_Call_Event_Event_0xD20087_SetEventStatus(Call_Event_Event_0xD20087_SetEventStatus_EventStatus);
    /* Rte_Call_Event_Event_0xD20087_SetEventStatus User Code start*/

    /* Rte_Call_Event_Event_0xD20087_SetEventStatus User Code end*/
    Rte_Call_Event_Event_0xD20108_SetEventStatus(Call_Event_Event_0xD20108_SetEventStatus_EventStatus);
    /* Rte_Call_Event_Event_0xD20108_SetEventStatus User Code start*/

    /* Rte_Call_Event_Event_0xD20108_SetEventStatus User Code end*/
    Rte_Call_Event_Event_0xD20186_SetEventStatus(Call_Event_Event_0xD20186_SetEventStatus_EventStatus);
    /* Rte_Call_Event_Event_0xD20186_SetEventStatus User Code start*/

    /* Rte_Call_Event_Event_0xD20186_SetEventStatus User Code end*/
    Rte_Call_Event_Event_0xD20187_SetEventStatus(Call_Event_Event_0xD20187_SetEventStatus_EventStatus);
    /* Rte_Call_Event_Event_0xD20187_SetEventStatus User Code start*/

    /* Rte_Call_Event_Event_0xD20187_SetEventStatus User Code end*/
    Rte_Call_Event_Event_0xD20208_SetEventStatus(Call_Event_Event_0xD20208_SetEventStatus_EventStatus);
    /* Rte_Call_Event_Event_0xD20208_SetEventStatus User Code start*/

    /* Rte_Call_Event_Event_0xD20208_SetEventStatus User Code end*/
    Rte_Call_Event_Event_0xD20286_SetEventStatus(Call_Event_Event_0xD20286_SetEventStatus_EventStatus);
    /* Rte_Call_Event_Event_0xD20286_SetEventStatus User Code start*/

    /* Rte_Call_Event_Event_0xD20286_SetEventStatus User Code end*/
    Rte_Call_Event_Event_0xD20287_SetEventStatus(Call_Event_Event_0xD20287_SetEventStatus_EventStatus);
    /* Rte_Call_Event_Event_0xD20287_SetEventStatus User Code start*/

    /* Rte_Call_Event_Event_0xD20287_SetEventStatus User Code end*/
    Rte_Call_Event_Event_0xD20308_SetEventStatus(Call_Event_Event_0xD20308_SetEventStatus_EventStatus);
    /* Rte_Call_Event_Event_0xD20308_SetEventStatus User Code start*/

    /* Rte_Call_Event_Event_0xD20308_SetEventStatus User Code end*/
    Rte_Call_Event_Event_0xD20386_SetEventStatus(Call_Event_Event_0xD20386_SetEventStatus_EventStatus);
    /* Rte_Call_Event_Event_0xD20386_SetEventStatus User Code start*/

    /* Rte_Call_Event_Event_0xD20386_SetEventStatus User Code end*/
    Rte_Call_Event_Event_0xD20387_SetEventStatus(Call_Event_Event_0xD20387_SetEventStatus_EventStatus);
    /* Rte_Call_Event_Event_0xD20387_SetEventStatus User Code start*/

    /* Rte_Call_Event_Event_0xD20387_SetEventStatus User Code end*/
    Rte_Call_Event_Event_0xD20408_SetEventStatus(Call_Event_Event_0xD20408_SetEventStatus_EventStatus);
    /* Rte_Call_Event_Event_0xD20408_SetEventStatus User Code start*/

    /* Rte_Call_Event_Event_0xD20408_SetEventStatus User Code end*/
    Rte_Call_Event_Event_0xD20486_SetEventStatus(Call_Event_Event_0xD20486_SetEventStatus_EventStatus);
    /* Rte_Call_Event_Event_0xD20486_SetEventStatus User Code start*/

    /* Rte_Call_Event_Event_0xD20486_SetEventStatus User Code end*/
    Rte_Call_Event_Event_0xD20508_SetEventStatus(Call_Event_Event_0xD20508_SetEventStatus_EventStatus);
    /* Rte_Call_Event_Event_0xD20508_SetEventStatus User Code start*/

    /* Rte_Call_Event_Event_0xD20508_SetEventStatus User Code end*/
    Rte_Call_Event_Event_0xD20586_SetEventStatus(Call_Event_Event_0xD20586_SetEventStatus_EventStatus);
    /* Rte_Call_Event_Event_0xD20586_SetEventStatus User Code start*/

    /* Rte_Call_Event_Event_0xD20586_SetEventStatus User Code end*/
    Rte_Call_Event_Event_0xD20608_SetEventStatus(Call_Event_Event_0xD20608_SetEventStatus_EventStatus);
    /* Rte_Call_Event_Event_0xD20608_SetEventStatus User Code start*/

    /* Rte_Call_Event_Event_0xD20608_SetEventStatus User Code end*/
    Rte_Call_Event_Event_0xD20686_SetEventStatus(Call_Event_Event_0xD20686_SetEventStatus_EventStatus);
    /* Rte_Call_Event_Event_0xD20686_SetEventStatus User Code start*/

    /* Rte_Call_Event_Event_0xD20686_SetEventStatus User Code end*/
    Rte_Call_Event_Event_0xD20708_SetEventStatus(Call_Event_Event_0xD20708_SetEventStatus_EventStatus);
    /* Rte_Call_Event_Event_0xD20708_SetEventStatus User Code start*/

    /* Rte_Call_Event_Event_0xD20708_SetEventStatus User Code end*/
    Rte_Call_Event_Event_0xD20786_SetEventStatus(Call_Event_Event_0xD20786_SetEventStatus_EventStatus);
    /* Rte_Call_Event_Event_0xD20786_SetEventStatus User Code start*/

    /* Rte_Call_Event_Event_0xD20786_SetEventStatus User Code end*/
    Rte_Call_Event_Event_0xD20808_SetEventStatus(Call_Event_Event_0xD20808_SetEventStatus_EventStatus);
    /* Rte_Call_Event_Event_0xD20808_SetEventStatus User Code start*/

    /* Rte_Call_Event_Event_0xD20808_SetEventStatus User Code end*/
    Rte_Call_Event_Event_0xD20886_SetEventStatus(Call_Event_Event_0xD20886_SetEventStatus_EventStatus);
    /* Rte_Call_Event_Event_0xD20886_SetEventStatus User Code start*/

    /* Rte_Call_Event_Event_0xD20886_SetEventStatus User Code end*/
    Rte_Call_Event_Event_0xD20908_SetEventStatus(Call_Event_Event_0xD20908_SetEventStatus_EventStatus);
    /* Rte_Call_Event_Event_0xD20908_SetEventStatus User Code start*/

    /* Rte_Call_Event_Event_0xD20908_SetEventStatus User Code end*/
    Rte_Call_Event_Event_0xD20986_SetEventStatus(Call_Event_Event_0xD20986_SetEventStatus_EventStatus);
    /* Rte_Call_Event_Event_0xD20986_SetEventStatus User Code start*/

    /* Rte_Call_Event_Event_0xD20986_SetEventStatus User Code end*/
    Rte_Call_Event_Event_0xD20A08_SetEventStatus(Call_Event_Event_0xD20A08_SetEventStatus_EventStatus);
    /* Rte_Call_Event_Event_0xD20A08_SetEventStatus User Code start*/

    /* Rte_Call_Event_Event_0xD20A08_SetEventStatus User Code end*/
    Rte_Call_Event_Event_0xD20A86_SetEventStatus(Call_Event_Event_0xD20A86_SetEventStatus_EventStatus);
    /* Rte_Call_Event_Event_0xD20A86_SetEventStatus User Code start*/

    /* Rte_Call_Event_Event_0xD20A86_SetEventStatus User Code end*/
    Rte_Call_Event_Event_0xD20B08_SetEventStatus(Call_Event_Event_0xD20B08_SetEventStatus_EventStatus);
    /* Rte_Call_Event_Event_0xD20B08_SetEventStatus User Code start*/

    /* Rte_Call_Event_Event_0xD20B08_SetEventStatus User Code end*/
    Rte_Call_Event_Event_0xD20B86_SetEventStatus(Call_Event_Event_0xD20B86_SetEventStatus_EventStatus);
    /* Rte_Call_Event_Event_0xD20B86_SetEventStatus User Code start*/

    /* Rte_Call_Event_Event_0xD20B86_SetEventStatus User Code end*/
    Rte_Call_Event_Event_0xD20C08_SetEventStatus(Call_Event_Event_0xD20C08_SetEventStatus_EventStatus);
    /* Rte_Call_Event_Event_0xD20C08_SetEventStatus User Code start*/

    /* Rte_Call_Event_Event_0xD20C08_SetEventStatus User Code end*/
    Rte_Call_Event_Event_0xD20C86_SetEventStatus(Call_Event_Event_0xD20C86_SetEventStatus_EventStatus);
    /* Rte_Call_Event_Event_0xD20C86_SetEventStatus User Code start*/

    /* Rte_Call_Event_Event_0xD20C86_SetEventStatus User Code end*/
    Rte_Call_Event_Event_0xD20D08_SetEventStatus(Call_Event_Event_0xD20D08_SetEventStatus_EventStatus);
    /* Rte_Call_Event_Event_0xD20D08_SetEventStatus User Code start*/

    /* Rte_Call_Event_Event_0xD20D08_SetEventStatus User Code end*/
    Rte_Call_Event_Event_0xD20D86_SetEventStatus(Call_Event_Event_0xD20D86_SetEventStatus_EventStatus);
    /* Rte_Call_Event_Event_0xD20D86_SetEventStatus User Code start*/

    /* Rte_Call_Event_Event_0xD20D86_SetEventStatus User Code end*/
    Rte_Call_Event_Event_0xD20E08_SetEventStatus(Call_Event_Event_0xD20E08_SetEventStatus_EventStatus);
    /* Rte_Call_Event_Event_0xD20E08_SetEventStatus User Code start*/

    /* Rte_Call_Event_Event_0xD20E08_SetEventStatus User Code end*/
    Rte_Call_Event_Event_0xD20E86_SetEventStatus(Call_Event_Event_0xD20E86_SetEventStatus_EventStatus);
    /* Rte_Call_Event_Event_0xD20E86_SetEventStatus User Code start*/

    /* Rte_Call_Event_Event_0xD20E86_SetEventStatus User Code end*/
    Rte_Call_Event_Event_0xD20F08_SetEventStatus(Call_Event_Event_0xD20F08_SetEventStatus_EventStatus);
    /* Rte_Call_Event_Event_0xD20F08_SetEventStatus User Code start*/

    /* Rte_Call_Event_Event_0xD20F08_SetEventStatus User Code end*/
    Rte_Call_Event_Event_0xD20F86_SetEventStatus(Call_Event_Event_0xD20F86_SetEventStatus_EventStatus);
    /* Rte_Call_Event_Event_0xD20F86_SetEventStatus User Code start*/

    /* Rte_Call_Event_Event_0xD20F86_SetEventStatus User Code end*/
    Rte_Call_Event_Event_0xD21008_SetEventStatus(Call_Event_Event_0xD21008_SetEventStatus_EventStatus);
    /* Rte_Call_Event_Event_0xD21008_SetEventStatus User Code start*/

    /* Rte_Call_Event_Event_0xD21008_SetEventStatus User Code end*/
    Rte_Call_Event_Event_0xD21087_SetEventStatus(Call_Event_Event_0xD21087_SetEventStatus_EventStatus);
    /* Rte_Call_Event_Event_0xD21087_SetEventStatus User Code start*/

    /* Rte_Call_Event_Event_0xD21087_SetEventStatus User Code end*/
    Rte_Call_Event_Event_0xD21208_SetEventStatus(Call_Event_Event_0xD21208_SetEventStatus_EventStatus);
    /* Rte_Call_Event_Event_0xD21208_SetEventStatus User Code start*/

    /* Rte_Call_Event_Event_0xD21208_SetEventStatus User Code end*/
    Rte_Call_Event_Event_0xD21287_SetEventStatus(Call_Event_Event_0xD21287_SetEventStatus_EventStatus);
    /* Rte_Call_Event_Event_0xD21287_SetEventStatus User Code start*/

    /* Rte_Call_Event_Event_0xD21287_SetEventStatus User Code end*/
    Rte_Call_Event_Event_0xD21308_SetEventStatus(Call_Event_Event_0xD21308_SetEventStatus_EventStatus);
    /* Rte_Call_Event_Event_0xD21308_SetEventStatus User Code start*/

    /* Rte_Call_Event_Event_0xD21308_SetEventStatus User Code end*/
    Rte_Call_Event_Event_0xD21387_SetEventStatus(Call_Event_Event_0xD21387_SetEventStatus_EventStatus);
    /* Rte_Call_Event_Event_0xD21387_SetEventStatus User Code start*/

    /* Rte_Call_Event_Event_0xD21387_SetEventStatus User Code end*/
    Rte_Call_Event_Event_0xD21408_SetEventStatus(Call_Event_Event_0xD21408_SetEventStatus_EventStatus);
    /* Rte_Call_Event_Event_0xD21408_SetEventStatus User Code start*/

    /* Rte_Call_Event_Event_0xD21408_SetEventStatus User Code end*/
    Rte_Call_Event_Event_0xD21487_SetEventStatus(Call_Event_Event_0xD21487_SetEventStatus_EventStatus);
    /* Rte_Call_Event_Event_0xD21487_SetEventStatus User Code start*/

    /* Rte_Call_Event_Event_0xD21487_SetEventStatus User Code end*/
    Rte_Call_Event_Event_0xD21508_SetEventStatus(Call_Event_Event_0xD21508_SetEventStatus_EventStatus);
    /* Rte_Call_Event_Event_0xD21508_SetEventStatus User Code start*/

    /* Rte_Call_Event_Event_0xD21508_SetEventStatus User Code end*/
    Rte_Call_Event_Event_0xD21608_SetEventStatus(Call_Event_Event_0xD21608_SetEventStatus_EventStatus);
    /* Rte_Call_Event_Event_0xD21608_SetEventStatus User Code start*/

    /* Rte_Call_Event_Event_0xD21608_SetEventStatus User Code end*/
    Rte_Call_Event_Event_0xD21708_SetEventStatus(Call_Event_Event_0xD21708_SetEventStatus_EventStatus);
    /* Rte_Call_Event_Event_0xD21708_SetEventStatus User Code start*/

    /* Rte_Call_Event_Event_0xD21708_SetEventStatus User Code end*/
    Rte_Call_Event_Event_0xD22086_SetEventStatus(Call_Event_Event_0xD22086_SetEventStatus_EventStatus);
    /* Rte_Call_Event_Event_0xD22086_SetEventStatus User Code start*/

    /* Rte_Call_Event_Event_0xD22086_SetEventStatus User Code end*/
    Rte_Call_Event_Event_0xD22186_SetEventStatus(Call_Event_Event_0xD22186_SetEventStatus_EventStatus);
    /* Rte_Call_Event_Event_0xD22186_SetEventStatus User Code start*/

    /* Rte_Call_Event_Event_0xD22186_SetEventStatus User Code end*/
    Rte_Call_Event_Event_0xD22286_SetEventStatus(Call_Event_Event_0xD22286_SetEventStatus_EventStatus);
    /* Rte_Call_Event_Event_0xD22286_SetEventStatus User Code start*/

    /* Rte_Call_Event_Event_0xD22286_SetEventStatus User Code end*/
    Rte_Call_Event_Event_0xD22386_SetEventStatus(Call_Event_Event_0xD22386_SetEventStatus_EventStatus);
    /* Rte_Call_Event_Event_0xD22386_SetEventStatus User Code start*/

    /* Rte_Call_Event_Event_0xD22386_SetEventStatus User Code end*/
    Rte_Call_Event_Event_0xD22486_SetEventStatus(Call_Event_Event_0xD22486_SetEventStatus_EventStatus);
    /* Rte_Call_Event_Event_0xD22486_SetEventStatus User Code start*/

    /* Rte_Call_Event_Event_0xD22486_SetEventStatus User Code end*/
    Rte_Call_Event_Event_0xD22586_SetEventStatus(Call_Event_Event_0xD22586_SetEventStatus_EventStatus);
    /* Rte_Call_Event_Event_0xD22586_SetEventStatus User Code start*/

    /* Rte_Call_Event_Event_0xD22586_SetEventStatus User Code end*/
    Rte_Call_Event_Event_0xD22686_SetEventStatus(Call_Event_Event_0xD22686_SetEventStatus_EventStatus);
    /* Rte_Call_Event_Event_0xD22686_SetEventStatus User Code start*/

    /* Rte_Call_Event_Event_0xD22686_SetEventStatus User Code end*/
    Rte_Call_Event_Event_0xD22786_SetEventStatus(Call_Event_Event_0xD22786_SetEventStatus_EventStatus);
    /* Rte_Call_Event_Event_0xD22786_SetEventStatus User Code start*/

    /* Rte_Call_Event_Event_0xD22786_SetEventStatus User Code end*/
    Rte_Call_Event_Event_0xD23087_SetEventStatus(Call_Event_Event_0xD23087_SetEventStatus_EventStatus);
    /* Rte_Call_Event_Event_0xD23087_SetEventStatus User Code start*/

    /* Rte_Call_Event_Event_0xD23087_SetEventStatus User Code end*/
    Rte_Call_Event_Event_0xD23187_SetEventStatus(Call_Event_Event_0xD23187_SetEventStatus_EventStatus);
    /* Rte_Call_Event_Event_0xD23187_SetEventStatus User Code start*/

    /* Rte_Call_Event_Event_0xD23187_SetEventStatus User Code end*/
    Rte_Call_Event_Event_0xD23487_SetEventStatus(Call_Event_Event_0xD23487_SetEventStatus_EventStatus);
    /* Rte_Call_Event_Event_0xD23487_SetEventStatus User Code start*/

    /* Rte_Call_Event_Event_0xD23487_SetEventStatus User Code end*/
    Rte_Call_Event_Event_0xD23587_SetEventStatus(Call_Event_Event_0xD23587_SetEventStatus_EventStatus);
    /* Rte_Call_Event_Event_0xD23587_SetEventStatus User Code start*/

    /* Rte_Call_Event_Event_0xD23587_SetEventStatus User Code end*/
    Rte_Call_Event_Event_0xD23687_SetEventStatus(Call_Event_Event_0xD23687_SetEventStatus_EventStatus);
    /* Rte_Call_Event_Event_0xD23687_SetEventStatus User Code start*/

    /* Rte_Call_Event_Event_0xD23687_SetEventStatus User Code end*/
    /* CC_DiagMsg_SWC_10ms_Feedback User Code start*/

    /* CC_DiagMsg_SWC_10ms_Feedback User Code end*/

}
#define CC_DiagMsg_SWC_STOP_SEC_CODE
#include "CC_DiagMsg_SWC_MemMap.h"




