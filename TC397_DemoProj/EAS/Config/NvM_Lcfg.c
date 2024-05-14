/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : NvM_Lcfg.c
********************************************************************************
*   Project/Product : AUTOSAR BSW PROJECT
*   Title           : NvM module configuration File
*   Author          : Hirain
********************************************************************************
*   Description     : NvM module configuration File
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
*   Includes
*******************************************************************************/
#include "NvM.h"
#include "Dem.h"
#include "App.h"
#include "Rte_NvM.h"

/*******************************************************************************
*   Global Vars
*******************************************************************************/
#define NVM_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"
VAR(NvM_RamBlock_Type, NVM_VAR_NOINIT)  NvM_AdmBlock[14];
VAR(NvM_QueBuf_Type, NVM_VAR_NOINIT) NvM_QueBuf[10];

#define NVM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"

#define NVM_START_SEC_VAR_NOINIT_8
#include "MemMap.h"

VAR(uint8, NVM_VAR_NOINIT) NvM_CfgIDBuffer[3];
#define NVM_STOP_SEC_VAR_NOINIT_8
#include "MemMap.h"
/*******************************************************************************
*   Config parameters
*******************************************************************************/
#define NVM_START_SEC_CONFIG_DATA_8
#include "MemMap.h"
CONST(uint8, NVM_CONST) NvM_CompiledConfigId[2] = {(uint8)127, (uint8)22};
#define NVM_STOP_SEC_CONFIG_DATA_8
#include "MemMap.h"

#define NVM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"

