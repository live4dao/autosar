/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
*   File Name       : Nm.c
********************************************************************************
*   Project/Product : AUTOSAR 4.2
*   Title           : Nm.c
*   Author          : Hirain
********************************************************************************
*   Description     : Implementation of Nm provided functionality
*
********************************************************************************
*   Limitations     : None
*
********************************************************************************
*
********************************************************************************
*   Revision History:
*
*   Version      Date           Initials        CR#           Descriptions
*   ---------    ----------    ------------   ----------   ---------------
*   01.00.00     03/12/2016    Boxue.Li        N/A         Original
*   01.00.01     01/08/2018    Feixiang.Dong   N/A         EAS422_Nm_20180801_01
*   01.00.02     21/01/2019    Boxue.Li        N/A         EAS422_Nm_20190121_01
*   01.00.03     12/03/2019    Feixiang.Dong   N/A         EAS422_Nm_20190312_01
*   01.00.04     12/03/2019    Tianrui.Zhang   N/A         EAS422_Nm_20200526_01
*   01.00.05     22/07/2022    ziyi.zhao       QAC         EAS422_Nm_20220722_01
*   01.00.06     24/11/2023    Feixiang.Dong   N/A         EAS422_Nm_20231124_01
********************************************************************************
* END_FILE_HDR*/

/*******************************************************************************
*     Includes
*******************************************************************************/
#include "Nm.h"
#include "Nm_Cbk.h"
#include "Nm_Callout.h"
#if(STD_ON == NM_DEV_ERROR_DETECT)
#include "Det.h"
#endif

/*******************************************************************************
*  General QAC Suppression
*******************************************************************************/
/*PRQA S 3614,3214,0862 EOF*/
/*
According to the requirements of AUTOSAR Specification,when locating address 
segments in the files of each module,#include "MemMap.h" is required.Defined 
XXX_START_SEC_ will undefine in MemMap.h
*/

/*PRQA S 3453 EOF*/
/*
Enhance code readability
*/

/*PRQA S 3432,3429 EOF*/
/*
P2VAR and other macros in the Compiler conforms to AUTOSAR standard.There's no 
need to revise.
*/

/*PRQA S 3119 EOF*/
/*
No unified input parameter processing is used
*/

/*******************************************************************************
*   Version Check
*******************************************************************************/
/*ComM0136 */
#if(STD_ON == NM_VERSION_CHECK)
/* check Version with other import module */

/* check Version with cfg file */
#if ((NM_CONFIG_VARIANTS != STD_CONFIG_VARIANTS_PRECOMPILE) &&\
        (NM_CONFIG_VARIANTS != STD_CONFIG_VARIANTS_LINKTIME))
#error "The Nm module only supports Pre-Compile and Link-time Configuration."
#endif

#if ((NM_AR_RELEASE_MAJOR_VERSION != NM_AR_RELEASE_MAJOR_VERSION_CFG) || \
       (NM_AR_RELEASE_MINOR_VERSION != NM_AR_RELEASE_MINOR_VERSION_CFG))
#error "AutoSar Version Numbers of Nm and its cfg file are incompatible"
#endif

#if ((NM_SW_MAJOR_VERSION != NM_SW_MAJOR_VERSION_CFG) || \
       (NM_SW_MINOR_VERSION != NM_SW_MINOR_VERSION_CFG))
#error "SW Version Numbers of Nm and its cfg file are incompatible"
#endif


#endif/*#if(STD_ON == NM_VERSION_CHECK)*/


/*******************************************************************************
*   Macro
*******************************************************************************/
#if(STD_ON == NM_DEV_ERROR_DETECT)

#define  NM_DET_REPORT_ERROR(ApiId, errcode)  \
    DET_REPORT_ERROR(NM_MODULE_ID, NM_INSTANCE_ID, (ApiId), (errcode))

#else

#define  NM_DET_REPORT_ERROR(ApiId, errcode)

#endif

/*Initialization status*/
#define NM_IS_INITIALIZED()                    (STD_INITIALIZED == Nm_InitStatus)
#define NM_SET_INITIALIZED()                   (Nm_InitStatus = STD_INITIALIZED)
#define NM_SET_UNINITIALIZED()                 (Nm_InitStatus = STD_UNINITIALIZED)

#if(NM_CONFIG_VARIANTS == STD_CONFIG_VARIANTS_PRECOMPILE)
#define NM_BUSTYPE(NetworkHandle)              (Nm_ChannelCfg[NetworkHandle].NmBusType)
#define NM_BUSNMID(NetworkHandle)              (Nm_ChannelCfg[NetworkHandle].NmBusNmChannelId)
#define NM_COMMID(NetworkHandle)               (Nm_ChannelCfg[NetworkHandle].NmComMChannelId)

#else
#define NM_BUSTYPE(NetworkHandle)              (Nm_ChannelLCfg[NetworkHandle].NmBusType)
#define NM_BUSNMID(NetworkHandle)              (Nm_ChannelLCfg[NetworkHandle].NmBusNmChannelId)
#define NM_COMMID(NetworkHandle)               (Nm_ChannelLCfg[NetworkHandle].NmComMChannelId)
#endif

/*******************************************************************************
*   Local Data Define
*******************************************************************************/
#define NM_START_SEC_VAR_INIT_8
#include "MemMap.h"
STATIC VAR(Std_InitStateType, NM_VAR)  Nm_InitStatus = STD_UNINITIALIZED;
#define NM_STOP_SEC_VAR_INIT_8
#include "MemMap.h"


/*******************************************************************************
*   Local Functions declaration
*******************************************************************************/

#define NM_START_SEC_CODE
#include "MemMap.h"


