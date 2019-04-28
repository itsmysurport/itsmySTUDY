#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	int cnt = 0;
	DDRC = 0x00;
	DDRD = 0xff;
	PORTD = 0xff;
    /* Replace with your application code */
    while (1) 
    {
		if(!(PINC & 0x01))
		{
			_delay_ms(30);
			cnt++;
			if( (((cnt/3)%2) == 1 ) && ((cnt % 3)== 0) )
			{
				PORTD = 0x00;
			}
			if( (((cnt/3)%2) == 0 ) && ((cnt % 3)== 0) )
			{
				PORTD = 0xff;
			}
			
			while(!(PINC & 0x01))
			{
				_delay_ms(30);
			}
		}
    }
}

