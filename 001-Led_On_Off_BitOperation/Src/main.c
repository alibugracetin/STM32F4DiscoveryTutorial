/**
  ******************************************************************************
  *
  *Created 29.06.2020
  *Created by alibugracetin
  *
  ******************************************************************************
*/


/*
 *	Base adress of AHB1_Rcc = 0x40023800
 *	ofset adress for RCC Enable periph 0x30
 *	Adress of RCC_Enable_periph = 0x40023830
 *
 * 	Base adress  Mode_register of GPIOD = 0x40020C00
 * 	ofset adress for GPIO Enable Periph 0x00
 * 	Adress of GPIOD_Mode_Reg = 0x40020C00
 *
 * 	Base adress  Output_register of GPIOD = 0x40020C00
 * 	ofset adress for GPIO Enable Periph 0x14
 * 	Adress of GPIOD_Output_Reg = 0x40020C14
 */

#include<stdint.h>

#define LED_HIGH

int main(void)
{

	//constant pointer pointing to uint32_t variable. Const pointer shouldn't point another adress
	uint32_t  volatile *const RCC_AHB1_Enable 	= (uint32_t *)(0x40023830);
	uint32_t  volatile *const GPIOD_Mode_Reg   	= (uint32_t *)(0x40020C00);
	uint32_t  volatile *const GPIOD_Output_Reg 	= (uint32_t *)(0x40020C14);


	*RCC_AHB1_Enable |= (1 << 3) ;
	//shift left three times and  masking

	*GPIOD_Mode_Reg &= (~(3 << 24));
	*GPIOD_Mode_Reg |= (1 << 24);

#ifdef LED_HIGH

	//LED_12 HIGH
	*GPIOD_Output_Reg |= (1 << 12);

#else
	//LED_12 LOW
	*GPIOD_Output_Reg &= (0 << 12);

#endif

	while (1)
	{


	}

}
