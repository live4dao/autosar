/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
*   File Name       : Crc.h
********************************************************************************
*   Project/Product : AUTOSAR 4.2.2
*   Title           : Crc.h
*   Author          : Hirain
********************************************************************************
*   Description     : Main header file of the AUTOSAR CRC Calculation Protocol,
*                     according to AUTOSAR_SWS_CRCLibrary.pdf(Release 4.2.2)
*                     The header file contains the declaration of the CRC module
*                     API;contains 'extern' declarations of constants,global data,
*                     type definitions and services that are specified in the
*                     CRC module SWS.
*
********************************************************************************
*   Limitations     :
*
********************************************************************************
*
********************************************************************************
*   Revision History:
*
*   Version     Date          Initials      CR#          Descriptions
*   ---------   ----------    ------------  ----------   ---------------
*   01.00.00    18/08/2017    Jingwei.Xi      N/A          Original
********************************************************************************
* END_FILE_HDR*/

#ifndef _CRC_H_
#define _CRC_H_

/*******************************************************************************
*   Includes
*******************************************************************************/
#include "Std_Types.h"
#include "Crc_Cfg.h"
#include "Platform_Types.h"
/*CRC22*/


/*******************************************************************************
*   Macro
*******************************************************************************/
#define TABLE_SIZE      256
#define RIGHTMOVE_INDEX ((uint8)8)


#define CRC_POLY32       0xF4ACFB13
#define CRC_POLY32P4     0x04C11DB7
#define CRC_POLY16       0x1021
#define CRC_POLY8        0x1D
#define CRC_POLY8H2F     0x2F

#define  CRC_CALCULATE_CRC32_API_ID                     (0x03U)
#define  CRC_CALCULATE_CRC32P4_API_ID                   (0x06U)
#define  CRC_CALCULATE_CRC16_API_ID                     (0x02U)
#define  CRC_CALCULATE_CRC8_API_ID                      (0x01U)
#define  CRC_CALCULATE_CRC8H2F_API_ID                   (0x05U)
#define  CRC_GET_VERSIONINFO_API_ID                     (0x04U)
/**************************************************************************************************
* Gloabol Data definitions
**************************************************************************************************/

#define CRC_START_SEC_CODE
#include "MemMap.h"

FUNC(uint32, CRC_CODE) Crc_CalculateCRC32
(
    P2CONST(uint8, AUTOMATIC, CRC_APPL_DATA) Crc_DataPtr,
    uint32 Crc_Length,
    uint32 Crc_StartValue32,
    boolean Crc_IsFirstCall
);

FUNC(uint32, CRC_CODE) Crc_CalculateCRC32P4
(
    P2CONST(uint8, AUTOMATIC, CRC_APPL_DATA) Crc_DataPtr,
    uint32 Crc_Length,
    uint32 Crc_StartValue32,
    boolean Crc_IsFirstCall
);

FUNC(uint16, CRC_CODE) Crc_CalculateCRC16
(
    P2CONST(uint8, AUTOMATIC, CRC_APPL_DATA) Crc_DataPtr,
    uint32 Crc_Length,
    uint16 Crc_StartValue16,
    boolean Crc_IsFirstCall
);

FUNC(uint8, CRC_CODE) Crc_CalculateCRC8
(
    P2CONST(uint8, AUTOMATIC, CRC_APPL_DATA) Crc_DataPtr,
    uint32 Crc_Length,
    uint8 Crc_StartValue8,
    boolean Crc_IsFirstCall
);

FUNC(uint8, CRC_CODE) Crc_CalculateCRC8H2F
(
    P2CONST(uint8, AUTOMATIC, CRC_APPL_DATA) Crc_DataPtr,
    uint32 Crc_Length,
    uint8 Crc_StartValue8H2F,
    boolean Crc_IsFirstCall
);
FUNC(void, CRC_CODE) Crc_GetVersionInfo
(
    P2VAR(Std_VersionInfoType, AUTOMATIC, CRC_APPL_DATA) Versioninfo
);

#define CRC_STOP_SEC_CODE
#include "MemMap.h"

#endif /* _CRC_H_*/

