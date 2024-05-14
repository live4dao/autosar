/*
 * App.c
 *
 *  Created on: 2024.01.30
 *      Author: zhenxing.wu
 */

/**********************************   Includes   *********************************/
#include "App.h"

/*************************   Global Variable Definitions   ***********************/
uint8 Dcm_L2_AttemptCounter;

uint8 com_T_APA_slot_1 = 0x55;
uint8 com_R_MHU_DM_SwitchModeSts = 0x0;

uint8 NvM_Block27[1] = {0x55};
uint8 Get_NvM_Block27[1] = {0xAA};
uint8 StaticCalibrationInfo_0x4F4A_Array[16] = {0};
uint8 Get_StaticCalibrationInfo_0x4F4A_Array[16] = {0};


