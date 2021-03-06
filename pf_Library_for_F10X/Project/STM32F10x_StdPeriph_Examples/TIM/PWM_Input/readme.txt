/**
  @page TIM_PWM_Input TIM PWM Input example
  
  @verbatim
  ******************** (C) COPYRIGHT 2011 STMicroelectronics *******************
  * @file    TIM/PWM_Input/readme.txt 
  * @author  MCD Application Team
  * @version V3.6.0
  * @date    20-September-2021
  * @brief   Description of the TIM PWM Input example.
  ******************************************************************************
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
  ******************************************************************************
   @endverbatim

@par Example Description 

This example shows how to use the TIM peripheral to measure the frequency and 
duty cycle of an external signal.

The TIMxCLK frequency is set to SystemCoreClock (Hz), the Prescaler is 0 so the 
TIM3 counter clock is SystemCoreClock (Hz).
SystemCoreClock is set to 72 MHz for Low-density, Medium-density, High-density
and Connectivity line devices. For Low-Density Value line, Medium-Density 
Value line and High-Density devices, SystemCoreClock is set to 24 MHz.

TIM3 is configured in PWM Input Mode: the external signal is connected to 
TIM3 Channel2 used as input pin.
To measure the frequency and the duty cycle we use the TIM3 CC2 interrupt request,
so In the TIM3_IRQHandler routine, the frequency and the duty cycle of the external 
signal are computed. 
The "Frequency" variable contains the external signal frequency:
Frequency = TIM3 counter clock / TIM3_CCR2 in Hz, 
The "DutyCycle" variable contains the external signal duty cycle:
DutyCycle = (TIM3_CCR1*100)/(TIM3_CCR2) in %.

For Low-density, Medium-density, High-density and Connectivity line devices, 
the minimum frequency value to measure is 1100 Hz. 
For Low-Density Value line and Medium-Density Value line devices, the minimum
frequency value to measure is 366 Hz.

@par Directory contents 

  - TIM/PWM_Input/stm32f10x_conf.h    Library Configuration file
  - TIM/PWM_Input/stm32f10x_it.c      Interrupt handlers
  - TIM/PWM_Input/stm32f10x_it.h      Interrupt handlers header file
  - TIM/PWM_Input/main.c              Main program 
  - TIM/PWM_Input/system_stm32f10x.c  STM32F10x system source file
  
@par Hardware and Software environment 

  - This example runs on STM32F10x Connectivity line, High-Density, High-Density 
    Value line, Medium-Density, XL-Density, Medium-Density Value line, Low-Density 
    and Low-Density Value line Devices.
  
  - This example has been tested with STMicroelectronics STM32100E-EVAL (High-Density
    Value line), STM32100B-EVAL (Medium-Density Value line), STM3210C-EVAL (Connectivity line), 
    STM3210E-EVAL (High-Density and XL-Density) and STM3210B-EVAL (Medium-Density) 
    evaluation boards and can be easily tailored to any other supported device 
    and development board.

  - STM32100B-EVAL, STM3210E-EVAL, STM32100E-EVAL, STM3210B-EVAL and STM3210C-EVAL  Set-up 
    - Connect the external signal to measure to the TIM3 CH2 pin (PA.07).   
  
@par How to use it ? 

In order to make the program work, you must do the following :
 - Copy all source files from this example folder to the template folder under
   Project\STM32F10x_StdPeriph_Template
 - Open your preferred toolchain 
 - Rebuild all files and load your image into target memory
 - Run the example 

@note
 - Low-density Value line devices are STM32F100xx microcontrollers where the 
   Flash memory density ranges between 16 and 32 Kbytes.
 - Low-density devices are STM32F101xx, STM32F102xx and STM32F103xx 
   microcontrollers where the Flash memory density ranges between 16 and 32 Kbytes.
 - Medium-density Value line devices are STM32F100xx microcontrollers where
   the Flash memory density ranges between 64 and 128 Kbytes.  
 - Medium-density devices are STM32F101xx, STM32F102xx and STM32F103xx 
   microcontrollers where the Flash memory density ranges between 64 and 128 Kbytes.
 - High-density Value line devices are STM32F100xx microcontrollers where
   the Flash memory density ranges between 256 and 512 Kbytes.
 - High-density devices are STM32F101xx and STM32F103xx microcontrollers where
   the Flash memory density ranges between 256 and 512 Kbytes.
 - XL-density devices are STM32F101xx and STM32F103xx microcontrollers where
   the Flash memory density ranges between 512 and 1024 Kbytes.
 - Connectivity line devices are STM32F105xx and STM32F107xx microcontrollers.
   
 * <h3><center>&copy; COPYRIGHT 2011 STMicroelectronics</center></h3>
 */
