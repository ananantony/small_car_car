/*
 * @File         : \User\Driver\motor_ctrl\motor_ctrl.h
 * @Author       : mengmld@qq.com
 * @Date         : 2025-09-24 17:53:43
 * @LastEditors  : mengmld@qq.com
 * @LastEditTime : 2025-09-24 21:50:31
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
#ifndef __MOTOR_CTRL_H__
#define __MOTOR_CTRL_H__

#include "common_define.h"

typedef enum
{
    MOTOR_LF = 0,
    MOTOR_LR = 1,
    MOTOR_RF = 2,
    MOTOR_RR = 3,
    MOTOR_ID_MAX,
} MotorID_e;

#define MOTOR_MAX_SPEED 1000
#define MOTOR_MIN_SPEED 0

#endif /* __MOTOR_CTRL_H__ */
