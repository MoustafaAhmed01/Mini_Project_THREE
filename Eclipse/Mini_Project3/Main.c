/******************************************************************************
 *
 * Module: Common - Platform Types Abstraction
 *
 * File Name: Main.c
 *
 * Description: types for AVR
 *
 * Date Created: 4/10/2022
 *
 * Author: Moustafa Ahmed
 *
 *******************************************************************************/

#include "Libraries.h"
#include "std_types.h"
#include "GPIO.h"
#include "LCD.h"
#include "ADC.h"
#include "lM35_TempSensor.h"
#include "DcMotor.h"
#include "TIMER.h"
/**-------------------------Defines-------------------------------**/

/**-------------------------Function Def Section------------------**/

void Initializing()
{
	/* Initializing Everything */
	{
		LCD_init(); /* LCD Initializing */
	}

	/*---------------------------------------------------------*/
	/*
	 * Setting the Configuration values for ADC
	 * Creating a member from the ADC_ConfigType structure
	 * Ref_Voltage will Internal 2.56v
	 * F_ADC = F_CPU/8
	 */
	{
		ADC_ConfigType Config;
		Config.ref_volt = Internal_Ref;
		Config.prescaler=F_ADC8;
		ADC_init(&Config);
	}

	/*---------------------------------------------------------*/
	{
		/*
		 * DcMotor Initializing
		 *
		 */
		DCMotor_init();
	}
	/*---------------------------------------------------------*/
	{
		/*
		 * TIMER0_PWM initialize
		 *Setting the Prescaler to F_CPU/8
		 */
		TIMER_ConfigType Config;
		Config.prescaler=F_TIMER8;
		Timer0_PWM_Init( &Config);
	}
	/*---------------------------------------------------------*/
}
/**-------------------------MAIN----------------------------------**/
int main(void)
{

	Initializing(); /* Initializing Everything */
	uint8 a_TempValue=0;
	while(1)
	{
		/* Reading the Temperature value using Pulling method */
		a_TempValue = LM35_getTemperature();

		/* Displaying on the screen
		 * Fan is "ON/OFF
		 */
		LCD_moveCursor(0, 3);
		LCD_displayString("Fan is ");

		/*---------------------------------------------------------*/
		/* Controlling the Motor speed */
		/* For less than 30C Turn on fan by 0% of it's total power */
		if( a_TempValue < 30)
		{
			DcMotor_Rotate(ClockWise,0);
			LCD_displayString("OFF");
		}
		/* For more than 30C Turn on fan by 25% of it's total power */
		else if( a_TempValue >= 30 && a_TempValue < 60)
		{
			DcMotor_Rotate(ClockWise,64);
			LCD_displayString("ON ");
		}
		/* For more than 60C Turn on fan by 50% of it's total power */
		else if( a_TempValue >= 60 && a_TempValue < 90)
		{
			DcMotor_Rotate(ClockWise,128);
			LCD_displayString("ON ");
		}
		/* For more than 90C Turn on fan by 75% of it's total power */
		else if( a_TempValue >= 90 && a_TempValue < 120)
		{
			DcMotor_Rotate(ClockWise,192);
			LCD_displayString("ON ");
		}
		/* For more than 120C Turn on fan by 100% of it's total power */
		else if(a_TempValue >= 120)
		{
			DcMotor_Rotate(ClockWise,255);
			LCD_displayString("ON ");
		}

		/*---------------------------------------------------------*/
		{
			/*
			 * Displaying the Temperature
			 */
			LCD_moveCursor(1, 2); /* To write the whole word in the middle */
			LCD_displayString("Temp = ");
			if(a_TempValue < 100 && a_TempValue >= 10)
			{
				LCD_intgerToString(a_TempValue);
				LCD_displayString(" ");
			}
			else if(a_TempValue < 10)
			{
				LCD_intgerToString(a_TempValue);
				LCD_displayString("  ");
			}
			else
			{
				LCD_intgerToString(a_TempValue);
			}
			LCD_displayString("C");
		}
		/*---------------------------------------------------------*/
	}

	return 0;
}
/**-------------------------END------------------------------------**/
