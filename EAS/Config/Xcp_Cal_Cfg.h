/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : Xcp_Cal_Cfg.h
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
#ifndef XCP_CAL_CFG_H
#define XCP_CAL_CFG_H

/*******************************************************************************
*   Include files
*******************************************************************************/

/*******************************************************************************
*   Parameter
*******************************************************************************/
#define XCP_CAL_SUPPORTED                                   STD_ON
#define XCP_MASTER_BLOCK_MODE_SUPPORT                       STD_ON
#define XCP_MASTER_BLOCK_BUFFER_SIZE                        200
#define XCP_MIN_ST                                          1
#define XCP_CHECK_WRITEMTA_CBK_SUPPORT                      STD_OFF
#define XCP_MODIFYBITS_SUPPORT                              STD_OFF

#endif /* ifndef XCP_CAL_CFG_H*/


