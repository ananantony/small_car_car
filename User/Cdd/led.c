/*
 * @File         : \User\Driver\led\led.c
 * @Author       : mengmld@qq.com
 * @Date         : 2025-09-13 12:26:21
 * @LastEditors  : menglingda@govyair.com
 * @LastEditTime : 2025-09-28 17:09:00
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
#include "led.h"

/**
 * @description: 板载led控制，对应端口低电平点亮
 * @param on_off LED_ON/LED_OFF
 * @return
 */
void Led_Ctrl(uint8_t on_off)
{
    if (LED_ON == on_off)
    {
        HAL_GPIO_WritePin(LED_PORT, LED_PIN, GPIO_PIN_RESET);
    }
    else
    {
        HAL_GPIO_WritePin(LED_PORT, LED_PIN, GPIO_PIN_SET);
    }
}
