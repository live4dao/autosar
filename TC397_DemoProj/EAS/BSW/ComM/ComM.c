/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
*   File Name       : ComM.c
********************************************************************************
*   Project/Product : AUTOSAR 4.2
*   Title           : ComM.c
*   Author          : Hirain
********************************************************************************
*   Description     : Implementation of ComM provided functionality
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
*   01.00.00    11/10/2016    Boxue.Li      N/A          Beta
*   01.01.00    26/06/2018    Boxue.Li      N/A          Original
*   01.01.01    04/09/2018    Beibei.Xing   N/A          EAS422_COMM_20180904_01
*   01.01.02    13/09/2018    Beibei.Xing   N/A          EAS422_COMM_20180913_01
*   01.01.03    09/10/2018    Beibei.Xing   N/A          EAS422_COMM_20181009_01
*   01.01.04    10/10/2018    Beibei.Xing   N/A          EAS422_COMM_20181010_01
*   01.01.05    30/10/2018    Beibei.Xing   N/A          EAS422_COMM_20181030_01
*   01.01.06    29/11/2018    Beibei.Xing   N/A          EAS422_COMM_20181129_01
*   01.01.07    25/04/2019    Beibei.Xing   N/A          EAS422_COMM_20190425_01
*   01.01.08    16/04/2021    Heyan.Li      N/A          EAS422_COMM_20210416_01
*   01.01.09    30/06/2022    Feixiang.Dong N/A          EAS422_COMM_20220630_01
*   01.01.10    22/11/2022    Yaru.Sun      N/A          EAS422_COMM_20221122_01
********************************************************************************
* END_FILE_HDR*/

/*SWS_ComM_00463*/
/*******************************************************************************
*   Includes
*******************************************************************************/
/*SWS_ComM_00506*/
#include "ComM.h"
#include "SchM_ComM.h"
#include "BswM_ComM.h"

#if(STD_OFF == COMM_NVM_SUPPORT)
#include "Bsw_Common.h"
#endif

#if(STD_ON == COMM_NM_SUPPORT)
#include "Nm.h"
#endif

#if(STD_ON == COMM_DCM_SUPPORT)
#include "Dcm_Cbk.h"
#endif

#if(COMM_NUM_OF_CAN_CHANNEL > 0)
#include "CanSM_ComM.h"
#endif

#if(COMM_NUM_OF_LIN_CHANNEL > 0)
#include "LinSM.h"
#endif

#if(COMM_NUM_OF_FR_CHANNEL > 0)
#include "FrSM.h"
#endif

#if(COMM_NUM_OF_ETH_CHANNEL > 0)
#include "EthSM.h"
#endif

#if(STD_ON == COMM_DEV_ERROR_DETECT)
#include "Det.h"
#endif

#if((STD_ON == COMM_PNC_SUPPORT) && (STD_ON == COMM_USED_PNC_ENABLED))
#include "Com.h"
#endif

/*******************************************************************************
*   Version Check
*******************************************************************************/
/*ComM0136 */
#if(STD_ON == COMM_VERSION_CHECK)
/* check Version with other import module */

/* check Version with cfg file */
#if ((COMM_CONFIG_VARIANTS != STD_CONFIG_VARIANTS_PRECOMPILE) && \
    (COMM_CONFIG_VARIANTS != STD_CONFIG_VARIANTS_POSTBUILD))
#error "The ComM module only supports Pre-Compile and Post-Build Configuration."
#endif

#if ((COMM_AR_RELEASE_MAJOR_VERSION != COMM_AR_RELEASE_MAJOR_VERSION_CFG) || \
   (COMM_AR_RELEASE_MINOR_VERSION != COMM_AR_RELEASE_MINOR_VERSION_CFG))
#error "AutoSar Version Numbers of ComM and its cfg file are incompatible"
#endif

#if ((COMM_SW_MAJOR_VERSION != COMM_SW_MAJOR_VERSION_CFG) || \
   (COMM_SW_MINOR_VERSION != COMM_SW_MINOR_VERSION_CFG))
#error "SW Version Numbers of ComM and its cfg file are incompatible"
#endif


#endif/*#if(STD_ON == COMM_VERSION_CHECK)*/


/*Cfg compatibility check*/
#if((STD_ON == COMM_PNC_NM_REQUEST) && (STD_OFF == COMM_PNC_SUPPORT))
#error "COMM_PNC_NM_REQUEST must be off when COMM_PNC_SUPPORT is off!!"
#endif

#if((STD_ON == COMM_PNC_NM_REQUEST) && (STD_OFF == COMM_NM_SUPPORT))
#error "COMM_PNC_NM_REQUEST must be off when COMM_NM_SUPPORT is off!!"
#endif

#if((STD_ON == COMM_PNC_SUPPORT) && (STD_ON == COMM_USED_PNC_ENABLED))
/*SWS_ComM_00920*/
#if(COMM_NUM_OF_ACTUALPNC > 56)
#error "COMM_NUM_OF_ACTUALPNC shall be less than 57!!"
#endif

#if(COMM_NUM_OF_ACTUALPNC > COMM_NUM_OF_PNC)
#error "COMM_NUM_OF_ACTUALPNC shall be less than or equal to COMM_NUM_OF_PNC!!"
#endif

#if((COMM_EIRA_BYTE_OFFSET + COMM_EIRA_SIG_LENGTH) > 8)
#error "(COMM_EIRA_BYTE_OFFSET + COMM_EIRA_SIG_LENGTH) shall be less than 9!!"
#endif
#endif

#if(COMM_MAX_USER_MAPPING_CHANNEL>255)
#error "COMM_MAX_USER_MAPPING_CHANNEL shall be less than 255!!"
#endif
#if(COMM_MAX_CHANNEL_MAPPING_USER>255)
#error "COMM_MAX_CHANNEL_MAPPING_USER shall be less than 255!!"
#endif

/*#if(COMM_MAX_USER_MAPPING_CHANNEL != COMM_MAX_CHANNEL_MAPPING_USER)
#error "COMM_MAX_USER_MAPPING_CHANNEL shall be equal to COMM_MAX_CHANNEL_MAPPING_USER !!"
#endif*/

#if((STD_ON == COMM_NMVARIANT_PASSIVE_ENABLED) && (STD_OFF == COMM_MODE_LIMITATION_ENABLED))
#error "COMM_MODE_LIMITATION_ENABLED shall turn on when NMVARIANT=PASSIVE is on!!"
#endif

#if((COMM_NUM_OF_INTERNAL_CHANNEL>0) && (STD_OFF == COMM_NMVARIANT_NONE_ENABLED))
#error "NMVARIANT shall be NONE when Bus type is INTERNAL!!"
#endif

#if(STD_ON == COMM_NM_SUPPORT)
#if((STD_OFF == COMM_NMVARIANT_FULL_ENABLED) && (STD_OFF == COMM_NMVARIANT_PASSIVE_ENABLED))
#error "Should be either FULL or PASSIVE when COMM_NM_SUPPORT=STD_ON"
#endif
#else
#if((STD_ON == COMM_NMVARIANT_FULL_ENABLED) || (STD_ON == COMM_NMVARIANT_PASSIVE_ENABLED))
#error "Should be neither FULL nor PASSIVE when COMM_NM_SUPPORT=STD_OFF"
#endif
#endif

/*SWS_ComM_00501 SWS_ComM_00502*/
#if(STD_ON == COMM_NM_PASSIVE_MODE_ENABLED)
#if(STD_ON == COMM_NMVARIANT_FULL_ENABLED)
#error "NMVARIANT shall not be FULL when COMM_NM_PASSIVE_MODE_ENABLED!!"
#endif
#else
#if(STD_ON == COMM_NMVARIANT_PASSIVE_ENABLED)
#error "NMVARIANT shall not be PASSIVE when COMM_NMVARIANT_PASSIVE_ENABLED=FALSE!!"
#endif
#endif


/*******************************************************************************
*   Macro
*******************************************************************************/
#if(STD_ON == COMM_DEV_ERROR_DETECT)

#define  COMM_DET_ERROR_DETECT(cond, ApiId, errcode)  \
    DET_ERROR_DETECT((cond), COMM_MODULE_ID, COMM_INSTANCE_ID,(ApiId),(errcode))

#define  COMM_DET_ERROR_DETECT_RET(cond, ApiId, errcode, ret) \
    DET_ERROR_DETECT_RET((cond), COMM_MODULE_ID, COMM_INSTANCE_ID,(ApiId),(errcode), (ret))

#define  COMM_DET_REPORT_ERROR(ApiId, errcode)  \
    DET_REPORT_ERROR(COMM_MODULE_ID, COMM_INSTANCE_ID, (ApiId), (errcode))

#else

#define  COMM_DET_ERROR_DETECT(cond, ApiId, errcode)
#define  COMM_DET_ERROR_DETECT_RET(cond, ApiId, errcode, ret)
#define  COMM_DET_REPORT_ERROR(ApiId, errcode)

#endif

/*Initialization status*/
#define COMM_IS_INITIALIZED()                       (COMM_INIT == ComM_InitStatus)
#define COMM_SET_INITIALIZED()                      (ComM_InitStatus = COMM_INIT)
#define COMM_SET_UNINITIALIZED()                    (ComM_InitStatus = COMM_UNINIT)
#define COMM_GET_INIT_STATUS()                      (ComM_InitStatus)


/*Mode & State*/
#define COMM_MODE_SET_NO_COM(Channel)               (ComM_Mode[Channel] = COMM_NO_COMMUNICATION)
#define COMM_MODE_SET_FULL_COM(Channel)             (ComM_Mode[Channel] = COMM_FULL_COMMUNICATION)
#define COMM_MODE_SET_SILENT_COM(Channel)           (ComM_Mode[Channel] = COMM_SILENT_COMMUNICATION)
#define COMM_MODE_IS_NO_COM(Channel)                (COMM_NO_COMMUNICATION == ComM_Mode[Channel])
#define COMM_MODE_IS_FULL_COM(Channel)              (COMM_FULL_COMMUNICATION == ComM_Mode[Channel])
#define COMM_MODE_IS_SILENT_COM(Channel)            (COMM_SILENT_COMMUNICATION == ComM_Mode[Channel])
#define COMM_GET_MODE(Channel)                      (ComM_Mode[Channel])

#define COMM_SET_STATE(Channel, state)              (ComM_State[Channel] = (state))
#define COMM_GET_STATE(Channel)                     (ComM_State[Channel])
#define COMM_STATE_SET_NO_PENDING_REQUEST(Channel)  (ComM_State[Channel] = COMM_NO_COM_NO_PENDING_REQUEST)
#define COMM_STATE_SET_REQUEST_PENDING(Channel)     (ComM_State[Channel] = COMM_NO_COM_REQUEST_PENDING)
#define COMM_STATE_SET_NETWORK_REQUESTED(Channel)   (ComM_State[Channel] = COMM_FULL_COM_NETWORK_REQUESTED)
#define COMM_STATE_SET_READY_SLEEP(Channel)         (ComM_State[Channel] = COMM_FULL_COM_READY_SLEEP)
#define COMM_STATE_SET_SILENT(Channel)              (ComM_State[Channel] = COMM_SILENT_COM)

#define COMM_STATE_IS_NO_PENDING_REQUEST(Channel)   (COMM_NO_COM_NO_PENDING_REQUEST == ComM_State[Channel])
#define COMM_STATE_IS_REQUEST_PENDING(Channel)      (COMM_NO_COM_REQUEST_PENDING == ComM_State[Channel])
#define COMM_STATE_IS_NETWORK_REQUESTED(Channel)    (COMM_FULL_COM_NETWORK_REQUESTED == ComM_State[Channel])
#define COMM_STATE_IS_READY_SLEEP(Channel)          (COMM_FULL_COM_READY_SLEEP == ComM_State[Channel])
#define COMM_STATE_IS_SILENT(Channel)               (COMM_SILENT_COM == ComM_State[Channel])

#if(STD_ON == COMM_NMVARIANT_ENABLED)
/*Nm Variant*/
#define COMM_IS_NMVARIANT_FULL(Channel)             (COMM_FULL == ComMNmVariant[Channel])
#define COMM_IS_NMVARIANT_LIGHT(Channel)            (COMM_LIGHT == ComMNmVariant[Channel])
#define COMM_IS_NMVARIANT_PASSIVE(Channel)          (COMM_PASSIVE == ComMNmVariant[Channel])
#define COMM_IS_NMVARIANT_NONE(Channel)             (COMM_NONE == ComMNmVariant[Channel])
#else
#define COMM_IS_NMVARIANT_FULL(Channel)             (STD_ON == COMM_NMVARIANT_FULL_ENABLED)
#define COMM_IS_NMVARIANT_LIGHT(Channel)            (STD_ON == COMM_NMVARIANT_LIGHT_ENABLED)
#define COMM_IS_NMVARIANT_PASSIVE(Channel)          (STD_ON == COMM_NMVARIANT_PASSIVE_ENABLED)
#define COMM_IS_NMVARIANT_NONE(Channel)             (STD_ON == COMM_NMVARIANT_NONE_ENABLED)
#endif

/*Virtual User Request Channel Counter*/
#define COMM_IS_USER_REQUEST_CHANNEL_EXIST(Channel)         (ComMUserReqChannelCnt[Channel]>0)
#define COMM_RESET_USER_REQUEST_CHANNEL(Channel)            (ComMUserReqChannelCnt[Channel]=0)
#define COMM_INC_USER_REQUEST_CHANNEL(Channel)              (ComMUserReqChannelCnt[Channel]++)
#define COMM_DEC_USER_REQUEST_CHANNEL(Channel)              (ComMUserReqChannelCnt[Channel]--)

/*User Request Pnc Counter*//*SWS_ComM_00910*/
#if((STD_ON == COMM_PNC_SUPPORT) && (STD_ON == COMM_USED_PNC_ENABLED))

/*uesr request*/
#define COMM_IS_USER_REQUEST_PNC_EXIST(Pnc)         (ComMUserReqPncCnt[Pnc]>0)
#define COMM_RESET_USER_REQUEST_PNC(Pnc)            (ComMUserReqPncCnt[Pnc]=0)
#define COMM_INC_USER_REQUEST_PNC(Pnc)              (ComMUserReqPncCnt[Pnc]++)
#define COMM_DEC_USER_REQUEST_PNC(Pnc)              (ComMUserReqPncCnt[Pnc]--)

/*Pnc state*/
#define COMM_GET_PNCSTATE(Pnc)                      (ComM_PncState[Pnc])
#define COMM_PNCSTATE_IS_NO_COMMUNICATION(Pnc)      (COMM_PNC_NO_COMMUNICATION == ComM_PncState[Pnc])
#define COMM_PNCSTATE_IS_PREPARE_SLEEP(Pnc)         (COMM_PNC_PREPARE_SLEEP == ComM_PncState[Pnc])
#define COMM_PNCSTATE_IS_READY_SLEEP(Pnc)           (COMM_PNC_READY_SLEEP == ComM_PncState[Pnc])
#define COMM_PNCSTATE_IS_REQUESTED(Pnc)             (COMM_PNC_REQUESTED == ComM_PncState[Pnc])

#define COMM_SET_PNCSTATE_NO_COMMUNICATION(Pnc)     (ComM_PncState[Pnc] = COMM_PNC_NO_COMMUNICATION)
#define COMM_SET_PNCSTATE_PREPARE_SLEEP(Pnc)        (ComM_PncState[Pnc] = COMM_PNC_PREPARE_SLEEP)
#define COMM_SET_PNCSTATE_READY_SLEEP(Pnc)          (ComM_PncState[Pnc] = COMM_PNC_READY_SLEEP)
#define COMM_SET_PNCSTATE_REQUESTED(Pnc)            (ComM_PncState[Pnc] = COMM_PNC_REQUESTED)

#define COMM_GET_PNCID(PncIndex)                    (ComMPncId[PncIndex])

/*PBS timer*/
#define COMM_START_PNC_PREPARE_SLEEP_TIMER(Pnc)     (ComMPncPrepareSleepTimer[Pnc] = ComM_PncPrepareTimer[Pnc])
#define COMM_STOP_PNC_PREPARE_SLEEP_TIMER(Pnc)      (ComMPncPrepareSleepTimer[Pnc] = 0)
#define COMM_DEC_PNC_PREPARE_SLEEP_TIMER(Pnc)      (ComMPncPrepareSleepTimer[Pnc]--)
#define COMM_IS_PNC_PREPARE_SLEEP_TIMER_EXP(Pnc)    (0 == ComMPncPrepareSleepTimer[Pnc])

/*SWS_ComM_00825*/
#define COMM_GET_PNC_BYTE_INDEX(PncID)              (((PncID) >> 3) - COMM_EIRA_BYTE_OFFSET)
#define COMM_GET_PNC_BIT_INDEX(PncID)               ((PncID) % 8)

/*EIRA*/
#define COMM_SET_EIRA_OF_PNC(Pnc)                    (ComM_EIRAStateOfPnc[Pnc] = TRUE)
#define COMM_CLR_EIRA_OF_PNC(Pnc)                    (ComM_EIRAStateOfPnc[Pnc] = FALSE)
#define COMM_IS_EIRA_OF_PNC_VALID(Pnc)               (TRUE == ComM_EIRAStateOfPnc[Pnc])


/*Nm request mandatory*/
#if (STD_ON == COMM_PNC_NM_REQUEST)
#define COMM_SET_NM_REQUEST_MANDATORY(Channel)       (ComM_NmReqMandatory[Channel] = TRUE)
#define COMM_CLR_NM_REQUEST_MANDATORY(Channel)       (ComM_NmReqMandatory[Channel] = FALSE)
#define COMM_IS_NM_REQUEST_MANDATORY_VALID(Channel)  (TRUE == ComM_NmReqMandatory[Channel])

#define COMM_IS_PNC_NM_REQUEST_CHANNEL(Channel)      (TRUE == ComMPncNmRequest[Channel])
#endif

/*Pnc wakeup flag*/
#if((STD_ON == COMM_ECUM_SUPPORT) && (STD_ON == COMM_SYNCHRONOUS_WAKE_UP))
#define COMM_SET_PNC_WAKEUP_FLAG(Pnc)               (ComM_PncWakeupFlag[Pnc] = TRUE)
#define COMM_CLR_PNC_WAKEUP_FLAG(Pnc)               (ComM_PncWakeupFlag[Pnc] = FALSE)
#define COMM_IS_PNC_WAKEUP_VALID(Pnc)               (TRUE == ComM_PncWakeupFlag[Pnc])
#endif


#endif

/*Bit Position of ComM_TriggerInfo*/
#define COMM_NM_MODE_IND_MASK                       ((uint8)(0x03))
#define COMM_NETWORK_START_IND_MASK                 ((uint8)(0x01<<2))
#define COMM_NM_RESTART_IND_MASK                    ((uint8)(0x01<<3))
#define COMM_LIMIT_TO_NO_COM_MASK                   ((uint8)(0x01<<4))
#define COMM_ACTIVE_DIAG_MASK                       ((uint8)(0x01<<5))
#define COMM_WAKEUP_IND_MASK                        ((uint8)(0x01<<6))
#define COMM_COM_ALLOWED_IND_MASK                   ((uint8)(0x01<<7))

#if(STD_ON == COMM_NM_SUPPORT)
/*Nm Mode Indication*/
#define COMM_NM_MODE_BUS_SLEEP                      (1)
#define COMM_NM_MODE_PBS                            (2)
#define COMM_NM_MODE_NETWORK                        (3)
#define COMM_RESET_NM_MODE_IND(Channel)             (ComM_TriggerInfo[Channel] &=~ COMM_NM_MODE_IND_MASK)
#define COMM_SET_NM_NETWORK_MODE(Channel)           (ComM_TriggerInfo[Channel] = \
        ((ComM_TriggerInfo[Channel] &~ COMM_NM_MODE_IND_MASK) |\
         (COMM_NM_MODE_NETWORK)))
