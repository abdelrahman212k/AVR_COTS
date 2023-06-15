/**
 * @file ADC_reg.h
 * @author Abdelrahman Kamal (abdelrahman.k212@gmail.com)
 * @brief register definition for ADC peripheral
 * @version 0.1
 * @date 2023-06-13
 */
#ifndef ADC_REG_H_
#define ADC_REG_H_

#define ADMUX_REG       *((volatile uint8*) 0x27)   //ADC multiplexer selection register

#define ADMUX_REFS0     7U                          //ADC reference selection bit1
#define ADMUX_REFS1     6U                          //ADC reference selection bit0
#define ADMUX_ADLAR     5U                          //ADC left adjust result



#define ADCSRA_REG      *((volatile uint8*) 0x26)   //ADC control & status register A

#define ADCSRA_ADEN     7U                          //ADC enable
#define ADCSRA_ADSC     6U                          //ADC start conversion
#define ADCSRA_ADATE    5U                          //ADC auto trigger enable
#define ADCSRA_ADIF     4U                          //ADC interrupt flag
#define ADCSRA_ADIE     3U                          //ADC interrupt enable
#define ADCSRA_ADPS2    2U                          //ADC prescaler bit2
#define ADCSRA_ADPS1    1U                          //ADC prescaler bit1
#define ADCSRA_ADPS0    0U                          //ADC prescaler bit0



#define ADCH_REG        *((volatile uint8*) 0x25)   //ADC data register HIGH
#define ADCL_REG        *((volatile uint8*) 0x24)   //ADC data register LOW
#define ADC_DATA_REG    *((volatile uint16*) 0x24)  //ADC 10bit data register

#ifndef SFIOR_REG
#define SFIOR_REG       *((volatile uint8*) 0x50)    // Special Function Input Output Register
#endif

#define SFIOR_ADTS0     5U                          //ADC auto trigger source bit0
#define SFIOR_ADTS1     6U                          //ADC auto trigger source bit1
#define SFIOR_ADTS2     7U                          //ADC auto trigger source bit2

#endif /* ADC_REG_H_ */
