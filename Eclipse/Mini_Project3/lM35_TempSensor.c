/******************************************************************************
 *
 * Module: Common - Platform Types Abstraction
 *
 * File Name: IM35_TempSensor.c
 *
 * Description: types for AVR
 *
 * Date Created: 3/10/2022
 *
 * Author: Moustafa Ahmed
 *
 *******************************************************************************/

/**-------------------------INCLUDES Section------------------------**/
#include "lM35_TempSensor.h"

#include "ADC.h"
/**-------------------------Function Definition Section-------------**/

/*
 * Description :
 * Function responsible for calculate the temperature from the ADC digital value.
 */
uint8 LM35_getTemperature(void)
{
	uint8 a_temp_value = 0;

	uint16 a_adc_value = 0;

	/* Read ADC channel where the temperature sensor is connected */
	a_adc_value = ADC_readChannel(SENSOR_CHANNEL_ID);

	/* Calculate the temperature from the ADC value*/
	a_temp_value = (uint8)(((uint32)a_adc_value*SENSOR_MAX_TEMPERATURE*ADC_REF_VOLT_VALUE)/(ADC_MAXIMUM_VALUE*SENSOR_MAX_VOLT_VALUE));

	return a_temp_value;
}
/**---------------------------------END-----------------------------**/
