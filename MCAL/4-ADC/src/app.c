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


void main(void)
{
	DIO_vInit();
	GIE_vEnableGlobalInterrupt();
	while(1)
	{

	}
}
