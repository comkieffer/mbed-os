/*
** ###################################################################
**     Compilers:           Keil ARM C/C++ Compiler
**                          Freescale C/C++ for Embedded ARM
**                          GNU C Compiler
**                          IAR ANSI C/C++ Compiler for ARM
**
**     Reference manual:    K22P121M100SF9RM, Rev. 1, April 25, 2014
**     Version:             rev. 1.3, 2014-05-06
**     Build:               b140604
**
**     Abstract:
**         Extension to the CMSIS register access layer header.
**
**     Copyright (c) 2014 Freescale Semiconductor, Inc.
**     All rights reserved.
**
**     Redistribution and use in source and binary forms, with or without modification,
**     are permitted provided that the following conditions are met:
**
**     o Redistributions of source code must retain the above copyright notice, this list
**       of conditions and the following disclaimer.
**
**     o Redistributions in binary form must reproduce the above copyright notice, this
**       list of conditions and the following disclaimer in the documentation and/or
**       other materials provided with the distribution.
**
**     o Neither the name of Freescale Semiconductor, Inc. nor the names of its
**       contributors may be used to endorse or promote products derived from this
**       software without specific prior written permission.
**
**     THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
**     ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
**     WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
**     DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
**     ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
**     (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
**     LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
**     ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
**     (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
**     SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
**
**     http:                 www.freescale.com
**     mail:                 support@freescale.com
**
**     Revisions:
**     - rev. 1.0 (2013-11-01)
**         Initial version.
**     - rev. 1.1 (2013-12-20)
**         Update according to reference manual rev. 0.1,
**     - rev. 1.2 (2014-02-10)
**         The declaration of clock configurations has been moved to separate header file system_MK22F12810.h
**     - rev. 1.3 (2014-05-06)
**         Update according to reference manual rev. 1.0,
**         Update of system and startup files.
**         Module access macro module_BASES replaced by module_BASE_PTRS.
**
** ###################################################################
*/

/*
 * WARNING! DO NOT EDIT THIS FILE DIRECTLY!
 *
 * This file was generated automatically and any changes may be lost.
 */
#ifndef __HW_PORT_REGISTERS_H__
#define __HW_PORT_REGISTERS_H__

#include "MK22F12810.h"
#include "fsl_bitaccess.h"

/*
 * MK22F12810 PORT
 *
 * Pin Control and Interrupts
 *
 * Registers defined in this header file:
 * - HW_PORT_PCRn - Pin Control Register n
 * - HW_PORT_GPCLR - Global Pin Control Low Register
 * - HW_PORT_GPCHR - Global Pin Control High Register
 * - HW_PORT_ISFR - Interrupt Status Flag Register
 * - HW_PORT_DFER - Digital Filter Enable Register
 * - HW_PORT_DFCR - Digital Filter Clock Register
 * - HW_PORT_DFWR - Digital Filter Width Register
 *
 * - hw_port_t - Struct containing all module registers.
 */

#define HW_PORT_INSTANCE_COUNT (5U) /*!< Number of instances of the PORT module. */
#define HW_PORTA (0U) /*!< Instance number for PORTA. */
#define HW_PORTB (1U) /*!< Instance number for PORTB. */
#define HW_PORTC (2U) /*!< Instance number for PORTC. */
#define HW_PORTD (3U) /*!< Instance number for PORTD. */
#define HW_PORTE (4U) /*!< Instance number for PORTE. */

/*******************************************************************************
 * HW_PORT_PCRn - Pin Control Register n
 ******************************************************************************/

/*!
 * @brief HW_PORT_PCRn - Pin Control Register n (RW)
 *
 * Reset value: 0x00000702U
 *
 * See the Signal Multiplexing and Pin Assignment chapter for the reset value of
 * this device. See the GPIO Configuration section for details on the available
 * functions for each pin. Do not modify pin configuration registers associated
 * with pins not available in your selected package. All unbonded pins not
 * available in your package will default to DISABLE state for lowest power consumption.
 */
typedef union _hw_port_pcrn
{
    uint32_t U;
    struct _hw_port_pcrn_bitfields
    {
        uint32_t PS : 1;               /*!< [0] Pull Select */
        uint32_t PE : 1;               /*!< [1] Pull Enable */
        uint32_t SRE : 1;              /*!< [2] Slew Rate Enable */
        uint32_t RESERVED0 : 1;        /*!< [3]  */
        uint32_t PFE : 1;              /*!< [4] Passive Filter Enable */
        uint32_t ODE : 1;              /*!< [5] Open Drain Enable */
        uint32_t DSE : 1;              /*!< [6] Drive Strength Enable */
        uint32_t RESERVED1 : 1;        /*!< [7]  */
        uint32_t MUX : 3;              /*!< [10:8] Pin Mux Control */
        uint32_t RESERVED2 : 4;        /*!< [14:11]  */
        uint32_t LK : 1;               /*!< [15] Lock Register */
        uint32_t IRQC : 4;             /*!< [19:16] Interrupt Configuration */
        uint32_t RESERVED3 : 4;        /*!< [23:20]  */
        uint32_t ISF : 1;              /*!< [24] Interrupt Status Flag */
        uint32_t RESERVED4 : 7;        /*!< [31:25]  */
    } B;
} hw_port_pcrn_t;

/*!
 * @name Constants and macros for entire PORT_PCRn register
 */
/*@{*/
#define HW_PORT_PCRn_COUNT (32U)

#define HW_PORT_PCRn_ADDR(x, n)  ((x) + 0x0U + (0x4U * (n)))

