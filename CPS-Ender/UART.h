/*
 * UART.h
 *
 * Created: 5/10/2020 16:15:04
 *  Author: Arne Troch
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>

#ifndef UART_H_
#define UART_H_

void initUSART(uint16_t ubrr);
void usart_putchar(char data);
void usart_pstr(char *s);

#endif /* UART_H_ */