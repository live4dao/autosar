/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
*   File Name       : Det_Version.h
********************************************************************************
*   Project/Product : AUTOSAR 4.2
*   Title           : Default Error Tracer Header File
*   Author          : Hirain
********************************************************************************
*   Description     : Includes all user relevant information for the tracing of
*                     development errors.   .
*
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

#ifndef DET_VERSION_H
#define DET_VERSION_H

/*****************************************************************************
 *  General QAC Suppression
 *****************************************************************************/
/*PRQA S 792,791 EOF*/
/*
Name of macros may not follow relevant naming rules.
*/

/*******************************************************************************
*   Macro SWS_Det_00036
*******************************************************************************/
#define DET_VENDOR_ID                   STD_HIRAIN_VENDOR_ID
#define DET_MODULE_ID                   ((uint16)15)
#define DET_INSTANCE_ID                 ((uint8)0)
#define DET_SW_MAJOR_VERSION            (1)
#define DET_SW_MINOR_VERSION            (2)
#define DET_SW_PATCH_VERSION            (2)
#define DET_SW_DEV_PHASE                (Beta.0)



#define DET_AR_RELEASE_MAJOR_VERSION    (4)
#define DET_AR_RELEASE_MINOR_VERSION    (2)
#define DET_AR_RELEASE_REVISION_VERSION (2)


#endif/* DET_VERSION_H */
