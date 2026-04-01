/***************************************************************************************************
 * @file: 			EXTI_Prv.h
 * @brief: 			This file contains the private definitions for the EXTI peripheral
 * @author: 		Ibrahim Saber
 * @version: 		1.0
 * @date: 			24-03-2025
 * Last Update:     08:11 PM, Wednesday, April 1, 2026
 ****************************************************************************************************/
#ifndef EXTI_PRV_H
#define EXTI_PRV_H


#define INTERRUPT_LINES_NUM		15U
#define NULL ( (void *) 0)


/*For flag states checking*/
#define EXTI5_FLAG		(1 & ((EXTI -> PR) >> 5))
#define EXTI6_FLAG  	(1 & ((EXTI -> PR) >> 6))
#define EXTI7_FLAG  	(1 & ((EXTI -> PR) >> 7))
#define EXTI8_FLAG  	(1 & ((EXTI -> PR) >> 8))
#define EXTI9_FLAG  	(1 & ((EXTI -> PR) >> 9))
#define EXTI10_FLAG  	(1 & ((EXTI -> PR) >> 10))
#define EXTI11_FLAG  	(1 & ((EXTI -> PR) >> 11))
#define EXTI12_FLAG  	(1 & ((EXTI -> PR) >> 12))
#define EXTI13_FLAG  	(1 & ((EXTI -> PR) >> 13))
#define EXTI14_FLAG  	(1 & ((EXTI -> PR) >> 14))
#define EXTI15_FLAG  	(1 & ((EXTI -> PR) >> 15))

#define FLAG_RAISED		1u



#endif
