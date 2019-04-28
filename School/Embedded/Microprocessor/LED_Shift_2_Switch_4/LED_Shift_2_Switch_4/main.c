#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	/* Replace with your application code */
	DDRC = 0x00;
	DDRD= 0xff;
	PORTD = 0xfc;
	
	while (1)
	{
		if(!(PINC & 0x01))
		{
			if((PORTD & 0x3f) == 0x3f)
				PORTD = 0x7e;
			else if((PORTD & 0x7e) == 0x7e)
				PORTD = 0xfc;	
			else
				PORTD = ((PORTD << 1) | (0x01));
			_delay_ms(300);
		}
		
		if(!(PINC & 0x02))
		{
			if((PORTD & 0xfc) == 0xfc)
				PORTD = 0x7e;
			else if((PORTD & 0x7e) == 0x7e)
				PORTD = 0x3f;
			else
				PORTD = ((PORTD >> 1) | (0x80));
			_delay_ms(300);
		}
		
		if(!(PINC & 0x04))
		{
			if((PORTD & 0x3f) == 0x3f)
				PORTD = 0xfc;
			else if((PORTD & 0x7e) == 0x7e)
				PORTD = 0xf9;
			else if((PORTD & 0x9f) == 0x9f)
				PORTD = 0x7e;
			else
			PORTD = ((PORTD << 2) | (0x03));
			_delay_ms(300);
		}
		
		if(!(PINC & 0x08))
		{
			if((PORTD & 0xfc) == 0xfc)
				PORTD = 0x3f;
			else if((PORTD & 0x7e) == 0x7e)
				PORTD = 0x9f;
			else if((PORTD & 0xf9) == 0xf9)
				PORTD = 0x7e;
			else
			PORTD = ((PORTD >> 2) | (0xc0));
			_delay_ms(300);
		}
	}
}