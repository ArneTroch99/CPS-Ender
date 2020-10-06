/*
 * ADC.c
 *
 * Created: 05/10/2020 14:08:27
 *  Author: Siemen
 */ 

#include "ADC.h"
#include <avr/io.h>


// This function intializes the ADC 13 for use of input: "thermistor 0".
void ADC_init(){
	
	//Reference: analog ground, input: ADC 13, left adjusted
	ADMUX = 0b101;	
	//ADC 13 input (MSB)
	ADCSRB = 1 << 3;
	//Enable and factor 128 prescaler (16MHz -> 128 kHz)
	ADCSRA = 0b10000111;
}

int16_t ADC_read(){
	
	//Start conversion
	ADCSRA |= 1 << 6;
	//Wait for result
	while ( (ADCSRA & (1 << 4)) == 0);
	//Read results
	int16_t result = ADCL + (ADCH << 8);
	//Clear "finished"-bit
	ADCSRA |= 1 << 4;
	return result;
}