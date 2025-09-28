/*
 * @File         : \User\Utils\common_utils.c
 * @Author       : menglingda@govyair.com
 * @Date         : 2025-09-28 17:34:43
 * @LastEditors  : menglingda@govyair.com
 * @LastEditTime : 2025-09-28 17:40:09
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
#include "common_utils.h"

void Ms_To_Os_Tick(uint32_t ms)
{
    return ms * osKernelGetTickFreq() / 1000;
}
