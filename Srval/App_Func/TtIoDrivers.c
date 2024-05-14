/******************************************************************************
;       Program     :    TtIoDrivers.c
;       Function    :    APIs transfer to TT API format
;       Chip        :    Infineon TC397
;       Clock       :    Internal Clock 300MHz
;       Date        :    2023 / 1 / 2
;       Author      :    Fenderson Lu
;       Description:    
******************************************************************************/
//---------------------------- Include File ---------------------------------//
// #include "Cpu0_Main.h"
#include "TtIoDrivers.h"
#include "UssDrivers.h"
//---------------------------- Declare Global Variable ----------------------//


//---------------------------- Start Program --------------------------------//

/******************************************************************************
;       Function Name           :    int get_threshold(Uss_Sensor_Id_t tSensorMask)
;       Function Description    :    Read sensors threshold setup parameters.
;       Parameters              :    [Uss_Sensor_Id_t tSensorMask] - Sensors ID
;       Return Values           :    0 = Success
;                                    1 = Failure
;       Description             :    Ex. get_threshold(USS_ID_IO2_TXRX_FLM)
******************************************************************************/
int get_threshold(Uss_Sensor_Id_t tSensorMask)
{
    return (int)UssDrivers_Sensors_Thres_Get(tSensorMask);
}
/******************************************************************************
;       Function Name           :    int read_threshold(Uss_Sensor_Id_t tSensorMask, Uss_Thres_Data_t *tThresholdData)
;       Function Description    :    Get threshold setup parameters from the MCU memory.
;       Parameters              :    [Uss_Sensor_Id_t tSensorMask]        - Sensors ID
;                                    [Uss_Thres_Data_t *tThresholdData]    - Threshold setup paremeters
;       Return Values           :    0 = Success
;                                    1 = Failure
;       Description            :    Ex. read_threshold(USS_ID_IO2_TXRX_FLM, &Buff)
******************************************************************************/
int read_threshold(Uss_Sensor_Id_t tSensorMask, Uss_Thres_Data_t *tThresholdData)
{
    return (int)UssDrivers_Thres_Para_Read(tSensorMask, tThresholdData);
}
/******************************************************************************
;       Function Name           :    int write_threshold(Uss_Sensor_Id_t tSensorMask, Uss_Thres_Data_t *tThresSetupPara)
;       Function Description    :    Send and set threshold setup parameters
;       Parameters              :    [Uss_Sensor_Id_t tSensorMask]        - Sensors ID
;                                    [Uss_Thres_Data_t *tThresSetupPara]    - Threshold setup parameters
;       Return Values           :    0 = FUNC_SUCCESS
;       Description             :    Ex. write_threshold(USS_ID_IO1_TXRX_FLC, &gtUssThresSetupPara[0])
******************************************************************************/
int write_threshold(Uss_Sensor_Id_t tSensorMask, Uss_Thres_Data_t *tThresSetupPara)
{
    return (int)UssDrivers_ThresSetup_Para_Write(tSensorMask, tThresSetupPara);
}

/******************************************************************************
;       Function Name           :   int get_meas(Uss_Sensor_Id_t tSensorMask)
;       Function Description    :    Read sensors meas setup parameters.
;       Parameters              :   [Uss_Sensor_Id_t tSensorMask] - Sensors ID
;       Return Values           :   0 = Success
;                                   1 = Failure
;       Description             :   Ex. get_meas(USS_ID_IO2_TXRX_FLM)
******************************************************************************/
int get_meas(Uss_Sensor_Id_t tSensorMask)
{
    return (int)UssDrivers_Meas_Setup_Get(tSensorMask);
}

