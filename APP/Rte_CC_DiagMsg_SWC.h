/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : Rte_CC_DiagMsg_SWC.h
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
#ifndef RTE_CC_DIAGMSG_SWC_H
#define RTE_CC_DIAGMSG_SWC_H

#ifndef RTE_CORE
#ifdef RTE_APPLICATION_HEADER_FILE
#error Multiple application header files included.
#endif /* RTE_APPLICATION_HEADER_FILE */
#define RTE_APPLICATION_HEADER_FILE
#endif
# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

/*******************************************************************************
*   Includes.
*******************************************************************************/
#include "Rte_CC_DiagMsg_SWC_Type.h"
#include "Com.h"
#include "Dem.h"
/*******************************************************************************
*   define for a symbolic name of the RunnableEntity.
*******************************************************************************/
#define RTE_RUNNABLE_CC_DiagMsg_SWC_10ms                    CC_DiagMsg_SWC

/*******************************************************************************
*   Instance Handle
*******************************************************************************/
#ifndef RTE_CORE
typedef CONSTP2CONST(Rte_CDS_CC_DiagMsg_SWC, AUTOMATIC, RTE_CONST) Rte_Instance;
#endif

/*******************************************************************************
*   Macro definition.
*******************************************************************************/
#define Rte_Read_ABSFailed_ABSFailed                        Rte_Read_CC_DiagMsg_SWC_ABSFailed_ABSFailed
#define Rte_Read_ABS_EBDFailed_ABS_EBDFailed                Rte_Read_CC_DiagMsg_SWC_ABS_EBDFailed_ABS_EBDFailed
#define Rte_Read_ABS_FLWheelSpeedInvalid_ABS_FLWheelSpeedInvalid      Rte_Read_CC_DiagMsg_SWC_ABS_FLWheelSpeedInvalid_ABS_FLWheelSpeedInvalid
#define Rte_Read_ABS_FLWheelSpeedRCSts_ABS_FLWheelSpeedRCSts          Rte_Read_CC_DiagMsg_SWC_ABS_FLWheelSpeedRCSts_ABS_FLWheelSpeedRCSts
#define Rte_Read_ABS_FRWheelSpeedInvalid_ABS_FRWheelSpeedInvalid      Rte_Read_CC_DiagMsg_SWC_ABS_FRWheelSpeedInvalid_ABS_FRWheelSpeedInvalid
#define Rte_Read_ABS_FRWheelSpeedRCSts_ABS_FRWheelSpeedRCSts          Rte_Read_CC_DiagMsg_SWC_ABS_FRWheelSpeedRCSts_ABS_FRWheelSpeedRCSts
#define Rte_Read_ABS_FWSpeMCUKPH_AliveCounter_ABS_FWSpeMCUKPH_AliveCounter      Rte_Read_CC_DiagMsg_SWC_ABS_FWSpeMCUKPH_AliveCounter_ABS_FWSpeMCUKPH_AliveCounter
#define Rte_Read_ABS_FWSpeMCUKPH_CheckSum_ABS_FWSpeMCUKPH_CheckSum    Rte_Read_CC_DiagMsg_SWC_ABS_FWSpeMCUKPH_CheckSum_ABS_FWSpeMCUKPH_CheckSum
#define Rte_Read_ABS_RLWheelSpeedInvalid_ABS_RLWheelSpeedInvalid      Rte_Read_CC_DiagMsg_SWC_ABS_RLWheelSpeedInvalid_ABS_RLWheelSpeedInvalid
#define Rte_Read_ABS_RLWheelSpeedRCSts_ABS_RLWheelSpeedRCSts          Rte_Read_CC_DiagMsg_SWC_ABS_RLWheelSpeedRCSts_ABS_RLWheelSpeedRCSts
#define Rte_Read_ABS_RRWheelSpeedInvalid_ABS_RRWheelSpeedInvalid      Rte_Read_CC_DiagMsg_SWC_ABS_RRWheelSpeedInvalid_ABS_RRWheelSpeedInvalid
#define Rte_Read_ABS_RRWheelSpeedRCSts_ABS_RRWheelSpeedRCSts          Rte_Read_CC_DiagMsg_SWC_ABS_RRWheelSpeedRCSts_ABS_RRWheelSpeedRCSts
#define Rte_Read_ABS_RWSpeMCUKPH_AliveCounter_ABS_RWSpeMCUKPH_AliveCounter      Rte_Read_CC_DiagMsg_SWC_ABS_RWSpeMCUKPH_AliveCounter_ABS_RWSpeMCUKPH_AliveCounter
#define Rte_Read_ABS_RWSpeMCUKPH_CheckSum_ABS_RWSpeMCUKPH_CheckSum    Rte_Read_CC_DiagMsg_SWC_ABS_RWSpeMCUKPH_CheckSum_ABS_RWSpeMCUKPH_CheckSum
#define Rte_Read_ABS_Status_AliveCounter_ABS_Status_AliveCounter      Rte_Read_CC_DiagMsg_SWC_ABS_Status_AliveCounter_ABS_Status_AliveCounter
#define Rte_Read_ABS_Status_CheckSum_ABS_Status_CheckSum    Rte_Read_CC_DiagMsg_SWC_ABS_Status_CheckSum_ABS_Status_CheckSum
#define Rte_Read_ABS_VehicleSpeedInvalid_ABS_VehicleSpeedInvalid      Rte_Read_CC_DiagMsg_SWC_ABS_VehicleSpeedInvalid_ABS_VehicleSpeedInvalid
#define Rte_Read_ABS_WheelSpeMCURC_AliveCounter_ABS_WheelSpeMCURC_AliveCounter  Rte_Read_CC_DiagMsg_SWC_ABS_WheelSpeMCURC_AliveCounter_ABS_WheelSpeMCURC_AliveCounter
#define Rte_Read_ABS_WheelSpeMCURC_CheckSum_ABS_WheelSpeMCURC_CheckSum          Rte_Read_CC_DiagMsg_SWC_ABS_WheelSpeMCURC_CheckSum_ABS_WheelSpeMCURC_CheckSum
#define Rte_Read_AB_BrkPedalSwStsV_AB_BrkPedalSwStsV        Rte_Read_CC_DiagMsg_SWC_AB_BrkPedalSwStsV_AB_BrkPedalSwStsV
#define Rte_Read_AB_Fault_Status_AB_Fault_Status            Rte_Read_CC_DiagMsg_SWC_AB_Fault_Status_AB_Fault_Status
#define Rte_Read_ACU_AliveCounter_ACU_AliveCounter          Rte_Read_CC_DiagMsg_SWC_ACU_AliveCounter_ACU_AliveCounter
#define Rte_Read_ACU_CheckSum_ACU_CheckSum                  Rte_Read_CC_DiagMsg_SWC_ACU_CheckSum_ACU_CheckSum
#define Rte_Read_BCM_TurnLight_FaultSts_BCM_TurnLight_FaultSts        Rte_Read_CC_DiagMsg_SWC_BCM_TurnLight_FaultSts_BCM_TurnLight_FaultSts
#define Rte_Read_CCU_ExternalTemperatureFailSts_CCU_ExternalTemperatureFailSts  Rte_Read_CC_DiagMsg_SWC_CCU_ExternalTemperatureFailSts_CCU_ExternalTemperatureFailSts
#define Rte_Read_CheckSum_0x106_CheckSum_0x106              Rte_Read_CC_DiagMsg_SWC_CheckSum_0x106_CheckSum_0x106
#define Rte_Read_CheckSum_0x109_CheckSum_0x109              Rte_Read_CC_DiagMsg_SWC_CheckSum_0x109_CheckSum_0x109
#define Rte_Read_CheckSum_0x17F_CheckSum_0x17F              Rte_Read_CC_DiagMsg_SWC_CheckSum_0x17F_CheckSum_0x17F
#define Rte_Read_CheckSum_0x3F1_CheckSum_0x3F1              Rte_Read_CC_DiagMsg_SWC_CheckSum_0x3F1_CheckSum_0x3F1
#define Rte_Read_CheckSum_0x3F7_CheckSum_0x3F7              Rte_Read_CC_DiagMsg_SWC_CheckSum_0x3F7_CheckSum_0x3F7
#define Rte_Read_Checksum_0x132_Checksum_0x132              Rte_Read_CC_DiagMsg_SWC_Checksum_0x132_Checksum_0x132
#define Rte_Read_Checksum_0x17E_Checksum_0x17E              Rte_Read_CC_DiagMsg_SWC_Checksum_0x17E_Checksum_0x17E
#define Rte_Read_Checksum_0x3E2_Checksum_0x3E2              Rte_Read_CC_DiagMsg_SWC_Checksum_0x3E2_Checksum_0x3E2
#define Rte_Read_Checksum_230_Checksum_230                  Rte_Read_CC_DiagMsg_SWC_Checksum_230_Checksum_230
#define Rte_Read_EPS_ADAS_ModAvail_EPS_ADAS_ModAvail        Rte_Read_CC_DiagMsg_SWC_EPS_ADAS_ModAvail_EPS_ADAS_ModAvail
#define Rte_Read_ESC_LateralACC_Valid_ESC_LateralACC_Valid  Rte_Read_CC_DiagMsg_SWC_ESC_LateralACC_Valid_ESC_LateralACC_Valid
#define Rte_Read_ESC_LongitudeACC_Valid_ESC_LongitudeACC_Valid        Rte_Read_CC_DiagMsg_SWC_ESC_LongitudeACC_Valid_ESC_LongitudeACC_Valid
#define Rte_Read_ESC_MasterCylinderPressureV_ESC_MasterCylinderPressureV        Rte_Read_CC_DiagMsg_SWC_ESC_MasterCylinderPressureV_ESC_MasterCylinderPressureV
#define Rte_Read_ESC_VehDynYawRate_Valid_ESC_VehDynYawRate_Valid      Rte_Read_CC_DiagMsg_SWC_ESC_VehDynYawRate_Valid_ESC_VehDynYawRate_Valid
#define Rte_Read_MFS_L2_Failure_MFS_L2_Failure              Rte_Read_CC_DiagMsg_SWC_MFS_L2_Failure_MFS_L2_Failure
#define Rte_Read_Nav_Error_Nav_errorSts                     Rte_Read_CC_DiagMsg_SWC_Nav_Error_Nav_errorSts
#define Rte_Read_PEPS_IGN1RelayValidity_PEPS_IGN1RelayValidity        Rte_Read_CC_DiagMsg_SWC_PEPS_IGN1RelayValidity_PEPS_IGN1RelayValidity
#define Rte_Read_PEPS_Message_Sts_AliveCounter_PEPS_Message_Sts_AliveCounter    Rte_Read_CC_DiagMsg_SWC_PEPS_Message_Sts_AliveCounter_PEPS_Message_Sts_AliveCounter
#define Rte_Read_PEPS_Message_Sts_CheckSum_PEPS_Message_Sts_CheckSum  Rte_Read_CC_DiagMsg_SWC_PEPS_Message_Sts_CheckSum_PEPS_Message_Sts_CheckSum
#define Rte_Read_PEPS_PowerModeValidity_PEPS_PowerModeValidity        Rte_Read_CC_DiagMsg_SWC_PEPS_PowerModeValidity_PEPS_PowerModeValidity
#define Rte_Read_RollingCounter_0x106_RollingCounter_0x106  Rte_Read_CC_DiagMsg_SWC_RollingCounter_0x106_RollingCounter_0x106
#define Rte_Read_RollingCounter_0x109_RollingCounter_0x109  Rte_Read_CC_DiagMsg_SWC_RollingCounter_0x109_RollingCounter_0x109
#define Rte_Read_RollingCounter_0x132_RollingCounter_0x132  Rte_Read_CC_DiagMsg_SWC_RollingCounter_0x132_RollingCounter_0x132
#define Rte_Read_RollingCounter_0x17F_RollingCounter_0x17F  Rte_Read_CC_DiagMsg_SWC_RollingCounter_0x17F_RollingCounter_0x17F
#define Rte_Read_RollingCounter_0x3E2_RollingCounter_0x3E2  Rte_Read_CC_DiagMsg_SWC_RollingCounter_0x3E2_RollingCounter_0x3E2
#define Rte_Read_RollingCounter_0x3F1_RollingCounter_0x3F1  Rte_Read_CC_DiagMsg_SWC_RollingCounter_0x3F1_RollingCounter_0x3F1
#define Rte_Read_RollingCounter_0x3F7_RollingCounter_0x3F7  Rte_Read_CC_DiagMsg_SWC_RollingCounter_0x3F7_RollingCounter_0x3F7
#define Rte_Read_RollingCounter_230_RollingCounter_230      Rte_Read_CC_DiagMsg_SWC_RollingCounter_230_RollingCounter_230
#define Rte_Read_Rolling_counter_0x17E_Rolling_counter_0x17E          Rte_Read_CC_DiagMsg_SWC_Rolling_counter_0x17E_Rolling_counter_0x17E
#define Rte_Read_SAS_Calibrated_SAS_Calibrated              Rte_Read_CC_DiagMsg_SWC_SAS_Calibrated_SAS_Calibrated
#define Rte_Read_SAS_SASFailure_SAS_SASFailure              Rte_Read_CC_DiagMsg_SWC_SAS_SASFailure_SAS_SASFailure
#define Rte_Read_SAS_SASStsSnsr_SAS_SASStsSnsr              Rte_Read_CC_DiagMsg_SWC_SAS_SASStsSnsr_SAS_SASStsSnsr
#define Rte_Read_SAS_SteerWhlRotSpdStatus_SAS_SteerWhlRotSpdStatus    Rte_Read_CC_DiagMsg_SWC_SAS_SteerWhlRotSpdStatus_SAS_SteerWhlRotSpdStatus
#define Rte_Read_SAS_SteeringAngleValid_SAS_SteeringAngleValid        Rte_Read_CC_DiagMsg_SWC_SAS_SteeringAngleValid_SAS_SteeringAngleValid
#define Rte_Read_TPMS_LFpressureV_TPMS_LFpressureV          Rte_Read_CC_DiagMsg_SWC_TPMS_LFpressureV_TPMS_LFpressureV
#define Rte_Read_TPMS_LRpressureV_TPMS_LRpressureV          Rte_Read_CC_DiagMsg_SWC_TPMS_LRpressureV_TPMS_LRpressureV
#define Rte_Read_TPMS_RFpressureV_TPMS_RFpressureV          Rte_Read_CC_DiagMsg_SWC_TPMS_RFpressureV_TPMS_RFpressureV
#define Rte_Read_TPMS_RRpressureV_TPMS_RRpressureV          Rte_Read_CC_DiagMsg_SWC_TPMS_RRpressureV_TPMS_RRpressureV
#define Rte_Read_VCU_AccPedal_Valid_VCU_AccPedal_Valid      Rte_Read_CC_DiagMsg_SWC_VCU_AccPedal_Valid_VCU_AccPedal_Valid
#define Rte_Read_VCU_Ctrl_AliveCounter_VCU_Ctrl_AliveCounter          Rte_Read_CC_DiagMsg_SWC_VCU_Ctrl_AliveCounter_VCU_Ctrl_AliveCounter
#define Rte_Read_VCU_Ctrl_CheckSum_VCU_Ctrl_CheckSum        Rte_Read_CC_DiagMsg_SWC_VCU_Ctrl_CheckSum_VCU_Ctrl_CheckSum
#define Rte_Read_VCU_ModeGearSts_VCU_ModeGearSts            Rte_Read_CC_DiagMsg_SWC_VCU_ModeGearSts_VCU_ModeGearSts
#define Rte_Read_VCU_StsEpt_AliveCounter_VCU_StsEpt_AliveCounter      Rte_Read_CC_DiagMsg_SWC_VCU_StsEpt_AliveCounter_VCU_StsEpt_AliveCounter
#define Rte_Read_VCU_StsEpt_CheckSum_VCU_StsEpt_CheckSum    Rte_Read_CC_DiagMsg_SWC_VCU_StsEpt_CheckSum_VCU_StsEpt_CheckSum
#define Rte_Read_WCBS_ABAAva_WCBS_ABAAva                    Rte_Read_CC_DiagMsg_SWC_WCBS_ABAAva_WCBS_ABAAva
#define Rte_Read_WCBS_ABPAva_WCBS_ABPAva                    Rte_Read_CC_DiagMsg_SWC_WCBS_ABPAva_WCBS_ABPAva
#define Rte_Read_WCBS_ACC_VLC_Avl_WCBS_ACC_VLC_Avl          Rte_Read_CC_DiagMsg_SWC_WCBS_ACC_VLC_Avl_WCBS_ACC_VLC_Avl
#define Rte_Read_WCBS_AEBAva_WCBS_AEBAva                    Rte_Read_CC_DiagMsg_SWC_WCBS_AEBAva_WCBS_AEBAva
#define Rte_Read_WCBS_AWBAvl_WCBS_AWBAvl                    Rte_Read_CC_DiagMsg_SWC_WCBS_AWBAvl_WCBS_AWBAvl
#define Rte_Read_WCBS_ESCDeteACCErroSta_WCBS_ESCDeteACCErroSta        Rte_Read_CC_DiagMsg_SWC_WCBS_ESCDeteACCErroSta_WCBS_ESCDeteACCErroSta
#define Rte_Call_Event_Event_0x9401A3_SetEventStatus(EventStatus)     NULL_PTR
#define Rte_Call_Event_Event_0x940354_SetEventStatus(EventStatus)     NULL_PTR
#define Rte_Call_Event_Event_0x940406_SetEventStatus(EventStatus)     NULL_PTR
#define Rte_Call_Event_Event_0x942009_SetEventStatus(EventStatus)     NULL_PTR
#define Rte_Call_Event_Event_0x942209_SetEventStatus(EventStatus)     NULL_PTR
#define Rte_Call_Event_Event_0x942309_SetEventStatus(EventStatus)     NULL_PTR
#define Rte_Call_Event_Event_0x942409_SetEventStatus(EventStatus)     NULL_PTR
#define Rte_Call_Event_Event_0x942509_SetEventStatus(EventStatus)     NULL_PTR
#define Rte_Call_Event_Event_0x942609_SetEventStatus(EventStatus)     NULL_PTR
#define Rte_Call_Event_Event_0x942D09_SetEventStatus(EventStatus)     NULL_PTR
#define Rte_Call_Event_Event_0x942F09_SetEventStatus(EventStatus)     NULL_PTR
#define Rte_Call_Event_Event_0x943009_SetEventStatus(EventStatus)     NULL_PTR
#define Rte_Call_Event_Event_0xD20008_SetEventStatus(EventStatus)     NULL_PTR
#define Rte_Call_Event_Event_0xD20086_SetEventStatus(EventStatus)     NULL_PTR
#define Rte_Call_Event_Event_0xD20087_SetEventStatus(EventStatus)     NULL_PTR
#define Rte_Call_Event_Event_0xD20108_SetEventStatus(EventStatus)     NULL_PTR
#define Rte_Call_Event_Event_0xD20186_SetEventStatus(EventStatus)     NULL_PTR
#define Rte_Call_Event_Event_0xD20187_SetEventStatus(EventStatus)     NULL_PTR
#define Rte_Call_Event_Event_0xD20208_SetEventStatus(EventStatus)     NULL_PTR
#define Rte_Call_Event_Event_0xD20286_SetEventStatus(EventStatus)     NULL_PTR
#define Rte_Call_Event_Event_0xD20287_SetEventStatus(EventStatus)     NULL_PTR
#define Rte_Call_Event_Event_0xD20308_SetEventStatus(EventStatus)     NULL_PTR
#define Rte_Call_Event_Event_0xD20386_SetEventStatus(EventStatus)     NULL_PTR
#define Rte_Call_Event_Event_0xD20387_SetEventStatus(EventStatus)     NULL_PTR
#define Rte_Call_Event_Event_0xD20408_SetEventStatus(EventStatus)     NULL_PTR
#define Rte_Call_Event_Event_0xD20486_SetEventStatus(EventStatus)     NULL_PTR
#define Rte_Call_Event_Event_0xD20508_SetEventStatus(EventStatus)     NULL_PTR
#define Rte_Call_Event_Event_0xD20586_SetEventStatus(EventStatus)     NULL_PTR
#define Rte_Call_Event_Event_0xD20608_SetEventStatus(EventStatus)     NULL_PTR
#define Rte_Call_Event_Event_0xD20686_SetEventStatus(EventStatus)     NULL_PTR
#define Rte_Call_Event_Event_0xD20708_SetEventStatus(EventStatus)     NULL_PTR
#define Rte_Call_Event_Event_0xD20786_SetEventStatus(EventStatus)     NULL_PTR
#define Rte_Call_Event_Event_0xD20808_SetEventStatus(EventStatus)     NULL_PTR
#define Rte_Call_Event_Event_0xD20886_SetEventStatus(EventStatus)     NULL_PTR
#define Rte_Call_Event_Event_0xD20908_SetEventStatus(EventStatus)     NULL_PTR
#define Rte_Call_Event_Event_0xD20986_SetEventStatus(EventStatus)     NULL_PTR
#define Rte_Call_Event_Event_0xD20A08_SetEventStatus(EventStatus)     NULL_PTR
#define Rte_Call_Event_Event_0xD20A86_SetEventStatus(EventStatus)     NULL_PTR
#define Rte_Call_Event_Event_0xD20B08_SetEventStatus(EventStatus)     NULL_PTR
#define Rte_Call_Event_Event_0xD20B86_SetEventStatus(EventStatus)     NULL_PTR
#define Rte_Call_Event_Event_0xD20C08_SetEventStatus(EventStatus)     NULL_PTR
#define Rte_Call_Event_Event_0xD20C86_SetEventStatus(EventStatus)     NULL_PTR
#define Rte_Call_Event_Event_0xD20D08_SetEventStatus(EventStatus)     NULL_PTR
#define Rte_Call_Event_Event_0xD20D86_SetEventStatus(EventStatus)     NULL_PTR
#define Rte_Call_Event_Event_0xD20E08_SetEventStatus(EventStatus)     NULL_PTR
#define Rte_Call_Event_Event_0xD20E86_SetEventStatus(EventStatus)     NULL_PTR
#define Rte_Call_Event_Event_0xD20F08_SetEventStatus(EventStatus)     NULL_PTR
#define Rte_Call_Event_Event_0xD20F86_SetEventStatus(EventStatus)     NULL_PTR
#define Rte_Call_Event_Event_0xD21008_SetEventStatus(EventStatus)     NULL_PTR
#define Rte_Call_Event_Event_0xD21087_SetEventStatus(EventStatus)     NULL_PTR
#define Rte_Call_Event_Event_0xD21208_SetEventStatus(EventStatus)     NULL_PTR
#define Rte_Call_Event_Event_0xD21287_SetEventStatus(EventStatus)     NULL_PTR
#define Rte_Call_Event_Event_0xD21308_SetEventStatus(EventStatus)     NULL_PTR
#define Rte_Call_Event_Event_0xD21387_SetEventStatus(EventStatus)     NULL_PTR
#define Rte_Call_Event_Event_0xD21408_SetEventStatus(EventStatus)     NULL_PTR
#define Rte_Call_Event_Event_0xD21487_SetEventStatus(EventStatus)     NULL_PTR
#define Rte_Call_Event_Event_0xD21508_SetEventStatus(EventStatus)     NULL_PTR
#define Rte_Call_Event_Event_0xD21608_SetEventStatus(EventStatus)     NULL_PTR
#define Rte_Call_Event_Event_0xD21708_SetEventStatus(EventStatus)     NULL_PTR
#define Rte_Call_Event_Event_0xD22086_SetEventStatus(EventStatus)     NULL_PTR
#define Rte_Call_Event_Event_0xD22186_SetEventStatus(EventStatus)     NULL_PTR
#define Rte_Call_Event_Event_0xD22286_SetEventStatus(EventStatus)     NULL_PTR
#define Rte_Call_Event_Event_0xD22386_SetEventStatus(EventStatus)     NULL_PTR
#define Rte_Call_Event_Event_0xD22486_SetEventStatus(EventStatus)     NULL_PTR
#define Rte_Call_Event_Event_0xD22586_SetEventStatus(EventStatus)     NULL_PTR
#define Rte_Call_Event_Event_0xD22686_SetEventStatus(EventStatus)     NULL_PTR
#define Rte_Call_Event_Event_0xD22786_SetEventStatus(EventStatus)     NULL_PTR
#define Rte_Call_Event_Event_0xD23087_SetEventStatus(EventStatus)     NULL_PTR
#define Rte_Call_Event_Event_0xD23187_SetEventStatus(EventStatus)     NULL_PTR
#define Rte_Call_Event_Event_0xD23487_SetEventStatus(EventStatus)     NULL_PTR
#define Rte_Call_Event_Event_0xD23587_SetEventStatus(EventStatus)     NULL_PTR
#define Rte_Call_Event_Event_0xD23687_SetEventStatus(EventStatus)     NULL_PTR
/*******************************************************************************
*   Extended
*******************************************************************************/
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CC_DiagMsg_SWC_ABSFailed_ABSFailed
(
    P2VAR(ABSFailed_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CC_DiagMsg_SWC_ABS_EBDFailed_ABS_EBDFailed
(
    P2VAR(ABS_EBDFailed_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CC_DiagMsg_SWC_ABS_FLWheelSpeedInvalid_ABS_FLWheelSpeedInvalid
(
    P2VAR(ABS_FLWheelSpeedInvalid_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CC_DiagMsg_SWC_ABS_FLWheelSpeedRCSts_ABS_FLWheelSpeedRCSts
(
    P2VAR(ABS_FLWheelSpeedRCSts_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CC_DiagMsg_SWC_ABS_FRWheelSpeedInvalid_ABS_FRWheelSpeedInvalid
(
    P2VAR(ABS_FRWheelSpeedInvalid_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CC_DiagMsg_SWC_ABS_FRWheelSpeedRCSts_ABS_FRWheelSpeedRCSts
(
    P2VAR(ABS_FRWheelSpeedRCSts_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CC_DiagMsg_SWC_ABS_FWSpeMCUKPH_AliveCounter_ABS_FWSpeMCUKPH_AliveCounter
(
    P2VAR(ABS_FWSpeMCUKPH_AliveCounter_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CC_DiagMsg_SWC_ABS_FWSpeMCUKPH_CheckSum_ABS_FWSpeMCUKPH_CheckSum
(
    P2VAR(ABS_FWSpeMCUKPH_CheckSum_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CC_DiagMsg_SWC_ABS_RLWheelSpeedInvalid_ABS_RLWheelSpeedInvalid
(
    P2VAR(ABS_RLWheelSpeedInvalid_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CC_DiagMsg_SWC_ABS_RLWheelSpeedRCSts_ABS_RLWheelSpeedRCSts
(
    P2VAR(ABS_RLWheelSpeedRCSts_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CC_DiagMsg_SWC_ABS_RRWheelSpeedInvalid_ABS_RRWheelSpeedInvalid
(
    P2VAR(ABS_RRWheelSpeedInvalid_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CC_DiagMsg_SWC_ABS_RRWheelSpeedRCSts_ABS_RRWheelSpeedRCSts
(
    P2VAR(ABS_RRWheelSpeedRCSts_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CC_DiagMsg_SWC_ABS_RWSpeMCUKPH_AliveCounter_ABS_RWSpeMCUKPH_AliveCounter
(
    P2VAR(ABS_RWSpeMCUKPH_AliveCounter_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CC_DiagMsg_SWC_ABS_RWSpeMCUKPH_CheckSum_ABS_RWSpeMCUKPH_CheckSum
(
    P2VAR(ABS_RWSpeMCUKPH_CheckSum_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CC_DiagMsg_SWC_ABS_Status_AliveCounter_ABS_Status_AliveCounter
(
    P2VAR(ABS_Status_AliveCounter_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CC_DiagMsg_SWC_ABS_Status_CheckSum_ABS_Status_CheckSum
(
    P2VAR(ABS_Status_CheckSum_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CC_DiagMsg_SWC_ABS_VehicleSpeedInvalid_ABS_VehicleSpeedInvalid
(
    P2VAR(ABS_VehicleSpeedInvalid_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CC_DiagMsg_SWC_ABS_WheelSpeMCURC_AliveCounter_ABS_WheelSpeMCURC_AliveCounter
(
    P2VAR(ABS_WheelSpeMCURC_AliveCounter_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CC_DiagMsg_SWC_ABS_WheelSpeMCURC_CheckSum_ABS_WheelSpeMCURC_CheckSum
(
    P2VAR(ABS_WheelSpeMCURC_CheckSum_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CC_DiagMsg_SWC_AB_BrkPedalSwStsV_AB_BrkPedalSwStsV
(
    P2VAR(AB_BrkPedalSwStsV_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CC_DiagMsg_SWC_AB_Fault_Status_AB_Fault_Status
(
    P2VAR(AB_Fault_Status_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CC_DiagMsg_SWC_ACU_AliveCounter_ACU_AliveCounter
(
    P2VAR(ACU_AliveCounter_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CC_DiagMsg_SWC_ACU_CheckSum_ACU_CheckSum
(
    P2VAR(ACU_CheckSum_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CC_DiagMsg_SWC_BCM_TurnLight_FaultSts_BCM_TurnLight_FaultSts
(
    P2VAR(BCM_TurnLight_FaultSts_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CC_DiagMsg_SWC_CCU_ExternalTemperatureFailSts_CCU_ExternalTemperatureFailSts
(
    P2VAR(CCU_ExternalTemperatureFailSts_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CC_DiagMsg_SWC_CheckSum_0x106_CheckSum_0x106
(
    P2VAR(CheckSum_0x106_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CC_DiagMsg_SWC_CheckSum_0x109_CheckSum_0x109
(
    P2VAR(CheckSum_0x109_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CC_DiagMsg_SWC_CheckSum_0x17F_CheckSum_0x17F
(
    P2VAR(CheckSum_0x17F_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CC_DiagMsg_SWC_CheckSum_0x3F1_CheckSum_0x3F1
(
    P2VAR(CheckSum_0x3F1_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CC_DiagMsg_SWC_CheckSum_0x3F7_CheckSum_0x3F7
(
    P2VAR(CheckSum_0x3F7_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CC_DiagMsg_SWC_Checksum_0x132_Checksum_0x132
(
    P2VAR(Checksum_0x132_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CC_DiagMsg_SWC_Checksum_0x17E_Checksum_0x17E
(
    P2VAR(Checksum_0x17E_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CC_DiagMsg_SWC_Checksum_0x3E2_Checksum_0x3E2
(
    P2VAR(Checksum_0x3E2_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CC_DiagMsg_SWC_Checksum_230_Checksum_230
(
    P2VAR(Checksum_230_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CC_DiagMsg_SWC_EPS_ADAS_ModAvail_EPS_ADAS_ModAvail
(
    P2VAR(EPS_ADAS_ModAvail_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CC_DiagMsg_SWC_ESC_LateralACC_Valid_ESC_LateralACC_Valid
(
    P2VAR(ESC_LateralACC_Valid_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CC_DiagMsg_SWC_ESC_LongitudeACC_Valid_ESC_LongitudeACC_Valid
(
    P2VAR(ESC_LongitudeACC_Valid_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CC_DiagMsg_SWC_ESC_MasterCylinderPressureV_ESC_MasterCylinderPressureV
(
    P2VAR(ESC_MasterCylinderPressureV_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CC_DiagMsg_SWC_ESC_VehDynYawRate_Valid_ESC_VehDynYawRate_Valid
(
    P2VAR(ESC_VehDynYawRate_Valid_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CC_DiagMsg_SWC_MFS_L2_Failure_MFS_L2_Failure
(
    P2VAR(MFS_L2_Failure_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CC_DiagMsg_SWC_Nav_Error_Nav_errorSts
(
    P2VAR(Nav_errorSts_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CC_DiagMsg_SWC_PEPS_IGN1RelayValidity_PEPS_IGN1RelayValidity
(
    P2VAR(PEPS_IGN1RelayValidity_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CC_DiagMsg_SWC_PEPS_Message_Sts_AliveCounter_PEPS_Message_Sts_AliveCounter
(
    P2VAR(PEPS_Message_Sts_AliveCounter_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CC_DiagMsg_SWC_PEPS_Message_Sts_CheckSum_PEPS_Message_Sts_CheckSum
(
    P2VAR(PEPS_Message_Sts_CheckSum_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CC_DiagMsg_SWC_PEPS_PowerModeValidity_PEPS_PowerModeValidity
(
    P2VAR(PEPS_PowerModeValidity_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CC_DiagMsg_SWC_RollingCounter_0x106_RollingCounter_0x106
(
    P2VAR(RollingCounter_0x106_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CC_DiagMsg_SWC_RollingCounter_0x109_RollingCounter_0x109
(
    P2VAR(RollingCounter_0x109_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CC_DiagMsg_SWC_RollingCounter_0x132_RollingCounter_0x132
(
    P2VAR(RollingCounter_0x132_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CC_DiagMsg_SWC_RollingCounter_0x17F_RollingCounter_0x17F
(
    P2VAR(RollingCounter_0x17F_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CC_DiagMsg_SWC_RollingCounter_0x3E2_RollingCounter_0x3E2
(
    P2VAR(RollingCounter_0x3E2_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CC_DiagMsg_SWC_RollingCounter_0x3F1_RollingCounter_0x3F1
(
    P2VAR(RollingCounter_0x3F1_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CC_DiagMsg_SWC_RollingCounter_0x3F7_RollingCounter_0x3F7
(
    P2VAR(RollingCounter_0x3F7_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CC_DiagMsg_SWC_RollingCounter_230_RollingCounter_230
(
    P2VAR(RollingCounter_230_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CC_DiagMsg_SWC_Rolling_counter_0x17E_Rolling_counter_0x17E
(
    P2VAR(Rolling_counter_0x17E_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CC_DiagMsg_SWC_SAS_Calibrated_SAS_Calibrated
(
    P2VAR(SAS_Calibrated_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CC_DiagMsg_SWC_SAS_SASFailure_SAS_SASFailure
(
    P2VAR(SAS_SASFailure_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CC_DiagMsg_SWC_SAS_SASStsSnsr_SAS_SASStsSnsr
(
    P2VAR(SAS_SASStsSnsr_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CC_DiagMsg_SWC_SAS_SteerWhlRotSpdStatus_SAS_SteerWhlRotSpdStatus
(
    P2VAR(SAS_SteerWhlRotSpdStatus_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CC_DiagMsg_SWC_SAS_SteeringAngleValid_SAS_SteeringAngleValid
(
    P2VAR(SAS_SteeringAngleValid_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CC_DiagMsg_SWC_TPMS_LFpressureV_TPMS_LFpressureV
(
    P2VAR(TPMS_LFpressureV_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CC_DiagMsg_SWC_TPMS_LRpressureV_TPMS_LRpressureV
(
    P2VAR(TPMS_LRpressureV_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CC_DiagMsg_SWC_TPMS_RFpressureV_TPMS_RFpressureV
(
    P2VAR(TPMS_RFpressureV_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CC_DiagMsg_SWC_TPMS_RRpressureV_TPMS_RRpressureV
(
    P2VAR(TPMS_RRpressureV_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CC_DiagMsg_SWC_VCU_AccPedal_Valid_VCU_AccPedal_Valid
(
    P2VAR(VCU_AccPedal_Valid_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CC_DiagMsg_SWC_VCU_Ctrl_AliveCounter_VCU_Ctrl_AliveCounter
(
    P2VAR(VCU_Ctrl_AliveCounter_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CC_DiagMsg_SWC_VCU_Ctrl_CheckSum_VCU_Ctrl_CheckSum
(
    P2VAR(VCU_Ctrl_CheckSum_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CC_DiagMsg_SWC_VCU_ModeGearSts_VCU_ModeGearSts
(
    P2VAR(VCU_ModeGearSts_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CC_DiagMsg_SWC_VCU_StsEpt_AliveCounter_VCU_StsEpt_AliveCounter
(
    P2VAR(VCU_StsEpt_AliveCounter_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CC_DiagMsg_SWC_VCU_StsEpt_CheckSum_VCU_StsEpt_CheckSum
(
    P2VAR(VCU_StsEpt_CheckSum_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CC_DiagMsg_SWC_WCBS_ABAAva_WCBS_ABAAva
(
    P2VAR(WCBS_ABAAva_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CC_DiagMsg_SWC_WCBS_ABPAva_WCBS_ABPAva
(
    P2VAR(WCBS_ABPAva_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CC_DiagMsg_SWC_WCBS_ACC_VLC_Avl_WCBS_ACC_VLC_Avl
(
    P2VAR(WCBS_ACC_VLC_Avl_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CC_DiagMsg_SWC_WCBS_AEBAva_WCBS_AEBAva
(
    P2VAR(WCBS_AEBAva_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CC_DiagMsg_SWC_WCBS_AWBAvl_WCBS_AWBAvl
(
    P2VAR(WCBS_AWBAvl_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CC_DiagMsg_SWC_WCBS_ESCDeteACCErroSta_WCBS_ESCDeteACCErroSta
(
    P2VAR(WCBS_ESCDeteACCErroSta_IDT, AUTOMATIC, RTE_APPL_DATA) data
);

/*******************************************************************************
*   Runnable Extended
*******************************************************************************/

#define CC_DiagMsg_SWC_START_SEC_CODE
#include "CC_DiagMsg_SWC_MemMap.h"

extern FUNC(void, CC_DiagMsg_SWC_CODE) CC_DiagMsg_SWC
(
    void
);
#define CC_DiagMsg_SWC_STOP_SEC_CODE
#include "CC_DiagMsg_SWC_MemMap.h"


# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif  /*RTE_CC_DIAGMSG_SWC_H*/


