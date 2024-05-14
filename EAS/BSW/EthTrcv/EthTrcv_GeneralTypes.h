/*EthTrcv_GeneralTypes.h
Created on: 2020.3.30
	Author: peng.tian
*/
#ifndef _ETHTRCV_GENERALTYPES_H_
#define _ETHTRCV_GENERALTYPES_H_

#include "ComStack_Types.h"

/**
* @brief          Ethernet Transceiver's state.
* @details        This type defines the transceiver modes
* @implements     EthTrcv_ModeType_enumeration
*/
typedef enum
{
    ETHTRCV_MODE_DOWN = 0,  /**< Transceiver disabled */
    ETHTRCV_MODE_ACTIVE     /**< Transceiver enabled */
} EthTrcv_ModeType;

/**
* @brief          Ethernet Transceiver's speed grade
* @details        This type defines the Ethernet baud rate. The baud rate gets either negotiated
                  between the connected transceivers or has to be configured.
* @implements     EthTrcv_BaudRateType_enumeration
*/
typedef enum
{
    ETHTRCV_STATE_UNINIT = 0,     /**< Driver is not yet configured */
    ETHTRCV_STATE_INIT
} EthTrcv_StateType;

/**
* @brief          Ethernet Transceiver's device master/slave setting
* @details        This type defines the transceiver master slave mode
* @implements     EthTrcv_MasterSlaveType_enumeration
*/
typedef enum
{
  ETHTRCV_SLAVE = 0,
  ETHTRCV_MASTER,
} EthTrcv_MasterSlaveType;

/**
* @brief          Ethernet Transceiver's Link state.
* @details        This type defines the Ethernet link state. The link state changes after an
*                 Ethernet cable gets plugged in and the transceivers on both ends negotiated
*                 the transmission parameters (i.e. baud rate and duplex mode)
* @implements     EthTrcv_LinkStateType_enumeration
*/
typedef enum
{
    ETHTRCV_LINK_STATE_DOWN = 0,  /**< No physical Ethernet connection established */
    ETHTRCV_LINK_STATE_ACTIVE     /**< Physical Ethernet connection established */
} EthTrcv_LinkStateType;

/**
* @brief          Ethernet Transceiver's speed grade
* @details        This type defines the Ethernet baud rate. The baud rate gets either negotiated
                  between the connected transceivers or has to be configured.
* @implements     EthTrcv_BaudRateType_enumeration
*/
typedef enum
{
    ETHTRCV_BAUD_RATE_10MBIT = 0, /**< 10MBIT Ethernet connection */
    ETHTRCV_BAUD_RATE_100MBIT,    /**< 100MBIT Ethernet connection */
    ETHTRCV_BAUD_RATE_1000MBIT    /**< 1000MBIT Ethernet connection */
}  EthTrcv_BaudRateType;

/**
* @brief          Result of cable diagnostic.
* @details        Describes the results of the cable diagnostics.
* @implements     EthTrcv_CableDiagResultType_enumeration
*/
typedef enum
{
    ETHTRCV_CABLEDIAG_OK = 0,     /**< Cable diagnostic ok */
    ETHTRCV_CABLEDIAG_ERROR,      /**< Cable diagnostic failed */
    ETHTRCV_CABLEDIAG_SHORT,      /**< Short circuit detected */
    ETHTRCV_CABLEDIAG_OPEN,       /**< Open circuit detected */
    ETHTRCV_CABLEDIAG_PENDING,    /**< cable diagnostic is still running */
    ETHTRCV_CABLEDIAG_WRONG_POLARITY  /**< cable diagnostics has detected wrong polarity */
} EthTrcv_CableDiagResultType;

/**
* @brief          Ethernet PHY transmit mode.
* @details        Describes the possible PHY transmit modes
* @implements     EthTrcv_PhyTxModeType_enumeration
*/
typedef enum
{
    ETHTRCV_PHYTXMODE_NORMAL = 0,   /**< normal operation */
    ETHTRCV_PHYTXMODE_TX_OFF,       /**< transmitter disabled */
    ETHTRCV_PHYTXMODE_SCRAMBLER_OFF /**< scrambler disabled */
} EthTrcv_PhyTxModeType;

