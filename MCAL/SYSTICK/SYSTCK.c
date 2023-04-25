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
#include "Libraries/Error_Status.h"
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

/**
 *
 * @brief This function responsible for setting the preload value of the counter
 * @warning preload value must be less than or equal to ( 0x00FFFFFF )
 * @param preLoadValue
 * @return locStatus
 **/
static ENM_ErrorStatus_t systckLoadCounter(uint32_t preLoadValue );

void SysTick_Handler()
{
    gpCallBackFunctionPointer();
}

ENM_ErrorStatus_t systckInit(void)
{
    ENM_ErrorStatus_t locStatus = enm_Status_NOT_OK;
    uint32_t locRegister=0;
    locRegister = SYSTCK->CTRL;
    locRegister &= ~(0x7);
    locRegister |= SYSTICK_INTERRUPT_STATE | SYSTICK_CLOCK_SOURCE;
    SYSTCK->CTRL =locRegister;
    locStatus =enm_Status_OK;
    return locStatus;

}
ENM_ErrorStatus_t systckSetPeriodTimeMS(uint32_t TickTime,uint32_t SystemClock)
{
    ENM_ErrorStatus_t locStatus = enm_Status_NOT_OK;
    uint32_t locTick=0;
    locTick = (SystemClock / 1000) * TickTime;
    systckLoadCounter(locTick);
    locStatus =enm_Status_OK;
    return locStatus;
}
ENM_ErrorStatus_t systckStart(void)
{
    ENM_ErrorStatus_t locStatus = enm_Status_NOT_OK;
    uint32_t locRegister=0;
    /* start the counter */
    locRegister = SYSTCK->CTRL;
    locRegister |=SYSTCK_ENABLE_COUNTER;
    SYSTCK->CTRL=locRegister;
    locStatus = enm_Status_OK;
    return locStatus;
}
ENM_ErrorStatus_t systckStopCounter(void)
{
    ENM_ErrorStatus_t locStatus = enm_Status_NOT_OK;
    uint32_t locRegister=0;
    /* disable the counter to reload new value */
    locRegister = SYSTCK->CTRL;
    locRegister &=SYSTCK_DISABLE_COUNTER;
    SYSTCK->CTRL=locRegister;
    locStatus =enm_Status_OK;
    return locStatus;
}
ENM_ErrorStatus_t systckGetCurrentValue(uint32_t * value)
{
    ENM_ErrorStatus_t locStatus = enm_Status_NOT_OK;
    uint32_t locValue=0;
    /* check if null pointer  */
    if (!value)
    {
        locStatus = enm_Status_NULL_Pointer;
    }
    else
    {
        /* reading the value register */
        locValue=SYSTCK->VAL;
        *value=locValue;
        locStatus= enm_Status_OK;
    }
    return locStatus;
}
ENM_ErrorStatus_t systckSetCallBackFunction(callBackFun_t cbf)
{
    ENM_ErrorStatus_t locStatus = enm_Status_NOT_OK;
    if (!cbf)
    {
        locStatus = enm_Status_NULL_Pointer;
    }
    else
    {
        gpCallBackFunctionPointer=cbf;
        locStatus = enm_Status_OK;
    }

    return locStatus;
}

static ENM_ErrorStatus_t systckLoadCounter(uint32_t preLoadValue )
{
    ENM_ErrorStatus_t locStatus = enm_Status_NOT_OK;
    uint32_t locPreLoadValue = preLoadValue;
    uint32_t locRegister=0;
    if (locPreLoadValue > MAX_LOAD_VALUE)
    {
        locStatus =enm_Status_EXCEEDS_MAX_VALUE;
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
        SYSTCK->VAL = locRegister ;
        locStatus = enm_Status_OK;
    }

    return locStatus;
}
