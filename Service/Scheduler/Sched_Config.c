/**********************************************************
 *
 *  @name Sched_Config.c
 *  @date: April 18, 2023
 *  @Author: Moaz Omar
 *  @category Service DRIVER
 *  @GitHub https://github.com/moazomar16
 *
 *********************************************************/

#include "Sched_Config.h"
#include "HAL/Switch/Switch_interface.h"

/**
 *
 * @brief This array is used to list all runnable used by Scheduler
 * @warning the Number of runnable must be define in the Sched_Config.h
 *
 * */
const TasKsINFO_t tasksList[SCHED_RUNNABLE_NUMBER]=
{
		[LED_GREEN_TASK]={

				.name=LED_GREEN_TASK,
				.period=200,
				.startDelay =0,
				.taskCbf=(void *) &switchTask
		},
        [LED_RED_TASK]={
                .name=LED_RED_TASK,
                .period=400,
                .startDelay =0,
                .taskCbf=(void *) &switchTask
        },[LED_YELLOW_TASK]={

				.name=LED_GREEN_TASK,
				.period=200,
				.startDelay =0,
				.taskCbf=(void *) &switchTask
		},
        [SWITCH_STATE_TASK]={
                .name=LED_RED_TASK,
                .period=5,
                .startDelay =0,
                .taskCbf=(void *) &switchTask
        }
};
