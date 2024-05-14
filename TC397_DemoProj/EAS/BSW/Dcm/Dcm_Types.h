/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
*   File Name       : Dcm_Types.h
********************************************************************************
*   Project/Product : AUTOSAR 4.2
*   Title           : Dcm module head File
*   Author          : Hirain
********************************************************************************
*   Description: Main source file of the AUTOSAR Diagnositc communcation manager,
*               according to AUTOSAR_SWS_DiagnosticCommunicationManager.pdf
*               (Release 4.2) and ISO14229-1(2013).pdf.
*
********************************************************************************
*   Limitations: None
*
********************************************************************************
*
********************************************************************************
*   Revision History:
*   Reference to Core C File
********************************************************************************
* END_FILE_HDR*/

#ifndef DCM_TYPES_H
#define DCM_TYPES_H

/*******************************************************************************
* Include files
*******************************************************************************/
/*SWS_Dcm_00683*/
#include "Rte_Dcm_Type.h"
#include "ComStack_Types.h"
#include "Dcm_Cfg.h"

#ifndef DCM_UDS_34_SERVICE
#define DCM_UDS_34_SERVICE    STD_OFF
#endif

#ifndef DCM_UDS_35_SERVICE
#define DCM_UDS_35_SERVICE    STD_OFF
#endif

#ifndef DCM_UDS_36_SERVICE
#define DCM_UDS_36_SERVICE    STD_OFF
#endif

#ifndef DCM_UDS_37_SERVICE
#define DCM_UDS_37_SERVICE    STD_OFF
#endif
/*******************************************************************************
* Typedef
*******************************************************************************/
/*Car platform types*/
#define DCM_NO_PLATFORM        0U
#define DCM_GAC_PLATFORM       1U
#define DCM_HYUNDAI_PLATFORM   2U
#define DCM_GEELY_PLATFORM     3U
#define DCM_RNDS_PLATFORM      4U
#define DCM_NISSAN_PLATFORM    5U
#define DCM_FAW_PLATFORM       6U

typedef uint16 Dcm_SecRefType;
typedef uint16 Dcm_SesRefType;
/*UDS service ID*/
#define DCM_10_SERVICE   0x10U
#define DCM_11_SERVICE   0x11U
#define DCM_14_SERVICE   0x14U
#define DCM_19_SERVICE   0x19U
#define DCM_22_SERVICE   0x22U
#define DCM_23_SERVICE   0x23U
#define DCM_24_SERVICE   0x24U
#define DCM_27_SERVICE   0x27U
#define DCM_28_SERVICE   0x28U
#define DCM_2A_SERVICE   0x2AU
#define DCM_2C_SERVICE   0x2CU
#define DCM_2E_SERVICE   0x2EU
#define DCM_2F_SERVICE   0x2FU
#define DCM_31_SERVICE   0x31U
#define DCM_34_SERVICE   0x34U
#define DCM_35_SERVICE   0x35U
#define DCM_36_SERVICE   0x36U
#define DCM_37_SERVICE   0x37U
#define DCM_38_SERVICE   0x38U
#define DCM_3D_SERVICE   0x3DU
#define DCM_3E_SERVICE   0x3EU
#define DCM_83_SERVICE   0x83U
#define DCM_84_SERVICE   0x84U
#define DCM_85_SERVICE   0x85U
#define DCM_86_SERVICE   0x86U
#define DCM_87_SERVICE   0x87U
/*OBD service ID*/
#define DCM_01_SERVICE   0x01U
#define DCM_02_SERVICE   0x02U
#define DCM_03_SERVICE   0x03U
#define DCM_04_SERVICE   0x04U
#define DCM_05_SERVICE   0x05U
#define DCM_06_SERVICE   0x06U
#define DCM_07_SERVICE   0x07U
#define DCM_08_SERVICE   0x08U
#define DCM_09_SERVICE   0x09U
#define DCM_0A_SERVICE   0x0AU

/*Dcm return type*/
/*SWS_Dcm_00690*/
#define DCM_E_PENDING               ((Std_ReturnType)10)/*0xA*/
#define DCM_E_FORCE_RCRRP           ((Std_ReturnType)12)/*0xC*/
/*SWS_Dcm_00685*/
#define DCM_E_COMPARE_KEY_FAILED    ((Std_ReturnType)11)
/*SWS_Dcm_00694*/
#define DCM_E_REQUEST_NOT_ACCEPTED  ((Std_ReturnType)8)

#if(DCM_COMM_SUPPORT == STD_ON)
/*Dcm_ComM_ModeType */
typedef uint8 Dcm_ComM_ModeType;
#define DCM_COMM_NOCOM              (uint8)0
#define DCM_COMM_SILENTCOM          (uint8)1
#define DCM_COMM_FULLCOM            (uint8)2
#endif


/*Dcm module state*/
typedef uint16 Dcm_StateType;
#define DCM_IDLE                    ((Dcm_StateType)0x0000)
/*#define DCM_RXBUSY                  ((Dcm_StateType)0x0001)*/
#define DCM_PROCESSING              ((Dcm_StateType)0x0002)
#define DCM_PROCESSING_DONE         ((Dcm_StateType)0x0004)
#define DCM_RCRRP                   ((Dcm_StateType)0x0008)
#define DCM_RCRRP_FORCE             ((Dcm_StateType)0x0010)
#define DCM_RCRRP_FORCE_OK          ((Dcm_StateType)0x0020)
#define DCM_PERIODIC_TX             ((Dcm_StateType)0x0040)
#define DCM_RCRRP_REPEATTX          ((Dcm_StateType)0x0080)


#define DCM_FNC_INVALID_INDEX       ((uint16)0xFFFF)

/*ECUC_Dcm_00713*/
typedef enum
{
    DCM_USE_BLOCK_ID                          = 0U,
    DCM_USE_DATA_ASYNCH_CLIENT_SERVER         = 1U,
    DCM_USE_DATA_ASYNCH_CLIENT_SERVER_ERROR   = 2U,
    DCM_USE_DATA_ASYNCH_FNC                   = 3U,
    DCM_USE_DATA_ASYNCH_FNC_ERROR             = 4U,
    DCM_USE_DATA_SENDER_RECEIVER              = 5U,
    DCM_USE_DATA_SENDER_RECEIVER_AS_SERVICE   = 6U,
    DCM_USE_DATA_SYNCH_CLIENT_SERVER          = 7U,
    DCM_USE_DATA_SYNCH_FNC                    = 8U,
    DCM_USE_ECU_SIGNAL                        = 9U
} Dcm_DspDataUsePortType;


/*SWS_Dcm_00985*/
typedef uint8 Dcm_ReturnReadMemoryType;
#define DCM_READ_OK            ((uint8)0x00)
#define DCM_READ_PENDIN        ((uint8)0x01)
#define DCM_READ_FAILED        ((uint8)0x02)
#define DCM_READ_FORCE_RCRRP   ((uint8)0x03)


/*SWS_Dcm_00986*/
typedef uint8 Dcm_ReturnWriteMemoryType;
#define DCM_WRITE_OK           ((uint8)0x00)
#define DCM_WRITE_PENDIN       ((uint8)0x01)
#define DCM_WRITE_FAILED       ((uint8)0x02)
#define DCM_WRITE_FORCE_RCRRP  ((uint8)0x03)


/*SWS_Dcm_00987*/
typedef uint8 Dcm_EcuStartModeType;
#define DCM_COLD_START         ((uint8)0x00)
#define DCM_WARM_START         ((uint8)0x01)

/*SWS_Dcm_00988*/
typedef struct
{
    uint16  TesterSourceAddr;
    uint8   ProtocolId;
    uint8   Sid;
    uint8   SubFncId;
    boolean ReprogramingRequest;
    boolean ApplUpdated;
    boolean ResponseRequired;
} Dcm_ProgConditionsType;


/*SWS_Dcm_00989*/
typedef uint8 Dcm_MsgItemType;
/*SWS_Dcm_00990*/
typedef P2VAR(Dcm_MsgItemType, TYPEDEF, DCM_VAR_NOINIT) Dcm_MsgType;
/*SWS_Dcm_00991*/
typedef uint32 Dcm_MsgLenType;


/*SWS_Dcm_00992*/
typedef uint8 Dcm_BitType;
typedef struct
{
    /* 0: physical request
       1: functional request*/
    Dcm_BitType reqType               : 1;
    /* 0: do not suppress
       1: no positive response will be sent */
    Dcm_BitType suppressPosResponse   : 1;
} Dcm_MsgAddInfoType;


typedef enum
{
    DCM_PHYSICAL_TYPE     = 0U,
    DCM_FUNCTIONAL_TYPE   = 1U
} Dcm_RequestAddrseeType;


#define DCM_REQ_PHY_MASK  ((uint8)0x01)
#define DCM_REQ_FUN_MASK  ((uint8)0x02)


/*SWS_Dcm_00993*/
typedef uint8 Dcm_IdContextType;
/*SWS_Dcm_00994*/
typedef struct
{
    Dcm_MsgType        reqData;
    Dcm_MsgLenType     reqDataLen;
    Dcm_MsgType        resData;
    Dcm_MsgLenType     resDataLen;
    Dcm_MsgLenType     CopyDataIndex;
    Dcm_MsgAddInfoType msgAddInfo;
    Dcm_MsgLenType     resMaxDataLen;
    Dcm_IdContextType  idContext;
    PduIdType          RxPduId;
} Dcm_MsgContextType;


/*SWS_Dcm_01138*/
typedef uint8 Dcm_DidSupportedType;
#define DCM_DID_SUPPORTED      (uint8)0x00
#define DCM_DID_NOT_SUPPORTED  (uint8)0x01

/*******************************************************************************
* for Dsd SubModule
*******************************************************************************/
typedef P2FUNC(Std_ReturnType, DCM_CODE, EcucFunctionServiceFncDef)
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
);

/*ECUC_Dcm_00802*/
typedef struct
{
    /*ECUC_Dcm_00803*/
    uint8 DcmDsdSubServiceId;
    /*ECUC_Dcm_01047*/
    boolean DcmDsdSubServiceUsed;
    uint8 DcmDsdSubServiceSupportAddress;
    /*ECUC_Dcm_00812*/
#if(STD_ON == DCM_UDS_27_SERVICE)
    Dcm_SecRefType DcmDsdSubServiceSecurityLevelRef;
#endif
    /*ECUC_Dcm_00804*/
    Dcm_SesRefType DcmDsdSubServiceSessionLevelRef;
    /*ECUC_Dcm_00924*/
    //DcmDsdSubServiceModeRuleRef;
    /*ECUC_Dcm_00942*/
    EcucFunctionServiceFncDef DcmDsdSubServiceFnc;
} Dcm_DsdSubServiceType;

