/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
*   File Name       : Crc8.c
********************************************************************************
*   Project/Product : AUTOSAR 4.2.2
*   Title           : 8-bit CRC function module Source File
*   Author          : Hirain
********************************************************************************
*   Description     : This service makes a CRC8 calculation on Crc_Length data bytes, with SAE J1850 parameters.

*
********************************************************************************
*   Limitations     : None
*
********************************************************************************
*
********************************************************************************
*     Revision History:
*     Reference to Core H File
********************************************************************************
* END_FILE_HDR*/



/*******************************************************************************
*   Includes
*******************************************************************************/
#include "Crc.h"

/*******************************************************************************
*   Macro
*******************************************************************************/
#define CRC_8_INIT_VALUE     ((uint8)(0xFF))
#define CRC_8_XOR_VALUE      ((uint8)(0xFF))


#define CRC_START_SEC_CONFIG_DATA_8
#include "MemMap.h"

STATIC CONST(uint8, CRC_CONST) Crc_Table8[TABLE_SIZE] =
{
    (uint8)0x0,  (uint8)0x1d, (uint8)0x3a, (uint8)0x27, (uint8)0x74, (uint8)0x69, (uint8)0x4e, (uint8)0x53,
    (uint8)0xe8, (uint8)0xf5, (uint8)0xd2, (uint8)0xcf, (uint8)0x9c, (uint8)0x81, (uint8)0xa6, (uint8)0xbb,
    (uint8)0xcd, (uint8)0xd0, (uint8)0xf7, (uint8)0xea, (uint8)0xb9, (uint8)0xa4, (uint8)0x83, (uint8)0x9e,
    (uint8)0x25, (uint8)0x38, (uint8)0x1f, (uint8)0x2,  (uint8)0x51, (uint8)0x4c, (uint8)0x6b, (uint8)0x76,
    (uint8)0x87, (uint8)0x9a, (uint8)0xbd, (uint8)0xa0, (uint8)0xf3, (uint8)0xee, (uint8)0xc9, (uint8)0xd4,
    (uint8)0x6f, (uint8)0x72, (uint8)0x55, (uint8)0x48, (uint8)0x1b, (uint8)0x6,  (uint8)0x21, (uint8)0x3c,
    (uint8)0x4a, (uint8)0x57, (uint8)0x70, (uint8)0x6d, (uint8)0x3e, (uint8)0x23, (uint8)0x4,  (uint8)0x19,
    (uint8)0xa2, (uint8)0xbf, (uint8)0x98, (uint8)0x85, (uint8)0xd6, (uint8)0xcb, (uint8)0xec, (uint8)0xf1,
    (uint8)0x13, (uint8)0xe,  (uint8)0x29, (uint8)0x34, (uint8)0x67, (uint8)0x7a, (uint8)0x5d, (uint8)0x40,
    (uint8)0xfb, (uint8)0xe6, (uint8)0xc1, (uint8)0xdc, (uint8)0x8f, (uint8)0x92, (uint8)0xb5, (uint8)0xa8,
    (uint8)0xde, (uint8)0xc3, (uint8)0xe4, (uint8)0xf9, (uint8)0xaa, (uint8)0xb7, (uint8)0x90, (uint8)0x8d,
    (uint8)0x36, (uint8)0x2b, (uint8)0xc,  (uint8)0x11, (uint8)0x42, (uint8)0x5f, (uint8)0x78, (uint8)0x65,
    (uint8)0x94, (uint8)0x89, (uint8)0xae, (uint8)0xb3, (uint8)0xe0, (uint8)0xfd, (uint8)0xda, (uint8)0xc7,
    (uint8)0x7c, (uint8)0x61, (uint8)0x46, (uint8)0x5b, (uint8)0x8,  (uint8)0x15, (uint8)0x32, (uint8)0x2f,
    (uint8)0x59, (uint8)0x44, (uint8)0x63, (uint8)0x7e, (uint8)0x2d, (uint8)0x30, (uint8)0x17, (uint8)0xa,
    (uint8)0xb1, (uint8)0xac, (uint8)0x8b, (uint8)0x96, (uint8)0xc5, (uint8)0xd8, (uint8)0xff, (uint8)0xe2,
    (uint8)0x26, (uint8)0x3b, (uint8)0x1c, (uint8)0x1,  (uint8)0x52, (uint8)0x4f, (uint8)0x68, (uint8)0x75,
    (uint8)0xce, (uint8)0xd3, (uint8)0xf4, (uint8)0xe9, (uint8)0xba, (uint8)0xa7, (uint8)0x80, (uint8)0x9d,
    (uint8)0xeb, (uint8)0xf6, (uint8)0xd1, (uint8)0xcc, (uint8)0x9f, (uint8)0x82, (uint8)0xa5, (uint8)0xb8,
    (uint8)0x3,  (uint8)0x1e, (uint8)0x39, (uint8)0x24, (uint8)0x77, (uint8)0x6a, (uint8)0x4d, (uint8)0x50,
    (uint8)0xa1, (uint8)0xbc, (uint8)0x9b, (uint8)0x86, (uint8)0xd5, (uint8)0xc8, (uint8)0xef, (uint8)0xf2,
    (uint8)0x49, (uint8)0x54, (uint8)0x73, (uint8)0x6e, (uint8)0x3d, (uint8)0x20, (uint8)0x7,  (uint8)0x1a,
    (uint8)0x6c, (uint8)0x71, (uint8)0x56, (uint8)0x4b, (uint8)0x18, (uint8)0x5,  (uint8)0x22, (uint8)0x3f,
    (uint8)0x84, (uint8)0x99, (uint8)0xbe, (uint8)0xa3, (uint8)0xf0, (uint8)0xed, (uint8)0xca, (uint8)0xd7,
    (uint8)0x35, (uint8)0x28, (uint8)0xf,  (uint8)0x12, (uint8)0x41, (uint8)0x5c, (uint8)0x7b, (uint8)0x66,
    (uint8)0xdd, (uint8)0xc0, (uint8)0xe7, (uint8)0xfa, (uint8)0xa9, (uint8)0xb4, (uint8)0x93, (uint8)0x8e,
    (uint8)0xf8, (uint8)0xe5, (uint8)0xc2, (uint8)0xdf, (uint8)0x8c, (uint8)0x91, (uint8)0xb6, (uint8)0xab,
    (uint8)0x10, (uint8)0xd,  (uint8)0x2a, (uint8)0x37, (uint8)0x64, (uint8)0x79, (uint8)0x5e, (uint8)0x43,
    (uint8)0xb2, (uint8)0xaf, (uint8)0x88, (uint8)0x95, (uint8)0xc6, (uint8)0xdb, (uint8)0xfc, (uint8)0xe1,
    (uint8)0x5a, (uint8)0x47, (uint8)0x60, (uint8)0x7d, (uint8)0x2e, (uint8)0x33, (uint8)0x14, (uint8)0x9,
    (uint8)0x7f, (uint8)0x62, (uint8)0x45, (uint8)0x58, (uint8)0xb,  (uint8)0x16, (uint8)0x31, (uint8)0x2c,
    (uint8)0x97, (uint8)0x8a, (uint8)0xad, (uint8)0xb0, (uint8)0xe3, (uint8)0xfe, (uint8)0xd9, (uint8)0xc4
};

