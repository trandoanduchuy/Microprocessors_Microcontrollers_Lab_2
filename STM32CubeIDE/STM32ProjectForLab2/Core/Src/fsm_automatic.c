/*
 * fsm_automatic.c
 *
 *  Created on: Nov 17, 2023
 *      Author: Huy
 */
#include "fsm_automatic.h"


void fsm_automatic_run(void)
{
	switch(scan_led_status)
	{
	case INIT:
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_SET);
		scan_led_status = LED1;
		setTimer2(ON_TIME);
		break;
	case LED1:
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_SET);
		display7SEG(1);
		if(timer2_flag == 1)
		{
			setTimer2(ON_TIME);
			scan_led_status = LED2;
		}
		break;
	case LED2:
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_RESET);
		display7SEG(2);
		if(timer2_flag == 1)
		{
			setTimer2(ON_TIME);
			scan_led_status = LED1;
		}
		break;
	default:
		break;
	}
}


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
