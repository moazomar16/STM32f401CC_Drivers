/**********************************************************
 *
 *  @name GPIO.c
 *  @date: Mar 23, 2023
 *  @Author: Moaz Omar
 *  @category MCAL DRIVER
 *  @GitHub https://github.com/moazomar16
 *
 *********************************************************/

#include "Libraries/Std_Types.h"
#include "Libraries/Bit_Math.h"
#include "Libraries/Error_Status.h"
#include "GPIO_interface.h"
#include "diag/trace.h"

/**
 * @brief this mode is for debug only
 */
#define DEBUG_MODE

/**
 * @brief Pin Mode Input
 **/
#define INPUT_MODE                  0x00
/**
 * @brief Pin Mode Output
 **/
#define OUTPUT_MODE                 0x01
/**
 * @brief Pin Mode Alternate Function
 **/
#define ALTERNATE_FUNC_MODE         0x10
/**
 * @brief Pin Mode Analog
 **/
#define ANALOG_MODE                 0x11

/**
 * @brief pin output mode push pull
 **/
#define OUTPUT_PUSH_PULL_MODE            0
/**
 * @brief pin output mode push pull
 **/
#define OUTPUT_OPEN_DRAIN_MODE           1



/**
 * @brief Pull State No pull up or down
 **/
#define NO_PULL                     0x00
/**
 * @brief Pull State pull up
 **/
#define PULL_UP                     0x01
/**
 * @brief Pull State pull down
 **/
#define PULL_DOWN                   0x10

typedef struct
{
    /**
     * @brief GPIO port mode register
     **/
    vuint32_t MODE;
    /**
     * @brief GPIO port output type register
     **/
    vuint32_t OTYPE;
    /**
     * @brief GPIO port output speed register
     **/
    vuint32_t OSPEED;
    /**
    * @brief GPIO port pull-up/pull-down register
    **/
    vuint32_t PUPD;
    /**
    * @brief GPIO port input data register
    **/
    vuint32_t IDR;
    /**
    * @brief GPIO port output data register
    **/
    vuint32_t ODR;
    /**
     * GPIO port bit set/reset register
     **/
    vuint32_t BSRR;
    /**
     * @brief GPIO port configuration lock register
    **/
    vuint32_t LCK;
    /**
    * @brief GPIO alternate function low register
    **/
    vuint32_t AFRL;
    /**
    * @brief GPIO alternate function high register
    **/
    vuint32_t AFRH;
}GPIO_REG_t;

/**
 *
 * @brief this function is used to set pin mode
 * @param GPIO_PORT
 * @param gpioPin
 * @param pinMode
 * @return locStatus
 **/
static ENM_ErrorStatus_t gpioSetMode(GPIO_REG_t * GPIO_PORT, GPIO_PIN_t gpioPin, uint32_t pinMode);
/**
 *
 * @brief this function is used to set pin output type
 * @param GPIO_PORT
 * @param gpioPin
 * @param pinOutputType
 * @return locStatus
 */
static ENM_ErrorStatus_t gpioSetOutputType(GPIO_REG_t * GPIO_PORT, GPIO_PIN_t gpioPin, uint32_t pinOutputType);
/**
 *
 * @brief this function is used to set pin output Speed
 * @param GPIO_PORT
 * @param gpioPin
 * @param pinSped
 * @return locStatus
 */
static ENM_ErrorStatus_t gpioSpeed(GPIO_REG_t * GPIO_PORT, GPIO_PIN_t gpioPin, uint32_t pinSpeed);
/**
 *
 * @brief this function is used to set pin pull state
 * @param GPIO_PORT
 * @param gpioPin
 * @param pinPullState
 * @return locStatus
 */
static ENM_ErrorStatus_t gpioSetPullState(GPIO_REG_t * GPIO_PORT, GPIO_PIN_t gpioPin, uint32_t pinPullState);


