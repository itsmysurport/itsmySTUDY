#include "ADC_H.h"

void ADC_init()
{
	DDRF = 0x00;
	ADCSRA = 0x87;		// 8 = Enable 7 = 128 프리스케일러
	ADMUX = 0x40;		// ADMUX
}

int ADC_Read(char channel) {
	int ADC_value, adc_low, adc_high;
	ADMUX = (0x40) | (channel & 0x07);
	_delay_us(20);
	ADCSRA |= (1<<ADSC);
	while((ADCSRA & 0x10)!=0x10);
	ADCSRA |= (1<<ADIF);
	
	adc_low = ADCL; //결과 저장
	adc_high =ADCH; //결과 저장
	ADC_value = (adc_high << 8) | adc_low; // 값으로 변환

	return ADC_value;
}