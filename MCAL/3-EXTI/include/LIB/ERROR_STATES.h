/*******************************************************************************************************/
/* Author            : Abdelrahman Kamal Eldean                                                        */
/* Version           : V0.0.0                                                                          */
/* Data              : 16 May 2023                                                                     */
/* Description       : LERROR_STATES.h                                                                 */
/*******************************************************************************************************/

/*******************************************************************************************************/
/*                                             File Guard		                                       */
/*******************************************************************************************************/
#ifndef ERROR_STATES_H_
#define ERROR_STATES_H_
/*******************************************************************************************************/
/*                                        Enumerators for Errors	     	                           */
/*******************************************************************************************************/
typedef enum
{
	ES_NOK,
	ES_OK,
	ES_OUT_OF_RANGE,
	ES_NULL_POINTER
}ES_t;

#define NOK           0U
#define OK            1U
#define NULL_PTR_ERR  2U



#endif /* ERROR_STATES_H_ */