/******************************************************************************
;       Function Name           :   int read_meas(Uss_Sensor_Id_t tSensorMask, Uss_Meas_Data_t *tMeasSetupPara)
;       Function Description    :    Get meas setup parameters from the MCU memory.
;       Parameters              :   [Uss_Sensor_Id_t tSensorMask]        - Sensors ID
;                                   [Uss_Meas_Data_t *tMeasSetupPara]    - Get parameters from the MCU memory
;       Return Values           :   0 = Success
;                                   1 = Failure
;       Description             :   Ex. read_meas(tSensorMask, &Buff)
******************************************************************************/
int read_meas(Uss_Sensor_Id_t tSensorMask, Uss_Meas_Data_t *tMeasSetupPara)
{
    return (int)UssDrivers_Meas_Setup_Read(tSensorMask, tMeasSetupPara);
}

/******************************************************************************
;       Function Name           :   int write_meas(Uss_Sensor_Id_t sensor_mask, uss_meas_data_t meas_data[12])
;       Function Description    :
;       Parameters              :   [Uss_Sensor_Id_t tSensorMask]   - Sensors ID
;                                   [uint16 *u16StatusData]         - USS status
;       Return Values           :   0 = Success
;                                   1 = Failure
;       Description             :   Ex. read_status(USS_ID_IO1_TXRX_FLC, &u16Status)
******************************************************************************/
int write_meas(Uss_Sensor_Id_t sensor_mask, Uss_Meas_Data_t *tMeasSetupPara)
{
    return (int)UssDrivers_Meas_Para_Write(sensor_mask, tMeasSetupPara);
}

/******************************************************************************
;       Function Name           :    int get_calibration(Uss_Sensor_Id_t tSensorMask)
;       Function Description    :    Read sensors calibration data.
;       Parameters              :    [Uss_Sensor_Id_t tSensorMask] - Sensors ID
;       Return Values           :    0 = Success
;                                    1 = Failure
;       Description             :    Ex. get_calibration(USS_ID_IO2_TXRX_FLM)
******************************************************************************/
int get_calibration(Uss_Sensor_Id_t tSensorMask)
{
    return (int)UssDrivers_Sensors_Calib_Get(tSensorMask);
}

/******************************************************************************
;       Function Name           :    int read_calibration(Uss_Sensor_Id_t tSensorMask, Uss_Calib_Data_t *tCalibData)
;       Function Description    :    Get calibration values.
;       Parameters              :    [Uss_Sensor_Id_t tSensorMask]    - Sensors ID
;                                    [Uss_Calib_Data_t *tCalibData]    - calibration values
;       Return Values           :    0 = Success
;                                    1 = Failure
;       Description             :    Ex. read_calibration(USS_ID_IO2_TXRX_FLM, &CalibBuff)
******************************************************************************/
int read_calibration(Uss_Sensor_Id_t tSensorMask, Uss_Calib_Data_t *tCalibData)
{
    return (int)UssDrivers_Calib_Read(tSensorMask, tCalibData);
}

/******************************************************************************
;       Function Name           :    int write_calibration(Uss_Sensor_Id_t tSensorMask, Uss_Calib_Data_t *tCalibWritePara)
;       Function Description    :    Send and set calibration parameters
;       Parameters              :    [Uss_Sensor_Id_t tSensorMask]        - Sensors ID
;                                    [Uss_Calib_Data_t *tCalibWritePara]    - Calibration write parameters
;       Return Values           :    0 = FUNC_SUCCESS
;       Description             :    Ex. write_calibration(USS_ID_IO1_TXRX_FLC, &gtUssCalibWritePara)
******************************************************************************/
int write_calibration(Uss_Sensor_Id_t tSensorMask, Uss_Calib_Data_t *tCalibWritePara)
{
    return (int)UssDrivers_Calib_Write(tSensorMask, tCalibWritePara);
}

/******************************************************************************
;       Function Name           :    int get_eeprom(Uss_Sensor_Id_t tSensorMask)
;       Function Description    :    Read sensors EEPROM values.
;       Parameters              :    [Uss_Sensor_Id_t tSensorMask]    - Sensors ID
;       Return Values           :    0 = Success
;                                    1 = Failure
;       Description             :    Ex. get_eeprom(USS_ID_IO2_TXRX_FLM)
******************************************************************************/
int get_eeprom(Uss_Sensor_Id_t tSensorMask)
{
    return (int)UssDrivers_Sensors_EEPROM_Get(tSensorMask);
}

