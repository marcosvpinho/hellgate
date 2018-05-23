/*
 * FIFO.h
 *
 *  Created on: 31 de mar de 2017
 *      Author: aluno
 */

#ifndef FIFO_H_
#define FIFO_H_

template <int Q_SIZE, typename T>
class FIFO {
public:

	static const unsigned int FIFO_ERROR_EMPTY = -1;
	static const unsigned int FIFO_ERROR_FULL = -2;

	FIFO(){ clear(); };


	~FIFO(){};

	int push(T value){
		if (_cont == Q_SIZE) return FIFO_ERROR_FULL;
		//if (((_tail+1)%Q_SIZE) == _head) return FIFO_ERROR_FULL; // erro nesta funcao

		_buffer[_tail]= value;
		T temp = _tail;
		/*update the tail*/
		_cont++;
		if (_tail >= Q_SIZE){ //fila cheia
			_tail = 0; // volta para o 'começo' da fila
		}else{
			_tail++;
		}
		return temp; // posição de inserção
	};

	T pop(){//////////////////////////////////////////////////////////
		if(_cont == 0) return (T) FIFO_ERROR_EMPTY;
		//if(_head == _tail) return (T) FIFO_ERROR_EMPTY;// retorno em formato de T só pra não dar warning
		T returnval = _buffer[_head]; // carrega proximo da fila
		_cont--;
		if (_head >= Q_SIZE) { // trata o 'fim' da fila
			_head = 0;	// retorna para o começo da fila
		}else{
			_head++;
		}
		return returnval;
	};

///////// implementar search e consulta em uma classe lista ///////////
	T search(T treta){// RFID é a treta
		for (int i=_head; i != _tail; i++){
			if (treta == consulta(i)) {
				return consulta(i);// fila é o cadastro. RFID é o codigo lido, escrito dentro da fila. A comparação é entre o conteudo de cada posição da fila com o RFID lido
			}
		}
		return -1;
	}

	T consulta(int val){// retorna item em posição val sem removê-lo
		return _buffer[val];
	}

	int tamanho(){
		return _cont;
	}
///////////////////// //////////////// / //////////////// / ///////////////

	void clear (){
		this->_head = 0;
		this->_tail = 0;
		this->_cont = 0;
	}



private:
	unsigned int _head,_tail,_cont;
	T _buffer[Q_SIZE];

};

#endif /* FIFO_H_ */
