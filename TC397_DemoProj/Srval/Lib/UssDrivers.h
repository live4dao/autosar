/******************************************************************************
;       Program		: UssDrivers.h
;       Function	: Declare USS Drivers Function & Variable
;       Chip		: Infineon TC397
;       Clock		: Internal SYSPLL 300MHz
;       Date		: 2024 / 02 / 15
;       Author		: Fenderson Lu
******************************************************************************/
#ifndef __USSDRIVERS_H__
#define __USSDRIVERS_H__
//---------------------------- Include Library ------------------------------//
#include "Platform_Types.h"
#include "Dio.h"
#include "Port.h"
#include "Common.h"

#include "Icu_17_TimerIp_Cfg.h"
#include "Icu_17_TimerIp.h"
#include "IfxSrc_reg.h"
#include "string.h"

#include "Gpt_Cfg.h"
#include "Gpt.h"

//---------------------------- Declare Constant -----------------------------//

enum UssCmdsSize{
	SIZE_THRES_SETUP = 10,		// TS_BYTEx
	SIZE_USS_SENSOR = 12,		// USS_SENSOR_SIDE_MASK_x
	SIZE_THRES_THVAL = 12,
	SIZE_CALIB_WRITE = 5,		// CW_BYTEx
	SIZE_MEAS_WRITE = 5,
	SIZE_ISR_RX_RAW = 120,
	SIZE_TIME_TAG = 250,
	SIZE_USS_RX = 4,
	SIZE_SND_REC = 128,
	SIZE_SEND_REC_TAG = (SIZE_SND_REC+1),
	SIZE_CAL_PULSES = 4
};

enum UssSensorsMask{

	MASK_IO1_FLC = 0x0001,
	MASK_IO2_FLM = 0x0002,
	MASK_IO3_FRC = 0x0004,
	MASK_IO4_FRM = 0x0008,
	MASK_IO5_RLC = 0x0010,
	MASK_IO6_RLM = 0x0020,
	MASK_IO7_RRC = 0x0040,
	MASK_IO8_RRM = 0x0080,
	MASK_IO9_FLS = 0x0100,
	MASK_IO10_FRS = 0x0200,
	MASK_IO11_RLS = 0x0400,
	MASK_IO12_RRS = 0x0800
};

//---------------------------- Declare Typedef Data -------------------------//
typedef enum{
	USS_ID_IO1_TXRX_FLC = 0,
	USS_ID_IO2_TXRX_FLM = 1,
	USS_ID_IO3_TXRX_FRC = 2,
	USS_ID_IO4_TXRX_FRM = 3,
	USS_ID_IO5_TXRX_RLC = 4,
	USS_ID_IO6_TXRX_RLM = 5,
	USS_ID_IO7_TXRX_RRC = 6,
	USS_ID_IO8_TXRX_RRM = 7,
	USS_ID_IO9_TXRX_FLS = 8,
	USS_ID_IO10_TXRX_FRS = 9,
	USS_ID_IO11_TXRX_RLS = 10,
	USS_ID_IO12_TXRX_RRS = 11,
	USS_ID_TOTAL_ENUM_VALUES
} Uss_Sensor_Id_t;

typedef enum{
	MODE_SEND_REC_A = 0,
	MODE_SEND_REC_B = 1,
	MODE_SEND_REC_C = 2,
	MODE_ENVELOPE = 3
} Uss_Detect_Mode_t;

typedef struct
{
    uint8 sw_major_version;
    uint8 sw_minor_version;
    uint8 sw_patch_version;
}Uss_VerInfoType;

typedef struct
{
    uint8 u8Thval[SIZE_THRES_THVAL];
    uint8 u8Thsft_Cfg;
	uint8 u8Atg_Cfg;
	uint8 u8Atg_Tau;
	uint8 u8Atg_Alpha;
	uint8 u8Thresscale_Rec;
}Uss_Thres_Data_t;

typedef struct
{
	uint8 u8npulses_a;
	uint8 u8tmeas_a;
	uint8 u8thresscale_a;
	uint8 u8npulses_b;
	uint8 u8tmeas_b;
	uint8 u8thresscale_b;
	uint8 u8npulses_c;
	uint8 u8tmeas_c;
	uint8 u8thresscale_c;
	uint8 u8echo_deb;
	uint8 u8rt_cfg;
	uint8 u8nftg;
	uint8 u8ftc;
	uint8 u8epd;
	uint8 u8stc_cfg;
	uint8 u8stc_start;
	uint8 u8noise_cfg;
	uint8 u8filter_cfg;
}Uss_Meas_Data_t;

