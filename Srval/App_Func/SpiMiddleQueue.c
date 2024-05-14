#include "SpiMiddleQueue.h"

#define TDCU_TEST
#define TESTCASE 1

#ifndef TDCU_TEST

#include "SPI_DMA.h"
#include "stdlib.h"
#include "stdint.h"

#define uint8 uint8_t
#define uint32 uint32_t

#else



#include "Spi.h"
#include "Uart.h"
#include "Uart_Demo.h"
#include "Port.h"

#endif

#define HeaderByte1 0x28
#define HeaderByte2 0x29

uint8 msg_RecvOK[10] = "Recv OK.\r\n";
uint8 msg_ShiftDetect[14] = "shift occur.\r\n";
uint8 msg_HeadNotFound[21] = "no header detected.\r\n";
extern volatile uint8 g_uartIrqTransmit;

static uint8 trans[66] = {0};
static uint8 recv[66] = {0};

static uint8 sendBuf[BUFFER_SIZE];
static uint8 recvBuf[BUFFER_SIZE];

static QUEUE_HandleTypeDef Send_Queue;
static QUEUE_HandleTypeDef Recv_Queue;

static QUEUE_Status Queue_Push(QUEUE_HandleTypeDef *queue, uint8 *data);
static QUEUE_Status Queue_Pop(QUEUE_HandleTypeDef *queue, uint8 *data);
static QUEUE_Status W_SPIQueuePop(uint8 *data_64byte);
static QUEUE_Status R_SPIQueuePush(uint8 *data_64byte);

void initMasterTxBuffers();
void SpiSend(uint8 *psend, uint8 *precv, uint8 size);
void UartSend(uint8 *data, uint8 size);
void dataShift(uint8 *buf, uint8 buf_size, uint8 offset);


void Init_SPIQueue(void)
{
  
    Send_Queue.start = 0;
    Send_Queue.end = 0;
    Send_Queue.length = BUFFER_SIZE;
    Send_Queue.dataBuf = sendBuf;
    Send_Queue.lock = QUEUE_UNLOCK;
    Send_Queue.buf_full = QUEUE_NOTFULL;

    Recv_Queue.start = 0;
    Recv_Queue.end = 0;
    Recv_Queue.length = BUFFER_SIZE;
    Recv_Queue.dataBuf = recvBuf;
    Recv_Queue.lock = QUEUE_UNLOCK;
    Recv_Queue.buf_full = QUEUE_NOTFULL;

}

void W_SPIQueuePush(uint8 *data_64byte, uint8 *result)
{
  QUEUE_Status ret;
  if (Send_Queue.lock == QUEUE_UNLOCK)
  {
    Send_Queue.lock == QUEUE_LOCK;
    ret = Queue_Push(&Send_Queue, data_64byte);
    Send_Queue.lock == QUEUE_UNLOCK;
  }
  else
  {
    ret = STATUS_LOCK;
  }
  *result = ret;
}
QUEUE_Status W_SPIQueuePop(uint8 *data_64byte)
{
  QUEUE_Status ret;
  if (Send_Queue.lock == QUEUE_UNLOCK)
  {
    Send_Queue.lock == QUEUE_LOCK;
    ret = Queue_Pop(&Send_Queue, data_64byte);
    Send_Queue.lock == QUEUE_UNLOCK;
  }
  else
  {
    ret = STATUS_LOCK;
  }
  return ret;
}

QUEUE_Status R_SPIQueuePush(uint8 *data_64byte)
{
  QUEUE_Status ret;
  if (Recv_Queue.lock == QUEUE_UNLOCK)
  {
    Recv_Queue.lock == QUEUE_LOCK;
    ret = Queue_Push(&Recv_Queue, data_64byte);
    Recv_Queue.lock == QUEUE_UNLOCK;
  }
  else
  {
    ret = STATUS_LOCK;
  }
  return ret;
}
void R_SPIQueuePop(uint8 *data_64byte, uint8 *result)
{
  QUEUE_Status ret;
  if (Recv_Queue.lock == QUEUE_UNLOCK)
  {
    Recv_Queue.lock == QUEUE_LOCK;
    ret = Queue_Pop(&Recv_Queue, data_64byte);
    Recv_Queue.lock == QUEUE_UNLOCK;
  }
  else
  {
    ret = STATUS_LOCK;
  }
  *result = ret;
}

QUEUE_Status Queue_Push(QUEUE_HandleTypeDef *queue, uint8 *data)
{
  uint8 res, count = 0;
  uint32 tmp;
  tmp = (queue->end + DATA_LENGTH) % queue->length;

  while (count < DATA_LENGTH)
  {
    queue->dataBuf[queue->end + count] = data[count];
    count++;
  }
  queue->end = tmp;
  if (queue->start == queue->end || queue->buf_full == QUEUE_FULL)
  {
    queue->start = tmp;
    queue->buf_full = QUEUE_FULL;
  }
  res = STATUS_OK;

  return res;
}

