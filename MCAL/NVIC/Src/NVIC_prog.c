/***************************************************************************************************
 * @file  	NVIC_Prog.c
 * @brief 	This file contains the function implementation of the NVIC Driver
 * @author 	Ibrahim Saber
 * @version 1.0
 * @date 	09 - 2 -2025
 ***************************************************************************************************/
#include <stdint.h>

#include "Stm32F446xx.h"

#include "NVIC_Prv.h"
#include "NVIC_Interface.h"


/****************************************************************************************************
 * 	@brief		 This Function is used to enable the interrupt of a given source.
 * 	@param 		 NVIC_IRQs_t Copy_u8IRQNum: an enum value that holds the IRQ number(position) from the vector table.
 * 	@return 	 NVIC_ErrorState_t: return errorState
 * 	@pre		 None

 * 	@post 		 Interrupt is enabled for this src
 * 	Synch/Asynch: Synch.
 * 	Reentrant/NonReenterant: Re
 ***************************************************************************************************/
NVIC_ErrorState_t NVIC_EnableIRQ(NVIC_IRQs_t Copy_u8IRQNum)
{

	NVIC_ErrorState_t Local_u8ErrorStates = NVIVC_Exit_Ok;

	if((Copy_u8IRQNum >= MASKABLE_EXCEPTIONS_START) && (Copy_u8IRQNum <= MASKABLE_EXCEPTIONS_END))
	{
		uint8_t Local_u8RegNum = Copy_u8IRQNum / NVIC_REGISTERS_SIZE;
		uint8_t Local_u8BitNum = Copy_u8IRQNum % NVIC_REGISTERS_SIZE;

		(NVIC -> ISER[Local_u8RegNum]) = 1 << Local_u8BitNum;

	}

	else
	{
		Local_u8ErrorStates = NVIC_Invalid_IRQ;
	}

	return Local_u8ErrorStates;
}



/****************************************************************************************************
 * 	@brief		 This Function is used to disable the interrupt of a given source.
 * 	@param 		 NVIC_IRQs_t Copy_u8IRQNum: an enum value that holds the IRQ number(position) from the vector table.
 * 	@return 	 NVIC_ErrorState_t: return errorState
 * 	@pre		 None

 * 	@post 		 Interrupt is enabled for this src
 * 	Synch/Asynch: Synch.
 * 	Reentrant/NonReenterant: Re
 ***************************************************************************************************/
NVIC_ErrorState_t NVIC_DisableIRQ(NVIC_IRQs_t Copy_u8IRQNum)
{

	NVIC_ErrorState_t Local_u8ErrorStates = NVIVC_Exit_Ok;

	if((Copy_u8IRQNum >= MASKABLE_EXCEPTIONS_START) && (Copy_u8IRQNum <= MASKABLE_EXCEPTIONS_END))
	{
		uint8_t Local_u8RegNum = Copy_u8IRQNum / NVIC_REGISTERS_SIZE;
		uint8_t Local_u8BitNum = Copy_u8IRQNum % NVIC_REGISTERS_SIZE;

		(NVIC -> ICER[Local_u8RegNum]) = 1 << Local_u8BitNum;


	}

	else
	{
		Local_u8ErrorStates = NVIC_Invalid_IRQ;
	}

	return Local_u8ErrorStates;

}




/****************************************************************************************************
 * 	@brief		 This Function is used to set the priority of the interrupt of a given source.
 * 	@param 		 NVIC_IRQs_t Copy_u8IRQNum: an enum value that holds the IRQ number(position) from the vector table.
 * 	@return 	 NVIC_ErrorState_t: return errorState
 * 	@pre		 perfable SCB_SetPriGroup is used to set the config type of this priority(group vs sub)

 * 	@post 		 Interrupt priority is set for this src
 * 	Synch/Asynch: Synch.
 * 	Reentrant/NonReenterant: Re
 ***************************************************************************************************/
NVIC_ErrorState_t NVIC_SetPriority(NVIC_IRQs_t Copy_u8IRQNum, uint8_t Copy_u8Priority)
{

	NVIC_ErrorState_t Local_u8ErrorStates = NVIVC_Exit_Ok;

	if((Copy_u8IRQNum >= MASKABLE_EXCEPTIONS_START) && (Copy_u8IRQNum <= MASKABLE_EXCEPTIONS_END))
	{

		if((Copy_u8Priority >= 0) && (Copy_u8Priority <= 15))
		{
			(NVIC -> IPR[Copy_u8IRQNum]) = Copy_u8Priority << 4;

		}

		else
		{
			Local_u8ErrorStates = NVIC_Invalid_Priority;
		}



	}

	else
	{
		Local_u8ErrorStates = NVIC_Invalid_IRQ;
	}

	return Local_u8ErrorStates;

}





