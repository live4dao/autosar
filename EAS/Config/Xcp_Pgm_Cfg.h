/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : Xcp_Pgm_Cfg.h
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
#ifndef XCP_PGM_CFG_H
#define XCP_PGM_CFG_H

/*******************************************************************************
*   Include files
*******************************************************************************/

/*******************************************************************************
*   Parameter
*******************************************************************************/
#define XCP_PGM_SUPPORTED                                   STD_OFF
#define XCP_MAX_SECTOR                                      0
#define XCP_MASTER_BLOCK_MODE_PGM_SUPPORT                   STD_OFF
#define XCP_SLAVE_BLOCK_MODE_PGM_SUPPORT                    STD_OFF
#define XCP_INTERLEAVED_MODE_PGM                            STD_OFF
#define XCP_COMM_MODE_PGM                                   ((uint8)0x0U)
#define XCP_MIN_ST_PGM                                      ((uint8)0x0U)
#define XCP_QUEUE_SIZE_PGM                                  0
#define XCP_PGM_FUN_ADDR_SUPPORTED                          STD_OFF
#define XCP_PGM_PROPERTIES                                  ((uint8)0x01U)
#define XCP_PGM_BUFFER_SIZE                                 (128)

#define XCP_PGMSTART_SUPPORT                                STD_OFF
#define XCP_PGM_ASYN_SUPPORT                                STD_OFF
#define XCP_CHECKPROGADDR_CBK_SUPPORT                       STD_OFF
#define XCP_PRERESET_CBK_SUPPORT                            STD_OFF
#define XCP_RESET_CBK_SUPPORT                               STD_OFF
#define XCP_GETSEQNUM_CBK_SUPPORT                           STD_OFF
#define XCP_PREPAREPROG_SUPPORT                             STD_OFF
#define XCP_PROGSEGMENTEND_CBK_SUPPORT                      STD_OFF

#endif /* ifndef XCP_PGM_CFG_H*/

