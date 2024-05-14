/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : Dcm_Lcfg.h
********************************************************************************
*   Project/Product : AUTOSAR BSW PROJECT
*   Title           : Dcm module configuration File
*   Author          : Hirain
********************************************************************************
*   Description     : Dcm module configuration File
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

#ifndef DCM_LCFG_H
#define DCM_LCFG_H
/*******************************************************************************
* Include files
*******************************************************************************/
#include "Dcm_Types.h"
/********************************************************************************
* Macro definition
********************************************************************************/

#define DCM_DEFAULT_LEVEL                                   0
#define DCM_PROGRAMMING_LEVEL                               1
#define DCM_EXTENDED_LEVEL                                  2
#define DCM_DEFAULT_MASK                                    (uint16)0x0001
#define DCM_PROGRAMMING_MASK                                (uint16)0x0002
#define DCM_EXTENDED_MASK                                   (uint16)0x0004

#define DCM_SECURITY_LOCKED_LEVEL                           0
#define DCM_SECURITY_L2_LEVEL                               1
#define DCM_SECURITY_L9_LEVEL                               2
#define DCM_SECURITY_ALL_LEVEL                              (uint8)0xFF
#define DCM_LOCKED_MASK                                     (uint16)0x0001
#define DCM_L2_MASK                                         (uint16)0x0002
#define DCM_L9_MASK                                         (uint16)0x0004
#define DCM_ALL_MASK                                        (uint16)0xFFFF
/*******************************************************************************
* Configuration
*******************************************************************************/
#define DCM_START_SEC_CONFIG_DATA_8
#include "MemMap.h"
extern CONST(uint8, DCM_CONST) Dcm_RxPduToProtocolMap[DCM_CFG_RXPDU_NUM];
#define DCM_STOP_SEC_CONFIG_DATA_8
#include "MemMap.h"

#define DCM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"
extern CONST(Dcm_DslProtocolRowType, DCM_CONST) Dcm_DslProtocolRow[DCM_CFG_NUM_OF_PROTOCOL];


extern CONST(Dcm_DspSessionType, DCM_CONST) Dcm_DspSession[DCM_CFG_NUM_OF_PROTOCOL];
extern CONST(Dcm_DspSecurityType, DCM_CONST) Dcm_DspSecurity[DCM_CFG_NUM_OF_PROTOCOL];
extern CONST(Dcm_DspDataType, DCM_CONST) Dcm_DspData[DCM_CFG_NUM_OF_PROTOCOL];
extern CONST(Dcm_DspDidType, DCM_CONST) Dcm_DspDid[DCM_CFG_NUM_OF_PROTOCOL];
extern CONST(Dcm_DspComControlType, DCM_CONST) Dcm_DspComControl[DCM_CFG_NUM_OF_PROTOCOL];
extern CONST(Dcm_DspRoutineType, DCM_CONST) Dcm_DspRoutine[DCM_CFG_NUM_OF_PROTOCOL];
#define DCM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"

#endif


