/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE                              
*   This software is the property of HiRain Technologies. Any information 
*   contained in this doc should not be reproduced, or used, or disclosed 
*   without the written authorization from HiRain Technologies.
********************************************************************************
*   File Name       : EthIf.c
********************************************************************************
*   Project/Product : AUTOSAR 4.2.2
*   Title           : Ethernet Interface module Source File
*   Author          : Hirain
********************************************************************************
*   Description     : Implementation of Ethernet Interface 
*                     provided functionality
*
********************************************************************************
*   Limitations     : None
*
********************************************************************************
*
********************************************************************************
*   Revision History:
* 
*   Version     Date          Initials       CR#          Descriptions
*   ---------   ----------    ------------   ----------   ---------------
*   01.00.00    10/10/2017    junfei.chen    N/A          Original
*   01.00.01    19/04/2018    xueyu.zhao     N/A          add VLAN and switch
*   01.00.02    17/07/2018    xueyu.zhao     N/A          after test and QAC
*   01.00.03    20/12/2018    xueyu.zhao     N/A          First release version
*   01.00.04    16/08/2019    qiang.yang     N/A          ETH422_EthIf_20190816_01
*   01.00.05    28/06/2020    tianrui.zhang  N/A          ETH422_EthIf_20200628_01
*   01.00.06    04/09/2020    tianrui.zhang  N/A          ETH422_EthIf_20200904_01
*   01.00.07    21/04/2022    wenbo.cui      N/A          after test
*   01.00.08    05/05/2023    hao.liu8       N/A          Updated version number
*   01.00.09    16/05/2023    hao.liu8       N/A          delete error version number
*   01.00.10    01/06/2023    hao.liu8       N/A          ETH422_EthIf_20230601_01
*   01.01.00    20/07/2023    yanheng.he     N/A          Fix ETHIF_CALLUP_TRCVMODE_INDICATION lack of input parameter
*   01.01.01    02/08/2023    yanheng.he     N/A          Fix DET 'PhysAddrPtr' error of function EthIf_Transmit 
*   01.01.02    21/09/2023    yanheng.he     N/A          Optimized header file structure 
*   01.01.03    27/09/2023    yanheng.he     N/A          Fix None Controller transceiver's mode can not switch to active
********************************************************************************
* END_FILE_HDR*/

/******************************************************************************
*   General QAC Suppression
******************************************************************************/
/*PRQA S 3206 EOF*/
/* No use info */

/*PRQA S 3429,3453 EOF*/
/* Function-like macros will be used in this file */ 

/*PRQA S 3214,3138,3141,862,3614,1853 EOF*/
/* Some macros are defined but not used, they are reserved according to AUTOSAR specification */

/*PRQA S 3432,3409,3410,3672,5087,0515,0563 EOF*/
/* The defination of APIs follows AUTOSAR standard */

/*PRQA S 3416 EOF*/
/* Enable calling APIs in a if-condition */

/*PRQA S 1860,1862,1863,3383,3384 EOF*/
/* Comparison,++,equal operation,will change into integer.This problem is risk-free and can't be revised */  

/*******************************************************************************
*   Includes
*******************************************************************************/                     
#include "EthIf.h"
#include "Bsw_Common.h"
#include "SchM_EthIf.h"

#if(ETHIF_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"
#endif

/******************************************************************************
 *  Version Check
 ******************************************************************************/
#if(STD_ON == ETHIF_PRIVATE_VERSION_CHECK)
/* check Version with other import module */
/* check Version with cfg file */
#if((ETHIF_AR_RELEASE_MAJOR_VERSION != ETHIF_AR_RELEASE_MAJOR_VERSION_CFG) || \
   (ETHIF_AR_RELEASE_MINOR_VERSION != ETHIF_AR_RELEASE_MINOR_VERSION_CFG))
#error "AutoSar Version Numbers of EthIf and its cfg file are different"
#endif
#endif

#if(STD_ON == ETHIF_DEV_ERROR_DETECT)
#define ETHIF_DET_ERROR_DETECT(cond, ApiId, errcode)  \
        DET_ERROR_DETECT((cond), ETHIF_MODULE_ID, ETHIF_INSTANCE_ID,(ApiId),(errcode))
    
#define ETHIF_DET_ERROR_DETECT_RET(cond, ApiId, errcode, ret) \
        DET_ERROR_DETECT_RET((cond), ETHIF_MODULE_ID,ETHIF_INSTANCE_ID,(ApiId),(errcode), (ret))
    
#define ETHIF_DET_REPORT_ERROR(ApiId, errcode)  \
        DET_REPORT_ERROR(ETHIF_MODULE_ID, ETHIF_INSTANCE_ID, (ApiId), (errcode))    
#else
#define ETHIF_DET_ERROR_DETECT(cond, ApiId, errcode)
#define ETHIF_DET_ERROR_DETECT_RET(cond, ApiId, errcode, ret)
#define ETHIF_DET_REPORT_ERROR(ApiId, errcode)
#endif

#define ETHIF_START_SEC_VAR_INIT_8

#include "MemMap.h"
STATIC VAR(EthIf_StateType, ETHIF_VAR_INIT) EthIf_InitState = ETHCTRL_STATE_UNINIT;
#define ETHIF_STOP_SEC_VAR_INIT_8
#include "MemMap.h"

#define ETHIF_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" 
STATIC P2CONST(EthIf_ConfigType, AUTOMATIC, AUTOMATIC)  EthIf_DefaultCfgPtr;
STATIC EthIf_TrcvLinkCheckType EthIf_CheckLinkStateFreqCnt;
#define ETHIF_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"    


/******************************************************************************
*   Macros
******************************************************************************/
#define ETHIF_INVALID_OWNER                     ((uint8)0xFF)
#define ETHIF_VLAN_TAG_LEN                      ((uint16)4)
#define ETHIF_VLAN_FRAME_TYPE                   ((Eth_FrameType)0x8100)

#define ETHIF_GETTXBUFOWNER(CtrlIdx, BufIdx)    (EthIf_TxBufOwner[CtrlIdx][BufIdx])

/*get config information*/
#define ETHIF_GET_CTRL_NUMBER()                 (EthIf_DefaultCfgPtr->CtrlNum)
#define ETHIF_GET_CTRL_PTR(idx)                 (&(EthIf_DefaultCfgPtr->CtrlCfg[idx]))
#define ETHIF_GET_TRCV_NUMBER()                 (EthIf_DefaultCfgPtr->TrcvNum)
#define ETHIF_GET_TRCV_PTR(idx)                 (&(EthIf_DefaultCfgPtr->TrcvCfg[idx]))
#define ETHIF_GET_SWT_NUMBER()                  (EthIf_DefaultCfgPtr->SwtNum)
#define ETHIF_GET_SWT_PTR(idx)                  (&(EthIf_DefaultCfgPtr->SwtCfg[idx]))
#define ETHIF_GET_SWT_PORT_NUMBER()             (EthIf_DefaultCfgPtr->SwtPortNum)
#define ETHIF_GET_SWT_PORT_PTR(idx)             (&(EthIf_DefaultCfgPtr->SwtPortCfg[idx]))
#define ETHIF_GET_SWT_PORTGROUP_NUMBER()        (EthIf_DefaultCfgPtr->SwtPortGroupNum)
#define ETHIF_GET_SWT_PORTGROUP_PTR(idx)        (&(EthIf_DefaultCfgPtr->SwtPortGroupCfg[idx]))
#define ETHIF_GET_OWNER_NUMBER()                (EthIf_DefaultCfgPtr->FrameOwnerNum)
#define ETHIF_GET_OWNER_PTR(idx)                (&(EthIf_DefaultCfgPtr->FrameOwnerCfg[idx]))
#define ETHIF_GET_TRCV_LINKCHG_NUMBER()         (EthIf_DefaultCfgPtr->TrcvLinkChgNum)
#define ETHIF_GET_TRCV_LINKCHG(idx)             (EthIf_DefaultCfgPtr->TrcvLinkStateChgs[idx])
#define ETHIF_GET_RXIND_NUMBER()                (EthIf_DefaultCfgPtr->RxTxCbkNum)
#define ETHIF_GET_RXIND(idx)                    (EthIf_DefaultCfgPtr->RxIndCfg[idx])
#define ETHIF_GET_TXCONF(idx)                   (EthIf_DefaultCfgPtr->TxConfCfg[idx])

/*get controller information*/
#define ETHIF_GET_PHYTYPE(CtrlIdx)              (ETHIF_GET_CTRL_PTR(CtrlIdx)->PhyType)
#define ETHIF_GET_TXBUF_NUMBER(CtrlIdx)         (ETHIF_GET_CTRL_PTR(CtrlIdx)->TxBufNum)
#define ETHIF_GET_HWCTRL_STATE_PTR(CtrlIdx)     (ETHIF_GET_CTRL_PTR(CtrlIdx)->HwStatePtr)
#define ETHIF_GET_CTRL_STATE_PTR(CtrlIdx)       (ETHIF_GET_CTRL_PTR(CtrlIdx)->StatePtr)
#define ETHIF_GET_CTRL_MODE(CtrlIdx)            (ETHIF_GET_CTRL_STATE_PTR(CtrlIdx)->CtrlMode)
#define ETHIF_GET_TRCV_MODE(CtrlIdx)            (ETHIF_GET_CTRL_STATE_PTR(CtrlIdx)->TrcvMode)
#define ETHIF_GET_CTRL_MODE_PTR(CtrlIdx)        (&ETHIF_GET_CTRL_STATE_PTR(CtrlIdx)->CtrlMode)
#define ETHIF_GET_TRCV_MODE_PTR(CtrlIdx)        (&ETHIF_GET_CTRL_STATE_PTR(CtrlIdx)->TrcvMode)
#define ETHIF_GET_TRCV_LINK_STATE_PTR(CtrlIdx)  (&ETHIF_GET_CTRL_STATE_PTR(CtrlIdx)->LinkState)
#define ETHIF_GET_CTRL_API_PTR(CtrlIdx)         (ETHIF_GET_CTRL_PTR(CtrlIdx)->EthApis)
#define ETHIF_GET_SWTPORT_GROUP_PTR(CtrlIdx)    (ETHIF_GET_SWT_PORTGROUP_PTR(ETHIF_GET_CTRL_PTR(CtrlIdx)->PhyIdx))

/*get trcv information*/
#define ETHIF_GET_HWTRCV_STATE(TrcvIdx)             (ETHIF_GET_TRCV_PTR(TrcvIdx)->HwStatePtr)
#define ETHIF_GET_TRCV_API_PTR(TrcvIdx)             (ETHIF_GET_TRCV_PTR(TrcvIdx)->TrcvApis)
#define ETHIF_GET_TRCV_PTR_BY_CTRLIDX(CtrlIdx)      (ETHIF_GET_TRCV_PTR(ETHIF_GET_CTRL_PTR(CtrlIdx)->PhyIdx))
#define ETHIF_GET_HWTRCV_STATE_BY_CTRLIDX(CtrlIdx)  (ETHIF_GET_TRCV_PTR(ETHIF_GET_CTRL_PTR(CtrlIdx)->PhyIdx)->HwStatePtr)
#define ETHIF_GET_TRCV_API_PTR_BY_CTRLIDX(CtrlIdx)  (ETHIF_GET_TRCV_PTR(ETHIF_GET_CTRL_PTR(CtrlIdx)->PhyIdx)->TrcvApis)

