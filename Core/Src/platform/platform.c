/* Директива препроцессора для подключения заголовочного файла */
#include "platform.h"
#include "main.h"
#include "lab1_gpio/lab1_gpio.h"
//#include "lab2_timer/lab2_timer.h"
//#include "lab3_stepper/lab3_stepper.h"
//#include "lab4_adc/lab4_adc.h"
extern UART_HandleTypeDef huart1;
/* Однократный вызов */
int plt_init(void)
{

	return 0;
}


/* Повторяющийся вызов */
void plt_process(void)
{
    static uint8_t brightness = 0;
    static int8_t direction = 1;

    for (uint8_t i = 0; i < 100; i++)
    {
        if (i < brightness)
        {
            HAL_GPIO_WritePin(USER_LED_GPIO_Port, USER_LED_Pin, GPIO_PIN_SET);
        }
        else
        {
            HAL_GPIO_WritePin(USER_LED_GPIO_Port, USER_LED_Pin, GPIO_PIN_RESET);
        }

        for (volatile uint32_t d = 0; d < 300; d++)
        {
            // короткая задержка
        }
    }

    brightness += direction;

    if (brightness >= 100)
    {
        direction = -1;
    }
    else if (brightness == 0)
    {
        direction = 1;
    }
}
/* Перенести в main.c в user code */
//void plt_delay(uint32_t delay_ms)
//{
//	HAL_Delay(delay_ms);
//}
