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
#ifndef MICRO_CONFIG_H_
#define MICRO_CONFIG_H_

#ifndef F_CPU
#define F_CPU 1000000UL //1MHz Clock frequency
#endif

#ifndef NULL
#define NULL (void *)0
#endif

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#define GLOBAL_INTERRUPT_ENABLE() SET_BIT(SREG,7)
#endif /* MICRO_CONFIG_H_ */
