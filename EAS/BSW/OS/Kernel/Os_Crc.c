/* BEGIN_FILE_HDR
********************************************************************************
* NOTICE
* This software is the property of HiRain Technologies. Any information
* contained in this doc should not be reproduced, or used, or disclosed
* without the written authorization from HiRain Technologies.
********************************************************************************
* File Name:       Os_Crc.c
********************************************************************************
* Project/Product: AUTOSAR OS PROJECT
* Title:           Os_Crc.c
* Author:          Hirain
********************************************************************************
* Description:     Crc implement of OS
*
********************************************************************************
* Limitations     : None
*
********************************************************************************
*
********************************************************************************
* Revision History:
* Reference to Core Os_Kernel.c File
********************************************************************************
* END_FILE_HDR*/
/*PRQA S 0857 EOF*/
/*
Number of macro definitions exceeds 1024
*/
#include "Os_Internal.h"

/*****************************************************************************
* General QAC Suppression
******************************************************************************/
/*PRQA S 0862 EOF*/
/*
The code segment like:

#define XXX
#include "Os_MemMap.h"

is a part of AUTOSAR specification, but will be an error in PRQA.
*/

/*PRQA S 0553 EOF*/
/*
Some files are empty because user do not enable this function.
*/

#if(OS_CRC_SUPPORT == OS_ON)
/*******************************************************************************
*   Macro
*******************************************************************************/
#define OS_CRC_8_INIT_VALUE     ((Os_uint8)(0xFF))
#define OS_CRC_8_XOR_VALUE      ((Os_uint8)(0xFF))

#define OS_CRC_8_ARRAY_SIZE     ((Os_uint16)256)

#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"

