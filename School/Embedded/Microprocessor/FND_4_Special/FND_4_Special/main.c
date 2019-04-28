#include <avr/io.h>
#include <util/delay.h>
#include "FND_CHAR.h"
int ms = 0, ms_1 = 0, sec = 0, sec_1 = 0;
int toggle = 1;
void ClockCalc();

int main(void)
{
	DDRA = 0xff;
	DDRG = 0x0f;
	DDRD = 0x00;
	while (1)
	{
		for(int cnt = 0; cnt < 12; cnt++)
		{
			PORTG = 0x01;
			PORTA = my_Number[ms];
			_delay_ms(1);
			PORTG = 0x02;
			PORTA = my_Number[ms_1];
			_delay_ms(1);
			PORTG = 0x04;
			PORTA = (my_Number[sec]& _DP_);
			_delay_ms(1);
			PORTG = 0x08;
			PORTA = (my_Number[sec_1]);
			_delay_ms(1);
		}
		if(!(PIND & 0x01))
		{
			toggle = 1;
		}
		if(!(PIND & 0x02))
		{
			toggle = 0;
		}
		if(!(PIND & 0x04))
		{
			ms = 0; 
			ms_1 = 0; 
			sec = 0; 
			sec_1 = 0;
		}
		if(toggle)
			ClockCalc();
	}
}

void ClockCalc()
{
	ms++;
	if(ms > 9)
	{
		ms = 0;
		ms_1++;
	}
	if (ms_1 > 9)
	{
		ms_1 = 0;
		sec++;
	}
	if (sec > 9)
	{
		sec = 0;
		sec_1++;
	}
	if (sec_1 > 5)
	{
		sec_1 = 0;
	}
}