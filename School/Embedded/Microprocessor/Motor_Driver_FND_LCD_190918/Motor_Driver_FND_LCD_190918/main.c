/*
 * Motor_Driver_3Switch_190918.c
 *
 * Created: 2019-09-18 오전 10:24:49
 * Author : test
 */ 

#include <avr/io.h>
#include <util/delay.h>

void COMMAND(unsigned char byte);
void DATA(unsigned char byte);
void LCD__INIT(void);
char String(char Data[]);

void MOVE(int x, int y);

void MOVE(int x, int y){
	unsigned char data;
	data = 0x80+x-1;
	if(y==2){
		data = 0xc0+x-1;
	}
	COMMAND(data);
}

void COMMAND(unsigned char byte){
	_delay_ms(2);
	PORTC = (byte & 0xF0);
	PORTC &= 0xFE;
	PORTC &= 0xFD;
	_delay_us(1);
	PORTC |= 0x04;
	_delay_us(1);
	PORTC &= 0xFB;
	
	PORTC = ((byte<<4) & 0xF0);
	PORTC &= 0xFE;
	PORTC &= 0xFD;
	_delay_us(1);
	PORTC |= 0x04;
	_delay_us(1);
	PORTC &= 0xFB;
}

char String(char Data[]){
	for(int i=0; Data[i]!=0; i++){
		DATA(Data[i]);
	}
}

void DATA(unsigned char byte)
{
	_delay_ms(2);
	// 데이터 상위 바이트
	PORTC = (byte & 0xF0);    // 데이터
	PORTC |= 0x01;        //RS = 1;
	PORTC &= 0xFD;        //RW = 0;
	_delay_us(1);
	PORTC |= 0x04;        //E = 1;
	_delay_us(1);
	PORTC &= 0xFB;        //E = 0;
	
	// 데이터 하위 바이트
	PORTC = ((byte<<4) & 0xF0);      // 데이터
	PORTC |= 0x01;        //RS = 1;
	PORTC &= 0xFD;        //RW = 0;
	_delay_us(1);
	PORTC |= 0x04;        //E = 1;
	_delay_us(1);
	PORTC &= 0xFB;        //E = 0;
}

void LCD__INIT(void)
{
	// 충분한 지연시간을 통한 안정화 과정
	_delay_ms(30);
	COMMAND(0x20);    // D5=1
	_delay_ms(39);
	COMMAND(0x20);    // D5=1
	_delay_ms(1.53);
	COMMAND(0x20);    // D5=1
	
	// 초기화 과정
	COMMAND(0x28);    // function set
	COMMAND(0x06);    // entry mode set
	COMMAND(0x01);    // all clear
	COMMAND(0x0c);    // display on
}

int main(void)
{
	DDRC = 0xFF;
	DDRB = 0xE0;
	DDRD = 0x0F;

    while (1) 
    {
		if( (PIND&0x10) == 0x00 )
		{
			LCD__INIT();
			PORTB = 0xB0;
			PORTD = 0x0E;
			MOVE(1,1);
			String("LEFT");
		}
		else if ( (PIND&0x20) == 0x00 )
		{
			LCD__INIT();
			PORTB = 0xF0;
			PORTD = 0x0F;
			MOVE(1,1);
			String("STOP");
		}
		else if ( (PIND&0x40) == 0x00 )
		{
			LCD__INIT();
			PORTB = 0x70;
			PORTD = 0x0B;
			MOVE(1,1);
			String("RIGHT");
		}
    }
}

