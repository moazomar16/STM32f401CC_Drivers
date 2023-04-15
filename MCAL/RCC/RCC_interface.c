/*
 * Author: Moaz Omar
 * Date: Feb 13, 2023
 *
 *
 */



#include "Libraries/Std_Types.h"
#include "Libraries/Bit_Math.h"
#include "RCC_interface.h"

#define RCC_APB_2_CHECK                    0x90000000
#define RCC_APB_1_CHECK                    0x20000000
#define RCC_AHB_2_CHECK                    0x80000000
#define RCC_AHB_1_CHECK                    0x40000000
#define PLL_CFGR_CHECK                     0xA0000000
#define RCC_CR_CHECK                       0x80000000
#define RCC_CFGR_CHECK                     0x00000300
#define SYSTEM_CLOCK_CLEAR				   0xFFFFFFFC
#define PLLP_CLEAR                         0xFFFCFFFF
#define PLLM_CLEAR                         0xFFFFFFC0
#define PLLN_CLEAR                         0xFFFF803F
#define PLLSRC_CLEAR                       0xFFBFFFFF
#define PLLQ_CLEAR                         0xF0FFFFFF
#define CLOCK_SECURITY_SYSTEM_CLEAR        0xFFF7FFFF
#define CLOCK_OUTPUT_MOC_2_CLEAR           0x3FFFFFFF
#define CLOCK_OUTPUT_MOC_1_CLEAR           0xFF9FFFFF
#define MOC_2_DIV_CLEAR                    0xC7FFFFFF
#define MOC_1_DIV_CLEAR                    0xF8FFFFFF
#define RTC_DIV_CLEAR                      0xFFE0FFFF
#define BUS_APB_1_DIV_CLEAR                0xFFFFE3FF
#define BUS_APB_2_DIV_CLEAR                0xFFFF1FFF
#define SYSCLK_DIV_CLEAR                   0xFFFFFF0F
#define SYSTEM_CLOCK_HSI_CHECK             0x000000000
#define SYSTEM_CLOCK_HSE_CHECK             0x000000004
#define SYSTEM_CLOCK_PLL_CHECK             0x000000008
#define TIME_OUT                           10000

static ENM_ERROR_STATUS_t  rcc_EnableHSE(uint32_t Clock);/* tested XD*/
static ENM_ERROR_STATUS_t  rcc_EnableHSI(uint32_t Clock); /* tested XD*/
static ENM_ERROR_STATUS_t  rcc_EnableHSEByPASS(uint32_t Clock);
static ENM_ERROR_STATUS_t  rcc_EnablePLL(uint32_t Clock);/* tested XD*/
static ENM_ERROR_STATUS_t  rcc_EnablePLLI2C(uint32_t Clock);
static ENM_ERROR_STATUS_t  rcc_DisableHSE(uint32_t Clock);/* tested XD*/
static ENM_ERROR_STATUS_t  rcc_DisableHSI(uint32_t Clock); /* tested XD*/
static ENM_ERROR_STATUS_t  rcc_DisableHSEByPASS(uint32_t Clock);
static ENM_ERROR_STATUS_t  rcc_DisablePLL(uint32_t Clock);/* tested XD*/
static ENM_ERROR_STATUS_t  rcc_DisablePLLI2C(uint32_t Clock);

/*Ptr_to_RCC RCC;*/

