/**
 *@file PORT_cfg.h
 * @author Abdelrahman Kamal
 * @brief 
 * @version 0.1
 * @date 2023-05-22
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef PORT_CFG_H_
#define PORT_CFG_H_

/*
Configure pins direction:
    options:    1- INPUT
                2- OUTPUT
*/
//PORTA
#define PORTA_PIN0_DIR      INPUT
#define PORTA_PIN1_DIR      INPUT
#define PORTA_PIN2_DIR      INPUT
#define PORTA_PIN3_DIR      INPUT
#define PORTA_PIN4_DIR      INPUT
#define PORTA_PIN5_DIR      INPUT
#define PORTA_PIN6_DIR      OUTPUT
#define PORTA_PIN7_DIR      OUTPUT

//PORTB
#define PORTB_PIN0_DIR      INPUT
#define PORTB_PIN1_DIR      INPUT
#define PORTB_PIN2_DIR      INPUT
#define PORTB_PIN3_DIR      INPUT
#define PORTB_PIN4_DIR      INPUT
#define PORTB_PIN5_DIR      INPUT
#define PORTB_PIN6_DIR      INPUT
#define PORTB_PIN7_DIR      INPUT

//PORTC
#define PORTC_PIN0_DIR      INPUT
#define PORTC_PIN1_DIR      INPUT
#define PORTC_PIN2_DIR      INPUT
#define PORTC_PIN3_DIR      INPUT
#define PORTC_PIN4_DIR      INPUT
#define PORTC_PIN5_DIR      INPUT
#define PORTC_PIN6_DIR      INPUT
#define PORTC_PIN7_DIR      INPUT

//PORTD
#define PORTD_PIN0_DIR      OUTPUT
#define PORTD_PIN1_DIR      OUTPUT
#define PORTD_PIN2_DIR      OUTPUT
#define PORTD_PIN3_DIR      OUTPUT
#define PORTD_PIN4_DIR      INPUT
#define PORTD_PIN5_DIR      INPUT
#define PORTD_PIN6_DIR      INPUT
#define PORTD_PIN7_DIR      INPUT


/*
Configure initial value of pins, Options for input pins:    1- FLOATING
                                                            2- PULL_UP

                                Options for output pins:    1- HIGH
                                                            2- LOW
*/
//PORTA
#define PORTA_PIN0_INITIAL_VAL      FLOATING
#define PORTA_PIN1_INITIAL_VAL      FLOATING
#define PORTA_PIN2_INITIAL_VAL      FLOATING
#define PORTA_PIN3_INITIAL_VAL      FLOATING
#define PORTA_PIN4_INITIAL_VAL      FLOATING
#define PORTA_PIN5_INITIAL_VAL      FLOATING
#define PORTA_PIN6_INITIAL_VAL      LOW
#define PORTA_PIN7_INITIAL_VAL      LOW

//PORTB
#define PORTB_PIN0_INITIAL_VAL      FLOATING
#define PORTB_PIN1_INITIAL_VAL      FLOATING
#define PORTB_PIN2_INITIAL_VAL      FLOATING
#define PORTB_PIN3_INITIAL_VAL      FLOATING
#define PORTB_PIN4_INITIAL_VAL      FLOATING
#define PORTB_PIN5_INITIAL_VAL      FLOATING
#define PORTB_PIN6_INITIAL_VAL      FLOATING
#define PORTB_PIN7_INITIAL_VAL      FLOATING

//PORTC
#define PORTC_PIN0_INITIAL_VAL      FLOATING
#define PORTC_PIN1_INITIAL_VAL      FLOATING
#define PORTC_PIN2_INITIAL_VAL      FLOATING
#define PORTC_PIN3_INITIAL_VAL      FLOATING
#define PORTC_PIN4_INITIAL_VAL      FLOATING
#define PORTC_PIN5_INITIAL_VAL      FLOATING
#define PORTC_PIN6_INITIAL_VAL      FLOATING
#define PORTC_PIN7_INITIAL_VAL      FLOATING

//PORTD
#define PORTD_PIN0_INITIAL_VAL      LOW
#define PORTD_PIN1_INITIAL_VAL      LOW
#define PORTD_PIN2_INITIAL_VAL      LOW
#define PORTD_PIN3_INITIAL_VAL      LOW
#define PORTD_PIN4_INITIAL_VAL      FLOATING
#define PORTD_PIN5_INITIAL_VAL      FLOATING
#define PORTD_PIN6_INITIAL_VAL      FLOATING
#define PORTD_PIN7_INITIAL_VAL      FLOATING

#endif /* PORT_CFG_H_ */
