#include "FND_CHAR.h"
#include <avr/io.h>
#include <util/delay.h>

int aSentenceIndex[8] = {
		__I, __L, __O, __V, 
		__E, __Y, __O, __U
	};
	
int index = 0;
int main(void)
{
	DDRD = 0xff;
	DDRG = 0xff;
	DDRC = 0x00;
	PORTG = 0xff;
	
    /* Replace with your application code */
    while (1) 
    {
		while (!(PINC&0x01))
		{
			PORTD = aSentenceIndex[(index%8)];
			index++;
			_delay_ms(500);
		}
		index = 0;
		PORTD = 0x00;
    }
}

