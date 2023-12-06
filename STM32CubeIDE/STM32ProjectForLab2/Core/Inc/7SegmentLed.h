/*
 * 7SegmentLed.h
 *
 *  Created on: Nov 2, 2023
 *      Author: Huy
 */

#ifndef INC_7SEGMENTLED_H_
#define INC_7SEGMENTLED_H_

#include "global.h"

extern int index_led;
extern const int MAX_LED;
extern int led_buffer[];

/*funtion to display 7-segment led*/
void display7SEG(unsigned int num);

/* Function to display number on led*/
void update7SEG(int index);

/* Function to display number on 7-segment led*/
void DisplayNumberOnLed(int led, unsigned int* value_buffer);


#endif /* INC_7SEGMENTLED_H_ */
