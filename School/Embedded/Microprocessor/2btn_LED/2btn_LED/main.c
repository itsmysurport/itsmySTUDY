#include <avr/io.h>

// PULLUP
// When I push the button(LOW), status is 0
// When I release the button(HIGH), status is 1
int main(void)
{
	DDRD = 0xff;
	DDRF = 0x00;
	PORTD = 0xff;
	while (1)
	{
		PORTD = PINA;
	}
}

