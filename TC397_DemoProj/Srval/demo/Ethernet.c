/*
 * Ethernet.c
 *
 *  Created on: 2024骞�1鏈�22鏃�
 *      Author: Brandon
 */
#include "Mcal_Version.h"
#include "Eth_17_GEthMacV2.h"
#include "EthIf.h"
#include "IfxSrc_reg.h"
#include "Port.h"
#include "Dio.h"

#define ETH_IP_PROTOCOL                         (0X0800U)
#define ETH_ARP_PROTOCOL                        (0X0806U)

#define PHY_CTRL_REG                            (0x00)
#define PHY_STAT_REG                            (0x01)
#define PHY_PHYCTL1_REG                         (0x13)
#define PHY_PHYCTL2_REG                         (0x14)
#define PHY_MIICTRL_REG                         (0x17)

#define PHY_100MBPS_FULLDPLX_REG_VAL            (0x2100)

#define PHY_PHYCTL1_REG_VAL                     (0x0001)
#define PHY_PHYCTL2_REG_VAL                     (0x8006)
/*PHY Status Reg Link status bit position*/
#define PHY_STAT_REG_LS_SHIFT                   (0x02)
#define PHY_MIICTRL_RMII_REG_VAL                (0xF702)

#define ETH_PHY_REG_COUNT                       (32U)

#define ETH_PHY_INIT_DURATION                   (2000U)
#define PHY_READ_DELAY                          (500U)
#define DELAY_30SEC                             (30000U)

#define ETH_FRAME_TYPE_1                        (0xABCDU)

#define MMC_TX_GB_REG_BASE_OFFSET               (0x124U)
#define MMC_RX_GB_REG_BASE_OFFSET               (0x1ACU)

#define ETH_ESC_CHAR_ASCII_VAL                  (27U)

#define ETH_OFFSET_4_BYTE                       (4U)
#define ETH_OFFSET_8_BYTE                       (8U)
#define ETH_OFFSET_12_BYTE                      (12U)
#define ETH_OFFSET_16_BYTE                      (16U)
#define ETH_OFFSET_20_BYTE                      (20U)

#define ETH_IPADDRESS_LENGTH                    (4U)

#define ETH_ARPFRAME_DEST_IPADD_OFFSET          (24U)

/*PHY Interface Mode Value*/
#define ETH_RGMII_MODE                          (0x00400000U)
#define ETH_RMII_MODE                           (0x01000000U)
#define ETH_MII_MODE                            (0x00000000U)

#define RTL8211F_PHY_STATUS                     0x1a
#define RTL8211F_AUTONEG_ENABLE                 0x1000
#define RTL8211F_PHYSTAT_SPEED                  0x0030
#define RTL8211F_PHYSTAT_GBIT                   0x0020
#define RTL8211F_PHYSTAT_100                    0x0010
#define RTL8211F_PHYSTAT_DUPLEX                 0x0008
#define RTL8211F_PHYSTAT_SPDDONE                0x0800
#define RTL8211F_PHYSTAT_LINK                   0x0004
#define RTL8211F_PAGE_SELECT                    0x1f
#define RTL8211F_TX_DELAY                       0x100

/* PHY Identifier Registers */
#define RTL8211F_PHY_ID1          (0x001cU)      /* PHY_ID1 for RTL8211F */
#define RTL8211F_PHY_ID2          (0xc916U)      /* PHY_ID2 for RTL8211F */

#define MII_BMCR                  0x00  /* Basic mode control register */
#define MII_BMSR                  0x01  /* Basic mode status register  */
#define MII_PHYSID1               0x02  /* PHYS ID 1                   */
#define MII_PHYSID2               0x03  /* PHYS ID 2                   */
#define MII_PHYADDR               0x19  /* PHY address                 */
#define BMCR_RESET                0x8000  /* Reset to default state      */

/* Basic mode control register. */
#define BMCR_SPEED1000            0x0040  /* MSB of Speed (1000)         */
#define BMCR_FULLDPLX             0x0100  /* Full duplex                 */
#define BMCR_ANRESTART            0x0200  /* Auto negotiation restart    */
#define BMCR_SPEED100             0x2000  /* Select 100Mbps              */
#define BMCR_SPEED10              0x0000  /* Select 10Mbps               */

/* Basic mode status register. */
#define BMSR_ANEGCOMPLETE         0x0020  /* Auto-negotiation complete   */

