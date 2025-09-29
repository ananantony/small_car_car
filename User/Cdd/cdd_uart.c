/*
 * @File         : \User\Cdd\cdd_uart.c
 * @Author       : tony.meng
 * @Date         : 2025-09-29 15:43:18
 * @LastEditors  : mengmld@qq.com
 * @LastEditTime : 2025-09-29 17:15:16
 * @Description  :
 *
 * Copyright (c) 2025 by tony.meng, All Rights Reserved.
 *
 *   _________________________________________________________________________
 *  | Date       | Version | Author      |  Description                       |
 *  |=========================================================================|
 *  |            |         |             |                                    |
 *  |-------------------------------------------------------------------------|
 *  |            |         |             |                                    |
 *  |-------------------------------------------------------------------------|
 */
#include "cdd_uart.h"

UartConfig uart_config[] = {
    {
     .channel = UART_CHANNEL_LOG,
     .huart   = &huart1,
     .is_init = 0,
     .tx_busy = 0,
     .rx_busy = 0,

     },

    {
     .channel = UART_CHANNEL_CMD,
     .huart   = &huart2,
     .is_init = 0,
     .tx_busy = 0,
     .rx_busy = 0,
     }
};

void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart)
{
    if (huart->Instance == USART1)
    {
        uart_config[UART_CHANNEL_LOG].tx_busy = 0;
    }
}

UartConfig *UartGetConfig(UartChannel channel)
{
    return &uart_config[channel];
}
