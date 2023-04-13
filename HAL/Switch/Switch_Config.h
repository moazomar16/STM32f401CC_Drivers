/**********************************************************
 *
 *  @name Switch_Config.h
 *  @date: Mar 26, 2023
 *  @Author: Moaz Omar
 *  @category HAL DRIVER
 *  @GitHub https://github.com/moazomar16
 *
 *********************************************************/

#ifndef WORKINGDIR_SWITCH_CONFIG_H
#define WORKINGDIR_SWITCH_CONFIG_H

#include "Libraries/Std_Types.h"
#include "MCAL/GPIO/GPIO_interface.h"

/**
 * @brief switch mode input pull up
 **/
#define SWITCH_PULL_UP     1
/**
 * @brief switch mode input pull down
 */
#define SWITCH_PULL_DOWN    0


/**
 * @brief Maximum number of switches
 */
#define MAX_SWITCH_NUMBER 1

typedef enum
{
    Switch_Run=0
}SWITCH_Name_t;

/**
 * @brief SWITCH configuration
 */
typedef struct
{
    void * port;
    uint32_t pin;
    uint32_t mode;
    uint32_t name;
}SWITCH_Config_t;


#endif /*WORKINGDIR_SWITCH_CONFIG_H*/