#define COMM_SET_NM_BUS_SLEEP_MODE(Channel)         (ComM_TriggerInfo[Channel] = \
        ((ComM_TriggerInfo[Channel] &~ COMM_NM_MODE_IND_MASK) |\
         (COMM_NM_MODE_BUS_SLEEP)))
#define COMM_SET_NM_PBS_MODE(Channel)               (ComM_TriggerInfo[Channel] = \
        ((ComM_TriggerInfo[Channel] &~ COMM_NM_MODE_IND_MASK) |\
         (COMM_NM_MODE_PBS)))
#define COMM_IS_NM_NETWORK_MODE(Channel)            (COMM_NM_MODE_NETWORK == (ComM_TriggerInfo[Channel] & COMM_NM_MODE_IND_MASK))
#define COMM_IS_NM_BUS_SLEEP_MODE(Channel)          (COMM_NM_MODE_BUS_SLEEP == (ComM_TriggerInfo[Channel] & COMM_NM_MODE_IND_MASK))
#define COMM_IS_NM_PBS_MODE(Channel)                (COMM_NM_MODE_PBS == (ComM_TriggerInfo[Channel] & COMM_NM_MODE_IND_MASK))

/*Nm Network Start*/
#define COMM_IS_NETWORK_STARTED(Channel)            (0 != (ComM_TriggerInfo[Channel] & COMM_NETWORK_START_IND_MASK))
#define COMM_SET_NETWORK_START_IND(Channel)         (ComM_TriggerInfo[Channel] |= COMM_NETWORK_START_IND_MASK)
#define COMM_CLR_NETWORK_START_IND(Channel)         (ComM_TriggerInfo[Channel] &=~ COMM_NETWORK_START_IND_MASK)

/*Nm Restart*/
#define COMM_IS_NM_RESTARTED(Channel)               (0 != (ComM_TriggerInfo[Channel] & COMM_NM_RESTART_IND_MASK))
#define COMM_SET_NM_RESTART_IND(Channel)            (ComM_TriggerInfo[Channel] |= COMM_NM_RESTART_IND_MASK)
#define COMM_CLR_NM_RESTART_IND(Channel)            (ComM_TriggerInfo[Channel] &=~ COMM_NM_RESTART_IND_MASK)
#endif


#if(STD_ON == COMM_MODE_LIMITATION_ENABLED)
/*Limit to No Com*/
#define COMM_IS_LIMIT_TO_NO_COM_STATUS(Channel)     (0 != (ComM_TriggerInfo[Channel] & COMM_LIMIT_TO_NO_COM_MASK))
#define COMM_IS_LIMIT_TO_NO_COM(Channel)            ((0 != (ComM_TriggerInfo[Channel] & COMM_LIMIT_TO_NO_COM_MASK)) && (ComMEcuGroupClassification & COMM_LIMIT_TO_COMM_FULL_COMMUNICATION_MODE))
#define COMM_LIMIT_TO_NO_COM(Channel)               (ComM_TriggerInfo[Channel] |= COMM_LIMIT_TO_NO_COM_MASK)
#define COMM_UNLIMIT_TO_NO_COM(Channel)             (ComM_TriggerInfo[Channel] &=~ COMM_LIMIT_TO_NO_COM_MASK)
#endif

#if(STD_ON == COMM_DCM_SUPPORT)
/*Active Diagnostic*/
#define COMM_IS_ACTIVE_DIAG(Channel)                (0 != (ComM_TriggerInfo[Channel] & COMM_ACTIVE_DIAG_MASK))
#define COMM_ACTIVE_DIAG(Channel)                   (ComM_TriggerInfo[Channel] |= COMM_ACTIVE_DIAG_MASK)
#define COMM_INACTIVE_DIAG(Channel)                 (ComM_TriggerInfo[Channel] &=~ COMM_ACTIVE_DIAG_MASK)
#endif

#if(STD_ON == COMM_ECUM_SUPPORT)
/*Wakeup Indication*/
#define COMM_IS_WAKEN(Channel)                      (0 != (ComM_TriggerInfo[Channel] & COMM_WAKEUP_IND_MASK))
#define COMM_SET_WKUP_IND(Channel)                  (ComM_TriggerInfo[Channel] |= COMM_WAKEUP_IND_MASK)
#define COMM_CLR_WKUP_IND(Channel)                  (ComM_TriggerInfo[Channel] &=~ COMM_WAKEUP_IND_MASK)
#endif

/*Communication Allowed*/
#define COMM_IS_COM_ALLOWED(Channel)                (0 != (ComM_TriggerInfo[Channel] & COMM_COM_ALLOWED_IND_MASK))
#define COMM_SET_COM_ALLOWED(Channel)               (ComM_TriggerInfo[Channel] |= COMM_COM_ALLOWED_IND_MASK)
#define COMM_SET_COM_DISALLOWED(Channel)            (ComM_TriggerInfo[Channel] &=~ COMM_COM_ALLOWED_IND_MASK)

#if(STD_ON == COMM_WAKEUP_INHIBITION_ENABLED)
/*Limit to No Wakeup*/
#define COMM_IS_PREVENT_WAKEUP_STATUS(Channel)      (TRUE == ComMNoWakeup[Channel])
#define COMM_IS_PREVENT_WAKEUP(Channel)             ((TRUE == ComMNoWakeup[Channel]) && (ComMEcuGroupClassification & COMM_WAKE_UP_INHIBITION_ACTIVE))
#define COMM_PREVENT_WAKEUP(Channel)                (ComMNoWakeup[Channel] = TRUE)
#define COMM_PERMIT_WAKEUP(Channel)                 (ComMNoWakeup[Channel] = FALSE)
#endif

/*BusType*/
#define COMM_GET_BUS_TYPE(Channel)                  (ComMBusType[Channel])
#define COMM_IS_BUS_TYPE_INTERNAL(Channel)          (COMM_BUS_TYPE_INTERNAL == ComMBusType[Channel])

#define COMM_IS_KEEP_COM(Channel)                   (TRUE == ComMKeepComFlag[Channel])

/*Timers*/
#if((STD_ON == COMM_NMVARIANT_LIGHT_ENABLED) || (STD_ON == COMM_NMVARIANT_NONE_ENABLED))
#define COMM_TMIN_FCMD_INVALID 0xffff
#define COMM_START_TMIN_FCMD_TIMER(Channel)         (ComMTMinFullComModeDurationTimer[Channel] = ComMTMinFullComModeDuration[Channel])
#define COMM_STOP_TMIN_FCMD_TIMER(Channel)          (ComMTMinFullComModeDurationTimer[Channel] = COMM_TMIN_FCMD_INVALID)
#define COMM_DEC_TMIN_FCMD_TIMER(Channel)           (ComMTMinFullComModeDurationTimer[Channel]--)
#define COMM_IS_TMIN_FCMD_TIMER_EXP(Channel)        (0 == ComMTMinFullComModeDurationTimer[Channel])
#define COMM_IS_TMIN_FCMD_TIMER_STARTED(Channel)    (COMM_TMIN_FCMD_INVALID != ComMTMinFullComModeDurationTimer[Channel])
#endif

#if(STD_ON == COMM_NMVARIANT_LIGHT_ENABLED)
#define COMM_NM_LIGHT_TO_INVALID 0xffff
#define COMM_START_NM_LIGHT_TO_TIMER(Channel)       (ComMNmLightToTimer[Channel] = ComMNmLightTimeout[Channel])
#define COMM_STOP_NM_LIGHT_TO_TIMER(Channel)        (ComMNmLightToTimer[Channel] = COMM_NM_LIGHT_TO_INVALID)
#define COMM_DEC_NM_LIGHT_TO_TIMER(Channel)         (ComMNmLightToTimer[Channel]--)
#define COMM_IS_NM_LIGHT_TO_TIMER_EXP(Channel)      (0 == ComMNmLightToTimer[Channel])
#define COMM_IS_NM_LIGHT_TO_TIMER_STARTED(Channel)  (COMM_NM_LIGHT_TO_INVALID != ComMNmLightToTimer[Channel])
#endif

/******************************************************************************
*   Global Vars
******************************************************************************/
#define COMM_START_SEC_VAR_INIT_8
#include "MemMap.h"
/*SWS_ComM_00910*/
#if((STD_ON == COMM_PNC_SUPPORT) && (STD_ON == COMM_USED_PNC_ENABLED))
VAR(boolean, COMM_VAR) ComM_EIRAUpdateFlag = FALSE;
#endif
#define COMM_STOP_SEC_VAR_INIT_8
#include "MemMap.h"

#define COMM_START_SEC_VAR_NOINIT_8
#include "MemMap.h"
/*This varible is not static since it will be access by NvM*/
VAR(ComM_InhibitionStatusType, COMM_VAR) ComMEcuGroupClassification;
#if(STD_ON == COMM_WAKEUP_INHIBITION_ENABLED)
/*This varible is not static since it will be access by NvM*/
VAR(boolean, COMM_VAR) ComMNoWakeup[COMM_NUM_OF_CHANNEL];
#endif
#define COMM_STOP_SEC_VAR_NOINIT_8
#include "MemMap.h"

#define COMM_START_SEC_VAR_NOINIT_16
#include "MemMap.h"
#if(STD_ON == COMM_MODE_LIMITATION_ENABLED)
/*SWS_ComM_00141*//*This varible is not static since it will be access by NvM*/
VAR(uint16, COMM_VAR) ComMInhibitCounter;
#endif
#define COMM_STOP_SEC_VAR_NOINIT_16
#include "MemMap.h"

/*******************************************************************************
*   Local Data Define
*******************************************************************************/
#define COMM_START_SEC_VAR_INIT_8
#include "MemMap.h"
STATIC VAR(ComM_InitStatusType, COMM_VAR) ComM_InitStatus = COMM_UNINIT;
#define COMM_STOP_SEC_VAR_INIT_8
#include "MemMap.h"


#define COMM_START_SEC_VAR_NOINIT_8
#include "MemMap.h"

#if(COMM_NUM_OF_USER > 0)
STATIC VAR(ComM_ModeType, COMM_VAR) ComM_UserComMode[COMM_NUM_OF_USER];
#endif

STATIC VAR(ComM_ModeType, COMM_VAR) ComM_Mode[COMM_NUM_OF_CHANNEL];
STATIC VAR(ComM_StateType, COMM_VAR) ComM_State[COMM_NUM_OF_CHANNEL];
STATIC VAR(boolean, COMM_VAR) ComMKeepComFlag[COMM_NUM_OF_CHANNEL];

STATIC VAR(uint8, COMM_VAR) ComM_TriggerInfo[COMM_NUM_OF_CHANNEL];
STATIC VAR(uint8, COMM_VAR) ComMUserReqChannelCnt[COMM_NUM_OF_CHANNEL];
#if((STD_OFF == COMM_NMVARIANT_PASSIVE_ENABLED) || (STD_ON == COMM_NMVARIANT_ENABLED))
STATIC VAR(ComM_ModeType, COMM_VAR) ComMUserMappingChannelModeReq[COMM_MAX_USER_MAPPING_CHANNEL];
#endif

/*SWS_ComM_00910*/
#if((STD_ON == COMM_PNC_SUPPORT) && (STD_ON == COMM_USED_PNC_ENABLED))
STATIC VAR(ComM_ModeType, COMM_VAR) ComMUserMappingPncModeReq[COMM_MAX_USER_MAPPING_PNC];
STATIC VAR(uint8, COMM_VAR) ComMUserReqPncCnt[COMM_NUM_OF_PNC];
/*SWS_ComM_00909*/
STATIC VAR(ComM_PncModeType, COMM_VAR) ComM_PncState[COMM_NUM_OF_PNC];
/*SWS_ComM_00982*/
STATIC VAR(uint8, COMM_VAR) ComM_EIRATxValue[COMM_EIRA_SIG_LENGTH];
STATIC VAR(boolean, COMM_VAR) ComM_EIRAStateOfPnc[COMM_NUM_OF_PNC];

#if (STD_ON == COMM_PNC_NM_REQUEST)
STATIC VAR(boolean, COMM_VAR) ComM_NmReqMandatory[COMM_NUM_OF_CHANNEL];
#endif

#if((STD_ON == COMM_ECUM_SUPPORT) && (STD_ON == COMM_SYNCHRONOUS_WAKE_UP))
STATIC VAR(boolean, COMM_VAR) ComM_PncWakeupFlag[COMM_NUM_OF_PNC];
#endif

#endif
#define COMM_STOP_SEC_VAR_NOINIT_8
#include "MemMap.h"



#define COMM_START_SEC_VAR_NOINIT_16
#include "MemMap.h"
/*SWS_ComM_00910*/
#if((STD_ON == COMM_PNC_SUPPORT) && (STD_ON == COMM_USED_PNC_ENABLED))
STATIC VAR(uint16, COMM_VAR) ComMPncPrepareSleepTimer[COMM_NUM_OF_PNC];
#endif

#if((STD_ON == COMM_NMVARIANT_LIGHT_ENABLED) || (STD_ON == COMM_NMVARIANT_NONE_ENABLED))
STATIC VAR(uint16, COMM_VAR) ComMTMinFullComModeDurationTimer[COMM_NUM_OF_CHANNEL];
#endif
#if(STD_ON == COMM_NMVARIANT_LIGHT_ENABLED)
STATIC VAR(uint16, COMM_VAR) ComMNmLightToTimer[COMM_NUM_OF_CHANNEL];
#endif

#define COMM_STOP_SEC_VAR_NOINIT_16
#include "MemMap.h"

#define COMM_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"

#if(COMM_CONFIG_VARIANTS == STD_CONFIG_VARIANTS_POSTBUILD)
STATIC P2CONST(ComM_ConfigType, COMM_VAR_NOINIT, COMM_CONST) ComM_ConfigSet;
#endif

#define COMM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"

/*******************************************************************************
*   Local Functions declaration
*******************************************************************************/
#define COMM_START_SEC_CODE
#include "MemMap.h"
/*SWS_ComM_00910*/
#if((STD_ON == COMM_PNC_SUPPORT) && (STD_ON == COMM_USED_PNC_ENABLED))
STATIC FUNC(void, COMM_CODE) ComM_InitPnc
(
    void
);
STATIC FUNC(void, COMM_CODE) ComM_DeInitPnc
(
    void
);
STATIC FUNC(void, COMM_CODE)ComM_TimerMainFunctionPnc
(
    PNCHandleType Pnc
);
STATIC FUNC(void, COMM_CODE) ComM_MainFunctionPnc
(
    PNCHandleType Pnc
);
STATIC FUNC(void, COMM_CODE) ComM_EIRAReceiveUpdate
(
    void
);
STATIC FUNC(void, COMM_CODE) ComM_PncNoComProc
(
    PNCHandleType Pnc
);
STATIC FUNC(void, COMM_CODE) ComM_PncNoComEnter
(
    PNCHandleType Pnc
);
STATIC FUNC(void, COMM_CODE) ComM_PncRequestedProc
(
    PNCHandleType Pnc
);
STATIC FUNC(void, COMM_CODE) ComM_PncRequestedEnter
(
    PNCHandleType Pnc
);
STATIC FUNC(void, COMM_CODE) ComM_PncReadySleepProc
(
    PNCHandleType Pnc
);
STATIC FUNC(void, COMM_CODE) ComM_PncReadySleepEnter
(
    PNCHandleType Pnc
);
STATIC FUNC(void, COMM_CODE) ComM_PncPrepareSleepProc
(
    PNCHandleType Pnc
);
STATIC FUNC(void, COMM_CODE) ComM_PncPrepareSleepEnter
(
    PNCHandleType Pnc
);
#endif

STATIC FUNC(Std_ReturnType, COMM_CODE) ComM_RequestChannelMode
(
    ComM_UserHandleType VirtualUser,
    ComM_ModeType ComMode
);

STATIC FUNC(void, COMM_CODE) ComM_NoPendingRequestProc
(
    const NetworkHandleType Channel
);

STATIC FUNC(void, COMM_CODE) ComM_RequestPendingProc
(
    const NetworkHandleType Channel
);

#if(STD_ON == COMM_NM_SUPPORT)
STATIC FUNC(void, COMM_CODE) ComM_SilentComProc
(
    const NetworkHandleType Channel
);
#endif

STATIC FUNC(void, COMM_CODE) ComM_NetworkRequestedProc
(
    const NetworkHandleType Channel
);

STATIC FUNC(void, COMM_CODE) ComM_ReadySleepProc
(
    const NetworkHandleType Channel
);

STATIC FUNC(void, COMM_CODE) ComM_ChannelNoComEnter
(
    const NetworkHandleType Channel
);

STATIC FUNC(void, COMM_CODE) ComM_ChannelFullComEnter
(
    const NetworkHandleType Channel,
    const ComM_StateType SubState
);

#if(STD_ON == COMM_NM_SUPPORT)
STATIC FUNC(void, COMM_CODE) ComM_ChannelSilentComEnter
(
    const NetworkHandleType Channel
);
#endif

STATIC FUNC(void, COMM_CODE) ComM_NoPendingRequestEnter
(
    const NetworkHandleType Channel
);

STATIC FUNC(void, COMM_CODE) ComM_RequestPendingEnter
(
    const NetworkHandleType Channel
);

STATIC FUNC(void, COMM_CODE) ComM_NetworkRequestedEnter
(
    const NetworkHandleType Channel
);

STATIC FUNC(void, COMM_CODE) ComM_ReadySleepEnter
(
    const NetworkHandleType Channel
);

STATIC FUNC(void, COMM_CODE) ComM_BusSM_RequestComMode
(
    const NetworkHandleType Channel,
    const ComM_ModeType Mode
);

STATIC FUNC(Std_ReturnType, COMM_CODE) ComM_BusSM_GetCurrentComMode
(
    const NetworkHandleType Channel,
    P2VAR(ComM_ModeType, AUTOMATIC, COMM_VAR) ComM_ModePtr
);

STATIC FUNC(void, COMM_CODE) ComM_ReportModeSwitch
(
    const NetworkHandleType Channel
);

STATIC FUNC(void, COMM_CODE) ComM_UpdateKeepComFlag
(
    const NetworkHandleType Channel
);

#if(STD_ON == COMM_MODE_LIMITATION_ENABLED)
STATIC FUNC(Std_ReturnType, COMM_CODE) ComM_RestoreNoComVal
(
    void
);
#endif

#if(STD_OFF == COMM_NVM_SUPPORT)
#if(STD_ON == COMM_MODE_LIMITATION_ENABLED)
STATIC FUNC(void, COMM_CODE) ComM_RestoreInhibitCounter
(
    void
);
#endif

#if(STD_ON == COMM_WAKEUP_INHIBITION_ENABLED)
STATIC FUNC(Std_ReturnType, COMM_CODE) ComM_RestoreNoWakeupVal
(
    void
);
#endif

STATIC FUNC(Std_ReturnType, COMM_CODE) ComM_RestoreEcuGroupClassificationVal
(
    void
);
#endif

#if((STD_ON == COMM_NMVARIANT_LIGHT_ENABLED) || (STD_ON == COMM_NMVARIANT_NONE_ENABLED))
STATIC FUNC(void, COMM_CODE) ComM_TimerMainFunction
(
    NetworkHandleType Channel
);
#endif


