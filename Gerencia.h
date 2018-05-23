/*
 * gerencia.h
 *
 *  Created on: 26 de abr de 2017
 *      Author: aluno
 */

#ifndef GERENCIA_H_
#define GERENCIA_H_

#include "FIFO.h"



class Gerencia {
public:

	Gerencia();

	bool Verifica_RFID(unsigned long long numero_rfid);

	void Cadastra_RFID(unsigned long long numero_rfid);

	bool Deleta_RFID();

private:


};
#endif /* GERENCIA_H_ */