STATIC CONST(Os_uint8, OS_CONST) OsCrc_Table8[OS_CRC_8_ARRAY_SIZE] =
{
    (Os_uint8)0x0,  (Os_uint8)0x1d, (Os_uint8)0x3a, (Os_uint8)0x27, (Os_uint8)0x74, (Os_uint8)0x69, (Os_uint8)0x4e, (Os_uint8)0x53,
    (Os_uint8)0xe8, (Os_uint8)0xf5, (Os_uint8)0xd2, (Os_uint8)0xcf, (Os_uint8)0x9c, (Os_uint8)0x81, (Os_uint8)0xa6, (Os_uint8)0xbb,
    (Os_uint8)0xcd, (Os_uint8)0xd0, (Os_uint8)0xf7, (Os_uint8)0xea, (Os_uint8)0xb9, (Os_uint8)0xa4, (Os_uint8)0x83, (Os_uint8)0x9e,
    (Os_uint8)0x25, (Os_uint8)0x38, (Os_uint8)0x1f, (Os_uint8)0x2,  (Os_uint8)0x51, (Os_uint8)0x4c, (Os_uint8)0x6b, (Os_uint8)0x76,
    (Os_uint8)0x87, (Os_uint8)0x9a, (Os_uint8)0xbd, (Os_uint8)0xa0, (Os_uint8)0xf3, (Os_uint8)0xee, (Os_uint8)0xc9, (Os_uint8)0xd4,
    (Os_uint8)0x6f, (Os_uint8)0x72, (Os_uint8)0x55, (Os_uint8)0x48, (Os_uint8)0x1b, (Os_uint8)0x6,  (Os_uint8)0x21, (Os_uint8)0x3c,
    (Os_uint8)0x4a, (Os_uint8)0x57, (Os_uint8)0x70, (Os_uint8)0x6d, (Os_uint8)0x3e, (Os_uint8)0x23, (Os_uint8)0x4,  (Os_uint8)0x19,
    (Os_uint8)0xa2, (Os_uint8)0xbf, (Os_uint8)0x98, (Os_uint8)0x85, (Os_uint8)0xd6, (Os_uint8)0xcb, (Os_uint8)0xec, (Os_uint8)0xf1,
    (Os_uint8)0x13, (Os_uint8)0xe,  (Os_uint8)0x29, (Os_uint8)0x34, (Os_uint8)0x67, (Os_uint8)0x7a, (Os_uint8)0x5d, (Os_uint8)0x40,
    (Os_uint8)0xfb, (Os_uint8)0xe6, (Os_uint8)0xc1, (Os_uint8)0xdc, (Os_uint8)0x8f, (Os_uint8)0x92, (Os_uint8)0xb5, (Os_uint8)0xa8,
    (Os_uint8)0xde, (Os_uint8)0xc3, (Os_uint8)0xe4, (Os_uint8)0xf9, (Os_uint8)0xaa, (Os_uint8)0xb7, (Os_uint8)0x90, (Os_uint8)0x8d,
    (Os_uint8)0x36, (Os_uint8)0x2b, (Os_uint8)0xc,  (Os_uint8)0x11, (Os_uint8)0x42, (Os_uint8)0x5f, (Os_uint8)0x78, (Os_uint8)0x65,
    (Os_uint8)0x94, (Os_uint8)0x89, (Os_uint8)0xae, (Os_uint8)0xb3, (Os_uint8)0xe0, (Os_uint8)0xfd, (Os_uint8)0xda, (Os_uint8)0xc7,
    (Os_uint8)0x7c, (Os_uint8)0x61, (Os_uint8)0x46, (Os_uint8)0x5b, (Os_uint8)0x8,  (Os_uint8)0x15, (Os_uint8)0x32, (Os_uint8)0x2f,
    (Os_uint8)0x59, (Os_uint8)0x44, (Os_uint8)0x63, (Os_uint8)0x7e, (Os_uint8)0x2d, (Os_uint8)0x30, (Os_uint8)0x17, (Os_uint8)0xa,
    (Os_uint8)0xb1, (Os_uint8)0xac, (Os_uint8)0x8b, (Os_uint8)0x96, (Os_uint8)0xc5, (Os_uint8)0xd8, (Os_uint8)0xff, (Os_uint8)0xe2,
    (Os_uint8)0x26, (Os_uint8)0x3b, (Os_uint8)0x1c, (Os_uint8)0x1,  (Os_uint8)0x52, (Os_uint8)0x4f, (Os_uint8)0x68, (Os_uint8)0x75,
    (Os_uint8)0xce, (Os_uint8)0xd3, (Os_uint8)0xf4, (Os_uint8)0xe9, (Os_uint8)0xba, (Os_uint8)0xa7, (Os_uint8)0x80, (Os_uint8)0x9d,
    (Os_uint8)0xeb, (Os_uint8)0xf6, (Os_uint8)0xd1, (Os_uint8)0xcc, (Os_uint8)0x9f, (Os_uint8)0x82, (Os_uint8)0xa5, (Os_uint8)0xb8,
    (Os_uint8)0x3,  (Os_uint8)0x1e, (Os_uint8)0x39, (Os_uint8)0x24, (Os_uint8)0x77, (Os_uint8)0x6a, (Os_uint8)0x4d, (Os_uint8)0x50,
    (Os_uint8)0xa1, (Os_uint8)0xbc, (Os_uint8)0x9b, (Os_uint8)0x86, (Os_uint8)0xd5, (Os_uint8)0xc8, (Os_uint8)0xef, (Os_uint8)0xf2,
    (Os_uint8)0x49, (Os_uint8)0x54, (Os_uint8)0x73, (Os_uint8)0x6e, (Os_uint8)0x3d, (Os_uint8)0x20, (Os_uint8)0x7,  (Os_uint8)0x1a,
    (Os_uint8)0x6c, (Os_uint8)0x71, (Os_uint8)0x56, (Os_uint8)0x4b, (Os_uint8)0x18, (Os_uint8)0x5,  (Os_uint8)0x22, (Os_uint8)0x3f,
    (Os_uint8)0x84, (Os_uint8)0x99, (Os_uint8)0xbe, (Os_uint8)0xa3, (Os_uint8)0xf0, (Os_uint8)0xed, (Os_uint8)0xca, (Os_uint8)0xd7,
    (Os_uint8)0x35, (Os_uint8)0x28, (Os_uint8)0xf,  (Os_uint8)0x12, (Os_uint8)0x41, (Os_uint8)0x5c, (Os_uint8)0x7b, (Os_uint8)0x66,
    (Os_uint8)0xdd, (Os_uint8)0xc0, (Os_uint8)0xe7, (Os_uint8)0xfa, (Os_uint8)0xa9, (Os_uint8)0xb4, (Os_uint8)0x93, (Os_uint8)0x8e,
    (Os_uint8)0xf8, (Os_uint8)0xe5, (Os_uint8)0xc2, (Os_uint8)0xdf, (Os_uint8)0x8c, (Os_uint8)0x91, (Os_uint8)0xb6, (Os_uint8)0xab,
    (Os_uint8)0x10, (Os_uint8)0xd,  (Os_uint8)0x2a, (Os_uint8)0x37, (Os_uint8)0x64, (Os_uint8)0x79, (Os_uint8)0x5e, (Os_uint8)0x43,
    (Os_uint8)0xb2, (Os_uint8)0xaf, (Os_uint8)0x88, (Os_uint8)0x95, (Os_uint8)0xc6, (Os_uint8)0xdb, (Os_uint8)0xfc, (Os_uint8)0xe1,
    (Os_uint8)0x5a, (Os_uint8)0x47, (Os_uint8)0x60, (Os_uint8)0x7d, (Os_uint8)0x2e, (Os_uint8)0x33, (Os_uint8)0x14, (Os_uint8)0x9,
    (Os_uint8)0x7f, (Os_uint8)0x62, (Os_uint8)0x45, (Os_uint8)0x58, (Os_uint8)0xb,  (Os_uint8)0x16, (Os_uint8)0x31, (Os_uint8)0x2c,
    (Os_uint8)0x97, (Os_uint8)0x8a, (Os_uint8)0xad, (Os_uint8)0xb0, (Os_uint8)0xe3, (Os_uint8)0xfe, (Os_uint8)0xd9, (Os_uint8)0xc4
};

