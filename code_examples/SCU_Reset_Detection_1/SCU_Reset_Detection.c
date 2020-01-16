/**********************************************************************************************************************
 * \file SCU_Reset_Detection.c
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

/*********************************************************************************************************************/
/*-----------------------------------------------------Includes------------------------------------------------------*/
/*********************************************************************************************************************/
#include "SCU_Reset_Detection.h"
#include "IfxPort.h"
#include "Ifx_Types.h"

/*********************************************************************************************************************/
/*------------------------------------------------------Macros-------------------------------------------------------*/
/*********************************************************************************************************************/
#define RSTCON2_CLRC_BIT   0x2

/*********************************************************************************************************************/
/*---------------------------------------------Function Implementations----------------------------------------------*/
/*********************************************************************************************************************/
/* Clear Cold Power-On Reset sticky bits */
void clearColdPowerOnResetBits(void)
{
    uint16 safetyEndinitPw = IfxScuWdt_getSafetyWatchdogPassword();
    IfxScuWdt_clearSafetyEndinit(safetyEndinitPw);
    MODULE_SCU.RSTCON2.U = MODULE_SCU.RSTCON2.U | RSTCON2_CLRC_BIT;
    IfxScuWdt_setSafetyEndinit(safetyEndinitPw);
}

/* This function evaluates the last reset condition and trigger */
scuRcuResetCode evaluateReset(void)
{
    Ifx_SCU_RSTCON      rstCon;         /* Define register object on rstcon         */
    Ifx_SCU_RSTSTAT     rstStat;        /* Define register object on rststat        */

    scuRcuResetCode resetCode;          /* Object to store the evaluation result    */

    /* Set default value of evaluation result for resetType */
    resetCode.resetType    = IfxScuRcu_ResetType_undefined;

    /* Set default value of evaluation result for resetTrigger */
    resetCode.resetTrigger = IfxScuRcu_Trigger_undefined;

    rstStat.U = MODULE_SCU.RSTSTAT.U;   /* Get register values of rststat           */
    rstCon.U  = MODULE_SCU.RSTCON.U;    /* Get register values of rstcon            */

    /* Evaluate the warm reset conditions first */
    if (rstStat.B.ESR0)
    {
        /* ResetType depending on configuration of rstCon.B.ESR0 */
        resetCode.resetType    = (scuRcuResetType)rstCon.B.ESR0;

        /* Reset Trigger is ESR0 */
        resetCode.resetTrigger = IfxScuRcu_Trigger_esr0;
    }
    else if (rstStat.B.ESR1)
    {
        /* ResetType depending on configuration of rstCon.B.ESR1 */
        resetCode.resetType    = (scuRcuResetType)rstCon.B.ESR1;

        /* Reset Trigger is ESR1 */
        resetCode.resetTrigger = IfxScuRcu_Trigger_esr1;
    }
    else if (rstStat.B.SMU)
    {
        /* ResetType depending on configuration of rstCon.B.SMU */
        resetCode.resetType    = (scuRcuResetType)rstCon.B.SMU;

        /* Reset Trigger is SMU */
        resetCode.resetTrigger = IfxScuRcu_Trigger_smu;
    }
    else if (rstStat.B.SW)
    {
        /* ResetType depending on configuration of rstCon.B.SW */
        resetCode.resetType    = (scuRcuResetType)rstCon.B.SW;

        /* Reset Trigger is SW */
        resetCode.resetTrigger = IfxScuRcu_Trigger_sw;
    }
    else if (rstStat.B.STM0)
    {
        /* ResetType depending on configuration of rstCon.B.STM0 */
        resetCode.resetType    = (scuRcuResetType)rstCon.B.STM0;

        /* Reset Trigger is STM0 */
        resetCode.resetTrigger = IfxScuRcu_Trigger_stm0;
    }
    else if (rstStat.B.STM1)
    {
        /* ResetType depending on configuration of rstCon.B.STM1 */
        resetCode.resetType    = (scuRcuResetType)rstCon.B.STM1;

        /* Reset Trigger is STM1 */
        resetCode.resetTrigger = IfxScuRcu_Trigger_stm1;
    }
    else if (rstStat.B.STM2)
    {
        /* ResetType depending on configuration of rstCon.B.STM2 */
        resetCode.resetType    = (scuRcuResetType)rstCon.B.STM2;

        /* Reset Trigger is STM2 */
        resetCode.resetTrigger = IfxScuRcu_Trigger_stm2;
    }
    else if (rstStat.B.CB0)
    {
        /* ResetType is system */
        resetCode.resetType    = IfxScuRcu_ResetType_system;

        /* Reset Trigger is CB0 */
        resetCode.resetTrigger = IfxScuRcu_Trigger_cb0;
    }
    else if (rstStat.B.CB1)
    {
        /* ResetType is debug */
        resetCode.resetType    = IfxScuRcu_ResetType_debug;

        /* Reset Trigger is CB1 */
        resetCode.resetTrigger = IfxScuRcu_Trigger_cb1;
    }
    else if (rstStat.B.CB3)
    {
        /* ResetType is application */
        resetCode.resetType    = IfxScuRcu_ResetType_application;

        /* Reset Trigger is CB3 */
        resetCode.resetTrigger = IfxScuRcu_Trigger_cb3;
    }
    else
    {
        /* Evaluate for Cold reset conditions */
        if (rstStat.B.EVR13)
        {
            /* ResetType is Cold Power-On */
            resetCode.resetType    = IfxScuRcu_ResetType_coldpoweron;

            /* Reset Trigger is EVR13 */
            resetCode.resetTrigger = IfxScuRcu_Trigger_evr13;
        }
        else if (rstStat.B.EVR33)
        {
            /* ResetType is Cold Power-On */
            resetCode.resetType    = IfxScuRcu_ResetType_coldpoweron;

            /* Reset Trigger is EVR33 */
            resetCode.resetTrigger = IfxScuRcu_Trigger_evr33;
        }
        else if (rstStat.B.SWD)
        {
            /* ResetType is Cold Power-On */
            resetCode.resetType    = IfxScuRcu_ResetType_coldpoweron;

            /* Reset Trigger is SWD */
            resetCode.resetTrigger = IfxScuRcu_Trigger_swd;
        }
        else if (rstStat.B.STBYR)
        {
            /* ResetType is Cold Power-On */
            resetCode.resetType    = IfxScuRcu_ResetType_coldpoweron;

            /* Reset Trigger is STDBYR */
            resetCode.resetTrigger = IfxScuRcu_Trigger_stbyr;
        }
    }

    /* Finally - Evaluate selectively for PORST */
    if (rstStat.B.PORST)
    {
        /* If none of the Cold Power-On reset bits is set */
        if (resetCode.resetType != IfxScuRcu_ResetType_coldpoweron)
        {
            resetCode.resetType = IfxScuRcu_ResetType_warmpoweron;  /* ResetType is Warm Power-On   */
            resetCode.resetTrigger = IfxScuRcu_Trigger_porst;       /* Rest Trigger is PORST        */
        }
    }

    return resetCode;
}

