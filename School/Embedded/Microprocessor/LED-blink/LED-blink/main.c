#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    DDRD = 0xff;
	PORTD = 0xff;
    while (1) 
    {
		PORTD = 0xff;
		_delay_ms(300);
		PORTD = 0x00;
		_delay_ms(300);
		PORTD = 0xff;
		_delay_ms(100);
		PORTD = 0x00;
		_delay_ms(100);
		PORTD = 0xff;
		_delay_ms(50);
		PORTD = 0x00;
		_delay_ms(50);
		PORTD = 0xff;
		_delay_ms(10);
		PORTD = 0x00;
		_delay_ms(10);
		PORTD = 0xff;
		_delay_ms(5);
		PORTD = 0x00;
		_delay_ms(5);
    }
}

