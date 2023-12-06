/*
 * fsm_automatic.h
 *
 *  Created on: Nov 17, 2023
 *      Author: Huy
 */

#ifndef INC_FSM_AUTOMATIC_H_
#define INC_FSM_AUTOMATIC_H_

/********************************************************************************************
INCLUDE LIBRARY
********************************************************************************************/
#include "global.h"

/********************************************************************************************
CONSTANT DECLARATION
********************************************************************************************/
/* Time constants for blinking led red*/
#define BLINK_ON_TIME	500
#define BLINK_OFF_TIME	500

/* Time constants for blinking dot*/
#define DOT_ON_TIME		1000
#define DOT_OFF_TIME	1000

/* Time constants for scanning led*/
#define ON_TIME	250

/********************************************************************************************
TYPE DEFINITON
********************************************************************************************/
/* States of blink led red finite state machine*/
typedef enum
{
	BLINK_INIT,
	BLINK_ON,
	BLINK_OFF
} BLINK_STATUS;

/* States of blink dot finite state machine*/
typedef enum
{
	DOT_INIT,
	DOT_ON,
	DOT_OFF
} BLINK_DOT;

/* States of scan led finite state machine*/
typedef enum
{
	INIT,
	LED0,
	LED1,
	LED2,
	LED3
}SCAN_LED_STATUS;

/********************************************************************************************
GLOBAL VARIABLE
********************************************************************************************/
extern BLINK_STATUS blink_status;				/* state of blink led red machine*/
extern BLINK_DOT blink_dot_status;				/* state of blink dot machine*/
extern SCAN_LED_STATUS scan_led_status;			/* state of scan led machine*/

/********************************************************************************************
FUNCTION PROTOTYPE
********************************************************************************************/
/* Function to blink led red*/
void blink_led(void);

/* Function to blink dot*/
void blink_dot(void);

/* Function to scan 4 7-segment led*/
void scan_led(unsigned int* clock_buffer);

#endif /* INC_FSM_AUTOMATIC_H_ */