/*ECUC_Dcm_00689*//*ECUC_Dcm_00732*/
typedef struct
{
    /*ECUC_Dcm_00735*//*constr_6047*/
    uint8 DcmDsdSidTabServiceId; /*0..255*/
    /*ECUC_Dcm_01044*/
    boolean DcmDsdServiceUsed;
    uint8 DcmDsdServiceSupportAddress;
    uint16 DcmDsdServiceMinLength;
    /*ECUC_Dcm_00777*/
    EcucFunctionServiceFncDef DcmDsdSidTabFnc;
    /*ECUC_Dcm_00737*/
    boolean DcmDsdSidTabSubfuncAvail;
    /*ECUC_Dcm_00733*/
#if(STD_ON == DCM_UDS_27_SERVICE)
    Dcm_SecRefType DcmDsdSidTabSecurityLevelRef;
#endif
    /*ECUC_Dcm_00734*/
    Dcm_SesRefType DcmDsdSidTabSessionLevelRef;
    /*ECUC_Dcm_00918*/
    //DcmDsdSidTabModeRuleRef;
    uint8 NumOfSubService;
    const Dcm_DsdSubServiceType *DcmDsdSubService;
#if(DCM_CAR_PLATFORM == DCM_GEELY_PLATFORM)
    uint32 P4ServerMax;
#endif
} Dcm_DsdServiceType;

/*ECUC_Dcm_00732*/
typedef struct
{
    /*ECUC_Dcm_00736*/
    uint8 DcmDsdSidTabId;/*0..255*/
    /*ECUC_Dcm_00689*/
    uint8 NumOfService;
    const Dcm_DsdServiceType *DcmDsdService;
} Dcm_DsdServiceTableType;




/*******************************************************************************
* for Dsl SubModule
*******************************************************************************/
/*ECUC_Dcm_00739*/
typedef struct
{
    /*ECUC_Dcm_00738*/
    uint32 DcmDslBufferSize; /*8..0xFFFFFFFE(4294967294)*/
    uint8 *DataPtr;
} Dcm_DslBufferType;

/*ECUC_Dcm_00691*/
typedef struct
{
    /*ECUC_Dcm_00693*/
    uint8 DcmDslDiagRespMaxNumRespPend; /*0..255*/
    /*ECUC_Dcm_00914*/
    boolean DcmDslDiagRespOnSecondDeclinedRequest;
} Dcm_DslDiagRespType;


typedef enum
{
    DCM_TYPE1 = 0U,
    DCM_TYPE2 = 1U
} Dcm_DslProtocolTransType;


/*ECUC_Dcm_00709*/
typedef struct
{
    /*ECUC_Dcm_00710*/
    Dcm_RequestAddrseeType DcmDslProtocolRxAddrType;
    /*ECUC_Dcm_00687*/
    uint16 DcmDslProtocolRxPduId;/*0..65535*/
    /*ECUC_Dcm_00770*/
    PduIdType DcmDslProtocolRxPduRef;
} Dcm_DslProtocolRxType;

/*ECUC_Dcm_00711*/
typedef struct
{
    /*ECUC_Dcm_00864*/
    uint16 DcmDslTxConfirmationPduId;
    /*ECUC_Dcm_00772*/
    PduIdType DcmDslProtocolTxPduRef;
} Dcm_DslProtocolTxType;


/*ECUC_Dcm_00897*/
typedef struct
{
    /*ECUC_Dcm_00862*/
    uint16 DcmDslPeriodicTxConfirmationPduId;
    /*ECUC_Dcm_00742*/
    PduIdType DcmDslPeriodicTxPduRef;
} Dcm_DslPeriodicConnectionType;


/*ECUC_Dcm_00741*/
typedef struct
{
    uint16 NumOfPeriodicConnection;
    const Dcm_DslPeriodicConnectionType *DcmDslPeriodicConnection;
} Dcm_DslPeriodicTransmissionType;

/*ECUC_Dcm_00706*/
typedef struct
{
    /*ECUC_Dcm_00826*/
    uint16 DcmDslProtocolRxTesterSourceAddr;/*0..65535*/
    /*ECUC_Dcm_00707*/
    //DcmDslPeriodicTransmissionConRef;
    /*ECUC_Dcm_00952*/
    uint8 DcmDslProtocolComMChannelRef;
    /*ECUC_Dcm_00708*/
    //DcmDslROEConnectionRef;
    uint16 NumOfRxPdu;/*1..**/
    const Dcm_DslProtocolRxType *DcmDslProtocolRx;
    const Dcm_DslProtocolTxType *DcmDslProtocolTx;
} Dcm_DslMainConnectionType;

/*ECUC_Dcm_00705*/
typedef struct
{
    const Dcm_DslMainConnectionType *DcmDslMainConnection;
    const Dcm_DslPeriodicTransmissionType *DcmDslPeriodicTransmission;
    //Dcm_DslResponseOnEventType *DcmDslResponseOnEvent;
} Dcm_DslConnectionType;

/*ECUC_Dcm_00694*//*ECUC_Dcm_00695*/
typedef struct
{
    /*ECUC_Dcm_00696*/
    Dcm_ProtocolType DcmDslProtocolID;
    /*ECUC_Dcm_01020*/
    uint16 DcmDslProtocolMaximumResponseSize; /*1 .. 65535,default value 4095*/
    /*ECUC_Dcm_00698*/
    uint16 DcmDslProtocolPreemptTimeout; /*0 .. 1s*/
    /*ECUC_Dcm_00699 Lower numeric values represent higher protocol priority*/
    uint8 DcmDslProtocolPriority; /*0 .. 255*/
    /*ECUC_Dcm_01043:Allows to activate or deactivate the usage of a Protocol.
    This parameter can be used for multi-purpose ECUs.*/
    boolean DcmDslProtocolRowUsed;
    /*ECUC_Dcm_00700*/
    Dcm_DslProtocolTransType DcmDslProtocolTransType; /*TYPE1 or TYPE2*/
    /*ECUC_Dcm_00910*/
    boolean DcmSendRespPendOnTransToBoot;
    /*ECUC_Dcm_00729*/
    uint16 DcmTimStrP2ServerAdjust; /*0 .. 1s,must be a multiple of DcmTaskTime*/
    /*ECUC_Dcm_00728*/
    uint16 DcmTimStrP2StarServerAdjust; /*0 .. 5s,must be a multiple of DcmTaskTime*/
    /*ECUC_Dcm_00701*/
    Dcm_DslBufferType DcmDslProtocolRxBufferRef;
    /*ECUC_Dcm_00704*/
    Dcm_DslBufferType DcmDslProtocolTxBufferRef;
    /*ECUC_Dcm_00702*/
    const Dcm_DsdServiceTableType *DcmDslProtocolSIDTable;
    uint8 NumOfConnection;
    const Dcm_DslConnectionType *DcmDslConnection;/*1..**/
    uint32 S3Server;
} Dcm_DslProtocolRowType;


/*******************************************************************************
* for Dsp SubModule
*******************************************************************************/
typedef enum
{
    DCM_OPAQUE        = 0U,
    DCM_BIG_ENDIAN    = 1U,
    DCM_LITTLE_ENDIAN = 2U,
} Dcm_DataEndiannessType;

typedef enum
{
    DCM_BOOLEAN   = 0U,
    DCM_SINT16    = 1U,
    DCM_SINT16_N  = 2U,
    DCM_SINT32    = 3U,
    DCM_SINT32_N  = 4U,
    DCM_SINT8     = 5U,
    DCM_SINT8_N   = 6U,
    DCM_UINT16    = 7U,
    DCM_UINT16_N  = 8U,
    DCM_UINT32    = 9U,
    DCM_UINT32_N  = 10U,
    DCM_UINT8     = 11U,
    DCM_UINT8_DYN = 12U,
    DCM_UINT8_N   = 13U,
    DCM_VARIABLE_LENGTH  = 14U
} Dcm_DataType;


/*ECUC_Dcm_01039*/
typedef enum
{
    DCM_AFTER_RESET  = 0U,
    DCM_BEFORE_RESET = 1U
} Dcm_ResponseToEcuResetType;

#if(DCM_CONFIG_VARIANTS == STD_CONFIG_VARIANTS_LINKTIME)
/*ECUC_Dcm_00712*/
typedef struct
{
    /*ECUC_Dcm_00966*/
    boolean DcmDspDDDIDcheckPerSourceDID;
    /*ECUC_Dcm_00987*/
    Dcm_DataEndiannessType DcmDspDataDefaultEndianness;
    /*ECUC_Dcm_01061*/
    boolean DcmDspEnableObdMirror;
    /*ECUC_Dcm_00638*/
    uint16 DcmDspMaxDidToRead;/*1..65535*/
    /*ECUC_Dcm_00818*/
    uint8 DcmDspPowerDownTime;/*valid:00-FE,unit:s*/
    /*ECUC_Dcm_01039*/
    Dcm_ResponseToEcuResetType DcmResponseToEcuReset;
#if(DCM_UDS_2A_SERVICE == STD_ON)
    /*ECUC_Dcm_00956*/
    uint16 DcmDspMaxPeriodicDidToRead;/*1..65535*/
    /*ECUC_Dcm_00962,DcmDspMaxPeriodicDidScheduler*/
    uint8 DcmDspMaxPeriodicDidScheduler;/*1..255*/
#endif
} Dcm_DspGeneralType;
#endif


/*******************************************************************************
* for UDS 10 Service
*******************************************************************************/
/*ECUC_Dcm_00815*/
typedef enum
{
    DCM_NO_BOOT = 0,
    DCM_OEM_BOOT,
    DCM_OEM_BOOT_RESPAPP,
    DCM_SYS_BOOT,
    DCM_SYS_BOOT_RESPAPP
} Dcm_DspSessionForBootType;

