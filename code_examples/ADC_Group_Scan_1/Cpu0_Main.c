/**********************************************************************************************************************
 * \file Cpu0_Main.c
 * \copyright Copyright (C) Infineon Technologies AG 2020
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
 /*\title Auto Scan of ADC channel
 * \abstract The Versatile Analog-to-Digital Converter (VADC) is configured to measure multiple analog signals in a sequence using  scan request.
 * \description The Auto Scan mode of the Versatile Analog to Digital Converter (VADC) module is enabled over the
 *              channels 0 to 4 of the Group 0. Additionally, the converted results are checked with the
 *              Valid Flag (VF) of the Result Register, and then sent to the PC via UART.
 *
 * \name ADC_Group_Scan_1
 * \version V1.0.0
 * \board APPLICATION KIT TC2X7 V1.1, KIT_AURIX_TC297_TFT_BC-Step, TC29xTA/TX_BC-step
 * \keywords ADC, ADC_Group_Scan_1, AURIX, VADC, auto scan, conversion
 * \documents https://www.infineon.com/aurix-expert-training/Infineon-AURIX_ADC_Group_Scan_1-TR-v01_00_00-EN.pdf
 * \documents https://www.infineon.com/aurix-expert-training/iLLD_UM_TC29B.chm
 * \lastUpdated 2020-01-17
 *********************************************************************************************************************/
#include "Ifx_Types.h"
#include "IfxCpu.h"
#include "IfxScuWdt.h"
#include "ADC_Group_Scan.h"

IfxCpu_syncEvent g_cpuSyncEvent = 0;

int core0_main(void)
{
    IfxCpu_enableInterrupts();

    /* !!WATCHDOG0 AND SAFETY WATCHDOG ARE DISABLED HERE!!
     * Enable the watchdogs and service them periodically if it is required
     */
    IfxScuWdt_disableCpuWatchdog(IfxScuWdt_getCpuWatchdogPassword());
    IfxScuWdt_disableSafetyWatchdog(IfxScuWdt_getSafetyWatchdogPassword());

    /* Wait for CPU sync event */
    IfxCpu_emitEvent(&g_cpuSyncEvent);
    IfxCpu_waitEvent(&g_cpuSyncEvent, 1);

    /* Initialize the VADC and ASCLIN modules */
    init_vadc();                /* Initialize the VADC module                           */
    init_uart();                /* Initialize the ASCLIN module for UART communication  */

    char rxData[RX_LENGTH];     /* Placeholder for the received command                 */
    while(1)
    {
        rxData[0] = RESET_CHARACTER;        /* Reset received data                      */
        while(rxData[0] != PASS_CHARACTER)  /* Wait for receive the correct character   */
        {
            receive_data(rxData, RX_LENGTH);
        }

        run_vadc();             /* Get and print VADC conversions                       */
    }

    return (1);
}
