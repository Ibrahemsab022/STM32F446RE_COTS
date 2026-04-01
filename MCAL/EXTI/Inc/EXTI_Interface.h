/***************************************************************************************************
 * @file: 			EXTI_Interface.h
 * @brief: 			This file contains the interfaces & func prototypes for the EXTI peripheral
 * @author: 		Ibrahim Saber
 * @version: 		1.0
 * @date: 			24-03-2025
 * Last Update:     08:11 PM, Wednesday, April 1, 2026
 ****************************************************************************************************/
#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H


									/******************		Interfacing Enums		****************/
/*Error State enum as a return values of the EXTI funcs*/
typedef enum
{
	EXTI_Exit_OK,
	EXTI_NULL_Ptr_Err,
	EXTI_InvalidLineNumber,
	EXTI_InvalidEdgeType,
	EXTI_InvalidInitState,


}EXTI_ErrorStates_t;


/*EXTI Num*/
typedef enum
{
	EXTI0,
	EXTI1,
	EXTI2,
	EXTI3,
	EXTI4,
	EXTI5,
	EXTI6,
	EXTI7,
	EXTI8,
	EXTI9,
	EXTI10,
	EXTI11,
	EXTI12,
	EXTI13,
	EXTI14,
	EXTI15


}EXTI_ExtIntLine_t;



/*EXTI edge type trigger*/
typedef enum
{
	EXTI_FallingEdge,
	EXTI_RisingEdge,
	EXTI_OnChange

}EXTI_TrigEdge_t;


/*EXTI Interrupt States enum*/
typedef enum
{
	EXTI_DISABLED,
	EXTI_ENABLED

}EXTI_IntState_t;


										/******************		Interfacing Enums		****************/
typedef struct
{
	EXTI_ExtIntLine_t IntLine;
	EXTI_IntState_t InitStat;
	EXTI_TrigEdge_t TrigType;
	void (*callBackFunc)(void);

}EXTI_Configs_t;


										/******************		Function Prototypes		****************/

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
EXTI_ErrorStates_t EXTI_Init(EXTI_Configs_t *Copy_pExtIntConfigs);



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
EXTI_ErrorStates_t EXTI_EnableInterrupt(EXTI_ExtIntLine_t Copy_u8InterruptLine);


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
EXTI_ErrorStates_t EXTI_DisableInterrupt(EXTI_ExtIntLine_t Copy_u8InterruptLine);




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
EXTI_ErrorStates_t EXTI_SetTrigEdge(EXTI_ExtIntLine_t Copy_u8InterruptLine, EXTI_TrigEdge_t Copy_u8TrigEdge);



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
EXTI_ErrorStates_t EXTI_SetCallBackFunc(EXTI_ExtIntLine_t Copy_u8InterruptLine, void (*Copy_pcallBackFunc)(void));





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
EXTI_ErrorStates_t EXTI_ClearPendingFlag(EXTI_ExtIntLine_t Copy_u8InterruptLine);


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
EXTI_ErrorStates_t EXTI_ReadPendingFlag(EXTI_ExtIntLine_t Copy_u8InterruptLine, uint8_t* Copy_pPendingFlagState);













#endif
