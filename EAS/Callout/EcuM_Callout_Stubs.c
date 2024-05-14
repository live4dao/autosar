/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : EcuM_Callout_Stubs.c
********************************************************************************
*   Project/Product : AUTOSAR BSW PROJECT
*   Title           : EcuM module configuration File
*   Author          : Hirain
********************************************************************************
*   Description     : EcuM module configuration File
*
********************************************************************************
*   Limitations     : None
*
********************************************************************************
*
********************************************************************************
*   Revision History:
*
*   Version     Date          Initials      CR#          Descriptions
*   ---------   ----------    ------------  ----------   ---------------
*   V1.0.0_3.5.5_AZ240046       27/03/2024    Eas           N/A          N/A
*
********************************************************************************
* END_FILE_HDR*/


/*******************************************************************************
*   Includes
*******************************************************************************/
#include "EcuM.h"
#include "Det.h"
/* Input File User Code start*/
#include "BswM.h"

#include "IfxSrc_reg.h"
#include "Stm.h"
#include "Mcu.h"
#include "Port.h"
#include "Dio.h"
#include "I2c.h"
#include "I2c_Demo.h"
#include "Can_17_McmCan.h"
#include "Irq.h"
#include "Fee.h"
#include "SchM_Fee.h"
#include "Fls_17_Dmu.h"
#include "SchM_Fls_17_Dmu.h"

#include "Eth_17_GEthMacV2.h"
#include "Eth_17_GEthMacV2_Cfg.h"
/* Input File User Code end*/
#define ECUM_START_SEC_CONFIG_CODE
#include "MemMap.h"
#include "Ethernet.h"

/*******************************************************************************
*  PUBLIC Functions define
*******************************************************************************/
#define STM_Timer0      (0U)
#define STM_0_Cmp1      (1U)
#define STM_Cont_Mode   (1U)

#define CAN_SC_SET_SRE  0x00000400

