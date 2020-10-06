/*
 * temperature.h
 *
 * Created: 05/10/2020 16:25:25
 *  Author: Siemen
 */ 


#ifndef TEMPERATURE_H_
#define TEMPERATURE_H_

//If multiple measurements are added together, the oversampleNR should be altered
#define OVERSAMPLENR 1

//The code below: https://github.com/Creality3DPrinting/Ender-3/blob/master/Ender-3%20Firmware%20(Marlin)/Ender-3%20(includes%20power%20failure%20resume-%20English)/Marlin/thermistortable_6.h
// 100k Epcos thermistor
const short temptable[][2] = {
	{    1 * OVERSAMPLENR, 350 },
	{   28 * OVERSAMPLENR, 250 }, // top rating 250C
	{   31 * OVERSAMPLENR, 245 },
	{   35 * OVERSAMPLENR, 240 },
	{   39 * OVERSAMPLENR, 235 },
	{   42 * OVERSAMPLENR, 230 },
	{   44 * OVERSAMPLENR, 225 },
	{   49 * OVERSAMPLENR, 220 },
	{   53 * OVERSAMPLENR, 215 },
	{   62 * OVERSAMPLENR, 210 },
	{   71 * OVERSAMPLENR, 205 }, // fitted graphically
	{   78 * OVERSAMPLENR, 200 }, // fitted graphically
	{   94 * OVERSAMPLENR, 190 },
	{  102 * OVERSAMPLENR, 185 },
	{  116 * OVERSAMPLENR, 170 },
	{  143 * OVERSAMPLENR, 160 },
	{  183 * OVERSAMPLENR, 150 },
	{  223 * OVERSAMPLENR, 140 },
	{  270 * OVERSAMPLENR, 130 },
	{  318 * OVERSAMPLENR, 120 },
	{  383 * OVERSAMPLENR, 110 },
	{  413 * OVERSAMPLENR, 105 },
	{  439 * OVERSAMPLENR, 100 },
	{  484 * OVERSAMPLENR,  95 },
	{  513 * OVERSAMPLENR,  90 },
	{  607 * OVERSAMPLENR,  80 },
	{  664 * OVERSAMPLENR,  70 },
	{  781 * OVERSAMPLENR,  60 },
	{  810 * OVERSAMPLENR,  55 },
	{  849 * OVERSAMPLENR,  50 },
	{  914 * OVERSAMPLENR,  45 },
	{  914 * OVERSAMPLENR,  40 },
	{  935 * OVERSAMPLENR,  35 },
	{  954 * OVERSAMPLENR,  30 },
	{  970 * OVERSAMPLENR,  25 },
	{  978 * OVERSAMPLENR,  22 },
	{ 1008 * OVERSAMPLENR,   3 },
	{ 1023 * OVERSAMPLENR,   0 } // to allow internal 0 degrees C
};

//This function uses a value between 0 and 1024 from the ADC to determine the temperature (for 100K epcos thermistor).
short voltage_to_temp(short);


#endif /* TEMPERATURE_H_ */