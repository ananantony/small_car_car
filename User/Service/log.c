/*
 * @File         : \User\Service\log.c
 * @Author       : tony.meng
 * @Date         : 2025-09-29 15:15:44
 * @LastEditors  : mengmld@qq.com
 * @LastEditTime : 2025-09-30 15:04:16
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
#include "log.h"
#include "cdd_uart.h"

static MessageBufferHandle_t log_message_buffer;
static StaticMessageBuffer_t log_message_buffer_struct;
static uint8_t               log_buffer[LOG_QUEUE_SIZE];

static UartConfig *log_uart_config;

// ---------------- 内部函数 ----------------
static const char *GetLevelString(LogLevel level)
{
    switch (level)
    {
        case LOG_LEVEL_DEBUG:
            return "[DEBUG]";
        case LOG_LEVEL_INFO:
            return "[INFO]";
        case LOG_LEVEL_WARN:
            return "[WARN]";
        case LOG_LEVEL_ERROR:
            return "[ERROR]";
        default:
            return "[UNK]";
    }
}

void LogInit(void)
{
    log_message_buffer = xMessageBufferCreateStatic(sizeof(log_buffer), log_buffer, &log_message_buffer_struct);
    log_uart_config    = UartGetConfig(UART_CHANNEL_LOG);
}

void LogPrintf(LogLevel level, const char *func, int line, const char *fmt, ...)
{
    char    buf[LOG_MSG_BUF_SIZE];
    int     len;
    va_list args;

    uint32_t tick = 0;

    if (osKernelGetState() == osKernelRunning)
    {
        tick = osKernelGetTickCount();
    }

    const char *level_str = GetLevelString(level);
    len                   = snprintf(buf, sizeof(buf), "[%lu]%s[%s:%d] ", tick, level_str, func, line);

    va_start(args, fmt);
    len += vsnprintf(buf + len, sizeof(buf) - len, fmt, args);
    va_end(args);

    if (len > sizeof(buf) - 3)
    {
        len = sizeof(buf) - 3;
    }

    buf[len++] = '\r';
    buf[len++] = '\n';
    buf[len]   = '\0';

    if (osKernelGetState() == osKernelRunning)
    {
        size_t sent = xMessageBufferSend(log_message_buffer, buf, len, 0);
        if (sent < len)
        {
            log_uart_config->tx_lost_count++;
        }
    }
    else
    {
        HAL_UART_Transmit(log_uart_config->huart, (uint8_t *)buf, len, HAL_MAX_DELAY);
    }
}

static char msg_buffer[LOG_MSG_BUF_SIZE];
size_t      recv_len;

void LogServiceMainFunc(void)
{

    while ((recv_len = xMessageBufferReceive(log_message_buffer, msg_buffer, sizeof(msg_buffer), 0)) > 0)
    {
        HAL_UART_Transmit_IT(log_uart_config->huart, (uint8_t *)msg_buffer, recv_len);
        log_uart_config->tx_busy = 1;
        while (log_uart_config->tx_busy)
        {
            osDelay(pdMS_TO_TICKS(1)); // 等待中断回调清忙
        }
    }
}