/****************************************************************************************************
 * 	@brief		 This Function is used to set the pending flag of a given source.
 * 	@param 		 NVIC_IRQs_t Copy_u8IRQNum: an enum value that holds the IRQ number(position) from the vector table.
 * 	@return 	 NVIC_ErrorState_t: return errorState
 * 	@pre		 None

 * 	@post 		 pending flag is enabled for this src
 * 	Synch/Asynch: Synch.
 * 	Reentrant/NonReenterant: Re
 ***************************************************************************************************/
NVIC_ErrorState_t NVIC_SetPendingFlag(NVIC_IRQs_t Copy_u8IRQNum)
{

	NVIC_ErrorState_t Local_u8ErrorStates = NVIVC_Exit_Ok;

	if((Copy_u8IRQNum >= MASKABLE_EXCEPTIONS_START) && (Copy_u8IRQNum <= MASKABLE_EXCEPTIONS_END))
	{
		uint8_t Local_u8RegNum = Copy_u8IRQNum / NVIC_REGISTERS_SIZE;
		uint8_t Local_u8BitNum = Copy_u8IRQNum % NVIC_REGISTERS_SIZE;

		(NVIC -> ISPR[Local_u8RegNum]) = 1 << Local_u8BitNum;

	}

	else
	{
		Local_u8ErrorStates = NVIC_Invalid_IRQ;
	}

	return Local_u8ErrorStates;

}



/****************************************************************************************************
 * 	@brief		 This Function is used to clear the pending flag of a given source.
 * 	@param 		 NVIC_IRQs_t Copy_u8IRQNum: an enum value that holds the IRQ number(position) from the vector table.
 * 	@return 	 NVIC_ErrorState_t: return errorState
 * 	@pre		 None

 * 	@post 		 pending flag is enabled for this src
 * 	Synch/Asynch: Synch.
 * 	Reentrant/NonReenterant: Re
 ***************************************************************************************************/
NVIC_ErrorState_t NVIC_ClearPendingFlag(NVIC_IRQs_t Copy_u8IRQNum)
{

	NVIC_ErrorState_t Local_u8ErrorStates = NVIVC_Exit_Ok;

	if((Copy_u8IRQNum >= MASKABLE_EXCEPTIONS_START) && (Copy_u8IRQNum <= MASKABLE_EXCEPTIONS_END))
	{
		uint8_t Local_u8RegNum = Copy_u8IRQNum / NVIC_REGISTERS_SIZE;
		uint8_t Local_u8BitNum = Copy_u8IRQNum % NVIC_REGISTERS_SIZE;

		(NVIC -> ICPR[Local_u8RegNum]) = 1 << Local_u8BitNum;


	}

	else
	{
		Local_u8ErrorStates = NVIC_Invalid_IRQ;
	}

	return Local_u8ErrorStates;

}



/****************************************************************************************************
 * 	@brief		 This Function is used to get the active flag status of a given source.
 * 	@param 		 NVIC_IRQs_t Copy_u8IRQNum: 			an enum value that holds the IRQ number(position) from the vector table.
 * 				 NVIC_ActvFlag_t* Copy_u8ActvFlgStat:	used to store the status.
 * 	@return 	 NVIC_ErrorState_t: return errorState
 * 	@pre		 None

 * 	@post 		 pending flag is enabled for this src
 * 	Synch/Asynch: Synch.
 * 	Reentrant/NonReenterant: Re
 ***************************************************************************************************/
NVIC_ErrorState_t NVIC_GetActiveFlag(NVIC_IRQs_t Copy_u8IRQNum, NVIC_ActvFlag_t* Copy_u8ActvFlgStat)
{


	NVIC_ErrorState_t Local_u8ErrorStates = NVIVC_Exit_Ok;

	if(Copy_u8ActvFlgStat != NULL)
	{

		if((Copy_u8IRQNum >= MASKABLE_EXCEPTIONS_START) && (Copy_u8IRQNum <= MASKABLE_EXCEPTIONS_END))
		{
			uint8_t Local_u8RegNum = Copy_u8IRQNum / NVIC_REGISTERS_SIZE;
			uint8_t Local_u8BitNum = Copy_u8IRQNum % NVIC_REGISTERS_SIZE;

			*Copy_u8ActvFlgStat = 1 & ((NVIC -> IABR[Local_u8RegNum]) >> Local_u8BitNum);


		}

		else
		{
			Local_u8ErrorStates = NVIC_Invalid_IRQ;
		}
     }

	else
	{
		Local_u8ErrorStates = NVIC_NULL_PTR;
	}


	return Local_u8ErrorStates;



}
