#include <stdio.h>
#include <wiringPi.h>

#define SW 7
int myIndex[8] = {1, 4, 5, 6, 29, 0, };

int switchControl()
{
	int i, status = 0;
	
		
	pinMode(SW, INPUT);
	for(i = 0; i < 5; i++)
	{
		printf("i : %d\n", i);
		pinMode(myIndex[i], OUTPUT);
		digitalWrite(myIndex[i], LOW);
	}

	while(1)
	{
		if(digitalRead(SW) == HIGH)
		{
			if(status == 0)
				digitalWrite(myIndex[5], LOW);
			else
				digitalWrite(myIndex[(status - 1)], LOW);
			printf("%d\n", status);
			delay(30);
			digitalWrite(myIndex[status], HIGH);
			
			status++;
			if(status > 5)
				status = 0;

			while(digitalRead(SW) == HIGH);
			delay(30);
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
