/**
 * @file ADC_prv.h
 * @author Abdelrahman Kamal (abdelrahman.k212@gmail.com)
 * @brief private macros definitions for ADC peripheral
 * @version 0.1
 * @date 2023-06-13
 */
#ifndef ADC_PRV_H_
#define ADC_PRV_H_

/* Reference voltage options */
#define AREF_REF                1U
#define AVCC_REF                2U
#define INTERNAL_2560mV_REF     3U

/* ADC resolution options */
#define EIGHT_BITS              1U
#define TEN_BITS                2U

/* ADC prescaler values */
#define DIVISION_BY_2       1U
#define DIVISION_BY_4       2U
#define DIVISION_BY_8       3U
#define DIVISION_BY_16      4U
#define DIVISION_BY_32      5U
#define DIVISION_BY_64      6U
#define DIVISION_BY_128     7U

#define AUTO_TRIGGER_MASK   0b11100000
#define PRESCALER_MASK      0b00000111
#define CHANNEL_MASK        0b00011111

#endif /* ADC_PRV_H_ */
