/*
 * GPIO.cpp
 *
 *  Created on: 22 de mar de 2017
 *      Author: aluno
 */

#include "GPIO.h"
#include <avr/io.h>


GPIO::GPIO(int pin, PortDirection_t dir){
	// Calcular mascara
	// configurar DDR
	if ((0 <= pin) & (pin <= 7)){
		_mask = (1 << pin);
		_ddr = &DDRD;
		_pin = &PIND;
		_port = &PORTD;
	}else if((8 <= pin) & (pin <= 13)){
		_mask = (1 << (pin-8));
		_ddr = &DDRB;
		_pin = &PINB;
		_port = &PORTB;
	}else if((pin >= 14) & (pin <=19)){ // PIN C
		 _mask = (1 << (pin-14));
		_ddr = &DDRC;
		_pin = &PINC;
		_port = &PORTC;
	}

	if(dir==OUTPUT){
		*_ddr |= _mask;
	}else{
		*_ddr &= ~_mask;
	}

}

GPIO::~GPIO() {};

bool GPIO::get(){
	//ler do pino
	return (*_pin & _mask);
};

void GPIO::set(bool valor){
	//escrever na port
	if (valor){
		*_port |= _mask;
	}else{
		*_port &= ~_mask;
	};
};
