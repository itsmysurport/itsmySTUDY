#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

void GotoLeft();
void GotoRight();
void SetLeft();
void SetRight();

int main(void)
{
	// init
	DDRD = 0xff;
	PORTD = 0x01;
	
	// Run Code
	while (1)
	{
		GotoLeft();
		if(PORTD == 0xff)
		{
			SetRight();
			while(PORTD != 0xff)
			GotoRight();
			SetLeft();
		}
	}
}

void GotoLeft()
{
	PORTD |= PORTD<<1;
	_delay_ms(70);				// delay to 0.07 second
}

void GotoRight()
{
	PORTD |= PORTD>>1;
	_delay_ms(70);
}

void SetRight()
{
	PORTD = 0x80;
	_delay_ms(70);
}

void SetLeft()
{
	PORTD = 0x01;
	_delay_ms(70);
}

