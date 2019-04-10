#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	/* Replace with your application code */
	DDRC = 0x00;
	DDRD= 0xff;
	PORTD = 0xff;
	while (1)
	{
		if(!(PINC & 0x01))
		{
			if((PORTD & 0x7f) == 0x7f)
				PORTD = 0xfe;
			else
				PORTD = ((PORTD << 1) | (0x01));
			_delay_ms(300);
		}
		
		if(!(PINC & 0x02))
		{
			if((PORTD & 0xfe) == 0xfe)
				PORTD = 0x7f;
			else
				PORTD = ((PORTD >> 1) | (0x80));
			_delay_ms(300);
		}
	}
}