#define HW_PORT_PCRn(x, n)       (*(__IO hw_port_pcrn_t *) HW_PORT_PCRn_ADDR(x, n))
#define HW_PORT_PCRn_RD(x, n)    (HW_PORT_PCRn(x, n).U)
#define HW_PORT_PCRn_WR(x, n, v) (HW_PORT_PCRn(x, n).U = (v))
#define HW_PORT_PCRn_SET(x, n, v) (HW_PORT_PCRn_WR(x, n, HW_PORT_PCRn_RD(x, n) |  (v)))
#define HW_PORT_PCRn_CLR(x, n, v) (HW_PORT_PCRn_WR(x, n, HW_PORT_PCRn_RD(x, n) & ~(v)))
#define HW_PORT_PCRn_TOG(x, n, v) (HW_PORT_PCRn_WR(x, n, HW_PORT_PCRn_RD(x, n) ^  (v)))
/*@}*/

/*
 * Constants & macros for individual PORT_PCRn bitfields
 */

/*!
 * @name Register PORT_PCRn, field PS[0] (RW)
 *
 * Pull configuration is valid in all digital pin muxing modes.
 *
 * Values:
 * - 0 - Internal pulldown resistor is enabled on the corresponding pin, if the
 *     corresponding PE field is set.
 * - 1 - Internal pullup resistor is enabled on the corresponding pin, if the
 *     corresponding PE field is set.
 */
/*@{*/
#define BP_PORT_PCRn_PS      (0U)          /*!< Bit position for PORT_PCRn_PS. */
#define BM_PORT_PCRn_PS      (0x00000001U) /*!< Bit mask for PORT_PCRn_PS. */
#define BS_PORT_PCRn_PS      (1U)          /*!< Bit field size in bits for PORT_PCRn_PS. */

/*! @brief Read current value of the PORT_PCRn_PS field. */
#define BR_PORT_PCRn_PS(x, n) (BITBAND_ACCESS32(HW_PORT_PCRn_ADDR(x, n), BP_PORT_PCRn_PS))

/*! @brief Format value for bitfield PORT_PCRn_PS. */
#define BF_PORT_PCRn_PS(v)   ((uint32_t)((uint32_t)(v) << BP_PORT_PCRn_PS) & BM_PORT_PCRn_PS)

/*! @brief Set the PS field to a new value. */
#define BW_PORT_PCRn_PS(x, n, v) (BITBAND_ACCESS32(HW_PORT_PCRn_ADDR(x, n), BP_PORT_PCRn_PS) = (v))
/*@}*/

/*!
 * @name Register PORT_PCRn, field PE[1] (RW)
 *
 * Pull configuration is valid in all digital pin muxing modes.
 *
 * Values:
 * - 0 - Internal pullup or pulldown resistor is not enabled on the
 *     corresponding pin.
 * - 1 - Internal pullup or pulldown resistor is enabled on the corresponding
 *     pin, if the pin is configured as a digital input.
 */
/*@{*/
#define BP_PORT_PCRn_PE      (1U)          /*!< Bit position for PORT_PCRn_PE. */
#define BM_PORT_PCRn_PE      (0x00000002U) /*!< Bit mask for PORT_PCRn_PE. */
#define BS_PORT_PCRn_PE      (1U)          /*!< Bit field size in bits for PORT_PCRn_PE. */

/*! @brief Read current value of the PORT_PCRn_PE field. */
#define BR_PORT_PCRn_PE(x, n) (BITBAND_ACCESS32(HW_PORT_PCRn_ADDR(x, n), BP_PORT_PCRn_PE))

/*! @brief Format value for bitfield PORT_PCRn_PE. */
#define BF_PORT_PCRn_PE(v)   ((uint32_t)((uint32_t)(v) << BP_PORT_PCRn_PE) & BM_PORT_PCRn_PE)

/*! @brief Set the PE field to a new value. */
#define BW_PORT_PCRn_PE(x, n, v) (BITBAND_ACCESS32(HW_PORT_PCRn_ADDR(x, n), BP_PORT_PCRn_PE) = (v))
/*@}*/

/*!
 * @name Register PORT_PCRn, field SRE[2] (RW)
 *
 * Slew rate configuration is valid in all digital pin muxing modes.
 *
 * Values:
 * - 0 - Fast slew rate is configured on the corresponding pin, if the pin is
 *     configured as a digital output.
 * - 1 - Slow slew rate is configured on the corresponding pin, if the pin is
 *     configured as a digital output.
 */
/*@{*/
#define BP_PORT_PCRn_SRE     (2U)          /*!< Bit position for PORT_PCRn_SRE. */
#define BM_PORT_PCRn_SRE     (0x00000004U) /*!< Bit mask for PORT_PCRn_SRE. */
#define BS_PORT_PCRn_SRE     (1U)          /*!< Bit field size in bits for PORT_PCRn_SRE. */

/*! @brief Read current value of the PORT_PCRn_SRE field. */
#define BR_PORT_PCRn_SRE(x, n) (BITBAND_ACCESS32(HW_PORT_PCRn_ADDR(x, n), BP_PORT_PCRn_SRE))

/*! @brief Format value for bitfield PORT_PCRn_SRE. */
#define BF_PORT_PCRn_SRE(v)  ((uint32_t)((uint32_t)(v) << BP_PORT_PCRn_SRE) & BM_PORT_PCRn_SRE)

/*! @brief Set the SRE field to a new value. */
#define BW_PORT_PCRn_SRE(x, n, v) (BITBAND_ACCESS32(HW_PORT_PCRn_ADDR(x, n), BP_PORT_PCRn_SRE) = (v))
/*@}*/

/*!
 * @name Register PORT_PCRn, field PFE[4] (RW)
 *
 * Passive filter configuration is valid in all digital pin muxing modes.
 *
 * Values:
 * - 0 - Passive input filter is disabled on the corresponding pin.
 * - 1 - Passive input filter is enabled on the corresponding pin, if the pin is
 *     configured as a digital input. Refer to the device data sheet for filter
 *     characteristics.
 */
