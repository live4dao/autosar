/*
 * ADC_Demo.c
 *
 *  Created on: 2024年1月5日
 *      Author: Dell
 */
#pragma optimize 0
#include "Std_Types.h"
#include "Adc.h"
#include "ADC_Demo.h"
#include "Uart_Demo.h"
#include "IfxSrc_reg.h"
#include "Irq.h"

#include "Adc_UserCfg.h"

typedef enum
{
    ADC_Convert_Idle = 0,
    ADC_Convert_Busy = 1,
    ADC_Convert_Finish = 2
} ADC_Convert_Flag;

typedef struct
{
    uint16 uiIRCnt;
    volatile ADC_Convert_Flag AdcConvertFlag[6];
    float fBatteryFactor;
    float fBatteryDiode;
    float fBatteryVoltage;
    float fIgniteFactor;
    float fIgniteDiode;
    float fIgniteVoltage;
    float fPcbFactor;
    float fPcbTemperature;
    float fVDD;
    float fVDDP3;
    float isEolCompleted;
} stADC_Convert_Cfg;

// Setup ADC Group0 channel
static AdcMeasureStats AN0_BATT_P, AN1_VDD_12V0, AN2_VSYS_3V3, AN3_VSYS_5V0, AN4_VCCA_3V3, AN6_VDD_MMC1,
    AN7_VDD_CORE_0V8;
const AdcMeasureStats *AdcMeasureGroup0[7] = {&AN0_BATT_P, &AN1_VDD_12V0, &AN2_VSYS_3V3, &AN3_VSYS_5V0, &AN4_VCCA_3V3,
                                              &AN6_VDD_MMC1, &AN7_VDD_CORE_0V8};

// Setup ADC Group1 channel
static AdcMeasureStats AN8_VDD_CPU_AVS, AN9_VDD_MCUIO_3V3, AN10_96712_1_1V8, AN11_96712_1_1V0, AN12_96712_1_1V2,
    AN15_VDD_IO_1V2;
const AdcMeasureStats *AdcMeasureGroup1[6] = {&AN8_VDD_CPU_AVS, &AN9_VDD_MCUIO_3V3, &AN10_96712_1_1V8,
                                              &AN11_96712_1_1V0, &AN12_96712_1_1V2, &AN15_VDD_IO_1V2};

// Setup ADC Group2 channel
static AdcMeasureStats AN16_VDD_SYS_1V8, AN20_PVDDIO_ETH, AN21_BATT_P_LDO_9V, AN22_96712_1_CAM_12VSTB,
    AN23_VDD_PERI_3V3_1;
const AdcMeasureStats *AdcMeasureGroup2[5] = {&AN16_VDD_SYS_1V8, &AN20_PVDDIO_ETH, &AN21_BATT_P_LDO_9V,
                                              &AN22_96712_1_CAM_12VSTB, &AN23_VDD_PERI_3V3_1};

// Setup ADC Group3 channel
static AdcMeasureStats AN24_96712_2_CAM_12VSTB, AN25_VDD_PERI_3V3_2, AN26_USS_PS, AN27_M5_MCU1_3V3, AN28_WAKEUP_CON,
    AN30_VDD_IO_3V3;
const AdcMeasureStats *AdcMeasureGroup3[6] = {&AN24_96712_2_CAM_12VSTB, &AN25_VDD_PERI_3V3_2, &AN26_USS_PS,
                                              &AN27_M5_MCU1_3V3, &AN28_WAKEUP_CON, &AN30_VDD_IO_3V3};

stADC_Convert_Cfg g_stAdcCfg;
Adc_GroupType Group0, Group1, Group2, Group3;

Std_ReturnType lRetVal;
Std_ReturnType Read_Err;

