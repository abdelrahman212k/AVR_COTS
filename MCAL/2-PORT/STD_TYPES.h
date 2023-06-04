/*******************************************************************************************************/
/* Author            : Abdelrahman Kamal Eldean                                                        */
/* Version           : V0.0.0                                                                          */
/* Data              : 16 May 2023                                                                     */
/* Description       : LSTD_TYPES.h                                                                    */
/*******************************************************************************************************/


/*******************************************************************************************************/
/*                                              File guard		                                       */
/*******************************************************************************************************/

#ifndef CE18E59B_1384_429B_ACD7_595D9166EA4F
#define CE18E59B_1384_429B_ACD7_595D9166EA4F
#ifndef STD_TYPES_H_
#define STD_TYPES_H_
/*******************************************************************************************************/
/*                                           BOOLEAN VALUES	     	                                   */
/*******************************************************************************************************/

#ifndef		FALSE
#define		FALSE   (0u)
#endif

#ifndef		TRUE
#define		TRUE   (1u)
#endif


// Unsigned Variables
typedef unsigned char			  	uint8  ;
typedef unsigned short int			uint16 ;
typedef unsigned long  int			uint32 ;
typedef unsigned long long int		uint64 ;

// Signed Variables
typedef signed char			     	sint8  ;
typedef signed short int			sint16 ;
typedef signed long  int			sint32 ;
typedef signed long long int		sint64 ;

// Float Variables
typedef float						f32	 ;
typedef double						f64	 ;
typedef long double                 f128 ;


#define NULL  		((void*) 0)


#endif /* STD_TYPES_H_ */


#endif /* CE18E59B_1384_429B_ACD7_595D9166EA4F */
