#include "LCD_H.h"

void COMMAND(unsigned char byte)
{
	_delay_ms(2);
	PORTC = byte&0xf0;
	PORTC &= 0b11111100;
	_delay_us(1);
	PORTC |= 0b00000100;
	_delay_us(1);
	PORTC &= 0b11111011;
	
	PORTC = (byte<<4)&0xf0;
	PORTC &= 0b11111100;
	_delay_us(1);
	PORTC |= 0b00000100;
	_delay_us(1);
	PORTC &= 0b11111011;
}

void DATA(unsigned char byte)
{
	_delay_ms(2);
	PORTC = byte&0xf0;			//??4?? ??? ??
	PORTC |= 0b00000001;		//RS = 1, ??? ??
	PORTC &= 0b11111101;		//RW = 0, ?? ??
	_delay_us(1);
	PORTC |= 0b00000100;
	_delay_us(1);
	PORTC &= 0b11111011;
	
	//??4?? ?????
	PORTC = (byte<<4)&0xf0;		//??4?? ??? ??
	PORTC |= 0b00000001;		//RS = 1, ??? ??
	PORTC &= 0b11111101;		//RW = 0, ?? ??
	_delay_us(1);
	PORTC |= 0b00000100;
	_delay_us(1);
	PORTC &= 0b11111011;
}

void LCD_INIT(void)
{
	DDRC = 0xff;
	PORTC = 0x00;
	_delay_ms(30);				// ?? ?? ? 30ms ?? ??
	
	//Function set
	COMMAND(0b00101000);
	// ?????(DL) = 0(4bit), ??(N) = 1(2??), ??(F)=0(5*7 dot)
	_delay_us(40);
	
	//Display ON OFF
	COMMAND(0b00001100);
	_delay_us(40);
	// D C B 100
	
	//Clear display
	COMMAND(0x01);
	_delay_ms(2);
	//ENTRY MODE SET
	COMMAND(0b00000110);
	//I/D = 1, S=0
}

void STRING(char mStr[16])
{
	int i = 0;
	while(1)
	{
		if(mStr[i] == '\0')	break;
		DATA(mStr[i++]);
	}
}

void MOVE(int y, int x)
{
	unsigned char data = 0;
	if(y==1)
	{
		data = 0x80 + x - 1;
	}
	else if(y == 2)
	{
		data = 0xC0 + x - 1;
	}
	
	COMMAND(data);
}