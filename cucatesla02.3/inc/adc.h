/*
 * adc.h
 *
 *  Created on: 23 nov. 2022
 *      Author: Magdalena
 */

#ifndef ADC_H_
#define ADC_H_

void ADC_Init(void);

#define DEMO_ADC_CLOCK_DIVIDER 1U
#define DEMO_ADC_SAMPLE_CHANNEL_NUMBER 0U
#define histeresis 25

int NivelLuz(int valorADC);
void Chequeo_Luz(void);
#endif /* ADC_H_ */
