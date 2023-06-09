/**
 * @file EXTI_cfg.h
 * @author Abdelrahman Kamal (abdelrahman.k212@gmail.com)
 * @brief This file configures the EXTI module in pre-built configuration method
 * @version 0.1
 * @date 2023-06-08
 */
#ifndef EXTI_CFG_H_
#define EXTI_CFG_H_

/**
 * @details Configure INT0 Sense control, options:  1- EXTI_u8LOW_LEVEL
                                                    2- EXTI_u8ON_CHANGE
                                                    3- EXTI_u8FALLING_EDGE
                                                    4- EXTI_u8RISING_EDGE
 */
#define INT0_SENSE_CTRL     EXTI_u8FALLING_EDGE
/**
 *@details Configure the initial state for INT0, options:  1- ENABLED
                                                            2- DISABLED
 */
#define INT0_INITIAL_STATE      ENABLED


/**
 * @details Configure INT1 Sense control, options:  1- EXTI_u8LOW_LEVEL
                                                    2- EXTI_u8ON_CHANGE
                                                    3- EXTI_u8FALLING_EDGE
                                                    4- EXTI_u8RISING_EDGE
  */
#define INT1_SENSE_CTRL     EXTI_u8FALLING_EDGE
/**
 *@details Configure the initial state for INT1, options:   1- ENABLED
                                                            2- DISABLED
   */
#define INT1_INITIAL_STATE      ENABLED


/**
 * @details Configure INT2 Sense control, options:  1- EXTI_u8FALLING_EDGE
                                                    2- EXTI_u8RISING_EDGE
  */
#define INT2_SENSE_CTRL     EXTI_u8FALLING_EDGE
/**
 *@details Configure the initial state for INT2, options:   1- ENABLED
                                                            2- DISABLED
  */
#define INT2_INITIAL_STATE      DISABLED

#endif /* EXTI_CFG_H_ */
