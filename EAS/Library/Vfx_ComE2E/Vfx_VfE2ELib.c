/*-----------------------------------------------------------------------------
 * Copyright (c) 2022 VinFast Trading and Production LLC. All rights reserved.
 * The reproduction, distribution and utilization of this document as well as 
 * the communication of its contents to others without explicit authorization 
 * is prohibited. Offenders will be held liable for the payment of damages. 
 * All rights reserved in the event of the grant of a patent, utility model or 
 * design.
-----------------------------------------------------------------------------*/
/**
*   @file LCE2ELib.c
*
*   @brief E2E library
*
*   @author Vinfast
*
*   @copyright Copyright (c) 2022.
*
*   @note Note 
*
*/
/*-----------------------------------------------------------------------------
*   MODIFICATION HISTORY:
*
*   Ver     PIC       Date             Changes
*   -----   --------   ----------   -------------------------------------------
*   1.00    ThanhNH40 25-02-2022       Initial
* 
-----------------------------------------------------------------------------*/

/* ********************************************************************************************************************
 * Files inclusion
 ******************************************************************************************************************* */

#include "Vfx_VfE2ELib.h"
#include "Crc.h"

/* ********************************************************************************************************************
 * Internal Macros
 ******************************************************************************************************************* */
#define LCE2ELIB_MAX_COUNTER_VALUE 14u
#define LCE2ELIB_MIN_PDU_LEN 1u
#define LCE2ELIB_CHECK_SUM_BYTE_POS 0u
#define LCE2ELIB_ALIVE_CNT_BYTE_POS 1u

#define LCE2ELIB_LOW_NIBBLE_BYTE_MASK 0x0Fu
#define LCE2ELIB_HIGH_NIBBLE_BYTE_MASK 0xF0u


#define LCE2ELIB_ALIVE_CNT_BYTE_6B 6u
#define LCE2ELIB_CHECK_SUM_BYTE_7B 7u
/* ********************************************************************************************************************
 * Static function declaration
 ******************************************************************************************************************* */

/* ********************************************************************************************************************
 * Variables
 ******************************************************************************************************************* */

/* ********************************************************************************************************************
 * Static function definition
 ******************************************************************************************************************* */

/* ********************************************************************************************************************
 * Public function definition
 ******************************************************************************************************************* */
