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
/* Definitions for TaskSafety */
osThreadId_t TaskSafetyHandle;
const osThreadAttr_t TaskSafety_attributes = {
  .name = "TaskSafety",
  .stack_size = 512 * 4,
  .priority = (osPriority_t) osPriorityHigh7,
};
/* Definitions for TaskLed */
osThreadId_t TaskLedHandle;
const osThreadAttr_t TaskLed_attributes = {
  .name = "TaskLed",
  .stack_size = 512 * 4,
  .priority = (osPriority_t) osPriorityNormal,
};
/* Definitions for TaskEncoder */
osThreadId_t TaskEncoderHandle;
const osThreadAttr_t TaskEncoder_attributes = {
  .name = "TaskEncoder",
  .stack_size = 512 * 4,
  .priority = (osPriority_t) osPriorityHigh6,
};
/* Definitions for TaskCtrl */
osThreadId_t TaskCtrlHandle;
const osThreadAttr_t TaskCtrl_attributes = {
  .name = "TaskCtrl",
  .stack_size = 1024 * 4,
  .priority = (osPriority_t) osPriorityHigh6,
};
/* Definitions for TaskComm */
osThreadId_t TaskCommHandle;
const osThreadAttr_t TaskComm_attributes = {
  .name = "TaskComm",
  .stack_size = 2048 * 4,
  .priority = (osPriority_t) osPriorityHigh5,
};
/* Definitions for TaskCalculate */
osThreadId_t TaskCalculateHandle;
const osThreadAttr_t TaskCalculate_attributes = {
  .name = "TaskCalculate",
  .stack_size = 2048 * 4,
  .priority = (osPriority_t) osPriorityHigh4,
};
/* Definitions for TaskLog */
osThreadId_t TaskLogHandle;
const osThreadAttr_t TaskLog_attributes = {
  .name = "TaskLog",
  .stack_size = 2048 * 4,
  .priority = (osPriority_t) osPriorityHigh2,
};
/* Definitions for Task_ensor */
osThreadId_t Task_ensorHandle;
const osThreadAttr_t Task_ensor_attributes = {
  .name = "Task_ensor",
  .stack_size = 2048 * 4,
  .priority = (osPriority_t) osPriorityHigh3,
};

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */

/* USER CODE END FunctionPrototypes */

void TaskSafetyEntry(void *argument);
void TaskLedEntry(void *argument);
void TaskEncoderEntry(void *argument);
void TaskCtrlEntry(void *argument);
void TaskCommEntry(void *argument);
void TaskCalculateEntry(void *argument);
void TaskLogEntry(void *argument);
void TaskSensorEntry(void *argument);

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
  /* creation of TaskSafety */
  TaskSafetyHandle = osThreadNew(TaskSafetyEntry, NULL, &TaskSafety_attributes);

  /* creation of TaskLed */
  TaskLedHandle = osThreadNew(TaskLedEntry, NULL, &TaskLed_attributes);

  /* creation of TaskEncoder */
  TaskEncoderHandle = osThreadNew(TaskEncoderEntry, NULL, &TaskEncoder_attributes);

  /* creation of TaskCtrl */
  TaskCtrlHandle = osThreadNew(TaskCtrlEntry, NULL, &TaskCtrl_attributes);

  /* creation of TaskComm */
  TaskCommHandle = osThreadNew(TaskCommEntry, NULL, &TaskComm_attributes);

  /* creation of TaskCalculate */
  TaskCalculateHandle = osThreadNew(TaskCalculateEntry, NULL, &TaskCalculate_attributes);

  /* creation of TaskLog */
  TaskLogHandle = osThreadNew(TaskLogEntry, NULL, &TaskLog_attributes);

  /* creation of Task_ensor */
  Task_ensorHandle = osThreadNew(TaskSensorEntry, NULL, &Task_ensor_attributes);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

  /* USER CODE BEGIN RTOS_EVENTS */
  /* add events, ... */
  /* USER CODE END RTOS_EVENTS */

}

/* USER CODE BEGIN Header_TaskSafetyEntry */
/**
  * @brief  Function implementing the TaskSafety thread.
  * @param  argument: Not used
  * @retval None
  */
/* USER CODE END Header_TaskSafetyEntry */
__weak void TaskSafetyEntry(void *argument)
{
  /* USER CODE BEGIN TaskSafetyEntry */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END TaskSafetyEntry */
}

/* USER CODE BEGIN Header_TaskLedEntry */
/**
* @brief Function implementing the TaskLed thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_TaskLedEntry */
__weak void TaskLedEntry(void *argument)
{
  /* USER CODE BEGIN TaskLedEntry */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END TaskLedEntry */
}

/* USER CODE BEGIN Header_TaskEncoderEntry */
/**
* @brief Function implementing the TaskEncoder thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_TaskEncoderEntry */
__weak void TaskEncoderEntry(void *argument)
{
  /* USER CODE BEGIN TaskEncoderEntry */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END TaskEncoderEntry */
}

/* USER CODE BEGIN Header_TaskCtrlEntry */
/**
* @brief Function implementing the TaskCtrl thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_TaskCtrlEntry */
__weak void TaskCtrlEntry(void *argument)
{
  /* USER CODE BEGIN TaskCtrlEntry */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END TaskCtrlEntry */
}

/* USER CODE BEGIN Header_TaskCommEntry */
/**
* @brief Function implementing the TaskComm thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_TaskCommEntry */
__weak void TaskCommEntry(void *argument)
{
  /* USER CODE BEGIN TaskCommEntry */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END TaskCommEntry */
}

/* USER CODE BEGIN Header_TaskCalculateEntry */
/**
* @brief Function implementing the TaskCalculate thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_TaskCalculateEntry */
__weak void TaskCalculateEntry(void *argument)
{
  /* USER CODE BEGIN TaskCalculateEntry */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END TaskCalculateEntry */
}

/* USER CODE BEGIN Header_TaskLogEntry */
/**
* @brief Function implementing the TaskLog thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_TaskLogEntry */
__weak void TaskLogEntry(void *argument)
{
  /* USER CODE BEGIN TaskLogEntry */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END TaskLogEntry */
}

/* USER CODE BEGIN Header_TaskSensorEntry */
/**
* @brief Function implementing the Task_ensor thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_TaskSensorEntry */
__weak void TaskSensorEntry(void *argument)
{
  /* USER CODE BEGIN TaskSensorEntry */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END TaskSensorEntry */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */

/* USER CODE END Application */

