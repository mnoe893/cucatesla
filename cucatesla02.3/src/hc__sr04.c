/*
 * hc__sr04.c
 *
 *  Created on: 1 nov. 2022
 *      Author: martin
 */
#include "cucateslainc.h"
#include "hc_sr04.h"





void mando_pulso()
{
	TRIG1_ON;
	TRIG0_ON;
	//match_on;
	CTIMER0->TCR |= (uint32_t)(0x1<<1U);
	CTIMER0->TCR &= (uint32_t)~(0x1<<1U);
}