QUEUE_Status Queue_Pop(QUEUE_HandleTypeDef *queue, uint8 *data)
{
  uint8 res = STATUS_OK, count = 0;
  uint32 tmp;

  if (queue->start == queue->end && queue->buf_full == QUEUE_NOTFULL)
  {
    res = STATUS_EMPTY;
  }
  else
  {
    while (count < DATA_LENGTH)
    {
      data[count] = queue->dataBuf[queue->start + count];
      count++;
    }
    queue->start = (queue->start + DATA_LENGTH) % queue->length;

    if (queue->buf_full == QUEUE_FULL)
    {
      queue->buf_full = QUEUE_NOTFULL;
    }

    res = STATUS_OK;
  }

  return res;
}

void initMasterTxBuffers()
{
  for (int i = 0; i < 66; i++)
  {
    trans[i] = 0xFF;
  }
}

void UartSend(uint8 *data, uint8 size)
{
  uint8 myret = 0;
  g_uartIrqTransmit=0;
  Uart_Write(0, &data[0], size);

  while(!g_uartIrqTransmit);
  g_uartIrqTransmit =0;
}

void SpiSend(uint8 *psend, uint8 *precv, uint8 size)
{
  uint32 counter = 0;
  uint8 ret = 0;

  ret = Spi_SetupEB(SpiConf_SpiChannel_SpiChannel_0, (Spi_DataBufferType *)psend, (Spi_DataBufferType *)precv, size);
  ret = Spi_SyncTransmit(SpiConf_SpiSequence_SpiSequence_0);

  ret = Spi_GetSequenceResult(SpiConf_SpiSequence_SpiSequence_0);
  while (ret != E_OK && counter != 2000u)
  {
    ret = Spi_GetSequenceResult(SpiConf_SpiSequence_SpiSequence_0);
    if (ret == SPI_SEQ_FAILED)
    {
      //debug("spi communication failed.");
    }
    counter++;
  }
}

void dataShift(uint8 *buf, uint8 buf_size, uint8 offset)
{
  int index = 0;
  for (int i = offset; i < buf_size; i++)
  {
    buf[index] = buf[offset];
    index++;
  }
}

// void receivedData (void)
//{
//     uint32 i;
//     uint32 error = 0;
//
//     static uint8 count = 1;
//
//     /* Enable SPI Slave for communication */
//     g_qspiDma.qspiBuffer.spiSlaveTxBuffer[0] = count;
//
//     IfxQspi_SpiSlave_exchange(&g_qspiDma.spiSlave, &g_qspiDma.qspiBuffer.spiSlaveTxBuffer[0],
//             &g_qspiDma.qspiBuffer.spiSlaveRxBuffer[0], SPI_BUFFER_SIZE);
//
//     /* Wait until the slave received all data */
//     while (IfxQspi_SpiSlave_getStatus(&g_qspiDma.spiSlave) == SpiIf_Status_busy)
//     {
//     }
//
//     /* Compare exchanged data */
//     for (i = 0; i < SPI_BUFFER_SIZE; i++)
//     {
//         if (g_qspiDma.qspiBuffer.spiSlaveRxBuffer[i] != g_qspiDma.qspiBuffer.spiMasterTxBuffer[i])
//         {
//             error++;
//         }
//     }
//     /* Switch on the LED D110 in case of no errors (LED is low-level active) */
//     if (error == 0)
//     {
//         IfxPort_togglePin(LED_D109);
//
//     }
//     count++;
// }

