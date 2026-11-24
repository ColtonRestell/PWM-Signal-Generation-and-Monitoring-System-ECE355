#ifndef EXTI_H
#define EXTI_H

void myEXTI2_3_Init()
{
    SYSCFG->EXTICR[0] |= SYSCFG_EXTICR1_EXTI2_PB; //EXTI line 2 connects to PB2

    SYSCFG->EXTICR[0] |= SYSCFG_EXTICR1_EXTI3_PB; //EXTI line 3 connects to PB3

    EXTI->RTSR |= EXTI_RTSR_TR2 | EXTI_RTSR_TR3; //rising edge trigger on line 2 & 3

    EXTI->IMR |= EXTI_IMR_MR2; //EXTI line 2 active

    EXTI->IMR &= ~EXTI_IMR_MR3; //EXTI line 3 not active (masked)

    NVIC_SetPriority(EXTI2_3_IRQn, 0); //priority 0

    NVIC_EnableIRQ(EXTI2_3_IRQn); //enable IRQ from EXTI line
}

void myEXTI0_1_Init()
{
     SYSCFG->EXTICR[0] |= SYSCFG_EXTICR1_EXTI0_PA; //EXTI line 0 connects to PA0

     EXTI->RTSR |= EXTI_RTSR_TR0; //rising edge trigger

     EXTI->IMR |= EXTI_IMR_MR0; //EXTI line 0 active

     NVIC_SetPriority(EXTI0_1_IRQn, 0); //priority 0

     NVIC_EnableIRQ(EXTI0_1_IRQn); //enable IRQ from EXTI line
}

#endif // EXTI_H
