/*
 * @File         : \User\App\Task_Entry.h
 * @Author       : menglingda@govyair.com
 * @Date         : 2025-09-28 16:52:23
 * @LastEditors  : mengmld@qq.com
 * @LastEditTime : 2025-09-30 15:05:31
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
#ifndef __TASK_ENTRY_H__
#define __TASK_ENTRY_H__
#include "common_define.h"

#include "FreeRTOS.h"
#include "task.h"
#include "cmsis_os2.h"

// 时间驱动型
#define TASK_COMM_PERIOD_MS      (1000)
#define TASK_SAFETY_PERIOD_MS    (1000)
// 周期型
#define TASK_SENSOR_PERIOD_MS    (50)
#define TASK_LOG_PERIOD_MS       (50)
#define TASK_LED_PERIOD_MS       (100)
#define TASK_ENCODER_PERIOD_MS   (10)
#define TASK_CTRL_PERIOD_MS      (10)
#define TASK_CALCULATE_PERIOD_MS (10)

void TaskEntry(void);
#endif /* __TASK_ENTRY_H__ */
