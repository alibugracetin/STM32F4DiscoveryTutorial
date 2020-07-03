/*
 * main.h
 *
 *  Created on: Jul 3, 2020
 *      Author: alibugracetin
 */

#ifndef MAIN_H_
#define MAIN_H_

#include<stdint.h>

typedef struct
{

	uint32_t GPIOA_ENABLE			:1;
	uint32_t GPIOB_ENABLE			:1;
	uint32_t GPIOC_ENABLE			:1;
	uint32_t GPIOD_ENABLE			:1;
	uint32_t GPIOE_ENABLE			:1;
	uint32_t GPIOF_ENABLE			:1;
	uint32_t GPIOG_ENABLE			:1;
	uint32_t GPIOH_ENABLE			:1;
	uint32_t GPIOI_ENABLE			:1;
	uint32_t Reserved1				:3;
	uint32_t CRC_ENABLE 			:1;
	uint32_t Reserved2				:5;
	uint32_t BKPSRAM_ENABLE			:1;
	uint32_t Reserved3				:1;
	uint32_t CCMDATARAM_ENABLE 		:1;
	uint32_t DMA1_ENABLE 			:1;
	uint32_t DMA2_ENABLE			:1;
	uint32_t Reserved4				:2;
	uint32_t ETHMAC_ENABLE 			:1;
	uint32_t ETHMACTX_ENABLE		:1;
	uint32_t ETHMACRX_ENABLE		:1;
	uint32_t ETHMACPTP_ENABLE		:1;
	uint32_t OTGHS_ENABLE			:1;
	uint32_t OTGHSULPI_ENABLE		:1;
	uint32_t Reserved5				:1;

}RCC_AHB1_EN_t;

typedef struct
{
	//00 Input 01 Output
	uint32_t GPIO_Pin_0				:2;
	uint32_t GPIO_Pin_1				:2;
	uint32_t GPIO_Pin_2				:2;
	uint32_t GPIO_Pin_3				:2;
	uint32_t GPIO_Pin_4				:2;
	uint32_t GPIO_Pin_5				:2;
	uint32_t GPIO_Pin_6				:2;
	uint32_t GPIO_Pin_7				:2;
	uint32_t GPIO_Pin_8				:2;
	uint32_t GPIO_Pin_9				:2;
	uint32_t GPIO_Pin_10			:2;
	uint32_t GPIO_Pin_11			:2;
	uint32_t GPIO_Pin_12			:2;
	uint32_t GPIO_Pin_13			:2;
	uint32_t GPIO_Pin_14			:2;
	uint32_t GPIO_Pin_15			:2;

}GPIOx_MODER_t;

typedef struct
{
	//00 Input 01 Output
	uint32_t GPIO_Pin_0				:1;
	uint32_t GPIO_Pin_1				:1;
	uint32_t GPIO_Pin_2				:1;
	uint32_t GPIO_Pin_3				:1;
	uint32_t GPIO_Pin_4				:1;
	uint32_t GPIO_Pin_5				:1;
	uint32_t GPIO_Pin_6				:1;
	uint32_t GPIO_Pin_7				:1;
	uint32_t GPIO_Pin_8				:1;
	uint32_t GPIO_Pin_9				:1;
	uint32_t GPIO_Pin_10			:1;
	uint32_t GPIO_Pin_11			:1;
	uint32_t GPIO_Pin_12			:1;
	uint32_t GPIO_Pin_13			:1;
	uint32_t GPIO_Pin_14			:1;
	uint32_t GPIO_Pin_15			:1;
	uint32_t Reserved				:16;

}GPIOx_OutPut_t;

typedef struct
{

	uint32_t IDR0		:1;
	uint32_t IDR1		:1;
	uint32_t IDR2		:1;
	uint32_t IDR3		:1;
	uint32_t IDR4		:1;
	uint32_t IDR5		:1;
	uint32_t IDR6		:1;
	uint32_t IDR7		:1;
	uint32_t IDR8		:1;
	uint32_t IDR9		:1;
	uint32_t IDR10		:1;
	uint32_t IDR11		:1;
	uint32_t IDR12		:1;
	uint32_t IDR13		:1;
	uint32_t IDR14		:1;
	uint32_t IDR15		:1;
	uint32_t Reserved   :16;

}GPIOx_InPut_t;

#endif /* MAIN_H_ */