/*******************************************************************************
*   Local Functions define
*******************************************************************************/
#if(STD_ON == COMM_MODE_LIMITATION_ENABLED)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: ComM_RestoreNoComVal
*
* Description:   If no parameters are available, ComM shall use the default values
*                in the ComM configuration..().
*
* Inputs:        None
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(Std_ReturnType, COMM_CODE) ComM_RestoreNoComVal
(
    void
)
{
    NetworkHandleType Channel;

    for(Channel = 0; Channel < COMM_NUM_OF_CHANNEL; Channel++)
    {
        if(TRUE == ComMNoComDefault[Channel])
        {
            COMM_LIMIT_TO_NO_COM(Channel);
        }
        else
        {
            COMM_UNLIMIT_TO_NO_COM(Channel);
        }
    }
    return E_OK;
}
#endif

#if(STD_OFF == COMM_NVM_SUPPORT)
#if(STD_ON == COMM_MODE_LIMITATION_ENABLED)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: ComM_RestoreInhibitCounter
*
* Description:   If no parameters are available, ComM shall use the default values
*                in the ComM configuration..().
*
* Inputs:        None
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, COMM_CODE) ComM_RestoreInhibitCounter
(
    void
)
{
    ComMInhibitCounter = ComMInhibitCounterDefault;
}
#endif

#if(STD_ON == COMM_WAKEUP_INHIBITION_ENABLED)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: ComM_RestoreNoWakeupVal
*
* Description:   If no parameters are available, ComM shall use the default values
*                in the ComM configuration..().
*
* Inputs:        None
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(Std_ReturnType, COMM_CODE) ComM_RestoreNoWakeupVal
(
    void
)
{
    NetworkHandleType Channel;

    for(Channel = 0; Channel < COMM_NUM_OF_CHANNEL; Channel++)
    {
        if(TRUE == ComMNoWakeupDefault[Channel])
        {
            COMM_PREVENT_WAKEUP(Channel);
        }
        else
        {
            COMM_PERMIT_WAKEUP(Channel);
        }
    }

    return E_OK;
}
#endif

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: ComM_RestoreEcuGroupClassificationVal
*
* Description:   If no parameters are available, ComM shall use the default values
*                in the ComM configuration..().
*
* Inputs:        None
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(Std_ReturnType, COMM_CODE) ComM_RestoreEcuGroupClassificationVal
(
    void
)
{
    ComMEcuGroupClassification = ComMEcuGroupClassificationDefault;

    return E_OK;
}
#endif

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: ComM_BusSM_RequestComMode
*
* Description:   Turn on/off the Tx/Rx ability of the bus interface by calling
*                XXSM_RequestComMode() on the required channel
*
* Inputs:        Channel
*                Mode  COMM_NO_COMMUNICATION: Turn off Tx/Rx
*                      COMM_SILENT_COMMUNICATION: Turn off Tx and turn on Rx
*                      COMM_FULL_COMMUNICATION: Turn on Tx/Rx
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, COMM_CODE) ComM_BusSM_RequestComMode
(
    const NetworkHandleType Channel,
    const ComM_ModeType Mode
)
{
    /*SWS_ComM_00962 SWS_ComM_00958 SWS_ComM_00402*/
    switch(COMM_GET_BUS_TYPE(Channel))
    {
#if(COMM_NUM_OF_CAN_CHANNEL > 0)
        case COMM_BUS_TYPE_CAN:
            (void)CanSM_RequestComMode(ComMMappingChannelToBusSM[Channel], Mode);
            break;
#endif
#if(COMM_NUM_OF_LIN_CHANNEL > 0)
        case COMM_BUS_TYPE_LIN:
            (void)LinSM_RequestComMode(ComMMappingChannelToBusSM[Channel], Mode);
            break;
#endif
#if(COMM_NUM_OF_FR_CHANNEL > 0)
        case COMM_BUS_TYPE_FR:
            (void)FrSM_RequestComMode(ComMMappingChannelToBusSM[Channel], Mode);
            break;
#endif
#if(COMM_NUM_OF_ETH_CHANNEL > 0)
        case COMM_BUS_TYPE_ETH:
            (void)EthSM_RequestComMode(ComMMappingChannelToBusSM[Channel], Mode);
            break;
#endif
#if(COMM_NUM_OF_INTERNAL_CHANNEL > 0)
        /*SWS_ComM_00664*/
        case COMM_BUS_TYPE_INTERNAL:
            break;
#endif
#if(COMM_NUM_OF_CDD_CHANNEL > 0)
        /*SWS_ComM_00957*/
        case COMM_BUS_TYPE_CDD:
            (void)ComM_CddSMRequestComModeApiName[Channel](ComMMappingChannelToBusSM[Channel], Mode);
            break;
#endif
        default:
            break;
    }
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: ComM_BusSM_GetCurrentComMode
*
* Description:     Get current mode of BusSM by calling XXSM_GetCurrentComMode() on the required
*                       channel
*
* Inputs:         Channel
*
* Outputs:         Mode  COMM_NO_COMMUNICATION: Turn off Tx/Rx
*                      COMM_SILENT_COMMUNICATION: Turn off Tx and turn on Rx
*                      COMM_FULL_COMMUNICATION: Turn on Tx/Rx*
* Limitations:     None
********************************************************************************
END_FUNCTION_HDR*/
/*SWS_ComM_00084*/
STATIC FUNC(Std_ReturnType, COMM_CODE) ComM_BusSM_GetCurrentComMode
(
    const NetworkHandleType Channel,
    P2VAR(ComM_ModeType, AUTOMATIC, COMM_VAR) ComM_ModePtr
)
{
    Std_ReturnType ret = E_NOT_OK;

    /*SWS_ComM_00963 SWS_ComM_00962*/
    switch(COMM_GET_BUS_TYPE(Channel))
    {
#if(COMM_NUM_OF_CAN_CHANNEL > 0)
        case COMM_BUS_TYPE_CAN:
            ret = CanSM_GetCurrentComMode(ComMMappingChannelToBusSM[Channel], ComM_ModePtr);
            break;
#endif
#if(COMM_NUM_OF_CDD_CHANNEL > 0)
        /*SWS_ComM_00957*/
        case COMM_BUS_TYPE_CDD:
            ret = ComM_CddSMGetCurrentComModeApiName[Channel](ComMMappingChannelToBusSM[Channel], ComM_ModePtr);
            break;
#endif
#if(COMM_NUM_OF_LIN_CHANNEL > 0)
        case COMM_BUS_TYPE_LIN:
            ret = LinSM_GetCurrentComMode(ComMMappingChannelToBusSM[Channel], ComM_ModePtr);
            break;
#endif
#if(COMM_NUM_OF_FR_CHANNEL > 0)
        case COMM_BUS_TYPE_FR:
            ret = FrSM_GetCurrentComMode(ComMMappingChannelToBusSM[Channel], ComM_ModePtr);
            break;
#endif
#if(COMM_NUM_OF_ETH_CHANNEL > 0)
        case COMM_BUS_TYPE_ETH:
            ret = EthSM_GetCurrentComMode(ComMMappingChannelToBusSM[Channel], ComM_ModePtr);
            break;
#endif
#if(COMM_NUM_OF_INTERNAL_CHANNEL > 0)
        case COMM_BUS_TYPE_INTERNAL:
            ChannelComMode = COMM_NO_COMMUNICATION;
            ret = E_OK;
            break;
#endif
        default:
            ret = E_NOT_OK;
            break;
    }

    return ret;
}

#if((STD_OFF == COMM_NMVARIANT_PASSIVE_ENABLED) || (STD_ON == COMM_NMVARIANT_ENABLED))
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: ComM_ReportModeSwitch
*
* Description:     Propagates the mode switch to user and BswM
*
* Inputs:         Channel
*
* Outputs:         None
*
* Limitations:     None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, COMM_CODE) ComM_ReportModeSwitch
(
    const NetworkHandleType Channel
)
{
    ComM_UserHandleType User;
    uint8 UserIndex;
    uint8 StartUser, EndUser;
    NetworkHandleType ChannelAll;
    uint8 ChannelIndex;
    uint8 StartChannel, EndChannel;
    uint8 virtualUser;
/*SWS_ComM_00910*/
#if((STD_ON == COMM_PNC_SUPPORT) && (STD_ON == COMM_USED_PNC_ENABLED))
    uint8 StartPnc;
    uint8 EndPnc;
    PNCHandleType Pnc;
    uint8 PncIndex;
#endif
    ComM_ModeType TempComMode;


    TempComMode = COMM_FULL_COMMUNICATION;
    StartUser = ComMChannelMappingUserStart[Channel];
    EndUser = StartUser + ComMChannelMappingUserNum[Channel];

    for(UserIndex = StartUser; UserIndex < EndUser; UserIndex++)
    {
        User = ComMChannelMappingUser[UserIndex];

/*SWS_ComM_00910*/
#if((STD_ON == COMM_PNC_SUPPORT) && (STD_ON == COMM_USED_PNC_ENABLED))
        StartPnc = ComMUserMappingPncStart[User];
        EndPnc = StartPnc + ComMUserMappingPncNum[User];
        for(PncIndex = StartPnc; PncIndex < EndPnc; PncIndex++)
        {            
            Pnc = ComMUserMappingPnc[PncIndex];
            virtualUser = Pnc;
#else
            virtualUser = User;
#endif
            StartChannel = ComMUserMappingChannelStart[virtualUser];
            EndChannel = StartChannel + ComMUserMappingChannelNum[virtualUser];
            for(ChannelIndex = StartChannel; ChannelIndex < EndChannel; ChannelIndex++)
            {                
                ChannelAll = ComMUserMappingChannel[ChannelIndex];
                /*SWS_ComM_00663*/
                if(COMM_MODE_IS_NO_COM(ChannelAll))
                {
                    TempComMode = COMM_NO_COMMUNICATION;
                    break;
                }
                else if(COMM_MODE_IS_SILENT_COM(ChannelAll))
                {
                    TempComMode = COMM_SILENT_COMMUNICATION;
                }
                else
                {}
            }
/*SWS_ComM_00910*/
#if((STD_ON == COMM_PNC_SUPPORT) && (STD_ON == COMM_USED_PNC_ENABLED)) 
            /*SWS_ComM_00663*/
            if(COMM_NO_COMMUNICATION == TempComMode)
            {
                break;
            }
        }
#endif 
        /*Report to User *//*SWS_ComM_00091 SWS_ComM_00778*/
        ComM_RteSwitchFunction[User](TempComMode);
    }

}
#endif

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: ComM_UpdateKeepComFlag
*
* Description:     Calculate if we need to keep com
*
* Inputs:         Channel
*
* Outputs:         None
*
* Limitations:     None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, COMM_CODE) ComM_UpdateKeepComFlag
(
    const NetworkHandleType Channel
)
{
#if(STD_ON == COMM_DCM_SUPPORT)
    /*SWS_ComM_00866*//*SWS_ComM_00182*/
    if(COMM_IS_ACTIVE_DIAG(Channel))
    {
        ComMKeepComFlag[Channel] = TRUE;
    }
    else
#endif
         /*SWS_ComM_00686*//*SWS_ComM_00303*/
        if(COMM_IS_USER_REQUEST_CHANNEL_EXIST(Channel)
#if(STD_ON == COMM_MODE_LIMITATION_ENABLED)
                && (!COMM_IS_LIMIT_TO_NO_COM(Channel))
#endif
          )
        {
#if(STD_ON == COMM_WAKEUP_INHIBITION_ENABLED)
            /*SWS_ComM_00302 SWS_ComM_00218 SWS_ComM_00219 SWS_ComM_00841*/
            if((COMM_IS_PREVENT_WAKEUP(Channel)) && (!COMM_STATE_IS_NETWORK_REQUESTED(Channel)) && (!COMM_STATE_IS_READY_SLEEP(Channel)))
            {
                ComMKeepComFlag[Channel] = FALSE;
            }
            else
            {
#endif
                ComMKeepComFlag[Channel] = TRUE;
#if(STD_ON == COMM_WAKEUP_INHIBITION_ENABLED)
            }
#endif
        }
        else
        {
            ComMKeepComFlag[Channel] = FALSE;
        }
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: ComM_ChannelNoComEnter
*
* Description:     Process actions on enter COMM_NO_COMMUNICATION mode
*
* Inputs:         Channel
*                initialization: donot indicate BswM and RTE if true
* Outputs:         None
*
* Limitations:     None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, COMM_CODE) ComM_ChannelNoComEnter
(
    const NetworkHandleType Channel
)
{
    uint8 ChannelIndex;

    COMM_MODE_SET_NO_COM(Channel);
    /*SWS_ComM_00313*/
    if(COMM_IS_INITIALIZED())
    {
        /*SWS_ComM_00472 SWS_ComM_00976 SWS_ComM_00861*/
#if((STD_OFF == COMM_NMVARIANT_PASSIVE_ENABLED) || (STD_ON == COMM_NMVARIANT_ENABLED))
        ComM_ReportModeSwitch(Channel);
#endif
        BswM_ComM_CurrentMode(Channel, COMM_NO_COMMUNICATION);
    }

    /*ComM073*//*SWS_ComM_00846*//*SWS_ComM_00092 SWS_ComM_00073*/
    ComM_BusSM_RequestComMode(Channel, COMM_NO_COMMUNICATION);

#if((STD_OFF == COMM_NMVARIANT_PASSIVE_ENABLED) || (STD_ON == COMM_NMVARIANT_ENABLED))
    /*SWS_ComM_00582*/
    for(ChannelIndex = 0; ChannelIndex < COMM_MAX_USER_MAPPING_CHANNEL; ChannelIndex++)
    {
        if(Channel == ComMUserMappingChannel[ChannelIndex])
        {
            ComMUserMappingChannelModeReq[ChannelIndex] = COMM_NO_COMMUNICATION;
        }
    }
#endif

    /*SWS_ComM_00355*/
#if(STD_ON == COMM_RESET_AFTER_FORCING_NOCOMM)
    if(COMM_IS_LIMIT_TO_NO_COM)
    {
        BswM_ComM_InitiateReset();
    }
#endif

    /*IMPORTANT!! Necessary to reset Nm mode indication etc.*/
#if(STD_ON == COMM_NM_SUPPORT)
    COMM_RESET_NM_MODE_IND(Channel);
    COMM_CLR_NETWORK_START_IND(Channel);
    COMM_CLR_NM_RESTART_IND(Channel);
#endif
#if(STD_ON == COMM_ECUM_SUPPORT)
    COMM_CLR_WKUP_IND(Channel);
#endif
#if(STD_ON == COMM_DCM_SUPPORT)
    COMM_INACTIVE_DIAG(Channel);
#endif

    COMM_RESET_USER_REQUEST_CHANNEL(Channel);
    ComM_UpdateKeepComFlag(Channel);

#if(STD_ON == COMM_NMVARIANT_FULL_ENABLED)
    /*SWS_ComM_00288*/
    if(COMM_IS_NMVARIANT_FULL(Channel))
    {
        /*SWS_ComM_00261*/
        (void)Nm_NetworkRelease(ComMMappingChannelToNm[Channel]);
    }
#endif

    /*SWS_ComM_00898*/
    ComM_NoPendingRequestEnter(Channel);

}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: ComM_ChannelFullComEnter
*
* Description:     Process actions on enter COMM_FULL_COMMUNICATION mode
*
* Inputs:         Channel
*                SubState
* Outputs:         None
*
* Limitations:     None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, COMM_CODE) ComM_ChannelFullComEnter
(
    const NetworkHandleType Channel,
    const ComM_StateType SubState
)
{
    COMM_MODE_SET_FULL_COM(Channel);
    /*SWS_ComM_00899*/
    COMM_SET_STATE(Channel, SubState);

    /*SWS_ComM_00472 SWS_ComM_00976 SWS_ComM_00861*/
#if((STD_OFF == COMM_NMVARIANT_PASSIVE_ENABLED) || (STD_ON == COMM_NMVARIANT_ENABLED))
    ComM_ReportModeSwitch(Channel);
#endif
    BswM_ComM_CurrentMode(Channel, COMM_FULL_COMMUNICATION);

    /*SWS_ComM_00845*//*SWS_ComM_00092 SWS_ComM_00069*/
    ComM_BusSM_RequestComMode(Channel, COMM_FULL_COMMUNICATION);

    if(COMM_FULL_COM_NETWORK_REQUESTED == SubState)
    {
        /*SWS_ComM_00880*/
        ComM_NetworkRequestedEnter(Channel);
    }
    else
    {
        /*SWS_ComM_00880*/
        ComM_ReadySleepEnter(Channel);
    }

}

