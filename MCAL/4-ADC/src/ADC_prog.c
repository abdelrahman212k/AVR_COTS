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

#if ADC_u8RESOLUTION == TEN_BITS
static uint16* ADC_pu16ConversionResult = NULL;
#elif ADC_u8RESOLUTION == EIGHT_BITS
static uint8* ADC_pu16ConversionResult = NULL;
#endif

static void (*ADC_pvfNotificationFunc)(void) = NULL;
static uint8 ADC_u8BusyFlag = IDLE;

static ADC_CHAIN_t* ADC_strChainConversionAsync = {NULL};
static sint8 ADC_s8ChainCounter = -1;

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


uint8 ADC_u8StartConversionSync(ADC_CHANNEL_t Copy_u8Channel, uint16* Copy_pu16Result)
{
	uint8 Local_u8ErrorState = OK;

	if(Copy_pu16Result != NULL)
	{
		/* Checking ADC state */
		if( ADC_u8BusyFlag == IDLE)
		{
			uint32 Local_u32TimeoutCounter = 0u;

			/* ADC is now busy */
			ADC_u8BusyFlag = BUSY;

			/* Configure channel selected */
			CLR_BITS(ADMUX_REG, CHANNEL_MASK);
			SET_BITS(ADMUX_REG, Copy_u8Channel);

			/* Start conversion */
			SET_BIT(ADCSRA_REG, ADCSRA_ADSC);

			/* Wait until conversion is complete */
			while ((GET_BIT(ADCSRA_REG, ADCSRA_ADIF) == 0) && (Local_u32TimeoutCounter < ADC_u32TIMEOUT_VALUE))
			{
				Local_u32TimeoutCounter++;
			}
			if(Local_u32TimeoutCounter >= ADC_u32TIMEOUT_VALUE)
			{
				/* flag isn't raised before timeout is passed */
				Local_u8ErrorState = TIMEOUT_ERR;
			}
			else
			{
				/* flag is raised before timeout is passed */
				/* Clear conversion complete flag manually by writing 1 to it */
				SET_BIT(ADCSRA_REG, ADCSRA_ADIF);

				/* Returning the digital value after conversion */
#if ADC_u8RESOLUTION == EIGHT_BITS
				*Copy_pu16Result = ADCH_REG;
#elif ADC_u8RESOLUTION == TEN_BITS
				*Copy_pu16Result = ADC_DATA_REG;
#endif

				/* returning ADC to IDLE state */
				ADC_u8BusyFlag = IDLE;
			}
		}
		else
		{
			Local_u8ErrorState = BUSY_STATE_ERR;
		}
	}
	else
	{
		Local_u8ErrorState = NULL_PTR_ERR;
	}

	return Local_u8ErrorState;
}


uint8 ADC_u8StartConversionAsync(ADC_CHANNEL_t Copy_u8Channel, uint16* Copy_pu16Result, void(*Copy_pvfNotificationFunc)(void))
{
	uint8 Local_u8ErrorState = OK;

	if((Copy_pu16Result != NULL) && (Copy_pvfNotificationFunc != NULL))
	{
		/* Checking ADC state */
		if (ADC_u8BusyFlag == IDLE)
		{
			/* ADC is now BUSY */
			ADC_u8BusyFlag = BUSY;

			/* Assign the Conversion Result global pointer */
			ADC_pu16ConversionResult = Copy_pu16Result;

			/* Assign the Notification Function global pointer to function */
			ADC_pvfNotificationFunc = Copy_pvfNotificationFunc;

			/* Configure channel selected */
			CLR_BITS(ADMUX_REG, CHANNEL_MASK);
			SET_BITS(ADMUX_REG, Copy_u8Channel);

			/* Enable ADC conversion complete interrupt */
			SET_BIT(ADCSRA_REG, ADCSRA_ADIE);

			/* Start conversion */
			SET_BIT(ADCSRA_REG, ADCSRA_ADSC);
		}
	}
	else
	{
		Local_u8ErrorState = NULL_PTR_ERR;
	}
	return Local_u8ErrorState;
}


