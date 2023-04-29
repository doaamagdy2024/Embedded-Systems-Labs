#line 1 "D:/Academic_college/Third_Year/Second_Term/Embeded_Systems/labs/Repo/Embedded-Systems-Labs/lab_6/lab_6.c"
#line 14 "D:/Academic_college/Third_Year/Second_Term/Embeded_Systems/labs/Repo/Embedded-Systems-Labs/lab_6/lab_6.c"
void main() {
 GPIO_Digital_Output(&GPIOD_BASE, _GPIO_PINMASK_ALL);
 GPIO_Digital_Output(&GPIOE_BASE, _GPIO_PINMASK_ALL);

 GPIOD_ODR = 0;
 GPIOE_ODR = 0;

 while(1) {
 GPIOD_ODR = ~GPIOD_ODR;
 GPIOE_ODR = ~GPIOE_ODR;

 Delay_ms(500);
 }
}
#line 42 "D:/Academic_college/Third_Year/Second_Term/Embeded_Systems/labs/Repo/Embedded-Systems-Labs/lab_6/lab_6.c"
void main() {
 GPIO_Digital_Output(&GPIOD_BASE, _GPIO_PINMASK_ALL);
 GPIO_Digital_Output(&GPIOE_BASE, _GPIO_PINMASK_ALL);

 GPIOD_ODR = 0;
 GPIOE_ODR = 0;

 while(1) {
 for(int i = 0; i < 16; i=i+4)
 {
 GPIOD_ODR |= (1<<i) | (1<<(i+1)) | (1<<(i+2)) | (1<<(i+3));
 GPIOE_ODR |= (1<<i) | (1<<(i+1)) | (1<<(i+2)) | (1<<(i+3));
 Delay_ms(100);
 }
 for(int i = 0; i < 16; i=i+4)
 {
 GPIOD_ODR |= (0<<i) | (0<<(i+1)) | (0<<(i+2)) | (0<<(i+3));
 GPIOE_ODR |= (0<<i) | (0<<(i+1)) | (0<<(i+2)) | (0<<(i+3));
 Delay_ms(100);
 }

 }
}
#line 78 "D:/Academic_college/Third_Year/Second_Term/Embeded_Systems/labs/Repo/Embedded-Systems-Labs/lab_6/lab_6.c"
void main() {
 GPIO_Digital_input(&GPIOB_BASE, _GPIO_PINMASK_0 | _GPIO_PINMASK_1);
 GPIO_Digital_Output(&GPIOD_BASE, _GPIO_PINMASK_0 | _GPIO_PINMASK_1 | _GPIO_PINMASK_2 | _GPIO_PINMASK_3);

 GPIOD_ODR = 0;
 GPIOB_ODR = 0;

 uint8_t counter = 0;

 while(1) {
 if(counter < 15 && Button(&GPIOB_IDR, 0, 1, 1))
 {
 counter = counter + 1;
 GPIOD_ODR = counter;
 }
 else if(counter > 0 && Button(&GPIOB_IDR, 1, 1, 1))
 {
 counter = counter - 1;
 GPIOD_ODR = counter;
 }


 while();

 }
}
