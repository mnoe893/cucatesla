/*
 * mde_mov.h
 *
 *  Created on: 3 nov. 2022
 *      Author: Magdalena
 */

#ifndef MDE_MOV_H_
#define MDE_MOV_H_

#define ang_izq 30000 //"angulo" para el pwm que lo deja para la izquierda revisar
#define ang_der 60000 //"angulo" para el pwm que lo deja para la dererecha
#define ang_ade 43000 //"angulo" .......
#define Adelante 1
#define Atras 0
#define ON 0
#define OFF 1
#define DIST_LIMITE 5 //5cm

enum{ESPERA, ATRAS, IZQUIERDA, DERECHA, ADELANTE, TRUCO, NEUTRO, ESQUIVAR, DOBLAR, RETROCEDER, EMERGENCIA};

void mde_mov_user(void);
void mde_doblar_user(void);
void mde_avanzar_user(void);
void mde_mov_autonomo(void);
uint8_t buscar_lado(void);
uint8_t Sensor(uint8_t);
void doblar(uint8_t lado);
void moverse(uint8_t direc);
void frenar(void);
void mde_mov(void);
void cambiar_velocidad(void);

#endif /* MDE_MOV_H_ */
