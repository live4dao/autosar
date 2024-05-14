/******************************************************************************
;       Program     : Timer_Gpt12.c
;       Function    : Use GPT12 timer to gerernal vistual timer
;       Chip        : Infineon TC397
;       Clock       : Internal SYSPLL 300MHz
;       Date        : 2023 / 12 / 26
;       Author      : Fenderson Lu
;       Describe    : 
******************************************************************************/
//---------------------------- Include File ---------------------------------//
#include "Timer.h"
#include "McalLib.h"


//---------------------------- Declare External Var -------------------------//


//---------------------------- Start Program --------------------------------//
void IoHwAb_GptNotification_1ms(void);



/**
 * @name :Timer_Gpt_Init()
 * @brief:It will open two GPT
 *        1.System tasks: 1ms
 *        2.USS Driver used: 50us
*/
void Timer_Gpt_Init(void)
{
    if(Mcal_GetCpuPhysicalId()==0){
        /* Initialiase interrupt request configurations */
        SRC_GTMTOM00.B.SRE = 1;
        // SRC_GTMTOM01.B.SRE = 1;
        Gpt_Init(&Gpt_Config);
    //}else if(Mcal_GetCpuPhysicalId()==3){
        /* Initialize GPT driver */
        Gpt_Init(&Gpt_Config);

        /** @brief: 1us Timer init **/
        /* Enable notification*/
        // Gpt_EnableNotification(GptConf_GptChannelConfiguration_GptChannelConfiguration_0);
        Gpt_EnableNotification(GptConf_GptChannelConfiguration_GptChannelConfiguration_1);
        /* 16 bit max value in GPT12 timer */
        //Gpt_StartTimer(GptConf_GptChannelConfiguration_GptChannelConfiguration_0,6250U);  //MCAL set GtmTOM0_0 Clock=100MHz/(2^4)=(100/16)MHz=0.16us
                                                                                        //0.16us*6250，interrup time= 1ms. The input MAX value=65535.

        Gpt_StartTimer(GptConf_GptChannelConfiguration_GptChannelConfiguration_1,5000U);  //MCAL set GtmTOM0_0 Clock=100MHz/(2^0)=(100/1)MHz=0.01us
                                                                                        //0.01us*5000，interrup time= 50us. The input MAX value=65535.
    }
}

//---------------------------------------------------------------------------//
uint32 newTimes=0;
uint32 Oldimes=0;
/** @brief: Trigger ever 1ms **/
void IoHwAb_GptNotification_1ms(void)
{
    __nop();
}

//---------------------------------------------------------------------------//
