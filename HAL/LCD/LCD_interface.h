/**********************************************************
 *
 *  @name LCD_interface.c
 *  @date: Mar 26, 2023
 *  @Author: Moaz Omar
 *  @category HAL DRIVER
 *  @GitHub https://github.com/moazomar16
 *
 *********************************************************/
#ifndef WORKINGDIR_LCD_INTERFACE_H
#define WORKINGDIR_LCD_INTERFACE_H

#include "LCD_Config.h"
#include "Libraries/Error_Status.h"


extern const LCD_CFG_t lcd;

#define CONCATENATE_HELPER(b7,b6,b5,b4,b3,b2,b1,b0)     0b##b7##b6##b5##b4##b3##b2##b1##b0
#define CONCATENATE(b7,b6,b5,b4,b3,b2,b1,b0)            CONCATENATE_HELPER(b7,b6,b5,b4,b3,b2,b1,b0)
#define LCD_COMMAND                                     0
#define LCD_DATA                                        1
#define LCD_READ                                        0
#define LCD_WRITE                                       1

#define LCD_CLEAR_DISPLAY                               0x01
#define LCD_RETURN_HOME                                 0x02
#define LCD_ENTRY_MODE                                  CONCATENATE(0,0,0,0,0,1,lcd.operationMode.entryMode,lcd.operationMode.displayShiftMode)
#define LCD_DISPLAY_CONTROL                             CONCATENATE(0,0,0,0,1,lcd.operationMode.displayState,lcd.operationMode.cursorState,lcd.operationMode.cursorBlink)
#define LCD_CD_CURSOR_DISPLAY_SHIFT                     CONCATENATE(0,0,0,1,lcd.operationMode.cursorDisplayShiftMode,lcd.operationMode.shiftDirection,0,0)
#define LCD_FUNCTION_SET                                CONCATENATE(0,0,1,lcd.operationMode.mode,lcd.operationMode.numberOfLines,lcd.operationMode.font,0,0)



#endif //WORKINGDIR_LCD_INTERFACE_H
