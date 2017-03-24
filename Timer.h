/*
 * Timer.h
 *
 *  Created on: 24 de mar de 2017
 *      Author: aluno
 */

#ifndef TIMER_H_
#define TIMER_H_

class Timer {
public:
	typedef unsigned long long Hertz;
	typedef unsigned long long Microseconds;
	typedef unsigned long long Milliseconds;
	Timer(Hertz freq);
	~Timer();
	Milliseconds millis();
	Microseconds micros();
	void delay(Milliseconds ms);
	void delaymicro(Microseconds us);

	static void isr_handler(){
		_ticks++;
	}
private:
	static unsigned long long _ticks;


};

#endif /* TIMER_H_ */
