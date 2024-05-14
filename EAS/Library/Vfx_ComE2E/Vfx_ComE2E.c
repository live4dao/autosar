/* ********************************************************************************************************************
 *
 * COPYRIGHT RESERVED, 2021 VinFast Trading and Production LLC. All rights reserved.
 * The reproduction, distribution and utilization of this document as well as the communication of its contents to
 * others without explicit authorization is prohibited. Offenders will be held liable for the payment of damages.
 * All rights reserved in the event of the grant of a patent, utility model or design.
 *
 ******************************************************************************************************************* */


/* ********************************************************************************************************************
 * Files inclusion
 ******************************************************************************************************************* */

#include "Vfx_VfE2ELib.h"
# include "Rte_Type.h"
#include "Com_Cfg.h"
#include "com_code.h"
// #include "Rte_ComDataConv.h"
/* ********************************************************************************************************************
 * Internal Macros
 ******************************************************************************************************************* */
 typedef uint8 (*RTEcall_SetEventStatus_fp)(Dem_EventStatusType SetFaultSts);

 typedef struct
{
  uint16                          PduID;
  Dem_EventIdType        DemID;
  RTEcall_SetEventStatus_fp RTEcall_SetEventStatusCRC;
  RTEcall_SetEventStatus_fp RTEcall_SetEventStatusCNT;
} LCxE2EIDFormatType;

/* Macro to generate protect or check state variable */                                  
  static LCE2ELib_ProtectStateType_tst ComE2E_ProtectState_ACAN_ADAS_01={0};
  static LCE2ELib_ProtectStateType_tst ComE2E_ProtectState_ACAN_ADAS_02={0};
  static LCE2ELib_ProtectStateType_tst ComE2E_ProtectState_ACAN_ADAS_03={0};
  static LCE2ELib_ProtectStateType_tst ComE2E_ProtectState_ACAN_ADAS_Info23={0};
/* ********************************************************************************************************************
 * Static function declaration
 ******************************************************************************************************************* */
