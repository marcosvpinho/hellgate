/*
 * GPIO.h
 *
 *  Created on: 22 de mar de 2017
 *      Author: aluno
 */

#include <stdint.h>

#ifndef GPIO_H_
#define GPIO_H_

class GPIO {
public:
	enum PortDirection_t {
		INPUT = 0,
		OUTPUT = 1
	};


	GPIO(int pin, PortDirection_t dir);
	~GPIO();

	bool get();
	void set(bool valor);

private :
	unsigned char _mask;
	volatile uint8_t * _port;
	volatile uint8_t * _pin;
	volatile uint8_t * _ddr;
};


#endif /* GPIO_H_ */
