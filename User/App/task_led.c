/*
 * @File         : \User\Task\Task_Led.c
 * @Author       : menglingda@govyair.com
 * @Date         : 2025-09-28 16:50:16
 * @LastEditors  : mengmld@qq.com
 * @LastEditTime : 2025-09-29 15:10:01
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
#include "Led.h"
void TaskLedEntry(void *argument)
{
    const uint32_t period_ticks   = pdMS_TO_TICKS(TASK_LED_PERIOD_MS); // 10 ms
    uint32_t       next_wake_tick = osKernelGetTickCount();
    while (1)
    {
        



        next_wake_tick += period_ticks;
        if (osDelayUntil(next_wake_tick) != osOK)
        {
            // 错误处理：周期过长或者被误调用
        }
    }
}
