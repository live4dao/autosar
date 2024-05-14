/*BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
*   File Name       : Dem_J1939Dcm.h
********************************************************************************
*   Project/Product : AUTOSAR 4.2
*   Title           : Dem_J1939Dcm.h
*   Author          : Hirain
********************************************************************************
*   Description: for Dem APIs used by the J1939Dcm exclusively.
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

#ifndef DEM_J1939DCM_H
#define DEM_J1939DCM_H

/*******************************************************************************
* Include files
*******************************************************************************/
#include "Dem_Types.h"
#include "Dem_Version.h"

/*******************************************************************************
* Global Function Prototype
*******************************************************************************/

#define DEM_START_SEC_CODE
#include "MemMap.h"

#if(DEM_J1939_SUPPORT == STD_ON)
/*******************************************************************************
* Access DTCs and Status Information
*******************************************************************************/
#if(STD_ON == DEM_CFG_J1939READING_DTC_SUPPORT)
/*SWS_Dem_00970*/
extern FUNC(Dem_ReturnSetFilterType, DEM_CODE) Dem_J1939DcmSetDTCFilter
(
    Dem_J1939DcmDTCStatusFilterType DTCStatusFilter,
    Dem_DTCKindType DTCKind,
    uint8 node,
    P2VAR(Dem_J1939DcmLampStatusType, AUTOMATIC, DEM_APPL_DATA) LampStatus
);

/*SWS_Dem_00972*/
extern FUNC(Dem_ReturnGetNumberOfFilteredDTCType, DEM_CODE) Dem_J1939DcmGetNumberOfFilteredDTC
(
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) NumberOfFilteredDTC
);

/*SWS_Dem_00973*/
extern FUNC(Dem_ReturnGetNextFilteredElementType, DEM_CODE) Dem_J1939DcmGetNextFilteredDTC
(
    P2VAR(uint32, AUTOMATIC, DEM_APPL_DATA) J1939DTC,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) OccurenceCounter
);
#endif

#if(STD_ON == DEM_CFG_J1939DM31_SUPPORT)
/*SWS_Dem_00974*/
extern FUNC(void, DEM_CODE) Dem_J1939DcmFirstDTCwithLampStatus
(
    uint8 node
);

/*SWS_Dem_00975*/
extern FUNC(Dem_ReturnGetNextFilteredElementType, DEM_CODE) Dem_J1939DcmGetNextDTCwithLampStatus
(
    P2VAR(Dem_J1939DcmLampStatusType, AUTOMATIC, DEM_APPL_DATA) LampStatus,
    P2VAR(uint32, AUTOMATIC, DEM_APPL_DATA) J1939DTC,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) OccurenceCounter
);
#endif
/*******************************************************************************
* DTC storage
*******************************************************************************/
#if(STD_ON == DEM_CFG_J1939CLEAR_DTC_SUPPORT)
/*SWS_Dem_00976*/
extern FUNC(Dem_ReturnClearDTCType, DEM_CODE) Dem_J1939DcmClearDTC
(
    Dem_J1939DcmSetClearFilterType DTCTypeFilter,
    uint8 node
);
#endif

#if((STD_ON == DEM_CFG_J1939EX_FF_SUPPORT)||(STD_ON == DEM_CFG_J1939_FF_SUPPORT))
/*SWS_Dem_00977*/
extern FUNC(Dem_ReturnSetFilterType, DEM_CODE) Dem_J1939DcmSetFreezeFrameFilter
(
    Dem_J1939DcmSetFreezeFrameFilterType FreezeFrameKind,
    uint8 node
);

/*SWS_Dem_00978*/
extern FUNC(Dem_ReturnGetNextFilteredElementType, DEM_CODE) Dem_J1939DcmGetNextFreezeFrame
(
    P2VAR(uint32, AUTOMATIC, DEM_APPL_DATA) J1939DTC,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) OccurenceCounter,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DestBuffer,
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) BufSize
);
#endif

#if(STD_ON == DEM_CFG_J1939EX_FF_SUPPORT)
/*SWS_Dem_00979*/
extern FUNC(Dem_ReturnGetNextFilteredElementType, DEM_CODE) Dem_J1939DcmGetNextSPNInFreezeFrame
(
    P2VAR(uint32, AUTOMATIC, DEM_APPL_DATA) SPNSupported,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) SPNDataLength
);
#endif
/*******************************************************************************
* Reporting
*******************************************************************************/
#if(STD_ON == DEM_CFG_J1939_RATIO_SUPPORT)
/*SWS_Dem_00980*/
extern FUNC(Dem_ReturnSetFilterType, DEM_CODE) Dem_J1939DcmSetRatioFilter
(
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) IgnitionCycleCounter,
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) OBDMonitoringConditionsEncountered,
    uint8 node
);

/*SWS_Dem_00981*/
extern FUNC(Dem_ReturnGetNextFilteredElementType, DEM_CODE) Dem_J1939DcmGetNextFilteredRatio
(
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) SPN,
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) Numerator,
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) Denominator
);
#endif

#if(STD_ON == DEM_CFG_J1939READINESS_1_SUPPORT)
/*SWS_Dem_00982*/
extern FUNC(Std_ReturnType, DEM_CODE) Dem_J1939DcmReadDiagnosticReadiness1
(
    P2VAR(Dem_J1939DcmDiagnosticReadiness1Type, AUTOMATIC, DEM_APPL_DATA) DataValue,
    uint8 node
);
#endif

#if(STD_ON == DEM_CFG_J1939READINESS_2_SUPPORT)
/*SWS_Dem_00983*/
extern FUNC(Std_ReturnType, DEM_CODE) Dem_J1939DcmReadDiagnosticReadiness2
(
    P2VAR(Dem_J1939DcmDiagnosticReadiness2Type, AUTOMATIC, DEM_APPL_DATA) DataValue,
    uint8 node
);
#endif

#if(STD_ON == DEM_CFG_J1939READINESS_3_SUPPORT)
/*SWS_Dem_00770*/
extern FUNC(Std_ReturnType, DEM_CODE) Dem_J1939DcmReadDiagnosticReadiness3
(
    P2VAR(Dem_J1939DcmDiagnosticReadiness3Type, AUTOMATIC, DEM_APPL_DATA) DataValue,
    uint8 node
);
#endif
#endif/*#if(DEM_J1939_SUPPORT == STD_ON)*/

#define DEM_STOP_SEC_CODE
#include "MemMap.h"

#endif/* DEM_J1939DCM_H */


