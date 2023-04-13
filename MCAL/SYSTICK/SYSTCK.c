/**********************************************************
 *
 *  @name SYSTCK.c
 *  @date: Mar 13, 2023
 *  @Author: Moaz Omar
 *  @category MCAL DRIVER
 *  @GitHub https://github.com/moazomar16
 *
 *********************************************************/

#include "Libraries/Std_Types.h"
#include "Libraries/Bit_Math.h"
#include "SYSTCK_interface.h"

/**
 * @brief the maximum value allowed by sysTick
 * @details The RELOAD value can be any value in the range 0x00000001-0x00FFFFFF
 */
#define MAX_LOAD_VALUE              0x00FFFFFF
/**
 * @brief used to start the counter
 */
#define SYSTCK_ENABLE_COUNTER        0x00000001
/**
 * @brief used to stop the counter
 */
#define SYSTCK_DISABLE_COUNTER       0xFFFFFFFE
#define ZERO                         0
#define SYSTCK_ENABLE_INTERRUPT      0x00000002
#define SYSTCK_DISABLE_INTERRUPT     0xFFFFFFFD

/**
 *
 * SysTick registers data type
 */
typedef struct
{
    /**
     * SysTick control and status register
     **/
    vuint32_t CTRL;
    /**
     * SysTick reload value register
     **/
    vuint32_t LOAD;
    /**
     * SysTick current value register
     **/
    vuint32_t VAL;
    /**
    * SysTick calibration value register
    **/
    vuint32_t CALIB;

}SYSTCK_REG_t;

/**
 * pointer to SysTick registers tupe
 */
#define SYSTCK ((volatile SYSTCK_REG_t *)0xE000E010)

static callBackFun_t gpCallBackFunctionPointer=NULL;

void SysTick_Handler(void){

    gpCallBackFunctionPointer();

}

ENM_SYSTCK_ERROR_STATUS_t systckStartCounter(uint32_t preLoadValue)
{
    ENM_SYSTCK_ERROR_STATUS_t locStatus = enmSYSTCK_Status_NOT_OK;
    uint32_t locPreLoadValue = preLoadValue;
    uint32_t locRegister=0;
    if (locPreLoadValue > MAX_LOAD_VALUE)
    {
        locStatus =enmSYSTCK_Status_EXCEEDS_MAX_VALUE;
    }
    else
    {
        /* disable the counter to reload new value  not needed*/
        locRegister = SYSTCK->CTRL;
        locRegister &=SYSTCK_DISABLE_COUNTER;
        SYSTCK->CTRL=locRegister;
        /*clear the current value of the load register*/
        locRegister = SYSTCK->LOAD;
        locRegister=ZERO;
        /* set the load register with the new value*/
        locRegister = locPreLoadValue;
        SYSTCK->LOAD= locRegister;
        /* clear the value of the val register */
        locRegister = SYSTCK->VAL;
        locRegister=ZERO;
        /* start the counter */
        locRegister = SYSTCK->CTRL;
        locRegister |=SYSTCK_ENABLE_COUNTER;
        SYSTCK->CTRL=locRegister;
        locStatus = enmSYSTCK_Status_OK;
    }

    return locStatus;
}
ENM_SYSTCK_ERROR_STATUS_t systckStopCounter(void)
{
    ENM_SYSTCK_ERROR_STATUS_t locStatus = enmSYSTCK_Status_NOT_OK;
    uint32_t locRegister=0;
    /* disable the counter to reload new value */
    locRegister = SYSTCK->CTRL;
    locRegister &=SYSTCK_DISABLE_COUNTER;
    SYSTCK->CTRL=locRegister;
    locStatus =enmSYSTCK_Status_OK;
    return locStatus;
}
ENM_SYSTCK_ERROR_STATUS_t systckGetCurrentValue(uint32_t * value)
{
    ENM_SYSTCK_ERROR_STATUS_t locStatus = enmSYSTCK_Status_NOT_OK;
    uint32_t locValue=0;
    /* check if null pointer  */
    if (!value)
    {
        locStatus = enmSYSTCK_Status_NULL_Pointer;
    }
    else
    {
        /* reading the value register */
        locValue=SYSTCK->VAL;
        *value=locValue;
        locStatus= enmSYSTCK_Status_OK;
    }
    return locStatus;
}
ENM_SYSTCK_ERROR_STATUS_t systckInterruptStatus(uint8_t interruptStatus)
{
    ENM_SYSTCK_ERROR_STATUS_t locStatus = enmSYSTCK_Status_NOT_OK;

    return locStatus;
}
ENM_SYSTCK_ERROR_STATUS_t systckSetCallBackFunction(callBackFun_t cbf)
{
    ENM_SYSTCK_ERROR_STATUS_t locStatus = enmSYSTCK_Status_NOT_OK;
    if (!cbf)
    {
        locStatus = enmSYSTCK_Status_NULL_Pointer;
    }
    else
    {
        gpCallBackFunctionPointer=cbf;
        locStatus = enmSYSTCK_Status_OK;
    }

    return locStatus;
}

