/*
 * Timer.cpp
 *
 *  Created on: 24 de mar de 2017
 *      Author: aluno
 */

#include "Timer.h"

static unsigned long long _ticks;

Timer::Timer() {
	TCCR0A = 0x00; // Normal operation
	TCCR0B = 0x05; // div 1024
	TIMSK0 = 0x01; // Liga int de Overflow
	TCNT0  = 0xF0;
}

Timer::~Timer() {
	// TODO Auto-generated destructor stub
}


Milliseconds Timer::millis(){
	return _ticks;

}
Microseconds Timer::micros(){


}
void  Timer::delay(Milliseconds ms){


}
void Timer::delaymicro(Microseconds us){

}

