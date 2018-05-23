/*
 * Timer.cpp
 *
 *  Created on: 24 de mar de 2017
 *      Author: aluno
 */

#include "Timer.h"
#include <avr/io.h>
#include <avr/interrupt.h>
unsigned long long Timer::_ticks;
Timer * Timer::_singleton = 0;

Timer::Timer(Hertz freq) {
	Freq_dado = freq;
	_singleton = this;
	// TODO Auto-generated constructor stub
	TCCR0A = 0x00;	// normal operation
	TIMSK0 = 0x01; 	// ligar interrupcao de Overflow
	//lógica p seleção de divisor
	unsigned long long div=1;
	if (freq<= 15000){
		TCCR0B = 0x05; // div 1024
		div = 1024;
	}else if (freq <= 62000){
		TCCR0B = 0x04; // div 256
		div = 256;
	}else if (freq <= 2500000){
		TCCR0B = 0x03; // div 64
		div = 64;
	}else if (freq <= 20000000){
		TCCR0B = 0x02; // div 8
		div = 8;
	}else if (freq <= 16000000){
		TCCR0B = 0x01; // div 1
		div = 1;
	}
	//calcular ciclos de ticks
		long int FreqT = F_CPU / div;
		int ciclos = FreqT / freq;
		_base_freq = ciclos;
		TCNT0 = 0xFF - ciclos;// alterado p FF - ciclos // 0xFF (que eh o max) - 16 (para que de 16 ciclos de clock por tick)

}
/*
Timer::~Timer() {
	// TODO Auto-generated destructor stub
}
*/

Microseconds Timer::millis(){ //versão errada
	return (this->micros()/1000); //ticks *( 1ms/freq_dada ) //unsigned long long;
};
Milliseconds Timer::micros(){
	return _ticks * (1000000/Freq_dado);//ticks *( 1us/freq_dada ) //unsigned long long;
};

void Timer::delay(Milliseconds ms){
	udelay(ms*1000);
};
void Timer::udelay(Microseconds us){
	Microseconds t = micros();
	while (micros() - t <= us);
};

void Timer::isr_handler(){
	TCNT0 = 0xF0 - self()->_base_freq;
	_ticks++;
};

ISR (TIMER0_OVF_vect) {
	Timer::isr_handler();
}
