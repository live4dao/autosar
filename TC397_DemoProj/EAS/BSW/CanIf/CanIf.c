/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
*   File Name       : CanIf.c
********************************************************************************
*   Project/Product : AUTOSAR 4.2
*   Title           : CAN Interface module Source File
*   Author          : Hirain
********************************************************************************
*   Description     : Implementation of CAN Interface provided functionality
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
*   01.00.00    17/08/2016    Ning.Chen      N/A          Beta
*   01.01.00    17/03/2018    Ning.Chen      N/A          Original
*   01.01.01    13/08/2018    Feixiang.Dong  N/A          EAS422_CanIf_20180813_01
*   01.02.00    20/11/2018    Ning.Chen      N/A          EAS422_CanIf_20181120_01
*   01.02.01    08/09/2020    Yanan.Zhao1    N/A          EAS422_CanIf_20200908_01
*   01.02.02    11/03/2021    Ning.Chen      N/A          EAS422_CanIf_20210311_01
*   01.02.03    21/03/2023    Feixiang.Dong  N/A          EAS422_CanIf_20230321_01
*   01.02.05    08/05/2023    shuai.xu1      N/A          EAS422_CanIf_20230508_01
*   01.03.00    09/23/2023    Ning.Chen      N/A          EAS422_CanIf_20230923_01
*   01.03.01    12/13/2023    Ning.Chen      N/A          EAS422_CanIf_20231213_01
********************************************************************************
* END_FILE_HDR*/

/*******************************************************************************
*   Includes
*******************************************************************************/
#include "CanIf.h"
#include "CanIf_Cbk.h"
#include "Bsw_Common.h"

#include "SchM_CanIf.h"
#if(STD_ON == CANIF_PUBLIC_DEV_ERROR_DETECT)
#include "Det.h"
#endif

/*******************************************************************************
*   Version Check
*******************************************************************************/
/*CANIF021  CANIF728*/
#if(STD_ON == CANIF_PRIVATE_VERSION_CHECK)
/* check Version with other import module */


/* check Version with cfg file */
#if ((CANIF_AR_RELEASE_MAJOR_VERSION != CANIF_AR_RELEASE_MAJOR_VERSION_CFG) || \
   (CANIF_AR_RELEASE_MINOR_VERSION != CANIF_AR_RELEASE_MINOR_VERSION_CFG))
#error "AutoSar Version Numbers of CanIf and its cfg file are different"
#endif

#if ((CANIF_SW_MAJOR_VERSION != CANIF_SW_MAJOR_VERSION_CFG) || \
   (CANIF_SW_MINOR_VERSION != CANIF_SW_MINOR_VERSION_CFG))
#error "SW Version Numbers of CanIf and its cfg file are different"
#endif


#endif/*#if(STD_ON == CANIF_PRIVATE_AR_VERSION_CHECK)*/


/*******************************************************************************
*   Macro
*******************************************************************************/
#if(STD_ON == CANIF_PUBLIC_DEV_ERROR_DETECT)

#define  CANIF_DET_ERROR_DETECT(cond, ApiId, errcode)  \
    DET_ERROR_DETECT((cond), CANIF_MODULE_ID, CANIF_INSTANCE_ID,(ApiId),(errcode))

#define  CANIF_DET_ERROR_DETECT_RET(cond, ApiId, errcode, ret) \
    DET_ERROR_DETECT_RET((cond), CANIF_MODULE_ID,CANIF_INSTANCE_ID,(ApiId),(errcode), (ret))

#define  CANIF_DET_REPORT_ERROR(ApiId, errcode)  \
    DET_REPORT_ERROR(CANIF_MODULE_ID, CANIF_INSTANCE_ID, (ApiId), (errcode))

#else

#define  CANIF_DET_ERROR_DETECT(cond, ApiId, errcode)
#define  CANIF_DET_ERROR_DETECT_RET(cond, ApiId, errcode, ret)
#define  CANIF_DET_REPORT_ERROR(ApiId, errcode)

#endif

/* Used to less code cost in single channel case */
#if((CANIF_CONFIG_VARIANTS != STD_CONFIG_VARIANTS_PRECOMPILE) || (CANIF_MAX_CONTROLLER_NUM > 1))
#define CANIF_CONTROLLER_ID               (ControllerId)
#else
#define CANIF_CONTROLLER_ID               (0)
#endif

#if(STD_ON == CANIF_TRCV_WAKEUP_SUPPORT)
#if((CANIF_CONFIG_VARIANTS != STD_CONFIG_VARIANTS_PRECOMPILE) || (CANIF_MAX_TRCV_NUM > 1))
#define CANIF_TRCV_ID               (TransceiverId)
#else
#define CANIF_TRCV_ID               (0)
#endif
#endif


/* Access hth*/
#define CanIf_GetHthOfTxPdu(TxPduId)     (CANIF_HTH_CFG_INFO[CANIF_TXPDU_CFG_INFO[(TxPduId)].HthRef])
#if(CANIF_MAX_CONTROLLER_NUM > 1)
#define CanIf_CtrlIdOfTxPdu(TxPduId)     CanIf_GetHthOfTxPdu(TxPduId).CanIfCtrlIdRef
#endif
#define CanIf_HthOfTxPdu(TxPduId)        CanIf_GetHthOfTxPdu(TxPduId).HthIdSymRef
#define CanIf_HthTypeOfTxPdu(TxPduId)    CanIf_GetHthOfTxPdu(TxPduId).isFullCanType
#if(STD_ON == CANIF_PUBLIC_TX_BUFFERING)
#define CanIf_FirstIndexOfTxBuf(TxPduId) CanIf_GetHthOfTxPdu(TxPduId).FirstBufIndexHth
#define CanIf_SizeOfTxBuf(TxPduId)       CanIf_GetHthOfTxPdu(TxPduId).TxBufSize
#endif

#if(STD_ON == CANIF_PUBLIC_MULTIPLE_DRV_SUPPORT)
#define CanIf_GetDrvIdOfTxPdu(TxPduId)  CanIf_CtrlCfg[CanIf_CtrlIdOfTxPdu(TxPduId)].CanDrvIndex
#else
#define CanIf_GetDrvIdOfTxPdu(TxPduId)  (0)
#endif

/* Access hrh*/
#if(CANIF_MAX_CONTROLLER_NUM > 1)
#define CanIf_GetHrhOfRxPdu(RxPduId)    (CANIF_HRH_CFG_INFO[CANIF_RXPDU_CFG_INFO[(RxPduId)].HrhRef])
#define CanIf_CtrlIdOfRxPdu(RxPduId)    CanIf_GetHrhOfRxPdu(RxPduId).CanIfCtrlIdRef
#endif


#if(STD_ON == CANIF_PUBLIC_MULTIPLE_DRV_SUPPORT)
#define CanIf_GetDrvIdOfRxPdu(RxPduId)  CanIf_CtrlCfg[CanIf_CtrlIdOfRxPdu(RxPduId)].CanDrvIndex
#endif

/* Access Controller*/
#if(STD_ON == CANIF_PUBLIC_MULTIPLE_DRV_SUPPORT)
#define CanIf_GetDrvIdOfCtrl(ControllerId)  CanIf_CtrlCfg[ControllerId].CanDrvIndex
#define CanIf_GetCtrlId(ControllerId)       CanIf_CtrlCfg[ControllerId].CanCtrlIdRef
#else
#define CanIf_GetDrvIdOfCtrl(ControllerId)  (0)
#define CanIf_GetCtrlId(ControllerId)       (ControllerId)
#endif


/* Access Trcv*/
#if(CANIF_MAX_TRCV_NUM > 0)
#if(STD_ON == CANIF_PUBLIC_MULTIPLE_TRCVDRV_SUPPORT)
#define CanIf_GetDrvIdOfTrcv(TransceiverId)  CanIf_TrcvCfg[TransceiverId].TrcvDrvIndex
#define CanIf_GetTrcvId(TransceiverId)       CanIf_TrcvCfg[TransceiverId].CanTrcvRef
#else
#define CanIf_GetDrvIdOfTrcv(TransceiverId)  (0)
#define CanIf_GetTrcvId(TransceiverId)       (TransceiverId)
#endif
#endif


/*******************************************************************************
*   Local Data Define
*******************************************************************************/
#define CANIF_START_SEC_VAR_INIT_8
#include "MemMap.h"

STATIC VAR(Std_InitStateType, CANIF_VAR)  CanIf_InitStatus = STD_UNINITIALIZED;

#define CANIF_STOP_SEC_VAR_INIT_8
#include "MemMap.h"


#define CANIF_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"

#if(CANIF_CONFIG_VARIANTS == STD_CONFIG_VARIANTS_POSTBUILD)
STATIC P2CONST(CanIf_ConfigType, CANIF_VAR_NOINIT, CANIF_CONST) CanIf_ConfigSet;
#endif

#define CANIF_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"



#define CANIF_START_SEC_CODE
#include "MemMap.h"
#if(CANIF_MAX_TXPDU_NUM > 0)
STATIC FUNC(Std_ReturnType, CANIF_CODE) CanIf_TransmitInternal
(
    PduIdType CanTxPduId,
    P2CONST(PduInfoType, AUTOMATIC, CANIF_APPL_DATA) PduInfoPtr
);

#if(STD_ON == CANIF_PUBLIC_TX_BUFFERING)
STATIC FUNC(void, CANIF_CODE)  CanIf_ClearTransmitBuffer
(
    const uint8 ControllerId
);
#endif

#endif/* #if(CANIF_MAX_TXPDU_NUM > 0) */


#if(CANIF_MAX_RXPDU_NUM > 0)
STATIC FUNC(PduIdType, CANIF_CODE) CanIf_GetRxPduId
(
    uint8 ControllerId,
    Can_HwHandleType Hrh,
    Can_IdType CanId
);
#if((STD_OFF == CANIF_PUBLIC_MULTIPLE_DRV_SUPPORT) && (STD_OFF == CANIF_HOH_OPTIMIZE_SUPPORT))
STATIC FUNC(Can_HwHandleType, CANIF_CODE) CanIf_GetInternalHrh
(
    Can_HwHandleType Hrh
);
#endif

#if(STD_ON == CANIF_PRIVATE_DLC_CHECK)
STATIC FUNC(boolean, CANIF_CODE) CanIf_DlcCheck
(
    P2VAR(uint8, AUTOMATIC, AUTOMATIC)  CanDlc,
    const PduIdType RxPduId
);
#endif
#endif/*#if(CANIF_MAX_RXPDU_NUM > 0)*/

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: CanIf_Init  SWS_CANIF_00001
*
* Description:   This service Initializes internal and external interfaces of
*                the CAN Interface for the further processing.
*
* Inputs:        ConfigPtr: Pointer to configuration parameter set,
*                           used e.g. for post build parameters
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, CANIF_CODE) CanIf_Init
(
    P2CONST(CanIf_ConfigType, AUTOMATIC, CANIF_CONST) ConfigPtr
)
{
#if((CANIF_CONFIG_VARIANTS != STD_CONFIG_VARIANTS_PRECOMPILE) || (CANIF_MAX_CONTROLLER_NUM > 1))
    uint8 ControllerId;
#endif

#if((STD_ON == CANIF_PUBLIC_TX_BUFFERING) || (STD_ON == CANIF_PRIVATE_SWTXFIFO_SUPPORT))
#if(CANIF_MAX_HTH_NUM > 0)
    Can_HwHandleType HohCnt;
#endif
#endif
#if((CANIF_PUBLIC_TX_BUFFERING == STD_ON) \
  ||(STD_ON == CANIF_PUBLIC_SETDYNAMICTXID_API) \
  ||(STD_ON == CANIF_PUBLIC_READTXPDU_NOTIFY_STATUS_API) \
  ||(STD_ON == CANIF_PUBLIC_READRXPDU_NOTIFY_STATUS_API) \
  ||(STD_ON == CANIF_PUBLIC_READRXPDU_DATA_API))
    PduIdType PduCnt;
#endif


#if(CANIF_CONFIG_VARIANTS == STD_CONFIG_VARIANTS_POSTBUILD)
    if(NULL_PTR == ConfigPtr)
    {
        CANIF_DET_REPORT_ERROR(CANIF_INIT_APIID, CANIF_E_PARAM_POINTER);
    }
    else
