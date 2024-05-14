#ifndef ADC_USER_CONFIG_H
#define ADC_USER_CONFIG_H


#define EVADC_MAX           4095            /* Maximum value (conversion results are expressed in 12-bit format)    */
#define EVADC_MIN           0               /* Minimum value of a conversion result                                 */
#define VOLT_CONVERSION     3.3 / EVADC_MAX /* Conversion factor from ADC value to voltage (V)                      */

#define ADC_GROUP0_CHANNEL_NUM 7
#define ADC_GROUP1_CHANNEL_NUM 6
#define ADC_GROUP2_CHANNEL_NUM 5
#define ADC_GROUP3_CHANNEL_NUM 6

#define AN0_VOL_MAX 1.45
#define AN0_VOL_MIN 0.81
#define AN0_DIV_R1 1
#define AN0_DIV_R2 10



#endif