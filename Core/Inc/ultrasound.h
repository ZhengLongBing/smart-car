//
// Created by ZhengLongBing on 2024/9/8.
//

#ifndef ULTRASOUND_H
#define ULTRASOUND_H

#include "stm32f1xx_hal.h"


/// trig引脚：
/// 设置为定时器为 One Pulse Mode
/// 通道模式为 PWM mode 2
/// 通道极性为 High
/// echo引脚：
/// 设置定时器两个通道为输入捕获模式
/// 一个通道为直接模式 上升沿触发
/// 一个通道为间接模式 下降沿触发


typedef enum {
    Init,
    Start,
    Distance,
    Error
}RangingState;

typedef union {
    float distance;
    const char * error;
}RangingUnion;

typedef struct {
    RangingState state;
    RangingUnion value;
}Ranging;

typedef struct {
    TIM_HandleTypeDef * trig_htim;
    uint32_t trig_channel;
    TIM_HandleTypeDef * echo_htim;
    uint32_t echo_rising_channel;
    uint32_t echo_falling_channel;
    int echo_rising_active_channel;
    int echo_falling_active_channel;
    // 设置echo对应定时器arr的值
    uint16_t counter_period;
    Ranging ranging;
}Ultrasound;

void ULTRASOUND_Init(Ultrasound * ultrasound);
void ULTRASOUND_Trig(Ultrasound * ultrasound);

// !!! 将该函数放入回调函数 HAL_TIM_IC_CaptureCallback 中。
void ULTRASOUND_IT(Ultrasound * ultrasound,TIM_HandleTypeDef *htim);

//完成测距的回调 自己实现逻辑
void ULTRASOUND_RangingCpltCallback(Ultrasound * ultrasound);
//测距错误的回调 自己实现逻辑
void ULTRASOUND_RangingErrorCallback(Ultrasound * ultrasound);
#endif //ULTRASOUND_H
