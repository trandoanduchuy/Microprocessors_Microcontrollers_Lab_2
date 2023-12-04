/*
 * fsm_automatic.c
 *
 *  Created on: Nov 17, 2023
 *      Author: Huy
 */
#include "fsm_automatic.h"

/*
 * Function to display a number on a specified led
 * num: order of led to display number
 * num_to_display: number to be displayed on led
 * */
void TurnLed(int num, int num_to_display)
{

	switch(num)
	{
	case 0:
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, GPIO_PIN_SET);
		break;
	case 1:
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, GPIO_PIN_SET);
		break;
	case 2:
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, GPIO_PIN_SET);
		break;
	case 3:
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, GPIO_PIN_RESET);
		break;
	default:
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, GPIO_PIN_SET);
		break;
	}
	display7SEG(num_to_display);
}

/* Function to get number and display them on led*/
void DisplayNumber(int LedOrder)
{
	unsigned char* number_to_display = (unsigned char*) malloc(sizeof(unsigned char) * 4);
	number_to_display[0] = NUM_0;
	number_to_display[1] = NUM_1;
	number_to_display[2] = NUM_2;
	number_to_display[3] = NUM_3;
	TurnLed(LedOrder, number_to_display[LedOrder]);
	free(number_to_display);
}

/* Function to turn each 7-segment led*/
void fsm_automatic_run(void)
{
	switch(scan_led_status)
	{
	case INIT:
//		TurnLed(6, 0); /* Turn off all led*/
		DisplayNumber(0);
		scan_led_status = LED0;
		setTimer2(ON_TIME);
		break;
	case LED0:
		DisplayNumber(0);
//		TurnLed(0, num_to_display[0]); /* Turn on LED 0*/
		if(timer2_flag == 1)
		{
			setTimer2(ON_TIME);
			scan_led_status = LED1;
		}
		break;
	case LED1:
		DisplayNumber(1);
//		TurnLed(1, num_to_display[1]); /* Turn on LED 0*/
		if(timer2_flag == 1)
		{
			setTimer2(ON_TIME);
			scan_led_status = LED2;
		}
		break;
	case LED2:
		DisplayNumber(2);
//		TurnLed(2, num_to_display[2]); /* Turn on LED 0*/
		if(timer2_flag == 1)
		{
			setTimer2(ON_TIME);
			scan_led_status = LED3;
		}
		break;
	case LED3:
		DisplayNumber(3);
//		TurnLed(3, num_to_display[3]); /* Turn on LED 0*/
		if(timer2_flag == 1)
		{
			setTimer2(ON_TIME);
			scan_led_status = LED0;
		}
		break;
	default:
		break;
	}
}

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
		setTimer3(DOT_ON_TIME);
		break;
	case DOT_ON:
		HAL_GPIO_WritePin(DOT_GPIO_Port, DOT_Pin, GPIO_PIN_RESET);
		if(timer3_flag == 1)
		{
			setTimer3(DOT_OFF_TIME);
			blink_dot_status = DOT_OFF;
		}
		break;
	case DOT_OFF:
		HAL_GPIO_WritePin(DOT_GPIO_Port, DOT_Pin, GPIO_PIN_SET);
		if(timer3_flag == 1)
		{
			setTimer3(DOT_ON_TIME);
			blink_dot_status = DOT_ON;
		}
		break;
	default:
		break;

	}
}

/* Function to scan led using update7SEG() function*/
void scan_led(void)
{
	switch(scan_led_status)
	{
	case INIT:
		update7SEG(4); /* Turn of all 7-segment led*/
		scan_led_status = LED0;
		setTimer2(ON_TIME);
		break;
	case LED0:
		update7SEG(0); /* Turn on only led 0*/
		if(timer2_flag == 1)
		{
			setTimer2(ON_TIME);
			scan_led_status = LED1;
		}
		break;
	case LED1:
		update7SEG(1); /* Turn on only led 0*/
		if(timer2_flag == 1)
		{
			setTimer2(ON_TIME);
			scan_led_status = LED2;
		}
		break;
	case LED2:
		update7SEG(2); /* Turn on only led 0*/
		if(timer2_flag == 1)
		{
			setTimer2(ON_TIME);
			scan_led_status = LED3;
		}
		break;
	case LED3:
		update7SEG(3); /* Turn on only led 0*/
		if(timer2_flag == 1)
		{
			setTimer2(ON_TIME);
			scan_led_status = LED0;
		}
		break;
	default:
		break;
	}
}