#if 0
 boolean CC_ACAN_ACU_ChimeTelltaleReq_E2E(PduIdType PduId, PduInfoType *PduInfoPtr)
 {
  Std_ReturnType ProcessStatus_o;                                            
    boolean CheckResult_o;                                                     
    (void)PduId;     

    ProcessStatus_o = LCE2ELib_Check_Last1(PduInfoPtr->SduDataPtr, (uint16)PduInfoPtr->SduLength);       
    if (E_OK == ProcessStatus_o)
    {
        CheckResult_o = TRUE ;
    }
    else
    {
        CheckResult_o = FALSE;   
    }
    
        return CheckResult_o;           

 }
 boolean CC_ACAN_BCM_LIGHT_0x106_E2E(PduIdType PduId, PduInfoType *PduInfoPtr)
 {
  Std_ReturnType ProcessStatus_o;                                            
    boolean CheckResult_o;                                                     
    (void)PduId;     

    ProcessStatus_o = LCE2ELib_Check(PduInfoPtr->SduDataPtr, (uint16)PduInfoPtr->SduLength);       
    if (E_OK == ProcessStatus_o)
    {
        CheckResult_o = TRUE ;
    }
    else
    {
        CheckResult_o = FALSE;   
    }
    
        return CheckResult_o;           

 }
 boolean CC_ACAN_BCM_SwitchSts_0x109_E2E(PduIdType PduId, PduInfoType *PduInfoPtr)
 {
  Std_ReturnType ProcessStatus_o;                                            
    boolean CheckResult_o;                                                     
    (void)PduId;     

    ProcessStatus_o = LCE2ELib_Check(PduInfoPtr->SduDataPtr, (uint16)PduInfoPtr->SduLength);       
    if (E_OK == ProcessStatus_o)
    {
        CheckResult_o = TRUE ;
    }
    else
    {
        CheckResult_o = FALSE;   
    }
    
        return CheckResult_o;           

 }
 boolean CC_ACAN_ABS_FrontWheelSpeMCUKPH_E2E(PduIdType PduId, PduInfoType *PduInfoPtr)
 {
  Std_ReturnType ProcessStatus_o;                                            
    boolean CheckResult_o;                                                     
    (void)PduId;     

    ProcessStatus_o = LCE2ELib_Check_Last(PduInfoPtr->SduDataPtr, (uint16)PduInfoPtr->SduLength);       
    if (E_OK == ProcessStatus_o)
    {
        CheckResult_o = TRUE ;
    }
    else
    {
        CheckResult_o = FALSE;   
    }
    
        return CheckResult_o;           

 }
 boolean CC_ACAN_ABS_RearWheelSpeMCUKPH_E2E(PduIdType PduId, PduInfoType *PduInfoPtr)
 {
  Std_ReturnType ProcessStatus_o;                                            
    boolean CheckResult_o;                                                     
    (void)PduId;     

    ProcessStatus_o = LCE2ELib_Check_Last(PduInfoPtr->SduDataPtr, (uint16)PduInfoPtr->SduLength);       
    if (E_OK == ProcessStatus_o)
    {
        CheckResult_o = TRUE ;
    }
    else
    {
        CheckResult_o = FALSE;   
    }
    
        return CheckResult_o;           

 }
 boolean CC_ACAN_ABS_WheelSpeedRC_E2E(PduIdType PduId, PduInfoType *PduInfoPtr)
 {
  Std_ReturnType ProcessStatus_o;                                            
    boolean CheckResult_o;                                                     
    (void)PduId;     

    ProcessStatus_o = LCE2ELib_Check_Last(PduInfoPtr->SduDataPtr, (uint16)PduInfoPtr->SduLength);       
    if (E_OK == ProcessStatus_o)
    {
        CheckResult_o = TRUE ;
    }
    else
    {
        CheckResult_o = FALSE;   
    }
    
        return CheckResult_o;           

 }
 boolean CC_ACAN_ABS_Status_E2E(PduIdType PduId, PduInfoType *PduInfoPtr)
 {

     Std_ReturnType ProcessStatus_o;                                            
    boolean CheckResult_o;                                                     
    (void)PduId;     
   
    ProcessStatus_o = LCE2ELib_Check_Last( PduInfoPtr->SduDataPtr,(uint16)PduInfoPtr->SduLength);       
    if (E_OK == ProcessStatus_o)
    {
        CheckResult_o = TRUE ;
    }
    else
    {
        CheckResult_o = FALSE;   
    }
    
        return CheckResult_o;  

 }
 boolean CC_ACAN_ESC_Status_0x132_E2E(PduIdType PduId, PduInfoType *PduInfoPtr)
 {

     Std_ReturnType ProcessStatus_o;                                            
    boolean CheckResult_o;                                                     
    (void)PduId;     
   
    ProcessStatus_o = LCE2ELib_Check( PduInfoPtr->SduDataPtr,(uint16)PduInfoPtr->SduLength);       
    if (E_OK == ProcessStatus_o)
    {
        CheckResult_o = TRUE ;
    }
    else
    {
        CheckResult_o = FALSE;   
    }
    
        return CheckResult_o;  

 }
 boolean CC_ACAN_VCU_Ctrl_E2E(PduIdType PduId, PduInfoType *PduInfoPtr)
 {

     Std_ReturnType ProcessStatus_o;                                            
    boolean CheckResult_o;                                                     
    (void)PduId;     
   
    ProcessStatus_o = LCE2ELib_Check_Last( PduInfoPtr->SduDataPtr,(uint16)PduInfoPtr->SduLength);       
    if (E_OK == ProcessStatus_o)
    {
        CheckResult_o = TRUE ;
    }
    else
    {
        CheckResult_o = FALSE;   
    }
    
        return CheckResult_o;  

 }
 boolean CC_ACAN_VCU_StsEpt_E2E(PduIdType PduId, PduInfoType *PduInfoPtr)
 {

     Std_ReturnType ProcessStatus_o;                                            
    boolean CheckResult_o;                                                     
    (void)PduId;     
   
    ProcessStatus_o = LCE2ELib_Check_Last( PduInfoPtr->SduDataPtr,(uint16)PduInfoPtr->SduLength);       
    if (E_OK == ProcessStatus_o)
    {
        CheckResult_o = TRUE ;
    }
    else
    {
        CheckResult_o = FALSE;   
    }
    
        return CheckResult_o;  

 }
 boolean CC_ACAN_SAS_Sensor_0x17E_E2E(PduIdType PduId, PduInfoType *PduInfoPtr)
 {

     Std_ReturnType ProcessStatus_o;                                            
    boolean CheckResult_o;                                                     
    (void)PduId;     
   
    ProcessStatus_o = LCE2ELib_Check( PduInfoPtr->SduDataPtr,(uint16)PduInfoPtr->SduLength);       
    if (E_OK == ProcessStatus_o)
    {
        CheckResult_o = TRUE ;
    }
    else
    {
        CheckResult_o = FALSE;   
    }
    
        return CheckResult_o;  

 }
 boolean CC_ACAN_EPS_LKA_Sts_E2E(PduIdType PduId, PduInfoType *PduInfoPtr)
 {

     Std_ReturnType ProcessStatus_o;                                            
    boolean CheckResult_o;                                                     
    (void)PduId;     
   
    ProcessStatus_o = LCE2ELib_Check1( PduInfoPtr->SduDataPtr,(uint16)PduInfoPtr->SduLength);       
    if (E_OK == ProcessStatus_o)
    {
        CheckResult_o = TRUE ;
    }
    else
    {
        CheckResult_o = FALSE;   
    }
    
        return CheckResult_o;  

 }
 boolean CC_ACAN_BCM_PEPS_Sts_E2E(PduIdType PduId, PduInfoType *PduInfoPtr)
 {

     Std_ReturnType ProcessStatus_o;                                            
    boolean CheckResult_o;                                                     
    (void)PduId;     
   
    ProcessStatus_o = LCE2ELib_Check_Last( PduInfoPtr->SduDataPtr,(uint16)PduInfoPtr->SduLength);       
    if (E_OK == ProcessStatus_o)
    {
        CheckResult_o = TRUE ;
    }
    else
    {
        CheckResult_o = FALSE;   
    }
    
        return CheckResult_o;  

 }
 boolean CC_ACAN_ESC_EPB_0x230_E2E(PduIdType PduId, PduInfoType *PduInfoPtr)
 {

     Std_ReturnType ProcessStatus_o;                                            
    boolean CheckResult_o;                                                     
    (void)PduId;     
   
    ProcessStatus_o = LCE2ELib_Check( PduInfoPtr->SduDataPtr,(uint16)PduInfoPtr->SduLength);       
    if (E_OK == ProcessStatus_o)
    {
        CheckResult_o = TRUE ;
    }
    else
    {
        CheckResult_o = FALSE;   
    }
    
        return CheckResult_o;  

 }
 boolean CC_ACAN_ESC_YawAngle_0x3E2_E2E(PduIdType PduId, PduInfoType *PduInfoPtr)
 {

     Std_ReturnType ProcessStatus_o;                                            
    boolean CheckResult_o;                                                     
    (void)PduId;     
   
    ProcessStatus_o = LCE2ELib_Check( PduInfoPtr->SduDataPtr,(uint16)PduInfoPtr->SduLength);       
    if (E_OK == ProcessStatus_o)
    {
        CheckResult_o = TRUE ;
    }
    else
    {
        CheckResult_o = FALSE;   
    }
    
        return CheckResult_o;  

 }
 boolean CC_ACAN_IPC_TotalOdometer_E2E(PduIdType PduId, PduInfoType *PduInfoPtr)
 {

     Std_ReturnType ProcessStatus_o;                                            
    boolean CheckResult_o;                                                     
    (void)PduId;     
   
    ProcessStatus_o = LCE2ELib_Check_Last( PduInfoPtr->SduDataPtr,(uint16)PduInfoPtr->SduLength);       
    if (E_OK == ProcessStatus_o)
    {
        CheckResult_o = TRUE ;
    }
    else
    {
        CheckResult_o = FALSE;   
    }
    
        return CheckResult_o;  

 }
 boolean CC_ACAN_MFS_L_Control_Button2_0x3F7_E2E(PduIdType PduId, PduInfoType *PduInfoPtr)
 {

     Std_ReturnType ProcessStatus_o;                                            
    boolean CheckResult_o;                                                     
    (void)PduId;     
   
    ProcessStatus_o = LCE2ELib_Check( PduInfoPtr->SduDataPtr,(uint16)PduInfoPtr->SduLength);       
    if (E_OK == ProcessStatus_o)
    {
        CheckResult_o = TRUE ;
    }
    else
    {
        CheckResult_o = FALSE;   
    }
    
        return CheckResult_o;  

 }