#endif

    {
#if(CANIF_CONFIG_VARIANTS == STD_CONFIG_VARIANTS_POSTBUILD)
        CanIf_ConfigSet = ConfigPtr;
#else
        (void)ConfigPtr;
#endif

#if((CANIF_CONFIG_VARIANTS != STD_CONFIG_VARIANTS_PRECOMPILE) || (CANIF_MAX_CONTROLLER_NUM > 1))
        for(ControllerId = 0; ControllerId < CANIF_USED_CONTROLLER_NUM; ControllerId++)
#endif
        {
            CanIf_PduMode[CANIF_CONTROLLER_ID] = CANIF_OFFLINE;/*SWS_CANIF_00864*/
            CanIf_ControllerMode[CANIF_CONTROLLER_ID] = CANIF_CS_UNINIT;
#if(STD_ON == CANIF_PUBLIC_TXCONFIRM_POLLING_SUPPORT)
            CanIf_TxConfStatus[CANIF_CONTROLLER_ID] = CANIF_NO_NOTIFICATION;
#endif

#if((STD_ON == CANIF_TRCV_WAKEUP_SUPPORT) || (STD_ON == CANIF_CTRL_WAKEUP_SUPPORT))
#if(STD_ON == CANIF_PUBLIC_WAKEUP_CHECK_VALIDATION_SUPPORT)
            CanIf_WakeupStatus[CANIF_CONTROLLER_ID] = FALSE;/*SWS_CANIF_479*/
#endif
#endif

#if(STD_ON == CANIF_PUBLIC_PN_SUPPORT)
            CanIf_PnActive[CANIF_CONTROLLER_ID] = TRUE;/*SWS_CANIF_00863*/
#endif

        }

        /* CANIF387 init tx buffer */
#if(STD_ON == CANIF_PUBLIC_TX_BUFFERING)
#if(CANIF_MAX_HTH_NUM > 0)
        for(HohCnt = (Can_HwHandleType)0; HohCnt < CANIF_USED_HTH_NUM; HohCnt++)
        {
            CanIf_TxBufferFillCount[HohCnt] = (PduIdType)0;
        }
#endif

#if(CANIF_MAX_TXBUF_NUM > 0)
        for(PduCnt = (PduIdType)0; PduCnt < CANIF_USED_TXBUF_NUM; PduCnt++)
        {
            CanIf_TxBufActiveFlag[PduCnt] = FALSE;
            CanIf_TxBufPdu[PduCnt].id = (Can_IdType)0;
            CanIf_TxBufPdu[PduCnt].length = (uint8)0;
            CanIf_TxBufPdu[PduCnt].swPduHandle = COMSTACK_INVALID_PDUID;
            CanIf_TxBufPdu[PduCnt].sdu = NULL_PTR;
        }
#endif
#endif/*#if(STD_ON == CANIF_PUBLIC_TX_BUFFERING)*/

#if((STD_ON == CANIF_PRIVATE_SWTXFIFO_SUPPORT) && (CANIF_MAX_HTH_NUM > 0))
        for(HohCnt = (Can_HwHandleType)0; HohCnt < CANIF_USED_HTH_NUM; HohCnt++)
        {
            CanIf_TxSwFifo_ResetFifo(HohCnt);
        }
#endif



#if(STD_ON == CANIF_PUBLIC_SETDYNAMICTXID_API)
#if(CANIF_MAX_DYNTXPDU_NUM > 0)
        for(PduCnt = (PduIdType)0; PduCnt < CANIF_USED_TXPDU_NUM; PduCnt++)
        {
            if(TRUE == CANIF_TXPDU_CFG_INFO[PduCnt].isDynPduType)
            {
                /*SWS_CANIF_00857*/
                CanIf_TxPduCanIdForDynamic[CANIF_TXPDU_CFG_INFO[PduCnt].DynPduIndex]
                    = CANIF_TXPDU_CFG_INFO[PduCnt].CanId;
            }

        }
#endif
#endif

#if(STD_ON == CANIF_PUBLIC_READTXPDU_NOTIFY_STATUS_API)
#if(CANIF_MAX_TXNOTIFY_NUM > 0)
        for(PduCnt = (PduIdType)0; PduCnt < CANIF_USED_TXNOTIFY_NUM; PduCnt++)
        {
            CanIf_TxNotifStatus[PduCnt] = CANIF_NO_NOTIFICATION;
        }
#endif
#endif


#if(STD_ON == CANIF_PUBLIC_READRXPDU_NOTIFY_STATUS_API)
#if(CANIF_MAX_RXNOTIFY_NUM > 0)
        for(PduCnt = (PduIdType)0; PduCnt < CANIF_USED_RXNOTIFY_NUM; PduCnt++)
        {
            CanIf_RxNotifStatus[PduCnt] = CANIF_NO_NOTIFICATION;
        }
#endif
#endif

#if(STD_ON == CANIF_PUBLIC_READRXPDU_DATA_API)
#if(CANIF_MAX_RXBUF_NUM > 0)
        for(PduCnt = (PduIdType)0; PduCnt < CANIF_USED_RXBUF_NUM; PduCnt++)
        {
            CanIf_RxBufferSduLength[PduCnt] = (PduIdType)0;
        }
#endif
#endif

#if((CANIF_CONFIG_VARIANTS != STD_CONFIG_VARIANTS_PRECOMPILE) || (CANIF_MAX_CONTROLLER_NUM > 1))
        for(ControllerId = (uint8)0; ControllerId < CANIF_USED_CONTROLLER_NUM; ControllerId++)
#endif
        {
            /*SWS_CANIF_476 477 478*/
            CanIf_ControllerMode[CANIF_CONTROLLER_ID] = CANIF_CS_STOPPED;
        }
        CanIf_InitStatus = STD_INITIALIZED;
    }

}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: CanIf_SetControllerMode  SWS_CANIF_00003
*
* Description:   This service calls the corresponding CAN Driver service for
*                changing of the CAN controller mode.
*
* Inputs:        ControllerId: Abstracted CanIf ControllerId which is assigned
*                              to a CAN controller, which is requested for mode
*                              transition.
*                ControllerMode: Requested mode transition
*
* Outputs:       Std_ReturnType:E_OK: Controller mode request has been accepted
*                               E_NOT_OK: Controller mode request has not been
*                               accepted
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, CANIF_CODE) CanIf_SetControllerMode
(
    uint8 ControllerId,
    CanIf_ControllerModeType ControllerMode
)
{
    Std_ReturnType ret = E_OK;
    CanIf_CanSetControllerModeType canSetModeFctPtr;
    Can_StateTransitionType targetMode;

#if(CANIF_MAX_HTH_NUM > 0)
    Can_HwHandleType HohCnt;
#endif

    /*SWS_CANIF_00311 312*/
    if(STD_INITIALIZED != CanIf_InitStatus)
    {
        CANIF_DET_REPORT_ERROR(CANIF_SETCONTROLLERMODE_APIID, CANIF_E_UNINIT);
        ret = E_NOT_OK;
    }
    else if(ControllerId >= CANIF_USED_CONTROLLER_NUM)
    {
        CANIF_DET_REPORT_ERROR(CANIF_SETCONTROLLERMODE_APIID, CANIF_E_PARAM_CONTROLLERID);
        ret = E_NOT_OK;
    }
    else
    {
        /* since the state transition is not very clear in V4.0.3
        so here follow the V4.2.2's detail
        from start -> sleep and from sleep to start are both not allowed
        if the invalid transition is called, canDrv should return Not_Ok

        V4.2.2 SWS_CANIF_00488  SWS_CANIF_00487 ,
        CanSM will not send such transition request ever
        V4.0.3  CANIF719
        */

        /* src     dest  result
        stop -> stop  stop   SWS_CANIF_480
        stop -> start  start SWS_CANIF_481
        stop -> sleep  sleep SWS_CANIF_482

        start->start start   CANIF584
        start->stop stop        CANIF585
        start->sleep sleep     candrv retrun not ok

        sleep->sleep  sleep  SWS_CANIF_486
        sleep->stop  wake  SWS_CANIF_487
        sleep->start start  candrv retrun not ok
        */
        switch(ControllerMode)
        {
        case CANIF_CS_STARTED:
            targetMode = CAN_T_START;    /*if sleep ->start this will be detected by canDrv*/
#if((STD_ON == CANIF_PRIVATE_SWTXFIFO_SUPPORT) && (CANIF_MAX_HTH_NUM > 0))
            for(HohCnt = (Can_HwHandleType)0; HohCnt < CANIF_USED_HTH_NUM; HohCnt++)
                {
                    CanIf_TxSwFifo_ResetFifo(HohCnt);
                }
#endif
            break;

        case CANIF_CS_SLEEP:
            targetMode = CAN_T_SLEEP;  /*if sleep ->start this will be detected by canDrv*/
            /*
            SWS_CANIF_865, set OffLine when call CanIf_SetControllerMode(sleep)
            SWS_CANIF_0073,clear txbuffer when swtich to Offline
            */
            CanIf_PduMode[CANIF_CONTROLLER_ID] = CANIF_OFFLINE;
#if(STD_ON == CANIF_PUBLIC_TX_BUFFERING)
            CanIf_ClearTransmitBuffer((uint8)CANIF_CONTROLLER_ID);
#endif

#if(STD_ON == CANIF_PUBLIC_PN_SUPPORT)
            CanIf_PnActive[CANIF_CONTROLLER_ID] = TRUE;/*SWS_CANIF_00749*/
#endif


            break;

        case CANIF_CS_STOPPED:
            if(CANIF_CS_SLEEP == CanIf_ControllerMode[CANIF_CONTROLLER_ID])
            {
                targetMode = CAN_T_WAKEUP;
            }
            else
            {
                targetMode = CAN_T_STOP;
            }

            /*
            SWS_CANIF_866, set TxOffLine when call CanIf_SetControllerMode(stop)
            SWS_CANIF_489,clear txbuffer when swtich to txOffline
            */
            CanIf_PduMode[CANIF_CONTROLLER_ID] = CANIF_TX_OFFLINE;
#if(STD_ON == CANIF_PUBLIC_TX_BUFFERING)
            CanIf_ClearTransmitBuffer((uint8)CANIF_CONTROLLER_ID);
#endif

            break;

        default:
            /*SWS_CANIF_00774*/
            CANIF_DET_REPORT_ERROR(CANIF_SETCONTROLLERMODE_APIID, CANIF_E_PARAM_CTRLMODE);
            ret = E_NOT_OK;
            break;
        }

        if(E_OK == ret)
        {
            canSetModeFctPtr = CanIf_Can_SetControllerMode[CanIf_GetDrvIdOfCtrl(CANIF_CONTROLLER_ID)];
            if(NULL_PTR == canSetModeFctPtr)
            {
                CANIF_DET_REPORT_ERROR(CANIF_SETCONTROLLERMODE_APIID, CANIF_E_LINKAPINULL);
                ret = E_NOT_OK;
            }
            else
            {
                /*SWS_CANIF_00308*/
                if(CAN_OK != canSetModeFctPtr(CanIf_GetCtrlId((uint8)CANIF_CONTROLLER_ID), targetMode))
                {
                    ret = E_NOT_OK;/*SWS_CANIF_475*/
                }
            }
        }
    }
    return ret;

}


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: CanIf_GetControllerMode  SWS_CANIF_00229
*
* Description:   This service reports about the current status of the requested
*                CAN controller.
*
* Inputs:        ControllerId      Abstracted CanIf ControllerId which is
*                                  assigned to a CAN controller, which is
*                                  requested for current operation mode.
*                ControllerModePtr Pointer to a memory location, where the
*                                  current mode of the CAN controller will be
*                                  stored.
*
* Outputs:       Std_ReturnType:E_OK: Controller mode request has been accepted
*                               E_NOT_OK: Controller mode request has not been
*                               accepted
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, CANIF_CODE) CanIf_GetControllerMode
(
    uint8 ControllerId,
    P2VAR(CanIf_ControllerModeType, AUTOMATIC, CANIF_APPL_DATA) ControllerModePtr
)
{
    Std_ReturnType ret = E_NOT_OK;

    /*SWS_CANIF_00316 313 656*/
    if(STD_INITIALIZED != CanIf_InitStatus)
    {
        CANIF_DET_REPORT_ERROR(CANIF_GETCONTROLLERMODE_APIID, CANIF_E_UNINIT);
    }
    else if(ControllerId >= CANIF_USED_CONTROLLER_NUM)
    {
        CANIF_DET_REPORT_ERROR(CANIF_GETCONTROLLERMODE_APIID, CANIF_E_PARAM_CONTROLLERID);
    }
    else if(NULL_PTR == ControllerModePtr)
    {
        CANIF_DET_REPORT_ERROR(CANIF_GETCONTROLLERMODE_APIID, CANIF_E_PARAM_POINTER);
    }
    else
    {
        /*SWS_CANIF_00229*/
        *ControllerModePtr = CanIf_ControllerMode[CANIF_CONTROLLER_ID];
        ret = E_OK;
    }

    return ret;

}

#if(CANIF_MAX_TXPDU_NUM > 0)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: CanIf_TransmitInternal
*
* Description:   This service Transmit a can PDU
*
*
* Inputs:        CanTxPduId   L-PDU handle of CAN L-PDU to be transmitted.
*                             This handle specifies the corresponding CAN L-PDU
*                             ID and implicitly the CAN Driver instance as well
*                             as the corresponding CAN controller device.
*                PduInfoPtr   Pointer to a structure with CAN L-PDU related data
*                             DLC and pointer to CAN L-SDU buffer
*
* Outputs:       Std_ReturnType:E_OK: request has been accepted
*                               E_NOT_OK: request has not been accepted
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(Std_ReturnType, CANIF_CODE) CanIf_TransmitInternal
(
    PduIdType CanTxPduId,
    P2CONST(PduInfoType, AUTOMATIC, CANIF_APPL_DATA) PduInfoPtr
)
{
#if(STD_ON == CANIF_PRIVATE_CANFD_SUPPORT)
    uint8 CanIfTxPduBuffer[CANFD_MAX_DLC];
#else
    uint8 CanIfTxPduBuffer[CAN_MAX_DLC];
#endif


    Can_PduType CanIfTxPduObject;
    Can_ReturnType CanTxResult;
    CanIf_CanWriteType canWriteFctPtr;
#if((STD_ON == CANIF_PUBLIC_TX_BUFFERING) && (CANIF_MAX_TXBUF_NUM > 0) && (CANIF_MAX_HTH_NUM > 0))
    PduIdType txBufIndex;
#endif
    Std_ReturnType ret = E_NOT_OK;
    uint8 maxDlc = CAN_MAX_DLC;


    canWriteFctPtr = CanIf_Can_Write[CanIf_GetDrvIdOfTxPdu(CanTxPduId)];
    if(NULL_PTR == canWriteFctPtr)
    {
        CANIF_DET_REPORT_ERROR(CANIF_TRANSMIT_APIID, CANIF_E_LINKAPINULL);
    }
    else
    {
        /* SWS_CANIF_00318 SWS_CANIF_00243*/
        SchM_Enter_CanIf_CANIF_EXCLUSIVE_AREA_0();
#if(STD_ON == CANIF_PUBLIC_SETDYNAMICTXID_API)
#if(CANIF_MAX_DYNTXPDU_NUM > 0)
        /*So that,CanIf_SetDynamicTxId()will not be interrupted
        by CanIf_Transmit()*/

        if(TRUE == CANIF_TXPDU_CFG_INFO[CanTxPduId].isDynPduType)
        {
            CanIfTxPduObject.id = CanIf_TxPduCanIdForDynamic[CANIF_TXPDU_CFG_INFO[CanTxPduId].DynPduIndex];
        }
        else
#endif
#endif
        {
            CanIfTxPduObject.id = CANIF_TXPDU_CFG_INFO[CanTxPduId].CanId;
        }
        SchM_Exit_CanIf_CANIF_EXCLUSIVE_AREA_0();



#if(STD_ON == CANIF_PRIVATE_CANFD_SUPPORT)
        /* check dlc */
        if((Can_IdType)0 != (Can_IdType)(CAN_CANFD_MASK & CanIfTxPduObject.id))/* Ext CanId*/
        {
            maxDlc = CANFD_MAX_DLC;
        }
#endif


        if(PduInfoPtr->SduLength > maxDlc)/*SWS_CANIF_00893*/
        {
            CANIF_DET_REPORT_ERROR(CANIF_TRANSMIT_APIID, CANIF_E_DATA_LENGTH_MISMATCH);
        }
        else
        {
            SchM_Enter_CanIf_CANIF_EXCLUSIVE_AREA_0();
#if(STD_ON == CANIF_TRIGGER_TRANSMIT_SUPPORT)
            if(TRUE == CANIF_TXPDU_CFG_INFO[CanTxPduId].isTriggerPdu)
            {
                CanIfTxPduObject.length = (uint8)0;
                CanIfTxPduObject.sdu = NULL_PTR;
                CanIfTxPduObject.swPduHandle = CanTxPduId;
            }
            else
#endif
            {
                /* DLC has Checked in det */
                CanIfTxPduObject.length = (uint8)PduInfoPtr->SduLength;
                Bsw_MemCpy(CanIfTxPduBuffer, PduInfoPtr->SduDataPtr, (uint32)CanIfTxPduObject.length);
                CanIfTxPduObject.sdu = &CanIfTxPduBuffer[0];
                CanIfTxPduObject.swPduHandle = CanTxPduId;
            }
            SchM_Exit_CanIf_CANIF_EXCLUSIVE_AREA_0();

#if(STD_ON == CANIF_PRIVATE_SWTXFIFO_SUPPORT)
            /* fifo need HthRef , not CanIf_HthOfTxPdu*/
            CanTxResult =  CanIf_TxSwFifo_Write(CANIF_TXPDU_CFG_INFO[(CanTxPduId)].HthRef, &CanIfTxPduObject);
#else
            CanTxResult = canWriteFctPtr(CanIf_HthOfTxPdu(CanTxPduId), &CanIfTxPduObject);
#endif


            if(CAN_OK == CanTxResult )
            {
                ret = E_OK;/*SWS_CANIF_00162*/
            }
            else
            {
                ret = E_NOT_OK;
            }


#if((STD_ON == CANIF_PUBLIC_TX_BUFFERING) && (CANIF_MAX_TXBUF_NUM > 0) && (CANIF_MAX_HTH_NUM > 0))
            /*SWS_CANIF_00063, SWS_CANIF_00849,SWS_CANIF_00881
              SWS_CANIF_00381,835,836 :check if there is active buffer for this pdu
              SWS_CANIF_068, new data will overwrite old data in buffer

            */
            if(CAN_BUSY == CanTxResult)
            {
                txBufIndex = CANIF_TXPDU_CFG_INFO[(CanTxPduId)].TxBufIndex;
                if(txBufIndex != COMSTACK_INVALID_PDUID)
                {
                    SchM_Enter_CanIf_CANIF_EXCLUSIVE_AREA_1();

                    if(FALSE == CanIf_TxBufActiveFlag[txBufIndex])
                    {
                        CanIf_TxBufActiveFlag[txBufIndex] = TRUE;
                        CanIf_TxBufferFillCount[CANIF_TXPDU_CFG_INFO[(CanTxPduId)].HthRef]++;
                    }
#if(STD_ON == CANIF_TRIGGER_TRANSMIT_SUPPORT)
                    if(TRUE == CANIF_TXPDU_CFG_INFO[CanTxPduId].isTriggerPdu)
                    {
                        CanIf_TxBufPdu[txBufIndex].id = CanIfTxPduObject.id;
                        CanIf_TxBufPdu[txBufIndex].length = (uint8)0;
                        CanIf_TxBufPdu[txBufIndex].sdu = NULL_PTR;
                        CanIf_TxBufPdu[txBufIndex].swPduHandle = CanTxPduId;

                    }
                    else
#endif

                    {
                        /* CANIF068 */
                        Bsw_MemCpy(CANIF_TXPDU_CFG_INFO[(CanTxPduId)].dataBuf, CanIfTxPduBuffer, (uint32)CanIfTxPduObject.length);

                        CanIf_TxBufPdu[txBufIndex].id = CanIfTxPduObject.id;
                        CanIf_TxBufPdu[txBufIndex].length = CanIfTxPduObject.length;
                        CanIf_TxBufPdu[txBufIndex].sdu = CANIF_TXPDU_CFG_INFO[(CanTxPduId)].dataBuf;
                        CanIf_TxBufPdu[txBufIndex].swPduHandle = CanTxPduId;
                    }
                    SchM_Exit_CanIf_CANIF_EXCLUSIVE_AREA_1();

                    ret = E_OK;
                }
            }
#endif /*#if (STD_ON == CANIF_PUBLIC_TX_BUFFERING)*/

        }

    }
    return ret;
}

