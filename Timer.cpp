/*
 * Timer.cpp
 *
 *  Created on: 24 de mar de 2017
 *      Author: aluno
 */

#include "Timer.h"
#include <avr/io.h>

static unsigned long long _ticks;

typedef unsigned long long Hertz;
typedef unsigned long long Microseconds;
typedef unsigned long long Milliseconds;

Timer::Timer(Hertz freq) {
	TCCR0A = 0x00; // Normal operation
	TCCR0B = 0x05; // div 1024
	TIMSK0 = 0x01; // Liga int de Overflow
	TCNT0  = 0xF0;
	/*
	 * 			div		Fmin	Fmax
	 * 			1
	 * 			8
	 * 			64		62001	250000
	 * 			256		15001	62000
	 * 			1024	62		15000
	 */
	//loógica para selecionar divisor

	if(freq=15000){
		TCCR0B = 0x05; //div 1024
	}else if(freq <= 62000){
		TCCR0B = 0x04;
	}else if(freq <= 250000){
		TCCR0B = 0x03;
	}else if(freq <= 2000000){
		TCCR0B = 0x02;
	}else if(freq <= 16000000){
		TCCR0B = 0x01;
	}
	// TCCR0B = FREQUENCIA;
	Hertz ciclos =
	//Freq_timer = Fre/ div

		;
	//calcular ciclos de timer

	TCNT0 = 0xFF - ciclos;
}

Timer::~Timer() {
	// Todo Auto-generated destructor stub
}


Milliseconds Timer::millis(){

	return _ticks;
}

Microseconds Timer::micros(){

	return _ticks;
}

void  Timer::delay(Milliseconds ms){

	udelay(ms*1000);
}

void Timer::delaymicro(Microseconds us){

}

