/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
*   File Name       : Xcp_Process.h
********************************************************************************
*   Project/Product : AUTOSAR 4.2
*   Title           : Xcp module Header File
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
#ifndef XCP_PROCESS_H
#define XCP_PROCESS_H

/*******************************************************************************
*   Includes
*******************************************************************************/
#include "Xcp_Callout.h"

/*******************************************************************************
*   macro define
*******************************************************************************/
/* XCP Protocol Layer Version define */
#define XCP_VERSION_MAJOR                       ((uint8)0x01U)
#define XCP_VERSION_MINOR                       ((uint8)0x00U)

/* XCP Transport Layer Version define */
#define XCP_TP_VERSION_MAJOR                    ((uint8)0x01U)
#define XCP_TP_VERSION_MINOR                    ((uint8)0x00U)

#define XCP_NUMBER_OF_COMMAND                   (56U)

/*Macro of byte number*/
#define XCP_PACKET_HEADER                       (Xcp_TpProConfig[Xcp_ActiveLink.XcpTpHandle].Header)
#define XCP_PACKET_BYTE0                        (XCP_PACKET_HEADER + 0)
#define XCP_PACKET_BYTE1                        (XCP_PACKET_HEADER + 1)
#define XCP_PACKET_BYTE2                        (XCP_PACKET_HEADER + 2)
#define XCP_PACKET_BYTE3                        (XCP_PACKET_HEADER + 3)
#define XCP_PACKET_BYTE4                        (XCP_PACKET_HEADER + 4)
#define XCP_PACKET_BYTE5                        (XCP_PACKET_HEADER + 5)
#define XCP_PACKET_BYTE6                        (XCP_PACKET_HEADER + 6)
#define XCP_PACKET_BYTE7                        (XCP_PACKET_HEADER + 7)

#define XCP_CAN_MAX_DLC                         (8)

#define XCP_RESERVED_BYTE                       ((uint8)0x00U)


#define XCP_ERR_RES_BASIC_LENGTH                (2)
#define XCP_NORMAL_POSLEN                       (1)

#define XCP_PRO_HANDLE_INVALID                 (255)
#define XCP_PDUID_HANDLE_INVALID               ((PduIdType)(-1))

#define XCP_TRANSMIT_FLAG_IDLE                 (0)
#define XCP_TRANSMIT_FLAG_CMD                  (1)
#define XCP_TRANSMIT_FLAG_DAQ                  (2)

/* Tx PID Codes */
#define XCP_CMD_RES_CODE                        ((uint8)0xFFU)
#define XCP_CMD_ERROR_CODE                      ((uint8)0xFEU)
#define XCP_EVENT_CODE                          ((uint8)0xFDU)
/* Error Codes */
#define XCP_ERR_CMD_SYNCH                       ((uint8)0x00U)
#define XCP_ERR_CMD_BUSY                        ((uint8)0x10U)
#define XCP_ERR_DAQ_ACTIVE                      ((uint8)0x11U)
#define XCP_ERR_PGM_ACTIVE                      ((uint8)0x12U)
#define XCP_ERR_CMD_UNKNOWN                     ((uint8)0x20U)
#define XCP_ERR_CMD_SYNTAX                      ((uint8)0x21U)
#define XCP_ERR_OUT_OF_RANGE                    ((uint8)0x22U)
#define XCP_ERR_WRITE_PROTECTED                 ((uint8)0x23U)
#define XCP_ERR_ACCESS_DENIED                   ((uint8)0x24U)
#define XCP_ERR_ACCESS_LOCKED                   ((uint8)0x25U)
#define XCP_ERR_PAGE_NOT_VALID                  ((uint8)0x26U)
#define XCP_ERR_MODE_NOT_VALID                  ((uint8)0x27U)
#define XCP_ERR_SEGMENT_NOT_VALID               ((uint8)0x28U)
#define XCP_ERR_SEQUENCE                        ((uint8)0x29U)
#define XCP_ERR_DAQ_CONFIG                      ((uint8)0x2AU)
#define XCP_ERR_MEMORY_OVERFLOW                 ((uint8)0x30U)
#define XCP_ERR_GENERIC                         ((uint8)0x31U)
#define XCP_ERR_VERIFY                          ((uint8)0x32U)
#define XCP_ERR_RESOURCE_TEMPORARY_NOT_ACCESSIBLE   ((uint8)0x33U)
#define XCP_NO_ERR                              ((uint8)0xFFU)


