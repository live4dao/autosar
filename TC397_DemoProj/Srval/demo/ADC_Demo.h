/*
 * ADC_Demo.h
 *
 *  Created on: 2024年1月5日
 *      Author: Dell
 */

#ifndef SRVAL_DEMO_ADC_DEMO_H_
#define SRVAL_DEMO_ADC_DEMO_H_

#include "Adc.h"
#include "Adc_UserCfg.h"

/* Structure to store the processed values of the conversions */

typedef enum
{
    ADC_Init_Voltage = 0,
    ADC_Over_Voltage = 1,
    ADC_Under_Voltage = 2,
    ADC_Normal_Voltage = 3
} ADC_Voltage_Status;

typedef struct
{
    Adc_ValueGroupType currentValue;
    float realVoltageValue;

    float max;
    float min;

    float r1;
    float r2;
    ADC_Voltage_Status voltage_stat;
} AdcMeasureStats;

typedef enum
{
    iAN0_BATT_P = 0,
    iAN1_VDD_12V0,
    iAN2_VSYS_3V3,
    iAN3_VSYS_5V0,
    iAN4_VCCA_3V3,
    iAN6_VDD_MMC1 = 6,
    iAN7_VDD_CORE_0V8,
    iAN8_VDD_CPU_AVS,
    iAN9_VDD_MCUIO_3V3,
    iAN10_96712_1_1V8,
    iAN11_96712_1_1V0,
    iAN12_96712_1_1V2,
    iAN15_VDD_IO_1V2 = 15,
    iAN16_VDD_SYS_1V8,
    iAN20_PVDDIO_ETH = 20,
    iAN21_BATT_P_LDO_9V,
    iAN22_96712_1_CAM_12VSTB,
    iAN23_VDD_PERI_3V3_1,
    iAN24_96712_2_CAM_12VSTB,
    iAN25_VDD_PERI_3V3_2,
    iAN26_USS_PS,
    iAN27_M5_MCU1_3V3,
    iAN28_WAKEUP_CON,
    iAN30_VDD_IO_3V3 = 30
} ADC_PIN_INDEX;

void DemoAdcInit();
void DemoAdc();
ADC_Voltage_Status GetAdcStatus(ADC_PIN_INDEX index);
#endif /* SRVAL_DEMO_ADC_DEMO_H_ */
