/*
 * DigitalClock.c
 *
 *  Created on: Dec 4, 2023
 *      Author: Huy
 */
#include "DigitalClock.h"

int hour = 15;
int minute = 8;
int second = 50;



int DigitalClock()
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
}
