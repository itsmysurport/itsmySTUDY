#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	int cnt = 0;
	DDRC = 0x00;
	DDRD = 0xff;
	PORTD = 0xff;
	/* Replace with your application code */
	while (1)
	{
		if(!(PINC & 0x01))
		{
			_delay_ms(30);
			cnt++;
			if(cnt == 3)
			{
				PORTD = 0x55;
			}
			if(cnt == 6)
			{
				PORTD = ~(0x55);
			}
			if(cnt == 9)
			{
				PORTD = 0xf0;
			}
			if(cnt == 12)
			{
				PORTD = ~(0xf0);
			}
			if(cnt == 15)
			{
				PORTD = 0xff;
			}
			while(!(PINC & 0x01))
			{
				_delay_ms(30);
			}
		}
	}
}