typedef struct
{
	uint8 u8Osc_Trim;
	uint8 u8Customer_Bits;
	uint8 u8G_Dig;
	uint8 u8G_Ana;
	uint8 u8I_Drv;
	uint8 u8F_Drv;
	uint8 u8Vprog_Status; //EE_Read can read out it, but Calib r/w no the data.
} Uss_Calib_Data_t;

typedef enum{
	CMDS_SEND_A=0,
	CMDS_SEND_B,
	CMDS_SEND_C,
	CMDS_REC_A,
	CMDS_REC_B,
	CMDS_REC_C,
	CMDS_ENVELOPE_SEND_A,
	CMDS_ENVELOPE_REC_A	
} Uss_Cmds_SendRecEnv;

typedef enum{
	FUNC_SUCCESS = 0,
	FUNC_FAIL	 = 1,
	FUNC_BUSY	 = 2,
	FUNC_TIMEOUT = 3,
	FUNC_CMDERROR = 4,
	FUNC_OFFLINE =5,
} Func_Status_t;


/***************************************************************************
 * Uss_Exchange_Cmds : That list all USS command.
 * @warning: If do any change, include sequence change.
 *           That need to modify "Uss_Cmds_step_table[]".
 * *************************************************************************/
typedef enum{
    EX_CMDS_SEND_A=0,
	EX_CMDS_RECEIVE_A,
	EX_CMDS_SEND_B,
	EX_CMDS_RECEIVE_B,
	EX_CMDS_SEND_C,
	EX_CMDS_RECEIVE_C,
	EX_CMDS_ENVELOPE_SEND_A, //It sens CMD only.
	EX_CMDS_ENVELOPE_REC_A,  //It sens CMD only.
	EX_CMDS_THRES_SETUP,
	EX_CMDS_READ_THRES_SETUP,
	EX_CMDS_MEAS_SETUP,
	EX_CMDS_READ_MEAS_SETUP,
	EX_CMDS_READ_STATUS,
	EX_CMDS_CAL_PULSES,
	EX_CMDS_READ_TEMP,
	EX_CMDS_CALIB_WRITE,
	EX_CMDS_CALIB_READ,
	EX_CMDS_EE_COPY,
	EX_CMDS_EE_READ,
	EX_CMDS_READ_ID,
	EX_CMDS_STANDBY,
	EX_CMDS_WAKE_UP,
	EX_CMDS_TOTAL_ENUM_VALUES //This for check cmd is correct use.
} Uss_Exchange_Cmds;




//--------------------------- Extern Support --------------------------------//
extern void UssDrivers_GetVersionInfo(Uss_VerInfoType* const VersionInfoPtr);

/*************************************************
 * @brief: The USS default configuration setting.
*************************************************/
//The Thres default was refer Spec.
extern void UssDrivers_Thres_Default(Uss_Thres_Data_t *Thres_Data);

//The Meas default was refer Spec.
extern void UssDrivers_Meas_Default(Uss_Meas_Data_t *Meas_Data);

//The Calib default was from USS read out.
extern void UssDrivers_Calib_Default(Uss_Calib_Data_t *Calib_Data);

//---------------------------- Declare Function -----------------------------// 

/************************************************************************************************
 * UssDrivers_Cmds_Transmit()
 * @brief: Thisis USS command transmit function.
 * @return: 0:Command push out.
 *          1:The USS is busy.
 *          2:The Cmd not correct.
 * @warning: Need to fix DetectTime_ms value
*************************************************************************************************/
extern uint8 UssDrivers_Cmds_Transmit(Uss_Sensor_Id_t tSensorMask, Uss_Exchange_Cmds u8Cmd);

/*************************************************************************************
 ** @name:UssDrivers_DetectTime_Hander()                                           **
 ** @brief:need to pollling each 1ms.                                              **
 *************************************************************************************/
extern void UssDrivers_DetectTime_Hander(void);

/*************************************************************************************
 ** @name:UssDriver_Diagnostic_Hander()                                           **
 ** @brief:need to pollling each 1ms.                                              **
 *************************************************************************************/
extern void UssDriver_Diagnostic_Hander(void);

extern void USS_Rx_Init(void);
extern void USS_Rx_Init_Muilt_core(void);

extern void USS_Rx_Handler(void);


