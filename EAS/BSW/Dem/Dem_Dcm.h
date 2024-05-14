/*BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
*   File Name       : Dem_Dcm.h
********************************************************************************
*   Project/Product : AUTOSAR 4.2
*   Title           : Dem_Dcm.h
*   Author          : Hirain
********************************************************************************
*   Description: for Dem APIs used by the Dcm exclusively.
*
********************************************************************************
*   Limitations:
*
********************************************************************************
*
********************************************************************************
*   Revision History:
*   Reference to Core C File
********************************************************************************
*END_FILE_HDR*/

#ifndef DEM_DCM_H
#define DEM_DCM_H

/*******************************************************************************
* Include files
*******************************************************************************/
#include "Dem_Types.h"
#include "Dem_Version.h"
#if((DEM_CFG_OBD_SUPPORT == DEM_OBD_MASTER_ECU)||(DEM_CFG_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU))
#include "Dcm_Types.h"
#endif

/*******************************************************************************
* Global Function Prototype
*******************************************************************************/

#define DEM_START_SEC_CODE
#include "MemMap.h"

/*SWS_Dem_00230*/
extern FUNC(Dem_DTCTranslationFormatType, DEM_CODE) Dem_DcmGetTranslationType
(
    void
);
/*SWS_Dem_00213*/
extern FUNC(Std_ReturnType, DEM_CODE) Dem_DcmGetDTCStatusAvailabilityMask
(
    P2VAR(Dem_UdsStatusByteType, AUTOMATIC, DEM_APPL_DATA) DTCStatusMask
);
/*SWS_Dem_00212*/
extern FUNC(Dem_ReturnGetStatusOfDTCType, DEM_CODE) Dem_DcmGetStatusOfDTC
(
    uint32 DTC,
    Dem_DTCOriginType DTCOrigin,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DTCStatus
);
/*SWS_Dem_00232*/
extern FUNC(Dem_ReturnGetSeverityOfDTCType, DEM_CODE) Dem_DcmGetSeverityOfDTC
(
    uint32 DTC,
    P2VAR(Dem_DTCSeverityType, AUTOMATIC, DEM_APPL_DATA) DTCSeverity
);
/*SWS_Dem_00594*/
extern FUNC(Dem_ReturnGetFunctionalUnitOfDTCType, DEM_CODE) Dem_DcmGetFunctionalUnitOfDTC
(
    uint32 DTC,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DTCFunctionalUnit
);
/*SWS_Dem_00208*/
extern FUNC(Dem_ReturnSetFilterType, DEM_CODE) Dem_DcmSetDTCFilter
(
    Dem_UdsStatusByteType DTCStatusMask,
    Dem_DTCKindType DTCKind,
    Dem_DTCFormatType DTCFormat,
    Dem_DTCOriginType DTCOrigin,
    boolean FilterWithSeverity,
    Dem_DTCSeverityType DTCSeverityMask,
    boolean FilterForFaultDetectionCounter/*no use*/
);
/*SWS_Dem_00214*/
extern FUNC(Dem_ReturnGetNumberOfFilteredDTCType, DEM_CODE) Dem_DcmGetNumberOfFilteredDTC
(
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) NumberOfFilteredDTC
);
/*SWS_Dem_00215*/
extern FUNC(Dem_ReturnGetNextFilteredElementType, DEM_CODE) Dem_DcmGetNextFilteredDTC
(
    P2VAR(uint32, AUTOMATIC, DEM_APPL_DATA) DTC,
    P2VAR(Dem_UdsStatusByteType, AUTOMATIC, DEM_APPL_DATA) DTCStatus
);
/*SWS_Dem_00227*/
extern FUNC(Dem_ReturnGetNextFilteredElementType, DEM_CODE) Dem_DcmGetNextFilteredDTCAndFDC
(
    P2VAR(uint32, AUTOMATIC, DEM_APPL_DATA) DTC,
    P2VAR(sint8, AUTOMATIC, DEM_APPL_DATA) DTCFaultDetectionCounter
);
/*SWS_Dem_00281*/
extern FUNC(Dem_ReturnGetNextFilteredElementType, DEM_CODE) Dem_DcmGetNextFilteredDTCAndSeverity
(
    P2VAR(uint32, AUTOMATIC, DEM_APPL_DATA) DTC,
    P2VAR(Dem_UdsStatusByteType, AUTOMATIC, DEM_APPL_DATA) DTCStatus,
    P2VAR(Dem_DTCSeverityType, AUTOMATIC, DEM_APPL_DATA) DTCSeverity,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DTCFunctionalUnit
);
/*SWS_Dem_00209*/
extern FUNC(Dem_ReturnSetFilterType, DEM_CODE) Dem_DcmSetFreezeFrameRecordFilter
(
    Dem_DTCFormatType DTCFormat,
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) NumberOfFilteredRecords
);
/*SWS_Dem_00224*/
extern FUNC(Dem_ReturnGetNextFilteredElementType, DEM_CODE) Dem_DcmGetNextFilteredRecord
(
    P2VAR(uint32, AUTOMATIC, DEM_APPL_DATA) DTC,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) RecordNumber
);
/*SWS_Dem_00218*/
extern FUNC(Dem_ReturnGetDTCByOccurrenceTimeType, DEM_CODE) Dem_DcmGetDTCByOccurrenceTime
(
    Dem_DTCRequestType DTCRequest,
    P2VAR(uint32, AUTOMATIC, DEM_APPL_DATA) DTC
);
#if(DEM_CFG_TRIGGER_DCM_REPORTS == STD_ON)
/*SWS_Dem_00846*/
extern FUNC(void, DEM_CODE) Dem_DcmControlDTCStatusChangedNotification
(
    boolean TriggerNotification
);
#endif

