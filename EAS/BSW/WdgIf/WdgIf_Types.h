/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
*   File Name       : WdgIf_Types.h
********************************************************************************
*   Project/Product : AUTOSAR 4.2
*   Title           : WdgIf module type Header File
*   Author          : Hirain
********************************************************************************
*   Description     : WdgIf module type Header File
*
********************************************************************************
*   Limitations     : None
*
********************************************************************************
*
********************************************************************************
*   Revision History:
********************************************************************************
* END_FILE_HDR*/
#ifndef WDGIF_TYPES_H
#define WDGIF_TYPES_H
#include "Std_Types.h"
#include "WdgIf_Version.h"
/*******************************************************************************
*   Typedef SWS_WdgIf_00061
*******************************************************************************/
typedef enum
{
    WDGIF_OFF_MODE = 0,  /*WDG is disable.Switched off  */
    WDGIF_SLOW_MODE,     /*in this mode,WDG is set up for a long 20ms timeout period*/
    WDGIF_FAST_MODE     /*in this mode,WDG is set up for a short 5ms timeout period*/
} WdgIf_ModeType;        /*Operating modes of the WDG Driver*/

#define WDGIF_TYPES_VENDOR_ID                    STD_HIRAIN_VENDOR_ID
#define WDGIF_TYPES_MODULE_ID                    ((uint16)43U)
#define WDGIF_TYPES_AR_RELEASE_MAJOR_VERSION     (4)
#define WDGIF_TYPES_AR_RELEASE_MINOR_VERSION     (2)
#define WDGIF_TYPES_AR_RELEASE_REVISION_VERSION  (2)
#define WDGIF_TYPES_SW_MAJOR_VERSION             (1)
#define WDGIF_TYPES_SW_MINOR_VERSION             (2)
#define WDGIF_TYPES_SW_PATCH_VERSION             (0)

#endif /* WDGIF_TYPES_H */
