//
// Created by ZhengLongBing on 2024/9/11.
//



#ifndef COMPONENT_H
#define COMPONENT_H


#include "servo.h"
#include "ultrasound.h"
#include "bluetooth.h"
#include "car.h"
#include "tim.h"
#include "gpio.h"
#include "usart.h"


#define SERVO_HTIM htim2
#define SERVO_CHANNEL TIM_CHANNEL_1
// 设置对应定时器 arr 的值
#define SERVO_COUNTER_PERIOD 2000


#define Trig_HTIM htim4
#define Trig_CHANNEL TIM_CHANNEL_1

#define Echo_HTIM htim3
#define Echo_Rising_CHANNEL TIM_CHANNEL_1
#define Echo_Falling_CHANNEL TIM_CHANNEL_2

#define Echo_Rising_ACTIVE_CHANNEL   HAL_TIM_ACTIVE_CHANNEL_1
#define Echo_Falling_ACTIVE_CHANNEL  HAL_TIM_ACTIVE_CHANNEL_2

// 设置对应定时器 arr 的值
#define ULTRASOUND_COUNTER_PERIOD 10000


#define CAR_HTIM htim3
#define LeftMotor_CHANNEL TIM_CHANNEL_3
#define RightMotor_CHANNEL TIM_CHANNEL_4
// 设置对应定时器 arr 的值
#define CAR_COUNTER_PERIOD 10000


#define BLUETOOTH_HUART huart1


extern Servo SERVO;
extern Ultrasound ULTRASOUND;
extern Bluetooth BLUETOOTH;
extern Car CAR;

#endif //COMPONENT_H
