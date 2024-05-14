/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : Rte_DoIP.h
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
#ifndef RTE_DOIP_H
#define RTE_DOIP_H

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
#include "DoIP.h"
#include "Rte_DoIP_Type.h"
#define RTE_START_SEC_CODE
#include "MemMap.h"

#define DoIP_Rte_Rte_Call_DoIP_CBGetPowerMode_GetPowerMode  Rte_Call_DoIP_CBGetPowerMode_GetPowerMode
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DoIP_CBGetPowerMode_GetPowerMode
(
    P2VAR(DoIP_PowerStateType, AUTOMATIC, RTE_APPL_DATA) PowerStateReady
);
#define Rte_Mode_DoIPActivationLineSwitchNotification_currentDoIPActivationLineStatus     Rte_Mode_DoIP_DoIPActivationLineSwitchNotification_currentDoIPActivationLineStatus
extern FUNC(Rte_ModeType_currentDoIPActivationLineStatus, RTE_CODE) Rte_Mode_DoIP_DoIPActivationLineSwitchNotification_currentDoIPActivationLineStatus(void);

#define RTE_STOP_SEC_CODE
#include "MemMap.h"

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif  /*RTE_DOIP_H*/


