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

extern int timer2_counter;
extern int timer2_flag;

void setTimer2(int duration);

extern int time3_counter;
extern int timer3_flag;

void setTimer3(int duration);

extern int timer4_counter;
extern int timer4_flag;

void setTimer4(int duration);

void timerRun();


#endif /* INC_SOFTWARE_TIMER_H_ */
