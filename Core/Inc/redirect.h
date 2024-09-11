//
// Created by ZhengLongBing on 2024/9/8.
//

#ifndef REDIRECT_H
#define REDIRECT_H
#include <sys/stat.h>
#include "stm32f1xx_hal.h"

void RedirectInit(UART_HandleTypeDef *huart);

int _isatty(int fd);

int _write(int fd, char *ptr, int len);

int _close(int fd);

int _lseek(int fd, int ptr, int dir);

int _read(int fd, char *ptr, int len);

int _fstat(int fd, struct stat *st);


#endif //REDIRECT_H
