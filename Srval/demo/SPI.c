/*
 * SPI.c
 *
 *  Created on: 2024年1月25日
 *      Author: Dell
 */
#include "Spi.h"
#include "Port.h"

void Spi4Send(uint8 *psend, uint8 *precv, uint8 size)
{
  uint32 counter = 0;
  uint8 ret = 0;

  ret = Spi_SetupEB(SpiConf_SpiChannel_SpiChannel_1, (Spi_DataBufferType *)psend, (Spi_DataBufferType *)precv, size);
  ret = Spi_SyncTransmit(SpiConf_SpiSequence_SpiSequence_1);

  while (Spi_GetSequenceResult(SpiConf_SpiSequence_SpiSequence_1) != E_OK && counter != 2000u)
  {
    if (Spi_GetSequenceResult(SpiConf_SpiSequence_SpiSequence_1) == SPI_SEQ_FAILED)
    {
      break;
    }
    counter++;
  }
  counter = 0;
  if (Spi_GetSequenceResult(SpiConf_SpiSequence_SpiSequence_1) != E_OK)
  {
    // break;
  }
}


void Spi_PortPin_tdcu_boot()
{
    Port_SetPinMode(PortConf_PortContainer_7_PORT_14_PIN_6, PORT_INPUT_PULL_UP);
    Port_SetPinMode(PortConf_PortContainer_7_PORT_14_PIN_5, PORT_INPUT_PULL_UP);
    Port_SetPinMode(PortConf_PortContainer_7_PORT_14_PIN_10, PORT_INPUT_PULL_UP);

}


void Spi_PortPin_alt()
{
    Port_SetPinDirection(PortConf_PortContainer_7_PORT_14_PIN_6, PORT_PIN_OUT);
    Port_SetPinMode(PortConf_PortContainer_7_PORT_14_PIN_6, PORT_PIN_MODE_ALT2);

    Port_SetPinDirection(PortConf_PortContainer_7_PORT_14_PIN_10, PORT_PIN_OUT);
    Port_SetPinMode(PortConf_PortContainer_7_PORT_14_PIN_10, PORT_PIN_MODE_ALT2);

    Port_RefreshPortDirection();
}
