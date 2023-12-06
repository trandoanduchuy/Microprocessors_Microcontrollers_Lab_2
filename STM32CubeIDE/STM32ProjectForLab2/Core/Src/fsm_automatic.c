/*
 * fsm_automatic.c
 *
 *  Created on: Nov 17, 2023
 *      Author: Huy
 */
#include "fsm_automatic.h"

/****************************************************************************************
GLOBAL VARIABLE
****************************************************************************************/
/* Status of blink_led finite state machine*/
BLINK_STATUS blink_status = BLINK_INIT;

/* status of blink dot machine*/
BLINK_DOT blink_dot_status = DOT_INIT;

/* Status of scan led finite state machine*/
SCAN_LED_STATUS scan_led_status = INIT;

/****************************************************************************************
FUNCTION DEFINITION
****************************************************************************************/
/* Function to blink led red*/
void blink_led(void)
{
	switch(blink_status)
	{
	case BLINK_INIT:
		HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, GPIO_PIN_SET); /* Turn off led red*/
		blink_status = BLINK_ON;
		setTimer1(BLINK_ON_TIME);
		break;
	case BLINK_ON:
		/* Turn on the led red*/
		HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, GPIO_PIN_RESET);
		if(timer1_flag == 1)
		{
			setTimer1(BLINK_OFF_TIME);
			blink_status = BLINK_OFF;
		}
		break;
	case BLINK_OFF:
		/* Turn off the led red*/
		HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, GPIO_PIN_SET);
		if(timer1_flag == 1)
		{
			setTimer1(BLINK_ON_TIME);
			blink_status = BLINK_ON;
		}
		break;
	default:
		break;
	}
}

/* Function to blink dot*/
void blink_dot(void)
{
	switch(blink_dot_status)
	{
	case DOT_INIT:
		HAL_GPIO_WritePin(DOT_GPIO_Port, DOT_Pin, GPIO_PIN_SET);
		blink_dot_status = DOT_ON;
		setTimer2(DOT_ON_TIME);
		break;
	case DOT_ON:
		HAL_GPIO_WritePin(DOT_GPIO_Port, DOT_Pin, GPIO_PIN_RESET);
		if(timer2_flag == 1)
		{
			setTimer2(DOT_OFF_TIME);
			blink_dot_status = DOT_OFF;
		}
		break;
	case DOT_OFF:
		HAL_GPIO_WritePin(DOT_GPIO_Port, DOT_Pin, GPIO_PIN_SET);
		if(timer2_flag == 1)
		{
			setTimer2(DOT_ON_TIME);
			blink_dot_status = DOT_ON;
		}
		break;
	default:
		break;

	}
}

/* Function to scan 4 7-segment led*/
void scan_led(unsigned int* clock_buffer)
{
	switch(scan_led_status)
	{
	case INIT:
		DisplayNumberOnLed(4, clock_buffer);
		scan_led_status = LED0;
		setTimer3(ON_TIME);
		break;
	case LED0:
		DisplayNumberOnLed(0, clock_buffer);
		if(timer3_flag == 1)
		{
			setTimer3(ON_TIME);
			scan_led_status = LED1;
		}
		break;
	case LED1:
		DisplayNumberOnLed(1, clock_buffer);
		if(timer3_flag == 1)
		{
			setTimer3(ON_TIME);
			scan_led_status = LED2;
		}
		break;
	case LED2:
		DisplayNumberOnLed(2, clock_buffer);
		if(timer3_flag == 1)
		{
			setTimer3(ON_TIME);
			scan_led_status = LED3;
		}
		break;
	case LED3:
		DisplayNumberOnLed(3, clock_buffer);
		if(timer3_flag == 1)
		{
			setTimer3(ON_TIME);
			scan_led_status = LED0;
		}
		break;
	default:
		break;
	}
}
