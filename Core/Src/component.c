//
// Created by ZhengLongBing on 2024/9/11.
//

#include "component.h"



Servo SERVO = {
    .htim = &SERVO_HTIM,
    .channel = SERVO_CHANNEL,
    .counter_period = SERVO_COUNTER_PERIOD,
};

Ultrasound ULTRASOUND = {
    .trig_htim = &Trig_HTIM,
    .trig_channel = Trig_CHANNEL,
    .echo_htim = &Echo_HTIM,
    .echo_rising_channel = Echo_Rising_CHANNEL,
    .echo_falling_channel = Echo_Falling_CHANNEL,
    .echo_rising_active_channel = Echo_Rising_ACTIVE_CHANNEL,
    .echo_falling_active_channel = Echo_Falling_ACTIVE_CHANNEL,
    .counter_period = ULTRASOUND_COUNTER_PERIOD,
    .ranging = {
        .state = Init,
        .value = {
            .distance = 0.0
        }
    }
};


Bluetooth BLUETOOTH = {
    .huart = &BLUETOOTH_HUART,
    .buf = {},
};


Car CAR = {
    .left_motor = {
        .in1_port = Lin1_GPIO_Port,
        .in1_pin = Lin1_Pin,
        .in2_port = Lin2_GPIO_Port,
        .in2_pin = Lin2_Pin,
        .pwm_htim = &CAR_HTIM,
        .pwm_channel = LeftMotor_CHANNEL,
        .counter_period = CAR_COUNTER_PERIOD,
    },
    .right_motor = {
        .in1_port = Rin1_GPIO_Port,
        .in1_pin = Rin1_Pin,
        .in2_port = Rin2_GPIO_Port,
        .in2_pin = Rin2_Pin,
        .pwm_htim = &CAR_HTIM,
        .pwm_channel = RightMotor_CHANNEL,
        .counter_period = CAR_COUNTER_PERIOD,
    },
    .stby_port = STBY_GPIO_Port,
    .stby_pin = STBY_Pin
};


// 超声波测距
void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim) {
    ULTRASOUND_IT(&ULTRASOUND,htim);
}