Std_ReturnType LCE2ELib_Protect(LCE2ELib_ProtectStateType_tst *StatePtr_pst,uint8 *DataPtr_pu8,uint16 DataLen_u16)
{
    Std_ReturnType ProcessStatus_o;
    uint8 ComputedCRC_u8;

    /* Validate input parameter */
    if ((StatePtr_pst != NULL_PTR) && (DataPtr_pu8 != NULL_PTR))
    {
        if ((StatePtr_pst->AlvCounter_u8 <= LCE2ELIB_MAX_COUNTER_VALUE)
                && (DataLen_u16 >= LCE2ELIB_MIN_PDU_LEN))
        {
            /* Calculate and set Alive counter */
            DataPtr_pu8[LCE2ELIB_ALIVE_CNT_BYTE_POS] = (DataPtr_pu8[LCE2ELIB_ALIVE_CNT_BYTE_POS]
                    & LCE2ELIB_HIGH_NIBBLE_BYTE_MASK) | StatePtr_pst->AlvCounter_u8;
            /* Calculate and set checksum */
            ComputedCRC_u8 = 0u;
            ComputedCRC_u8 = Crc_CalculateCRC8(&DataPtr_pu8[LCE2ELIB_CHECK_SUM_BYTE_POS + 1u], (uint32)DataLen_u16 - 1u,
                    ComputedCRC_u8, FALSE);
            DataPtr_pu8[LCE2ELIB_CHECK_SUM_BYTE_POS] = ComputedCRC_u8;

            /*Increment value of Counter. Valid values are 0..14 */
            StatePtr_pst->AlvCounter_u8 = (StatePtr_pst->AlvCounter_u8 + 1u) % (LCE2ELIB_MAX_COUNTER_VALUE + 1u);

            /* Set status of protect completion */
            ProcessStatus_o = LCE2ELIB_OK;
        }
        else
        {
            ProcessStatus_o = LCE2ELIB_INPUTERR_WRONG;
        }
    }
    else
    {
        ProcessStatus_o = LCE2ELIB_INPUTERR_NULL;
    }

    return ProcessStatus_o;
}
Std_ReturnType LCE2ELib_Protect_Low(LCE2ELib_ProtectStateType_tst *StatePtr_pst,uint8 *DataPtr_pu8,uint16 DataLen_u16)
{
    Std_ReturnType ProcessStatus_o;
    uint8 ComputedCRC_u8;

    /* Validate input parameter */
    if ((StatePtr_pst != NULL_PTR) && (DataPtr_pu8 != NULL_PTR))
    {
        if ((StatePtr_pst->AlvCounter_u8 <= LCE2ELIB_MAX_COUNTER_VALUE)
                && (DataLen_u16 >= LCE2ELIB_MIN_PDU_LEN))
        {
            /* Calculate and set Alive counter */
            DataPtr_pu8[LCE2ELIB_ALIVE_CNT_BYTE_POS] = (DataPtr_pu8[LCE2ELIB_ALIVE_CNT_BYTE_POS]
                    & LCE2ELIB_LOW_NIBBLE_BYTE_MASK) | StatePtr_pst->AlvCounter_u8;
            /* Calculate and set checksum */
            ComputedCRC_u8 = 0u;
            ComputedCRC_u8 = Crc_CalculateCRC8(&DataPtr_pu8[LCE2ELIB_CHECK_SUM_BYTE_POS + 1u], (uint32)DataLen_u16 - 1u,
                    ComputedCRC_u8, FALSE);
            DataPtr_pu8[LCE2ELIB_CHECK_SUM_BYTE_POS] = ComputedCRC_u8;

            /*Increment value of Counter. Valid values are 0..14 */
            StatePtr_pst->AlvCounter_u8 = (StatePtr_pst->AlvCounter_u8 + 1u) % (LCE2ELIB_MAX_COUNTER_VALUE + 1u);

            /* Set status of protect completion */
            ProcessStatus_o = LCE2ELIB_OK;
        }
        else
        {
            ProcessStatus_o = LCE2ELIB_INPUTERR_WRONG;
        }
    }
    else
    {
        ProcessStatus_o = LCE2ELIB_INPUTERR_NULL;
    }

    return ProcessStatus_o;
}
Std_ReturnType LCE2ELib_Check( const uint8 *DataPtr_pcu8, uint16 DataLen_u16)
{
    uint8 ReceivedCounter_u8;
    uint8 ComputedCRC_u8;
    uint8 ReceivedCRC_u8;
    Std_ReturnType ProcessStatus_o;

    /* Validate input parameter */
    if (DataPtr_pcu8 != NULL_PTR)
    {
        if (DataLen_u16 >= LCE2ELIB_MIN_PDU_LEN)
        {
            /* Looking for received alive counter */
            ReceivedCounter_u8 = DataPtr_pcu8[LCE2ELIB_ALIVE_CNT_BYTE_POS] & LCE2ELIB_LOW_NIBBLE_BYTE_MASK;

            /* Verify receive counter and checksum */
            if (ReceivedCounter_u8 <= LCE2ELIB_MAX_COUNTER_VALUE)
            {
                ReceivedCRC_u8 = DataPtr_pcu8[LCE2ELIB_CHECK_SUM_BYTE_POS];
                ComputedCRC_u8 = 0u;
                ComputedCRC_u8 = Crc_CalculateCRC8(&DataPtr_pcu8[LCE2ELIB_CHECK_SUM_BYTE_POS + 1u],
                        (uint32)DataLen_u16 - 1u, ComputedCRC_u8, FALSE);

                /* CRC is correct, check alive counter */
                if (ReceivedCRC_u8 == ComputedCRC_u8)
                {
                     ProcessStatus_o = E_OK;
                }
                else
                {
                     ProcessStatus_o = E_NOT_OK;
                }
            }
            else
            {
                 ProcessStatus_o = E_NOT_OK;
            }

            
        }
        else
        {
            ProcessStatus_o = E_NOT_OK;
        }
    }
    else
    {
        ProcessStatus_o = E_NOT_OK;
    }

    return ProcessStatus_o;
}