ENM_ERROR_STATUS_t rcc_EnableClock(uint32_t Clock)
{
    uint32_t loc_clock;
    uint8_t loc_status  = enmRCC_Status_NOT_OK;

    loc_clock=Clock;
    if(!(loc_clock & RCC_CR_CHECK))
    {
        loc_status=enmRCC_Status_Wrong_Arguments;
    }
    else
    {
        if(loc_clock == CLOCK_HSI)
        {
            loc_status= (uint8_t)rcc_EnableHSI(loc_clock & (~RCC_CR_CHECK));
            if (loc_status != enmRCC_Status_OK)
            {
                loc_status=(uint8_t)enmRCC_Status_NOT_OK;
            }
        }
        else if (loc_clock == CLOCK_HSE)
        {
            loc_status= (uint8_t)rcc_EnableHSE(loc_clock & (~RCC_CR_CHECK));
            if (loc_status != enmRCC_Status_OK)
            {
                loc_status=(uint8_t)enmRCC_Status_NOT_OK;
            }
        }
        else if (loc_clock == CLOCK_HSE_BYPASS)
        {
            loc_status= (uint8_t)rcc_EnableHSEByPASS(loc_clock & (~RCC_CR_CHECK));
            if (loc_status != enmRCC_Status_OK)
            {
                loc_status=(uint8_t)enmRCC_Status_NOT_OK;
            }
        }
        else if (loc_clock == CLOCK_PLL)
        {
            loc_status= (uint8_t) rcc_EnablePLL(loc_clock & (~RCC_CR_CHECK));
            if (loc_status != enmRCC_Status_OK)
            {
                loc_status=(uint8_t)enmRCC_Status_NOT_OK;
            }
        }
        else if (loc_clock == CLOCK_PLLI2S)
        {
            loc_status= (uint8_t) rcc_EnablePLLI2C(loc_clock & (~RCC_CR_CHECK));
            if (loc_status != enmRCC_Status_OK)
            {
                loc_status=(uint8_t)enmRCC_Status_NOT_OK;
            }
        }
        else
        {
            loc_status=enmRCC_Status_MORE_THAN_ONE_OPTION;
        }
    }
    return loc_status;
} /*tested */
ENM_ERROR_STATUS_t rcc_DisableClock(uint32_t Clock)
{

    uint32_t loc_clock;
    uint8_t loc_status=enmRCC_Status_NOT_OK;

    loc_clock=Clock;
    if(!(loc_clock & RCC_CR_CHECK))
    {
        loc_status=enmRCC_Status_Wrong_Arguments;
    }
    else
    {
        if(loc_clock == CLOCK_HSI)
        {
            loc_status= (uint8_t) rcc_DisableHSI(loc_clock & (~RCC_CR_CHECK));
            if (loc_status != enmRCC_Status_OK)
            {
                loc_status=(uint8_t)enmRCC_Status_NOT_OK;
            }
        }
        else if (loc_clock == CLOCK_HSE)
        {
            loc_status= (uint8_t) rcc_DisableHSE(loc_clock & (~RCC_CR_CHECK));
            if (loc_status != enmRCC_Status_OK)
            {
                loc_status=(uint8_t)enmRCC_Status_NOT_OK;
            }
        }
        else if (loc_clock == CLOCK_HSE_BYPASS)
        {
            loc_status= (uint8_t) rcc_DisableHSEByPASS(loc_clock & (~RCC_CR_CHECK));
            if (loc_status != enmRCC_Status_OK)
            {
                loc_status=(uint8_t)enmRCC_Status_NOT_OK;
            }
        }
        else if (loc_clock == CLOCK_PLL)
        {
            loc_status= (uint8_t) rcc_DisablePLL(loc_clock & (~RCC_CR_CHECK));
            if (loc_status != enmRCC_Status_OK)
            {
                loc_status=(uint8_t)enmRCC_Status_NOT_OK;
            }
        }
        else if (loc_clock == CLOCK_PLLI2S)
        {
            loc_status= (uint8_t) rcc_DisablePLLI2C(loc_clock & (~RCC_CR_CHECK));
            if (loc_status != enmRCC_Status_OK)
            {
                loc_status=(uint8_t)enmRCC_Status_NOT_OK;
            }
        }
        else
        {
            loc_status=enmRCC_Status_MORE_THAN_ONE_OPTION;
        }
    }
    return loc_status;
} /* tested */
ENM_ERROR_STATUS_t rcc_ChangeSystemClock(uint32_t SystemClock)
{
    uint32_t loc_systemClock;
    uint8_t loc_status;
    uint32_t loc_register;
    uint32_t loc_timeout;
    /* initial local variable */
    loc_systemClock=SystemClock;
    loc_timeout=0;
    loc_status=enmRCC_Status_NOT_OK;
    if(!(loc_systemClock & RCC_CFGR_CHECK))
    {
        loc_status=enmRCC_Status_Wrong_Arguments;
    }
    else {
        /* get the current value of the CR register*/
        loc_register = RCC->CFGR;
        /* clear the clock pins*/
        loc_register &= SYSTEM_CLOCK_CLEAR;
        /* add the new param to the local variable*/
        loc_register |= (loc_systemClock & (~RCC_CFGR_CHECK));
        /* assign the register with the new value */
        RCC->CFGR = loc_register;
        /* wait for the systemClock to be ready or time out*/
        /*SHIFT_LEFT(loc_register,2);*/
        while (loc_timeout++ < TIME_OUT && !((( RCC->CFGR )& 0x0F)>>2== (loc_register&0x3)) );
        /* check if the loop finished because of time out*/
        if (loc_timeout == TIME_OUT)
        {
            loc_status = enmRCC_Status_TIME_OUT;
        }
            /* check if the systemClock is ready or not */
        else if ((( RCC->CFGR )& 0x0F)>>2== (loc_register&0x3))
        {
            loc_status = enmRCC_Status_OK;
        }
        else {
            loc_status = enmRCC_Status_NOT_Ready;
        }
    }
    /* return the local status*/
    return loc_status;
} /* tested */

