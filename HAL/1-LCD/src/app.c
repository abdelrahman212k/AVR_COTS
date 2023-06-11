/*
 * app.c
 *
 *  Created on: Jun 11, 2023
 *      Author: Abdelrahman Kamal
 */

/********************  LIB includes  ********************/
#include "../include/LIB/STD_TYPES.h"
#include "../include/LIB/DEFINES.h"
#include "../include/LIB/BIT_MATH.h"
#include "../include/LIB/ERROR_STATES.h"

#include <util/delay.h>

/********************  MCAL includes  ********************/
#include "../include/MCAL/DIO/DIO_interface.h"

/********************  HAL includes  ********************/
#include "../include/HAL/LCD/LCD_interface.h"

void main(void)
{
	/* LCD pins initialization */
	/*DIO_u8SetPinDirection(DIO_u8PORTA, DIO_u8PIN7, DIO_u8PIN_OUTPUT); // RS pin
	DIO_u8SetPinDirection(DIO_u8PORTA, DIO_u8PIN6, DIO_u8PIN_OUTPUT); // E pin

	DIO_u8SetPinDirection(DIO_u8PORTD, DIO_u8PIN0, DIO_u8PIN_OUTPUT); // D4 pin
	DIO_u8SetPinDirection(DIO_u8PORTD, DIO_u8PIN1, DIO_u8PIN_OUTPUT); // D5 pin
	DIO_u8SetPinDirection(DIO_u8PORTD, DIO_u8PIN2, DIO_u8PIN_OUTPUT); // D6 pin
	DIO_u8SetPinDirection(DIO_u8PORTD, DIO_u8PIN3, DIO_u8PIN_OUTPUT); // D7 pin*/

	DIO_vInit();

	LCD_vInit();

//	LCD_u8SendString("Hi, Abdelrahman");
//	LCD_vGoToXY(0,1);
//	LCD_u8SendString("0b:");
//	LCD_vSendNumber(1412);
//	LCD_vSendBinaryNumber(1412);

	uint8 Local_u8MyPattern[8] = {0,0, 0b00001010, 0b00011111, 0b00011111, 0b00001110, 0b00000100};

	LCD_vSendData('L');
	LCD_vGoToXY(2,0);
	LCD_u8SendString("VE YOU");
	LCD_vSendSpecialChar(Local_u8MyPattern, 0, 1, 0);
	while(1)
	{

	}
}
