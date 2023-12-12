/*
 * led_matrix.c
 *
 *  Created on: Dec 12, 2023
 *      Author: Huy
 */

#include "led_matrix.h"

const int MAX_LED_MATRIX = 8;
int index_led_matrix = 0;
unsigned char matrix_buffer[8] = {0xEF, 0x03, 0xED, 0xEE, 0xEE, 0xED, 0x03, 0xEF};

void updateLEDMatrix(int index)
{
	switch(index)
	{
	case 0:
		/* Turn on col 0 with matrix_buffer[0], to turn on col -> reset*/
		HAL_GPIO_WritePin(ENM0_GPIO_Port, ENM0_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(ENM1_GPIO_Port, ENM1_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(ENM2_GPIO_Port, ENM2_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(ENM3_GPIO_Port, ENM3_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(ENM4_GPIO_Port, ENM4_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(ENM5_GPIO_Port, ENM5_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(ENM6_GPIO_Port, ENM6_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(ENM7_GPIO_Port, ENM7_Pin, GPIO_PIN_SET);

		/* Turn on rows based on buffer_matrix[0], to turn on row -> reset*/
		HAL_GPIO_WritePin(ROW0_GPIO_Port, ROW0_Pin, ((matrix_buffer[0] >> 0) & 0x01));
		HAL_GPIO_WritePin(ROW1_GPIO_Port, ROW1_Pin, ((matrix_buffer[0] >> 1) & 0x01));
		HAL_GPIO_WritePin(ROW2_GPIO_Port, ROW2_Pin, ((matrix_buffer[0] >> 2) & 0x01));
		HAL_GPIO_WritePin(ROW3_GPIO_Port, ROW3_Pin, ((matrix_buffer[0] >> 3) & 0x01));
		HAL_GPIO_WritePin(ROW4_GPIO_Port, ROW4_Pin, ((matrix_buffer[0] >> 4) & 0x01));
		HAL_GPIO_WritePin(ROW5_GPIO_Port, ROW5_Pin, ((matrix_buffer[0] >> 5) & 0x01));
		HAL_GPIO_WritePin(ROW6_GPIO_Port, ROW6_Pin, ((matrix_buffer[0] >> 6) & 0x01));
		HAL_GPIO_WritePin(ROW7_GPIO_Port, ROW7_Pin, ((matrix_buffer[0] >> 7) & 0x01));
		break;
	case 1:
		/* Turn on col 0 with matrix_buffer[0], to turn on col -> reset*/
		HAL_GPIO_WritePin(ENM0_GPIO_Port, ENM0_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(ENM1_GPIO_Port, ENM1_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(ENM2_GPIO_Port, ENM2_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(ENM3_GPIO_Port, ENM3_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(ENM4_GPIO_Port, ENM4_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(ENM5_GPIO_Port, ENM5_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(ENM6_GPIO_Port, ENM6_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(ENM7_GPIO_Port, ENM7_Pin, GPIO_PIN_SET);

		/* Turn on rows based on buffer_matrix[0], to turn on row -> reset*/
		HAL_GPIO_WritePin(ROW0_GPIO_Port, ROW0_Pin, ((matrix_buffer[1] >> 0) & 0x01));
		HAL_GPIO_WritePin(ROW1_GPIO_Port, ROW1_Pin, ((matrix_buffer[1] >> 1) & 0x01));
		HAL_GPIO_WritePin(ROW2_GPIO_Port, ROW2_Pin, ((matrix_buffer[1] >> 2) & 0x01));
		HAL_GPIO_WritePin(ROW3_GPIO_Port, ROW3_Pin, ((matrix_buffer[1] >> 3) & 0x01));
		HAL_GPIO_WritePin(ROW4_GPIO_Port, ROW4_Pin, ((matrix_buffer[1] >> 4) & 0x01));
		HAL_GPIO_WritePin(ROW5_GPIO_Port, ROW5_Pin, ((matrix_buffer[1] >> 5) & 0x01));
		HAL_GPIO_WritePin(ROW6_GPIO_Port, ROW6_Pin, ((matrix_buffer[1] >> 6) & 0x01));
		HAL_GPIO_WritePin(ROW7_GPIO_Port, ROW7_Pin, ((matrix_buffer[1] >> 7) & 0x01));
		break;
	case 2:
		/* Turn on col 0 with matrix_buffer[0], to turn on col -> reset*/
		HAL_GPIO_WritePin(ENM0_GPIO_Port, ENM0_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(ENM1_GPIO_Port, ENM1_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(ENM2_GPIO_Port, ENM2_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(ENM3_GPIO_Port, ENM3_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(ENM4_GPIO_Port, ENM4_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(ENM5_GPIO_Port, ENM5_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(ENM6_GPIO_Port, ENM6_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(ENM7_GPIO_Port, ENM7_Pin, GPIO_PIN_SET);

		/* Turn on rows based on buffer_matrix[0], to turn on row -> reset*/
		HAL_GPIO_WritePin(ROW0_GPIO_Port, ROW0_Pin, ((matrix_buffer[2] >> 0) & 0x01));
		HAL_GPIO_WritePin(ROW1_GPIO_Port, ROW1_Pin, ((matrix_buffer[2] >> 1) & 0x01));
		HAL_GPIO_WritePin(ROW2_GPIO_Port, ROW2_Pin, ((matrix_buffer[2] >> 2) & 0x01));
		HAL_GPIO_WritePin(ROW3_GPIO_Port, ROW3_Pin, ((matrix_buffer[2] >> 3) & 0x01));
		HAL_GPIO_WritePin(ROW4_GPIO_Port, ROW4_Pin, ((matrix_buffer[2] >> 4) & 0x01));
		HAL_GPIO_WritePin(ROW5_GPIO_Port, ROW5_Pin, ((matrix_buffer[2] >> 5) & 0x01));
		HAL_GPIO_WritePin(ROW6_GPIO_Port, ROW6_Pin, ((matrix_buffer[2] >> 6) & 0x01));
		HAL_GPIO_WritePin(ROW7_GPIO_Port, ROW7_Pin, ((matrix_buffer[2] >> 7) & 0x01));
		break;
	case 3:
		/* Turn on col 0 with matrix_buffer[0], to turn on col -> reset*/
		HAL_GPIO_WritePin(ENM0_GPIO_Port, ENM0_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(ENM1_GPIO_Port, ENM1_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(ENM2_GPIO_Port, ENM2_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(ENM3_GPIO_Port, ENM3_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(ENM4_GPIO_Port, ENM4_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(ENM5_GPIO_Port, ENM5_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(ENM6_GPIO_Port, ENM6_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(ENM7_GPIO_Port, ENM7_Pin, GPIO_PIN_SET);

		/* Turn on rows based on buffer_matrix[0], to turn on row -> reset*/
		HAL_GPIO_WritePin(ROW0_GPIO_Port, ROW0_Pin, ((matrix_buffer[3] >> 0) & 0x01));
		HAL_GPIO_WritePin(ROW1_GPIO_Port, ROW1_Pin, ((matrix_buffer[3] >> 1) & 0x01));
		HAL_GPIO_WritePin(ROW2_GPIO_Port, ROW2_Pin, ((matrix_buffer[3] >> 2) & 0x01));
		HAL_GPIO_WritePin(ROW3_GPIO_Port, ROW3_Pin, ((matrix_buffer[3] >> 3) & 0x01));
		HAL_GPIO_WritePin(ROW4_GPIO_Port, ROW4_Pin, ((matrix_buffer[3] >> 4) & 0x01));
		HAL_GPIO_WritePin(ROW5_GPIO_Port, ROW5_Pin, ((matrix_buffer[3] >> 5) & 0x01));
		HAL_GPIO_WritePin(ROW6_GPIO_Port, ROW6_Pin, ((matrix_buffer[3] >> 6) & 0x01));
		HAL_GPIO_WritePin(ROW7_GPIO_Port, ROW7_Pin, ((matrix_buffer[3] >> 7) & 0x01));
		break;
	case 4:
		/* Turn on col 0 with matrix_buffer[0], to turn on col -> reset*/
		HAL_GPIO_WritePin(ENM0_GPIO_Port, ENM0_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(ENM1_GPIO_Port, ENM1_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(ENM2_GPIO_Port, ENM2_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(ENM3_GPIO_Port, ENM3_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(ENM4_GPIO_Port, ENM4_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(ENM5_GPIO_Port, ENM5_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(ENM6_GPIO_Port, ENM6_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(ENM7_GPIO_Port, ENM7_Pin, GPIO_PIN_SET);

		/* Turn on rows based on buffer_matrix[0], to turn on row -> reset*/
		HAL_GPIO_WritePin(ROW0_GPIO_Port, ROW0_Pin, ((matrix_buffer[4] >> 0) & 0x01));
		HAL_GPIO_WritePin(ROW1_GPIO_Port, ROW1_Pin, ((matrix_buffer[4] >> 1) & 0x01));
		HAL_GPIO_WritePin(ROW2_GPIO_Port, ROW2_Pin, ((matrix_buffer[4] >> 2) & 0x01));
		HAL_GPIO_WritePin(ROW3_GPIO_Port, ROW3_Pin, ((matrix_buffer[4] >> 3) & 0x01));
		HAL_GPIO_WritePin(ROW4_GPIO_Port, ROW4_Pin, ((matrix_buffer[4] >> 4) & 0x01));
		HAL_GPIO_WritePin(ROW5_GPIO_Port, ROW5_Pin, ((matrix_buffer[4] >> 5) & 0x01));
		HAL_GPIO_WritePin(ROW6_GPIO_Port, ROW6_Pin, ((matrix_buffer[4] >> 6) & 0x01));
		HAL_GPIO_WritePin(ROW7_GPIO_Port, ROW7_Pin, ((matrix_buffer[4] >> 7) & 0x01));
		break;
	case 5:
		/* Turn on col 0 with matrix_buffer[0], to turn on col -> reset*/
		HAL_GPIO_WritePin(ENM0_GPIO_Port, ENM0_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(ENM1_GPIO_Port, ENM1_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(ENM2_GPIO_Port, ENM2_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(ENM3_GPIO_Port, ENM3_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(ENM4_GPIO_Port, ENM4_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(ENM5_GPIO_Port, ENM5_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(ENM6_GPIO_Port, ENM6_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(ENM7_GPIO_Port, ENM7_Pin, GPIO_PIN_SET);

		/* Turn on rows based on buffer_matrix[0], to turn on row -> reset*/
		HAL_GPIO_WritePin(ROW0_GPIO_Port, ROW0_Pin, ((matrix_buffer[5] >> 0) & 0x01));
		HAL_GPIO_WritePin(ROW1_GPIO_Port, ROW1_Pin, ((matrix_buffer[5] >> 1) & 0x01));
		HAL_GPIO_WritePin(ROW2_GPIO_Port, ROW2_Pin, ((matrix_buffer[5] >> 2) & 0x01));
		HAL_GPIO_WritePin(ROW3_GPIO_Port, ROW3_Pin, ((matrix_buffer[5] >> 3) & 0x01));
		HAL_GPIO_WritePin(ROW4_GPIO_Port, ROW4_Pin, ((matrix_buffer[5] >> 4) & 0x01));
		HAL_GPIO_WritePin(ROW5_GPIO_Port, ROW5_Pin, ((matrix_buffer[5] >> 5) & 0x01));
		HAL_GPIO_WritePin(ROW6_GPIO_Port, ROW6_Pin, ((matrix_buffer[5] >> 6) & 0x01));
		HAL_GPIO_WritePin(ROW7_GPIO_Port, ROW7_Pin, ((matrix_buffer[5] >> 7) & 0x01));
		break;
	case 6:
		/* Turn on col 0 with matrix_buffer[0], to turn on col -> reset*/
		HAL_GPIO_WritePin(ENM0_GPIO_Port, ENM0_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(ENM1_GPIO_Port, ENM1_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(ENM2_GPIO_Port, ENM2_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(ENM3_GPIO_Port, ENM3_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(ENM4_GPIO_Port, ENM4_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(ENM5_GPIO_Port, ENM5_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(ENM6_GPIO_Port, ENM6_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(ENM7_GPIO_Port, ENM7_Pin, GPIO_PIN_SET);

		/* Turn on rows based on buffer_matrix[0], to turn on row -> reset*/
		HAL_GPIO_WritePin(ROW0_GPIO_Port, ROW0_Pin, ((matrix_buffer[6] >> 0) & 0x01));
		HAL_GPIO_WritePin(ROW1_GPIO_Port, ROW1_Pin, ((matrix_buffer[6] >> 1) & 0x01));
		HAL_GPIO_WritePin(ROW2_GPIO_Port, ROW2_Pin, ((matrix_buffer[6] >> 2) & 0x01));
		HAL_GPIO_WritePin(ROW3_GPIO_Port, ROW3_Pin, ((matrix_buffer[6] >> 3) & 0x01));
		HAL_GPIO_WritePin(ROW4_GPIO_Port, ROW4_Pin, ((matrix_buffer[6] >> 4) & 0x01));
		HAL_GPIO_WritePin(ROW5_GPIO_Port, ROW5_Pin, ((matrix_buffer[6] >> 5) & 0x01));
		HAL_GPIO_WritePin(ROW6_GPIO_Port, ROW6_Pin, ((matrix_buffer[6] >> 6) & 0x01));
		HAL_GPIO_WritePin(ROW7_GPIO_Port, ROW7_Pin, ((matrix_buffer[6] >> 7) & 0x01));
		break;
	case 7:
		/* Turn on col 0 with matrix_buffer[0], to turn on col -> reset*/
		HAL_GPIO_WritePin(ENM0_GPIO_Port, ENM0_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(ENM1_GPIO_Port, ENM1_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(ENM2_GPIO_Port, ENM2_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(ENM3_GPIO_Port, ENM3_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(ENM4_GPIO_Port, ENM4_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(ENM5_GPIO_Port, ENM5_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(ENM6_GPIO_Port, ENM6_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(ENM7_GPIO_Port, ENM7_Pin, GPIO_PIN_RESET);

		/* Turn on rows based on buffer_matrix[0], to turn on row -> reset*/
		HAL_GPIO_WritePin(ROW0_GPIO_Port, ROW0_Pin, ((matrix_buffer[7] >> 0) & 0x01));
		HAL_GPIO_WritePin(ROW1_GPIO_Port, ROW1_Pin, ((matrix_buffer[7] >> 1) & 0x01));
		HAL_GPIO_WritePin(ROW2_GPIO_Port, ROW2_Pin, ((matrix_buffer[7] >> 2) & 0x01));
		HAL_GPIO_WritePin(ROW3_GPIO_Port, ROW3_Pin, ((matrix_buffer[7] >> 3) & 0x01));
		HAL_GPIO_WritePin(ROW4_GPIO_Port, ROW4_Pin, ((matrix_buffer[7] >> 4) & 0x01));
		HAL_GPIO_WritePin(ROW5_GPIO_Port, ROW5_Pin, ((matrix_buffer[7] >> 5) & 0x01));
		HAL_GPIO_WritePin(ROW6_GPIO_Port, ROW6_Pin, ((matrix_buffer[7] >> 6) & 0x01));
		HAL_GPIO_WritePin(ROW7_GPIO_Port, ROW7_Pin, ((matrix_buffer[7] >> 7) & 0x01));
		break;
	default:
		break;
	}
}

