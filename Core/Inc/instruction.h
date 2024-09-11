//
// Created by ZhengLongBing on 2024/9/11.
//


#ifndef INSTRUCTION_H
#define INSTRUCTION_H
#include "stm32f1xx_hal.h"

/* 接受的指令


#define Forward 0
#define Backward 1
#define Left  2
#define Right  3
#define TurnLeft 4
#define TurnRight 5
#define Stop 6
#define Brake 7

#define SERVO_Angle_0 8
#define SERVO_Angle_45 9
#define SERVO_Angle_90 10
#define SERVO_Angle_135 11
#define SERVO_Angle_180 12

#define ULTRASOUND_Randing 13

*/

typedef enum {
    Unused,
    Used,
}UseState;

extern uint8_t INSTRUCTION;
extern UseState USE_STATE;


void INSTRUCTION_Init(void);
void INSTRUCTION_Listen();


#endif //INSTRUCTION_H