/*SWS_Dem_00233*/
extern FUNC(Dem_ReturnDisableDTCRecordUpdateType, DEM_CODE) Dem_DcmDisableDTCRecordUpdate
(
    uint32 DTC,
    Dem_DTCOriginType DTCOrigin
);
/*SWS_Dem_00234*/
extern FUNC(Std_ReturnType, DEM_CODE) Dem_DcmEnableDTCRecordUpdate
(
    void
);
/*SWS_Dem_00236*/
extern FUNC(Dem_ReturnGetFreezeFrameDataByDTCType, DEM_CODE) Dem_DcmGetFreezeFrameDataByDTC
(
    uint32 DTC,
    Dem_DTCOriginType DTCOrigin,
    uint8 RecordNumber,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DestBuffer,
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) BufSize
);
/*SWS_Dem_00238*/
extern FUNC(Dem_ReturnGetSizeOfDataByDTCType, DEM_CODE) Dem_DcmGetSizeOfFreezeFrameByDTC
(
    uint32 DTC,
    Dem_DTCOriginType DTCOrigin,
    uint8 RecordNumber,
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) SizeOfFreezeFrame
);
/*SWS_Dem_00239*/
extern FUNC(Dem_ReturnGetExtendedDataRecordByDTCType, DEM_CODE) Dem_DcmGetExtendedDataRecordByDTC
(
    uint32 DTC,
    Dem_DTCOriginType DTCOrigin,
    uint8 ExtendedDataNumber,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DestBuffer,
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) BufSize
);
/*SWS_Dem_00240*/
extern FUNC(Dem_ReturnGetSizeOfDataByDTCType, DEM_CODE) Dem_DcmGetSizeOfExtendedDataRecordByDTC
(
    uint32 DTC,
    Dem_DTCOriginType DTCOrigin,
    uint8 ExtendedDataNumber,
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) SizeOfExtendedDataRecord
);


/*SWS_Dem_01196*/
extern FUNC(Dem_ReturnClearDTCType, DEM_CODE) Dem_DcmCheckClearParameter
(
    uint32 DTC,
    Dem_DTCFormatType DTCFormat,
    Dem_DTCOriginType DTCOrigin
);
/*SWS_Dem_00241*/
extern FUNC(Dem_ReturnClearDTCType, DEM_CODE) Dem_DcmClearDTC
(
    uint32 DTC,
    Dem_DTCFormatType DTCFormat,
    Dem_DTCOriginType DTCOrigin
);
/*SWS_Dem_00242*/
extern FUNC(Dem_ReturnControlDTCSettingType, DEM_CODE) Dem_DcmDisableDTCSetting
(
    uint32 DTCGroup,
    Dem_DTCKindType DTCKind
);
/*SWS_Dem_00243*/
extern FUNC(Dem_ReturnControlDTCSettingType, DEM_CODE) Dem_DcmEnableDTCSetting
(
    uint32 DTCGroup,
    Dem_DTCKindType DTCKind
);




#if((DEM_CFG_OBD_SUPPORT == DEM_OBD_MASTER_ECU)||(DEM_CFG_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU))

