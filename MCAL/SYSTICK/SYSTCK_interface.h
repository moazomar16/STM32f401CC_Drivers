/**********************************************************
 *
 *  @name SYSTCK_interface.h
 *  @date: Mar 13, 2023
 *  @Author: Moaz Omar
 *  @category MCAL DRIVER
 *  @GitHub https://github.com/moazomar16
 *
 *********************************************************/

#ifndef COTS_INSHALLAH_SYSTCK_H
#define COTS_INSHALLAH_SYSTCK_H




#define SYSTCK_INTERRUPT_ENABLE             0xD0000002
#define SYSTCK_INTERRUPT_DISABLE            0xDFFFFFFD
#define SYSTCK_CLK_SOURCE_AHB_BY_8          0xDFFFFFFB
#define SYSTCK_CLK_SOURCE_AHB               0xD0000004

/**
 *  @brief SysTick error status
 **/
typedef enum
{
    enmSYSTCK_Status_OK=0,
    enmSYSTCK_Status_NOT_OK,
    enmSYSTCK_Status_NULL_Pointer,
    enmSYSTCK_Status_Wrong_Arguments,
    enmSYSTCK_Status_TIME_OUT,
    enmSYSTCK_Status_EXCEEDS_MAX_VALUE
}ENM_SYSTCK_ERROR_STATUS_t;
/**
 * @brief call back function type
 */
typedef void(* callBackFun_t)(void);

/**
 *
 * @brief This function responsible for setting the preload value of the counter
 * @warning preload value must be less than or equal to ( 0x00FFFFFF )
 * @param preLoadValue
 * @return locStatus
 **/
ENM_SYSTCK_ERROR_STATUS_t systckStartCounter(uint32_t preLoadValue);
/**
 *
 * @brief This function responsible for stopping the counter
 *
 * @param void
 * @return locStatus
 *
 **/
ENM_SYSTCK_ERROR_STATUS_t systckStopCounter(void);
/**
 *
 * @brief This function responsible for getting the remaining value of the counter
 * @param value
 * @return locStatus
 *
 **/
ENM_SYSTCK_ERROR_STATUS_t systckGetCurrentValue(uint32_t * value);
/**
 *
 * @brief This function responsible for controlling the interrupt status of the counter
 * @param interruptStatus
 * @return locStatus
 *
 **/
ENM_SYSTCK_ERROR_STATUS_t systckInterruptStatus(uint8_t interruptStatus);
/**
 *
 * @brief This function responsible for setting the call back function that will be used when the counter finishes
 * @param cbf
 * @return locStatus
 *
 **/
ENM_SYSTCK_ERROR_STATUS_t systckSetCallBackFunction(callBackFun_t cbf);







#endif /*COTS_INSHALLAH_SYSTCK_H*/
