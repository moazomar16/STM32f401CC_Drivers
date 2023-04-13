/**********************************************************
 *
 *  @name LED_interface.h
 *  @date: Mar 24, 2023
 *  @Author: Moaz Omar
 *  @category HAL DRIVER
 *  @GitHub https://github.com/moazomar16
 *
 *********************************************************/
#ifndef HAL_LED_LED_INTERFACE_H_
#define HAL_LED_LED_INTERFACE_H_

#include "LED_Config.h"

extern const LED_Config_t LEDs[MAX_LED_NUMBER];

/**
 * @brief this function is responsible for initializing led
 * @return locStatus
 */
ENM_ErrorStatus_t ledInit(void);
/**
 *
 * @brief this function is responsible for setting led value
 * @param led
 * @param state
 * @return locStatus
 */
ENM_ErrorStatus_t ledSet(uint32_t led, uint32_t state);



#endif /* HAL_LED_LED_INTERFACE_H_ */