Adc_ValueGroupType DataBufferG0Ptr[14]; // Assuming buffer size of 7 is sufficient for the AdcChannel group0 being depicted
Adc_ValueGroupType DataBufferG1Ptr[12]; // Assuming buffer size of 6 is sufficient for the AdcChannel group1 being depicted
Adc_ValueGroupType DataBufferG2Ptr[10]; // Assuming buffer size of 10 is sufficient for the AdcChannel group2 being depicted
Adc_ValueGroupType DataBufferG3Ptr[12]; // Assuming buffer size of 10 is sufficient for the AdcChannel group3 being depicted

extern void delay_ms(uint32 ms);

void SetupAdcChannelLimit(AdcMeasureStats *m, float max, float min)
{
    m->max = max;
    m->min = min;
}
void SetupAdcChannelDIV(AdcMeasureStats *m, float r1, float r2)
{
    m->r1 = r1;
    m->r2 = r2;
}
void UpdateAdcChannel(AdcMeasureStats *m, Adc_ValueGroupType Data)
{
    float convertRate;
    uint8 ret = 0;

    m->currentValue = Data;

    if (m->r1 == 0)
    {
        convertRate = 1;
    }
    else
    {
        convertRate = m->r1 / (m->r1 + m->r2);
    }
    //    m->realVoltageValue = m->currentValue * VOLT_CONVERSION / convertRate;
    m->realVoltageValue = m->currentValue * VOLT_CONVERSION;
    if (m->max < m->realVoltageValue)
    {
        // call event callback function
//        debug_printf(" %d , %2f , overVol \r\n", m->currentValue, m->realVoltageValue);
        m->voltage_stat = ADC_Over_Voltage;
    }
    else if (m->min > m->realVoltageValue)
    {
        // call event callback function
//        debug_printf(" %d , %2f , underVol \r\n", m->currentValue, m->realVoltageValue);
        m->voltage_stat = ADC_Under_Voltage;
    }
    else
    {
//        debug_printf(" %d , %2f , normalVol \r\n", m->currentValue, m->realVoltageValue);
        m->voltage_stat = ADC_Normal_Voltage;
    }
}

