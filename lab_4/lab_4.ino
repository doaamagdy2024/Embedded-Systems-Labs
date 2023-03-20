// #include <avr/io.h>
// #include <avr/interrupt.h>
// #include <util/delay.h>
// #include <Arduino.h>
// #define POT_PIN PC0 // Analog input pin that the potentiometer is attached to

// // Initialize adc:
// // Make ADC Ref=VCC (AREF = AVcc)
// // Enable ADC
// // Set prescaler by 128 so 𝐹𝑒𝑞 = 16MHz/128 = 125KHz

// void init_adc(void) {
//   ADMUX |= (1 << REFS0); // Set ADC reference to AVCC
//   ADCSRA |= (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0); // Set ADC prescaler to 128 - 125KHz sample rate @ 16MHz
//   ADCSRA |= (1 << ADEN); // Enable ADC
// }

// // Read ADC value
// // select the corresponding channel 0~7
// // start single convertion
// // wait for conversion to complete
// // return ADC
// uint16_t read_adc(uint8_t ch) {
//   // select the corresponding channel 0~7
//   // ANDing with ’7′ will always keep the value
//   // of ‘ch’ between 0 and 7
//   ch &= 0b00000111; // AND operation with 7
//   ADMUX = (ADMUX & 0xF8) | ch; // clears the bottom 3 bits before ORing

//   // start single convertion
//   // write ’1′ to ADSC
//   ADCSRA |= (1 << ADSC);

//   // wait for conversion to complete
//   // ADSC becomes ’0′ again
//   // till then, run loop continuously
//   while (ADCSRA & (1 << ADSC));

//   return (ADC);
// }
// void setup() {
//   // put your setup code here, to run once:
//   Serial.begin(9600);
//   init_adc();
// }

// void loop() {
//   // put your main code here, to run repeatedly:
//   uint16_t adc_value = read_adc(POT_PIN);
//   Serial.println(adc_value);
// ///
// }

// #include <avr/io.h>
// #include <avr/interrupt.h>
// #include <util/delay.h>

// #define POT_PIN PC0 // Analog input pin that the potentiometer is attached to

// #define LED_PIN PB5 // Digital output pin that the LED is attached to
// uint8_t ADC_end = 0;
// void isr_adc(void)
// {
//     ADC_end = 1;
// }

// void init_adc(void)
// {
//     ADMUX |= (1 << REFS0);                                // Set ADC reference to AVCC
//     ADCSRA |= (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0); // Set ADC prescaler to 128 - 125KHz sample rate @ 16MHz
//     ADCSRA |= (1 << ADEN);                                // Enable ADC
//     ADCSRA |= (1 << ADIE);                                // Enable ADC Interrupt
//     ADCSRA |= (1 << ADSC);                                // Start A2D Conversions
// }


// ISR(ADC_vect)
// {
//     isr_adc();
// }
// uint16_t read_adc(uint8_t ch)
// {
//     // select the corresponding channel 0~7
//     // ANDing with ’7′ will always keep the value
//     // of ‘ch’ between 0 and 7
//     ch &= 0b00000111;            // AND operation with 7
//     ADMUX = (ADMUX & 0xF8) | ch; // clears the bottom 3 bits before ORing
//                                  // start single convertion
//     // write ’1′ to ADSC
//     ADCSRA |= (1 << ADSC);
//     if (ADC_end == 1)
//     {
//         ADC_end = 0;
//         return ADC;
//     }
//     else
//         return -1;
// }
// uint16_t adc_value = 0;
// void setup()
// {
//     // put your setup code here, to run once:
//     Serial.begin(9600);
//     sei(); // Enable global interrupts

//     init_adc();
// }

// void loop()
// {
//     // put your main code here, to run repeatedly:
//     adc_value = read_adc(POT_PIN);
//     if (adc_value != -1)
//     {
//         Serial.println(adc_value);
        
//     }
//     else Serial.println("ADC not ready");
// }

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#define POT_PIN PC0 // Analog input pin that the potentiometer is attached to
#define LED_PIN1 PD4 // Digital output pin that the LED is attached to
#define LED_PIN2 PD5 // Digital output pin that the LED is attached to
#define LED_PIN3 PD6 // Digital output pin that the LED is attached to

uint8_t ADC_end = 0;
void isr_adc(void)
{
    ADC_end = 1;
}

void init_adc(void)
{
    ADMUX |= (1 << REFS0);                                // Set ADC reference to AVCC
    ADCSRA |= (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0); // Set ADC prescaler to 128 - 125KHz sample rate @ 16MHz
    ADCSRA |= (1 << ADEN);                                // Enable ADC
    ADCSRA |= (1 << ADIE);                                // Enable ADC Interrupt
    ADCSRA |= (1 << ADSC);                                // Start A2D Conversions
}


ISR(ADC_vect)
{
    isr_adc();
}
uint16_t read_adc(uint8_t ch)
{
    // select the corresponding channel 0~7
    // ANDing with ’7′ will always keep the value
    // of ‘ch’ between 0 and 7
    ch &= 0b00000111;            // AND operation with 7
    ADMUX = (ADMUX & 0xF8) | ch; // clears the bottom 3 bits before ORing
                                 // start single convertion
    // write ’1′ to ADSC
    ADCSRA |= (1 << ADSC);
    if (ADC_end == 1)
    {
        ADC_end = 0;
        return ADC;
    }
    else
        return -1;
}
uint16_t adc_value = 0;
void setup()
{
    // put your setup code here, to run once:
    Serial.begin(9600);
    sei(); // Enable global interrupts
    DDRD |= (1 << LED_PIN1) | (1 << LED_PIN2) | (1 << LED_PIN3);
    PORTD &= ~(1 << LED_PIN1) & ~(1 << LED_PIN2) & ~(1 << LED_PIN3);
    init_adc();
}

void loop()
{
    // put your main code here, to run repeatedly:
    adc_value = read_adc(POT_PIN);
    if (adc_value != -1)
    {
        //map adc_value to 0-7
        uint8_t adc_value_mapped = adc_value * 7 / 1023;
        PORTD = (PORTD & 0b10001111) | (adc_value_mapped << 4);
        Serial.println(adc_value_mapped);
        Serial.println(PORTD);

    }
    else Serial.println("ADC not ready");
}
