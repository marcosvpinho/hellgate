/*
 * gerencia.cpp
 *
 *  Created on: 26 de abr de 2017
 *      Author: aluno
 */

#include "Gerencia.h"

	FIFO<64,unsigned long long> _ger_fifo;

Gerencia::Gerencia() {
	// TODO Auto-generated constructor stub
}


bool Gerencia::Verifica_RFID(unsigned long long numero_rfid){ // retorna true ou false se encontrar ou não
	if (_ger_fifo.search(numero_rfid) == (unsigned long long)-1){
		return false;
	}
	return true;
}

void Gerencia::Cadastra_RFID(unsigned long long numero_rfid){ // cadastra
	if (!Verifica_RFID(numero_rfid)){ // não encontrou na fila
		_ger_fifo.push(numero_rfid);
	}
}

bool Gerencia::Deleta_RFID(){
	_ger_fifo.clear();
	return true;
}


