#ifndef timer_H
#define timer_H

#define myTIM2_PRESCALER ((uint16_t)0x0000)
#define myTIM2_PERIOD ((uint32_t)0xFFFFFFFF)

void myTIM2_Init()
{
  	RCC->APB1ENR |= RCC_APB1ENR_TIM2EN; //enable clock for TIM2

  	TIM2->CR1 = ((uint16_t)0x008C);  //buffered auto reload, update event on over/underflow, counter stops at update event

  	TIM2->PSC = myTIM2_PRESCALER; //0 prescaler

  	TIM2->ARR = myTIM2_PERIOD; //0xFFFFFFFF

  	TIM2->EGR = ((uint16_t)0x0001); //initialize timer

  	NVIC_SetPriority(TIM2_IRQn, 0); //priority 0

  	NVIC_EnableIRQ(TIM2_IRQn); //enable TIM2 IRQ

  	TIM2->DIER |= TIM_DIER_UIE; //enable interrupts on update event
}

void myTIM3_Init() //3ms overflow
{
	RCC->APB1ENR |= RCC_APB1ENR_TIM3EN; //enable TIM3 clock

	TIM3->CR1 = ((uint16_t)0x008C); //buffered auto reload, update event on over/underflow, counter stops at update event

	TIM3->PSC = 0x0; //no prescaler

	TIM3->ARR = 0x23280; //ARR for it to overflow in 3ms

	TIM3->EGR = ((uint16_t)0x0001); //initialize timer
}

void myTim3Init_Refresh()
{
	TIM3->CR1 = ((uint16_t)0x008C);

	TIM3->PSC = 0x0;

	TIM3->ARR = 0x493E00;  //ARR for it to overflow in 100ms

	TIM3->EGR = ((uint16_t)0x0001);
}

#endif // timer_H
