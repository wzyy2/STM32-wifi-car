#ifndef __USART1_H
#define	__USART1_H

#include "stm32f10x.h"
#include <stdio.h>

void USART2_Config(void);
void NVIC_Configuration(void);
int fputc(int ch, FILE *f);

#endif /* __USART1_H */