/*******************************************************************************
*  PUBLIC Functions define
*******************************************************************************/

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Nm_Init  Nm030
*
* Description:   Initializes the NM Interface
*
*
* Inputs:        ConfigPtr Pointer to the selected configuration set.
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, NM_CODE) Nm_Init
(
    void
)
{

    NM_SET_INITIALIZED();
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Nm_PassiveStartUp  Nm031
*
* Description:   This function calls the <BusNm>_PassiveStartUp function
*
*
* Inputs:        NetworkHandle Identification of the NM-channel.
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, NM_CODE) Nm_PassiveStartUp
(
    CONST(NetworkHandleType, NMIF_CONST) NetworkHandle
)
{
    Std_ReturnType ret = E_NOT_OK;

    if(!NM_IS_INITIALIZED())
    {
        /*Nm128*/
        NM_DET_REPORT_ERROR(NM_PASSIVESTARTUP_APIID, NM_E_UNINIT);
    }
    else if(NetworkHandle >= (NetworkHandleType)NM_NUM_OF_CHANNELS)
    {
        NM_DET_REPORT_ERROR(NM_PASSIVESTARTUP_APIID, NM_E_HANDLE_UNDEF);
    }
    else
    {
        switch(NM_BUSTYPE(NetworkHandle))
        {
#if(NM_NUM_OF_CANNM_CHANNEL > 0)
        case NM_BUSNM_CANNM:
            ret = CanNm_PassiveStartUp(NM_BUSNMID(NetworkHandle));
            break;
#endif
#if(NM_NUM_OF_OSEKNM_CHANNEL > 0)
        case NM_BUSNM_OSEKNM:
            ret = OsekNm_PassiveStartUp(NM_BUSNMID(NetworkHandle));
            break;
#endif
#if(NM_NUM_OF_FR_CHANNEL > 0)
        case NM_BUSNM_FRNM:
            ret = FrNm_PassiveStartUp(NM_BUSNMID(NetworkHandle));
            break;
#endif
#if(NM_NUM_OF_LIN_CHANNEL > 0)
        case NM_BUSNM_LINNM:
            ret = LinNm_PassiveStartUp(NM_BUSNMID(NetworkHandle));
            break;
#endif
#if(NM_NUM_OF_ETH_CHANNEL > 0)
        case NM_BUSNM_UDPNM:
            ret = UdpNm_PassiveStartUp(NM_BUSNMID(NetworkHandle));
            break;
#endif
        default:
            ret = E_NOT_OK;
            break;
        }
    }

    return ret;
}

/*Nm130 Nm132*/
#if(NM_PASSIVEMODE != NM_PASSIVEMODE_ENABLED_ONLY)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Nm_NetworkRequest  Nm032
*
* Description:   This function calls the <BusNm>_NetworkRequest
*
*
* Inputs:        NetworkHandle Identification of the NM-channel.
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, NM_CODE) Nm_NetworkRequest
(
    CONST(NetworkHandleType, NMIF_CONST) NetworkHandle
)
{
    Std_ReturnType ret = E_NOT_OK;

    if(!NM_IS_INITIALIZED())
    {
        /*Nm129*/
        NM_DET_REPORT_ERROR(NM_NETWORKREQUEST_APIID, NM_E_UNINIT);
    }
    else if(NetworkHandle >= (NetworkHandleType)NM_NUM_OF_CHANNELS)
    {
        NM_DET_REPORT_ERROR(NM_NETWORKREQUEST_APIID, NM_E_HANDLE_UNDEF);
    }
    else
    {
        switch(NM_BUSTYPE(NetworkHandle))
        {
#if(NM_NUM_OF_CANNM_CHANNEL > 0)
        case NM_BUSNM_CANNM:
            ret = CanNm_NetworkRequest(NM_BUSNMID(NetworkHandle));
            break;
#endif
#if(NM_NUM_OF_OSEKNM_CHANNEL > 0)
        case NM_BUSNM_OSEKNM:
            ret = OsekNm_NetworkRequest(NM_BUSNMID(NetworkHandle));
            break;
#endif
#if(NM_NUM_OF_FR_CHANNEL > 0)
        case NM_BUSNM_FRNM:
            ret = FrNm_NetworkRequest(NM_BUSNMID(NetworkHandle));
            break;
#endif
#if(NM_NUM_OF_LIN_CHANNEL > 0)
        case NM_BUSNM_LINNM:
            ret = LinNm_NetworkRequest(NM_BUSNMID(NetworkHandle));
            break;
#endif
#if(NM_NUM_OF_ETH_CHANNEL > 0)
        case NM_BUSNM_UDPNM:
            ret = UdpNm_NetworkRequest(NM_BUSNMID(NetworkHandle));
            break;
#endif
        default:
            ret = E_NOT_OK;
            break;
        }
    }

    return ret;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Nm_NetworkRelease  Nm046
*
* Description:   This function calls the <BusNm>_NetworkRelease bus specific function
*
*
* Inputs:        NetworkHandle Identification of the NM-channel.
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, NM_CODE) Nm_NetworkRelease
(
    CONST(NetworkHandleType, NMIF_CONST) NetworkHandle
)
{
    Std_ReturnType ret = E_NOT_OK;

    if(!NM_IS_INITIALIZED())
    {
        /*Nm131*/
        NM_DET_REPORT_ERROR(NM_NETWORKRELEASE_APIID, NM_E_UNINIT);
    }
    else if(NetworkHandle >= (NetworkHandleType)NM_NUM_OF_CHANNELS)
    {
        NM_DET_REPORT_ERROR(NM_NETWORKRELEASE_APIID, NM_E_HANDLE_UNDEF);
    }
    else
    {
        switch(NM_BUSTYPE(NetworkHandle))
        {
#if(NM_NUM_OF_CANNM_CHANNEL > 0)
        case NM_BUSNM_CANNM:
            ret = CanNm_NetworkRelease(NM_BUSNMID(NetworkHandle));
            break;
#endif
#if(NM_NUM_OF_OSEKNM_CHANNEL > 0)
        case NM_BUSNM_OSEKNM:
            ret = OsekNm_NetworkRelease(NM_BUSNMID(NetworkHandle));
            break;
#endif
#if(NM_NUM_OF_FR_CHANNEL > 0)
        case NM_BUSNM_FRNM:
            ret = FrNm_NetworkRelease(NM_BUSNMID(NetworkHandle));
            break;
#endif
#if(NM_NUM_OF_LIN_CHANNEL > 0)
        case NM_BUSNM_LINNM:
            ret = LinNm_NetworkRelease(NM_BUSNMID(NetworkHandle));
            break;
#endif
#if(NM_NUM_OF_ETH_CHANNEL > 0)
        case NM_BUSNM_UDPNM:
            ret = UdpNm_NetworkRelease(NM_BUSNMID(NetworkHandle));
            break;
#endif

        default:
            ret = E_NOT_OK;
            break;
        }
    }

    return ret;
}

