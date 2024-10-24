/*****************************************************
 * file: RCC_Program.c
 * brief: This file contains the implementation of RCC Peripheral functions
 * author: Ibrahim Saber
 * version: 1.0
 * date: 24-03-2024
 ****************************************************/

#include "stdint.h"

#include "Stm32F446xx.h"

#include "RCC_Private.h"
#include "RCC_Interface.h"



/***************************************************************************************************
 * 	Decription: This Function is used to set the status of the different clk sources
 * 	Parameters: - clockTypes_t type: expecting an enum indicating wether it's HSI, HSE, PLL,PLL_R, PLLI2S or PLLSAI.
 * 				- clockStatus_t status: expecting an enum indicating wether it's On or off
 * 	Returns: RCC_ErrorStates_t
 * 	Preconditions: -
 * 				   -
 * 	Side effects: No side effects
 * 	Post Conditions: a clk source state is indicated succesfully
 * 	Synch/Asynch: Synch.
 * 	Reentrant/NonReenterant: Non
 ***************************************************************************************************/
RCC_ErrorStates_t RCC_SetClkStatus(clockTypes_t type, clockStatus_t status)
{
	RCC_ErrorStates_t ErrorState = OK;
	uint32_t TimeOutCounter = 0;

	switch(status)
	{
		case ON:
		{
			switch(type)
			{
				case HSE:
				{
					/*setting HSEON bit: CR_bit16*/
					RCC -> CR |= (uint32_t)(1 << HSE_ON);

					/*wait on HSERDY flag: CR_bit17*/
					while ((!(1 & (RCC->CR >> HSE_RDY))) && !(TimeOutCounter > TIME_OUT))
					{
						TimeOutCounter++;
					}

					break;
				}

				case HSI:
				{
					/*setting HSION bit: CR_bit0*/
					RCC -> CR |= (uint32_t)(HSI_ON);

					/*wait on HSIRDY flag: CR_bit1*/
					while((!(1 & (RCC -> CR >> HSI_RDY))) && !(TimeOutCounter > TIME_OUT))
					{
						TimeOutCounter++;
					}

					break;
				}

				case PLLP:
				{
					/*setting PLLON bit: CR_bit24*/
					RCC -> CR |= (uint32_t)(1 << PLL_ON);

					/*wait on PLLRDY flag: CR_bit25*/
					while((!(1 & (RCC -> CR >> PLL_RDY))) && !(TimeOutCounter > TIME_OUT))
					{
						TimeOutCounter++;
					}

					break;
				}

				case PLLI2S:
				{
					/*setting PLLON bit: CR_bit26*/
					RCC -> CR |= (uint32_t)(1 << PLLI2S_ON);

					/*wait on PLLRDY flag: CR_bit27*/
					while((!(1 & (RCC -> CR >> PLLI2S_RDY))) && !(TimeOutCounter > TIME_OUT))
					{
						TimeOutCounter++;
					}

					break;
				}

				case PLLSAI:
				{
					/*setting PLLON bit: CR_bit28*/
					RCC -> CR |= (uint32_t)(1 << PLLSAI_ON);

					/*wait on PLLRDY flag: CR_bit29*/
					while((!(1 & (RCC -> CR >> PLLSAI_RDY))) && !(TimeOutCounter > TIME_OUT))
					{
						TimeOutCounter++;
					}

					break;
				}

				default: ErrorState = WRONG_CLK_SRC_INPUT;
			}

			break;
		}


		case OFF:
		{
			switch(type)
			{
				case HSE:
				{

					if(((RCC -> CFGR & ((uint32_t)CFGR_SW_BITS_MASK)) != HSE) || ((RCC -> CFGR & ((uint32_t)CFGR_SWS_BITS_MASK)) != HSE)) /*12 here means 0b00001100: bits3:2*/

					{
						/*Resetting HSEON bit: CR_bit16*/
						RCC -> CR &= (uint32_t)(~(1 << HSE_ON));
					}

					else
					{
						ErrorState = SWITCHING_OFF_SELECTED_CLK;
					}

					break;
				}


				case HSI:
				{
					if(((RCC -> CFGR & ((uint32_t)CFGR_SW_BITS_MASK)) != HSI) || ((RCC -> CFGR & ((uint32_t)CFGR_SWS_BITS_MASK)) != HSI)) /*12 here means 0b00001100: bits3:2*/

					{
						/*Resetting HSION bit: CR_bit0*/
						RCC -> CR &= HSI_ON;
					}

					else
					{
						ErrorState = SWITCHING_OFF_SELECTED_CLK;
					}

					break;
				}

				case PLLP:
				{
					/*you can't turn off a clk which is selected as a sysClk. Note that: PLLR is dependent on PLLP and can be selected As sysClk so must be included in the corner case*/
					if(((RCC -> CFGR & ((uint32_t)CFGR_SW_BITS_MASK)) != PLLP) || ((RCC -> CFGR & ((uint32_t)CFGR_SWS_BITS_MASK)) != PLLP) ||
					  ((RCC -> CFGR & ((uint32_t)CFGR_SW_BITS_MASK)) != PLL_R) || ((RCC -> CFGR & ((uint32_t)CFGR_SWS_BITS_MASK)) != PLL_R)) /*12 here means 0b00001100: bits3:2*/
					{
						/*Resetting PLLON bit: CR_bit24*/
						RCC -> CR &= (uint32_t)(~(1 << PLL_ON));
					}

					else
					{
						ErrorState = SWITCHING_OFF_SELECTED_CLK;
					}

					break;
				}


				case PLLI2S:
				{

					/*Resetting PLLI2SON bit: CR_bit26*/
					RCC -> CR &= (uint32_t)(~(1 << PLLI2S_ON));

					break;
				}

				case PLLSAI:
				{

					/*Resetting PLLSAION bit: CR_bit28*/
					RCC -> CR &= (uint32_t)(~(1 << PLLSAI_ON));

					break;
				}

				default: ErrorState = WRONG_CLK_SRC_INPUT;

			}
		}
	}



	if (TimeOutCounter > TIME_OUT)
	{
		ErrorState = TIME_OUT_EXCEEDED;
	}


	return ErrorState;

}




