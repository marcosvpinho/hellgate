#include <avr/io.h>
#include <util/delay.h>

char pin =5;
const unsigned char led_mask=(1<<pin);
bool led_state=0;

void acende_led(){
	led_state=1;
	PORTB=(led_state <<5);
	_delay_ms(1000);
}

void apaga_led(){
	led_state=0;
	PORTB=(led_state <<5);
	_delay_ms(1000);

}
void setup(){
	DDRB= DDRB | led_mask;
}

void loop(){
	acende_led();
	apaga_led();
}


int main(){
	setup();
	while(true) loop();
	return 0;
}