/*ECUC_Dcm_00767*/
typedef struct
{
    /*ECUC_Dcm_00815*/
    Dcm_DspSessionForBootType DcmDspSessionBoot;
    /*ECUC_Dcm_00765 subFunction value of the DiagnosticSession*/
    Dcm_SesCtrlType DcmDspSessionLevel;
    uint16 DcmDspSessionMask;
    /*ECUC_Dcm_00766*/
    uint16 DcmDspSessionP2ServerMax;/*unit:ms*/
    /*ECUC_Dcm_00768*/
    uint16 DcmDspSessionP2StarServerMax;/*unit:10ms*/
} Dcm_DspSessionRowType;

/*ECUC_Dcm_00769*/
typedef struct
{
    uint8 NumOfSessionRow;
    const Dcm_DspSessionRowType *DcmDspSessionRow;
} Dcm_DspSessionType;

/*******************************************************************************
* for UDS 11 Service
*******************************************************************************/
#define DCM_HARD_RESET        ((uint8)0x01)
#define DCM_KEYOFFON_RESET    ((uint8)0x02)
#define DCM_SOFT_RESET        ((uint8)0x03)



/*******************************************************************************
* for UDS 14 Service
*******************************************************************************/
/*no definition*/



/*******************************************************************************
* for UDS 19 Service
*******************************************************************************/
#define Dcm_reportNumberOfDTCByStatusMask                     ((uint8)0x01)
#define Dcm_reportDTCByStatusMask                             ((uint8)0x02)
#define Dcm_reportDTCSnapshotIdentification                   ((uint8)0x03)
#define Dcm_reportDTCSnapshotRecordByDTCNumber                ((uint8)0x04)
#define Dcm_reportDTCExtDataRecordByDTCNumber                 ((uint8)0x06)
#define Dcm_reportSupportedDTC                                ((uint8)0x0A)
#define Dcm_reportFirstTestFailedDTC                          ((uint8)0x0B)
#define Dcm_reportFirstConfirmedDTC                           ((uint8)0x0C)
#define Dcm_reportMostRecentTestFailedDTC                     ((uint8)0x0D)
#define Dcm_reportMostRecentConfirmedDTC                      ((uint8)0x0E)
#define Dcm_reportMirrorMemoryDTCByStatusMask                 ((uint8)0x0F)
#define Dcm_reportMirrorMemoryDTCExtDataRecordByDTCNumber     ((uint8)0x10)
#define Dcm_reportNumberOfMirrorMemoryDTCByStatusMask         ((uint8)0x11)
#define Dcm_reportNumberOfEmissionsRelatedOBDDTCByStatusMask  ((uint8)0x12)
#define Dcm_reportDTCFaultDetectionCounter                    ((uint8)0x14)
#define Dcm_reportDTCWithPermanentStatus                      ((uint8)0x15)


/*******************************************************************************
* for UDS 22 Service
*******************************************************************************/
#define DCM_INVALID_DID   (0xFFFFU)


/*******************************************************************************
* for UDS 23 Service
*******************************************************************************/
/*******************************************************************************
* for UDS 3D Service
*******************************************************************************/
/*******************************************************************************
* for UDS 34 Service
*******************************************************************************/
/*******************************************************************************
* for UDS 35 Service
*******************************************************************************/
#if((DCM_UDS_23_SERVICE == STD_ON)||(DCM_UDS_3D_SERVICE == STD_ON) \
    || (DCM_UDS_34_SERVICE == STD_ON)||(DCM_UDS_35_SERVICE == STD_ON))

#define DCM_INVALID_MEMORY_ID   (0xFFU)

/*ECUC_Dcm_00963*/
typedef struct
{
    uint8 NumOfFormat;/*0..255*/
    const uint8 *DcmDspSupportedAddressAndLengthFormatIdentifier;
} Dcm_DspAddressAndLengthFormatIdentifierType;

#if((DCM_UDS_23_SERVICE == STD_ON)||(DCM_UDS_35_SERVICE == STD_ON))
/*ECUC_Dcm_00785*/
typedef struct
{
    /*ECUC_Dcm_00787*/
    uint32 DcmDspReadMemoryRangeHigh;/*0..4294967294(0xFFFF FFFE)*/
    /*ECUC_Dcm_00786*/
    uint32 DcmDspReadMemoryRangeLow;/*0..4294967294(0xFFFF FFFE)*/
    /*ECUC_Dcm_00920*/
    //DcmDspReadMemoryRangeModeRuleRef;
#if(STD_ON == DCM_UDS_27_SERVICE)
    /*ECUC_Dcm_00788*/
    Dcm_SecRefType DcmDspReadMemoryRangeSecurityLevelRef;
#endif
    /*ECUC_Dcm_01086*/
    Dcm_SesRefType DcmDspReadMemoryRangeSessionLevelRef;
} Dcm_DspReadMemoryRangeInfoType;
#endif

#if((DCM_UDS_3D_SERVICE == STD_ON)||(DCM_UDS_34_SERVICE == STD_ON))
/*ECUC_Dcm_00789*/
typedef struct
{
    /*ECUC_Dcm_00791*/
    uint32 DcmDspWriteMemoryRangeHigh;/*0..4294967294(0xFFFF FFFE)*/
    /*ECUC_Dcm_00790*/
    uint32 DcmDspWriteMemoryRangeLow;/*0..4294967294(0xFFFF FFFE)*/
    /*ECUC_Dcm_00916*/
    //DcmDspWriteMemoryRangeModeRuleRef;
#if(STD_ON == DCM_UDS_27_SERVICE)
    /*ECUC_Dcm_00793*/
    Dcm_SecRefType DcmDspWriteMemoryRangeSecurityLevelRef;
#endif
    /*ECUC_Dcm_01076*/
    Dcm_SesRefType DcmDspWriteMemoryRangeSessionLevelRef;
} Dcm_DspWriteMemoryRangeInfoType;
#endif

/*ECUC_Dcm_00911*/
typedef struct
{
    /*ECUC_Dcm_00913*/
    uint8 DcmDspMemoryIdValue;/*0..255*/
#if((DCM_UDS_23_SERVICE == STD_ON)||(DCM_UDS_35_SERVICE == STD_ON))
    uint16 NumofReadMemory;
    const Dcm_DspReadMemoryRangeInfoType *DcmDspReadMemoryRangeInfo;
#endif
#if((DCM_UDS_3D_SERVICE == STD_ON)||(DCM_UDS_34_SERVICE == STD_ON))
    uint16 NumofWriteMemory;
    const Dcm_DspWriteMemoryRangeInfoType *DcmDspWriteMemoryRangeInfo;
#endif
} Dcm_DspMemoryIdInfoType;

/*ECUC_Dcm_00784*/
typedef struct
{
    Dcm_DspAddressAndLengthFormatIdentifierType DcmDspAddressAndLengthFormatIdentifier;
    uint8 NumOfMemoryId;
    const Dcm_DspMemoryIdInfoType *DcmDspMemoryIdInfo;
} Dcm_DspMemoryType;
#endif

/*******************************************************************************
* for UDS 24 Service
*******************************************************************************/




/*******************************************************************************
* for UDS 27 Service
*******************************************************************************/
/*ECUC_Dcm_00967*/
typedef enum
{
    DCM_USE_ASYNCH_CLIENT_SERVER = 0U,
    DCM_USE_ASYNCH_FNC           = 1U
} Dcm_DspSecurityUsePortType;

/*SWS_Dcm_00685*/
/*SWS_Dcm_01151*/
/*Used while DcmDspSecurityADRSize is not 0*/
typedef P2FUNC(Std_ReturnType, DCM_CODE, EcucFncGetSeedDefA)
(
    P2CONST(uint8, AUTOMATIC, DCM_APPL_DATA) SecurityAccessDataRecord,
    Dcm_OpStatusType OpStatus,
    P2VAR(uint8, AUTOMATIC, DCM_VAR) Seed,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode
);
/*Used while DcmDspSecurityADRSize is 0*/
typedef P2FUNC(Std_ReturnType, DCM_CODE, EcucFncGetSeedDefB)
(
    Dcm_OpStatusType OpStatus,
    P2VAR(uint8, AUTOMATIC, DCM_VAR) Seed,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode
);

typedef P2FUNC(Std_ReturnType, DCM_CODE, EcucFncCompareKeyDef)
(
    P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Key,
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode
);

/*SWS_Dcm_01152*/
typedef P2FUNC(Std_ReturnType, DCM_CODE, EcucFncGetAttemptCounterDef)
(
    Dcm_OpStatusType OpStatus,
    P2VAR(uint8, AUTOMATIC, DCM_VAR) AttemptCounter
);
/*SWS_Dcm_01153*/
typedef P2FUNC(Std_ReturnType, DCM_CODE, EcucFncSetAttemptCounterDef)
(
    Dcm_OpStatusType OpStatus,
    VAR(uint8, AUTOMATIC) AttemptCounter
);
/*ECUC_Dcm_00759*/
typedef struct
{
    /*ECUC_Dcm_00725*/
    uint32 DcmDspSecurityADRSize;/*1 .. 4294967295,0 is the invalid value*/
    /*ECUC_Dcm_01050*/
    boolean DcmDspSecurityAttemptCounterEnabled;
    /*ECUC_Dcm_00969*/
    EcucFncCompareKeyDef DcmDspSecurityCompareKeyFnc;
    /*ECUC_Dcm_00757*/
    uint32 DcmDspSecurityDelayTime;/*0..65535000 ms*/
    /*ECUC_Dcm_00726*/
    uint32 DcmDspSecurityDelayTimeOnBoot;/*0..65535000 ms*/
    /*ECUC_Dcm_01048*/
    EcucFncGetAttemptCounterDef DcmDspSecurityGetAttemptCounterFnc;
    /*ECUC_Dcm_00968*/
    uint8 DcmDspSecurityGetSeedFncIndex;
    /*ECUC_Dcm_00760*/
    uint32 DcmDspSecurityKeySize;
    /*ECUC_Dcm_00754*/
    /*Value of Security level,SecurityLevel = (SecurityAccessType (requestSeed) + 1) / 2*/
    Dcm_SecLevelType DcmDspSecurityLevel;
    /*ECUC_Dcm_00762*/
    uint8 DcmDspSecurityNumAttDelay;
    /*ECUC_Dcm_00755*/
    uint32 DcmDspSecuritySeedSize;
    /*ECUC_Dcm_01049*/
    EcucFncSetAttemptCounterDef DcmDspSecuritySetAttemptCounterFnc;
    /*ECUC_Dcm_00967*/
    Dcm_DspSecurityUsePortType DcmDspSecurityUsePort;
    uint16 DcmDspSecurityMask;
} Dcm_DspSecurityRowType;

