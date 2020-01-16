/**********************************************************************************************************************
 * \file DMA_ADC_Transfer.h
 * \copyright Copyright (C) Infineon Technologies AG 2019
 *
 * Use of this file is subject to the terms of use agreed between (i) you or the company in which ordinary course of
 * business you are acting and (ii) Infineon Technologies AG or its licensees. If and as long as no such terms of use
 * are agreed, use of this file is subject to following:
 *
 * Boost Software License - Version 1.0 - August 17th, 2003
 *
 * Permission is hereby granted, free of charge, to any person or organization obtaining a copy of the software and
 * accompanying documentation covered by this license (the "Software") to use, reproduce, display, distribute, execute,
 * and transmit the Software, and to prepare derivative works of the Software, and to permit third-parties to whom the
 * Software is furnished to do so, all subject to the following:
 *
 * The copyright notices in the Software and this entire statement, including the above license grant, this restriction
 * and the following disclaimer, must be included in all copies of the Software, in whole or in part, and all
 * derivative works of the Software, unless such copies or derivative works are solely in the form of
 * machine-executable object code generated by a source language processor.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
 * WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT SHALL THE
 * COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN
 * CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 *********************************************************************************************************************/

#ifndef DMA_ADC_TRANSFER_H_
#define DMA_ADC_TRANSFER_H_

/*********************************************************************************************************************/
/*-----------------------------------------------------Includes------------------------------------------------------*/
/*********************************************************************************************************************/
#include "Ifx_Types.h"
#include "IfxDma_Dma.h"
#include "IfxVadc.h"
#include "IfxVadc_Adc.h"

/*********************************************************************************************************************/
/*------------------------------------------------------Macros-------------------------------------------------------*/
/*********************************************************************************************************************/
#define DMA_CHANNEL             1    /* DMA Channel used in this example (0 lowest priority - 127 highest priority) */
#define N_TRANSFER              1           /* Number of transfer in 1 transaction                                  */
#define ISR_PRIORITY_ADC        DMA_CHANNEL /* Priority for interrupt after ADC conversion.
                                             * Should be equal to DMA_CHANNEL when DMA is the Interrupt Service Provider */
#define ISR_PRIORITY_DMA        20          /* Priority for interrupt after DMA transfer done                       */
#define ADC_CHANNEL             0           /* ADC channel number                                                   */
#define RX_LENGTH               1           /* RX message length                                                    */
#define PASS_CHARACTER          '1'         /* Character which enables the ADC conversion + DMA transfer            */
#define RESET_CHARACTER         '0'         /* Reset value of UART exchange character after a DMA transfer          */
#define TEXT_LENGTH             17          /* Length of the acknowledgment message after a DMA transfer            */
#define DEST_ADDR               0x90000000  /* Start address of the LMURAM                                          */
#define SRC_ADDR                0xF0020700  /* Start address of the VADC result register Group 0-Channel 0 (VADC_G0RES0) */
                                            /* Result Registers addresses can be found in IfxVadc_reg.h                  */
#define COMPLETED_TRANSFER_TEXT "Transfer done!\r\n"

#define ISR_PRIORITY_ASCLIN_TX  1           /* Priority for interrupt ISR Transmit                                  */
#define ISR_PRIORITY_ASCLIN_RX  2           /* Priority for interrupt ISR Receive                                   */
#define ISR_PRIORITY_ASCLIN_ER  3           /* Priority for interrupt ISR Errors                                    */
#define ASC_TX_BUFFER_SIZE      64
#define ASC_RX_BUFFER_SIZE      64
#define ASC_PRESCALER           1
#define ASC_BAUDRATE            9600

/*********************************************************************************************************************/
/*------------------------------------------------Function Prototypes------------------------------------------------*/
/*********************************************************************************************************************/
void init_uart(void);
void init_vadc(void);
void init_dma(void);
void receive_data(char *data, Ifx_SizeT length);
void run_vadc(void);
void send_data(char *data, Ifx_SizeT length);

#endif /* DMA_ADC_TRANSFER_H_ */
