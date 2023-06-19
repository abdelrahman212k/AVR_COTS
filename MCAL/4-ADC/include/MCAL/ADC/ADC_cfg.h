/**
 * @file ADC_cfg.h
 * @author Abdelrahman Kamal (abdelrahman.k212@gmail.com)
 * @brief configuration file for ADC peripheral
 * @version 0.1
 * @date 2023-06-13
 */
#ifndef ADC_CFG_H_
#define ADC_CFG_H_

/**
 * @brief configure the reference voltage for ADC
 * @details options:    1- AREF_REF
 *                      2- AVCC_REF
 *                      3- INTERNAL_2560mV_REF
 */
#define ADC_u8REF_VOLT      AVCC_REF

/**
 * @brief select the desired resolution to operate ADC on
 * @details options:    1- EIGHT_BITS
 *                      2- TEN_BITS
 */
#define ADC_u8RESOLUTION    EIGHT_BITS

/**
 * @brief configure auto trigger
 * @details options:    1- ENABLED
 *                      2- DISABLED
 */
#define ADC_u8AUTO_TRIGGER  DISABLED

#if ADC_u8AUTO_TRIGGER == ENABLED
/**
 * @brief configure auto trigger source
 * @details options:    1- FREE_RUNNING
 *                      2- ANALOG_COMPARATOR
 *                      3- EXTI_INT0
 *                      4- TMR0_COMPARE_MATCH
 *                      5- TMR0_OVER_FLOW
 *                      6- TMR1_COMPARE_MATCH_B
 *                      7- TMR1_OVER_FLOW
 *                      8- TMR1_CAPTURE_EVENT
 */
#define ADC_u8AUTO_TRIGGER_SOURCE  EXTI_INT0
#endif

/**
 * @brief configure if the ADC PIE is on or off
 * @details options:    1- ENABLED
 *                      2- DISABLED
 */
#define ADC_u8INTERRUPT     DISABLED

/**
 * @brief configure the value of prescaler for ADC clk
 * @details options:    1- DIVISION_BY_2
 *                      2- DIVISION_BY_4
 *                      3- DIVISION_BY_8
 *                      4- DIVISION_BY_16
 *                      5- DIVISION_BY_32
 *                      6- DIVISION_BY_64
 *                      7- DIVISION_BY_128
 */
#define ADC_u8PRESCALER_VALUE       DIVISION_BY_128

/**
 * @brief configure the value of time out when using ADC_u8StartConversionSynch
 */
#define ADC_u32TIMEOUT_VALUE		50000U

#endif /* ADC_CFG_H_ */
