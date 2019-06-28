#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>
#include <stdio.h>
#include "FND_CHAR.h"

void COMMAND(unsigned char byte);
void DATA(unsigned char byte);
void LCD_INIT(void);
void STRING(char font[], unsigned char n);
void MOVE(int y, int x);
int mathi();
int enterNum(void);
void fndcount();

int i = 0;
int myNum[16]= {0, };

char myName[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
char test[20] = {0, };
char mOperator[5] = {'+', '-', '*'}; 

int main(void)
{
	int ask = 0;
	int answer1 = 0;
	int rnd = 0;
	int count = 0;

	DDRF = 0xff;
	PORTF = 0xff;
	DDRD = 0xff;
	DDRC = 0x00;
	DDRA = 0x00;
	PORTD = 0x00;
	PINC = 0x00;
	
	DDRE = 0xff;
	PORTE = 0x00;
	DDRB = 0xff;
	PORTB = 0x00;
	LCD_INIT();
	STRING("PRESS TO START", 14);
	while(1)
	{
		rnd++;
		if(rnd > 5000)
			rnd = 0;
		if(!(PINA & 0x08))
		{
			srand(rnd);
			break;
		}
	}
	while(1)
	{

		LCD_INIT();
		ask = mathi();
		answer1 = enterNum();
		LCD_INIT();
		
		if(ask == answer1)
		{
			PORTF = 0xfe;
			STRING("CORRECT!!!", 10);
			count += 1;
		}
		else
		{
			PORTF = 0xfd;
			STRING("INCORRECT!!!", 12);
		}
		_delay_ms(2000);
		PORTF = 0xff;
		fndcount(count);
	}
}

int mathi()
{
	int a = rand() % 100, b = rand() % 100, c = 0;
	int op = rand() % 3, answer = 0;
	if(mOperator[op] == '-' && b > a)
	{
		c = a;
		a = b;
		b = c;
		answer = a-b;
	}
	else if (mOperator[op] == '+')
	{
		answer = a + b;
	}
	else if (mOperator[op] == '*')
	{
		answer = a * b;
	}
	else if (mOperator[op] == '-')
	{
		answer = a - b;
	}

	sprintf(myName, "%03d %c %03d", a, mOperator[op], b);
	STRING(myName, 9);
	MOVE(2,1);
	STRING("Answer : ", 9);
	return answer;
}

int enterNum(void)
{
	int data = 0;
	int dupdup = 1;
	
	i = 0;
	for(int a = i; a < 15; a++)
	{
		myNum[a] = 0;
	}
	
	while(1)
	{
		if(!(PINC & 0x01))
		{
			_delay_ms(30);
			DATA('0');
			myNum[i++] = 0;
			while(!(PINC & 0x01));
		}
		else if(!(PINC & 0x02))
		{
			_delay_ms(30);
			DATA('1');
			myNum[i++] = 1;
			while(!(PINC & 0x02));
		}
		else if(!(PINC & 0x04))
		{
			_delay_ms(30);
			DATA('2');
			myNum[i++] = 2;
			while(!(PINC & 0x04));
		}
		else if(!(PINC & 0x08))
		{
			_delay_ms(30);
			DATA('3');
			myNum[i++] = 3;
			while(!(PINC & 0x08));
		}
		else if(!(PINC & 0x10))
		{
			_delay_ms(30);
			DATA('4');
			myNum[i++] = 4;
			while(!(PINC & 0x10));
		}
		else if(!(PINC & 0x20))
		{
			_delay_ms(30);
			DATA('5');
			myNum[i++] = 5;
			while(!(PINC & 0x20));
		}
		else if(!(PINC & 0x40))
		{
			_delay_ms(30);
			DATA('6');
			myNum[i++] = 6;
			while(!(PINC & 0x40));
		}
		else if(!(PINC & 0x80))
		{
			_delay_ms(30);
			DATA('7');
			myNum[i++] = 7;
			while(!(PINC & 0x80));
		}
		else if(!(PINA & 0x01))
		{
			_delay_ms(30);
			DATA('8');
			myNum[i++] = 8;
			while(!(PINA & 0x01));
		}
		else if(!(PINA & 0x02))
		{
			_delay_ms(30);
			DATA('9');
			myNum[i++] = 9;
			while(!(PINA & 0x02));
		}
		else if(!(PINA & 0x08))
		{
			_delay_ms(30);
			MOVE(2, 10);
			STRING("      ", 6);

			i = 0;
			for(int a = i; a < 15; a++)
			{
				myNum[a] = 0;
			}
			MOVE(2, 10);
			while(!(PINA & 0x08));
		}
		
		if(!(PINA & 0x04))
		{
			myNum[i] = 'E';
			break;
		}
		_delay_ms(30);
	}
	LCD_INIT();
	dupdup = 1;
	for(int q = i-1; q >= 0; q --)
	{
		int ddata = myNum[q];
		
		for(int kk = 0; kk < dupdup-1; kk++)
		{
			ddata *= 10;
		}
		data += ddata;
		dupdup++; 
	}

	return data;
}

void fndcount(int count)
{
	switch(count / 10)
	{
		case 0: PORTB = __0_;	break;
		case 1: PORTB = __1_;	break;
		case 2: PORTB = __2_;	break;
		case 3: PORTB = __3_;	break;
		case 4: PORTB = __4_;	break;
		case 5: PORTB = __5_;	break;
		case 6: PORTB = __6_;	break;
		case 7: PORTB = __7_;	break;
		case 8: PORTB = __8_;	break;
		case 9: PORTB = __9_;	break;
	}
	switch(count % 10)
	{
		case 0: PORTE = __0_;	break;
		case 1: PORTE = __1_;	break;
		case 2: PORTE = __2_;	break;
		case 3: PORTE = __3_;	break;
		case 4: PORTE = __4_;	break;
		case 5: PORTE = __5_;	break;
		case 6: PORTE = __6_;	break;
		case 7: PORTE = __7_;	break;
		case 8: PORTE = __8_;	break;
		case 9: PORTE = __9_;	break;
	}
	return;
}