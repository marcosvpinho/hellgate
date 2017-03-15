/*
 * UART.h
 *
 *  Created on: 15 de mar de 2017
 *      Author: aluno
 */

#ifndef UART_H_
#define UART_H_

class UART {
public:
	UART(int rate, int stop_bit, int parity, int db);
	void put(unsigned char data);
	unsigned char get();
	void puts(char * str);

private:
	int _baud_rate;
	int _stop_bit;
	int _parity;
	int _data_bits;

};

#endif /* UART_H_ */
