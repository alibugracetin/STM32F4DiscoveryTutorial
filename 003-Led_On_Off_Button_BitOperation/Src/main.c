/**
 ******************************************************************************
 *
 *Created 01.07.2020
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

#include<stdint.h>

#define DelayTime  100000

int main(void) {

	//constant pointer pointing to uint32_t variable. Const pointer shouldn't point another adress
	uint32_t volatile *const RCC_AHB1_Enable = (uint32_t*) (0x40023830);
	uint32_t volatile *const GPIOD_Mode_Reg = (uint32_t*) (0x40020C00);
	uint32_t volatile *const GPIOD_Output_Reg = (uint32_t*) (0x40020C14);

	uint32_t volatile *const GPIOA_Mode_Reg = (uint32_t*) (0x40020000);
	uint32_t volatile *const GPIOA_Pull_Up_Down = (uint32_t*) (0x4002000C);
	uint32_t volatile *const GPIOA_Input = (uint32_t*) (0x40020010);

	*RCC_AHB1_Enable |= (1 << 0); //RCC Enable for GPIOA
	*RCC_AHB1_Enable |= (1 << 3); //RCC Enable for GPIOD
	//shift left three times and  masking

	*GPIOD_Mode_Reg &= (~(3 << 24));
	*GPIOD_Mode_Reg |= (1 << 24);

	//GPIOA A0 input mode
	*GPIOA_Mode_Reg &= (~(3 << 0));

	//GPIOA A0 Pull Up
	*GPIOA_Pull_Up_Down &= (~(3 << 0));
	*GPIOA_Pull_Up_Down |= (0 << 1);

	while (1) {
		uint8_t input = (uint8_t) (*GPIOA_Input & 0x1);

		if (input == 0) {
			*GPIOD_Output_Reg = (1 << 12);
		} else
			*GPIOD_Output_Reg = (0 << 12);
	}

	return 0;
}