/*@{*/
#define BP_PORT_PCRn_PFE     (4U)          /*!< Bit position for PORT_PCRn_PFE. */
#define BM_PORT_PCRn_PFE     (0x00000010U) /*!< Bit mask for PORT_PCRn_PFE. */
#define BS_PORT_PCRn_PFE     (1U)          /*!< Bit field size in bits for PORT_PCRn_PFE. */

/*! @brief Read current value of the PORT_PCRn_PFE field. */
#define BR_PORT_PCRn_PFE(x, n) (BITBAND_ACCESS32(HW_PORT_PCRn_ADDR(x, n), BP_PORT_PCRn_PFE))

/*! @brief Format value for bitfield PORT_PCRn_PFE. */
#define BF_PORT_PCRn_PFE(v)  ((uint32_t)((uint32_t)(v) << BP_PORT_PCRn_PFE) & BM_PORT_PCRn_PFE)

/*! @brief Set the PFE field to a new value. */
#define BW_PORT_PCRn_PFE(x, n, v) (BITBAND_ACCESS32(HW_PORT_PCRn_ADDR(x, n), BP_PORT_PCRn_PFE) = (v))
/*@}*/

/*!
 * @name Register PORT_PCRn, field ODE[5] (RW)
 *
 * Open drain configuration is valid in all digital pin muxing modes.
 *
 * Values:
 * - 0 - Open drain output is disabled on the corresponding pin.
 * - 1 - Open drain output is enabled on the corresponding pin, if the pin is
 *     configured as a digital output.
 */
/*@{*/
#define BP_PORT_PCRn_ODE     (5U)          /*!< Bit position for PORT_PCRn_ODE. */
#define BM_PORT_PCRn_ODE     (0x00000020U) /*!< Bit mask for PORT_PCRn_ODE. */
#define BS_PORT_PCRn_ODE     (1U)          /*!< Bit field size in bits for PORT_PCRn_ODE. */

/*! @brief Read current value of the PORT_PCRn_ODE field. */
#define BR_PORT_PCRn_ODE(x, n) (BITBAND_ACCESS32(HW_PORT_PCRn_ADDR(x, n), BP_PORT_PCRn_ODE))

/*! @brief Format value for bitfield PORT_PCRn_ODE. */
#define BF_PORT_PCRn_ODE(v)  ((uint32_t)((uint32_t)(v) << BP_PORT_PCRn_ODE) & BM_PORT_PCRn_ODE)

/*! @brief Set the ODE field to a new value. */
#define BW_PORT_PCRn_ODE(x, n, v) (BITBAND_ACCESS32(HW_PORT_PCRn_ADDR(x, n), BP_PORT_PCRn_ODE) = (v))
/*@}*/

/*!
 * @name Register PORT_PCRn, field DSE[6] (RW)
 *
 * Drive strength configuration is valid in all digital pin muxing modes.
 *
 * Values:
 * - 0 - Low drive strength is configured on the corresponding pin, if pin is
 *     configured as a digital output.
 * - 1 - High drive strength is configured on the corresponding pin, if pin is
 *     configured as a digital output.
 */
/*@{*/
#define BP_PORT_PCRn_DSE     (6U)          /*!< Bit position for PORT_PCRn_DSE. */
#define BM_PORT_PCRn_DSE     (0x00000040U) /*!< Bit mask for PORT_PCRn_DSE. */
#define BS_PORT_PCRn_DSE     (1U)          /*!< Bit field size in bits for PORT_PCRn_DSE. */

/*! @brief Read current value of the PORT_PCRn_DSE field. */
#define BR_PORT_PCRn_DSE(x, n) (BITBAND_ACCESS32(HW_PORT_PCRn_ADDR(x, n), BP_PORT_PCRn_DSE))

/*! @brief Format value for bitfield PORT_PCRn_DSE. */
#define BF_PORT_PCRn_DSE(v)  ((uint32_t)((uint32_t)(v) << BP_PORT_PCRn_DSE) & BM_PORT_PCRn_DSE)

/*! @brief Set the DSE field to a new value. */
#define BW_PORT_PCRn_DSE(x, n, v) (BITBAND_ACCESS32(HW_PORT_PCRn_ADDR(x, n), BP_PORT_PCRn_DSE) = (v))
/*@}*/

/*!
 * @name Register PORT_PCRn, field MUX[10:8] (RW)
 *
 * Not all pins support all pin muxing slots. Unimplemented pin muxing slots are
 * reserved and may result in configuring the pin for a different pin muxing
 * slot. The corresponding pin is configured in the following pin muxing slot as
 * follows:
 *
 * Values:
 * - 000 - Pin disabled (analog).
 * - 001 - Alternative 1 (GPIO).
 * - 010 - Alternative 2 (chip-specific).
 * - 011 - Alternative 3 (chip-specific).
 * - 100 - Alternative 4 (chip-specific).
 * - 101 - Alternative 5 (chip-specific).
 * - 110 - Alternative 6 (chip-specific).
 * - 111 - Alternative 7 (chip-specific).
 */
/*@{*/
#define BP_PORT_PCRn_MUX     (8U)          /*!< Bit position for PORT_PCRn_MUX. */
#define BM_PORT_PCRn_MUX     (0x00000700U) /*!< Bit mask for PORT_PCRn_MUX. */
#define BS_PORT_PCRn_MUX     (3U)          /*!< Bit field size in bits for PORT_PCRn_MUX. */

/*! @brief Read current value of the PORT_PCRn_MUX field. */
#define BR_PORT_PCRn_MUX(x, n) (HW_PORT_PCRn(x, n).B.MUX)

