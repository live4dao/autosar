################################################################################
# Automatically-generated file. Do not edit!
################################################################################

C_FILES += "..\Mcal\Tricore\Can_17_McmCan\ssc\src\Can_17_McmCan.c"
OBJ_FILES += "Mcal\Tricore\Can_17_McmCan\ssc\src\Can_17_McmCan.o"
"Mcal\Tricore\Can_17_McmCan\ssc\src\Can_17_McmCan.o" : "..\Mcal\Tricore\Can_17_McmCan\ssc\src\Can_17_McmCan.c" "Mcal\Tricore\Can_17_McmCan\ssc\src\.Can_17_McmCan.o.opt"
	@echo Compiling ${<F}
	@"${PRODDIR}\bin\cctc" -f "Mcal\Tricore\Can_17_McmCan\ssc\src\.Can_17_McmCan.o.opt"

"Mcal\Tricore\Can_17_McmCan\ssc\src\.Can_17_McmCan.o.opt" : .refresh
	@argfile "Mcal\Tricore\Can_17_McmCan\ssc\src\.Can_17_McmCan.o.opt" -o "Mcal\Tricore\Can_17_McmCan\ssc\src\Can_17_McmCan.o" "..\Mcal\Tricore\Can_17_McmCan\ssc\src\Can_17_McmCan.c" -Ctc39x --lsl-core=vtc -t -I"F:\LC_SWC_Projiectend\TC397_PROJECT_NEW\TC397_DemoProj" -Wa-H"sfr/regtc39x.def" -Wa-gAHLs --emit-locals=-equs,-symbols -Wa-Ogs -Wa--error-limit=42 -I"F:\LC_SWC_Projiectend\TC397_PROJECT_NEW\TC397_DemoProj\Mcal\EB_Cfg" -I"F:\LC_SWC_Projiectend\TC397_PROJECT_NEW\TC397_DemoProj\Mcal\EB_Cfg\inc" -I"F:\LC_SWC_Projiectend\TC397_PROJECT_NEW\TC397_DemoProj\Mcal\EB_Cfg\src" -I"F:\LC_SWC_Projiectend\TC397_PROJECT_NEW\TC397_DemoProj\Mcal\Infra_Prod" -I"F:\LC_SWC_Projiectend\TC397_PROJECT_NEW\TC397_DemoProj\Mcal\Infra_Prod\Autosar_Srv" -I"F:\LC_SWC_Projiectend\TC397_PROJECT_NEW\TC397_DemoProj\Mcal\Infra_Prod\Autosar_Srv\AS440" -I"F:\LC_SWC_Projiectend\TC397_PROJECT_NEW\TC397_DemoProj\Mcal\Infra_Prod\Cfg_Ssw" -I"F:\LC_SWC_Projiectend\TC397_PROJECT_NEW\TC397_DemoProj\Mcal\Infra_Prod\Cfg_Ssw\TC39B" -I"F:\LC_SWC_Projiectend\TC397_PROJECT_NEW\TC397_DemoProj\Mcal\Infra_Prod\Integration" -I"F:\LC_SWC_Projiectend\TC397_PROJECT_NEW\TC397_DemoProj\Mcal\Infra_Prod\Irq" -I"F:\LC_SWC_Projiectend\TC397_PROJECT_NEW\TC397_DemoProj\Mcal\Infra_Prod\Irq\ssc" -I"F:\LC_SWC_Projiectend\TC397_PROJECT_NEW\TC397_DemoProj\Mcal\Infra_Prod\Irq\ssc\inc" -I"F:\LC_SWC_Projiectend\TC397_PROJECT_NEW\TC397_DemoProj\Mcal\Infra_Prod\Irq\ssc\src" -I"F:\LC_SWC_Projiectend\TC397_PROJECT_NEW\TC397_DemoProj\Mcal\Infra_Prod\Platform" -I"F:\LC_SWC_Projiectend\TC397_PROJECT_NEW\TC397_DemoProj\Mcal\Infra_Prod\Platform\AS440" -I"F:\LC_SWC_Projiectend\TC397_PROJECT_NEW\TC397_DemoProj\Mcal\Infra_Prod\Sfr" -I"F:\LC_SWC_Projiectend\TC397_PROJECT_NEW\TC397_DemoProj\Mcal\Infra_Prod\Sfr\TC39xB" -I"F:\LC_SWC_Projiectend\TC397_PROJECT_NEW\TC397_DemoProj\Mcal\Infra_Prod\Sfr\TC39xB\_Reg" -I"F:\LC_SWC_Projiectend\TC397_PROJECT_NEW\TC397_DemoProj\Mcal\Infra_Prod\Ssw" -I"F:\LC_SWC_Projiectend\TC397_PROJECT_NEW\TC397_DemoProj\Mcal\Infra_Prod\Ssw\TC39B" -I"F:\LC_SWC_Projiectend\TC397_PROJECT_NEW\TC397_DemoProj\Mcal\Infra_Prod\Ssw\TC39B\Tricore" -I"F:\LC_SWC_Projiectend\TC397_PROJECT_NEW\TC397_DemoProj\Mcal\Tricore" -I"F:\LC_SWC_Projiectend\TC397_PROJECT_NEW\TC397_DemoProj\Mcal\Tricore\Adc" -I"F:\LC_SWC_Projiectend\TC397_PROJECT_NEW\TC397_DemoProj\Mcal\Tricore\Adc\ssc" -I"F:\LC_SWC_Projiectend\TC397_PROJECT_NEW\TC397_DemoProj\Mcal\Tricore\Adc\ssc\inc" -I"F:\LC_SWC_Projiectend\TC397_PROJECT_NEW\TC397_DemoProj\Mcal\Tricore\Adc\ssc\src" -I"F:\LC_SWC_Projiectend\TC397_PROJECT_NEW\TC397_DemoProj\Mcal\Tricore\Can_17_McmCan" -I"F:\LC_SWC_Projiectend\TC397_PROJECT_NEW\TC397_DemoProj\Mcal\Tricore\Can_17_McmCan\ssc" -I"F:\LC_SWC_Projiectend\TC397_PROJECT_NEW\TC397_DemoProj\Mcal\Tricore\Can_17_McmCan\ssc\inc" -I"F:\LC_SWC_Projiectend\TC397_PROJECT_NEW\TC397_DemoProj\Mcal\Tricore\Can_17_McmCan\ssc\src" -I"F:\LC_SWC_Projiectend\TC397_PROJECT_NEW\TC397_DemoProj\Mcal\Tricore\Dio" -I"F:\LC_SWC_Projiectend\TC397_PROJECT_NEW\TC397_DemoProj\Mcal\Tricore\Dio\ssc" -I"F:\LC_SWC_Projiectend\TC397_PROJECT_NEW\TC397_DemoProj\Mcal\Tricore\Dio\ssc\inc" -I"F:\LC_SWC_Projiectend\TC397_PROJECT_NEW\TC397_DemoProj\Mcal\Tricore\Dio\ssc\src" -I"F:\LC_SWC_Projiectend\TC397_PROJECT_NEW\TC397_DemoProj\Mcal\Tricore\Eth_17_GEthMacV2" -I"F:\LC_SWC_Projiectend\TC397_PROJECT_NEW\TC397_DemoProj\Mcal\Tricore\Eth_17_GEthMacV2\ssc" -I"F:\LC_SWC_Projiectend\TC397_PROJECT_NEW\TC397_DemoProj\Mcal\Tricore\Eth_17_GEthMacV2\ssc\inc" -I"F:\LC_SWC_Projiectend\TC397_PROJECT_NEW\TC397_DemoProj\Mcal\Tricore\Eth_17_GEthMacV2\ssc\src" -I"F:\LC_SWC_Projiectend\TC397_PROJECT_NEW\TC397_DemoProj\Mcal\Tricore\Fee" -I"F:\LC_SWC_Projiectend\TC397_PROJECT_NEW\TC397_DemoProj\Mcal\Tricore\Fee\ssc" -I"F:\LC_SWC_Projiectend\TC397_PROJECT_NEW\TC397_DemoProj\Mcal\Tricore\Fee\ssc\inc" -I"F:\LC_SWC_Projiectend\TC397_PROJECT_NEW\TC397_DemoProj\Mcal\Tricore\Fee\ssc\src" -I"F:\LC_SWC_Projiectend\TC397_PROJECT_NEW\TC397_DemoProj\Mcal\Tricore\Fls_17_Dmu" -I"F:\LC_SWC_Projiectend\TC397_PROJECT_NEW\TC397_DemoProj\Mcal\Tricore\Fls_17_Dmu\ssc" -I"F:\LC_SWC_Projiectend\TC397_PROJECT_NEW\TC397_DemoProj\Mcal\Tricore\Fls_17_Dmu\ssc\inc" -I"F:\LC_SWC_Projiectend\TC397_PROJECT_NEW\TC397_DemoProj\Mcal\Tricore\Fls_17_Dmu\ssc\src" -I"F:\LC_SWC_Projiectend\TC397_PROJECT_NEW\TC397_DemoProj\Mcal\Tricore\Gpt" -I"F:\LC_SWC_Projiectend\TC397_PROJECT_NEW\TC397_DemoProj\Mcal\Tricore\Gpt\ssc" -I"F:\LC_SWC_Projiectend\TC397_PROJECT_NEW\TC397_DemoProj\Mcal\Tricore\Gpt\ssc\inc" -I"F:\LC_SWC_Projiectend\TC397_PROJECT_NEW\TC397_DemoProj\Mcal\Tricore\Gpt\ssc\src" -I"F:\LC_SWC_Projiectend\TC397_PROJECT_NEW\TC397_DemoProj\Mcal\Tricore\I2c" -I"F:\LC_SWC_Projiectend\TC397_PROJECT_NEW\TC397_DemoProj\Mcal\Tricore\I2c\ssc" -I"F:\LC_SWC_Projiectend\TC397_PROJECT_NEW\TC397_DemoProj\Mcal\Tricore\I2c\ssc\inc" -I"F:\LC_SWC_Projiectend\TC397_PROJECT_NEW\TC397_DemoProj\Mcal\Tricore\I2c\ssc\src" -I"F:\LC_SWC_Projiectend\TC397_PROJECT_NEW\TC397_DemoProj\Mcal\Tricore\Icu_17_TimerIp" -I"F:\LC_SWC_Projiectend\TC397_PROJECT_NEW\TC397_DemoProj\Mcal\Tricore\Icu_17_TimerIp\ssc" -I"F:\LC_SWC_Projiectend\TC397_PROJECT_NEW\TC397_DemoProj\Mcal\Tricore\Icu_17_TimerIp\ssc\inc" -I"F:\LC_SWC_Projiectend\TC397_PROJECT_NEW\TC397_DemoProj\Mcal\Tricore\Icu_17_TimerIp\ssc\src" -I"F:\LC_SWC_Projiectend\TC397_PROJECT_NEW\TC397_DemoProj\Mcal\Tricore\McalLib" -I"F:\LC_SWC_Projiectend\TC397_PROJECT_NEW\TC397_DemoProj\Mcal\Tricore\McalLib\ssc" -I"F:\LC_SWC_Projiectend\TC397_PROJECT_NEW\TC397_DemoProj\Mcal\Tricore\McalLib\ssc\inc" -I"F:\LC_SWC_Projiectend\TC397_PROJECT_NEW\TC397_DemoProj\Mcal\Tricore\McalLib\ssc\inc\AS440" -I"F:\LC_SWC_Projiectend\TC397_PROJECT_NEW\TC397_DemoProj\Mcal\Tricore\McalLib\ssc\src" -I"F:\LC_SWC_Projiectend\TC397_PROJECT_NEW\TC397_DemoProj\Mcal\Tricore\Mcu" -I"F:\LC_SWC_Projiectend\TC397_PROJECT_NEW\TC397_DemoProj\Mcal\Tricore\Mcu\ssc" -I"F:\LC_SWC_Projiectend\TC397_PROJECT_NEW\TC397_DemoProj\Mcal\Tricore\Mcu\ssc\inc" -I"F:\LC_SWC_Projiectend\TC397_PROJECT_NEW\TC397_DemoProj\Mcal\Tricore\Mcu\ssc\src" -I"F:\LC_SWC_Projiectend\TC397_PROJECT_NEW\TC397_DemoProj\Mcal\Tricore\Ocu" -I"F:\LC_SWC_Projiectend\TC397_PROJECT_NEW\TC397_DemoProj\Mcal\Tricore\Ocu\ssc" -I"F:\LC_SWC_Projiectend\TC397_PROJECT_NEW\TC397_DemoProj\Mcal\Tricore\Ocu\ssc\inc" -I"F:\LC_SWC_Projiectend\TC397_PROJECT_NEW\TC397_DemoProj\Mcal\Tricore\Ocu\ssc\src" -I"F:\LC_SWC_Projiectend\TC397_PROJECT_NEW\TC397_DemoProj\Mcal\Tricore\Port" -I"F:\LC_SWC_Projiectend\TC397_PROJECT_NEW\TC397_DemoProj\Mcal\Tricore\Port\ssc" -I"F:\LC_SWC_Projiectend\TC397_PROJECT_NEW\TC397_DemoProj\Mcal\Tricore\Port\ssc\inc" -I"F:\LC_SWC_Projiectend\TC397_PROJECT_NEW\TC397_DemoProj\Mcal\Tricore\Port\ssc\src" -I"F:\LC_SWC_Projiectend\TC397_PROJECT_NEW\TC397_DemoProj\Mcal\Tricore\Pwm_17_GtmCcu6" -I"F:\LC_SWC_Projiectend\TC397_PROJECT_NEW\TC397_DemoProj\Mcal\Tricore\Pwm_17_GtmCcu6\ssc" -I"F:\LC_SWC_Projiectend\TC397_PROJECT_NEW\TC397_DemoProj\Mcal\Tricore\Pwm_17_GtmCcu6\ssc\inc" -I"F:\LC_SWC_Projiectend\TC397_PROJECT_NEW\TC397_DemoProj\Mcal\Tricore\Pwm_17_GtmCcu6\ssc\src" -I"F:\LC_SWC_Projiectend\TC397_PROJECT_NEW\TC397_DemoProj\Mcal\Tricore\Smu" -I"F:\LC_SWC_Projiectend\TC397_PROJECT_NEW\TC397_DemoProj\Mcal\Tricore\Smu\ssc" -I"F:\LC_SWC_Projiectend\TC397_PROJECT_NEW\TC397_DemoProj\Mcal\Tricore\Smu\ssc\inc" -I"F:\LC_SWC_Projiectend\TC397_PROJECT_NEW\TC397_DemoProj\Mcal\Tricore\Smu\ssc\src" -I"F:\LC_SWC_Projiectend\TC397_PROJECT_NEW\TC397_DemoProj\Mcal\Tricore\Spi" -I"F:\LC_SWC_Projiectend\TC397_PROJECT_NEW\TC397_DemoProj\Mcal\Tricore\Spi\ssc" -I"F:\LC_SWC_Projiectend\TC397_PROJECT_NEW\TC397_DemoProj\Mcal\Tricore\Spi\ssc\inc" -I"F:\LC_SWC_Projiectend\TC397_PROJECT_NEW\TC397_DemoProj\Mcal\Tricore\Spi\ssc\src" -I"F:\LC_SWC_Projiectend\TC397_PROJECT_NEW\TC397_DemoProj\Mcal\Tricore\Stm" -I"F:\LC_SWC_Projiectend\TC397_PROJECT_NEW\TC397_DemoProj\Mcal\Tricore\Stm\ssc" -I"F:\LC_SWC_Projiectend\TC397_PROJECT_NEW\TC397_DemoProj\Mcal\Tricore\Stm\ssc\inc" -I"F:\LC_SWC_Projiectend\TC397_PROJECT_NEW\TC397_DemoProj\Mcal\Tricore\Stm\ssc\src" -I"F:\LC_SWC_Projiectend\TC397_PROJECT_NEW\TC397_DemoProj\Mcal\Tricore\Uart" -I"F:\LC_SWC_Projiectend\TC397_PROJECT_NEW\TC397_DemoProj\Mcal\Tricore\Uart\ssc" -I"F:\LC_SWC_Projiectend\TC397_PROJECT_NEW\TC397_DemoProj\Mcal\Tricore\Uart\ssc\inc" -I"F:\LC_SWC_Projiectend\TC397_PROJECT_NEW\TC397_DemoProj\Mcal\Tricore\Uart\ssc\src" -I"F:\LC_SWC_Projiectend\TC397_PROJECT_NEW\TC397_DemoProj\Mcal\Tricore\Wdg_17_Scu" -I"F:\LC_SWC_Projiectend\TC397_PROJECT_NEW\TC397_DemoProj\Mcal\Tricore\Wdg_17_Scu\ssc" -I"F:\LC_SWC_Projiectend\TC397_PROJECT_NEW\TC397_DemoProj\Mcal\Tricore\Wdg_17_Scu\ssc\inc" -I"F:\LC_SWC_Projiectend\TC397_PROJECT_NEW\TC397_DemoProj\Mcal\Tricore\Wdg_17_Scu\ssc\src" -I"F:\LC_SWC_Projiectend\TC397_PROJECT_NEW\TC397_DemoProj\Srval" -I"F:\LC_SWC_Projiectend\TC397_PROJECT_NEW\TC397_DemoProj\Srval\Lib" -I"F:\LC_SWC_Projiectend\TC397_PROJECT_NEW\TC397_DemoProj\Srval\App_Func" -I"F:\LC_SWC_Projiectend\TC397_PROJECT_NEW\TC397_DemoProj\Srval\demo" -I"F:\LC_SWC_Projiectend\TC397_PROJECT_NEW\TC397_DemoProj\Srval\Irq" -I"F:\LC_SWC_Projiectend\TC397_PROJECT_NEW\TC397_DemoProj\Srval\Irq\Adc_Irq" -I"F:\LC_SWC_Projiectend\TC397_PROJECT_NEW\TC397_DemoProj\Srval\Irq\Gtm_Irq" -I"F:\LC_SWC_Projiectend\TC397_PROJECT_NEW\TC397_DemoProj\Srval\Irq\AscLin_Irq" -I"F:\LC_SWC_Projiectend\TC397_PROJECT_NEW\TC397_DemoProj\Srval\Irq\Can_Irq" -I"F:\LC_SWC_Projiectend\TC397_PROJECT_NEW\TC397_DemoProj\Srval\Irq\EthV2_Irq" -I"F:\LC_SWC_Projiectend\TC397_PROJECT_NEW\TC397_DemoProj\Srval\Irq\Stm_Irq" -I"F:\LC_SWC_Projiectend\TC397_PROJECT_NEW\TC397_DemoProj\Srval\Main" -I"F:\LC_SWC_Projiectend\TC397_PROJECT_NEW\TC397_DemoProj\APP" -I"F:\LC_SWC_Projiectend\TC397_PROJECT_NEW\TC397_DemoProj\EAS" -I"F:\LC_SWC_Projiectend\TC397_PROJECT_NEW\TC397_DemoProj\EAS\BSW" -I"F:\LC_SWC_Projiectend\TC397_PROJECT_NEW\TC397_DemoProj\EAS\BSW\BswM" -I"F:\LC_SWC_Projiectend\TC397_PROJECT_NEW\TC397_DemoProj\EAS\BSW\CanIf" -I"F:\LC_SWC_Projiectend\TC397_PROJECT_NEW\TC397_DemoProj\EAS\BSW\CanNm" -I"F:\LC_SWC_Projiectend\TC397_PROJECT_NEW\TC397_DemoProj\EAS\BSW\CanSm" -I"F:\LC_SWC_Projiectend\TC397_PROJECT_NEW\TC397_DemoProj\EAS\BSW\CanTp" -I"F:\LC_SWC_Projiectend\TC397_PROJECT_NEW\TC397_DemoProj\EAS\BSW\CanTSyn" -I"F:\LC_SWC_Projiectend\TC397_PROJECT_NEW\TC397_DemoProj\EAS\BSW\Com" -I"F:\LC_SWC_Projiectend\TC397_PROJECT_NEW\TC397_DemoProj\EAS\BSW\ComM" -I"F:\LC_SWC_Projiectend\TC397_PROJECT_NEW\TC397_DemoProj\EAS\BSW\Common" -I"F:\LC_SWC_Projiectend\TC397_PROJECT_NEW\TC397_DemoProj\EAS\BSW\Crc" -I"F:\LC_SWC_Projiectend\TC397_PROJECT_NEW\TC397_DemoProj\EAS\BSW\Dcm" -I"F:\LC_SWC_Projiectend\TC397_PROJECT_NEW\TC397_DemoProj\EAS\BSW\Dem" -I"F:\LC_SWC_Projiectend\TC397_PROJECT_NEW\TC397_DemoProj\EAS\BSW\Det" -I"F:\LC_SWC_Projiectend\TC397_PROJECT_NEW\TC397_DemoProj\EAS\BSW\DoIP" -I"F:\LC_SWC_Projiectend\TC397_PROJECT_NEW\TC397_DemoProj\EAS\BSW\EcuM" -I"F:\LC_SWC_Projiectend\TC397_PROJECT_NEW\TC397_DemoProj\EAS\BSW\Eth" -I"F:\LC_SWC_Projiectend\TC397_PROJECT_NEW\TC397_DemoProj\EAS\BSW\EthIf" -I"F:\LC_SWC_Projiectend\TC397_PROJECT_NEW\TC397_DemoProj\EAS\BSW\EthSM" -I"F:\LC_SWC_Projiectend\TC397_PROJECT_NEW\TC397_DemoProj\EAS\BSW\EthTrcv" -I"F:\LC_SWC_Projiectend\TC397_PROJECT_NEW\TC397_DemoProj\EAS\BSW\EthTSyn" -I"F:\LC_SWC_Projiectend\TC397_PROJECT_NEW\TC397_DemoProj\EAS\BSW\FiM" -I"F:\LC_SWC_Projiectend\TC397_PROJECT_NEW\TC397_DemoProj\EAS\BSW\FlsTst" -I"F:\LC_SWC_Projiectend\TC397_PROJECT_NEW\TC397_DemoProj\EAS\BSW\MemIf" -I"F:\LC_SWC_Projiectend\TC397_PROJECT_NEW\TC397_DemoProj\EAS\BSW\Nm" -I"F:\LC_SWC_Projiectend\TC397_PROJECT_NEW\TC397_DemoProj\EAS\BSW\NvM" -I"F:\LC_SWC_Projiectend\TC397_PROJECT_NEW\TC397_DemoProj\EAS\BSW\OS" -I"F:\LC_SWC_Projiectend\TC397_PROJECT_NEW\TC397_DemoProj\EAS\BSW\OS\Kernel" -I"F:\LC_SWC_Projiectend\TC397_PROJECT_NEW\TC397_DemoProj\EAS\BSW\OS\Portable" -I"F:\LC_SWC_Projiectend\TC397_PROJECT_NEW\TC397_DemoProj\EAS\BSW\PduR" -I"F:\LC_SWC_Projiectend\TC397_PROJECT_NEW\TC397_DemoProj\EAS\BSW\RamTst" -I"F:\LC_SWC_Projiectend\TC397_PROJECT_NEW\TC397_DemoProj\EAS\BSW\SoAd" -I"F:\LC_SWC_Projiectend\TC397_PROJECT_NEW\TC397_DemoProj\EAS\BSW\StbM" -I"F:\LC_SWC_Projiectend\TC397_PROJECT_NEW\TC397_DemoProj\EAS\BSW\TcpIp" -I"F:\LC_SWC_Projiectend\TC397_PROJECT_NEW\TC397_DemoProj\EAS\BSW\TcpIp\lwip-2.1.2" -I"F:\LC_SWC_Projiectend\TC397_PROJECT_NEW\TC397_DemoProj\EAS\BSW\TcpIp\lwip-2.1.2\api" -I"F:\LC_SWC_Projiectend\TC397_PROJECT_NEW\TC397_DemoProj\EAS\BSW\TcpIp\lwip-2.1.2\arch" -I"F:\LC_SWC_Projiectend\TC397_PROJECT_NEW\TC397_DemoProj\EAS\BSW\TcpIp\lwip-2.1.2\core" -I"F:\LC_SWC_Projiectend\TC397_PROJECT_NEW\TC397_DemoProj\EAS\BSW\TcpIp\lwip-2.1.2\core\ipv4" -I"F:\LC_SWC_Projiectend\TC397_PROJECT_NEW\TC397_DemoProj\EAS\BSW\TcpIp\lwip-2.1.2\core\ipv6" -I"F:\LC_SWC_Projiectend\TC397_PROJECT_NEW\TC397_DemoProj\EAS\BSW\TcpIp\lwip-2.1.2\include" -I"F:\LC_SWC_Projiectend\TC397_PROJECT_NEW\TC397_DemoProj\EAS\BSW\TcpIp\lwip-2.1.2\include\compat" -I"F:\LC_SWC_Projiectend\TC397_PROJECT_NEW\TC397_DemoProj\EAS\BSW\TcpIp\lwip-2.1.2\include\compat\posix" -I"F:\LC_SWC_Projiectend\TC397_PROJECT_NEW\TC397_DemoProj\EAS\BSW\TcpIp\lwip-2.1.2\include\compat\posix\arpa" -I"F:\LC_SWC_Projiectend\TC397_PROJECT_NEW\TC397_DemoProj\EAS\BSW\TcpIp\lwip-2.1.2\include\compat\posix\net" -I"F:\LC_SWC_Projiectend\TC397_PROJECT_NEW\TC397_DemoProj\EAS\BSW\TcpIp\lwip-2.1.2\include\compat\posix\sys" -I"F:\LC_SWC_Projiectend\TC397_PROJECT_NEW\TC397_DemoProj\EAS\BSW\TcpIp\lwip-2.1.2\include\compat\stdc" -I"F:\LC_SWC_Projiectend\TC397_PROJECT_NEW\TC397_DemoProj\EAS\BSW\TcpIp\lwip-2.1.2\include\lwip" -I"F:\LC_SWC_Projiectend\TC397_PROJECT_NEW\TC397_DemoProj\EAS\BSW\TcpIp\lwip-2.1.2\include\lwip\apps" -I"F:\LC_SWC_Projiectend\TC397_PROJECT_NEW\TC397_DemoProj\EAS\BSW\TcpIp\lwip-2.1.2\include\lwip\priv" -I"F:\LC_SWC_Projiectend\TC397_PROJECT_NEW\TC397_DemoProj\EAS\BSW\TcpIp\lwip-2.1.2\include\lwip\prot" -I"F:\LC_SWC_Projiectend\TC397_PROJECT_NEW\TC397_DemoProj\EAS\BSW\TcpIp\lwip-2.1.2\include\netif" -I"F:\LC_SWC_Projiectend\TC397_PROJECT_NEW\TC397_DemoProj\EAS\BSW\TcpIp\lwip-2.1.2\include\netif\ppp" -I"F:\LC_SWC_Projiectend\TC397_PROJECT_NEW\TC397_DemoProj\EAS\BSW\TcpIp\lwip-2.1.2\include\netif\ppp\polarssl" -I"F:\LC_SWC_Projiectend\TC397_PROJECT_NEW\TC397_DemoProj\EAS\BSW\TcpIp\lwip-2.1.2\netif" -I"F:\LC_SWC_Projiectend\TC397_PROJECT_NEW\TC397_DemoProj\EAS\BSW\TcpIp\lwip-2.1.2\netif\ppp" -I"F:\LC_SWC_Projiectend\TC397_PROJECT_NEW\TC397_DemoProj\EAS\BSW\TcpIp\lwip-2.1.2\netif\ppp\polarssl" -I"F:\LC_SWC_Projiectend\TC397_PROJECT_NEW\TC397_DemoProj\EAS\BSW\UdpNm" -I"F:\LC_SWC_Projiectend\TC397_PROJECT_NEW\TC397_DemoProj\EAS\BSW\WdgIf" -I"F:\LC_SWC_Projiectend\TC397_PROJECT_NEW\TC397_DemoProj\EAS\BSW\WdgM" -I"F:\LC_SWC_Projiectend\TC397_PROJECT_NEW\TC397_DemoProj\EAS\BSW\Xcp" -I"F:\LC_SWC_Projiectend\TC397_PROJECT_NEW\TC397_DemoProj\EAS\BSW\Xcp\Cal" -I"F:\LC_SWC_Projiectend\TC397_PROJECT_NEW\TC397_DemoProj\EAS\BSW\Xcp\Daq" -I"F:\LC_SWC_Projiectend\TC397_PROJECT_NEW\TC397_DemoProj\EAS\BSW\Xcp\Pag" -I"F:\LC_SWC_Projiectend\TC397_PROJECT_NEW\TC397_DemoProj\EAS\BSW\Xcp\Pgm" -I"F:\LC_SWC_Projiectend\TC397_PROJECT_NEW\TC397_DemoProj\EAS\BSW\Xcp\Std" -I"F:\LC_SWC_Projiectend\TC397_PROJECT_NEW\TC397_DemoProj\EAS\BSW\Xcp\XcpOnEth" -I"F:\LC_SWC_Projiectend\TC397_PROJECT_NEW\TC397_DemoProj\EAS\Callout" -I"F:\LC_SWC_Projiectend\TC397_PROJECT_NEW\TC397_DemoProj\EAS\Config" -I"F:\LC_SWC_Projiectend\TC397_PROJECT_NEW\TC397_DemoProj\EAS\Library\Vfx_ComE2E" --iso=99 --language=-gcc,-volatile,+strings,-kanji --fp-model=3 --switch=auto --align=0 --default-near-size=0 --default-a0-size=0 --default-a1-size=0 -O1 --tradeoff=2 -g --error-limit=42 --source -c --dep-file="Mcal\Tricore\Can_17_McmCan\ssc\src\.Can_17_McmCan.o.d" -Wc--make-target="Mcal\Tricore\Can_17_McmCan\ssc\src\Can_17_McmCan.o"
DEPENDENCY_FILES += "Mcal\Tricore\Can_17_McmCan\ssc\src\.Can_17_McmCan.o.d"


GENERATED_FILES += "Mcal\Tricore\Can_17_McmCan\ssc\src\Can_17_McmCan.o" "Mcal\Tricore\Can_17_McmCan\ssc\src\.Can_17_McmCan.o.opt" "Mcal\Tricore\Can_17_McmCan\ssc\src\.Can_17_McmCan.o.d" "Mcal\Tricore\Can_17_McmCan\ssc\src\Can_17_McmCan.src" "Mcal\Tricore\Can_17_McmCan\ssc\src\Can_17_McmCan.lst"
