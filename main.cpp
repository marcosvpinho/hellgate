/*
 * main2.cpp
 *
 *  Created on: 12 de abr de 2017
 *      Author: aluno
 */

#include <stdio.h>
#include <avr/interrupt.h>
#include <avr/io.h>

#include "UART.h"
#include "GPIO.h"
#include "Timer.h"
#include "FIFO.h"
#include "Gerencia.h"

#include "Singleton.h"
#include "RDM6300.h"
#include "UART1.h"

UART uart(19200, UART::DATABITS_8, UART::PARITY_NONE, UART::STOPBITS_1);
GPIO led_verm(11, GPIO::OUTPUT);
GPIO led_verde(9, GPIO::OUTPUT);
GPIO botao_cadastro(12, GPIO::INPUT);
GPIO botao_LimpaFifo(13, GPIO::INPUT);  /**/
GPIO botao_fechadura(7, GPIO::INPUT);	/**/
GPIO buzzer(8, GPIO::OUTPUT);			/**/
GPIO rele(10, GPIO::OUTPUT);			/**/
Gerencia RFID;
Timer timer(1000);

UART1 uart1;
RDM6300<UART1> leitor_rfid(&uart1);

// RFID Rf_Id(unsigned int id)


bool val_botao;
char buffer[64];

void liga_buzzer(){
	for (int i = 0;i<100;i++){
		buzzer.set(1);
		timer.udelay(333);
		buzzer.set(0);
		timer.udelay(333);
	}
}

void abre_porta(){
	led_verm.set(false);
	led_verde.set(true);
	rele.set(true);
	liga_buzzer();
	led_verde.set(false);
	rele.set(false);
};

void fecha_porta(){
	led_verm.set(true);
	led_verde.set(false);
	rele.set(false);
}

void print_rfid64(unsigned long long & id, bool endline = false) {
    static char buffer[32];
    union {
        unsigned long long ull;
        unsigned long ul[2];
        unsigned short us[4];
        unsigned char uc[8];
    } rfid64;
    rfid64.ull = id;
    if (endline)
        sprintf(buffer, "%04x %04x %04x %04x\r\n", rfid64.us[3], rfid64.us[2],
                rfid64.us[1], rfid64.us[0]);
    else
        sprintf(buffer, "%lu%lu", rfid64.ul[0], rfid64.ul[1]);
    uart.puts(buffer);
}


void loop() {

		unsigned long long id;
		unsigned long long ud;
	if(botao_cadastro.get() == true){
		while (uart1.has_data()) {
			leitor_rfid.parse(uart1.get());
		}
		if(leitor_rfid.get_valid_id()){
			leitor_rfid.set_valid_id(false);
			id = leitor_rfid.get_id();
			print_rfid64(id);

		}
		print_rfid64(id);



		RFID.Cadastra_RFID(id);
		abre_porta();
	}
	if(botao_fechadura.get() == true){
		while (uart1.has_data()) {

					leitor_rfid.parse(uart1.get());
				}
				if(leitor_rfid.get_valid_id()){
					leitor_rfid.set_valid_id(false);
					ud = leitor_rfid.get_id();
					print_rfid64(ud);
				}


		if(RFID.Verifica_RFID(ud)){
			abre_porta();
		}else fecha_porta();
	}
	if(botao_LimpaFifo.get()==true){
		RFID.Deleta_RFID();

	}

	/*
//	RFID.Cadastra_RFID(123123124); // exclusivo testes
	liga_buzzer();
	if(RFID.Verifica_RFID(123123124) == true){
		abre_porta();
		timer.delay(1000);
	}else{
		if(botao_cadastro.get() == true){
			RFID.Cadastra_RFID(123123124); // 123123123 é o numero recebido
		}
	}
		fecha_porta();
		timer.delay(1000);*/
};

void setup(){
	sei();
};

int main(){
	setup();
	while (true)
		loop();
};




