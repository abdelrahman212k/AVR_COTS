#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

/*****************************************************************************************/
/*                                 Public Functions                                      */
/*****************************************************************************************/

void DIO_vInit(void);

/*****************************************************************************************
 * Description: This function is used to set port direction
 * Scope:       public
 * Inputs:      Copy_u8Port ------ port number is given, range [DIO_u8PORTA ~ DIO_u8PORTD]
 *              Copy_u8Direction --------- DIO_u8PORT_INPUT / DIO_u8PORT_OUTPUT or any other 8bit value
 * Return:      Local_u8ErrorState -------- OK / NOK
 *****************************************************************************************/
uint8 DIO_u8SetPortDirection(uint8 Copy_u8Port, uint8 Copy_u8Direction);


/*****************************************************************************************
 * Description: This function is used to set port value
 * Scope:       public
 * Inputs:      Copy_u8Port ------ port number is given, range [DIO_u8PORTA ~ DIO_u8PORTD]
 *              Copy_u8Value --------- Input value by the user
 * Return:      Local_u8ErrorState -------- OK / NOK
 *****************************************************************************************/
uint8 DIO_u8SetPortValue(uint8 Copy_u8Port, uint8 Copy_u8Value);


/*****************************************************************************************
 * Description: This function is used to toggle port value
 * Scope:       public
 * Inputs:      Copy_u8Port ------ port number is given, range [DIO_u8PORTA ~ DIO_u8PORTD]
 * Return:      Local_u8ErrorState -------- OK / NOK
 *****************************************************************************************/
uint8 DIO_u8TogglePortValue(uint8 Copy_u8Port);


/*****************************************************************************************
 * Description: This function is used to get the port value
 * Scope:       public
 * Inputs:      Copy_u8Port ------ port number is given, range [DIO_u8PORTA ~ DIO_u8PORTD]
 * Return:      Local_u8ErrorState -------- OK / NOK / NULL_PTR_ERR
 *              Copy_pu8Value ----- Value of the port as pointer
 *****************************************************************************************/
uint8 DIO_u8GetPortVal (uint8 Copy_u8Port, uint8* Copy_pu8Value);


/*****************************************************************************************
 * Description: This function is used to set pin direction
 * Scope:       public
 * Inputs:      Copy_u8Port ------ port number is given, range [DIO_u8PORTA ~ DIO_u8PORTD]
 *              Copy_u8Pin ------- pin number is given, Range [DIO_u8PIN0 ~ DIO_u8PIN7]
 *              Copy_u8Direction --------- DIO_u8PIN_INPUT / DIO_u8PIN_OUTPUT
 * Return:      Local_u8ErrorState -------- OK / NOK
 *****************************************************************************************/
uint8 DIO_u8SetPinDirection (uint8 Copy_u8Port, uint8 Copy_u8Pin, uint8 Copy_u8Direction);

/*****************************************************************************************
 * Description: This function is used to set pin value
 * Scope:       public
 * Inputs:      Copy_u8Port ------ port number is given, range [DIO_u8PORTA ~ DIO_u8PORTD]
 *              Copy_u8Pin ------- pin number is given, Range [DIO_u8PIN0 ~ DIO_u8PIN7]
 *              Copy_u8Value --------- DIO_u8PIN_HIGH / DIO_u8PIN_LOW
 * Return:      Local_u8ErrorState -------- OK / NOK
 *****************************************************************************************/
uint8 DIO_u8SetPinValue(uint8 Copy_u8Port, uint8 Copy_u8Pin, uint8 Copy_u8Value);


/*****************************************************************************************
 * Description: This function is used to toggle pin value
 * Scope:       public
 * Inputs:      Copy_u8Port ------ port number is given, range [DIO_u8PORTA ~ DIO_u8PORTD]
 *              Copy_u8Pin ------- pin number is given, Range [DIO_u8PIN0 ~ DIO_u8PIN7]
 * Return:      Local_u8ErrorState -------- OK / NOK
 *****************************************************************************************/
uint8 DIO_u8TogglePinValue(uint8 Copy_u8Port, uint8 Copy_u8Pin);

/*****************************************************************************************
 * Description: This function is used to get the pin value
 * Scope:       public
 * Inputs:      Copy_u8Port ------ port number is given, range [DIO_u8PORTA ~ DIO_u8PORTD]
 *              Copy_u8Pin ------- pin number is given, Range [DIO_u8PIN0 ~ DIO_u8PIN7]
 * Return:      Local_u8ErrorState ---- OK / NOK / NULL_PTR_ERR
 *              Copy_pu8Value as pointer
 *****************************************************************************************/
uint8 DIO_u8GetPinValue(uint8 Copy_u8Port, uint8 Copy_u8Pin, uint8* Copy_pu8Value);

/*****************************************************************************************
 * Description: This function is used to control internal pull up
 * Scope:       public
 * Inputs:      Copy_u8Port ------ port number is given, range [DIO_u8PORTA ~ DIO_u8PORTD]
 *              Copy_u8Pin ------- pin number is given, Range [DIO_u8PIN0 ~ DIO_u8PIN7]
 *              Copy_u8PullUpStatus --------- DIO_u8PULLUP_ENABLE / DIO_u8PULLUP_DISABLE
 * Return:      Local_u8ErrorState ---- OK / NOK
 *****************************************************************************************/
uint8 DIO_u8InternalPullUp(uint8 Copy_u8Port, uint8 Copy_u8Pin, uint8 Copy_u8PullUpStatus);

/*****************************************************************************************
 * Description: This function is used to disable all internal pull up
 * 				By putting a 1 in PUD bit @ SFIOR register
 * Scope:       public
 * Inputs:      void
 * Return:      void
 *****************************************************************************************/
void DIO_vDisableAllInternalPullUp();

/*****************************************************************************************/
/*                                   Public Macros                                       */
/*****************************************************************************************/

//Port definitions
#define DIO_u8PORTA  0U
#define DIO_u8PORTB  1U
#define DIO_u8PORTC  2U
#define DIO_u8PORTD  3U

//Pin definitions
#define DIO_u8PIN0   0U
#define DIO_u8PIN1   1U
#define DIO_u8PIN2   2U
#define DIO_u8PIN3   3U
#define DIO_u8PIN4   4U
#define DIO_u8PIN5   5U
#define DIO_u8PIN6   6U
#define DIO_u8PIN7   7U

//Directions
#define DIO_u8PIN_OUTPUT   1U
#define DIO_u8PIN_INPUT    0U
#define DIO_u8PORT_OUTPUT  0xFFU
#define DIO_u8PORT_INPUT   0U

//Digital Values
#define DIO_u8PIN_HIGH      1U
#define DIO_u8PIN_LOW       0U
#define DIO_u8PORT_HIGH     0xFFU
#define DIO_u8PORT_LOW      0U

// Internal PullUp
#define DIO_u8PULLUP_ENABLE    1U
#define DIO_u8PULLUP_DISABLE   0U

#endif /* DIO_INTERFACE_H_ */