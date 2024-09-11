//
// Created by ZhengLongBing on 2024/9/11.
//

#ifndef BLUETOOTH_H
#define BLUETOOTH_H

// !!! 需要开启对应的DMA通道

#include "stm32f1xx_hal.h"

#define BLUETOOTH_BUF_LEN 32


typedef struct {
    UART_HandleTypeDef *huart;
    uint8_t buf[BLUETOOTH_BUF_LEN];
}Bluetooth;


void BLUETOOTH_Write(Bluetooth *bluetooth, uint8_t *data, uint16_t size);
void BLUETOOTH_Read(Bluetooth *bluetooth,uint8_t *data, uint16_t size);
void BLUETOOTH_ReadToIdle(Bluetooth *bluetooth);

#endif //BLUETOOTH_H
