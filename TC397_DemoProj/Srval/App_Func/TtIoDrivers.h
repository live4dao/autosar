/******************************************************************************
;       Program     : TtIoDrivers.h
;       Function    : Declare TT APIs Format Function & Variable
;       Chip        : Infineon TC397
;       Clock       : Internal SYSPLL 300MHz
;       Date        : 2023 / 1 / 2
;       Author      : Fenderson Lu
******************************************************************************/
#ifndef __TTIODRIVERS_H__
#define __TTIODRIVERS_H__
//---------------------------- Include Library ------------------------------//
#include "UssDrivers.h"
//---------------------------- Define Constant ------------------------------//
//---------------------------- Declare Function -----------------------------// 
extern int get_threshold(Uss_Sensor_Id_t tSensorMask);
extern int read_threshold(Uss_Sensor_Id_t tSensorMask, Uss_Thres_Data_t *tThresholdData);
extern int write_threshold(Uss_Sensor_Id_t tSensorMask, Uss_Thres_Data_t *tThresSetupPara);

extern int get_meas(Uss_Sensor_Id_t tSensorMask);
extern int read_meas(Uss_Sensor_Id_t tSensorMask, Uss_Meas_Data_t *tMeasSetupPara);
extern int write_meas(Uss_Sensor_Id_t sensor_mask, Uss_Meas_Data_t *tMeasSetupPara);

extern int get_calibration(Uss_Sensor_Id_t tSensorMask);
extern int read_calibration(Uss_Sensor_Id_t tSensorMask, Uss_Calib_Data_t *tCalibData);
extern int write_calibration(Uss_Sensor_Id_t tSensorMask, Uss_Calib_Data_t *tCalibWritePara);

extern int get_eeprom(Uss_Sensor_Id_t tSensorMask);
extern int read_eeprom(Uss_Sensor_Id_t tSensorMask, Uss_Calib_Data_t *tEepromData);
extern int copy_eeprom(Uss_Sensor_Id_t tSensorMask);

extern int get_temp(Uss_Sensor_Id_t tSensorMask);
extern int read_temp(Uss_Sensor_Id_t tSensorMask, uint16 *u16Temp);

extern int get_status(Uss_Sensor_Id_t tSensorMask);
extern int read_status(Uss_Sensor_Id_t tSensorMask, uint16 *u16StatusData);
extern int get_cal_pulses(Uss_Sensor_Id_t tSensorMask);
extern int read_cal_pulses(Uss_Sensor_Id_t tSensorMask, uint32 *u32PulseTimes);
extern int get_id(Uss_Sensor_Id_t tSensorMask);
extern int read_id(Uss_Sensor_Id_t tSensorMask, uint32 *u32ChipId);
extern int uss_standby(Uss_Sensor_Id_t tSensorMask);
extern int uss_wakeup(Uss_Sensor_Id_t tSensorMask);

extern int uss_detect(Uss_Detect_Mode_t tMode, uint16 u16SendMask, uint16 u16RecMask, uint16 u16DetTime_us);
extern int read_bilateral_time(Uss_Sensor_Id_t tSensorMask, Uss_Cmds_SendRecEnv tCmd, uint32 *u32BilateralT);

extern int get_diag(Uss_Sensor_Id_t tSensorMask);
extern int read_diag(Uss_Sensor_Id_t tSensorMask, uint16 *u16Status);

extern int read_uss_working_status(Uss_Sensor_Id_t tSensorMask);

#endif




