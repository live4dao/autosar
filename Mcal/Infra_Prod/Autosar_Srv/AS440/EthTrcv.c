/******************************************************************************
**                                                                           **
** Copyright (C) Infineon Technologies (2021)                                **
**                                                                           **
** All rights reserved.                                                      **
**                                                                           **
** This document contains proprietary information belonging to Infineon      **
** Technologies. Passing on and copying of this document, and communication  **
** of its contents is not permitted without prior written authorization.     **
**                                                                           **
*******************************************************************************
**                                                                           **
**  FILENAME    : EthTrcv.c                                                  **
**                                                                           **
**  CC VERSION  : 2.0.0                                                      **
**                                                                           **
**  $DATE       : 2021-11-208                                                **
**                                                                           **
**  AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION : This file contains                                         **
**                Implementation of ETH Transceiver functions                **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: Yes                                     **
**                                                                           **
******************************************************************************/

#include "EthTrcv.h"

#ifdef APP_SW
#if (APP_SW == TEST_APP)
#include "Test_EthTrcv.h"
#endif /*#if (APP_SW == TEST_APP)*/
#endif
static EthTrcv_ModeType EthTrcv_CtrlMode = ETHTRCV_MODE_DOWN;
//STATIC VAR(EthTrcv_WakeupModeType, ETHTRCV_APPL_DATA) EthTrcv_WakeupMode = ETHTRCV_WUM_DISABLE;

void EthTrcv_WriteMiiIndication( uint8 CtrlIdx, uint8 TrcvIdx, uint8 RegIdx )
{
  #ifdef APP_SW
  #if (APP_SW == TEST_APP)
  Test_EthTrcv_WriteMiiIndication(CtrlIdx,TrcvIdx,RegIdx);
  #endif /*#if (APP_SW == TEST_APP)*/
  #endif
}

void EthTrcv_ReadMiiIndication( uint8 CtrlIdx, uint8 TrcvIdx, uint8 RegIdx,
                                                              uint8 RegVal )
{
  #ifdef APP_SW
  #if (APP_SW == TEST_APP)
  Test_EthTrcv_ReadMiiIndication(CtrlIdx,TrcvIdx,RegIdx,RegVal);
  #endif /*#if (APP_SW == TEST_APP)*/
  #endif
}

Std_ReturnType EthTrcv_SetTransceiverMode
(
    uint8 TrcvIdx,
    EthTrcv_ModeType CtrlMode
)
{
    Std_ReturnType ret = E_OK;

    if(CtrlMode == ETHTRCV_MODE_ACTIVE)
    {
        EthTrcv_CtrlMode = ETHTRCV_MODE_ACTIVE;
    }
    else
    {
        EthTrcv_CtrlMode = ETHTRCV_MODE_DOWN;
    }

    CtrlMode = EthTrcv_CtrlMode;
    
	EthIf_TrcvModeIndication(TrcvIdx, CtrlMode);
}

Std_ReturnType EthTrcv_GetTransceiverMode
(
    uint8 TrcvIdx,
    EthTrcv_ModeType *TrcvModePtr
)
{
    *TrcvModePtr = EthTrcv_CtrlMode;
	return E_OK;
}

Std_ReturnType EthTrcv_GetLinkState
(
    uint8 TrcvIdx,
    EthTrcv_LinkStateType *LinkStatePtr
)
{
    *LinkStatePtr = ETHTRCV_LINK_STATE_ACTIVE;

	return E_OK;
}