#endif

/*Nm134 Nm136*/
#if(STD_ON == NM_COM_CONTROL_ENABLED)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Nm_DisableCommunication  Nm033
*
* Description:   Disables the NM PDU transmission ability
*
*
* Inputs:        NetworkHandle Identification of the NM-channel.
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, NM_CODE) Nm_DisableCommunication
(
    CONST(NetworkHandleType, NMIF_CONST) NetworkHandle
)
{
    Std_ReturnType ret = E_NOT_OK;

    if(!NM_IS_INITIALIZED())
    {
        /*Nm133*/
        NM_DET_REPORT_ERROR(NM_DISABLECOMMUNICATION_APIID, NM_E_UNINIT);
    }
    else if(NetworkHandle >= (NetworkHandleType)NM_NUM_OF_CHANNELS)
    {
        NM_DET_REPORT_ERROR(NM_DISABLECOMMUNICATION_APIID, NM_E_HANDLE_UNDEF);
    }
    else
    {
        switch(NM_BUSTYPE(NetworkHandle))
        {
#if(NM_NUM_OF_CANNM_CHANNEL > 0)
        case NM_BUSNM_CANNM:
            ret = CanNm_DisableCommunication(NM_BUSNMID(NetworkHandle));
            break;
#endif
#if(NM_NUM_OF_OSEKNM_CHANNEL > 0)
        case NM_BUSNM_OSEKNM:
            ret = OsekNm_Silent(NM_BUSNMID(NetworkHandle));
            break;
#endif
#if(NM_NUM_OF_FR_CHANNEL > 0)
        case NM_BUSNM_FRNM:
            ret = FrNm_DisableCommunication(NM_BUSNMID(NetworkHandle));
            break;
#endif
#if(NM_NUM_OF_LIN_CHANNEL > 0)
        case NM_BUSNM_LINNM:
            ret = LinNm_DisableCommunication(NM_BUSNMID(NetworkHandle));
            break;
#endif
#if(NM_NUM_OF_ETH_CHANNEL > 0)
        case NM_BUSNM_UDPNM:
            ret = UdpNm_DisableCommunication(NM_BUSNMID(NetworkHandle));
            break;
#endif
        default:
            ret = E_NOT_OK;
            break;
        }
    }

    return ret;

}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Nm_EnableCommunication  Nm034
*
* Description:   Enables the NM PDU transmission ability
*
*
* Inputs:        NetworkHandle Identification of the NM-channel.
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, NM_CODE) Nm_EnableCommunication
(
    CONST(NetworkHandleType, NMIF_CONST) NetworkHandle
)
{
    Std_ReturnType ret = E_NOT_OK;

    if(!NM_IS_INITIALIZED())
    {
        /*Nm135*/
        NM_DET_REPORT_ERROR(NM_ENABLECOMMUNICATION_APIID, NM_E_UNINIT);
    }
    else if(NetworkHandle >= (NetworkHandleType)NM_NUM_OF_CHANNELS)
    {
        NM_DET_REPORT_ERROR(NM_ENABLECOMMUNICATION_APIID, NM_E_HANDLE_UNDEF);
    }
    else
    {
        switch(NM_BUSTYPE(NetworkHandle))
        {
#if(NM_NUM_OF_CANNM_CHANNEL > 0)
        case NM_BUSNM_CANNM:
            ret = CanNm_EnableCommunication(NM_BUSNMID(NetworkHandle));
            break;
#endif
#if(NM_NUM_OF_OSEKNM_CHANNEL > 0)
        case NM_BUSNM_OSEKNM:
            ret = OsekNm_Talk(NM_BUSNMID(NetworkHandle));
            break;
#endif
#if(NM_NUM_OF_FR_CHANNEL > 0)
        case NM_BUSNM_FRNM:
            ret = FrNm_EnableCommunication(NM_BUSNMID(NetworkHandle));
            break;
#endif
#if(NM_NUM_OF_LIN_CHANNEL > 0)
        case NM_BUSNM_LINNM:
            ret = LinNm_EnableCommunication(NM_BUSNMID(NetworkHandle));
            break;
#endif
#if(NM_NUM_OF_ETH_CHANNEL > 0)
        case NM_BUSNM_UDPNM:
            ret = UdpNm_EnableCommunication(NM_BUSNMID(NetworkHandle));
            break;
#endif
        default:
            ret = E_NOT_OK;
            break;
        }
    }

    return ret;

}

#endif