#if(STD_ON == COMM_NM_SUPPORT)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: ComM_ChannelSilentComEnter
*
* Description:     Process actions on enter COMM_SILENT_COMMUNICATION mode
*
* Inputs:         Channel
*
* Outputs:         None
*
* Limitations:     None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, COMM_CODE) ComM_ChannelSilentComEnter
(
    const NetworkHandleType Channel
)
{
    COMM_MODE_SET_SILENT_COM(Channel);
    COMM_STATE_SET_SILENT(Channel);

    /*SWS_ComM_00472 SWS_ComM_00976 SWS_ComM_00861*/
#if((STD_OFF == COMM_NMVARIANT_PASSIVE_ENABLED) || (STD_ON == COMM_NMVARIANT_ENABLED))
    ComM_ReportModeSwitch(Channel);
#endif
    BswM_ComM_CurrentMode(Channel, COMM_SILENT_COMMUNICATION);

    /*ComM071*//*SWS_ComM_00092 SWS_ComM_00071*/
    ComM_BusSM_RequestComMode(Channel, COMM_SILENT_COMMUNICATION);

    /*ComM_SilentComProc(Channel);*/
}
#endif

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: ComM_NoPendingRequestEnter
*
* Description:     Process actions on enter COMM_NO_COM_NO_PENDING_REQUEST state
*
* Inputs:         Channel
*
* Outputs:         None
*
* Limitations:     None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, COMM_CODE) ComM_NoPendingRequestEnter
(
    const NetworkHandleType Channel
)
{
    COMM_STATE_SET_NO_PENDING_REQUEST(Channel);
    /*ComM_NoPendingRequestProc(Channel);*/
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: ComM_RequestPendingEnter
*
* Description:     Process actions on enter COMM_NO_COM_REQUEST_PENDING state
*
* Inputs:         Channel
*
* Outputs:         None
*
* Limitations:     None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, COMM_CODE) ComM_RequestPendingEnter
(
    const NetworkHandleType Channel
)
{
    COMM_STATE_SET_REQUEST_PENDING(Channel);
    ComM_RequestPendingProc(Channel);
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: ComM_NetworkRequestedEnter
*
* Description:     Process actions on enter COMM_FULL_COM_NETWORK_REQUESTED state
*
* Inputs:         Channel
*
* Outputs:         None
*
* Limitations:     None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, COMM_CODE) ComM_NetworkRequestedEnter
(
    const NetworkHandleType Channel
)
{
#if(STD_ON == COMM_NMVARIANT_FULL_ENABLED)
    ComM_ModeType ComMode = COMM_NO_COMMUNICATION;
#endif
    COMM_STATE_SET_NETWORK_REQUESTED(Channel);

#if((STD_ON == COMM_NMVARIANT_LIGHT_ENABLED) || (STD_ON == COMM_NMVARIANT_NONE_ENABLED))
    /*SWS_ComM_00886*/
    if(COMM_IS_NMVARIANT_LIGHT(Channel) || COMM_IS_NMVARIANT_NONE(Channel))
    {
        COMM_START_TMIN_FCMD_TIMER(Channel);
    }
#endif
#if (STD_ON == COMM_NMVARIANT_LIGHT_ENABLED)
    /*SWS_ComM_00892*/
    if(COMM_IS_NMVARIANT_LIGHT(Channel))
    {
        COMM_STOP_NM_LIGHT_TO_TIMER(Channel);
    }
#endif
#if(STD_ON == COMM_NMVARIANT_FULL_ENABLED)
    /*SWS_ComM_00869 SWS_ComM_00870*/
    if(COMM_IS_NMVARIANT_FULL(Channel))
    {
        (void)ComM_BusSM_GetCurrentComMode(Channel, &ComMode);
        if((COMM_IS_KEEP_COM(Channel)) && (COMM_FULL_COMMUNICATION == ComMode))
        {
            /*SWS_ComM_00261*/
            (void)Nm_NetworkRequest(ComMMappingChannelToNm[Channel]);
        }
    }
#endif
#if (STD_ON == COMM_PNC_NM_REQUEST)
    if((COMM_IS_NM_REQUEST_MANDATORY_VALID(Channel)) && (COMM_IS_PNC_NM_REQUEST_CHANNEL(Channel)))
    {
        COMM_CLR_NM_REQUEST_MANDATORY(Channel);
    }
#endif
    /*ComM_NetworkRequestedProc(Channel);*/
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: ComM_ReadySleepEnter
*
* Description:     Process actions on enter COMM_FULL_COM_READY_SLEEP state
*
* Inputs:         Channel
*
* Outputs:         None
*
* Limitations:     None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, COMM_CODE) ComM_ReadySleepEnter
(
    const NetworkHandleType Channel
)
{
    COMM_STATE_SET_READY_SLEEP(Channel);
#if(STD_ON == COMM_NMVARIANT_FULL_ENABLED)
    /*SWS_ComM_00133*/
    if(COMM_IS_NMVARIANT_FULL(Channel))
    {
        /*SWS_ComM_00261*/
        (void)Nm_NetworkRelease(ComMMappingChannelToNm[Channel]);
    }
#endif
#if(STD_ON == COMM_NMVARIANT_LIGHT_ENABLED)
    /*SWS_ComM_00891*/
    if(COMM_IS_NMVARIANT_LIGHT(Channel))
    {
        COMM_START_NM_LIGHT_TO_TIMER(Channel);
    }
#endif

    /*ComM_ReadySleepProc(Channel);*/
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: ComM_NoPendingRequestProc
*
* Description:     Process actions in COMM_NO_COM_NO_PENDING_REQUEST state
*
* Inputs:         Channel
*
* Outputs:         None
*
* Limitations:     None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, COMM_CODE) ComM_NoPendingRequestProc
(
    const NetworkHandleType Channel
)
{
#if(STD_ON == COMM_SYNCHRONOUS_WAKE_UP)
    NetworkHandleType ChannelIndex;
    boolean WkupFlg = FALSE;
#endif
    boolean RequestPendingFlg = FALSE;

    /*SWS_ComM_00875 SWS_ComM_00876 SWS_ComM_00894*/
    if(COMM_IS_KEEP_COM(Channel)
#if(STD_ON == COMM_NM_SUPPORT)
            || (COMM_IS_NM_RESTARTED(Channel))
            || (COMM_IS_NETWORK_STARTED(Channel))
#endif
      )
    {
        RequestPendingFlg = TRUE;
    }

#if(STD_ON == COMM_ECUM_SUPPORT)
    /*SWS_ComM_00893*/
    if(COMM_IS_WAKEN(Channel))
    {
        RequestPendingFlg = TRUE;
#if(STD_ON == COMM_SYNCHRONOUS_WAKE_UP)
        WkupFlg = TRUE;
#endif
    }
#endif

    if(TRUE == RequestPendingFlg)
    {
        /*SWS_ComM_00694*/
#if(STD_ON == COMM_SYNCHRONOUS_WAKE_UP)
        if(TRUE == WkupFlg)
        {
            /*should we wakeup all channels, or only the channels in NO_PENDING_REQUEST?*/
            for(ChannelIndex = 0; ChannelIndex < COMM_NUM_OF_CHANNEL; ChannelIndex++)
            {
                if(!COMM_IS_WAKEN(ChannelIndex) && (COMM_STATE_IS_NO_PENDING_REQUEST(ChannelIndex)))
                {
                    COMM_SET_WKUP_IND(ChannelIndex);
                }
            }
        }
#endif
        ComM_RequestPendingEnter(Channel);
    }
    else
    {
        /*Stay in NoPendingRequest*/
    }
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: ComM_RequestPendingProc
*
* Description:     Process actions in COMM_NO_COM_REQUEST_PENDING state
*
* Inputs:         Channel
*
* Outputs:         None
*
* Limitations:     None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, COMM_CODE) ComM_RequestPendingProc
(
    const NetworkHandleType Channel
)
{
    /*SWS_ComM_00897*/
    if((!COMM_IS_KEEP_COM(Channel))
#if(STD_ON == COMM_NM_SUPPORT)
            && (!COMM_IS_NM_RESTARTED(Channel))
            && (!COMM_IS_NETWORK_STARTED(Channel))
#endif
#if(STD_ON == COMM_ECUM_SUPPORT)
            && (!COMM_IS_WAKEN(Channel))
#endif
      )
    {
        ComM_NoPendingRequestEnter(Channel);
    }
    /*SWS_ComM_00895 SWS_ComM_00896*/
    else if(COMM_IS_COM_ALLOWED(Channel))
    {
        if(COMM_IS_KEEP_COM(Channel))
        {
            ComM_ChannelFullComEnter(Channel, COMM_FULL_COM_NETWORK_REQUESTED);
        }
        else
        {
            ComM_ChannelFullComEnter(Channel, COMM_FULL_COM_READY_SLEEP);
        }
    }
    else
    {
        /*Stay in RequestPending*/
    }
}

#if(STD_ON == COMM_NM_SUPPORT)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: ComM_SilentComProc
*
* Description:     Process actions in COMM_SILENT_COM state
*
* Inputs:         Channel
*
* Outputs:         None
*
* Limitations:     None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, COMM_CODE) ComM_SilentComProc
(
    const NetworkHandleType Channel
)
{
    /*Only PASSIVE or FULL channel can reach here*/   
#if(STD_ON == COMM_NMVARIANT_FULL_ENABLED)
    /*SWS_ComM_00877 SWS_ComM_00878*/
    if(COMM_IS_KEEP_COM(Channel))
    {
        ComM_ChannelFullComEnter(Channel, COMM_FULL_COM_NETWORK_REQUESTED);
    }
    /*SWS_ComM_00295*/
    else 
#endif
/*SWS_ComM_00602*/
#if((STD_ON == COMM_NMVARIANT_FULL_ENABLED) || (STD_ON == COMM_NMVARIANT_PASSIVE_ENABLED))
    if(COMM_IS_NM_BUS_SLEEP_MODE(Channel))
    {
        ComM_ChannelNoComEnter(Channel);
    }
    /*SWS_ComM_00296*//*SWS_ComM_00066*/
    else if(COMM_IS_NM_NETWORK_MODE(Channel))
    {
        ComM_ChannelFullComEnter(Channel, COMM_FULL_COM_READY_SLEEP);
    }
    else
    {
        /*Stay here*/
    }
#endif
}
#endif

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: ComM_NetworkRequestedProc
*
* Description:     Process actions in COMM_FULL_COM_NETWORK_REQUESTED state
*
* Inputs:         Channel
*
* Outputs:         None
*
* Limitations:     None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, COMM_CODE) ComM_NetworkRequestedProc
(
    const NetworkHandleType Channel
)
{
#if (STD_ON == COMM_PNC_NM_REQUEST)
    ComM_ModeType ComMode;
#endif

#if(STD_ON == COMM_NMVARIANT_PASSIVE_ENABLED)
    /*SWS_ComM_00915*//*SWS_ComM_00066*/
    if(COMM_IS_NMVARIANT_PASSIVE(Channel))
    {
        ComM_ReadySleepEnter(Channel);
    }
    else
#endif

        if(!COMM_IS_KEEP_COM(Channel))
        {
#if((STD_ON == COMM_NMVARIANT_LIGHT_ENABLED) || (STD_ON == COMM_NMVARIANT_NONE_ENABLED))
            if(COMM_IS_NMVARIANT_LIGHT(Channel) || COMM_IS_NMVARIANT_NONE(Channel))
            {
                if(COMM_IS_TMIN_FCMD_TIMER_EXP(Channel))
                {
                    /*SWS_ComM_00889*/
                    COMM_STOP_TMIN_FCMD_TIMER(Channel);
                    ComM_ReadySleepEnter(Channel);
                }
#if(STD_ON == COMM_MODE_LIMITATION_ENABLED)
                else if(COMM_IS_LIMIT_TO_NO_COM(Channel)
#if(STD_ON == COMM_DCM_SUPPORT)
                        && (!COMM_IS_ACTIVE_DIAG(Channel))
#endif
                       )
                {
                    /*SWS_ComM_00890 SWS_ComM_00888 SWS_ComM_00215*/
                    /*Even if TMIN_FCMD_TIMER is on, we still change state*/
                    /*TMIN_FCMD_TIMER may still on, never mind*/
                    ComM_ReadySleepEnter(Channel);
                }
#endif
            }
            else
#endif
                /*Must be FULL now*/
            {
                /*SWS_ComM_00888 SWS_ComM_00303*/
                ComM_ReadySleepEnter(Channel);
            }
        }
        else
        {
            /*KeepCom, Staty NetworkRequested*/

#if (STD_ON == COMM_PNC_NM_REQUEST)
            /*if the ??FULL Communication?? is requested due to a change in the PNC state
                 machine to PNC_REQUESTED, API Nm_NetworkRequest() shall be
                 called, even if the current state is already "Full communication".*//*SWS_ComM_00980*/

            if((COMM_IS_NM_REQUEST_MANDATORY_VALID(Channel)) && (COMM_IS_PNC_NM_REQUEST_CHANNEL(Channel)))
            {
                COMM_CLR_NM_REQUEST_MANDATORY(Channel);
                (void)ComM_BusSM_GetCurrentComMode(Channel, &ComMode);
                if(COMM_FULL_COMMUNICATION == ComMode)
                {
                    /*SWS_ComM_00261*/
                    (void)Nm_NetworkRequest(ComMMappingChannelToNm[Channel]);
                }
            }
#endif

        }
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: ComM_ReadySleepProc
*
* Description:     Process actions in COMM_FULL_COM_READY_SLEEP state
*
* Inputs:         Channel
*
* Outputs:         None
*
* Limitations:     None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, COMM_CODE) ComM_ReadySleepProc
(
    const NetworkHandleType Channel
)
{
#if(STD_ON == COMM_NMVARIANT_NONE_ENABLED)
    /*SWS_ComM_00671*/
    if(COMM_IS_BUS_TYPE_INTERNAL(Channel))
    {
        /*NmVariant is NONE on internal bus*/
        ComM_ChannelNoComEnter(Channel);
    }
    else
#endif
/*SWS_ComM_00602*/
#if(STD_ON == COMM_NMVARIANT_PASSIVE_ENABLED)
        if(COMM_IS_NMVARIANT_PASSIVE(Channel))
        {
            /*SWS_ComM_00826*/
            if(COMM_IS_NM_PBS_MODE(Channel))
            {
                ComM_ChannelSilentComEnter(Channel);
            }
            /*SWS_ComM_00637*/
            else if(COMM_IS_NM_BUS_SLEEP_MODE(Channel))
            {
                ComM_ChannelNoComEnter(Channel);
            }
            else
            {
                /*Stay ReadySleep*/
            }
        }
        else
#endif
            /*SWS_ComM_00882 SWS_ComM_00883 SWS_ComM_00892*/
            if(COMM_IS_KEEP_COM(Channel))
            {
                /*Even if NM_LIGHT_TO_TIMER is on, we still change state*/
                /*NM_LIGHT_TO_TIMER may still on, never mind*/
                ComM_NetworkRequestedEnter(Channel);
            }
            else
            {
#if(STD_ON == COMM_NMVARIANT_LIGHT_ENABLED)
                /*SWS_ComM_00610*/
                if(COMM_IS_NMVARIANT_LIGHT(Channel))
                {
                    if(COMM_IS_NM_LIGHT_TO_TIMER_EXP(Channel))
                    {
                        COMM_STOP_NM_LIGHT_TO_TIMER(Channel);
                        ComM_ChannelNoComEnter(Channel);
                    }
                    else
                    {
                        /*Stay ReadySleep*/
                    }
                }
                else
#endif
/*SWS_ComM_00602*/
#if(STD_ON == COMM_NMVARIANT_FULL_ENABLED)
                    if(COMM_IS_NMVARIANT_FULL(Channel))
                    {
                        /*SWS_ComM_00826*/
                        if(COMM_IS_NM_PBS_MODE(Channel))
                        {
                            ComM_ChannelSilentComEnter(Channel);
                        }
                        /*SWS_ComM_00637*/
                        else if(COMM_IS_NM_BUS_SLEEP_MODE(Channel))
                        {
                            ComM_ChannelNoComEnter(Channel);
                        }
                        else
                        {
                            /*Stay ReadySleep*/
                        }
                    }
                    else
#endif
                    {
                        /*Stay ReadySleep if NONE*/
                    }
            }

}



/*******************************************************************************
*  PUBLIC Functions define
*******************************************************************************/

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: ComM_GetStatus  SWS_ComM_00242
*
* Description:   Returns the initialization status of the AUTOSAR Communication Manager
*
* Inputs:        None
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, COMM_CODE) ComM_GetStatus
(
    P2VAR(ComM_InitStatusType, AUTOMATIC, COMM_APPL_DATA) Status
)
{    
    Std_ReturnType ret = E_NOT_OK;

    if(NULL_PTR == Status)
    {        
        COMM_DET_REPORT_ERROR(COMM_GETSTATUS_APIID, COMM_E_PARAM_POINTER);
    }
    else
    {
        *Status = COMM_GET_INIT_STATUS();
        ret = E_OK;
    }
    return ret;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: ComM_GetInhibitionStatus  SWS_ComM_00619
*
* Description:   Returns the initialization status of the AUTOSAR Communication Manager
*
* Inputs:        None
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, COMM_CODE) ComM_GetInhibitionStatus
(
    NetworkHandleType Channel,
    P2VAR(ComM_InhibitionStatusType, AUTOMATIC, COMM_APPL_DATA) Status
)
{
    /*SWS_ComM_00612*/
    Std_ReturnType ret = E_NOT_OK;
    ComM_InhibitionStatusType TempStatus;

    if(!COMM_IS_INITIALIZED())
    {
        /*SWS_ComM_00858*/
        COMM_DET_REPORT_ERROR(COMM_GETINHIBITIONSTATUS_APIID, COMM_E_NOT_INITED);
    }
    else if(Channel >= COMM_NUM_OF_CHANNEL)
    {
        COMM_DET_REPORT_ERROR(COMM_GETINHIBITIONSTATUS_APIID, COMM_E_WRONG_PARAMETERS);
    }
    else if(NULL_PTR == Status)
    {
        COMM_DET_REPORT_ERROR(COMM_GETINHIBITIONSTATUS_APIID, COMM_E_PARAM_POINTER);
    }
    else
    {
        TempStatus = 0;
#if(STD_ON == COMM_WAKEUP_INHIBITION_ENABLED)
        if(COMM_IS_PREVENT_WAKEUP_STATUS(Channel))
        {
            TempStatus |= COMM_WAKE_UP_INHIBITION_ACTIVE;
        }
#endif
#if(STD_ON == COMM_MODE_LIMITATION_ENABLED)
        if(COMM_IS_LIMIT_TO_NO_COM_STATUS(Channel))
        {
            TempStatus |= COMM_LIMIT_TO_COMM_FULL_COMMUNICATION_MODE;
        }
#endif
        *Status = TempStatus;
        ret = E_OK;
    }
    return ret;
}

#if((STD_OFF == COMM_NMVARIANT_PASSIVE_ENABLED) || (STD_ON == COMM_NMVARIANT_ENABLED))

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: ComM_RequestChannelMode
*
* Description:   Requesting of a Communication Mode by a user
*
* Inputs:        User Handle of the user who requests a mode
*                ComMode Mode that user requested
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(Std_ReturnType, COMM_CODE) ComM_RequestChannelMode
(
    ComM_UserHandleType VirtualUser,
    ComM_ModeType ComMode
)
{
    uint8 StartChannel;
    uint8 EndChannel;
    uint8 ChannelIndex;
    NetworkHandleType Channel;
    Std_ReturnType ret = E_NOT_OK;

    /*SWS_ComM_00795*/
    StartChannel = ComMUserMappingChannelStart[VirtualUser];
    EndChannel = StartChannel + ComMUserMappingChannelNum[VirtualUser];

    if(COMM_NO_COMMUNICATION == ComMode)
    {
        for(ChannelIndex = StartChannel; ChannelIndex < EndChannel; ChannelIndex++)
        {
            /*SWS_ComM_00795*/
            Channel = ComMUserMappingChannel[ChannelIndex];
/*SWS_ComM_00910 SWS_ComM_00667*/
#if((STD_ON == COMM_NMVARIANT_PASSIVE_ENABLED) && ((STD_ON != COMM_PNC_SUPPORT) || (STD_ON != COMM_USED_PNC_ENABLED)))
            if(COMM_IS_NMVARIANT_PASSIVE(Channel))
            {
                COMM_DET_REPORT_ERROR(COMM_REQUESTCOMMODE_APIID, COMM_E_ILLEGAL_REQUEST);
                ret = COMM_E_ILLEGAL_REQUEST;
                continue;
            }
#endif
            /*if already in the COMM_NO_COMMUNICATION, ignore*/
            if(COMM_NO_COMMUNICATION != ComMUserMappingChannelModeReq[ChannelIndex])
            {
                /*SWS_ComM_00839 SWS_ComM_00625*//*SWS_ComM_00500*/
                ComMUserMappingChannelModeReq[ChannelIndex] = COMM_NO_COMMUNICATION;
                if(COMM_IS_USER_REQUEST_CHANNEL_EXIST(Channel))
                {
                    COMM_DEC_USER_REQUEST_CHANNEL(Channel);
                    ComM_UpdateKeepComFlag(Channel);
                }
            }
        }
#if((STD_ON == COMM_NMVARIANT_PASSIVE_ENABLED) && ((STD_ON != COMM_PNC_SUPPORT) || (STD_ON != COMM_USED_PNC_ENABLED)))
        if(COMM_E_ILLEGAL_REQUEST != ret)
#endif
        {
            ret = E_OK;
        }
#if((STD_ON == COMM_NMVARIANT_PASSIVE_ENABLED) && ((STD_ON != COMM_PNC_SUPPORT) || (STD_ON != COMM_USED_PNC_ENABLED)))
        else
        {
            ret = E_NOT_OK;
        }
#endif
    }
    else/*COMM_FULL_COMMUNICATION*/
    {
        for(ChannelIndex = StartChannel; ChannelIndex < EndChannel; ChannelIndex++)
        {
            Channel = ComMUserMappingChannel[ChannelIndex];
/*SWS_ComM_00667*/
#if((STD_ON == COMM_NMVARIANT_PASSIVE_ENABLED) && ((STD_ON != COMM_PNC_SUPPORT) || (STD_ON != COMM_USED_PNC_ENABLED)))
            if(COMM_IS_NMVARIANT_PASSIVE(Channel))
            {
                COMM_DET_REPORT_ERROR(COMM_REQUESTCOMMODE_APIID, COMM_E_ILLEGAL_REQUEST);
                ret = COMM_E_ILLEGAL_REQUEST;
                continue;
            }
#endif
#if(STD_ON == COMM_MODE_LIMITATION_ENABLED)
            if(COMM_IS_LIMIT_TO_NO_COM(Channel))
            {
                /*SWS_ComM_00138 SWS_ComM_00142 SWS_ComM_00141*/
                if(ComMInhibitCounter < 65535)
                {
                    ComMInhibitCounter++;
/*SWS_ComM_00140 SWS_ComM_00103*/
#if(STD_ON == COMM_NVM_SUPPORT)
                    NvM_SetRamBlockStatus(ComMInhibitCounterBlockId, TRUE);
#endif
                }

                ret = COMM_E_MODE_LIMITATION;
            }
            /*no else*/
#endif
            /*if already in the COMM_FULL_COMMUNICATION, ignore*/
            if(COMM_FULL_COMMUNICATION != ComMUserMappingChannelModeReq[ChannelIndex])
            {
                 /*SWS_ComM_00686*//*SWS_ComM_00500*//*SWS_ComM_00840*/
                ComMUserMappingChannelModeReq[ChannelIndex] = COMM_FULL_COMMUNICATION;
                COMM_INC_USER_REQUEST_CHANNEL(Channel);
                ComM_UpdateKeepComFlag(Channel);
            }
        }
#if(STD_ON == COMM_MODE_LIMITATION_ENABLED)
        if(COMM_E_MODE_LIMITATION != ret)
#endif
        {
#if((STD_ON == COMM_NMVARIANT_PASSIVE_ENABLED) && ((STD_ON != COMM_PNC_SUPPORT) || (STD_ON != COMM_USED_PNC_ENABLED)))
            if(COMM_E_ILLEGAL_REQUEST != ret)
#endif
            {
                ret = E_OK;
            }
#if((STD_ON == COMM_NMVARIANT_PASSIVE_ENABLED) && ((STD_ON != COMM_PNC_SUPPORT) || (STD_ON != COMM_USED_PNC_ENABLED)))
            else
            {
                ret = E_NOT_OK;
            }
#endif
        }
    }

    return ret;
}



