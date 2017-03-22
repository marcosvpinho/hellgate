/*
 * GPIO.h
 *
 *  Created on: 22 de mar de 2017
 *      Author: aluno
 */
#include <avr/io.h>
#ifndef GPIO_H_
#define GPIO_H_

class GPIO {
public:

	enum portDirection_t{
		INPUT =0,
		OUTPUT=1
	};

	GPIO(int pin, portDirection_t dir);
	bool get();
	void set(bool val);

private:
	 uint8_t *port;
	 uint8_t *ddr;
	 uint8_t *pin;

};


#endif /* GPIO_H_ */
