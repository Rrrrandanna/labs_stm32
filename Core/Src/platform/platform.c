/* Директива препроцессора для подключения заголовочного файла */
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

uint32_t ini = 0;
/* Повторяющийся вызов */
void plt_process(void)
{
	HAL_UART_Transmit(&huart1, "hello", 5, HAL_MAX_DELAY);
//	plt_adc_start();
//	plt_adc_conversion_poll();
//	ini = plt_adc_get_value();
//	plt_adc_stop();
	/* Устанавливаем задержку */
	plt_delay(500);
}

/* Перенести в main.c в user code */
//void plt_delay(uint32_t delay_ms)
//{
//	HAL_Delay(delay_ms);
//}
