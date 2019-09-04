#include <avr/io.h>
#include <util/delay.h>

#define TRIG 6
#define ECHO 7
#define  SOUND_VELOCITY 340UL

void COMMAND(unsigned char byte);
void DATA(unsigned char byte);
void LCD__INIT(void);
char String(char Data[]);

void MOVE(int x, int y);

int main(void)
{
	DDRC = 0xff;
	DDRB = 0xff;
	DDRA = (DDRA | (1<<TRIG) & ~(1<<ECHO));
	int i;
	
	unsigned int distance;
	LCD__INIT();
	
	COMMAND(0x40);

	while (1)
	{
		LCD__INIT();
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
		_delay_ms(100);
		
		for(i =0 ; i < (distance/ 10); i ++)
		{
			if(i > 14)	break;
			DATA(0xff);
			_delay_ms(5);
		}
		_delay_ms(500);
	}
	
}

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