/*
 * Motor_Driver_3Switch_190918.c
 *
 * Created: 2019-09-18 오전 10:24:49
 * Author : test
 * 승호 바보
 */ 

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRB = 0xE0;
	DDRD = 0x0F;
    
    while (1) 
    {
		if( (PIND&0x10) == 0x00 )
		{
			PORTB = 0xB0;
			PORTD = 0x0E;
		}
		else if ( (PIND&0x20) == 0x00 )
		{
			PORTB = 0xF0;
			PORTD = 0x0F;
		}
		else if ( (PIND&0x40) == 0x00 )
		{
			PORTB = 0x70;
			PORTD = 0x0B;
		}
    }
}

