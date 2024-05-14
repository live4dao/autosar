/*
 * Ethernet.h
 *
 *  Created on: 2024年1月22日
 *      Author: Brandon
 */

#ifndef SRVAL_DEMO_ETHERNET_H_
#define SRVAL_DEMO_ETHERNET_H_

void Eth_Swt_Enable (void);
void Tx_EthFrame (void);
void Receive_Poll (void);
void Ping_App(void);
void TransmitArpFrame(void);
void Eth_PortPin_tdcu_Boot (void);
void Eth_PortPin_alt (void);


#endif /* SRVAL_DEMO_ETHERNET_H_ */
