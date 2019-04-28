#include <avr/io.h>
#include <util/delay.h>
#include "FND_CHAR.h"
int ms = 0, sec_1 = 0, sec_2 = 0, min = 0;

void ClockCalc();

int main(void)
{
    DDRA = 0xff;
    DDRG = 0x0f;
    while (1) 
    {
		for(int cnt = 0; cnt < 25; cnt++)
		{
			PORTG = 0x01;
			PORTA = my_Number[ms];
			_delay_ms(1);
			PORTG = 0x02;
			PORTA = (my_Number[sec_1] & _DP_);
			_delay_ms(1);
			PORTG = 0x04;
			PORTA = my_Number[sec_2];
			_delay_ms(1);
			PORTG = 0x08;
			PORTA = (my_Number[min] & _DP_);
			_delay_ms(1);		
		}
		ClockCalc();
    }
}

void ClockCalc()
{
	ms++;
	if(ms > 9)
	{
		ms = 0;
		sec_1++;
	}
	if (sec_1 > 9)
	{
		sec_1 = 0;
		sec_2++;
	}
	if (sec_2 > 5)
	{
		sec_2 = 0;
		min++;
	}
	if (min > 9)
	{
		min = 0;
	}
}