/**
 *@file EXTI_interface.h
 * @author Abdelrahman Kamal (abdelrahman.k212@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-06-08
 */
#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_

#define EXTI_u8INT0     0U
#define EXTI_u8INT1     1U
#define EXTI_u8INT2     2U

#define EXTI_u8LOW_LEVEL        1U
#define EXTI_u8ON_CHANGE        2U
#define EXTI_u8FALLING_EDGE     3U
#define EXTI_u8RISING_EDGE      4U

void EXTI_vInit(void);
uint8 EXTI_u8SetSenseControl(uint8 Copy_u8InterruptNum, uint8 Copy_u8Sense);
uint8 EXTI_u8InterruptEnable(uint8 Copy_u8InterruptNum);
uint8 EXTI_u8InterruptDisable(uint8 Copy_u8InterruptNum);
uint8 EXTI_u8SetCallBack(uint8 Copy_u8InterruptNum, void (*Copy_pfFuncPtr)(void));

#endif /* EXTI_INTERFACE_H_ */
