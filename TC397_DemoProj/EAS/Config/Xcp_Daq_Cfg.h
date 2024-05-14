/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : Xcp_Daq_Cfg.h
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
#ifndef XCP_DAQ_CFG_H
#define XCP_DAQ_CFG_H

/*******************************************************************************
*   Include files
*******************************************************************************/

/*******************************************************************************
*   Macro
*******************************************************************************/
#define XCP_DAQ_NO_OVERLOAD_IND                				(0)
#define XCP_DAQ_OVERLOAD_MSB                   				(1)
#define XCP_DAQ_OVERLOAD_EVENT                 				(2)

#define XCP_ID_ABS_TYPE                        				(0)
#define XCP_ID_REL_BYTE_TYPE                   				(1)
#define XCP_ID_REL_WORD_TYPE                   				(2)
#define XCP_ID_REL_WORDALG_TYPE                				(3)

/*******************************************************************************
*   Parameter
*******************************************************************************/
#define XCP_DAQ_SUPPORTED                                   STD_ON
#define XCP_BITOFFSET_SUPPORT                               STD_OFF
#define XCP_STIM_SUPPORTED                      			STD_OFF
#define XCP_OVERLOAD_IND_TYPE                   			XCP_DAQ_NO_OVERLOAD_IND
#define XCP_PIDOFF_SUPPORTED                    			STD_OFF
#define XCP_TIMESTAMP_SUPPORTED                 			STD_OFF
#define XCP_RESUME_SUPPORTED                    			STD_OFF
#define XCP_PRESCALER_SUPPORTED                 			STD_OFF
#define XCP_DAQ_CONFIG_DYNAMIC_SUPPORTED        			STD_OFF
#define DAQ_PROCESSOR_INFO                      			(0)
#define XCP_DAQ_PRIORITY_SUPPORTED              			STD_OFF
#define XCP_ID_FIELD_TYPE                       			XCP_ID_ABS_TYPE
#define DAQ_KEY_BYTE                            			(0)
#define XCP_GRANULARITY_ODT_ENTRY_SIZE_DAQ      			(1)
#define XCP_MAX_ODT_ENTRY_SIZE_DAQ              			(4)

#define XCP_MAX_DAQ                             			(1)
#define XCP_MAX_EVENT_CHANNEL                   			(1)
#define XCP_MIN_DAQ                             			(0)


#endif /* ifndef XCP_DAQ_CFG_H*/

