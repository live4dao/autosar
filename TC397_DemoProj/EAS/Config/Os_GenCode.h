/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : Os_GenCode.h
********************************************************************************
*   Project/Product : AUTOSAR BSW PROJECT
*   Title           : OS module configuration File
*   Author          : Hirain
********************************************************************************
*   Description     : OS module configuration File
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

#ifndef OS_GENCODE_H
#define OS_GENCODE_H
#include "Os_Types.h"
#include "Rte_Type.h"
/*****************************************************************************
* Generated variables
******************************************************************************/
#define OS_START_SEC_CODE
#include "Os_MemMap.h"

/**************************TASK************************************************/

extern TASK(OsTask_Core0_InitTask);
extern TASK(OsTask_Core0_Bsw_5ms);
extern TASK(OsTask_Core0_App_10ms);
extern TASK(OsTask_Core0_BswWdgM_1ms);
extern TASK(OsTask_Core0_App_InitTask);
extern TASK(TaskIdleCore0);
extern TASK(OsTask_Core1_Bsw_10ms);
extern TASK(OsTask_Core1_InitTask);
extern TASK(OsTask_Core1_App_10ms);
extern TASK(OsTask_Core1_App_InitTask);
extern TASK(TaskIdleCore1);
extern TASK(OsTask_Core2_Bsw_10ms);
extern TASK(OsTask_Core2_InitTask);
extern TASK(OsTask_Core2_App_10ms);
extern TASK(OsTask_Core2_App_40ms);
extern TASK(OsTask_Core2_App_1ms);
extern TASK(OsTask_Core2_App_5ms);
extern TASK(OsTask_Core2_App_1s);
extern TASK(OsTask_Core2_App_InitTask);
extern TASK(TaskIdleCore2);
extern TASK(OsTask_Core3_Bsw_10ms);
extern TASK(OsTask_Core3_InitTask);
extern TASK(OsTask_Core3_App_10ms);
extern TASK(OsTask_Core3_App_20ms);
extern TASK(OsTask_Core3_App_40ms);
extern TASK(OsTask_Core3_App_InitTask);
extern TASK(TaskIdleCore3);
extern TASK(OsTask_Core4_Bsw_10ms);
extern TASK(OsTask_Core4_InitTask);
extern TASK(OsTask_Core4_App_10ms);
extern TASK(OsTask_Core4_App_InitTask);
extern TASK(TaskIdleCore4);
extern TASK(OsTask_Core5_Bsw_10ms);
extern TASK(OsTask_Core5_InitTask);
extern TASK(OsTask_Core5_App_10ms);
extern TASK(OsTask_Core5_App_InitTask);
extern TASK(TaskIdleCore5);
/**************************ISR************************************************/

extern void ISR_CAN0_Core0_CAN2SR0(void);
extern void ISR_CAN0_Core0_CAN2SR1(void);
extern void ISR_CAN0_Core0_CAN2SR2(void);
extern void ISR_CAN0_Core0_CAN2SR3(void);
extern void ISR_CAN1_Core0_CAN2SR4(void);
extern void ISR_CAN1_Core0_CAN2SR5(void);
extern void ISR_CAN1_Core0_CAN2SR6(void);
extern void ISR_CAN1_Core0_CAN2SR7(void);
extern void ISR_Core0_ETHSR2(void);
extern void ISR_Core0_ETHSR6(void);

/**************************Trap Hook************************************************/

extern void Os_PL_Trap0_Hook(Os_uint8 tin);
extern void Os_PL_Trap1_Hook(Os_uint8 tin);
extern void Os_PL_Trap2_Hook(Os_uint8 tin);
extern void Os_PL_Trap3_Hook(Os_uint8 tin);
extern void Os_PL_Trap4_Hook(Os_uint8 tin);
extern void Os_PL_Trap5_Hook(Os_uint8 tin);
extern void Os_PL_Trap6_Hook(Os_uint8 tin);
extern void Os_PL_Trap7_Hook(Os_uint8 tin);

