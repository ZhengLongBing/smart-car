//
// Created by ZhengLongBing on 2024/9/12.
//
#include "interrupt.h"
#include "instruction.h"



void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim) {
    ULTRASOUND_IT(&ULTRASOUND,htim);
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart) {
    INSTRUCTION_IT(huart);
}