ENM_ERROR_STATUS_t rcc_AHP1BusPeripheralControl(ENM_PeripheralControl_t StatePeripheral ,uint32_t Peripheral)
{
    uint32_t loc_peripheral;
    uint8_t loc_status;
    uint32_t loc_register;
    /* initial local variable */
    loc_peripheral= Peripheral;
    loc_status=enmRCC_Status_NOT_OK;
    if((!(loc_peripheral & RCC_AHB_1_CHECK)))
    {
        loc_status=enmRCC_Status_Wrong_Arguments;
    }
    else {
        /* check if the state is enabled or disabled*/
        if (StatePeripheral == ENABLE_PERIPHERAL) {
            /* get the current value of the CR register*/
            loc_register = RCC->AHB1ENR;
            /* add the new param to the local variable*/
            loc_register |= (loc_peripheral & (~RCC_AHB_1_CHECK));
            /* assign the register with the new value */
            RCC->AHB1ENR = loc_register;
            /* wait for the systemClock to be ready or time out*/
            loc_status = enmRCC_Status_OK;
        }
        else if (StatePeripheral == DISABLE_PERIPHERAL)
        {
            /* get the current value of the CR register*/
            loc_register = RCC->AHB1ENR;
            /* add the new param to the local variable*/
            loc_register &= ~(loc_peripheral & (~RCC_AHB_1_CHECK));
            /* assign the register with the new value */
            RCC->AHB1ENR = loc_register;
            /* wait for the systemClock to be ready or time out*/
            loc_status=enmRCC_Status_OK;
        }
        else
        {
            loc_status= enmRCC_Status_Wrong_Arguments;
        }
    }
    /* return the local status*/
    return loc_status;
}/* tested */
ENM_ERROR_STATUS_t rcc_AHP2BusPeripheralControl(ENM_PeripheralControl_t StatePeripheral ,uint32_t Peripheral)
{
    uint32_t loc_peripheral;
    uint8_t loc_status;
    uint32_t loc_register;
    /* initial local variable */
    loc_peripheral= Peripheral;
    loc_status=enmRCC_Status_NOT_OK;
    if(!(loc_peripheral & RCC_AHB_2_CHECK))
    {
        loc_status=enmRCC_Status_Wrong_Arguments;
    }
    else {
        if(StatePeripheral == ENABLE_PERIPHERAL)
        {
            /* get the current value of the CR register*/
            loc_register = RCC->AHB2ENR;
            /* add the new param to the local variable*/
            loc_register |= (loc_peripheral & (~RCC_AHB_2_CHECK));
            /* assign the register with the new value */
            RCC->AHB2ENR = loc_register;
            /* wait for the systemClock to be ready or time out*/
            loc_status = enmRCC_Status_OK;
        }
        else if (StatePeripheral == DISABLE_PERIPHERAL)
        {
            /* get the current value of the CR register*/
            loc_register = RCC->AHB2ENR;
            /* add the new param to the local variable*/
            loc_register &= ~(loc_peripheral & (~RCC_AHB_2_CHECK));
            /* assign the register with the new value */
            RCC->AHB2ENR = loc_register;
            /* wait for the systemClock to be ready or time out*/
            loc_status=enmRCC_Status_OK;
        }
        else
        {
            loc_status = enmRCC_Status_Wrong_Arguments;
        }
    }
    /* return the local status*/
    return loc_status;
}/* tested */
ENM_ERROR_STATUS_t rcc_APB1BusPeripheralControl(ENM_PeripheralControl_t StatePeripheral ,uint32_t Peripheral)
{
    uint32_t loc_peripheral;
    uint8_t loc_status;
    uint32_t loc_register;
    /* initial local variable */
    loc_peripheral= Peripheral;
    loc_status=enmRCC_Status_NOT_OK;
    if(!(loc_peripheral & RCC_APB_1_CHECK))
    {
        loc_status=enmRCC_Status_Wrong_Arguments;
    }
    else {
        if (StatePeripheral == ENABLE_PERIPHERAL)
        {
            /* get the current value of the CR register*/
            loc_register = RCC->APB1ENR;
            /* add the new param to the local variable*/
            loc_register |= (loc_peripheral & (~RCC_APB_1_CHECK));
            /* assign the register with the new value */
            RCC->APB1ENR = loc_register;
            /* wait for the systemClock to be ready or time out*/
            loc_status = enmRCC_Status_OK;
        }
        else if (StatePeripheral == DISABLE_PERIPHERAL)
        {
            /* get the current value of the CR register*/
            loc_register = RCC->APB1ENR;
            /* add the new param to the local variable*/
            loc_register &= ~ (loc_peripheral & (~RCC_APB_1_CHECK));
            /* assign the register with the new value */
            RCC->APB1ENR = loc_register;
            /* wait for the systemClock to be ready or time out*/
            loc_status=enmRCC_Status_OK;
        }
        else
        {
            loc_status = enmRCC_Status_Wrong_Arguments;
        }
    }
    /* return the local status*/
    return loc_status;
}/* tested */
ENM_ERROR_STATUS_t rcc_APB2BusPeripheralControl(ENM_PeripheralControl_t StatePeripheral ,uint32_t Peripheral)
{
    uint32_t loc_peripheral;
    uint8_t loc_status;
    uint32_t loc_register;
    /* initial local variable */
    loc_peripheral= Peripheral;
    loc_status=enmRCC_Status_NOT_OK;
    if(!(loc_peripheral & RCC_APB_2_CHECK))
    {
        loc_status=enmRCC_Status_Wrong_Arguments;
    }
    else {
        if (StatePeripheral == ENABLE_PERIPHERAL)
        {
            /* get the current value of the CR register*/
            loc_register = RCC->APB2ENR;
            /* add the new param to the local variable*/
            loc_register |= (loc_peripheral & (~RCC_APB_2_CHECK));
            /* assign the register with the new value */
            RCC->APB2ENR = loc_register;
            /* wait for the systemClock to be ready or time out*/
            loc_status = enmRCC_Status_OK;
        }
        else if (StatePeripheral == DISABLE_PERIPHERAL)
        {
            /* get the current value of the CR register*/
            loc_register = RCC->APB2ENR;
            /* add the new param to the local variable*/
            loc_register &= ~ (loc_peripheral & (~RCC_APB_2_CHECK));
            /* assign the register with the new value */
            RCC->APB2ENR = loc_register;
            /* wait for the systemClock to be ready or time out*/
            loc_status=enmRCC_Status_OK;
        }
        else
        {
            loc_status = enmRCC_Status_Wrong_Arguments;
        }
    }
    /* return the local status*/
    return loc_status;
}/* tested */