/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: ComM_RequestComMode  SWS_ComM_00110
*
* Description:   Requesting of a Communication Mode by a user
*
* Inputs:        User Handle of the user who requests a mode
*                ComMode Mode that user requested
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, COMM_CODE) ComM_RequestComMode
(
    ComM_UserHandleType User,
    ComM_ModeType ComMode
)
{
    /*SWS_ComM_00910*/
#if((STD_ON == COMM_PNC_SUPPORT) && (STD_ON == COMM_USED_PNC_ENABLED))
    uint8 StartPnc;
    uint8 EndPnc;
    uint8 PncIndex;
    PNCHandleType Pnc;
#if((STD_ON == COMM_NMVARIANT_PASSIVE_ENABLED) || (STD_ON == COMM_MODE_LIMITATION_ENABLED))
    uint8 StartChannel;
    uint8 EndChannel;
    uint8 ChannelIndex;
    NetworkHandleType Channel;
#endif
#endif
    /*SWS_ComM_00612*/
    Std_ReturnType ret = E_NOT_OK;

    if(!COMM_IS_INITIALIZED())
    {
        /*SWS_ComM_00858*/
        COMM_DET_REPORT_ERROR(COMM_REQUESTCOMMODE_APIID, COMM_E_NOT_INITED);
    }
    else if(User >= COMM_NUM_OF_USER)
    {
        COMM_DET_REPORT_ERROR(COMM_REQUESTCOMMODE_APIID, COMM_E_WRONG_PARAMETERS);
    }
    /*SWS_ComM_00151*/
    else if((COMM_NO_COMMUNICATION != ComMode) && (COMM_FULL_COMMUNICATION != ComMode))
    {
        COMM_DET_REPORT_ERROR(COMM_REQUESTCOMMODE_APIID, COMM_E_WRONG_PARAMETERS);
    }
    else
    {
        SchM_Enter_ComM_COMM_EXCLUSIVE_AREA_0();

        /*SWS_ComM_00839*//*SWS_ComM_00972*/
        ComM_UserComMode[User] = ComMode;
/*SWS_ComM_00910*/
#if((STD_ON == COMM_PNC_SUPPORT) && (STD_ON == COMM_USED_PNC_ENABLED))

        StartPnc = ComMUserMappingPncStart[User];
        EndPnc = StartPnc + ComMUserMappingPncNum[User];

        for(PncIndex = StartPnc; PncIndex < EndPnc; PncIndex++)
        {
            /*Find the user-controlled pnc*/
            Pnc = ComMUserMappingPnc[PncIndex];

#if(STD_ON == COMM_NMVARIANT_PASSIVE_ENABLED)
            StartChannel = ComMUserMappingChannelStart[Pnc];
            EndChannel = StartChannel + ComMUserMappingChannelNum[Pnc];
            for(ChannelIndex = StartChannel; ChannelIndex < EndChannel; ChannelIndex++)
            {
                Channel = ComMUserMappingChannel[ChannelIndex];
                /*SWS_ComM_00667*/
                if(COMM_IS_NMVARIANT_PASSIVE(Channel))
                {
                    COMM_DET_REPORT_ERROR(COMM_REQUESTCOMMODE_APIID, COMM_E_ILLEGAL_REQUEST);
                    ret = COMM_E_ILLEGAL_REQUEST;
                    break;
                }
            }
#endif

#if(STD_ON == COMM_NMVARIANT_PASSIVE_ENABLED)
            if(COMM_E_ILLEGAL_REQUEST != ret)
            {
#endif

                /*release PNC*/
                if(COMM_NO_COMMUNICATION == ComMode)
                {
                    /*if already in the COMM_NO_COMMUNICATION, ignore*/
                    if(COMM_PNC_NO_COMMUNICATION != ComMUserMappingPncModeReq[PncIndex])
                    {
                        /*SWS_ComM_00500*//*SWS_ComM_00972*/
                        ComMUserMappingPncModeReq[PncIndex] = COMM_PNC_NO_COMMUNICATION;

                        /*Check if there are still users requesting this pnc*/
                        if(COMM_IS_USER_REQUEST_PNC_EXIST(Pnc))
                        {
                            COMM_DEC_USER_REQUEST_PNC(Pnc);
                        }
                    }

                }
                /*request PNC*/
                else
                {
#if (STD_ON == COMM_MODE_LIMITATION_ENABLED)
                    StartChannel = ComMUserMappingChannelStart[Pnc];
                    EndChannel = StartChannel + ComMUserMappingChannelNum[Pnc];
                    for(ChannelIndex = StartChannel; ChannelIndex < EndChannel; ChannelIndex++)
                    {
                        Channel = ComMUserMappingChannel[ChannelIndex];
                        if(COMM_IS_LIMIT_TO_NO_COM(Channel))
                        {
                            ret = COMM_E_MODE_LIMITATION;
                            break;
                        }
                    }
                    if(COMM_PNCSTATE_IS_REQUESTED(Pnc))
                    {
                        ComM_RequestChannelMode(Pnc, COMM_FULL_COMMUNICATION);
                    }

#endif
                    /*if already in the COMM_FULL_COMMUNICATION, ignore*/
                    if(COMM_PNC_REQUESTED != ComMUserMappingPncModeReq[PncIndex])
                    {
                        /*SWS_ComM_00686*//*SWS_ComM_00500*//*SWS_ComM_00972*/
                        ComMUserMappingPncModeReq[PncIndex] = COMM_PNC_REQUESTED;
                        COMM_INC_USER_REQUEST_PNC(Pnc);
                    }
                }
#if(STD_ON == COMM_NMVARIANT_PASSIVE_ENABLED)
            }  
            else
            {
                break;
            }
#endif
        }

#if(STD_ON == COMM_MODE_LIMITATION_ENABLED)
        if(COMM_E_MODE_LIMITATION != ret)
#endif
        {
#if(STD_ON == COMM_NMVARIANT_PASSIVE_ENABLED)
            if(COMM_E_ILLEGAL_REQUEST != ret)
#endif
            {
                ret = E_OK;
            }
#if(STD_ON == COMM_NMVARIANT_PASSIVE_ENABLED)
            else
            {
                ret = E_NOT_OK;
            }
#endif
        }

#else
        /*SWS_ComM_00827*/
        ret = ComM_RequestChannelMode(User, ComMode);
#endif

        SchM_Exit_ComM_COMM_EXCLUSIVE_AREA_0();

    }

    return ret;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: ComM_GetMaxComMode  SWS_ComM_00085
*
* Description:   Function to query the maximum allowed Communication Mode of the
*               corresponding user.
*
* Inputs:        User Handle of the user who requests a mode
*
* Outputs:       ComMode
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, COMM_CODE) ComM_GetMaxComMode
(
    ComM_UserHandleType User,
    P2VAR(ComM_ModeType, AUTOMATIC, COMM_APPL_DATA) ComMode
)
{
#if((STD_ON == COMM_MODE_LIMITATION_ENABLED) || (STD_ON == COMM_WAKEUP_INHIBITION_ENABLED))
    NetworkHandleType Channel;
    uint8 ChannelIndex;
    uint8 StartChannel, EndChannel;
    uint8 virtualUser;
/*SWS_ComM_00910*/
#if((STD_ON == COMM_PNC_SUPPORT) && (STD_ON == COMM_USED_PNC_ENABLED))
    uint8 StartPnc;
    uint8 EndPnc;
    PNCHandleType Pnc;
    uint8 PncIndex;
#endif
#endif
    /*SWS_ComM_00612*/
    Std_ReturnType ret = E_NOT_OK;
    ComM_ModeType TempComMode;

    if(!COMM_IS_INITIALIZED())
    {
        /*SWS_ComM_00858*/
        COMM_DET_REPORT_ERROR(COMM_GETMAXCOMMODE_APIID, COMM_E_NOT_INITED);
    }
    else if(User >= COMM_NUM_OF_USER)
    {
        COMM_DET_REPORT_ERROR(COMM_GETMAXCOMMODE_APIID, COMM_E_WRONG_PARAMETERS);
    }
    else if(NULL_PTR == ComMode)
    {
        COMM_DET_REPORT_ERROR(COMM_GETMAXCOMMODE_APIID, COMM_E_PARAM_POINTER);
    }
    else
    {
        /*set highest mode as the initial value*/
        TempComMode = COMM_FULL_COMMUNICATION;

#if((STD_ON == COMM_MODE_LIMITATION_ENABLED) || (STD_ON == COMM_WAKEUP_INHIBITION_ENABLED))
/*SWS_ComM_00910*/
#if((STD_ON == COMM_PNC_SUPPORT) && (STD_ON == COMM_USED_PNC_ENABLED))
        StartPnc = ComMUserMappingPncStart[User];
        EndPnc = StartPnc + ComMUserMappingPncNum[User];
        for(PncIndex = StartPnc; PncIndex < EndPnc; PncIndex++)
        {
            /*SWS_ComM_00796*/
            Pnc = ComMUserMappingPnc[PncIndex];
            virtualUser = Pnc;
#else
        virtualUser = User;
#endif
            StartChannel = ComMUserMappingChannelStart[virtualUser];
            EndChannel = StartChannel + ComMUserMappingChannelNum[virtualUser];
            for(ChannelIndex = StartChannel; ChannelIndex < EndChannel; ChannelIndex++)
            {
                /*SWS_ComM_00796*/
                Channel = ComMUserMappingChannel[ChannelIndex];
#if(STD_ON == COMM_MODE_LIMITATION_ENABLED)
                if(COMM_IS_LIMIT_TO_NO_COM(Channel))
                {
                    /*SWS_ComM_00374*/
                    TempComMode = COMM_NO_COMMUNICATION;
                    break;
                }
#endif
#if(STD_ON == COMM_WAKEUP_INHIBITION_ENABLED)
                if(COMM_IS_PREVENT_WAKEUP(Channel))
                {
                    /*SWS_ComM_00374*/
                    TempComMode = COMM_NO_COMMUNICATION;
                    break;
                }
#endif
            }
/*SWS_ComM_00910*/
#if((STD_ON == COMM_PNC_SUPPORT) && (STD_ON == COMM_USED_PNC_ENABLED))
            /*SWS_ComM_00374*/
            if(COMM_NO_COMMUNICATION == TempComMode)
            {
                break;
            }
        }
#endif
#endif/*COMM_MODE_LIMITATION_ENABLED is enable, or COMM_WAKEUP_INHIBITION_ENABLED is enable.*/
        *ComMode = TempComMode;
        ret = E_OK;
    }

    return ret;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: ComM_GetRequestedComMode  SWS_ComM_00079
*
* Description:   Function to query the currently requested Communication Mode
*               of the corresponding user.
*
* Inputs:        User Handle of the user who requests a mode
*
* Outputs:       ComMode
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, COMM_CODE) ComM_GetRequestedComMode
(
    ComM_UserHandleType User,
    P2VAR(ComM_ModeType, AUTOMATIC, COMM_APPL_DATA) ComMode
)
{
    /*SWS_ComM_00612*/
    Std_ReturnType ret = E_NOT_OK;

    if(!COMM_IS_INITIALIZED())
    {
        /*SWS_ComM_00858*/
        COMM_DET_REPORT_ERROR(COMM_GETREQUESTEDCOMMODE_APIID, COMM_E_NOT_INITED);
    }
    else if(User >= COMM_NUM_OF_USER)
    {
        COMM_DET_REPORT_ERROR(COMM_GETREQUESTEDCOMMODE_APIID, COMM_E_WRONG_PARAMETERS);
    }
    else if(NULL_PTR == ComMode)
    {
        COMM_DET_REPORT_ERROR(COMM_GETREQUESTEDCOMMODE_APIID, COMM_E_PARAM_POINTER);
    }
    else
    {
        *ComMode = ComM_UserComMode[User];
        ret = E_OK;
    }

    return ret;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: ComM_GetCurrentComMode  SWS_ComM_00083
*
* Description:   Function to query the current Communication Mode.
*
* Inputs:        User Handle of the user who requests a mode
*
* Outputs:       ComMode
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, COMM_CODE) ComM_GetCurrentComMode
(
    ComM_UserHandleType User,
    P2VAR(ComM_ModeType, AUTOMATIC, COMM_APPL_DATA) ComMode
)
{
    NetworkHandleType Channel;
    uint8 ChannelIndex;
    uint8 StartChannel, EndChannel;
    ComM_ModeType ChannelComMode;
    ComM_ModeType TempComMode;
    uint8 virtualUser;
/*SWS_ComM_00910*/
#if((STD_ON == COMM_PNC_SUPPORT) && (STD_ON == COMM_USED_PNC_ENABLED))
    uint8 StartPnc;
    uint8 EndPnc;
    PNCHandleType Pnc;
    uint8 PncIndex;
#endif
    /*SWS_ComM_00612*/
    Std_ReturnType ret = E_NOT_OK;

    if(!COMM_IS_INITIALIZED())
    {
        /*SWS_ComM_00858*/
        COMM_DET_REPORT_ERROR(COMM_GETCURRENTCOMMODE_APIID, COMM_E_NOT_INITED);
    }
    else if(User >= COMM_NUM_OF_USER)
    {
        COMM_DET_REPORT_ERROR(COMM_GETCURRENTCOMMODE_APIID, COMM_E_WRONG_PARAMETERS);
    }
    else if(NULL_PTR == ComMode)
    {
        COMM_DET_REPORT_ERROR(COMM_GETCURRENTCOMMODE_APIID, COMM_E_PARAM_POINTER);
    }
    else
    {
        /*set highest mode as the initial value*/
        TempComMode = COMM_FULL_COMMUNICATION;
/*SWS_ComM_00910*/
#if((STD_ON == COMM_PNC_SUPPORT) && (STD_ON == COMM_USED_PNC_ENABLED))

        StartPnc = ComMUserMappingPncStart[User];
        EndPnc = StartPnc + ComMUserMappingPncNum[User];
        for(PncIndex = StartPnc; PncIndex < EndPnc; PncIndex++)
        {
            /*SWS_ComM_00798*/
            Pnc = ComMUserMappingPnc[PncIndex];
            virtualUser = Pnc;
#else
        virtualUser = User;
#endif
            StartChannel = ComMUserMappingChannelStart[virtualUser];
            EndChannel = StartChannel + ComMUserMappingChannelNum[virtualUser];
            for(ChannelIndex = StartChannel; ChannelIndex < EndChannel; ChannelIndex++)
            {
                /*SWS_ComM_00798*/
                Channel = ComMUserMappingChannel[ChannelIndex];
                /*SWS_ComM_00084*/
                ret = ComM_BusSM_GetCurrentComMode(Channel, &ChannelComMode);
                if(E_OK != ret)
                {
                    break;
                }
                /*SWS_ComM_00176*/
                if(COMM_NO_COMMUNICATION == ChannelComMode)
                {
                    TempComMode = COMM_NO_COMMUNICATION;
                    break;
                }
                /*SWS_ComM_00176*/
                else if(COMM_SILENT_COMMUNICATION == ChannelComMode)
                {
                    TempComMode = COMM_SILENT_COMMUNICATION;
                }
                else
                {
                }

            }
/*SWS_ComM_00910*/
#if((STD_ON == COMM_PNC_SUPPORT) && (STD_ON == COMM_USED_PNC_ENABLED))
            /*SWS_ComM_00176*/
            if((E_OK != ret) || (COMM_NO_COMMUNICATION == TempComMode))
            {
                break;
            }
        }
#endif
        *ComMode = TempComMode;
    }

    return ret;
}
#endif

#if(STD_ON == COMM_WAKEUP_INHIBITION_ENABLED)/*SWS_ComM_00799*/
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: ComM_PreventWakeUp  SWS_ComM_00156
*
* Description:   Changes the inhibition status COMM_NO_WAKEUP for the corresponding channel.
*
* Inputs:        Channel
*                Status
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
/*SWS_ComM_00301*/
FUNC(Std_ReturnType, COMM_CODE) ComM_PreventWakeUp
(
    NetworkHandleType Channel,
    boolean Status
)
{
    /*SWS_ComM_00612*/
    Std_ReturnType ret = E_NOT_OK;

    if(!COMM_IS_INITIALIZED())
    {
        /*SWS_ComM_00858*/
        COMM_DET_REPORT_ERROR(COMM_PREVENTWAKEUP_APIID, COMM_E_NOT_INITED);
    }
    else if(Channel >= COMM_NUM_OF_CHANNEL)
    {
        COMM_DET_REPORT_ERROR(COMM_PREVENTWAKEUP_APIID, COMM_E_WRONG_PARAMETERS);
    }
    else
    {
        SchM_Enter_ComM_COMM_EXCLUSIVE_AREA_7();

        if(TRUE == Status)
        {
            COMM_PREVENT_WAKEUP(Channel);
        }
        else
        {
            COMM_PERMIT_WAKEUP(Channel);
        }
        ComM_UpdateKeepComFlag(Channel);

        SchM_Exit_ComM_COMM_EXCLUSIVE_AREA_7();
#if(STD_ON == COMM_NVM_SUPPORT)
        /*SWS_ComM_00157 SWS_ComM_00103*/
        if(TRUE == ComMNoWakeupNvMStorage[Channel])
        {
            NvM_SetRamBlockStatus(ComMNoWakeupBlockId[Channel], TRUE);
        }
#endif
        ret = E_OK;
    }

    return ret;
}
#endif

