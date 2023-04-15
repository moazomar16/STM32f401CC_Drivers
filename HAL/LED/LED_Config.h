/**********************************************************
 *
 *  @name LED_Config.h
 *  @date: Mar 24, 2023
 *  @Author: Moaz Omar
 *  @category HAL DRIVER
 *  @GitHub https://github.com/moazomar16
 *
 *********************************************************/

#ifndef HAL_LED_LED_CONFIG_H_
#define HAL_LED_LED_CONFIG_H_

#include "Libraries/Std_Types.h"
#include "MCAL/GPIO/GPIO_interface.h"



/**
 * @brief led mode output push pull and pull up (Active High)
 **/
#define LED_ACTIVE_HIGH     0
/**
 * @brief led mode output push pull and pull down (Active Low)
 */
#define LED_ACTIVE_LOW      1

#define LED_ON          1
#define LED_OFF         0

/**
 * @brief Maximum number of led
 */
#define MAX_LED_NUMBER 4
/**
 * @brief Led names
 */
typedef enum
{
    LED_Alarm=0,
    LED_Stop,
    LED_Start,
    LED_Run
}LED_Name_t;

/**
 * @brief led configuration
 */
typedef struct
{
    void * port;
    uint32_t pin;
    uint32_t mode;
    uint32_t speed;
    uint32_t name;
    uint32_t color;
    uint32_t intiState;
}LED_Config_t;

/**
 * @brief Led colors
 */
typedef enum
{
    RED,
    ORANGE,
    YELLOW,
    GREEN,
    BLUE
}LED_Color_t;

#endif /* HAL_LED_LED_CONFIG_H_ */