/* Command Codes */
/* Standard Commands Handles */
#define XCP_CONNECT                             ((uint8)0xFFU)
#define XCP_DISCONNECT                          ((uint8)0xFEU)
#define XCP_GET_STATUS                          ((uint8)0xFDU)
#define XCP_SYNCH                               ((uint8)0xFCU)
#define XCP_GET_COMM_MODE_INFO                  ((uint8)0xFBU)
#define XCP_GET_ID                              ((uint8)0xFAU)
#define XCP_SET_REQUEST                         ((uint8)0xF9U)
#define XCP_GET_SEED                            ((uint8)0xF8U)
#define XCP_UNLOCK                              ((uint8)0xF7U)
#define XCP_SET_MTA                             ((uint8)0xF6U)
#define XCP_UPLOAD                              ((uint8)0xF5U)
#define XCP_SHORT_UPLOAD                        ((uint8)0xF4U)
#define XCP_BUILD_CHECKSUM                      ((uint8)0xF3U)
#define XCP_TRANSPORT_LAYER_CMD                 ((uint8)0xF2U)
#define XCP_USER_CMD                            ((uint8)0xF1U)
/* Calibration Commands */
#define XCP_DOWNLOAD                            ((uint8)0xF0U)
#define XCP_DOWNLOAD_NEXT                       ((uint8)0xEFU)
#define XCP_DOWNLOAD_MAX                        ((uint8)0xEEU)
#define XCP_SHORT_DOWNLOAD                      ((uint8)0xEDU)
#define XCP_MODIFY_BITS                         ((uint8)0xECU)
/* Page Switching Commands */
#define XCP_SET_CAL_PAGE                        ((uint8)0xEBU)
#define XCP_GET_CAL_PAGE                        ((uint8)0xEAU)
#define XCP_GET_PAG_PROCESSOR_INFO              ((uint8)0xE9U)
#define XCP_GET_SEGMENT_INFO                    ((uint8)0xE8U)
#define XCP_GET_PAGE_INFO                       ((uint8)0xE7U)
#define XCP_SET_SEGMENT_MODE                    ((uint8)0xE6U)
#define XCP_GET_SEGMENT_MODE                    ((uint8)0xE5U)
#define XCP_COPY_CAL_PAGE                       ((uint8)0xE4U)
/* DAQ Commands-Basics */
#define XCP_SET_DAQ_PTR                         ((uint8)0xE2U)
#define XCP_WRITE_DAQ                           ((uint8)0xE1U)
#define XCP_SET_DAQ_LIST_MODE                   ((uint8)0xE0U)
#define XCP_START_STOP_DAQ_LIST                 ((uint8)0xDEU)
#define XCP_START_STOP_SYNCH                    ((uint8)0xDDU)
#define XCP_WRITE_DAQ_MULTIPLE                  ((uint8)0xC7U)
#define XCP_READ_DAQ                            ((uint8)0xDBU)
#define XCP_GET_DAQ_CLOCK                       ((uint8)0xDCU)
#define XCP_GET_DAQ_PROCESSOR_INFO              ((uint8)0xDAU)
#define XCP_GET_DAQ_RESOLUTION_INFO             ((uint8)0xD9U)
#define XCP_GET_DAQ_LIST_MODE                   ((uint8)0xDFU)
#define XCP_GET_DAQ_EVENT_INFO                  ((uint8)0xD7U)
/* DAQ Commands-Static Configuration */
#define XCP_CLEAR_DAQ_LIST                      ((uint8)0xE3U)
#define XCP_GET_DAQ_LIST_INFO                   ((uint8)0xD8U)
/* DAQ Commands-Dynamic Configuration */
#define XCP_FREE_DAQ                            ((uint8)0xD6U)
#define XCP_ALLOC_DAQ                           ((uint8)0xD5U)
#define XCP_ALLOC_ODT                           ((uint8)0xD4U)
#define XCP_ALLOC_ODT_ENTRY                     ((uint8)0xD3U)
/* Programming Commands */
#define XCP_PROGRAM_START                       ((uint8)0xD2U)
#define XCP_PROGRAM_CLEAR                       ((uint8)0xD1U)
#define XCP_PROGRAM                             ((uint8)0xD0U)
#define XCP_PROGRAM_RESET                       ((uint8)0xCFU)
#define XCP_GET_PGM_PROCESSOR_INFO              ((uint8)0xCEU)
#define XCP_GET_SECTOR_INFO                     ((uint8)0xCDU)
#define XCP_PROGRAM_PREPARE                     ((uint8)0xCCU)
#define XCP_PROGRAM_FORMAT                      ((uint8)0xCBU)
#define XCP_PROGRAM_NEXT                        ((uint8)0xCAU)
#define XCP_PROGRAM_MAX                         ((uint8)0xC9U)
#define XCP_PROGRAM_VERIFY                      ((uint8)0xC8U)


