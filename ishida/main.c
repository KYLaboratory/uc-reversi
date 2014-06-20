#include <avr/io.h>

int main(void)
{
  unsigned short data;

  ADCSRA = 0b10000100;
  ADMUX = 0b00000110;

  DDRA |= _BV(PA2);
  PORTA &= ~_BV(PA2);

  while(1) {
    ADCSRA |= _BV(ADSC);
    loop_until_bit_is_set(ADCSRA, ADIF);
    data = ADC;

    if (data >= 30) {
      PORTA |= _BV(PA2);
    } else {
      PORTA &= ~_BV(PA2);
    }
  }

  return 0;

  /*
  DDRA = 0b10000000;
  int i = 0;
  while (1){
    i++;
    if (i < 10000) {
      PORTA = 0b10000000;
    } else if (i < 20000) {
      PORTA = 0b00000000;
    } else {
      i = 0;
    }
  }
  return 0;
  */
}
