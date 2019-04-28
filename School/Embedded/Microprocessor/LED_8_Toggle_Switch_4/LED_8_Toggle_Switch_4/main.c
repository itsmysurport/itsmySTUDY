#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	/* Replace with your application code */
	DDRC = 0x00;
	DDRD= 0xff;
	PORTD = 0x55;
	while (1)
	{
		if(!(PINC & 0x01))
		{
			PORTD = ~(PORTD);
			_delay_ms(300);
		}
	}
}