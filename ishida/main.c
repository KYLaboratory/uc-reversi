#include <avr/io.h>

int main(void)
{
  //unsigned char switch_flag = 0;
  unsigned short data;

  ADCSRA = 0b10000100;
  ADMUX = 0b00000110;

  DDRA |= _BV(PA2);
  PORTA &= ~_BV(PA2);

  while(1) {
    //if (switch_flag) {
    //ADMUX = 0b00000110;
      ADCSRA |= _BV(ADSC);
      loop_until_bit_is_set(ADCSRA, ADIF);
      data = ADC;

      if (data >= 30) {
        PORTA |= _BV(PA2);
      } else {
        PORTA &= ~_BV(PA2);
      }
      //}

    /*ADMUX = 0b00000000;
    ADCSRA |= _BV(ADSC);
    loop_until_bit_is_set(ADCSRA, ADIF);
    data = ADC;

    if (data >= 30) {
      //PORTA |= _BV(PA2);
    } else {
      switch_flag = 1;
      //PORTA &= ~_BV(PA2);
      }*/
  }

  return 0;
}
