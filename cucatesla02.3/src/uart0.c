/*
 * uart0.c
 *
 *  Created on: 8 oct. 2022
 *      Author: gos
 */

#include "cucateslainc.h"

volatile uint8_t txStart = 0;  //flag para activar/desactivar transmisión serie

// Buffer de Transmision
uint8_t bufferTx[TXBUFFER_SIZE];
// Buffer de Recepcion
uint8_t bufferRx[RXBUFFER_SIZE];

// Indices de Recepcion
uint8_t inx_rx_in = 0;
uint8_t inx_rx_out = 0;
// Indices de Transmision
uint8_t inx_tx_in = 0;
uint8_t inx_tx_out = 0;


/**
 	\file PR_serie.c
 	\brief Primitiva de transmisión serie
 	\details Escribe en el buffer de Tx protegiendo índices. Dispara la tx. Está del lado del main
 	\param [in] void
 	\return void
*/
void UART0_pushTx(uint8_t dato)
{
	bufferTx[inx_tx_in] = dato;
	inx_tx_in++;
	inx_tx_in %= TXBUFFER_SIZE;

	if(txStart == 0){   //si no hay transmisión activa.... la activo
		txStart = 1;
		//Escribo TXDAT y activo int Tx. Es una macro para no pinchar capas
		START_TX();     //#define START_TX()	( USART0->INTENSET = (1 << 2); ) // int tx
	}
}


/**
 	\file PR_serie.c
 	\brief Transmisión serie.
 	\details Es llamada por la isr extrayendo el dato a transmitir desde el buffer de Tx protegiendo índices
 	\details La consideramos primitiva pues aunque la llama la isr no está comprometida con el HW
 	\param [in] void
	\return 0 por exito, -1 por Error (no hay mas datos para transmitir en el buffer)
*/
int16_t UART0_popTx(void)
{
	int16_t dato = -1;

	if(inx_tx_in != inx_tx_out){
		dato = (uint16_t) bufferTx[inx_tx_out];
		inx_tx_out++;
		inx_tx_out %= TXBUFFER_SIZE;
	}
	return dato;
}

/**
 	\file PR_serie.c
 	\brief Recepción serie.
 	\details Es invocada por la isr para escribir en el buffer de Rx protegiendo índices
 	\details La consideramos primitiva pues aunque la llama la isr no está comprometida con el HW
 	\param [in] Recibe el dato que fue leído en el registro de recepción serie RXDAT
	\return void
*/
void UART0_pushRx(uint8_t dato)
{
	bufferRx[inx_rx_in] = dato;
	inx_rx_in++;
	inx_rx_in %= RXBUFFER_SIZE;
}


/**
 	\file PR_serie.c
 	\brief Primitiva de recepción serie.
 	\details Lee desde el buffer de Rx protegiendo índices. Está del lado del main
 	\details La consideramos primitiva pues aunque la llama la isr no está comprometida con el HW
 	\param [in] void
	\return 0 por exito, -1 por Error (no hay mas datos para recibir desde el buffer)
*/
int16_t UART0_popRx(void)
{
	int16_t dato = -1;

	if(inx_rx_in != inx_rx_out){
		dato = (uint16_t) bufferRx[inx_rx_out],
		inx_rx_out++;
		inx_rx_out %= RXBUFFER_SIZE;
	}
	return dato;
}

/**
 	\file PR_serie.c
 	\brief Primitiva de transmisión serie de mas alto nivel para enviar cadenas.
 	\details Descompone la cadena en caracteres e invoca a pushTx() caracter a caracter.
 	\param [in] cadena a transmitir
	\return void
*/
void EnviarString (const char *str)
{
	uint8_t i = 0;
	while(str[i] != 0x00){
		UART0_pushTx(str[i]);
		i++;
	}
}

/**
	\fn int16_t Transmitir ( const void * datos , uint8_t cant)
	\brief Primitiva de transmisión serie de mas alto nivel para enviar bloques de datos.
	\brief despacha los datos a transmitir desde un buffer
 	\author Ing. Marcelo Trujillo
 	\date 5 de oct. de 2017
	\param [in] const void * datos: datos a transmitir
	\param [in] uint8_t cant: cantidad de datos a transmitir
	\return 0 por exito, -1 por Error (datos exedidos)
*/
int16_t Transmitir (const void * datos , uint8_t cant )
{
	uint8_t	i;

	if ( cant > MAX_DATOS )
		return -1;


	for ( i = 0 ; i < cant ; i++ )
		UART0_pushTx( * ( ( uint8_t * ) ( datos + i ) ) );

	return 0 ;
}

