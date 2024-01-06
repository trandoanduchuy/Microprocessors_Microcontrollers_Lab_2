/*
 * DigitalClock.h
 *
 *  Created on: Dec 4, 2023
 *      Author: Huy
 */

#ifndef INC_DIGITALCLOCK_H_
#define INC_DIGITALCLOCK_H_

#include "global.h"

extern unsigned int clock_buffer[];

/* Function to update values of elements of clock_buffer*/
void updateClockBuffer();


/* Function to update second, minute, hour every second*/
void DigitalClock();

#endif /* INC_DIGITALCLOCK_H_ */