/******************************************************************************
;       Program     :    Common.c
;       Function    :    The Main Program
;       Chip        :    Infineon TC397
;       Clock       :    Internal Clock 300MHz
;       Date        :    2023 / 12 / 5
;       Author      :    Fenderson Lu
******************************************************************************/
//---------------------------- Include File ---------------------------------//
// #include "Cpu0_Main.h"
#include "Common.h"
//---------------------------- Declare Global Variable ----------------------//

//---------------------------- Define Constant ------------------------------//
enum CounterPara{
    CNT_DONE = 0U,
    CNT_REDUCE = 1U
};


//---------------------------- Start Program --------------------------------//
/******************************************************************************
;       Function Name         :    void Common_Delay(Ifx_STM *pDelayUnit, uint32 u32DelayTime)
;       Function Description  :    Tiem delay function.
;       Parameters            :    [u8DelayUnit] - Delay time unit selection
;                                                  (1) UNIT_MINISECOND : Time unit is millisecond
;                                                  (2) UNIT_MICROSEOND : Time unit is microsecond
;                                    [u32DelayTime] - Timer counter
;       Return Values         :    void
;        Source ID            :    
******************************************************************************/
void Common_Delay(uint8 u8DelayUnit, uint32 u32DelayTime)
{

    uint32 CurrSTMTick = Mcal_DelayGetTick();
    uint32 BaseSTMTick = CurrSTMTick;

    switch(u8DelayUnit)
    {
        case UNIT_MILLISECOND:
            while ((uint32)((CurrSTMTick - BaseSTMTick) & 0xffffffff)< u32DelayTime* 100000){
                CurrSTMTick = Mcal_DelayGetTick();
            }
        break;
        case UNIT_MICROSEOND:
            while ((uint32)((CurrSTMTick - BaseSTMTick) & 0xffffffff)< u32DelayTime* 100){
                CurrSTMTick = Mcal_DelayGetTick();
            }
        break;
    }    
}

//---------------------------------------------------------------------------//
boolean Common_Debounce_Counter(uint32 *u32CountValues)
{
    boolean bFlag;
    
    if(*u32CountValues == (uint32)(CNT_DONE))
    {
        bFlag = TRUE;
    }
    else
    {        
        bFlag = FALSE;
        *u32CountValues -= (uint32)(CNT_REDUCE);
    }            

    (void)(u32CountValues);
    return bFlag;
}
//---------------------------------------------------------------------------//