ENM_ERROR_STATUS_t rcc_EnableClockSecurity(uint32_t State)
{
    uint32_t loc_register;
    uint32_t loc_state;
    uint8_t loc_status=enmRCC_Status_NOT_OK;

    loc_state=State;
    if(!(loc_state & RCC_CR_CHECK))
    {
        loc_status=enmRCC_Status_Wrong_Arguments;
    }
    else
    {
        /* get the current value of the CR register*/
        loc_register= RCC->CR;
        /* add the new param to the local variable*/
        loc_register |= loc_state;
        /* assign the register with the new value */
        RCC->CR=loc_register;
        loc_status=enmRCC_Status_OK;
    }
    return loc_status;
}
ENM_ERROR_STATUS_t rcc_PLLConfiguration(uint32_t PLL_Configuration )
{
    uint32_t loc_configuration;
    uint8_t loc_status;
    uint32_t loc_register;
    /* initial local variable */
    loc_configuration= PLL_Configuration;
    loc_status=enmRCC_Status_NOT_OK;
    if(!(loc_configuration & PLL_CFGR_CHECK))
    {
        loc_status=enmRCC_Status_Wrong_Arguments;
    }
    else {
        /* get the current value of the CR register*/
        loc_register = RCC->PLLCFGR;

        /* clear the register */
        loc_register &= 0x00000000;
        /* add the new param to the local variable*/
        loc_register |= (loc_configuration & (~PLL_CFGR_CHECK));
        /* assign the register with the new value */
        RCC->PLLCFGR = loc_register;
        /* wait for the systemClock to be ready or time out*/
        loc_status=enmRCC_Status_OK;
    }
    /* return the local status*/
    return loc_status;
}

