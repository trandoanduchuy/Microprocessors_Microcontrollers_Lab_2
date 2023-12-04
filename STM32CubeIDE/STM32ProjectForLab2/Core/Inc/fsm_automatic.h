/*
 * fsm_automatic.h
 *
 *  Created on: Nov 17, 2023
 *      Author: Huy
 */

#ifndef INC_FSM_AUTOMATIC_H_
#define INC_FSM_AUTOMATIC_H_

#include "global.h"

#define ON_TIME	250

#define BLINK_ON_TIME	500
#define BLINK_OFF_TIME	500

#define DOT_ON_TIME		1000
#define DOT_OFF_TIME	1000

/* Number to display*/
#define NUM_0	1
#define NUM_1	2
#define NUM_2	3
#define NUM_3	0

void TurnLed(int num, int num_to_display);

void DisplayNumber(int LedOrder);

void fsm_automatic_run(void);

void blink_led(void);

void blink_dot(void);

void scan_led();

#endif /* INC_FSM_AUTOMATIC_H_ */
