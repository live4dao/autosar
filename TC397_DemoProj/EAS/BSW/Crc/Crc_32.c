/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
*   File Name       : Crc32.c
********************************************************************************
*   Project/Product : AUTOSAR 4.2.2
*   Title           : 32-bit CRC function module Source File
*   Author          : Hirain
********************************************************************************
*   Description     : This service makes a CRC32 calculation on Crc_Length data bytes.

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
#define CRC_32_INIT_VALUE     ((uint32)(0xFFFFFFFF))
#define CRC_32_XOR_VALUE      ((uint32)(0xFFFFFFFF))

#define CRC_START_SEC_VAR_INIT_32
#include "MemMap.h"

STATIC CONST(uint32, CRC_CONST) Crc_Table32[TABLE_SIZE] =
{
    (uint32)0x00000000, (uint32)0x77073096, (uint32)0xee0e612c, (uint32)0x990951ba,
    (uint32)0x076dc419, (uint32)0x706af48f, (uint32)0xe963a535, (uint32)0x9e6495a3,
    (uint32)0x0edb8832, (uint32)0x79dcb8a4, (uint32)0xe0d5e91e, (uint32)0x97d2d988,
    (uint32)0x09b64c2b, (uint32)0x7eb17cbd, (uint32)0xe7b82d07, (uint32)0x90bf1d91,
    (uint32)0x1db71064, (uint32)0x6ab020f2, (uint32)0xf3b97148, (uint32)0x84be41de,
    (uint32)0x1adad47d, (uint32)0x6ddde4eb, (uint32)0xf4d4b551, (uint32)0x83d385c7,
    (uint32)0x136c9856, (uint32)0x646ba8c0, (uint32)0xfd62f97a, (uint32)0x8a65c9ec,
    (uint32)0x14015c4f, (uint32)0x63066cd9, (uint32)0xfa0f3d63, (uint32)0x8d080df5,
    (uint32)0x3b6e20c8, (uint32)0x4c69105e, (uint32)0xd56041e4, (uint32)0xa2677172,
    (uint32)0x3c03e4d1, (uint32)0x4b04d447, (uint32)0xd20d85fd, (uint32)0xa50ab56b,
    (uint32)0x35b5a8fa, (uint32)0x42b2986c, (uint32)0xdbbbc9d6, (uint32)0xacbcf940,
    (uint32)0x32d86ce3, (uint32)0x45df5c75, (uint32)0xdcd60dcf, (uint32)0xabd13d59,
    (uint32)0x26d930ac, (uint32)0x51de003a, (uint32)0xc8d75180, (uint32)0xbfd06116,
    (uint32)0x21b4f4b5, (uint32)0x56b3c423, (uint32)0xcfba9599, (uint32)0xb8bda50f,
    (uint32)0x2802b89e, (uint32)0x5f058808, (uint32)0xc60cd9b2, (uint32)0xb10be924,
    (uint32)0x2f6f7c87, (uint32)0x58684c11, (uint32)0xc1611dab, (uint32)0xb6662d3d,
    (uint32)0x76dc4190, (uint32)0x01db7106, (uint32)0x98d220bc, (uint32)0xefd5102a,
    (uint32)0x71b18589, (uint32)0x06b6b51f, (uint32)0x9fbfe4a5, (uint32)0xe8b8d433,
    (uint32)0x7807c9a2, (uint32)0x0f00f934, (uint32)0x9609a88e, (uint32)0xe10e9818,
    (uint32)0x7f6a0dbb, (uint32)0x086d3d2d, (uint32)0x91646c97, (uint32)0xe6635c01,
    (uint32)0x6b6b51f4, (uint32)0x1c6c6162, (uint32)0x856530d8, (uint32)0xf262004e,
    (uint32)0x6c0695ed, (uint32)0x1b01a57b, (uint32)0x8208f4c1, (uint32)0xf50fc457,
    (uint32)0x65b0d9c6, (uint32)0x12b7e950, (uint32)0x8bbeb8ea, (uint32)0xfcb9887c,
    (uint32)0x62dd1ddf, (uint32)0x15da2d49, (uint32)0x8cd37cf3, (uint32)0xfbd44c65,
    (uint32)0x4db26158, (uint32)0x3ab551ce, (uint32)0xa3bc0074, (uint32)0xd4bb30e2,
    (uint32)0x4adfa541, (uint32)0x3dd895d7, (uint32)0xa4d1c46d, (uint32)0xd3d6f4fb,
    (uint32)0x4369e96a, (uint32)0x346ed9fc, (uint32)0xad678846, (uint32)0xda60b8d0,
    (uint32)0x44042d73, (uint32)0x33031de5, (uint32)0xaa0a4c5f, (uint32)0xdd0d7cc9,
    (uint32)0x5005713c, (uint32)0x270241aa, (uint32)0xbe0b1010, (uint32)0xc90c2086,
    (uint32)0x5768b525, (uint32)0x206f85b3, (uint32)0xb966d409, (uint32)0xce61e49f,
    (uint32)0x5edef90e, (uint32)0x29d9c998, (uint32)0xb0d09822, (uint32)0xc7d7a8b4,
    (uint32)0x59b33d17, (uint32)0x2eb40d81, (uint32)0xb7bd5c3b, (uint32)0xc0ba6cad,
    (uint32)0xedb88320, (uint32)0x9abfb3b6, (uint32)0x03b6e20c, (uint32)0x74b1d29a,
    (uint32)0xead54739, (uint32)0x9dd277af, (uint32)0x04db2615, (uint32)0x73dc1683,
    (uint32)0xe3630b12, (uint32)0x94643b84, (uint32)0x0d6d6a3e, (uint32)0x7a6a5aa8,
    (uint32)0xe40ecf0b, (uint32)0x9309ff9d, (uint32)0x0a00ae27, (uint32)0x7d079eb1,
    (uint32)0xf00f9344, (uint32)0x8708a3d2, (uint32)0x1e01f268, (uint32)0x6906c2fe,
    (uint32)0xf762575d, (uint32)0x806567cb, (uint32)0x196c3671, (uint32)0x6e6b06e7,
    (uint32)0xfed41b76, (uint32)0x89d32be0, (uint32)0x10da7a5a, (uint32)0x67dd4acc,
    (uint32)0xf9b9df6f, (uint32)0x8ebeeff9, (uint32)0x17b7be43, (uint32)0x60b08ed5,
    (uint32)0xd6d6a3e8, (uint32)0xa1d1937e, (uint32)0x38d8c2c4, (uint32)0x4fdff252,
    (uint32)0xd1bb67f1, (uint32)0xa6bc5767, (uint32)0x3fb506dd, (uint32)0x48b2364b,
    (uint32)0xd80d2bda, (uint32)0xaf0a1b4c, (uint32)0x36034af6, (uint32)0x41047a60,
    (uint32)0xdf60efc3, (uint32)0xa867df55, (uint32)0x316e8eef, (uint32)0x4669be79,
    (uint32)0xcb61b38c, (uint32)0xbc66831a, (uint32)0x256fd2a0, (uint32)0x5268e236,
    (uint32)0xcc0c7795, (uint32)0xbb0b4703, (uint32)0x220216b9, (uint32)0x5505262f,
    (uint32)0xc5ba3bbe, (uint32)0xb2bd0b28, (uint32)0x2bb45a92, (uint32)0x5cb36a04,
    (uint32)0xc2d7ffa7, (uint32)0xb5d0cf31, (uint32)0x2cd99e8b, (uint32)0x5bdeae1d,
    (uint32)0x9b64c2b0, (uint32)0xec63f226, (uint32)0x756aa39c, (uint32)0x026d930a,
    (uint32)0x9c0906a9, (uint32)0xeb0e363f, (uint32)0x72076785, (uint32)0x05005713,
    (uint32)0x95bf4a82, (uint32)0xe2b87a14, (uint32)0x7bb12bae, (uint32)0x0cb61b38,
    (uint32)0x92d28e9b, (uint32)0xe5d5be0d, (uint32)0x7cdcefb7, (uint32)0x0bdbdf21,
    (uint32)0x86d3d2d4, (uint32)0xf1d4e242, (uint32)0x68ddb3f8, (uint32)0x1fda836e,
    (uint32)0x81be16cd, (uint32)0xf6b9265b, (uint32)0x6fb077e1, (uint32)0x18b74777,
    (uint32)0x88085ae6, (uint32)0xff0f6a70, (uint32)0x66063bca, (uint32)0x11010b5c,
    (uint32)0x8f659eff, (uint32)0xf862ae69, (uint32)0x616bffd3, (uint32)0x166ccf45,
    (uint32)0xa00ae278, (uint32)0xd70dd2ee, (uint32)0x4e048354, (uint32)0x3903b3c2,
    (uint32)0xa7672661, (uint32)0xd06016f7, (uint32)0x4969474d, (uint32)0x3e6e77db,
    (uint32)0xaed16a4a, (uint32)0xd9d65adc, (uint32)0x40df0b66, (uint32)0x37d83bf0,
    (uint32)0xa9bcae53, (uint32)0xdebb9ec5, (uint32)0x47b2cf7f, (uint32)0x30b5ffe9,
    (uint32)0xbdbdf21c, (uint32)0xcabac28a, (uint32)0x53b39330, (uint32)0x24b4a3a6,
    (uint32)0xbad03605, (uint32)0xcdd70693, (uint32)0x54de5729, (uint32)0x23d967bf,
    (uint32)0xb3667a2e, (uint32)0xc4614ab8, (uint32)0x5d681b02, (uint32)0x2a6f2b94,
    (uint32)0xb40bbe37, (uint32)0xc30c8ea1, (uint32)0x5a05df1b, (uint32)0x2d02ef8d
};

