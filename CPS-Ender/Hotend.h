/*
 * Hotend.h
 *
 * Created: 5/10/2020 16:21:46
 *  Author: Arne Troch
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>

#ifndef HOTEND_H_
#define HOTEND_H_

void initHotend();
void setHotend(int value);

#endif /* HOTEND_H_ */