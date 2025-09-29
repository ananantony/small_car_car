/*
 * @File         : \User\Cdd\Log\log.h
 * @Author       : tony.meng
 * @Date         : 2025-09-29 15:15:52
 * @LastEditors  : mengmld@qq.com
 * @LastEditTime : 2025-09-29 15:21:08
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
#ifndef __LOG_H__
#define __LOG_H__

#include "common_define.h"
#include "cmsis_os2.h"
#include "usart.h"
#include "message_buffer.h"

#define LOG_MSG_BUF_SIZE 128  // 单条日志最大长度
#define LOG_QUEUE_SIZE   2048 // Message Buffer 容量

typedef enum
{
    LOG_LEVEL_DEBUG,
    LOG_LEVEL_INFO,
    LOG_LEVEL_WARN,
    LOG_LEVEL_ERROR
} LogLevel;

void Log_Init(void);
void Log_Task(void *argument);
void Log_Printf(const char *func, int line, const char *fmt, ...);

#define LOGD(fmt, ...) Log_Printf(__FUNCTION__, __LINE__, "[DEBUG] " fmt, ##__VA_ARGS__)
#define LOGI(fmt, ...) Log_Printf(__FUNCTION__, __LINE__, "[INFO] " fmt, ##__VA_ARGS__)
#define LOGW(fmt, ...) Log_Printf(__FUNCTION__, __LINE__, "[WARN] " fmt, ##__VA_ARGS__)
#define LOGE(fmt, ...) Log_Printf(__FUNCTION__, __LINE__, "[ERROR] " fmt, ##__VA_ARGS__)

#endif /* __LOG_H__ */
