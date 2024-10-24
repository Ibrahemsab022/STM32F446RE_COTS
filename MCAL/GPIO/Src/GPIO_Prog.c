/*****************************************************
 * file: GPIO_Pro.c
 * brief: This file contains the implementation of GPIO Peripheral functions
 * author: Ibrahim Saber
 * version: 1.0
 * date: 8 - 10 -2024
 ****************************************************/

#include "stdint.h"

#include "Stm32F446xx.h"

#include "GPIO_Interface.h"
#include "GPIO_Prv.h"


/*Array of Ptrs to the addresses of the GPIOs, their index is matching their position in the PORT enum (This to avoid switching on the PinConfigs -> PORT)*/
static GPIO_RegDef_t * GPIO_PORT[GPIO_PERIPHERAL_NUM] = {GPIOA, GPIOB, GPIOC, GPIOD, GPIOE, GPIOF, GPIOG, GPIOH};


/****************************************************************************************************
 * 	Decription: This Function is used to init a GPIO pin.
 * 	Parameters: - const PinConfig_t * PinConfigs: is a pointer to a struct contain the configs.
 * 	Returns: uint8_t errorState
 * 	Preconditions: - RCC is initialized and working
 * 				   - Clk enabled for GPIO Peripheral
 * 	Side effects: No side effects
 * 	Post Conditions: a GPIO Pin is configed
 * 	Synch/Asynch: Synch.
 * 	Reentrant/NonReenterant: Re
 ***************************************************************************************************/
uint8_t GPIO_u8PinInit(const GPIO_PinConfig_t * PinConfigs)
{

	GPIOErrorStates_t ErrorState = Exit_Ok;


	if (PinConfigs != NULL)
	{

		if ((PinConfigs -> Port <= PORTH) && (PinConfigs -> PinNum <= PIN15))
		{

			/*Selecting The pin mode: Input, output, analog, AF*/
			(GPIO_PORT[PinConfigs -> Port] -> MODER) &= ~(GPIO_2BIT_MASK 	   		<< ((PinConfigs -> PinNum) * GPIO_2BIT_PIN_REG));
			(GPIO_PORT[PinConfigs -> Port] -> MODER) |=  ((PinConfigs -> Mode) 		<< ((PinConfigs -> PinNum) * GPIO_2BIT_PIN_REG));

			/*Selecting Pull-up/down Configs*/
			(GPIO_PORT[PinConfigs -> Port] -> PUPDR) &= ~(GPIO_2BIT_MASK 		   	<< ((PinConfigs -> PinNum) * GPIO_2BIT_PIN_REG));
			(GPIO_PORT[PinConfigs -> Port] -> PUPDR) |=  ((PinConfigs -> PullType) 	<< ((PinConfigs -> PinNum) * GPIO_2BIT_PIN_REG));


			/*Output-specfic Configs*/
			if ((PinConfigs -> Mode == OUTPUT) || (PinConfigs -> Mode == ALT_FUNC))
			{
				/*Selecting Output types: Push-Pull, Open-Drain*/
				(GPIO_PORT[PinConfigs -> Port] -> OTYPER) &= ~(GPIO_1BIT_MASK 			  << (PinConfigs -> PinNum));
				(GPIO_PORT[PinConfigs -> Port] -> OTYPER) |=  ((PinConfigs -> OutputType) << (PinConfigs -> PinNum));

				/*Selecting Output Speed: Low, Mid, Fast or High*/
				(GPIO_PORT[PinConfigs -> Port] -> OSPEEDR) &= ~(GPIO_2BIT_MASK 		  << ((PinConfigs -> PinNum) * GPIO_2BIT_PIN_REG));
				(GPIO_PORT[PinConfigs -> Port] -> OSPEEDR) |=  ((PinConfigs -> Speed) << ((PinConfigs -> PinNum) * GPIO_2BIT_PIN_REG));

			}


			/*AF-Specfic Configs*/
			if (PinConfigs -> Mode == ALT_FUNC)
			{
				uint8_t Local_u8RegNum = (PinConfigs -> PinNum) / AFR_PIN_SHIFTING;
				uint8_t Local_u8BitNum = (PinConfigs -> PinNum) % AFR_PIN_SHIFTING;

				/*For the Low register (AFRL)*/
				(GPIO_PORT[PinConfigs -> Port] -> AFR[Local_u8RegNum]) &= ~(GPIO_4BIT_MASK 			<< (Local_u8BitNum * 4));
				(GPIO_PORT[PinConfigs -> Port] -> AFR[Local_u8RegNum]) |=  ((PinConfigs -> AltFunc) << (Local_u8BitNum * 4));

			}

	}

	else
	{
		ErrorState = InvalidPinOrPortNum;
	}

}

	else
	{
		ErrorState = NullPtr;
	}



	return ErrorState;

}




