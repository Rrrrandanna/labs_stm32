/* Директива препроцессора для подключения заголовочного файла */
#include <stdint.h>
extern volatile uint32_t adc_value;
extern volatile float adc_voltage;
#include "platform.h"
#include "main.h"
//#include "lab1_gpio/lab1_gpio.h"
//#include "lab2_timer/lab2_timer.h"
//#include "lab3_stepper/lab3_stepper.h"
#include "lab4_adc/lab4_adc.h"
extern UART_HandleTypeDef huart1;
/* Однократный вызов */
int plt_init(void)
{

	return 0;
}


/* Повторяющийся вызов */
void plt_process(void)
{
	plt_adc_start();

	plt_adc_conversion_poll();

	adc_value = plt_adc_get_value();
	adc_voltage = plt_adc_get_voltage();

	plt_adc_stop();

	if ((adc_value > 3000) || (adc_voltage > 3.0f))
	   {
		   HAL_GPIO_WritePin(USER_LED_GPIO_Port, USER_LED_Pin, GPIO_PIN_SET);
	   }
	   else
	   {
		   HAL_GPIO_WritePin(USER_LED_GPIO_Port, USER_LED_Pin, GPIO_PIN_RESET);
	   }

	/* Устанавливаем задержку */
	plt_delay(500);
}

/* Перенести в main.c в user code */
//void plt_delay(uint32_t delay_ms)
//{
//	HAL_Delay(delay_ms);
//}
