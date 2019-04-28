#include <avr/io.h>
#include <util/delay.h>
#include "FND_CHAR.h"

int main(void)
{
	DDRA = 0xff;
	DDRG = 0x0f;
	while (1)
	{
		PORTG = 0x08;
		PORTA = _1_;
		_delay_ms(1);
		PORTG = 0x04;
		PORTA = _2_;
		_delay_ms(1);
		PORTG = 0x02;
		PORTA = _3_;
		_delay_ms(1);
		PORTG = 0x01;
		PORTA = _4_;
		_delay_ms(1);
	}
}