#define CRC_STOP_SEC_VAR_INIT_32
#include "MemMap.h"

/*******************************************************************************
*   Local Data Define
*******************************************************************************/
#define CRC_START_SEC_CODE
#include "MemMap.h"

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Crc_CalculateCRC32
*
* Description:   This service makes a CRC32 calculation on Crc_Length data bytes, using the polynomial 0xF4ACFB13.
*
*
* Inputs:        Crc_DataPtr          Pointer to start address of data block to be calculated.
*                Crc_Length           Length of data block to be calculated in bytes.
*                Crc_StartValue32     Start value when the algorithm starts.
*                Crc_IsFirstCall      TRUE: First call in a sequence or individual CRC calculation;
*                                          start from initial value, ignore Crc_StartValue32.
*                                     FALSE: Subsequent call in a call sequence; Crc_StartValue32
*                                     is interpreted to be the return value of the previous function call.
*
* Outputs:       uint32:   32 bit result of CRC calculation.
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
/*CRC20,CRC3,CRC16*/
FUNC(uint32, CRC_CODE) Crc_CalculateCRC32
(
    P2CONST(uint8, AUTOMATIC, CRC_APPL_DATA) Crc_DataPtr,
    uint32 Crc_Length,
    uint32 Crc_StartValue32,
    boolean Crc_IsFirstCall
)
{
    uint32 crc;
    uint32 i;


    if (Crc_IsFirstCall == TRUE)
    {
        /*CRC14*/
        crc = CRC_32_INIT_VALUE;
    }
    else
    {
        /*CRC41*/
        crc = (Crc_StartValue32) ^ (CRC_32_XOR_VALUE);
    }

    for (i = (uint32)0; i < Crc_Length; i++)
    {
        /*get the crc32 table index by data and crc*/
        crc = Crc_Table32[(Crc_DataPtr[i]) ^ ((uint8)crc)] ^ (crc >> RIGHTMOVE_INDEX);
    }

    return (crc ^ CRC_32_XOR_VALUE);
}

#define CRC_STOP_SEC_CODE
#include "MemMap.h"


