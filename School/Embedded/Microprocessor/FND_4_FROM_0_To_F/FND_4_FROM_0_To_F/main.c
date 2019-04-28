#include <avr/io.h>
#include <util/delay.h>
#include "FND_CHAR.h"


int main(void)
{
	int i = 0;
	DDRA = 0xff;
	DDRG = 0x0f;
	PORTG = 0x01;
	while (1)
	{
		PORTA = my_Number[i];
		i++;
		_delay_ms(500);
		i %= 16;
	}
}