/* ********************************************************************************************************************
 * Variables
 ******************************************************************************************************************* */

boolean CC_ACAN_ADAS_01_E2E(PduIdType PduId, PduInfoType *PduInfoPtr)
{
      (void)PduId;                                                               
    (void)LCE2ELib_Protect_Low(&ComE2E_ProtectState_ACAN_ADAS_01,  PduInfoPtr->SduDataPtr, (uint16)PduInfoPtr->SduLength);                 
    return TRUE;                                                               
}
boolean CC_ACAN_ADAS_02_E2E(PduIdType PduId, PduInfoType *PduInfoPtr)
{
      (void)PduId;                                                               
    (void)LCE2ELib_Protect_Low(&ComE2E_ProtectState_ACAN_ADAS_02,  PduInfoPtr->SduDataPtr, (uint16)PduInfoPtr->SduLength);                 
    return TRUE;                                                               
}
boolean CC_ACAN_ADAS_03_E2E(PduIdType PduId, PduInfoType *PduInfoPtr)
{
      (void)PduId;                                                               
    (void)LCE2ELib_Protect( &ComE2E_ProtectState_ACAN_ADAS_03, PduInfoPtr->SduDataPtr, (uint16)PduInfoPtr->SduLength);                 
    return TRUE;                                                               
}
boolean CC_ACAN_ADAS_Info23_E2E(PduIdType PduId, PduInfoType *PduInfoPtr)
{
      (void)PduId;                                                               
    (void)LCE2ELib_Protect_Low( &ComE2E_ProtectState_ACAN_ADAS_Info23, PduInfoPtr->SduDataPtr, (uint16)PduInfoPtr->SduLength);                 
    return TRUE;                                                               
}
#endif