/*! @brief Format value for bitfield PORT_PCRn_MUX. */
#define BF_PORT_PCRn_MUX(v)  ((uint32_t)((uint32_t)(v) << BP_PORT_PCRn_MUX) & BM_PORT_PCRn_MUX)

/*! @brief Set the MUX field to a new value. */
#define BW_PORT_PCRn_MUX(x, n, v) (HW_PORT_PCRn_WR(x, n, (HW_PORT_PCRn_RD(x, n) & ~BM_PORT_PCRn_MUX) | BF_PORT_PCRn_MUX(v)))
/*@}*/

/*!
 * @name Register PORT_PCRn, field LK[15] (RW)
 *
 * Values:
 * - 0 - Pin Control Register fields [15:0] are not locked.
 * - 1 - Pin Control Register fields [15:0] are locked and cannot be updated
 *     until the next system reset.
 */
/*@{*/
#define BP_PORT_PCRn_LK      (15U)         /*!< Bit position for PORT_PCRn_LK. */
#define BM_PORT_PCRn_LK      (0x00008000U) /*!< Bit mask for PORT_PCRn_LK. */
#define BS_PORT_PCRn_LK      (1U)          /*!< Bit field size in bits for PORT_PCRn_LK. */

/*! @brief Read current value of the PORT_PCRn_LK field. */
#define BR_PORT_PCRn_LK(x, n) (BITBAND_ACCESS32(HW_PORT_PCRn_ADDR(x, n), BP_PORT_PCRn_LK))

/*! @brief Format value for bitfield PORT_PCRn_LK. */
#define BF_PORT_PCRn_LK(v)   ((uint32_t)((uint32_t)(v) << BP_PORT_PCRn_LK) & BM_PORT_PCRn_LK)

/*! @brief Set the LK field to a new value. */
#define BW_PORT_PCRn_LK(x, n, v) (BITBAND_ACCESS32(HW_PORT_PCRn_ADDR(x, n), BP_PORT_PCRn_LK) = (v))
/*@}*/

/*!
 * @name Register PORT_PCRn, field IRQC[19:16] (RW)
 *
 * The pin interrupt configuration is valid in all digital pin muxing modes. The
 * corresponding pin is configured to generate interrupt/DMA request as follows:
 *
 * Values:
 * - 0000 - Interrupt/DMA request disabled.
 * - 0001 - DMA request on rising edge.
 * - 0010 - DMA request on falling edge.
 * - 0011 - DMA request on either edge.
 * - 1000 - Interrupt when logic 0.
 * - 1001 - Interrupt on rising-edge.
 * - 1010 - Interrupt on falling-edge.
 * - 1011 - Interrupt on either edge.
 * - 1100 - Interrupt when logic 1.
 */
/*@{*/
#define BP_PORT_PCRn_IRQC    (16U)         /*!< Bit position for PORT_PCRn_IRQC. */
#define BM_PORT_PCRn_IRQC    (0x000F0000U) /*!< Bit mask for PORT_PCRn_IRQC. */
#define BS_PORT_PCRn_IRQC    (4U)          /*!< Bit field size in bits for PORT_PCRn_IRQC. */

/*! @brief Read current value of the PORT_PCRn_IRQC field. */
#define BR_PORT_PCRn_IRQC(x, n) (HW_PORT_PCRn(x, n).B.IRQC)

/*! @brief Format value for bitfield PORT_PCRn_IRQC. */
#define BF_PORT_PCRn_IRQC(v) ((uint32_t)((uint32_t)(v) << BP_PORT_PCRn_IRQC) & BM_PORT_PCRn_IRQC)

/*! @brief Set the IRQC field to a new value. */
#define BW_PORT_PCRn_IRQC(x, n, v) (HW_PORT_PCRn_WR(x, n, (HW_PORT_PCRn_RD(x, n) & ~BM_PORT_PCRn_IRQC) | BF_PORT_PCRn_IRQC(v)))
/*@}*/

/*!
 * @name Register PORT_PCRn, field ISF[24] (W1C)
 *
 * The pin interrupt configuration is valid in all digital pin muxing modes.
 *
 * Values:
 * - 0 - Configured interrupt is not detected.
 * - 1 - Configured interrupt is detected. If the pin is configured to generate
 *     a DMA request, then the corresponding flag will be cleared automatically
 *     at the completion of the requested DMA transfer. Otherwise, the flag
 *     remains set until a logic 1 is written to the flag. If the pin is configured for
 *     a level sensitive interrupt and the pin remains asserted, then the flag
 *     is set again immediately after it is cleared.
 */
/*@{*/
#define BP_PORT_PCRn_ISF     (24U)         /*!< Bit position for PORT_PCRn_ISF. */
#define BM_PORT_PCRn_ISF     (0x01000000U) /*!< Bit mask for PORT_PCRn_ISF. */
#define BS_PORT_PCRn_ISF     (1U)          /*!< Bit field size in bits for PORT_PCRn_ISF. */

/*! @brief Read current value of the PORT_PCRn_ISF field. */
#define BR_PORT_PCRn_ISF(x, n) (BITBAND_ACCESS32(HW_PORT_PCRn_ADDR(x, n), BP_PORT_PCRn_ISF))

/*! @brief Format value for bitfield PORT_PCRn_ISF. */
#define BF_PORT_PCRn_ISF(v)  ((uint32_t)((uint32_t)(v) << BP_PORT_PCRn_ISF) & BM_PORT_PCRn_ISF)

/*! @brief Set the ISF field to a new value. */
#define BW_PORT_PCRn_ISF(x, n, v) (BITBAND_ACCESS32(HW_PORT_PCRn_ADDR(x, n), BP_PORT_PCRn_ISF) = (v))
/*@}*/

/*******************************************************************************
 * HW_PORT_GPCLR - Global Pin Control Low Register
 ******************************************************************************/