ENM_ERROR_STATUS_t rcc_ClockOutputControl(ENM_CLOCK_OUTPUT_t ClockOutNumber ,uint32_t Clock, uint32_t DivFactor)
{
    uint32_t loc_clock;
    uint32_t loc_div_factor;
    uint8_t loc_status;
    uint32_t loc_register;
    /* initial local variable */
    loc_clock= Clock;
    loc_div_factor= DivFactor;
    loc_status=enmRCC_Status_NOT_OK;
    if((!(loc_clock & RCC_CFGR_CHECK)) && (!(loc_div_factor & RCC_CFGR_CHECK)))
    {
        loc_status=enmRCC_Status_Wrong_Arguments;
    }
    else {
        if (ClockOutNumber == CLOCK_OUTPUT_MOC_1)
        {
            /* get the current value of the CR register*/
            loc_register = RCC->CFGR;
            /* clear the register */
            loc_register &= CLOCK_OUTPUT_MOC_1_CLEAR;
            /* add the new param to the local variable*/
            loc_register |= (loc_clock & (~RCC_CFGR_CHECK));
            /* assign the register with the new value */
            RCC->CFGR = loc_register;
            /* wait for the systemClock to be ready or time out*/
            loc_status = enmRCC_Status_OK;

            /* ------- Configuring Prescaler -------*/
            /* get the current value of the CR register*/
            loc_register = RCC->CFGR;
            /* clear the register */
            loc_register &= MOC_1_DIV_CLEAR;
            /* add the new param to the local variable*/
            loc_register |= (loc_div_factor & (~RCC_CFGR_CHECK));
            /* assign the register with the new value */
            RCC->CFGR = loc_register;
            /* wait for the systemClock to be ready or time out*/
            loc_status=enmRCC_Status_OK;
        }
        else if (ClockOutNumber == CLOCK_OUTPUT_MOC_2)
        {
            /* get the current value of the CR register*/
            loc_register = RCC->CFGR;
            /* clear the register */
            loc_register &= CLOCK_OUTPUT_MOC_2_CLEAR;
            /* add the new param to the local variable*/
            loc_register |= (loc_clock & (~RCC_CFGR_CHECK));
            /* assign the register with the new value */
            RCC->CFGR = loc_register;
            /* wait for the systemClock to be ready or time out*/
            loc_status=enmRCC_Status_OK;

            /* ------- Configuring Prescaler -------*/
            /* get the current value of the CR register*/
            loc_register = RCC->CFGR;
            /* clear the register */
            loc_register &= MOC_2_DIV_CLEAR;
            /* add the new param to the local variable*/
            loc_register |= (loc_div_factor & (~RCC_CFGR_CHECK));
            /* assign the register with the new value */
            RCC->CFGR = loc_register;
            /* wait for the systemClock to be ready or time out*/
            loc_status=enmRCC_Status_OK;
        }
        else
        {
            loc_status= enmRCC_Status_Wrong_Arguments;
        }
    }
    /* return the local status*/
    return loc_status;
}/* tested XD*/

ENM_ERROR_STATUS_t rcc_APB1BusPrescaler(uint32_t DivFactor)
{
    uint32_t loc_div_factor;
    uint8_t loc_status;
    uint32_t loc_register;
    /* initial local variable */
    loc_div_factor= DivFactor;
    loc_status = enmRCC_Status_NOT_OK;
    if(!(loc_div_factor & RCC_CFGR_CHECK))
    {
        loc_status=enmRCC_Status_Wrong_Arguments;
    }
    else {
        /* get the current value of the CR register*/
        loc_register = RCC->CFGR;
        /* clear the register */
        loc_register &= BUS_APB_1_DIV_CLEAR;
        /* add the new param to the local variable*/
        loc_register |= (loc_div_factor & (~RCC_CFGR_CHECK));
        /* assign the register with the new value */
        RCC->CFGR = loc_register;
        /* wait for the systemClock to be ready or time out*/
        loc_status=enmRCC_Status_OK;
    }
    /* return the local status*/
    return loc_status;
}/* tested XD*/
ENM_ERROR_STATUS_t rcc_APB2BusPrescaler(uint32_t DivFactor)
{
    uint32_t loc_div_factor;
    uint8_t loc_status;
    uint32_t loc_register;
    /* initial local variable */
    loc_div_factor= DivFactor;
    loc_status = enmRCC_Status_NOT_OK;
    if(!(loc_div_factor & RCC_CFGR_CHECK))
    {
        loc_status=enmRCC_Status_Wrong_Arguments;
    }
    else {
        /* get the current value of the CR register*/
        loc_register = RCC->CFGR;
        /* clear the register */
        loc_register &= BUS_APB_2_DIV_CLEAR;
        /* add the new param to the local variable*/
        loc_register |= (loc_div_factor & (~RCC_CFGR_CHECK));
        /* assign the register with the new value */
        RCC->CFGR = loc_register;
        /* wait for the systemClock to be ready or time out*/
        loc_status=enmRCC_Status_OK;
    }
    /* return the local status*/
    return loc_status;
}/* tested XD*/
ENM_ERROR_STATUS_t rcc_SystemClockPrescaler(uint32_t DivFactor)
{
    uint32_t loc_div_factor;
    uint8_t loc_status;
    uint32_t loc_register;
    /* initial local variable */
    loc_div_factor= DivFactor;
    loc_status = enmRCC_Status_NOT_OK;
    if(!(loc_div_factor & RCC_CFGR_CHECK))
    {
        loc_status=enmRCC_Status_Wrong_Arguments;
    }
    else {
        /* get the current value of the CR register*/
        loc_register = RCC->CFGR;
        /* clear the register */
        loc_register &= SYSCLK_DIV_CLEAR;
        /* add the new param to the local variable*/
        loc_register |= (loc_div_factor & (~RCC_CFGR_CHECK));
        /* assign the register with the new value */
        RCC->CFGR = loc_register;
        /* wait for the systemClock to be ready or time out*/
        loc_status=enmRCC_Status_OK;
    }
    /* return the local status*/
    return loc_status;
}

