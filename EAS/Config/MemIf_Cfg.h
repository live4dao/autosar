/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : MemIf_Cfg.h
********************************************************************************
*   Project/Product : AUTOSAR BSW PROJECT
*   Title           : MemIf module configuration File
*   Author          : Hirain
********************************************************************************
*   Description     : MemIf module configuration File
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

#ifndef MEMIF_CFG_H
#define MEMIF_CFG_H

/*******************************************************************************
    Includes Files
*******************************************************************************/
#include "MemIf_Types.h"
#include "Fee.h"

/*******************************************************************************
    Macro Definition
*******************************************************************************/
#define MEMIF_CONFIG_VARIANTS                               STD_CONFIG_VARIANTS_PRECOMPILE

#define MEMIF_DEV_ERROR_DETECT                              STD_OFF
#define MEMIF_VERSION_INFO_API                              STD_ON
#define MEMIF_NUMBER_OF_DEVICE                              1
#define MEMIF_VERSION_CHECK                                 STD_OFF
#define MEMIF_BROADCAST_ID                                  ((uint8)255)
#define MEMIF_SW_MAJOR_VERSION_CFG                          1
#define MEMIF_SW_MINOR_VERSION_CFG                          2
#define MEMIF_SW_PATCH_VERSION_CFG                          1
#define MEMIF_AR_RELEASE_MAJOR_VERSION_CFG                  4
#define MEMIF_AR_RELEASE_MINOR_VERSION_CFG                  2
#define MEMIF_AR_RELEASE_REVISION_VERSION_CFG               2

/*******************************************************************************
    Prototype Definition
*******************************************************************************/
#define MemIf_SetMode(Mode) \
    Fee_SetMode((Mode))
#define MemIf_Read(DeviceIndex, BlockNumber, BlockOffset, DataBufferPtr, Length) \
    Fee_Read((BlockNumber), (BlockOffset), (DataBufferPtr), (Length))
#define MemIf_Write(DeviceIndex, BlockNumber, DataBufferPtr) \
    Fee_Write((BlockNumber), (DataBufferPtr))
#define MemIf_EraseImmediateBlock(DeviceIndex, BlockNumber) \
    Fee_EraseImmediateBlock((BlockNumber))
#define MemIf_InvalidateBlock(DeviceIndex, BlockNumber) \
    Fee_InvalidateBlock((BlockNumber))
#define MemIf_Cancel(DeviceIndex) \
    Fee_Cancel()
#define MemIf_GetStatus(DeviceIndex) \
    Fee_GetStatus()
#define MemIf_GetJobResult(DeviceIndex) \
    Fee_GetJobResult()

#endif /* #ifndef MEMIF_CFG_H */


