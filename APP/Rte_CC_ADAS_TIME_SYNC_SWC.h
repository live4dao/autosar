/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : Rte_CC_ADAS_TIME_SYNC_SWC.h
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
*   V1.0.2_3.5.5_AZ240046       10/05/2024    Eas           N/A          N/A
*
********************************************************************************
* END_FILE_HDR*/
#ifndef RTE_CC_ADAS_TIME_SYNC_SWC_H
#define RTE_CC_ADAS_TIME_SYNC_SWC_H

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
#include "Rte_CC_ADAS_TIME_SYNC_SWC_Type.h"
#include "Com.h"
#include "StbM.h"
/*******************************************************************************
*   define for a symbolic name of the RunnableEntity.
*******************************************************************************/
#define RTE_RUNNABLE_CC_ADAS_TIME_SYNC_SWC_500ms            CC_ADAS_TIME_SYNC_SWC_500ms

/*******************************************************************************
*   Instance Handle
*******************************************************************************/
#ifndef RTE_CORE
typedef CONSTP2CONST(Rte_CDS_CC_ADAS_TIME_SYNC_SWC, AUTOMATIC, RTE_CONST) Rte_Instance;
#endif

/*******************************************************************************
*   Macro definition.
*******************************************************************************/
#define Rte_Read_GPSSystAtv_GPSSystAtv                      Rte_Read_CC_ADAS_TIME_SYNC_SWC_GPSSystAtv_GPSSystAtv
#define Rte_Read_Time_Day_Time_Day                          Rte_Read_CC_ADAS_TIME_SYNC_SWC_Time_Day_Time_Day
#define Rte_Read_Time_Hour_Time_Hour                        Rte_Read_CC_ADAS_TIME_SYNC_SWC_Time_Hour_Time_Hour
#define Rte_Read_Time_Minute_Time_Minute                    Rte_Read_CC_ADAS_TIME_SYNC_SWC_Time_Minute_Time_Minute
#define Rte_Read_Time_Month_Time_Month                      Rte_Read_CC_ADAS_TIME_SYNC_SWC_Time_Month_Time_Month
#define Rte_Read_Time_Year_Time_Year                        Rte_Read_CC_ADAS_TIME_SYNC_SWC_Time_Year_Time_Year
#define Rte_Read_Time_second_Time_second                    Rte_Read_CC_ADAS_TIME_SYNC_SWC_Time_second_Time_second
#define Rte_Call_GlobalTime_Master_StbMSynchronizedTimeBase_SetGlobalTime(timeStampPtr, userDataPtr)          NULL_PTR
/*******************************************************************************
*   Extended
*******************************************************************************/
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CC_ADAS_TIME_SYNC_SWC_GPSSystAtv_GPSSystAtv
(
    P2VAR(GPSSystAtv_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CC_ADAS_TIME_SYNC_SWC_Time_Day_Time_Day
(
    P2VAR(Time_Day_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CC_ADAS_TIME_SYNC_SWC_Time_Hour_Time_Hour
(
    P2VAR(Time_Hour_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CC_ADAS_TIME_SYNC_SWC_Time_Minute_Time_Minute
(
    P2VAR(Time_Minute_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CC_ADAS_TIME_SYNC_SWC_Time_Month_Time_Month
(
    P2VAR(Time_Month_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CC_ADAS_TIME_SYNC_SWC_Time_Year_Time_Year
(
    P2VAR(Time_Year_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CC_ADAS_TIME_SYNC_SWC_Time_second_Time_second
(
    P2VAR(Time_second_IDT, AUTOMATIC, RTE_APPL_DATA) data
);

/*******************************************************************************
*   Runnable Extended
*******************************************************************************/

#define CC_ADAS_TIME_SYNC_SWC_START_SEC_CODE
#include "CC_ADAS_TIME_SYNC_SWC_MemMap.h"

extern FUNC(void, CC_ADAS_TIME_SYNC_SWC_CODE) CC_ADAS_TIME_SYNC_SWC_500ms
(
    void
);
#define CC_ADAS_TIME_SYNC_SWC_STOP_SEC_CODE
#include "CC_ADAS_TIME_SYNC_SWC_MemMap.h"


# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif  /*RTE_CC_ADAS_TIME_SYNC_SWC_H*/


