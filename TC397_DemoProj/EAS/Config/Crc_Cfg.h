/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : Crc_Cfg.h
********************************************************************************
*   Project/Product : AUTOSAR BSW PROJECT
*   Title           : Crc module configuration File
*   Author          : Hirain
********************************************************************************
*   Description     : Crc module configuration File
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
#ifndef CRC_CFG_H
#define CRC_CFG_H
/*******************************************************************************
*   Macro 
*******************************************************************************/
#define CRC_8_TABLE         (0)
#define CRC_8_RUNTIME       (1)
#define CRC_8_HARDWARE      (2)

#define CRC_8H2F_TABLE      (0)
#define CRC_8H2F_RUNTIME    (1)
#define CRC_8H2F_HARDWARE   (2)

#define CRC_16_TABLE        (0)
#define CRC_16_RUNTIME      (1)
#define CRC_16_HARDWARE     (2)

#define CRC_32_TABLE        (0)
#define CRC_32_RUNTIME      (1)
#define CRC_32_HARDWARE     (2)

#define CRC_32P4_TABLE      (0)
#define CRC_32P4_RUNTIME    (1)
#define CRC_32P4_HARDWARE   (2)

#define CRC_8_MODE         CRC_8_TABLE
#define CRC_8H2F_MODE      CRC_8H2F_TABLE
#define CRC_16_MODE        CRC_16_TABLE
#define CRC_32_MODE        CRC_32_TABLE
#define CRC_32P4_MODE      CRC_32P4_TABLE


#define CRC_PRIVATE_VERSION_CHECK                           STD_ON

/* generate tool's version*/
#define CRC_SW_MAJOR_VERSION_CFG                            1
#define CRC_SW_MINOR_VERSION_CFG                            2
#define CRC_SW_PATCH_VERSION_CFG                            3
#define CRC_AR_RELEASE_MAJOR_VERSION_CFG                    4
#define CRC_AR_RELEASE_MINOR_VERSION_CFG                    2
#define CRC_AR_RELEASE_REVISION_VERSION_CFG                 2

#endif


