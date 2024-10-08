# 智能小车项目

## 项目简介

本项目是一个基于 STM32F103C8T6 微控制器的智能小车控制系统。该项目使用了 STM32 HAL 库和 FreeRTOS 实现了多任务管理，并通过蓝牙模块、舵机、超声波测距模块、电机驱动模块等硬件实现了小车的远程控制和自动避障功能。

## 硬件组件

- **微控制器**: STM32F103C8T6
- **蓝牙模块**: HC-06
- **舵机**: SG90
- **超声波测距模块**: HC-SR04
- **电机驱动模块**: TB6612FNG

## 软件框架

- **STM32 HAL 库**: 用于硬件抽象层编程。
- **FreeRTOS**: 实时操作系统，用于多任务管理。

## 功能特性

- **蓝牙控制**: 通过蓝牙模块 HC-06 实现小车的远程控制。
- **自动避障**: 通过超声波测距模块 HC-SR04 实现自动避障功能。
- **舵机控制**: 通过舵机 SG90 实现方向控制。
- **电机驱动**: 通过电机驱动模块 TB6612FNG 实现小车的前进、后退、左转、右转等基本运动。

## 硬件连接

1. **STM32F103C8T6**:
    - 电源: VCC 接 3.3V，GND 接地。
    - 蓝牙模块 HC-06:
        - VCC 接 3.3V
        - GND 接地
        - TXD 接 STM32 RXD
        - RXD 接 STM32 TXD
    - 舵机 SG90:
        - VCC 接 5V
        - GND 接地
        - 控制信号接 STM32 的 PWM 引脚
    - 超声波测距模块 HC-SR04:
        - VCC 接 5V
        - GND 接地
        - TRIG 接 STM32 的 GPIO 引脚
        - ECHO 接 STM32 的 GPIO 引脚
    - 电机驱动模块 TB6612FNG:
        - VCC 接 5V
        - GND 接地
        - AIN1, AIN2, BIN1, BIN2 接 STM32 的 GPIO 引脚
        - PWMA, PWMB 接 STM32 的 PWM 引脚
        - STBY 接 STM32 的 GPIO 引脚

## 软件设计

### FreeRTOS 任务

1. **蓝牙任务**: 负责接收蓝牙指令并控制小车的运动。
2. **避障任务**: 负责读取超声波测距模块的数据，并根据距离信息进行避障处理。
3. **舵机任务**: 负责控制舵机的方向。
4. **电机任务**: 负责控制电机的转动方向和速度。


## 编译和烧录

1. 使用 [STM32CubeMX](https://www.st.com/en/development-tools/stm32cubemx.html) 生成 HAL 库代码。
2. 使用 [STM32CubeIDE](https://www.st.com/en/development-tools/stm32cubeide.html) 编译项目。
3. 通过 [ST-Link](https://www.st.com/en/development-tools/st-link-v2.html) 将编译好的固件烧录到 STM32F103C8T6 芯片中。


## 实物图
![侧面](https://fastly.jsdelivr.net/gh/ZhengLongBing/images@main/pictures/19605716bbfa7e22313360c908ed0fe-2024-9-13-10:51:33.jpg)

![正面](https://fastly.jsdelivr.net/gh/ZhengLongBing/images@main/pictures/ffb79e4808a05257c0e1348127f751b-2024-9-13-10:51:19.jpg)


## 使用说明

1. 将小车的硬件按上述连接方式连接好。
2. 打开电源，确保蓝牙模块 HC-06 处于可配对状态。
3. 使用手机蓝牙连接 HC-06，并通过蓝牙终端应用发送控制指令。
4. 小车将根据接收到的指令进行相应的运动和避障操作。

## 贡献

欢迎对本项目进行贡献！你可以通过以下方式参与：
- 提交问题 (Issues)
- 提交合并请求 (Pull Requests)
- 提出改进建议

## 许可证

本项目采用 [MIT 许可证](LICENSE)。
