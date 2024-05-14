/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
*   File Name       : Crc32P4.c
********************************************************************************
*   Project/Product : AUTOSAR 4.2.2
*   Title           : 32-bit CRC function module Source File(using the polynomial 0xF4ACFB13 )
*   Author          : Hirain
********************************************************************************
*   Description     : This service makes a CRC32 calculation on Crc_Length data bytes, using the polynomial 0xF4ACFB13.
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
#define CRC_32P4_INIT_VALUE     ((uint32)(0xFFFFFFFF))
#define CRC_32P4_XOR_VALUE      ((uint32)(0xFFFFFFFF))

#define CRC_START_SEC_VAR_INIT_32
#include "MemMap.h"

STATIC CONST(uint32, CRC_CONST) Crc_Table32P4[TABLE_SIZE] =
{
    (uint32)0x00000000, (uint32)0x30850ff5, (uint32)0x610a1fea, (uint32)0x518f101f,
    (uint32)0xc2143fd4, (uint32)0xf2913021, (uint32)0xa31e203e, (uint32)0x939b2fcb,
    (uint32)0x159615f7, (uint32)0x25131a02, (uint32)0x749c0a1d, (uint32)0x441905e8,
    (uint32)0xd7822a23, (uint32)0xe70725d6, (uint32)0xb68835c9, (uint32)0x860d3a3c,
    (uint32)0x2b2c2bee, (uint32)0x1ba9241b, (uint32)0x4a263404, (uint32)0x7aa33bf1,
    (uint32)0xe938143a, (uint32)0xd9bd1bcf, (uint32)0x88320bd0, (uint32)0xb8b70425,
    (uint32)0x3eba3e19, (uint32)0xe3f31ec, (uint32)0x5fb021f3, (uint32)0x6f352e06,
    (uint32)0xfcae01cd, (uint32)0xcc2b0e38, (uint32)0x9da41e27, (uint32)0xad2111d2,
    (uint32)0x565857dc, (uint32)0x66dd5829, (uint32)0x37524836, (uint32)0x7d747c3,
    (uint32)0x944c6808, (uint32)0xa4c967fd, (uint32)0xf54677e2, (uint32)0xc5c37817,
    (uint32)0x43ce422b, (uint32)0x734b4dde, (uint32)0x22c45dc1, (uint32)0x12415234,
    (uint32)0x81da7dff, (uint32)0xb15f720a, (uint32)0xe0d06215, (uint32)0xd0556de0,
    (uint32)0x7d747c32, (uint32)0x4df173c7, (uint32)0x1c7e63d8, (uint32)0x2cfb6c2d,
    (uint32)0xbf6043e6, (uint32)0x8fe54c13, (uint32)0xde6a5c0c, (uint32)0xeeef53f9,
    (uint32)0x68e269c5, (uint32)0x58676630, (uint32)0x9e8762f, (uint32)0x396d79da,
    (uint32)0xaaf65611, (uint32)0x9a7359e4, (uint32)0xcbfc49fb, (uint32)0xfb79460e,
    (uint32)0xacb0afb8, (uint32)0x9c35a04d, (uint32)0xcdbab052, (uint32)0xfd3fbfa7,
    (uint32)0x6ea4906c, (uint32)0x5e219f99, (uint32)0xfae8f86, (uint32)0x3f2b8073,
    (uint32)0xb926ba4f, (uint32)0x89a3b5ba, (uint32)0xd82ca5a5, (uint32)0xe8a9aa50,
    (uint32)0x7b32859b, (uint32)0x4bb78a6e, (uint32)0x1a389a71, (uint32)0x2abd9584,
    (uint32)0x879c8456, (uint32)0xb7198ba3, (uint32)0xe6969bbc, (uint32)0xd6139449,
    (uint32)0x4588bb82, (uint32)0x750db477, (uint32)0x2482a468, (uint32)0x1407ab9d,
    (uint32)0x920a91a1, (uint32)0xa28f9e54, (uint32)0xf3008e4b, (uint32)0xc38581be,
    (uint32)0x501eae75, (uint32)0x609ba180, (uint32)0x3114b19f, (uint32)0x191be6a,
    (uint32)0xfae8f864, (uint32)0xca6df791, (uint32)0x9be2e78e, (uint32)0xab67e87b,
    (uint32)0x38fcc7b0, (uint32)0x879c845, (uint32)0x59f6d85a, (uint32)0x6973d7af,
    (uint32)0xef7eed93, (uint32)0xdffbe266, (uint32)0x8e74f279, (uint32)0xbef1fd8c,
    (uint32)0x2d6ad247, (uint32)0x1defddb2, (uint32)0x4c60cdad, (uint32)0x7ce5c258,
    (uint32)0xd1c4d38a, (uint32)0xe141dc7f, (uint32)0xb0cecc60, (uint32)0x804bc395,
    (uint32)0x13d0ec5e, (uint32)0x2355e3ab, (uint32)0x72daf3b4, (uint32)0x425ffc41,
    (uint32)0xc452c67d, (uint32)0xf4d7c988, (uint32)0xa558d997, (uint32)0x95ddd662,
    (uint32)0x646f9a9, (uint32)0x36c3f65c, (uint32)0x674ce643, (uint32)0x57c9e9b6,
    (uint32)0xc8df352f, (uint32)0xf85a3ada, (uint32)0xa9d52ac5, (uint32)0x99502530,
    (uint32)0xacb0afb, (uint32)0x3a4e050e, (uint32)0x6bc11511, (uint32)0x5b441ae4,
    (uint32)0xdd4920d8, (uint32)0xedcc2f2d, (uint32)0xbc433f32, (uint32)0x8cc630c7,
    (uint32)0x1f5d1f0c, (uint32)0x2fd810f9, (uint32)0x7e5700e6, (uint32)0x4ed20f13,
    (uint32)0xe3f31ec1, (uint32)0xd3761134, (uint32)0x82f9012b, (uint32)0xb27c0ede,
    (uint32)0x21e72115, (uint32)0x11622ee0, (uint32)0x40ed3eff, (uint32)0x7068310a,
    (uint32)0xf6650b36, (uint32)0xc6e004c3, (uint32)0x976f14dc, (uint32)0xa7ea1b29,
    (uint32)0x347134e2, (uint32)0x4f43b17, (uint32)0x557b2b08, (uint32)0x65fe24fd,
    (uint32)0x9e8762f3, (uint32)0xae026d06, (uint32)0xff8d7d19, (uint32)0xcf0872ec,
    (uint32)0x5c935d27, (uint32)0x6c1652d2, (uint32)0x3d9942cd, (uint32)0xd1c4d38,
    (uint32)0x8b117704, (uint32)0xbb9478f1, (uint32)0xea1b68ee, (uint32)0xda9e671b,
    (uint32)0x490548d0, (uint32)0x79804725, (uint32)0x280f573a, (uint32)0x188a58cf,
    (uint32)0xb5ab491d, (uint32)0x852e46e8, (uint32)0xd4a156f7, (uint32)0xe4245902,
    (uint32)0x77bf76c9, (uint32)0x473a793c, (uint32)0x16b56923, (uint32)0x263066d6,
    (uint32)0xa03d5cea, (uint32)0x90b8531f, (uint32)0xc1374300, (uint32)0xf1b24cf5,
    (uint32)0x6229633e, (uint32)0x52ac6ccb, (uint32)0x3237cd4, (uint32)0x33a67321,
    (uint32)0x646f9a97, (uint32)0x54ea9562, (uint32)0x565857d, (uint32)0x35e08a88,
    (uint32)0xa67ba543, (uint32)0x96feaab6, (uint32)0xc771baa9, (uint32)0xf7f4b55c,
    (uint32)0x71f98f60, (uint32)0x417c8095, (uint32)0x10f3908a, (uint32)0x20769f7f,
    (uint32)0xb3edb0b4, (uint32)0x8368bf41, (uint32)0xd2e7af5e, (uint32)0xe262a0ab,
    (uint32)0x4f43b179, (uint32)0x7fc6be8c, (uint32)0x2e49ae93, (uint32)0x1ecca166,
    (uint32)0x8d578ead, (uint32)0xbdd28158, (uint32)0xec5d9147, (uint32)0xdcd89eb2,
    (uint32)0x5ad5a48e, (uint32)0x6a50ab7b, (uint32)0x3bdfbb64, (uint32)0xb5ab491,
    (uint32)0x98c19b5a, (uint32)0xa84494af, (uint32)0xf9cb84b0, (uint32)0xc94e8b45,
    (uint32)0x3237cd4b, (uint32)0x2b2c2be, (uint32)0x533dd2a1, (uint32)0x63b8dd54,
    (uint32)0xf023f29f, (uint32)0xc0a6fd6a, (uint32)0x9129ed75, (uint32)0xa1ace280,
    (uint32)0x27a1d8bc, (uint32)0x1724d749, (uint32)0x46abc756, (uint32)0x762ec8a3,
    (uint32)0xe5b5e768, (uint32)0xd530e89d, (uint32)0x84bff882, (uint32)0xb43af777,
    (uint32)0x191be6a5, (uint32)0x299ee950, (uint32)0x7811f94f, (uint32)0x4894f6ba,
    (uint32)0xdb0fd971, (uint32)0xeb8ad684, (uint32)0xba05c69b, (uint32)0x8a80c96e,
    (uint32)0xc8df352, (uint32)0x3c08fca7, (uint32)0x6d87ecb8, (uint32)0x5d02e34d,
    (uint32)0xce99cc86, (uint32)0xfe1cc373, (uint32)0xaf93d36c, (uint32)0x9f16dc99
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
* Function Name: Crc_CalculateCRC32P4
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

* Outputs:       uint32:   32 bit result of CRC calculation.
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
/* CRC56,CRC58,CRC59*/
FUNC(uint32, CRC_CODE) Crc_CalculateCRC32P4
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
        /* CRC14*/
        crc = (CRC_32P4_INIT_VALUE);
    }
    else
    {
        /* CRC41*/
        crc = (Crc_StartValue32) ^ (CRC_32P4_XOR_VALUE);
    }

    for (i = (uint32)0; i < Crc_Length; i++)
    {
        /*get the crc32P4 table index by data and crc*/
        crc = Crc_Table32P4[(Crc_DataPtr[i]) ^ ((uint8)crc)] ^ (crc >> RIGHTMOVE_INDEX);
    }

    return (crc ^ CRC_32P4_XOR_VALUE);
}


#define CRC_STOP_SEC_CODE
#include "MemMap.h"

