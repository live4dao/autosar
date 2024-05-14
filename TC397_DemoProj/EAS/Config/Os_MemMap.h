
/*****************************************************************************
* General QAC Suppression
******************************************************************************/
/*PRQA S 0841,0890,0883 EOF*/
/*
This part has been verified and has no problem.
Current C compilers do support "#undef"
*/

/*PRQA S 3608 EOF*/
/*
Current compilers support "#elif".
*/

/*PRQA S 3116 EOF*/
/*
"#pragma section" directives are different for different compilers.
This part has been verified and has no problem.
*/

/*****************************************************************************
**                                 OS                                      **
******************************************************************************/


/* -------------------------------------------------------------------------- */
/* Begin alignment mapping of OS                                              */
/* -------------------------------------------------------------------------- */
/*code*/
#if defined (OS_START_SEC_CODE)
	#pragma section all= "Os_Code_Section"
#undef      OS_START_SEC_CODE
#elif defined (OS_STOP_SEC_CODE)
	#pragma section all restore
#undef      OS_STOP_SEC_CODE
#endif

#if defined (OS_START_SEC_CALLOUT_CODE)
	#pragma section all= "Os_Code_Section"
#undef      OS_START_SEC_CALLOUT_CODE
#elif defined (OS_STOP_SEC_CALLOUT_CODE)
	#pragma section all restore
#undef      OS_STOP_SEC_CALLOUT_CODE
#endif
/*var noinit*/
#if defined (OS_START_SEC_VAR_NOINIT_8)
	#pragma section all="OS_KERNEL_RAM_NOINIT_8BIT"
	#pragma align 1
#undef      OS_START_SEC_VAR_NOINIT_8
#elif defined (OS_STOP_SEC_VAR_NOINIT_8)
	#pragma align restore
	#pragma section all restore
#undef      OS_STOP_SEC_VAR_NOINIT_8
#endif

#if defined (OS_START_SEC_VAR_NOINIT_16)
	#pragma section all="OS_KERNEL_RAM_NOINIT_16BIT"
	#pragma align 2
#undef      OS_START_SEC_VAR_NOINIT_16
#elif defined (OS_STOP_SEC_VAR_NOINIT_16)
	#pragma align restore
	#pragma section all restore
#undef      OS_STOP_SEC_VAR_NOINIT_16
#endif

#if defined (OS_START_SEC_VAR_NOINIT_32)
	#pragma section all="OS_KERNEL_RAM_NOINIT_32BIT"
	#pragma align 4
#undef      OS_START_SEC_VAR_NOINIT_32
#elif defined (OS_STOP_SEC_VAR_NOINIT_32)
	#pragma align restore
	#pragma section all restore
#undef      OS_STOP_SEC_VAR_NOINIT_32
#endif

#if defined (OS_START_SEC_VAR_NOINIT_UNSPECIFIED)
	#pragma section all= "OS_KERNEL_RAM_NOINIT_UNSPECIFIED"
#undef      OS_START_SEC_VAR_NOINIT_UNSPECIFIED
#elif defined (OS_STOP_SEC_VAR_NOINIT_UNSPECIFIED)
	#pragma section all restore
#undef      OS_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#endif
/*var init*/
#if defined (OS_START_SEC_VAR_INIT_UNSPECIFIED)
	#pragma section all= "OS_KERNEL_RAM_INIT_UNSPECIFIED"
#undef      OS_START_SEC_VAR_INIT_UNSPECIFIED
#elif defined (OS_STOP_SEC_VAR_INIT_UNSPECIFIED)
	#pragma section all restore
#undef      OS_STOP_SEC_VAR_INIT_UNSPECIFIED
#endif
/*const*/
#if defined (OS_START_SEC_CONST_UNSPECIFIED)
#undef      OS_START_SEC_CONST_UNSPECIFIED
	#pragma section all= "DEFAULT_CONST_UNSPECIFIED"
#elif defined (OS_STOP_SEC_CONST_UNSPECIFIED)
	#pragma section all restore
#undef      OS_STOP_SEC_CONST_UNSPECIFIED
#endif

#if defined (OS_START_SEC_CONST_8)
	#pragma section all="DEFAULT_CONST_8BIT"
	#pragma align 1
#undef      OS_START_SEC_CONST_8
#elif defined (OS_STOP_SEC_CONST_8)
	#pragma align restore
	#pragma section all restore
#undef      OS_STOP_SEC_CONST_8
#endif

#if defined (OS_START_SEC_CONST_16)
	#pragma section all="DEFAULT_CONST_16BIT"
	#pragma align 2
