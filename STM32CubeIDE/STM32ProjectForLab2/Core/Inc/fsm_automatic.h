/*
 * fsm_automatic.h
 *
 *  Created on: Nov 17, 2023
 *      Author: Huy
 */

#ifndef INC_FSM_AUTOMATIC_H_
#define INC_FSM_AUTOMATIC_H_

#include "global.h"

#define ON_TIME	500

#define BLINK_ON_TIME	500
#define BLINK_OFF_TIME	500

void fsm_automatic_run(void);

void blink_led(void);

#endif /* INC_FSM_AUTOMATIC_H_ */
