/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
*   File Name       : Crc16.c
********************************************************************************
*   Project/Product : AUTOSAR 4.2.2
*   Title           : 16-bit CRC function module Source File
*   Author          : Hirain
********************************************************************************
*   Description     : This service makes a CRC16 calculation on Crc_Length data bytes.

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
#define CRC_16_INIT_VALUE     ((uint16)(0xFFFF))
#define CRC_16_XOR_VALUE      ((uint16)(0x0000))


#define CRC_START_SEC_VAR_INIT_16
#include "MemMap.h"

STATIC CONST(uint16, CRC_CONST) Crc_Table16[TABLE_SIZE] =
{
    (uint16)0x0, (uint16)0x1021, (uint16)0x2042, (uint16)0x3063, 
	(uint16)0x4084, (uint16)0x50a5, (uint16)0x60c6, (uint16)0x70e7,
    (uint16)0x8108, (uint16)0x9129, (uint16)0xa14a, (uint16)0xb16b, 
    (uint16)0xc18c, (uint16)0xd1ad, (uint16)0xe1ce, (uint16)0xf1ef,
    (uint16)0x1231, (uint16)0x210, (uint16)0x3273, (uint16)0x2252, 
    (uint16)0x52b5, (uint16)0x4294, (uint16)0x72f7, (uint16)0x62d6,
    (uint16)0x9339, (uint16)0x8318, (uint16)0xb37b, (uint16)0xa35a, 
    (uint16)0xd3bd, (uint16)0xc39c, (uint16)0xf3ff, (uint16)0xe3de,
    (uint16)0x2462, (uint16)0x3443, (uint16)0x420, (uint16)0x1401, 
    (uint16)0x64e6, (uint16)0x74c7, (uint16)0x44a4, (uint16)0x5485,
    (uint16)0xa56a, (uint16)0xb54b, (uint16)0x8528, (uint16)0x9509, 
    (uint16)0xe5ee, (uint16)0xf5cf, (uint16)0xc5ac, (uint16)0xd58d,
    (uint16)0x3653, (uint16)0x2672, (uint16)0x1611, (uint16)0x630, 
    (uint16)0x76d7, (uint16)0x66f6, (uint16)0x5695, (uint16)0x46b4,
    (uint16)0xb75b, (uint16)0xa77a, (uint16)0x9719, (uint16)0x8738, 
    (uint16)0xf7df, (uint16)0xe7fe, (uint16)0xd79d, (uint16)0xc7bc,
    (uint16)0x48c4, (uint16)0x58e5, (uint16)0x6886, (uint16)0x78a7, 
    (uint16)0x840, (uint16)0x1861, (uint16)0x2802, (uint16)0x3823,
    (uint16)0xc9cc, (uint16)0xd9ed, (uint16)0xe98e, (uint16)0xf9af, 
    (uint16)0x8948, (uint16)0x9969, (uint16)0xa90a, (uint16)0xb92b,
    (uint16)0x5af5, (uint16)0x4ad4, (uint16)0x7ab7, (uint16)0x6a96, 
    (uint16)0x1a71, (uint16)0xa50, (uint16)0x3a33, (uint16)0x2a12,
    (uint16)0xdbfd, (uint16)0xcbdc, (uint16)0xfbbf, (uint16)0xeb9e, 
    (uint16)0x9b79, (uint16)0x8b58, (uint16)0xbb3b, (uint16)0xab1a,
    (uint16)0x6ca6, (uint16)0x7c87, (uint16)0x4ce4, (uint16)0x5cc5, 
    (uint16)0x2c22, (uint16)0x3c03, (uint16)0xc60, (uint16)0x1c41,
    (uint16)0xedae, (uint16)0xfd8f, (uint16)0xcdec, (uint16)0xddcd, 
    (uint16)0xad2a, (uint16)0xbd0b, (uint16)0x8d68, (uint16)0x9d49,
    (uint16)0x7e97, (uint16)0x6eb6, (uint16)0x5ed5, (uint16)0x4ef4, 
    (uint16)0x3e13, (uint16)0x2e32, (uint16)0x1e51, (uint16)0xe70,
    (uint16)0xff9f, (uint16)0xefbe, (uint16)0xdfdd, (uint16)0xcffc, 
    (uint16)0xbf1b, (uint16)0xaf3a, (uint16)0x9f59, (uint16)0x8f78,
    (uint16)0x9188, (uint16)0x81a9, (uint16)0xb1ca, (uint16)0xa1eb, 
    (uint16)0xd10c, (uint16)0xc12d, (uint16)0xf14e, (uint16)0xe16f,
    (uint16)0x1080, (uint16)0xa1, (uint16)0x30c2, (uint16)0x20e3, 
    (uint16)0x5004, (uint16)0x4025, (uint16)0x7046, (uint16)0x6067,
    (uint16)0x83b9, (uint16)0x9398, (uint16)0xa3fb, (uint16)0xb3da, 
    (uint16)0xc33d, (uint16)0xd31c, (uint16)0xe37f, (uint16)0xf35e,
    (uint16)0x2b1, (uint16)0x1290, (uint16)0x22f3, (uint16)0x32d2, 
    (uint16)0x4235, (uint16)0x5214, (uint16)0x6277, (uint16)0x7256,
    (uint16)0xb5ea, (uint16)0xa5cb, (uint16)0x95a8, (uint16)0x8589, 
    (uint16)0xf56e, (uint16)0xe54f, (uint16)0xd52c, (uint16)0xc50d,
    (uint16)0x34e2, (uint16)0x24c3, (uint16)0x14a0, (uint16)0x481, 
    (uint16)0x7466, (uint16)0x6447, (uint16)0x5424, (uint16)0x4405,
    (uint16)0xa7db, (uint16)0xb7fa, (uint16)0x8799, (uint16)0x97b8, 
    (uint16)0xe75f, (uint16)0xf77e, (uint16)0xc71d, (uint16)0xd73c,
    (uint16)0x26d3, (uint16)0x36f2, (uint16)0x691, (uint16)0x16b0, 
    (uint16)0x6657, (uint16)0x7676, (uint16)0x4615, (uint16)0x5634,
    (uint16)0xd94c, (uint16)0xc96d, (uint16)0xf90e, (uint16)0xe92f, 
    (uint16)0x99c8, (uint16)0x89e9, (uint16)0xb98a, (uint16)0xa9ab,
    (uint16)0x5844, (uint16)0x4865, (uint16)0x7806, (uint16)0x6827, 
    (uint16)0x18c0, (uint16)0x8e1, (uint16)0x3882, (uint16)0x28a3,
    (uint16)0xcb7d, (uint16)0xdb5c, (uint16)0xeb3f, (uint16)0xfb1e, 
    (uint16)0x8bf9, (uint16)0x9bd8, (uint16)0xabbb, (uint16)0xbb9a,
    (uint16)0x4a75, (uint16)0x5a54, (uint16)0x6a37, (uint16)0x7a16, 
    (uint16)0xaf1, (uint16)0x1ad0, (uint16)0x2ab3, (uint16)0x3a92,
    (uint16)0xfd2e, (uint16)0xed0f, (uint16)0xdd6c, (uint16)0xcd4d, 
    (uint16)0xbdaa, (uint16)0xad8b, (uint16)0x9de8, (uint16)0x8dc9,
    (uint16)0x7c26, (uint16)0x6c07, (uint16)0x5c64, (uint16)0x4c45, 
    (uint16)0x3ca2, (uint16)0x2c83, (uint16)0x1ce0, (uint16)0xcc1,
    (uint16)0xef1f, (uint16)0xff3e, (uint16)0xcf5d, (uint16)0xdf7c, 
    (uint16)0xaf9b, (uint16)0xbfba, (uint16)0x8fd9, (uint16)0x9ff8,
    (uint16)0x6e17, (uint16)0x7e36, (uint16)0x4e55, (uint16)0x5e74, 
    (uint16)0x2e93, (uint16)0x3eb2, (uint16)0xed1, (uint16)0x1ef0
};

