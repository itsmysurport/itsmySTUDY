#include <avr/io.h>
#include <util/delay.h>
#include "FND_CHAR.h"

int ahexDice[16] = {
	__0_, __1_, __2_, __3_, __4_, __5_, __6_,
	__7_, __8_, __9_, __A_, __B_, __C_, __D_,
	__E_, __F_
};


int main(void)
{
	int index = 0;
	int index1 = 0;
	DDRA = 0xff;
	DDRC = 0xff;
	DDRD = 0x00;
	PORTG = 0xff;
	
	/* Replace with your application code */
	while (1)
	{
		while (!(PIND&0x01))
		{
			index = 1;
			index1 = 1;
			PORTA = ahexDice[(index)];
			PORTC = ahexDice[(index1)];
			_delay_ms(100);
		}

	}
}