/* This function is developed only for testing purposes. Based on the local variable swRstType,
 * it triggers either a SW Application Reset or a SW System Reset.
 */
void triggerSWReset(uint32 swRstType)
{
    uint16 endinitSftyPw = IfxScuWdt_getSafetyWatchdogPassword();
    IfxScuWdt_clearSafetyEndinit(endinitSftyPw);

    if(swRstType == 1)
    {
        SCU_RSTCON.B.SW = IfxScuRcu_ResetType_application; /* Trigger SW Reset Type as application reset    */
    }
    else if(swRstType == 2)
    {
        SCU_RSTCON.B.SW = IfxScuRcu_ResetType_system;      /* Trigger SW Reset Type as system reset         */
    }
    /* The following instructions are not executed if a SW reset occurs */
    SCU_SWRSTCON.B.SWRSTREQ = 1;
    IfxScuWdt_clearSafetyEndinit(endinitSftyPw);
}

/* This function is the entry into the example and called from Cpu0_Main. */
void startScuResetDetection(void)
{
    volatile scuRcuResetCode lastReset;
    volatile uint32 swReset = 0;

    lastReset = evaluateReset();

    clearColdPowerOnResetBits(); /* Clears Cold Power On sticky bits of RSTCON register */

    /* The following while loop is used to stay in the startScuResetDetection() function during debug,
     * in order to watch the local variable lastReset.
     */
    while(1)
    {
        if(swReset > 0)
        {
            triggerSWReset(swReset);
        }
    }
}
