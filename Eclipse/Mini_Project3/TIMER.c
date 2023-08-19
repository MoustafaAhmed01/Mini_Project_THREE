/******************************************************************************
 *
 * Module: Common - Platform Types Abstraction
 *
 * File Name: TIMER.c
 *
 * Description: types for AVR
 *
 * Date Created: 4/10/2022
 *
 * Author: Moustafa Ahmed
 *
 *******************************************************************************/

/**-------------------------INCLUDES Section------------------------**/
#include "Libraries.h"
#include "GPIO.h"
#include "TIMER.h"

/**-------------------------Function Definition Section-------------**/

/*
 * Initializing Timer0_PWM
 */
void Timer0_PWM_Init(TIMER_ConfigType *Config_Ptr)
{
	TCNT0 = 0; /* Set Timer Initial Value to 0 */

	/* Configure PB3/OC0 as output pin --> pin where the PWM signal is generated from MC */
	GPIO_setupPinDirection(PWM0_PORT_ID, PWM0_PIN_ID, PIN_OUTPUT);

	/* Configure timer control register
	 * 1. Fast PWM mode FOC0=0
	 * 2. Fast PWM Mode WGM01=1 & WGM00=1
	 * 3. Clear OC0 when match occurs (non inverted mode) COM00=0 & COM01=1
	 * 4. clock = Dependent on the user
	 */
	TCCR0 = (1<<WGM00) | (1<<WGM01) | (1<<COM01);
	TCCR0 |= Config_Ptr->prescaler;
}


/*
 * Setting Timer0_PWM
 */
void Timer0_PWM_Activate(uint8 SetDuty)
{
	TCNT0 = 0; /* Set Timer Initial Value to 0 */
	OCR0  = SetDuty; /* Set Compare Value */
}

/**---------------------------------END-----------------------------**/
