; * ---------------------------------------------------------------------------------------
; *  @file:    startup_MK22F12810.s
; *  @purpose: CMSIS Cortex-M4 Core Device Startup File
; *            MK22F12810
; *  @version: 1.3
; *  @date:    2014-5-6
; *  @build:   b140611
; * ---------------------------------------------------------------------------------------
; *
; * Copyright (c) 1997 - 2014 , Freescale Semiconductor, Inc.
; * All rights reserved.
; *
; * Redistribution and use in source and binary forms, with or without modification,
; * are permitted provided that the following conditions are met:
; *
; * o Redistributions of source code must retain the above copyright notice, this list
; *   of conditions and the following disclaimer.
; *
; * o Redistributions in binary form must reproduce the above copyright notice, this
; *   list of conditions and the following disclaimer in the documentation and/or
; *   other materials provided with the distribution.
; *
; * o Neither the name of Freescale Semiconductor, Inc. nor the names of its
; *   contributors may be used to endorse or promote products derived from this
; *   software without specific prior written permission.
; *
; * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
; * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
; * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
; * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
; * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
; * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
; * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
; * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
; * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
; * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
; *
; *------- <<< Use Configuration Wizard in Context Menu >>> ------------------
; *
; *****************************************************************************/
__initial_sp        EQU     0x20003FFF  ; Top of RAM


                PRESERVE8
                THUMB


; Vector Table Mapped to Address 0 at Reset

                AREA    RESET, DATA, READONLY
                EXPORT  __Vectors
                EXPORT  __Vectors_End
                EXPORT  __Vectors_Size

