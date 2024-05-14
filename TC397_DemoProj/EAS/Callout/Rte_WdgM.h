/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : Rte_WdgM.h
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
#ifndef RTE_WDGM_H
#define RTE_WDGM_H

#ifndef RTE_CORE
#ifdef RTE_APPLICATION_HEADER_FILE
#error Multiple application header files included.
#endif /* RTE_APPLICATION_HEADER_FILE */
#define RTE_APPLICATION_HEADER_FILE
#endif
# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

/*******************************************************************************
*   Includes.
*******************************************************************************/
#include "WdgM.h"
#include "Rte_WdgM_Type.h"
#define RTE_START_SEC_CODE
#include "MemMap.h"

#define Rte_Call_alive_WdgMSupervisedEntity_SE0_CheckpointReached(CheckpointID) WdgM_CheckpointReached(WDGM_SE_WdgMSupervisedEntity_SE0, CheckpointID)
#define Rte_Call_alive_WdgMSupervisedEntity_SE0_GetFirstExpiredSEID() WdgM_GetFirstExpiredSEID(WDGM_SE_WdgMSupervisedEntity_SE0)
#define Rte_Call_alive_WdgMSupervisedEntity_SE0_GetGlobalStatus(Status)         WdgM_GetGlobalStatus(Status)
#define Rte_Call_alive_WdgMSupervisedEntity_SE0_GetLocalStatus(Status)          WdgM_GetLocalStatus(WDGM_SE_WdgMSupervisedEntity_SE0, Status)
#define Rte_Call_alive_WdgMSupervisedEntity_SE0_GetMode(Mode)         WdgM_GetMode(Mode)
#define Rte_Call_alive_WdgMSupervisedEntity_SE0_PerformReset()        WdgM_PerformReset()
#define Rte_Call_alive_WdgMSupervisedEntity_SE0_SetMode(Mode, CallerID)         WdgM_SetMode(Mode, CallerID)
#define Rte_Call_alive_WdgMSupervisedEntity_SE0_UpdateAliveCounter()  WdgM_UpdateAliveCounter(WDGM_SE_WdgMSupervisedEntity_SE0)
#define Rte_Switch_globalmode_WdgM_Mode                     Rte_Switch_WdgM_globalmode_WdgM_Mode
#define Rte_Switch_mode_WdgMSupervisedEntity_SE0_WdgM_Mode  Rte_Switch_WdgM_mode_WdgMSupervisedEntity_SE0_WdgM_Mode
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Switch_WdgM_globalmode_WdgM_Mode
(
    VAR(Rte_ModeType_WdgM_Mode, AUTOMATIC) nextMode
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Switch_WdgM_mode_WdgMSupervisedEntity_SE0_WdgM_Mode
(
    VAR(Rte_ModeType_WdgM_Mode, AUTOMATIC) nextMode
);

#define RTE_STOP_SEC_CODE
#include "MemMap.h"

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif  /*RTE_WDGM_H*/


