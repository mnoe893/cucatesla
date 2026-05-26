/*
 * mde_com.c
 *
 *  Created on: 13 oct. 2022
 *      Author: Martin
 */

#include "cucateslainc.h"


volatile uint16_t config[4]={1700,4,5,1};//= {nivel luz, frecnciadlb, dismin, velocidad}
extern volatile uint32_t valorADC;


volatile uint16_t autonomo[2]={0,0};//= {modo, pausa}
volatile uint16_t ojos=0;//= x (on/off);
volatile uint8_t flag_oscu=0;
volatile uint32_t comando_mov, comando_dob;

int leerTrama(void)
{
	int val=-1, dato;
	static int ESTADO=0, j=0, auxiliar=0, aux[10];
	dato=RECIBIR_UART0;
	if(dato == -1)
		return -1;
	switch(ESTADO)
	{
	case 0:	if((uint8_t)dato=='#')
			{
				ESTADO=1;
				auxiliar=0;
			}
			break;
	case 1:
			aux[j]=(uint8_t)dato-48;
			j++;
			if(j == 3)
			{
				ESTADO = 2;
				j=0;
			}

			break;
	case 2:
		if((uint8_t)dato=='$')
		{
			auxiliar = aux[0] * 100;
			auxiliar += aux[1] * 10;
			auxiliar += aux[2]*1;

			val=auxiliar;
		}
		ESTADO=0;
		break;
	}
	return val;
}

void mde_recepcion()
{
	int dato, filtro=-1;

	dato=leerTrama();
	if(dato!=-1)
	{
		filtro=dato%1000;
		dato/=1000;
		switch(filtro)
		{
		case NvlLuz: config[0]= valorADC;break; //Guarda la lectura actual como nivel
		case FrDoblar: config[1]=dato; break;
		case DistMin: config[2]=dato; break;
		case Vel: config[3] = dato; break;
		case WoN: comando_mov = 'w'; break;
		case WoFF: comando_mov = 0;break;
		case SoN: comando_mov = 's';break;
		case SoFF: comando_mov = 0;break;
		case AoN: comando_dob = 'a';break;
		case AoFF: comando_dob = 0;break;
		case DoN: comando_dob = 'd';break;
		case DoFF: comando_dob = 0;break;
		case Emerg: comando_dob = 'm';break;
		case ModAuto: autonomo[0] = 1;break;
		case ModUsr: autonomo[0] = 0;break;
		case OjoN: ojos=1;break;
		case OjoFF: ojos=0;break;
		case Pause: autonomo[1]=1;break;
		case Play: autonomo[1]=0;break;
		}
	}
}

void mde_com(void)
{
	mde_recepcion();
}
