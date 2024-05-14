/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : BswM_Cfg.h
********************************************************************************
*   Project/Product : AUTOSAR BSW PROJECT
*   Title           : BswM module configuration File
*   Author          : Hirain
********************************************************************************
*   Description     : BswM module configuration File
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
*   V1.0.0_3.5.5_AZ240046       27/03/2024    Eas           N/A          N/A
*
********************************************************************************
* END_FILE_HDR*/
#ifndef BSWM_CFG_H
#define BSWM_CFG_H

/*******************************************************************************
*   Includes
*******************************************************************************/


/*******************************************************************************
*   Common Macro
*******************************************************************************/
/*The configuration variant and version informations*/
#define BSWM_CONFIG_VARIANTS                                STD_CONFIG_VARIANTS_PRECOMPILE


/*******************************************************************************
*   Non Autosar Standard
*******************************************************************************/
/* only used when postbuild is selected  */

/* EAS special */
#define BSWM_VERSION_CHECK                                  STD_ON


/*******************************************************************************
*   BswMGeneral
*******************************************************************************/
/* ECUC_BswM_00811 */
#define BSWM_DEV_ERROR_DETECT                               STD_ON
/* ECUC_BswM_00812 */
#define BSWM_VERSION_INFO_API                               STD_ON
/* ECUC_BswM_00813 */
#define BSWM_MAINFUNCTION_PERIOD                            5

/* ECUC_BswM_00938 */
#define BSWM_CANSM_ENABLED                                  STD_ON
/* ECUC_BswM_01029 */
#define BSWM_CANSM_ICOM_ENABLED                             STD_OFF
/* ECUC_BswM_00939 */
#define BSWM_COMM_ENABLED                                   STD_ON
/* ECUC_BswM_00940 */
#define BSWM_DCM_ENABLED                                    STD_ON
/* ECUC_BswM_00941 */
#define BSWM_ECUM_ENABLED                                   STD_ON
/* ECUC_BswM_00942 */
#define BSWM_ETHSM_ENABLED                                  STD_ON
/* ECUC_BswM_00943 */
#define BSWM_FRSM_ENABLED                                   STD_OFF
/* ECUC_BswM_00944 */
#define BSWM_LINSM_ENABLED                                  STD_OFF
/* ECUC_BswM_00945 */
#define BSWM_LINTP_ENABLED                                  STD_OFF
/* ECUC_BswM_00946 */
#define BSWM_NVM_ENABLED                                    STD_ON
/* ECUC_BswM_00947 */
#define BSWM_SCHM_ENABLED                                   STD_OFF
/* ECUC_BswM_00948 */
#define BSWM_WDGM_ENABLED                                   STD_ON
/* ECUC_BswM_00949 */
#define BSWM_GENERIC_REQUEST_ENABLED                        STD_ON

/* ECUC_BswM_00987 */
#define BSWM_J1939DCM_ENABLED                               STD_OFF
/* ECUC_BswM_00965 */
#define BSWM_J1939NM_ENABLED                                STD_OFF
/* ECUC_BswM_01047 */
#define BSWM_SD_ENABLED                                     STD_OFF
/* ECUC_BswM_01071 */
#define BSWM_NM_ENABLED                                     STD_ON

#define BSWM_TIMER_ENABLED                                  STD_ON

#define BSWM_ECUM_WKUPSRC_ENABLED                           STD_OFF
#define BSWM_DEM_ENABLED                                    STD_OFF
#define BSWM_ABORTONFAIL_ENABLED                            STD_OFF
#define BSWM_MULTICORE_ENABLED                              STD_OFF
#define BSWM_MODEINITVALUE_ENABLED                          STD_ON

#define BSWM_NVM_READALL_SUPPORT                            STD_ON
#define BSWM_NVM_WRITEALL_SUPPORT                           STD_ON

#define BSWM_COMM_PNC_ENABLED                               STD_OFF
#define BSWM_COMM_RESET_ENABLED                             STD_OFF
#define BSWM_MULTIPATITION_ENABLED                          STD_OFF

/* generate tool's version*/
#define BSWM_SW_MAJOR_VERSION_CFG                           1
#define BSWM_SW_MINOR_VERSION_CFG                           1
#define BSWM_SW_PATCH_VERSION_CFG                           25
#define BSWM_AR_RELEASE_MAJOR_VERSION_CFG                   4
#define BSWM_AR_RELEASE_MINOR_VERSION_CFG                   2
#define BSWM_AR_RELEASE_REVISION_VERSION_CFG                2



/*******************************************************************************
*   RequestedMode & RequestedUser Cfg
*******************************************************************************/

#define BSWM_MAX_GENERAL_REQUESTING_USER                    (1)

#define BSWM_MAX_GENERAL_REQUESTED_MODE                     (1)

#define BSWM_MAX_COMM_PNC_REQUESTING_USER                   (0)

#define BSWM_MAX_DCM_COMMUNICATION_REQUESTING_NETWORK       (1)

#define BSWM_MAX_ETHSM_REQUESTING_USER                      (0)