__Vectors       DCD     __initial_sp  ; Top of Stack
                DCD     Reset_Handler  ; Reset Handler
                DCD     NMI_Handler                         ;NMI Handler
                DCD     HardFault_Handler                   ;Hard Fault Handler
                DCD     MemManage_Handler                   ;MPU Fault Handler
                DCD     BusFault_Handler                    ;Bus Fault Handler
                DCD     UsageFault_Handler                  ;Usage Fault Handler
                DCD     0                                   ;Reserved
                DCD     0                                   ;Reserved
                DCD     0                                   ;Reserved
                DCD     0                                   ;Reserved
                DCD     SVC_Handler                         ;SVCall Handler
                DCD     DebugMon_Handler                    ;Debug Monitor Handler
                DCD     0                                   ;Reserved
                DCD     PendSV_Handler                      ;PendSV Handler
                DCD     SysTick_Handler                     ;SysTick Handler

                                                            ;External Interrupts
                DCD     DMA0_IRQHandler                     ;DMA Channel 0 Transfer Complete
                DCD     DMA1_IRQHandler                     ;DMA Channel 1 Transfer Complete
                DCD     DMA2_IRQHandler                     ;DMA Channel 2 Transfer Complete
                DCD     DMA3_IRQHandler                     ;DMA Channel 3 Transfer Complete
                DCD     Reserved20_IRQHandler               ;Reserved interrupt 20
                DCD     Reserved21_IRQHandler               ;Reserved interrupt 21
                DCD     Reserved22_IRQHandler               ;Reserved interrupt 22
                DCD     Reserved23_IRQHandler               ;Reserved interrupt 23
                DCD     Reserved24_IRQHandler               ;Reserved interrupt 24
                DCD     Reserved25_IRQHandler               ;Reserved interrupt 25
                DCD     Reserved26_IRQHandler               ;Reserved interrupt 26
                DCD     Reserved27_IRQHandler               ;Reserved interrupt 27
                DCD     Reserved28_IRQHandler               ;Reserved interrupt 28
                DCD     Reserved29_IRQHandler               ;Reserved interrupt 29
                DCD     Reserved30_IRQHandler               ;Reserved interrupt 30
                DCD     Reserved31_IRQHandler               ;Reserved interrupt 31
                DCD     DMA_Error_IRQHandler                ;DMA Error Interrupt
                DCD     MCM_IRQHandler                      ;Normal Interrupt
                DCD     FTF_IRQHandler                      ;FTFA Command complete interrupt
                DCD     Read_Collision_IRQHandler           ;Read Collision Interrupt
                DCD     LVD_LVW_IRQHandler                  ;Low Voltage Detect, Low Voltage Warning
                DCD     LLW_IRQHandler                      ;Low Leakage Wakeup
                DCD     Watchdog_IRQHandler                 ;WDOG Interrupt
                DCD     Reserved39_IRQHandler               ;Reserved Interrupt 39
                DCD     I2C0_IRQHandler                     ;I2C0 interrupt
                DCD     I2C1_IRQHandler                     ;I2C1 interrupt
                DCD     SPI0_IRQHandler                     ;SPI0 Interrupt
                DCD     SPI1_IRQHandler                     ;SPI1 Interrupt
                DCD     I2S0_Tx_IRQHandler                  ;I2S0 transmit interrupt
                DCD     I2S0_Rx_IRQHandler                  ;I2S0 receive interrupt
                DCD     LPUART0_IRQHandler                  ;LPUART0 status/error interrupt
                DCD     UART0_RX_TX_IRQHandler              ;UART0 Receive/Transmit interrupt
                DCD     UART0_ERR_IRQHandler                ;UART0 Error interrupt
                DCD     UART1_RX_TX_IRQHandler              ;UART1 Receive/Transmit interrupt
                DCD     UART1_ERR_IRQHandler                ;UART1 Error interrupt
                DCD     UART2_RX_TX_IRQHandler              ;UART2 Receive/Transmit interrupt
                DCD     UART2_ERR_IRQHandler                ;UART2 Error interrupt
                DCD     Reserved53_IRQHandler               ;Reserved interrupt 53
                DCD     Reserved54_IRQHandler               ;Reserved interrupt 54
                DCD     ADC0_IRQHandler                     ;ADC0 interrupt
                DCD     CMP0_IRQHandler                     ;CMP0 interrupt
                DCD     CMP1_IRQHandler                     ;CMP1 interrupt
                DCD     FTM0_IRQHandler                     ;FTM0 fault, overflow and channels interrupt
                DCD     FTM1_IRQHandler                     ;FTM1 fault, overflow and channels interrupt
                DCD     FTM2_IRQHandler                     ;FTM2 fault, overflow and channels interrupt
                DCD     Reserved61_IRQHandler               ;Reserved interrupt 61
                DCD     RTC_IRQHandler                      ;RTC interrupt
                DCD     RTC_Seconds_IRQHandler              ;RTC seconds interrupt
                DCD     PIT0_IRQHandler                     ;PIT timer channel 0 interrupt
                DCD     PIT1_IRQHandler                     ;PIT timer channel 1 interrupt
                DCD     PIT2_IRQHandler                     ;PIT timer channel 2 interrupt
                DCD     PIT3_IRQHandler                     ;PIT timer channel 3 interrupt
                DCD     PDB0_IRQHandler                     ;PDB0 Interrupt
                DCD     USB0_IRQHandler                     ;USB0 interrupt
                DCD     Reserved70_IRQHandler               ;Reserved interrupt 70
                DCD     Reserved71_IRQHandler               ;Reserved interrupt 71
                DCD     DAC0_IRQHandler                     ;DAC0 interrupt
                DCD     MCG_IRQHandler                      ;MCG Interrupt
                DCD     LPTimer_IRQHandler                  ;LPTimer interrupt
                DCD     PORTA_IRQHandler                    ;Port A interrupt
                DCD     PORTB_IRQHandler                    ;Port B interrupt
                DCD     PORTC_IRQHandler                    ;Port C interrupt
                DCD     PORTD_IRQHandler                    ;Port D interrupt
                DCD     PORTE_IRQHandler                    ;Port E interrupt
                DCD     SWI_IRQHandler                      ;Software interrupt
                DCD     Reserved81_IRQHandler               ;Reserved interrupt 81
                DCD     Reserved82_IRQHandler               ;Reserved interrupt 82
                DCD     Reserved83_IRQHandler               ;Reserved interrupt 83
                DCD     Reserved84_IRQHandler               ;Reserved interrupt 84
                DCD     Reserved85_IRQHandler               ;Reserved interrupt 85
                DCD     Reserved86_IRQHandler               ;Reserved interrupt 86
                DCD     Reserved87_IRQHandler               ;Reserved interrupt 87
                DCD     Reserved88_IRQHandler               ;Reserved interrupt 88
                DCD     ADC1_IRQHandler                     ;ADC1 interrupt
                DCD     Reserved90_IRQHandler               ;Reserved Interrupt 90
                DCD     Reserved91_IRQHandler               ;Reserved Interrupt 91
                DCD     Reserved92_IRQHandler               ;Reserved Interrupt 92
                DCD     Reserved93_IRQHandler               ;Reserved Interrupt 93
                DCD     Reserved94_IRQHandler               ;Reserved Interrupt 94
                DCD     Reserved95_IRQHandler               ;Reserved Interrupt 95
                DCD     Reserved96_IRQHandler               ;Reserved Interrupt 96
                DCD     Reserved97_IRQHandler               ;Reserved Interrupt 97
                DCD     Reserved98_IRQHandler               ;Reserved Interrupt 98
                DCD     Reserved99_IRQHandler               ;Reserved Interrupt 99
                DCD     Reserved100_IRQHandler              ;Reserved Interrupt 100
                DCD     Reserved101_IRQHandler              ;Reserved Interrupt 101
                DCD     DefaultISR                          ;102
                DCD     DefaultISR                          ;103
                DCD     DefaultISR                          ;104
                DCD     DefaultISR                          ;105
                DCD     DefaultISR                          ;106
                DCD     DefaultISR                          ;107
                DCD     DefaultISR                          ;108
                DCD     DefaultISR                          ;109
                DCD     DefaultISR                          ;110
                DCD     DefaultISR                          ;111
                DCD     DefaultISR                          ;112
                DCD     DefaultISR                          ;113
                DCD     DefaultISR                          ;114
                DCD     DefaultISR                          ;115
                DCD     DefaultISR                          ;116
                DCD     DefaultISR                          ;117
                DCD     DefaultISR                          ;118
                DCD     DefaultISR                          ;119
                DCD     DefaultISR                          ;120
                DCD     DefaultISR                          ;121
                DCD     DefaultISR                          ;122
                DCD     DefaultISR                          ;123
                DCD     DefaultISR                          ;124
                DCD     DefaultISR                          ;125
                DCD     DefaultISR                          ;126
                DCD     DefaultISR                          ;127
                DCD     DefaultISR                          ;128
                DCD     DefaultISR                          ;129
                DCD     DefaultISR                          ;130
                DCD     DefaultISR                          ;131
                DCD     DefaultISR                          ;132
                DCD     DefaultISR                          ;133
                DCD     DefaultISR                          ;134
                DCD     DefaultISR                          ;135
                DCD     DefaultISR                          ;136
                DCD     DefaultISR                          ;137
                DCD     DefaultISR                          ;138
                DCD     DefaultISR                          ;139
                DCD     DefaultISR                          ;140
                DCD     DefaultISR                          ;141
                DCD     DefaultISR                          ;142
                DCD     DefaultISR                          ;143
                DCD     DefaultISR                          ;144
                DCD     DefaultISR                          ;145
                DCD     DefaultISR                          ;146
                DCD     DefaultISR                          ;147
                DCD     DefaultISR                          ;148
                DCD     DefaultISR                          ;149
                DCD     DefaultISR                          ;150
                DCD     DefaultISR                          ;151
                DCD     DefaultISR                          ;152
                DCD     DefaultISR                          ;153
                DCD     DefaultISR                          ;154
                DCD     DefaultISR                          ;155
                DCD     DefaultISR                          ;156
                DCD     DefaultISR                          ;157
                DCD     DefaultISR                          ;158
                DCD     DefaultISR                          ;159
                DCD     DefaultISR                          ;160
                DCD     DefaultISR                          ;161
                DCD     DefaultISR                          ;162
                DCD     DefaultISR                          ;163
                DCD     DefaultISR                          ;164
                DCD     DefaultISR                          ;165
                DCD     DefaultISR                          ;166
                DCD     DefaultISR                          ;167
                DCD     DefaultISR                          ;168
                DCD     DefaultISR                          ;169
                DCD     DefaultISR                          ;170
                DCD     DefaultISR                          ;171
                DCD     DefaultISR                          ;172
                DCD     DefaultISR                          ;173
                DCD     DefaultISR                          ;174
                DCD     DefaultISR                          ;175
                DCD     DefaultISR                          ;176
                DCD     DefaultISR                          ;177
                DCD     DefaultISR                          ;178
                DCD     DefaultISR                          ;179
                DCD     DefaultISR                          ;180
                DCD     DefaultISR                          ;181
                DCD     DefaultISR                          ;182
                DCD     DefaultISR                          ;183
                DCD     DefaultISR                          ;184
                DCD     DefaultISR                          ;185
                DCD     DefaultISR                          ;186
                DCD     DefaultISR                          ;187
                DCD     DefaultISR                          ;188
                DCD     DefaultISR                          ;189
                DCD     DefaultISR                          ;190
                DCD     DefaultISR                          ;191
                DCD     DefaultISR                          ;192
                DCD     DefaultISR                          ;193
                DCD     DefaultISR                          ;194
                DCD     DefaultISR                          ;195
                DCD     DefaultISR                          ;196
                DCD     DefaultISR                          ;197
                DCD     DefaultISR                          ;198
                DCD     DefaultISR                          ;199
                DCD     DefaultISR                          ;200
                DCD     DefaultISR                          ;201
                DCD     DefaultISR                          ;202
                DCD     DefaultISR                          ;203
                DCD     DefaultISR                          ;204
                DCD     DefaultISR                          ;205
                DCD     DefaultISR                          ;206
                DCD     DefaultISR                          ;207
                DCD     DefaultISR                          ;208
                DCD     DefaultISR                          ;209
                DCD     DefaultISR                          ;210
                DCD     DefaultISR                          ;211
                DCD     DefaultISR                          ;212
                DCD     DefaultISR                          ;213
                DCD     DefaultISR                          ;214
                DCD     DefaultISR                          ;215
                DCD     DefaultISR                          ;216
                DCD     DefaultISR                          ;217
                DCD     DefaultISR                          ;218
                DCD     DefaultISR                          ;219
                DCD     DefaultISR                          ;220
                DCD     DefaultISR                          ;221
                DCD     DefaultISR                          ;222
                DCD     DefaultISR                          ;223
                DCD     DefaultISR                          ;224
                DCD     DefaultISR                          ;225
                DCD     DefaultISR                          ;226
                DCD     DefaultISR                          ;227
                DCD     DefaultISR                          ;228
                DCD     DefaultISR                          ;229
                DCD     DefaultISR                          ;230
                DCD     DefaultISR                          ;231
                DCD     DefaultISR                          ;232
                DCD     DefaultISR                          ;233
                DCD     DefaultISR                          ;234
                DCD     DefaultISR                          ;235
                DCD     DefaultISR                          ;236
                DCD     DefaultISR                          ;237
                DCD     DefaultISR                          ;238
                DCD     DefaultISR                          ;239
                DCD     DefaultISR                          ;240
                DCD     DefaultISR                          ;241
                DCD     DefaultISR                          ;242
                DCD     DefaultISR                          ;243
                DCD     DefaultISR                          ;244
                DCD     DefaultISR                          ;245
                DCD     DefaultISR                          ;246
                DCD     DefaultISR                          ;247
                DCD     DefaultISR                          ;248
                DCD     DefaultISR                          ;249
                DCD     DefaultISR                          ;250
                DCD     DefaultISR                          ;251
                DCD     DefaultISR                          ;252
                DCD     DefaultISR                          ;253
                DCD     DefaultISR                          ;254
                DCD     0xFFFFFFFF                          ; Reserved for user TRIM value
