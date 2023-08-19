/******************************************************************************
 *
 * Module: Common - Platform Types Abstraction
 *
 * File Name: ADC.c
 *
 * Description: types for AVR
 *
 * Date Created: 3/10/2022
 *
 * Author: Moustafa Ahmed
 *
 *******************************************************************************/

/**-------------------------INCLUDES Section------------------------**/
#include "Libraries.h"
#include "GPIO.h"
#include "ADC.h"

/**-------------------------Function Definition Section-------------**/
/*
 * Description :
 * Function responsible for initialize the ADC driver.
 */
void ADC_init(const ADC_ConfigType *Config_Ptr)
{
	/* Choosing the Reference voltage */
	ADMUX = (ADMUX & 0x3F) |(Config_Ptr->ref_volt<<6);

	/* Activating the ADC */
	SET_BIT(ADCSRA,ADEN);

	/* Setting F_ADC = F_CPU/x */
	ADCSRA = (ADCSRA & 0xF8) | Config_Ptr->prescaler;

}

/*----------------------------------------------------------------------------*/

/*
 * Description :
 * Function responsible for read analog data from a certain ADC channel
 * and convert it to digital using the ADC driver.
 */
uint16 ADC_readChannel(uint8 channel_num)
{
	ADMUX &= 0xE0; /* Clearing the first 5 bits */
	ADMUX = ADMUX | channel_num; /* Choosing which channel will be used*/
	SET_BIT(ADCSRA,ADSC); /* Start Conversion   */

	while(BIT_IS_CLEAR(ADCSRA,ADIF)); /* Based ON pulling method */

	SET_BIT(ADCSRA,ADIF); /* Clearing the flag register */

	return ADC; /* Read the digital value from the data register */
}
/**---------------------------------END-----------------------------**/
