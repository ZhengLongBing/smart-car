//
// Created by ZhengLongBing on 2024/9/9.
//

#include "motor.h"

void MOTOR_Init(const Motor * motor) {
    HAL_TIM_Base_Start(motor->pwm_htim);
    HAL_TIM_PWM_Start(motor->pwm_htim, motor->pwm_channel);
    MOTOR_Stop(motor);
}

void MOTOR_SetCommand(const Motor * motor, const MotorCommand command) {
    switch (command.flag) {
        case Forward: {
            const uint16_t speed =command.speed > motor->counter_period ? motor->counter_period : command.speed;
            __HAL_TIM_SET_COMPARE(motor->pwm_htim,motor->pwm_channel,speed);
            HAL_GPIO_WritePin(motor->in1_port, motor->in1_pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(motor->in2_port, motor->in2_pin, GPIO_PIN_RESET);
            break;
        }
        case Backward: {
            const uint16_t speed =command.speed > motor->counter_period ? motor->counter_period : command.speed;
            __HAL_TIM_SET_COMPARE(motor->pwm_htim,motor->pwm_channel,speed);
            HAL_GPIO_WritePin(motor->in1_port, motor->in1_pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(motor->in2_port, motor->in2_pin, GPIO_PIN_SET);
            break;
        }
        case Stop: {
            HAL_GPIO_WritePin(motor->in1_port, motor->in1_pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(motor->in2_port, motor->in2_pin, GPIO_PIN_RESET);
            break;
        }
        case Brake: {
            HAL_GPIO_WritePin(motor->in1_port, motor->in1_pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(motor->in2_port, motor->in2_pin, GPIO_PIN_SET);
            break;
        }
    }
}


void MOTOR_Forward(const Motor * motor, const uint16_t speed) {
    const MotorCommand command = {
        .flag = Forward,
        .speed = speed,
    };
    MOTOR_SetCommand(motor,command);
}

void MOTOR_Backward(const Motor * motor, const uint16_t speed) {
    const MotorCommand command = {
        .flag = Backward,
        .speed = speed,
    };
    MOTOR_SetCommand(motor,command);
}
void MOTOR_Stop(const Motor * motor) {
    const MotorCommand command = {
        .flag = Stop,
        .speed = 0,
    };
    MOTOR_SetCommand(motor,command);
}
void MOTOR_Brake(const Motor * motor) {
    const MotorCommand command = {
        .flag = Brake,
        .speed = 0,
    };
    MOTOR_SetCommand(motor,command);
}