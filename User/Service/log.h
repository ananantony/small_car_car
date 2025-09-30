/*
 * @File         : \User\Service\log.h
 * @Author       : tony.meng
 * @Date         : 2025-09-29 15:15:52
 * @LastEditors  : mengmld@qq.com
 * @LastEditTime : 2025-09-30 15:04:23
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

void LogInit(void);
void LogPrintf(LogLevel level, const char *func, int line, const char *fmt, ...);
void LogServiceMainFunc(void);

#define LOG_DEBUG(fmt, ...) LogPrintf(LOG_LEVEL_DEBUG, __FUNCTION__, __LINE__, "[DEBUG] " fmt, ##__VA_ARGS__)
#define LOG_INFO(fmt, ...)  LogPrintf(LOG_LEVEL_INFO, __FUNCTION__, __LINE__, "[INFO] " fmt, ##__VA_ARGS__)
#define LOG_WARN(fmt, ...)  LogPrintf(LOG_LEVEL_WARN, __FUNCTION__, __LINE__, "[WARN] " fmt, ##__VA_ARGS__)
#define LOG_ERROR(fmt, ...) LogPrintf(LOG_LEVEL_ERROR, __FUNCTION__, __LINE__, "[ERROR] " fmt, ##__VA_ARGS__)

#endif /* __LOG_H__ */
