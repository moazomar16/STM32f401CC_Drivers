/**********************************************************
 *
 *  @name Sched_interface.h
 *  @date: April 18, 2023
 *  @Author: Moaz Omar
 *  @category Service DRIVER
 *  @GitHub https://github.com/moazomar16
 *
 *********************************************************/
#ifndef WORKINGDIR_SCHED_INTERFACE_H
#define WORKINGDIR_SCHED_INTERFACE_H



extern const TasKsINFO_t tasksList[SCHED_RUNNABLE_NUMBER];

/**
 * @brief this type is used to calculate the remaining time for each task
 */
typedef struct
{
    /**
     * @brief contains task info
     */
    const TasKsINFO_t*  taskInfo;
    /**
     * @brief contains the remaining time for each task
     */
    uint32_t remain;
}Tasks_t;

/**
 * @brief this type is used define the two status of the scheduler
 */
typedef enum
{
    Sched_Idle=0,
    Sched_Busy
}Sched_Status_t;

/**
 * @brief this function is responsible for initializing scheduler
 * @return locStatus
 */
ENM_ErrorStatus_t schedInit(void);
/**
 * @brief this function is used to start the scheduler
 */
void schedStart(void);



#endif /*WORKINGDIR_SCHED_INTERFACE_H*/
