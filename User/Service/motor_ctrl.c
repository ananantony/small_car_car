/*
 * @File         : \User\Driver\motor_ctrl\motor_ctrl.c
 * @Author       : mengmld@qq.com
 * @Date         : 2025-09-24 17:53:33
 * @LastEditors  : mengmld@qq.com
 * @LastEditTime : 2025-09-24 22:01:35
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
#include "motor_ctrl.h"
#include "stm32h7xx_hal_tim.h"
#include "tim.h"
#include "gpio.h"

#define CYCLE_CONUT (2496) // 编码器每转一圈的脉冲数 13x48x4=2496

typedef struct
{
    uint16_t           id;
    TIM_HandleTypeDef *pwm;
    uint32_t           channel;
    TIM_HandleTypeDef *encoder;
} MotorCfg_t;

MotorCfg_t motor_cfg[] = {
    {.id = MOTOR_LF, .pwm = &htim1, .channel = TIM_CHANNEL_1,  .encoder = &htim2},
    {.id = MOTOR_LR, .pwm = &htim1, .channel = TIM_CHANNEL_2,  .encoder = &htim5},
    {.id = MOTOR_RF, .pwm = &htim1, .channel = TIM_CHANNEL_3, .encoder = &htim23},
    {.id = MOTOR_RR, .pwm = &htim1, .channel = TIM_CHANNEL_4, .encoder = &htim24},
};
void InitMotor(void)
{
    // PWM初始化
    MX_TIM1_Init();

    // 编码器初始化
    MX_TIM2_Init();
    MX_TIM5_Init();
    MX_TIM23_Init();
    MX_TIM24_Init();

    for (uint8_t i = 0; i < sizeof(motor_cfg) / sizeof(MotorCfg_t); i++)
    {
        HAL_TIM_PWM_Start(motor_cfg[i].pwm, motor_cfg[i].channel);
        HAL_TIM_Encoder_Start(motor_cfg[i].encoder, TIM_CHANNEL_ALL);
    }
}

void SetMotorSpeed(MotorID_e id, uint16_t speed)
{
    if (id >= MOTOR_ID_MAX)
    {
        return;
    }
    if (speed > MOTOR_MAX_SPEED)
    {
        speed = MOTOR_MAX_SPEED;
    }
    __HAL_TIM_SET_COMPARE(motor_cfg[id].pwm, motor_cfg[id].channel, speed);
}

uint32_t GetEncoderCount(MotorID_e id)
{
    if (id >= MOTOR_ID_MAX)
    {
        return 0;
    }
    return __HAL_TIM_GET_COUNTER(motor_cfg[id].encoder);
}
