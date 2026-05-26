/*
 * uart0.h
 *
 *  Created on: 8 oct. 2022
 *      Author: gos
 */

#ifndef UART0_H_
#define UART0_H_

#include "LPC845_Regs.h"

#define TXBUFFER_SIZE	120    //arbitrario
#define RXBUFFER_SIZE	120    //arbitrario
#define MAX_DATOS	    30     //arbitrario

//primitivas de recepción y transmisión. No están comprometidas con el HW
void UART0_pushTx(uint8_t dato);
int16_t UART0_popTx(void);
void UART0_pushRx(uint8_t dato);
int16_t UART0_popRx(void);
void EnviarString (const char *str);
int16_t Transmitir (const void * , uint8_t );
//------------------------------------------------------------------------

//Macro definida para arrancar la Tx y no pinchar capas
#define   START_TX()	USART0->INTENSET = (1 << 2)

#define RECIBIR_UART0 UART0_popRx()
#define ENVIAR_UART0 UART0_pushTx()


void inic_uart0(void);

#endif /* UART0_H_ */
