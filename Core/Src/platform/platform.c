/* Директива препроцессора для подключения заголовочного файла */
#include "platform.h"
#include "main.h"
//#include "lab1_gpio/lab1_gpio.h"
#include "lab2_timer/lab2_timer.h"
//#include "lab3_stepper/lab3_stepper.h"
//#include "lab4_adc/lab4_adc.h"
extern UART_HandleTypeDef huart1;
/* Однократный вызов */
int plt_init(void)
{
	  plt_timer_set(200);
	    plt_timer_start_irq();
	return 0;
}


/* Повторяющийся вызов */
void plt_process(void)
{

}
void plt_timer_irq_cb(void)
{
    HAL_GPIO_TogglePin(USER_LED_GPIO_Port, USER_LED_Pin);
}


/* Перенести в main.c в user code */
//void plt_delay(uint32_t delay_ms)
//{
//	HAL_Delay(delay_ms);
//}
