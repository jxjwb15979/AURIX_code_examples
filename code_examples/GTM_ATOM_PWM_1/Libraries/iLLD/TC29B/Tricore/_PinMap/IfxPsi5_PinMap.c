/**
 * \file IfxPsi5_PinMap.c
 * \brief PSI5 I/O map
 * \ingroup IfxLld_Psi5
 *
 * \version iLLD_1_0_1_11_0
 * \copyright Copyright (c) 2013 Infineon Technologies AG. All rights reserved.
 *
 *
 *                                 IMPORTANT NOTICE
 *
 *
 * Use of this file is subject to the terms of use agreed between (i) you or 
 * the company in which ordinary course of business you are acting and (ii) 
 * Infineon Technologies AG or its licensees. If and as long as no such 
 * terms of use are agreed, use of this file is subject to following:


 * Boost Software License - Version 1.0 - August 17th, 2003

 * Permission is hereby granted, free of charge, to any person or 
 * organization obtaining a copy of the software and accompanying 
 * documentation covered by this license (the "Software") to use, reproduce,
 * display, distribute, execute, and transmit the Software, and to prepare
 * derivative works of the Software, and to permit third-parties to whom the 
 * Software is furnished to do so, all subject to the following:

 * The copyright notices in the Software and this entire statement, including
 * the above license grant, this restriction and the following disclaimer, must
 * be included in all copies of the Software, in whole or in part, and all
 * derivative works of the Software, unless such copies or derivative works are
 * solely in the form of machine-executable object code generated by a source
 * language processor.

 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR 
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
 * SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE 
 * FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.

 *
 */

#include "IfxPsi5_PinMap.h"

IfxPsi5_Rx_In IfxPsi5_RX0A_P00_1_IN = {&MODULE_PSI5, IfxPsi5_ChannelId_0, {&MODULE_P00, 1}, Ifx_RxSel_a};
IfxPsi5_Rx_In IfxPsi5_RX0B_P02_3_IN = {&MODULE_PSI5, IfxPsi5_ChannelId_0, {&MODULE_P02, 3}, Ifx_RxSel_b};
IfxPsi5_Rx_In IfxPsi5_RX0C_P33_1_IN = {&MODULE_PSI5, IfxPsi5_ChannelId_0, {&MODULE_P33, 1}, Ifx_RxSel_c};
IfxPsi5_Rx_In IfxPsi5_RX1A_P00_3_IN = {&MODULE_PSI5, IfxPsi5_ChannelId_1, {&MODULE_P00, 3}, Ifx_RxSel_a};
IfxPsi5_Rx_In IfxPsi5_RX1B_P02_5_IN = {&MODULE_PSI5, IfxPsi5_ChannelId_1, {&MODULE_P02, 5}, Ifx_RxSel_b};
IfxPsi5_Rx_In IfxPsi5_RX1C_P33_3_IN = {&MODULE_PSI5, IfxPsi5_ChannelId_1, {&MODULE_P33, 3}, Ifx_RxSel_c};
IfxPsi5_Rx_In IfxPsi5_RX2A_P00_5_IN = {&MODULE_PSI5, IfxPsi5_ChannelId_2, {&MODULE_P00, 5}, Ifx_RxSel_a};
IfxPsi5_Rx_In IfxPsi5_RX2B_P02_7_IN = {&MODULE_PSI5, IfxPsi5_ChannelId_2, {&MODULE_P02, 7}, Ifx_RxSel_b};
IfxPsi5_Rx_In IfxPsi5_RX2C_P33_5_IN = {&MODULE_PSI5, IfxPsi5_ChannelId_2, {&MODULE_P33, 5}, Ifx_RxSel_c};
IfxPsi5_Rx_In IfxPsi5_RX3A_P13_10_IN = {&MODULE_PSI5, IfxPsi5_ChannelId_3, {&MODULE_P13,10}, Ifx_RxSel_a};
IfxPsi5_Rx_In IfxPsi5_RX3B_P13_13_IN = {&MODULE_PSI5, IfxPsi5_ChannelId_3, {&MODULE_P13,13}, Ifx_RxSel_b};
IfxPsi5_Rx_In IfxPsi5_RX3C_P10_6_IN = {&MODULE_PSI5, IfxPsi5_ChannelId_3, {&MODULE_P10, 6}, Ifx_RxSel_c};
IfxPsi5_Rx_In IfxPsi5_RX4A_P13_4_IN = {&MODULE_PSI5, IfxPsi5_ChannelId_4, {&MODULE_P13, 4}, Ifx_RxSel_a};
IfxPsi5_Rx_In IfxPsi5_RX4B_P22_5_IN = {&MODULE_PSI5, IfxPsi5_ChannelId_4, {&MODULE_P22, 5}, Ifx_RxSel_b};
IfxPsi5_Tx_Out IfxPsi5_TX0_P00_2_OUT = {&MODULE_PSI5, IfxPsi5_ChannelId_0, {&MODULE_P00, 2}, IfxPort_OutputIdx_alt4};
IfxPsi5_Tx_Out IfxPsi5_TX0_P02_2_OUT = {&MODULE_PSI5, IfxPsi5_ChannelId_0, {&MODULE_P02, 2}, IfxPort_OutputIdx_alt4};
IfxPsi5_Tx_Out IfxPsi5_TX0_P33_2_OUT = {&MODULE_PSI5, IfxPsi5_ChannelId_0, {&MODULE_P33, 2}, IfxPort_OutputIdx_alt4};
IfxPsi5_Tx_Out IfxPsi5_TX1_P00_4_OUT = {&MODULE_PSI5, IfxPsi5_ChannelId_1, {&MODULE_P00, 4}, IfxPort_OutputIdx_alt4};
IfxPsi5_Tx_Out IfxPsi5_TX1_P02_6_OUT = {&MODULE_PSI5, IfxPsi5_ChannelId_1, {&MODULE_P02, 6}, IfxPort_OutputIdx_alt4};
IfxPsi5_Tx_Out IfxPsi5_TX1_P33_4_OUT = {&MODULE_PSI5, IfxPsi5_ChannelId_1, {&MODULE_P33, 4}, IfxPort_OutputIdx_alt4};
IfxPsi5_Tx_Out IfxPsi5_TX2_P00_6_OUT = {&MODULE_PSI5, IfxPsi5_ChannelId_2, {&MODULE_P00, 6}, IfxPort_OutputIdx_alt4};
IfxPsi5_Tx_Out IfxPsi5_TX2_P02_8_OUT = {&MODULE_PSI5, IfxPsi5_ChannelId_2, {&MODULE_P02, 8}, IfxPort_OutputIdx_alt4};
IfxPsi5_Tx_Out IfxPsi5_TX2_P33_6_OUT = {&MODULE_PSI5, IfxPsi5_ChannelId_2, {&MODULE_P33, 6}, IfxPort_OutputIdx_alt4};
IfxPsi5_Tx_Out IfxPsi5_TX3_P10_5_OUT = {&MODULE_PSI5, IfxPsi5_ChannelId_3, {&MODULE_P10, 5}, IfxPort_OutputIdx_alt7};
IfxPsi5_Tx_Out IfxPsi5_TX3_P13_11_OUT = {&MODULE_PSI5, IfxPsi5_ChannelId_3, {&MODULE_P13,11}, IfxPort_OutputIdx_alt5};
IfxPsi5_Tx_Out IfxPsi5_TX3_P13_15_OUT = {&MODULE_PSI5, IfxPsi5_ChannelId_3, {&MODULE_P13,15}, IfxPort_OutputIdx_alt4};
IfxPsi5_Tx_Out IfxPsi5_TX4_P14_11_OUT = {&MODULE_PSI5, IfxPsi5_ChannelId_4, {&MODULE_P14,11}, IfxPort_OutputIdx_alt3};
IfxPsi5_Tx_Out IfxPsi5_TX4_P22_4_OUT = {&MODULE_PSI5, IfxPsi5_ChannelId_4, {&MODULE_P22, 4}, IfxPort_OutputIdx_alt5};


