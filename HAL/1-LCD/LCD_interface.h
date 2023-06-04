/***************************************************************************************************/
/****************             Author: Abdelrahman Kamal Eldean                 *********************/
/****************             File: LCD_interface.h                            *********************/
/****************             Version: 1.00                                    *********************/
/***************************************************************************************************/

#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_


void LCD_vSendCmd(uint8 Copy_u8Cmd);

void LCD_vSendData(uint8 Copy_u8Data);

void LCD_vInit(void);

uint8 LCD_u8SendString(char* Copy_chString);

void LCD_vSendNumber(sint32 Copy_s32Number);

void LCD_vSendBinaryNumber(sint32 Copy_s32Number);

void LCD_vGoToXY(uint8 Copy_u8XPosition, uint8 Copy_u8YPosition);

void LCD_vSendSpecialChar(uint8* Copy_pu8Pattern, uint8 Copy_u8PatternNumber, uint8 Copy_u8XPosition, uint8 Copy_u8YPosition);

#endif
