/**********************************************************
 *
 *  @name Switch_interface.h
 *  @date: Mar 26, 2023
 *  @Author: Moaz Omar
 *  @category HAL DRIVER
 *  @GitHub https://github.com/moazomar16
 *
 *********************************************************/

#ifndef WORKINGDIR_SWITCH_INTERFACE_H
#define WORKINGDIR_SWITCH_INTERFACE_H

#include "Switch_Config.h"
#include "Libraries/Error_Status.h"


extern const SWITCH_Config_t  Switches[MAX_SWITCH_NUMBER];


typedef enum{
    SWITCH_Released=0,
    SWITCH_Pressed
}SWITCH_State_t;


/**
 * @brief this function is responsible for initializing switches
 * @return locStatus
 */
ENM_ErrorStatus_t switchInit(void);
/**
 *
 * @brief this function is responsible for getting switch value
 * @param switch
 * @param value
 * @return locStatus
 */
ENM_ErrorStatus_t switchGetState(uint32_t Switch, uint32_t *value);

/**
 * @brief this is a runnable task to get all switches state
 * @param void
 * @return void
 */
void switchTask(void);

#endif /*WORKINGDIR_SWITCH_INTERFACE_H*/