/*get swt information*/
#define ETHIF_GET_SWT_API_PTR(SwtIdx)               (ETHIF_GET_SWT_PTR(SwtIdx)->SwtApis)

/*get swt port information*/
#define ETHIF_GET_HWPORT_STATE(PortIdx)    (ETHIF_GET_SWT_PORT_PTR(PortIdx)->HwStatePtr)
#define ETHIF_GET_PORT_STATE(PortIdx)      (ETHIF_GET_SWT_PORT_PTR(PortIdx)->StatePtr)
#define ETHIF_GET_PORT_API_PTR(PortIdx)    (ETHIF_GET_SWT_API_PTR(ETHIF_GET_SWT_PORT_PTR(PortIdx)->SwtIdx))
#define ETHIF_GET_HWPORT_IDX(PortIdx1)     (ETHIF_GET_SWT_PORT_PTR(PortIdx1)->PortIdx)
#define ETHIF_GET_HWSWT_IDX(PortIdx)       (ETHIF_GET_SWT_PTR(ETHIF_GET_SWT_PORT_PTR(PortIdx)->SwtIdx)->SwitchIdx)

/*0 & 65535 is defined as invalid VlanId in protocol IEEE 802.1Q */
#define ETHIF_VLANID_PTR                       (ETHIF_GET_CTRL_PTR(CtrlIdx)->VlanId)
#define ETHIF_CTRL_IS_VLAN(CtrlIdx)            ((ETHIF_VLANID_PTR!=0x0000)&&(ETHIF_VLANID_PTR!=0xFFFF))

/*PRQA S 3435,3456 ++*/
/*the cfgptr pointer can be used multiple times */
#define ETHIF_CFG_CHECK_ERROR(CfgPtr)            ((0==(CfgPtr)->CtrlNum)||(NULL_PTR==(CfgPtr)->CtrlCfg)\
    ||((0<(CfgPtr)->SwtNum) && (NULL_PTR==(CfgPtr)->SwtCfg))\
    ||(0==(CfgPtr)->FrameOwnerNum)||(NULL_PTR==(CfgPtr)->FrameOwnerCfg)\
    ||(0==(CfgPtr)->TrcvLinkChgNum)||(NULL_PTR==(CfgPtr)->TrcvLinkStateChgs)\
    ||(0==(CfgPtr)->RxTxCbkNum)||(NULL_PTR==(CfgPtr)->RxIndCfg)||(NULL_PTR==(CfgPtr)->TxConfCfg))
/*PRQA S 3435,3456 --*/


/******************************************************************************
 * Local Functions Declaration
 ******************************************************************************/
#define ETHIF_START_SEC_CODE
#include "MemMap.h"
STATIC FUNC(void, ETHIF_CODE) EthIf__InitCtrlState
(
    uint8 CtrlIdx
);
STATIC FUNC(Std_ReturnType, ETHIF_CODE) EthIf__SetHwCtrlActive
(
    uint8 CtrlIdx
);
STATIC FUNC(Std_ReturnType, ETHIF_CODE) EthIf__SetHwCtrlDown
(
    uint8 CtrlIdx
);
STATIC FUNC(Std_ReturnType, ETHIF_CODE) EthIf__SetTrcvActive
(
    uint8 CtrlIdx
);
STATIC FUNC(Std_ReturnType, ETHIF_CODE) EthIf__SetTrcvDown
(
    uint8 CtrlIdx
);
STATIC FUNC(void, ETHIF_CODE) EthIf__PollTrcvLinkState
(
    void
);
STATIC FUNC(Std_ReturnType, ETHIF_CODE) EthIf__GetTrcvLinkState
(
    uint8 CtrlIdx,
    P2VAR(EthTrcv_LinkStateType, AUTOMATIC, ETHIF_APPL_DATA) LinkState
);
STATIC FUNC(Std_ReturnType, ETHIF_CODE) EthIf__GetPortGroupLinkState
(
    uint8 CtrlIdx,
    P2VAR(EthTrcv_LinkStateType, AUTOMATIC, ETHIF_APPL_DATA) LinkState
);
#if(ETHIF_WAKEUP_SUPPORT == STD_ON)
STATIC FUNC(Std_ReturnType, ETHIF_CODE) EthIf__GetCheckWakeupFct
(
    uint8 TrcvId,
    P2VAR(EthIf_EthTrcvCheckWakeupType, AUTOMATIC, ETHIF_APPL_DATA) FctPtr
);
#endif

/******************************************************************************
*   Function Define
******************************************************************************/
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: EthIf_Init
*                
* Description:   Initialize the complete EthIf module. 
*                             
* Inputs:        CfgPtr: Pointer to a selected configuration structure.
*             
* Outputs:       None
* 
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, ETHIF_CODE) EthIf_Init
(
    P2CONST(EthIf_ConfigType, AUTOMATIC, ETHIF_APPL_DATA) CfgPtr
)
{
    uint8 CtrlId;
    uint8 TxBufId;
        
#if(ETHIF_CONFIG_VARIANTS == STD_CONFIG_VARIANTS_POSTBUILD)
    if(NULL_PTR == CfgPtr)
    {
        ETHIF_DET_REPORT_ERROR(ETHIF_API_ID_INIT, ETHIF_E_PARAM_POINTER);
    }
    else
#endif
    {
#if(ETHIF_CONFIG_VARIANTS == STD_CONFIG_VARIANTS_POSTBUILD)
        /*[SWS_EthIf_00025]*/
        EthIf_DefaultCfgPtr = CfgPtr;
#else
        EthIf_DefaultCfgPtr = ETHIF_DEFAULT_CONFIGURATION_PTR;
#endif    

        /*[SWS_EthIf_00116] && [ECUC_EthIf_00010]*/
        if (ETHIF_CFG_CHECK_ERROR(EthIf_DefaultCfgPtr))
        {
            ETHIF_DET_REPORT_ERROR(ETHIF_API_ID_INIT, ETHIF_E_INIT_FAILED);
        }
        else
        {
            EthIf_CheckLinkStateFreqCnt.FreqCnt = (uint8)0;
            EthIf_CheckLinkStateFreqCnt.CtrlIdx = ETHIF_GET_CTRL_NUMBER();

            for (CtrlId = (uint8)0; CtrlId < ETHIF_GET_CTRL_NUMBER(); CtrlId++)
            {
                *ETHIF_GET_HWCTRL_STATE_PTR(CtrlId) = (uint8)0;

                EthIf__InitCtrlState(CtrlId);

                for (TxBufId = (uint8)0; TxBufId < ETHIF_GET_TXBUF_NUMBER(CtrlId); TxBufId++)
                {
                    EthIf_TxBufOwner[CtrlId][TxBufId] = ETHIF_INVALID_OWNER;
                }
            }
           
            /*[SWS_EthIf_00114]*/
            EthIf_InitState = ETHCTRL_STATE_INIT;
        }
    }
}

