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

#include "SYSCFG_Prv.h"
#include "SYSCFG_Interface.h"


SYSCFG_ErroState_t SYSCFG_SetEXTIPort(SYSCFG_IntPort_t Copy_u8Port, SYSCFG_ExtIntLine_t Copy_u8line)
{
	SYSCFG_ErroState_t Local_u8ErrorState = SYSCFG_Exit_Ok;

	if((Copy_u8Port >= SYSCFG_PORTA) && (Copy_u8Port <= SYSCFG_PORTG))
	{
		if((Copy_u8line >= SYSCFG_EXTI0) && (Copy_u8line <= SYSCFG_EXTI15))
		{
			uint8_t Local_u8RegNum = Copy_u8line / LINES_NUM_PER_REG;
			uint8_t Local_u8BitNum = ((Copy_u8line % LINES_NUM_PER_REG) * LINES_NUM_PER_REG);


			(SYSCFG -> EXTICR[Local_u8RegNum]) &= ~((0b1111) << Local_u8BitNum);
			(SYSCFG -> EXTICR[Local_u8RegNum]) |= Copy_u8Port << Local_u8BitNum;

		}

		else
		{
			Local_u8ErrorState = SYSCFG_InvalidIntLine;
		}

	}

	else
	{
		Local_u8ErrorState = SYSCFG_InvalidIntPort;
	}





	return Local_u8ErrorState;

}

