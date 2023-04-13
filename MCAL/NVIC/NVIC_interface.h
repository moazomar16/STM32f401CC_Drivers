/**********************************************************
 * NVIC_interface.h
 *
 *  @date: Mar 10, 2023
 *      @Author: Moaz Omar
 *
 *********************************************************/

#ifndef COTS_INSHALLAH_NVIC_INTERFACE_H
#define COTS_INSHALLAH_NVIC_INTERFACE_H

#include "Libraries/Std_Types.h"



#define MAX_NUMBER_OF_INTERRUPTS        84

/**
 * @brief 0 bit for sub & 4 bit For group
 **/
#define PRIORITY_GROUP_3     0x85FA0300
/**
 * @brief 1 bit for sub & 3 bit For group
 **/
#define PRIORITY_GROUP_4     0x85FA0400
/**
 * @brief 2 bit for sub & 2 bit For group
 **/
#define PRIORITY_GROUP_5     0x85FA0500
/**
 * @brief 3 bit for sub & 1 bit For group
 **/
#define PRIORITY_GROUP_6     0x85FA0600
/**
 * @brief 4 bit for sub & 0 bit For group
 **/
#define PRIORITY_GROUP_7     0x85FA0700

/**
 *
 *      @brief This enum is used to indicate the number of interrupt requests
 *
 **/
typedef enum
{
    WWDG                =0,
    EXTI_16             =1,
    EXTI_21             =2,
    EXTI_22             =3,
    FLASH               =4,
    RCC                 =5,
    EXTI_0              =6,
    EXTI_1              =7,
    EXTI_2              =8,
    EXTI_3              =9,
    EXTI_4              =10,
    DMA1_Stream_0       =11,
    DMA1_Stream_1       =12,
    DMA1_Stream_2       =13,
    DMA1_Stream_3       =14,
    DMA1_Stream_4       =15,
    DMA1_Stream_5       =16,
    DMA1_Stream_6       =17,
    ADC                 =18,
    EXTI_9_5            =23,
    TIM1_BRK_TIM9       =24,
    TIM1_BRK_TIM10      =25,
    TIM1_TRG_COM_TIM    =26,
    TIM1_CC             =27,
    TIM_2               =28,
    TIM_3               =29,
    TIM_4               =30,
    I2C1_EV             =31,
    I2C1_ER             =32,
    I2C2_EV             =33,
    I2C2_ER             =34,
    SPI1                =35,
    SPI2                =36,
    USART1              =37,
    USART2              =38,
    EXTI_15_10          =40,
    EXTI_17_RTC_Alarm   =41,
    EXTI_18_OTG_FS_WKUP =42,
    DMA1_Stream7        =47,
    SDIO                =49,
    TIM_5               =50,
    SPI_3               =51,
    DMA2_Stream_0       =56,
    DMA2_Stream_1       =57,
    DMA2_Stream_2       =58,
    DMA2_Stream_3       =59,
    DMA2_Stream_4       =60,
    OTG_FS              =67,
    DMA2_Stream_5       =68,
    DMA2_Stream_6       =69,
    DMA2_Stream_7       =70,
    USART_6             =71,
    I2C3_EV             =72,
    I2C3_ER             =73,
    FPU                 =81,
    SPI_4               =84,


}ENM_ISQ_t;

/**********************************************************
 *
 *      @brief This enum is used to indicate Group priority
 *
 *********************************************************/
typedef enum
{
    Group_priority_0=0,
    Group_priority_1,
    Group_priority_2,
    Group_priority_3,
    Group_priority_4,
    Group_priority_5,
    Group_priority_6,
    Group_priority_7,
    Group_priority_8,
    Group_priority_9,
    Group_priority_10,
    Group_priority_11,
    Group_priority_12,
    Group_priority_13,
    Group_priority_14,
    Group_priority_15

}ENM_GroupPriority_t;

/**********************************************************
 *
 *      @brief This enum is used to indicate SubGroup priority
 *
 *********************************************************/
typedef enum
{
    SubGroup_priority_0=0,
    SubGroup_priority_1,
    SubGroup_priority_2,
    SubGroup_priority_3,
    SubGroup_priority_4,
    SubGroup_priority_5,
    SubGroup_priority_6,
    SubGroup_priority_7,
    SubGroup_priority_8,
    SubGroup_priority_9,
    SubGroup_priority_10,
    SubGroup_priority_11,
    SubGroup_priority_12,
    SubGroup_priority_13,
    SubGroup_priority_14,
    SubGroup_priority_15

}ENM_SubGroupPriority_t;




