/***************************************************************************************************/
/****************             Author: Abdelrahman Kamal Eldean                 *********************/
/****************             File: LCD_cfg.h                                  *********************/
/****************             Version: 1.00                                    *********************/
/***************************************************************************************************/

#ifndef LCD_CFG_H_
#define LCD_CFG_H_

/*
 *	Configure the operation mode for LCD
 *	Configure Options:	1- EIGHT_BIT_MODE
 *           			2- FOUR_BIT_MODE
 */
#define LCD_OP_MODE 	FOUR_BIT_MODE

/*
 *	Choose the control port for pins: RS, RW, E
 *  Options:    1- DIO_u8PORTA
 *              2- DIO_u8PORTB
 *              3- DIO_u8PORTC
 *              4- DIO_u8PORTD
 */
#define LCD_CTRL_PORT   DIO_u8PORTA

/*
 *	Choose the data pins port: D0 ~ D7
 *  Options:    1- DIO_u8PORTA
 *              2- DIO_u8PORTB
 *              3- DIO_u8PORTC
 *              4- DIO_u8PORTD
 */
#define LCD_DATA_PORT   	DIO_u8PORTD

/*
 *	Choose the pins connected to: RS & E
 *	Options:    [DIO_u8PIN0 ~ DIO_u8PIN7]
*/
#define LCD_RS_PIN  	DIO_u8PIN7
#define LCD_E_PIN   	DIO_u8PIN6

/*
 *	Configure if the RW pin is controlled or not
 *	Options:		1- ENABLED
 * 					2- DISABLED
 */
#define LCD_RW_CTRL		DISABLED
#if LCD_RW_CTRL == ENABLED
/* Choose the pin connected to RW */
#define LCD_RW_PIN  	DIO_u8PIN1

#endif

/* Choosing data pins for 4-Bit mode */
#if LCD_OP_MODE == FOUR_BIT_MODE

#define LCD_D4_PIN  	DIO_u8PIN0
#define LCD_D5_PIN  	DIO_u8PIN1
#define LCD_D6_PIN  	DIO_u8PIN2
#define LCD_D7_PIN  	DIO_u8PIN3

#endif


#endif
