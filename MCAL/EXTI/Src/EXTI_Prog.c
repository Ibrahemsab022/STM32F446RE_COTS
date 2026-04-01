/***************************************************************************************************
 * @file: 			SYSCFG_Prog.c
 * @brief: 			This file contains the implementation for the SYSCFG peripheral
 * @author: 		Ibrahim Saber
 * @version: 		1.0
 * @date: 			24-03-2025
 * Last Update:     08:11 PM, Wednesday, April 1, 2026
 ****************************************************************************************************/
#include "stdint.h"

#include "Stm32F446xx.h"

#include "EXTI_Prv.h"
#include "EXTI_Interface.h"


/*
 *
 * @brief: Global array of ptrs to functions for call backs
 *
 * */
static void (* CallBack_FuncPtrs[INTERRUPT_LINES_NUM + 1])(void) = {NULL};





/**************************************************************************************************************
 * 	Decription:                 This Function is used to configure the EXTI line
 * 	Parameters:                 - EXTI_Configs_t *ExtIntConfigs: The address of a struct that contains the EXTI configs
 * 	Returns:                    - EXTI_ErorrStates_t: an enum indicating the error state of the function
 * 	Preconditions:              -  RCC must be configured and a system clk type is selected.
 * 								-  SYSCFG must be configured first
 * 	Side effects:               No side effects
 * 	Post Conditions:            The EXTI line is configured and ready to be used
 * 	Synch/Asynch:               Synch.
 * 	Reentrant/NonReenterant:    Non
 *************************************************************************************************************/
EXTI_ErrorStates_t EXTI_Init(EXTI_Configs_t *Copy_pExtIntConfigs)
{

	EXTI_ErrorStates_t	Local_u8ErrorState = EXTI_Exit_OK;

	if((Copy_pExtIntConfigs -> IntLine >= 0) && (Copy_pExtIntConfigs -> IntLine <= 15))
	{

		if(Copy_pExtIntConfigs != NULL)
		{

			/*edge Detection type setting*/
			switch(Copy_pExtIntConfigs -> TrigType)
			{
				case EXTI_RisingEdge:
				{
					EXTI -> RTSR |=  (1 << (Copy_pExtIntConfigs -> IntLine));
					EXTI -> FTSR &= ~(1 << (Copy_pExtIntConfigs -> IntLine));
					break;
				}

				case EXTI_FallingEdge:
				{
					EXTI -> RTSR &=  ~(1 << (Copy_pExtIntConfigs -> IntLine));
					EXTI -> FTSR |=   (1 << (Copy_pExtIntConfigs -> IntLine));
					break;
				}

				case EXTI_OnChange:
				{
					EXTI -> RTSR |=   (1 << (Copy_pExtIntConfigs -> IntLine));
					EXTI -> FTSR |=   (1 << (Copy_pExtIntConfigs -> IntLine));
					break;
				}

				default: Local_u8ErrorState = EXTI_InvalidEdgeType; break;

			}

			/*Interrupt initial state setting*/
			switch(Copy_pExtIntConfigs -> InitStat)
			{
				case EXTI_ENABLED:  EXTI -> IMR |=  (1 << (Copy_pExtIntConfigs -> IntLine)); break;
				case EXTI_DISABLED: EXTI -> IMR &= ~(1 << (Copy_pExtIntConfigs -> IntLine)); break;
				default: Local_u8ErrorState = EXTI_InvalidInitState; break;

			}




			/*call back func setting*/
			if((Copy_pExtIntConfigs -> callBackFunc) != NULL)
			{
				CallBack_FuncPtrs[(Copy_pExtIntConfigs -> IntLine)] = Copy_pExtIntConfigs -> callBackFunc;
			}

			else
			{
				Local_u8ErrorState = EXTI_NULL_Ptr_Err;
			}

		}

		else
		{
			Local_u8ErrorState = EXTI_NULL_Ptr_Err;
		}

	}

	else
	{
		Local_u8ErrorState = EXTI_InvalidLineNumber;
	}



	return Local_u8ErrorState;
}



