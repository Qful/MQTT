/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * File Name          : freertos.c
  * Description        : Code for freertos applications
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2019 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
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
osThreadId sys_watcherHandle;
osThreadId flash_serverHandle;
osThreadId serial_serverHandle;
osThreadId sys_coreHandle;
osThreadId tcm300_serverHandle;
osThreadId web_serverHandle;
osMessageQId serial_queueHandle;
osMessageQId flash_queueHandle;
osMessageQId tcm300_tx_queueHandle;

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */

/* USER CODE END FunctionPrototypes */

void sys_watcher_function(void const * argument);
void flash_server_function(void const * argument);
void serial_server_function(void const * argument);
void sys_core_function(void const * argument);
void tcm300_tx_server(void const * argument);
void web_server_function(void const * argument);

void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

/* Hook prototypes */
void vApplicationIdleHook(void);
void vApplicationTickHook(void);

/* USER CODE BEGIN 2 */

/* USER CODE END 2 */

/* USER CODE BEGIN 3 */

/* USER CODE END 3 */

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

  /* Create the queue(s) */
  /* definition and creation of serial_queue */
  osMessageQDef(serial_queue, 8, uint32_t);
  serial_queueHandle = osMessageCreate(osMessageQ(serial_queue), NULL);

  /* definition and creation of flash_queue */
  osMessageQDef(flash_queue, 5, uint32_t);
  flash_queueHandle = osMessageCreate(osMessageQ(flash_queue), NULL);

  /* definition and creation of tcm300_tx_queue */
  osMessageQDef(tcm300_tx_queue, 8, uint32_t);
  tcm300_tx_queueHandle = osMessageCreate(osMessageQ(tcm300_tx_queue), NULL);

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */
  /* definition and creation of sys_watcher */
  osThreadDef(sys_watcher, sys_watcher_function, osPriorityNormal, 0, 200);
  sys_watcherHandle = osThreadCreate(osThread(sys_watcher), NULL);

  /* definition and creation of flash_server */
  osThreadDef(flash_server, flash_server_function, osPriorityAboveNormal, 0, 600);
  flash_serverHandle = osThreadCreate(osThread(flash_server), NULL);

  /* definition and creation of serial_server */
  osThreadDef(serial_server, serial_server_function, osPriorityHigh, 0, 400);
  serial_serverHandle = osThreadCreate(osThread(serial_server), NULL);

  /* definition and creation of sys_core */
  osThreadDef(sys_core, sys_core_function, osPriorityAboveNormal, 0, 300);
  sys_coreHandle = osThreadCreate(osThread(sys_core), NULL);

  /* definition and creation of tcm300_server */
  osThreadDef(tcm300_server, tcm300_tx_server, osPriorityHigh, 0, 300);
  tcm300_serverHandle = osThreadCreate(osThread(tcm300_server), NULL);

  /* definition and creation of web_server */
  osThreadDef(web_server, web_server_function, osPriorityAboveNormal, 0, 300);
  web_serverHandle = osThreadCreate(osThread(web_server), NULL);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

}

/* USER CODE BEGIN Header_sys_watcher_function */
/**
  * @brief  Function implementing the sys_watcher thread.
  * @param  argument: Not used 
  * @retval None
  */
/* USER CODE END Header_sys_watcher_function */
void sys_watcher_function(void const * argument)
{

  /* USER CODE BEGIN sys_watcher_function */
  InitW5500();
  osDelay(1000);
  vStartMQTTTasks(400,osPriorityAboveNormal);
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END sys_watcher_function */
}

/* USER CODE BEGIN Header_flash_server_function */
/**
* @brief Function implementing the flash_server thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_flash_server_function */
void flash_server_function(void const * argument)
{
  /* USER CODE BEGIN flash_server_function */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END flash_server_function */
}

/* USER CODE BEGIN Header_serial_server_function */
/**
* @brief Function implementing the serial_server thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_serial_server_function */
void serial_server_function(void const * argument)
{
  /* USER CODE BEGIN serial_server_function */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END serial_server_function */
}

/* USER CODE BEGIN Header_sys_core_function */
/**
* @brief Function implementing the sys_core thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_sys_core_function */
void sys_core_function(void const * argument)
{
  /* USER CODE BEGIN sys_core_function */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END sys_core_function */
}

/* USER CODE BEGIN Header_tcm300_tx_server */
/**
* @brief Function implementing the tcm300_server thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_tcm300_tx_server */
void tcm300_tx_server(void const * argument)
{
  /* USER CODE BEGIN tcm300_tx_server */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END tcm300_tx_server */
}

/* USER CODE BEGIN Header_web_server_function */
/**
* @brief Function implementing the web_server thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_web_server_function */
void web_server_function(void const * argument)
{
  /* USER CODE BEGIN web_server_function */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END web_server_function */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */
     
/* USER CODE END Application */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
