/*
 * GPIOport.cpp
 *
 *  Created on: 24 de mar de 2017
 *      Author: aluno
 */

#include "GPIO_Port.h"

GPIO_Port::GPIO_Port() {
	// TODO Auto-generated constructor stub
enum PORT_ADD_BASE{
	AVR_PORTB= 0x0023,
	AVR_PORTC= 0x0026,
	AVR_PORTD= 0x0029
};

}

GPIO_Port::~GPIO_Port() {
	// TODO Auto-generated destructor stub
}
void GPIO_Port::set(int p, int val){
	if(val){
		port |= (1 << p);
	}else{
		port &= ~(1 << p);
	}

}
void GPIO_Port::dir(int p, int io){


}
