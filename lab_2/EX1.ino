#include <avr/io.h>
#include <avr/interrupt.h>


void setup(){
    //configuration of the interrupt
    SREG = SREG & (~(1<<7)); 
    DDRD = 0;
    EIMSK |= (1<<INT0);
    EICRA |= (1<<ISC00) | (1<<ISC01);
    SREG = SREG | (1<<7); 
    
    DDRC = 1;
    PORTC = 0;
}


ISR(INT0_vect){
    PORTC ^= (1<<PC0);
}




void loop(){

}
