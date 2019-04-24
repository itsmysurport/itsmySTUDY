#include <stdio.h>
#include <wiringPi.h>

#define SW 29 
#define LED 1

int switchControl()
{
	int i;
	
	printf("Hello\n");
	
	pinMode(SW, INPUT);
	pinMode(LED, OUTPUT);

	while(1)
	{
		if(digitalRead(SW) == HIGH)
		{
			printf("H\n");
			delay(1000);
		}
	}

	return 0;
}

int main(int argc, char** argv)
{
	wiringPiSetup();
	switchControl();

	return 0;
}