/**************************************************************************************************************
 * 	Decription:                 This Function is used to enable the EXTI line
 * 	Parameters:                 - EXTI_ExtIntLine_t Copy_u8InterruptLine: The Interrupt line
 * 	Returns:                    - EXTI_ErorrStates_t: an enum indicating the error state of the function
 * 	Preconditions:              -  EXTI_Init() must be used to init the Interrupt line first.
 * 	Side effects:               No side effects
 * 	Post Conditions:            The EXTI line is enabled
 * 	Synch/Asynch:               Synch.
 * 	Reentrant/NonReenterant:    Non
 *************************************************************************************************************/
EXTI_ErrorStates_t EXTI_EnableInterrupt(EXTI_ExtIntLine_t Copy_u8InterruptLine)
{
	EXTI_ErrorStates_t	Local_u8ErrorState = EXTI_Exit_OK;

	if((Copy_u8InterruptLine >= 0) && (Copy_u8InterruptLine <= 15))
	{
		EXTI -> IMR |= (1 << Copy_u8InterruptLine);
	}

	else
	{
		Local_u8ErrorState = EXTI_InvalidLineNumber;
	}

	return Local_u8ErrorState;

}


/**************************************************************************************************************
 * 	Decription:                 This Function is used to disable the EXTI line
 * 	Parameters:                 - EXTI_ExtIntLine_t Copy_u8InterruptLine: The Interrupt line
 * 	Returns:                    - EXTI_ErorrStates_t: an enum indicating the error state of the function
 * 	Preconditions:              -  EXTI_Init() must be used to init the Interrupt line first.
 * 	Side effects:               No side effects
 * 	Post Conditions:            The EXTI line is Disabled
 * 	Synch/Asynch:               Synch.
 * 	Reentrant/NonReenterant:    Non
 *************************************************************************************************************/
EXTI_ErrorStates_t EXTI_DisableInterrupt(EXTI_ExtIntLine_t Copy_u8InterruptLine)
{
	EXTI_ErrorStates_t	Local_u8ErrorState = EXTI_Exit_OK;

	if((Copy_u8InterruptLine >= 0) && (Copy_u8InterruptLine <= 15))
	{
		EXTI -> IMR &= ~(1 << Copy_u8InterruptLine);
	}

	else
	{
		Local_u8ErrorState = EXTI_InvalidLineNumber;
	}

	return Local_u8ErrorState;

}


/**************************************************************************************************************
 * 	Decription:                 This Function is used to change the inital trig edge of an Interrupt
 * 	Parameters:                 - EXTI_ExtIntLine_t Copy_u8InterruptLine: The Interrupt line
 * 								- EXTI_TrigEdge_t Copy_u8TrigEdge: Rising, Falling or onChange
 * 	Returns:                    - EXTI_ErorrStates_t: an enum indicating the error state of the function
 * 	Preconditions:              -  EXTI_Init() must be used to init the Interrupt line first.
 * 	Side effects:               No side effects
 * 	Post Conditions:            The EXTI pending flag is cleared
 * 	Synch/Asynch:               Synch.
 * 	Reentrant/NonReenterant:    Non
 *************************************************************************************************************/
EXTI_ErrorStates_t EXTI_SetTrigEdge(EXTI_ExtIntLine_t Copy_u8InterruptLine, EXTI_TrigEdge_t Copy_u8TrigEdge)
{
	EXTI_ErrorStates_t	Local_u8ErrorState = EXTI_Exit_OK;

	if((Copy_u8InterruptLine >= 0) && (Copy_u8InterruptLine <= 15))
	{
		switch(Copy_u8TrigEdge)
		{
			case EXTI_RisingEdge:
			{
				EXTI -> RTSR |=  (1 << Copy_u8InterruptLine);
				EXTI -> FTSR &= ~(1 << Copy_u8InterruptLine);
				break;
			}

			case EXTI_FallingEdge:
			{
				EXTI -> RTSR &=  ~(1 << Copy_u8InterruptLine);
				EXTI -> FTSR |=   (1 << Copy_u8InterruptLine);
				break;
			}

			case EXTI_OnChange:
			{
				EXTI -> RTSR |=   (1 << Copy_u8InterruptLine);
				EXTI -> FTSR |=   (1 << Copy_u8InterruptLine);
				break;
			}

			default: Local_u8ErrorState = EXTI_InvalidEdgeType; break;

		}
	}

	else
	{
		Local_u8ErrorState = EXTI_InvalidLineNumber;
	}


	return Local_u8ErrorState;

}




