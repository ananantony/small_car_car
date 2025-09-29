/*
 * @File         : \User\Driver\led.h
 * @Author       : mengmld@qq.com
 * @Date         : 2025-09-13 12:29:19
 * @LastEditors  : mengmld@qq.com
 * @LastEditTime : 2025-09-13 15:48:20
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
#ifndef __LED_H__
#define __LED_H__

#include "common_define.h"

#define LED_ON  (1)
#define LED_OFF (0)

#define LED_PIN  GPIO_PIN_2
#define LED_PORT GPIOE

/**
 * @description: 板载led控制，对应端口低电平点亮
 * @param on_off LED_ON/LED_OFF
 * @return
 */
void Led_Ctrl(uint8_t on_off);

#endif /* __LED_H__ */
