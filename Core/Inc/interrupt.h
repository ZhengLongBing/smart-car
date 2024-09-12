//
// Created by ZhengLongBing on 2024/9/12.
//

#ifndef INTERRUPT_H
#define INTERRUPT_H
#include "component.h"


extern void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim);
extern void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart);

#endif //INTERRUPT_H
