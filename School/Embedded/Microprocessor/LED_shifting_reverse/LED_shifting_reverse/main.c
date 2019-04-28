#include <avr/io.h>
#include <util/delay.h>

void SetRight()
{
	PORTD = 0xfe;
	_delay_ms(100);
}

void SetLeft()
{
	PORTD = 0x7f;
	_delay_ms(100);
}

int main(void)
{
	DDRD = 0xff;
	PORTD = 0xfe;
	
	while (1)
	{
		PORTD = (0xff ^ ((0xff ^ PORTD) << 1));
		_delay_ms(100);
		
		if(PORTD == 0xff)
		{
			SetLeft();
			while(PORTD != 0xff)
			{
				PORTD = (0xff ^ ((0xff ^ PORTD) >> 1));
				_delay_ms(100);
			}
			SetRight();
		}
	}
}

