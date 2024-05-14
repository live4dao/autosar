/******************************************************************************
;       Program     :   PinIO.c
;       Function    :   GPIO sensing
;       Chip        :   Infineon TC397
;       Clock       :   Internal SYSPLL 300MHz
;       Date        :   2023 / 12 / 27
;       Author      :   Fenderson Lu
;       Describe    :   Power Control pins
;
******************************************************************************/
//---------------------------- Include File ----------------------------------//
#include "Power_Manager.h"

//---------------------------- Declare Global Variable -----------------------//

//---------------------------- Start Program ---------------------------------//
void PinIO_Pwr_On_Sequence(void)
{
    Dio_WriteChannel(DioConf_DioChannel_portPOWER_EN_5141, STD_HIGH); /* DIO_CHANNEL_20_11 */
    Dio_WriteChannel(DioConf_DioChannel_portUSS_PWR_EN_TC397, STD_HIGH); /* DIO_CHANNEL_20_11 */   
}
//-------------------------------------------------------------------------//
