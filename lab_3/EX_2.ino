//req_2
#include <avr/io.h>
#include <avr/interrupt.h>
// global variable to count the number of overflows
volatile uint8_t tot_overflow;
// TIMER0 overflow interrupt service routine
// called whenever TCNT0 overflows
#define a PC0
#define b PC1
#define c PC2
#define d PC3
#define e PC4
#define f PC5
#define g PD5

uint8_t counter;
void setup() {
 // put your setup code here, to run once:
 Serial.begin(9600);
sei();
counter = 0;
DDRC |= 0x7F;
DDRD |= (1 << PD5);
TCCR2B &= ~(1 << CS00);
TCCR2B |= (0x6 << CS00);
TCNT2 = 0;
PORTC &= ~(0x7f << PC0);
PORTD &= ~(1 << PD5);
tot_overflow = 0;
TIMSK2 |= (1 << TOIE0);
}
ISR(TIMER2_OVF_vect)
{
  tot_overflow++;
 }

void loop() {
 Display(counter);
 // check if no. of overflows = 30
if (tot_overflow >= 244) // NOTE: '>=' is used
{
   // check if the timer count reaches 53
   if (TCNT2 >= 35){
     
     if (counter == 9){
       counter = 0;
     }
     else counter++;
     TCNT2 = 0; // reset counter
     Serial.println(counter);
 tot_overflow = 0; // reset overflow counter
   }
 }
}

void Display(int value)
{ 
 bool digits[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
 digits[value] = 1;
 PORTC = 0;
 PORTD &= ~(1 << g);
 PORTC = PORTC | (!(digits[1] || digits[4]) << a);
 PORTC = PORTC | (!(digits[5] || digits[6]) << b);
 PORTC = PORTC | (!digits[2] << c);
 PORTC = PORTC | (!(digits[4] || digits[1] || digits[7]) << d);
 PORTC = PORTC | ((digits[0] || digits[2] || digits[6]|| digits[8] || digits[6]) << e);
 PORTC = PORTC | (!(digits[2] || digits[1] || digits[7]|| digits[3]) << f);
 PORTD = PORTD | (!(digits[0] || digits[1] || digits[7]) << g);
 }
 