/**********************************************************
 *
 *  @name GPIO_interface.h
 *  @date: Mar 23, 2023
 *  @Author: Moaz Omar
 *  @category MCAL DRIVER
 *  @GitHub https://github.com/moazomar16
 *
 *********************************************************/

#ifndef MCAL_GPIO_GPIO_INTERFACE_H_
#define MCAL_GPIO_GPIO_INTERFACE_H_

#include "Libraries/Error_Status.h"
#include "Libraries/Std_Types.h"

/**
 * @brief pointer to base address of GPIO port A
 **/
#define GPIO_PORT_A                 ((void * )0x40020000)
/**
 * @brief pointer to base address of GPIO port B
 **/
#define GPIO_PORT_B                 ((void * )0x40020400)
/**
 * @brief pointer to base address of GPIO port C
 **/
#define GPIO_PORT_C                 ((void * )0x40020800)
/**
 * @brief pointer to base address of GPIO port D
 **/
#define GPIO_PORT_D                 ((void * )0x40020C00)
/**
 * @brief pointer to base address of GPIO port E
 **/
#define GPIO_PORT_E                 ((void * )0x40021000)
/**
 * @brief pointer to base address of GPIO port H
 **/
#define GPIO_PORT_H                 ((void * )0x40021C00)


/**
 * @brief mode output _ output type push pull _ Pull state No pull
 **/
#define OUTPUT_PUSH_PULL                                    0
/**
 * @brief mode output _ output type push pull _ Pull state  pull up
 **/
#define OUTPUT_PUSH_PULL_PULL_UP                            1
/**
 * @brief mode output _ output type push pull _ Pull state pull Down
 **/
#define OUTPUT_PUSH_PULL_PULL_DOWN                          2
/**
 * @brief mode output _ output type open drain _ Pull state No pull
 **/
#define OUTPUT_OPEN_DRAIN                                   3
/**
 * @brief mode output _ output type open drain _ Pull state pull up
 **/
#define OUTPUT_OPEN_DRAIN_PULL_UP                           4
/**
 * @brief mode output _ output type open drain _ Pull state pull down
 **/
#define OUTPUT_OPEN_DRAIN_PULL_DOWN                         5
/**
 * @brief mode output alternate function _ output type push pull _ Pull state No pull
 **/
#define OUTPUT_ALTERNATE_FUNCTION_PUSH_PULL                 6
/**
 * @brief mode output alternate function _ output type push pull _ Pull state pull up
 **/
#define OUTPUT_ALTERNATE_FUNCTION_PUSH_PULL_PULL_UP         7
/**
 * @brief mode output alternate function _ output type push pull _ Pull state pull down
 **/
#define OUTPUT_ALTERNATE_FUNCTION_PUSH_PULL_PULL_DOWN       8
/**
 * @brief mode output alternate function _ output type open drain _ Pull state no pull
 **/
#define OUTPUT_ALTERNATE_FUNCTION_OPEN_DRAIN                9
/**
 * @brief mode output alternate function _ output type open drain _ Pull state pull up
 **/
#define OUTPUT_ALTERNATE_FUNCTION_OPEN_DRAIN_PULL_UP        10
/**
 * @brief mode output alternate function _ output type open drain _ Pull state pull down
 **/
#define OUTPUT_ALTERNATE_FUNCTION_OPEN_DRAIN_PULL_DOWN      11
/**
 * @brief mode input _ output type floating _ Pull state no pull
 **/
#define INPUT_FLOATING                                      12
/**
 * @brief mode input _ output type dont care _ Pull state pull up
 **/
#define INPUT_PULL_UP                                       13
/**
 * @brief mode input _ output type dont care _ Pull state pull down
 **/
#define INPUT_PULL_DOWN                                     14
/**
 * @brief mode analog input output _ output type dont care _ Pull state no pull
 **/
#define ANALOG_INPUT_OUTPUT                                 15

/**
 * @brief pin output Speed Low
 **/
#define LOW_SPEED                   0x00
/**
 * @brief pin output Speed Medium
 **/
#define MEDIUM_SPEED                0x01
/**
 * @brief pin output Speed High
 **/
