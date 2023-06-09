#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DEFINES.h"
#include "ERROR_STATES.h"

#include "DIO_reg.h"
#include "DIO_prv.h"
#include "DIO_interface.h"
#include "DIO_cfg.h"

uint8 DIO_u8SetPortDirection (uint8 Copy_u8Port, uint8 Copy_u8Direction)
{
    uint8 Local_u8ErrorState = OK;
    switch (Copy_u8Port)
    {
        case DIO_u8PORTA: DDRA_REG = Copy_u8Direction; break;
        case DIO_u8PORTB: DDRB_REG = Copy_u8Direction; break;
        case DIO_u8PORTC: DDRC_REG = Copy_u8Direction; break;
        case DIO_u8PORTD: DDRD_REG = Copy_u8Direction; break;
        default: Local_u8ErrorState = NOK;             break; //PORT out of range
    }
    return Local_u8ErrorState;
}

uint8 DIO_u8SetPortValue (uint8 Copy_u8Port, uint8 Copy_u8Value)
{
    uint8 Local_u8ErrorState = OK;
    switch (Copy_u8Port)
    {
        case DIO_u8PORTA: PORTA_REG = Copy_u8Value; break;
        case DIO_u8PORTB: PORTB_REG = Copy_u8Value; break;
        case DIO_u8PORTC: PORTC_REG = Copy_u8Value; break;
        case DIO_u8PORTD: PORTD_REG = Copy_u8Value; break;
        default: Local_u8ErrorState = NOK;          break; //PORT out of range
    }
    return Local_u8ErrorState;
}

uint8 DIO_u8TogglePortValue(uint8 Copy_u8Port)
{
    uint8 Local_u8ErrorState = OK;
    switch (Copy_u8Port)
    {
        // you can also toggle the REG using this method: PORT ^= OxFF
        case DIO_u8PORTA: PORTA_REG = ~PORTA_REG; break;
        case DIO_u8PORTB: PORTB_REG = ~PORTB_REG; break;
        case DIO_u8PORTC: PORTC_REG = ~PORTC_REG; break;
        case DIO_u8PORTD: PORTD_REG = ~PORTD_REG; break;
        default: Local_u8ErrorState = NOK;        break;//PORT out of range
    }
    return Local_u8ErrorState;
}

uint8 DIO_u8GetPortVal (uint8 Copy_u8Port, uint8* Copy_pu8Value)
{
    uint8 Local_u8ErrorState = OK;
    if (Copy_pu8Value != NULL)
    {
        switch (Copy_u8Port)
        {
            case DIO_u8PORTA: *Copy_pu8Value = PINA_REG; break;
            case DIO_u8PORTB: *Copy_pu8Value = PINB_REG; break;
            case DIO_u8PORTC: *Copy_pu8Value = PINC_REG; break;
            case DIO_u8PORTD: *Copy_pu8Value = PIND_REG; break;
            default: Local_u8ErrorState = NOK;        break;//PORT out of range
        }
    }
    else
    {
        Local_u8ErrorState = NULL_PTR_ERR;
    }
    return Local_u8ErrorState;
}

uint8 DIO_u8SetPinDirection (uint8 Copy_u8Port, uint8 Copy_u8Pin, uint8 Copy_u8Direction)
{
    uint8 Local_u8ErrorState = OK;
    if (Copy_u8Pin <= DIO_u8PIN7)
    {
        if (Copy_u8Direction == DIO_u8PIN_INPUT)
        {
            switch (Copy_u8Port)
            {
                case DIO_u8PORTA: CLR_BIT(DDRA_REG, Copy_u8Pin); break;
                case DIO_u8PORTB: CLR_BIT(DDRB_REG, Copy_u8Pin); break;
                case DIO_u8PORTC: CLR_BIT(DDRC_REG, Copy_u8Pin); break;
                case DIO_u8PORTD: CLR_BIT(DDRD_REG, Copy_u8Pin); break;
                default: Local_u8ErrorState = NOK; break; //PORT out of range
            }
        }
        else if (Copy_u8Direction == DIO_u8PIN_OUTPUT)
        {
            switch (Copy_u8Port)
            {
                case DIO_u8PORTA: SET_BIT(DDRA_REG, Copy_u8Pin); break;
                case DIO_u8PORTB: SET_BIT(DDRB_REG, Copy_u8Pin); break;
                case DIO_u8PORTC: SET_BIT(DDRC_REG, Copy_u8Pin); break;
                case DIO_u8PORTD: SET_BIT(DDRD_REG, Copy_u8Pin); break;
                default: Local_u8ErrorState = NOK; break; //PORT out of range
            }
        }
        else
        {
            Local_u8ErrorState = NOK; //Invalid direction
        }
    }
    else
    {
        Local_u8ErrorState = NOK; //PIN out of range
    }
    return Local_u8ErrorState;
}

