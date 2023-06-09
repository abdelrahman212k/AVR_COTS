/**
 *@file PORT_reg.h
 * @author Abdelrahman Kamal
 * @brief Registers definition for PORT driver
 * @version 0.1
 * @date 2023-05-22
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef PORT_REG_H_
#define PORT_REG_H_

/* PORT Direction Registers */
#define DDRA_REG  *((volatile uint8*) 0x3A)
#define DDRB_REG  *((volatile uint8*) 0x37)
#define DDRC_REG  *((volatile uint8*) 0x34)
#define DDRD_REG  *((volatile uint8*) 0x31)

/* PORT Value Registers */
#define PORTA_REG *((volatile uint8*) 0x3B)
#define PORTB_REG *((volatile uint8*) 0x38)
#define PORTC_REG *((volatile uint8*) 0x35)
#define PORTD_REG *((volatile uint8*) 0x32)

#endif /* PORT_REG_H_ */