#define ETH_FRAMEHEADER_LENGTH       (14U)
#define ETH_FRAMECHKSUM_LENGTH       (4U)
#define ETH_SHIFT_8BIT               (8U)
#define ETH_SHIFT_16BIT              (16U)
#define ETH_SHIFT_24BIT              (24U)

/* Macro for Numbers. */
#define ETH_17_ZERO                  (0U)
#define ETH_17_ONE                   (1U)
#define ETH_MOD_ENABLE               (0U)


static uint8 Temp_Macaddress[6];
static volatile BufReq_ReturnType Global_TempUSage1;
static Eth_BufIdxType TmpBuffIdx;
volatile Std_ReturnType EthDemoRetVal;

volatile uint16 Test_EthTxConfirmCount[ETH_17_GETHMACV2_MAX_CONTROLLERS];
volatile uint16 Eth_RxFrame_Length[ETH_17_GETHMACV2_MAX_CONTROLLERS];
volatile uint16 Test_EthRxConfirmCount[ETH_17_GETHMACV2_MAX_CONTROLLERS];

static uint8 MacDestArpaddress[6] =
{0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF}; /*Broadcast*/
uint8 ArpData[28] =
{
  0x00, 0x01, 0x08, 0x00, 0x06, 0x04, 0x00, 0x01, 0x00, 0x03, 0x19, 0x00, 0x00, 0x01,
  0xa9, 0xfe, 0xfe, 0xab, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xa9, 0xfe, 0xab, 0xa8
};

uint32 Src_IPaddress = 0xa9fefeab;
Eth_RxStatusType RxStatus;
uint8 ArpReply;


extern void delay_ms(uint32 ms);

/*******************************************************************************
**    Fill Tx Buffer           **
*******************************************************************************/

void TxBufferFill(uint8 *pTxBuff, uint16 DataLen, uint8 *Framedatax )
{
  uint8 i = 0;

  for(; i < DataLen ; i++)
  {
    *(pTxBuff + i) = Framedatax[i];
  }

  return;
}

