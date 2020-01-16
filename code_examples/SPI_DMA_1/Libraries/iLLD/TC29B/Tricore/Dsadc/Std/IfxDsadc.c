/**
 * \file IfxDsadc.c
 * \brief DSADC  basic functionality
 *
 * \version iLLD_1_0_1_11_0
 * \copyright Copyright (c) 2017 Infineon Technologies AG. All rights reserved.
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

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "IfxDsadc.h"

/******************************************************************************/
/*-------------------------Function Implementations---------------------------*/
/******************************************************************************/

volatile Ifx_SRC_SRCR *IfxDsadc_getAuxSrc(Ifx_DSADC *dsadc, IfxDsadc_ChannelId channel)
{
    return &(MODULE_SRC.DSADC.DSADC[channel].SRA);
}


float32 IfxDsadc_getIntegratorOutFreq(Ifx_DSADC *dsadc, IfxDsadc_ChannelId channel)
{
    float32            frequency = IfxDsadc_getMainCombOutFreq(dsadc, channel);

    frequency = frequency / ((float32)1.0 + dsadc->CH[channel].IWCTR.B.NVALINT);
    Ifx_DSADC_CH_FCFGM fcfgm = dsadc->CH[channel].FCFGM;

    if (fcfgm.B.FIR0EN != 0)
    {
        frequency = frequency / 2;
    }

    if (fcfgm.B.FIR1EN != 0)
    {
        frequency = frequency / 2;
    }

    return frequency;
}


float32 IfxDsadc_getMainCombOutFreq(Ifx_DSADC *dsadc, IfxDsadc_ChannelId channel)
{
    float32 frequency = IfxDsadc_getModulatorClockFreq(dsadc, channel);

    return frequency / ((float32)1.0 + dsadc->CH[channel].FCFGC.B.CFMDF);
}


float32 IfxDsadc_getMainGroupDelay(Ifx_DSADC *dsadc, IfxDsadc_ChannelId channel)
{
    Ifx_DSADC_CH_FCFGC fcfgc  = dsadc->CH[channel].FCFGC;
    Ifx_DSADC_CH_FCFGM fcfgm  = dsadc->CH[channel].FCFGM;
    Ifx_DSADC_CH_DICFG dicfg  = dsadc->CH[channel].DICFG;
    Ifx_DSADC_CH_IWCTR iwctr  = dsadc->CH[channel].IWCTR;
    float32            tsMod  = 1.0 / IfxDsadc_getModulatorClockFreq(dsadc, channel);
    float32            tsCic  = tsMod * (1 + fcfgc.B.CFMDF);
    float32            tsFir0 = tsCic * (1 + fcfgm.B.FIR0EN);
    float32            tsFir1 = tsFir0 * (1 + fcfgm.B.FIR1EN);

    float32            gdDsA  = (7 + 1) * tsMod;
    float32            cicN   = (1 + fcfgc.B.CFMDF);
    float32            cick   = (1 + fcfgc.B.CFMC);
    float32            gdCic  = tsMod * ((cick < 4) ? (0.5 * cick * (cicN - 1.0)) : ((2.0 * cicN) - 1.0));
    float32            gdFir0 = (fcfgm.B.FIR0EN != 0) ? ((3.5 + (3.0 / cicN)) * tsCic) : 0.0;
    float32            gdFir1;

    if (fcfgm.B.FIR0EN)
    {
        gdFir1 = (fcfgm.B.FIR1EN != 0) ? (0.5 * (28.0 + (5.0 / cicN)) * tsFir0) : 0.0;
    }
    else
    {
        gdFir1 = (fcfgm.B.FIR1EN != 0) ? ((28.0 + (5.0 / cicN)) * tsFir0) : 0.0;
    }

    float32 gdInt = (dicfg.B.ITRMODE == IfxDsadc_IntegratorTrigger_bypassed) ? 0 : ((iwctr.B.NVALINT) * tsFir1);

    return gdDsA + gdCic + gdFir0 + gdFir1 + gdInt;
}


volatile Ifx_SRC_SRCR *IfxDsadc_getMainSrc(Ifx_DSADC *dsadc, IfxDsadc_ChannelId channel)
{
    return &(MODULE_SRC.DSADC.DSADC[channel].SRM);
}


float32 IfxDsadc_getModulatorClockFreq(Ifx_DSADC *dsadc, IfxDsadc_ChannelId channel)
{
    float32 sourceFreq = IfxDsadc_getModulatorInputClockFreq(dsadc);

    return sourceFreq / ((dsadc->CH[channel].MODCFG.B.DIVM + 1) * 2);
}


float32 IfxDsadc_getModulatorInputClockFreq(Ifx_DSADC *dsadc)
{
    float32 result;

    switch (dsadc->GLOBCFG.B.MCSEL)
    {
    case IfxDsadc_ModulatorClock_fOSC0:
        result = IfxScuCcu_getOsc0Frequency();
        break;
    case IfxDsadc_ModulatorClock_fERAY:
        result = IfxScuCcu_getPllErayFrequency();
        break;
    case IfxDsadc_ModulatorClock_fDSD:
        result = IfxScuCcu_getSpbFrequency();
        break;
    default:
        result = 0;
        break;
    }

    return result;
}


void IfxDsadc_resetModule(Ifx_DSADC *dsadc)
{
    uint16 passwd = IfxScuWdt_getCpuWatchdogPassword();

    IfxScuWdt_clearCpuEndinit(passwd);
    dsadc->KRST0.B.RST = 1;         /* Only if both Kernel reset bits are set a reset is executed */
    dsadc->KRST1.B.RST = 1;
    IfxScuWdt_setCpuEndinit(passwd);

    while (0 == dsadc->KRST0.B.RSTSTAT)     /* Wait until reset is executed */

    {}

    IfxScuWdt_clearCpuEndinit(passwd);
    dsadc->KRSTCLR.B.CLR = 1;           /* Clear Kernel reset status bit */
    IfxScuWdt_setCpuEndinit(passwd);
}
