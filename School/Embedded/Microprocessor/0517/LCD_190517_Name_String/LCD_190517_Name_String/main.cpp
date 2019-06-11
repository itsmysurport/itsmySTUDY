#include <avr/io.h>
#include <util/delay.h>

void COMMAND(unsigned char byte);
void DATA(unsigned char byte);
void LCD_INIT(void);

void STRING(unsigned char font[], unsigned int n)
{
	int i;
	for(i = 0; i < 14; i++)
	{
		DATA(font[i]);
		_delay_ms(500);
	}
}

int main(void)
{
	unsigned char myName[] = "Choi Seung-Ho.";
	DDRB = 0xff;
	PORTB = 0x00;
	LCD_INIT();
	while (1)
	{
		STRING(myName,14);
		COMMAND(0x01);
	}
}

void COMMAND(unsigned char byte)
{
	_delay_ms(2);
	PORTB = byte&0xf0;
	PORTB &= 0b11111100;
	_delay_us(1);
	PORTB |= 0b00000100;
	_delay_us(1);
	PORTB &= 0b11111011;
	
	PORTB = (byte<<4)&0xf0;
	PORTB &= 0b11111100;
	_delay_us(1);
	PORTB |= 0b00000100;
	_delay_us(1);
	PORTB &= 0b11111011;
}

void DATA(unsigned char byte)
{
	_delay_ms(2);
	PORTB = byte&0xf0;			//??4?? ??? ??
	PORTB |= 0b00000001;		//RS = 1, ??? ??
	PORTB &= 0b11111101;		//RW = 0, ?? ??
	_delay_us(1);
	PORTB |= 0b00000100;
	_delay_us(1);
	PORTB &= 0b11111011;
	
	//??4?? ?????
	PORTB = (byte<<4)&0xf0;		//??4?? ??? ??
	PORTB |= 0b00000001;		//RS = 1, ??? ??
	PORTB &= 0b11111101;		//RW = 0, ?? ??
	_delay_us(1);
	PORTB |= 0b00000100;
	_delay_us(1);
	PORTB &= 0b11111011;
}

void LCD_INIT(void)
{
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
