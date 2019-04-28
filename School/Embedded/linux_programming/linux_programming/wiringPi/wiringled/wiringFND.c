#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>
#include "FND_CHAR.h"

int main(int argc, char** argv)
{
	int i;
	int number = 0;
	int numIndex[10] = {
		_0_, _1_, _2_, _3_, _4_,
		_5_, _6_, _7_, _8_, _9_ 
	};
	int PrintNumber();

	if(argc !=  2)
	{
		fprintf(stderr, "HOW TO USE : ./%s NUMBER\n", argv[0]);
	}
	number = atoi(argv[1]);
	number %= 10;
	printf("SUCCES TO %d\n", number);

	wiringPiSetup();
	pinMode(0, OUTPUT);
	pinMode(1, OUTPUT);
	pinMode(2, OUTPUT);
	pinMode(3, OUTPUT);
	pinMode(4, OUTPUT);
	pinMode(5, OUTPUT);
	pinMode(6, OUTPUT);
	pinMode(7, OUTPUT);
	PrintNumber(numIndex[number]);
	
	return 0;
}
