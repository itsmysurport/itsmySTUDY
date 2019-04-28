#include <avr/io.h>
#include <util/delay.h>
#include "FND_CHAR.h"

unsigned int fnd_position = 0x01;
int i = 0;
int main(void)
{
	DDRA = 0xff;
	DDRG = 0x0f;
    PORTA = 0xf0;
	while (1) 
    {
		PORTG = fnd_position;
		fnd_position <<=1;
		if(fnd_position & 0x10)
			fnd_position = 0x01;
		PORTA = my_Number[i];
		i++;
		if(i > 15)	i = 0;
		_delay_ms(1000);
    }
}