CONST(NvM_BlockConfigType, NVM_CONST) NvM_Config[14] =
{
    /* Block0, index = 0 */
    {
        NVM_NULL, NVM_NULL, /*Ram Rom*/
        NVM_BLOCK_NATIVE, /*Block Type*/
        (uint16)1, (uint16)0, (uint8)0, /*Length, BaseNum, DeviceId*/
        (uint8)1, (uint8)1, TRUE, TRUE, /*NvNum, Pri, EnReadAll, EnWrAll*/
        FALSE, /*BswMEn*/
        FALSE, NVM_CRC8, /*crc, crcType, crcComp*/
        FALSE, FALSE /*setRam, autoValidated*/
    },
    /* Block_CfgID, index = 1 */
    {
        (uint8 *)NvM_CfgIDBuffer, (const uint8 *)NvM_CompiledConfigId, /*Ram Rom*/
        NVM_BLOCK_REDUNDANT, /*Block Type*/
        (uint16)2, (uint16)1, (uint8)0, /*Length, BaseNum, DeviceId*/
        (uint8)2, (uint8)1, TRUE, TRUE, /*NvNum, Pri, EnReadAll, EnWrAll*/
        FALSE, /*BswMEn*/
        TRUE, NVM_CRC8, /*crc, crcType, crcComp*/
        FALSE, FALSE /*setRam, autoValidated*/
    },
    /* Block_Dem, index = 2 */
    {
        (uint8 *)&Dem_StorageMem, NVM_NULL, /*Ram Rom*/
        NVM_BLOCK_NATIVE, /*Block Type*/
        (uint16)9448, (uint16)2, (uint8)0, /*Length, BaseNum, DeviceId*/
        (uint8)1, (uint8)1, FALSE, TRUE, /*NvNum, Pri, EnReadAll, EnWrAll*/
        FALSE, /*BswMEn*/
        TRUE, NVM_CRC8, /*crc, crcType, crcComp*/
        FALSE, FALSE /*setRam, autoValidated*/
    },
    /* Block_VIN_0xF190, index = 3 */
    {
        NVM_NULL, NVM_NULL, /*Ram Rom*/
        NVM_BLOCK_NATIVE, /*Block Type*/
        (uint16)17, (uint16)3, (uint8)0, /*Length, BaseNum, DeviceId*/
        (uint8)1, (uint8)1, FALSE, FALSE, /*NvNum, Pri, EnReadAll, EnWrAll*/
        FALSE, /*BswMEn*/
        TRUE, NVM_CRC8, /*crc, crcType, crcComp*/
        FALSE, FALSE /*setRam, autoValidated*/
    },
    /* Block_RepairShopCode_0xF198, index = 4 */
    {
        NVM_NULL, NVM_NULL, /*Ram Rom*/
        NVM_BLOCK_NATIVE, /*Block Type*/
        (uint16)16, (uint16)4, (uint8)0, /*Length, BaseNum, DeviceId*/
        (uint8)1, (uint8)1, FALSE, FALSE, /*NvNum, Pri, EnReadAll, EnWrAll*/
        FALSE, /*BswMEn*/
        TRUE, NVM_CRC8, /*crc, crcType, crcComp*/
        FALSE, FALSE /*setRam, autoValidated*/
    },
    /* Block_Base100T1Sqi_0xF1C2, index = 5 */
    {
        NVM_NULL, NVM_NULL, /*Ram Rom*/
        NVM_BLOCK_NATIVE, /*Block Type*/
        (uint16)1, (uint16)5, (uint8)0, /*Length, BaseNum, DeviceId*/
        (uint8)1, (uint8)1, FALSE, FALSE, /*NvNum, Pri, EnReadAll, EnWrAll*/
        FALSE, /*BswMEn*/
        TRUE, NVM_CRC8, /*crc, crcType, crcComp*/
        FALSE, FALSE /*setRam, autoValidated*/
    },
    /* Block_Base1000T1Sqi_0xF1C3, index = 6 */
    {
        NVM_NULL, NVM_NULL, /*Ram Rom*/
        NVM_BLOCK_NATIVE, /*Block Type*/
        (uint16)1, (uint16)6, (uint8)0, /*Length, BaseNum, DeviceId*/
        (uint8)1, (uint8)1, FALSE, FALSE, /*NvNum, Pri, EnReadAll, EnWrAll*/
        FALSE, /*BswMEn*/
        TRUE, NVM_CRC8, /*crc, crcType, crcComp*/
        FALSE, FALSE /*setRam, autoValidated*/
    },
    /* Block_MasterSlaveState_0xF1C8, index = 7 */
    {
        NVM_NULL, NVM_NULL, /*Ram Rom*/
        NVM_BLOCK_NATIVE, /*Block Type*/
        (uint16)2, (uint16)7, (uint8)0, /*Length, BaseNum, DeviceId*/
        (uint8)1, (uint8)1, FALSE, FALSE, /*NvNum, Pri, EnReadAll, EnWrAll*/
        FALSE, /*BswMEn*/
        TRUE, NVM_CRC8, /*crc, crcType, crcComp*/
        FALSE, FALSE /*setRam, autoValidated*/
    },
    /* Block_SwitchArlTable_0xF1CB, index = 8 */
    {
        NVM_NULL, NVM_NULL, /*Ram Rom*/
        NVM_BLOCK_NATIVE, /*Block Type*/
        (uint16)7, (uint16)8, (uint8)0, /*Length, BaseNum, DeviceId*/
        (uint8)1, (uint8)1, FALSE, FALSE, /*NvNum, Pri, EnReadAll, EnWrAll*/
        FALSE, /*BswMEn*/
        TRUE, NVM_CRC8, /*crc, crcType, crcComp*/
        FALSE, FALSE /*setRam, autoValidated*/
    },
    /* Block_EnableXcp_0x4F30, index = 9 */
    {
        NVM_NULL, NVM_NULL, /*Ram Rom*/
        NVM_BLOCK_NATIVE, /*Block Type*/
        (uint16)1, (uint16)9, (uint8)0, /*Length, BaseNum, DeviceId*/
        (uint8)1, (uint8)1, FALSE, FALSE, /*NvNum, Pri, EnReadAll, EnWrAll*/
        FALSE, /*BswMEn*/
        TRUE, NVM_CRC8, /*crc, crcType, crcComp*/
        FALSE, FALSE /*setRam, autoValidated*/
    },
    /* Block_StaticCalibrationInfo_0x4F4A, index = 10 */
    {
        (uint8 *)StaticCalibrationInfo_0x4F4A_Array, NVM_NULL, /*Ram Rom*/
        NVM_BLOCK_REDUNDANT, /*Block Type*/
        (uint16)16, (uint16)10, (uint8)0, /*Length, BaseNum, DeviceId*/
        (uint8)2, (uint8)1, FALSE, FALSE, /*NvNum, Pri, EnReadAll, EnWrAll*/
        FALSE, /*BswMEn*/
        TRUE, NVM_CRC8, /*crc, crcType, crcComp*/
        FALSE, FALSE /*setRam, autoValidated*/
    },
    /* Block_DynamicCalibrationInfo_0x4F4C, index = 11 */
    {
        NVM_NULL, NVM_NULL, /*Ram Rom*/
        NVM_BLOCK_NATIVE, /*Block Type*/
        (uint16)1, (uint16)11, (uint8)0, /*Length, BaseNum, DeviceId*/
        (uint8)1, (uint8)1, FALSE, FALSE, /*NvNum, Pri, EnReadAll, EnWrAll*/
        FALSE, /*BswMEn*/
        TRUE, NVM_CRC8, /*crc, crcType, crcComp*/
        FALSE, FALSE /*setRam, autoValidated*/
    },
    /* Block_WorkMode_0x4F4D, index = 12 */
    {
        NVM_NULL, NVM_NULL, /*Ram Rom*/
        NVM_BLOCK_NATIVE, /*Block Type*/
        (uint16)1, (uint16)12, (uint8)0, /*Length, BaseNum, DeviceId*/
        (uint8)1, (uint8)1, FALSE, FALSE, /*NvNum, Pri, EnReadAll, EnWrAll*/
        FALSE, /*BswMEn*/
        TRUE, NVM_CRC8, /*crc, crcType, crcComp*/
        FALSE, FALSE /*setRam, autoValidated*/
    },
    /* Block_27SecurityAttemp, index = 13 */
    {
        NVM_NULL, NVM_NULL, /*Ram Rom*/
        NVM_BLOCK_NATIVE, /*Block Type*/
        (uint16)1, (uint16)13, (uint8)0, /*Length, BaseNum, DeviceId*/
        (uint8)1, (uint8)1, FALSE, FALSE, /*NvNum, Pri, EnReadAll, EnWrAll*/
        FALSE, /*BswMEn*/
        TRUE, NVM_CRC8, /*crc, crcType, crcComp*/
        FALSE, FALSE /*setRam, autoValidated*/
    },
};

