/********************  LIB includes  ********************/
#include "../include/LIB/STD_TYPES.h"
#include "../include/LIB/DEFINES.h"
#include "../include/LIB/BIT_MATH.h"
#include "../include/LIB/ERROR_STATES.h"

/********************  MCAL includes  ********************/
#include "../include/MCAL/GIE/GIE_reg.h"
#include "../include/MCAL/GIE/GIE_interface.h"

void GIE_vEnableGlobalInterrupt(void)
{
//    SET_BIT(SREG_REG, SREG_I);
	__asm __volatile("SEI");
}

void GIE_vDisableGlobalInterrupt(void)
{
//    CLR_BIT(SREG_REG, SREG_I);
	__asm __volatile("CLI");
}