STATIC FUNC(void, ETHIF_CODE) EthIf__InitCtrlState
(
    uint8 CtrlIdx
)
{
    uint8 i;
    uint8 PortMax;
    P2VAR(EthIf_CtrlType, AUTOMATIC, AUTOMATIC) CtrlStatePtr;
    P2CONST(EthIf_SwtPortGroupType, AUTOMATIC, AUTOMATIC) SwtPortGroupPtr;

    CtrlStatePtr = ETHIF_GET_CTRL_STATE_PTR(CtrlIdx);


    CtrlStatePtr->CtrlMode = ETH_MODE_DOWN;
    CtrlStatePtr->TrcvMode = ETHTRCV_MODE_DOWN;
    CtrlStatePtr->LinkState = ETHTRCV_LINK_STATE_DOWN;

    switch(ETHIF_GET_PHYTYPE(CtrlIdx))
    {
    case ETHIF_TRCV:
        *(ETHIF_GET_HWTRCV_STATE_BY_CTRLIDX(CtrlIdx)) = ETH_MODE_DOWN;
        break;
    case ETHIF_SWTPORT_GROUP:
        SwtPortGroupPtr = ETHIF_GET_SWTPORT_GROUP_PTR(CtrlIdx);
        PortMax = SwtPortGroupPtr->PortIdx + SwtPortGroupPtr->PortNum;
        for(i = SwtPortGroupPtr->PortIdx;i < PortMax; i++)
        {
            *ETHIF_GET_HWPORT_STATE(i) = (uint8)0;
        }
        break;
    default:
        /* Intentionally Empty */
        break;
    }
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: EthIf_SetControllerMode
*                
* Description:   Set the controller mode.
*                             
* Inputs:        CtrlIdx  : the index of the ethernet interface controller.
*                CtrlMode : the mode of the ethernet controller.
*             
* Outputs:       None
* 
* Limitations:   Call it after EthIf_Init has been called.
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, ETHIF_CODE) EthIf_SetControllerMode
(
    uint8 CtrlIdx,
    Eth_ModeType CtrlMode
)
{
    boolean immediateInd = FALSE;
    Std_ReturnType ret = E_NOT_OK;    
    P2VAR(Eth_ModeType, AUTOMATIC, AUTOMATIC) CtrlModePtr;

    /*[SWS_EthIf_00036]*/
    if (ETHCTRL_STATE_INIT != EthIf_InitState)
    {
        ETHIF_DET_REPORT_ERROR(ETHIF_API_ID_SETCONTROLLERMODE, ETHIF_E_NOT_INITIALIZED);
    }
    /*[SWS_EthIf_00037]*/
    else if (CtrlIdx >= ETHIF_GET_CTRL_NUMBER())
    {
        ETHIF_DET_REPORT_ERROR(ETHIF_API_ID_SETCONTROLLERMODE, ETHIF_E_INV_CTRL_IDX);
    }
    else
    {
        CtrlModePtr = ETHIF_GET_CTRL_MODE_PTR(CtrlIdx);
        if(*CtrlModePtr == CtrlMode)
        {
            ret = E_OK;
            immediateInd = TRUE;
        }
        else if(CtrlMode == ETH_MODE_ACTIVE)
        {
            /*SWS_EthIf_00035*/
            ret = EthIf__SetHwCtrlActive(CtrlIdx);
        }
        else
        {
            /*SWS_EthIf_00035*/
            ret = EthIf__SetHwCtrlDown(CtrlIdx);
        }
    }
    
    /*update virtual controller mode && inform upper layer of the new controller mode*/
    if(ret == E_OK)
    {
        *CtrlModePtr = CtrlMode;
        if((ETHIF_CTRL_IS_VLAN(CtrlIdx)) || (immediateInd == TRUE))
        {
            ETHIF_CALLUP_CTRLMODE_INDICATION(CtrlIdx, CtrlMode);
        }
    }

    return ret;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: EthIf__SetHwCtrlActive
*
* Description:   set  the hardware controller of the EthIf controller to ACTIVE, or just update the
              Active counter.
*
* Inputs:         CtrlIdx: EthIf controller index
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(Std_ReturnType, ETHIF_CODE) EthIf__SetHwCtrlActive
(
    uint8 CtrlIdx
)
{
    Std_ReturnType ret;
    EthIf_EthSetControllerModeType EthSetModeFctPtr;
    P2VAR(uint8, AUTOMATIC, AUTOMATIC) HwCtrlModePtr;

    ret = E_OK;
    HwCtrlModePtr = ETHIF_GET_HWCTRL_STATE_PTR(CtrlIdx);
    if(!ETHIF_CTRL_IS_VLAN(CtrlIdx))
    {
        EthSetModeFctPtr = ETHIF_GET_CTRL_API_PTR(CtrlIdx)->SetCtrlMode;
        if(NULL_PTR != EthSetModeFctPtr)
        {
            ret = EthSetModeFctPtr(ETHIF_GET_CTRL_PTR(CtrlIdx)->CtrlIdx, ETH_MODE_ACTIVE);
        }
    }
    else if(*HwCtrlModePtr == 0)
    {
        EthSetModeFctPtr = ETHIF_GET_CTRL_API_PTR(CtrlIdx)->SetCtrlMode;
        if(NULL_PTR != EthSetModeFctPtr)
        {
            ret = EthSetModeFctPtr(ETHIF_GET_CTRL_PTR(CtrlIdx)->CtrlIdx, ETH_MODE_ACTIVE);
            if(ret == E_OK)
            {
                *HwCtrlModePtr += 1;
            }
        }
    }
    else
    {
        *HwCtrlModePtr += 1;
    }

    return ret;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: EthIf__SetHwCtrlDown
*
* Description:   set  the hardware controller of the EthIf controller to DOWN, or just update the
              Active counter.
*
* Inputs:         CtrlIdx: EthIf controller index
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(Std_ReturnType, ETHIF_CODE) EthIf__SetHwCtrlDown
(
    uint8 CtrlIdx
)
{
    Std_ReturnType ret;
    EthIf_EthSetControllerModeType EthSetModeFctPtr;
    P2VAR(uint8, AUTOMATIC, AUTOMATIC) HwCtrlModePtr;

    ret = E_OK;
    HwCtrlModePtr = ETHIF_GET_HWCTRL_STATE_PTR(CtrlIdx);

    if(!ETHIF_CTRL_IS_VLAN(CtrlIdx))
    {
        EthSetModeFctPtr = ETHIF_GET_CTRL_API_PTR(CtrlIdx)->SetCtrlMode;
        if(NULL_PTR != EthSetModeFctPtr)
        {
            ret = EthSetModeFctPtr(ETHIF_GET_CTRL_PTR(CtrlIdx)->CtrlIdx, ETH_MODE_DOWN);
        }
    }
    else if(*HwCtrlModePtr == 1)
    {
        EthSetModeFctPtr = ETHIF_GET_CTRL_API_PTR(CtrlIdx)->SetCtrlMode;
        if(NULL_PTR != EthSetModeFctPtr)
        {
            ret = EthSetModeFctPtr(ETHIF_GET_CTRL_PTR(CtrlIdx)->CtrlIdx, ETH_MODE_DOWN);
            if(ret == E_OK)
            {
                *HwCtrlModePtr -= 1;
            }
        }
    }
    else if(*HwCtrlModePtr > 1)
    {
        *HwCtrlModePtr -= 1;
    }
    else
    {
        /* Intentionally Empty */
    }
    return ret;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: EthIf_GetControllerMode
*                
* Description:   Get the controller mode. 
*                             
* Inputs:        CtrlIdx     : the index of the ethernet interface controller.
*                CtrlModePtr : Pointer to store the controller mode.
*             
* Outputs:       None
* 
* Limitations:   Call it after EthIf_Init has been called.
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, ETHIF_CODE) EthIf_GetControllerMode
(
    uint8 CtrlIdx,
    P2VAR(Eth_ModeType, AUTOMATIC, ETHIF_APPL_DATA) CtrlModePtr
)
{
    Std_ReturnType ret = E_NOT_OK;    

    /*[SWS_EthIf_00041]*/
    if (ETHCTRL_STATE_INIT != EthIf_InitState)
    {
        ETHIF_DET_REPORT_ERROR(ETHIF_API_ID_SETCONTROLLERMODE, ETHIF_E_NOT_INITIALIZED);
    }
    /*[SWS_EthIf_00042]*/
    else if (CtrlIdx >= ETHIF_GET_CTRL_NUMBER())
    {
        ETHIF_DET_REPORT_ERROR(ETHIF_API_ID_SETCONTROLLERMODE, ETHIF_E_INV_CTRL_IDX);
    }
    /*[SWS_EthIf_00043]*/
    else if (NULL_PTR == CtrlModePtr)
    {
        ETHIF_DET_REPORT_ERROR(ETHIF_API_ID_SETCONTROLLERMODE, ETHIF_E_PARAM_POINTER);
    }
    else
    {
        ret = E_OK;
        *CtrlModePtr = ETHIF_GET_CTRL_MODE(CtrlIdx);
    }
    return ret;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: EthIf_SetTransceiverMode
*                
* Description:   Set the transceiver mode. 
*                             
* Inputs:        CtrlIdx     : the index of a ethernet interface controller.
*                TrcvModePtr : Pointer to store the transceiver mode.
*             
* Outputs:       None
* 
* Limitations:   Call it after EthIf_Init has been called.
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, ETHIF_CODE) EthIf_SetTransceiverMode
(
    uint8 CtrlIdx,
    EthTrcv_ModeType TrcvMode
)
{
    Std_ReturnType ret;
    P2VAR(EthTrcv_ModeType, AUTOMATIC, AUTOMATIC) TrcvModePtr;

    ret = E_NOT_OK;
        
    /*[SWS_EthIf_00052]*/
    if (ETHCTRL_STATE_INIT != EthIf_InitState)
    {
        ETHIF_DET_REPORT_ERROR(ETHIF_API_ID_SETTRANSCEIVERMODE, ETHIF_E_NOT_INITIALIZED);
    }
    /*[SWS_EthIf_00053]*/
    else if (CtrlIdx >= ETHIF_GET_CTRL_NUMBER())
    {
        ETHIF_DET_REPORT_ERROR(ETHIF_API_ID_SETTRANSCEIVERMODE, ETHIF_E_INV_TRCV_IDX);
    }
    else
    {
        TrcvModePtr = ETHIF_GET_TRCV_MODE_PTR(CtrlIdx);
        if(*TrcvModePtr == TrcvMode)
        {
            ret = E_OK;
        }
        else if(TrcvMode == ETHTRCV_MODE_ACTIVE)
        {
            /*[SWS_EthIf_00051]*/
            ret = EthIf__SetTrcvActive(CtrlIdx);
        }
        else
        {
            /*[SWS_EthIf_00051]*/
            ret = EthIf__SetTrcvDown(CtrlIdx);
        }
    }

    if(ret == E_OK)
    {
        *TrcvModePtr = TrcvMode;
        /*update virtual controller mode && inform upper layer of the new controller mode*/        
        if(ETHIF_CTRL_IS_VLAN(CtrlIdx) || (ETHIF_GET_PHYTYPE(CtrlIdx) == ETHIF_NONE))
        {
            ETHIF_CALLUP_TRCVMODE_INDICATION(CtrlIdx, TrcvMode);
        }
    }    

    return ret;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: EthIf__SetTrcvActive
*
* Description:   set  the hardware transceiver of the EthIf controller to ACTIVE, or just update the
              Active counter.
*
* Inputs:         CtrlIdx: EthIf controller index
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(Std_ReturnType, ETHIF_CODE) EthIf__SetTrcvActive
(
    uint8 CtrlIdx
)
{
    uint8 i;
    uint8 PortMax;
    Std_ReturnType ret;
    Std_ReturnType retTmp;
    P2VAR(Eth_ModeType, AUTOMATIC, AUTOMATIC) HwPhyStatePtr;
    EthIf_EthTrcvSetTransceiverModeType EthTrcvSetModeFctPtr;
    EthIf_SetSwtPortModeType EthSetSwtPortModeFctPtr;
    P2CONST(EthIf_SwtPortGroupType, AUTOMATIC, AUTOMATIC) SwtPortGroupPtr;

    switch(ETHIF_GET_PHYTYPE(CtrlIdx))
    {
    case ETHIF_TRCV:
        ret = E_OK;
        HwPhyStatePtr = ETHIF_GET_HWTRCV_STATE_BY_CTRLIDX(CtrlIdx);
        if(*HwPhyStatePtr == ETH_MODE_DOWN)
        {
            EthTrcvSetModeFctPtr = ETHIF_GET_TRCV_API_PTR_BY_CTRLIDX(CtrlIdx)->SetTrcvMode;
            if(NULL_PTR != EthTrcvSetModeFctPtr)
            {
                ret = EthTrcvSetModeFctPtr(ETHIF_GET_TRCV_PTR_BY_CTRLIDX(CtrlIdx)->TrcvIdx, ETHTRCV_MODE_ACTIVE);
                if(ret == E_OK)
                {
                    *HwPhyStatePtr = ETH_MODE_ACTIVE;
                }
            }
        }
        else
        {
            *HwPhyStatePtr = ETH_MODE_ACTIVE;
        }
        break;
    case ETHIF_SWTPORT_GROUP:
        ret = E_NOT_OK;
        SwtPortGroupPtr = ETHIF_GET_SWTPORT_GROUP_PTR(CtrlIdx);
        PortMax = SwtPortGroupPtr->PortIdx + SwtPortGroupPtr->PortNum;
        for(i = SwtPortGroupPtr->PortIdx; i < PortMax; i++)
        {
            /*PRQA S 1442 ++*/
            /*assign a value to a type*/
            HwPhyStatePtr = ETHIF_GET_HWPORT_STATE(i);
            /*PRQA S 1442 --*/
            if(*HwPhyStatePtr == ETH_MODE_DOWN)
            {
                EthSetSwtPortModeFctPtr = ETHIF_GET_PORT_API_PTR(i)->SetSwtPortMode;
                if(NULL_PTR != EthSetSwtPortModeFctPtr)
                {
                    retTmp = EthSetSwtPortModeFctPtr(ETHIF_GET_HWSWT_IDX(i), ETHIF_GET_SWT_PORT_PTR(i)->PortIdx, ETHTRCV_MODE_ACTIVE);
                    if(retTmp == E_OK)
                    {
                        ret = E_OK;
                        *HwPhyStatePtr = ETH_MODE_ACTIVE;
                    }
                }
                else
                {
                    ret = E_OK;
                }
            }
            else
            {
                ret = E_OK;
                *HwPhyStatePtr = ETH_MODE_ACTIVE;
            }
        }
        break;
    case ETHIF_NONE:
        ret = E_OK;
        break;
    default:
        ret = E_NOT_OK;
        break;
    }

    return ret;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: EthIf__SetTrcvDown
*
* Description:   set  the hardware tranceiver of the EthIf controller to DOWN, or just update the
              Active counter.
*
* Inputs:         CtrlIdx: EthIf controller index
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(Std_ReturnType, ETHIF_CODE) EthIf__SetTrcvDown
(
    uint8 CtrlIdx
)
{
    uint8 i;
    uint8 PortMax;
    Std_ReturnType ret;
    Std_ReturnType retTmp;
    P2VAR(Eth_ModeType, AUTOMATIC, AUTOMATIC) HwPhyStatePtr;
    EthIf_EthTrcvSetTransceiverModeType EthTrcvSetModeFctPtr;
    EthIf_SetSwtPortModeType EthSetSwtPortModeFctPtr;
    P2CONST(EthIf_SwtPortGroupType, AUTOMATIC, AUTOMATIC) SwtPortGroupPtr;

    switch(ETHIF_GET_PHYTYPE(CtrlIdx))
    {
    case ETHIF_TRCV:
        ret = E_OK;
        HwPhyStatePtr = ETHIF_GET_HWTRCV_STATE_BY_CTRLIDX(CtrlIdx);
        if(*HwPhyStatePtr == ETH_MODE_ACTIVE)
        {
            EthTrcvSetModeFctPtr = ETHIF_GET_TRCV_API_PTR_BY_CTRLIDX(CtrlIdx)->SetTrcvMode;
            if(NULL_PTR != EthTrcvSetModeFctPtr)
            {
                ret = EthTrcvSetModeFctPtr(ETHIF_GET_TRCV_PTR_BY_CTRLIDX(CtrlIdx)->TrcvIdx, ETHTRCV_MODE_DOWN);
                if(ret == E_OK)
                {
                    *HwPhyStatePtr = ETH_MODE_DOWN;
                }
            }
        }
        else if(*HwPhyStatePtr == ETH_MODE_DOWN)
        {
            /*do nothing*/
        }
        else
        {
            ret = E_NOT_OK;
        }
        break;
    case ETHIF_SWTPORT_GROUP:
        ret = E_NOT_OK;
        SwtPortGroupPtr = ETHIF_GET_SWTPORT_GROUP_PTR(CtrlIdx);
        PortMax = SwtPortGroupPtr->PortIdx + SwtPortGroupPtr->PortNum;
        for(i = SwtPortGroupPtr->PortIdx; i < PortMax; i++)
        {
            /*PRQA S 1442 ++*/
            /*assign a value to a type*/
            HwPhyStatePtr = ETHIF_GET_HWPORT_STATE(i) ;
            /*PRQA S 1442 --*/
            if(*HwPhyStatePtr == ETH_MODE_ACTIVE)
            {
                EthSetSwtPortModeFctPtr = ETHIF_GET_PORT_API_PTR(i)->SetSwtPortMode;
                if(NULL_PTR != EthSetSwtPortModeFctPtr)
                {
                    retTmp = EthSetSwtPortModeFctPtr(ETHIF_GET_HWSWT_IDX(i), ETHIF_GET_SWT_PORT_PTR(i)->PortIdx, ETHTRCV_MODE_DOWN);
                    if(retTmp == E_OK)
                    {
                        ret = E_OK;
                        *HwPhyStatePtr = ETH_MODE_DOWN;
                    }
                }
                else
                {
                    ret = E_OK;
                }
            }
            else if(*HwPhyStatePtr == ETH_MODE_DOWN)
            {
                /*do nothing*/
            }
            else
            {
                ret = E_NOT_OK;
            }
        }
        break;
    case ETHIF_NONE:
        ret = E_OK;
        break;
    default:
        ret = E_NOT_OK;
        break;
    }

    return ret;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: EthIf_GetTransceiverMode
*                
* Description:   Get the transceiver mode. 
*                             
* Inputs:        CtrlIdx     : the index of a ethernet interface controller.
*                TrcvModePtr : Pointer to store the transceiver mode.
*             
* Outputs:       None
* 
* Limitations:   Call it after EthIf_Init has been called.
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, ETHIF_CODE) EthIf_GetTransceiverMode
(
    uint8 CtrlIdx,
    P2VAR(EthTrcv_ModeType, AUTOMATIC, ETHIF_APPL_DATA) TrcvModePtr
)
{
    Std_ReturnType ret = E_NOT_OK;    

    /*[SWS_EthIf_00057]*/
    if (ETHCTRL_STATE_INIT != EthIf_InitState)
    {
        ETHIF_DET_REPORT_ERROR(ETHIF_API_ID_GETTRANSCEIVERMODE, ETHIF_E_NOT_INITIALIZED);
    }
    /*[SWS_EthIf_00058]*/
    else if (CtrlIdx >= ETHIF_GET_CTRL_NUMBER())
    {
        ETHIF_DET_REPORT_ERROR(ETHIF_API_ID_GETTRANSCEIVERMODE, ETHIF_E_INV_TRCV_IDX);
    }
    /*[SWS_EthIf_00059]*/
    else if (NULL_PTR == TrcvModePtr)
    {
        ETHIF_DET_REPORT_ERROR(ETHIF_API_ID_GETTRANSCEIVERMODE, ETHIF_E_PARAM_POINTER);
    }
    else
    {
        *TrcvModePtr = ETHIF_GET_TRCV_MODE(CtrlIdx);
        ret = E_OK;
    }
    return ret;
}

/*[SWS_EthIf_00237]*/
/*[SWS_EthIf_00248]*/
#if(ETHIF_WAKEUP_SUPPORT == STD_ON)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: EthIf_SetTransceiverWakeupMode
*                
* Description:   Set the transceiver wakeup mode. 
*                             
* Inputs:        TrcvIdx       : Index of the transceiver.
*                TrcvWakeupMode: Wakeup mode.
*             
* Outputs:       None
* 
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, ETHIF_CODE) EthIf_SetTransceiverWakeupMode
(
    uint8  TrcvIdx,
    EthTrcv_WakeupModeType  TrcvWakeupMode
)
{
    Std_ReturnType ret = E_NOT_OK;    
    EthIf_EthTrcvSetTrcvWakeupModeType EthTrcvSetWakeupModeFctPtr;

    /*[SWS_EthIf_00235]*/
    if (ETHCTRL_STATE_INIT != EthIf_InitState)
    {
        ETHIF_DET_REPORT_ERROR(ETHIF_API_ID_SETTRANSCEIVERWAKEUPMODE, ETHIF_E_NOT_INITIALIZED);
    }
    /*[SWS_EthIf_00236]*/
    else if (TrcvIdx >= ETHIF_GET_CTRL_NUMBER())
    {
        ETHIF_DET_REPORT_ERROR(ETHIF_API_ID_SETTRANSCEIVERWAKEUPMODE, ETHIF_E_INV_TRCV_IDX);
    }
    else
    {
        /*[SWS_EthIf_00234]*/
        EthTrcvSetWakeupModeFctPtr = ETHIF_GET_TRCV_API_PTR(TrcvIdx)->SetTrcvWakeupMode;
        if (NULL_PTR != EthTrcvSetWakeupModeFctPtr)
        {            
            ret = EthTrcvSetWakeupModeFctPtr(ETHIF_GET_TRCV_PTR(TrcvIdx)->TrcvIdx, TrcvWakeupMode);
        }
    }
    return ret;
}

#if(ETHIF_GET_TRANSCEIVER_WAKEUP_MODE_API == STD_ON)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: EthIf_GetTransceiverWakeupMode
*                
* Description:   Get the transceiver wakeup mode. 
*                             
* Inputs:        TrcvIdx: Index of the transceiver within the context of the 
*                         Ethernet Interface.
*             
* Outputs:       TrcvWakeupModePtr: Wakeup mode.
*                
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, ETHIF_CODE) EthIf_GetTransceiverWakeupMode
(
    uint8  TrcvIdx,
    P2VAR(EthTrcv_WakeupModeType, AUTOMATIC, ETHIF_APPL_DATA) TrcvWakeupModePtr
)
{
    Std_ReturnType ret = E_NOT_OK;    
    EthIf_EthTrcvGetTrcvWakeupModeType EthTrcvGetWakeupModeFctPtr;

    /*[SWS_EthIf_00240]*/
    if (ETHCTRL_STATE_INIT != EthIf_InitState)
    {
        ETHIF_DET_REPORT_ERROR(ETHIF_API_ID_GETTRANSCEIVERWAKEUPMODE, ETHIF_E_NOT_INITIALIZED);
    }
    /*[SWS_EthIf_00241]*/
    else if (TrcvIdx >= ETHIF_GET_CTRL_NUMBER())
    {
        ETHIF_DET_REPORT_ERROR(ETHIF_API_ID_GETTRANSCEIVERWAKEUPMODE, ETHIF_E_INV_TRCV_IDX);
    }
    /*[SWS_EthIf_00242]*/
    else if (NULL_PTR == TrcvWakeupModePtr)
    {
        ETHIF_DET_REPORT_ERROR(ETHIF_API_ID_GETTRANSCEIVERWAKEUPMODE, ETHIF_E_PARAM_POINTER);
    }
    else
    {
        /*[SWS_EthIf_00239]*/
        EthTrcvGetWakeupModeFctPtr = ETHIF_GET_TRCV_API_PTR(TrcvIdx)->GetTrcvWakeupMode;
        if (NULL_PTR != EthTrcvGetWakeupModeFctPtr)
        {            
            ret = EthTrcvGetWakeupModeFctPtr(ETHIF_GET_TRCV_PTR(TrcvIdx)->TrcvIdx, TrcvWakeupModePtr);
        }
    }
    return ret;
}
#endif

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: EthIf_CheckWakeup
*                
* Description:   Check wake up event.
*                             
* Inputs:        WakeupSource: source (transceiver) which initiated the wake up 
*                              event.
*             
* Outputs:       None
* 
* Limitations:   Call it after EthIf_Init has been called.
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, ETHIF_CODE) EthIf_CheckWakeup
(
    EcuM_WakeupSourceType  WakeupSource
)
{
    uint8 i;
    uint8 EthTrcvId;
    Std_ReturnType ret;
    EthIf_EthTrcvCheckWakeupType EthTrcvCheckWakeupFctPtr;

    ret = E_NOT_OK;
    /*[SWS_EthIf_00246]*/
    if (ETHCTRL_STATE_INIT != EthIf_InitState)
    {
        ETHIF_DET_REPORT_ERROR(ETHIF_API_ID_CHECKWAKEUP, ETHIF_E_NOT_INITIALIZED);
    }
    /*[SWS_EthIf_00247]*/
    else if(!(ECUM_IS_WAKEUPSOURCE(WakeupSource, ECUM_WKSOURCE_VALID_MASK)))
    {
        ETHIF_DET_REPORT_ERROR(ETHIF_API_ID_CHECKWAKEUP, ETHIF_E_INV_PARAM);
    }
    else
    {
        for (i = (uint8)0; i < ETHIF_WAKEUPMAP_NUM; i++)
        {
            if ((EthIf_WakeupMap[i].WakeupSource & WakeupSource) > (EcuM_WakeupSourceType)0)
            {
                EthTrcvId = EthIf_WakeupMap[i].EthTrcvId;
                /*[SWS_EthIf_00245]*/
                EthTrcvCheckWakeupFctPtr = ETHIF_GET_TRCV_API_PTR(EthTrcvId)->CheckWakeup;
                if (NULL_PTR != EthTrcvCheckWakeupFctPtr)
                {            
                    ret = EthTrcvCheckWakeupFctPtr(EthTrcvId);
                }
            }
        }
    }
    return ret;
}
STATIC FUNC(Std_ReturnType, ETHIF_CODE) EthIf__GetCheckWakeupFct
(
    uint8 TrcvId,
    P2VAR(EthIf_EthTrcvCheckWakeupType, AUTOMATIC, ETHIF_APPL_DATA) FctPtr
)
{
    uint8 i;
    Std_ReturnType ret = E_NOT_OK;
    *FctPtr = NULL_PTR;

    for(i = (uint8)0; i < ETHIF_GET_TRCV_NUMBER(); i++)
    {
        if(ETHIF_GET_TRCV_PTR(i)->TrcvIdx == TrcvId)
        {
            *FctPtr = ETHIF_GET_TRCV_API_PTR(i)->CheckWakeup;
            if(*FctPtr != NULL_PTR)
            {
                ret = E_OK;
                break;
            }
        }
    }
    return ret;
}
#endif

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: EthIf_GetPhysAddr
*                
* Description:   Return the MAC of a ethernet controller. 
*                             
* Inputs:        CtrlIdx     : the index of a ethernet controller.
*                  PhysAddrPtr : the MAC buffer.
*             
* Outputs:       None
* 
* Limitations:   Call it after EthIf_Init has been called.
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, ETHIF_CODE) EthIf_GetPhysAddr
(
    uint8 CtrlIdx,
    P2VAR(uint8, AUTOMATIC, ETHIF_APPL_DATA) PhysAddrPtr
)
{    
    EthIf_EthGetPhysAddrType EthGetPhysAddrFctPtr;

    /*[SWS_EthIf_00063]*/
    if (ETHCTRL_STATE_INIT != EthIf_InitState)
    {
        ETHIF_DET_REPORT_ERROR(ETHIF_API_ID_GETPHYSADDR, ETHIF_E_NOT_INITIALIZED);
    }
    /*[SWS_EthIf_00064]*/
    else if (CtrlIdx >= ETHIF_GET_CTRL_NUMBER())
    {
        ETHIF_DET_REPORT_ERROR(ETHIF_API_ID_GETPHYSADDR, ETHIF_E_INV_CTRL_IDX);
    }
    /*[SWS_EthIf_00065]*/
    else if (NULL_PTR == PhysAddrPtr)
    {
        ETHIF_DET_REPORT_ERROR(ETHIF_API_ID_GETPHYSADDR, ETHIF_E_PARAM_POINTER);
    }
    else
    {
        /*[SWS_EthIf_00062]*/
        EthGetPhysAddrFctPtr = ETHIF_GET_CTRL_API_PTR(CtrlIdx)->GetPhyAddr;
        if (NULL_PTR != EthGetPhysAddrFctPtr)
        {            
            EthGetPhysAddrFctPtr(ETHIF_GET_CTRL_PTR(CtrlIdx)->CtrlIdx, PhysAddrPtr);
        }
    }
    return ;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: EthIf_SetPhysAddr
*                
* Description:   Change the MAC of a ethernet controller. 
*                             
* Inputs:        CtrlIdx     : the index of a ethernet controller.
*                  PhysAddrPtr : the MAC buffer.
*             
* Outputs:       None
* 
* Limitations:   Call it after EthIf_Init has been called.
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, ETHIF_CODE) EthIf_SetPhysAddr
(
    uint8 CtrlIdx,
    P2CONST(uint8, AUTOMATIC, ETHIF_APPL_DATA) PhysAddrPtr
)
{    
    EthIf_EthSetPhysAddrType EthSetPhyAddrFctPtr;

    /*[SWS_EthIf_00135]*/
    if (ETHCTRL_STATE_INIT != EthIf_InitState)
    {
        ETHIF_DET_REPORT_ERROR(ETHIF_API_ID_SETPHYSADDR, ETHIF_E_NOT_INITIALIZED);
    }
    /*[SWS_EthIf_00136]*/
    else if (CtrlIdx >= ETHIF_GET_CTRL_NUMBER())
    {
        ETHIF_DET_REPORT_ERROR(ETHIF_API_ID_SETPHYSADDR, ETHIF_E_INV_CTRL_IDX);
    }
    /*[SWS_EthIf_00137]*/
    else if (NULL_PTR == PhysAddrPtr)
    {
        ETHIF_DET_REPORT_ERROR(ETHIF_API_ID_SETPHYSADDR, ETHIF_E_PARAM_POINTER);
    }
    else
    {
        /*[SWS_EthIf_00134]*/
        EthSetPhyAddrFctPtr = ETHIF_GET_CTRL_API_PTR(CtrlIdx)->SetPhyAddr;
        if (NULL_PTR != EthSetPhyAddrFctPtr)
        {            
            EthSetPhyAddrFctPtr(ETHIF_GET_CTRL_PTR(CtrlIdx)->CtrlIdx, PhysAddrPtr);
        }
    }

    return ;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: EthIf_UpdatePhysAddrFilter
*                
* Description:   Update the MAC Filter of a ethernet controller. 
*                             
* Inputs:        CtrlIdx     : the index of a ethernet controller.
*                  PhysAddrPtr : the MAC buffer.
*                  Action         : action.
*
* Outputs:       If the filter is updated successfully return E_OK.
* 
* Limitations:   Call it after EthIf_Init has been called.
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, ETHIF_CODE) EthIf_UpdatePhysAddrFilter
(
    uint8 CtrlIdx,
    P2VAR(uint8, AUTOMATIC, ETHIF_APPL_DATA) PhysAddrPtr,
    Eth_FilterActionType Action
)
{
    Std_ReturnType ret = E_NOT_OK;    
    EthIf_EthUpdatePhysAddrFilterType EthUpdatePhysAddrFctPtr;

    /*[SWS_EthIf_00141]*/
    if (ETHCTRL_STATE_INIT != EthIf_InitState)
    {
        ETHIF_DET_REPORT_ERROR(ETHIF_API_ID_UPDATEPHYSADDRFILTER, ETHIF_E_NOT_INITIALIZED);
    }
    /*[SWS_EthIf_00142]*/
    else if (CtrlIdx >= ETHIF_GET_CTRL_NUMBER())
    {
        ETHIF_DET_REPORT_ERROR(ETHIF_API_ID_UPDATEPHYSADDRFILTER, ETHIF_E_INV_CTRL_IDX);
    }
    /*[SWS_EthIf_00143]*/
    else if (NULL_PTR == PhysAddrPtr)
    {
        ETHIF_DET_REPORT_ERROR(ETHIF_API_ID_UPDATEPHYSADDRFILTER, ETHIF_E_PARAM_POINTER);
    }
    else
    {
        /*[SWS_EthIf_00140]*/
        EthUpdatePhysAddrFctPtr = ETHIF_GET_CTRL_API_PTR(CtrlIdx)->UpdatePhyAddrFilter;
        if (NULL_PTR != EthUpdatePhysAddrFctPtr)
        {            
            ret = EthUpdatePhysAddrFctPtr(ETHIF_GET_CTRL_PTR(CtrlIdx)->CtrlIdx, PhysAddrPtr, Action);
        }
    }
    
    return ret;
}