/*ECUC_Dcm_00764*/
typedef struct
{
    uint8 NumOfSecurityRow;
    const Dcm_DspSecurityRowType *DcmDspSecurityRow;
    const EcucFncGetSeedDefA *DcmDspGetSeedFncATable;
    const EcucFncGetSeedDefB *DcmDspGetSeedFncBTable;
} Dcm_DspSecurityType;

/*******************************************************************************
* for UDS 28 Service
*******************************************************************************/
#define DCM_ENABLE_RX_TX                    ((uint8)0x00)
#define DCM_ENABLE_RX_DISABLE_TX            ((uint8)0x01)
#define DCM_DISABLE_RX_ENABLE_TX            ((uint8)0x02)
#define DCM_DISABLE_RX_TX                   ((uint8)0x03)
#define DCM_ENABLE_RX_DISABLE_TX_ENHANCED   ((uint8)0x04)
#define DCM_ENABLE_RX_TX_ENHANCED           ((uint8)0x05)


/*SWS_Dcm_00981*/
typedef uint8 Dcm_CommunicationModeType;
#define DCM_ENABLE_RX_TX_NORM               ((uint8)0x00)
#define DCM_ENABLE_RX_DISABLE_TX_NORM       ((uint8)0x01)
#define DCM_DISABLE_RX_ENABLE_TX_NORM       ((uint8)0x02)
#define DCM_DISABLE_RX_TX_NORMAL            ((uint8)0x03)
#define DCM_ENABLE_RX_TX_NM                 ((uint8)0x04)
#define DCM_ENABLE_RX_DISABLE_TX_NM         ((uint8)0x05)
#define DCM_DISABLE_RX_ENABLE_TX_NM         ((uint8)0x06)
#define DCM_DISABLE_RX_TX_NM                ((uint8)0x07)
#define DCM_ENABLE_RX_TX_NORM_NM            ((uint8)0x08)
#define DCM_ENABLE_RX_DISABLE_TX_NORM_NM    ((uint8)0x09)
#define DCM_DISABLE_RX_ENABLE_TX_NORM_NM    ((uint8)0x0A)
#define DCM_DISABLE_RX_TX_NORM_NM           ((uint8)0x0B)

#define DCM_NORMAL_MSG                      ((uint8)0x01)
#define DCM_NM_MSG                          ((uint8)0x02)
#define DCM_NM_NORMAL_MSG                   ((uint8)0x03)

typedef P2FUNC(Std_ReturnType, DCM_CODE, EcucSwitchFncCommunicationControl)
(
    uint8 nextMode
);
/*ECUC_Dcm_00901*/
typedef struct
{
    /*ECUC_Dcm_01045*/
    boolean DcmDspComControlAllChannelUsed;
    /*ECUC_Dcm_00902*/
    uint8 DcmDspAllComMChannelRef;
    EcucSwitchFncCommunicationControl SwitchCommunicationControlAllChannelFnc;
} Dcm_DspComControlAllChannelType;

/*ECUC_Dcm_00943*/
typedef struct
{
    /*ECUC_Dcm_00944*/
    uint8 DcmDspComControlCommunicationReEnableModeRuleRef;
} Dcm_DspComControlSettingType;

/*ECUC_Dcm_00903*/
typedef struct
{
    /*ECUC_Dcm_01046*/
    boolean DcmDspComControlSpecificChannelUsed;
    /*ECUC_Dcm_00905*/
    uint8 DcmDspSubnetNumber;/*1..14*/
    /*ECUC_Dcm_00904*/
    uint8 DcmDspComMChannelRef;
    EcucSwitchFncCommunicationControl SwitchCommunicationControlSpecificChannelFnc;
} Dcm_DspComControlSpecificChannelType;

/*ECUC_Dcm_01033*/
typedef struct
{
    /*ECUC_Dcm_01031*/
    uint16 DcmDspComControlSubNodeId;/*1..65535*/
    /*ECUC_Dcm_01032*/
    boolean DcmDspComControlSubNodeUsed;
    /*ECUC_Dcm_01030*/
    uint8 DcmDspComControlSubNodeComMChannelRef;
    EcucSwitchFncCommunicationControl SwitchCommunicationControlSubNodeFnc;
} Dcm_DspComControlSubNodeType;

/*ECUC_Dcm_00900*/
typedef struct
{
    uint8 NumOfControlAllChannel;/*0..255*/
    const Dcm_DspComControlAllChannelType *DcmDspComControlAllChannel;
    //const Dcm_DspComControlSettingType *DcmDspComControlSetting;
    uint8 NumOfControlSpecificChannel;/*0..14*/
    const Dcm_DspComControlSpecificChannelType *DcmDspComControlSpecificChannel;
    uint16 NumOfControlSubNode;/*0..65535*/
    const Dcm_DspComControlSubNodeType *DcmDspComControlSubNode;
} Dcm_DspComControlType;



/*******************************************************************************
* for UDS 2A Service
*******************************************************************************/
#if(DCM_UDS_2A_SERVICE == STD_ON)
#define DCM_2A_HIGHBYTE               ((uint8)0xF2)

#define DCM_2A_SENDATSLOWRATE         ((uint8)0x01)
#define DCM_2A_SENDATMEDIUMRATE       ((uint8)0x02)
#define DCM_2A_SENDATFASTRATE         ((uint8)0x03)
#define DCM_2A_STOPSENDING            ((uint8)0x04)

/*ECUC_Dcm_00957*/
typedef struct
{
    /*ECUC_Dcm_00960*/
    /*uint:ms range:1..255,0 means the transmission mode not supported*/
    uint8 DcmDspPeriodicTransmissionFastRate;
    /*ECUC_Dcm_00959*/
    /*uint:ms range:1..255,0 means the transmission mode not supported*/
    uint8 DcmDspPeriodicTransmissionMediumRate;
    /*ECUC_Dcm_00958*/
    /*uint:ms range:1..255,0 means the transmission mode not supported*/
    uint8 DcmDspPeriodicTransmissionSlowRate;
} Dcm_DspPeriodicTransmissionType;

/*ECUC_Dcm_00961*/
typedef struct
{
    /*ECUC_Dcm_00962*/
    /*Defines the maximum number of periodicDataIdentifiers that can be
    scheduled concurrently.*/
    uint8 DcmDspMaxPeriodicDidScheduler;
} Dcm_DspPeriodicDidTransmissionType;
#endif

/*******************************************************************************
* for UDS 2C Service
*******************************************************************************/
#if(DCM_UDS_2C_SERVICE == STD_ON)
#define DCM_2C_BY_IDENTIFIER         ((uint8)0x01)
#define DCM_2C_BY_MEMORYADDR         ((uint8)0x02)
#define DCM_2C_CLEAR_DDDID           ((uint8)0x03)

typedef struct
{
    uint16 DcmDspDDDIDSourceDidIndex;
    /*Converte byte position in request message to bit position*/
    uint16 DcmDspDDDIDDataPositionInSourceDid;
    uint16 DcmDspDataIndex;
    uint8 DcmDspDDDIDMemoryId;
    uint32 DcmDspDDDIDDataMemoryAddress;
    uint32 DcmDspDDDIDDataSize;
} Dcm_DspDDDIDElementInfoType;

typedef struct
{
    uint16 DcmDspDDDIDIndex;
    boolean DcmDspDDDIDDefined;
    uint8 DcmDspDDDIDElementUsedNum;
    Dcm_DspDDDIDElementInfoType *DcmDspDDDIDElementPtr;
} Dcm_DspDDDIDType;
#endif

/*******************************************************************************
* for UDS 2E Service
*******************************************************************************/



/*******************************************************************************
* for UDS 2F Service
*******************************************************************************/



/*******************************************************************************
* for UDS 31 Service
*******************************************************************************/
#if(DCM_UDS_31_SERVICE == STD_ON)
#define DCM_START_ROUTINE            ((uint8)0x01)
#define DCM_STOP_ROUTINE             ((uint8)0x02)
#define DCM_REQUEST_ROUTINE_RESULTS  ((uint8)0x03)

/*DcmDspRequestRoutineResultsOutSignal.DcmDspRoutineSignalType)} != VARIABLE_LENGTH*/
typedef P2FUNC(Std_ReturnType, DCM_CODE, EcucFncRoutineRequestResultDefA)
(
    Dcm_OpStatusType OpStatus,
    P2VAR(uint8, AUTOMATIC, DCM_VAR) DataOut,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode
);
/*DcmDspRequestRoutineResultsOutSignal.DcmDspRoutineSignalType)} == VARIABLE_LENGTH*/
typedef P2FUNC(Std_ReturnType, DCM_CODE, EcucFncRoutineRequestResultDefB)
(
    Dcm_OpStatusType OpStatus,
    P2VAR(uint8, AUTOMATIC, DCM_VAR) DataOut,
    P2VAR(uint16, AUTOMATIC, DCM_VAR) currentDataLength,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode
);