/*!
 * @brief HW_PORT_GPCLR - Global Pin Control Low Register (WORZ)
 *
 * Reset value: 0x00000000U
 *
 * Only 32-bit writes are supported to this register.
 */
typedef union _hw_port_gpclr
{
    uint32_t U;
    struct _hw_port_gpclr_bitfields
    {
        uint32_t GPWD : 16;            /*!< [15:0] Global Pin Write Data */
        uint32_t GPWE : 16;            /*!< [31:16] Global Pin Write Enable */
    } B;
} hw_port_gpclr_t;

/*!
 * @name Constants and macros for entire PORT_GPCLR register
 */
/*@{*/
#define HW_PORT_GPCLR_ADDR(x)    ((x) + 0x80U)

#define HW_PORT_GPCLR(x)         (*(__O hw_port_gpclr_t *) HW_PORT_GPCLR_ADDR(x))
#define HW_PORT_GPCLR_RD(x)      (HW_PORT_GPCLR(x).U)
#define HW_PORT_GPCLR_WR(x, v)   (HW_PORT_GPCLR(x).U = (v))
/*@}*/

/*
 * Constants & macros for individual PORT_GPCLR bitfields
 */

/*!
 * @name Register PORT_GPCLR, field GPWD[15:0] (WORZ)
 *
 * Write value that is written to all Pin Control Registers bits [15:0] that are
 * selected by GPWE.
 */
/*@{*/
#define BP_PORT_GPCLR_GPWD   (0U)          /*!< Bit position for PORT_GPCLR_GPWD. */
#define BM_PORT_GPCLR_GPWD   (0x0000FFFFU) /*!< Bit mask for PORT_GPCLR_GPWD. */
#define BS_PORT_GPCLR_GPWD   (16U)         /*!< Bit field size in bits for PORT_GPCLR_GPWD. */

/*! @brief Format value for bitfield PORT_GPCLR_GPWD. */
#define BF_PORT_GPCLR_GPWD(v) ((uint32_t)((uint32_t)(v) << BP_PORT_GPCLR_GPWD) & BM_PORT_GPCLR_GPWD)

/*! @brief Set the GPWD field to a new value. */
#define BW_PORT_GPCLR_GPWD(x, v) (HW_PORT_GPCLR_WR(x, (HW_PORT_GPCLR_RD(x) & ~BM_PORT_GPCLR_GPWD) | BF_PORT_GPCLR_GPWD(v)))
/*@}*/

/*!
 * @name Register PORT_GPCLR, field GPWE[31:16] (WORZ)
 *
 * Selects which Pin Control Registers (15 through 0) bits [15:0] update with
 * the value in GPWD. If a selected Pin Control Register is locked then the write
 * to that register is ignored.
 *
 * Values:
 * - 0 - Corresponding Pin Control Register is not updated with the value in
 *     GPWD.
 * - 1 - Corresponding Pin Control Register is updated with the value in GPWD.
 */
/*@{*/
#define BP_PORT_GPCLR_GPWE   (16U)         /*!< Bit position for PORT_GPCLR_GPWE. */
#define BM_PORT_GPCLR_GPWE   (0xFFFF0000U) /*!< Bit mask for PORT_GPCLR_GPWE. */
#define BS_PORT_GPCLR_GPWE   (16U)         /*!< Bit field size in bits for PORT_GPCLR_GPWE. */

/*! @brief Format value for bitfield PORT_GPCLR_GPWE. */
#define BF_PORT_GPCLR_GPWE(v) ((uint32_t)((uint32_t)(v) << BP_PORT_GPCLR_GPWE) & BM_PORT_GPCLR_GPWE)

/*! @brief Set the GPWE field to a new value. */
#define BW_PORT_GPCLR_GPWE(x, v) (HW_PORT_GPCLR_WR(x, (HW_PORT_GPCLR_RD(x) & ~BM_PORT_GPCLR_GPWE) | BF_PORT_GPCLR_GPWE(v)))
/*@}*/

/*******************************************************************************
 * HW_PORT_GPCHR - Global Pin Control High Register
 ******************************************************************************/

/*!
 * @brief HW_PORT_GPCHR - Global Pin Control High Register (WORZ)
 *
 * Reset value: 0x00000000U
 *
 * Only 32-bit writes are supported to this register.
 */
typedef union _hw_port_gpchr
{
    uint32_t U;
    struct _hw_port_gpchr_bitfields
    {
        uint32_t GPWD : 16;            /*!< [15:0] Global Pin Write Data */
        uint32_t GPWE : 16;            /*!< [31:16] Global Pin Write Enable */
    } B;
} hw_port_gpchr_t;

/*!
 * @name Constants and macros for entire PORT_GPCHR register
 */
/*@{*/
#define HW_PORT_GPCHR_ADDR(x)    ((x) + 0x84U)

#define HW_PORT_GPCHR(x)         (*(__O hw_port_gpchr_t *) HW_PORT_GPCHR_ADDR(x))
#define HW_PORT_GPCHR_RD(x)      (HW_PORT_GPCHR(x).U)
#define HW_PORT_GPCHR_WR(x, v)   (HW_PORT_GPCHR(x).U = (v))
/*@}*/

/*
 * Constants & macros for individual PORT_GPCHR bitfields
 */

/*!
 * @name Register PORT_GPCHR, field GPWD[15:0] (WORZ)
 *
 * Write value that is written to all Pin Control Registers bits [15:0] that are
 * selected by GPWE.
 */
/*@{*/
#define BP_PORT_GPCHR_GPWD   (0U)          /*!< Bit position for PORT_GPCHR_GPWD. */
#define BM_PORT_GPCHR_GPWD   (0x0000FFFFU) /*!< Bit mask for PORT_GPCHR_GPWD. */
#define BS_PORT_GPCHR_GPWD   (16U)         /*!< Bit field size in bits for PORT_GPCHR_GPWD. */