/**********************************************************
 *
 * Description: this a static function used to enable HSE clock
 * @param Clock
 * @return loc_status
 *********************************************************/
static ENM_ERROR_STATUS_t rcc_EnableHSE(uint32_t Clock)
{
    uint32_t loc_clock;
    uint8_t loc_status;
    uint32_t loc_register;
    uint32_t loc_timeout;
    /* initial local variable */
    loc_clock=Clock;
    loc_timeout=0;
    loc_status=enmRCC_Status_NOT_OK;
    /* get the current value of the CR register*/
    loc_register= RCC->CR;
    /* add the new param to the local variable*/
    loc_register |= loc_clock;
    /* assign the register with the new value */
    RCC->CR=loc_register;
    /* wait for the clock to be ready or time out*/
    while( loc_timeout++< TIME_OUT && !GET_BIT(RCC->CR,17) );
    /* check if the loop finished because of time out*/
    if(loc_timeout == TIME_OUT)
    {
        loc_status=enmRCC_Status_TIME_OUT;
    }
        /* check if the clock is ready or not */
    else if (GET_BIT(RCC->CR,17) == 1)
    {
        loc_status=enmRCC_Status_OK;
    }
    else
    {
        loc_status=enmRCC_Status_NOT_Ready;
    }
    /* return the local status*/
    return loc_status;
}

/**********************************************************
 *
 * Description: this a static function used to enable HSI clock
 * @param Clock
 * @return loc_status
 **********************************************************/
static ENM_ERROR_STATUS_t rcc_EnableHSI(uint32_t Clock)
{
    uint32_t loc_clock;
    uint8_t loc_status;
    uint32_t loc_register;
    uint32_t loc_timeout;
    /* initial local variable */
    loc_clock=Clock;
    loc_timeout=0;
    loc_status=enmRCC_Status_NOT_OK;
    /* get the current value of the CR register*/
    loc_register= RCC->CR;
    /* add the new param to the local variable*/
    loc_register |= loc_clock;
    /* assign the register with the new value */
    RCC->CR=loc_register;
    /* wait for the clock to be ready or time out*/
    while( loc_timeout++< TIME_OUT && !GET_BIT(RCC->CR,1) );
    /* check if the loop finished because of time out*/
    if(loc_timeout == TIME_OUT)
    {
        loc_status=enmRCC_Status_TIME_OUT;
    }
        /* check if the clock is ready or not */
    else if (GET_BIT(RCC->CR,1) == 1)
    {
        loc_status=enmRCC_Status_OK;
    }
    else
    {
        loc_status=enmRCC_Status_NOT_Ready;
    }
    /* return the local status*/
    return loc_status;
}

/**********************************************************
 *
 * Description: this a static function used to enable HSE BY PASS clock
 * @param Clock
 * @return loc_status
 **********************************************************/
static ENM_ERROR_STATUS_t rcc_EnableHSEByPASS(uint32_t Clock)
{
    uint32_t loc_clock;
    uint8_t loc_status;
    uint32_t loc_register;
    uint32_t loc_timeout;
    /* initial local variable */
    loc_clock=Clock;
    loc_timeout=0;
    loc_status=enmRCC_Status_NOT_OK;
    /* get the current value of the CR register*/
    loc_register= RCC->CR;
    /* add the new param to the local variable*/
    loc_register |= loc_clock;
    /* assign the register with the new value */
    RCC->CR=loc_register;
    /* wait for the clock to be ready or time out*/
    while( loc_timeout++< TIME_OUT && !GET_BIT(RCC->CR,17) );
    /* check if the loop finished because of time out*/
    if(loc_timeout == TIME_OUT)
    {
        loc_status=enmRCC_Status_TIME_OUT;
    }
        /* check if the clock is ready or not */
    else if (GET_BIT(RCC->CR,17) == 1)
    {
        loc_status=enmRCC_Status_OK;
    }
    else
    {
        loc_status=enmRCC_Status_NOT_Ready;
    }
    /* return the local status*/
    return loc_status;
}

