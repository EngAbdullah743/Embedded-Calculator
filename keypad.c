#include "keypad.h"

void keypad_init(void)
{
    HAL_GPIO_WritePin(PIN_PORT_ROW1, PIN_ROW1, GPIO_PIN_SET);
    HAL_GPIO_WritePin(PIN_PORT_ROW2, PIN_ROW2, GPIO_PIN_SET);
    HAL_GPIO_WritePin(PIN_PORT_ROW3, PIN_ROW3, GPIO_PIN_SET);
    HAL_GPIO_WritePin(PIN_PORT_ROW4, PIN_ROW4, GPIO_PIN_SET);
}

/* Returns pressed key or ' ' if none */
unsigned char key_press(void)
{
    unsigned char row, idx;
    unsigned char key_arr[16] = {
        KEY_ROW1_CLM1, KEY_ROW2_CLM1, KEY_ROW3_CLM1, KEY_ROW4_CLM1,
        KEY_ROW1_CLM2, KEY_ROW2_CLM2, KEY_ROW3_CLM2, KEY_ROW4_CLM2,
        KEY_ROW1_CLM3, KEY_ROW2_CLM3, KEY_ROW3_CLM3, KEY_ROW4_CLM3,
        KEY_ROW1_CLM4, KEY_ROW2_CLM4, KEY_ROW3_CLM4, KEY_ROW4_CLM4
    };

    for (uint8_t col = 0; col < 4; col++)
    {
        uint16_t colPin = PIN_COLUMN1 << col;
        GPIO_TypeDef *colPort = (GPIO_TypeDef *)PIN_PORT_COLUMN1;
        if (HAL_GPIO_ReadPin(colPort, colPin) == GPIO_PIN_SET)
        {
            row = check_row(colPort, colPin);
            if (row > 0)
            {
                idx = col * 4 + (row - 1);
                return key_arr[idx];
            }
        }
    }
    return KEY_NO_PRESS;
}

unsigned char check_row(GPIO_TypeDef *port, uint16_t pin)
{
    unsigned char row = 0;
    for (uint8_t r = 0; r < 4; r++)
    {
        HAL_GPIO_WritePin(PIN_PORT_ROW1 << r, PIN_ROW1 << r, (r==0?GPIO_PIN_RESET:GPIO_PIN_SET));
        HAL_Delay(1);
        if (HAL_GPIO_ReadPin(port, pin) == GPIO_PIN_RESET)
        {
            row = r + 1;
        }
        HAL_GPIO_WritePin(PIN_PORT_ROW1 << r, PIN_ROW1 << r, GPIO_PIN_SET);
        if (row) break;
    }
    return row;
}
