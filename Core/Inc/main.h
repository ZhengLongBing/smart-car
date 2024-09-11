/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

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
#define Led_Pin GPIO_PIN_13
#define Led_GPIO_Port GPIOC
#define STBY_Pin GPIO_PIN_1
#define STBY_GPIO_Port GPIOA
#define Lin1_Pin GPIO_PIN_2
#define Lin1_GPIO_Port GPIOA
#define Lin2_Pin GPIO_PIN_3
#define Lin2_GPIO_Port GPIOA
#define Rin1_Pin GPIO_PIN_4
#define Rin1_GPIO_Port GPIOA
#define Rin2_Pin GPIO_PIN_5
#define Rin2_GPIO_Port GPIOA
#define Echo_Pin GPIO_PIN_6
#define Echo_GPIO_Port GPIOA
#define LeftMotor_Pin GPIO_PIN_0
#define LeftMotor_GPIO_Port GPIOB
#define RightMotor_Pin GPIO_PIN_1
#define RightMotor_GPIO_Port GPIOB
#define Servo_Pin GPIO_PIN_15
#define Servo_GPIO_Port GPIOA
#define Trig_Pin GPIO_PIN_6
#define Trig_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