/*DcmDspRoutineInSignal.DcmDspRoutineSignalType != VARIABLE_LENGTH &&
DcmDspRoutineOutSignal.DcmDspRoutineSignalType != VARIABLE_LENGTH*/
typedef P2FUNC(Std_ReturnType, DCM_CODE, EcucFncRoutineStartStopDefA)
(
    P2VAR(uint8, AUTOMATIC, DCM_VAR) DataIn,
    Dcm_OpStatusType OpStatus,
    P2VAR(uint8, AUTOMATIC, DCM_VAR) DataOut,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode
);
/*DcmDspRoutineInSignal.DcmDspRoutineSignalType != VARIABLE_LENGTH &&
DcmDspRoutineOutSignal.DcmDspRoutineSignalType == VARIABLE_LENGTH*/
typedef P2FUNC(Std_ReturnType, DCM_CODE, EcucFncRoutineStartStopDefB)
(
    P2VAR(uint8, AUTOMATIC, DCM_VAR) DataInX,
    Dcm_OpStatusType OpStatus,
    P2VAR(uint8, AUTOMATIC, DCM_VAR) DataOutN,
    P2VAR(uint16, AUTOMATIC, DCM_VAR) currentDataLength,/*For DataOutN*/
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode
);
/*DcmDspRoutineInSignal.DcmDspRoutineSignalType == VARIABLE_LENGTH &&
DcmDspRoutineOutSignal.DcmDspRoutineSignalType != VARIABLE_LENGTH*/
typedef P2FUNC(Std_ReturnType, DCM_CODE, EcucFncRoutineStartStopDefC)
(
    P2VAR(uint8, AUTOMATIC, DCM_VAR) DataInN,
    Dcm_OpStatusType OpStatus,
    P2VAR(uint8, AUTOMATIC, DCM_VAR) DataOutX,
    uint16 currentDataLength,/*For DataInN*/
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode
);
/*DcmDspRoutineInSignal.DcmDspRoutineSignalType == VARIABLE_LENGTH &&
DcmDspRoutineOutSignal.DcmDspRoutineSignalType == VARIABLE_LENGTH*/
typedef P2FUNC(Std_ReturnType, DCM_CODE, EcucFncRoutineStartStopDefD)
(
    P2VAR(uint8, AUTOMATIC, DCM_VAR) DataInN,
    Dcm_OpStatusType OpStatus,
    P2VAR(uint8, AUTOMATIC, DCM_VAR) DataOutN,
    P2VAR(uint16, AUTOMATIC, DCM_VAR) currentDataLength,/*In&Out parameter*/
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode
);

typedef struct
{
    /*ECUC_Dcm_01013*//*ECUC_Dcm_01014*//*ECUC_Dcm_01015*/
    /*ECUC_Dcm_01016*//*ECUC_Dcm_01017*/
    Dcm_DataEndiannessType DcmDspRoutineSignalEndianness;
    /*ECUC_Dcm_00838*//*ECUC_Dcm_00841*//*ECUC_Dcm_00844*/
    /*ECUC_Dcm_00847*//*ECUC_Dcm_00850*/
    /*Provide the length in bits of the signal in the
    RoutineControl request/response*/
    uint32 DcmDspRoutineSignalLength;/*Changed to length in byte by dfx20181029*/
    /*ECUC_Dcm_00837*//*ECUC_Dcm_00840*//*ECUC_Dcm_00843*/
    /*ECUC_Dcm_00846*//*ECUC_Dcm_00867*/
    /*Provide the position of the signal in the RoutineControl
    request/response.The position is defined in bits.*/
    uint32 DcmDspRoutineSignalPos;
    /*ECUC_Dcm_00881*//*ECUC_Dcm_00882*//*ECUC_Dcm_00883*/
    /*ECUC_Dcm_00884*//*ECUC_Dcm_00885*/
    Dcm_DataType DcmDspRoutineSignalType;
} Dcm_DspRoutineSignalType;

/*ECUC_Dcm_01025*/
typedef struct
{
    /*ECUC_Dcm_01028*/
    //DcmDspCommonAuthorizationModeRuleRef;
    uint8 DcmDspCommonAuthorizationSupportAddress;
#if(STD_ON == DCM_UDS_27_SERVICE)
    /*ECUC_Dcm_01026*/
    Dcm_SecRefType DcmDspCommonAuthorizationSecurityLevelRef;
#endif
    /*ECUC_Dcm_01027*/
    Dcm_SesRefType DcmDspCommonAuthorizationSessionRef;
} Dcm_DspCommonAuthorizationType;

/*ECUC_Dcm_01023*/
typedef struct
{
    /*ECUC_Dcm_00753*/
    uint16 DcmDspRequestRoutineResultsFncIndex;
    /*ECUC_Dcm_01054*/
    const Dcm_DspCommonAuthorizationType *DcmDspRequestRoutineResultsCommonAuthorizationRef;
    /*ECUC_Dcm_00831*//*ECUC_Dcm_00836*/
    Dcm_DspRoutineSignalType DcmDspRequestRoutineResultsOut;
#if(DCM_CAR_PLATFORM == DCM_GEELY_PLATFORM)
    uint32 P4ServerMax;
#endif

} Dcm_DspRequestRoutineResultsType;

/*ECUC_Dcm_01022*/
typedef struct
{
    /*ECUC_Dcm_00752*/
    uint16 DcmDspStopRoutineFncIndex;
    /*ECUC_Dcm_01053*/
    const Dcm_DspCommonAuthorizationType *DcmDspStopRoutineCommonAuthorizationRef;
    /*ECUC_Dcm_00832*//*ECUC_Dcm_00839*/
    Dcm_DspRoutineSignalType DcmDspStopRoutineIn;
    /*ECUC_Dcm_00833*//*ECUC_Dcm_00842*/
    Dcm_DspRoutineSignalType DcmDspStopRoutineOut;
#if(DCM_CAR_PLATFORM == DCM_GEELY_PLATFORM)
    uint32 P4ServerMax;
#endif
} Dcm_DspStopRoutineType;

/*ECUC_Dcm_01021*/
typedef struct
{
    /*ECUC_Dcm_00664*/
    uint16 DcmDspStartRoutineFncIndex;
    /*ECUC_Dcm_01052*/
    const Dcm_DspCommonAuthorizationType *DcmDspStartRoutineCommonAuthorizationRef;
    /*ECUC_Dcm_00832*//*ECUC_Dcm_00845*/
    Dcm_DspRoutineSignalType DcmDspStartRoutineIn;
    /*ECUC_Dcm_00833*//*ECUC_Dcm_00848*/
    Dcm_DspRoutineSignalType DcmDspStartRoutineOut;
#if(DCM_CAR_PLATFORM == DCM_GEELY_PLATFORM)
    uint32 P4ServerMax;
#endif
} Dcm_DspStartRoutineType;

typedef struct
{
    /*ECUC_Dcm_00641*/
    uint16 DcmDspRoutineIdentifier;
    /*ECUC_Dcm_01063*/
    //uint8 DcmDspRoutineInfoByte;/*0..255,OBD use cases*/
    /*ECUC_Dcm_00724*/
    boolean DcmDspRoutineUsePort;
    /*ECUC_Dcm_00807*/
    boolean DcmDspRoutineUsed;
    const Dcm_DspStartRoutineType *DcmDspStartRoutine;
    const Dcm_DspStopRoutineType *DcmDspStopRoutine;
    const Dcm_DspRequestRoutineResultsType *DcmDspRequestRoutineResults;
} Dcm_DspRoutineIdInfoType;

/*ECUC_Dcm_00640*/
typedef struct
{
    uint16 NumOfRoutineId;
    const Dcm_DspRoutineIdInfoType *DcmDspRoutineIdInfo;

    const EcucFncRoutineStartStopDefA *DcmDspRoutineStartFncATable;
    const EcucFncRoutineStartStopDefB *DcmDspRoutineStartFncBTable;
    const EcucFncRoutineStartStopDefC *DcmDspRoutineStartFncCTable;
    const EcucFncRoutineStartStopDefD *DcmDspRoutineStartFncDTable;

    const EcucFncRoutineStartStopDefA *DcmDspRoutineStopFncATable;
    const EcucFncRoutineStartStopDefB *DcmDspRoutineStopFncBTable;
    const EcucFncRoutineStartStopDefC *DcmDspRoutineStopFncCTable;
    const EcucFncRoutineStartStopDefD *DcmDspRoutineStopFncDTable;

    const EcucFncRoutineRequestResultDefA *DcmDspRoutineRequestResulDefATable;
    const EcucFncRoutineRequestResultDefB *DcmDspRoutineRequestResulDefBTable;
} Dcm_DspRoutineType;

#endif

/*******************************************************************************
* for UDS 3E Service
*******************************************************************************/


/*******************************************************************************
* for UDS 85 Service
*******************************************************************************/
#if(DCM_UDS_85_SERVICE == STD_ON)
#define DCM_DTC_SETTING_ON   ((uint8)0x01)
#define DCM_DTC_SETTING_OFF  ((uint8)0x02)
#endif

/*******************************************************************************
* for UDS 87 Service
*******************************************************************************/
#if(DCM_UDS_87_SERVICE == STD_ON)
#define DCM_VERIFY_FIXED_PARAMETER     ((uint8)0x01)
#define DCM_VERIFY_SPECIFIC_PARAMETER  ((uint8)0x02)
#define DCM_TRANSITION_MODE            ((uint8)0x03)
#endif

/*******************************************************************************
* DID definition for UDS 22/2A/2C/2E/2F service
*******************************************************************************/
/*ECUC_Dcm_01059*/
typedef enum
{
    DCM_CONTROLMASK_EXTERNAL = 0U,
    DCM_CONTROLMASK_INTERNAL = 1U,/*default value*/
    DCM_CONTROLMASK_NO       = 2U
} Dcm_DspDidControlMaskType;

/*ECUC_Dcm_01057*/
typedef struct
{
    /*ECUC_Dcm_01058*/
    uint8 DcmDspDidControlMaskBitPosition;/*0 .. 31*/
} Dcm_DspDidControlEnableMaskType;

/*ECUC_Dcm_00619*/
typedef struct
{
    /*ECUC_Dcm_01059*/
    Dcm_DspDidControlMaskType DcmDspDidControlMask;
    /*ECUC_Dcm_01060*/
    /*The value defines the size of the controlEnableMaskRecord in bytes.*/
    uint8 DcmDspDidControlMaskSize;/*0..4*/
    /*ECUC_Dcm_00624*/
    boolean DcmDspDidFreezeCurrentState;
    /*ECUC_Dcm_00623*/
    boolean DcmDspDidResetToDefault;
    /*ECUC_Dcm_00625*/
    boolean DcmDspDidShortTermAdjustment;
    /*ECUC_Dcm_00923*/
    //DcmDspDidControlModeRuleRef;
    uint8 DcmDspDidControlSupportAddress;
    /*ECUC_Dcm_00620*/
#if(STD_ON == DCM_UDS_27_SERVICE)
    Dcm_SecRefType DcmDspDidControlSecurityLevelRef;
#endif
    /*ECUC_Dcm_00621*/
    Dcm_SesRefType DcmDspDidControlSessionRef;
    /*ECUC_Dcm_01057*/
    uint8 NumOfControlEnableMask;/*0..32*//*The value is equal to NumOfDidSignal*/
    const Dcm_DspDidControlEnableMaskType *DcmDspDidControlEnableMask;
} Dcm_DspDidControlType;

