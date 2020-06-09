 /******************************************************************************
 *
 * Module: adc
 *
 * File Name: adc.h
 *
 * Description: adc driver header file
 *
 * Author: Ahmed Mohamed
 *
 *******************************************************************************/

#ifndef ADC_H_
#define ADC_H_
/*********************************************************************************
 * 								Libraries										 *
 *********************************************************************************/
#include"micro_config.h"
#include"common_macros.h"
#include"std_types.h"
/*********************************************************************************
 * 								Variables Declaration							 *
 *********************************************************************************/
extern volatile uint16 current_reading;
/*********************************************************************************
* 								Types Declarations								 *
 *********************************************************************************/
typedef enum
{
	AREF,
	AVCC,
	_2_56v = 3,
}ADC_voltage_reference;

typedef enum
{
	ADC0 ,
	ADC1 ,
	ADC2 ,
	ADC3 ,
	ADC4 ,
	ADC5 ,
	ADC6 ,
	ADC7 ,
}ADC_channel;

typedef enum
{
	POLLING , INTERRUPT ,
}ADC_conversion_complete;

typedef enum
{
	ADC_F_CPU_2 , ADC_F_CPU_2_2 , ADC_F_CPU_4 , ADC_F_CPU_8 ,
	ADC_F_CPU_16 , ADC_F_CPU_32 , ADC_F_CPU_64 , ADC_F_CPU_128 ,
}ADC_prescaler;
/*
 * configuration structure for adc module
 * type :  ADC_config_struct
 * 1. reference voltage (AREF , AVCC , _2_56V )
 * 2. POLLING or INTERRUPT
 * 3. prescaler (ADC_F_CPU_2_2 , ADC_F_CPU_2,4,8,16,32,64,128)
 */
typedef struct
{
	ADC_voltage_reference 	ref;
	ADC_conversion_complete type;
	ADC_prescaler			prescaler;
}ADC_config_struct;
/*********************************************************************************
* 								Functions Declaration							 *
 *********************************************************************************/
/*
 * Description: Function to set the Call Back function address.
 */
void ADC_setCallBack(void(*a_ptr)(void));
/*
 * Description: Function to initialize the ADC Driver
 * 1.set the reference voltage
 * 2.clear the left adjust bit in ADMUX
 * 3.enable the adc module by ADEN bit
 * 4.set the conversion type polling or interrupt
 * 5.set prescaler
 */
void ADC_init(const ADC_config_struct * config_ptr);
/*
 * Description: Function to start conversion of signal
 * 1. set the channel you want to convert for
 * 2. start conversion by setting ADSC bit in ADCSRA
 */
void ADC_readChannel(const ADC_config_struct * config_ptr , ADC_channel a_channel);
#endif /* ADC_H_ */