CONST(NvM_SingleCallBackFun, NVM_CONST) NvM_SingleCallBackFunPtr[14] =
{
    NVM_NULL,
    NVM_NULL,
    NVM_NULL,
    &NvM_Rte_Block_VIN_0xF190_VIN_0xF190,
    &NvM_Rte_Block_RepairShopCode_0xF198_RepairShopCode_0xF198,
    &NvM_Rte_Block_Base100T1Sqi_0xF1C2_Base100T1Sqi_0xF1C2,
    &NvM_Rte_Block_Base1000T1Sqi_0xF1C3_Base1000T1Sqi_0xF1C3,
    &NvM_Rte_Block_MasterSlaveState_0xF1C8_MasterSlaveState_0xF1C8,
    &NvM_Rte_Block_SwitchArlTable_0xF1CB_SwitchArlTable_0xF1CB,
    &NvM_Rte_Block_EnableXcp_0x4F30_EnableXcp_0x4F30,
    &NvM_Rte_Block_StaticCalibrationInfo_0x4F4A_StaticCalibrationInfo_0x4F4A,
    &NvM_Rte_Block_DynamicCalibrationInfo_0x4F4C_DynamicCalibrationInfo_0x4F4C,
    &NvM_Rte_Block_WorkMode_0x4F4D_WorkMode_0x4F4D,
    &NvM_Rte_Block_27SecurityAttemp_SecurityAttemp,
};

CONST(NvM_InitBlockCallBackFun, NVM_CONST) NvM_InitBlockCallBackFunPtr[14] =
{
    NVM_NULL,
    NVM_NULL,
    &NvM_Rte_Block_Dem_Dem_NvM_InitStorageMem,
    &NvM_Rte_Block_VIN_0xF190_NVM_Init_VIN_0xF190,
    &NvM_Rte_Block_RepairShopCode_0xF198_NVM_Init_RepairShopCode_0xF198,
    &NvM_Rte_Block_Base100T1Sqi_0xF1C2_NVM_Init_Base100T1Sqi_0xF1C2,
    &NvM_Rte_Block_Base1000T1Sqi_0xF1C3_NVM_Init_Base1000T1Sqi_0xF1C3,
    &NvM_Rte_Block_MasterSlaveState_0xF1C8_NVM_Init_MasterSlaveState_0xF1C8,
    &NvM_Rte_Block_SwitchArlTable_0xF1CB_NVM_Init_SwitchArlTable_0xF1CB,
    &NvM_Rte_Block_EnableXcp_0x4F30_NVM_Init_EnableXcp_0x4F30,
    &NvM_Rte_Block_StaticCalibrationInfo_0x4F4A_NVM_Init_StaticCalibrationInfo_0x4F4A,
    &NvM_Rte_Block_DynamicCalibrationInfo_0x4F4C_NVM_Init_DynamicCalibrationInfo_0x4F4C,
    &NvM_Rte_Block_WorkMode_0x4F4D_NVM_Init_WorkMode_0x4F4D,
    &NvM_Rte_Block_27SecurityAttemp_NVM_Init_SecurityAttemp,
};
CONST(NvM_MultiCallBackFun, NVM_CONST) NvM_MultiCallBackFunPtr = NVM_NULL ;

#define NVM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"            



