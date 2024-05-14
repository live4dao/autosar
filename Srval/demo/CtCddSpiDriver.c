#include "Std_Types.h"

#include "CtCddSpiDriver.h"
#include "Uart.h"

uint8 test_data[64] = "0123456789:;ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
uint8 read_data[64] = {0};
uint8 cmp66[64] = "0000123456789012345678901234567890123456789012345678901234567890";
uint8 msg_IndexErr[21] = "Index error occur.\r\n";
uint8 msg_DataErr[19] = "Data error occur.\r\n";

uint8 data_index = 1;
uint8 ret = 0;
void DemoMiddleWareInit()
{
    Init_SPIQueue();
}
void DemoMiddleWare()
{
    test_data[0] = data_index;
    for (int i = 0; i < 64; i++)
    {
        read_data[i] = 0;
    }
    W_SPIQueuePush(&test_data[0], &ret);

    ExchangeData();

    R_SPIQueuePop(&read_data[0], &ret);
    // check message index
    if (ret == STATUS_OK)
    {
        if (read_data[0] != data_index)
        {
            // data check error
            UartSend(msg_DataErr, sizeof(msg_DataErr));
        }
        else
        {

            for (int i = 1; i <= DATA_LENGTH - 1; i++)
            {
                if (read_data[i] != cmp66[i])
                {
                    // data check error
                   UartSend(msg_DataErr, sizeof(msg_DataErr));
                    break;
                }
            }

            if (data_index == 255)
            {
                data_index = 1;
            }
            else
            {
                data_index++;
            }
        }
    }
}
