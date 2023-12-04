/*
 * global.h
 *
 *  Created on: Oct 21, 2023
 *      Author: Huy
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "main.h"
#include "software_timer.h"
#include "7SegmentLed.h" /*Library for control 7-segment led*/
#include "stdlib.h"

/* For scan led*/
typedef enum
{
	INIT,
	LED0,
	LED1,
	LED2,
	LED3
}SCAN_LED_STATUS;
extern SCAN_LED_STATUS scan_led_status;

/* For blink led red*/
typedef enum
{
	BLINK_INIT,
	BLINK_ON,
	BLINK_OFF
} BLINK_STATUS;
extern BLINK_STATUS blink_status;
/* For blink dot*/
typedef enum
{
	DOT_INIT,
	DOT_ON,
	DOT_OFF
} BLINK_DOT;

extern BLINK_DOT blink_dot_status;



#endif /* INC_GLOBAL_H_ */
