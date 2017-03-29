/*
 * GPIO.cpp
 *
 *  Created on: 22 de mar de 2017
 *      Author: aluno
 */

#include "GPIO.h"
#include <avr/io.h>
#include "GPIO_Port.h"

GPIO::GPIO(int pin, portDirection_t dir){
	if(pin <=7){
		port =GPIO_PORT::portD;

	}else if(pin<13){
		port =GPIO_PORT::portC;
		pin =14;
	}else{
		port = GPIO_PORT::portB;
		pin =8;
	}
	_port->dir(pin, dir);
}

bool GPIO::get(){
	return this->port->get(pin);
}

void GPIO::set(bool val){
		port->set(pin,val);
}
void GPIO::clear(){
	this->set(0);
}