#define BSWM_MAX_FRSM_REQUESTING_USER                       (0)

#define BSWM_MAX_LINSM_REQUESTING_USER                      (0)

#define BSWM_MAX_WKUPSRC_NUM                                (0)

#define BSWM_MAX_LINSM_REQUESTED_SCHEDULE                   (0)

#define BSWM_MAX_WDGM_REQUESTED_APP                         (0)

#define BSWM_MAX_NM_CHANNEL                                 (0)

#define BSWM_MAX_SD_CS_USER                                 (0)
#define BSWM_MAX_SD_CS_MODE                                 (0)

#define BSWM_MAX_SD_EVENTGROUP_ID                           (0)
#define BSWM_MAX_SD_EVENTGROUP_STATE                        (0)

#define BSWM_MAX_SD_EVENTHANDLER_USER                       (0)
#define BSWM_MAX_SD_EVENTHANDLER_MODE                       (0)


/*******************************************************************************
*   Macro
*******************************************************************************/


#define BSWM_MAX_ACTIONLIST_NUM                             (18)
#define BSWM_MAX_RULE_NUM                                   (19)


/*PortNum*/
#define BSWM_ECUM_PORT_NUM                                  (1)
#define BSWM_LINSM_PORT_NUM                                 (0)
#define BSWM_FRSM_PORT_NUM                                  (0)
#define BSWM_ETHSM_PORT_NUM                                 (0)
#define BSWM_CANSM_PORT_NUM                                 (2)
#define BSWM_CANSM_ICOM_PORT_NUM                            (0)
#define BSWM_DCM_PORT_NUM                                   (1)
#define BSWM_DCM_APP_UPDATE_PORT_NUM                        (0)
#define BSWM_COMM_PORT_NUM                                  (3)
#define BSWM_COMM_PNC_PORT_NUM                              (0)
#define BSWM_COMM_RESET_PORT_NUM                            (0)
#define BSWM_NVM_BLOCK_PORT_NUM                             (0)
#define BSWM_NVM_JOB_PORT_NUM                               (2)
#define BSWM_LINTP_PORT_NUM                                 (0)
#define BSWM_LINSM_SCH_PORT_NUM                             (0)
#define BSWM_NM_CAR_WKUP_PORT_NUM                           (0)
#define BSWM_GENERAL_PORT_NUM                               (1)
#define BSWM_TIMER_PORT_NUM                                 (1)
#define BSWM_ECUM_WKUPSRC_PORT_NUM                          (0)
#define BSWM_J1939DCM_PORT_NUM                              (0)
#define BSWM_J1939NM_PORT_NUM                               (0)
#define BSWM_SD_CS_PORT_NUM                                 (0)
#define BSWM_SD_EVENTGROUP_PORT_NUM                         (0)
#define BSWM_SD_EVENTHANDLER_PORT_NUM                       (0)
#define BSWM_WDGM_RESET_PORT_NUM                            (0)
#define BSWM_SWC_MODE_NOTIFY_PORT_NUM                       (0)
#define BSWM_BSW_MODE_NOTIFY_PORT_NUM                       (0)
#define BSWM_SWC_MODE_REQUEST_PORT_NUM                      (0)
#define BSWM_ECUM_INDICATION_PORT_NUM                       (0)

