//Slave Code:

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

#define SS PB2
#define MOSI PB3
#define MISO PB4
#define SCK PB5

char received_data;

void SPI_SlaveInit(void) {
  DDRB &= ~((1 << MOSI) | (1 << SCK) | (1 << SS));  // Set MOSI, SCK and SS as input pins
  DDRB |= (1 << MISO);                              // Set MISO as output pin

  SPCR = (1 << SPE);// | (1 << SPR0);  // Enable SPI and set clock rate to fosc/16
}

char SPI_SlaveReceive(void) {
  while (!(SPSR & (1 << SPIF))); /* Wait for reception complete */

  return SPDR; /* Return Data Register */
}

void slave_send(char reply_data){
  char flush_buffer;
  SPDR = reply_data;  // Send reply back to master
  while(!(SPSR & (1<<SPIF)));
  flush_buffer = SPDR;

}

void setup() {
  Serial.begin(9600);
  SPI_SlaveInit();  // Initialize SPI Slave
}



void loop() {
  received_data = SPI_SlaveReceive();  // Receive data from master

  uint8_t temp = (uint8_t)received_data + 100;
  char reply_data = (char)temp;  // Add 100 to received data

  slave_send(reply_data);
  

  Serial.println("Slave received: " + (uint8_t)received_data);
  Serial.println("Slave replied: " + (uint8_t)reply_data);

  _delay_ms(500);
}
