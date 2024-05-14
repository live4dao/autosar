#include "Std_Types.h"
#include "PowerDiagnosis.h"

#include "ADC_Demo.h"
#include "TLF35584.h"
#include "Dio.h"
#include "Dio.h"
#include "Dem.h"

#define BATT_CHECK_LIST_SIZE 1
#define LM5141_CHECK_LIST_SIZE 7
#define CAM_CHECK_LIST_SIZE 3
#define DP83TC_CHECK_LIST_SIZE 1
#define TLF35584_CHECK_LIST_SIZE 1

uint8 testflag = 0 ;
uint8 testcount = 0 ;
boolean Fault_current_of_VBAT_TEG()
{
    Dio_LevelType flt_74910_state;
//    flt_74910_state = Dio_ReadChannel(DioConf_DioChannel_FLT_74910);
#if CDD_DEM_ENABLED    
    if (flt_74910_state == STD_HIGH)
    {
        Dem_SetEventStatus(Dem_Event_0x94001D, DEM_EVENT_STATUS_PREFAILED);
    }
    else
    {
         Dem_SetEventStatus(Dem_Event_0x94001D, DEM_EVENT_STATUS_PREPASSED);
    }
#endif

return (boolean)flt_74910_state;
}

boolean Fault_BattLow()
{
    boolean fault_flag = FALSE;
    ADC_Voltage_Status ret;

    uint8 check_list[TLF35584_CHECK_LIST_SIZE] = {iAN0_BATT_P};

    for (int i = 0; i < BATT_CHECK_LIST_SIZE; i++)
    {
        ret = GetAdcStatus(check_list[i]);
        if (ret == ADC_Under_Voltage || ret == ADC_Over_Voltage)
        {
            fault_flag = TRUE;
        }
    }
#if CDD_DEM_ENABLED
    if (fault_flag)
    {
        Dem_SetEventStatus(Dem_Event_0x9404A2, DEM_EVENT_STATUS_PREFAILED);  
    }else{
        Dem_SetEventStatus(Dem_Event_0x9404A2, DEM_EVENT_STATUS_PREPASSED);
    }
#endif
    return fault_flag;
}
// boolean Fault_BattHigh()
// {
//     boolean fault_flag = FALSE;
//     ADC_Voltage_Status ret;

//     uint8 check_list[TLF35584_CHECK_LIST_SIZE] = {iAN0_BATT_P};

//     for (int i = 0; i < BATT_CHECK_LIST_SIZE; i++)
//     {
//         ret = GetAdcStatus(check_list[i]);
//         if (ret == ADC_Over_Voltage)
//         {
//             fault_flag = TRUE;
//             debug_printf("index=%d,status =%d \r\n", i, ret);
//         }
//     }
// #if CDD_DEM_ENABLED
//     if (fault_flag)
//     {
//         Dem_SetEventStatus(Dem_Event_0x9404A3, DEM_EVENT_STATUS_PREFAILED);  
//     }else{
//         Dem_SetEventStatus(Dem_Event_0x9404A3, DEM_EVENT_STATUS_PREPASSED);
//     }
// #endif
//     return fault_flag;
// }

