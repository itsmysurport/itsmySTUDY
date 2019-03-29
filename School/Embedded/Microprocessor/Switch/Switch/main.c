#include <avr/io.h>

// PULLUP
// When I push the button(LOW), status is 0
// When I release the button(HIGH), status is 1
int main(void)
{
	DDRD = 0xff;
	DDRF = 0x00;
	PORTD = 0xff;
    while (1) 
    {
		PORTD = PINA;
// 		if((PINA&0x01) == 0x00)
// 		{
// 			PORTD |= (1<<PORTD0);
// 			while((PINA&0x01) == 0x00);	
// 		}
// 		if((PINA&0x02) == 0x00)
// 		{
// 			PORTD |= (1<<PORTD1);
// 			while((PINA&0x01) == 0x00);
// 		}
// 		if((PINA&0x04) == 0x00)
// 		{
// 			PORTD |= (1<<PORTD2);
// 			while((PINA&0x04) == 0x00);
// 		}
// 		if((PINA&0x08) == 0x00)
// 		{
// 			PORTD |= (1<<PORTD3);
// 			while((PINA&0x08) == 0x00);
// 		}
// 		if((PINA&0x10) == 0x00)
// 		{
// 			PORTD |= (1<<PORTD4);
// 			while((PINA&0x10) == 0x00);
// 		}
// 		if((PINA\\\\\\\//&0x20) == 0x00)
// 		{
// 			PORTD |= (1<<PORTD5);
// 			while((PINA&0x20) == 0x00);
// 		}
// 		if((PINA&0x40) == 0x00)
// 		{
// 			PORTD |= (1<<PORTD6);
// 			while((PINA&0x40) == 0x00);
// 		}
// 		if((PINA&0x80) == 0x00)
// 		{
// 			PORTD |= (1<<PORTD7);
// 			while((PINA&0x80) == 0x00);
// 		}
	}
}

