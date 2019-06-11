#include <avr/io.h>

int main(void)
{
    DDRA = 0xff;
	DDRG = 0xff;
    
	while (1) 
    {
		PORTG = 0x04;
		PORTA = 0x0f;
    }
}