/**********************************************************
 *
 * Description: this a static function used to enable PLL clock
 * @param Clock
 * @return loc_status
 **********************************************************/
static  ENM_ERROR_STATUS_t rcc_EnablePLL(uint32_t Clock)
{
    uint32_t loc_clock;
    uint8_t loc_status;
    uint32_t loc_register;
    uint32_t loc_timeout;
    /* initial local variable */
    loc_clock=Clock;
    loc_timeout=0;
    loc_status=enmRCC_Status_NOT_OK;
    /* get the current value of the CR register*/
    loc_register= RCC->CR;
    /* add the new param to the local variable*/
    loc_register |= loc_clock;
    /* assign the register with the new value */
    RCC->CR=loc_register;
    /* wait for the clock to be ready or time out*/
    while( loc_timeout++< TIME_OUT && !GET_BIT(RCC->CR,25) );
    /* check if the loop finished because of time out*/
    if(loc_timeout == TIME_OUT)
    {
        loc_status=enmRCC_Status_TIME_OUT;
    }
        /* check if the clock is ready or not */
    else if (GET_BIT(RCC->CR,25) == 1)
    {
        loc_status=enmRCC_Status_OK;
    }
    else
    {
        loc_status=enmRCC_Status_NOT_Ready;
    }
    /* return the local status*/
    return loc_status;
}

/**********************************************************
 *
 * Description: this a static function used to enable PLLI2C clock
 * @param Clock
 * @return loc_status
 **********************************************************/
static  ENM_ERROR_STATUS_t rcc_EnablePLLI2C(uint32_t Clock)
{
    uint32_t loc_clock;
    uint8_t loc_status;
    uint32_t loc_register;
    uint32_t loc_timeout;
    /* initial local variable */
    loc_clock=Clock;
    loc_timeout=0;
    loc_status=enmRCC_Status_NOT_OK;
    /* get the current value of the CR register*/
    loc_register= RCC->CR;
    /* add the new param to the local variable*/
    loc_register |= loc_clock;
    /* assign the register with the new value */
    RCC->CR=loc_register;
    /* wait for the clock to be ready or time out*/
    while( loc_timeout++< TIME_OUT && !GET_BIT(RCC->CR,27) );
    /* check if the loop finished because of time out*/
    if(loc_timeout == TIME_OUT)
    {
        loc_status=enmRCC_Status_TIME_OUT;
    }
        /* check if the clock is ready or not */
    else if (GET_BIT(RCC->CR,27) == 1)
    {
        loc_status=enmRCC_Status_OK;
    }
    else
    {
        loc_status=enmRCC_Status_NOT_Ready;
    }
    /* return the local status*/
    return loc_status;
}

/**********************************************************
 *
 * Description: this a static function used to enable HSE clock
 * @param Clock
 * @return loc_status
 *********************************************************/
static ENM_ERROR_STATUS_t rcc_DisableHSE(uint32_t Clock)
{
    uint32_t loc_clock;
    uint8_t loc_status;
    uint32_t loc_register;
    uint32_t loc_timeout;
    /* initial local variable */
    loc_clock=Clock;
    loc_timeout=0;
    loc_status=enmRCC_Status_NOT_OK;
    /* get the current value of the CR register*/
    loc_register= RCC->CR;
    /* add the new param to the local variable*/
    loc_register &= ~loc_clock;
    /* assign the register with the new value */
    RCC->CR=loc_register;
    /* wait for the clock to be ready or time out*/
    while( loc_timeout++< TIME_OUT && GET_BIT(RCC->CR,17) );
    /* check if the loop finished because of time out*/
    if(loc_timeout == TIME_OUT)
    {
        loc_status=enmRCC_Status_TIME_OUT;
    }
        /* check if the clock is ready or not */
    else if (GET_BIT(RCC->CR,17) == 0)
    {
        loc_status=enmRCC_Status_OK;
    }
    else
    {
        loc_status=enmRCC_Status_NOT_OK;
    }
    /* return the local status*/
    return loc_status;
}

/**********************************************************
 *
 * Description: this a static function used to Disable HSI clock
 * @param Clock
 * @return loc_status
 **********************************************************/
