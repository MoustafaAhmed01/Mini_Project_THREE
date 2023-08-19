/******************************************************************************
 *
 * Module: Common - Platform Types Abstraction
 *
 * File Name: ADC.h
 *
 * Description: types for AVR
 *
 * Date Created: 3/10/2022
 *
 * Author: Moustafa Ahmed
 *
 *******************************************************************************/


#ifndef ADC_H_
#define ADC_H_

/**-------------------------INCLUDES Section------------------------**/
#include "std_types.h"
/**-------------------------Definitions & Config Section------------**/
/* Main Definitions */
#define ADC_CHANNEL_ZERO_ID			0
#define ADC_CHANNEL_ONE_ID			1
#define ADC_CHANNEL_TWO_ID			2
#define ADC_CHANNEL_THREE_ID		3
#define ADC_CHANNEL_FOUR_ID			4
#define ADC_CHANNEL_FIVE_ID			5
#define ADC_CHANNEL_SIX_ID			6
#define ADC_CHANNEL_SEVEN_ID		7
#define ADC_MAXIMUM_VALUE    1023
#define ADC_REF_VOLT_VALUE   2.56
/* Modifiable Definitions*/
#define ADC_INPUT_PORT_ID 			PORTA_ID
#define ADC_REF_VOLTAGE_ID			AVCC

/**-------------------------Enum Section----------------------------**/

/*
 * Description:
 * Selecting the reference voltage
 */
typedef enum
{
	AREF=0,AVCC,Reserved,Internal_Ref
}ADC_ReferenceVoltage;

/*
 * Description:
 * Selecting the clock of ADC
 */
typedef enum
{
	F_ADC2=1,F_ADC4,F_ADC8,F_ADC16,F_ADC32,F_ADC64,F_ADC128
}ADC_Prescaler;

/**-------------------------Struct Section--------------------------**/

/*
 * Description:
 * Giving Values when Initializing it
 * Configure the required ADC settings
 */
typedef struct
{
	ADC_ReferenceVoltage ref_volt;
	ADC_Prescaler prescaler;
}ADC_ConfigType;

/**-------------------------Function Dec. Section-------------------**/

/*
 * Description :
 * Function responsible for initialize the ADC driver.
 */
void ADC_init(const ADC_ConfigType *Config_Ptr);

/*----------------------------------------------------------------------------*/
/*
 * Description :
 * Function responsible for read analog data from a certain ADC channel
 * and convert it to digital using the ADC driver.
 */
uint16 ADC_readChannel(uint8 channel_num);

/**-------------------------END-------------------------------------**/

#endif /* ADC_H_ */