#if(STD_ON == NM_USER_DATA_ENABLED)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Nm_SetUserData  Nm034
*
* Description:   Set user data for NM messages transmitted next on the bus
*
*
* Inputs:        NetworkHandle Identification of the NM-channel.
*                nmUserDataPtr User data for the next transmitted NM message
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, NM_CODE) Nm_SetUserData
(
    CONST(NetworkHandleType, NMIF_CONST) NetworkHandle,
    CONSTP2CONST(uint8, AUTOMATIC, NMIF_CONST) nmUserDataPtr
)
{
    Std_ReturnType ret = E_NOT_OK;

    if(!NM_IS_INITIALIZED())
    {
        /*Nm137*/
        NM_DET_REPORT_ERROR(NM_SETUSERDATA_APIID, NM_E_UNINIT);
    }
    else if(NetworkHandle >= (NetworkHandleType)NM_NUM_OF_CHANNELS)
    {
        NM_DET_REPORT_ERROR(NM_SETUSERDATA_APIID, NM_E_HANDLE_UNDEF);
    }
    else if(NULL_PTR == nmUserDataPtr)
    {
        NM_DET_REPORT_ERROR(NM_SETUSERDATA_APIID, NM_E_PARAM_POINTER);
    }
    else
    {
        switch(NM_BUSTYPE(NetworkHandle))
        {
#if(NM_NUM_OF_CANNM_CHANNEL > 0)
        case NM_BUSNM_CANNM:
            ret = CanNm_SetUserData(NM_BUSNMID(NetworkHandle), nmUserDataPtr);
            break;
#endif
#if(NM_NUM_OF_OSEKNM_CHANNEL > 0)
        case NM_BUSNM_OSEKNM:
            ret = OsekNm_SetUserData(NM_BUSNMID(NetworkHandle), nmUserDataPtr);
            break;
#endif
#if(NM_NUM_OF_FR_CHANNEL > 0)
        case NM_BUSNM_FRNM:
            ret = FrNm_SetUserData(NM_BUSNMID(NetworkHandle), nmUserDataPtr);
            break;
#endif
#if(NM_NUM_OF_LIN_CHANNEL > 0)
        case NM_BUSNM_LINNM:
            ret = LinNm_SetUserData(NM_BUSNMID(NetworkHandle), nmUserDataPtr);
            break;
#endif
#if(NM_NUM_OF_ETH_CHANNEL > 0)
        case NM_BUSNM_UDPNM:
            ret = UdpNm_SetUserData(NM_BUSNMID(NetworkHandle), nmUserDataPtr);
            break;
#endif
        default:
            ret = E_NOT_OK;
            break;
        }
    }

    return ret;

}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Nm_GetUserData  Nm036
*
* Description:   Get user data out of the last successfully received NM message
*
* Inputs:        NetworkHandle Identification of the NM-channel.
*
* Outputs:       nmUserDataPtr Pointer where user data out of the last successfully
*                              received NM message shall be copied to
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, NM_CODE) Nm_GetUserData
(
    CONST(NetworkHandleType, NMIF_CONST) NetworkHandle,
    CONSTP2VAR(uint8, AUTOMATIC, NMIF_CONST) nmUserDataPtr
)
{
    Std_ReturnType ret = E_NOT_OK;

    if(!NM_IS_INITIALIZED())
    {
        /*Nm139*/
        NM_DET_REPORT_ERROR(NM_GETUSERDATA_APIID, NM_E_UNINIT);
    }
    else if(NetworkHandle >= (NetworkHandleType)NM_NUM_OF_CHANNELS)
    {
        NM_DET_REPORT_ERROR(NM_GETUSERDATA_APIID, NM_E_HANDLE_UNDEF);
    }
    else if(NULL_PTR == nmUserDataPtr)
    {
        NM_DET_REPORT_ERROR(NM_GETUSERDATA_APIID, NM_E_PARAM_POINTER);
    }
    else
    {
        switch(NM_BUSTYPE(NetworkHandle))
        {
#if(NM_NUM_OF_CANNM_CHANNEL > 0)
        case NM_BUSNM_CANNM:
            ret = CanNm_GetUserData(NM_BUSNMID(NetworkHandle), nmUserDataPtr);
            break;
#endif
#if(NM_NUM_OF_OSEKNM_CHANNEL > 0)
        case NM_BUSNM_OSEKNM:
            ret = OsekNm_GetUserData(NM_BUSNMID(NetworkHandle), nmUserDataPtr);
            break;
#endif
#if(NM_NUM_OF_FR_CHANNEL > 0)
        case NM_BUSNM_FRNM:
            ret = FrNm_GetUserData(NM_BUSNMID(NetworkHandle), nmUserDataPtr);
            break;
#endif
#if(NM_NUM_OF_LIN_CHANNEL > 0)
        case NM_BUSNM_LINNM:
            ret = LinNm_GetUserData(NM_BUSNMID(NetworkHandle), nmUserDataPtr);
            break;
#endif
#if(NM_NUM_OF_ETH_CHANNEL > 0)
        case NM_BUSNM_UDPNM:
            ret = UdpNm_GetUserData(NM_BUSNMID(NetworkHandle), nmUserDataPtr);
            break;
#endif
        default:
            ret = E_NOT_OK;
            break;
        }
    }

    return ret;

}


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Nm_GetPduData  Nm037
*
* Description:   Get the whole PDU data out of the most recently received NM message
*
* Inputs:        NetworkHandle Identification of the NM-channel.
*
* Outputs:       nmPduData Pointer where NM PDU shall be copied to.
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, NM_CODE) Nm_GetPduData
(
    CONST(NetworkHandleType, NMIF_CONST) NetworkHandle,
    CONSTP2VAR(uint8, AUTOMATIC, NMIF_CONST) nmPduData
)
{
    Std_ReturnType ret = E_NOT_OK;

    if(!NM_IS_INITIALIZED())
    {
        /*Nm141*/
        NM_DET_REPORT_ERROR(NM_GETPDUDATA_APIID, NM_E_UNINIT);
    }
    else if (NetworkHandle >= (NetworkHandleType)NM_NUM_OF_CHANNELS)
    {
        NM_DET_REPORT_ERROR(NM_GETPDUDATA_APIID, NM_E_HANDLE_UNDEF);
    }
    else if(NULL_PTR == nmPduData)
    {
        NM_DET_REPORT_ERROR(NM_GETPDUDATA_APIID, NM_E_PARAM_POINTER);
    }
    else
    {
        switch(NM_BUSTYPE(NetworkHandle))
        {
#if(NM_NUM_OF_CANNM_CHANNEL > 0)
        case NM_BUSNM_CANNM:
            ret = CanNm_GetPduData(NM_BUSNMID(NetworkHandle), nmPduData);
            break;
#endif
#if(NM_NUM_OF_OSEKNM_CHANNEL > 0)
        case NM_BUSNM_OSEKNM:
            ret = OsekNm_GetPduData(NM_BUSNMID(NetworkHandle), nmPduData);
            break;
#endif
#if(NM_NUM_OF_FR_CHANNEL > 0)
        case NM_BUSNM_FRNM:
            ret = FrNm_GetPduData(NM_BUSNMID(NetworkHandle), nmPduData);
            break;
#endif
#if(NM_NUM_OF_LIN_CHANNEL > 0)
        case NM_BUSNM_LINNM:
            ret = LinNm_GetPduData(NM_BUSNMID(NetworkHandle), nmPduData);
            break;
#endif
#if(NM_NUM_OF_ETH_CHANNEL > 0)
        case NM_BUSNM_UDPNM:
            ret = UdpNm_GetPduData(NM_BUSNMID(NetworkHandle), nmPduData);
            break;
#endif
        default:
            ret = E_NOT_OK;
            break;
        }
    }

    return ret;

}
#endif


