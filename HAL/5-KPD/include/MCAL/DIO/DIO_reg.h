#ifndef DIO_REG_H_
#define DIO_REG_H_

/***************************************************************************************************************/
/*                                              DIO Registers Definition                                       */
/***************************************************************************************************************/
// DDR register
#define DDRA_REG    *((volatile uint8*) 0x3A)
#define DDRB_REG    *((volatile uint8*) 0x37)
#define DDRC_REG    *((volatile uint8*) 0x34)
#define DDRD_REG    *((volatile uint8*) 0x31)


// PORT register
#define PORTA_REG   *((volatile uint8*) 0x3B)
#define PORTB_REG   *((volatile uint8*) 0x38)
#define PORTC_REG   *((volatile uint8*) 0x35)
#define PORTD_REG   *((volatile uint8*) 0x32)


// PIN register
#define PINA_REG    *((volatile uint8*) 0x39)
#define PINB_REG    *((volatile uint8*) 0x36)
#define PINC_REG    *((volatile uint8*) 0x33)
#define PIND_REG    *((volatile uint8*) 0x30)

// SFIOR: Special Function Input Output Register
#define SFIOR_REG   *((volatile uint8*) 0x50)
#define PUD_BIT 2

#endif /* DIO_REG_H_ */