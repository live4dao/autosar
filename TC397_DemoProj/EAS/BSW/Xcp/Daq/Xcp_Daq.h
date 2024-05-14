/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
*   File Name       : Xcp_Daq.h
********************************************************************************
*   Project/Product : AUTOSAR 4.2
*   Title           : Xcp module head File
*   Author          : Hirain
********************************************************************************
*   Description     : Implementation of Xcp provided functionality
*
********************************************************************************
*   Limitations     : None
*
********************************************************************************
*
********************************************************************************
*   Revision History:
********************************************************************************
* END_FILE_HDR*/

#ifndef XCP_DAQ_H
#define XCP_DAQ_H

/*******************************************************************************
*   Includes
*******************************************************************************/
#include "Xcp_Process.h"

#if(STD_ON == XCP_DAQ_SUPPORTED)
/*******************************************************************************
*   macro define
*******************************************************************************/
#define XCP_WRITE_DAQ_NO_BIT_MASK      ((uint8)0xFFU)
#define XCP_WRITE_DAQ_BIT_MASK_MAX     ((uint8)0x1FU)


#define XCP_INVALID_DAQ_NUM         ((uint16)0xFFFFU)
#define XCP_INVALID_ODT_NUM         ((uint8)0xFFU)
#define XCP_INVALID_ODTENTRY_NUM    ((uint8)0xFFU)

#define XCP_DAQMODE_PIDOFF_MASK     (0x20U)
#define XCP_DAQMODE_TIMESTAMP_MASK  (0x10U)
#define XCP_DAQMODE_DIR_MASK        (0x02U)

/*******************************************************************************
*   extern data declair
*******************************************************************************/


#define XCP_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"

#if(XCP_MAX_EVENT_CHANNEL > 0)
extern CONST (Xcp_Event_Config_Type, XCP_CONST) Xcp_EventConfig[XCP_MAX_EVENT_CHANNEL];
#endif


#if(XCP_MAX_DAQ > 0)
extern CONST (Xcp_DAQ_Config_Type, XCP_CONST) Xcp_DAQConfig[XCP_MAX_DAQ];
#endif


#define XCP_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"



/*******************************************************************************
*   extern function declair
*******************************************************************************/
#define XCP_START_SEC_CODE
#include "MemMap.h"

extern FUNC(void, XCP_CODE) Xcp_DaqInit (void);
extern FUNC(void, XCP_CODE) Xcp_DaqMainFuntion (void);
extern FUNC(void, XCP_CODE) Xcp_DaqTxContinue (void);

extern FUNC(void, XCP_CODE) Xcp_RestartDaqPending (void);

/*DAQ*/
extern FUNC(void, XCP_CODE) Xcp_FuncClearDaqList (void);
extern FUNC(void, XCP_CODE) Xcp_FuncSetDaqPtr (void);
extern FUNC(void, XCP_CODE) Xcp_FuncWriteDaq (void);
extern FUNC(void, XCP_CODE) Xcp_FuncSetDaqListMode (void);
extern FUNC(void, XCP_CODE) Xcp_FuncGetDaqListMode (void);
extern FUNC(void, XCP_CODE) Xcp_FuncStartStopDaqList (void);
extern FUNC(void, XCP_CODE) Xcp_FuncStartStopSynch (void);

/*DAQ Option*/
extern FUNC(void, XCP_CODE) Xcp_FuncGetDaqClock (void);
extern FUNC(void, XCP_CODE) Xcp_FuncReadDaq (void);
extern FUNC(void, XCP_CODE) Xcp_FuncGetDaqProcessorInfo (void);
extern FUNC(void, XCP_CODE) Xcp_FuncGetDaqResolution_Info (void);
extern FUNC(void, XCP_CODE) Xcp_FuncGetDaqListInfo (void);
extern FUNC(void, XCP_CODE) Xcp_FuncGetDaqEventInfo (void);


#define XCP_STOP_SEC_CODE
#include "MemMap.h"

#else

#define Xcp_FuncClearDaqList          NULL_PTR
#define Xcp_FuncSetDaqPtr             NULL_PTR
#define Xcp_FuncWriteDaq              NULL_PTR
#define Xcp_FuncSetDaqListMode        NULL_PTR
#define Xcp_FuncGetDaqListMode        NULL_PTR
#define Xcp_FuncStartStopDaqList      NULL_PTR
#define Xcp_FuncStartStopSynch        NULL_PTR

#define Xcp_FuncGetDaqClock           NULL_PTR
#define Xcp_FuncReadDaq               NULL_PTR
#define Xcp_FuncGetDaqProcessorInfo   NULL_PTR
#define Xcp_FuncGetDaqResolution_Info NULL_PTR
#define Xcp_FuncGetDaqListInfo        NULL_PTR
#define Xcp_FuncGetDaqEventInfo       NULL_PTR


#endif /*#if(STD_ON == XCP_DAQ_SUPPORTED)*/


#endif  /* ifndef XCP_DAQ_H*/

