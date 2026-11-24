#ifndef DAC_ADC_H
#define DAC_ADC_H

void DAC_Init()
{
	RCC->APB1ENR |= 0x20000000; //enable clock for DAC

	DAC1->CR |= DAC_CR_EN1; //enable DAC

	DAC1->CR &= ~(DAC_CR_BOFF1); //enable buffer

	DAC1->CR &= ~(DAC_CR_TEN1); //disable trigger
}

void ADC_Init()
{
	RCC-> APB2ENR |= RCC_APB2ENR_ADCEN; //enable clock for ADC

	ADC1-> CFGR1 = 0x3000; //OVERMOD = 1, CONT = 1

	ADC1-> CR |= 0x1; //enable ADC process

	ADC1->SMPR |= 0x7; //sampling speed

	ADC1-> CHSELR |= 0x2; //select channel 1

	while(((ADC1->ISR) & 0x1) == 0); //waiting for ADRDY

	ADC1 -> CR |= 0x4; //start ADC process
}

#endif // DAC_ADC_H
