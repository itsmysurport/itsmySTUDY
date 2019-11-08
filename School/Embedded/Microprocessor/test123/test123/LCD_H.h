#ifndef LCD_H_H_
#define LCD_H_H_

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

void COMMAND(unsigned char);
void DATA(unsigned char);
void LCD_INIT(void);
void STRING(char *);
void MOVE(int, int);

#endif /* LCD_H_H_ */