/****************************************************************************************************
 * 	Decription: This Function is used to init a GPIO Port (use it when all pins have same configs)
 * 	Parameters: - const PinConfig_t * PinConfigs: is a pointer to a struct contain the configs.
 * 	Returns: uint8_t errorState
 * 	Preconditions: - RCC is initialized and working
 * 				   - Clk enabled for GPIO Peripheral
 * 	Side effects: No side effects
 * 	Post Conditions: a GPIO Port is configed
 * 	Synch/Asynch: Synch.
 * 	Reentrant/NonReenterant: Re
 ***************************************************************************************************/
uint8_t GPIO_u8PortInit(const GPIO_PinConfig_t * PinConfigs)
{

	GPIOErrorStates_t ErrorState = Exit_Ok;


	if (PinConfigs != NULL)
	{

		if (PinConfigs -> Port <= PORTH)
		{

			uint8_t i;

			for(i = 0; i <= 15; i++)
			{

				/*Selecting The pin mode: Input, output, analog, AF*/
				(GPIO_PORT[PinConfigs -> Port] -> MODER) &= ~(GPIO_2BIT_MASK 	   		<< ((i) * GPIO_2BIT_PIN_REG));
				(GPIO_PORT[PinConfigs -> Port] -> MODER) |=  ((PinConfigs -> Mode) 		<< ((i) * GPIO_2BIT_PIN_REG));

				/*Selecting Pull-up/down Configs*/
				(GPIO_PORT[PinConfigs -> Port] -> PUPDR) &= ~(GPIO_2BIT_MASK 		   	<< ((i) * GPIO_2BIT_PIN_REG));
				(GPIO_PORT[PinConfigs -> Port] -> PUPDR) |=  ((PinConfigs -> PullType) 	<< ((i) * GPIO_2BIT_PIN_REG));

			}

				/*Output-specfic Configs*/
				if ((PinConfigs -> Mode == OUTPUT) || (PinConfigs -> Mode == ALT_FUNC))
				{
					for(i = 0; i <= 15; i++)
					{
						/*Selecting Output types: Push-Pull, Open-Drain*/
						(GPIO_PORT[PinConfigs -> Port] -> OTYPER) &= ~(GPIO_1BIT_MASK 			  << (i));
						(GPIO_PORT[PinConfigs -> Port] -> OTYPER) |=  ((PinConfigs -> OutputType) << (i));

						/*Selecting Output Speed: Low, Mid, Fast or High*/
						(GPIO_PORT[PinConfigs -> Port] -> OSPEEDR) &= ~(GPIO_2BIT_MASK 		  << ((i) * GPIO_2BIT_PIN_REG));
						(GPIO_PORT[PinConfigs -> Port] -> OSPEEDR) |=  ((PinConfigs -> Speed) << ((i) * GPIO_2BIT_PIN_REG));
					}
				}


				/*AF-Specfic Configs*/
				if (PinConfigs -> Mode == ALT_FUNC)
				{
					for(i = 0; i <= 15; i++)
					{
						uint8_t Local_u8RegNum = (i) / AFR_PIN_SHIFTING;
						uint8_t Local_u8BitNum = (i) % AFR_PIN_SHIFTING;

						/*For the Low register (AFRL)*/
						(GPIO_PORT[PinConfigs -> Port] -> AFR[Local_u8RegNum]) &= ~(GPIO_4BIT_MASK 			<< (Local_u8BitNum * 4));
						(GPIO_PORT[PinConfigs -> Port] -> AFR[Local_u8RegNum]) |=  ((PinConfigs -> AltFunc) << (Local_u8BitNum * 4));

					}
				}

		}


		else
		{
			ErrorState = InvalidPinOrPortNum;
		}

	}


	else
	{
		ErrorState = NullPtr;
	}


	return ErrorState;
}





