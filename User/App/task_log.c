/*
 * @File         : \User\App\Task_Log.c
 * @Author       : tony.meng
 * @Date         : 2025-09-28 16:51:12
 * @LastEditors  : mengmld@qq.com
 * @LastEditTime : 2025-09-30 15:05:20
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

#include "task_entry.h"
#include "log.h"

void TaskLogEntry(void *argument)
{
    const uint32_t period_ticks   = pdMS_TO_TICKS(TASK_LOG_PERIOD_MS);
    uint32_t       next_wake_tick = osKernelGetTickCount();

    while (1)
    {

        LogServiceMainFunc();

        // 阻塞直到下一个周期
        next_wake_tick += period_ticks;
        if (osDelayUntil(next_wake_tick) != osOK)
        {
            // 错误处理：周期过长或者被误调用
        }
    }
}