/***************************************************************************************************
 * 	Decription: This Function is used to set the sys clk to a given clk source
 * 	Parameters: - clockTypes_t type: expecting an enum indicating wether it's HSI, HSE, PLL or PLL_R
 * 	Returns: void
 * 	Preconditions: - The Source clk is off while switching
 * 				   -
 * 	Side effects: No side effects
 * 	Post Conditions: Sys clk is set succesfully
 * 	Synch/Asynch: Synch.
 * 	Reentrant/NonReenterant: Non
 ***************************************************************************************************/
void RCC_SetSysClk(clockTypes_t type)
{
	RCC -> CFGR &= ~(CFGR_SW_BITS_MASK);
	RCC -> CFGR |= type;
}




/****************************************************************************************************
 * 	Decription: This Function is used to configure the PLL clk
 * 	Parameters: - PLL_CFG_t *PLL_CfgStructPtr:a ptr to sutruct containing the configs
 * 	Returns: void
 * 	Preconditions: - PLL & PLLI2S are disabled
 * 				   -
 * 	Side effects: No side effects
 * 	Post Conditions:PLL is configured succesfully
 * 	Synch/Asynch: Synch.
 * 	Reentrant/NonReenterant: Non
 ***************************************************************************************************/
RCC_ErrorStates_t RCC_PLLCongfig(PLL_CFG_t *PLL_CfgStructPtr)
{

	RCC_ErrorStates_t ErrorState = OK;
	uint8_t VCOinputFrequency;
	uint16_t VCOoutputFrequency;
	uint8_t PLLoutputFrequency;
	uint8_t PLLQoutFrequency;


	/*Make sure PLLON bit in CR reg is 0; PLL is disabled*/
		if((1 & (RCC -> CR >> PLL_ON)) == 0)
		{
			/*Putting the value of the source clk to PLLSRC bit in CFGR Reg*/
			RCC -> PLLCFGR &= ~(1 << PLLSRC);
			RCC -> PLLCFGR |= ((PLL_CfgStructPtr -> PLL_Src) << PLLSRC);

			/*Factors calculations and checkups*/


			/*first check whether the input is HSI/HSE and calc the VCOin accordingly*/
			/*HSI: input frequency = 16 MHz*/
			if(((RCC -> CFGR & ((uint32_t)CFGR_SW_BITS_MASK)) == HSI) || ((RCC -> CFGR & ((uint32_t)CFGR_SWS_BITS_MASK)) == HSI))
			{
				VCOinputFrequency = (float)16 / PLL_CfgStructPtr -> M_Factor;
			}

			/*HSE: input frequency = value in the ConfigStruct MHz*/
			else if (((RCC -> CFGR & ((uint32_t)CFGR_SW_BITS_MASK)) == HSE) || ((RCC -> CFGR & ((uint32_t)CFGR_SWS_BITS_MASK)) == HSE))
			{
				VCOinputFrequency = (PLL_CfgStructPtr -> HSE_Input_Freq) / PLL_CfgStructPtr -> M_Factor;
			}

			/*Calculate VCOout to use it for comparison later*/
			VCOoutputFrequency = VCOinputFrequency * (PLL_CfgStructPtr -> N_Factor);


			/*Check the validity of the selected factors according to datasheet*/

			/*M-Factor Check*/
			if(((PLL_CfgStructPtr -> M_Factor) >= 2) && ((PLL_CfgStructPtr -> M_Factor) <= 63))
			{
				if ((VCOinputFrequency >= 1) && (VCOinputFrequency <= 2))
				{
					/*Putting the value of the Multiplication factor into PLLCFGR Reg*/
					RCC -> PLLCFGR &= ~(uint32_t)(CFGR_PLL_M_FACTOR_BITS_MASK << PLLM0);
					RCC -> PLLCFGR |= (uint32_t)((PLL_CfgStructPtr -> M_Factor) << PLLM0);
				}

				else
				{
					/*output frequency is out of the recommended range, M factor need to be adjusted*/
					ErrorState = WRONG_PLLM_CONFIGURATION;
				}

			}

			/*N-Factor Check*/
			if(((PLL_CfgStructPtr -> N_Factor) >= 50) && ((PLL_CfgStructPtr -> N_Factor) <= 432))
			{
				if ((VCOoutputFrequency >= 100) && (VCOoutputFrequency <= 432))
				{
					/*Putting the value of the Multiplication factor into PLLCFGR Reg*/
					RCC -> PLLCFGR &= ~(uint32_t)(CFGR_PLL_N_FACTOR_BITS_MASK << PLLN0);
					RCC -> PLLCFGR |= (uint32_t)((PLL_CfgStructPtr -> N_Factor) << PLLN0);
				}

				else
				{
					/*output frequency is out of the recommended range, N factor need to be adjusted*/
					ErrorState = WRONG_PLLN_CONFIGURATION;
				}

			}

			else
			{
				ErrorState = WRONG_PLLN_CONFIGURATION;
			}


			/*Calculate PLLout to use it for comparison later*/
			PLLoutputFrequency = VCOoutputFrequency / (PLL_CfgStructPtr -> P_Factor);


			/*P-Factor Check*/
			if(((PLL_CfgStructPtr -> P_Factor) >= 2) && ((PLL_CfgStructPtr -> P_Factor) <= 8))
			{
				if (PLLoutputFrequency <= 180)
				{
					/*Putting the value of the Division factor into PLLCFGR Reg*/
					RCC -> PLLCFGR &= ~(uint32_t)(CFGR_PLL_P_FACTOR_BITS_MASK << PLLP0);
					RCC -> PLLCFGR |= (uint32_t)((PLL_CfgStructPtr -> P_Factor) << PLLP0);
				}

				else
				{
					/*output frequency is out of the recommended range, P factor need to be adjusted*/
					ErrorState = WRONG_PLLP_CONFIGURATION;
				}
			}

			else
			{
				ErrorState = WRONG_PLLP_CONFIGURATION;
			}

			/*Calculate PLLout to use it for comparison later*/
			PLLQoutFrequency = VCOoutputFrequency / (PLL_CfgStructPtr -> Q_Factor);


			/*Q-Factor Check*/
			if(((PLL_CfgStructPtr -> Q_Factor) >= 2) && ((PLL_CfgStructPtr -> Q_Factor) <= 15))
			{
				if (PLLQoutFrequency <= 48)
				{
					/*Putting the value of the Division factor into PLLCFGR Reg*/
					RCC -> PLLCFGR &= ~(uint32_t)(CFGR_PLL_Q_FACTOR_BITS_MASK << PLLQ0);
					RCC -> PLLCFGR |= (uint32_t)((PLL_CfgStructPtr -> Q_Factor) << PLLQ0);
				}

				else
				{
					/*output frequency is out of the recommended range, Q factor need to be adjusted*/
					ErrorState = WRONG_PLLQ_CONFIGURATION;
				}

			}

			else
			{
				ErrorState = WRONG_PLLQ_CONFIGURATION;
			}



			/*R-Factor Check*/
				if(((PLL_CfgStructPtr -> R_Factor) >= 2) && ((PLL_CfgStructPtr -> R_Factor) <= 7))
				{

						/*Putting the value of the Division factor into PLLCFGR Reg*/
						RCC -> PLLCFGR &= ~(uint32_t)(CFGR_PLL_R_FACTOR_BITS_MASK << PLLR0);
						RCC -> PLLCFGR |= (uint32_t)((PLL_CfgStructPtr -> R_Factor) << PLLR0);

				}

				else
				{
					/*output frequency is out of the recommended range, Q factor need to be adjusted*/
					ErrorState = WRONG_PLLR_CONFIGURATION;
				}


		}




		else
		{
			ErrorState = CONFIGING_PLL_WHILE_ON;
		}




	return ErrorState;

}





