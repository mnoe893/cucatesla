/*
 * mrt.c
 *
 *  Created on: 23 nov. 2022
 *      Author: juanm y martin
 */
#include "cucateslainc.h"

extern volatile uint32_t AnchoBarrido, AnchoDoblar, AnchoVelocidad;
extern volatile uint8_t EstadoSensor[4];
extern volatile float distancia_D,distancia_T;
extern volatile uint16_t config[4];


void MRT_Inic(void)
{
	//Activo el MRT
	SYSCON->SYSAHBCLKCTRL0 |= (0x1<<10U);
	NVIC->ISER[0] |= (0x1<<10U);

	//Configuro MRT0
	MRT->PART[0].CTRL |= (0x1<<0U);
	MRT->PART[0].CTRL |= (0x1<<1U);

	//Configuro MRT1/2
	MRT->PART[1].CTRL |= (0x1<<0U);
	MRT->PART[1].CTRL |= (0x1<<1U);

	MRT->PART[2].CTRL |= (0x1<<0U);
	MRT->PART[2].CTRL |= (0x1<<1U);

	MRT->PART[0].INTVAL =AnchoVelocidad;//20 milisegundos
	MRT->PART[1].INTVAL =AnchoBarrido;//1.5 milisegundo
	MRT->PART[2].INTVAL =AnchoDoblar;//1.5 milisegundo
}

void MRT_IRQHandler(void)
{
	static uint8_t estado_a = 1;
	static uint8_t estado_b = 1;
	static uint8_t estado_c = 1;
	uint32_t status=MRT->IRQ_FLAG;
	if(status>>0 & 0x1)//mrt0 --> Velocidad motor
	{
		MRT->IRQ_FLAG |= (0x1<<0U);
		if(estado_c && ((PulsoVelocidad - AnchoVelocidad) != 0)){
			MRT->PART[1].INTVAL = (PulsoVelocidad - AnchoVelocidad);
			SetPIN(0,15,0);
			estado_c = 0;
		}
		else{
			MRT->PART[1].INTVAL = AnchoVelocidad;
			SetPIN(0,15,1);
			estado_c = 1;
		}
	}
	if(status>>1 & 0x1)//mrt1 --> Servo sensor
	{
		MRT->IRQ_FLAG |= (0x1<<1U);
		if(estado_a && ((PulsoBarrido - AnchoBarrido) != 0)){
			MRT->PART[1].INTVAL = (PulsoBarrido - AnchoBarrido);
			SetPIN(0,9,0);
			ServoSensor_OFF;
			estado_a = 0;
		}
		else{
			MRT->PART[1].INTVAL = AnchoBarrido;
			SetPIN(0,9,1);
			ServoSensor_ON;
			estado_a = 1;
		}
	}

	if(status>>2 & 0x1)//mrt2 --> Servo ruedas
	{
		MRT->IRQ_FLAG |= (0x1<<2U); //bajo bandera
		if(estado_b && ((PulsoDoblar - AnchoDoblar) != 0)){
			MRT->PART[2].INTVAL = (PulsoDoblar - AnchoDoblar); //reconfiguro timer

			ServoDoblar_OFF;//bajo pulso
			estado_b = 0;//cambio estado
		}
		else{
			MRT->PART[2].INTVAL = AnchoDoblar;

			ServoDoblar_ON;
			estado_b = 1;
		}
	}
}

void barrido_mrt(void)
{
	static uint8_t caso=0;
	if(!caso)
	{
		AnchoBarrido+=1000;
		if(AnchoBarrido==60000)
			caso=1;
	}
	else
	{
		AnchoBarrido-=1000;
		if(AnchoBarrido==30000)
			caso=0;
	}
	if(distancia_D<config[2])
	{
		if(AnchoBarrido>= 30000 && AnchoBarrido<= 34000)
			EstadoSensor[0]=0;
		if(AnchoBarrido> 34000 && AnchoBarrido< 54000)
			EstadoSensor[1]=0;
		if(AnchoBarrido>= 54000 && AnchoBarrido<= 60000)
			EstadoSensor[2]=0;
	}
	else
	{
		if(AnchoBarrido>= 30000 && AnchoBarrido<= 34000)
			EstadoSensor[0]=1;
		if(AnchoBarrido> 34000 && AnchoBarrido< 54000)
			EstadoSensor[1]=1;
		if(AnchoBarrido>= 54000 && AnchoBarrido<= 60000)
			EstadoSensor[2]=1;
	}
	if(distancia_T<config[2])
		EstadoSensor[3]=0;
	else
		EstadoSensor[3]=1;
}