/*******************************************************************************
**    Transmit Arp Frame           **
*******************************************************************************/
void TransmitArpFrame(void)
{
  boolean Txstatus1 = 0;
  uint16 Tmp_Txlenghth1 = 28;
  uint8 *TmpEthTxBuffPtr;
  #if(MCAL_AR_VERSION == MCAL_AR_440)
  uint8 Test_Priority = 0;
  Global_TempUSage1 = Eth_17_GEthMacV2_ProvideTxBuffer(0,Test_Priority, &TmpBuffIdx, &TmpEthTxBuffPtr, &Tmp_Txlenghth1);
  #else
  Global_TempUSage1 = Eth_17_GEthMac_ProvideTxBuffer(0, &TmpBuffIdx, &TmpBuffPtr, &Tmp_Txlenghth1);
  #endif

  if (Global_TempUSage1 == BUFREQ_OK)
  {
    //print_f("\n BUFREQ_OK ");
  }
  else if (Global_TempUSage1 == BUFREQ_E_NOT_OK)
  {
    //print_f("\n BUFREQ_E_NOT_OK ");
  }
  else if (Global_TempUSage1 == BUFREQ_E_BUSY)
  {
    //print_f("\n BUFREQ_E_BUSY ");
  }
  else if (Global_TempUSage1 == BUFREQ_E_OVFL)
  {
    //print_f("\n BUFREQ_E_OVFL ");
  }

  TxBufferFill(TmpEthTxBuffPtr, Tmp_Txlenghth1, ArpData);

  #if(MCAL_AR_VERSION == MCAL_AR_440)
  EthDemoRetVal = Eth_17_GEthMacV2_Transmit(0, TmpBuffIdx, ETH_ARP_PROTOCOL, \
  Txstatus1, Tmp_Txlenghth1, &MacDestArpaddress[0]);
  #else
  EthDemoRetVal = Eth_17_GEthMac_Transmit(0, TmpBuffIdx, ETH_ARP_PROTOCOL, \
  Txstatus1, Tmp_Txlenghth1, &MacDestBrodaddress[0]);
  #endif

  if(EthDemoRetVal == E_OK)
  {
    //print_f("\n GEthMac Transmit SUCCESS");
  }
  else
  {
    //print_f("\n GEthMac Transmit Failed");
  }
}
/*******************************************************************************
**    Ping Application                                            **
*******************************************************************************/
void Ping_App(void)
{
  uint8 i;
  char param[20];
  char szString1[20]="192.168.6.78";
  char *pszString1;
  uint32 paramArray[6];
  volatile uint32 TimeoutCntr = 0;
  uint8 paramCount = 0, charCount = 0;
  #if(MCAL_AR_VERSION == MCAL_AR_440)
  uint8 Test_FifoIdx = 0;
  #endif

  //print_f("\n\n Enter IP Address to Ping(Your PC IP) : ");
  //getline(szString1, sizeof szString1 - 1);
  pszString1 = &szString1[0];

  do
  {
    /* Look for the '.' delimiter */
    if (*pszString1 != '.')
    {
      param[charCount++] = (char) * pszString1;
    }
    else
    {
      param[charCount] = 0;
      paramArray[paramCount] = (uint32)atoi(param);
      paramCount++;
      charCount = 0;
    }
    pszString1++;
  } while (*pszString1 != '\0');

  //print_f("\n After Do while Loop ");
  param[charCount] = 0;
  paramArray[paramCount] = (uint32) atoi(param);

  for(i = 0; i < ETH_IPADDRESS_LENGTH; i++)
  {
    ArpData[ETH_ARPFRAME_DEST_IPADD_OFFSET + i] = (uint8)paramArray[i];
  }

  Src_IPaddress = (((paramArray[0] & 0xFF) << ETH_SHIFT_24BIT) |  \
  ((paramArray[1] & 0xFF) << ETH_SHIFT_16BIT) | ((paramArray[2] & 0xFF) << ETH_SHIFT_8BIT) \
   | (paramArray[3] & 0xFF));

  //print_f("\n Enter TransmitArpFrame() ");
  TransmitArpFrame();
  //print_f("\n Exit TransmitArpFrame() ");

  do
  {
    #if(MCAL_AR_VERSION == MCAL_AR_440)
    Eth_17_GEthMacV2_Receive(0, Test_FifoIdx, (Eth_RxStatusType* )&RxStatus);
    #else
    Eth_17_GEthMac_Receive(0, (Eth_RxStatusType* )&RxStatus);
    #endif
    delay_ms(1);
    TimeoutCntr++;
  } while(( ArpReply != 1) && (DELAY_30SEC != TimeoutCntr));

  if(ArpReply == 1)
  {
    //print_f("\n ArpReply OK\n  ");
    ArpReply = 0;
    //StartResult();
    //print_f("Result = Pass;");
    //EndResult();
  }
  else
  {
    //print_f("\n Destination Host Unreachable\n  ");
    //print_f("Reason 1: Ethernet Cross Wire is NOT connected between AURIX Tri-Board and Your PC\n ");
    //print_f("Reason 2: IP Address Entered is Wrong\n ");
    //StartResult();
    //print_f("Result = Fail;");
    //EndResult();
  }
}


/*******************************************************************************
**    Promiscuous mode Receive all Frames                                     **
*******************************************************************************/
uint8 PromiscuousCheck;
void Receive_Poll (void)
{
  volatile uint32 TimeoutCntr = 0;
  #if(MCAL_AR_VERSION == MCAL_AR_440)
  uint8 Test_FifoIdx = 0;

  Eth_17_GEthMacV2_GetPhysAddr(0, Temp_Macaddress);

  /* Update filter for Open filter mode */
  Eth_17_GEthMacV2_UpdatePhysAddrFilter(0, (uint8*)&MacDestArpaddress, ETH_ADD_TO_FILTER);

  do
  {
    Eth_17_GEthMacV2_Receive(0, Test_FifoIdx, (Eth_RxStatusType* )&RxStatus);
    delay_ms(1);
    TimeoutCntr++;
  }
  #else
  Eth_17_GEthMac_GetPhysAddr(0, Ret_MacAddr);

  /* Update filter for Open filter mode */
  Eth_17_GEthMac_UpdatePhysAddrFilter(0, (uint8*)&MacDestBrodaddress, ETH_ADD_TO_FILTER);

  do
  {
    Eth_17_GEthMac_Receive(0, (Eth_RxStatusType* )&RxStatus);
    Timer_DelayMs(1);
    TimeoutCntr++;
  }
  #endif
  while(DELAY_30SEC != TimeoutCntr);
  /* Wait for 30 secs to receive frames */

  if((Test_EthRxConfirmCount[0])&&(PromiscuousCheck))
  {
//    StartResult();
//    print_f("Result = Pass;");
//    EndResult();
  }
  else
  {
//    StartResult();
//    print_f("Result = Fail;");
//    EndResult();
  }
}

/*******************************************************************************
**    Initialise Eth Driver including PHY        **
*******************************************************************************/

