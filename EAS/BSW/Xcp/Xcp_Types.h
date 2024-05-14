/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
*   File Name       : Xcp_Types.h
********************************************************************************
*   Project/Product : AUTOSAR 4.2
*   Title           : Xcp_Types module head File
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
#ifndef XCP_TYPE_H
#define XCP_TYPE_H

/*******************************************************************************
*   Includes
*******************************************************************************/
#include "ComStack_Types.h"
#include "Xcp_Cfg.h"
#include "Xcp_Std_Cfg.h"
#include "Xcp_Cal_Cfg.h"
#include "Xcp_Daq_Cfg.h"
#include "Xcp_Pag_Cfg.h"
#include "Xcp_Pgm_Cfg.h"
#if(STD_ON == XCP_DEV_ERROR_DETECT)
#include "Det.h"
#endif
#include "Xcp_Version.h"
#include "SchM_Xcp.h"

/*******************************************************************************
*   macro define
*******************************************************************************/

/* Asyn job command return code */
#define XCP_ASYN_JOB_OK          E_OK
#define XCP_ASYN_JOB_NOT_OK      E_NOT_OK
#define XCP_ASYN_JOB_PENDING    (2)


/*******************************************************************************
*   Typedefs
*******************************************************************************/
/* AUTOSAR Standard PDU ConfigType*/
typedef struct
{
    PduIdType XcpTxPduId;
    uint8     XcpTpType;/*OnCan OnEth.*/
} Xcp_PduType;


typedef struct
{
    uint8 XcpTpHandle;
    PduIdType XcpRxPduId;
    PduIdType XcpTxPduId;
    PduIdType XcpTxConfirmationPduId;
} Xcp_LinkType;


typedef struct
{
    uint8 NumOfConnections;
    P2CONST (Xcp_PduType, TYPEDEF, XCP_CONST) Connections;
} Xcp_ConfigType;

typedef Std_ReturnType (*XcpTxFunctionNameDef)
(CONSTP2VAR (PduInfoType, TYPEDEF, XCP_VAR_NOINIT) pduInfo);
typedef struct
{
    uint8  MaxCto;
    uint8  MaxCtoPGM;
    uint16 MaxDto;
    uint8  Header;
    uint8  Tail;
    XcpTxFunctionNameDef TpTxFunc;
} Xcp_TpProConfigType;


/* Structure Definition */
typedef void (*XcpFunctionNameDef) (void);

typedef struct
{
    uint8 CmdSwitch;
    XcpFunctionNameDef XCPCmdFunc;
    uint8 MinPacketLength;
    uint8 ProtectRes;
} Xcp_ServiceInfoType;

/* XCP Connect Status */
typedef enum
{
    XCP_STATUS_DISCONNECTED,
    XCP_STATUS_CONNECTED,
    XCP_STATUS_RESUME
} Xcp_Status_Type;


typedef struct
{
    uint8  XcpEventProperties;
    uint8  XcpEventChannelMaxDaqList;
    uint8  XcpEventChannelPriority;
    uint8  XcpEventTimeCycle; /* unit is xcp main cycle*/
    P2CONST (uint16, TYPEDEF, XCP_CONST) XcpEventChannelTriggeredDaqListRef;
    uint8  XcpEventNameInBytes;
    P2CONST (uint8, TYPEDEF, XCP_CONST) XcpEventName;
} Xcp_Event_Config_Type;

typedef struct
{
    uint32  XcpOdtEntryAddress;
    uint8   XcpOdtEntryLength;
    uint8   XcpOdtEntryAddressExt;
    uint8   XcpOdtEntryBitOffset;
} Xcp_OdtEntry_Type;

typedef struct
{
    uint8  XcpDtoPid;
    CONSTP2VAR (Xcp_OdtEntry_Type, TYPEDEF, XCP_PRIVATE_DATA)  XcpOdtEntry;
} Xcp_ODT_Config_Type;

typedef struct
{
    uint16 XcpRelateEvent;
    uint8  XcpDaqProperties;
    uint8  XcpMaxOdt;
    /* in same tp, all ODT has same entrynum
       but in different tp , ODT entrynum may be different
    */
    uint8  XcpMaxOdtEntries;
    P2CONST (Xcp_ODT_Config_Type, TYPEDEF, XCP_CONST)  XcpOdt;
} Xcp_DAQ_Config_Type;