/****************************************************************************************************
 * 	Decription: This Function is used to set a GPIO pin.
 * 	Parameters: - port_t Port: is an enum holding the port.
 *				- Pin_t PinNum: is an enum holding the pin number.
 *				- PinVal_t PinVal: is an enum holding the pin value.
 * 	Returns: uint8_t errorState
 * 	Preconditions: - RCC is initialized and working
 * 				   - Clk enabled for GPIO Peripheral
 *				   - Pin is Configed usin GPIO_u8PinInit as OUTPUT
 * 	Side effects: No side effects
 * 	Post Conditions: a GPIO Pin is set to a value
 * 	Synch/Asynch: Synch.
 * 	Reentrant/NonReenterant: Re
 ***************************************************************************************************/
uint8_t GPIO_u8SetPinValue(Port_t Port, Pin_t PinNum, PinVal_t PinVal)
{
	GPIOErrorStates_t ErrorState = Exit_Ok;


	if ((Port <= PORTH) && (PinNum <= PIN15))
	{
		if(PinVal == PIN_LOW)
		{
			(GPIO_PORT[Port] -> ODR) &= ~(GPIO_1BIT_MASK << PinNum);
			/*GPIO_PORT[Port] -> BSRR = 1 << (16 + PinNum)*/ /* <- This method is faster using the bit set/reset reg */
		}

		else if(PinVal == PIN_HIGH)
		{
			(GPIO_PORT[Port] -> ODR) |= (GPIO_1BIT_MASK << PinNum);
		}

		else
		{
			ErrorState = InvalidPinOrPortNum;
		}


	}

	else
	{
		ErrorState = InvalidPinOrPortNum;
	}


	return ErrorState;
}





/****************************************************************************************************
 * 	Decription: This Function is used to toggle a GPIO pin.
 * 	Parameters: - port_t Port: is an enum holding the port.
 *				- Pin_t PinNum: is an enum holding the pin number.
 * 	Returns: uint8_t errorState
 * 	Preconditions: - RCC is initialized and working
 * 				   - Clk enabled for GPIO Peripheral
 *				   - Pin is Configed usin GPIO_u8PinInit as OUTPUT
 * 	Side effects: No side effects
 * 	Post Conditions: a GPIO Pin is set to a value
 * 	Synch/Asynch: Synch.
 * 	Reentrant/NonReenterant: Re
 ***************************************************************************************************/
uint8_t GPIO_u8TogglePinValue(Port_t Port, Pin_t PinNum)
{

	GPIOErrorStates_t ErrorState = Exit_Ok;


	if ((Port <= PORTH) && (PinNum <= PIN15))
	{

		(GPIO_PORT[Port] -> ODR) ^= (GPIO_1BIT_MASK << PinNum);

	}

	else
	{
		ErrorState = InvalidPinOrPortNum;
	}


	return ErrorState;
}





/****************************************************************************************************
 * 	Decription: This Function is used to set a GPIO pin.
 * 	Parameters: - port_t Port: is an enum holding the port.
 *				- Pin_t PinNum: is an enum holding the pin number.
 *				- PinVal_t* PinVal: is a ptr to an enum to recive the value by reference.
 * 	Returns: uint8_t errorState
 * 	Preconditions: - RCC is initialized and working
 * 				   - Clk enabled for GPIO Peripheral
 *				   - Pin is Configed usin GPIO_u8PinInit as INPUT
 * 	Side effects: No side effects
 * 	Post Conditions: a GPIO Pin is read
 * 	Synch/Asynch: Synch.
 * 	Reentrant/NonReenterant: Re
 ***************************************************************************************************/
uint8_t GPIO_u8ReadPinValue(Port_t Port, Pin_t PinNum, PinVal_t* PinVal)
{

	GPIOErrorStates_t ErrorState = Exit_Ok;


	if ((Port <= PORTH) && (PinNum <= PIN15))
	{

		*PinVal = (GPIO_1BIT_MASK & ((GPIO_PORT[Port] -> IDR) >> PinNum));

	}

	else
	{
		ErrorState = InvalidPinOrPortNum;
	}


	return ErrorState;


}


