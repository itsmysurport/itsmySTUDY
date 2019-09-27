/*
 * test123.c
 *
 * Created: 2019-09-20 오후 7:50:45
 * Author : test
 */ 

#define F_CPU 16000000UL
#include <util/delay.h>
#include <avr/io.h>

int main(void)
{
	// PA0 - (+)
	
	/* In Arduino
	pinMode(PA0, OUTPUT);
	*/
	
	DDRA = 0xff;
	
    /* Replace with your application code */
    while (1) 
    {
		/* In Arduino
		digitalWrite(PA0, HIGH);
		*/
		// IN PORT, 1 = HIGH, 0 = LOW
		PORTA = 0xff;
		_delay_ms(1000);	// 1000 Millisecond = 1 second
		PORTA = 0x00;
		_delay_ms(1000);
    }
}

