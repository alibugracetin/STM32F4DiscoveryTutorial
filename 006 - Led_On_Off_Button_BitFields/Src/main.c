/**
  ******************************************************************************
  *
  *Created 03.07.2020
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
	GPIOx_MODER_t  volatile *const pGPIOA_Mode	   		= (GPIOx_MODER_t*)(0x40020000);
	GPIOx_InPut_t  volatile *const pGPIOA_InPut	    	= (GPIOx_InPut_t*)(0x40020010);

	pRCC_AHB1_Clock -> GPIOA_ENABLE = 1;
	pRCC_AHB1_Clock -> GPIOD_ENABLE = 1;
	//Set GPIOAEN, GPIODEN Periph

	pGPIOA_Mode ->GPIO_Pin_0 = 0;
	//Input Mode Pin0

	pGPIOD_Mode -> GPIO_Pin_12 = 1;
	pGPIOD_Mode -> GPIO_Pin_13 = 1;
	pGPIOD_Mode -> GPIO_Pin_14 = 1;
	pGPIOD_Mode -> GPIO_Pin_15 = 1;
	//OutPut Pin12, Pin13, Pin14, Pin15

	uint32_t status ;
	//Pin status variable

	while(1){

	status = pGPIOA_InPut -> IDR0 ;

	//Don't Press User Button
		if(status == 0)
		{

			pGPIOD_OutPut ->GPIO_Pin_12 = 1;
			pGPIOD_OutPut ->GPIO_Pin_13 = 1;
			pGPIOD_OutPut ->GPIO_Pin_14 = 1;
			pGPIOD_OutPut ->GPIO_Pin_15 = 1;

			//Setbit Pin12, Pin13, Pin14, Pin15

		}

		//Press User Button
		else
		{

			pGPIOD_OutPut ->GPIO_Pin_12 = 0;
			pGPIOD_OutPut ->GPIO_Pin_13 = 0;
			pGPIOD_OutPut ->GPIO_Pin_14 = 0;
			pGPIOD_OutPut ->GPIO_Pin_15 = 0;

			//Resetbit Pin12, Pin13, Pin14, Pin15
		}

	}
}