#if(STD_ON == NM_NODE_DETECTION_ENABLED)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name:  Nm_RepeatMessageRequest  Nm038
*
* Description:   Set Repeat Message Request Bit for NM messages transmitted next on the bus.
*
* Inputs:        NetworkHandle Identification of the NM-channel.
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, NM_CODE) Nm_RepeatMessageRequest
(
    CONST(NetworkHandleType, NMIF_CONST) NetworkHandle
)
{
    Std_ReturnType ret = E_NOT_OK;

    if(!NM_IS_INITIALIZED())
    {
        /*Nm143*/
        NM_DET_REPORT_ERROR(NM_REPEATEMESSAGEREQUEST_APIID, NM_E_UNINIT);
    }
    else if(NetworkHandle >= (NetworkHandleType)NM_NUM_OF_CHANNELS)
    {
        NM_DET_REPORT_ERROR(NM_REPEATEMESSAGEREQUEST_APIID, NM_E_HANDLE_UNDEF);
    }
    else
    {
        switch(NM_BUSTYPE(NetworkHandle))
        {
#if(NM_NUM_OF_CANNM_CHANNEL > 0)
        case NM_BUSNM_CANNM:
            ret = CanNm_RepeatMessageRequest(NM_BUSNMID(NetworkHandle));
            break;
#endif
#if(NM_NUM_OF_OSEKNM_CHANNEL > 0)
        case NM_BUSNM_OSEKNM:
            ret = E_OK;
            break;
#endif
#if(NM_NUM_OF_FR_CHANNEL > 0)
        case NM_BUSNM_FRNM:
            ret = FrNm_RepeatMessageRequest(NM_BUSNMID(NetworkHandle));
            break;
#endif
#if(NM_NUM_OF_LIN_CHANNEL > 0)
        case NM_BUSNM_LINNM:
            ret = LinNm_RepeatMessageRequest(NM_BUSNMID(NetworkHandle));
            break;
#endif
#if(NM_NUM_OF_ETH_CHANNEL > 0)
        case NM_BUSNM_UDPNM:
            ret = UdpNm_RepeatMessageRequest(NM_BUSNMID(NetworkHandle));
            break;
#endif
        default:
            ret = E_NOT_OK;
            break;
        }
    }

    return ret;

}
#endif

#if(STD_ON == NM_NODE_ID_ENABLED)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Nm_GetNodeIdentifier  Nm039
*
* Description:   Get node identifier out of the last successfully received NM-message
*
* Inputs:        NetworkHandle Identification of the NM-channel.
*
* Outputs:       nmNodeIdPtr Pointer where node identifier out of the last successfully
*                            received NM-message shall be copied to
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, NM_CODE) Nm_GetNodeIdentifier
(
    CONST(NetworkHandleType, NMIF_CONST) NetworkHandle,
    CONSTP2VAR(uint8, AUTOMATIC, NMIF_CONST) nmNodeIdPtr
)
{
    Std_ReturnType ret = E_NOT_OK;

    if(!NM_IS_INITIALIZED())
    {
        /*Nm145*/
        NM_DET_REPORT_ERROR(NM_GETNODEIDENTIFIER_APIID, NM_E_UNINIT);
    }
    else if(NetworkHandle >= (NetworkHandleType)NM_NUM_OF_CHANNELS)
    {
        NM_DET_REPORT_ERROR(NM_GETNODEIDENTIFIER_APIID, NM_E_HANDLE_UNDEF);
    }
    else if(NULL_PTR == nmNodeIdPtr)
    {
        NM_DET_REPORT_ERROR(NM_GETNODEIDENTIFIER_APIID, NM_E_PARAM_POINTER);
    }
    else
    {
        switch(NM_BUSTYPE(NetworkHandle))
        {
#if(NM_NUM_OF_CANNM_CHANNEL > 0)
        case NM_BUSNM_CANNM:
            ret = CanNm_GetNodeIdentifier(NM_BUSNMID(NetworkHandle), nmNodeIdPtr);
            break;
#endif
#if(NM_NUM_OF_OSEKNM_CHANNEL > 0)
        case NM_BUSNM_OSEKNM:
            ret = OsekNm_GetNodeIdentifier(NM_BUSNMID(NetworkHandle), nmNodeIdPtr);
            break;
#endif
#if(NM_NUM_OF_FR_CHANNEL > 0)
        case NM_BUSNM_FRNM:
            ret = FrNm_GetNodeIdentifier(NM_BUSNMID(NetworkHandle), nmNodeIdPtr);
            break;
#endif
#if(NM_NUM_OF_LIN_CHANNEL > 0)
        case NM_BUSNM_LINNM:
            ret = LinNm_GetNodeIdentifier(NM_BUSNMID(NetworkHandle), nmNodeIdPtr);
            break;
#endif
#if(NM_NUM_OF_ETH_CHANNEL > 0)
        case NM_BUSNM_UDPNM:
            ret = UdpNm_GetNodeIdentifier(NM_BUSNMID(NetworkHandle), nmNodeIdPtr);
            break;
#endif
        default:
            ret = E_NOT_OK;
            break;
        }
    }

    return ret;

}


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Nm_GetLocalNodeIdentifier  Nm040
*
* Description:   Get node identifier configured for the local node.
*
* Inputs:        NetworkHandle Identification of the NM-channel.
*
* Outputs:       nmNodeIdPtr Pointer where node identifier of the local node shall be
*                            copied to
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, NM_CODE) Nm_GetLocalNodeIdentifier
(
    CONST(NetworkHandleType, NMIF_CONST) NetworkHandle,
    CONSTP2VAR(uint8, AUTOMATIC, NMIF_CONST) nmNodeIdPtr
)
{
    Std_ReturnType ret = E_NOT_OK;

    if(!NM_IS_INITIALIZED())
    {
        /*Nm147*/
        NM_DET_REPORT_ERROR(NM_GETLOCALNODEIDENTIFIER_APIID, NM_E_UNINIT);
    }
    else if(NetworkHandle >= (NetworkHandleType)NM_NUM_OF_CHANNELS)
    {
        NM_DET_REPORT_ERROR(NM_GETLOCALNODEIDENTIFIER_APIID, NM_E_HANDLE_UNDEF);
    }
    else if(NULL_PTR == nmNodeIdPtr)
    {
        NM_DET_REPORT_ERROR(NM_GETLOCALNODEIDENTIFIER_APIID, NM_E_PARAM_POINTER);
    }
    else
    {
        switch(NM_BUSTYPE(NetworkHandle))
        {
#if(NM_NUM_OF_CANNM_CHANNEL > 0)
        case NM_BUSNM_CANNM:
            ret = CanNm_GetLocalNodeIdentifier(NM_BUSNMID(NetworkHandle), nmNodeIdPtr);
            break;
#endif
#if(NM_NUM_OF_OSEKNM_CHANNEL > 0)
        case NM_BUSNM_OSEKNM:
            ret = OsekNm_GetLocalNodeIdentifier(NM_BUSNMID(NetworkHandle), nmNodeIdPtr);
            break;
#endif
#if(NM_NUM_OF_FR_CHANNEL > 0)
        case NM_BUSNM_FRNM:
            ret = FrNm_GetLocalNodeIdentifier(NM_BUSNMID(NetworkHandle), nmNodeIdPtr);
            break;
#endif
#if(NM_NUM_OF_LIN_CHANNEL > 0)
        case NM_BUSNM_LINNM:
            ret = LinNm_GetLocalNodeIdentifier(NM_BUSNMID(NetworkHandle), nmNodeIdPtr);
            break;
#endif
#if(NM_NUM_OF_ETH_CHANNEL > 0)
        case NM_BUSNM_UDPNM:
            ret = UdpNm_GetLocalNodeIdentifier(NM_BUSNMID(NetworkHandle), nmNodeIdPtr);
            break;
#endif
        default:
            ret = E_NOT_OK;
            break;
        }
    }

    return ret;

}
#endif

