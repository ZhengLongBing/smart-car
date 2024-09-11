//
// Created by ZhengLongBing on 2024/9/8.
//
#include "servo.h"


void SERVO_Init(Servo *servo) {
    HAL_TIM_Base_Start(servo->htim);
    HAL_TIM_PWM_Start(servo->htim,servo->channel);
}


void SERVO_SetAngle(Servo *servo,Angle angle) {
    switch (angle) {
        case Angle0: {
            __HAL_TIM_SET_COMPARE(servo->htim,servo->channel,0.025 * servo->counter_period);
            break;
        }
        case Angle45: {
            __HAL_TIM_SET_COMPARE(servo->htim,servo->channel,0.05 * servo->counter_period);
            break;
        }
        case Angle90: {
            __HAL_TIM_SET_COMPARE(servo->htim,servo->channel,0.075 * servo->counter_period);
            break;
        }
        case Angle135: {
            __HAL_TIM_SET_COMPARE(servo->htim,servo->channel,0.1 * servo->counter_period);
            break;
        }
        case Angle180: {
            __HAL_TIM_SET_COMPARE(servo->htim,servo->channel,0.125 * servo->counter_period);
            break;
        }
    }
}