/**********************************************************
 *
 *  @name LED.c
 *  @date: Mar 24, 2023
 *  @Author: Moaz Omar
 *  @category HAL DRIVER
 *  @GitHub https://github.com/moazomar16
 *
 *********************************************************/

#include "Libraries/Std_Types.h"
#include "Libraries/Error_Status.h"
#include "LED_interface.h"
#include "diag/trace.h"

/**
 * @brief this mode is for debug only
 */
#define DEBUG_MODE

ENM_ErrorStatus_t ledInit(void)
{
    /* create object from gpio configuration type  */
    GPIO_PIN_CONFIG_t gpioPinConfig;
    ENM_ErrorStatus_t locStatus = enm_Status_NOT_OK;
    uint32_t idx;
    /* loop used to init all define led  */
    for ( idx = 0; idx < sizeof (LEDs)/ sizeof (LED_Config_t); ++idx)
    {
        /* sets gpio object  */
        gpioPinConfig.port=LEDs[idx].port;
        gpioPinConfig.mode=OUTPUT_PUSH_PULL;
        gpioPinConfig.speed=LEDs[idx].speed;
        gpioPinConfig.pin=LEDs[idx].pin;
        locStatus= gpioInit(&gpioPinConfig);
        /* check if the init function is all ok */
        if (locStatus)
        {
            locStatus= enm_Status_NOT_OK;
            #ifdef DEBUG_MODE
            trace_printf("[ERROR] null pointer in %d in line %d ",__FILE__,__LINE__);
            #endif
        }
        else
        {
            locStatus = enm_Status_OK;
        }
    }
    return locStatus;
}
ENM_ErrorStatus_t ledSet( uint32_t led, uint32_t state)
{
    ENM_ErrorStatus_t locStatus = enm_Status_NOT_OK;
    if ((led < ( sizeof (LEDs)/ sizeof (LED_Config_t))) && state <2 )
    {
        /* call gpio set pin to turn on or off led */
        locStatus = gpioSetPinValue(LEDs[led].port,LEDs[led].pin,state^LEDs[led].mode);
        /* check if the gpio set pin function is all ok */
        if (locStatus)
        {
            locStatus= enm_Status_NOT_OK;
            #ifdef DEBUG_MODE
            trace_printf("[ERROR] not ok in %d in line %d ",__FILE__,__LINE__);
            #endif
        }
        else
        {
            locStatus = enm_Status_OK;
        }
    }
    else
    {
        locStatus = enm_Status_NOT_OK;
        #ifdef DEBUG_MODE
        trace_printf("[ERROR] not ok in %d in line %d ",__FILE__,__LINE__);
        #endif
    }


    return locStatus;

}

