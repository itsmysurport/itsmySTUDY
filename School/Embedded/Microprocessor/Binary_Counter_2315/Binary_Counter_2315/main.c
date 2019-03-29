#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRD = 0xff;
    PORTD = 0xff;
	while (1) 
    {
		_delay_ms(250);
		PORTD -= 1;
		if(PORTD <= 0x00)
			PORTD = 0xff;
	}
}

