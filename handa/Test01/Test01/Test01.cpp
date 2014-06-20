/*
 * Test01.cpp
 *
 * Created: 2014/06/02 22:52:50
 *  Author: Masato
 */ 

//LED Blink




#include <avr/io.h>
#include <avr/delay.h>

#define White  0
#define Black 1
#define Right 0
#define RightTop 1
#define Top 2
#define LeftTop 3
#define Left 4
#define LeftBottom 5
#define Bottom 6
#define RightBottom 7
#define LEDInterval 10

void sendMes(int Color, int Direction)
{
	//�X�^�[�g��(1010)
	PORTC = 0b00000001;
	_delay_ms(LEDInterval);
	PORTC = 0b00000000;
	_delay_ms(LEDInterval);
	PORTC = 0b00000001;
	_delay_ms(LEDInterval);
	PORTC = 0b00000000;
	_delay_ms(LEDInterval);
	
	//�f�[�^��
	switch(Color){
		case White:
		   PORTC = 0b00000000;
		   _delay_ms(LEDInterval);
		   break;
		case Black:
		   PORTC = 0b00000001;
		   _delay_ms(LEDInterval);
		   break;
	}
	
	switch(Direction){
		case Right:
			PORTC = 0b00000000;
			_delay_ms(LEDInterval);
			PORTC = 0b00000000;
			_delay_ms(LEDInterval);
			PORTC = 0b00000000;
			_delay_ms(LEDInterval);
			break;
		case RightTop:
			PORTC = 0b00000000;
			_delay_ms(LEDInterval);
			PORTC = 0b00000000;
			_delay_ms(LEDInterval);
			PORTC = 0b00000001;
			_delay_ms(LEDInterval);
			break;
		case Top:
			PORTC = 0b00000000;
			_delay_ms(LEDInterval);
			PORTC = 0b00000001;
			_delay_ms(LEDInterval);
			PORTC = 0b00000000;
			_delay_ms(LEDInterval);
			break;
		case LeftTop:
			PORTC = 0b00000000;
			_delay_ms(LEDInterval);
			PORTC = 0b00000001;
			_delay_ms(LEDInterval);
			PORTC = 0b00000001;
			_delay_ms(LEDInterval);
			break;
		case Left:
			PORTC = 0b00000001;
			_delay_ms(LEDInterval);
			PORTC = 0b00000000;
			_delay_ms(LEDInterval);
			PORTC = 0b00000000;
			_delay_ms(LEDInterval);
			break;
		case LeftBottom:
			PORTC = 0b00000001;
			_delay_ms(LEDInterval);
			PORTC = 0b00000000;
			_delay_ms(LEDInterval);
			PORTC = 0b00000001;
			_delay_ms(LEDInterval);
			break;
		case Bottom:
			PORTC = 0b00000001;
			_delay_ms(LEDInterval);
			PORTC = 0b00000001;
			_delay_ms(LEDInterval);
			PORTC = 0b00000000;
			_delay_ms(LEDInterval);
			break;
		case RightBottom:
			PORTC = 0b00000001;
			_delay_ms(LEDInterval);
			PORTC = 0b00000001;
			_delay_ms(LEDInterval);
			PORTC = 0b00000001;
			_delay_ms(LEDInterval);
			break;
	}
	
	
	//�G���h��(1010)
	PORTC = 0b00000001;
	_delay_ms(LEDInterval);
	PORTC = 0b00000000;
	_delay_ms(LEDInterval);
	PORTC = 0b00000001;
	_delay_ms(LEDInterval);
	PORTC = 0b00000000;
	_delay_ms(LEDInterval);
	
}
	
	
int main(void)
{
	DDRC = 0b00000001;			//C0���o�͂ɂ���
	PORTC = 0b00000000;
	
    while(1)
    {
		sendMes(Black, Right);
 
    }
}