void InitAdcMeasureGroup()
{
    // Group 0

    SetupAdcChannelLimit(&AN0_BATT_P, 1.45, 0.81);
    SetupAdcChannelDIV(&AN0_BATT_P, 1, 10);

    SetupAdcChannelLimit(&AN1_VDD_12V0, 2.64, 2.16);
    SetupAdcChannelDIV(&AN1_VDD_12V0, 2.49, 10);

    SetupAdcChannelLimit(&AN2_VSYS_3V3, 3.3, 1.49);
    SetupAdcChannelDIV(&AN2_VSYS_3V3, 10, 10);

    SetupAdcChannelLimit(&AN3_VSYS_5V0, 2.75, 2.25);
    SetupAdcChannelDIV(&AN3_VSYS_5V0, 10, 10);

    SetupAdcChannelLimit(&AN4_VCCA_3V3, 3.3, 1.49);
    SetupAdcChannelDIV(&AN4_VCCA_3V3, 10, 10);

    SetupAdcChannelLimit(&AN6_VDD_MMC1, 3.3, 1.49);
    SetupAdcChannelDIV(&AN6_VDD_MMC1, 10, 10);

    SetupAdcChannelLimit(&AN7_VDD_CORE_0V8, 3.3, 0.72);
    SetupAdcChannelDIV(&AN7_VDD_CORE_0V8, 0, 10);

    // Group 1
    SetupAdcChannelLimit(&AN8_VDD_CPU_AVS, 3.3, 0.72);
    SetupAdcChannelDIV(&AN8_VDD_CPU_AVS, 0, 10);

    SetupAdcChannelLimit(&AN9_VDD_MCUIO_3V3, 3.3, 1.49);
    SetupAdcChannelDIV(&AN9_VDD_MCUIO_3V3, 10, 10);

    SetupAdcChannelLimit(&AN10_96712_1_1V8, 1.89, 1.71);
    SetupAdcChannelDIV(&AN10_96712_1_1V8, 0, 10);

    SetupAdcChannelLimit(&AN11_96712_1_1V0, 1.05, 0.95);
    SetupAdcChannelDIV(&AN11_96712_1_1V0, 0, 10);

    SetupAdcChannelLimit(&AN12_96712_1_1V2, 1.26, 1.14);
    SetupAdcChannelDIV(&AN12_96712_1_1V2, 0, 10);

    SetupAdcChannelLimit(&AN15_VDD_IO_1V2, 1.26, 1.14);
    SetupAdcChannelDIV(&AN15_VDD_IO_1V2, 0, 10);

    // Group 2
    SetupAdcChannelLimit(&AN16_VDD_SYS_1V8, 3.3, 1.62);
    SetupAdcChannelDIV(&AN16_VDD_SYS_1V8, 0, 10);

    SetupAdcChannelLimit(&AN20_PVDDIO_ETH, 1.75, 1.55);
    SetupAdcChannelDIV(&AN20_PVDDIO_ETH, 10, 10);

    SetupAdcChannelLimit(&AN21_BATT_P_LDO_9V, 3.3, 0.9);
    SetupAdcChannelDIV(&AN21_BATT_P_LDO_9V, 2.49, 10);

    SetupAdcChannelLimit(&AN22_96712_1_CAM_12VSTB, 2.64, 2.16);
    SetupAdcChannelDIV(&AN22_96712_1_CAM_12VSTB, 2.49, 10);

    SetupAdcChannelLimit(&AN23_VDD_PERI_3V3_1, 3.3, 1.49);
    SetupAdcChannelDIV(&AN23_VDD_PERI_3V3_1, 10, 10);

    // Group 3

    SetupAdcChannelLimit(&AN24_96712_2_CAM_12VSTB, 2.64, 2.16);
    SetupAdcChannelDIV(&AN24_96712_2_CAM_12VSTB, 2.49, 10);

    SetupAdcChannelLimit(&AN25_VDD_PERI_3V3_2, 3.3, 1.49);
    SetupAdcChannelDIV(&AN25_VDD_PERI_3V3_2, 10, 10);

    SetupAdcChannelLimit(&AN26_USS_PS, 1.84, 1.76);
    SetupAdcChannelDIV(&AN26_USS_PS, 2.49, 10);

    SetupAdcChannelLimit(&AN27_M5_MCU1_3V3, 3.3, 1.49);
    SetupAdcChannelDIV(&AN27_M5_MCU1_3V3, 10, 10);

    //    SetupAdcChannelLimit(AN28_WAKEUP_CON, 3.3, 1.49);
    //    SetupAdcChannelDIV( &AN28_WAKEUP_CON, 2.49, 10);

    SetupAdcChannelLimit(&AN30_VDD_IO_3V3, 3.3, 1.49);
    SetupAdcChannelDIV(&AN30_VDD_IO_3V3, 10, 10);
};

void IoHwAb_AdcNotificationG0()
{
    g_stAdcCfg.AdcConvertFlag[0] = ADC_Convert_Finish;
}

void IoHwAb_AdcNotificationG1()
{
    g_stAdcCfg.AdcConvertFlag[1] = ADC_Convert_Finish;
}

void IoHwAb_AdcNotificationG2()
{
    g_stAdcCfg.AdcConvertFlag[2] = ADC_Convert_Finish;
}

void IoHwAb_AdcNotificationG3()
{
    g_stAdcCfg.AdcConvertFlag[3] = ADC_Convert_Finish;
}

void DemoAdcInit()
{
    Adc_Init(&Adc_Config);
    InitAdcMeasureGroup();
    /* ADC Startup Calibration */
    Adc_TriggerStartupCal();
    /* Wait till the Start Calibration is over*/
    while (Adc_GetStartupCalStatus() != ADC_STARTUP_CALIB_OVER)
        ;
    /* Initialize the SRPN and TOS for used interrupts */
    IrqAdc_Init();
    /* Enable Interrupts for used ADC HW units(x) */
    SRC_VADC_G0_SR0.B.SRE = 1U;
    SRC_VADC_G1_SR0.B.SRE = 1U;
    SRC_VADC_G2_SR0.B.SRE = 1U;
    SRC_VADC_G3_SR0.B.SRE = 1U;
    //    SRC_VADC_G2_SR1.B.SRE = 1U;
    //    SRC_VADC_G2_SR2.B.SRE = 1U;
}