/****************************************************************************************************
 * 	Decription: This Function is used to enable the clk for given peripheral on the AHB bus
 * 	Parameters: - AHB1_Peripheral_t Peripheral: an enum value indicating the required peripheral
 * 	Returns: void
 * 	Preconditions: -
 * 				   -
 * 	Side effects: No side effects
 * 	Post Conditions: a peripheral is enabled succesfully
 * 	Synch/Asynch: Synch.
 * 	Reentrant/NonReenterant: Non
 ***************************************************************************************************/
void RCC_AHB1EnableClk(AHB1_Peripheral_t Peripheral)
{
	RCC -> AHB1ENR &= (uint32_t)~(1 << Peripheral);
	RCC -> AHB1ENR |= (uint32_t)(1 << Peripheral);
}





/****************************************************************************************************
 * 	Decription: This Function is used to enable the clk for given peripheral on the AHB bus
 * 	Parameters: - AHB2_Peripheral_t Peripheral: an enum value indicating the required peripheral
 * 	Returns: void
 * 	Preconditions: -
 * 				   -
 * 	Side effects: No side effects
 * 	Post Conditions: a peripheral is enabled succesfully
 * 	Synch/Asynch: Synch.
 * 	Reentrant/NonReenterant: Non
 ***************************************************************************************************/
