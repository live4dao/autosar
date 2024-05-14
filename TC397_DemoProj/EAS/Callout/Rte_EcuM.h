/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : Rte_EcuM.h
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
#ifndef RTE_ECUM_H
#define RTE_ECUM_H

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
#include "EcuM.h"
#include "Rte_EcuM_Type.h"
#define RTE_START_SEC_CODE
#include "MemMap.h"

#define Rte_Call_AlarmClock_User0_AbortWakeupAlarm()        EcuM_AbortWakeupAlarm(ECUM_USER0)
#define Rte_Call_AlarmClock_User0_SetAbsWakeupAlarm(time)   EcuM_SetAbsWakeupAlarm(ECUM_USER0, time)
#define Rte_Call_AlarmClock_User0_SetClock(time)            EcuM_SetClock(ECUM_USER0, time)
#define Rte_Call_AlarmClock_User0_SetRelWakeupAlarm(time)   EcuM_SetRelWakeupAlarm(ECUM_USER0, time)
#define Rte_Call_BootTarget_User0_GetBootTarget(target)     EcuM_GetBootTarget(target)
#define Rte_Call_BootTarget_User0_SelectBootTarget(target)  EcuM_SelectBootTarget(target)
#define Rte_Call_ShutdownTarget_User0_GetLastShutdownTarget(shutdownTarget, shutdownMode) EcuM_GetLastShutdownTarget(shutdownTarget, shutdownMode)
#define Rte_Call_ShutdownTarget_User0_GetShutdownTarget(shutdownTarget, shutdownMode)     EcuM_GetShutdownTarget(shutdownTarget, shutdownMode)
#define Rte_Call_ShutdownTarget_User0_SelectShutdownTarget(shutdownTarget, shutdownMode)  EcuM_SelectShutdownTarget(shutdownTarget, shutdownMode)
#define Rte_Call_ShutdownTarget_User0_GetShutdownCause(shutdownMode)  EcuM_GetShutdownCause(shutdownMode)
#define Rte_Call_ShutdownTarget_User0_SelectShutdownCause(shutdownMode)         EcuM_SelectShutdownCause(shutdownMode)
#define Rte_Call_StateRequest_User0_ReleasePOSTRUN()        EcuM_ReleasePOST_RUN(ECUM_USER0)
#define Rte_Call_StateRequest_User0_ReleaseRUN()            EcuM_ReleaseRUN(ECUM_USER0)
#define Rte_Call_StateRequest_User0_RequestPOSTRUN()        EcuM_RequestPOST_RUN(ECUM_USER0)
#define Rte_Call_StateRequest_User0_RequestRUN()            EcuM_RequestRUN(ECUM_USER0)
#define Rte_Call_time_GetCurrentTime(time)                  EcuM_GetCurrentTime(time)
#define Rte_Call_time_GetWakeupTime(time)                   EcuM_GetWakeupTime(time)
#define Rte_Switch_CurrentMode_EcuM_Mode                    Rte_Switch_EcuM_CurrentMode_EcuM_Mode
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Switch_EcuM_CurrentMode_EcuM_Mode
(
    VAR(Rte_ModeType_EcuM_Mode, AUTOMATIC) nextMode
);

#define RTE_STOP_SEC_CODE
#include "MemMap.h"

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif  /*RTE_ECUM_H*/


