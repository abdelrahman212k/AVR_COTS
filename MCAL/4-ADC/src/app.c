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
#include "../include/MCAL/ADC/ADC_interface.h"


void main(void)
{
	uint8 Local_u8DigitalReading;
	DIO_vInit();
	ADC_vInit();
	while(1)
	{
		Local_u8DigitalReading = (uint8)ADC_u16GetChannelReading(ADC_SINGLE_ENDED_CH0);
		DIO_u8SetPortValue(DIO_u8PORTC, Local_u8DigitalReading);
	}
}