typedef enum
{
    enmNVIC_Status_OK=0,
    enmNVIC_Status_NOT_OK,
    enmNVIC_Status_NULL_Pointer,
    enmNVIC_Status_Wrong_BUS,
    enmNVIC_Status_Wrong_Arguments,
    enmNVIC_Status_TIME_OUT
}ENM_NVIC_ERROR_STATUS_t;

/**********************************************************
 *
 * @brief this function responsible for enabling peripheral interrupt
 * @param interruptRequestNumber
 * @warning this function can only deals with one interrupt at a time
 * @return loc_status
 *********************************************************/
ENM_NVIC_ERROR_STATUS_t nvicEnableIrq(ENM_ISQ_t interruptRequestNumber) ;

/**********************************************************
 *
 * @brief this function responsible for disabling peripheral interrupt
 * @param interruptRequestNumber
 * @warning this function can only deals with one interrupt at a time
 * @return loc_status
 *********************************************************/
ENM_NVIC_ERROR_STATUS_t nvicDisableIrq(ENM_ISQ_t interruptRequestNumber) ;

/**********************************************************
 *
 * @brief this function responsible for setting peripheral pending interrupt flag
 * @param interruptRequestNumber
 * @warning this function can only deals with one interrupt at a time
 * @return loc_status
 *********************************************************/
ENM_NVIC_ERROR_STATUS_t nvicSetPendingIrq(ENM_ISQ_t interruptRequestNumber);

/**********************************************************
 *
 * @brief this function responsible for clearing peripheral pending interrupt flag
 * @param interruptRequestNumber
 * @warning this function can only deals with one interrupt at a time
 * @return loc_status
 *********************************************************/
ENM_NVIC_ERROR_STATUS_t nvicClearPendingIrq(ENM_ISQ_t interruptRequestNumber) ;

/**********************************************************
 *
 * @brief this function responsible for getting peripheral active status flag
 * @param interruptRequestNumber
 * @param value
 * @warning this function can only deals with one interrupt at a time
 * @return loc_status
 *********************************************************/
ENM_NVIC_ERROR_STATUS_t nvicGetActive (ENM_ISQ_t interruptRequestNumber, uint32_t * value);

/**********************************************************
 *
 * @brief this function responsible for getting peripheral pending status flag
 * @param interruptRequestNumber
 * @param value
 * @warning this function can only deals with one interrupt at a time
 * @return loc_status
 *********************************************************/
ENM_NVIC_ERROR_STATUS_t nvicGetPendingIrq(ENM_ISQ_t interruptRequestNumber, uint32_t * value);

/**********************************************************
 *
 * @brief this function responsible for setting peripheral interrupt priority
 * @param interruptRequestNumber
 * @param priority
 * @warning this function can only deals with one interrupt at a time
 * @return loc_status
 *********************************************************/
ENM_NVIC_ERROR_STATUS_t  nvicSetPriority(ENM_ISQ_t interruptRequestNumber, ENM_GroupPriority_t groupPriority, ENM_SubGroupPriority_t subGroupPriority);

/**********************************************************
 *
 * @brief this function responsible for getting peripheral interrupt priority
 * @param interruptRequestNumber
 * @param value
 * @warning this function can only deals with one interrupt at a time
 * @return loc_status
 *********************************************************/
ENM_NVIC_ERROR_STATUS_t nvicGetPriority(ENM_ISQ_t interruptRequestNumber, uint8_t * value);

/**********************************************************
 *
 * @brief this function responsible for setting peripheral interrupt group priority
 * @param priorityGrouping
 *      @arg PRIORITY_GROUP_3
 *      @arg PRIORITY_GROUP_4
 *      @arg PRIORITY_GROUP_5
 *      @arg PRIORITY_GROUP_6
 *      @arg PRIORITY_GROUP_7
 * @warning this function can only deals with one interrupt at a time
 * @return loc_status
 *********************************************************/
ENM_NVIC_ERROR_STATUS_t nvicSetPriorityGrouping(uint32_t priorityGrouping);

/**********************************************************
 *
 * @brief this function responsible for Generating software interrupt
 * @param interruptRequestNumber
 * @warning this function can only deals with one interrupt at a time
 * @return loc_status
 *********************************************************/
ENM_NVIC_ERROR_STATUS_t nvicTriggerSoftwareInterrupt(ENM_ISQ_t interruptRequestNumber);


#endif /* COTS_INSHALLAH_NVIC_INTERFACE_H */
