/*
 * inicializacion.c
 *
 *  Created on: 13 oct. 2022
 *      Author: juamm
 */
#include "cucateslainc.h"
extern volatile uint32_t SystemCoreClock;

void inic_pines(void){
	SYSCON->SYSAHBCLKCTRL0 |= SYSCON_SYSAHBCLKCTRL0_GPIO0_MASK | SYSCON_SYSAHBCLKCTRL0_GPIO1_MASK;
	//no se que son
	SetDIR(0,8, SALIDA);
	SetPINMODE_OUT(8, PUSH_PULL);
	//pwm (servo)
	SetDIR(ServoSensor, 1);
	SetPINMODE_OUT(PIN_SERVO_SEN, PUSH_PULL);

	SetDIR(ServoDoblar, 1);
	SetPINMODE_OUT(PIN_SERVO_DOB, PUSH_PULL);

	SetDIR(0,15,1); //PWM para regular velocidad motor
	SetPINMODE_OUT(PIN_SERVO_DOB, PUSH_PULL);
	//hcsr04 (sensores)
	SetPIN(TRIGGER0, 0);
	SetDIR(TRIGGER0, SALIDA);
	SetPINMODE_OUT(PIN_TRIGGER0, PUSH_PULL);

	//SetDIR(ECHO0, 0);
	//SetPINMODE_IN(PIN_ECHO0, PULL_UP); se inicializan solos en el ctimer
	SetPIN(TRIGGER0, 0);
	SetDIR(TRIGGER1, SALIDA);
	SetPINMODE_OUT(PIN_TRIGGER1, PUSH_PULL);

	//SetDIR(ECHO1, 0);
	//SetPINMODE_IN(PIN_ECHO1, PULL_UP); se inicializan solos en el ctimer
	//Motor
	SetDIR(MotorAvanzar, 1);
	SetPINMODE_OUT(PIN_MOTOR_AVA, PUSH_PULL);

	SetDIR(MotorRetroceder, 1);
	SetPINMODE_OUT(PIN_MOTOR_RET, PUSH_PULL);
	SetPIN(LED_VERDE, 1);

	//leds del lpc
	SetDIR(LED_VERDE, SALIDA);
	SetPINMODE_OUT(PIN_LED_VERDE, PUSH_PULL);

	SetPIN(LED_AZUL, 0);
	SetDIR(LED_AZUL, SALIDA);
	SetPINMODE_OUT(PIN_LED_AZUL, PUSH_PULL);

	SetPIN(LED_ROJO, 0);
	SetDIR(LED_ROJO, SALIDA);
	SetPINMODE_OUT(PIN_LED_ROJO, PUSH_PULL);

	//vcc
	SetPIN(0,9, 1);
	SetDIR(0,9, SALIDA);
	SetPINMODE_OUT(IOCON_INDEX_PIO0_9, PUSH_PULL);

	//ldr (luz)
	SetPIN(LDR, 0);
	SetDIR(LDR, 0);
	SetPINMODE_IN(18, PULL_UP);
}
void inicializacion(void)
{
	Inic_OSC();
	inic_pines();
	inic_uart0();
	inicializar_ctimer();
	MRT_Inic();
	SysTick_Config(SystemCoreClock/1000);
	//ADC_Init();
}
