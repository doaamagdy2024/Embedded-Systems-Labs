//req_1
#include <avr/io.h>
#include <avr/interrupt.h>
// global variable to count the number of overflows
volatile uint8_t tot_overflow;
// TIMER0 overflow interrupt service routine
// called whenever TCNT0 overflows

void setup() {
 // put your setup code here, to run once:
 sei();
DDRC |= (1 << PC0);
TCCR2B |= (0x7 << CS00);
TCNT2 = 0;
PORTC &= ~(1 << PC0);
tot_overflow = 0;
TIMSK2 |= (1 << TOIE0);
}
ISR(TIMER2_OVF_vect)
{
  tot_overflow++;
 }

void loop() {
 // check if no. of overflows = 30
 if (tot_overflow >= 30) // NOTE: '>=' is used
 {
   // check if the timer count reaches 53
   if (TCNT2 >= 131){
     PORTC ^= (1 << 0); // toggles the led
     TCNT2 = 0; // reset counter
     tot_overflow = 0; // reset overflow counter
   }
 }
}