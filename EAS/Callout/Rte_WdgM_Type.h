/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : Rte_WdgM_Type.h
********************************************************************************
*   Project/Product : AUTOSAR BSW PROJECT
*   Title           : Rte module configuration File
*   Author          : Hirain
********************************************************************************
*   Description     : Rte module configuration File
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
#ifndef RTE_WDGM_TYPE_H
#define RTE_WDGM_TYPE_H
/*******************************************************************************
*   Includes.
*******************************************************************************/
#include "Rte_Type.h"

#ifndef RTE_MODETYPE_WdgM_Mode
#define RTE_MODETYPE_WdgM_Mode
typedef uint8 Rte_ModeType_WdgM_Mode;
#endif
#ifndef RTE_MODE_WdgM_Mode_SUPERVISION_OK
#define RTE_MODE_WdgM_Mode_SUPERVISION_OK                   0U
#endif
#ifndef RTE_MODE_WdgM_Mode_SUPERVISION_FAILED
#define RTE_MODE_WdgM_Mode_SUPERVISION_FAILED               1U
#endif
#ifndef RTE_MODE_WdgM_Mode_SUPERVISION_EXPIRED
#define RTE_MODE_WdgM_Mode_SUPERVISION_EXPIRED              2U
#endif
#ifndef RTE_MODE_WdgM_Mode_SUPERVISION_STOPPED
#define RTE_MODE_WdgM_Mode_SUPERVISION_STOPPED              3U
#endif
#ifndef RTE_MODE_WdgM_Mode_SUPERVISION_DEACTIVATED
#define RTE_MODE_WdgM_Mode_SUPERVISION_DEACTIVATED          4U
#endif
#ifndef RTE_TRANSITION_WdgM_Mode
#define RTE_TRANSITION_WdgM_Mode                            5U
#endif

#endif



