/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : Rte_NvM.h
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
#ifndef RTE_NVM_H
#define RTE_NVM_H

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
#include "NvM.h"
#include "Rte_NvM_Type.h"
#define RTE_START_SEC_CODE
#include "MemMap.h"

#define NvM_Rte_Block_27SecurityAttemp_NVM_Init_SecurityAttemp        Rte_Call_NvM_PNIB_Block_27SecurityAttemp_InitBlock
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_PNIB_Block_27SecurityAttemp_InitBlock
(
    void
);
#define NvM_Rte_Block_Base1000T1Sqi_0xF1C3_NVM_Init_Base1000T1Sqi_0xF1C3        Rte_Call_NvM_PNIB_Block_Base1000T1Sqi_0xF1C3_InitBlock
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_PNIB_Block_Base1000T1Sqi_0xF1C3_InitBlock
(
    void
);
#define NvM_Rte_Block_Base100T1Sqi_0xF1C2_NVM_Init_Base100T1Sqi_0xF1C2          Rte_Call_NvM_PNIB_Block_Base100T1Sqi_0xF1C2_InitBlock
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_PNIB_Block_Base100T1Sqi_0xF1C2_InitBlock
(
    void
);
#define NvM_Rte_Block_Dem_Dem_NvM_InitStorageMem            Rte_Call_NvM_PNIB_Block_Dem_InitBlock
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_PNIB_Block_Dem_InitBlock
(
    void
);
#define NvM_Rte_Block_DynamicCalibrationInfo_0x4F4C_NVM_Init_DynamicCalibrationInfo_0x4F4C          Rte_Call_NvM_PNIB_Block_DynamicCalibrationInfo_0x4F4C_InitBlock
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_PNIB_Block_DynamicCalibrationInfo_0x4F4C_InitBlock
(
    void
);
#define NvM_Rte_Block_EnableXcp_0x4F30_NVM_Init_EnableXcp_0x4F30      Rte_Call_NvM_PNIB_Block_EnableXcp_0x4F30_InitBlock
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_PNIB_Block_EnableXcp_0x4F30_InitBlock
(
    void
);
#define NvM_Rte_Block_MasterSlaveState_0xF1C8_NVM_Init_MasterSlaveState_0xF1C8  Rte_Call_NvM_PNIB_Block_MasterSlaveState_0xF1C8_InitBlock
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_PNIB_Block_MasterSlaveState_0xF1C8_InitBlock
(
    void
);
#define NvM_Rte_Block_RepairShopCode_0xF198_NVM_Init_RepairShopCode_0xF198      Rte_Call_NvM_PNIB_Block_RepairShopCode_0xF198_InitBlock
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_PNIB_Block_RepairShopCode_0xF198_InitBlock
(
    void
);
#define NvM_Rte_Block_StaticCalibrationInfo_0x4F4A_NVM_Init_StaticCalibrationInfo_0x4F4A  Rte_Call_NvM_PNIB_Block_StaticCalibrationInfo_0x4F4A_InitBlock
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_PNIB_Block_StaticCalibrationInfo_0x4F4A_InitBlock
(
    void
);
#define NvM_Rte_Block_SwitchArlTable_0xF1CB_NVM_Init_SwitchArlTable_0xF1CB      Rte_Call_NvM_PNIB_Block_SwitchArlTable_0xF1CB_InitBlock
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_PNIB_Block_SwitchArlTable_0xF1CB_InitBlock
(
    void
);
#define NvM_Rte_Block_VIN_0xF190_NVM_Init_VIN_0xF190        Rte_Call_NvM_PNIB_Block_VIN_0xF190_InitBlock
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_PNIB_Block_VIN_0xF190_InitBlock
(
    void
);
#define NvM_Rte_Block_WorkMode_0x4F4D_NVM_Init_WorkMode_0x4F4D        Rte_Call_NvM_PNIB_Block_WorkMode_0x4F4D_InitBlock
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_PNIB_Block_WorkMode_0x4F4D_InitBlock
(
    void
);
#define NvM_Rte_Block_27SecurityAttemp_SecurityAttemp       Rte_Call_NvM_PNJY_Block_27SecurityAttemp_JobFinished
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_PNJY_Block_27SecurityAttemp_JobFinished
(
    VAR(uint8, AUTOMATIC) ServiceId,
    VAR(NvM_RequestResultType, AUTOMATIC) JobResult
);
#define NvM_Rte_Block_Base1000T1Sqi_0xF1C3_Base1000T1Sqi_0xF1C3       Rte_Call_NvM_PNJY_Block_Base1000T1Sqi_0xF1C3_JobFinished
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_PNJY_Block_Base1000T1Sqi_0xF1C3_JobFinished
(
    VAR(uint8, AUTOMATIC) ServiceId,
    VAR(NvM_RequestResultType, AUTOMATIC) JobResult
);
#define NvM_Rte_Block_Base100T1Sqi_0xF1C2_Base100T1Sqi_0xF1C2         Rte_Call_NvM_PNJY_Block_Base100T1Sqi_0xF1C2_JobFinished
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_PNJY_Block_Base100T1Sqi_0xF1C2_JobFinished
(
    VAR(uint8, AUTOMATIC) ServiceId,
    VAR(NvM_RequestResultType, AUTOMATIC) JobResult
);
#define NvM_Rte_Block_DynamicCalibrationInfo_0x4F4C_DynamicCalibrationInfo_0x4F4C         Rte_Call_NvM_PNJY_Block_DynamicCalibrationInfo_0x4F4C_JobFinished
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_PNJY_Block_DynamicCalibrationInfo_0x4F4C_JobFinished
(
    VAR(uint8, AUTOMATIC) ServiceId,
    VAR(NvM_RequestResultType, AUTOMATIC) JobResult
);
#define NvM_Rte_Block_EnableXcp_0x4F30_EnableXcp_0x4F30     Rte_Call_NvM_PNJY_Block_EnableXcp_0x4F30_JobFinished
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_PNJY_Block_EnableXcp_0x4F30_JobFinished
(
    VAR(uint8, AUTOMATIC) ServiceId,
    VAR(NvM_RequestResultType, AUTOMATIC) JobResult
);
#define NvM_Rte_Block_MasterSlaveState_0xF1C8_MasterSlaveState_0xF1C8 Rte_Call_NvM_PNJY_Block_MasterSlaveState_0xF1C8_JobFinished
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_PNJY_Block_MasterSlaveState_0xF1C8_JobFinished
(
    VAR(uint8, AUTOMATIC) ServiceId,
    VAR(NvM_RequestResultType, AUTOMATIC) JobResult
);
#define NvM_Rte_Block_RepairShopCode_0xF198_RepairShopCode_0xF198     Rte_Call_NvM_PNJY_Block_RepairShopCode_0xF198_JobFinished
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_PNJY_Block_RepairShopCode_0xF198_JobFinished
(
    VAR(uint8, AUTOMATIC) ServiceId,
    VAR(NvM_RequestResultType, AUTOMATIC) JobResult
);
#define NvM_Rte_Block_StaticCalibrationInfo_0x4F4A_StaticCalibrationInfo_0x4F4A Rte_Call_NvM_PNJY_Block_StaticCalibrationInfo_0x4F4A_JobFinished
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_PNJY_Block_StaticCalibrationInfo_0x4F4A_JobFinished
(
    VAR(uint8, AUTOMATIC) ServiceId,
    VAR(NvM_RequestResultType, AUTOMATIC) JobResult
);
#define NvM_Rte_Block_SwitchArlTable_0xF1CB_SwitchArlTable_0xF1CB     Rte_Call_NvM_PNJY_Block_SwitchArlTable_0xF1CB_JobFinished
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_PNJY_Block_SwitchArlTable_0xF1CB_JobFinished
(
    VAR(uint8, AUTOMATIC) ServiceId,
    VAR(NvM_RequestResultType, AUTOMATIC) JobResult
);
#define NvM_Rte_Block_VIN_0xF190_VIN_0xF190                 Rte_Call_NvM_PNJY_Block_VIN_0xF190_JobFinished
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_PNJY_Block_VIN_0xF190_JobFinished
(
    VAR(uint8, AUTOMATIC) ServiceId,
    VAR(NvM_RequestResultType, AUTOMATIC) JobResult
);
#define NvM_Rte_Block_WorkMode_0x4F4D_WorkMode_0x4F4D       Rte_Call_NvM_PNJY_Block_WorkMode_0x4F4D_JobFinished
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_PNJY_Block_WorkMode_0x4F4D_JobFinished
(
    VAR(uint8, AUTOMATIC) ServiceId,
    VAR(NvM_RequestResultType, AUTOMATIC) JobResult
);
#define Rte_Call_PS_Block0_GetErrorStatus(RequestResultPtr) NvM_GetErrorStatus(NvM_Block0, RequestResultPtr)
#define Rte_Call_PS_Block0_ReadBlock(DstPtr)                NvM_ReadBlock(NvM_Block0, DstPtr)
#define Rte_Call_PS_Block0_WriteBlock(SrcPtr)               NvM_WriteBlock(NvM_Block0, SrcPtr)
#define Rte_Call_PS_Block0_RestoreBlockDefaults(DstPtr)     NvM_RestoreBlockDefaults(NvM_Block0, DstPtr)
#define Rte_Call_PS_Block0_SetRamBlockStatus(BlockChanged)  NvM_SetRamBlockStatus(NvM_Block0, BlockChanged)
#define Rte_Call_PS_Block_27SecurityAttemp_GetErrorStatus(RequestResultPtr)     NvM_GetErrorStatus(NvM_Block_27SecurityAttemp, RequestResultPtr)
#define Rte_Call_PS_Block_27SecurityAttemp_ReadBlock(DstPtr)          NvM_ReadBlock(NvM_Block_27SecurityAttemp, DstPtr)
#define Rte_Call_PS_Block_27SecurityAttemp_WriteBlock(SrcPtr)         NvM_WriteBlock(NvM_Block_27SecurityAttemp, SrcPtr)
#define Rte_Call_PS_Block_27SecurityAttemp_RestoreBlockDefaults(DstPtr)         NvM_RestoreBlockDefaults(NvM_Block_27SecurityAttemp, DstPtr)
#define Rte_Call_PS_Block_27SecurityAttemp_SetRamBlockStatus(BlockChanged)      NvM_SetRamBlockStatus(NvM_Block_27SecurityAttemp, BlockChanged)
#define Rte_Call_PS_Block_Base1000T1Sqi_0xF1C3_GetErrorStatus(RequestResultPtr) NvM_GetErrorStatus(NvM_Block_Base1000T1Sqi_0xF1C3, RequestResultPtr)
#define Rte_Call_PS_Block_Base1000T1Sqi_0xF1C3_ReadBlock(DstPtr)      NvM_ReadBlock(NvM_Block_Base1000T1Sqi_0xF1C3, DstPtr)
#define Rte_Call_PS_Block_Base1000T1Sqi_0xF1C3_WriteBlock(SrcPtr)     NvM_WriteBlock(NvM_Block_Base1000T1Sqi_0xF1C3, SrcPtr)
#define Rte_Call_PS_Block_Base1000T1Sqi_0xF1C3_RestoreBlockDefaults(DstPtr)     NvM_RestoreBlockDefaults(NvM_Block_Base1000T1Sqi_0xF1C3, DstPtr)
#define Rte_Call_PS_Block_Base1000T1Sqi_0xF1C3_SetRamBlockStatus(BlockChanged)  NvM_SetRamBlockStatus(NvM_Block_Base1000T1Sqi_0xF1C3, BlockChanged)
#define Rte_Call_PS_Block_Base100T1Sqi_0xF1C2_GetErrorStatus(RequestResultPtr)  NvM_GetErrorStatus(NvM_Block_Base100T1Sqi_0xF1C2, RequestResultPtr)
#define Rte_Call_PS_Block_Base100T1Sqi_0xF1C2_ReadBlock(DstPtr)       NvM_ReadBlock(NvM_Block_Base100T1Sqi_0xF1C2, DstPtr)
#define Rte_Call_PS_Block_Base100T1Sqi_0xF1C2_WriteBlock(SrcPtr)      NvM_WriteBlock(NvM_Block_Base100T1Sqi_0xF1C2, SrcPtr)
#define Rte_Call_PS_Block_Base100T1Sqi_0xF1C2_RestoreBlockDefaults(DstPtr)      NvM_RestoreBlockDefaults(NvM_Block_Base100T1Sqi_0xF1C2, DstPtr)
#define Rte_Call_PS_Block_Base100T1Sqi_0xF1C2_SetRamBlockStatus(BlockChanged)   NvM_SetRamBlockStatus(NvM_Block_Base100T1Sqi_0xF1C2, BlockChanged)
#define Rte_Call_PS_Block_CfgID_GetErrorStatus(RequestResultPtr)      NvM_GetErrorStatus(NvM_Block_CfgID, RequestResultPtr)
#define Rte_Call_PS_Block_CfgID_ReadBlock(DstPtr)           NvM_ReadBlock(NvM_Block_CfgID, DstPtr)
#define Rte_Call_PS_Block_CfgID_WriteBlock(SrcPtr)          NvM_WriteBlock(NvM_Block_CfgID, SrcPtr)
#define Rte_Call_PS_Block_CfgID_RestoreBlockDefaults(DstPtr)          NvM_RestoreBlockDefaults(NvM_Block_CfgID, DstPtr)
#define Rte_Call_PS_Block_CfgID_SetRamBlockStatus(BlockChanged)       NvM_SetRamBlockStatus(NvM_Block_CfgID, BlockChanged)
#define Rte_Call_PS_Block_Dem_GetErrorStatus(RequestResultPtr)        NvM_GetErrorStatus(NvM_Block_Dem, RequestResultPtr)
#define Rte_Call_PS_Block_Dem_ReadBlock(DstPtr)             NvM_ReadBlock(NvM_Block_Dem, DstPtr)
#define Rte_Call_PS_Block_Dem_WriteBlock(SrcPtr)            NvM_WriteBlock(NvM_Block_Dem, SrcPtr)
#define Rte_Call_PS_Block_Dem_RestoreBlockDefaults(DstPtr)  NvM_RestoreBlockDefaults(NvM_Block_Dem, DstPtr)
#define Rte_Call_PS_Block_Dem_SetRamBlockStatus(BlockChanged)         NvM_SetRamBlockStatus(NvM_Block_Dem, BlockChanged)
#define Rte_Call_PS_Block_DynamicCalibrationInfo_0x4F4C_GetErrorStatus(RequestResultPtr)  NvM_GetErrorStatus(NvM_Block_DynamicCalibrationInfo_0x4F4C, RequestResultPtr)
#define Rte_Call_PS_Block_DynamicCalibrationInfo_0x4F4C_ReadBlock(DstPtr)       NvM_ReadBlock(NvM_Block_DynamicCalibrationInfo_0x4F4C, DstPtr)
#define Rte_Call_PS_Block_DynamicCalibrationInfo_0x4F4C_WriteBlock(SrcPtr)      NvM_WriteBlock(NvM_Block_DynamicCalibrationInfo_0x4F4C, SrcPtr)
#define Rte_Call_PS_Block_DynamicCalibrationInfo_0x4F4C_RestoreBlockDefaults(DstPtr)      NvM_RestoreBlockDefaults(NvM_Block_DynamicCalibrationInfo_0x4F4C, DstPtr)
#define Rte_Call_PS_Block_DynamicCalibrationInfo_0x4F4C_SetRamBlockStatus(BlockChanged)   NvM_SetRamBlockStatus(NvM_Block_DynamicCalibrationInfo_0x4F4C, BlockChanged)
#define Rte_Call_PS_Block_EnableXcp_0x4F30_GetErrorStatus(RequestResultPtr)     NvM_GetErrorStatus(NvM_Block_EnableXcp_0x4F30, RequestResultPtr)
#define Rte_Call_PS_Block_EnableXcp_0x4F30_ReadBlock(DstPtr)          NvM_ReadBlock(NvM_Block_EnableXcp_0x4F30, DstPtr)
#define Rte_Call_PS_Block_EnableXcp_0x4F30_WriteBlock(SrcPtr)         NvM_WriteBlock(NvM_Block_EnableXcp_0x4F30, SrcPtr)
#define Rte_Call_PS_Block_EnableXcp_0x4F30_RestoreBlockDefaults(DstPtr)         NvM_RestoreBlockDefaults(NvM_Block_EnableXcp_0x4F30, DstPtr)
#define Rte_Call_PS_Block_EnableXcp_0x4F30_SetRamBlockStatus(BlockChanged)      NvM_SetRamBlockStatus(NvM_Block_EnableXcp_0x4F30, BlockChanged)
#define Rte_Call_PS_Block_MasterSlaveState_0xF1C8_GetErrorStatus(RequestResultPtr)        NvM_GetErrorStatus(NvM_Block_MasterSlaveState_0xF1C8, RequestResultPtr)
#define Rte_Call_PS_Block_MasterSlaveState_0xF1C8_ReadBlock(DstPtr)   NvM_ReadBlock(NvM_Block_MasterSlaveState_0xF1C8, DstPtr)
#define Rte_Call_PS_Block_MasterSlaveState_0xF1C8_WriteBlock(SrcPtr)  NvM_WriteBlock(NvM_Block_MasterSlaveState_0xF1C8, SrcPtr)
#define Rte_Call_PS_Block_MasterSlaveState_0xF1C8_RestoreBlockDefaults(DstPtr)  NvM_RestoreBlockDefaults(NvM_Block_MasterSlaveState_0xF1C8, DstPtr)
#define Rte_Call_PS_Block_MasterSlaveState_0xF1C8_SetRamBlockStatus(BlockChanged)         NvM_SetRamBlockStatus(NvM_Block_MasterSlaveState_0xF1C8, BlockChanged)
#define Rte_Call_PS_Block_RepairShopCode_0xF198_GetErrorStatus(RequestResultPtr)          NvM_GetErrorStatus(NvM_Block_RepairShopCode_0xF198, RequestResultPtr)
#define Rte_Call_PS_Block_RepairShopCode_0xF198_ReadBlock(DstPtr)     NvM_ReadBlock(NvM_Block_RepairShopCode_0xF198, DstPtr)
#define Rte_Call_PS_Block_RepairShopCode_0xF198_WriteBlock(SrcPtr)    NvM_WriteBlock(NvM_Block_RepairShopCode_0xF198, SrcPtr)
#define Rte_Call_PS_Block_RepairShopCode_0xF198_RestoreBlockDefaults(DstPtr)    NvM_RestoreBlockDefaults(NvM_Block_RepairShopCode_0xF198, DstPtr)
#define Rte_Call_PS_Block_RepairShopCode_0xF198_SetRamBlockStatus(BlockChanged) NvM_SetRamBlockStatus(NvM_Block_RepairShopCode_0xF198, BlockChanged)
#define Rte_Call_PS_Block_StaticCalibrationInfo_0x4F4A_GetErrorStatus(RequestResultPtr)   NvM_GetErrorStatus(NvM_Block_StaticCalibrationInfo_0x4F4A, RequestResultPtr)
#define Rte_Call_PS_Block_StaticCalibrationInfo_0x4F4A_ReadBlock(DstPtr)        NvM_ReadBlock(NvM_Block_StaticCalibrationInfo_0x4F4A, DstPtr)
#define Rte_Call_PS_Block_StaticCalibrationInfo_0x4F4A_WriteBlock(SrcPtr)       NvM_WriteBlock(NvM_Block_StaticCalibrationInfo_0x4F4A, SrcPtr)
#define Rte_Call_PS_Block_StaticCalibrationInfo_0x4F4A_RestoreBlockDefaults(DstPtr)       NvM_RestoreBlockDefaults(NvM_Block_StaticCalibrationInfo_0x4F4A, DstPtr)
#define Rte_Call_PS_Block_StaticCalibrationInfo_0x4F4A_SetRamBlockStatus(BlockChanged)    NvM_SetRamBlockStatus(NvM_Block_StaticCalibrationInfo_0x4F4A, BlockChanged)
#define Rte_Call_PS_Block_SwitchArlTable_0xF1CB_GetErrorStatus(RequestResultPtr)          NvM_GetErrorStatus(NvM_Block_SwitchArlTable_0xF1CB, RequestResultPtr)
#define Rte_Call_PS_Block_SwitchArlTable_0xF1CB_ReadBlock(DstPtr)     NvM_ReadBlock(NvM_Block_SwitchArlTable_0xF1CB, DstPtr)
#define Rte_Call_PS_Block_SwitchArlTable_0xF1CB_WriteBlock(SrcPtr)    NvM_WriteBlock(NvM_Block_SwitchArlTable_0xF1CB, SrcPtr)
#define Rte_Call_PS_Block_SwitchArlTable_0xF1CB_RestoreBlockDefaults(DstPtr)    NvM_RestoreBlockDefaults(NvM_Block_SwitchArlTable_0xF1CB, DstPtr)
#define Rte_Call_PS_Block_SwitchArlTable_0xF1CB_SetRamBlockStatus(BlockChanged) NvM_SetRamBlockStatus(NvM_Block_SwitchArlTable_0xF1CB, BlockChanged)
#define Rte_Call_PS_Block_VIN_0xF190_GetErrorStatus(RequestResultPtr) NvM_GetErrorStatus(NvM_Block_VIN_0xF190, RequestResultPtr)
#define Rte_Call_PS_Block_VIN_0xF190_ReadBlock(DstPtr)      NvM_ReadBlock(NvM_Block_VIN_0xF190, DstPtr)
#define Rte_Call_PS_Block_VIN_0xF190_WriteBlock(SrcPtr)     NvM_WriteBlock(NvM_Block_VIN_0xF190, SrcPtr)
#define Rte_Call_PS_Block_VIN_0xF190_RestoreBlockDefaults(DstPtr)     NvM_RestoreBlockDefaults(NvM_Block_VIN_0xF190, DstPtr)
#define Rte_Call_PS_Block_VIN_0xF190_SetRamBlockStatus(BlockChanged)  NvM_SetRamBlockStatus(NvM_Block_VIN_0xF190, BlockChanged)
#define Rte_Call_PS_Block_WorkMode_0x4F4D_GetErrorStatus(RequestResultPtr)      NvM_GetErrorStatus(NvM_Block_WorkMode_0x4F4D, RequestResultPtr)
#define Rte_Call_PS_Block_WorkMode_0x4F4D_ReadBlock(DstPtr) NvM_ReadBlock(NvM_Block_WorkMode_0x4F4D, DstPtr)
#define Rte_Call_PS_Block_WorkMode_0x4F4D_WriteBlock(SrcPtr)          NvM_WriteBlock(NvM_Block_WorkMode_0x4F4D, SrcPtr)
#define Rte_Call_PS_Block_WorkMode_0x4F4D_RestoreBlockDefaults(DstPtr)          NvM_RestoreBlockDefaults(NvM_Block_WorkMode_0x4F4D, DstPtr)
#define Rte_Call_PS_Block_WorkMode_0x4F4D_SetRamBlockStatus(BlockChanged)       NvM_SetRamBlockStatus(NvM_Block_WorkMode_0x4F4D, BlockChanged)
#define Rte_Call_ReadAll_ReadAll()                          NvM_ReadAll()
#define Rte_Call_WriteAll_WriteAll()                        NvM_WriteAll()

#define RTE_STOP_SEC_CODE
#include "MemMap.h"

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif  /*RTE_NVM_H*/


