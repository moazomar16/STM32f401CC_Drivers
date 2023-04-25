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



#define SYSTCK_INTERRUPT_ENABLE             0x00000002
#define SYSTCK_INTERRUPT_DISABLE            0x00000000
#define SYSTCK_CLK_SOURCE_AHB_BY_8          0x00000000
#define SYSTCK_CLK_SOURCE_AHB               0x00000004

#define SYSTICK_CLOCK_SOURCE                SYSTCK_CLK_SOURCE_AHB
#define SYSTICK_INTERRUPT_STATE             SYSTCK_INTERRUPT_ENABLE



/**
 * @brief call back function type
 */
typedef void(* callBackFun_t)(void);


/**
 *
 * @brief This function responsible for initializing the systick with the clock source and to enable interrupt
 * @return locStatus
 **/
ENM_ErrorStatus_t systckInit(void);


/**
 *
 * @brief This function responsible for starting the counter
 * @return locStatus
 **/
ENM_ErrorStatus_t systckStart(void);
/**
 *
 * @brief This function responsible for stopping the counter
 *
 * @param void
 * @return locStatus
 *
 **/
ENM_ErrorStatus_t systckStopCounter(void);
/**
 *
 * @brief This function responsible for getting the remaining value of the counter
 * @param value
 * @return locStatus
 *
 **/
ENM_ErrorStatus_t systckGetCurrentValue(uint32_t * value);
/**
 *
 * @brief This function responsible for setting the call back function that will be used when the counter finishes
 * @param cbf
 * @return locStatus
 *
 **/
ENM_ErrorStatus_t systckSetCallBackFunction(callBackFun_t cbf);

/**
 *
 * @brief this function is used to set periods
 * @param TickTime
 * @param SystemClock
 * @return locStatus
 */
ENM_ErrorStatus_t systckSetPeriodTimeMS(uint32_t TickTime,uint32_t SystemClock);






#endif /*COTS_INSHALLAH_SYSTCK_H*/
