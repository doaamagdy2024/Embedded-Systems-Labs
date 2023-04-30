// req 1

//void main() {
unsigned int period = 0;  // variable defenition must be at the beg. of the code
int dutyCycle = 0;
              void main(){
// first we need to configure the GPIO pins
GPIO_Digital_Output(&GPIOE_BASE, _GPIO_PINMASK_14);


period = PWM_TIM1_Init(500); // initializes timer 1 in PWM mode with 500 Hz frequency

dutyCycle = period * 0.2;
PWM_TIM1_Set_Duty(dutyCycle, _PWM_NON_INVERTED, _PWM_CHANNEL4);

PWM_TIM1_Start(_PWM_CHANNEL4, &_GPIO_MODULE_TIM1_CH4_PE14);
while(1){}
}

// // req 2

// void main() {
// unsigned int period = 0;  // variable defenition must be at the beg. of the code
// int dutyCycle = 0;
// int i = 0;

// // first we need to configure the GPIO pins
// //GPIO_Digital_Output(&GPIOE_BASE, _GPIO_PINMASK_14);


// period = PWM_TIM1_Init(3800); // initializes timer 1 in PWM mode with 500 Hz frequency

// while (1)
// {
// for (i = 0; i <= 100; i++)
// {
//     dutyCycle = period * (i / 100.0);
//     PWM_TIM1_Set_Duty(dutyCycle, _PWM_NON_INVERTED, _PWM_CHANNEL4);
//     PWM_TIM1_Start(_PWM_CHANNEL4, &_GPIO_MODULE_TIM1_CH4_PE14);
//     Delay_ms(50);

// }

// for (i = 100; i >= 0; i--)
// {
//     dutyCycle = period * (i / 100.0);
//     PWM_TIM1_Set_Duty(dutyCycle, _PWM_NON_INVERTED, _PWM_CHANNEL4);
//     PWM_TIM1_Start(_PWM_CHANNEL4, &_GPIO_MODULE_TIM1_CH4_PE14);
//     Delay_ms(50);

// }
// }



// }
// // req 3

// void main() {
// unsigned int period = 0;  // variable defenition must be at the beg. of the code
// int dutyCycle = 0;
// int i = 0;


// // first we need to configure the GPIO pins
// GPIO_Digital_Output(&GPIOD_BASE, _GPIO_PINMASK_14);
// GPIO_Digital_Output(&GPIOD_BASE, _GPIO_PINMASK_12);
// GPIO_Digital_Output(&GPIOD_BASE, _GPIO_PINMASK_15);
// GPIO_Digital_Output(&GPIOD_BASE, _GPIO_PINMASK_13);


// period = PWM_TIM4_Init(4000); // initializes timer 1 in PWM mode with 500 Hz frequency

// while (1)
// {


// for (i = 0; i <= 100; i++)
// {
//     dutyCycle = period * (i / 100.0);
//     PWM_TIM4_Set_Duty(dutyCycle, _PWM_NON_INVERTED, _PWM_CHANNEL1);
//     PWM_TIM4_Start(_PWM_CHANNEL1, &_GPIO_MODULE_TIM4_CH1_PD12);
//     Delay_ms(5);

// }

// for (i = 0; i <= 100; i++)
// {
//     dutyCycle = period * (i / 100.0);
//     PWM_TIM4_Set_Duty(dutyCycle, _PWM_NON_INVERTED, _PWM_CHANNEL2);
//     PWM_TIM4_Start(_PWM_CHANNEL2, &_GPIO_MODULE_TIM4_CH2_PD13);
//     Delay_ms(5);

// }

// for (i = 0; i <= 100; i++)
// {
//     dutyCycle = period * (i / 100.0);
//     PWM_TIM4_Set_Duty(dutyCycle, _PWM_NON_INVERTED, _PWM_CHANNEL3);
//     PWM_TIM4_Start(_PWM_CHANNEL3, &_GPIO_MODULE_TIM4_CH3_PD14);
//     Delay_ms(5);

// }

// for (i = 0; i <= 100; i++)
// {
//     dutyCycle = period * (i / 100.0);
//     PWM_TIM4_Set_Duty(dutyCycle, _PWM_NON_INVERTED, _PWM_CHANNEL4);
//     PWM_TIM4_Start(_PWM_CHANNEL4, &_GPIO_MODULE_TIM4_CH4_PD15);
//     Delay_ms(5);

// }

// for (i = 100; i >= 0; i--)

// {
//     dutyCycle = period * (i / 100.0);
//     PWM_TIM4_Set_Duty(dutyCycle, _PWM_NON_INVERTED, _PWM_CHANNEL1);
//     PWM_TIM4_Start(_PWM_CHANNEL1, &_GPIO_MODULE_TIM4_CH1_PD12);
//     Delay_ms(5);

// }

// for (i = 100; i >= 0; i--)

// {
//     dutyCycle = period * (i / 100.0);
//     PWM_TIM4_Set_Duty(dutyCycle, _PWM_NON_INVERTED, _PWM_CHANNEL2);
//     PWM_TIM4_Start(_PWM_CHANNEL2, &_GPIO_MODULE_TIM4_CH2_PD13);
//     Delay_ms(5);

// }

// for (i = 100; i >= 0; i--)

// {
//     dutyCycle = period * (i / 100.0);
//     PWM_TIM4_Set_Duty(dutyCycle, _PWM_NON_INVERTED, _PWM_CHANNEL3);
//     PWM_TIM4_Start(_PWM_CHANNEL3, &_GPIO_MODULE_TIM4_CH3_PD14);
//     Delay_ms(5);

// }

// for (i = 100; i >= 0; i--)

// {
//     dutyCycle = period * (i / 100.0);
//     PWM_TIM4_Set_Duty(dutyCycle, _PWM_NON_INVERTED, _PWM_CHANNEL4);
//     PWM_TIM4_Start(_PWM_CHANNEL4, &_GPIO_MODULE_TIM4_CH4_PD15);
//     Delay_ms(5);

// }

// }

// }