__Vectors_End

__Vectors_Size 	EQU     __Vectors_End - __Vectors

; <h> Flash Configuration
;   <i> 16-byte flash configuration field that stores default protection settings (loaded on reset)
;   <i> and security information that allows the MCU to restrict acces to the FTFL module.
;   <h> Backdoor Comparison Key
;     <o0>  Backdoor Key 0  <0x0-0xFF:2>
;     <o1>  Backdoor Key 1  <0x0-0xFF:2>
;     <o2>  Backdoor Key 2  <0x0-0xFF:2>
;     <o3>  Backdoor Key 3  <0x0-0xFF:2>
;     <o4>  Backdoor Key 4  <0x0-0xFF:2>
;     <o5>  Backdoor Key 5  <0x0-0xFF:2>
;     <o6>  Backdoor Key 6  <0x0-0xFF:2>
;     <o7>  Backdoor Key 7  <0x0-0xFF:2>
BackDoorK0      EQU     0xFF
BackDoorK1      EQU     0xFF
BackDoorK2      EQU     0xFF
BackDoorK3      EQU     0xFF
BackDoorK4      EQU     0xFF
BackDoorK5      EQU     0xFF
BackDoorK6      EQU     0xFF
BackDoorK7      EQU     0xFF
;   </h>
;   <h> Program flash protection bytes (FPROT)
;     <i> Each program flash region can be protected from program and erase operation by setting the associated PROT bit.
;     <i> Each bit protects a 1/32 region of the program flash memory.
;     <h> FPROT0
;       <i> Program flash protection bytes
;       <i> 1/32 - 8/32 region
;       <o.0>   FPROT0.0
;       <o.1>   FPROT0.1
;       <o.2>   FPROT0.2
;       <o.3>   FPROT0.3
;       <o.4>   FPROT0.4
;       <o.5>   FPROT0.5
;       <o.6>   FPROT0.6
;       <o.7>   FPROT0.7
nFPROT0         EQU     0x00
FPROT0          EQU     nFPROT0:EOR:0xFF
;     </h>
;     <h> FPROT1
;       <i> Program Flash Region Protect Register 1
;       <i> 9/32 - 16/32 region
;       <o.0>   FPROT1.0
;       <o.1>   FPROT1.1
;       <o.2>   FPROT1.2
;       <o.3>   FPROT1.3
;       <o.4>   FPROT1.4
;       <o.5>   FPROT1.5
;       <o.6>   FPROT1.6
;       <o.7>   FPROT1.7
nFPROT1         EQU     0x00
FPROT1          EQU     nFPROT1:EOR:0xFF
;     </h>
;     <h> FPROT2
;       <i> Program Flash Region Protect Register 2
;       <i> 17/32 - 24/32 region
;       <o.0>   FPROT2.0
;       <o.1>   FPROT2.1
;       <o.2>   FPROT2.2
;       <o.3>   FPROT2.3
;       <o.4>   FPROT2.4
;       <o.5>   FPROT2.5
;       <o.6>   FPROT2.6
;       <o.7>   FPROT2.7
nFPROT2         EQU     0x00
FPROT2          EQU     nFPROT2:EOR:0xFF
;     </h>
;     <h> FPROT3
;       <i> Program Flash Region Protect Register 3
;       <i> 25/32 - 32/32 region
;       <o.0>   FPROT3.0
;       <o.1>   FPROT3.1
;       <o.2>   FPROT3.2
;       <o.3>   FPROT3.3
;       <o.4>   FPROT3.4
;       <o.5>   FPROT3.5
;       <o.6>   FPROT3.6
;       <o.7>   FPROT3.7
nFPROT3         EQU     0x00
FPROT3          EQU     nFPROT3:EOR:0xFF
;     </h>
;   </h>
;   <h> Data flash protection byte (FDPROT)
;     <i> Each bit protects a 1/8 region of the data flash memory.
;     <i> (Program flash only devices: Reserved)
;     <o.0>   FDPROT.0
;     <o.1>   FDPROT.1
;     <o.2>   FDPROT.2
;     <o.3>   FDPROT.3
;     <o.4>   FDPROT.4
;     <o.5>   FDPROT.5
;     <o.6>   FDPROT.6
;     <o.7>   FDPROT.7
nFDPROT         EQU     0x00
FDPROT          EQU     nFDPROT:EOR:0xFF
;   </h>
;   <h> EEPROM protection byte (FEPROT)
;     <i> FlexNVM devices: Each bit protects a 1/8 region of the EEPROM.
;     <i> (Program flash only devices: Reserved)
;     <o.0>   FEPROT.0
;     <o.1>   FEPROT.1
;     <o.2>   FEPROT.2
;     <o.3>   FEPROT.3
;     <o.4>   FEPROT.4
;     <o.5>   FEPROT.5
;     <o.6>   FEPROT.6
;     <o.7>   FEPROT.7
nFEPROT         EQU     0x00
FEPROT          EQU     nFEPROT:EOR:0xFF
;   </h>
;   <h> Flash nonvolatile option byte (FOPT)
;     <i> Allows the user to customize the operation of the MCU at boot time.
;     <o.0>  LPBOOT
;       <0=> Low-power boot
;       <1=> normal boot
;     <o.1>  EZPORT_DIS
;       <0=> EzPort operation is enabled
;       <1=> EzPort operation is disabled
FOPT            EQU     0xFF
;   </h>
;   <h> Flash security byte (FSEC)
;     <i> WARNING: If SEC field is configured as "MCU security status is secure" and MEEN field is configured as "Mass erase is disabled",
;     <i> MCU's security status cannot be set back to unsecure state since Mass erase via the debugger is blocked !!!
;     <o.0..1> SEC
;       <2=> MCU security status is unsecure
;       <3=> MCU security status is secure
;         <i> Flash Security
;         <i> This bits define the security state of the MCU.
;     <o.2..3> FSLACC
;       <2=> Freescale factory access denied
;       <3=> Freescale factory access granted
;         <i> Freescale Failure Analysis Access Code
;         <i> This bits define the security state of the MCU.
;     <o.4..5> MEEN
;       <2=> Mass erase is disabled
;       <3=> Mass erase is enabled
;         <i> Mass Erase Enable Bits
;         <i> Enables and disables mass erase capability of the FTFL module
;     <o.6..7> KEYEN
;       <2=> Backdoor key access enabled
;       <3=> Backdoor key access disabled
;         <i> Backdoor key Security Enable
;         <i> These bits enable and disable backdoor key access to the FTFL module.
FSEC            EQU     0xFE
;   </h>
; </h>
                IF      :LNOT::DEF:RAM_TARGET
                AREA    |.ARM.__at_0x400|, CODE, READONLY
                DCB     BackDoorK0, BackDoorK1, BackDoorK2, BackDoorK3
                DCB     BackDoorK4, BackDoorK5, BackDoorK6, BackDoorK7
                DCB     FPROT0,     FPROT1,     FPROT2,     FPROT3
                DCB     FSEC,       FOPT,       FEPROT,     FDPROT
                ENDIF

                AREA    |.text|, CODE, READONLY

                
