/**********************************************************
 *
 *  @name LED_Config.c
 *  @date: Mar 24, 2023
 *  @Author: Moaz Omar
 *  @category HAL DRIVER
 *  @GitHub https://github.com/moazomar16
 *
 *********************************************************/


#include "Libraries/Std_Types.h"
#include "LED_Config.h"

  const LED_Config_t LEDs[MAX_LED_NUMBER]={
          [LED_Alarm]={
                  .port=GPIO_PORT_A,
                  .pin=gpioPin_0,
                  .mode=LED_ACTIVE_HIGH,
                  .speed=HIGH_SPEED,
                  .color=RED,
                  .name=LED_Alarm,
                  .intiState=LED_ON
          },
          [LED_Stop]={
              .port=GPIO_PORT_B,
              .pin=gpioPin_1,
              .mode=LED_ACTIVE_LOW,
              .speed=HIGH_SPEED,
              .color=YELLOW,
              .name=LED_Stop,
              .intiState=LED_OFF
          },
          [LED_Start]={
                  .port=GPIO_PORT_B,
                  .pin=gpioPin_5,
                  .mode=LED_ACTIVE_LOW,
                  .speed=HIGH_SPEED,
                  .color=GREEN,
                  .name=LED_Start,
                  .intiState=LED_OFF
          },
          [LED_Run]={
                  .port=GPIO_PORT_A,
                  .pin=gpioPin_1,
                  .mode=LED_ACTIVE_HIGH,
                  .speed=HIGH_SPEED,
                  .color=BLUE,
                  .name=LED_Start,
                  .intiState=LED_ON
          }
  };

