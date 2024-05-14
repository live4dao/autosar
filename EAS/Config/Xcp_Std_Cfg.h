/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : Xcp_Std_Cfg.h
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
#ifndef XCP_STD_CFG_H
#define XCP_STD_CFG_H

/*******************************************************************************
*   Include files
*******************************************************************************/

/*******************************************************************************
*   Parameter
*******************************************************************************/
#define XCP_RESOURCE_IN_CONNECT                             ((uint8)0x5U)
#define XCP_SLAVE_BLOCK_MODE_SUPPORT                        STD_ON
#define XCP_COMM_MODE_BASIC                                 ((uint8)0xc1U)
#define XCP_INTERLEAVED_MODE                                STD_OFF
#define XCP_COMM_MODE_OPTIONAL                              ((uint8)0x1U)
#define XCP_QUEUE_SIZE                                      (0)
#define XCP_SEEDKEY_SUPPORT                                 STD_OFF
#define XCP_MAX_SEED_SIZE                                   0
#define XCP_MAX_KEY_SIZE                                    0
#define XCP_LOCK_INIT                                       ((uint8)0x0U)

#define XCP_AUX_CMD_SUPPORT                                 STD_OFF
#define XCP_USER_CONNECT_MODE_SUPPORT                       STD_OFF
#define XCP_GETSLAVEID_SUPPORT                              STD_OFF
#define XCP_CHECK_MTA_CBK_SUPPORT                           STD_OFF
#define XCP_CHECK_READMTA_CBK_SUPPORT                       STD_OFF
#define XCP_BUILDCS_SUPPORT                                 STD_OFF
#define XCP_BUILDCS_ASYN_SUPPORT                            STD_OFF

#define XCP_REQ_STORECALDATA_SUPPORT                        STD_OFF
#define XCP_REQ_STORECALDATA_ASYN_SUPPORT                   STD_OFF
#define XCP_REQ_STOREDAQ_SUPPORT                            STD_OFF
#define XCP_REQ_CLEARDAQ_SUPPORT                            STD_OFF
#define XCP_SETREQ_SUPPORT                                  (XCP_REQ_STORECALDATA_SUPPORT|XCP_REQ_STOREDAQ_SUPPORT|XCP_REQ_CLEARDAQ_SUPPORT)

#endif /* ifndef XCP_STD_CFG_H*/