ENM_ErrorStatus_t gpioInit(GPIO_PIN_CONFIG_t const *pinConfig)
{
    ENM_ErrorStatus_t locStatus = enm_Status_NOT_OK;
    GPIO_PIN_CONFIG_t const *locPinConfig =pinConfig;
    GPIO_REG_t *GPIO =(GPIO_REG_t *)locPinConfig->port;
    /* Check if the port address is valid */
    if (!(locPinConfig->port))
    {
        locStatus=enm_Status_NULL_Pointer;
        #ifdef DEBUG_MODE
        trace_printf("[ERROR] null pointer in %d in line %d ",__FILE__,__LINE__);
        #endif
    }
    /* check if the number of bin is valid */
    else if (locPinConfig->pin <16)
    {
        switch (locPinConfig->mode)
        {
            case OUTPUT_PUSH_PULL:
                locStatus = gpioSetMode(GPIO,locPinConfig->pin,OUTPUT_MODE);
                if(locStatus)
                {
                    locStatus =enm_Status_NOT_OK;
                    #ifdef DEBUG_MODE
                    trace_printf("[ERROR] null pointer in %d in line %d ",__FILE__,__LINE__);
                    #endif
                }
                locStatus = gpioSetOutputType(GPIO,locPinConfig->pin,OUTPUT_PUSH_PULL_MODE);
                if(locStatus)
                {
                    locStatus =enm_Status_NOT_OK;
                    #ifdef DEBUG_MODE
                    trace_printf("[ERROR] null pointer in %d in line %d ",__FILE__,__LINE__);
                    #endif
                }
                locStatus = gpioSetPullState(GPIO,locPinConfig->pin,NO_PULL);
                if(locStatus)
                {
                    locStatus =enm_Status_NOT_OK;
                    #ifdef DEBUG_MODE
                    trace_printf("[ERROR] null pointer in %d in line %d ",__FILE__,__LINE__);
                    #endif
                }
                break;

            case OUTPUT_PUSH_PULL_PULL_UP:
                locStatus = gpioSetMode(GPIO,locPinConfig->pin,OUTPUT_MODE);
                if(locStatus)
                {
                    locStatus =enm_Status_NOT_OK;
                    #ifdef DEBUG_MODE
                    trace_printf("[ERROR] null pointer in %d in line %d ",__FILE__,__LINE__);
                    #endif
                }
                locStatus = gpioSetOutputType(GPIO,locPinConfig->pin,OUTPUT_PUSH_PULL_MODE);
                if(locStatus)
                {
                    locStatus =enm_Status_NOT_OK;
                #ifdef DEBUG_MODE
                    trace_printf("[ERROR] null pointer in %d in line %d ",__FILE__,__LINE__);
                #endif
                }
                locStatus = gpioSetPullState(GPIO,locPinConfig->pin,PULL_UP);
                if(locStatus)
                {
                    locStatus =enm_Status_NOT_OK;
                    #ifdef DEBUG_MODE
                    trace_printf("[ERROR] null pointer in %d in line %d ",__FILE__,__LINE__);
                    #endif
                }

                break;
            case OUTPUT_PUSH_PULL_PULL_DOWN:
                locStatus = gpioSetMode(GPIO,locPinConfig->pin,OUTPUT_MODE);
                if(locStatus)
                {
                    locStatus =enm_Status_NOT_OK;
                    #ifdef DEBUG_MODE
                    trace_printf("[ERROR] null pointer in %d in line %d ",__FILE__,__LINE__);
                    #endif
                }
                locStatus = gpioSetOutputType(GPIO,locPinConfig->pin,OUTPUT_PUSH_PULL_MODE);
                if(locStatus)
                {
                    locStatus =enm_Status_NOT_OK;
                    #ifdef DEBUG_MODE
                    trace_printf("[ERROR] null pointer in %d in line %d ",__FILE__,__LINE__);
                    #endif
                }
                locStatus = gpioSetPullState(GPIO,locPinConfig->pin,PULL_DOWN);
                if(locStatus)
                {
                    locStatus =enm_Status_NOT_OK;
                    #ifdef DEBUG_MODE
                    trace_printf("[ERROR] null pointer in %d in line %d ",__FILE__,__LINE__);
                    #endif
                }
                break;

            case OUTPUT_OPEN_DRAIN:
                locStatus = gpioSetMode(GPIO,locPinConfig->pin,OUTPUT_MODE);
                if(locStatus)
                {
                    locStatus =enm_Status_NOT_OK;
                    #ifdef DEBUG_MODE
                    trace_printf("[ERROR] null pointer in %d in line %d ",__FILE__,__LINE__);
                    #endif
                }
                locStatus = gpioSetOutputType(GPIO,locPinConfig->pin,OUTPUT_OPEN_DRAIN_MODE);
                if(locStatus)
                {
                    locStatus =enm_Status_NOT_OK;
                    #ifdef DEBUG_MODE
                    trace_printf("[ERROR] null pointer in %d in line %d ",__FILE__,__LINE__);
                    #endif
                }
                locStatus = gpioSetPullState(GPIO,locPinConfig->pin,NO_PULL);
                if(locStatus)
                {
                    locStatus =enm_Status_NOT_OK;
                    #ifdef DEBUG_MODE
                    trace_printf("[ERROR] null pointer in %d in line %d ",__FILE__,__LINE__);
                    #endif
                }
                break;
            case OUTPUT_OPEN_DRAIN_PULL_UP:
                locStatus = gpioSetMode(GPIO,locPinConfig->pin,OUTPUT_MODE);
                if(locStatus)
                {
                    locStatus =enm_Status_NOT_OK;
                    #ifdef DEBUG_MODE
                    trace_printf("[ERROR] null pointer in %d in line %d ",__FILE__,__LINE__);
                    #endif
                }
                locStatus = gpioSetOutputType(GPIO,locPinConfig->pin,OUTPUT_OPEN_DRAIN_MODE);
                if(locStatus)
                {
                    locStatus =enm_Status_NOT_OK;
                #ifdef DEBUG_MODE
                    trace_printf("[ERROR] null pointer in %d in line %d ",__FILE__,__LINE__);
                #endif
                }
                locStatus = gpioSetPullState(GPIO,locPinConfig->pin,PULL_UP);
                if(locStatus)
                {
                    locStatus =enm_Status_NOT_OK;
                #ifdef DEBUG_MODE
                    trace_printf("[ERROR] null pointer in %d in line %d ",__FILE__,__LINE__);
                #endif
                }
                break;

            case OUTPUT_OPEN_DRAIN_PULL_DOWN:
                locStatus = gpioSetMode(GPIO,locPinConfig->pin,OUTPUT_MODE);
                if(locStatus)
                {
                    locStatus =enm_Status_NOT_OK;
                    #ifdef DEBUG_MODE
                    trace_printf("[ERROR] null pointer in %d in line %d ",__FILE__,__LINE__);
                    #endif
                }
                locStatus = gpioSetOutputType(GPIO,locPinConfig->pin,OUTPUT_OPEN_DRAIN_MODE);
                if(locStatus)
                {
                    locStatus =enm_Status_NOT_OK;
                    #ifdef DEBUG_MODE
                    trace_printf("[ERROR] null pointer in %d in line %d ",__FILE__,__LINE__);
                    #endif
                }
                locStatus = gpioSetPullState(GPIO,locPinConfig->pin,PULL_DOWN);
                if(locStatus)
                {
                    locStatus =enm_Status_NOT_OK;
                    #ifdef DEBUG_MODE
                    trace_printf("[ERROR] null pointer in %d in line %d ",__FILE__,__LINE__);
                    #endif
                }
                break;

            case OUTPUT_ALTERNATE_FUNCTION_PUSH_PULL:
                locStatus = gpioSetMode(GPIO,locPinConfig->pin,ALTERNATE_FUNC_MODE);
                if(locStatus)
                {
                    locStatus =enm_Status_NOT_OK;
                    #ifdef DEBUG_MODE
                    trace_printf("[ERROR] null pointer in %d in line %d ",__FILE__,__LINE__);
                    #endif
                }
                locStatus = gpioSetOutputType(GPIO,locPinConfig->pin,OUTPUT_PUSH_PULL_MODE);
                if(locStatus)
                {
                    locStatus =enm_Status_NOT_OK;
                    #ifdef DEBUG_MODE
                    trace_printf("[ERROR] null pointer in %d in line %d ",__FILE__,__LINE__);
                    #endif
                }
                locStatus = gpioSetPullState(GPIO,locPinConfig->pin,NO_PULL);
                if(locStatus)
                {
                    locStatus =enm_Status_NOT_OK;
                    #ifdef DEBUG_MODE
                    trace_printf("[ERROR] null pointer in %d in line %d ",__FILE__,__LINE__);
                    #endif
                }
                break;

            case OUTPUT_ALTERNATE_FUNCTION_PUSH_PULL_PULL_UP:
                locStatus = gpioSetMode(GPIO,locPinConfig->pin,ALTERNATE_FUNC_MODE);
                if(locStatus)
                {
                    locStatus =enm_Status_NOT_OK;
                    #ifdef DEBUG_MODE
                    trace_printf("[ERROR] null pointer in %d in line %d ",__FILE__,__LINE__);
                    #endif
                }
                locStatus = gpioSetOutputType(GPIO,locPinConfig->pin,OUTPUT_PUSH_PULL_MODE);
                if(locStatus)
                {
                    locStatus =enm_Status_NOT_OK;
                    #ifdef DEBUG_MODE
                    trace_printf("[ERROR] null pointer in %d in line %d ",__FILE__,__LINE__);
                    #endif
                }
                locStatus = gpioSetPullState(GPIO,locPinConfig->pin,PULL_UP);
                if(locStatus)
                {
                    locStatus =enm_Status_NOT_OK;
                    #ifdef DEBUG_MODE
                    trace_printf("[ERROR] null pointer in %d in line %d ",__FILE__,__LINE__);
                    #endif
                }

                break;
            case OUTPUT_ALTERNATE_FUNCTION_PUSH_PULL_PULL_DOWN:
                locStatus = gpioSetMode(GPIO,locPinConfig->pin,ALTERNATE_FUNC_MODE);
                if(locStatus)
                {
                    locStatus =enm_Status_NOT_OK;
                    #ifdef DEBUG_MODE
                    trace_printf("[ERROR] null pointer in %d in line %d ",__FILE__,__LINE__);
                    #endif
                }
                locStatus = gpioSetOutputType(GPIO,locPinConfig->pin,OUTPUT_PUSH_PULL_MODE);
                if(locStatus)
                {
                    locStatus =enm_Status_NOT_OK;
                    #ifdef DEBUG_MODE
                    trace_printf("[ERROR] null pointer in %d in line %d ",__FILE__,__LINE__);
                    #endif
                }
                locStatus = gpioSetPullState(GPIO,locPinConfig->pin,PULL_DOWN);
                if(locStatus)
                {
                    locStatus =enm_Status_NOT_OK;
                    #ifdef DEBUG_MODE
                    trace_printf("[ERROR] null pointer in %d in line %d ",__FILE__,__LINE__);
                    #endif
                }
                break;
            case OUTPUT_ALTERNATE_FUNCTION_OPEN_DRAIN:
                locStatus = gpioSetMode(GPIO,locPinConfig->pin,ALTERNATE_FUNC_MODE);
                if(locStatus)
                {
                    locStatus =enm_Status_NOT_OK;
                    #ifdef DEBUG_MODE
                    trace_printf("[ERROR] null pointer in %d in line %d ",__FILE__,__LINE__);
                    #endif
                }
                locStatus = gpioSetOutputType(GPIO,locPinConfig->pin,OUTPUT_OPEN_DRAIN_MODE);
                if(locStatus)
                {
                    locStatus =enm_Status_NOT_OK;
                    #ifdef DEBUG_MODE
                    trace_printf("[ERROR] null pointer in %d in line %d ",__FILE__,__LINE__);
                    #endif
                }
                locStatus = gpioSetPullState(GPIO,locPinConfig->pin,NO_PULL);
                if(locStatus)
                {
                    locStatus =enm_Status_NOT_OK;
                    #ifdef DEBUG_MODE
                    trace_printf("[ERROR] null pointer in %d in line %d ",__FILE__,__LINE__);
                    #endif
                }
                break;
            case OUTPUT_ALTERNATE_FUNCTION_OPEN_DRAIN_PULL_UP:
                locStatus = gpioSetMode(GPIO,locPinConfig->pin,ALTERNATE_FUNC_MODE);
                if(locStatus)
                {
                    locStatus =enm_Status_NOT_OK;
                    #ifdef DEBUG_MODE
                    trace_printf("[ERROR] null pointer in %d in line %d ",__FILE__,__LINE__);
                    #endif
                }
                locStatus = gpioSetOutputType(GPIO,locPinConfig->pin,OUTPUT_OPEN_DRAIN_MODE);
                if(locStatus)
                {
                    locStatus =enm_Status_NOT_OK;
                    #ifdef DEBUG_MODE
                    trace_printf("[ERROR] null pointer in %d in line %d ",__FILE__,__LINE__);
                    #endif
                }
                locStatus = gpioSetPullState(GPIO,locPinConfig->pin,PULL_UP);
                if(locStatus)
                {
                    locStatus =enm_Status_NOT_OK;
                    #ifdef DEBUG_MODE
                    trace_printf("[ERROR] null pointer in %d in line %d ",__FILE__,__LINE__);
                    #endif
                }
                break;

            case OUTPUT_ALTERNATE_FUNCTION_OPEN_DRAIN_PULL_DOWN:
                locStatus = gpioSetMode(GPIO,locPinConfig->pin,ALTERNATE_FUNC_MODE);
                if(locStatus)
                {
                    locStatus =enm_Status_NOT_OK;
                    #ifdef DEBUG_MODE
                    trace_printf("[ERROR] null pointer in %d in line %d ",__FILE__,__LINE__);
                    #endif
                }
                locStatus = gpioSetOutputType(GPIO,locPinConfig->pin,OUTPUT_OPEN_DRAIN_MODE);
                if(locStatus)
                {
                    locStatus =enm_Status_NOT_OK;
                #ifdef DEBUG_MODE
                    trace_printf("[ERROR] null pointer in %d in line %d ",__FILE__,__LINE__);
                #endif
                }
                locStatus = gpioSetPullState(GPIO,locPinConfig->pin,PULL_DOWN);
                if(locStatus)
                {
                    locStatus =enm_Status_NOT_OK;
                    #ifdef DEBUG_MODE
                    trace_printf("[ERROR] null pointer in %d in line %d ",__FILE__,__LINE__);
                    #endif
                }
                break;

            case INPUT_FLOATING:
                locStatus = gpioSetMode(GPIO,locPinConfig->pin,INPUT_MODE);
                if(locStatus)
                {
                    locStatus =enm_Status_NOT_OK;
                    #ifdef DEBUG_MODE
                    trace_printf("[ERROR] null pointer in %d in line %d ",__FILE__,__LINE__);
                    #endif
                }
                locStatus = gpioSetOutputType(GPIO,locPinConfig->pin,OUTPUT_PUSH_PULL_MODE);
                if(locStatus)
                {
                    locStatus =enm_Status_NOT_OK;
                    #ifdef DEBUG_MODE
                    trace_printf("[ERROR] null pointer in %d in line %d ",__FILE__,__LINE__);
                    #endif
                }
                locStatus = gpioSetPullState(GPIO,locPinConfig->pin,NO_PULL);
                if(locStatus)
                {
                    locStatus =enm_Status_NOT_OK;
                    #ifdef DEBUG_MODE
                    trace_printf("[ERROR] null pointer in %d in line %d ",__FILE__,__LINE__);
                    #endif
                }
                break;
            case INPUT_PULL_UP:
                locStatus = gpioSetMode(GPIO,locPinConfig->pin,INPUT_MODE);
                if(locStatus)
                {
                    locStatus =enm_Status_NOT_OK;
                    #ifdef DEBUG_MODE
                    trace_printf("[ERROR] null pointer in %d in line %d ",__FILE__,__LINE__);
                    #endif
                }
                locStatus = gpioSetOutputType(GPIO,locPinConfig->pin,OUTPUT_PUSH_PULL_MODE);
                if(locStatus)
                {
                    locStatus =enm_Status_NOT_OK;
                    #ifdef DEBUG_MODE
                    trace_printf("[ERROR] null pointer in %d in line %d ",__FILE__,__LINE__);
                    #endif
                }
                locStatus = gpioSetPullState(GPIO,locPinConfig->pin,PULL_UP);
                if(locStatus)
                {
                    locStatus =enm_Status_NOT_OK;
                    #ifdef DEBUG_MODE
                    trace_printf("[ERROR] null pointer in %d in line %d ",__FILE__,__LINE__);
                    #endif
                }
                break;
            case INPUT_PULL_DOWN:
                locStatus = gpioSetMode(GPIO,locPinConfig->pin,INPUT_MODE);
                if(locStatus)
                {
                    locStatus =enm_Status_NOT_OK;
                    #ifdef DEBUG_MODE
                    trace_printf("[ERROR] null pointer in %d in line %d ",__FILE__,__LINE__);
                    #endif
                }
                locStatus = gpioSetOutputType(GPIO,locPinConfig->pin,OUTPUT_PUSH_PULL_MODE);
                if(locStatus)
                {
                    locStatus =enm_Status_NOT_OK;
                    #ifdef DEBUG_MODE
                    trace_printf("[ERROR] null pointer in %d in line %d ",__FILE__,__LINE__);
                    #endif
                }
                locStatus = gpioSetPullState(GPIO,locPinConfig->pin,PULL_DOWN);
                if(locStatus)
                {
                    locStatus =enm_Status_NOT_OK;
                #ifdef DEBUG_MODE
                    trace_printf("[ERROR] null pointer in %d in line %d ",__FILE__,__LINE__);
                #endif
                }
                break;

            case ANALOG_INPUT_OUTPUT:
                locStatus = gpioSetMode(GPIO,locPinConfig->pin,ANALOG_MODE);
                if(locStatus)
                {
                    locStatus =enm_Status_NOT_OK;
                    #ifdef DEBUG_MODE
                    trace_printf("[ERROR] null pointer in %d in line %d ",__FILE__,__LINE__);
                    #endif
                }
                locStatus = gpioSetOutputType(GPIO,locPinConfig->pin,OUTPUT_PUSH_PULL_MODE);
                if(locStatus)
                {
                    locStatus =enm_Status_NOT_OK;
                    #ifdef DEBUG_MODE
                    trace_printf("[ERROR] null pointer in %d in line %d ",__FILE__,__LINE__);
                    #endif
                }
                locStatus = gpioSetPullState(GPIO,locPinConfig->pin,NO_PULL);
                if(locStatus)
                {
                    locStatus =enm_Status_NOT_OK;
                    #ifdef DEBUG_MODE
                    trace_printf("[ERROR] null pointer in %d in line %d ",__FILE__,__LINE__);
                    #endif
                }
                break;
        }
        /* check if the input mode is correct */
        if (locPinConfig->speed < 4)
        {
            locStatus= gpioSpeed(GPIO,locPinConfig->pin,locPinConfig->speed);
            if (locStatus)
            {
                locStatus =enm_Status_NOT_OK;
                #ifdef DEBUG_MODE
                trace_printf("[ERROR] Not ok in %d in line %d ",__FILE__,__LINE__);
                #endif
            }
        }
    }
    return locStatus;

}
ENM_ErrorStatus_t gpioSetPinValue(void * GPIO_PORT,GPIO_PIN_t gpioPin, uint32_t pinState )
{
    ENM_ErrorStatus_t locStatus = enm_Status_NOT_OK ;
    GPIO_REG_t  *GPIO =(GPIO_REG_t *)GPIO_PORT;
    uint32_t locRegister;
    /* Check if the port address is valid */
    if (!GPIO)
    {
        locStatus=enm_Status_NULL_Pointer;
        #ifdef DEBUG_MODE
        trace_printf("[ERROR] null pointer in %d in line %d ",__FILE__,__LINE__);
        #endif
    }
    /* check if the number of bin is valid */
    else if (gpioPin <16)
    {
        if ( PIN_HIGH == pinState )
        {
            /* adding 16 to access set bits */
            gpioPin+= 16;
            /* getting the current value of the BSRR register */
            locRegister =GPIO->BSRR;
            /* Clearing the required bit */
            locRegister &= ~(0x1<<gpioPin);
            /* setting the required bit */
            locRegister |= (0x1<<gpioPin);
            /* assigning the new value to BSRR register */
            GPIO->BSRR=locRegister;
            locStatus = enm_Status_OK;
        }
        else if (PIN_LOW == pinState)
        {
            /* getting the current value of the BSRR register */
            locRegister =GPIO->BSRR;
            /* Clearing the required bit */
            locRegister &= ~(0x1<<gpioPin);
            /* setting the required bit */
            locRegister |= (0x1<<gpioPin);
            /* assigning the new value to BSRR register */
            GPIO->BSRR=locRegister;
            locStatus = enm_Status_OK;
        }
        else
        {
            locStatus =enm_Status_Wrong_Arguments;
            #ifdef DEBUG_MODE
            trace_printf("[ERROR] wrong arguments in %d in line %d ",__FILE__,__LINE__);
            #endif
        }
    }
    return locStatus;
}
ENM_ErrorStatus_t gpioGetPinValue(void * GPIO_PORT,GPIO_PIN_t gpioPin, uint32_t *pinState )
{
    ENM_ErrorStatus_t locStatus = enm_Status_NOT_OK ;
    GPIO_REG_t  *GPIO =(GPIO_REG_t *)GPIO_PORT;
    uint32_t locRegister;
    uint32_t  locValue;

    /* Check if the port address is valid */
    if (!GPIO  || !pinState)
    {
        locStatus=enm_Status_NULL_Pointer;
        #ifdef DEBUG_MODE
        trace_printf("[ERROR] null pointer in %d in line %d ",__FILE__,__LINE__);
        #endif
    }
    /* check if the number of bin is valid */
    else if (gpioPin <16)
    {
        /* getting the current value of the IDR register */
        locRegister =GPIO->IDR;
        /* reading the value of required pin */
        locValue = (locRegister>>gpioPin)& 0x01;
        /* assigning the value to the pointer */
        *pinState =locValue;
        locStatus = enm_Status_OK;
    }
    else
    {
        locStatus =enm_Status_Wrong_Arguments;
        #ifdef DEBUG_MODE
        trace_printf("[ERROR] wrong arguments in %d in line %d ",__FILE__,__LINE__);
        #endif
    }
    return locStatus;
}
ENM_ErrorStatus_t gpioSetPortValue(void * GPIO_PORT, uint32_t *portValue)
{
    ENM_ErrorStatus_t locStatus = enm_Status_NOT_OK ;
    GPIO_REG_t  *GPIO =(GPIO_REG_t *)GPIO_PORT;
    uint32_t locRegister;
    /* Check if the port address is valid */
    if (!GPIO || !portValue)
    {
        locStatus=enm_Status_NULL_Pointer;
        #ifdef DEBUG_MODE
        trace_printf("[ERROR] null pointer in %d in line %d ",__FILE__,__LINE__);
        #endif
    }
    else
    {
            /* getting the current value of the ODR register */
            locRegister =GPIO->ODR;
            /* setting the required bit */
            locRegister = *portValue;
            /* assigning the new value to ODR register */
            GPIO->ODR=locRegister;
            locStatus = enm_Status_OK;
    }
    return locStatus;
}
ENM_ErrorStatus_t gpioGetPortValue(void * GPIO_PORT, uint32_t *portValue)
{
    ENM_ErrorStatus_t locStatus = enm_Status_NOT_OK ;
    GPIO_REG_t  *GPIO =(GPIO_REG_t *)GPIO_PORT;
    uint32_t locRegister;
    uint32_t  locValue;

    /* Check if the port address is valid */
    if (!GPIO  || !portValue)
    {
        locStatus=enm_Status_NULL_Pointer;
        #ifdef DEBUG_MODE
        trace_printf("[ERROR] null pointer in %d in line %d ",__FILE__,__LINE__);
        #endif
    }
        /* check if the number of bin is valid */
    else
    {
        /* getting the current value of the IDR register */
        locRegister =GPIO->IDR;
        /* reading the value of required pin */
        locValue = locRegister;
        /* assigning the value to the pointer */
        *portValue =locValue;
        locStatus = enm_Status_OK;
    }
    return locStatus;
}
ENM_ErrorStatus_t gpioSetAlternateFunction(void * GPIO_PORT,GPIO_PIN_t gpioPin,AlternateFunction_t AlternateFunction)
{
    ENM_ErrorStatus_t locStatus = enm_Status_NOT_OK ;
    GPIO_REG_t  *GPIO =(GPIO_REG_t *)GPIO_PORT;
    uint32_t locRegister;
    /* Check if the port address is valid */
    if (!GPIO)
    {
        locStatus=enm_Status_NULL_Pointer;
        #ifdef DEBUG_MODE
        trace_printf("[ERROR] null pointer in %d in line %d ",__FILE__,__LINE__);
        #endif
    }
    /* check if the number of bin is valid */
    else if (gpioPin <16)
    {
        if (gpioPin <8)
        {
            /* getting the current value of the AFRL register */
            locRegister =GPIO->AFRL;
            /* Clearing the required bit */
            locRegister &= ~(0xF<<gpioPin*4);
            /* setting the required bit */
            locRegister |= (AlternateFunction<<gpioPin*4);
            /* assigning the new value to AFRL register */
            GPIO->AFRL=locRegister;
            locStatus = enm_Status_OK;
        }
        else
        {
            gpioPin -= 8;
            /* getting the current value of the AFRH register */
            locRegister =GPIO->AFRH;
            /* Clearing the required bit */
            locRegister &= ~(0xF<<gpioPin*4);
            /* setting the required bit */
            locRegister |= (AlternateFunction<<gpioPin*4);
            /* assigning the new value to AFRH register */
            GPIO->AFRH=locRegister;
            locStatus = enm_Status_OK;
        }

    }
    else
    {
        locStatus =enm_Status_Wrong_Arguments;
        #ifdef DEBUG_MODE
        trace_printf("[ERROR] wrong arguments in %d in line %d ",__FILE__,__LINE__);
        #endif
    }

    return locStatus;
}
ENM_ErrorStatus_t gpioLockConfiguration(void * GPIO_PORT,GPIO_PIN_t gpioPin)
{
    ENM_ErrorStatus_t locStatus = enm_Status_NOT_OK ;
    GPIO_REG_t  *GPIO =(GPIO_REG_t *)GPIO_PORT;
    uint32_t locRegister;
    /* Check if the port address is valid */
    if (!GPIO)
    {
        locStatus=enm_Status_NULL_Pointer;
        #ifdef DEBUG_MODE
        trace_printf("[ERROR] null pointer in %d in line %d ",__FILE__,__LINE__);
        #endif
    }
        /* check if the number of bin is valid */
    else if (gpioPin <16)
    {
        /* getting the current value of the LCK register */
        locRegister =GPIO->LCK;
        /* Clearing the required bit */
        locRegister &= ~(0x1<<gpioPin);
        /* setting the required bit */
        locRegister |= (0x1<<gpioPin);
        /* assigning the new value to LCK register */
        /* using lock sequence  */
        locRegister |= (0x1<<16);
        /* write 1 on bit[16] */
        GPIO->LCK=locRegister;
        locRegister &= ~(0x1<<16);
        /* write 0 on bit[16] */
        GPIO->LCK=locRegister;
        locRegister |= (0x1<<16);
        /* write 1 on bit[16] */
        GPIO->LCK=locRegister;
        locStatus = enm_Status_OK;
    }
    else
    {
        locStatus =enm_Status_Wrong_Arguments;
        #ifdef DEBUG_MODE
        trace_printf("[ERROR] wrong arguments in %d in line %d ",__FILE__,__LINE__);
        #endif
    }

    return locStatus;
}