#endif/*#if(CANIF_MAX_TXPDU_NUM > 0)*/

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: CanIf_Transmit  SWS_CANIF_00005
*
* Description:   This service Transmit a can PDU
*
*
* Inputs:        CanTxPduId   L-PDU handle of CAN L-PDU to be transmitted.
*                             This handle specifies the corresponding CAN L-PDU
*                             ID and implicitly the CAN Driver instance as well
*                             as the corresponding CAN controller device.
*                PduInfoPtr   Pointer to a structure with CAN L-PDU related data
*                             DLC and pointer to CAN L-SDU buffer
*
* Outputs:       Std_ReturnType:E_OK: request has been accepted
*                               E_NOT_OK: request has not been accepted
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, CANIF_CODE) CanIf_Transmit
(
    PduIdType CanTxPduId,
    P2CONST(PduInfoType, AUTOMATIC, CANIF_APPL_DATA) PduInfoPtr
)
{

#if((CANIF_CONFIG_VARIANTS != STD_CONFIG_VARIANTS_PRECOMPILE) || (CANIF_MAX_CONTROLLER_NUM > 1))
    uint8 ControllerId = 0;
#endif

    Std_ReturnType ret = E_NOT_OK;
    CanIf_PduModeType tempMode;


    /*SWS_CANIF_00319 320*/
    if(STD_INITIALIZED != CanIf_InitStatus)
    {
        CANIF_DET_REPORT_ERROR(CANIF_TRANSMIT_APIID, CANIF_E_UNINIT);
    }
    else if(CanTxPduId >= CANIF_USED_TXPDU_NUM)
    {
        CANIF_DET_REPORT_ERROR(CANIF_TRANSMIT_APIID, CANIF_E_INVALID_TXPDUID);
    }
    else if((NULL_PTR == PduInfoPtr)
#if((STD_ON == CANIF_TRIGGER_TRANSMIT_SUPPORT) && (CANIF_MAX_TXPDU_NUM > 0))
            && (FALSE == CANIF_TXPDU_CFG_INFO[CanTxPduId].isTriggerPdu) /*SWS_CANIF_00882*/
#endif
           )
    {
        CANIF_DET_REPORT_ERROR(CANIF_TRANSMIT_APIID, CANIF_E_PARAM_POINTER);
    }
    else
    {

#if(CANIF_MAX_TXPDU_NUM > 0)

#if(CANIF_MAX_CONTROLLER_NUM > 1)
        ControllerId = CanIf_CtrlIdOfTxPdu(CanTxPduId);
#endif
        tempMode = CanIf_PduMode[CANIF_CONTROLLER_ID];

        /* SWS_CANIF_00317 if controller is not in start or the channel is in txoffline
           the tx request will not accept SWS_CANIF_00382 723 677*/
        if((CANIF_CS_STARTED != CanIf_ControllerMode[CANIF_CONTROLLER_ID])
                || (CANIF_OFFLINE == tempMode) /*SWS_CANIF_00073*/
                || (CANIF_TX_OFFLINE == tempMode)) /*SWS_CANIF_00489*/
        {
            /* remoce this Det as , message may need transmit in busoff state*/
            /*CANIF_DET_REPORT_ERROR(CANIF_TRANSMIT_APIID, CANIF_E_STOPPED);*/
        }
        else
        {
#if(STD_ON == CANIF_PUBLIC_PN_SUPPORT)/*SWS_CANIF_00750*/
            /* when pn enable, only pdu config as pnfilter can be transmit*/
            if((FALSE == CanIf_PnActive[CANIF_CONTROLLER_ID])
                    || (TRUE == CANIF_TXPDU_CFG_INFO[CanTxPduId].isPnFilterPdu))
#endif
            {
#if(STD_ON == CANIF_TXOFF_ACTIVE_SUPPORT)/*SWS_CANIF_00072*/
                if(CANIF_TX_OFFLINE_ACTIVE == tempMode)
                {
                    ret = E_OK;
                    /*
                    this call up back may cause uplayyer's state incorrect
                    */
                    CanIf_TxConfirmation(CanTxPduId);
                }
                else
#endif
                {
                    ret = CanIf_TransmitInternal(CanTxPduId, PduInfoPtr);
                }
            }

        }

#endif/*#if(CANIF_MAX_TXPDU_NUM > 0)*/
    }


    return ret;
}


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: CanIf_CancelTransmit  SWS_CANIF_00520
*
* Description:   This is a dummy API introduced for interface compatibility.
*
*
* Inputs:        CanTxPduId   L-PDU handle of CAN L-PDU to be transmitted.
*                             This handle specifies the corresponding CAN L-PDU
*                             ID and implicitly the CAN Driver instance as well
*                             as the corresponding CAN controller device.
*
* Outputs:       Std_ReturnType:Always return E_OK
*
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
#if(CANIF_PUBLIC_CANCEL_TRANSMIT_SUPPORT == STD_ON)/*SWS_CANIF_00521*/
FUNC(Std_ReturnType, CANIF_CODE) CanIf_CancelTransmit
(
    PduIdType CanTxPduId
)
{
    Std_ReturnType ret = E_NOT_OK;
    /*SWS_CANIF_00652*/
    if(STD_INITIALIZED != CanIf_InitStatus)
    {
        CANIF_DET_REPORT_ERROR(CANIF_CANCELTRANSMIT_APIID, CANIF_E_UNINIT);
    }
    else if(CanTxPduId >= CANIF_USED_TXPDU_NUM)
    {
        CANIF_DET_REPORT_ERROR(CANIF_CANCELTRANSMIT_APIID, CANIF_E_INVALID_TXPDUID);
    }
    else
    {
        /*******************************************************************
        * PRQA S 3112   MISRA-C:2004 Rule 14.2
        * CanTxPduId is not used because this is a dummy API introduced for
        * interface compatibility.
        * The "(void)" is to avoid generate warning information.
        * This part of code is verified manually and has no impact.
        *******************************************************************/
        (void)CanTxPduId;
        ret = E_OK;
    }

    return ret;
}
#endif


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: CanIf_ReadRxPduData SWS_CANIF_00194
*
* Description:   This service provides the CAN DLC and the received data of the
*                requested CanRxPduId to the calling upper layer.
*                NOTE:This API must not be used for CanRxPduIds, which are
*                defined to receive multiple CAN-Ids (range reception).
*
* Inputs:        CanRxPduId   L-PDU handle of CAN L-PDU to be received.
*                             This handle specifies the corresponding CAN L-PDU
*                             ID and implicitly the CAN Driver instance as well
*                             as the corresponding CAN controller device.
*                PduInfoPtr   Pointer to a structure with CAN L-PDU related data
*                             DLC and pointer to CAN L-SDU buffer
*
* Outputs:       Std_ReturnType  E_OK: Request for L-PDU data has been accepted
*                                E_NOT_OK: No valid data has been received
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
#if((STD_ON == CANIF_PUBLIC_READRXPDU_DATA_API) && (CANIF_MAX_RXBUF_NUM > 0))/*SWS_CANIF_00330*/
FUNC(Std_ReturnType, CANIF_CODE) CanIf_ReadRxPduData
(
    PduIdType CanRxPduId,
    P2VAR(PduInfoType, AUTOMATIC, CANIF_APPL_DATA) PduInfoPtr
)
{
#if((CANIF_CONFIG_VARIANTS != STD_CONFIG_VARIANTS_PRECOMPILE) || (CANIF_MAX_CONTROLLER_NUM > 1))
    uint8 ControllerId = (uint8)0;
#endif
    CanIf_PduModeType tempMode;
    Std_ReturnType ret = E_NOT_OK;
    PduIdType bufIndex = (PduIdType)0;

    /*SWS_CANIF_00325 326*/
    if(STD_INITIALIZED != CanIf_InitStatus)
    {
        CANIF_DET_REPORT_ERROR(CANIF_READRXPDUDATA_APIID, CANIF_E_UNINIT);
    }
    else if((CanRxPduId >= CANIF_USED_RXPDU_NUM) || (FALSE == CANIF_RXPDU_CFG_INFO[CanRxPduId].RxPduReadData))
    {
        CANIF_DET_REPORT_ERROR(CANIF_READRXPDUDATA_APIID, CANIF_E_INVALID_RXPDUID);
    }
    else if(NULL_PTR == PduInfoPtr)
    {
        CANIF_DET_REPORT_ERROR(CANIF_READRXPDUDATA_APIID, CANIF_E_PARAM_POINTER);
    }
    else
    {
#if(CANIF_MAX_RXBUF_NUM > 0)
#if(CANIF_MAX_CONTROLLER_NUM > 1)
        ControllerId = CanIf_CtrlIdOfRxPdu(CanRxPduId);
#endif
        tempMode = CanIf_PduMode[CANIF_CONTROLLER_ID];

        /*SWS_CANIF_00324*/
        if(CANIF_CS_STARTED == CanIf_ControllerMode[CANIF_CONTROLLER_ID])
        {
            if(tempMode > CANIF_TX_OFFLINE_ACTIVE)
            {
                bufIndex = CANIF_RXPDU_CFG_INFO[CanRxPduId].RxBufIndex;
                SchM_Enter_CanIf_CANIF_EXCLUSIVE_AREA_3();/*SWS_CANIF_199*//*SWS_CANIF_00329*/
#if(STD_ON == CANIF_PRIVATE_CANFD_SUPPORT)
                if(CanIf_RxBufferSduLength[bufIndex] <= CANFD_MAX_DLC)
#else
                if(CanIf_RxBufferSduLength[bufIndex] <= CAN_MAX_DLC)
#endif
                {

                    PduInfoPtr->SduLength = CanIf_RxBufferSduLength[bufIndex];
                    Bsw_MemCpy(PduInfoPtr->SduDataPtr, CANIF_RXPDU_CFG_INFO[CanRxPduId].dataBuf,
                               (uint32)CanIf_RxBufferSduLength[bufIndex]);

                    ret = E_OK;
                }
                SchM_Exit_CanIf_CANIF_EXCLUSIVE_AREA_3();
            }
        }
#endif/*#if(CANIF_MAX_RXBUF_NUM > 0)*/

    }
    return ret;
}
#endif

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: CanIf_ReadTxNotifStatus SWS_CANIF_00202
*
* Description:   This service returns the confirmation status
*                (confirmation occured of not) of a specific
*                static or dynamic CAN Tx L-PDU, requested by the CanTxPduId.
*
* Inputs:        CanTxPduId   L-PDU handle of CAN L-PDU to be transmitted.
*                             This handle specifies the corresponding CAN L-PDU
*                             ID and implicitly the CAN Driver instance as well
*                             as the corresponding CAN controller device.
*
* Outputs:       CanIf_NotifStatusType   Current confirmation status of the
*                                        corresponding CAN Tx L-PDU.
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
#if(STD_ON == CANIF_PUBLIC_READTXPDU_NOTIFY_STATUS_API)/*SWS_CANIF_00335*/
#if(CANIF_MAX_TXNOTIFY_NUM > 0)
FUNC(CanIf_NotifStatusType, CANIF_CODE) CanIf_ReadTxNotifStatus
(
    PduIdType CanTxPduId
)
{
    CanIf_NotifStatusType ret = CANIF_NO_NOTIFICATION;
    PduIdType notifyIndex;

    /*SWS_CANIF_00331 334*/
    if(STD_INITIALIZED != CanIf_InitStatus)
    {
        CANIF_DET_REPORT_ERROR(CANIF_READTXNOTIFSTATUS_APIID, CANIF_E_UNINIT);
    }
    else if((CanTxPduId >= CANIF_USED_TXPDU_NUM) || (FALSE == CANIF_TXPDU_CFG_INFO[CanTxPduId].TxPduReadNotifyStatus))
    {
        CANIF_DET_REPORT_ERROR(CANIF_READTXNOTIFSTATUS_APIID, CANIF_E_INVALID_TXPDUID);
    }
    else
    {

        notifyIndex = CANIF_TXPDU_CFG_INFO[CanTxPduId].TxNotifyIndex;
        if(CANIF_TX_RX_NOTIFICATION == CanIf_TxNotifStatus[notifyIndex])
        {
            ret =  CANIF_TX_RX_NOTIFICATION;
            CanIf_TxNotifStatus[notifyIndex] = CANIF_NO_NOTIFICATION;/*SWS_CANIF_00393*/
        }
    }

    return ret;
}
#endif
#endif

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: CanIf_ReadRxNotifStatus  SWS_CANIF_00230
*
* Description:   This service returns the indication status
*                (indication occured of not) of a specific
*                static or dynamic CAN Rx L-PDU, requested by the CanRxPduId.
*
* Inputs:        CanRxPduId   L-PDU handle of CAN L-PDU to be received.
*                             This handle specifies the corresponding CAN L-PDU
*                             ID and implicitly the CAN Driver instance as well
*                             as the corresponding CAN controller device.
*
* Outputs:       CanIf_NotifStatusType   Current confirmation status of the
*                                        corresponding CAN Rx L-PDU.
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
#if(STD_ON == CANIF_PUBLIC_READRXPDU_NOTIFY_STATUS_API)/*SWS_CANIF_00340*/
#if(CANIF_MAX_RXNOTIFY_NUM > 0)
FUNC(CanIf_NotifStatusType, CANIF_CODE) CanIf_ReadRxNotifStatus
(
    PduIdType CanRxPduId
)
{
    CanIf_NotifStatusType ret = CANIF_NO_NOTIFICATION;
    PduIdType notifyIndex;

    /*SWS_CANIF_00336  339*/
    if(STD_INITIALIZED != CanIf_InitStatus)
    {
        CANIF_DET_REPORT_ERROR(CANIF_READRXNOTIFSTATUS_APIID, CANIF_E_UNINIT);
    }
    else if((CanRxPduId >= CANIF_USED_RXPDU_NUM) || (FALSE == CANIF_RXPDU_CFG_INFO[CanRxPduId].RxPduReadNotifyStatus))
    {
        CANIF_DET_REPORT_ERROR(CANIF_READRXNOTIFSTATUS_APIID, CANIF_E_INVALID_RXPDUID);
    }
    else
    {

        notifyIndex = CANIF_RXPDU_CFG_INFO[CanRxPduId].RxNotifyIndex;
        if(CANIF_TX_RX_NOTIFICATION == CanIf_RxNotifStatus[notifyIndex])
        {
            ret =  CANIF_TX_RX_NOTIFICATION;
            CanIf_RxNotifStatus[notifyIndex] = CANIF_NO_NOTIFICATION;  /*SWS_CANIF_00394*/
        }

    }

    return ret;
}
#endif
#endif

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: CanIf_SetPduMode  SWS_CANIF_00008
*
* Description:   This service sets the requested mode at the L-PDUs of a
*                predefined logical PDU channel.
*
* Inputs:        ControllerId   All PDUs of the own ECU connected to the
*                               corresponding CanIf ControllerId, which is
*                               assigned to a physical CAN controller are
*                               addressed.
*                PduModeRequest Requested PDU mode change
*                               (see CanIf_PduSetModeType)
*
* Outputs:       Std_ReturnType:E_OK: Controller mode request has been accepted
*                               E_NOT_OK: Controller mode request has not been
*                               accepted
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, CANIF_CODE) CanIf_SetPduMode
(
    uint8 ControllerId,
    CanIf_PduModeType PduModeRequest
)
{
    Std_ReturnType ret = E_NOT_OK;

    /*SWS_CANIF_00860 341 344*/
    if(STD_INITIALIZED != CanIf_InitStatus)
    {
        CANIF_DET_REPORT_ERROR(CANIF_SETPDUMODE_APIID, CANIF_E_UNINIT);
    }
    else if(ControllerId >= CANIF_USED_CONTROLLER_NUM)
    {
        CANIF_DET_REPORT_ERROR(CANIF_SETPDUMODE_APIID, CANIF_E_PARAM_CONTROLLERID);
    }
    else if(PduModeRequest > CANIF_ONLINE)
    {
        CANIF_DET_REPORT_ERROR(CANIF_SETPDUMODE_APIID, CANIF_E_PARAM_PDU_MODE);
    }
    else
    {
        /*SWS_CANIF_00874*/
        if(CANIF_CS_STARTED == CanIf_ControllerMode[CANIF_CONTROLLER_ID])
        {


#if(STD_ON == CANIF_PUBLIC_TX_BUFFERING)
            /* clear tx buffer when enter offline txoffline  SWS_CANIF_0073 SWS_CANIF_489
               tx-off-active is not reqired by autosar, but here also clear buffer
            */
            if(PduModeRequest < CANIF_ONLINE)
            {
                CanIf_ClearTransmitBuffer((uint8)CANIF_CONTROLLER_ID);
            }

#endif

#if(STD_ON == CANIF_PUBLIC_PN_SUPPORT)
            /* SWS_CANIF_00878 */
            if(PduModeRequest == CANIF_TX_OFFLINE)
            {
                CanIf_PnActive[CANIF_CONTROLLER_ID] = TRUE;
            }

#endif

            CanIf_PduMode[CANIF_CONTROLLER_ID] = PduModeRequest;
            ret = E_OK;
        }

    }

    return ret;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: CanIf_GetPduMode  SWS_CANIF_00009
*
* Description:   This service reports the current mode of a requested PDU
*                channel.
*
* Inputs:        ControllerId   All PDUs of the own ECU connected to the
*                               corresponding CanIf ControllerId, which is
*                               assigned to a physical CAN controller are
*                               addressed.
*                PduModePtr     Pointer to a memory location, where the current
*                               mode of the logical PDU channel will be stored.
*
* Outputs:       Std_ReturnType:E_OK: Controller mode request has been accepted
*                               E_NOT_OK: Controller mode request has not been
*                               accepted
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, CANIF_CODE) CanIf_GetPduMode
(
    uint8 ControllerId,
    P2VAR(CanIf_PduModeType, AUTOMATIC, CANIF_APPL_DATA) PduModePtr
)
{
    Std_ReturnType ret = E_NOT_OK;
    /*SWS_CANIF_00346 349 657*/
    if(STD_INITIALIZED != CanIf_InitStatus)
    {
        CANIF_DET_REPORT_ERROR(CANIF_GETPDUMODE_APIID, CANIF_E_UNINIT);
    }
    else if(ControllerId >= CANIF_USED_CONTROLLER_NUM)
    {
        CANIF_DET_REPORT_ERROR(CANIF_GETPDUMODE_APIID, CANIF_E_PARAM_CONTROLLERID);
    }
    else if(NULL_PTR == PduModePtr)
    {
        CANIF_DET_REPORT_ERROR(CANIF_GETPDUMODE_APIID, CANIF_E_PARAM_POINTER);
    }
    else
    {
        *PduModePtr = CanIf_PduMode[CANIF_CONTROLLER_ID];
        ret = E_OK;
    }
    return ret;
}


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: CanIf_GetVersionInfo  SWS_CANIF_00158
*
* Description:   This service returns the version information of the called
*                CAN Interface module
*
* Inputs:        VersionInfo  Pointer to where to store the version information
*                             of this module.DLC and pointer to CAN L-SDU buffer
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
#if(STD_ON == CANIF_PUBLIC_VERSION_INFO_API)
FUNC(void, CANIF_CODE) CanIf_GetVersionInfo
(
    P2VAR(Std_VersionInfoType, AUTOMATIC, CANIF_APPL_DATA) VersionInfo
)
{
    if(NULL_PTR == VersionInfo)
    {
        CANIF_DET_REPORT_ERROR(CANIF_GETVERSIONINFO, CANIF_E_PARAM_POINTER);
    }
    else
    {
        /*SWS_CANIF_00661 getVersion can be called even canif is not init */
        VersionInfo->vendorID = CANIF_VENDOR_ID;
        VersionInfo->moduleID = CANIF_MODULE_ID;

        VersionInfo->sw_major_version = (uint8)CANIF_SW_MAJOR_VERSION;
        VersionInfo->sw_minor_version = (uint8)CANIF_SW_MINOR_VERSION;
        VersionInfo->sw_patch_version = (uint8)CANIF_SW_PATCH_VERSION;
    }
}
#endif



