/******************************************************************************
 *
 * Module: Common - Platform Types Abstraction
 *
 * File Name: IM35_TempSensor.h
 *
 * Description: types for AVR
 *
 * Date Created: 3/10/2022
 *
 * Author: Moustafa Ahmed
 *
 *******************************************************************************/

#ifndef LM35_TEMPSENSOR_H_
#define LM35_TEMPSENSOR_H_

/**-------------------------INCLUDES Section------------------------**/
#include "std_types.h"
/**-------------------------Definitions & Config Section------------**/

#define SENSOR_CHANNEL_ID         2
#define SENSOR_MAX_VOLT_VALUE     1.5
#define SENSOR_MAX_TEMPERATURE    150

/**-------------------------Function Dec. Section-------------------**/

/*
 * Description :
 * Function responsible for calculate the temperature from the ADC digital value.
 */
uint8 LM35_getTemperature(void);


/**---------------------------------END-----------------------------**/



#endif /* LM35_TEMPSENSOR_H_ */