void RCC_AHB2EnableClk(AHB2_Peripheral_t Peripheral)
{
	RCC -> AHB2ENR &= (uint32_t)~(1 << Peripheral);
	RCC -> AHB2ENR |= (uint32_t)(1 << Peripheral);
}


/****************************************************************************************************
 * 	Decription: This Function is used to enable the clk for given peripheral on the AHB bus
 * 	Parameters: - AHB3_Peripheral_t Peripheral: an enum value indicating the required peripheral
 * 	Returns: void
 * 	Preconditions: -
 * 				   -
 * 	Side effects: No side effects
 * 	Post Conditions: a peripheral is enabled succesfully
 * 	Synch/Asynch: Synch.
 * 	Reentrant/NonReenterant: Non
 ***************************************************************************************************/
void RCC_AHB3EnableClk(AHB3_Peripheral_t Peripheral)
{
	RCC -> AHB3ENR &= (uint32_t)~(1 << Peripheral);
	RCC -> AHB3ENR |= (uint32_t)(1 << Peripheral);
}




/****************************************************************************************************
 * 	Decription: This Function is used to disable the clk for given peripheral on the AHB bus
 * 	Parameters: - AHB1_Peripheral_t Peripheral: an enum value indicating the required peripheral
 * 	Returns: void
 * 	Preconditions: -
 * 				   -
 * 	Side effects: No side effects
 * 	Post Conditions: a peripheral is disabled succesfully
 * 	Synch/Asynch: Synch.
 * 	Reentrant/NonReenterant: Non
 ***************************************************************************************************/
void RCC_AHB1DisableClk(AHB1_Peripheral_t Peripheral)
{
	RCC -> AHB1ENR &= (uint32_t)~(1 << Peripheral);
}



