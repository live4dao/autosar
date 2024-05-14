/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : CC_ADAS_TIME_SYNC_SWC.c
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
/*******************************************************************************
*   Includes.
*******************************************************************************/
#include "Rte_CC_ADAS_TIME_SYNC_SWC.h"

/* CC_ADAS_TIME_SYNC_SWCInput File User Code start*/

/* CC_ADAS_TIME_SYNC_SWCInput File User Code end*/

/* CC_ADAS_TIME_SYNC_SWC.c Custom Code (#define variable etc.) User Code start*/

/* CC_ADAS_TIME_SYNC_SWC.c Custom Code (#define variable etc.) User Code end*/

/*******************************************************************************
*   Runnable Extended
*******************************************************************************/

#define CC_ADAS_TIME_SYNC_SWC_START_SEC_CODE
#include "CC_ADAS_TIME_SYNC_SWC_MemMap.h"

FUNC(void, CC_ADAS_TIME_SYNC_SWC_CODE) CC_ADAS_TIME_SYNC_SWC_500ms
(
    void
)
{
    /* CC_ADAS_TIME_SYNC_SWC_500ms_Start User Code start*/

    /* CC_ADAS_TIME_SYNC_SWC_500ms_Start User Code end*/
    GPSSystAtv_IDT Read_GPSSystAtv_GPSSystAtv;
    Time_Day_IDT Read_Time_Day_Time_Day;
    Time_Hour_IDT Read_Time_Hour_Time_Hour;
    Time_Minute_IDT Read_Time_Minute_Time_Minute;
    Time_Month_IDT Read_Time_Month_Time_Month;
    Time_Year_IDT Read_Time_Year_Time_Year;
    Time_second_IDT Read_Time_second_Time_second;
    StbM_TimeStampType Call_GlobalTime_Master_StbMSynchronizedTimeBase_SetGlobalTime_timeStampPtr;
    StbM_UserDataType Call_GlobalTime_Master_StbMSynchronizedTimeBase_SetGlobalTime_userDataPtr;
    /* CC_ADAS_TIME_SYNC_SWC_500ms Varaible Define User Code start*/

    /* CC_ADAS_TIME_SYNC_SWC_500ms Varaible Define User Code end*/




    Rte_Read_GPSSystAtv_GPSSystAtv(&Read_GPSSystAtv_GPSSystAtv);
    /* Rte_Read_GPSSystAtv_GPSSystAtv User Code start*/

    /* Rte_Read_GPSSystAtv_GPSSystAtv User Code end*/
    Rte_Read_Time_Day_Time_Day(&Read_Time_Day_Time_Day);
    /* Rte_Read_Time_Day_Time_Day User Code start*/

    /* Rte_Read_Time_Day_Time_Day User Code end*/
    Rte_Read_Time_Hour_Time_Hour(&Read_Time_Hour_Time_Hour);
    /* Rte_Read_Time_Hour_Time_Hour User Code start*/

    /* Rte_Read_Time_Hour_Time_Hour User Code end*/
    Rte_Read_Time_Minute_Time_Minute(&Read_Time_Minute_Time_Minute);
    /* Rte_Read_Time_Minute_Time_Minute User Code start*/

    /* Rte_Read_Time_Minute_Time_Minute User Code end*/
    Rte_Read_Time_Month_Time_Month(&Read_Time_Month_Time_Month);
    /* Rte_Read_Time_Month_Time_Month User Code start*/

    /* Rte_Read_Time_Month_Time_Month User Code end*/
    Rte_Read_Time_Year_Time_Year(&Read_Time_Year_Time_Year);
    /* Rte_Read_Time_Year_Time_Year User Code start*/

    /* Rte_Read_Time_Year_Time_Year User Code end*/
    Rte_Read_Time_second_Time_second(&Read_Time_second_Time_second);
    /* Rte_Read_Time_second_Time_second User Code start*/

    /* Rte_Read_Time_second_Time_second User Code end*/
    Rte_Call_GlobalTime_Master_StbMSynchronizedTimeBase_SetGlobalTime(Call_GlobalTime_Master_StbMSynchronizedTimeBase_SetGlobalTime_timeStampPtr,Call_GlobalTime_Master_StbMSynchronizedTimeBase_SetGlobalTime_userDataPtr);
    /* Rte_Call_GlobalTime_Master_StbMSynchronizedTimeBase_SetGlobalTime User Code start*/

    /* Rte_Call_GlobalTime_Master_StbMSynchronizedTimeBase_SetGlobalTime User Code end*/
    /* CC_ADAS_TIME_SYNC_SWC_500ms_Feedback User Code start*/

    /* CC_ADAS_TIME_SYNC_SWC_500ms_Feedback User Code end*/

}
#define CC_ADAS_TIME_SYNC_SWC_STOP_SEC_CODE
#include "CC_ADAS_TIME_SYNC_SWC_MemMap.h"




