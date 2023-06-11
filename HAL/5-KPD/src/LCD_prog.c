/***************************************************************************************************/
/****************             Author: Abdelrahman Kamal Eldean                 *********************/
/****************             File: LCD_prog.h                                 *********************/
/****************             Version: 1.00                                    *********************/
/***************************************************************************************************/

/********************  LIB includes  ********************/
#include "../include/LIB/STD_TYPES.h"
#include "../include/LIB/DEFINES.h"
#include "../include/LIB/BIT_MATH.h"
#include "../include/LIB/ERROR_STATES.h"

#include <util/delay.h>

/********************  MCAL includes  ********************/
#include "../include/MCAL/DIO/DIO_interface.h"

/********************  HAL includes  ********************/
#include "../include/HAL/LCD/LCD_prv.h"
#include "../include/HAL/LCD/LCD_cfg.h"
#include "../include/HAL/LCD/LCD_interface.h"


static void LCD_vSendEnablePulse(void)
{
	/* Send enable pulse */
	DIO_u8SetPinValue(LCD_CTRL_PORT, LCD_E_PIN, DIO_u8PIN_HIGH);
	_delay_ms(2);
	DIO_u8SetPinValue(LCD_CTRL_PORT, LCD_E_PIN, DIO_u8PIN_LOW);
}


#if LCD_OP_MODE == FOUR_BIT_MODE
static void LCD_vSend4BitData(uint8 Copy_u8Nipple)
{
	/* Send the 4 LSBs */
	DIO_u8SetPinValue(LCD_DATA_PORT, LCD_D4_PIN, GET_BIT(Copy_u8Nipple, 0));
	DIO_u8SetPinValue(LCD_DATA_PORT, LCD_D5_PIN, GET_BIT(Copy_u8Nipple, 1));
	DIO_u8SetPinValue(LCD_DATA_PORT, LCD_D6_PIN, GET_BIT(Copy_u8Nipple, 2));
	DIO_u8SetPinValue(LCD_DATA_PORT, LCD_D7_PIN, GET_BIT(Copy_u8Nipple, 3));
}
#endif


void LCD_vSendCmd(uint8 Copy_u8Cmd)
{
	/* Set RS pin to low for command */
	DIO_u8SetPinValue(LCD_CTRL_PORT, LCD_RS_PIN, DIO_u8PIN_LOW);

#if LCD_RW_CTRL == ENABLED
	/* Set RW pin to low for writing operation */
	DIO_u8SetPinValue(LCD_CTRL_PORT, LCD_RW_PIN, DIO_u8PIN_LOW);
#endif

#if LCD_OP_MODE == EIGHT_BIT_MODE
	/* Send command on data pins */
	DIO_u8SetPortValue(LCD_DATA_PORT, Copy_u8Cmd);

	/* Send enable pulse */
	LCD_vSendEnablePulse();

#elif LCD_OP_MODE == FOUR_BIT_MODE
	/* Send the 4 MSBs first */
	LCD_vSend4BitData(Copy_u8Cmd>>4);
	LCD_vSendEnablePulse();

	/* Then send the 4 LSBs second */
	LCD_vSend4BitData(Copy_u8Cmd);
	LCD_vSendEnablePulse();
#endif
}


void LCD_vSendData(uint8 Copy_u8Data)
{
	/* Set RS pin to high for data */
	DIO_u8SetPinValue(LCD_CTRL_PORT, LCD_RS_PIN, DIO_u8PIN_HIGH);

#if LCD_RW_CTRL == ENABLED
	/* Set RW pin to low for writing operation */
	DIO_u8SetPinValue(LCD_CTRL_PORT, LCD_RW_PIN, DIO_u8PIN_LOW);
#endif

#if LCD_OP_MODE == EIGHT_BIT_MODE
	/* Send command on data pins */
	DIO_u8SetPortValue(LCD_DATA_PORT, Copy_u8Data);

	/* Send enable pulse */
	LCD_vSendEnablePulse();

#elif LCD_OP_MODE == FOUR_BIT_MODE
	/* Send the 4 MSBs first */
	LCD_vSend4BitData(Copy_u8Data>>4);
	LCD_vSendEnablePulse();

	/* Then send the 4 LSBs second */
	LCD_vSend4BitData(Copy_u8Data);
	LCD_vSendEnablePulse();
#endif
}


