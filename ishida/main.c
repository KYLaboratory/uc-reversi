#include <avr/io.h>

int main(void)
{
  DDRA &= ~_BV(PA0);
  PORTA |= _BV(PA0);
  DDRA |= _BV(PA2);
  PORTA &= ~_BV(PA2);

  short flag = 0;

  while(1) {
    if ((PINA & 0b00000001) == 0) {
      flag = 1;
    }
    if (flag) {
      PORTA |= _BV(PA2);
    } else {
      PORTA &= ~_BV(PA2);
    }
  }

  return 0;
}
