/*
 * Timer.h
 *
 *  Created on: 24 de mar de 2017
 *      Author: aluno
 */

#ifndef TIMER_H_
#define TIMER_H_

typedef unsigned long int Hertz;
typedef unsigned long long int Microseconds;
typedef unsigned long long int Milliseconds;


class Timer {
public:


	Timer(Hertz freq);

	Microseconds millis();
	Milliseconds micros();

	void delay(Milliseconds ms);
	void udelay(Microseconds us);

	static void isr_handler();

//	virtual ~Timer();
	static Timer * self() {return _singleton;}

private:
	static Timer * _singleton;
	static unsigned long long _ticks;
	Hertz Freq_dado;
	int _base_freq;
};

#endif /* TIMER_H_ */
