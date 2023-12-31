/*
 * led_matrix.h
 *
 *  Created on: Dec 12, 2023
 *      Author: Huy
 */

#ifndef INC_LED_MATRIX_H_
#define INC_LED_MATRIX_H_

#include "global.h"

#define DISPLAY_TIME_OF_A_COL	1000

typedef enum
{
	LED_MATRIX_INIT,
	COL0,
	COL1,
	COL2,
	COL3,
	COL4,
	COL5,
	COL6,
	COL7
}LED_MATRIX_STATUS;

extern const int MAX_LED_MATRIX;
extern int index_led_matrix;

//extern LED_MATRIX_STATUS led_matrix_status;

void updateLEDMatrix(int index);

void LedMatrixDisplay(void);

#endif /* INC_LED_MATRIX_H_ */
