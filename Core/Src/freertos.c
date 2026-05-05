/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * File Name          : freertos.c
 * Description        : Code for freertos applications
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2024 STMicroelectronics.
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
#include "usart.h"

#include "bsp_st7789_driver.h"
#include "st7789_reg_define.h"
#include "bsp_st7789_link.h"
#include "fonts.h"
#include "bsp_cst816t_driver.h"
#include "bsp_cst816t_link.h"
#include "lvgl.h"
#include "lvgl/examples/porting/lv_port_disp_template.h"
#include "lvgl/examples/porting/lv_port_indev_template.h"
#include "gui_guider.h"
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
bsp_st7789_driver_t st7789_driver_instance;
basic_oper_driver_interface_t st7789_oper_instance = {
  .pf_spi_transmit = spi_transmit_data,
  .pf_spi_transmit_dma = spi_transmit_data_dma,
  .pf_write_cs_pin = gpio_write_cs_pin,
  .pf_write_dc_pin = gpio_write_dc_pin,
  .pf_write_reset_pin = gpio_write_reset_pin
};

st7789_spi_driver_interface_t st7789_spi_instance;

st7789_timebase_interface_t st7789_time_instance = {
  .pf_delay_no_os = HAL_Delay,
  .pf_get_tick_count = HAL_GetTick
};

st7789_yield_interface_t st7789_yield = {
  .pf_rtos_yield = vTaskDelay
};
bsp_cst816t_driver_t cst816t_driver_instance;

timebase_interface_t g_timebase_instance = {
    .pf_get_tick_count = HAL_GetTick,
};

yield_interface_t g_yield_instance = {
    .pf_rtos_yield = vTaskDelay,
};

iic_driver_interface_t g_iic_driver_instance = {
    .hi2c = &hi2c3,
    .pf_iic_init         = iic_driver_init,
    .pf_iic_deinit       = iic_driver_deinit,
    .pf_iic_mem_write    = iic_mem_write,
    .pf_iic_mem_read     = iic_mem_read,
    .pf_iic_mem_read_dma = iic_mem_read_dma,
};

gpio_opt_interface_t gpio_opt_instance = {
    .pf_write_reset_pin = gpio_opt_write_reset_pin,
};

void (*pf_int_interrupt_callback)(void *, void *) = NULL;

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
    log_i("HAL_GPIO_EXTI_Callback");
    if (GPIO_Pin == GPIO_PIN_2 && pf_int_interrupt_callback != NULL)
    {
        cst816_xy_t cst816_xy;
        pf_int_interrupt_callback(&cst816t_driver_instance, &cst816_xy);
    }
}
lv_ui guider_ui;
/* USER CODE END Variables */
/* Definitions for defaultTask */
osThreadId_t defaultTaskHandle;
const osThreadAttr_t defaultTask_attributes = {
  .name = "defaultTask",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityNormal,
};
/* Definitions for LVGLTask */
osThreadId_t LVGLTaskHandle;
const osThreadAttr_t LVGLTask_attributes = {
  .name = "LVGLTask",
  .stack_size = 1024 * 4,
  .priority = (osPriority_t) osPriorityLow2,
};

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */
void system_init(void);
void touch_test(void);

/* USER CODE END FunctionPrototypes */

void StartDefaultTask(void *argument);
void LVGLTask_event(void *argument);

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
  /* creation of defaultTask */
  defaultTaskHandle = osThreadNew(StartDefaultTask, NULL, &defaultTask_attributes);

  /* creation of LVGLTask */
  LVGLTaskHandle = osThreadNew(LVGLTask_event, NULL, &LVGLTask_attributes);

  /* USER CODE BEGIN RTOS_THREADS */
	/* add threads, ... */
	xTaskCreate((TaskFunction_t)system_init, "system_init", 1024, NULL, osPriorityNormal1, NULL);
	//xTaskCreate((TaskFunction_t)touch_test, "touch_test", 1024, NULL, osPriorityNormal, NULL);
  /* USER CODE END RTOS_THREADS */

  /* USER CODE BEGIN RTOS_EVENTS */
	/* add events, ... */
  /* USER CODE END RTOS_EVENTS */

}

/* USER CODE BEGIN Header_StartDefaultTask */
/**
 * @brief  Function implementing the defaultTask thread.
 * @param  argument: Not used
 * @retval None
 */
/* USER CODE END Header_StartDefaultTask */
void StartDefaultTask(void *argument)
{
  /* USER CODE BEGIN StartDefaultTask */
	/* Infinite loop */
	for (;;)
	{
		log_i("StartDefaultTask\r\n");
		osDelay(1000);
	}
  /* USER CODE END StartDefaultTask */
}

/* USER CODE BEGIN Header_LVGLTask_event */
/**
* @brief Function implementing the LVGLTask thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_LVGLTask_event */
void LVGLTask_event(void *argument)
{
  /* USER CODE BEGIN LVGLTask_event */
  /* Infinite loop */
 while (1)
 {
  lv_task_handler();
  osDelay(3);
 }
 
  /* USER CODE END LVGLTask_event */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */
void system_init(void)
{
	log_i("==========system init start==========\r\n");

	for (;;)
	{
		st7789_instance_driver_link(&st7789_driver_instance,
									&st7789_oper_instance,
									&st7789_spi_instance,
									&st7789_time_instance,
									&st7789_yield);
		st7789_driver_instance.pf_st7789_init(&st7789_driver_instance);
		
		bsp_cst816t_inst(&cst816t_driver_instance,
						 &g_timebase_instance,
#ifdef OS_SUPPORTING
						 &g_yield_instance,
#endif /* OS_SUPPORTING */
						 &g_iic_driver_instance,
						 &gpio_opt_instance,
						 &pf_int_interrupt_callback);
		
		// test the display device
		//st7789_driver_instance.pf_test_your_device(&st7789_driver_instance);
		
    //lvgl init 
    lv_init();
    lv_port_disp_init();
    lv_port_indev_init();

    setup_ui(&guider_ui);

		vTaskDelete(NULL);
	}
}

void touch_test(void)
{
	log_i("touch_test\r\n");
	cst816_xy_t cst816_xy;

	for (;;)
	{
		cst816t_driver_instance.pf_cst816_get_xy_axis(&cst816t_driver_instance, &cst816_xy);
		// log_i("touch_test: x = %d, y = %d\r\n", cst816_xy.x_pos, cst816_xy.y_pos);
		osDelay(100);
	}
}
/* USER CODE END Application */

