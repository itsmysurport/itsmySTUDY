#include "FND_CHAR.h"
#include <stdlib.h>
#include <time.h>
#include <avr/io.h>
#include <util/delay.h>

int aDice[6] = {
	__1, __2, __3, __4, __5, __6
};


int main(void)
{
	int index = 0;
	srand(((unsigned int)time(NULL)));
	DDRD = 0xff;
	DDRG = 0xff;
	DDRC = 0x00;
	PORTG = 0xff;
	
	/* Replace with your application code */
	while (1)
	{
		while (!(PINC&0x01))
		{
			index = rand() % 6;
			PORTD = aDice[(index)];
			_delay_ms(50);
		}

	}
}


