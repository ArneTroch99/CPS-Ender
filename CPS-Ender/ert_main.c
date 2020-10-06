/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ert_main.c
 *
 * Code generated for Simulink model 'PID'.
 *
 * Model version                  : 1.42
 * Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
 * C/C++ source code generated on : Thu Oct  1 16:35:16 2020
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include <stddef.h>
#include <stdio.h>              /* This ert_main.c example uses printf/fflush */
#include "PID.h"                       /* Model's header file */
#include "rtwtypes.h"
#include "UART.h"
#include "Hotend.h"

#include <avr/io.h>
#include <avr/interrupt.h>

#define BAUD 9600
#define MYUBRR F_CPU/16/BAUD-1

void initTimer(void);

/*
 * Associating rt_OneStep with a real-time clock or interrupt service routine
 * is what makes the generated code "real-time".  The function rt_OneStep is
 * always associated with the base rate of the model.  Subrates are managed
 * by the base rate from inside the generated code.  Enabling/disabling
 * interrupts and floating point context switches are target specific.  This
 * example code indicates where these should take place relative to executing
 * the generated code step function.  Overrun behavior should be tailored to
 * your application needs.  This example simply sets an error status in the
 * real-time model and returns from rt_OneStep.
 */


volatile int aan;
volatile int pwm = 0;
void rt_OneStep(void);
void rt_OneStep(void)
{
	
  static boolean_T OverrunFlag = false;

  /* Disable interrupts here */

  /* Check for overrun */
  if (OverrunFlag) {
    rtmSetErrorStatus(PID_M, "Overrun");
    return;
  }

  OverrunFlag = true;

  /* Save FPU context here (if necessary) */
  /* Re-enable timer or interrupt here */
  /* Set model inputs here */

  /* Step the model */
  PID_step();

  /* Get model outputs here */

  /* Indicate task complete */
  OverrunFlag = false;

  /* Disable interrupts here */
  /* Restore FPU context here (if necessary) */
  /* Enable interrupts here */
}


int_T main(int_T argc, const char *argv[])
{
	aan = false;
	DDRA |= 0b00000001;

	initTimer();
	sei();
	initUSART(MYUBRR);
	initHotend();
		
	/* Unused arguments */
	(void)(argc);
	(void)(argv);

	/* Initialize model */
	PID_initialize();

	/* Attach rt_OneStep to a timer or interrupt service routine with
	 * period 1.0 seconds (the model's base sample time) here.  The
	 * call syntax for rt_OneStep is
	 *
	 *  rt_OneStep();
	*/
	fflush((NULL));
	while (rtmGetErrorStatus(PID_M) == (NULL)) {
		/*  Perform other application tasks here */
	}

	/* Disable rt_OneStep() here */

	/* Terminate model */
	PID_terminate();
	return 0;
}


void initTimer(){
	// Make sure timer/counter0 is enabled
	PRR0 |= 1 << 2;
	// Enable bit set on compare
	TCCR1A = 0b11000100;
	// Enable 1024 prescaler
	TCCR1B = 0b1101;
	// Set the compare registers
	OCR1A = 0b0011110100001001;
	// Enable the interrupt
	TIMSK1 |= 1 << 1;
}

ISR(TIMER1_COMPA_vect){
	if (aan == false){
		PORTA |= 0b00000001;
		aan = true;
	} else {
		PORTA &= 0b11111110;
		aan = false;
	}	
	TIFR1 |= 0b00000010;
	//char* strB = "Ne seconde";
	//usart_pstr(strB);
	if (pwm == 40){
		pwm = 0;
	}
	pwm += 1;
	setHotend(pwm);
	if (pwm%5==0){
		usart_putchar('a');
	}
}
