/*
 * software_timer.h
 *
 *  Created on: Oct 21, 2023
 *      Author: Huy
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

#define TICK	10

extern int timer1_counter;
extern int timer1_flag;

void setTimer1(int duration);

void timerRun();


#endif /* INC_SOFTWARE_TIMER_H_ */
