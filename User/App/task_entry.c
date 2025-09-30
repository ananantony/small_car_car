/*
 * @File         : \User\App\Task_Entry.c
 * @Author       : menglingda@govyair.com
 * @Date         : 2025-09-28 17:17:35
 * @LastEditors  : mengmld@qq.com
 * @LastEditTime : 2025-09-30 15:23:56
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

#include "gpio.h"
#include "usart.h"
#include "tim.h"
#include "freertos.h"

void TaskEntry(void)
{
    // 驱动初始化
    MX_GPIO_Init();
    MX_USART1_UART_Init();
    MX_TIM2_Init();
    MX_TIM1_Init();
    MX_TIM5_Init();
    MX_TIM23_Init();
    MX_TIM24_Init();
    MX_USART2_UART_Init();
    // 初始化FreeRTOS
    osKernelInitialize();
    MX_FREERTOS_Init();
    osKernelStart();
}
