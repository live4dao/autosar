#ifndef __USSAPP_H__
#define __USSAPP_H__

//---------------------------- Include File ---------------------------------//
#include "TtIoDrivers.h"

//---------------------------- Support Library ------------------------------//



//---------------------------- Define Constant ------------------------------//


//---------------------------- Declare Function -----------------------------//
extern void Uss_Init(void);

/*****************************************************
 * @name : Uss_MainFunction
 * @brief: This is Uss Driver run function
 * @todo : polling each 1ms.
 * ****************************************************/
extern void Uss_MainFunction(void);
extern void Uss_Power_Status_updata(void);
extern void Uss_Demo(void);
extern void Uss_API_Test(void);

#endif