/**************************App Hook************************************************/


/**************************Alarm Callback************************************************/

/**************************IOC************************************************/
/*OsIoc0_Test*/
extern FUNC(Std_ReturnType, OS_CODE) IocWrite_IocId0_Sender0(Os_uint8 Counter);
extern FUNC(Std_ReturnType, OS_CODE) IocRead_IocId0_Receiver0(Os_uint8* Counter);
/*RteOs_CtApSignal_Transmission_PiAvmFusionParkingSlot_PiAvmFusionParkingSlot*/
extern FUNC(Std_ReturnType, OS_CODE) IocWrite_IocId1_Sender0(ParkingSlotSet data);
extern FUNC(Std_ReturnType, OS_CODE) IocRead_IocId1_Receiver0(ParkingSlotSet* data);
/*RteOs_CtApSignal_Transmission_PiGuideLine_PiGuideLine*/
extern FUNC(Std_ReturnType, OS_CODE) IocWrite_IocId2_Sender0(GuideLine data);
extern FUNC(Std_ReturnType, OS_CODE) IocRead_IocId2_Receiver0(GuideLine* data);
/*RteOs_CtApSignal_Transmission_PiUssPdcInfo_PiUssPdcInfo*/
extern FUNC(Std_ReturnType, OS_CODE) IocWrite_IocId3_Sender0(UssPdcInfo data);
extern FUNC(Std_ReturnType, OS_CODE) IocRead_IocId3_Receiver0(UssPdcInfo* data);
/*RteOs_CtApSignal_Transmission_TimeStamp_ABS_FrontWheelSpeMCUKPH_0x122_TimeStamp_ABS_FrontWheelSpeMCUKPH_0x122*/
extern FUNC(Std_ReturnType, OS_CODE) IocWrite_IocId4_Sender0(uint64 data);
extern FUNC(Std_ReturnType, OS_CODE) IocRead_IocId4_Receiver0(uint64* data);
/*RteOs_CtApSignal_Transmission_TimeStamp_ABS_RearWheelSpeMCUKPH_0x123_TimeStamp_ABS_RearWheelSpeMCUKPH_0x123*/
extern FUNC(Std_ReturnType, OS_CODE) IocWrite_IocId5_Sender0(uint64 data);
extern FUNC(Std_ReturnType, OS_CODE) IocRead_IocId5_Receiver0(uint64* data);
/*RteOs_CtApSignal_Transmission_TimeStamp_ABS_Status_0x125_TimeStamp_ABS_Status_0x125*/
extern FUNC(Std_ReturnType, OS_CODE) IocWrite_IocId6_Sender0(uint64 data);
extern FUNC(Std_ReturnType, OS_CODE) IocRead_IocId6_Receiver0(uint64* data);
/*RteOs_CtApSignal_Transmission_TimeStamp_ABS_WheelSpeedRC_0x124_TimeStamp_ABS_WheelSpeedRC_0x124*/
extern FUNC(Std_ReturnType, OS_CODE) IocWrite_IocId7_Sender0(uint64 data);
extern FUNC(Std_ReturnType, OS_CODE) IocRead_IocId7_Receiver0(uint64* data);
/*RteOs_CtApSignal_Transmission_TimeStamp_ESC_YawAngle_0x3E2_TimeStamp_ESC_YawAngle_0x3E2*/
extern FUNC(Std_ReturnType, OS_CODE) IocWrite_IocId8_Sender0(uint64 data);
extern FUNC(Std_ReturnType, OS_CODE) IocRead_IocId8_Receiver0(uint64* data);
/*RteOs_CtApSignal_Transmission_TimeStamp_IBS_ADAS_Info_0x269_TimeStamp_IBS_ADAS_Info_0x269*/
extern FUNC(Std_ReturnType, OS_CODE) IocWrite_IocId9_Sender0(uint64 data);
extern FUNC(Std_ReturnType, OS_CODE) IocRead_IocId9_Receiver0(uint64* data);
/*RteOs_CtApSignal_Transmission_TimeStamp_SAS_Sensor_0x17E_TimeStamp_SAS_Sensor_0x17E*/
extern FUNC(Std_ReturnType, OS_CODE) IocWrite_IocId10_Sender0(uint64 data);
extern FUNC(Std_ReturnType, OS_CODE) IocRead_IocId10_Receiver0(uint64* data);
/*RteOs_CtApSignal_Transmission_TimeStamp_VCU_Ctrl_0x162_TimeStamp_VCU_Ctrl_0x162*/
extern FUNC(Std_ReturnType, OS_CODE) IocWrite_IocId11_Sender0(uint64 data);
extern FUNC(Std_ReturnType, OS_CODE) IocRead_IocId11_Receiver0(uint64* data);
/*RteOs_CC_TCP_Handler_PiCarInfoH_PiCarInfoH*/
extern FUNC(Std_ReturnType, OS_CODE) IocWrite_IocId12_Sender0(CarInfoH data);
extern FUNC(Std_ReturnType, OS_CODE) IocRead_IocId12_Receiver0(CarInfoH* data);
/*RteOs_CC_TCP_Handler_PiCarInfoL_PiCarInfoL*/
extern FUNC(Std_ReturnType, OS_CODE) IocWrite_IocId13_Sender0(CarInfoL data);
extern FUNC(Std_ReturnType, OS_CODE) IocRead_IocId13_Receiver0(CarInfoL* data);
/*RteOs_CC_TCP_Handler_PiGlobalPoseBuffer_PiGlobalPoseBuffer*/
extern FUNC(Std_ReturnType, OS_CODE) IocWrite_IocId14_Sender0(GlobalPoseBuffer data);
extern FUNC(Std_ReturnType, OS_CODE) IocRead_IocId14_Receiver0(GlobalPoseBuffer* data);
/*RteOs_CC_TCP_Handler_PiManualParkingSlotSet_PiManualParkingSlotSet*/
extern FUNC(Std_ReturnType, OS_CODE) IocWrite_IocId15_Sender0(ParkingSlotSet data);
extern FUNC(Std_ReturnType, OS_CODE) IocRead_IocId15_Receiver0(ParkingSlotSet* data);
/*RteOs_CC_TCP_Handler_PiPerceptionCommand_PiPerceptionCommand*/
extern FUNC(Std_ReturnType, OS_CODE) IocWrite_IocId16_Sender0(PerceptionCommand data);
extern FUNC(Std_ReturnType, OS_CODE) IocRead_IocId16_Receiver0(PerceptionCommand* data);
/*RteOs_CC_TCP_Handler_PiUssInfo_PiUssInfo*/
extern FUNC(Std_ReturnType, OS_CODE) IocWrite_IocId17_Sender0(UssInfo data);
extern FUNC(Std_ReturnType, OS_CODE) IocRead_IocId17_Receiver0(UssInfo* data);
/*RteOs_CC_TCP_Handler_PiUssRawDataSet_PiUssRawDataSet*/
extern FUNC(Std_ReturnType, OS_CODE) IocWrite_IocId18_Sender0(UssRawDataSet data);
extern FUNC(Std_ReturnType, OS_CODE) IocRead_IocId18_Receiver0(UssRawDataSet* data);
/*RteOs_CC_TCP_Handler_PiUssStatusSet_PiUssStatusSet*/
extern FUNC(Std_ReturnType, OS_CODE) IocWrite_IocId19_Sender0(UssStatusSet data);
extern FUNC(Std_ReturnType, OS_CODE) IocRead_IocId19_Receiver0(UssStatusSet* data);
/*RteOs_CC_TCP_Handler_PiVehicleInfo_PiVehicleInfo*/
extern FUNC(Std_ReturnType, OS_CODE) IocWrite_IocId20_Sender0(VehicleInfo data);
extern FUNC(Std_ReturnType, OS_CODE) IocRead_IocId20_Receiver0(VehicleInfo* data);
/*RteOs_CC_TCP_Handler_PiVisionPerceptionControl_PiVisionPerceptionControl*/
extern FUNC(Std_ReturnType, OS_CODE) IocWrite_IocId21_Sender0(VisionPerceptionControl data);
extern FUNC(Std_ReturnType, OS_CODE) IocRead_IocId21_Receiver0(VisionPerceptionControl* data);
/*RteOs_Driving_Control_PiVision_WorkingStus_PiVision_WorkingStus*/
extern FUNC(Std_ReturnType, OS_CODE) IocWrite_IocId22_Sender0(Vision_WorkingStus data);
extern FUNC(Std_ReturnType, OS_CODE) IocRead_IocId22_Receiver0(Vision_WorkingStus* data);
/*RteOs_Driving_Control_PiFUSION_HEADER_ST_FUSION_HEADER_ST*/
extern FUNC(Std_ReturnType, OS_CODE) IocWrite_IocId23_Sender0(Fusion_Header_ST data);
extern FUNC(Std_ReturnType, OS_CODE) IocRead_IocId23_Receiver0(Fusion_Header_ST* data);
/*RteOs_Driving_Control_PiFUSION_OBJECT_ST_FUSION_OBJECT_ST*/
extern FUNC(Std_ReturnType, OS_CODE) IocWrite_IocId24_Sender0(Fusion_Object_ST data);
extern FUNC(Std_ReturnType, OS_CODE) IocRead_IocId24_Receiver0(Fusion_Object_ST* data);
/*RteOs_Driving_Control_PiFusion_Status_Fusion_Status*/
extern FUNC(Std_ReturnType, OS_CODE) IocWrite_IocId25_Sender0(Fusion_Status data);
extern FUNC(Std_ReturnType, OS_CODE) IocRead_IocId25_Receiver0(Fusion_Status* data);
/*RteOs_Driving_Control_PiVisionCal_PiVisionCal*/
extern FUNC(Std_ReturnType, OS_CODE) IocWrite_IocId26_Sender0(VisionCal data);
extern FUNC(Std_ReturnType, OS_CODE) IocRead_IocId26_Receiver0(VisionCal* data);
/*RteOs_Driving_Control_PiVisionTrafficSignSet_PiVisionTrafficSignSet*/
extern FUNC(Std_ReturnType, OS_CODE) IocWrite_IocId27_Sender0(VisionTrafficSignSet data);
extern FUNC(Std_ReturnType, OS_CODE) IocRead_IocId27_Receiver0(VisionTrafficSignSet* data);
/*RteOs_Driving_Control_PiVisionFailSafe_PiVisionFailSafe*/
extern FUNC(Std_ReturnType, OS_CODE) IocWrite_IocId28_Sender0(VisionFailSafe data);
extern FUNC(Std_ReturnType, OS_CODE) IocRead_IocId28_Receiver0(VisionFailSafe* data);
/*RteOs_Driving_Control_PiVisionLaneSet_PiVisionLaneSet*/
extern FUNC(Std_ReturnType, OS_CODE) IocWrite_IocId29_Sender0(VisionLaneSet data);
extern FUNC(Std_ReturnType, OS_CODE) IocRead_IocId29_Receiver0(VisionLaneSet* data);
/*RteOs_Driving_Control_PiVisionObjectSet_PiVisionObjectSet*/
extern FUNC(Std_ReturnType, OS_CODE) IocWrite_IocId30_Sender0(VisionObjectSet data);
extern FUNC(Std_ReturnType, OS_CODE) IocRead_IocId30_Receiver0(VisionObjectSet* data);
/*RteOs_Driving_Fusion_PiFrontRadarInfo_PiFrontRadarInfo*/
extern FUNC(Std_ReturnType, OS_CODE) IocWrite_IocId31_Sender0(FrontRadarInfo data);
extern FUNC(Std_ReturnType, OS_CODE) IocRead_IocId31_Receiver0(FrontRadarInfo* data);
/*RteOs_Driving_Fusion_PiVehicleInfo_PiVehicleInfo*/
extern FUNC(Std_ReturnType, OS_CODE) IocWrite_IocId32_Sender0(VehicleInfo data);
extern FUNC(Std_ReturnType, OS_CODE) IocRead_IocId32_Receiver0(VehicleInfo* data);
/*RteOs_Driving_Fusion_PiVisionLaneSet_PiVisionLaneSet*/
extern FUNC(Std_ReturnType, OS_CODE) IocWrite_IocId33_Sender0(VisionLaneSet data);
extern FUNC(Std_ReturnType, OS_CODE) IocRead_IocId33_Receiver0(VisionLaneSet* data);
/*RteOs_Driving_Fusion_PiVisionObjectSet_PiVisionObjectSet*/
extern FUNC(Std_ReturnType, OS_CODE) IocWrite_IocId34_Sender0(VisionObjectSet data);
extern FUNC(Std_ReturnType, OS_CODE) IocRead_IocId34_Receiver0(VisionObjectSet* data);
/*RteOs_CtApUss_Data_Processing_PiGlobalPoseBuffer_PiGlobalPoseBuffer*/
extern FUNC(Std_ReturnType, OS_CODE) IocWrite_IocId35_Sender0(GlobalPoseBuffer data);
extern FUNC(Std_ReturnType, OS_CODE) IocRead_IocId35_Receiver0(GlobalPoseBuffer* data);
/*RteOs_CtApUss_Data_Processing_PiCarInfoH_PiCarInfoH*/
extern FUNC(Std_ReturnType, OS_CODE) IocWrite_IocId36_Sender0(CarInfoH data);
extern FUNC(Std_ReturnType, OS_CODE) IocRead_IocId36_Receiver0(CarInfoH* data);
/*RteOs_CtApUss_Data_Processing_PiCarInfoL_PiCarInfoL*/
extern FUNC(Std_ReturnType, OS_CODE) IocWrite_IocId37_Sender0(CarInfoL data);
extern FUNC(Std_ReturnType, OS_CODE) IocRead_IocId37_Receiver0(CarInfoL* data);
/*RteOs_CtApUss_Data_Processing_PiPerceptionCommand_PiPerceptionCommand*/
extern FUNC(Std_ReturnType, OS_CODE) IocWrite_IocId38_Sender0(PerceptionCommand data);
extern FUNC(Std_ReturnType, OS_CODE) IocRead_IocId38_Receiver0(PerceptionCommand* data);
/*RteOs_CtApUss_Raw_Data_task_PiCarInfoH_PiCarInfoH*/
extern FUNC(Std_ReturnType, OS_CODE) IocWrite_IocId39_Sender0(CarInfoH data);
extern FUNC(Std_ReturnType, OS_CODE) IocRead_IocId39_Receiver0(CarInfoH* data);
/*RteOs_CtApUss_Raw_Data_task_PiCarInfoL_PiCarInfoL*/
extern FUNC(Std_ReturnType, OS_CODE) IocWrite_IocId40_Sender0(CarInfoL data);
extern FUNC(Std_ReturnType, OS_CODE) IocRead_IocId40_Receiver0(CarInfoL* data);
/*RteOs_CtApUss_Raw_Data_task_PiPerceptionCommand_PiPerceptionCommand*/
extern FUNC(Std_ReturnType, OS_CODE) IocWrite_IocId41_Sender0(PerceptionCommand data);
extern FUNC(Std_ReturnType, OS_CODE) IocRead_IocId41_Receiver0(PerceptionCommand* data);
/*RteOs_CtApState_Machine_ADAS_ACC_OperatingSts_ADAS_ACC_OperatingSts*/
extern FUNC(Std_ReturnType, OS_CODE) IocWrite_IocId42_Sender0(ADAS_ACC_OperatingSts_IDT data);
extern FUNC(Std_ReturnType, OS_CODE) IocRead_IocId42_Receiver0(ADAS_ACC_OperatingSts_IDT* data);
/*RteOs_CtApState_Machine_AEB_TgtDecel_Req_AEB_TgtDecel_Req*/
extern FUNC(Std_ReturnType, OS_CODE) IocWrite_IocId43_Sender0(AEB_TgtDecel_Req_IDT data);
extern FUNC(Std_ReturnType, OS_CODE) IocRead_IocId43_Receiver0(AEB_TgtDecel_Req_IDT* data);
/*RteOs_CtApState_Machine_PiFusionStatus_PiFusionStatus*/
extern FUNC(Std_ReturnType, OS_CODE) IocWrite_IocId44_Sender0(WorkingStatus data);
extern FUNC(Std_ReturnType, OS_CODE) IocRead_IocId44_Receiver0(WorkingStatus* data);
/*RteOs_CtApState_Machine_PiPlanningWorkingStatus_PiPlanningWorkingStatus*/
extern FUNC(Std_ReturnType, OS_CODE) IocWrite_IocId45_Sender0(WorkingStatus data);
extern FUNC(Std_ReturnType, OS_CODE) IocRead_IocId45_Receiver0(WorkingStatus* data);
/*RteOs_CtApState_Machine_PiUssDataProWorkingStatus_P_PiUssDataProWorkingStatus*/
extern FUNC(Std_ReturnType, OS_CODE) IocWrite_IocId46_Sender0(WorkingStatus data);
extern FUNC(Std_ReturnType, OS_CODE) IocRead_IocId46_Receiver0(WorkingStatus* data);
/*RteOs_CtApState_Machine_PiUssFsdWorkingStatus_PiUssFsdWorkingStatus*/
extern FUNC(Std_ReturnType, OS_CODE) IocWrite_IocId47_Sender0(WorkingStatus data);
extern FUNC(Std_ReturnType, OS_CODE) IocRead_IocId47_Receiver0(WorkingStatus* data);
/*RteOs_CtApState_Machine_PiUssPdcWorkingStatus_PiUssPdcWorkingStatus*/
extern FUNC(Std_ReturnType, OS_CODE) IocWrite_IocId48_Sender0(WorkingStatus data);
extern FUNC(Std_ReturnType, OS_CODE) IocRead_IocId48_Receiver0(WorkingStatus* data);
/*RteOs_CtApState_Machine_PiUssStatusSet_PiUssStatusSet*/
extern FUNC(Std_ReturnType, OS_CODE) IocWrite_IocId49_Sender0(UssStatusSet data);
extern FUNC(Std_ReturnType, OS_CODE) IocRead_IocId49_Receiver0(UssStatusSet* data);
/*RteOs_CtApState_Machine_PiUssTaskWorkingStatus_PiUssTaskWorkingStatus*/
extern FUNC(Std_ReturnType, OS_CODE) IocWrite_IocId50_Sender0(WorkingStatus data);
extern FUNC(Std_ReturnType, OS_CODE) IocRead_IocId50_Receiver0(WorkingStatus* data);
/*RteOs_CtApState_Machine_PiVisionStatus_PiVisionStatus*/
extern FUNC(Std_ReturnType, OS_CODE) IocWrite_IocId51_Sender0(WorkingStatus data);
extern FUNC(Std_ReturnType, OS_CODE) IocRead_IocId51_Receiver0(WorkingStatus* data);
/*RteOs_CtApUss_Pdc_PiCarInfoH_PiCarInfoH*/
extern FUNC(Std_ReturnType, OS_CODE) IocWrite_IocId52_Sender0(CarInfoH data);
extern FUNC(Std_ReturnType, OS_CODE) IocRead_IocId52_Receiver0(CarInfoH* data);
/*RteOs_CtApUss_Pdc_PiCarInfoL_PiCarInfoL*/
extern FUNC(Std_ReturnType, OS_CODE) IocWrite_IocId53_Sender0(CarInfoL data);
extern FUNC(Std_ReturnType, OS_CODE) IocRead_IocId53_Receiver0(CarInfoL* data);
/*RteOs_CtApUss_Pdc_PiGlobalPoseBuffer_PiGlobalPoseBuffer*/
extern FUNC(Std_ReturnType, OS_CODE) IocWrite_IocId54_Sender0(GlobalPoseBuffer data);
extern FUNC(Std_ReturnType, OS_CODE) IocRead_IocId54_Receiver0(GlobalPoseBuffer* data);
/*RteOs_CtApUss_Pdc_PiPdcCommand_PiPdcCommand*/
extern FUNC(Std_ReturnType, OS_CODE) IocWrite_IocId55_Sender0(Command data);
extern FUNC(Std_ReturnType, OS_CODE) IocRead_IocId55_Receiver0(Command* data);
/*RteOs_CtApAPA_Control_PiApaDesiredTrajectoryGeneral_PiApaDesiredTrajectoryGeneral*/
extern FUNC(Std_ReturnType, OS_CODE) IocWrite_IocId56_Sender0(DesiredTrajectoryGeneral data);
extern FUNC(Std_ReturnType, OS_CODE) IocRead_IocId56_Receiver0(DesiredTrajectoryGeneral* data);
/*RteOs_CtApAPA_Control_PiParkingSlotError_PiParkingSlotError*/
extern FUNC(Std_ReturnType, OS_CODE) IocWrite_IocId57_Sender0(ParkingSlotError data);
extern FUNC(Std_ReturnType, OS_CODE) IocRead_IocId57_Receiver0(ParkingSlotError* data);
/*RteOs_CtApAPA_Control_PiFusionFreespaceSet_PiFusionFreespaceSet*/
extern FUNC(Std_ReturnType, OS_CODE) IocWrite_IocId58_Sender0(FreespaceSet data);
extern FUNC(Std_ReturnType, OS_CODE) IocRead_IocId58_Receiver0(FreespaceSet* data);
/*RteOs_CtApAPA_Control_PiFusionParkingSlotSet_PiFusionParkingSlotSet*/
extern FUNC(Std_ReturnType, OS_CODE) IocWrite_IocId59_Sender0(ParkingSlotSet data);
extern FUNC(Std_ReturnType, OS_CODE) IocRead_IocId59_Receiver0(ParkingSlotSet* data);
/*RteOs_CtApAPA_Control_PiUssInfo_PiUssInfo*/
extern FUNC(Std_ReturnType, OS_CODE) IocWrite_IocId60_Sender0(UssInfo data);
extern FUNC(Std_ReturnType, OS_CODE) IocRead_IocId60_Receiver0(UssInfo* data);
/*RteOs_CtApDriving_Signal_Transmission_ADAS_APA_SystemSts_ADAS_APA_SystemSts*/
extern FUNC(Std_ReturnType, OS_CODE) IocWrite_IocId61_Sender0(ADAS_APA_SystemSts_IDT data);
extern FUNC(Std_ReturnType, OS_CODE) IocRead_IocId61_Receiver0(ADAS_APA_SystemSts_IDT* data);
/*RteOs_CtApDriving_Signal_Transmission_ADAS_APA_OperationSts_ADAS_APA_OperationSts*/
extern FUNC(Std_ReturnType, OS_CODE) IocWrite_IocId62_Sender0(ADAS_APA_OperationSts_IDT data);
extern FUNC(Std_ReturnType, OS_CODE) IocRead_IocId62_Receiver0(ADAS_APA_OperationSts_IDT* data);
#define OS_STOP_SEC_CODE
#include "Os_MemMap.h"

#endif
