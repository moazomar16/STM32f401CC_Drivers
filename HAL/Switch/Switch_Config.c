/**********************************************************
 *
 *  @name Switch_Config.c
 *  @date: Mar 26, 2023
 *  @Author: Moaz Omar
 *  @category HAL DRIVER
 *  @GitHub https://github.com/moazomar16
 *
 *********************************************************/

#include "Switch_Config.h"

/**
 * @brief this is an array containing all the switches in the system the user must add all the switches he wish to use
 * @param SWITCH_PULL_UP
 * @param SWITCH_PULL_DOWN
 * @param INPUT_FLOATING
 */
const SWITCH_Config_t  Switches[MAX_SWITCH_NUMBER]={
        [Switch_Run]={
                .port=GPIO_PORT_A,
                .pin=gpioPin_0,
                .mode=SWITCH_PULL_UP,
                .name=Switch_Run
        }

};