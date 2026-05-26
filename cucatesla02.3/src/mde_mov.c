/*
 * mde_mov.c
 *
 *  Created on: 3 nov. 2022
 *      Author: Magdalena
 */
#include "cucateslainc.h"


extern volatile uint16_t t_doblar;
extern volatile uint8_t comando_mov,comando_dob;
extern volatile uint8_t flag_oscu;
volatile uint8_t EstadoSensor[4]={1,1,1,1};
extern volatile uint16_t autonomo[2];//= {modo, pausa}
extern volatile uint16_t config[4]; //= {nivel luz, frecnciadlb, distmin, velocidad}
extern volatile uint32_t AnchoDoblar, AnchoBarrido, AnchoVelocidad;
extern volatile uint8_t velocidad;



void mde_mov_autonomo(void){

	static uint8_t estado = NEUTRO;
	uint8_t lado;
    switch (estado) {
        case NEUTRO:
		//if(flag_oscu)
			if(!Sensor(ADELANTE)){ // Si se detecta un obstaculo...
			estado = ESQUIVAR;
			}
			else if(t_doblar == 0){
				lado = buscar_lado();
				t_doblar = config[2];;
				if(lado != -1){ // Si no puede doblar, ignora que el timer haya vencido
					//doblar(lado);
					if(lado == DERECHA )
					{
						AnchoDoblar = DerechaMax;
					}
					else
					{
						AnchoDoblar = IzquierdaMax;
					}
					estado = DOBLAR;
					t_doblar = 1500; //Dobla minimo por 1,5 segundos
				}
			}
			else moverse(ADELANTE);
		//}
		//else frenar();
        break;
        case ESQUIVAR:
// Lee los costados
        	if((lado = buscar_lado()) != -1){
        		moverse(ADELANTE);
        		//doblar(lado);
        		if(lado == DERECHA )
				{
					AnchoDoblar = DerechaMax;
				}
				else
				{
					AnchoDoblar = IzquierdaMax;
				}
        		estado = DOBLAR;
        		t_doblar = 1500; //Dobla minimo por 1,5 segundos
        	}
// Lee atras
            else if(Sensor(ATRAS)){
            	moverse(ATRAS);
                estado = RETROCEDER;
            }
// Si se queda sin opciones, entra en emergecia
            else{
            	Transmitir("#e1$", 4);
                estado = EMERGENCIA;
            }
        break;
        case DOBLAR:
        	//frenar();
        	if(Sensor(ADELANTE) && t_doblar == 0){

        		//doblar(ADELANTE);
        		AnchoDoblar = Centro;
        		moverse(ADELANTE);
        		estado = NEUTRO;
        	}

        	break;
        case RETROCEDER:
        	if((lado = buscar_lado()) != -1){
        		//doblar(lado);
        		if(lado == DERECHA )
				{
					AnchoDoblar = DerechaMax;
				}
				else
				{
					AnchoDoblar = IzquierdaMax;
				}
        		estado = DOBLAR;
        		t_doblar = 1500; //Dobla minimo por 1,5 segundos
        	}
        	else if(!Sensor(ATRAS)){
        		Transmitir("#e1$", 4);
        		estado = EMERGENCIA;
        	}
        break;
        case EMERGENCIA:
			frenar();
			if(comando_mov == 'm' || !GetPIN(TECLA_USR)){
				lado = buscar_lado();
				if(lado != -1){
					//doblar(lado);
					if(lado == DERECHA )
					{
						AnchoDoblar = DerechaMax;
					}
					else
					{
						AnchoDoblar = IzquierdaMax;
					}
					estado = DOBLAR;
					t_doblar = 1500; //Dobla minimo por 1,5 segundos
					Transmitir("#e0$", 4);
				}
				else if(Sensor(ATRAS)){
					estado = RETROCEDER;
					moverse(ATRAS);
					Transmitir("#e0$", 4);
				}
			}
        break;
        default: estado = NEUTRO;
    }
}

