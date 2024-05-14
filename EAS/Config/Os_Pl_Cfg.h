/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : Os_Pl_Cfg.h
********************************************************************************
*   Project/Product : AUTOSAR BSW PROJECT
*   Title           : OS module configuration File
*   Author          : Hirain
********************************************************************************
*   Description     : OS module configuration File
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

#ifndef OS_PL_CFG_H
#define OS_PL_CFG_H


#define OS_PL_SW_MAJOR_VERSION_CFG                          1
#define OS_PL_SW_TEC_VERSION_CFG                            3
#define OS_PL_SW_TKPC_VERSION_CFG                           4
#define OS_PL_SW_PATCH_VERSION_CFG                          0
#define OS_PL_IDE                                           OS_PL_Tasking
#define OS_PL_CHIP                                          OS_PL_TC_397
#define OS_PL_REG_RETRY_TIMES                               ((Os_uint8)3)
#define OS_PL_SYSTIMER_RELOAD_VAL                           ((Os_uint32)100000)
#define OS_PL_MAX_CORE_NUMBER                               6


#endif
