#include <avr/io.h>
#include <util/delay.h>

#define TRIG 6
#define ECHO 7
#define  SOUND_VELOCITY 340UL

int main(void)
{
	DDRD = 0xff;
    DDRA = (DDRA | (1<<TRIG) & ~(1<<ECHO));
	int i;
	unsigned int distance;
	
    while (1) 
    {
		TCCR1B = 0x03;
		PORTA &= ~(1<<TRIG);
		_delay_us(10);
		PORTA |= (1<<TRIG);
		_delay_us(10);
		PORTA &= ~(1<<TRIG);
		while(!(PINA&(1<<ECHO)));
		TCNT1 = 0x0000;
		while(PINA & (1<<ECHO));
		TCCR1B = 0x00;
		distance = (unsigned)(SOUND_VELOCITY * (TCNT1 * 4 / 2) / 1000);
		i = distance / 10;
		
			     if(i < 4)			PORTD = 0b10000000;
			else if(i>=4 && i < 10)	PORTD = 0b10001110;
			else if(i>=10 && i < 20)PORTD = 0b10001100;
			else if(i>=20)			PORTD = 0b00001111;
		_delay_ms(500);
    }
}

