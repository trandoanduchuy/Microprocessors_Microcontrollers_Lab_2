/*
 * DigitalClock.c
 *
 *  Created on: Dec 4, 2023
 *      Author: Huy
 */
#include "DigitalClock.h"

unsigned int hour = 15;
unsigned int minute = 8;
unsigned int second = 50;

unsigned int clock_buffer[4] = {0, 0, 0, 0};

void updateClockBuffer()
{
	clock_buffer[0] = hour/10;
	clock_buffer[1] = hour%10;
	clock_buffer[2] = minute/10;
	clock_buffer[3] = minute%10;
}

void DigitalClock()
{
	if(timer4_flag == 1)
	{
		setTimer4(1000);
		second++;
		if(second >= 60)
		{
			minute++;
			second = 0;
		}
		if(minute >= 60)
		{
			hour++;
			minute = 0;
		}
		if(hour >= 24)
		{
			hour = 0;
		}
	}
	updateClockBuffer();
}



