/**********************************************************
 *
 *  @name Sched_Config.h
 *  @date: April 18, 2023
 *  @Author: Moaz Omar
 *  @category Service DRIVER
 *  @GitHub https://github.com/moazomar16
 *
 *********************************************************/

#ifndef WORKINGDIR_SCHED_CONFIG_H
#define WORKINGDIR_SCHED_CONFIG_H

#include <stdint-gcc.h>
#include "Libraries/Std_Types.h"

/**
 * @brief define the tick time
 */
#define SCHED_TICK_MS               1
/**
 * @brief set the number of tasks to run
 */
#define SCHED_RUNNABLE_NUMBER        4

/**
 * @brief Call back function type
 */
typedef void(* callBackFun_t)(void);

/**
 * @brief define each task name
 */
typedef enum
{
    LED_GREEN_TASK=0,
    LED_RED_TASK,
    LED_YELLOW_TASK,
    SWITCH_STATE_TASK
}TasksName_t;

/**
 * @brief task info type
 */
typedef struct
{
    TasksName_t name;
    uint32_t period;
    uint32_t startDelay;
    callBackFun_t taskCbf;
}TasKsINFO_t;



#endif /*WORKINGDIR_SCHED_CONFIG_H*/
