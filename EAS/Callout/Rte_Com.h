/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : Rte_Com.h
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
#ifndef RTE_COM_H
#define RTE_COM_H

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
#include "Com.h"
#include "Rte_Com_Type.h"
#define RTE_START_SEC_CODE
#include "MemMap.h"

#define Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ABS_Status_ABS_HAZActive      NULL_PTR
#define Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ABS_Status_ABS_HAZActive  NULL_PTR
#define Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ABS_Status_ABS_LowBrakeFluid  NULL_PTR
#define Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ABS_Status_ABS_LowBrakeFluid        NULL_PTR
#define Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_AirbagWarningStatus      NULL_PTR
#define Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_AirbagWarningStatus  NULL_PTR
#define Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_CoDAirbagStatus          NULL_PTR
#define Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_CoDAirbagStatus      NULL_PTR
#define Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_CoDSeatOccupSensorStat   NULL_PTR
#define Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_CoDSeatOccupSensorStat         NULL_PTR
#define Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_CoDSeatbletPTighten      NULL_PTR
#define Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_CoDSeatbletPTighten  NULL_PTR
#define Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_CrashFrontOutputSts      NULL_PTR
#define Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_CrashFrontOutputSts  NULL_PTR
#define Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_CrashLeftOutputSts       NULL_PTR
#define Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_CrashLeftOutputSts   NULL_PTR
#define Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_CrashRearOutputSts       NULL_PTR
#define Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_CrashRearOutputSts   NULL_PTR
#define Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_CrashRightOutputSts      NULL_PTR
#define Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_CrashRightOutputSts  NULL_PTR
#define Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_CrashSts       NULL_PTR
#define Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_CrashSts   NULL_PTR
#define Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_DAirbagStatus  NULL_PTR
#define Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_DAirbagStatus        NULL_PTR
#define Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_DSeatOccupSensorStat     NULL_PTR
#define Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_DSeatOccupSensorStat NULL_PTR
#define Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_DSeatbletPTighten        NULL_PTR
#define Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_DSeatbletPTighten    NULL_PTR
#define Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_LCABsts        NULL_PTR
#define Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_LCABsts    NULL_PTR
#define Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_LPSeatOccupSensorStat    NULL_PTR
#define Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_LPSeatOccupSensorStat          NULL_PTR
#define Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_LPSeatbeltBucklestatus   NULL_PTR
#define Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_LPSeatbeltBucklestatus         NULL_PTR
#define Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_LSABsts        NULL_PTR
#define Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_LSABsts    NULL_PTR
#define Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_MPSeatOccupSensorStat    NULL_PTR
#define Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_MPSeatOccupSensorStat          NULL_PTR
#define Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_MPSeatbeltBucklestatus   NULL_PTR
#define Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_MPSeatbeltBucklestatus         NULL_PTR
#define Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_RCABsts        NULL_PTR
#define Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_RCABsts    NULL_PTR
#define Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_RPSeatOccupSensorStat    NULL_PTR
#define Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_RPSeatOccupSensorStat          NULL_PTR
#define Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_RPSeatbeltBucklestatus   NULL_PTR
#define Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_RPSeatbeltBucklestatus         NULL_PTR
#define Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_RSABsts        NULL_PTR
#define Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_RSABsts    NULL_PTR
#define Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_BCM_DoorState_0x4D4_BCM_ATWS_St         NULL_PTR
#define Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_BCM_DoorState_0x4D4_BCM_ATWS_St     NULL_PTR
#define Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_BCM_DoorState_0x4D4_BCM_TailGateSts     NULL_PTR
#define Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_BCM_DoorState_0x4D4_BCM_TailGateSts NULL_PTR
#define Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_BCM_LIGHT_0x106_BCM_AmbeLightZone1Sts   NULL_PTR
#define Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_BCM_LIGHT_0x106_BCM_AmbeLightZone1Sts         NULL_PTR
#define Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_BCM_LIGHT_0x106_BCM_AmbeLightZone2Sts   NULL_PTR
#define Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_BCM_LIGHT_0x106_BCM_AmbeLightZone2Sts         NULL_PTR
#define Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_BCM_LIGHT_0x106_BCM_BrakeLightSts       NULL_PTR
#define Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_BCM_LIGHT_0x106_BCM_BrakeLightSts   NULL_PTR
#define Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_BCM_LIGHT_0x106_BCM_DayRunningLampSts   NULL_PTR
#define Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_BCM_LIGHT_0x106_BCM_DayRunningLampSts         NULL_PTR
#define Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_BCM_LIGHT_0x106_BCM_Fr_domelampSts      NULL_PTR
#define Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_BCM_LIGHT_0x106_BCM_Fr_domelampSts  NULL_PTR
#define Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_BCM_LIGHT_0x106_BCM_HeadLight_adjustSts NULL_PTR
#define Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_BCM_LIGHT_0x106_BCM_HeadLight_adjustSts       NULL_PTR
#define Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_BCM_LIGHT_0x106_BCM_HighBeamSts         NULL_PTR
#define Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_BCM_LIGHT_0x106_BCM_HighBeamSts     NULL_PTR
#define Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_BCM_LIGHT_0x106_BCM_LicensePlateLightSts          NULL_PTR
#define Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_BCM_LIGHT_0x106_BCM_LicensePlateLightSts      NULL_PTR
#define Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_BCM_LIGHT_0x106_BCM_LowBeamSts          NULL_PTR
#define Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_BCM_LIGHT_0x106_BCM_LowBeamSts      NULL_PTR
#define Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_BCM_LIGHT_0x106_BCM_PosLmpSts NULL_PTR
#define Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_BCM_LIGHT_0x106_BCM_PosLmpSts       NULL_PTR
#define Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_BCM_LIGHT_0x106_BCM_RMarkerLightSts     NULL_PTR
#define Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_BCM_LIGHT_0x106_BCM_RMarkerLightSts NULL_PTR
#define Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_BCM_LIGHT_0x106_BCM_RearFogLampLightSts NULL_PTR
#define Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_BCM_LIGHT_0x106_BCM_RearFogLampLightSts       NULL_PTR
#define Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_BCM_LIGHT_0x106_BCM_ReverseLightSts     NULL_PTR
#define Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_BCM_LIGHT_0x106_BCM_ReverseLightSts NULL_PTR
#define Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_BCM_LIGHT_0x106_BCM_Rr_domelampSts      NULL_PTR
#define Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_BCM_LIGHT_0x106_BCM_Rr_domelampSts  NULL_PTR
#define Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_BCM_LIGHT_0x106_BCM_STAT_InteriorLight  NULL_PTR
#define Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_BCM_LIGHT_0x106_BCM_STAT_InteriorLight        NULL_PTR
#define Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_BCM_LIGHT_0x106_BCM_STAT_SwLightBrightness        NULL_PTR
#define Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_BCM_LIGHT_0x106_BCM_STAT_SwLightBrightness    NULL_PTR
#define Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_BCM_PEPS_Sts_BCM_WPC_Off_Req        NULL_PTR
#define Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_BCM_PEPS_Sts_PEPS_Learning_Status   NULL_PTR
#define Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_BCM_RLS_RLS_LightRequest  NULL_PTR
#define Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_BCM_RLS_RLS_LightSensorError        NULL_PTR
#define Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_BCM_RLS_RLS_RainSensorError         NULL_PTR
#define Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_BCM_RLS_RLS_Solar_Left_Driveside    NULL_PTR
#define Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_BCM_RLS_RLS_Solar_Right_PassgSide   NULL_PTR
#define Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_BCM_SwitchSts_0x109_BCM_FFogLampSWSts   NULL_PTR
#define Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_BCM_SwitchSts_0x109_BCM_FFogLampSWSts         NULL_PTR
#define Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_BCM_SwitchSts_0x109_BCM_HighBeamSWSts   NULL_PTR
#define Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_BCM_SwitchSts_0x109_BCM_HighBeamSWSts         NULL_PTR
#define Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_BCM_SwitchSts_0x109_BCM_LowBeamSWSts    NULL_PTR
#define Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_BCM_SwitchSts_0x109_BCM_LowBeamSWSts          NULL_PTR
#define Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_BCM_SwitchSts_0x109_BCM_RFogLampSWSts   NULL_PTR
#define Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_BCM_SwitchSts_0x109_BCM_RFogLampSWSts         NULL_PTR
#define Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_BCM_SwitchSts_0x109_BCM_STAT_HazardWarn NULL_PTR
#define Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_BCM_SwitchSts_0x109_BCM_STAT_HazardWarn       NULL_PTR
#define Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_BCM_SwitchSts_0x109_BCM_STAT_Horn       NULL_PTR
#define Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_BCM_SwitchSts_0x109_BCM_STAT_Horn   NULL_PTR
#define Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_BCM_SwitchSts_0x109_BCM_Tail_MicroSW    NULL_PTR
#define Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_BCM_SwitchSts_0x109_BCM_Tail_MicroSW          NULL_PTR
#define Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_BCM_SwitchSts_0x109_STAT_Central_LockSts          NULL_PTR
#define Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_BCM_SwitchSts_0x109_STAT_Central_LockSts      NULL_PTR
#define Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_BCM_WindowSts_BCM_FLWinAntipinchSts NULL_PTR
#define Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_BCM_WindowSts_BCM_FLWin_Postion     NULL_PTR
#define Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_BCM_WindowSts_BCM_FRWinAntipinchSts NULL_PTR
#define Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_BCM_WindowSts_BCM_FRWin_Postion     NULL_PTR
#define Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_BCM_WindowSts_BCM_FrontWinWashSWSts NULL_PTR
#define Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_BCM_WindowSts_BCM_FrontWipeReturn   NULL_PTR
#define Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_BCM_WindowSts_BCM_RLWinAntipinchSts NULL_PTR
#define Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_BCM_WindowSts_BCM_RLWinIN_Postion   NULL_PTR
#define Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_BCM_WindowSts_BCM_RRWinAntipinchSts NULL_PTR
#define Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_BCM_WindowSts_BCM_RRWin_Postion     NULL_PTR
#define Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_BCM_WindowSts_BCM_RearWinWashSWSts  NULL_PTR
#define Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_BCM_WindowSts_BCM_RearWipeReturn    NULL_PTR
#define Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_BCM_WindowSts_BCM_RearWipeSWSts     NULL_PTR
#define Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_BCM_WindowSts_BCM_RearWipeSts       NULL_PTR
#define Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_BCM_WindowSts_BCM_WinLockSts        NULL_PTR
#define Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_CCU_StsInfo1_CCU_AC_Req       NULL_PTR
#define Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_CCU_StsInfo1_CCU_AC_Req   NULL_PTR
#define Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_CCU_StsInfo1_CCU_AC_Sts       NULL_PTR
#define Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_CCU_StsInfo1_CCU_AC_Sts   NULL_PTR
#define Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_CCU_StsInfo1_CCU_AUTO_Status  NULL_PTR
#define Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_CCU_StsInfo1_CCU_AUTO_Status        NULL_PTR
#define Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_CCU_StsInfo1_CCU_Anion_Generator_Sts    NULL_PTR
#define Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_CCU_StsInfo1_CCU_Anion_Generator_Sts          NULL_PTR
#define Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_CCU_StsInfo1_CCU_Circulation_Sts        NULL_PTR
#define Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_CCU_StsInfo1_CCU_Circulation_Sts    NULL_PTR
#define Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_CCU_StsInfo1_CCU_CompSpdMEAS_Comp       NULL_PTR
#define Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_CCU_StsInfo1_CCU_CompSpdMEAS_Comp   NULL_PTR
#define Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_CCU_StsInfo1_CCU_FrontDefrostSts        NULL_PTR
#define Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_CCU_StsInfo1_CCU_FrontDefrostSts    NULL_PTR
#define Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_CCU_StsInfo1_CCU_Onoff_Sts    NULL_PTR
#define Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_CCU_StsInfo1_CCU_Onoff_Sts          NULL_PTR
#define Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_CCU_StsInfo1_CCU_PTCPwr_Req   NULL_PTR
#define Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_CCU_StsInfo1_CCU_PTCPwr_Req         NULL_PTR
#define Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_CCU_StsInfo1_CCU_PTC_Req      NULL_PTR
#define Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_CCU_StsInfo1_CCU_PTC_Req  NULL_PTR
#define Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_CCU_StsInfo1_CCU_PTCgear_Req_Reserve    NULL_PTR
#define Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_CCU_StsInfo1_CCU_PTCgear_Req_Reserve          NULL_PTR
#define Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_CCU_StsInfo1_CCU_Temp_Sync_Sts          NULL_PTR
#define Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_CCU_StsInfo1_CCU_Temp_Sync_Sts      NULL_PTR
#define Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_CCU_StsInfo1_CCU_evaporator_Temperature NULL_PTR
#define Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_CCU_StsInfo1_CCU_evaporator_Temperature       NULL_PTR
#define Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_EPS_LKA_Sts_EPS_SterMod       NULL_PTR
#define Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_EPS_LKA_Sts_EPS_SterMod   NULL_PTR
#define Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_EPS_LKA_Sts_EPS_SterModV      NULL_PTR
#define Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_EPS_LKA_Sts_EPS_SterModV  NULL_PTR
#define Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ESC_EPB_0x230_EPB_AVHStatIndReq         NULL_PTR
#define Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ESC_EPB_0x230_EPB_AVHStatIndReq     NULL_PTR
#define Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ESC_EPB_0x230_EPB_AVHWrnIndReq          NULL_PTR
#define Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ESC_EPB_0x230_EPB_AVHWrnIndReq      NULL_PTR
#define Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ESC_EPB_0x230_EPB_AVHWrnIndReqV         NULL_PTR
#define Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ESC_EPB_0x230_EPB_AVHWrnIndReqV     NULL_PTR
#define Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ESC_EPB_0x230_EPB_SysBrkLtsReq          NULL_PTR
#define Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ESC_EPB_0x230_EPB_SysBrkLtsReq      NULL_PTR
#define Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ESC_EPB_0x230_EPB_SysDspMsgReq          NULL_PTR
#define Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ESC_EPB_0x230_EPB_SysDspMsgReq      NULL_PTR
#define Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ESC_EPB_0x230_EPB_SysDspMsgReqV         NULL_PTR
#define Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ESC_EPB_0x230_EPB_SysDspMsgReqV     NULL_PTR
#define Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ESC_EPB_0x230_EPB_SysStatIndReq         NULL_PTR
#define Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ESC_EPB_0x230_EPB_SysStatIndReq     NULL_PTR
#define Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ESC_EPB_0x230_EPB_SysStatIndReqV        NULL_PTR
#define Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ESC_EPB_0x230_EPB_SysStatIndReqV    NULL_PTR
#define Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ESC_EPB_0x230_EPB_SysWrnIndReqV         NULL_PTR
#define Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ESC_EPB_0x230_EPB_SysWrnIndReqV     NULL_PTR
#define Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ESC_EPB_0x230_WCBS_Trailermode_Feedback NULL_PTR
#define Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ESC_EPB_0x230_WCBS_Trailermode_Feedback       NULL_PTR
#define Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ESC_Status_0x132_BAS_CtrlActv NULL_PTR
#define Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ESC_Status_0x132_BAS_CtrlActv       NULL_PTR
#define Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ESC_Status_0x132_BAS_FlgFlt   NULL_PTR
#define Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ESC_Status_0x132_BAS_FlgFlt         NULL_PTR
#define Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ESC_Status_0x132_ESC_EscFlgFlt          NULL_PTR
#define Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ESC_Status_0x132_ESC_EscFlgFlt      NULL_PTR
#define Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ESC_Status_0x132_ESC_HBAFlgFlt          NULL_PTR
#define Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ESC_Status_0x132_ESC_HBAFlgFlt      NULL_PTR
#define Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ESC_Status_0x132_ESC_HSA_Status_Fault   NULL_PTR
#define Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ESC_Status_0x132_ESC_HSA_Status_Fault         NULL_PTR
#define Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ESC_Status_0x132_ESC_HbaCtrlActv        NULL_PTR
#define Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ESC_Status_0x132_ESC_HbaCtrlActv    NULL_PTR
#define Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ESC_Status_0x132_ESC_TcsFlgFlt          NULL_PTR
#define Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ESC_Status_0x132_ESC_TcsFlgFlt      NULL_PTR
#define Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_ACC_VLC_AccInTar     NULL_PTR
#define Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_ACC_VLC_AccInTar NULL_PTR
#define Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_IBS_Info_AB_IBS_Sys_Fault_Sts NULL_PTR
#define Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_IBS_Info_AB_IBS_Sys_Fault_Sts       NULL_PTR
#define Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_IPC_TotalOdometer_IPC_Remain_Maintenance      NULL_PTR
#define Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_MHU_ADAS03_Nav_TimeIndcn      NULL_PTR
#define Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_MHU_ADAS03_Nav_TimeIndcn  NULL_PTR
#define Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_MHU_ADAS03_Nav_TimeMod        NULL_PTR
#define Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_MHU_ADAS03_Nav_TimeMod    NULL_PTR
#define Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_MHU_Status_Info_MHU_AVH_Req         NULL_PTR
#define Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_MHU_Status_Info_MHU_ESCOFF_SW_Sts   NULL_PTR
#define Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_MHU_Status_Info_MHU_RegencyLevRequest         NULL_PTR
#define Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_MHU_Status_Info_MHU_VCU_CreepDisable_stt      NULL_PTR
#define Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_VCU_Ctrl_VCU_P_Sts  NULL_PTR
#define Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_VCU_Ctrl_VCU_P_Sts        NULL_PTR
#define Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_VCU_Ctrl_VCU_RegencyLevInd    NULL_PTR
#define Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_VCU_Ctrl_VCU_RegencyLevInd          NULL_PTR
#define Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_VCU_Ctrl_VCU_Warning_IMMO_Fail          NULL_PTR
#define Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_VCU_Ctrl_VCU_Warning_IMMO_Fail      NULL_PTR
#define Rte_COMCbk_Com_CanConfigSet_Rx_Radar_ARS_OD_Header_Signal_Group_ARS_OD_Header     NULL_PTR
#define Rte_COMCbk_Com_CanConfigSet_Rx_Radar_ARS_SYS_PERFORM_ARS_SP_AzimuthCorrection     NULL_PTR
#define Rte_COMCbk_Com_CanConfigSet_Rx_Radar_ARS_SYS_PERFORM_ARS_SP_CalibrationState      NULL_PTR
#define Rte_COMCbk_Com_CanConfigSet_Rx_Radar_ARS_SYS_PERFORM_ARS_SP_ElevationCorrection   NULL_PTR
#define Rte_COMCbk_Com_CanConfigSet_Rx_Radar_ARS_SYS_PERFORM_ARS_SP_ErrStateGroup_4       NULL_PTR
#define Rte_COMCbk_Com_CanConfigSet_Rx_Radar_ARS_SYS_PERFORM_ARS_SP_OperationMode         NULL_PTR
#define Rte_COMCbk_Com_CanConfigSet_Rx_Radar_ARS_SYS_PERFORM_ARS_SP_TunnelFlag  NULL_PTR
#define Rte_COMCbk_Com_CanConfigSet_Rx_Radar_ARS_SYS_PERFORM_ARS_SP_VisibilityRange       NULL_PTR
#define Rte_COMCbk_Com_CanConfigSet_Rx_Radar_ARS_SYS_PERFORM_ARS_SP_VisibilityState       NULL_PTR
#define Rte_COMCbk_Com_CanConfigSet_Rx_Radar_ARS_SYS_PERFORM_Signal_Group_ARS_SYS_PERFORM NULL_PTR
#define Rte_COMCbk_Com_CanConfigSet_Rx_Radar_ARS_TIME_SYNC_Signal_Group_ARS_TIME_SYNC     NULL_PTR
#define Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_01_ADAS_01_Checksum        NULL_PTR
#define Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_01_ADAS_01_RollingCounter  NULL_PTR
#define Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_02_ADAS_02_Checksum        NULL_PTR
#define Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_02_ADAS_02_RollingCounter  NULL_PTR
#define Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_03_ADAS_03_Checksum        NULL_PTR
#define Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_03_ADAS_03_RollingCounter  NULL_PTR
#define Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_Info23_CheckSum_1F8        NULL_PTR
#define Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_Info23_RollingCounter_1F8  NULL_PTR
#define Rte_COMCbk_Com_Tcp_ReceiveSignal                    NULL_PTR
#define Rte_COMCbkTAck_Com_Tcp_SendSignal                   NULL_PTR
#define Rte_COMCbk_Com_Udp_ReceiveSignal                    NULL_PTR
#define Rte_COMCbkTAck_Com_Udp_SendSignal                   NULL_PTR

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_Info17_ADAS_APA_LightReq
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_07_ADAS_APA_SuggestedID
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_Info20_APA_ChimeRequest
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_Info23_APA_EPS_AngReqSts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_Info23_APA_EPS_TargetSteeringAngle
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_Info20_APA_FRegion1ObjectSts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_Info20_APA_FRegion2ObjectSts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_Info20_APA_FRegion3ObjectSts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_Info20_APA_FRegion4ObjectSts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_Info20_APA_FrontExtenedDistance
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_Info20_APA_ParkAssistRExtenedDistance
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_Info20_APA_ParkAssistRRegion1ObjectSts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_Info20_APA_ParkAssistRRegion2ObjectSts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_Info20_APA_ParkAssistRRegion3ObjectSts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_Info20_APA_ParkAssistRRegion4ObjectSts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_Info23_APA_WCBS_BrakeMode
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_Info23_APA_WCBS_ExpectedGearPosition
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_Info23_APA_WCBS_SpeedLimitation
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_Info23_APA_WCBS_TargetStopDistance
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info19_APA_slot_10
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info21_APA_slot_11
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info23_APA_slot_12
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info1_APA_slot_1
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info3_APA_slot_2
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info5_APA_slot_3
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info7_APA_slot_4
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info9_APA_slot_5
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info11_APA_slot_6
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info13_APA_slot_7
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info15_APA_slot_8
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info17_APA_slot_9
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info19_APA_slot_ID_10_P0_X
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info19_APA_slot_ID_10_P0_Y
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info19_APA_slot_ID_10_P1_X
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info19_APA_slot_ID_10_P1_Y
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info20_APA_slot_ID_10_P2_X
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info20_APA_slot_ID_10_P2_Y
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info20_APA_slot_ID_10_P3_X
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info20_APA_slot_ID_10_P3_Y
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info20_APA_slot_ID_10_Type
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info21_APA_slot_ID_11_P0_X
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info21_APA_slot_ID_11_P0_Y
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info21_APA_slot_ID_11_P1_X
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info21_APA_slot_ID_11_P1_Y
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info22_APA_slot_ID_11_P2_X
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info22_APA_slot_ID_11_P2_Y
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info22_APA_slot_ID_11_P3_X
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info22_APA_slot_ID_11_P3_Y
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info22_APA_slot_ID_11_Type
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info23_APA_slot_ID_12_P0_X
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info23_APA_slot_ID_12_P0_Y
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info23_APA_slot_ID_12_P1_X
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info23_APA_slot_ID_12_P1_Y
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info24_APA_slot_ID_12_P2_X
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info24_APA_slot_ID_12_P2_Y
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info24_APA_slot_ID_12_P3_X
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info24_APA_slot_ID_12_P3_Y
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info24_APA_slot_ID_12_Type
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info1_APA_slot_ID_1_P0_X
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info1_APA_slot_ID_1_P0_Y
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info1_APA_slot_ID_1_P1_X
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info1_APA_slot_ID_1_P1_Y
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info2_APA_slot_ID_1_P2_X
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info2_APA_slot_ID_1_P2_Y
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info2_APA_slot_ID_1_P3_X
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info2_APA_slot_ID_1_P3_Y
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info2_APA_slot_ID_1_Type
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info3_APA_slot_ID_2_P0_X
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info3_APA_slot_ID_2_P0_Y
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info3_APA_slot_ID_2_P1_X
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info3_APA_slot_ID_2_P1_Y
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info4_APA_slot_ID_2_P2_X
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info4_APA_slot_ID_2_P2_Y
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info4_APA_slot_ID_2_P3_X
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info4_APA_slot_ID_2_P3_Y
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info4_APA_slot_ID_2_Type
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info5_APA_slot_ID_3_P0_X
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info5_APA_slot_ID_3_P0_Y
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info5_APA_slot_ID_3_P1_X
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info5_APA_slot_ID_3_P1_Y
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info6_APA_slot_ID_3_P2_X
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info6_APA_slot_ID_3_P2_Y
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info6_APA_slot_ID_3_P3_X
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info6_APA_slot_ID_3_P3_Y
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info6_APA_slot_ID_3_Type
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info7_APA_slot_ID_4_P0_X
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info7_APA_slot_ID_4_P0_Y
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info7_APA_slot_ID_4_P1_X
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info7_APA_slot_ID_4_P1_Y
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info8_APA_slot_ID_4_P2_X
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info8_APA_slot_ID_4_P2_Y
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info8_APA_slot_ID_4_P3_X
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info8_APA_slot_ID_4_P3_Y
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info8_APA_slot_ID_4_Type
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info9_APA_slot_ID_5_P0_X
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info9_APA_slot_ID_5_P0_Y
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info9_APA_slot_ID_5_P1_X
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info9_APA_slot_ID_5_P1_Y
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info10_APA_slot_ID_5_P2_X
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info10_APA_slot_ID_5_P2_Y
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info10_APA_slot_ID_5_P3_X
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info10_APA_slot_ID_5_P3_Y
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info10_APA_slot_ID_5_Type
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info11_APA_slot_ID_6_P0_X
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info11_APA_slot_ID_6_P0_Y
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info11_APA_slot_ID_6_P1_X
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info11_APA_slot_ID_6_P1_Y
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info12_APA_slot_ID_6_P2_X
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info12_APA_slot_ID_6_P2_Y
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info12_APA_slot_ID_6_P3_X
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info12_APA_slot_ID_6_P3_Y
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info12_APA_slot_ID_6_Type
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info13_APA_slot_ID_7_P0_X
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info13_APA_slot_ID_7_P0_Y
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info13_APA_slot_ID_7_P1_X
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info13_APA_slot_ID_7_P1_Y
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info14_APA_slot_ID_7_P2_X
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info14_APA_slot_ID_7_P2_Y
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info14_APA_slot_ID_7_P3_X
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info14_APA_slot_ID_7_P3_Y
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info14_APA_slot_ID_7_Type
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info15_APA_slot_ID_8_P0_X
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info15_APA_slot_ID_8_P0_Y
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info15_APA_slot_ID_8_P1_X
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info15_APA_slot_ID_8_P1_Y
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info16_APA_slot_ID_8_P2_X
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info16_APA_slot_ID_8_P2_Y
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info16_APA_slot_ID_8_P3_X
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info16_APA_slot_ID_8_P3_Y
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info16_APA_slot_ID_8_Type
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info17_APA_slot_ID_9_P0_X
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info17_APA_slot_ID_9_P0_Y
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info17_APA_slot_ID_9_P1_X
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info17_APA_slot_ID_9_P1_Y
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info18_APA_slot_ID_9_P2_X
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info18_APA_slot_ID_9_P2_Y
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info18_APA_slot_ID_9_P3_X
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info18_APA_slot_ID_9_P3_Y
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_APA_slot_Info18_APA_slot_ID_9_Type
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_Info21_FLC_ExtenedDistance
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_Info21_FLM_ExtenedDistance
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_Info21_FLS_ExtenedDistance
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_Info21_FRC_ExtenedDistance
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_Info21_FRM_ExtenedDistance
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_Info21_FRS_ExtenedDistance
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_Info22_RLC_ExtenedDistance
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_Info22_RLM_ExtenedDistance
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_Info22_RLS_ExtenedDistance
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_Info22_RRC_ExtenedDistance
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_Info22_RRM_ExtenedDistance
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_Info22_RRS_ExtenedDistance
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ABS_FrontWheelSpeMCUKPH_ABS_FLWheelDirection
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ABS_FrontWheelSpeMCUKPH_ABS_FLWheelDirection
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ABS_FrontWheelSpeMCUKPH_ABS_FLWheelSpeedKPH
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ABS_FrontWheelSpeMCUKPH_ABS_FLWheelSpeedKPH
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ABS_WheelSpeedRC_ABS_FLWheelSpeedRC
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ABS_WheelSpeedRC_ABS_FLWheelSpeedRC
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ABS_FrontWheelSpeMCUKPH_ABS_FRWheelDirection
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ABS_FrontWheelSpeMCUKPH_ABS_FRWheelDirection
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ABS_FrontWheelSpeMCUKPH_ABS_FRWheelSpeedKPH
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ABS_FrontWheelSpeMCUKPH_ABS_FRWheelSpeedKPH
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ABS_WheelSpeedRC_ABS_FRWheelSpeedRC
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ABS_WheelSpeedRC_ABS_FRWheelSpeedRC
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ABS_RearWheelSpeMCUKPH_ABS_RLWheelDirection
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ABS_RearWheelSpeMCUKPH_ABS_RLWheelDirection
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ABS_RearWheelSpeMCUKPH_ABS_RLWheelSpeedKPH
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ABS_RearWheelSpeMCUKPH_ABS_RLWheelSpeedKPH
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ABS_WheelSpeedRC_ABS_RLWheelSpeedRC
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ABS_WheelSpeedRC_ABS_RLWheelSpeedRC
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ABS_RearWheelSpeMCUKPH_ABS_RRWheelDirection
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ABS_RearWheelSpeMCUKPH_ABS_RRWheelDirection
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ABS_RearWheelSpeMCUKPH_ABS_RRWheelSpeedKPH
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ABS_RearWheelSpeMCUKPH_ABS_RRWheelSpeedKPH
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ABS_WheelSpeedRC_ABS_RRWheelSpeedRC
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ABS_WheelSpeedRC_ABS_RRWheelSpeedRC
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ABS_Status_ABS_VehicleSpeed
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ABS_Status_ABS_VehicleSpeed
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_IBS_Info_AB_BrkPedalSwSts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_IBS_Info_AB_BrkPedalSwSts
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_IBS_Info_AB_BrkPedalTravel
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_IBS_Info_AB_BrkPedalTravel
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_IBS_Info_AB_Fault_Status
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_IBS_Info_AB_Fault_Status
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_CoDSeatbeltBucklestatus
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_CoDSeatbeltBucklestatus
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_DSeatbeltBucklestatus
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_DSeatbeltBucklestatus
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_BCM_DoorState_0x4D4_BCM_CodriversSideDoorAjarSts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_BCM_DoorState_0x4D4_BCM_CodriversSideDoorAjarSts
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_BCM_DoorState_0x4D4_BCM_CoverAjarStatus
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_BCM_DoorState_0x4D4_BCM_CoverAjarStatus
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_BCM_DoorState_0x4D4_BCM_DriverSideDoorAjarSts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_BCM_DoorState_0x4D4_BCM_DriverSideDoorAjarSts
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_BCM_DoorState_0x4D4_BCM_RearLeftDoorAjarStatus
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_BCM_DoorState_0x4D4_BCM_RearLeftDoorAjarStatus
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_BCM_DoorState_0x4D4_BCM_RearRightDoorAjarStatus
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_BCM_DoorState_0x4D4_BCM_RearRightDoorAjarStatus
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_BCM_DoorState_0x4D4_BCM_TrunckAjarStatus
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_BCM_DoorState_0x4D4_BCM_TrunckAjarStatus
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_CCU_StsInfo1_CCU_ExternalTemperature
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_CCU_StsInfo1_CCU_ExternalTemperature
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ESC_EPB_0x230_EPB_Sts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ESC_EPB_0x230_EPB_Sts
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_EPS_LKA_Sts_EPS_APA_CtrlAbortFeedback
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_EPS_LKA_Sts_EPS_APA_CtrlAbortFeedback
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_EPS_LKA_Sts_EPS_APA_ModActv
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_EPS_LKA_Sts_EPS_APA_ModActv
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_EPS_LKA_Sts_EPS_APA_ModAvail
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_EPS_LKA_Sts_EPS_APA_ModAvail
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_EPS_LKA_Sts_EPS_DrStrTorqVal
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_EPS_LKA_Sts_EPS_DrStrTorqVal
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ESC_YawAngle_0x3E2_ESC_LateralACC
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ESC_YawAngle_0x3E2_ESC_LateralACC
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ESC_YawAngle_0x3E2_ESC_LongitudeACC
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ESC_YawAngle_0x3E2_ESC_LongitudeACC
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ESC_Status_0x132_ESC_MasterCylinderPressure
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ESC_Status_0x132_ESC_MasterCylinderPressure
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ESC_Status_0x132_ESC_SlopeGradeAngle
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ESC_Status_0x132_ESC_SlopeGradeAngle
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ESC_YawAngle_0x3E2_ESC_VehDynYawRate
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ESC_YawAngle_0x3E2_ESC_VehDynYawRate
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_MHU_ADSA01_MHU_APA_ParkingSpace_ID
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_MHU_Status_Info_MHU_UPAMuteSwitch
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_BCM_PEPS_Sts_PEPS_IGN1RelaySts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_BCM_PEPS_Sts_PEPS_PowerMode
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_SAS_Sensor_0x17E_SAS_SteerWheelAngle
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_SAS_Sensor_0x17E_SAS_SteerWheelAngle
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_SAS_Sensor_0x17E_SAS_SteerWhlRotSpdStatus
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_SAS_Sensor_0x17E_SAS_SteerWhlRotSpdStatus
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_SAS_Sensor_0x17E_SAS_SteerWhlRotSpd
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_SAS_Sensor_0x17E_SAS_SteerWhlRotSpd
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_BCM_TPMS_Info2_TPMS_LFpressureSts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_BCM_TPMS_Info2_TPMS_LFpressure
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_BCM_TPMS_Info2_TPMS_LRpressureSts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_BCM_TPMS_Info2_TPMS_LRpressure
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_BCM_TPMS_Info2_TPMS_RFpressureSts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_BCM_TPMS_Info2_TPMS_RFpressure
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_BCM_TPMS_Info2_TPMS_RRpressureSts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_BCM_TPMS_Info2_TPMS_RRpressure
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_VCU_StsEpt_VCU_AccPedalPosition
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_VCU_StsEpt_VCU_AccPedalPosition
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_VCU_Ctrl_VCU_ModeGearSts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_VCU_Ctrl_VCU_ModeGearSts
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_VCU_StsEpt_VCU_StsSysFault
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_VCU_StsEpt_VCU_StsSysFault
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_APA_CDD_Active
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_APA_CDD_Active
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_APA_VLC_Active
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_APA_VLC_Active
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_APA_VLC_Available
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_APA_VLC_Available
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_APA_VLC_FailureStatus
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_APA_VLC_FailureStatus
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_APA_VLC_Status
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_APA_VLC_Status
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_VStandstillSta
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_VStandstillSta
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Udp_SendSignal_1501
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Udp_SendSignal_1502
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Udp_SendSignal_1503
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Udp_SendSignal_1504
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Udp_SendSignal_1505
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Udp_SendSignal_1506
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Udp_SendSignal_1507
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Tcp_ReceiveSignal_1601
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Tcp_ReceiveSignal_1602
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Tcp_ReceiveSignal_1603
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Tcp_ReceiveSignal_1604
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Tcp_ReceiveSignal_1605
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Tcp_ReceiveSignal_1606
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Tcp_ReceiveSignal_1607
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Tcp_ReceiveSignal_1608
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ABS_Status_ABSFailed
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ABS_Status_ABSFailed
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ABS_Status_ABS_EBDFailed
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ABS_Status_ABS_EBDFailed
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ABS_FrontWheelSpeMCUKPH_ABS_FLWheelSpeedInvalid
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ABS_FrontWheelSpeMCUKPH_ABS_FLWheelSpeedInvalid
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ABS_WheelSpeedRC_ABS_FLWheelSpeedRCSts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ABS_WheelSpeedRC_ABS_FLWheelSpeedRCSts
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ABS_FrontWheelSpeMCUKPH_ABS_FRWheelSpeedInvalid
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ABS_FrontWheelSpeMCUKPH_ABS_FRWheelSpeedInvalid
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ABS_WheelSpeedRC_ABS_FRWheelSpeedRCSts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ABS_WheelSpeedRC_ABS_FRWheelSpeedRCSts
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ABS_FrontWheelSpeMCUKPH_ABS_FWSpeMCUKPH_AliveCounter
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ABS_FrontWheelSpeMCUKPH_ABS_FWSpeMCUKPH_AliveCounter
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ABS_FrontWheelSpeMCUKPH_ABS_FWSpeMCUKPH_CheckSum
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ABS_FrontWheelSpeMCUKPH_ABS_FWSpeMCUKPH_CheckSum
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ABS_RearWheelSpeMCUKPH_ABS_RLWheelSpeedInvalid
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ABS_RearWheelSpeMCUKPH_ABS_RLWheelSpeedInvalid
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ABS_WheelSpeedRC_ABS_RLWheelSpeedRCSts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ABS_WheelSpeedRC_ABS_RLWheelSpeedRCSts
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ABS_RearWheelSpeMCUKPH_ABS_RRWheelSpeedInvalid
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ABS_RearWheelSpeMCUKPH_ABS_RRWheelSpeedInvalid
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ABS_WheelSpeedRC_ABS_RRWheelSpeedRCSts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ABS_WheelSpeedRC_ABS_RRWheelSpeedRCSts
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ABS_RearWheelSpeMCUKPH_ABS_RWSpeMCUKPH_AliveCounter
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ABS_RearWheelSpeMCUKPH_ABS_RWSpeMCUKPH_AliveCounter
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ABS_RearWheelSpeMCUKPH_ABS_RWSpeMCUKPH_CheckSum
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ABS_RearWheelSpeMCUKPH_ABS_RWSpeMCUKPH_CheckSum
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ABS_Status_ABS_Status_AliveCounter
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ABS_Status_ABS_Status_AliveCounter
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ABS_Status_ABS_Status_CheckSum
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ABS_Status_ABS_Status_CheckSum
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ABS_Status_ABS_VehicleSpeedInvalid
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ABS_Status_ABS_VehicleSpeedInvalid
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ABS_WheelSpeedRC_ABS_WheelSpeMCURC_AliveCounter
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ABS_WheelSpeedRC_ABS_WheelSpeMCURC_AliveCounter
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ABS_WheelSpeedRC_ABS_WheelSpeMCURC_CheckSum
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ABS_WheelSpeedRC_ABS_WheelSpeMCURC_CheckSum
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_IBS_Info_AB_BrkPedalSwStsV
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_IBS_Info_AB_BrkPedalSwStsV
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_AliveCounter
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_AliveCounter
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_CheckSum
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ACU_ChimeTelltaleReq_ACU_CheckSum
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_BCM_LIGHT_0x106_BCM_TurnLight_FaultSts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_BCM_LIGHT_0x106_BCM_TurnLight_FaultSts
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_CCU_StsInfo1_CCU_ExternalTemperatureFailSts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_CCU_StsInfo1_CCU_ExternalTemperatureFailSts
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_BCM_LIGHT_0x106_CheckSum_0x106
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_BCM_LIGHT_0x106_CheckSum_0x106
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_BCM_SwitchSts_0x109_CheckSum_0x109
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_BCM_SwitchSts_0x109_CheckSum_0x109
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_EPS_LKA_Sts_CheckSum_0x17F
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_EPS_LKA_Sts_CheckSum_0x17F
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_IPC_TotalOdometer_CheckSum_0x3F1
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_MFS_L_Control_Button2_0x3F7_CheckSum_0x3F7
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_MFS_L_Control_Button2_0x3F7_CheckSum_0x3F7
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ESC_Status_0x132_Checksum_0x132
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ESC_Status_0x132_Checksum_0x132
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_SAS_Sensor_0x17E_Checksum_0x17E
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_SAS_Sensor_0x17E_Checksum_0x17E
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ESC_YawAngle_0x3E2_Checksum_0x3E2
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ESC_YawAngle_0x3E2_Checksum_0x3E2
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ESC_EPB_0x230_Checksum_230
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ESC_EPB_0x230_Checksum_230
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_EPS_LKA_Sts_EPS_ADAS_ModAvail
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_EPS_LKA_Sts_EPS_ADAS_ModAvail
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ESC_YawAngle_0x3E2_ESC_LateralACC_Valid
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ESC_YawAngle_0x3E2_ESC_LateralACC_Valid
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ESC_YawAngle_0x3E2_ESC_LongitudeACC_Valid
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ESC_YawAngle_0x3E2_ESC_LongitudeACC_Valid
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ESC_Status_0x132_ESC_MasterCylinderPressureV
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ESC_Status_0x132_ESC_MasterCylinderPressureV
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ESC_YawAngle_0x3E2_ESC_VehDynYawRate_Valid
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ESC_YawAngle_0x3E2_ESC_VehDynYawRate_Valid
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_MFS_L_Control_Button2_0x3F7_MFS_L2_Failure
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_MFS_L_Control_Button2_0x3F7_MFS_L2_Failure
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_BCM_PEPS_Sts_PEPS_IGN1RelayValidity
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_BCM_PEPS_Sts_PEPS_Message_Sts_AliveCounter
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_BCM_PEPS_Sts_PEPS_Message_Sts_CheckSum
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_BCM_PEPS_Sts_PEPS_PowerModeValidity
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_BCM_LIGHT_0x106_RollingCounter_0x106
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_BCM_LIGHT_0x106_RollingCounter_0x106
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_BCM_SwitchSts_0x109_RollingCounter_0x109
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_BCM_SwitchSts_0x109_RollingCounter_0x109
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ESC_Status_0x132_RollingCounter_0x132
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ESC_Status_0x132_RollingCounter_0x132
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_EPS_LKA_Sts_RollingCounter_0x17F
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_EPS_LKA_Sts_RollingCounter_0x17F
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ESC_YawAngle_0x3E2_RollingCounter_0x3E2
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ESC_YawAngle_0x3E2_RollingCounter_0x3E2
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_IPC_TotalOdometer_RollingCounter_0x3F1
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_MFS_L_Control_Button2_0x3F7_RollingCounter_0x3F7
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_MFS_L_Control_Button2_0x3F7_RollingCounter_0x3F7
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ESC_EPB_0x230_RollingCounter_230
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ESC_EPB_0x230_RollingCounter_230
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_SAS_Sensor_0x17E_Rolling_counter_0x17E
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_SAS_Sensor_0x17E_Rolling_counter_0x17E
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_SAS_Sensor_0x17E_SAS_Calibrated
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_SAS_Sensor_0x17E_SAS_Calibrated
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_SAS_Sensor_0x17E_SAS_SASFailure
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_SAS_Sensor_0x17E_SAS_SASFailure
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_SAS_Sensor_0x17E_SAS_SASStsSnsr
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_SAS_Sensor_0x17E_SAS_SASStsSnsr
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_SAS_Sensor_0x17E_SAS_SteeringAngleValid
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_SAS_Sensor_0x17E_SAS_SteeringAngleValid
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_BCM_TPMS_Info2_TPMS_LFpressureV
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_BCM_TPMS_Info2_TPMS_LRpressureV
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_BCM_TPMS_Info2_TPMS_RFpressureV
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_BCM_TPMS_Info2_TPMS_RRpressureV
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_VCU_StsEpt_VCU_AccPedal_Valid
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_VCU_StsEpt_VCU_AccPedal_Valid
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_VCU_Ctrl_VCU_Ctrl_AliveCounter
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_VCU_Ctrl_VCU_Ctrl_AliveCounter
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_VCU_Ctrl_VCU_Ctrl_CheckSum
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_VCU_Ctrl_VCU_Ctrl_CheckSum
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_VCU_StsEpt_VCU_StsEpt_AliveCounter
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_VCU_StsEpt_VCU_StsEpt_AliveCounter
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_VCU_StsEpt_VCU_StsEpt_CheckSum
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_VCU_StsEpt_VCU_StsEpt_CheckSum
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_ABAAva
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_ABAAva
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_ABPAva
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_ABPAva
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_ACC_VLC_Avl
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_ACC_VLC_Avl
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_AEBAva
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_AEBAva
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_AWBAvl
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_AWBAvl
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_ESCDeteACCErroSta
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_ESCDeteACCErroSta
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_08_ADAS_ECU_Fault
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_08_ADAS_FrontCamera_Fault
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_08_ADAS_LeftCamera_Fault
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_08_ADAS_RearCamera_Fault
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_08_ADAS_RightCamera_Fault
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_TBOX_DateTime1_GPSSystAtv
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_TBOX_DateTime1_GPSSystAtv
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_TBOX_DateTime1_Time_Day
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_TBOX_DateTime1_Time_Day
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_TBOX_DateTime1_Time_Hour
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_TBOX_DateTime1_Time_Hour
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_TBOX_DateTime1_Time_Minute
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_TBOX_DateTime1_Time_Minute
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_TBOX_DateTime1_Time_Month
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_TBOX_DateTime1_Time_Month
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_TBOX_DateTime1_Time_Year
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_TBOX_DateTime1_Time_Year
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_TBOX_DateTime1_Time_second
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_TBOX_DateTime1_Time_second
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_07_ADAS_APA_AbortWarning
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_Info23_ADAS_APA_BrakeModeSts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_07_ADAS_APA_ModeSelect
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_07_ADAS_APA_OperationSts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_Info17_ADAS_APA_OtherWarning
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_07_ADAS_APA_OverspeedAlarm
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_07_ADAS_APA_ParkingDirection
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_Info17_ADAS_APA_ParkingModeReq
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_07_ADAS_APA_ParkingType
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_07_ADAS_APA_PauseWarning
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_Info17_ADAS_APA_RemindTxt1
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_Info17_ADAS_APA_RemindTxt2
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_07_ADAS_APA_RenewParkingReq
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_Info17_ADAS_APA_SearchingWarning
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_Info17_ADAS_APA_Soundremind
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_07_ADAS_APA_StartParkingReq
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_07_ADAS_APA_SystemSts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_Info21_ADAS_USS_FaultFLI
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_Info21_ADAS_USS_FaultFLO
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_Info21_ADAS_USS_FaultFLS
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_Info21_ADAS_USS_FaultFRI
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_Info21_ADAS_USS_FaultFRO
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_Info21_ADAS_USS_FaultFRS
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_Info22_ADAS_USS_FaultRLI
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_Info22_ADAS_USS_FaultRLO
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_Info22_ADAS_USS_FaultRLS
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_Info22_ADAS_USS_FaultRRI
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_Info22_ADAS_USS_FaultRRO
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_Info22_ADAS_USS_FaultRRS
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_Info20_APA_FrontSystemSts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_Info20_APA_RearSystemSts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_Info23_APA_WCBS_BrakeFunctionMode
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ESC_EPB_0x230_EPB_SysWrnIndReq
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ESC_EPB_0x230_EPB_SysWrnIndReq
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_EPS_LKA_Sts_EPS_SterFltMod
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_EPS_LKA_Sts_EPS_SterFltMod
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ESC_Status_0x132_ESC_TcsCtrlActv
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ESC_Status_0x132_ESC_TcsCtrlActv
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_MHU_ADSA01_MHU_APA_ParkIn_Req
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_MHU_ADSA01_MHU_APA_ParkOut_Direction
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_MHU_ADSA01_MHU_APA_ParkOut_Mode
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_MHU_ADSA01_MHU_APA_ParkOut_Req
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_MHU_ADSA01_MHU_APA_ParkingReCover_Req
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_MHU_ADSA01_MHU_APA_ParkingStart_Req
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_MHU_ADSA01_MHU_APA_Req
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_BCM_TPMS_Info2_TPMS_SysSts
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_VCU_Ctrl_VCU_Ready
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_VCU_Ctrl_VCU_Ready
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_APA_EmgyBrkAvlb
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_APA_EmgyBrkAvlb
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_04_ACC_AdtLowerJerkLimit
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_04_ACC_AdtUpperJerkLimit
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_08_ACC_DriveoffReq
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_08_ACC_TxtInfoForDriver
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_04_ADAS_ACC_BrakePreferred
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_01_ADAS_ACC_DistanceLevel
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_01_ADAS_ACC_ObjDispSts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_01_ADAS_ACC_OperatingSts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_01_ADAS_ACC_SpdUnit
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_01_ADAS_ACC_TakeOverReq
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_01_ADAS_ACC_TargetSpeed
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_01_ADAS_ACC_TimeGapLevel
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_04_ADAS_AEB_AbaLevel
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_04_ADAS_AEB_AbpReq
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_Info15_ADAS_AEB_FuncSWResp
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_03_ADAS_AEB_TgtDecel_ReqValue
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_03_ADAS_AccelerationReq
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_02_ADAS_EPS_AngReqSts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_02_ADAS_EPS_TargetSteeringAngle
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_02_ADAS_EPS_Vibration_Req
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_04_ADAS_IBS_CarStarting
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_04_ADAS_IBS_EBAReq
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_04_ADAS_IBS_MinBreakReq
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_04_ADAS_IBS_StopReq
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_02_ADAS_LSS_AngCmdReqPortnValue
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_02_ADAS_LSS_AssidFormResp
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_06_ADAS_LSS_Available
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_06_ADAS_LSS_ErrSts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_06_ADAS_LSS_FunSts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_02_ADAS_LSS_FuncResp
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_02_ADAS_LSS_HandsoffWarn
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_02_ADAS_LSS_LeLineTrackingSts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_02_ADAS_LSS_RiLineTrackingSts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_02_ADAS_LSS_VoiceWarn
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_06_ADAS_LSS_WarnFromResp
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_03_ADAS_MaxSoftAcceleration
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_03_ADAS_MinSoftAcceleration
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_06_ADAS_TSR_OperationSts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_06_ADAS_TSR_SWSts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_06_ADAS_TSR_SpeedLimit
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_04_ADAS_VLCModeReq
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_04_ADAS_VLCShutDownReq
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_04_AEB_ABA_Req
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_04_AEB_AWB_Level
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_04_AEB_AWB_Req
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_Info15_AEB_ErrorSts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_Info15_AEB_FCW_Warning
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_Info15_AEB_FuncSts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_04_AEB_TgtDecel_Req
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_Info15_AEB_VRUActive
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_Info15_AEB_VehActive
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_04_AEB_VehHldReq
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_Info15_AEB_FCW_SnvtyResp
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_06_FC_BlockageSts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_06_FC_CalibrationSts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_06_TSR_SLWSwtResp
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_Info15_TSR_SLWVisualWarn
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_Info15_TSR_SLWVoiceWarn
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_Info15_TSR_SpdAssistInfoDisp
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_Info15_TSR_TrafSign
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_CanConfigSet_Tx_ACAN_ADAS_Info15_TSR_Warning_offset
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ABS_Status_ABSActive
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ABS_Status_ABSActive
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_IBS_Info_AB_BrkPedalPct
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_IBS_Info_AB_BrkPedalPct
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_MHU_ADSA01_AEB_FCW_SnvtyReq
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_MHU_ADSA01_AEB_FuncSwtReq
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_BCM_WindowSts_BCM_AutoWipeSts
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_BCM_DoorState_0x4D4_BCM_DoorLockStatusCodrivres
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_BCM_DoorState_0x4D4_BCM_DoorLockStatusCodrivres
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_BCM_DoorState_0x4D4_BCM_DoorLockStatusDrv
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_BCM_DoorState_0x4D4_BCM_DoorLockStatusDrv
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_BCM_DoorState_0x4D4_BCM_DoorLockStatusRL
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_BCM_DoorState_0x4D4_BCM_DoorLockStatusRL
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_BCM_DoorState_0x4D4_BCM_DoorLockStatusRR
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_BCM_DoorState_0x4D4_BCM_DoorLockStatusRR
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_BCM_LIGHT_0x106_BCM_FrontFogLampLightSts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_BCM_LIGHT_0x106_BCM_FrontFogLampLightSts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_BCM_WindowSts_BCM_FrontWipeSWSts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_BCM_WindowSts_BCM_FrontWipeSts
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_BCM_LIGHT_0x106_BCM_TurnIndicatorSts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_BCM_LIGHT_0x106_BCM_TurnIndicatorSts
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_BCM_SwitchSts_0x109_BCM_TurnLightSWSts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_BCM_SwitchSts_0x109_BCM_TurnLightSWSts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_MHU_ADSA01_BSD_LCA_FuncSWReq
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ESC_Status_0x132_ESC_TcsDisableSts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ESC_Status_0x132_ESC_TcsDisableSts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_MHU_ADSA01_DOW_FuncSWReq
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ESC_EPB_0x230_EPB_AVHFeedbackSts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ESC_EPB_0x230_EPB_AVHFeedbackSts
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ESC_EPB_0x230_EPB_AVHStatIndReqV
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ESC_EPB_0x230_EPB_AVHStatIndReqV
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_EPS_LKA_Sts_EPS_ADAS_CtrlAbortFeedback
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_EPS_LKA_Sts_EPS_ADAS_CtrlAbortFeedback
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_EPS_LKA_Sts_EPS_ADAS_ModActv
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_EPS_LKA_Sts_EPS_ADAS_ModActv
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_EPS_LKA_Sts_EPS_DrStrTorqV
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_EPS_LKA_Sts_EPS_DrStrTorqV
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_EPS_LKA_Sts_EPS_LKARespTorq
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_EPS_LKA_Sts_EPS_LKARespTorq
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ESC_Status_0x132_ESC_EscCtrlActv
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ESC_Status_0x132_ESC_EscCtrlActv
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ESC_Status_0x132_ESC_EscDisableSts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ESC_Status_0x132_ESC_EscDisableSts
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ESC_Status_0x132_ESC_HSA_Control_Status
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ESC_Status_0x132_ESC_HSA_Control_Status
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_ESC_Status_0x132_IBS_ESCOFF_StsFB
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_ESC_Status_0x132_IBS_ESCOFF_StsFB
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_IPC_TotalOdometer_IPC_IPCTotalOdometerV
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_IPC_TotalOdometer_IPC_IPCTotalOdometer
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_MFS_L_Control_Button2_0x3F7_MFS_ACC_CruiseCancel
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_MFS_L_Control_Button2_0x3F7_MFS_ACC_CruiseCancel
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_MFS_L_Control_Button2_0x3F7_MFS_ACC_CruiseGapSet
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_MFS_L_Control_Button2_0x3F7_MFS_ACC_CruiseGapSet
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_MFS_L_Control_Button2_0x3F7_MFS_ACC_CruiseOn_Off
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_MFS_L_Control_Button2_0x3F7_MFS_ACC_CruiseOn_Off
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_MFS_L_Control_Button2_0x3F7_MFS_ACC_CruiseSpdDecrease
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_MFS_L_Control_Button2_0x3F7_MFS_ACC_CruiseSpdDecrease
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_MFS_L_Control_Button2_0x3F7_MFS_ACC_CruiseSpdIncrease
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_MFS_L_Control_Button2_0x3F7_MFS_ACC_CruiseSpdIncrease
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_MHU_Status_Info_MHU_DM_SwitchModeSts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_MHU_ADSA01_MHU_LSS_Mode
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_MHU_ADSA01_MHU_LSS_Req
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_MHU_ADSA01_MHU_LSS_WarningMethod
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_MHU_ADSA01_MHU_TSR_Req
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_MHU_Status_Info_MHU_Trailermode_Req
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_MHU_ADAS02_Nav_CtryType
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_MHU_ADAS02_Nav_CtryType
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_MHU_ADAS02_Nav_RoadType
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_MHU_ADAS02_Nav_RoadType
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_MHU_ADAS02_Nav_SpdLimType
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_MHU_ADAS02_Nav_SpdLimType
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_MHU_ADAS02_Nav_SpdLimUnit
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_MHU_ADAS02_Nav_SpdLimUnit
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_MHU_ADAS02_Nav_SpdLimValue
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_MHU_ADAS02_Nav_SpdLimValue
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_MHU_ADAS02_Nav_TSRTrafSign
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_MHU_ADAS02_Nav_TSRTrafSign
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_MHU_ADAS02_Nav_VehToTrafEyeDist
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_MHU_ADAS02_Nav_VehToTrafEyeDist
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_MHU_ADAS02_Nav_errorSts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_MHU_ADAS02_Nav_errorSts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_MHU_ADSA01_RCTA_FuncSWReq
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_MHU_ADSA01_RCW_FuncSWReq
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_BCM_RLS_RLS_Rainfall_magnitude
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_Radar_ARS_OD_00_01_Signal_Group_ARS_OD_00_01
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_Radar_ARS_OD_02_03_Signal_Group_ARS_OD_02_03
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_Radar_ARS_OD_04_05_Signal_Group_ARS_OD_04_05
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_Radar_ARS_OD_06_07_Signal_Group_ARS_OD_06_07
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_Radar_ARS_OD_08_09_Signal_Group_ARS_OD_08_09
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_Radar_ARS_OD_10_11_Signal_Group_ARS_OD_10_11
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_Radar_ARS_OD_12_13_Signal_Group_ARS_OD_12_13
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_Radar_ARS_OD_14_15_Signal_Group_ARS_OD_14_15
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_Radar_ARS_OD_16_17_Signal_Group_ARS_OD_16_17
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_Radar_ARS_OD_18_19_Signal_Group_ARS_OD_18_19
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_Radar_ARS_OD_20_21_Signal_Group_ARS_OD_20_21
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_Radar_ARS_OD_22_23_Signal_Group_ARS_OD_22_23
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_Radar_ARS_OD_24_25_Signal_Group_ARS_OD_24_25
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_Radar_ARS_OD_26_27_Signal_Group_ARS_OD_26_27
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_Radar_ARS_OD_28_29_Signal_Group_ARS_OD_28_29
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_Radar_ARS_OD_30_31_Signal_Group_ARS_OD_30_31
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_MHU_ADSA01_TSR_SLWFuncSwtReq
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_MHU_ADSA01_TSR_SpdWarningOffs_S
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_VCU_Ctrl_VCU_LimpHomeSts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_VCU_Ctrl_VCU_LimpHomeSts
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_VCU_StsEpt_VCU_StsAccPedalFault
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_VCU_StsEpt_VCU_StsAccPedalFault
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_ABAAtv
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_ABAAtv
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_ABPAtv
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_ABPAtv
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_ACC_CDD_Active
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_ACC_CDD_Active
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_ACC_CDD_Avl
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_ACC_CDD_Avl
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_ACC_VLC_Active
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_ACC_VLC_Active
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_AEBAtv
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_AEBAtv
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_AWBAtv
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_AWBAtv
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_BrkFrcSta
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_CanConfigSet_Rx_ACAN_IBS_ADAS_Info_WCBS_BrkFrcSta
(
    void
);

#define RTE_STOP_SEC_CODE
#include "MemMap.h"

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif  /*RTE_COM_H*/


