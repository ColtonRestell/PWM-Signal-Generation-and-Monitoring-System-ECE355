#ifndef GPIO_H
#define GPIO_H

void myGPIOA_Init()
{
	RCC-> AHBENR |= RCC_AHBENR_GPIOAEN; //enable clock

	GPIOA->MODER |= 0x30C; //set PA1 & PA4 to analog mode

	GPIOA->PUPDR &= 0xFFFFFFF2; //set PA0 to pull down & PA1 as no pull up/pull down
}


void myGPIOB_Init()
{
	RCC-> AHBENR |= RCC_AHBENR_GPIOBEN; //enable clock

	GPIOB->MODER = 0x88450000; //SPI AF's and port B outputs

	GPIOB->PUPDR = 0x00450000; //PB8, PB9, PB11 all pull up
}

void myGPIOC_Init()
{
	RCC-> AHBENR |= RCC_AHBENR_GPIOCEN; //enable clock

	GPIOC->MODER = 0x00050000;//PC8 & PC9 output

	GPIOC->PUPDR = 0x0; //no pull up/pull down on any pins

	GPIOC -> BSRR = 0x01000200; //PC9 (green led) on, PC8 (blue led) off
}

#endif // GPIO_H