#if(STD_ON == NM_REMOTE_SLEEP_IND_ENABLED)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Nm_CheckRemoteSleepIndication  Nm042
*
* Description:   Check if remote sleep indication takes place or not
*
* Inputs:        NetworkHandle Identification of the NM-channel.
*
* Outputs:       nmRemoteSleepIndPtr Pointer where check result of remote sleep indication
*                                    shall be copied to
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, NM_CODE) Nm_CheckRemoteSleepIndication
(
    CONST(NetworkHandleType, NMIF_CONST) NetworkHandle,
    CONSTP2VAR(boolean, AUTOMATIC, NMIF_CONST) nmRemoteSleepIndPtr
)
{
    Std_ReturnType ret = E_NOT_OK;

    if(!NM_IS_INITIALIZED())
    {
        /*Nm149*/
        NM_DET_REPORT_ERROR(NM_CHECKREMOTESLEEPINDICATION_APIID, NM_E_UNINIT);
    }
    else if(NetworkHandle >= (NetworkHandleType)NM_NUM_OF_CHANNELS)
    {
        NM_DET_REPORT_ERROR(NM_CHECKREMOTESLEEPINDICATION_APIID, NM_E_HANDLE_UNDEF);
    }
    else if(NULL_PTR == nmRemoteSleepIndPtr)
    {
        NM_DET_REPORT_ERROR(NM_CHECKREMOTESLEEPINDICATION_APIID, NM_E_PARAM_POINTER);
    }
    else
    {
        switch(NM_BUSTYPE(NetworkHandle))
        {
#if(NM_NUM_OF_CANNM_CHANNEL > 0)
        case NM_BUSNM_CANNM:
            ret = CanNm_CheckRemoteSleepIndication(NM_BUSNMID(NetworkHandle), nmRemoteSleepIndPtr);
            break;
#endif
#if(NM_NUM_OF_OSEKNM_CHANNEL > 0)
        case NM_BUSNM_OSEKNM:
            ret = E_OK;
            break;
#endif
#if(NM_NUM_OF_FR_CHANNEL > 0)
        case NM_BUSNM_FRNM:
            ret = FrNm_CheckRemoteSleepIndication(NM_BUSNMID(NetworkHandle), nmRemoteSleepIndPtr);
            break;
#endif
#if(NM_NUM_OF_LIN_CHANNEL > 0)
        case NM_BUSNM_LINNM:
            ret = LinNm_CheckRemoteSleepIndication(NM_BUSNMID(NetworkHandle), nmRemoteSleepIndPtr);
            break;
#endif
#if(NM_NUM_OF_ETH_CHANNEL > 0)
        case NM_BUSNM_UDPNM:
            ret = UdpNm_CheckRemoteSleepIndication(NM_BUSNMID(NetworkHandle), nmRemoteSleepIndPtr);
            break;
#endif
        default:
            ret = E_NOT_OK;
            break;
        }
    }

    return ret;

}
#endif

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Nm_GetState  Nm043
*
* Description:   Returns the state of the network management
*
* Inputs:        NetworkHandle Identification of the NM-channel.
*
* Outputs:       nmStatePtr Pointer where state of the network management shall be
*                           copied to
*                nmModePtr  Pointer to the location where the mode of the network
*                           management shall be copied to
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, NM_CODE) Nm_GetState
(
    CONST(NetworkHandleType, NMIF_CONST) NetworkHandle,
    CONSTP2VAR(Nm_StateType, AUTOMATIC, NMIF_CONST) nmStatePtr,
    CONSTP2VAR(Nm_ModeType, AUTOMATIC, NMIF_CONST) nmModePtr
)
{
    Std_ReturnType ret = E_NOT_OK;

    if(!NM_IS_INITIALIZED())
    {
        /*Nm151*/
        NM_DET_REPORT_ERROR(NM_GETSTATE_APIID, NM_E_UNINIT);
    }
    else if(NetworkHandle >= (NetworkHandleType)NM_NUM_OF_CHANNELS)
    {
        NM_DET_REPORT_ERROR(NM_GETSTATE_APIID, NM_E_HANDLE_UNDEF);
    }
    else if(NULL_PTR == nmStatePtr)
    {
        NM_DET_REPORT_ERROR(NM_GETSTATE_APIID, NM_E_PARAM_POINTER);
    }
    else if(NULL_PTR == nmModePtr)
    {
        NM_DET_REPORT_ERROR(NM_GETSTATE_APIID, NM_E_PARAM_POINTER);
    }
    else
    {
        switch(NM_BUSTYPE(NetworkHandle))
        {
#if(NM_NUM_OF_CANNM_CHANNEL > 0)
        case NM_BUSNM_CANNM:
            ret = CanNm_GetState(NM_BUSNMID(NetworkHandle), nmStatePtr, nmModePtr);
            break;
#endif
#if(NM_NUM_OF_OSEKNM_CHANNEL > 0)
        case NM_BUSNM_OSEKNM:
            ret = OsekNm_GetState(NM_BUSNMID(NetworkHandle), nmStatePtr, nmModePtr);
            break;
#endif
#if(NM_NUM_OF_FR_CHANNEL > 0)
        case NM_BUSNM_FRNM:
            ret = FrNm_GetState(NM_BUSNMID(NetworkHandle), nmStatePtr, nmModePtr);
            break;
#endif
#if(NM_NUM_OF_LIN_CHANNEL > 0)
        case NM_BUSNM_LINNM:
            ret = LinNm_GetState(NM_BUSNMID(NetworkHandle), nmStatePtr, nmModePtr);
            break;
#endif
#if(NM_NUM_OF_ETH_CHANNEL > 0)
        case NM_BUSNM_UDPNM:
            ret = UdpNm_GetState(NM_BUSNMID(NetworkHandle), nmStatePtr, nmModePtr);
            break;
#endif
        default:
            ret = E_NOT_OK;
            break;
        }
    }

    return ret;

}