/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: CanIf_SetDynamicTxId  SWS_CANIF_00189
*
* Description:   This service set dynamic id
*
* Inputs:        CanTxPduId   L-PDU handle of CAN L-PDU to be transmitted.
*                             This handle specifies the corresponding CAN L-PDU
*                             ID and implicitly the CAN Driver instance as well
*                             as the corresponding CAN controller device.
*                CanId        Standard/Extended CAN ID of CAN L-PDU that shall
*                             be transmitted
*
* Outputs:       None
*
* Limitations:   The input id must have extension bit
********************************************************************************
END_FUNCTION_HDR*/
#if (STD_ON == CANIF_PUBLIC_SETDYNAMICTXID_API)/*SWS_CANIF_00357*/
#if(CANIF_MAX_DYNTXPDU_NUM > 0)
FUNC(void, CANIF_CODE) CanIf_SetDynamicTxId
(
    PduIdType CanTxPduId,
    Can_IdType CanId
)
{
    const Can_IdType usedId = CanId & CAN_CANID_MASK;
    uint32 maxId;

    /*SWS_CANIF_00352 355 356*/
    if(STD_INITIALIZED != CanIf_InitStatus)
    {
        CANIF_DET_REPORT_ERROR(CANIF_SETDYNAMICTXID_APIID, CANIF_E_UNINIT);
    }
    else if((CanTxPduId >= CANIF_USED_TXPDU_NUM) || (FALSE == CANIF_TXPDU_CFG_INFO[CanTxPduId].isDynPduType))
    {
        CANIF_DET_REPORT_ERROR(CANIF_SETDYNAMICTXID_APIID, CANIF_E_INVALID_TXPDUID);
    }
    else
    {
        /*CANIF353
              extension bit = 0, id must <= 0x7ff
              extension bit = 1, id must <= 0x1fffffff
        */
        if(CAN_EXT_CANID_FLAG == (CanId & CAN_EXT_CANID_FLAG))
        {
            maxId = CAN_EXT_MAX_CANID;
        }
        else
        {
            maxId = (uint32)CAN_STD_MAX_CANID;
        }

        if(usedId > maxId)
        {
            CANIF_DET_REPORT_ERROR(CANIF_SETDYNAMICTXID_APIID, CANIF_E_PARAM_CANID);
        }
        else
        {
            /*SWS_CANIF_00356*/
            SchM_Enter_CanIf_CANIF_EXCLUSIVE_AREA_0();
            CanIf_TxPduCanIdForDynamic[CANIF_TXPDU_CFG_INFO[CanTxPduId].DynPduIndex] = CanId;
            SchM_Exit_CanIf_CANIF_EXCLUSIVE_AREA_0();

        }
    }

}
#endif
#endif

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: CanIf_SetTrcvMode  SWS_CANIF_00287
*
* Description:   This service set Trcv's opration mode
*
* Inputs:        TransceiverId, TranseiverMode
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
#if(CANIF_MAX_TRCV_NUM > 0)/*SWS_CANIF_362  367 371 373*/
FUNC(Std_ReturnType, CANIF_CODE) CanIf_SetTrcvMode
(
    uint8 TransceiverId,
    CanTrcv_TrcvModeType TranseiverMode
)
{
    Std_ReturnType ret = E_NOT_OK;

    /*SWS_CANIF_00538 648*/
    if(STD_INITIALIZED != CanIf_InitStatus)
    {
        CANIF_DET_REPORT_ERROR(CANIF_SETTRCVMODE_APIID, CANIF_E_UNINIT);
    }
    else if(TransceiverId >= CANIF_USED_TRCV_NUM)
    {
        CANIF_DET_REPORT_ERROR(CANIF_SETTRCVMODE_APIID, CANIF_E_PARAM_TRCV);
    }
    else if((CANTRCV_TRCVMODE_NORMAL != TranseiverMode)
            && (CANTRCV_TRCVMODE_SLEEP != TranseiverMode)
            && (CANTRCV_TRCVMODE_STANDBY != TranseiverMode))
    {
        CANIF_DET_REPORT_ERROR(CANIF_SETTRCVMODE_APIID, CANIF_E_PARAM_TRCVMODE);
    }
    else if(NULL_PTR == CanIf_CanTrcv_SetOpMode[CanIf_GetDrvIdOfTrcv(TransceiverId)])
    {
        CANIF_DET_REPORT_ERROR(CANIF_SETTRCVMODE_APIID, CANIF_E_LINKAPINULL);
    }
    else
    {
        /*SWS_CANIF_00358*/
        ret = CanIf_CanTrcv_SetOpMode[CanIf_GetDrvIdOfTrcv(TransceiverId)](CanIf_GetTrcvId(TransceiverId), TranseiverMode);
    }


    return ret;

}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: CanIf_GetTrcvMode  SWS_CANIF_00288
*
* Description:   This service get Trcv's opration mode
*
* Inputs:        TransceiverId, TransceiverModePtr
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, CANIF_CODE) CanIf_GetTrcvMode
(
    P2VAR(CanTrcv_TrcvModeType, AUTOMATIC, CANIF_APPL_DATA)  TransceiverModePtr,
    uint8 TransceiverId
)
{
    Std_ReturnType ret = E_NOT_OK;

    /*SWS_CANIF_00364 650 */
    if(STD_INITIALIZED != CanIf_InitStatus)
    {
        CANIF_DET_REPORT_ERROR(CANIF_GETTRCVMODE_APIID, CANIF_E_UNINIT);
    }
    else if(TransceiverId >= CANIF_USED_TRCV_NUM)
    {
        CANIF_DET_REPORT_ERROR(CANIF_GETTRCVMODE_APIID, CANIF_E_PARAM_TRCV);
    }
    else if(NULL_PTR == TransceiverModePtr)
    {
        CANIF_DET_REPORT_ERROR(CANIF_GETTRCVMODE_APIID, CANIF_E_PARAM_POINTER);
    }
    else if(NULL_PTR == CanIf_CanTrcv_GetOpMode[CanIf_GetDrvIdOfTrcv(TransceiverId)])
    {
        CANIF_DET_REPORT_ERROR(CANIF_GETTRCVMODE_APIID, CANIF_E_LINKAPINULL);
    }
    else
    {
        /*SWS_CANIF_00363*/
        ret = CanIf_CanTrcv_GetOpMode[CanIf_GetDrvIdOfTrcv(TransceiverId)](CanIf_GetTrcvId(TransceiverId), TransceiverModePtr);
    }

    return ret;

}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: CanIf_GetTrcvWakeupReason  SWS_CANIF_00289
*
* Description:   This service get Trcv's wakeup reason
*
* Inputs:        TransceiverId, TrcvWuReasonPtr
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, CANIF_CODE) CanIf_GetTrcvWakeupReason
(
    uint8 TransceiverId,
    P2VAR(CanTrcv_TrcvWakeupReasonType, AUTOMATIC, CANIF_APPL_DATA)  TrcvWuReasonPtr
)
{
    Std_ReturnType ret = E_NOT_OK;


    /*SWS_CANIF_00537 649 */
    if(STD_INITIALIZED != CanIf_InitStatus)
    {
        CANIF_DET_REPORT_ERROR(CANIF_GETTRCVWUR_APIID, CANIF_E_UNINIT);
    }
    else if(TransceiverId >= CANIF_USED_TRCV_NUM)
    {
        CANIF_DET_REPORT_ERROR(CANIF_GETTRCVWUR_APIID, CANIF_E_PARAM_TRCV);
    }
    else if(NULL_PTR == TrcvWuReasonPtr)
    {
        CANIF_DET_REPORT_ERROR(CANIF_GETTRCVWUR_APIID, CANIF_E_PARAM_POINTER);
    }
    else if(NULL_PTR == CanIf_CanTrcv_GetWuR[CanIf_GetDrvIdOfTrcv(TransceiverId)])
    {
        CANIF_DET_REPORT_ERROR(CANIF_GETTRCVWUR_APIID, CANIF_E_LINKAPINULL);
    }
    else
    {
        /*SWS_CANIF_00368*/
        ret = CanIf_CanTrcv_GetWuR[CanIf_GetDrvIdOfTrcv(TransceiverId)](CanIf_GetTrcvId(TransceiverId), TrcvWuReasonPtr);
    }

    return ret;

}


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: CanIf_SetTrcvWakeupMode  SWS_CANIF_00290
*
* Description:   This service set Trcv's wakeup mode
*
* Inputs:        TransceiverId, TrcvWakeupMode
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, CANIF_CODE) CanIf_SetTrcvWakeupMode
(
    uint8 TransceiverId,
    CanTrcv_TrcvWakeupModeType TrcvWakeupMode
)
{
    Std_ReturnType ret = E_NOT_OK;

    /*SWS_CANIF_00535 536*/
    if(STD_INITIALIZED != CanIf_InitStatus)
    {
        CANIF_DET_REPORT_ERROR(CANIF_SETTRCVWUMODE_APIID, CANIF_E_UNINIT);
    }
    else if(TransceiverId >= CANIF_USED_TRCV_NUM)
    {
        CANIF_DET_REPORT_ERROR(CANIF_SETTRCVWUMODE_APIID, CANIF_E_PARAM_TRCV);
    }
    else if((CANTRCV_WUMODE_ENABLE != TrcvWakeupMode)
            && (CANTRCV_WUMODE_DISABLE != TrcvWakeupMode)
            && (CANTRCV_WUMODE_CLEAR != TrcvWakeupMode))
    {
        CANIF_DET_REPORT_ERROR(CANIF_SETTRCVWUMODE_APIID, CANIF_E_PARAM_TRCVWAKEUPMODE);
    }
    else if(NULL_PTR == CanIf_CanTrcv_SetWuMode[CanIf_GetDrvIdOfTrcv(TransceiverId)])
    {
        CANIF_DET_REPORT_ERROR(CANIF_SETTRCVWUMODE_APIID, CANIF_E_LINKAPINULL);
    }
    else
    {
        /*SWS_CANIF_00372*/
        ret = CanIf_CanTrcv_SetWuMode[CanIf_GetDrvIdOfTrcv(TransceiverId)](CanIf_GetTrcvId(TransceiverId), TrcvWakeupMode);
    }

    return ret;

}

