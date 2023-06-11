/***************************************************************************************************/
/****************             Author: Abdelrahman Kamal Eldean                 *********************/
/****************             File: LCD_cfg.h                                  *********************/
/****************             Version: 1.00                                    *********************/
/***************************************************************************************************/

#ifndef LCD_PRV_H_
#define LCD_PRV_H_

static void LCD_vSendEnablePulse(void);
static void LCD_vSend4BitData(uint8 Copy_u8Nipple);

#define FOUR_BIT_MODE   1U
#define EIGHT_BIT_MODE  2U

#define ENABLED		1U
#define DISABLED	2U
#endif
