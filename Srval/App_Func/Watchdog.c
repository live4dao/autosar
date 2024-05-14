//---------------------------- Include File ---------------------------------//
#include "Watchdog.h"

//---------------------------- Start Program --------------------------------//
void WDG_Init(void){
#ifdef WDG_ENABLE
    //    WDG test code
    Smu_Init(&Smu_Config);
    Wdg_17_Scu_Init(&Wdg_17_Scu_Config_0);
    SRC_STM0SR0.B.IOVCLR = 1U;
    SRC_STM0SR0.B.CLRR = 1U;
    SRC_STM0SR0.B.SWSCLR = 1U;
    /* Enable the interrupt */
    SRC_STM0SR0.B.SRE = 1;

    *(volatile uint32 *)0xF000047C = 0x00003000;
    Wdg_17_Scu_SetTriggerCondition(3000);
#endif

}

void feed_dog(void){
#ifdef WDG_ENABLE
    Wdg_17_Scu_SetTriggerCondition(3000);
#endif
}