uint8 DIO_u8SetPinValue(uint8 Copy_u8Port, uint8 Copy_u8Pin, uint8 Copy_u8Value)
{
    uint8 Local_u8ErrorState = OK;
    if (Copy_u8Pin <= DIO_u8PIN7)
    {
        if (Copy_u8Value == DIO_u8PIN_LOW)
        {
            switch (Copy_u8Port)
            {
                case DIO_u8PORTA: CLR_BIT(PORTA_REG, Copy_u8Pin); break;
                case DIO_u8PORTB: CLR_BIT(PORTB_REG, Copy_u8Pin); break;
                case DIO_u8PORTC: CLR_BIT(PORTC_REG, Copy_u8Pin); break;
                case DIO_u8PORTD: CLR_BIT(PORTD_REG, Copy_u8Pin); break;
                default: Local_u8ErrorState = NOK; break; //PORT out of range
            }
        }
        else if (Copy_u8Value == DIO_u8PIN_HIGH)
        {
            switch (Copy_u8Port)
            {
                case DIO_u8PORTA: SET_BIT(PORTA_REG, Copy_u8Pin); break;
                case DIO_u8PORTB: SET_BIT(PORTB_REG, Copy_u8Pin); break;
                case DIO_u8PORTC: SET_BIT(PORTC_REG, Copy_u8Pin); break;
                case DIO_u8PORTD: SET_BIT(PORTD_REG, Copy_u8Pin); break;
                default: Local_u8ErrorState = NOK; break; //PORT out of range
            }
        }
        else
        {
            Local_u8ErrorState = NOK; //Invalid value
        }
    }
    else
    {
        Local_u8ErrorState = NOK; //PIN out of range
    }
    return Local_u8ErrorState;
}

uint8 DIO_u8TogglePinValue(uint8 Copy_u8Port, uint8 Copy_u8Pin)
{
    uint8 Local_u8ErrorState = OK;
    if (Copy_u8Pin <= DIO_u8PIN7)
    {
        switch (Copy_u8Port)
        {
            case DIO_u8PORTA: TOG_BIT(PORTA_REG, Copy_u8Pin); break;
            case DIO_u8PORTB: TOG_BIT(PORTB_REG, Copy_u8Pin); break;
            case DIO_u8PORTC: TOG_BIT(PORTC_REG, Copy_u8Pin); break;
            case DIO_u8PORTD: TOG_BIT(PORTD_REG, Copy_u8Pin); break;
            default: Local_u8ErrorState = NOK;                break; //PORT out of range
        }
    }
    else
    {
        Local_u8ErrorState = NOK; //PIN out of range
    }
    return Local_u8ErrorState;
}

uint8 DIO_u8GetPinValue (uint8 Copy_u8Port, uint8 Copy_u8Pin, uint8* Copy_pu8Value)
{
    uint8 Local_u8ErrorState = OK;
    if (Copy_pu8Value != NULL)
    {
        if (Copy_u8Pin <= DIO_u8PIN7)
        {
            switch (Copy_u8Port)
            {
                case DIO_u8PORTA: *Copy_pu8Value = GET_BIT(PINA_REG, Copy_u8Pin); break;
                case DIO_u8PORTB: *Copy_pu8Value = GET_BIT(PINB_REG, Copy_u8Pin); break;
                case DIO_u8PORTC: *Copy_pu8Value = GET_BIT(PINC_REG, Copy_u8Pin); break;
                case DIO_u8PORTD: *Copy_pu8Value = GET_BIT(PIND_REG, Copy_u8Pin); break;
                default: Local_u8ErrorState = NOK; break; //PORT out of range
            }
        }
        else
        {
            Local_u8ErrorState = NOK; //PIN out of range
        }
    }
    else
    {
        Local_u8ErrorState = NULL_PTR_ERR;
    }
    return Local_u8ErrorState;
}

uint8 DIO_u8InternalPullUp(uint8 Copy_u8Port, uint8 Copy_u8Pin, uint8 Copy_u8PullUpStatus)
{
    uint8 Local_u8ErrorState = OK;
    if (Copy_u8Pin <= DIO_u8PIN7)
    {
        if (Copy_u8PullUpStatus == DIO_u8PULLUP_ENABLE)
        {
            if ((GET_BIT(SFIOR_REG, PUD_BIT)) == 1)
            {
                CLR_BIT(SFIOR_REG, PUD_BIT);
            }
            else
            {
                //Internal Pullup is enabled
            }
            switch (Copy_u8Port)
            {
                case DIO_u8PORTA: CLR_BIT(DDRA_REG, Copy_u8Pin); SET_BIT(PORTA_REG, Copy_u8Pin); break;
                case DIO_u8PORTB: CLR_BIT(DDRB_REG, Copy_u8Pin); SET_BIT(PORTB_REG, Copy_u8Pin); break;
                case DIO_u8PORTC: CLR_BIT(DDRC_REG, Copy_u8Pin); SET_BIT(PORTC_REG, Copy_u8Pin); break;
                case DIO_u8PORTD: CLR_BIT(DDRD_REG, Copy_u8Pin); SET_BIT(PORTD_REG, Copy_u8Pin); break;
                default: Local_u8ErrorState = NOK; break; //PORT out of range
            }
        }
        else if (Copy_u8PullUpStatus == DIO_u8PULLUP_DISABLE)
        {
            switch (Copy_u8Port)
            {
                case DIO_u8PORTA: CLR_BIT(PORTA_REG, Copy_u8Pin); break;
                case DIO_u8PORTB: CLR_BIT(PORTB_REG, Copy_u8Pin); break;
                case DIO_u8PORTC: CLR_BIT(PORTC_REG, Copy_u8Pin); break;
                case DIO_u8PORTD: CLR_BIT(PORTD_REG, Copy_u8Pin); break;
                default: Local_u8ErrorState = NOK; break; //PORT out of range
            }
        }
        else
        {
            Local_u8ErrorState = NOK; //Invalid value
        }
    }
    else
    {
        Local_u8ErrorState = NOK; //PIN out of range
    }
    return Local_u8ErrorState;
}

void DIO_vDisableAllInternalPullUp()
{
    SET_BIT(SFIOR_REG, PUD_BIT);
}