#if(DEM_CFG_OBD_ENGINE_TYPE == DEM_IGNITION_SPARK)
/*SWS_Dem_00316*/
extern FUNC(Std_ReturnType, DEM_CODE) Dem_DcmGetInfoTypeValue08
(
    Dcm_OpStatusType OpStatus,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) Iumprdata08,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) Iumprdata08BufferSize
);
#endif

#if(DEM_CFG_OBD_ENGINE_TYPE == DEM_IGNITION_COMPRESSION)
/*SWS_Dem_00317*/
extern FUNC(Std_ReturnType, DEM_CODE) Dem_DcmGetInfoTypeValue0B
(
    Dcm_OpStatusType OpStatus,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) Iumprdata0B,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) Iumprdata0BBufferSize
);
#endif

/*SWS_Dem_00318*/
extern FUNC(Std_ReturnType, DEM_CODE) Dem_DcmReadDataOfPID01
(
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) PID01value
);

/*SWS_Dem_00325*/
extern FUNC(Std_ReturnType, DEM_CODE) Dem_DcmReadDataOfPID1C
(
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) PID1Cvalue
);

/*SWS_Dem_00319*/
extern FUNC(Std_ReturnType, DEM_CODE) Dem_DcmReadDataOfPID21
(
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) PID21value
);

/*SWS_Dem_00320*/
extern FUNC(Std_ReturnType, DEM_CODE) Dem_DcmReadDataOfPID30
(
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) PID30value
);

/*SWS_Dem_00321*/
extern FUNC(Std_ReturnType, DEM_CODE) Dem_DcmReadDataOfPID31
(
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) PID31value
);

/*SWS_Dem_00322*/
extern FUNC(Std_ReturnType, DEM_CODE) Dem_DcmReadDataOfPID41
(
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) PID41value
);

/*SWS_Dem_00323*/
extern FUNC(Std_ReturnType, DEM_CODE) Dem_DcmReadDataOfPID4D
(
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) PID4Dvalue
);

/*SWS_Dem_00324*/
extern FUNC(Std_ReturnType, DEM_CODE) Dem_DcmReadDataOfPID4E
(
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) PID4Evalue
);

/*SWS_Dem_01187*/
extern FUNC(Std_ReturnType, DEM_CODE) Dem_DcmReadDataOfPID91
(
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) PID91value
);

/*SWS_Dem_00327*/
extern FUNC(Std_ReturnType, DEM_CODE) Dem_DcmReadDataOfOBDFreezeFrame
(
    uint8 PID,
    uint8 DataElementIndexOfPID,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DestBuffer,
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) BufSize
);

/*SWS_Dem_00624*/
extern FUNC(Std_ReturnType, DEM_CODE) Dem_DcmGetDTCOfOBDFreezeFrame
(
    uint8 FrameNumber,
    P2VAR(uint32, AUTOMATIC, DEM_APPL_DATA) DTC,
    Dem_DTCFormatType DTCFormat
);

/*SWS_Dem_00766*/
extern FUNC(Std_ReturnType, DEM_CODE) Dem_DcmGetAvailableOBDMIDs
(
    uint8 Obdmid,
    P2VAR(uint32, AUTOMATIC, DEM_APPL_DATA) Obdmidvalue
);

/*SWS_Dem_00767*/
extern FUNC(Std_ReturnType, DEM_CODE) Dem_DcmGetNumTIDsOfOBDMID
(
    uint8 Obdmid,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) numberOfTIDs
);

/*SWS_Dem_00768*/
extern FUNC(Std_ReturnType, DEM_CODE) Dem_DcmGetDTRData
(
    uint8 Obdmid,
    uint8 TIDindex,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) TIDvalue,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) UaSID,
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) Testvalue,
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) Lowlimvalue,
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) Upplimvalue
);

/*SWS_Dem_01168*/
extern FUNC(Std_ReturnType, DEM_CODE) Dem_DcmGetDTCSeverityAvailabilityMask
(
    P2VAR(Dem_DTCSeverityType, AUTOMATIC, DEM_APPL_DATA) DTCSeverityMask
);
#endif/*#if((DEM_CFG_OBD_SUPPORT == DEM_OBD_MASTER_ECU)||(DEM_CFG_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU))*/

#define DEM_STOP_SEC_CODE
#include "MemMap.h"

#endif /* DEM_DCM_H */


