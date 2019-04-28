#include <wiringPi.h>
#include <stdio.h>

void PrintNumber(int nNumber)
{
	int nCmp = 0x01;
	int i = 0;
	
	for(i = 0; i < 7; i++)
	{
		digitalWrite(i, HIGH);
	}
	for(i = 0; i < 7; i++)
	{
		if(!(nNumber & nCmp))
		{
			digitalWrite(i, LOW);
		}
		nCmp = nCmp << 1;
	}
}
