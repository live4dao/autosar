/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : Dcm_Cfg.h
********************************************************************************
*   Project/Product : AUTOSAR BSW PROJECT
*   Title           : Dcm module configuration File
*   Author          : Hirain
********************************************************************************
*   Description     : Dcm module configuration File
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
*   V1.0.2_3.5.5_AZ240046       09/05/2024    Eas           N/A          N/A
*
********************************************************************************
* END_FILE_HDR*/

#ifndef DCM_CFG_H
#define DCM_CFG_H
/***********************************************************************************
* Include files
***********************************************************************************/
#include "ComM_Cfg.h"

/***********************************************************************************
* Version
***********************************************************************************/

#define DCM_PRIVATE_VERSION_CHECK                           STD_ON
#define DCM_SW_MAJOR_VERSION_CFG                            1
#define DCM_SW_MINOR_VERSION_CFG                            2
#define DCM_SW_PATCH_VERSION_CFG                            19
#define DCM_AR_RELEASE_MAJOR_VERSION_CFG                    4
#define DCM_AR_RELEASE_MINOR_VERSION_CFG                    2
#define DCM_AR_RELEASE_REVISION_VERSION_CFG                 2

/***********************************************************************************
* The following are configurable
***********************************************************************************/
#define DCM_OBD_SUPPORT                                     STD_OFF
#define DCM_CAR_PLATFORM                                    DCM_NO_PLATFORM
#define DCM_COMM_SUPPORT                                    STD_ON
#define DCM_BSWM_SUPPORT                                    STD_ON
#define DCM_DEM_SUPPORT                                     STD_ON
#define DCM_NVM_SUPPORT                                     STD_ON
#define DCM_CONFIG_VARIANTS                                 STD_CONFIG_VARIANTS_PRECOMPILE

/*DcmGeneral*/

/*ECUC_Dcm_00971*/
#define DCM_DDDID_STORAGE                                   STD_OFF
/*ECUC_Dcm_00823*/
#define DCM_DEV_ERROR_DETECT                                STD_OFF
/*ECUC_Dcm_00600*/
#define DCM_RESPOND_ALL_REQUEST                             STD_ON
/*ECUC_Dcm_00820*/
#define DCM_TASK_TIME                                       5
/*ECUC_Dcm_00821*/
#define DCM_VERSION_INFO_API                                STD_OFF
/*ECUC_Dcm_00984*/
#define DCM_VIN_REF                                         DCM_INVALID_DID
#define DCM_VIN_IN_PROTOCOL                                 0

#define DCM_RESPONSE_WITHP2TIMER                            STD_ON
/*ECUC_Dcm_00783*/
#define DCM_DSD_MANUFACTURER_NOTIFICATION_ENABLED           STD_OFF
/*ECUC_Dcm_00868*/
#define DCM_DSD_SUPPLIER_NOTIFICATION_ENABLED               STD_OFF

/*UDS 0x10 Service*/
#define DCM_UDS_10_SUPPORT_SUPPRESSPOSRESBIT                STD_ON

/*UDS 0x11 Service*/
#define DCM_UDS_11_SERVICE                                  STD_ON
#define DCM_UDS_11_SUPPORT_SUPPRESSPOSRESBIT                STD_ON

/*UDS 0x14 Service*/
#define DCM_UDS_14_SERVICE                                  STD_ON
#define DCM_APP_CLEARDTCCHECK_ENABLE                        STD_OFF

/*UDS 0x19 Service*/
#define DCM_UDS_19_SERVICE                                  STD_ON
#define DCM_UDS_19_SUPPORT_SUPPRESSPOSRESBIT                STD_OFF

/*UDS 0x22 Service*/
#define DCM_UDS_22_SERVICE                                  STD_ON

/*UDS 0x23 Service*/
#define DCM_UDS_23_SERVICE                                  STD_OFF

/*UDS 0x27 Service*/
#define DCM_UDS_27_SERVICE                                  STD_ON
#define DCM_UDS_27_SUPPORT_SUPPRESSPOSRESBIT                STD_OFF
#define DCM_CFG_MANUFACTORY_MODE_SUPPORT                    STD_OFF
#define DCM_UDS_27_NCR24AFTERZEROSEED                       STD_ON
#define DCM_UDS_27_REQUESTSEEDCONTINOUS                     STD_ON

/*UDS 0x28 Service*/
#define DCM_UDS_28_SERVICE                                  STD_ON
#define DCM_UDS_28_SUPPORT_SUPPRESSPOSRESBIT                STD_ON
#define Dcm_Rte_CommunicationMode_CurrentState(Handle,Mode)     \
    BswM_Dcm_CommunicationMode_CurrentState(Handle,Mode)

/*UDS 0x2A Service*/
#define DCM_UDS_2A_SERVICE                                  STD_OFF

/*UDS 0x2C Service*/
#define DCM_UDS_2C_SERVICE                                  STD_OFF

/*UDS 0x2E Service*/
#define DCM_UDS_2E_SERVICE                                  STD_ON

/*UDS 0x2F Service*/
#define DCM_UDS_2F_SERVICE                                  STD_OFF

/*UDS 0x31 Service*/
#define DCM_UDS_31_SERVICE                                  STD_ON
#define DCM_UDS_31_SUPPORT_SUPPRESSPOSRESBIT                STD_ON

