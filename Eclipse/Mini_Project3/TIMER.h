/******************************************************************************
 *
 * Module: Common - Platform Types Abstraction
 *
 * File Name: TIMER.h
 *
 * Description: types for AVR
 *
 * Date Created: 4/10/2022
 *
 * Author: Moustafa Ahmed
 *
 *******************************************************************************/
#ifndef TIMER_H_
#define TIMER_H_

/**-------------------------INCLUDES Section------------------------**/

#include "std_types.h"

/**-------------------------Definitions & Config Section------------**/
#define PWM0_PORT_ID		PORTB_ID
#define PWM0_PIN_ID			PIN3_ID
/**-------------------------Enum Section----------------------------**/

typedef enum
{
	F_TIMER8=2,F_TIMER64,F_TIMER256,F_TIMER1024
}TIMER_prescaler;

/**-------------------------Struct Section--------------------------**/
typedef struct
{
	TIMER_prescaler prescaler;
}TIMER_ConfigType;

/**-------------------------Function Dec. Section-------------------**/
/*
 * Initializing Timer0_PWM
 */
void Timer0_PWM_Init(TIMER_ConfigType *Config_Ptr);

/*
 * Setting Timer0_PWM
 */
void Timer0_PWM_Activate(uint8 SetDuty);

/**-------------------------END-------------------------------------**/

#endif /* TIMER_H_ */
