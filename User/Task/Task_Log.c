/*
 * @File         : \User\Task\Task_Log.c
 * @Author       : tony.meng
 * @Date         : 2025-09-28 16:51:12
 * @LastEditors  : mengmld@qq.com
 * @LastEditTime : 2025-09-29 15:56:43
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
#include "Task_Entry.h"
#include "message_buffer.h"
#include "semphr.h"
#include "usart.h"

#define LOG_MSG_BUF_SIZE 128      // 单条日志最大长度
#define LOG_QUEUE_SIZE   1024 * 4 // Message Buffer 容量

static MessageBufferHandle_t log_message_buffer;
static StaticMessageBuffer_t log_message_buffer_struct;
static uint8_t               log_buffer[LOG_QUEUE_SIZE];

void Task_Log_Entry(void *argument)
{
    const uint32_t period_ticks   = Ms_To_Os_Tick(TASK_LOG_PERIOD_MS); // 10 ms
    uint32_t       next_wake_tick = osKernelGetTickCount();

    log_message_buffer = xMessageBufferCreateStatic(sizeof(log_buffer), log_buffer, &log_message_buffer_struct);
    for (;;)
    {
        next_wake_tick += period_ticks;

        // 阻塞直到下一个周期
        if (osDelayUntil(next_wake_tick) != osOK)
        {
            // 错误处理：周期过长或者被误调用
        }
    }
}
