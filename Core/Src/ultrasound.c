//
// Created by ZhengLongBing on 2024/9/8.
//
#include "ultrasound.h"

#include <stdio.h>


void ULTRASOUND_Init(Ultrasound * ultrasound) {
    HAL_TIM_Base_Start(ultrasound->echo_htim);
    HAL_TIM_IC_Start(ultrasound->echo_htim,ultrasound->echo_rising_channel);
    HAL_TIM_IC_Start_IT(ultrasound->echo_htim,ultrasound->echo_falling_channel);
    HAL_TIM_PWM_Start(ultrasound->trig_htim,ultrasound->trig_channel);
}


void ULTRASOUND_Trig(Ultrasound * ultrasound) {
    HAL_TIM_Base_Stop(ultrasound->trig_htim);
    HAL_TIM_Base_Start(ultrasound->trig_htim);
    ultrasound->ranging.state = Start;
}

void ULTRASOUND_IT(Ultrasound * ultrasound,TIM_HandleTypeDef *htim) {
    if(htim == ultrasound->echo_htim&& htim->Channel == ultrasound->echo_falling_active_channel ) {
        if (ultrasound->ranging.state == Init || ultrasound->ranging.state == Error ) {
            ultrasound->ranging.state = Error;
            ultrasound->ranging.value.error = "未触发trig,echo有抖动！\n";
        }else {
            ultrasound->ranging.state = Distance;
            const uint16_t rising = HAL_TIM_ReadCapturedValue(ultrasound->echo_htim,ultrasound->echo_rising_channel);
            const uint16_t falling = HAL_TIM_ReadCapturedValue(ultrasound->echo_htim,ultrasound->echo_falling_channel);
            if (falling > rising) {
                ultrasound->ranging.value.distance = (falling - rising)*0.034/2.0;
            }else {
                ultrasound->ranging.value.distance = (ultrasound->counter_period + falling - rising)*0.034/2.0;
            }
        }
    }
}

