#ifndef KEYPAD_H
#define KEYPAD_H

#include <stdint.h>
#include "main.h"

/* Rows (outputs) */
#define PIN_ROW1          GPIO_PIN_0
#define PIN_ROW2          GPIO_PIN_1
#define PIN_ROW3          GPIO_PIN_2
#define PIN_ROW4          GPIO_PIN_3
#define PIN_PORT_ROW1     GPIOB
#define PIN_PORT_ROW2     GPIOB
#define PIN_PORT_ROW3     GPIOB
#define PIN_PORT_ROW4     GPIOB

/* Columns (inputs) */
#define PIN_COLUMN1       GPIO_PIN_4
#define PIN_COLUMN2       GPIO_PIN_5
#define PIN_COLUMN3       GPIO_PIN_6
#define PIN_COLUMN4       GPIO_PIN_7
#define PIN_PORT_COLUMN1  GPIOB
#define PIN_PORT_COLUMN2  GPIOB
#define PIN_PORT_COLUMN3  GPIOB
#define PIN_PORT_COLUMN4  GPIOB

/* Key mapping */
#define KEY_ROW1_CLM1 '7'
#define KEY_ROW1_CLM2 '8'
#define KEY_ROW1_CLM3 '9'
#define KEY_ROW1_CLM4 '/'
#define KEY_ROW2_CLM1 '4'
#define KEY_ROW2_CLM2 '5'
#define KEY_ROW2_CLM3 '6'
#define KEY_ROW2_CLM4 '*'
#define KEY_ROW3_CLM1 '1'
#define KEY_ROW3_CLM2 '2'
#define KEY_ROW3_CLM3 '3'
#define KEY_ROW3_CLM4 '-'
#define KEY_ROW4_CLM1 '$'    // clear/negative
#define KEY_ROW4_CLM2 '0'
#define KEY_ROW4_CLM3 '='
#define KEY_ROW4_CLM4 '+'

#define KEY_CLEAR  KEY_ROW4_CLM1
#define KEY_EQUALS KEY_ROW4_CLM3
#define KEY_NO_PRESS ' '

/* Prototypes */
void keypad_init(void);
unsigned char key_press(void);
unsigned char check_row(GPIO_TypeDef port, uint16_t pin);

#endif /* KEYPAD_H */
