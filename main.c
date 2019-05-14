/*
 * GccApplication9.c
 *
 * Created: 10-May-19 2:19:35 PM
 * Author : JAYASREE
 */ 

#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>
#define RS 7
#define E 5
void send_command (unsigned char command);
void send_character (unsigned char character);
int main(void)
{
	DDRC=0XFF;
	DDRD=0XFF;
	_delay_ms(50);
	send_command(0X01);//sending clear data command
	send_command(0X38);
	send_command(0X0E);//display on cursor on
	//data to print
	send_character(0X4A);
	send_character(0X41);
	send_character(0X59);
	send_character(0X41);
	send_character(0X53);
	send_character(0X52);
	send_character(0X49);
}
void send_command(unsigned char command)
{
		PORTC=command;
		PORTD&=~(0<<RS);
		PORTD|=(1<<E);
		_delay_ms(50);
		PORTD&=~(1<<E);
		PORTC=0;
}
void send_character(unsigned char character)
{
	PORTC=character;
	PORTD|=(1<<RS);
	PORTD|=(1<<E);
	_delay_ms(50);
	PORTD&=~(1<<E);
	PORTC=0;
}


