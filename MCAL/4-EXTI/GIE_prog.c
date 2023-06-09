#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GIE_reg.h"
#include "GIE_interface.h"

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
