#include <avr/io.h>

int main(void)
{
  unsigned short data;

  ADCSRA = 0b10000100;
  ADMUX = 0b00000110;

  DDRA |= _BV(PA2);
  PORTA &= ~_BV(PA2);
  DDRA |= _BV(PA6);
  PORTA &= ~_BV(PA6);

  PORTA |= _BV(PA6);

  unsigned int i = 0;

  while(1) {
    /*i++;
    if (i < 30000) {
      PORTA |= _BV(PA6);
    } else if (i < 60000) {
      PORTA &= ~_BV(PA6);
    } else {
      i = 0;
      }*/

    ADCSRA |= _BV(ADSC);
    loop_until_bit_is_set(ADCSRA, ADIF);
    data = ADCW;

    if (data >= 5) {
      PORTA |= _BV(PA2);
    } else {
      PORTA &= ~_BV(PA2);
    }
  }

  return 0;
}
