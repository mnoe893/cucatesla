/*
 * timers.h
 *
 *  Created on: 3 nov. 2022
 *      Author: marti
 */

#include "cucateslainc.h"
/*
volatile 	uint32_t Tmr_Run		[ N_TIMERS ];
volatile 	uint8_t  TMR_Events	[ N_TIMERS ];
void 	 	(* TMR_handlers 		[N_TIMERS]) (void);
volatile 	uint8_t  TMR_StandBy	[ N_TIMERS ];
volatile 	uint8_t  Tmr_Base		[ N_TIMERS ];


void TimerStart(uint8_t event, uint32_t time, Timer_Handler handler , uint8_t base )
{
    switch ( base )
    {
        case DEC:
            time = DECIMAS;
            break;
        case SEG:
            time= ( SEGUNDOS * DECIMAS );
            break;
        case MINU:
            time = ( MINUTOS* SEGUNDOS * DECIMAS );
            break;
    }

    Tmr_Base[event] = base;

    if(time != 0)    //el tiempo no es 0, lo cargo
    {
        Tmr_Run[event] = time;
        TMR_Events[event] = 0;
    }
    else    //el tiempo es cero, el timer vence automáticamente
    {
        Tmr_Run[event] = 0;
        TMR_Events[event] = 1;
    }
    TMR_handlers[event] = handler;
}

void TimerStop (uint8_t Ev)
{
      Tmr_Run[ event ] = 0;
	TMR_Events[ event ] = 0;
	TMR_handlers[ event ] = NULL;
	Tmr_Base[ event ] = 0;
	TMR_StandBy[ event ] = RUN;
}

void StandByTimer( uint8_t event , uint8_t accion)
{
	TMR_StandBy[ event ] = accion;
}

*/
