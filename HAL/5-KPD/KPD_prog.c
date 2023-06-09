/**
 *@file KPD_prog.c
 * @author Abdelrahman Kamal
 * @brief 
 * @version 0.1
 * @date 2023-05-23
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "STD_TYPES.h"
#include "ERROR_STATES.h"

#include "DIO_interface.h"

#include "KPD_cfg.h"
#include "KPD_interface.h"
#include "KPD_prv.h"

/* Required: All row pins are input pullup, all column pins are output high */
uint8 KPD_u8GetPressedKey(void)
{
    uint8 Local_u8PressedKey = KPD_u8NO_PRESSED_KEY;
    uint8 Local_u8KeyState, Local_u8RowCounter, Local_u8ColCounter;
    static uint8 Local_u8ColArr[KPD_u8COL_NUM] ={KPD_u8COL1_PIN, KPD_u8COL2_PIN, KPD_u8COL3_PIN, KPD_u8COL4_PIN};
    static uint8 Local_u8RowArr[KPD_u8ROW_NUM] ={KPD_u8ROW1_PIN, KPD_u8ROW2_PIN, KPD_u8ROW3_PIN, KPD_u8ROW4_PIN};
    static uint8 Local_u8KPDArr[KPD_u8ROW_NUM][KPD_u8COL_NUM] = KPD_u8BUTTON_ARR;
    /* Activate columns pins and read the rows */
    for (Local_u8ColCounter = 0; Local_u8ColCounter < KPD_u8COL_NUM; Local_u8ColCounter++)
    {
        /* Change the value of the column to low */
        DIO_u8SetPinValue(KPD_u8COL_PORT, Local_u8ColArr[Local_u8ColCounter], DIO_u8PIN_LOW);
        
        /* Read the rows to know which button is pressed */
        for (Local_u8RowCounter = 0; Local_u8RowCounter < KPD_u8ROW_NUM; Local_u8RowCounter++)
        {
            /* Read the current row */
            DIO_u8GetPinValue(KPD_u8ROW_PORT, Local_u8RowArr[Local_u8RowCounter], &Local_u8KeyState);
            
            /* If the current row is low -> key is pressed */
            if (Local_u8KeyState == DIO_u8PIN_LOW)
            {
                /* Get pressed key value */
                Local_u8PressedKey = Local_u8KPDArr[Local_u8RowCounter][Local_u8ColCounter];
                
                /* Wait until the button is released */
                while (Local_u8KeyState == DIO_u8PIN_LOW)
                {
                    DIO_u8GetPinValue(KPD_u8ROW_PORT, Local_u8RowArr[Local_u8RowCounter], &Local_u8KeyState);
                }
                
                return Local_u8PressedKey;
            }
        }
        DIO_u8SetPinValue(KPD_u8COL_PORT, Local_u8ColArr[Local_u8ColCounter], DIO_u8PIN_HIGH);
    }
    return Local_u8PressedKey;
}
