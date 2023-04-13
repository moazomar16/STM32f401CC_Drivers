/**********************************************************
 *
 *  @name LCD_config.c
 *  @date: Mar 26, 2023
 *  @Author: Moaz Omar
 *  @category HAL DRIVER
 *  @GitHub https://github.com/moazomar16
 *
 *********************************************************/
#include "LCD_Config.h"


const LCD_CFG_t lcd={
        .operationMode={
                .mode=lcd_8_bitMode,
                .numberOfLines=lcd_1_lineMode,
                .font=lcd_5x8_font,
                .displayState=lcdDisplayON,
                .cursorState=lcdCursorStateOFF,
                .cursorBlink=lcdCursorBlinkStateOFF,
                .entryMode=lcdEntryIncrement,
                .displayShiftMode=lcdDisplayShiftOFF,
                .cursorDisplayShiftMode=lcdShiftCursor,
                .shiftDirection=lcdShiftRight,
        },
        .lcdPins.enable={
                .mode=OUTPUT_PUSH_PULL,
                .port=GPIO_PORT_A,
                .pin=gpioPin_0,
                .speed=HIGH_SPEED
        },
        .lcdPins.readWrite={
                .mode=OUTPUT_PUSH_PULL,
                .port=GPIO_PORT_A,
                .pin=gpioPin_1,
                .speed=HIGH_SPEED
        },
        .lcdPins.registerSelector={
                .mode=OUTPUT_PUSH_PULL,
                .port=GPIO_PORT_A,
                .pin=gpioPin_2,
                .speed=HIGH_SPEED
        },
        .lcdPins.data[0]={
        				.port = GPIO_PORT_A,
						.mode = OUTPUT_PUSH_PULL,
						.pin = gpioPin_3,
						.speed = HIGH_SPEED
        },
        .lcdPins.data[1]={
                        .port = GPIO_PORT_A,
                        .mode = OUTPUT_PUSH_PULL,
                        .pin = gpioPin_4,
                        .speed = HIGH_SPEED
        },
        .lcdPins.data[2]={
                        .port = GPIO_PORT_A,
                        .mode = OUTPUT_PUSH_PULL,
                        .pin = gpioPin_5,
                        .speed = HIGH_SPEED
        },
        .lcdPins.data[3]={
                        .port = GPIO_PORT_A,
                        .mode = OUTPUT_PUSH_PULL,
                        .pin = gpioPin_6,
                        .speed = HIGH_SPEED
        },
        .lcdPins.data[4]={
                        .port = GPIO_PORT_A,
                        .mode = OUTPUT_PUSH_PULL,
                        .pin = gpioPin_7,
                        .speed = HIGH_SPEED
        },
        .lcdPins.data[5]={
                        .port = GPIO_PORT_A,
                        .mode = OUTPUT_PUSH_PULL,
                        .pin = gpioPin_8,
                        .speed = HIGH_SPEED
        },
        .lcdPins.data[6]={
                        .port = GPIO_PORT_A,
                        .mode = OUTPUT_PUSH_PULL,
                        .pin = gpioPin_9,
                        .speed = HIGH_SPEED
        },
        .lcdPins.data[7]={
                        .port = GPIO_PORT_A,
                        .mode = OUTPUT_PUSH_PULL,
                        .pin = gpioPin_10,
                        .speed = HIGH_SPEED
        }
};

