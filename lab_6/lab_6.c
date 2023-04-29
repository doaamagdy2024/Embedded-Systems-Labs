
//req #3
/*
 * Req description
       It is required to use the pins PD0, PD1, PD2, PD3 as a binary counter from 0 to 15.
       Configure PB0 and PB1 as input pins. PB0 is used as incrementer and PB1 is a
       decrementer. When the counter achieves 15 then PB0 will do nothing. When the counter
       achieves 0 then PB1 will do nothing. The transition must happen on the rising edge of the
       push buttons.
 * NOTES:
     - Turn ON PORTD, PORTE, LEDs at SW4 and SW5. (board specific).  no but SW15 in slides
 */

void main() {
  unsigned int prev0, prev1, current0, current1;
  unsigned int counter = 0;
  GPIO_Digital_input(&GPIOB_BASE, _GPIO_PINMASK_0 | _GPIO_PINMASK_1);
  GPIO_Digital_Output(&GPIOD_BASE, _GPIO_PINMASK_0 | _GPIO_PINMASK_1 | _GPIO_PINMASK_2 | _GPIO_PINMASK_3);

  GPIOD_ODR = 0;
  current0 = 0;
  current1 = 0;
  prev0 = 0;
  prev1 = 0;


  while(1) {
    prev0 = current0;
    prev1 = current1;
    current0 = Button(&GPIOB_IDR, 0, 30, 1);
    current1 = Button(&GPIOB_IDR, 1, 30, 1);
    if(counter < 15 && !prev0 && current0)
    {

       counter = counter + 1;
       GPIOD_ODR = counter;

    }
    if(counter > 0 && !prev1 && current1)
    {
        counter = counter - 1;
        GPIOD_ODR = counter;

    }



  }
}
