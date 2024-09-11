//
// Created by ZhengLongBing on 2024/9/11.
//

#include "bluetooth.h"

uint8_t buf[BLUETOOTH_BUF_LEN];


void BLUETOOTH_Write(Bluetooth *bluetooth, uint8_t *data, const uint16_t size) {
    HAL_UART_Transmit_DMA(bluetooth->huart,data, size);
}

void BLUETOOTH_Read(Bluetooth *bluetooth,uint8_t *data, const uint16_t size){
    HAL_UART_Receive_DMA(bluetooth->huart, data, size);
}

void BLUETOOTH_ReadToIdle(Bluetooth *bluetooth){
    HAL_UARTEx_ReceiveToIdle_DMA(bluetooth->huart, bluetooth->buf, BLUETOOTH_BUF_LEN);
}
