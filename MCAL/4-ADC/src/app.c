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

void Notificaion(void);

void main(void)
{
	uint8 Local_u8DigitalReading;
	DIO_vInit();
	ADC_vInit();
	ADC_CHAIN_t ChainConversions = {.ChainSize = 2,
									.ChannelArray = {ADC_SINGLE_ENDED_CH0, ADC_SINGLE_ENDED_CH1},
									.ADC_pvfNotificationFunc = &Notificaion};
	while(1)
	{
		ADC_u8StartConversionSync(ADC_SINGLE_ENDED_CH0, (uint16*)&Local_u8DigitalReading);
		DIO_u8SetPortValue(DIO_u8PORTC, Local_u8DigitalReading);
	}
}

void Notificaion(void)
{

}