; Reset Handler

Reset_Handler   PROC
                EXPORT  Reset_Handler             [WEAK]
                IMPORT  SystemInit
                IMPORT  __main
                LDR     R0, =SystemInit
                BLX     R0
                LDR     R0, =__main
                BX      R0
                ENDP

                
; Dummy Exception Handlers (infinite loops which can be modified)
NMI_Handler\
                PROC
                EXPORT  NMI_Handler         [WEAK]
                B       .
                ENDP
HardFault_Handler\
                PROC
                EXPORT  HardFault_Handler         [WEAK]
                B       .
                ENDP
MemManage_Handler\
                PROC
                EXPORT  MemManage_Handler         [WEAK]
                B       .
                ENDP
BusFault_Handler\
                PROC
                EXPORT  BusFault_Handler         [WEAK]
                B       .
                ENDP
UsageFault_Handler\
                PROC
                EXPORT  UsageFault_Handler         [WEAK]
                B       .
                ENDP
SVC_Handler\
                PROC
                EXPORT  SVC_Handler         [WEAK]
                B       .
                ENDP
DebugMon_Handler\
                PROC
                EXPORT  DebugMon_Handler         [WEAK]
                B       .
                ENDP
PendSV_Handler\
                PROC
                EXPORT  PendSV_Handler         [WEAK]
                B       .
                ENDP
