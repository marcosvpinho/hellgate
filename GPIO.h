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
	void set(bool val = 1);

private:
	 GPIO *port;

	 int pin;

};


#endif /* GPIO_H_ */