/* ASYN job id */
#define XCP_NO_ASYN_JOB                         ((uint8)0x00U)
#define XCP_STORECALDATA_JOB                    ((uint8)0x01U)
#define XCP_BLOCK_UPLOAD_JOB                    ((uint8)0x02U)
#define XCP_PGM_CLEAR_JOB                       ((uint8)0x03U)
#define XCP_PGM_PROG_JOB                        ((uint8)0x04U)
#define XCP_PGM_VERIFY_JOB                      ((uint8)0x05U)
#define XCP_BUILDCS_JOB                         ((uint8)0x06U)
#define XCP_COPYPAGE_JOB                        ((uint8)0x07U)

/* Macro Definition Protected Source */
#define XCP_NO_PROTECTED                        ((uint8)0x00U)
#define XCP_CAL_PROTECTED                       ((uint8)0x01U)
#define XCP_DAQ_PROTECTED                       ((uint8)0x04U)
#define XCP_STIM_PROTECTED                      ((uint8)0x08U)
#define XCP_PGM_PROTECTED                       ((uint8)0x10U)

/*******************************************************************************
* PRQA S 3453 MISRA-C:2004 Rule 19.7
* A function could probably be used instead of this function-like macro.
* These function-like macros make code easy to read.
* This part of code is verified manually and has no impact.
*******************************************************************************/
/* Motorola format define */
#define Xcp_GetHighByte(x)                      Xcp_GetByteOf16Bits((x),TRUE)
#define Xcp_GetLowByte(x)                       Xcp_GetByteOf16Bits((x),FALSE)
#define Xcp_GetFirstByte(x)                     Xcp_GetByteOf32Bits((x),0)
#define Xcp_GetSecondByte(x)                    Xcp_GetByteOf32Bits((x),1)
#define Xcp_GetThirdByte(x)                     Xcp_GetByteOf32Bits((x),2)
#define Xcp_GetFourthByte(x)                    Xcp_GetByteOf32Bits((x),3)

#define Xcp_Get_Drive_Version(x,y)      ((uint8)(((x)<<4)|((y)&((uint8)0x0fU))))




/*Det Error*/
#if(STD_ON == XCP_DEV_ERROR_DETECT)

#define  XCP_DET_ERROR_DETECT(cond, ApiId, errcode)  \
    DET_ERROR_DETECT((cond), XCP_MODULE_ID, XCP_INSTANCE_ID,(ApiId),(errcode))

#define  XCP_DET_ERROR_DETECT_RET(cond, ApiId, errcode, ret) \
    DET_ERROR_DETECT_RET((cond), XCP_MODULE_ID,XCP_INSTANCE_ID,(ApiId),(errcode), (ret))

#define  XCP_DET_REPORT_ERROR(ApiId, errcode)  \
    DET_REPORT_ERROR(XCP_MODULE_ID, XCP_INSTANCE_ID, (ApiId), (errcode))

#else

#define  XCP_DET_ERROR_DETECT(cond, ApiId, errcode)
#define  XCP_DET_ERROR_DETECT_RET(cond, ApiId, errcode, ret)
#define  XCP_DET_REPORT_ERROR(ApiId, errcode)

#endif



#define XCP_E_INV_POINTER       ((uint8)0x1U)
#define XCP_E_NOT_INITIALIZED   ((uint8)0x2U)
#define XCP_E_INVALID_PDUID     ((uint8)0x3U)
#define XCP_E_INVALID_PDULEN    ((uint8)0x4U)
#define XCP_E_NULL_POINTER      ((uint8)0x12U)

/*XCP_E_INIT_FAILED not supported */


#define XCP_INIT_APIID          ((uint8)0x00U)
#define XCP_GETVERSION_APIID    ((uint8)0x01U)
#define XCP_MAIN_APIID          ((uint8)0x04U)
#define XCP_RXIND_APIID         ((uint8)0x03U)
#define XCP_TXCONF_APIID        ((uint8)0x02U)
#define XCP_TRIGGERTX_APIID     ((uint8)0x41U)
#define XCP_SETTXMODE_APIID     ((uint8)0x05U)


/*******************************************************************************
*   local Data Declare
*******************************************************************************/
#define XCP_START_SEC_VAR_INIT_8
#include "MemMap.h"
extern VAR(Std_InitStateType, XCP_VAR)Xcp_State;
#define XCP_STOP_SEC_VAR_INIT_8
#include "MemMap.h"

