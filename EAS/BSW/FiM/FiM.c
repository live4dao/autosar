/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
*   File Name       : FiM.c
********************************************************************************
*   Project/Product : AUTOSAR 4.2
*   Title           : FiM module Source File
*   Author          : Hirain
********************************************************************************
*   Description     : FiM module Source File
*
********************************************************************************
*   Limitations     : None
*
********************************************************************************
*
********************************************************************************
*   Revision History:
*
*   Version     Date          Initials        CR#        Descriptions
*   ---------   ----------    ------------  ----------   ---------------
*   01.00.00    05/10/2019    Xin.Yang        N/A         Beta 
*   01.00.01    14/12/2020    Xin.Yang        N/A         Beta 
*   01.00.02    18/03/2022    Xin.Yang        N/A         EAS422_FiM_20220318_01
********************************************************************************
* END_FILE_HDR*/

/*******************************************************************************
*   Includes
*******************************************************************************/
#include "FiM.h"
#include "FiM_Version.h"
#include "Dem.h"/*SWS_Fim_00031 */
#include "FiM_Cfg.h"
#include "FiM_Lcfg.h"

#if (STD_ON == FIM_DEV_ERROR_DETECT)
#include "Det.h"
#endif
/*******************************************************************************
*   Version Check
*******************************************************************************/
#if(STD_ON == FIM_PRIVATE_VERSION_CHECK)
/* check Version with other import module */

/* check Version with cfg file */
#if ((FIM_AR_RELEASE_MAJOR_VERSION != FIM_AR_RELEASE_MAJOR_VERSION_CFG) || \
   (FIM_AR_RELEASE_MINOR_VERSION != FIM_AR_RELEASE_MINOR_VERSION_CFG))
#error "AutoSar Version Numbers of FIM and its cfg file are different"
#endif

#if ((FIM_SW_MAJOR_VERSION != FIM_SW_MAJOR_VERSION_CFG) || \
   (FIM_SW_MINOR_VERSION != FIM_SW_MINOR_VERSION_CFG))
#error "SW Version Numbers of FIM and its cfg file are different"
#endif

#endif/*#if(STD_ON == FIM_PRIVATE_VERSION_CHECK)*/

/*******************************************************************************
*  Macros
*******************************************************************************/
#if(STD_ON == FIM_DEV_ERROR_DETECT)

#define FIM_DET_REPORT_ERROR(ApiId, errcode)  \
    DET_REPORT_ERROR(FIM_MODULE_ID, FIM_INSTANCE_ID, (ApiId), (errcode))/*SWS_Fim_00080*/
#else
#define FIM_DET_REPORT_ERROR(ApiId, errcode)

#endif

/*******************************************************************************
*   Local Data Define
*******************************************************************************/
#define FIM_START_SEC_VAR_INIT_8
#include "MemMap.h"
STATIC VAR(FiM_InitType, FIM_VAR) FiM_InitStatus = FIM_UNINITIALIZED;
#define FIM_STOP_SEC_VAR_INIT_8
#include "MemMap.h"


#define FIM_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
STATIC P2CONST(FiM_ConfigType, FIM_VAR, FIM_CONST) FiM_ConfigPtr = NULL_PTR;
#define FIM_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"


/*******************************************************************************
*   Local Functions declare
*******************************************************************************/
#define FIM_START_SEC_CODE
#include "MemMap.h"
#if(FIM_DEM_COMPONENT_SUPPORT == STD_ON)
/*function for calculating Component is failed or not*/
STATIC FUNC(boolean,FIM_CODE)FiM_CalculatePermissionByComponent
(
    FiM_FunctionIdType FunctionID
#if(FIM_EVENT_UPDATE_TRIGGERED_BY_DEM == STD_OFF && FIM_QUARY_MODE == FIM_CYCLICALLY)
    ,Dem_ComponentIdType *ComponentIDPtr
#endif
);
#endif
/*function for calculating Event occurs or not*/
#if(FIM_EVENT_UPDATE_TRIGGERED_BY_DEM == STD_OFF)
STATIC FUNC(boolean,FIM_CODE)FiM_CalculatePermissionByEvent
(
    FiM_FunctionIdType FunctionID
);
#endif
/*judge status is equal to mask or not*/
STATIC FUNC(boolean,FIM_CODE)FiM_InhibitionCalculation
(
    Dem_UdsStatusByteType Status,
    FiM_InhibitionMaskType Mask
);
/*calculate all FIDs' permission cyclically*/
#if(FIM_EVENT_UPDATE_TRIGGERED_BY_DEM == STD_OFF && FIM_QUARY_MODE == FIM_CYCLICALLY)
STATIC FUNC(void,FIM_CODE) FiM_QuaryAllFunction
(
    void
);
#endif
/*******************************************************************************
*   Local Functions define
*******************************************************************************/


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name : FiM_Init
*
* Description   : This function initializes the FIM module.
*
* Inputs        : -configPtr:Pointer to selected configuration structure.
*
* Outputs       : None
*
* return        : None
*
* Limitations   : None
********************************************************************************
END_FUNCTION_HDR */

