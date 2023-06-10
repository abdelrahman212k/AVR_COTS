/**
 * @file EXTI_prog.c
 * @author Abdelrahman Kamal (abdelrahman.k212@gmail.com)
 * @brief This file implements the EXTI module functions
 * @version 0.1
 * @date 2023-06-08
 */
#include "STD_TYPES.h"
#include "DEFINES.h"
#include "ERROR_STATES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "EXTI_reg.h"
#include "EXTI_interface.h"
#include "EXTI_cfg.h"
#include "EXTI_prv.h"

/* Array of pointers to function to hold the ISR callback functions addresses */
static void (*EXTI_pfINTFuncPtr[3])(void) = {NULL};

void EXTI_vInit(void)
{
/* Implement INT0 sense control configurations */
#if INT0_SENSE_CTRL == EXTI_u8LOW_LEVEL
    CLR_BIT(MCUCR_REG, MCUCR_ISC00);
    CLR_BIT(MCUCR_REG, MCUCR_ISC01);
#elif INT0_SENSE_CTRL == EXTI_u8ON_CHANGE
    SET_BIT(MCUCR_REG, MCUCR_ISC00);
    CLR_BIT(MCUCR_REG, MCUCR_ISC01);
#elif INT0_SENSE_CTRL == EXTI_u8FALLING_EDGE
    CLR_BIT(MCUCR_REG, MCUCR_ISC00);
    SET_BIT(MCUCR_REG, MCUCR_ISC01);
#elif INT0_SENSE_CTRL == EXTI_u8RISING_EDGE
    SET_BIT(MCUCR_REG, MCUCR_ISC00);
    SET_BIT(MCUCR_REG, MCUCR_ISC01);
#else
#error wrong INT0_SENSE_CTRL configuration option
#endif

#if INT0_INITIAL_STATE == ENABLED
    SET_BIT(GICR_REG, GICR_INT0);
#elif INT0_INITIAL_STATE == DISABLED
    CLR_BIT(GICR_REG, GICR_INT0);
#else
#error Wrong INT0_INITIAL_STATE configuration option
#endif


/* Implement INT1 sense control configurations */
#if INT1_SENSE_CTRL == EXTI_u8LOW_LEVEL
    CLR_BIT(MCUCR_REG, MCUCR_ISC10);
    CLR_BIT(MCUCR_REG, MCUCR_ISC11);
#elif INT1_SENSE_CTRL == EXTI_u8ON_CHANGE
    SET_BIT(MCUCR_REG, MCUCR_ISC10);
    CLR_BIT(MCUCR_REG, MCUCR_ISC11);
#elif INT1_SENSE_CTRL == EXTI_u8FALLING_EDGE
    CLR_BIT(MCUCR_REG, MCUCR_ISC10);
    SET_BIT(MCUCR_REG, MCUCR_ISC11);
#elif INT1_SENSE_CTRL == EXTI_u8RISING_EDGE
    SET_BIT(MCUCR_REG, MCUCR_ISC10);
    SET_BIT(MCUCR_REG, MCUCR_ISC11);
#else
#error wrong INT1_SENSE_CTRL configuration option
#endif

#if INT1_INITIAL_STATE == ENABLED
    SET_BIT(GICR_REG, GICR_INT1);
#elif INT1_INITIAL_STATE == DISABLED
    CLR_BIT(GICR_REG, GICR_INT1);
#else
#error Wrong INT1_INITIAL_STATE configuration option
#endif


/* Implement INT2 sense control configurations */
#if INT2_SENSE_CTRL == EXTI_u8FALLING_EDGE
    CLR_BIT(MCUCSR_REG, MCUCSR_ISC2);
#elif INT2_SENSE_CTRL == EXTI_u8RISING_EDGE
    SET_BIT(MCUCSR_REG, MCUCSR_ISC2);
#else
#error wrong INT2_SENSE_CTRL configuration option
#endif

#if INT2_INITIAL_STATE == ENABLED
    SET_BIT(GICR_REG, GICR_INT2);
#elif INT2_INITIAL_STATE == DISABLED
    CLR_BIT(GICR_REG, GICR_INT2);
#else
#error Wrong INT2_INITIAL_STATE configuration option
#endif
}

