//
// Created by ZhengLongBing on 2024/9/11.
//
#include "instruction.h"
#include <stdio.h>
#include "component.h"
#include "redirect.h"

uint8_t INSTRUCTION;
UseState USE_STATE = Used;

void INSTRUCTION_Init(void) {
    SERVO_Init(&SERVO);
    ULTRASOUND_Init(&ULTRASOUND);
    CAR_Init(&CAR);
    RedirectInit(&BLUETOOTH_HUART);
    BLUETOOTH_Read(&BLUETOOTH,&INSTRUCTION,1);
}


void INSTRUCTION_Listen() {
    while(1) {
        HAL_Delay(1);
        if (USE_STATE == Unused) {
            USE_STATE = Used;
            printf("instruction: %d\n",INSTRUCTION);
            switch (INSTRUCTION){
                case 0 : {
                    CAR_Forward(&CAR);
                    break;
                }
                case 1 :{
                    CAR_Backward(&CAR);
                    break;
                }
                case 2: {
                    CAR_Left(&CAR);
                    break;
                }
                case 3: {
                    CAR_Right(&CAR);
                    break;
                }
                case 4: {
                    CAR_TurnLeft(&CAR);
                    break;
                }
                case 5: {
                    CAR_TurnRight(&CAR);
                    break;
                }
                case 6: {
                    CAR_Stop(&CAR);
                    break;
                }
                case 7: {
                    CAR_Stop(&CAR);
                    break;
                }
                case 8: {
                    SERVO_SetAngle(&SERVO,Angle0);
                    break;
                }
                case 9: {
                    SERVO_SetAngle(&SERVO,Angle45);
                    break;
                }
                case 10: {
                    SERVO_SetAngle(&SERVO,Angle90);
                    break;
                }
                case 11: {
                    SERVO_SetAngle(&SERVO,Angle135);
                    break;
                }
                case 12: {
                    SERVO_SetAngle(&SERVO,Angle180);
                    break;
                }
                case 13: {
                    ULTRASOUND_Trig(&ULTRASOUND);
                    HAL_Delay(10);
                    switch(ULTRASOUND.ranging.state) {
                        case Distance: {
                            printf("distance: %.2fcm\n",ULTRASOUND.ranging.value.distance);
                            break;
                        }
                        case Error: {
                            printf("error: %s\n",ULTRASOUND.ranging.value.error);
                            break;
                        }
                        default: {
                            printf("错误状态！\n");
                            break;
                        }
                    }
                    break;
                }
                default: {
                    printf("未知指令！\n");
                }
            }
        }
    }
}


void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart) {
    if (huart == &BLUETOOTH_HUART) {
        USE_STATE = Unused;
        BLUETOOTH_Read(&BLUETOOTH,&INSTRUCTION,1);
    }
}