/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : Xcp_Cfg.h
********************************************************************************
*   Project/Product : AUTOSAR BSW PROJECT
*   Title           : Xcp module configuration File
*   Author          : Hirain
********************************************************************************
*   Description     : Xcp module configuration File
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
#ifndef XCP_CFG_H
#define XCP_CFG_H

/*******************************************************************************
*   Include files
*******************************************************************************/

/*******************************************************************************
*   Macro
*******************************************************************************/
#define XCP_LSB_FIRST                                       (1) /*Byte order type, 1:Intel*/
#define XCP_MSB_FIRST                                       (0) /*Byte order type, 0:Motorola*/

/*******************************************************************************
*   Parameter
*******************************************************************************/
#define XCP_CONFIG_VARIANTS                                 STD_CONFIG_VARIANTS_PRECOMPILE
#define XCP_VERSION_CHECK                                   STD_ON
#define XCP_DEV_ERROR_DETECT                                STD_ON
#define XCP_VERSION_INFO_API                                STD_OFF
#define XCP_MAIN_FUNCTION_PERIOD                            5

#define XCP_ON_CAN_ENABLED                                  STD_OFF
#define XCP_ON_ETHERNET_ENABLED                             STD_ON
#define XCP_ON_FLEXRAY_ENABLED                              STD_OFF

#define XCP_CONFIG_NUM                                      1
#define XCP_NUMBER_OF_SUPPORTED_PRO                         (1)
#define XCP_PRO_HANDLE_ON_ETH                               0
#define XCP_RX_BUFFER_SIZE                                  204
#define XCP_TX_BUFFER_SIZE                                  204
#define XCP_BYTE_ORDER                                      XCP_MSB_FIRST
#define XCP_BIT_ORDER                                       CPU_BIT_ORDER
#define XCP_AG                                              1
#define XCP_ASYN_TIMEOUT                                    0
#define XCP_TX_TIMEOUT                                      0
#define XCP_ASYN_TIMEOUT_CBK_SUPPORT                        STD_OFF
#define XCP_TX_TIMEOUT_CBK_SUPPORT                          STD_OFF
#define XCP_SPECIAL_ACCESS_RAM                              STD_OFF

#define XCP_SW_MAJOR_VERSION_CFG                            1
#define XCP_SW_MINOR_VERSION_CFG                            0
#define XCP_SW_PATCH_VERSION_CFG                            17
#define XCP_AR_RELEASE_MAJOR_VERSION_CFG                    4
#define XCP_AR_RELEASE_MINOR_VERSION_CFG                    2
#define XCP_AR_RELEASE_REVISION_VERSION_CFG                 2

/*******************************************************************************
*   PduRef
*******************************************************************************/
#define Xcp_Xcp_Rx                                          0
#define Xcp_Xcp_Tx                                          0

#endif

