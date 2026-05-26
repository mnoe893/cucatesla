/*
 * ctimer.c
 *
 *  Created on: 18 oct. 2022
 *      Author: juamm mnoe
 */
#include "cucateslainc.h"

extern volatile float distancia_D;
extern volatile float distancia_T;


/*
 * Interpretación de como funciona CTIMER0 segun lo leido: Ctimer es un periferico que permite temporizaciones externas,
 * hay dos formas de trabajar con Ctimer, por match o por captura(o las dos a la vez), match es que cuando el valor que querramos coincida con el
 * valor del timer se lance una interrupcion, Y por captura es que cuando el timer reciba una señal se haga una captura del
 * valor del timer.
 */

/*Paso a paso de cómo funciona capture timer:
 * Configuro la funcion en la switch matrix y establezco un pin como input para medir los pulsos
 * Hago que el timer se resetee cuando hay un borde ascendente (empieza pulso y arranca en 0)
 * Configuro que se realice una captura del tiempo cuando hay un borde descentende (termino pulso)
 * Leo el tiempo guardado en "capture registers"*/

void inicializar_ctimer(void)
{
	//RECETA DE LA INICIALIZACION DE CTIMER pag 360, Capitulo 20.3

	//1.Activo el clock de SWM
	SYSCON->SYSAHBCLKCTRL0 |= (SYSCON_SYSAHBCLKCTRL0_SWM_MASK);

	//2.Hago un reset al CTIMER0, para que es esto?
	SYSCON->PRESETCTRL0 |= (SYSCON_SYSAHBCLKCTRL0_CTIMER0_MASK);

	//3.Selecciono los pins para el timer pag 363 preguntar

	SWM_SetMovablePinSelect(kSWM_T0_CAP_CHN0,kSWM_PortPin_P0_29); //echo delantero
	SWM_SetMovablePinSelect(kSWM_T0_CAP_CHN2,kSWM_PortPin_P0_30); //echo trasero

	//4.Apago el clock de SWM
	SYSCON->SYSAHBCLKCTRL0 &= ~(SYSCON_SYSAHBCLKCTRL0_SWM_MASK);

	//5.Activo el clock del CTIMER0 pag 100
	SYSCON->SYSAHBCLKCTRL0 |= (SYSCON_SYSAHBCLKCTRL0_CTIMER0_MASK);

	//6.Para configurar el evento de cap o captura pag 369 preguntar
	CTIMER0->CCR |= ((uint32_t)(0x1<<1U));
	CTIMER0->CCR |= ((uint32_t)(0x1<<2U));// INICIALIZACIONES DEL CANAL 0

	CTIMER0->CCR |= ((uint32_t)(0x1<<7U));
	CTIMER0->CCR |= ((uint32_t)(0x1<<8U)); //INICIALIZACIONES DEL CANAL 2
	//
	CTIMER0->MCR |= (uint32_t)(0x1<<0U);//genera una interrupcion cuando MCR0 = TC
	//CTIMER0->MCR |= (uint32_t)(0x1<<1U);
	CTIMER0->MCR |= (uint32_t)(0x1<<24U);

	//7.Configuro el ctimer(CTIMER0->CTCR o CTIMER0->EMR, dependiendo de si uso match o captura) pag 371 preguntar

	//8.Establezco la velocidad del timer pag 367
	CTIMER0->PR=30U;//Hago trabajar el CTIMER a 10MHZ
	CTIMER0->MR[0]=10U;//1 millon de micro segundos= 1 segundo
	CTIMER0->MSR[0]=10U;
	//9.Activar la interrupcion en NVIC pag 67
	NVIC->ISER[0] |= (uint32_t)(0x1<<CTIMER0_IRQn);

	//ON
	CTIMER0->TCR |= (uint32_t)(0x1<<0U);
}

void CTIMER0_IRQHandler(void)//Debo checkear el status para saber de quien fue la interrupcion que atajo?? pero donde esta el status??
{
		uint32_t status = 0;
		//static int i=0,cap1=0;
		float cap=0,capt=0;
		status=(CTIMER0->IR & 0x7F); //porque el status llega con 2 bits ?
		if((status>>0) & (0x1<<0))
		{
			CTIMER0->IR |= (0x1<<0U);
			TRIG1_OFF;
			TRIG0_OFF;

		}

		if((status>>4) & (0x1<<0)) //Lo desplazo y lo andeo con un 1, si era un 1 entra al if
		{
			CTIMER0->IR |= (0x1<<4U);
			cap=CTIMER0->CR[0]; //porque no hay valor de captura aca?
			if(cap > 0)
			distancia_D=(cap-554)/55;
		//	CTIMER0->TCR &= (uint32_t)~(0x1<<0U);
		}
		if((status>>6) & (0x1<<0))
		{
			CTIMER0->IR |= (0x1<<6U);
			capt=CTIMER0->CR[2]; //porque no hay valor de captura aca?
			if(capt > 0)
			distancia_T=(capt-554)/55;
		//	CTIMER0->TCR &= (uint32_t)~(0x1<<0U);
		}


}


