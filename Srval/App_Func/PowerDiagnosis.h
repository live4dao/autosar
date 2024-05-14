#ifndef POWER_DIAGNOSIS_H
#define POWER_DIAGNOSIS_H

#include "Std_Types.h"
#include "Dem_Cfg.h"
#define CDD_DEM_ENABLED 1

boolean Fault_BattLow();
// boolean Fault_BattHigh();

boolean Fault_OutputVoltage_of_TLF35584();
boolean Fault_OutputVoltage_of_LM5141();
boolean Fault_Voltage_of_DP83TC812RRHARQ1();
boolean Fault_CAM_Voltage_Abnormal();

#endif
