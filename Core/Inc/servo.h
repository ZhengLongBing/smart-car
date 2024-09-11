//
// Created by ZhengLongBing on 2024/9/8.
//

#ifndef SERVO_H
#define SERVO_H



#include "stm32f1xx_hal.h"


// !!! 舵机的pwm周期必须为50hz,才能正确运行


typedef struct {
    TIM_HandleTypeDef* htim;
    uint32_t channel;
    // 设置对应定时器arr的值
    uint16_t counter_period;
}Servo;


typedef enum {
    Angle0,
    Angle45,
    Angle90,
    Angle135,
    Angle180,
}Angle;


void SERVO_Init(Servo * servo);
void SERVO_SetAngle(Servo * servo, Angle angle);

#endif //SERVO_H