void LCD_vInit(void)
{
	/* Wait for more than 30ms after power on */
	_delay_ms(40);

	/* Function Set Command Control */
#if LCD_OP_MODE == EIGHT_BIT_MODE
	/* B3: number of LCD lines, 2 lines -> N=1,
	 * B2: font size, 5x7 -> F=0
	 * Other bits constants or don't care */
	LCD_vSendCmd(0b00111000);

#elif LCD_OP_MODE == FOUR_BIT_MODE
	/* Constant command set for 4bit mode */
	LCD_vSend4BitData(0b0010);
	LCD_vSendEnablePulse();
	LCD_vSend4BitData(0b0010);
	LCD_vSendEnablePulse();

	/* B3 = N -> 2 lines N=1,
	 * B2 = F -> 5x7 font size F=0
	 * Remaining 2 bits don't care */
	LCD_vSend4BitData(0b1000);
	LCD_vSendEnablePulse();
#endif

	/* Display ON/OFF control command:
	 * B2: display enable -> D=1,
	 * B1: cursor disable -> C=0,
	 * B0: blink disable  -> B=0
	 * Other bits are constant */
	LCD_vSendCmd(0b00001100);

	/* Display clear */
	LCD_vSendCmd(1);
}


uint8 LCD_u8SendString(char* Copy_chString)
{
	uint8 Local_u8ErrorState = OK;
	if(Copy_chString != NULL)
	{
		uint8 Local_u8Counter = 0;
		while(Copy_chString[Local_u8Counter] != '\0')
		{
			LCD_vSendData(Copy_chString[Local_u8Counter]);
			Local_u8Counter++;
		}
	}
	else
	{
		Local_u8ErrorState = NULL_PTR_ERR;
	}
	return Local_u8ErrorState;
}


void LCD_vSendNumber(sint32 Copy_s32Number)
{
	uint32 Local_s32ReversedNumber = 0;
	uint8 Local_u8RightDigit;
	uint8 Local_u8Counter = 0;

	if(Copy_s32Number == 0)
	{
		LCD_vSendData('0');
		return ;
	}
	else if (Copy_s32Number < 0)
	{
		LCD_vSendData('-');
		Copy_s32Number *= -1;
	}
	while(Copy_s32Number != 0)
	{
		Local_u8RightDigit = Copy_s32Number%10; // Extracting right most digit
		Local_s32ReversedNumber = Local_s32ReversedNumber*10 + Local_u8RightDigit; // put right digit in reversed number
		Copy_s32Number /= 10; // delete right most digit from original number
		Local_u8Counter++;
	}
	while(Local_u8Counter != 0)
	{
		Local_u8RightDigit = Local_s32ReversedNumber%10;
		LCD_vSendData(Local_u8RightDigit + '0');
		Local_s32ReversedNumber /= 10;
		Local_u8Counter--;
	}
}


void LCD_vSendBinaryNumber(sint32 Copy_s32Number)
{
	uint8 Local_u8Counter = 0;
	sint8 Local_s8LastOneIndex = 0;
	while(Local_u8Counter < 32)
	{
		if(GET_BIT(Copy_s32Number, Local_u8Counter) == 1)
		{
			Local_s8LastOneIndex = Local_u8Counter;
		}
		Local_u8Counter++;
	}
	while(Local_s8LastOneIndex >= 0)
	{
		if(GET_BIT(Copy_s32Number, Local_s8LastOneIndex) == 1)
		{
			LCD_vSendData('1');
		}
		else
		{
			LCD_vSendData('0');
		}
		Local_s8LastOneIndex--;
	}
}


void LCD_vGoToXY(uint8 Copy_u8XPosition, uint8 Copy_u8YPosition)
{
	uint8 Local_u8DDRamAddress;
	if(Copy_u8YPosition == 0u)
	{
		Local_u8DDRamAddress = Copy_u8XPosition;
	}
	else if(Copy_u8YPosition == 1u)
	{
		Local_u8DDRamAddress = 0x40 + Copy_u8XPosition;
	}

	/* Set bit 7 for DDRAM address command set */
	SET_BIT(Local_u8DDRamAddress, 7);

	/* Send the command to move go to position */
	LCD_vSendCmd(Local_u8DDRamAddress);
}


void LCD_vSendSpecialChar(uint8* Copy_pu8Pattern, uint8 Copy_u8PatternNumber, uint8 Copy_u8XPosition, uint8 Copy_u8YPosition)
{
	uint8 Local_u8CGRamAddress = Copy_u8PatternNumber * 8u;
	uint8 Local_u8LoopCouter;

	/* Set B6 to one for set CGRAM address command */
	SET_BIT(Local_u8CGRamAddress, 6);

	/* Set CGRAM address */
	LCD_vSendCmd(Local_u8CGRamAddress);

	/* Write pattern into CGRAM */
	for(Local_u8LoopCouter = 0; Local_u8LoopCouter < 8; Local_u8LoopCouter++)
	{
		LCD_vSendData(Copy_pu8Pattern[Local_u8LoopCouter]);
	}

	/* Go to DDRAM to display the pattern */
	LCD_vGoToXY(Copy_u8XPosition, Copy_u8YPosition);

	/* Display the pattern written inside CGRAM */
	LCD_vSendData(Copy_u8PatternNumber);
}