Std_ReturnType LCE2ELib_Check1( const uint8 *DataPtr_pcu8, uint16 DataLen_u16)
{
    uint8 ReceivedCounter_u8;
    uint8 ComputedCRC_u8;
    uint8 ReceivedCRC_u8;
    Std_ReturnType ProcessStatus_o;

    /* Validate input parameter */
    if (DataPtr_pcu8 != NULL_PTR)
    {
        if (DataLen_u16 >= LCE2ELIB_MIN_PDU_LEN)
        {
            /* Looking for received alive counter */
            ReceivedCounter_u8 =( DataPtr_pcu8[LCE2ELIB_ALIVE_CNT_BYTE_POS]>>4) & LCE2ELIB_LOW_NIBBLE_BYTE_MASK;

            /* Verify receive counter and checksum */
            if (ReceivedCounter_u8 <= LCE2ELIB_MAX_COUNTER_VALUE)
            {
                ReceivedCRC_u8 = DataPtr_pcu8[LCE2ELIB_CHECK_SUM_BYTE_POS];
                ComputedCRC_u8 = 0u;
                ComputedCRC_u8 = Crc_CalculateCRC8(&DataPtr_pcu8[LCE2ELIB_CHECK_SUM_BYTE_POS + 1u],
                        (uint32)DataLen_u16 - 1u, ComputedCRC_u8, FALSE);

                /* CRC is correct, check alive counter */
                if (ReceivedCRC_u8 == ComputedCRC_u8)
                {
                     ProcessStatus_o = E_OK;
                }
                else
                {
                     ProcessStatus_o = E_NOT_OK;
                }
            }
            else
            {
                 ProcessStatus_o = E_NOT_OK;
            }

            
        }
        else
        {
            ProcessStatus_o = E_NOT_OK;
        }
    }
    else
    {
        ProcessStatus_o = E_NOT_OK;
    }

    return ProcessStatus_o;
}

Std_ReturnType LCE2ELib_Check_Last( const uint8 *DataPtr_pcu8, uint16 DataLen_u16)
{
    uint8 ReceivedCounter_u8;
    uint8 ComputedCRC_u8;
    uint8 ReceivedCRC_u8;
    Std_ReturnType ProcessStatus_o;

    /* Validate input parameter */
    if (DataPtr_pcu8 != NULL_PTR)
    {
        if (DataLen_u16 >= LCE2ELIB_MIN_PDU_LEN)
        {
            /* Looking for received alive counter */
            ReceivedCounter_u8 = DataPtr_pcu8[LCE2ELIB_ALIVE_CNT_BYTE_6B] & LCE2ELIB_LOW_NIBBLE_BYTE_MASK;

            /* Verify receive counter and checksum */
            if (ReceivedCounter_u8 <= LCE2ELIB_MAX_COUNTER_VALUE)
            {
                ReceivedCRC_u8 = DataPtr_pcu8[LCE2ELIB_CHECK_SUM_BYTE_7B];
                ComputedCRC_u8 = 0u;
                ComputedCRC_u8 = Crc_CalculateCRC8(&DataPtr_pcu8[0],
                        (uint32)DataLen_u16 - 1u, ComputedCRC_u8, FALSE);

                /* CRC is correct, check alive counter */
                if (ReceivedCRC_u8 == ComputedCRC_u8)
                {
                     ProcessStatus_o = E_OK;
                }
                else
                {
                     ProcessStatus_o = E_NOT_OK;
                }
            }
            else
            {
                 ProcessStatus_o = E_NOT_OK;
            }

            
        }
        else
        {
            ProcessStatus_o = E_NOT_OK;
        }
    }
    else
    {
        ProcessStatus_o = E_NOT_OK;
    }

    return ProcessStatus_o;
}
Std_ReturnType LCE2ELib_Check_Last1( const uint8 *DataPtr_pcu8, uint16 DataLen_u16)
{
    uint8 ReceivedCounter_u8;
    uint8 ComputedCRC_u8;
    uint8 ReceivedCRC_u8;
    Std_ReturnType ProcessStatus_o;

    /* Validate input parameter */
    if (DataPtr_pcu8 != NULL_PTR)
    {
        if (DataLen_u16 >= LCE2ELIB_MIN_PDU_LEN)
        {
            /* Looking for received alive counter */
            ReceivedCounter_u8 = (DataPtr_pcu8[LCE2ELIB_ALIVE_CNT_BYTE_6B]>>4) & LCE2ELIB_LOW_NIBBLE_BYTE_MASK;

            /* Verify receive counter and checksum */
            if (ReceivedCounter_u8 <= LCE2ELIB_MAX_COUNTER_VALUE)
            {
                ReceivedCRC_u8 = DataPtr_pcu8[LCE2ELIB_CHECK_SUM_BYTE_7B];
                ComputedCRC_u8 = 0u;
                ComputedCRC_u8 = Crc_CalculateCRC8(&DataPtr_pcu8[0],
                        (uint32)DataLen_u16 - 1u, ComputedCRC_u8, FALSE);

                /* CRC is correct, check alive counter */
                if (ReceivedCRC_u8 == ComputedCRC_u8)
                {
                     ProcessStatus_o = E_OK;
                }
                else
                {
                     ProcessStatus_o = E_NOT_OK;
                }
            }
            else
            {
                 ProcessStatus_o = E_NOT_OK;
            }

            
        }
        else
        {
            ProcessStatus_o = E_NOT_OK;
        }
    }
    else
    {
        ProcessStatus_o = E_NOT_OK;
    }

    return ProcessStatus_o;
}