/*

void MRT_Inic(void)
{
	//Activo el MRT
	SYSCON->SYSAHBCLKCTRL0 |= (0x1<<10U);
	NVIC->ISER[0] |= (0x1<<10U);

	//Configuro MRT0
	MRT->PART[0].CTRL |= (0x1<<0U);
	MRT->PART[3].CTRL |= (0x1<<1U);


	//Configuro MRT1/2
	MRT->PART[1].CTRL |= (0x1<<0U);
	MRT->PART[1].CTRL |= (0x1<<1U);

	MRT->PART[2].CTRL |= (0x1<<0U);
	MRT->PART[2].CTRL |= (0x1<<1U);

	MRT->PART[0].INTVAL =PulsoBarrido;//20 milisegundos

	MRT->PART[1].INTVAL =AnchoBarrido;//1.5 milisegundo

	MRT->PART[3].INTVAL =PulsoDoblar;//20 milisegundos

	MRT->PART[2].INTVAL =AnchoDoblar;//1.5 milisegundo
}

void MRT_IRQHandler(void)
{
	uint32_t status=MRT->IRQ_FLAG;
	if(status>>0 & 0x1)//mrt0
	{
		MRT->IRQ_FLAG |= (0x1<<0U);
		//SetPIN(0,9,1);//barrido
		ServoSensor_ON;

		MRT->PART[1].INTVAL =AnchoBarrido;
		//MRT->PART[2].INTVAL =AnchoDoblar;
	}
	if(status>>1 & 0x1)//mrt1
	{
		MRT->IRQ_FLAG |= (0x1<<1U);
		//SetPIN(0,9,0);
		ServoSensor_OFF;
	}
	if(status>>2 & 0x1)//mrt2
	{
		MRT->IRQ_FLAG |= (0x1<<2U);
		//SetPIN(0,8,0);
		ServoDoblar_OFF;
	}
	if(status>>3 & 0x1)//mrt3
	{
		MRT->IRQ_FLAG |= (0x1<<3U);

		//SetPIN(0,8,1);//doblar
		ServoDoblar_ON;
		//MRT->PART[1].INTVAL =AnchoBarrido;
		MRT->PART[2].INTVAL =AnchoDoblar;
	}

}

void barrido_mrt(void)
{
	static uint8_t caso=0;
	if(!caso)
	{
		AnchoBarrido+=1000;
		if(AnchoBarrido==60000)
			caso=1;
	}
	else
	{
		AnchoBarrido-=1000;
		if(AnchoBarrido==30000)
			caso=0;
	}
	if(distancia_D<config[2])
	{
		if(AnchoBarrido>= 30000 && AnchoBarrido<= 34000)
			EstadoSensor[0]=0;
		if(AnchoBarrido> 34000 && AnchoBarrido< 54000)
			EstadoSensor[1]=0;
		if(AnchoBarrido>= 54000 && AnchoBarrido<= 60000)
			EstadoSensor[2]=0;
	}
	else
	{
		if(AnchoBarrido>= 30000 && AnchoBarrido<= 34000)
			EstadoSensor[0]=1;
		if(AnchoBarrido> 34000 && AnchoBarrido< 54000)
			EstadoSensor[1]=1;
		if(AnchoBarrido>= 54000 && AnchoBarrido<= 60000)
			EstadoSensor[2]=1;
	}
	if(distancia_T<config[2])
		EstadoSensor[3]=0;
	else
		EstadoSensor[3]=1;
}
*/