#if(ETHIF_SWITCH_SUPPORT == STD_ON)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: EthIf_GetPortMacAddr
*
* Description:   Obtains the port over which this MAC-address can be reached.
*
* Inputs:        MacAddrPtr: MAC-address for which a switch port is searched
*
* Outputs:       SwitchIdxPtr: Pointer to the switch index
*                PortIdxPtr: Pointer to the port index
*                Std_ReturnType: If the filter is updated successfully return E_OK.
*
* Limitations:   Call it after EthIf_Init has been called.
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, ETHIF_CODE) EthIf_GetPortMacAddr
(
    P2CONST(uint8, AUTOMATIC, ETHIF_APPL_DATA) MacAddrPtr,
    P2VAR(uint8, AUTOMATIC, ETHIF_APPL_DATA) SwitchIdxPtr,
    P2VAR(uint8, AUTOMATIC, ETHIF_APPL_DATA) PortIdxPtr
)
{
    uint8 i;
    Std_ReturnType ret;
    EthIf_GetPortMacAddrType GetPortMacAddrFuncPtr;

    ret = E_NOT_OK;

    /*[SWS_EthIf_00193]*/
    if (ETHCTRL_STATE_INIT != EthIf_InitState)
    {
        ETHIF_DET_REPORT_ERROR(ETHIF_API_ID_GETPORTMACADDR, ETHIF_E_NOT_INITIALIZED);
    }
    /*[SWS_EthIf_00194]*/
    else if((MacAddrPtr == NULL_PTR) || (SwitchIdxPtr == NULL_PTR) || (PortIdxPtr == NULL_PTR))
    {
        ETHIF_DET_REPORT_ERROR(ETHIF_API_ID_GETPORTMACADDR, ETHIF_E_PARAM_POINTER);
    }
    else
    {
        for(i = 0; i < ETHIF_GET_SWT_NUMBER(); i++)
        {
            GetPortMacAddrFuncPtr = ETHIF_GET_SWT_API_PTR(i)->GetPortMacAddr;
            if(GetPortMacAddrFuncPtr != NULL_PTR)
            {
                ret = GetPortMacAddrFuncPtr(MacAddrPtr, SwitchIdxPtr, PortIdxPtr);
                if(ret == E_OK)
                {
                    break;
                }
            }
        }
    }

    return ret;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: EthIf_GetBufferLevel
*
* Description:   Reads the buffer level of the corresponding switch.
*
* Inputs:        SwitchIdx: Index of the switch within the context of the
*                            Ethernet Switch Driver
*
* Outputs:       SwitchBufferLevelPtr: The interpretation of this value is switch dependent
*                Std_ReturnType: If the filter is updated successfully return E_OK.
*
* Limitations:   Call it after EthIf_Init has been called.
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, ETHIF_CODE) EthIf_GetBufferLevel
(
    uint8 SwitchIdx,
    P2VAR(uint32, AUTOMATIC, ETHIF_APPL_DATA) SwitchBufferLevelPtr
)
{
    Std_ReturnType ret;
    EthIf_GetBufferLevelType GetBufferLevelFuncPtr;

    ret = E_NOT_OK;

    /*[SWS_EthIf_00205]*/
    if (ETHCTRL_STATE_INIT != EthIf_InitState)
    {
        ETHIF_DET_REPORT_ERROR(ETHIF_API_ID_GETBUFFERLEVEL, ETHIF_E_NOT_INITIALIZED);
    }
    /*[SWS_EthIf_00206]*/
    else if(SwitchBufferLevelPtr == NULL_PTR)
    {
        ETHIF_DET_REPORT_ERROR(ETHIF_API_ID_GETBUFFERLEVEL, ETHIF_E_PARAM_POINTER);
    }
    else
    {
        GetBufferLevelFuncPtr = ETHIF_GET_SWT_API_PTR(SwitchIdx)->GetBufferLevel;
        if(GetBufferLevelFuncPtr != NULL_PTR)
        {
            ret = GetBufferLevelFuncPtr(ETHIF_GET_SWT_PTR(SwitchIdx)->SwitchIdx, SwitchBufferLevelPtr);
        }
    }

    return ret;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: EthIf_StoreConfiguration
*
* Description:   Stores the configuration of the learned MAC/Port tables of a
*                switch in a persistent manner and will be used by e.g. CDD.
*
* Inputs:        SwitchIdx: Index of the switch within the context of the
*                            Ethernet Switch Driver
*
* Outputs:       Std_ReturnType: If store configuration successfully return E_OK.
*
* Limitations:   Call it after EthIf_Init has been called.
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, ETHIF_CODE) EthIf_StoreConfiguration
(
    uint8 SwitchIdx
)
{
    Std_ReturnType ret;
    EthIf_StoreConfigurationType StoreConfigurationFuncPtr;

    ret = E_NOT_OK;

    /*[SWS_EthIf_00217]*/
    if (ETHCTRL_STATE_INIT != EthIf_InitState)
    {
        ETHIF_DET_REPORT_ERROR(ETHIF_API_ID_STORECONFIGURATION, ETHIF_E_NOT_INITIALIZED);
    }
    else
    {
        StoreConfigurationFuncPtr = ETHIF_GET_SWT_API_PTR(SwitchIdx)->StoreConfiguration;
        if(StoreConfigurationFuncPtr != NULL_PTR)
        {
            ret = StoreConfigurationFuncPtr(ETHIF_GET_SWT_PTR(SwitchIdx)->SwitchIdx);
        }
    }

    return ret;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: EthIf_ResetConfiguration
*
* Description:   Resets the configuration of the learned MAC/Port tables of a
*                switch in a persistent manner and will be used by e.g. CDD.
*                The statically configured entries shall still remain.
*
* Inputs:        SwitchIdx: Index of the switch within the context of the
*                            Ethernet Switch Driver
*
* Outputs:       Std_ReturnType: If reset configuration successfully return E_OK.
*
* Limitations:   Call it after EthIf_Init has been called.
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, ETHIF_CODE) EthIf_ResetConfiguration
(
    uint8 SwitchIdx
)
{
    Std_ReturnType ret;
    EthIf_ResetConfigurationType ResetConfigurationFuncPtr;

    ret = E_NOT_OK;

    /*[SWS_EthIf_00222]*/
    if (ETHCTRL_STATE_INIT != EthIf_InitState)
    {
        ETHIF_DET_REPORT_ERROR(ETHIF_API_ID_RESETCONFIGURATION, ETHIF_E_NOT_INITIALIZED);
    }
    else
    {
        ResetConfigurationFuncPtr = ETHIF_GET_SWT_API_PTR(SwitchIdx)->ResetConfiguration;
        if(ResetConfigurationFuncPtr != NULL_PTR)
        {
            ret = ResetConfigurationFuncPtr(ETHIF_GET_SWT_PTR(SwitchIdx)->SwitchIdx);
        }
    }

    return ret;
}
#endif

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: EthIf_ProvideTxBuffer
*                
* Description:   Get a Tx buffer. 
*                             
* Inputs:        CtrlIdx     : the index of a ethernet controller.
*                  FrameType   : the type of a ethernet frame.
*                  Priority    : the priority of a ethernet frame.
*                  BufIdPtr     : the index of the buffer.
*                  BufPtr         : the buffer.
*                  LenBytePtr  : the length of the buffer.
*             
* Outputs:       If the buffer is provided successfully return E_OK.
* 
* Limitations:   Call it after EthIf_Init has been called.
********************************************************************************
END_FUNCTION_HDR*/
FUNC(BufReq_ReturnType, ETHIF_CODE) EthIf_ProvideTxBuffer
(
    uint8 CtrlIdx,
    Eth_FrameType FrameType,
    uint8 Priority,
    P2VAR(Eth_BufIdxType, AUTOMATIC, ETHIF_APPL_DATA) BufIdxPtr,
    P2VAR(P2VAR(uint8, AUTOMATIC, AUTOMATIC), AUTOMATIC, ETHIF_APPL_DATA) BufPtr,
    P2VAR(uint16, AUTOMATIC, ETHIF_APPL_DATA) LenBytePtr
)
{
    BufReq_ReturnType ret;
    uint16 VlanLenByte;
    P2VAR(uint8, AUTOMATIC, AUTOMATIC) VlanBufPtr;
    EthIf_EthProvideTxBufferType EthProvideTxBufferFctPtr;
    P2CONST(EthIf_ControllerType, AUTOMATIC, AUTOMATIC) EthIfCtrlPtr;

    ret = BUFREQ_E_NOT_OK;
    
    /*[SWS_EthIf_00069]*/
    if (ETHCTRL_STATE_INIT != EthIf_InitState)
    {
        ETHIF_DET_REPORT_ERROR(ETHIF_API_ID_PROVIDETXBUFFER, ETHIF_E_NOT_INITIALIZED);
    }
    /*[SWS_EthIf_00070]*/
    else if (CtrlIdx >= ETHIF_GET_CTRL_NUMBER())
    {
        ETHIF_DET_REPORT_ERROR(ETHIF_API_ID_PROVIDETXBUFFER, ETHIF_E_INV_CTRL_IDX);
    }
    /*[SWS_EthIf_00071]*/ /*[SWS_EthIf_00072]*/ /*[SWS_EthIf_00073]*/
    else if ((NULL_PTR == BufIdxPtr)
               || (NULL_PTR == BufPtr)
               || (NULL_PTR == LenBytePtr))
    {
        ETHIF_DET_REPORT_ERROR(ETHIF_API_ID_PROVIDETXBUFFER, ETHIF_E_PARAM_POINTER);
    }
    else
    {
        EthIfCtrlPtr = ETHIF_GET_CTRL_PTR(CtrlIdx);
        if((*LenBytePtr <= EthIfCtrlPtr->CtrlMtu)
            && (ETHIF_GET_CTRL_MODE(CtrlIdx) == ETH_MODE_ACTIVE))
        {

            EthProvideTxBufferFctPtr = ETHIF_GET_CTRL_API_PTR(CtrlIdx)->ProvideTxBuffer;
            if(NULL_PTR != EthProvideTxBufferFctPtr)
            {
                if (!ETHIF_CTRL_IS_VLAN(CtrlIdx))
                {
                    /*[SWS_EthIf_00068]*/
                    ret = EthProvideTxBufferFctPtr(EthIfCtrlPtr->CtrlIdx,
                                        Priority, //modified by Yibo: Priority is added to adapt mcal version
                                        BufIdxPtr,
                                        BufPtr,
                                        LenBytePtr); 
                }
                else
                {
                    /*[SWS_EthIf_00147]*/
                    VlanLenByte = *LenBytePtr + ETHIF_VLAN_TAG_LEN;
                    /*[SWS_EthIf_00068]*/
                    ret = EthProvideTxBufferFctPtr(EthIfCtrlPtr->CtrlIdx,
                    						Priority, //modified by Yibo: Priority is added to adapt mcal version
                                            BufIdxPtr,
                                            &VlanBufPtr,
                                            &VlanLenByte);
                    if (BUFREQ_OK == ret)
                    {
                        /* IEEE 802.1Q
                        * |0------7|--------|--- - ----|--------|--------|--------|
                        * |   0x8100         |PCP|0|    VLANID     | FrameType       |
                        */
                        VlanBufPtr[0] = (uint8)((((uint32)Priority << (uint32)5) & (uint32)0xE0)
                                | (((uint32)(EthIfCtrlPtr->VlanId) >> (uint32)8) & (uint32)0x0F));
                        VlanBufPtr[1] = (uint8)(((uint32)(EthIfCtrlPtr->VlanId)) & (uint32)0xFF);
                        VlanBufPtr[2] = (uint8)((((uint32)FrameType) >> (uint32)8) & (uint32)0xFF);
                        VlanBufPtr[3] = (uint8)(((uint32)FrameType >> (uint32)0) & (uint32)0xFF);
                        /*point to the free space*/
                        *BufPtr = &VlanBufPtr[4];
                        *LenBytePtr = VlanLenByte - ETHIF_VLAN_TAG_LEN;
                    }
                }
            }
        }
        else
        {
            
        }
    }
    
    return ret;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: EthIf_Transmit
*                
* Description:   Transmit a ethernet frame. 
*                             
* Inputs:        CtrlIdx        : the index of a ethernet controller.
*                  BufId           : the index of the buffer.
*                  FrameType      : the type of a ethernet frame.
*                  TxConfirmation : If true, the confirmation will be called.
*                  LenByte        : the length of the buffer.
*                  PhysAddrPtr    : the DMAC.
*             
* Outputs:       If the buffer is transmitted successfully return E_OK.
* 
* Limitations:   Call it after EthIf_Init has been called.
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, ETHIF_CODE) EthIf_Transmit
(
    uint8 CtrlIdx,
    uint8 BufIdx,
    Eth_FrameType FrameType,
    boolean TxConfirmation,
    uint16 LenByte,
    P2CONST(uint8, AUTOMATIC, ETHIF_APPL_DATA) PhysAddrPtr
)
{
    Std_ReturnType ret = E_NOT_OK;
    P2CONST(EthIf_ControllerType, AUTOMATIC, AUTOMATIC) EthIfCtrlPtr;
    P2CONST(EthIf_FrameOwnerType, AUTOMATIC, AUTOMATIC) OwnerPtr;    
    Eth_FrameType TmpFrameType;
    EthIf_EthTransmitType EthTransmitFctPtr;
    uint8 i;
    uint8 OwnerNum;

    /*[SWS_EthIf_00077]*/
    if (ETHCTRL_STATE_INIT != EthIf_InitState)
    {
        ETHIF_DET_REPORT_ERROR(ETHIF_API_ID_TRANSMIT, ETHIF_E_NOT_INITIALIZED);
    }
    /*[SWS_EthIf_00078]*/
    else if (CtrlIdx >= ETHIF_GET_CTRL_NUMBER())
    {
        ETHIF_DET_REPORT_ERROR(ETHIF_API_ID_TRANSMIT, ETHIF_E_INV_CTRL_IDX);
    }
    /*[SWS_EthIf_00079]*/
    else if (BufIdx >= ETHIF_GET_TXBUF_NUMBER(CtrlIdx)/*ETHIF_MAX_TXBUFS_TOTAL*/)
    {
        ETHIF_DET_REPORT_ERROR(ETHIF_API_ID_TRANSMIT, ETHIF_E_INV_PARAM);
    }
    /*[SWS_EthIf_00080]*/
    else if (NULL_PTR == PhysAddrPtr)
    {
        ETHIF_DET_REPORT_ERROR(ETHIF_API_ID_TRANSMIT, ETHIF_E_PARAM_POINTER);
    }
    else
    {
        EthIfCtrlPtr = ETHIF_GET_CTRL_PTR(CtrlIdx);
        /*PRQA S 1400 ++*/
        /*judging the pattern ,no problem*/
        if((LenByte <= EthIfCtrlPtr->CtrlMtu)
            && (ETHIF_GET_CTRL_MODE(CtrlIdx) == ETH_MODE_ACTIVE)&& (ETHIF_GET_TRCV_MODE(CtrlIdx) == ETHTRCV_MODE_ACTIVE))
        /*PRQA S 1400 --*/
        {
            /*SWS_EthIf_00250*/
            if (!ETHIF_CTRL_IS_VLAN(CtrlIdx))
            {
                TmpFrameType = FrameType;
            }
            else
            {
                /*PRQA S 1338 ++*/
                /*the value of this variable can be modified*/
                TmpFrameType = ETHIF_VLAN_FRAME_TYPE;
                LenByte += ETHIF_VLAN_TAG_LEN;
                /*PRQA S 1338 --*/
            }

            if(TRUE == TxConfirmation)
            {
                /* Tx Confirmation desired
                * store information to retrieve upper layer in Tx Confirmation context */

                OwnerNum = ETHIF_GET_OWNER_NUMBER();
                OwnerPtr = ETHIF_GET_OWNER_PTR(0);
                
                for (i = (uint8)0; i < OwnerNum; i++)
                {
                    if (OwnerPtr[i].FrameType == (uint16)FrameType)
                    {
                        ETHIF_GETTXBUFOWNER(CtrlIdx, BufIdx) = OwnerPtr[i].Owner;
                        break;
                    }
                }
            }

            /*[SWS_EthIf_00081]*/
            EthTransmitFctPtr = ETHIF_GET_CTRL_API_PTR(CtrlIdx)->Transmit;
            if (NULL_PTR != EthTransmitFctPtr)
            {
                ret = EthTransmitFctPtr(EthIfCtrlPtr->CtrlIdx,
                                    BufIdx,
                                    TmpFrameType,
                                    TxConfirmation,
                                    LenByte,
                                    PhysAddrPtr);
            }
        }
        else
        {
            ret = E_NOT_OK;
        }
    }
            
    return ret;
}