#if 1
boolean CC_ACAN_ACU_ChimeTelltaleReq_E2E(PduIdType PduId, PduInfoType *PduInfoPtr){}
boolean CC_ACAN_BCM_LIGHT_0x106_E2E(PduIdType PduId, PduInfoType *PduInfoPtr){}
boolean CC_ACAN_BCM_SwitchSts_0x109_E2E(PduIdType PduId, PduInfoType *PduInfoPtr){}
boolean CC_ACAN_ABS_FrontWheelSpeMCUKPH_E2E(PduIdType PduId, PduInfoType *PduInfoPtr){}
boolean CC_ACAN_ABS_RearWheelSpeMCUKPH_E2E(PduIdType PduId, PduInfoType *PduInfoPtr){}
boolean CC_ACAN_ABS_WheelSpeedRC_E2E(PduIdType PduId, PduInfoType *PduInfoPtr){}
boolean CC_ACAN_ABS_Status_E2E(PduIdType PduId, PduInfoType *PduInfoPtr){}
boolean CC_ACAN_ESC_Status_0x132_E2E(PduIdType PduId, PduInfoType *PduInfoPtr){}
boolean CC_ACAN_VCU_Ctrl_E2E(PduIdType PduId, PduInfoType *PduInfoPtr){}
boolean CC_ACAN_VCU_StsEpt_E2E(PduIdType PduId, PduInfoType *PduInfoPtr){}
boolean CC_ACAN_SAS_Sensor_0x17E_E2E(PduIdType PduId, PduInfoType *PduInfoPtr){}
boolean CC_ACAN_EPS_LKA_Sts_E2E(PduIdType PduId, PduInfoType *PduInfoPtr){}
boolean CC_ACAN_BCM_PEPS_Sts_E2E(PduIdType PduId, PduInfoType *PduInfoPtr){}
boolean CC_ACAN_ESC_EPB_0x230_E2E(PduIdType PduId, PduInfoType *PduInfoPtr){}
boolean CC_ACAN_ESC_YawAngle_0x3E2_E2E(PduIdType PduId, PduInfoType *PduInfoPtr){}
boolean CC_ACAN_IPC_TotalOdometer_E2E(PduIdType PduId, PduInfoType *PduInfoPtr){}
boolean CC_ACAN_MFS_L_Control_Button2_0x3F7_E2E(PduIdType PduId, PduInfoType *PduInfoPtr){}

//TX
boolean CC_ACAN_ADAS_01_E2E(PduIdType PduId, PduInfoType *PduInfoPtr){}
boolean CC_ACAN_ADAS_02_E2E(PduIdType PduId, PduInfoType *PduInfoPtr){}
boolean CC_ACAN_ADAS_03_E2E(PduIdType PduId, PduInfoType *PduInfoPtr){}
boolean CC_ACAN_ADAS_Info23_E2E(PduIdType PduId, PduInfoType *PduInfoPtr){}

#endif
/*
 * E2E Tx protect state variable declaration
 * Format CC_PROTECT_STATE({ipdu_shortname})
 */