/******************************************************************************
;       Function Name           :    int read_eeprom(Uss_Sensor_Id_t tSensorMask, Uss_Calib_Data_t *tEepromData)
;       Function Description    :    Get EEPROM values from the MCU memory.
;       Parameters              :    [Uss_Sensor_Id_t tSensorMask]    - Sensors ID
;                                    [Uss_Calib_Data_t *tEepromData]    - EEPROM data and VPROG_STATUS
;       Return Values           :    0 = Success
;                                    1 = Failure
;        Description            :    Ex. read_eeprom(tSensorMask, &Buffer);
******************************************************************************/
int read_eeprom(Uss_Sensor_Id_t tSensorMask, Uss_Calib_Data_t *tEepromData)
{
    return (int)UssDrivers_EEPROM_Data_Read(tSensorMask, tEepromData);
}

/******************************************************************************
;       Function Name           :    int copy_eeprom(Uss_Sensor_Id_t tSensorMask)
;       Function Description    :    The EEPROM cells are programmed with the current calibration register contents.
;       Parameters              :    [Uss_Sensor_Id_t tSensorMask]    - Sensors ID
;       Return Values           :    0 = Success
;                                    1 = Failure
;       Description             :    Ex. copy_eeprom(USS_ID_IO2_TXRX_FLM)
******************************************************************************/
int copy_eeprom(Uss_Sensor_Id_t tSensorMask)
{
    return (int)UssDrivers_EEPROM_Copy(tSensorMask);
}

/******************************************************************************
;       Function Name           :    int get_temp(Uss_Sensor_Id_t tSensorMask)
;       Function Description    :    Read sensors temperature values
;       Parameters              :    [Uss_Sensor_Id_t tSensorMask] - Sensors ID
;       Return Values           :    0 = Success
;                                    1 = Failure
;       Description             :    Ex. get_temp(USS_ID_IO2_TXRX_FLM)
******************************************************************************/
int get_temp(Uss_Sensor_Id_t tSensorMask)
{
    return (int)UssDrivers_Sensors_Temp_Get(tSensorMask);
}

/******************************************************************************
;       Function Name           :    int read_temp(Uss_Sensor_Id_t tSensorMask, uint16 *u16Temp)
;       Function Description    :    Get sensors temperature values from the MCU memory
;       Parameters              :    [Uss_Sensor_Id_t tSensorMask]    - Sensors ID
;                                    [uint16 *u16Temp]                - Sensor temperature values
;       Return Values           :    0 = Success
;                                    1 = Failure
;       Description             :    Ex. read_temp(USS_ID_IO2_TXRX_FLM, &gu16Temperture)
******************************************************************************/
int read_temp(Uss_Sensor_Id_t tSensorMask, uint16 *u16Temp)
{
    return (int)UssDrivers_Temperature_Read(tSensorMask, u16Temp);
}

/******************************************************************************
;       Function Name           :    int get_status(Uss_Sensor_Id_t tSensorMask)
;       Function Description    :    Read sensors status
;       Parameters              :    [Uss_Sensor_Id_t tSensorMask]    - Sensors ID
;       Return Values           :    0 = Success
;                                    1 = Failure
;       Description             :    Ex. get_status(USS_ID_IO2_TXRX_FLM)
******************************************************************************/
int get_status(Uss_Sensor_Id_t tSensorMask)
{
    return (int)UssDrivers_Status_Get(tSensorMask);
}

/******************************************************************************
;       Function Name           :    int read_status(Uss_Sensor_Id_t tSensorMask, uint16 *u16StatusData)
;       Function Description    :    Get sensors status from the MCU memory.
;       Parameters              :    [Uss_Sensor_Id_t tSensorMask]    - Sensors ID
;                                    [uint16 *u16StatusData]            - USS status
;       Return Values           :    0 = Success
;                                    1 = Failure
;       Description             :    Ex. read_status(USS_ID_IO1_TXRX_FLC, &Buff)
******************************************************************************/
int read_status(Uss_Sensor_Id_t tSensorMask, uint16 *u16StatusData)
{
    return (int)UssDrivers_Status_Data_Read(tSensorMask, u16StatusData);
}

