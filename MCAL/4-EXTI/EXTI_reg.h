/**
 * @file EXTI_reg.h
 * @author Abdelrahman Kamal (abdelrahman.k212@gmail.com)
 * @brief Register definition for External Interrupt Driver
 * @version 0.1
 * @date 2023-06-07
 */
#ifndef EXTI_REG_H_
#define EXTI_REG_H_

/** @brief GICR-> General Interrupt Control Register
 *  @details to unable/disable the external interrupt sources INT1,INT0,INT2 */
#define GICR_REG        *((volatile uint8*) 0x5B)

#define GICR_INT1       7U  /** @brief INT1 Control Bit */
#define GICR_INT0       6U  /** @brief INT0 Control Bit */
#define GICR_INT2       5U  /** @brief INT2 Control Bit */

/** @brief MCUCR-> MCU Control Register
 *  @details used to configure the interrupt sense control for INT1 & INT0 */
#define MCUCR_REG       *((volatile uint8*) 0x55)

#define MCUCR_ISC00     0U  /** @brief INT0 sense control bit0 */
#define MCUCR_ISC01     1U  /** @brief INT0 sense control bit1 */
#define MCUCR_ISC10     2U  /** @brief INT1 sense control bit0 */
#define MCUCR_ISC11     3U  /** @brief INT1 sense control bit1 */

/** @brief MCUCSR-> General Interrupt Control & Status Register
 *  @details used to configure the interrupt sense control for INT2 */
#define MCUCSR_REG      *((volatile uint8*) 0x54)

#define MCUCSR_ISC2     6U  /** @brief INT2 sense control */
#endif /* EXTI_REG_H_ */
