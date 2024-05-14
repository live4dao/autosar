/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : FlsTst_Cfg.h
********************************************************************************
*   Project/Product : AUTOSAR BSW PROJECT
*   Title           : FlsTst module configuration File
*   Author          : Hirain
********************************************************************************
*   Description     : FlsTst module configuration File
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
#ifndef FLSTST_CFG_H
#define FLSTST_CFG_H

/*******************************************************************************
*   Macro
*******************************************************************************/
#define FLSTST_CONFIG_VARIANTS                              STD_CONFIG_VARIANTS_PRECOMPILE
#define FLSTST_DEM_SUPPORT                                  STD_OFF

/*ECUC_FlsTst_00083 */
#define FLSTST_DEV_ERROR_DETECT                             STD_ON
/*ECUC_FlsTst_00161 */
#define FLSTST_NUMBER_OF_TESTED_CELLS                       ((uint32)32)
/*ECUC_FlsTst_00120 */
#define FLSTST_NUMBER_OF_TESTED_CELLS_ATOMIC                8
/*ECUC_FlsTst_00084 */
#define FLSTST_TEST_COMPLETED_NOTIFICATION_SUPPORTED        STD_ON
/*ECUC_FlsTst_00158 */
#define FLSTST_TEST_INTERVAL_ID_END_VALUE                   ((FlsTst_IntervalIdType)10)
#define FLSTST_GET_SIG_CALLOUT_SUPPORTED                    STD_OFF


/*ECUC_FlsTst_00092 */
#define FLSTST_GET_CURRENT_STATE_API                        STD_ON
/*ECUC_FlsTst_00098 */
#define FLSTST_GET_ERROR_DETAILS_API                        STD_OFF
/*ECUC_FlsTst_00094 */
#define FLSTST_GET_TEST_RESULT_BGND_API                     STD_OFF
/*ECUC_FlsTst_00150 */
#define FLSTST_GET_TEST_RESULT_FGND_API                     STD_OFF
/*ECUC_FlsTst_00096 */
#define FLSTST_GET_TEST_SIGNATURE_BGND_API                  STD_OFF
/*ECUC_FlsTst_00097 */
#define FLSTST_GET_TEST_SIGNATURE_FGND_API                  STD_OFF
/*ECUC_FlsTst_00086 */
#define FLSTST_START_FGND_API                               STD_OFF
/*ECUC_FlsTst_00087 */
#define FLSTST_SUSPEND_RESUME_API                           STD_OFF
/*ECUC_FlsTst_00099 */
#define FLSTST_TEST_ECC_API                                 STD_OFF
/*ECUC_FlsTst_00095 */
#define FLSTST_VERSION_INFO_API                             STD_ON
/*ECUC_FlsTst_00122 */
#define FLSTST_NUMBER_OF_BGND_BLOCKS                        ((FlsTst_BlockIdBgndType)0)
/*ECUC_FlsTst_00124 */
#define FLSTST_NUMBER_OF_FGND_BLOCKS                        ((FlsTst_BlockIdFgndType)1)


/*version check*/
#define FLSTST_PRIVATE_VERSION_CHECK                        STD_ON
#define FLSTST_SW_MAJOR_VERSION_CFG                         1
#define FLSTST_SW_MINOR_VERSION_CFG                         2
#define FLSTST_SW_PATCH_VERSION_CFG                         6
#define FLSTST_AR_RELEASE_MAJOR_VERSION_CFG                 4
#define FLSTST_AR_RELEASE_MINOR_VERSION_CFG                 2
#define FLSTST_AR_RELEASE_REVISION_VERSION_CFG              2

#endif /*FLSTST_CFG_H*/


