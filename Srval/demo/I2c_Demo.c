/*********************************************************************************************************************/
/*-----------------------------------------------------Includes------------------------------------------------------*/
/*********************************************************************************************************************/

#include "I2c.h"
#include "IfxSrc_reg.h"

/*********************************************************************************************************************/
/*------------------------------------------------------Macros-------------------------------------------------------*/
/*********************************************************************************************************************/
#define MCP79411_EEPROM_ADDRESS     0x57                        /* 7 bit slave device address for reading from EEPROM
                                                                   of MCP79411 is 0b1010111 which is 0x57.          */
#define ADDRESS_OF_MAC_ADDRESS      0xF2                        /* Location of EUI-48 node address (MAC address)    */
#define LENGTH_OF_ADDRESS           1                           /* Length of address of the register, in which the
                                                                   requested MAC address is stored in bytes         */
#define LENGTH_OF_MAC_ADDRESS       6                           /* Length of the MAC address in bytes               */

/*********************************************************************************************************************/
/*-------------------------------------------------Global variables--------------------------------------------------*/
/*********************************************************************************************************************/
uint8 g_macAddr[LENGTH_OF_MAC_ADDRESS] = {0, 0, 0, 0, 0, 0};    /* Global parameter for 6-byte EUI-48 MAC address   */

/*********************************************************************************************************************/
/*---------------------------------------------Function Implementations----------------------------------------------*/
/*********************************************************************************************************************/

uint32 count = 0;

void IoHwAb_I2cNotification0(I2c_ErrorType ErrorId)
{
    count++;
    if(ErrorId)
    {
        while(1);
    }
}

#define I2C_USER_CHANNEL0 (0)
 
uint8  I2C_Test_ret = 0;
void I2C_Test()
{
    // uint8  I2C_Test_ret = 0;
    //Async read operation
    /* Address of 6-byte EUI-48 MAC address location */
    uint8 i2cTxBuffer[1] = {ADDRESS_OF_MAC_ADDRESS};


    // Sync read operation
    // 0x57 << 1 == 0xAE
    I2C_Test_ret = I2c_SyncWrite(I2C_USER_CHANNEL0, &i2cTxBuffer[0], 1, MCP79411_EEPROM_ADDRESS);//write read address
    // while(I2c_GetStatus(I2C_USER_CHANNEL0) == I2C_BUSY);
    I2C_Test_ret = I2c_SyncRead(I2C_USER_CHANNEL0, &g_macAddr[0], 6, MCP79411_EEPROM_ADDRESS);//read register
    while(I2c_GetStatus(I2C_USER_CHANNEL0) == I2C_BUSY);

    // //Async read operation
    // I2c_AsyncWrite(I2C_USER_CHANNEL0, &i2cTxBuffer[0], LENGTH_OF_ADDRESS, MCP79411_EEPROM_ADDRESS);//write read address
    // while(I2c_GetStatus(I2C_USER_CHANNEL0) == I2C_BUSY);
    // I2c_AsyncRead(I2C_USER_CHANNEL0, &g_macAddr[0], LENGTH_OF_MAC_ADDRESS, MCP79411_EEPROM_ADDRESS);//read register
    // while(I2c_GetStatus(I2C_USER_CHANNEL0) == I2C_BUSY);
}

void CAN_Normal_Mode()
{
    // uint8  I2C_Test_ret = 0;
    //Async read operation
    /* Address of 6-byte EUI-48 MAC address location */
    uint8 i2cTxBuffer[2]= {0};
    /* Set output value */
    i2cTxBuffer[0] = 0x2;
    /* [P07:P00] 0010 0000 */
    i2cTxBuffer[1] = 0x20;

    // Sync read operation
    // 0x57 << 1 == 0xAE
    I2C_Test_ret = I2c_SyncWrite(I2C_USER_CHANNEL0, i2cTxBuffer, 2, 0x77);//write read address
    while(I2c_GetStatus(I2C_USER_CHANNEL0) == I2C_BUSY);
    /* Set P00-P06 to output mode */
    i2cTxBuffer[0] = 0x6;
    /* [P07:P00] 1000 0000 */
    i2cTxBuffer[1] = 0x80;
    I2C_Test_ret = I2c_SyncWrite(I2C_USER_CHANNEL0, i2cTxBuffer, 2, 0x77);//write read address
     while(I2c_GetStatus(I2C_USER_CHANNEL0) == I2C_BUSY);

    // //Async read operation
    // I2c_AsyncWrite(I2C_USER_CHANNEL0, &i2cTxBuffer[0], LENGTH_OF_ADDRESS, MCP79411_EEPROM_ADDRESS);//write read address
    // while(I2c_GetStatus(I2C_USER_CHANNEL0) == I2C_BUSY);
    // I2c_AsyncRead(I2C_USER_CHANNEL0, &g_macAddr[0], LENGTH_OF_MAC_ADDRESS, MCP79411_EEPROM_ADDRESS);//read register
    // while(I2c_GetStatus(I2C_USER_CHANNEL0) == I2C_BUSY);
}
void I2c_Enable_Service_Request(void)
{
    SRC_I2C0DTR.B.SRE = 1;
    SRC_I2C0ERR.B.SRE = 1;    
    SRC_I2C0P.B.SRE = 1;
}


