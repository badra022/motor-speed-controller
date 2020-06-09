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
#include"lcd.h"
#include"adc.h"
#include"timer0.h"
#include"dc_motor.h"
#include"external_int.h"
/*********************************************************************************
* 								MAIN APPLICATION										 *
 *********************************************************************************/
uint8 speed = 0;
void ADC_speedConversion(void)
{
	speed = ((1023 - current_reading)/1023)*255;
}
/*void setSpeed(void)
{
	TIMER0_setCompareValue(speed);
}*/
int main(void)
{
	/*initialization code*/
	INT1_init(INT1_FALLING , PULLUP);
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
	TIMER0_config_struct T0_config = { FAST_PWM , CLEAR_OUTPUT , T0_F_CPU , ENABLE
			 , ENABLE , 100 , 0};
	TIMER0_init(&T0_config);
	LCD_init();
	/*
	 * configuration structure for adc module
	 * type :  ADC_config_struct
	 * 1. reference voltage (AREF , AVCC , _2_56V )
	 * 2. POLLING or INTERRUPT
	 * 3. pre-scaler (ADC_F_CPU_2_2 , ADC_F_CPU_2,4,8,16,32,64,128)
	 */
	ADC_config_struct ADC_config = {AREF , INTERRUPT , ADC_F_CPU_8 };
	ADC_init(&ADC_config);
	INT1_setCallBack(DCMOTOR_toggleMove);
	ADC_setCallBack(ADC_speedConversion);
	//LCD_displayString("ADC value= ");
	DCMOTOR_init();
	DCMOTOR_move();
	GLOBAL_INTERRUPT_ENABLE();
	//TIMER0_setCallBackCompareMode(setSpeed);
	/*super loop*/
	while(TRUE)
	{
		/*Application code*/
		ADC_readChannel(&ADC_config , ADC0);
		LCD_goToColRow(0 , 0);
		LCD_displayInt(current_reading);
		T0_config.compare_value = speed;
		TIMER0_init(&T0_config);
	}
}