void GEthV2ControllerInit (void)
{
  uint16 RET;
  RET= Eth_17_GEthMacV2_SetControllerMode(0, ETH_MODE_ACTIVE);
  if(RET == E_OK)
  {

   // printf("\n\n Eth_17_GEthMac_SetControllerMode Success ");
  }
  else {

    //printf("\n\n Eth_17_GEthMac_SetControllerMode Failed ");
  }

  //printf("\n\n ENTER Eth_17_GEthMac_GetPhysAddr ");
  Eth_17_GEthMacV2_GetPhysAddr((uint8)0, &Temp_Macaddress[0]);

  //printf("\n\n Eth_17_GEthMac_GetPhysAddr =%x:%x:%x:%x:%x:%x", Temp_Macaddress[0], \
   Temp_Macaddress[1], Temp_Macaddress[2], Temp_Macaddress[3], Temp_Macaddress[4], Temp_Macaddress[5]);

}

/* PHY Reset */
void local_GETH_PHY_Reset(uint8 phy_addr)
{
  uint16 reg_bmcr;

  /* Reset PHY*/
  Eth_17_GEthMacV2_ReadMii(0, 1, MII_BMCR, &reg_bmcr);
  reg_bmcr |= BMCR_RESET;
  Eth_17_GEthMacV2_WriteMii(0, 1, MII_BMCR, reg_bmcr);

  /* Wait for the reset to complete */
  do
  {
    Eth_17_GEthMacV2_ReadMii(0, 1, MII_BMCR, &reg_bmcr);
  } while ((reg_bmcr & BMCR_RESET) != 0);
}
/******************************************************************************
* Function Name : EthTest_Init()                           *
* Description   : Test funtion to Initialize ETHERNET module*
*******************************************************************************/
void GEthV2PhyInit(void)
{
 // printf("\n Calling EthMac_Init API;\n\n");
    Eth_17_GEthMacV2_Init(&Eth_17_GEthMacV2_Config);
 // printf("\n  EthMac_Init API; Done \n\n");

  uint16 phy_id1 = 0;
  uint16 phy_id2 = 0;
  uint16 reg_value = 0;
  uint16 val = 0;

  do
  {
    /* Check Device Identification. */
    Eth_17_GEthMacV2_ReadMii(0, 1, MII_PHYSID1, &phy_id1);
    Eth_17_GEthMacV2_ReadMii(0, 1, MII_PHYSID2, &phy_id2);
  } while((phy_id1 != RTL8211F_PHY_ID1) && (phy_id2 != RTL8211F_PHY_ID2));

  local_GETH_PHY_Reset(1);
  delay_ms(PHY_READ_DELAY);

  Eth_17_GEthMacV2_WriteMii(0, 1, RTL8211F_PAGE_SELECT, 0xa43);
  Eth_17_GEthMacV2_ReadMii(0, 1, 0x19, &reg_value);

  reg_value |= 0x1;
  Eth_17_GEthMacV2_WriteMii(0, 1, 0x19, reg_value);
  Eth_17_GEthMacV2_WriteMii(0, 1, RTL8211F_PAGE_SELECT, 0x0);

  /* A PHY reset should be issued after setting this bits in PHYCR2 */
  local_GETH_PHY_Reset(1);
  delay_ms(PHY_READ_DELAY);

  Eth_17_GEthMacV2_WriteMii(0, 1, RTL8211F_PAGE_SELECT, 0xd08);
  Eth_17_GEthMacV2_ReadMii(0, 1, 0x11, &reg_value);

  /* Adding TX-delay for RGMII mode*/
  {
    reg_value |= RTL8211F_TX_DELAY;
  }

  Eth_17_GEthMacV2_WriteMii(0, 1, 0x11, reg_value);
  /* restore to default page 0 */
  Eth_17_GEthMacV2_WriteMii(0, 1, RTL8211F_PAGE_SELECT, 0x0);

  /* Disable green Ethernet */
  Eth_17_GEthMacV2_WriteMii(0, 1, RTL8211F_PAGE_SELECT, 0xa43);
  Eth_17_GEthMacV2_WriteMii(0, 1, 27, 0x8011);
  Eth_17_GEthMacV2_WriteMii(0, 1, 28, 0x573f);
  Eth_17_GEthMacV2_WriteMii(0, 1, RTL8211F_PAGE_SELECT, 0x0);

  /* Set green LED for Link, yellow LED for Active */
  Eth_17_GEthMacV2_WriteMii(0, 1, RTL8211F_PAGE_SELECT, 0xd04);
  Eth_17_GEthMacV2_WriteMii(0, 1, 0x10, 0x617f);
  Eth_17_GEthMacV2_WriteMii(0, 1, RTL8211F_PAGE_SELECT, 0x0);
  reg_value = 0U;

//  printf ("Configured 1000 Mbps \n");
//  reg_value |= BMCR_SPEED1000;
  reg_value |= BMCR_SPEED100;

 // printf ("Configured Full Duplex \n");
  reg_value |= BMCR_FULLDPLX;

  Eth_17_GEthMacV2_WriteMii(0, 1, MII_BMCR, reg_value);

  do
  {
    delay_ms(PHY_READ_DELAY);
    /*Link Speed status */
    Eth_17_GEthMacV2_WriteMii(0, 1, RTL8211F_PAGE_SELECT, 0xa43);
    Eth_17_GEthMacV2_ReadMii(0, 1, RTL8211F_PHY_STATUS, &val);
    Eth_17_GEthMacV2_WriteMii(0, 1, RTL8211F_PAGE_SELECT, 0);
  } while((val & RTL8211F_PHYSTAT_LINK) != 0x0004);

 // printf("\n\n ETH Driver Initialised Successfully!! ");
//  printf("\n\n Ethernet LINK UP ");

  /*Delay added since ETh_init takes time to stabilize */
  delay_ms(ETH_PHY_INIT_DURATION);
}


