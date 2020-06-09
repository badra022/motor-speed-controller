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

#ifndef TIMER0_H_
#define TIMER0_H_
/*********************************************************************************
 * 								Libraries										 *
 *********************************************************************************/
#include"micro_config.h"
#include"common_macros.h"
#include"std_types.h"

/*********************************************************************************
* 								Types Declarations							 *
 *********************************************************************************/
extern uint8 g_t0tick;
typedef enum
{
	NORMAL = 0x00 ,
	PWM_PHASE_CORRECT = 0x40 ,
	CTC = 0x08 ,
	FAST_PWM = 0x48 ,
}TIMER0_mode;

typedef enum
{
	NORMAL_OUTPUT ,
	TOGGLE_OUTPUT,
	CLEAR_OUTPUT ,
	SET_OUTPUT ,
}TIMER0_Compare_output_mode;

typedef enum
{
	T0_NON , T0_F_CPU , T0_F_CPU_8 , T0_F_CPU_64 , 	T0_F_CPU_256 , T0_F_CPU_1024 ,
	T0_PIN_FALLING_EDGE ,
	T0_PIN_RAISING_EDGE ,
}TIMER0_clock;
/*
	 * configuration structure of timer0
	 * type : TIMER0_config_struct
	 * 1. mode
	 * 2. output mode
	 * 3. clock
	 * 4. compare interrupt
	 * 5. overflow interrupt
	 * 6. compare value
	 * 7. initial value
	 */
typedef struct
{
	TIMER0_mode mode;
	TIMER0_Compare_output_mode output_mode;
	TIMER0_clock clock;
	uint8 compare_interrupt;
	uint8 overflow_interrupt;
	uint8 compare_value;
	uint8 initial_value;
}TIMER0_config_struct;

/*********************************************************************************
* 								Function Declarations							 *
 *********************************************************************************/
void TIMER0_init(const TIMER0_config_struct * config_ptr);
void TIMER0_setCompareValue(uint8 value);
void TIMER0_stop(void);
void TIMER0_setCallBackCompareMode(void (*a_ptr)(void));
void TIMER0_setCallBackOverflowMode(void (*a_ptr)(void));
#endif /* TIMER0_H_ */
