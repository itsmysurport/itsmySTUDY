#include <avr/io.h>
#include <util/delay.h>

int aNumberIndex[31] = {
	0x3f, 0x06, 0x5b, 0x4f, 0x66, 
	0x6d, 0x7c, 0x07, 0x7f, 0x6f,
	0x5F, 0x7C, 0x58, 0x5E,	0x7B,
	0x71, 0x6F, 0x74, 0x30, 0x0E,
	0x38, 0x54, 0x5C, 0x73, 0x67,
	0x50, 0x6D, 0x78, 0x1C, 0x66, 0x5B
	};
	
int i = 0;
int main(void)
{
	DDRD = 0xff;
	DDRG = 0xff;
	PORTG = 0xff;
    /* Replace with your application code */
    while (1) 
    {
		/*
		0 -> 0011 1111 3F
		1 -> 0000 0110 06
		2 -> 0101 1011 5B
		3 -> 0100 1111 4F
		4 -> 0110 0110 66
		5 -> 0110 1101 6D
		6 -> 0111 1100 7C
		7 -> 0000 0111 07
		8 -> 0111 1111 7F
		9 -> 0110 1111 6F
		*/
		PORTD = aNumberIndex[(i%31)];
		i++;
		_delay_ms(500);
    }
}

