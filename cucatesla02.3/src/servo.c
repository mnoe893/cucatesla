/*
 * servo.c
 *
 *  Created on: 2 nov. 2022
 *      Author: marti
 */
#include "cucateslainc.h"
extern volatile uint16_t DelayPeriod;
extern volatile uint16_t DelayHigh;

//un posible llamado a la funcion es simple como pwm_on(servo0,period);
void servo_on(uint32_t puerto, uint32_t pin, uint32_t period){
	if(period != 0){
		if(DelayHigh == 0){
			//GPIO->CLR[puerto] = (uint32_t)(1 << pin); //Cuando termina, apaga
			SetPIN(puerto,pin,0);
		}
		if(DelayPeriod == 0){
			//GPIO->SET[puerto] = (uint32_t)(1 << pin); //Cuando termina, prende
			SetPIN(puerto,pin,1);
			DelayPeriod = 265;
			DelayHigh = (period +10); //La minima unidad del stimer es 10 milisegundos
		}
	}
	else{SetPIN(puerto,pin,0);} //Si vale 0, debe estar apagado
}

void servo_off(uint32_t puerto, uint32_t pin){
	//GPIO->CLR[puerto] = (uint32_t)(1 << pin);
	SetPIN(puerto,pin,0);
}
/*
void pwm_servo(uint32_t giro, uint32_t period, uint32_t puerto, uint32_t pin)
{
	static int bloqueo_0 = 0, bloqueo_1 = 0;
	static int ciclo = CENTRO;
	static int vueltas = INICIO;


}*/
///codigo alternativo
/*

#include "Servo.h"

void servoOPEN(void){
	setPIN(SERVO, OFF);
	TimerStart(0, OPEN, mMS, handler0);
	TimerStart(2, 500, MS, handler4);
}

void servoCLOSE(void){
	setPIN(SERVO, OFF);
	TimerStart(1, CLOSE, mMS, handler2);
	TimerStart(2, 500, MS, handler4);
}

*/
