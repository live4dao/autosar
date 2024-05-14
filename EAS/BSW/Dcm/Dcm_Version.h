/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
*   File Name       : Dcm_Version.h
********************************************************************************
*   Project/Product : AUTOSAR 4.2
*   Title           : Dcm module head File
*   Author          : Hirain
********************************************************************************
*   Description     :
********************************************************************************
*   Limitations     : None
*
********************************************************************************
*
********************************************************************************
*   Revision History:
*   Reference to Core C File
********************************************************************************
* END_FILE_HDR*/

#ifndef DCM_VERSION_H
#define DCM_VERSION_H

/*******************************************************************************
*   Includes
*******************************************************************************/
#include "Std_Types.h"

#define DCM_VENDOR_ID                   STD_HIRAIN_VENDOR_ID/* Supplier ID */
/*SWS_Dcm_00052*/
#define DCM_MODULE_ID                   ((uint16)53)/* Dcm Moudle ID */
#define DCM_INSTANCE_ID                 (0)
#define DCM_SW_MAJOR_VERSION            (1)
#define DCM_SW_MINOR_VERSION            (2)
#define DCM_SW_PATCH_VERSION            (1)
#define DCM_SW_DEV_PHASE                (Beta.1)

#define DCM_AR_RELEASE_MAJOR_VERSION    (4)
#define DCM_AR_RELEASE_MINOR_VERSION    (2)
#define DCM_AR_RELEASE_REVISION_VERSION (2)

#endif/*DCM_VERSION_H*/

