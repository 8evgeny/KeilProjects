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
	// http://dimoon.ru/obuchalka/stm32f1/programmirovanie-stm32-chast-5-portyi-vvoda-vyivoda-gpio.html
  RCC->APB2ENR |= RCC_APB2ENR_IOPAEN | RCC_APB2ENR_IOPBEN|RCC_APB2ENR_IOPCEN; //ports A & B clock enabled
  GPIOC->CRH = 0x44344444; //Pin C13 enable. If you don't like number 13, use pin C_1_P.M. LOL
	GPIOA->CRH = 0x44444443; // A08 enable
	GPIOB->CRL = 0x44444434; // B01 enable 
	GPIOB->CRH = 0x43434344; // B10 B12 B14 enable
}

int main(void)
{
    gpio_ports_enable();

    for(;;)  //main loop - read "forever", or you may use 'while(1)'
    {
			GPIOC->BSRR = GPIO_BSRR_BS13;
      delay(1000000);
      GPIOC->BSRR = GPIO_BSRR_BR13; 
      delay(1000000); 

			GPIOB->BSRR = GPIO_BSRR_BS1;
      delay(1000000);
			GPIOB->BSRR = GPIO_BSRR_BR1;
      delay(1000000);
			
			GPIOB->BSRR = GPIO_BSRR_BS10;
      delay(1000000);
			GPIOB->BSRR = GPIO_BSRR_BR10;
      delay(1000000);
			
			GPIOB->BSRR = GPIO_BSRR_BS12;
      delay(1000000);
			GPIOB->BSRR = GPIO_BSRR_BR12;
      delay(1000000);
			
			GPIOB->BSRR = GPIO_BSRR_BS14;
      delay(1000000);
			GPIOB->BSRR = GPIO_BSRR_BR14;
      delay(1000000);
			
			GPIOA->BSRR = GPIO_BSRR_BS8;
      delay(1000000);
			GPIOA->BSRR = GPIO_BSRR_BR8;
      delay(1000000);
			
    }    
}
//Можно сбросить или установить сразу несколько битов одним обращением к регистру BSRR. 
//Это будет выглядеть так.

//GPIOB -> BSRR = GPIO_BSRR_BS10 | GPIO_BSRR_BS15 | GPIO_BSRR_BR11 | GPIO_BSRR_BR12; // установить биты 10 и 15, сбросить биты 11 и 12