/******************************************************************************
;       Function Name           :   int get_cal_pulses(Uss_Sensor_Id_t tSensorMask)
;       Function Description    :    Read sensors OSC frequency for calibration.
;       Parameters              :   [Uss_Sensor_Id_t tSensorMask] - Sensors ID
;       Return Values           :   0 = Success
;                                   1 = Failure
;       Description             :   Ex. get_cal_pulses(USS_ID_IO2_TXRX_FLM)
******************************************************************************/
int get_cal_pulses(Uss_Sensor_Id_t tSensorMask)
{
    return (int)UssDrivers_Calibrate_OSC_Get(tSensorMask);
}

/******************************************************************************
;       Function Name           :   int read_cal_pulses(Uss_Sensor_Id_t tSensorMask, uint32 *u32PulseTimes)
;       Function Description    :    Get calibrate OSC frequency capture time from the MCU memory.
;       Parameters              :   [Uss_Sensor_Id_t tSensorMask]    - Sensors ID
;                                    [uint32 *u32PulseTimes]            - Capture time of OSC frequency
;       Return Values           :   0 = Success
;                                   1 = Failure
;       Description             :   Ex. read_cal_pulses(USS_ID_IO2_TXRX_FLM, &u32Buff[0])
******************************************************************************/ 
int read_cal_pulses(Uss_Sensor_Id_t tSensorMask, uint32 *u32PulseTimes)
{
    return (int)UssDrivers_Calibrate_Data_Read(tSensorMask, u32PulseTimes);
}

/******************************************************************************
;       Function Name           :   int get_id(Uss_Sensor_Id_t tSensorMask)
;       Function Description    :    Read sensors ID.
;       Parameters              :   [Uss_Sensor_Id_t tSensorMask] - Sensors ID
;       Return Values           :   0 = Success
;                                   1 = Failure
;       Description             :   Ex. get_id(USS_ID_IO2_TXRX_FLM)
******************************************************************************/
int get_id(Uss_Sensor_Id_t tSensorMask)
{
    return (int)UssDrivers_ID_Get(tSensorMask);
}
 
/******************************************************************************
;       Function Name           :   int read_id(Uss_Sensor_Id_t tSensorMask, uint32 *u32ChipId)
;       Function Description    :    Get ID data from the MCU memory.
;       Parameters              :   [Uss_Sensor_Id_t tSensorMask] - Sensors ID
;                                    [uint32 *u32ChipId]            - ID values
;       Return Values           :   0 = Success
;                                   1 = Failure
;       Description             :   Ex. read_id(USS_ID_IO2_TXRX_FLM, &u32Buff)
******************************************************************************/
int read_id(Uss_Sensor_Id_t tSensorMask, uint32 *u32ChipId)
{
    return (int)UssDrivers_ID_Data_Read(tSensorMask, u32ChipId);
}

/******************************************************************************
;       Function Name           :   int uss_standby(Uss_Sensor_Id_t tSensorMask)
;       Function Description    :    Sensor entry standby mode.
;       Parameters              :   [Uss_Sensor_Id_t tSensorMask] - Sensors ID
;       Return Values           :   0 = Success
;                                   1 = Failure
;       Description             :   Ex. uss_standby(USS_ID_IO2_TXRX_FLM)
******************************************************************************/
int uss_standby(Uss_Sensor_Id_t tSensorMask)
{
    return (int)UssDrivers_Standby(tSensorMask);
}

/******************************************************************************
;       Function Name           :   int uss_wakeup(Uss_Sensor_Id_t tSensorMask)
;       Function Description    :    Sensor entry wakeup mode.
;       Parameters              :   [Uss_Sensor_Id_t tSensorMask] - Sensors ID
;       Return Values           :   0 = Success
;                                   1 = Failure
;       Description             :   Ex. uss_wakeup(USS_ID_IO2_TXRX_FLM)
******************************************************************************/
int uss_wakeup(Uss_Sensor_Id_t tSensorMask)
{
    return (int)UssDrivers_Wakeup(tSensorMask);
}

