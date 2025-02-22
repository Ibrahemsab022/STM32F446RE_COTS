/*****************************************************
 * file:  SCB_Program.c
 * brief: This file contains the implementation of SCB Peripheral functions
 * author: Ibrahim Saber
 * version: 1.0
 * date: 22-02-2025
 ****************************************************/

#include "stdint.h"

#include "Stm32F446xx.h"


#include "SCB_Private.h"
#include "SCB_Interface.h"


/***************************************************************************************************
 * 	Decription: This Function is used to set the NVIC priority config type
 * 	Parameters: - uint32_t Copy_u32PriGroup: expecting a hex macro indicating the Priority group config
 * 	Returns: SCB_ErrorStates_t
 * 	Preconditions: - VECTKEY must be written at the same time with the PRIGROUP
 * 				   -
 * 	Side effects: No side effects
 * 	Post Conditions: PRIGROUP is indicated succesfully
 * 	Synch/Asynch: Synch.
 * 	Reentrant/NonReenterant: Non
 ***************************************************************************************************/
SCB_ErrorStates_t SCB_SetPriorityGroup(uint32_t Copy_u32PriGroup)
{
	SCB_ErrorStates_t Local_u8ErrorState = SCB_Exit_Ok;

	if((Copy_u32PriGroup >= SCB_PRI_GROUP_3) && (Copy_u32PriGroup <= SCB_PRI_GROUP_7))
	{
		SCB -> AIRCR = Copy_u32PriGroup;
	}

	else
	{
		Local_u8ErrorState = SCB_Invalid_PriGroup;
	}





	return Local_u8ErrorState;

}