#undef      OS_START_SEC_CONST_16
#elif defined (OS_STOP_SEC_CONST_16)
	#pragma align restore
	#pragma section all restore
#undef      OS_STOP_SEC_CONST_16
#endif

#if defined (OS_START_SEC_CONST_32)
	#pragma section all="DEFAULT_CONST_32BIT"
	#pragma align 4
#undef      OS_START_SEC_CONST_32
#elif defined (OS_STOP_SEC_CONST_32)
	#pragma align restore
	#pragma section all restore
#undef      OS_STOP_SEC_CONST_32
#endif
/*config const*/
#if defined (OS_START_SEC_CONFIG_DATA_8)
	#pragma section all="DEFAULT_CONST_8BIT"
	#pragma align 1
#undef      OS_START_SEC_CONFIG_DATA_8
#elif defined (OS_STOP_SEC_CONFIG_DATA_8)
	#pragma align restore
	#pragma section all restore
#undef      OS_STOP_SEC_CONFIG_DATA_8
#endif

#if defined (OS_START_SEC_CONFIG_DATA_UNSPECIFIED)
	#pragma section all="DEFAULT_CONST_UNSPECIFIED"
#undef      OS_START_SEC_CONFIG_DATA_UNSPECIFIED
#elif defined (OS_STOP_SEC_CONFIG_DATA_UNSPECIFIED)
	#pragma section all restore
#undef      OS_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#endif

#if defined (OS_START_SEC_VAR_NOINIT_MULTICORE)
	#pragma section all= "OS_KERNEL_RAM_NOINIT_MULTICORE_UNSPECIFIED"
#undef      OS_START_SEC_VAR_NOINIT_MULTICORE
#elif defined (OS_STOP_SEC_VAR_NOINIT_MULTICORE)
	#pragma section all restore
#undef      OS_STOP_SEC_VAR_NOINIT_MULTICORE
#endif
#if defined (OS_START_SEC_VAR_INIT_MULTICORE)
	#pragma section all= "OS_KERNEL_RAM_INIT_MULTICORE_UNSPECIFIED"
#undef      OS_START_SEC_VAR_INIT_MULTICORE
#elif defined (OS_STOP_SEC_VAR_INIT_MULTICORE)
	#pragma section all restore
#undef      OS_STOP_SEC_VAR_INIT_MULTICORE
#endif
#if defined (OS_START_SEC_OS_STACK_CORE0)
	#pragma section all="OS_STACK0"
#undef      OS_START_SEC_OS_STACK_CORE0
#elif defined (OS_STOP_SEC_OS_STACK_CORE0)
	#pragma section all restore
#undef      OS_STOP_SEC_OS_STACK_CORE0
#endif

#if defined (OS_START_SEC_OS_STACK_CORE1)
	#pragma section all="OS_STACK1"
#undef      OS_START_SEC_OS_STACK_CORE1
#elif defined (OS_STOP_SEC_OS_STACK_CORE1)
	#pragma section all restore
#undef      OS_STOP_SEC_OS_STACK_CORE1
#endif

#if defined (OS_START_SEC_OS_STACK_CORE2)
	#pragma section all="OS_STACK2"
#undef      OS_START_SEC_OS_STACK_CORE2
#elif defined (OS_STOP_SEC_OS_STACK_CORE2)
	#pragma section all restore
#undef      OS_STOP_SEC_OS_STACK_CORE2
#endif

#if defined (OS_START_SEC_OS_STACK_CORE3)
	#pragma section all="OS_STACK3"
#undef      OS_START_SEC_OS_STACK_CORE3
#elif defined (OS_STOP_SEC_OS_STACK_CORE3)
	#pragma section all restore
#undef      OS_STOP_SEC_OS_STACK_CORE3
#endif

#if defined (OS_START_SEC_OS_STACK_CORE4)
	#pragma section all="OS_STACK4"
#undef      OS_START_SEC_OS_STACK_CORE4
#elif defined (OS_STOP_SEC_OS_STACK_CORE4)
	#pragma section all restore
#undef      OS_STOP_SEC_OS_STACK_CORE4
#endif

#if defined (OS_START_SEC_OS_STACK_CORE5)
	#pragma section all="OS_STACK5"
#undef      OS_START_SEC_OS_STACK_CORE5
#elif defined (OS_STOP_SEC_OS_STACK_CORE5)
	#pragma section all restore
#undef      OS_STOP_SEC_OS_STACK_CORE5
#endif