#if(NM_VERSION_INFO_API == STD_ON)  /*Nm153*/
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Nm_GetVersionInfo   Nm044
*
* Description  : This function returns the version information of this module.
*
* Inputs       : nmVerInfoPtr: Indicator as to where to store the version infor-
*                              mation of this module.
*
* Outputs      : None.
*
* Limitations  : None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, NM_CODE) Nm_GetVersionInfo
(
    P2VAR(Std_VersionInfoType, AUTOMATIC, NM_APPL_DATA) nmVerInfoPtr
)
{
    if(NULL_PTR == nmVerInfoPtr)
    {
        NM_DET_REPORT_ERROR(NM_GETVERSIONINFO_APIID, NM_E_PARAM_POINTER);
    }
    else
    {
        /*Nm152*/
        nmVerInfoPtr->vendorID = NM_VENDOR_ID;
        nmVerInfoPtr->moduleID = NM_MODULE_ID;

        nmVerInfoPtr->sw_major_version = (uint8)NM_SW_MAJOR_VERSION;
        nmVerInfoPtr->sw_minor_version = (uint8)NM_SW_MINOR_VERSION;
        nmVerInfoPtr->sw_patch_version = (uint8)NM_SW_PATCH_VERSION;
    }
}
#endif


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Nm_NetworkStartIndication   Nm154
*
* Description  : Notification that a NM-message has been received in the Bus-Sleep
*                Mode, what indicates that some nodes in the network have already
*                entered the Network Mode
*
* Inputs       : nmNetworkHandle Identification of the NM-channel
*
* Outputs      : None.
*
* Limitations  : None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, NM_CODE) Nm_NetworkStartIndication
(
    CONST(NetworkHandleType, NMIF_CONST) nmNetworkHandle
)
{
    /*Nm155*/
    ComM_Nm_NetworkStartIndication(NM_COMMID(nmNetworkHandle));
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Nm_NetworkMode   Nm156
*
* Description  : Notification that the network management has entered Network Mode
*
* Inputs       : nmNetworkHandle Identification of the NM-channel
*
* Outputs      : None.
*
* Limitations  : None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, NM_CODE) Nm_NetworkMode
(
    CONST(NetworkHandleType, NMIF_CONST) nmNetworkHandle
)
{
    /*Nm158*/
    ComM_Nm_NetworkMode(NM_COMMID(nmNetworkHandle));
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Nm_BusSleepMode   Nm162
*
* Description  : Notification that the network management has entered Bus-Sleep Mode.
*
* Inputs       : nmNetworkHandle Identification of the NM-channel
*
* Outputs      : None.
*
* Limitations  : None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, NM_CODE) Nm_BusSleepMode
(
    CONST(NetworkHandleType, NMIF_CONST) nmNetworkHandle
)
{
    /*Nm163*/
    ComM_Nm_BusSleepMode(NM_COMMID(nmNetworkHandle));
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Nm_PrepareBusSleepMode   Nm159
*
* Description  : Notification that the network management has entered Prepare Bus-Sleep Mode.
*
* Inputs       : nmNetworkHandle Identification of the NM-channel
*
* Outputs      : None.
*
* Limitations  : None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, NM_CODE) Nm_PrepareBusSleepMode
(
    CONST(NetworkHandleType, NMIF_CONST) nmNetworkHandle
)
{
    /*Nm161*/
    ComM_Nm_PrepareBusSleepMode(NM_COMMID(nmNetworkHandle));
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Nm_RemoteSleepIndication   Nm192
*
* Description  : Notification that the network management has detected that all
*                other nodes on the network are ready to enter Bus-Sleep Mode.
*
* Inputs       : nmNetworkHandle Identification of the NM-channel
*
* Outputs      : None.
*
* Limitations  : None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, NM_CODE) Nm_RemoteSleepIndication
(
    CONST(NetworkHandleType, NMIF_CONST) nmNetworkHandle
)
{
    (void)nmNetworkHandle;
    /*The notification that all other nodes on the network are ready to enter
    Bus-Sleep Mode is only needed for internal purposes of the NM Coordinator.*/
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Nm_RemoteSleepCancellation   Nm193
*
* Description  : Notification that the network management has detected that not
*                all other nodes on the network are longer ready to enter Bus-Sleep Mode.
*
* Inputs       : nmNetworkHandle Identification of the NM-channel
*
* Outputs      : None.
*
* Limitations  : None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, NM_CODE) Nm_RemoteSleepCancellation
(
    CONST(NetworkHandleType, NMIF_CONST) nmNetworkHandle
)
{
    (void)nmNetworkHandle;
    /*The notification that not all other nodes on the network are longer ready to
    enter BusSleep Mode is only needed for internal purposes of the NM Coordinator.*/
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Nm_SynchronizationPoint   Nm194
*
* Description  : Notification to the NM Coordinator functionality that this is a
*                suitable point in time to initiate the coordination algorithm on
*
* Inputs       : nmNetworkHandle Identification of the NM-channel
*
* Outputs      : None.
*
* Limitations  : None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, NM_CODE) Nm_SynchronizationPoint
(
    CONST(NetworkHandleType, NMIF_CONST) nmNetworkHandle
)
{
    (void)nmNetworkHandle;
    /*The notification that this is a suitable point in time to initiate the coordination
    algorithm on is only needed for internal purposes of the NM Coordinator.*/
}