#if ((ETHIF_VERSIONINFO_API_MACRO == STD_ON) && (ETHIF_VERSION_INFO_API == STD_ON))
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: EthIf_GetVersionInfo
*                
* Description:   Get the version of EthIf module. 
*                             
* Inputs:        None
*             
* Outputs:       VersionInfoPtr: Pointer to store version information.
* 
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, ETHIF_CODE) EthIf_GetVersionInfo
(
    P2VAR(Std_VersionInfoType, AUTOMATIC, ETHIF_APPL_DATA) VersionInfoPtr
)
{
    /*[SWS_EthIf_00127]*/
    if(NULL_PTR == VersionInfoPtr)
    {        
        ETHIF_DET_REPORT_ERROR(ETHIF_API_ID_GETVERSIONINFO, ETHIF_E_PARAM_POINTER);    
    }
    else
    {
        VersionInfoPtr->vendorID = ETHIF_VENDOR_ID;
        VersionInfoPtr->moduleID = ETHIF_MODULE_ID;
        VersionInfoPtr->sw_major_version = ETHIF_SW_MAJOR_VERSION;
        VersionInfoPtr->sw_minor_version = ETHIF_SW_MINOR_VERSION;
        VersionInfoPtr->sw_patch_version = ETHIF_SW_PATCH_VERSION;
    }
}
#endif

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: EthIf_RxIndication
*                
* Description:   This function is called when a ethernet frame was received. 
*                             
* Inputs:        CtrlIdx        : the index of a ethernet controller.
*                  FrameType      : the type of the ethernet frame.
*                  isBoradcase    : If true, the frame is a boradcase frame.
*                  PhysAddrPtr    : the DMAC.
*                  DataPtr        : the data in the frame.
*                  LenByte        : the length of the buffer.
*             
* Outputs:       None
* 
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, ETHIF_CODE) EthIf_RxIndication
(
    uint8 CtrlIdx,
    Eth_FrameType FrameType,
    boolean IsBroadcast,
    P2CONST(uint8, AUTOMATIC, ETHIF_APPL_DATA) PhysAddrPtr,
    P2VAR(Eth_DataType, AUTOMATIC, ETHIF_APPL_DATA) DataPtr,
    uint16 LenByte
)
{
    P2CONST(EthIf_FrameOwnerType, AUTOMATIC, AUTOMATIC) OwnerPtr;
    EthIf_RxIndicationFctPtr RxIndication;
    uint8 OwnerNum;
    uint8 i;
    P2CONST(EthIf_ControllerType, AUTOMATIC, AUTOMATIC) CtrlPtr;
    P2CONST(EthIf_ControllerType, AUTOMATIC, AUTOMATIC) CurCtrlPtr;
    uint16 RxVlanId;

    uint16 RxIndIdx;
    uint8 EthIfCtrlIdx = CtrlIdx;
    P2VAR(Eth_DataType, AUTOMATIC, AUTOMATIC) DataPtrTmp = DataPtr;
    Eth_FrameType FrameTypeTmp = FrameType;
    uint8 CtrlTotalNum;

    /*[SWS_EthIf_00086]*/
    /*[SWS_EthIf_00089]*/
    if (ETHCTRL_STATE_INIT != EthIf_InitState)
    {
        ETHIF_DET_REPORT_ERROR(ETHIF_API_ID_RXINDICATION, ETHIF_E_NOT_INITIALIZED);
    }
    /*[SWS_EthIf_00087]*/
    else if (CtrlIdx >= ETHIF_GET_CTRL_NUMBER())
    {
        ETHIF_DET_REPORT_ERROR(ETHIF_API_ID_RXINDICATION, ETHIF_E_INV_CTRL_IDX);
    }
    /*[SWS_EthIf_00088]*/
    else if (NULL_PTR == DataPtr)
    {
        ETHIF_DET_REPORT_ERROR(ETHIF_API_ID_RXINDICATION, ETHIF_E_PARAM_POINTER);
    }
    else
    {
        CtrlTotalNum = ETHIF_GET_CTRL_NUMBER();
        if(FrameType == ETHIF_VLAN_FRAME_TYPE)
        {
            EthIfCtrlIdx = CtrlTotalNum;
            RxVlanId = (uint16)(((uint32)DataPtr[0] << (uint32)8) | ((uint32)DataPtr[1]));
            FrameTypeTmp = ((Eth_FrameType)((((uint32)DataPtr[2]) << (uint32)8) | ((uint32)DataPtr[3])));
            i = CtrlIdx;
            CtrlPtr = ETHIF_GET_CTRL_PTR(i);
            CurCtrlPtr = CtrlPtr;
            while((i < CtrlTotalNum) && (CtrlPtr->CtrlIdx == CurCtrlPtr->CtrlIdx)
#if(STD_ON == ETHIF_MULTIPLE_DRV_SUPPORT)
                &&(CtrlPtr->EthApiIdx == CurCtrlPtr->EthApiIdx)
#endif
            )
            {
                if(RxVlanId == CurCtrlPtr->VlanId)
                {
                    /*PRQA S 1338 ++*/
                    /*the value of this variable can be modified*/
                    EthIfCtrlIdx = i;
                    LenByte -= 4;
                    DataPtrTmp = &DataPtr[4];
                    break;
                     /*PRQA S 1338 --*/
                }
                else
                {
                    i++;
                    CurCtrlPtr = ETHIF_GET_CTRL_PTR(i);
                }
            }
        }
        if((EthIfCtrlIdx < CtrlTotalNum)
            && (ETHIF_GET_CTRL_MODE(EthIfCtrlIdx) == ETH_MODE_ACTIVE))
        {
            /*Get owner id*/
            OwnerNum = ETHIF_GET_OWNER_NUMBER();
            OwnerPtr = ETHIF_GET_OWNER_PTR(0);
            for (i = (uint8)0; i < OwnerNum; i++)
            {
                if (OwnerPtr[i].FrameType == (uint16)FrameTypeTmp)
                {
                    RxIndIdx = OwnerPtr[i].Owner;
                    /*SWS_EthIf_00104,SWS_EthIf_00105*/
                    RxIndication = ETHIF_GET_RXIND(RxIndIdx);
                    if(RxIndication != NULL_PTR)
                    {
                        RxIndication(EthIfCtrlIdx,
                                 FrameTypeTmp,
                                 IsBroadcast,
                                 PhysAddrPtr,
                                 DataPtrTmp,
                                 LenByte);
                    }
                    break;
                }
            }
        }
    }
    
    return ;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: EthIf_TxConfirmation
*                
* Description:   This function is called when a ethernet frame was transmitted. 
*                             
* Inputs:        CtrlIdx        : the index of a ethernet controller.
*                  BufIdx         : the buffer index
*             
* Outputs:       None
* 
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, ETHIF_CODE) EthIf_TxConfirmation
(
    uint8 CtrlIdx,
    uint8 BufIdx,
    Std_ReturnType ret //modified by Yibo: ret is added to adapt mcal version
)
{
    EthIf_TxConfirmationFctPtr TxConfirmationFctPtr;
    uint8 tmpCtrlIdx;
    P2CONST(EthIf_ControllerType, AUTOMATIC, AUTOMATIC) CtrlPtr;
    P2CONST(EthIf_ControllerType, AUTOMATIC, AUTOMATIC) tmpCtrlPtr;
    uint8 TxConfIdx;
    if (E_OK == ret)
    {

    }//modified by Yibo: ret is added to adapt mcal version
    /*[SWS_EthIf_00092]*/
    /*[SWS_EthIf_00095]*/
    if (ETHCTRL_STATE_INIT != EthIf_InitState)
    {
        ETHIF_DET_REPORT_ERROR(ETHIF_API_ID_TXCONFIRMATION, ETHIF_E_NOT_INITIALIZED);
    }
    /*[SWS_EthIf_00093]*/
    else if (CtrlIdx >= ETHIF_GET_CTRL_NUMBER())
    {
        ETHIF_DET_REPORT_ERROR(ETHIF_API_ID_TXCONFIRMATION, ETHIF_E_INV_CTRL_IDX);
    }
    /*[SWS_EthIf_00094]*/
    else if(BufIdx >= ETHIF_GET_TXBUF_NUMBER(CtrlIdx)/*ETHIF_MAX_TXBUFS_TOTAL*/)
    {
        ETHIF_DET_REPORT_ERROR(ETHIF_API_ID_TXCONFIRMATION, ETHIF_E_INV_PARAM);
    }
    else
    {
        CtrlPtr = ETHIF_GET_CTRL_PTR(CtrlIdx);
        tmpCtrlIdx = CtrlIdx;
        tmpCtrlPtr = CtrlPtr;
        while((CtrlPtr->CtrlIdx == tmpCtrlPtr->CtrlIdx) && (CtrlPtr->EthApis == tmpCtrlPtr->EthApis))
        {
            if ( ETHIF_INVALID_OWNER != ETHIF_GETTXBUFOWNER(tmpCtrlIdx, BufIdx))
            {
                TxConfIdx = (uint8)ETHIF_GETTXBUFOWNER(tmpCtrlIdx, BufIdx);
                ETHIF_GETTXBUFOWNER(tmpCtrlIdx, BufIdx) = ETHIF_INVALID_OWNER;

                /*SWS_EthIf_00104,SWS_EthIf_00105*/
                TxConfirmationFctPtr = ETHIF_GET_TXCONF(TxConfIdx);
                if(TxConfirmationFctPtr != NULL_PTR)
                {
                    TxConfirmationFctPtr(tmpCtrlIdx, BufIdx);
                    break;
                }
            }
            tmpCtrlIdx++;
            tmpCtrlPtr = ETHIF_GET_CTRL_PTR(tmpCtrlIdx);
        }
    }
    
    return;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: EthIf_CtrlModeIndication
*                
* Description:   Controller mode indication. 
*                             
* Inputs:        CtrlIdx     : Controller index.
*                CtrlMode    : Controller mode.
*             
* Outputs:       None
* 
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, ETHIF_CODE) EthIf_CtrlModeIndication
(
    uint8 CtrlIdx,
    Eth_ModeType CtrlMode
)
{    
    if (ETHCTRL_STATE_INIT != EthIf_InitState)
    {
        ETHIF_DET_REPORT_ERROR(ETHIF_API_ID_CTRLMODEINDICATION, ETHIF_E_NOT_INITIALIZED);
    }
    else if (CtrlIdx >= ETHIF_GET_CTRL_NUMBER())
    {
        ETHIF_DET_REPORT_ERROR(ETHIF_API_ID_CTRLMODEINDICATION, ETHIF_E_INV_CTRL_IDX);
    }
    /*[SWS_EthIf_00252]*/
    else if(!ETHIF_CTRL_IS_VLAN(CtrlIdx))
    {
        ETHIF_CALLUP_CTRLMODE_INDICATION(CtrlIdx, CtrlMode);
    }
    else
    {
        /* Intentionally Empty */
    }

    return ;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: EthIf_TrcvModeIndication
*                
* Description:   Transceiver mode indication. 
*                             
* Inputs:        CtrlIdx     : Controller index.
*                TrcvMode    : Transceiver mode
*             
* Outputs:       None
* 
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, ETHIF_CODE) EthIf_TrcvModeIndication
(
    uint8  CtrlIdx,
    EthTrcv_ModeType TrcvMode
)
{
    if (ETHCTRL_STATE_INIT != EthIf_InitState)
    {
        ETHIF_DET_REPORT_ERROR(ETHIF_API_ID_TRCVMODEINDICATION, ETHIF_E_NOT_INITIALIZED);
    }
    else if (CtrlIdx >= ETHIF_GET_CTRL_NUMBER())
    {
        ETHIF_DET_REPORT_ERROR(ETHIF_API_ID_TRCVMODEINDICATION, ETHIF_E_INV_CTRL_IDX);
    }
    else
    {
        /*update transceiver mode of the virtual controller && inform upper layer of the new transceiver mode*/
        /*[SWS_EthIf_00253]*/
        ETHIF_CALLUP_TRCVMODE_INDICATION(CtrlIdx, TrcvMode);
    }

    return ;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: EthIf_MainFunctionRx
*                
* Description:   The Main function for receiving. 
*                             
* Inputs:        None
*             
* Outputs:       None
* 
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, ETHIF_CODE) EthIf_MainFunctionRx
(
    void
)
{
#if (ETHIF_ENABLE_RX_INTERRUPT == STD_OFF)
    uint8 CtrlId;
    uint8 CtrlTotalNum;
    uint16 RxCnt;
    Eth_RxStatusType EthRxStatus;
    EthIf_EthReceiveType EthRecFctPtr;
#endif
    /*[SWS_EthIf_00098]*/
    if (ETHCTRL_STATE_INIT != EthIf_InitState)
    {
        ETHIF_DET_REPORT_ERROR(ETHIF_API_ID_MAINFUNCTIONRX, ETHIF_E_NOT_INITIALIZED);
    }
    else
    {
/*[SWS_EthIf_00099]*/
#if (ETHIF_ENABLE_RX_INTERRUPT == STD_OFF)
        CtrlTotalNum = ETHIF_GET_CTRL_NUMBER();
        for (CtrlId = (uint8)0; CtrlId < CtrlTotalNum; CtrlId++)
        {
            if(ETHIF_GET_CTRL_MODE(CtrlId) == ETH_MODE_ACTIVE)
            {
                EthRecFctPtr = ETHIF_GET_CTRL_API_PTR(CtrlId)->Receive;
                if (NULL_PTR != EthRecFctPtr)
                {
                    for (RxCnt = (uint16)0; RxCnt < ETHIF_RX_INDICATION_ITERATIONS; RxCnt++)
                    {
                        EthRecFctPtr(ETHIF_GET_CTRL_PTR(CtrlId)->CtrlIdx, &EthRxStatus);
                        if (EthRxStatus != ETH_RECEIVED_MORE_DATA_AVAILABLE)
                        {
                            break;
                        }
                    }
                }
            }
        }
#endif
    }

    return ;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: EthIf_MainFunctionTx
*                
* Description:   The Main function for transmitting. 
*                             
* Inputs:        None
*             
* Outputs:       None
* 
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, ETHIF_CODE) EthIf_MainFunctionTx
(
    void
)
{
    uint8 CtrlTotalNum;
#if (ETHIF_ENABLE_TX_INTERRUPT == STD_OFF)
    uint8 CtrlId;
    EthIf_EthTxConfirmationType EthTxConfFctPtr;
#endif
    
    /*[SWS_EthIf_00124]*/
    if (ETHCTRL_STATE_INIT != EthIf_InitState)
    {
        ETHIF_DET_REPORT_ERROR(ETHIF_API_ID_MAINFUNCTIONTX, ETHIF_E_NOT_INITIALIZED);
    }
    else
    {
        CtrlTotalNum = ETHIF_GET_CTRL_NUMBER();
/*[SWS_EthIf_00100]*/
#if (ETHIF_ENABLE_TX_INTERRUPT == STD_OFF)

        for (CtrlId = (uint8)0; CtrlId < CtrlTotalNum; CtrlId++)
        {
            if(ETHIF_GET_CTRL_MODE(CtrlId) == ETH_MODE_ACTIVE)
            {
                EthTxConfFctPtr = ETHIF_GET_CTRL_API_PTR(CtrlId)->TxConfirmation;
                if (NULL_PTR != EthTxConfFctPtr)
                {
                    EthTxConfFctPtr(ETHIF_GET_CTRL_PTR(CtrlId)->CtrlIdx);
                }
            }
        }
#endif

        /*[SWS_EthIf_00101]*/
        if(EthIf_CheckLinkStateFreqCnt.FreqCnt == 0)
        {
            EthIf_CheckLinkStateFreqCnt.CtrlIdx = (uint8)0;
            EthIf_CheckLinkStateFreqCnt.FreqCnt = ETHIF_TRCV_LINKSTATECHG_MAIN_RELOAD;
        }
        if(EthIf_CheckLinkStateFreqCnt.CtrlIdx < CtrlTotalNum)
        {
            EthIf__PollTrcvLinkState();
        }
        EthIf_CheckLinkStateFreqCnt.FreqCnt--;
    }

    return;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: EthIf__PollTrcvLinkState
*
* Description:   Check if the link state of all the transceivers are changed.
*
* Inputs:        None
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, ETHIF_CODE) EthIf__PollTrcvLinkState
(
    void
)
{
    uint8 i;
    Std_ReturnType ret;
    uint8 count;
    uint8 CtrlId;
    uint8 LinkStateChgNum;
    EthIf_TrcvLinkStateChgFctPtr LinkStateChgFct;
    uint8 CtrlTotalNum = ETHIF_GET_CTRL_NUMBER();
    EthTrcv_LinkStateType localLinkState = ETHTRCV_LINK_STATE_DOWN;

    count = (uint8)0;
    while((count < ETHIF_LINKCHEK_NUM_PER_MAIN)
        && (EthIf_CheckLinkStateFreqCnt.CtrlIdx < CtrlTotalNum))
    {
        CtrlId = EthIf_CheckLinkStateFreqCnt.CtrlIdx;
        if((ETHIF_GET_CTRL_MODE(CtrlId) == ETH_MODE_ACTIVE)
            && (ETHIF_GET_TRCV_MODE(CtrlId) == ETHTRCV_MODE_ACTIVE))
        {
            switch(ETHIF_GET_PHYTYPE(CtrlId))
            {
            case ETHIF_NONE:    /*SWS_EthIf_00229*/
                ret = E_OK;
                localLinkState = ETHTRCV_LINK_STATE_ACTIVE;
                break;
            case ETHIF_TRCV:
                ret = EthIf__GetTrcvLinkState(CtrlId, &localLinkState);
                break;
            case ETHIF_SWTPORT_GROUP:
                ret = EthIf__GetPortGroupLinkState(CtrlId, &localLinkState);
                break;
            default:
                ret = E_NOT_OK;
                break;
            }

            /* inform UL module of LinkState and update EthIf_CtrlLinkState*/
            if((ret == E_OK) && (*ETHIF_GET_TRCV_LINK_STATE_PTR(CtrlId) != localLinkState))
            {
                LinkStateChgNum = ETHIF_GET_TRCV_LINKCHG_NUMBER();
                for (i = (uint8)0; i < LinkStateChgNum; i++)
                {
                    LinkStateChgFct = ETHIF_GET_TRCV_LINKCHG(i);
                    if(LinkStateChgFct != NULL_PTR)
                    {
                        LinkStateChgFct(CtrlId, localLinkState);
                    }
                }
                *ETHIF_GET_TRCV_LINK_STATE_PTR(CtrlId) = localLinkState;
            }
        }
        count++;
        EthIf_CheckLinkStateFreqCnt.CtrlIdx++;
    }
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: EthIf__GetTrcvLinkState
*
* Description:   Check if the link state of all the transceivers are changed.
*
* Inputs:        CtrlIdx
*
* Outputs:       Std_ReturnType E_OK: GetLinkState success
*                                 E_NOT_OK: GetLinkState failed: the trcv has no
*                                           GetLinkState function; the GetLinkState
*                                           function returns E_NOT_OK;
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(Std_ReturnType, ETHIF_CODE) EthIf__GetTrcvLinkState
(
    uint8 CtrlIdx,
    P2VAR(EthTrcv_LinkStateType, AUTOMATIC, ETHIF_APPL_DATA) LinkState
)
{
    uint8 TrcvId;
    Std_ReturnType ret;
    EthIf_EthTrcvGetLinkStateType EthTrcvGetLinkStateFctPtr;

    ret = E_NOT_OK;
    TrcvId = ETHIF_GET_CTRL_PTR(CtrlIdx)->PhyIdx;
    EthTrcvGetLinkStateFctPtr = ETHIF_GET_TRCV_API_PTR(TrcvId)->GetLinkState;
    if(EthTrcvGetLinkStateFctPtr != NULL_PTR)
    {
        ret = EthTrcvGetLinkStateFctPtr(ETHIF_GET_TRCV_PTR(CtrlIdx)->TrcvIdx, LinkState);
    }
    else
    {
        *LinkState = ETHTRCV_LINK_STATE_ACTIVE;
    }

    return ret;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: EthIf__GetPortGroupLinkState
*
* Description:   Check if the link state of all the transceivers are changed.
*
* Inputs:        CtrlIdx
*
* Outputs:       Std_ReturnType E_OK: GetLinkState success
*                                 E_NOT_OK: GetLinkState failed: all the ports has no
*                                           GetLinkState function; one of the ports
*                                           GetLinState failed
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(Std_ReturnType, ETHIF_CODE) EthIf__GetPortGroupLinkState
(
    uint8 CtrlIdx,
    P2VAR(EthTrcv_LinkStateType, AUTOMATIC, ETHIF_APPL_DATA) LinkState
)
{
    uint8 i;
    uint8 LinkUpNum;
    Std_ReturnType ret;
    uint8 PortMax;
    P2CONST(EthIf_SwtPortGroupType, AUTOMATIC, AUTOMATIC) SwtPortGroupPtr;
    EthIf_GetSwtLinkStateType SwtGetLinkStateFctPtr;

    ret = E_OK;
    LinkUpNum = (uint8)0;
    SwtPortGroupPtr = ETHIF_GET_SWTPORT_GROUP_PTR(CtrlIdx);
    PortMax = SwtPortGroupPtr->PortIdx + SwtPortGroupPtr->PortNum;
    for(i = SwtPortGroupPtr->PortIdx; i < PortMax; i++)
    {
        SwtGetLinkStateFctPtr = ETHIF_GET_PORT_API_PTR(i)->GetSwtLinkState;
        if(SwtGetLinkStateFctPtr != NULL_PTR)
        {
            ret = SwtGetLinkStateFctPtr(ETHIF_GET_HWSWT_IDX(i), ETHIF_GET_HWPORT_IDX(i), LinkState);
            if((ret == E_OK) && (*LinkState == ETHTRCV_LINK_STATE_ACTIVE))
            {
                LinkUpNum += 1;
            }
        }
        else
        {
            LinkUpNum += 1;
        }
    }
    if(LinkUpNum > 0)
    {
        *LinkState = ETHTRCV_LINK_STATE_ACTIVE;
    }
    else
    {
        *LinkState = ETHTRCV_LINK_STATE_DOWN;
    }

    return ret;
}

#include "MemMap.h"