#endif/*#if (CANIF_MAX_TRCV_NUM > 0)*/

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: CanIf_CheckWakeup  SWS_CANIF_00219
*
* Description:   This service check the wakeu src
*
* Inputs:        WakeupSource
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
/* SWS_CANIF_00180 892*/
#if((STD_ON == CANIF_TRCV_WAKEUP_SUPPORT) || (STD_ON == CANIF_CTRL_WAKEUP_SUPPORT))
FUNC(Std_ReturnType, CANIF_CODE) CanIf_CheckWakeup
(
    EcuM_WakeupSourceType WakeupSource
)
{
    uint8 searchIndex = (uint8)0;
#if((CANIF_CONFIG_VARIANTS != STD_CONFIG_VARIANTS_PRECOMPILE) || (CANIF_MAX_CONTROLLER_NUM > 1))
    uint8 ControllerId;
#endif

#if(STD_ON == CANIF_CTRL_WAKEUP_SUPPORT)
    CanIf_CanCheckWakeupType canCheckFctPtr;
#endif

#if(STD_ON == CANIF_TRCV_WAKEUP_SUPPORT)
#if((CANIF_CONFIG_VARIANTS != STD_CONFIG_VARIANTS_PRECOMPILE) || (CANIF_MAX_TRCV_NUM > 1))
    uint8 TransceiverId;
#endif
    CanIf_TrcvCheckWakeupType canTrcvCheckFctPtr;
#endif
    Std_ReturnType ret = E_NOT_OK;

    /*SWS_CANIF_00401 398*/
    boolean srcValidFlag = FALSE;/* used to check the WakeupSource  */

    if(STD_INITIALIZED != CanIf_InitStatus)
    {
        CANIF_DET_REPORT_ERROR(CANIF_CHECKWAKEUP_APIID, CANIF_E_UNINIT);
    }
    else
    {
        /* SWS_CANIF_395 720 678
           first get target controller or trcv , search the wakeup source
           each controller or trcv can only have single wakeupsource
           then, call the target Xxx_CheckWakeup to confirm the wakeup
          */

        for(searchIndex = (uint8)0; searchIndex < CANIF_USED_WAKRUPSRC_NUM; searchIndex++)
        {
            if((EcuM_WakeupSourceType)0 != (CanIf_WakeupCfg[searchIndex].Source & WakeupSource))
            {
			    srcValidFlag = TRUE;
#if((CANIF_CONFIG_VARIANTS != STD_CONFIG_VARIANTS_PRECOMPILE) || (CANIF_MAX_CONTROLLER_NUM > 1))
                ControllerId = CanIf_WakeupCfg[searchIndex].CanIfCtrlIndex;
#endif

#if(STD_ON == CANIF_PUBLIC_DEV_ERROR_DETECT)
                /* SWS_CANIF_679 */
                if(CANIF_CS_SLEEP != CanIf_ControllerMode[CANIF_CONTROLLER_ID])
                {
                    CANIF_DET_REPORT_ERROR(CANIF_CHECKWAKEUP_APIID, CANIF_E_NOT_SLEEP);
                }
                else
#endif
                {
#if(STD_ON == CANIF_TRCV_WAKEUP_SUPPORT)
                    if(FALSE == CanIf_WakeupCfg[searchIndex].isCtrlWakeupType)
                    {
#if((CANIF_CONFIG_VARIANTS != STD_CONFIG_VARIANTS_PRECOMPILE) || (CANIF_MAX_TRCV_NUM > 1))
                        TransceiverId = CanIf_WakeupCfg[searchIndex].CanIfTrcvIndex;
#endif
                        canTrcvCheckFctPtr = CanIf_CanTrcv_CheckWakeup[CanIf_GetDrvIdOfTrcv(CANIF_TRCV_ID)];
#if(STD_ON == CANIF_PUBLIC_DEV_ERROR_DETECT)
                        if(NULL_PTR == canTrcvCheckFctPtr)
                        {
                            CANIF_DET_REPORT_ERROR(CANIF_CHECKWAKEUP_APIID, CANIF_E_LINKAPINULL);
                        }
                        else
#endif
                        {
                            ret = canTrcvCheckFctPtr(CanIf_GetTrcvId(CANIF_TRCV_ID));
                        }
                    }
                    else
#endif
                    {
#if(STD_ON == CANIF_CTRL_WAKEUP_SUPPORT)
                        canCheckFctPtr = CanIf_Can_CheckWakeup[CanIf_GetDrvIdOfCtrl(CANIF_CONTROLLER_ID)];
#if(STD_ON == CANIF_PUBLIC_DEV_ERROR_DETECT)
                        if(NULL_PTR == canCheckFctPtr)
                        {
                            CANIF_DET_REPORT_ERROR(CANIF_CHECKWAKEUP_APIID, CANIF_E_LINKAPINULL);
                        }
                        else
#endif
                        {
                            if(CAN_OK == canCheckFctPtr(CanIf_GetCtrlId((uint8)CANIF_CONTROLLER_ID)))
                            {
                                ret = E_OK;
                            }
                        }
#endif
                    }

                }
                /* dont break as more than 1 wakesrc may be input */

            }

        }

        if(srcValidFlag == FALSE)/* SWS_CANIF_00398*/
        {
            CANIF_DET_REPORT_ERROR(CANIF_CHECKWAKEUP_APIID, CANIF_E_PARAM_WAKEUPSOURCE);
        }

    }

    return ret;

}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: CanIf_CheckValidation  SWS_CANIF_00178
*
* Description:   This service validation the wakeup event
*
* Inputs:        WakeupSource
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
#if(STD_ON == CANIF_PUBLIC_WAKEUP_CHECK_VALIDATION_SUPPORT)/*SWS_CANIF_226 408*/
FUNC(Std_ReturnType, CANIF_CODE) CanIf_CheckValidation
(
    EcuM_WakeupSourceType WakeupSource
)
{
    /* */
    uint8 searchIndex = (uint8)0;
#if((CANIF_CONFIG_VARIANTS != STD_CONFIG_VARIANTS_PRECOMPILE) || (CANIF_MAX_CONTROLLER_NUM > 1))
    uint8 ControllerId;
#endif
    boolean flag = FALSE;
    EcuM_WakeupSourceType retSrc = (EcuM_WakeupSourceType)0;/* all clear */
    Std_ReturnType ret = E_NOT_OK;


    /*SWS_CANIF_00407*/
    if(STD_INITIALIZED != CanIf_InitStatus)
    {
        CANIF_DET_REPORT_ERROR(CANIF_CHECKVALIDATION_APIID, CANIF_E_UNINIT);
    }
    else
    {
        for(searchIndex = (uint8)0; searchIndex < CANIF_USED_WAKRUPSRC_NUM; searchIndex++)
        {
            if((EcuM_WakeupSourceType)0 != (CanIf_WakeupCfg[searchIndex].Source & WakeupSource))
            {
#if((CANIF_CONFIG_VARIANTS != STD_CONFIG_VARIANTS_PRECOMPILE) || (CANIF_MAX_CONTROLLER_NUM > 1))
                ControllerId = CanIf_WakeupCfg[searchIndex].CanIfCtrlIndex;
#endif
                if(TRUE == CanIf_WakeupStatus[CANIF_CONTROLLER_ID])
                {
                    retSrc = WakeupSource;   /*SWS_CANIF_179*/
                }

                /* dont break as more than 1 wakesrc may be input */
                flag = TRUE;
            }
        }


        if(flag != TRUE)/*SWS_CANIF_00404*/
        {
            CANIF_DET_REPORT_ERROR(CANIF_CHECKVALIDATION_APIID, CANIF_E_PARAM_WAKEUPSOURCE);
        }
        else
        {
#if(CANIF_CONFIG_VARIANTS != STD_CONFIG_VARIANTS_PRECOMPILE)
            if(NULL_PTR == CanIf_DispatchUserValidateWakeupEventName)
#endif
            {
                if((EcuM_WakeupSourceType)0 != retSrc)
                {
                    CANIF_DISPATCH_USERVALIDATEWAKEUPEVENT_NAME;/*SWS_CANIF_179*/
                }
                ret = E_OK;
            }
        }
    }


    /* tbd, if no src is valid, still return E_OK */
    return ret;

}
#endif


#endif/*#if((STD_ON == CANIF_TRCV_WAKEUP_SUPPORT) || (STD_ON == CANIF_CTRL_WAKEUP_SUPPORT))*/


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: CanIf_GetTxConfirmationState  SWS_CANIF_00734
*
* Description:   This service reports, if any TX confirmation has been done for the whole CAN
*                controller since the last CAN controller start
*
* Inputs:        WakeupSource
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
#if(STD_ON == CANIF_PUBLIC_TXCONFIRM_POLLING_SUPPORT)/*SWS_CANIF_00738*/
FUNC(CanIf_NotifStatusType, CANIF_CODE) CanIf_GetTxConfirmationState
(
    uint8 ControllerId
)
{
    CanIf_NotifStatusType ret = CANIF_NO_NOTIFICATION;


    /*SWS_CANIF_00736 737*/
    if(STD_INITIALIZED != CanIf_InitStatus)
    {
        CANIF_DET_REPORT_ERROR(CANIF_GETTXCONFSTATE_APIID, CANIF_E_UNINIT);
    }
    else if(ControllerId >= CANIF_USED_CONTROLLER_NUM)
    {
        CANIF_DET_REPORT_ERROR(CANIF_GETTXCONFSTATE_APIID, CANIF_E_PARAM_CONTROLLERID);
    }
    else
    {
        ret = CanIf_TxConfStatus[CANIF_CONTROLLER_ID];
    }


    return ret;
}
#endif



#if(STD_ON == CANIF_PUBLIC_PN_SUPPORT)/*SWS_CANIF_00771 813*/
#if(CANIF_MAX_TRCV_NUM > 0)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: CanIf_ClearTrcvWufFlag  SWS_CANIF_00760
*
* Description:   This service clear the wakeup flag of trcv
*
* Inputs:        TransceiverId
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, CANIF_CODE) CanIf_ClearTrcvWufFlag
(
    uint8 TransceiverId
)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 drvIndex = 0;
    uint8 conIndex = 0;

    /*SWS_CANIF_00769*/
    if(STD_INITIALIZED != CanIf_InitStatus)
    {
        CANIF_DET_REPORT_ERROR(CANIF_CLEARTRCVWAKEUPFLAG_APIID, CANIF_E_UNINIT);
    }
    else if(TransceiverId >= CANIF_USED_TRCV_NUM)
    {
        CANIF_DET_REPORT_ERROR(CANIF_CLEARTRCVWAKEUPFLAG_APIID, CANIF_E_PARAM_TRCV);
    }
    else
    {
        drvIndex = CanIf_GetDrvIdOfTrcv(TransceiverId);
        conIndex = CanIf_GetTrcvId(TransceiverId);
        if(NULL_PTR == CanIf_CanTrcv_ClearWakeupFlag[CanIf_GetDrvIdOfTrcv(TransceiverId)])
        {
            CANIF_DET_REPORT_ERROR(CANIF_CLEARTRCVWAKEUPFLAG_APIID, CANIF_E_LINKAPINULL);
        }
        else
        {
            /*SWS_CANIF_00766*/
            ret = CanIf_CanTrcv_ClearWakeupFlag[drvIndex](conIndex);
        }

    }

    return ret;


}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: CanIf_CheckTrcvWakeFlag  SWS_CANIF_00761
*
* Description:   This service check the wakeup flag of trcv
*
* Inputs:        TransceiverId
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, CANIF_CODE) CanIf_CheckTrcvWakeFlag
(
    uint8 TransceiverId
)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 drvIndex = 0;
    uint8 conIndex = 0;

    /*SWS_CANIF_00770*/
    if(STD_INITIALIZED != CanIf_InitStatus)
    {
        CANIF_DET_REPORT_ERROR(CANIF_CHECKTRCVWAKEUPFLAG_APIID, CANIF_E_UNINIT);
    }
    else if(TransceiverId >= CANIF_USED_TRCV_NUM)
    {
        CANIF_DET_REPORT_ERROR(CANIF_CHECKTRCVWAKEUPFLAG_APIID, CANIF_E_PARAM_TRCV);
    }
    else
    {
        drvIndex = CanIf_GetDrvIdOfTrcv(TransceiverId);
        conIndex = CanIf_GetTrcvId(TransceiverId);
        if(NULL_PTR == CanIf_CanTrcv_CheckWakeupFlag[CanIf_GetDrvIdOfTrcv(TransceiverId)])
        {
            CANIF_DET_REPORT_ERROR(CANIF_CHECKTRCVWAKEUPFLAG_APIID, CANIF_E_LINKAPINULL);
        }
        else
        {
            /*SWS_CANIF_00765*/
            ret = CanIf_CanTrcv_CheckWakeupFlag[drvIndex](conIndex);
        }

    }

    return ret;
}
#endif
#endif/*#if(STD_ON == CANIF_PUBLIC_PN_SUPPORT)*/


