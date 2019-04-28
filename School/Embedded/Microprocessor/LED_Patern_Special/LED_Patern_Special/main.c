#include <avr/io.h>
#include <util/delay.h>

int i;
int nFront = 0x00;
int nBack = 0x00;

void SET_LED_ON();
void SET_LED_OFF();

void ON_IN_START();
void ON_OUT_START();

void OFF_IN_START();
void OFF_OUT_START();

int main(void)
{
	DDRD = 0xff;

    while (1) 
    {
		SET_LED_ON();
		ON_IN_START();
		ON_OUT_START();
		SET_LED_OFF();
		OFF_IN_START();
		OFF_OUT_START();
    }
}

void SET_LED_ON()
{
	nFront = 0x80; 
	nBack = 0x01;
	PORTD = nFront + nBack;
	_delay_ms(700);
}

void SET_LED_OFF()
{
	nFront = 0x70;
	nBack = 0x0e;
	PORTD = nFront + nBack;
	_delay_ms(700);
}

void ON_IN_START()					// Repeat 3 times
{
	for (i = 0; i < 3; i++)
	{
		nFront |= (nFront >> 1);
		nBack |= (nBack << 1);
		PORTD = nFront + nBack;
		_delay_ms(700);
	}
}

void ON_OUT_START()					// Repeat 4 times
{
	for(i = 0; i < 4; i++)
	{
		nFront = nFront << 1;
		nBack = nBack >> 1;
		PORTD = nFront + nBack;
		_delay_ms(700);
	}	
}

void OFF_IN_START()					// Repeat 3 times
{
	for (i = 0; i < 3; i++)
	{
		nFront = (nFront >> 1) & (0xf0);
		nBack = (nBack << 1) & (0x0f);
		PORTD = nFront + nBack;
		_delay_ms(700);
	}
}

void OFF_OUT_START()
{
	nFront = 0x10;
	nBack = 0x08;
	PORTD = nFront + nBack;
	_delay_ms(700);
	
	for(i = 0; i < 3; i++)
	{
		nFront |= nFront << 1;
		nBack |= nBack >> 1;
		PORTD = nFront + nBack;
		_delay_ms(700);
	}
}