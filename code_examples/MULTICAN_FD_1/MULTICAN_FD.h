/********************************************************************************************************************
 * \file MULTICAN_FD.h
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

#ifndef MULTICAN_FD_H_
#define MULTICAN_FD_H_ 1
/*********************************************************************************************************************/
/*-----------------------------------------------------Includes------------------------------------------------------*/
/*********************************************************************************************************************/
#include <stdio.h>
#include <string.h>
#include "Ifx_Types.h"
#include "IfxMultican_Can.h"
#include "IfxMultican.h"
#include "IfxPort.h"                                            /* For GPIO Port Pin Control                         */

/*********************************************************************************************************************/
/*------------------------------------------------------Macros-------------------------------------------------------*/
/*********************************************************************************************************************/
#define STANDARD_MESSAGE_ID_1       0x444                       /* Message ID that is used in arbitration phase      */
#define STANDARD_MESSAGE_ID_2       0x777                       /* Message ID that is used in arbitration phase      */
#define EXTENDED_MESSAGE_ID_1       0x1234567                   /* Message ID that is used in arbitration phase      */
#define EXTENDED_MESSAGE_ID_2       0xAABBCCD                   /* Message ID that is used in arbitration phase      */
#define DST_MO_OFFSET               10                          /* Offset where the destination MOs are located      */
#define SRC_EXTENDED_MO_OFFSET      64                          /* Offset where the src extended MOs are located     */
#define DST_EXTENDED_MO_OFFSET      128                         /* Offset where the dst extended MOs are located     */
#define RX_INTERRUPT_SRC_ID         IfxMultican_SrcId_1         /* RX interrupt service request ID                   */
#define PORT13_PIN0                 0                           /* LED used in RX ISR is connected to this pin       */
#define INVALID_TX_DATA_VALUE       (uint8)0x55                 /* Used to invalidate TX message data content        */
#define INVALID_RX_DATA_VALUE       (uint8)0xAA                 /* Used to invalidate RX message data content        */
#define INVALID_FAST_BITRATE_VALUE  (boolean)FALSE              /* Used to invalidate RX messages fast bit rate value*/
#define INVALID_ID_VALUE            (uint32)0xFFFFFFFF          /* Used to invalidate RX messages ID value           */
#define INVALID_LENGTH_VALUE        (IfxMultican_DataLengthCode)0   /* Used to invalidate RX messages length value   */
#define TX_DATA_INIT_SHIFT_OFFSET   6                           /* Define the shift offset value for the TX data     */
#define ISR_PRIORITY_CAN_RX         1                           /* Define the CAN RX interrupt priority              */
#define NUMBER_OF_CAN_FD_CASES      4                           /* Define the number of CAN FD use cases             */
#define MAXIMUM_CAN_FD_DATA_PAYLOAD 64                          /* Define maximum CAN FD data payload in bytes       */

/*********************************************************************************************************************/
/*--------------------------------------------------Data Structures--------------------------------------------------*/
/*********************************************************************************************************************/
typedef struct
{
    IfxMultican_Can can;                                           /* CAN module handle to HW module SFR set         */
    IfxMultican_Can_Config canConfig;                              /* CAN module configuration structure             */
    IfxMultican_Can_Node canNode0;                                 /* CAN node 0 handle data structure               */
    IfxMultican_Can_Node canNode1;                                 /* CAN node 1 handle data structure               */
    IfxMultican_Can_NodeConfig canNodeConfig;                      /* CAN node configuration structure               */
    IfxMultican_Can_MsgObj canSrcMsgObj[NUMBER_OF_CAN_FD_CASES];   /* CAN source standard message objects array      */
    IfxMultican_Can_MsgObj canDstMsgObj[NUMBER_OF_CAN_FD_CASES];   /* CAN destination standard message objects array */
    IfxMultican_Can_MsgObjConfig canMsgObjConfig;                  /* CAN message object configuration structure     */
    IfxMultican_Message txMsg;                                     /* Transmitted CAN message structure              */
    IfxMultican_Message rxMsg;                                     /* Received CAN messages structure                */
    uint8 txData[MAXIMUM_CAN_FD_DATA_PAYLOAD];                     /* Transmitted CAN data array                     */
    uint8 rxData[MAXIMUM_CAN_FD_DATA_PAYLOAD];                     /* Received CAN data array                        */
} multicanType;

typedef struct
{
    uint32  messageId : 29;                             /* Define the standard or extended message ID                */
    boolean extendedFrame : 1;                          /* Define frame mode to be used                              */
    IfxMultican_DataLengthCode messageLen : 4;          /* Define length of the transmitted data (number of bytes)   */
    boolean fastBitRate : 1;                            /* Define usage of bit rate switching                        */
} canMessageObjectConfigType;

typedef enum
{
    CanCommunicationStatus_Success = 0,
    CanCommunicationStatus_Error_noNewDataReceived,
    CanCommunicationStatus_Error_newDataButOneLost,
    CanCommunicationStatus_Error_notExpectedFifoCurPointer,
    CanCommunicationStatus_Error_notExpectedMessageId,
    CanCommunicationStatus_Error_notExpectedLengthCode,
    CanCommunicationStatus_Error_notExpectedFastBitrateValue,
    CanCommunicationStatus_Error_notExpectedData
} canCommunicationStatusType;

/*********************************************************************************************************************/
/*-------------------------------------------------Global variables--------------------------------------------------*/
/*********************************************************************************************************************/
IFX_EXTERN uint8 g_currentCanFdUseCase;
IFX_EXTERN canCommunicationStatusType g_status;
IFX_EXTERN IfxPort_Pin_Config g_led1;

/*********************************************************************************************************************/
/*-----------------------------------------------Function Prototypes-------------------------------------------------*/
/*********************************************************************************************************************/
void canIsrRxHandler(void);
void initMultican(void);
void initLed(void);
void transmitCanMessage(void);
void verifyCanMessage(void);

#endif /* MULTICAN_FD_H_ */