const IfxPsi5_Rx_In *IfxPsi5_Rx_In_pinTable[IFXPSI5_PINMAP_NUM_MODULES][IFXPSI5_PINMAP_NUM_CHANNELS][IFXPSI5_PINMAP_RX_IN_NUM_ITEMS] = {
    {
        {
            &IfxPsi5_RX0A_P00_1_IN,
            &IfxPsi5_RX0B_P02_3_IN,
            &IfxPsi5_RX0C_P33_1_IN
        },
        {
            &IfxPsi5_RX1A_P00_3_IN,
            &IfxPsi5_RX1B_P02_5_IN,
            &IfxPsi5_RX1C_P33_3_IN
        },
        {
            &IfxPsi5_RX2A_P00_5_IN,
            &IfxPsi5_RX2B_P02_7_IN,
            &IfxPsi5_RX2C_P33_5_IN
        },
        {
            &IfxPsi5_RX3A_P13_10_IN,
            &IfxPsi5_RX3B_P13_13_IN,
            &IfxPsi5_RX3C_P10_6_IN
        },
        {
            &IfxPsi5_RX4A_P13_4_IN,
            &IfxPsi5_RX4B_P22_5_IN,
            NULL_PTR
        }
    }
};

const IfxPsi5_Tx_Out *IfxPsi5_Tx_Out_pinTable[IFXPSI5_PINMAP_NUM_MODULES][IFXPSI5_PINMAP_NUM_CHANNELS][IFXPSI5_PINMAP_TX_OUT_NUM_ITEMS] = {
    {
        {
            &IfxPsi5_TX0_P00_2_OUT,
            &IfxPsi5_TX0_P02_2_OUT,
            &IfxPsi5_TX0_P33_2_OUT
        },
        {
            &IfxPsi5_TX1_P00_4_OUT,
            &IfxPsi5_TX1_P02_6_OUT,
            &IfxPsi5_TX1_P33_4_OUT
        },
        {
            &IfxPsi5_TX2_P00_6_OUT,
            &IfxPsi5_TX2_P02_8_OUT,
            &IfxPsi5_TX2_P33_6_OUT
        },
        {
            &IfxPsi5_TX3_P10_5_OUT,
            &IfxPsi5_TX3_P13_11_OUT,
            &IfxPsi5_TX3_P13_15_OUT
        },
        {
            &IfxPsi5_TX4_P14_11_OUT,
            &IfxPsi5_TX4_P22_4_OUT,
            NULL_PTR
        }
    }
};
