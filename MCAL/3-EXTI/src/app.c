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
#include "../include/MCAL/GIE/GIE_interface.h"
#include "../include/MCAL/EXTI/EXTI_interface.h"

void LED_On(void);
void LED_Off(void);

void main(void)
{
	DIO_vInit();
	EXTI_vInit();
	EXTI_u8SetCallBack(EXTI_u8INT0, &LED_On);
	EXTI_u8SetCallBack(EXTI_u8INT1, &LED_Off);
	GIE_vEnableGlobalInterrupt();
	while(1)
	{

	}
}

void LED_On(void)
{
	DIO_u8SetPinValue(DIO_u8PORTA, DIO_u8PIN0, DIO_u8PIN_HIGH);
}

void LED_Off(void)
{
	DIO_u8SetPinValue(DIO_u8PORTA, DIO_u8PIN0, DIO_u8PIN_LOW);
}
