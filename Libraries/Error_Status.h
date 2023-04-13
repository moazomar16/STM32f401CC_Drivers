/**********************************************************
 *
 *  @name Error_Status.h
 *  @date: Mar 23, 2023
 *  @Author: Moaz Omar
 *  @category Libraries
 *  @GitHub https://github.com/moazomar16
 *
 *********************************************************/

#ifndef WORKINGDIR_ERROR_STATUS_H
#define WORKINGDIR_ERROR_STATUS_H

typedef enum
{
    enm_Status_OK=0,
    enm_Status_NOT_OK,
    enm_Status_NULL_Pointer,
    enm_Status_Wrong_BUS,
    enm_Status_Wrong_Arguments,
    enm_Status_NOT_Ready,
    enm_Status_MORE_THAN_ONE_OPTION,
    enm_Status_TIME_OUT,
    enm_Status_EXCEEDS_MAX_VALUE
}ENM_ErrorStatus_t;

#endif /*WORKINGDIR_ERROR_STATUS_H*/
