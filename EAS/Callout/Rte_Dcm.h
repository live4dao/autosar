/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : Rte_Dcm.h
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
#ifndef RTE_DCM_H
#define RTE_DCM_H

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
#include "Dcm.h"
#include "Rte_Dcm_Type.h"
#define RTE_START_SEC_CODE
#include "MemMap.h"

#define Dcm_Rte_CallbackDCMRequestServices_User_StartProtocol         Rte_Call_Dcm_CallbackDCMRequestServices_User_StartProtocol
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_CallbackDCMRequestServices_User_StartProtocol
(
    VAR(Dcm_ProtocolType, AUTOMATIC) ProtocolID
);
#define Dcm_Rte_CallbackDCMRequestServices_User_StopProtocol          Rte_Call_Dcm_CallbackDCMRequestServices_User_StopProtocol
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_CallbackDCMRequestServices_User_StopProtocol
(
    VAR(Dcm_ProtocolType, AUTOMATIC) ProtocolID
);
#define Dcm_Rte_DataServices_DspData_0x4F01_0_ReadData      Rte_Call_Dcm_DataServices_DspData_0x4F01_0_ReadData
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_DspData_0x4F01_0_ReadData
(
    VAR(Dcm_OpStatusType, AUTOMATIC) OpStatus,
    VAR(DataTypeUint8_N_1, AUTOMATIC) Data,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode
);
#define Dcm_Rte_DataServices_DspData_0x4F02_0_ReadData      Rte_Call_Dcm_DataServices_DspData_0x4F02_0_ReadData
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_DspData_0x4F02_0_ReadData
(
    VAR(Dcm_OpStatusType, AUTOMATIC) OpStatus,
    VAR(DataTypeUint8_N_3, AUTOMATIC) Data,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode
);
#define Dcm_Rte_DataServices_DspData_0x4F03_0_ReadData      Rte_Call_Dcm_DataServices_DspData_0x4F03_0_ReadData
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_DspData_0x4F03_0_ReadData
(
    VAR(Dcm_OpStatusType, AUTOMATIC) OpStatus,
    VAR(DataTypeUint8_N_6, AUTOMATIC) Data,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode
);
#define Dcm_Rte_DataServices_DspData_0x4F04_0_ReadData      Rte_Call_Dcm_DataServices_DspData_0x4F04_0_ReadData
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_DspData_0x4F04_0_ReadData
(
    VAR(Dcm_OpStatusType, AUTOMATIC) OpStatus,
    VAR(DataTypeUint8_N_2, AUTOMATIC) Data,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode
);
#define Dcm_Rte_DataServices_DspData_0x4F05_0_ReadData      Rte_Call_Dcm_DataServices_DspData_0x4F05_0_ReadData
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_DspData_0x4F05_0_ReadData
(
    VAR(Dcm_OpStatusType, AUTOMATIC) OpStatus,
    VAR(DataTypeUint8_N_1, AUTOMATIC) Data,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode
);
#define Dcm_Rte_DataServices_DspData_0x4F30_0_ReadData      Rte_Call_Dcm_DataServices_DspData_0x4F30_0_ReadData
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_DspData_0x4F30_0_ReadData
(
    VAR(Dcm_OpStatusType, AUTOMATIC) OpStatus,
    VAR(DataTypeUint8_N_1, AUTOMATIC) Data,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode
);
#define Dcm_Rte_DataServices_DspData_0x4F30_0_WriteData     Rte_Call_Dcm_DataServices_DspData_0x4F30_0_WriteData
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_DspData_0x4F30_0_WriteData
(
    VAR(DataTypeUint8_N_1, AUTOMATIC) Data,
    VAR(Dcm_OpStatusType, AUTOMATIC) OpStatus,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode
);
#define Dcm_Rte_DataServices_DspData_0x4F31_0_ReadData      Rte_Call_Dcm_DataServices_DspData_0x4F31_0_ReadData
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_DspData_0x4F31_0_ReadData
(
    VAR(Dcm_OpStatusType, AUTOMATIC) OpStatus,
    VAR(DataTypeUint8_N_1, AUTOMATIC) Data,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode
);
#define Dcm_Rte_DataServices_DspData_0x4F31_0_WriteData     Rte_Call_Dcm_DataServices_DspData_0x4F31_0_WriteData
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_DspData_0x4F31_0_WriteData
(
    VAR(DataTypeUint8_N_1, AUTOMATIC) Data,
    VAR(Dcm_OpStatusType, AUTOMATIC) OpStatus,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode
);
#define Dcm_Rte_DataServices_DspData_0x4F32_0_ReadData      Rte_Call_Dcm_DataServices_DspData_0x4F32_0_ReadData
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_DspData_0x4F32_0_ReadData
(
    VAR(Dcm_OpStatusType, AUTOMATIC) OpStatus,
    VAR(DataTypeUint8_N_1, AUTOMATIC) Data,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode
);
#define Dcm_Rte_DataServices_DspData_0x4F32_0_WriteData     Rte_Call_Dcm_DataServices_DspData_0x4F32_0_WriteData
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_DspData_0x4F32_0_WriteData
(
    VAR(DataTypeUint8_N_1, AUTOMATIC) Data,
    VAR(Dcm_OpStatusType, AUTOMATIC) OpStatus,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode
);
#define Dcm_Rte_DataServices_DspData_0x4F33_0_ReadData      Rte_Call_Dcm_DataServices_DspData_0x4F33_0_ReadData
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_DspData_0x4F33_0_ReadData
(
    VAR(Dcm_OpStatusType, AUTOMATIC) OpStatus,
    VAR(DataTypeUint8_N_12, AUTOMATIC) Data,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode
);
#define Dcm_Rte_DataServices_DspData_0x4F34_0_ReadData      Rte_Call_Dcm_DataServices_DspData_0x4F34_0_ReadData
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_DspData_0x4F34_0_ReadData
(
    VAR(Dcm_OpStatusType, AUTOMATIC) OpStatus,
    VAR(DataTypeUint8_N_12, AUTOMATIC) Data,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode
);
#define Dcm_Rte_DataServices_DspData_0x4F35_0_ReadData      Rte_Call_Dcm_DataServices_DspData_0x4F35_0_ReadData
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_DspData_0x4F35_0_ReadData
(
    VAR(Dcm_OpStatusType, AUTOMATIC) OpStatus,
    VAR(DataTypeUint8_N_1, AUTOMATIC) Data,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode
);
#define Dcm_Rte_DataServices_DspData_0x4F36_0_ReadData      Rte_Call_Dcm_DataServices_DspData_0x4F36_0_ReadData
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_DspData_0x4F36_0_ReadData
(
    VAR(Dcm_OpStatusType, AUTOMATIC) OpStatus,
    VAR(DataTypeUint8_N_12, AUTOMATIC) Data,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode
);
#define Dcm_Rte_DataServices_DspData_0x4F37_0_ReadData      Rte_Call_Dcm_DataServices_DspData_0x4F37_0_ReadData
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_DspData_0x4F37_0_ReadData
(
    VAR(Dcm_OpStatusType, AUTOMATIC) OpStatus,
    VAR(DataTypeUint8_N_12, AUTOMATIC) Data,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode
);
#define Dcm_Rte_DataServices_DspData_0x4F38_0_ReadData      Rte_Call_Dcm_DataServices_DspData_0x4F38_0_ReadData
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_DspData_0x4F38_0_ReadData
(
    VAR(Dcm_OpStatusType, AUTOMATIC) OpStatus,
    VAR(DataTypeUint8_N_2, AUTOMATIC) Data,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode
);
#define Dcm_Rte_DataServices_DspData_0x4F39_0_ReadData      Rte_Call_Dcm_DataServices_DspData_0x4F39_0_ReadData
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_DspData_0x4F39_0_ReadData
(
    VAR(Dcm_OpStatusType, AUTOMATIC) OpStatus,
    VAR(DataTypeUint8_N_9, AUTOMATIC) Data,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode
);
#define Dcm_Rte_DataServices_DspData_0x4F3A_0_ReadData      Rte_Call_Dcm_DataServices_DspData_0x4F3A_0_ReadData
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_DspData_0x4F3A_0_ReadData
(
    VAR(Dcm_OpStatusType, AUTOMATIC) OpStatus,
    VAR(DataTypeUint8_N_8, AUTOMATIC) Data,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode
);
#define Dcm_Rte_DataServices_DspData_0x4F3B_0_ReadData      Rte_Call_Dcm_DataServices_DspData_0x4F3B_0_ReadData
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_DspData_0x4F3B_0_ReadData
(
    VAR(Dcm_OpStatusType, AUTOMATIC) OpStatus,
    VAR(DataTypeUint8_N_8, AUTOMATIC) Data,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode
);
#define Dcm_Rte_DataServices_DspData_0x4F3C_0_ReadData      Rte_Call_Dcm_DataServices_DspData_0x4F3C_0_ReadData
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_DspData_0x4F3C_0_ReadData
(
    VAR(Dcm_OpStatusType, AUTOMATIC) OpStatus,
    VAR(DataTypeUint8_N_8, AUTOMATIC) Data,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode
);
#define Dcm_Rte_DataServices_DspData_0x4F3D_0_ReadData      Rte_Call_Dcm_DataServices_DspData_0x4F3D_0_ReadData
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_DspData_0x4F3D_0_ReadData
(
    VAR(Dcm_OpStatusType, AUTOMATIC) OpStatus,
    VAR(DataTypeUint8_N_8, AUTOMATIC) Data,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode
);
#define Dcm_Rte_DataServices_DspData_0x4F3E_0_ReadData      Rte_Call_Dcm_DataServices_DspData_0x4F3E_0_ReadData
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_DspData_0x4F3E_0_ReadData
(
    VAR(Dcm_OpStatusType, AUTOMATIC) OpStatus,
    VAR(DataTypeUint8_N_1, AUTOMATIC) Data,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode
);
#define Dcm_Rte_DataServices_DspData_0x4F3F_0_ReadData      Rte_Call_Dcm_DataServices_DspData_0x4F3F_0_ReadData
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_DspData_0x4F3F_0_ReadData
(
    VAR(Dcm_OpStatusType, AUTOMATIC) OpStatus,
    VAR(DataTypeUint8_N_5, AUTOMATIC) Data,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode
);
#define Dcm_Rte_DataServices_DspData_0x4F40_0_ReadData      Rte_Call_Dcm_DataServices_DspData_0x4F40_0_ReadData
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_DspData_0x4F40_0_ReadData
(
    VAR(Dcm_OpStatusType, AUTOMATIC) OpStatus,
    VAR(DataTypeUint8_N_25, AUTOMATIC) Data,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode
);
#define Dcm_Rte_DataServices_DspData_0x4F41_0_ReadData      Rte_Call_Dcm_DataServices_DspData_0x4F41_0_ReadData
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_DspData_0x4F41_0_ReadData
(
    VAR(Dcm_OpStatusType, AUTOMATIC) OpStatus,
    VAR(DataTypeUint8_N_25, AUTOMATIC) Data,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode
);
#define Dcm_Rte_DataServices_DspData_0x4F42_0_ReadData      Rte_Call_Dcm_DataServices_DspData_0x4F42_0_ReadData
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_DspData_0x4F42_0_ReadData
(
    VAR(Dcm_OpStatusType, AUTOMATIC) OpStatus,
    VAR(DataTypeUint8_N_25, AUTOMATIC) Data,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode
);
#define Dcm_Rte_DataServices_DspData_0x4F43_0_ReadData      Rte_Call_Dcm_DataServices_DspData_0x4F43_0_ReadData
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_DspData_0x4F43_0_ReadData
(
    VAR(Dcm_OpStatusType, AUTOMATIC) OpStatus,
    VAR(DataTypeUint8_N_1, AUTOMATIC) Data,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode
);
#define Dcm_Rte_DataServices_DspData_0x4F44_0_ReadData      Rte_Call_Dcm_DataServices_DspData_0x4F44_0_ReadData
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_DspData_0x4F44_0_ReadData
(
    VAR(Dcm_OpStatusType, AUTOMATIC) OpStatus,
    VAR(DataTypeUint8_N_36, AUTOMATIC) Data,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode
);
#define Dcm_Rte_DataServices_DspData_0x4F45_0_ReadData      Rte_Call_Dcm_DataServices_DspData_0x4F45_0_ReadData
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_DspData_0x4F45_0_ReadData
(
    VAR(Dcm_OpStatusType, AUTOMATIC) OpStatus,
    VAR(DataTypeUint8_N_30, AUTOMATIC) Data,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode
);
#define Dcm_Rte_DataServices_DspData_0x4F46_0_ReadData      Rte_Call_Dcm_DataServices_DspData_0x4F46_0_ReadData
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_DspData_0x4F46_0_ReadData
(
    VAR(Dcm_OpStatusType, AUTOMATIC) OpStatus,
    VAR(DataTypeUint8_N_6, AUTOMATIC) Data,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode
);
#define Dcm_Rte_DataServices_DspData_0x4F48_0_ReadData      Rte_Call_Dcm_DataServices_DspData_0x4F48_0_ReadData
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_DspData_0x4F48_0_ReadData
(
    VAR(Dcm_OpStatusType, AUTOMATIC) OpStatus,
    VAR(DataTypeUint8_N_2, AUTOMATIC) Data,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode
);
#define Dcm_Rte_DataServices_DspData_0x4F4A_0_ReadData      Rte_Call_Dcm_DataServices_DspData_0x4F4A_0_ReadData
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_DspData_0x4F4A_0_ReadData
(
    VAR(Dcm_OpStatusType, AUTOMATIC) OpStatus,
    VAR(DataTypeUint8_N_16, AUTOMATIC) Data,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode
);
#define Dcm_Rte_DataServices_DspData_0x4F4A_0_WriteData     Rte_Call_Dcm_DataServices_DspData_0x4F4A_0_WriteData
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_DspData_0x4F4A_0_WriteData
(
    VAR(DataTypeUint8_N_16, AUTOMATIC) Data,
    VAR(Dcm_OpStatusType, AUTOMATIC) OpStatus,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode
);
#define Dcm_Rte_DataServices_DspData_0x4F4B_0_ReadData      Rte_Call_Dcm_DataServices_DspData_0x4F4B_0_ReadData
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_DspData_0x4F4B_0_ReadData
(
    VAR(Dcm_OpStatusType, AUTOMATIC) OpStatus,
    VAR(DataTypeUint8_N_13, AUTOMATIC) Data,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode
);
#define Dcm_Rte_DataServices_DspData_0x4F4C_0_ReadData      Rte_Call_Dcm_DataServices_DspData_0x4F4C_0_ReadData
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_DspData_0x4F4C_0_ReadData
(
    VAR(Dcm_OpStatusType, AUTOMATIC) OpStatus,
    VAR(DataTypeUint8_N_1, AUTOMATIC) Data,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode
);
#define Dcm_Rte_DataServices_DspData_0x4F4C_0_WriteData     Rte_Call_Dcm_DataServices_DspData_0x4F4C_0_WriteData
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_DspData_0x4F4C_0_WriteData
(
    VAR(DataTypeUint8_N_1, AUTOMATIC) Data,
    VAR(Dcm_OpStatusType, AUTOMATIC) OpStatus,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode
);
#define Dcm_Rte_DataServices_DspData_0x4F4D_0_ReadData      Rte_Call_Dcm_DataServices_DspData_0x4F4D_0_ReadData
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_DspData_0x4F4D_0_ReadData
(
    VAR(Dcm_OpStatusType, AUTOMATIC) OpStatus,
    VAR(DataTypeUint8_N_1, AUTOMATIC) Data,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode
);
#define Dcm_Rte_DataServices_DspData_0x4F4D_0_WriteData     Rte_Call_Dcm_DataServices_DspData_0x4F4D_0_WriteData
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_DspData_0x4F4D_0_WriteData
(
    VAR(DataTypeUint8_N_1, AUTOMATIC) Data,
    VAR(Dcm_OpStatusType, AUTOMATIC) OpStatus,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode
);
#define Dcm_Rte_DataServices_DspData_0xF112_0_ReadData      Rte_Call_Dcm_DataServices_DspData_0xF112_0_ReadData
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_DspData_0xF112_0_ReadData
(
    VAR(Dcm_OpStatusType, AUTOMATIC) OpStatus,
    VAR(DataTypeUint8_N_8, AUTOMATIC) Data,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode
);
#define Dcm_Rte_DataServices_DspData_0xF15A_0_ReadData      Rte_Call_Dcm_DataServices_DspData_0xF15A_0_ReadData
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_DspData_0xF15A_0_ReadData
(
    VAR(Dcm_OpStatusType, AUTOMATIC) OpStatus,
    VAR(DataTypeUint8_N_13, AUTOMATIC) Data,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode
);
#define Dcm_Rte_DataServices_DspData_0xF180_0_ReadData      Rte_Call_Dcm_DataServices_DspData_0xF180_0_ReadData
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_DspData_0xF180_0_ReadData
(
    VAR(Dcm_OpStatusType, AUTOMATIC) OpStatus,
    VAR(DataTypeUint8_N_26, AUTOMATIC) Data,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode
);
#define Dcm_Rte_DataServices_DspData_0xF186_0_ReadData      Rte_Call_Dcm_DataServices_DspData_0xF186_0_ReadData
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_DspData_0xF186_0_ReadData
(
    VAR(Dcm_OpStatusType, AUTOMATIC) OpStatus,
    VAR(DataTypeUint8_N_1, AUTOMATIC) Data,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode
);
#define Dcm_Rte_DataServices_DspData_0xF187_0_ReadData      Rte_Call_Dcm_DataServices_DspData_0xF187_0_ReadData
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_DspData_0xF187_0_ReadData
(
    VAR(Dcm_OpStatusType, AUTOMATIC) OpStatus,
    VAR(DataTypeUint8_N_26, AUTOMATIC) Data,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode
);
#define Dcm_Rte_DataServices_DspData_0xF18A_0_ReadData      Rte_Call_Dcm_DataServices_DspData_0xF18A_0_ReadData
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_DspData_0xF18A_0_ReadData
(
    VAR(Dcm_OpStatusType, AUTOMATIC) OpStatus,
    VAR(DataTypeUint8_N_6, AUTOMATIC) Data,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode
);
#define Dcm_Rte_DataServices_DspData_0xF18C_0_ReadData      Rte_Call_Dcm_DataServices_DspData_0xF18C_0_ReadData
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_DspData_0xF18C_0_ReadData
(
    VAR(Dcm_OpStatusType, AUTOMATIC) OpStatus,
    VAR(DataTypeUint8_N_30, AUTOMATIC) Data,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode
);
#define Dcm_Rte_DataServices_DspData_0xF190_0_ReadData      Rte_Call_Dcm_DataServices_DspData_0xF190_0_ReadData
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_DspData_0xF190_0_ReadData
(
    VAR(Dcm_OpStatusType, AUTOMATIC) OpStatus,
    VAR(DataTypeUint8_N_17, AUTOMATIC) Data,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode
);
#define Dcm_Rte_DataServices_DspData_0xF190_0_WriteData     Rte_Call_Dcm_DataServices_DspData_0xF190_0_WriteData
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_DspData_0xF190_0_WriteData
(
    VAR(DataTypeUint8_N_17, AUTOMATIC) Data,
    VAR(Dcm_OpStatusType, AUTOMATIC) OpStatus,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode
);
#define Dcm_Rte_DataServices_DspData_0xF192_0_ReadData      Rte_Call_Dcm_DataServices_DspData_0xF192_0_ReadData
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_DspData_0xF192_0_ReadData
(
    VAR(Dcm_OpStatusType, AUTOMATIC) OpStatus,
    VAR(DataTypeUint8_N_26, AUTOMATIC) Data,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode
);
#define Dcm_Rte_DataServices_DspData_0xF193_0_ReadData      Rte_Call_Dcm_DataServices_DspData_0xF193_0_ReadData
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_DspData_0xF193_0_ReadData
(
    VAR(Dcm_OpStatusType, AUTOMATIC) OpStatus,
    VAR(DataTypeUint8_N_26, AUTOMATIC) Data,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode
);
#define Dcm_Rte_DataServices_DspData_0xF195_0_ReadData      Rte_Call_Dcm_DataServices_DspData_0xF195_0_ReadData
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_DspData_0xF195_0_ReadData
(
    VAR(Dcm_OpStatusType, AUTOMATIC) OpStatus,
    VAR(DataTypeUint8_N_6, AUTOMATIC) Data,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode
);
#define Dcm_Rte_DataServices_DspData_0xF198_0_ReadData      Rte_Call_Dcm_DataServices_DspData_0xF198_0_ReadData
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_DspData_0xF198_0_ReadData
(
    VAR(Dcm_OpStatusType, AUTOMATIC) OpStatus,
    VAR(DataTypeUint8_N_16, AUTOMATIC) Data,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode
);
#define Dcm_Rte_DataServices_DspData_0xF198_0_WriteData     Rte_Call_Dcm_DataServices_DspData_0xF198_0_WriteData
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_DspData_0xF198_0_WriteData
(
    VAR(DataTypeUint8_N_16, AUTOMATIC) Data,
    VAR(Dcm_OpStatusType, AUTOMATIC) OpStatus,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode
);
#define Dcm_Rte_DataServices_DspData_0xF199_0_ReadData      Rte_Call_Dcm_DataServices_DspData_0xF199_0_ReadData
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_DspData_0xF199_0_ReadData
(
    VAR(Dcm_OpStatusType, AUTOMATIC) OpStatus,
    VAR(DataTypeUint8_N_4, AUTOMATIC) Data,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode
);
#define Dcm_Rte_DataServices_DspData_0xF19D_0_ReadData      Rte_Call_Dcm_DataServices_DspData_0xF19D_0_ReadData
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_DspData_0xF19D_0_ReadData
(
    VAR(Dcm_OpStatusType, AUTOMATIC) OpStatus,
    VAR(DataTypeUint8_N_4, AUTOMATIC) Data,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode
);
#define Dcm_Rte_DataServices_DspData_0xF1C1_0_ReadData      Rte_Call_Dcm_DataServices_DspData_0xF1C1_0_ReadData
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_DspData_0xF1C1_0_ReadData
(
    VAR(Dcm_OpStatusType, AUTOMATIC) OpStatus,
    VAR(DataTypeUint8_N_2, AUTOMATIC) Data,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode
);
#define Dcm_Rte_DataServices_DspData_0xF1C2_0_ReadData      Rte_Call_Dcm_DataServices_DspData_0xF1C2_0_ReadData
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_DspData_0xF1C2_0_ReadData
(
    VAR(Dcm_OpStatusType, AUTOMATIC) OpStatus,
    VAR(DataTypeUint8_N_1, AUTOMATIC) Data,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode
);
#define Dcm_Rte_DataServices_DspData_0xF1C2_0_WriteData     Rte_Call_Dcm_DataServices_DspData_0xF1C2_0_WriteData
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_DspData_0xF1C2_0_WriteData
(
    VAR(DataTypeUint8_N_1, AUTOMATIC) Data,
    VAR(Dcm_OpStatusType, AUTOMATIC) OpStatus,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode
);
#define Dcm_Rte_DataServices_DspData_0xF1C3_0_ReadData      Rte_Call_Dcm_DataServices_DspData_0xF1C3_0_ReadData
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_DspData_0xF1C3_0_ReadData
(
    VAR(Dcm_OpStatusType, AUTOMATIC) OpStatus,
    VAR(DataTypeUint8_N_1, AUTOMATIC) Data,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode
);
#define Dcm_Rte_DataServices_DspData_0xF1C3_0_WriteData     Rte_Call_Dcm_DataServices_DspData_0xF1C3_0_WriteData
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_DspData_0xF1C3_0_WriteData
(
    VAR(DataTypeUint8_N_1, AUTOMATIC) Data,
    VAR(Dcm_OpStatusType, AUTOMATIC) OpStatus,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode
);
#define Dcm_Rte_DataServices_DspData_0xF1C6_0_ReadData      Rte_Call_Dcm_DataServices_DspData_0xF1C6_0_ReadData
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_DspData_0xF1C6_0_ReadData
(
    VAR(Dcm_OpStatusType, AUTOMATIC) OpStatus,
    VAR(DataTypeUint8_N_6, AUTOMATIC) Data,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode
);
#define Dcm_Rte_DataServices_DspData_0xF1C7_0_ReadData      Rte_Call_Dcm_DataServices_DspData_0xF1C7_0_ReadData
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_DspData_0xF1C7_0_ReadData
(
    VAR(Dcm_OpStatusType, AUTOMATIC) OpStatus,
    VAR(DataTypeUint8_N_2, AUTOMATIC) Data,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode
);
#define Dcm_Rte_DataServices_DspData_0xF1C8_0_ReadData      Rte_Call_Dcm_DataServices_DspData_0xF1C8_0_ReadData
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_DspData_0xF1C8_0_ReadData
(
    VAR(Dcm_OpStatusType, AUTOMATIC) OpStatus,
    VAR(DataTypeUint8_N_2, AUTOMATIC) Data,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode
);
#define Dcm_Rte_DataServices_DspData_0xF1C8_0_WriteData     Rte_Call_Dcm_DataServices_DspData_0xF1C8_0_WriteData
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_DspData_0xF1C8_0_WriteData
(
    VAR(DataTypeUint8_N_2, AUTOMATIC) Data,
    VAR(Dcm_OpStatusType, AUTOMATIC) OpStatus,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode
);
#define Dcm_Rte_DataServices_DspData_0xF1C9_0_ReadData      Rte_Call_Dcm_DataServices_DspData_0xF1C9_0_ReadData
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_DspData_0xF1C9_0_ReadData
(
    VAR(Dcm_OpStatusType, AUTOMATIC) OpStatus,
    VAR(DataTypeUint8_N_2, AUTOMATIC) Data,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode
);
#define Dcm_Rte_DataServices_DspData_0xF1CA_0_ReadData      Rte_Call_Dcm_DataServices_DspData_0xF1CA_0_ReadData
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_DspData_0xF1CA_0_ReadData
(
    VAR(Dcm_OpStatusType, AUTOMATIC) OpStatus,
    VAR(DataTypeUint8_N_4, AUTOMATIC) Data,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode
);
#define Dcm_Rte_DataServices_DspData_0xF1CB_0_ReadData      Rte_Call_Dcm_DataServices_DspData_0xF1CB_0_ReadData
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_DspData_0xF1CB_0_ReadData
(
    VAR(Dcm_OpStatusType, AUTOMATIC) OpStatus,
    VAR(DataTypeUint8_N_7, AUTOMATIC) Data,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode
);
#define Dcm_Rte_DataServices_DspData_0xF1CB_0_WriteData     Rte_Call_Dcm_DataServices_DspData_0xF1CB_0_WriteData
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_DspData_0xF1CB_0_WriteData
(
    VAR(DataTypeUint8_N_7, AUTOMATIC) Data,
    VAR(Dcm_OpStatusType, AUTOMATIC) OpStatus,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode
);
#define Dcm_Rte_DataServices_DspData_0xF1CC_0_ReadData      Rte_Call_Dcm_DataServices_DspData_0xF1CC_0_ReadData
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_DspData_0xF1CC_0_ReadData
(
    VAR(Dcm_OpStatusType, AUTOMATIC) OpStatus,
    VAR(DataTypeUint8_N_2, AUTOMATIC) Data,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode
);
#define Dcm_Rte_DataServices_DspData_0xF1CD_0_ReadData      Rte_Call_Dcm_DataServices_DspData_0xF1CD_0_ReadData
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_DspData_0xF1CD_0_ReadData
(
    VAR(Dcm_OpStatusType, AUTOMATIC) OpStatus,
    VAR(DataTypeUint8_N_5, AUTOMATIC) Data,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode
);
#define Dcm_Rte_RoutineServices_0xFF02_Start                Rte_Call_Dcm_RoutineServices_0xFF02_Start
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_RoutineServices_0xFF02_Start
(
    VAR(DataTypeUint8_N_1, AUTOMATIC) DataIn,
    VAR(Dcm_OpStatusType, AUTOMATIC) OpStatus,
    P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) DataOut,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode
);
#define Dcm_Rte_SecurityAccess_L2_GetSeed                   Rte_Call_Dcm_SecurityAccess_L2_GetSeed
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_SecurityAccess_L2_GetSeed
(
    VAR(Dcm_OpStatusType, AUTOMATIC) OpStatus,
    VAR(DataTypeUint8_N_4, AUTOMATIC) Seed,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode
);
#define Dcm_Rte_SecurityAccess_L2_CompareKey                Rte_Call_Dcm_SecurityAccess_L2_CompareKey
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_SecurityAccess_L2_CompareKey
(
    VAR(DataTypeUint8_N_4, AUTOMATIC) Key,
    VAR(Dcm_OpStatusType, AUTOMATIC) OpStatus,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode
);
#define Dcm_Rte_SecurityAccess_L2_GetSecurityAttemptCounter Rte_Call_Dcm_SecurityAccess_L2_GetSecurityAttemptCounter
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_SecurityAccess_L2_GetSecurityAttemptCounter
(
    VAR(Dcm_OpStatusType, AUTOMATIC) OpStatus,
    P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) AttemptCounter
);
#define Dcm_Rte_SecurityAccess_L2_SetSecurityAttemptCounter Rte_Call_Dcm_SecurityAccess_L2_SetSecurityAttemptCounter
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_SecurityAccess_L2_SetSecurityAttemptCounter
(
    VAR(Dcm_OpStatusType, AUTOMATIC) OpStatus,
    VAR(uint8, AUTOMATIC) AttemptCounter
);
#define Dcm_Rte_SecurityAccess_L9_GetSeed                   Rte_Call_Dcm_SecurityAccess_L9_GetSeed
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_SecurityAccess_L9_GetSeed
(
    VAR(Dcm_OpStatusType, AUTOMATIC) OpStatus,
    VAR(DataTypeUint8_N_4, AUTOMATIC) Seed,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode
);
#define Dcm_Rte_SecurityAccess_L9_CompareKey                Rte_Call_Dcm_SecurityAccess_L9_CompareKey
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_SecurityAccess_L9_CompareKey
(
    VAR(DataTypeUint8_N_4, AUTOMATIC) Key,
    VAR(Dcm_OpStatusType, AUTOMATIC) OpStatus,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode
);

#define RTE_STOP_SEC_CODE
#include "MemMap.h"

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif  /*RTE_DCM_H*/