#if(STD_ON == CANIF_SET_BAUDRATE_API)/*SWS_CANIF_00871*/
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: CanIf_SetBaudrate  SWS_CANIF_00867
*
* Description:   This service change the baudrate
*
* Inputs:        ControllerId, Baudrate
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, CANIF_CODE) CanIf_SetBaudrate
(
    uint8 ControllerId,
    const uint16 BaudRateConfigID
)
{
    uint8 drvIndex = (uint8)0;
    uint8 conIndex = ControllerId;
    Std_ReturnType ret = E_NOT_OK;


    /*SWS_CANIF_00869  SWS_CANIF_00870*/
    if(STD_INITIALIZED != CanIf_InitStatus)
    {
        CANIF_DET_REPORT_ERROR(CANIF_SETBAUDRATE_APIID, CANIF_E_UNINIT);
    }
    else if(ControllerId >= CANIF_USED_CONTROLLER_NUM)
    {
        CANIF_DET_REPORT_ERROR(CANIF_SETBAUDRATE_APIID, CANIF_E_PARAM_CONTROLLERID);
    }
    else
    {
#if(STD_ON == CANIF_PUBLIC_MULTIPLE_DRV_SUPPORT)
        drvIndex = CanIf_CtrlCfg[CANIF_CONTROLLER_ID].CanDrvIndex;
        conIndex = CanIf_CtrlCfg[CANIF_CONTROLLER_ID].CanCtrlIdRef;
#endif
        if(NULL_PTR == CanIf_Can_ChangeBaudrate[drvIndex])
        {
            CANIF_DET_REPORT_ERROR(CANIF_SETBAUDRATE_APIID, CANIF_E_LINKAPINULL);
        }
        else
        {
            /*SWS_CANIF_00868*/
            ret = CanIf_Can_ChangeBaudrate[drvIndex](conIndex, BaudRateConfigID);
        }

    }

    return ret;


}

#endif/*#if(STD_ON == CANIF_SET_BAUDRATE_API)*/

/*******************************************************************************
*   Callback Functions
*******************************************************************************/

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: CanIf_TxConfirmation SWS_CANIF_00007
*
* Description:   This service confirms a previously successfully processed
*                transmission of a CAN TxPDU.
*
* Inputs:        CanTxPduId   L-PDU handle of CAN L-PDU to be transmitted.
*                             This handle specifies the corresponding CAN L-PDU
*                             ID and implicitly the CAN Driver instance as well
*                             as the corresponding CAN controller device.
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, CANIF_CODE) CanIf_TxConfirmation
(
    PduIdType CanTxPduId
)
{
#if((CANIF_CONFIG_VARIANTS != STD_CONFIG_VARIANTS_PRECOMPILE) || (CANIF_MAX_CONTROLLER_NUM > 1))
    uint8 ControllerId;
#endif
    CanIf_User_TxConfirmationType TxConfFctPtr = NULL_PTR;
    CanIf_PduModeType tempMode;
#if((STD_ON == CANIF_PUBLIC_TX_BUFFERING) && (CANIF_MAX_TXBUF_NUM > 0) && (CANIF_MAX_HTH_NUM > 0))
    PduIdType handle;
    Can_HwHandleType hth;
    CanIf_CanWriteType canWriteFctPtr;
#endif


    /*SWS_CANIF_00410 412 413*/
    if(STD_INITIALIZED != CanIf_InitStatus)
    {
        CANIF_DET_REPORT_ERROR(CANIF_TXCONFIRMATION_APIID, CANIF_E_UNINIT);
    }
    else if(CanTxPduId >= CANIF_USED_TXPDU_NUM)
    {
        CANIF_DET_REPORT_ERROR(CANIF_TXCONFIRMATION_APIID, CANIF_E_INVALID_TXPDUID);
    }
    else
    {
#if(CANIF_MAX_TXPDU_NUM > 0)
#if((CANIF_CONFIG_VARIANTS != STD_CONFIG_VARIANTS_PRECOMPILE) || (CANIF_MAX_CONTROLLER_NUM > 1))
        ControllerId = CanIf_CtrlIdOfTxPdu(CanTxPduId);
#endif
        tempMode = CanIf_PduMode[CANIF_CONTROLLER_ID];

#if(STD_ON == CANIF_PUBLIC_PN_SUPPORT)
        CanIf_PnActive[CANIF_CONTROLLER_ID] = FALSE/*SWS_CANIF_00751*/;
#endif

        /* only process when controller is start and pdumode is txConfEnabled SWS_CANIF_00073 */
        if((CANIF_CS_STARTED == CanIf_ControllerMode[CANIF_CONTROLLER_ID])
                && ((CANIF_ONLINE == tempMode) || (CANIF_TX_OFFLINE_ACTIVE == tempMode)))/*SWS_CANIF_00489*/

        {

            /*SWS_CANIF_391 472*/
#if(STD_ON == CANIF_PUBLIC_READTXPDU_NOTIFY_STATUS_API)
#if(CANIF_MAX_TXNOTIFY_NUM > 0)
            if(TRUE == CANIF_TXPDU_CFG_INFO[CanTxPduId].TxPduReadNotifyStatus)
            {
                CanIf_TxNotifStatus[CANIF_TXPDU_CFG_INFO[CanTxPduId].TxNotifyIndex] = CANIF_TX_RX_NOTIFICATION;
            }
#endif
#endif

#if(STD_ON == CANIF_PUBLIC_TXCONFIRM_POLLING_SUPPORT)  /*SWS_CANIF_740*/
            CanIf_TxConfStatus[CANIF_CONTROLLER_ID] = CANIF_TX_RX_NOTIFICATION;
#endif

#if(STD_ON == CANIF_PRIVATE_SWTXFIFO_SUPPORT)
            CanIf_TxSwFifo_TxConfirmation(CanTxPduId);
#endif
            /* SWS_CANIF_383  SWS_CANIF_00414 notify uplayer*/
            /*not report det error here if txconf null */
            TxConfFctPtr = CanIf_TxConfirmationName[CANIF_TXPDU_CFG_INFO[CanTxPduId].TxConfirmation];
            if(NULL_PTR != TxConfFctPtr)
            {
                TxConfFctPtr(CANIF_TXPDU_CFG_INFO[CanTxPduId].PduRef);
            }

#if((STD_ON == CANIF_PUBLIC_TX_BUFFERING) && (CANIF_MAX_TXBUF_NUM > 0) && (CANIF_MAX_HTH_NUM > 0))
            /*SWS_CANIF_386 SWS_CANIF_668: CanIf will check the buffer of this hth, if there is pdu pending
                                 new transmit will be request
            */
            SchM_Enter_CanIf_CANIF_EXCLUSIVE_AREA_1();
            if((FALSE == CanIf_HthTypeOfTxPdu(CanTxPduId)) && (CanIf_SizeOfTxBuf(CanTxPduId) > (PduIdType)0))
            {
                hth = CANIF_TXPDU_CFG_INFO[CanTxPduId].HthRef;
                /* buffered pdu must have same driver index and hth*/
                canWriteFctPtr = CanIf_Can_Write[CanIf_GetDrvIdOfTxPdu(CanTxPduId)];
                if((PduIdType)0 != CanIf_TxBufferFillCount[hth])
                {
                    /* search for buffering tx request
                       SWS_CANIF_070:the pdu will be ordered by its canid in config time
                    */
                    for(handle = CanIf_FirstIndexOfTxBuf(CanTxPduId);
                            handle < (CanIf_SizeOfTxBuf(CanTxPduId) + CanIf_FirstIndexOfTxBuf(CanTxPduId));
                            handle++)
                    {
                        if(TRUE == CanIf_TxBufActiveFlag[handle])
                        {
                            if(NULL_PTR == canWriteFctPtr)
                            {
                                CANIF_DET_REPORT_ERROR(CANIF_TXCONFIRMATION_APIID, CANIF_E_LINKAPINULL);
                            }
                            else
                            {
                                if(CAN_OK == canWriteFctPtr(CANIF_HTH_CFG_INFO[hth].HthIdSymRef, &CanIf_TxBufPdu[handle]))
                                {
                                    /*SWS_CANIF_183: txOK, the pengding pdu is removed*/
                                    CanIf_TxBufActiveFlag[handle] = FALSE;
                                    CanIf_TxBufferFillCount[hth]--;
                                }
                            }
                            break;
                        }
                    }
                }
            }
            SchM_Exit_CanIf_CANIF_EXCLUSIVE_AREA_1();
#endif/*#if((STD_ON == CANIF_PUBLIC_TX_BUFFERING) && (CANIF_MAX_TXBUF_NUM > 0) && (CANIF_MAX_HTH_NUM > 0))*/

        }
#endif/*#if(CANIF_MAX_TXPDU_NUM > 0)*/

    }
}



