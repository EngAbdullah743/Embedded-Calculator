#include "LCD.h"

/* Store selected mode */
static volatile uint8_t lcdModeSel;

void LCD(uint8_t val, uint8_t cmdData)
{
    HAL_GPIO_WritePin(PIN_PORT_RS, PIN_RS, (GPIO_PinState)cmdData);
    if (lcdModeSel == LCD_8BIT_MODE) LCD_8bit_mode(val);
    else                            LCD_4bit_mode(val);
}

void LCD_init(uint8_t lcdMode)
{
    /* Reset all control & data pins */
    HAL_GPIO_WritePin(PIN_PORT_RS, PIN_RS, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(PIN_PORT_EN, PIN_EN, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(PIN_PORT_D4, PIN_D4, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(PIN_PORT_D5, PIN_D5, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(PIN_PORT_D6, PIN_D6, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(PIN_PORT_D7, PIN_D7, GPIO_PIN_RESET);
    if (lcdMode == LCD_8BIT_MODE) {
        HAL_GPIO_WritePin(PIN_PORT_D0, PIN_D0, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(PIN_PORT_D1, PIN_D1, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(PIN_PORT_D2, PIN_D2, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(PIN_PORT_D3, PIN_D3, GPIO_PIN_RESET);
    }
    lcdModeSel = lcdMode;
    HAL_Delay(50);

    /* Initialization sequence */
    if (lcdModeSel == LCD_8BIT_MODE) {
        LCD(0x38, LCD_COMMAND);
    } else {
        LCD(0x02, LCD_COMMAND);
        LCD(0x28, LCD_COMMAND);
    }
    LCD(DISP_ON_CURSOR_BLINK, LCD_COMMAND);
    LCD(INCREMENT_CURSOR,      LCD_COMMAND);
    LCD(CLEAR_SCREEN,          LCD_COMMAND);
    LCD(CURSOR_1ST_LINE_1ST_COLUMN, LCD_COMMAND);
    HAL_Delay(10);
}

void LCD_str(uint8_t *str)
{
    while (*str) {
        LCD(*str++, LCD_DATA);
    }
}

void LCD_8bit_mode(uint8_t val)
{
    for (uint8_t i = 0; i < 8; i++) {
        HAL_GPIO_WritePin(PIN_PORT_D0 + i, PIN_D0 + i,
            (GPIO_PinState)((val >> i) & 0x01));
    }
    lcdEnablePulse();
}

void LCD_4bit_mode(uint8_t val)
{
    /* upper nibble */
    for (uint8_t i = 0; i < 4; i++)
        HAL_GPIO_WritePin(PIN_PORT_D4 + i, PIN_D4 + i,
            (GPIO_PinState)((val >> (4 + i)) & 0x01));
    lcdEnablePulse();
    /* lower nibble */
    for (uint8_t i = 0; i < 4; i++)
        HAL_GPIO_WritePin(PIN_PORT_D4 + i, PIN_D4 + i,
            (GPIO_PinState)((val >> i) & 0x01));
    lcdEnablePulse();
}

void lcdEnablePulse(void)
{
    HAL_GPIO_WritePin(PIN_PORT_EN, PIN_EN, GPIO_PIN_SET);
    HAL_Delay(1);
    HAL_GPIO_WritePin(PIN_PORT_EN, PIN_EN, GPIO_PIN_RESET);
    HAL_Delay(1);
}
