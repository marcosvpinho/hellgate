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
	enum StopBits_t{
		STOPBITS_1 = 0,
		STOPBITS_2 = 1
	};
	enum ParityBits_t{
			PARITY_NONE = 0,
			PARITY_EVEN = 2,
			PARITY_ODD = 3
		};
	enum DataBits_t{
			DATABITS_5 = 0,
			DATABITS_6 = 1,
			DATABITS_7 = 2,
			DATABITS_8 = 3,
			DATABITS_9 = 7

		};
	UART(unsigned long rate, StopBits_t stop_bit , ParityBits_t parity , DataBits_t db);
	void put(unsigned char data);
	unsigned char get();
	void puts(char * str);

private:
	unsigned long _baud_rate;
	StopBits_t _stop_bit;
	ParityBits_t _parity;
	DataBits_t _data_bits;

};

#endif /* UART_H_ */
