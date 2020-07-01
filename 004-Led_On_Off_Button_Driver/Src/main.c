/**
  ******************************************************************************
  *
  *Created 01.07.2020
  *Created by alibugracetin
  *
  ******************************************************************************
*/

#include <stdint.h>
#include "Led_Driver.h"
#include "Button_Driver.h"


int main(void)
{
	Led_init();
	Button_init();

	while (1)
	{

		uint8_t input = Button_Read();

		if(input == 0)
		{
			Led_On();
		}
		else
			Led_Off();
	}

	return 0;

}
