/*
 * adc.c
 *
 *  Created on: 23 nov. 2022
 *      Author: Magdalena
 */

#include "cucateslainc.h"

extern volatile uint8_t DelayADC;
extern volatile uint32_t valorADC;
extern volatile uint32_t SystemCoreClock;
extern volatile uint16_t config[3]; //= {nivel luz, frecnciadlb, dismin}
volatile uint32_t max_luz = 1000; //lectura del nivel de luz maxima (aprox 1000)
volatile uint32_t min_luz = 3000; //lectura del nivel de luz minima (aprox 3000)
volatile uint32_t nivel_luz; //lectura del nivel de luz actual

extern volatile uint8_t flag_oscu;

void calibraADC(void){

	uint32_t temporal;
    uint32_t frecuencia = 0U;

	// 4-Calibra ADC
	//a-Se debe obtener la frecuencia del ADC
	frecuencia = SystemCoreClock;
	temporal = ADC0->CTRL;
	//b-Se debe llevar la frecuencia del ADC a 500kHz
	ADC0->CTRL &= ~ADC_CTRL_CLKDIV_MASK;
	ADC0->CTRL |= ADC_CTRL_CLKDIV((frecuencia / 500000U) - 1U);
	/* Clear the LPWR bit. */
	ADC0->CTRL &= ~ADC_CTRL_LPWRMODE_MASK;

	/* Start ADC self-calibration. */
	ADC0->CTRL |= ADC_CTRL_CALMODE_MASK;
	/* Delay de 300us*/
	DelayADC = 2;
	while(DelayADC);
	if (ADC_CTRL_CALMODE_MASK == (ADC0->CTRL & ADC_CTRL_CALMODE_MASK))
	{
		/* Restore the contents of the ADC CTRL register. */
		ADC0->CTRL = temporal;
		/*Timeout de calibración*/
		while(1);
	}
	/* Restore the contents of the ADC CTRL register. */
	ADC0->CTRL = temporal;
}


/*
 * No funciona la calibración
 * No interrumpe
 * VErificar los bits en cada configuración
 *
 * **/

// Para disparo por sw hay que configurar la fuente de trigger en SEQA_CTRL y SEQB_CTRL en 0
// Luego de habilitar la secuencia, el ADC convierte al escribir el bit START
// En la misma escritura de SEQ_ENA, se pueden escribir TRIGPOL y START
// Cuidar que no se modifiquen TRIGPOL y SEQ_ENA en la próxima escritura de START
// El valor d econversión será: (4095 x VIN- VREFN)/(VREFP - VREFN)
// Para disparar una conversión por SW de un canal:
// 1-Habilitar la función analógica del pin correspondiente al canal que se desea usar
// 2-Configurar el CLK a 25MHz y CLKDIV a 0 para 1MSa/sen ADC_CTRL
// 3-Elegir el canal del ADC a usar usando los bits CHANNELS en SEQA_CTRL
// 4-Elegir TRIGPOL en 1 y SEQA_ENA a 1 en SEQA_CTRL
// 5-Elegir START en 1 en SEQA_CTRL
// 6-Leer el resultado en DAT1


