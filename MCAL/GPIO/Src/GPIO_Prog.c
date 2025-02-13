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
uint8_t GPIO_u8PinInit(const PinConfig_t * PinConfigs)
{

	GPIOErrorStates_t ErrorState = GPIO_Exit_OK;


	if (((PinConfigs -> PinNum) >= 0) && ((PinConfigs -> PinNum) <= 15))
	{
		switch(PinConfigs -> Port)
		{

		/******************* PORTA *******************/
			case PORTA:
			{
				/*Selecting The pin mode: Input, output, analog, AF*/
				GPIOA -> MODER &= ~(GPIO_2BIT_MASK << ((PinConfigs -> PinNum) * 2));
				GPIOA -> MODER |= ((PinConfigs -> Mode) << ((PinConfigs -> PinNum) * 2));

				/*Output-specfic Configs*/
				if ((PinConfigs -> Mode == OUTPUT) || (PinConfigs -> Mode == ALT_FUNC))
				{
					/*Selecting Output types: Push-Pull, Open-Drain*/
					GPIOA -> OTYPER &= ~(GPIO_1BIT_MASK << (PinConfigs -> PinNum));
					GPIOA -> OTYPER |= ((PinConfigs -> OutputType) << (PinConfigs -> PinNum));

					/*Selecting Output Speed: Low, Mid, Fast or High*/
					GPIOA -> OSPEEDR &= ~(GPIO_2BIT_MASK << ((PinConfigs -> PinNum) * 2));
					GPIOA -> OSPEEDR |= ((PinConfigs -> Speed) << ((PinConfigs -> PinNum) * 2));

				}


				/*Selecting Pull-up/down Configs*/
				GPIOA -> PUPDR &= ~(GPIO_2BIT_MASK << ((PinConfigs -> PinNum) * 2));
				GPIOA -> PUPDR |= ((PinConfigs -> PullType) << ((PinConfigs -> PinNum) * 2));

				/*AF-Specfic Configs*/
				if (PinConfigs -> Mode == ALT_FUNC)
				{
					if(PinConfigs -> PinNum <= 7)
					{
						GPIOA -> AFR[0] &= ~(GPIO_4BIT_MASK << ((PinConfigs -> PinNum) * 4));
						GPIOA -> AFR[0] |= ((PinConfigs -> AltFunc) << ((PinConfigs -> PinNum) * 4));
					}

					else
					{
						GPIOA -> AFR[1] &= ~(GPIO_4BIT_MASK << ((PinConfigs -> PinNum) * 4));
						GPIOA -> AFR[1] |= ((PinConfigs -> AltFunc) << ((PinConfigs -> PinNum) * 4));
					}
				}
			}

			/******************* PORTB *******************/
			case PORTB:
			{
				/*Selecting The pin mode: Input, output, analog, AF*/
				GPIOB -> MODER &= ~(GPIO_2BIT_MASK << ((PinConfigs -> PinNum) * 2));
				GPIOB -> MODER |= ((PinConfigs -> Mode) << ((PinConfigs -> PinNum) * 2));

				/*Output-specfic Configs*/
				if ((PinConfigs -> Mode == OUTPUT) || (PinConfigs -> Mode == ALT_FUNC))
				{
					/*Selecting Output types: Push-Pull, Open-Drain*/
					GPIOB -> OTYPER &= ~(GPIO_1BIT_MASK << (PinConfigs -> PinNum));
					GPIOB -> OTYPER |= ((PinConfigs -> OutputType) << (PinConfigs -> PinNum));

					/*Selecting Output Speed: Low, Mid, Fast or High*/
					GPIOB -> OSPEEDR &= ~(GPIO_2BIT_MASK << ((PinConfigs -> PinNum) * 2));
					GPIOB -> OSPEEDR |= ((PinConfigs -> Speed) << ((PinConfigs -> PinNum) * 2));

				}


				/*Selecting Pull-up/down Configs*/
				GPIOB -> PUPDR &= ~(GPIO_2BIT_MASK << ((PinConfigs -> PinNum) * 2));
				GPIOB -> PUPDR |= ((PinConfigs -> PullType) << ((PinConfigs -> PinNum) * 2));

				/*AF-Specfic Configs*/
				if (PinConfigs -> Mode == ALT_FUNC)
				{
					if(PinConfigs -> PinNum <= 7)
					{
						GPIOB -> AFR[0] &= ~(GPIO_4BIT_MASK << ((PinConfigs -> PinNum) * 4));
						GPIOB -> AFR[0] |= ((PinConfigs -> AltFunc) << ((PinConfigs -> PinNum) * 4));
					}

					else
					{
						GPIOB -> AFR[1] &= ~(GPIO_4BIT_MASK << ((PinConfigs -> PinNum) * 4));
						GPIOB -> AFR[1] |= ((PinConfigs -> AltFunc) << ((PinConfigs -> PinNum) * 4));
					}
				}
			}


			/******************* PORTC *******************/
			case PORTC:
			{
				/*Selecting The pin mode: Input, output, analog, AF*/
				GPIOC -> MODER &= ~(GPIO_2BIT_MASK << ((PinConfigs -> PinNum) * 2));
				GPIOC -> MODER |= ((PinConfigs -> Mode) << ((PinConfigs -> PinNum) * 2));

				/*Output-specfic Configs*/
				if ((PinConfigs -> Mode == OUTPUT) || (PinConfigs -> Mode == ALT_FUNC))
				{
					/*Selecting Output types: Push-Pull, Open-Drain*/
					GPIOC -> OTYPER &= ~(GPIO_1BIT_MASK << (PinConfigs -> PinNum));
					GPIOC -> OTYPER |= ((PinConfigs -> OutputType) << (PinConfigs -> PinNum));

					/*Selecting Output Speed: Low, Mid, Fast or High*/
					GPIOC -> OSPEEDR &= ~(GPIO_2BIT_MASK << ((PinConfigs -> PinNum) * 2));
					GPIOC -> OSPEEDR |= ((PinConfigs -> Speed) << ((PinConfigs -> PinNum) * 2));

				}


				/*Selecting Pull-up/down Configs*/
				GPIOC -> PUPDR &= ~(GPIO_2BIT_MASK << ((PinConfigs -> PinNum) * 2));
				GPIOC -> PUPDR |= ((PinConfigs -> PullType) << ((PinConfigs -> PinNum) * 2));

				/*AF-Specfic Configs*/
				if (PinConfigs -> Mode == ALT_FUNC)
				{
					if(PinConfigs -> PinNum <= 7)
					{
						GPIOC -> AFR[0] &= ~(GPIO_4BIT_MASK << ((PinConfigs -> PinNum) * 4));
						GPIOC -> AFR[0] |= ((PinConfigs -> AltFunc) << ((PinConfigs -> PinNum) * 4));
					}

					else
					{
						GPIOC -> AFR[1] &= ~(GPIO_4BIT_MASK << ((PinConfigs -> PinNum) * 4));
						GPIOC -> AFR[1] |= ((PinConfigs -> AltFunc) << ((PinConfigs -> PinNum) * 4));
					}
				}
			}

			/******************* PORTD *******************/
			case PORTD:
			{
				/*Selecting The pin mode: Input, output, analog, AF*/
				GPIOD -> MODER &= ~(GPIO_2BIT_MASK << ((PinConfigs -> PinNum) * 2));
				GPIOD -> MODER |= ((PinConfigs -> Mode) << ((PinConfigs -> PinNum) * 2));

				/*Output-specfic Configs*/
				if ((PinConfigs -> Mode == OUTPUT) || (PinConfigs -> Mode == ALT_FUNC))
				{
					/*Selecting Output types: Push-Pull, Open-Drain*/
					GPIOD -> OTYPER &= ~(GPIO_1BIT_MASK << (PinConfigs -> PinNum));
					GPIOD -> OTYPER |= ((PinConfigs -> OutputType) << (PinConfigs -> PinNum));

					/*Selecting Output Speed: Low, Mid, Fast or High*/
					GPIOD -> OSPEEDR &= ~(GPIO_2BIT_MASK << ((PinConfigs -> PinNum) * 2));
					GPIOD -> OSPEEDR |= ((PinConfigs -> Speed) << ((PinConfigs -> PinNum) * 2));

				}


				/*Selecting Pull-up/down Configs*/
				GPIOD -> PUPDR &= ~(GPIO_2BIT_MASK << ((PinConfigs -> PinNum) * 2));
				GPIOD -> PUPDR |= ((PinConfigs -> PullType) << ((PinConfigs -> PinNum) * 2));

				/*AF-Specfic Configs*/
				if (PinConfigs -> Mode == ALT_FUNC)
				{
					if(PinConfigs -> PinNum <= 7)
					{
						GPIOD -> AFR[0] &= ~(GPIO_4BIT_MASK << ((PinConfigs -> PinNum) * 4));
						GPIOD -> AFR[0] |= ((PinConfigs -> AltFunc) << ((PinConfigs -> PinNum) * 4));
					}

					else
					{
						GPIOD -> AFR[1] &= ~(GPIO_4BIT_MASK << ((PinConfigs -> PinNum) * 4));
						GPIOD -> AFR[1] |= ((PinConfigs -> AltFunc) << ((PinConfigs -> PinNum) * 4));
					}
				}
			}

			/******************* PORTE *******************/
			case PORTE:
			{
				/*Selecting The pin mode: Input, output, analog, AF*/
				GPIOE -> MODER &= ~(GPIO_2BIT_MASK << ((PinConfigs -> PinNum) * 2));
				GPIOE -> MODER |= ((PinConfigs -> Mode) << ((PinConfigs -> PinNum) * 2));

				/*Output-specfic Configs*/
				if ((PinConfigs -> Mode == OUTPUT) || (PinConfigs -> Mode == ALT_FUNC))
				{
					/*Selecting Output types: Push-Pull, Open-Drain*/
					GPIOE -> OTYPER &= ~(GPIO_1BIT_MASK << (PinConfigs -> PinNum));
					GPIOE -> OTYPER |= ((PinConfigs -> OutputType) << (PinConfigs -> PinNum));

					/*Selecting Output Speed: Low, Mid, Fast or High*/
					GPIOE -> OSPEEDR &= ~(GPIO_2BIT_MASK << ((PinConfigs -> PinNum) * 2));
					GPIOE -> OSPEEDR |= ((PinConfigs -> Speed) << ((PinConfigs -> PinNum) * 2));

				}


				/*Selecting Pull-up/down Configs*/
				GPIOE -> PUPDR &= ~(GPIO_2BIT_MASK << ((PinConfigs -> PinNum) * 2));
				GPIOE -> PUPDR |= ((PinConfigs -> PullType) << ((PinConfigs -> PinNum) * 2));

				/*AF-Specfic Configs*/
				if (PinConfigs -> Mode == ALT_FUNC)
				{
					if(PinConfigs -> PinNum <= 7)
					{
						GPIOE -> AFR[0] &= ~(GPIO_4BIT_MASK << ((PinConfigs -> PinNum) * 4));
						GPIOE -> AFR[0] |= ((PinConfigs -> AltFunc) << ((PinConfigs -> PinNum) * 4));
					}

					else
					{
						GPIOE -> AFR[1] &= ~(GPIO_4BIT_MASK << ((PinConfigs -> PinNum) * 4));
						GPIOE -> AFR[1] |= ((PinConfigs -> AltFunc) << ((PinConfigs -> PinNum) * 4));
					}
				}
			}

			/******************* PORTF *******************/
			case PORTF:
			{
				/*Selecting The pin mode: Input, output, analog, AF*/
				GPIOF -> MODER &= ~(GPIO_2BIT_MASK << ((PinConfigs -> PinNum) * 2));
				GPIOF -> MODER |= ((PinConfigs -> Mode) << ((PinConfigs -> PinNum) * 2));

				/*Output-specfic Configs*/
				if ((PinConfigs -> Mode == OUTPUT) || (PinConfigs -> Mode == ALT_FUNC))
				{
					/*Selecting Output types: Push-Pull, Open-Drain*/
					GPIOF -> OTYPER &= ~(GPIO_1BIT_MASK << (PinConfigs -> PinNum));
					GPIOF -> OTYPER |= ((PinConfigs -> OutputType) << (PinConfigs -> PinNum));

					/*Selecting Output Speed: Low, Mid, Fast or High*/
					GPIOF -> OSPEEDR &= ~(GPIO_2BIT_MASK << ((PinConfigs -> PinNum) * 2));
					GPIOF -> OSPEEDR |= ((PinConfigs -> Speed) << ((PinConfigs -> PinNum) * 2));

				}


				/*Selecting Pull-up/down Configs*/
				GPIOF -> PUPDR &= ~(GPIO_2BIT_MASK << ((PinConfigs -> PinNum) * 2));
				GPIOF -> PUPDR |= ((PinConfigs -> PullType) << ((PinConfigs -> PinNum) * 2));

				/*AF-Specfic Configs*/
				if (PinConfigs -> Mode == ALT_FUNC)
				{
					if(PinConfigs -> PinNum <= 7)
					{
						GPIOF -> AFR[0] &= ~(GPIO_4BIT_MASK << ((PinConfigs -> PinNum) * 4));
						GPIOF -> AFR[0] |= ((PinConfigs -> AltFunc) << ((PinConfigs -> PinNum) * 4));
					}

					else
					{
						GPIOF -> AFR[1] &= ~(GPIO_4BIT_MASK << ((PinConfigs -> PinNum) * 4));
						GPIOF -> AFR[1] |= ((PinConfigs -> AltFunc) << ((PinConfigs -> PinNum) * 4));
					}
				}
			}

			/******************* PORTG *******************/
			case PORTG:
			{
				/*Selecting The pin mode: Input, output, analog, AF*/
				GPIOG -> MODER &= ~(GPIO_2BIT_MASK << ((PinConfigs -> PinNum) * 2));
				GPIOG -> MODER |= ((PinConfigs -> Mode) << ((PinConfigs -> PinNum) * 2));

				/*Output-specfic Configs*/
				if ((PinConfigs -> Mode == OUTPUT) || (PinConfigs -> Mode == ALT_FUNC))
				{
					/*Selecting Output types: Push-Pull, Open-Drain*/
					GPIOG -> OTYPER &= ~(GPIO_1BIT_MASK << (PinConfigs -> PinNum));
					GPIOG -> OTYPER |= ((PinConfigs -> OutputType) << (PinConfigs -> PinNum));

					/*Selecting Output Speed: Low, Mid, Fast or High*/
					GPIOG -> OSPEEDR &= ~(GPIO_2BIT_MASK << ((PinConfigs -> PinNum) * 2));
					GPIOG -> OSPEEDR |= ((PinConfigs -> Speed) << ((PinConfigs -> PinNum) * 2));

				}


				/*Selecting Pull-up/down Configs*/
				GPIOG -> PUPDR &= ~(GPIO_2BIT_MASK << ((PinConfigs -> PinNum) * 2));
				GPIOG -> PUPDR |= ((PinConfigs -> PullType) << ((PinConfigs -> PinNum) * 2));

				/*AF-Specfic Configs*/
				if (PinConfigs -> Mode == ALT_FUNC)
				{
					if(PinConfigs -> PinNum <= 7)
					{
						GPIOG -> AFR[0] &= ~(GPIO_4BIT_MASK << ((PinConfigs -> PinNum) * 4));
						GPIOG -> AFR[0] |= ((PinConfigs -> AltFunc) << ((PinConfigs -> PinNum) * 4));
					}

					else
					{
						GPIOG -> AFR[1] &= ~(GPIO_4BIT_MASK << ((PinConfigs -> PinNum) * 4));
						GPIOG -> AFR[1] |= ((PinConfigs -> AltFunc) << ((PinConfigs -> PinNum) * 4));
					}
				}
			}

			/******************* PORTH *******************/
			case PORTH:
			{
				/*Selecting The pin mode: Input, output, analog, AF*/
				GPIOH -> MODER &= ~(GPIO_2BIT_MASK << ((PinConfigs -> PinNum) * 2));
				GPIOH -> MODER |= ((PinConfigs -> Mode) << ((PinConfigs -> PinNum) * 2));

				/*Output-specfic Configs*/
				if ((PinConfigs -> Mode == OUTPUT) || (PinConfigs -> Mode == ALT_FUNC))
				{
					/*Selecting Output types: Push-Pull, Open-Drain*/
					GPIOH -> OTYPER &= ~(GPIO_1BIT_MASK << (PinConfigs -> PinNum));
					GPIOH -> OTYPER |= ((PinConfigs -> OutputType) << (PinConfigs -> PinNum));

					/*Selecting Output Speed: Low, Mid, Fast or High*/
					GPIOH -> OSPEEDR &= ~(GPIO_2BIT_MASK << ((PinConfigs -> PinNum) * 2));
					GPIOH -> OSPEEDR |= ((PinConfigs -> Speed) << ((PinConfigs -> PinNum) * 2));

				}


				/*Selecting Pull-up/down Configs*/
				GPIOH -> PUPDR &= ~(GPIO_2BIT_MASK << ((PinConfigs -> PinNum) * 2));
				GPIOH -> PUPDR |= ((PinConfigs -> PullType) << ((PinConfigs -> PinNum) * 2));

				/*AF-Specfic Configs*/
				if (PinConfigs -> Mode == ALT_FUNC)
				{
					if(PinConfigs -> PinNum <= 7)
					{
						GPIOH -> AFR[0] &= ~(GPIO_4BIT_MASK << ((PinConfigs -> PinNum) * 4));
						GPIOH -> AFR[0] |= ((PinConfigs -> AltFunc) << ((PinConfigs -> PinNum) * 4));
					}

					else
					{
						GPIOH -> AFR[1] &= ~(GPIO_4BIT_MASK << ((PinConfigs -> PinNum) * 4));
						GPIOH -> AFR[1] |= ((PinConfigs -> AltFunc) << ((PinConfigs -> PinNum) * 4));
					}
				}
			}


			default: ErrorState = GPIO_InvalidPortName;

		}


	}

	else
	{
		ErrorState = GPIO_InvalidPinNum;
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
	GPIOErrorStates_t ErrorState = GPIO_Exit_OK;


	if ((PinNum >= 0) && (PinNum <= 15))
	{
		switch(Port)
		{

		/******************* PORTA *******************/
			case PORTA:
			{
				GPIOA -> ODR &= ~(GPIO_1BIT_MASK << PinNum);
				GPIOA -> ODR |= ((PinVal << PinNum));
			}

		/******************* PORTB *******************/
			case PORTB:
			{
				GPIOB -> ODR &= ~(GPIO_1BIT_MASK << PinNum);
				GPIOB -> ODR |= ((PinVal << PinNum));
			}

		/******************* PORTC *******************/
			case PORTC:
			{
				GPIOC -> ODR &= ~(GPIO_1BIT_MASK << PinNum);
				GPIOC -> ODR |= ((PinVal << PinNum));
			}

		/******************* PORTD *******************/
			case PORTD:
			{
				GPIOD -> ODR &= ~(GPIO_1BIT_MASK << PinNum);
				GPIOD -> ODR |= ((PinVal << PinNum));
			}

		/******************* PORTE *******************/
			case PORTE:
			{
				GPIOE -> ODR &= ~(GPIO_1BIT_MASK << PinNum);
				GPIOE -> ODR |= ((PinVal << PinNum));
			}

		/******************* PORTF *******************/
			case PORTF:
			{
				GPIOF -> ODR &= ~(GPIO_1BIT_MASK << PinNum);
				GPIOF -> ODR |= ((PinVal << PinNum));
			}

		/******************* PORTG *******************/
			case PORTG:
			{
				GPIOG -> ODR &= ~(GPIO_1BIT_MASK << PinNum);
				GPIOG -> ODR |= ((PinVal << PinNum));
			}

		/******************* PORTH *******************/
			case PORTH:
			{
				GPIOH -> ODR &= ~(GPIO_1BIT_MASK << PinNum);
				GPIOH -> ODR |= ((PinVal << PinNum));
			}


			default: ErrorState = GPIO_InvalidPortName;

		}

	}

	else
	{
		ErrorState = GPIO_InvalidPinNum;
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
	GPIOErrorStates_t ErrorState = GPIO_Exit_OK;


	if ((PinNum >= 0) && (PinNum <= 15))
	{
		switch(Port)
		{

		/******************* PORTA *******************/
			case PORTA:
			{
				GPIOA -> ODR &= ~(GPIO_1BIT_MASK << PinNum);
				GPIOA -> ODR ^= ((1 << PinNum));
			}

		/******************* PORTB *******************/
			case PORTB:
			{
				GPIOB -> ODR &= ~(GPIO_1BIT_MASK << PinNum);
				GPIOB -> ODR ^= ((1 << PinNum));
			}

		/******************* PORTC *******************/
			case PORTC:
			{
				GPIOC -> ODR &= ~(GPIO_1BIT_MASK << PinNum);
				GPIOC -> ODR ^= ((1 << PinNum));
			}

		/******************* PORTD *******************/
			case PORTD:
			{
				GPIOD -> ODR &= ~(GPIO_1BIT_MASK << PinNum);
				GPIOD -> ODR ^= ((1 << PinNum));
			}

		/******************* PORTE *******************/
			case PORTE:
			{
				GPIOE -> ODR &= ~(GPIO_1BIT_MASK << PinNum);
				GPIOE -> ODR ^= ((1 << PinNum));
			}

		/******************* PORTF *******************/
			case PORTF:
			{
				GPIOF -> ODR &= ~(GPIO_1BIT_MASK << PinNum);
				GPIOF -> ODR ^= ((1 << PinNum));
			}

		/******************* PORTG *******************/
			case PORTG:
			{
				GPIOG -> ODR &= ~(GPIO_1BIT_MASK << PinNum);
				GPIOG -> ODR ^= ((1 << PinNum));
			}

		/******************* PORTH *******************/
			case PORTH:
			{
				GPIOH -> ODR &= ~(GPIO_1BIT_MASK << PinNum);
				GPIOH -> ODR ^= ((1 << PinNum));
			}


			default: ErrorState = GPIO_InvalidPortName;

		}

	}

	else
	{
		ErrorState = GPIO_InvalidPinNum;
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

	GPIOErrorStates_t ErrorState = GPIO_Exit_OK;


	if (PinVal != NULL)
	{
		if ((PinNum >= 0) && (PinNum <= 15))
		{
			switch(Port)
			{

			/******************* PORTA *******************/
				case PORTA:
				{
					*PinVal = GPIOA -> IDR & (1 >> PinNum);
				}

			/******************* PORTB *******************/
				case PORTB:
				{
					*PinVal = GPIOB -> IDR & (1 >> PinNum);
				}

		/******************* PORTC *******************/
				case PORTC:
				{
					*PinVal = GPIOC -> IDR & (1 >> PinNum);
				}

		/******************* PORTD *******************/
				case PORTD:
				{
					*PinVal = GPIOD -> IDR & (1 >> PinNum);
				}

		/******************* PORTE *******************/
				case PORTE:
				{
					*PinVal = GPIOE -> IDR & (1 >> PinNum);
				}

		/******************* PORTF *******************/
				case PORTF:
				{
					*PinVal = GPIOF -> IDR & (1 >> PinNum);
				}

		/******************* PORTG *******************/
				case PORTG:
				{
					*PinVal = GPIOG -> IDR & (1 >> PinNum);
				}

		/******************* PORTH *******************/
				case PORTH:
				{
					*PinVal = GPIOH -> IDR & (1 >> PinNum);
				}


				default: ErrorState = GPIO_InvalidPortName;

			}

		}

		else
		{
			ErrorState = GPIO_InvalidPinNum;
		}

	}

	else
	{
		ErrorState = GPIO_NullPtr;
	}


	return ErrorState;

}
