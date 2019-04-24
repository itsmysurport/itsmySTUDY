#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>
#include "FND_CHAR.h"

#define SW 29

int toogle = 0;

int main(int argc, char** argv)
{
	int i;
	int number = 0;
	int numIndex[10] = {
		_0_, _1_, _2_, _3_, _4_,
		_5_, _6_, _7_, _8_, _9_ 
	};
	int PrintNumber();

	wiringPiSetup();
	pinMode(0, OUTPUT);
	pinMode(1, OUTPUT);
	pinMode(2, OUTPUT);
	pinMode(3, OUTPUT);
	pinMode(4, OUTPUT);
	pinMode(5, OUTPUT);
	pinMode(6, OUTPUT);
	pinMode(7, OUTPUT);
	while(1)
	{
		if(digitalRead(SW) == HIGH)
		{
			toogle = ~(toogle);
			printf("%d\n", toogle);
			while(digitalRead(SW) == HIGH);
		}
		if(toogle)
		{
			number++;
			number %= 10;
			PrintNumber(numIndex[number]);
			delay(200);
	
		}
	}
	return 0;
}
