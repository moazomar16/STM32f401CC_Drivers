/*
 * NVIC.c
 *
 *  Created on: Mar 10, 2023
 *      @Author: Moaz Omar
 */


#include "Libraries/Std_Types.h"
#include "Libraries/Bit_Math.h"
#include "NVIC_interface.h"

/*
#define NVIC_ISER_0            *((vuint32_t *) 0xE000E100)
#define NVIC_ISER_1            *((vuint32_t *) 0xE000E104)
#define NVIC_ISER_2            *((vuint32_t *) 0xE000E108)

#define NVIC_ICER_0            *((vuint32_t *) 0xE000E180)
#define NVIC_ICER_1            *((vuint32_t *) 0xE000E184)
#define NVIC_ICER_2            *((vuint32_t *) 0xE000E188)

#define NVIC_ISPR_0            *((vuint32_t *) 0xE000E200)
#define NVIC_ISPR_1            *((vuint32_t *) 0xE000E204)
#define NVIC_ISPR_2            *((vuint32_t *) 0xE000E208)

#define NVIC_ICPR_0            *((vuint32_t *) 0xE000E280)
#define NVIC_ICPR_1            *((vuint32_t *) 0xE000E284)
#define NVIC_ICPR_2            *((vuint32_t *) 0xE000E288)

#define NVIC_IABR_0            *((vuint32_t *) 0xE000E300)
#define NVIC_IABR_1            *((vuint32_t *) 0xE000E304)
#define NVIC_IABR_2            *((vuint32_t *) 0xE000E308)

#define NVIC_IPR_0             *((vuint32_t *) 0xE000E400)
#define NVIC_IPR_1             *((vuint32_t *) 0xE000E404)
#define NVIC_IPR_2             *((vuint32_t *) 0xE000E408)
#define NVIC_IPR_3             *((vuint32_t *) 0xE000E40C)
#define NVIC_IPR_4             *((vuint32_t *) 0xE000E410)
#define NVIC_IPR_5             *((vuint32_t *) 0xE000E414)
#define NVIC_IPR_6             *((vuint32_t *) 0xE000E418)
#define NVIC_IPR_7             *((vuint32_t *) 0xE000E41C)
#define NVIC_IPR_8             *((vuint32_t *) 0xE000E420)
#define NVIC_IPR_9             *((vuint32_t *) 0xE000E424)
#define NVIC_IPR_10            *((vuint32_t *) 0xE000E428)
#define NVIC_IPR_11            *((vuint32_t *) 0xE000E42C)
#define NVIC_IPR_12            *((vuint32_t *) 0xE000E430)
#define NVIC_IPR_13            *((vuint32_t *) 0xE000E434)
#define NVIC_IPR_14            *((vuint32_t *) 0xE000E438)
#define NVIC_IPR_15            *((vuint32_t *) 0xE000E43C)
#define NVIC_IPR_16            *((vuint32_t *) 0xE000E440)
#define NVIC_IPR_17            *((vuint32_t *) 0xE000E444)
#define NVIC_IPR_18            *((vuint32_t *) 0xE000E448)
#define NVIC_IPR_19            *((vuint32_t *) 0xE000E44C)
#define NVIC_IPR_20            *((vuint32_t *) 0xE000E450)
#define NVIC_IPR_21            *((vuint32_t *) 0xE000E454)
#define NVIC_IPR_22            *((vuint32_t *) 0xE000E458)
*/
#define NVIC_STIR               *((vuint32_t *) 0xE000EF00)

/**
 * @brief the size of each register in the nvic registers
 */
#define REGISTER_WIDTH          32
#define PRIORITY_GROUP_CHECK    0x80000000
#define PRIORITY_GROUP_CLEAR    0xFFFFF8FF
#define PRIORITY_GROUP_BASE     0x05FA0300
/**
 * @brief NVIC list of Registers
 **/
typedef struct{

    /**
     * @brief Interrupt set-enable register
     **/
    vuint32_t ISER         [ 32 ];
    /**
     * @brief Interrupt clear-enable register
     **/
    vuint32_t ICER         [ 32 ];
    /**
     * @brief Interrupt set-pending register
     **/
    vuint32_t ISPR         [ 32 ];
    /**
     * @brief Interrupt clear-pending register
     **/
    vuint32_t ICPR         [ 32 ];
    /**
     * @brief Interrupt active bit register
     **/
    vuint32_t IAPR         [ 32 ];
    /**
     * @brief reserved locations
     **/
    vuint32_t RESERVED     [ 32 ];
    /**
     * @brief Interrupt priority register
     **/
    vuint8_t IPR           [ 128];

}NVIC_REG_t;

