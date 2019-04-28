#include <avr/io.h>
#include <util/delay.h>
#include "FND_CHAR.h"

int hexAdecimal[16] = {
	~(__0), ~(__1), ~(__2), ~(__3), ~(__4),
	~(__5), ~(__6), ~(__7), ~(__8), ~(__9),
	~(__A), ~(__B), ~(__C), ~(__D), ~(__E), ~(__F)	
};

int main(void)
{
	int oneDigit = 0, tenDigit = 0;
	DDRA = 0xff;
	DDRC = 0xff;
	DDRG = 0xff;
	PORTG = 0xff;
	while (1) 
    {
		PORTA = hexAdecimal[tenDigit];
		PORTC = hexAdecimal[oneDigit];
		oneDigit++;
		if(oneDigit > 15)
		{
			oneDigit = 0;
			tenDigit++;
			if(tenDigit > 15)
				tenDigit = 0;
		}
		_delay_ms(50);
    }
}

