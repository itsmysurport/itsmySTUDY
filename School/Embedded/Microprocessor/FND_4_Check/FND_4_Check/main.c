#include <avr/io.h>


int main(void)
{
    DDRA = 0xff;
	DDRG = 0x0f;
    while (1)    
	{
		PORTA = 0x0f;
		PORTG = 0x01;
    }
}