typedef struct{

   vuint32_t CPUID;
   vuint32_t ICSR;
   vuint32_t VTOR;
   vuint32_t AIRCR;
   vuint32_t SCR;
   vuint32_t CCR;
   vuint32_t SHPR1;
   vuint32_t SHPR2;
   vuint32_t SHPR3;
   vuint32_t SHCSR;
   vuint32_t CFSR;
   vuint32_t HFSR;
   vuint32_t RESERVED;
   vuint32_t MMFAR;
   vuint32_t BFAR;

}SCB_REG_t;


/**
 * @brief Pointer to NVIC registers
 **/
#define NVIC      ( ( volatile NVIC_REG_t *)0xE000E100 )
/**
 * @brief Pointer to SCB registers
 **/
#define SCB ((volatile SCB_REG_t *) 0xE000ED00 )

/**********************************************************
 *
 * @brief this function get the current grouping setting from core
 * @param priorityGrouping
 * @return locStatus
 */
static ENM_NVIC_ERROR_STATUS_t nvicGetPriorityGrouping(uint32_t *priorityGrouping);

ENM_NVIC_ERROR_STATUS_t nvicEnableIrq(ENM_ISQ_t interruptRequestNumber)
{
    ENM_NVIC_ERROR_STATUS_t locStatus = enmNVIC_Status_NOT_OK;
    uint32_t locInterruptNumber=interruptRequestNumber;
    if(locInterruptNumber < MAX_NUMBER_OF_INTERRUPTS)
    {
        locStatus = enmNVIC_Status_Wrong_Arguments;
    }
    else
    {
        NVIC->ISER[locInterruptNumber / REGISTER_WIDTH] |= (1<<(locInterruptNumber % REGISTER_WIDTH));
        locStatus=enmNVIC_Status_OK;
    }
    return locStatus;
}
ENM_NVIC_ERROR_STATUS_t nvicDisableIrq(ENM_ISQ_t interruptRequestNumber)
{
    ENM_NVIC_ERROR_STATUS_t locStatus = enmNVIC_Status_NOT_OK;
    uint32_t locInterruptNumber=interruptRequestNumber;
    if(locInterruptNumber > MAX_NUMBER_OF_INTERRUPTS)
    {
        locStatus = enmNVIC_Status_Wrong_Arguments;
    }
    else
    {
        NVIC->ICER[locInterruptNumber / REGISTER_WIDTH] |= (1<<(locInterruptNumber % REGISTER_WIDTH));
        locStatus=enmNVIC_Status_OK;
    }
    return locStatus;
}
ENM_NVIC_ERROR_STATUS_t nvicSetPendingIrq(ENM_ISQ_t interruptRequestNumber)
{
    ENM_NVIC_ERROR_STATUS_t locStatus = enmNVIC_Status_NOT_OK;
    uint32_t locInterruptNumber=interruptRequestNumber;
    if(locInterruptNumber > MAX_NUMBER_OF_INTERRUPTS)
    {
        locStatus = enmNVIC_Status_Wrong_Arguments;
    }
    else
    {
        NVIC->ISPR[locInterruptNumber / REGISTER_WIDTH] |= (1<<(locInterruptNumber % REGISTER_WIDTH));
        locStatus=enmNVIC_Status_OK;
    }
    return locStatus;
}
ENM_NVIC_ERROR_STATUS_t nvicClearPendingIrq(ENM_ISQ_t interruptRequestNumber)
{
    ENM_NVIC_ERROR_STATUS_t locStatus = enmNVIC_Status_NOT_OK;
    uint32_t locInterruptNumber=interruptRequestNumber;
    if(locInterruptNumber > MAX_NUMBER_OF_INTERRUPTS)
    {
        locStatus = enmNVIC_Status_Wrong_Arguments;
    }
    else
    {
        NVIC->ICPR[locInterruptNumber / REGISTER_WIDTH] |= (1<<(locInterruptNumber % REGISTER_WIDTH));
        locStatus=enmNVIC_Status_OK;
    }
    return locStatus;
}
ENM_NVIC_ERROR_STATUS_t nvicGetPendingIrq(ENM_ISQ_t interruptRequestNumber, uint32_t * value)
{
    ENM_NVIC_ERROR_STATUS_t locStatus = enmNVIC_Status_NOT_OK;
    uint32_t locInterruptNumber=interruptRequestNumber;
    uint8_t locValue;

    if(locInterruptNumber > MAX_NUMBER_OF_INTERRUPTS)
    {
        locStatus = enmNVIC_Status_Wrong_Arguments;
    }
    else if (value == NULL)
    {
        locStatus=enmNVIC_Status_NULL_Pointer;
    }
    else
    {
        locValue= (((NVIC->ICPR[locInterruptNumber / REGISTER_WIDTH]) >> (locInterruptNumber % REGISTER_WIDTH)) & 0x01);
        *value=locValue;
        locStatus=enmNVIC_Status_OK;
    }
    return locStatus;
}
ENM_NVIC_ERROR_STATUS_t nvicGetActive (ENM_ISQ_t interruptRequestNumber, uint32_t * value)
{
    ENM_NVIC_ERROR_STATUS_t locStatus = enmNVIC_Status_NOT_OK;
    uint32_t locInterruptNumber=interruptRequestNumber;
    uint8_t locValue;

    if(locInterruptNumber > MAX_NUMBER_OF_INTERRUPTS)
    {
        locStatus = enmNVIC_Status_Wrong_Arguments;
    }
    else if (value == NULL)
    {
        locStatus=enmNVIC_Status_NULL_Pointer;
    }
    else
    {
        locValue= (((NVIC->IAPR[locInterruptNumber / REGISTER_WIDTH]) >> (locInterruptNumber % REGISTER_WIDTH)) & 0x01);
        *value=locValue;
        locStatus=enmNVIC_Status_OK;
    }
    return locStatus;
}
ENM_NVIC_ERROR_STATUS_t nvicSetPriority(ENM_ISQ_t interruptRequestNumber, ENM_GroupPriority_t groupPriority, ENM_SubGroupPriority_t subGroupPriority)
{
    ENM_NVIC_ERROR_STATUS_t locStatus = enmNVIC_Status_NOT_OK;
    uint32_t locInterruptNumber=interruptRequestNumber;
    uint32_t locPriorityGrouping=0;
    uint8_t locPriority=0;
    if(locInterruptNumber > MAX_NUMBER_OF_INTERRUPTS || groupPriority > 15 || subGroupPriority > 15)
    {
        locStatus = enmNVIC_Status_Wrong_Arguments;
    }
    else
    {
        locStatus = nvicGetPriorityGrouping(&locPriorityGrouping);
        if (!locStatus)
        {
            locStatus=enmNVIC_Status_NOT_OK;
        }
        else
        {
            locPriority = (uint8_t)(subGroupPriority | (groupPriority << ((locPriorityGrouping - PRIORITY_GROUP_BASE)/ 0x100)));
            NVIC->IPR[locInterruptNumber] =(uint8_t)(locPriority <<4);
            locStatus = enmNVIC_Status_OK;
        }
    }
    return locStatus;
}
ENM_NVIC_ERROR_STATUS_t nvicGetPriority(ENM_ISQ_t interruptRequestNumber, uint8_t * value)
{
    ENM_NVIC_ERROR_STATUS_t locStatus = enmNVIC_Status_NOT_OK;
    uint32_t locInterruptNumber=interruptRequestNumber;
    uint8_t locValue;

    if(locInterruptNumber > MAX_NUMBER_OF_INTERRUPTS)
    {
        locStatus = enmNVIC_Status_Wrong_Arguments;
    }
    else if (value == NULL)
    {
        locStatus=enmNVIC_Status_NULL_Pointer;
    }
    else
    {
        locValue= ((NVIC->IPR[locInterruptNumber]) >> (4));
        *value=locValue;
        locStatus=enmNVIC_Status_OK;
    }
    return locStatus;
}
ENM_NVIC_ERROR_STATUS_t nvicSetPriorityGrouping(uint32_t priorityGrouping)
{
    ENM_NVIC_ERROR_STATUS_t locStatus = enmNVIC_Status_NOT_OK;
    uint32_t locGroupPriority=priorityGrouping;
    uint32_t locRegister= SCB->AIRCR;
    if(!(priorityGrouping & PRIORITY_GROUP_CHECK))
    {
        locStatus = enmNVIC_Status_Wrong_Arguments;
    }
    else
    {
       locRegister &=PRIORITY_GROUP_CLEAR;
       locRegister |=(locGroupPriority &(~PRIORITY_GROUP_CHECK));
       SCB->AIRCR= locRegister;
       locStatus=enmNVIC_Status_OK;
    }
    return locStatus;
}
ENM_NVIC_ERROR_STATUS_t nvicTriggerSoftwareInterrupt(ENM_ISQ_t interruptRequestNumber)
{
    ENM_NVIC_ERROR_STATUS_t locStatus = enmNVIC_Status_NOT_OK;
    uint32_t locInterruptNumber=interruptRequestNumber;
    if(locInterruptNumber > MAX_NUMBER_OF_INTERRUPTS)
    {
        locStatus = enmNVIC_Status_Wrong_Arguments;
    }
    else
    {
        NVIC_STIR = locInterruptNumber;
        locStatus=enmNVIC_Status_OK;
    }
    return locStatus;
}
static ENM_NVIC_ERROR_STATUS_t nvicGetPriorityGrouping(uint32_t *priorityGrouping)
{
    ENM_NVIC_ERROR_STATUS_t locStatus = enmNVIC_Status_NOT_OK;
    uint32_t locValue;

    if (priorityGrouping == NULL)
    {
        locStatus=enmNVIC_Status_NULL_Pointer;
    }
    else
    {
        locValue= SCB->AIRCR;
        *priorityGrouping = locValue;
        locStatus=enmNVIC_Status_OK;
    }
    return locStatus;
}
