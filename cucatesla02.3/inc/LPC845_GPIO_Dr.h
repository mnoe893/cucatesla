/*
 * LPC845_GPIO_Dr.h
 *
 *  Created on: 10 ene. 2022
 *      Author: gos
 */

#ifndef LPC845_GPIO_DR_H_
#define LPC845_GPIO_DR_H_


#define SALIDA		1
#define ENTRADA 	0

#define NO_PULL		0x00
#define PULL_DOWN	0x01
#define PULL_UP		0x02
#define REP			0x03

#define PUSH_PULL	0x00
#define OPEN_DRAIN	0x01

#define PIN_LED_VERDE	IOCON_INDEX_PIO1_0
#define PIN_LED_AZUL	IOCON_INDEX_PIO1_1
#define PIN_LED_ROJO	IOCON_INDEX_PIO1_2
#define PIN_TRIGGER0	IOCON_INDEX_PIO0_31
#define PIN_ECHO0		IOCON_INDEX_PIO0_30
#define PIN_TRIGGER1	IOCON_INDEX_PIO0_28
#define PIN_ECHO1		IOCON_INDEX_PIO0_29
#define PIN_SERVO_SEN	IOCON_INDEX_PIO0_9
#define PIN_SERVO_DOB	IOCON_INDEX_PIO0_8
#define PIN_MOTOR_AVA	IOCON_INDEX_PIO0_16
#define PIN_MOTOR_RET	IOCON_INDEX_PIO0_17

//Ultra Delantero
#define TRIGGER0 0,31
#define ECHO0 0,30
//Ultra Trasero
#define TRIGGER1 0,28
#define ECHO1 0,29
//Servos
#define ServoSensor 0,9
#define ServoDoblar 0,8
//Motor
#define MotorAvanzar 0,16
#define MotorRetroceder 0,17
//LDR
#define LDR 0,7 //PIN ARBITRARIO, MODIFICAR

#define TRIG0_ON 		SetPIN(TRIGGER0,1)
#define TRIG0_OFF 		SetPIN(TRIGGER0,0)
#define TRIG1_ON 		SetPIN(TRIGGER1,1)
#define TRIG1_OFF 		SetPIN(TRIGGER1,0)

#define ServoSensor_ON 		SetPIN(ServoSensor,1)
#define ServoSensor_OFF 		SetPIN(ServoSensor,0)
#define ServoDoblar_ON 		SetPIN(ServoDoblar,1)
#define ServoDoblar_OFF 		SetPIN(ServoDoblar,0)

#define MotorAvanzar_ON 		SetPIN(MotorAvanzar,1)
#define MotorAvanzar_OFF 		SetPIN(MotorAvanzar,0)
#define MotorRetroceder_ON 		SetPIN(MotorRetroceder,1)
#define MotorRetroceder_OFF 	SetPIN(MotorRetroceder,0)

#define LED_VERDE	1,0
#define LED_AZUL	1,1
#define LED_ROJO	1,2
#define	TECLA_USR	0,4
#define	TECLA_ISP	0,12

#define LED_ROJO_ON		SetPIN(LED_ROJO,0)
#define LED_ROJO_OFF	SetPIN(LED_ROJO,1)
#define LED_ROJO_NOT	TogglePIN(LED_ROJO)


void SetPIN(uint32_t, uint32_t, uint32_t);
void SetDIR(uint32_t, uint32_t, uint32_t);
uint32_t GetPIN(uint32_t, uint32_t);
void SetPINMODE_IN(uint32_t, uint32_t);
void SetPINMODE_OUT(uint32_t, uint32_t);
void TogglePIN(uint32_t, uint32_t);

#endif /* LPC845_GPIO_DR_H_ */
