#include <stdio.h>
#include <wiringPi.h>

#define SW 8
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
			digitalWrite(LED, HIGH);
			delay(1000);
			digitalWrite(LED, LOW);
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
