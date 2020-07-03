/**
  ******************************************************************************
  *
  *Created 02.07.2020
  *Created by alibugracetin
  *
  ******************************************************************************
*/

#include <stdint.h>
//Define all packet in main.h headers file
#include "main.h"

int main(void)
{

	RCC_AHB1_EN_t  volatile *const pRCC_AHB1_Clock 		= (RCC_AHB1_EN_t*)(0x40023830);
	GPIOx_MODER_t  volatile *const pGPIOD_Mode	   		= (GPIOx_MODER_t*)(0x40020C00);
	GPIOx_OutPut_t volatile *const pGPIOD_OutPut	    = (GPIOx_OutPut_t*)(0x40020C14);

	pRCC_AHB1_Clock -> GPIOD_ENABLE = 1;
	//Set GPIODEN Periph

	pGPIOD_Mode -> GPIO_Pin_12 = 1;
	pGPIOD_Mode -> GPIO_Pin_13 = 1;
	pGPIOD_Mode -> GPIO_Pin_14 = 1;
	pGPIOD_Mode -> GPIO_Pin_15 = 1;
	//OutPut Pin12, Pin13, Pin14, Pin15

	while(1){

	pGPIOD_OutPut ->GPIO_Pin_12 = 1;
	pGPIOD_OutPut ->GPIO_Pin_13 = 1;
	pGPIOD_OutPut ->GPIO_Pin_14 = 1;
	pGPIOD_OutPut ->GPIO_Pin_15 = 1;

	//Setbit Pin12, Pin13, Pin14, Pin15

	for(int i = 0; i < 100000; i++)
		{
			//Delay 0.125 seconds
		}

	pGPIOD_OutPut ->GPIO_Pin_12 = 0;
	pGPIOD_OutPut ->GPIO_Pin_13 = 0;
	pGPIOD_OutPut ->GPIO_Pin_14 = 0;
	pGPIOD_OutPut ->GPIO_Pin_15 = 0;

	//Resetbit Pin12, Pin13, Pin14, Pin15

	for(int i = 0; i < 100000; i++)
		{
			//Delay 0.125 seconds
		}
	}
}
