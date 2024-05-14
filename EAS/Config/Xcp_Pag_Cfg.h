/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : Xcp_Pag_Cfg.h
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
#ifndef XCP_PAG_CFG_H
#define XCP_PAG_CFG_H

/*******************************************************************************
*   Include files
*******************************************************************************/

/*******************************************************************************
*   Parameter
*******************************************************************************/
#define XCP_PAG_SUPPORTED                                   STD_OFF
#define XCP_PAGE_FREEZE_SUPPORTED                           STD_OFF
#define XCP_PAG_PROPERTIES                                  XCP_PAGE_FREEZE_SUPPORTED
#define XCP_MAX_SEGMENT                                     0
#define XCP_SETPAG_CBK_SUPPORT                              STD_OFF
#define XCP_COPYPAG_SUPPORT                                 STD_OFF
#define XCP_COPYPAG_ASYN_SUPPORT                            STD_OFF

#endif /* ifndef XCP_PAG_CFG_H*/

