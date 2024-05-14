#ifndef QUEUE_H
#define QUEUE_H

#define BUFFER_SIZE 192 // 64*3
#define SPI_BUFFER_SIZE 66
#define DATA_LENGTH 64

#define QUEUE_UNLOCK 0
#define QUEUE_LOCK 1
#define QUEUE_NOTFULL 0
#define QUEUE_FULL 1

#include "Std_Types.h"

typedef struct QUEUE_HandleTypeDef
{
    uint32 start;
    uint32 end;
    uint32 length;
    uint8 *dataBuf;
    uint8 lock;
    uint8 buf_full;
} QUEUE_HandleTypeDef;

typedef enum QUEUE_Status
{
    STATUS_OK = 0,
    STATUS_INIT_FAIL,
    STATUS_EMPTY,
    STATUS_BUFFULL,
    STATUS_LOCK
} QUEUE_Status;

void Init_SPIQueue(void);

void W_SPIQueuePush(uint8 *data_64byte, uint8 *result);
void R_SPIQueuePop(uint8 *data_64byte, uint8 *result);

void ExchangeData(void);
 
#endif
