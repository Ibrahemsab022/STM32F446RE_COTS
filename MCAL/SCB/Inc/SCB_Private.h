/********************************************************************************************************
 * file: SCB_Private.h
 * brief: This file contains the registers mapping, private definitions for the RCC peripheral
 * author: Ibrahim Saber
 * version: 1.0
 * date: 22-02-2025
 ********************************************************************************************************/
#ifndef SCB_PRIVATE_H
#define SCB_PRIVATE_H


/********************************    Private Definition   ***************************/
#define SCB_VECTKEY				0x05FA			/*Must be written whenever to write in this register*/

/*Pritory group configs, ready to be written*/



/********************************    Registers Bits   ***************************/

/* Application Interrupt and Reset Control Register (AIRCR): */
#define AIRCR_VECTRESET			0u
#define AIRCR_VECTCLRACTIVE		1u
#define AIRCR_SYSRESETREQ		2u
#define AIRCR_PRIGROUP			8U
#define AIRCR_ENDIANNESS		14u
#define AIRCR_VECTKEY			16u


/********************************    Registers Masks   ***************************/
#define SCB_MASK_1BIT	0b1
#define SCB_MASK_3BITS	0b111
#define SCB_MASK_16BITS	0xFFFF


#endif