/**
	\fn  	void UART0_IRQHandler(void)
	\brief 	Isr de UART0
 	\author Ing. Gabriel Soccodato
 	\date 	28 de Julio de 2021
 	\param 	void
 	\return void
*/
void UART0_IRQHandler(void){
	int16_t auxTemporal;
	uint32_t stat = USART0->STAT;   //consulto el estado de la UART

    // CASO RECEPCION
	if(stat & (1 << 0))  //Receiver Ready Flag. Si vale 1, indica que un dato es disponible para ser leído del buffer del
			             //receptor. Se borra solo luego de leer uno de los registros RXDAT o RXDATSTAT.
	{
		auxTemporal = (int16_t) USART0->RXDAT;    		//recibo dato
		UART0_pushRx((uint8_t) auxTemporal);            //manejo bufferRx correctamente
	}

	//CASO TRANSMISION
	if(stat & (1 << 2))  //Transmitter Ready flag.  Si vale 1, indica que se puede escribir en TXDAT.
		// El dato previo podria aún estar en proceso de transmisión. Se borra solo cuando se escribe el registro TXDAT, y se pone en 1
		// cuando el dato es movido desde TXDAT al serializador.
	{
		auxTemporal = UART0_popTx();    //Si hubo una int de Tx, leo del bufferTx y almaceno en variable de trabajo (auxTemporal)
		if(auxTemporal >= 0)      //¿sigue habiendo datos para tx? (popTx() devuelve -1 cuando ya no hay datos para tx)
			USART0->TXDAT = (uint8_t)auxTemporal;  //escribo TXDAT (transmito)
		else
		{   //no hay mas datos.... Desactivo Int Tx
			USART0->INTENCLR = (1 << 2); //disable int TX
			txStart = 0;  //cuando vale 0 indica que no hay tx activa
		}
	}
}

/**
	\fn  	void inic_uart0(void)
	\brief 	Inicializacion de UART0
 	\author Ing. Gabriel Soccodato
 	\date 	28 de Julio de 2021
 	\param 	void
 	\return void
*/
void inic_uart0(void){
    /* Habilita clock de SWM */
	SYSCON->SYSAHBCLKCTRL0 |= (SYSCON_SYSAHBCLKCTRL0_SWM_MASK);

	/* USART0_TXD connect to P0_25 */
    SWM_SetMovablePinSelect(kSWM_USART0_TXD, kSWM_PortPin_P0_25);

    /* USART0_RXD connect to P0_24 */
    SWM_SetMovablePinSelect(kSWM_USART0_RXD, kSWM_PortPin_P0_24);

    /* Deshabilita clock de SWM */
    SYSCON->SYSAHBCLKCTRL0 &= ~(SYSCON_SYSAHBCLKCTRL0_SWM_MASK);

    // FRO/2 en UART0
    UART0CLKSEL = (uint32_t)0x04;

    /* Habilita clock de UART0 */
	SYSCON->SYSAHBCLKCTRL0 |= SYSCON_SYSAHBCLKCTRL0_UART0_MASK; 			// Habilito clk de la usart0

    /* Configura comunicacion de UART0 */
	USART0->CFG |= USART_CFG_ENABLE_MASK;							// USART0 enabled
	USART0->CFG &= ~(USART_CFG_DATALEN_MASK);						// USART0 8 bits de datos
	USART0->CFG |= (0x01 << USART_CFG_DATALEN_SHIFT);
	USART0->CFG &= ~USART_CFG_PARITYSEL_MASK;						// USART0 sin paridad
	USART0->CFG &= ~USART_CFG_STOPLEN_MASK;						// USART0 1 bit de stop

    /* Configura BR de UART0 */
	//USART0->CTL = (uint32_t) 0x00;											// Configuro CTL para operación normal
	USART0->BRG = (uint32_t)97;												// Configura FRGVL en 97 para lograr 9600bps desde 15MHz
																			// Ojo que el manual dice que el clk sale de FRG pero sale de FCLK
    /* Configura INT UART0 */
	USART0->INTENSET |= USART_INTENSET_RXRDYEN_MASK;				// Habilito interrupciones locales de RX
	NVIC->ISER[0] |= (uint32_t) (0x01 << USART0_IRQn);						// Habilito interrupciones globales
}
