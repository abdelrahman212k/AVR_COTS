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
#include "../include/HAL/KPD/KPD_interface.h"

void main(void)
{
	uint8 Local_u8PressedKey = 0xff;

	DIO_vInit();
	LCD_vInit();

	LCD_u8SendString("Press a key");
	LCD_vGoToXY(0,1);

	while(1)
	{
		Local_u8PressedKey = KPD_u8GetPressedKey();
		if(Local_u8PressedKey != 0xff)
		{
			LCD_vSendData(Local_u8PressedKey);
		}
	}
}
