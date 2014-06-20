#include <stdio.h>
#include <iostream>

#define Right 0
#define RightTop 1
#define Top 2
#define LeftTop 3
#define Left 4
#define LeftBottom 5
#define Bottom 6
#define RightBottom 7

int main(int argc, char* argv[]) {
  int direction = Bottom;
  int b_direction[3];
  for (int i = 0; i < 16; i++) {
    b_direction[i] = direction % 2;
    direction = direction / 2;
  }
  for (int i = 3 - 1; i >= 0; i--) {
    printf("%d", b_direction[i]);
  }

  std::cout << std::endl;

  int aaa = RightTop << 2;
  std::cout << RightTop << std::endl;
  std::cout << aaa << std::endl;
  /*  switch(Direction){
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
    }*/
}