/*******************************************************************************
**    Transmit ETH Frame of User Defined Length                               **
*******************************************************************************/
void Tx_EthFrame (void)
{
  volatile uint32 TimeoutCntr;
  char szString[80];
  uint16 TmpTxlength, i;
  uint8 *TmpEthTxBuffPtr;

  Test_EthTxConfirmCount[0] = 0;

//  printf("\n\n Enter ETH Frame Payload Length(42...1500) : ");
//  getline(szString, sizeof szString - 1);

  TmpTxlength = 28;//(uint16)atoi(szString);

  Global_TempUSage1 = Eth_17_GEthMacV2_ProvideTxBuffer(0,0, &TmpBuffIdx, &TmpEthTxBuffPtr, &TmpTxlength);

  for (i = 0; i < TmpTxlength ; i++)
  {
    *TmpEthTxBuffPtr = i + 1;
    TmpEthTxBuffPtr += 1;
  }

  EthDemoRetVal = Eth_17_GEthMacV2_Transmit(0, TmpBuffIdx, ETH_FRAME_TYPE_1, \
   1, TmpTxlength, &MacDestArpaddress[0]);

  TimeoutCntr = 0x7FFFFF;
#if 1
   do
  {
    Eth_17_GEthMacV2_TxConfirmation(0);
  }
  while((!Test_EthTxConfirmCount[0])&&(TimeoutCntr--));

  if(Test_EthTxConfirmCount[0])
  {
//    printf("\n Transmitted ETH Frame of FrameType 0xABCD");
//    printf("\n Payload Length %d bytes and Total Frame Length %d bytes\n", \
//    TmpTxlength, (TmpTxlength + ETH_FRAMEHEADER_LENGTH + ETH_FRAMECHKSUM_LENGTH));
    Test_EthTxConfirmCount[0] = 0;

//    StartResult();
//    printf("Result = Pass;");
//    EndResult();
  }
  else
  {
//    StartResult();
//    printf("Result = Fail;");
//    EndResult();
  }
#endif
}

