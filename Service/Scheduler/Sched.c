/**********************************************************
 *
 *  @name Sched.c
 *  @date: April 18, 2023
 *  @Author: Moaz Omar
 *  @category Service DRIVER
 *  @GitHub https://github.com/moazomar16
 *
 *********************************************************/
#include "Sched_Config.h"
#include "Libraries/Error_Status.h"
#include "Sched_interface.h"
#include "MCAL/SYSTICK/SYSTCK_interface.h"
#include "diag/trace.h"


#define DEBUG_MODE

/**
 * @brief this is the scheduler function used to run all runnable in their periods
 */
static void sched(void);

/**
 * @brief this function is used to as call back function to systick handler
 */
static void schedTickCbf(void);

/**
 * @brief array of all tasks
 */
Tasks_t Tasks[sizeof(tasksList) / sizeof(TasKsINFO_t)];

/**
 * this variable is used to indicate the state of the scheduler
 */
static Sched_Status_t GlobalSchedStatus=Sched_Idle;

/**
 * @brief this function is responsible for initializing scheduler
 * @return locStatus
 */
ENM_ErrorStatus_t schedInit(void)
{
    ENM_ErrorStatus_t locStatus;
    uint32_t locIterator;
    /* init systick */
    locStatus=systckInit();
    if (!locStatus)
    {
        locStatus =enm_Status_NOT_OK;
        #ifdef DEBUG_MODE
        trace_printf("[ERROR] Not ok in %d in line %d ",__FILE__,__LINE__);
        #endif
    }
    /* set call back function */
    locStatus = systckSetCallBackFunction(&schedTickCbf);
    if (!locStatus)
    {
        locStatus =enm_Status_NOT_OK;
        #ifdef DEBUG_MODE
        trace_printf("[ERROR] Not ok in %d in line %d ",__FILE__,__LINE__);
        #endif
    }
    /* set the scheduler periods */
    locStatus = systckSetPeriodTimeMS(SCHED_TICK_MS,25000000UL);
    if (!locStatus)
    {
        locStatus =enm_Status_NOT_OK;
        #ifdef DEBUG_MODE
        trace_printf("[ERROR] Not ok in %d in line %d ",__FILE__,__LINE__);
        #endif
    }
    /* initializing the tasks remaining time */
    for (locIterator = 0; locIterator < (sizeof(tasksList) / sizeof(TasKsINFO_t)) ; ++locIterator)
    {
        Tasks[locIterator].taskInfo = &tasksList[locIterator];
        Tasks[locIterator].remain= tasksList->startDelay;
    }
    locStatus =enm_Status_OK;
    return locStatus;
}

/**
 * @brief this function is used to start the scheduler
 * @return locStatus
 */
void schedStart(void)
{
    ENM_ErrorStatus_t locStatus;
    locStatus = systckStart();
    if (!locStatus)
    {
        locStatus =enm_Status_NOT_OK;
        #ifdef DEBUG_MODE
        trace_printf("[ERROR] Not ok in %d in line %d ",__FILE__,__LINE__);
        #endif
    }
    while (1)
    {
        if (GlobalSchedStatus == Sched_Busy)
        {
            sched();
            GlobalSchedStatus = Sched_Idle;
        }
    }

}

static void sched(void)
{
    ENM_ErrorStatus_t locStatus;
    uint32_t locIterator;
    /* loop to check all tasks */
    for (locIterator = 0; locIterator < (sizeof(tasksList) / sizeof(TasKsINFO_t)) ; ++locIterator)
    {
        /* check if the call back function is valid */
        if (Tasks[locIterator].taskInfo->taskCbf)
        {
            /* check if the remaining time is zero   */
            if (Tasks[locIterator].remain == 0)
            {
                /* call the task call back function */
                Tasks[locIterator].taskInfo->taskCbf();
                /* update remaining time with the task period */
                Tasks[locIterator].remain = Tasks[locIterator].taskInfo->period;
                locStatus=enm_Status_OK;
            }
            else
            {
                /* decrementing the remaining time by the Tick time */
                Tasks[locIterator].remain -= SCHED_TICK_MS;
                locStatus=enm_Status_OK;
            }
        } else
        {
            locStatus =enm_Status_NULL_Pointer;
            #ifdef DEBUG_MODE
            trace_printf("[ERROR] CPU Load 100% in %d in line %d ",__FILE__,__LINE__);
            #endif
        }
    }


}

static void schedTickCbf(void)
{
    ENM_ErrorStatus_t locStatus;
    /* check if scheduler is Idle or busy  */
    if (GlobalSchedStatus == Sched_Idle)
    {
        GlobalSchedStatus =Sched_Busy;
    }
    else
    {
        /* scheduler is busy and CPU load is 100% */
        locStatus =enm_Status_CPU_LOAD_100;
        #ifdef DEBUG_MODE
        trace_printf("[ERROR] CPU Load 100% in %d in line %d ",__FILE__,__LINE__);
        #endif
    }
}