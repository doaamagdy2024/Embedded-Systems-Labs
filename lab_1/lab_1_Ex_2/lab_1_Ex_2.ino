#include <avr/io.h>
#include <util/delay.h>
void setup() {
  // put your setup code here, to run once:
  //configure pins
  DDRB = 0;
  DDRC = 0xFF;
  PORTC = PORTC & (~(1<<PC0));
  PORTC = PORTC & (~(1<<PC1));
}

void loop() {
  // put your main code here, to run repeatedly:
  if(PINB&0x01==1)
  {
     PORTC = PORTC |(1<<PC0);
   }
   else 
   {
      PORTC = PORTC & (~(1<<PC0));
    }
    if(PINB&0x02)
  {
     PORTC = PORTC |(1<<PC1);
   }
   else 
   {
      PORTC = PORTC & (~(1<<PC1));
    }
  
}
