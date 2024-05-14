/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : CC_TDA4_DiagMsg_SWC.c
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
/*******************************************************************************
*   Includes.
*******************************************************************************/
#include "Rte_CC_TDA4_DiagMsg_SWC.h"

/* CC_TDA4_DiagMsg_SWCInput File User Code start*/

/* CC_TDA4_DiagMsg_SWCInput File User Code end*/

/* CC_TDA4_DiagMsg_SWC.c Custom Code (#define variable etc.) User Code start*/

/* CC_TDA4_DiagMsg_SWC.c Custom Code (#define variable etc.) User Code end*/

/*******************************************************************************
*   Runnable Extended
*******************************************************************************/

#define CC_TDA4_DiagMsg_SWC_START_SEC_CODE
#include "CC_TDA4_DiagMsg_SWC_MemMap.h"

FUNC(void, CC_TDA4_DiagMsg_SWC_CODE) CC_TDA4_DiagMsg_SWC_10ms
(
    void
)
{
    /* CC_TDA4_DiagMsg_SWC_10ms_Start User Code start*/

    /* CC_TDA4_DiagMsg_SWC_10ms_Start User Code end*/
    ADAS_ECU_Fault_IDT Write_ADAS_ECU_Fault_ADAS_ECU_Fault;
    ADAS_FrontCamera_Fault_IDT Write_ADAS_FrontCamera_Fault_ADAS_FrontCamera_Fault;
    ADAS_LeftCamera_Fault_IDT Write_ADAS_LeftCamera_Fault_ADAS_LeftCamera_Fault;
    ADAS_RearCamera_Fault_IDT Write_ADAS_RearCamera_Fault_ADAS_RearCamera_Fault;
    ADAS_RightCamera_Fault_IDT Write_ADAS_RightCamera_Fault_ADAS_RightCamera_Fault;
    uint8 Call_EventInfo_Event_0x940706_GetEventFreezeFrameDataEx_RecordNumber;
    uint16 Call_EventInfo_Event_0x940706_GetEventFreezeFrameDataEx_DataId;
    Dem_MaxDataValueType Call_EventInfo_Event_0x940706_GetEventFreezeFrameDataEx_DestBuffer;
    uint16 Call_EventInfo_Event_0x940706_GetEventFreezeFrameDataEx_BufSize;
    Dem_EventStatusType Call_Event_Event_0x940604_SetEventStatus_EventStatus;
    Dem_EventStatusType Call_Event_Event_0x940704_SetEventStatus_EventStatus;
    Dem_EventStatusType Call_Event_Event_0x940804_SetEventStatus_EventStatus;
    Dem_EventStatusType Call_Event_Event_0x940904_SetEventStatus_EventStatus;
    /* CC_TDA4_DiagMsg_SWC_10ms Varaible Define User Code start*/

    /* CC_TDA4_DiagMsg_SWC_10ms Varaible Define User Code end*/




    Rte_Write_ADAS_ECU_Fault_ADAS_ECU_Fault(Write_ADAS_ECU_Fault_ADAS_ECU_Fault);
    /* Rte_Write_ADAS_ECU_Fault_ADAS_ECU_Fault User Code start*/

    /* Rte_Write_ADAS_ECU_Fault_ADAS_ECU_Fault User Code end*/
    Rte_Write_ADAS_FrontCamera_Fault_ADAS_FrontCamera_Fault(Write_ADAS_FrontCamera_Fault_ADAS_FrontCamera_Fault);
    /* Rte_Write_ADAS_FrontCamera_Fault_ADAS_FrontCamera_Fault User Code start*/

    /* Rte_Write_ADAS_FrontCamera_Fault_ADAS_FrontCamera_Fault User Code end*/
    Rte_Write_ADAS_LeftCamera_Fault_ADAS_LeftCamera_Fault(Write_ADAS_LeftCamera_Fault_ADAS_LeftCamera_Fault);
    /* Rte_Write_ADAS_LeftCamera_Fault_ADAS_LeftCamera_Fault User Code start*/

    /* Rte_Write_ADAS_LeftCamera_Fault_ADAS_LeftCamera_Fault User Code end*/
    Rte_Write_ADAS_RearCamera_Fault_ADAS_RearCamera_Fault(Write_ADAS_RearCamera_Fault_ADAS_RearCamera_Fault);
    /* Rte_Write_ADAS_RearCamera_Fault_ADAS_RearCamera_Fault User Code start*/

    /* Rte_Write_ADAS_RearCamera_Fault_ADAS_RearCamera_Fault User Code end*/
    Rte_Write_ADAS_RightCamera_Fault_ADAS_RightCamera_Fault(Write_ADAS_RightCamera_Fault_ADAS_RightCamera_Fault);
    /* Rte_Write_ADAS_RightCamera_Fault_ADAS_RightCamera_Fault User Code start*/

    /* Rte_Write_ADAS_RightCamera_Fault_ADAS_RightCamera_Fault User Code end*/
    Rte_Call_EventInfo_Event_0x940706_GetEventFreezeFrameDataEx(Call_EventInfo_Event_0x940706_GetEventFreezeFrameDataEx_RecordNumber,Call_EventInfo_Event_0x940706_GetEventFreezeFrameDataEx_DataId,&Call_EventInfo_Event_0x940706_GetEventFreezeFrameDataEx_DestBuffer,&Call_EventInfo_Event_0x940706_GetEventFreezeFrameDataEx_BufSize);
    /* Rte_Call_EventInfo_Event_0x940706_GetEventFreezeFrameDataEx User Code start*/

    /* Rte_Call_EventInfo_Event_0x940706_GetEventFreezeFrameDataEx User Code end*/
    Rte_Call_Event_Event_0x940604_SetEventStatus(Call_Event_Event_0x940604_SetEventStatus_EventStatus);
    /* Rte_Call_Event_Event_0x940604_SetEventStatus User Code start*/

    /* Rte_Call_Event_Event_0x940604_SetEventStatus User Code end*/
    Rte_Call_Event_Event_0x940704_SetEventStatus(Call_Event_Event_0x940704_SetEventStatus_EventStatus);
    /* Rte_Call_Event_Event_0x940704_SetEventStatus User Code start*/

    /* Rte_Call_Event_Event_0x940704_SetEventStatus User Code end*/
    Rte_Call_Event_Event_0x940804_SetEventStatus(Call_Event_Event_0x940804_SetEventStatus_EventStatus);
    /* Rte_Call_Event_Event_0x940804_SetEventStatus User Code start*/

    /* Rte_Call_Event_Event_0x940804_SetEventStatus User Code end*/
    Rte_Call_Event_Event_0x940904_SetEventStatus(Call_Event_Event_0x940904_SetEventStatus_EventStatus);
    /* Rte_Call_Event_Event_0x940904_SetEventStatus User Code start*/

    /* Rte_Call_Event_Event_0x940904_SetEventStatus User Code end*/
    /* CC_TDA4_DiagMsg_SWC_10ms_Feedback User Code start*/

    /* CC_TDA4_DiagMsg_SWC_10ms_Feedback User Code end*/

}
#define CC_TDA4_DiagMsg_SWC_STOP_SEC_CODE
#include "CC_TDA4_DiagMsg_SWC_MemMap.h"