/**
* @brief          Ethernet PHY loopback mode.
* @details        Describes the possible PHY loopback modes
* @implements     EthTrcv_PhyLoopbackModeType_enumeration
*/
typedef enum
{
    ETHTRCV_PHYLOOPBACK_NONE = 0,   /**< normal operation */
    ETHTRCV_PHYLOOPBACK_INTERNAL,   /**< internal loopback */
    ETHTRCV_PHYLOOPBACK_EXTERNAL,   /**< external loopback */
    ETHTRCV_PHYLOOPBACK_REMOTE      /**< remote loopback */
} EthTrcv_PhyLoopbackModeType;

/**
* @brief          Ethernet PHY test mode.
* @details        Describes the possible PHY test modes
* @implements     EthTrcv_PhyTestModeType_enumeration
*/
typedef enum
{
    ETHTRCV_PHYTESTMODE_NONE = 0,   /**< normal operation */
    ETHTRCV_PHYTESTMODE_1,          /**< test transmitter droop */
    ETHTRCV_PHYTESTMODE_2,          /**< test master timing jitter */
    ETHTRCV_PHYTESTMODE_3,          /**< test slave timing jitter */
    ETHTRCV_PHYTESTMODE_4,          /**< test transmitter distortion */
    ETHTRCV_PHYTESTMODE_5           /**< test power spectral density (PSD) mask */
} EthTrcv_PhyTestModeType;

/**
* @brief          Ethernet PHY wake up reason.
* @details        This type defines the transceiver wake up reasons.
* @implements     EthTrcv_WakeupReasonType_enumeration
*/
typedef enum
{
    ETHTRCV_WUR_NONE = 0,   /**< No wake up reason detected. */
    ETHTRCV_WUR_GENERAL,    /**< General wake up detected, no distinct reason supported by hardware. */
    ETHTRCV_WUR_BUS,        /**< Bus wake up detected. Available if supported by hardware. */
    ETHTRCV_WUR_INTERNAL,   /**< Internal wake up detected. Available if supported by hardware. */
    ETHTRCV_WUR_RESET,      /**< Reset wake up detected. Available if supported by hardware. */
    ETHTRCV_WUR_POWER_ON,   /**< Power on wake up detected. Available if supported by hardware. */
    ETHTRCV_WUR_PIN,        /**< Pin wake up detected. Available if supported by hardware. */
    ETHTRCV_WUR_SYSERR      /**< System error wake up detected. Available if supported by hardware. */
} EthTrcv_WakeupReasonType;

/**
* @brief          Ethernet PHY wake up mode.
* @details        This type controls the transceiver wake up modes and/or clears the wake-up reason.
* @implements     EthTrcv_WakeupModeType_enumeration
*/
typedef enum
{
    ETHTRCV_WUM_DISABLE = 0,  /**< Transceiver wake up disabled */
    ETHTRCV_WUM_ENABLE,       /**< Transceiver wake up enabled */
    ETHTRCV_WUM_CLEAR         /**< Transceiver wake up reason cleared. */
} EthTrcv_WakeupModeType;

/**
* @brief          Ethernet PHY duplex mode.
* @details        This type defines the Ethernet duplex mode. The duplex mode gets either negotiated
                  between the connected transceivers or has to be configured.
* @implements     EthTrcv_DuplexModeType_enumeration
*/
typedef enum
{
    ETHTRCV_DUPLEX_MODE_HALF = 0,   /**< Half duplex Ethernet connection */
    ETHTRCV_DUPLEX_MODE_FULL        /**< Full duplex Ethernet connection */
} EthTrcv_DuplexModeType;

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
#endif/* ETHTRCV_GENERALTYPES_H */

