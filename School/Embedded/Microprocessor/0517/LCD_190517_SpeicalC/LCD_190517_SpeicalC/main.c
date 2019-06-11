#include <stdio.h>
#include <avr/io.h>
#include <util/delay.h>

int nMinute = 0, nSecond = 0, nMil = 0;
char myID[] = "00:00:00";

void COMMAND(unsigned char byte);
void DATA(unsigned char byte);
void LCD_INIT(void);

void MOVE(int y, int x)		//0x80
{
	unsigned char data = 0x80;
	if(y == 2)
	{
		data += 0x40;
	}
	data += (x - 1);
	COMMAND(data);
}

void STRING(char font[], unsigned int n)
{
	int i;
	for(i = 0; i < n; i++)
	{
		DATA(font[i]);
		//_delay_ms(500);
	}
}

void updateCLOCK()
{
	nMil++;
	if(nMil > 99)
	{
		nSecond++;
		nMil = 0;
		if (nSecond > 59)
		{
			nMinute++;
			nSecond = 0;
			if (nMinute > 59)
			{
				nMinute = 0;
				nSecond = 0;
				nMil = 0;
			}
		}
	}
	
	sprintf(myID, "%02d:%02d:%02d", nMinute, nSecond, nMil);
}

int main(void)
{
	int toggle = 1;
	char myName[] = "TIME";
	DDRB = 0xff;
	DDRC = 0x00;
	PORTB = 0x00;
	LCD_INIT();
	MOVE(1, 7);
	STRING(myName, sizeof(myName) - 1);
	MOVE(2, 5);
	STRING(myID, sizeof(myID) - 1);
	
	while (1)
	{
		if (!(PINC&0x01))
		{
			toggle = !toggle;
			while (!(PINC&0x01));	
		}
		if (!(PINC&0x02))
		{
			nMinute = 0;
			nSecond = 0;
			nMil = 0;
			sprintf(myID, "00:00:00");
			MOVE(2, 5);
			
			STRING(myID, sizeof(myID)- 1);
			_delay_ms(10);
			while (!(PINC&0x02));
		}
		if(toggle)
		{
			updateCLOCK();
			MOVE(2, 5);
		
			STRING(myID, sizeof(myID)- 1);
			_delay_ms(10);
		}
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