#define XCP_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"
extern P2CONST(Xcp_ConfigType, AUTOMATIC, XCP_CONST) XcpConfigInfoPtr;
extern VAR(PduInfoType, XCP_VAR_NOINIT) Xcp_TxPduInfo;
extern VAR(Xcp_LinkType, XCP_VAR_NOINIT) Xcp_ActiveLink;
#define XCP_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"

#define XCP_START_SEC_VAR_NOINIT_8
#include "MemMap.h"
extern VAR(uint8, XCP_VAR_NOINIT) Xcp_RxData[XCP_RX_BUFFER_SIZE];
extern VAR(uint8, XCP_VAR_NOINIT) Xcp_TxData[XCP_TX_BUFFER_SIZE];
extern VAR(uint8, XCP_VAR_NOINIT) Xcp_AsynJob;
extern VAR(boolean, XCP_VAR_NOINIT) Xcp_TransmitingFlag;
extern VAR(uint8, XCP_VAR_NOINIT) Xcp_ProtectMask;
extern VAR(Xcp_Status_Type, XCP_VAR_NOINIT) Xcp_Status;
/*******************************************************************************
* PRQA S 759 MISRA-C:2004 Rule 18.4
* Use union to fullfill xcp protocol and also union make the code easy to
* read and implement.
* This part of code is verified manually and has no impact.
*******************************************************************************/
extern VAR(Xcp_Current_Session_Status_Type, XCP_VAR_NOINIT) Xcp_SessionStatus;
extern VAR(uint8, XCP_VAR_NOINIT) Xcp_AddressExtension;
#define XCP_STOP_SEC_VAR_NOINIT_8
#include "MemMap.h"


#define XCP_START_SEC_VAR_NOINIT_16
#include "MemMap.h"
extern VAR(PduLengthType, XCP_VAR_NOINIT) Xcp_RxPduLength;
#define XCP_STOP_SEC_VAR_NOINIT_16
#include "MemMap.h"


#define XCP_START_SEC_VAR_NOINIT_32
#include "MemMap.h"
extern VAR(uint32, XCP_VAR_NOINIT) Xcp_MTA;
#define XCP_STOP_SEC_VAR_NOINIT_32
#include "MemMap.h"




/*******************************************************************************
*   config Data Declare
*******************************************************************************/
#define XCP_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"

extern CONST(Xcp_ConfigType, XCP_CONST) Xcp_Config[XCP_CONFIG_NUM];
extern CONST(Xcp_TpProConfigType, XCP_CONST) Xcp_TpProConfig[XCP_NUMBER_OF_SUPPORTED_PRO];

#define XCP_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"

/*******************************************************************************
*   Internal Function Declare
*******************************************************************************/
#define XCP_START_SEC_CODE
#include "MemMap.h"

extern FUNC(void, XCP_CODE) Xcp_RxIndication(void);
extern FUNC(void, XCP_CODE) Xcp_TxConfirmation(void);

extern FUNC(void, XCP_CODE) Xcp_InternalProcessing(void);
extern FUNC(void, XCP_CODE) Xcp_ProcessInit(void);
extern FUNC(void, XCP_CODE) Xcp_PreReset(void);
extern FUNC(void, XCP_CODE) Xcp_PostReset(void);
extern FUNC(void, XCP_CODE) Xcp_Reset(void);
extern FUNC(void, XCP_CODE) Xcp_CreatErrResponse
(
    const uint8 ErrorCode
);

extern FUNC(void, XCP_CODE) Xcp_Transmit(void);

extern FUNC(uint32, XCP_CODE) Xcp_Make32Bits
(
    const uint8 byte0,
    const uint8 byte1,
    const uint8 byte2,
    const uint8 byte3
);
extern FUNC(uint16, XCP_CODE) Xcp_Make16Bits
(
    const uint8 byte0,
    const uint8 byte1
);

extern FUNC(uint8, XCP_CODE) Xcp_GetByteOf16Bits
(
    const uint16 value,
    const boolean highByte
);

extern FUNC(uint8, XCP_CODE) Xcp_GetByteOf32Bits
(
    const uint32 value,
    const uint8 index
);



#if((STD_ON == XCP_REQ_STORECALDATA_ASYN_SUPPORT) \
  ||(STD_ON == XCP_PGM_ASYN_SUPPORT)    \
  ||(STD_ON == XCP_BUILDCS_ASYN_SUPPORT) \
  ||(STD_ON == XCP_COPYPAG_ASYN_SUPPORT))
extern FUNC(void, XCP_CODE) Xcp_AsynJobEndNotification(void);
extern FUNC(void, XCP_CODE) Xcp_AsynErrorNotification
(
    const uint8 errcode
);
#endif

#define XCP_STOP_SEC_CODE
#include "MemMap.h"


#endif

