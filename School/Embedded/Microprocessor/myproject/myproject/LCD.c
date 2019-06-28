#include <util/delay.h>
#include <avr/io.h>

void COMMAND(unsigned char byte)
{
	_delay_ms(2);
	PORTD = byte&0xf0;
	PORTD &= 0b11111100;
	_delay_us(1);
	PORTD |= 0b00000100;
	_delay_us(1);
	PORTD &= 0b11111011;
	
	PORTD = (byte<<4)&0xf0;
	PORTD &= 0b11111100;
	_delay_us(1);
	PORTD |= 0b00000100;
	_delay_us(1);
	PORTD &= 0b11111011;
}

void DATA(unsigned char byte)
{
	_delay_ms(2);
	PORTD = byte&0xf0;			//??4?? ??? ??
	PORTD |= 0b00000001;		//RS = 1, ??? ??
	PORTD &= 0b11111101;		//RW = 0, ?? ??
	_delay_us(1);
	PORTD |= 0b00000100;
	_delay_us(1);
	PORTD &= 0b11111011;
	
	//??4?? ?????
	PORTD = (byte<<4)&0xf0;		//??4?? ??? ??
	PORTD |= 0b00000001;		//RS = 1, ??? ??
	PORTD &= 0b11111101;		//RW = 0, ?? ??
	_delay_us(1);
	PORTD |= 0b00000100;
	_delay_us(1);
	PORTD &= 0b11111011;
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

void STRING(char font[], unsigned char n){
	for(int i = 0; i<n;i++){
		DATA(font[i]);
	}
	
}

void MOVE(int y, int x){
	unsigned char data;
	data = 0x80;
	if(y==2){
		data+=0x40;
	}
	data+=(x-1);
	COMMAND(data);
}