/**
  ******************************************************************************
  *
  *Created 29.06.2020
  *Created by alibugracetin
  *
  ******************************************************************************
*/


/*
 *	Base adress  AHB1_Rcc = 0x40023800
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

#define DelayTime  100000

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

	while (1)
	{
		*GPIOD_Output_Reg ^= (1 << 12);

		for(uint32_t i = 0; i < DelayTime; i++)
		{
			/*
			 * 0.125 seconds delay for 100000 times increase i variable

				assembly code for "for loops"
				---------------------------------------------------------
				for(uint32_t i = 0; i < DelayTime; i++)
				0800022a:   movs    r3, #0
				0800022c:   str     r3, [r7, #12]
				0800022e:   b.n     0x8000236 <main+78>
				08000230:   ldr     r3, [r7, #12]
				08000232:   adds    r3, #1
				08000234:   str     r3, [r7, #12]
				08000236:   ldr     r3, [r7, #12]
				08000238:   ldr     r2, [pc, #16]   ; (0x800024c <main+100>)
				0800023a:   cmp     r3, r2
				0800023c:   bls.n   0x8000230 <main+72>
				---------------------------------------------------------

				complete for one "for loop" 10 clock cycle
				in STM32F4 one clock cyle = 1/8000000
				0.125 second = (1/8000000)*10*100000

			  */
		}

	}

	return 0;
}
