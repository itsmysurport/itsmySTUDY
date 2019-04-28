#include <avr/io.h>
#include <util/delay.h>
#include "FND_CHAR.h"

int myPhonenumber[17] = {0xff, 0xff, 0xff, 0xff, _0_,
					_1_, _0_, _DASH_, _9_, _2_, _9_, _4_, _DASH_,
					_5_, _4_, _7_, _9_};

int i = 0, j = 1, k = 2, l = 3;

int main(void)
{
    DDRA = 0xff;
    DDRG = 0x0f;
    while (1) 
    {
		for(int cnt = 0; cnt < 100; cnt++)
		{
			PORTG = 0x08;
			PORTA = myPhonenumber[i];
			_delay_ms(1);
			PORTG = 0x04;
			PORTA = myPhonenumber[j];
			_delay_ms(1);
			PORTG = 0x02;
			PORTA = myPhonenumber[k];
			_delay_ms(1);
			PORTG = 0x01;
			PORTA = myPhonenumber[l];
			_delay_ms(1);
		}
		i++;	j++;	k++;	l++;
		i %= 17;	j %= 17;	k %= 17; l %= 17;
	}
}

