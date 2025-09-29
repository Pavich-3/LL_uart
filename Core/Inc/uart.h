#ifndef __USART_H__
#define __USART_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "main.h"

void UART_Init(LL_USART_InitTypeDef* uartHandle);
void sendChar(char ch);

#ifdef __cplusplus
}
#endif

#endif

