#include <avr/io.h>
#include <util/delay.h>
void setup() {
  // put your setup code here, to run once:
  //configure pins
  DDRB=0;
  DDRC=0XFF;
  
  //INTERNAL pull up res
  DDRB = DDRB & (~(1<<PB0));
  PORTB = PORTB | (1<<PB0);

  PORTC = 0;
}

void loop() {
  // put your main code here, to run repeatedly:

  delay(30);
  if(PINB&(0x01))
  {
    while(PINB&(0x01));
    
    PORTC=PORTC^(1<<PC0);
  }
}
