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
  //スタート部(1010)
  PORTC = 0b00000001;
  _delay_ms(LEDInterval);
  PORTC = 0b00000000;
  _delay_ms(LEDInterval);
  PORTC = 0b00000001;
  _delay_ms(LEDInterval);
  PORTC = 0b00000000;
  _delay_ms(LEDInterval);

  //データ部
  PORTC = Color;
  _delay_ms(LEDInterval);

  int b_direction[3];
  for (int i = 0; i < 16; i++) {
    b_direction[i] = Direction % 2;
    Direction = Direction / 2;
  }
  PORTC = b_direction[2];
  _delay_ms(LEDInterval);
  PORTC = b_direction[1];
  _delay_ms(LEDInterval);
  PORTC = b_direction[0];
  _delay_ms(LEDInterval);

  //エンド部(1010)
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
  DDRC = 0b00000001;			//C0を出力にする
  PORTC = 0b00000000;

  while(1) {
    sendMes(Black, Right);
  }
}
