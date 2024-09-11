//
// Created by ZhengLongBing on 2024/9/9.
//

#ifndef CAR_H
#define CAR_H

#include "stm32f1xx_hal.h"
#include "motor.h"


typedef struct {
    Motor left_motor;
    Motor right_motor;
    GPIO_TypeDef *stby_port;
    uint16_t stby_pin;
}Car;


void CAR_Init(Car *car);
void CAR_Enable(Car *car);
void CAR_Disable(Car *car);
void CAR_Forward(Car *car);
void CAR_Backward(Car *car);
void CAR_Left(Car *car);
void CAR_Right(Car *car);
void CAR_TurnLeft(Car *car);
void CAR_TurnRight(Car *car);
void CAR_Stop(Car *car);
void CAR_Brake(Car *car);


#endif //CAR_H
