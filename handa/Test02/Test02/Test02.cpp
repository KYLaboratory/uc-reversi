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
	unsigned short Illumination;	//観測輝度値
	unsigned short Buff;
	
	Buff = 0;
	
	//12bitでデータが送られてくる
	
	//AD変換
	ADCSRA |= _BV(ADSC);				//AD変換を開始
	loop_until_bit_is_set(ADCSRA,ADIF);	//AD変換終了待ち
	Illumination = ADC;					//観測輝度値に格納
	
	//バッファを更新
	Buff = Buff << 1;
	if(Illumination > IlluminationThresh){
		Buff |= 1; 
	}else{
		Buff |= 0;
	}
	
	//識別
	//TODO:12bit目~9bit目が1010と一致しているか？
	//TODO:4bit目~1bit目が1010と一致しているか？
	//TODO:8bit目~5bit目から色、方向を算出
	
	
	_delay_ms(LEDInterval);
	
	
	
}
int main(void)
{
	
	
	ADCSRA = 0b10000100;	//AD変換を有効にする
	ADMUX = 0b00000000;			//AD変換の対象ピンをPC0（ADC0)とする
	
	DDRD = 0b00000100;		//PD2を出力に設定（※LEDデバッグ）
	PORTD = 0b00000000;		//PD2のLEDを消灯（※LEDデバッグ）
	
    while(1)
    {
		recieveMes();
    }
}