/****************************************************************************************************
 * 	Decription: This Function is used to disable the clk for given peripheral on the AHB bus
 * 	Parameters: - AHB2_Peripheral_t Peripheral: an enum value indicating the required peripheral
 * 	Returns: void
 * 	Preconditions: -
 * 				   -
 * 	Side effects: No side effects
 * 	Post Conditions: a peripheral is disabled succesfully
 * 	Synch/Asynch: Synch.
 * 	Reentrant/NonReenterant: Non
 ***************************************************************************************************/
void RCC_AHB2DisableClk(AHB2_Peripheral_t Peripheral)
{

	RCC -> AHB2ENR &= (uint32_t)~(1 << Peripheral);

}



/****************************************************************************************************
 * 	Decription: This Function is used to disable the clk for given peripheral on the AHB bus
 * 	Parameters: - AHB3_Peripheral_t Peripheral: an enum value indicating the required peripheral
 * 	Returns: void
 * 	Preconditions: -
 * 				   -
 * 	Side effects: No side effects
 * 	Post Conditions: a peripheral is disabled succesfully
 * 	Synch/Asynch: Synch.
 * 	Reentrant/NonReenterant: Non
 ***************************************************************************************************/
void RCC_AHB3DisableClk(AHB3_Peripheral_t Peripheral)
{
	RCC -> AHB3ENR &= (uint32_t)~(1 << Peripheral);
}




/****************************************************************************************************
 * 	Decription: This Function is used to enable the clk for given peripheral on the APB2 bus
 * 	Parameters: - APB2_Peripheral_t Peripheral: an enum value indicating the required peripheral
 * 	Returns: void
 * 	Preconditions: -
 * 				   -
 * 	Side effects: No side effects
 * 	Post Conditions: a peripheral is enabled succesfully
 * 	Synch/Asynch: Synch.
 * 	Reentrant/NonReenterant: Non
 ***************************************************************************************************/
void RCC_APB2EnableClk(APB2_Peripheral_t Peripheral)
{
	RCC -> APB2ENR &= (uint32_t)~(1 << Peripheral);
	RCC -> APB2ENR |= (uint32_t)(1 << Peripheral);
}



/****************************************************************************************************
 * 	Decription: This Function is used to disable the clk for given peripheral on the APB2 bus
 * 	Parameters: - APB2_Peripheral_t Peripheral: an enum value indicating the required peripheral
 * 	Returns: void
 * 	Preconditions: -
 * 				   -
 * 	Side effects: No side effects
 * 	Post Conditions: a peripheral is disabled succesfully
 * 	Synch/Asynch: Synch.
 * 	Reentrant/NonReenterant: Non
 ***************************************************************************************************/
void RCC_APB2DisableClk(APB2_Peripheral_t Peripheral)
{
	RCC -> APB2ENR &= (uint32_t)~(1 << Peripheral);
}



/****************************************************************************************************
 * 	Decription: This Function is used to enable the clk for given peripheral on the APB1 bus
 * 	Parameters: - APB1_Peripheral_t Peripheral: an enum value indicating the required peripheral
 * 	Returns: void
 * 	Preconditions: -
 * 				   -
 * 	Side effects: No side effects
 * 	Post Conditions: a peripheral is enabled succesfully
 * 	Synch/Asynch: Synch.
 * 	Reentrant/NonReenterant: Non
 ***************************************************************************************************/
void RCC_APB1EnableClk(APB1_Peripheral_t Peripheral)
{
	RCC -> APB1ENR &= (uint32_t)~(1 << Peripheral);
	RCC -> APB1ENR |= (uint32_t)(1 << Peripheral);
}



/****************************************************************************************************
 * 	Decription: This Function is used to disable the clk for given peripheral on the APB1 bus
 * 	Parameters: - APB1_Peripheral_t Peripheral: an enum value indicating the required peripheral
 * 	Returns: void
 * 	Preconditions: -
 * 				   -
 * 	Side effects: No side effects
 * 	Post Conditions: a peripheral is disabled succesfully
 * 	Synch/Asynch: Synch.
 * 	Reentrant/NonReenterant: Non
 ***************************************************************************************************/
void RCC_APB1DisableClk(APB1_Peripheral_t Peripheral)
{
	RCC -> APB1ENR &= (uint32_t)~(1 << Peripheral);
}