/*! @brief Format value for bitfield PORT_GPCHR_GPWD. */
#define BF_PORT_GPCHR_GPWD(v) ((uint32_t)((uint32_t)(v) << BP_PORT_GPCHR_GPWD) & BM_PORT_GPCHR_GPWD)

/*! @brief Set the GPWD field to a new value. */
#define BW_PORT_GPCHR_GPWD(x, v) (HW_PORT_GPCHR_WR(x, (HW_PORT_GPCHR_RD(x) & ~BM_PORT_GPCHR_GPWD) | BF_PORT_GPCHR_GPWD(v)))
/*@}*/

/*!
 * @name Register PORT_GPCHR, field GPWE[31:16] (WORZ)
 *
 * Selects which Pin Control Registers (31 through 16) bits [15:0] update with
 * the value in GPWD. If a selected Pin Control Register is locked then the write
 * to that register is ignored.
 *
 * Values:
 * - 0 - Corresponding Pin Control Register is not updated with the value in
 *     GPWD.
 * - 1 - Corresponding Pin Control Register is updated with the value in GPWD.
 */
/*@{*/
#define BP_PORT_GPCHR_GPWE   (16U)         /*!< Bit position for PORT_GPCHR_GPWE. */
#define BM_PORT_GPCHR_GPWE   (0xFFFF0000U) /*!< Bit mask for PORT_GPCHR_GPWE. */
#define BS_PORT_GPCHR_GPWE   (16U)         /*!< Bit field size in bits for PORT_GPCHR_GPWE. */

/*! @brief Format value for bitfield PORT_GPCHR_GPWE. */
#define BF_PORT_GPCHR_GPWE(v) ((uint32_t)((uint32_t)(v) << BP_PORT_GPCHR_GPWE) & BM_PORT_GPCHR_GPWE)

/*! @brief Set the GPWE field to a new value. */
#define BW_PORT_GPCHR_GPWE(x, v) (HW_PORT_GPCHR_WR(x, (HW_PORT_GPCHR_RD(x) & ~BM_PORT_GPCHR_GPWE) | BF_PORT_GPCHR_GPWE(v)))
/*@}*/

/*******************************************************************************
 * HW_PORT_ISFR - Interrupt Status Flag Register
 ******************************************************************************/

/*!
 * @brief HW_PORT_ISFR - Interrupt Status Flag Register (W1C)
 *
 * Reset value: 0x00000000U
 *
 * The pin interrupt configuration is valid in all digital pin muxing modes. The
 * Interrupt Status Flag for each pin is also visible in the corresponding Pin
 * Control Register, and each flag can be cleared in either location.
 */
typedef union _hw_port_isfr
{
    uint32_t U;
    struct _hw_port_isfr_bitfields
    {
        uint32_t ISF : 32;             /*!< [31:0] Interrupt Status Flag */
    } B;
} hw_port_isfr_t;

/*!
 * @name Constants and macros for entire PORT_ISFR register
 */
/*@{*/
#define HW_PORT_ISFR_ADDR(x)     ((x) + 0xA0U)

#define HW_PORT_ISFR(x)          (*(__IO hw_port_isfr_t *) HW_PORT_ISFR_ADDR(x))
#define HW_PORT_ISFR_RD(x)       (HW_PORT_ISFR(x).U)
#define HW_PORT_ISFR_WR(x, v)    (HW_PORT_ISFR(x).U = (v))
#define HW_PORT_ISFR_SET(x, v)   (HW_PORT_ISFR_WR(x, HW_PORT_ISFR_RD(x) |  (v)))
#define HW_PORT_ISFR_CLR(x, v)   (HW_PORT_ISFR_WR(x, HW_PORT_ISFR_RD(x) & ~(v)))
#define HW_PORT_ISFR_TOG(x, v)   (HW_PORT_ISFR_WR(x, HW_PORT_ISFR_RD(x) ^  (v)))
/*@}*/

/*
 * Constants & macros for individual PORT_ISFR bitfields
 */

/*!
 * @name Register PORT_ISFR, field ISF[31:0] (W1C)
 *
 * Each bit in the field indicates the detection of the configured interrupt of
 * the same number as the field.
 *
 * Values:
 * - 0 - Configured interrupt is not detected.
 * - 1 - Configured interrupt is detected. If the pin is configured to generate
 *     a DMA request, then the corresponding flag will be cleared automatically
 *     at the completion of the requested DMA transfer. Otherwise, the flag
 *     remains set until a logic 1 is written to the flag. If the pin is configured for
 *     a level sensitive interrupt and the pin remains asserted, then the flag
 *     is set again immediately after it is cleared.
 */
/*@{*/
#define BP_PORT_ISFR_ISF     (0U)          /*!< Bit position for PORT_ISFR_ISF. */
#define BM_PORT_ISFR_ISF     (0xFFFFFFFFU) /*!< Bit mask for PORT_ISFR_ISF. */
#define BS_PORT_ISFR_ISF     (32U)         /*!< Bit field size in bits for PORT_ISFR_ISF. */

/*! @brief Read current value of the PORT_ISFR_ISF field. */
#define BR_PORT_ISFR_ISF(x)  (HW_PORT_ISFR(x).U)

/*! @brief Format value for bitfield PORT_ISFR_ISF. */
#define BF_PORT_ISFR_ISF(v)  ((uint32_t)((uint32_t)(v) << BP_PORT_ISFR_ISF) & BM_PORT_ISFR_ISF)

/*! @brief Set the ISF field to a new value. */
#define BW_PORT_ISFR_ISF(x, v) (HW_PORT_ISFR_WR(x, v))
/*@}*/