#define HIGH_SPEED                  0x10
/**
 * @brief pin output Speed Very High
 **/
#define VERY_HIGH_SPEED             0x11

/**
* @brief Pin state low
*/
#define PIN_LOW                     0
/**
* @brief Pin state high
*/
#define PIN_HIGH                    1


/**
 * @brief Alternate Function name
 **/
typedef enum
{
    AlternateFunction_0_System          =0,
    AlternateFunction_1_Tim1Tim2        =1,
    AlternateFunction_2_Tim3_to_Tim5    =2,
    AlternateFunction_3_Tim9_to_Tim11   =3,
    AlternateFunction_4_I2C1_to_I2C3    =4,
    AlternateFunction_5_SPI1_to_SPI4    =5,
    AlternateFunction_6_SPI3            =6,
    AlternateFunction_7_USART1_USART2   =7,
    AlternateFunction_8_USART6          =8,
    AlternateFunction_9_I2C2_I2C3       =9,
    AlternateFunction_10_OG_FS          =10,
    AlternateFunction_12_SDIO           =12,
    AlternateFunction_15_EVENTOUT       =15
}AlternateFunction_t;
/**
 * @brief Gpio pins
 **/
typedef enum
{
    gpioPin_0=0,
    gpioPin_1,
    gpioPin_2,
    gpioPin_3,
    gpioPin_4,
    gpioPin_5,
    gpioPin_6,
    gpioPin_7,
    gpioPin_8,
    gpioPin_9,
    gpioPin_10,
    gpioPin_11,
    gpioPin_12,
    gpioPin_13,
    gpioPin_14,
    gpioPin_15
}GPIO_PIN_t;
/**
 * @brief Gpio pin configuration
 **/
typedef struct
{
    void * port;
    uint32_t pin;
    uint32_t mode;
    uint32_t speed;
}GPIO_PIN_CONFIG_t;

/*
 * APIS
 */
/**
 *
 * @brief this function is responsible for initializing pins setting mode, speed, output type and pull state
 * @param pinConfig
 * @return locStatus
 *
 **/
ENM_ErrorStatus_t gpioInit(GPIO_PIN_CONFIG_t const *pinConfig);
/**
 *
 * @brief this function is responsible for setting pin value
 * @param GPIO_PORT
 * @param gpioPin
 * @param pinState
 * @return locStatus
 *
 **/
ENM_ErrorStatus_t gpioSetPinValue(void * GPIO_PORT,GPIO_PIN_t gpioPin, uint32_t pinState );
/**
 *
 * @brief this function is responsible for getting pin value
 * @param GPIO_PORT
 * @param gpioPin
 * @param pinState
 * @return locStatus
 *
 **/
ENM_ErrorStatus_t gpioGetPinValue(void * GPIO_PORT,GPIO_PIN_t gpioPin, uint32_t *pinState );
/**
 *
 * @brief this function is responsible for setting port value
 * @param GPIO_PORT
 * @param portValue
 * @return locStatus
 *
 **/
ENM_ErrorStatus_t gpioSetPortValue(void * GPIO_PORT, uint32_t *portValue);
/**
 *
 * @brief this function is responsible for getting port value
 * @param GPIO_PORT
 * @param portValue
 * @return locStatus
 *
 **/
ENM_ErrorStatus_t gpioGetPortValue(void * GPIO_PORT, uint32_t *portValue);
/**
 *
 * @brief this function is responsible for changing pin function with another alternative function
 * @param GPIO_PORT
 * @param gpioPin
 * @param AlternateFunction
 * @return locStatus
 *
 **/
ENM_ErrorStatus_t gpioSetAlternateFunction(void * GPIO_PORT,GPIO_PIN_t gpioPin,AlternateFunction_t AlternateFunction);
/**
 *
 * @brief this function is responsible for locking pin configuration
 * @param GPIO_PORT
 * @return locStatus
 *
 **/
ENM_ErrorStatus_t gpioLockConfiguration(void * GPIO_PORT, GPIO_PIN_t gpioPin);




#endif /* MCAL_GPIO_GPIO_INTERFACE_H_ */