#if(STD_ON == COMM_MODE_LIMITATION_ENABLED)/*SWS_ComM_00800 SWS_ComM_00801 SWS_ComM_00802 SWS_ComM_00803*/
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: ComM_LimitChannelToNoComMode  SWS_ComM_00163
*
* Description:   Changes the inhibition status for the channel for changing
*               from COMM_NO_COMMUNICATION to a higher Communication Mode.
* Inputs:        Channel
*                Status
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
/*SWS_ComM_00301*//*SWS_ComM_00488*/
FUNC(Std_ReturnType, COMM_CODE) ComM_LimitChannelToNoComMode
(
    NetworkHandleType Channel,
    boolean Status
)
{
    /*SWS_ComM_00612*/
    Std_ReturnType ret = E_NOT_OK;

    if(!COMM_IS_INITIALIZED())
    {
        /*SWS_ComM_00858*/
        COMM_DET_REPORT_ERROR(COMM_LIMITCHANNELTONOCOMMODE_APIID, COMM_E_NOT_INITED);
    }
    else if(Channel >= COMM_NUM_OF_CHANNEL)
    {
        COMM_DET_REPORT_ERROR(COMM_LIMITCHANNELTONOCOMMODE_APIID, COMM_E_WRONG_PARAMETERS);
    }
    else
    {
        if(TRUE != Status)
        {
            SchM_Enter_ComM_COMM_EXCLUSIVE_AREA_7();

            COMM_UNLIMIT_TO_NO_COM(Channel);
            ComM_UpdateKeepComFlag(Channel);

            SchM_Exit_ComM_COMM_EXCLUSIVE_AREA_7();
        }
        else
        {
            /*SWS_ComM_00842 ignore req if in states other than NetworkRequested*/
            if(COMM_STATE_IS_NETWORK_REQUESTED(Channel))
            {
                SchM_Enter_ComM_COMM_EXCLUSIVE_AREA_7();

                COMM_LIMIT_TO_NO_COM(Channel);
                ComM_UpdateKeepComFlag(Channel);

                SchM_Exit_ComM_COMM_EXCLUSIVE_AREA_7();
            }
        }
        ret = E_OK;
    }

    return ret;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: ComM_LimitECUToNoComMode  SWS_ComM_00124
*
* Description:   Changes the inhibition status for the ECU (=all channels) for changing
*               from COMM_NO_COMMUNICATION to a higher Communication Mode.
* Inputs:        Status
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
/*SWS_ComM_00301*/
FUNC(Std_ReturnType, COMM_CODE) ComM_LimitECUToNoComMode
(
    boolean Status
)
{
    NetworkHandleType Channel;
    /*SWS_ComM_00612*/
    Std_ReturnType ret = E_NOT_OK;

    if(!COMM_IS_INITIALIZED())
    {
        /*SWS_ComM_00858*/
        COMM_DET_REPORT_ERROR(COMM_LIMITECUTONOCOMMODE_APIID, COMM_E_NOT_INITED);
    }
    else
    {
        SchM_Enter_ComM_COMM_EXCLUSIVE_AREA_7();

        if(TRUE != Status)
        {
            for(Channel = 0; Channel < COMM_NUM_OF_CHANNEL; Channel++)
            {
                COMM_UNLIMIT_TO_NO_COM(Channel);
                ComM_UpdateKeepComFlag(Channel);
            }
        }
        else
        {
            for(Channel = 0; Channel < COMM_NUM_OF_CHANNEL; Channel++)
            {
                if(COMM_STATE_IS_NETWORK_REQUESTED(Channel))
                {
                    COMM_LIMIT_TO_NO_COM(Channel);
                    ComM_UpdateKeepComFlag(Channel);
                }
            }
        }

        SchM_Exit_ComM_COMM_EXCLUSIVE_AREA_7();

        ret = E_OK;
    }

    return ret;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: ComM_ReadInhibitCounter  SWS_ComM_00224
*
* Description:   This function returns the amount of rejected COMM_FULL_COMMUNICATION
*               user requests.
* Inputs:        None
*
* Outputs:       CounterValue Amount of rejected COMM_FULL_COMMUNICATION user requests.
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, COMM_CODE) ComM_ReadInhibitCounter
(
    P2VAR(uint16, AUTOMATIC, COMM_APPL_DATA) CounterValue
)
{
    /*SWS_ComM_00612*/
    Std_ReturnType ret = E_NOT_OK;

    if(!COMM_IS_INITIALIZED())
    {
        /*SWS_ComM_00858*/
        COMM_DET_REPORT_ERROR(COMM_READINHIBITCOUNTER_APIID, COMM_E_NOT_INITED);
    }
    else if(NULL_PTR == CounterValue)
    {
        COMM_DET_REPORT_ERROR(COMM_READINHIBITCOUNTER_APIID, COMM_E_PARAM_POINTER);
    }
    else
    {
        *CounterValue = ComMInhibitCounter;
        ret = E_OK;
    }

    return ret;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: ComM_ResetInhibitCounter  SWS_ComM_00108
*
* Description:   This function resets the Inhibited COMM_FULL_COMMUNICATION request Counter.
*
* Inputs:        None
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
/*SWS_ComM_00143*/
FUNC(Std_ReturnType, COMM_CODE) ComM_ResetInhibitCounter
(
    void
)
{
    /*SWS_ComM_00612*/
    Std_ReturnType ret = E_NOT_OK;

    if(!COMM_IS_INITIALIZED())
    {
        /*SWS_ComM_00858*/
        COMM_DET_REPORT_ERROR(COMM_RESETINHIBITCOUNTER_APIID, COMM_E_NOT_INITED);
    }
    else
    {
        ComMInhibitCounter = 0;
#if(STD_ON == COMM_NVM_SUPPORT)
        /*SWS_ComM_00103*/
        NvM_SetRamBlockStatus(ComMInhibitCounterBlockId, TRUE);
#endif
        ret = E_OK;
    }

    return ret;
}
#endif

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: ComM_SetECUGroupClassification  SWS_ComM_00552
*
* Description:   Changes the ECU Group Classification status
*
* Inputs:        Status
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, COMM_CODE) ComM_SetECUGroupClassification
(
    ComM_InhibitionStatusType Status
)
{
#if((STD_ON == COMM_WAKEUP_INHIBITION_ENABLED) || (STD_ON == COMM_MODE_LIMITATION_ENABLED))
    NetworkHandleType Channel;
#endif
    /*SWS_ComM_00612*/
    Std_ReturnType ret = E_NOT_OK;

    if(!COMM_IS_INITIALIZED())
    {
        /*SWS_ComM_00858*/
        COMM_DET_REPORT_ERROR(COMM_RESETINHIBITCOUNTER_APIID, COMM_E_NOT_INITED);
    }
    else
    {
        SchM_Enter_ComM_COMM_EXCLUSIVE_AREA_7();
        ComMEcuGroupClassification = Status;
#if((STD_ON == COMM_WAKEUP_INHIBITION_ENABLED) || (STD_ON == COMM_MODE_LIMITATION_ENABLED))
        for(Channel = 0; Channel < COMM_NUM_OF_CHANNEL; Channel++)
        {
            ComM_UpdateKeepComFlag(Channel);
        }
#endif
        SchM_Exit_ComM_COMM_EXCLUSIVE_AREA_7();

#if(STD_ON == COMM_NVM_SUPPORT)
        /*SWS_ComM_00103*/
        NvM_SetRamBlockStatus(ComMEcuGroupClassificationBlockId, TRUE);
#endif
        ret = E_OK;
    }

    return ret;
}


#if(STD_ON == COMM_VERSION_INFO_API)/*SWS_ComM_00823*/
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: ComM_GetVersionInfo  SWS_ComM_00370
*
* Description:   This function returns the published information
*
* Inputs:        None
*
* Outputs:       VersionInfo  Pointer to where to store the version information
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, COMM_CODE) ComM_GetVersionInfo
(
    P2VAR(Std_VersionInfoType, AUTOMATIC, COMM_APPL_DATA) VersionInfo
)
{
    if(NULL_PTR == VersionInfo)
    {
        COMM_DET_REPORT_ERROR(COMM_GETVERSIONINFO_APIID, COMM_E_PARAM_POINTER);
    }
    else
    {
        /*SWS_ComM_00822*/
        VersionInfo->vendorID = COMM_VENDOR_ID;
        VersionInfo->moduleID = COMM_MODULE_ID;

        VersionInfo->sw_major_version = COMM_SW_MAJOR_VERSION;
        VersionInfo->sw_minor_version = COMM_SW_MINOR_VERSION;
        VersionInfo->sw_patch_version = COMM_SW_PATCH_VERSION;
    }
}
#endif


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: ComM_Init  SWS_ComM_00146
*
* Description:   Initializes the AUTOSAR Communication Manager and restarts the
*               internal state machines.
*
* Inputs:        ConfigPtr Pointer to the selected configuration set.
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, COMM_CODE) ComM_Init
(
    P2CONST(ComM_ConfigType, AUTOMATIC, COMM_CONST) ConfigPtr
)
{
    NetworkHandleType Channel;
    ComM_UserHandleType User;
/*SWS_ComM_00910*/
#if((STD_ON == COMM_PNC_SUPPORT) && (STD_ON == COMM_USED_PNC_ENABLED))
    PNCHandleType Pnc;
    ComM_UserHandleType VirtualUser, PncUser;
    uint8 PncStart;
    uint8 PncUserStart;
    uint8 PncEnd;
    uint8 PncUserEnd;
    uint8 PncIndex;
    uint8 PncUserIndex;
    uint8 ChannelStart;
    uint8 ChannelEnd;
    uint8 ChannelIndex;
    uint8 ChannelPncStart;
    uint8 ChannelPncEnd;
    uint8 ChannelPncIndex;
    uint8 ChannelPnc;
#endif

    /*Cfg compatibility check*/
#if(STD_ON == COMM_DEV_ERROR_DETECT)
/*SWS_ComM_00910*/
#if((STD_ON == COMM_PNC_SUPPORT) && (STD_ON == COMM_USED_PNC_ENABLED))
    for(Pnc = 0; Pnc < COMM_NUM_OF_PNC; Pnc++)
    {
        VirtualUser = Pnc;
        if((ComMUserMappingChannelStart[VirtualUser] + ComMUserMappingChannelNum[VirtualUser]) > COMM_MAX_USER_MAPPING_CHANNEL)
        {
            COMM_DET_REPORT_ERROR(COMM_INIT_APIID, COMM_E_INIT_FAILED);
        }
    }
#endif

    for(User = 0; User < COMM_NUM_OF_USER; User++)
    {
/*SWS_ComM_00910*/
#if((STD_ON == COMM_PNC_SUPPORT) && (STD_ON == COMM_USED_PNC_ENABLED))
        if((ComMUserMappingPncStart[User] + ComMUserMappingPncNum[User]) > COMM_MAX_USER_MAPPING_PNC)
        {
            COMM_DET_REPORT_ERROR(COMM_INIT_APIID, COMM_E_INIT_FAILED);
        }

        /*Check if the channel is associated with both the PNC and the user on this PNC.*/
        if(((COMM_NUM_OF_PNC - COMM_NUM_OF_ACTUALPNC) > 0) && (COMM_NUM_OF_ACTUALPNC > 0))
        {
            PncStart = ComMUserMappingPncStart[User];
            PncEnd = PncStart + ComMUserMappingPncNum[User];
            for(PncIndex = PncStart; PncIndex < PncEnd; PncIndex++)
            {
                Pnc = ComMUserMappingPnc[PncIndex];
                /*The pnc is a virtual pnc.*/
                if(Pnc >= COMM_NUM_OF_ACTUALPNC)
                {
                    ChannelStart = ComMUserMappingChannelStart[Pnc];
                    ChannelEnd = ChannelStart + ComMUserMappingChannelNum[Pnc];
                    for(ChannelIndex = ChannelStart; ChannelIndex < ChannelEnd; ChannelIndex++)
                    {
                        Channel = ComMUserMappingChannel[ChannelIndex];

                        /*check the pnc on the channel*/
                        ChannelPncStart = ComMChannelMappingPncStart[Channel];
                        ChannelPncEnd = ChannelPncStart + ComMChannelMappingPncNum[Channel];
                        for(ChannelPncIndex = ChannelPncStart; ChannelPncIndex < ChannelPncEnd; ChannelPncIndex++)
                        {
                            ChannelPnc = ComMChannelMappingPnc[ChannelPncIndex];
                            /*The pnc is an actual pnc.*/
                            if(ChannelPnc < COMM_NUM_OF_ACTUALPNC)
                            {
                                /*check the user on the pnc*/
                                PncUserStart = ComMPncMappingUserStart[ChannelPnc];
                                PncUserEnd = PncUserStart + ComMPncMappingUserNum[ChannelPnc];
                                for(PncUserIndex = PncUserStart; PncUserIndex < PncUserEnd; PncUserIndex++)
                                {
                                    PncUser = ComMPncMappingUser[PncUserIndex];
                                    if(PncUser == User)
                                    {
                                        COMM_DET_REPORT_ERROR(COMM_INIT_APIID, COMM_E_INIT_FAILED);
                                    }
                                }
                            }
                        }

                    }
                }
            }
        }
#else
#if((STD_OFF == COMM_NMVARIANT_PASSIVE_ENABLED) || (STD_ON == COMM_NMVARIANT_ENABLED))
        if(ComMUserMappingChannelStart[User] + ComMUserMappingChannelNum[User] > COMM_MAX_USER_MAPPING_CHANNEL)
        {
            COMM_DET_REPORT_ERROR(COMM_INIT_APIID, COMM_E_INIT_FAILED);
        }
#endif
#endif
    }
    for(Channel = 0; Channel < COMM_NUM_OF_CHANNEL; Channel++)
    {
#if((STD_OFF == COMM_NMVARIANT_PASSIVE_ENABLED) || (STD_ON == COMM_NMVARIANT_ENABLED))
        if(ComMChannelMappingUserStart[Channel] + ComMChannelMappingUserNum[Channel] > COMM_MAX_CHANNEL_MAPPING_USER)
        {
            COMM_DET_REPORT_ERROR(COMM_INIT_APIID, COMM_E_INIT_FAILED);
        }
#endif
        /*ECUC_ComM_00568*/
#if(STD_ON == COMM_NM_PASSIVE_MODE_ENABLED)
        if(COMM_IS_NMVARIANT_FULL(Channel))
        {
            COMM_DET_REPORT_ERROR(COMM_INIT_APIID, COMM_E_INIT_FAILED);
        }
/*SWS_ComM_00910*/
#if((STD_ON == COMM_PNC_SUPPORT) && (STD_ON == COMM_USED_PNC_ENABLED))
        /*Check if the Pnc on the passive channel has a User, and if so, report a DET error.*/
        if(COMM_IS_NMVARIANT_PASSIVE(Channel))
        {
            ChannelPncStart = ComMChannelMappingPncStart[Channel];
            ChannelPncEnd = ChannelPncStart + ComMChannelMappingPncNum[Channel];
            for(ChannelPncIndex = ChannelPncStart; ChannelPncIndex < ChannelPncEnd; ChannelPncIndex++)
            {
                ChannelPnc = ComMChannelMappingPnc[ChannelPncIndex];
                for(User = 0; User < COMM_NUM_OF_USER; User++)
                {
                    PncStart = ComMUserMappingPncStart[User];
                    PncEnd = PncStart + ComMUserMappingPncNum[User];
                    for(PncIndex = PncStart; PncIndex < PncEnd; PncIndex++)
                    {
                        Pnc = ComMUserMappingPnc[PncIndex];
                        if(Pnc == ChannelPnc)
                        {
                            COMM_DET_REPORT_ERROR(COMM_INIT_APIID, COMM_E_INIT_FAILED);
                        }
                    }
                }
            }

        }
#endif
#else
        if(COMM_IS_NMVARIANT_PASSIVE(Channel))
        {
            COMM_DET_REPORT_ERROR(COMM_INIT_APIID, COMM_E_INIT_FAILED);
        }
#endif
#if(STD_ON == COMM_NMVARIANT_NONE_ENABLED)
        if(COMM_IS_BUS_TYPE_INTERNAL(Channel) && (!COMM_IS_NMVARIANT_NONE(Channel)))
        {
            COMM_DET_REPORT_ERROR(COMM_INIT_APIID, COMM_E_INIT_FAILED);
        }
#endif
#if((STD_ON == COMM_NMVARIANT_LIGHT_ENABLED) || (STD_ON == COMM_NMVARIANT_NONE_ENABLED))
        if(COMM_TMIN_FCMD_INVALID == ComMTMinFullComModeDuration[Channel])
        {
            COMM_DET_REPORT_ERROR(COMM_INIT_APIID, COMM_E_INIT_FAILED);
        }
#endif
#if(STD_ON == COMM_NMVARIANT_LIGHT_ENABLED)
        if(COMM_NM_LIGHT_TO_INVALID == ComMNmLightTimeout[Channel])
        {
            COMM_DET_REPORT_ERROR(COMM_INIT_APIID, COMM_E_INIT_FAILED);
        }
#endif
    }
#endif

#if(COMM_CONFIG_VARIANTS == STD_CONFIG_VARIANTS_POSTBUILD)
    if(NULL_PTR == ConfigPtr)
    {
        COMM_DET_REPORT_ERROR(COMM_INIT_APIID, COMM_E_PARAM_POINTER);
    }
    else
#else
    (void)ConfigPtr;
#endif
    {
#if(COMM_CONFIG_VARIANTS == STD_CONFIG_VARIANTS_POSTBUILD)
        ComM_ConfigSet = ConfigPtr;
#endif

#if((STD_OFF == COMM_NMVARIANT_PASSIVE_ENABLED) || (STD_ON == COMM_NMVARIANT_ENABLED))
        /*Reset all User ComMode*/
        for(User = 0; User < COMM_NUM_OF_USER; User++)
        {
            ComM_UserComMode[User] = COMM_NO_COMMUNICATION;
        }
#endif

#if(STD_ON == COMM_MODE_LIMITATION_ENABLED)
        ComM_RestoreNoComVal();
#endif

        /*Without NvM we should initialize the non-volatile variables here,
          otherwise NvM had done it before. SWS_ComM_00793 SWS_ComM_00864 */
#if(STD_OFF == COMM_NVM_SUPPORT)
#if(STD_ON == COMM_MODE_LIMITATION_ENABLED)
        ComM_RestoreInhibitCounter();
#endif
#if(STD_ON == COMM_WAKEUP_INHIBITION_ENABLED)
        ComM_RestoreNoWakeupVal();
#endif
        ComM_RestoreEcuGroupClassificationVal();
#endif

        for(Channel = 0; Channel < COMM_NUM_OF_CHANNEL; Channel++)
        {
            /*SWS_ComM_00884*/
            COMM_SET_COM_DISALLOWED(Channel);

#if((STD_ON == COMM_NMVARIANT_LIGHT_ENABLED) || (STD_ON == COMM_NMVARIANT_NONE_ENABLED))
            COMM_STOP_TMIN_FCMD_TIMER(Channel);
#endif
#if(STD_ON == COMM_NMVARIANT_LIGHT_ENABLED)
            COMM_STOP_NM_LIGHT_TO_TIMER(Channel);
#endif

            /*SWS_ComM_00485*/
            ComM_ChannelNoComEnter(Channel);
        }
/*SWS_ComM_00910*/
#if((STD_ON == COMM_PNC_SUPPORT) && (STD_ON == COMM_USED_PNC_ENABLED))
        ComM_InitPnc();
#endif

        COMM_SET_INITIALIZED();
    }
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: ComM_DeInit  SWS_ComM_00147
*
* Description:   This API de-initializes the AUTOSAR Communication Manager
*
* Inputs:        None
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, COMM_CODE) ComM_DeInit
(
    void
)
{
    NetworkHandleType Channel;

    /*SWS_ComM_00794 caller need to make sure all the state machine has been resetted*/

    for(Channel = 0; Channel < COMM_NUM_OF_CHANNEL; Channel++)
    {
#if((STD_ON == COMM_NMVARIANT_LIGHT_ENABLED) || (STD_ON == COMM_NMVARIANT_NONE_ENABLED))
        COMM_STOP_TMIN_FCMD_TIMER(Channel);
#endif
#if(STD_ON == COMM_NMVARIANT_LIGHT_ENABLED)
        COMM_STOP_NM_LIGHT_TO_TIMER(Channel);
#endif
        COMM_MODE_SET_NO_COM(Channel);
        COMM_STATE_SET_NO_PENDING_REQUEST(Channel);
    }
/*SWS_ComM_00910*/
#if((STD_ON == COMM_PNC_SUPPORT) && (STD_ON == COMM_USED_PNC_ENABLED))
    ComM_DeInitPnc();
#endif

#if(STD_ON == COMM_NVM_SUPPORT)
    /*SWS_ComM_00865*/
#if(STD_ON == COMM_WAKEUP_INHIBITION_ENABLED)
    for(Channel = 0; Channel < COMM_NUM_OF_CHANNEL; Channel++)
    {
        if(TRUE == ComMNoWakeupNvMStorage[Channel])
        {
            /*SWS_ComM_00103*/
            NvM_SetRamBlockStatus(ComMNoWakeupBlockId[Channel], TRUE);
        }
    }
#endif
    NvM_SetRamBlockStatus(ComMEcuGroupClassificationBlockId, TRUE);
#if(STD_ON == COMM_MODE_LIMITATION_ENABLED)
    NvM_SetRamBlockStatus(ComMInhibitCounterBlockId, TRUE);
#endif
#endif

    COMM_SET_UNINITIALIZED();
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: ComM_GetState  SWS_ComM_00872
*
* Description:   Return current state, including sub-state, of the ComM channel state machine.
*
* Inputs:        Channel The Network Channel for the requested state of ComM state
*                         machine.
*
* Outputs:       State State of the ComM channel state machine
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, COMM_CODE) ComM_GetState
(
    NetworkHandleType Channel,
    P2VAR(ComM_StateType, AUTOMATIC, COMM_APPL_DATA) State
)
{
    /*SWS_ComM_00612*/
    Std_ReturnType ret = E_NOT_OK;
    
    if(!COMM_IS_INITIALIZED())
    {
        /*SWS_ComM_00858*/
        COMM_DET_REPORT_ERROR(COMM_GETSTATE_APIID, COMM_E_NOT_INITED);
    }
    else if(Channel >= COMM_NUM_OF_CHANNEL)
    {
        COMM_DET_REPORT_ERROR(COMM_GETSTATE_APIID, COMM_E_WRONG_PARAMETERS);
    }
    else if(NULL_PTR == State)
    {
        COMM_DET_REPORT_ERROR(COMM_GETSTATE_APIID, COMM_E_PARAM_POINTER);
    }
    else
    {
        *State = COMM_GET_STATE(Channel);
        ret = E_OK;
    }

    return ret;
}