/*******************************************************************************
 * HW_PORT_DFER - Digital Filter Enable Register
 ******************************************************************************/

/*!
 * @brief HW_PORT_DFER - Digital Filter Enable Register (RW)
 *
 * Reset value: 0x00000000U
 *
 * The corresponding bit is read only for pins that do not support a digital
 * filter. Refer to the Chapter of Signal Multiplexing and Signal Descriptions for
 * the pins that support digital filter. The digital filter configuration is valid
 * in all digital pin muxing modes.
 */
typedef union _hw_port_dfer
{
    uint32_t U;
    struct _hw_port_dfer_bitfields
    {
        uint32_t DFE : 32;             /*!< [31:0] Digital Filter Enable */
    } B;
} hw_port_dfer_t;

/*!
 * @name Constants and macros for entire PORT_DFER register
 */
/*@{*/
#define HW_PORT_DFER_ADDR(x)     ((x) + 0xC0U)

#define HW_PORT_DFER(x)          (*(__IO hw_port_dfer_t *) HW_PORT_DFER_ADDR(x))
#define HW_PORT_DFER_RD(x)       (HW_PORT_DFER(x).U)
#define HW_PORT_DFER_WR(x, v)    (HW_PORT_DFER(x).U = (v))
#define HW_PORT_DFER_SET(x, v)   (HW_PORT_DFER_WR(x, HW_PORT_DFER_RD(x) |  (v)))
#define HW_PORT_DFER_CLR(x, v)   (HW_PORT_DFER_WR(x, HW_PORT_DFER_RD(x) & ~(v)))
#define HW_PORT_DFER_TOG(x, v)   (HW_PORT_DFER_WR(x, HW_PORT_DFER_RD(x) ^  (v)))
/*@}*/

/*
 * Constants & macros for individual PORT_DFER bitfields
 */

/*!
 * @name Register PORT_DFER, field DFE[31:0] (RW)
 *
 * The digital filter configuration is valid in all digital pin muxing modes.
 * The output of each digital filter is reset to zero at system reset and whenever
 * the digital filter is disabled. Each bit in the field enables the digital
 * filter of the same number as the field.
 *
 * Values:
 * - 0 - Digital filter is disabled on the corresponding pin and output of the
 *     digital filter is reset to zero.
 * - 1 - Digital filter is enabled on the corresponding pin, if the pin is
 *     configured as a digital input.
 */
/*@{*/
#define BP_PORT_DFER_DFE     (0U)          /*!< Bit position for PORT_DFER_DFE. */
#define BM_PORT_DFER_DFE     (0xFFFFFFFFU) /*!< Bit mask for PORT_DFER_DFE. */
#define BS_PORT_DFER_DFE     (32U)         /*!< Bit field size in bits for PORT_DFER_DFE. */

/*! @brief Read current value of the PORT_DFER_DFE field. */
#define BR_PORT_DFER_DFE(x)  (HW_PORT_DFER(x).U)

/*! @brief Format value for bitfield PORT_DFER_DFE. */
#define BF_PORT_DFER_DFE(v)  ((uint32_t)((uint32_t)(v) << BP_PORT_DFER_DFE) & BM_PORT_DFER_DFE)

/*! @brief Set the DFE field to a new value. */
#define BW_PORT_DFER_DFE(x, v) (HW_PORT_DFER_WR(x, v))
/*@}*/

/*******************************************************************************
 * HW_PORT_DFCR - Digital Filter Clock Register
 ******************************************************************************/

/*!
 * @brief HW_PORT_DFCR - Digital Filter Clock Register (RW)
 *
 * Reset value: 0x00000000U
 *
 * This register is read only for ports that do not support a digital filter.
 * The digital filter configuration is valid in all digital pin muxing modes.
 */
typedef union _hw_port_dfcr
{
    uint32_t U;
    struct _hw_port_dfcr_bitfields
    {
        uint32_t CS : 1;               /*!< [0] Clock Source */
        uint32_t RESERVED0 : 31;       /*!< [31:1]  */
    } B;
} hw_port_dfcr_t;

/*!
 * @name Constants and macros for entire PORT_DFCR register
 */
/*@{*/
#define HW_PORT_DFCR_ADDR(x)     ((x) + 0xC4U)

#define HW_PORT_DFCR(x)          (*(__IO hw_port_dfcr_t *) HW_PORT_DFCR_ADDR(x))
#define HW_PORT_DFCR_RD(x)       (HW_PORT_DFCR(x).U)
#define HW_PORT_DFCR_WR(x, v)    (HW_PORT_DFCR(x).U = (v))
#define HW_PORT_DFCR_SET(x, v)   (HW_PORT_DFCR_WR(x, HW_PORT_DFCR_RD(x) |  (v)))
#define HW_PORT_DFCR_CLR(x, v)   (HW_PORT_DFCR_WR(x, HW_PORT_DFCR_RD(x) & ~(v)))
#define HW_PORT_DFCR_TOG(x, v)   (HW_PORT_DFCR_WR(x, HW_PORT_DFCR_RD(x) ^  (v)))
/*@}*/

/*
 * Constants & macros for individual PORT_DFCR bitfields
 */

/*!
 * @name Register PORT_DFCR, field CS[0] (RW)
 *
 * The digital filter configuration is valid in all digital pin muxing modes.
 * Configures the clock source for the digital input filters. Changing the filter
 * clock source must be done only when all digital filters are disabled.
 *
 * Values:
 * - 0 - Digital filters are clocked by the bus clock.
 * - 1 - Digital filters are clocked by the 1 kHz LPO clock.
 */
/*@{*/
#define BP_PORT_DFCR_CS      (0U)          /*!< Bit position for PORT_DFCR_CS. */
#define BM_PORT_DFCR_CS      (0x00000001U) /*!< Bit mask for PORT_DFCR_CS. */
#define BS_PORT_DFCR_CS      (1U)          /*!< Bit field size in bits for PORT_DFCR_CS. */

