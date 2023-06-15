/**
 * @file ADC_prog.c
 * @author Abdelrahman Kamal (abdelrahman.k212@gmail.com)
 * @brief functions implementation for ADC peripheral
 * @version 0.1
 * @date 2023-06-13
 */
/********************  LIB includes  ********************/
#include "../include/LIB/STD_TYPES.h"
#include "../include/LIB/DEFINES.h"
#include "../include/LIB/BIT_MATH.h"
#include "../include/LIB/ERROR_STATES.h"

/********************  MCAL includes  ********************/
#include "../include/MCAL/ADC/ADC_reg.h"
#include "../include/MCAL/ADC/ADC_prv.h"
#include "../include/MCAL/ADC/ADC_cfg.h"
#include "../include/MCAL/ADC/ADC_interface.h"


void ADC_vInit(void)
{
    /* Implementing voltage reference configuration */
#if ADC_u8REF_VOLT == AREF_REF
    CLR_BIT(ADMUX_REG, ADMUX_REFS0);
    CLR_BIT(ADMUX_REG, ADMUX_REFS1);
#elif ADC_u8REF_VOLT == AVCC_REF
    SET_BIT(ADMUX_REG, ADMUX_REFS0);
    CLR_BIT(ADMUX_REG, ADMUX_REFS1);
#elif ADC_u8REF_VOLT == INTERNAL_2560mV_REF
    SET_BIT(ADMUX_REG, ADMUX_REFS0);
    SET_BIT(ADMUX_REG, ADMUX_REFS1);
#else
#error Wrong ADC_u8REF_VOLT configuration option
#endif

    /* Left adjust or right adjust depending on resolution */
#if ADC_u8RESOLUTION == EIGHT_BITS
    SET_BIT(ADMUX_REG, ADMUX_ADLAR);
#elif ADC_u8RESOLUTION == TEN_BITS
    CLR_BIT(ADMUX_REG, ADMUX_ADLAR);
#else 
#error Wrong ADC_u8RESOLUTION configuration option
#endif

    /* Auto Trigger Enable */
#if ADC_u8AUTO_TRIGGER == ENABLED
    SET_BIT(ADCSRA_REG, ADCSRA_ADATE);
    
    /* Auto Trigger Source Configuration */
    CLR_BITS(SFIOR_REG, AUTO_TRIGGER_MASK);
    SET_BITS(SFIOR_REG, ADC_u8AUTO_TRIGGER_SOURCE);
#elif ADC_u8AUTO_TRIGGER == DISABLED
    CLR_BIT(ADCSRA_REG, ADCSRA_ADATE);
#else
#error Wrong ADC_u8AUTO_TRIGGER configuration option
#endif

    /* ADC Interrupt */
#if ADC_u8INTERRUPT == ENABLED
    SET_BIT(ADCSRA_REG, ADCSRA_ADIE);
#elif ADC_u8INTERRUPT == DISABLED
    CLR_BIT(ADCSRA_REG, ADCSRA_ADIE);
#else 
#error Wrong ADC_u8INTERRUPT configuration option
#endif

    /* Configure prescaler bits */
    CLR_BITS(ADCSRA_REG, PRESCALER_MASK);
    SET_BITS(ADCSRA_REG, ADC_u8PRESCALER_VALUE);

    /* ADC enable */
    SET_BIT(ADCSRA_REG, ADCSRA_ADEN);
}


uint16 ADC_u16GetChannelReading(ADC_CHANNEL_t Copy_u8Channel)
{
    /* Configure channel selected */
    CLR_BITS(ADMUX_REG, CHANNEL_MASK);
    SET_BITS(ADMUX_REG, Copy_u8Channel);

    /* Start conversion */
    SET_BIT(ADCSRA_REG, ADCSRA_ADSC);

    /* Wait until conversion is complete */
    while (GET_BIT(ADCSRA_REG, ADCSRA_ADIF) == 0);

    /* Clear conversion complete flag manually by writing 1 to it */
    SET_BIT(ADCSRA_REG, ADCSRA_ADIF);

    /* Returning the digital value after conversion */
#if ADC_u8RESOLUTION == EIGHT_BITS
    return ADCH_REG;
#elif ADC_u8RESOLUTION == TEN_BITS
    return ADC_DATA_REG;
#endif
}
