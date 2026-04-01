/***************************************************************************************************
 * @file: 			SYSCFG_Interface.h
 * @brief: 			This file contains the interfaces & func prototypes for the SYSCFG peripheral
 * @author: 		Ibrahim Saber
 * @version: 		1.0
 * @date: 			24-03-2025
 * Last Update:     08:11 PM, Wednesday, April 1, 2026
 ****************************************************************************************************/
#ifndef SYSCFG_INTERFACE_H
#define SYSCFG_INTERFACE_H


								/******** 	Interfacing Enums	**********/
typedef enum
{
	SYSCFG_Exit_Ok,
	SYSCFG_InvalidIntPort,
	SYSCFG_InvalidIntLine

}SYSCFG_ErroState_t;


/*External interrupt line enum values to be used in the set int. line func*/
typedef enum
{
	SYSCFG_EXTI0,
	SYSCFG_EXTI1,
	SYSCFG_EXTI2,
	SYSCFG_EXTI3,
	SYSCFG_EXTI4,
	SYSCFG_EXTI5,
	SYSCFG_EXTI6,
	SYSCFG_EXTI7,
	SYSCFG_EXTI8,
	SYSCFG_EXTI9,
	SYSCFG_EXTI10,
	SYSCFG_EXTI11,
	SYSCFG_EXTI12,
	SYSCFG_EXTI13,
	SYSCFG_EXTI14,
	SYSCFG_EXTI15


}SYSCFG_ExtIntLine_t;



/*External interrupt port of the ext. interrupt line enum values to be used in the set int. line func*/
typedef enum
{
	SYSCFG_PORTA,
	SYSCFG_PORTB,
	SYSCFG_PORTC,
	SYSCFG_PORTD,
	SYSCFG_PORTE,
	SYSCFG_PORTF,
	SYSCFG_PORTG
}SYSCFG_IntPort_t;



/**************************************************************************************************************
 * 	Decription:                 This Function is used to set the EXTI Port and line
 * 	Parameters:                 - SYSCFG_IntPort_t Copy_u8Port:    The external interrupt port
 * 								- SYSCFG_ExtIntLine_t Copy_u8line: The external interrupt line.
 * 	Returns:                    - SYSCFG_ErroState_t: an enum indicating the error state of the function
 * 	Preconditions:              -  RCC must be configured and a system clk type is selected.
 * 	Side effects:               No side effects
 * 	Post Conditions:            EXTI port and line are selected
 * 	Synch/Asynch:               Synch.
 * 	Reentrant/NonReenterant:    Non
 *************************************************************************************************************/
SYSCFG_ErroState_t SYSCFG_SetEXTIPort(SYSCFG_IntPort_t Copy_u8Port, SYSCFG_ExtIntLine_t Copy_u8line);



#endif