/*PortStartNum*/
#define PORT_ECUM_START_NUM                                 (0)
#define PORT_LINSM_START_NUM                                (1)
#define PORT_FRSM_START_NUM                                 (1)
#define PORT_ETHSM_START_NUM                                (1)
#define PORT_CANSM_START_NUM                                (1)
#define PORT_CANSM_ICOM_START_NUM                           (3)
#define PORT_DCM_START_NUM                                  (3)
#define PORT_DCM_APP_UPDATE_START_NUM                       (4)
#define PORT_COMM_START_NUM                                 (4)
#define PORT_COMM_PNC_START_NUM                             (7)
#define PORT_COMM_RESET_START_NUM                           (7)
#define PORT_NVM_BLOCK_START_NUM                            (7)
#define PORT_NVM_JOB_START_NUM                              (7)
#define PORT_LINTP_START_NUM                                (9)
#define PORT_LINSM_SCH_START_NUM                            (9)
#define PORT_NM_CAR_WKUP_START_NUM                          (9)
#define PORT_BSWM_GENERAL_START_NUM                         (9)
#define PORT_TIMER_START_NUM                                (10)
#define PORT_ECUM_WKUPSRC_START_NUM                         (11)
#define PORT_J1939DCM_START_NUM                             (11)
#define PORT_J1939NM_START_NUM                              (11)
#define PORT_SD_CS_START_NUM                                (11)
#define PORT_SD_EVENTGROUP_START_NUM                        (11)
#define PORT_SD_EVENTHANDLER_START_NUM                      (11)
#define PORT_WDGM_RESET_START_NUM                           (11)
#define PORT_SWC_MODE_NOTIFY_START_NUM                      (11)
#define PORT_BSW_MODE_NOTIFY_START_NUM                      (11)
#define PORT_SWC_MODE_REQUEST_START_NUM                     (11)
#define PORT_ECUM_INDICATION_START_NUM                      (11)
#define BSWM_MAX_PORT_NUM                                   (11)
/*MAP*/
#define BSWM_MAP_ECUM_TO_PORT()                             ((BswMPortType)0)
#define BSWM_MAP_LINSM_TO_PORT(Network)                     ((BswMPortType)1 + (Network))
#define BSWM_MAP_FRSM_TO_PORT(Network)                      ((BswMPortType)1 + (Network))
#define BSWM_MAP_ETHSM_TO_PORT(Network)                     ((BswMPortType)1 + (Network))
#define BSWM_MAP_CANSM_TO_PORT(Network)                     ((BswMPortType)1 + (Network))
#define BSWM_MAP_CANSM_ICOM_TO_PORT(Network)                ((BswMPortType)3 + (Network))
#define BSWM_MAP_DCM_TO_PORT(Network)                       ((BswMPortType)3 + (Network))
#define BSWM_MAP_DCM_APP_UPDATE_TO_PORT()                   ((BswMPortType)4)
#define BSWM_MAP_COMM_TO_PORT(Network)                      ((BswMPortType)4 + (Network))
#define BSWM_MAP_COMM_PNC_TO_PORT(PNC)                      ((BswMPortType)7 + (PNC))
#define BSWM_MAP_COMM_RESET_TO_PORT()                       ((BswMPortType)7)
#define BSWM_MAP_NVM_BLOCK_TO_PORT(Block)                   ((BswMPortType)7 + (Block))
#define BSWM_MAP_NVM_READ_ALL_JOB_TO_PORT()                 ((BswMPortType)7)
#define BSWM_MAP_NVM_WRITE_ALL_JOB_TO_PORT()                ((BswMPortType)8)
#define BSWM_MAP_LINTP_TO_PORT(Network)                     ((BswMPortType)9 + (Network))
#define BSWM_MAP_LINSM_SCH_TO_PORT(Network)                 ((BswMPortType)9 + (Network))
#define BSWM_MAP_NM_CAR_WKUP_TO_PORT(Network)               ((BswMPortType)9 + (Network))
#define BSWM_MAP_BSWM_GENERAL_TO_PORT(user)                 ((BswMPortType)9 + (user))
#define BSWM_MAP_TIMER_TO_PORT()                            (10)
#define BSWM_MAP_ECUM_WKUPSRC_TO_PORT(src)                  ((BswMPortType)11 + (src))
#define BSWM_MAP_J1939_DCM_TO_PORT()                        ((BswMPortType)11)
#define BSWM_MAP_J1939NM_TO_PORT(Network)                   ((BswMPortType)11 + (Network))
#define BSWM_MAP_SD_CS_TO_PORT(SdClientServiceHandleId)     ((BswMPortType)11 + (SdClientServiceHandleId))
#define BSWM_MAP_SD_EVENTGROUP_TO_PORT(SdConsumedEventGroupHandleId)  ((BswMPortType)11 + (SdConsumedEventGroupHandleId))
#define BSWM_MAP_SD_EVENTHANDLER_TO_PORT(SdEventHandlerHandleId)      ((BswMPortType)11 + (SdEventHandlerHandleId))
#define BSWM_MAP_WDGM_RESET_TO_PORT(Application)            ((BswMPortType)11 + (Application))
#define BSWM_MAP_SWC_MODE_NOTIFY_TO_PORT(Port)              ((BswMPortType)11 + (Port))
#define BSWM_MAP_BSW_MODE_NOTIFY_TO_PORT(Port)              ((BswMPortType)11 + (Port))
#define BSWM_MAP_SWC_MODE_REQUEST_TO_PORT(Port)             ((BswMPortType)11 + (Port))
#define BSWM_MAP_ECUM_MODE_IND_TO_PORT()                    ((BswMPortType)11)
#define BSWM_MAX_PORT_MAPPING_RULE_NUM                      ((BswMPortType)59)

#define BSWM_ACTIONLIST_NULL                                (18)
#define BSWM_RULE_NULL                                      (19)




#define BSWM_GENERIC_MODE_INIT                              0x00U
#define BSWM_GENERIC_MODE_WAKEUP                            0x01U
#define BSWM_GENERIC_MODE_READ_NVM                          0x02U
#define BSWM_GENERIC_MODE_WRITE_NVM                         0x03U
#define BSWM_GENERIC_MODE_APP_RUN                           0x04U
#define BSWM_GENERIC_MODE_POST_RUN                          0x05U
#define BSWM_GENERIC_MODE_PREP_SHUTDOWN                     0x06U
#define BSWM_GENERIC_MODE_SLEEP                             0x07U
#define BSWM_GENERIC_MODE_SHUTDOWN                          0x08U

#define BswM_SysState                                       0U

#define BSWM_NO_INITVALUE                                   0U

#endif /* BSWM_CFG_H */



