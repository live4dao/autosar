/******************************************************************************
**                                                                           **
** Copyright (C) Infineon Technologies (2020)                                **
**                                                                           **
** All rights reserved.                                                      **
**                                                                           **
** This document contains proprietary information belonging to Infineon      **
** Technologies. Passing on and copying of this document, and communication  **
** of its contents is not permitted without prior written authorization.     **
**                                                                           **
*******************************************************************************
**                                                                           **
**  FILENAME   : EthTrcv.h                                                   **
**                                                                           **
**  VERSION    : 1.0.0                                                       **
**                                                                           **
**  DATE       : 2020-08-27                                                  **
**                                                                           **
**  VARIANT    : NA                                                          **
**                                                                           **
**  PLATFORM   : Infineon AURIX2G                                            **
**                                                                           **
**  AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION  : This file exports ETHTRCV functions                       **
**                  This file is for Evaluation Purpose Only                 **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: yes                                     **
**                                                                           **
******************************************************************************/

#ifndef ETHTRCV_H
#define ETHTRCV_H

#include "Eth_17_GEthMacV2.h"
#include "EthTrcv_Types.h"
extern void EthTrcv_WriteMiiIndication( uint8 CtrlIdx, uint8 TrcvIdx, uint8 RegIdx );
extern void EthTrcv_ReadMiiIndication( uint8 CtrlIdx, uint8 TrcvIdx, uint8 RegIdx, uint8 RegVal );
extern Std_ReturnType EthTrcv_SetTransceiverMode( uint8 TrcvIdx, EthTrcv_ModeType CtrlMode);
extern Std_ReturnType EthTrcv_GetTransceiverMode( uint8 TrcvIdx, EthTrcv_ModeType *TrcvModePtr);
extern Std_ReturnType EthTrcv_GetLinkState( uint8 TrcvIdx, EthTrcv_LinkStateType *LinkStatePtr);
#endif /* End of ETHTRCV_H */
