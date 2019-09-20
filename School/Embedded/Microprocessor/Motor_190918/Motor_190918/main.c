/*
 * Motor_190918.c
 *
 * Created: 2019-09-18 오전 10:02:28
 * Author : test
 * 승호 바보
 */ 

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRB = 0xE0;
    DDRD = 0x0F;
    while (1) 
    {
		PORTB = 0xB0;
		PORTD = 0x01;
		_delay_ms(5000);
		
		PORTB = 0x70;
		PORTD = 0x08;
		_delay_ms(5000);
		
		PORTB = 0xF0;
		PORTD = 0x08;
		_delay_ms(5000);
    }
}

