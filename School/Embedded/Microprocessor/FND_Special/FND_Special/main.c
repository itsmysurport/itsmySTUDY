#include "FND_CHAR.h"
#include <stdlib.h>
#include <time.h>
#include <avr/io.h>
#include <util/delay.h>

int aNumberIndex[10] = {
	__0, __1, __2, __3, __4, 
	__5, __6, __7, __8, __9
};


int main(void)
{
	int index = 0;
	DDRD = 0xff;
	DDRG = 0xff;
	DDRC = 0x00;
	PORTG = 0xff;
	
	/* Replace with your application code */
	while (1)
	{
		if (!(PINC&0x01))
		{
			if (index <= 0)
			{
				index = 9;
			}
			else
			{
				index--;
			}
			PORTD = aNumberIndex[index];
			while(!(PINC&0x01));
			_delay_ms(30);
		}
		else if (!(PINC&0x02))
		{
			if (index == 9)
			{
				index = 0;
			}
			else
			{
				index++;
			}
			PORTD = aNumberIndex[index];
			while(!(PINC&0x02));
			_delay_ms(30);
		}
		else if (!(PINC&0x04))
		{
			index = 0;
			PORTD = aNumberIndex[index];
			while(!(PINC&0x04));
			_delay_ms(30);
		}
	}
}