#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"

/*******************************************************************************
*   Local Data Define
*******************************************************************************/
#define OS_START_SEC_CODE
#include "Os_MemMap.h"

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: OsCrc_Calculate
*
* Description:   This service makes a CRC8 calculation on OS_SAVE_CONTEXT_SIZE
*                data bytes, with SAE J1850 parameters.
*
*
* Inputs:        startAddr: Pointer to start address of data block to be calculated.
*
* Outputs:       uint8: 8 bit result of CRC calculation.
*
* Limitations:   In Os, the length of data involved in the CRC calculation is
*                fix, always call once to get the CRC result
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Os_uint8, OS_CODE) OsCrc_Calculate
(
    Os_AddrType startAddr
)
{
    Os_uint8 crc;
    Os_uint32 i;
    P2CONST(Os_uint8, AUTOMATIC, AUTOMATIC) Crc_DataPtr;

    Os_AddrType tempAddr;

    tempAddr = OsCpu_ConvertAddr(startAddr);

    /*PRQA S 0306 ++*/
    /*
    "tempAddr" is an address actually, 
    so the cast here is essential to access memory.
    Crc use data as uint8 here.
    */
    Crc_DataPtr = (const Os_uint8 *)tempAddr;
    /*PRQA S 0306 --*/

    crc = OS_CRC_8_INIT_VALUE;

    for (i = (Os_uint32)0; i < OS_SAVE_CONTEXT_SIZE; i++)
    {
        /*get the crc8H2F table index by data and crc*/
        crc = OsCrc_Table8[Crc_DataPtr[i] ^ crc];
    }

    return (crc ^ OS_CRC_8_XOR_VALUE);
}

#define OS_STOP_SEC_CODE
#include "Os_MemMap.h"

#endif /*(OS_CRC_SUPPORT == OS_ON)*/