FUNC(void, FIM_CODE) FiM_Init/*SWS_Fim_00077*/
( 
    P2CONST(FiM_ConfigType, AUTOMATIC, FIM_CONST) configPtr
)
{
    uint16 FunctionIndex = (uint16)0;
#if(FIM_EVENT_UPDATE_TRIGGERED_BY_DEM == STD_ON)
    uint16 EventIndex = (uint16)0;
#endif
#if(FIM_CONFIG_VARIANTS == STD_CONFIG_VARIANTS_POSTBUILD)
    if(NULL_PTR == configPtr)
    {
        FIM_DET_REPORT_ERROR(FIM_INIT_API_ID, FIM_E_PARAM_POINTER);
    }
    else
#else
    (void)configPtr;
#endif
#if(FIM_CONFIG_VARIANTS == STD_CONFIG_VARIANTS_POSTBUILD)	
    {
        FiM_ConfigPtr = configPtr;/*SWS_Fim_00008*/
#else
    FiM_ConfigPtr = &FiM_Config;
#endif
    for(FunctionIndex = (uint16)0; FunctionIndex < FIM_FUNCTION_NUM_CFG; FunctionIndex++)/*initialize global variables*/
    {
        FiM_Availability[FunctionIndex] = FiM_AvailabilityCfg[FunctionIndex];
        FiM_Permission[FunctionIndex] = FALSE;
    }
#if(FIM_EVENT_UPDATE_TRIGGERED_BY_DEM == STD_ON)
    for(EventIndex = (uint16)0; EventIndex < FIM_EVENT_NUM_CFG; EventIndex++)
    {
        for(FunctionIndex = (uint16)0; FunctionIndex < FiM_EventCfg[EventIndex].FunctionNum; FunctionIndex++)
        {
            FiM_EventCfg[EventIndex].EventNotOccuredFlag[FunctionIndex] = FIM_EVENT_OCCURED;
        }
    }
#endif
    FiM_InitStatus = FIM_INITIALIZED;/*SWS_Fim_00059*/
#if(FIM_CONFIG_VARIANTS == STD_CONFIG_VARIANTS_POSTBUILD)
    }
#endif
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name : FiM_GetFunctionPermission
*
* Description   : Reports the permission state to the functionality.
*
* Inputs        : FID
*
* Outputs       : PERMISSITION
*
* return        : E_OK: The request is accepted;E_NOT_OK: The request is not accepted,ie. initialization of FIM not completed
*
* Limitations   : None
********************************************************************************
END_FUNCTION_HDR */

FUNC(Std_ReturnType, FIM_CODE) FiM_GetFunctionPermission/*SWS_Fim_00020*//*SWS_Fim_00011*/

( 
    FiM_FunctionIdType FID,
    P2VAR(boolean, AUTOMATIC, FIM_APPL_DATA) Permission
)
{
    Std_ReturnType ret = E_NOT_OK;
#if(FIM_EVENT_UPDATE_TRIGGERED_BY_DEM == STD_OFF && FIM_QUARY_MODE == FIM_ON_CALL_FUNCTION)
    boolean Per = FALSE;
#else
#endif
    if(FiM_InitStatus != FIM_INITIALIZED_FULL)/*SWS_Fim_00056*//*SWS_Fim_00104*/
    {
        FIM_DET_REPORT_ERROR(FIM_GET_FUNCTION_PERMISSION_API_ID,  FIM_E_UNINIT);
    }
    else if(Permission == NULL_PTR)
    {
        FIM_DET_REPORT_ERROR(FIM_GET_FUNCTION_PERMISSION_API_ID, FIM_E_PARAM_POINTER);
    }
    else if(FID > FIM_FUNCTION_ID_MAX)/*SWS_Fim_00055*/
    {
        FIM_DET_REPORT_ERROR(FIM_GET_FUNCTION_PERMISSION_API_ID,  FIM_E_FID_OUT_OF_RANGE);
    }
    else if(FiM_Availability[FID] == FALSE)/*SWS_Fim_00105*/
    {
        /*do nothing*/
    }
    else
    {
#if(FIM_EVENT_UPDATE_TRIGGERED_BY_DEM == STD_OFF && FIM_QUARY_MODE == FIM_ON_CALL_FUNCTION)
        if(FALSE == FiM_CalculatePermissionByEvent(FID))
        {
            /*do nothing*/
        }
        else
        {
#if(FIM_DEM_COMPONENT_SUPPORT == STD_OFF)
            Per = TRUE;
#else
            if(FALSE == FiM_CalculatePermissionByComponent(FID))
            {
                /*do nothing*/
            }
            else
            {
                Per = TRUE;
            }
#endif
        }
        *Permission = Per;
#else
        *Permission = FiM_Permission[FID];
#endif
        ret = E_OK;
    }
    return ret;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name : FiM_SetFunctionAvailable
*
* Description   : Sets the availability of a function. The function is only available if FiMAvailabilitySupport is configured as True.
*
* Inputs        : FID,Availability
*
* Outputs       : None
*
* return        : E_OK: The request is accepted;E_NOT_OK: The request is not accepted.
*
* Limitations   : None
********************************************************************************
END_FUNCTION_HDR */
#if(FIM_AVAILABILITY_SUPPORT == STD_ON)
FUNC(Std_ReturnType,FIM_CODE) FiM_SetFunctionAvailable/*SWS_Fim_00106*/
(
    FiM_FunctionIdType FID,
    boolean Availability
)
{
    Std_ReturnType ret = E_NOT_OK;

    if(FiM_InitStatus == FIM_UNINITIALIZED)
    {
        FIM_DET_REPORT_ERROR(FIM_SET_FUNCTION_AVAILABLE_API_ID , FIM_E_UNINIT);
    }
    else if(FID > FIM_FUNCTION_ID_MAX)
    {
        FIM_DET_REPORT_ERROR(FIM_SET_FUNCTION_AVAILABLE_API_ID,  FIM_E_FID_OUT_OF_RANGE);
    }
    else
    {
        FiM_Availability[FID] = Availability;
        ret = E_OK;
    }
    return  ret;
}
#endif


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name : FiM_DemTriggerOnEventStatus
*
* Description   : Provided by the Dem in order to call FiM upon status changes.
*
* Inputs        : EventId,EventStatusByteOld,EventStatusByteNew
*
* Outputs       : None
*
* return        : None
*
* Limitations   : None
********************************************************************************
END_FUNCTION_HDR */
#if(FIM_EVENT_UPDATE_TRIGGERED_BY_DEM == STD_ON)/*SWS_Fim_00073*/
FUNC(void,FIM_CODE) FiM_DemTriggerOnEventStatus/*SWS_Fim_00021*/
(
    Dem_EventIdType EventId,
    Dem_UdsStatusByteType EventStatusByteOld,
    Dem_UdsStatusByteType EventStatusByteNew
)
{
    uint16 FunctionIndex = (uint16)0;    
    uint16 FunctionIndex1 = (uint16)0; 
    uint16 EventIndex = (uint16)0;
    uint16 tempEventIndex = (uint16)0;
    FiM_FunctionIdType FID = (FiM_FunctionIdType)0;
    FiM_InhibitionMaskType Mask = (FiM_InhibitionMaskType)0;

    if(FiM_InitStatus != FIM_INITIALIZED_FULL)/*SWS_Fim_00058*/
    {
        FIM_DET_REPORT_ERROR(FIM_DEM_TRIGGER_ON_EVENT_STATUS_API_ID , FIM_E_UNINIT);
    }
    else if(EventId > FIM_EVENT_ID_MAX)
    {
        FIM_DET_REPORT_ERROR(FIM_DEM_TRIGGER_ON_EVENT_STATUS_API_ID , FIM_E_EVENTID_OUT_OF_RANGE);/*SWS_Fim_00057*/
    }
    else if((EventStatusByteOld & FIM_EVENT_TEST_BIT) == (EventStatusByteNew & FIM_EVENT_TEST_BIT))
    {
        /*do nothing*/
    }
    else
    {
        for(EventIndex = (uint16)0; EventIndex < FIM_EVENT_NUM_CFG; EventIndex++)
        {
            if(FiM_EventCfg[EventIndex].EventId == EventId)
            {
                tempEventIndex = EventIndex;
                break;
            }
        }
        for(FunctionIndex = (uint16)0; FunctionIndex < FiM_EventCfg[tempEventIndex].FunctionNum; FunctionIndex++)
        {
            FID = FiM_EventCfg[tempEventIndex].FunctionIdPtr[FunctionIndex];
            Mask = FiM_EventCfg[tempEventIndex].InhibitionMaskPtr[FunctionIndex];
            if(FALSE == FiM_InhibitionCalculation(EventStatusByteNew,Mask))/*FALSE means this event occured*/
            {
                if(FiM_Permission[FID] == TRUE)
                {
                    FiM_Permission[FID] = FALSE;
                    FiM_EventCfg[tempEventIndex].EventNotOccuredFlag[FunctionIndex] = FIM_EVENT_OCCURED;
                }
                else
                {
                    /*event occured, this function shall be inhibited, and the permission value is FALSE already,
                    so just do nothing*/
                    FiM_EventCfg[tempEventIndex].EventNotOccuredFlag[FunctionIndex] = FIM_EVENT_OCCURED;
                }                
            }
            else
            {
                if(FiM_Permission[FID] == TRUE)
                {
                    /*event not occured, permission value stays unchanged*/
                }
                else
                {
                    /*event not occured, and the permission value is FALSE, we can't ensure that no other events had occured,
                    so the polling is required*/
                    FiM_EventCfg[tempEventIndex].EventNotOccuredFlag[FunctionIndex] = FIM_EVENT_NOT_OCCURED;
                    FiM_Permission[FID] = (boolean)FiM_EventCfg[tempEventIndex].EventNotOccuredFlag[FunctionIndex];
                    for(EventIndex = (uint16)0; EventIndex < FIM_EVENT_NUM_CFG; EventIndex++)
                    {
                        if(EventIndex != tempEventIndex)
                        {
                            for(FunctionIndex1 = (uint16)0; FunctionIndex1 < FiM_EventCfg[EventIndex].FunctionNum; FunctionIndex1++)
                            {
                                if(FiM_EventCfg[EventIndex].FunctionIdPtr[FunctionIndex1] == FID)
                                {
                                    if(FiM_EventCfg[EventIndex].EventNotOccuredFlag[FunctionIndex1] != FIM_EVENT_NOT_CARED)
                                    {
                                        FiM_Permission[FID] &= (boolean)FiM_EventCfg[EventIndex].EventNotOccuredFlag[FunctionIndex1];
                                    }
                                    break;
                                }
                            }
                        }
                    }
                }
            }           
        }
    }
}
#endif

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name : FiM_DemTriggerOnComponentStatus
*
* Description   : Triggers on changes of the component failed status.
*
* Inputs        : ComponentId,ComponentFailedStatus
*
* Outputs       : None
*
* return        : None
*
* Limitations   : None
********************************************************************************
END_FUNCTION_HDR */
#if(FIM_DEM_COMPONENT_SUPPORT == STD_ON)
#if(FIM_EVENT_UPDATE_TRIGGERED_BY_DEM == STD_ON)
FUNC(void,FIM_CODE) FiM_DemTriggerOnComponentStatus
(
    Dem_ComponentIdType ComponentId,
    boolean ComponentFailedStatus
)
{
    uint16 FunctionNum = (uint16)0;
    FiM_FunctionIdType Fid = (FiM_FunctionIdType)0;
    uint16 Index = (uint16)0;
    boolean Per = TRUE;
    uint16 NumOfUint32 = (uint16)0;
    uint16 Num = (uint16)0;

    if(FiM_InitStatus != FIM_INITIALIZED_FULL)
    {
        FIM_DET_REPORT_ERROR(FIM_DEM_TRIGGER_ON_COMPONENT_STATUS_API_ID , FIM_E_UNINIT);
    }
    else if(ComponentId > FIM_COMPONENT_ID_MAX)
    {
        FIM_DET_REPORT_ERROR(FIM_DEM_TRIGGER_ON_COMPONENT_STATUS_API_ID, FIM_E_COMPONENTID_OUT_OF_RANGE);
    }
    else
    {
        /*find FIDs linked to this componentID*/
        for(FunctionNum = (uint16)0; FunctionNum < FiM_ComponentCfg[ComponentId].FunctionCfgNum; FunctionNum++)
        {
            Per = TRUE;
            Fid = FiM_ComponentCfg[ComponentId].FunctionIdPtr[FunctionNum];
            Index = FiM_FunCfg[Fid].CindexPtr[ComponentId];
            if(ComponentFailedStatus == TRUE)/*this parameter is true,it means errors happened,relative bit set to 1*/
            {
                (FiM_FunCfg[Fid].ComponentAsBitArrayPtr[Index>>BITS_OF_SHIFT]) |= ((uint32)1 << (uint32)(Index%BITS_OF_ELEMENT));
                Per = FALSE;
            }
            else
            {
                (FiM_FunCfg[Fid].ComponentAsBitArrayPtr[Index>>BITS_OF_SHIFT]) &= (~((uint32)1 << (uint32)(Index%BITS_OF_ELEMENT)));
                Num = (uint16)(FiM_FunCfg[Fid].ComponentCfgNum>>BITS_OF_SHIFT)+(uint16)1;
                for(NumOfUint32 = (uint16)0; NumOfUint32 < Num; NumOfUint32++)
                {
                    if(FiM_FunCfg[Fid].ComponentAsBitArrayPtr[NumOfUint32] != (uint32)0)
                    {
                        Per = FALSE;
                        break;
                    }
                    else
                    {
                        /*do nothing*/
                    }
                }
                if(Per == TRUE)
                {
                    Num = (uint16)(FiM_FunCfg[Fid].EventCfgNum>>BITS_OF_SHIFT)+(uint16)1;
                    for(NumOfUint32 = (uint16)0; NumOfUint32 < Num; NumOfUint32++)
                    {
                        if(FiM_FunCfg[Fid].EventAsBitArrayPtr[NumOfUint32] != (uint32)0)
                        {
                            Per = FALSE;
                            break;
                        }
                        else
                        {
                            /*do nothing*/
                        }
                    }
                }
                else
                {
                    /*do nothing*/
                }
            }
            FiM_Permission[Fid] = Per;
        }
    }
}
#endif
#endif
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name : FiM_DemInit
*
* Description   : Re-initializes the FIM.
*
* Inputs        : None
*
* Outputs       : None
*
* return        : None
*
* Limitations   : None
********************************************************************************
END_FUNCTION_HDR */
FUNC(void,FIM_CODE) FiM_DemInit/*SWS_Fim_00006*/
(
    void
)
{   
#if(FIM_EVENT_UPDATE_TRIGGERED_BY_DEM == STD_ON)
    uint16 EventIndex = (uint16)0;
    Dem_UdsStatusByteType Status = (Dem_UdsStatusByteType)0;
    Std_ReturnType ret = E_OK;
    uint16 FunctionIndex = (uint16)0;
    FiM_InhibitionMaskType Mask = (FiM_InhibitionMaskType)0;
    boolean FirstAssignmentFlag[FIM_FUNCTION_NUM_CFG];
    uint8 counter = (uint8)0;
    FiM_FunctionIdType FunctionID = (FiM_FunctionIdType)0;
#if(FIM_DEM_COMPONENT_SUPPORT == STD_ON)
    boolean ComponentNotFail = TRUE;
#endif
#endif

    if(FiM_InitStatus == FIM_UNINITIALIZED)
    {
        FIM_DET_REPORT_ERROR(FIM_DEMINIT_API_ID, FIM_E_UNINIT);
    }
    else
    {
#if(FIM_EVENT_UPDATE_TRIGGERED_BY_DEM == STD_OFF && FIM_QUARY_MODE == FIM_CYCLICALLY)
        FiM_QuaryAllFunction();/*when FiM is configured as querying permission cyclically*/
#elif(FIM_EVENT_UPDATE_TRIGGERED_BY_DEM == STD_ON)/*when FiM is configured as being triggered by Dem*/
        for(FunctionID = (uint16)0; FunctionID < FIM_FUNCTION_NUM_CFG; FunctionID++)
        {
            FirstAssignmentFlag[FunctionID] = TRUE;
        }
        for(EventIndex = (uint16)0; EventIndex < FIM_EVENT_NUM_CFG; EventIndex++)
        {
            ret = Dem_GetEventStatus(FiM_EventCfg[EventIndex].EventId, &Status);
            if(ret == E_NOT_OK)
            {
                FiM_EventCfg[EventIndex].EventNotOccuredFlag[FunctionIndex] = FIM_EVENT_NOT_CARED;
            }
            else
            {
                for(FunctionIndex = (uint16)0; FunctionIndex < FiM_EventCfg[EventIndex].FunctionNum; FunctionIndex++)
                {
                    Mask = FiM_EventCfg[EventIndex].InhibitionMaskPtr[FunctionIndex];
                    FiM_EventCfg[EventIndex].EventNotOccuredFlag[FunctionIndex] = (FiM_EventStatusType)FiM_InhibitionCalculation(Status, Mask);                   
                }
            }
        }
        for(FunctionID = (uint16)0; FunctionID < FIM_FUNCTION_NUM_CFG; FunctionID++)
        {
            for(EventIndex = (uint16)0; EventIndex < FIM_EVENT_NUM_CFG; EventIndex++)
            {
                for(FunctionIndex = (uint16)0; FunctionIndex < FiM_EventCfg[EventIndex].FunctionNum; FunctionIndex++)
                {
                    if(FiM_EventCfg[EventIndex].FunctionIdPtr[FunctionIndex] == FunctionID)
                    {
                        if(FiM_EventCfg[EventIndex].EventNotOccuredFlag[FunctionIndex] != FIM_EVENT_NOT_CARED)
                        {
                            if(FirstAssignmentFlag[FunctionID] == TRUE)
                            {
                                FiM_Permission[FunctionID] = (boolean)FiM_EventCfg[EventIndex].EventNotOccuredFlag[FunctionIndex];
                                FirstAssignmentFlag[FunctionID] = FALSE;
                            }
                            else
                            {
                                FiM_Permission[FunctionID] &= (boolean)FiM_EventCfg[EventIndex].EventNotOccuredFlag[FunctionIndex];
                            }
                        }
                        break;
                    }                
                }
            }
        }
#endif/*there is no efforts for querying one by one,it shall be processed in FiM_GetFunctionPermission*/
        FiM_InitStatus = FIM_INITIALIZED_FULL;
    }
}


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name : FiM_GetVersionInfo
*
* Description   :Returns the version information of this module.
*
* Inputs        : None
*
* Outputs       :-versioninfo:Pointer to where to store the version information of this module.
*
* return        : None
*
* Limitations   : None
********************************************************************************
END_FUNCTION_HDR */
#if(STD_ON == FIM_VERSION_INFO_API)
FUNC(void, FIM_CODE) FiM_GetVersionInfo/*SWS_Fim_00078*/
(
    P2VAR(Std_VersionInfoType,  AUTOMATIC, FIM_APPL_DATA) versioninfo
)
{
    if(versioninfo == NULL_PTR)
    {
        FIM_DET_REPORT_ERROR(FIM_GET_VERSION_INFO_API_ID, FIM_E_PARAM_POINTER);
    }
    else
    {
        versioninfo->vendorID = FIM_VENDOR_ID;
        versioninfo->moduleID = FIM_MODULE_ID;
        versioninfo->sw_major_version = (uint8)FIM_SW_MAJOR_VERSION;
        versioninfo->sw_minor_version = (uint8)FIM_SW_MINOR_VERSION;
        versioninfo->sw_patch_version = (uint8)FIM_SW_PATCH_VERSION;
    }
}
#endif




/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name : FiM_MainFunction
*
* Description   : None
*
* Inputs        : None
*
* Outputs       : None
*
* return        : None
*
* Limitations   : None
********************************************************************************
END_FUNCTION_HDR */
#if(FIM_EVENT_UPDATE_TRIGGERED_BY_DEM == STD_OFF && FIM_QUARY_MODE == FIM_CYCLICALLY)
FUNC(void, FIM_CODE) FiM_MainFunction
(
    void
)
{
    if(FiM_InitStatus != FIM_INITIALIZED_FULL)
    {
        FIM_DET_REPORT_ERROR(FIM_MAIN_FUNCTION_API_ID , FIM_E_UNINIT);
    }
    else
    {
        FiM_QuaryAllFunction();
    }
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name : FiM_QuaryAllFunction
*
* Description   : calculate every FID's Permission
*
* Inputs        : None
*
* Outputs       : None
*
* return        : None
*
* Limitations   : None
********************************************************************************
END_FUNCTION_HDR */
#if(FIM_DEM_COMPONENT_SUPPORT == STD_ON)
STATIC FUNC(void,FIM_CODE) FiM_QuaryAllFunction/*when component is supported*/
(
    void
)
{
    FiM_FunctionIdType Fid = (FiM_FunctionIdType)0;
    boolean Per = FALSE;
    boolean Flag[FIM_FUNCTION_NUM_CFG];
    Dem_ComponentIdType ComponentID = (Dem_ComponentIdType)0;
    uint16 FuncNum = (uint16)0;
    FiM_FunctionIdType FunctionID = (FiM_FunctionIdType)0;

    for(Fid = (FiM_FunctionIdType)0;  Fid < FIM_FUNCTION_NUM_CFG;  Fid++)
    {
        Flag[Fid] = TRUE;
    }
    for(Fid = (FiM_FunctionIdType)0;  Fid < FIM_FUNCTION_NUM_CFG;  Fid++)
    {
        Per = FALSE;
        if(Flag[Fid] == TRUE)
        {
            if(FALSE == FiM_CalculatePermissionByEvent(Fid))
            {
                /*do nothing*/
            }
            else
            {
                if(FALSE == FiM_CalculatePermissionByComponent(Fid,&ComponentID))/*component is failed,then all FIDs linked to it will be inhibited*/
                {
                    for(FuncNum = (uint16)0; FuncNum < FiM_ComponentCfg[ComponentID].FunctionCfgNum; FuncNum++)
                    {
                        FunctionID = FiM_ComponentCfg[ComponentID].FunctionIdPtr[FuncNum];
                        Flag[FunctionID] = FALSE;
                    }
                }
                else
                {
                    Per = TRUE;
                }
            }
        }
        else
        {
            /*do nothing*/
        }
        FiM_Permission[Fid] = Per;
    }
}
#else
STATIC FUNC(void,FIM_CODE) FiM_QuaryAllFunction/*when component is not supported*/
(
    void
)
{
    FiM_FunctionIdType Fid = (FiM_FunctionIdType)0;
    boolean Per = FALSE;

    for(Fid = (FiM_FunctionIdType)0;  Fid < FIM_FUNCTION_NUM_CFG;  Fid++)
    {
        Per = FALSE;
        if(FALSE == FiM_CalculatePermissionByEvent(Fid))
        {
            /*do nothing*/
        }
        else
        {
            Per = TRUE;
        }
        FiM_Permission[Fid] = Per;
    }
}
#endif/* #if(FIM_DEM_COMPONENT_SUPPORT == STD_ON) */
#endif/* #if(FIM_EVENT_UPDATE_TRIGGERED_BY_DEM == STD_OFF && FIM_QUARY_MODE == FIM_CYCLICALLY) */

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name : FiM_CalculatePermissionByEvent
*
* Description   : Calculate permission by events linked to FID
*
* Inputs        : FID
*
* Outputs       : None
*
* return        : E_OK: Events linked to this FID do not inhibit it;E_NOT_OK: One or more of events linked to this FID inhibits it
*
* Limitations   : None
********************************************************************************
END_FUNCTION_HDR */
#if(FIM_EVENT_UPDATE_TRIGGERED_BY_DEM == STD_OFF)
STATIC FUNC(boolean,FIM_CODE)FiM_CalculatePermissionByEvent
(
    FiM_FunctionIdType FunctionID
)
{
    boolean EventNotOccur = TRUE;
    Std_ReturnType ret = E_OK;
    uint16 EventNum = (uint16)0;
    uint16 counter = (uint16)0;
    FiM_InhibitionMaskType Mask = (FiM_InhibitionMaskType)0;
    Dem_UdsStatusByteType Status = (Dem_UdsStatusByteType)0;

#if(FIM_DEM_COMPONENT_SUPPORT == STD_ON)/*when component is supported,event number configured can be 0;not supported,shall not be 0*/
    if(FiM_FunCfg[FunctionID].EventCfgNum == (uint16)0)
    {
        /*do nothing*/
    }
    else
    {
#endif
        for(EventNum = (uint16)0; EventNum < FiM_FunCfg[FunctionID].EventCfgNum; EventNum++)/*SWS_Fim_00065*/
        {
            ret = Dem_GetEventStatus(FiM_FunCfg[FunctionID].EventIdPtr[EventNum], &Status);
            if(ret == E_NOT_OK)
            {
                counter++;

                if(counter == FiM_FunCfg[FunctionID].EventCfgNum)
                {
                    EventNotOccur = FALSE;
                }
                else
                {
                    /*do nothing*/
                } 
            }
            else
            {
                Mask = FiM_FunCfg[FunctionID].InhibitionMaskPtr[EventNum];
                if(FALSE == FiM_InhibitionCalculation(Status,Mask))
                {
                    EventNotOccur = FALSE;
                    break;
                }
                else
                {
                    /*do nothing*/
                }
            }
        }
#if(FIM_DEM_COMPONENT_SUPPORT == STD_ON)
    }
#endif
    return EventNotOccur;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name : FiM_CalculatePermissionByComponent
*
* Description   : Calculate permission by components linked to FID
*
* Inputs        : FID
*
* Outputs       : None
*
* return        : E_OK: Components linked to this FID do not inhibit it;E_NOT_OK: One or more of components linked to this FID inhibits it
*
* Limitations   : None
********************************************************************************
END_FUNCTION_HDR */
#if(FIM_DEM_COMPONENT_SUPPORT == STD_ON)
STATIC FUNC(boolean,FIM_CODE)FiM_CalculatePermissionByComponent
(
    FiM_FunctionIdType FunctionID
#if(FIM_EVENT_UPDATE_TRIGGERED_BY_DEM == STD_OFF && FIM_QUARY_MODE == FIM_CYCLICALLY)
    ,Dem_ComponentIdType *ComponentIDPtr
#endif
)
{
    uint16 ComponentNum = (uint16)0;
    uint16 counter = (uint16)0;
    boolean ComponentFailedStatus = FALSE;
    boolean ComponentNotFail = TRUE;
    Std_ReturnType ret = E_NOT_OK;

    if(FiM_FunCfg[FunctionID].ComponentCfgNum == (uint16)0)
    {
        /*do nothing*/
    }
    else
    {
        for(ComponentNum = (uint16)0; ComponentNum < FiM_FunCfg[FunctionID].ComponentCfgNum; ComponentNum++)
        {
            ret = Dem_GetComponentFailed(FiM_FunCfg[FunctionID].ComponentIdPtr[ComponentNum], &ComponentFailedStatus);
            if(ret == E_NOT_OK)
            {
                counter++;

                if(counter == FiM_FunCfg[FunctionID].ComponentCfgNum)
                {
                    ComponentNotFail = FALSE;
                }
                else
                {
                    /*do nothing*/
                }
            }
            else
            {
                if(ComponentFailedStatus == TRUE)
                {
                    ComponentNotFail = FALSE;
                    break;
                }
                else
                {
                    /*do nothing*/
                }
            }
        }
#if(FIM_EVENT_UPDATE_TRIGGERED_BY_DEM == STD_OFF && FIM_QUARY_MODE == FIM_CYCLICALLY)
        *ComponentIDPtr = FiM_FunCfg[FunctionID].ComponentIdPtr[ComponentNum];
#endif
    }
    return ComponentNotFail;
}
#endif/* #if(FIM_DEM_COMPONENT_SUPPORT == STD_ON) */
#endif/* #if(FIM_EVENT_UPDATE_TRIGGERED_BY_DEM == STD_OFF) */

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name : FiM_InhibitionCalculation
*
* Description   : calculate to affirm if status is equal to mask
*
* Inputs        : status,mask
*
* Outputs       : None
*
* return        : E_OK: equal;E_NOT_OK: not equal
*
* Limitations   : None
********************************************************************************
END_FUNCTION_HDR */
STATIC FUNC(boolean,FIM_CODE) FiM_InhibitionCalculation
(
    Dem_UdsStatusByteType Status,
    FiM_InhibitionMaskType Mask
)
{
    boolean MaskNotEqualToStatus = FALSE;

    if((Mask != FIM_LAST_FAILED) && (Mask != FIM_NOT_TESTED) && (Mask != FIM_TESTED) && (Mask != FIM_TESTED_AND_FAILED))
    {
        FIM_DET_REPORT_ERROR(FIM_INHIBITIONCALCULATION_API_ID, FIM_E_INVALID_PARAMETER);
    }
    else
    {
        if(Mask == FIM_LAST_FAILED)
        {
            if((Status & FIM_EVENT_TEST_BIT) == FIM_LAST_FAILED)
            {
                /*do nothing*/
            }
            else
            {
                MaskNotEqualToStatus = TRUE;
            }
        }
        else if(Mask == FIM_NOT_TESTED)
        {
            if((Status & FIM_EVENT_TEST_BIT) == FIM_NOT_TESTED)
            {
                /*do nothing*/
            }
            else
            {
                MaskNotEqualToStatus = TRUE;
            }
        }
        else if(Mask == FIM_TESTED)
        {
            if((Status & FIM_EVENT_TEST_BIT) == FIM_TESTED)
            {
                /*do nothing*/
            }
            else
            {
                MaskNotEqualToStatus = TRUE;
            }
        }
        else if(Mask == FIM_TESTED_AND_FAILED)
        {
            if((Status & FIM_EVENT_TEST_BIT) == FIM_TESTED_AND_FAILED)
            {
                /*do nothing*/
            }
            else
            {
                MaskNotEqualToStatus = TRUE;
            }
        }
        else
        {
            /*do nothing*/
        }
    }
    return MaskNotEqualToStatus;
}

#define FIM_STOP_SEC_CODE
#include "MemMap.h"

