/*
 * Servo_Motor.c
 *
 * Created: 11-12-2019 10:37:00
 * Author : robe1819
 */ 


#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#define F_CPU 16E6

void Drej_Motor()
{
	for(OCR1A=500;OCR1A <= 1500;OCR1A++)
	{
		_delay_ms(15);
	}
	
	for(OCR1A=500;OCR1A >= 500;OCR1A--)
	{
		_delay_ms(5);
	}
}

int main(void)
{
	DDRB |= (1<<DDB5);
	
	TCCR1B |= (1<<WGM13);
	
	TCCR1A |= (1<<COM1A1) | (1<<WGM11);
	
	ICR1 = 20000;
	
	OCR1A = 1000;
	
	TCCR1B |= ((1<<CS11));
		
    while (1) 
    {
		Drej_Motor();
    }
}

