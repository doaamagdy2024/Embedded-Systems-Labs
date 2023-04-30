/*
req #2
It is required to fade PE14 LED ( and hence the Buzzer).
Use timer 1 to output a 3.8 kHz PWM signal with a duty ration that goes from 0 to 100%
then from 100% to zero and so on.
Hint:
Use Delay_us(time_in_microseconds) in your loop.

*/
unsigned int period = 0;  // variable defenition must be at the beg. of the code
int decrease = 0;
int dutyCycle = 0;
int i =0;
void main(){


// first we need to configure the GPIO pins
//GPIO_Digital_Output(&GPIOE_BASE, _GPIO_PINMASK_14);

period = PWM_TIM4_Init(4000); // initializes timer 1 in PWM mode with 3.8 kHz frequency

while(1){

for( dutyCycle =0; dutyCycle<period ;dutyCycle++)
{
PWM_TIM4_Set_Duty(dutyCycle, _PWM_NON_INVERTED, _PWM_CHANNEL1);
PWM_TIM4_Start(_PWM_CHANNEL1, &_GPIO_MODULE_TIM4_CH1_PD12);
}

for( dutyCycle =0; dutyCycle<period ;dutyCycle++)
{
PWM_TIM4_Set_Duty(dutyCycle, _PWM_NON_INVERTED, _PWM_CHANNEL2);
PWM_TIM4_Start(_PWM_CHANNEL2, &_GPIO_MODULE_TIM4_CH2_PD13);
}

for( dutyCycle =0; dutyCycle<period ;dutyCycle++)
{
PWM_TIM4_Set_Duty(dutyCycle, _PWM_NON_INVERTED, _PWM_CHANNEL3);
PWM_TIM4_Start(_PWM_CHANNEL3, &_GPIO_MODULE_TIM4_CH3_PD14);
}


for( dutyCycle =0; dutyCycle<period ;dutyCycle++)
{
PWM_TIM4_Set_Duty(dutyCycle, _PWM_NON_INVERTED, _PWM_CHANNEL4);
PWM_TIM4_Start(_PWM_CHANNEL4, &_GPIO_MODULE_TIM4_CH4_PD15);
}

Delay_us(50);

for( dutyCycle =period; dutyCycle>0 ;dutyCycle--)
{
PWM_TIM4_Set_Duty(dutyCycle, _PWM_NON_INVERTED, _PWM_CHANNEL1);
PWM_TIM4_Start(_PWM_CHANNEL1, &_GPIO_MODULE_TIM4_CH1_PD12);
}
for( dutyCycle =period; dutyCycle>0 ;dutyCycle--)
{
PWM_TIM4_Set_Duty(dutyCycle, _PWM_NON_INVERTED, _PWM_CHANNEL2);
PWM_TIM4_Start(_PWM_CHANNEL2, &_GPIO_MODULE_TIM4_CH2_PD13);
}
for( dutyCycle =period; dutyCycle>0 ;dutyCycle--)
{
PWM_TIM4_Set_Duty(dutyCycle, _PWM_NON_INVERTED, _PWM_CHANNEL3);
PWM_TIM4_Start(_PWM_CHANNEL3, &_GPIO_MODULE_TIM4_CH3_PD14);
}
for( dutyCycle =period; dutyCycle>0 ;dutyCycle--)
{
PWM_TIM4_Set_Duty(dutyCycle, _PWM_NON_INVERTED, _PWM_CHANNEL4);
PWM_TIM4_Start(_PWM_CHANNEL4, &_GPIO_MODULE_TIM4_CH4_PD15);
}
}
}