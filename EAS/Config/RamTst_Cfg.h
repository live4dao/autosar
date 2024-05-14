/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : RamTst_Cfg.h
********************************************************************************
*   Project/Product : AUTOSAR BSW PROJECT
*   Title           : RamTst module configuration File
*   Author          : Hirain
********************************************************************************
*   Description     : RamTst module configuration File
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
#ifndef RAMTST_CFG_H
#define RAMTST_CFG_H

/*******************************************************************************
*   Common Macro
*******************************************************************************/

/*ECUC_RamTst_00186 */
#define RAMTST_CELL_SIZE                                    ((RamTst_NumberOfTestedCellsType)8)

/*******************************************************************************
*   Moudle support configuration
*******************************************************************************/

/*The API configuration*/
#define RAMTST_DEM_REPORT_ERROR_STATUS                      STD_OFF
/*ECUC_RamTst_00121 */
#define RAMTST_DEV_ERROR_DETECT                             STD_ON
/*ECUC_RamTst_00128 */
#define RAMTST_GET_VERSION_INFO_API                         STD_OFF

/*ECUC_RamTst_00120 */
#define RAMTST_ALLOW_API                                    STD_ON
/*ECUC_RamTst_00127 */
#define RAMTST_STOP_API                                     STD_OFF
/*ECUC_RamTst_00156 */
#define RAMTST_SUSPEND_API                                  STD_OFF
/*ECUC_RamTst_00155 */
#define RAMTST_RESUME_API                                   STD_OFF

/*ECUC_RamTst_00182 */
#define RAMTST_SELECT_ALG_PARAMS_API                        STD_OFF
/*ECUC_RamTst_00118 */
#define RAMTST_CHANGE_NUMBER_OF_TESTED_CELLS_API            STD_OFF

/*ECUC_RamTst_00183 */
#define RAMTST_GET_ALG_PARAMS_API                           STD_OFF
/*ECUC_RamTst_00122 */
#define RAMTST_GET_EXECUTION_STATUS_API                     STD_OFF
/*ECUC_RamTst_00123 */
#define RAMTST_GET_NUMBER_OF_TESTED_CELLS_API               STD_OFF
/*ECUC_RamTst_00124 */
#define RAMTST_GET_TEST_ALGORITHM_API                       STD_OFF
/*ECUC_RamTst_00125 */
#define RAMTST_GET_TEST_RESULT_API                          STD_OFF
/*ECUC_RamTst_00126 */
#define RAMTST_GET_TEST_RESULT_PER_BLOCK_API                STD_OFF

/*ECUC_RamTst_00184 */
#define RAMTST_RUN_FULL_TEST_API                            STD_OFF
/*ECUC_RamTst_00185 */
#define RAMTST_RUN_PARTIAL_TEST_API                         STD_OFF

/*The algorithm configuration*/
/*ECUC_RamTst_00130 */
#define RAMTST_CHECKERBOARD_TEST_SELECTED                   STD_ON
/*ECUC_RamTst_00133 */
#define RAMTST_MARCH_TEST_SELECTED                          STD_OFF
/*ECUC_RamTst_00132 */
#define RAMTST_GALPAT_TEST_SELECTED                         STD_OFF
/*ECUC_RamTst_00134 */
#define RAMTST_TRANSP_GALPAT_TEST_SELECTED                  STD_OFF
/*ECUC_RamTst_00135 */
#define RAMTST_WALK_PATH_TEST_SELECTED                      STD_OFF
/*ECUC_RamTst_00129 */
#define RAMTST_ABRAHAM_TEST_SELECTED                        STD_OFF

/*version check*/
#define RAMTST_PRIVATE_VERSION_CHECK                        STD_ON
#define RAMTST_SW_MAJOR_VERSION_CFG                         1
#define RAMTST_SW_MINOR_VERSION_CFG                         2
#define RAMTST_SW_PATCH_VERSION_CFG                         3
#define RAMTST_AR_RELEASE_MAJOR_VERSION_CFG                 4
#define RAMTST_AR_RELEASE_MINOR_VERSION_CFG                 2
#define RAMTST_AR_RELEASE_REVISION_VERSION_CFG              2


#define RAMTST_MAX_NUMBER_OF_BLOCKS                         ((RamTst_NumberOfBlocksType)1)

#define RamTstAlgParams_1                                   ((RamTst_AlgParamsIdType)1)

#define RamTstBlock_1                                       ((RamTst_NumberOfBlocksType)1)

#endif /* RAMTST_CFG_H */



