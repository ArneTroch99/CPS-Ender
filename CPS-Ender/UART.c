/*
 * UART.c
 *
 * Created: 5/10/2020 16:14:45
 *  Author: Arne Troch
 */ 

#include "UART.h"

void initUSART(uint16_t ubrr){
	UBRR0H = (uint8_t)(ubrr>>8);
	UBRR0L = (uint8_t)(ubrr);
}

void usart_putchar(char data){
	/*wait for empty transmit buffer*/
	while(!((UCSR0A)& (_BV(UDRE0))));
	UDR0 = data;
}

void usart_pstr(char *s){
	while(*s){
		usart_putchar(*s);
		s++;
	}
}