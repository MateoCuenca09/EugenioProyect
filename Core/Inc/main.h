/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define PC1_Pin GPIO_PIN_1
#define PC1_GPIO_Port GPIOC
#define PC3_Pin GPIO_PIN_3
#define PC3_GPIO_Port GPIOC
#define PA1_Pin GPIO_PIN_1
#define PA1_GPIO_Port GPIOA
#define PA3_Pin GPIO_PIN_3
#define PA3_GPIO_Port GPIOA
#define PA5_Pin GPIO_PIN_5
#define PA5_GPIO_Port GPIOA
#define PA7_Pin GPIO_PIN_7
#define PA7_GPIO_Port GPIOA
#define PD9_Pin GPIO_PIN_9
#define PD9_GPIO_Port GPIOD
#define PD9_EXTI_IRQn EXTI9_5_IRQn
#define PD11_Pin GPIO_PIN_11
#define PD11_GPIO_Port GPIOD
#define PD11_EXTI_IRQn EXTI15_10_IRQn
#define PD13_Pin GPIO_PIN_13
#define PD13_GPIO_Port GPIOD
#define PD13_EXTI_IRQn EXTI15_10_IRQn
#define PD14_Pin GPIO_PIN_14
#define PD14_GPIO_Port GPIOD
#define PD14_EXTI_IRQn EXTI15_10_IRQn

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