#if(CANIF_MAX_RXPDU_NUM > 0)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: CanIf_GetRxPduId
*
* Description:   This service implement sw filter
*
* Inputs:        ControllerId,Hrh,CanId
*
* Outputs:       PduIdType
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(PduIdType, CANIF_CODE) CanIf_GetRxPduId
(
    uint8 ControllerId,
    Can_HwHandleType Hrh,
    Can_IdType CanId
)
{
    PduIdType  PduIndex;
    PduIdType  PduIndexResult = COMSTACK_INVALID_PDUID;
    Can_IdType mask;
    Can_IdType tempCanId;


    /*******************************************************************************
    * PRQA S 0771  MISRA-C:2004 Rule 14.6
    * More than one break statement is being used to terminate an iteration statement.
    * 2 kind of filter path both need to break.
    * This part of code is verified manually and has no impact.
    *******************************************************************************/


#if(CANIF_FILTER_TYPE_INDEX == CANIF_PRIVATE_SOFTWARE_FILTER_TYPE)
    for(PduIndex = CANIF_HRH_CFG_INFO[Hrh].FirstRxPduIdInHrh;
        PduIndex != COMSTACK_INVALID_PDUID;
        PduIndex = CANIF_RXPDU_CFG_INFO[PduIndex].NextPduId)
    {
        if(Hrh == CANIF_RXPDU_CFG_INFO[PduIndex].HrhRef)
        {
#elif(CANIF_FILTER_TYPE_LINEAR == CANIF_PRIVATE_SOFTWARE_FILTER_TYPE)
    for(PduIndex = 0; PduIndex < CANIF_USED_RXPDU_NUM; PduIndex++)
    {
        if(Hrh == CANIF_RXPDU_CFG_INFO[PduIndex].HrhRef)
        {
#endif
#if(CANIF_FILTER_TYPE_TABLE == CANIF_PRIVATE_SOFTWARE_FILTER_TYPE)
    if(CanId <= CANIF_MAX_CANID)
    {
        if(NULL_PTR != CANIF_RXPDUTABLE_CFG_INFO[CanId])
        {
            PduIndex = CANIF_RXPDUTABLE_CFG_INFO[CanId][ControllerId];
#endif
#if(STD_ON == CANIF_HRH_RANGE_FILTER_SUPPORT)
            if(NULL_PTR != CANIF_RXPDU_CFG_INFO[PduIndex].IdRange)
            {
                tempCanId = CanId;

#if(STD_ON == CANIF_PRIVATE_CANFD_SUPPORT)
                /*
                    EXTENDED_CAN and STANDARD_CAN type support both fd or non fd
                    in these 2 type, the range id is generated without fd bit
                    so the canid need to remove fd bit before compare with range id
                */
                if((EXTENDED_CAN == CANIF_RXPDU_CFG_INFO[PduIndex].CanIdType)
                        || (STANDARD_CAN == CANIF_RXPDU_CFG_INFO[PduIndex].CanIdType))
                {
                    tempCanId = (CanId & CAN_CANFD_INV_MASK);/*clear Fd Bit*/
                }
#endif

                if((tempCanId >= CANIF_RXPDU_CFG_INFO[PduIndex].IdRange->LowerCanId)
                        && (tempCanId <= CANIF_RXPDU_CFG_INFO[PduIndex].IdRange->UpperCanId))
                {
                    PduIndexResult = PduIndex;
                    break;
                }

            }
            else
#endif
            {
                mask = CANIF_RXPDU_CFG_INFO[PduIndex].CanIdMask;
                if((CanId & mask) == (CANIF_RXPDU_CFG_INFO[PduIndex].CanId & mask))
                {
                    PduIndexResult = PduIndex;
                    break;
                }
            }
        }
    }

    return PduIndexResult;

}


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: CanIf_GetInternalHrh
*
* Description:   This service remap the hrh from can to canif's internal hrh
*
* Inputs:        Hrh
*
* Outputs:       PduIdType
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
#if((STD_OFF == CANIF_PUBLIC_MULTIPLE_DRV_SUPPORT) && (STD_OFF == CANIF_HOH_OPTIMIZE_SUPPORT))
STATIC FUNC(Can_HwHandleType, CANIF_CODE) CanIf_GetInternalHrh
(
    Can_HwHandleType Hrh
)
{
    Can_HwHandleType HrhResult = CAN_INVALID_HOH;
    Can_HwHandleType i;

    for(i = (Can_HwHandleType)0; i < CANIF_USED_HRH_NUM; i++)
    {
        if(CANIF_HRH_CFG_INFO[i].HrhIdSymRef == Hrh)
        {
            HrhResult = i;
            break;
        }
    }

    return HrhResult;
}
#endif


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: CanIf_GetInternalHrh
*
* Description:   This service remap the hrh from can to canif's internal hrh
*
* Inputs:        Hrh
*
* Outputs:       PduIdType
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
#if(STD_ON == CANIF_PRIVATE_DLC_CHECK)
STATIC FUNC(boolean, CANIF_CODE) CanIf_DlcCheck
(
    P2VAR(uint8, AUTOMATIC, AUTOMATIC)  CanDlc,
    const PduIdType RxPduId
)
{
    boolean dlcValid = TRUE;

    if(TRUE == CANIF_RXPDU_CFG_INFO[RxPduId].needDlcCheck)
    {
#if(CANIF_DLC_CHECK_TYPE == CANIF_DLC_CHECK_AUTOSAR)
        if(*CanDlc < CANIF_RXPDU_CFG_INFO[RxPduId].Length)
        {
            dlcValid = FALSE;
        }
        else
        {
            /* SWS_CANIF_00297 set dlc to config dlc
            when the reveived dlc is bigger than config dlc*/
            *CanDlc = CANIF_RXPDU_CFG_INFO[RxPduId].Length;
        }
#else
        dlcValid = CanIf_DlcCheckCallout(RxPduId, CanDlc, CANIF_RXPDU_CFG_INFO[RxPduId].Length);
#endif

    }
    return dlcValid;
}
#endif
#endif/*#if(CANIF_MAX_RXPDU_NUM > 0)*/

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: CanIf_RxIndication SWS_CANIF_00006
*
* Description:   This service indicates a successful reception of a received CAN
*                Rx L-PDU to the CanIf after passing all filters and validation
*                checks.
*
* Inputs:        Hrh         ID of the corresponding Hardware Object
*                            Range: 0..(total number of HRH -1)
*                CanId       Standard/Extended CAN ID of CAN L-PDU that has been
*                            successfully received
*                CanDlc      Data Length Code (length of CAN L-PDU payload)
*                CanSduPtr   Pointer to received L-SDU (payload)
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, CANIF_CODE) CanIf_RxIndication
(
    P2CONST(Can_HwType, AUTOMATIC, CANIF_APPL_DATA) Mailbox,
    P2CONST(PduInfoType, AUTOMATIC, CANIF_APPL_DATA) PduInfoPtr
)
{
    Can_HwHandleType internalHrh;
#if((CANIF_CONFIG_VARIANTS != STD_CONFIG_VARIANTS_PRECOMPILE) || (CANIF_MAX_CONTROLLER_NUM > 1))
    uint8 ControllerId;
#endif
    CanIf_User_RxIndicationType RxIndFctPtr = NULL_PTR;
    uint8 tempMode;
    PduIdType    canIfRxPduId = COMSTACK_INVALID_PDUID;
    Can_IdType CanId;
    uint8 maxDlc = CAN_MAX_DLC;
    uint8 CanDlc = (uint8)0;
    PduInfoType tempPduInfo;


    /*******************************************************************************
    * PRQA S 0715  MISRA-C:2004 Rule 1.1
    * Nesting of control structures (statements) exceeds 15 - program does not conform
    * strictly to ISO:C90. Sequence of rx process need these  statements.
    * This part of code is verified manually and has no impact.
    *******************************************************************************/

    /*SWS_CANIF_00419 421 422 */
    if(STD_INITIALIZED != CanIf_InitStatus)
    {
        CANIF_DET_REPORT_ERROR(CANIF_RXINDICATION_APIID, CANIF_E_UNINIT);
    }
    else if(NULL_PTR == Mailbox)
    {
        CANIF_DET_REPORT_ERROR(CANIF_RXINDICATION_APIID, CANIF_E_PARAM_POINTER);
    }
    else if(NULL_PTR == PduInfoPtr)
    {
        CANIF_DET_REPORT_ERROR(CANIF_RXINDICATION_APIID, CANIF_E_PARAM_POINTER);
    }
    else if(NULL_PTR == PduInfoPtr->SduDataPtr)
    {
        CANIF_DET_REPORT_ERROR(CANIF_RXINDICATION_APIID, CANIF_E_PARAM_POINTER);
    }
    else
    {
#if(CANIF_MAX_RXPDU_NUM > 0)
        /*SWS_CANIF_00417 not implement: CanId is not checked here */
        CanId = Mailbox->CanId;
        CanDlc = (uint8)PduInfoPtr->SduLength;
        tempPduInfo.SduDataPtr = PduInfoPtr->SduDataPtr;

#if(STD_ON == CANIF_PRIVATE_CANFD_SUPPORT)
        /*max Dlc Check*/
        if(CAN_CANFD_MASK == (Can_IdType)(CanId & CAN_CANFD_MASK))
        {
            maxDlc = CANFD_MAX_DLC;
        }
#endif
        if(CanDlc > maxDlc)
        {
            CANIF_DET_REPORT_ERROR(CANIF_RXINDICATION_APIID, CANIF_E_INVALID_DLC);
        }
        else
        {
            internalHrh = Mailbox->Hoh;
#if(STD_OFF == CANIF_PUBLIC_MULTIPLE_DRV_SUPPORT)
            /* when mutidrv is off, candrv will directly call this rx cbk funtion
               so the hrh will be serach and check here
               when mutidrv is on, this will be done in generate rx cbk functions
            */
#if(STD_OFF == CANIF_HOH_OPTIMIZE_SUPPORT)
            /* HRH check */
            internalHrh = CanIf_GetInternalHrh(Mailbox->Hoh);

            /* when HOH_OPTIMIZE, hrh can be internalHrh directly */

#endif
#endif
            if(internalHrh >= CANIF_USED_HRH_NUM)/*SWS_CANIF_00416*/
            {
                CANIF_DET_REPORT_ERROR(CANIF_RXINDICATION_APIID, CANIF_E_PARAM_HOH);
            }
            else
            {
#if((CANIF_CONFIG_VARIANTS != STD_CONFIG_VARIANTS_PRECOMPILE) || (CANIF_MAX_CONTROLLER_NUM > 1))
                ControllerId = CANIF_HRH_CFG_INFO[internalHrh].CanIfCtrlIdRef;
#endif
                tempMode = (uint8)CanIf_PduMode[CANIF_CONTROLLER_ID];

                if((CANIF_CS_STARTED == CanIf_ControllerMode[CANIF_CONTROLLER_ID])
                        && (tempMode > (uint8)CANIF_TX_OFFLINE_ACTIVE)) /*SWS_CANIF_00073 489*/
                {
                    /* SWS_CANIF_415 417 389 645 646 030
                    software filter process ,dont need to check fullcan feather */
                    canIfRxPduId = CanIf_GetRxPduId(CANIF_CONTROLLER_ID,internalHrh, CanId);
                    if(COMSTACK_INVALID_PDUID == canIfRxPduId)
                    {
                        /*CANIF_DET_REPORT_ERROR(CANIF_RXINDICATION_APIID, CANIF_E_PARAM_CANID);
                          should not report error, as CanId not pass software filter is normally
                        */
                    }
                    else
                    {
#if(STD_ON == CANIF_PRIVATE_DLC_CHECK)/*SWS_CANIF_418 390*/
                        if(FALSE == CanIf_DlcCheck(&CanDlc, canIfRxPduId))/*SWS_CANIF_168 026 829 830*/
                        {
                            CANIF_DET_REPORT_ERROR(CANIF_RXINDICATION_APIID, CANIF_E_INVALID_DLC);
                        }
                        else
#endif
                        {

                            /* wakeup is only valid when correct pdu is received */
#if((STD_ON == CANIF_TRCV_WAKEUP_SUPPORT) || (STD_ON == CANIF_CTRL_WAKEUP_SUPPORT))
#if(STD_ON == CANIF_PUBLIC_WAKEUP_CHECK_VALIDATION_SUPPORT)
#if((STD_ON == CANIF_PUBLIC_WAKEUP_CHECK_VALID_BY_NM)&&(STD_ON == CANIF_PUBLIC_WAKEUP_CHECK_VALID_BY_OSEKNM))
                            if((CANIF_NM_RX_CBK_HANDLE == CANIF_RXPDU_CFG_INFO[canIfRxPduId].RxIndication) \
                                    || (CANIF_OSEKNM_RX_CBK_HANDLE == CANIF_RXPDU_CFG_INFO[canIfRxPduId].RxIndication))
#else
#if(STD_ON == CANIF_PUBLIC_WAKEUP_CHECK_VALID_BY_NM)
                            if(CANIF_NM_RX_CBK_HANDLE == CANIF_RXPDU_CFG_INFO[canIfRxPduId].RxIndication)
#endif
#if(STD_ON == CANIF_PUBLIC_WAKEUP_CHECK_VALID_BY_OSEKNM)
                                if(CANIF_OSEKNM_RX_CBK_HANDLE == CANIF_RXPDU_CFG_INFO[canIfRxPduId].RxIndication)
#endif

#endif
                                /*SWS_CANIF_286 when validByNm is true, set wakeup true only when rx nm msg*/

                            {
#if( STD_ON != CANIF_PUBLIC_WAKEUP_CHECK_VALID_BY_PNNM)
                                CanIf_WakeupStatus[CANIF_CONTROLLER_ID] = TRUE;
#endif                         
                            }
#endif
#endif


                            /* first copy data and notify to buf, then call out to uplayyer
                               as uplayyer may getdata in callout
                            */
#if(STD_ON == CANIF_PUBLIC_READRXPDU_NOTIFY_STATUS_API)
#if(CANIF_MAX_RXNOTIFY_NUM > 0)
                            /*SWS_CANIF_392 473*/
                            if(TRUE == CANIF_RXPDU_CFG_INFO[canIfRxPduId].RxPduReadNotifyStatus)
                            {
                                CanIf_RxNotifStatus[CANIF_RXPDU_CFG_INFO[canIfRxPduId].RxNotifyIndex] = CANIF_TX_RX_NOTIFICATION;
                            }
#endif
#endif

#if(STD_ON == CANIF_PUBLIC_READRXPDU_DATA_API)/*SWS_CANIF_198*/
#if(CANIF_MAX_RXBUF_NUM > 0)
                            /*SWS_CANIF_297 why copy config dlc here? */
                            if(TRUE == CANIF_RXPDU_CFG_INFO[canIfRxPduId].RxPduReadData)
                            {
                                SchM_Enter_CanIf_CANIF_EXCLUSIVE_AREA_3();/*SWS_CANIF_199*/
                                Bsw_MemCpy(CANIF_RXPDU_CFG_INFO[canIfRxPduId].dataBuf,
                                           tempPduInfo.SduDataPtr, (uint32)CanDlc);
                                CanIf_RxBufferSduLength[CANIF_RXPDU_CFG_INFO[canIfRxPduId].RxBufIndex] = CanDlc;
                                SchM_Exit_CanIf_CANIF_EXCLUSIVE_AREA_3();
                            }
#endif
#endif
                            tempPduInfo.SduLength = CanDlc;/* dlc may change to config dlc.*/
                            /*SWS_CANIF_056 135*/
#if(STD_ON == CANIF_OSEKNM_SUPPORT)
                            if(CANIF_RXPDU_CFG_INFO[canIfRxPduId].RxIndication == 0xFF)
                            {
                                OsekNm_RxIndication(CANIF_RXPDU_CFG_INFO[canIfRxPduId].PduRef, \
                                                    ((Mailbox->CanId)&CAN_CANFD_INV_MASK), \
                                                    &tempPduInfo);
                            }
                            else
#endif
                            {
                                RxIndFctPtr = CanIf_RxIndicationName[CANIF_RXPDU_CFG_INFO[canIfRxPduId].RxIndication];
                                if(NULL_PTR != RxIndFctPtr)
                                {
                                    /*SWS_CANIF_423 SWS_CANIF_00415*/
                                    RxIndFctPtr(CANIF_RXPDU_CFG_INFO[canIfRxPduId].PduRef, &tempPduInfo);
                                }
                            }
                        }


                    }
                }

            }

        }
#endif/*#if(CANIF_MAX_RXPDU_NUM > 0)*/
    }

}



/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: CanIf_ControllerBusOff  SWS_CANIF_00218
*
* Description:   This service indicates a Controller BusOff event referring to
*                the corresponding CAN Controller.
*
*
* Inputs:        Controller   CAN controller, where a BusOff occured
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, CANIF_CODE) CanIf_ControllerBusOff
(
    uint8 ControllerId
)
{

    /* SWS_CANIF_00429 431 432*/
    if(STD_INITIALIZED != CanIf_InitStatus)
    {
        CANIF_DET_REPORT_ERROR(CANIF_CONTROLLERBUSOFF_APIID, CANIF_E_UNINIT);
    }
    else if(ControllerId >= CANIF_USED_CONTROLLER_NUM)
    {
        CANIF_DET_REPORT_ERROR(CANIF_CONTROLLERBUSOFF_APIID, CANIF_E_PARAM_CONTROLLER);
    }
    else
    {
#if(STD_ON == CANIF_PUBLIC_TX_BUFFERING)/*SWS_CANIF_485*/
        CanIf_ClearTransmitBuffer((uint8)CANIF_CONTROLLER_ID);
#endif


#if(STD_ON == CANIF_PUBLIC_TXCONFIRM_POLLING_SUPPORT)
        /*SWS_CANIF_739*/
        CanIf_TxConfStatus[CANIF_CONTROLLER_ID] = CANIF_NO_NOTIFICATION;
#endif
        /*SWS_CANIF_298 488 866*/
        CanIf_ControllerMode[CANIF_CONTROLLER_ID] = CANIF_CS_STOPPED;
        CanIf_PduMode[CANIF_CONTROLLER_ID] = CANIF_TX_OFFLINE;

        /*******************************************************************
        * PRQA S 3138   MISRA-C:2004 Rule 14.3
        * PRQA S 3141
        * If not configed by user,CANIF_USERCTRLBUSOFF_FUN is Null.
        * This part of code is verified manually and has no impact.
        *******************************************************************/
        /* Call uplayyer handle */

#if(CANIF_CONFIG_VARIANTS != STD_CONFIG_VARIANTS_PRECOMPILE)
        if(NULL_PTR != CanIf_DispatchUserCtrlModeIndicationName)
#endif
        {
            CANIF_DISPATCH_USERCTRLBUSOFF_NAME; /*SWS_CANIF_724*/
        }

    }
}


#if(CANIF_PUBLIC_PN_SUPPORT == STD_ON)/* SWS_CANIF_00754 808 812*/
#if(CANIF_MAX_TRCV_NUM > 0)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: CanIf_ConfirmPnAvailability  SWS_CANIF_00815
*
* Description:   This service indicates that the transceiver is running in PN communication mode.
*
* Inputs:        Transceiver
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, CANIF_CODE) CanIf_ConfirmPnAvailability
(
    uint8 TransceiverId
)
{

    /* SWS_CANIF_00816 817 818 */
    if(STD_INITIALIZED != CanIf_InitStatus)
    {
        CANIF_DET_REPORT_ERROR(CANIF_CONFPNACTIVE_APIID, CANIF_E_UNINIT);
    }
    else if(TransceiverId >= CANIF_USED_TRCV_NUM)
    {
        CANIF_DET_REPORT_ERROR(CANIF_CONFPNACTIVE_APIID, CANIF_E_PARAM_TRCV);
    }
    else
    {

#if(CANIF_CONFIG_VARIANTS != STD_CONFIG_VARIANTS_PRECOMPILE)
        if(NULL_PTR != CanIfDispatchUserConfirmPnAvailabilityName)
#endif
        {
            /*SWS_CANIF_00753*/
            CANIF_DISPATCH_USERCONFIRMPNAVAILABILITY_NAME;
        }
    }

}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: CanIf_ClearTrcvWufFlagIndication  SWS_CANIF_00762
*
* Description:   This service indicates that the transceiver has cleared the WufFlag.
*
* Inputs:        Transceiver
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, CANIF_CODE) CanIf_ClearTrcvWufFlagIndication
(
    uint8 TransceiverId
)
{

    /* SWS_CANIF_00806 807 805*/
    if(STD_INITIALIZED != CanIf_InitStatus)
    {
        CANIF_DET_REPORT_ERROR(CANIF_CLEARTRCVWUFFIND_APIID, CANIF_E_UNINIT);
    }
    else if(TransceiverId >= CANIF_USED_TRCV_NUM)
    {
        CANIF_DET_REPORT_ERROR(CANIF_CLEARTRCVWUFFIND_APIID, CANIF_E_PARAM_TRCV);
    }
    else
    {
#if(CANIF_CONFIG_VARIANTS != STD_CONFIG_VARIANTS_PRECOMPILE)
        if(NULL_PTR != CanIfDispatchUserClearTrcvWufFlagIndicationName)
#endif
        {
            CANIF_DISPATCH_USERCLEARTRCVWUFFLAGINDICATION_NAME;/*SWS_CANIF_00757*/
        }


    }

}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: CanIf_CheckTrcvWakeFlagIndication  SWS_CANIF_00763
*
* Description:   This service indicates the reason for the wake up that the CAN
*                transceiver has detected.
*
* Inputs:        Transceiver
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, CANIF_CODE) CanIf_CheckTrcvWakeFlagIndication
(
    uint8 TransceiverId
)
{

    /* SWS_CANIF_00810 811 */
    if(STD_INITIALIZED != CanIf_InitStatus)
    {
        CANIF_DET_REPORT_ERROR(CANIF_CHECKTRCVWUFFIND_APIID, CANIF_E_UNINIT);
    }
    else if(TransceiverId >= CANIF_USED_TRCV_NUM)
    {
        CANIF_DET_REPORT_ERROR(CANIF_CHECKTRCVWUFFIND_APIID, CANIF_E_PARAM_TRCV);
    }
    else
    {
#if(CANIF_CONFIG_VARIANTS != STD_CONFIG_VARIANTS_PRECOMPILE)
        if(NULL_PTR != CanIfDispatchUserCheckTrcvWakeFlagIndicationName)
#endif
        {
            /*SWS_CANIF_00759*/
            CANIF_DISPATCH_USERCHECKTRCVWAKEFLAGINDICATION_NAME;
        }
    }
}
#endif/*#if(CANIF_MAX_TRCV_NUM > 0)*/
#endif/*#if(CANIF_PUBLIC_PN_SUPPORT == STD_ON)*/


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: CanIf_ControllerModeIndication  SWS_CANIF_00699]
*
* Description:   This service indicates a Controller state transition event
*                referring to the corresponding CAN Controller.
*
* Inputs:        ControllerId:CAN controller, which state has been transitioned.
*                ControllerMode:  Mode to which the CAN controller transitioned
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, CANIF_CODE) CanIf_ControllerModeIndication
(
    uint8 ControllerId,
    CanIf_ControllerModeType ControllerMode
)
{
    /* SWS_CANIF_00700 702 703 */
    if(STD_INITIALIZED != CanIf_InitStatus)
    {
        CANIF_DET_REPORT_ERROR(CANIF_CONTROLLERMODEINDICATION_APIID, CANIF_E_UNINIT);
    }
    else if(ControllerId >= CANIF_USED_CONTROLLER_NUM)
    {
        CANIF_DET_REPORT_ERROR(CANIF_CONTROLLERMODEINDICATION_APIID, CANIF_E_PARAM_CONTROLLERID);
    }
    else if((ControllerMode != CANIF_CS_STARTED)
            && (ControllerMode != CANIF_CS_SLEEP)
            && (ControllerMode != CANIF_CS_STOPPED))
    {
        CANIF_DET_REPORT_ERROR(CANIF_CONTROLLERMODEINDICATION_APIID, CANIF_E_PARAM_CTRLMODE);
    }
    else if((ControllerMode == CANIF_CS_STARTED)
            && (CANIF_CS_SLEEP == CanIf_ControllerMode[CANIF_CONTROLLER_ID]))
    {
        /* not allow start <-> sleep */
        CANIF_DET_REPORT_ERROR(CANIF_CONTROLLERMODEINDICATION_APIID, CANIF_E_PARAM_CTRLMODE);
    }
    else if((ControllerMode == CANIF_CS_SLEEP)
            && (CANIF_CS_STARTED == CanIf_ControllerMode[CANIF_CONTROLLER_ID]))
    {
        /* not allow start <-> sleep */
        CANIF_DET_REPORT_ERROR(CANIF_CONTROLLERMODEINDICATION_APIID, CANIF_E_PARAM_CTRLMODE);
    }
    else
    {
        /*SWS_CANIF_713 714 715 CANIF716 CANIF717 CANIF718 CANIF719*/
        CanIf_ControllerMode[CANIF_CONTROLLER_ID] = ControllerMode;


        if(CANIF_CS_STOPPED == ControllerMode)
        {
            /* clear tx buf SWS_CANIF_485*/
#if(STD_ON == CANIF_PUBLIC_TX_BUFFERING)
            CanIf_ClearTransmitBuffer((uint8)CANIF_CONTROLLER_ID);
#endif
#if(STD_ON == CANIF_PUBLIC_TXCONFIRM_POLLING_SUPPORT)
            CanIf_TxConfStatus[CANIF_CONTROLLER_ID] = CANIF_NO_NOTIFICATION;
#endif

            /* no need tp clear TxRxNotifStatus, since if there is TxRxNotify active,
               it should be keeped until uplayyer read it
            */

            /* PduMode no need to change */
        }

#if((STD_ON == CANIF_TRCV_WAKEUP_SUPPORT) || (STD_ON == CANIF_CTRL_WAKEUP_SUPPORT))
#if(STD_ON == CANIF_PUBLIC_WAKEUP_CHECK_VALIDATION_SUPPORT)
        if(CANIF_CS_SLEEP == ControllerMode)
        {
            CanIf_WakeupStatus[CANIF_CONTROLLER_ID] = FALSE;/*SWS_CANIF_756*/
        }
#endif
#endif

        /* Call uplayyer handle SWS_CANIF_711*/
#if(CANIF_CONFIG_VARIANTS != STD_CONFIG_VARIANTS_PRECOMPILE)
        if(NULL_PTR != CanIf_DispatchUserCtrlModeIndicationName)
#endif
        {
            CANIF_DISPATCH_USERCTRLMODEINDICATION_NAME;
        }


    }

}


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: CanIf_TrcvModeIndication  SWS_CANIF_00764
*
* Description:   This service indicates a transceive sition re r state tran ferring
*                to the corresponding CAN transceiver.
*
* Inputs:        Transceiver,TransceiverMode
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
#if(CANIF_MAX_TRCV_NUM > 0) /*SWS_CANIF_00730*/
FUNC(void, CANIF_CODE) CanIf_TrcvModeIndication
(
    uint8 TransceiverId,
    CanTrcv_TrcvModeType TransceiverMode
)
{
    /* CSWS_CANIF_00706 708 709 */
    if(STD_INITIALIZED != CanIf_InitStatus)
    {
        CANIF_DET_REPORT_ERROR(CANIF_TRCVMODEIND_APIID, CANIF_E_UNINIT);
    }
    else if(TransceiverId >= CANIF_USED_TRCV_NUM)
    {
        CANIF_DET_REPORT_ERROR(CANIF_TRCVMODEIND_APIID, CANIF_E_PARAM_TRCV);
    }
    else
    {
        /*SWS_CANIF_712*/
#if(CANIF_CONFIG_VARIANTS != STD_CONFIG_VARIANTS_PRECOMPILE)
        if(NULL_PTR != CanIf_DispatchUserTrcvModeIndicationName)
#endif
        {
            CANIF_DISPATCH_USERTRCVMODEINDICATION_NAME;
        }

    }

}
#endif


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: CanIf_SetIcomConfiguration  SWS_CANIF_00861
*
* Description:   This service will call Can Driver's api, to change the icom configration
*
* Inputs:        ControllerId,ConfigurationId
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
#if(STD_ON ==  CANIF_PUBLIC_ICOM_SUPPORT) /*SWS_CANIF_00875*/
FUNC(Std_ReturnType, CANIF_CODE) CanIf_SetIcomConfiguration
(
    uint8 ControllerId,
    IcomConfigIdType ConfigurationId
)
{
    Std_ReturnType ret = E_NOT_OK;
    CanIf_CanSetIComConfigrationType canSetIcomFctPtr;

    /*SWS_CANIF_00872*/
    if(STD_INITIALIZED != CanIf_InitStatus)
    {
        CANIF_DET_REPORT_ERROR(CANIF_SETICOM_APIID, CANIF_E_UNINIT);
    }
    else if(ControllerId >= CANIF_USED_CONTROLLER_NUM)
    {
        CANIF_DET_REPORT_ERROR(CANIF_SETICOM_APIID, CANIF_E_PARAM_CONTROLLERID);
    }
    else
    {
        canSetIcomFctPtr = CanIf_Can_SetIComConfigration[CanIf_GetDrvIdOfCtrl(CANIF_CONTROLLER_ID)];
        if(NULL_PTR == canSetIcomFctPtr)
        {
            CANIF_DET_REPORT_ERROR(CANIF_SETICOM_APIID, CANIF_E_LINKAPINULL);
        }
        else
        {
            ret = canSetIcomFctPtr(CanIf_GetCtrlId((uint8)CANIF_CONTROLLER_ID), ConfigurationId);/*SWS_CANIF_00838*/
        }

    }

    return ret;

}
#endif



