/*
 * @File         : \User\Task\Task_Led.c
 * @Author       : menglingda@govyair.com
 * @Date         : 2025-09-28 16:50:16
 * @LastEditors  : menglingda@govyair.com
 * @LastEditTime : 2025-09-28 17:40:29
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
void Task_Safety_Entry(void *argument)
{
    const uint32_t period_ticks   = Ms_To_Os_Tick(TASK_LED_PERIOD_MS); // 10 ms
    uint32_t       next_wake_tick = osKernelGetTickCount();
    for (;;)
    {
        next_wake_tick += period_ticks;

        // 阻塞直到下一个周期
        if (osDelayUntil(next_wake_tick) != osOK)
        {
            // 错误处理：周期过长或者被误调用
        }
    }
    /* USER CODE END Task_Safety_Entry */
}
