#ifndef LCD_H
#define LCD_H

#include <stdint.h>
#include "main.h"

/* LCD Control Pins */
#define PIN_RS           GPIO_PIN_8
#define PIN_EN           GPIO_PIN_9
#define PIN_WR           GPIO_PIN_10

/* LCD Data Pins */
#define PIN_D0           GPIO_PIN_0
#define PIN_D1           GPIO_PIN_1
#define PIN_D2           GPIO_PIN_2
#define PIN_D3           GPIO_PIN_3
#define PIN_D4           GPIO_PIN_4
#define PIN_D5           GPIO_PIN_5
#define PIN_D6           GPIO_PIN_6
#define PIN_D7           GPIO_PIN_7

/* Ports */
#define PIN_PORT_RS      GPIOA
#define PIN_PORT_EN      GPIOA
#define PIN_PORT_WR      GPIOA
#define PIN_PORT_D0      GPIOA
#define PIN_PORT_D1      GPIOA
#define PIN_PORT_D2      GPIOA
#define PIN_PORT_D3      GPIOA
#define PIN_PORT_D4      GPIOA
#define PIN_PORT_D5      GPIOA
#define PIN_PORT_D6      GPIOA
#define PIN_PORT_D7      GPIOA

/* Commands & Modes */
#define CLEAR_SCREEN               0x01
#define CURSOR_1ST_LINE_1ST_COLUMN 0x80
#define CURSOR_2ND_LINE_1ST_COLUMN 0xC0
#define CURSOR_3RD_LINE_1ST_COLUMN 0x94
#define CURSOR_4TH_LINE_1ST_COLUMN 0xD4
#define INCREMENT_CURSOR           0x06
#define DISP_ON_CURSOR_BLINK       0x0E
#define DISP_ON_CURSOR_OFF         0x0C

#define LCD_COMMAND 0
#define LCD_DATA    1

#define LCD_4BIT_MODE 0
#define LCD_8BIT_MODE 1

/* Prototypes */
void LCD(uint8_t val, uint8_t cmdData);
void LCD_init(uint8_t lcdMode);
void LCD_str(uint8_t *str);
void LCD_8bit_mode(uint8_t val);
void LCD_4bit_mode(uint8_t val);
void lcdEnablePulse(void);

#endif /* LCD_H */