void UpdateAdcGroup0()
{
    boolean fault_flag = FALSE;

    for (int i = 0; i < ADC_GROUP0_CHANNEL_NUM; i++)
    {
        if(AdcMeasureGroup0[i] != NULL_PTR)
        UpdateAdcChannel(AdcMeasureGroup0[i], DataBufferG0Ptr[i]);
    }

//    debug_printf("\r\n");
}
void UpdateAdcGroup1()
{
    for (int i = 0; i < ADC_GROUP1_CHANNEL_NUM; i++)
    {
        if(AdcMeasureGroup0[i] != NULL_PTR)
        UpdateAdcChannel(AdcMeasureGroup1[i], DataBufferG1Ptr[i]);
    }
//    debug_printf("\r\n");
}
void UpdateAdcGroup2()
{
    for (int i = 0; i < ADC_GROUP2_CHANNEL_NUM; i++)
    {
        if(AdcMeasureGroup0[i] != NULL_PTR)
        UpdateAdcChannel(AdcMeasureGroup2[i], DataBufferG2Ptr[i]);
    }
//    debug_printf("\r\n");
}
void UpdateAdcGroup3()
{
    for (int i = 0; i < ADC_GROUP3_CHANNEL_NUM; i++)
    {
        if(AdcMeasureGroup0[i] != NULL_PTR)
        UpdateAdcChannel(AdcMeasureGroup3[i], DataBufferG3Ptr[i]);
    }
//    debug_printf("\r\n");
}
ADC_Voltage_Status GetAdcStatus(ADC_PIN_INDEX index)
{
    ADC_Voltage_Status ret;
    switch (index)
    {
    case iAN0_BATT_P:
        ret = AN0_BATT_P.voltage_stat;
        break;
    case iAN1_VDD_12V0:
        ret = AN1_VDD_12V0.voltage_stat;
        break;
    case iAN2_VSYS_3V3:
        ret = AN2_VSYS_3V3.voltage_stat;
        break;
    case iAN3_VSYS_5V0:
        ret = AN3_VSYS_5V0.voltage_stat;
        break;
    case iAN4_VCCA_3V3:
        ret = AN4_VCCA_3V3.voltage_stat;
        break;
    case iAN6_VDD_MMC1:
        ret = AN6_VDD_MMC1.voltage_stat;
        break;
    case iAN7_VDD_CORE_0V8:
        ret = AN7_VDD_CORE_0V8.voltage_stat;
        break;
    case iAN8_VDD_CPU_AVS:
        ret = AN8_VDD_CPU_AVS.voltage_stat;
        break;
    case iAN9_VDD_MCUIO_3V3:
        ret = AN9_VDD_MCUIO_3V3.voltage_stat;
        break;
    case iAN10_96712_1_1V8:
        ret = AN10_96712_1_1V8.voltage_stat;
        break;
    case iAN11_96712_1_1V0:
        ret = AN11_96712_1_1V0.voltage_stat;
        break;
    case iAN12_96712_1_1V2:
        ret = AN12_96712_1_1V2.voltage_stat;
        break;
    case iAN15_VDD_IO_1V2:
        ret = AN15_VDD_IO_1V2.voltage_stat;
        break;
    case iAN16_VDD_SYS_1V8:
        ret = AN16_VDD_SYS_1V8.voltage_stat;
        break;
    case iAN20_PVDDIO_ETH:
        ret = AN20_PVDDIO_ETH.voltage_stat;
        break;
    case iAN21_BATT_P_LDO_9V:
        ret = AN21_BATT_P_LDO_9V.voltage_stat;
        break;
    case iAN22_96712_1_CAM_12VSTB:
        ret = AN22_96712_1_CAM_12VSTB.voltage_stat;
        break;
    case iAN23_VDD_PERI_3V3_1:
        ret = AN23_VDD_PERI_3V3_1.voltage_stat;
        break;
    case iAN24_96712_2_CAM_12VSTB:
        ret = AN24_96712_2_CAM_12VSTB.voltage_stat;
        break;
    case iAN25_VDD_PERI_3V3_2:
        ret = AN25_VDD_PERI_3V3_2.voltage_stat;
        break;
    case iAN26_USS_PS:
        ret = AN26_USS_PS.voltage_stat;
        break;
    case iAN27_M5_MCU1_3V3:
        ret = AN27_M5_MCU1_3V3.voltage_stat;
        break;
    case iAN28_WAKEUP_CON:
        ret = AN28_WAKEUP_CON.voltage_stat;
        break;
    case iAN30_VDD_IO_3V3:
        ret = AN30_VDD_IO_3V3.voltage_stat;
        break;
    default:
        break;
    }
    return ret;
}
void DemoAdc()
{
    Group0 = AdcConf_AdcGroup_AdcGroup_0;
    Group1 = AdcConf_AdcGroup_AdcGroup_1;
    Group2 = AdcConf_AdcGroup_AdcGroup_2;
    Group3 = AdcConf_AdcGroup_AdcGroup_3;

    Adc_EnableGroupNotification(Group0);
    Adc_EnableGroupNotification(Group1);
    Adc_EnableGroupNotification(Group2);
    Adc_EnableGroupNotification(Group3);

    lRetVal = Adc_SetupResultBuffer(Group0, &DataBufferG0Ptr[0]);
    if (lRetVal != E_NOT_OK)
    {
        Adc_StartGroupConversion(Group0);
    }
    else
    {
        /*Could not setup result buffer*/
    }
    lRetVal = Adc_SetupResultBuffer(Group1, &DataBufferG1Ptr[0]);
    if (lRetVal != E_NOT_OK)
    {
        Adc_StartGroupConversion(Group1);
    }
    else
    {
        /*Could not setup result buffer*/
    }

    lRetVal = Adc_SetupResultBuffer(Group2, &DataBufferG2Ptr[0]);
    if (lRetVal != E_NOT_OK)
    {
        Adc_StartGroupConversion(Group2);
    }
    else
    {
        /*Could not setup result buffer*/
    }

    lRetVal = Adc_SetupResultBuffer(Group3, &DataBufferG3Ptr[0]);
    if (lRetVal != E_NOT_OK)
    {
        Adc_StartGroupConversion(Group3);
    }
    else
    {
        /*Could not setup result buffer*/
    }

    for (int i = 0; i <= 3;)
    {

        if (g_stAdcCfg.AdcConvertFlag[i] == ADC_Convert_Finish)
        {
            g_stAdcCfg.AdcConvertFlag[i] = ADC_Convert_Idle;
            i++;
        }
    }
    Read_Err = Adc_ReadGroup(Group0, &DataBufferG0Ptr[0]);
    if (Read_Err != E_NOT_OK)
    {
        /*Adc read group is successful*/
        UpdateAdcGroup0();
    }
    Read_Err = Adc_ReadGroup(Group1, &DataBufferG1Ptr[0]);
    if (Read_Err != E_NOT_OK)
    {
        /*Adc read group is successful*/
        UpdateAdcGroup1();
    }
    Read_Err = Adc_ReadGroup(Group2, &DataBufferG2Ptr[0]);
    if (Read_Err != E_NOT_OK)
    {
        /*Adc read group is successful*/
        UpdateAdcGroup2();
    }
    Read_Err = Adc_ReadGroup(Group3, &DataBufferG3Ptr[0]);
    if (Read_Err != E_NOT_OK)
    {
        /*Adc read group is successful*/
        UpdateAdcGroup3();
    }
}
