#include <avr/io.h>
#include <util/delay.h>
#include "FND_CHAR.h"

int aIlu[12] = {
	0xff, _I_, 0xff, _L_, _O_, _V_,
	_E_, 0xff, _Y_, _O_, _U_, 0xff
};

int main(void)
{
	int oneDigit = 0, tenDigit = 11;
	DDRA = 0xff;	DDRC = 0xff;
	DDRD = 0x00;
	DDRG = 0xff;
	PORTG = 0xff;
	
	while (1)
	{
		if(!(PIND & 0x01))
		{
			PORTA = aIlu[tenDigit];
			PORTC = aIlu[oneDigit];
			oneDigit++;
			tenDigit++;
			if(oneDigit > 11)
			{
				oneDigit = 0;
			}
			if (tenDigit > 11)
			{
				tenDigit = 0;
			}
			
			_delay_ms(500);
		}
	}
}
