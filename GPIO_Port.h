/*
 * GPIO_port.h
 *
 *  Created on: 24 de mar de 2017
 *      Author: aluno
 */

#ifndef GPIO_PORT_H_
#define GPIO_PORT_H_

namespace GPIO_Port{
class GPIO_Port {
public:
	GPIO_Port();
	~GPIO_Port();
	void dir(int p, int io);
	void set(int p, int val =1);
	void clear(int p);
	int get(int p);

private:
	unsigned char pin;
	unsigned char ddr;
	unsigned char port;

};
extern GPIO_Port * portB;
extern GPIO_Port * portC;
extern GPIO_Port * portD;
}

#endif /* GPIO_PORT_H_ */
