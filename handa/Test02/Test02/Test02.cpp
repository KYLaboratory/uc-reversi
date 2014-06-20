/*
 * Test02.cpp
 *
 * Created: 2014/06/15 20:11:43
 *  Author: Masato
 */ 


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
#define IlluminationThresh 100

void recieveMes()
{
	unsigned short Illumination;	//�ϑ��P�x�l
	unsigned short Buff;
	
	Buff = 0;
	
	//12bit�Ńf�[�^�������Ă���
	
	//AD�ϊ�
	ADCSRA |= _BV(ADSC);				//AD�ϊ����J�n
	loop_until_bit_is_set(ADCSRA,ADIF);	//AD�ϊ��I���҂�
	Illumination = ADC;					//�ϑ��P�x�l�Ɋi�[
	
	//�o�b�t�@���X�V
	Buff = Buff << 1;
	if(Illumination > IlluminationThresh){
		Buff |= 1; 
	}else{
		Buff |= 0;
	}
	
	//����
	//TODO:12bit��~9bit�ڂ�1010�ƈ�v���Ă��邩�H
	//TODO:4bit��~1bit�ڂ�1010�ƈ�v���Ă��邩�H
	//TODO:8bit��~5bit�ڂ���F�A�������Z�o
	
	
	_delay_ms(LEDInterval);
	
	
	
}
int main(void)
{
	
	
	ADCSRA = 0b10000100;	//AD�ϊ���L���ɂ���
	ADMUX = 0b00000000;			//AD�ϊ��̑Ώۃs����PC0�iADC0)�Ƃ���
	
	DDRD = 0b00000100;		//PD2���o�͂ɐݒ�i��LED�f�o�b�O�j
	PORTD = 0b00000000;		//PD2��LED�������i��LED�f�o�b�O�j
	
    while(1)
    {
		recieveMes();
    }
}