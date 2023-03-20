//master

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#define SS PB2
#define MOSI PB3
#define MISO PB4
#define SCK PB5

char count = 0;

void SPI_MasterInit(void) {
  DDRB |= (1 << MOSI) | (1 << SCK) | (1 << SS);  // Set MOSI, SCK and SS as output pins
  DDRB &= ~(1 << MISO);                          // Set MISO as input pin

  PORTB |= (1 << SS);  // Set SS high initially

  SPCR = (1 << SPE) | (1 << MSTR) | (1 << SPR0);  // Enable SPI, set as master and set clock rate to fosc/16
  SPSR &= ~(1<<SPI2X); //Disable speed doubler
}

void SPI_MasterWrite(char data) {
  char flush_buffer;
  SPDR = data;  // Load data into the buffer
  while (!(SPSR & (1 << SPIF)));  // Wait until transmission complete
  flush_buffer = SPDR;  //flush received data
}

char master_read(){
  //read the coming data
  SPDR = 0xff;
  while(!(SPSR & (1<<SPIF)));  // Wait till reception complete
  return SPDR;

}

void setup() {
  Serial.begin(9600);
  SPI_MasterInit();
  PORTB &= ~(1 << SS);  // Select slave by setting SS low
  _delay_ms(1000);

}


void loop() {
  SPI_MasterWrite(count);  // Send count to slave

  count++;
  if ((uint8_t)count > 100) count = 1;  // Reset count after reaching 100
  

  char received_data = master_read();  // Read received data from buffer

  //PORTB |= (1 << SS);  // Deselect slave by setting SS high

  Serial.println("Master sent: " + (uint8_t)count);
  Serial.println("Slave replied: " + (uint8_t)received_data);

  _delay_ms(500);
}