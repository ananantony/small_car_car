/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * File Name          : freertos.c
  * Description        : Code for freertos applications
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "cmsis_os.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN Variables */

/* USER CODE END Variables */
/* Definitions for Task_Safety */
osThreadId_t Task_SafetyHandle;
const osThreadAttr_t Task_Safety_attributes = {
  .name = "Task_Safety",
  .stack_size = 512 * 4,
  .priority = (osPriority_t) osPriorityHigh7,
};
/* Definitions for Task_Led */
osThreadId_t Task_LedHandle;
const osThreadAttr_t Task_Led_attributes = {
  .name = "Task_Led",
  .stack_size = 512 * 4,
  .priority = (osPriority_t) osPriorityNormal,
};
/* Definitions for Task_Encoder */
osThreadId_t Task_EncoderHandle;
const osThreadAttr_t Task_Encoder_attributes = {
  .name = "Task_Encoder",
  .stack_size = 512 * 4,
  .priority = (osPriority_t) osPriorityHigh6,
};
/* Definitions for Task_Ctrl */
osThreadId_t Task_CtrlHandle;
const osThreadAttr_t Task_Ctrl_attributes = {
  .name = "Task_Ctrl",
  .stack_size = 1024 * 4,
  .priority = (osPriority_t) osPriorityHigh6,
};
/* Definitions for Task_Comm */
osThreadId_t Task_CommHandle;
const osThreadAttr_t Task_Comm_attributes = {
  .name = "Task_Comm",
  .stack_size = 2048 * 4,
  .priority = (osPriority_t) osPriorityHigh5,
};
/* Definitions for Task_Calculate */
osThreadId_t Task_CalculateHandle;
const osThreadAttr_t Task_Calculate_attributes = {
  .name = "Task_Calculate",
  .stack_size = 2048 * 4,
  .priority = (osPriority_t) osPriorityHigh4,
};
/* Definitions for Task_Log */
osThreadId_t Task_LogHandle;
const osThreadAttr_t Task_Log_attributes = {
  .name = "Task_Log",
  .stack_size = 2048 * 4,
  .priority = (osPriority_t) osPriorityHigh2,
};
/* Definitions for Task_Sensor */
osThreadId_t Task_SensorHandle;
const osThreadAttr_t Task_Sensor_attributes = {
  .name = "Task_Sensor",
  .stack_size = 2048 * 4,
  .priority = (osPriority_t) osPriorityHigh3,
};

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */

/* USER CODE END FunctionPrototypes */

void Task_Safety_Entry(void *argument);
void Task_Led_Entry(void *argument);
void Task_Encoder_Entry(void *argument);
void Task_Ctrl_Entry(void *argument);
void Task_Comm_Entry(void *argument);
void Task_Calculate_Entry(void *argument);
void Task_Log_Entry(void *argument);
void Task_Sensor_Entry(void *argument);

void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

/**
  * @brief  FreeRTOS initialization
  * @param  None
  * @retval None
  */
void MX_FREERTOS_Init(void) {
  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */
  /* creation of Task_Safety */
  Task_SafetyHandle = osThreadNew(Task_Safety_Entry, NULL, &Task_Safety_attributes);

  /* creation of Task_Led */
  Task_LedHandle = osThreadNew(Task_Led_Entry, NULL, &Task_Led_attributes);

  /* creation of Task_Encoder */
  Task_EncoderHandle = osThreadNew(Task_Encoder_Entry, NULL, &Task_Encoder_attributes);

  /* creation of Task_Ctrl */
  Task_CtrlHandle = osThreadNew(Task_Ctrl_Entry, NULL, &Task_Ctrl_attributes);

  /* creation of Task_Comm */
  Task_CommHandle = osThreadNew(Task_Comm_Entry, NULL, &Task_Comm_attributes);

  /* creation of Task_Calculate */
  Task_CalculateHandle = osThreadNew(Task_Calculate_Entry, NULL, &Task_Calculate_attributes);

  /* creation of Task_Log */
  Task_LogHandle = osThreadNew(Task_Log_Entry, NULL, &Task_Log_attributes);

  /* creation of Task_Sensor */
  Task_SensorHandle = osThreadNew(Task_Sensor_Entry, NULL, &Task_Sensor_attributes);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

  /* USER CODE BEGIN RTOS_EVENTS */
  /* add events, ... */
  /* USER CODE END RTOS_EVENTS */

}

/* USER CODE BEGIN Header_Task_Safety_Entry */
/**
  * @brief  Function implementing the Task_Safety thread.
  * @param  argument: Not used
  * @retval None
  */
/* USER CODE END Header_Task_Safety_Entry */
__weak void Task_Safety_Entry(void *argument)
{
  /* USER CODE BEGIN Task_Safety_Entry */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END Task_Safety_Entry */
}

/* USER CODE BEGIN Header_Task_Led_Entry */
/**
* @brief Function implementing the Task_Led thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_Task_Led_Entry */
__weak void Task_Led_Entry(void *argument)
{
  /* USER CODE BEGIN Task_Led_Entry */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END Task_Led_Entry */
}

/* USER CODE BEGIN Header_Task_Encoder_Entry */
/**
* @brief Function implementing the Task_Encoder thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_Task_Encoder_Entry */
__weak void Task_Encoder_Entry(void *argument)
{
  /* USER CODE BEGIN Task_Encoder_Entry */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END Task_Encoder_Entry */
}

/* USER CODE BEGIN Header_Task_Ctrl_Entry */
/**
* @brief Function implementing the Task_Ctrl thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_Task_Ctrl_Entry */
__weak void Task_Ctrl_Entry(void *argument)
{
  /* USER CODE BEGIN Task_Ctrl_Entry */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END Task_Ctrl_Entry */
}

/* USER CODE BEGIN Header_Task_Comm_Entry */
/**
* @brief Function implementing the Task_Comm thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_Task_Comm_Entry */
__weak void Task_Comm_Entry(void *argument)
{
  /* USER CODE BEGIN Task_Comm_Entry */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END Task_Comm_Entry */
}

/* USER CODE BEGIN Header_Task_Calculate_Entry */
/**
* @brief Function implementing the Task_Calculate thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_Task_Calculate_Entry */
__weak void Task_Calculate_Entry(void *argument)
{
  /* USER CODE BEGIN Task_Calculate_Entry */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END Task_Calculate_Entry */
}

/* USER CODE BEGIN Header_Task_Log_Entry */
/**
* @brief Function implementing the Task_Log thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_Task_Log_Entry */
__weak void Task_Log_Entry(void *argument)
{
  /* USER CODE BEGIN Task_Log_Entry */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END Task_Log_Entry */
}

/* USER CODE BEGIN Header_Task_Sensor_Entry */
/**
* @brief Function implementing the Task_Sensor thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_Task_Sensor_Entry */
__weak void Task_Sensor_Entry(void *argument)
{
  /* USER CODE BEGIN Task_Sensor_Entry */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END Task_Sensor_Entry */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */

/* USER CODE END Application */

