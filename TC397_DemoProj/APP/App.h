/*
 * App.h
 *
 *  Created on: 2024.01.30
 *      Author: zhenxing.wu
 */

#ifndef APP_APP_H_
#define APP_APP_H_

/**********************************   Includes   *********************************/
#include "Platform_Types.h"

/*************************   Global Variable Definitions   ***********************/
extern uint8 Dcm_L2_AttemptCounter;

extern uint8 com_T_APA_slot_1;
extern uint8 com_R_MHU_DM_SwitchModeSts;

extern uint8 NvM_Block27[1];
extern uint8 Get_NvM_Block27[1];
extern uint8 StaticCalibrationInfo_0x4F4A_Array[16];
extern uint8 Get_StaticCalibrationInfo_0x4F4A_Array[16];

#endif /* APP_APP_H_ */