/*! @brief Read current value of the PORT_DFCR_CS field. */
#define BR_PORT_DFCR_CS(x)   (BITBAND_ACCESS32(HW_PORT_DFCR_ADDR(x), BP_PORT_DFCR_CS))

/*! @brief Format value for bitfield PORT_DFCR_CS. */
#define BF_PORT_DFCR_CS(v)   ((uint32_t)((uint32_t)(v) << BP_PORT_DFCR_CS) & BM_PORT_DFCR_CS)

/*! @brief Set the CS field to a new value. */
#define BW_PORT_DFCR_CS(x, v) (BITBAND_ACCESS32(HW_PORT_DFCR_ADDR(x), BP_PORT_DFCR_CS) = (v))
/*@}*/

/*******************************************************************************
 * HW_PORT_DFWR - Digital Filter Width Register
 ******************************************************************************/

/*!
 * @brief HW_PORT_DFWR - Digital Filter Width Register (RW)
 *
 * Reset value: 0x00000000U
 *
 * This register is read only for ports that do not support a digital filter.
 * The digital filter configuration is valid in all digital pin muxing modes.
 */
typedef union _hw_port_dfwr
{
    uint32_t U;
    struct _hw_port_dfwr_bitfields
    {
        uint32_t FILT : 5;             /*!< [4:0] Filter Length */
        uint32_t RESERVED0 : 27;       /*!< [31:5]  */
    } B;
} hw_port_dfwr_t;

/*!
 * @name Constants and macros for entire PORT_DFWR register
 */
/*@{*/
#define HW_PORT_DFWR_ADDR(x)     ((x) + 0xC8U)

#define HW_PORT_DFWR(x)          (*(__IO hw_port_dfwr_t *) HW_PORT_DFWR_ADDR(x))
#define HW_PORT_DFWR_RD(x)       (HW_PORT_DFWR(x).U)
#define HW_PORT_DFWR_WR(x, v)    (HW_PORT_DFWR(x).U = (v))
#define HW_PORT_DFWR_SET(x, v)   (HW_PORT_DFWR_WR(x, HW_PORT_DFWR_RD(x) |  (v)))
#define HW_PORT_DFWR_CLR(x, v)   (HW_PORT_DFWR_WR(x, HW_PORT_DFWR_RD(x) & ~(v)))
#define HW_PORT_DFWR_TOG(x, v)   (HW_PORT_DFWR_WR(x, HW_PORT_DFWR_RD(x) ^  (v)))
/*@}*/

/*
 * Constants & macros for individual PORT_DFWR bitfields
 */

/*!
 * @name Register PORT_DFWR, field FILT[4:0] (RW)
 *
 * The digital filter configuration is valid in all digital pin muxing modes.
 * Configures the maximum size of the glitches, in clock cycles, that the digital
 * filter absorbs for the enabled digital filters. Glitches that are longer than
 * this register setting will pass through the digital filter, and glitches that
 * are equal to or less than this register setting are filtered. Changing the
 * filter length must be done only after all filters are disabled.
 */
/*@{*/
#define BP_PORT_DFWR_FILT    (0U)          /*!< Bit position for PORT_DFWR_FILT. */
#define BM_PORT_DFWR_FILT    (0x0000001FU) /*!< Bit mask for PORT_DFWR_FILT. */
#define BS_PORT_DFWR_FILT    (5U)          /*!< Bit field size in bits for PORT_DFWR_FILT. */

/*! @brief Read current value of the PORT_DFWR_FILT field. */
#define BR_PORT_DFWR_FILT(x) (HW_PORT_DFWR(x).B.FILT)

/*! @brief Format value for bitfield PORT_DFWR_FILT. */
#define BF_PORT_DFWR_FILT(v) ((uint32_t)((uint32_t)(v) << BP_PORT_DFWR_FILT) & BM_PORT_DFWR_FILT)

/*! @brief Set the FILT field to a new value. */
#define BW_PORT_DFWR_FILT(x, v) (HW_PORT_DFWR_WR(x, (HW_PORT_DFWR_RD(x) & ~BM_PORT_DFWR_FILT) | BF_PORT_DFWR_FILT(v)))
/*@}*/

/*******************************************************************************
 * hw_port_t - module struct
 ******************************************************************************/
/*!
 * @brief All PORT module registers.
 */
#pragma pack(1)
typedef struct _hw_port
{
    __IO hw_port_pcrn_t PCRn[32];          /*!< [0x0] Pin Control Register n */
    __O hw_port_gpclr_t GPCLR;             /*!< [0x80] Global Pin Control Low Register */
    __O hw_port_gpchr_t GPCHR;             /*!< [0x84] Global Pin Control High Register */
    uint8_t _reserved0[24];
    __IO hw_port_isfr_t ISFR;              /*!< [0xA0] Interrupt Status Flag Register */
    uint8_t _reserved1[28];
    __IO hw_port_dfer_t DFER;              /*!< [0xC0] Digital Filter Enable Register */
    __IO hw_port_dfcr_t DFCR;              /*!< [0xC4] Digital Filter Clock Register */
    __IO hw_port_dfwr_t DFWR;              /*!< [0xC8] Digital Filter Width Register */
} hw_port_t;
#pragma pack()

/*! @brief Macro to access all PORT registers. */
/*! @param x PORT module instance base address. */
/*! @return Reference (not a pointer) to the registers struct. To get a pointer to the struct,
 *     use the '&' operator, like <code>&HW_PORT(PORTA_BASE)</code>. */
#define HW_PORT(x)     (*(hw_port_t *)(x))

#endif /* __HW_PORT_REGISTERS_H__ */
/* EOF */
