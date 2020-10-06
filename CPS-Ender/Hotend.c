/*
 * Hotend.c
 *
 * Created: 5/10/2020 16:21:36
 *  Author: Arne Troch
 */ 

#include "Hotend.h"

void initHotend(){
	//set PB4 as an output
	DDRB |=  (1<<PB4);
	
	//set fast PWM mode and set non-inverting mode
	TCCR2A |= (1<<WGM20)|(1<<WGM21)|(1<<COM2A1);
	
	//prescaler of 1024
	TCCR2B |= (1<<WGM22)|(1<<CS22)|(1<<CS21)|(1<<CS20);
		
}

void setHotend(int value){
	//see if the value is valid
	if(value < 40 & value > 0){
		
		//calculate the duty cycle
		float duty = value/40;
		uint8_t duty8bit = duty * 256;
		
		//set the duty cycle
		OCR2A = duty8bit;
		
		} else {
		//invalid value -> turn off the hotend
		OCR2A = 0;
		}
}