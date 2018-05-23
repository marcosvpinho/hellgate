/*
 * UART.cpp
 *
 *  Created on: 15 de mar de 2017
 *      Author: aluno
 */

#include "UART.h"
#include <avr/interrupt.h>
#include <avr/io.h>



FIFO<8,char> rx_fifo; // fila de char de 8 posicoes
UART * UART::__singleton = 0;


UART::UART(unsigned long bd, DataBits_t db, ParityBits_t pr, StopBits_t sb)
: _baudrate(bd), _databits(db), _paridade(pr), _stopbits(sb)
{
	//set baudrate
	UBRR0 = (F_CPU / (16ul * this->_baudrate)) -1;
	// liga Tx e Rx
	UCSR0B = (1<<RXEN0)|(1<<TXEN0);
	UCSR0C = (3<<UCSZ00);


//set databits
	if (_databits == DATABITS_9){ // recebi 9 bits

	}else{ // recebi 8 bits
		UCSR0C = (UCSR0C & ~(3 << UCSZ00)) | (_databits << UCSZ00);
	}
//set parity
	UCSR0C = (UCSR0C & ~(3 << UPM00)) | (_paridade << UPM00);

//set stopbits
//	unsigned char reg = UCSR0C; //READ
//	reg = (reg & ~(1 << USBS0)) | (_stopbits << USBS0); //Modify
//	UCSR0C = reg; //update
	UCSR0C = (UCSR0C & ~(1 << USBS0)) | (_stopbits << USBS0); // read, modify, update (faz tudo das 3 linhas acima)

	__singleton = this;
}




//UART::~UART() {
	// TODO Auto-generated destructor stub
//}

void UART::put(unsigned char dado){
	// wait until UDR is empty
	while( !(UCSR0A & (1 <<UDRE0)));
	// TXCIE0
	//send data
	UDR0 = dado;
}
unsigned char UART::get(){

	 UCSR0B = (UCSR0A & 1<<RXC0); //UCSR0A =  USART Receive Complete
	return rx_fifo.pop(); ////////////////////////////////////////////


}

void UART::puts(const char * str){
	while(*str != '\0'){
		this -> put(*str);
		str++;
	}
}

void UART::isr_rx_handler(){
	cli();
	self()->_rx_fifo.push(UDR0);
	sei();
}

void UART::isr_tx_handler(){
	cli();// desabilitando interrups
	if(self()->_tx_fifo.tamanho()!=0) UDR0 = self()->_tx_fifo.pop();
	sei();//habilitando
}


#ifdef __AVR_ATmega2560__
ISR(USART0_RX_vect)
#else
ISR(USART_RX_vect)
#endif
{
    //SEU CÓDIGO AQUI!!!
	UART::isr_rx_handler();
}

#ifdef __AVR_ATmega2560__
ISR(USART0_UDRE_vect)
#else
ISR(USART_UDRE_vect)
#endif
{
    //SEU CÓDIGO AQUI!!!
	UART::isr_tx_handler();
}


//rxc_handler(){
//	rx_fifo.push(UDR0);
//}