void ADC_Init(void){

	//uint32_t temporal;

	SYSCON->SYSAHBCLKCTRL0 |= SYSCON_SYSAHBCLKCTRL0_SWM_MASK;
	// 4-Configura SWM
    SWM0->PINENABLE0 &= ~SWM_PINENABLE0_ADC_0_MASK;
    // 5-Desactiva clk de SWM
	SYSCON->SYSAHBCLKCTRL0 &= ~SYSCON_SYSAHBCLKCTRL0_SWM_MASK;

	// 1-Elige FRO como clk de ADC
	SYSCON->ADCCLKSEL &= ~(uint32_t)(0x03);
	// 2-Setea divisor de ADC en 1
	SYSCON->ADCCLKDIV |= (uint32_t)(0x01);

	// 3-Enciende ADC
	SYSCON->PDRUNCFG &= ~SYSCON_PDRUNCFG_ADC_PD_MASK;
	// 3-Habilita clock del ADC
	SYSCON->SYSAHBCLKCTRL0 |= SYSCON_SYSAHBCLKCTRL0_ADC_MASK;

	calibraADC();

    // Modo Sincrónico de clock
    ADC0->CTRL &= ~(uint32_t)ADC_CTRL_ASYNMODE_MASK;

    // Divisor de clock 1
    ADC0->CTRL |= (uint32_t)DEMO_ADC_CLOCK_DIVIDER;

    // Modo Low Power off
    ADC0->CTRL &= ~(uint32_t)ADC_CTRL_LPWRMODE_MASK;

    // Configura canal SeqA
    ADC0->SEQ_CTRL[0] |= (1 << DEMO_ADC_SAMPLE_CHANNEL_NUMBER);
    // Configura el trigger para sw trigger
    ADC0->SEQ_CTRL[0] &= ~ADC_SEQ_CTRL_TRIGGER_MASK;
    // Polaridad del trigger positiva
    ADC0->SEQ_CTRL[0] |= ADC_SEQ_CTRL_TRIGPOL_MASK;
    // Bypass deshabilitado
    ADC0->SEQ_CTRL[0] &= ~ADC_SEQ_CTRL_SYNCBYPASS_MASK;
    // No single step
    ADC0->SEQ_CTRL[0] &= ~ADC_SEQ_CTRL_SINGLESTEP_MASK;
    // Una intrrupción por secuencia
    ADC0->SEQ_CTRL[0] |= ADC_SEQ_CTRL_MODE_MASK;
    // Habilita secuencia
    ADC0->SEQ_CTRL[0] |= ADC_SEQ_CTRL_SEQ_ENA_MASK;

    // Activo int
    ADC0->INTEN |= ADC_INTEN_SEQA_INTEN_MASK;
	NVIC->ISER[0] |= (uint32_t) (0x01 << ADC0_SEQA_IRQn);						// Habilito interrupciones globales

	// Convierte
    ADC0->SEQ_CTRL[0] |= ADC_SEQ_CTRL_START_MASK;
//    while(ADC0->FLAGS & ADC_FLAGS_SEQA_INT_MASK);
//    temporal = ADC0->SEQ_GDAT[0];

}

void ADC_SEQA_IRQHandler(void){
	// Limpia flag de int SACAR
	ADC0->FLAGS |= (1<<28);
	valorADC = ADC0->SEQ_GDAT[0];
	valorADC &= 0x0000FFF0;
	valorADC >>= 4;

	// Dispara conversión
    ADC0->SEQ_CTRL[0] |= ADC_SEQ_CTRL_START_MASK;
}
/*
 * Tambien se puede leer el valorADC de forma directa
 * Oscuridad suele ser 2800 e iluminado 1000, pero habria que configurarlo
 * segun la habitacion, por eso existen las variables min_luz y max_luz*/

int NivelLuz(int valorADC){ //Retorna de 0 a 100 (0 oscuro / 100 iluminado)
	int aux;
	aux = valorADC;
	aux -= min_luz;
	aux *= 100;
	aux /= max_luz;
	return (100 - aux);
}

void Chequeo_Luz(void){
	nivel_luz = valorADC;
	if(nivel_luz > config[0] + histeresis){ //Si se supera el nivel de luz (hay iluminacion)
		if(flag_oscu == 1){
			flag_oscu = 0;	// + 10 es la histeresis
			Transmitir("#l0$", 4);
		}
	}
	if(nivel_luz < config[0] - histeresis){//Si se supera el nivel de luz (hay oscuridad)
		if(flag_oscu == 0){
			flag_oscu = 1; // - 10 es la histeresis
			Transmitir("#l1$", 4);
		}
	}
}