/*******************************************************************************
*   Callback Functions
*******************************************************************************/
#if(STD_ON == COMM_NM_SUPPORT)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: ComM_Nm_NetworkStartIndication  SWS_ComM_00383
*
* Description:     Indication that a NM-message has been received in the Bus Sleep
*               Mode, what indicates that some nodes in the network have already
*               entered the Network Mode
*
* Inputs:         Channel
*
* Outputs:         None
*
* Limitations:     None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, COMM_CODE) ComM_Nm_NetworkStartIndication
(
    NetworkHandleType Channel
)
{
    /*SWS_ComM_00805*/
    if(!COMM_IS_INITIALIZED())
    {
        COMM_DET_REPORT_ERROR(COMM_NM_NETWORKSTARTINDICATION_APIID, COMM_E_NOT_INITED);
    }
    else if(Channel >= COMM_NUM_OF_CHANNEL)
    {
        COMM_DET_REPORT_ERROR(COMM_NM_NETWORKSTARTINDICATION_APIID, COMM_E_WRONG_PARAMETERS);
    }
    else
    {
        SchM_Enter_ComM_COMM_EXCLUSIVE_AREA_3();
        COMM_SET_NETWORK_START_IND(Channel);
        SchM_Exit_ComM_COMM_EXCLUSIVE_AREA_3();
    }

    return;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: ComM_Nm_NetworkMode  SWS_ComM_00390
*
* Description:     Notification that the network management has entered Network Mode
*
* Inputs:         Channel
*
* Outputs:         None
*
* Limitations:     None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, COMM_CODE) ComM_Nm_NetworkMode
(
    NetworkHandleType Channel
)
{
    /*SWS_ComM_00806*/
    if(!COMM_IS_INITIALIZED())
    {
        COMM_DET_REPORT_ERROR(COMM_NM_NETWORKMODE_APIID, COMM_E_NOT_INITED);
    }
    else if(Channel >= COMM_NUM_OF_CHANNEL)
    {
        COMM_DET_REPORT_ERROR(COMM_NM_NETWORKMODE_APIID, COMM_E_WRONG_PARAMETERS);
    }
    else
    {
        SchM_Enter_ComM_COMM_EXCLUSIVE_AREA_2();
        COMM_SET_NM_NETWORK_MODE(Channel);
        SchM_Exit_ComM_COMM_EXCLUSIVE_AREA_2();
    }

    return;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: ComM_Nm_PrepareBusSleepMode  SWS_ComM_00391
*
* Description:     Notification that the network management has entered Prepare Bus-Sleep Mode
*
* Inputs:         Channel
*
* Outputs:         None
*
* Limitations:     None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, COMM_CODE) ComM_Nm_PrepareBusSleepMode
(
    NetworkHandleType Channel
)
{
    /*SWS_ComM_00808*/
    if(!COMM_IS_INITIALIZED())
    {
        COMM_DET_REPORT_ERROR(COMM_NM_PREPAREBUSSLEEPMODE_APIID, COMM_E_NOT_INITED);
    }
    else if(Channel >= COMM_NUM_OF_CHANNEL)
    {
        COMM_DET_REPORT_ERROR(COMM_NM_PREPAREBUSSLEEPMODE_APIID, COMM_E_WRONG_PARAMETERS);
    }
    else
    {
        SchM_Enter_ComM_COMM_EXCLUSIVE_AREA_2();
        COMM_SET_NM_PBS_MODE(Channel);
        SchM_Exit_ComM_COMM_EXCLUSIVE_AREA_2();
    }

    return;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: ComM_Nm_BusSleepMode  SWS_ComM_00392
*
* Description:     Notification that the network management has entered Bus-Sleep Mode
*
* Inputs:         Channel
*
* Outputs:         None
*
* Limitations:     None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, COMM_CODE) ComM_Nm_BusSleepMode
(
    NetworkHandleType Channel
)
{
    /*SWS_ComM_00810*/
    if(!COMM_IS_INITIALIZED())
    {
        COMM_DET_REPORT_ERROR(COMM_NM_BUSSLEEPMODE_APIID, COMM_E_NOT_INITED);
    }
    else if(Channel >= COMM_NUM_OF_CHANNEL)
    {
        COMM_DET_REPORT_ERROR(COMM_NM_BUSSLEEPMODE_APIID, COMM_E_WRONG_PARAMETERS);
    }
    else
    {
        SchM_Enter_ComM_COMM_EXCLUSIVE_AREA_2();
        COMM_SET_NM_BUS_SLEEP_MODE(Channel);
        SchM_Exit_ComM_COMM_EXCLUSIVE_AREA_2();
    }

    return;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: ComM_Nm_RestartIndication  SWS_ComM_00792
*
* Description:     If NmIf has started to shut down the coordinated busses, AND
*               not all coordinated busses have indicated bus sleep state, AND
*               on at least on one of the coordinated busses NM is restarted, THEN
*               the NM Interface shall call the callback function
*               ComM_Nm_RestartIndication with the nmNetworkHandle of the
*               channels which have already indicated bus sleep state.
*
* Inputs:         Channel
*
* Outputs:         None
*
* Limitations:     None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, COMM_CODE) ComM_Nm_RestartIndication
(
    NetworkHandleType Channel
)
{
    /*SWS_ComM_00812*/
    if(!COMM_IS_INITIALIZED())
    {
        COMM_DET_REPORT_ERROR(COMM_NM_RESTARTINDICATION_APIID, COMM_E_NOT_INITED);
    }
    else if(Channel >= COMM_NUM_OF_CHANNEL)
    {
        COMM_DET_REPORT_ERROR(COMM_NM_RESTARTINDICATION_APIID, COMM_E_WRONG_PARAMETERS);
    }
    else
    {
        SchM_Enter_ComM_COMM_EXCLUSIVE_AREA_3();
        COMM_SET_NM_RESTART_IND(Channel);
        SchM_Exit_ComM_COMM_EXCLUSIVE_AREA_3();
    }

    return;
}
#endif

#if(STD_ON == COMM_DCM_SUPPORT)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: ComM_DCM_ActiveDiagnostic  SWS_ComM_00873
*
* Description:     Indication of active diagnostic by the DCM
*
* Inputs:         Channel Channel needed for Diagnostic communication
*
* Outputs:         None
*
* Limitations:     None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, COMM_CODE) ComM_DCM_ActiveDiagnostic
(
    NetworkHandleType Channel
)
{
    if(!COMM_IS_INITIALIZED())
    {
        COMM_DET_REPORT_ERROR(COMM_DCM_ACTIVEDIAGNOSTIC_APIID, COMM_E_NOT_INITED);
    }
    else if(Channel >= COMM_NUM_OF_CHANNEL)
    {
        COMM_DET_REPORT_ERROR(COMM_DCM_ACTIVEDIAGNOSTIC_APIID, COMM_E_WRONG_PARAMETERS);
    }
    else
    {
        SchM_Enter_ComM_COMM_EXCLUSIVE_AREA_4();
        /*if already in an Active Diagnostic, ignore*/
        if(!COMM_IS_ACTIVE_DIAG(Channel))
        {
            COMM_ACTIVE_DIAG(Channel);
            ComM_UpdateKeepComFlag(Channel);
        }
        SchM_Exit_ComM_COMM_EXCLUSIVE_AREA_4();
    }

    return;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: ComM_DCM_InactiveDiagnostic  SWS_ComM_00874
*
* Description:     Indication of inactive diagnostic by the DCM.
*
* Inputs:         Channel Channel no longer needed for Diagnostic communication
*
* Outputs:         None
*
* Limitations:     None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, COMM_CODE) ComM_DCM_InactiveDiagnostic
(
    NetworkHandleType Channel
)
{
    if(!COMM_IS_INITIALIZED())
    {
        COMM_DET_REPORT_ERROR(COMM_DCM_INACTIVEDIAGNOSTIC_APIID, COMM_E_NOT_INITED);
    }
    else if(Channel >= COMM_NUM_OF_CHANNEL)
    {
        COMM_DET_REPORT_ERROR(COMM_DCM_INACTIVEDIAGNOSTIC_APIID, COMM_E_WRONG_PARAMETERS);
    }
    else
    {
        SchM_Enter_ComM_COMM_EXCLUSIVE_AREA_4();
        /*if not in an Active Diagnostic, ignore*/
        if(COMM_IS_ACTIVE_DIAG(Channel))
        {
            COMM_INACTIVE_DIAG(Channel);
            ComM_UpdateKeepComFlag(Channel);
        }
        SchM_Exit_ComM_COMM_EXCLUSIVE_AREA_4();
    }

    return;
}
#endif

#if(STD_ON == COMM_ECUM_SUPPORT)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: ComM_EcuM_WakeUpIndication  SWS_ComM_00275
*
* Description:     Notification of a wake up on the corresponding channel.
*
* Inputs:         Channel
*
* Outputs:         None
*
* Limitations:     None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, COMM_CODE) ComM_EcuM_WakeUpIndication
(
    NetworkHandleType Channel
)
{
/*SWS_ComM_00910*/
#if((STD_ON == COMM_PNC_SUPPORT) && (STD_ON == COMM_USED_PNC_ENABLED) && (STD_ON == COMM_SYNCHRONOUS_WAKE_UP))
    PNCHandleType PncIndex;
#endif

    /*SWS_ComM_00814*/
    if(!COMM_IS_INITIALIZED())
    {
        COMM_DET_REPORT_ERROR(COMM_ECUM_WAKEUPINDICATION_APIID, COMM_E_NOT_INITED);
    }
    else if(Channel >= COMM_NUM_OF_CHANNEL)
    {
        COMM_DET_REPORT_ERROR(COMM_ECUM_WAKEUPINDICATION_APIID, COMM_E_WRONG_PARAMETERS);
    }
    else
    {
        SchM_Enter_ComM_COMM_EXCLUSIVE_AREA_5();
        COMM_SET_WKUP_IND(Channel);
/*SWS_ComM_00910*/        
#if((STD_ON == COMM_PNC_SUPPORT) && (STD_ON == COMM_USED_PNC_ENABLED) && (STD_ON == COMM_SYNCHRONOUS_WAKE_UP))
        for(PncIndex = 0; PncIndex < COMM_NUM_OF_PNC; PncIndex++)
        {
            COMM_SET_PNC_WAKEUP_FLAG(PncIndex);
        }
#endif
        SchM_Exit_ComM_COMM_EXCLUSIVE_AREA_5();
    }

    return;
}
#endif

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: ComM_CommunicationAllowed  SWS_ComM_00871
*
* Description:     indicate to ComM when communication is allowed
*
* Inputs:         Channel
*                Allowed
*
* Outputs:         None
*
* Limitations:     None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, COMM_CODE) ComM_CommunicationAllowed
(
    NetworkHandleType Channel,
    boolean Allowed
)
{
    if(!COMM_IS_INITIALIZED())
    {
        COMM_DET_REPORT_ERROR(COMM_COMMUNICATIONALLOWED_APIID, COMM_E_NOT_INITED);
    }
    else if(Channel >= COMM_NUM_OF_CHANNEL)
    {
        COMM_DET_REPORT_ERROR(COMM_COMMUNICATIONALLOWED_APIID, COMM_E_WRONG_PARAMETERS);
    }
    else
    {
        SchM_Enter_ComM_COMM_EXCLUSIVE_AREA_6();
        /*SWS_ComM_00885*/
        if(TRUE == Allowed)
        {
            COMM_SET_COM_ALLOWED(Channel);
        }
        else
        {
            COMM_SET_COM_DISALLOWED(Channel);
        }

        SchM_Exit_ComM_COMM_EXCLUSIVE_AREA_6();
    }

    return;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: ComM_BusSM_ModeIndication  SWS_ComM_00675
*
* Description:     Indication of the actual bus mode by the corresponding Bus State Manager
*
* Inputs:         Channel
*                Allowed
*
* Outputs:         None
*
* Limitations:     None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, COMM_CODE) ComM_BusSM_ModeIndication
(
    NetworkHandleType Channel,
    P2VAR(ComM_ModeType, AUTOMATIC, COMM_VAR) ComMode
)
{
#if(STD_ON == COMM_NM_SUPPORT)
    boolean NmPassiveStartUpFlg = FALSE;
#endif

    /*SWS_ComM_00816*/
    if(!COMM_IS_INITIALIZED())
    {
        COMM_DET_REPORT_ERROR(COMM_BUSSM_MODEINDICATION_APIID, COMM_E_NOT_INITED);
    }
    else if(Channel >= COMM_NUM_OF_CHANNEL)
    {
        COMM_DET_REPORT_ERROR(COMM_BUSSM_MODEINDICATION_APIID, COMM_E_WRONG_PARAMETERS);
    }
    else if(NULL_PTR == ComMode)
    {
        COMM_DET_REPORT_ERROR(COMM_BUSSM_MODEINDICATION_APIID, COMM_E_PARAM_POINTER);
    }
    else
    {
        if(*ComMode == COMM_GET_MODE(Channel))
        {
#if(STD_ON == COMM_DCM_SUPPORT)
            /*SWS_ComM_00266*/
            switch(*ComMode)
            {
                case COMM_NO_COMMUNICATION:
                    Dcm_ComM_NoComModeEntered(Channel);
                    break;
                    /*SWS_ComM_00868*/
                case COMM_SILENT_COMMUNICATION:
                    Dcm_ComM_SilentComModeEntered(Channel);
                    break;
                case COMM_FULL_COMMUNICATION:
                    Dcm_ComM_FullComModeEntered(Channel);
                    break;
                default:
                    break;
            }
#endif
            if(COMM_FULL_COMMUNICATION == *ComMode)
            {
#if(STD_ON == COMM_ECUM_SUPPORT)
                /*SWS_ComM_00665*/
                if(COMM_IS_WAKEN(Channel))
                {
                    COMM_CLR_WKUP_IND(Channel);
#if(STD_ON == COMM_NM_SUPPORT)
                    NmPassiveStartUpFlg = TRUE;
#endif
                }
#endif
#if(STD_ON == COMM_NM_SUPPORT)
                /*SWS_ComM_00902*/
                if(COMM_IS_NM_RESTARTED(Channel))
                {
                    COMM_CLR_NM_RESTART_IND(Channel);
                    NmPassiveStartUpFlg = TRUE;
                }
                /*SWS_ComM_00903 SWS_ComM_00583 race condition error*/
                if(COMM_IS_NETWORK_STARTED(Channel))
                {
                    COMM_CLR_NETWORK_START_IND(Channel);
                    NmPassiveStartUpFlg = TRUE;
                }
                if(TRUE == NmPassiveStartUpFlg)
                {
                    if((COMM_IS_NMVARIANT_FULL(Channel)) || (COMM_IS_NMVARIANT_PASSIVE(Channel)))
                    {
                        /*SWS_ComM_00261*/
                        Nm_PassiveStartUp(ComMMappingChannelToNm[Channel]);
                    }
                }
#endif

#if(STD_ON == COMM_NMVARIANT_FULL_ENABLED)
                /*SWS_ComM_00869 SWS_ComM_00870*/
                if(COMM_IS_NMVARIANT_FULL(Channel))
                {
                    if(COMM_IS_KEEP_COM(Channel))
                    {
                        /*SWS_ComM_00261*/
                        Nm_NetworkRequest(ComMMappingChannelToNm[Channel]);
                    }
                }
#endif
            }
        }
    }

    return;
}


