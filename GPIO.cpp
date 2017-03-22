/*
 * GPIO.cpp
 *
 *  Created on: 22 de mar de 2017
 *      Author: aluno
 */

#include "GPIO.h"
#include <avr/io.h>

GPIO::GPIO(int pin, portDirection_t dir){

	if(pin <=7){
		const unsigned char mask=(1<<pin);

		*ddr= DDRD | mask;
		*port=PORTD;

	}else{
		int p=pin-8;
		const unsigned char mask=(1<<p);
		*ddr= DDRB | mask;
		*port=PORTB;
	}
}

bool GPIO::get(){
	return this->port;
}

void GPIO::set(bool val){

}
