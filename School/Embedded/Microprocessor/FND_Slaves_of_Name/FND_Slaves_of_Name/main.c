#include "FND_CHAR.h"
#include <stdlib.h>
#include <time.h>
#include <avr/io.h>
#include <util/delay.h>

int ahexDice[16] = {
	__0_, __1_, __2_, __3_, __4_, __5_, __6_, 
	__7_, __8_, __9_, __A_, __B_, __C_, __D_,
	__E_, __F_
};


int main(void)
{
	int index = 0, index1 = 0;
	srand(((unsigned int)time(NULL)));
	DDRA = 0xff;	DDRC = 0xff;
	DDRD = 0x00;
	DDRG = 0xff;
	PORTG = 0xff;
	
	/* Replace with your application code */
	while (1)
	{
		while (!(PIND&0x01))
		{
			index = rand() % 16;
			index1 = rand() % 16;
			PORTA = ahexDice[(index)];
			PORTC = ahexDice[(index1)];
			_delay_ms(100);
		}

	}
}


