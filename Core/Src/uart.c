#include "uart.h"

void UART_Init(LL_USART_InitTypeDef* uartHandle)
{
	LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOA);
	LL_APB2_GRP1_EnableClock(LL_APB2_GRP1_PERIPH_USART1);

	LL_GPIO_InitTypeDef GPIO_InitSturct = {
			.Pin = LL_GPIO_PIN_9,
			.Mode = LL_GPIO_MODE_ALTERNATE,
			.OutputType = LL_GPIO_OUTPUT_PUSHPULL,
			.Pull = LL_GPIO_PULL_NO,
			.Speed = LL_GPIO_SPEED_FREQ_VERY_HIGH,
			.Alternate = LL_GPIO_AF_7
	};
	LL_GPIO_Init(GPIOA, &GPIO_InitSturct);

	uartHandle->BaudRate = 9600;
	uartHandle->DataWidth = LL_USART_DATAWIDTH_8B;
	uartHandle->StopBits = LL_USART_STOPBITS_1;
	uartHandle->Parity = LL_USART_PARITY_NONE;
	uartHandle->TransferDirection = LL_USART_DIRECTION_TX;
	uartHandle->HardwareFlowControl = LL_USART_HWCONTROL_NONE;
	uartHandle->OverSampling = LL_USART_OVERSAMPLING_16;
	LL_USART_Init(USART1, uartHandle);
}
