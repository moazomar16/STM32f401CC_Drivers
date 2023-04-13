/**********************************************************
 *
 *  @name Switch.c
 *  @date: Mar 26, 2023
 *  @Author: Moaz Omar
 *  @category HAL DRIVER
 *  @GitHub https://github.com/moazomar16
 *
 *********************************************************/

#include "Libraries/Std_Types.h"
#include "Switch_interface.h"
#include "diag/trace.h"

/**
 * @brief this mode is for debug only
 */
#define DEBUG_MODE

static SWITCH_State_t currentSwitchesState[sizeof (Switches)/ sizeof (SWITCH_Config_t)];


ENM_ErrorStatus_t switchInit(void)
{
    /* create object from gpio configuration type  */
    GPIO_PIN_CONFIG_t gpioPinConfig;
    ENM_ErrorStatus_t locStatus = enm_Status_NOT_OK;
    uint32_t idx;
    /* loop used to init all define led  */
    for ( idx = 0; idx < sizeof (Switches)/ sizeof (SWITCH_Config_t ); ++idx)
    {
        /* sets gpio object  */
        gpioPinConfig.port=Switches[idx].port;
        gpioPinConfig.mode=Switches[idx].mode;
        gpioPinConfig.speed=LOW_SPEED;
        gpioPinConfig.pin=Switches[idx].pin;
        locStatus= gpioInit(&gpioPinConfig);
        /* check if the init function is all ok */
        if (locStatus)
        {
            locStatus= enm_Status_NOT_OK;
            /* used for debug purpose only */
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
ENM_ErrorStatus_t switchGetState(uint32_t Switch, uint32_t *value)
{
    ENM_ErrorStatus_t locStatus = enm_Status_NOT_OK;
    if (Switch > (sizeof (Switches)/ sizeof (SWITCH_Config_t)))
    {
        locStatus = enm_Status_Wrong_Arguments;
        /* used for debug purpose only */
        #ifdef DEBUG_MODE
        trace_printf("[ERROR] wrong switch in %d in line %d ",__FILE__,__LINE__);
        #endif
    }
    /* check for null pointer */
    else if (value)
    {
        locStatus = enm_Status_NULL_Pointer;
        /* used for debug purpose only */
        #ifdef DEBUG_MODE
        trace_printf("[ERROR] null pointer in %d in line %d ",__FILE__,__LINE__);
        #endif
    }
    else
    {
        /* if all input param are good return the current registered state  */
        *value= currentSwitchesState[Switch];
        locStatus = enm_Status_OK;
    }
    return locStatus;

}

void switchTask(void)
{
    /* create loc variables to keep track of the switches status */
    static uint8_t locCounter[sizeof (Switches)/ sizeof (SWITCH_Config_t)];
    SWITCH_State_t locCurrentState[sizeof (Switches)/ sizeof (SWITCH_Config_t)];
    static SWITCH_State_t locPreviousState[sizeof (Switches)/ sizeof (SWITCH_Config_t)];
    uint32_t locIDX=0;
    ENM_ErrorStatus_t locStatus;
    /* this loop is used to check all the switches state */
    for (locIDX = 0; locIDX < (sizeof (Switches)/ sizeof (SWITCH_Config_t)) ; ++locIDX)
    {
        /* call gpio get pin value to read the switch */
        locStatus= gpioGetPinValue(Switches[locIDX].port,Switches[locIDX].pin,&locCurrentState[locIDX]);
        /* check if the function executed with no errors */
        if (locStatus)
        {
            locStatus=enm_Status_NOT_OK;
        }
        /* check if the current state equal the previous state */
        if (locCurrentState[locIDX] == locPreviousState[locIDX])
        {
            /* update the counter with 1 */
            locCounter[locIDX]++;
        }
        /* the current state and the previous state are not equal */
        else
        {
            /* reset the counter */
            locCounter[locIDX]=0;
        }
        /* if the counter equals 5 means 5 stable reads of the switch */
        if (locCounter[locIDX] == 5)
        {
            /* update the switch with the new state */
            currentSwitchesState[locIDX]=locCurrentState[locIDX];
            /* Reset the counter */
            locCounter[locIDX]=0;
        }
        /* update the previous with the current state */
        locPreviousState[locIDX]= locCurrentState[locIDX];
    }
}