extern Func_Status_t UssDrivers_Sensors_Thres_Get(Uss_Sensor_Id_t tSensorMask);
extern Func_Status_t UssDrivers_Thres_Para_Read(Uss_Sensor_Id_t tSensorMask, Uss_Thres_Data_t *tThresholdData);
extern Func_Status_t UssDrivers_ThresSetup_Para_Write(Uss_Sensor_Id_t tSensorMask, Uss_Thres_Data_t *tThresSetupPara);
extern Func_Status_t UssDrivers_Meas_Setup_Get(Uss_Sensor_Id_t tSensorMask);
extern Func_Status_t UssDrivers_Meas_Setup_Read(Uss_Sensor_Id_t tSensorMask, Uss_Meas_Data_t *tMeasPara) ;
extern Func_Status_t UssDrivers_Meas_Para_Write(Uss_Sensor_Id_t tSensorMask, Uss_Meas_Data_t *tMeasPara);
extern Func_Status_t UssDrivers_Sensors_Calib_Get(Uss_Sensor_Id_t tSensorMask);
extern Func_Status_t UssDrivers_Calib_Read(Uss_Sensor_Id_t tSensorMask, Uss_Calib_Data_t *tCalibData);
extern Func_Status_t UssDrivers_Calib_Write(Uss_Sensor_Id_t tSensorMask, Uss_Calib_Data_t *tCalibWritePara);
extern Func_Status_t UssDrivers_Sensors_EEPROM_Get(Uss_Sensor_Id_t tSensorMask);
extern Func_Status_t UssDrivers_EEPROM_Data_Read(Uss_Sensor_Id_t tSensorMask, Uss_Calib_Data_t *tEepromData);
extern Func_Status_t UssDrivers_EEPROM_Copy(Uss_Sensor_Id_t tSensorMask);
extern Func_Status_t UssDrivers_Sensors_Temp_Get(Uss_Sensor_Id_t tSensorMask);
extern Func_Status_t UssDrivers_Temperature_Read(Uss_Sensor_Id_t tSensorMask, uint16 *u16Temp);

extern Func_Status_t UssDrivers_Status_Get(Uss_Sensor_Id_t tSensorMask);
extern Func_Status_t UssDrivers_Status_Data_Read(Uss_Sensor_Id_t tSensorMask, uint16 *u16StatusData);
extern Func_Status_t UssDrivers_Calibrate_OSC_Get(Uss_Sensor_Id_t tSensorMask);
extern Func_Status_t UssDrivers_Calibrate_Data_Read(Uss_Sensor_Id_t tSensorMask, uint32 *u32PulseTimes);
extern Func_Status_t UssDrivers_ID_Get(Uss_Sensor_Id_t tSensorMask);
extern Func_Status_t UssDrivers_ID_Data_Read(Uss_Sensor_Id_t tSensorMask, uint32 *u32ChipId);
extern Func_Status_t UssDrivers_Standby(Uss_Sensor_Id_t tSensorMask);
extern Func_Status_t UssDrivers_Wakeup(Uss_Sensor_Id_t tSensorMask);
extern Func_Status_t UssDrivers_SndRecEnv_Detect(Uss_Detect_Mode_t tMode, uint16 u16SendMask, uint16 u16RecMask, uint16 u16DetTime_us);
extern Func_Status_t UssDrivers_Bilat_Read(Uss_Sensor_Id_t tSensorMask, Uss_Cmds_SendRecEnv tCmd, uint32 *u32BilateralT);

extern Func_Status_t UssDrivers_Diag_Status_Get(Uss_Sensor_Id_t tSensorMask);
extern Func_Status_t UssDrivers_Diag_Status_Read(Uss_Sensor_Id_t tSensorMask, uint16 *u16Status);

extern Func_Status_t UssDrivers_work_status_Read(Uss_Sensor_Id_t tSensorMask);

/***********************************************************************************************
 * @class: Interrup Hander Function
 * @brief: ICU interrup for USS TX RX Pin
 * **********************************************************************************************/
extern inline void USS_TX_IQR_50us(void);
extern inline void USS_RX1_IQR(void);
extern inline void USS_RX2_IQR(void);
extern inline void USS_RX3_IQR(void);
extern inline void USS_RX4_IQR(void);
extern inline void USS_RX5_IQR(void);
extern inline void USS_RX6_IQR(void);
extern inline void USS_RX7_IQR(void);
extern inline void USS_RX8_IQR(void);
extern inline void USS_RX9_IQR(void);
extern inline void USS_RX10_IQR(void);
extern inline void USS_RX11_IQR(void);
extern inline void USS_RX12_IQR(void);

#endif




