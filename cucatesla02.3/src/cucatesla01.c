/*
===============================================================================
 Name        : cucatesla01.c
 Author      : $(author)
 Version     :
 Copyright   : $(copyright)
 Description : main definition
===============================================================================
*/

#include <cr_section_macros.h>
#include "cucateslainc.h"
#include "stdlib.h"

volatile uint32_t SystemCoreClock;
volatile uint32_t DelayPeriod = 255;
volatile uint32_t DelayHigh = 0;


volatile uint32_t t_espera =200;
volatile float distancia_D=-1;
volatile float distancia_T=-1;

//volatile uint8_t comando_mov;
volatile uint32_t t_doblar;
volatile uint8_t DelayADC;
volatile uint32_t valorADC;

volatile uint32_t AnchoBarrido=45000, AnchoDoblar=43000, AnchoVelocidad = 20000;

volatile uint32_t a;
int main(void) {
	//static int i=0;
	char buf[5];
	char buf2[5];
	inicializacion();

    while(1) {
        mde_com();
        mde_mov_user();
        mde_mov_autonomo();


    	if(distancia_D>2)
    	{
    		LED_ROJO_ON;

    		//SENSOR DELANTERO
    		distancia_D *= 100;
    		for(int j=4;j>=0;j--)
    		{
    			if(j==2)
    				buf[j]='.';
    			else
    			{
        			buf[j]=((int)distancia_D%10)+48;
        			distancia_D= (int)distancia_D/10;
    			}
    		}
    		UART0_pushTx('D');
    		Transmitir(buf,5);
    		UART0_pushTx('\n');
    		UART0_pushTx('\r');
    		distancia_D = 0;
    	}

    	if(distancia_T > 2)
    	{
    		//SENSOR TRASERO
    		distancia_T *= 100;
    		for(int j=4;j>=0;j--)
			{
				if(j==2)
					buf2[j]='.';
				else
				{
					buf2[j]=((int)distancia_T%10)+48;
					distancia_T= (int)distancia_T/10;
				}
			}
    		UART0_pushTx('T');
			Transmitir(buf2,5);
			UART0_pushTx('\n');
			UART0_pushTx('\r');
			distancia_T = 0;
    	}
    	else
    	{
    		LED_ROJO_OFF;
    	}
    }
    return 0 ;
}