SysTick_Handler\
                PROC
                EXPORT  SysTick_Handler         [WEAK]
                B       .
                ENDP
Default_Handler\
                PROC
                EXPORT  DMA0_IRQHandler         [WEAK]
                EXPORT  DMA1_IRQHandler         [WEAK]
                EXPORT  DMA2_IRQHandler         [WEAK]
                EXPORT  DMA3_IRQHandler         [WEAK]
                EXPORT  Reserved20_IRQHandler         [WEAK]
                EXPORT  Reserved21_IRQHandler         [WEAK]
                EXPORT  Reserved22_IRQHandler         [WEAK]
                EXPORT  Reserved23_IRQHandler         [WEAK]
                EXPORT  Reserved24_IRQHandler         [WEAK]
                EXPORT  Reserved25_IRQHandler         [WEAK]
                EXPORT  Reserved26_IRQHandler         [WEAK]
                EXPORT  Reserved27_IRQHandler         [WEAK]
                EXPORT  Reserved28_IRQHandler         [WEAK]
                EXPORT  Reserved29_IRQHandler         [WEAK]
                EXPORT  Reserved30_IRQHandler         [WEAK]
                EXPORT  Reserved31_IRQHandler         [WEAK]
                EXPORT  DMA_Error_IRQHandler         [WEAK]
                EXPORT  MCM_IRQHandler         [WEAK]
                EXPORT  FTF_IRQHandler         [WEAK]
                EXPORT  Read_Collision_IRQHandler         [WEAK]
                EXPORT  LVD_LVW_IRQHandler         [WEAK]
                EXPORT  LLW_IRQHandler         [WEAK]
                EXPORT  Watchdog_IRQHandler         [WEAK]
                EXPORT  Reserved39_IRQHandler         [WEAK]
                EXPORT  I2C0_IRQHandler         [WEAK]
                EXPORT  I2C1_IRQHandler         [WEAK]
                EXPORT  SPI0_IRQHandler         [WEAK]
                EXPORT  SPI1_IRQHandler         [WEAK]
                EXPORT  I2S0_Tx_IRQHandler         [WEAK]
                EXPORT  I2S0_Rx_IRQHandler         [WEAK]
                EXPORT  LPUART0_IRQHandler         [WEAK]
                EXPORT  UART0_RX_TX_IRQHandler         [WEAK]
                EXPORT  UART0_ERR_IRQHandler         [WEAK]
                EXPORT  UART1_RX_TX_IRQHandler         [WEAK]
                EXPORT  UART1_ERR_IRQHandler         [WEAK]
                EXPORT  UART2_RX_TX_IRQHandler         [WEAK]
                EXPORT  UART2_ERR_IRQHandler         [WEAK]
                EXPORT  Reserved53_IRQHandler         [WEAK]
                EXPORT  Reserved54_IRQHandler         [WEAK]
                EXPORT  ADC0_IRQHandler         [WEAK]
                EXPORT  CMP0_IRQHandler         [WEAK]
                EXPORT  CMP1_IRQHandler         [WEAK]
                EXPORT  FTM0_IRQHandler         [WEAK]
                EXPORT  FTM1_IRQHandler         [WEAK]
                EXPORT  FTM2_IRQHandler         [WEAK]
                EXPORT  Reserved61_IRQHandler         [WEAK]
                EXPORT  RTC_IRQHandler         [WEAK]
                EXPORT  RTC_Seconds_IRQHandler         [WEAK]
                EXPORT  PIT0_IRQHandler         [WEAK]
                EXPORT  PIT1_IRQHandler         [WEAK]
                EXPORT  PIT2_IRQHandler         [WEAK]
                EXPORT  PIT3_IRQHandler         [WEAK]
                EXPORT  PDB0_IRQHandler         [WEAK]
                EXPORT  USB0_IRQHandler         [WEAK]
                EXPORT  Reserved70_IRQHandler         [WEAK]
                EXPORT  Reserved71_IRQHandler         [WEAK]
                EXPORT  DAC0_IRQHandler         [WEAK]
                EXPORT  MCG_IRQHandler         [WEAK]
                EXPORT  LPTimer_IRQHandler         [WEAK]
                EXPORT  PORTA_IRQHandler         [WEAK]
                EXPORT  PORTB_IRQHandler         [WEAK]
                EXPORT  PORTC_IRQHandler         [WEAK]
                EXPORT  PORTD_IRQHandler         [WEAK]
                EXPORT  PORTE_IRQHandler         [WEAK]
                EXPORT  SWI_IRQHandler         [WEAK]
                EXPORT  Reserved81_IRQHandler         [WEAK]
                EXPORT  Reserved82_IRQHandler         [WEAK]
                EXPORT  Reserved83_IRQHandler         [WEAK]
                EXPORT  Reserved84_IRQHandler         [WEAK]
                EXPORT  Reserved85_IRQHandler         [WEAK]
                EXPORT  Reserved86_IRQHandler         [WEAK]
                EXPORT  Reserved87_IRQHandler         [WEAK]
                EXPORT  Reserved88_IRQHandler         [WEAK]
                EXPORT  ADC1_IRQHandler         [WEAK]
                EXPORT  Reserved90_IRQHandler         [WEAK]
                EXPORT  Reserved91_IRQHandler         [WEAK]
                EXPORT  Reserved92_IRQHandler         [WEAK]
                EXPORT  Reserved93_IRQHandler         [WEAK]
                EXPORT  Reserved94_IRQHandler         [WEAK]
                EXPORT  Reserved95_IRQHandler         [WEAK]
                EXPORT  Reserved96_IRQHandler         [WEAK]
                EXPORT  Reserved97_IRQHandler         [WEAK]
                EXPORT  Reserved98_IRQHandler         [WEAK]
                EXPORT  Reserved99_IRQHandler         [WEAK]
                EXPORT  Reserved100_IRQHandler         [WEAK]
                EXPORT  Reserved101_IRQHandler         [WEAK]
                EXPORT  DefaultISR         [WEAK]