/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: CanIf_TriggerTransmit  SWS_CANIF_00883
*
* Description:   This service is called by CanWrite, to trigger the Tx data from uplayyer
*
* Inputs:        TxPduId,PduInfoPtr
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
#if(STD_ON ==  CANIF_TRIGGER_TRANSMIT_SUPPORT) /*SWS_CANIF_00884*/
#if(CANIF_MAX_TXTRIGGER_NUM > 0)
FUNC(Std_ReturnType, CANIF_CODE) CanIf_TriggerTransmit
(
    PduIdType TxPduId,
    P2VAR(PduInfoType, AUTOMATIC, CANIF_APPL_DATA) PduInfoPtr
)
{

    Std_ReturnType ret = E_NOT_OK;
    CanIf_User_TriggerTransmitType  TriggerTxFun = NULL_PTR;

    if(STD_INITIALIZED != CanIf_InitStatus)
    {
        CANIF_DET_REPORT_ERROR(CANIF_TRIGGER_TRANSMIT_APIID, CANIF_E_UNINIT);
    }
    else if((TxPduId >= CANIF_USED_TXPDU_NUM) || (FALSE == CANIF_TXPDU_CFG_INFO[TxPduId].isTriggerPdu))
    {
        CANIF_DET_REPORT_ERROR(CANIF_TRIGGER_TRANSMIT_APIID, CANIF_E_INVALID_TXPDUID);
    }
    else if(NULL_PTR == PduInfoPtr)
    {
        CANIF_DET_REPORT_ERROR(CANIF_TRIGGER_TRANSMIT_APIID, CANIF_E_PARAM_POINTER);
    }
    else
    {

        TriggerTxFun = CanIf_TxTriggerName[CANIF_TXPDU_CFG_INFO[TxPduId].TriggerTransmit];
        if(NULL_PTR != TriggerTxFun)
        {
            ret = TriggerTxFun(CANIF_TXPDU_CFG_INFO[TxPduId].PduRef, PduInfoPtr);/*SWS_CANIF_00885*/
        }

    }

    return ret;

}
#endif
#endif

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: CanIf_CurrentIcomConfiguration  SWS_CANIF_00862
*
* Description:   This service is called when CanDrv finish the new ICom set
*
* Inputs:        TxPduId,PduInfoPtr
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
#if(STD_ON ==  CANIF_PUBLIC_ICOM_SUPPORT) /*SWS_CANIF_00876*/
FUNC(void, CANIF_CODE) CanIf_CurrentIcomConfiguration
(
    uint8 ControllerId,
    IcomConfigIdType ConfigurationId,
    IcomSwitch_ErrorType Error
)
{

    /*SWS_CANIF_00873*/
    if(STD_INITIALIZED != CanIf_InitStatus)
    {
        CANIF_DET_REPORT_ERROR(CANIF_CURRENTICOM_APIID, CANIF_E_UNINIT);
    }
    else if(ControllerId >= CANIF_USED_CONTROLLER_NUM)
    {
        CANIF_DET_REPORT_ERROR(CANIF_CURRENTICOM_APIID, CANIF_E_PARAM_CONTROLLERID);
    }
    else
    {
#if(CANIF_CONFIG_VARIANTS != STD_CONFIG_VARIANTS_PRECOMPILE)
        if(NULL_PTR != CanIf_DispatchUserCurrentIcomConfigurationName)
#endif
        {
            CANIF_DISPATCH_CURRENTICOM_NAME;  /*SWS_CANIF_00839*/
        }

    }

}
#endif

#if(STD_ON == CANIF_PUBLIC_TX_BUFFERING)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: CanIf_ClearTransmitBuffer
*
* Description:   Clear the  CanIfTxBufferPDUFillflag of CanTxPdu which
*                belong to the specific  controller
* Inputs:        ControllerId : controller which wanted to clear the buffer
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, CANIF_CODE)  CanIf_ClearTransmitBuffer
(
    const uint8 ControllerId
)
{
#if((CANIF_MAX_TXBUF_NUM > 0) && (CANIF_MAX_HTH_NUM > 0))
    Can_HwHandleType HthCnt;
    PduIdType BufIndex;
    /* search all hth of this controller ,clear buffer*/
    for(HthCnt = (Can_HwHandleType)0; HthCnt < CANIF_USED_HTH_NUM; HthCnt++)
    {
        if(CANIF_HTH_CFG_INFO[HthCnt].CanIfCtrlIdRef == ControllerId)
        {
            CanIf_TxBufferFillCount[HthCnt] = (PduIdType)0;
            if(CANIF_HTH_CFG_INFO[HthCnt].TxBufSize > (Can_HwHandleType)0)
            {
                for(BufIndex = CANIF_HTH_CFG_INFO[HthCnt].FirstBufIndexHth;
                        BufIndex < (CANIF_HTH_CFG_INFO[HthCnt].FirstBufIndexHth + CANIF_HTH_CFG_INFO[HthCnt].TxBufSize);
                        BufIndex++)
                {
                    CanIf_TxBufActiveFlag[BufIndex] = FALSE;
                    CanIf_TxBufPdu[BufIndex].id = (Can_IdType)0;
                    CanIf_TxBufPdu[BufIndex].length = (uint8)0;
                    CanIf_TxBufPdu[BufIndex].swPduHandle = COMSTACK_INVALID_PDUID;
                    CanIf_TxBufPdu[BufIndex].sdu = NULL_PTR;
                    /* dont need to set buffer data to 0 */
                }

            }
        }
    }
#endif
}
#endif

#if( STD_ON == CANIF_PUBLIC_WAKEUP_CHECK_VALID_BY_PNNM)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: CanIf_SetWakeupStatus
*
* Description:   Set wakeup status.
* Inputs:        ControllerId : controller which wanted to set wakeup status.
*                WakeupStatus : wakeup status.
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, CANIF_CODE) CanIf_SetWakeupStatus
(
    uint8 ControllerId,
    const boolean WakeupStatus
)
{
    CanIf_WakeupStatus[ControllerId] = WakeupStatus;
}
#endif

#if((CANIF_PRIVATE_SWTXFIFO_RETRY == STD_ON) && (CANIF_PRIVATE_SWTXFIFO_SUPPORT == STD_ON))
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: CanIf_MainFunction
*
* Description:   Operation of FIFO in tasks of the main loop.
*
* Inputs:        None
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, CANIF_CODE) CanIf_MainFunction
(
    void
)
{
	if(STD_INITIALIZED != CanIf_InitStatus)
    {
        CANIF_DET_REPORT_ERROR(CANIF_TXFIFOMAIN_APIID, CANIF_E_UNINIT);
    }
    else
    {
    	CanIf_TxSwFifo_MainFunction();
    }

}
#endif



#define CANIF_STOP_SEC_CODE
#include "MemMap.h"