boolean Fault_OutputVoltage_of_TLF35584()
{

    boolean fault_flag = FALSE;
    ADC_Voltage_Status ret;

    uint8 check_list[TLF35584_CHECK_LIST_SIZE] = {iAN27_M5_MCU1_3V3};

    UpdatePowerFlagsTLF35584(&g_tlfDevice);
    // Check V_UC (corresponds to LDO_μC) voltage
    if (g_tlfDevice.MONSF0.B.UCSG == ShortToGround_detected || g_tlfDevice.MONSF1.B.UCOV == OverVoltage_detected || g_tlfDevice.MONSF2.B.UCUV == UnderVoltage_detected)
    {
        fault_flag = TRUE;
    }
    // Check P5V (corresponds to LDO_Com) voltage
    if (g_tlfDevice.MONSF0.B.COMSG == ShortToGround_detected || g_tlfDevice.MONSF1.B.COMOV == OverVoltage_detected || g_tlfDevice.MONSF2.B.COMUV == UnderVoltage_detected)
    {
        fault_flag = TRUE;
    }
    // Check V_PREREG (corresponds to PreReg) voltage
    if (g_tlfDevice.MONSF0.B.PREGSG == ShortToGround_detected || g_tlfDevice.MONSF1.B.PREGOV == OverVoltage_detected || g_tlfDevice.MONSF2.B.PREGUV == UnderVoltage_detected)
    {
        fault_flag = TRUE;
    }
    // Check P1V25 (corresponds to Core_Sup) voltage
    if (g_tlfDevice.MONSF0.B.VCORESG == ShortToGround_detected || g_tlfDevice.MONSF1.B.VCOREOV == OverVoltage_detected || g_tlfDevice.MONSF2.B.VCOREUV == UnderVoltage_detected)
    {
        fault_flag = TRUE;
    }

    // Check QST (corresponds to LDO_Stby) voltage
    if (g_tlfDevice.MONSF0.B.STBYSG == ShortToGround_detected || g_tlfDevice.MONSF1.B.STBYOV == OverVoltage_detected || g_tlfDevice.MONSF2.B.STBYUV == UnderVoltage_detected)
    {
        fault_flag = TRUE;
    }

    for (int i = 0; i < TLF35584_CHECK_LIST_SIZE; i++)
    {
        ret = GetAdcStatus(check_list[i]);
        if (ret != ADC_Normal_Voltage)
        {
            fault_flag = TRUE;
        }
    }
#if CDD_DEM_ENABLED
    if (fault_flag)
    {
        Dem_SetEventStatus(Dem_Event_0x94001C, DEM_EVENT_STATUS_PREFAILED);
    }
    else
    {
        Dem_SetEventStatus(Dem_Event_0x94001C, DEM_EVENT_STATUS_PREPASSED);
    }
#endif

    return fault_flag;
}

boolean Fault_OutputVoltage_of_LM5141()
{
    boolean fault_flag = FALSE;
    ADC_Voltage_Status ret;
    // TODO: need add MCU_CAN_5V

    uint8 check_list[LM5141_CHECK_LIST_SIZE] = {iAN1_VDD_12V0, iAN2_VSYS_3V3, iAN3_VSYS_5V0, iAN15_VDD_IO_1V2,
                                                iAN16_VDD_SYS_1V8, iAN21_BATT_P_LDO_9V, iAN26_USS_PS};
    for (int i = 0; i < LM5141_CHECK_LIST_SIZE; i++)
    {
        ret = GetAdcStatus(check_list[i]);
        if (ret != ADC_Normal_Voltage)
        {
            fault_flag = TRUE;
        }
    }
#if CDD_DEM_ENABLED
    if (fault_flag)
    {
        Dem_SetEventStatus(Dem_Event_0x94021C, DEM_EVENT_STATUS_PREFAILED);
    }
    else
    {
        Dem_SetEventStatus(Dem_Event_0x94021C, DEM_EVENT_STATUS_PREPASSED);
    }
#endif

    return fault_flag;
}
boolean Fault_Voltage_of_DP83TC812RRHARQ1()
{
    boolean fault_flag = FALSE;
    ADC_Voltage_Status ret;

    uint8 check_list[DP83TC_CHECK_LIST_SIZE] = {iAN20_PVDDIO_ETH};
    for (int i = 0; i < DP83TC_CHECK_LIST_SIZE; i++)
    {
        ret = GetAdcStatus(check_list[i]);
        if (ret != ADC_Normal_Voltage)
        {
            fault_flag = TRUE;
        }
    }

#if CDD_DEM_ENABLED
    if (fault_flag)
    {
        Dem_SetEventStatus(Dem_Event_0x94031C, DEM_EVENT_STATUS_PREFAILED);
    }
    else
    {
        Dem_SetEventStatus(Dem_Event_0x94031C, DEM_EVENT_STATUS_PREPASSED);
    }
#endif

    return fault_flag;
}

boolean Fault_CAM_Voltage_Abnormal()
{

    boolean fault_flag = FALSE;
    ADC_Voltage_Status ret;

    uint8 check_list[CAM_CHECK_LIST_SIZE] = {iAN10_96712_1_1V8, iAN11_96712_1_1V0, iAN12_96712_1_1V2};
    for (int i = 0; i < CAM_CHECK_LIST_SIZE; i++)
    {
        ret = GetAdcStatus(check_list[i]);
        if (ret != ADC_Normal_Voltage)
        {
            fault_flag = TRUE;
        }
    }
#if CDD_DEM_ENABLED
    if (fault_flag)
    {
        Dem_SetEventStatus(Dem_Event_0x94051C, DEM_EVENT_STATUS_PREFAILED);
    }
    else
    {
        Dem_SetEventStatus(Dem_Event_0x94051C, DEM_EVENT_STATUS_PREPASSED);
    }
#endif
    return fault_flag;
}
