//
// Created by ZhengLongBing on 2024/9/9.
//

#ifndef MOTOR_H
#define MOTOR_H

#include "stm32f1xx_hal.h"

//设置为对应定时器 arr 的值
#define MAX_SPEED 10000

typedef enum {
    Forward,
    Backward,
    Stop,
    Brake
}MotorFlag;

typedef struct {
    MotorFlag flag;
    uint16_t speed;
}MotorCommand;


typedef struct {
    GPIO_TypeDef * in1_port;
    uint16_t in1_pin;
    GPIO_TypeDef * in2_port;
    uint16_t in2_pin;
    TIM_HandleTypeDef * pwm_htim;
    uint32_t pwm_channel;
    // 设置对应定时器arr的值
    uint16_t counter_period;
}Motor;

void MOTOR_Init(const Motor * motor);
void MOTOR_SetCommand(const Motor * motor, MotorCommand command);
void MOTOR_Forward(const Motor * motor, uint16_t speed);
void MOTOR_Backward(const Motor * motor, uint16_t speed);
void MOTOR_Stop(const Motor * motor);
void MOTOR_Brake(const Motor * motor);
#endif //MOTOR_H
