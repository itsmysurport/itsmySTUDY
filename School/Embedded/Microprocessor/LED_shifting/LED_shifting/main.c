#include <avr/io.h>
#include <util/delay.h>

void SetRight()
{
	PORTD = 0x01;
	_delay_ms(100);
}

void SetLeft()
{
	PORTD = 0x80;
	_delay_ms(100);
}

int main(void)
{
    DDRD = 0xff;
	PORTD = 0x01;
	
    while (1) 
    {		
		PORTD = PORTD << 1;
		_delay_ms(100);
		
		if(PORTD == 0x00)
		{
			SetLeft();
			while(PORTD != 0x00)
			{
				PORTD = PORTD >> 1;
				_delay_ms(100);
			}
			SetRight();
		}
    }
}

