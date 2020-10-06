/*
 * temperature.c
 *
 * Created: 05/10/2020 16:25:14
 *  Author: Siemen
 */ 

#include "temperature.h"

short voltage_to_temp(short voltage){
	
	short adc_value;
	
	for (short i = 0; i < 38; i++){
		 adc_value = temptable[i][0];
		 
		 if (adc_value > voltage) return temptable[i - 1][1]; //Returning the temperature, rounded up
	}
	
	return -1;	//Error code 
}