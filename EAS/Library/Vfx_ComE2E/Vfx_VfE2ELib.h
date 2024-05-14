/* ********************************************************************************************************************
 *
 * COPYRIGHT RESERVED, 2022 VinFast Trading and Production LLC. All rights reserved.
 * The reproduction, distribution and utilization of this document as well as the communication of its contents to
 * others without explicit authorization is prohibited. Offenders will be held liable for the payment of damages.
 * All rights reserved in the event of the grant of a patent, utility model or design.
 *
 ******************************************************************************************************************* */
#ifndef LCE2ELIB_INC_LCE2ELIB_H_
#define LCE2ELIB_INC_LCE2ELIB_H_

#ifdef __cplusplus
extern "C"
{
#endif

#ifdef __cplusplus
}
#endif

/* ********************************************************************************************************************
 * Files inclusion
 ******************************************************************************************************************* */
#include "Std_Types.h"

/* ********************************************************************************************************************
 * Macros definition
 ******************************************************************************************************************* */

/* Error: At least one pointer parameter is NULL    */
#define LCE2ELIB_INPUTERR_NULL 0x13u

/* Error: At least one input parameter is erroneous, e.g. out of range    */
#define LCE2ELIB_INPUTERR_WRONG 0x17u

/* Function completed successfully */
#define LCE2ELIB_OK 0x00u

/* ********************************************************************************************************************
 * Type definition
 ******************************************************************************************************************* */
typedef struct
{
    uint8 AlvCounter_u8; /* Counter to be used for protecting the next Data */
} LCE2ELib_ProtectStateType_tst;

typedef enum
{
    LCE2ELib_STATUS_OK_e,
    LCE2ELib_STATUS_WRONGCNT_e,
    LCE2ELib_STATUS_WRONGCRC_e
} LCE2ELib_CheckStatusType_ten;

typedef struct
{
    uint8 LastValidCounter_u8; /* Counter value most recently received */
    boolean WaitForFirstData_b; /* If true means that no correct Data has been received yet */
    LCE2ELib_CheckStatusType_ten Status_en; /* Result of the verification of the Data */
} LCE2ELib_CheckStateType_tst;


/* ********************************************************************************************************************
 * Function declaration
 ******************************************************************************************************************* */

/**********************************************************************************************************************
 *  E2E_P01Protect()
 *********************************************************************************************************************/
/*!
 * \brief           Protection function of E2Elib Vinfast Profile
 * \details         Protects the array/buffer to be transmitted using the Vinfast E2E Profile. This includes checksum
 *                  calculation and handling of counter.
 * \param[in,out]   LCE2ELib_ProtectStateType  Pointer to communication state
 * \param[in,out]   DataPtr_pu8   Pointer to data to be protected
 * \param[in]  		DataLen_u16   Length of data to be protected
 * \return          E2E_E_INPUTERR_NULL: A pointer parameter is NULL
 * \return          E2E_E_INPUTERR_WRONG: One parameter is erroneous
 * \return          E2E_E_INTERR: Internal library error
 * \return          E2E_E_OK: Protection successful
 * \pre             -
 * \reentrant       FALSE
 * \synchronous     TRUE
 */
Std_ReturnType LCE2ELib_Protect(LCE2ELib_ProtectStateType_tst *StatePtr_pst, uint8 *DataPtr_pu8,uint16 DataLen_u16);
Std_ReturnType LCE2ELib_Protect_Low(LCE2ELib_ProtectStateType_tst *StatePtr_pst,uint8 *DataPtr_pu8,uint16 DataLen_u16);
/**********************************************************************************************************************
 *  E2E_P01Check()
 *********************************************************************************************************************/
/*!
 * \brief           Check function of E2Elib Vinfast Profile
 * \details         Checks the data received using the Vinfast E2E Profile. This includes CRC calculation and handling
 *                  of the counter.
 * \param[in,out]   StatePtr_pst  Pointer to communication state
 * \param[in] DataPtr_pcu8 Pointer to data to be checked
 * \param[in]  		DataLen_u16   Length of data to be checked
 * \return          E2E_E_INPUTERR_NULL: A pointer parameter is NULL
 * \return          E2E_E_INPUTERR_WRONG: One parameter is erroneous
 * \return          E2E_E_INTERR: Internal library error
 * \return          E2E_E_OK: Check successful
 * \pre             -
 * \reentrant       FALSE
 * \synchronous     TRUE
 */
Std_ReturnType LCE2ELib_Check( const uint8 *DataPtr_pcu8,uint16 DataLen_u16);

Std_ReturnType LCE2ELib_Check_Last( const uint8 *DataPtr_pcu8,uint16 DataLen_u16);

Std_ReturnType LCE2ELib_Check1( const uint8 *DataPtr_pcu8,uint16 DataLen_u16);

Std_ReturnType LCE2ELib_Check_Last1( const uint8 *DataPtr_pcu8,uint16 DataLen_u16);
#endif /* LCE2ELIB_INC_LCE2ELIB_H_ */