DMA0_IRQHandler
DMA1_IRQHandler
DMA2_IRQHandler
DMA3_IRQHandler
Reserved20_IRQHandler
Reserved21_IRQHandler
Reserved22_IRQHandler
Reserved23_IRQHandler
Reserved24_IRQHandler
Reserved25_IRQHandler
Reserved26_IRQHandler
Reserved27_IRQHandler
Reserved28_IRQHandler
Reserved29_IRQHandler
Reserved30_IRQHandler
Reserved31_IRQHandler
DMA_Error_IRQHandler
MCM_IRQHandler
FTF_IRQHandler
Read_Collision_IRQHandler
LVD_LVW_IRQHandler
LLW_IRQHandler
Watchdog_IRQHandler
Reserved39_IRQHandler
I2C0_IRQHandler
I2C1_IRQHandler
SPI0_IRQHandler
SPI1_IRQHandler
I2S0_Tx_IRQHandler
I2S0_Rx_IRQHandler
LPUART0_IRQHandler
UART0_RX_TX_IRQHandler
UART0_ERR_IRQHandler
UART1_RX_TX_IRQHandler
UART1_ERR_IRQHandler
UART2_RX_TX_IRQHandler
UART2_ERR_IRQHandler
Reserved53_IRQHandler
Reserved54_IRQHandler
ADC0_IRQHandler
CMP0_IRQHandler
CMP1_IRQHandler
FTM0_IRQHandler
FTM1_IRQHandler
FTM2_IRQHandler
Reserved61_IRQHandler
RTC_IRQHandler
RTC_Seconds_IRQHandler
PIT0_IRQHandler
PIT1_IRQHandler
PIT2_IRQHandler
PIT3_IRQHandler
PDB0_IRQHandler
USB0_IRQHandler
Reserved70_IRQHandler
Reserved71_IRQHandler
DAC0_IRQHandler
MCG_IRQHandler
LPTimer_IRQHandler
PORTA_IRQHandler
PORTB_IRQHandler
PORTC_IRQHandler
PORTD_IRQHandler
PORTE_IRQHandler
SWI_IRQHandler
Reserved81_IRQHandler
Reserved82_IRQHandler
Reserved83_IRQHandler
Reserved84_IRQHandler
Reserved85_IRQHandler
Reserved86_IRQHandler
Reserved87_IRQHandler
Reserved88_IRQHandler
ADC1_IRQHandler
Reserved90_IRQHandler
Reserved91_IRQHandler
Reserved92_IRQHandler
Reserved93_IRQHandler
Reserved94_IRQHandler
Reserved95_IRQHandler
Reserved96_IRQHandler
Reserved97_IRQHandler
Reserved98_IRQHandler
Reserved99_IRQHandler
Reserved100_IRQHandler
Reserved101_IRQHandler
DefaultISR
                B       .
                ENDP
                  ALIGN


                END