/*******************************************************************************
**    Eth_SWT enable                               **
*******************************************************************************/
void Eth_Swt_Enable (void)
{
    delay_ms(1000);
    Dio_WriteChannel(DioConf_DioChannel_ETHSW_RSTN, STD_HIGH);
    delay_ms(1000);
    //GEthV2PhyInit();
    Eth_17_GEthMacV2_Init(&Eth_17_GEthMacV2_Config);
    EthDemoRetVal=Eth_17_GEthMacV2_SetControllerMode(0, ETH_MODE_DOWN);
    uint8 MacAddress[6]={0};

    MacAddress[0] = 0xDE;
    MacAddress[1] = 0xAD;
    MacAddress[2] = 0xBE;
    MacAddress[3] = 0xEF;
    MacAddress[4] = 0xFE;
    MacAddress[5] = 0xED;
    Eth_17_GEthMacV2_SetPhysAddr(0, &MacAddress[0]);
    Eth_17_GEthMacV2_GetPhysAddr((uint8)0, &Temp_Macaddress[0]);
    //GEthV2ControllerInit();
    /*Enable ETH TX and RX Interrupt*/
    IrqEthernet_Init();
    SRC_GETH_GETH0_SR2.B.SRE = 1;
    SRC_GETH_GETH0_SR6.B.SRE = 1;

}
void Eth_PortPin_tdcu_Boot (void)
{

    //MDC
    Port_SetPinMode(PortConf_PortContainer_5_PORT_12_PIN_0, PORT_OUTPUT_PUSH_PULL);
    Dio_WriteChannel(DIO_CHANNEL_12_0, 0x00);
    //MDIO
    Port_SetPinMode(PortConf_PortContainer_5_PORT_12_PIN_1, PORT_OUTPUT_PUSH_PULL);
    Dio_WriteChannel(DIO_CHANNEL_12_1, 0x00);
    //TX0
    Port_SetPinMode(PortConf_PortContainer_4_PORT_11_PIN_3, PORT_OUTPUT_PUSH_PULL);
    Dio_WriteChannel(DIO_CHANNEL_11_3, 0x00);
    //TX1
    Port_SetPinMode(PortConf_PortContainer_4_PORT_11_PIN_2, PORT_OUTPUT_PUSH_PULL);
    Dio_WriteChannel(DIO_CHANNEL_11_2, 0x00);
    //TX2
    Port_SetPinMode(PortConf_PortContainer_4_PORT_11_PIN_1, PORT_OUTPUT_PUSH_PULL);
    Dio_WriteChannel(DIO_CHANNEL_11_1, 0x00);
    //TX3
    Port_SetPinMode(PortConf_PortContainer_4_PORT_11_PIN_0, PORT_OUTPUT_PUSH_PULL);
    Dio_WriteChannel(DIO_CHANNEL_11_0, 0x00);
    //TXCTL
    Port_SetPinMode(PortConf_PortContainer_4_PORT_11_PIN_6, PORT_OUTPUT_PUSH_PULL);
    Dio_WriteChannel(DIO_CHANNEL_11_6, 0x00);
    //TXCLK
    Port_SetPinMode(PortConf_PortContainer_4_PORT_11_PIN_4, PORT_INPUT_PULL_UP);

}

void Eth_PortPin_alt (void)
{

    //MDC
    Port_SetPinDirection(PortConf_PortContainer_5_PORT_12_PIN_0, PORT_PIN_OUT);
    Port_SetPinMode(PortConf_PortContainer_5_PORT_12_PIN_0, PORT_PIN_MODE_ALT6);
    //MDIO
    /* Port_SetPinDirection(PortConf_PortContainer_5_PORT_12_PIN_1, PORT_PIN_OUT); */
    /* Port_SetPinMode(PortConf_PortContainer_5_PORT_12_PIN_1, PORT_OUTPUT_PUSH_PULL); */
    //TX0
    Port_SetPinDirection(PortConf_PortContainer_4_PORT_11_PIN_3, PORT_PIN_OUT);
    Port_SetPinMode(PortConf_PortContainer_4_PORT_11_PIN_3, PORT_PIN_MODE_ALT6);
    //TX1
    Port_SetPinDirection(PortConf_PortContainer_4_PORT_11_PIN_2, PORT_PIN_OUT);
    Port_SetPinMode(PortConf_PortContainer_4_PORT_11_PIN_2, PORT_PIN_MODE_ALT6);
    //TX2
    Port_SetPinDirection(PortConf_PortContainer_4_PORT_11_PIN_1, PORT_PIN_OUT);
    Port_SetPinMode(PortConf_PortContainer_4_PORT_11_PIN_1, PORT_PIN_MODE_ALT6);
    //TX3
    Port_SetPinDirection(PortConf_PortContainer_4_PORT_11_PIN_0, PORT_PIN_OUT);
    Port_SetPinMode(PortConf_PortContainer_4_PORT_11_PIN_0, PORT_PIN_MODE_ALT6);
    //TXCTL
    Port_SetPinDirection(PortConf_PortContainer_4_PORT_11_PIN_6, PORT_PIN_OUT);
    Port_SetPinMode(PortConf_PortContainer_4_PORT_11_PIN_6, PORT_PIN_MODE_ALT6);

    Port_SetPinDirection(PortConf_PortContainer_4_PORT_11_PIN_4, PORT_PIN_OUT);
    Port_SetPinMode(PortConf_PortContainer_4_PORT_11_PIN_4, PORT_PIN_MODE_ALT7);
    Port_RefreshPortDirection();
}
