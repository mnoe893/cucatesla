/*
 * timers.h
 *
 *  Created on: 3 nov. 2022
 *      Author: marti
 */

#ifndef TIMERS_H_
#define TIMERS_H_


#define 	DEC			0
#define 	SEG			1
#define 	MIN			2
#define 	DECIMAS	40
#define 	SEGUNDOS	400
#define 	MINUTOS	24000
#define 	RUN			0
#define 	PAUSE		1

/*
void TimerStart(uint8_t event, uint32_t time, Timer_Handler handler , uint8_t base );
void TimerStop(uint8_t event); 		//apago un timer antes de que venza (#evento)
void Tmrclose(void); 		//apaga los timers de una vez
void SetTimer(uint8_t event , uint32_t t); 	//ajusto timer al vuelo
void GetTimer(uint8_t event); 		//leo timer al vuelo
void StanByTimer(uint8_t evento, Timer_Handler accion);
*/
#endif /* TIMERS_H_ */
