#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    /* Replace with your application code */
	DDRC = 0xfe;
	PORTC = ~(0x04);
    while (1) 
    {
		if(!(PINC & 0x01))
		{
			PORTC ^= (PINC=~(0x04))^(PINC=~(0x08));
			_delay_ms(300);
		}
    }
}

