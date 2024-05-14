/*
 * Uart_Demo.c
 *
 *  Created on: 2024年1月23日
 *      Author: Brandon
 */



/******************************************************************************
**                      Includes                                             **
******************************************************************************/
#include "Std_Types.h"
#include "IfxAsclin_reg.h"
#include "IfxSrc_reg.h"
#include "Irq.h"
#include "Uart.h"
#include "Uart_Demo.h"
//#include <stdarg.h>
//#include <stdio.h>
//#include <string.h>

/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/

#define UART_SRC_SET_SRE          (1U)

/*******************************************************************************
**                      Private Variable Declarations                         **
*******************************************************************************/

uint8 g_uartIrqTransmit = 0;
/*******************************************************************************
**                      Private Function Definitions                          **
*******************************************************************************/

/******************************************************************************/
/********************Write notification function*******************************/
/******************************************************************************/
void UartTx(Uart_ErrorIdType ErrorId)
{
  if(ErrorId == UART_E_NO_ERR)
  {
    g_uartIrqTransmit = 1;
  /* 20 frames transmited successfully */
  }
}


/******************************************************************************/
/********************Read notification function********************************/
/******************************************************************************/
void UartRx(Uart_ErrorIdType ErrorId)
{
  if(ErrorId == UART_E_NO_ERR)
  {
    /* 20 frames received without error start process received data */
  }
}


/******************************************************************************/
/******************************** UART Driver Demo  ***************************/
/******************************************************************************/

void Uart_Demo()
{
  Uart_Init(&Uart_Config);
  IrqAsclin_Init();
  // ASCLIN0
  // P14.0  OUT TX ASC0
  // P14.1  IN RX ASC0
  SRC_ASCLIN9TX.B.SRE = UART_SRC_SET_SRE;
  SRC_ASCLIN9RX.B.SRE = UART_SRC_SET_SRE;
  SRC_ASCLIN9ERR.B.SRE = UART_SRC_SET_SRE;
}


void debug_printf(char *format, ...)
{
    char   message[255 + 1];
    sint16 count;
    va_list   args;
    va_start(args, format);
    vsprintf((char *)message, format, args);
    va_end(args);
    count = (sint16)strlen(message);

    g_uartIrqTransmit = 0;
    /* Uart write */
    Uart_Write(0,message,count);
    while (g_uartIrqTransmit == 0) {}
}


