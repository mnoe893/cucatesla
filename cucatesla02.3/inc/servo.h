/*
 * servo.h
 *
 *  Created on: 2 nov. 2022
 *      Author: marti
 */

#ifndef SERVO_H_
#define SERVO_H_

void servo_on(uint32_t puerto, uint32_t pin, uint32_t period);
void servo_off(uint32_t puerto, uint32_t pin);

#endif /* SERVO_H_ */

///codigo alternativo
/*
#include "DR_Servo.h"
#include "Timers.h"

#define PERIOD 	20
#define CLOSE 	1	// 0,5 ms
#define OPEN 	3 	// 2,5 ms

void servoOPEN(void);
void servoCLOSE(void);
*/
