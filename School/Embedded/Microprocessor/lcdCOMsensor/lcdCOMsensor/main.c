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
	MOVE(1,1);
	String("CM : ");
	
	COMMAND(0x40);

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
		MOVE(1,1);
		String("CM : ");
		for(i=0; i<4; i++){
			MOVE(9-i,1);
			
			if (i==1)
			{
				String(".");
			}
			else
			{
				if (distance%10==0)
				{
					String("0");
				}
				else if (distance%10==1)
				{
					String("1");
				}
				else if (distance%10==2)
				{
					String("2");
				}
				else if (distance%10==3)
				{
					String("3");
				}
				else if (distance%10==4)
				{
					String("4");
				}
				else if (distance%10==5)
				{
					String("5");
				}
				else if (distance%10==6)
				{
					
					String("6");
				}
				else if (distance%10==7)
				{
					String("7");
				}
				else if (distance%10==8)
				{
					String("8");
				}
				else if (distance%10==9)
				{
					String("9");
				}
				distance = distance/10;
			}
			
		}
		_delay_ms(100);
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