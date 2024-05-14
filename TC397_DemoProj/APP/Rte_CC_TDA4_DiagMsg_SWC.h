/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : Rte_CC_TDA4_DiagMsg_SWC.h
********************************************************************************
*   Project/Product : AUTOSAR BSW PROJECT
*   Title           : Rte module configuration File
*   Author          : Hirain
********************************************************************************
*   Description     : Rte module configuration File
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
*   V1.0.2_3.5.5_AZ240046       10/05/2024    Eas           N/A          N/A
*
********************************************************************************
* END_FILE_HDR*/
#ifndef RTE_CC_TDA4_DIAGMSG_SWC_H
#define RTE_CC_TDA4_DIAGMSG_SWC_H

#ifndef RTE_CORE
#ifdef RTE_APPLICATION_HEADER_FILE
#error Multiple application header files included.
#endif /* RTE_APPLICATION_HEADER_FILE */
#define RTE_APPLICATION_HEADER_FILE
#endif
# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

/*******************************************************************************
*   Includes.
*******************************************************************************/
#include "Rte_CC_TDA4_DiagMsg_SWC_Type.h"
#include "Com.h"
#include "Dem.h"
/*******************************************************************************
*   define for a symbolic name of the RunnableEntity.
*******************************************************************************/
#define RTE_RUNNABLE_CC_TDA4_DiagMsg_SWC_10ms               CC_TDA4_DiagMsg_SWC_10ms
/*******************************************************************************
*   Application Error.
*******************************************************************************/
#define RTE_E_DiagnosticInfo_DEM_E_NODATAAVAILABLE          48U
#define RTE_E_DiagnosticInfo_DEM_E_NO_DTC_AVAILABLE         2U
#define RTE_E_DiagnosticInfo_DEM_E_NO_FDC_AVAILABLE         3U
#define RTE_E_DiagnosticInfo_DEM_E_WRONG_BUFFERSIZE         21U
#define RTE_E_DiagnosticInfo_DEM_E_WRONG_DIDNUMBER          50U
#define RTE_E_DiagnosticInfo_DEM_E_WRONG_RECORDNUMBER       49U

/*******************************************************************************
*   Instance Handle
*******************************************************************************/
#ifndef RTE_CORE
typedef CONSTP2CONST(Rte_CDS_CC_TDA4_DiagMsg_SWC, AUTOMATIC, RTE_CONST) Rte_Instance;
#endif

/*******************************************************************************
*   Macro definition.
*******************************************************************************/
#define Rte_Write_ADAS_ECU_Fault_ADAS_ECU_Fault             Rte_Write_CC_TDA4_DiagMsg_SWC_ADAS_ECU_Fault_ADAS_ECU_Fault
#define Rte_Write_ADAS_FrontCamera_Fault_ADAS_FrontCamera_Fault       Rte_Write_CC_TDA4_DiagMsg_SWC_ADAS_FrontCamera_Fault_ADAS_FrontCamera_Fault
#define Rte_Write_ADAS_LeftCamera_Fault_ADAS_LeftCamera_Fault         Rte_Write_CC_TDA4_DiagMsg_SWC_ADAS_LeftCamera_Fault_ADAS_LeftCamera_Fault
#define Rte_Write_ADAS_RearCamera_Fault_ADAS_RearCamera_Fault         Rte_Write_CC_TDA4_DiagMsg_SWC_ADAS_RearCamera_Fault_ADAS_RearCamera_Fault
#define Rte_Write_ADAS_RightCamera_Fault_ADAS_RightCamera_Fault       Rte_Write_CC_TDA4_DiagMsg_SWC_ADAS_RightCamera_Fault_ADAS_RightCamera_Fault
#define Rte_Call_EventInfo_Event_0x940706_GetEventFreezeFrameDataEx(RecordNumber, DataId, DestBuffer, BufSize)          NULL_PTR
#define Rte_Call_Event_Event_0x940604_SetEventStatus(EventStatus)     NULL_PTR
#define Rte_Call_Event_Event_0x940704_SetEventStatus(EventStatus)     NULL_PTR
#define Rte_Call_Event_Event_0x940804_SetEventStatus(EventStatus)     NULL_PTR
#define Rte_Call_Event_Event_0x940904_SetEventStatus(EventStatus)     NULL_PTR
/*******************************************************************************
*   Extended
*******************************************************************************/
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CC_TDA4_DiagMsg_SWC_ADAS_ECU_Fault_ADAS_ECU_Fault
(
    VAR(ADAS_ECU_Fault_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CC_TDA4_DiagMsg_SWC_ADAS_FrontCamera_Fault_ADAS_FrontCamera_Fault
(
    VAR(ADAS_FrontCamera_Fault_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CC_TDA4_DiagMsg_SWC_ADAS_LeftCamera_Fault_ADAS_LeftCamera_Fault
(
    VAR(ADAS_LeftCamera_Fault_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CC_TDA4_DiagMsg_SWC_ADAS_RearCamera_Fault_ADAS_RearCamera_Fault
(
    VAR(ADAS_RearCamera_Fault_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CC_TDA4_DiagMsg_SWC_ADAS_RightCamera_Fault_ADAS_RightCamera_Fault
(
    VAR(ADAS_RightCamera_Fault_IDT, AUTOMATIC) data
);

/*******************************************************************************
*   Runnable Extended
*******************************************************************************/

#define CC_TDA4_DiagMsg_SWC_START_SEC_CODE
#include "CC_TDA4_DiagMsg_SWC_MemMap.h"

extern FUNC(void, CC_TDA4_DiagMsg_SWC_CODE) CC_TDA4_DiagMsg_SWC_10ms
(
    void
);
#define CC_TDA4_DiagMsg_SWC_STOP_SEC_CODE
#include "CC_TDA4_DiagMsg_SWC_MemMap.h"


# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif  /*RTE_CC_TDA4_DIAGMSG_SWC_H*/


