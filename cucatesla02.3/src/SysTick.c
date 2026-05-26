/*
 * SysTick.c
 *
 *  Created on: 12 ene. 2022
 *      Author: gos
 */

#include "cucateslainc.h"

extern volatile uint16_t DelayHigh;
extern volatile uint16_t DelayPeriod;
extern volatile uint16_t t_doblar;
extern volatile uint16_t t_espera;
volatile uint8_t DelaySensor = 14, DelaySonico=200;


/**
	\fn  	uint32_t SysTick_Config(uint32_t ticks)
	\brief 	Inicializacion del SysTick
 	\author Ing. Gabriel Soccodato
 	\date 	19 de Setiembre de 2022
 	\param 	uint32_t ticks, cantidad de plsos de clock a contar
 	\return uint32_t, 0
*/

uint32_t SysTick_Config(uint32_t ticks)
{
			SYST_RVR  = (ticks) - 1 ;
			SYST_CVR = 0; /*para que desborde al próximo tick y se
			reinicialice al valor adecuado programado en STRELOAD*/
			ENABLE = 1; //habilito que comience a contar
			TICKINT = 1; //habilito interrupciones
			CLKSOURCE = 1; //uso clock interno
			return (0UL);
}


/**
	\fn  	void SysTick_Handler(void)
	\brief 	Isr del SysTick
 	\author Ing. Gabriel Soccodato
 	\date 	19 de Setiembre de 2022
 	\param 	void
 	\return void
*/
void SysTick_Handler(void)
{
	if(DelayHigh)
		DelayHigh--;
	if(t_doblar)
		t_doblar--;
	if(DelayPeriod)
		DelayPeriod--;
	if(t_espera)
		t_espera--;
	if(DelaySensor)
		DelaySensor--;
	else
	{
		DelaySensor = 14;
		barrido_mrt();
	}
	if(DelaySonico)
		DelaySonico--;
	else
	{
		DelaySonico = 200;
		mando_pulso();
	}
	//Chequeo_Luz(); // Modifica la flag_oscu

}


