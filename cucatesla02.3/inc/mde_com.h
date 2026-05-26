/*
 * mde_com.h
 *
 *  Created on: 13 oct. 2022
 *      Author: Martin
 */


#ifndef MDE_COM_H_
#define MDE_COM_H_

//definiciones
#define NvlLuz 10
#define FrDoblar 20
#define DistMin 30
#define Vel 40
#define WoN 1
#define WoFF 11
#define SoN 21
#define SoFF 31
#define AoN 41
#define AoFF 51
#define DoN 61
#define DoFF 71
#define Emerg 72
#define ModAuto 81
#define ModUsr 91
#define OjoN 101
#define OjoFF 111
#define Pause 121
#define Play 131

void mde_com(void);
void mde_recepcion(void);
int leerTrama(void);

#endif /* MDE_COM_H_ */