void ExchangeData(void)
{
#ifdef TDCU_TEST

  uint8 sec_pos, offset = 0;

  for (uint8 k = 0; k < 66; k++)
  {
    trans[k] = 0;
    recv[k] = 0;
  }
  /* Setup header */
  trans[0] = HeaderByte1;
  trans[1] = HeaderByte2;

  //debug("start Exchange().");

  /* Get data from Ring buffer(write)*/

  if (W_SPIQueuePop(&trans[2]) == STATUS_EMPTY)
  {

    /* Start SPI Master 2 byte Header communication */
    SpiSend(trans, recv, 2);

    /* Check header data */
    if (recv[0] == HeaderByte1 && recv[1] == HeaderByte2)
    {
      /* Start SPI 64 byte data transfer */
      SpiSend(&trans[2], &recv[2], SPI_BUFFER_SIZE - 2);
      R_SPIQueuePush(&recv[2]);
    }
    else if (recv[1] == HeaderByte1)
    {
      /* Start SPI Master after 1 byte communication */
      trans[0] = 0;
      SpiSend(&trans[0], &recv[1], 1);
      if (recv[1] == HeaderByte2)
      {
        /* Start SPI Master after 64 byte communication */
        SpiSend(&trans[2], &recv[2], SPI_BUFFER_SIZE - 2);
        R_SPIQueuePush(&recv[2]);
      }
      else
      {
        // Header error or no header detected
       UartSend(msg_HeadNotFound, sizeof(msg_HeadNotFound));
      }
    }
  }
  else
  {

    /* Start SPI 66 byte data transfer */
    SpiSend(trans, recv, 66);
    /* Check header position*/
    for (int i = 0; i < SPI_BUFFER_SIZE - 1; i++)
    {
      if (recv[i] == HeaderByte1 && recv[i + 1] == HeaderByte2)
      {
        break;
      }
      offset++;
    }
    if (offset == 0)
    {
      // header OK
      R_SPIQueuePush(&recv[2]);
    }
    else if (offset > 0 && offset < DATA_LENGTH)
    {
      // header shift
      // need shift data from offset to index 0
      
      dataShift(&trans[0], DATA_LENGTH, offset);
      initMasterTxBuffers();

      sec_pos = DATA_LENGTH - offset;

      SpiSend(trans, &recv[sec_pos], offset);
      R_SPIQueuePush(&recv[0]);
     UartSend(msg_ShiftDetect, sizeof(msg_ShiftDetect));
    }
    else if (offset == SPI_BUFFER_SIZE - 1)
    {
      // Header error or no header detected
     UartSend(msg_HeadNotFound, sizeof(msg_HeadNotFound));
    }
  }

#else
  uint32 i;
  uint32 error = 0;

  uint8 offset = 0;
  uint8 sec_pos = 0;

  /* Get data from Ring buffer(write)*/
  if (W_SPIQueuePop(&g_qspiDma.qspiBuffer.spiMasterTxBuffer[2]) == STATUS_EMPTY)
  {

    /* Start SPI Master 2 byte Header communication */
    IfxQspi_SpiMaster_exchange(&g_qspiDma.spiMasterChannel, &g_qspiDma.qspiBuffer.spiMasterTxBuffer[0],
                               &g_qspiDma.qspiBuffer.spiMasterRxBuffer[0], 2);
    /* Check header data */

    if (g_qspiDma.qspiBuffer.spiMasterRxBuffer[0] == HeaderByte1 && g_qspiDma.qspiBuffer.spiMasterRxBuffer[1] == HeaderByte2)
    {

      /* Start SPI 64 byte data transfer */
      IfxQspi_SpiMaster_exchange(&g_qspiDma.spiMasterChannel, &g_qspiDma.qspiBuffer.spiMasterTxBuffer[0],
                                 &g_qspiDma.qspiBuffer.spiMasterRxBuffer[0], DATA_LENGTH);

      R_SPIQueuePush(&g_qspiDma.qspiBuffer.spiMasterRxBuffer[0]);
    }
    else if (g_qspiDma.qspiBuffer.spiMasterRxBuffer[1] == HeaderByte1)
    {
      /* Start SPI Master after 65 byte communication */
      IfxQspi_SpiMaster_exchange(&g_qspiDma.spiMasterChannel, &g_qspiDma.qspiBuffer.spiMasterTxBuffer[0],
                                 &g_qspiDma.qspiBuffer.spiMasterRxBuffer[0], SPI_BUFFER_SIZE - 1);

      if (g_qspiDma.qspiBuffer.spiMasterRxBuffer[0] == HeaderByte2)
      {
        IfxQspi_SpiMaster_exchange(&g_qspiDma.spiMasterChannel, &g_qspiDma.qspiBuffer.spiMasterTxBuffer[0],
                                   &g_qspiDma.qspiBuffer.spiMasterRxBuffer[1], DATA_LENGTH);
      }
    }
  }
  else
  {
    /* Setup header */
    g_qspiDma.qspiBuffer.spiMasterTxBuffer[0] = HeaderByte1;
    g_qspiDma.qspiBuffer.spiMasterTxBuffer[1] = HeaderByte2;
    /* Start SPI 66 byte data transfer */
    IfxQspi_SpiMaster_exchange(&g_qspiDma.spiMasterChannel, &g_qspiDma.qspiBuffer.spiMasterTxBuffer[0],
                               &g_qspiDma.qspiBuffer.spiMasterRxBuffer[0], SPI_BUFFER_SIZE);

    /* Check header position*/
    for (i = 0; i < SPI_BUFFER_SIZE - 1; i++)
    {

      if (g_qspiDma.qspiBuffer.spiMasterRxBuffer[i] == HeaderByte1 && g_qspiDma.qspiBuffer.spiMasterRxBuffer[i + 1] == HeaderByte2)
      {
        break;
      }
      offset++;
    }
    if (offset > 0 && offset < DATA_LENGTH)
    {
      // need shift data from offset to index 0
      dataShift(&g_qspiDma.qspiBuffer.spiMasterRxBuffer[0], DATA_LENGTH, offset);
      initQSPI2MasterTxBuffers();

      sec_pos = DATA_LENGTH - offset;

      IfxQspi_SpiMaster_exchange(&g_qspiDma.spiMasterChannel, &g_qspiDma.qspiBuffer.spiMasterTxBuffer[0],
                                 &g_qspiDma.qspiBuffer.spiMasterRxBuffer[sec_pos], offset);

      R_SPIQueuePush(&g_qspiDma.qspiBuffer.spiMasterRxBuffer[0]);
    }
    else if (offset == SPI_BUFFER_SIZE - 1)
    {
      // no header received
    }
  }
#endif
  //debug("end exchange().");
}

