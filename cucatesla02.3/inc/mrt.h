/*
 * mrt.h
 *
 *  Created on: 23 nov. 2022
 *      Author: juamm y martin
 */

#ifndef MRT_H_
#define MRT_H_



#define DerechaMax 		49000
#define IzquierdaMax 	35000
#define Centro 			41000

#define PulsoBarrido 	100000
#define PulsoDoblar 	100000
#define PulsoVelocidad  20000

#define periodo 100000

void MRT_Inic(void);
void barrido_mrt(void);

#endif /* MRT_H_ */
