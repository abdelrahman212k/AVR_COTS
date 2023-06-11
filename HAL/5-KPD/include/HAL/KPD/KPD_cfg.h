/**
 *@file KPD_cfg.h
 * @author Abdelrahman Kamal
 * @brief 
 * @version 0.1
 * @date 2023-05-23
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef KPD_CFG_H_
#define KPD_CFG_H_

#define KPD_u8ROW_NUM      4
#define KPD_u8COL_NUM      4

// Configure rows
#define KPD_u8ROW_PORT      DIO_u8PORTD

#define KPD_u8ROW1_PIN      DIO_u8PIN4
#define KPD_u8ROW2_PIN      DIO_u8PIN5
#define KPD_u8ROW3_PIN      DIO_u8PIN6
#define KPD_u8ROW4_PIN      DIO_u8PIN7

// Configure columns
#define KPD_u8COL_PORT      DIO_u8PORTD

#define KPD_u8COL1_PIN      DIO_u8PIN3
#define KPD_u8COL2_PIN      DIO_u8PIN2
#define KPD_u8COL3_PIN      DIO_u8PIN1
#define KPD_u8COL4_PIN      DIO_u8PIN0

#define KPD_u8BUTTON_ARR    {{'7', '8', '9', '+'}, {'4','5','6','-'}, {'1','2','3','*'}, {'.','0','=','/'}}

#define KPD_u8NO_PRESSED_KEY    0XFF
#endif /* KPD_CFG_H_ */
