#include "stm32f10x.h"
#include "stm32f10x.h"
#include "main.h"

void delay(long cycles)
{
  while(cycles >0)
  cycles-- ; 
}

void gpio_ports_enable(void)
{
  RCC->APB2ENR |= RCC_APB2ENR_IOPAEN | RCC_APB2ENR_IOPBEN|RCC_APB2ENR_IOPCEN; //ports A & B clock enabled
  GPIOC->CRH = 0x44344444; //Pin C13 enable. If you don't like number 13, use pin C_1_P.M. LOL
}

int main(void)
{
    gpio_ports_enable();

    for(;;)  //main loop - read "forever", or you may use 'while(1)'
    {
			GPIOC->BSRR = GPIO_BSRR_BS13; 
      delay(3000000);
      GPIOC->BSRR = GPIO_BSRR_BR13; 
      delay(3000000); 
    }    
}
//Можно сбросить или установить сразу несколько битов одним обращением к регистру BSRR. 
//Это будет выглядеть так.

//GPIOB -> BSRR = GPIO_BSRR_BS10 | GPIO_BSRR_BS15 | GPIO_BSRR_BR11 | GPIO_BSRR_BR12; // установить биты 10 и 15, сбросить биты 11 и 12