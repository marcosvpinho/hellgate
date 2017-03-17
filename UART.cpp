/*
 * UART.cpp
 *
 *  Created on: 15 de mar de 2017
 *      Author: aluno
 */

#include "UART.h"
#include <avr/io.h>

UART::UART(unsigned long rate, StopBits_t stop_bit , ParityBits_t parity , DataBits_t db):
_baud_rate(rate),
_stop_bit(stop_bit),
_parity(parity),
_data_bits(db)
{
	UBRR0=(F_CPU/(16ul * rate))-1;
	//Liga TX e RX
	UCSR0B=(1<<RXEN0)|(1<<TXEN0);

	//SET DATA BIT
	if(db == DATABITS_9){
		//........

	}else{
		UCSR0C = (UCSR0C & ~(3 << UCSZ00))|(db << UCSZ00);
	}

	//SET PARITY
	UCSR0C = ( UCSR0C & ~(3 << UPM00)) | (parity << UPM00);
	unsigned char reg = UCSR0C; //read
	reg = ( reg & ~(1 << USBS0)) | (stop_bit << USBS0);
	UCSR0C = reg;

	//set frame: BN1
	//UCSR0C=(3<<UCSZ00);

}
// Wait until UDR is empty
void put(unsigned char data){
	while(!(UCSR0A &(1 << UDRE0)));
		//send data
		UDR0 = data;

}


unsigned char UART::get(){
	//wait until data is received
	while(!(UCSR0A & (1<<RXC0)));
	return UDR0; //Return receive data
}

