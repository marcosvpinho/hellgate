/*
 * UART.cpp
 *
 *  Created on: 15 de mar de 2017
 *      Author: aluno
 */

#include "UART.h"
#include <avr/io.h>

UART::UART(int rate, int stop_bit, int parity, int db):
_baud_rate(rate),_stop_bit(stop_bit),
_parity(parity),_data_bits(db)
{
	UBRR0=(F_CPU/(16ul *_baud_rate))-1;
	UCSR0B=(1<<RXEN0)|(1<<TXEN0);
	UCSR0C=(3<<UCSZ00);

}
void put(unsigned char data){


}

