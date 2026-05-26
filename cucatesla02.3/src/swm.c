/*
 * FW_SWM.c
 *
 *  Created on: 10 may. 2022
 *      Author: gos
 */
#include "cucateslainc.h"

/*!
 * Asignación de periféricos digitales a los pines.
 *
 * Esta función elige un pin (Designado por su números de GPIO port y bit) para una función.
 *
 * param dirección base de SWM.
 * param función móvil.
 * param swm_port_pin cualquier pin con GPIO port y bit number.
 */

/**
	\fn  	void SWM_SetMovablePinSelect(swm_select_movable_t func, swm_port_pin_type_t swm_port_pin)
	\brief 	Asignación de función
 	\author Ing. Gabriel Soccodato
 	\date 	19 de Setiembre de 2022
 	\param 	swm_select_movable_t func, es un enum función
 			swm_port_pin_type_t swm_port_pin
 	\return void
*/
void SWM_SetMovablePinSelect(swm_select_movable_t func, swm_port_pin_type_t swm_port_pin)
{
    uint32_t temp;
    uint32_t pinassign = 0;
    uint32_t shifter   = 0;

    pinassign = (uint32_t)func / 4U;
    shifter   = ((uint32_t)func % 4U) * 8U;

    temp = SWM0->PINASSIGN_DATA[pinassign];
    temp &= ~(0xFFUL << (shifter));
    temp |= ((uint32_t)swm_port_pin << shifter);
    SWM0->PINASSIGN_DATA[pinassign] = temp;
}