uint8 EXTI_u8SetSenseControl(uint8 Copy_u8InterruptNum, uint8 Copy_u8Sense)
{
    uint8 Local_u8ErrorState = OK;
    switch (Copy_u8InterruptNum)
    {
        case EXTI_u8INT0:
            switch (Copy_u8Sense)
            {
                case EXTI_u8LOW_LEVEL:
                    CLR_BIT(MCUCR_REG, MCUCR_ISC00);
                    CLR_BIT(MCUCR_REG, MCUCR_ISC01);
                    break;
                case EXTI_u8ON_CHANGE:
                    SET_BIT(MCUCR_REG, MCUCR_ISC00);
                    CLR_BIT(MCUCR_REG, MCUCR_ISC01);
                    break;
                case EXTI_u8FALLING_EDGE:
                    CLR_BIT(MCUCR_REG, MCUCR_ISC00);
                    SET_BIT(MCUCR_REG, MCUCR_ISC01);
                    break;
                case EXTI_u8RISING_EDGE:
                    SET_BIT(MCUCR_REG, MCUCR_ISC00);
                    SET_BIT(MCUCR_REG, MCUCR_ISC01);
                    break;
                default: Local_u8ErrorState = NOK; break;
            }
            break;
        case EXTI_u8INT1:
            switch (Copy_u8Sense)
            {
                case EXTI_u8LOW_LEVEL:
                    CLR_BIT(MCUCR_REG, MCUCR_ISC10);
                    CLR_BIT(MCUCR_REG, MCUCR_ISC11);
                    break;
                case EXTI_u8ON_CHANGE:
                    SET_BIT(MCUCR_REG, MCUCR_ISC10);
                    CLR_BIT(MCUCR_REG, MCUCR_ISC11);
                    break;
                case EXTI_u8FALLING_EDGE:
                    CLR_BIT(MCUCR_REG, MCUCR_ISC10);
                    SET_BIT(MCUCR_REG, MCUCR_ISC11);
                    break;
                case EXTI_u8RISING_EDGE:
                    SET_BIT(MCUCR_REG, MCUCR_ISC10);
                    SET_BIT(MCUCR_REG, MCUCR_ISC11);
                    break;
                default: Local_u8ErrorState = NOK; break;
            }
            break;
        case EXTI_u8INT2:
            switch (Copy_u8Sense)
            {
                case EXTI_u8FALLING_EDGE: CLR_BIT(MCUCSR_REG, MCUCSR_ISC2); break;
                case EXTI_u8RISING_EDGE:  SET_BIT(MCUCSR_REG, MCUCSR_ISC2); break;
                default: Local_u8ErrorState = NOK;                          break;
            }
            break;
        default: Local_u8ErrorState = NOK; break;
    }
    return Local_u8ErrorState;
}

uint8 EXTI_u8EnableInterrupt(uint8 Copy_u8InterruptNum)
{
    uint8 Local_u8ErrorState = OK;
    switch (Copy_u8InterruptNum)
    {
        case EXTI_u8INT0: SET_BIT(GICR_REG, GICR_INT0); break;
        case EXTI_u8INT1: SET_BIT(GICR_REG, GICR_INT1); break;
        case EXTI_u8INT2: SET_BIT(GICR_REG, GICR_INT2); break;
        default: Local_u8ErrorState = NOK; break;
    }
    return Local_u8ErrorState;
}

uint8 EXTI_u8DisableInterrupt(uint8 Copy_u8InterruptNum)
{
    uint8 Local_u8ErrorState = OK;
    switch (Copy_u8InterruptNum)
    {
        case EXTI_u8INT0: CLR_BIT(GICR_REG, GICR_INT0); break;
        case EXTI_u8INT1: CLR_BIT(GICR_REG, GICR_INT1); break;
        case EXTI_u8INT2: CLR_BIT(GICR_REG, GICR_INT2); break;
        default: Local_u8ErrorState = NOK; break;
    }
    return Local_u8ErrorState;
}

uint8 EXTI_u8SetCallBack(uint8 Copy_u8InterruptNum, void (*Copy_pfFuncPtr)(void))
{
	uint8 Local_u8ErrorState = OK;
	if(Copy_pfFuncPtr != NULL)
	{
		EXTI_pfINTFuncPtr[Copy_u8InterruptNum] = Copy_pfFuncPtr;
	}
	else
	{
		Local_u8ErrorState = NULL_PTR_ERR;
	}
	return Local_u8ErrorState;
}

/**
 * @brief INT0 ISR
 */
void __vector_1(void) __attribute__((signal));
void __vector_1(void)
{
	if(EXTI_pfINTFuncPtr[EXTI_u8INT0] != NULL)
	{
		EXTI_pfINTFuncPtr[EXTI_u8INT0]();
	}
}

/**
 * @brief INT1 ISR
 */
void __vector_2(void) __attribute__((signal));
void __vector_2(void)
{
	if(EXTI_pfINTFuncPtr[EXTI_u8INT1] != NULL)
	{
		EXTI_pfINTFuncPtr[EXTI_u8INT1]();
	}
}


/**
 * @brief INT2 ISR
 */
void __vector_3(void) __attribute__((signal));
void __vector_3(void)
{
	if(EXTI_pfINTFuncPtr[EXTI_u8INT2] != NULL)
	{
		EXTI_pfINTFuncPtr[EXTI_u8INT2]();
	}
}
