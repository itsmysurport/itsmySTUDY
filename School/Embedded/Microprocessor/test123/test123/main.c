#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#include "ADC_H.h"
#include "LCD_H.h"

int main(void)
{
	int ADC_value;
	ADC_init();
	LCD_INIT();
	while(1)
	{
		char buffer[20], buffer1[20], buffer2[20];
		ADC_value = ADC_Read(0);
		sprintf(buffer, "X =%4d", ADC_value);
		MOVE(1,1);
		STRING(buffer);
		
		ADC_value = ADC_Read(1);
		sprintf(buffer1, "Y =%4d", ADC_value);
		MOVE(1,9);
		STRING(buffer1);
			
		ADC_value = ADC_Read(2);
		if(ADC_value > 300)	ADC_value = 1;
		else ADC_value = 0;
		sprintf(buffer2, "Z = %d", ADC_value);
		MOVE(2,1);
		STRING(buffer2);
	}
}