/* XCP DAQ Pionter Type */
typedef struct
{
    uint16 DaqIndex;
    uint8 OdtIndex;
    uint8 OdtEntryIndex;
} Xcp_DAQ_Ptr_Type;

typedef enum
{
    XCP_DAQ_STOP,      /* DAQ is not started */
    XCP_DAQ_WAIT_EVENT,/* DAQ is started, but not actived by event */
    XCP_DAQ_PENDING   /* DAQ is started, and actived by event, but not transmiting as priority is not the highest */
    /* XCP_DAQ_BUSY,       //DAQ is started, and actived by event, and transmiting as priority is  highest */
    /* XCP_DAQ_WAITING,    //DAQ is started, and actived by event, but interrupted by higher priority daq, it will retransmit after high priority daq is transmited */
} Xcp_DaqSubState_Type;



/*******************************************************************************
*   XCP Status Bits Unions
*******************************************************************************/
/*
  here suggest bitorder = byteorder
*/

/*******************************************************************************
* PRQA S 635 750 3131
* union and bitfield is used here to make code easy to read and easy to
* add extra function later
* This part of code is verified manually and has no impact.
*******************************************************************************/

typedef union
{
    uint8 Byte;
    struct
    {
#if(XCP_LSB_FIRST == XCP_BIT_ORDER)
        uint8 STORE_CAL_REQ             : 1;
        uint8 BlankDat1                 : 1;
        uint8 STORE_DAQ_REQ             : 1;
        uint8 CLEAR_DAQ_REQ             : 1;
        uint8 BlankDat2                 : 2;
        uint8 DAQ_RUNNING               : 1;
        uint8 RESUME                    : 1;
#else
        uint8 RESUME                    : 1;
        uint8 DAQ_RUNNING               : 1;
        uint8 BlankDat2                 : 2;
        uint8 CLEAR_DAQ_REQ             : 1;
        uint8 STORE_DAQ_REQ             : 1;
        uint8 BlankDat1                 : 1;
        uint8 STORE_CAL_REQ             : 1;
#endif
    } Bit;
} Xcp_Current_Session_Status_Type;

/* Current Mode parameter in GET_DAQ_LIST_MODE */
typedef union
{
    uint8 Byte;
    struct
    {
#if(XCP_LSB_FIRST == XCP_BIT_ORDER)
        uint8 SELECTED                  : 1;
        uint8 DIRECTION                 : 1;
        uint8 BlankDat1                 : 2;
        uint8 TIMESTAMP                 : 1;
        uint8 PID_OFF                   : 1;
        uint8 RUNNING                   : 1;
        uint8 RESUME                    : 1;

#else
        uint8 RESUME                    : 1;
        uint8 RUNNING                   : 1;
        uint8 PID_OFF                   : 1;
        uint8 TIMESTAMP                 : 1;
        uint8 BlankDat1                 : 2;
        uint8 DIRECTION                 : 1;
        uint8 SELECTED                  : 1;
#endif
    } Bit;
} Xcp_Daq_Mode_Type;



/*******************************************************************************
*   Memory types
*******************************************************************************/
/* Sector Info */
typedef struct
{
    uint32 Start_Address;
    uint32 Sector_Length;
} Xcp_Sector_Info_Type;

typedef struct
{
    uint32 Source_Address;
    uint32 Map_Length;
} Xcp_Info_of_SegmentMapping_Type;

typedef struct
{
    uint8 Page_Property;
    uint8 Init_Segment;
} Xcp_Info_of_Page_Type;

typedef struct
{
    uint8 Number_of_Pages;
    uint8 Number_of_Mapping;
    uint32 Basic_Address;
    uint32 Segment_Length;
    uint8 Address_Extension;
    uint8 Compression_method;
    uint8 Encryption_method;
    P2CONST (Xcp_Info_of_SegmentMapping_Type, TYPEDEF, XCP_CONST)  MapInfo;
    P2CONST (Xcp_Info_of_Page_Type, TYPEDEF, XCP_CONST)  PageInfo;
} Xcp_Info_of_Segment_Type;




#endif

