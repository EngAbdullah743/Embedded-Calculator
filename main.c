/* USER CODE BEGIN Header */
/*
  • @file    : main.c
  • @brief   : Main program body for STM32 Calculator Project
  • @author  : Abdullah Ahmad
  • @date    : June 2025
  • @note    : Complete embedded calculator implementation for STM32F103C6
*/
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include <stdint.h>
#include <math.h>
#include "keypad.h"
#include "Arithmatic.h"
#include "LCD.h"

/* Private define ------------------------------------------------------------*/
#define MAX_DIGITS 10

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
void DisplayFloat(float numDisp, uint8_t dispPosition);
double calcFun(uint8_t key1, float num1, float num2);
float ConvertArrayIntoNumber(unsigned char *ptrNum);

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
    uint8_t varKey = 0, prevVarKey = 0;
    uint8_t defaultArr[] = {"Abdullah_Ahmad"};
    uint8_t clearArr[]   = {"Clear all"};
    float number1 = 0, number2 = 0;
    double result = 0; float result1 = 0;
    uint8_t numArr[MAX_DIGITS] = {0}, numCounter = 0, clearFlag = 0;

    HAL_Init();
    SystemClock_Config();
    MX_GPIO_Init();

    HAL_Delay(1000);
    LCD_init(LCD_8BIT_MODE);
    HAL_Delay(100);
    keypad_init();

    LCD(CURSOR_1ST_LINE_1ST_COLUMN, LCD_COMMAND);
    LCD_str(defaultArr);
    LCD(CURSOR_2ND_LINE_1ST_COLUMN, LCD_COMMAND);

    while (1)
    {
        HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, GPIO_PIN_SET);
        HAL_Delay(100);
        varKey = key_press();

        if (varKey == KEY_CLEAR)            // Clear key '$'
        {
            LCD(CURSOR_2ND_LINE_1ST_COLUMN, LCD_COMMAND);
            LCD_str(clearArr);
            clearFlag = 1;
        }
        else if (varKey == KEY_EQUALS)     // Equals key '='
        {
            number2 = ConvertArrayIntoNumber(numArr);
            result  = calcFun(prevVarKey, number1, number2);
            DisplayFloat((float)result, CURSOR_3RD_LINE_1ST_COLUMN);
            HAL_Delay(1000);
            clearFlag = 1;
        }
        else if ((varKey >= '0' && varKey <= '9') || (varKey == '.'))
        {
            LCD(varKey, LCD_DATA);
            if (numCounter < MAX_DIGITS - 1)
                numArr[numCounter++] = varKey;
        }
        else if (varKey != ' ')            // Operator keys
        {
            result1 = ConvertArrayIntoNumber(numArr);
            LCD(' ', LCD_DATA);
            LCD(varKey, LCD_DATA);
            LCD(' ', LCD_DATA);

            if (number1 == 0)
                number1 = result1;
            else if (number2 == 0)
            {
                number2 = result1;
                DisplayFloat(number2, CURSOR_3RD_LINE_1ST_COLUMN);
                result = calcFun(prevVarKey, number1, number2);
                DisplayFloat((float)result, CURSOR_4TH_LINE_1ST_COLUMN);
                number1 = (float)result;
                number2 = 0;
            }

            // reset for next number
            for (uint8_t i = 0; i < MAX_DIGITS; i++) numArr[i] = 0;
            numCounter = 0;
            prevVarKey = varKey;
        }

        if (clearFlag)
        {
            prevVarKey = number1 = number2 = result = 0;
            clearFlag = 0;
            for (uint8_t i = 0; i < MAX_DIGITS; i++) numArr[i] = 0;
            LCD(CLEAR_SCREEN, LCD_COMMAND);
            LCD(CURSOR_1ST_LINE_1ST_COLUMN, LCD_COMMAND);
            LCD_str(defaultArr);
            LCD(CURSOR_2ND_LINE_1ST_COLUMN, LCD_COMMAND);
        }

        HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, GPIO_PIN_RESET);
        HAL_Delay(100);
    }
}

/* (Omitted: SystemClock_Config and MX_GPIO_Init implementations) */
