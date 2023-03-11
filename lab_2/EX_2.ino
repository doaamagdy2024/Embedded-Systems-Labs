#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>


void setup() {
  // put your setup code here, to run once:
  DDRC = 0X03;

  //Enable the internal pull up resistance at INT1 pin (PD3).
  DDRC &= ~(1<<PC3);
  PORTC |= (1<<PC3);
  
  PORTC = 0;
}

ISR(INT1_vect){
  //Let the leds falsh 5 times for 5 seconds
  for(int i =0; i < 5; i=i+1)
  {  
      PORTC ^= (1<<PC0) ^ (1<<PC1) ^ (1<<PC2);
      delayMicroseconds(1000);
  }
  
  
}

void int_init()
{
  //Disable interrupts by clearing I-bit.
  cli();
  
  //Configure INT1/PD3 as input pin.
  DDRD &= ~(1<<PD3);

  //Enable external interrupt pin INT1.
  EIMSK |= (1<<INT1);
  
  //Trigger INT1 with the raising edge.
  EICRA |= (1<<ISC10) | (1<<ISC11);

  //Enable interrupts by setting I-bit.
  sei();
}


void loop() {
  // put your main code here, to run repeatedly:
  
  int_init();

  //perform the original program (roll action)
  PORTC |= (1<<PC0) & ~(1<<PC1) & ~(1<<PC2);
  //PORTC &= ~(1<<PC1);
  //PORTC &= ~(1<<PC2);
  delay(500);
  PORTC &= ~(1<<PC0) | (1<<PC1) & ~(1<<PC2);
  //PORTC |= (1<<PC1);
  //PORTC &= ~(1<<PC2);
  delay(500);
  PORTC &= ~(1<<PC0) & ~(1<<PC1) | (1<<PC2);
  //PORTC &= ~(1<<PC1);
  //PORTC |= (1<<PC2);
  delay(500);
  
}