/**************************************************************************************************************
 * 	Decription:                 This Function is used to change the inital trig edge of an Interrupt
 * 	Parameters:                 - EXTI_ExtIntLine_t Copy_u8InterruptLine: The Interrupt line
 * 								- void (*Copy_pcallBackFunc)(void): ptr to the callback func
 * 	Returns:                    - EXTI_ErorrStates_t: an enum indicating the error state of the function
 * 	Preconditions:              -  EXTI_Init() must be used to init the Interrupt line first.
 * 	Side effects:               No side effects
 * 	Post Conditions:            The EXTI pending flag is cleared
 * 	Synch/Asynch:               Synch.
 * 	Reentrant/NonReenterant:    Non
 *************************************************************************************************************/
EXTI_ErrorStates_t EXTI_SetCallBackFunc(EXTI_ExtIntLine_t Copy_u8InterruptLine, void (*Copy_pcallBackFunc)(void))
{

	EXTI_ErrorStates_t Local_u8ErrorState = EXTI_Exit_OK;

	if((Copy_u8InterruptLine >= 0) && (Copy_u8InterruptLine <= 15))
	{
		if(Copy_pcallBackFunc != NULL)
		{
			CallBack_FuncPtrs[Copy_u8InterruptLine] = Copy_pcallBackFunc;
		}

		else
		{
			Local_u8ErrorState = EXTI_NULL_Ptr_Err;
		}

	}

	else
	{
		Local_u8ErrorState = EXTI_InvalidLineNumber;
	}




	return Local_u8ErrorState;

}




/**************************************************************************************************************
 * 	Decription:                 This Function is used to clear the EXTI pending flag
 * 	Parameters:                 - EXTI_ExtIntLine_t Copy_u8InterruptLine: The Interrupt line
 * 	Returns:                    - EXTI_ErorrStates_t: an enum indicating the error state of the function
 * 	Preconditions:              -  EXTI_Init() must be used to init the Interrupt line first.
 * 	Side effects:               No side effects
 * 	Post Conditions:            The EXTI pending flag is cleared
 * 	Synch/Asynch:               Synch.
 * 	Reentrant/NonReenterant:    Non
 *************************************************************************************************************/
EXTI_ErrorStates_t EXTI_ClearPendingFlag(EXTI_ExtIntLine_t Copy_u8InterruptLine)
{
	EXTI_ErrorStates_t	Local_u8ErrorState = EXTI_Exit_OK;

	if((Copy_u8InterruptLine >= 0) && (Copy_u8InterruptLine <= 15))
	{
		EXTI -> PR = 1 << Copy_u8InterruptLine;
	}

	else
	{
		Local_u8ErrorState = EXTI_InvalidLineNumber;
	}

	return Local_u8ErrorState;

}


/**************************************************************************************************************
 * 	Description:                 This Function is used to clear the EXTI pending flag
 * 	Parameters:                 - EXTI_ExtIntLine_t Copy_u8InterruptLine: The Interrupt line
 * 								- uint8_t* Copy_pPendingFlagState: a ptr to unit8_t variable that will be derfernced with the flag state
 * 	Returns:                    - EXTI_ErorrStates_t: an enum indicating the error state of the function
 * 	Preconditions:              -  EXTI_Init() must be used to init the Interrupt line first.
 * 	Side effects:               No side effects
 * 	Post Conditions:            The EXTI pending flag state is retrieved
 * 	Synch/Asynch:               Synch.
 * 	Reentrant/NonReenterant:    Non
 *************************************************************************************************************/