static ENM_ErrorStatus_t gpioSetMode(GPIO_REG_t * GPIO_PORT, GPIO_PIN_t gpioPin, uint32_t pinMode)
{
    ENM_ErrorStatus_t locStatus = enm_Status_NOT_OK ;
    uint32_t locRegister;
    /* load the value of mode reg */
    locRegister= GPIO_PORT->MODE;
    /* Clear the required pin  Mode configuration */
    locRegister &= ~(0x3<<(gpioPin*2));
    /* Assign the required pin with Mode configuration */
    locRegister |= (pinMode<<(gpioPin*2));
    GPIO_PORT->MODE = locRegister;
    locStatus = enm_Status_OK;
    return locStatus;
}
static ENM_ErrorStatus_t gpioSetOutputType(GPIO_REG_t * GPIO_PORT, GPIO_PIN_t gpioPin, uint32_t pinOutputType)
{
    ENM_ErrorStatus_t locStatus = enm_Status_NOT_OK ;
    uint32_t locRegister;
    /* load the value of mode reg */
    locRegister= GPIO_PORT->OTYPE;
    /* Clear the required pin  Mode configuration */
    locRegister &= ~(0x1<<gpioPin);
    /* Assign the required pin with Mode configuration */
    locRegister |= (pinOutputType<<gpioPin);
    GPIO_PORT->OTYPE=locRegister;
    locStatus = enm_Status_OK;
    return locStatus;
}
static ENM_ErrorStatus_t gpioSpeed(GPIO_REG_t * GPIO_PORT, GPIO_PIN_t gpioPin, uint32_t pinSpeed)
{
    ENM_ErrorStatus_t locStatus = enm_Status_NOT_OK ;
    uint32_t locRegister;
    /* load the value of mode reg */
    locRegister= GPIO_PORT->OSPEED;
    /* Clear the required pin  Mode configuration */
    locRegister &= ~(0x3<<(gpioPin*2));
    /* Assign the required pin with Mode configuration */
    locRegister |= (pinSpeed<<(gpioPin*2));
    GPIO_PORT->OSPEED=locRegister;
    locStatus = enm_Status_OK;
    return locStatus;
}
static ENM_ErrorStatus_t gpioSetPullState(GPIO_REG_t * GPIO_PORT, GPIO_PIN_t gpioPin, uint32_t pinPullState)
{
    ENM_ErrorStatus_t locStatus = enm_Status_NOT_OK ;
    uint32_t locRegister;
    /* load the value of mode reg */
    locRegister= GPIO_PORT->PUPD;
    /* Clear the required pin  Mode configuration */
    locRegister &= ~(0x3<<(gpioPin*2));
    /* Assign the required pin with Mode configuration */
    locRegister |= (pinPullState<<(gpioPin*2));
    GPIO_PORT->PUPD=locRegister;
    locStatus = enm_Status_OK;
    return locStatus;
}
