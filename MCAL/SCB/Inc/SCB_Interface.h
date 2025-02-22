/*****************************************************
 * file:   SCB_Interface.h
 * brief:  This file contains the interfaces & func prototypes for the SCB peripheral
 * author: Ibrahim Saber
 * version: 1.0
 * date: 22-02-2025
 ****************************************************/

#ifndef SCB_INTERFACE_H_
#define SCB_INTERFACE_H_


/******************************

      Interfacing Macros

******************************/
#define SCB_PRI_GROUP_3     (0x05FA0300)        /*group priority 4, subpriority 0*/
#define SCB_PRI_GROUP_4     (0x05FA0400)        /*group priority 3, subpriority 1*/
#define SCB_PRI_GROUP_5     (0x05FA0500)        /*group priority 2, subpriority 2*/
#define SCB_PRI_GROUP_6     (0x05FA0600)        /*group priority 1, subpriority 3*/
#define SCB_PRI_GROUP_7     (0x05FA0700)        /*group priority 0, subpriority 4*/





/******************************

      Interfacing Enums

******************************/


/*Error State Enum*/
typedef enum
{
	SCB_Exit_Ok,
	SCB_Invalid_PriGroup



}SCB_ErrorStates_t;







/******************************

      Functions Prototypes

******************************/

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
SCB_ErrorStates_t SCB_SetPriorityGroup(uint32_t Copy_u32PriGroup);




#endif