/*UDS 0x3D Service*/
#define DCM_UDS_3D_SERVICE                                  STD_OFF

/*UDS 0x3E Service*/
#define DCM_UDS_3E_SERVICE                                  STD_ON
#define DCM_UDS_3E_SUPPORT_SUPPRESSPOSRESBIT                STD_ON

/*UDS 0x85 Service*/
#define DCM_UDS_85_SERVICE                                  STD_ON
#define DCM_UDS_85_SUPPORT_SUPPRESSPOSRESBIT                STD_ON
#define DCM_SUPPORT_DTC_RECORD                              STD_OFF

/*UDS 0x87 Service*/
#define DCM_UDS_87_SERVICE                                  STD_OFF

/*UDS 0x34 Service*/
#define DCM_UDS_34_SERVICE                                  STD_OFF

/*UDS 0x35 Service*/
#define DCM_UDS_35_SERVICE                                  STD_OFF

/*UDS 0x346 Service*/
#define DCM_UDS_36_SERVICE                                  STD_OFF

/*UDS 0x37 Service*/
#define DCM_UDS_37_SERVICE                                  STD_OFF

/*UDS 0x01 Service*/
#define DCM_OBD_01_SERVICE                                  STD_OFF

/*OBD 0x02 Service*/
#define DCM_OBD_02_SERVICE                                  STD_OFF

/*OBD 0x03 Service*/
#define DCM_OBD_03_SERVICE                                  STD_OFF

/*OBD 0x04 Service*/
#define DCM_OBD_04_SERVICE                                  STD_OFF

/*OBD 0x06 Service*/
#define DCM_OBD_06_SERVICE                                  STD_OFF

/*OBD 0x07 Service*/
#define DCM_OBD_07_SERVICE                                  STD_OFF

/*OBD 0x08 Service*/
#define DCM_OBD_08_SERVICE                                  STD_OFF

/*OBD 0x09 Service*/
#define DCM_OBD_09_SERVICE                                  STD_OFF

/*OBD 0x0A Service*/
#define DCM_OBD_0A_SERVICE                                  STD_OFF
/*Dsl Configuration*/
/*ECUC_Dcm_00693,DcmDslDiagRespMaxNumRespPend*/
#define DCM_CFG_RESP_PEND_MAX_NUM                           4
/*ECUC_Dcm_00914,DcmDslDiagRespOnSecondDeclinedRequest*/
#define DCM_CFG_RESP_ON_SECOND_REQ                          FALSE
/*Dsp Configuration*/
/*ECUC_Dcm_00966,DcmDspDDDIDcheckPerSourceDID*/
#define DCM_CFG_DSP_DDDID_CHECK_SRC_DID                     FALSE
/*ECUC_Dcm_00987,DcmDspDataDefaultEndianness*/
#define DCM_CFG_DSP_DEFAULT_ENDIANNESS                      DCM_OPAQUE
/*ECUC_Dcm_01061,DcmDspEnableObdMirror*/
#define DCM_CFG_DSP_EN_OBD_MIRROR                           FALSE
/*ECUC_Dcm_00638,DcmDspMaxDidToRead,1..65535*/
#define DCM_CFG_DSP_MAX_DID_READ                            1
/*ECUC_Dcm_00818,DcmDspPowerDownTime,valid:00-FE,unit:s*/
#define DCM_CFG_DSP_POWER_DOWN_TIME                         0
/*ECUC_Dcm_01039,DcmResponseToEcuReset*/
#define DCM_CFG_DSP_RESP_TO_RESET                           DCM_BEFORE_RESET
/*ECUC_Dcm_00956,DcmDspMaxPeriodicDidToRead,1..65535*/
#define DCM_CFG_DSP_MAX_PERIODIC_DID_READ                   1
#define DCM_NUM_COMM_CHANNEL                                COMM_NUM_OF_CHANNEL

#define DCM_CFG_NUM_OF_PROTOCOL                             1

#define DCM_CFG_NUM_SECURITY_LEVEL                          2
#define DCM_CFG_RXPDU_NUM                                   4
#define DCM_CFG_DDDID_NUM                                   0
#define DCM_CFG_ALL_DDDID_ELEMENT_NUM                       0
#define DCM_CFG_RID_NUM                                     1

#define DcmTransmit(DcmTxPduId,PduInfoPtr)    PduR_DcmTransmit(DcmTxPduId,PduInfoPtr)
#define DcmCancelTransmit(DcmTxPduId)
#define DcmCancelReceive(DcmTxPduId)

#define Dcm_PduR_CanConfigSet_Rx_ACAN_UDS_FuncDiagReq       (0)
#define Dcm_PduR_CanConfigSet_Rx_ACAN_UDS_PhyDiagReq_ADAS   (1)
#define Dcm_PduR_DoIPDefaultConfig_DoIP_To_Dcm_Fun          (2)
#define Dcm_PduR_DoIPDefaultConfig_DoIP_To_Dcm_Phy          (3)

#define Dcm_PduR_CanConfigSet_Tx_ACAN_UDS_DiagResp_ADAS     (0)
#define Dcm_PduR_DoIPDefaultConfig_Dcm_To_DoIP              (1)

#endif

