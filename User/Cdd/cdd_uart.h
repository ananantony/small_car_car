/*
 * @File         : \User\Cdd\cdd_uart.h
 * @Author       : tony.meng
 * @Date         : 2025-09-29 15:43:32
 * @LastEditors  : mengmld@qq.com
 * @LastEditTime : 2025-09-29 17:14:09
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
#ifndef __CDD_UART_H__
#define __CDD_UART_H__

#include <stdio.h>
#include <stdarg.h>
#include "string.h"

#include "usart.h"

typedef struct
{
    UART_HandleTypeDef huart;
    uint8_t           *buffer;
    uint16_t           buffer_size;
    uint16_t           buffer_index;
} CddUart;

typedef enum
{
    UART_CHANNEL_LOG,
    UART_CHANNEL_CMD
} UartChannel;

typedef struct
{
    UartChannel         channel;
    UART_HandleTypeDef *huart;
    uint8_t             is_init;
    uint8_t             tx_busy;
    uint8_t             rx_busy;
} UartConfig;

#endif /* __CDD_UART_H__ */