EXTI_ErrorStates_t EXTI_ReadPendingFlag(EXTI_ExtIntLine_t Copy_u8InterruptLine, uint8_t* Copy_pPendingFlagState)
{
	EXTI_ErrorStates_t	Local_u8ErrorState = EXTI_Exit_OK;

	if((Copy_u8InterruptLine >= 0) && (Copy_u8InterruptLine <= 15))
	{
		if(Copy_pPendingFlagState != NULL)
		{
			*Copy_pPendingFlagState = (1 & ((EXTI -> PR) >> Copy_u8InterruptLine));
		}

		else
		{
			Local_u8ErrorState = EXTI_NULL_Ptr_Err;
		}
	}

	else
	{
		Local_u8ErrorState = EXTI_InvalidLineNumber;
	}

	return Local_u8ErrorState;
}





/*
 *
 * @brief: Imblementing the IRQs
 *
 * */
void EXTI0_IRQHandler()
{
	/*clearing the pending flag*/
	EXTI -> PR = (1 << EXTI0);

	/*Invoking the callback func*/
	CallBack_FuncPtrs[EXTI0]();


}



void EXTI1_IRQHandler()
{
	/*clearing the pending flag*/
	EXTI->PR = (1 << EXTI1);

	/*Invoking the callback func*/
	CallBack_FuncPtrs[EXTI1]();


}



void EXTI2_IRQHandler()
{
	/*clearing the pending flag*/
	EXTI->PR = (1 << EXTI2);

	/*Invoking the callback func*/
	CallBack_FuncPtrs[EXTI2]();


}



void EXTI3_IRQHandler()
{
	/*clearing the pending flag*/
	EXTI->PR = (1 << EXTI3);

	/*Invoking the callback func*/
	CallBack_FuncPtrs[EXTI3]();


}



void EXTI4_IRQHandler()
{
	/*clearing the pending flag*/
	EXTI->PR = (1 << EXTI4);

	/*Invoking the callback func*/
	CallBack_FuncPtrs[EXTI4]();


}



void EXTI9_5_IRQHandler()
{
	if(EXTI5_FLAG == FLAG_RAISED)
	{
		/*clearing the pending flag*/
		EXTI->PR = (1 << EXTI5);

		/*Invoking the callback func*/
		CallBack_FuncPtrs[EXTI5]();
	}

	if(EXTI6_FLAG == FLAG_RAISED)
	{

		EXTI->PR = (1 << EXTI6);
		CallBack_FuncPtrs[EXTI6]();
	}

	if(EXTI7_FLAG == FLAG_RAISED)
	{

		EXTI->PR = (1 << EXTI7);
		CallBack_FuncPtrs[EXTI7]();
	}

	if(EXTI8_FLAG == FLAG_RAISED)
	{

		EXTI->PR = (1 << EXTI8);
		CallBack_FuncPtrs[EXTI8]();
	}

	if(EXTI9_FLAG == FLAG_RAISED)
	{
		EXTI->PR = (1 << EXTI9);
    	CallBack_FuncPtrs[EXTI9]();
    }
}



void EXTI15_10_IRQHandler()
{
	if(EXTI10_FLAG == FLAG_RAISED)
	{
		/*clearing the pending flag*/
		EXTI->PR = (1 << EXTI10);

		/*Invoking the callback func*/
		CallBack_FuncPtrs[EXTI10]();
	}

	if(EXTI11_FLAG == FLAG_RAISED)
	{

		EXTI->PR = (1 << EXTI11);
		CallBack_FuncPtrs[EXTI11]();
	}

	if(EXTI12_FLAG == FLAG_RAISED)
	{

		EXTI->PR = (1 << EXTI12);
		CallBack_FuncPtrs[EXTI12]();
	}

	if(EXTI13_FLAG == FLAG_RAISED)
	{

		EXTI->PR = (1 << EXTI13);
		CallBack_FuncPtrs[EXTI13]();
	}

	if(EXTI14_FLAG == FLAG_RAISED)
	{
		EXTI->PR = (1 << EXTI14);
    	CallBack_FuncPtrs[EXTI14]();
    }

	if(EXTI15_FLAG == FLAG_RAISED)
	{
		EXTI->PR = (1 << EXTI15);
		CallBack_FuncPtrs[EXTI15]();
	}
}



void PVD_IRQHandler()
{

}



void TAMP_STAMP_IRQHandler()
{

}

void RTC_WKUP_IRQHandler()
{

}