uint8_t buscar_lado(void){
	uint8_t lado = -1;
    if(AnchoBarrido <= Centro){ // Si el barrido esta en el lado de izquierda, primero mira izquierda
    	if(Sensor(IZQUIERDA)){ // En el otro caso, mira a derecha (chance de 50/50)
    		lado = IZQUIERDA;
    	}
    }
	else if(Sensor(DERECHA)){
		lado = DERECHA;
	}
	else if(Sensor(IZQUIERDA)){ //Si derecha esta ocupado, chequea izquierda
		lado = IZQUIERDA;
	}
    return lado;
}


void doblar(uint8_t lado){
	int angulo[3] = {ang_izq, ang_der, ang_ade};
	AnchoDoblar = angulo[lado-IZQUIERDA];
}

void moverse(uint8_t direc){ //Adelante o Atras
	frenar(); //Frenamos por un instante para no prender ambos pines
	//del puente h a la vez y quemarlo
	if(direc == ADELANTE){SetPIN(MotorAvanzar, 1);}
	else{SetPIN(MotorRetroceder, 1);}
}

void frenar(void){
	SetPIN(MotorAvanzar, 0);
	SetPIN(MotorRetroceder, 0);
}

uint8_t Sensor(uint8_t a){
	uint8_t retorno=-1;

	switch(a)
	{
	case ADELANTE: retorno= EstadoSensor[1]; break;
	case ATRAS: retorno= EstadoSensor[3]; break;
	case IZQUIERDA: retorno= EstadoSensor[0]; break;
	case DERECHA: retorno= EstadoSensor[2]; break;
	}
	return retorno;
}

void mde_mov_user(void){
	mde_avanzar_user();
	mde_doblar_user();
}

void mde_avanzar_user(void){
	static uint8_t estado = ESPERA;
	switch(estado){
		case ESPERA:
			if(comando_mov == 'w'){
				frenar();
				SetPIN(MotorAvanzar,1);
				estado = ADELANTE;
				break;
			}
			if(comando_mov == 's'){
				frenar();
				SetPIN(MotorRetroceder,1);
				estado = ATRAS;
				break;
			}
			frenar();
			break;
		case ADELANTE:
			if(comando_mov == 0){ //Tambien se podria hacer (!comando_mov) ya que cuando
				frenar();          //Se deja se presionar una tecla comando_mov vale 0 por un instante
				estado = ESPERA;
			}
			break;
		case ATRAS:
			if(comando_mov == 0){
				frenar();
				estado = ESPERA;
			}
			break;
		default: estado = ESPERA;
			break;
	}
}

void mde_doblar_user(void){
	static uint8_t estado = ESPERA;

	switch(estado){
		case ESPERA:
			if(comando_dob == 'd'){
				AnchoDoblar=DerechaMax;
				estado = DERECHA;
			}
			else if(comando_dob == 'a'){
				AnchoDoblar=IzquierdaMax;
				estado = IZQUIERDA;
			}
			break;
		case DERECHA:
			if(comando_dob == 0){
				AnchoDoblar=Centro;
				estado =ESPERA;
			}
			break;
		case IZQUIERDA:
			if(comando_dob == 0){
				AnchoDoblar=Centro;
				estado = ESPERA;
			}
			break;
		default: estado = ESPERA;
			break;
	}

}

void cambiar_velocidad(void){
	int new_vel;
	switch (velocidad) {
		case 1:
			new_vel = 8000;
			break;
		case 2:
			new_vel = 12000;
			break;
		case 3:
			new_vel = 20000;
			break;
	}
	if(AnchoVelocidad != new_vel)
		AnchoVelocidad = new_vel;
}

void mde_mov(void){
	cambiar_velocidad();
	if(autonomo[0] == 1){
		if(autonomo[1] == 1){
			frenar();
		}
		else{
			mde_mov_autonomo();
		}
	}
	else{
		mde_mov_user();
	}
}
