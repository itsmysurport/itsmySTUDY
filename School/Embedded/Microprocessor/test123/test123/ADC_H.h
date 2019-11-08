/*
 * ADC_H.h
 *
 * Created: 2019-10-23 오전 10:26:00
 *  Author: test
 */ 


#ifndef ADC_H_H_
#define ADC_H_H_

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#define ipin PINF
#define iport PORTF
#define ADC_VERF_TYPE 0x20
void ADC_init();
int ADC_Read(char);


#endif /* ADC_H_H_ */