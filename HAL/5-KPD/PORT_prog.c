/**
 *@file PORT_prog.c
 * @author Abdelrahman Kamal
 * @brief 
 * @version 0.1
 * @date 2023-05-22
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "STD_TYPES.h"
#include "PORT_reg.h"
#include "PORT_cfg.h"
#include "PORT_prv.h"
#include "PORT_interface.h"

void PORT_vInit(void)
{
    DDRA_REG = PORTA_DIR;
    DDRB_REG = PORTB_DIR;
    DDRC_REG = PORTC_DIR;
    DDRD_REG = PORTD_DIR;

    PORTA_REG = PORTA_INITIAL_VAL;
    PORTB_REG = PORTB_INITIAL_VAL;
    PORTC_REG = PORTC_INITIAL_VAL;
    PORTD_REG = PORTD_INITIAL_VAL;
}