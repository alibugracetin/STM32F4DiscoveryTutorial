/*
 * Button_Driver.c
 *
 *  Created on: Jul 1, 2020
 *      Author: alibugracetin
 */

/*
 * 	Base adress of AHB1_Rcc = 0x40023800
 *	ofset adress for RCC Enable periph 0x30
 *	Adress of RCC_Enable_periph_A = 0x40023830
 *
 * 	Base adress  Mode_register of GPIOA = 0x40020000
 * 	ofset adress for GPIO Enable Periph 0x00
 * 	Adress of GPIOD_Mode_Reg = 0x40020000
 *
 * 	Base adress  Input_register of GPIOA = 0x40020000
 * 	ofset adress for GPIO Enable Periph 0x10
 * 	Adress of GPIOD_Output_Reg = 0x40020010
 *
 * 	Base adress  PullUpPullDown of GPIOA = 0x40020000
 * 	ofset adress for GPIO Enable Periph 0x0C
 * 	Adress of GPIOD_Output_Reg = 0x4002000C
 *
 */

#include <stdint.h>

uint32_t volatile *const RCC_AHB1_Enable_A 	 = (uint32_t *)(0x40023830);
uint32_t volatile *const GPIOA_Mode_Reg		 = (uint32_t *)(0x40020000);
uint32_t volatile *const GPIOA_Pull_Up_Down  = (uint32_t *)(0x4002000C);
uint32_t volatile *const GPIOA_Input		 = (uint32_t *)(0x40020010);

void Button_init(void)
{
	*RCC_AHB1_Enable_A |= (1 << 0) ; //RCC Enable for GPIOA

	//GPIOA A0 input mode
	*GPIOA_Mode_Reg &= (~(3 << 0));

	//GPIOA A0 Pull Up
	*GPIOA_Pull_Up_Down &= (~(3 << 0));
	*GPIOA_Pull_Up_Down |= (0 << 1);

}

int Button_Read(void)
{
	uint8_t input = (uint8_t)(*GPIOA_Input & 0x1);
	return input;
}
