/*
 * ctimer.h
 *
 *  Created on: 18 oct. 2022
 *      Author: juamm
 */

#ifndef CTIMER_H_
#define CTIMER_H_

#define valor_timer CTIMER0->CR[0]
#define match_on 	CTIMER0->TCR |= (uint32_t)(0x1<<0U)
#define match_off	CTIMER0->TCR &= (uint32_t)~(0x1<<0U)

void inicializar_ctimer(void);


#endif /* CTIMER_H_ */
