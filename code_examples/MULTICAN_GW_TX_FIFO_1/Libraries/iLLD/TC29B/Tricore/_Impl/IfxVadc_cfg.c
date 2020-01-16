/**
 * \file IfxVadc_cfg.c
 * \brief VADC on-chip implementation data
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

#include "IfxVadc_cfg.h"

/******************************************************************************/
/*-----------------------Exported Variables/Constants-------------------------*/
/******************************************************************************/

IFX_CONST uint32 IfxVadc_cfg_srcAddresses[(IFXVADC_NUM_ADC_GROUPS * 4) + (IFXVADC_NUM_ADC_COMMON_GROUPS * 4)] = {
    (uint32)&SRC_VADC_G0_SR0,
    (uint32)&SRC_VADC_G0_SR1,
    (uint32)&SRC_VADC_G0_SR2,
    (uint32)&SRC_VADC_G0_SR3,
    (uint32)&SRC_VADC_G1_SR0,
    (uint32)&SRC_VADC_G1_SR1,
    (uint32)&SRC_VADC_G1_SR2,
    (uint32)&SRC_VADC_G1_SR3,
    (uint32)&SRC_VADC_G2_SR0,
    (uint32)&SRC_VADC_G2_SR1,
    (uint32)&SRC_VADC_G2_SR2,
    (uint32)&SRC_VADC_G2_SR3,
    (uint32)&SRC_VADC_G3_SR0,
    (uint32)&SRC_VADC_G3_SR1,
    (uint32)&SRC_VADC_G3_SR2,
    (uint32)&SRC_VADC_G3_SR3,
    (uint32)&SRC_VADC_G4_SR0,
    (uint32)&SRC_VADC_G4_SR1,
    (uint32)&SRC_VADC_G4_SR2,
    (uint32)&SRC_VADC_G4_SR3,
    (uint32)&SRC_VADC_G5_SR0,
    (uint32)&SRC_VADC_G5_SR1,
    (uint32)&SRC_VADC_G5_SR2,
    (uint32)&SRC_VADC_G5_SR3,
    (uint32)&SRC_VADC_G6_SR0,
    (uint32)&SRC_VADC_G6_SR1,
    (uint32)&SRC_VADC_G6_SR2,
    (uint32)&SRC_VADC_G6_SR3,
    (uint32)&SRC_VADC_G7_SR0,
    (uint32)&SRC_VADC_G7_SR1,
    (uint32)&SRC_VADC_G7_SR2,
    (uint32)&SRC_VADC_G7_SR3,
    (uint32)&SRC_VADC_G8_SR0,
    (uint32)&SRC_VADC_G8_SR1,
    (uint32)&SRC_VADC_G8_SR2,
    (uint32)&SRC_VADC_G8_SR3,
    (uint32)&SRC_VADC_G9_SR0,
    (uint32)&SRC_VADC_G9_SR1,
    (uint32)&SRC_VADC_G9_SR2,
    (uint32)&SRC_VADC_G9_SR3,
    (uint32)&SRC_VADC_G10_SR0,
    (uint32)&SRC_VADC_G10_SR1,
    (uint32)&SRC_VADC_G10_SR2,
    (uint32)&SRC_VADC_G10_SR3,
    (uint32)&SRC_VADC_CG0_SR0,
    (uint32)&SRC_VADC_CG0_SR1,
    (uint32)&SRC_VADC_CG0_SR2,
    (uint32)&SRC_VADC_CG0_SR3,
    (uint32)&SRC_VADC_CG1_SR0,
    (uint32)&SRC_VADC_CG1_SR1,
    (uint32)&SRC_VADC_CG1_SR2,
    (uint32)&SRC_VADC_CG1_SR3
};
