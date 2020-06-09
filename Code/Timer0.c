 /******************************************************************************
 *
 * Module: Lcd
 *
 * File Name: lcd.h
 *
 * Description: lcd header file
 *
 * Author: Ahmed Mohamed
 *
 *******************************************************************************/

/*********************************************************************************
* 									Drivers										 *
 *********************************************************************************/
#include"timer0.h"
/*********************************************************************************
* 									Global Variables							 *
 *********************************************************************************/
static void (*volatile g_T0CompareInterruptFunc_ptr)(void) = NULL;
static void (*volatile g_T0OverflowInterruptFunc_ptr)(void) = NULL;
uint8 g_t0tick = 0;
/*********************************************************************************
* 									Functions Definition						 *
 *********************************************************************************/
void TIMER0_setCallBackCompareMode(void (*a_ptr)(void))
{
	g_T0CompareInterruptFunc_ptr = a_ptr;
}
void TIMER0_setCallBackOverflowMode(void (*a_ptr)(void))
{
	g_T0OverflowInterruptFunc_ptr = a_ptr;
}
void TIMER0_init(const TIMER0_config_struct * config_ptr)
{
	TCCR0 = 0;
	TCCR0 = config_ptr->mode;
	if(config_ptr->mode == NORMAL || config_ptr->mode == CTC)
	{
		SET_BIT(TCCR0 , FOC0);
	}
	else
	{
		CLEAR_BIT(TCCR0 , FOC0);
	}
	TCCR0 |= ((config_ptr->output_mode) << 4) | (config_ptr->clock);
	TCNT0 = config_ptr->initial_value;
	OCR0 = config_ptr->compare_value;
	if(config_ptr->output_mode != NORMAL_OUTPUT )
	{
		SET_BIT(DDRB , 3);
		CLEAR_BIT(PORTB , 3);
	}
	TIMSK |= config_ptr->overflow_interrupt | ((config_ptr->compare_interrupt)<<OCIE0);
}
void TIMER0_setCompareValue(uint8 value)
{
	OCR0 = value;
}
void TIMER0_stop(void)
{
	CLEAR_BIT(TCCR0 , 0);
	CLEAR_BIT(TCCR0 , 1);
	CLEAR_BIT(TCCR0 , 2);
}
/*********************************************************************************
* 								Interrupt service routines							 *
 *********************************************************************************/
ISR(TIMER0_COMP_vect)
{
	if(g_T0CompareInterruptFunc_ptr != NULL)
	{
		g_T0CompareInterruptFunc_ptr();
	}
}
ISR(TIMER0_OVF_vect)
{
	if(g_T0OverflowInterruptFunc_ptr != NULL)
	{
		g_T0OverflowInterruptFunc_ptr();
	}
}