extern void Stm_Cycle_1ms_Cbk(void);
extern void delay_ms(uint32 ms);

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: EcuM_ErrorHook
*
* Description:
*
* Inputs:        reason - error value
*
* Outputs:       None
*
* Limitations:   SWS_EcuM_02904
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, ECUM_CALLOUT_CODE) EcuM_ErrorHook
(
    VAR(Std_ReturnType, AUTOMATIC) reason
)
{
    (void)reason;
    while (1)   /*SWS_EcuM_02758*/
    {

    /* EcuM_ErrorHook User Code start*/

    /* EcuM_ErrorHook User Code end*/
    }
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: EcuM_AL_SetProgrammableInterrupts
*
* Description:
*
* Inputs:        None
*
* Outputs:       None
*
* Limitations:   SWS_EcuM_04085
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, ECUM_CALLOUT_CODE) EcuM_AL_SetProgrammableInterrupts
(
    void
)
{

    /* EcuM_AL_SetProgrammableInterrupts User Code start*/

    /* EcuM_AL_SetProgrammableInterrupts User Code end*/
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: EcuM_AL_DriverInitZero
*
* Description:
*
* Inputs:        None
*
* Outputs:       None
*
* Limitations:   SWS_EcuM_02095
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, ECUM_CALLOUT_CODE) EcuM_AL_DriverInitZero
(
    void
)
{
    /* EcuM_AL_DriverInitZero User Code start*/
	Dem_PreInit();
    /* EcuM_AL_DriverInitZero User Code end*/
    Det_Init(NULL_PTR);
    /* EcuM_AL_DriverInitZero Det_Init User Code start*/
	/* MCU and GTM Initialization */
	Mcu_Init(&Mcu_Config);
	Mcu_InitClock(0U);
	while(Mcu_GetPllStatus() != MCU_PLL_LOCKED);
	Mcu_DistributePllClock();

    Port_Init(&Port_Config);

    // Stm_EnableModule(STM_Timer0);
    /*Initialization of STM IRQ service*/
    // IrqStm_Init();

    //X03 tda4 PWR dwon
    Dio_WriteChannel(DioConf_DioChannel_portPOWER_EN_5141, 0x00);
    Spi_PortPin_tdcu_boot();
    Eth_PortPin_tdcu_Boot();
    delay_ms(1000);
    //for TDA4 booting
    //Port_SetPinMode(PortConf_PortContainer_4_PORT_11_PIN_4, PORT_INPUT_PULL_UP);
    //Init TDA4 state
    /*
      Port_SetPinMode(PortConf_PortContainer_13_PORT_32_PIN_6, PORT_INPUT_PULL_UP);

      Port_SetPinMode(PortConf_PortContainer_7_PORT_14_PIN_6, PORT_INPUT_PULL_UP);
      Port_SetPinMode(PortConf_PortContainer_7_PORT_14_PIN_5, PORT_INPUT_PULL_UP);
      Port_SetPinMode(PortConf_PortContainer_7_PORT_14_PIN_10, PORT_INPUT_PULL_UP);
    */
    //X03 tda4 PWR up
    Dio_WriteChannel(DioConf_DioChannel_portPOWER_EN_5141, 0x01);
    delay_ms(1000);

    Uart_Demo();

    //TODO: Didn't set SPI in mcal configuration but set here
#if 0//For tda4 booting
    Port_SetPinDirection(PortConf_PortContainer_7_PORT_14_PIN_6, PORT_PIN_OUT);
    Port_SetPinMode(PortConf_PortContainer_7_PORT_14_PIN_6, PORT_PIN_MODE_ALT2);

    Port_SetPinDirection(PortConf_PortContainer_7_PORT_14_PIN_10, PORT_PIN_OUT);
    Port_SetPinMode(PortConf_PortContainer_7_PORT_14_PIN_10, PORT_PIN_MODE_ALT2);
#endif
    //Recover eth tx clk setting
    //Port_SetPinDirection(PortConf_PortContainer_4_PORT_11_PIN_4, PORT_PIN_OUT);
    //Port_SetPinMode(PortConf_PortContainer_4_PORT_11_PIN_4, PORT_PIN_MODE_ALT7);
    /////////////////////////////


    Can_17_McmCan_Init(&Can_17_McmCan_Config);

    IrqCan_Init();
    //controller_0 enable ISR
    SRC_CAN2INT0.U |= CAN_SC_SET_SRE;
    SRC_CAN2INT1.U |= CAN_SC_SET_SRE;
    SRC_CAN2INT2.U |= CAN_SC_SET_SRE;//BUSOFF not crash program in can controller_0
    SRC_CAN2INT3.U |= CAN_SC_SET_SRE;
    /* Exit Critical Section */

    delay_ms(500);
    //controller_1 enable ISR
    SRC_CAN2INT4.U |= CAN_SC_SET_SRE;
    SRC_CAN2INT5.U |= CAN_SC_SET_SRE;
    SRC_CAN2INT6.U |= CAN_SC_SET_SRE;//BUSOFF not crash program in can controller_1
    SRC_CAN2INT7.U |= CAN_SC_SET_SRE;
    /* Exit Critical Section */

    Can_17_McmCan_SetControllerMode(Can_17_McmCanConf_CanController_CAN0, CAN_CS_STARTED); //mcal 440 not 422
    Can_17_McmCan_EnableControllerInterrupts(Can_17_McmCanConf_CanController_CAN0);

    Can_17_McmCan_SetControllerMode(Can_17_McmCanConf_CanController_CAN1, CAN_CS_STARTED); //mcal 440 not 422
    Can_17_McmCan_EnableControllerInterrupts(Can_17_McmCanConf_CanController_CAN1);

    /* Memory Init */
    Fls_17_Dmu_Init(&Fls_17_Dmu_Config);
    Fee_Init(&Fee_Config);
    while(MEMIF_IDLE != Fee_GetStatus())
    {
    	Fee_MainFunction();
    	Fls_17_Dmu_MainFunction();
    }

    /*SRE bit needs to be set to enable interrupts*/
//    SRC_STM0SR1.B.SRE = 1U;
//    Stm_EnableAlarm(STM_Timer0, STM_0_Cmp1, STM_Cont_Mode, 1 * 100000, Stm_Cycle_1ms_Cbk);

    I2c_Init(&I2c_Config);
    CAN_Normal_Mode();
    Spi_PortPin_alt();
    Eth_PortPin_alt();
    uint8 cnt=0;
    for(cnt=0;cnt<6;cnt++)
    	delay_ms(1000);
    Eth_Swt_Enable();
#if 0    
    /*Eth Init*/
    delay_ms(1000);
    Dio_WriteChannel(DioConf_DioChannel_ETHSW_RSTN, STD_HIGH);
    delay_ms(1000);
    //GEthV2PhyInit();
    Eth_17_GEthMacV2_Init(&Eth_17_GEthMacV2_Config);
    Eth_17_GEthMacV2_SetControllerMode(0, ETH_MODE_DOWN);

    //GEthV2ControllerInit();
    /*Enable ETH TX and RX Interrupt*/
    IrqEthernet_Init();
    SRC_GETH_GETH0_SR2.B.SRE = 1;
    SRC_GETH_GETH0_SR6.B.SRE = 1;
#endif
    /* EcuM_AL_DriverInitZero Det_Init User Code end*/
    /*Initialiaze drivers that not depend on the Post-Build configurations*/
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: EcuM_DeterminePbConfiguration
*
* Description:
*
* Inputs:        None
*
* Outputs:       The Post-Build Configurations of the EcuM module.
*
* Limitations:   SWS_EcuM_02096
********************************************************************************
END_FUNCTION_HDR*/
FUNC(const EcuM_ConfigType *, ECUM_CALLOUT_CODE) EcuM_DeterminePbConfiguration
(
    void
)
{
    /* EcuM_DeterminePbConfiguration User Code start*/

    /* EcuM_DeterminePbConfiguration User Code end*/
    return &EcuM_PostBuildConfig;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: EcuM_AL_DriverInitOne
*
* Description:
*
* Inputs:        ConfigPtr - The Post-Build Configurations of the EcuM module.
*
* Outputs:       None
*
* Limitations:   SWS_EcuM_02097
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, ECUM_CALLOUT_CODE) EcuM_AL_DriverInitOne
(
    P2CONST(EcuM_ConfigType, AUTOMATIC, ECUM_VAR) ConfigPtr
)
{
    /* EcuM_AL_DriverInitOne User Code start*/

    /* EcuM_AL_DriverInitOne User Code end*/
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: EcuM_OnGoOffOne
*
* Description:
*
* Inputs:        None
*
* Outputs:       None
*
* Limitations:   SWS_EcuM_02916
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, ECUM_CALLOUT_CODE) EcuM_OnGoOffOne
(
    void
)
{

    /* EcuM_OnGoOffOne User Code start*/

    /* EcuM_OnGoOffOne User Code end*/
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: EcuM_OnGoOffTwo
*
* Description:
*
* Inputs:        None
*
* Outputs:       None
*
* Limitations:   SWS_EcuM_02917
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, ECUM_CALLOUT_CODE) EcuM_OnGoOffTwo
(
    void
)
{

    /* EcuM_OnGoOffTwo User Code start*/

    /* EcuM_OnGoOffTwo User Code end*/
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: EcuM_AL_SwitchOff
*
* Description:
*
* Inputs:        None
*
* Outputs:       None
*
* Limitations:   SWS_EcuM_02920
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, ECUM_CALLOUT_CODE) EcuM_AL_SwitchOff
(
    void
)
{
    /*If the ECU does NOT support OFF, issue a reset instead.*/
    /* EcuM_AL_SwitchOff User Code start*/

    /* EcuM_AL_SwitchOff User Code end*/
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: EcuM_AL_Reset
*
* Description:
*
* Inputs:        None
*
* Outputs:       None
*
* Limitations:   SWS_EcuM_04065
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, ECUM_CALLOUT_CODE) EcuM_AL_Reset
(
    VAR(EcuM_ResetType, AUTOMATIC) reset
)
{
    EcuM_BootTargetType target;

    (void)EcuM_GetBootTarget(&target);

    switch (target)
    {
    case ECUM_BOOT_TARGET_APP :
    /* EcuM_AL_Reset User Code start*/

    /* EcuM_AL_Reset User Code end*/
        break;
    case ECUM_BOOT_TARGET_OEM_BOOTLOADER :
        /*SWS_EcuM_02247*/
    /* EcuM_AL_Reset User Code start*/

    /* EcuM_AL_Reset User Code end*/
        break;
    case ECUM_BOOT_TARGET_SYS_BOOTLOADER :
    /* EcuM_AL_Reset User Code start*/

    /* EcuM_AL_Reset User Code end*/
        break;
    default:
    /* EcuM_AL_Reset User Code start*/

    /* EcuM_AL_Reset User Code end*/
        break;
    }

    /*Reset now*/
}
#define ECUM_STOP_SEC_CONFIG_CODE
#include "MemMap.h"