#if(STD_ON == NM_PDU_RXINDICATION_ENABLED) /*Nm164*/
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Nm_PduRxIndication   Nm112
*
* Description  : Notification that a NM message has been received.
*
* Inputs       : nmNetworkHandle Identification of the NM-channel
*
* Outputs      : None.
*
* Limitations  : None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, NM_CODE) Nm_PduRxIndication
(
    CONST(NetworkHandleType, NMIF_CONST) nmNetworkHandle
)
{
    /*The notification that an NM message has been received is only needed for OEM
    specific extensions of the NM Coordinator.*/
	Nm_PduRxIndication_Callout(nmNetworkHandle);
}
#endif

#if(STD_ON == NM_STATE_CHANGE_IND_ENABLED) /*Nm165*/
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Nm_StateChangeNotification   Nm114
*
* Description  : Notification that the state of the lower layer <BusNm> has changed.
*
* Inputs       : nmNetworkHandle Identification of the NM-channel
*                nmPreviousState
*
* Outputs      : None.
*
* Limitations  : None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, NM_CODE) Nm_StateChangeNotification
(
    CONST(NetworkHandleType, NMIF_CONST) nmNetworkHandle,
    CONST(Nm_StateType, NMIF_CONST) nmPreviousState,
    CONST(Nm_StateType, NMIF_CONST) nmCurrentState
)
{
    Nm_StateChangeIndCallout(nmNetworkHandle, nmPreviousState, nmCurrentState);
}
#endif

#if(STD_ON == NM_REPEAT_MSG_IND_ENABLED) /*Nm231*/
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Nm_RepeatMessageIndication   Nm230
*
* Description  : Service to indicate that an NM message with set Repeat Message
*                Request Bit has been received.
*
* Inputs       : nmNetworkHandle Identification of the NM-channel
*
* Outputs      : None.
*
* Limitations  : None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, NM_CODE) Nm_RepeatMessageIndication
(
    CONST(NetworkHandleType, NMIF_CONST) nmNetworkHandle
)
{
    (void)nmNetworkHandle;
    /*The notification that an NM message with the set Repeat Message Bit has been
    received is only needed for OEM specific extensions of the NM Coordinator*/
}
#endif

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Nm_TxTimeoutException   Nm234
*
* Description  : Service to indicate that an attempt to send an NM message failed.
*
* Inputs       : nmNetworkHandle Identification of the NM-channel
*
* Outputs      : None.
*
* Limitations  : None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, NM_CODE) Nm_TxTimeoutException
(
    CONST(NetworkHandleType, NMIF_CONST) nmNetworkHandle
)
{
    (void)nmNetworkHandle;
    /*The notification that an attempt to send an NM message failed is only needed
    for OEM specific extensions of the Nm*/
}

#if(STD_ON == NM_CAR_WAKEUP_RX_ENABLED) /*Nm251*/
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Nm_CarWakeUpIndication   Nm250
*
* Description  : This function is called by a <Bus>Nm to indicate reception of a CWU request
*
* Inputs       : nmNetworkHandle Identification of the NM-channel
*
* Outputs      : None.
*
* Limitations  : None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, NM_CODE) Nm_CarWakeUpIndication
(
    CONST(NetworkHandleType, NMIF_CONST) nmNetworkHandle
)
{
    NM_CAR_WAKE_UP_CBK(nmNetworkHandle);
}
#endif

#if(STD_ON == NM_COORDINATOR_SUPPORT)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Nm_CoordReadyToSleepIndication   Nm254
*
* Description  : Sets an indication, when the NM Coordinator Sleep Ready bit in
*                the Control Bit Vector is set
*
* Inputs       : nmNetworkHandle Identification of the NM-channel
*
* Outputs      : None.
*
* Limitations  : None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, NM_CODE) Nm_CoordReadyToSleepIndication
(
    CONST(NetworkHandleType, NMIF_CONST) nmNetworkHandle
)
{
    (void)nmNetworkHandle;
    /*The notification that an attempt to send an NM message failed is only needed
    for OEM specific extensions of the Nm*/
}
#endif

#if(STD_ON == NM_COORDINATOR_SUPPORT)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Nm_MainFunction   Nm118
*
* Description  : This function implements the processes of the NM Interface, which
*                need a fix cyclic scheduling.
*
* Inputs       : None
*
* Outputs      : None.
*
* Limitations  : None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, NM_CODE) Nm_MainFunction
(
    void
)
{
    if(!NM_IS_INITIALIZED())
    {
        /*Nm121*/
    }
    else
    {

    }

}
#endif


#define NM_STOP_SEC_CODE
#include "MemMap.h"