#define CRC_STOP_SEC_VAR_INIT_16
#include "MemMap.h"

/*******************************************************************************
*   Local Data Define
*******************************************************************************/
#define CRC_START_SEC_CODE
#include "MemMap.h"

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Crc_CalculateCRC16
*
* Description:   This service makes a CRC16 calculation on Crc_Length data bytes, with SAE J1850 parameters.
*
*
* Inputs:        Crc_DataPtr          Pointer to start address of data block to be calculated.
*                Crc_Length           Length of data block to be calculated in bytes.
*                Crc_StartValue16     Start value when the algorithm starts.
*                Crc_IsFirstCall      TRUE: First call in a sequence or individual CRC calculation;
*                                          start from initial value, ignore Crc_StartValue16.
*                                     FALSE: Subsequent call in a call sequence; Crc_StartValue16
*                                     is interpreted to be the return value of the previous function call.
*
* Outputs:       uint32:   8 bit result of CRC calculation.
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
/*******************************************************************************
* CRC2: The CRC module shall implement the CRC16 routine based on
* the CCITT-FALSE CRC16 Standard:
*******************************************************************************/
/* CRC19*/
/*******************************************************************************
* CRC15: The function Crc_CalculateCRC16 shall perform a CRC16 calculation on
* Crc_Length data bytes, pointed to by Crc_DataPtr, with the start-ing value of
* Crc_StartValue16.
*******************************************************************************/
FUNC(uint16, CRC_CODE) Crc_CalculateCRC16
(
    P2CONST(uint8, AUTOMATIC, CRC_APPL_DATA) Crc_DataPtr,
    uint32 Crc_Length,
    uint16 Crc_StartValue16,
    boolean Crc_IsFirstCall
)
{
    uint16 crc;
    uint32 i;


    if (Crc_IsFirstCall == TRUE)
    {
        /* CRC14*/
        crc = CRC_16_INIT_VALUE;
    }
    else
    {
        /* CRC41*/
        crc = Crc_StartValue16 ^ CRC_16_XOR_VALUE;
    }

    for (i = (uint32)0; i < Crc_Length; i++)
    {
        /*get the crc16 table index by data and crc*/
        crc = Crc_Table16[Crc_DataPtr[i] ^ (uint8)(crc >> RIGHTMOVE_INDEX)] ^ (crc << RIGHTMOVE_INDEX);
    }

    return (crc ^ CRC_16_XOR_VALUE);
}

#define CRC_STOP_SEC_CODE
#include "MemMap.h"