#define CRC_STOP_SEC_CONFIG_DATA_8
#include "MemMap.h"

/*******************************************************************************
*   Local Data Define
*******************************************************************************/
#define CRC_START_SEC_CODE
#include "MemMap.h"

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Crc_CalculateCRC8
*
* Description:   This service makes a CRC8 calculation on Crc_Length data bytes, with SAE J1850 parameters.
*
*
* Inputs:        Crc_DataPtr          Pointer to start address of data block to be calculated.
*                Crc_Length           Length of data block to be calculated in bytes.
*                Crc_StartValue8      Start value when the algorithm starts.
*                Crc_IsFirstCall      TRUE: First call in a sequence or individual CRC calculation;
*                                          start from initial value, ignore Crc_StartValue8.
*                                     FALSE: Subsequent call in a call sequence; Crc_StartValue8
*                                     is interpreted to be the return value of the previous function call.
*
* Outputs:       uint32:   8 bit result of CRC calculation.
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
/*CRC30,CRC31,CRC32*/
FUNC(uint8, CRC_CODE) Crc_CalculateCRC8
(
    P2CONST(uint8, AUTOMATIC, CRC_APPL_DATA) Crc_DataPtr,
    uint32 Crc_Length,
    uint8 Crc_StartValue8,
    boolean Crc_IsFirstCall
)
{
    uint8 crc;
    uint32 i;


    if (Crc_IsFirstCall == TRUE)
    {
        /* CRC14*/
        crc = CRC_8_INIT_VALUE;
    }
    else
    {
        /* CRC41*/
        crc = Crc_StartValue8 ^ CRC_8_XOR_VALUE;
    }

    for (i = (uint32)0; i < Crc_Length; i++)
    {
        /*get the crc8H2F table index by data and crc*/
        crc = Crc_Table8[Crc_DataPtr[i] ^ crc];
    }

    return (crc ^ CRC_8_XOR_VALUE);
}

#define CRC_STOP_SEC_CODE
#include "MemMap.h"