/******************************************************************************
;       Function Name           :    int uss_detect(Uss_Detect_Mode_t tMode, uint16 u16SendMask, uint16 u16RecMask, uint16 u16DetTime_us)
;       Function Description    :    Range measurement
;       Parameters              :    [Uss_Detect_Mode_t tMode]    - Command mode selection
;                                    [uint16 u16SendMask]        - Choose send sensor
;                                    [uint16 u16RecMask]            - Choose receive sensor
;                                    [uint16 u16DetTime_us]        - Sensor ACK time length
;       Return Values           :    0 = Success
;                                    1 = Failure
;       Description             :    Ex. uss_detect(MODE_SEND_REC_C, 0x0002, 0x0000, 36000);
******************************************************************************/
int uss_detect(Uss_Detect_Mode_t tMode, uint16 u16SendMask, uint16 u16RecMask, uint16 u16DetTime_us)
{
    return (int)UssDrivers_SndRecEnv_Detect(tMode, u16SendMask, u16RecMask, u16DetTime_us);
}

/******************************************************************************
;       Function Name           :    int read_bilateral_time(Uss_Sensor_Id_t tSensorMask, Uss_Cmds_SendRecEnv tCmd, uint32 *u32BilateralT)
;       Function Description    :    Read sensors bilateral time
;       Parameters              :    [Uss_Sensor_Id_t tSensorMask]    - Sensors ID
;                                    [Uss_Cmds_SendRecEnv tCmd]        - Choose command
;                                    [uint32 *u32BilateralT]            - read and store bilateral time of command
;       Return Values           :    0 = Success
;                                    1 = Failure
;       Description             :    Ex. read_bilateral_time(USS_ID_IO2_TXRX_FLM, CMDS_SEND_C, &gu32Buffer[0])
******************************************************************************/
int read_bilateral_time(Uss_Sensor_Id_t tSensorMask, Uss_Cmds_SendRecEnv tCmd, uint32 *u32BilateralT)
{
    return    (int)UssDrivers_Bilat_Read(tSensorMask, tCmd, u32BilateralT);//u32BilateralT size need set SIZE_SND_REC=128
}

/******************************************************************************
;       Function Name           :   int get_diag(Uss_Sensor_Id_t tSensorMask)
;       Function Description    :    Read USS IO diagnostic status.
;       Parameters              :   [Uss_Sensor_Id_t tSensorMask] - Sensors ID
;       Return Values           :   0 = Success
;                                   1 = Failure
;       Description             :   
******************************************************************************/
int get_diag(Uss_Sensor_Id_t tSensorMask)
{
    return (int)UssDrivers_Diag_Status_Get(tSensorMask);
}

/******************************************************************************
;       Function Name           :   int read_diag(Uss_Sensor_Id_t tSensorMask, uint16 *u16Status)
;       Function Description    :    Get diagnostic status values.
;       Parameters              :   [Uss_Sensor_Id_t tSensorMask]    - Sensors ID
;                                    [uint16 *u16Status]                - Diagnostic status values
;       Return Values           :   0 = Success
;                                   1 = Failure
;       Description             :   
******************************************************************************/
int read_diag(Uss_Sensor_Id_t tSensorMask, uint16 *u16Status)
{
    return (int)UssDrivers_Diag_Status_Read(tSensorMask, u16Status);
}

/******************************************************************************
;       Function Name        : int read_uss_working_status(Uss_Sensor_Id_t tSensorMask)
;       Function Description : read USS work status.
;       Parameters           : [Uss_Sensor_Id_t tSensorMask]        - Sensors ID
;       Return Values        : 0 = Idle, last command run completed, can send new command.
;                              1 = Busy, It's writing/reading data with USS.
******************************************************************************/
int read_uss_working_status(Uss_Sensor_Id_t tSensorMask)
{
    return (int)UssDrivers_work_status_Read(tSensorMask);
}

//---------------------------------------------------------------------------//