/*******************************************************************************
*    Scheduled Functions
*******************************************************************************/
#if((STD_ON == COMM_NMVARIANT_LIGHT_ENABLED) || (STD_ON == COMM_NMVARIANT_NONE_ENABLED))
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: ComM_TimerMainFunction
*
* Description:     Main function of the Timers
*
* Inputs:          None
*
* Outputs:         None
*
* Limitations:     None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, COMM_CODE) ComM_TimerMainFunction
(
    NetworkHandleType Channel
)
{
    if(COMM_STATE_IS_NETWORK_REQUESTED(Channel))
    {
        if(COMM_IS_NMVARIANT_LIGHT(Channel) || COMM_IS_NMVARIANT_NONE(Channel))
        {
            if(!COMM_IS_TMIN_FCMD_TIMER_EXP(Channel))
            {
                COMM_DEC_TMIN_FCMD_TIMER(Channel);
            }
        }
    }
#if(STD_ON == COMM_NMVARIANT_LIGHT_ENABLED)
    if(COMM_STATE_IS_READY_SLEEP(Channel))
    {
        if(COMM_IS_NMVARIANT_LIGHT(Channel))
        {
            if(!COMM_IS_NM_LIGHT_TO_TIMER_EXP(Channel))
            {
                COMM_DEC_NM_LIGHT_TO_TIMER(Channel);
            }
        }
    }
#endif

}
#endif
/*SWS_ComM_00910*/
#if((STD_ON == COMM_PNC_SUPPORT) && (STD_ON == COMM_USED_PNC_ENABLED))

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: ComM_InitPnc
*
* Description:     Initialize Pnc
*
* Inputs:          void
*
* Outputs:         None
*
* Limitations:     None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, COMM_CODE) ComM_InitPnc
(
    void
)
{
    PNCHandleType Pnc;
    uint8 PncIndex;
    uint8 SigIndex;
#if (STD_ON == COMM_PNC_NM_REQUEST)
    uint8 Channel;
#endif

    for(PncIndex = 0; PncIndex < COMM_MAX_USER_MAPPING_PNC; PncIndex++)
    {
        ComMUserMappingPncModeReq[PncIndex] = COMM_PNC_NO_COMMUNICATION;
    }
    for(SigIndex = 0; SigIndex < COMM_EIRA_SIG_LENGTH; SigIndex++)
    {
        ComM_EIRATxValue[SigIndex] = 0;
    }
#if (STD_ON == COMM_PNC_NM_REQUEST)
    for(Channel = 0; Channel < COMM_NUM_OF_CHANNEL; Channel++)
    {
        COMM_CLR_NM_REQUEST_MANDATORY(Channel);
    }
#endif
    for(Pnc = 0; Pnc < COMM_NUM_OF_PNC; Pnc++)
    {
        COMM_STOP_PNC_PREPARE_SLEEP_TIMER(Pnc);
        COMM_RESET_USER_REQUEST_PNC(Pnc);
        COMM_CLR_EIRA_OF_PNC(Pnc);
        /*SWS_ComM_00926 SWS_ComM_00927*/
        ComM_PncNoComEnter(Pnc);
    }

}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: ComM_DeInitPnc
*
* Description:     Deinitialize Pnc
*
* Inputs:          void
*
* Outputs:         None
*
* Limitations:     None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, COMM_CODE) ComM_DeInitPnc
(
    void
)
{
    PNCHandleType Pnc;

    for(Pnc = 0; Pnc < COMM_NUM_OF_PNC; Pnc++)
    {
        COMM_STOP_PNC_PREPARE_SLEEP_TIMER(Pnc);
        ComM_PncNoComEnter(Pnc);
    }
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: ComM_TimerMainFunctionPnc
*
* Description:     Main function of the Timers
*
* Inputs:          Pnc
*
* Outputs:         None
*
* Limitations:     None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, COMM_CODE) ComM_TimerMainFunctionPnc
(
    PNCHandleType Pnc
)
{
    if(COMM_PNCSTATE_IS_PREPARE_SLEEP(Pnc))
    {
        if(!COMM_IS_PNC_PREPARE_SLEEP_TIMER_EXP(Pnc))
        {
            COMM_DEC_PNC_PREPARE_SLEEP_TIMER(Pnc);
        }
    }
}

/********************************************************************************
* Function Name: ComM_MainFunctionPnc
*
* Description:     Main function of the Pnc
*
* Inputs:          Pnc
*
* Outputs:         None
*
* Limitations:     None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, COMM_CODE) ComM_MainFunctionPnc
(
    PNCHandleType Pnc
)
{
    ComM_EIRAReceiveUpdate();
    ComM_TimerMainFunctionPnc(Pnc);
    /*SWS_ComM_00978*/
    switch(COMM_GET_PNCSTATE(Pnc))
    {
        case COMM_PNC_NO_COMMUNICATION:
            ComM_PncNoComProc(Pnc);
            break;
        case COMM_PNC_PREPARE_SLEEP:
            ComM_PncPrepareSleepProc(Pnc);
            break;
        case COMM_PNC_READY_SLEEP:
            ComM_PncReadySleepProc(Pnc);
            break;
        case COMM_PNC_REQUESTED:
            ComM_PncRequestedProc(Pnc);
            break;
        default:
            break;

    }
}



/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: ComM_EIRAReceiveUpdate
*
* Description:     Update the EIRA value of Pnc accoding to the received EIRA sigal.
*
* Inputs:          None
*
* Outputs:         None
*
* Limitations:     None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, COMM_CODE) ComM_EIRAReceiveUpdate
(
    void
)
{
    PNCHandleType Pnc;
    ComM_PncIdType PncID;
    uint8 PncByteIndex;
    uint8 PncBitIndex;
    uint8 Temp;
    /*SWS_ComM_00982*/
    uint8 EIRARx[COMM_EIRA_SIG_LENGTH];

    if(TRUE == ComM_EIRAUpdateFlag)
    {
        ComM_EIRAUpdateFlag = FALSE;
        /*SWS_ComM_00984*/
        Com_ReceiveSignal((Com_SignalIdType)COMM_EIRA_RECE_SIG_ID, EIRARx);
        for(Pnc = 0; Pnc < COMM_NUM_OF_ACTUALPNC; Pnc++)
        {
            /* update the EIRA State according to the received EIRA */

            PncID = COMM_GET_PNCID(Pnc);
            PncByteIndex = COMM_GET_PNC_BYTE_INDEX(PncID);
            PncBitIndex = COMM_GET_PNC_BIT_INDEX(PncID);
            Temp = EIRARx[PncByteIndex] & ((uint8)1 << PncBitIndex);
            if(Temp > 0)
            {
                /*SWS_ComM_00944*//*SWS_ComM_00971*/
                COMM_SET_EIRA_OF_PNC(Pnc);
            }
            else
            {
                /*SWS_ComM_00971*/
                COMM_CLR_EIRA_OF_PNC(Pnc);
            }

        }
    }
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: ComM_PncNoComProc
*
* Description:   Process actions in PNC sub state PNC_NO_COMMUNICATION
*
* Inputs:        Pnc
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, COMM_CODE) ComM_PncNoComProc
(
    PNCHandleType Pnc
)
{
    if(COMM_IS_USER_REQUEST_PNC_EXIST(Pnc))
    {
        /*SWS_ComM_00932*/
        ComM_PncRequestedEnter(Pnc);
    }
    else if(COMM_IS_EIRA_OF_PNC_VALID(Pnc))
    {
        /*SWS_ComM_00933*/
        ComM_PncReadySleepEnter(Pnc);
    }
    else
    {
    /*SWS_ComM_00990*/
#if((STD_ON == COMM_SYNCHRONOUS_WAKE_UP) && (STD_ON == COMM_ECUM_SUPPORT))
        /*SWS_ComM_00931*/
        if(COMM_IS_PNC_WAKEUP_VALID(Pnc))
        {
            COMM_CLR_PNC_WAKEUP_FLAG(Pnc);
            ComM_PncPrepareSleepEnter(Pnc);
        }
#endif
    }


}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: ComM_PncNoComEnter
*
* Description:   Process actions on entry of PNC sub state PNC_NO_COMMUNICATION
*
* Inputs:        Pnc
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, COMM_CODE) ComM_PncNoComEnter
(
    PNCHandleType Pnc
)
{
    COMM_SET_PNCSTATE_NO_COMMUNICATION(Pnc);

#if((STD_ON == COMM_ECUM_SUPPORT) && (STD_ON == COMM_SYNCHRONOUS_WAKE_UP))
    COMM_CLR_PNC_WAKEUP_FLAG(Pnc);
#endif

    if(COMM_IS_INITIALIZED())
    {
        /*notify BswM if the pnc is not a virtual pnc*/
        if(Pnc < COMM_NUM_OF_ACTUALPNC)
        {
            /*SWS_ComM_00976*//*SWS_ComM_00908 SWS_ComM_00829*/
            BswM_ComM_CurrentPNCMode(Pnc, COMM_PNC_NO_COMMUNICATION);
        }
    }
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: ComM_PncRequestedProc
*
* Description:   Process actions in PNC sub state PNC_REQUESTED
*
* Inputs:        Pnc
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, COMM_CODE) ComM_PncRequestedProc
(
    PNCHandleType Pnc
)
{
    if(!COMM_IS_USER_REQUEST_PNC_EXIST(Pnc))
    {
        /*SWS_ComM_00938*/
        ComM_PncReadySleepEnter(Pnc);
    }
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: ComM_PncRequestedEnter
*
* Description:   Process actions on entry of PNC sub state PNC_REQUESTED
*
* Inputs:        Pnc
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, COMM_CODE) ComM_PncRequestedEnter
(
    PNCHandleType Pnc
)
{
    uint16 SignalStartIndex;
    uint16 SignalEndIndex;
    uint16 SignalIndex;
    ComM_PncIdType PncID;
    uint8 PncByteIndex;
    uint8 PncBitIndex;
    uint8 i;
    uint8 EIRATx[COMM_EIRA_SIG_LENGTH];
#if (STD_ON == COMM_PNC_NM_REQUEST)
    uint8 StartChannel;
    uint8 EndChannel;
    uint8 ChannelIndex;
    NetworkHandleType Channel;
#endif

    if(COMM_PNCSTATE_IS_PREPARE_SLEEP(Pnc))
    {
        /*Stop prepare sleep timer*/
        COMM_STOP_PNC_PREPARE_SLEEP_TIMER(Pnc);
    }
    COMM_SET_PNCSTATE_REQUESTED(Pnc);

    if(Pnc < COMM_NUM_OF_ACTUALPNC)
    {
        /* uptate EIRA bit to 1*/
        PncID = COMM_GET_PNCID(Pnc);
        PncByteIndex = COMM_GET_PNC_BYTE_INDEX(PncID);
        PncBitIndex = COMM_GET_PNC_BIT_INDEX(PncID);
        /*SWS_ComM_00982 SWS_ComM_00930*/
        ComM_EIRATxValue[PncByteIndex] |= (uint8)1 << PncBitIndex;

        SignalStartIndex = ComM_PncMappingTxEIRAStart[Pnc];
        SignalEndIndex = SignalStartIndex + ComM_PncMappingTxEIRANum[Pnc];

        for(SignalIndex = SignalStartIndex; SignalIndex < SignalEndIndex; SignalIndex++)
        {
            for(i = 0; i < COMM_EIRA_SIG_LENGTH; i++)
            {
                /*SWS_ComM_00916*/
                EIRATx[i] = ComM_EIRATxValue[i] & Signal_Mask[SignalIndex][i];
            }
            /*SWS_ComM_00975 SWS_ComM_00916 SWS_ComM_00930*/
            Com_SendSignal(ComM_PncMappingTxEIRAId[SignalIndex], EIRATx);
        }

        /*notify BswM*//*SWS_ComM_00976*//*SWS_ComM_00908 SWS_ComM_00829*/
        BswM_ComM_CurrentPNCMode(Pnc, COMM_PNC_REQUESTED);

#if (STD_ON == COMM_PNC_NM_REQUEST)
        StartChannel = ComMUserMappingChannelStart[Pnc];
        EndChannel = StartChannel + ComMUserMappingChannelNum[Pnc];
        for(ChannelIndex = StartChannel; ChannelIndex < EndChannel; ChannelIndex++)
        {
            Channel = ComMUserMappingChannel[ChannelIndex];
            if((COMM_IS_NMVARIANT_FULL(Channel)) && (COMM_IS_PNC_NM_REQUEST_CHANNEL(Channel)))
            {
                COMM_SET_NM_REQUEST_MANDATORY(Channel);
            }
        }
#endif
    }

    /* request COMM_FULL_COMMUNICATION for all configured ComM channels for this PNC *//*SWS_ComM_00827 SWS_ComM_00929*/
    ComM_RequestChannelMode(Pnc, COMM_FULL_COMMUNICATION);
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: ComM_PncReadySleepProc
*
* Description:   Process actions in PNC sub state PNC_READY_SLEEP
*
* Inputs:        Pnc
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, COMM_CODE) ComM_PncReadySleepProc
(
    PNCHandleType Pnc
)
{
    if(COMM_IS_USER_REQUEST_PNC_EXIST(Pnc))
    {
        /*SWS_ComM_00165*/
        ComM_PncRequestedEnter(Pnc);
    }
    else if(!COMM_IS_EIRA_OF_PNC_VALID(Pnc))
    {
        /*SWS_ComM_00940*/
        ComM_PncPrepareSleepEnter(Pnc);
    }
    else
    {
        /*stay in ready sleep*/
    }
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: ComM_PncReadySleepEnter
*
* Description:   Process actions on entry of PNC sub state PNC_READY_SLEEP
*
* Inputs:        Pnc
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, COMM_CODE) ComM_PncReadySleepEnter
(
    PNCHandleType Pnc
)
{
    uint16 SignalStartIndex;
    uint16 SignalEndIndex;
    uint16 SignalIndex;
    ComM_PncIdType PncID;
    uint8 PncByteIndex;
    uint8 PncBitIndex;
    uint8 i;
    uint8 EIRATx[COMM_EIRA_SIG_LENGTH];

    /*from request to ready sleep*/
    if(COMM_PNCSTATE_IS_REQUESTED(Pnc))
    {
        if(Pnc < COMM_NUM_OF_ACTUALPNC)
        {
            /* uptate EIRA bit to 0*/
            PncID = COMM_GET_PNCID(Pnc);
            PncByteIndex = COMM_GET_PNC_BYTE_INDEX(PncID);
            PncBitIndex = COMM_GET_PNC_BIT_INDEX(PncID);
            /*SWS_ComM_00982 SWS_ComM_00960*/
            ComM_EIRATxValue[PncByteIndex] &= ~((uint8)1 << PncBitIndex);

            SignalStartIndex = ComM_PncMappingTxEIRAStart[Pnc];
            SignalEndIndex = SignalStartIndex + ComM_PncMappingTxEIRANum[Pnc];

            for(SignalIndex = SignalStartIndex; SignalIndex < SignalEndIndex; SignalIndex++)
            {
                for(i = 0; i < COMM_EIRA_SIG_LENGTH; i++)
                {
                    /*SWS_ComM_00916*/
                    EIRATx[i] = ComM_EIRATxValue[i] & Signal_Mask[SignalIndex][i];
                }
                /*SWS_ComM_00975 SWS_ComM_00916 SWS_ComM_00960*/
                Com_SendSignal(ComM_PncMappingTxEIRAId[SignalIndex], EIRATx);
            }
        }
        /* release the COMM_FULL_COMMUNICATION request for all configured ComM channels for this PNC *//*SWS_ComM_00827 SWS_ComM_00961*/
        ComM_RequestChannelMode(Pnc, COMM_NO_COMMUNICATION);
    }
    else if(COMM_PNCSTATE_IS_PREPARE_SLEEP(Pnc))
    {
        /*Stop prepare sleep timer*/
        COMM_STOP_PNC_PREPARE_SLEEP_TIMER(Pnc);
    }
    else
    {
        /* do nothing */
    }
    COMM_SET_PNCSTATE_READY_SLEEP(Pnc);

    /*notify BswM*/
    if(Pnc < COMM_NUM_OF_ACTUALPNC)
    {
        /*SWS_ComM_00976*//*SWS_ComM_00908 SWS_ComM_00829*/
        BswM_ComM_CurrentPNCMode(Pnc, COMM_PNC_READY_SLEEP);
    }

}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: ComM_PncPrepareSleepProc
*
* Description:   Process actions in PNC sub state PNC_PREPARE_SLEEP
*
* Inputs:        Pnc
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, COMM_CODE) ComM_PncPrepareSleepProc
(
    PNCHandleType Pnc
)
{
    if(COMM_IS_USER_REQUEST_PNC_EXIST(Pnc))
    {
        /*SWS_ComM_00948*/
        ComM_PncRequestedEnter(Pnc);
    }
    else if(COMM_IS_EIRA_OF_PNC_VALID(Pnc))
    {
        /*SWS_ComM_00950*/
        ComM_PncReadySleepEnter(Pnc);
    }
    else if(COMM_IS_PNC_PREPARE_SLEEP_TIMER_EXP(Pnc))
    {
        /*SWS_ComM_00947*/
        ComM_PncNoComEnter(Pnc);
    }
    else
    {
        /* stay in prepare sleep */
    }

}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: ComM_PncPrepareSleepEnter
*
* Description:   Process actions on entry of PNC sub state PNC_PREPARE_SLEEP
*
* Inputs:        Pnc
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, COMM_CODE) ComM_PncPrepareSleepEnter
(
    PNCHandleType Pnc
)
{
    COMM_SET_PNCSTATE_PREPARE_SLEEP(Pnc);
    /*The pnc is a actual pnc.*/
    if(Pnc < COMM_NUM_OF_ACTUALPNC)
    {
        /*start the timer*//*SWS_ComM_00952*/
        COMM_START_PNC_PREPARE_SLEEP_TIMER(Pnc);
        /*notify BswM*//*SWS_ComM_00976*//*SWS_ComM_00908 SWS_ComM_00829*/
        BswM_ComM_CurrentPNCMode(Pnc, COMM_PNC_PREPARE_SLEEP);
    }
    else
    {
        ComM_PncNoComEnter(Pnc);
    }

}

#endif/*COMM_PNC_SUPPORT*/


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: ComM_MainFunction
*
* Description:   Main function of the ComM
*
* Inputs:         None
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
/*SWS_ComM_00987 SWS_ComM_00979*/
FUNC(void, COMM_CODE) ComM_MainFunction
(
    NetworkHandleType Channel
)
{
/*SWS_ComM_00910*/
#if((STD_ON == COMM_PNC_SUPPORT) && (STD_ON == COMM_USED_PNC_ENABLED))
    uint8 PncStartIndex;
    uint8 PncEndIndex;
    uint8 PncIndex;
#endif

    if(!COMM_IS_INITIALIZED())
    {
        COMM_DET_REPORT_ERROR(COMM_MAINFUNCTION_APIID, COMM_E_NOT_INITED);
    }
    else if(Channel >= COMM_NUM_OF_CHANNEL)
    {
        COMM_DET_REPORT_ERROR(COMM_MAINFUNCTION_APIID, COMM_E_WRONG_PARAMETERS);
    }
    else
    {
        SchM_Enter_ComM_COMM_EXCLUSIVE_AREA_1();
/*SWS_ComM_00910*/        
#if((STD_ON == COMM_PNC_SUPPORT) && (STD_ON == COMM_USED_PNC_ENABLED))
        PncStartIndex = ComMChannelMappingPncStart[Channel];
        PncEndIndex = PncStartIndex + ComMChannelMappingPncNum[Channel];
        for(PncIndex = PncStartIndex; PncIndex < PncEndIndex; PncIndex++)
        {
            /*SWS_ComM_00953*/
            ComM_MainFunctionPnc(ComMChannelMappingPnc[PncIndex]);
        }
#endif
#if((STD_ON == COMM_NMVARIANT_LIGHT_ENABLED) || (STD_ON == COMM_NMVARIANT_NONE_ENABLED))
        ComM_TimerMainFunction(Channel);
#endif
        /*SWS_ComM_00953*/
        switch(COMM_GET_STATE(Channel))
        {
            case COMM_NO_COM_NO_PENDING_REQUEST:
                ComM_NoPendingRequestProc(Channel);
                break;
            case COMM_NO_COM_REQUEST_PENDING:
                ComM_RequestPendingProc(Channel);
                break;
#if(STD_ON == COMM_NM_SUPPORT)
            case COMM_SILENT_COM:
                ComM_SilentComProc(Channel);
                break;
#endif
            case COMM_FULL_COM_NETWORK_REQUESTED:
                ComM_NetworkRequestedProc(Channel);
                break;
            case COMM_FULL_COM_READY_SLEEP:
                ComM_ReadySleepProc(Channel);
                break;
            default:
                break;
        }
        SchM_Exit_ComM_COMM_EXCLUSIVE_AREA_1();
    }
    return;
}



#define COMM_STOP_SEC_CODE
#include "MemMap.h"


