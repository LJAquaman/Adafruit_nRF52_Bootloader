#ifndef _MY_CUSTOM_BOARD_H
#define _MY_CUSTOM_BOARD_H

// 1. 定义芯片型号
#define _PINNUM(port, pin)    ((port)*32 + (pin))
#define UICR_REGOUT0_VALUE    UICR_REGOUT0_VOUT_3V3

// 2. 定义板子名称
#define BOARD_NAME            "My Custom PCB REV6"

// 3. 定义 LED 连接
// --------------------------------------------------------------------------------
// 你的 RGB 灯 (WS2812) 在 P0.26
#define NEOPIXEL_PIN          _PINNUM(0, 26)
#define NEOPIXEL_POWER_PIN    -1  // 如果 RGB 灯没有独立的电源开关脚，设为 -1

// [关键技巧]
// Bootloader 逻辑必须需要一个“普通 LED”来闪烁状态。
// 但你的板子上没有普通 LED，为了防止 Bootloader 去乱动你的 SPI/ADC 引脚，
// 我们把这个普通 LED 映射到一个【完全没用到的空引脚】上。
// 假设 P1.00 是空的（根据你的 Config.h，P1.00 似乎没用，或者找一个你确信悬空的脚）
#define LED_PRIMARY_PIN       _PINNUM(1, 0) 
#define LED_STATE_ON          0

// 4. 定义按钮
// 如果你有复位按钮，Bootloader 通常靠复位引脚进入，这里可以设为无效
#define BUTTON_1              _PINNUM(1, 15) // 随便设一个没用的，防止冲突
#define BUTTON_PULL           NRF_GPIO_PIN_PULLUP
#define BUTTON_STATE_ACTIVE   0

// 5. USB 配置 (标准配置，不用动)
#define USB_DESC_VID           0x239A
#define USB_DESC_UF2_PID       0x0029
#define USB_DESC_CDC_ONLY_PID  0x002A

#define UF2_PRODUCT_NAME       "My Custom Board"
#define UF2_VOLUME_LABEL       "MY_BOOT" // U盘显示的磁盘名
#define UF2_BOARD_FAMILY_ID    0xADA52840
#define UF2_INDEX_URL          "https://www.adafruit.com"

#endif // _MY_CUSTOM_BOARD_H