uint8 ADC_u8StartChainConversionAsync(ADC_CHAIN_t* Copy_strChain)
{
	uint8 Local_u8ErrorState = OK;
	if(Copy_strChain != NULL)
	{
		/* Checking ADC state */
		if (ADC_u8BusyFlag == IDLE)
		{
			/* ADC is now BUSY */
			ADC_u8BusyFlag = BUSY;

			/* Check if this is the first entry of the function to tell the ISR to perform Chain Conversions */
			if(ADC_s8ChainCounter == -1)
			{
				ADC_s8ChainCounter = 0;
			}

			/* Assigning the local pointer to struct to our global struct to be accessible by ISR */
			ADC_strChainConversionAsync = Copy_strChain;

			/* Configure channel selected */
			CLR_BITS(ADMUX_REG, CHANNEL_MASK);
			SET_BITS(ADMUX_REG, ADC_strChainConversionAsync -> ChannelArray[ADC_s8ChainCounter]);

			/* Enable ADC conversion complete interrupt */
			SET_BIT(ADCSRA_REG, ADCSRA_ADIE);

			/* Start conversion */
			SET_BIT(ADCSRA_REG, ADCSRA_ADSC);
		}
		else
		{
			Local_u8ErrorState = BUSY_STATE_ERR;
		}
	}
	else
	{
		Local_u8ErrorState = NULL_PTR_ERR;
	}
	return Local_u8ErrorState;
}


/**
 * @brief ADC conversion complete ISR
 */
void __vector_16(void) __attribute__((signal));
void __vector_16(void)
{
	/* Checking for chain conversion */
	if(ADC_s8ChainCounter == -1)
	{
		/************************************* Single Conversion *************************************/
		if(ADC_pu16ConversionResult != NULL)
		{
			/* Returning the digital value after conversion */
#if ADC_u8RESOLUTION == EIGHT_BITS
			*ADC_pu16ConversionResult = ADCH_REG;
#elif ADC_u8RESOLUTION == TEN_BITS
			*ADC_pu16ConversionResult = ADC_DATA_REG;
#endif

			/* Disable ADC conversion complete interrupt */
			CLR_BIT(ADCSRA_REG, ADCSRA_ADIE);

			/* ADC finished conversion & now in IDLE state */
			ADC_u8BusyFlag = IDLE;

			/* Invoke notification function */
			if(ADC_pvfNotificationFunc != NULL)
			{
				ADC_pvfNotificationFunc();
			}
			else
			{
				/* Notification function pointer = NULL */
			}
		}
		else
		{
			/* Conversion result pointer = NULL */
		}
	}
	else
	{
		/************************************* Chain Conversion *************************************/
		if(ADC_strChainConversionAsync != NULL)
		{
			/* Returning the digital value after conversion */
#if ADC_u8RESOLUTION == EIGHT_BITS
			ADC_strChainConversionAsync -> ChannelArray[ADC_s8ChainCounter] = ADCH_REG;
#elif ADC_u8RESOLUTION == TEN_BITS
			ADC_strChainConversionAsync -> ChannelArray[ADC_s8ChainCounter] = ADC_DATA_REG;
#endif
			/* Disable ADC conversion complete interrupt */
			CLR_BIT(ADCSRA_REG, ADCSRA_ADIE);

			/* ADC finished conversion & now in IDLE state */
			ADC_u8BusyFlag = IDLE;

			/* incrementing the chain counter */
			ADC_s8ChainCounter++;

			/* Checking if there are conversions left */
			if((ADC_strChainConversionAsync -> ChainSize) > ADC_s8ChainCounter) /* still some conversions left */
			{
				/* Calling ADC_u8StartChainConversionAsync to continue the chain conversions */
				ADC_u8StartChainConversionAsync(ADC_strChainConversionAsync);
			}
			else /* Conversions are done */
			{
				/* Returning Conversion flag to its initial state */
				ADC_s8ChainCounter = -1;

				/* Invoke notification function */
				if((ADC_strChainConversionAsync -> ADC_pvfNotificationFunc) != NULL)
				{
					ADC_strChainConversionAsync -> ADC_pvfNotificationFunc();
				}
				else
				{
					/* Notification function pointer = NULL */
				}
			}
		}
		else
		{
			/* Chain Conversion Global Struct = NULL */
		}
	}
}
