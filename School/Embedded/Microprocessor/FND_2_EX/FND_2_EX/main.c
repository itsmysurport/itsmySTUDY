#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRG = 0xff;
	DDRA = 0xff;
	DDRC = 0xff;
	PORTG = 0xff;
	while (1)
	{
		PORTA = 0x00;
		PORTC = 0x00;
		_delay_ms(500);
		PORTA = 0xff;
		PORTC = 0xff;
		_delay_ms(500);
	}
}