/*ECUC_Dcm_00613*/
typedef struct
{
    /*ECUC_Dcm_00917*/
    //DcmDspDidReadModeRuleRef;
    uint8 DcmDspDidReadSupportAddress;
    /*ECUC_Dcm_00614*/
#if(STD_ON == DCM_UDS_27_SERVICE)
    Dcm_SecRefType DcmDspDidReadSecurityLevelRef;
#endif
    /*ECUC_Dcm_00615*/
    Dcm_SesRefType DcmDspDidReadSessionRef;
} Dcm_DspDidReadType;

/*ECUC_Dcm_00616*/
typedef struct
{
    /*ECUC_Dcm_00922*/
    //DcmDspDidWriteModeRuleRef;
    uint8 DcmDspDidWriteSupportAddress;
    /*ECUC_Dcm_00617*/
#if(STD_ON == DCM_UDS_27_SERVICE)
    Dcm_SecRefType DcmDspDidWriteSecurityLevelRef;
#endif
    /*ECUC_Dcm_00618*/
    Dcm_SesRefType DcmDspDidWriteSessionRef;
} Dcm_DspDidWriteType;

#if((DCM_UDS_2C_SERVICE == STD_ON)||(DCM_UDS_2F_SERVICE == STD_ON) \
  ||(DCM_UDS_22_SERVICE == STD_ON)||(DCM_UDS_2E_SERVICE == STD_ON) \
  ||(DCM_UDS_2A_SERVICE == STD_ON))
/*ECUC_Dcm_00607*/
typedef struct
{
#if(DCM_UDS_2C_SERVICE == STD_ON)
    /*ECUC_Dcm_00970*/
    /*Maximum number of source elements of a DDDID.*/
    uint8 DcmDspDDDIDMaxElements;
    /*ECUC_Dcm_00612*/
    boolean DcmDspDidDynamicallyDefined;
    uint16 DcmDspDDDIDBufferIndex;
#endif
#if(DCM_UDS_2F_SERVICE == STD_ON)
    const Dcm_DspDidControlType *DcmDspDidControl;
#endif
#if((DCM_UDS_22_SERVICE == STD_ON)||(DCM_UDS_2A_SERVICE == STD_ON))
    const Dcm_DspDidReadType *DcmDspDidRead;
#endif
#if(DCM_UDS_2E_SERVICE == STD_ON)
    const Dcm_DspDidWriteType *DcmDspDidWrite;
#endif
} Dcm_DspDidInfoType;
#endif

/*ECUC_Dcm_00810*/
typedef struct
{
    /*ECUC_Dcm_00611*/
    uint32 DcmDspDataScalingInfoSize;/*0..4294967295*/
} Dcm_DspDataInfoType;

/*SWS_Dcm_00686*/
/*DcmDspDataUsePort == USE_DATA_ASYNCH_CLIENT_SERVER/USE_DATA_ASYNCH_FNC/
USE_DATA_ASYNCH_CLIENT_SERVER_ERROR/USE_DATA_ASYNCH_FNC_ERROR*/
typedef P2FUNC(Std_ReturnType, DCM_CODE, EcucFncDataServicesConditionCheckReadDefA)
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode
);
/*DcmDspDataUsePort == USE_DATA_SYNCH_CLIENT_SERVER/USE_DATA_SYNCH_FNC*/
typedef P2FUNC(Std_ReturnType, DCM_CODE, EcucFncDataServicesConditionCheckReadDefB)
(
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode
);

typedef P2FUNC(Std_ReturnType, DCM_CODE, EcucFncDataServicesGetScalingInformationDefA)
(
    Dcm_OpStatusType OpStatus,
    P2VAR(void, AUTOMATIC, DCM_VAR) ScalingInfo,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode
);
typedef P2FUNC(Std_ReturnType, DCM_CODE, EcucFncDataServicesGetScalingInformationDefB)
(
    P2VAR(void, AUTOMATIC, DCM_VAR) ScalingInfo,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode
);

/*DcmDspDataUsePort == USE_DATA_ASYNCH_CLIENT_SERVER/USE_DATA_ASYNCH_FNC*/
typedef P2FUNC(Std_ReturnType, DCM_CODE, EcucFncDataServicesReadDataDefA)
(
    Dcm_OpStatusType OpStatus,
    P2VAR(uint8, AUTOMATIC, DCM_VAR) Data
);
/*DcmDspDataUsePort == USE_DATA_ASYNCH_CLIENT_SERVER_ERROR/USE_DATA_ASYNCH_FNC_ERROR*/
typedef P2FUNC(Std_ReturnType, DCM_CODE, EcucFncDataServicesReadDataDefB)
(
    Dcm_OpStatusType OpStatus,
    P2VAR(uint8, AUTOMATIC, DCM_VAR) Data,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode
);
/*DcmDspDataUsePort == USE_DATA_SYNCH_CLIENT_SERVER/USE_DATA_SYNCH_FNC*/
typedef P2FUNC(Std_ReturnType, DCM_CODE, EcucFncDataServicesReadDataDefC)
(
    P2VAR(uint8, AUTOMATIC, DCM_VAR) Data
);

/*DcmDspDataUsePort == USE_DATA_ASYNCH_CLIENT_SERVER/USE_DATA_ASYNCH_CLIENT_SERVER_ERROR/
USE_DATA_ASYNCH_FNC/USE_DATA_ASYNCH_FNC_ERROR &&
DcmDspDataType == UINT8_DYN*/
typedef P2FUNC(Std_ReturnType, DCM_CODE, EcucFncDataServicesReadDataLengthDefA)
(
    Dcm_OpStatusType OpStatus,
    P2VAR(uint16, AUTOMATIC, DCM_VAR) DataLength
);
/*DcmDspDataUsePort == USE_DATA_SYNCH_CLIENT_SERVER/USE_DATA_SYNCH_FNC &&
DcmDspDataType == UINT8_DYN*/
typedef P2FUNC(Std_ReturnType, DCM_CODE, EcucFncDataServicesReadDataLengthDefB)
(
    P2VAR(uint16, AUTOMATIC, DCM_VAR) DataLength
);

