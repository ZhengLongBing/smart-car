//
// Created by ZhengLongBing on 2024/9/11.
//
#include "instruction.h"
#include <stdio.h>

#include "cmsis_os.h"
#include "component.h"
#include "FreeRTOS.h"
#include "queue.h"
#include "redirect.h"
#include "task.h"
#include "ultrasound.h"

uint8_t INSTRUCTION;
ModeState MODE_STATE = Free;
QueueHandle_t INSTRUCTION_QUEUE = NULL;
QueueHandle_t DISTANCE_QUEUE = NULL;
TaskHandle_t MODE_AUTO_TASK = NULL;

void MODE_Free(uint8_t instruction);
void MODE_Auto(void * arg);


void INSTRUCTION_Init(void) {
    SERVO_Init(&SERVO);
    ULTRASOUND_Init(&ULTRASOUND);
    CAR_Init(&CAR);
    RedirectInit(&BLUETOOTH_HUART);
    BLUETOOTH_Read(&BLUETOOTH,&INSTRUCTION,1);
    INSTRUCTION_QUEUE = xQueueCreate(8,sizeof(uint8_t));
    DISTANCE_QUEUE = xQueueCreate(1,sizeof(float));
}


void INSTRUCTION_Listen() {
    while(1) {
        uint8_t instruction ;
        xQueueReceive(INSTRUCTION_QUEUE,&instruction,portMAX_DELAY);
        printf("instruction: %d\n",instruction);
        switch(MODE_STATE) {
            case Free: {
                MODE_Free(instruction);
                break;
            }
            case Auto: {
                switch (instruction) {
                    case 14: {
                        MODE_STATE = Free;
                        if(MODE_AUTO_TASK ==NULL) {
                            printf("NULL");
                        }
                        vTaskDelete(MODE_AUTO_TASK);
                        break;
                    }
                    default:{}
                }
                break;
            }
        }
    }
}


void MODE_Free(uint8_t instruction) {
    switch(instruction) {
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
            vTaskDelay(20);
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
                }
            }
            break;
        }
        case 14: {
            break;
        }
        case 15: {
            MODE_STATE  = Auto;
            BaseType_t stat = xTaskCreate(MODE_Auto , "MODE_AUTO_TASK", 64, NULL,osPriorityNormal ,&MODE_AUTO_TASK);
            if (stat != pdPASS) {
                printf("任务创建失败！\n");
            }
            break;
        }
        default: {
            printf("未知指令！\n");
        }
    }
}


void MODE_Auto(void * arg) {
    while(1) {
        SERVO_SetAngle(&SERVO,Angle90);
        vTaskDelay(500);
        ULTRASOUND_Trig(&ULTRASOUND);
        CAR_Forward(&CAR);
        while(1) {
            float  distance;
            xQueueReceive(DISTANCE_QUEUE,&distance,portMAX_DELAY);
            if(distance < 15.0) {
                CAR_Stop(&CAR);
                break;
            }
        }
        float  distance;
        SERVO_SetAngle(&SERVO,Angle180);
        vTaskDelay(500);
        xQueueReceive(DISTANCE_QUEUE,&distance,portMAX_DELAY);
        if(distance > 15.0) {
            CAR_TurnLeft(&CAR);
            vTaskDelay(1000);
            CAR_Stop(&CAR);
            continue;
        }
        SERVO_SetAngle(&SERVO,Angle0);
        vTaskDelay(500);
        xQueueReceive(DISTANCE_QUEUE,&distance,portMAX_DELAY);
        if(distance > 15.0) {
            CAR_TurnRight(&CAR);
            vTaskDelay(1000);
            CAR_Stop(&CAR);
            continue;
        }
        break;
    }
    MODE_STATE = Free;
    printf("退出 Auto !\n");
    vTaskDelete(NULL);
}



void INSTRUCTION_IT(UART_HandleTypeDef *huart) {
    if (huart == &BLUETOOTH_HUART) {
        BLUETOOTH_Read(&BLUETOOTH,&INSTRUCTION,1);
        printf("%d\n",INSTRUCTION);
        xQueueSendToBackFromISR(INSTRUCTION_QUEUE,&INSTRUCTION,0);
    }
}


//完成测距的回调 自己实现逻辑
void ULTRASOUND_RangingCpltCallback(Ultrasound * ultrasound) {
    if (ultrasound == &ULTRASOUND && MODE_STATE == Auto) {
        ULTRASOUND_Trig(ultrasound);
        xQueueSendToBackFromISR(DISTANCE_QUEUE,&ultrasound->ranging.value.distance,0);
        printf("distance: %.2fcm\n",ultrasound->ranging.value.distance);
    }
}

//测距错误的回调 自己实现逻辑
void ULTRASOUND_RangingErrorCallback(Ultrasound * ultrasound){}