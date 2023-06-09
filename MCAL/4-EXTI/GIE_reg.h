#ifndef GIE_REG_H_
#define GIE_REG_H_

#define SREG_REG        *((volatile uint8*) 0x5F)   // Status Register
#define SREG_I          7U                          // Interrupt Bit

#endif /* GIE_REG_H_ */