/*DcmDspDataUsePort == USE_DATA_ASYNCH_CLIENT_SERVER/USE_DATA_ASYNCH_FNC/
USE_DATA_ASYNCH_CLIENT_SERVER_ERROR/USE_DATA_ASYNCH_FNC_ERROR  &&
DcmDspDataType != UINT8_DYN*/
typedef P2FUNC(Std_ReturnType, DCM_CODE, EcucFncDataServicesWriteDataDefA)
(
    P2VAR(uint8, AUTOMATIC, DCM_VAR) Data,
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode
);
/*DcmDspDataUsePort == USE_DATA_ASYNCH_CLIENT_SERVER/USE_DATA_ASYNCH_FNC/
USE_DATA_ASYNCH_CLIENT_SERVER_ERROR/USE_DATA_ASYNCH_FNC_ERROR  &&
DcmDspDataType == UINT8_DYN*/
typedef P2FUNC(Std_ReturnType, DCM_CODE, EcucFncDataServicesWriteDataDefB)
(
    P2VAR(uint8, AUTOMATIC, DCM_VAR) Data,
    uint16 DataLength,
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode
);
/*DcmDspDataUsePort == USE_DATA_SYNCH_CLIENT_SERVER/USE_DATA_SYNCH_FNC  &&
DcmDspDataType != UINT8_DYN*/
typedef P2FUNC(Std_ReturnType, DCM_CODE, EcucFncDataServicesWriteDataDefC)
(
    P2VAR(uint8, AUTOMATIC, DCM_VAR) Data,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode
);
/*DcmDspDataUsePort == USE_DATA_SYNCH_CLIENT_SERVER/USE_DATA_SYNCH_FNC  &&
DcmDspDataType == UINT8_DYN*/
typedef P2FUNC(Std_ReturnType, DCM_CODE, EcucFncDataServicesWriteDataDefD)
(
    P2VAR(uint8, AUTOMATIC, DCM_VAR) Data,
    uint16 DataLength,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode
);
/*DcmDspDataUsePort == USE_DATA_ASYNCH_CLIENT_SERVER/USE_DATA_ASYNCH_FNC/
USE_DATA_ASYNCH_CLIENT_SERVER_ERROR/USE_DATA_ASYNCH_FNC_ERROR  &&
DcmDspDidControlMask != DCM_CONTROLMASK_EXTERNAL*/
typedef P2FUNC(Std_ReturnType, DCM_CODE, EcucFncDataServicesIOControlDefA)
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode
);
/*DcmDspDataUsePort == USE_DATA_ASYNCH_CLIENT_SERVER/USE_DATA_ASYNCH_FNC/
USE_DATA_ASYNCH_CLIENT_SERVER_ERROR/USE_DATA_ASYNCH_FNC_ERROR  &&
DcmDspDidControlMask == DCM_CONTROLMASK_EXTERNAL*/
typedef P2FUNC(Std_ReturnType, DCM_CODE, EcucFncDataServicesIOControlDefB)
(
    Dcm_OpStatusType OpStatus,
    uint32 controlMask,/*in parameter*/
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode
);
/*DcmDspDataUsePort == USE_DATA_SYNCH_CLIENT_SERVER/USE_DATA_SYNCH_FNC  &&
DcmDspDidControlMask != DCM_CONTROLMASK_EXTERNAL*/
/*For ReturnControlToEcu service: DcmDspDidControlMask != DCM_CONTROLMASK_EXTERNAL*/
typedef P2FUNC(Std_ReturnType, DCM_CODE, EcucFncDataServicesIOControlDefC)
(
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode
);
/*DcmDspDataUsePort == USE_DATA_SYNCH_CLIENT_SERVER/USE_DATA_SYNCH_FNC  &&
DcmDspDidControlMask == DCM_CONTROLMASK_EXTERNAL*/
/*For ReturnControlToEcu service: DcmDspDidControlMask == DCM_CONTROLMASK_EXTERNAL*/
typedef P2FUNC(Std_ReturnType, DCM_CODE, EcucFncDataServicesIOControlDefD)
(
    uint32 controlMask,/*in parameter*/
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode
);
/*DcmDspDataUsePort == USE_DATA_ASYNCH_CLIENT_SERVER/USE_DATA_ASYNCH_FNC/
USE_DATA_ASYNCH_CLIENT_SERVER_ERROR/USE_DATA_ASYNCH_FNC_ERROR  &&
DcmDspDataType != UINT8_DYN  &&
DcmDspDidControlMask != DCM_CONTROLMASK_EXTERNAL*/
typedef P2FUNC(Std_ReturnType, DCM_CODE, EcucFncDataServicesShortTermAdjustmentDefA)
(
    P2VAR(uint8, AUTOMATIC, DCM_VAR) ControlStateInfo,
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode
);
/*DcmDspDataUsePort == USE_DATA_ASYNCH_CLIENT_SERVER/USE_DATA_ASYNCH_FNC/
USE_DATA_ASYNCH_CLIENT_SERVER_ERROR/USE_DATA_ASYNCH_FNC_ERROR  &&
DcmDspDataType != UINT8_DYN  &&
DcmDspDidControlMask == DCM_CONTROLMASK_EXTERNAL*/
typedef P2FUNC(Std_ReturnType, DCM_CODE, EcucFncDataServicesShortTermAdjustmentDefB)
(
    P2VAR(uint8, AUTOMATIC, DCM_VAR) ControlStateInfo,
    Dcm_OpStatusType OpStatus,
    uint32 controlMask,/*in parameter*/
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode
);
/*DcmDspDataUsePort == USE_DATA_ASYNCH_CLIENT_SERVER/USE_DATA_ASYNCH_FNC/
USE_DATA_ASYNCH_CLIENT_SERVER_ERROR/USE_DATA_ASYNCH_FNC_ERROR  &&
DcmDspDataType == UINT8_DYN  &&
DcmDspDidControlMask != DCM_CONTROLMASK_EXTERNAL*/
typedef P2FUNC(Std_ReturnType, DCM_CODE, EcucFncDataServicesShortTermAdjustmentDefC)
(
    P2VAR(uint8, AUTOMATIC, DCM_VAR) ControlStateInfo,
    uint16 DataLength,
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode
);
/*DcmDspDataUsePort == USE_DATA_ASYNCH_CLIENT_SERVER/USE_DATA_ASYNCH_FNC/
USE_DATA_ASYNCH_CLIENT_SERVER_ERROR/USE_DATA_ASYNCH_FNC_ERROR  &&
DcmDspDataType == UINT8_DYN  &&
DcmDspDidControlMask == DCM_CONTROLMASK_EXTERNAL*/
typedef P2FUNC(Std_ReturnType, DCM_CODE, EcucFncDataServicesShortTermAdjustmentDefD)
(
    P2VAR(uint8, AUTOMATIC, DCM_VAR) ControlStateInfo,
    uint16 DataLength,
    Dcm_OpStatusType OpStatus,
    uint32 controlMask,/*in parameter*/
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode
);
/*DcmDspDataUsePort == USE_DATA_SYNCH_CLIENT_SERVER/USE_DATA_SYNCH_FNC  &&
DcmDspDataType != UINT8_DYN  &&
DcmDspDidControlMask != DCM_CONTROLMASK_EXTERNAL*/
typedef P2FUNC(Std_ReturnType, DCM_CODE, EcucFncDataServicesShortTermAdjustmentDefE)
(
    P2VAR(uint8, AUTOMATIC, DCM_VAR) ControlStateInfo,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode
);
/*DcmDspDataUsePort == USE_DATA_SYNCH_CLIENT_SERVER/USE_DATA_SYNCH_FNC  &&
DcmDspDataType != UINT8_DYN  &&
DcmDspDidControlMask == DCM_CONTROLMASK_EXTERNAL*/
typedef P2FUNC(Std_ReturnType, DCM_CODE, EcucFncDataServicesShortTermAdjustmentDefF)
(
    P2VAR(uint8, AUTOMATIC, DCM_VAR) ControlStateInfo,
    uint32 controlMask,/*in parameter*/
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode
);
/*DcmDspDataUsePort == USE_DATA_SYNCH_CLIENT_SERVER/USE_DATA_SYNCH_FNC  &&
DcmDspDataType == UINT8_DYN  &&
DcmDspDidControlMask != DCM_CONTROLMASK_EXTERNAL*/
typedef P2FUNC(Std_ReturnType, DCM_CODE, EcucFncDataServicesShortTermAdjustmentDefG)
(
    P2VAR(uint8, AUTOMATIC, DCM_VAR) ControlStateInfo,
    uint16 DataLength,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode
);
/*DcmDspDataUsePort == USE_DATA_SYNCH_CLIENT_SERVER/USE_DATA_SYNCH_FNC  &&
DcmDspDataType == UINT8_DYN  &&
DcmDspDidControlMask == DCM_CONTROLMASK_EXTERNAL*/
typedef P2FUNC(Std_ReturnType, DCM_CODE, EcucFncDataServicesShortTermAdjustmentDefH)
(
    P2VAR(uint8, AUTOMATIC, DCM_VAR) ControlStateInfo,
    uint16 DataLength,
    uint32 controlMask,/*in parameter*/
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode
);

/*ECUC_Dcm_00869*/
typedef struct
{
    /*ECUC_Dcm_00986*/
    Dcm_DataEndiannessType DcmDspDataEndianness;
#if((DCM_UDS_22_SERVICE == STD_ON)||(DCM_UDS_2A_SERVICE == STD_ON)||(DCM_UDS_2F_SERVICE == STD_ON))
    /*ECUC_Dcm_00677*/
    uint16 DcmDspDataConditionCheckReadFncIndex;
    /*ECUC_Dcm_00955*/
    boolean DcmDspDataConditionCheckReadFncUsed;
    /*ECUC_Dcm_00671*/
    uint16 DcmDspDataReadDataLengthFncIndex;
    /*ECUC_Dcm_00824*/
    /*Only relevant if DcmDspDataUsePort==USE_ECU_SIGNAL*/
    //DcmDspDataReadEcuSignal;/*Function Name*/
    /*ECUC_Dcm_00669*/
    uint16 DcmDspDataReadFncIndex;
#endif
    /*ECUC_Dcm_00676*/
    //DcmDspDataGetScalingInfoFnc;/*Function Name for UDS 24 service*/
    /*ECUC_Dcm_00811*/
    //const Dcm_DspDataInfoType* DcmDspDataInfoRef;
    /*ECUC_Dcm_00993*/
    //DcmDspDiagnosisScaling;
#if(DCM_UDS_2F_SERVICE == STD_ON)
    /*ECUC_Dcm_00825*/
    /*Only relevant if DcmDspDataUsePort==USE_ECU_SIGNAL*/
    //DcmDspDataEcuSignal;/*Function Name*/
    /*ECUC_Dcm_00672*/
    uint16 DcmDspDataReturnControlToEcuFncIndex;
    /*ECUC_Dcm_00673*/
    uint16 DcmDspDataResetToDefaultFncIndex;
    /*ECUC_Dcm_00674*/
    uint16 DcmDspDataFreezeCurrentStateFncIndex;
    /*ECUC_Dcm_00675*/
    uint16 DcmDspDataShortTermAdjustmentFncIndex;
#endif
    /*ECUC_Dcm_00605*/
    uint16 DcmDspDataSize;/*Length of data in bits associated to the Data.*/
    /*ECUC_Dcm_00985*/
    Dcm_DataType DcmDspDataType;
    /*ECUC_Dcm_00713*/
    Dcm_DspDataUsePortType DcmDspDataUsePort;
#if(DCM_UDS_2E_SERVICE == STD_ON)
    /*ECUC_Dcm_00670*/
    uint16 DcmDspDataWriteFncIndex;
#endif
    /*ECUC_Dcm_00988*/
    /*Defines additional description for ODX documentation*/
    //DcmDspOdxDataDescription;
#if(DCM_NVM_SUPPORT == STD_ON)
    /*ECUC_Dcm_00809*/
    uint16 DcmDspDataBlockIdRef;
#endif
    /*ECUC_Dcm_00989*/
    //DcmDspExternalSRDataElementClass;
} Dcm_DspDataTableType;

typedef struct
{
    uint16 NumOfDidData;
    const Dcm_DspDataTableType *DcmDspDataTable;
#if((DCM_UDS_22_SERVICE == STD_ON)||(DCM_UDS_2A_SERVICE == STD_ON)||(DCM_UDS_2F_SERVICE == STD_ON))
    const EcucFncDataServicesConditionCheckReadDefA *DcmDspDataConditionCheckReadFncATable;
    const EcucFncDataServicesConditionCheckReadDefB *DcmDspDataConditionCheckReadFncBTable;
    const EcucFncDataServicesReadDataLengthDefA *DcmDspDataReadDataLengthFncATable;
    const EcucFncDataServicesReadDataLengthDefB *DcmDspDataReadDataLengthFncBTable;
    const EcucFncDataServicesReadDataDefA *DcmDspDataReadDataFncATable;
    const EcucFncDataServicesReadDataDefB *DcmDspDataReadDataFncBTable;
    const EcucFncDataServicesReadDataDefC *DcmDspDataReadDataFncCTable;
#endif
#if(DCM_UDS_2E_SERVICE == STD_ON)
    const EcucFncDataServicesWriteDataDefA *DcmDspDataWriteDataFncATable;
    const EcucFncDataServicesWriteDataDefB *DcmDspDataWriteDataFncBTable;
    const EcucFncDataServicesWriteDataDefC *DcmDspDataWriteDataFncCTable;
    const EcucFncDataServicesWriteDataDefD *DcmDspDataWriteDataFncDTable;
#endif
#if(DCM_UDS_2F_SERVICE == STD_ON)
    const EcucFncDataServicesIOControlDefC *DcmDspDataReturnControlToEcuFncCTable;
    const EcucFncDataServicesIOControlDefD *DcmDspDataReturnControlToEcuFncDTable;

    const EcucFncDataServicesIOControlDefA *DcmDspDataResetToDefaultFncATable;
    const EcucFncDataServicesIOControlDefB *DcmDspDataResetToDefaultFncBTable;
    const EcucFncDataServicesIOControlDefC *DcmDspDataResetToDefaultFncCTable;
    const EcucFncDataServicesIOControlDefD *DcmDspDataResetToDefaultFncDTable;

    const EcucFncDataServicesIOControlDefA *DcmDspDataFreezeCurrentStateFncATable;
    const EcucFncDataServicesIOControlDefB *DcmDspDataFreezeCurrentStateFncBTable;
    const EcucFncDataServicesIOControlDefC *DcmDspDataFreezeCurrentStateFncCTable;
    const EcucFncDataServicesIOControlDefD *DcmDspDataFreezeCurrentStateFncDTable;

    const EcucFncDataServicesShortTermAdjustmentDefA *DcmDspDataShortTermAdjustmentFncATable;
    const EcucFncDataServicesShortTermAdjustmentDefB *DcmDspDataShortTermAdjustmentFncBTable;
    const EcucFncDataServicesShortTermAdjustmentDefC *DcmDspDataShortTermAdjustmentFncCTable;
    const EcucFncDataServicesShortTermAdjustmentDefD *DcmDspDataShortTermAdjustmentFncDTable;
    const EcucFncDataServicesShortTermAdjustmentDefE *DcmDspDataShortTermAdjustmentFncETable;
    const EcucFncDataServicesShortTermAdjustmentDefF *DcmDspDataShortTermAdjustmentFncFTable;
    const EcucFncDataServicesShortTermAdjustmentDefG *DcmDspDataShortTermAdjustmentFncGTable;
    const EcucFncDataServicesShortTermAdjustmentDefH *DcmDspDataShortTermAdjustmentFncHTable;
#endif
} Dcm_DspDataType;

