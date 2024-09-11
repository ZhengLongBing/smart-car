//
// Created by ZhengLongBing on 2024/9/9.
//

#include "car.h"



void CAR_Init(Car *car) {
    MOTOR_Init(&car->left_motor);
    MOTOR_Init(&car->right_motor);
    CAR_Enable(car);
}

void CAR_Enable(Car *car) {
    HAL_GPIO_WritePin(car->stby_port, car->stby_pin, GPIO_PIN_SET);
}

void CAR_Disable(Car *car) {
    HAL_GPIO_WritePin(car->stby_port, car->stby_pin, GPIO_PIN_RESET);
}

void CAR_Forward(Car *car) {
    MOTOR_Forward(&car->left_motor,car->left_motor.counter_period);
    MOTOR_Forward(&car->right_motor,car->right_motor.counter_period);
}

void CAR_Backward(Car *car) {
    MOTOR_Backward(&car->left_motor,car->left_motor.counter_period);
    MOTOR_Backward(&car->right_motor,car->right_motor.counter_period);
}
void CAR_Left(Car *car) {
    MOTOR_Forward(&car->left_motor,0);
    MOTOR_Forward(&car->right_motor,car->right_motor.counter_period);
}
void CAR_Right(Car *car) {
    MOTOR_Forward(&car->left_motor,car->left_motor.counter_period);
    MOTOR_Forward(&car->right_motor,0);
}
void CAR_TurnLeft(Car *car) {
    MOTOR_Backward(&car->left_motor,car->left_motor.counter_period);
    MOTOR_Forward(&car->right_motor,car->right_motor.counter_period);
}
void CAR_TurnRight(Car *car) {
    MOTOR_Forward(&car->left_motor,car->left_motor.counter_period);
    MOTOR_Backward(&car->right_motor,car->right_motor.counter_period);
}
void CAR_Stop(Car *car) {
    MOTOR_Stop(&car->left_motor);
    MOTOR_Stop(&car->right_motor);
}

void CAR_Brake(Car *car) {
    MOTOR_Brake(&car->left_motor);
    MOTOR_Brake(&car->right_motor);
}