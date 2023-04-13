/**********************************************************
 *
 *  @name LCD_config.h
 *  @date: Mar 26, 2023
 *  @Author: Moaz Omar
 *  @category HAL DRIVER
 *  @GitHub https://github.com/moazomar16
 *
 *********************************************************/

#ifndef WORKINGDIR_LCD_CONFIG_H
#define WORKINGDIR_LCD_CONFIG_H


#include "MCAL/GPIO/GPIO_interface.h"
#include "Libraries/Std_Types.h"

/**
 *  @brief type contains the bit mode for the lcd
 */
typedef enum
{
    lcd_4_bitMode=0,
    lcd_8_bitMode
}LcdBitMode_t;
/**
 *  @brief type contains the lines option for the lcd
 */
typedef enum
{
    lcd_1_lineMode=0,
    lcd_2_lineMode
}LcdLineMode_t;
/**
 *  @brief type contains the font option for the lcd
 */
typedef enum
{
    lcd_5x8_font=0,
    lcd_5x11font

}LcdFont_t;
/**
 *  @brief type contains the display state option for the lcd
 */
typedef enum
{
    lcdDisplayOFF=0,
    lcdDisplayON
}LcdDisplayState_t;
/**
 *  @brief type contains the cursor state option for the lcd
 */
typedef enum
{
    lcdCursorStateOFF=0,
    lcdCursorStateON
}LcdCursorState_t;
/**
 *  @brief type contains the cursor blinking state option for the lcd
 */
typedef enum
{
    lcdCursorBlinkStateOFF=0,
    lcdCursorBlinkStateON
}LcdCursorBlinkState_t;
/**
 *  @brief type contains the cursor entry mode option for the lcd
 */
typedef enum
{
    lcdEntryDecrement=0,
    lcdEntryIncrement
}LcdEntryMode_t;
/**
 *  @brief type contains the display shift state option for the lcd
 */
typedef enum
{
    lcdDisplayShiftOFF=0,
    lcdDisplayShiftON
}LcdDisplayShift_t;
/**
 *  @brief type contains the shift direction option for the lcd
 */
typedef enum
{
    lcdShiftLeft=0,
    lcdShiftRight
}LcdShiftDirection_t;
/**
 *  @brief type contains the display cursor shift state option for the lcd
 */
typedef enum
{
    lcdShiftCursor=0,
    lcdShiftDisplay
}LcdShiftMode_t;

typedef struct
{
    struct {
        /**
         * @brief this variable is used to select the number of lines
         * @option lcd_1_lineMode
         * @option lcd_2_lineMode
         **/
        LcdLineMode_t numberOfLines;
        /**
         * @brief this variable is used to select the number of bits used to interface with the lcd
         * @option lcd_4_bitMode
         * @option lcd_8_bitMode
         **/
        LcdBitMode_t mode;
        /**
         * @brief this variable is used to select the font size for the lcd
         * @option lcd_5x8_font
         * @option lcd_5x11font
         **/
        LcdFont_t font;
        /**
         * @brief this variable is used to select the state of display to be on or off for the lcd
         * @option lcdDisplayOFF
         * @option lcdDisplayON
         **/
        LcdDisplayState_t displayState;
        /**
         * @brief this variable is used to select the state of cursor to be on or off for the lcd
         * @option lcdCursorStateOFF
         * @option lcdCursorStateON
         **/
        LcdCursorState_t cursorState;
        /**
        * @brief this variable is used to select the state of cursor blink to be on or off for the lcd
        * @option lcdCursorBlinkStateOFF
        * @option lcdCursorBlinkStateON
        **/
        LcdCursorBlinkState_t cursorBlink;
        /**
        * @brief this variable is used to select the entry mode for the lcd
        * @option lcdEntryDecrement
        * @option lcdEntryIncrement
        **/
        LcdEntryMode_t entryMode;
        /**
        * @brief this variable is used to select the display shift state for the lcd
        * @option lcdDisplayShiftOFF
        * @option lcdDisplayShiftON
        **/
        LcdDisplayShift_t displayShiftMode;
        /**
        * @brief this variable is used to select cursor display shift mode for the lcd
        * @option lcdShiftCursor
        * @option lcdShiftDisplay
        **/
        LcdShiftMode_t cursorDisplayShiftMode;
        /**
        * @brief this variable is used to select  shift direction for the lcd
        * @option  lcdShiftLeft
        * @option  lcdShiftRight
        **/
        LcdShiftDirection_t shiftDirection;
    }operationMode;
    struct
    {
        /**
         * @brief this variable is used to configure enable pin of the lcd
        **/
        GPIO_PIN_CONFIG_t enable;
        /**
         * @brief this variable is used to configure data pins of the lcd
         **/
        GPIO_PIN_CONFIG_t data[8];
        /**
         * @brief this variable is used to configure read write pin of the lcd
         **/
        GPIO_PIN_CONFIG_t readWrite;
        /**
         * @brief this variable is used to configure register Selector pin of the lcd
         **/
        GPIO_PIN_CONFIG_t registerSelector;
    }lcdPins;
}LCD_CFG_t;


#endif /*WORKINGDIR_LCD_CONFIG_H*/