/*ECUC_Dcm_00813*/
typedef struct
{
    /*ECUC_Dcm_00814*/
    uint16 DcmDspDidDataPos;/*The position is defined in bits.*/
    /*ECUC_Dcm_00808*/
    uint16 DcmDspDidDataRef;/*Reference to DcmDspData*/
} Dcm_DspDidSignalType;


/*ECUC_Dcm_00601*/
typedef struct
{
    /*ECUC_Dcm_00602*/
    uint16 DcmDspDidIdentifier;
    /*ECUC_Dcm_00805*/
#if(DCM_CONFIG_VARIANTS != STD_CONFIG_VARIANTS_POSTBUILD)
    boolean DcmDspDidUsed;
#endif
#if((DCM_UDS_2C_SERVICE == STD_ON)||(DCM_UDS_2F_SERVICE == STD_ON) \
  ||(DCM_UDS_22_SERVICE == STD_ON)||(DCM_UDS_2E_SERVICE == STD_ON) \
  ||(DCM_UDS_2A_SERVICE == STD_ON))
    /*ECUC_Dcm_00604*/
    Dcm_DspDidInfoType DcmDspDidInfoRef;
#endif
    /*ECUC_Dcm_00606*/
    //uint16 NumOfDidRef;
    //const uint16 *DcmDspDidRef;/*Reference to DcmDspDid*/
    uint16 NumOfDidSignal;
    const Dcm_DspDidSignalType *DcmDspDidSignal;
} Dcm_DspDidTableType;

typedef struct
{
    uint16 NumOfDid;
    const Dcm_DspDidTableType *Dcm_DspDidTable;
} Dcm_DspDidType;



/*******************************************************************************
* OBD type define start
*******************************************************************************/
#if((DCM_OBD_01_SERVICE == STD_ON)||(DCM_OBD_02_SERVICE == STD_ON))

/*ECUC_Dcm_00893*/
typedef enum
{
    DCM_SERVICE_01      = 0U,
    DCM_SERVICE_01_02   = 1U,
    DCM_SERVICE_02      = 2U
} Dcm_DspPidServiceType;

#if(DCM_OBD_01_SERVICE == STD_ON)
/*ECUC_Dcm_00894*/
typedef struct
{
    /*ECUC_Dcm_01012*/
    Dcm_DataEndiannessType DcmDspPidDataEndianness;
    /*ECUC_Dcm_00629*/
    EcucFncDataServicesReadDataDefC DcmDspPidDataReadFnc;
    /*ECUC_Dcm_01018*/
    Dcm_DataType DcmDspPidDataType;
    /*ECUC_Dcm_00720*/
    Dcm_DspDataUsePortType DcmDspPidDataUsePort;
} Dcm_DspPidService01Type;
#endif

#if(DCM_OBD_02_SERVICE == STD_ON)
/*ECUC_Dcm_00895*/
typedef struct
{
    /*ECUC_Dcm_00887*/
    uint8 DcmDspPidDataDemRef;/*Reference to DemPidDataElement in DEM configuration.*/
} Dcm_DspPidService02Type;
#endif

/*ECUC_Dcm_00874*/
typedef struct
{
    /*ECUC_Dcm_00876*/
    uint8 DcmDspPidDataSupportInfoBit;/*Referenced Bit of the SupportInfo. Range:0..255*/
    /*ECUC_Dcm_00875*/
    uint8 DcmDspPidDataSupportInfoRef;/*Reference to DcmDspPidSupportInfo.*/
} Dcm_DspPidDataSupportInfoType;

/*ECUC_Dcm_00865*/
typedef struct
{
    /*ECUC_Dcm_00866*/
    uint16 DcmDspPidDataPos;/*Position in bit. Range:0..2040*/
    /*ECUC_Dcm_00628*/
    uint16 DcmDspPidDataSize;/*Length of data associated to the PID in bit(s). Range:0..2040*/
    /*ECUC_Dcm_00874*/
    /*const Dcm_DspPidDataSupportInfoType *DcmDspPidDataSupportInfo;*/
#if(DCM_OBD_01_SERVICE == STD_ON)
    /*ECUC_Dcm_00894*/
    const Dcm_DspPidService01Type *DcmDspPidService01;
#endif
#if(DCM_OBD_02_SERVICE == STD_ON)
    /*ECUC_Dcm_00895*/
    /*const Dcm_DspPidService02Type *DcmDspPidService02;*/
#endif
} Dcm_DspPidDataType;

/*ECUC_Dcm_00871*/
typedef struct
{
    /*ECUC_Dcm_00873*/
    uint8 DcmDspPidSupportInfoLen;/*Length of the support information in bytes. Range:0..255*/
    /*ECUC_Dcm_00872*/
    uint8 DcmDspPidSupportInfoPos;/*Position of the support information in bytes. Range:0..255*/
} Dcm_DspPidSupportInfoType;

/*ECUC_Dcm_00626*/
typedef struct
{
    /*ECUC_Dcm_00627*/
    uint8 DcmDspPidIdentifier;/*Range:0..255*/
    /*ECUC_Dcm_00893*/
    Dcm_DspPidServiceType DcmDspPidService;
    /*ECUC_Dcm_00870*/
    uint8 DcmDspPidSize;/*Length of a PID in byte(s). Range:0..255*/
#if(DCM_CONFIG_VARIANTS != STD_CONFIG_VARIANTS_POSTBUILD)
    /*ECUC_Dcm_00806*/
    boolean DcmDspPidUsed;
#endif
    /*ECUC_Dcm_00865*/
    uint8 NumOfPidData;/*Range:1..255*/
    const Dcm_DspPidDataType *DcmDspPidData;
    /*ECUC_Dcm_00871*/
    /*uint8 NumOfPidSupportInfo;*//*Range:0..255*/
    /*const Dcm_DspPidSupportInfoType *DcmDspPidSupportInfo;*/
} Dcm_DspPidType;

#endif


#if(DCM_OBD_08_SERVICE == STD_ON)

typedef P2FUNC(Std_ReturnType, DCM_CODE, EcucFncTIDRequestControlDef)
(
    P2VAR(uint8, AUTOMATIC, DCM_VAR) OutBuffer,
    P2VAR(uint8, AUTOMATIC, DCM_VAR) InBuffer
);

/*ECUC_Dcm_00637*/
typedef struct
{
    /*ECUC_Dcm_00722*/
    uint8 DcmDspRequestControlInBufferSize;/*Number of bytes. Range:0..255*/
    /*ECUC_Dcm_00723*/
    uint8 DcmDspRequestControlOutBufferSize;/*Number of bytes. Range:0..255*/
    /*ECUC_Dcm_00656*/
    uint8 DcmDspRequestControlTestId;/*Test Id for Service $08. Range:0..255*/
    /*Function used to control the TID*/
    EcucFncTIDRequestControlDef DcmDspRequestControlFunction;
} Dcm_DspRequestControlType;

#endif


#if(DCM_OBD_09_SERVICE == STD_ON)

/*ECUC_Dcm_00889*//*SWS_Dcm_00688*/
typedef P2FUNC(Std_ReturnType, DCM_CODE, EcucFncVehInfoDataReadDef)
(
    Dcm_OpStatusType OpStatus,
    P2VAR(uint8, AUTOMATIC, DCM_VAR) DataValueBuffer,
    P2VAR(uint8, AUTOMATIC, DCM_VAR) DataValueBufferSize
);

/*ECUC_Dcm_00888*/
typedef struct
{
    /*ECUC_Dcm_00891*/
    uint8 DcmDspVehInfoDataOrder;/*Defines the order of the data item in the InfoType.*/
    /*ECUC_Dcm_00889*/
    EcucFncVehInfoDataReadDef DcmDspVehInfoDataReadFnc;
    /*ECUC_Dcm_00890*/
    uint8 DcmDspVehInfoDataSize;/*Size in bytes of the InfoType data item. Range:0..255*/
    /*ECUC_Dcm_00727*/
    boolean DcmDspVehInfoDataUsePort;
} Dcm_DspVehInfoDataType;

/*ECUC_Dcm_00630*/
typedef struct
{
    /*ECUC_Dcm_00631*/
    uint8 DcmDspVehInfoInfoType;/*Value of InfoType. Range:0..255*/
    /*ECUC_Dcm_01051*/
    boolean DcmDspVehInfoNODIProvResp;
    /*ECUC_Dcm_00888*/
    uint8 NumOfVehInfoData;/*Range:1..255*/
    const Dcm_DspVehInfoDataType *DcmDspVehInfoData;
} Dcm_DspVehInfoType;

#endif

/*******************************************************************************
* OBD type define end
*******************************************************************************/

typedef struct
{
    /*ECUC_Dcm_00805*/
    const boolean *DcmDspDidUsed;
} Dcm_ConfigType;



#endif/*DCM_TYPES_H*/