static ENM_ERROR_STATUS_t rcc_DisableHSI(uint32_t Clock)
{
    uint32_t loc_clock;
    uint8_t loc_status;
    uint32_t loc_register;
    uint32_t loc_timeout;
    /* initial local variable */
    loc_clock=Clock;
    loc_timeout=0;
    loc_status=enmRCC_Status_NOT_OK;
    /* get the current value of the CR register*/
    loc_register= RCC->CR;
    /* add the new param to the local variable*/
    loc_register &= ~loc_clock;
    /* assign the register with the new value */
    RCC->CR=loc_register;
    /* wait for the clock to be ready or time out*/
    while( loc_timeout++< TIME_OUT && GET_BIT(RCC->CR,1) );
    /* check if the loop finished because of time out*/
    if(loc_timeout == TIME_OUT)
    {
        loc_status=enmRCC_Status_TIME_OUT;
    }
        /* check if the clock is ready or not */
    else if (GET_BIT(RCC->CR,1) == 0)
    {
        loc_status=enmRCC_Status_OK;
    }
    else
    {
        loc_status=enmRCC_Status_NOT_OK;
    }
    /* return the local status*/
    return loc_status;
}

/**********************************************************
 *
 * Description: this a static function used to Disable HSE BY PASS clock
 * @param Clock
 * @return loc_status
 **********************************************************/
static ENM_ERROR_STATUS_t rcc_DisableHSEByPASS(uint32_t Clock)
{
    uint32_t loc_clock;
    uint8_t loc_status;
    uint32_t loc_register;
    uint32_t loc_timeout;
    /* initial local variable */
    loc_clock=Clock;
    loc_timeout=0;
    loc_status=enmRCC_Status_NOT_OK;
    /* get the current value of the CR register*/
    loc_register= RCC->CR;
    /* add the new param to the local variable*/
    loc_register &= ~loc_clock;
    /* assign the register with the new value */
    RCC->CR=loc_register;
    /* wait for the clock to be ready or time out*/
    while( loc_timeout++< TIME_OUT && GET_BIT(RCC->CR,17) );
    /* check if the loop finished because of time out*/
    if(loc_timeout == TIME_OUT)
    {
        loc_status=enmRCC_Status_TIME_OUT;
    }
        /* check if the clock is ready or not */
    else if (GET_BIT(RCC->CR,17) == 0)
    {
        loc_status=enmRCC_Status_OK;
    }
    else
    {
        loc_status=enmRCC_Status_NOT_OK;
    }
    /* return the local status*/
    return loc_status;
}

/**********************************************************
 *
 * Description: this a static function used to Disable PLL clock
 * @param Clock
 * @return loc_status
 **********************************************************/
static  ENM_ERROR_STATUS_t rcc_DisablePLL(uint32_t Clock)
{
    uint32_t loc_clock;
    uint8_t loc_status;
    uint32_t loc_register;
    uint32_t loc_timeout;
    /* initial local variable */
    loc_clock=Clock;
    loc_timeout=0;
    loc_status=enmRCC_Status_NOT_OK;
    /* get the current value of the CR register*/
    loc_register= RCC->CR;
    /* add the new param to the local variable*/
    loc_register &= ~loc_clock;
    /* assign the register with the new value */
    RCC->CR=loc_register;
    /* wait for the clock to be ready or time out*/
    while( loc_timeout++< TIME_OUT && GET_BIT(RCC->CR,25) );
    /* check if the loop finished because of time out*/
    if(loc_timeout == TIME_OUT)
    {
        loc_status=enmRCC_Status_TIME_OUT;
    }
        /* check if the clock is ready or not */
    else if (GET_BIT(RCC->CR,25) == 0)
    {
        loc_status=enmRCC_Status_OK;
    }
    else
    {
        loc_status=enmRCC_Status_NOT_OK;
    }
    /* return the local status*/
    return loc_status;
}

/**********************************************************
 *
 * Description: this a static function used to Disable PLLI2C clock
 * @param Clock
 * @return loc_status
 **********************************************************/
static  ENM_ERROR_STATUS_t rcc_DisablePLLI2C(uint32_t Clock)
{
    uint32_t loc_clock;
    uint8_t loc_status;
    uint32_t loc_register;
    uint32_t loc_timeout;
    /* initial local variable */
    loc_clock=Clock;
    loc_timeout=0;
    loc_status=enmRCC_Status_NOT_OK;
    /* get the current value of the CR register*/
    loc_register= RCC->CR;
    /* add the new param to the local variable*/
    loc_register &= ~loc_clock;
    /* assign the register with the new value */
    RCC->CR=loc_register;
    /* wait for the clock to be ready or time out*/
    while( loc_timeout++< TIME_OUT && GET_BIT(RCC->CR,27) );
    /* check if the loop finished because of time out*/
    if(loc_timeout == TIME_OUT)
    {
        loc_status=enmRCC_Status_TIME_OUT;
    }
        /* check if the clock is ready or not */
    else if (GET_BIT(RCC->CR,27) == 0)
    {
        loc_status=enmRCC_Status_OK;
    }
    else
    {
        loc_status=enmRCC_Status_NOT_OK;
    }
    /* return the local status*/
    return loc_status;
}
